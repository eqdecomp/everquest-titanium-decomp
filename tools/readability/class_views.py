r"""Titanium class views: every struct/class definition of src/ and include/ with the VAs it carries, and the VA
families (one vtable / ctor / dtor VA seen under several class names, one per TU view).

    cd eq-titanium
    ..\.venv\Scripts\python.exe tools\readability\class_views.py family 0x00576BD0     (the views of one class)
    ..\.venv\Scripts\python.exe tools\readability\class_views.py view src/EverQuest/tu_166.cpp Owner_guess
    ..\.venv\Scripts\python.exe tools\readability\class_views.py aliases --out structs_alias.tsv

Titanium has file-local types: every TU declares its own view of a class, so one class can carry a different name in
each TU (the CSidlScreenWnd ctor/dtor under 104 names). A view carries a VA when the TU marks or defines one of its
members at it:
  vtable  `// EXTERNAL: TITANIUM 0x... ??_7Name@@6B@` (also `??_7Name@@6BBase@@@`, a secondary table)
  ctor    a `// FUNCTION:`/`// EXTERNAL:` marker on `Name::Name(` or on `Name(` inside the class body
  dtor    the same for `~Name`
  meth    any other member marked or defined at a VA
A family is the views that carry the VA as their vtable, ctor or dtor (`--methods`: as any member too; off by
default because a derived view often declares the base's dtor/ctor as one of its own members).

The layout of each view comes from tools/structs/cparse.py (MSVC rules; `exact` is False when a type was guessed).
Moved here from the phase-4 inventory script, which keeps its own copy for the reports.
Importable: load(repo) -> Views; Views.family(va), Views.views_in(rel), Views.by_name(rel, name).
"""
from __future__ import annotations

import argparse
import collections
import csv
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "structs"))
import cparse  # noqa: E402

SUBDIRS = ("src", "include")
MARK = re.compile(r"^\s*//\s*(FUNCTION|EXTERNAL|STUB|LIBRARY|VTABLE|GLOBAL):\s*(\w+)\s+0[xX]([0-9A-Fa-f]{1,8})\s*(.*)$")
QUAL = re.compile(r"([A-Za-z_]\w*)\s*::\s*(~?\s*[A-Za-z_]\w*)\s*\(")
VT = re.compile(r"\?\?_7(\w+?)@@6")
DECL = re.compile(r"(~?\s*[A-Za-z_]\w*)\s*\(")


@dataclass
class View:
    uid: int
    file: str
    name: str                   # qualified (Outer::Inner) as written
    line: int
    end_line: int
    kw: str
    virtual: bool
    size: int
    exact: bool
    bases: list
    vt: set = field(default_factory=set)
    ctor: set = field(default_factory=set)
    dtor: set = field(default_factory=set)
    meth: set = field(default_factory=set)
    decl: object = None         # cparse.StructDef

    @property
    def simple(self) -> str:
        return self.name.split("::")[-1]

    def vas(self, methods=False) -> set:
        return self.vt | self.ctor | self.dtor | (self.meth if methods else set())

    def row(self) -> dict:
        h = lambda s: ",".join(f"0x{v:08X}" for v in sorted(s))       # noqa: E731
        return {"file": self.file, "name": self.name, "line": self.line, "size": hex(self.size),
                "exact": self.exact, "virtual": self.virtual, "vtable": h(self.vt), "ctor": h(self.ctor),
                "dtor": h(self.dtor), "methods": len(self.meth)}


def qname(d) -> str:
    parts = []
    while d is not None:
        parts.append(d.name)
        d = d.parent
    return "::".join(reversed(parts))


class Views:
    def __init__(self, idx: cparse.Index, token="TITANIUM"):
        self.idx = idx
        self.token = token.upper()
        self.views: list[View] = []
        self._attribute()

    # -- building
    def _attribute(self):
        idx = self.idx
        defs_by_file = collections.defaultdict(list)
        for d in idx.all_defs():
            if d.tag or d.aliases:
                defs_by_file[d.file].append(d)
        info = {}
        for d in idx.all_defs():
            if not (d.tag or d.aliases):
                continue
            L = idx.layout(d)
            info[d.uid] = View(d.uid, d.file, qname(d), d.line, d.end_line, d.kw, bool(d.has_virtual), L.size,
                               L.exact, list(d.bases), decl=d)
        for rel, fi in idx.files.items():
            lines = fi.text.split("\n")
            code_lines = fi.code.split("\n")
            defs = sorted(defs_by_file.get(rel, []), key=lambda d: d.end_line - d.line)     # innermost first
            top = {}
            for d in defs_by_file.get(rel, []):
                if d.parent is None:
                    for n in d.names:
                        top.setdefault(n, d)

            def inside(ln):
                for d in defs:
                    if d.line <= ln <= d.end_line:
                        return d
                return None

            for i, ln in enumerate(lines):
                m = MARK.match(ln)
                if not m or m.group(2).upper() != self.token:
                    continue
                va, rest = int(m.group(3), 16), m.group(4)
                v = VT.search(rest)
                if v:
                    d = top.get(v.group(1))
                    if d is not None:
                        info[d.uid].vt.add(va)
                    continue
                sig = ""
                for j in range(i + 1, min(i + 6, len(lines))):
                    s = code_lines[j].strip() if j < len(code_lines) else ""
                    if s:
                        sig = s
                        break
                q = QUAL.search(sig)
                owner = meth = None
                if q and not sig.startswith(("struct ", "class ", "union ")):
                    owner, meth = top.get(q.group(1)), q.group(2).replace(" ", "")
                else:
                    d = inside(i + 2)
                    mm = DECL.search(sig)
                    if d is not None and mm:
                        owner, meth = d, mm.group(1).replace(" ", "")
                if owner is None or not meth or owner.uid not in info:
                    continue
                cls = owner.name
                vw = info[owner.uid]
                (vw.ctor if meth == cls else vw.dtor if meth == "~" + cls else vw.meth).add(va)
        self.views = [info[k] for k in sorted(info)]

    # -- queries
    def family(self, va: int, methods=False) -> list[View]:
        """The views that carry `va` as their vtable, ctor or dtor (methods: as any member too)."""
        return [v for v in self.views if va in v.vas(methods)]

    def views_in(self, rel: str) -> list[View]:
        return [v for v in self.views if v.file == rel]

    def by_name(self, rel: str, name: str) -> list[View]:
        """Views of `rel` called `name` (simple or qualified)."""
        return [v for v in self.views_in(rel) if v.name == name or v.simple == name]

    def siblings(self, view: View, methods=False) -> list[View]:
        """The views sharing one of `view`'s own vtable/ctor/dtor VAs (one hop, `view` included)."""
        own = view.vas(methods)
        return [v for v in self.views if v.uid == view.uid or own & v.vas(methods)]

    def layout(self, view: View):
        return self.idx.layout(view.decl)

    def alias_rows(self) -> list[dict]:
        """structs_alias.tsv: one row per vtable/ctor/dtor VA carried by 2+ differently named views."""
        by_va = collections.defaultdict(list)
        for v in self.views:
            for k in ("vt", "ctor", "dtor"):
                for va in getattr(v, k):
                    by_va[(k, va)].append(v)
        rows = []
        for (k, va), vs in by_va.items():
            names = {v.name for v in vs}
            if len(names) < 2:
                continue
            rows.append({"va": f"{va:08X}", "kind": {"vt": "vtable", "ctor": "ctor", "dtor": "dtor"}[k],
                         "names": len(names), "files": len({v.file for v in vs}),
                         "sizes": ",".join(sorted({hex(v.size) for v in vs})),
                         "virtual": "/".join(sorted({str(v.virtual) for v in vs})),
                         "name_list": " ".join(sorted(names))})
        rows.sort(key=lambda r: (-r["names"], r["va"]))
        return rows


def load(repo, subdirs=SUBDIRS, token="TITANIUM") -> Views:
    return Views(cparse.load_index(Path(repo), subdirs=subdirs), token)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["family", "view", "aliases"])
    ap.add_argument("args", nargs="*")
    ap.add_argument("--repo", default=".")
    ap.add_argument("--methods", action="store_true", help="family: a view carrying the VA as any member counts")
    ap.add_argument("--out", help="aliases: write the TSV here (default stdout)")
    a = ap.parse_args(argv)
    vw = load(a.repo)
    if a.cmd == "family":
        if len(a.args) != 1:
            ap.error("family VA")
        rows = [v.row() for v in vw.family(int(a.args[0], 16), a.methods)]
    elif a.cmd == "view":
        if len(a.args) != 2:
            ap.error("view FILE NAME")
        rows = []
        for v in vw.by_name(a.args[0].replace("\\", "/"), a.args[1]):
            rows.append(v.row())
            L = vw.layout(v)
            own = {rm.name for rm in v.decl.raw if rm.name}
            for m in L.members:
                if not m.is_pad and m.path == m.name:
                    print(f"  +0x{m.offset:03x} {m.size:#x} {m.type} {m.name}" + ("" if m.name in own else " (base)"))
    else:
        rows = vw.alias_rows()
    if not rows:
        print("nothing found")
        return 1
    fh = open(a.out, "w", encoding="utf-8", newline="") if a.out else sys.stdout
    w = csv.DictWriter(fh, fieldnames=list(rows[0]), delimiter="\t", lineterminator="\n")
    w.writeheader()
    w.writerows(rows)
    if a.out:
        fh.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())
