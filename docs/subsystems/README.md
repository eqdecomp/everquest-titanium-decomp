# Subsystem pages

[Overview](../ARCHITECTURE.md) | [Source guide](../README.md) | [Known client bugs](../KNOWN_CLIENT_BUGS.md)

One short page per subsystem named in the overview: purpose, files and classes, key functions with their
VAs, data flow, key globals, and the known client bugs that touch it. Names are the source names; the VA is the stable key:
grep for `FUNCTION: TITANIUM 0x<VA>` to find a function. Opcodes are the `OP_` names of
`include/titanium/opcodes.h` (EQEmu's names) with the value in parentheses; values without a unique EQEmu name
are numbers in the code. The longer pages beside the overview give more detail.

## Index

| Page | Covers | Main files |
|---|---|---|
| [network.md](network.md) | connections, the send path, world login, the message dispatcher | `tu_017_ConnectionManager.cpp`, `tu_042_EQHandleMsg.cpp`, `tu_073_login.cpp` |
| [zone_world.md](zone_world.md) | entering, loading and leaving a zone; light and weather | `tu_029_Display.cpp`, `tu_062_EverQuest.cpp`, `tu_084_Weather.cpp` |
| [spawns_physics.md](spawns_physics.md) | EQPlayer, spawn messages, physics, animation, missiles | `tu_053_EQPlayer.cpp`, `tu_081_Physics.cpp`, `tu_039_EQAnimate.cpp`, `tu_047_EQMissile.cpp` |
| [items_inventory.md](items_inventory.md) | item packets, placement by mode, slot numbers, moves | `tu_069_KeypressHandler.cpp`, `tu_172_InvSlotMgr.cpp`, `tu_077_ItemMoveQueue.cpp` |
| [spells_buffs.md](spells_buffs.md) | spell table, the cast gate, landing, buff stacking, SPA totals | `tu_012_CharacterMagicSystem.cpp`, `tu_038_EQ_Spell.cpp` |
| [chat_commands.md](chat_commands.md) | key commands, typed commands and channels, chat windows | `tu_044_ExecuteCmd.cpp`, `tu_062_EverQuest.cpp`, `tu_143_ChatManager.cpp`, `tu_144_ChatWindow.cpp` |
| [ui.md](ui.md) | skin and XML loading, window life cycle, window classes | `tu_029_Display.cpp`, `tu_099_ActionsWnd` .. `tu_236_VideoModesWnd` |
| [rendering_sound.md](rendering_sound.md) | graphics DLL load, one world frame, sound manager | `tu_097_Win.cpp`, `tu_029_Display.cpp`, `tu_037_EQ_SoundManager.cpp`, `tu_087_SoundManager.cpp` |
| [character_combat.md](character_combat.md) | the character tick, stats and HP, damage, stun, skills, swings, stand states | `tu_013_EQ_Character.cpp`, `tu_053_EQPlayer.cpp`, `tu_042_EQHandleMsg.cpp` |
| [guild_group_tasks.md](guild_group_tasks.md) | guild, group, raid, task, tribute, adventure and expedition managers and where the dispatcher sends their messages | `tu_010_guilds.cpp`, `tu_025_Raid.cpp`, `tu_026_TaskManager.cpp`, `tu_008_AdventureManager.cpp`, `tu_031_Expedition.cpp` |

Not given its own page here: process start and the main loop ([startup.md](../startup.md)).
