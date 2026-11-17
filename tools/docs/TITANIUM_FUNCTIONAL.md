# Titanium functional tests (Unicorn)

The trilogy harness runs eq-titanium unchanged: VC7.1 (`[toolchain] vc71`), `/O1 /GS /GX /Gy` from each TU's
`// CFLAGS:` line, annotations `// FUNCTION: TITANIUM`. Proven 2026-11-07 on 12 fixtures (9 identical, 3
`rewritten`), all with mutation checks. A fixture shows a rewrite *behaves* like the original; bytes may differ.

## How to fixture a function (from the eq-titanium checkout)
```
tools\unicorn\tools\make_fixture.py titanium 0x0042510E [--run]   skeleton -> tests\unicorn\EverQuest\tu_018\<Name>.json
python -m pytest tests\unicorn\EverQuest\tu_018                    run (conftest.py: client titanium)
tools\unicorn\tools\mutate_check.py --va 0x0042510E                mutants of the rewrite must fail
```
- `tests/unicorn/crt_defaults.json` serves compare and the harness: `rewrite_aliases` (DLL symbol -> client VA:
  `__EH_prolog`, `@__security_check_cookie@4`, `__ftol2`, std helpers), `rewrite_data_aliases` (DLL data -> client
  VA: `___security_cookie`, globals; the harness now patches the DLL's relocated references) and harness-only
  `callees`: `__EH_prolog`/`__ftol2` passthrough, the /GS check a fastcall stub recording ECX (the cookie),
  `_chkstk` a probe, the pure string/memory CRT (strlen, strcpy, memset, ...) passthrough.
- A `throw` passes the TU's ThrowInfo: alias it per fixture, `"rewrite_data_aliases": {"__TI2?AU<T>@@": "0x<VA>"}`.
- Test DLLs link with `trap_unresolved`: TUs are byte-match units that compile but were never meant to link
  (declared-only classes still get vftables); a missing symbol is an int3 trap, a call to it an unscripted callee.
- Write `_shape` and `_survivors` (why a survivor is equivalent) into the fixture; `coverage_ok` for dead blocks.

## What the harness cannot emulate yet
1. **C++ exception unwinding.** `__EH_prolog` frames and `fs:[0]` registration run fine (passthrough), but nothing
   dispatches a throw: `_CxxThrowException` must be `noreturn`, `catch` blocks and unwind funclets never run
   (0x00426A3C: the catch block is `coverage_ok`, its two mutants survive). Needs `__CxxFrameHandler` + RtlUnwind.
2. **MT CRT per-thread data.** VC7.1 LIBCMT `atoi/atol`, `_stricmp/_strnicmp`, `isxxx`, `strtol`, `sprintf` reach
   `_getptd` (TlsGetValue/GetLastError) and locale state that no run initialises: stub them per fixture (scripted
   `ret`), never passthrough. Fix: a fake per-thread-data block + kernel32 Tls* stubs, or CRT init once per image.
3. **Uninitialised stack is zero.** Deleting `buffer[0] = 0` before a callee that may not write the buffer
   survives (0x00408E74). Random-filling the stack below ESP per case would catch it (harness-wide change).
4. **Virtual calls into .rdata vftables.** A call through a client object's vptr needs a fixture vtable with
   `"@fn"` slots; real `.rdata` tables (0x0063F4F0, ...) point at client code the fixture must script by VA.
5. **Globals needing init.** `.data`/`.bss` are file contents: `pEverQuest`, `pCharData`, the managers at
   0x00905D24 etc. are 0 until a fixture seeds them (`memory`). No runtime snapshot exists for Titanium yet.
6. **Callee prototypes.** make_fixture takes Titanium callee conventions from the export (often `cdecl, 0 args`
   for thiscall/fastcall helpers); check each against the call site. The purge check warns on mismatches.
7. (Fixed) Worktrees not named `eq-titanium` take the image from their conftest's `PRIMARY` (`image_of_source`).
