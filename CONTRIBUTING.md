# Contributing

Thank you for helping. This project lives or dies by where its material comes from, so the provenance
rules come first; a change that breaks one of them is rejected however good the code is.

## Provenance rules

1. **No original bytes.** Do not add game files, binaries, DLLs, memory dumps, disassembly listings,
   Ghidra/IDA/BinDiff projects or exports, or bulk copies of the client's code or data, in any form (hex,
   base64, arrays). Inline assembly is only for code the compiler cannot reproduce. Fixtures that need
   original data reference it by address (`"from_image": "0x..."`) and the harness reads it from the user's
   own binary.
2. **No decompiler output.** Do not paste Hex-Rays, Ghidra or other decompiler output, from this client or
   any other build. Write the function yourself from the evidence; the decompiler is a reading aid.
3. **No leaked or unlicensed source.** Never use leaked Sony/Daybreak source. Do not paste code from GPL or
   unlicensed projects (EQEmu, ShowEQ, MacroQuest, EQClassic, TAKP and others): this repository is MIT. They
   are **evidence only**: facts such as offsets, opcode values, addresses and names may be used and are
   credited in `docs/ATTRIBUTION.md`; their code may not.
4. **Names say where they come from.** A name that is inferred rather than known carries the `_guess` suffix.
5. **No connection to live servers**, and no code meant to cheat, bypass protection or attack anyone.

By opening a pull request you confirm that your contribution follows these rules and that you have the right
to submit it under the repository's licence. The maintainers may reject or remove anything whose origin is
unclear.

## How a change is checked

You need the setup from [BUILDING.md](BUILDING.md): your own `eqgame.exe` and Visual C++ .NET 2003 (7.1). Run
`tools\doctor.py --repo-name eq-titanium` first.

- **A new or changed function**: annotate it (`// FUNCTION: TITANIUM 0x...`), add or update its fixture in
  `tests/unicorn/EverQuest/`, and run it:
  `..\.venv\Scripts\python.exe -m pytest tests\unicorn\EverQuest\<folder or file>`.
  Then the match check (`tools\compare\compare.py --repo . --client titanium --match <file>`). Say in the pull
  request what still differs, if anything. The rules for writing and marking code: `tools/docs/RULES.md`.
- **A rename, comment or other change that must not change code**: run the readability gate
  (`tools\readability\gate.py`, see `tools/readability/README.md`); it compiles every touched file before and
  after and fails on any difference.
- **Before a pull request**: the fixtures of every file you touched, and `tools\compare\source_checks.py`
  (status markers, fake-match oddities; it also lists existing violations, so only new ones in your files
  matter).

The fixtures and compare need the binary and the compiler, so run them locally and state the result in the
pull request. GitHub CI runs only what needs neither: `python tools/ci/check_tree.py .` (forbidden files,
local paths, annotation format, fixture shape); run it before pushing. When a function will not match,
[docs/VC71_QUIRKS.md](docs/VC71_QUIRKS.md) lists the compiler's known patterns.

## Style
- Literal translation over cleanup; keep the original's types, statement order and code shape.
- Fake matches only in the allowed forms, always marked (`tools/docs/RULES.md`, "Fake matches").
- One topic per pull request; small is better.
