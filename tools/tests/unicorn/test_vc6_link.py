"""Self-test for vc6.build_dll: a /NOENTRY test DLL must link whatever LIBC and Win32 pieces a rewrite uses.

Needs VC6 (skips without it); no game files. Regression for: float code (__fltused), stdio (sprintf ->
_flsbuf -> __amsg_exit, which LIBC defines in the EXE start-up crt0.obj -> unresolved _main) and Win32 /
LIBC imports (Sleep, MultiByteToWideChar behind _strcmpi) with no CRT start-up object naming kernel32.lib.
"""
import os
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "unicorn"))

from eqd_unicorn.pe import load_pe, read_map  # noqa: E402
from eqd_unicorn.vc6 import DEFAULT_VC6, build_dll  # noqa: E402

SRC = r"""
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern "C" float scale(float a, float b) { return a * 0.75f + b; }
extern "C" int fmt(char *out, unsigned short id) { return sprintf(out, "%s%u", "x", id); }
extern "C" int same(const char *a, const char *b) { return _strcmpi(a, b) == 0 && isspace(' '); }
extern "C" void nap(void) { Sleep(1); }
"""


def test_crt_float_stdio_and_win32_link(tmp_path):
    vc6 = Path(os.environ.get("EQD_VC6") or DEFAULT_VC6)
    if not (vc6 / "Bin" / "CL.EXE").is_file():
        pytest.skip(f"VC6 not found at {vc6}")
    src = tmp_path / "linkcheck.cpp"
    src.write_text(SRC)
    dll, mapf = build_dll("linkcheck", [src], tmp_path / "out", vc6=vc6)
    img = load_pe(dll, base=0x30000000)
    read_map(mapf, img)
    names = set(img.by_name)
    assert {"_scale", "_fmt", "_same", "_nap"} <= names
    assert "_main" not in names
    assert "kernel32.dll!Sleep" in set(img.imports.values())


# --- per-source CFLAGS lines ---------------------------------------------------------------------------------

from eqd_unicorn.vc6 import DEFAULT_CFLAGS, BuildError, cflags_for, source_cflags  # noqa: E402


def test_cflags_lines_are_parsed_in_order(tmp_path):
    src = tmp_path / "a.c"
    src.write_text("/* rdp.\n * CFLAGS: /O2\n */\n// CFLAGS: /Oy- /GX-\n/* CFLAGS: /Zp4 */\nint x;\n"
                   "// not a CFLAGS: line because the marker must start the comment\n")
    assert source_cflags(src) == ["/O2", "/Oy-", "/GX-", "/Zp4"]
    flags = cflags_for(src)
    assert "/O1" not in flags and flags[-4:] == ["/O2", "/Oy-", "/GX-", "/Zp4"]
    assert flags[:-4] == [f for f in DEFAULT_CFLAGS if f != "/O1"]


def test_cflags_append_without_level(tmp_path):
    src = tmp_path / "b.cpp"
    src.write_text("// CFLAGS: /Ot\nint y;\n")
    assert cflags_for(src) == DEFAULT_CFLAGS + ["/Ot"]
    plain = tmp_path / "c.cpp"
    plain.write_text("int z;\n")
    assert cflags_for(plain) == DEFAULT_CFLAGS
    assert "/GX" in DEFAULT_CFLAGS


@pytest.mark.parametrize("bad", ["/MD", "/DFOO", "/Iinc", "/FAs", "-O2"])
def test_cflags_refuses_non_codegen_options(tmp_path, bad):
    src = tmp_path / "d.c"
    src.write_text(f"// CFLAGS: {bad}\n")
    with pytest.raises(BuildError, match="..."):
        source_cflags(src)


def test_cflags_allows_titanium_static_model_and_gs_options(tmp_path):
    src = tmp_path / "titanium.cpp"
    src.write_text("// CFLAGS: /O1 /GS /GX /Gy /MT /GR-\nint f() { return 1; }\n")
    assert source_cflags(src) == ["/O1", "/GS", "/GX", "/Gy", "/MT", "/GR-"]
    with pytest.raises(BuildError, match="..."):
        source_cflags(src, base=["/MD"])


def test_build_dll_compiles_each_source_with_its_flags(tmp_path):
    """Two sources in one DLL: the /Od one keeps an EBP frame, the default /O1 one doesn't."""
    vc6 = Path(os.environ.get("EQD_VC6") or DEFAULT_VC6)
    if not (vc6 / "Bin" / "CL.EXE").is_file():
        pytest.skip(f"VC6 not found at {vc6}")
    body = "extern \"C\" int {n}(int a, int b) {{ return a * b + 7; }}\n"
    (tmp_path / "fast.cpp").write_text(body.format(n="fast"))
    (tmp_path / "slow.cpp").write_text("// CFLAGS: /Od\n" + body.format(n="slow"))
    dll, mapf = build_dll("flagcheck", [tmp_path / "fast.cpp", tmp_path / "slow.cpp"], tmp_path / "out", vc6=vc6)
    img = load_pe(dll, base=0x30000000)
    read_map(mapf, img)
    assert img.read(img.by_name["_slow"], 3) == b"\x55\x8b\xec"         # push ebp; mov ebp, esp
    assert img.read(img.by_name["_fast"], 1) != b"\x55"


def test_build_dll_compiles_each_source_with_its_toolchain(tmp_path, monkeypatch):
    """A `// TOOLCHAIN:` source gets its own cl run with that toolchain's CL.EXE; the link stays the build's."""
    from eqd_unicorn import vc6 as v
    own, other = tmp_path / "own", tmp_path / "other"
    for d in (own, other):
        (d / "Bin").mkdir(parents=True)
        (d / "Bin" / "CL.EXE").write_bytes(b"")
    monkeypatch.setattr(v, "_TOOLCHAIN_DIRS", {})
    monkeypatch.setenv("EQD_TOOLCHAIN_OTHER", str(other))
    (tmp_path / "a.cpp").write_text("int a;\n")
    (tmp_path / "b.cpp").write_text("// TOOLCHAIN: other\nint b;\n")
    (tmp_path / "c.cpp").write_text("int c;\n")
    runs = []

    def fake_run(cmd, env, cwd):
        runs.append((Path(cmd[0]), [Path(x).name for x in cmd if x.endswith(".cpp")], env["PATH"]))
        if Path(cmd[0]).name == "LINK.EXE":
            raise v.BuildError("stop")
        return ""
    monkeypatch.setattr(v, "_run", fake_run)
    # fake cl writes no .obj files, so skip the EQ_METHOD stub scan that reads them
    monkeypatch.setattr(v.thiscall_stubs, "write_stub_obj", lambda objs, out, extra=None: None)
    with pytest.raises(v.BuildError):
        build_dll("tc", [tmp_path / n for n in ("a.cpp", "b.cpp", "c.cpp")], tmp_path / "out", vc6=own,
                  cache_dir=False)
    cl = [(exe.parent.parent, srcs, path) for exe, srcs, path in runs if exe.name == "CL.EXE" and srcs]
    assert cl == [(own, ["a.cpp", "c.cpp"], cl[0][2]), (other, ["b.cpp"], cl[1][2])]
    assert cl[1][2].startswith(str(other / "Bin"))
    assert runs[-1][0] == own / "Bin" / "LINK.EXE"


def test_compiler_runs_hold_the_compile_lock(tmp_path, monkeypatch):
    """EQD_COMPILE_LOCK: every cl/link run of a test-DLL build holds the shared compiler lock (one compiler job
    at a time with other compare runs); the guard is re-entrant, so a caller already holding it doesn't deadlock."""
    from eqd_unicorn import vc6
    lock = tmp_path / "vc6.lock"
    monkeypatch.setenv("EQD_COMPILE_LOCK", str(lock))
    seen = []

    def fake_run(cmd, **kw):
        seen.append(lock.read_text())
        return type("P", (), {"returncode": 0, "stdout": "", "stderr": ""})()
    monkeypatch.setattr(vc6.subprocess, "run", fake_run)
    vc6._run(["cl"], {}, tmp_path)
    with vc6.compile_guard():
        vc6._run(["link"], {}, tmp_path)
        assert lock.is_file()
    assert seen == [str(os.getpid())] * 2
    assert not lock.exists()


def test_release_tolerates_a_lock_taken_away(tmp_path, monkeypatch):
    """A sandboxed waiter took a live holder for dead and deleted its lock, and the holder's release
    then failed the landing gate with FileNotFoundError. Gone or re-taken by another holder: leave it."""
    from eqd_unicorn import vc6
    lock = tmp_path / "vc6.lock"
    monkeypatch.setenv("EQD_COMPILE_LOCK", str(lock))
    with vc6.compile_guard():
        lock.unlink()
    assert not lock.exists()
    with vc6.compile_guard():
        lock.write_text("4242")
    assert lock.read_text() == "4242"


@pytest.mark.skipif(os.name != "nt", reason="Windows OpenProcess")
def test_pid_alive_counts_access_denied_as_alive():
    from eqd_unicorn import vc6
    assert vc6._pid_alive(os.getpid())
    assert vc6._pid_alive(4)                # System: OpenProcess is refused, but it runs
    assert not vc6._pid_alive(0x7FFFFFF0)   # no such process


TRAP_SRC = r"""
#include <string.h>
struct Declared_guess {                 // a class a byte-match TU only declares: its vftable is still emitted
    virtual void Slot00_guess();
    Declared_guess() : value(0) {}
    int value;
};
// EXTERNAL: TRILOGY 0x0052a000 strcpy
extern "C" Declared_guess* make(char* out, const char* in) { strcpy(out, in); strcat(out, in); return new Declared_guess; }
"""


def test_link_errors_recoverable_and_unresolved_symbols():
    from eqd_unicorn.vc6 import link_errors_recoverable, unresolved_symbols
    out = ('LIBCMT.lib(strcat.obj) : error LNK2005: _strcpy already defined in eqd_thiscall_stubs.obj\n'
           'a.obj : error LNK2001: unresolved external symbol "public: virtual void __thiscall X::f(void)" (?f@X@@UAEXXZ)\n'
           'a.obj : error LNK2019: unresolved external symbol _g referenced in function _h\n'
           'x.dll : fatal error LNK1120: 2 unresolved externals\n')
    assert unresolved_symbols(out) == ["?f@X@@UAEXXZ", "_g"]
    assert link_errors_recoverable(out, "eqd_thiscall_stubs.obj")
    assert not link_errors_recoverable(out, None)
    assert not link_errors_recoverable(out, "eqd_thiscall_stubs.obj", unresolved_ok=False)
    dup_only = out.splitlines()[0] + "\nx.dll : fatal error LNK1169: one or more multiply defined symbols found\n"
    assert link_errors_recoverable(dup_only,
                                   "eqd_thiscall_stubs.obj", unresolved_ok=False)
    assert not link_errors_recoverable("b.obj : error LNK2005: _f already defined in a.obj\n", "eqd_thiscall_stubs.obj")
    assert not link_errors_recoverable("LINK : fatal error LNK1104: cannot open file 'x.lib'\n", None)


@pytest.mark.parametrize("key", ["vc6", "vc71"])
def test_build_dll_traps_unresolved_slots_and_keeps_stubs_over_crt_members(tmp_path, key):
    """With trap_unresolved a declared-only virtual slot links as an int3 trap (without it the link fails), and a
    client-function stub (`strcpy` marked `// EXTERNAL:`) survives LIBCMT's strcat.obj, which defines strcpy
    too (VC7.1: LNK2005)."""
    from eqd_unicorn import Workspace, externs
    from eqd_unicorn.thiscall_stubs import TRAP
    try:
        tc = Path(Workspace().cfg["toolchain"][key])
    except Exception:  # noqa: BLE001
        pytest.skip(f"no [toolchain] {key}")
    if not (tc / "Bin" / "CL.EXE").is_file():
        pytest.skip(f"{key} not found at {tc}")
    src = tmp_path / "trap.cpp"
    src.write_text(TRAP_SRC)
    with pytest.raises(BuildError):
        build_dll("plain", [src], tmp_path / "out", vc6=tc, cache_dir=False)
    dll, mapf = build_dll("trap", [src], tmp_path / "out", vc6=tc, cache_dir=False, trap_unresolved=True)
    img = load_pe(dll, base=0x30000000)
    read_map(mapf, img)
    assert img.read(img.by_name["?Slot00_guess@Declared_guess@@UAEXXZ"], 8) == TRAP
    assert externs.stub_target(img.read, img.by_name["_strcpy"]) == 0x0052A000
