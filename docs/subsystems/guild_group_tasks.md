# Guild, group, raid, tasks, tribute and adventures

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) sections 6 and 9 | [Long page](../network.md)

Each social system is a small manager object at a fixed address. The dispatcher (0x0045B8F0) forwards a
family of opcodes to the manager's own switch, or calls one handler per opcode. Requests go out with
`EQSendMessage` (0x004912B1) from the slash commands and windows. Which switch a family sits in matters:
the second switch runs only once CDisplay reports the world loaded (0x0043745D).

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_010_guilds.cpp` | `GuildManagement_guess` (0x00905D38), `ListOwner_guess`, `RecordTable_guess`, `RequestOwner_guess` | guild names, members, MOTD, rank requests |
| `tu_025_Raid.cpp` | `CRaid_guess` (0x0091D708) | raid roster, loot rules, raid commands |
| `tu_026_TaskManager.cpp` | `TaskManager_guess`, `TaskManagerView_guess` (0x0079DC78) | task slots, history, shared-task members |
| `tu_027_Tribute.cpp` | `TributeTable_guess`, `MessageRouter_guess` (0x00850350) | personal and guild tribute |
| `tu_008_AdventureManager.cpp` | `AdventureManager_guess` (0x009232F0) | LDoN adventure request, timers, finish |
| `tu_031_Expedition.cpp` | `Expedition_guess` (0x009231C8), `MessageState_guess` | expedition info, members, lockouts, compass |
| `tu_062_EverQuest.cpp` | `GlobalState_guess`, `EverQuestActionView_guess` | group invite / follow / disband, guild commands |
| `tu_042_EQHandleMsg.cpp` | dispatcher cases | group update, guild invite, war and peace |
| `tu_080_EQ_PC.cpp` | `EQ_PCView_guess` | "in my group" tests |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x0040B8CB | `GuildManagement_guess::HandleMessage_guess(conn, opcode, data, size)` | guild switch: names table, member add / delete / rename / level / note, member list, rename and delete guild; after a member change rebuilds the "Guild" name list in the chat manager under `pEverQuest` |
| 0x0040AF04 | `ListOwner_guess::LoadGuildMemberList_guess(stream)` | OP_GuildMemberList: big-endian count, then per member a variable-length entry (name, nine big-endian ints, note, one int) decoded into a 0x274-byte record |
| 0x0040A7FD | `ListOwner_guess::UpdateFromRequest_guess(request)` | OP_GuildMOTD (0x475A): shows string 0x1D4 when the text changed; keeps the MOTD (+0x1774C) and its author (+0x1794C) |
| 0x00455134 | `Handle_OP_GuildInvite_guess(.., .., packet)` | OP_GuildInvite (0x18B7) for this player: answers OP_GuildInviteAccept (0x61D0) at once or asks in a 10 s yes/no box |
| 0x00453B3F / 0x00453C24 | `Handle_OP_GuildWar_guess` / `Handle_OP_GuildPeace_guess` | to a guild leader (rank 2): a yes/no box (types 0x68 / 0x69, 10 s) holding a copy of the packet |
| 0x00453ABB | `Handle_GuildWarFailed_guess` | opcode 0x186D: war refused (-2) or not possible (-5) |
| 0x0049BF15 | `EverQuestActionView_guess::GuildInvite_guess(name, action)` | /guildinvite: needs a guild (+0xE0C) and officer rank (+0xE10); OP_GuildInvite (0x18B7), 0x88 bytes |
| 0x0049C20E | `GlobalState_guess::GuildRemove_guess(name)` | /guildremove: leave (not the leader) or remove a member, OP_GuildRemove (0x0179) |
| 0x0040ACBF / 0x0040AD67 / 0x0040AE42 | `SendGuildPublicNote_guess` / `SendGuildDemote_guess` / `SendGuildBankerFlags_guess` | OP_GuildPublicNote (0x17A2), OP_GuildDemote (0x4EB9), OP_GuildManageBanker (0x3D1E) |
| 0x00458738 | `Handle_OP_GroupUpdate_guess(packet)` | OP_GroupUpdate (0x2DD6): action 0 joined, 1 left, 3 renamed, 5 removed, 6 disbanded, 7 you joined, 8 new leader, 9 formed; ignored while an offline flag is set |
| 0x0049D654 | `GlobalState_guess::HandleGroupInvite_guess(opcode, packet)` | OP_GroupInvite (0x1B48) / OP_GroupInvite2 (0x12D6): shows the invite, or declines with OP_GroupCancelInvite (0x1F27, 1 a box open, 2 grouped, 4 raid invite pending, 5 in a raid) |
| 0x0049D300 | `GlobalState_guess::doUnInvite_guess(packet)` | OP_GroupCancelInvite (0x1F27): prints the reason |
| 0x0049D3CC / 0x0049D7B6 / 0x0049D8BD | `Invite_guess` / `AcceptGroupInvite_guess` / `Disband_guess` | /invite (leader only), /follow (OP_GroupFollow 0x7BC7, or 0x42C9 after OP_GroupInvite2), /disband (OP_GroupDisband (0x0E76); refused in a locked raid) |
| 0x004BB226 | `EQ_PCView_guess::IsAGroupMember_guess(name)` | our own name or one of the 0x40-byte member names |
| 0x00431CF2 | `CRaid_guess::HandleS2CRaidMessage_guess(message)` | OP_RaidJoin / OP_RaidUpdate (0x1F21) by command id: 0 add, 1 delete, 2 rename, 3 group, 5 / 10 disband, 8 and 30 leader, 11 / 32-34 loot, 17 / 18 lock, 35 MOTD, 36 member note |
| 0x0043060E | `CRaid_guess::SendRaidCommand_guess(id, name, text, options)` | OP_RaidInvite (0x5891), 0x88 bytes |
| 0x00430CE5 | `CRaid_guess::InviteToRaid_guess(name)` | raid invite with its refusals (pending, not leader, full, self, NPC, already in) |
| 0x00433887 | `TaskManagerView_guess::HandleTaskMessage_guess(opcode, data, size)` | task switch (below) |
| 0x0043320E | `TaskManager_guess::TaskManager_guess` | constructor: 21 task slots, 50 history entries |
| 0x00434D9A | `TributeTable_guess::HandleTributeMessage_guess(opcode, data)` | personal tribute: master opened, 5 active slots (OP_TributeUpdate, 0x5639), timer, points, item and money replies |
| 0x00435163 | `MessageRouter_guess::HandleGuildTributeMessage_guess(opcode, data)` | guild tribute: 2 active slots, opt in / out, donations |
| 0x004347D3 / 0x00434567 | `MessageRouter_guess::OnItemDonated_guess` / `OnPlatinumDonated_guess` | donation replies (tribute and guild tribute) |
| 0x00434111 | `CooldownState_guess::TickTributeTimers_guess` | advanced every second by the character tick |
| 0x004089B2 | `AdventureManager_guess::OnEvent_guess(conn, opcode, data, size)` | adventure switch (below) |
| 0x004082DF | `AdventureManager_guess::Tick_guess()` | called by DoMainLoop each frame when the character has flag 0x20: while the request window is active in modes 1-2, every 500 ms closes it when the NPC is gone or the player is more than 30 units away; modes 3-4 count down by the second |
| 0x00408672 / 0x00408616 / 0x00408644 / 0x004087D6 | `RequestAdventureInfo_guess` / `AcceptAdventure_guess` / `DeclineAdventure_guess` / `SendLeaveAdventure_guess` | OP_AdventureInfoRequest (0x2AAF, NPC id), OP_LDoNButton (0x13C8, 1 / 0), OP_LeaveAdventure (0x0C0D) |
| 0x00447364 | `Expedition_guess::Dispatch_guess(conn, opcode, data, size)` | expedition switch (below) |
| 0x00446421 / 0x00446494 | `MessageState_guess::Send_guess` / `SetFrom_guess` | expedition invite box (string 0xDC7) and its answer OP_DzExpeditionInviteResponse (0x5DA9, 0x4C bytes) |

### Where the dispatcher sends each family (0x0045B8F0)

| Family | Switch 1 (always) | Switch 2 (world loaded) |
|---|---|---|
| guild | OP_GuildInvite (0x18B7), OP_GuildWar (0x0C81), OP_GuildPeace (0x215A), 0x186D, OP_LFGuild (0x1858, window 0x00991C40), OP_GuildBank (0xB4AB, window 0x00991A90) | 0x0040B8CB for 0x0F4D, OP_GuildMemberList (0x147D), 0x2EC9, OP_GuildDeleteGuild (0x3230), 0x32CF, OP_GuildMemberLevel (0x461A), OP_GuildRenameGuild (0x4CC7), OP_GuildsList (0x6957), 0x6966, OP_GuildMemberDelete (0x712A), OP_GuildMemberAdd (0x754E), OP_GuildMemberRename (0x7C59); OP_GuildMOTD (0x475A); OP_GetGuildMOTDReply (0x3246) |
| group | OP_GroupUpdate (0x2DD6), OP_AssistGroup (0x5104) | OP_GroupInvite (0x1B48), OP_GroupInvite2 (0x12D6), OP_GroupCancelInvite (0x1F27) |
| raid | OP_RaidJoin / OP_RaidUpdate (0x1F21) | |
| leadership | 17 opcodes (OP_MarkNPC, OP_SetGroupTarget, OP_RaidDelegateAbility, ...) to 0x009859EC method 0x004B5145 `LeadershipManager_guess::HandleLeadershipMessage_guess`, only with bit 0x40 of the character flags (EQ_PC +0xC280, +0x108) | |
| tasks | 0x00433887 `TaskManagerView_guess::HandleTaskMessage_guess` for OP_TaskHistoryReply (0x397D), OP_CancelTask (0x3BA8), OP_TaskActivityComplete (0x54EB), OP_TaskSelectWindow (0x5E7C), OP_TaskDescription (0x5EF7), OP_TaskActivity (0x682D), 0x6A1D, OP_CompletedTasks (0x76A2); OP_SharedTaskAddPlayer (0x6934, yes/no box) | 0x00433887 `TaskManagerView_guess::HandleTaskMessage_guess` for 0x16F0, 0x24F0, 0x2568, 0x4562, 0x46AA, 0x5886, 0x64D7, 0x67C6, 0x6C97, 0x7135, OP_SharedTaskMemberList (0x722F), 0x729C, 0x79B4; OP_SharedTaskSelectWindow (0x013F, window 0x00992820) |
| tribute | 0x00434D9A `HandleTributeMessage_guess` for OP_SendTributes (0x067A), OP_TributeInfo (0x152D), 0x27B3, OP_TributeTimer (0x4665), OP_OpenTributeMaster (0x512E), OP_TributeUpdate (0x5639), OP_SelectTribute (0x625D), OP_TributePointUpdate (0x6463), OP_TributeItem (0x6F6C) | |
| guild tribute | 0x00435163 `MessageRouter_guess::HandleGuildTributeMessage_guess` for OP_GuildOptInOut (0x0CFC), OP_GuildSendActiveTributes (0x1A29), OP_GuildTributeDonateItem (0x32C0), OP_GuildTributeToggleReply (0x3312), OP_GuildTributeDonatePlat (0x44C4), OP_GuildModifyBenefits (0x4EEF), 0x5E3D, OP_OpenGuildTributeMaster (0x60B6), OP_GuildTributeFavorAndTimer (0x67EA), OP_GuildSelectTribute (0x704F) | |
| adventure | | 0x004089B2 for OP_AdventureData (0x0677), OP_AdventureLeaderboardReply (0x0D0F), 0x0FF1, 0x16C6, OP_AdventureInfo (0x1DB5), OP_AdventureFinish (0x3906), OP_AdventureDetails (0x3F26), OP_AdventurePointsUpdate (0x420A), 0x475E, 0x49A5, OP_AdventureStatsReply (0x56CD), OP_AdventureUpdate (0x64AC), only with bit 0x20 of the same flags (0x20 is LDoN in the expansion mask, 0x0045386D); OP_AdventureMerchantSell (0x0097) |
| expedition | | 0x00447364 for OP_DzExpeditionInfo (0x098E), OP_DzMemberList (0x09B6), OP_DzChooseZone (0x1022), OP_DzMemberListName (0x1826), OP_DzExpeditionEndsWarning (0x1C3F), OP_DzCompass (0x28AA), OP_DzMemberListStatus (0x330D), OP_DzExpeditionInvite (0x3817), OP_DzSetLeaderName (0x7ABC), OP_DzExpeditionLockoutTimers (0x7C12) |

Bare values have no unique EQEmu name and stay numbers in the code.

### The manager switches

- Guild (0x0040B8CB): OP_GuildsList (0x6957) must be 0x17740 bytes and fills 1500 names of 0x40 bytes at
  +0x4C; any other size sends OP_CrashDump (0x7825) with a size-mismatch text. OP_GuildRenameGuild (0x4CC7)
  and 0x2EC9 rename one entry below 1500. OP_GuildMemberUpdate (0x0F4D) updates one member record and its online flag.
- Tasks (0x00433887 `TaskManagerView_guess::HandleTaskMessage_guess`): OP_TaskActivity (0x682D) to 0x00432FD2, OP_TaskHistoryReply (0x397D) to 0x00432379,
  OP_TaskActivityComplete (0x54EB) a centre-screen line (0x1773-0x1775), OP_TaskSelectWindow (0x5E7C) to the
  task select window, OP_TaskTimers (0x6A1D) sets pCharData +0xE50 to now + seconds, 0x6C97 a shared-task
  status line (strings 0xE19-0xE25), OP_AnnoyingZoneUnknown (0x729C) template text.
- Adventures (0x004089B2): mode at +4 is 0 idle, 1 info shown (OP_AdventureInfo, 0x1DB5), 2 details
  (OP_AdventureDetails, 0x3F26), 3 / 4 countdowns (OP_AdventureData 0x0677, 0x49A5), 5 a server string
  (0x0FF1). OP_AdventureFinish (0x3906) prints the result (strings 0x2154 / 0x1410 with the points, large
  text 0x2152 or 0x2153, sound 0x8D or 0x8C) and returns to mode 0. OP_AdventurePointsUpdate (0x420A) writes
  five totals and 0x78 bytes into pCharData +0x102C .. +0x10C0. OP_AdventureLeaderboardReply (0x0D0F) and
  OP_AdventureStatsReply (0x56CD) go to their windows (0x004D5D1D, 0x004D743F).
- Expeditions (0x00447364): OP_DzExpeditionInfo (0x098E, leader, name, max players; members cleared when it
  ends), OP_DzSetLeaderName (0x7ABC), OP_DzExpeditionEndsWarning (0x1C3F, string 0xDDF, minutes left),
  OP_DzChooseZone (0x1022, choose-zone window), OP_DzCompass (0x28AA, markers, string 0xDFE), member list,
  names, status and lockout timers.

## Data flow

```
slash command / window -> 0x0049BF15, 0x0049D3CC, 0x0043060E, 0x00408672 `RequestAdventureInfo_guess` ... -> EQSendMessage 0x004912B1
server -> 0x0045B8F0 switch 1: group update, raid, guild invite / war / peace, tasks, tribute
                     switch 2: guild 0x0040B8CB, group invites, tasks, adventures 0x004089B2, expeditions 0x00447364
DoMainLoop each frame (flag 0x20) -> AdventureManager Tick 0x004082DF
character tick each second -> tribute timers 0x00434111 `TickTributeTimers_guess`
```

## Key globals and structs

| Address / offset | What |
|---|---|
| 0x00905D38 | guild manager: names at +0x4C (1500 x 0x40), MOTD +0x1774C |
| character +0xE0C / +0xE10 | guild id (-1 none) / guild rank (2 leader) |
| 0x009043A4 | group leader name (empty when not grouped) |
| 0x00904248 / 0x0090424D / 0x00904390 | group member flags / names (0x40 each) / spawns, cleared together (0x19C bytes) |
| 0x00985808 | a group invite box is open |
| 0x0091D708 | `CRaid_guess`: state +0x55E4 (1 none, 2 invite pending, 4 in a raid), +0x55F0 loot type, +0x5AB8 locked |
| 0x0079DC78 | task manager |
| 0x00850350 | tribute and guild tribute |
| 0x009232F0 | adventure manager; mode at +4 |
| 0x009231C8 | expedition manager |
| 0x009859EC | leadership object |

## Known client bugs

- [B16, B17](../KNOWN_CLIENT_BUGS.md#guilds-tu_010_guilds-tu_166_guildmanagementwnd): 0x0040A79B `RecordTable_guess::FindGuildIdByNamePrefix_guess` finds a guild by name prefix;
  0x0040AE42 `SendGuildBankerFlags_guess` refuses below leader rank with string id 516; the claimed wording mismatch needs the matching eqstr_us.txt.
- [B44, B45](../KNOWN_CLIENT_BUGS.md#guilds-tu_010_guilds-tu_166_guildmanagementwnd): guild management window notes by hash
  (0x0050F485 `FindPersonalNote_guess`); `UpdateButtons_guess` (0x0050E2D2) does not change the Promote button's enabled state.
- [B61](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd): guild
  bank split (0x0050DD43).
- [B50](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd) and
  [B49](../KNOWN_CLIENT_BUGS.md#other-confirmed-behaviour): tribute item reply accepts slot 31 (0x004347D3 `OnItemDonated_guess`);
  the per-bag send loop cannot run (0x00433EAC).
- [B62, B63](../KNOWN_CLIENT_BUGS.md#windows-tu_099-to-tu_234): task window timer colour (0x0055E645) and
  task sort comparator (0x0055F412 `CompareTimeLeft_guess`).
- [B78](../KNOWN_CLIENT_BUGS.md#purchase-prompts-tu_001_sync-tu_064_sync-tu_085_recommendeddrivers): adventure multi-item purchase prompt ids (0x00401527); the claimed wording swap needs the matching
  eqstr_us.txt.
- [B82](../KNOWN_CLIENT_BUGS.md#windows-tu_099-to-tu_234): group search filters, the last one wins
  (0x00508955 `CGroupSearchFiltersWnd_guess::IsFilteredOut_guess`).
