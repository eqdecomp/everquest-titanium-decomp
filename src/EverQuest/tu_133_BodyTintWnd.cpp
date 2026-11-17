// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 133: a hint from compare/tumap.py.
// CBodyTintWnd ("BodyTintWnd"): armor dyeing. Seven wear slots (head, chest, arms, wrist, hands,
// legs, feet; indexes 7-8 stay null) each have a dye button (TINT_*Btn) and the item's own colour
// (TINT_O*ColorBtn). Each changed slot costs one dye (item 32557, probably Prismatic Dye); Save sends
// OP_Dye. CBodyTintWndView_guess, ValidationCallback_guess and ColorWindow_guess are views of this window.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include <string.h>
#include "titanium/wnd/CColorPickerWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CFacePick.h"

struct TintControl_guess : CXWnd
{
	char pad_11c_guess[0x20];
	int tint_13c_guess;
};

struct SidlPiece_guess
{
	char pad_000_guess[0x60];
	unsigned int flags_060_guess;
};

struct ByteAtTwo_guess
{
	unsigned short pad_000_guess;
	unsigned char field_002_guess;
};

struct BodyTintBase_guess
{
	char pad_004_guess[0x10];
	unsigned char field_014_guess;
	char pad_015_guess[0x4b];
	int field_060_guess;
	int windowStyle_0064_guess;
	char pad_068_guess[0xbc];
	void* sidlPiece_124_guess;
	char pad_128_guess[0x30];
	int field_158_guess;

	// EXTERNAL: TITANIUM 0x005A3900 BodyTintBase_guess::BodyTintBase_guess
	BodyTintBase_guess(CXWnd* parent_guess, const CXStr& name_guess);
	// EXTERNAL: TITANIUM 0x005A3100 BodyTintBase_guess::~BodyTintBase_guess
	virtual ~BodyTintBase_guess();
	virtual void Slot_guess() {}
};

// EXTERNAL: TITANIUM 0x006511B8 ??_7CBodyTintWnd_guess@@6B@
struct CBodyTintWnd_guess : BodyTintBase_guess
{
	int dyesAvailable_015c_guess;
	int selectedSlot_0160_guess;
	int dyesNeeded_0164_guess;
	int tint_168_guess;
	CXWnd* reagentsNeeded_16c_guess;
	CXWnd* reagentsLabel_170_guess;
	CXWnd* saveTint_174_guess;
	CXWnd* originalColors_178_guess[9];
	CXWnd* buttons_19c_guess[9];
	CXWnd* resetTint_1c0_guess;
	CXWnd* brush_1c4_guess;
	virtual void Slot_guess() {}
	CBodyTintWnd_guess(CXWnd* parent_guess);
	// EXTERNAL: TITANIUM 0x004E7579 CBodyTintWnd_guess::CountDyesAvailable_guess
	void CountDyesAvailable_guess();
	void UpdateReagents_guess();
	bool AboutToShow_guess();
	void UpdateBrush_guess(bool visible_guess);
	void SetTint_guess(int tint_guess);
	void ResetTints_guess();
	bool AboutToHide_guess();
	int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, unsigned int data_guess);
};

// Binds the TINT_ children; the brush colour (+0x168) starts unset (-1).
// FUNCTION: TITANIUM 0x004E6E5D
CBodyTintWnd_guess::CBodyTintWnd_guess(CXWnd* parent_guess)
	: BodyTintBase_guess(parent_guess, "BodyTintWnd")
{
	field_014_guess = 0xff;
	((ByteAtTwo_guess*)&windowStyle_0064_guess)->field_002_guess |= 1;
	tint_168_guess |= -1;
	field_158_guess = 8;
	selectedSlot_0160_guess = 0;
	dyesAvailable_015c_guess = 0;
	dyesNeeded_0164_guess = 0;
	reagentsNeeded_16c_guess = 0;
	reagentsLabel_170_guess = 0;
	saveTint_174_guess = 0;
	resetTint_1c0_guess = 0;
	brush_1c4_guess = 0;
	for (int i_guess = 0; i_guess < 9; ++i_guess)
	{
		originalColors_178_guess[i_guess] = 0;
		buttons_19c_guess[i_guess] = 0;
	}
	if (sidlPiece_124_guess != 0)
	{
		windowStyle_0064_guess |= ((SidlPiece_guess*)sidlPiece_124_guess)->flags_060_guess;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		saveTint_174_guess = ((CSidlScreenWnd*)this)->GetChildItem("TINT_SaveTint");
		// "Bodyt" is the real SIDL name; don't fix the spelling.
		resetTint_1c0_guess = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ResetBodytTint");
		brush_1c4_guess = ((CSidlScreenWnd*)this)->GetChildItem("TINT_CurBrushBtn");
		if (brush_1c4_guess != 0)
			((TintControl_guess*)brush_1c4_guess)->tint_13c_guess = tint_168_guess;
		for (int i_guess = 0; i_guess < 9; ++i_guess)
			buttons_19c_guess[i_guess] = 0;
		reagentsNeeded_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ReagentsNeeded");
		reagentsLabel_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ReagentsLabel");
		buttons_19c_guess[0] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_HeadBtn");
		buttons_19c_guess[4] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_HandsBtn");
		buttons_19c_guess[3] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ForeArmBtn");
		buttons_19c_guess[2] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ArmsBtn");
		buttons_19c_guess[1] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_ChestBtn");
		buttons_19c_guess[6] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_FeetBtn");
		buttons_19c_guess[5] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_LegsBtn");
		originalColors_178_guess[0] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OHeadColorBtn");
		originalColors_178_guess[4] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OHandsColorBtn");
		originalColors_178_guess[3] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OForeArmColorBtn");
		originalColors_178_guess[2] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OArmsColorBtn");
		originalColors_178_guess[1] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OChestColorBtn");
		originalColors_178_guess[6] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OFeetColorBtn");
		originalColors_178_guess[5] = ((CSidlScreenWnd*)this)->GetChildItem("TINT_OLegsColorBtn");
		buttons_19c_guess[7] = 0;
		buttons_19c_guess[8] = 0;
		originalColors_178_guess[7] = 0;
		originalColors_178_guess[8] = 0;
	}
}

struct ColorWindow_guess
{
	char pad_000_guess[0x5c];
	char active_05c_guess;

	// EXTERNAL: TITANIUM 0x005A1880 ColorWindow_guess::OnShow
	void OnShow();
	// EXTERNAL: TITANIUM 0x004E739A ColorWindow_guess::FormatColor_guess
	char* FormatColor_guess(unsigned int color_guess, char* output_guess);
	void UpdateColor_guess();
};


// When +0x5C is set, shows context tip 8 in the tip window (0x9928E0) before finishing.
// FUNCTION: TITANIUM 0x004E7376
void ColorWindow_guess::UpdateColor_guess()
{
	if (active_05c_guess != 0 && pinstCTipWndCONTEXT_guess != 0)
		pinstCTipWndCONTEXT_guess->selectTip_guess(8, 0);
	OnShow();
}

// Tooltip text "R = r, G = g, B = b" for an ARGB colour.
// FUNCTION: TITANIUM 0x004E739A
char* ColorWindow_guess::FormatColor_guess(unsigned int color_guess, char* output_guess)
{
	sprintf(output_guess, "R = %d, G = %d, B = %d", (color_guess >> 16) & 0xff,
		(color_guess >> 8) & 0xff, color_guess & 0xff);
	return output_guess;
}

struct ItemEntry_guess
{
	char pad_000_guess[0x5d];
	char flag_05d_guess;
	char pad_05e_guess[0x78 - 0x5e];
	CXStr text_078_guess;
	char pad_07c_guess[0x13c - 0x7c];
	int tint_013c_guess;
};

struct ContextObject_guess
{
	// EXTERNAL: TITANIUM 0x005F05E0 ContextObject_guess::IsReady_guess
	int IsReady_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x005F09D0 ContextObject_guess::SetSlotValue_guess
	void SetSlotValue_guess(int index_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x0043DA4A ContextObject_guess::GetSlotValue_guess
	int GetSlotValue_guess(int index_guess);
};

struct EQPlayerView_guess
{
	char pad_000_guess[0x1bc];
	int values_1bc_guess[1];

	// EXTERNAL: TITANIUM 0x0047A3D0 EQPlayerView_guess::GetArmorType_guess
	int GetArmorType_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x0047A406 EQPlayerView_guess::SetArmorTint_guess
	void SetArmorTint_guess(int index_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x004845D8 EQPlayerView_guess::HandleMaterialEx_guess
	void HandleMaterialEx_guess(int index_guess, int first_guess, int second_guess, int value_guess, int flag_guess);
};

struct ValidationCallback_guess
{
	char pad_000_guess[0x160];
	int index_160_guess;

	void Update_guess(int value_guess);
};

struct CBodyTintWndView_guess
{
	char pad_000_guess[0x15c];
	int field_15c_guess;
	char pad_160_guess[4];
	int dyesNeeded_0164_guess;
	int selectedColor_0168_guess;
	char pad_16c_guess[0xc];
	ItemEntry_guess* slots_178_guess[9];
	ItemEntry_guess* entries_19c_guess[9];
	char pad_1c0_guess[4];
	ItemEntry_guess* selectedEntry_01c4_guess;

	int GetSlotTint_guess(int index_guess);
	void SendSlots_guess();
	void CountDyesNeeded_guess();
};

#define g_contextObject_guess EQ_GLOBAL(ContextObject_guess*, 0x00905D00)
#define g_validationState_guess EQ_GLOBAL(int*, 0x00905CE4)
#define g_validationStateObject_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)
#define g_connection_guess EQ_GLOBAL(int, 0x00905CA0)

// Previews tint `value_guess` on the player's model for wear slot +0x160: stores it (SetArmorTint at
// 0x47A406) and re-applies the slot's material without sending OP_WearChange (last argument 1). Slots
// with nothing worn and no material are skipped.
// FUNCTION: TITANIUM 0x004E73C7
void ValidationCallback_guess::Update_guess(int value_guess)
{
	if (g_validationStateObject_guess == 0)
		return;
	if ((g_contextObject_guess == 0 || g_contextObject_guess->IsReady_guess(index_160_guess) == 0) &&
		g_validationStateObject_guess->GetArmorType_guess(index_160_guess) == 0)
		return;
	g_validationStateObject_guess->SetArmorTint_guess(index_160_guess, value_guess);
	int valueAtIndex_guess = g_validationStateObject_guess->values_1bc_guess[index_160_guess];
	g_validationStateObject_guess->HandleMaterialEx_guess(index_160_guess,
		g_validationStateObject_guess->GetArmorType_guess(index_160_guess),
		g_validationStateObject_guess->GetArmorType_guess(index_160_guess),
		valueAtIndex_guess, 1);
}

// Dye colour of slot button `index_guess`; -1 means no dye.
// FUNCTION: TITANIUM 0x004E745E
int CBodyTintWndView_guess::GetSlotTint_guess(int index_guess)
{
	int value_guess = 0;
	ItemEntry_guess* entry_guess = entries_19c_guess[index_guess];
	if (entry_guess != 0)
		value_guess = entry_guess->tint_013c_guess;
	return value_guess;
}

// Save: when enough dyes are on hand, stores the nine tints in the profile (no dye as 0) and sends them
// as OP_Dye (0xDD, 9 ints).
// FUNCTION: TITANIUM 0x004E7478
void CBodyTintWndView_guess::SendSlots_guess()
{
	int values_guess[9];
	int index_guess = 0;
	if (g_contextObject_guess != 0 && g_validationState_guess != 0)
	{
		memset(values_guess, 0, sizeof(values_guess));
		if (dyesNeeded_0164_guess <= field_15c_guess)
		{
			ItemEntry_guess** entry_guess = entries_19c_guess;
			for (index_guess = 0; index_guess < 9; index_guess++, entry_guess++)
			{
				if (*entry_guess != 0)
				{
					if ((*entry_guess)->tint_013c_guess == -1)
					{
						g_contextObject_guess->SetSlotValue_guess(index_guess, 0);
						values_guess[index_guess] = 0;
					}
					else
					{
						int value_guess = GetSlotTint_guess(index_guess);
						values_guess[index_guess] = value_guess;
						g_contextObject_guess->SetSlotValue_guess(index_guess, value_guess);
					}
				}
			}
			EQSendMessage(&g_connection_guess, OP_Dye, values_guess, sizeof(values_guess), 1);
		}
	}
}

// Dyes needed (+0x164): one for each slot whose button colour differs from the profile's tint.
// FUNCTION: TITANIUM 0x004E7525
void CBodyTintWndView_guess::CountDyesNeeded_guess()
{
	dyesNeeded_0164_guess = 0;
	if (g_contextObject_guess != 0)
	{
		int index_guess = 0;
		ItemEntry_guess** entry_guess = entries_19c_guess;
		for (; index_guess < 9; index_guess++, entry_guess++)
		{
			if (*entry_guess != 0)
			{
				int remote_guess = g_contextObject_guess->GetSlotValue_guess(index_guess);
				int local_guess = (*entry_guess)->tint_013c_guess;
				if (local_guess == -1)
					local_guess = 0;
				if (remote_guess != local_guess)
					dyesNeeded_0164_guess++;
			}
		}
	}
}

struct OffsetBlock_guess
{
	char pad_000_guess[4];
	int vbaseOffset_0004_guess;
};

struct GlobalBlock_guess
{
	char pad_000_guess[8];
	union
	{
		OffsetBlock_guess* offsetBlock_guess;
		char objectData_guess[1];
	} field_008_guess;
};

struct QueryResult_guess
{
	char pad_000_guess[0x48];
	int field_048_guess;

	// EXTERNAL: TITANIUM 0x005ECCC0 QueryResult_guess::GetItemClass_guess
	int GetItemClass_guess();
	// EXTERNAL: TITANIUM 0x005E0F30 QueryResult_guess::GetItemId_guess
	int GetItemId_guess();
	// EXTERNAL: TITANIUM 0x005ECC30 QueryResult_guess::GetCount_guess
	int GetCount_guess();
	// EXTERNAL: TITANIUM 0x005EC630 QueryResult_guess::GetEntry_guess
	QueryResult_guess* GetEntry_guess(int index_guess);

	// EXTERNAL: TITANIUM 0x005E0B90 QueryResult_guess::Read_guess
	int Read_guess();
};

struct QueryObject_guess
{
	// EXTERNAL: TITANIUM 0x0040CC50 QueryObject_guess::GetInventorySlot_guess
	QueryResult_guess* GetInventorySlot_guess(int argument_guess);
	// EXTERNAL: TITANIUM 0x004BC5B5 QueryObject_guess::GetBodyTint_guess
	int GetBodyTint_guess(int argument_guess);
};

struct UnknownOwner_guess
{
	int GetInvSlotItemColor_guess(int argument_guess);
};

#define g_globalBlock_guess EQ_GLOBAL(GlobalBlock_guess*, 0x00905D00)

// Dyes on hand (+0x15C): the count (+0x48) of every dye (item 32557) in bag slots 22-29 and
// inside those bags.
// FUNCTION: TITANIUM 0x004E7579
// @early-stop: budget, diff ndiff=15
void CBodyTintWnd_guess::CountDyesAvailable_guess()
{
	QueryResult_guess* container_guess;
	dyesAvailable_015c_guess = 0;
	if (g_globalBlock_guess != 0)
	{
		for (int itemIndex_guess = 0x16; itemIndex_guess <= 0x1d; itemIndex_guess++)
		{
			if (((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
				g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess) != 0)
			{
				if (((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
					g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess)->GetItemClass_guess() == 0)
				{
					if (((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
						g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess)->GetItemId_guess() == 0x7f2d)
					{
						dyesAvailable_015c_guess += ((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
							g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess)->field_048_guess;
						continue;
					}
				}
				if (((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
					g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess)->GetItemClass_guess() == 1)
				{
					container_guess = ((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
						g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(itemIndex_guess);
					for (int entryIndex_guess = 0; entryIndex_guess < container_guess->GetCount_guess(); entryIndex_guess++)
					{
						if (container_guess->GetEntry_guess(entryIndex_guess) != 0)
						{
							if (container_guess->GetEntry_guess(entryIndex_guess)->GetItemClass_guess() == 0 &&
								container_guess->GetEntry_guess(entryIndex_guess)->GetItemId_guess() == 0x7f2d)
							{
								dyesAvailable_015c_guess += container_guess->GetEntry_guess(entryIndex_guess)->field_048_guess;
							}
						}
					}
				}
			}
		}
	}
}

// Colour (Read_guess) of the item in inventory slot `argument_guess`, or 0 for an empty slot.
// FUNCTION: TITANIUM 0x004E76C1
int UnknownOwner_guess::GetInvSlotItemColor_guess(int argument_guess)
{
	int value_guess;
	if (((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
		g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(argument_guess) != 0)
	{
		QueryResult_guess* result_guess = ((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
			g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetInventorySlot_guess(argument_guess);
		value_guess = result_guess->Read_guess();
	}
	else
	{
		value_guess = 0;
	}
	return value_guess;
}

// EXTERNAL: TITANIUM 0x00464B55 GetInvSlotFromMaterialSlot_guess
int __cdecl GetInvSlotFromMaterialSlot_guess(int index_guess);

// Refreshes the brush and the per-slot colours: TINT_O*ColorBtn get the worn items' own colours and,
// unless `visible_guess`, the dye buttons get the profile's tints (0 shown as -1, no dye).
// FUNCTION: TITANIUM 0x004E7703
// @early-stop: budget, diff ndiff=46
void CBodyTintWnd_guess::UpdateBrush_guess(bool visible_guess)
{
	char buf_guess[256];
	CBodyTintWndView_guess* owner_guess = (CBodyTintWndView_guess*)this;
	if (owner_guess->selectedEntry_01c4_guess != 0)
	{
		owner_guess->selectedEntry_01c4_guess->tint_013c_guess = owner_guess->selectedColor_0168_guess;
		CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(owner_guess->selectedColor_0168_guess, buf_guess));
		owner_guess->selectedEntry_01c4_guess->text_078_guess = text_guess;
	}
	ItemEntry_guess** slot_guess = owner_guess->slots_178_guess;
	int remaining_guess = 9;
	do
	{
		if (*slot_guess != 0)
		{
			(*slot_guess)->flag_05d_guess = 0;
			(*slot_guess)->tint_013c_guess = -1;
			CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(-1, buf_guess));
			(*slot_guess)->text_078_guess = text_guess;
		}
		slot_guess++;
	} while (--remaining_guess != 0);
	if (g_contextObject_guess != 0)
	{
		for (int index_guess = 0; index_guess < 9; index_guess++)
		{
			int value_guess = ((UnknownOwner_guess*)this)->GetInvSlotItemColor_guess(GetInvSlotFromMaterialSlot_guess(index_guess));
			if (value_guess == 0)
				value_guess = -1;
			int slotValue_guess = g_contextObject_guess->GetSlotValue_guess(index_guess);
			if (slotValue_guess == 0)
				slotValue_guess = -1;
			if (index_guess >= 0 && index_guess < 7)
			{
				if (owner_guess->slots_178_guess[index_guess] != 0)
				{
					int color_guess = value_guess | 0xff000000;
					owner_guess->slots_178_guess[index_guess]->tint_013c_guess = color_guess;
					CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(color_guess, buf_guess));
					owner_guess->slots_178_guess[index_guess]->text_078_guess = text_guess;
				}
				if (!visible_guess && owner_guess->entries_19c_guess[index_guess] != 0)
				{
					int color_guess = slotValue_guess | 0xff000000;
					owner_guess->entries_19c_guess[index_guess]->tint_013c_guess = color_guess;
					CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(color_guess, buf_guess));
					owner_guess->entries_19c_guess[index_guess]->text_078_guess = text_guess;
				}
			}
		}
	}
}

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess, const char* text_guess,
	int zero1_guess, int zero2_guess, int zero3_guess, int zero4_guess, int zero5_guess,
	int zero6_guess, int zero7_guess, int zero8_guess);
// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

// Virtual view of a label window: SetWindowTextA is slot 63 (0xFC).
struct TintLabel_guess
{
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
	virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
	virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
	virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
	virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
	virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
	virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
	virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
	virtual void Slot63_guess(const CXStr& text_guess);
};

// Recounts and shows "Reagents Available" (6731) and "Reagents Needed" (6732); Save is enabled only with
// at least one dye and no fewer than needed.
// FUNCTION: TITANIUM 0x004E7992
void CBodyTintWnd_guess::UpdateReagents_guess()
{
	char buffer_guess[256];
	CountDyesAvailable_guess();
	((CBodyTintWndView_guess*)this)->CountDyesNeeded_guess();
	if (reagentsLabel_170_guess != 0)
	{
		FormatText_guess(buffer_guess, 0x1a4b,
			__itoa(dyesAvailable_015c_guess, EQ_ARRAY(char, 0x0099DB00), 10), 0, 0, 0, 0, 0, 0, 0, 0);
		CXStr text_guess(buffer_guess);
		((TintLabel_guess*)reagentsLabel_170_guess)->Slot63_guess(text_guess);
	}
	if (reagentsNeeded_16c_guess != 0)
	{
		FormatText_guess(buffer_guess, 0x1a4c,
			__itoa(dyesNeeded_0164_guess, EQ_ARRAY(char, 0x0099DB00), 10), 0, 0, 0, 0, 0, 0, 0, 0);
		CXStr text_guess(buffer_guess);
		((TintLabel_guess*)reagentsNeeded_16c_guess)->Slot63_guess(text_guess);
	}
	if (saveTint_174_guess != 0)
	{
		if (dyesAvailable_015c_guess <= 0 || dyesAvailable_015c_guess < dyesNeeded_0164_guess)
			saveTint_174_guess->Enabled = 0;
		else
			saveTint_174_guess->Enabled = 1;
	}
}


// Object at 0x00925518: slots 1, 4, 5, 6 and 8 are used; floats at +0x2c and +0x34.
struct TintCamera_guess
{
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess(float value_guess);
	virtual void Slot05_guess(float value_guess);
	virtual void Slot06_guess(float value_guess);
	virtual void Slot07_guess();
	virtual void Slot08_guess(float value_guess);
	char pad_004_guess[0x28];
	float f_02c_guess;
	char pad_030_guess[4];
	float f_034_guess;
};

#define g_tintCamera_guess EQ_GLOBAL(TintCamera_guess*, 0x00925518)

struct TintView_guess
{
	char pad_000_guess[0x4c];
	float value_04c_guess;
};

#define g_tintView_guess EQ_GLOBAL(TintView_guess*, 0x00905CE4)

// pCharData: a virtual base at +0xC384 (vbptr at +0xC284); flags at +0x108 of it.
struct CharFlagsBase_guess
{
	char pad_000_guess[0x108];
	unsigned char flags_108_guess;
};

struct CharFlagsPart_guess : virtual CharFlagsBase_guess
{
};

struct CharFlagsHolder_guess
{
	char pad_000_guess[0xc284];
	CharFlagsPart_guess part_c284_guess;
};

#define g_charFlags_guess EQ_GLOBAL(CharFlagsHolder_guess*, 0x00905D00)

struct DisplayRoot_guess
{
	// EXTERNAL: TITANIUM 0x0043C783 DisplayRoot_guess::RestoreCameraMode_guess
	void RestoreCameraMode_guess();
	// EXTERNAL: TITANIUM 0x004392DE DisplayRoot_guess::SetCameraMode_guess
	void SetCameraMode_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x004426FB DisplayRoot_guess::SetupCharacterViewCamera_guess
	void SetupCharacterViewCamera_guess(int value_guess);
};

#define g_displayRoot_guess EQ_GLOBAL(DisplayRoot_guess*, 0x00905D24)

// AboutToShow: refused while the face pick window (0x850BA0) is open, or without expansion bits 0x30 at
// pCharData +0xC384 +0x108 (probably Legacy of Ykesha / LDoN). Moves the camera (mode 7) to face the
// player.
// FUNCTION: TITANIUM 0x004E7AFC
bool CBodyTintWnd_guess::AboutToShow_guess()
{
	if (pinstCFacePick_guess != 0 && pinstCFacePick_guess->IsVisible_guess() == 1)
		return false;
	if ((g_charFlags_guess->part_c284_guess.flags_108_guess & 0x30) == 0)
		return false;
	dyesNeeded_0164_guess = 0;
	g_displayRoot_guess->SetCameraMode_guess(7);
	g_tintCamera_guess->Slot01_guess();
	g_displayRoot_guess->SetupCharacterViewCamera_guess(100);
	g_tintCamera_guess->Slot08_guess(g_tintView_guess->value_04c_guess);
	g_tintCamera_guess->Slot06_guess(g_tintCamera_guess->f_034_guess + 10.5f);
	g_tintCamera_guess->Slot05_guess(0.0f);
	g_tintCamera_guess->Slot04_guess(g_tintCamera_guess->f_02c_guess - 2.0f);
	UpdateBrush_guess(0);
	UpdateReagents_guess();
	return true;
}

struct TintButton_guess
{
	char pad_000_guess[0x78];
	CXStr tooltip_078_guess;
	char pad_07c_guess[0xc0];
	int tint_13c_guess;
};

// Sets the dye of the current slot (+0x160) and previews it; -1 (no dye) previews the slot's default
// colour instead (0x4BC5B5), while the button keeps -1.
// FUNCTION: TITANIUM 0x004E7BC7
void CBodyTintWnd_guess::SetTint_guess(int tint_guess)
{
	char buffer_guess[256];
	int value_guess = tint_guess;
	if (originalColors_178_guess[selectedSlot_0160_guess] != 0 &&
		((TintButton_guess*)buttons_19c_guess[selectedSlot_0160_guess])->tint_13c_guess != tint_guess)
	{
		if (tint_guess == -1)
		{
			value_guess = ((QueryObject_guess*)&g_globalBlock_guess->field_008_guess.objectData_guess[
				g_globalBlock_guess->field_008_guess.offsetBlock_guess->vbaseOffset_0004_guess])->GetBodyTint_guess(selectedSlot_0160_guess);
		}
		TintButton_guess* button_guess = (TintButton_guess*)buttons_19c_guess[selectedSlot_0160_guess];
		if (button_guess != 0)
		{
			button_guess->tint_13c_guess = tint_guess;
			CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(tint_guess, buffer_guess));
			TintButton_guess* tip_guess = (TintButton_guess*)buttons_19c_guess[selectedSlot_0160_guess];
			tip_guess->tooltip_078_guess = text_guess;
		}
		((ValidationCallback_guess*)this)->Update_guess(value_guess);
		UpdateReagents_guess();
	}
}

// Back to the saved state: slots with no dye in the profile preview the item's own colour and clear
// their button; the others re-apply the profile's tint.
// FUNCTION: TITANIUM 0x004E7CC4
void CBodyTintWnd_guess::ResetTints_guess()
{
	char buffer_guess[256];
	if (g_contextObject_guess != 0)
	{
		int i_guess = 0;
		CXWnd** color_guess = originalColors_178_guess;
		for (; i_guess < 9; ++i_guess, ++color_guess)
		{
			int value_guess = g_contextObject_guess->GetSlotValue_guess(i_guess);
			selectedSlot_0160_guess = i_guess;
			if (value_guess == 0)
			{
				if (*color_guess != 0)
				{
					((ValidationCallback_guess*)this)->Update_guess(
						((TintButton_guess*)*color_guess)->tint_13c_guess);
					if (buttons_19c_guess[selectedSlot_0160_guess] != 0)
					{
						((TintButton_guess*)buttons_19c_guess[selectedSlot_0160_guess])->tint_13c_guess |= -1;
						CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(-1, buffer_guess));
						TintButton_guess* tip_guess = (TintButton_guess*)buttons_19c_guess[selectedSlot_0160_guess];
						tip_guess->tooltip_078_guess = text_guess;
					}
				}
			}
			else
			{
				SetTint_guess(value_guess);
			}
		}
		selectedSlot_0160_guess = 0;
		UpdateReagents_guess();
	}
}


// Buttons: Save, Reset, the brush and the slot buttons open the colour picker (0x850C0C) for that slot
// (+0x160, -1 for the brush), preset to the brush colour when one is set. Message 0x20 is the picked
// colour: a slot colour with every channel below 25 becomes (25, 25, 25), probably because 0 means no dye.
// FUNCTION: TITANIUM 0x004E7DEB
int CBodyTintWnd_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
	unsigned int data_guess)
{
	char buffer_guess[256];
	if (message_guess == 1)
	{
		if (sender_guess == saveTint_174_guess)
		{
			((CBodyTintWndView_guess*)this)->SendSlots_guess();
			return 0;
		}
		if (sender_guess == resetTint_1c0_guess)
		{
			ResetTints_guess();
			return 0;
		}
		if (sender_guess == brush_1c4_guess)
		{
			selectedSlot_0160_guess = -1;
			pinstCColorPickerWnd_guess->Activate_guess(this, ((TintButton_guess*)brush_1c4_guess)->tint_13c_guess);
			return 0;
		}
		for (int i_guess = 0; i_guess < 9; ++i_guess)
		{
			if (sender_guess == buttons_19c_guess[i_guess])
			{
				selectedSlot_0160_guess = i_guess;
				pinstCColorPickerWnd_guess->Activate_guess(this, ((CBodyTintWndView_guess*)this)->GetSlotTint_guess(i_guess));
				if (tint_168_guess != -1)
					pinstCColorPickerWnd_guess->SetPresetColor_guess(0, tint_168_guess);
				return 0;
			}
		}
	}
	else if (message_guess == 0x20)
	{
		if (selectedSlot_0160_guess == -1)
		{
			tint_168_guess = data_guess;
			if (brush_1c4_guess != 0)
			{
				((TintButton_guess*)brush_1c4_guess)->tint_13c_guess = data_guess;
				CXStr text_guess(((ColorWindow_guess*)this)->FormatColor_guess(data_guess, buffer_guess));
				TintButton_guess* tip_guess = (TintButton_guess*)brush_1c4_guess;
				tip_guess->tooltip_078_guess = text_guess;
			}
		}
		else
		{
			unsigned int color_guess = data_guess;
			if ((color_guess & 0xff0000) < 0x190000 && (color_guess & 0xff00) < 0x1900 &&
				(color_guess & 0xff) < 0x19)
				color_guess = 0xff191919;
			SetTint_guess(color_guess);
		}
		selectedSlot_0160_guess = 0;
		return 0;
	}
	return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, (void*)data_guess);
}

// On close: drops the preview (saved tints back) and restores the camera.
// FUNCTION: TITANIUM 0x004E7F90
bool CBodyTintWnd_guess::AboutToHide_guess()
{
	ResetTints_guess();
	g_displayRoot_guess->RestoreCameraMode_guess();
	return true;
}

