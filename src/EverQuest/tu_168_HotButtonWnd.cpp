// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 168: a hint from compare/tumap.py.
// CHotButtonWnd (CHotButtonWnd_guess): one hot button bar (children "HB<n>_..."; the first bar has no number).
// Each bar has 10 pages of 10 buttons; the shown page is 0x983B75[bar], entries are 8 bytes at 0x983B7C (type
// byte, value) with dirty flags at 0x9839E5. Secondary_guess is its confirmation-dialog callback. The file
// button saves, loads, deletes and clears sets (.\userdata\HB_<slot>_<char>_<server>.ini, table 0x984A84).
#include "titanium/types.h"

#define g_resourceState_guess EQ_GLOBAL(CContextMenuManager_guess*, 0x0099D414)

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* operator new(unsigned int size);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void operator delete(void* memory);

// EXTERNAL: TITANIUM 0x00577000 FUN_00577000_guess
void __cdecl FUN_00577000_guess(char* buffer, int size, const char* format, ...);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* dest, int radix);

struct Display_guess {
	char pad_000[0x148];
	unsigned int ticks_148;
	// EXTERNAL: TITANIUM 0x00440F63 Display_guess::CycleCamera_guess
	void CycleCamera_guess();
};
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)
#define g_emptyText_guess EQ_ARRAY(char, 0x00645EB4)

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CSocialEditWnd.h"
#include "titanium/wnd/CAAWnd.h"
#include "titanium/wnd/CCastSpellWnd.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CItemDisplayManager.h"
#include "titanium/wnd/COptionsWnd.h"
#include "titanium/wnd/CSpellBookWnd.h"
#include "titanium/wnd/CTextEntryWnd.h"

// EXTERNAL: TITANIUM 0x0063FD9C ??_7Secondary_guess@@6B@
// EXTERNAL: TITANIUM 0x005482A0 Secondary_guess::Reset
struct Secondary_guess {
	virtual ~Secondary_guess() { Reset(-1); }
	void Reset(int value);
	void OnMessage_guess(int msg, unsigned int flags, int* data);
};

struct CContextMenu_guess;

// EXTERNAL: TITANIUM 0x005AD7F0 CContextMenuManager_guess::Unregister
// EXTERNAL: TITANIUM 0x005AD5A0 CContextMenuManager_guess::Register_guess
struct CContextMenuManager_guess {
	void Unregister(int resourceId, int flag);
	int Register_guess(CContextMenu_guess* thing);
};

// EXTERNAL: TITANIUM 0x00656070 ??_7CHotButtonWnd_guess@@6BCSidlScreenWndBase@@@
// EXTERNAL: TITANIUM 0x00656068 ??_7CHotButtonWnd_guess@@6BSecondary_guess@@@
struct CHotButtonWnd_guess : CSidlScreenWndBase, Secondary_guess {
	virtual ~CHotButtonWnd_guess();
	void* Delete_guess(unsigned char flags);
	void CreateFileMenu_guess();
	CXWnd* pageLeftButton_160;               // 0x160
	CXWnd* pageRightButton_164;              // 0x164
	CXWnd* currentPageLabel_168;             // 0x168
	int field_16c;                           // 0x16c
	CXWnd* buttons_170[10];                  // 0x170
	CXWnd* invSlots_198[10];                 // 0x198
	CXWnd* spellGems_1c0[10];                // 0x1c0
	int resourceId_1e8;
	int slot_1ec;
	CXWnd* fileButton_1f0;                 // 0x1f0
	CContextMenu_guess* thing_1f4;
	CContextMenu_guess* thing_1f8;
	CContextMenu_guess* thing_1fc;
	unsigned int field_200;                  // 0x200
	int page_204;                            // 0x204
	int field_208;                           // 0x208
	void UpdateFileMenu_guess();
	void SelectHotbutton_guess(int index_guess);
	void DoHotButton(int button_guess, int mode_guess);
	int OnProcessFrame_guess();
	int WndNotification(CXWnd* sender, unsigned int message, int data);
	void UpdatePageLabel_guess();
	bool Function_00514142_guess();
	// EXTERNAL: TITANIUM 0x00513CD7 CHotButtonWnd_guess::CHotButtonWnd_guess
	CHotButtonWnd_guess(CXWnd* parent, int page, const char* name);
};

// Virtual view of a child window: SetWindowTextA is slot 0xFC.
struct TextWnd_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
	virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
	virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
	virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess();
	virtual void SetWindowText_guess(const CXStr& text);   // 0xFC
};

// Virtual view of an inventory slot button: SetPressed is slot 0xC0, flag at +0x13C.
struct ButtonWnd_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
	virtual void SetPressed_guess(int value, int flag);    // 0xC0
	char pad_004[0x138];
	unsigned char field_13c;                               // 0x13C
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// 16-byte rectangle built on the stack for each new (left, top, right, bottom).
struct Rect_guess {
	int left, top, right, bottom;
	Rect_guess(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

// 0x1A8 bytes. Ctor 0x005BFAE0 returns this; Named_guess 0x005BFCF0 takes a
// string, a key and two ints, and cleans its own stack.
struct CContextMenu_guess {
	// EXTERNAL: TITANIUM 0x005BFAE0 CContextMenu_guess::CContextMenu_guess
	CContextMenu_guess(int x, int y, const Rect_guess& rect);
	// EXTERNAL: TITANIUM 0x005BFCF0 CContextMenu_guess::Named_guess
	void Named_guess(const CXStr& text, unsigned int key, int a, int b);
	// EXTERNAL: TITANIUM 0x005BFEF0 CContextMenu_guess::Reset_guess
	void Reset_guess();
	// EXTERNAL: TITANIUM 0x005BFF10 CContextMenu_guess::Flag_guess
	void Flag_guess(int which, bool on);
	char pad_000[0x1A8];
};

// 0x20-byte table entry at 0x00984A84: name string at +0, enabled byte at +0x19.
struct HotButtonSet_guess {
	char name_000[0x19];
	unsigned char enabled_019;
	unsigned char flag_01a;
	char pad_01b;
	int index_01c;
};
#define g_entries_guess EQ_ARRAY(HotButtonSet_guess, 0x00984A84)

struct HotbarEntry_guess {
	unsigned char type_000;
	char pad_001[3];
	int value_004;
};

struct EQPlayerView_guess {
	char pad_000[0x251];
	char mode_251;
	// EXTERNAL: TITANIUM 0x0048297B EQPlayerView_guess::Open_guess
	void Open_guess(int id, int flag, int value);
	// EXTERNAL: TITANIUM 0x0047E8E0 EQPlayerView_guess::Activate_guess
	void Activate_guess();
};

struct SlotAction_guess {
	// EXTERNAL: TITANIUM 0x0041F4A0 SlotAction_guess::Activate_guess
	void Activate_guess(unsigned char action, int value);
};

struct ChatUi_guess {
	// EXTERNAL: TITANIUM 0x0049C800 ChatUi_guess::Open_guess
	void Open_guess(const char* text);
	// EXTERNAL: TITANIUM 0x0049D3CC ChatUi_guess::Invite_guess
	void Invite_guess(int flag);
	// EXTERNAL: TITANIUM 0x0049D7B6 ChatUi_guess::AcceptGroupInvite_guess
	void AcceptGroupInvite_guess();
	// EXTERNAL: TITANIUM 0x0049D8BD ChatUi_guess::Disband_guess
	void Disband_guess();
	// EXTERNAL: TITANIUM 0x0049DDA6 ChatUi_guess::PrepareToCamp_guess
	void PrepareToCamp_guess();
	// EXTERNAL: TITANIUM 0x0049DCFA ChatUi_guess::ToggleSit_guess
	void ToggleSit_guess();
	// EXTERNAL: TITANIUM 0x00492874 ChatUi_guess::GetInnateDesc_guess
	const char* GetInnateDesc_guess(int id);
};

// Virtual base of the client character; its vbptr sits at +8.
struct ItemHolder_guess;
struct CharBase_guess {
	char pad_000[0x3C];
	char name_03c[0x40];
	// EXTERNAL: TITANIUM 0x0040E705 CharBase_guess::GetMemorizedSpell_guess
	int GetMemorizedSpell_guess(int gem);
	// EXTERNAL: TITANIUM 0x0040CC50 CharBase_guess::GetInventorySlot_guess
	ItemHolder_guess* GetInventorySlot_guess(int id);
};

struct CoreHead_guess {
	char pad_000[0x8];
};

struct EQ_CharacterView_guess : CoreHead_guess, virtual CharBase_guess {
	char pad_00c[0xC274];
	SlotAction_guess slotAction_c280;
	// EXTERNAL: TITANIUM 0x005F0A00 EQ_CharacterView_guess::GetHotbuttonText_guess
	const char* GetHotbuttonText_guess(int id);
	// EXTERNAL: TITANIUM 0x004BB39D EQ_CharacterView_guess::DoCombatAbility
	void DoCombatAbility(const char* text);
	// EXTERNAL: TITANIUM 0x004BAC08 EQ_CharacterView_guess::GetDisciplineTimer_guess
	unsigned int GetDisciplineTimer_guess(int id);
	// EXTERNAL: TITANIUM 0x004BAAEB EQ_CharacterView_guess::HasAltAbility_guess
	bool HasAltAbility_guess(int id);
	// EXTERNAL: TITANIUM 0x005F0BD0 EQ_CharacterView_guess::GetSlotCount_guess
	unsigned int GetSlotCount_guess(int slot);
};

struct SpellManager_guess {
	// EXTERNAL: TITANIUM 0x0040CBD6 SpellManager_guess::GetSpell_guess
	int GetSpell_guess(const char* text);
};

struct HotbuttonPage_guess {
	char pad_000[0x8];
	int count_008;
	int nameId_00c;
	int descId_010;
	int extraId_014;
};

struct LeadershipManager_guess {
	HotbuttonPage_guess* pages_000[31];
	// EXTERNAL: TITANIUM 0x004B4795 LeadershipManager_guess::UseAbility_guess
	void UseAbility_guess(int page, int slot);
	// EXTERNAL: TITANIUM 0x004B44C6 LeadershipManager_guess::CanUseAbility_guess
	bool CanUseAbility_guess(EQ_CharacterView_guess* core, int page, int slot);
};

struct HotbuttonWindow_guess {
	// EXTERNAL: TITANIUM 0x0059DD30 HotbuttonWindow_guess::CanUse_guess
	char CanUse_guess();
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess();
	virtual void Action84_guess();
	virtual void Action88_guess();
};

struct CPetInfoWndView_guess {
	// EXTERNAL: TITANIUM 0x0054209C CPetInfoWndView_guess::GetButton_guess
	int GetButton_guess(int value);
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Dispatch80_guess(int value, int flag, int extra);
};

struct CameraState_guess {
	char pad_000[0x48];
	float value_048;
};

#define g_clientState_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)
#define g_restrictedState_guess EQ_GLOBAL(int, 0x009248D0)
#define g_chatUi_guess EQ_GLOBAL(ChatUi_guess*, 0x00988DF0)
#define g_clientCore_guess EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)
#define g_textManager_guess EQ_GLOBAL(SpellManager_guess*, 0x00985CC8)
#define g_pageManager_guess EQ_GLOBAL(LeadershipManager_guess*, 0x009859EC)
#define pinstCPetInfoWnd_guess EQ_GLOBAL(CPetInfoWndView_guess*, 0x00850BAC)
#define g_cameraState_guess EQ_GLOBAL(CameraState_guess*, 0x00905CF8)
#define g_hotbarEntries_guess EQ_ARRAY(HotbarEntry_guess, 0x00983B7C)
#define g_hotbarPageOffsets_guess EQ_ARRAY(signed char, 0x00983B75)
#define g_hotbarEntryTypes_guess EQ_ARRAY(unsigned char, 0x00983B7C)
#define g_hotbarEntryValues_guess EQ_ARRAY(int, 0x00983B80)
#define g_activeHotbarEntry_guess EQ_GLOBAL(int, 0x009839E0)
#define g_itemActivationState_guess EQ_GLOBAL(char, 0x00924670)
#define g_delayedHotbuttonGuess_guess EQ_GLOBAL(int, 0x00694D8C)
#define g_settingsOpen_guess EQ_GLOBAL(char, 0x00923798)
#define g_alternateUi_guess EQ_GLOBAL(char, 0x00985808)
#define g_showHotbar_guess EQ_GLOBAL(char, 0x009237B4)
#define g_toggleHotbar_guess EQ_GLOBAL(char, 0x00923990)
#define g_cameraValue_guess EQ_GLOBAL(float, 0x00640038)

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int id, int flag, int extra);

// Hot button bar destructor: releases the file menu's id (+0x1E8) at the menu manager (0x99D414).
// FUNCTION: TITANIUM 0x00513794
CHotButtonWnd_guess::~CHotButtonWnd_guess() {
	if (resourceId_1e8 != -1) {
		CContextMenuManager_guess* resourceState = g_resourceState_guess;
		if (resourceState != 0) {
			resourceState->Unregister(resourceId_1e8, 1);
		}
	}
}

// Builds the file button's context menu: Load and Delete submenus, Save (item 0x189C) and Clear (0x1900).
// FUNCTION: TITANIUM 0x00513806
void CHotButtonWnd_guess::CreateFileMenu_guess() {
	thing_1f4 = new CContextMenu_guess(0, 0, Rect_guess(0, 0, 0x32, 0xa));
	thing_1f8 = new CContextMenu_guess(0, 0, Rect_guess(0, 0, 0x32, 0xa));
	thing_1fc = new CContextMenu_guess(0, 0, Rect_guess(0, 0, 0x32, 0xa));
	int id = g_resourceState_guess->Register_guess(thing_1f8);
	{
		CXStr name(pStringTable->getString(0x1f49, 0));
		thing_1f4->Named_guess(name, id + 0x80000000, 0, -1);
	}
	{
		CXStr name(pStringTable->getString(0x1f4a, 0));
		thing_1f4->Named_guess(name, 0x189c, 0, -1);
	}
	id = g_resourceState_guess->Register_guess(thing_1fc);
	{
		CXStr name(pStringTable->getString(0x1f4b, 0));
		thing_1f4->Named_guess(name, id + 0x80000000, 0, -1);
	}
	{
		CXStr name(pStringTable->getString(0x1f5c, 0));
		thing_1f4->Named_guess(name, 0x1900, 0, -1);
	}
	resourceId_1e8 = g_resourceState_guess->Register_guess(thing_1f4);
}

// Fills Load (items 0x17D4+n) and Delete (0x1838+n) with the saved set names, disabling both when none
// exist. Only the first 10 of the 100 set slots are listed.
// FUNCTION: TITANIUM 0x00513A6A
void CHotButtonWnd_guess::UpdateFileMenu_guess() {
	thing_1f8->Reset_guess();
	thing_1fc->Reset_guess();
	int remaining = 10;
	int count = 0;
	int key = 0x1838;
	HotButtonSet_guess* entry = g_entries_guess;
	do {
		if (entry->enabled_019 != 0) {
			++count;
			{
				CXStr name(entry->name_000);
				thing_1f8->Named_guess(name, key - 100, 0, -1);
			}
			{
				CXStr name(entry->name_000);
				thing_1fc->Named_guess(name, key, 0, -1);
			}
		}
		++entry;
		++key;
	} while (--remaining != 0);
	thing_1f4->Flag_guess(0, count > 0);
	thing_1f4->Flag_guess(2, count > 0);
}

#define g_controlValues_guess EQ_ARRAY(signed char, 0x00983B75)

// Formatted-string temporary: the int formatter 0x005724C0 fills it, its dtor releases it.
struct FormattedString_guess {
	char* value_guess;
	// EXTERNAL: TITANIUM 0x005724C0 FormattedString_guess::FormattedString_guess
	FormattedString_guess(int value, int radix, int bufferSize);
	// EXTERNAL: TITANIUM 0x00571D00 FormattedString_guess::FreeRep
	void FreeRep(char* value);
	~FormattedString_guess() {
		if (value_guess != 0) {
			FreeRep(value_guess);
		}
	}
};

// Virtual view of a child window that takes a formatted string: SetText is slot 0xFC.
struct FormattedText_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
	virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
	virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
	virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess();
	virtual void SetText_guess(const FormattedString_guess& text);   // 0xFC
};

// Wraps the bar's page to 0-9 and shows it 1-based in CurrentPageLabel.
// FUNCTION: TITANIUM 0x00513B6B
void CHotButtonWnd_guess::UpdatePageLabel_guess() {
	if (g_controlValues_guess[page_204] < 0) {
		g_controlValues_guess[page_204] = 9;
	}
	if (g_controlValues_guess[page_204] >= 10) {
		g_controlValues_guess[page_204] = 0;
	}
	field_16c = g_controlValues_guess[page_204];
	if (currentPageLabel_168 != 0) {
		((FormattedText_guess*)currentPageLabel_168)->SetText_guess(FormattedString_guess(field_16c + 1, 2, 0x20));
	}
}

// 16-byte value returned by Child_guess::Slot57_guess (hidden return pointer).
struct Pair_guess {
	int first;
	int second;
};

struct Out_guess : Pair_guess {
	int extra[2];
};

// EXTERNAL: TITANIUM 0x0051A3A0 DataHandler_guess::Apply_guess
struct DataHandler_guess {
	char pad_000[0x10];
	void Apply_guess(Pair_guess* pair);
};

// Child window: vptr at 0, handler pointer at +0x140, slot 57 (+0xE4) returns Out_guess.
struct Child_guess {
	char pad_000[0x13C];
	DataHandler_guess* handler_140;
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess();
	virtual void Slot05_guess();
	virtual void Slot06_guess();
	virtual void Slot07_guess();
	virtual void Slot08_guess();
	virtual void Slot09_guess();
	virtual void Slot10_guess();
	virtual void Slot11_guess();
	virtual void Slot12_guess();
	virtual void Slot13_guess();
	virtual void Slot14_guess();
	virtual void Slot15_guess();
	virtual void Slot16_guess();
	virtual void Slot17_guess();
	virtual void Slot18_guess();
	virtual void Slot19_guess();
	virtual void Slot20_guess();
	virtual void Slot21_guess();
	virtual void Slot22_guess();
	virtual void Slot23_guess();
	virtual void Slot24_guess();
	virtual void Slot25_guess();
	virtual void Slot26_guess();
	virtual void Slot27_guess();
	virtual void Slot28_guess();
	virtual void Slot29_guess();
	virtual void Slot30_guess();
	virtual void Slot31_guess();
	virtual void Slot32_guess();
	virtual void Slot33_guess();
	virtual void Slot34_guess();
	virtual void Slot35_guess();
	virtual void Slot36_guess();
	virtual void Slot37_guess();
	virtual void Slot38_guess();
	virtual void Slot39_guess();
	virtual void Slot40_guess();
	virtual void Slot41_guess();
	virtual void Slot42_guess();
	virtual void Slot43_guess();
	virtual void Slot44_guess();
	virtual void Slot45_guess();
	virtual void Slot46_guess();
	virtual void Slot47_guess();
	virtual void Slot48_guess();
	virtual void Slot49_guess();
	virtual void Slot50_guess();
	virtual void Slot51_guess();
	virtual void Slot52_guess();
	virtual void Slot53_guess();
	virtual void Slot54_guess();
	virtual void Slot55_guess();
	virtual void Slot56_guess();
	virtual Out_guess Slot57_guess();
};

#define g_actionDisabled_guess EQ_GLOBAL(int, 0x00923888)

// Right-click action: a social (0-119) opens CSocialEditWnd, an AA (120+) is selected in the AA window
// (0x850BD0), an item is used through its inventory slot, and a spell gem goes to CCastSpellWnd
// (0x4EBF26) unless 0x923888 is set.
// FUNCTION: TITANIUM 0x00513BFF
// @early-stop: budget, structural ndiff=21
void CHotButtonWnd_guess::SelectHotbutton_guess(int index_guess) {
	int state = page_204;
	int recordIndex = index_guess + ((int)g_hotbarPageOffsets_guess[state] + state * 10) * 10;
	HotbarEntry_guess* record = &g_hotbarEntries_guess[recordIndex];
	if (record->type_000 == 4) {
		g_activeHotbarEntry_guess = record->value_004;
		if (g_activeHotbarEntry_guess < 0x78) {
			pinstCSocialEditWnd_guess->Run_guess(g_activeHotbarEntry_guess);
		} else {
			pinstCAAWnd_guess->Activate();
			pinstCAAWnd_guess->SelectAbility_guess(g_activeHotbarEntry_guess - 0x78);
		}
	} else if (record->type_000 == 5) {
		CXWnd** childSlot = &invSlots_198[index_guess];
		Child_guess* child = (Child_guess*)*childSlot;
		if (child != 0 && child->handler_140 != 0) {
			DataHandler_guess* handler = child->handler_140;
			const Out_guess& values = child->Slot57_guess();
			Pair_guess pair = values;
			handler->Apply_guess(&pair);
		}
	} else if (record->type_000 == 7 && g_actionDisabled_guess == 0) {
		pinstCCastSpellWnd_guess->Dispatch_guess(record->value_004);
	}
}

// Hot button bar constructor for bar `page` (0-based): finds the page arrows, page label and file button,
// then the ten buttons with their InvSlot and SpellGem overlays, which start off (virtual slot 48 with 0);
// builds the file menu (0x00513806) and keeps the creation time (+0x200).
// FUNCTION: TITANIUM 0x00513CD7
CHotButtonWnd_guess::CHotButtonWnd_guess(CXWnd* parent, int page, const char* name)
	: CSidlScreenWndBase(parent, name, -1, 2, 0), resourceId_1e8(-1) {
	thing_1f4 = 0;
	thing_1f8 = 0;
	thing_1fc = 0;
	pageLeftButton_160 = 0;
	pageRightButton_164 = 0;
	currentPageLabel_168 = 0;
	fileButton_1f0 = 0;
	field_208 = 0;
	for (int i = 0; i < 10; ++i) {
		buttons_170[i] = 0;
		invSlots_198[i] = 0;
		spellGems_1c0[i] = 0;
	}
	page_204 = page;
	if (SidlPiece != 0) {
		field_018_guess = 0;
		WindowStyle |= SidlPiece->style_guess | 0x800;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		char suffix[12];
		suffix[0] = 0;
		if (page + 1 != 1) {
			_itoa(page + 1, suffix, 10);
		}
		char text[0x100];
		// `suffix` stays empty for the first bar.
		FUN_00577000_guess(text, 0x100, "HB%s_PageLeftButton", suffix);
		pageLeftButton_160 = ((CSidlScreenWnd*)this)->GetChildItem(text);
		FUN_00577000_guess(text, 0x100, "HB%s_PageRightButton", suffix);
		pageRightButton_164 = ((CSidlScreenWnd*)this)->GetChildItem(text);
		FUN_00577000_guess(text, 0x100, "HB%s_CurrentPageLabel", suffix);
		currentPageLabel_168 = ((CSidlScreenWnd*)this)->GetChildItem(text);
		FUN_00577000_guess(text, 0x100, "HB%s_FileButton", suffix);
		fileButton_1f0 = ((CSidlScreenWnd*)this)->GetChildItem(text);
		if (currentPageLabel_168 != 0) {
			((TextWnd_guess*)currentPageLabel_168)->SetWindowText_guess(g_emptyText_guess);
		}
		field_16c = 0;
		for (int index = 0; index < 10; ++index) {
			FUN_00577000_guess(text, 0x100, "HB%s_Button%d", suffix, index + 1);
			buttons_170[index] = ((CSidlScreenWnd*)this)->GetChildItem(text);
			FUN_00577000_guess(text, 0x100, "HB%s_InvSlot%d", suffix, index + 1);
			invSlots_198[index] = ((CSidlScreenWnd*)this)->GetChildItem(text);
			if (invSlots_198[index] != 0) {
				((ButtonWnd_guess*)invSlots_198[index])->field_13c = 1;
				((ButtonWnd_guess*)invSlots_198[index])->SetPressed_guess(0, 1);
			}
			FUN_00577000_guess(text, 0x100, "HB%s_SpellGem%d", suffix, index + 1);
			spellGems_1c0[index] = ((CSidlScreenWnd*)this)->GetChildItem(text);
			if (spellGems_1c0[index] != 0) {
				((ButtonWnd_guess*)spellGems_1c0[index])->SetPressed_guess(0, 1);
			}
		}
		CreateFileMenu_guess();
		field_200 = g_display_guess->ticks_148;
	}
}

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_guess
void __cdecl FormatCXStr_guess(CXStr* text, const char* format, ...);
// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* dest, int id, const char* text, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);
// EXTERNAL: TITANIUM 0x0060BF10 IniRead_guess
void __cdecl IniRead_guess(const char* section, const char* key, const char* fallback, char* buffer, int size, const char* file);
// EXTERNAL: TITANIUM 0x0060E3A3 atoi
int __cdecl atoi(const char* text);
// EXTERNAL: TITANIUM 0x0060D970 strlen
unsigned int __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x00494DDC SortEntries_guess
void __cdecl SortEntries_guess();
struct EverQuestHotbar_guess {
	// EXTERNAL: TITANIUM 0x004B023B EverQuestHotbar_guess::SaveHotButtons_guess
	void SaveHotButtons_guess();
};
#define g_hotbarEnabled_guess EQ_ARRAY(unsigned char, 0x009839E5)
#define g_serverName_guess EQ_ARRAY(char, 0x0095D3D4)
#define g_emptyLine_guess EQ_ARRAY(char, 0x0063F53F)
#define g_fmtKey_guess EQ_ARRAY(char, 0x00656220)
#define g_fmtPath_guess EQ_ARRAY(char, 0x00656230)
#define g_userdata_guess EQ_ARRAY(char, 0x006492E8)
#define g_sectionHotbuttons_guess EQ_ARRAY(char, 0x00656214)

// Confirmation answers (flags 1 or 4 = yes): 0x7F loads set `*data` into all 10 pages (Page<r>.Slot<c> =
// type letter from 'A' plus value), 0x80 drops it from the menus, 0x81 clears all 100 entries of this bar.
// FUNCTION: TITANIUM 0x0051450A
// @early-stop: budget, structural ndiff=112
void Secondary_guess::OnMessage_guess(int msg, unsigned int flags, int* data) {
	switch (msg) {
	case 0x7f: {
		if ((flags & 5) != 0 && g_entries_guess[*data].enabled_019 != 0) {
			char text[0x200];
			char buf[16];
			CXStr key;
			CXStr path;
			FormatCXStr_guess(&path, g_fmtPath_guess, g_userdata_guess, g_entries_guess[*data].index_01c,
			                  g_clientCore_guess->name_03c, g_serverName_guess);
			for (int row = 0; row < 10; ++row) {
				for (int col = 0; col < 10; ++col) {
					int idx = (row + static_cast<CHotButtonWnd_guess*>(this)->page_204 * 10) * 10 + col;
					g_hotbarEnabled_guess[idx] = 1;
					g_hotbarEntries_guess[idx].type_000 = 0;
					g_hotbarEntries_guess[idx].value_004 = 0;
					FormatCXStr_guess(&key, g_fmtKey_guess, row + 1, col + 1);
					IniRead_guess(g_sectionHotbuttons_guess, key, g_emptyLine_guess, buf, 16, path);
					if (strlen(buf) != 0) {
						char c = buf[0] - 'A';
						g_hotbarEntries_guess[idx].type_000 = c;
						if (c != 0) {
							g_hotbarEntries_guess[idx].value_004 = atoi(buf + 1);
						}
					}
				}
			}
			FormatText_guess(text, 0x1f4f, g_entries_guess[*data].name_000, 0, 0, 0, 0, 0, 0, 0, 0);
			((EverQuestHotbar_guess*)pEverQuest)->SaveHotButtons_guess();
			pEverQuest->dsp_chat(text, 0xf, 1);
		}
		return;
	}
	case 0x80: {
		if ((flags & 5) == 0) {
			return;
		}
		if (g_entries_guess[*data].enabled_019 == 0) {
			return;
		}
		char text[0x200];
		FormatText_guess(text, 0x1f4d, g_entries_guess[*data].name_000, 0, 0, 0, 0, 0, 0, 0, 0);
		g_entries_guess[*data].enabled_019 = 0;
		g_entries_guess[*data].flag_01a = 1;
		SortEntries_guess();
		static_cast<CHotButtonWnd_guess*>(this)->UpdateFileMenu_guess();
		pEverQuest->dsp_chat(text, 0xf, 1);
		return;
	}
	case 0x81:
	if ((flags & 5) == 0) {
		return;
	}
	for (int row = 0; row < 10; ++row) {
		for (int col = 0; col < 10; ++col) {
			int idx = (row + static_cast<CHotButtonWnd_guess*>(this)->page_204 * 10) * 10 + col;
			g_hotbarEntries_guess[idx].type_000 = 0;
			g_hotbarEntries_guess[idx].value_004 = -1;
			g_hotbarEnabled_guess[idx] = 1;
		}
	}
	((EverQuestHotbar_guess*)pEverQuest)->SaveHotButtons_guess();
	pEverQuest->dsp_chat(pStringTable->getString(0x1f60, 0), 0xf, 1);
	}
}

// Scalar deleting destructor of a hot button bar (vtable 0x656070 slot 1): runs the destructor
// (0x00513794) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00514126
void* CHotButtonWnd_guess::Delete_guess(unsigned char flags) {
	this->CHotButtonWnd_guess::~CHotButtonWnd_guess();
	if ((flags & 1) != 0) {
		free(this);
	}
	return this;
}

// Shows the page label again and restarts the 200 ms refresh timer.
// FUNCTION: TITANIUM 0x00514142
bool CHotButtonWnd_guess::Function_00514142_guess() {
	field_200 = g_display_guess->ticks_148;
	UpdatePageLabel_guess();
	return true;
}

// Runs button `button_guess` of the shown page; `mode_guess` 1 is a click, which does nothing for an item
// (items run on right-click). Types: 1 attack (value 0) or range attack (1), 2-3 probably combat and ability
// skill slots (tables 0x95D414, 0x95D424), 4 social or AA, 5 item, 6 menu button, 7 spell gem, 8 pet command,
// 9 skill or innate (value 100+), 10 combat ability, 11 leadership ability (value / 8, value % 8).
// FUNCTION: TITANIUM 0x0051415B
void CHotButtonWnd_guess::DoHotButton(int button_guess, int mode_guess) {
	HotbarEntry_guess* entry = g_hotbarEntries_guess;
	if (((g_clientState_guess != 0) && (g_clientState_guess->mode_251 == 'f')) || (g_restrictedState_guess != 0)) {
		// Frozen (stand state 'f') or with a server request pending (0x9248D0).
		pEverQuest->dsp_chat(pStringTable->getString(0x2F34, 0), 0x111, 1);
		return;
	}
	int pageIndex = page_204;
	int rowIndex = (int)g_hotbarPageOffsets_guess[pageIndex] + pageIndex * 10;
	int entryIndex = button_guess + rowIndex * 10;
	entry += entryIndex;
	if (entry->type_000 == 1) {
		switch (entry->value_004) {
		case 0:
			ExecuteCmd(10, 1, 0);
			return;
		case 1:
			if (g_itemActivationState_guess == 0) {
				return;
			}
			g_itemActivationState_guess = 0;
			g_clientState_guess->Open_guess(0x0B, 0, EQ_GLOBAL(int, 0x00905D04));
			return;
		default:
			return;
		}
	}
	if ((entry->type_000 == 2) && (entry->value_004 != -1)) {
		g_clientCore_guess->slotAction_c280.Activate_guess((unsigned char)EQ_ARRAY(int, 0x0095D414)[entry->value_004], EQ_GLOBAL(int, 0x00905D04));
		return;
	}
	if ((entry->type_000 == 3) && (entry->value_004 != -1)) {
		g_clientCore_guess->slotAction_c280.Activate_guess((unsigned char)EQ_ARRAY(int, 0x0095D424)[entry->value_004], EQ_GLOBAL(int, 0x00905D04));
		return;
	}
	if ((entry->type_000 == 9) && (entry->value_004 != -1)) {
		g_clientCore_guess->slotAction_c280.Activate_guess((unsigned char)entry->value_004, EQ_GLOBAL(int, 0x00905D04));
		return;
	}
	if ((entry->type_000 == 10) && (entry->value_004 != -1)) {
		const char* text = g_clientCore_guess->GetHotbuttonText_guess(entry->value_004 - 0x84);
		if (g_textManager_guess->GetSpell_guess(text) == 0) {
			return;
		}
		g_clientCore_guess->DoCombatAbility(text);
		return;
	}
	if (entry->type_000 == 4) {
		if (g_delayedHotbuttonGuess_guess != -1) {
			return;
		}
		g_delayedHotbuttonGuess_guess = entry->value_004 << 3;
		return;
	}
	if (entry->type_000 == 11) {
		int value = entry->value_004;
		g_pageManager_guess->UseAbility_guess(value / 8, value % 8);
		return;
	}
	if (entry->type_000 == 5) {
		if (mode_guess == 1) {
			return;
		}
		SelectHotbutton_guess(button_guess);
		return;
	}
	if (entry->type_000 == 6) {
		switch (entry->value_004) {
		case 0:
			if (g_settingsOpen_guess == 0) {
				g_chatUi_guess->Open_guess(EQ_ARRAY(char, 0x0063F53F));
			}
			break;
		case 1:
			if (g_alternateUi_guess != 0) {
				g_chatUi_guess->AcceptGroupInvite_guess();
			} else {
				g_chatUi_guess->Invite_guess(0);
			}
			break;
		case 2:
			g_chatUi_guess->Disband_guess();
			break;
		case 3:
			g_chatUi_guess->PrepareToCamp_guess();
			break;
		case 4:
			g_chatUi_guess->ToggleSit_guess();
			break;
		case 5:
			g_showHotbar_guess = (char)(g_showHotbar_guess ^ 1);
			break;
		case 7:
			if (pinstCOptionsWnd_guess->IsVisible_guess() == 0) {
				pinstCOptionsWnd_guess->Activate();
			}
			break;
		case 8:
			g_display_guess->CycleCamera_guess();
			break;
		case 9:
			if (pinstCInventoryWnd_guess->IsVisible_guess() == 0) {
				pinstCInventoryWnd_guess->Activate();
			}
			break;
		case 10:
			if (pinstCSpellBookWnd_guess->IsVisible_guess() == 0) {
				if ((g_cameraState_guess != 0) && (g_cameraState_guess->value_048 > 0.01f)) {
					// Menu 10 is the spell book: refused while moving or looting (stand state 'i').
					pEverQuest->dsp_chat(pStringTable->getString(0x2F35, 0));
					return;
				}
				if (g_clientState_guess->mode_251 == 'i') {
					return;
				}
				pinstCSpellBookWnd_guess->Activate();
			} else {
				pinstCSpellBookWnd_guess->Deactivate();
				return;
			}
			break;
		case 11:
			g_toggleHotbar_guess = (char)(g_toggleHotbar_guess ^ 1);
			break;
		case 12:
			ExecuteCmd(0xC9, 1, 0);
			break;
		}
		return;
	}
	if (entry->type_000 == 7) {
		g_clientState_guess->Activate_guess();
		pinstCCastSpellWnd_guess->Select_guess(entry->value_004);
		return;
	}
	if (entry->type_000 == 8) {
		int result = pinstCPetInfoWnd_guess->GetButton_guess(entry->value_004);
		if (result != 0) {
			pinstCPetInfoWnd_guess->Dispatch80_guess(result, 1, 0);
		}
		return;
	}
}

// First 48 virtual slots (0x00..0xBC) of a child window.
struct Slots30_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
};

// Hot button: SetWindowText at slot 0xFC, its icon fields at 0x16C..0x17C.
struct HotButton_guess : Slots30_guess {
	virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
	virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
	virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess();
	virtual void SetWindowText_guess(const CXStr& text);   // 0xFC
	char pad_004[0x78];
	int color_07c;
	char pad_080[0xEC];
	int icon_16c;
	int icon_170;
	int icon_174;
	int pad_178;
	int icon_17c;
};

// Button that an item lookup returns; GetText_guess returns a CXStr by value.
struct ItemButton_guess {
	char pad_000[0x16c];
	int icon_16c;
	int icon_170;
	int icon_174;
	int pad_178;
	int icon_17c;
	// EXTERNAL: TITANIUM 0x004D22D7 ItemButton_guess::GetText_guess
	CXStr GetText_guess();
};

struct ItemWindow_guess {
	// EXTERNAL: TITANIUM 0x004D2A03 ItemWindow_guess::GetCombatPageButton_guess
	ItemButton_guess* GetCombatPageButton_guess(int slot);
	// EXTERNAL: TITANIUM 0x004D2A11 ItemWindow_guess::GetMainPageButton_guess
	ItemButton_guess* GetMainPageButton_guess(int index);
};

struct SpellIconInfo_guess {
	char pad_000[0x11c];
	int field_11c;
	char pad_120[0x10];
	int field_130;
};

struct SpellIcon_guess {
	int pad_000;
	SpellIconInfo_guess* info_004;
	int field_008;
};

struct CInvSlotMgr_guess {
	// EXTERNAL: TITANIUM 0x0051A84D CInvSlotMgr_guess::FindInvSlot
	SpellIcon_guess* FindInvSlot(int id);
};

// Inventory slot button: SetPressed at slot 0xC0.
struct CInvSlot_guess : Slots30_guess {
	virtual void SetPressed_guess(int value, int flag);    // 0xC0
	char pad_004[0x118];
	int field_11c;
	int value_120;
	char pad_124[0x8];
	int field_12c;
	int field_130;
	// EXTERNAL: TITANIUM 0x0051B7A8 CInvSlot_guess::SetIcon_guess
	void SetIcon_guess(SpellIcon_guess* icon);
};

// Spell gem: SetPressed at slot 0xC0.
struct SpellGem_guess : Slots30_guess {
	virtual void SetPressed_guess(int value, int flag);    // 0xC0
	char pad_004[0x184];
	int spellIcon_188;
	int state_18c;
	// EXTERNAL: TITANIUM 0x00558984 SpellGem_guess::SetSpellIcon_guess
	void SetSpellIcon_guess(int icon);
	// EXTERNAL: TITANIUM 0x005589AB SpellGem_guess::SetSpellGemTint_guess
	void SetSpellGemTint_guess(unsigned int color);
	// EXTERNAL: TITANIUM 0x00558A18 SpellGem_guess::SetFadeMode_guess
	void SetFadeMode_guess(int state);
};

struct Spell_guess {
	char pad_000[0x1c0];
	int id_1c0;
	char pad_1c4[0x44];
	const char* name_208;
	char pad_20c[0x3c];
	int icon_248;
	// EXTERNAL: TITANIUM 0x0044D103 Spell_guess::GetColor_guess
	unsigned int GetColor_guess();
};

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpell_guess
bool __cdecl IsValidSpell_guess(int id);
// EXTERNAL: TITANIUM 0x00576E80 GetTime_guess
unsigned int __cdecl GetTime_guess();
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

struct SkillInfo_guess {
	int nameId_000;
	char pad_004[6];
	char kind_00a;
};

struct SocialEntry_guess {
	char text_000[0x510];
	signed char color_510;
};

struct SocialPage_guess {
	SocialEntry_guess entries[12];
};

struct Item_guess {
	int id_000;
	int pad_004;
	int nameId_008;
	int descId_00c;
	char pad_010[0x2c];
	int slot_03c;
};

struct AltAdvManager_guess {
	// EXTERNAL: TITANIUM 0x00447D1F AltAdvManager_guess::Find_guess
	Item_guess* Find_guess(EQ_CharacterView_guess* core, int index);
	// EXTERNAL: TITANIUM 0x00447BE2 AltAdvManager_guess::Count_guess
	void Count_guess(EQ_CharacterView_guess* core, Item_guess* item, int* count);
};

struct CDBStr_guess {
	// EXTERNAL: TITANIUM 0x004355F7 CDBStr_guess::GetString_guess
	const char* GetString_guess(int id, int kind, int flag);
};

struct PlayerTimers_guess {
	char pad_000[0xe8];
	unsigned int gemReady_0e8[9];
	unsigned int field_10c;
	unsigned int field_110;
	char pad_114[0xe84];
	int castingSpell_f98;
};

struct Player_guess {
	char pad_000[0x1a8];
	PlayerTimers_guess* timers_1a8;
};

struct CXStrFormat_guess {
	CStrRep* Ptr;
	// EXTERNAL: TITANIUM 0x005738B0 CXStrFormat_guess::Format_guess
	void __cdecl Format_guess(const char* format, ...);
};

#define pinstCActionsWnd_guess EQ_GLOBAL(ItemWindow_guess*, 0x00850C44)
#define pinstCInvSlotMgr_guess EQ_GLOBAL(CInvSlotMgr_guess*, 0x00850CB8)
#define g_itemManager_guess EQ_GLOBAL(AltAdvManager_guess*, 0x008511D8)
#define g_dbStrings_guess EQ_GLOBAL(CDBStr_guess*, 0x00850398)
#define g_player_guess EQ_GLOBAL(Player_guess*, 0x00905CE4)
#define g_skillInfo_guess EQ_ARRAY(SkillInfo_guess*, 0x00851200)
#define g_socialPages_guess EQ_ARRAY(SocialPage_guess, 0x0095D4D4)
#define g_skillOff_guess EQ_ARRAY(char, 0x0092460C)
#define g_skillAttackReady_guess EQ_GLOBAL(char, 0x00924672)
#define g_autoCheck_guess EQ_GLOBAL(char, 0x009858C8)
#define g_newline_guess EQ_ARRAY(char, 0x00641588)
#define g_slotFormat_guess EQ_ARRAY(char, 0x00656248)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

#define HOTBAR_ENTRY(i) g_hotbarEntries_guess[((int)g_hotbarPageOffsets_guess[page_204] + page_204 * 10) * 10 + (i)]

// Every 200 ms while shown: redraws each button from its entry (text, icon, tooltip). A checked button is
// one whose action is not ready now (recast, AA timer, skill off, leadership rank).
// FUNCTION: TITANIUM 0x0051482B
// @early-stop: budget, structural ndiff=673
int CHotButtonWnd_guess::OnProcessFrame_guess() {
	if (((HotbuttonWindow_guess*)this)->CanUse_guess() == 1 && g_display_guess->ticks_148 > field_200 + 200) {
		for (int i = 0; i < 10; ++i) {
			HotButton_guess** button = (HotButton_guess**)&buttons_170[i];
			if (*button == 0) {
				continue;
			}
			CInvSlot_guess** slot = (CInvSlot_guess**)&invSlots_198[i];
			if (*slot == 0) {
				continue;
			}
			if (spellGems_1c0[i] == 0) {
				continue;
			}
			if (HOTBAR_ENTRY(i).type_000 != 0) {
				((CButtonWnd*)*button)->SetCheck(false);
				(*button)->color_07c = -1;
				if (HOTBAR_ENTRY(i).type_000 != 5) {
					(*slot)->SetIcon_guess(0);
					(*slot)->value_120 = -1;
					(*slot)->SetPressed_guess(0, 1);
				}
				if (HOTBAR_ENTRY(i).type_000 != 7) {
					((SpellGem_guess*)spellGems_1c0[i])->SetPressed_guess(0, 1);
				}
				if (HOTBAR_ENTRY(i).type_000 != 1) {
					(*button)->icon_16c = 0;
					(*button)->icon_174 = 0;
					(*button)->icon_170 = 0;
					(*button)->icon_17c = 0;
				} else {
					(*button)->icon_16c = pinstCActionsWnd_guess->GetCombatPageButton_guess(HOTBAR_ENTRY(i).value_004)->icon_16c;
					(*button)->icon_174 = pinstCActionsWnd_guess->GetCombatPageButton_guess(HOTBAR_ENTRY(i).value_004)->icon_174;
					(*button)->icon_170 = pinstCActionsWnd_guess->GetCombatPageButton_guess(HOTBAR_ENTRY(i).value_004)->icon_170;
					(*button)->icon_17c = pinstCActionsWnd_guess->GetCombatPageButton_guess(HOTBAR_ENTRY(i).value_004)->icon_17c;
				}
				char type = HOTBAR_ENTRY(i).type_000;
				if (type == 10) {
					const char* text = g_clientCore_guess->GetHotbuttonText_guess(HOTBAR_ENTRY(i).value_004 - 0x84);
					CXStr unused;
					Spell_guess* spell = (Spell_guess*)g_textManager_guess->GetSpell_guess(text);
					if (spell != 0) {
						(*button)->SetWindowText_guess(CXStr(spell->name_208));
						((CButtonWnd*)*button)->SetCheck(g_clientCore_guess->GetDisciplineTimer_guess(spell->id_1c0) > GetTime_guess());
					}
				} else if (type == 1) {
					(*button)->SetWindowText_guess(pinstCActionsWnd_guess->GetCombatPageButton_guess(HOTBAR_ENTRY(i).value_004)->GetText_guess());
					if (g_itemActivationState_guess == 0) {
						((CButtonWnd*)*button)->SetCheck(true);
					}
					if (g_autoCheck_guess != 0) {
						((CButtonWnd*)*button)->SetCheck(true);
					}
				} else if (type == 9) {
					int value = HOTBAR_ENTRY(i).value_004;
					if (value > 100) {
						(*button)->SetWindowText_guess(CXStr(g_chatUi_guess->GetInnateDesc_guess(value - 100)));
					} else if (value >= 0) {
						(*button)->SetWindowText_guess(CXStr(pStringTable->getString(g_skillInfo_guess[value]->nameId_000, 0)));
					}
					value = HOTBAR_ENTRY(i).value_004;
					if (value != -1) {
						if (value < 100) {
							((CButtonWnd*)*button)->SetCheck(g_skillInfo_guess[value]->kind_00a == 2 ? g_skillAttackReady_guess == 0 : g_skillOff_guess[value] == 0);
						} else if (value == 0x6f) {
							((CButtonWnd*)*button)->SetCheck(g_skillAttackReady_guess == 0);
						} else if (value == 0x72 || value == 0x73) {
							((CButtonWnd*)*button)->SetCheck(false);
						} else {
							((CButtonWnd*)*button)->SetCheck(g_display_guess->ticks_148 < g_player_guess->timers_1a8->field_10c);
						}
					}
				} else if (type == 2 || type == 3) {
				} else if (type == 6) {
					int value = HOTBAR_ENTRY(i).value_004;
					CXStr text("Menu Button");
					switch (value) {
					case 0: case 1: case 2: case 3: case 4: case 5: case 12: {
						ItemButton_guess* menu = pinstCActionsWnd_guess->GetMainPageButton_guess(value);
						if (menu != 0) {
							text = menu->GetText_guess();
						}
						break;
					}
					case 10:
						text = "Spells";
						break;
					}
					(*button)->SetWindowText_guess(text);
				} else if (type == 4) {
					if (HOTBAR_ENTRY(i).value_004 < 0x78) {
						SocialEntry_guess* social = &g_socialPages_guess[HOTBAR_ENTRY(i).value_004 / 12].entries[HOTBAR_ENTRY(i).value_004 % 12];
						(*button)->SetWindowText_guess(CXStr(social->text_000));
						(*button)->color_07c = pinstCSocialEditWnd_guess->GetColor_guess(social->color_510);
					} else {
						CXStr tip;
						Item_guess* item = g_itemManager_guess->Find_guess(g_clientCore_guess, HOTBAR_ENTRY(i).value_004 - 0x78);
						if (item != 0) {
							if (item->nameId_008 > 0) {
								tip = g_dbStrings_guess->GetString_guess(item->nameId_008, 2, 0);
							}
							if (item->descId_00c > 0) {
								tip += g_newline_guess;
								tip += g_dbStrings_guess->GetString_guess(item->descId_00c, 3, 0);
							}
							(*button)->SetWindowText_guess(tip);
							if (g_clientCore_guess->HasAltAbility_guess(item->id_000)) {
								int slotIndex = item->slot_03c;
								if (slotIndex < 0 || slotIndex >= 30 || g_clientCore_guess->GetSlotCount_guess(slotIndex) == 0) {
									((CButtonWnd*)*button)->SetCheck(false);
								} else {
									int count;
									g_itemManager_guess->Count_guess(g_clientCore_guess, item, &count);
									if (count > 0) {
										((CButtonWnd*)*button)->SetCheck(true);
									}
								}
							} else {
								((CButtonWnd*)*button)->SetCheck(true);
							}
						} else {
							// AA no longer known: tooltip "Not" / "Usable" (0x1F61, 0x1F62).
							tip = pStringTable->getString(0x1f61, 0);
							tip += g_newline_guess;
							tip += pStringTable->getString(0x1f62, 0);
							(*button)->SetWindowText_guess(tip);
						}
					}
				} else if (type == 11) {
					CXStr tip;
					int page = HOTBAR_ENTRY(i).value_004 / 8;
					int index = HOTBAR_ENTRY(i).value_004 % 8;
					if (page >= 0 && page < 31) {
						if (g_pageManager_guess->pages_000[page]->nameId_00c > 0) {
							tip = pStringTable->getString(g_pageManager_guess->pages_000[page]->nameId_00c, 0);
						}
						if (g_pageManager_guess->pages_000[page]->descId_010 > 0) {
							tip += g_newline_guess;
							tip += pStringTable->getString(g_pageManager_guess->pages_000[page]->descId_010, 0);
						}
						if (g_pageManager_guess->pages_000[page]->extraId_014 > 0) {
							tip += g_newline_guess;
							tip += pStringTable->getString(g_pageManager_guess->pages_000[page]->extraId_014, 0);
						}
						if (g_pageManager_guess->pages_000[page]->count_008 > 1) {
							char number[4];
							sprintf(number, g_slotFormat_guess, index);
							tip += number;
						}
						(*button)->SetWindowText_guess(tip);
						((CButtonWnd*)*button)->SetCheck(!g_pageManager_guess->CanUseAbility_guess(g_clientCore_guess, page, index));
					}
				} else if (type == 5) {
					if (*slot != 0) {
						int value = HOTBAR_ENTRY(i).value_004;
						SpellIcon_guess* icon = pinstCInvSlotMgr_guess->FindInvSlot(value);
						if (icon != 0) {
							(*slot)->SetIcon_guess(icon);
							(*slot)->value_120 = value;
							(*slot)->field_130 = icon->info_004->field_130;
							(*slot)->field_11c = icon->info_004->field_11c;
							(*slot)->field_12c = icon->field_008;
							(*slot)->SetPressed_guess(1, 0);
							(*button)->SetWindowText_guess(CXStr(g_emptyString_guess));
							((CButtonWnd*)*button)->SetCheck(true);
						} else {
							(*slot)->SetIcon_guess(0);
							(*slot)->value_120 = -1;
							(*slot)->SetPressed_guess(0, 1);
						}
					}
				} else if (type == 7) {
					SpellGem_guess** gem = (SpellGem_guess**)&spellGems_1c0[i];
					if (*gem != 0) {
						int gemIndex = HOTBAR_ENTRY(i).value_004;
						int icon = -1;
						unsigned int color = 0xff000000;
						if (IsValidSpell_guess(g_clientCore_guess->GetMemorizedSpell_guess(gemIndex))) {
							Spell_guess* spell = (Spell_guess*)g_textManager_guess->GetSpell_guess((const char*)g_clientCore_guess->GetMemorizedSpell_guess(gemIndex));
							icon = spell->icon_248;
							color = spell->GetColor_guess();
						}
						int oldIcon = (*gem)->spellIcon_188;
						(*gem)->SetSpellIcon_guess(icon);
						(*gem)->SetSpellGemTint_guess(color);
						(*gem)->SetPressed_guess(1, 0);
						if (IsValidSpell_guess(g_player_guess->timers_1a8->castingSpell_f98)
							|| !IsValidSpell_guess(g_clientCore_guess->GetMemorizedSpell_guess(gemIndex))
							|| g_display_guess->ticks_148 < g_player_guess->timers_1a8->gemReady_0e8[gemIndex]
							|| g_display_guess->ticks_148 <= g_player_guess->timers_1a8->field_110) {
							(*gem)->SetFadeMode_guess(1);
						} else if (oldIcon == -1 || (*gem)->state_18c == 1) {
							(*gem)->SetFadeMode_guess(2);
						}
						(*button)->SetWindowText_guess(CXStr(g_emptyString_guess));
						((CButtonWnd*)*button)->SetCheck(true);
					}
				} else if (type == 8) {
					ItemButton_guess* item = (ItemButton_guess*)pinstCPetInfoWnd_guess->GetButton_guess(HOTBAR_ENTRY(i).value_004);
					if (item != 0) {
						CXStr tip;
						((CXStrFormat_guess*)&tip)->Format_guess("%s %s", pStringTable->getString(0x1a2c, 0), (char*)item->GetText_guess());
						(*button)->SetWindowText_guess(tip);
					}
				}
			} else {
				(*button)->SetWindowText_guess(CXStr(g_emptyString_guess));
				((CButtonWnd*)*button)->SetCheck(true);
				(*button)->icon_16c = 0;
				(*button)->icon_174 = 0;
				(*button)->icon_170 = 0;
				(*button)->icon_17c = 0;
				(*slot)->SetIcon_guess(0);
				(*slot)->value_120 = -1;
				(*slot)->SetPressed_guess(0, 1);
				((SpellGem_guess*)spellGems_1c0[i])->SetSpellIcon_guess(-1);
				((SpellGem_guess*)spellGems_1c0[i])->SetPressed_guess(0, 1);
			}
		}
		field_200 = g_display_guess->ticks_148;
	}
	return ((CXWnd*)this)->OnProcessFrame();
}

struct CXPoint_guess {
	int x, y;
	CXPoint_guess() : x(0), y(0) {}
};

// EXTERNAL: TITANIUM 0x005ADC20 PopupManager_guess::Show_guess
struct PopupManager_guess {
	void Show_guess(int id, const CXPoint_guess& point, CHotButtonWnd_guess* owner);
};
#define g_popupManager_guess EQ_GLOBAL(PopupManager_guess*, 0x0099D414)

struct WndText_guess {
	// EXTERNAL: TITANIUM 0x00560D80 WndText_guess::GetEntryText_guess
	CXStr GetEntryText_guess() const;
};

struct InvSlotWnd_guess {
	char pad_000[0x11C];
	int value_11c;
};

// Cursor attachment window: mode at +0x15C, value at +0x160, clear is slot 0x88.
struct CCursorAttachmentView_guess : HotbuttonWindow_guess {
	char pad_004[0x158];
	int mode_15c;
	int value_160;
	// EXTERNAL: TITANIUM 0x004FD91E CCursorAttachmentView_guess::Attach_guess
	void Attach_guess(int owner, int kind, int value, const char* text, int id);
};
#define pinstCCursorAttachment_guess EQ_GLOBAL(CCursorAttachmentView_guess*, 0x00850C24)

struct ItemHolder_guess {
	char pad_000[0x48];
	int id_048;
	// EXTERNAL: TITANIUM 0x005ECCC0 ItemHolder_guess::GetItemClass_guess
	int GetItemClass_guess();
	// EXTERNAL: TITANIUM 0x005EC760 ItemHolder_guess::IsStackable_guess
	char IsStackable_guess();
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

struct EverQuestUi_guess {
	// EXTERNAL: TITANIUM 0x004B023B EverQuestUi_guess::SaveHotButtons_guess
	void SaveHotButtons_guess();
	// EXTERNAL: TITANIUM 0x00494DDC EverQuestUi_guess::RefreshHotbuttons_guess
	void RefreshHotbuttons_guess();
};
#define g_everQuestUi_guess EQ_GLOBAL(EverQuestUi_guess*, 0x00988DF0)

// Hot button file dialog.

#define g_hotbarDirty_guess EQ_ARRAY(char, 0x009839E5)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_serverName_guess EQ_ARRAY(char, 0x0095D3D4)

// EXTERNAL: TITANIUM 0x00574950 CompareNoCase_guess
int __cdecl CompareNoCase_guess(const char* a, const char* b);
// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
void __cdecl FormatString_guess(char* out, int id, const char* a1, const char* a2, const char* a3, const char* a4,
	const char* a5, const char* a6, const char* a7, const char* a8, const char* a9);
// EXTERNAL: TITANIUM 0x00576FA0 CopyString_guess
void __cdecl CopyString_guess(char* dest, const char* src, int size);
// EXTERNAL: TITANIUM 0x0060BEE0 WriteIniString_guess
void __cdecl WriteIniString_guess(const char* section, const char* key, const char* value, const char* file);

#define HB_ENTRY(i) g_hotbarEntries_guess[(i) + ((int)g_hotbarPageOffsets_guess[page_204] + page_204 * 10) * 10]
#define HB_DIRTY(i) g_hotbarDirty_guess[((int)g_hotbarPageOffsets_guess[page_204] + page_204 * 10) * 10 + (i)]

// Click: paging, or runs the button; with a hot-button attachment on the cursor (CCursorAttachment kind 4+)
// drops it here and picks up what was there. Right-click: SelectHotbutton_guess. 0x17 picks the button up;
// 0x18/0x1A on a gem open and close its spell display. 0x21 brings the name for Save (CTextEntryWnd), 0x14
// the file menu's items.
// FUNCTION: TITANIUM 0x0051550D
// @early-stop: budget, structural ndiff=406
int CHotButtonWnd_guess::WndNotification(CXWnd* sender, unsigned int message, int data) {
	if (sender == fileButton_1f0 && (message == 1 || message == 3 || message == 0x1a || message == 0x19)) {
		if (resourceId_1e8 != -1) {
			UpdateFileMenu_guess();
			CXPoint_guess point;
			CXRect rect = fileButton_1f0->GetScreenRect();
			point.y = (rect.bottom - rect.top) / 2 + rect.top;
			point.x = rect.right;
			g_popupManager_guess->Show_guess(resourceId_1e8, point, this);
		}
	} else if (message == 1) {
		int old = g_hotbarPageOffsets_guess[page_204];
		if (sender == pageLeftButton_160) {
			g_hotbarPageOffsets_guess[page_204]--;
		} else if (sender == pageRightButton_164) {
			g_hotbarPageOffsets_guess[page_204]++;
		}
		if (g_hotbarPageOffsets_guess[page_204] != old) {
			UpdatePageLabel_guess();
		}
		for (int i = 0; i < 10; ++i) {
			if (sender == buttons_170[i] || sender == invSlots_198[i] || sender == spellGems_1c0[i]) {
				if (pinstCCursorAttachment_guess->CanUse_guess() == 0 || pinstCCursorAttachment_guess->mode_15c < 4) {
					DoHotButton(i, 1);
				} else {
					int value = -1;
					int type = 0;
					CXStr text;
					if (HB_ENTRY(i).type_000 > 0) {
						value = HB_ENTRY(i).value_004;
						type = HB_ENTRY(i).type_000;
						text = ((ItemButton_guess*)sender)->GetText_guess();
					}
					switch (pinstCCursorAttachment_guess->mode_15c) {
					case 5:
						HB_ENTRY(i).type_000 = 6;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 4:
						HB_ENTRY(i).type_000 = 4;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 12:
						HB_ENTRY(i).type_000 = 10;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 13:
						HB_ENTRY(i).type_000 = 11;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 7:
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						HB_ENTRY(i).type_000 = HB_ENTRY(i).value_004 >= 2 ? 2 : 1;
						break;
					case 11:
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						HB_ENTRY(i).type_000 = 9;
						break;
					case 6:
						HB_ENTRY(i).type_000 = 3;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 8:
						HB_ENTRY(i).type_000 = 5;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 9:
						HB_ENTRY(i).type_000 = 7;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					case 10:
						HB_ENTRY(i).type_000 = 8;
						HB_ENTRY(i).value_004 = pinstCCursorAttachment_guess->value_160;
						break;
					}
					if (type > 0) {
						int kind = type;
						switch (type) {
						case 1: kind = 7; break;
						case 2: value += 2; kind = 7; break;
						case 3: kind = 6; break;
						case 4: kind = 4; break;
						case 5: kind = 8; break;
						case 6: kind = 5; break;
						case 7: kind = 9; break;
						case 8: kind = 10; break;
						case 9: kind = 11; break;
						case 10: kind = 12; break;
						case 11: kind = 13; break;
						}
						if (kind == 8) {
							int id = -1;
							if (g_clientCore_guess != 0 && g_clientCore_guess->GetInventorySlot_guess(value) != 0
								&& g_clientCore_guess->GetInventorySlot_guess(value)->GetItemClass_guess() == 0
								&& g_clientCore_guess->GetInventorySlot_guess(value)->IsStackable_guess()) {
								id = g_clientCore_guess->GetInventorySlot_guess(value)->id_048;
							}
							pinstCCursorAttachment_guess->Attach_guess(((InvSlotWnd_guess*)invSlots_198[i])->value_11c, 8, value, text, id);
						} else {
							pinstCCursorAttachment_guess->Attach_guess(0, kind, value, text, -1);
						}
					} else {
						pinstCCursorAttachment_guess->Action88_guess();
					}
					HB_DIRTY(i) = 1;
					g_everQuestUi_guess->SaveHotButtons_guess();
				}
				break;
			}
		}
	} else if (message == 3) {
		for (int i = 0; i < 10; ++i) {
			if (sender == buttons_170[i] || sender == spellGems_1c0[i]) {
				SelectHotbutton_guess(i);
				break;
			}
		}
	} else if (message == 0x17) {
		for (int i = 0; i < 10; ++i) {
			if (sender == buttons_170[i] || sender == invSlots_198[i] || sender == spellGems_1c0[i]) {
				if (pinstCCursorAttachment_guess->CanUse_guess() == 0 && HB_ENTRY(i).type_000 > 0) {
					int value = HB_ENTRY(i).value_004;
					int kind = -1;
					switch (HB_ENTRY(i).type_000) {
					case 1: kind = 7; break;
					case 2: value += 2; kind = 7; break;
					case 3: kind = 6; break;
					case 4: kind = 4; break;
					case 5: {
						int id = -1;
						if (g_clientCore_guess != 0 && g_clientCore_guess->GetInventorySlot_guess(value) != 0
							&& g_clientCore_guess->GetInventorySlot_guess(value)->GetItemClass_guess() == 0
							&& g_clientCore_guess->GetInventorySlot_guess(value)->IsStackable_guess()) {
							id = g_clientCore_guess->GetInventorySlot_guess(value)->id_048;
						}
						CXStr text = ((ItemButton_guess*)sender)->GetText_guess();
						pinstCCursorAttachment_guess->Attach_guess(((InvSlotWnd_guess*)invSlots_198[i])->value_11c, 8, value, text, id);
						break;
					}
					case 6: kind = 5; break;
					case 7: kind = 9; break;
					case 8: kind = 10; break;
					case 9: kind = 11; break;
					case 10: kind = 12; break;
					case 11: kind = 13; break;
					}
					if (kind != -1) {
						CXStr text = ((ItemButton_guess*)sender)->GetText_guess();
						pinstCCursorAttachment_guess->Attach_guess(0, kind, value, text, -1);
					}
					HB_ENTRY(i).type_000 = 0;
					HB_ENTRY(i).value_004 = -1;
					HB_DIRTY(i) = 1;
					g_everQuestUi_guess->SaveHotButtons_guess();
				}
				break;
			}
		}
	} else if (message == 0x18) {
		for (int i = 0; i < 10; ++i) {
			if (sender == spellGems_1c0[i]
				&& IsValidSpell_guess(g_clientCore_guess->GetMemorizedSpell_guess(HB_ENTRY(i).value_004))) {
				pinstCItemDisplayManager_guess->Set_guess(g_clientCore_guess->GetMemorizedSpell_guess(HB_ENTRY(i).value_004),
					(pinstCXWndManager_guess->GetKeyboardFlags() & 1) == 0, 1, -1);
				break;
			}
		}
	} else if (message == 0x1a) {
		for (int i = 0; i < 10; ++i) {
			if (sender == spellGems_1c0[i]) {
				pinstCItemDisplayManager_guess->CloseNewestItemDisplay_guess();
				break;
			}
		}
	} else if (message == 0x21) {
		if (data == 1) {
			CXStr name = ((WndText_guess*)sender)->GetEntryText_guess();
			slot_1ec = -1;
			int index = 0;
			for (HotButtonSet_guess* entry = g_entries_guess; entry < &g_entries_guess[100]; ++index, ++entry) {
				if (entry->enabled_019 != 0 && CompareNoCase_guess(name, entry->name_000) == 0) {
					slot_1ec = index;
					break;
				}
				if (slot_1ec == -1 && entry->enabled_019 == 0) {
					slot_1ec = index;
				}
			}
			if (slot_1ec == -1) {
				char errorText[0x200];
				// "You have reached the limit of 100 hotbutton sets."
				FormatString_guess(errorText, 0x1f46, _itoa(100, g_itoaBuffer_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
				pEverQuest->dsp_chat(errorText, 0xd, 1);
				return 0;
			}
			g_entries_guess[slot_1ec].enabled_019 = 1;
			g_entries_guess[slot_1ec].flag_01a = 1;
			g_entries_guess[slot_1ec].index_01c = slot_1ec;
			CopyString_guess(g_entries_guess[slot_1ec].name_000, name, 0x18);
			CXStr key;
			CXStr value;
			CXStr file;
			((CXStrFormat_guess*)&file)->Format_guess(".\\%s\\HB_%d_%s_%s.ini", "userdata", slot_1ec,
				g_clientCore_guess->name_03c, g_serverName_guess);
			for (int page = 0; page < 10; ++page) {
				for (int slot = 0; slot < 10; ++slot) {
					HotbarEntry_guess* entry = &g_hotbarEntries_guess[slot + (page + page_204 * 10) * 10];
					// Each slot is saved as type letter plus value; empty ones delete their key.
					((CXStrFormat_guess*)&key)->Format_guess("Page%d.Slot%d", page + 1, slot + 1);
					if (entry->type_000 != 0) {
						((CXStrFormat_guess*)&value)->Format_guess("%c%d", entry->type_000 + 'A', entry->value_004);
						WriteIniString_guess("Hotbuttons", key, value, file);
					} else {
						WriteIniString_guess("Hotbuttons", key, 0, file);
					}
				}
			}
			char text[0x200];
			FormatString_guess(text, 0x1f47, g_entries_guess[slot_1ec].name_000, 0, 0, 0, 0, 0, 0, 0, 0);
			g_everQuestUi_guess->RefreshHotbuttons_guess();
			UpdateFileMenu_guess();
			pEverQuest->dsp_chat(text, 0xf, 1);
		}
	} else if (message == 0x14) {
		if (data >= 0x17d4 && data < 0x17de) {
			field_208 = data - 0x17d4;
			pConfirmationDialogPool_guess->Activate(static_cast<Secondary_guess*>(this), 0x7f,
				pStringTable->getString(0x1f5e, 0), 0xc, -1, (int)&field_208, 0);
			return 0;
		}
		if (data >= 0x1838 && data < 0x1842) {
			field_208 = data - 0x1838;
			pConfirmationDialogPool_guess->Activate(static_cast<Secondary_guess*>(this), 0x80,
				pStringTable->getString(0x1f5f, 0), 0xc, -1, (int)&field_208, 0);
			return 0;
		}
		if (data == 0x189c) {
			if (pinstCTextEntryWnd_guess != 0) {
				pinstCTextEntryWnd_guess->Activate_guess(this, 0, pStringTable->getString(0x1f48, 0), 1, 0x18, g_emptyString_guess);
			}
			return 0;
		}
		if (data == 0x1900) {
			pConfirmationDialogPool_guess->Activate(static_cast<Secondary_guess*>(this), 0x81,
				pStringTable->getString(0x1f5d, 0), 0xc, -1, 0, 0);
			return 0;
		}
	}
	return ((CSidlScreenWnd*)this)->WndNotification(sender, message, (void*)data);
}
