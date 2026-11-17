# Tool index: need -> tool -> command

Check here before writing a one-off script: most recurring needs already have a tool. Commands run from
the decomp repo (`cd eq-trilogy`; this repo is its `tools\` submodule) unless they say "workspace" (run
from the workspace root, this repo as `eq-titanium\tools\`). `PY` = `..\.venv\Scripts\python.exe` (from
the workspace: `.venv\Scripts\python.exe`). Details are in each folder's README.

## Find work and what's known about it

| Need | Tool | Command |
|---|---|---|
| Another image of the repo (eqmain.dll): which client id, paths, toolchain | `unicorn/eqd_unicorn/clients.py` | `-c eqmain` on every tool; `docs/EQMAIN.md` |
| Everything needed to rewrite a function | `context/pack_context.py` | workspace: `PY eq-titanium\tools\context\pack_context.py trilogy ADDR [ADDR ...] \| --next N \| --subsystem S` |

## Rewrite and test a function

| Need | Tool | Command |
|---|---|---|
| A fixture skeleton for a rewritten function | `unicorn/tools/make_fixture.py` | `PY tools\unicorn\tools\make_fixture.py trilogy 0x00410C80 [--run]` |
| Run fixtures (original vs rewrite under Unicorn) | `unicorn/` harness via pytest | `PY -m pytest tests/unicorn/<subsystem path> [-k Name -v]` |
| Prove the fixture catches wrong code (mutation check) | `unicorn/tools/mutate_check.py` | `PY tools\unicorn\tools\mutate_check.py --va 0x00410C80` (or a fixture path) |
| Functional tests for Titanium: how to fixture, gaps, landing proposal | `docs/TITANIUM_FUNCTIONAL.md` | `PY tools\unicorn\tools\make_fixture.py titanium 0x0042510E --run` |
| Test-DLL cache stats, prune, warm-up | `unicorn/tools/unicorn_cache.py` | `PY tools\unicorn\tools\unicorn_cache.py --stats \| --prune \| --clear \| --warm` |
| Per-file compiler options | `// CFLAGS:` line in the source | see `unicorn/README.md` "Per-source compiler flags" |
| Per-file toolchain (SP4/SP5) | `// TOOLCHAIN: vc6` line in the source, or the image's folder rule (`clients.py toolchain_dirs`) | see `docs/EQMAIN.md` "Per-file toolchain" |

## Match the original's code

| Need | Tool | Command |
|---|---|---|
| Is a rewrite instruction-identical (DLL build)? | `compare/compare.py` | `PY tools\compare\compare.py [src\...\X.cpp] [-v] [--va VA --show]` |
| Byte-match status for every rewrite, near-miss list | `compare/compare.py --match` | `PY tools\compare\compare.py --match --json ..\build\match\match.json --nearmiss ..\build\match\nearmiss.txt` |
| Search source variants for a near miss | `permute/permute.py` | `PY tools\permute\permute.py --snapshot --va 0x004A3911` (or `--nearmiss F`, `--match-json F --status diff`) |
| Status markers, unmarked fake-match oddities, readability ratchet | `compare/source_checks.py` | `PY tools\compare\source_checks.py [-v] [--update \| --raise-floor]` |

| Estimate each function's original object (hint) | `compare/tumap.py` | `PY tools\compare\tumap.py titanium` -> `build\titanium\tus.json` |
| Find STL and CRT code misfiled in the game span | `compare/libfence.py` | `PY tools\compare\libfence.py titanium` -> `build\titanium\libfence.json` |
| Clone a tested rewrite onto its dupes.py cluster siblings, verify each (fixture, mutation, match) | `compare/clone.py` | `PY tools\compare\clone.py --from VA (--siblings \| --to VA ...) [--dry-run]`, then `apply_patches.py <out>\results.jsonl` |
| Clone tested eqgame.exe rewrites onto their eqmain.dll siblings | `compare/clone.py --from-client` | `PY tools\compare\clone.py --client eqmain --from-client trilogy --all-siblings [--limit N]` |

## Giants (functions >= 4 KB)

| Need | Tool | Command |
|---|---|---|
| Mutants only in some lines / spread over the `// REGION` blocks, reported per region; `--max` scales with the function's size | `unicorn/tools/mutate_check.py` | `--lines 120-340` (repeatable); `--region-markers [--region R05] [--max-per-region 3]` |
| Decode switches Ghidra missed, create functions it never made (vtable/table-only) | `ghidra/scripts/recover_code.py` | workspace: `PY eq-titanium\tools\ghidra\scripts\recover_code.py trilogy [--dry-run] [--only send_social,0042A26F] [--all]` |

## Close a wave

| Need | Tool | Command |
|---|---|---|
| Names from the rewrites' `// FUNCTION:` annotations | `ghidra/scripts/annotation_names.py` | workspace: `PY eq-titanium\tools\ghidra\scripts\annotation_names.py trilogy --committed --write` |
| Hook DLL, hooks.ini, launcher; find a bad hook | decomp repo's `hooks\` | `hooks\build.bat`; `PY hooks\bisect_hooks.py`; `..\build\trilogy\hooks\eqlaunch.exe` |

## Ghidra project, names and types (workspace; order in `ghidra/README.md`)

| Need | Tool | Command |
|---|---|---|
| Create a client project (import + analysis) | `make_project.py` | `PY eq-titanium\tools\ghidra\scripts\make_project.py trilogy --overwrite` |
| VC6 library signatures (FID) and applying them | `build_vc6_fid.py`, `apply_fid.py`, `fid_names.py` | `build_vc6_fid.py import LIB` / `build`; `apply_fid.py trilogy`; `fid_names.py trilogy` |
| BinExport/features, BinDiff pairs | `export_features.py` + `bindiff` | `export_features.py trilogy`; `bindiff --output_dir=build\bindiff A.BinExport B.BinExport` |
| Original source file per Mac function | `mac_debug_map.py` | `mac_debug_map.py` |
| Carry names Mac -> TAKP -> Trilogy; beta and string names | `name_chain.py`, `name_beta.py`, `eqd_match.py` | `name_chain.py takp`, `name_chain.py trilogy`; `name_beta.py [--validate]` |
| EQClassic source-comment names | `extract_eqclassic_notes.py` | `extract_eqclassic_notes.py` |
| Apply all name lists to the project | `apply_names.py` | `apply_names.py trilogy` |
| Headers -> Ghidra types; typed globals and signatures | `build_gdt.py`, `apply_types.py`, `apply_typed_symbols.py` | `build_gdt.py trilogy`; `apply_types.py trilogy`; `apply_typed_symbols.py trilogy` |
| How much is named/typed | `coverage_report.py` | `coverage_report.py` -> `build\coverage.md` |
| JSON export for the queue and context packer | `export/export_client.py` | `PY eq-titanium\tools\export\export_client.py trilogy [--phase meta]` |

## Tool self-tests (workspace)

`PY -m pytest eq-titanium\tools\tests\<queue|compare|context|export|permute|unicorn>`; the unicorn self-tests
are slow, run only the folder you changed.
