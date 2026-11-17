# Titanium byte-match notes (verified facts only)

Every line here was checked on this binary with cl 13.10.3077. Compiler quirks with repros: `VC71_QUIRKS.md`.

## Find your rule from the first difference
Look up the first differing line of `compare.py --match` here, then read only that section.

| first difference looks like | read |
|---|---|
| `F:_name` in your listing | Referring to the rest of the client |
| `push ebp; mov ebp,esp` only in the original, no locals | Frames: "bare EBP frame" below, then "Frames that come from classes" |
| `mov eax,[0x79AC74]` (cookie) only on one side | Frames: /GS; "Cookie in one build only" below |
| `call 0x60D5A8` / `[ebp-4]` state stores on one side | Destructors; the `~T();` rule |
| same instructions, registers swapped (ESI/EDI, EAX/ECX) | "Register roles" below, then "Shapes that look like register luck" |
| same instructions, two lines in another order | "Causes behind repeated match failures" (sinking, hoisting, arm-call hoist) |
| status `normalised` (ndiff 0, bytes differ) | "normalised" below |
| `pop ecx` vs `add esp,4`, or a register kept across a call | Same-file effects |
| `jcc` sense or block order | Block order rule in "Causes behind repeated match failures"; switch rules |
| `lea r,[x+N]` vs `[x+N]` folded | loop accessor / member spelled twice rules |
| `call [IAT]` or Win32 API | "Win32 calls" below |
| EDX vs ECX for a temporary, ECX never loaded before a call | "Rules from the second review pass": callee is a member |
| `[ecx+eax+N]` vs `[eax+ecx+N]` (base/index swapped) | "Rules from the second review pass" (named array reference), then "normalised" |
| a store and a load around the argument pushes in another order | "Rules from the second review pass" (array pointer, one global object) |
| `push 1` / `mov ecx,r` swapped before `call [eax]` | "Rules from the second review pass" (`delete`) |
| the original starts with `[ebp-N]` use or ends `leave` with no frame setup | "Not a function" below |
| `add eax,0xFFFFxxxx` (a negative immediate) vs `sub eax,K` / `sub eax,reg` | "Rules from the hand pass" (constants) |
| `and eax,M; add eax,C` with the wrong `M` or `C` | "Rules from the hand pass" (two-value ternary) |
| `sub al,cl` (8-bit) vs `sub eax,ecx` | "Rules from the hand pass" (char result) |
| a clear loop ending in `int3`, or std::string / ostringstream code | "Rules from the local probes" |
| `push 0x6xxxxx` (a literal) differs, everything else matches | "Rules from the hand pass" (read the string) |
| `mov eax,[x]; lea edx,[ebp-4]; push edx; push eax` vs `lea; push; push dword ptr [eax]` | "Rules from the hand pass" (iterator by value) |
| `shr eax,1; not al; and eax,0xFFFFFF01; push eax` | "Rules from the hand pass" (`bool` argument) |

## Never land these (they match bytes but are not source; a lint will refuse them)
Counted at review time (2026-11-03); each one is a later cleanup job.
- `throw()` on a declaration (61 uses in 25 files, 0 with the required comment). Use the `~T();` rule; if it still
  needs `throw()`, defer with slug `inline` and say so in the note.
- Dead code that changes code generation: `if (0) { jmp_buf b; setjmp(b); }` (10 functions, tu_013 and tu_144).
  It only forces an EBP frame (same code as building with `/Oy-`). See "bare EBP frame".
- `__assume(0)` after a call or `__debugbreak()` (6 uses). Use `__declspec(noreturn)` on the callee.
- `(char*)this + N`, `reinterpret_cast<T*>(reinterpret_cast<char*>(this) + N)`, `(char*)p + N` (about 35 uses):
  declare the member at offset N.
- A vtable stored by hand: `*(void**)this = EQ_ARRAY(...)`, `vtable_guess = EQ_ARRAY(...)` (8 uses). It is a ctor or
  dtor of a class with a marked vtable.
- Comparing an address with a literal: `while ((int)&entry->f < 0x0079621C)`. Use `EQ_ARRAY(T, start)` and a count or
  an end pointer `EQ_ARRAY(T, end)`.
- Win32 functions called through `EQ_GLOBAL` function-pointer typedefs at their import slot (62 typedefs in 10 files).
  Call them by name; see "Win32 calls".
- `__fastcall` on a function whose only register argument is ECX (33 definitions): that is a member function. Write
  `struct X_guess { void F(); };`. `__fastcall` is right only when EDX carries a second argument.
- `&= 0` to get `and dword ptr [m],0`: plain `= 0` compiles to the same `and` at /O1 (probe, both with and without a
  zero register live). Write `= 0`.
If only a lever gets `identical`, leave the honest best version in the file and defer with the slug that fits and a
note starting `lever:` naming it. A deferred function goes to a stronger pass with your note; a lever does not land.

## New rules from match results (2026-11-03 review)
- Bare EBP frame: the original has `push ebp; mov ebp,esp` and addresses parameters as `[ebp+8]` with no locals, your
  build uses `[esp+N]`. First try the parameter-naming rule under "Frames that come from classes" (name the parameter
  in each branch; do not cache it in a local). Known cases where nothing honest has worked yet: 0x00416F99-0x0041716C
  (tu_013, 9 of 10 adjacent functions framed, 0x0041716C not), 0x00417023, 0x004F6F9E. After two tries, defer with slug
  `layout` and note `frame-pointer kept`.
- Cookie in one build only: the original has no cookie but a buffer of 8+ bytes, so it was not a `char` array: write
  `int buf[N/4]` or a struct of ints (seven recorded fixes, e.g. two `char[12]` → `int[3]` matched a 24-byte frame). The
  original has a cookie and your frame is a few bytes short: the buffer is bigger than its use (a 260-byte buffer, not 256,
  matched 0x0042DE64); size it from `sub esp` minus the other locals.
- Win32 calls: `#include <winsock2.h>` then `#include <windows.h>` at the top and call the API by name. The compare maps
  `__imp__Name@n` to the import slot. Two calls of one API in a function give `mov edi,[import]; call edi`, which the
  `dllimport` declaration reproduced; a function-pointer `EQ_GLOBAL` gives two `call [m]` instead (recorded fix,
  FindFirstFileA).
- `normalised` (same instruction text, different bytes): the encoding differs. Known causes: base and index swapped in
  `[a+b+N]` (see the bounds-checked loop rule), a `jmp` after `int3` that the original lacks, a short vs long branch from a
  different block size elsewhere. Look at the bytes in the context file; if none of these, defer with slug `tiebreak` and
  note `normalised`.
- Register roles: two values in ESI and EDI (or EBX/EDI) swapped against the original. Try, one per compile: (1) swap
  which value is assigned first, (2) swap the declaration order of the two locals, (3) for parameters, use them in the
  other order in the first statement. If three tries do not move it, defer: about a third of the recorded
  failures are this shape and more tries rarely fixed it.
- Not a function: the assembly starts using `[ebp-N]` or `fs:[0]` with no `push ebp`/`__EH_prolog`, or ends `leave` with
  no frame setup. It is the tail of another function (export boundary). Write nothing; defer with slug
  `compiler-generated` and the note `fragment of <caller VA>` (12 queue entries, for example 0x00403510, 0x00426622).
- Float to a `double` parameter: `push ecx; push ecx; fstp qword ptr [esp]` is the conversion at the call, not two
  arguments.

## What counts
`compare.py --match` reports `identical` only when the instructions and every byte outside relocation fields equal the
original, and every call and global resolves to the original's address. That is the whole test: there are no
fixtures. String literals and float constants may be plain literals; they are compared by content. `normalised` is not a pass.

## Source form
- One `// CFLAGS:` line at the top, never changed: `/O1 /GS /GX /Gy /MT /GR-` is proven for game code.
- Each function has `// FUNCTION: TITANIUM 0x<VA>` on the line above its definition, ascending by address.
- Types are local to the file (`struct Thing_guess { ... };`, field offsets in comments), except what the shared
  headers in `include/titanium/` declare: see "Shared headers" below.
- `__thiscall` is not a usable keyword (vc71q-thiscall-keyword). A normal member function gets `this` in ECX and
  cleans its own stack arguments. So a function reading `[ecx+N]`, ending `ret N`, is a member of a `_guess` struct.
- `__cdecl` / `__stdcall` free functions are spelled as usual; `__stdcall` ends `ret N` with no ECX use.

## Referring to the rest of the client
- A function: declare it and mark its address on the line above the declaration; the plain call then compiles to
  `call rel32` and is checked against that address:
  ```cpp
  // EXTERNAL: TITANIUM 0x00464FF8 FillText_guess
  void __cdecl FillText_guess(const char* input, char* output);
  ```
  Members the same way, inside the class, with the qualified name:
  `// EXTERNAL: TITANIUM 0x004A02E5 Item_guess::Item_guess`.
  A vtable: `// EXTERNAL: TITANIUM 0x00535430 ??_7Item_guess@@6B@` (the decorated name).
- A global: `#include "titanium/eqaddr.h"` is in the file. `EQ_GLOBAL(int, 0x00850CCC)` is an lvalue,
  `EQ_ARRAY(char, 0x00850CCC)` a pointer. Give it a name:
  `#define g_thingCount_guess EQ_GLOBAL(int, 0x00850CCC)`.
- CRT functions keep their real names: `#include "titanium/crt.h"` (markers at the real VAs). 0x0060D0D5 is
  `operator delete` (write `delete p`; 91 landed files call it `free`: bytes right, name wrong), 0x0060D682 `delete[]`,
  0x0060D071 `new`, 0x0060E985 `new[]`, 0x0060E07D `free`, 0x0060E3A3 `atoi` (not atol). A file that already declares
  a CRT function itself keeps that and does not include `crt.h`.
- In the diff, `F:<hex>` is a client function by address. `F:_name` is a symbol the tool could not place, which
  means a missing `// EXTERNAL:` marker or a wrong declaration.

## Shared headers (include/titanium; checked 2026-11-03, whole-repo compare unchanged with them)
- In new or edited code `#include "titanium/types.h"` (pulls `core_decls.h`) for listed client functions and layouts
  (EQPlayer, EQ_PC, CEverQuest, CXStr, CXWnd, CListWnd, CSidlScreenWnd, 50 windows), `#include "titanium/crt.h"` for
  CRT/new/delete. Landed files keep their local declarations; don't change declarations of code you aren't editing.
- If a callee's VA is in `core_decls.h`, use that declaration and class, e.g.
  `pEverQuest->dsp_chat(pStringTable->getString(id, 0), color, 1)`; no local `_guess` for it, never redeclare a header
  class or function. Real arities: early-pushed arguments are the plain nested call (VC pushes the outer call's
  trailing arguments before evaluating the inner call, 0x00401B42).
- `__EH_prolog`, the cookie check, `__ftol2`, eh vector iterators are compiler-generated: never declare or call them.
- Header classes have no virtuals (vtable = field at +0). For a ctor, dtor or virtual override keep a local class with
  the slots. Window ctors: a local polymorphic base with markers for 0x005A3900 `(CXWnd*, const CXStr&)` or 0x005A3850
  (5 args), dtor 0x005A3100 and the vtable, then `((CSidlScreenWnd*)this)->GetChildItem(...)` (README recipe).
- `~CXStr` is inline; the compare maps its out-of-line calls via the alias `??1CXStr@@QAE@XZ -> 0x004482FB` in
  `tests/unicorn/crt_defaults.json`.
- If a header field type disagrees with movsx/movzx or fld/mov, say so in the note; don't cast around it. Open:
  `pCharData` is declared `EQ_Character*` with GetCharInfo2's base at +4, but EQ_PC (0x004BF2A7) reaches its
  virtual base through a vbptr at +8; trust the original's `lea ecx,[eax+4]` per site.

## Rules from the review passes (2026-11-03, each fixed the named function)
- Loop over members, not local copies of them (0x0047C3AF).
- `switch` arms each with the full call (all arguments): VC merges the tails (0x00494B3D).
- CXStr arguments: `push eax` right after the CXStr ctor = explicit `CXStr(text)` (the ctor's EAX is passed);
  `lea eax,[ebp-N]` before the push = implicit `const char*` conversion (0x004982C6, 0x004CAD26, 0x00547C3D, 0x0054EFB5).
- Clamp the variable in place, not through a temp (0x004106A3 ndiff 202 -> 103).
- Offsets into a sub-object through a vbptr: virtual bases, never `char*` offset levers (0x00416A40). A vbptr at +8 means
  an 8-byte non-virtual base comes first (0x00431C6B). Virtual-base ctors: a missing base-ctor call = two bases under one
  intermediate; a single `ret 4` parameter is the hidden most-derived flag (0x004BF2A7).
- Unfolded virtual-base access `lea eax,[vbase]; lea ecx,[eax+4]` = an inline method of the virtual base; a cast or
  reference gives a null check instead (0x004850A0).
- A class passed by value needs a declared copy ctor (0x0044B14A ndiff 27 -> 4).
- An inline float getter left of `*` with a call on the right gives a temp copy (0x0048A026).
- A jump table biased by one needs an explicit `case N: return default;` (0x00464E25).
- `delete p` right after a dereference of `p` drops delete's null test (0x004F949F).
- Classes that earlier rewrites split across several `_guess` structs: unify them into one so the same-file effect comes back
  (tu_095 vlong, 7 functions).
- Constants in a register are decided per typed constant: `mov al,0xff` byte stores appear only if the other 0xff stores
  have another type (0x004850A0).
- In-class inline members with float parameters or return are not inlined; a static free helper is (0x004850A0).
- Member-initialiser order: an address-taken local comes after the hash call; the EH `-1` store vanishes only with a
  visible nothrow inline cleanup (0x004850A0, 0x004849B2).
- `cmp eax, base+N; jl` over a global table needs a real array symbol (a data alias in `crt_defaults.json`);
  `EQ_ARRAY` gives a separate counter (0x004849B2, 0x00497395).
- Two stores through a member pointer with no reload = an inline method of the pointee; `push imm; pop reg` feeding two
  stores = a temp struct with an inline ctor (0x00536D26, 0x00516E9A).
- SIDL template inline accessor folds `or eax,[ecx+0x60]`; an extra `| 0x800` goes through a local (0x00516E9A, 0x0054EFB5).
- One loop counter declared before the buffer takes the dead parameter slot `[ebp+8]` (0x0056982F).

## Frames and patterns seen in this binary (game span)
- `/GS`: `mov eax,[0x79AC74]` at entry, cookie at the top of the frame, `call 0x60D674` at exit. It comes from a local
  char array (or a struct holding one) of 5 or more bytes, or a local whose address is taken in the right shape.
  Just declare the buffer; never write the cookie yourself.
- `call 0x60D5A8` (`__EH_prolog`): `/GX` frame from a local with a destructor living across a call. Write the local
  object with a declared destructor. No inline `fs:[0]` frames exist in game code.
- `(int)floatValue` calls `__ftol2` (0x60E98C).
- `push imm8; pop reg` instead of `mov reg, imm`: `/O1` size choice, nothing to do.
- A small helper is inlined at `/O1`. A call that exists in the original to a tiny function means that function was
  not visible to the compiler at that point: declare it with an `// EXTERNAL:` marker, do not define it.

- `int3` inside a function (a bounds or state check that traps) is `__debugbreak();`. It compiles without a header.
- A virtual call: declare the class with its slots in order (`virtual void Slot00_guess();` ...) and call the slot.
  `jmp [eax+N]` at the end of a function is a virtual call in tail position.
- A constructor stores its vtable after the base constructor and member initialisers. Declare the class and
  mark its vtable above it: `// EXTERNAL: TITANIUM 0x006519E0 ??_7Constructed_guess@@6B@`. Then the store compiles to
  the original's immediate. A destructor stores its own vtable first.
- A destructor with no EH frame that still calls member and base destructors: the member destructors' bodies were visible
  (header inlines) and only reach nothrow calls. VC then drops the EH state around them; this holds for the callee before or after
  the caller, and for one of several sub-objects inside a framed dtor (0x0054815C). Write `~T();`, not `throw()`. Define the callee
  in the file with its own `// FUNCTION:` line in address order, unless the item list shows that VA landed in another file (the landing would be refused: defer with slug
  `name-conflict` and name the VA); an `// EXTERNAL:` marker on a
  defined function leaves `call ?`. Its leaf calls must be nothrow: `delete[] p` with `#include <new>` and
  `// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z`, or `extern "C"` on `free`. A C++ `void __cdecl free` brings the frame back
  (0x004C9C05). A virtual call, `new`, a throwing helper (0x00405492) or an unseen function keeps it, in all 73 framed dtors checked.
  Only calls before the last matter: a lone member or base dtor ends in `jmp` with no frame and needs nothing (0x004D5B22).
  Fixed without `throw()`: 0x004C7A11, 0x004C9C05, 0x004F9DDC, 0x004FEC5F, 0x00523262, 0x0054815C, 0x0054C494. If the callee's body cannot be written, defer with slug `inline`; `throw()` does not land.
- A range check returning false with `xor al,al` is a `char` return; `xor eax,eax` is `bool`.

## Same-file effects (vc71q-same-tu-effect, real pair at 0x447B98)
A caller compiles differently when its callee is defined in the same file, before or after it: a value can stay in
a register across the call, and `/O1` cleanup of one argument is `add esp,4` for a same-file callee and `pop ecx` for
an external one. So a function can be unmatchable with an `// EXTERNAL:` declaration and match with the callee's body
in the file. Inline: a same-file static helper is inlined at `/O1`, also with a loop, and in-class methods too.

## Sizes and shapes at /O1 (probes, cl 13.10.3077)
- `x*3`, `*5`, `*9` use `lea`; `*7`, `*15` use `imul`. `/` by a constant uses `idiv` or `div`.
- Copy of 12 bytes: three `movsd`. 32 bytes: `rep movsd`. 16-iteration zero loop: `rep stosd`.
- `memset`, `strcpy`, `strlen` are calls, unless the original inlines them; 0.0f and 1.0f load from constants.
- Dense `switch`: a jump table from 8 cases, a compare chain below that. Case label order sets block order. An explicit
  `case 0:` keeps the table from being biased by one.
- `char` arrays of 8 or more get the cookie; `char[2..4]` do not; a `char[16]` in a struct does.
- Scalar locals: the first declared takes the lowest slot (`first=-12, second=-8, third=-4`). Buffers
  `first[32], second[64], third[16]` sit at `first=-52, second=-116, third=-20`.
- `new T()` zeroes a trivial `T`, `new T` does not. A destructible local across a call gets `__EH_prolog`.
- `while (count > 0)` on an unsigned exits with `jbe`, `while (count != 0)` with `je`.
- `return Tail(x);` is `jmp`. `(x & 0x20) != 0` gives `shr; and`, no `setcc`.

## Reading the asm as C++
- Register choice follows declaration and first-use order of locals and the order of statements.
- `movsx`/`movzx` give the field's signedness and width; `jl/jg` against `jb/ja` give signed against unsigned.
- `test r8,1` after `shr` is `(bool)((x >> n) & 1)`; `test r,mask` is `x & mask`.
- An argument evaluated before a call that is pushed after it means the original kept it in a temp.
- A byte store `mov byte ptr [..],al` of a compare result means a `bool` or `char` return or field.

## Frames that come from classes (each fixed real functions)
- `push ebp; mov ebp,esp; push ecx; and dword ptr [ebp-4],0 ... mov eax,[ebp+8]; leave` is a function returning a class
  by value, that class having a destructor (declare `~Str();`). The zeroed word is the compiler's flag, never a local:
  `Str Owner::Get() { return name; }` (0x004D91F5), `return At(field);`, `return g_db->Get(id, 0);` via `Str(const char*)`.
- `mov ecx,esp; mov [ebp-4],esp` (or `[esp+N],esp`) after `push ecx` builds a by-value argument: the callee takes a class
  with a destructor: `void Set(Str s, int a, int b);`, then `sink->Set(text, 1, 0)` (0x005614DD). Never write the slot.
- Overloaded ctors need decorated markers: `// EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z`
  (a shared `Str_guess::Str_guess` name maps to neither). 0x00407D68 copy ctor, 0x00571E00 `const char*` ctor of the
  game string class; `""` at 0x0063F53F is `EQ_ARRAY(char, 0x0063F53F)`.
- An EBP frame with no locals is a size choice driven by how often the source names its parameters, counted before
  the optimizer merges them: do not cache in a local. `kind == 1 ? a : b` in each branch got the frame (0x0040154F); one
  `int i = kind - 1;` lost it. Dead reads such as `(void)x;` do not count.
- A hidden return pointer with a 4-byte result and an EBP frame is an iterator class with a user copy ctor and inline
  operators: `It Find(It first, It last, const char& v) { for (; first != last; ++first) if (*first == v) break; return
  first; }` (`std::find` over `_Ptrit`, 0x0052D79C, 0x0052F8BE). Without the copy ctor a 4-byte class returns in EAX.

## Destructors (fixed 0x004258A7, 0x0049545E, 0x004C468D, 0x004CBE25, 0x005293C9)
- `push esi; mov esi,ecx; call dtor; test byte ptr [esp+8],1; ... free` is the compiler's `??_G`. Write it by hand as a
  member calling `this->T::~T();` then `if (flags & 1) free(this); return this;`. If VC inlines the dtor, the class is
  missing a member or base with a user dtor: `struct M { ~M() {} };`, `struct T { M m; virtual ~T(); };`, `T::~T() {}`:
  the dtor still compiles to the single vtable store, and now stays a call. A dtor ending `jmp <base dtor>`: derive from
  a base with `virtual ~Base();` and a decorated EXTERNAL `??1Base_guess@@UAE@XZ`. File order does not matter.

## Shapes that look like register luck (each fixed a real `tiebreak`)
- `dec eax; je; sub eax,6; je; dec eax; dec eax; je` is a `switch`, never an if chain (0x00417DAF). `sub ecx,eax` with
  EAX zero, then `dec`s: same, each case with its own body: `case 0: r = 1; break; case 1: r = 1; break;` (0x0043235E).
  Shared `case 0: case 1:` gives `test; jl; cmp` instead.
- A range check repeating its lower bound is the macro form, with the constant first: `min(0x60, max(4, v))` using
  `#define max(a,b) (((a) > (b)) ? (a) : (b))` (0x004C5007). Argument order changes the code.
- `mov ecx,[global]; add esp,N; test ecx,ecx` is not a stale compare: the global is the `this` of the next call:
  `if (g_obj != 0) g_obj->Refresh(a, b);` (0x00430304). Read what ECX is used for before picking a free function.
- `add ecx,N; push [ecx]; call` is a thiscall on a member object: `struct Sub { int head; void F(int, const unsigned*);
  void Add(const unsigned& v) { F(head, &v); } };`, `s.Add(v);` (0x00484909). `[ecx+N]` folded means `this` stayed outer.
- Never write a vtable store by hand: `*(void**)this = ...` lets VC fold the next virtual call to `call [vtable]`. It is a
  dtor: `inline Rc::~Rc() { if (--refs == 0) delete this; }`, inlined into `Rd::~Rd() { _free(buf); }` with the callee
  `extern "C"` so no EH frame appears (0x0044AD80, 0x0044B09C). `delete this` is `push 1; call [eax]`.
- `mov eax,ecx` at entry with stores through EAX is a constructor (it returns `this`), never `void Init()`: `C::C() {
  v[0] = 0; ... }` (0x0042E660). Repeating store groups are member ctors: `struct R { R() : a(0), b(-1), c(-1), d(0) {} }`,
  and a call first means a base: `T3::T3() : a28(0), ... {}`, `struct T3 : T2` (0x004B7451, 0x004B7470).
- `mov ecx,[global]; test ecx,ecx; push esi; mov esi,ecx; ... dtor; push esi; free` is `delete g_p; g_p = 0;` with a
  non-virtual `~T();` and `// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z` for `operator delete` (0x004B90CD, 0x004B6DB3).
  Same inside `if (p->refs != 0) { --p->refs; return; } delete p;` (0x004CA75F).
- A call that never returns ending a function with ECX kept live (`mov edx,[ecx+4]`, not `mov ecx,[ecx+4]`): the callee is
  a member: `__declspec(noreturn) void Fail();`, `T& At(int i) { if (i < count && i >= 0 && data) return data[i]; Fail(); }`
  with a real element struct for the `imul`, no `__debugbreak` or `__assume` (0x00432806; 0x00405492 is that `Fail`).
- `return *this;` from a member, copying through a copy ctor, gives `push ecx; mov ecx,[esp+8]; call copy` (0x004D9160).
- Both arguments loaded before the first push: keep the left one in a local: `const char* l = *a; return strcmp(l, *b);`
  (0x0056BF4F, 0x00567773). A read kept before a store: `int h = handle; r = v; if (h) ...` (0x004C503A).
- `a ? b : 0` and `if (!a) return 0; return b;` differ: `xor eax,eax` before a shared `ret` is the ternary (0x004CB2DD).
- A null test repeated with `jbe` after it is an inline accessor called twice, not a merged read:
  `unsigned Count() const { return p ? p->count : 0; }`, `if (Count() > 0) return Count() - 1;` (0x0044AD92).
- `lea eax,[esp+N]` at the top byte of a pushed slot is a plain `char c;` passed as `&c`, not a byte of `this` (0x004D73F2).

## Causes behind repeated match failures (each fixed the named failed functions)
- `ret` leaving a global or argument in EAX is a return value, also when nothing seems to use it. A `void` guess moves the
  zero and the arguments to other registers: `R* F() { if (!g) g = new R; return g; }` (0x00401022), `T* Copy(T* d, const T* s)`
  (0x0048A00B). `neg al; sbb eax,eax; neg eax` with `xor eax,eax` beside it is an `int` return, not `bool` (0x0044E79F).
- A value computed before a test and named once after it sinks past the test. Name it twice:
  `int i = h % count; ...; if (n) return n; int j = i + 1; if (i + 1 < count) for (; j < count; ++j) ...` (vc71q-single-use-sinks,
  all seven hash iterators: 0x00405697, 0x0042EC1A, 0x00446718, 0x00446788, 0x004FE51C, 0x0054BFEA, 0x005651BE).
- `mov ebx,edi; ...; lea ecx,[edi+N]; mov edi,[ecx]`, then stores through ECX, is a link pointer in a list walk:
  `E* c = p; unsigned h = c->hash; E** l = &p->next; p = *l; h %= count;` with `*l = 0` / `*l = f` (six hash `Rehash` clones,
  0x004467FB). `new E*[n]` / `delete[]` call `??_U`/`??_V` when `operator new[]` is declared, `??2`/`??3` when it is not (0x00490C98).
- `lea r,[this+N]` in the preheader with `[r]` re-read in a loop: an inline accessor of a member object in the loop condition:
  `while (q.Head())`, `i < c.Get()` (vc71q-loop-accessor-lea, 0x004C6059, 0x004F2B97). In an `if` it folds to `[esi+N]`.
- `lea eax,[esi+N]; cmp [eax],0; ...; mov eax,[eax]` with a 4-byte N: the member spelled twice, no local or reference:
  `if (x != 0) x->Slot();` (vc71q-member-spelled-twice-lea, 0x004FE582, 0x00547E07).
- `xor al,0xff; and eax,0xffffff01` is `!(b & 1)` on `unsigned char` (vc71q-bit-test-negate, 0x00541D4A, 0x004E8B1E).
  `~b` gives `not al`, `!b` gives `neg al; sbb`. Pass it straight to the call: a byte local added an EBP frame.
- Step-by-4 byte offsets, `cmp r,N*4`, or a pointer with a `dec` counter are usually a plain index loop that VC rewrote:
  write `for (i...) a[i]`, not the walk (vc71q-index-loop-reduction, 0x004054A8, 0x0042E63B, 0x00437B89, 0x00491373), nested too
  (0x004C934C, 0x004C941E, 0x0056AA54, 0x00454F3F). This fixed more failures than any other rule.
- `[eax+ecx+N]` in a bounds-checked loop over a member array, step 4: the access sits in the `else`, through the array's address:
  `if (o >= lim) { __debugbreak(); } else { ((W*)((char*)&v + o))->x &= 0; } o += 4;` (0x0040E776, 0x0045871F, 0x004BC5D2,
  0x004BE82F, 0x004BDC13). Decay `v + o` or an access after the `if` gives `[ecx+eax+N]`.
- Pushes before a `Jcc` with only the rest of the arguments in the arms: an `if`/`else` with a full call in each arm. VC hoists the
  shared pushes and merges the tails; a ternary gives `setcc` (vc71q-arm-call-hoist, 0x00454E75, 0x00452D85).
- A null test repeated after a call with the value kept in ESI: the callee is EXTERNAL and the first test reads the member:
  `if (a && cur) { N* n = cur; Adv(); if (n) return n->v; }` (0x0040CC1F, 0x0040CEA6). A same-file callee keeps it in EDX.
- `cmp r,K` ahead of stores it does not depend on, with the `Jcc` after them: the test reads the field just stored, no local:
  `f = *v; g = v[1]; if (f == K)` (0x004C334D).
- `mov ecx,edi` between `test` and `jne` in a loop: `this` of real member calls on both sides of the branch, in a `while`, not a
  `__stdcall` stand-in (0x004C830A). Tail `jmp` with ECX kept is a member too.
- `mov [ecx],vtable; ret` with no `mov eax,ecx` is a destructor, `T::~T() {}`, not a constructor (0x00401429).
- Block order is source order: the block after a `Jcc` is the `then` body. An inverted early return needs the test inverted:
  `if (ok) { ...; return true; } fail; return false;` (0x00454F79). `c = n; n = n->next; free(c);` instead of
  `next = n->next; free(n); n = next;` keeps the zero after the loop for `and [esi+N],edi` (0x0040A8E9).
- `lea eax,[ebp+8]` passed as an out argument while the parameter stays in EDI: a plain local. VC lays it over the dead parameter's
  home: `unsigned w; r->Read(&w, 4); f = w;`, never `&r` (0x00454FCD). Same for `[ebp-4]`: a plain local, not a saved `this` (0x00403B24).
- Scratch copies of the repo need `tests/unicorn/crt_defaults.json`, or every cookie and `__EH_prolog` call shows as a false diff.

## Rules from the second review pass (2026-11-04, each fixed the named function)
- ECX never loaded before a call, and the original uses EDX for a temporary where you get ECX: ECX still holds `this`, so the
  callee is a member of the same object, not the free `__stdcall`/`__cdecl` function you declared. Its own listing reads
  `[ecx+N]` and ends `ret N`. Declare it in the class with an `// EXTERNAL:` marker (0x00402DD4 calls 0x00402D37). A
  by-value return through `[ebp+8]` with ECX kept is the same: `Result Mid(int start, int count);` as a member, and a
  repeated null test is the inline accessor called twice: `if (n >= Length()) return Mid(0, 0xffff); return Mid(Length()
  - n, 0xffff);` (0x0050178B calls 0x00573250). A second marker for that VA on another class is fine when the file
  already declares it as a free function for a landed function: leave that one as it is.
- `[ecx+eax+N]` (`this` as base) for a bounds-checked byte-array member, `if (i >= N) __debugbreak(); a[i] = v;`: indexing
  the member, a decayed `unsigned char* p = a`, `*(a + i)`, `i[a]` and an inline getter returning the array all give
  `[eax+ecx+N]`. A named local reference to the array gives `[ecx+eax+N]`: `unsigned char (&b)[9] = a;` or
  `BoundedArray<unsigned char, 0x24>& r = bytes;` (also `BoundedArray<..>* p = &a; (*p)[i]`). Mark it
  `/* fake match: ... */` (vc71q-array-ref-base, 0x004B9679, 0x0044E755). The bounds-checked loop rule above is
  the other direction.
- A store that the original makes before loading an array element for an argument (`mov byte ptr [esi+0x254],0xff`
  between the pushes, then `push [esi+0x1e0]`): passing `field_1e0[0]` loads it first, a local copy too. A pointer to the
  array keeps the order: `int* v = field_1e0; field_254 = -1; F(0, b, v[0], 0, 1);`, marked fake match (0x0048492C).
- Separate `EQ_GLOBAL`s are separate symbols, so VC knows they cannot overlap and reorders around them: two global stores
  and a `rep stosd` clear came out clear-first. When the original keeps the stores first, the globals are fields of one
  object: a struct at the lowest address, with pads, `#define g_s EQ_GLOBAL(S, 0x009237DC)`, `g_s.a = 4; g_s.b = 0;
  for (i...) g_s.table[i] = 0;` (0x004CCA22). `memset` is a call at /O1 (`push 0x400; ...; call`); an inline
  `rep stosd` is a loop.
- `mov eax,[r]; push 1; call [eax]` on an object already tested for null is `delete p` with a virtual destructor (slot 0 is
  the scalar deleting destructor; the null test folds away): `virtual ~T();`, not a `virtual void Close(int)` called
  with 1. `mov ecx,r` before `push 1` against after: the branch that deletes ends on its own, `if (!found) { report();
  delete p; return 0; }`, instead of falling through to a shared `delete p; return 0;` (0x00569FA8).
- `or eax,-1` ahead of an `and [x],0` that sits before the `-1` stores: the first `-1` field comes first in the source,
  the zero store second: `f164 = -1; f178 = 0; f168 = -1; ...` (0x00557B62). The zero first gives `and` first.
- Not solved, three or more tries each (don't repeat them): a global loaded into ECX and then copied to EDI against loaded
  into EDI (manager local, the global read twice, a reference: 0x00552751); a cdecl call's `pop ecx` right after the call
  against `add esp,4` at the end, with the callee in the same file (2D array, a local, inline: 0x00417355); a
  constructor that loads its second argument first (plain body in the original order, an initializer list, declaration
  order: 0x004C5E4D).

## Rules from the hand pass (2026-11-05, each fixed the named near miss)
- `neg/sbb/and eax,M/add eax,C` is a two-value ternary, `c ? A : B`: VC computes `B + (mask & (A - B))`, so `C = B`
  and `M = A - B` (mod 2^32). Write the two real values, not the mask: `flag ? 0xFFFFFFFF : 0xFFC0C0C0` (and
  `0x3F3F3F`, add `0xFFC0C0C0`: 0x00511F40), `x < 3000 ? 0xFF42DE63 : 0xFFDE7B21` (0x0044D103). Work out `A = C + M`
  from the original's two constants; a wrong guess for `A` shows up only as a different `M` (0x004A1953: `and
  0xFFFFDDC3, add 0x3025` is `flag ? 0x0DE8 : 0x3025`). `(cond ? X : 0) + C` and `-(int)c & M` forms keep VC's
  folding and never match.
- `add eax,0xFFFFFF01` where you get `sub eax,ecx` (ECX already holds 0xFF for the compare) or `sub eax,0xFF`: the loop
  works on the member itself, `while (f170 >= 0xff) f170 -= 0xff;`, and the member is `int`; VC keeps it in EAX
  and stores it once after the loop (0x00544F69). A local copy (`int phase = f170; do phase -= 0xff; ...`) shares
  the constant with the compare. A cast `(int)f170` on an `unsigned` member keeps the member in memory.
- `sub al,cl` (8-bit) on a `char` result where you get `sub eax,ecx`: subtract into a `char` local and return it,
  `char r = (char)v; r -= base; return r;` (0x00419DFD). `return (char)(v - base);`, `(char)v - (char)base` and
  `unsigned char` casts all stay 32-bit; a `char result = 0;` set in the branch moves the zeroing ahead of the test.
- A literal that differs (`push 0x649904` against your string, ndiff 1, rest identical): the string is in the image,
  so read it instead of guessing. The linker shares string tails, so the address can point into the middle of a
  longer string: 0x649904 is `" %s"`, the tail of `"/tell %s"` at 0x6498FF (0x00498449). The check prints it after the
  first difference: `(string at 0x649904 is b' %s', yours is b'/tell %s')`. Don't spend tries on guesses.
- An argument loaded into a register before the address of a local is pushed (`mov eax,[ecx+4]; mov eax,[eax];
  lea edx,[ebp-4]; push edx; push eax`, where you get `lea; push; push dword ptr [eax]`): the first argument is
  a small class with a constructor, passed by value, here a list iterator: `struct It { Node* p; It(Node* n) :
  p(n) {} }; It Begin() { return It(head->next); } void Insert(It where, T* const& v); void PushFront(T* const&
  v) { Insert(Begin(), v); }`, then `list->PushFront(this)`. A plain struct, an accessor, a by-reference iterator
  or a by-value wrapper without a constructor all give the other order (0x00518D79, 0x0054B02A; every caller of
  0x00518D4A has this shape).
- `shr eax,1; not al; and eax,0xFFFFFF01; push eax`: the callee takes `bool`, and the source passes a condition,
  `Key((key & 2) == 0)`; a written mask (`~(key >> 1) & 1`) with an `int` parameter keeps the 32-bit form
  (0x005219F6; its landed sibling 0x005217B6 stays identical with the parameter as `bool`).

## Rules from the 2026-11-06 permuter pass (each is the cleaned winner for the named near miss)
The permuter (`permute/permute.py`) found these from saved earlier attempts; each was rewritten by hand without the
mutation noise. They are ordering and scoping effects, so try them before anything structural:
- Declare a buffer in the scope that uses it: `char text[12];` inside the `if` that calls `sprintf`, not at the top
  (0x00401463, 0x004B1213). Same for a reference temporary: `{ const unsigned long& v = obj->field; obj->Call(v); }`
  as its own block (0x004E4CA6; outside a block the frame is 4 bytes larger).
- Declaration order picks registers and slots: the loop counter declared before an unrelated pointer
  (0x0051D058, and as `unsigned short`), the hash index before the `self` pointer (0x004065C1), an adjusted copy
  before the random calls (0x0041897D).
- Store order is kept: if two independent stores come out swapped, swap them in the source (0x004F86D9, 0x004C5E4D,
  0x004B3EFA; `Cos` and `Sin` both before the x update: 0x0047BB72).
- No temporaries where the original reads directly: `rec->flag = (char)!_strnicmp(...)` (0x0040C405), the call
  result as an argument (0x00454B8D, 0x004B8915, 0x004D8188 `... + time(0)`), `x*x` from the member (0x00435B82),
  the Row9 copy straight from the Row14 slot (0x004B8013).
- An `int&` local into a member array instead of an `int` copy changes which pointer VC keeps in EDI (0x004C14B0;
  a reference to a parameter: 0x00418AEF).
- Control shape: an early return for the second test (0x00410DB0); `if (a) return 0; else { ... }` (0x0055697D);
  a duplicated tail return inside the mode block, `if (mode == 4) { if (row == 0) return 0; return T[...]; } return
  T[...];` (0x00416F59, 0x00417023); two values that need no action as separate empty `else if` branches before the
  default (0x0050A846); one combined test `if (Ready() && (mode == 3 || mode == 2)) return 0; return 1;`
  (0x004FD36C); a `bool` local for `actor == 0 || actor->IsHidden()` (0x004396DF); `<= 0x82` instead of `< 0x83`
  (0x004903F1); a `for` over four slots written as `do { ... } while (++i < 4)` form (0x004C14B0).
- The permuter's raw output carries noise (empty branches, yoda compares, `(int)` casts on calls, split
  declarations). Each cleaned form above was re-checked; when the clean form fails, keep only the mutation that
  matters (0x0050A846 needed the empty branches; 0x004E4CA6 needed the block).

## Rules from the local probes (2026-11-06; each fixed the named functions)
- std::string, ostringstream, list, vector, deque, map: use the compiler's own headers (`#include <string>`,
  `<sstream>`, `<list>`, `<vector>`, `<deque>`, `<map>`), never local `_guess` copies. VC7.1 drops the EH state stores
  around a destructor only when it sees the whole body down to nothrow leaves, which the real templates give and a
  `_guess` copy calling an external `_Tidy` never does (0x0042A8C8, 0x0052FD5C, 0x0042C1B2, 0x0042BDEE, 0x0042846B,
  0x004286D4, 0x00428962, 0x0042B34A). The out-of-line helpers (`_Tidy`, ctors, `find`, `substr`, `operator<<`,
  `ostringstream::str`, `~ios_base` ...) resolve through `rewrite_aliases` in `tests/unicorn/crt_defaults.json` (real
  decorated name -> real address; the `basic_ios` vtable is a data alias). Add an alias only for a real helper at its
  real address. Container element types are guesses; the linker merged the helpers across element types.
  `os << (flag ? 1 : 0)` when the original calls `operator<<(int)` (0x0042846B).
- A clear loop ending in `int3` (bounds check) goes through `include/titanium/bounded_array.h`:
  `BoundedArray_guess<int, N> values;` and `for (unsigned i = 0; i < N; ++i) values[i] = 0;`. Its `operator[]` is
  `if ((unsigned)i < N) return data[i]; __debugbreak(); return data[i];`: the two returns merge into one store after
  the `int3`. Loop index `unsigned` for a `jb` back edge, `int` for `jl`. The `if (i >= N) __debugbreak();` spelling
  lets VC split the loop into `stosd` stores. Replaces the `(char*)&array + offset` lever (0x004BE82F, 0x004BC5D2,
  0x004BDC13, 0x0045871F, 0x0041AAD4).
