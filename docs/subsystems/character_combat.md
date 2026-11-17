# Character rules and combat

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) sections 9 and 12 | [Long page](../world.md)

The character (`pCharData`, an EQ_PC) carries the rules: stats, hit points, the per-frame tick, damage,
stun and skills. The server decides hits. The client keeps the swing and skill timers, mirrors the damage
rules for characters it simulates, and reports its own state changes (target, auto-attack, run mode, stand
state) to the server.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_013_EQ_Character.cpp` | `TickUser_guess`, `CostOwner_guess`, `SkillUser_guess`, `RankOwner_guess` (the inventory view), `RankTotalsOwner_guess`, `DynamicPropertyOwner_guess` (views of EQ_Character) | tick, stats, HP, damage, stun, skills, hunger and thirst |
| `tu_053_EQPlayer.cpp` | `EQPlayerCore_guess`, `EQPlayer_guess` | swings, stand state, knock-out, death |
| `tu_042_EQHandleMsg.cpp` | dispatcher cases, `Handle_OP_Damage_guess` | incoming damage, death, HP and stun messages |
| `tu_062_EverQuest.cpp` | `EverQuestSelf_guess`, `EverQuestReport_guess` | death report, consider |
| `tu_029_Display.cpp` | `CDisplay_guess` | runs the tick once per drawn frame |
| `tu_080_EQ_PC.cpp` | `EQ_PCView_guess` | group tests the tick uses |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x00422198 | `TickUser_guess::DoPassageOfTime_guess()` | the per-frame character tick (below) |
| 0x004212B3 | `RankTotalsOwner_guess::Recalculate_guess()` | clears and re-adds the worn-item stat bonuses (21 worn slots plus 7 more entries); first step of the tick |
| 0x00416963 | `CostOwner_guess::Max_HP_guess(mode)` (max HP) | max HP: base formula, + SPA 214 (in 1/100 percent) and + 5 when mode is 0, + SPA 69; caps at 10,000,000 and caches it on the spawn |
| 0x00417E07 | `CostOwner_guess::Cur_HP(mode)` | current HP: stored value + bonus, written to spawn +0x274, clipped to max (which resets the stored value), cap 10,000,000 |
| 0x00418EBF | `CostOwner_guess::Str_guess()` | STR: profile +0x11B4, item total, SPA 159 (all stats) and SPA 4, then the shared cap step |
| 0x00417839 | `CostOwner_guess::StunMe_guess(duration, ...)` (StunMe in the earlier sibling decomp) | stun: none under Divine Aura (SPA 40); at least 1 s for a player; sets the stun end time and state 1, string 0x30BF |
| 0x0041C905 | `CostOwner_guess::TakeDamage_guess(damage, record, notify, ...)` | one damage record on a simulated character (below) |
| 0x00420DEC | `CostOwner_guess::TakeFallDamage_guess(height)` | fall damage from height + 1% of +0x48 - 1.5 (20000 at 9 or more); below 9, Safe Fall (skill 39, plus its SPA 228 bonus) lowers it and sends OP_SafeFallSuccess (0x3B21); passed to TakeDamage as type 0xFC |
| 0x0041F4A0 | `SkillUser_guess::UseSkill_guess(skill, ...)` | a skill button: gates, reuse timer, then one case per skill (below) |
| 0x0048297B | `EQPlayerCore_guess::DoAttack(kind, skill, target)` | one swing: `kind` 11 range, 13 primary, 14 secondary, 100 a skill attack, 0x65 primary or bare hand; a skill attack or bare-hand swing needs stand state 100 (else string 0x3050 at 102, 0x3051 otherwise) and range (`CanIHit_guess`), then `DoMissileHit_guess` |
| 0x00483556 | `EQPlayer_guess::ChangePosition_guess(state)` | sets the stand state, refuses to stand into a ceiling, sends OP_SpawnAppearance (0x7C32, type 14), plays the animation; sitting stamps actor +0x70 for rest regen |
| 0x00484DF5 | `EQPlayer_guess::KnockedOut_guess()` | sets stand state 115 (0x73, lying: the value feign death also uses) and, for our spawn, character state 3, which is what marks the knock-out (string 0x324D) |
| 0x00484D8D | `EQPlayer_guess::GetConscious_guess()` | clears state 3 (string 0x324C), kneels, then stands (100) |
| 0x00484E79 | `EQPlayer_guess::IDied_guess(message)` | Type 2, stand state 120, renamed to a corpse |
| 0x00420F51 | `InventoryView_guess::ProcessHungerandThirst_guess(now)` | food and water; with spawn +0x256 set both stay at 32000 |
| 0x00452C54 | `Handle_OP_Damage_guess(packet)` | OP_Damage (0x5C78, switch 2): damage to us lowers HP at once, except type 0xE7 |
| 0x004A8CD5 | `EverQuestSelf_guess::ReportDeath_guess(packet)` | OP_Death (0x6160, switch 2): settles a duel, closes windows on the corpse, drops it as target and stops auto-attack, prints the death line |
| 0x0049BEB8 | `EverQuestReport_guess::Consider` | OP_Consider (0x65CA, switch 1) |

### The tick (0x00422198)

`CDisplay_guess::RealRender_World_guess` (0x00445243) calls it on the character's +0xC280 part unless the
game is paused (0x00905CA4); DoMainLoop reaches it through `Render_World_guess` (0x00445A6C). Each call:

```
UI resync if asked; tells the server about changes: run mode OP_SetRunMode (0x4ABA), target OP_TargetMouse (0x6C47, body types 11, 60, 65, 67 cannot be targeted), auto-attack OP_AutoAttack (0x5E55) and
  OP_AutoAttack2 (0x0701), auto-fire OP_AutoFire (0x6C53)
Recalculate 0x004212B3; stop here when the character state is 4
poison application done after SPA 234 ms (default 10 s) -> OP_ApplyPoison (0x0C2C)
stun end (actor +0xD0) -> state 0 unless mezzed (SPA 31); 0 HP or less -> KnockedOut, above 0 -> GetConscious
swing timers: delay = item delay x 100 ms (bare hand: skill reuse), hasted by 0x0047F01E `EQPlayerCore_guess::ModifyAttackSpeed_guess` (Mac ModifyAttackSpeed) -> ready bytes
skill timers for 0x4A skills (Mend, Hide, Sneak and Bind Wound have their own rules) -> ready bytes
tracking (state 0x35) every 2 s; hiding ends on a move (not for a sneaking rogue); camping ends unless
  sitting, else counts down, then OP_Logout (0x61FF)
every 1 s:  tribute timers, root / movement speed, visibility, air supply, environmental damage,
            fishing, boat: OP_BoardBoat (0x4298) / OP_LeaveBoat (0x67C9) when actor +0x158 changes
every 6 s:  drunkenness, buff tick 0x00413AE4, fatigue, HP regen (item regen capped at 30, more above
            level 60 and 65, + SPA 317; base regen with a sitting bonus; below level 21 with the newbie
            rule 10 sitting / 6 else), endurance through 0x0040E2BD, mana regen 0x0041E361 `RegenMana_guess`
every 18 s / 60 s: smaller counters
hunger and thirst 0x00420F51 `ProcessHungerandThirst_guess`
death check (online only): HP below -10 - SPA 328 -> a damage record to OnDamage
local cast completion (offline only); then the social-macro player (one line per 100 ms, /pause)
```

### TakeDamage (0x0041C905)

Does nothing for stand state 102, a linkdead spawn or character state 4. Divine Aura (SPA 40) makes damage -5 unless the spell is 982, its first effect is SPA 145, or mode is zero. Environmental types (0xF4, 0xF6, 0xFA-0xFD) to us go out as OP_EnvDamage (0x31B3). Then: mez
(SPA 31) buffs are removed; a spin stun (SPA 64) may break; negate-attack charges (SPA 163); runes (SPA 55,
and SPA 78 for spell type 0xE7) absorb first and may trigger SPA 333; melee mitigation (SPA 162); the HP
change; KnockedOut at 0 HP; a bash (type 10) or a level 55+ warrior kick (type 30) rolls a stun; death at
-10 - SPA 328 (0 for NPCs) goes to the death slot; otherwise OP_Damage (0x5C78, 0x17 bytes) unless an offline
flag is set.

### UseSkill (0x0041F4A0)

Refused with no HP, at stand state 102 (string 0x3050), or on a mount / under SPA 113 for all but a few
skills (string 0x3069). Melee skills go to `DoAttack(100, skill, target)`. Others need the ready byte, set
the reuse timer (less SPA 227 seconds) and send their own message: Feign Death stands at 115, stops
auto-attack and sends OP_FeignDeath (0x7489) with the last damage source (0x00923848); Bind Wound
OP_Bind_Wound (0x601D, kneels from standing); Mend OP_Mend (0x14EF); Hide OP_Hide (0x4312); Sneak OP_Sneak (0x74E1); Forage OP_Forage (0x4796); Sense Heading OP_SenseHeading (0x05AC); Fishing OP_Fishing (0x0B36); Tracking
OP_TrackUnknown (0x6177); Pick Pockets OP_PickPocket (0x2AD8); Taunt OP_Taunt (0x5E48); Intimidation
OP_InstillDoubt (0x389E); Begging OP_Begging (0x13E7); Disarm OP_Disarm (0x17D9); Sense / Disarm Traps OP_SenseTraps (0x5666) / OP_DisarmTraps (0x1241), with 0x07A8 / 0x41B9 for an LDoN chest.

## Stand states (EQPlayer +0x251)

| Value | Meaning | Where |
|---|---|---|
| 100 (0x64) | standing | needed by DoAttack and most spells |
| 102 (0x66) | no control | TakeDamage, UseSkill and DoAttack refuse |
| 105 (0x69) | kneeling | Bind Wound from standing; GetConscious passes through it |
| 110 (0x6E) | sitting | rest regen in the tick; refused while mounted |
| 111 (0x6F) | ducking | |
| 115 (0x73) | lying: feign death or knocked out | UseSkill Feign Death; KnockedOut 0x00484DF5 (which also sets character state 3) |
| 120 (0x78) | dead | IDied |

`CastSpell` (0x00411F3D) refuses a bard song only at 115 or 120.

## Data flow

```
frame -> Render_World 0x00445A6C -> RealRender_World 0x00445243 -> DoPassageOfTime 0x00422198
      -> ready bytes, regen, timers; OP_TargetMouse / OP_AutoAttack / OP_SetRunMode to the server
attack key / auto-attack -> DoAttack 0x0048297B -> DoMissileHit_guess
skill button -> UseSkill 0x0041F4A0 -> DoAttack(100, ...) or a skill message
OP_Damage (0x5C78) -> 0x00452C54; OP_Action (0x497C) -> EQPlayer 0x0047F614; OP_Death (0x6160) -> 0x004A8CD5
OP_Stun (0x1E51) -> 0x00417839 `CostOwner_guess::StunMe_guess`; OP_HPUpdate (0x3BCF), OP_MobHealth (0x0695), OP_InitialMobHealth (0x3D2D) -> spawn HP
local damage record -> TakeDamage 0x0041C905 -> OP_Damage (0x5C78) / OP_EnvDamage (0x31B3)
```

## Key globals and structs

| Address / offset | What |
|---|---|
| 0x00905D00 | `pCharData` (EQ_PC); the tick runs on its +0xC280 part |
| 0x00905CE4 / 0x00905CF8 / 0x00905D04 | our spawn / the controlled spawn / the target |
| 0x009858C7 / 0x009858C8 | auto-attack / auto-fire |
| 0x00924670 / 0x00924671 / 0x00924672 | primary / secondary / skill-attack ready (set from actor +0x114 / +0x118; UseSkill clears it) |
| 0x0092447C / 0x0092460C / 0x00851200 | skill last-use times / skill ready bytes / skill table (reuse time) |
| 0x00923CC4 / 0x00923CD4 | active skill (0x35 tracking, 29 hide) / tracked spawn |
| 0x00923994 | camp end time |
| 0x00923798 / 0x00923884 | offline flags: no OP_Damage, no death check, local cast completion |
| 0x00905CA4 | paused: no tick |
| character +0xFC | state: 1 stunned, 3 knocked out (KnockedOut / GetConscious), 4 nothing runs |
| actor +0x54 / +0x58 / +0x74 / +0x78 | last 1 s, 6 s, 18 s, 60 s step |
| actor +0x60 / +0xDC / +0x114 / +0x118 | primary and secondary swing times, skill attack time and delay |
| actor +0xD0, +0x9D, +0x158 | stun end, last attack kind, boat |

## Known client bugs

- [B03](../KNOWN_CLIENT_BUGS.md#character-rules-and-combat-tu_013_eq_character): 0x0041C905: for spin spell 0x12F, positive damage reaching the spin check always breaks the buff from level 40; other spin spells use different probabilities.
- [B05, B06](../KNOWN_CLIENT_BUGS.md#character-rules-and-combat-tu_013_eq_character): 0x00422198 the save counter is a
  byte tested against 300; `/pause` is matched on 4 characters and read at offset 7.
- [B04, B07, B01, B02](../KNOWN_CLIENT_BUGS.md#other-confirmed-behaviour): dropped damage-shield totals
  (0x0041C905), a dropped hasted ranged delay (0x00422198), the ignored SPA 229 total in the stun
  (0x00417839 `CostOwner_guess::StunMe_guess`), an identical ternary (0x00417F8E `GetClassRaceACBonus_guess`).
