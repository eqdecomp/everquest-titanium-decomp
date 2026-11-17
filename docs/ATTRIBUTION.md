# Attribution

[Overview](ARCHITECTURE.md) | [Source guide](README.md)

The code in this tree was rewritten from the original `eqgame.exe`; no source code from the projects below
is included. What they contributed are names: function, class and field names, opcode names, packet
layouts and constant values, used as facts to label code whose behaviour was read from the binary. Each name
was recorded with its source when it was given, and the source code comments say where a name or value
comes from.

## Sources

| Project | What was used | Where it shows |
|---|---|---|
| EQEmu (EQEmu/Server, `utils/patches/patch_Titanium.conf`, `common/patches/titanium_structs.h`, `common/patches/titanium_limits.h`, `common/classes.h`, `races.h`, `skills.h`, `spdat.h`) | opcode names and values; packet struct layouts (Spawn_Struct, PlayerProfile, MoveCoin_Struct, ...); constant names and values (classes, races, skills, spell effects, inventory slots) | `Handle_OP_*` handler names, the `OP_` names in `include/titanium/opcodes.h` and in the code, field names pinned by struct copies, the enum headers in `include/titanium/` |
| MacroQuest / MQ2 (MQ2Emu's Titanium `eqgame.h`, `EQClasses.h`, `EQData.h`, `EQUIStructs.h`) | function names at exact addresses, class layouts and field names, window class and global names (`pinst...`) | `include/titanium/core_decls.h`, `include/titanium/types.h`, bare (no `_guess`) names, field names |
| ShowEQ | a few names cross-checked against its packet and spawn definitions | a handful of names (counts below) |
| EverQuest Mac client symbols and the TAKP project's name lists | function and class names for code shared with the older client | many `_guess` names whose evidence cites the Mac client |

Names with none of these sources were made up here from what the code does (strings, call graph, data);
they all end in `_guess`.

## Counts

In this tree, 5,561 functions in `src/EverQuest/` carry a `// FUNCTION:` line. 85 still have a `FUN_<VA>`
placeholder name, 143 have a bare name (no `_guess`: a CRT or Windows symbol, or an exact-address MQ2 or Mac
symbol), and 115 are opcode handlers named `Handle_OP_<EQEmu name>_guess`. `include/titanium/wnd/` declares
104 window and UI classes (95 of them windows and dialogs), named after the client's window classes as
MQ2's `pinst...` globals spell them.

Where the names came from, from the name records of the main rename pass. A name can cite more than one
source, so the source columns overlap; "code only" counts names whose evidence cites none of them.
Later passes added names from the code that uses them.

Functions (2,125 renames by VA in the main pass):

| EQEmu | MQ2 | ShowEQ | Mac / TAKP | earlier sibling decomp | code only |
|---:|---:|---:|---:|---:|---:|
| 262 (106 of them `Handle_OP_*`) | 97 | 1 | 415 | 313 | 1,173 |

Fields (321 renames in the main field map): EQEmu struct evidence 243, MQ2 field names 203, code only 47.
A second field pass (223 decision rows, 152 renames) cites EQEmu in 34 rows and MQ2 in 3; the rest is from
the code. A third pass (577 renames) names fields from the code that uses them; EQEmu and MQ2 / ShowEQ names
were checked as references (the raid fields, the profile stat order at +0x11B4), and the spell record's
columns follow the spells_us.txt column order as EQEmu documents it.

Classes (179 renames in the main pass: 160 per-file classes, 19 families by constructor or vtable): 96 are
window classes (`C...Wnd` and similar) whose names match the client's XML screen names and MQ2's window
classes; the rest are named from the code.

Constants (enum entries in `include/titanium/`, names and values from EQEmu): spell effects 132, skills 78,
inventory slots 37, classes 25, races 15. Opcodes: `opcodes.h` has 383 `OP_` names with their values, all
from EQEmu's `patch_Titanium.conf`; the code uses them for 688 literals (sends, `case` labels, one compare). `core_decls.h` declares 45 functions and globals under MQ2's names.

Candidate pool (all names collected for `eqgame.exe` before review, 2,638 rows, not all used): Mac / TAKP
1,935, MQ2 263, earlier sibling decomp 189, EQEmu 109, ShowEQ 4, structural (vtable slots, exports,
destructor patterns) 138.

## Reference files

EQEmu's `titanium_structs.h`, `titanium_limits.h` and the constant lists were used as reference while naming
and checking. They are not part of this tree and are not shipped. The same holds for the MQ2 and ShowEQ
sources and the Mac / TAKP name lists: only the names and values listed above were taken.

## Licence

This tree is released under the MIT licence; see [LICENSE](../LICENSE). The licence covers this project's
own work only. It grants nothing in EverQuest or in the projects listed above.

## Trademarks

EverQuest is a registered trademark of its owner. This project is not affiliated with or endorsed by it.
