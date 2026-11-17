r"""Safe rename: a function, a VA global (#define) or a local/label, everywhere its name lives.

    cd eq-trilogy
    ..\.venv\Scripts\python.exe tools\readability\rename.py -c eqmain WrapTextIntoRows_guess WrapTextIntoLines_guess
    ..\.venv\Scripts\python.exe tools\readability\rename.py -c eqmain 0x10009080 WrapTextIntoLines_guess --dry-run
    ..\.venv\Scripts\python.exe tools\readability\rename.py -c trilogy local_804 slotCount --in 0x004E4C10
    ..\.venv\Scripts\python.exe tools\readability\rename.py -c eqgfx --map proposals.json [--journal F]

OLD is a function name (qualified `Class::Name` or simple), a `#define` name, or a VA (`0x...`: the function
annotated at it, else the VA's canonical global name from the registry). NEW is the new name (for a member:
simple, or qualified with the same class).

What is renamed (C tokens, not regex: string literals are never touched; comments get whole-word updates
unless --no-comments):
  function   the identifier in every code file of the client (src/ + its include/ headers; #define bodies
             included), the fixtures' "function" / "rewrite" / callees[VA].name / rewrite_aliases keys (test-DLL
             symbols such as `_Old`, `?Old@Class@@QAEXXZ`, also a stale `FUN_<va>`), the queue entry's name,
             names/<names>.manual.csv (row added or updated: `_guess` -> confidence low, else certain), and
             #define call macros of that VA whose name is the old name or its upper-snake form
             (`WRAP_TEXT_INTO_ROWS_GUESS`, `EQGFX_WRAP_..._GUESS`): they follow in the same style.
  global     every `#define OLD EQ_GLOBAL/ARRAY/...(..., VA)` of that VA and the uses of OLD in each file that
             defines or sees it; with --unify-defines also the VA's other #define names (one name per VA).
  local      --in VA: only inside that function (head + body): locals, parameters, goto labels.

Refused (exit 2, nothing written):
  - NEW is a #define name anywhere in the client's files or include/ (a macro would rewrite the definition);
  - NEW is already an identifier in the files that would change (--allow-existing skips this one check);
  - OLD's simple name is annotated at another VA too (ambiguous: rename by VA with --only-files);
  - a touched file would get two #defines of one name with different bodies (C4005);
  - the new name is not an identifier, or a qualified NEW names another class.

--dry-run prints every edit. --journal F appends one JSON line per rename ({client, va, kind, old, new});
gate.py --renames F maps symbol names with it. Ghidra: run ghidra/scripts/apply_names.py afterwards.

Titanium (`-c titanium`, a client with file-local types: every TU declares its own view of a class, so one VA
can carry a different name in each TU) changes a function rename like this:
  - files by VA: a file is renamed when it defines the VA, has an `// EXTERNAL:` marker for it, or names it
    through an EQ_* macro; a file whose markers/definitions give OLD's simple name to ANOTHER VA is left alone
    (another view's function), and a file with both is refused. A file with neither is renamed when it names the
    old class (a member) or when no other VA uses the simple name (a free function linked by its decorated name).
  - a caller's own view name follows (--keep-views keeps them): a free function's, and a member's (`View::Old` ->
    `View::NEW`, the view class keeps its name: one name per function everywhere). A member view is kept and
    noted ("kept view name") when a token swap would not be exact (member_view_clash: NEW already in the file,
    the old name declared by another class, used outside the view, in a header or a preprocessor line).
  - `// EXTERNAL: TITANIUM 0x<va> <name>` markers of the VA follow (undecorated `Class::Old` or decorated
    `?Old@Class@@...`), also with --no-comments.
  - fixtures by VA: `"function"`/`"rewrite"` of the VA's own fixtures (decorated too), `callees[VA].name` in any
    view (`Class::Old` keeps its class), and `rewrite_aliases` keys whose value is the VA (`?Old@AnyView@@...`,
    `_Old`); in tests/unicorn/crt_defaults.json as well.
  - decorated names are MSVC 7.1: `?Old@Class@@QAEXXZ`. Refused when the signature would need a name
    back-reference (NEW or OLD spelled as a type in it: `U0@`), which a text swap can't give.
  - another VA with the same simple name is not refused up front (views reuse member names); a free function
    or a qualified NEW that already names a function is.
  - --gate: snapshot compare --match of the touched TUs, apply, compare again and run the fixtures of the renamed
    VAs and their callers (match_gate.py); a function identical before must stay identical, else every file is
    restored. With --map the whole map is gated once; on a failure it is bisected (halves on top of the kept
    ones, down to the items that fail alone). TUs whose edit is inert (comments only, or a marker no code uses)
    are not compiled (match_gate.inert_changes).
No names/*.csv rows for a client without a names file (Titanium has none).
"""
from __future__ import annotations

import argparse
import collections
import csv
import io
import json
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import registry as R  # noqa: E402

import ctoken as ct  # noqa: E402  (permute/, on sys.path via registry)
import tu  # noqa: E402

IDENT = re.compile(r"[A-Za-z_]\w*")
QUAL = re.compile(r"[A-Za-z_~]\w*(?:::[A-Za-z_~]\w*)*")
_PP_TOKEN = re.compile(r'(?P<comment>//[^\n]*|/\*.*?\*/)|(?P<str>L?"(?:\\.|[^"\\\n])*"|L?\'(?:\\.|[^\'\\\n])*\')'
                       r'|(?P<id>[A-Za-z_]\w*)|(?P<num>\d\w*)', re.S)
CSV_COLS = ["address", "name", "confidence", "source", "note", "from_address", "file"]


class Refused(Exception):
    pass


@dataclass
class Plan:
    client: str
    kind: str                   # fn | global | local
    va: int | None
    old: str
    new: str
    edits: dict = field(default_factory=lambda: collections.defaultdict(list))   # rel -> [(start, end, text, line)]
    texts: dict = field(default_factory=dict)          # rel -> new full text
    notes: list = field(default_factory=list)
    renamed_files: list = field(default_factory=list)  # (old rel, new rel)

    def journal(self) -> list[dict]:
        out = [{"client": self.client, "va": f"{self.va:08X}" if self.va is not None else None,
                "kind": self.kind, "old": self.old, "new": self.new}]
        for o, n in self.notes_macros:
            out.append({"client": self.client, "va": f"{self.va:08X}" if self.va is not None else None,
                        "kind": "macro", "old": o, "new": n})
        return out

    notes_macros: list = field(default_factory=list)


# --- token-level replacement --------------------------------------------------------------------------------

def code_like(name: str) -> bool:
    """A name that can't be an ordinary word of prose (`param_1`, `WrapText`, `g_x`, `FUN_1000`): only these are
    updated inside comments, so renaming `count` -> `rows` and back doesn't rewrite the English word "rows"."""
    return bool(re.search(r"_|\d|[a-z][A-Z]|^[A-Z]{2,}", name))


def ident_spans(text: str, names: set, comments=True, lo=0, hi=None):
    """[(start, end, name, where)] of identifier occurrences of `names` in text[lo:hi]: code tokens, identifiers
    inside preprocessor lines (not their string literals), and (comments=True) whole words in comments."""
    hi = len(text) if hi is None else hi
    out = []
    cnames = {n for n in names if code_like(n)}
    for t in ct.tokenize(text):
        if t.end <= lo or t.start >= hi:
            continue
        if t.kind == "id" and t.text in names:
            out.append((t.start, t.end, t.text, "code"))
        elif t.kind == "pp":
            for m in _PP_TOKEN.finditer(t.text):
                if m.lastgroup == "id" and m.group() in names:
                    out.append((t.start + m.start(), t.start + m.end(), m.group(), "pp"))
                elif m.lastgroup == "comment" and comments:
                    for w in re.finditer(r"(?<![\w$])[A-Za-z_]\w*(?![\w$])", m.group()):
                        if w.group() in cnames:
                            s = t.start + m.start() + w.start()
                            out.append((s, s + len(w.group()), w.group(), "comment"))
        elif t.kind == "comment" and comments:
            for w in re.finditer(r"(?<![\w$])[A-Za-z_]\w*(?![\w$])", t.text):
                if w.group() in cnames:
                    out.append((t.start + w.start(), t.start + w.end(), w.group(), "comment"))
    return [x for x in out if lo <= x[0] and x[1] <= hi]


def dup_neighbour(text: str, s: int, e: int, new: str) -> bool:
    """True if swapping text[s:e] for `new` in a comment would put the same word next to itself
    ("effect slotIndex `slotIndex`"): the nearest word to the left or right (backticks, quotes and blanks between
    ignored) is already `new`."""
    left = re.search(r"([A-Za-z_]\w*)[\s`'\"]*$", text[max(0, s - 80):s])
    right = re.match(r"[\s`'\"]*([A-Za-z_]\w*)", text[e:e + 80])
    return any(m and m.group(1) == new for m in (left, right))


def drop_dup_comment_swaps(raw: str, edits, notes: list):
    """Comment edits that would double a word are dropped and listed in `notes` (the identifier stays; the prose
    needs a manual look)."""
    out = []
    for ed in edits:
        s, en, new, line, where = ed
        if where == "comment" and dup_neighbour(raw, s, en, new):
            notes.append(f"skipped comment swap line {line}: {raw[s:en]} -> {new} (would double the word {new})")
        else:
            out.append(ed)
    return out


def member_starts(text: str) -> set:
    """Start offsets of the identifier tokens right after `.`, `->` or `::` (struct members and qualified names):
    a local/parameter rename must never touch them (wave 1: a parameter `gender` also named the member
    `->gender`, 5 member uses were renamed and the build broke)."""
    out, prev = set(), None
    for t in ct.tokenize(text):
        if t.kind == "id" and prev in (".", "->", "::"):
            out.add(t.start)
        if t.kind not in ("ws", "comment"):
            prev = t.text
    return out


def code_idents(text: str, skip_members=False) -> collections.Counter:
    """Identifier counts of a file's code (pp lines included, comments and literals not). skip_members: leave
    out names right after `.` or `->` (struct fields: a local may share a field's name)."""
    c = collections.Counter()
    prev = None
    for t in ct.tokenize(text):
        if t.kind == "id":
            if not (skip_members and prev in (".", "->")):
                c[t.text] += 1
        elif t.kind == "pp":
            for m in _PP_TOKEN.finditer(t.text):
                if m.lastgroup == "id":
                    c[m.group()] += 1
        if t.kind not in ("ws", "comment"):
            prev = t.text
    return c


def apply_edits(text: str, edits) -> str:
    out, pos = [], 0
    for s, e, new, *_ in sorted(edits, key=lambda x: x[0]):
        if s < pos:
            raise Refused(f"overlapping edits at {s}")
        out.append(text[pos:s])
        out.append(new)
        pos = e
    out.append(text[pos:])
    return "".join(out)


def line_of(text: str, off: int) -> int:
    return text.count("\n", 0, off) + 1


def define_names(text: str) -> dict:
    """{macro name: [normalised bodies]} of a file's #defines (between #undefs a re-#define is a new one)."""
    out = collections.defaultdict(list)
    for m in re.finditer(r"^[ \t]*#[ \t]*(define|undef)[ \t]+([A-Za-z_]\w*)((?:\([^)]*\))?)(.*(?:\\\r?\n.*)*)",
                         text, re.M):
        if m.group(1) == "undef":
            out[m.group(2)].append(None)
        else:
            body = re.sub(r"\s+", " ", R.blank_comments(m.group(3) + m.group(4)).replace("\\\n", " ")).strip()
            out[m.group(2)].append(body)
    return out


def define_clashes(text: str) -> list[str]:
    """Macro names defined twice with different bodies and no #undef between (VC6 C4005, only a warning)."""
    bad = []
    for name, bodies in define_names(text).items():
        cur = None
        for b in bodies:
            if b is None:
                cur = None
            elif cur is not None and b != cur:
                bad.append(name)
                break
            else:
                cur = b
    return bad


# --- names ----------------------------------------------------------------------------------------------------

def snake_upper(name: str) -> str:
    """`WrapTextIntoRows_guess` -> `WRAP_TEXT_INTO_ROWS_GUESS`, `t3dGetObject` -> `T3D_GET_OBJECT`."""
    s = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name)
    s = re.sub(r"([A-Z]+)([A-Z][a-z])", r"\1_\2", s)
    return re.sub(r"_+", "_", s).upper()


def macro_style_new(macro: str, old_simple: str, new_simple: str) -> str | None:
    """The new name of a call/global macro derived from the function's old name, in the same style, else None:
    `<prefix>_?<core><_suffix>?` where core is the old name as written, its upper-snake form, or that without
    `_GUESS` (`t3dAllocateMemory_call`, `EQGFX_T3D_ALLOCATE_MEMORY_GUESS`, `WRAP_TEXT_INTO_ROWS`)."""
    if macro == old_simple:
        return new_simple
    strip = lambda x: re.sub(r"_guess$", "", x)                      # noqa: E731
    cores = [(strip(old_simple), strip(new_simple)), (snake_upper(strip(old_simple)), snake_upper(strip(new_simple))),
             (old_simple, new_simple), (snake_upper(old_simple), snake_upper(new_simple))]
    for old_c, new_c in cores:
        m = re.fullmatch(r"((?:[A-Za-z][A-Za-z0-9]*_)?)" + re.escape(old_c) + r"((?:_\w+)?)", macro)
        if m:
            suffix = m.group(2)
            if suffix.lower() == "_guess" and new_c.lower().endswith("_guess"):
                suffix = ""                 # FUN_x -> Name_guess: EQGFX_FUN_X_GUESS -> EQGFX_NAME_GUESS
            return m.group(1) + new_c + suffix
    return None


def all_define_names(repo: Path, client: str, reg: R.Registry) -> dict:
    """{macro name: [rel]} over the client's files and every include/ header."""
    out = collections.defaultdict(list)
    files = dict(reg.files)
    inc = repo / "include"
    for p in sorted(inc.rglob("*.h")) if inc.is_dir() else []:
        rel = p.relative_to(repo).as_posix()
        if rel not in files:
            files[rel] = p.read_text(encoding="utf-8", errors="replace")
    for rel, text in files.items():
        for name in define_names(text):
            out[name].append(rel)
    return out


# --- planning -------------------------------------------------------------------------------------------------

def _read(repo: Path, rel: str) -> str:
    with open(repo / rel, encoding="utf-8", errors="replace", newline="") as f:
        return f.read()


def resolve(reg: R.Registry, old: str):
    """(kind, va, qualified old name) for OLD."""
    if re.fullmatch(r"0[xX][0-9a-fA-F]+", old):
        va = int(old, 16)
        e = reg.entries.get(va)
        if e is None:
            raise Refused(f"{old}: not in the {reg.client} registry")
        if e.ann_name:
            return "fn", va, e.ann_name
        d = e.define_names
        if not d:
            raise Refused(f"{old}: no definition and no #define name to rename")
        return "global", va, e.canonical
    hits = [(va, e) for va, e in reg.entries.items()
            if any(s.name == old or (s.source == "ann" and R.simple(s.name) == old and "::" not in old)
                   for s in e.by("ann"))]
    if len(hits) == 1:
        return "fn", hits[0][0], hits[0][1].ann_name
    if len(hits) > 1:
        raise Refused(f"{old}: defined at {len(hits)} VAs ({', '.join(f'{v:08X}' for v, _ in hits)}); rename by VA")
    hits = [va for va, e in reg.entries.items() if old in {s.name for s in e.by("define")}]
    if len(hits) == 1:
        return "global" if reg.entries[hits[0]].kind == "global" else "macro", hits[0], old
    if len(hits) > 1:
        raise Refused(f"{old}: #define'd for {len(hits)} VAs; rename by VA")
    raise Refused(f"{old}: no function or #define of that name in {reg.client}")


def plan_rename(repo, client: str, old: str, new: str, *, reg=None, in_va=None, comments=True,
                allow_existing=False, unify_defines=False, csv_rows=True, only_files=None,
                rename_fixture_files=False, views=True) -> Plan:
    repo = Path(repo).resolve()
    reg = reg or R.build(repo, client)
    if in_va is not None:
        return _plan_local(repo, client, reg, old, new, int(in_va, 16) if isinstance(in_va, str) else in_va,
                           comments, allow_existing)
    kind, va, old_q = resolve(reg, old)
    old_s = R.simple(old_q)
    if "::" in new:
        if "::" not in old_q or new.rsplit("::", 1)[0] != old_q.rsplit("::", 1)[0]:
            raise Refused(f"{new}: a qualified new name must keep the class of {old_q}")
        new_s = R.simple(new)
    else:
        new_s = new
    if not IDENT.fullmatch(new_s):
        raise Refused(f"{new}: not an identifier")
    new_q = (old_q.rsplit("::", 1)[0] + "::" + new_s) if "::" in old_q else new_s
    if new_s == old_s:
        raise Refused("new name = old name")
    plan = Plan(client, "fn" if kind == "fn" else "global", va, old_q, new_q)
    defs = all_define_names(repo, client, reg)
    e = reg.entries[va]

    names = {old_s: new_s}
    view = kind == "fn" and R.view_names(client)
    if kind == "fn":
        others = [v for v, x in reg.entries.items() if v != va and any(R.simple(s.name) == old_s for s in x.by("ann"))]
        if others and not view:
            raise Refused(f"{old_s} is also the name of {', '.join(f'{v:08X}' for v in others)}: ambiguous")
        kept = set()
        for s in e.by("define") + e.by("define_use"):
            if s.name in names or s.name in kept:
                continue
            nm = macro_style_new(s.name, old_s, new_s)
            elsewhere = [v for v, x in reg.entries.items() if v != va
                         and s.name in {y.name for y in x.by("define") + x.by("define_use")}]
            if nm and not elsewhere:
                plan.notes_macros.append((s.name, nm))
                names[s.name] = nm
            else:
                kept.add(s.name)
                why = (f"also #defined for {', '.join(f'{v:08X}' for v in elsewhere[:3])}" if nm
                       else f"not derived from {old_s}")
                plan.notes.append(f"kept #define {s.name} ({s.path}:{s.line}): {why}")
    else:
        targets = {old_s}
        if unify_defines:
            targets |= set(e.define_names)
        for t in sorted(targets - {old_s}):
            names[t] = new_s
            plan.notes_macros.append((t, new_s))
        other = [v for v, x in reg.entries.items() if v != va and old_s in {s.name for s in x.by("define")}]
        if other:
            plan.notes.append(f"{old_s} is also #defined for {', '.join(f'{v:08X}' for v in other)}: "
                              f"only files that define it for {va:08X} are changed")
    # refusals: macro shadowing / existing identifiers
    same_va = set()                             # another #define name of this same global: merging is fine
    if kind != "fn":
        for nm in set(names.values()):
            if {v for v, x in reg.entries.items()
                    if nm in {y.name for y in x.by("define") + x.by("define_use")}} <= {va}:
                same_va.add(nm)
    for nm in set(names.values()):
        if nm in defs and nm not in names and nm not in same_va:
            raise Refused(f"{nm} is already a #define name ({', '.join(defs[nm][:3])}): it would rewrite every use")
    if kind == "fn" and view and "::" in new_q:
        # Titanium member: views reuse member names across classes; only the same qualified name is a clash
        hit = [v for v, x in reg.entries.items() if v != va
               and any(s.name == new_q for s in x.by("ann") + x.by("external"))]
        if hit:
            raise Refused(f"{new_q} is already the name of {', '.join(f'{v:08X}' for v in hit[:3])}")
    elif kind == "fn":
        for nm in set(names.values()):
            if nm == new_s and any(R.simple(s.name) == new_s for x in reg.entries.values() for s in x.by("ann")):
                raise Refused(f"{new_s} is already the name of a function in {client}")

    # code files
    files = sorted(reg.files) if only_files is None else sorted(only_files)
    if kind != "fn":
        # a global macro: only files that define it for this VA, plus files that include such a header
        dfiles = {s.path for s in e.by("define") + e.by("define_use") if s.name in names}
        hdrs = {f for f in dfiles if f.endswith(".h")}
        files = [f for f in files if f in dfiles or (hdrs and _includes_any(reg.files.get(f, ""), hdrs))]
    ext_files = {s_.path for s_ in e.by("external")} if view else set()      # markers may spell a stale name
    view_aliases = set()                    # other names of the VA that files dropped for NEW (marker_spellings)
    veto = set()                            # member view names some file keeps: every file keeps them
    if view and views:
        tok = R.clients.get(client).token
        for rel in sorted(ext_files):
            if (repo / rel).is_file():
                marker_spellings(_read(repo, rel), va, old_s, new_s, tok, reg, rel, None, views, repo, veto)
    for rel in sorted(set(files) | (ext_files if only_files is None else set())):
        if rel in reg.files and rel not in ext_files and not any(n in reg.files[rel] for n in names):
            continue                        # cheap pre-filter: the name isn't even a substring
        raw = _read(repo, rel)
        marks, fnames = [], names
        if view:
            if not _view_file(reg, rel, raw, va, old_q, plan):
                continue
            tok = R.clients.get(client).token
            fnames = dict(names, **marker_spellings(raw, va, old_s, new_s, tok, reg, rel, plan, views, repo,
                                                    veto=veto))
            marks = external_edits(raw, va, old_q, new_q, tok, set(fnames) - set(names))
            view_aliases |= set(fnames) - set(names)
        spans = ident_spans(raw, set(fnames), comments)
        if marks:                           # the marker's name is edited as a whole (decorated too), with or
            spans = [x for x in spans       # without --no-comments
                     if not any(m[0] <= x[0] < m[1] for m in marks)]
        if not spans and not marks:
            continue
        if not allow_existing:
            have = code_idents(raw)
            for nm in set(names.values()):
                if have.get(nm):
                    raise Refused(f"{nm} already occurs in {rel} ({have[nm]}x); pick another name or --allow-existing")
        edits = [(s, en, fnames[w], line_of(raw, s), where) for s, en, w, where in spans]
        edits = drop_dup_comment_swaps(raw, edits, plan.notes) + marks
        new_text = apply_edits(raw, edits)
        before = set(define_clashes(raw))
        clash = [c for c in define_clashes(new_text) if c not in before]
        if clash:
            raise Refused(f"{rel}: the rename defines {', '.join(clash)} twice with different bodies (C4005)")
        plan.edits[rel] = edits
        plan.texts[rel] = new_text
    if kind == "fn":
        _plan_fixtures(repo, client, reg, plan, va, old_q, new_q, rename_fixture_files, view_aliases)
        _plan_queue(repo, client, plan, va, old_q, new_q)
        if csv_rows and R.clients.get(client).names:
            _plan_csv(repo, client, plan, va, old_q, new_q)
    if not plan.texts:
        raise Refused(f"{old}: nothing to change")
    return plan


# --- Titanium: views, EXTERNAL markers, decorated names --------------------------------------------------------

EXT_LINE = re.compile(r"^([ \t]*//[ \t]*EXTERNAL:[ \t]*(\w+)[ \t]+(0[xX][0-9a-fA-F]+)[ \t]+)(\S+)[ \t]*$", re.M)
# `?Name@Scope@...@@Tail`: a decorated function or member (not `??0` ctors, `??_7` tables and other specials)
MANGLED = re.compile(r"\?(?P<name>[A-Za-z_]\w*)@(?P<scope>(?:[A-Za-z_]\w*@)*)@(?P<tail>.*)", re.S)


def mangled_rename(sym: str, old_s: str, new_s: str, cls: str | None = None, va: int | None = None) -> str | None:
    """`?Old@Class@@QAEXXZ` -> `?New@Class@@QAEXXZ` (MSVC decoration) when the name part is `old_s` (or the stale
    `FUN_<va>` of `va`) and, with `cls`, the scope is that class (`A::B` is spelled `B@A@`); else None.
    Refused when the swap would be wrong: MSVC writes a name a second time as a back-reference digit, so a
    signature that spells NEW as a type, or refers back to OLD as a type (`U0@`), needs a real re-decoration."""
    m = MANGLED.fullmatch(sym)
    if not m:
        return None
    name = m.group("name")
    if name != old_s and not (va is not None and name.lower() in (f"fun_{va:08x}", f"fun_{va:08x}_guess")):
        return None
    if cls is not None:
        want = "".join(part + "@" for part in reversed(cls.split("::"))) if cls else ""
        if m.group("scope") != want:
            return None
    tail = m.group("tail")
    # NEW as a scope name, or as a struct/class/union/enum name in the signature (`PAUNew@@`, `W4New@@`)
    if new_s in m.group("scope").split("@") or re.search(r"(?:[UVT]|W4)" + re.escape(new_s) + "@", tail) or \
            re.search(r"(?:[UVT]|W4)0@", tail):
        raise Refused(f"{sym}: the decorated name needs a back-reference for {new_s or old_s}; rename by hand")
    return "?" + new_s + "@" + m.group("scope") + "@" + tail


def renamed_symbol(sym: str, va: int, old_q: str, new_q: str, also=()) -> str | None:
    """A name that stands for the function at `va` in some view, renamed: decorated (`?Old@AnyClass@@...`),
    qualified (`View::Old` keeps its view's class), plain (`Old`), or a stale `FUN_<va>`/`FUN_<va>_guess`;
    `also`: more simple names of the VA (a file's own view name, marker_spellings)."""
    old_s, new_s = R.simple(old_q), R.simple(new_q)
    if sym.startswith("?"):
        for o in (old_s, *also):
            nn = mangled_rename(sym, o, new_s, va=va)
            if nn:
                return nn
        return None
    head, _, last = sym.rpartition("::")
    if last == old_s or last in also or last.lower() in (f"fun_{va:08x}", f"fun_{va:08x}_guess"):
        return (head + "::" if head else "") + new_s
    return None


def external_edits(raw: str, va: int, old_q: str, new_q: str, token: str, also=()) -> list:
    """Edits renaming the `// EXTERNAL: <TOKEN> 0x<va> <name>` markers of `va` in `raw` (undecorated or
    decorated name; the marker keeps its own view's class; `also` as renamed_symbol)."""
    out = []
    for m in EXT_LINE.finditer(raw):
        if m.group(2).upper() != token or int(m.group(3), 16) != va:
            continue
        nn = renamed_symbol(m.group(4), va, old_q, new_q, also)
        if nn and nn != m.group(4):
            out.append((m.start(4), m.end(4), nn, line_of(raw, m.start(4)), "external"))
    return out


def marker_spellings(raw: str, va: int, old_s: str, new_s: str, token: str, reg=None, rel: str = "",
                     plan: Plan | None = None, views: bool = True, repo=None, kept: set | None = None,
                     veto=()) -> dict:
    """{name: new_s} for the other names this file's `// EXTERNAL:` markers give `va`, so the whole file follows:
    another spelling of the address name (`FUN_0042429e_guess` in a caller of `FUN_0042429E_guess`: the address's
    letter case differs, and so does the C++ identifier), and with `views` the file's own view name: a free
    function's (`ParseValue_guess` in tu_069 for 0x00408E74) unless the file gives that name to another VA too, and
    a member's (`View::Update_47CB5F_guess`: the member is renamed in its view class, which keeps its name) unless
    member_view_clash finds the old or the new name elsewhere in the file. Skipped view names are noted and, for a
    member, added to `kept`; a member name in `veto` (kept in another file) is kept here too, so every fixture and
    alias of that spelling stays consistent."""
    out = {}
    stale = (f"fun_{va:08x}", f"fun_{va:08x}_guess")
    here = collections.defaultdict(set)         # view class -> this VA's member names in this file
    for m in EXT_LINE.finditer(raw):
        if m.group(2).upper() == token and int(m.group(3), 16) == va:
            u = R.undecorate(m.group(4))
            if "::" in u and R.simple(u).lower() not in stale:
                here[u.rsplit("::", 1)[0]].add(R.simple(u))
    for m in EXT_LINE.finditer(raw):
        if m.group(2).upper() != token or int(m.group(3), 16) != va:
            continue
        full = R.undecorate(m.group(4))
        sn = R.simple(full)
        if sn == old_s or sn in out:
            continue
        if sn.lower() in stale:
            out[sn] = new_s
            continue
        if not views:
            continue
        cls_names = here.get(full.rsplit("::", 1)[0], set()) if "::" in full else set()
        if len(cls_names) > 1:
            # one VA under several member names of one view (ApplyTwo_guess/ApplyThree_guess, two signatures
            # of 0x0048083A in tu_046): one NEW would make them overloads, and a marker can't map an overload
            why = (f"its class gives the VA {len(cls_names)} names ({', '.join(sorted(cls_names))}): "
                   "they would become overloads")
            if plan is not None:
                plan.notes.append(f"kept view name {full} in {rel} ({why})")
            if kept is not None:
                kept.add(sn)
            continue
        why = ""
        if reg is not None:
            clash = [v for v, x in reg.entries.items() if v != va
                     and any(R.simple(R.undecorate(y.name)) == sn and y.path == rel for y in x.by("ann") + x.by("external"))]
            if clash or re.search(r"^[ \t]*#[ \t]*define[ \t]+%s\b" % re.escape(sn), raw, re.M):
                why = "the file uses that name for something else too"
        if not why and "::" in full:
            if rel.lower().endswith((".h", ".hpp", ".inl")):
                why = "a member view in a header"
            else:
                why = member_view_clash(raw, full.rsplit("::", 1)[0], sn, new_s,
                                        _all_header_ids(repo, rel) if repo is not None else set())
                if not why and m.group(4).startswith("?"):
                    try:
                        mangled_rename(m.group(4), sn, new_s)
                    except Refused as e:
                        why = str(e)
            if not why and sn in veto:
                why = "a member view name kept in another file"
            if why and kept is not None:
                kept.add(sn)
        if why:
            if plan is not None:
                plan.notes.append(f"kept view name {full} in {rel} ({why})")
            continue
        out[sn] = new_s
    return out


def _all_header_ids(repo, rel: str) -> set:
    """Every identifier (code and #define lines) of the headers `rel` includes with quotes, transitively."""
    out, seen = set(), set()
    todo = [Path(repo) / rel]
    while todo:
        path = todo.pop()
        try:
            txt = path.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        if path != Path(repo) / rel:
            out |= set(code_idents(txt))
        for name in re.findall(r'^\s*#\s*include\s+"([^"]+)"', txt, re.M):
            for b in (path.parent, Path(repo) / "include"):
                h = (b / name).resolve()
                if h.is_file():
                    if h not in seen:
                        seen.add(h)
                        todo.append(h)
                    break
    return out


_STRUCT_KW = {"struct", "class", "union"}


def _block_owner(stmt: list, stack: list):
    """(kind, class) of a `{` block whose head is the tokens `stmt`: a struct/class body (its name), a function body
    (`Cls::f(...)`: Cls; a free function inherits the enclosing owner) or any other block (inherits)."""
    inherit = stack[-1][1] if stack else None
    for i, w in enumerate(stmt):
        if w in _STRUCT_KW:
            j = i + 1
            while j < len(stmt) and stmt[j] == "__declspec":
                j = stmt.index(")", j) + 1 if ")" in stmt[j:] else len(stmt)
            if "(" in stmt[j:]:
                break                           # `struct X* f(...)`: a function returning a struct
            return ("struct", stmt[j] if j < len(stmt) and IDENT.fullmatch(stmt[j]) else "?")
    paren = stmt.index("(") if "(" in stmt else len(stmt)
    if paren < len(stmt):
        for k in range(paren - 1, 0, -1):
            if stmt[k] == "::":
                return ("func", stmt[k - 1])
        return ("func", inherit)
    return ("block", inherit)


def member_view_clash(raw: str, view_cls: str, sn: str, new_s: str, header_ids=()) -> str:
    """Why this file's member view `view_cls::sn` can't be renamed to `new_s` by a token swap of `sn` (empty when
    it can): `new_s` already occurs in the file or a header it includes (another member of the view, or any other
    name: a token swap would merge them); or `sn` means something other than the view's member somewhere in the
    file: declared in another class body, qualified by another class, used unqualified outside the view's own
    bodies and member functions, spelled in a preprocessor line, or declared in an included header."""
    cls = view_cls.split("::")[-1]
    if code_idents(raw).get(new_s) or new_s in header_ids:
        return f"{new_s} is already used in the file or its headers"
    if sn in header_ids:
        return f"{sn} is also spelled in a header it includes"
    toks = [t for t in ct.tokenize(raw) if t.kind not in ("ws", "comment")]
    stack, stmt = [], []
    pp = re.compile(r"\b%s\b" % re.escape(sn))
    for i, t in enumerate(toks):
        if t.kind == "pp":
            if pp.search(t.text):
                return f"{sn} is used in a preprocessor line"
            continue
        if t.kind == "id" and t.text == sn:
            prev = toks[i - 1].text if i else ""
            if prev == "::":
                q = toks[i - 2].text if i >= 2 else ""
                if q != cls:
                    return f"{q}::{sn} names another class's member"
            elif prev not in (".", "->"):
                if stack and stack[-1][0] == "struct":
                    if stack[-1][1] != cls:
                        return f"{stack[-1][1]} declares {sn} too"
                elif not stack or stack[-1][1] != cls:
                    return f"{sn} is used unqualified outside {cls}"
        if t.kind == "op" and t.text == "{":
            stack.append(_block_owner(stmt, stack))
            stmt = []
        elif t.kind == "op" and t.text == "}":
            if stack:
                stack.pop()
            stmt = []
        elif t.kind == "op" and t.text == ";":
            stmt = []
        else:
            stmt.append(t.text)
    return ""


def _view_file(reg, rel: str, raw: str, va: int, old_q: str, plan: Plan) -> bool:
    """Titanium: does `rel`'s use of OLD's simple name mean the function at `va`? Yes when the file defines it,
    marks it `// EXTERNAL:` or names its VA in an EQ_* macro; no (noted) when the file's definitions/markers give
    that name to another VA only; refused when both. Otherwise yes for a member if the file names its class, and
    for a free function if no other VA has the name (its callers link by the decorated name)."""
    old_s = R.simple(old_q)
    mine, other = False, set()
    for v, e in reg.entries.items():
        for s_ in e.by("ann") + e.by("external"):
            if s_.path == rel:
                if v == va:
                    mine = True
                elif R.simple(s_.name) == old_s or R.simple(R.undecorate(s_.name)) == old_s:
                    other.add(v)
    if not mine:
        mine = any(int(tok, 16) == va for _k, tok, *_ in R.scan_macros(raw))
    if mine and other:
        raise Refused(f"{rel}: {old_s} names {va:08X} and {', '.join(f'{v:08X}' for v in sorted(other))} here "
                      "(two views in one file); rename by hand")
    if other:
        plan.notes.append(f"kept {rel}: its {old_s} is {', '.join(f'{v:08X}' for v in sorted(other))}")
        return False
    if mine:
        return True
    have = code_idents(raw)
    if "::" in old_q:
        cls = old_q.rsplit("::", 1)[0].split("::")[-1]
        if not have.get(cls):
            plan.notes.append(f"kept {rel}: {old_s} there is not a member of {cls}")
            return False
        return True
    users = [v for v, e in reg.entries.items() if v != va
             and any(R.simple(s_.name) == old_s for s_ in e.by("ann") + e.by("external"))]
    if users:
        raise Refused(f"{rel}: calls {old_s} with no marker, and {', '.join(f'{v:08X}' for v in users[:3])} "
                      "has that name too: add an // EXTERNAL: marker or rename by hand")
    return True


def _includes_any(text: str, hdrs: set) -> bool:
    inc = re.findall(r'^\s*#\s*include\s+"([^"]+)"', text, re.M)
    return any(h.endswith("/" + i.split("/")[-1]) or h.endswith(i) for i in inc for h in hdrs)


def file_scope_idents(text: str) -> set:
    """Names a header puts in file scope: identifiers outside every brace block (types, prototypes, globals,
    #define names and bodies) plus enum constants; struct/class fields and member prototypes are left out
    (a local may share a field's name; inside a member function the gate catches the shadowing)."""
    out = set()
    depth, enum_depth, prev = 0, None, []
    for t in ct.tokenize(text):
        if t.kind == "pp":
            ids = {m.group() for m in _PP_TOKEN.finditer(t.text) if m.lastgroup == "id"}
            fm = re.match(r"#\s*define\s+\w+\(([^)]*)\)", t.text)      # a macro's parameters are not file scope
            out |= ids - (set(re.findall(r"[A-Za-z_]\w*", fm.group(1))) if fm else set())
        elif t.kind == "op" and t.text == "{":
            depth += 1
            if enum_depth is None and "enum" in prev[-4:]:
                enum_depth = depth
        elif t.kind == "op" and t.text == "}":
            if enum_depth == depth:
                enum_depth = None
            depth = max(0, depth - 1)
        elif t.kind == "id" and (depth == 0 or enum_depth == depth):
            out.add(t.text)
        if t.kind not in ("ws", "comment"):
            prev = (prev + [t.text])[-6:]
    return out


def header_idents(repo: Path, path: Path, seen=None) -> set:
    """File-scope names of the headers `path` includes with quotes, transitively (its dir, then
    <repo>/include)."""
    seen = set() if seen is None else seen
    out = set()
    try:
        txt = path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return out
    for name in re.findall(r'^\s*#\s*include\s+"([^"]+)"', txt, re.M):
        for b in (path.parent, repo / "include"):
            h = (b / name).resolve()
            if h.is_file():
                if h not in seen:
                    seen.add(h)
                    out |= file_scope_idents(h.read_text(encoding="utf-8", errors="replace"))
                    out |= header_idents(repo, h, seen)
                break
    return out


def _cached_headers(cache: dict, repo: Path, rel: str) -> set:
    if ("hdr", rel) not in cache:
        cache[("hdr", rel)] = header_idents(repo, repo / rel)
    return cache[("hdr", rel)]


def _plan_local(repo, client, reg, old, new, va, comments, allow_existing) -> Plan:
    if not IDENT.fullmatch(new) or not IDENT.fullmatch(old):
        raise Refused("local renames take plain identifiers")
    e = reg.entries.get(va)
    if not e or not e.by("ann"):
        raise Refused(f"{va:08X}: no annotated function in {client}")
    a = e.by("ann")[0]
    raw = _read(repo, a.path)
    fns = tu.find_functions(raw)
    lines = raw.split("\n")
    ann_off = sum(len(x) + 1 for x in lines[:a.line - 1])
    f = next((f for f in fns if f.start > ann_off), None)
    if f is None:
        raise Refused(f"{va:08X}: function body not found in {a.path}")
    # local renames leave defines, headers and function names alone, so a --map run reuses these per registry
    cache = reg.__dict__.setdefault("_local_cache", {})
    if "defs" not in cache:
        cache["defs"] = all_define_names(repo, client, reg)
        cache["fn_names"] = {R.simple(s.name) for x in reg.entries.values() for s in x.by("ann")}
    defs = cache["defs"]
    if new in defs:
        raise Refused(f"{new} is a #define name ({', '.join(defs[new][:3])})")
    # a function-like macro of the file can name the local (`#define CCI_ROLL_STATS() ... roll ...`, expanded in
    # the body): renaming the local would leave the macro pointing at nothing (or at the new name's owner)
    for t in ct.tokenize(raw):
        if t.kind == "pp" and re.match(r"#\s*define\b", t.text):
            m = re.match(r"#\s*define\s+(\w+)", t.text)
            rest = R.blank_comments(t.text[m.end():] if m else "")
            pm = re.match(r"\(([^)]*)\)", rest)          # function-like: its parameters are bound names
            params = set(re.findall(r"[A-Za-z_]\w*", pm.group(1))) if pm else set()
            words = set(re.findall(r"[A-Za-z_]\w*", rest[pm.end():] if pm else rest)) - params
            for nm in (old, new):
                if nm in words:
                    raise Refused(f"{nm} is named inside #define {m.group(1) if m else '?'} (line {line_of(raw, t.start)}):"
                                  " the macro uses it, rename by hand together with the macro")
    body = raw[f.start:f.body_end]
    have = code_idents(body)
    if not have.get(old):
        raise Refused(f"{old} does not occur in {a.name}")
    if code_idents(body, skip_members=True).get(new) and not allow_existing:
        raise Refused(f"{new} already occurs in {a.name}")
    # a file-scope name of that spelling (outside every function body: globals, types, prototypes, #defines,
    # enum constants) or a function of the client: refuse, the new local would shadow it. Struct fields don't
    # count (a local may share a field's name; inside a member function the gate catches any shadowing), nor
    # do other functions' locals.
    scope, pos = [], 0
    for g in fns:
        scope.append(raw[pos:g.start])
        pos = g.body_end
    scope.append(raw[pos:])
    if not allow_existing and (new in file_scope_idents("".join(scope)) or new in {g.simple for g in fns}
                               or new in _cached_headers(cache, repo, a.path)
                               or new in cache["fn_names"]):
        raise Refused(f"{new} is also a file-scope name or a function in {client} (would be shadowed)")
    spans = ident_spans(raw, {old}, comments, f.lead if comments else f.start, f.body_end)
    spans = [s for s in spans if s[3] != "comment" or s[0] >= f.lead]
    members = member_starts(raw[:f.body_end])
    spans = [s for s in spans if not (s[3] == "code" and s[0] in members)]      # `->old` / `.old` is a member, not the local
    plan = Plan(client, "local", va, old, new)
    edits = [(s, en, new, line_of(raw, s), where) for s, en, w, where in spans]
    edits = drop_dup_comment_swaps(raw, edits, plan.notes)
    plan.edits[a.path] = edits
    plan.texts[a.path] = apply_edits(raw, edits)
    return plan


def _json_str(s: str) -> str:
    return json.dumps(s)[1:-1]


ALIAS_KEY = re.compile(r"(?P<pre>[?_@]?)(?P<name>[A-Za-z_]\w*)(?P<post>@.*)?")


# C runtime / library symbols the test DLLs link (and registry names that equal them, e.g. strcpy 005219C0): a
# rewrite_aliases key of this name is the DLL's own CRT symbol, which a source rename does not change (review
# #8). Compared without leading underscores, case-insensitively.
CRT_NAMES = frozenset(n.lower() for n in (
    "EH_prolog", "ftol", "chkstk", "alloca_probe", "purecall", "CIacos", "CIasin", "CIatan", "CIatan2", "CIcos",
    "CIexp", "CIfmod", "CIlog", "CIlog10", "CIpow", "CIsin", "CIsqrt", "CItan", "allmul", "alldiv", "allrem",
    "aulldiv", "aullrem", "allshl", "allshr", "aullshr", "strcpy", "strncpy", "strcat", "strncat", "strcmp",
    "strncmp", "stricmp", "strcmpi", "strnicmp", "strlen", "strchr", "strrchr", "strstr", "strspn", "strcspn",
    "strpbrk", "strtok", "strdup", "strlwr", "strupr", "strrev", "strtol", "strtoul", "strtod", "memcpy",
    "memmove", "memset", "memcmp", "memchr", "malloc", "calloc", "realloc", "free", "msize", "new", "delete",
    "sprintf", "vsprintf", "snprintf", "vsnprintf", "printf", "vprintf", "fprintf", "vfprintf", "sscanf",
    "scanf", "fscanf", "atoi", "atol", "atof", "itoa", "ltoa", "ultoa", "fopen", "fclose", "fread", "fwrite",
    "fseek", "ftell", "fgets", "fputs", "fgetc", "fputc", "fflush", "feof", "rewind", "remove", "rename",
    "exit", "abort", "atexit", "time", "ctime", "localtime", "gmtime", "mktime", "clock", "rand", "srand",
    "qsort", "bsearch", "abs", "labs", "toupper", "tolower", "isalpha", "isdigit", "isspace", "isalnum",
    "isupper", "islower", "sqrt", "sin", "cos", "tan", "atan", "atan2", "pow", "exp", "log", "log10", "floor",
    "ceil", "fabs", "fmod", "getenv", "beginthread", "beginthreadex", "endthread", "endthreadex", "access",
    "open", "close", "read", "write", "lseek", "stat", "findfirst", "findnext", "findclose", "mkdir", "getcwd",
    "chdir", "splitpath", "makepath", "fullpath", "except_handler3", "local_unwind2", "global_unwind2",
    "CxxThrowException", "CxxFrameHandler", "setjmp", "longjmp", "setjmp3", "initterm", "onexit", "cinit",
    "DllMainCRTStartup", "CRT_INIT"))


def _va_of(value) -> int | None:
    """A rewrite_aliases value as a VA, or None when it is not one."""
    if isinstance(value, str) and re.fullmatch(r"0[xX][0-9a-fA-F]+", value.strip()):
        return int(value, 16)
    return None


def is_crt_name(name: str) -> bool:
    return name.lstrip("_").lower() in CRT_NAMES


def alias_new_key(key: str, va: int, old_q: str, new_q: str, value=None) -> str | None:
    """A fixture's rewrite_aliases key is a test-DLL symbol of a rewritten function: `name`, `_name`, `_name@8`,
    `@name@8`, `?name@@YAXH@Z` or `?name@Class@@QAEXXZ`; its value is the client VA its calls go to. The key
    follows the rename when its name part is the old simple name, or the stale `FUN_<va>` of the renamed VA (
    10 such keys fixed by hand), in the same scope: a mangled key carries the class (`@Class@@`, nested classes
    innermost first), a C-decorated key only stands for a free function, or for a method's flattened free form
    `Class_Method` (review #8). When `value` is a VA it must be `va` too (review #8: a key of the same
    name for another VA, such as a CRT symbol, is not this function). Returns the new key, or None."""
    m = ALIAS_KEY.fullmatch(key)
    if not m:
        return None
    vv = _va_of(value)
    if vv is not None and vv != va:
        return None
    old_s, new_s = R.simple(old_q), R.simple(new_q)
    cls = old_q.rsplit("::", 1)[0] if "::" in old_q else ""
    flat = [(old_q.replace("::", "_"), new_q.replace("::", "_"))] if cls and "::" in new_q else []
    pre, name, post = m.group("pre"), m.group("name"), m.group("post") or ""
    cands = [(pre, name)] + ([("", pre + name)] if pre == "_" else [])     # `_x`: `_` + x, or a name `_x`
    for p, n in cands:
        for o, nw, c in [(old_s, new_s, cls)] + [(fo, fn, "") for fo, fn in flat]:
            if n != o and not (c == cls and n.lower() == f"fun_{va:08x}"):
                continue
            if p == "?":
                scope = ("@" + "@".join(reversed(c.split("::"))) + "@@") if c else "@@"
                if not post.startswith(scope):
                    continue
            elif c or (post and not re.fullmatch(r"@\d+", post)):
                continue                               # a method has no C-decorated symbol
            return p + nw + post
    return None


def _alias_edits(raw: str, d: dict, va: int, old_q: str, new_q: str, rel: str) -> list:
    """Edits renaming the rewrite_aliases keys of fixture `d` (text `raw`) that stand for the renamed function."""
    al = d.get("rewrite_aliases")
    if not isinstance(al, dict) or not al:
        return []
    new = {k: nk for k, v in al.items() for nk in [alias_new_key(k, va, old_q, new_q, v)] if nk and nk != k}
    if not new:
        return []
    for k, nk in new.items():
        km = ALIAS_KEY.fullmatch(k)
        if km and is_crt_name(km.group("name")) and _va_of(al[k]) != va:
            # review #8: a CRT name's key is the DLL's own CRT symbol; only a value naming this VA says otherwise
            raise Refused(f"{rel}: rewrite_aliases key {k} is a C runtime name and its value {al[k]!r} is not "
                          f"0x{va:08X}")
        if nk in al and nk not in new:
            raise Refused(f"{rel}: rewrite_aliases has both {k} and {nk}")
        twins = sorted(k2 for k2, n2 in new.items() if n2 == nk)
        if len(twins) > 1:
            raise Refused(f"{rel}: rewrite_aliases keys {', '.join(twins)} would all become {nk}")
    m = re.search(r'"rewrite_aliases"\s*:\s*\{', raw)
    end = raw.find("}", m.end()) if m else -1
    if end < 0:
        raise Refused(f"{rel}: rewrite_aliases not found in the text")
    out = []
    for k, nk in new.items():
        km = re.compile(r'"%s"(?=\s*:)' % re.escape(_json_str(k))).search(raw, m.end(), end)
        if not km:
            raise Refused(f"{rel}: rewrite_aliases key {k} not found in the text")
        out.append((km.start(), km.end(), f'"{_json_str(nk)}"', line_of(raw, km.start()), "alias"))
    want = {new.get(k, k): v for k, v in al.items()}
    if json.loads(apply_edits(raw, out)).get("rewrite_aliases") != want:
        raise Refused(f"{rel}: rewrite_aliases edit did not give the expected keys")
    return out


def _plan_fixtures(repo, client, reg, plan, va, old_q, new_q, rename_files=False, also=()):
    c = R.clients.get(client)
    tdir = c.tests_dir(repo)
    old_s, new_s = R.simple(old_q), R.simple(new_q)
    olds = {old_q, old_s, old_q.replace("::", "_")}
    if R.view_names(c):
        return _plan_fixtures_by_va(repo, client, plan, va, old_q, new_q, rename_files, also)
    for f in sorted(tdir.rglob("*.json")) if tdir.is_dir() else []:
        rel = f.relative_to(repo).as_posix()
        if not R.clients.owns(client, rel):
            continue
        raw = _read(repo, rel)
        vtag = (f'"0x{va:08x}"', f'"0x{va:x}"')                # a fixture of this VA: its "function" follows the
        if not any(o in raw for o in olds) and not any(t in raw.lower() for t in vtag) \
                and f"fun_{va:08x}" not in raw.lower():    # rename even when stale ("function", alias keys)
            continue
        try:
            d = json.loads(raw)
        except ValueError:
            continue
        if not isinstance(d, dict):
            continue
        edits = []
        own = str(d.get("original", "")).lower() in (f"0x{va:08x}", f"0x{va:x}")
        if own:
            for key in ("function", "rewrite"):
                v = d.get(key)
                stale = key == "function" and isinstance(v, str) and v not in olds and v not in (new_q, new_s)
                if v in olds or stale:
                    # a stale "function" (it named the VA before an earlier rename that missed it) takes the new
                    # name in the same form: qualified when it was qualified (two gate LINT stops)
                    nv = (new_q if "::" in v else new_s) if stale else                         new_q if v == old_q else new_s if v == old_s else new_q.replace("::", "_")
                    for m in re.finditer(r'("%s"\s*:\s*)"%s"' % (key, re.escape(_json_str(v))), raw):
                        edits.append((m.start(), m.end(), f'{m.group(1)}"{_json_str(nv)}"', line_of(raw, m.start()),
                                      key))
        for k, v in (d.get("callees") or {}).items():
            try:
                kva = int(k, 16)
            except ValueError:
                continue
            if kva == va and isinstance(v, dict) and v.get("name") in olds:
                m = re.search(r'"%s"\s*:\s*\{' % re.escape(k), raw)
                if m:
                    n = re.compile(r'("name"\s*:\s*)"%s"' % re.escape(_json_str(v["name"]))).search(raw, m.end())
                    if n:
                        nv = new_q if v["name"] == old_q else new_s
                        edits.append((n.start(), n.end(), f'{n.group(1)}"{_json_str(nv)}"', line_of(raw, n.start()),
                                      "callee"))
        edits += _alias_edits(raw, d, va, old_q, new_q, rel)
        if not edits:
            continue
        new_text = apply_edits(raw, edits)
        json.loads(new_text)
        plan.edits[rel] = edits
        plan.texts[rel] = new_text
        if rename_files and own and f.stem in (old_s, old_q.replace("::", "_")):
            nf = f.with_name(f.name.replace(f.stem, new_s if f.stem == old_s else new_q.replace("::", "_"), 1))
            if not nf.exists():
                plan.renamed_files.append((rel, nf.relative_to(repo).as_posix()))


def _plan_fixtures_by_va(repo, client, plan, va, old_q, new_q, rename_files=False, also=()):
    """Titanium fixtures, matched by VA: the VA's own fixtures' "function" and "rewrite" (plain, qualified or
    decorated, also when stale), `callees[VA].name` in every fixture (each view keeps its class), and
    `rewrite_aliases` keys whose value is the VA (any view's decorated name or `_Old`). A key with no VA value
    follows only when it is the old name in the old class (alias_new_key). `also`: view names the sources dropped
    for NEW (their aliases and labels follow too). Also tests/unicorn/crt_defaults.json."""
    c = R.clients.get(client)
    tdir = c.tests_dir(repo)
    old_s, new_s = R.simple(old_q), R.simple(new_q)
    vtags = (f"0x{va:08x}", f"0x{va:x}")
    for f in sorted(tdir.rglob("*.json")) if tdir.is_dir() else []:
        rel = f.relative_to(repo).as_posix()
        if not R.clients.owns(client, rel):
            continue
        raw = _read(repo, rel)
        low = raw.lower()
        if not any(t in low for t in vtags) and old_s not in raw and not any(x in raw for x in also):
            continue
        try:
            d = json.loads(raw)
        except ValueError:
            continue
        if not isinstance(d, dict):
            continue
        edits = []
        own = str(d.get("original", "")).lower() in vtags
        for key in ("function", "rewrite") if own else ():
            v = d.get(key)
            if not isinstance(v, str) or not v:
                continue
            nv = renamed_symbol(v, va, old_q, new_q, also)
            if nv is None and key == "function" and not v.startswith("?"):
                nv = new_q if "::" in v else new_s          # a stale label of this VA takes the new name
            if nv and nv != v:
                for m in re.finditer(r'("%s"\s*:\s*)"%s"' % (key, re.escape(_json_str(v))), raw):
                    edits.append((m.start(), m.end(), f'{m.group(1)}"{_json_str(nv)}"', line_of(raw, m.start()), key))
        for k, v in (d.get("callees") or {}).items():
            try:
                kva = int(k, 16)
            except ValueError:
                continue
            if kva != va or not isinstance(v, dict) or not isinstance(v.get("name"), str):
                continue
            nv = renamed_symbol(v["name"], va, old_q, new_q, also)
            m = re.search(r'"%s"\s*:\s*\{' % re.escape(k), raw)
            if nv and nv != v["name"] and m:
                n = re.compile(r'("name"\s*:\s*)"%s"' % re.escape(_json_str(v["name"]))).search(raw, m.end())
                if n:
                    edits.append((n.start(), n.end(), f'{n.group(1)}"{_json_str(nv)}"', line_of(raw, n.start()),
                                  "callee"))
        edits += _alias_edits_by_va(raw, d, va, old_q, new_q, rel, also)
        if not edits:
            continue
        new_text = apply_edits(raw, edits)
        json.loads(new_text)
        plan.edits[rel] = edits
        plan.texts[rel] = new_text
        stems = {old_s, re.sub(r"_guess$", "", old_s)}
        if rename_files and own and f.stem in stems:
            nf = f.with_name(re.sub(r"_guess$", "", new_s) + f.suffix)
            if not nf.exists():
                plan.renamed_files.append((rel, nf.relative_to(repo).as_posix()))


def _alias_edits_by_va(raw: str, d: dict, va: int, old_q: str, new_q: str, rel: str, also=()) -> list:
    """rewrite_aliases edits for Titanium: a key whose value is `va` follows in whatever view it names the
    function (`?Old@View@@...`, `_Old`, `@Old@8`); a key with no VA value only as alias_new_key says."""
    al = d.get("rewrite_aliases")
    if not isinstance(al, dict) or not al:
        return []
    old_s, new_s = R.simple(old_q), R.simple(new_q)
    new = {}
    for k, v in al.items():
        if _va_of(v) == va:
            if k.startswith("?"):
                nk = renamed_symbol(k, va, old_q, new_q, also)
            else:
                km = ALIAS_KEY.fullmatch(k)
                nk = None
                if km and km.group("pre") != "?" and (km.group("name") in {old_s, *also} or km.group("name").lower()
                                                      in (f"fun_{va:08x}", f"fun_{va:08x}_guess")):
                    nk = km.group("pre") + new_s + (km.group("post") or "")
        else:
            nk = alias_new_key(k, va, old_q, new_q, v)
        if nk and nk != k:
            new[k] = nk
    if not new:
        return []
    for k, nk in new.items():
        if nk in al and nk not in new:
            raise Refused(f"{rel}: rewrite_aliases has both {k} and {nk}")
        if sum(1 for x in new.values() if x == nk) > 1:
            raise Refused(f"{rel}: two rewrite_aliases keys would both become {nk}")
    m = re.search(r'"rewrite_aliases"\s*:\s*\{', raw)
    end = raw.find("}", m.end()) if m else -1
    if end < 0:
        raise Refused(f"{rel}: rewrite_aliases not found in the text")
    out = []
    for k, nk in new.items():
        km = re.compile(r'"%s"(?=\s*:)' % re.escape(_json_str(k))).search(raw, m.end(), end)
        if not km:
            raise Refused(f"{rel}: rewrite_aliases key {k} not found in the text")
        out.append((km.start(), km.end(), f'"{_json_str(nk)}"', line_of(raw, km.start()), "alias"))
    if json.loads(apply_edits(raw, out)).get("rewrite_aliases") != {new.get(k, k): v for k, v in al.items()}:
        raise Refused(f"{rel}: rewrite_aliases edit did not give the expected keys")
    return out


def _plan_queue(repo, client, plan, va, old_q, new_q):
    rel = R.clients.get(client).queue
    p = repo / rel
    if not p.is_file():
        return
    raw = _read(repo, rel)
    pos = 0
    edits = []
    for line in raw.splitlines(True):
        if f'"{va:08X}"' in line or f'"{va:08x}"' in line:
            d = json.loads(line)
            if int(d["address"], 16) == va and d.get("name") != new_q:
                m = re.search(r'("name"\s*:\s*)"%s"' % re.escape(_json_str(d.get("name") or "")), line)
                if m:
                    edits.append((pos + m.start(), pos + m.end(), f'{m.group(1)}"{_json_str(new_q)}"',
                                  line_of(raw, pos), "queue"))
        pos += len(line)
    if edits:
        plan.edits[rel] = edits
        plan.texts[rel] = apply_edits(raw, edits)


def csv_row(va: int, name: str, note: str) -> dict:
    guess = name.endswith("_guess")
    return {"address": f"{va:08X}", "name": name[:-len("_guess")] if guess else name,
            "confidence": "low" if guess else "certain", "source": "manual", "note": note, "from_address": "",
            "file": ""}


def _csv_line(row: dict, cols) -> str:
    b = io.StringIO()
    csv.writer(b, lineterminator="\n").writerow([row.get(c, "") for c in cols])
    return b.getvalue()


def _plan_csv(repo, client, plan, va, old_q, new_q):
    c = R.clients.get(client)
    rel = f"names/{c.names}.manual.csv"
    p = repo / rel
    raw = _read(repo, rel) if p.is_file() else ",".join(CSV_COLS) + "\n"
    lines = raw.splitlines(True)
    cols = next(csv.reader([lines[0]]))
    out, done = [], False
    for ln in lines:
        r = next(csv.reader([ln]), None)
        if r and not done and _va(r[0]) == va:
            row = dict(zip(cols, r))
            new = csv_row(va, new_q, row.get("note", ""))
            row.update({"name": new["name"], "confidence": new["confidence"]})
            if f"was {old_q}" not in row.get("note", ""):
                row["note"] = (row.get("note", "") + f" (rename.py: was {old_q})").strip()
            out.append(_csv_line(row, cols))
            done = True
        else:
            out.append(ln)
    if not done:
        if out and not out[-1].endswith("\n"):
            out[-1] += "\n"
        out.append(_csv_line(csv_row(va, new_q, f"rename.py: was {old_q}"), cols))
    new_text = "".join(out)
    plan.edits[rel] = [(0, len(raw), "", 0, "csv")]
    plan.texts[rel] = new_text


def _va(s: str):
    try:
        return int(s, 16)
    except ValueError:
        return None


# --- apply ----------------------------------------------------------------------------------------------------

def write_plan(repo, plan: Plan, journal=None, txn=None):
    """Write the plan's files (through `txn`, a match_gate.Txn undo log, when given) and its journal lines."""
    repo = Path(repo)
    for rel, text in plan.texts.items():
        if txn is not None:
            txn.write(rel, text)
            continue
        with open(repo / rel, "w", encoding="utf-8", newline="") as f:
            f.write(text)
    for o, n in plan.renamed_files:
        if txn is not None:
            txn.rename(o, n)
        else:
            (repo / o).rename(repo / n)
    if journal:
        write_journal(journal, [plan])


def write_journal(journal, plans):
    with open(journal, "a", encoding="utf-8") as f:
        for plan in plans:
            for j in plan.journal():
                f.write(json.dumps(j) + "\n")


def describe(plan: Plan, verbose=True) -> str:
    out = [f"{plan.client} {plan.kind} {plan.va:08X} {plan.old} -> {plan.new}" if plan.va is not None
           else f"{plan.client} {plan.kind} {plan.old} -> {plan.new}"]
    for rel, edits in sorted(plan.edits.items()):
        kinds = collections.Counter(e[4] for e in edits)
        out.append(f"  {rel}: " + ", ".join(f"{k} {v}" for k, v in sorted(kinds.items())))
        if verbose and not rel.endswith(".csv"):
            for s, e, new, line, where in sorted(edits)[:200]:
                out.append(f"    {line}: {where} -> {new}")
    for o, n in plan.renamed_files:
        out.append(f"  rename file {o} -> {n}")
    for o, n in plan.notes_macros:
        out.append(f"  macro {o} -> {n}")
    for n in plan.notes:
        out.append(f"  note: {n}")
    return "\n".join(out)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("old", nargs="?")
    ap.add_argument("new", nargs="?")
    ap.add_argument("--repo", default=".")
    ap.add_argument("-c", "--client", required=True, choices=R.ALL_CLIENT_IDS)
    ap.add_argument("--in", dest="in_va", help="local/parameter/label rename inside the function at this VA")
    ap.add_argument("--map", help="JSON list of {old, new[, in]} (or {old: new}) applied in order")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--no-comments", action="store_true", help="leave comments alone")
    ap.add_argument("--no-csv", action="store_true", help="don't add/update the names/*.manual.csv row")
    ap.add_argument("--allow-existing", action="store_true",
                    help="allow NEW where it already occurs as an identifier (never a #define name)")
    ap.add_argument("--rename-fixture-files", action="store_true",
                    help="also rename the function's fixture file when it is named after the old name")
    ap.add_argument("--unify-defines", action="store_true", help="global: give the VA's other #defines NEW too")
    ap.add_argument("--journal", help="append the renames (JSON lines) here, for gate.py --renames")
    ap.add_argument("--keep-views", action="store_true",
                    help="titanium: leave other TUs' own names of the function (their EXTERNAL view names) alone")
    ap.add_argument("--gate", action="store_true",
                    help="compare --match before/after + fixtures (match_gate.py); restore everything on a failure")
    ap.add_argument("--fixtures", choices=["renamed", "tu", "none"], default="renamed",
                    help="--gate: which fixtures to run (default: the renamed VAs' own and their callers')")
    ap.add_argument("--gate-json", help="--gate: write the verdict(s) here")
    ap.add_argument("--gate-cache", help="--gate: work folder (default <build>/readability/titanium)")
    ap.add_argument("-q", "--quiet", action="store_true")
    a = ap.parse_args(argv)
    repo = Path(a.repo).resolve()
    if a.map:
        m = json.loads(Path(a.map).read_text(encoding="utf-8"))
        items = [{"old": k, "new": v} for k, v in m.items()] if isinstance(m, dict) else m
    elif a.old and a.new:
        items = [{"old": a.old, "new": a.new, "in": a.in_va}]
    else:
        ap.error("OLD NEW or --map")
    opts = dict(comments=not a.no_comments, allow_existing=a.allow_existing, unify_defines=a.unify_defines,
                csv_rows=not a.no_csv, rename_fixture_files=a.rename_fixture_files, views=not a.keep_views)
    if a.gate and not a.dry_run:
        return gated(repo, a, items, opts)
    rc, _done = apply_items(repo, a.client, items, opts, dry_run=a.dry_run, journal=a.journal, quiet=a.quiet)
    return rc


def apply_items(repo, client, items, opts, dry_run=False, journal=None, quiet=False, txn=None):
    """Plan and write `items` in order (the registry is rebuilt after a function or global rename).
    -> (rc, [(item, plan)] written); rc 2 when one was refused."""
    reg = None
    rc, done = 0, []
    for it in items:
        try:
            reg = reg or R.build(repo, client)
            plan = plan_rename(repo, client, it["old"], it["new"], reg=reg, in_va=it.get("in"), **opts)
        except Refused as e:
            print(f"REFUSED {it['old']} -> {it['new']}: {e}")
            rc = 2
            continue
        print(describe(plan, verbose=not quiet))
        if not dry_run:
            write_plan(repo, plan, journal, txn)
            done.append((it, plan))
            if plan.kind == "local":        # one function body changed: keep the registry, refresh that text
                for rel, text in plan.texts.items():
                    reg.files[rel] = text
            else:
                reg = None                  # files changed: rescan before the next rename
    return rc, done


def gated(repo, a, items, opts) -> int:
    """--gate: apply the whole map, gate it once (match_gate.gate_txn); on a failure restore every file and, for
    a map of several items, bisect it (match_gate.bisect: halves gated on top of the ones kept, a passing half
    kept whole, down to the single items that fail). The journal gets only what was kept. Prints
    `GATE-REJECTED old -> new: why` per rejected item. -> 0, 1 (something rejected), 2 (refused)."""
    import match_gate as MG
    verdicts = []

    def run(group):
        txn = MG.Txn(repo)
        rc, done = apply_items(repo, a.client, group, opts, quiet=a.quiet, txn=txn)
        if not done:
            return rc, None
        vas = {p.va for _i, p in done if p.kind == "fn" and p.va is not None}
        try:
            v = MG.gate_txn(repo, txn, vas, cache=a.gate_cache, fixtures=a.fixtures)
        except BaseException:
            txn.restore()                   # never leave a half-gated tree behind
            raise
        verdicts.append({"items": [[i["old"], i["new"]] for i, _p in done], **v.as_json()})
        print(v.report())
        if not v.ok:
            txn.restore()
        elif a.journal:
            write_journal(a.journal, [p for _i, p in done])
        return rc, v

    rc, v = run(items)
    rejected = []
    if v is not None and not v.ok:
        rc_b, rejected = MG.bisect(items, run, first=v)
        rc = max(rc, rc_b)
    for it, vv in rejected:
        why = "; ".join((vv.problems + vv.regressions + [f"fixture {f}" for f in vv.fixtures_failed])[:3])
        print(f"GATE-REJECTED {it['old']} -> {it['new']}: {why}")
    if a.gate_json:
        Path(a.gate_json).write_text(json.dumps(verdicts, indent=1), encoding="utf-8")
    return 2 if rc == 2 else (1 if rejected else 0)


if __name__ == "__main__":
    sys.exit(main())
