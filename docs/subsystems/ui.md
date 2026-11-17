# UI: SIDL windows

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 14 | [Long page](../ui.md)

The game's windows are `CSidlScreenWnd` subclasses built from the XML screens of the current UI skin. The
window library (CXWnd, CSidlScreenWnd, the controls, the XML loader) is not rewritten; the game side is
CDisplay's UI life cycle plus about 115 window classes, mostly one per file.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_029_Display.cpp` | `CDisplay_guess` | loads the skin and XML, creates, deactivates and deletes the windows |
| `tu_099_ActionsWnd.cpp` .. `tu_236_VideoModesWnd.cpp` | mostly one window class per file, alphabetical | constructors, `WndNotification`, `OnProcessFrame` |
| `tu_153_EQWndManager.cpp` | `CEQMainWnd_guess` | the EQ button and its menu |
| `tu_217_UiHelpers.cpp`, `tu_210_SidlControlFactory.cpp` | small shared helpers | |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x00442D80 | `CDisplay_guess::InitNewUI_guess` | reads `UISkin` / `AtlasSkin` (from eqclient.ini before a character is loaded, else from the character's UI ini); loads EQUI_GUIDE.xml for a GM when it exists, else EQUI.xml, from `UIFiles\<skin>\`; on an XML error retries once with the default skin; a second failure shows an error box pointing to UIErrors.txt and exits; finally loads the textures |
| 0x0043EE74 | `CDisplay_guess::InitCharSelectUI_guess` | runs `CleanGameUI`, then creates the character-creation, character-select, face-pick and system-info windows |
| 0x0043EFDD | `CDisplay_guess::InitGameUI_guess` | creates every game window that is not there yet and stores it in its own global (the mail windows only when mail is enabled) |
| 0x0043AF46 | `CDisplay_guess::CleanGameUI` | deletes or releases the window globals |
| 0x00437BCD | `CDisplay_guess::DeactivateMainUI_guess` | deactivates the game windows without clearing their globals |
| 0x00443DBC | `CDisplay_guess::ReloadUI(value)` | deactivate, reset, `InitNewUI_guess`, then the character-select or game windows (character select when the owner's state field +0xB54 is 2), activate, reload fonts |
| 0x00516E9A | `CInventoryWndView_guess` constructor | a typical window: base constructor with `"InventoryWindow"`, `CreateChildrenFromSidl`, then `GetChildItem("InvSlot%d")` for 30 slots and the other named controls |
| 0x004FFDB4 | `CEQMainWnd_guess::WndNotification_guess` | message 1 on the EQ button opens or closes the menu; anything else goes to the base |

## Data flow

```
InitNewUI_guess 0x00442D80        skin path, EQUI.xml -> window library (screens, templates)
InitGameUI_guess 0x0043EFDD       new <Window>(parent)  -> global per window
   window ctor                    CreateChildrenFromSidl, GetChildItem("<XML name>") per control
each frame                        window manager -> OnProcessFrame_guess / Draw
on input                          window manager -> WndNotification_guess(sender, message, data)
   handler                        reads pCharData / spawns, calls ExecuteCmd or EQSendMessage directly
ReloadUI 0x00443DBC               DeactivateMainUI_guess, reset, InitNewUI_guess, Init*UI_guess
```

## Key globals and structs

| Address | What |
|---|---|
| 0x0099D3EC | window manager (CXWndManager) |
| 0x00850B9C - 0x00850CC8, 0x009917xx - 0x009929xx | one global per game window, filled by 0x0043EFDD (0x00991B88 and 0x00991E44 are the item-display and confirmation-dialog managers) |
| 0x00850C6C | social-edit window |
| 0x00850CB8 | inventory slot manager (created in 0x0043EFDD) |
| 0x009928DC / 0x009928E0 | tip window, mode 0 (tip of the day) / mode 1 (context tips), both created in 0x0043EFDD |

The `CXWnd` base is 0x11C bytes and `CSidlScreenWnd` 0x15C; window-specific fields start after that
(the inventory window's controls sit at +0x17C and up).

## Known client bugs

All in [Windows](../KNOWN_CLIENT_BUGS.md#windows-tu_099-to-tu_234) unless noted:
B15 potion belt (0x00548B9D), B22 / B23 actions window (0x004D3C53 `CombatPageOnProcessFrame_guess`, 0x004D400B `CActionsWnd_guess::SocialsPageOnProcessFrame_guess`), B24 barter
(0x004E09DF), B25 spell gem draw (0x00558A3A), B45 guild management (0x0050E2D2 `UpdateButtons_guess`, in
[Guilds](../KNOWN_CLIENT_BUGS.md#guilds-tu_010_guilds-tu_166_guildmanagementwnd)), B52-B54 PvP leaderboard (0x0054B657), B58 link
control (0x004DA15B), B62 / B63 task window (0x0055E645, 0x0055F412 `CompareTimeLeft_guess`), B64 mail (0x0052DFBB `SyncWithAddressBook_guess`), B67 bazaar
(0x004E5907), B69 body tint (0x004E7BC7), B70 selector (0x00552387), B71 petition list (0x00544157), B72
tracking (0x00566CE6), B76 skills (0x00554C2D), B80 alarm (0x004D7EEF), B82 group search (0x00508955 `IsFilteredOut_guess`),
and B08 bag fade options (0x0053D0F5 `BagOptions_guess::WriteBagFadeSetting_guess`, in [Options](../KNOWN_CLIENT_BUGS.md#options-ini-and-local-files)).
