# Spells

[Overview](ARCHITECTURE.md) section 11 | [Source guide](README.md)

Four parts: the spell table loaded from spells_<lang>.txt, the casting code on the character
(`tu_012_CharacterMagicSystem`), the spell messages in the dispatcher, and the spell windows.

```
spells_<lang>.txt --> spell table (0x00985CC8, tu_089_Story) --> EQ_Spell records (tu_038_EQ_Spell), ids 0-9999
                                   ^ lookup by id
CCastSpellWnd (gem click, tu_140_CastSpellWnd) -+
EQ_Character::UseSkill (tu_013_EQ_Character)    +--> CastSpell 0x00411F3D (tu_012_CharacterMagicSystem)
action queue (tu_172_InvSlotMgr)              |      |- checks, cast time (focus/AA adjustments)
CEverQuest command code            |      |- online:  send OP_CastSpell (0x304B)
                                   |      `- sending off: StartCasting_guess directly
server: OP_BeginCast (0x3990) ---> CEverQuest::StartCasting_guess 0x0049B39D (tu_062_EverQuest): casting bar, animation
server: OP_Buff (0x6A53)      ---> dispatcher inline: copy the buff record into the character
EQPlayer::IWasHit_guess       ---> HitBySpell 0x00414913: apply a landed spell
DoPassageOfTime_guess         ---> ProcessAffects_guess 0x00413AE4: per-tick buff effects
```

## The spell table (tu_089_Story, tu_038_EQ_Spell)
`CEverQuest::DoLogin_guess` (0x0049377D) builds it once, from spells_<lang>.txt (the language suffix comes
from the table at 0x00799830), and stores it at 0x00985CC8. The constructor (0x004C7481):
- fills all 10,000 entries with one placeholder record (an unknown-spell record with placeholder messages) and its
  checksum;
- reads the file line by line with `^` as the separator; the first field is the spell id; an id above 9999
  stops the load;
- fills an `EQ_Spell` per line and keeps a checksum of each record's first 0x204 bytes. The record parser is
  `EQ_Spell_guess::ParseFromText_guess` (0x0044DBF0): it reads one record, or writes the unknown-spell
  defaults when there is none, and returns `this`; the Mac client calls it the `EQ_Spell` constructor. It
  stores two different columns at +0x244, so the later one wins (an original bug, B32 in
  [KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md)).
  `SendSpellChecksum_guess` (0x0046DD41, tu_046_EQMisc) also reads spells_%s.txt; the checksums probably serve the
  server's file check (inferred from the name and the shared file).

`EQ_Spell` (tu_038_EQ_Spell; class `EQ_Spell_guess`, with a second view `EQ_SpellView_guess`): the parser
fills fixed fields (ints, floats and the eight message strings: cast-on-you, cast-on-other, fades, ...), then
twelve-entry arrays for the effect slots. The field layout follows the column order of spells_us.txt; most
fields are not named yet. Known: +0x14 cast time, +0x20 duration formula, +0x2C mana, +0x120 the effect ids
(SPA), +0x17D beneficial, +0x180 target type, +0x1C4 marks a combat ability (not a bard song: each +0x1C4
branch in `CastSpell` picks the skill wording, e.g. 5819 "too distracted to use a skill"), +0x1FC "cast in
any state". tu_038_EQ_Spell also loads the visual effect table: spells.eff, or SpellsNew.eff when
present (`GetEffFiles_guess` 0x0044D773), into 0x008513B8; `WriteSpellEffects_guess` (0x0044D074) writes it back.

## Casting (tu_012_CharacterMagicSystem)
The file is the original `CharacterMagicSystem.cpp` (its path is in an assert string). Its class in the
source is `CharacterMagicSystem_guess`; MQ2 places these methods on `EQ_Character1`, the Mac client on
`EQ_Character`.

| VA | name | what |
|---|---|---|
| 0x00411F3D | `CastSpell` | validates (strings 0x16BB = 5819, 0x3098 = 12440, 0x309A = 12442, ...), computes the cast time, sends or starts the cast |
| 0x0040D663 | `GetFocusCastingTimeModifier` | cast-time change from spell-haste focus effects (items, augments, AAs) |
| 0x0040E2D2 | `GetAACastingTimeModifier` | level-based cast-time cut: Ranger, Shadow Knight, Paladin and Beastlord above level 50, spells of 3 s or more
with +0x17D == 0, 3% per level over 50 up to 45%; no AA is checked |
| 0x0040F06D | `StopSpellCast_guess` | ends a cast; sends 0x4839 (OP_ManaChange, empty). (0x4672 is sent only by `HitBySpell`'s PreserveCorpse branch, SPA 72, with the corpse's spawn id.) |
| 0x00414913 | `HitBySpell` | a spell lands on the character; its only caller is `EQPlayer::IWasHit_guess` |
| 0x00413AE4 | `ProcessAffects_guess` | runs buff effects; called only by `DoPassageOfTime_guess` |
| 0x00414071 | `CharacterMagicSystem_guess::FindBuffSlot_guess` | chooses the buff slot by the stacking rules: an existing buff of the same spell, or a conflicting one, may be replaced; not only a free-slot search |
| 0x004106A3 | `TotalSpellAffects_guess` | returns the cached total for one effect type |
| 0x0041002F | `InitializeSpellAffects_guess` | rebuilds the per-SPA totals from the buffs |
| 0x0040F8C3 | `FinishSpellAffects_guess` | adds the worn items' effects to those totals |
| 0x0040E7AC | `GetBuff_guess` (Mac/MQ2: `GetEffect`) | the buff record for a slot |
| 0x00411161 | `RemovePCAffectex_guess` | removes a buff |

Not every SPA total is a sum: haste, movement speed, SPA 98/119, 168/182/197 and a few others keep one value
by fixed rules (0x0041002F; asm 0x004105F0-0x00410640).

Three tests many comments rely on: 0x0040DB0B (`IsBardSong_guess`) is "is a bard song" (class 8, not a
combat ability, a real level for bards); 0x0040E40B (`IsBuffLevelBlocked_guess`) is "too powerful for the target";
0x004BB226 (`IsAGroupMember_guess`) is "is in my group" (`HitBySpell` drops a spell with string 2242 "This
spell cannot be cast on group members.").

The spell book in the profile block (+0x730) has 512 entries in the client: the accessor 0x0041AA26 traps at
index 0x200. EQEmu's struct names 400 of them and leaves the rest unknown.
`CastSpell` in short, from the end of the function:
- Cast time: the spell's base time plus the focus adjustment (`GetFocusCastingTimeModifier` 0x0040D663) and
  the level/class adjustment (`GetAACastingTimeModifier` 0x0040E2D2), never below half the base time.
- With sending enabled (0x00923798 and 0x00923884 both 0), it sends OP_CastSpell (0x304B, 0x14 bytes: gem
  slot, spell id, item reference, a value looked up by spell id, target spawn id) and waits for the server's
  OP_BeginCast.
- With sending disabled it calls `StartCasting_guess` itself with the same `{spawn id, spell id, cast time}`
  record OP_BeginCast carries (8 bytes). This is the offline path: the same two flags gate the client-side
  cast completion in `DoPassageOfTime_guess` (asm 0x00423AB0 in 0x00422198).
- Gem slots 0-8 get a 10-second timer in the actor info; slot 9 has its own.
- Item clicks take the cast time from the item (0x005E0D70) instead.

## Spell messages (dispatcher, [network.md](network.md))
| opcode | handling |
|---|---|
| OP_BeginCast (0x3990) | copies 8 bytes, calls `StartCasting_guess` (0x0049B39D) |
| OP_CastSpell (0x304B) | sent by `CastSpell` |
| OP_InterruptCast (0x0B97), and 0x5663 (no EQEmu name) in the same case | both show spell text filtered by options 7-9 at 0x009248E0; builds a text from a string id plus arguments (0x0B97) or takes the text as sent (0x5663), then shows it for the spawn whose id leads the payload |
| OP_Buff (0x6A53) | inline: one path copies a 0x14-byte buff record into the slot `GetBuff_guess` (0x0040E7AC) returns |
| OP_MemorizeSpell (0x308E) | `Handle_OP_MemorizeSpell_guess` 0x00458ED8 |
| OP_LoadSpellSet (0x403E) | `Handle_OP_LoadSpellSet_guess` 0x004520A1 |
| OP_SpellEffect (0x22C5) | inline: passes spawn ids and effect values to the object returned by 0x004B6A36 (tu_074_ModDatIni) |
| (no EQEmu name) | `Handle_SpellBookUpdate_guess` 0x00459985 |

## Spell windows
| file | window | notes |
|---|---|---|
| tu_215_SpellBookWnd | `CSpellBookWnd` (class `SpellBookWnd_guess`, view `SpellBookWndView_guess`), ctor 0x00558521 | `MemorizeSet` 0x00557CD8, `SwapSpellBookSlots_guess` 0x0055828A; `StartMemorize_guess` 0x00556FA1 (MQ2 BeginMemorizeSpell*) and `StartScribe_guess` 0x0055721C (BeginScribeSpell*), on the view `SpellBookWndView_guess`; 0x00556F72 (AttachBookSpellToCursor*) is still `FUN_00556f72_guess` |
| tu_216_SpellGemWnd | `CSpellGemWnd_guess` | one gem button; the original `SpellGemWnd.cpp` |
| tu_140_CastSpellWnd | `CCastSpellWnd`*, ctor 0x004EC8B4 | the gem bar; 0x004ECB56 (`Callback_guess::Select_guess`, MQ2 `HandleSpellLeftClick`) calls `CastSpell` |
| tu_139_CastingWnd | `CCastingWnd`*, ctor 0x004EB411 | the casting bar |
| tu_136_BuffWindow | `CBuffWindow_guess`, ctor 0x004E955B | `SetBuffIcon_guess` 0x004E8BA8, `OnProcessFrame_guess` 0x004E950F (on the view `CBuffWindowView_guess`) |
| tu_193_PetInfoWnd | pet buffs | |

tu_139_CastingWnd's class is `CCastingWndView_guess` (base `CSidlScreenWndBase`); no map covers
tu_140_CastSpellWnd's `CastSpellWnd_guess` and its view `Callback_guess`. The `C...Wnd` names above are MQ2's
for those constructors. tu_136_BuffWindow's classes are
`CBuffWindow_guess` (family 0x004E955B) and the views `CBuffWindowView_guess`, `CBuffWindowDtorView_guess`.
