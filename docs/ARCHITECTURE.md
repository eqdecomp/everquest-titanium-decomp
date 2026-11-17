# EverQuest Titanium client: architecture overview

A reader's map of `eqgame.exe` (build "Oct 31 2005 10:33:37") as rebuilt in this tree. It says which part
of the client does what, where the code is, and how the parts talk to each other. Addresses (VAs) are given
beside names because many names are still provisional: a name ending in `_guess` was made up here, and the
same original class often has a different local name in each file. The VA never changes; grep for
`FUNCTION: TITANIUM 0x<VA>` to find a function.

File names, function names and counts are those of the source tree this page ships with. Statements marked
[bin] were checked against the original binary; the rest is read from the source. This page mostly uses
short names (no `_guess`, no class prefix); the subsystem pages give the exact source names. One that differs
in more than the suffix: "Tick" here is `DoPassageOfTime_guess` (0x00422198).

Pages:
- [README.md](README.md): source layout, `_guess` names, markers, match and queue states, fixtures.
- [startup.md](startup.md): WinMain, the eqmain hand-off, CEverQuest's lifetime, the main loop.
- [network.md](network.md): connections, the send path, the dispatcher, opcodes, zone-in order.
- [world.md](world.md): CEverQuest, CDisplay, EQPlayer, EQ_PC and the profile block, zoning.
- [ui.md](ui.md): CXWnd / CSidlScreenWnd, XML screens, which file holds which window.
- [items_inventory.md](items_inventory.md): item packets, modes, slot numbers, inventory windows.
- [spells.md](spells.md): the spell table, casting, buffs, spell messages and windows.
- [rendering.md](rendering.md): the graphics DLL interfaces, one frame, actors.
- [subsystems/README.md](subsystems/README.md): one short page per subsystem: files, key functions, data flow, globals, bugs.
- [KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md): original client defects the tree keeps, with evidence.
- [ATTRIBUTION.md](ATTRIBUTION.md): sources of names and constants.
- [VC71_QUIRKS.md](VC71_QUIRKS.md): Visual C++ .NET 2003 code-generation patterns for byte-exact matching.

Contents
1. The three images and what is rewritten
2. Subsystems, files and classes
3. The globals that tie it together
4. Process lifetime
5. Game states and the main loop
6. Network: connections, sending, the dispatcher
7. Connecting to world and zone: the message flow
8. Spawns: EQPlayer and its actor data
9. The character: EQ_PC, EQ_Character and the profile
10. Items and inventory
11. Spells
12. Combat
13. Commands and input
14. The UI
15. Rendering and sound
16. What is not rewritten
17. Original bugs worth knowing
18. Reading traps

--------------------------------------------------------------------------------------------------------

## 1. The three images and what is rewritten

| Image | Role | In this tree |
|---|---|---|
| `eqgame.exe` | the game: world, UI, network, rules | `src/EverQuest/` (193 files), 5 pilots in `src/Suite/` |
| eqmain.dll | login and server select, loaded by WinMain | no |
| EQGraphicsDX9.dll | renderer, collision, math; reached through interfaces | no |

Inside `eqgame.exe` the code falls into address bands:

| Range | What | State |
|---|---|---|
| 0x00401000 - 0x00570FCA | game code, one `tu_NNN_<Name>.cpp` per original object file | rewritten: 5,870 queue rows |
| 0x00571000 - 0x005DFFFF | the UI library ("Suite": CXWnd, CSidlScreenWnd, CListWnd, CXStr, SIDL/XML) | not rewritten, 5 pilots |
| 0x005E0000 - 0x0060CFFF | item accessors, EQ_Character helpers (0x005EC220 GetCharInfo2), the connection library, the graphics-DLL loader (0x00609680), ini helpers | not rewritten |
| 0x0060D000 up | C runtime | not rewritten |

Every function in the band has a queue row: tested (accepted, nearly all byte-identical), rewritten (not
accepted yet; nearly all have a behaviour fixture), todo, library (CRT, STL and exception code linked into
the game band) or skipped. PROGRESS.md at the repository root has the current counts. A function that is
not identical carries an `@early-stop` line; its source is complete, but its details deserve a second look
against the binary before they are quoted as fact (section 17 lists cases where that mattered).

--------------------------------------------------------------------------------------------------------

## 2. Subsystems, files and classes

`tu_NNN` is the index of the original object file in link order, not a feature; the `_<Name>` after it is
the original file name where the binary or the earlier sibling decomp gives it, else the class that owns most
of the file. The class column gives the intended name; in the source most classes still appear under
per-file view names.

| Subsystem | Files | Classes / objects | Entry points (VA) |
|---|---|---|---|
| Process start, window, input devices | tu_097_Win | WinMain, eqWndProc, DirectInput setup | 0x004CFD32 WinMain_guess, 0x004CF93C ExecuteEverQuest_guess, 0x004CE798 eqWndProc |
| Game object and main loop | tu_062_EverQuest (original `EverQuest.cpp`), tu_023_SystemCommands, tu_063_Options | CEverQuest | ctor 0x004A3341, 0x004ACF33 ProcessGame, 0x004ABA14 DoMainLoop |
| Message handlers | tu_042_EQHandleMsg | CEverQuest (handlers), item placement | 0x0045B8F0 dispatcher, handlers 0x00451ABA-0x0045B86D |
| Connection management | tu_017_ConnectionManager, tu_073_login | ConnectionManager, world login | 0x00424F2E Connect, 0x004B649F AuthenticateWorld, 0x004B611D ConnectToHost |
| World view | tu_029_Display, tu_049_EQMoveMissle, tu_084_Weather | CDisplay | ctor 0x0043DA73, 0x00444116 LoadZone, 0x00445A6C Render_World |
| Spawns | tu_053_EQPlayer, tu_057_RaceTagTable, tu_039_EQAnimate (animation), tu_047_EQMissile (missiles) | EQPlayer, actor data | ctor 0x004850A0, 0x0048297B DoAttack, 0x00450C2F SetAnim |
| Movement and physics | tu_055_Movement, tu_056_EQMovePlayer, tu_081_Physics | movement state, process_physics | 0x0048A0FC GetFloorHeightAt, 0x0048B6C5 CheckForUnderFloor, 0x004BFE0F process_physics |
| Character rules | tu_013_EQ_Character (EQ_Character), tu_079_PlayerProfile, tu_080_EQ_PC (EQ_PC) | EQ_Character, EQ_PC | 0x00422198 Tick (DoPassageOfTime_guess), 0x0041C905 TakeDamage, 0x0041F4A0 UseSkill, 0x004BA899 profile load (Handle_OP_PlayerProfile_guess) |
| Spells | tu_012_CharacterMagicSystem (original `CharacterMagicSystem.cpp`), tu_011_SpellFocus, tu_038_EQ_Spell, tu_089_Story | EQ_Character (magic), EQ_Spell, spell table | 0x00411F3D CastSpell, 0x00414913 HitBySpell, 0x0041002F InitializeSpellAffects |
| Items | tu_069_KeypressHandler, tu_077_ItemMoveQueue, tu_171-tu_174, tu_148-tu_150 | EQ_Item, CInvSlot, CInvSlotMgr, containers | 0x004B232E item factory (CreateItemList_guess), 0x0045A817 PlaceReceivedItem, 0x0051A9A8 MoveItem |
| Commands | tu_044_ExecuteCmd, tu_046_EQMisc | key commands, slash commands | 0x004619CD ExecuteCmd, 0x00498B78 InterpretCmd |
| Chat, text filters | tu_143_ChatManager, tu_144_ChatWindow, tu_051_bad_word_class | CChatManager, CChatWindow | |
| Groups, raids, guilds, tasks, tribute, adventures, expeditions | tu_025_Raid, tu_010_guilds, tu_026_TaskManager, tu_027_Tribute, tu_008_AdventureManager, tu_031_Expedition | one manager each, with its own opcode switch | guild 0x0040B8CB HandleMessage, tasks 0x00433887 HandleTaskMessage, tribute 0x00434D9A HandleTributeMessage, adventure 0x004089B2 OnEvent, expeditions 0x00447364 Dispatch |
| Sound and music | tu_037_EQ_SoundManager, tu_087_SoundManager | EqSoundManager, Miles wrappers | ctor 0x0044CA8F |
| Windows | tu_099_ActionsWnd - tu_236_VideoModesWnd (alphabetical by class) | about 115 CSidlScreenWnd classes | one constructor each |
| Options, key map, ini | tu_063_Options, tu_069_KeypressHandler, tu_192_OptionsWnd | LoadOptions, KeyMap, COptionsWnd | 0x004AF32C loadOptions_guess |

--------------------------------------------------------------------------------------------------------

## 3. The globals that tie it together

The client is built around a handful of singletons reached through globals. Code reads them at their
original addresses (`EQ_GLOBAL(type, 0x...)`); MQ2 users know several as `pinst...`.

| Global | Address | Points to |
|---|---|---|
| `pEverQuest` | 0x00988DF0 | the CEverQuest object (0x3A1C8 bytes): game state, chat, command entry, message handlers |
| `pinstCDisplay` | 0x00905D24 | CDisplay: zone, actors, camera, UI life cycle; +0x148 holds the frame time |
| `pCharData` | 0x00905D00 | the local character (EQ_PC, 0xC4D0 bytes) |
| `pinstLocalPlayer` | 0x00905CE4 | our own EQPlayer |
| controlled spawn | 0x00905CF8 | the spawn we steer (differs from the local player on a boat or when controlling a pet) |
| `pinstTarget` | 0x00905D04 | current target EQPlayer |
| spawn list | 0x00905CC4 | head of the EQPlayer list; id table at 0x00900F50 (0x00401B28 looks up by id) |
| connection | 0x00905CA0 | the live world or zone connection; senders pass its address |
| connection manager | 0x0079DBD8 | opens and closes connections |
| `pStringTable` | 0x00905CB0 | eqstr_us.txt lookups: `getString(id, 0)`; dbstr_us.txt has its own manager at 0x00850398 |
| spell table | 0x00985CC8 | EQ_Spell records by id |
| skill table | 0x00851200 | one record per skill id (name string, reuse time, per-class data) |
| window manager | 0x0099D3EC | CXWndManager: all windows, focus, drawing |
| graphics object | 0x0099E38C | game-side video state; +4 is the fullscreen flag [bin] |
| graphics interfaces | 0x0099E348 - 0x0099E374 | vtable objects inside the graphics DLL |
| sound manager | 0x00851390 | EqSoundManager |
| window pointers | 0x00850B9C - 0x00850CC8, 0x009917xx - 0x009929xx | one global per game window; a few hold other UI objects (0x00991B88 item-display manager, 0x00991E44 confirmation-dialog manager) |
| auto-attack / auto-fire | 0x009858C7 / 0x009858C8 | set through 0x004A2F7A SetAutoAttack_guess / 0x0049994C SetAutoFire_guess |
| key states | 0x00925520[command id] | held movement and camera keys |
| command names | 0x00789908 | 0xF7 name strings, AUTORUN .. ROTATE_STATS [bin] |
| offline flags | 0x00923798, 0x00923884 | when set, the client runs without a server; nothing in the rewritten code sets them |
| leave code | 0x00923794 | why the frame loop ended: 0xFD exit, 0xFE back to character select |
| "in world" flag | 0x00923788 | set when the zone answers MSG_READY_ENTER_WORLD |
| server mode | 0x00900478 | rule set from the world server; 0 means players cannot harm players |
| ms clock | 0x0046D655 | rdtsc minus a base taken in WinMain, in ms since client start [bin] |

--------------------------------------------------------------------------------------------------------

## 4. Process lifetime

```
WinMain 0x004CFD32 (tu_097_Win)
  log the start and build, graphics object, load EQGraphicsDX9.dll (0x00609680)
  calibrate timers -> base for the ms clock
  pre-init 0x004CED8F: critical files, arguments, WinSock, Keyboard.txt, window class, main window
  loop:
    run the front end 0x004CE2D6: load eqmain.dll, call its entry with the block at 0x00986FC0
    copy account, password, world host, key code to the login globals (0x00904004 ...)
    ExecuteEverQuest 0x004CF93C
      DirectInput keyboard and mouse
      pEverQuest = new CEverQuest          ctor 0x004A3341
      DoLogin 0x0049377D                   world login, spell table, string tables, CDisplay init
      0x004CDD75 (SEH guard) -> 0x004CDD09 run the game, then tear down
         CEverQuest::ProcessGame 0x004ACF33     the whole session (section 5)
         log the cleanup, delete pEverQuest, delete three critical sections
      release input devices
```

0x004CDD75 `GuardedShutdown_guess` is misleading: through 0x004CDD09 `RunGameAndShutdown_guess` it runs the
game first, then shuts down. WinMain's loop lets the player go back to server select without restarting the process.
0x004CDD75 runs the game under `__try`; its `__except` filter writes a crash report and the handler
(0x004CDE43-0x004CE2D5, reached only through the SEH scope table) adds system details, offers to send the
report and exits. The function is identical, handler included ([startup.md](startup.md)).

--------------------------------------------------------------------------------------------------------

## 5. Game states and the main loop

`CEverQuest::SetGameState` (0x00494B3D) stores the state and, for 1, 2 and 5, switches groups of key
commands on or off.

| State | Meaning | Set by |
|---|---|---|
| 0 | session start | ProcessGame entry |
| 1 | character select | 0x004A9EBF (character select), 0x004AA92B |
| 2 | character-creation screen loop | 0x004A9CD2 (named RunCharacterSelectLoop_guess) |
| 3 | OP_EnterWorld sent, waiting for the zone address | ProcessGame |
| 7 | creating the initial actors (DoMainLoop restores the previous state after) | DoMainLoop entry |
| 5 | in the zone: the frame loop runs | DoMainLoop, ProcessGame |
| 0xFD | zone address arrived during the first wait | ProcessGame |
| 0xFF | leave the session | many error paths, normal exit |

### ProcessGame (0x004ACF33)
```
state 0
while state != 0xFF:
    no character chosen:  authenticate to world if needed, run character select (0x004AA92B)
    else:                 check Spdat.eff and eqgame.exe checksums
                          send OP_EnterWorld (0x7CBA) with the name; state 3
                          pump messages up to 120 s for the zone address (logs a time-out if none comes)
    while state != 0xFF:
        on a re-zone: world re-auth, OP_EnterWorld again, wait
        EnterZone 0x004A861D        sends OP_ReqNewZone, loads the zone
        per-character ini files
        request AA data and skill rank data
        DoMainLoop 0x004ABA14       the zone session
        free the profile's items, stop the world display
        leave code 0xFD or 0xFE: break
    leave code 0xFE: send opcode 0x0F66 (logout, no EQEmu name), back to character select
    leave code 0xFD: state 0xFF, return
```

### DoMainLoop (0x004ABA14)
Zone-in part: state 7 while the initial actors are created, then the previous state again; load the game
sounds; send OP_ReqClientSpawn and wait for the ready flag; convert old hot buttons; send OP_SendExpZonein
(the client's MSG_READY_ENTER_WORLD) and wait again; send OP_ClientReady; set up models, the character and
music.

Frame part, once per frame while the state is 5:
```
frame time = ms clock -> CDisplay +0x148
ProcessMBox 0x004A56B1                 queued message boxes and received messages
zone change pending (0x00923D7A): return
connection lost check 0x00496932       on loss: wait 16 s, set leave code, OP_DeleteSpawn, return
ProcessGameEvents 0x004A9C84           mouse, Windows messages, keyboard
world time, movement of the local player, lights, sounds, OP_ClientUpdate (0x14CB) when we moved
window manager: mouse move, ProcessFrame, DrawWindows, DrawCursor
ProcessControls 0x004A1D74             only while the window is active
CDisplay::Render_World 0x00445A6C      skipped for the first 30 frames; calls RealRender_World_guess
                                       0x00445243, which runs Tick 0x00422198 (DoPassageOfTime_guess,
                                       section 9) unless paused (0x00905CA4)
sleep for the rest of the frame
```
The character-select and character-creation screens have their own smaller frame loops (0x004A9EBF,
0x004A9CD2) with the same shape: input, network pump, disconnect check, UI, render.

--------------------------------------------------------------------------------------------------------

## 6. Network: connections, sending, the dispatcher

One connection is live at a time: first the world server, then a zone server. Both use the same connection
library (not rewritten). An application message is a 16-bit opcode followed by the payload.

- Open/close: ConnectionManager (tu_017_ConnectionManager, global 0x0079DBD8): 0x00424F2E Connect(host, port, flags),
  0x00424FB5 WaitForDisconnect, 0x0042500C close (clears the caller's pointer). Port settings come from
  `[Networking]` in eqclient.ini.
- Send: `EQSendMessage(&conn, opcode, data, size, wait)` at 0x004912B1. 0x006007F0 puts the opcode in
  front of the payload; a failed send logs the connection status and tears the connection down. With the
  offline flag 0x00923798 set, sending on a null connection returns 0 without logging.
- Receive: the library calls back 0x00424E57 with (connection id, bytes, length); it passes
  `*(u16*)bytes`, `bytes + 2`, `length - 2` to the dispatcher.
- Before a character is in the world, world messages go to the login handler in tu_073_login (0x004B624F)
  instead.

### The dispatcher (0x0045B8F0, tu_042_EQHandleMsg, 24 KB)
`EverQuestB8F0_guess::HandleWorldMessage_guess(connection, opcode, data, size)`, a CEverQuest method. Two
`switch` statements in a row:
1. always: connect and zone-in messages, character data, items, coins, spells, doors, GM tools, and
   whole families forwarded to their manager (tasks 0x00433887 TaskManagerView_guess::HandleTaskMessage_guess, tribute 0x00434D9A
   HandleTributeMessage, guild tribute 0x00435163 MessageRouter_guess::HandleGuildTributeMessage_guess);
2. only when CDisplay reports the world as loaded (0x0043745D): chat and combat text, spawn and position
   updates, ground objects, trade and merchant, and the families forwarded to the guild (0x0040B8CB),
   adventure (0x004089B2) and expedition (0x00447364) managers; more task messages also go to
   0x00433887 from here.

439 case labels in 331 groups. There is no default case: an unknown opcode is ignored. The function
returns 1, except 0 when the OP_ZoneEntry handler fails.

Case labels and send arguments are `OP_` names from `include/titanium/opcodes.h` (names and values from
EQEmu's `patch_Titanium.conf`) where the value has one unique EQEmu name: 259 of the 439 labels. The rest
keep their number, including some well-known messages (OP_ZoneChange 0x5DD8, OP_ReqNewZone 0x7AC5,
OP_ReqClientSpawn 0x0322); the pages give their EQEmu name with the value. The client's own names survive
only in log strings [bin]:

| Opcode | EQEmu | Client log text |
|---|---|---|
| OP_ZoneServerInfo (0x61B6) | MSG_ZONE_ADDRESS |
| OP_PlayerProfile (0x75DF) | MSG_SEND_PC |
| OP_ZoneEntry (0x7213) | MSG_EQ_ADDPLAYER |
| OP_ZoneSpawns (0x2E78) | MSG_EQ_NETPLAYERBUFF |
| OP_TimeOfDay (0x1580) | MSG_TIME_STAMP |
| OP_Weather (0x254D) | MSG_WEATHER_EVENT |
| OP_SendExpZonein (0x0587) | MSG_READY_ENTER_WORLD |
| OP_RequestClientZoneChange (0x7834) | MSG_TELEPORT_PC |
| 0x0F66 (no EQEmu name) | MSG_LOGOUT_PLAYER |

--------------------------------------------------------------------------------------------------------

## 7. Connecting to world and zone: the message flow

C = client sends, S = server sends. "Zone connect step N" is the step number the client logs.

| # | Dir | Message | Code |
|---|---|---|---|
| 1 | C | connect to the world host (0x00904104); OP_SendLoginInfo (0x4DD0, account, password), or 0x34C7 with a key code | 0x004B649F AuthenticateWorld (tu_073_login) |
| 2 | S | OP_LogServer (0x0FA6), OP_ApproveWorld (0x3C25), OP_SendCharInfo (0x4513) ... | 0x004B624F, later dispatcher case OP_LogServer |
| 3 | C | OP_WorldClientReady (0x5E99); character select; OP_CharacterCreate (0x10B2), OP_ApproveName (0x3EA6), OP_RandomNameGenerator (0x23D4) from the creation screen | 0x004A9EBF, tu_141_CharacterCreation |
| 4 | C | OP_EnterWorld (0x7CBA) with the character name; game state 3 | 0x004A9EBF / 0x004ACF33 |
| 5 | S | zone connect step 0: MSG_ZONE_ADDRESS (host, port) | dispatcher case OP_ZoneServerInfo (0x61B6) |
| 6 | C | OP_WorldComplete (0x509D); wait up to 30 s for the world to drop us; connect to the zone | case OP_ZoneServerInfo, 0x004B611D ConnectToHost |
| 7 | C | OP_ZoneEntry (0x7213, 0x44 bytes: name and a hash) | 0x004A8193 GetZoneInfoFromNetwork |
| 8 | S | zone connect step 3: MSG_SEND_PC, the player profile (0x4C88 bytes, checksummed) | case OP_PlayerProfile (0x75DF) -> 0x004BA899 |
| 9 | S | zone connect step 4: MSG_EQ_ADDPLAYER, our own spawn | case OP_ZoneEntry (0x7213) -> 0x00457F32 |
| 10 | C | OP_ReqNewZone (0x7AC5) | 0x004A861D EnterZone |
| 11 | S | OP_NewZone (0x0920, zone header at 0x009239E0), OP_TimeOfDay, OP_Weather | dispatcher |
| 12 | C | OP_ReqClientSpawn (0x0322); first wait for the ready flag | DoMainLoop |
| 13 | S | OP_ZoneSpawns (0x2E78), OP_SpawnDoor (0x4C24), ground objects, OP_SendZonepoints (0x3EBA), OP_CharInventory (0x5394) ... | dispatcher |
| 14 | C | OP_SendExpZonein (0x0587, logged as MSG_READY_ENTER_WORLD) | DoMainLoop |
| 15 | S | OP_SendExpZonein (0x0587) back: sets 0x00923788 and refreshes windows | dispatcher, switch 2 |
| 16 | C | OP_ClientReady (0x5E20); the frame loop starts (state 5 was set before OP_ReqClientSpawn) | DoMainLoop |

Leaving a zone: OP_ZoneChange (0x5DD8) from 0x00499139 IsZoneAvailable_guess, OP_SaveOnZoneReq (0x1540) from
0x004976BF SavePCOnZone_guess, OP_DeleteSpawn (0x55BC) for ourselves; the server can also move us (OP_RequestClientZoneChange / MSG_TELEPORT_PC,
OP_GMGoto, OP_GMSummon, OP_ZonePlayerToBind, boat transfer 0x0B71, no EQEmu name). All of these end in 0x004AB056
(MoveToZone_guess), which takes a short reason string for the log (portal spell, GM goto, zone transfer,
vehicle transfer, ...).
Camping: `/camp` starts a timer in Tick; when it runs out the client sets 0x00923D94 to 8,
sends OP_Logout (0x61FF) and waits up to 3 s for the connection to close.

--------------------------------------------------------------------------------------------------------

## 8. Spawns: EQPlayer and its actor data

Every entity in a zone (players, NPCs, pets, corpses, boats, ourselves) is an `EQPlayer` (0x348 bytes, no
vtable; ctor 0x004850A0). The server's spawn record is copied field by field in 0x004816D7.

Fields that the rest of the code leans on (offsets [bin] where they were checked):

| Offset | Field | Notes |
|---|---|---|
| +0x30 / +0x34 / +0x38 | Y, X, Z | |
| +0x48 | run speed | |
| +0x4C | Heading | 0-511 |
| +0x120 | Name | |
| +0x1A0 | bounding radius | from Spawn_Struct +0x158 [bin]; the header's "SpeedHeading" label is wrong |
| +0x1A8 | pActorInfo | per-spawn working state, 0x10C0 bytes (below) |
| +0x1B2 | Linkdead | from Spawn_Struct +0x90; shown as " <LINKDEAD>" / " LD" [bin] |
| +0x214 / +0x220 | pNext / pPrev | the spawn list |
| +0x218 | character object | the EQ_Character of this spawn, when the client simulates one |
| +0x234, +0x238 | eye height, height offset | |
| +0x244 | Type | 0 player, 1 NPC, 2 and 3 corpses |
| +0x24C | Level | |
| +0x251 | StandState | 100 standing, 102 no control, 110 sitting, 111 ducking, 115 (0x73) lying: feign death, and knocked out (0x00484DF5 KnockedOut sets 115 and character state 3), 120 dead |
| +0x252 | Class | |
| +0x258 | SpawnID | |
| +0x25C | MasterID | owner of a pet |
| +0x260 | Race | |
| +0x270 | BodyType | 11, 60, 65, 67 cannot be targeted |
| +0x274 | HPCurrent | cached by TakeDamage |

Actor data (`pActorInfo`) holds what the client itself tracks for a spawn:

| Offset | Use |
|---|---|
| +0x54, +0x58, +0x74, +0x78 | last 1 s, 6 s, 18 s and 60 s tick times |
| +0x60, +0xDC | primary/range and secondary swing timers |
| +0x9D | last attack kind (11, 13, 14) |
| +0x114, +0x118 | skill timer and its delay |
| +0xD0 | time the stun ends |
| +0xD8, +0xF98, +0xF9C, +0x1048 | cast end time, spell being cast, gem, clicked item |
| +0x158 | the boat we stand on (not a pet) |
| +0x15C / +0x160 | mount / the spawn linked to a mount |
| +0x16C | pet's spawn id |
| +0x134, +0x138 | current and next animation |

Who owns what: the dispatcher's spawn handlers (0x004554E5 OP_NewSpawn, 0x00455710 OP_ZoneSpawns,
0x004581B7 OP_DeleteSpawn, 0x00451ABA OP_ClientUpdate, 0x0045242F OP_SpawnAppearance) create and update
spawns; CDisplay gives each one an actor in the graphics DLL; tu_039_EQAnimate chooses animations (0x00450C2F);
tu_055_Movement/tu_056_EQMovePlayer/tu_081_Physics move them (0x004BFE0F process_physics); tu_047_EQMissile flies missiles.

--------------------------------------------------------------------------------------------------------

## 9. The character: EQ_PC, EQ_Character and the profile

`pCharData` points at an `EQ_PC` (0xC4D0 bytes). It uses multiple and virtual inheritance: a second base
at +0xC280 and the virtual base `EQ_Character` near the end. Code reaches the virtual base through the
vbptr's offset table: accessors such as `VirtualBase_guess()` in tu_013_EQ_Character (the table's layout is
in `include/titanium/layouts/core.h`). The rules live on `EQ_Character` (tu_012_CharacterMagicSystem, tu_013_EQ_Character); the same
code also runs for NPC character objects the client creates.

`EQ_Character::GetCharInfo2` (0x005EC220, not rewritten) returns the profile block that most code reads.
Offsets into that block:

| Offset | Field | Evidence |
|---|---|---|
| +0x0010 .. | item pointers by slot (0-30; slot 30 is the cursor) | CastSpell, HitBySpell |
| +0x0730 | spell book, 0x200 entries | bounded accessor 0x0041AA26 [bin] |
| +0x0F70 .. | skills | Alcohol Tolerance (66) read by MakeDrunk |
| +0x1198 | race | racial forge checks |
| +0x119C | class | lexicon checks, bard tests |
| +0x11A4 | level | |
| +0x11A8 | mana | SPA 15 path, CastSpell's mana test |
| +0x11AC | endurance | SPA 189 / 198 through 0x0040E2BD |
| +0x11D4 - +0x11E0 | platinum, gold, silver, copper carried | |
| +0x11E4 - +0x11F0 | the same four on the cursor | sent as OP_MoveCoin |

Other character state: +0xFC is a state byte (0 normal, 1 set by a mez or a stun, 3 knocked out, 4 a
final state in which Tick and TakeDamage do nothing); +0xBC the name of the boat being ridden; the buff array is reached through 0x0040E7AC.

### Tick: DoPassageOfTime_guess (0x00422198), once per frame
Reports changes to the server (run mode, target, auto-attack, auto-fire), finishes a poison application,
ends stuns, keeps the swing and skill timers, drives tracking, hide and camping, and runs the timed work:
every second the cooldowns, movement effects and boat messages; every 6 s the buff tick, regeneration and
bleeding; every 18 s and 60 s smaller counters; then the death check and the social-macro player.

### Profile load
OP_PlayerProfile goes to 0x004BA899 (size 0x4C88, checksum), which copies it into the EQ_PC through
0x004BA0FB LoadProfile. The in-memory layout is the client's own; EQEmu's packet offsets do not apply past the head.

--------------------------------------------------------------------------------------------------------

## 10. Items and inventory

An item instance is an `EQ_Item` (0xA8 bytes, vtable 0x00644780): a pointer to the item definition at
+0x1C, up to 10 contained items at +0x20 (bag contents or augments) and a count at +0x48. tu_069_KeypressHandler names it
`EQ_Item_guess`; another view of the item there, `SettingsLoader_guess` (its `Load_guess` 0x004B212A parses the item record), keeps its own name. The definition's accessors are in the
0x005E0000 band and are not rewritten; each file declares the ones it uses under local names. Three that
were pinned down in review: 0x005EC8B0 class mask (+0x114), 0x005EC920 race mask (+0x118), 0x005ECCC0
item class byte (+0xD5: 0 item, 1 container, 2 book), 0x005E10B0 the augment's distiller item id (+0x2A0).

Arrival: OP_ItemPacket (0x3397) carries a mode and a text record. 0x004B232E builds the item; if it parses,
`PlaceReceivedItem` (0x0045A817) puts it by mode: merchant list, trade window, loot window, the character's
slots, the cursor queue, a world container, tribute slots. OP_CharInventory (0x5394) delivers everything
at zone-in.

Slot numbers (Titanium): 0-21 worn, 22-29 general, 30 cursor; bag contents 251-330 (331-340: the bag on the cursor) as
`31 + 10 * slot + n`; bank 2000-2015 with bag contents from 2031; shared bank 2500-2501 with 2531 up;
tribute 400-404; guild tribute 450-451.

Moving: a click on an `InvSlotWnd` (tu_173_InvSlotWnd, original `InvSlotWnd.cpp`) reaches its `CInvSlot`; the
`CInvSlotMgr` (global 0x00850CB8) swaps the two slots and sends OP_MoveItem (0x420F: from, to, 0).
tu_077_ItemMoveQueue also holds the position history (`PositionHistory_guess`), whose `BuildMessage` 0x004B6F1F
feeds the movement-history opcode 0x6A1B; its 2 s hold mixes two clocks (section 17). Coins move with OP_MoveCoin (0x7657).
Containers: `CContainerMgr` (tu_148_ContainerMgr) hands out `CContainerWnd`s (tu_149_ContainerWnd), which also do tradeskill
combines and augment insertion/removal.

--------------------------------------------------------------------------------------------------------

## 11. Spells

Data: spells_us.txt is parsed at login (0x0044DBF0 per line) into the table at 0x00985CC8. An `EQ_Spell`
has fixed fields and twelve effect slots: effect id (SPA) at +0x120, base, max, formula, a second value at
+0x60. Useful fields: +0x14 cast time, +0x20 duration formula, +0x2C mana, +0x17D beneficial, +0x180
target type, +0x1C4 combat ability, +0x1FC "cast in any state".

Casting, on the character (tu_012_CharacterMagicSystem):
```
gem click / item click / hot button
  -> CastSpell 0x00411F3D        checks in order, each with its own message
       -> OP_CastSpell (0x304B)    gem, spell, inventory slot, target id
server: OP_BeginCast (0x3990)      -> CEverQuest 0x0049B39D: casting bar, animation
server: OP_Action / OP_Damage    -> EQPlayer 0x0047F614 -> HitBySpell 0x00414913
server: OP_Buff (0x6A53)           -> buff slot written by the dispatcher
server: OP_InterruptCast, OP_ManaChange, OP_MemorizeSpell ...
```

`HitBySpell` (0x00414913) decides locally whether the spell lands (immunity, level, PvP and group rules),
applies instant effects slot by slot, or places a buff through the stacking code 0x00414071 FindBuffSlot_guess and sets up
its standing state. `InitializeSpellAffects` (0x0041002F) rebuilds the per-SPA totals from the buffs and
`FinishSpellAffects` (0x0040F8C3) adds worn item effects; `TotalSpellAffects` (0x004106A3) reads a total.
Most SPAs add up; haste, movement speed and a few others keep one value by fixed rules
(0x0041002F). Focus limits (SPA 134-144, 311, 348) are checked in tu_011_SpellFocus (0x0040CC88 CheckFocusLimit).

Three tests that many comments rely on: 0x0040DB0B IsBardSong "is a bard song" (class 8, not a combat ability, a real
level for bards) [bin]; 0x0040E40B IsBuffLevelBlocked "too powerful for the target"; 0x004BB226 (IsAGroupMember_guess) "is in
my group".

Windows: CSpellBookWnd (tu_215_SpellBookWnd), CCastSpellWnd (tu_140_CastSpellWnd, the gem bar), CSpellGemWnd (tu_216_SpellGemWnd), CCastingWnd
(tu_139_CastingWnd), CBuffWindow (tu_136_BuffWindow).

--------------------------------------------------------------------------------------------------------

## 12. Combat

The server decides hits. The client keeps timers, plays the swing, and mirrors the damage rules it needs
for display and for its own state.

- Timers: Tick sets the ready flags (0x00924670 primary, 0x00924671 secondary, 0x00924672 skill attack, and
  one byte per skill at 0x0092460C) when a delay has passed. Delay = item delay x 100 ms, or a skill's reuse
  time for bare hands, then haste (0x0047F01E ModifyAttackSpeed_guess, the Mac client's ModifyAttackSpeed). The skill-attack byte comes from the actor's
  skill timer (+0x114/+0x118), and UseSkill (0x0041F4A0) clears it before a melee skill; there is no separate
  ranged ready byte (the source calls 0x00924672 `g_skillAttackReady_guess`).
- `EQPlayer::DoAttack` (0x0048297B): `kind` 11/13/14 for range, primary, secondary; 100 for a skill attack;
  checks stance and range, swaps weapon models when changing between ranged and melee, rolls dual wield
  (0x0041EDAC CheckDualWield) and double attack (0x0041EE86 CanDoubleAttack) for the animation, and calls 0x004753F0 (DoMissileHit_guess)
  once per swing.
- `EQ_Character::TakeDamage` (0x0041C905): runs for a damage record on a character the client simulates:
  invulnerability, mez break, runes and mitigation, the HP change, the bash/kick stun roll, death, and the
  outgoing OP_Damage (0x5C78). Environmental damage to ourselves goes out as OP_EnvDamage (0x31B3).
- Incoming: OP_Damage and OP_Action (dispatcher switch 2) -> 0x00452C54 and the EQPlayer hit handlers;
  OP_Death (0x6160); HP updates OP_MobHealth (0x0695), OP_HPUpdate (0x3BCF), OP_InitialMobHealth (0x3D2D).
- Auto-attack is the flag 0x009858C7, toggled by command AUTOPRIM; Tick reports it with OP_AutoAttack
  (0x5E55) and OP_AutoAttack2 (0x0701), and auto-fire with OP_AutoFire (0x6C53).
- Skills: `UseSkill` (0x0041F4A0, tu_013_EQ_Character); pickpocket, begging, bind wound and the rest have their own
  opcodes and reply cases in the dispatcher.

--------------------------------------------------------------------------------------------------------

## 13. Commands and input

Input devices are DirectInput 8 (tu_097_Win): buffered keyboard and mouse data are read each frame and turned
into command ids through the key map (tu_069_KeypressHandler; names from Keyboard.txt and the table at 0x00789908).

`ExecuteCmd(command, keyDown, data)` (0x004619CD, tu_044_ExecuteCmd) is the single entry for key-map commands, hot
buttons and several UI buttons. Ids below 0xF7 have names in the client (AUTORUN 0, JUMP 1, FORWARD 2,
AUTOPRIM 0x0A, DUCK 0x0C, TARGETME 0x18, HOT1_1 0x23, CAST1 0x73, SIT_STAND 0x8A, ...), read from the
table at 0x00789908. Movement and camera keys only record their state in
0x00925520[id]; the movement code reads it each frame.

Typed lines go to `CEverQuest::InterpretCmd` (0x00498B78); the slash commands are a table of handlers in
tu_046_EQMisc (about 400 functions). Socials (macros) are run by Tick, one line per 100 ms.

--------------------------------------------------------------------------------------------------------

## 14. The UI

Two layers. The window library (original `C:\EQ\Suite\Suite\`: XWnd.cpp, SidlScreenWnd.cpp, ButtonWnd.cpp,
ComboWnd.cpp) is in the 0x00571000 band and not rewritten. The game's windows derive from it and are
rewritten, mostly one window class per file, tu_099_ActionsWnd to tu_236_VideoModesWnd in alphabetical class order.

```
CXWnd (0x11C bytes)                 +0x5C Show, +0x5D Enabled, +0x64 style, children/siblings at +0x2C/+0x30
 |- CButtonWnd                      +0x128 Checked (setter 0x005BB140)
 |- CListWnd                        AddString 0x0059B9D0, GetCurSel 0x00597BE0, GetItemData 0x00597ED0
 |- edit, label, gauge, slider, STML text ...
 `- CSidlScreenWnd (0x15C bytes)    a window built from an XML <Screen>
      `- about 115 game windows
CXWndManager (0x0099D3EC)           owns the windows: mouse, focus, per-frame, drawing
CSidlManager (0x0099D3F4)           the loaded XML: screens, templates, animations
```

A game window's constructor always has the same shape: pass the screen name to the base
(`"InventoryWindow"`), call `CreateChildrenFromSidl` (0x005A25B0), fetch each control with
`GetChildItem("<XML name>")` (0x005A1E10). Behaviour is in the overrides: `WndNotification(sender,
message, data)` for clicks and selections (message 1 = click, 0x1F = a quantity or confirmation answer),
`OnProcessFrame` for per-frame refresh, sometimes `Draw`. Virtual slot 48 (+0xC0) is Show.

CDisplay owns the life cycle (tu_029_Display): 0x00442D80 loads EQUI.xml from the skin folder (falling back to
the default skin once on an XML error), 0x0043EE74 creates the character-select windows and 0x0043EFDD the
game windows, each stored in its own global; 0x0043AF46 deletes them; 0x00443DBC reloads the UI. A file
that uses another file's window includes its header, `include/titanium/wnd/<Class>.h` (one per window or UI
class), and calls it through that global; ui.md explains the layout.
Window positions are saved per character through `StoreIniInfo` / `LoadIniInfo`.

Windows talk to the rest of the game directly: they read `pCharData` and the spawn list, call ExecuteCmd
or the managers, and send their own messages with EQSendMessage. There is no model/view separation.

--------------------------------------------------------------------------------------------------------

## 15. Rendering and sound

`eqgame.exe` does not render the world itself. WinMain loads EQGraphicsDX9.dll (or the DLL named in
`[Defaults] GraphicsDLL9`), calls its `CreateGraphicsEngine` export and keeps nine interface pointers at
0x0099E348-0x0099E374: file access, resources, the renderer, the world (actors, sky, time), particles,
collision and traces, and math (`Sin`, `Cos`). Game code only calls virtual methods on them; every file
declares a small local view of the slots it uses.

One frame (0x00445243, called through 0x00445A6C): feed the sound manager and particles the listener
position, move the boat the controlled spawn stands on (actor +0x158), then, unless paused, the controlled
and local spawns; run physics for the other spawns, update the sky,
then begin frame, optional video-mode change or screenshot, end frame. The UI library draws windows and
text through the same DLL.

Sound is separate: `EqSoundManager` (tu_037_EQ_SoundManager, global 0x00851390) and the Miles Sound System wrappers in
tu_087_SoundManager (2D and 3D sample pools, XMIDI, MP3 play lists).

--------------------------------------------------------------------------------------------------------

## 16. What is not rewritten

- The connection library (in the 0x005E0000-0x0060CFFF band): sessions, sequencing, compression and
  encoding of packets. Game code sees only connect, send, the status calls and the receive callback.
- The UI library (0x00571000 up): CXWnd and the controls, CXStr, the SIDL/XML loader, fonts and textures.
  Five functions exist as pilots in `src/Suite/`.
- Item, character and string-table helpers in the 0x005D0000-0x005F0000 band (GetCharInfo2 0x005EC220,
  item accessors 0x005E0xxx / 0x005ECxxx, getString 0x005DFA00, world data 0x005F6xxx).
- Library functions inside the game band (C runtime, STL, exception handling), skipped rows (export
  fragments, an SEH filter, mid-instruction entries) and the few functions still marked todo; PROGRESS.md
  counts them.
- eqmain.dll and EQGraphicsDX9.dll.

--------------------------------------------------------------------------------------------------------

## 17. Original bugs worth knowing

All checked in the binary. [KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md) has the full list with evidence; these are
the ones a reader meets first.

| Where | Bug | Id |
|---|---|---|
| LoadOptions 0x004AF32C | the Camera2-* ini keys are loaded into the Camera1 globals; camera 2 is never loaded | D01 |
| Tick 0x00422198 | a byte counter is tested against 300, so a periodic call (0x004A1350 SavePC_guess) never runs | B05 |
| Tick 0x00422198 | `/pause` in a macro is matched on 4 characters but its number is read at offset 7 | B06 |
| ExecuteCmd 0x004619CD | clipboard paste falls through into the PvP statistics-window toggle | B47 |
| ExecuteCmd 0x004619CD | cycle-reply passes the reply word as the sprintf format | B46 |
| ExecuteCmd 0x004619CD | the paste filter compares a signed char: bytes 0x80-0xFF become spaces | B48 |
| dispatcher 0x0045B8F0, case 0x4BB4 (no EQEmu name) | a batch position update with too large a count is read past the packet | X01 |
| position history 0x004B6F1F BuildMessage (opcode 0x6A1B) | entries are stamped with `EqGetTime` and aged with GetTickCount; the two clocks differ, so the 2 s hold does not work as intended | B42 |
| profile load 0x004BA0FB LoadProfile | one position field is written twice and another never | B27 |
| bag options 0x0053D0F5 BagOptions_guess::WriteBagFadeSetting_guess | only one ini section per bag kind gets the new fade settings | B08 |
| titles 0x00554E7A (the OP_CustomTitles handler, `CSkillsWndTitlesView_guess::Run_guess` in tu_213_SocialEditWnd) | server text is used as a sprintf format | B73 |
| hot-button loadouts 0x004B010A (SaveHotbuttonLoadouts_guess) | scans 100 entries of a 10-entry table | B85 |

Eight claimed bugs turned out to be decompilation or reading errors, not client bugs (B18, B20, B26, B35,
B37, B40, B51, B77; listed under "Not bugs" in KNOWN_CLIENT_BUGS.md).

--------------------------------------------------------------------------------------------------------

## 18. Reading traps

- One class, many names. `GlobalState_guess`, `EverQuestB8F0_guess`, `CEverQuest_guess` are all
  CEverQuest; `CostOwner_guess`, `TickUser_guess`, `CharacterMagicSystem_guess`, `DynamicPropertyOwner_guess`
  are all EQ_Character. Trust the VA of the method and the address of the global.
- Names that say less than the code does: 0x004CDD75 `GuardedShutdown_guess` runs the whole session
  (through 0x004CDD09 `RunGameAndShutdown_guess`) before it shuts down; 0x004A9CD2 `RunCharacterSelectLoop_guess` runs the character-creation screen; 0x00422198
  `DoPassageOfTime_guess` is the whole per-frame character tick, not only the buff tick.
- Opcode names are EQEmu's and sometimes describe another use (the client's coin-gift message is EQEmu's
  OP_Sound). Values without a unique EQEmu name stay numbers in the code; `include/titanium/opcodes.h` lists
  the 383 names used.
- String ids appear in hex in the code (`getString(0x3050, 0)`) and in decimal in eqstr_us.txt (12368).
- Spell effect ids (SPA), skill ids, classes, races and slots have enums in `include/titanium/`
  (spell_effects.h, skills.h, classes.h, races.h, slots.h); not every literal has been replaced, because
  some replacements change the generated code.
- StandState 0x66 is "no control of yourself" (stun, mez, charm), not feign death; 0x73 (115) is lying,
  used both by feign death and by a knock-out (KnockedOut 0x00484DF5). Command 0x0C is DUCK;
  SIT_STAND is 0x8A.
- `+0x1C4` on a spell marks a combat ability, not a bard song.
- Two accessor names in tu_080_EQ_PC are swapped with respect to what they return: `GetRaces_guess`
  (0x005EC8B0) returns the classes mask and `GetClasses_guess` (0x005EC920) the races mask.
- Three markers that look odd but are exact: `// GENERATED:` under `// FUNCTION:` with no body (the
  compiler wrote that function from the class), an `__asm` block under `// as original:` (no C++ produces
  those instructions; the line says why), and `__try` / `__except` (filter and handler are blocks of the
  enclosing function, not functions). README.md explains each.
- A function with `@early-stop` is not byte-identical. Several "possible bug" notes written from such source
  were wrong; check the binary before calling something an original bug.
