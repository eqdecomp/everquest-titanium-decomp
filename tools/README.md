# tools

The tooling of this decompilation, vendored into the repo as `tools/` (it is developed as a separate project
and copied in for each release). It contains no game code, game data, or decompiler output. Some tools and
tests also support another client of the same project; those parts skip when their binaries are absent.

## Contents
- `docs/RULES.md`: how code is written and checked. `docs/tool-index.md`: which tool solves which need.
- `docs/VC71_QUIRKS.md` (+ `docs/vc71_quirks/`): known Visual C++ 7.1 code-generation patterns, each with a
  repro (the readable guide built on them is `docs/VC71_QUIRKS.md` in the repository's own `docs/` folder).
  `docs/TITANIUM_MATCH_NOTES.md`, `docs/TITANIUM_FUNCTIONAL.md`, `docs/TITANIUM_FIXTURE_NOTES.md`:
  matching, functional-equivalence and fixture notes for this client. `docs/EQ_NOTES.md`: facts about the
  client's own code.
- `doctor.py`: checks a workspace (Python, packages, `paths.local.ini`, the binary and its hash, the VC7.1
  compiler and linker versions) and says what is missing. Run it with `--repo-name eq-titanium`.
- `paths.example.ini`: template for the workspace `paths.local.ini`.
- `requirements.txt` / `requirements-lock.txt`: the Python dependencies (Python 3.13).
- `unicorn/`: the differential test harness (original function vs compiled rewrite under Unicorn).
- `compare/`: instruction/byte comparison of rewrites with the original (`compare.py`), `tumap.py` (object
  file estimates), `source_checks.py`, `progress.py`, `stackcmp.py`, `reccmp_map.py`.
- `permute/`: permuter, random semantics-preserving source mutations for near-miss functions.
- `readability/`: name registry, safe rename, the gate "compiles to the same code as before".
- `structs/`: struct-layout census, layout JSON -> C header generator and checks.
- `context/`: one function's evidence (pseudocode, assembly, callers/callees, structs) in one bundle, from a
  local Ghidra export; similar-function examples.
- `ghidra/`, `export/`: headless PyGhidra scripts and the read-only JSON export of a Ghidra project. Both need
  your own Ghidra project of your own binary.
- `ci/check_tree.py`: the repository checks GitHub CI runs (no binary or compiler needed).
- `tests/`: the tools' own tests. Many need a workspace with the binary and the compiler and skip without.

## Setup
See `BUILDING.md` in the repo root.

## Licence
MIT, see `LICENSE` (the same as the repository root).
