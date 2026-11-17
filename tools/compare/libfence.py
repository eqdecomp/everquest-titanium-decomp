r"""Find library code misfiled in the game span: compile the real STL, read the real libraries, compare bytes.

    ..\.venv\Scripts\python.exe tools\compare\libfence.py titanium

Candidates: every COMDAT of a probe source that instantiates the toolchain's own STL with the game's flags, and every
code section of the toolchain's static libraries (LIB_FILES). A candidate matches a function of the export when the
size agrees and all bytes outside its relocation fields agree. Functions under MIN_SIZE bytes are left out (a
two-line accessor is not evidence of anything). Output: build/<client>/libfence.json, one row per matched function.
A head of the repo's tests/unicorn/fragments.json is matched with its whole span (head, fragments and the catch
funclets between them, as one COMDAT holds them); its fragments are no candidates of their own.
"""
from __future__ import annotations

import argparse
import json
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path[:0] = [str(HERE.parent / "unicorn"), str(HERE), str(HERE.parent / "queue")]

import coff  # noqa: E402
import queuelib as q  # noqa: E402
from eqd_unicorn.vc6 import toolchain_env  # noqa: E402
from eqd_unicorn import Workspace  # noqa: E402
from tumap import pe_sections  # noqa: E402
from eqd_unicorn.extent import load_fragments  # noqa: E402

MIN_SIZE = 12
LIB_FILES = ("libcpmt.lib", "libcmt.lib")
PROBE_FLAGS = {"titanium": ["/O1", "/GS", "/GX", "/Gy", "/MT", "/GR-"]}
PROBE = r"""// Instances of the toolchain's own STL with common element types: all members, each its own COMDAT.
#pragma warning(disable: 4786 4530)
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <new>
template class std::basic_string<char>;
template class std::basic_string<wchar_t>;
template class std::vector<int>;
template class std::vector<char>;
template class std::vector<char *>;
template class std::vector<float>;
template class std::vector<std::string>;
template class std::list<int>;
template class std::list<void *>;
template class std::list<std::string>;
template class std::map<int, int>;
template class std::map<int, void *>;
template class std::map<std::string, int>;
template class std::map<std::string, std::string>;
template class std::set<int>;
template class std::set<std::string>;
template class std::deque<int>;
template class std::deque<void *>;
template class std::basic_ios<char>;
template class std::basic_streambuf<char>;
template class std::basic_istream<char>;
template class std::basic_ostream<char>;
template class std::basic_iostream<char>;
template class std::basic_filebuf<char>;
template class std::basic_ifstream<char>;
template class std::basic_ofstream<char>;
template class std::basic_fstream<char>;
template class std::basic_stringbuf<char>;
template class std::basic_istringstream<char>;
template class std::basic_ostringstream<char>;
template class std::basic_stringstream<char>;
// Free function templates: `template class` does not emit them.
template std::basic_istream<char, std::char_traits<char> > &std::getline<char, std::char_traits<char>,
    std::allocator<char> >(std::basic_istream<char, std::char_traits<char> > &,
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > &, const char);
template std::basic_istream<char, std::char_traits<char> > &std::operator>> <char, std::char_traits<char>,
    std::allocator<char> >(std::basic_istream<char, std::char_traits<char> > &,
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > &);
void Touch(std::vector<int> &v, std::vector<float> &f, std::vector<char *> &c) {
    std::sort(v.begin(), v.end()); std::sort(f.begin(), f.end()); std::sort(c.begin(), c.end());
    std::cout << 1 << "x" << std::endl;
    throw std::runtime_error("x");
}
"""


def archive_members(path: Path):
    """(name, bytes) of each object in a COFF archive."""
    d = path.read_bytes()
    at = 8
    n = 0
    while at + 60 <= len(d):
        size = int(d[at + 48:at + 58].split()[0])
        name = d[at:at + 16].rstrip()
        body = d[at + 60:at + 60 + size]
        at += 60 + size + (size & 1)
        n += 1
        if name in (b"/", b"//") or body[:2] != b"\x4c\x01":
            continue
        yield f"{path.name}#{n}", body


def code_sections(obj, origin: str):
    """(name, bytes, masked offsets) of an object's code sections."""
    for k, s in enumerate(obj.sections, 1):
        if not s.chars & coff.IMAGE_SCN_CNT_CODE or len(s.data) < MIN_SIZE:
            continue
        mask = set()
        for off, _sym, typ in s.relocs:
            if typ in (coff.REL_DIR32, coff.REL_REL32, coff.REL_DIR32NB):
                mask.update(range(off, off + 4))
        name = next((y.name for y in obj.symbols if y and y.section == k and y.storage == 2 and y.value == 0), "")
        yield name or origin, s.data, mask


def matches(data: bytes, mask, target: bytes) -> bool:
    return len(data) == len(target) and all(i in mask or data[i] == target[i] for i in range(len(data)))


def build_probe(client: str, out: Path) -> Path | None:
    flags = PROBE_FLAGS.get(client)
    if flags is None:
        raise SystemExit(f"libfence: no probe flags for client {client}")
    ws = Workspace(Path(q.repo_dir(client)))
    vc = ws.toolchain(client)
    src, obj = out / "stl_probe.cpp", out / "stl_probe.obj"
    src.write_text(PROBE, encoding="ascii")
    cmd = [str(vc / "Bin" / "CL.EXE"), "/nologo", "/c", *flags, f"/Fo{obj}", str(src)]
    p = subprocess.run(cmd, env=toolchain_env(vc), capture_output=True, text=True, errors="replace", cwd=out)
    (out / "stl_probe.log").write_text(p.stdout + p.stderr, encoding="utf-8")
    return obj if p.returncode == 0 else None


def main(argv=None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("client")
    ap.add_argument("--no-probe", action="store_true", help="skip compiling the STL probe")
    ap.add_argument("--out", help="result JSON (default build/<client>/libfence.json); the probe goes beside it")
    a = ap.parse_args(argv)
    root = q.find_root()
    dest = Path(a.out).resolve() if a.out else root / "build" / a.client / "libfence.json"
    out = dest.parent / "libfence" if a.out else root / "build" / a.client / "libfence"
    out.mkdir(parents=True, exist_ok=True)
    fns = json.loads((q.export_dir(a.client) / "functions.json").read_text(encoding="utf-8"))["functions"]
    exe = (root / "original" / q.client(a.client).binary).read_bytes()
    secs = pe_sections(exe)
    tva, tsize, tptr = secs[".text"]
    frags = load_fragments(q.repo_dir(a.client))
    merged = {k: v[0] for k, v in q.merged_spans(fns, frags).items()}
    by_size: dict = {}
    for f in fns:
        va = int(f["address"], 16)
        size = merged.get(f["address"], f["size"])
        if f["class"] == "eh_funclet" or size < MIN_SIZE or va in frags:
            continue
        if tva <= va and va + size <= tva + tsize:
            by_size.setdefault(size, []).append((f["address"], exe[tptr + va - tva:tptr + va - tva + size]))
    found: dict = {}
    n_cand = 0

    def scan(obj, origin):
        nonlocal n_cand
        for name, data, mask in code_sections(obj, origin):
            n_cand += 1
            trimmed = data.rstrip(b"\xcc\x90") if not mask or max(mask) < len(data.rstrip(b"\xcc\x90")) else data
            for d in {data, trimmed}:
                for addr, tb in by_size.get(len(d), ()):
                    if addr not in found and matches(d, mask, tb):
                        found[addr] = {"address": addr, "symbol": name, "origin": origin, "size": len(d)}

    if not a.no_probe:
        obj = build_probe(a.client, out)
        print("probe:", obj or f"failed, see {out / 'stl_probe.log'}")
        if obj:
            scan(coff.parse(obj), "stl_probe")
    ws = Workspace(Path(q.repo_dir(a.client)))
    for lib in LIB_FILES:
        p = ws.toolchain(a.client) / "Lib" / lib
        if not p.is_file():
            print("missing", p)
            continue
        for name, body in archive_members(p):
            try:
                scan(coff.parse_bytes(body), name)
            except (struct.error, ValueError, IndexError):
                continue
    rows = sorted(found.values(), key=lambda r: r["address"])
    dest.write_text(json.dumps({"schema_version": 1, "client": a.client, "candidates": n_cand, "matched": rows},
                               indent=0), encoding="utf-8")
    print(f"{n_cand} candidates, {len(rows)} functions matched -> {dest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
