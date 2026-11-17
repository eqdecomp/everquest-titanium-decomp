# UI: windows, XML screens and the window files

[Overview](ARCHITECTURE.md) section 14 | [Source guide](README.md)

The UI is two layers. The window library (the original's `C:\EQ\Suite\Suite\`: `XWnd.cpp`,
`SidlScreenWnd.cpp`, `ButtonWnd.cpp`, `ComboWnd.cpp`) lives at 0x00571000 and up and is mostly not rewritten
(five pilots in `src/Suite/`). The game's windows (0x004xxxxx-0x0057xxxx) derive from it and are rewritten,
mostly one window class per file (some hold several), in `src/EverQuest/tu_099_ActionsWnd.cpp` to `tu_236_VideoModesWnd.cpp`. Game code calls the library through the
declarations in `include/titanium/core_decls.h`.

## Class hierarchy

```
CXWnd                      0x11C bytes      ctor 0x005A1290*, dtor 0x005A0940*
 |- CListWnd               list/table control          (+0x11C ItemsCount, +0x13C CurSel)
 |- CButtonWnd             button, check box           (+0x128 Checked)
 |- CStmlWnd               rich text (STML)            SetSTMLText 0x005A8B00
 |- ...                    edit, slider, gauge, label: library classes, not declared yet
 `- CSidlScreenWnd         0x15C bytes      a window built from an XML screen definition
      |- CConfirmationDialog   0x00547C3D   tu_198_ConfirmationDialog
      |- CInventoryWnd         0x00516E9A   tu_170_InventoryWnd
      |- CSpellBookWnd         0x00558521   tu_215_SpellBookWnd
      `- ... about 115 game windows (sizes of 50 pinned in include/titanium/types.h)
CXWndManager               global 0x0099D3EC   owns all windows: input, focus, drawing
CSidlManager*              loads the XML and finds screen-piece templates (LoadSidl* 0x005B60B0)
```

`CXWnd` fields used by game code (`core_decls.h`, MQ2 layout): `pParentWindow` +0x28, `pChildren` +0x2C,
`pSiblings` +0x30, `Location` +0x3C, `Show` +0x5C, `Enabled` +0x5D, `WindowStyle` +0x64, `Alpha` +0xB0.
`Enabled` and `CButtonWnd::Checked` are named from use: 0x005BB140 is the `Checked` setter
(`if (+0x128 != arg) +0x128 = arg`, called as SetCheck(i == selected) on the creation-screen radio buttons in
0x004EF129), and `Enabled` is written as `points != 0` on the creation-screen stat buttons. Virtual slot 48
(+0xC0) is `Show(bool, bool)`.
`CSidlScreenWnd` adds `SidlText` +0x11C, `SidlScreen` +0x120, `SidlPiece` +0x124 and the INI storage fields
+0x13C/+0x140.

### Library functions the game calls most
| VA | function |
|---|---|
| 0x005A3900 / 0x005A3850 | `CSidlScreenWnd(CXWnd* parent, const CXStr& screen)` / the 5-argument form |
| 0x005A3100 | `~CSidlScreenWnd` |
| 0x005A25B0 | `CSidlScreenWnd::CreateChildrenFromSidl()` |
| 0x005A1E10 | `CSidlScreenWnd::GetChildItem(name)`: a child control by its XML name |
| 0x005A2230 | `CSidlScreenWnd::WndNotification(sender, message, data)` (virtual) |
| 0x005A1890 / 0x005A2660 | `StoreIniInfo` / `LoadIniInfo`: window position in the character INI |
| 0x0059D960 / 0x0059FEC0 | `CXWnd::GetScreenRect` / `IsReallyVisible` |
| 0x005A8BF0 | `CXWnd::SetWindowTextA(const CXStr&)` |
| 0x0059B9D0 / 0x00597ED0 | `CListWnd::AddString` / `GetItemData` |
| 0x00548460 | `CConfirmationDialog` pool `Activate` (game code, tu_198_ConfirmationDialog): the yes/no prompt |

## How a window is built
Every game window follows the same constructor shape. `CConfirmationDialog` (0x00547C3D, tu_198_ConfirmationDialog), as in the
source:

```cpp
ConfirmationDialog_guess::ConfirmationDialog_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "ConfirmationDialogBox") {    // 0x005A3900: the screen name
    ...
    if (SidlPiece != 0) {                                    // the XML had this screen
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        yesButton_160 = ((CSidlScreenWnd*)this)->GetChildItem("Yes_Button");
        noButton_164  = ((CSidlScreenWnd*)this)->GetChildItem("No_Button");
        okButton_16c  = ((CSidlScreenWnd*)this)->GetChildItem("OK_Button");
        textOutput_15c = ((CSidlScreenWnd*)this)->GetChildItem("TextOutput");
        ...
    }
}
```
1. The base constructor gets the screen name. It must match a `<Screen item="...">` in the loaded XML.
2. `CreateChildrenFromSidl` creates the child controls the XML lists.
3. `GetChildItem("<name>")` fetches each control the class needs; the names are the XML item names, so a
   window's member fields are best named after them (`yesButton_160 // Yes_Button`).
4. The window overrides virtual slots, mostly `WndNotification` (clicks, list selection: the `message` is a
   notification code) and `OnProcessFrame` (per-frame update), sometimes `Draw`.

To rewrite a window constructor you need a polymorphic base with the real constructor and destructor
(0x005A3900 and 0x005A3100): `CSidlScreenWndBase` in `include/titanium/layouts/sidl_base.h`, or a local
class when the window needs more virtual slots; plus the window's vtable marker
(`// EXTERNAL: TITANIUM 0x0065AB70 ??_7ConfirmationDialog_guess@@6B@`). The header classes in `types.h`
have no virtual functions; use them for `sizeof` and field offsets. Details: `include/titanium/README.md`.

Window classes are named `C<Name>Wnd_guess` when the screen name, MQ2 or the link order attests the class.
Files that only use a window include its header, `include/titanium/wnd/<Class>.h` (104 of them): the class on
the shared slot base `CSidlScreenWndVirtuals_guess` (`include/titanium/wnd_views.h`), its constructor, the
methods other files call, and its global `pinst<Class>_guess`. The file that defines the window keeps its own
class; a partial view there is `C<Name>WndView_guess` or `C<Name>Wnd<Aspect>View_guess`. A constructor or
vtable family is renamed once, by VA, in every TU that declares it.

## Loading the XML (tu_029_Display)
`InitNewUI_guess` (0x00442D80), called from `InitDisplay_guess` (0x00443F8F) and `ReloadUI` (0x00443DBC):
1. `InitUIManager_guess` (0x0043AD1F) creates a resource object (0x0099D3F4, probably the `CSidlManager`), the
   window manager on top of it (0x0099D3EC), optionally the IME manager (0x0099D3F8, MQ2 `pinstImeManager`),
   and registers the fonts (`CXWndManager::AddFont`* 0x005B1680).
2. Reads the skin: `[Defaults] UISkin`/`AtlasSkin` in eqclient.ini before a character is loaded, else
   `[Main] UISkin`/`AtlasSkin` in the character's INI. The skin path is `UIFiles\<skin>\`, with the default
   skin folder as the fallback path.
3. Loads EQUI.xml (or EQUI_GUIDE.xml for a GM when that file exists in the default folder).
4. On an XML error: logs it, writes UIErrors.txt (inferred from the message box text), and retries once with
   the default skin; if that also fails, it destroys the main window and shows an error box that points to
   UIErrors.txt.

Then `InitCharSelectUI_guess` (0x0043EE74) or `InitGameUI_guess` (0x0043EFDD) creates the windows:

```cpp
if (pinstCSocialEditWnd_guess == 0)                          // one global per window (0x00850C6C)
    pinstCSocialEditWnd_guess = new CSocialEditWnd_guess(0);  // class and global from wnd/CSocialEditWnd.h
```
Each window lives in a global (most in 0x00850B9C-0x00850CC8 and 0x009917xx-0x009929xx; MQ2 calls them
`pinstC...Wnd`). Most windows are created through their `wnd/` header like this; the few without one use a
local class named `Wnd<ctor VA>_guess`, "the window whose constructor is at that VA" (find its file with
`grep "FUNCTION: TITANIUM 0x<VA>" src`). `CleanGameUI` (0x0043AF46) deletes them.

## Per frame
`DoMainLoop` (0x004ABA14) calls the manager at 0x0099D3EC each frame, each call under its own test (the mouse moved; the character is
loaded; 0x00850508 != 3 for the two draws; 0x00923842 == 0 for the mouse and the cursor): `HandleMouseMove`* (0x005AF6A0),
`ProcessFrame`* (0x005B06A0; by its name it runs each window's `OnProcessFrame`), `DrawWindows`* (0x005AF250) and
`DrawCursor`* (0x005AF580). Windows are drawn through the library's own font and texture code, which
reaches the graphics DLL ([rendering.md](rendering.md)).

## Window files
The window files and their names in the tree (the class that owns most of the file, without the leading `C`;
names that a class map confirmed are listed in the top comment). The files are in the original link order,
which is alphabetical by class from tu_099_ActionsWnd to tu_236_VideoModesWnd, so a doubtful name can be
checked against its neighbours. There are no files for objects 107-124.

```
tu_005_AudioTriggersWindow        tu_096_VoiceMacroWnd              tu_099_ActionsWnd
tu_100_AdvancedDisplayOptionsWnd  tu_101_AdventureLeaderboardWnd    tu_102_AdventureRequestWnd
tu_103_AdventureStatsWnd          tu_104_AlarmWnd                   tu_105_AltStorageWnd
tu_106_AtlasRender                tu_125_AvaZoneWnd                 tu_126_BandolierWnd
tu_127_BankWnd                    tu_128_BarterMerchantWnd          tu_129_BarterSearchWnd
tu_130_BarterWnd                  tu_131_BazaarSearchWnd            tu_132_BazaarWnd
tu_133_BodyTintWnd                tu_134_BookWnd                    tu_135_BreathWnd
tu_136_BuffWindow                 tu_137_BugReportWnd               tu_138_CascadeWnd
tu_139_CastingWnd                 tu_140_CastSpellWnd               tu_141_CharacterCreation
tu_142_CharacterSelect            tu_143_ChatManager                tu_144_ChatWindow
tu_145_ColorPickerWnd             tu_146_CombatAbilityWnd           tu_147_CompassWnd
tu_148_ContainerMgr               tu_149_ContainerWnd               tu_150_CursorAttachment
tu_151_DynamicZoneWnd             tu_152_EQMainWnd                  tu_153_EQWndManager
tu_154_ExploreModeWnd             tu_155_FacePick                   tu_156_FeedbackWnd
tu_157_FileSelectionWnd           tu_158_FindLocationWnd            tu_159_FriendsWnd
tu_160_GemsGameWnd                tu_161_GiveWnd                    tu_162_GroupSearchFiltersWnd
tu_163_GroupSearchWnd             tu_164_GroupWnd                   tu_165_GuildBankWnd
tu_166_GuildManagementWnd         tu_167_GuildTributeMasterWnd      tu_168_HotButtonWnd
tu_169_InspectWnd                 tu_170_InventoryWnd               tu_171_InvSlot
tu_172_InvSlotMgr                 tu_173_InvSlotWnd                 tu_174_ItemDisplayWnd
tu_175_ItemExpTransferWnd         tu_176_JournalCatWnd              tu_177_JournalNPCWnd
tu_178_LargeDialogWnd             tu_179_LeadershipWindow           tu_180_LFGuildWnd
tu_181_LoadskinWnd                tu_182_LootWnd                    tu_183_MailAddressBookWnd
tu_184_MailCompositionWnd         tu_185_MailWnd                    tu_186_MapToolbarWnd
tu_187_MapViewWnd                 tu_188_MerchantWnd                tu_189_MIZoneSelectWnd
tu_190_MusicPlayerWnd             tu_191_NoteWnd                    tu_192_OptionsWnd
tu_193_PetInfoWnd                 tu_194_PetitionQWnd               tu_195_PlayerNotesWnd
tu_196_PlayerWnd                  tu_197_PointMerchantWnd           tu_198_ConfirmationDialog
tu_199_PotionBeltWnd              tu_200_ProgressionSelectionWnd    tu_201_PvpLeaderboardWnd
tu_202_PvPStatsWnd                tu_203_QuantityWnd                tu_204_RaidOptionsWnd
tu_205_RaidWnd                    tu_206_RespawnWnd                 tu_207_SelectorWnd
tu_208_ServerListWnd              tu_209_LargeDialogWindow          tu_210_SidlControlFactory
tu_211_SkillsSelectWnd            tu_212_SkillsWnd                  tu_213_SocialEditWnd
tu_214_SoulmarkWnd                tu_215_SpellBookWnd               tu_216_SpellGemWnd
tu_217_UiHelpers                  tu_218_SystemInfoDialogBox        tu_219_TargetOfTargetWnd
tu_220_TargetWnd                  tu_221_TaskSelectWnd              tu_222_TaskTemplateSelectWnd
tu_223_TaskWnd                    tu_224_TextEntryWnd               tu_225_TicketCommentWnd
tu_226_TicketWindow               tu_227_TimerWnd                   tu_228_TipWnd
tu_229_TitleWnd                   tu_230_TrackingWnd                tu_231_TradeskillWnd
tu_232_TradeWnd                   tu_233_TrainWnd                   tu_234_TributeBenefitWnd
tu_235_TributeMasterWnd           tu_236_VideoModesWnd
```
Not windows, although they sit among them: tu_217_UiHelpers (free helper functions: ShellExecute, target
colours, timers), tu_210_SidlControlFactory, tu_153_EQWndManager (the tail of the `CEQMainWnd` listener, vtable
0x00653C60, and the `EQWndManager` constructor). tu_143_ChatManager, tu_148_ContainerMgr, tu_171_InvSlot,
tu_172_InvSlotMgr and tu_150_CursorAttachment manage or serve windows rather than being one. The UI startup
code (`InitNewUI_guess` and friends) is not in a window file: it is `CDisplay` code in tu_029_Display.

Files that hold more than one class, or whose names mislead:

| file | what it holds | trap |
|---|---|---|
| tu_184_MailCompositionWnd | `CMailCompositionWnd_guess` (constructor 0x0052D28D) and methods of `CMailAddressBookWnd_guess` (constructor 0x0052BB96 is in tu_183) | |
| tu_212_SkillsWnd | views of `CSkillsSelectWnd` and `CSkillsWnd` | |
| tu_213_SocialEditWnd | `CSocialEditWnd_guess` (constructor 0x00555363) and the end of `CSkillsWnd` | |
| tu_207_SelectorWnd | `CSelectorWnd_guess` (constructor 0x0055279D, screen "SelectorWindow", vtables 0x0065C518 / 0x0065C638) | the view `CRespawnWndView_guess` is the selector: its 0x005530F5 `AboutToHide_guess` is the `CSelectorWnd` AboutToHide override (slot 50), which removes the window's second base (+0x15C) from the mail manager's list (0x00518B72; the manager is what `GetMailManager_guess` 0x00495250 returns) |
| tu_195_PlayerNotesWnd | first `CPetitionQWnd` methods (vtable 0x0065A468: 0x0054403B `CPetitionQWndView_guess::AboutToShow_guess`, slot 49, and 0x00544157 `WndNotification_guess`), then `CPlayerNotesWnd` (vtable 0x0065A5E0) | its petition fields are window fields, not `EQPlayer` offsets |
| tu_159_FriendsWnd | `CFriendsWnd_guess` (vtable 0x00654750, constructor 0x005035EA) and, at its tail, `CGaugeWnd_guess` (constructor 0x005044F2, the original `GaugeWnd.cpp`) | 0x005049FE asserts with `GaugeWnd.cpp` but is declared as `CFriendsWnd_guess::Draw` |
| tu_216_SpellGemWnd | `CSpellGemWnd_guess` | the file name is the original's (`SpellGemWnd.cpp`) |
