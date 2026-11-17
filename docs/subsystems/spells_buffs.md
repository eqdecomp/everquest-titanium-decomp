# Spells and buffs

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 11 | [Long page](../spells.md)

The spell table is parsed from spells_us.txt at login. Casting is checked locally and sent as
OP_CastSpell; the server answers with begin-cast, action and buff messages. Landing, buff stacking and the
per-effect (SPA) totals are computed on the character's magic part (`EQ_Character`).

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_012_CharacterMagicSystem.cpp` | `CharacterMagicSystem_guess` (EQ_Character's magic part) | cast checks, landing, stacking, totals |
| `tu_011_SpellFocus.cpp` | `Searcher_guess` | focus limits |
| `tu_038_EQ_Spell.cpp` | `EQ_Spell_guess` | one spells_us.txt line |
| `tu_062_EverQuest.cpp` | `GlobalState_guess` (CEverQuest) | begin-cast handling |
| `tu_042_EQHandleMsg.cpp` | dispatcher cases | buff, mana and memorize messages |
| `tu_136_BuffWindow.cpp`, `tu_139_CastingWnd.cpp`, `tu_140_CastSpellWnd.cpp`, `tu_215_SpellBookWnd.cpp`, `tu_216_SpellGemWnd.cpp` | spell windows | |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x0044DBF0 | `EQ_Spell_guess::ParseFromText_guess(line)` | parses one `^`-separated line: id, the name strings, the floats, then the integer fields |
| 0x00411F3D | `CharacterMagicSystem_guess::CastSpell(gem, spell, item, ...)` | the cast gate, then OP_CastSpell (0x304B, 0x14 bytes) |
| 0x00414913 | `CharacterMagicSystem_guess::HitBySpell(packet, amount)` | a spell landing on this character: Divine Aura (SPA 40) blocks most spells; bard-song and level gates; instant effects and buffs by SPA |
| 0x00414071 | `CharacterMagicSystem_guess::FindBuffSlot_guess(spell, caster, &index, noRemove)` | buff stacking: same spell refresh, per-effect rules against every buff, then a free slot |
| 0x0041002F | `CharacterMagicSystem_guess::InitializeSpellAffects_guess` | rebuilds the per-SPA totals from the buffs |
| 0x0040F8C3 | `CharacterMagicSystem_guess::FinishSpellAffects_guess` | adds worn item effects |
| 0x004106A3 | `CharacterMagicSystem_guess::TotalSpellAffects_guess(spa, includeAlt, sub, includeItems)` | one SPA total, with the haste rules |
| 0x0040DB0B | `IsBardSong_guess(spell, class)` | "is a bard song": class 8, spell +0x1C4 clear, a bard level of 1-254 |
| 0x0040CC88 | `Searcher_guess::CheckFocusLimit_guess` | focus limit checks |
| 0x0049B39D | `GlobalState_guess::StartCasting_guess(packet)` | OP_BeginCast (0x3990, 8 bytes) |

`CastSpell` order (0x00411F3D): no spawn or actor data; busy; unknown spell; not able to transact (string
0x16BB for a combat ability, else 0x3098); stand state other than 100 for a spell without "cast in any
state" (+0x1FC): stands a sitting caster (110) when an option allows, else strings 300 / 0x3099, and 0x3050
when the caster has no control (0x66); Divine Aura (SPA 40 total > 0, string 0xAE); ... a bard song is
refused only while lying (115: feign death or knocked out) or dead (120), string 212 (0xD4); any other spell needs stand state
100, string 213 (0xD5). Unless the spell passes the 0x0044D0ED `KeepsInvisibility_guess` test, casting removes the invisibility-type buffs (SPA 12, 28, 29,
94, 314-316), sends OP_SpawnAppearance (0x7C32, type 3) when the spawn was invisible, and cancels sneak and
hide.

## Data flow

```
spells_us.txt -> 0x0044DBF0 per line -> spell table 0x00985CC8
gem / item / hot button -> CastSpell 0x00411F3D -> OP_CastSpell (0x304B)
OP_BeginCast (0x3990)      -> StartCasting_guess 0x0049B39D
OP_Action / OP_Damage    -> ... -> HitBySpell 0x00414913 -> FindBuffSlot_guess 0x00414071 -> buff slot
OP_Buff (0x6A53)           -> dispatcher: mode 3 writes slot [6] (0x14 bytes); mode 1 removes the matching buff; else overwrites it
OP_ManaChange (0x4839), OP_MemorizeSpell (0x308E) -> their handlers
buffs changed            -> InitializeSpellAffects 0x0041002F + FinishSpellAffects 0x0040F8C3 -> totals
```

## Key globals and structs

| Address / offset | What |
|---|---|
| 0x00985CC8 | spell table |
| spell +0x120 | first effect id (SPA); 0x91 marks a special landing path in `HitBySpell` |
| spell +0x17D / +0x180 | beneficial / target type |
| spell +0x1C4 | combat ability (not "bard song") |
| spell +0x1FC | cast in any stand state |
| buff record | 0x14 bytes, reached through 0x0040E7AC `GetBuff_guess(index)` |

## Known client bugs

- [B32](../KNOWN_CLIENT_BUGS.md#spells-tu_038_eq_spell): 0x0044DBF0 stores two columns at spell +0x244.
- [B33](../KNOWN_CLIENT_BUGS.md#other-confirmed-behaviour): focus SPA 141 in 0x0040CC88 `Searcher_guess::CheckFocusLimit_guess` ignores its base value.
- [B01, B02](../KNOWN_CLIENT_BUGS.md#other-confirmed-behaviour): dropped totals and an identical ternary in
  the magic code (0x00417839 `CostOwner_guess::StunMe_guess`, 0x00417F8E `GetClassRaceACBonus_guess`).
- Not bugs: [B77](../KNOWN_CLIENT_BUGS.md#not-bugs) (the spell book has 512 entries).
