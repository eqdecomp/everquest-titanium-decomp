"""Read `// FUNCTION: <CLIENT> 0x...` annotations from decomp sources.

The annotation is followed (after more `//` comment lines) by the function definition. The qualified name
is the last `Name` or `Class::Name` before the first `(` on the definition line, e.g.
    char* CEverQuest::GetLanguageName(short languageId)  ->  CEverQuest::GetLanguageName
with the file's one-identifier `#define`s in force there applied, as the compiler sees it (the giants'
`#define CEverQuest CEverQuest_HandleWorldMessage_type_guess` file-local class trick).

A function the compiler writes itself (a scalar/vector deleting destructor, an implicit destructor or
constructor) has no definition to follow the annotation. A `// GENERATED:` line among the comment lines right
below the annotation binds the VA to it instead, by decorated name or by class and kind:
    // FUNCTION: TITANIUM 0x004BF94B
    // GENERATED: PcBase_guess::`scalar deleting destructor'      (or ??_GPcBase_guess@@UAEPAXI@Z)
Kinds: `Class::~Class`, `Class::Class`, and `Class::` + one of SPECIAL's names. The annotation's name is the
one `symbol_name` gives the object symbol, so the tools that pair names with symbols find it unchanged; a
decorated name is also kept in `symbol` and matched exactly (one overload of several implicit constructors).
"""
from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path

from .pe import undecorate

_ANN = re.compile(r"^\s*//\s*FUNCTION:\s*(\w+)\s+(0x[0-9a-fA-F]+)")
_NAME = re.compile(r"([A-Za-z_~][\w]*(?:::[A-Za-z_~][\w]*)*)\s*\(")
# Comments between the annotation and the definition are skipped whole, `/* */` blocks included, and
# preprocessor lines: a word before a parenthesis in one ("the creation routine (0x0040D980)") was taken as the
# name (seen in another decomp project, where it was worked around by setting `rewrite` by hand).
_BLOCK = re.compile(r"/\*.*?\*/", re.S)
_LINE = re.compile(r"//[^\n]*")
_DEFINE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)\s+([A-Za-z_]\w*)\s*(?://.*)?$")
_UNDEF = re.compile(r"^\s*#\s*undef\s+([A-Za-z_]\w*)")
_GEN = re.compile(r"^\s*//\s*GENERATED:\s*(\S.*?)\s*$")
_COMMENT = re.compile(r"^\s*//")
# The compiler's special members by decoration prefix (MSVC: ??_G, ??_E, ??_D).
SPECIAL = {"??_G": "`scalar deleting destructor'", "??_E": "`vector deleting destructor'",
           "??_D": "`vbase destructor'"}
_QUAL = r"[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*"
_GEN_NAME = re.compile(rf"^({_QUAL})::(~?[A-Za-z_]\w*|`[a-z ]+')$")


@dataclass(frozen=True)
class Annotation:
    client: str
    va: int
    name: str
    path: str
    line: int
    generated: bool = False         # bound by a `// GENERATED:` line (no written definition)
    symbol: str | None = None       # its decorated name, when the line gave one


def symbol_name(sym: str) -> str:
    """The annotation name of object symbol `sym`: `undecorate(sym)`, and for the compiler's special members
    (SPECIAL, no `$` this-adjustor: a vtordisp thunk keeps its decorated name) `Class::`kind'`."""
    kind = SPECIAL.get(sym[:4])
    if kind and "@@" in sym[4:]:
        cls, rest = sym[4:].split("@@", 1)
        if not rest.startswith("$") and cls and "?" not in cls:
            return "::".join(reversed(cls.split("@"))) + "::" + kind
    return undecorate(sym)


def matches(a: Annotation, sym: str) -> bool:
    """Is object symbol `sym` the function annotation `a` names?"""
    symbol = getattr(a, "symbol", None)     # (tests pass plain namespaces with va, name, line)
    return sym == symbol if symbol else symbol_name(sym) == a.name


def generated_name(spec: str) -> tuple[str, str | None]:
    """`// GENERATED:` text -> (annotation name, decorated name or None). ValueError when it names no function the
    compiler generates (a constructor, a destructor or one of SPECIAL)."""
    spec = spec.strip()
    sym = spec if spec.startswith("?") else None
    name = symbol_name(spec) if sym else re.sub(r"\s*::\s*", "::", spec)
    m = _GEN_NAME.match(name)
    if not m:
        raise ValueError(f"GENERATED: expected Class::~Class, Class::Class, Class::`kind' or the decorated name of "
                         f"one, got {spec!r}")
    cls, member = m.groups()
    simple = cls.split("::")[-1]
    if member not in (simple, "~" + simple) and member not in SPECIAL.values():
        raise ValueError(f"GENERATED: {spec!r} is not a constructor, destructor or one of {sorted(SPECIAL.values())}")
    return name, sym


def _generated(lines, i):
    """The `// GENERATED:` text in the comment lines right below annotation line `i`, else None."""
    for ln in lines[i + 1:i + 40]:
        if not _COMMENT.match(ln) or _ANN.match(ln):
            return None
        if g := _GEN.match(ln):
            return g.group(1)
    return None


def scan(paths, client: str | None = None) -> list[Annotation]:
    out = []
    for p in paths:
        lines = Path(p).read_text(encoding="utf-8", errors="replace").splitlines()
        defines = {}
        i = 0
        while i < len(lines):
            if d := _DEFINE.match(lines[i]):
                defines[d.group(1)] = d.group(2)
            elif u := _UNDEF.match(lines[i]):
                defines.pop(u.group(1), None)
            m = _ANN.match(lines[i])
            if not m or (client and m.group(1).upper() != client.upper()):
                i += 1
                continue
            if (spec := _generated(lines, i)) is not None:
                try:
                    name, sym = generated_name(spec)
                except ValueError as e:
                    raise ValueError(f"{p}:{i + 2}: {e}") from None
                if sym is None:
                    name = "::".join(("~" if part[:1] == "~" else "") + defines.get(part.lstrip("~"), part.lstrip("~"))
                                     for part in name.split("::"))
                out.append(Annotation(m.group(1).upper(), int(m.group(2), 16), name, str(p), i + 1, True, sym))
                i += 1
                continue
            code = _LINE.sub("", _BLOCK.sub(" ", "\n".join(lines[i + 1:i + 200])))
            head = " ".join([l for l in code.splitlines() if l.strip() and not l.lstrip().startswith("#")][:3])
            n = _NAME.search(head)
            if not n:
                raise ValueError(f"{p}:{i + 2}: no function name after FUNCTION annotation")
            name = "::".join(defines.get(part, part) for part in n.group(1).split("::"))
            out.append(Annotation(m.group(1).upper(), int(m.group(2), 16), name, str(p), i + 1))
            i += 1
    return out
