"""class_views.py and class_rename.py on a synthetic Titanium repo: TU-local class renames (tokens, markers, decorated
names, fixtures, crt_defaults twins), VA-family unification, typed field renames and their sibling views, and the
gated map (compare and the fixtures stubbed: no compiler here)."""
import json
from pathlib import Path

import pytest

import class_rename as cr
import class_views as CV
import match_gate as MG

EQADDR = """\
#ifndef TITANIUM_EQADDR_H
#define TITANIUM_EQADDR_H
#define EQ_GLOBAL(type, va) (*(type *)(va))
struct HeaderThing { int a; };
#endif
"""

TU10 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
#include "titanium/eqaddr.h"

struct Base_guess {
    int a;
};

// EXTERNAL: TITANIUM 0x00650000 ??_7Owner_guess@@6B@
struct Owner_guess : Base_guess {
    virtual void Slot00_guess();
    int field_8_guess;  // 0x8
    int count_c;        // 0xc
    // EXTERNAL: TITANIUM 0x00409000 Owner_guess::Helper_guess
    void Helper_guess();
    int Get_guess();
    Owner_guess* Self_guess();
    int Inline_guess() { return field_8_guess; }
};

struct Other_guess {
    int field_8_guess;
    int pad;
};

#define g_owner_guess EQ_GLOBAL(Owner_guess*, 0x00800000)

// FUNCTION: TITANIUM 0x00401000
int Owner_guess::Get_guess() {
    return field_8_guess + count_c;   // Owner_guess reads its own field_8_guess
}

// FUNCTION: TITANIUM 0x00401020
Owner_guess* Owner_guess::Self_guess() {
    return this;
}

// FUNCTION: TITANIUM 0x00401040
int __cdecl Sum_guess(Owner_guess* o, Other_guess* x) {
    Owner_guess* p = o;
    return o->field_8_guess + x->field_8_guess + g_owner_guess->field_8_guess + p->field_8_guess
        + ((Owner_guess*)x)->field_8_guess + (int)sizeof(Owner_guess) + "Owner_guess"[0];
}
"""

# another TU's own Owner_guess: a class rename in tu_010 must leave it alone
TU11 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct Owner_guess {
    int x;
};

struct Reader_guess {
    int handle_0;
    int count_4;
    // EXTERNAL: TITANIUM 0x00405000 Reader_guess::Reader_guess
    Reader_guess(const char* path);
};

// FUNCTION: TITANIUM 0x00402000
int UseOwner_guess(Owner_guess* o, Reader_guess* r) {
    return o->x + r->count_4;
}
"""

TU12 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct FileIn_guess {
    int h;
    int n;
    // EXTERNAL: TITANIUM 0x00405000 ??0FileIn_guess@@QAE@PBD@Z
    FileIn_guess(const char* path);
};

// FUNCTION: TITANIUM 0x00403000
int Lines_guess(FileIn_guess* f) {
    return f->n;
}
"""

# two views of the reader in one TU: a family rename can't give both one name
TU13 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct A_guess {
    char pad[8];
    // EXTERNAL: TITANIUM 0x00405000 A_guess::A_guess
    A_guess(const char* path);
};

struct B_guess {
    char pad[8];
    // EXTERNAL: TITANIUM 0x00405000 B_guess::B_guess
    B_guess(const char* path);
};
"""

# a view whose TU already has the family's new name as another class
TU14 = """\
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
struct LineReader_guess {
    int other;
};

struct In_guess {
    char pad[8];
    // EXTERNAL: TITANIUM 0x00405000 In_guess::In_guess
    In_guess(const char* path);
};
"""

FIX_GET = {"function": "Owner_guess::Get_guess", "original": "0x00401000", "sources": ["src/EverQuest/tu_010.cpp"],
           "rewrite": "?Get_guess@Owner_guess@@QAEHXZ", "conv": "thiscall", "args": [], "ret": "u32", "cases": [],
           "callees": {"0x00409000": {"name": "Owner_guess::Helper_guess", "conv": "thiscall", "args": []},
                       "0x00409100": {"name": "Owner_guess::Elsewhere_guess", "conv": "thiscall", "args": []},
                       "0x0040A000": {"name": "Owner_guess::Slot00_guess", "conv": "thiscall", "args": []}},
           "rewrite_aliases": {"?Helper_guess@Owner_guess@@QAEXXZ": "0x00409000", "_strlen": "0x00500000"}}
FIX_OTHER = {"function": "UseOwner_guess", "original": "0x00402000", "sources": ["src/EverQuest/tu_011.cpp"],
             "callees": {"0x00405000": {"name": "Owner_guess::Helper_guess"}}, "cases": []}
CRT = {"rewrite_aliases": {"?Helper_guess@Owner_guess@@QAEXXZ": "0x00409000",
                           "?Unrelated_guess@Owner_guess@@QAEXXZ": "0x00409999", "__ftol2": "0x0060E98C"}}


def write(p: Path, text: str):
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text, encoding="utf-8", newline="\n")


def jdump(d) -> str:
    return json.dumps(d, indent=2) + "\n"


@pytest.fixture
def tc(tmp_path):
    root = tmp_path / "tc"
    write(root / "tests/unicorn/conftest.py", 'PRIMARY = "titanium"\n')
    write(root / "include/titanium/eqaddr.h", EQADDR)
    for n, t in ((10, TU10), (11, TU11), (12, TU12), (13, TU13), (14, TU14)):
        write(root / f"src/EverQuest/tu_0{n}.cpp", t)
    write(root / "tests/unicorn/EverQuest/tu_010/Get.json", jdump(FIX_GET))
    write(root / "tests/unicorn/EverQuest/tu_011/Use.json", jdump(FIX_OTHER))
    write(root / "tests/unicorn/crt_defaults.json", jdump(CRT))
    write(root / "queue/queue.jsonl", json.dumps({"address": "00401000", "name": "FUN_00401000"}) + "\n")
    return root


def text(repo, rel):
    return (repo / rel).read_text(encoding="utf-8")


def tree(repo: Path) -> dict:
    return {p.relative_to(repo).as_posix(): p.read_bytes() for p in sorted(repo.rglob("*")) if p.is_file()}


# --- views and families ---------------------------------------------------------------------------------------------

def test_views_attribute_vtables_ctors_and_families(tc):
    vw = CV.load(tc)
    own = vw.by_name("src/EverQuest/tu_010.cpp", "Owner_guess")[0]
    assert own.vt == {0x00650000} and own.virtual and {0x00401000, 0x00401020, 0x00409000} <= own.meth
    fam = vw.family(0x00405000)
    assert sorted((v.file, v.name) for v in fam) == [
        ("src/EverQuest/tu_011.cpp", "Reader_guess"), ("src/EverQuest/tu_012.cpp", "FileIn_guess"),
        ("src/EverQuest/tu_013.cpp", "A_guess"), ("src/EverQuest/tu_013.cpp", "B_guess"),
        ("src/EverQuest/tu_014.cpp", "In_guess")]
    rows = vw.alias_rows()
    assert rows[0]["va"] == "00405000" and rows[0]["names"] == 5 and rows[0]["kind"] == "ctor"
    assert not vw.family(0x00409000) and vw.family(0x00409000, methods=True)


# --- decorated names ---------------------------------------------------------------------------------------------

def test_rename_class_in_symbol():
    f = cr.rename_class_in_symbol
    assert f("Owner_guess::Get_guess", "Owner_guess", "Wnd_guess") == "Wnd_guess::Get_guess"
    assert f("Owner_guess::~Owner_guess", "Owner_guess", "Wnd_guess") == "Wnd_guess::~Wnd_guess"
    assert f("CostOwner_guess::Get_guess", "Owner_guess", "Wnd_guess") == "CostOwner_guess::Get_guess"
    assert f("??_7Owner_guess@@6B@", "Owner_guess", "Wnd_guess") == "??_7Wnd_guess@@6B@"
    assert f("??0Owner_guess@@QAE@ABU0@@Z", "Owner_guess", "Wnd_guess") == "??0Wnd_guess@@QAE@ABU0@@Z"
    assert f("?Self_guess@Owner_guess@@QAEPAU1@XZ", "Owner_guess", "Wnd_guess") == "?Self_guess@Wnd_guess@@QAEPAU1@XZ"
    assert f("?Use@@YAHPAUOwner_guess@@@Z", "Owner_guess", "Wnd_guess") == "?Use@@YAHPAUWnd_guess@@@Z"
    assert f("?F@CostOwner_guess@@QAEXXZ", "Owner_guess", "Wnd_guess", {"CostOwner_guess"}) == \
        "?F@CostOwner_guess@@QAEXXZ"
    with pytest.raises(cr.Refused):              # `PAUXOwner_guess@`: X a type code or part of XOwner_guess?
        f("?Use@@YAHPAUXOwner_guess@@@Z", "Owner_guess", "Wnd_guess", {"XOwner_guess"})
    with pytest.raises(cr.Refused):              # NEW already in the symbol: a back-reference would be needed
        f("?Use@@YAHPAUOwner_guess@@PAUWnd_guess@@@Z", "Owner_guess", "Wnd_guess")


# --- class rename -------------------------------------------------------------------------------------------------

def test_class_rename_follows_tokens_markers_fixtures_and_crt(tc, tmp_path):
    other = text(tc, "src/EverQuest/tu_011.cpp"), text(tc, "tests/unicorn/EverQuest/tu_011/Use.json")
    j = tmp_path / "j.jsonl"
    rc = cr.main(["class", "src/EverQuest/tu_010.cpp", "Owner_guess", "GuildWnd_guess", "--repo", str(tc),
                  "--journal", str(j), "-q"])
    assert rc == 0
    t = text(tc, "src/EverQuest/tu_010.cpp")
    assert "Owner_guess" not in t.replace('"Owner_guess"', "")
    assert '"Owner_guess"[0]' in t                                  # string literals stay
    for s in ("// EXTERNAL: TITANIUM 0x00650000 ??_7GuildWnd_guess@@6B@", "struct GuildWnd_guess : Base_guess",
              "// EXTERNAL: TITANIUM 0x00409000 GuildWnd_guess::Helper_guess", "int GuildWnd_guess::Get_guess()",
              "GuildWnd_guess* GuildWnd_guess::Self_guess()", "EQ_GLOBAL(GuildWnd_guess*, 0x00800000)",
              "((GuildWnd_guess*)x)", "sizeof(GuildWnd_guess)", "GuildWnd_guess reads"):
        assert s in t, s
    fx = json.loads(text(tc, "tests/unicorn/EverQuest/tu_010/Get.json"))
    assert fx["function"] == "GuildWnd_guess::Get_guess" and fx["rewrite"] == "?Get_guess@GuildWnd_guess@@QAEHXZ"
    assert fx["callees"]["0x00409000"]["name"] == "GuildWnd_guess::Helper_guess"
    assert fx["callees"]["0x00409100"]["name"] == "Owner_guess::Elsewhere_guess"     # not this TU's VA: a label
    assert fx["callees"]["0x0040A000"]["name"] == "GuildWnd_guess::Slot00_guess"     # a member declared here
    assert set(fx["rewrite_aliases"]) == {"?Helper_guess@GuildWnd_guess@@QAEXXZ", "_strlen"}
    crt = json.loads(text(tc, "tests/unicorn/crt_defaults.json"))["rewrite_aliases"]
    assert crt["?Helper_guess@GuildWnd_guess@@QAEXXZ"] == "0x00409000"              # twin added
    assert "?Helper_guess@Owner_guess@@QAEXXZ" in crt and "?Unrelated_guess@GuildWnd_guess@@QAEXXZ" not in crt
    assert (text(tc, "src/EverQuest/tu_011.cpp"), text(tc, "tests/unicorn/EverQuest/tu_011/Use.json")) == other
    jl = json.loads(j.read_text().splitlines()[0])
    assert jl == {"client": "titanium", "kind": "class", "file": "src/EverQuest/tu_010.cpp", "class": "Owner_guess",
                  "old": "Owner_guess", "new": "GuildWnd_guess"}


def test_class_rename_refusals(tc, capsys):
    R = "src/EverQuest/tu_010.cpp"
    for old, new, why in (("Owner_guess", "Other_guess", "already a different class"),
                          ("Owner_guess", "Sum_guess", "already a name"),
                          ("Owner_guess", "HeaderThing", "its headers"),
                          ("HeaderThing", "Thing_guess", "not a struct/class/union defined"),
                          ("Nope_guess", "Thing_guess", "not a struct"),
                          ("Owner_guess", "Owner_guess", "new name = old name")):
        with pytest.raises(cr.Refused, match=why):
            cr.plan_class(tc, R, old, new)
    write(tc / "src/EverQuest/tu_015.cpp",
          "struct T_guess { int a; };\nstruct U_guess { struct T_guess { int b; } t; };\n")
    with pytest.raises(cr.Refused, match="defined 2 times"):
        cr.plan_class(tc, "src/EverQuest/tu_015.cpp", "T_guess", "V_guess")
    # a fixture that builds another source with its own Owner_guess
    write(tc / "tests/unicorn/EverQuest/tu_010/Both.json",
          jdump(dict(FIX_GET, sources=[R, "src/EverQuest/tu_011.cpp"])))
    with pytest.raises(cr.Refused, match="its own Owner_guess"):
        cr.plan_class(tc, R, "Owner_guess", "GuildWnd_guess")
    (tc / "tests/unicorn/EverQuest/tu_010/Both.json").unlink()
    before = tree(tc)
    assert cr.main(["class", R, "Owner_guess", "Other_guess", "--repo", str(tc)]) == 2
    assert "REFUSED" in capsys.readouterr().out and tree(tc) == before


# --- family ---------------------------------------------------------------------------------------------------------

def test_family_renames_one_view_per_tu(tc, capsys):
    rc = cr.main(["family", "0x00405000", "LineReader_guess", "--repo", str(tc), "-q"])
    out = capsys.readouterr().out
    assert rc == 2                                              # tu_014 refused (LineReader_guess is taken there)
    assert "struct LineReader_guess {" in text(tc, "src/EverQuest/tu_011.cpp")
    assert "LineReader_guess::LineReader_guess" in text(tc, "src/EverQuest/tu_011.cpp")
    assert "??0LineReader_guess@@QAE@PBD@Z" in text(tc, "src/EverQuest/tu_012.cpp")
    assert "int Lines_guess(LineReader_guess* f)" in text(tc, "src/EverQuest/tu_012.cpp")
    assert "A_guess" in text(tc, "src/EverQuest/tu_013.cpp") and "2 views of the family" in out
    assert "struct In_guess" in text(tc, "src/EverQuest/tu_014.cpp")
    assert "REFUSED class src/EverQuest/tu_014.cpp In_guess -> LineReader_guess" in out
    assert "Owner_guess" in text(tc, "src/EverQuest/tu_011.cpp")          # methods/other classes untouched


# --- fields -----------------------------------------------------------------------------------------------------------

def test_field_rename_types_its_accesses(tc):
    plan = cr.plan_field(tc, "src/EverQuest/tu_010.cpp", "Owner_guess", "field_8_guess", "width_8")
    assert plan.offset == 8 and plan.vas == {0x00401000, 0x00401040}
    t = plan.texts["src/EverQuest/tu_010.cpp"]
    for s in ("int width_8;  // 0x8", "{ return width_8; }", "return width_8 + count_c;", "o->width_8",
              "x->field_8_guess", "g_owner_guess->width_8", "p->width_8", "((Owner_guess*)x)->width_8",
              "struct Other_guess {\n    int field_8_guess;"):
        assert s in t, s
    assert "Owner_guess reads its own field_8_guess" in t      # comments untouched


def test_field_rename_refusals(tc):
    R = "src/EverQuest/tu_010.cpp"
    with pytest.raises(cr.Refused, match="already a member"):
        cr.plan_field(tc, R, "Owner_guess", "field_8_guess", "count_c")
    with pytest.raises(cr.Refused, match="already a member"):
        cr.plan_field(tc, R, "Owner_guess", "field_8_guess", "a")            # the base's member
    with pytest.raises(cr.Refused, match="not a data member"):
        cr.plan_field(tc, R, "Owner_guess", "a", "b_guess")
    with pytest.raises(cr.Refused, match="file-scope name"):
        cr.plan_field(tc, R, "Owner_guess", "field_8_guess", "Sum_guess")
    write(tc / R, TU10 + "\nOwner_guess* GetOwner_guess();\n// FUNCTION: TITANIUM 0x00401080\n"
          "int Odd_guess() {\n    return GetOwner_guess()->field_8_guess;\n}\n")
    with pytest.raises(cr.Refused, match="can't be typed"):
        cr.plan_field(tc, R, "Owner_guess", "field_8_guess", "width_8")
    write(tc / R, TU10 + "\n#define OWNER_FIELD(o) ((o)->field_8_guess)\n")
    with pytest.raises(cr.Refused, match="preprocessor"):
        cr.plan_field(tc, R, "Owner_guess", "field_8_guess", "width_8")


def test_field_family_renames_the_same_offset_in_sibling_views(tc, capsys):
    items, notes = cr.expand_field_family(tc, "src/EverQuest/tu_011.cpp", "Reader_guess", "count_4", "lineCount_4")
    assert [(i["file"], i["class"], i["old"]) for i in items] == [
        ("src/EverQuest/tu_011.cpp", "Reader_guess", "count_4"), ("src/EverQuest/tu_012.cpp", "FileIn_guess", "n")]
    assert any("tu_013" in n and "pad" in n for n in notes)
    assert cr.main(["field", "src/EverQuest/tu_011.cpp", "Reader_guess", "count_4", "lineCount_4", "--repo", str(tc),
                    "-q"]) == 0
    assert "r->lineCount_4" in text(tc, "src/EverQuest/tu_011.cpp")
    assert "return f->lineCount_4;" in text(tc, "src/EverQuest/tu_012.cpp")
    assert cr.main(["field", "src/EverQuest/tu_011.cpp", "Reader_guess", "handle_0", "fd_0", "--repo", str(tc),
                    "--no-family", "-q"]) == 0
    assert "int h;" in text(tc, "src/EverQuest/tu_012.cpp")


# --- the gate -------------------------------------------------------------------------------------------------------

def _fake_compare(bad_word=None):
    from eqd_unicorn import annotations as ann

    def fake(repo, tus, cache, tag, client="titanium", log=print):
        out = {}
        for t in tus:
            raw = (Path(repo) / t).read_text(encoding="utf-8")
            for a in ann.scan([Path(repo) / t], "TITANIUM"):
                bad = bad_word is not None and bad_word in raw
                out[a.va] = {"status": "diff" if bad else "identical", "ndiff": 1 if bad else 0, "name": a.name,
                             "source": t}
        return out
    return fake


def test_gated_map_keeps_good_items_and_restores_bad_ones(tc, tmp_path, monkeypatch, capsys):
    ran = []
    monkeypatch.setattr(MG, "compare_tus", _fake_compare(bad_word="BrokenWnd_guess"))
    monkeypatch.setattr(MG, "run_fixtures", lambda repo, rels, cache, tag: (ran.append((tag, list(rels))),
                                                                            ([], [], ""))[1])
    before12 = text(tc, "src/EverQuest/tu_012.cpp")
    m = tmp_path / "m.json"
    m.write_text(json.dumps([
        {"kind": "class", "file": "src/EverQuest/tu_010.cpp", "old": "Owner_guess", "new": "GuildWnd_guess"},
        {"kind": "field", "file": "src/EverQuest/tu_010.cpp", "class": "GuildWnd_guess", "old": "count_c",
         "new": "memberCount_c"},
        {"kind": "class", "file": "src/EverQuest/tu_012.cpp", "old": "FileIn_guess", "new": "BrokenWnd_guess"}]))
    j = tmp_path / "j.jsonl"
    rc = cr.main(["map", str(m), "--repo", str(tc), "--gate", "--journal", str(j), "-q",
                  "--gate-cache", str(tmp_path / "cache"), "--gate-json", str(tmp_path / "g.json")])
    out = capsys.readouterr().out
    assert rc == 1
    t = text(tc, "src/EverQuest/tu_010.cpp")
    assert "struct GuildWnd_guess" in t and "memberCount_c" in t
    assert text(tc, "src/EverQuest/tu_012.cpp") == before12                     # rejected and restored
    assert "GATE-REJECTED class src/EverQuest/tu_012.cpp FileIn_guess -> BrokenWnd_guess" in out
    kinds = [json.loads(x)["kind"] for x in j.read_text().splitlines()]
    assert kinds == ["class", "field"]
    g = json.loads((tmp_path / "g.json").read_text())                       # bisected: the map, the first two
    assert [len(x["items"]) for x in g] == [3, 2, 1] and [x["ok"] for x in g] == [False, True, False]  # kept whole
    assert any("tests/unicorn/EverQuest/tu_010/Get.json" in rels for _t, rels in ran)


def test_gated_single_item_restores_everything(tc, tmp_path, monkeypatch, capsys):
    before = tree(tc)
    monkeypatch.setattr(MG, "compare_tus", _fake_compare(bad_word="BrokenWnd_guess"))
    monkeypatch.setattr(MG, "run_fixtures", lambda *a, **k: ([], [], ""))
    rc = cr.main(["class", "src/EverQuest/tu_010.cpp", "Owner_guess", "BrokenWnd_guess", "--repo", str(tc), "--gate",
                  "-q", "--gate-cache", str(tmp_path / "cache")])
    assert rc == 1 and tree(tc) == before                    # source, fixture and crt_defaults twin all restored
    assert "REGRESSION 0x00401000" in capsys.readouterr().out
