# Building and testing

Nothing in this repository runs on its own: the tests and the compare need **your own** client binary and
**your own** compiler. Neither is included, and neither may be added to the repository.

## What you supply

| Item | Version | Where it is configured |
|---|---|---|
| `eqgame.exe` | EverQuest Titanium, SHA-256 `ffa64c072c0c5e834a982720fd395ddc8974df26d1597020e1dbeb651b7ed957` | `<original>\titanium\eqgame.exe` (`[workspace] original` in `paths.local.ini`) |
| Visual C++ .NET 2003 (VC7.1) | RTM: `cl.exe`/`c2.dll` 13.10.3077, `link.exe` 7.10.3077 (SP1, 13.10.6030, does not match) | `[toolchain] vc71` in `paths.local.ini`: the folder holding `Bin\cl.exe`, `Include\`, `Lib\` |
| Platform SDK headers/libs | any that work with VC7.1 (optional: `<vc71>\PlatformSDK_vc6\Include` and `Lib` are picked up if present) | inside the `vc71` folder |
| Python | 3.13, with the packages in `tools/requirements-lock.txt` | a virtual environment in the workspace |

Another build of `eqgame.exe` makes the fixtures skip (set `EQD_ANY_BINARY=1` to run them anyway; results are
then meaningless for byte matching).

## Workspace layout

```
<workspace>\
  paths.local.ini        your local settings (never committed)
  original\titanium\eqgame.exe
  build\                 created by the tools (test DLLs, compare objects)
  .venv\
  eq-titanium\           this repository (keep the folder name: the tools look the client up by it)
```

## Setup (Windows)

```
mkdir eqws & cd eqws
git clone https://github.com/eqdecomp/everquest-titanium-decomp.git eq-titanium
copy eq-titanium\tools\paths.example.ini paths.local.ini
py -3.13 -m venv .venv
.venv\Scripts\python -m pip install -r eq-titanium\tools\requirements-lock.txt
```

Edit `paths.local.ini`: set `[toolchain] vc71` to your VC7.1 folder and copy your `eqgame.exe` into
`original\titanium\`. Then check the workspace:

```
cd eq-titanium
..\.venv\Scripts\python tools\doctor.py --repo-name eq-titanium
```

`doctor.py` reports the Python version and packages, finds `paths.local.ini`, hashes `eqgame.exe` against the
supported build and reads the compiler's and linker's file versions (13.10.3077 / 7.10.3077). Every line marked
`MISSING` comes with the fix; exit code 0 means the fixtures can run.

## Compare (byte matching)

```
..\.venv\Scripts\python tools\compare\compare.py --repo . --client titanium --match src\EverQuest\tu_000_FadeList.cpp
```

Pass several files (or a shell glob over `src\EverQuest\*.cpp`) to compare more. Each function marked
`// FUNCTION: TITANIUM 0x...` is compiled with the flags in its file's `// CFLAGS:` line and compared with the
original's bytes.

## Fixtures (behaviour)

```
..\.venv\Scripts\python -m pytest tests\unicorn -q
..\.venv\Scripts\python -m pytest tests\unicorn\EverQuest\tu_018_MailtoLink -q
```

Each fixture builds a test DLL from the listed sources with VC7.1, runs the original function and the rewrite
under Unicorn on the same inputs, and compares return values, memory writes and calls. Fixture values that
equal the original are stored as `{"from_image": "0x<VA>", "image_size": N}` and read from your `eqgame.exe`.
Without the binary or the compiler, fixtures skip rather than fail.

The fixtures that need function boundaries from a Ghidra export (`<build>\export\titanium\functions.json`,
made with `tools\export\`) use them when present and fall back otherwise.
