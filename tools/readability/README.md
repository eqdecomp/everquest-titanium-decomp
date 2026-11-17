# readability/

Tools for the readability phase (Level 1: names, labels, fields, globals, constants, comments). The models
only *propose* names, as JSON. These scripts apply the names and prove the code did not change. Background:
the readability review (recommendations 1, 2 and 5, §5 R0).

Run them from a decomp repo checkout (eq-trilogy or a worktree), with `..\.venv\Scripts\python.exe`.

| tool | what it does |
|---|---|
| `registry.py` | One table per client (trilogy, eqgfx, eqmain, titanium): VA → canonical name. Built from the `// FUNCTION:` definitions, fixtures' `"function"`, the queue, `names/*.csv` and `#define`s, plus each VA's spellings. Reports conflicts: `define_names`, `spelling`, `queue_fun`, `queue_differs`, `fixture_differs`, `csv_unapplied`, `ann_dup`, `name_dup`, `macro_shadows`. `--out DIR` writes `<client>.tsv` and `<client>.conflicts.tsv`. |
| `rename.py` | Renames a function, a VA global or a local/label everywhere it lives. Covers definitions, uses, headers, `#define` bodies, call macros derived from the old name, fixtures (`function`, `rewrite`, callers' `callees[VA].name`), the queue entry and `names/<names>.manual.csv`. Uses C tokens, so string literals are never touched; comments get only code-like names. `--dry-run` lists every edit; `--map` applies a JSON list; `--journal` records what was done for the gate. |
| `gate.py` | The Level-1 gate (T0): every TU the edit touches compiles to the same code as on the base commit. It uses one shared match header and compares the objects function by function. It also checks that both builds compile, that no new C4005 appears, that source_checks counts per unit don't rise and markers/comment words don't fall (below), and it lints the fixtures. A retyped prototype (decorated name changed: `?f@@YAXH@Z` -> `?f@@YAXJ@Z`) is journaled (`protolink.py`, `--protos`/`--journal-out`) so callers compare as the same target; when anything is journaled or a definition is added/removed, a link check resolves the symbols over the changed TUs and every TU of that client naming them (LNK2005 duplicates, LNK2001 unresolved, C/C++ linkage mismatches). No fixtures are run, no mutation, no original binary. |
| `class_views.py` | Titanium class views: every struct/class with the vtable/ctor/dtor/method VAs its TU gives it, its layout (cparse), and the VA families (one VA under several view names). `family VA`, `view FILE NAME`, `aliases` (the structs_alias.tsv table). |
| `class_rename.py` | Titanium class, VA-family and field renames: `class FILE OLD NEW` (one TU's view: tokens, markers, decorated names, the TU's fixtures, crt_defaults twins), `family VA NEW` (every view of a family, one per TU), `field FILE CLASS OLD NEW` (typed member accesses; the same offset in the sibling views). `--gate` like rename.py. See "Titanium" below. |
| `match_gate.py` | Titanium's gate: `compare.py --match` of the touched TUs before and after an edit, plus the fixtures of the renamed functions and their callers. See "Titanium" below. |
| `passes.py` | Report only: what the scripted passes (a) spelling, (b) csv names, (c) address calls/globals → names, (d) HWM opcodes and (e) duplicate defines would change. |

## Typical use

```
cd eq-trilogy
..\.venv\Scripts\python.exe tools\readability\registry.py --out ..\build\readability\registry
..\.venv\Scripts\python.exe tools\readability\rename.py -c eqmain 0x10009080 WrapTextIntoLines_guess --dry-run
..\.venv\Scripts\python.exe tools\readability\rename.py -c eqmain --map proposals.json --journal renames.jsonl
..\.venv\Scripts\python.exe tools\readability\gate.py --base main --renames renames.jsonl
```

In a scratch copy the gate's default `--base HEAD` compares the working tree with the copy's own commit. By
hand on a readability branch, pass `--base main`. The before builds are cached under
`<build>\readability\before\<base>\<header>`, so a second run only compiles the after side: about 5 s per
TU on 2 workers. Exit codes: 0 pass, 1 fail, 2 setup problem.

## Titanium (`-c titanium`)

eq-titanium is C++ built with VC 7.1. Each TU declares its own view of the classes it uses, so one function can
have a different name in every TU that calls it. The tools find the client from the repo's
`tests/unicorn/conftest.py` (`PRIMARY = "titanium"`); `registry.py --client all` lists only that repo's clients.

```
cd eq-titanium
..\.venv\Scripts\python.exe tools\readability\registry.py --client titanium --out ..\build\readability\registry
..\.venv\Scripts\python.exe tools\readability\rename.py -c titanium 0x0042429E NextPrime_guess --dry-run
..\.venv\Scripts\python.exe tools\readability\rename.py -c titanium --map m.json --journal j.jsonl --gate
..\.venv\Scripts\python.exe tools\readability\driver.py run --client titanium --tu src/EverQuest/tu_016.cpp --stage fn --out OUT --dry-run
```

- **registry**: reads `// FUNCTION: TITANIUM`, the `include/titanium` headers, `// EXTERNAL: TITANIUM` markers
  (sightings `external`) and the `rewrite_aliases` of `tests/unicorn/crt_defaults.json` (sightings `alias`).
  `FUN_<va>_guess` counts as unnamed.
- **rename.py** decides by VA which files to change. A file is renamed when it defines the VA, has a marker for it,
  or names it in an EQ_* macro. A file that gives the old simple name to another VA is left alone; a file that
  does both is refused. Each caller's own spelling follows too: `FUN_0042429e_guess` for `FUN_0042429E_guess`
  (another C++ identifier), and the file's own view name (`--keep-views` keeps view names): a free function's
  (`FindCapacity_guess`), and a member's (`View::Update_47CB5F_guess` becomes `View::NEW`: one name per function
  everywhere; the view class keeps its name). A member view is kept, and noted `kept view name ...`, when the
  token swap would not be exact: NEW already occurs in the file or its headers (another member of the view, say),
  the old view name is declared by another class of the file, qualified by another class, used unqualified
  outside the view's bodies and member functions, spelled in a preprocessor line or a header, or the view is in a
  header; a member view name kept in one file is kept in every file, so its fixture aliases stay consistent.
  The marker is renamed with the code, even with `--no-comments`. Fixtures are matched by VA: the own fixture's `function` and `rewrite` (decorated names too),
  `callees[VA].name` in every fixture, and `rewrite_aliases` keys whose value is the VA, `crt_defaults.json`
  included. The queue `name` follows. Titanium has no `names/*.csv`. A decorated name (`?Old@Cls@@QAEXH@Z`)
  is edited as text. The rename is refused when the new name would need an MSVC back-reference
  (`PAUNew@@`, `U0@`).
- **Gate** (`--gate`, or `match_gate.py snapshot`/`check`): compare --match of the touched TUs before and after
  (the TUs that include a touched header, and the sources of touched fixtures, count too). Every function
  identical before must stay identical; nothing may get worse, appear or disappear. Then the fixtures of the
  renamed VAs, of their callers and of the touched fixtures run. On a failure every file is restored byte for
  byte. A `--map` that fails is bisected (`match_gate.bisect`): its halves are gated in map order on top of what
  was kept, a passing half is kept whole, and a half after a passing one is split without its own gate (the
  failure must be there); one bad item in n costs about 2*log2(n) gates instead of n.
  Verdicts are cached under `<work>/results` by the content of the whole tree (sources, headers, tests/unicorn
  JSON), the tools' code, the binary and the TU, so the before side of each bisect step (a tree just compared)
  is free; each TU is compared on its own (`match_gate.py _compare`, one process, one MatchContext) so a verdict
  does not depend on which TUs shared the call, and objects are cached under `<work>/objs` by the source, every
  header and the EQD_MATCH header, so an unchanged TU is not compiled again (nor waits for the compiler lock).
  TUs whose edit is inert are not compiled (`match_gate.inert_changes`, the verdict's notes list them): a source
  whose code tokens, line numbers and directive comments (`// FUNCTION:`, `// EXTERNAL:`, `CFLAGS:` lines) are
  unchanged ("comments only"); a source whose only other change is the name of `// EXTERNAL:` markers that no
  identifier of the source or its headers spells ("unreferenced marker": a marker maps an object's symbol by
  name, and the object can't reference an unspelled name); a TU in only because it includes headers whose edit is
  comments only. A marker the code uses, any code token, a preprocessor line, a header with a code edit, a
  changed fixture's sources and new or renamed files are always gated. `EQD_GATE_COMPARE=batch` gives the old
  single compare.py call without the cache. `GATE-REJECTED old -> new: why` lists what was dropped,
  and only kept renames reach `--journal`. Work files go under `<build>\readability\titanium`, not compare's own
  folders. Set `EQD_COMPILE_LOCK` to share the compiler slot with other runs. `gate.py` in a Titanium repo hands off to
  `match_gate.py check --base`.
- **class_rename.py** renames types, which rename.py does not: a TU's class view (`class`), every view of a VA
  family (`family`: the views carrying one vtable/ctor/dtor VA, from class_views.py; a TU with two views of the
  family, a header class or a TU where the new name is taken is noted/refused, not renamed) and a data member
  (`field`: typed accesses only; the same-offset, same-size own member of each sibling view follows unless
  `--no-family`). Decorated names change with the class (`?F@Old@@...`), so every rename is gated like a code
  change (`--gate`, same match_gate, bisected on a failure; journal kinds `class`/`field`).
- **driver.py** `--client titanium` runs the fn stage with `rename.py --gate` as its gate. `--dry-run` makes no
  model call: it writes the prompts, and `apply` validates an existing `BATCH.answer.json` through
  `rename.py --dry-run` without writing anything. The comment stage is not gated on Titanium yet.

## Rules the tools enforce

- **One match header for both builds.** It is generated from the VA tokens of *both* trees. When the header
  differed between the builds, a function's code moved on its own (00428686 ndiff 37/47/77). A VA written
  in another letter case compiles to the same code and passes.
- **Symbols are keyed by what they are, not how they are spelled:**
  - `eqd_fn_/eqd_va_` by VA;
  - the TU's functions by their annotated VA;
  - statics and strings by section and offset;
  - other symbols by name, after the renames (from the TUs' annotations on both sides plus `--renames`).
- **Litter is ignored.** `.check/` output, `__pycache__` and build files are not "changed files".
- **A marker or identification word that disappears fails.** Per unit (source_checks notes): `@early-stop`-style markers,
  `fake match` comments (`/* fake match */` blocks and each line of a `// fake match:` note), `as original` notes, and the
  words zlib, `__cdecl`, `__thiscall`, `__fastcall`, `__stdcall`, `EAX`, `Returns` in comments. A dropped one hides an oddity
  or a lost fact (the comment pass lost them and the gate did not notice).
- **A TU that differs only under the shared header gets a second look.** The union header can move one function's code on its
  own (1005FCB3, 00428686). When the only difference is under the union header, the TU is rebuilt with each tree's own
  generated header; if both sides then compile to the same code it passes, reported as `header-sensitive, own-header PASS`.
  Any difference under the own headers still fails.
- **source_checks compares counts per unit, not label text.** A renamed goto label or unused local keeps
  the same count. An unannotated unit is matched by name after the renames.
- **rename.py refuses (exit 2, nothing written):**
  - a new name that is a `#define` name anywhere: a macro named like a function rewrites its definition;
  - an existing identifier in the touched files (`--allow-existing` overrides this one);
  - an ambiguous simple name;
  - a new C4005 clash in a file;
  - a local that a `#define` body names (e.g. `roll` in `CCI_PICK_CITY`): it would compile but point at
    nothing.
  - a local named like a file-scope name of the file or its headers (types, globals, prototypes, enum
    constants).

## Pilot check (eq-trilogy main eda8c086, scratch worktree)

The pilot TUs were EQ_Character.cpp, unit_10008D60.cpp and unit_1000650E.c. Nine renames were applied:
- 3 functions: a member declared in `eq_character.h`, a `_guess` function, and a `FUN_` one whose
  `EQGFX_FUN_*_GUESS` call macro followed;
- 1 VA global (`PTR_SetTextColor_guess`, defined in two eqmain files);
- 3 goto labels;
- 2 locals: Ghidra's `param_1` and an unused local.

The gate built 7 TUs (the header pulled in EQSwitch, EQ_Character_MagicSystem and EQ_PC) and found 273
functions unchanged: PASS. The reverse map also passed.

Negative controls on the same files:
- a changed constant: FAIL, naming 10009080;
- a redefined macro: FAIL, C4005;
- one more cast: FAIL, source_checks `cast 21 -> 22`;
- a VA in lower case: PASS.

A tenth rename was refused: `roll` in FUN_0042a26f. The gate had first shown it breaking the build
(`C2065`) because `CCI_*` macros use that local.

## Known limits

- **Function renames replace the simple identifier in every file of the client.** A struct field or local
  with the same spelling would be renamed too. The gate catches any code change this causes, and the rename
  is refused if another function has that simple name.
- **The `_GUESS` suffix of derived macros follows the new name.** The round trip `EQGFX_FUN_X_GUESS` ↔
  `EQGFX_NAME_GUESS` is symmetric. Macros not derived from the old name are listed and kept; merging them is
  pass (e) (`--unify-defines` on a global).
- **Renaming a local to a plain word (`rows`) updates code, not prose.** Renaming it back leaves comments
  that already said "rows" alone. A comment that said `param_1` keeps "rows".
- **Ghidra is not updated here.** Run `ghidra/scripts/apply_names.py <client>` after a wave: rename.py
  writes `names/<names>.manual.csv` rows (`_guess` → `low`, else `certain`).
