"""`// GENERATED:` annotations: a VA bound to a function the compiler writes itself (scalar/vector deleting destructor,
implicit destructor/constructor), by decorated name or by class and kind. annotations.py reads them; compare --match
pairs them with the object's symbol; mutations.py refuses them (no body). Hand-made COFF, no VC6, no game files."""
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "unicorn"))
sys.path.insert(0, str(ROOT / "unicorn" / "tools"))
sys.path.insert(0, str(ROOT / "compare"))
sys.path.insert(0, str(ROOT / "queue"))

from eqd_unicorn import annotations as ann  # noqa: E402
from eqd_unicorn import difftest as D  # noqa: E402
from eqd_unicorn.pe import Image  # noqa: E402

import compare as C  # noqa: E402
import mutations as M  # noqa: E402
from test_target_obj import CALL_OFF, CALLEE, FN, GLOBAL, GLOBAL_OFF, TEXT, code, context, make_obj  # noqa: E402

SDD = "??_GFoo_guess@@UAEPAXI@Z"


def scan(tmp_path, text, client="TITANIUM"):
    src = tmp_path / "a.cpp"
    src.write_text(text)
    return ann.scan([src], client)


# -- annotations.py

def test_symbol_name_names_the_special_members():
    assert ann.symbol_name(SDD) == "Foo_guess::`scalar deleting destructor'"
    assert ann.symbol_name("??_EFoo_guess@@UAEPAXI@Z") == "Foo_guess::`vector deleting destructor'"
    assert ann.symbol_name("??_DFoo_guess@@QAEXXZ") == "Foo_guess::`vbase destructor'"
    assert ann.symbol_name("??_GInner@Outer@@UAEPAXI@Z") == "Outer::Inner::`scalar deleting destructor'"
    # a vtordisp thunk ($ adjustor) and a template class keep their decorated names; the rest is undecorate's
    assert ann.symbol_name("??_EFoo_guess@@$4PPPPPPPM@A@AEPAXI@Z") == "??_EFoo_guess@@$4PPPPPPPM@A@AEPAXI@Z"
    assert ann.symbol_name("??_G?$V@H@@UAEPAXI@Z") == "??_G?$V@H@@UAEPAXI@Z"
    assert ann.symbol_name("??1Foo_guess@@UAE@XZ") == "Foo_guess::~Foo_guess"
    assert ann.symbol_name("?Bar@Foo_guess@@QAEXXZ") == "Foo_guess::Bar"


def test_scan_reads_both_forms_and_keeps_the_next_definition(tmp_path):
    got = scan(tmp_path,
               "// FUNCTION: TITANIUM 0x004BF94B\n// note\n// GENERATED: Foo_guess::`scalar deleting destructor'\n\n"
               "// FUNCTION: TITANIUM 0x004BF97C\n// GENERATED: ??_GBar_guess@@UAEPAXI@Z\n\n"
               "// FUNCTION: TITANIUM 0x004BF9AD\n// GENERATED: Bar_guess :: ~Bar_guess\n\n"
               "// FUNCTION: TITANIUM 0x004BF9B2\nint Bar_guess::Next(int a)\n{\n}\n")
    assert [(a.va, a.name, a.generated, a.symbol) for a in got] == [
        (0x4BF94B, "Foo_guess::`scalar deleting destructor'", True, None),
        (0x4BF97C, "Bar_guess::`scalar deleting destructor'", True, "??_GBar_guess@@UAEPAXI@Z"),
        (0x4BF9AD, "Bar_guess::~Bar_guess", True, None),
        (0x4BF9B2, "Bar_guess::Next", False, None)]


def test_scan_generated_line_must_sit_right_below(tmp_path):
    """A GENERATED line after code, or under the next annotation, does not bind the one above."""
    got = scan(tmp_path, "// FUNCTION: TITANIUM 0x10\nvoid f(void)\n{\n}\n// GENERATED: Foo::~Foo\n")
    assert [(a.name, a.generated) for a in got] == [("f", False)]


def test_scan_generated_class_names_follow_defines(tmp_path):
    got = scan(tmp_path, "#define Foo Foo_local_guess\n// FUNCTION: TITANIUM 0x10\n// GENERATED: Foo::~Foo\n")
    assert got[0].name == "Foo_local_guess::~Foo_local_guess"


@pytest.mark.parametrize("spec", ["Foo::Bar", "Foo::`vftable'", "Foo", "?x", "Foo::~Bar"])
def test_scan_rejects_what_the_compiler_does_not_generate(tmp_path, spec):
    with pytest.raises(ValueError, match="GENERATED"):
        scan(tmp_path, f"// FUNCTION: TITANIUM 0x10\n// GENERATED: {spec}\n")


def test_matches_decorated_exactly_else_by_name(tmp_path):
    by_kind, by_symbol = scan(tmp_path, "// FUNCTION: TITANIUM 0x10\n// GENERATED: Foo::Foo\n"
                                        "// FUNCTION: TITANIUM 0x20\n// GENERATED: ??0Foo@@QAE@ABV0@@Z\n")
    assert ann.matches(by_kind, "??0Foo@@QAE@XZ") and ann.matches(by_kind, "??0Foo@@QAE@ABV0@@Z")
    assert ann.matches(by_symbol, "??0Foo@@QAE@ABV0@@Z") and not ann.matches(by_symbol, "??0Foo@@QAE@XZ")


# -- compare --match

def rewrite(tmp_path, symbols, body):
    syms = [(name, off, 1, 0x20, 2) for name, off in symbols]
    syms += [(f"_eqd_fn_0x{CALLEE:08X}", 0, 0, 0x20, 2), (f"_eqd_va_0x{GLOBAL:08X}", 0, 0, 0, 2)]
    n = len(symbols)
    return make_obj(tmp_path / "rw.obj", [(".text", body, TEXT, [(CALL_OFF, n, 0x14), (GLOBAL_OFF, n + 1, 0x06)])],
                    syms)


BODY = code(b"\0\0\0\0", b"\0\0\0\0")


def test_compare_pairs_a_generated_annotation_with_its_symbol(tmp_path):
    (a,) = scan(tmp_path, f"// FUNCTION: TITANIUM {FN:#x}\n// GENERATED: Foo_guess::`scalar deleting destructor'\n")
    (res,) = context().compare_obj(rewrite(tmp_path, [(SDD, 0)], BODY), Path("a.cpp"), [a], {a.name: {a.va}})
    assert C.match_status(res) == "identical", (res.first_diff, res.diff)
    assert res.name == "Foo_guess::`scalar deleting destructor'"


def test_compare_decorated_name_picks_one_of_two_implicit_constructors(tmp_path):
    body = BODY + b"\xc3"                                   # the default ctor: a bare ret after the copy ctor
    syms = [("??0Foo@@QAE@ABV0@@Z", 0), ("??0Foo@@QAE@XZ", len(BODY))]
    (by_kind,) = scan(tmp_path, f"// FUNCTION: TITANIUM {FN:#x}\n// GENERATED: Foo::Foo\n")
    (res,) = context().compare_obj(rewrite(tmp_path, syms, body), Path("a.cpp"), [by_kind], {})
    assert res.verdict == "error" and "2 symbols" in res.first_diff
    (by_symbol,) = scan(tmp_path, f"// FUNCTION: TITANIUM {FN:#x}\n// GENERATED: ??0Foo@@QAE@ABV0@@Z\n")
    (res,) = context().compare_obj(rewrite(tmp_path, syms, body), Path("a.cpp"), [by_symbol], {})
    assert C.match_status(res) == "identical", (res.first_diff, res.diff)


def test_a_call_to_a_generated_symbol_is_keyed_by_its_annotation(tmp_path):
    """`user` calls ??_GFoo_guess (an EXTERNAL symbol here): the generated annotation's VA keys it, as a hand-written
    definition's name would."""
    from types import SimpleNamespace
    user = SimpleNamespace(va=FN, name="user", line=1)
    syms = [("_user", 0, 1, 0x20, 2), (SDD, 0, 0, 0x20, 2), (f"_eqd_va_0x{GLOBAL:08X}", 0, 0, 0, 2)]
    obj = make_obj(tmp_path / "u.obj", [(".text", BODY, TEXT, [(CALL_OFF, 1, 0x14), (GLOBAL_OFF, 2, 0x06)])], syms)
    name = "Foo_guess::`scalar deleting destructor'"
    (res,) = context().compare_obj(obj, Path("u.cpp"), [user], {"user": {FN}, name: {CALLEE}})
    assert C.match_status(res) == "identical", (res.first_diff, res.diff)
    (res,) = context().compare_obj(obj, Path("u.cpp"), [user], {"user": {FN}, name: {CALLEE + 0x10}})
    assert res.verdict == "differs"


# -- mutations.py

def test_mutations_refuse_a_generated_annotation():
    text = ("// FUNCTION: TITANIUM 0x10\n// a note\n// GENERATED: Foo::~Foo\n\n"
            "// FUNCTION: TITANIUM 0x20\nint g(int a)\n{\n    return a + 1;\n}\n")
    with pytest.raises(ValueError, match="compiler-generated"):
        M.function_body(text, 0x10, "TITANIUM")
    open_, end, head = M.function_body(text, 0x20, "TITANIUM")
    assert text[open_] == "{" and "g" in head


# -- the Unicorn harness

def test_harness_finds_a_generated_function_by_name_or_its_alias():
    """The test DLL's map may list the deleting destructor under ??_E only (the compiler's alias of ??_G)."""
    img = Image("t.dll", 0x30000000, bytearray(0x100), 0x30000000)
    img.add_symbol(0x30000010, "??_EFoo_guess@@UAEPAXI@Z")
    img.add_symbol(0x30000020, "??1Foo_guess@@UAE@XZ")
    assert D._find_symbol(img, "Foo_guess::`scalar deleting destructor'") == 0x30000010
    assert D._find_symbol(img, "??_GFoo_guess@@UAEPAXI@Z") == 0x30000010
    assert D._find_symbol(img, "Foo_guess::`vector deleting destructor'") == 0x30000010
    assert D._find_symbol(img, "Foo_guess::~Foo_guess") == 0x30000020
    with pytest.raises(D.SymbolMissing):
        D._find_symbol(img, "Bar_guess::`scalar deleting destructor'")
