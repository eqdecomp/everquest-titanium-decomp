# Networking and packet dispatch

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) sections 6-7 | [Long page](../network.md)

One connection is live at a time, first to the world server and then to a zone server. Game code opens and
closes it through the connection manager, sends with `EQSendMessage`, and receives every message in one
large opcode switch on CEverQuest. The connection library itself is not rewritten.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_017_ConnectionManager.cpp` | `ConnectionManager_guess`, `ClosureOwner_guess`, receive and close callbacks | open, wait, close; hands received bytes to the dispatcher |
| `tu_062_EverQuest.cpp` | `EQSendMessage` (defined as `FUN_004912b1_guess`) | the send path |
| `tu_073_login.cpp` | `WorldAuthenticate_guess`, `AuthenticateWorld_guess`, `ConnectToHost_guess` | world login and the zone connect |
| `tu_042_EQHandleMsg.cpp` | `EverQuestB8F0_guess` (this is CEverQuest) | `HandleWorldMessage_guess`, the dispatcher, and most `Handle_OP_*_guess` handlers |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x00424F2E | `ConnectionManager_guess::Connect_guess(host, port, flags)` | starts the manager, asks the library for a connection, drops it if it is already in state 2, logs "Networking: Connection Established [n]" |
| 0x0042500C | `ClosureOwner_guess::CloseConnection_guess(&conn)` | state 0, waits up to 100 x 100 ms for pending bytes, flushes, releases, clears the caller's pointer |
| 0x00424E57 | `DispatchReceivedMessage_guess(id, data, len)` | receive callback: for the current connection id, calls the dispatcher with `*(u16*)data`, `data + 2`, `len - 2` |
| 0x004912B1 | `EQSendMessage(&conn, opcode, data, size, wait)` | prefixes the opcode (0x006007F0) and sends `size + 2` bytes (flag 4 when `wait`); on failure logs the connection status and tears the connection down; a null connection logs a void-connection message unless 0x00923798 is set |
| 0x004B649F | `AuthenticateWorld_guess` | connects to the world host (60 s), sends the login record (OP_SendLoginInfo 0x4DD0, 0x1D0 bytes) or the key-code record (0x34C7, no EQEmu name, 0x184 bytes), then waits for the world's answer |
| 0x004B624F | `WorldAuthenticate_guess::WorldAuthenticate(id, msg, size)` | the world-login message switch, used before a character is in the world |
| 0x004B611D | `ConnectToHost_guess(request)` | zone connect: 60 s connect, polls every 100 ms until the library reports a result |
| 0x0045B8F0 | `EverQuestB8F0_guess::HandleWorldMessage_guess(conn, opcode, data, size)` | the dispatcher (below) |

## Data flow

```
send:     caller -> EQSendMessage 0x004912B1 -> [opcode:2][payload] -> connection->Send
receive:  library -> DispatchReceivedMessage_guess 0x00424E57
                  -> HandleWorldMessage_guess 0x0045B8F0
                       switch 1: every message
                       switch 2: only when CDisplay_guess::GetValue2cf8_guess (0x0043745D) is non-zero
                  -> Handle_OP_*_guess, or a manager's own switch
```

The dispatcher has 439 case labels, 276 of them in the first switch. There is no `default`: an unknown
opcode is ignored. It returns 1, or 0 when `Handle_OP_ZoneEntry_guess` fails on OP_ZoneEntry (0x7213).

Families forwarded to a manager, with the switch they sit in:

| Manager (global) | Method | Switch |
|---|---|---|
| tasks (0x0079DC78) | 0x00433887 `TaskManagerView_guess::HandleTaskMessage_guess` | 1 and 2 |
| tribute (0x00850350) | 0x00434D9A `TributeTable_guess::HandleTributeMessage_guess` | 1 |
| guild tribute (0x00850350) | 0x00435163 `MessageRouter_guess::HandleGuildTributeMessage_guess` | 1 |
| expeditions (0x009231C8) | 0x00447364 `Expedition_guess::Dispatch_guess` | 2 |
| guild (0x00905D38) | 0x0040B8CB `GuildManagement_guess::HandleMessage_guess` | 2 |
| adventures (0x009232F0) | 0x004089B2 `AdventureManager_guess::OnEvent_guess` | 2 |

World login messages handled by 0x004B624F: OP_LogServer (0x0FA6, world address, port, server name and
six flags), OP_ApproveWorld (0x3C25), OP_SendCharInfo (0x4513), OP_PostEnterWorld (0x52A4, access granted),
OP_CharacterStillInZone (0x60FA), OP_GuildsList (0x6957), OP_ExpansionInfo (0x04EC), OP_EnterWorld (0x7CBA, an
error text), OP_WorldChecksumFailure (0x7D37, log only), OP_WorldLoginFailed (0x8DA7, "Invalid Login or
Password"), 0x0504 (petition queue). Anything else logs "UNKNOWN MESSAGE".

Zone-in markers in the dispatcher: OP_PlayerProfile (0x75DF) logs "Zone Connect -- 3 -- Received
MSG_SEND_PC" and calls 0x004BA899 `Handle_OP_PlayerProfile_guess`; OP_ZoneEntry (0x7213) logs "Zone Connect
-- 4 -- Received MSG_EQ_ADDPLAYER".

## Key globals

| Address | What |
|---|---|
| 0x00905CA0 | the live connection; senders pass its address so a failed send can clear it |
| 0x0079DBD8 | the connection manager |
| 0x00923798 | offline flag: silences the void-connection log in `EQSendMessage` |
| 0x00988DF0 | `pEverQuest`, the object the dispatcher runs on |

## Known client bugs

- [X01](../KNOWN_CLIENT_BUGS.md#server-data-used-without-checks): 0x0045B8F0 case 0x4BB4 raises the header
  count to what fits in the packet but never lowers it, so a large count is read past the end.
- [B73](../KNOWN_CLIENT_BUGS.md#server-data-used-without-checks): case OP_CustomTitles (0x2A28, switch 2)
  passes the packet to 0x00554E7A `CSkillsWndTitlesView_guess::Run_guess`, which uses each server string as a `sprintf` format into a 0x400-byte
  buffer.
