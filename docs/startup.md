# Startup and the main loop

[Overview](ARCHITECTURE.md) sections 4-5 | [Source guide](README.md)

`eqgame.exe` starts in `WinMain`, hands the login and server select to eqmain.dll, then builds one
`CEverQuest` object and runs the game until the player leaves the world. Leaving can return to the front end
(server select) without restarting the process.

Files: `tu_097_Win` holds WinMain, the window procedure and input setup; `tu_062_EverQuest`
holds `CEverQuest`'s constructor, login and main loop.

## Call outline

```
WinMain_guess                         0x004CFD32  tu_097_Win
 |- CheckCriticalFiles_guess          0x004CED8F  critical files, args, WinSock, window class, CreateWindowExA
 |- graphics DLL loader               0x00609680  (0x005E0000-0x0060CFFF band, not rewritten; rendering.md)
 `- loop:
     |- RunFrontend_guess             0x004CE2D6  load eqmain.dll, call its entry, unload it
     |   |- LoadEQMainDLL_guess       0x004CC7FD
     |   `- UnloadFrontendDll_guess   0x004CC889
     |- copy login fields from the eqmain block
     `- ExecuteEverQuest_guess        0x004CF93C
         |- DirectInput8Create, InitKeyboard_guess 0x004CD082, InitMouse_guess 0x004CE5C4
         |- new CEverQuest            ctor 0x004A3341  -> pEverQuest (0x00988DF0)
         |- CEverQuest::DoLogin_guess 0x0049377D  connect to world, load spells/racedata, init display
         |- GuardedShutdown_guess     0x004CDD75  __try { RunGameAndShutdown_guess }
         |   `- RunGameAndShutdown_guess 0x004CDD09
         |       |- CEverQuest::ProcessGame_guess  0x004ACF33  the whole session
         |       |   `- CEverQuest::DoMainLoop      0x004ABA14
         |       `- delete pEverQuest, DeleteCriticalSection x3
         `- release mouse, keyboard, DirectInput
```

## WinMain_guess (0x004CFD32)
In order, from the code:
1. Opens the debug log (Logs\dbg.txt) and logs the start with the build date and the time zone.
2. A command line containing the string at 0x0064DA6C makes it write a checksum file and exit
   (`WriteChecksumFile_guess` 0x004CE382).
3. Creates the graphics object (0x0099E38C) and loads the graphics DLL named by `[Defaults] GraphicsDLL9` in
   eqclient.ini (default EQGraphicsDX9.DLL). If a configured DLL fails, it retries with the default; if that
   fails too: message box, `exit(-0x2A)`. With no DLL configured, a failed load of the default is not tested.
4. Calibrates timers from the DLL's `EQG_GetCpuSpeed2/3` exports: it stores the
   rdtsc base at 0x00988C60 (`CyclesSinceStart_guess` 0x004CC98F returns the cycles since then, with an
   `rdtsc` asm block marked `// as original`), and `EqGetTime` (0x0046D655) later returns milliseconds since that moment. One
   piece of code compares that clock with `GetTickCount` (0x004B6F1F `BuildMessage_guess`, see
   [KNOWN_CLIENT_BUGS.md](KNOWN_CLIENT_BUGS.md) B42). It then clears 0x6215C bytes at 0x00923770 (the
   start of the game's global state block), calls `CheckCriticalFiles_guess`, then `CoInitialize`.
5. Loops: `RunFrontend_guess`, then `ExecuteEverQuest_guess`. It leaves the loop when `RunFrontend_guess` returns
   -1, or when the quit flag 0x00905D28 is 1 after a game pass. Its tests for a 0 return are dead: RunFrontend
   returns only -1 or 1.

`CheckCriticalFiles_guess` (0x004CED8F) is named after its first log line (checking critical files), but it
does the whole pre-init: it checks the patch files, parses the arguments (`patchme`, `/ticket:`, `tutorial`),
honours nosound.txt/noreverb.txt, starts WinSock, loads the keyboard tables (`LoadKeyboardTables_guess`
0x004CC8AF reads Keyboard.txt), registers `_EverQuestwndclass` and creates the main window (handle at
0x00988C24). The window procedure is `eqWndProc` (0x004CE798).

## The eqmain hand-off
`LoadEQMainDLL_guess` (0x004CC7FD) loads eqmain.dll and looks up `new_dll_main`, falling back to `dll_main`.
`RunFrontend_guess` calls whichever it found with the module and a 0x9C0-byte block at 0x00986FC0
(`new_dll_main` also gets the size). `RunFrontend_guess` reduces the entry's return to -1 or 1:

| entry returns | RunFrontend returns, and WinMain then |
|---|---|
| -1 | -1: leaves its loop |
| -2 | 1, after a message box saying eqmain.dll could not be initialised: copies the block and enters the game |
| other (0 included) | 1: copies the fields below and enters the game |

eqmain writes the player's choice into that block; WinMain copies it to the login globals that
`AuthenticateWorld_guess` (tu_073_login) reads. Offsets are into the 0x00986FC0 block; the field meanings are
inferred from how tu_073_login uses the destinations.

| block offset | copied to | used as |
|---|---|---|
| +0x40C | 0x00904004 | account name (cleared if it is the literal `login`) |
| +0x48C | 0x00904084 | password (cleared if it is the literal `password`) |
| +0x58C | 0x00904104 | world server host |
| +0x60C | 0x00904184 | key code; cleared if shorter than 25 characters |
| +0x9BC | delay | seconds to wait before logging in, if positive |

If both account and password are set, 0x00904208 is set to 1 (login ready). eqmain's own code is not part
of this tree.

## ExecuteEverQuest_guess (0x004CF93C)
Sets up DirectInput 8 (keyboard and mouse devices), copies command-line login arguments when the front end
did not supply any, sets the default resolution 640x480 (0x0092379C/0x009237A0) and three critical sections,
enumerates fonts, then:

```cpp
pEverQuest = new CEverQuest(hwnd);                             // 0x004A3341; size 0x3A1C8 (types.h)
if (pEverQuest->state == 0)
    result = pEverQuest->DoLogin_guess(mainWindow, hInstance);  // 0x0049377D
...
GuardedShutdown_guess();                                        // runs the game, then tears it down
```
If the constructor or a startup check leaves `state == 1`, the object is deleted, the world connection is
stopped and the function returns without running the game.

`CEverQuest::DoLogin_guess` (0x0049377D) connects to the world server through `AuthenticateWorld_guess`
(0x004B649F), keeps the connection in 0x00905CA0, loads spells_<lang>.txt into the spell table
(0x00985CC8, [spells.md](spells.md)) and racedata.txt, loads AnimationSounds.txt, shows the window and
calls `CDisplay::InitDisplay_guess` (0x00443F8F) and `CDisplay::InitWorld_guess` (0x0043DF32, Mac
`CDisplay::InitWorld`). It returns -1 on every path that reaches the end.

### Naming traps
`GuardedShutdown_guess` does more than shut down: it runs `RunGameAndShutdown_guess` (0x004CDD09), which first
calls `CEverQuest::ProcessGame_guess` (0x004ACF33) when `pEverQuest->state == 0`,
which runs the whole session, and only then deletes `pEverQuest`. `GuardedShutdown_guess` wraps it in
`__try/__except` after filling a 0x1000-byte buffer with 0xCE and clearing a 0x7E48-byte state block at
0x00989528 (the crash packet, below).
Read it as "run the game, then clean up". `CheckCriticalFiles_guess` (above) and
`CheckCharSelectDisconnect_guess` (below) are also narrower than their bodies.

### The crash handler
```cpp
__try {
    RunGameAndShutdown_guess();
} __except (BuildCrashReport_guess(GetExceptionInformation(), g_crashPacket_00989528_guess.report_guess,
                g_crashPacket_00989528_guess.faultAddress_guess),
    EXCEPTION_EXECUTE_HANDLER) {
    ... version, skin, graphics DLL, player, location and system lines; offer to send; exit ...
}
```
In the original the scope table at 0x0064D260 has one entry: the filter 0x004CDE2A calls
`BuildCrashReport_guess` (0x004CD620) with the exception information and two fields of the crash packet,
then returns 1 (`EXCEPTION_EXECUTE_HANDLER`); the handler 0x004CDE43-0x004CE2D5 (about 1.2 KB, no function of
its own) builds the rest of the report with `sprintf`, adds the version strings and exits. The original
function runs from 0x004CDD75 to 0x004CE2D6, where `RunFrontend_guess` starts; the CRT's `_except_handler3`
(0x00612944) runs the scope table. The rewrite is identical, filter and handler included: the compare follows
the scope table and treats both blocks as part of 0x004CDD75.

Read the filter as "write the crash report, then handle the exception". The 0x7E48-byte block at 0x00989528
is the crash packet the handler offers to send (`CrashPacket_guess`: player name +0x46, zone +0x86, fault
address +0xC6, graphics DLL +0x106, report text +0x146). The fixture harness cannot raise the exception, so
the handler is checked by the byte compare only.

## CEverQuest::ProcessGame_guess and DoMainLoop
`ProcessGame_guess` (0x004ACF33, 5,481 bytes, tu_062_EverQuest, state `rewritten`, structural) runs the whole session.
In the source it is a method of the view `GlobalState_guess`. Its loop (each step also writes a log line):

```
state 0
while state != 0xFF:
    no character chosen:  authenticate to world if needed, run character select
                          (DoCharacterSelection_guess 0x004A9EBF, StartNetworkGame 0x004AA92B)
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
        leave code (0x00923794) 0xFD or 0xFE: break
    leave code 0xFE: send opcode 0x0F66 (logout), back to character select
    leave code 0xFD: state 0xFF, return
```
`StartNetworkGame` (0x004AA92B) allocates the `EQ_PC`; zoning is in [world.md](world.md).

`DoMainLoop` (0x004ABA14, tu_062_EverQuest) sets game state 7 while it creates the initial actors (`CreateInitialActors_guess`
0x00496B5A), restores the previous state, sets state 5, sends OP_ReqClientSpawn (0x0322) and waits for the ready flag, sends OP_SendExpZonein (0x0587,
logged as MSG_READY_ENTER_WORLD) and waits for the same opcode back (0x00923788), sends
OP_ClientReady (0x5E20), then runs one frame per pass while the game state is 5:

```
while (state == 5):
    time stamp (0x0046D655 EqGetTime)
    CEverQuest::ProcessMBox_guess 0x004A56B1
    CheckCharSelectDisconnect_guess 0x00496932; on loss: wait 16 s, save position, send OP_DeleteSpawn (0x55BC), return
    ProcessGameEvents 0x004A9C84            mouse events, Windows message pump (PumpMessages_guess), keyboard
    EQWorldData::AdvanceTime 0x005F6740
    ... movement, lights, sound, target, keyboard state ...
    CXWndManager (0x0099D3EC): HandleMouseMove 0x005AF6A0, ProcessFrame 0x005B06A0,
                               DrawWindows 0x005AF250, DrawCursor 0x005AF580
    CEverQuest::ProcessControls_guess 0x004A1D74  (only when the window is active)
    CDisplay::Render_World_guess 0x00445A6C  (skipped for the first 30 frames)
    sleep for the rest of the frame time
```
`CheckCharSelectDisconnect_guess` takes its name from its log text, which mentions character select, but
character select, `DoMainLoop` and other loops all call it: it is the general lost-connection check. After it reports a loss
the frame loop waits 16 s before it gives up.
When the state leaves 5 (camp, zone, link loss), `DoMainLoop` returns to `ProcessGame_guess`, which zones or
returns to character select; when `ProcessGame_guess` returns, control goes back to `WinMain`'s loop.

`CEverQuest::SetGameState` (0x00494B3D) stores the state and, for 1, 2 and 5, enables or disables groups of
key commands (ids 0x101, 0xB9, 0x105-0x10A) through tu_044_ExecuteCmd. The states, from the code that sets them:

| state | meaning | set by |
|---|---|---|
| 0 | session start | `ProcessGame_guess` 0x004ACF33 on entry |
| 1 | character select | `DoCharacterSelection_guess` 0x004A9EBF, `StartNetworkGame` 0x004AA92B |
| 2 | the character-creation screen loop | 0x004A9CD2 (named `RunCharacterSelectLoop_guess`; it runs the creation screen) |
| 3 | OP_EnterWorld sent, waiting for the zone address | `ProcessGame_guess` |
| 7 | entering a zone | `DoMainLoop` on entry |
| 5 | in the zone: the frame loop runs | `DoMainLoop`, `ProcessGame_guess` |
| 0xFD | the zone address arrived during the first wait | `ProcessGame_guess` |
| 0xFF | leave the session | error paths and the normal exit |

The class view in tu_062_EverQuest also has an inline copy with the same body, `SetGameStateInline_guess`.

## Input
DirectInput devices live at 0x00988C7C (DirectInput), 0x00988C80 (keyboard), 0x00988C84 (mouse).
`FlushKeyboard_guess` (0x004CCB85), `ProcessKeyboardEvents_guess` (0x004CECC7), `ProcessMouseEvents_guess`
(0x004CCE44) and `HandleKeyDown_guess`/`HandleKeyUp_guess` (0x004CE4AC/0x004CCBFC) read the buffered device
data; `eqWndProc` passes messages to the IME manager first (0x0099D3F8).
