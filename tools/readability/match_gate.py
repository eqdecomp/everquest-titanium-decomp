r"""Titanium readability gate: a rename must not change what any function compiles to, nor what its fixtures do.

    cd eq-titanium           (a worktree or a copy)
    ..\.venv\Scripts\python.exe tools\readability\match_gate.py snapshot [FILES...] --json before.json
    ... (edit, e.g. rename.py -c titanium --map m.json --journal j.jsonl)
    ..\.venv\Scripts\python.exe tools\readability\match_gate.py check --before before.json [FILES...] [--renames j.jsonl]
    ..\.venv\Scripts\python.exe tools\readability\match_gate.py check --base HEAD [FILES...]

gate.py (VC6, one shared match header, before/after objects compared with each other) does not fit Titanium: its
TUs carry their own `// CFLAGS:`, build with vc71 and call each other through `// EXTERNAL:` markers. This gate
wraps the check the match tooling already trusts, `compare.py --match` against the original image:

1. TUs: the changed sources (FILES, else `git diff --name-only HEAD` plus untracked files), the sources that
   include a changed header, and the `sources` of a changed fixture.
2. Before: `snapshot` (compare run on the tree before the edit; rename.py --gate takes it itself), or `--base REV`
   (compare run on a `git archive` of REV, cached per commit).
3. After: compare on the working tree. Fail when a VA identical before is not identical after, when a VA appears or
   disappears, or when a non-identical VA gets worse (status identical < normalised < diff < structural < error,
   or a higher ndiff at the same status).
4. Fixtures (`--fixtures`, default `renamed`): the fixtures whose "original" is a renamed VA (--renames journal,
   else the VAs of the changed TUs whose annotated name changed), the fixtures that script one of those VAs as a
   callee, and every changed fixture; `tu` = every fixture of the TUs; `none` = skip. Run with pytest like the
   match tooling does; a fixture that also fails on the before side (the snapshot's "fixtures") is
   listed, not counted.

compare writes its objects under <build>/readability/titanium/ (never compare's own <build>/titanium/match), the
fixtures' DLLs likewise; EQD_COMPILE_LOCK (the shared compiler lock) is passed through when set.
Exit 0 = pass, 1 = fail, 2 = setup problem. Importable: snapshot(), check(), Txn (the undo log rename.py uses).
"""
from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
import re
import subprocess
import sys
import tarfile
import time
from dataclasses import dataclass, field
from pathlib import Path

HERE = Path(__file__).resolve().parent
TOOLS = HERE.parent
sys.path.insert(0, str(HERE))
import registry as R  # noqa: E402  (puts compare/, unicorn/ on sys.path)

from eqd_unicorn import Workspace  # noqa: E402

PY = sys.executable
RANK = {"identical": 0, "normalised": 1, "diff": 2, "structural": 3, "error": 4}
LITTER = re.compile(r"(^|/)(\.check|__pycache__|\.pytest_cache)/|\.(obj|pdb|ilk|exe|dll|map|lst|cod)$", re.I)
_INC = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)


@dataclass
class Verdict:
    ok: bool = True
    tus: list = field(default_factory=list)
    functions: int = 0
    identical: tuple = (0, 0)                           # identical functions (before, after)
    regressions: list = field(default_factory=list)     # "0x00401000 name: identical -> diff (ndiff 3)"
    fixtures_run: list = field(default_factory=list)
    fixtures_failed: list = field(default_factory=list)
    known_failing: list = field(default_factory=list)   # failing on the before side too (not counted)
    problems: list = field(default_factory=list)
    notes: list = field(default_factory=list)
    seconds: float = 0.0                                # gate_txn: wall time of the gate

    def report(self) -> str:
        out = [f"titanium match gate: {len(self.tus)} TU(s), {self.functions} functions "
               f"(identical {self.identical[0]} before, {self.identical[1]} after), {len(self.fixtures_run)} fixture(s)"
               + (f", {len(self.fixtures_failed)} failing" if self.fixtures_failed else "")
               + (f", {self.seconds:.0f} s" if self.seconds else "")]
        out += [f"  PROBLEM {p}" for p in self.problems]
        out += [f"  REGRESSION {r}" for r in self.regressions]
        out += [f"  FIXTURE FAIL {f}" for f in self.fixtures_failed]
        out += [f"  (fails on the before side too: {f})" for f in self.known_failing]
        out += [f"  note: {n}" for n in self.notes]
        out.append("PASS" if self.ok else "FAIL")
        return "\n".join(out)

    def as_json(self) -> dict:
        return dict(self.__dict__)


# --- which TUs, which fixtures --------------------------------------------------------------------------------

def git(repo: Path, *args, binary=False):
    p = subprocess.run(["git", "-C", str(repo), *args], capture_output=True, check=True)
    return p.stdout if binary else p.stdout.decode("utf-8", "replace")


def changed_files(repo: Path, base: str = "HEAD") -> list[str]:
    out = git(repo, "diff", "--name-only", base).splitlines() + \
        git(repo, "ls-files", "--others", "--exclude-standard").splitlines()
    return sorted({f.strip() for f in out if f.strip() and not LITTER.search(f) and not f.startswith("tools/")})


def dependents(repo: Path, headers) -> list[str]:
    """Sources under src/ that include one of `headers` (repo-relative), directly or through other headers."""
    want = {Path(h).name.lower() for h in headers}
    hdr_inc = {}
    for p in list((repo / "include").rglob("*.h")) + list((repo / "src").rglob("*.h")) \
            if (repo / "include").is_dir() else list((repo / "src").rglob("*.h")):
        hdr_inc[p.name.lower()] = {Path(i).name.lower() for i in _INC.findall(p.read_text("utf-8", "replace"))}
    changed = True
    while changed:                                   # a header including a changed header changes too
        changed = False
        for h, inc in hdr_inc.items():
            if h not in want and inc & want:
                want.add(h)
                changed = True
    out = []
    for p in sorted((repo / "src").rglob("*")):
        if p.suffix.lower() in (".c", ".cpp") and p.is_file():
            inc = {Path(i).name.lower() for i in _INC.findall(p.read_text("utf-8", "replace"))}
            if inc & want:
                out.append(p.relative_to(repo).as_posix())
    return out


def tus_of(repo: Path, files) -> list[str]:
    """The TUs to compile for a set of changed files (sources, includers of headers, sources of fixtures)."""
    repo = Path(repo)
    tus = {f for f in files if f.startswith("src/") and f.lower().endswith((".c", ".cpp"))}
    hdrs = [f for f in files if f.lower().endswith(".h")]
    if hdrs:
        tus |= set(dependents(repo, hdrs))
    for f in files:
        if f.startswith("tests/unicorn/") and f.endswith(".json") and (repo / f).is_file():
            try:
                d = json.loads((repo / f).read_text(encoding="utf-8"))
            except ValueError:
                continue
            if isinstance(d, dict):
                tus |= {s for s in d.get("sources") or [] if (repo / s).is_file()}
    return sorted(t for t in tus if (repo / t).is_file())


def fixture_index(repo: Path) -> list[tuple]:
    """[(rel, original VA or None, {callee VAs}, [sources])] of every fixture under tests/unicorn/<sub>/."""
    out = []
    base = Path(repo) / "tests" / "unicorn"
    for f in sorted(base.rglob("*.json")) if base.is_dir() else ():
        if f.parent == base or "negative" in f.parts:
            continue
        try:
            d = json.loads(f.read_text(encoding="utf-8"))
        except (ValueError, OSError):
            continue
        if not isinstance(d, dict):
            continue
        try:
            va = int(str(d.get("original")), 16)
        except ValueError:
            va = None
        cal = set()
        for k in d.get("callees") or {}:
            try:
                cal.add(int(k, 16))
            except ValueError:
                pass
        out.append((f.relative_to(repo).as_posix(), va, cal, list(d.get("sources") or [])))
    return out


def select_fixtures(repo: Path, vas, files, tus, mode="renamed") -> list[str]:
    """Fixture paths to run: `renamed` = own fixtures of `vas`, fixtures scripting one of `vas` as a callee, changed
    fixtures; `tu` = also every fixture whose sources include a TU of `tus`; `none` = nothing."""
    if mode == "none":
        return []
    vas = set(vas)
    changed = {f for f in files if f.startswith("tests/unicorn/") and f.endswith(".json")}
    out = []
    for rel, va, cal, srcs in fixture_index(repo):
        if rel in changed or va in vas or cal & vas or (mode == "tu" and set(srcs) & set(tus)):
            out.append(rel)
    return out


def renamed_vas(journal_paths) -> set:
    out = set()
    for jp in journal_paths or ():
        for line in Path(jp).read_text(encoding="utf-8").splitlines():
            if line.strip():
                j = json.loads(line)
                if j.get("kind") == "fn" and j.get("va"):
                    out.add(int(j["va"], 16))
    return out


# --- running compare and the fixtures -------------------------------------------------------------------------

def work_dir(repo: Path, cache=None) -> Path:
    if cache:
        return Path(cache).resolve()
    return (Workspace(repo).build / "readability" / "titanium").resolve()


def _env(cache: Path, tag: str) -> dict:
    env = dict(os.environ, PYTHONDONTWRITEBYTECODE="1", EQD_TOOLS=str(TOOLS),
               EQD_UNICORN_BUILD=str(cache / f"unicorn_{tag}"))
    return env


def compare_tus_batch(repo: Path, tus, cache: Path, tag: str, client="titanium", log=print) -> dict:
    """One `compare.py --match` call over all `tus` (the gate before the result cache; kept for measuring, and
    used with EQD_GATE_COMPARE=batch). -> {va int: {"status", "ndiff", "name", "source"}}."""
    if not tus:
        return {}
    repo = Path(repo).resolve()
    key = hashlib.sha1((str(repo) + "|" + tag).encode()).hexdigest()[:10]
    out, js = cache / "match" / key, cache / f"compare_{key}.json"
    js.unlink(missing_ok=True)
    cmd = [PY, str(TOOLS / "compare" / "compare.py"), "--repo", str(repo), "--client", client, "--match",
           "--out", str(out), "--json", str(js), *[str(repo / t) for t in tus]]
    p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", cwd=repo, env=_env(cache, tag))
    if not js.is_file():
        raise RuntimeError(f"compare --match failed: {(p.stdout + p.stderr)[-600:]}")
    return _rows_to_res(json.loads(js.read_text(encoding="utf-8"))["results"])


def _rows_to_res(rows) -> dict:
    res = {}
    for r in rows:
        res[int(r["va"], 16)] = {"status": r.get("match") or "error", "ndiff": r.get("ndiff"),
                                 "name": r.get("name"), "source": r.get("source")}
    return res


# --- the result cache --------------------------------------------------------------------------------------------
#
# A TU's verdict depends on more than its own text: the headers it includes, every `// EXTERNAL:` marker and
# annotation of the repo (MatchContext, cross_tu), crt_defaults.json and the fixtures' sizes. So a cached verdict
# is keyed by the whole tree (every source, header and tests/unicorn JSON, by content), the tools' code, the
# original binary, the repo path and the TU. A gated map compares the same tree many times: the before side of
# each group is the tree the last group left (its TUs were just compared), and a bisect's halves start from the
# tree whose before side was just taken. Those runs are free.
# Each TU is compared on its own (`match_gate.py _compare`: one process and one MatchContext, each TU with its own
# cross_tu): compare_match keys a call to a local unannotated function by the annotations of every source of the
# call, so a verdict from a batch could depend on which TUs shared the call; a per-TU verdict does not.
# Objects are cached too, by what the compiler reads (the source, every header of the repo, the generated EQD_MATCH
# header, the repo path): an unchanged TU, or a callee TU that cross_tu builds, is not compiled again and does not
# wait for the shared compiler lock.

CACHE_VERSION = "1"
TREE_DIRS = ("src", "include", "tests/unicorn")
TREE_EXT = {".c", ".cpp", ".h", ".hpp", ".inl", ".json"}
STATS = {"hit": 0, "miss": 0, "calls": 0, "skipped": 0}
_TOOLS_HASH = None


def tools_hash() -> str:
    """The code a verdict comes from: compare/, unicorn/eqd_unicorn/, structs/ and this file."""
    global _TOOLS_HASH
    if _TOOLS_HASH is None:
        h = hashlib.sha1(CACHE_VERSION.encode())
        for d in (TOOLS / "compare", TOOLS / "unicorn" / "eqd_unicorn", TOOLS / "structs"):
            for f in sorted(d.rglob("*.py")) if d.is_dir() else ():
                if "__pycache__" not in f.parts:
                    h.update(f.relative_to(TOOLS).as_posix().encode() + b"\0" + f.read_bytes() + b"\0")
        h.update(Path(__file__).read_bytes())
        _TOOLS_HASH = h.hexdigest()
    return _TOOLS_HASH


def tree_hash(repo: Path, dirs=TREE_DIRS) -> str:
    """Content hash of what compare --match reads from the repo: sources, headers, tests/unicorn JSON."""
    repo = Path(repo)
    h = hashlib.sha1()
    for d in dirs:
        base = repo / d
        for f in sorted(base.rglob("*")) if base.is_dir() else ():
            if f.suffix.lower() not in TREE_EXT or LITTER.search(f.as_posix()) or not f.is_file():
                continue
            h.update(f.relative_to(repo).as_posix().encode() + b"\0" + hashlib.sha1(f.read_bytes()).digest())
    return h.hexdigest()


def _binary_id(repo: Path, client: str) -> str:
    try:
        b = Workspace(repo).binary(client)
        st = b.stat()
        return f"{b}|{st.st_size}|{int(st.st_mtime)}"
    except (KeyError, OSError, RuntimeError):
        return "-"


def _atomic_write(path: Path, data: bytes):
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(f".{path.name}.{os.getpid()}.tmp")
    tmp.write_bytes(data)
    os.replace(tmp, path)


def compare_tus(repo: Path, tus, cache: Path, tag: str, client="titanium", log=print) -> dict:
    """compare --match of each TU of `tus` (repo-relative) on the tree as it is now -> {va int: {"status", "ndiff",
    "name", "source"}}. A TU's verdict comes from the result cache when this exact tree was compared before, the
    others from one `match_gate.py _compare` process (each TU on its own, objects cached).
    EQD_GATE_COMPARE=batch: the old single compare.py call, no cache."""
    if not tus:
        return {}
    if os.environ.get("EQD_GATE_COMPARE") == "batch":
        STATS["calls"] += 1
        return compare_tus_batch(repo, tus, cache, tag, client, log)
    repo = Path(repo).resolve()
    cache = Path(cache)
    base = hashlib.sha1("|".join([CACHE_VERSION, tools_hash(), client, str(repo).lower(), _binary_id(repo, client),
                                  tree_hash(repo)]).encode()).hexdigest()
    rows, missing = [], []
    for t in tus:
        f = cache / "results" / (hashlib.sha1((base + "|" + t).encode()).hexdigest()[:32] + ".json")
        try:
            rows += json.loads(f.read_text(encoding="utf-8"))["rows"]
            STATS["hit"] += 1
        except (OSError, ValueError, KeyError):
            missing.append((t, f))
    if missing:
        STATS["miss"] += len(missing)
        STATS["calls"] += 1
        key = hashlib.sha1((str(repo) + "|" + tag).encode()).hexdigest()[:10]
        js = cache / f"compare_{key}.json"
        js.unlink(missing_ok=True)
        cache.mkdir(parents=True, exist_ok=True)
        cmd = [PY, str(Path(__file__).resolve()), "_compare", "--repo", str(repo), "--client", client,
               "--out", str(cache / "match" / key), "--objs", str(cache / "objs"), "--json", str(js),
               *[t for t, _f in missing]]
        p = subprocess.run(cmd, capture_output=True, text=True, errors="replace", cwd=repo, env=_env(cache, tag))
        if not js.is_file():
            raise RuntimeError(f"compare --match failed: {(p.stdout + p.stderr)[-600:]}")
        per_tu = json.loads(js.read_text(encoding="utf-8"))["per_tu"]
        for t, f in missing:
            got = per_tu.get(t)
            if got is None:
                raise RuntimeError(f"compare --match gave nothing for {t}")
            _atomic_write(f, json.dumps({"tu": t, "rows": got}).encode())
            rows += got
    return _rows_to_res(rows)


def _compare_main(argv) -> int:
    """`match_gate.py _compare --repo R --client C --out D --objs D --json F TU...`: compare --match of each TU on
    its own, in one process (one MatchContext; compiles memoised and cached by content, _cache_compiles).
    Writes {"per_tu": {tu: [rows as compare.py --json writes them]}}."""
    ap = argparse.ArgumentParser(prog="match_gate.py _compare")
    ap.add_argument("tus", nargs="+")
    ap.add_argument("--repo", required=True)
    ap.add_argument("--client", default="titanium")
    ap.add_argument("--out", required=True)
    ap.add_argument("--objs", required=True)
    ap.add_argument("--json", required=True)
    a = ap.parse_args(argv)
    import compare as C                                             # tools/compare (on sys.path via registry)
    from eqd_unicorn import annotations as ann, clients
    repo = Path(a.repo).resolve()
    log = lambda m: print(m, file=sys.stderr)                        # noqa: E731
    aliases, _link = C.load_defaults(repo / clients.get(a.client).crt_defaults, repo)
    ctx = C.MatchContext(repo, a.client, Path(a.out), aliases, log)
    _cache_compiles(ctx, repo, Path(a.objs))
    per_tu = {}
    for t in a.tus:                                                  # = compare_match over [t], sharing ctx
        src = (repo / t).resolve()
        anns = ann.scan([src], a.client.upper())
        by_name: dict = {}
        for x in anns:
            by_name.setdefault(x.name, set()).add(x.va)
        rows = []
        if anns:
            obj, text, flags = ctx.compile_kept(src)
            if obj is None:
                err = "; ".join(ln.strip() for ln in text.splitlines() if "error" in ln)[:400]
                res = [C.Result(x.va, x.name, t, "error", first_diff=f"match build failed: {err}") for x in anns]
            else:
                xtu = ctx.cross_tu({src: obj}, {src: anns}, log)
                res = ctx.compare_obj(obj, src, anns, by_name, None, t, flags, None, xtu=xtu)
            rows = [dict(r.as_json(), match=C.match_status(r)) for r in res]
        per_tu[t] = rows
    Path(a.json).write_text(json.dumps({"per_tu": per_tu}), encoding="utf-8")
    return 0


def _cache_compiles(ctx, repo: Path, objs: Path):
    """Wrap ctx.compile_kept: each source is built once per process, and its object (or its failure) is kept under
    `objs`, keyed by what the compiler reads, so an unchanged source is not compiled again."""
    orig = ctx.compile_kept
    memo: dict = {}
    hh = hashlib.sha1()
    for d in ("include", "src"):
        for f in sorted((repo / d).rglob("*")) if (repo / d).is_dir() else ():
            if f.suffix.lower() in (".h", ".hpp", ".inl") and f.is_file():
                hh.update(f.relative_to(repo).as_posix().encode() + b"\0" + hashlib.sha1(f.read_bytes()).digest())
    try:
        hh.update(str(ctx.ws.toolchain(ctx.client)).encode())
    except (KeyError, OSError, RuntimeError, AttributeError):
        pass
    headers = hh.hexdigest()

    def kept(src):
        src = Path(src).resolve()
        if src in memo:
            return memo[src]
        try:
            hdr = Path(ctx.header_for(src))
            key = hashlib.sha1("|".join([CACHE_VERSION, tools_hash(), ctx.client, str(repo).lower(), str(src).lower(),
                                         headers, hashlib.sha1(src.read_bytes()).hexdigest(),
                                         hashlib.sha1(hdr.read_bytes()).hexdigest()]).encode()).hexdigest()[:32]
        except OSError:
            memo[src] = r = orig(src)
            return r
        meta, obj = objs / f"{key}.json", objs / f"{key}.obj"
        try:
            m = json.loads(meta.read_text(encoding="utf-8"))
            if not m["ok"] or not obj.is_file():
                raise ValueError("object missing")
            r = (obj, m["text"], m["flags"])
        except (OSError, ValueError, KeyError):
            r = orig(src)
            if r[0] is not None:                # a failed build is not kept: it may be the toolchain's fault
                _atomic_write(obj, Path(r[0]).read_bytes())
                _atomic_write(meta, json.dumps({"ok": True, "text": r[1], "flags": list(r[2]),
                                                "src": str(src)}).encode())
                r = (obj, r[1], r[2])
        memo[src] = r
        return r

    ctx.compile_kept = kept


def run_fixtures(repo: Path, rels, cache: Path, tag: str) -> tuple[list, list, str]:
    """pytest over fixture paths -> (failed paths, skip reasons, output)."""
    if not rels:
        return [], [], ""
    failed, skipped, out = set(), set(), []
    rels = list(rels)
    for i in range(0, len(rels), 40):
        p = subprocess.run([PY, "-m", "pytest", "-q", "-rs", "-p", "no:cacheprovider", *rels[i:i + 40]], cwd=repo,
                           env=_env(cache, tag), capture_output=True, text=True, errors="replace")
        failed |= {m.replace("\\", "/") for m in re.findall(r"^(?:FAILED|ERROR) (\S+?\.json)", p.stdout, re.M)}
        if p.returncode not in (0, 1) and not failed:
            failed |= set(rels[i:i + 40])          # pytest itself failed (collection, usage): count them all
        skipped |= set(re.findall(r"^SKIPPED \[\d+\] (.*)$", p.stdout, re.M))
        out.append(p.stdout + p.stderr)
    return sorted(failed), sorted(skipped), "".join(out)


# --- the verdict ------------------------------------------------------------------------------------------------

def judge(before: dict, after: dict) -> list[str]:
    """Regressions between two compare snapshots ({va: {"status", "ndiff", "name"}})."""
    out = []
    for va in sorted(set(before) | set(after)):
        b, a = before.get(va), after.get(va)
        if b is None:
            out.append(f"0x{va:08X} {a.get('name')}: new function (a rename adds none)")
            continue
        if a is None:
            out.append(f"0x{va:08X} {b.get('name')}: gone after the edit")
            continue
        rb, ra = RANK.get(b["status"], 4), RANK.get(a["status"], 4)
        worse = ra > rb or (ra == rb and rb > 0 and (a.get("ndiff") or 0) > (b.get("ndiff") or 0))
        if worse:
            out.append(f"0x{va:08X} {a.get('name')}: {b['status']} -> {a['status']}"
                       + (f" (ndiff {b.get('ndiff')} -> {a.get('ndiff')})" if a["status"] != "identical" else ""))
    return out


def snapshot(repo, files=None, cache=None, tag="before", tus=None, fixtures=None, log=print) -> dict:
    """compare (and optionally fixtures) of the TUs of `files` on the tree as it is now. -> a JSON-able dict."""
    repo = Path(repo).resolve()
    cache = work_dir(repo, cache)
    tus = sorted(tus) if tus is not None else tus_of(repo, files or [])
    res = compare_tus(repo, tus, cache, tag, log=log)
    snap = {"tus": tus, "compare": {f"0x{k:08X}": v for k, v in res.items()}}
    if fixtures:
        failed, skipped, _o = run_fixtures(repo, fixtures, cache, tag)
        snap["fixtures"] = {"run": list(fixtures), "failed": failed, "skipped": skipped}
    return snap


def check(repo, before: dict, files=None, cache=None, vas=None, fixtures="renamed", tag="after",
          fixtures_before=None, log=print, skip=None) -> Verdict:
    """Compare the TUs of `before` (plus those of `files`) now, judge against `before`, run the fixtures.
    `skip`: {TU: why} left out of the compare (inert_changes: their edit provably changes no verdict)."""
    repo = Path(repo).resolve()
    cache = work_dir(repo, cache)
    files = list(files or [])
    skip = dict(skip or {})
    all_tus = sorted(set(before.get("tus") or []) | set(tus_of(repo, files)))
    tus = [t for t in all_tus if t not in skip]
    v = Verdict(tus=tus)
    if skip:
        v.notes.append(f"{len(skip)} TU(s) not compiled, their change is inert: "
                       + "; ".join(f"{t} ({w})" for t, w in sorted(skip.items())[:8])
                       + (" ..." if len(skip) > 8 else ""))
    b = {int(k, 16): x for k, x in (before.get("compare") or {}).items()}
    missing = [t for t in tus if t not in (before.get("tus") or [])]
    if missing:
        v.problems.append(f"no before verdicts for {', '.join(missing)} (take the snapshot over them too)")
    try:
        a = compare_tus(repo, tus, cache, tag, log=log)
    except RuntimeError as e:
        v.problems.append(str(e))
        v.ok = False
        return v
    v.functions = len(a)
    v.identical = (sum(1 for x in b.values() if x["status"] == "identical"),
                   sum(1 for x in a.values() if x["status"] == "identical"))
    v.regressions = judge(b, a)
    if vas is None:                                  # the VAs whose annotated name differs from the snapshot's
        vas = {va for va, x in a.items() if va in b and x.get("name") != b[va].get("name")}
    fx = select_fixtures(repo, vas, files, all_tus, fixtures)
    v.fixtures_run = fx
    if fx:
        failed, skipped, out = run_fixtures(repo, fx, cache, tag)
        known = set((before.get("fixtures") or {}).get("failed") or []) | set(fixtures_before or [])
        v.fixtures_failed = [f for f in failed if f not in known]
        v.known_failing = [f for f in failed if f in known]
        if skipped:
            v.notes.append(f"fixtures skipped (no workspace/toolchain?): {'; '.join(skipped[:3])}")
        if v.fixtures_failed:
            cache.mkdir(parents=True, exist_ok=True)
            (cache / f"fixtures_{tag}.txt").write_text(out, encoding="utf-8")
            v.notes.append(f"fixture output: {cache / f'fixtures_{tag}.txt'}")
    v.ok = not (v.problems or v.regressions or v.fixtures_failed)
    return v


def base_tree(repo: Path, rev: str, cache: Path) -> Path:
    """`git archive <rev>` of what compare and the fixtures read (src, include, tests/unicorn), cached per commit."""
    sha = git(repo, "rev-parse", rev).strip()
    root = cache / "base" / sha[:16]
    if (root / ".done").is_file():
        return root
    data = git(repo, "archive", "--format=tar", sha, "src", "include", "tests/unicorn", binary=True)
    root.mkdir(parents=True, exist_ok=True)
    with tarfile.open(fileobj=io.BytesIO(data)) as t:
        t.extractall(root)
    (root / ".done").write_text(sha, encoding="utf-8")
    return root


# --- an undo log for edits under the gate -----------------------------------------------------------------------

class Txn:
    """Remembers each file's bytes before its first write (and file renames), so a failed gate restores the tree
    exactly; `swap()` puts the old bytes back for a before-snapshot and `unswap()` the new ones again."""

    def __init__(self, repo):
        self.repo = Path(repo)
        self.orig: dict = {}        # rel -> bytes or None (did not exist)
        self.renamed: list = []     # (old rel, new rel)

    def _keep(self, rel):
        if rel not in self.orig:
            p = self.repo / rel
            self.orig[rel] = p.read_bytes() if p.is_file() else None

    def write(self, rel: str, text: str):
        self._keep(rel)
        with open(self.repo / rel, "w", encoding="utf-8", newline="") as f:
            f.write(text)

    def rename(self, old: str, new: str):
        self._keep(old)
        self._keep(new)
        (self.repo / old).rename(self.repo / new)
        self.renamed.append((old, new))

    def files(self) -> list[str]:
        return sorted(self.orig)

    def restore(self):
        for o, n in reversed(self.renamed):
            if (self.repo / n).is_file() and not (self.repo / o).exists():
                (self.repo / n).rename(self.repo / o)
        for rel, data in self.orig.items():
            p = self.repo / rel
            if data is None:
                p.unlink(missing_ok=True)
            else:
                p.write_bytes(data)
        self.orig, self.renamed = {}, []

    def swap(self) -> dict:
        """Put the original bytes back; returns what to pass to unswap()."""
        now = {rel: ((self.repo / rel).read_bytes() if (self.repo / rel).is_file() else None) for rel in self.orig}
        for o, n in reversed(self.renamed):
            if (self.repo / n).is_file():
                (self.repo / n).rename(self.repo / o)
        for rel, data in self.orig.items():
            if data is None:
                (self.repo / rel).unlink(missing_ok=True)
            else:
                (self.repo / rel).write_bytes(data)
        return now

    def unswap(self, now: dict):
        for o, n in self.renamed:
            if (self.repo / o).is_file() and now.get(n) is not None:
                (self.repo / o).unlink()
        for rel, data in now.items():
            if data is None:
                (self.repo / rel).unlink(missing_ok=True)
            else:
                (self.repo / rel).write_bytes(data)


def gate_txn(repo, txn: Txn, vas, cache=None, fixtures="renamed", log=print, scope=True) -> Verdict:
    """The edits of `txn` are in the tree: compare their TUs before (swapped back) and after, run the fixtures of
    `vas` (both sides only when one fails after). On a failure the caller restores (txn.restore()).
    `scope`: leave out the TUs whose edit is inert (inert_changes); the fixtures are chosen as before."""
    t0 = time.time()
    repo = Path(repo).resolve()
    files = txn.files()
    skip = inert_changes(repo, txn) if scope else {}
    STATS["skipped"] += len(skip)
    now = txn.swap()
    try:
        tus = [t for t in tus_of(repo, files) if t not in skip]
        before = snapshot(repo, tus=tus, cache=cache, tag="before", log=log)
    finally:
        txn.unswap(now)
    v = check(repo, before, files, cache, vas, fixtures, log=log, skip=skip)
    if v.fixtures_failed:                            # did they fail before the edit too?
        now = txn.swap()
        try:
            failed, _s, _o = run_fixtures(repo, v.fixtures_failed, work_dir(repo, cache), "before")
        finally:
            txn.unswap(now)
        v.known_failing += [f for f in v.fixtures_failed if f in failed]
        v.fixtures_failed = [f for f in v.fixtures_failed if f not in failed]
        v.ok = not (v.problems or v.regressions or v.fixtures_failed)
    v.seconds = round(time.time() - t0, 1)
    return v


# --- scope: TUs whose edit is inert -------------------------------------------------------------------------------
#
# A rename touches many TUs besides the renamed function's own: callers' markers and view names, and comment words.
# A TU is left out of the compare only when its edit provably changes no verdict, i.e. compiling and comparing it
# after the edit would see exactly what it saw before. The test is on tokens, line by line:
#   - "comments only": the C/C++ tokens (with their line numbers) are the same, and so is every directive comment
#     (`// FUNCTION:`, `// EXTERNAL:`, `// CFLAGS:`, `// TOOLCHAIN:`: any comment with a line starting `// WORD:`,
#     `/* WORD:` or ` * WORD:`, the forms the tools' line regexes accept). The compiler sees the same token stream on the same lines (__LINE__ included), and
#     compare reads no other comment. Same object, same markers, same verdict.
#   - "unreferenced marker": as above, except that some `// EXTERNAL:` markers changed their name (same client,
#     same VA), and no identifier of the old or the new name occurs in the TU's code or in any header it includes.
#     A marker maps an undefined symbol of the object to a VA by name (externs.resolve); the object can only
#     reference a name its source or headers spell, so neither name maps anything, before or after. The VA
#     itself (which MatchContext seeds as a function start) is unchanged. A marker whose name the code does use is
#     NOT inert, even though it cannot change codegen: renamed without the code it would stop mapping the call
#     (a verdict change the gate must see).
#   - A changed header whose edit is comments only (the same rule) changes nothing for its includers: a TU in the
#     gate only because it includes such headers is left out too (a comment in include/titanium/crt.h pulled
#     every TU into one batch).
#   - Never: a TU that includes a header with any other edit, a source of a changed fixture, a new or renamed
#     file, or any edit to a code token or a preprocessor line, comments in it included (a declaration's name
#     changes the decorated symbol, so a callee's mapping, overload resolution or name hiding could change).
# Other TUs' edits reach a TU only through what it spells (its markers, its calls by decorated name), so an inert
# TU is in the same position as a TU the rename did not touch at all, which the gate never compared either.

# a directive line as the tools' regexes read it: `// FUNCTION:`, `// EXTERNAL:`, `// CFLAGS:`, ` * CFLAGS:` in a block
_DIRECTIVE = re.compile(r"^\s*(?://|/\*|\*)\s*[A-Z][A-Z0-9_]*\s*:", re.M)
_EXT_MARK = re.compile(r"//[ \t]*EXTERNAL:[ \t]*(\w+)[ \t]+(0[xX][0-9a-fA-F]+)[ \t]+(\S+)[ \t]*$")
_ID = re.compile(r"[A-Za-z_]\w*")


def _signature(text: str) -> list:
    """[(line, kind, text)] of what the compiler and compare read: code tokens and directive comments."""
    import ctoken as ct                                              # permute/ (on sys.path via registry)
    out, line = [], 1
    for t in ct.tokenize(text):
        if t.kind == "comment":
            if _DIRECTIVE.search(t.text):
                out.append((line, "dir", t.text.rstrip()))
        elif t.kind != "ws":
            out.append((line, t.kind, t.text))
        line += t.text.count("\n")
    return out


def _header_ids(repo: Path, src: Path, seen=None) -> set:
    """Every identifier of the headers `src` includes with quotes, transitively (its dir, then <repo>/include)."""
    import ctoken as ct
    seen = set() if seen is None else seen
    out = set()
    try:
        txt = src.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return out
    for name in _INC.findall(txt):
        for b in (src.parent, Path(repo) / "include"):
            h = (b / name).resolve()
            if h.is_file():
                if h not in seen:
                    seen.add(h)
                    out |= {t.text for t in ct.tokenize(h.read_text(encoding="utf-8", errors="replace"))
                            if t.kind == "id"}
                    out |= {m.group() for t in ct.tokenize(h.read_text(encoding="utf-8", errors="replace"))
                            if t.kind == "pp" for m in _ID.finditer(t.text)}
                    out |= _header_ids(repo, h, seen)
                break
    return out


def inert_edit(old: str, new: str, header_ids=lambda: set()) -> str | None:
    """Why the edit old -> new of one source changes no compare verdict ("comments only", "unreferenced marker"),
    or None when it might (see the scope notes above). `header_ids()`: the identifiers of its headers."""
    so, sn = _signature(old), _signature(new)
    if so == sn:
        return "comments only"
    if len(so) != len(sn):
        return None
    words = set()
    for a, b in zip(so, sn):
        if a == b:
            continue
        ma, mb = _EXT_MARK.match(a[2]), _EXT_MARK.match(b[2])
        if a[0] != b[0] or a[1] != "dir" or b[1] != "dir" or not ma or not mb \
                or ma.group(1).upper() != mb.group(1).upper() or int(ma.group(2), 16) != int(mb.group(2), 16):
            return None
        words |= set(_ID.findall(R.undecorate(ma.group(3)))) ^ set(_ID.findall(R.undecorate(mb.group(3))))
        words |= {ma.group(3), mb.group(3)}
    code = {t for _l, k, t in so + sn if k == "id"} | \
        {m.group() for _l, k, t in so + sn if k == "pp" for m in _ID.finditer(t)}
    if not words or words & code or words & header_ids():
        return None
    return "unreferenced marker"


def inert_changes(repo, txn: Txn) -> dict:
    """{TU: why} for the TUs the edits of `txn` would compile (tus_of) that need not be: a changed source whose
    edit is inert (inert_edit), and a TU that is in only because it includes headers whose edit is comments only
    (same signature: the includer's token stream is unchanged). Never a TU that includes a header with any other
    edit, a source of a changed fixture, or a new/renamed file."""
    repo = Path(repo).resolve()
    files = txn.files()

    def texts(rel):
        old, p = txn.orig.get(rel), repo / rel
        if old is None or not p.is_file():
            return None
        return old.decode("utf-8", "replace"), p.read_bytes().decode("utf-8", "replace")

    hdrs = [f for f in files if f.lower().endswith((".h", ".hpp", ".inl"))]
    quiet_hdrs = []
    for h in hdrs:
        t = texts(h)
        if t is not None and h not in {x for pair in txn.renamed for x in pair} and _signature(t[0]) == _signature(t[1]):
            quiet_hdrs.append(h)
    live_hdrs = [h for h in hdrs if h not in quiet_hdrs]
    held = set(dependents(repo, live_hdrs)) if live_hdrs else set()
    held |= set(tus_of(repo, [f for f in files if f.startswith("tests/unicorn/")]))
    held |= {x for pair in txn.renamed for x in pair}
    quiet_tus = set(dependents(repo, quiet_hdrs)) if quiet_hdrs else set()
    out = {}
    for rel in tus_of(repo, files):
        if rel in held:
            continue
        if rel not in files:
            if rel in quiet_tus:
                out[rel] = "only comment edits in its headers"
            continue
        t = texts(rel)
        if t is None:
            continue
        p = repo / rel
        why = inert_edit(t[0], t[1], lambda: _header_ids(repo, p))
        if why:
            out[rel] = why + (" (and comment edits in its headers)" if rel in quiet_tus else "")
    return out


# --- bisecting a failed map ---------------------------------------------------------------------------------------

def bisect(items, run, first=None, log=print) -> tuple[int, list]:
    """Find the items of a failed map that the gate rejects, keeping the rest. `run(group)` applies `group` on top of
    what is kept, gates it, keeps it on a pass and restores it on a failure -> (rc, Verdict or None when nothing was
    applied). `first`: the verdict of the whole `items` already run (else it is run here).
    A failing group is split in halves, the first half before the second (the map's order); a half that passes is
    kept whole. When the first half passed whole, the second must hold the failure, so it is split without
    gating it as a whole. One bad item in n costs about 2*log2(n) gates instead of n.
    -> (max rc of the runs, [(item, Verdict)] rejected)."""
    rc, rejected = 0, []

    def go(group, v=None, known_bad=False) -> bool:
        nonlocal rc
        if v is None and not (known_bad and len(group) > 1):
            rc_g, v = run(group)
            rc = max(rc, rc_g)
            if v is None or v.ok:
                return True
        if len(group) == 1:
            rejected.append((group[0], v))
            return False
        mid = (len(group) + 1) // 2
        log(f"gate failed for {len(group)} item(s): bisecting ({mid} + {len(group) - mid})")
        left = go(group[:mid])
        go(group[mid:], known_bad=left)
        return False

    if items:
        go(list(items), first)
    return rc, rejected


# --- command line -----------------------------------------------------------------------------------------------

def main(argv=None) -> int:
    argv = sys.argv[1:] if argv is None else list(argv)
    if argv[:1] == ["_compare"]:
        return _compare_main(argv[1:])
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["snapshot", "check"])
    ap.add_argument("files", nargs="*", help="changed files (default: git diff HEAD + untracked)")
    ap.add_argument("--repo", default=".")
    ap.add_argument("--before", help="check: a snapshot JSON taken before the edit")
    ap.add_argument("--base", help="check: compare the before side on a git archive of this commit instead")
    ap.add_argument("--renames", action="append", default=[], help="rename.py --journal file(s): the renamed VAs")
    ap.add_argument("--fixtures", choices=["renamed", "tu", "none"], default="renamed")
    ap.add_argument("--cache", help="work folder (default <build>/readability/titanium)")
    ap.add_argument("--json", help="snapshot: write it here; check: write the verdict here")
    a = ap.parse_args(argv)
    repo = Path(a.repo).resolve()
    files = [Path(f).resolve().relative_to(repo).as_posix() if Path(f).is_absolute() else f.replace("\\", "/")
             for f in a.files]
    try:
        if a.cmd == "snapshot":
            snap = snapshot(repo, files or changed_files(repo), a.cache)
            if a.json:
                Path(a.json).write_text(json.dumps(snap, indent=1), encoding="utf-8")
            print(f"snapshot: {len(snap['tus'])} TU(s), {len(snap['compare'])} functions")
            return 0
        files = files or changed_files(repo, a.base or "HEAD")
        if a.before:
            before = json.loads(Path(a.before).read_text(encoding="utf-8"))
        elif a.base:
            root = base_tree(repo, a.base, work_dir(repo, a.cache))
            tus = [t for t in tus_of(repo, files) if (root / t).is_file()]
            before = snapshot(root, tus=tus, cache=a.cache, tag="base")
        else:
            print("match_gate check: give --before SNAPSHOT or --base REV")
            return 2
        vas = renamed_vas(a.renames) if a.renames else None
        v = check(repo, before, files, a.cache, vas, a.fixtures)
    except (RuntimeError, FileNotFoundError, subprocess.CalledProcessError) as e:
        print(f"match_gate: {e}")
        return 2
    print(v.report())
    if a.json:
        Path(a.json).write_text(json.dumps(v.as_json(), indent=1), encoding="utf-8")
    return 0 if v.ok else 1


if __name__ == "__main__":
    sys.exit(main())
