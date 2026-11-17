# Known client bugs

[Overview](ARCHITECTURE.md) section 17 | [Source guide](README.md)

Defects of the original `eqgame.exe` (Titanium, build "Oct 31 2005 10:33:37") that this tree keeps as they
are, because the goal is the original's behaviour and code. Each row's behaviour was checked in the original
binary; the binary cannot show string-table wording or whether a rule was intended. "Byte-identical" means
the rewritten function compiles to the same bytes as the original, so the source shows the original logic; "asm" gives the instruction address in the original where the defect is
visible.

Ids are the review ids (B = bug note; D and X = other review rows; P = a later possible-bug note, kept here
only when the function is byte-identical). There are 91 notes: confirmed defects by subsystem, then other
confirmed behaviour, rejected claims and unresolved claims. Four notes (B17, B65, B78, B79) depend on the
wording of eqstr_us.txt, which is not part of this tree; the code shows only which string id is chosen.
Function names are given with their VA; if a name has moved, the VA finds the function under its current source name.

Most of these need unusual input to show: a custom UI file without a control, a crafted local file, or a
malformed server message. The ones a player could meet in normal play are B05, B06, B08, B22, B24, B27,
B42, B46, B47, B48, B52, B61, B80, B82, D01, P01 and P02.

## Character rules and combat (tu_013_EQ_Character)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B03 | 0x0041C905 | `TakeDamage_guess` | spin-break chance of spin spell 0x12F: the level tests > 49, > 44 and > 39 give the same result, so from level 40 any damage breaks it (other SPA 64 buffs: 1 in 10; spell 0x26B: 1 in 20) | asm 0x0041CB57-0x0041CB96: all three branches set 1 |
| B05 | 0x00422198 | `DoPassageOfTime_guess` (Tick) | a byte counter (0x00924673) is tested against > 300, so the periodic call 0x004A1350 (`SavePC_guess`) under it never runs | asm 0x0042338C: `movzx` of a byte, `cmp eax,0x12C` |
| B06 | 0x00422198 | `DoPassageOfTime_guess` | social macros: `/pause` is matched on 4 characters but its number is read at offset 7, so "/pau" matches and short forms read past the text | asm 0x00423FA6: `_strnicmp(..., 4)`, then `atoi(line + 7)` |

## Spells (tu_038_EQ_Spell)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B32 | 0x0044DBF0 | `EQ_Spell_guess::ParseFromText_guess` | two different columns of spells_us.txt are stored at spell +0x244; the later one wins | asm 0x0044E00A and 0x0044E325 both store to `[esi+0x244]` |

## Spawns, animation and missiles (tu_039_EQAnimate, tu_047_EQMissile)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B14 | 0x00450C2F | `SetAnim_guess` | animation sink +0x10 is used without a null test in the 0x20/0x4A/0x4E branch (crash for an actor with only the second sink and BodyType 1) | asm 0x004512F1; the branch at 0x00451218 does test it |
| B28 | 0x004766AA | `TrackTarget_guess` (missile turn) | at 32 units or more, a pitch error >= 1 and < 16 is never corrected (closer targets snap to the pitch) | asm 0x00476A70: leaves when the error is below 16 |
| B29 | 0x004766AA | `TrackTarget_guess` (missile turn) | with flag 0x00923798 set, writes through the state pointer (+0x48) before its null test | asm 0x004766BE before the test at 0x004766D0 |
| B30 | 0x00476B12 | `MotionObject_guess::CreateActorWhenReady_guess` (missile update) | reads state +0x1008 before the state null test | asm 0x00476B24 before the test at 0x00476B33 |
| B31 | 0x004766AA | `TrackTarget_guess` (missile turn) | the 125 ms re-aim delay can never be chosen | asm 0x00476730-0x00476782: the >= 150 test is reached only when distance >= 200 |

## Character profile, items and coins (tu_079_PlayerProfile, tu_077_ItemMoveQueue, tu_027_Tribute, tu_165_GuildBankWnd)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B27 | 0x004BA0FB | `LoadProfile_guess` (profile load) | one position field is written twice and another never: the first value is lost and +0x3C keeps its old value | asm 0x004BA22A and 0x004BA24A both `fstp [eax+ebx+0x34]` |
| B42 | 0x004B6F1F | `PositionHistory_guess::BuildMessage_guess` (movement history, sent as 0x6A1B) | entries are stamped with `EqGetTime` and aged with `GetTickCount`; the two clocks have different origins, so the 2 s hold does not work as intended | stamp 0x004B6E0E stores `EqGetTime` (0x0046D655); age test 0x004B6F53 uses `GetTickCount` |
| B43 | 0x004B78F2 | swap of a moved item | the slot lookup 0x004B76A6 can return 0, and the result is dereferenced without a test | asm 0x004B7943 |
| B50 | 0x004347D3 | `OnItemDonated_guess` (tribute item reply) | the direct-slot branch accepts slot 31, on which the slot getter 0x0040CC50 hits `int3` (only a bad reply can carry it) | asm 0x00434840: `cmp esi,0x1F; jg` |
| B61 | 0x0050DD43 | guild bank split | the split request (OP_GuildBank, 0xB4AB) is sent only when count > amount + 1, so a stack of 2 can never be split | asm 0x0050E1D6 |

## Commands and input (tu_044_ExecuteCmd)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B46 | 0x004619CD | `ExecuteCmd`, cycle reply | the reply word is passed as the sprintf format, so for a plain name the input line becomes only the reply word | asm 0x00462133: argument order `buf, replyWord, "/%s %s", name`; the ';'/'[' branch at 0x0046214E is right |
| B47 | 0x004619CD | `ExecuteCmd`, clipboard paste (0xE7) | missing break: after a paste it runs the 0xD6 window toggle (PvP statistics, global 0x00991EB0) | asm 0x004642C1: `CloseClipboard`, then straight into the 0xD6 case body |
| B48 | 0x004619CD | `ExecuteCmd`, paste filter | signed char compare: pasted bytes 0x80-0xFF become spaces | asm 0x0046424C: `cmp al,0x20; jl` and `cmp eax,0xFF` after `movsx` |

## Server data used without checks

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| X01 | 0x0045B8F0 | dispatcher, case 0x4BB4 | a batch position update whose header count is larger than the packet is read past its end | asm 0x00460CB9-0x00460CE1: the count is raised to what fits, never lowered |
| B73 | 0x00554E7A | `CSkillsWndTitlesView_guess::Run_guess` (the OP_CustomTitles handler, tu_213_SocialEditWnd) | server text is used as the sprintf format, into a 0x400-byte buffer | byte-identical: `sprintf(buf, text)` |
| B74 | 0x00565CD2 | `TitleTable_guess::Handle_OP_SendTitleList_guess` (title table, OP_SendTitleList) | `sprintf("%s")` of server strings into 32-byte fields, no length limit | byte-identical; the entry has `char first[32], second[32]` |

## Options, ini and local files

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| D01 | 0x004AF32C | `loadOptions_guess` | the seven Camera2-* ini keys are loaded into the Camera1 globals; camera 2 is never loaded | asm 0x004AF833-0x004AF8ED: stores to 0x00924A78-0x00924A90 |
| B08 | 0x0053D0F5 | `BagOptions_guess::WriteBagFadeSetting_guess` (bag fade options) | the section names get the constants 4, 5, 6 instead of slot + 1, so only [BagWorld4], [BagViewPC5] and [BagViewPCBank6] are written (8 times each) | byte-identical |
| B85 | 0x004B010A | `SaveHotbuttonLoadouts_guess` | scans 100 entries of a 10-entry table (0x00984A84), writing those whose active byte is 1; stray HBSetN keys are possible | byte-identical; the loader fills 10 and tu_062_EverQuest sorts it as `qsort(0x00984A84, 10, 0x20)` |
| B66 | 0x004C4143 | RecommendedDrivers parse | `fscanf("%x %s")` into a 512-byte buffer with no width | byte-identical |
| B68 | 0x004E5610 | `CBazaarWndView_guess::BuildIniPath_guess` (builds the bazaar ini name) | `.\BZR_<name>_<server>.ini` is built into a 64-byte field with no length check | byte-identical |
| B38 | 0x004C66D9 | `FileScanner_guess::Process_guess` (MP3 playlist scan) | no capacity check on the track table; a playlist that includes itself recurses forever; a 1024-byte line tail is copied into 512 bytes | byte-identical |
| B86 | 0x0044A8DF | mp3index.txt load | no bound on the line count; the table holds 100 names | byte-identical; table 0xC80 / 0x20 = 100 entries |

## Text and chat (tu_023_SystemCommands, tu_051_bad_word_class)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B09 | 0x0042DE64 | chat-text line splitter (prints through `pEverQuest` 0x00498436) | on a long line it stores 256 characters, then drops the next one (characters 257, 514, ... are lost) | byte-identical: the length >= 256 branch flushes without storing the character |
| B34 | 0x00478F73 | `GarbleText_guess` | the random letter is 0x60 + 0..25, so it can be a backtick and is never 'z' | asm 0x0047905E: `push 0x19; push 0; call 0x0040CBB2; add al,0x60` |

## Purchase prompts (tu_001_Sync, tu_064_Sync, tu_085_RecommendedDrivers)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B78 | 0x00401527 | `GetAdventurePurchaseConfirmId_guess` | multi-item branch selects 5931 when the second argument is 1, otherwise 5932; a wording defect is unverified without the matching eqstr_us.txt | source and binary prove ID selection; matching external string text not supplied |
| B79 | 0x004B12CE | `GetEbonPurchaseConfirmId_guess` | multi-item branch selects 5959 when the second argument is 1, otherwise 5960; a wording defect is unverified without the matching eqstr_us.txt | source and binary prove ID selection; matching external string text not supplied |
| B65 | 0x004C3A3B | `GetPvpPurchasePromptId_guess` (PvP purchase prompt) | multi-item branch selects 5947 when the second argument is 1, otherwise 5948; a wording defect is unverified without the matching eqstr_us.txt | source and binary prove ID selection; matching external string text not supplied |

## Sound and music (tu_037_EQ_SoundManager, tu_087_SoundManager, tu_178_LargeDialogWnd)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B36 | 0x004C5B16 | sound play | with a null parameter block it still reads params +0x28 | asm 0x004C5B71 `je 0x004C5BF2`, which is `push [esi+0x28]` |
| B81 | 0x00526574 | MP3 window volume slider | the label shows the value + 1 | asm 0x005266A1 `inc eax` before the format |
| P01 | 0x0044B741 | `EqSoundManagerView_guess::PlayMp3_guess` | the current MP3 is stopped and its pointer cleared before the null test, so a call with the track already playing restarts it (looked up again by name; `GetAsset_guess` 0x0044B33B tries the device cache first) | byte-identical: the stop and `target = 0` come before `if (target == 0)` |

## Character creation (tu_141_CharacterCreation)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B10 | 0x004EEB1D | start-city buttons | with no valid start city the index stays -1 and `cityButtons[-1]` (really `deityButtons[16]`) is used | asm 0x004EEE8D: no range test |
| B11 | 0x004EF129 | creation mode 6 | race buttons 9 and 12 are disabled without a null test | byte-identical |
| B13 | 0x004ED32E | screen help | when `ShowCreationHelp` is missing from the ini it only writes TRUE and does not show the help; it shows from the next visit | asm 0x004ED61E jumps past the Show call |

## Guilds (tu_010_guilds, tu_166_GuildManagementWnd)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B16 | 0x0040A79B | `RecordTable_guess::FindGuildIdByNamePrefix_guess` (guild lookup by name) | matches on a prefix: the first guild whose name starts with the text wins; an empty text matches the first record with a non-empty name | byte-identical: `_strnicmp(record, text, strlen(text))`, empty records skipped |
| B17 | 0x0040AE42 | `SendGuildBankerFlags_guess` (banker toggle) | below leader rank it shows string ID 516 and sends nothing; the claimed wording mismatch needs the matching eqstr_us.txt and remains unverified | source and asm 0x0040AE72 prove string ID 516 and the rank guard |
| B44 | 0x0050F485 | `FindPersonalNote_guess` (guild personal notes) | a note is found by name hash only; two names with the same hash share a note | byte-identical: no name compare |
| B45 | 0x0050E2D2 | `UpdateButtons_guess` (guild management window) | the Promote button (+0x184) is never enabled or disabled | the function never touches +0x184 |

## Journal (tu_024_Journal)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B55 | 0x0042E7D7 | `GetOrAddNpc_guess` (journal NPC record) | `strncpy(name, 0x3F)` into a record whose byte 0x3F is never cleared: a 63+ character name is not reliably terminated | asm 0x0042E807; init 0x0042E43A clears only byte 0 and +0x40..+0x50 |
| B56 | 0x0042E871 | `RemoveCategory_guess` (removing a category) | the category record is removed without being freed; the delete-selection path in CJournalCatWnd also does not free it | no free/delete call in 0x0042E8A4-0x0042E8EC |
| B57 | 0x0042ED03 | journal text | text is keyed by a 32-bit hash only; a different line with the same hash reuses the stored text | byte-identical |

## Windows (tu_099 to tu_234)

| Id | VA | Where | Effect | Evidence |
|---|---|---|---|---|
| B15 | 0x00548B9D | potion belt constructor | leaks the new animation when a PotionSlot button is missing | byte-identical |
| B22 | 0x004D3C53 | `CombatPageOnProcessFrame_guess` (actions window) | for skill ids 114/115 on the Combat page it clears the check on the Abilities-page button two slots on, not on this button | asm 0x004D3D0E: `mov ecx,[edi-0x20]` |
| B23 | 0x004D400B | `CActionsWnd_guess::SocialsPageOnProcessFrame_guess` (actions window, socials page refresh) | uses the social-edit window (0x00850C6C) without a null test | byte-identical |
| B24 | 0x004E09DF | `CBarterWnd` constructor | tests WelcomeEdit (+0x1B0) but sets the 256-character limit on the search box (+0x170); WelcomeEdit keeps its default | asm 0x004E1360 |
| B25 | 0x00558A3A | spell gem draw | hover colour is tint + 0x202020 with no clamp; a channel above 0xDF overflows | asm 0x00558AC4: `lea edx,[eax+0x202020]` |
| B52 | 0x0054B657 | PvP leaderboard | under the points and infamy sorts the tie test compares kills with the stored value, so ties almost never share a rank | asm 0x0054BD37 vs the store at 0x0054BD4C |
| B53 | 0x0054B657 | PvP leaderboard | rows are addressed by entry index, not by the row `AddString` returns (matters only if the server leaves gaps) | asm 0x0054BE56 pushes the loop index |
| B54 | 0x0054B657 | PvP leaderboard | the your-rank label is used without a null test | asm 0x0054BEDE |
| B58 | 0x004DA15B | link control | without a ClickAction key an uninitialised local is stored at +0x180 | 0x005DDA20 returns 1 without writing its output when the key is absent (0x005DDA2D) |
| B59 | 0x00506257 | gems game | the score is compared unsigned with the high-score table; a negative score ranks above a non-negative score, and score subtraction is reachable | asm 0x00506271: `cmp ecx,[eax]; ja` |
| B62 | 0x0055E645 | task window timer | the row turns red on the task's total duration (below 120), not on the time left | byte-identical |
| B63 | 0x0055F412 | `CompareTimeLeft_guess` (task sort) | for different times the qsort comparator returns 1 both ways, never a negative value (equal times go to the title compare) | byte-identical: `return (unsigned)(a - b) > 0`; equal times call `CompareTitle_guess` 0x0055F3E8 |
| B64 | 0x0052DFBB | `SyncWithAddressBook_guess` (mail recipient check) | leaks the entry on the paths that show no dialog | asm 0x0052E21D; one `new` at 0x0052E144, no delete on those paths |
| B67 | 0x004E5907 | bazaar window buttons | BZW_List_Button (+0x180) is outside the null guard | byte-identical |
| B69 | 0x004E7BC7 | body tint window | `buttons[slot]` is dereferenced before its null test | byte-identical |
| B70 | 0x00552387 | selector window | the hotbox (0x00991AE4) and short-buff (0x00850C1C) windows are used without a null test | asm 0x0055248B, 0x005524C9 |
| B71 | 0x00544157 | petition list | `GetItemData(GetCurSel())` without a -1 test: with no selection, -1 * 0xB8 addresses the record before the petition table, which is then copied | asm 0x005442CA, 0x005442DB |
| B72 | 0x00566CE6 | tracking window sort | in ascending distance mode (1) an empty entry (distance -1) is never moved; descending mode (3) does move it | asm 0x00566DA6-0x00566DBE |
| B76 | 0x00554C2D | skills window | a successful in-place row refresh increments rowCount_0164_guess without adding a list row (the effect depends on how callers reset it) | byte-identical: `++rowCount_0164_guess` |
| B80 | 0x004D7EEF | alarm window | the minutes branch sets the character limit on the hours box again (and crashes if only the minutes box exists) | byte-identical |
| B82 | 0x00508955 | `CGroupSearchFiltersWnd_guess::IsFilteredOut_guess` (group search filters) | each checked filter overwrites the result; the last one wins (an ignored player who is also a friend passes when both filters are on) | byte-identical: four independent assignments |
| P02 | 0x0050B94D | group search window, `CGroupSearchWndView_guess::HandleGroupInfoPage_guess` (tu_163_GroupSearchWnd) | of the 16 class checkboxes (GIP_<class>Checkbox), the Berserker box (index 2, class id 16) is omitted from the click test, so toggling only that box does not mark the group information as edited | byte-identical: the test lists indexes 0, 1 and 3-15 |

## Other confirmed behaviour

Present in the binary, but either redundant or of unclear intent: some rows change output or reject an
operation, and whether that was intended is not known.

| Id | VA | What | Evidence |
|---|---|---|---|
| B01 | 0x00417839 `CostOwner_guess::StunMe_guess` (stun) | the SPA 229 total is computed and ignored | byte-identical |
| B02 | 0x00417F8E `GetClassRaceACBonus_guess` | both arms of `level < 30 ? level + 5 : level + 5` are the same | asm 0x0041816B, again at 0x0041822F |
| B04 | 0x0041C905 | the damage-shield (SPA 59) and reverse damage-shield (SPA 121) totals are computed and dropped | asm 0x0041CCD4-0x0041CD18, 0x0041CDAB-0x0041CDC7 |
| B07 | 0x00422198 | a hasted ranged delay is computed and dropped; the test below hastes the actor's delay (+0x118) again and uses that | asm 0x00422B84, second call 0x00422B9A |
| B12 | 0x004ED85C `LanguageOwner_guess::SetStartCity_guess` (sets the start city) | the start-city description is copied into a local buffer that is never used | byte-identical |
| B21 | 0x005163A9 | results of `new` are used without a null check (the ordinary compiler shape, as everywhere in the client) | asm 0x0051658A-0x0051660F |
| B33 | 0x0040CC88 `Searcher_guess::CheckFocusLimit_guess` (focus limits) | focus limit SPA 141 ignores its base value and rejects a spell with a non-zero duration formula (+0x20); whether this rule is unintended is unproven | asm 0x0040CE30 |
| B39 | 0x004C72C1 | the track list `Clear` leaves first/last pointing at freed nodes; its only caller is the sound manager's destructor | byte-identical; caller 0x0044C793 |
| B41 | 0x00570FCA `UpdateChase_guess` | in game state 5, camera distance is capped at 200 with no lower clamp here; the distance is used to compute camera position | asm 0x0057109D-0x005710B2 |
| B49 | 0x00433EAC | the per-bag-slot send loop for tribute items cannot run: a non-empty bag is refused before it (string 0xD38) | byte-identical |
| B75 | 0x004DD386 `Dispatcher_guess::WndNotification_guess` (bank window button handler) | OP_BankerChange (0x6A5B) is sent with the clicked button's pointer as its 4-byte payload; nothing in the client shows an effect | asm 0x004DD422: `lea eax,[ebp+8]; push 4; push 0x6A5B` |
| B60 | 0x005065D2 | gems game: two occupied random column picks end the game and check the high score, even if other columns are free | byte-identical |
| B83 | 0x0040944C | barter sales are shown in chat but not written to Logs\btrlog_ (purchases are, through 0x004096EF); whether the asymmetry is intended is unproven | call graph |
| B84 | 0x004B102D | the old hot-button conversion covers the first 100 buttons only; its effect on older hot-button layouts is unverified | asm 0x004B11B5 |
| P03 | 0x0043AF46 `CleanGameUI` | the Radiant crystal and Ebon crystal currency objects (0x0098593C, 0x00985904) are tested for 0 and then set to 0 (they are created in `InitGameUI_guess` 0x0043EFDD and never freed here) | byte-identical |

## Not bugs

Claims made from rewritten source that the binary does not support. The source was corrected or the
comment reworded.

| Id | VA | Claim | Finding |
|---|---|---|---|
| B18 | 0x0040C6B7 | chat-channel parse type 7: `size - (int)tail` points nowhere | it is the byte count left after the two strings (asm 0x0040C91F); odd types in the source only |
| B20 | 0x004FAE39 | the distiller match compares the wrong values | 0x005E10B0 returns item +0x2A0, the augment's distiller item id, also sent in OP_AugmentInfo by 0x00521827; the match is right |
| B26 | 0x005254BB | journal DeleteText calls `ClearAllSel` without a null test | in the binary the call is inside the test (asm 0x005257A4 jumps past it); the source had a brace one level out |
| B35 | 0x004788E1 | the profanity test passes the rest of the line | the only caller passes a separate copy of one word; it is a case-insensitive substring match inside that word |
| B37 | 0x004C6B3A | audio init creates the 3D sample pool even when no Miles 3D provider was found | the pool call `AddInstances_guess(1, ...)` 0x004C6203 tests the provider (+0x18) at 0x004C621B and returns at 0x004C62D1; the rewrite has the same test (`provider_guess != 0`) |
| B40 | 0x00478F73 | GarbleText compares the input letter with 98 | `cmp al,0x62` at 0x00479025 tests the second random roll, not the letter; the rewrite compares the roll (`chance_guess > 98`) |
| B51 | 0x004356CC | the dbstr load's extra end-of-file pass reuses the previous id and type | 0x004B2056 always writes its outputs; the extra pass inserts an empty string for id 0, type 0 |
| B77 | 0x00557A73 `SaveSpellbookFile_guess` | the spell book dump loops over 512 slots while the book has 400 | the client's book array has 512 entries (accessor 0x0041AA26 traps at 0x200); 400 is only the part EQEmu names |

## Unresolved

| Id | VA | Claim | Status |
|---|---|---|---|
| B19 | 0x004FAD2F | `~CContainerWnd` (the source's `Initializer_guess::Destruct_guess` in tu_149_ContainerWnd) never frees the A_DragItem animation copy at +0x1A0 | the destructor does not free it, but the pointer is also held by the Container_Icon button, whose destructor is in the UI library and was not checked |
