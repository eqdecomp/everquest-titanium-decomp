r"""Titanium class, VA-family and field renames (the types rename.py does not touch), gated like rename.py --gate.

    cd eq-titanium
    ..\.venv\Scripts\python.exe tools\readability\class_rename.py class src/EverQuest/tu_166.cpp Owner_guess \
        GuildMgmtWnd_guess
    ..\.venv\Scripts\python.exe tools\readability\class_rename.py family 0x00576BD0 TextFileReader_guess [--methods]
    ..\.venv\Scripts\python.exe tools\readability\class_rename.py field src/EverQuest/tu_166.cpp GuildMgmtWnd_guess \
        receiver_174 motdInput_174 [--no-family]
    ..\.venv\Scripts\python.exe tools\readability\class_rename.py map M.json --gate --journal J [--gate-json G]
    (every command takes --dry-run, --gate, --journal F, --gate-json F, --gate-cache D, --fixtures, -q)

Titanium types are file-local: each TU declares its own view of a class (class_views.py), so a class rename is a
rename inside one TU, and a family rename is one such rename per TU view.

class FILE OLD NEW   the struct/class/union OLD defined (or forward-declared) in FILE becomes NEW, everywhere in FILE:
    every C token (declarations, `OLD::Method` definitions, ctor/dtor names, casts, sizeof, templates, #define
    bodies), whole words in comments (not with --no-comments), and the names of the file's `// EXTERNAL:` (and other)
    markers, undecorated (`OLD::F`) or MSVC-decorated (`??_7OLD@@6B@`, `?F@OLD@@QAEXXZ`, `PAUOLD@@`: a name fragment
    `OLD@` at a fragment start; back-references stay valid because NEW is new to the symbol). Fixtures whose
    "sources" contain FILE follow: "rewrite", rewrite_aliases / rewrite_data_aliases keys and rewrite_inline (the test
    DLL's symbols: always), "function" and callees[VA].name (labels: when FILE gives that VA to OLD). In
    tests/unicorn/crt_defaults.json a rewrite_aliases key naming a VA FILE gives to OLD gets a NEW twin (the old key
    stays: other TUs have their own OLD). Refused: NEW already an identifier in FILE or a name its headers declare
    ("already a different class"), OLD declared by an included header, OLD defined twice in FILE, a fixture that
    also builds another source using OLD, a decorated name where `OLD@` could be the tail of another name.

family VA NEW        every view carrying VA as its vtable, ctor or dtor (--methods: as any member) is renamed NEW in
    its TU, one `class` item per view. Methods keep their per-VA names (rename.py's job); layouts are not merged.
    Not renamed (noted): views in include/ headers, a TU with two views of the family (merge them by hand first),
    views already called NEW.

field FILE CLASS OLD NEW   the data member OLD declared in CLASS (FILE's view) becomes NEW: its declaration, bare
    uses inside CLASS's (and derived views') member functions, ctor initialisers and inline bodies, `CLASS::OLD`,
    `offsetof(CLASS, OLD)`, and `x->OLD` / `x.OLD` where x is typed as CLASS or a derived view (a small typer:
    locals, parameters, `this`, EQ_GLOBAL #defines, file-scope globals, casts, member chains, indexing). When no
    other struct of the TU or its headers has a member OLD, every `->OLD`/`.OLD` is CLASS's. An access whose base
    can't be typed while the name is shared is refused (line listed), as is OLD inside a #define, NEW already a
    member of CLASS/its bases/derived views, NEW bare in file scope, in CLASS's methods or in its headers.
    Unless --no-family, the same field is renamed in every sibling view (class_views: the views sharing CLASS's
    own vtable/ctor/dtor VA) whose own member at the same offset has the same size; views without one (a pad, a
    base's member, another width, an inexact layout) are noted.

--gate: like rename.py --gate (match_gate.gate_txn): apply everything, compare --match the touched TUs before and
after, run the fixtures of the renamed classes' VAs and of the changed functions (plus every changed fixture); a
function identical before must stay identical and nothing may get worse, else every file is restored and each item
(one TU view / one field) is retried alone on top of the ones kept. The journal gets {client, kind: class|field,
file, class, old, new[, offset]} lines for what was kept (gate.py --renames ignores them; they rename no VA).
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import registry as R  # noqa: E402
import rename as rn  # noqa: E402
import class_views as CV  # noqa: E402
import cparse  # noqa: E402  (tools/structs, on sys.path via class_views)

import ctoken as ct  # noqa: E402  (permute/, on sys.path via registry)
import tu  # noqa: E402

Refused = rn.Refused
IDENT = rn.IDENT
CLIENT = "titanium"
MARKER = re.compile(r"^([ \t]*//[ \t]*(?:EXTERNAL|FUNCTION|STUB|LIBRARY|VTABLE|GLOBAL):[ \t]*(\w+)[ \t]+"
                    r"(0[xX][0-9a-fA-F]+))(?:[ \t]+(\S+))?[ \t]*$", re.M)
JSTR = re.compile(r'"(?:\\.|[^"\\])*"')


@dataclass
class TypePlan(rn.Plan):
    file: str = ""
    cls: str = ""
    offset: int | None = None
    vas: set = field(default_factory=set)       # VAs whose fixtures the gate runs

    def journal(self) -> list[dict]:
        j = {"client": self.client, "kind": self.kind, "file": self.file, "class": self.cls, "old": self.old,
             "new": self.new}
        if self.offset is not None:
            j["offset"] = f"0x{self.offset:X}"
        return [j]


def _rel(repo: Path, f: str) -> str:
    p = Path(f)
    return (p.resolve().relative_to(repo).as_posix() if p.is_absolute() else f.replace("\\", "/"))


# --- decorated / undecorated symbols ---------------------------------------------------------------------------

def rename_class_in_symbol(sym: str, old: str, new: str, known=frozenset()) -> str:
    """`sym` with the class name OLD replaced by NEW. Undecorated (`Old::F`, `Old::~Old`): whole identifiers.
    MSVC-decorated: each name fragment `Old@` that starts a fragment (after `?`, `@`, `$`, or after type codes such
    as `PAU`, `??0`, `??_7`). Raises Refused when `Old@` could be the tail of another name (`known` has `XOld` for a
    suffix X of the letters in front) or NEW already is a fragment (a back-reference would be needed)."""
    if not sym.startswith("?"):
        return re.sub(r"(?<![A-Za-z0-9_$])%s(?![A-Za-z0-9_])" % re.escape(old), new, sym)
    hits = [m.start() for m in re.finditer(re.escape(old) + "@", sym)]
    if not hits:
        return sym
    if new + "@" in sym:
        raise Refused(f"{sym}: {new} is already a name in this decorated symbol (back-reference); rename by hand")
    out, pos = [], 0
    for i in hits:
        pre = sym[:i]
        if pre[-1] not in "?@$":
            run = re.search(r"[A-Za-z0-9_]*$", pre).group()
            if run + old in known and pre[:-len(run)][-1:] in ("?", "@", "$", ""):
                continue                    # `@XOld@`: the fragment is another name that ends in OLD
            if any((run[k:] + old) in known for k in range(len(run))):
                raise Refused(f"{sym}: `{old}@` may be the end of another name here; rename by hand")
        out.append(sym[pos:i])
        out.append(new)
        pos = i + len(old)
    out.append(sym[pos:])
    return "".join(out)


def _undecorated_has_class(name: str, old: str) -> bool:
    u = R.undecorate(name) if name.startswith("?") else name
    return old in [p.lstrip("~") for p in re.split(r"::", u.split("(")[0])][:-1] or \
        bool(re.search(r"(?<![\w$])%s(?:::|@)" % re.escape(old), name))


def class_vas(raw: str, old: str, token="TITANIUM") -> set:
    """VAs that this file gives to class `old`: markers naming `old::...` (or a decorated name with that scope),
    markers/definitions on `old::F(` lines, and markers inside old's class body (cparse span)."""
    out = set()
    lines = raw.split("\n")
    fi = cparse.parse_file("x.cpp", raw)
    spans = [(d.line, d.end_line) for d in fi.structs if old in d.names]
    for m in MARKER.finditer(raw):
        if m.group(2).upper() != token:
            continue
        va = int(m.group(3), 16)
        name = m.group(4)
        ln = rn.line_of(raw, m.start())
        if name and _undecorated_has_class(name, old):
            out.add(va)
            continue
        for j in range(ln, min(ln + 5, len(lines))):
            s = lines[j].strip()
            if not s or s.startswith("//"):
                continue
            q = re.match(r"(?:[\w\s\*&<>,]*?\s)?%s\s*::\s*~?\s*\w+\s*\(" % re.escape(old), s)
            if q or any(a <= j + 1 <= b for a, b in spans):
                out.add(va)
            break
    return out


# --- class rename ------------------------------------------------------------------------------------------------

def _struct_defs(raw: str, rel: str):
    return cparse.parse_file(rel, raw).structs


def plan_class(repo, rel: str, old: str, new: str, *, comments=True) -> TypePlan:
    repo = Path(repo).resolve()
    rel = _rel(repo, rel)
    if not IDENT.fullmatch(old) or not IDENT.fullmatch(new):
        raise Refused("class names are plain identifiers")
    if old == new:
        raise Refused("new name = old name")
    if not (repo / rel).is_file():
        raise Refused(f"{rel}: no such file")
    raw = rn._read(repo, rel)
    defs = [d for d in _struct_defs(raw, rel) if old in d.names]
    masked = cparse.mask(raw)
    fwd = re.search(r"\b(?:struct|class|union)\s+%s\s*;" % re.escape(old), masked)
    if not defs and not fwd:
        raise Refused(f"{old} is not a struct/class/union defined in {rel}")
    if len(defs) > 1:
        raise Refused(f"{old} is defined {len(defs)} times in {rel} (lines {', '.join(str(d.line) for d in defs)}); "
                      "rename by hand")
    hdr = rn.header_idents(repo, repo / rel)
    if old in hdr:
        raise Refused(f"{old} is declared by a header {rel} includes: rename the header class instead")
    have = rn.code_idents(raw)
    if have.get(new) or new in hdr:
        what = "a different class" if any(new in d.names for d in _struct_defs(raw, rel)) else "a name"
        raise Refused(f"{new} is already {what} in {rel}" + (" (its headers)" if new in hdr else ""))
    known = set(have) | hdr
    plan = TypePlan(CLIENT, "class", None, old, new, file=rel, cls=old)
    marks = []
    for m in MARKER.finditer(raw):
        if not m.group(4):
            continue
        nn = rename_class_in_symbol(m.group(4), old, new, known)
        if nn != m.group(4):
            marks.append((m.start(4), m.end(4), nn, rn.line_of(raw, m.start(4)), "marker"))
    spans = [x for x in rn.ident_spans(raw, {old}, comments) if not any(a <= x[0] < b for a, b, *_ in marks)]
    edits = [(s, e, new, rn.line_of(raw, s), where) for s, e, _w, where in spans]
    edits = rn.drop_dup_comment_swaps(raw, edits, plan.notes) + marks
    if not edits:
        raise Refused(f"{old}: nothing to change in {rel}")
    new_text = rn.apply_edits(raw, edits)
    before = set(rn.define_clashes(raw))
    clash = [c for c in rn.define_clashes(new_text) if c not in before]
    if clash:
        raise Refused(f"{rel}: the rename defines {', '.join(clash)} twice with different bodies (C4005)")
    plan.edits[rel] = edits
    plan.texts[rel] = new_text
    plan.vas = class_vas(raw, old)
    _plan_class_fixtures(repo, rel, old, new, known, plan)
    _plan_crt_defaults(repo, old, new, known, plan)
    return plan


def _json_strings(o, path=()):
    """(path, string, is_key) of every string in a JSON value (dict keys included)."""
    if isinstance(o, dict):
        for k, v in o.items():
            yield path + (k,), k, True
            yield from _json_strings(v, path + (k,))
    elif isinstance(o, list):
        for i, v in enumerate(o):
            yield from _json_strings(v, path + (i,))
    elif isinstance(o, str):
        yield path, o, False


def _map_strings(o, m: dict):
    if isinstance(o, dict):
        return {m.get(k, k): _map_strings(v, m) for k, v in o.items()}
    if isinstance(o, list):
        return [_map_strings(v, m) for v in o]
    if isinstance(o, str):
        return m.get(o, o)
    return o


def _va_key(k) -> int | None:
    try:
        return int(str(k), 16)
    except ValueError:
        return None


def _class_members(raw: str, rel: str, old: str) -> set:
    """Names declared inside old's class body in `raw` (methods `name(` and data members)."""
    out = set()
    for d in _struct_defs(raw, rel):
        if old in d.names:
            body = "\n".join(cparse.mask(raw).split("\n")[d.line - 1:d.end_line])
            out |= set(re.findall(r"(~?[A-Za-z_]\w*)\s*\(", body))
            out |= own_members(d)
    return out


def _declared_member(label: str, old: str, members: set) -> bool:
    """`Old::M` (undecorated) where M is declared in old's body: a label of this TU's class, whatever its VA."""
    parts = label.split("::")
    return len(parts) == 2 and parts[0] == old and parts[1] in members


def _plan_class_fixtures(repo: Path, rel: str, old: str, new: str, known: set, plan: TypePlan):
    tdir = R.clients.get(CLIENT).tests_dir(repo)
    crt = (repo / R.clients.get(CLIENT).crt_defaults).resolve()
    members = _class_members(rn._read(repo, rel), rel, old)
    for f in sorted(tdir.rglob("*.json")) if tdir.is_dir() else []:
        if f.resolve() == crt:
            continue
        frel = f.relative_to(repo).as_posix()
        raw = rn._read(repo, frel)
        if rel not in raw or old not in raw:
            continue
        try:
            d = json.loads(raw)
        except ValueError:
            continue
        if not isinstance(d, dict) or rel not in (d.get("sources") or []):
            continue
        for s in d.get("sources") or []:
            if s != rel and (repo / s).is_file() and rn.code_idents(rn._read(repo, s)).get(old):
                raise Refused(f"{frel}: also builds {s}, which has its own {old}; rename by hand")
        own_va = _va_key(d.get("original"))
        change, keep = {}, set()
        for path, s, is_key in _json_strings(d):
            nn = rename_class_in_symbol(s, old, new, known)
            if nn == s:
                continue
            top = path[0] if path else None
            sym = (top == "rewrite" and len(path) == 1) or (top == "rewrite_inline" and len(path) == 2) or \
                (top in ("rewrite_aliases", "rewrite_data_aliases") and len(path) == 2 and is_key)
            is_label = (top == "function" and len(path) == 1) or \
                (len(path) >= 3 and path[-1] == "name" and path[-3] == "callees")
            va = own_va if top == "function" else _va_key(path[-2]) if is_label else None
            label = is_label and (va in plan.vas or _declared_member(s, old, members))
            if sym or label:
                change[s] = nn
            else:
                keep.add(s)
                if top == "function" or (path and path[-1] == "name"):
                    plan.notes.append(f"kept {frel} label {s} (that VA is not {old}'s in {rel})")
        both = set(change) & keep
        if both:
            raise Refused(f"{frel}: {sorted(both)[0]} is both a symbol of {old} and another label; rename by hand")
        if not change:
            continue
        edits = []
        for m in JSTR.finditer(raw):
            v = json.loads(m.group())
            if v in change:
                edits.append((m.start(), m.end(), '"' + rn._json_str(change[v]) + '"', rn.line_of(raw, m.start()),
                              "fixture"))
        new_text = rn.apply_edits(raw, edits)
        if json.loads(new_text) != _map_strings(d, change):
            raise Refused(f"{frel}: fixture edit did not give the expected JSON")
        plan.edits[frel] = edits
        plan.texts[frel] = new_text


def _plan_crt_defaults(repo: Path, old: str, new: str, known: set, plan: TypePlan):
    crel = R.clients.get(CLIENT).crt_defaults
    p = repo / crel
    if not p.is_file():
        return
    raw = rn._read(repo, crel)
    if old not in raw:
        return
    d = json.loads(raw)
    al = d.get("rewrite_aliases") or {}
    add = []
    for k, v in al.items():
        if _va_key(v) not in plan.vas:
            continue
        nk = rename_class_in_symbol(k, old, new, known)
        if nk != k and nk not in al:
            add.append((k, nk, v))
    if not add:
        return
    m = re.search(r'"rewrite_aliases"\s*:\s*\{', raw)
    edits = []
    for k, nk, v in add:
        km = re.compile(r'"%s"(?=\s*:)' % re.escape(rn._json_str(k))).search(raw, m.end())
        ls = raw.rfind("\n", 0, km.start()) + 1
        indent = raw[ls:km.start()]
        sep = "\n" + indent if not indent.strip() and ls < km.start() else " "
        edits.append((km.start(), km.start(), f'"{rn._json_str(nk)}": {json.dumps(v)},{sep}',
                      rn.line_of(raw, km.start()), "crt-twin"))
    new_text = rn.apply_edits(raw, edits)
    want = dict(d, rewrite_aliases={**al, **{nk: v for _k, nk, v in add}})
    if json.loads(new_text) != want:
        raise Refused(f"{crel}: adding the {new} twin keys did not give the expected JSON")
    plan.edits[crel] = edits
    plan.texts[crel] = new_text
    plan.notes.append(f"{crel}: added {len(add)} {new} twin key(s) (old keys kept for other TUs' {old})")


# --- family -------------------------------------------------------------------------------------------------------

def expand_family(repo, va: int, new: str, views: CV.Views | None = None, methods=False):
    """-> ([class items], notes) for the views of the VA family (one per TU)."""
    views = views or CV.load(repo)
    fam = views.family(va, methods)
    if not fam:
        raise Refused(f"0x{va:08X}: no view carries it as vtable/ctor/dtor" + ("" if methods else " (try --methods)"))
    items, notes = [], []
    by_file = collections.defaultdict(list)
    for v in fam:
        by_file[v.file].append(v)
    for rel, vs in sorted(by_file.items()):
        names = sorted({v.name for v in vs})
        if rel.startswith("include/"):
            notes.append(f"{rel}: header class {', '.join(names)} left alone")
            continue
        if len(vs) > 1:
            notes.append(f"{rel}: {len(vs)} views of the family here ({', '.join(names)}); merge them by hand")
            continue
        v = vs[0]
        if v.simple == new:
            notes.append(f"{rel}: already {new}")
            continue
        items.append({"kind": "class", "file": rel, "old": v.simple, "new": new})
    return items, notes


# --- field rename -------------------------------------------------------------------------------------------------

def tu_index(repo: Path, rel: str, raw: str | None = None) -> cparse.Index:
    """cparse index of one TU and the include/ headers (what its layouts can see)."""
    idx = cparse.Index()
    inc = repo / "include"
    for p in sorted(inc.rglob("*.h")) if inc.is_dir() else []:
        idx.add(cparse.parse_file(p.relative_to(repo).as_posix(), p.read_text(encoding="utf-8", errors="replace")))
    idx.add(cparse.parse_file(rel, raw if raw is not None else rn._read(repo, rel)))
    idx.resolve_aliases()
    return idx


def own_members(d) -> set:
    out = set()
    for rm in d.raw:
        if rm.name:
            out.add(rm.name)
        elif rm.inline is not None:
            out |= own_members(rm.inline)
    return out


def field_span(L, name: str):
    """(offset, size) of a direct member of layout L, or None."""
    if name not in L.direct:
        return None
    off = L.direct[name][0]
    for a in L.aggregates:
        if a.path == name:
            return a.offset, a.size
    for m in L.members:
        if m.path == name:
            return m.offset, m.size
    sub = [m for m in L.members if m.path.startswith(name + ".")]
    if sub:
        return off, max(m.offset + m.size for m in sub) - off
    return off, 0


def _line_starts(text: str) -> list:
    out = [0]
    for m in re.finditer("\n", text):
        out.append(m.end())
    return out


class _Typer:
    """Types the base of a member access in one TU (struct name or None)."""

    def __init__(self, idx: cparse.Index, rel: str, raw: str, S, M, funcs, pp=()):
        self.idx, self.rel, self.raw, self.S, self.M = idx, rel, raw, S, M
        self.funcs = funcs
        self.globals = {}
        for t in pp:
            if t.kind == "pp":
                g = re.match(r"#\s*define\s+(\w+)\s+EQ_(?:GLOBAL|ARRAY)\s*\(\s*(?:(?:const|struct|class|union)\s+)*"
                             r"(\w+)\s*(\**)", t.text)
                if g:
                    self.globals[g.group(1)] = (g.group(2), len(g.group(3)) + (1 if "EQ_ARRAY" in t.text else 0))
        self.fn_ranges = [(self._idx_at(f.start), self._idx_at(f.body_end), f) for f in funcs]
        inside = [False] * (len(S) + 1)
        for a, b, _f in self.fn_ranges:
            for i in range(a, min(b, len(S))):
                inside[i] = True
        self.file_scope = [i for i in range(len(S)) if not inside[i]]

    def _idx_at(self, pos: int) -> int:
        lo, hi = 0, len(self.S)
        while lo < hi:
            mid = (lo + hi) // 2
            if self.S[mid].start < pos:
                lo = mid + 1
            else:
                hi = mid
        return lo

    def func_of(self, k: int):
        for a, b, f in self.fn_ranges:
            if a <= k < b:
                return a, f
        return None, None

    def owner(self, f) -> str | None:
        return f.name.rsplit("::", 1)[0].split("::")[-1] if f is not None and "::" in f.name else None

    def struct(self, name: str):
        return self.idx.find_struct(name, self.rel) if name else None

    def member_type(self, sname: str, member: str):
        d = self.struct(sname)
        if d is None:
            return None
        L = self.idx.layout(d)
        if member not in L.direct:
            return None
        _o, tname, dims = L.direct[member]
        base, ptr = cparse.split_type(tname)
        return base.replace("struct ", "").replace("class ", "").strip(), ptr + len(dims or [])

    def decl_type(self, name: str, lo: int, hi: int):
        """The type of the last declaration of `name` in S[lo:hi] (`T [*&]* name` before ; , = ) [ ( :)."""
        S, best = self.S, None
        for k in range(max(lo, 1), hi):
            t = S[k]
            if t.kind != "id" or t.text != name or k + 1 >= len(S) or S[k + 1].text not in (";", ",", "=", ")", "[",
                                                                                              "(", ":"):
                continue
            j, ptr = k - 1, 0
            while j >= lo and S[j].text in ("*", "&", "const", "volatile"):
                ptr += S[j].text == "*" or S[j].text == "&"
                j -= 1
            if j >= lo and S[j].kind == "id" and S[j].text not in ("return", "case", "goto", "delete", "new",
                                                                   "sizeof", "else") and \
                    (j == 0 or S[j - 1].text in (";", "{", "}", "(", ",", ")", ":", "const", "struct", "class",
                                                 "union", "unsigned", "signed", "static", "volatile", "register")):
                best = (S[j].text, ptr)
        return best

    def type_of(self, k: int, depth=0):
        """(struct name, pointer levels) of the operand ending at S[k], or None."""
        if k < 0 or depth > 12:
            return None
        S, M = self.S, self.M
        t = S[k]
        if t.kind == "id":
            p = S[k - 1].text if k > 0 else ""
            if p in (".", "->"):
                b = self.type_of(k - 2, depth + 1)
                return self.member_type(b[0], t.text) if b else None
            if p == "::":
                return None
            fa, f = self.func_of(k)
            if t.text == "this":
                o = self.owner(f)
                return (o, 1) if o else None
            if f is not None:
                dt = self.decl_type(t.text, fa, k)
                if dt:
                    return dt
                o = self.owner(f)
                if o:
                    mt = self.member_type(o, t.text)
                    if mt:
                        return mt
            if t.text in self.globals:
                return self.globals[t.text]
            best = None
            for i in self.file_scope:
                if i >= k:
                    break
                if S[i].kind == "id" and S[i].text == t.text:
                    dt = self.decl_type(t.text, max(0, i - 6), i + 1)
                    best = dt or best
            return best
        if t.text == "]" and k in M:
            b = self.type_of(M[k] - 1, depth + 1)
            return (b[0], max(b[1] - 1, 0)) if b else None
        if t.text == ")" and k in M:
            o = M[k]
            before = S[o - 1] if o > 0 else None
            if before is not None and before.text == ">":
                j = o - 2
                stars = 0
                while j > 0 and S[j].text in ("*", "&", "const"):
                    stars += S[j].text in ("*", "&")
                    j -= 1
                if S[j].kind == "id" and j >= 2 and S[j - 1].text == "<" and S[j - 2].text.endswith("_cast"):
                    return S[j].text, stars
                return None
            if before is not None and (before.kind == "id" and before.text not in ("return", "sizeof", "if", "while",
                                                                                    "switch", "case")
                                       or before.text in (")", "]")):
                return None                                     # a call: return types are not typed
            if S[o + 1].text == "(" and (o + 1) in M:
                c = M[o + 1]
                inner = [x.text for x in S[o + 2:c]]
                while inner and inner[0] in ("const", "struct", "class", "union", "volatile"):
                    inner = inner[1:]
                if inner and re.fullmatch(r"[A-Za-z_]\w*", inner[0]) and c + 1 < k \
                        and all(x in ("*", "&", "const") for x in inner[1:]):
                    return inner[0], sum(1 for x in inner[1:] if x in ("*", "&"))
            return self.type_of(k - 1, depth + 1)
        return None


def plan_field(repo, rel: str, cls: str, old: str, new: str, idx: cparse.Index | None = None) -> TypePlan:
    repo = Path(repo).resolve()
    rel = _rel(repo, rel)
    if not IDENT.fullmatch(old) or not IDENT.fullmatch(new):
        raise Refused("field names are plain identifiers")
    if old == new:
        raise Refused("new name = old name")
    raw = rn._read(repo, rel)
    idx = idx or tu_index(repo, rel, raw)
    fi = idx.files[rel]
    cands = [d for d in fi.structs if (CV.qname(d) == cls or cls in d.names)]
    if len(cands) != 1:
        raise Refused(f"{cls}: {len(cands)} definitions in {rel}")
    d = cands[0]
    simple = d.name
    if old not in own_members(d):
        raise Refused(f"{old} is not a data member declared in {cls} ({rel})")
    L = idx.layout(d)
    span = field_span(L, old)
    # the family: this view and every view of the file deriving from it (by base name, transitively)
    fam = {simple}
    changed = True
    while changed:
        changed = False
        for x in fi.structs:
            if x.name not in fam and any(cparse.split_type(b)[0] in fam for b in x.bases):
                fam.add(x.name)
                changed = True
    fam_defs = [x for x in fi.structs if x.name in fam]
    for x in fam_defs:
        if x is not d and old in own_members(x):
            raise Refused(f"{x.name} (derived from {cls}) declares its own {old}; rename by hand")
        if new in idx.layout(x).direct:
            raise Refused(f"{new} is already a member of {x.name} (or its bases)")
    nested = [x for x in fi.structs if x is not d and x.line >= d.line and x.end_line <= d.end_line and x.tag
              and old in own_members(x)]
    if nested:
        raise Refused(f"a struct nested in {cls} ({nested[0].name}) has its own {old}; rename by hand")
    hdr = rn.header_idents(repo, repo / rel)
    if new in hdr:
        raise Refused(f"{new} is a file-scope name of a header {rel} includes")
    toks = ct.tokenize(raw)
    for t in toks:
        if t.kind == "pp" and re.search(r"\b%s\b" % re.escape(old), t.text):
            raise Refused(f"{old} is used in a preprocessor line ({rel}:{rn.line_of(raw, t.start)}); rename by hand")
    S = ct.significant(toks)
    S = [t for t in S if t.kind != "pp"]
    M = ct.match_brackets(S)
    funcs = tu.find_functions(raw)
    ls = _line_starts(raw)
    pos_of = lambda line: ls[line - 1] if line - 1 < len(ls) else len(raw)      # noqa: E731
    body = (pos_of(d.line), pos_of(d.end_line + 1) if d.end_line < len(ls) else len(raw))
    fam_bodies = [(pos_of(x.line), pos_of(x.end_line + 1) if x.end_line < len(ls) else len(raw)) for x in fam_defs]
    fam_ids = {id(x) for x in fam_defs}
    other_owner = [x for x in idx.all_defs() if id(x) not in fam_ids and old in own_members(x)]
    shared = bool(other_owner)
    ty = _Typer(idx, rel, raw, S, M, funcs, [t for t in toks if t.kind == "pp"])
    struct_spans = [(pos_of(x.line), pos_of(x.end_line + 1) if x.end_line < len(ls) else len(raw))
                    for x in fi.structs if x.tag or x.aliases]
    in_any_struct = lambda p: any(a <= p < b for a, b in struct_spans)      # noqa: E731
    # NEW used bare where a member NEW would capture it
    if new in {f.simple for f in funcs}:
        raise Refused(f"{new} is a file-scope name in {rel} (a function)")
    for k, t in enumerate(S):
        if t.kind != "id" or t.text != new or (k and S[k - 1].text in (".", "->", "::")):
            continue
        fa, f = ty.func_of(k)
        if f is not None and ty.owner(f) in fam:
            raise Refused(f"{new} is already used in {f.name} ({rel}:{rn.line_of(raw, t.start)})")
        if f is None and not in_any_struct(t.start):
            raise Refused(f"{new} is a file-scope name in {rel} (line {rn.line_of(raw, t.start)})")
        if f is None and any(a <= t.start < b for a, b in fam_bodies):
            raise Refused(f"{new} is already used in a {cls} view body ({rel}:{rn.line_of(raw, t.start)})")
    edits, ambiguous, vas = [], [], set()
    fn_va = _function_vas(raw, funcs)
    for k, t in enumerate(S):
        if t.kind != "id" or t.text != old:
            continue
        p = S[k - 1].text if k else ""
        ours = False
        if p in (".", "->"):
            if not shared:
                ours = True
            else:
                b = ty.type_of(k - 2)
                if b is None or ty.struct(b[0]) is None:
                    ambiguous.append(rn.line_of(raw, t.start))
                    continue
                ours = b[0] in fam
        elif p == "::":
            ours = k >= 2 and S[k - 2].text in fam
        else:
            fa, f = ty.func_of(k)
            if any(a <= t.start < b for a, b in fam_bodies):
                ours = True
            elif f is not None and ty.owner(f) in fam:
                if any(getattr(x, "name", None) == old for x in f.params):
                    raise Refused(f"{f.name} has a parameter {old}; rename by hand")
                dt = ty.decl_type(old, ty._idx_at(f.body_start), k)
                if dt and dt[0] not in ("this",):
                    raise Refused(f"{f.name} declares a local {old} ({rel}:{rn.line_of(raw, t.start)}); rename by hand")
                ours = True
            elif k >= 4 and S[k - 1].text == "," and S[k - 2].text in fam and S[k - 3].text == "(" and \
                    S[k - 4].text == "offsetof":
                ours = True
        if ours:
            edits.append((t.start, t.end, new, rn.line_of(raw, t.start), "field"))
            fa, f = ty.func_of(k)
            if f is not None and f.body_start in fn_va:
                vas.add(fn_va[f.body_start])
    if ambiguous:
        raise Refused(f"{old} is a member of {', '.join(sorted({x.name for x in other_owner})[:3])} too and the base "
                      f"at {rel} line(s) {', '.join(map(str, sorted(set(ambiguous))[:6]))} can't be typed; "
                      "rename by hand")
    if not any(body[0] <= e[0] < body[1] for e in edits):
        raise Refused(f"{old}: declaration not found in {cls}'s body")
    plan = TypePlan(CLIENT, "field", None, old, new, file=rel, cls=simple, offset=span[0] if span else None, vas=vas)
    plan.edits[rel] = edits
    plan.texts[rel] = rn.apply_edits(raw, edits)
    return plan


def _function_vas(raw: str, funcs) -> dict:
    """{body_start: VA} of the file's annotated function definitions."""
    out = {}
    for f in funcs:
        lead = raw[f.lead:f.start]
        m = list(re.finditer(r"//\s*FUNCTION:\s*\w+\s+0[xX]([0-9a-fA-F]+)", lead))
        if m:
            out[f.body_start] = int(m[-1].group(1), 16)
    return out


def expand_field_family(repo, rel: str, cls: str, old: str, new: str, views: CV.Views | None = None,
                        methods=False):
    """-> ([field items], notes): the field in `cls` and the same-offset, same-size own member of each sibling
    view."""
    repo = Path(repo).resolve()
    rel = _rel(repo, rel)
    views = views or CV.load(repo)
    seeds = views.by_name(rel, cls)
    if len(seeds) != 1:
        raise Refused(f"{cls}: {len(seeds)} views in {rel}")
    seed = seeds[0]
    span = field_span(views.layout(seed), old)
    if span is None or old not in own_members(seed.decl):
        raise Refused(f"{old} is not a data member declared in {cls} ({rel})")
    items = [{"kind": "field", "file": rel, "class": cls, "old": old, "new": new}]
    notes = []
    for v in views.siblings(seed, methods):
        if v.uid == seed.uid:
            continue
        where = f"{v.file} {v.name}"
        if v.file.startswith("include/"):
            notes.append(f"{where}: header class left alone")
            continue
        if not (v.exact and seed.exact):
            notes.append(f"{where}: layout not exact, offsets unproven")
            continue
        Lv = views.layout(v)
        own = own_members(v.decl)
        hits = [n for n in Lv.direct if n in own and field_span(Lv, n) == span]
        if not hits:
            at = [n for n in Lv.direct if Lv.direct[n][0] == span[0]]
            notes.append(f"{where}: no own member at +0x{span[0]:X} of size {span[1]:#x}"
                         + (f" ({', '.join(at)} differs or is inherited)" if at else " (pad)"))
            continue
        for n in hits:
            if n == new:
                notes.append(f"{where}: already {new}")
            else:
                items.append({"kind": "field", "file": v.file, "class": v.name, "old": n, "new": new})
    return items, notes


# --- applying -----------------------------------------------------------------------------------------------------

def _leaf(it) -> bool:
    return it.get("kind") == "class" or (it.get("kind") == "field" and it.get("family") is False)


def plan_item(repo, it: dict, comments=True) -> TypePlan:
    if it["kind"] == "class":
        return plan_class(repo, it["file"], it["old"], it["new"], comments=comments)
    if it["kind"] == "field":
        return plan_field(repo, it["file"], it["class"], it["old"], it["new"])
    raise Refused(f"unknown item kind {it.get('kind')}")


def expand(repo, it: dict, methods=False):
    """A family / field-family item -> (leaf items, notes); a leaf -> ([it], [])."""
    if it.get("kind") == "family":
        va = it["va"]
        return expand_family(repo, int(va, 16) if isinstance(va, str) else va, it["new"],
                             methods=it.get("methods", methods))
    if it.get("kind") == "field" and it.get("family", True):
        items, notes = expand_field_family(repo, it["file"], it["class"], it["old"], it["new"],
                                           methods=it.get("methods", methods))
        return [dict(x, family=False) for x in items], notes
    return [dict(it)], []


def apply_items(repo, items, comments=True, dry_run=False, journal=None, quiet=False, txn=None, methods=False,
                leaves_out=None):
    """Expand and plan `items` in order, writing each plan before the next is planned. -> (rc, [(leaf, plan)])."""
    rc, done = 0, []
    for it in items:
        try:
            leaves, notes = expand(repo, it, methods)
        except Refused as e:
            print(f"REFUSED {_label(it)}: {e}")
            rc = 2
            continue
        for n in notes:
            print(f"  note ({_label(it)}): {n}")
        for lf in leaves:
            if leaves_out is not None:
                leaves_out.append(lf)
            try:
                plan = plan_item(repo, lf, comments)
            except Refused as e:
                print(f"REFUSED {_label(lf)}: {e}")
                rc = 2
                continue
            print(describe(plan, verbose=not quiet))
            if not dry_run:
                rn.write_plan(repo, plan, journal, txn)
                done.append((lf, plan))
    return rc, done


def _label(it: dict) -> str:
    if it.get("kind") == "family":
        return f"family {it['va']} -> {it['new']}"
    if it.get("kind") == "field":
        return f"field {it['file']} {it['class']}.{it['old']} -> {it['new']}"
    return f"class {it.get('file')} {it.get('old')} -> {it.get('new')}"


def describe(plan: TypePlan, verbose=True) -> str:
    head = f"{plan.client} {plan.kind} {plan.file} " + \
        (f"{plan.cls}.{plan.old} -> {plan.new}" + (f" (+0x{plan.offset:X})" if plan.offset is not None else "")
         if plan.kind == "field" else f"{plan.old} -> {plan.new}")
    out = [head]
    for rel, edits in sorted(plan.edits.items()):
        kinds = collections.Counter(e[4] for e in edits)
        out.append(f"  {rel}: " + ", ".join(f"{k} {v}" for k, v in sorted(kinds.items())))
        if verbose:
            for s, e, new, line, where in sorted(edits)[:200]:
                out.append(f"    {line}: {where} -> {new}")
    for n in plan.notes:
        out.append(f"  note: {n}")
    return "\n".join(out)


def gated(repo, items, *, comments=True, journal=None, gate_json=None, cache=None, fixtures="renamed", quiet=False,
          methods=False) -> int:
    """Apply everything, gate once; on a failure restore and bisect the leaves (match_gate.bisect: halves on top of
    the kept ones, down to the leaves that fail)."""
    import match_gate as MG
    verdicts = []

    def run(group, leaves_out=None):
        txn = MG.Txn(repo)
        rc, done = apply_items(repo, group, comments, quiet=quiet, txn=txn, methods=methods, leaves_out=leaves_out)
        if not done:
            return rc, None
        vas = set().union(*(p.vas for _l, p in done))
        try:
            v = MG.gate_txn(repo, txn, vas, cache=cache, fixtures=fixtures)
        except BaseException:
            txn.restore()
            raise
        verdicts.append({"items": [_label(lf) for lf, _p in done], **v.as_json()})
        print(v.report())
        if not v.ok:
            txn.restore()
        elif journal:
            rn.write_journal(journal, [p for _l, p in done])
        return rc, v

    leaves = []
    rc, v = run(items, leaves)
    rejected = []
    if v is not None and not v.ok:
        if len(leaves) > 1:
            rc_b, rejected = MG.bisect(leaves, run, first=v)
            rc = max(rc, rc_b)
        else:
            rejected.append((leaves[0] if leaves else items[0], v))
    for it, vv in rejected:
        why = "; ".join((vv.problems + vv.regressions + [f"fixture {f}" for f in vv.fixtures_failed])[:3])
        print(f"GATE-REJECTED {_label(it)}: {why}")
    if gate_json:
        Path(gate_json).write_text(json.dumps(verdicts, indent=1), encoding="utf-8")
    return 2 if rc == 2 else (1 if rejected else 0)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["class", "family", "field", "map"])
    ap.add_argument("args", nargs="*")
    ap.add_argument("--repo", default=".")
    ap.add_argument("--methods", action="store_true",
                    help="family/siblings: a view carrying the VA as any member counts")
    ap.add_argument("--no-family", action="store_true", help="field: only the given view")
    ap.add_argument("--no-comments", action="store_true", help="class: leave comments alone (markers still follow)")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--journal", help="append the kept renames (JSON lines) here")
    ap.add_argument("--gate", action="store_true", help="compare --match before/after + fixtures; restore on a failure")
    ap.add_argument("--fixtures", choices=["renamed", "tu", "none"], default="renamed")
    ap.add_argument("--gate-json", help="--gate: write the verdict(s) here")
    ap.add_argument("--gate-cache", help="--gate: work folder (default <build>/readability/titanium)")
    ap.add_argument("-q", "--quiet", action="store_true")
    a = ap.parse_args(argv)
    repo = Path(a.repo).resolve()
    n = {"class": 3, "family": 2, "field": 4, "map": 1}[a.cmd]
    if len(a.args) != n:
        ap.error({"class": "class FILE OLD NEW", "family": "family VA NEW", "field": "field FILE CLASS OLD NEW",
                  "map": "map M.json"}[a.cmd])
    if a.cmd == "class":
        items = [{"kind": "class", "file": a.args[0], "old": a.args[1], "new": a.args[2]}]
    elif a.cmd == "family":
        items = [{"kind": "family", "va": a.args[0], "new": a.args[1]}]
    elif a.cmd == "field":
        items = [{"kind": "field", "file": a.args[0], "class": a.args[1], "old": a.args[2], "new": a.args[3],
                  "family": not a.no_family}]
    else:
        items = json.loads(Path(a.args[0]).read_text(encoding="utf-8"))
        if isinstance(items, dict):
            items = items.get("items") or []
    for it in items:
        if it.get("file"):
            it["file"] = _rel(repo, it["file"])
    if a.gate and not a.dry_run:
        return gated(repo, items, comments=not a.no_comments, journal=a.journal, gate_json=a.gate_json,
                     cache=a.gate_cache, fixtures=a.fixtures, quiet=a.quiet, methods=a.methods)
    rc, _done = apply_items(repo, items, not a.no_comments, dry_run=a.dry_run, journal=a.journal, quiet=a.quiet,
                            methods=a.methods)
    return rc


if __name__ == "__main__":
    sys.exit(main())
