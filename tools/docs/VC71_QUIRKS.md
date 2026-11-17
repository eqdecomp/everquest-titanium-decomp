# VC++ .NET 2003 RTM codegen quirks

Patterns reproduced with VC++ .NET 2003 RTM (cl/c2 13.10.3077, LINK 7.10.3077), the Titanium compiler. Each entry has a small source check under `docs/vc71_quirks/`; no other VC7.1 claims are included.

The probes use the tool's `/O1 /W3 /MT /Gy /GX` defaults. A file's `// CFLAGS:` line adds options to those defaults.

Rerun the checks with:

```text
..\.venv\Scripts\python.exe tools\compare\probe.py --toolchain vc71 --check-quirks
```

## Stack protection

### vc71q-gs-trigger
keywords: `/GS`, security cookie, char array, stack · repro: `vc71_quirks/gs_trigger.cpp`

**Claim.** With `/GS`, an address-taken local `char` array gets a security cookie and a call to `@__security_check_cookie@4`. A struct containing a `char` array gets the same check. An address-taken `int` array does not.

**RTM.** The char-array and struct cases reference `___security_cookie`; the integer-array case has neither cookie symbol.

**Use.** A cookie in a function with a local aggregate can be explained by a character array nested in that aggregate.

## Calling conventions

### vc71q-thiscall-member
keywords: thiscall, ECX, member function · repro: `vc71_quirks/thiscall_member.cpp`

**Claim.** A normal C++ member function uses ECX for `this` and callee-cleans its argument, without spelling a calling-convention keyword.

**RTM.** The small member reads its field through ECX and ends with `ret 4`.

**Use.** Reproduce a class member declaration to get the implicit thiscall convention.

### vc71q-thiscall-keyword
keywords: thiscall, compiler diagnostic, calling convention · repro: `vc71_quirks/thiscall_keyword.cpp`

**Claim.** Explicit `__thiscall` on a member declaration or definition fails with compiler diagnostic C4234. Ordinary class members still use thiscall implicitly.

**Use.** Leave the convention implicit on ordinary member declarations.

## Exception handling

### vc71q-eh-frame
keywords: EH, exception frame, destructor, `__EH_prolog`, state · repro: `vc71_quirks/eh_frame.cpp`

**Claim.** With `/GX`, a destructible local that lives across a call gets an EH handler symbol and a call to `__EH_prolog`; the generated code updates its state around the call and destruction.

**RTM.** The handler symbol precedes `__EH_prolog`; the frame state is cleared after construction and set to `-1` before destruction.

**Use.** When matching EH code, preserve the object's lifetime across the call and the corresponding constructor/destructor operations.

**Flags.** The normalized listing for this repro is the same with `/GX` and `/EHsc`.

## Inlining

### vc71q-inline-small-static
keywords: inline, static helper, `/O1` · repro: `vc71_quirks/inline.cpp`

**Claim.** At default `/O1`, a small `static` helper is inlined into its caller. Adding `/Ob1` leaves a call in the caller.

**RTM.** The default listing contains the helper's arithmetic directly and has no call. The `/Ob1` listing calls the helper.

**Use.** An absent call to a small local helper can be explained by inlining.

## Layout and compiler options

### vc71q-packing
keywords: layout, packing, `/Zp1`, byte array · repro: `vc71_quirks/packing.cpp`

**Claim.** `/Zp1` removes the default padding after a three-byte member array. Following int fields move from offsets `0x20/0x24/0x28` to `0x1F/0x23/0x27`.

**RTM.** Reading the first int after the array uses `[eax + 0x20]` at default packing and `[eax + 0x1f]` with `/Zp1`.

**Use.** A one-byte field offset difference after a three-byte array can come from packing.

### vc71q-class-layout-option
keywords: layout, compiler diagnostic, internal option · repro: `vc71_quirks/class_layout_bare.cpp`, `vc71_quirks/class_layout_named.cpp`

**Claim.** The compiler rejects both `/d1reportSingleClassLayout` and `/d1reportSingleClassLayout:LayoutProbe` with C1007.

**RTM.** Both commands fail with an unrecognized-flag diagnostic.

**Use.** Do not rely on this internal layout-report switch with the RTM compiler.

## Calls and optimization

### vc71q-same-tu-effect
keywords: same translation unit, caller clobbers, ECX, register allocation · repro: `vc71_quirks/vc71q_same_tu_effect.cpp`

**Claim.** At `/O1`, a same-TU `__fastcall` callee lets the caller keep a live pointer in EDX across the call. With the callee external, the caller saves the pointer in ESI and restores it after the call.

**RTM.** `Caller` has `mov edx, ecx` in the same-TU variant and `mov esi, ecx` in the external variant; the listings differ. The real pair at `0x447B98` matches the same-TU version byte-for-byte, while the external version grows from 22 to 26 bytes.

**Use.** Keep a callee in the same translation unit when matching register values live across its call. A caller defined before the callee also matched the real pair.

### vc71q-call-cleanup
keywords: call cleanup, add esp, pop ecx, same translation unit · repro: `vc71_quirks/vc71q_call_cleanup.cpp`

**Claim.** For an `/O1` literal argument, a same-TU one-argument call cleans up with `add esp,4`; the external-callee variant uses `pop ecx`. At `/O2`, both tested forms use `add esp,4`.

**RTM.** The `CleanupLiteral` listings differ between the same-TU and external variants at `/O1`.

**Use.** Treat `add esp,4` versus `pop ecx` as a real call-context clue at `/O1`, not as a universal property of one callee.

### vc71q-g7-multiply
keywords: `/G7`, IMUL, LEA, CPU target, `/O1`, `/O2` · repro: `vc71_quirks/vc71q_g7_multiply.cpp`

**Claim.** `/G7` changes selected multiply-by-constant forms. At `/O1`, `x*3` uses `imul` under `/G7` and `lea` at default `/G`; at `/O2`, `x*7` uses `imul` at default `/G` and `lea` plus `sub` under `/G7`.

**RTM.** These differences appear in the O1 and O2 variant listings. The tested default, `/G5`, and `/G6` forms were identical for these functions.

**Use.** `/G7` is distinguishable by small arithmetic shapes; the game and Suite target checks rule it out for the tested spans.

## Arithmetic and control flow

### vc71q-switch-lowering
keywords: switch, jump table, byte index, dense, sparse · repro: `vc71_quirks/vc71q_switch_lowering.cpp`

**Claim.** Dense switches first use a jump table at 8 cases under `/O1` and 4 under `/O2` for these return-constant shapes. Under `/O2`, the sparse cases `0,3,6,200` use a byte index table and dword target table; `0,3,6,300` use comparisons.

**RTM.** The four dense and two sparse expectations pass. Additional boundary listings show compare lowering at sparse case values 255 and 256; the precise sparse heuristic cutoff is not established.

**Use.** A sparse-looking switch may still use a two-level table under `/O2`; table choice depends on the particular span and bodies.

### vc71q-division-constants
keywords: arithmetic, signed division, unsigned division, reciprocal multiply, `/O1`, `/O2` · repro: `vc71_quirks/vc71q_division_constants.cpp`

**Claim.** `/O1` uses `idiv` and `div` for signed and unsigned division by 5. `/O2` replaces both with reciprocal-multiply sequences.

**RTM.** The O1 object contains `idiv ecx` / `div ecx`; the O2 object contains `imul` / `mul` and no divide instruction.

**Use.** For constant division, signedness and optimization level determine whether the listing has hardware division or a multiply sequence.

### vc71q-intrinsic-oi
keywords: `/Oi`, memset, strcpy, strlen, intrinsic · repro: `vc71_quirks/vc71q_intrinsic_oi.cpp`

**Claim.** Without `/Oi`, the tested fixed-size memset, literal strcpy, and literal strlen call the CRT. With `/Oi`, they inline: four `stosd`, one dword literal store, and a constant return of 3.

**RTM.** The BASE and OI listings have those respective call and inline forms.

**Use.** A missing CRT call can be explained by `/Oi`, even when the source names `memset`, `strcpy`, or `strlen`.

### vc71q-aggregate-copy
keywords: struct copy, `movsd`, `rep movsd`, `rep stosd`, zero loop · repro: `vc71_quirks/vc71q_aggregate_copy.cpp`

**Claim.** At `/O1`, a 12-byte aggregate copy uses three `movsd`; a 32-byte copy uses `rep movsd`; and a 16-iteration dword-zero loop uses `rep stosd`.

**RTM.** All three instruction-shape expectations pass in the O1 listing.

**Use.** Preserve aggregate size and loop count when matching bulk memory operations.

## Frames, EH, and objects

### vc71q-gs-buffer-threshold
keywords: `/GS`, char buffer, security cookie, struct member, `_alloca` · repro: `vc71_quirks/vc71q_gs_buffer_threshold.cpp`

**Claim.** In these `/GS` probes, `char[4]` has no cookie while `char[8]` does. A struct containing `char[16]` also gets a cookie; a dynamic `_alloca` buffer does not in this shape.

**RTM.** `Buffer4` and `AllocaBuffer` lack `security_cookie`; `Buffer8` and `StructBuffer` reference it.

**Use.** A cookie can be triggered by a nested character array. The tested trigger boundary lies between four and eight bytes.

### vc71q-eh-state
keywords: EH, state word, `__EH_prolog`, C++ call · repro: `vc71_quirks/vc71q_eh_state.cpp`

**Claim.** With `/GX`, a C++-linkage call while a destructible local is live gets an EH frame and state updates around the call.

**RTM.** The listing references `__EH_prolog` and the C++ call; the full `eh_states_o1.asm` listing shows `and` of the state word to zero before the call and `or` to `-1` afterward.

**Use.** Keep a potentially throwing C++ call inside the object's lifetime to reproduce the state transition.

### vc71q-eh-new-tail
keywords: EH, `new`, value initialization, static guard, tail call, bit test · repro: `vc71_quirks/vc71q_eh_new_tail.cpp`

**Claim.** `/O1` tail-returns with `jmp`; `new Plain` leaves the trivial object uninitialized while `new Plain()` zeroes it. `new Guarded` creates constructor-failure cleanup, a static local uses a guard byte, and the two bit-test spellings use signed or unsigned shift plus `and`.

**RTM.** `TailWrap` jumps to `_Tail`; `NewPlain` lacks `stosd`, `NewValue` has it, `NewGuarded` references `__EH_prolog`, and the guard and bit functions match their expected sequences. The C-linkage call shape in this source has no C++ EH frame; the C++-linkage case is in `vc71q_eh_state.cpp`.

**Use.** Distinguish value initialization from default initialization, and preserve the call linkage and return spelling around EH and tail-call shapes.

### vc71q-float-conversion
keywords: float literal, x87 compare, unordered, `__ftol2` · repro: `vc71_quirks/vc71q_float_conversion.cpp`

**Claim.** At `/O1`, zero and one float returns load `__real@` constants, a float compare uses `fnstsw`, and `(int)f` tail-jumps to `__ftol2`.

**RTM.** The listing lacks `fldz` and `fld1`, contains `fnstsw`, and ends `FloatToInt` with `jmp __ftol2`.

**Use.** Preserve the x87 compare and conversion form, including the unordered flag handling, when matching floating-point code.

### vc71q-delete-array-header
keywords: delete array, `<new>`, vector deleting destructor, operator delete[] · repro: `vc71_quirks/vc71q_delete_array_header.cpp`

**Claim.** Including `<new>` changes the array-deallocation path emitted in the vector deleting destructor. Without the header the tested helper uses `operator delete`; with it the helper has an `operator delete[]` path.

**RTM.** The NO_NEW listing contains a call to `??3` and lacks `??_V`; the WITH_NEW listing contains a call to `??_V`.

**Use.** Check the declarations visible in a translation unit before treating scalar and array deallocation calls as interchangeable.

## Inlining

### vc71q-inline-o1
keywords: inline, static helper, loop, in-class member, `/O1` · repro: `vc71_quirks/vc71q_inline_o1.cpp`

**Claim.** At `/O1`, an unmarked same-TU static helper is inlined, including the tested loop helper, and an in-class member definition is inlined into its caller.

**RTM.** `SmallCaller`, `LoopCaller`, and `InClassCaller` contain no call instruction. This disproves the hypothesis that a loop prevents inlining at `/O1` for this shape.

**Use.** Keep the helper body, including its loop, in the same TU when matching an inlined caller.

## Frames from class semantics

### vc71q-return-flag
keywords: return by value, hidden return pointer, EBP frame, zeroed local, destructor · repro: `vc71_quirks/vc71q_return_by_value_flag.cpp`

**Claim.** Returning a class with a destructor by value gives an EBP frame with one extra dword, zeroed by `and [ebp-4],0`, even with no EH frame and no other local. Without the destructor neither appears.

**RTM.** `Owner::Get` has `push ebp`, `and dword ptr [ebp - 4], 0` and reloads the return pointer from `[ebp + 8]`; the variant with no destructor has none of them. Real functions 0x004D91F5 and 0x0055966C match this form.

**Use.** Read a zeroed one-word slot beside a `[ebp+8]` return as this flag; do not declare a local for it.

### vc71q-byvalue-arg-temp
keywords: by-value argument, temporary, mov ecx esp, destructor · repro: `vc71_quirks/vc71q_byvalue_arg_temp.cpp`

**Claim.** Building a by-value argument of a class with a destructor makes the compiler save the outgoing slot's address in a frame word.

**RTM.** `Owner::Fwd` has `mov ecx, esp` and `mov dword ptr [esp + 0x10], esp`; the variant with no destructor lacks the second store. Real function 0x005614DD matches this form.

**Use.** A store of ESP into a stack slot beside a constructor call means a by-value class parameter on the callee.

### vc71q-ebp-frame-refs
keywords: EBP frame, no locals, parameter references, /O1 size · repro: `vc71_quirks/vc71q_ebp_frame_refs.cpp`

**Claim.** At `/O1` a function with no locals gets an EBP frame depending on how many times the source names its parameters, counted before the optimizer merges those reads.

**RTM.** `Sel` has the frame when `kind == 1` is written in each branch and none with `kind - 1` cached in a local, although both load `kind` once. Real function 0x0040154F matches the repeated form.

**Use.** Spell parameter reads out instead of caching them when the target has a frame and few stack reads.

### vc71q-iterator-class-frame
keywords: std::find, _Ptrit, iterator class, EBP frame, copy constructor · repro: `vc71_quirks/vc71q_iterator_class_frame.cpp`

**Claim.** A 4-byte iterator class with a user copy constructor returns through a hidden pointer and, with inline operators, gets an EBP frame; without the copy constructor it returns in EAX with no frame.

**RTM.** `Find` has `push ebp` and `mov ecx, dword ptr [ebp + 0xc]` only in the copy-constructor variant. Real functions 0x0052D79C and 0x0052F8BE match that variant byte for byte.

**Use.** Hand-rolled pointer loops with a hidden return slot are STL algorithms over a class iterator.

### vc71q-dtor-member-no-inline
keywords: scalar deleting destructor, ??_G, inline, member destructor, base destructor · repro: `vc71_quirks/vc71q_dtor_member_no_inline.cpp`

**Claim.** A destructor is inlined into its caller at `/O1` only when the class has no member or base with a user destructor. An empty inline `~M() {}` on a member keeps a real call, and the destructor's own code does not change.

**RTM.** `T::Del` calls `??1T` only in the member variant; `T::~T` is the same one-store body in both. Definition order in the file makes no difference. Real functions 0x004258A7, 0x0049545E and 0x004C468D match this form.

**Use.** When a same-file destructor is inlined and the target calls it, add the member or base rather than an EXTERNAL.

### vc71q-minmax-macro
keywords: min, max, macro, clamp, repeated compare · repro: `vc71_quirks/vc71q_minmax_macro.cpp`

**Claim.** The classic `min(0x60, max(4, v))` macro expansion keeps a second compare against the lower bound. The equivalent if/else does not.

**RTM.** `Clamp` has two `cmp eax, 4` with the macro and one without. Real function 0x004C5007 matches the macro form only with the constant as `min`'s first argument and `max`'s first argument.

**Use.** A repeated bound check that the optimizer "should" remove is a macro expansion.

### vc71q-switch-split-cases
keywords: switch, dec chain, split case bodies · repro: `vc71_quirks/vc71q_switch_split_cases.cpp`

**Claim.** Case labels with separate identical bodies lower to a `sub`/`dec` chain, even for `case 0`; merged labels on one body lower to a `test`/`cmp` tree.

**RTM.** `F` has `sub ecx, eax` and two `dec ecx` when split; merged it has `test ecx, ecx; jl`. Real function 0x0043235E matches the split form.

**Use.** Split the labels when the target walks a `dec` chain.

## Sinking, hoisting and induction

### vc71q-single-use-sinks
keywords: div, modulo, forward substitution, single use, null test · repro: `vc71_quirks/vc71q_single_use_sinks.cpp`

**Claim.** A computed local with one use after a branch moves past the branch; a second use keeps it in place.

**RTM.** `T::Next` has the `div` after the null test in `ONE` and before it in `TWO`. All seven hash iterators (0x00405697, 0x0042EC1A, 0x00446718, 0x00446788, 0x004FE51C, 0x0054BFEA, 0x005651BE) match the `TWO` form.

**Use.** When an expensive expression sits above a test it does not feed, name its result twice.

### vc71q-loop-accessor-lea
keywords: member object, inline accessor, loop condition, lea, hoist · repro: `vc71_quirks/vc71q_loop_accessor_lea.cpp`

**Claim.** An inline accessor of a member object in a loop condition hoists the member's address into a register; in an `if` it folds to `[reg+N]`.

**RTM.** `L::F` has `lea esi,[ecx+4]` in `LOOP` and `mov esi,ecx` in `IF`. Real functions 0x004C6059 and 0x004F2B97 match the loop form.

**Use.** Read `lea r,[this+N]` with `[r]` re-reads in a loop as a member object with inline accessors.

### vc71q-member-spelled-twice-lea
keywords: null test, member spelled twice, lea, large displacement · repro: `vc71_quirks/vc71q_member_twice_lea.cpp`

**Claim.** After `this` moved to a saved register, a member at a 4-byte offset named twice in a test and a use gets `lea` and two loads. A local gives one load and `test`.

**RTM.** `E::F` has `lea eax,[esi+0x104]` and `cmp dword ptr [eax],0` in `TWICE`, `test ecx,ecx` in `LOCAL`; with an offset of 8 the `lea` is gone. Real functions 0x004FE582 and 0x00547E07 match.

**Use.** Do not cache a member in a local when the target tests it through `lea`.

### vc71q-bit-test-negate
keywords: xor al 0xff, not, bit test, unsigned char · repro: `vc71_quirks/vc71q_bit_test_negate.cpp`

**Claim.** `!(b & 1)` passed on as a byte compiles to `xor al,0xff; and eax,0xffffff01` for `unsigned char` and to `not al` with the same `and` for `char`.

**RTM.** `F` shows those two forms. Real functions 0x00541D4A and 0x004E8B1E match the `unsigned char` form.

**Use.** `xor al,0xff` before that `and` gives the callee's return type as `unsigned char` or `bool`.

### vc71q-index-loop-reduction
keywords: index loop, strength reduction, byte offset, dec counter · repro: `vc71_quirks/vc71q_index_loop_reduction.cpp`

**Claim.** A plain index loop over a global table steps a byte offset (`add esi,4; cmp esi,0xfa0`), and one bounded by a member count runs on a `dec` counter beside a pointer.

**RTM.** `F` and `S::F` show both. Real functions 0x004054A8, 0x0042E63B, 0x00437B89 and 0x00491373 match plain `for` loops.

**Use.** Try the index loop before writing the pointer walk seen in the listing.

### vc71q-arm-call-hoist
keywords: if else, argument push, hoist, tail merge, ternary · repro: `vc71_quirks/vc71q_arm_call_hoist.cpp`

**Claim.** An `if`/`else` with a full call in each arm hoists the shared pushes above the branch and merges the tails. Ternary arguments give `setcc` arithmetic.

**RTM.** `F` has `push 1` before `jle` in `ARMS`, and `setle` in `TERNARY`. Real functions 0x00454E75 and 0x00452D85 match the arms form.

**Use.** A push before a compare's `Jcc` with both arms pushing the rest is two written calls.

### vc71q-array-ref-base
keywords: base index, addressing mode, member array, reference, bounds check · repro: `vc71_quirks/vc71q_array_ref_base.cpp`

**Claim.** A bounds-checked store into a byte-array member (`if (i >= 9) __debugbreak(); a[i] = v;`) addresses it as `[index+this+N]`; indexing through a named local reference to the array addresses it as `[this+index+N]`.

**RTM.** `S::f` has `[eax + ecx + 0x1164]` in `DIRECT`, `DECAY` (`unsigned char* p = a`) and `GETTER` (inline function returning the array), and `[ecx + eax + 0x1164]` in `REF` (`unsigned char (&r)[9] = a`). Real functions 0x004B9679 and 0x0044E755 (a template `BoundedArray` member) match the reference form.

**Use.** Original `[ecx+eax+N]` with ECX = `this` after an `int3` bounds check: a reference local, marked `fake match` (nothing proves the original had the local).

