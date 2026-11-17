# FIXTURES.md: writing a Titanium fixture (functional mode)

A fixture runs the original function and your rewrite side by side in an emulator, from the same memory, and compares
everything a caller can see: return value, writes to memory, calls made (target and arguments), ESP and the saved
registers. Full format: `FIXTURE_FORMAT.md` in this folder (search it; don't read the tools folder); examples:
`tests\unicorn\EverQuest\**\*.json`.
- A call argument or `this` that points into the stack (a local's address) is compared as `<stack>`: frames differ
  by a few bytes and that is not behaviour. To compare what the local holds, type the arg `"mem:N"`.
- Don't seed `ExceptionList` (TEB `0xFFDFF000` / `fs:[0]`): the emulator sets it up; a fixture write there faults.

Commands (only these): `.\fixture.bat fixture 0x<VA>` (skeleton), `.\fixture.bat test 0x<VA>`,
`.\fixture.bat mutate 0x<VA>`, `.\fixture.bat coverage 0x<VA>`.

## Filling the skeleton
- `objects`: one per pointer the function follows (`this`, pointer args, pointers stored in fields), sized from the
  struct (`"size": "0x264"`), `"fill": "random"`. Link them with `init`: `{"offset": "0x10", "u32": "@other"}`.
- Fields that decide branches: set them per case (`"memory": [{"addr": "@obj", "offset": "0x260", "u32": 5}]`) and
  vary them in `fuzz.memory` (`{"addr": "@obj", "offset": "0x43c", "type": "int", "choices": [...]}`).
- Cases: every branch, both sides of every comparison (12 and 13 for `<= 12`), empty and full loops, null pointers
  only if the original checks them. `fuzz`: 50-200 extra cases.
- Callees: the skeleton guesses them from the export, often wrongly. Read each call site: ECX set = `thiscall`;
  `ret N` / no `add esp` after the call = callee pops; arg types `int u32 ptr cstr char bool float double ignore`.
  Pointers into the caller's stack frame: `ignore` (frames may differ). Give `ret` (one value, or a list per call),
  and `writes` when the caller reads what the callee wrote. A `warning:` about stack purge means the stub is wrong.
- Strings: `cstr` args are allocated for you; `{"addr": "0x0095D3D4", "cstr": "text"}` seeds a global buffer.

## What the emulator cannot do, and what to do instead
1. CRT that needs per-thread data: `atoi`, `atol`, `_stricmp`, `_strnicmp`, `isdigit`/`isspace`/..., `strtol`,
   `sprintf`. Never `passthrough`: script them in `callees` with a `ret` per call
   (`"0x0060e3a3": {"name": "atoi", "args": ["cstr"], "ret": [12, 0]}`). strlen/strcpy/strcmp/memset/memcpy already
   run natively by default; don't list them.
2. Globals start as the file's contents (mostly 0): seed every global the function reads
   (`{"addr": "0x00905d24", "u32": "@manager"}`), and pointer globals to fixture objects.
3. Virtual calls: point the object's vptr at a fixture table (`"init": [{"offset": 0, "u32": "@vtbl"}]`, `@vtbl`
   holding `"@fn_slot3"` at offset 12) and key the callee `"@fn_slot3"` with conv `thiscall`.
4. Exceptions: `throw` calls `_CxxThrowException` (key `0x0060e27f`, `"conv": "stdcall"`, `"args": ["ignore", "u32"]`,
   `"noreturn": true`); add `"rewrite_data_aliases": {"__TI2?AU<Type>@@": "0x<ThrowInfo VA from the original>"}`.
   `catch` blocks and unwind code never run: list their block range in `coverage_ok` with the reason, and name
   mutants inside them in `_survivors`.
5. Dead code (an `int3` bounds check the loop can never reach): `"coverage_ok": {"0040E794-0040E795": "why"}`.
6. The stack starts zeroed: a deleted `buf[0] = 0` before a callee that may not write `buf` can't be seen; say so
   in `_survivors`.

## Survivors
`mutate` changes your rewrite one edit at a time; each change must make some case fail. For a survivor, first add a
case that catches it. Only if no input can tell the two apart, explain it in the fixture:
`"_survivors": "L154: remaining == 2 is unreachable (40 - trunc(1.5*x) never equals 2); L727: dead bounds check"`.
Every survivor's line must appear as `L<line>`, or the runner refuses the landing.

## Never
Change a case's expected behaviour to match your rewrite, delete a failing case, edit tests\unicorn\conftest.py,
crt_defaults.json or another function's fixture, or set `"defaults": false`. A failing case means the rewrite is wrong.
