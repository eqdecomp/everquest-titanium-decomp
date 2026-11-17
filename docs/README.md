# EverQuest Titanium client: source guide

Start with [ARCHITECTURE.md](ARCHITECTURE.md), the overview of the whole client. This page covers the tree
layout and the conventions in the source.

This tree rebuilds `eqgame.exe` from the EverQuest Titanium client (build string "Oct 31 2005 10:33:37",
printed by `WinMain`). Each rewritten function compiles with the original compiler, Visual C++ .NET 2003
(13.10.3077). `compare.py --match` compares its bytes with the original; where a fixture exists, an emulator
run also compares behaviour. Functions marked `@early-stop` do not match yet (see Conventions).

The client is three images. This repo covers the first one.

| image | what it does | here |
|---|---|---|
| `eqgame.exe` | the game: world, UI, network, spells, items | `src/EverQuest/` (game code), `src/Suite/` (UI library pilots) |
| eqmain.dll | login and server select; `WinMain` loads it first ([startup.md](startup.md)) | not in this repo |
| EQGraphicsDX9.dll | the renderer; reached only through interfaces ([rendering.md](rendering.md)) | not in this repo |

## Source layout

```
src/EverQuest/tu_NNN_<Name>.cpp  game code, 0x00401000-0x00570FCA, one file per original object file (193 files)
src/Suite/pilot_<VA>.cpp      five pilot rewrites in the UI library range (0x00571000 up), built /O2
include/titanium/             shared headers: eqaddr.h, core_decls.h, types.h, crt.h, bounded_array.h,
                              the constant enums classes.h, races.h, skills.h, slots.h, spell_effects.h,
                              opcodes.h (the OP_ message opcodes), and the mail address book records
                              (mail_address_book.h, mail_address_record_guess.h)
include/titanium/layouts/     layouts shared by several files: core.h, geometry.h, math.h,
                              shared_classes.h, sidl_base.h, ui.h
include/titanium/wnd/         one header per window or UI class (104), on the shared slot base
                              in include/titanium/wnd_views.h
tests/unicorn/EverQuest/      fixtures, one folder per TU (tu_NNN_<Name>), one JSON file per function
PROGRESS.md (repository root) per-file counts of the states and compare results below
tools/                        compare, fixture harness, queue, export
```

A `tu_NNN` file is one translation unit of the original link order: `compare/tumap.py` estimated the object
boundaries from the binary (the `// Estimated object NNN` line at the top). The number is the object index,
not a feature. Two files carry a letter, `tu_054b_AnimationTracks` and `tu_073b_LeadershipAbility`: code
split off the estimated object because the original compiled it out of sight of its neighbours (the
first lines of each file give the evidence). The `_<Name>` after it is, in order of preference: the original source file name when the
binary has it (`C:\EQ\EverQuest\<Name>.cpp` in an assert or error string), the file name the earlier sibling
decomp of the older client uses for the same code (`EQ_Character`, `Display`, `EQHandleMsg`, `EQMisc`, `Win`,
`login`, ...), else the class that owns most of the file's code, with `_guess` dropped and, for windows, the
leading `C` dropped as the original window files do (`InvSlotWnd.cpp`). Files named from the binary:

| file | evidence |
|---|---|
| `tu_012_CharacterMagicSystem.cpp` | `C:\EQ\EverQuest\CharacterMagicSystem.cpp` |
| `tu_062_EverQuest.cpp` | `C:\EQ\EverQuest\EverQuest.cpp` |
| `tu_173_InvSlotWnd.cpp` | `C:\EQ\EverQuest\InvSlotWnd.cpp` |
| `tu_216_SpellGemWnd.cpp` | `C:\EQ\EverQuest\SpellGemWnd.cpp` |

`C:\EQ\EverQuest\GaugeWnd.cpp` also appears (used at 0x005049FE), but `GaugeWnd.cpp` is only the tail of object 159
(from 0x005044F2); most of that file is the friends window (`CFriendsWnd_guess`, constructor 0x005035EA, screen
`"FriendsWindow"`), so it is
`tu_159_FriendsWnd.cpp`. Files with mixed or helper-only content have the weakest names (for example
`tu_001_Sync`, `tu_002_ProgressionData`, `tu_089_Story`, `tu_217_UiHelpers`); grep by VA rather than trusting
them.

The same strings name the UI library's files (`C:\EQ\Suite\Suite\XWnd.cpp`, `SidlScreenWnd.cpp`,
`ButtonWnd.cpp`, `ComboWnd.cpp`); that is why `src/Suite/` has its name.

The docs refer to a file by its name without `.cpp` (`tu_042_EQHandleMsg`). All files are in
`src/EverQuest/`; there are no subfolders.

Window files (tu_099_ActionsWnd to tu_236_VideoModesWnd) follow the original link order, which is alphabetical by class
(`CActionsWnd` ... `CVideoModesWnd`). If a window file's own classes are still generic, its neighbours tell
you roughly which window it is.

## Reading order

0. [ARCHITECTURE.md](ARCHITECTURE.md): the overview; every other page goes deeper into one of its sections.
1. [startup.md](startup.md): `WinMain`, the eqmain hand-off, `CEverQuest` and the main loop. Read this first.
2. [network.md](network.md): how a message leaves (`EQSendMessage`) and how one arrives (the dispatcher).
3. [world.md](world.md): `CEverQuest`, `CDisplay`, `EQPlayer`, the character object, zoning.
4. [ui.md](ui.md): `CXWnd` / `CSidlScreenWnd`, the XML screens, and which file holds which window.
5. [items_inventory.md](items_inventory.md) and [spells.md](spells.md): two vertical slices through the above.
6. [rendering.md](rendering.md): where game code stops and the graphics DLL starts.
7. [KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md): defects of the original client that the tree keeps.
8. [ATTRIBUTION.md](ATTRIBUTION.md): where the names come from.
9. [VC71_QUIRKS.md](VC71_QUIRKS.md): Visual C++ .NET 2003 code-generation patterns and the source shapes that
   reproduce them, for matching work on this or any other program built with that compiler.

The four largest files hold most of the control flow: `tu_062_EverQuest` (CEverQuest, 242 functions), `tu_042_EQHandleMsg` (the
message handlers and the dispatcher), `tu_029_Display` (CDisplay) and `tu_046_EQMisc` (slash commands, 401 functions).

## Conventions

### `_guess` names
Every name we made up ends in `_guess`: `PlaceReceivedItem_guess`, `CDisplay_guess`, `name_0120_guess`. A name
without the suffix is confirmed: from the C++ runtime, a Windows API, or a symbol at the exact address in a
reference that matches this build (MQ2's Titanium `eqgame.h`, see `include/titanium/core_decls.h`, or the Mac
map). Placeholder names carry their address: `FUN_004912b1_guess` (function at 0x004912B1), `Wnd004FD26A_guess` (a class named after its
constructor's address). Field names end in their offset: `name_0120_guess` is the field at +0x120,
`pSpawn_c288_guess` the one at +0xC288. Two TUs often give one original class two names;
the VA of its constructor or vtable is the key that ties them together, and a class rename by that VA (a
"family") renames every TU's view at once.

Each name's source and confidence were recorded when it was given; [ATTRIBUTION.md](ATTRIBUTION.md)
counts them per source. Opcode handlers are named `Handle_OP_<EQEmu name>_guess`: the opcode's name comes
from EQEmu's Titanium patch file, not from the original client. A handler for an opcode EQEmu does not name is
`Handle_<Behavior>_guess`. A bare name (no suffix) is a symbol at the exact address in MQ2's Titanium
`eqgame.h` or the Mac client's map.

### `// FUNCTION:` and `// EXTERNAL:`
```cpp
// FUNCTION: TITANIUM 0x0045A817
// @early-stop: budget, structural ndiff=452
void __cdecl PlaceReceivedItem_guess(int mode_guess, int value_guess) { ... }

// EXTERNAL: TITANIUM 0x004B232E CreateItemList_guess
EQ_Item_guess* CreateItemList_guess(int arg);   // builds one item instance; "ItemList" is a misnomer
```
- `// FUNCTION: TITANIUM 0x<VA>` sits above every rewritten function: the function at that address in the
  original. The tools find functions by this line; grep for it to jump from an address to its source.
- `// EXTERNAL: TITANIUM 0x<VA> <symbol>` sits above a declaration of something defined elsewhere (another
  TU, the UI library, the CRT, a vtable `??_7...@@6B@`). The compare tool links the symbol to that address.
- `EQ_GLOBAL(type, 0x<VA>)` and `EQ_ARRAY(type, 0x<VA>)` (`eqaddr.h`) read a global at its original address.
- Do not edit these lines by hand, nor the `// CFLAGS:` line at the top of each file (the compiler flags of
  that object, normally `/O1 /GS /GX /Gy /MT /GR-`).

### Match states
`compare.py --match` compiles a TU and compares each function with the original. The work queue (one row
per function; not part of the release) records the result. The current counts, overall and per file, are in
PROGRESS.md at the repository root, which the export generates from the queue.

| status | meaning |
|---|---|
| `identical` | same bytes, outside relocations |
| `normalised` | same instructions once addresses are folded; bytes differ (register choice, literal placement) |
| `diff` | same instruction count, some instructions differ |
| `structural` | instruction counts differ |
| (none) | not compared: library code, todo, skip |

"Functional" below means the rewrite behaves like the original (its fixture passes) but the bytes differ.

A function that stays non-identical carries an `@early-stop: <reason>` line in the comment block under
`// FUNCTION:`; the line gives why the match stopped (most often `budget`), the status and `ndiff`
(`// @early-stop: budget, structural ndiff=452`). The compare tool also accepts `@equivalent`,
`@identity-TODO` and `@dead-code`, but no function uses them yet. Code bent only to steer the compiler is
marked `fake match: <why>`; an inline asm block that reproduces the original is marked
`// as original: <why>` (see below). Leave both alone when tidying.

### Queue states
Counts per state are in PROGRESS.md. `tested`: rewritten and accepted as equivalent; nearly all are
`identical`, and the identical bytes are the evidence, so most have no fixture file. `rewritten`: source
exists but the function is not accepted yet (for example `GlobalState_guess::ProcessGame_guess` 0x004ACF33,
structural); nearly all of these have a fixture that checks their behaviour against the original instead.
`todo`: not rewritten. `library`: CRT, STL or other third-party code, not rewritten. `skip`: export
fragments, an SEH filter and mid-instruction entries (the row's note says which).

### Fixtures
A fixture (`tests/unicorn/EverQuest/tu_NNN_<Name>/<Function>.json`; the release leaves out the few that
hold client text, and PUBLISH_MANIFEST gives the count) runs the original
function and the rewrite side by side in an emulator from the same memory, and compares what a caller can see:
return value, memory writes, calls made (target and arguments), ESP and the callee-saved registers. Each lists
the objects the function follows, the cases that reach every branch, fuzz ranges and scripted callees. A
mutation check then edits the rewrite one change at a time; every change must make some case fail, and any
survivor is explained in the fixture's `_survivors`. `tools/docs/TITANIUM_FIXTURE_NOTES.md` has the format.

### `// GENERATED:` (compiler-generated functions)
```cpp
// FUNCTION: TITANIUM 0x004BF94B
// GENERATED: PcBase_guess::`scalar deleting destructor'
// Slot 0 of PcBase's PcCharacter vtable ... runs ~PcBase and ~PcCharacter, then frees the object.
```
Some functions in the original have no source of their own: the compiler wrote them from a class declaration
(scalar and vector deleting destructors, vbase destructors, implicit constructors and destructors). A
`// GENERATED:` line right under `// FUNCTION:` says the function at that VA is the one the compiler emits for
this TU, named `Class::~Class`, `Class::Class`, ``Class::`scalar deleting destructor'`` (`??_G`),
`` `vector deleting destructor' `` (`??_E`) or `` `vbase destructor' `` (`??_D`), or by its exact decorated name
when a class has several (`??_GPcBase_guess@@UAEPAXI@Z`). There is no body to read: what it does follows from
the class (its destructor, its bases, whether it frees itself), and the comment under the line says it in
words. The compare and the fixture harness find the compiler's own symbol; the mutation check skips these
functions. To change one, change the class. The three in this tree are in tu_080_EQ_PC: 0x004BF94B,
0x004BF97C and 0x004BF9AD.

### Inline asm marked `// as original`
```cpp
// as original: `rdtsc` into two zeroed EBP-frame locals is an inline asm block; VC7.1 has no __rdtsc intrinsic.
// FUNCTION: TITANIUM 0x004CC98F
unsigned __int64 __cdecl CyclesSinceStart_guess() { ... __asm { rdtsc ... } ... }
```
An `__asm` block is used only where the original's instructions cannot come from any C++ the compiler accepts,
and the `// as original:` line above it gives the evidence: the instruction sequence, and why no construct
produces it. Three places do this: the `AtomicIncrement_guess` block in tu_007_TextOverlay (0x00407D68, the
precedent), its copies `AtomicIncrement_guess` / `AtomicDecrement_guess` in tu_017_ConnectionManager (`lock
inc|dec` + `setz`; `_InterlockedIncrement` is `lock xadd`), and `CyclesSinceStart_guess` 0x004CC98F in
tu_097_Win (`rdtsc`). Read the block as the one statement the comment names; it is not a match trick and not
marked `fake match`.

### `__try` / `__except`
One game function in this tree uses structured exception handling, 0x004CDD75 `GuardedShutdown_guess`
([startup.md](startup.md)). In MSVC the `__except (filter)` expression and the handler body are not functions
of their own: they are code blocks reached through the frame's scope table, run by the CRT's
`_except_handler3` (0x00612944, named in `names/eqgame.crt.csv`). The filter is usually a comma expression, `(call that
records the crash, EXCEPTION_EXECUTE_HANDLER)`: the call runs first, the second value says "handle it". The
compare and the fixture harness follow the scope table, so the filter (0x004CDE2A, a `skip` row in the queue)
and the handler (0x004CDE43-0x004CE2D5) are compared as part of 0x004CDD75. The fixture harness cannot raise
the exception, so the handler is checked by the byte compare only.

### Export fragments
`tests/unicorn/fragments.json` lists 11 addresses where the export split one function in two: a tail after a
`catch` block, or a body that falls through past where the export thought it ended. The fragment's code is in
its head function's source; its queue row is `skip` with the note "fragment of 0x...". The compare, the
fixture harness and the context tools treat head and fragment as one function.

### Header classes
`include/titanium/core_decls.h` declares the 45 most-called client functions and globals (`CXStr`,
`StringTable::getString`, `CEverQuest::dsp_chat`, the `CXWnd` family, `EQSendMessage`, `pEverQuest`,
`pCharData`). The enum headers name spell effects (SPA), skills, classes, races and inventory slots; not
every literal is replaced, because some replacements change the generated code. `types.h` pins class sizes from the original's `operator new` calls (`EQPlayer` 0x348, `EQ_PC`
0xC4D0, `CEverQuest` 0x3A1C8, `CSidlScreenWnd` 0x15C, 50 windows). These are layout views without virtual
functions. `layouts/` holds structs that several files used to declare on their own (plain data in core.h,
geometry.h, math.h and ui.h; merged class views in shared_classes.h), and sidl_base.h has
`CSidlScreenWndBase`, the polymorphic base that window classes derive from when they define their own
constructor or destructor. A TU whose window needs more virtual slots still declares its own class.

`wnd/<Class>.h` gives every other file one view of a window: the class (`CFriendsWnd_guess`) derives from
`CSidlScreenWndVirtuals_guess` in `wnd_views.h`, which lists the CSidlScreenWnd virtual slots, and declares
the constructor and the methods other files call, each with its `// EXTERNAL:` line, plus the window's global
(`pinstCFriendsWnd_guess`, 0x00850BC0). A file that uses a window includes its header and calls through the
global with no cast; the file that defines the window keeps its own class. A slot whose signature is not
known stays a placeholder (`SlotNN_guess`) and must not be called.

`opcodes.h` is `enum TitaniumOpcode`: the 383 message opcodes the code sends or switches on that have one
unique EQEmu name (names and values from EQEmu's `patch_Titanium.conf`). Send arguments, case labels and
compares use these names; values without such a name stay numbers ([network.md](network.md)).

### String ids
The code passes string ids in hex (`getString(0x16BB, 0)`); eqstr_us.txt is keyed in decimal. The pages give
both, or the text: 0x16BB is 5819, "too distracted to use a skill".

### Original bugs
The tree keeps the original client's bugs as they are. The confirmed ones are listed in
[KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md) (summary in ARCHITECTURE.md section 17). Source under an
`@early-stop` marker is not byte-identical and can differ from the binary in details; several bug notes
written from such source turned out wrong. Check the binary before calling something an original bug.

## Worked examples

Functions whose match needed something out of the ordinary; each is a good place to see a convention above
in real code.

| VA | function | file | what it shows |
|---|---|---|---|
| 0x004BF94B, 0x004BF97C, 0x004BF9AD | ``PcBase_guess::`scalar deleting destructor'``, ``EQ_PC_guess::`scalar deleting destructor'``, `EQ_PC_guess::~EQ_PC_guess` | tu_080_EQ_PC | `// GENERATED:` lines, no body; identical |
| 0x004CDD75 | `GuardedShutdown_guess` | tu_097_Win | `__try` / `__except` with the crash-report filter and handler; identical |
| 0x0042C213 | `FileLoader_guess::Probe_guess` (loads the mail address book) | tu_018_MailtoLink | records with real `std::string` / `std::vector` members; identical, as are the record constructors 0x0042BA5E / 0x0042BAEC (`PurgeObject_guess`) and 0x0042CC75 `MailAddressRecord_guess::Compare_guess` |
| 0x00424B38, 0x00424B5F | `CriticalSectionLock_guess` constructor and destructor | tu_017_ConnectionManager | `// as original:` inline asm; identical |
| 0x004CC98F | `CyclesSinceStart_guess` | tu_097_Win | `// as original:` `rdtsc`; identical |
| 0x0041682F | `Character1_guess::~Character1_guess` | tu_013_EQ_Character | a virtual-base destructor; identical |
| 0x004DEB5A | `Cc_guess::Reserve_guess` | tu_129_BarterSearchWnd | an export fragment (0x004DEB6D) merged into its head; identical |
| 0x0054F8FA | `CRaidWndView_guess::DumpRoster_guess` (the raid window's Dump button) | tu_205_RaidWnd | the same, fragment 0x0054F91A; identical |
| 0x00488BD6 | `Mapper_guess::FUN_00488bd6_guess` | tu_054_Mapper | identical once 0x00489060-0x0048960D moved to `tu_054b_AnimationTracks` |
| 0x004B3F48 | `LeadershipManager_guess::LeadershipManager_guess` | tu_073_login | identical once the element constructor 0x004B3898 (`MenuSelection_guess`) moved to `tu_073b_LeadershipAbility` |
| 0x00561D1E | `TicketEventOwner_guess::WndNotification_guess` | tu_226_TicketWindow | functional: the fixture passes, bytes differ (structural 82) |

## Subsystem pages

| page | covers | main files |
|---|---|---|
| [startup.md](startup.md) | WinMain, eqmain hand-off, CEverQuest lifetime, main loop | tu_097_Win, tu_062_EverQuest |
| [network.md](network.md) | connections, send path, dispatcher 0x0045B8F0, opcodes | tu_017_ConnectionManager, tu_042_EQHandleMsg, tu_062_EverQuest, tu_073_login |
| [world.md](world.md) | CEverQuest, CDisplay, EQPlayer, characters, zoning | tu_062_EverQuest, tu_029_Display, tu_053_EQPlayer, tu_013_EQ_Character, tu_080_EQ_PC |
| [ui.md](ui.md) | CXWnd, CSidlScreenWnd, XML screens, window files | tu_099-tu_236, tu_029_Display |
| [items_inventory.md](items_inventory.md) | item packets, slots, inventory windows | tu_042_EQHandleMsg, tu_069_KeypressHandler, tu_148-tu_174 |
| [spells.md](spells.md) | spell table, casting, effects, spell windows | tu_012_CharacterMagicSystem, tu_038_EQ_Spell, tu_089_Story, tu_215_SpellBookWnd, tu_216_SpellGemWnd |
| [rendering.md](rendering.md) | the boundary to EQGraphicsDX9.dll | tu_097_Win, tu_029_Display |
