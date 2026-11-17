// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 169: a hint from compare/tumap.py.
// CInspectWnd_guess ("InspectWnd" screen): shows another player's 22 worn items and inspect text from an
// OP_InspectAnswer packet; InspectResponseView_guess is EQEmu's InspectResponse_Struct (names[22][64],
// icons[22],
// text). CDisplayView_guess is CDisplay (0x905D24) and FUN_00401b28_guess the spawn-by-id table (0x900F50).
#include "titanium/types.h"
#include "titanium/crt.h"

struct Thing_guess {
	char name_guess[0xBC];
	int value_guess;
	char pad_guess[0x204];

	// EXTERNAL: TITANIUM 0x00601F60 Thing_guess::Thing_guess
	Thing_guess();
};

struct ItemEntry_guess {
	char text_guess[0x40];
};

struct InspectResponseView_guess {
	int pad_guess[2];
	ItemEntry_guess entries_guess[0x16];
	int values_guess[0x16];
	char text_guess[0x80];
};

struct Obj_guess {
	virtual void Slot00_guess(int flags);
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
	virtual void Slot57_guess();
	virtual void Slot58_guess();
	virtual void Slot59_guess();
	virtual void Slot60_guess();
	virtual void Slot61_guess();
	virtual void Slot62_guess();
	virtual void Slot63_guess(const CXStr& text);
	virtual void Slot64_guess();
	virtual void Slot65_guess();
	virtual void Slot66_guess();
	virtual void Slot67_guess();
	virtual void Slot68_guess();
	virtual void Slot69_guess();
	virtual void Slot70_guess();
	virtual void Slot71_guess();
	virtual void Slot72_guess();
	virtual void Slot73_guess();
	virtual void Slot74_guess();
	virtual void Slot75_guess();
	virtual CXStr Slot76_guess();
	char pad_guess[0x59];
	char flag5D_guess;
	// EXTERNAL: TITANIUM 0x005ECE20 Obj_guess::Obj_guess
	Obj_guess();
};

// EXTERNAL: TITANIUM 0x00644780 ??_7EQ_Item_guess@@6B@
struct EQ_Item_guess : Obj_guess {
	char pad_guess[0x48];
	EQ_Item_guess() {}
	// EXTERNAL: TITANIUM 0x005EC620 EQ_Item_guess::Attach_guess
	void Attach_guess(Thing_guess* thing);
};

struct Mgr_guess {
	// EXTERNAL: TITANIUM 0x004B078C Mgr_guess::saveCustom_guess
	void saveCustom_guess();
};

struct CDisplayView_guess {
	char pad_guess[0x148];
	unsigned int tick_guess;
	// EXTERNAL: TITANIUM 0x00439D16 CDisplayView_guess::PlayerDistance_guess
	float PlayerDistance_guess(int a, int b, float c);
};

// EXTERNAL: TITANIUM 0x0060E450 Copy_guess
void __cdecl Copy_guess(char* dst, void* src);

// EXTERNAL: TITANIUM 0x005A2230 FUN_005a2230_guess
int __stdcall FUN_005a2230_guess(int value, int code, int arg);

// Polymorphic base of the window: its vtable slots are the window's 35 slots, in order. The CSidlScreenWnd
// ctor (0x5A3900) runs first; the window's own ctor then stores its vtable over this one.
struct Wnd_guess {
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
	virtual void Slot57_guess();
	virtual void Slot58_guess();
	virtual void Slot59_guess();
	virtual void Slot60_guess();
	virtual void Slot61_guess();
	virtual void Slot62_guess();
	virtual void Slot63_guess(const CXStr& text);
	// EXTERNAL: TITANIUM 0x005A3900 Wnd_guess::Wnd_guess
	Wnd_guess(CXWnd* parent, const CXStr& screen);
	// EXTERNAL: TITANIUM 0x005A3100 Wnd_guess::~Wnd_guess
	~Wnd_guess();   /* non-virtual: keeps the slot numbers; the derived ctor's unwind calls it */
	// EXTERNAL: TITANIUM 0x005A1E10 Wnd_guess::GetChildItem
	CXWnd* GetChildItem(const CXStr& name);
	// EXTERNAL: TITANIUM 0x005A25B0 Wnd_guess::CreateChildrenFromSidl
	void CreateChildrenFromSidl();
};

struct Piece_guess {
	char pad_guess[0x60];
	unsigned int field60_guess;
};

struct Edit_guess {
	// EXTERNAL: TITANIUM 0x004D7EBC Edit_guess::SetMaxChars_guess
	void SetMaxChars_guess(int max);
};

// The window's vtable at 0x656278 is stored by its ctor, after the base ctor.
// EXTERNAL: TITANIUM 0x00656278 ??_7CInspectWnd_guess@@6B@
struct CInspectWnd_guess : Wnd_guess {
	CInspectWnd_guess(CXWnd* parent);

	char pad_guess[0x58];
	char flag5C_guess;
	char pad_5D_guess[7];
	unsigned int field64_guess;
	char pad_68_guess[0xBC];
	Piece_guess* piece124_guess;
	char pad_128_guess[0x34];
	unsigned int field15C_guess;
	int inspectedPlayer_0160_guess;
	int data_guess[0x16];
	Obj_guess* obj1bc_guess;
	int value1c0_guess;

	// EXTERNAL: TITANIUM 0x005A0E50 CInspectWnd_guess::OnProcessFrame
	void OnProcessFrame();

	void OnProcessFrame_guess();
	void InitializeInspectWindowData_guess();
	void AcceptInspectText_guess();
	void PlayerBeingDeleted_guess(int value);
	bool AboutToHide_guess();
	int WndNotification_guess(int value, int code, int arg);
	// EXTERNAL: TITANIUM 0x005A0A80 CInspectWnd_guess::Refresh_guess
	int Refresh_guess(int first, int second);
	int SetInspectAnswer_guess(InspectResponseView_guess* item);
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
int __cdecl FUN_00401b28_guess(int value);

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* text, int id, int value, int a4, int a5, int a6,
	int a7, int a8, int a9, int a10, int a11);

// Once a second while shown, hides the window when the inspected spawn is over 20 units from the player.
// FUNCTION: TITANIUM 0x00516665
void CInspectWnd_guess::OnProcessFrame_guess()
{
	if (flag5C_guess != 0) {
		unsigned int* due = &field15C_guess;
		unsigned int tick = EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)->tick_guess;
		if (tick >= *due) {
			*due = tick + 1000;
			if (inspectedPlayer_0160_guess != 0) {
				if (EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)->PlayerDistance_guess(inspectedPlayer_0160_guess, EQ_GLOBAL(int, 0x00905CE4), 1.0f) > 20.0f)
					Slot34_guess();
			}
		}
	}
	OnProcessFrame();
}

// INSW_Edit holds the inspect text: 254 characters, or 84 when 0x923D74 is set.
// FUNCTION: TITANIUM 0x0051675E
CInspectWnd_guess::CInspectWnd_guess(CXWnd* parent)
	: Wnd_guess(parent, "InspectWnd")
{
	InitializeInspectWindowData_guess();
	if (piece124_guess != 0) {
		field64_guess |= piece124_guess->field60_guess;
		CreateChildrenFromSidl();
		obj1bc_guess = (Obj_guess*)GetChildItem("INSW_Edit");
		if (obj1bc_guess != 0) {
			if (EQ_GLOBAL(int, 0x00923D74) == 0)
				((Edit_guess*)obj1bc_guess)->SetMaxChars_guess(0xfe);
			else
				((Edit_guess*)obj1bc_guess)->SetMaxChars_guess(0x54);
		}
		value1c0_guess = (int)GetChildItem("DoneButton");
	}
}

// Forgets the inspected spawn, the range-check time and the 22 item entries (no deletes).
// FUNCTION: TITANIUM 0x0051638B
void CInspectWnd_guess::InitializeInspectWindowData_guess()
{
	inspectedPlayer_0160_guess = 0;
	field15C_guess = 0;
	int* p = data_guess;
	for (int count = 0x16; count != 0; --count)
		*p++ = 0;
}

// Fills the window from an InspectResponse: title "You are inspecting %1." (string 1401), or "%1 is too far
// away to inspect" (1402) in chat beyond 20 units. The text box is editable only when inspecting yourself.
// Each non-empty item name gets a 0xA8-byte entry around a 0x2C4-byte item holding the name and icon;
// neither allocation is null-checked before use (original).
// FUNCTION: TITANIUM 0x005163A9
// @early-stop: unknown, structural ndiff=74
int CInspectWnd_guess::SetInspectAnswer_guess(InspectResponseView_guess* item)
{
	if (flag5C_guess == 0)
		InitializeInspectWindowData_guess();
	if (item == 0)
		return Refresh_guess(1, 1);

	char text[512] = { 0 };
	inspectedPlayer_0160_guess = FUN_00401b28_guess(item->pad_guess[1]);
	if (inspectedPlayer_0160_guess == 0)
		return -1;

	if (EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)->PlayerDistance_guess(
		inspectedPlayer_0160_guess, EQ_GLOBAL(int, 0x00905CF8), 1.0f) > 20.0f) {
		Format_guess(text, 0x57A, inspectedPlayer_0160_guess + 0x120, 0, 0, 0, 0, 0, 0, 0, 0);
		EQ_GLOBAL(CEverQuest*, 0x00988DF0)->dsp_chat(text, 0x111, true);
		return -1;
	}

	Format_guess(text, 0x579, inspectedPlayer_0160_guess + 0x120, 0, 0, 0, 0, 0, 0, 0, 0);
	{
		CXStr label(text);
		Slot63_guess(label);
	}

	if (obj1bc_guess != 0) {
		if (inspectedPlayer_0160_guess == EQ_GLOBAL(int, 0x00905CE4))
			obj1bc_guess->flag5D_guess = 1;
		else {
			if (flag5C_guess == 0)
				EQ_GLOBAL(CEverQuest*, 0x00988DF0)->dsp_chat(text, 10, true);
			obj1bc_guess->flag5D_guess = 0;
		}
		obj1bc_guess->Slot63_guess(item->text_guess);
	}

	Obj_guess** output = (Obj_guess**)data_guess;
	char* entryText = item->entries_guess[0].text_guess;
	int* itemValue = item->values_guess;
	int count = 0x16;
	do {
		if (*entryText != 0) {
			void* entryMemory = operator new(0xA8);
			EQ_Item_guess* entry = 0;
			if (entryMemory != 0)
				entry = new (entryMemory) EQ_Item_guess;

			void* thingMemory = operator new(0x2C4);
			Thing_guess* thing = 0;
			if (thingMemory != 0)
				thing = new (thingMemory) Thing_guess;
			strcpy(thing->name_guess, entryText);
			thing->value_guess = *itemValue;
			entry->Attach_guess(thing);
			*output = entry;
		}
		++output;
		entryText += 0x40;
		++itemValue;
		--count;
	} while (count != 0);
	return Refresh_guess(1, 1);
}

// Inspecting yourself: copies the edited text to your inspect message (0x985708) and saves it to the ini.
// FUNCTION: TITANIUM 0x005166CD
void CInspectWnd_guess::AcceptInspectText_guess()
{
	if (inspectedPlayer_0160_guess == EQ_GLOBAL(int, 0x00905CE4) && obj1bc_guess != 0) {
		Copy_guess(EQ_ARRAY(char, 0x00985708), (char*)obj1bc_guess->Slot76_guess());
		EQ_GLOBAL(Mgr_guess*, 0x00988DF0)->saveCustom_guess();
	}
}

// Hides the window when the inspected spawn goes away.
// FUNCTION: TITANIUM 0x00516747
void CInspectWnd_guess::PlayerBeingDeleted_guess(int value)
{
	if (value == inspectedPlayer_0160_guess)
		Slot34_guess();
}

// Saves your own inspect text, then deletes the 22 item entries.
// FUNCTION: TITANIUM 0x0051686E
bool CInspectWnd_guess::AboutToHide_guess()
{
	AcceptInspectText_guess();
	Obj_guess** slot = (Obj_guess**)data_guess;
	for (int count = 0x16; count != 0; --count, ++slot) {
		if (*slot != 0) {
			(*slot)->Slot00_guess(1);
			*slot = 0;
		}
	}
	return true;
}

// Enter in the text box (6) saves your inspect text; a DoneButton click (1) hides the window.
// FUNCTION: TITANIUM 0x0051689A
int CInspectWnd_guess::WndNotification_guess(int value, int code, int arg)
{
	if (code == 6) {
		if (value == (int)obj1bc_guess) {
			AcceptInspectText_guess();
			return 0;
		}
	}
	else if (code == 1 && value == value1c0_guess) {
		Slot34_guess();
		return 0;
	}
	return FUN_005a2230_guess(value, code, arg);
}
