# Zone and world

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) sections 5, 7 | [Long page](../world.md)

The world view is `CDisplay`: it loads a zone's files, owns the actors, the camera and the light. Entering
and leaving a zone is driven from CEverQuest: reset the per-zone state, load the zone, ask the server for
its data, and on a zone change ask the server first, save, and drop our spawn.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_029_Display.cpp` | `CDisplay_guess` | zone load, light, per-frame world work, UI life cycle |
| `tu_062_EverQuest.cpp` | `CEverQuest_guess` / `GlobalState_guess` (both CEverQuest) | `EnterZone`, `MoveToZone_guess`, `IsZoneAvailable_guess`, `SavePCOnZone_guess` |
| `tu_042_EQHandleMsg.cpp` | dispatcher cases | zone header, time, weather |
| `tu_084_Weather.cpp` | `Weather_guess` | rain, snow and lightning state |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x004A861D | `CEverQuest_guess::EnterZone` | clears the held keys (0x00925520, 0x100 entries) and many per-zone globals, turns auto-attack and auto-fire off, takes the zone from the profile, logs the world init, calls `LoadZone_guess`; on success sends OP_ReqNewZone (0x7AC5, unless offline), resets the cameras and vision colours |
| 0x00444116 | `CDisplay_guess::LoadZone_guess(zone)` | zone 188 shows a slide show; tries <zone>.eqg, else the `.s3d` must exist (zones 130 and 180 exempt); then <zone>_pre_chr.txt, the object files (`_obj2`, `_obj`, `_2_obj`, language variants first) and character files (`_chr2`, `2_chr`, `_chr`) |
| 0x00499139 | `GlobalState_guess::IsZoneAvailable_guess(zone, y, x, z, mode)` | zone 75 needs its `.s3d`; sends OP_ZoneChange (0x5DD8, 0x58 bytes) and pumps the connection until the reply or 180 s; returns the server's status, or -4 when the connection dropped to character select |
| 0x004AB056 | `GlobalState_guess::MoveToZone_guess(zone, reason, home, mode, y, x, z, heading)` | refuses with no spawn or stand state 102; asks `IsZoneAvailable_guess`; on refusal prints a reason by status, or for an unavailable home zone goes back to character select (OP_Logout, 0x61FF); on success sets the new position, saves (`SavePCOnZone_guess`), sends OP_DeleteSpawn (0x55BC) for our spawn, sets the zone-change flag 0x00923D7A and waits for the disconnect |
| 0x004976BF | `GlobalState_guess::SavePCOnZone_guess` | sends OP_SaveOnZoneReq (0x1540) |
| 0x00441295 | `CDisplay_guess::SetAmbientLight_guess` | light from the hourly sky tables or fixed values by zone type; eases by 0.01 per call |
| 0x0043745D | `CDisplay_guess::GetValue2cf8_guess` | the "world is displayed" flag that gates the dispatcher's second switch |
| 0x004C334D | `State_guess::Set_guess` (weather) | applies an OP_Weather packet |

## Data flow

```
zone-in:   EnterZone 0x004A861D -> LoadZone_guess 0x00444116 -> OP_ReqNewZone (0x7AC5)
           server: OP_NewZone (0x0920) -> zone header (0x2BC bytes copied; two range fields default to 500 / 600 when both are 0)
                   OP_TimeOfDay (0x1580), OP_Weather (0x254D) -> weather singleton 0x004C334D
zone out:  portal / GM / bind / boat ... -> MoveToZone_guess 0x004AB056
             -> IsZoneAvailable_guess 0x00499139 (OP_ZoneChange 0x5DD8, wait)
             -> SavePCOnZone_guess 0x004976BF (OP_SaveOnZoneReq, 0x1540), OP_DeleteSpawn (0x55BC)
             -> zone-change flag 0x00923D7A -> the frame loop returns, the session loop enters the next zone
```

## Key globals

| Address | What |
|---|---|
| 0x00905D24 | `pinstCDisplay` |
| 0x009239E0 | zone header (short name written here by `EnterZone`) |
| 0x00923D7A | zone change pending |
| 0x00923D94 | leave reason (8 when the home zone is unavailable) |
| 0x00923798 / 0x00923884 | offline flags: no zone requests are sent, the position is kept locally |

## Known client bugs

- [B27](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd): profile
  load 0x004BA0FB `LoadProfile_guess` writes one position field twice.
- [B05](../KNOWN_CLIENT_BUGS.md#character-rules-and-combat-tu_013_eq_character): the periodic save under Tick never runs.
