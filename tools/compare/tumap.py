r"""Estimate which original object (TU) each game-span function came from: a hint, not a fact.

    ..\.venv\Scripts\python.exe tools\compare\tumap.py titanium --out ..\build\titanium\tus.json

Evidence (client data in TUMAP below; a client without an entry is refused):
- every game object's .rdata starts with the same 20-byte int table, so a table hit opens a new object's
  .rdata, and .rdata contributions follow link order like .text does;
- a string or constant in .rdata lives in the first object that used it, so its lowest-addressed user votes for
  that object, and every other user is only bounded from below;
- `__FILE__` strings name a few objects; vtable slots vote weakly;
- objects are contiguous in .text: the fit is a non-decreasing step function of the address (dynamic programming).
Between the last evidence of one object and the first of the next the boundary is unknown: it goes at the cut with
the least call and shared-.data affinity, and those functions get a lower confidence. Objects without any
evidence (their .rdata is just the table) stay empty unless a clean cut exists: a low-confidence guess.

The accuracy report in the output (`accuracy`): held-out evidence (5 folds), and two checks the fit never saw: are
.data items monotone in the object index, do shared .data items stay inside one object, and do same-file call
cleanups fall inside one object.
"""
from __future__ import annotations

import argparse
import bisect
import json
import random
import re
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "queue"))
import queuelib as q  # noqa: E402

TUMAP = {
    "titanium": {
        "span": (0x00401000, 0x00571290),
        "table": (2000, 2500, 3000, 4000, 10000),
        "rdata_end": 0x0065FCE8,            # first string of the next project (EQpfs): game tables lie below it
        "folder": "EverQuest",
    },
}
XDATA_TYPES = ("FuncInfo", "UnwindMapEntry", "TryBlockMapEntry", "HandlerType")
W_FIRST, W_VTABLE, W_ANCHOR, P_BELOW = 1.0, 0.15, 5.0, 2.0


def pe_sections(exe: bytes, base_guess=0x400000):
    pe = struct.unpack_from("<I", exe, 0x3C)[0]
    nsec, opt = struct.unpack_from("<H", exe, pe + 6)[0], struct.unpack_from("<H", exe, pe + 20)[0]
    base = struct.unpack_from("<I", exe, pe + 24 + 28)[0]
    out = {}
    for i in range(nsec):
        o = pe + 24 + opt + 40 * i
        name = exe[o:o + 8].rstrip(b"\0").decode()
        vsize, va, rsize, rptr = struct.unpack_from("<IIII", exe, o + 8)
        out[name] = (base + va, min(vsize, rsize), rptr)
    return out


def table_hits(exe: bytes, secs, table, end) -> list:
    va, size, ptr = secs[".rdata"]
    pat = struct.pack(f"<{len(table)}I", *table)
    return [va + m.start() for m in re.finditer(re.escape(pat), exe[ptr:ptr + size]) if va + m.start() < end]


def load_export(client):
    d = q.export_dir(client)
    load = lambda n, k: json.loads((d / n).read_text(encoding="utf-8"))[k]    # noqa: E731
    return load("functions.json", "functions"), load("strings.json", "strings"), load("globals.json", "globals"), \
        load("callgraph.json", "functions")


class Evidence:
    """votes[j] = {tu: weight}; floor[j] = [lowest allowed tu ...] for the function index j."""

    def __init__(self, n):
        self.votes = [defaultdict(float) for _ in range(n)]
        self.floor = [0 for _ in range(n)]
        self.items = []         # (tu, j of the first user, kind)


def gather(fns, strings, globs, hits, secs, exe, span, use_vtable=True) -> Evidence:
    addr = [int(f["address"], 16) for f in fns]
    by_va = {a: i for i, a in enumerate(addr)}
    ev = Evidence(len(fns))
    lo, hi = hits[0], hits[-1] + 0x4000

    def tu_of(a):
        return bisect.bisect_right(hits, a) - 1

    def item(a, xrefs, kind):
        if not lo <= a < hi:
            return
        users = sorted({by_va[int(x["function"], 16)] for x in xrefs
                        if x.get("function") and int(x["function"], 16) in by_va})
        if not users:
            return
        t = tu_of(a)
        ev.votes[users[0]][t] += W_FIRST
        ev.items.append((t, users[0], kind))
        for j in users[1:]:
            ev.floor[j] = max(ev.floor[j], t)

    seen = set()
    for s in strings:
        if s.get("block") == ".rdata":
            a = int(s["address"], 16)
            seen.add(a)
            item(a, s["xrefs"], "string")
    for g in globs:
        if g.get("block") != ".rdata" or int(g["address"], 16) in seen:
            continue
        if str(g.get("type") or "").startswith(XDATA_TYPES):
            continue
        item(int(g["address"], 16), g.get("xrefs") or [], "rdata")
    if use_vtable:
        va, size, ptr = secs[".rdata"]
        lo_c, hi_c = span
        for off in range(0, size - 3, 4):
            v = struct.unpack_from("<I", exe, ptr + off)[0]
            if lo_c <= v < hi_c and v in by_va and lo <= va + off < hi:
                ev.votes[by_va[v]][tu_of(va + off)] += W_VTABLE
    return ev


def fit(ev: Evidence, n_tu: int, skip=frozenset()) -> list:
    """Non-decreasing tu per function with the highest vote score. O(functions * objects)."""
    n = len(ev.votes)
    NEG = float("-inf")
    best = [0.0] * n_tu
    back = []
    for j in range(n):
        votes = {} if j in skip else ev.votes[j]
        floor = 0 if j in skip else ev.floor[j]
        run, arg = NEG, 0
        new, ptr = [0.0] * n_tu, [0] * n_tu
        for t in range(n_tu):
            if best[t] > run:
                run, arg = best[t], t
            s = votes.get(t, 0.0) - (P_BELOW if t < floor else 0.0)
            new[t], ptr[t] = run + s, arg
        best = new
        back.append(ptr)
    t = max(range(n_tu), key=lambda k: best[k])
    out = [0] * n
    for j in range(n - 1, -1, -1):
        out[j] = t
        t = back[j][t]
    return out


def affinity(fns, cg, globs) -> list:
    """edges[j] = {k: weight}: direct calls and shared non-rdata items between game functions."""
    addr = {f["address"]: i for i, f in enumerate(fns)}
    edges = [defaultdict(float) for _ in fns]
    for f in fns:
        j = addr[f["address"]]
        for c in (cg.get(f["address"]) or {}).get("callees", []):
            k = addr.get(c.get("to"))
            if k is not None and k != j:
                edges[j][k] += 1.0
                edges[k][j] += 1.0
    for g in globs:
        if g.get("block") == ".rdata":
            continue
        users = sorted({addr[x["function"]] for x in g.get("xrefs") or [] if x.get("function") in addr})
        if 2 <= len(users) <= 12:
            w = 1.0 / len(users)
            for a in users:
                for b in users:
                    if a != b:
                        edges[a][b] += w
    return edges


def place_boundaries(tus, ev, edges) -> tuple:
    """Refine the fit between evidence points. -> (tu per function, confidence per function, ranges, cuts)."""
    n = len(tus)
    has = [ev.votes[j].get(tus[j], 0) >= W_FIRST for j in range(n)]
    conf = ["high" if h else "medium" for h in has]
    tus = list(tus)
    anchors = [j for j in range(n) if has[j]]
    cuts = 0
    ranges = {}             # function index -> [first, last] object it may be in, when the gap skips objects
    for a, b in zip(anchors, anchors[1:]):
        ta, tb = tus[a], tus[b]
        if ta == tb:
            for j in range(a + 1, b):
                tus[j] = ta
                conf[j] = "high" if b - a < 40 else "medium"
            continue
        # boundary somewhere in (a, b]: the cut with the least affinity across it
        cand = list(range(a + 1, b + 1))
        left = {j for j in range(max(0, a - 30), a + 1) if tus[j] == ta}
        right = {j for j in range(b, min(n, b + 30)) if tus[j] == tb}
        pull = [sum(w for k, w in edges[j].items() if k in left) - sum(w for k, w in edges[j].items() if k in right)
                for j in cand[:-1]]     # > 0: function j leans to the left object
        # cut at c: a+1..c-1 go left, c..b-1 go right. Start with all on the right, move them over one at a time.
        score = sum(-p for p in pull)
        best_c, best_s = a + 1, score
        for i, p in enumerate(pull):
            score += p + p
            if score > best_s:
                best_s, best_c = score, a + 2 + i
        for j in range(a + 1, b):
            tus[j] = ta if j < best_c else tb
            conf[j] = "low" if tb - ta > 1 or b - a > 40 else "medium"
            if tb - ta > 1:
                ranges[j] = [ta, tb]
        cuts += tb - ta
    if anchors:
        for j in range(anchors[0]):
            tus[j], conf[j] = tus[anchors[0]], "low"
        for j in range(anchors[-1] + 1, n):
            tus[j], conf[j] = tus[anchors[-1]], "low"
    return tus, conf, ranges, cuts


def holdout(ev: Evidence, n_tu, folds=5, seed=1) -> dict:
    evid = [j for j in range(len(ev.votes)) if any(w >= W_FIRST for w in ev.votes[j].values())]
    random.Random(seed).shuffle(evid)
    exact = near = tot = 0
    for k in range(folds):
        held = evid[k::folds]
        pred = fit(ev, n_tu, frozenset(held))
        for j in held:
            want = max(ev.votes[j], key=lambda t: ev.votes[j][t])
            tot += 1
            exact += pred[j] == want
            near += abs(pred[j] - want) <= 1
    return {"held_out": tot, "exact": exact, "within_one": near, "exact_pct": round(100 * exact / max(tot, 1), 1)}


def data_checks(fns, tus, globs) -> dict:
    """Independent of the fit: .data items in link order, and .data items shared inside one object."""
    addr = {f["address"]: i for i, f in enumerate(fns)}
    pts = []
    shared = same = 0
    rnd = random.Random(2)
    shuf = list(tus)
    rnd.shuffle(shuf)
    same_r = 0
    for g in globs:
        if g.get("block") != ".data":
            continue
        users = sorted({addr[x["function"]] for x in g.get("xrefs") or [] if x.get("function") in addr})
        if not users:
            continue
        pts.append((int(g["address"], 16), tus[users[0]]))
        if len(users) >= 2:
            shared += 1
            same += len({tus[u] for u in users}) == 1
            same_r += len({shuf[u] for u in users}) == 1
    pts.sort()
    asc = sum(1 for (_, a), (_, b) in zip(pts, pts[1:]) if b >= a)
    return {"data_items": len(pts), "data_order_ascending_pct": round(100 * asc / max(len(pts) - 1, 1), 1),
            "shared_items": shared, "shared_in_one_tu_pct": round(100 * same / max(shared, 1), 1),
            "shared_in_one_tu_if_shuffled_pct": round(100 * same_r / max(shared, 1), 1)}


def cleanup_check(client, fns, tus) -> dict:
    """Independent of the fit: at /O1 `add esp,4` after a one-argument call needs a callee in the same file
    (vc71q-call-cleanup), so those call sites should fall inside one estimated object."""
    tu = {f["address"]: t for f, t in zip(fns, tus)}
    same = total = 0
    calls = re.compile(r"CALL 0x([0-9a-f]{8})$")
    for shard in sorted((q.export_dir(client) / "asm").glob("*.jsonl")):
        for line in shard.read_text(encoding="utf-8").splitlines():
            r = json.loads(line) if line.strip() else {}
            if r.get("address") not in tu:
                continue
            ins = r["instructions"]
            for cur, nxt in zip(ins, ins[1:]):
                m = calls.match(cur[2])
                if m and nxt[2] == "ADD ESP,0x4" and m.group(1).upper() in tu:
                    total += 1
                    same += tu[m.group(1).upper()] == tu[r["address"]]
    return {"add_esp4_calls": total, "add_esp4_calls_inside_one_tu": same}


def build(client: str) -> dict:
    cfg = TUMAP.get(client)
    if cfg is None:
        raise SystemExit(f"tumap: no TU evidence configured for client {client}")
    root = q.find_root()
    exe = (root / "original" / q.client(client).binary).read_bytes()
    secs = pe_sections(exe)
    hits = table_hits(exe, secs, cfg["table"], cfg["rdata_end"])
    fns, strings, globs, cg = load_export(client)
    lo, hi = cfg["span"]
    fns = sorted((f for f in fns if lo <= int(f["address"], 16) < hi and f["class"] != "eh_funclet"),
                 key=lambda f: int(f["address"], 16))
    ev = gather(fns, strings, globs, hits, secs, exe, cfg["span"])
    n_tu = len(hits)
    raw = fit(ev, n_tu)
    edges = affinity(fns, cg, globs)
    tus, conf, ranges, cuts = place_boundaries(raw, ev, edges)
    names = {}
    for s in strings:
        m = re.fullmatch(r"[cC]:\\EQ\\EverQuest\\(\w+)\.cpp", s["value"])
        if m:
            users = sorted({x["function"] for x in s["xrefs"] if x.get("function")})
            idx = {f["address"]: i for i, f in enumerate(fns)}
            found = Counter(tus[idx[u]] for u in users if u in idx)
            if found:
                names[found.most_common(1)[0][0]] = {"name": m.group(1), "rdata_tu": bisect.bisect_right(
                    hits, int(s["address"], 16)) - 1, "users": len(users)}
    rows, tu_rows = [], {}
    for j, (f, t, c) in enumerate(zip(fns, tus, conf)):
        row = {"address": f["address"], "size": f["size"], "tu": t, "confidence": c}
        if j in ranges:
            row["tu_range"] = ranges[j]
        rows.append(row)
        r = tu_rows.setdefault(t, {"tu": t, "start": f["address"], "end": f["end"], "functions": 0, "bytes": 0,
                                   "rdata": f"{hits[t]:08X}"})
        r["end"], r["functions"], r["bytes"] = f["end"], r["functions"] + 1, r["bytes"] + f["size"]
    for t, r in tu_rows.items():
        r["name"] = names.get(t, {}).get("name")
        r["file"] = f"src/{cfg['folder']}/tu_{t:03d}" + (f"_{r['name']}" if r["name"] else "") + ".cpp"
    anchors_ok = sum(1 for t, a in names.items() if abs(a["rdata_tu"] - t) <= 0)
    weight = sum(max(v.values(), default=0) for v in ev.votes)
    got = sum(v.get(t, 0) for v, t in zip(ev.votes, tus))
    acc = {"tables": n_tu, "tus_with_functions": len(tu_rows), "functions": len(rows),
           "confidence": dict(Counter(conf)), "vote_weight_kept_pct": round(100 * got / max(weight, 1e-9), 1),
           "evidence_items": dict(Counter(k for *_, k in ev.items)), "boundary_cuts_in_gaps": cuts,
           "file_anchors": len(names), "file_anchors_on_their_rdata_tu": anchors_ok,
           "holdout": holdout(ev, n_tu), **data_checks(fns, tus, globs), **cleanup_check(client, fns, tus)}
    return {"schema_version": 1, "client": client, "hint_only": True,
            "method": "compare/tumap.py: .rdata table hits, first-user votes, monotone fit, least-affinity cuts",
            "accuracy": acc, "tus": [tu_rows[t] for t in sorted(tu_rows)], "functions": rows}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("client")
    ap.add_argument("--out", help="default <build>/<client>/tus.json")
    a = ap.parse_args(argv)
    res = build(a.client)
    out = Path(a.out) if a.out else q.find_root() / "build" / a.client / "tus.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(res, indent=0), encoding="utf-8")
    print(json.dumps(res["accuracy"], indent=1))
    print(f"wrote {out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
