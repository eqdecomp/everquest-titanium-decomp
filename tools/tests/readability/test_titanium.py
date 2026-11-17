"""The readability tools on a synthetic Titanium repo (file-local class views, EXTERNAL markers, MSVC 7.1 decorated
names in fixtures): registry, rename.py's view/fixture/queue handling, the match gate (compare and the fixtures
stubbed: no compiler here) and driver.py's fn stage in dry-run mode."""
import json
import subprocess
from pathlib import Path

import pytest

import match_gate as MG
import registry as R
import rename as rn

EQADDR = """\
#ifndef TITANIUM_EQADDR_H
#define TITANIUM_EQADDR_H
#define EQ_GLOBAL(type, va) (*(type *)(va))
#endif
"""

# 0x0040100A is defined as FUN_0040100A_guess; its callers spell it FUN_0040100a_guess (another C++ identifier,
# tied to it by the marker), RoundOdd_guess (tu_003's own view name) or Helper_guess::Round_guess (a member view).
TU1 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
#include "titanium/eqaddr.h"

struct Table_guess {
    int count;
    void Grow_guess(int extra);
};

// FUNCTION: TITANIUM 0x0040100A
int __cdecl FUN_0040100A_guess(int value) {
    return value | 1;
}

// FUNCTION: TITANIUM 0x00401020
void Table_guess::Grow_guess(int extra) {
    count = FUN_0040100A_guess(count + extra);   // FUN_0040100A_guess makes it odd
}
"""

TU2 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXTERNAL: TITANIUM 0x0040100A FUN_0040100a_guess
int __cdecl FUN_0040100a_guess(int value);

// FUNCTION: TITANIUM 0x00402000
int CallTwice_guess(int v) {
    return FUN_0040100a_guess(FUN_0040100a_guess(v));
}
"""

TU3 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXTERNAL: TITANIUM 0x0040100A RoundOdd_guess
int __cdecl RoundOdd_guess(int value);

struct Helper_guess {
    // EXTERNAL: TITANIUM 0x00401020 Helper_guess::Grow_guess
    void Grow_guess(int extra);
};

// FUNCTION: TITANIUM 0x00403000
int UseRound_guess(Helper_guess* h, int v) {
    h->Grow_guess(v);
    return RoundOdd_guess(v);
}
"""

# another view's Grow_guess at another VA: renaming Table_guess::Grow_guess must not touch it
TU4 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct Other_guess {
    int size;
    void Grow_guess(int extra);
};

// FUNCTION: TITANIUM 0x00404000
void Other_guess::Grow_guess(int extra) {
    size += extra;
}
"""

FIX_OWN = {"function": "FUN_0040100A_guess", "original": "0x0040100a", "sources": ["src/EverQuest/tu_001.cpp"],
           "rewrite": "?FUN_0040100A_guess@@YAHH@Z", "conv": "cdecl", "args": [], "ret": "u32", "cases": []}
FIX_CALLER = {"function": "Table_guess::Grow_guess", "original": "0x00401020", "sources": ["src/EverQuest/tu_001.cpp"],
              "conv": "thiscall", "args": [], "ret": "void", "cases": [],
              "callees": {"0x0040100A": {"name": "FUN_0040100a", "conv": "cdecl", "args": ["int"]}},
              "rewrite_aliases": {"?FUN_0040100A_guess@@YAHH@Z": "0x0040100A", "_strlen": "0x00500000"}}
CRT = {"rewrite_aliases": {"?RoundOdd_guess@@YAHH@Z": "0x0040100A", "?Grow_guess@Table_guess@@QAEXH@Z": "0x00401020",
                           "__ftol2": "0x0060E98C"}}


def write(p: Path, text: str):
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text, encoding="utf-8", newline="\n")


def jdump(d) -> str:
    return json.dumps(d, indent=2) + "\n"


def make_titanium(root: Path, git=False) -> Path:
    write(root / "tests/unicorn/conftest.py", 'PRIMARY = "titanium"\n')
    write(root / "include/titanium/eqaddr.h", EQADDR)
    write(root / "src/EverQuest/tu_001.cpp", TU1)
    write(root / "src/EverQuest/tu_002.cpp", TU2)
    write(root / "src/EverQuest/tu_003.cpp", TU3)
    write(root / "src/EverQuest/tu_004.cpp", TU4)
    write(root / "tests/unicorn/EverQuest/tu_001/FUN_0040100A.json", jdump(FIX_OWN))
    write(root / "tests/unicorn/EverQuest/tu_001/Grow.json", jdump(FIX_CALLER))
    write(root / "tests/unicorn/crt_defaults.json", jdump(CRT))
    q = [{"address": "0040100A", "name": "FUN_0040100a", "state": "tested"},
         {"address": "00401020", "name": "FUN_00401020", "state": "tested"},
         {"address": "00404000", "name": "Other_guess::Grow_guess", "state": "tested"}]
    write(root / "queue/queue.jsonl", "".join(json.dumps(x) + "\n" for x in q))
    if git:
        for cmd in (["init", "-q"], ["config", "user.email", "t@example.com"], ["config", "user.name", "t"],
                    ["config", "core.autocrlf", "false"], ["add", "-A"], ["commit", "-qm", "base"]):
            subprocess.run(["git", *cmd], cwd=root, check=True, capture_output=True)
    return root


@pytest.fixture
def ti(tmp_path):
    return make_titanium(tmp_path / "ti")


def text(repo, rel):
    return (repo / rel).read_text(encoding="utf-8")


def snapshot_tree(repo: Path) -> dict:
    return {p.relative_to(repo).as_posix(): p.read_bytes() for p in sorted(repo.rglob("*")) if p.is_file()
            and ".git" not in p.parts}


# --- registry ----------------------------------------------------------------------------------------------------

def test_registry_knows_titanium(ti):
    assert R.repo_clients(ti) == ("titanium",)
    reg = R.build(ti, "titanium")
    assert "include/titanium/eqaddr.h" in reg.files                  # include/titanium belongs to titanium
    e = reg.entries[0x0040100A]
    assert e.ann_name == "FUN_0040100A_guess"
    assert {s.name for s in e.by("external")} == {"FUN_0040100a_guess", "RoundOdd_guess"}
    assert [s.extra["symbol"] for s in e.by("alias")] == ["?RoundOdd_guess@@YAHH@Z"]
    assert reg.entries[0x00401020].canonical == "Table_guess::Grow_guess"
    kinds = {k for k, *_ in reg.conflicts()}
    assert "queue_fun" in kinds                                        # source has a name, the queue only FUN_
    # FUN_<va>_guess counts as unnamed for Titanium: 0x0040100A is no queue_fun conflict
    assert not [c for c in reg.conflicts() if c[0] == "queue_fun" and c[1] == 0x0040100A]
    assert R.is_unnamed("FUN_0040100A_guess") and R.is_unnamed("Cls::FUN_0040100a") and not R.is_fun("FUN_0040100A_guess")


def test_trilogy_clients_unchanged(repo):
    assert R.repo_clients(repo) == R.CLIENT_IDS                       # a bare repo: eq-trilogy's three images
    assert R.include_owner("include/trilogy/x.h") == "trilogy" and R.include_owner("include/eqmain/x.h") == "eqmain"
    assert R.include_owner("include/titanium/x.h", "titanium") == "titanium"


# --- rename.py ---------------------------------------------------------------------------------------------------

def test_function_rename_follows_every_view_marker_fixture_and_queue(ti):
    plan = rn.plan_rename(ti, "titanium", "0x0040100A", "MakeOdd_guess")
    rn.write_plan(ti, plan)
    t1, t2, t3 = (text(ti, f"src/EverQuest/tu_00{i}.cpp") for i in (1, 2, 3))
    assert "int __cdecl MakeOdd_guess(int value)" in t1 and "// MakeOdd_guess makes it odd" in t1
    assert "FUN_0040100" not in t1
    # the caller's spelling (other letter case) follows, marker included
    assert "// EXTERNAL: TITANIUM 0x0040100A MakeOdd_guess\nint __cdecl MakeOdd_guess(int value);" in t2
    assert "MakeOdd_guess(MakeOdd_guess(v))" in t2
    # tu_003's own free-function view name follows; its member view of another VA is not touched
    assert "// EXTERNAL: TITANIUM 0x0040100A MakeOdd_guess" in t3 and "return MakeOdd_guess(v);" in t3
    assert "Helper_guess::Grow_guess" in t3
    own = json.loads(text(ti, "tests/unicorn/EverQuest/tu_001/FUN_0040100A.json"))
    assert own["function"] == "MakeOdd_guess" and own["rewrite"] == "?MakeOdd_guess@@YAHH@Z"
    caller = json.loads(text(ti, "tests/unicorn/EverQuest/tu_001/Grow.json"))
    assert caller["callees"]["0x0040100A"]["name"] == "MakeOdd_guess"            # stale FUN_ label, by VA
    assert caller["rewrite_aliases"] == {"?MakeOdd_guess@@YAHH@Z": "0x0040100A", "_strlen": "0x00500000"}
    crt = json.loads(text(ti, "tests/unicorn/crt_defaults.json"))["rewrite_aliases"]
    assert "?MakeOdd_guess@@YAHH@Z" in crt and "?RoundOdd_guess@@YAHH@Z" not in crt   # the view name's alias
    assert "?Grow_guess@Table_guess@@QAEXH@Z" in crt
    q = [json.loads(x) for x in text(ti, "queue/queue.jsonl").splitlines()]
    assert q[0]["name"] == "MakeOdd_guess"
    assert not (ti / "names").exists()                                # Titanium has no names/*.csv
    j = plan.journal()[0]
    assert (j["va"], j["kind"], j["old"], j["new"]) == ("0040100A", "fn", "FUN_0040100A_guess", "MakeOdd_guess")


def test_member_rename_leaves_other_views_alone(ti):
    plan = rn.plan_rename(ti, "titanium", "Table_guess::Grow_guess", "Expand_guess")
    rn.write_plan(ti, plan)
    assert "void Table_guess::Expand_guess(int extra)" in text(ti, "src/EverQuest/tu_001.cpp")
    assert text(ti, "src/EverQuest/tu_004.cpp") == TU4                 # Other_guess::Grow_guess is 0x00404000
    t3 = text(ti, "src/EverQuest/tu_003.cpp")                          # a view of 0x00401020: marker + member follow
    assert "// EXTERNAL: TITANIUM 0x00401020 Helper_guess::Expand_guess" in t3 and "h->Expand_guess(v)" in t3
    assert any("kept src/EverQuest/tu_004.cpp" in n for n in plan.notes)
    crt = json.loads(text(ti, "tests/unicorn/crt_defaults.json"))["rewrite_aliases"]
    assert crt.get("?Expand_guess@Table_guess@@QAEXH@Z") == "0x00401020"
    assert json.loads(text(ti, "tests/unicorn/EverQuest/tu_001/Grow.json"))["function"] == "Table_guess::Expand_guess"


def test_keep_views_and_no_comments_still_follow_markers(ti):
    plan = rn.plan_rename(ti, "titanium", "0x0040100A", "MakeOdd_guess", views=False, comments=False)
    rn.write_plan(ti, plan)
    assert "RoundOdd_guess" in text(ti, "src/EverQuest/tu_003.cpp")    # --keep-views: tu_003 keeps its name
    t2 = text(ti, "src/EverQuest/tu_002.cpp")
    assert "// EXTERNAL: TITANIUM 0x0040100A MakeOdd_guess" in t2       # a marker is code, not a comment
    assert "// FUN_0040100A_guess makes it odd" in text(ti, "src/EverQuest/tu_001.cpp")


def test_titanium_refusals(ti):
    write(ti / "src/EverQuest/tu_005.cpp", "// EXTERNAL: TITANIUM 0x00401020 Table_guess::Grow_guess\n"
          "// EXTERNAL: TITANIUM 0x00404000 Other_guess::Grow_guess\n")
    with pytest.raises(rn.Refused, match="two views in one file"):
        rn.plan_rename(ti, "titanium", "0x00401020", "Expand_guess")
    # a free function named like another VA's member, called with no marker: which one is it? refused
    write(ti / "src/EverQuest/tu_005.cpp", "// FUNCTION: TITANIUM 0x00405000\nint Twin_guess(int v) { return v; }\n")
    write(ti / "src/EverQuest/tu_006.cpp", "struct Box_guess { int Twin_guess(int v); };\n"
          "// FUNCTION: TITANIUM 0x00406000\nint Box_guess::Twin_guess(int v) { return v; }\n")
    write(ti / "src/EverQuest/tu_007.cpp", "int Twin_guess(int v);\nint Use_guess() { return Twin_guess(1); }\n")
    with pytest.raises(rn.Refused, match="has that name too"):
        rn.plan_rename(ti, "titanium", "0x00405000", "Single_guess")


def test_titanium_member_name_clash_is_refused(ti):
    write(ti / "src/EverQuest/tu_006.cpp", "struct Table_guess { void Fill_guess(); };\n"
          "// FUNCTION: TITANIUM 0x00406000\nvoid Table_guess::Fill_guess() {}\n")
    with pytest.raises(rn.Refused, match="already the name"):
        rn.plan_rename(ti, "titanium", "0x00401020", "Fill_guess")


def test_mangled_rename():
    assert rn.mangled_rename("?Old_guess@Cls_guess@@QAEXH@Z", "Old_guess", "New_guess") == "?New_guess@Cls_guess@@QAEXH@Z"
    assert rn.mangled_rename("?Old@B@A@@QAEXXZ", "Old", "New", cls="A::B") == "?New@B@A@@QAEXXZ"
    assert rn.mangled_rename("?Old@B@A@@QAEXXZ", "Old", "New", cls="B") is None            # another scope
    assert rn.mangled_rename("?FUN_0040100a@@YAXXZ", "FUN_0040100A_guess", "N", va=0x0040100A) == "?N@@YAXXZ"
    assert rn.mangled_rename("??0Cls@@QAE@XZ", "Cls", "New") is None                         # ctors are not names
    with pytest.raises(rn.Refused, match="back-reference"):
        rn.mangled_rename("?Old@@YAXPAUNew@@@Z", "Old", "New")                               # NEW is a type there
    with pytest.raises(rn.Refused, match="back-reference"):
        rn.mangled_rename("?Old@@YAXPAU0@@Z", "Old", "New")                                  # refers back to OLD


# --- match gate --------------------------------------------------------------------------------------------------

def test_judge_rules():
    b = {1: {"status": "identical", "name": "a"}, 2: {"status": "diff", "ndiff": 3, "name": "b"},
         3: {"status": "structural", "ndiff": 9, "name": "c"}, 4: {"status": "identical", "name": "d"}}
    same = {k: dict(v) for k, v in b.items()}
    assert MG.judge(b, same) == []
    a = dict(same)
    a[1] = {"status": "normalised", "name": "a"}
    a[2] = {"status": "diff", "ndiff": 4, "name": "b"}
    a[3] = {"status": "diff", "ndiff": 2, "name": "c"}                 # better: fine
    del a[4]
    a[5] = {"status": "identical", "name": "e"}
    out = MG.judge(b, a)
    assert len(out) == 4 and out[0].startswith("0x00000001 a: identical -> normalised")
    assert any("ndiff 3 -> 4" in x for x in out) and any("gone" in x for x in out) and any("new function" in x for x in out)


def test_txn_restores_and_swaps(tmp_path):
    (tmp_path / "a.txt").write_text("old", encoding="utf-8")
    t = MG.Txn(tmp_path)
    t.write("a.txt", "new")
    t.write("b.txt", "made")
    now = t.swap()
    assert (tmp_path / "a.txt").read_text() == "old" and not (tmp_path / "b.txt").exists()
    t.unswap(now)
    assert (tmp_path / "a.txt").read_text() == "new" and (tmp_path / "b.txt").read_text() == "made"
    t.restore()
    assert (tmp_path / "a.txt").read_text() == "old" and not (tmp_path / "b.txt").exists()


def test_tus_and_fixture_selection(ti):
    assert MG.tus_of(ti, ["include/titanium/eqaddr.h"]) == ["src/EverQuest/tu_001.cpp"]
    assert MG.tus_of(ti, ["tests/unicorn/EverQuest/tu_001/Grow.json", "src/EverQuest/tu_002.cpp"]) == \
        ["src/EverQuest/tu_001.cpp", "src/EverQuest/tu_002.cpp"]
    fx = MG.select_fixtures(ti, {0x0040100A}, [], [])
    assert fx == ["tests/unicorn/EverQuest/tu_001/FUN_0040100A.json", "tests/unicorn/EverQuest/tu_001/Grow.json"]
    assert MG.select_fixtures(ti, {0x00404000}, [], []) == []
    assert MG.select_fixtures(ti, set(), [], ["src/EverQuest/tu_001.cpp"], mode="tu") == fx
    assert MG.select_fixtures(ti, {0x0040100A}, [], [], mode="none") == []


def _fake_compare(bad_marker=None):
    """compare_tus stand-in: every annotated function of the TUs is identical, except in a file that contains
    `bad_marker`, whose functions come out as diff."""
    from eqd_unicorn import annotations as ann

    def fake(repo, tus, cache, tag, client="titanium", log=print):
        out = {}
        for t in tus:
            raw = (Path(repo) / t).read_text(encoding="utf-8")
            for a in ann.scan([Path(repo) / t], "TITANIUM"):
                bad = bad_marker is not None and bad_marker in raw
                out[a.va] = {"status": "diff" if bad else "identical", "ndiff": 1 if bad else 0, "name": a.name,
                             "source": t}
        return out
    return fake


def test_gated_rename_keeps_a_passing_map(ti, tmp_path, monkeypatch, capsys):
    ran = []
    monkeypatch.setattr(MG, "compare_tus", _fake_compare())
    monkeypatch.setattr(MG, "run_fixtures", lambda repo, rels, cache, tag: (ran.append((tag, list(rels))), ([], [], ""))[1])
    j = tmp_path / "j.jsonl"
    rc = rn.main(["-c", "titanium", "--repo", str(ti), "0x0040100A", "MakeOdd_guess", "--gate", "--journal", str(j),
                  "--gate-cache", str(tmp_path / "cache"), "-q"])
    assert rc == 0
    assert "MakeOdd_guess" in text(ti, "src/EverQuest/tu_002.cpp")
    assert json.loads(j.read_text().splitlines()[0])["new"] == "MakeOdd_guess"
    assert ran and ran[0][0] == "after" and "tests/unicorn/EverQuest/tu_001/Grow.json" in ran[0][1]
    assert "PASS" in capsys.readouterr().out


def test_gated_rename_restores_on_a_regression(ti, tmp_path, monkeypatch, capsys):
    before = snapshot_tree(ti)
    monkeypatch.setattr(MG, "compare_tus", _fake_compare(bad_marker="BrokenOdd_guess"))
    monkeypatch.setattr(MG, "run_fixtures", lambda *a, **k: ([], [], ""))
    j = tmp_path / "j.jsonl"
    rc = rn.main(["-c", "titanium", "--repo", str(ti), "0x0040100A", "BrokenOdd_guess", "--gate", "--journal", str(j),
                  "--gate-cache", str(tmp_path / "cache"), "-q"])
    assert rc == 1
    assert snapshot_tree(ti) == before                                  # every file back, byte for byte
    assert not j.exists()
    out = capsys.readouterr().out
    assert "REGRESSION 0x0040100A" in out and "GATE-REJECTED 0x0040100A -> BrokenOdd_guess" in out


def test_gated_map_retries_items_alone(ti, tmp_path, monkeypatch, capsys):
    monkeypatch.setattr(MG, "compare_tus", _fake_compare(bad_marker="BrokenGrow_guess"))
    fixtures_failed = {"tests/unicorn/EverQuest/tu_001/Grow.json"}

    def fx(repo, rels, cache, tag):                                    # a fixture failure counts too
        bad = [r for r in rels if r in fixtures_failed and "BrokenGrow_guess" in text(ti, "src/EverQuest/tu_001.cpp")]
        return bad, [], ""
    monkeypatch.setattr(MG, "run_fixtures", fx)
    m = tmp_path / "map.json"
    m.write_text(json.dumps([{"old": "0x0040100A", "new": "MakeOdd_guess"},
                             {"old": "0x00401020", "new": "BrokenGrow_guess"}]), encoding="utf-8")
    rc = rn.main(["-c", "titanium", "--repo", str(ti), "--map", str(m), "--gate", "-q",
                  "--gate-cache", str(tmp_path / "cache"), "--gate-json", str(tmp_path / "g.json")])
    assert rc == 1
    t1 = text(ti, "src/EverQuest/tu_001.cpp")
    assert "MakeOdd_guess" in t1 and "BrokenGrow_guess" not in t1 and "Table_guess::Grow_guess" in t1
    assert "GATE-REJECTED 0x00401020 -> BrokenGrow_guess" in capsys.readouterr().out
    assert len(json.loads((tmp_path / "g.json").read_text())) == 3      # the map, then each item


def test_gate_py_hands_titanium_to_match_gate(ti, monkeypatch):
    import gate
    seen = []
    monkeypatch.setattr(MG, "main", lambda argv: seen.append(argv) or 0)
    assert gate.main(["--repo", str(ti), "--base", "HEAD", "src/EverQuest/tu_001.cpp"]) == 0
    assert seen[0][:5] == ["check", "--repo", str(ti.resolve()), "--base", "HEAD"]


# --- one name everywhere: member views ------------------------------------------------------------------------------

TU5 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct Holder_guess {
    // EXTERNAL: TITANIUM 0x00401020 Holder_guess::Enlarge_guess
    void Enlarge_guess(int extra);
    void Shrink_guess();
};

// FUNCTION: TITANIUM 0x00405000
void Holder_guess::Shrink_guess() {
    Enlarge_guess(-1);                       // Enlarge_guess backwards
}

int UseHolder_guess(Holder_guess* h) {
    h->Enlarge_guess(2);
    return 0;
}
"""

# a view whose class already has a member of the new name: kept and reported
TU6 = """\
struct Box_guess {
    // EXTERNAL: TITANIUM 0x00401020 Box_guess::Widen_guess
    void Widen_guess(int extra);
    void Expand_guess();
};
void UseBox_guess(Box_guess* b) { b->Widen_guess(1); b->Expand_guess(); }
"""

# another class of the file declares the view's member name too: a token swap would rename both
TU7 = """\
struct Bag_guess {
    // EXTERNAL: TITANIUM 0x00401020 Bag_guess::Stretch_guess
    void Stretch_guess(int extra);
};
struct Sack_guess {
    void Stretch_guess();
};
void UseBag_guess(Bag_guess* b, Sack_guess* s) { b->Stretch_guess(1); s->Stretch_guess(); }
"""

# the same view name as TU6's, free of clashes here: kept too, so the fixtures' spelling stays consistent
TU8 = """\
struct Crate_guess {
    // EXTERNAL: TITANIUM 0x00401020 ?Widen_guess@Crate_guess@@QAEXH@Z
    void Widen_guess(int extra);
};
void UseCrate_guess(Crate_guess* c) { c->Widen_guess(3); }
"""


def test_member_view_names_follow_the_rename(ti):
    write(ti / "src/EverQuest/tu_005.cpp", TU5)
    crt = json.loads(text(ti, "tests/unicorn/crt_defaults.json"))
    crt["rewrite_aliases"]["?Enlarge_guess@Holder_guess@@QAEXH@Z"] = "0x00401020"
    write(ti / "tests/unicorn/crt_defaults.json", jdump(crt))
    plan = rn.plan_rename(ti, "titanium", "0x00401020", "Expand_guess")
    rn.write_plan(ti, plan)
    t5 = text(ti, "src/EverQuest/tu_005.cpp")
    assert "// EXTERNAL: TITANIUM 0x00401020 Holder_guess::Expand_guess\n    void Expand_guess(int extra);" in t5
    assert "    Expand_guess(-1);" in t5 and "h->Expand_guess(2);" in t5 and "Enlarge_guess" not in t5
    assert "struct Holder_guess {" in t5 and "void Holder_guess::Shrink_guess()" in t5       # the class keeps its name
    assert "h->Expand_guess(v)" in text(ti, "src/EverQuest/tu_003.cpp")
    al = json.loads(text(ti, "tests/unicorn/crt_defaults.json"))["rewrite_aliases"]
    assert al.get("?Expand_guess@Holder_guess@@QAEXH@Z") == "0x00401020"
    assert "?Enlarge_guess@Holder_guess@@QAEXH@Z" not in al
    assert not any("kept view name" in n for n in plan.notes)


def test_member_view_name_collisions_are_kept_and_reported(ti):
    write(ti / "src/EverQuest/tu_005.cpp", TU5)
    for i, tu in ((6, TU6), (7, TU7), (8, TU8)):
        write(ti / f"src/EverQuest/tu_00{i}.cpp", tu)
    plan = rn.plan_rename(ti, "titanium", "0x00401020", "Expand_guess")
    rn.write_plan(ti, plan)
    assert text(ti, "src/EverQuest/tu_006.cpp") == TU6
    assert text(ti, "src/EverQuest/tu_007.cpp") == TU7
    assert text(ti, "src/EverQuest/tu_008.cpp") == TU8
    notes = "\n".join(plan.notes)
    assert "kept view name Box_guess::Widen_guess in src/EverQuest/tu_006.cpp (Expand_guess is already used" in notes
    assert "kept view name Bag_guess::Stretch_guess in src/EverQuest/tu_007.cpp (Sack_guess declares" in notes
    assert "kept view name Crate_guess::Widen_guess in src/EverQuest/tu_008.cpp (a member view name kept in " \
           "another file)" in notes
    assert "h->Expand_guess(2);" in text(ti, "src/EverQuest/tu_005.cpp")                  # the clean view follows


def test_member_view_clash_rules():
    ok = "struct V { void m(int); void n(); };\nvoid V::n() { m(1); this->m(2); }\nvoid f(V* v) { v->m(3); }\n"
    assert rn.member_view_clash(ok, "V", "m", "q") == ""
    assert "already used" in rn.member_view_clash(ok, "V", "m", "n")
    assert "unqualified outside V" in rn.member_view_clash(ok + "int m(int);\n", "V", "m", "q")
    assert "W declares m too" in rn.member_view_clash(ok + "struct W { void m(); };\n", "V", "m", "q")
    assert "W::m names another" in rn.member_view_clash(ok + "void g() { W::m(); }\n", "V", "m", "q")
    assert "preprocessor" in rn.member_view_clash(ok + "#define CALL_M(v) (v)->m(0)\n", "V", "m", "q")
    assert "in a header" in rn.member_view_clash(ok, "V", "m", "q", header_ids={"m"})
    nested = "struct V { struct In { int m; }; void m(int); };\n"
    assert "In declares m too" in rn.member_view_clash(nested, "V", "m", "q")


# one VA declared under two member names in one view (two signatures): one new name would make them overloads
TU9 = """\
struct Control_guess {
    // EXTERNAL: TITANIUM 0x00401020 Control_guess::ApplyTwo_guess
    void ApplyTwo_guess(int a);
    // EXTERNAL: TITANIUM 0x00401020 Control_guess::ApplyThree_guess
    void ApplyThree_guess(int a, int b);
};
void UseControl_guess(Control_guess* c) { c->ApplyTwo_guess(1); c->ApplyThree_guess(1, 2); }
"""


def test_member_view_with_two_names_of_the_va_is_kept(ti):
    write(ti / "src/EverQuest/tu_005.cpp", TU5)
    write(ti / "src/EverQuest/tu_009.cpp", TU9)
    plan = rn.plan_rename(ti, "titanium", "0x00401020", "Expand_guess")
    rn.write_plan(ti, plan)
    assert text(ti, "src/EverQuest/tu_009.cpp") == TU9
    assert any("kept view name Control_guess::ApplyTwo_guess in src/EverQuest/tu_009.cpp (its class gives the VA "
               "2 names" in n for n in plan.notes)
    assert "h->Expand_guess(2);" in text(ti, "src/EverQuest/tu_005.cpp")
