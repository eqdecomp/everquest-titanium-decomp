"""match_gate's bisect of a failed map, its inert-edit scope and its result cache (no compiler: fake gates and a
stubbed compare process), on the synthetic Titanium repo of test_titanium.py."""
import json
import math
import subprocess
from pathlib import Path

import pytest

import match_gate as MG
from test_titanium import make_titanium, text, write


class FakeVerdict:
    def __init__(self, ok, why=""):
        self.ok = ok
        self.problems, self.regressions, self.fixtures_failed = ([] if ok else [why]), [], []


def fake_gate(bad, together=()):
    """run(group) for MG.bisect: the kept items grow on a pass; a group fails when it holds an item of `bad`, or
    when the kept items plus the group hold every item of `together` (a clash of two renames)."""
    kept, calls = [], []

    def run(group):
        calls.append(list(group))
        now = kept + list(group)
        fail = any(x in bad for x in group) or (together and set(together) <= set(now) and set(together) & set(group))
        if fail:
            return 0, FakeVerdict(False, f"bad in {group}")
        kept.extend(group)
        return 0, FakeVerdict(True)
    return run, kept, calls


def test_bisect_finds_one_bad_item_in_log_time():
    items = list(range(70))
    run, kept, calls = fake_gate({41})
    rc, v = run(items)
    assert not v.ok
    rc, rejected = MG.bisect(items, run, first=v, log=lambda m: None)
    assert [x for x, _v in rejected] == [41]
    assert kept == [x for x in items if x != 41]                # map order kept, everything else kept
    assert len(calls) <= 1 + 2 * math.ceil(math.log2(70))       # the map + about 2 per level, not 70
    assert len(calls) < 15


def test_bisect_several_bad_and_a_clash():
    items = list("abcdefghijklmnop")
    run, kept, calls = fake_gate({"c", "n"}, together=("e", "k"))
    rc, rejected = MG.bisect(items, run, log=lambda m: None)    # runs the map itself
    assert sorted(x for x, _v in rejected) == ["c", "k", "n"]   # k clashes with the kept e: the later one goes
    assert kept == [x for x in items if x not in "ckn"]
    assert len(calls) <= 1 + 3 * 2 * 4                            # 3 bad in 16: at most ~2 log2(n) each


def test_bisect_nothing_applied_and_all_good():
    run, kept, calls = fake_gate(set())
    assert MG.bisect([1, 2, 3], run, log=lambda m: None) == (0, [])
    assert kept == [1, 2, 3] and len(calls) == 1
    assert MG.bisect([1], lambda g: (2, None), log=lambda m: None) == (2, [])     # all refused: nothing to gate


# --- scope ---------------------------------------------------------------------------------------------------------

SRC = """\
// CFLAGS: /O1
// EXTERNAL: TITANIUM 0x00401000 Helper_guess
int __cdecl Helper_guess(int v);
// EXTERNAL: TITANIUM 0x00402000 Unused_guess

// FUNCTION: TITANIUM 0x00403000
int Use_guess(int v) {
    return Helper_guess(v);   // calls Helper_guess
}
"""


def test_inert_edit_rules():
    hdr = lambda: {"Spelled_guess"}                                     # noqa: E731
    same = SRC.replace("// calls Helper_guess", "// calls Better_guess")
    assert MG.inert_edit(SRC, same, hdr) == "comments only"
    # an unreferenced marker: neither name is spelled in the code or its headers
    assert MG.inert_edit(SRC, SRC.replace("0x00402000 Unused_guess", "0x00402000 Unused2_guess"), hdr) == \
        "unreferenced marker"
    # a marker the code uses: renaming it alone would stop it mapping the call
    assert MG.inert_edit(SRC, SRC.replace("0x00401000 Helper_guess", "0x00401000 Other_guess"), hdr) is None
    # the new name spelled in an included header: not provably inert
    assert MG.inert_edit(SRC, SRC.replace("0x00402000 Unused_guess", "0x00402000 Spelled_guess"), hdr) is None
    # a marker moved to another VA, a FUNCTION/CFLAGS directive, a code token, a line shift: never inert
    assert MG.inert_edit(SRC, SRC.replace("0x00402000 Unused_guess", "0x00402004 Unused_guess"), hdr) is None
    assert MG.inert_edit(SRC, SRC.replace("// CFLAGS: /O1", "// CFLAGS: /O2"), hdr) is None
    assert MG.inert_edit(SRC, SRC.replace("0x00403000", "0x00403004"), hdr) is None
    assert MG.inert_edit(SRC, SRC.replace("return Helper_guess(v)", "return Helper_guess(v + 0)"), hdr) is None
    assert MG.inert_edit(SRC, SRC.replace("// calls Helper_guess", "// calls\n"), hdr) is None
    assert MG.inert_edit(SRC, SRC.replace("// calls Helper_guess", "/* calls */"), hdr) == "comments only"


def test_inert_changes_skips_only_provable_tus(tmp_path, monkeypatch):
    ti = make_titanium(tmp_path / "ti")
    write(ti / "src/EverQuest/tu_009.cpp", SRC)
    write(ti / "src/EverQuest/tu_010.cpp", '#include "titanium/eqaddr.h"\n' + SRC)
    t = MG.Txn(ti)
    t.write("src/EverQuest/tu_009.cpp", SRC.replace("0x00402000 Unused_guess", "0x00402000 Unused2_guess"))
    t.write("src/EverQuest/tu_002.cpp", text(ti, "src/EverQuest/tu_002.cpp").replace("FUN_0040100a_guess(v)",
                                                                                     "FUN_0040100a_guess(v + 0)"))
    t.write("src/EverQuest/tu_010.cpp", text(ti, "src/EverQuest/tu_010.cpp") + "// a comment\n")
    hdr = text(ti, "include/titanium/eqaddr.h")
    t.write("include/titanium/eqaddr.h", hdr + "#define EXTRA_GUESS 1\n")             # tu_001, tu_010 include it
    assert MG.inert_changes(ti, t) == {"src/EverQuest/tu_009.cpp": "unreferenced marker"}
    t.write("include/titanium/eqaddr.h", hdr + "/* EQ_GLOBAL reads a client global */\n")   # comments only
    assert MG.inert_changes(ti, t) == {"src/EverQuest/tu_009.cpp": "unreferenced marker",
                                       "src/EverQuest/tu_001.cpp": "only comment edits in its headers",
                                       "src/EverQuest/tu_010.cpp": "comments only (and comment edits in its headers)"}
    t.write("include/titanium/eqaddr.h", hdr + "#define EXTRA_GUESS 1\n")
    # the gate leaves the inert TU out of both compares and says so
    seen = []

    def fake(repo, tus, cache, tag, client="titanium", log=print):
        seen.append((tag, list(tus)))
        return {}
    monkeypatch.setattr(MG, "compare_tus", fake)
    monkeypatch.setattr(MG, "run_fixtures", lambda *a, **k: ([], [], ""))
    v = MG.gate_txn(ti, t, set(), cache=tmp_path / "c")
    assert v.ok and all("src/EverQuest/tu_009.cpp" not in tus for _t, tus in seen)
    assert "src/EverQuest/tu_002.cpp" in seen[0][1] and "src/EverQuest/tu_010.cpp" in seen[0][1]
    assert any("tu_009.cpp (unreferenced marker)" in n for n in v.notes)
    t.restore()


# --- result cache ------------------------------------------------------------------------------------------------

def test_compare_cache_reuses_verdicts_of_the_same_tree(tmp_path, monkeypatch):
    ti = make_titanium(tmp_path / "ti")
    runs = []
    real_run = subprocess.run

    def fake_run(cmd, **kw):
        if "_compare" not in cmd:
            return real_run(cmd, **kw)
        tus = cmd[cmd.index("--json") + 2:]
        runs.append(tus)
        js = Path(cmd[cmd.index("--json") + 1])
        per = {t: [{"va": f"0x{0x401000 + i:08X}", "match": "identical", "ndiff": 0, "name": t, "source": t}]
               for i, t in enumerate(tus)}
        js.write_text(json.dumps({"per_tu": per}), encoding="utf-8")
        return subprocess.CompletedProcess(cmd, 0, "", "")
    monkeypatch.setattr(MG.subprocess, "run", fake_run)
    monkeypatch.delenv("EQD_GATE_COMPARE", raising=False)
    cache = tmp_path / "cache"
    a = MG.compare_tus(ti, ["src/EverQuest/tu_001.cpp", "src/EverQuest/tu_002.cpp"], cache, "before")
    b = MG.compare_tus(ti, ["src/EverQuest/tu_002.cpp", "src/EverQuest/tu_001.cpp"], cache, "after")
    assert runs == [["src/EverQuest/tu_001.cpp", "src/EverQuest/tu_002.cpp"]] and a == b   # second: all cached
    MG.compare_tus(ti, ["src/EverQuest/tu_001.cpp", "src/EverQuest/tu_003.cpp"], cache, "x")
    assert runs[-1] == ["src/EverQuest/tu_003.cpp"]                                      # only the new TU
    write(ti / "src/EverQuest/tu_004.cpp", text(ti, "src/EverQuest/tu_004.cpp") + "// edited\n")
    MG.compare_tus(ti, ["src/EverQuest/tu_001.cpp"], cache, "y")                       # another tree: no reuse
    assert runs[-1] == ["src/EverQuest/tu_001.cpp"]
