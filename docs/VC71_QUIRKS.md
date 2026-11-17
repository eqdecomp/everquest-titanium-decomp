# Visual C++ .NET 2003 (7.1): code-generation quirks for matching decompilation

This page is for anyone who decompiles a program built with Visual C++ .NET 2003 (compiler 13.10.3077,
linker 7.10.3077, the RTM release) and wants the rebuilt source to compile to the same bytes. It collects the
patterns found while matching the EverQuest Titanium client (`eqgame.exe`, built with
`/O1 /GS /GX /Gy /MT /GR-`).

Every entry rests on one of two kinds of evidence:

- **probe**: a small source file in [tools/docs/vc71_quirks/](../tools/docs/vc71_quirks/), compiled with the
  flags it names and checked for the instructions it expects. [tools/docs/VC71_QUIRKS.md](../tools/docs/VC71_QUIRKS.md)
  lists what each one shows; `tools\compare\probe.py --toolchain vc71 --check-quirks` reruns them all.
- **fixed**: functions of `eqgame.exe` that became byte-identical after the source change described. The
  addresses are examples; [tools/docs/TITANIUM_MATCH_NOTES.md](../tools/docs/TITANIUM_MATCH_NOTES.md) has the
  longer, client-specific list.

Nothing here goes beyond what those checks showed. Unless an entry names other flags, it describes `/O1`.
Each entry gives **You see** (in the original's listing), **Why** (what the compiler does), and **Write** (the
source shape that reproduces the original).

## Find the entry from the first difference

Compile, compare, and look up the *first* differing instruction; later differences often follow from it.

| First difference | Section |
|---|---|
| a call in one listing and inlined code in the other | [Inlining and translation units](#inlining-and-translation-units) |
| `pop ecx` against `add esp,4` after a call | [Inlining and translation units](#inlining-and-translation-units) |
| `push ebp; mov ebp,esp` in only one listing | [Frames and stack layout](#frames-and-stack-layout) |
| a security cookie in only one listing | [Compiler options](#compiler-options) (`/GS`) |
| `__EH_prolog` or `[ebp-4]` state stores in only one listing | [Exception handling](#exception-handling) |
| same instructions, registers swapped, or two lines in another order | [Register allocation and statement order](#register-allocation-and-statement-order) |
| branch sense or block order | [Control flow and tail merging](#control-flow-and-tail-merging) |
| jump table against compare chain, or a `dec` chain | [Switch statements](#switch-statements) |
| a pointer walk against an index loop | [Loops](#loops) |
| `lea r,[x+N]` against a folded `[x+N]`, or base and index swapped | [Member access and addressing](#member-access-and-addressing) |
| `movsx`/`movzx`, 8-bit against 32-bit arithmetic, `setcc` against masks | [Integers, char and bool](#integers-char-and-bool) |
| x87 code, `__ftol2` | [Floating point](#floating-point) |
| `movsd`/`stosd` against calls, an inline or called `memset` | [Copies, clears and intrinsics](#copies-clears-and-intrinsics) |
| a ctor/dtor shape, `delete`, vtable stores | [Constructors, destructors and delete](#constructors-destructors-and-delete) |
| a string address, an import call | [Strings, imports and the linker](#strings-imports-and-the-linker) |

## Compiler options

### `/O1` against `/O2`: division by a constant
- **You see:** `idiv`/`div` for a constant divisor, or a multiply by a magic constant with no divide.
- **Why:** `/O1` keeps the hardware divide (signed and unsigned); `/O2` replaces both with reciprocal multiplies.
- **Write:** plain `x / 5`; the optimization level and the operand's signedness decide the form. (probe
  `vc71q_division_constants`)

### `/O1` against `/O2`: other differences
- **You see:** switch tables at different case counts, `pop ecx` cleanups, different multiply forms.
- **Why:** `/O1` optimizes for size: jump tables start at 8 dense cases (4 at `/O2`); a one-argument call may
  be cleaned up with `pop ecx` (at `/O2` the tested forms always use `add esp,4`); `push imm8; pop reg` replaces
  `mov reg,imm`.
- **Write:** nothing special; use these to tell the level from the listing. See the switch and translation-unit
  sections.

### `/Ob`: inlining of small helpers
- **You see:** the helper's arithmetic inside its caller, no call.
- **Why:** at `/O1` a small `static` helper in the same file is inlined; `/Ob1` keeps the call. (probe `inline`)
- **Write:** keep the helper in the same file. A call that the original *does* make to a tiny function means
  the compiler did not see its body: declare it, don't define it.

### `/Oy`: frame pointer omission
- **You see:** most functions address arguments as `[esp+N]`; some have `push ebp; mov ebp,esp` with no locals.
- **Why:** `/O1` omits the frame pointer unless the source shape asks for one. Forcing it (`/Oy-`, or dead code
  such as an unused `setjmp`) produces the frame but is not what the original said.
- **Write:** look for the real cause in [Frames and stack layout](#frames-and-stack-layout).

### `/GS`: which functions get a security cookie
- **You see:** a load of `___security_cookie` at entry, the cookie at the top of the frame, a call to
  `@__security_check_cookie@4` before return.
- **Why:** an address-taken local `char` array, or a struct holding one, gets the cookie. `char[4]` did not,
  `char[8]` did (the exact threshold lies between); a struct with `char[16]` did; `int` arrays and `_alloca`
  buffers did not. (probes `gs_trigger`, `vc71q_gs_buffer_threshold`)
- **Write:** never write the cookie. The original has no cookie but an 8+ byte buffer: it was not a `char`
  array; use `int buf[N/4]` or a struct of ints (two `char[12]` became `int[3]`). The original has a cookie and
  your frame is a few bytes short: the buffer is larger than its use (260 bytes, not 256, fixed 0x0042DE64);
  size it from `sub esp` minus the other locals.

### `/GX` and `/EHsc`
- **You see:** `__EH_prolog` frames.
- **Why:** both options gave the same listing for the EH probe. (probe `eh_frame`)
- **Write:** either; see [Exception handling](#exception-handling) for what creates a frame.

### `/Oi`: intrinsic `memset`, `strcpy`, `strlen`
- **You see:** a fixed-size `memset` as four `stosd`, a literal `strcpy` as a dword store, `strlen("abc")` as 3.
- **Why:** `/Oi` expands them inline; without it they are CRT calls. (probe `vc71q_intrinsic_oi`)
- **Write:** call them by name either way; a missing CRT call can mean `/Oi` (or a hand-written loop, see
  [Copies, clears and intrinsics](#copies-clears-and-intrinsics)).

### `/Zp1`: packing
- **You see:** an `int` read at `[eax+0x1F]` after a three-byte array where you get `[eax+0x20]`.
- **Why:** `/Zp1` removes the padding after the array. (probe `packing`)
- **Write:** a one-byte offset shift after an odd-sized member points at packing, not a missing field.

### `/G7`: CPU target
- **You see:** `x*3` as `imul` at `/O1` (`lea` normally); at `/O2`, `x*7` as `lea` plus `sub` (`imul` normally).
- **Why:** `/G7` changes some multiply-by-constant forms; default, `/G5` and `/G6` were identical in the probe.
  (probe `vc71q_g7_multiply`)
- **Write:** use these shapes to rule `/G7` in or out.

### Layout reports
- **You see:** `/d1reportSingleClassLayout` fails with C1007.
- **Why:** the RTM compiler does not accept that internal switch, with or without a class name. (probe
  `class_layout_*`)
- **Write:** check layouts with `offsetof` / compile-time asserts instead.

## Calling conventions and `this`

### Member functions: implicit thiscall
- **You see:** `this` in ECX, fields read as `[ecx+N]`, `ret N`.
- **Why:** an ordinary member function uses thiscall. Spelling `__thiscall` on a member is rejected (C4234).
  (probes `thiscall_member`, `thiscall_keyword`)
- **Write:** a member function with no convention keyword. `__fastcall` with only ECX used is the wrong
  stand-in: it is right only when EDX carries a second argument.

### ECX never loaded before a call
- **You see:** no `mov ecx,...` before a call, and a temporary in EDX where you get ECX.
- **Why:** ECX still holds `this`: the callee is a member of the same object, not a free function.
- **Write:** declare the callee in the class and call it as a member (fixed 0x00402DD4, 0x0050178B). A call
  that never returns, with ECX kept live, is a member too: `__declspec(noreturn) void Fail();` (fixed 0x00432806).

### A global loaded into ECX and tested
- **You see:** `mov ecx,[global]; add esp,N; test ecx,ecx`.
- **Why:** the global is the `this` of the next call, not a stale compare.
- **Write:** `if (g_obj != 0) g_obj->Refresh(a, b);` (fixed 0x00430304).

### Member objects
- **You see:** `add ecx,N; push [ecx]; call` (`this` moved to a sub-object), or `[ecx+N]` folded (`this` stayed outer).
- **Why:** an inline method of the member object forwarding to a real member.
- **Write:** `struct Sub { int head; void F(int, const unsigned*); void Add(const unsigned& v) { F(head, &v); } };`
  and `s.Add(v);` (fixed 0x00484909).

### Nested calls and argument order
- **You see:** the outer call's trailing arguments pushed before the inner call is evaluated.
- **Why:** VC7.1 pushes right to left and evaluates a nested call where its argument goes.
- **Write:** the plain nested call, `Show(Lookup(id, 0), color, 1)`, not a temporary (fixed 0x00401B42).

### Virtual calls and virtual bases
- **You see:** `call [eax+N]`; `jmp [eax+N]` at the end of a function; `lea eax,[vbase]; lea ecx,[eax+4]`.
- **Why:** slot N/4 of the vtable; a virtual call in tail position; an inline method of a virtual base (a cast
  or reference would add a null test instead).
- **Write:** declare the slots in order and call the slot. A vbptr at +8 means an 8-byte non-virtual base comes
  first (fixed 0x00431C6B); a lone `ret 4` parameter on a constructor is the hidden most-derived flag (fixed
  0x004BF2A7); offsets into a sub-object through a vbptr are virtual bases, not `char*` arithmetic (fixed 0x00416A40).

## Inlining and translation units

### A callee in the same file keeps registers alive
- **You see:** a pointer kept in EDX across a call where you get ESI saved and restored.
- **Why:** with the callee's body in the same translation unit, VC7.1 knows which registers it clobbers.
  Defined before or after the caller makes no difference. (probe `vc71q_same_tu_effect`, real pair at 0x00447B98)
- **Write:** define the callee in the same file. A function can be unmatchable with the callee only declared.

### `pop ecx` against `add esp,4`
- **You see:** a one-argument cdecl call cleaned up with `add esp,4` in one listing and `pop ecx` in the other.
- **Why:** at `/O1` the choice depends on whether the callee is in the same file (`add esp,4`) or external
  (`pop ecx`). (probe `vc71q_call_cleanup`)
- **Write:** treat it as a clue to where the callee lives, not as a property of the callee.

### What `/O1` inlines
- **You see:** no call to a helper that exists elsewhere in the binary.
- **Why:** a same-file `static` helper is inlined at `/O1` even with a loop inside, and so is an in-class member
  definition (probe `vc71q_inline_o1`). In-class members taking or returning `float` were not; a static free
  helper with the same body was (fixed 0x004850A0).
- **Write:** keep the body visible. One class split over several declarations loses this: merge them into one
  (fixed 7 functions of one class).

## Constructors, destructors and delete

### When a destructor is inlined
- **You see:** a destructor inlined into a caller where the original calls it, or the reverse.
- **Why:** at `/O1` a destructor is inlined only when the class has no member or base with a user-declared
  destructor; an empty `~M() {}` on a member is enough to keep the call. The destructor's own code does not change.
  (probe `vc71q_dtor_member_no_inline`; fixed 0x004258A7, 0x0049545E, 0x004C468D)
- **Write:** add the member or base the original had: `struct M { ~M() {} }; struct T { M m; virtual ~T(); };`.

### Telling constructors from destructors
- **You see:** `mov eax,ecx` at entry with stores through EAX; or `mov [ecx],vtable; ret` without `mov eax,ecx`.
- **Why:** a constructor returns `this` and stores its vtable after the base constructor and member
  initialisers; a destructor stores its own vtable first and returns nothing.
- **Write:** `C::C() { ... }` for the first (fixed 0x0042E660), `T::~T() {}` for the second (fixed 0x00401429).
  Repeating store groups are member constructors (`R() : a(0), b(-1) {}`); a call first is a base (fixed
  0x004B7451, 0x004B7470). Never store a vtable by hand: VC then folds the next virtual call differently.

### The scalar deleting destructor
- **You see:** `push esi; mov esi,ecx; call dtor; test byte ptr [esp+8],1; ... call free`.
- **Why:** the compiler's `??_G` helper; it frees only when bit 0 of the flag is set.
- **Write:** if you must write it at its own address: `this->T::~T(); if (flags & 1) free(this); return this;`.

### `delete` through a virtual destructor
- **You see:** `mov eax,[r]; push 1; call [eax]`, with no null test when `p` was already tested.
- **Why:** slot 0 is the scalar deleting destructor; the null test folds away. `delete p` right after a
  dereference of `p` also drops the test (fixed 0x004F949F).
- **Write:** `virtual ~T();` and `delete p;`, not a virtual `Close(int)` called with 1 (fixed 0x00569FA8).

### Array delete depends on `<new>`
- **You see:** `operator delete[]` / `new[]` (`??_V`, `??_U`) against `operator delete` / `new` (`??3`, `??2`).
- **Why:** the array forms are called only when `operator new[]` is declared in the translation unit.
  (probe `vc71q_delete_array_header`; fixed 0x00490C98)
- **Write:** `#include <new>` when the original calls the array forms.

### `new T` against `new T()`
- **You see:** a `rep stosd` (or stores of zero) right after the allocation, or none.
- **Why:** `new T()` value-initialises (zeroes) a trivial `T`; `new T` leaves it uninitialised. (probe `vc71q_eh_new_tail`)
- **Write:** the parentheses only if the original zeroes.

### Classes passed and returned by value
- **You see:** a copy constructor call where you get a plain copy; `push ecx; mov ecx,[esp+8]; call copy`.
- **Why:** a class passed by value needs its declared copy constructor (fixed 0x0044B14A); `return *this;` from a
  member copies through it (fixed 0x004D9160).
- **Write:** declare the copy constructor. A small class *with a constructor* passed by value (an iterator,
  `It(Node* n) : p(n) {}`) also changes the order in which arguments are loaded; a plain struct does not
  (fixed 0x00518D79, 0x0054B02A).

## Exception handling

### What creates an `__EH_prolog` frame
- **You see:** a call to `__EH_prolog` at entry and stores to a state word (`[ebp-4]`).
- **Why:** with `/GX`, a local with a destructor living across a call that can throw. The state is cleared
  (`and [ebp-4],0`) after construction and set to -1 (`or [ebp-4],-1`) before destruction. A call with
  C linkage does not count. In this client's game code every EH frame uses `__EH_prolog`; none sets up `fs:[0]` inline.
  (probes `eh_frame`, `vc71q_eh_state`, `vc71q_eh_new_tail`)
- **Write:** keep the object's lifetime around the call, and the callee's linkage, as in the original.
  `new Guarded` with a constructor that can throw also gets a frame for the cleanup.

### A destructor with no EH frame although it calls member destructors
- **You see:** member and base destructor calls with no state stores around them.
- **Why:** VC7.1 drops the EH states only when it sees every body down to calls that cannot throw. A virtual
  call, `new`, a throwing helper or a function it cannot see keeps the frame (73 framed destructors checked).
  Only calls before the last matter: a single member or base destructor ends in `jmp` and needs nothing.
- **Write:** define the member destructors in the file (header inlines), with nothrow leaves: `extern "C"` on
  `free`, or `delete[] p` with `<new>` included. A C++ `void __cdecl free` brings the frame back (fixed
  0x004C9C05, 0x0054815C, 0x0054C494). An exception specification `throw()` also removes the frame but is
  not what the original said.

### The standard library
- **You see:** container or `std::string` code with no EH states where your copy has them.
- **Why:** the real templates give the compiler every body down to nothrow leaves; a hand-written copy calling
  an external helper never does.
- **Write:** `#include <string>`, `<sstream>`, `<list>`, `<vector>`, `<deque>`, `<map>` from the compiler's own
  headers, never local copies (fixed 0x0042A8C8, 0x0052FD5C, 0x0042C1B2 and five more).

## Frames and stack layout

### Returning a class with a destructor
- **You see:** `push ebp; mov ebp,esp; push ecx; and dword ptr [ebp-4],0 ... mov eax,[ebp+8]; leave`, no other locals.
- **Why:** the zeroed word is the compiler's flag for the hidden return object, created only when the class has
  a destructor. (probe `vc71q_return_by_value_flag`; fixed 0x004D91F5, 0x0055966C)
- **Write:** `Str Owner::Get() { return name; }` with `~Str();` declared. Never declare a local for the flag.

### Passing a class with a destructor by value
- **You see:** `push ecx; mov ecx,esp` then a store of ESP into a frame slot, then a constructor call.
- **Why:** the compiler records the outgoing argument's address for cleanup. (probe `vc71q_byvalue_arg_temp`;
  fixed 0x005614DD)
- **Write:** a by-value class parameter on the callee, `void Set(Str s, int a, int b);`.

### An EBP frame with no locals
- **You see:** `push ebp; mov ebp,esp` and parameters at `[ebp+8]` where you get `[esp+N]`.
- **Why:** at `/O1` the frame depends on how many times the source names the parameters, counted before the
  optimizer merges the reads. Dead reads such as `(void)x;` do not count. (probe `vc71q_ebp_frame_refs`;
  fixed 0x0040154F)
- **Write:** spell the parameter out in each branch (`kind == 1 ? a : b` three times), don't cache it in a local.
  A byte-sized local can also add a frame (see the bit-test entry).

### A hidden return pointer for a 4-byte result
- **You see:** a pointer-sized result returned through `[ebp+8]` with an EBP frame.
- **Why:** a 4-byte class with a user copy constructor is returned through a hidden pointer; without the copy
  constructor it returns in EAX. (probe `vc71q_iterator_class_frame`; fixed 0x0052D79C, 0x0052F8BE)
- **Write:** an STL algorithm over a class iterator, e.g. `std::find` over a wrapped pointer, not a pointer loop.

### Local slot order
- **You see:** locals at other offsets than yours.
- **Why:** the first declared scalar takes the lowest slot (first `-12`, second `-8`, third `-4`). Buffers
  `first[32], second[64], third[16]` sat at `-52`, `-116`, `-20`.
- **Write:** reorder declarations. Declare a buffer in the scope that uses it (`char text[12];` inside the `if`
  that calls `sprintf`; fixed 0x00401463, 0x004B1213); a reference temporary in its own block keeps the frame
  4 bytes smaller (fixed 0x004E4CA6).

### Locals over dead parameters
- **You see:** `lea eax,[ebp+8]` passed as an out argument, or a loop counter at `[ebp+8]`.
- **Why:** VC7.1 lays a local over the home slot of a parameter that is no longer used.
- **Write:** a plain local, `unsigned w; r->Read(&w, 4);`, never `&param` (fixed 0x00454FCD, 0x0056982F).
  `lea eax,[esp+N]` at the top byte of a pushed slot is a `char c;` passed as `&c` (fixed 0x004D73F2).

## Register allocation and statement order

### Registers swapped
- **You see:** the same instructions with ESI and EDI (or EAX and ECX) exchanged.
- **Why:** register choice follows the declaration order and first use of locals and the order of statements.
- **Write:** one change per compile: (1) swap which value is assigned first, (2) swap the declarations, (3) use the
  parameters in the other order in the first statement. Loop counter before an unrelated pointer (fixed
  0x0051D058), hash index before the `self` pointer (fixed 0x004065C1). If three tries do not move it, stop:
  about a third of the failures recorded in this client had this shape, and more tries rarely helped.

### Stores in another order
- **You see:** two independent stores swapped.
- **Why:** VC7.1 keeps the source order of stores it cannot prove independent.
- **Write:** swap them in the source (fixed 0x004F86D9, 0x004B3EFA, 0x0047BB72). A `-1` and a `0` store:
  `or eax,-1` ahead of the `and [x],0` means the `-1` field came first (fixed 0x00557B62).

### Globals that move around each other
- **You see:** two global stores and a clear loop in another order.
- **Why:** separate global symbols cannot overlap, so VC7.1 may reorder them; fields of one object keep their order.
- **Write:** make them fields of one struct at the lowest address (fixed 0x004CCA22).

### A computation that sinks past a test
- **You see:** a `div` (or other expensive expression) above a null test it does not feed, where yours is below.
- **Why:** a computed value used once after a branch moves past it; used twice, it stays. (probe
  `vc71q_single_use_sinks`)
- **Write:** name the result twice, e.g. `int j = i + 1; if (i + 1 < count) ...` (fixed seven hash iterators,
  0x00405697, 0x0042EC1A, 0x00446718, 0x00446788, 0x004FE51C, 0x0054BFEA, 0x005651BE).

### Temporaries
- **You see:** both arguments loaded before the first push; a read kept before a store; or the reverse.
- **Why:** a named local pins the evaluation point; a direct expression lets VC schedule it.
- **Write:** a local where the original evaluates early (`const char* l = *a; return strcmp(l, *b);`, fixed
  0x0056BF4F; `int h = handle; r = v; if (h) ...`, fixed 0x004C503A), none where it reads directly (call results as
  arguments, fixed 0x00454B8D, 0x004B8915). An `int&` local into a member array instead of a copy changes which
  pointer stays in EDI (fixed 0x004C14B0).

### Constants in registers
- **You see:** `mov al,0xff` byte stores in one listing, a register in the other.
- **Why:** constants are shared in a register per typed constant.
- **Write:** give the stores the original's field types (fixed 0x004850A0).

## Control flow and tail merging

### Block order
- **You see:** the branch sense inverted and the blocks in another order.
- **Why:** block order is source order: the block after a conditional jump is the `then` body.
- **Write:** invert the test to match: `if (ok) { ...; return true; } fail(); return false;` (fixed 0x00454F79).

### Calls in both arms
- **You see:** pushes before a conditional jump, with only the remaining arguments in each arm, and one call.
- **Why:** an `if`/`else` with a full call in each arm: VC7.1 hoists the shared pushes and merges the tails. A
  ternary argument gives `setcc` arithmetic instead. (probe `vc71q_arm_call_hoist`; fixed 0x00454E75, 0x00452D85)
- **Write:** two complete calls. The same holds for `switch` arms (fixed 0x00494B3D).

### Tail calls
- **You see:** `jmp` to a function at the end.
- **Why:** `return Tail(x);` compiles to a jump at `/O1`; `jmp [eax+N]` is a virtual call in tail position.
  (probe `vc71q_eh_new_tail`)
- **Write:** `return Tail(x);`.

### Ternaries against early returns
- **You see:** `xor eax,eax` before a shared `ret`; or `neg`/`sbb`/`and eax,M`/`add eax,C`.
- **Why:** `a ? b : 0` and `if (!a) return 0; return b;` compile differently (fixed 0x004CB2DD). A two-value
  ternary `c ? A : B` becomes `B + (mask & (A - B))`, so `C = B` and `M = A - B`.
- **Write:** the two real values: work out `A = C + M` from the listing (fixed 0x00511F40, 0x0044D103,
  0x004A1953). Hand-written masks never match.

### Bounds that are tested twice
- **You see:** a range check comparing the lower bound twice.
- **Why:** the expansion of a classic `min`/`max` macro, which the optimizer does not reduce. Argument order
  matters. (probe `vc71q_minmax_macro`)
- **Write:** `#define max(a,b) (((a) > (b)) ? (a) : (b))` and `min(0x60, max(4, v))` with the constant first
  (fixed 0x004C5007). A null test repeated with `jbe` after it is an inline accessor called twice:
  `if (Count() > 0) return Count() - 1;` (fixed 0x0044AD92).

### Values left in EAX
- **You see:** `ret` with a global or argument still in EAX that nothing seems to use.
- **Why:** it is the return value; a `void` guess makes VC choose other registers for the rest.
- **Write:** `R* F() { if (!g) g = new R; return g; }` (fixed 0x00401022, 0x0048A00B).

### Small shapes worth trying
- **You see:** near-identical code with one branch or compare differing.
- **Why:** these source differences each changed the output in one place.
- **Write:** an early return for a second test (fixed 0x00410DB0); `if (a) return 0; else { ... }` (fixed
  0x0055697D); a duplicated tail return inside a block (fixed 0x00416F59); empty `else if` branches for values
  that need no action (fixed 0x0050A846); one combined test (fixed 0x004FD36C); a `bool` local for `a || b` (fixed
  0x004396DF); `<= 0x82` instead of `< 0x83` (fixed 0x004903F1); a `do { } while (++i < 4)` loop (fixed
  0x004C14B0). A compare ahead of stores it does not depend on reads the field just stored (fixed 0x004C334D).

## Switch statements

### Jump table or compare chain
- **You see:** a jump table, or a chain of compares.
- **Why:** dense return-constant switches got a table from 8 cases at `/O1` and from 4 at `/O2`. At `/O2`,
  sparse cases `0,3,6,200` used a byte index table plus a dword target table; `0,3,6,300` used compares. The
  exact sparse cutoff is not established. (probe `vc71q_switch_lowering`)
- **Write:** a `switch`, even when the listing looks like an `if` chain: `dec eax; je; sub eax,6; je; ...`
  is a switch (fixed 0x00417DAF).

### Split or merged case bodies
- **You see:** `sub ecx,eax` then a `dec` chain, against `test; jl; cmp`.
- **Why:** case labels with separate (even identical) bodies lower to a `sub`/`dec` chain, also for `case 0`;
  labels sharing one body lower to a compare tree. (probe `vc71q_switch_split_cases`; fixed 0x0043235E)
- **Write:** `case 0: r = 1; break; case 1: r = 1; break;` when the original walks a `dec` chain.

### Table range and block order
- **You see:** a table biased by one, or case blocks in another order.
- **Why:** the table spans the cases the source names; case label order sets block order.
- **Write:** an explicit `case 0:` keeps the table from being biased; an explicit `case N: return default;`
  produces the biased one (fixed 0x00464E25). Order the labels like the original's blocks.

## Loops

### Pointer walks are index loops
- **You see:** a byte offset stepped by 4 against `cmp esi,N*4`, or a pointer with a `dec` counter.
- **Why:** VC7.1 strength-reduces a plain index loop: over a global table to a byte offset, bounded by a member
  count to a `dec` counter beside a pointer. (probe `vc71q_index_loop_reduction`)
- **Write:** `for (i = 0; i < n; ++i) a[i] ...`, not the walk (fixed 0x004054A8, 0x0042E63B, 0x00437B89,
  0x00491373; nested: 0x004C934C, 0x0056AA54). In this client this fixed more functions than any other rule.

### Accessors in loop conditions
- **You see:** `lea esi,[ecx+N]` before the loop and `[esi]` re-read in it.
- **Why:** an inline accessor of a member object in a loop condition hoists the member's address; in an `if` it
  folds to `[reg+N]`. (probe `vc71q_loop_accessor_lea`; fixed 0x004C6059, 0x004F2B97)
- **Write:** `while (q.Head())`, `i < c.Get()`.

### Loop over the member itself
- **You see:** `add eax,0xFFFFFF01` where you get `sub eax,ecx`; member values kept in registers.
- **Why:** a loop on the member itself keeps it in EAX and stores once; a local copy shares the compare's constant.
- **Write:** `while (f >= 0xff) f -= 0xff;` on an `int` member (fixed 0x00544F69); loop over members, not local
  copies of them (fixed 0x0047C3AF).

### Exit conditions
- **You see:** `jbe` against `je`, `jb` against `jl` on the back edge.
- **Why:** `while (count > 0)` on an unsigned exits with `jbe`, `while (count != 0)` with `je`; an `unsigned`
  index gives `jb`, an `int` index `jl`.
- **Write:** the original's comparison and index type.

### Bounds-checked loops
- **You see:** a clear loop with an `int3` in it, or split into `stosd` stores.
- **Why:** `__debugbreak()` compiles to `int3`. An `operator[]` of the form
  `if ((unsigned)i < N) return data[i]; __debugbreak(); return data[i];` merges the two returns into one store
  after the `int3`; writing `if (i >= N) __debugbreak();` in the loop lets VC split it into `stosd` stores.
- **Write:** a small bounded-array template with that `operator[]` (fixed 0x004BE82F, 0x004BC5D2, 0x0045871F).

## Member access and addressing

### A member spelled twice
- **You see:** `lea eax,[esi+0x104]; cmp dword ptr [eax],0; ... mov eax,[eax]`.
- **Why:** a member at a large offset named twice, in a test and a use, after `this` moved to a saved register.
  A local gives one load and `test`; at small offsets the `lea` disappears. (probe `vc71q_member_twice_lea`)
- **Write:** `if (x != 0) x->Slot();` with no local (fixed 0x004FE582, 0x00547E07).

### Base and index swapped
- **You see:** `[ecx+eax+N]` against `[eax+ecx+N]` (same instruction, different encoding).
- **Why:** indexing a byte-array member, a decayed pointer or an inline getter gives `[index+this+N]`; a named
  local reference to the array gives `[this+index+N]`. (probe `vc71q_array_ref_base`; fixed 0x004B9679,
  0x0044E755) In a bounds-checked loop with step 4, an access in the `else` through the array's address gives
  the other order (fixed 0x0040E776, 0x004BC5D2).
- **Write:** `unsigned char (&r)[9] = a; r[i] = v;`. Nothing proves the original had such a local; mark it as a
  fake match.

### Declare members, don't add offsets
- **You see:** `[reg+N]` accesses that you might write as `(char*)this + N`.
- **Why:** the original accessed a member; offset casts hide the layout and are not what it said.
- **Write:** a member at offset N. A `cmp eax,base+N; jl` over a global table needs a real array symbol; an
  integer address cast gives a separate counter (fixed 0x004849B2, 0x00497395).

### Stores through a pointer with no reload
- **You see:** two stores through a member pointer with no reload; `push imm; pop reg` feeding two stores.
- **Why:** an inline method of the pointee; a temporary struct with an inline constructor.
- **Write:** those, not loose stores (fixed 0x00536D26, 0x00516E9A).

## Integers, char and bool

### Width and signedness
- **You see:** `movsx` against `movzx`, `jl/jg` against `jb/ja`.
- **Why:** they give the field's width and signedness.
- **Write:** the field types the listing implies; don't cast around a mismatch.

### Multiplying by constants
- **You see:** `lea` or `imul`.
- **Why:** at `/O1`, `x*3`, `*5`, `*9` use `lea`; `*7`, `*15` use `imul`. (probe `vc71q_g7_multiply`)
- **Write:** plain `x * k`.

### char and bool returns
- **You see:** `xor al,al`; `xor eax,eax`; `neg al; sbb eax,eax; neg eax`; a byte store of a compare result.
- **Why:** `xor al,al` is a `char` return, `xor eax,eax` a `bool`; `neg/sbb/neg` beside `xor eax,eax` is an `int`
  (fixed 0x0044E79F). A byte store of a compare result means a `bool` or `char` field or return.
- **Write:** the matching return type.

### 8-bit arithmetic
- **You see:** `sub al,cl` where you get `sub eax,ecx`.
- **Why:** only arithmetic into a `char` variable stays 8-bit; casts on the expression keep it 32-bit.
- **Write:** `char r = (char)v; r -= base; return r;` (fixed 0x00419DFD).

### Negated bit tests
- **You see:** `xor al,0xff; and eax,0xffffff01`, or `not al` before the same `and`.
- **Why:** `!(b & 1)` passed on as a byte: `xor al,0xff` for `unsigned char`, `not al` for `char`. `~b` gives
  `not al`, `!b` gives `neg al; sbb`. (probe `vc71q_bit_test_negate`; fixed 0x00541D4A, 0x004E8B1E)
- **Write:** pass the expression straight to the call; a byte local added an EBP frame.

### bool parameters and bit tests
- **You see:** `shr eax,1; not al; and eax,0xFFFFFF01; push eax`; `shr; and` with no `setcc`.
- **Why:** the callee takes `bool` and the source passes a condition (fixed 0x005219F6). `(x & 0x20) != 0` gives
  `shr; and`; `test r8,1` after `shr` is `(bool)((x >> n) & 1)`.
- **Write:** `Key((key & 2) == 0)` with a `bool` parameter; a hand-written mask with an `int` parameter keeps
  the 32-bit form.

### Zeroing a member
- **You see:** `and dword ptr [m],0`.
- **Why:** plain `= 0` compiles to `and` at `/O1`, with or without a zero register live.
- **Write:** `m = 0;`, not `m &= 0;`.

## Floating point

### Constants and compares
- **You see:** 0.0f and 1.0f loaded from memory, no `fldz`/`fld1`; compares through `fnstsw`.
- **Why:** at `/O1` float constants come from `__real@` constants; x87 compares go through the status word,
  including the unordered case. (probe `vc71q_float_conversion`)
- **Write:** plain literals and compares.

### Conversions
- **You see:** a call or `jmp` to `__ftol2`; `push ecx; push ecx; fstp qword ptr [esp]` before a call.
- **Why:** `(int)f` calls `__ftol2` (a tail `jmp` when it is the return value); the second is a `float`
  converted for a `double` parameter, not two arguments.
- **Write:** `(int)f`; a `double` parameter on the callee. Never declare or call `__ftol2` yourself.

### Temporaries in float expressions
- **You see:** a float copied to a temporary before a call on the right of `*`.
- **Why:** an inline float getter on the left of `*` with a call on the right is evaluated first and kept.
- **Write:** `Get() * Other()` with the inline getter (fixed 0x0048A026).

## Copies, clears and intrinsics

### Aggregate copies and clears
- **You see:** three `movsd`, `rep movsd`, `rep stosd`.
- **Why:** at `/O1` a 12-byte copy is three `movsd`, a 32-byte copy `rep movsd`, a 16-iteration dword-zero loop
  `rep stosd`. (probe `vc71q_aggregate_copy`)
- **Write:** struct assignment of the original's size; the loop with the original's count.

### `memset` and friends
- **You see:** an inline `rep stosd` clear where you call `memset`, or the reverse.
- **Why:** without `/Oi`, `memset` is a call (`push 0x400; ...; call`); an inline `rep stosd` comes from a loop.
- **Write:** a `for` loop that zeroes, when the original has no call (fixed 0x004CCA22).

## Strings, imports and the linker

### String addresses
- **You see:** a pushed string address that differs while everything else matches.
- **Why:** the linker shares string tails: an address can point into the middle of a longer string (the tail
  `" %s"` of a longer format string, fixed 0x00498449).
- **Write:** read the string at the original's address from the binary instead of guessing it.

### Static locals
- **You see:** a test and set of a guard byte around a one-time initialisation.
- **Why:** a function-level `static` local. (probe `vc71q_eh_new_tail`)
- **Write:** the `static` local.

### Win32 calls
- **You see:** `call [__imp__Name@n]`; two calls of one API as `mov edi,[import]; call edi`.
- **Why:** a `dllimport` declaration; with two calls VC loads the import once into a register. A function-pointer
  variable gives two `call [m]` instead.
- **Write:** `#include <winsock2.h>` then `#include <windows.h>` and call the API by name.

### Not a function
- **You see:** a "function" that starts using `[ebp-N]` or `fs:[0]` with no frame setup, or ends with `leave`
  and never sets one up.
- **Why:** it is the tail of another function that the disassembler split off.
- **Write:** nothing; rebuild the whole function it belongs to.

## Testing an idea

Write the smallest file that shows the shape, with a `// CFLAGS:` line and the instructions you expect, and
compile it in a few variants before changing real code. The files in
[tools/docs/vc71_quirks/](../tools/docs/vc71_quirks/) are templates for this, and `tools/compare/probe.py`
compiles and checks them.
