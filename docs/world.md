# World: CEverQuest, CDisplay, spawns and the character

[Overview](ARCHITECTURE.md) sections 3, 8 and 9 | [Source guide](README.md)

Four central objects, reached through globals (`EQPlayer` has one instance per spawn; its globals are the local
player and the target):

| object | global | size | constructor | main files |
|---|---|---|---|---|
| `CEverQuest` | `pEverQuest` 0x00988DF0 | 0x3A1C8 | 0x004A3341 | tu_062_EverQuest, tu_042_EQHandleMsg, tu_023_SystemCommands, tu_063_Options |
| `CDisplay` | `pinstCDisplay` 0x00905D24 | | 0x0043DA73 | tu_029_Display, tu_049_EQMoveMissle, tu_084_Weather |
| `EQPlayer` (one per spawn) | `pinstLocalPlayer` 0x00905CE4, `pinstTarget` 0x00905D04 | 0x348 | 0x004850A0 | tu_053_EQPlayer, tu_057_RaceTagTable, tu_055_Movement |
| `EQ_PC` (the character) | `pCharData` 0x00905D00 | 0xC4D0 | 0x004BF2A7 | tu_080_EQ_PC, tu_013_EQ_Character (EQ_Character) |

Sizes come from the `operator new` call before each constructor (`include/titanium/types.h`).

```
CEverQuest  ---- game state, chat, commands, network handlers
   |  owns the session: ProcessGame_guess -> DoMainLoop (startup.md)
   v
CDisplay    ---- the world view: zone load, actors, camera, sky, UI setup, Render_World
   |  creates an actor in the graphics DLL for each EQPlayer (rendering.md)
   v
EQPlayer    ---- a spawn: position, appearance, animation; list at 0x00905CC4, id table at 0x00900F50
   ^
   |  pSpawn (EQ_PC +0xC288)
EQ_PC       ---- the local character: stats, inventory, buffs, skills (EQ_Character base)
```

## CEverQuest
One object per game session (created in ExecuteEverQuest_guess and deleted when that session ends; see [startup.md](startup.md)). Its
methods are spread over four files because the original `EverQuest.cpp` split across objects; tu_062_EverQuest holds
the constructor (0x004A3341), destructor (0x00497395) and most of the class. In the source the class is still
called `GlobalState_guess`, `CEverQuest_guess`, `EverQuestSelf_guess` and others depending on the file.
`GlobalState_guess` is a second view of `CEverQuest` with no constructor or vtable of its own, so a rename
by family does not reach it; read it as `CEverQuest`.

| VA | name | file | what |
|---|---|---|---|
| 0x0049377D | `DoLogin_guess` | tu_062_EverQuest | world login, spell table, display init ([startup.md](startup.md)) |
| 0x00494B3D | `SetGameState` | tu_062_EverQuest | stores the state, enables key-command groups |
| 0x004ABA14 | `DoMainLoop` | tu_062_EverQuest | the per-frame loop while state is 5 |
| 0x0045B8F0 | `HandleWorldMessage_guess` | tu_042_EQHandleMsg | the opcode switch ([network.md](network.md)) |
| 0x004982C6 | `dsp_chat(text, color, flag)` | tu_062_EverQuest | prints a line to chat (in `core_decls.h`; `DspChat_guess` in tu_062_EverQuest) |
| 0x00498B78 | `InterpretCmd` | tu_062_EverQuest | parses a typed line; slash commands are in tu_046_EQMisc |
| 0x0049B39D | `StartCasting_guess` | tu_062_EverQuest | see [spells.md](spells.md) |
| 0x004A8193 | `GetZoneInfoFromNetwork` | tu_062_EverQuest | sends OP_ZoneEntry, waits for the zone's answer |
| 0x004A861D | `EnterZone` | tu_062_EverQuest | calls `CDisplay::LoadZone_guess` |
| 0x004971AD | `LoadStringTables_guess` | tu_062_EverQuest | reads eqstr_<lang>.txt and dbstr_<lang>.txt |

Text shown to the player comes from the string table: `pStringTable->getString(id, 0)` (0x005DFA00,
`pStringTable` 0x00905CB0). Comments name the string id's text where it matters; ids are hex in the code and
decimal in eqstr_us.txt.

## CDisplay (tu_029_Display)
The view of the world and the owner of the UI's life cycle. tu_029_Display has 173 functions. The class family of
constructor 0x0043DA73 is `CDisplay_guess` in every file that declares it (tu_029_Display and tu_062_EverQuest). Other tu_029_Display
views of `CDisplay` (`CoordinateService_guess`, `AngleMath_guess`, ...) keep their own names.

| VA | name | what |
|---|---|---|
| 0x00443F8F | `InitDisplay_guess` | display start-up; calls `InitNewUI_guess` |
| 0x0043DF32 | `InitWorld_guess` (Mac `CDisplay::InitWorld`) | loads GlobalLoad.txt, render options and the sky; called once, from `DoLogin_guess` |
| 0x00444116 | `LoadZone_guess` (Mac name: `StartWorldDisplay`) | starts the zone's display; called by `EnterZone` and `StartNetworkGame` |
| 0x0044350D | `StopWorldDisplay_guess` | unloads the zone |
| 0x00442D80 | `InitNewUI_guess` | loads the XML UI ([ui.md](ui.md)) |
| 0x0043EFDD / 0x0043EE74 | `InitGameUI_guess` / `InitCharSelectUI_guess` | create the windows |
| 0x0043AF46 / 0x00443DBC | `CleanGameUI` / `ReloadUI` | tear down / rebuild them |
| 0x0043972A / 0x00439A46 | `CreateActor_guess` / `DeleteActor_guess` | graphics-side actor for a spawn |
| 0x0043C84B | `CreatePlayerActor` | |
| 0x0043A2CE | `SetupEQPlayers_guess` (Mac `CDisplay::SetupEQPlayers`) | walks the spawn list and sets each spawn's floor height |
| 0x00439F26 | `GetFloorHeight_guess` | collision query through the graphics DLL |
| 0x00445A6C -> 0x00445243 | `Render_World_guess` -> `RealRender_World_guess` | one frame ([rendering.md](rendering.md)) |
| 0x00439BD1-0x00439D16 | `SimpleDistance_guess`, `TrueDistance_guess`, `PlayerDistance_guess`, ... | distance helpers |

tu_049_EQMoveMissle and tu_084_Weather hold a few more `CDisplay` methods (tu_049_EQMoveMissle: `CDisplayView_guess::MoveMissile_guess` 0x00477CC9, the Mac client's MoveMissile).

## EQPlayer: spawns (tu_053_EQPlayer, tu_057_RaceTagTable)
Every visible entity (player, NPC, corpse, the local player) is an `EQPlayer`. It has no vtable: the
constructor (0x004850A0) stores the byte 3 at +0. Fields named in `types.h` include position `Y/X/Z` at
+0x30, `Heading` +0x4C, `Name` +0x120, `pActorInfo` +0x1A8 (the most used field: animation and actor state,
0x10C0 bytes), `pNext` +0x214 / `pPrev` +0x220, `Type` +0x244, `Level` +0x24C, `SpawnID` +0x258, `Race` +0x260.
The `types.h` labels at +0x245..+0x24A look shifted (hair style is written to +0x249, labelled `Eyes2`); those
fields were not renamed.

Fields settled in review (the server's spawn record is copied field by field in 0x004816D7):
- +0x1A0 is the bounding radius (from Spawn_Struct +0x158; field `boundingRadius_01a0_guess`), not MQ2's
  `SpeedHeading`.
- +0x1B2 is the linkdead flag: copied from Spawn_Struct +0x90, the byte EQEmu labels `is_npc`, and shown by the
  client only as " <LINKDEAD>" / " LD".
- +0x251 is StandState: 100 standing, 102 no control of yourself (stun, mez, charm), 110 sitting, 111 ducking,
  115 (0x73) lying: feign death, and knocked out (`KnockedOut_guess` 0x00484DF5 sets 115 and character state 3;
  `GetConscious_guess` 0x00484D8D clears it), 120 dead. `ExecuteCmd` 0x004619CD and `DoPassageOfTime_guess`
  0x00422198 test these values.
- +0x25C is the owner's spawn id (for a pet).
- In the actor data (`pActorInfo`): +0x158 is the boat being ridden (`DoPassageOfTime_guess` sends its name as
  OP_BoardBoat), +0x15C the mount.

In tu_053_EQPlayer the class is `EQPlayer_guess` plus per-TU views: `EQPlayerCore_guess`, `EQPlayerRaceView_guess`,
`EQPlayerStatusView_guess`, `EQPlayerArmorView_guess`, `EQPlayerBoneView_guess`, `EQPlayerPcView_guess`,
`ActorInfoView_guess`. The animation family of 0x00485E40 is
`PlayerAnimation_guess`.

Two ways to find a spawn:
- the list starting at 0x00905CC4, linked through `pNext` (render and update loops walk it);
- the id table at 0x00900F50: `GetSpawnByID_guess(id)` (0x00401B28, tu_002_ProgressionData; the earlier sibling decomp calls it
  `GetPlayerFromID`) returns entry `id` for 0 < id < 3000, else null.

| VA | handler / method | what |
|---|---|---|
| 0x004554E5 | `Handle_OP_NewSpawn_guess` | updates a spawn that already exists, else `new EQPlayer(...)` (0x348 bytes) |
| 0x00455710 | `Handle_OP_ZoneSpawns_guess` | the zone's spawn list on entry |
| 0x004581B7 | `Handle_OP_DeleteSpawn_guess` | removes a spawn by id; if it was the pending duel partner, prints a notice and sends OP_DuelDecline (0x3BAD) |
| 0x00451ABA | `Handle_OP_ClientUpdate_guess` | position updates: unpacks packed records into spawn positions |
| 0x0045242F | `Handle_OP_SpawnAppearance_guess` | appearance changes |
| 0x00452C54 | `Handle_OP_Damage_guess` | |
| 0x004850A0 / 0x004849B2 | `EQPlayer` ctor / dtor (tu_053_EQPlayer) | both matched |
| 0x0047C3EF | `SetName_guess` | |
| 0x0047F614 | `IWasHit_guess` | calls `EQ_Character::HitBySpell` for spell hits |
| 0x00484E79 | `IDied_guess` | |
| 0x0048297B | `EQPlayerCore_guess::DoAttack` | |

Movement and physics for the local player are in tu_055_Movement and tu_056_EQMovePlayer. In tu_055 the class
is still the placeholder view `State_48995D_guess`: 0x0048A0FC `GetFloorHeightAt_guess` returns the floor height under a point (-1e27 when the spawn has no actor data), and
0x0048A945 `Update_48A945_guess` follows it at its call sites (`CDisplay_guess::MoveLocalPlayerToSafeCoords_guess`
0x0043D7C5 and two places in tu_012_CharacterMagicSystem); 0x0048B6C5 `CheckForUnderFloor_guess` is called by
`process_physics` 0x004BFE0F.

## EQ_PC and EQ_Character: the local character (tu_080_EQ_PC, tu_013_EQ_Character)
`EQ_PC` (0xC4D0 bytes, allocated by `StartNetworkGame` 0x004AA92B and `ProcessGame_guess`) uses multiple and
virtual inheritance: a second base at +0xC280 and the virtual base `EQ_Character` at +0xC384 (see the
comment in `types.h`). `pCharData` points at it; `EQ_Character::GetCharInfo2` (0x005EC220, not rewritten: one of the 0x005E....
helpers) returns the profile data that most code reads. The `EQ_PC` stores its spawn at +0xC288 (field
`pSpawn_c288_guess`). The tu_080_EQ_PC views are `EQ_PCView_guess`, `PcCharacterView_guess`, `CharInfo2View_guess`
and others; 17 of their fields carry MQ2's Titanium names (race, class, level, coins, hunger, thirst, STR, STA,
skills, mana, ...).

The profile block (the `GetCharInfo2` result), as settled in review:

| offset | field | evidence |
|---|---|---|
| +0x0730 | the spell book, 0x200 entries | bounded accessor 0x0041AA26 |
| +0x1198 | race | container checks in 0x004FC106 |
| +0x119C | class | lexicon checks in 0x004FC106, the bard-song test 0x0040DB0B |
| +0x11A4 | level | |
| +0x11A8 | mana | `HitBySpell` 0x00414913 SPA 15 branch, `CastSpell` 0x00411F3D mana test |
| +0x11AC | endurance (not HP) | added through 0x0040E2BD for SPA 189 and 198 |
| +0x11D4 .. +0x11E0 | platinum, gold, silver, copper carried | |
| +0x11E4 .. +0x11F0 | the same four on the cursor | sent as OP_MoveCoin by 0x004BE5FE |

tu_013_EQ_Character (149 functions) holds the character rules: `UseSkill_guess` (0x0041F4A0),
`TakeDamage_guess` (0x0041C905), `TakeFallDamage_guess` (0x00420DEC: damage from fall height and weight,
reduced below 9 units by the Safe Fall skill (39) and its SPA 228 bonus, which sends OP_SafeFallSuccess (0x3B21)), `DoPassageOfTime_guess` (0x00422198),
`encum_factor_guess` (0x004193C5, the Mac client's `encum_factor`), `Max_Endurance` (0x00416A40).
`DoPassageOfTime_guess` runs once per drawn frame (from `RealRender_World_guess` 0x00445243, which `DoMainLoop`
reaches through `Render_World_guess` 0x00445A6C; not while paused); the buff tick is its 6-second part. In the
source these methods sit on different views of `EQ_Character` (`SkillUser_guess`, `CostOwner_guess`,
`TickUser_guess`).
The profile arrives in OP_PlayerProfile (case 0x75DF), handled by the `EQ_PC` method
`Handle_OP_PlayerProfile_guess` (0x004BA899, tu_079_PlayerProfile).

## Zoning
See the message table in [network.md](network.md). On the game side, `ProcessGame_guess` calls
`StopWorldDisplay_guess`, `GetZoneInfoFromNetwork` and `EnterZone` (which calls `CDisplay::LoadZone_guess`),
then `DoMainLoop` runs again. `MoveLocalPlayerToSafeCoords_guess` (0x0043D7C5) is called from the
dispatcher, `DoMainLoop` and the physics check `CheckForUnderFloor_guess` (0x0048B6C5, tu_055_Movement, called by
`process_physics` 0x004BFE0F); by its name it puts the player back on safe ground.
