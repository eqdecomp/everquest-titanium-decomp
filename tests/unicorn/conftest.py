"""Unicorn differential tests for Titanium's eqgame.exe (see tools/unicorn/README.md, tools/docs/TITANIUM_FUNCTIONAL.md).

Run from the repo root:  ..\\.venv\\Scripts\\python.exe -m pytest tests/unicorn
Needs the workspace (paths.local.ini, original\\titanium\\eqgame.exe) and the vc71 toolchain; skips otherwise.
Fixtures live in tests/unicorn/<subsystem>/ (src/EverQuest/tu_018_MailtoLink.cpp -> tests/unicorn/EverQuest/tu_018_MailtoLink/).
Test DLLs are built into <workspace>\\build\\titanium\\unicorn\\ (never committed).

crt_defaults.json is shared with compare --match: its `rewrite_aliases` (the test DLL's CRT / std helpers /
compiler helpers -> the client's VAs), `rewrite_data_aliases` (DLL data symbol -> client VA) and `link` apply here too.
Test DLLs link with trap_unresolved: the TUs are byte-match units that compile but were never meant to link (a
class they only declare still gets its vftable); a symbol no source defines becomes an int3 trap, and a call to it
fails the fixture as an unscripted callee.
"""
import faulthandler
import hashlib
import json
import os
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent
CRT_DEFAULTS = HERE / "crt_defaults.json"
PRIMARY = "titanium"
TOOLS = Path(os.environ.get("EQD_TOOLS", REPO / "tools"))
sys.path.insert(0, str(TOOLS / "unicorn"))

from eqd_unicorn import Harness, Workspace, load_fixture  # noqa: E402
from eqd_unicorn import clients as _clients  # noqa: E402

SHA256 = {"eqgame.exe": "ffa64c072c0c5e834a982720fd395ddc8974df26d1597020e1dbeb651b7ed957"}


def clients():
    return [c.id for c in _clients.of_repo("eq-titanium")] or [PRIMARY]


def client_of(path) -> str:
    return PRIMARY


@pytest.hookimpl(trylast=True)
def pytest_configure(config):
    faulthandler.disable()


def fragments():
    """{fragment: head} of fragments.json: export starts that are really a split-off tail of the function before."""
    try:
        from eqd_unicorn.extent import load_fragments
    except ImportError:         # older tools: read the file directly
        p = HERE / "fragments.json"
        rows = json.loads(p.read_text(encoding="utf-8"))["fragments"] if p.is_file() else []
        return {int(r["fragment"], 16): int(r["head"], 16) for r in rows}
    return load_fragments(REPO)


def function_starts(ws=None, client=PRIMARY):
    """Every function of the Ghidra export (<build>/export/titanium/functions.json): tail-call boundaries for the
    original's extent. A fragment of fragments.json is no boundary: its head's extent runs on into it."""
    starts = set()
    if ws is not None:
        exp = ws.build / "export" / client / "functions.json"
        if exp.is_file():
            starts.update(int(f["address"], 16) for f in json.loads(exp.read_text(encoding="utf-8"))["functions"])
    return starts - set(fragments())


def fixture_paths():
    """tests/unicorn/<subsystem>/*.json (not negative/, not crt_defaults.json/spans.json directly in here)."""
    return sorted(p for p in HERE.rglob("*.json") if "negative" not in p.parts and p.parent != HERE)


def crt_defaults(client=PRIMARY):
    """The fixture defaults (the harness applies `rewrite_data_aliases` too: patched absolute references)."""
    d = json.loads(CRT_DEFAULTS.read_text(encoding="utf-8")) if CRT_DEFAULTS.is_file() else {}
    return d


_HARNESS = {}


def _check_binary(exe: Path):
    want = SHA256.get(exe.name.lower())
    if want is None or os.environ.get("EQD_ANY_BINARY") == "1":
        return
    got = hashlib.sha256(exe.read_bytes()).hexdigest()
    if got != want:
        pytest.skip(f"{exe}: SHA-256 {got} is not the supported Titanium build ({want}); set EQD_ANY_BINARY=1")


def make_harness(client=PRIMARY):
    if client in _HARNESS:
        return _HARNESS[client]
    try:
        ws = Workspace(REPO)
    except FileNotFoundError as e:
        pytest.skip(str(e))
    exe = ws.binary(client)
    if not exe.is_file():
        pytest.skip(f"{exe} not found")
    _check_binary(exe)
    tc = ws.toolchain(client)
    if not (tc / "Bin" / "CL.EXE").is_file():
        pytest.skip(f"toolchain {_clients.get(client).toolchain} not found at {tc}")
    _HARNESS[client] = Harness(exe, ws.unicorn_build_dir(client), include_dirs=[REPO / "include"],
                               client=client.upper(), function_starts=function_starts(ws, client), vc6=tc,
                               fixture_defaults=crt_defaults(client), trap_unresolved=True)
    return _HARNESS[client]


def link_sources(client=PRIMARY):
    return [REPO / p for p in crt_defaults(client).get("link", [])]


def run_fixture_with(harness, path, sources=None, name=None, rewrite_symbol=None, defines=(), client=None,
                     **overrides):
    client = client or client_of(path)
    if harness is None:
        harness = make_harness(client)
    fx = load_fixture(path)
    fx.update(overrides)
    srcs = [Path(s) if Path(s).is_absolute() else REPO / s for s in (sources or fx["sources"])]
    srcs += [s for s in link_sources(client) if s not in srcs]
    t = harness.difftest(fx, srcs, name=name, rewrite_symbol=rewrite_symbol, base_dir=REPO, defines=defines)
    return t.run()


@pytest.fixture(scope="session")
def harness():
    return make_harness()


@pytest.fixture(scope="session")
def run_fixture(harness):
    def run(path, *a, **kw):
        return run_fixture_with(harness, path, *a, **kw)
    return run


# Every fixture JSON is collected directly as an item (test_fixture[<path>]); there is no test_fixtures.py.

def fixture_id(path) -> str:
    return str(Path(path).resolve().relative_to(HERE)).replace("\\", "/")


def _is_fixture(path: Path) -> bool:
    try:
        rel = path.resolve().relative_to(HERE)
    except ValueError:
        return False
    return path.suffix.lower() == ".json" and len(rel.parts) > 1 and "negative" not in rel.parts


class FixtureItem(pytest.Item):
    def runtest(self):
        report = run_fixture_with(None, self.path)
        assert report.ok, report.summary()

    def reportinfo(self):
        return self.path, None, self.name


class FixtureFile(pytest.File):
    def collect(self):
        yield FixtureItem.from_parent(self, name=f"test_fixture[{fixture_id(self.path)}]")


def pytest_collect_file(file_path, parent):
    if _is_fixture(file_path):
        return FixtureFile.from_parent(parent, path=file_path)
    return None
