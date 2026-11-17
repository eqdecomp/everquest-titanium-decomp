# everquest-titanium-decomp

> **Legal warning:** This is an unofficial, unaffiliated reverse-engineering project. It contains no game
> files, and you need your own legally obtained copy of the client to use it. EverQuest is a trademark of its
> owners. For research and preservation only: do not use it with official servers or to break any agreement
> you are bound by.

> **AI notice:** Most of the code and documentation was written with AI tools. Every function is checked
> against the original by the tests and compare tools, not taken on trust, but names, comments and notes can
> still be wrong.

A decompilation of the EverQuest Titanium client (2005). The goal is readable C++ that behaves exactly like
the original and, with Visual C++ .NET 2003 (7.1), compiles to the same machine code. The client is three
binaries: `eqgame.exe` (the game), `eqmain.dll` (login and server select) and `EQGraphicsDX9.dll` (the
renderer). This repository covers `eqgame.exe`; the two DLLs are not started yet.

## Status

| Binary | Functions in scope | Decompiled | Tested by fixtures | Byte-identical |
|---|---:|---:|---:|---:|
| `eqgame.exe` | 5,522 | 5,520 (99.9%) | 999 (18.0%) | 4,551 (82.4%) |
| `eqmain.dll` | 982 | 0 | 0 | 0 |
| `EQGraphicsDX9.dll` | 3,015 | 0 | 0 | 0 |

- **Functions in scope**: the client's own functions. C runtime, STL and other library code, compiler helpers,
  data and thunks are not counted, and neither are the D3DX9 library linked into `EQGraphicsDX9.dll`, zlib, or
  the shared UI and support code (string, logging and file-pack classes) that each binary carries its own copy of.
- **Decompiled**: reconstructed source exists (a `// FUNCTION:` annotation).
- **Tested by fixtures**: a differential fixture in `tests/unicorn/` runs the original and the rewrite side by
  side. This counts the fixtures in this repository, not the result of a particular run.
- **Byte-identical**: the compiler turns the rewrite into the original's bytes (relocated fields aside).

"Tested by fixtures" counts the functions that have an emulator test. Every decompiled function is also
checked instruction by instruction with compare, which gives the byte-identical column; fixtures are added
where behaviour is worth pinning down.

The table is generated when the repository is exported. [PROGRESS.md](PROGRESS.md) has the counts per source
file and per compare result. This repository does not build a playable game.

Known gaps:

- Large functions: most small functions are identical, many large ones are close but not there yet. Those
  carry `@early-stop` with a note on what still differs.
- Many names end in `_guess` (inferred, not taken from symbols) and some functions are still `FUN_<address>`.
- A few files keep small `__asm` blocks where no C++ form has been found yet.
- Not included: fixtures that hold client text, and the library code linked into `eqgame.exe` (C runtime,
  STL, D3DX).

## How it is checked

Each reconstructed function carries its original address (`// FUNCTION: TITANIUM 0x...`) and is checked
against **your own copy** of the client:

- **Fixtures** (`tests/unicorn/`) run the original and the VC7.1-built rewrite side by side in an emulator on
  the same inputs. Return values, memory writes and calls must agree. Values that equal the original binary
  are stored as references (`from_image`) and read from your copy at test time.
- **compare** (`tools/compare/`) checks the rewrite's instructions and bytes against the original's.

## Terms

- **Fixture**: a JSON test case in `tests/unicorn/` that runs one function, original and rewrite, on the same
  inputs and compares the results.
- **`_guess`** on a name: inferred from behaviour or context, not from a symbol. `FUN_<address>`: no name yet.
- **`@early-stop`**: the function behaves like the original but its machine code still differs; the comment
  says how.

## Legal

- Not affiliated with or endorsed by Daybreak Game Company or Sony Online Entertainment. EverQuest is a
  trademark of its owners.
- **This repository contains no game files or assets:** no executables, DLLs, models, textures, sounds, music,
  archives or data files. Bring your own legally obtained `eqgame.exe`; [BUILDING.md](BUILDING.md) gives the
  supported build's SHA-256.
- It does contain material derived from the client, so that the code can be read and tested: reconstructed
  source, much of which compiles to the original machine code; a few small blocks of inline assembly; client
  text strings used by the code; and addresses, structure layouts, packet opcodes and names. Other original
  data is not stored: tests refer to it by address and read it from your binary.
- Licence: MIT, see [LICENSE](LICENSE). It covers this project's own work only and grants nothing in
  EverQuest or in third-party material.
- Names and values taken as facts from community projects (EQEmu, MacroQuest, ShowEQ, Mac client / TAKP
  name lists) are listed in [docs/ATTRIBUTION.md](docs/ATTRIBUTION.md). None of their files are included.
- **Rights holders:** see [SECURITY.md](SECURITY.md) to reach us privately.

## Quick start (Windows)

You need Python 3.13, git, your own `eqgame.exe` and Visual C++ .NET 2003 (7.1) RTM;
[BUILDING.md](BUILDING.md) has the details.

```
mkdir C:\eqws & cd /d C:\eqws
git clone https://github.com/eqdecomp/everquest-titanium-decomp.git eq-titanium
copy eq-titanium\tools\paths.example.ini paths.local.ini
py -3.13 -m venv .venv
.venv\Scripts\python -m pip install -r eq-titanium\tools\requirements-lock.txt
```

Keep the folder name `eq-titanium`. Copy `eqgame.exe` to `C:\eqws\original\titanium\`, set `[toolchain] vc71`
in `paths.local.ini`, then:

```
cd eq-titanium
..\.venv\Scripts\python tools\doctor.py --repo-name eq-titanium
..\.venv\Scripts\python -m pytest tests\unicorn\EverQuest\tu_018_MailtoLink -q
```

`doctor.py` lists anything missing. Without the binary or VC7.1, fixtures skip rather than fail, so a fresh
clone alone tests nothing.

## Layout

```
src/EverQuest/    reconstructed code, one file per estimated object file (tu_NNN_<Name>.cpp)
src/Suite/        pilot files from the UI library range
include/titanium/ shared declarations, global addresses, CRT markers
tests/unicorn/    differential fixtures
names/            address-to-name list for library code, with source and confidence
tools/            test harness, compare, permuter, readability and Ghidra scripts
docs/             architecture overview, subsystem guides, known client bugs, attribution
.github/          CI: repository checks that need no game files and no compiler
```

Documentation:

- [docs/README.md](docs/README.md): how the source tree is organised, conventions, reading order.
- [docs/ARCHITECTURE.md](docs/ARCHITECTURE.md): what each part of the client does and where its code is.
- [docs/VC71_QUIRKS.md](docs/VC71_QUIRKS.md): Visual C++ .NET 2003 code-generation patterns and the source
  shapes that reproduce them, for anyone matching code built with that compiler.
- [docs/KNOWN_CLIENT_BUGS.md](docs/KNOWN_CLIENT_BUGS.md): defects of the original client that the code keeps.
- [CONTRIBUTING.md](CONTRIBUTING.md), [BUILDING.md](BUILDING.md), [PROGRESS.md](PROGRESS.md).

## What's next

- **Large functions**: most of the remaining non-identical functions are large.
- **Names**: confirming `_guess` names and naming the last `FUN_` functions.
- **`eqmain.dll`, then `EQGraphicsDX9.dll`**: same compiler, same method; not started.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md), provenance rules first. Security issues: [SECURITY.md](SECURITY.md).
