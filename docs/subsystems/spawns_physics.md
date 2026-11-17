# Spawns, animation and physics

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 8 | [Long page](../world.md)

Every entity in a zone is an `EQPlayer` (0x348 bytes) with a per-spawn actor-data block at +0x1A8. The
dispatcher creates, updates and deletes spawns; the physics code moves them each frame; the animation code
picks what the model plays; missiles fly as their own objects.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_053_EQPlayer.cpp` | `EQPlayer_guess` | constructor, copy from the spawn record, attacks |
| `tu_042_EQHandleMsg.cpp` | `Handle_OP_*Spawn*_guess`, `Handle_OP_ClientUpdate_guess` | spawn messages |
| `tu_055_Movement.cpp`, `tu_056_EQMovePlayer.cpp` | `State_48995D_guess`, `Player_48BA76_guess` | floor height, collision sweep, movement state |
| `tu_081_Physics.cpp` | `process_physics` | per-spawn integration step |
| `tu_029_Display.cpp` | `ProcessPlayerPhysics_guess` | per-frame physics for spawns other than ours |
| `tu_039_EQAnimate.cpp` | `OldPlayerAnimationSetView_guess`, `InitAnimationTags_guess` | animation choice and tables |
| `tu_057_RaceTagTable.cpp` | `RaceTagTable_guess` | race and gender to model code |
| `tu_047_EQMissile.cpp` | `EQMissile_guess`, `MotionObject_guess` | missiles |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x004850A0 | `EQPlayer_guess::EQPlayer_guess(source, gender, race, class, name)` | builds a spawn; a source name of 0x40 or more characters becomes "NameTooLong" |
| 0x004554E5 | `Handle_OP_NewSpawn_guess` | an id already present only gets name, level and +0x1A0 refreshed; otherwise `new EQPlayer`, first physics state, pet id link, and our own character gets StandState 100 |
| 0x00455710 | `Handle_OP_ZoneSpawns_guess` | the zone-in batch: 0x181-byte spawn records, each id not yet known built as in OP_NewSpawn |
| 0x004581B7 | `Handle_OP_DeleteSpawn_guess` | resolves the id; clears references held elsewhere before removal (a pending challenge, answered with OP_DuelDecline (0x3BAD); saved name slots at 0x00904390) |
| 0x00451ABA | `Handle_OP_ClientUpdate_guess` | position update; for an unknown id while in game (state 5) sends OP_ConfirmDelete (0x3838) at most every 15 s; a spawn riding a mount (+0x15C) is unpacked into the mount |
| 0x0045242F | `Handle_OP_SpawnAppearance_guess` | {spawn id (0 = self), type, value}: one case per type, e.g. 0x18 AFK, 0x16 guild id, 0x1D size, 0x23-0x25 area regen in thousandths, 0x2B show helm |
| 0x00436039 | `ProcessPlayerPhysics_guess(player)` | skips the controlled spawn, our own spawn and the boat at actor +0x158; after 12 s without an update, skips a Type >= 1 spawn whose SpeedRun and SpeedZ are both 0 (one with only SpeedZ set still moves) and, while 0x00923884 is 0, any other spawn; otherwise `process_physics` then `MovePlayer_guess` |
| 0x004BFE0F | `process_physics(player, obj2, obj3)` | dt = elapsed ms x 0.02, capped at 3; a rider copies its mount's position and heading and stops; dead spawns (StandState 120) lose speed; races at or above 0x8CD are skipped |
| 0x0048ACEF | `Player_48BA76_guess::Pick_48ACEF_guess` | per-move collision sweep, stuck test, commit or restore |
| 0x00450C2F | `OldPlayerAnimationSetView_guess::SetAnim_guess(anim, ...)` | refuses ids from 0x4F, races from 0x1DB, spawns without actor or model, and spawns with HP below 10 that are at 0 HP or lying (115: feign death or knocked out) or dead (120), except animation 0x10 |
| 0x0044E7E4 | `InitAnimationTags_guess` | fills the 3-character track tags (0x14-byte rows from 0x008FFBC8, `g_animTrackTags_guess`) and the 4-letter animation names (5-byte rows from 0x009001F8, `g_animNames_guess`) |
| 0x0048C8AF | `RaceTagTable_guess` constructor | one entry per (race, gender 0/1/2) with the model code |
| 0x00476B12 | `MotionObject_guess::CreateActorWhenReady_guess` (waits, then creates the actor) | missile step: resolves its target, keeps a 120 s deadline |
| 0x004766AA | `MotionObject_guess::TrackTarget_guess` | missile turn toward the target |

## Data flow

```
OP_NewSpawn / OP_ZoneSpawns  -> 0x004554E5 / 0x00455710 -> new EQPlayer 0x004850A0 -> spawn list
OP_ClientUpdate (and batch 0x4BB4) -> 0x00451ABA -> unpack into Y, X, Z, heading, speeds
each frame: CDisplay frame 0x00445243 -> the controlled spawn's actor +0x158 spawn, the controlled spawn
                           and our own spawn moved directly
                           -> ProcessPlayerPhysics_guess 0x00436039 per other spawn
                                -> process_physics 0x004BFE0F -> MovePlayer_guess
            animation      -> SetAnim_guess 0x00450C2F
OP_DeleteSpawn -> 0x004581B7
```

## Key globals and structs

| Address / offset | What |
|---|---|
| 0x00905CC4 | head of the spawn list |
| 0x00905CE4 / 0x00905CF8 | our own spawn / the controlled spawn |
| EQPlayer +0x30/+0x34/+0x38 | Y, X, Z |
| EQPlayer +0x1A8 | actor data (`pActorInfo`); +0x158 boat, +0x15C mount, +0x160 rider link, +0xEBC last update time |
| EQPlayer +0x244 / +0x251 | Type / StandState (100 standing, 110 sitting, 115 lying: feign death or knocked out, 120 dead) |
| 0x008FFBC8 / 0x009001F8 | track tags / animation names (`g_animTrackTags_guess` / `g_animNames_guess`) |

## Known client bugs

- [B14](../KNOWN_CLIENT_BUGS.md#spawns-animation-and-missiles-tu_039_eqanimate-tu_047_eqmissile): `SetAnim_guess` 0x00450C2F
  uses an animation sink without a null test in one branch.
- [B28, B29, B31](../KNOWN_CLIENT_BUGS.md#spawns-animation-and-missiles-tu_039_eqanimate-tu_047_eqmissile): missile turn
  0x004766AA `TrackTarget_guess`.
- [B30](../KNOWN_CLIENT_BUGS.md#spawns-animation-and-missiles-tu_039_eqanimate-tu_047_eqmissile): `MotionObject_guess::CreateActorWhenReady_guess` 0x00476B12
  reads the state's last-update time before its null test.
- [X01](../KNOWN_CLIENT_BUGS.md#server-data-used-without-checks): the batch position update 0x4BB4 feeds
  `Handle_OP_ClientUpdate_guess` past the packet end.
