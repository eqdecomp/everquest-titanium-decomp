# Network: connections, sending, the dispatcher

[Overview](ARCHITECTURE.md) sections 6-7 | [Source guide](README.md)

The client talks to two servers over one connection object at a time: the world server (login, character
select) and then a zone server. Both use the same connection library (inside the 0x005E0000-0x0060CFFF
band, which also holds item and character helpers, ini helpers and the graphics-DLL loader; not rewritten)
and the same message format: a 16-bit opcode followed by the payload. Game code sees three
pieces:

| piece | where | what |
|---|---|---|
| `ConnectionManager_guess` | tu_017_ConnectionManager, global 0x0079DBD8 | opens and closes connections |
| `EQSendMessage` | 0x004912B1, tu_062_EverQuest | sends one message |
| `HandleWorldMessage_guess` | 0x0045B8F0, tu_042_EQHandleMsg | the opcode switch for every received message |

The live connection pointer is the global at 0x00905CA0. Most code passes its address
(`EQ_ARRAY(char, 0x00905CA0)` or `&g_connection_00905ca0_guess`) so a failed send can clear it.

```
                send                                          receive
 game code ---------------------------+        connection library (not rewritten)
   EQSendMessage(&conn, op, p, n, w)  |                 |
     |  0x006007F0 packs [op:2][p:n]  |                 v
     v                                |        ConnectionManager vtable slot (0x0064136C)
   conn->Send(w ? 4 : 0, buf, n + 2) -+->        DispatchReceivedMessage_guess 0x00424E57
     |  fails: log, ConnectionManager                    |
     |         ::CloseConnection_guess(&conn)           v
     v                                         pEverQuest->HandleWorldMessage_guess(conn, op, p, n)  0x0045B8F0
   returns 1 on success                                  |  two switches: 439 case labels
                                                         +--> Handle_OP_*_guess (tu_042_EQHandleMsg, mostly)
                                                         +--> sub-dispatchers (guild, task, tribute, ...)
```

## Opening a connection (tu_017_ConnectionManager)
`ConnectionManager_guess` derives from two bases (`ConnectionBase_guess` at +0, vtable 0x00641358, holding a
critical section at +0x28; `ClosureBase_guess` at +0x48). Its constructor (0x0042507B) sets the timeout to
180,000 ms.

| VA | name | what it does |
|---|---|---|
| 0x00424C15 | `Start_guess` | once: reads `[Networking] PortBase`/`PortRange` from eqclient.ini, fills the library config (buffer sizes 0x20000, timeouts), opens the local port and logs it |
| 0x00424F2E | `Connect_guess(host, port, flags)` | `Start_guess`, then asks the library for a connection; drops it if its state is 2 (disconnected) at once; counts and logs the new connection |
| 0x00424FB5 | `WaitForDisconnect_guess(conn, ms)` | polls every 50 ms until the connection is gone or in state 2; 1 = it dropped, 0 = timed out |
| 0x0042500C | `CloseConnection_guess(&conn)` | sets state 0, waits up to 100 x 100 ms for pending bytes, flushes, releases, clears the caller's pointer, logs the pending count |
| 0x00424E57 | `DispatchReceivedMessage_guess` (receive callback) | `__stdcall (id, data, len)`: if `id` is the current connection, calls the dispatcher with `*(u16*)data`, `data + 2`, `len - 2` |
| 0x00424E86 | `OnConnectionTerminated_guess` (close callback) | marks the owner closed and logs the termination with both status codes |

Callers of `Connect_guess`: `AuthenticateWorld_guess` (0x004B649F, world login) and `ConnectToHost_guess`
(0x004B611D, zone server). Both are in tu_073_login (the older client's `login.cpp` holds the same code).

## Sending (EQSendMessage, 0x004912B1)
```cpp
char __cdecl EQSendMessage(Connection** conn, int opcode, void* data, int size, char wait);
```
- A null `conn` or `*conn` logs the opcode as sent on a void connection and returns 0. With
  flag 0x00923798 set it returns 0 without logging instead. 0x00923798 and 0x00923884 together
  are the "no server" mode that `ExecuteCmd` (0x004619CD), `DoPassageOfTime_guess` (0x00422198), `CastSpell`
  (0x00411F3D) and `ProcessGame_guess` (0x004ACF33) all test. Nothing in the rewritten code sets either flag.
- Otherwise 0x006007F0 builds the wire buffer (opcode then payload; the `size + 2` length shows the 2-byte
  opcode) and the connection's `Send` (0x005E6EC0) gets flag 4 when `wait` is set.
- A failed send logs the status, then tears the connection down through the manager, which also nulls `*conn`.

About 480 call sites use it (export callgraph). `EQSendMessage` is the name in `core_decls.h`; the definition in tu_062_EverQuest is named
`FUN_004912b1_guess`. Both are 0x004912B1. A few TUs still declare it under a local name (for example `SendLogin_guess` and `SendPair_guess` in
tu_073_login); the VA is the same.

## The dispatcher (0x0045B8F0)
`HandleWorldMessage_guess` is a `CEverQuest` member (`this` is `pEverQuest`, 0x00988DF0). It is one function of
24,194 bytes with two `switch` statements in a row: 439 case labels in 331 groups. The second switch runs
only when CDisplay reports the world as loaded (0x0043745D). There is no default case: an unknown opcode is
ignored. In the source it is `EverQuestB8F0_guess::HandleWorldMessage_guess`; the class view keeps its
placeholder name. State `rewritten`, match `structural` (an early stop: the body is complete, the layout of the
jump tables is not). It returns 1, or 0 when a zone-entry message fails to parse.

What a case does falls into four shapes:
1. Call one handler with the payload: `case OP_NewSpawn: Handle_OP_NewSpawn_guess(data)` (OP_NewSpawn is 0x1860). Most handlers live just
   before the dispatcher in tu_042_EQHandleMsg (0x00451ABA `Handle_OP_ClientUpdate_guess` to 0x0045B86D
   `Handle_OP_SendAATable_guess`), each named from the case it serves.
2. Inline code for short messages (OP_Buff (0x6A53): one path copies a 0x14-byte buff record into the character).
3. Forward to a window or manager: `pinst...->Method(data)`, then a refresh (`V084_guess`).
4. Forward to a second dispatcher that switches again: adventure 0x004089B2 `OnEvent_guess` (tu_008_AdventureManager),
   guild 0x0040B8CB `HandleMessage_guess` (tu_010_guilds), tasks 0x00433887 `TaskManagerView_guess::HandleTaskMessage_guess` (tu_026_TaskManager), tribute 0x00434D9A `HandleTributeMessage_guess` and guild tribute 0x00435163 `MessageRouter_guess::HandleGuildTributeMessage_guess` (tu_027_Tribute), dynamic
   zones 0x00447364 `Dispatch_guess` (tu_031_Expedition).

Before the game the world connection's messages go to `WorldAuthenticate_guess::WorldAuthenticate` (0x004B624F,
tu_073_login) instead: OP_LogServer (0x0FA6), OP_ApproveWorld (0x3C25), OP_SendCharInfo (0x4513), OP_EnterWorld (0x7CBA), OP_PostEnterWorld (0x52A4), OP_WorldLoginFailed (0x8DA7), OP_WorldChecksumFailure (0x7D37) and a few more.

## World login and zoning (message order)
Taken from the log strings in the code (`Zone Connect -- N --`):

| step | where | message |
|---|---|---|
| world login | `AuthenticateWorld_guess` 0x004B649F | connect to the host at 0x00904104; send OP_SendLoginInfo (0x4DD0, 0x1D0 bytes: account, password) or, with a key code of 25+ characters, 0x34C7 (no EQEmu name; 0x184 bytes: account, password, key code) |
| 0 | dispatcher, case OP_ZoneServerInfo (0x61B6) | receive host (0x80 bytes) + port; send OP_WorldComplete (0x509D); wait up to 30 s for the world to drop; `ConnectToHost_guess` to the zone |
| 2 | `GetZoneInfoFromNetwork` 0x004A8193 | send OP_ZoneEntry (0x7213, 0x44 bytes: the character name and a hash of it) |
| 3 | case OP_PlayerProfile (0x75DF) | `Handle_OP_PlayerProfile_guess` 0x004BA899 (an `EQ_PC` method, tu_079_PlayerProfile) checks the size (0x4C88) and checksum and loads the profile; a corrupt profile disconnects |
| 4 | case OP_ZoneEntry (0x7213) | the server's copy of our spawn: 0x00457F32 (`Handle_OP_ZoneEntry_guess`) |
| then | `EnterZone` 0x004A861D | send OP_ReqNewZone (0x7AC5); the server answers with OP_NewZone (0x0920) |
| then | `DoMainLoop` 0x004ABA14 | send OP_ReqClientSpawn (0x0322) and wait for the ready flag |
| then | `DoMainLoop` | send OP_SendExpZonein (0x0587, logged as MSG_READY_ENTER_WORLD) and wait for the same opcode back (dispatcher case OP_SendExpZonein sets 0x00923788) |
| then | `DoMainLoop` | send OP_ClientReady (0x5E20); the frame loop starts (state 5 was set before OP_ReqClientSpawn) |

The client's own message names survive only in its log strings (dispatcher 0x0045B8F0); the code and
comments use EQEmu's names:

| opcode (EQEmu name) | client log text |
|---|---|
| OP_ZoneServerInfo (0x61B6) | MSG_ZONE_ADDRESS |
| OP_PlayerProfile (0x75DF) | MSG_SEND_PC |
| OP_ZoneEntry (0x7213) | MSG_EQ_ADDPLAYER |
| OP_ZoneSpawns (0x2E78) | MSG_EQ_NETPLAYERBUFF |
| OP_TimeOfDay (0x1580) | MSG_TIME_STAMP |
| OP_Weather (0x254D) | MSG_WEATHER_EVENT |
| OP_SendExpZonein (0x0587) | MSG_READY_ENTER_WORLD |
| OP_RequestClientZoneChange (0x7834) | MSG_TELEPORT_PC |
| 0x0F66 (no EQEmu name) | MSG_LOGOUT_PLAYER |

The world login in tu_073_login also logs MSG_LOGIN and MSG_LOGIN_KEYCODE.

## Opcodes
`include/titanium/opcodes.h` (`enum TitaniumOpcode`) holds the 383 opcodes the code sends, switches on or
compares that have one unique EQEmu name (names and values from `patch_Titanium.conf`). The code uses these
names in `EQSendMessage` arguments, `case` labels and compares: 259 of the dispatcher's 439 labels. The dispatcher's
`// OP_X` comments that only repeated the label were dropped; a literal label keeps a trailing comment with the
EQEmu candidates when there are several. Values with no unique name stay numbers, and so do a few common
messages EQEmu does name (OP_ZoneChange 0x5DD8, OP_ReqNewZone 0x7AC5, OP_ReqClientSpawn 0x0322,
OP_RaidJoin / OP_RaidUpdate 0x1F21); these pages give the EQEmu name with the value. A handler for a value
EQEmu does not name is named from what it does (`Handle_SenseTrapsReply_guess`).

EQEmu also names two values that the code keeps as numbers: 0x6A1B is OP_FloatListThing (sent from 0x0048C1A3 `State_48C_guess::SendMovementHistory_guess`, the movement-history send) and 0x729C
OP_AnnoyingZoneUnknown (tu_222_TaskTemplateSelectWnd); both are EQEmu placeholder names. Values with no EQEmu name at all: 0x7E61
(an evolving-item message of 0x18 bytes, sent from 0x0051DE5D `MessageSender_guess::RequestEvolvingFinalResult_guess`, 0x0042419C `RequestEvolvingItemToggle_guess` and 0x0052254F `CItemExpTransferWnd_guess::UpdateItems_guess`), 0x011D (the respawn
window, dispatcher 0x0045B8F0), 0x4672 (sent only by `HitBySpell` 0x00414913, SPA 72 PreserveCorpse branch),
0x0F66 (logout), the petition set 0x10A6, 0x017F, 0x193C, 0x3CB4, 0x42EB, 0x04B0, 0x588B, 0x72B0 (0x00544157
`WndNotification_guess`)
and the task-template set 0x4EDB, 0x64D7, 0x67C6, 0x7135 (0x0055CE86 `ShowAbilityInfo_guess` and neighbours).

Rules when naming one:
- The value comes from the code (a `case` label or an `EQSendMessage` argument); the name from EQEmu. Add a
  new name to `opcodes.h` and use it in the code only when EQEmu has exactly one name for the value.
- One value can serve two EQEmu names (`Handle_OP_ConsentResponse_guess` 0x004533B6 handles both ConsentResponse
  and DenyResponse; `Handle_OP_Trader_guess` 0x00453571 both Trader and BazaarSearch). Name the handler after the
  case it was found under, note the other.
- `PlaceReceivedItem_guess` (0x0045A817) is not the ItemPacket handler, although it is called from that case: the
  case first parses the item with 0x004B232E. See [items_inventory.md](items_inventory.md).

## Other connections
The chat server address arrives in OP_SetChatServer (0x00D7, `Handle_OP_SetChatServer_guess` 0x00454942), which
parses its fields with tu_010_guilds helpers and calls `ConnectChatServer_guess` (0x00495720). That stores the host, port
and name and creates the chat-server API object (reference name `ChannelServerApi`, code in tu_010_guilds) at `CEverQuest`
+0x290; `ChatServerGiveTime_guess` (0x004A2FD7) services it. `Handle_OP_SetChatServer2_guess` (0x00454A0C) does the
same for the mail ("Universal Chat") server through `ConnectMailServer_guess` (0x00495972), API at +0x834. Both
API objects are held by `CEverQuest`, not in the world/zone connection pointer at 0x00905CA0; how they reach the
network was not traced.
