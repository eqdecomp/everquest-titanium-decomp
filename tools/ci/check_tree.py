r"""Repository checks that need neither the client binaries nor Visual C++ .NET 2003 (what CI runs).

    python tools/ci/check_tree.py [REPO]     exit 0 = clean (warnings allowed), 1 = problems (listed)

Problems (exit 1):
- forbidden files: executables, objects, archives, images, sound, the client's data files, Ghidra/IDA/BinDiff
  projects, disassembly or decompiler dumps, compiler or SDK folders, local config (paths.local.ini),
  virtual environments;
- a file over 1 MB (fixtures 2 MB), NUL bytes, binary or archive magic, text that is not UTF-8, control
  characters in a text file;
- local paths (a drive's Users\<name> folder, /home/<name>, AppData) and e-mail addresses other than
  placeholder ones (example.com, example.org, .invalid, .test);
- annotations: every `// FUNCTION:` and `// EXTERNAL:` line in src/ and include/ reads
  `// FUNCTION: TITANIUM 0x<8 hex digits>` (or another image token of this client);
- fixtures (tests/unicorn/EverQuest/**/*.json): valid JSON objects with `function`, `original` ("0x<hex>"),
  `sources` (paths inside the repository that exist) and `cases` (a list); every `from_image` reference is
  "0x<hex>" with a positive `image_size` and no `hex` beside it (the bytes are read from your own binary at
  test time).
Warnings (listed, exit 0): one `// FUNCTION:` address annotated in several files (a shared helper rebuilt in
each file that inlines it), an `image_size` written as a hex string.

It cannot tell whether a value in a fixture is original data: that needs the binaries (the maintainers check
it before every release).
"""
from __future__ import annotations

import json
import re
import subprocess
import sys
from pathlib import Path

FORBIDDEN_EXT = {".exe", ".dll", ".obj", ".lib", ".pdb", ".exp", ".ilk", ".res", ".idb", ".i64", ".id0", ".id1",
                 ".nam", ".til", ".wav", ".bmp", ".png", ".jpg", ".tga", ".dds", ".s3d", ".wld", ".eqg", ".mid",
                 ".xmi", ".mp3", ".eff", ".eqm", ".zon", ".ter", ".zip", ".7z", ".gz", ".rar", ".tar", ".cab",
                 ".iso", ".gpr", ".gzf", ".binexport", ".bindiff", ".pyc", ".dmp", ".asm", ".lst", ".cod", ".map"}
FORBIDDEN_PARTS = {"original", "downloads", "toolchains", "dx7sdk", "dx9sdk", "vc7", "platformsdk", ".venv",
                   "__pycache__"}                                     # any level
FORBIDDEN_TOP = {"build", "ghidra"}                                   # workspace folders, at the repository root
FORBIDDEN_NAMES = re.compile(r"(?i)^(paths\.local\.ini.*|eqmac.*\.c|ddraw\.h|d3d\.h|d3d8.*\.h|d3d9.*\.h|"
                             r"d3dtypes\.h|d3dcaps\.h|dinput\.h|dsound\.h|dplay\.h|eqclassic_notes\.tsv|"
                             r"eqstr_.*\.txt|dbstr_.*\.txt|spells_.*\.txt|patch_.*\.conf)$")
MAX_FILE, MAX_FIXTURE = 1 << 20, 2 << 20
MAGIC = [(b"MZ", "PE/DOS executable"), (b"PK\x03\x04", "zip"), (b"7z\xbc\xaf\x27\x1c", "7z"), (b"\x1f\x8b", "gzip"),
         (b"Rar!", "rar"), (b"%PDF", "pdf"), (b"\x89PNG", "png"), (b"RIFF", "riff/wav"), (b"MThd", "midi"),
         (b"\x7fELF", "elf"), (b"\xcf\xfa\xed\xfe", "mach-o"), (b"\xce\xfa\xed\xfe", "mach-o")]
LOCAL = [(re.compile(r"[A-Za-z]:[\\/]+Users[\\/]+(?!<)[A-Za-z0-9_.-]+", re.I), "local user path"),
         (re.compile(r"/home/[a-z_][a-z0-9_-]*/"), "home path"),
         (re.compile(r"AppData[\\/]", re.I), "profile path")]
EMAIL = re.compile(r"[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}")
EMAIL_OK_DOMAINS = ("example.com", "example.org", ".invalid", ".test", "users.noreply.github.com")
IMAGES = {"TITANIUM", "TITANIUM_EQMAIN", "TITANIUM_DX9"}
ANN_LINE = re.compile(r"^[ \t]*//[ \t]*(FUNCTION|EXTERNAL):(.*)$", re.M)
ANN_OK = {"FUNCTION": re.compile(r" ([A-Z0-9_]+) 0x([0-9A-F]{8})[ \t]*\Z"),
          "EXTERNAL": re.compile(r" ([A-Z0-9_]+) 0x([0-9A-F]{8})(?: \S.*)?\Z")}
HEX = re.compile(r"0x[0-9A-Fa-f]+\Z")
CONTROL = re.compile(r"[\x01-\x08\x0b\x0c\x0e-\x1f\x7f]")
# Two tools files hold a control byte on purpose (a literal byte inside a bytes or regex literal).
CONTROL_OK = {"tools/structs/propagate.py", "tools/unicorn/eqd_unicorn/machine.py"}
# This file names the patterns it looks for; it is not checked against its own pattern list.
SELF = "tools/ci/check_tree.py"


def tracked(repo: Path) -> list[str]:
    try:
        out = subprocess.run(["git", "-C", str(repo), "ls-files", "-z"], capture_output=True, check=True).stdout
        files = [p for p in out.decode("utf-8").split("\0") if p]
        if files:
            return files
    except (OSError, subprocess.CalledProcessError):
        pass
    return sorted(p.relative_to(repo).as_posix() for p in repo.rglob("*") if p.is_file() and ".git" not in p.parts)


def refs(node, path, out):
    """Every dict holding a from_image key, with its JSON path."""
    if isinstance(node, dict):
        if "from_image" in node:
            out.append((path, node))
        for k, v in node.items():
            refs(v, f"{path}.{k}", out)
    elif isinstance(node, list):
        for i, v in enumerate(node):
            refs(v, f"{path}[{i}]", out)


def check_fixture(rel, fx, paths, problems, warnings):
    if not isinstance(fx, dict):
        problems.append(f"{rel}: a fixture must be a JSON object")
        return
    if not isinstance(fx.get("function"), str):
        problems.append(f"{rel}: `function` missing or not a string")
    if not (isinstance(fx.get("original"), str) and HEX.match(fx["original"])):
        problems.append(f"{rel}: `original` must be \"0x<hex>\"")
    if not isinstance(fx.get("cases"), list):
        problems.append(f"{rel}: `cases` missing or not a list")
    sources = fx.get("sources")
    if not (isinstance(sources, list) and sources):
        problems.append(f"{rel}: `sources` missing or empty")
        sources = []
    for s in sources:
        parts = re.split(r"[\\/]", s) if isinstance(s, str) else [".."]
        if not isinstance(s, str) or s.startswith(("/", "\\")) or re.match(r"[A-Za-z]:", s) or ".." in parts:
            problems.append(f"{rel}: source outside the repository: {s!r}")
        elif s.replace("\\", "/") not in paths:
            problems.append(f"{rel}: source not in the repository: {s!r}")
    found = []
    refs(fx, "$", found)
    for jp, node in found:
        va, n = node.get("from_image"), node.get("image_size")
        if isinstance(n, str) and HEX.match(n) and int(n, 16) > 0:
            warnings.append(f"{rel}: {jp}: image_size written as a string ({n!r}); an integer is the documented form")
            n = int(n, 16)
        if not (isinstance(va, str) and HEX.match(va)) or not (isinstance(n, int) and n > 0):
            problems.append(f"{rel}: {jp}: from_image needs \"0x<hex>\" and a positive image_size")
        if "hex" in node:
            problems.append(f"{rel}: {jp}: from_image together with hex")


def check(repo: Path):
    problems, warnings = [], []
    seen = {}
    files = tracked(repo)
    paths = set(files)
    for rel in files:
        p = repo / rel
        if not p.is_file():
            continue
        parts = rel.split("/")
        low = [x.lower() for x in parts]
        if (p.suffix.lower() in FORBIDDEN_EXT or set(low[:-1]) & FORBIDDEN_PARTS or FORBIDDEN_NAMES.match(parts[-1])
                or (len(low) > 1 and low[0] in FORBIDDEN_TOP)):
            problems.append(f"{rel}: forbidden file")
            continue
        data = p.read_bytes()
        fixture = rel.startswith("tests/unicorn/EverQuest/") and rel.endswith(".json") and "/negative/" not in rel
        if len(data) > (MAX_FIXTURE if fixture else MAX_FILE):
            problems.append(f"{rel}: {len(data)} bytes, over the size limit")
        for m, what in MAGIC:
            if data.startswith(m):
                problems.append(f"{rel}: starts like a {what} file")
        if b"\0" in data:
            problems.append(f"{rel}: NUL bytes (binary)")
            continue
        try:
            text = data.decode("utf-8")
        except UnicodeDecodeError as e:
            problems.append(f"{rel}: not UTF-8 ({e})")
            continue
        if CONTROL.search(text) and rel not in CONTROL_OK:
            problems.append(f"{rel}: control character in a text file")
        if rel != SELF:
            for rx, what in LOCAL:
                for mm in rx.finditer(text):
                    problems.append(f"{rel}:{text.count(chr(10), 0, mm.start()) + 1}: {what}: {mm.group(0)!r}")
            for mm in EMAIL.finditer(text):
                e = mm.group(0).lower()
                if e.endswith(EMAIL_OK_DOMAINS) or re.fullmatch(r".*@\d+\.\d+.*", e):
                    continue
                problems.append(f"{rel}:{text.count(chr(10), 0, mm.start()) + 1}: e-mail address {mm.group(0)!r}")
        if rel.endswith(".json") and rel.startswith("tests/"):
            try:
                fx = json.loads(text)
            except ValueError as e:
                problems.append(f"{rel}: invalid JSON ({e})")
                continue
            if fixture:
                check_fixture(rel, fx, paths, problems, warnings)
        if rel.startswith(("src/", "include/")) and p.suffix.lower() in (".c", ".cpp", ".h"):
            for mm in ANN_LINE.finditer(text):
                kind, rest = mm.group(1), mm.group(2).rstrip("\r")
                ok = ANN_OK[kind].match(rest)
                ln = text.count("\n", 0, mm.start()) + 1
                if not ok or ok.group(1) not in IMAGES:
                    problems.append(f"{rel}:{ln}: malformed annotation (want `// {kind}: TITANIUM 0x<8 hex digits>`):"
                                    f" {mm.group(0).strip()!r}")
                    continue
                if kind == "FUNCTION":
                    seen.setdefault((ok.group(1), int(ok.group(2), 16)), []).append(rel)
    for (tok, va), where in sorted(seen.items()):
        if len(set(where)) > 1:
            warnings.append(f"// FUNCTION: {tok} 0x{va:08X} annotated in {len(set(where))} files: "
                            + ", ".join(sorted(set(where))))
        elif len(where) > 1:
            problems.append(f"// FUNCTION: {tok} 0x{va:08X} annotated twice in {where[0]}")
    return problems, warnings


def main(argv=None) -> int:
    argv = sys.argv[1:] if argv is None else argv
    repo = Path(argv[0] if argv else ".").resolve()
    problems, warnings = check(repo)
    for x in problems:
        print("FAIL", x)
    for x in warnings:
        print("WARN", x)
    print(f"check_tree: {len(problems)} problem(s), {len(warnings)} warning(s)")
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
