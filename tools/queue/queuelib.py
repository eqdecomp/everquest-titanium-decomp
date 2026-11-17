r"""Shared code for the work queue: paths, JSON-lines IO, states, readiness.

NOTE: the sibling script is called queue.py (as specified), which shadows the stdlib `queue` module when
this folder is first on sys.path. Nothing here needs the stdlib one; run the scripts as files, and don't
add this folder to PYTHONPATH.
"""
import json
import os
from datetime import datetime, timezone
from pathlib import Path

STATES = ["todo", "rewritten", "tested", "verified", "needs_human", "library", "skip"]
DONE = {"rewritten", "tested", "verified", "library", "skip"}   # a caller may rely on such a callee
FIELDS = ["address", "name", "class", "subsystem", "subsystem_how", "state", "auto", "order", "depth",
          "scc", "size", "fp", "callees", "blocker", "note", "attempts", "match", "match_best", "match_history"]


def find_root():
    env = os.environ.get("EQD_ROOT")
    if env:
        return Path(env)
    for start in (Path.cwd(), Path(__file__).resolve()):
        for p in [start, *start.parents]:
            if (p / "paths.local.ini").exists():
                return p
    raise SystemExit("workspace root not found (set EQD_ROOT or run inside the workspace)")


def clients():
    """unicorn/eqd_unicorn/clients.py (the client registry), loaded by path: no harness imports here."""
    import importlib.util
    import sys
    mod = sys.modules.get("eqd_clients")
    if mod is None:
        path = Path(__file__).resolve().parents[1] / "unicorn" / "eqd_unicorn" / "clients.py"
        spec = importlib.util.spec_from_file_location("eqd_clients", path)
        mod = importlib.util.module_from_spec(spec)
        sys.modules["eqd_clients"] = mod
        spec.loader.exec_module(mod)
    return mod


def client(cid):
    """The registry entry for a client id (clients.py)."""
    return clients().get(cid)


def repo_dir(cid):
    """The client's decomp repo: EQD_REPO, else <workspace>/<repo> (eq-trilogy for trilogy and eqmain)."""
    return clients().repo_dir(cid, find_root())


def queue_path(client, override=None, repo=None):
    """--queue, else EQD_QUEUE, else <repo>/<the client's queue file> (eq-trilogy/queue/queue.jsonl for trilogy,
    eq-trilogy/queue/eqmain.jsonl for eqmain); `repo` (a --repo option) picks the repo, else EQD_REPO or the
    workspace's."""
    if override or os.environ.get("EQD_QUEUE"):
        return Path(override or os.environ["EQD_QUEUE"])
    return (Path(repo) if repo else repo_dir(client)) / clients().get(client).queue


def export_dir(client, override=None):
    return Path(override) if override else find_root() / "build" / "export" / client


def merged_spans(fns, frags: dict) -> dict:
    """{head address: (bytes, instructions)} for each head of `frags` ({fragment VA: head VA}, from
    eqd_unicorn.extent.load_fragments) over the export's `fns`: from the head to the end of the last piece that
    follows it with no other function in between (its own fragments and class `eh_funclet`, which the head's
    COMDAT holds too)."""
    info = {int(f["address"], 16): f for f in fns}
    order = sorted(info)
    out = {}
    for head in set(frags.values()):
        if head not in info:
            continue
        end, n = head + info[head]["size"], info[head].get("instructions") or 0
        for s in order[order.index(head) + 1:]:
            if frags.get(s) == head or info[s]["class"] == "eh_funclet":
                end, n = max(end, s + info[s]["size"]), n + (info[s].get("instructions") or 0)
                continue
            break
        out[info[head]["address"]] = (end - head, n)
    return out


def now():
    return datetime.now(timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")


def load(path):
    path = Path(path)
    if not path.exists():
        raise SystemExit(f"no queue at {path} (run build_queue.py <client>)")
    out = []
    for line in path.read_text(encoding="utf-8").splitlines():
        if line.strip():
            out.append(json.loads(line))
    return out


def dump(path, entries):
    """Entries in address order, fixed key order, one per line: small diffs."""
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    lines = []
    for e in sorted(entries, key=lambda e: e["address"]):
        ordered = {k: e[k] for k in FIELDS if k in e}
        ordered.update({k: v for k, v in e.items() if k not in ordered})
        lines.append(json.dumps(ordered, ensure_ascii=False))
    tmp = path.with_suffix(".tmp")
    with open(tmp, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("\n".join(lines) + "\n")
    tmp.replace(path)


def norm_addr(a):
    a = a.strip().upper()
    if a.startswith("0X"):
        a = a[2:]
    return a.zfill(8)


def _same_scc(d, e):
    return bool(e.get("scc")) and d.get("scc") == e.get("scc")


def waiting_on(e, by_addr):
    """Callees that still block this entry (not done, not in its own SCC)."""
    return [c for c in e.get("callees", [])
            if c in by_addr and by_addr[c]["state"] not in DONE and not _same_scc(by_addr[c], e)]


def ready(e, by_addr):
    """A todo entry whose callees are all done/library/skip (or in the same SCC)."""
    return e["state"] == "todo" and not waiting_on(e, by_addr)


# --- byte-match scores (record-match, wave_close) ---------------------------------------------------------------

MATCH_ORDER = ["error", "structural", "diff", "normalised", "identical"]   # worst -> best
HISTORY = 8                                                                  # match_history entries kept


def match_rank(m):
    """Sort key for a `match` record, higher is better: status (identical > normalised > diff > structural >
    error), then fewer differing instructions, then a longer matching prefix, then a later first mismatch."""
    if not m:
        return (-1,)
    st = MATCH_ORDER.index(m["status"]) if m.get("status") in MATCH_ORDER else 0
    return (st, -(m.get("ndiff") or 0), m.get("prefix") or 0, m.get("first_diff_at") or 0)


def match_short(m):
    """`diff/3 p12@0x2a`: status, ndiff, matching prefix and first-mismatch offset, for listings."""
    if not m:
        return "unmeasured"
    s = m.get("status", "?")
    if s in ("diff", "structural"):
        s += f"/{m.get('ndiff', 0)}"
    if m.get("prefix") is not None and m.get("status") in ("diff", "structural"):
        s += f" p{m['prefix']}" + (f"@0x{m['first_diff_at']:x}" if m.get("first_diff_at") is not None else "")
    return s


def record_match(e, m):
    """Set e["match"] = m; raise `match_best` if m is better (a first measurement seeds it from the previous
    `match`, if any); append to `match_history` when the score changed (last HISTORY kept).
    -> "new" | "better" | "worse" | "same"."""
    prev = e.get("match")
    best = e.get("match_best") or prev
    e["match"] = m
    hist = e.setdefault("match_history", [])
    if prev and not hist:
        hist.append(_hist(prev))
    if not hist or match_rank(hist[-1]) != match_rank(m):
        hist.append(_hist(m))
        del hist[:-HISTORY]
    if best is None or match_rank(m) > match_rank(best):
        e["match_best"] = dict(m)
        return "better" if best is not None else "new"
    e["match_best"] = best
    return "worse" if match_rank(m) < match_rank(best) else "same"


def _hist(m):
    return {k: m[k] for k in ("status", "ndiff", "prefix", "first_diff_at", "checked") if k in m}


def match_regressions(entries):
    """Entries whose current `match` is worse than their `match_best`, address order."""
    return [e for e in entries if e.get("match") and e.get("match_best") and not e.get("removed")
            and match_rank(e["match"]) < match_rank(e["match_best"])]
