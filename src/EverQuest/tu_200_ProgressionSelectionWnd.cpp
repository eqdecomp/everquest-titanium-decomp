// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 200: a hint from compare/tumap.py.
// CProgressionSelectionWnd ("ProgressionSelectionWnd"): the Monster Mission template picker (strings 4554
// and 4555, the select-monster title, and a monster-alt log line). Three cascading lists, progression -> branch -> step
// (template), feed a pane with the template's class, level, stats, AAs and equipment. The templates live in
// the registry at 0x79C120; the *View_guess classes are per-function views of the window.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"

struct LayoutHelper_guess
{
	char pad0[0x3C];
	void* field_15c_guess;	// 0x15C in CProgressionSelectionWndView_guess
	// EXTERNAL: TITANIUM 0x00572300 LayoutHelper_guess::FUN_00572300
	void* FUN_00572300(const char* name);
};

struct ProgressionWindow_guess
{
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
	virtual void Slot48_guess(int first, int second);
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
	virtual void Slot63_guess(CXStr& text);
	virtual void Slot64_guess();
	virtual void Slot65_guess();
	virtual void Slot66_guess();
	virtual void Slot67_guess();
	virtual void Slot68_guess();
	virtual void Slot69_guess();
	virtual void Slot70_guess();
	virtual void Slot71_guess();
	virtual void Slot72_guess();
	virtual void Slot73_guess(void* value);
	virtual void Slot74_guess(void* value);
	virtual void Slot75_guess();
	virtual void Slot76_guess();
	virtual void Slot77_guess();
	virtual void Slot78_guess();
};

struct ProgressionComponent_guess : ProgressionWindow_guess
{
	// EXTERNAL: TITANIUM 0x0059B9D0 ProgressionComponent_guess::AddString
	void* AddString(const CXStr& text_guess, int color_guess, int first_guess, int second_guess);
	// EXTERNAL: TITANIUM 0x0059B360 ProgressionComponent_guess::SetItemText
	void* SetItemText(void* value_guess, int index_guess, const CXStr& text_guess);
	// EXTERNAL: TITANIUM 0x00598620 ProgressionComponent_guess::SetItemData
	void SetItemData(void* value_guess, int amount_guess);
	// EXTERNAL: TITANIUM 0x0059B3E0 ProgressionComponent_guess::FUN_0059b3e0_guess
	void* FUN_0059b3e0_guess(void* value_guess, int index_guess, int color_guess);
};

struct CProgressionSelectionWndRowsView_guess
{
	char pad[0x160];
	ProgressionComponent_guess* component_160_guess;

	void AddProgressionRow_guess(void* value_guess, int amount_guess, const char* source_guess, const char* text_guess);
};

// Row in the progression list (+0x160): name in column 0, progress text ("done/total") in column 1,
// `amount_guess` as item data.
// FUNCTION: TITANIUM 0x00548E4A
void CProgressionSelectionWndRowsView_guess::AddProgressionRow_guess(void* value_guess, int amount_guess, const char* source_guess, const char* text_guess)
{
	if (component_160_guess != 0)
	{
		{
			CXStr label_guess(EQ_ARRAY(char, 0x0063F53F));
			component_160_guess->AddString(label_guess, 0xffffffff, 0, 0);
		}
		{
			CXStr source_text_guess(source_guess);
			component_160_guess->SetItemText(value_guess, 0, source_text_guess);
		}
		{
			CXStr text_str_guess(text_guess);
			component_160_guess->SetItemText(value_guess, 1, text_str_guess);
		}
		component_160_guess->SetItemData(value_guess, amount_guess);
	}
}

struct CProgressionSelectionWndBranchRowsView_guess
{
	char pad[0x164];
	ProgressionComponent_guess* component_164_guess;

	void AddBranchRow_guess(void* value_guess, int amount_guess, const char* source_guess, const char* text_guess, int flag_guess);
};

// Row in the branch list (+0x164). `flag_guess` is the branch state: 0 locked (red), 1 in progress
// (yellow), 2 unlocked (green); only unlocked rows keep white text, the rest are grey.
// FUNCTION: TITANIUM 0x00548F35
void CProgressionSelectionWndBranchRowsView_guess::AddBranchRow_guess(void* value_guess, int amount_guess, const char* source_guess, const char* text_guess, int flag_guess)
{
	int color_guess = flag_guess == 2 ? 0xffffffff : 0xff808080;
	if (component_164_guess != 0)
	{
		{
			CXStr label_guess(EQ_ARRAY(char, 0x0063F53F));
			component_164_guess->AddString(label_guess, color_guess, 0, 0);
		}
		{
			CXStr source_text_guess(source_guess);
			component_164_guess->SetItemText(value_guess, 0, source_text_guess);
		}
		{
			CXStr text_str_guess(text_guess);
			component_164_guess->SetItemText(value_guess, 1, text_str_guess);
		}
		component_164_guess->SetItemData(value_guess, amount_guess);
		switch (flag_guess)
		{
		case 0:
			component_164_guess->FUN_0059b3e0_guess(value_guess, 1, 0xffff0000);
			break;
		case 1:
			component_164_guess->FUN_0059b3e0_guess(value_guess, 1, 0xffffff00);
			break;
		case 2:
			component_164_guess->FUN_0059b3e0_guess(value_guess, 1, 0xff00ff00);
			break;
		}
	}
}

struct Obj178_guess
{
	char pad[0x5D];
	char flag_5d_guess;
};

struct CProgressionSelectionWndView_guess
{
	char pad[0x120];
	LayoutHelper_guess helper;		// 0x120
	ProgressionWindow_guess* field_160_guess;
	ProgressionWindow_guess* field_164_guess;
	ProgressionComponent_guess* field_168_guess;
	ProgressionWindow_guess* field_16c_guess;
	ProgressionWindow_guess* field_170_guess;
	CStmlWnd* field_174_guess;
	Obj178_guess* field_178_guess;
	ProgressionWindow_guess* field_17c_guess;
	ProgressionWindow_guess* progression;	// 0x180
	ProgressionWindow_guess* field_184_guess;
	ProgressionWindow_guess* field_188_guess;
	ProgressionWindow_guess* field_18c_guess;
	ProgressionWindow_guess* field_190_guess;
	ProgressionWindow_guess* field_194_guess;
	ProgressionWindow_guess* field_198_guess;
	ProgressionWindow_guess* field_19c_guess;
	ProgressionWindow_guess* field_1a0_guess;
	ProgressionWindow_guess* field_1a4_guess;
	ProgressionWindow_guess* field_1a8_guess;
	ProgressionWindow_guess* field_1ac_guess;
	ProgressionWindow_guess* field_1b0_guess;
	char pad_1b4[4];
	ProgressionWindow_guess* field_1b8_guess;
	char pad_1bc[0x4c];
	struct AnimationOwner_guess* field_208_guess;
	char pad_20c[8];
	char flag_214_guess;

	void AddStepRow_guess(int unused_guess, int amount_guess, const char* source_guess, const char* text_guess, char flag_guess);
	void ClearTemplateInfo_guess(void);
	void ClearSteps_guess(void);
	void LoadLayout_guess(void);
	void StoreLayout_guess(void);
	void CancelSelection_guess(void);
	void ClearBranches_guess(void);
	void ClearProgressions_guess(void);
	char AboutToHide_guess(void);
	void ShowSelectedProgression_guess(void);
	void ShowSelectedBranch_guess(void);
	void FillProgressionList_guess(void);
	void ShowSelectedStep_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x0054957D CProgressionSelectionWndView_guess::ShowSelectedEquipment_guess
	void ShowSelectedEquipment_guess(void);
	void ShowSelectedAbility_guess(void);
	int WndNotification_guess(void* target_guess, int msg_guess, int data_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(CXStr* output_guess, const char* format_guess, ...);

struct TextBuf_00549bc2_guess
{
	union
	{
		char buf_guess[16];
		char* ptr_guess;
	} data_guess;
	int size_guess;
	int cap_guess;
};

struct Leaf_00549bc2_guess
{
	Leaf_00549bc2_guess* next_guess;
	char pad_04[8];
	TextBuf_00549bc2_guess text_guess;
	const char* label_guess;
	int amount_guess;
	unsigned char flag_guess;
};

struct Inner_00549bc2_guess
{
	Inner_00549bc2_guess* next_guess;
	Inner_00549bc2_guess* prev_guess;
	int key_guess;
	char pad_0c[0x20];
	TextBuf_00549bc2_guess text_guess;
	char pad_44[8];
	Leaf_00549bc2_guess* sub_guess;
};

struct OuterNode_00549bc2_guess
{
	OuterNode_00549bc2_guess* next_guess;
	OuterNode_00549bc2_guess* prev_guess;
	int key_guess;
	char pad_0c[0x44];
	Inner_00549bc2_guess* sub_guess;
};

struct Object_00549977_guess
{
	char pad_00[0x14];
	OuterNode_00549bc2_guess* list_14_guess;
	// EXTERNAL: TITANIUM 0x00401B65 Object_00549977_guess::GetProgressionRecord_guess
	struct ProgressionRecord_guess* GetProgressionRecord_guess(int current_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x00401BEF Object_00549977_guess::StartShroudTransform_guess
	void StartShroudTransform_guess(int value);
	// EXTERNAL: TITANIUM 0x00401BB1 Object_00549977_guess::IsWithinRange_guess
	char IsWithinRange_guess(int value);
	// EXTERNAL: TITANIUM 0x00401C53 Object_00549977_guess::SendProgressionCancel_guess
	void SendProgressionCancel_guess(void);
	// EXTERNAL: TITANIUM 0x00518B72 Object_00549977_guess::FUN_00518b72_guess
	void FUN_00518b72_guess(int* value);
};

#define g_monsterTemplateRegistry_guess EQ_GLOBAL(Object_00549977_guess*, 0x0079C120)
#define g_counter_009248d4_guess EQ_GLOBAL(int, 0x009248D4)
#define g_counter_009248d0_guess EQ_GLOBAL(int, 0x009248D0)

struct CProgressionSelectionWndAcceptView_guess
{
	char pad[0x168];
	CListWnd* progression_guess;

	void AcceptSelectedStep_guess(void);
};

struct ProgressionEntry_guess
{
	char pad0[0x14];
	int stringId_14_guess;
	char pad18[0x28];
	int seconds_40_guess;
};

struct AltAdvManager
{
	// EXTERNAL: TITANIUM 0x00447D07 AltAdvManager::GetAltAbility
	ProgressionEntry_guess* GetAltAbility(int value_guess);
	// EXTERNAL: TITANIUM 0x00447D5B AltAdvManager::GetAbilityReqs_guess
	void GetAbilityReqs_guess(char* text_guess, ProgressionEntry_guess* entry_guess);
};

struct DBStringTable_guess
{
	// EXTERNAL: TITANIUM 0x004355F7 DBStringTable_guess::FUN_004355f7_guess
	char* FUN_004355f7_guess(int stringId_guess, int category_guess, int index_guess);
};

#define g_progressionRuntime_guess EQ_GLOBAL(AltAdvManager*, 0x008511D8)
#define g_progressionDatabase_guess EQ_GLOBAL(DBStringTable_guess*, 0x00850398)

// Row in the step list (+0x168). The template id is the item data, negated when the template is not
// available (`flag_guess` 0, grey row); ShowSelectedStep_guess reads the sign back for the accept button.
// FUNCTION: TITANIUM 0x00549064
void CProgressionSelectionWndView_guess::AddStepRow_guess(int, int amount_guess, const char* source_guess, const char* text_guess, char flag_guess)
{
	if (field_168_guess != 0)
	{
		CXStr formatted_guess;
		FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), text_guess);
		int color_guess = flag_guess != 0 ? 0xffffffff : 0xff808080;
		void* value_guess;
		{
			const CXStr& label_guess = CXStr(EQ_ARRAY(char, 0x0063F53F));
			value_guess = field_168_guess->AddString(label_guess, color_guess, 0, 0);
		}
		{
			const CXStr& source_text_guess = CXStr(source_guess);
			field_168_guess->SetItemText(value_guess, 0, source_text_guess);
		}
		field_168_guess->SetItemText(value_guess, 1, formatted_guess);
		field_168_guess->SetItemData(value_guess, flag_guess ? amount_guess : -amount_guess);
	}
}

// Resets the info pane: title string 4554 (select monster), '-' in the 11 value labels, empty AA and
// equipment lists, accept disabled, item icon hidden.
// FUNCTION: TITANIUM 0x0054916B
void CProgressionSelectionWndView_guess::ClearTemplateInfo_guess(void)
{
	if (field_174_guess != 0)
		field_174_guess->SetSTMLText(CXStr(EQ_ARRAY(char, 0x0063F53F)), false, 0);
	if (field_184_guess != 0)
	{
		CXStr text_guess(pStringTable->getString(0x11CA, 0));
		field_184_guess->Slot63_guess(text_guess);
	}
	if (field_188_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_188_guess->Slot63_guess(text_guess);
	}
	if (field_18c_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_18c_guess->Slot63_guess(text_guess);
	}
	if (field_190_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_190_guess->Slot63_guess(text_guess);
	}
	if (field_194_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_194_guess->Slot63_guess(text_guess);
	}
	if (field_198_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_198_guess->Slot63_guess(text_guess);
	}
	if (field_19c_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_19c_guess->Slot63_guess(text_guess);
	}
	if (field_1a0_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_1a0_guess->Slot63_guess(text_guess);
	}
	if (field_1a4_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_1a4_guess->Slot63_guess(text_guess);
	}
	if (field_1a8_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_1a8_guess->Slot63_guess(text_guess);
	}
	if (field_1ac_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_1ac_guess->Slot63_guess(text_guess);
	}
	if (field_1b0_guess != 0)
	{
		CXStr text_guess(EQ_ARRAY(char, 0x0065AE40));
		field_1b0_guess->Slot63_guess(text_guess);
	}
	if (field_16c_guess != 0)
		field_16c_guess->Slot76_guess();
	if (field_170_guess != 0)
		field_170_guess->Slot76_guess();
	if (field_178_guess != 0)
		field_178_guess->flag_5d_guess = 0;
	if (field_1b8_guess != 0)
		field_1b8_guess->Slot48_guess(0, 1);
}

// Empties the step list, then the info pane. ClearBranches_guess and ClearProgressions_guess chain on
// this, each emptying one more list.
// FUNCTION: TITANIUM 0x00549501
void CProgressionSelectionWndView_guess::ClearSteps_guess(void)
{
	if (field_168_guess != 0)
		field_168_guess->Slot76_guess();
	ClearTemplateInfo_guess();
}

struct ProgressionLink_0054957d_guess
{
	// EXTERNAL: TITANIUM 0x005B1AB0 ProgressionLink_0054957d_guess::FUN_005b1ab0_guess
	void FUN_005b1ab0_guess(int value);
};

struct ProgressionWindowFields_0054957d_guess
{
	char pad_000[0x158];
	void* link_158_guess;
	char pad_15c[0x10];
	int field_16c_guess;
	// EXTERNAL: TITANIUM 0x0059D080 ProgressionWindowFields_0054957d_guess::FUN_0059d080_guess
	void FUN_0059d080_guess(int value);
};

struct ProgressionEntry_0054957d_guess
{
	int unknown_0_guess;
	int value_guess;
	char pad_08[4];
	CXStr name_guess;
};

struct ProgressionDatabase_0054957d_guess
{
	// EXTERNAL: TITANIUM 0x00490D40 ProgressionDatabase_0054957d_guess::Find_guess
	ProgressionEntry_0054957d_guess* Find_guess(int value);
};

struct ProgressionErrorData_0054957d_guess
{
	int absolute_value_guess;
	int requested_value_guess;
};

#define g_progression_db_0054957d_guess EQ_GLOBAL(ProgressionDatabase_0054957d_guess, 0x00903EA0)
#define g_empty_string_0054957d_guess EQ_ARRAY(char, 0x0063F53F)

// Description and icon of the clicked equipment row. An item missing from 0x903EA0 (probably the
// item cache) is requested instead: message 0x68C5 (no EQEmu name), 8 bytes: template id, item id.
// FUNCTION: TITANIUM 0x0054957D
// @early-stop: unknown, diff ndiff=4
void CProgressionSelectionWndView_guess::ShowSelectedEquipment_guess(void)
{
	ProgressionErrorData_0054957d_guess error_data_guess;
	int value_guess;
	if (field_174_guess != 0)
	{
		field_174_guess->SetSTMLText(CXStr(g_empty_string_0054957d_guess), true, 0);
		if (field_1b8_guess != 0)
			field_1b8_guess->Slot48_guess(0, 1);
		if (field_16c_guess != 0)
			((CListWnd*)field_16c_guess)->SetCurSel(-1);
		if (field_170_guess != 0)
		{
			if (field_168_guess != 0)
			{
				int first_index_guess = ((CListWnd*)field_168_guess)->GetCurSel();
				value_guess = ((CListWnd*)field_168_guess)->GetItemData(first_index_guess);
				if (value_guess < 0)
					value_guess = -value_guess;
				int second_index_guess = ((CListWnd*)field_170_guess)->GetCurSel();
				int second_value_guess = ((CListWnd*)field_170_guess)->GetItemData(second_index_guess);
				ProgressionEntry_0054957d_guess* entry_guess = g_progression_db_0054957d_guess.Find_guess(second_value_guess);
				if (entry_guess != 0)
				{
					field_174_guess->SetSTMLText(entry_guess->name_guess, true, 0);
					if (field_1b8_guess != 0)
					{
						field_1b8_guess->Slot48_guess(1, 1);
						((ProgressionWindowFields_0054957d_guess*)field_1b8_guess)->FUN_0059d080_guess(1);
						((ProgressionWindowFields_0054957d_guess*)field_1b8_guess)->field_16c_guess = 0;
						((ProgressionWindowFields_0054957d_guess*)field_1b8_guess)->link_158_guess = pad_1bc;
						((ProgressionLink_0054957d_guess*)pad_1bc)->FUN_005b1ab0_guess(entry_guess->value_guess);
					}
				}
				else
				{
					error_data_guess.requested_value_guess = second_value_guess;
					error_data_guess.absolute_value_guess = value_guess;
					EQSendMessage(EQ_ARRAY(void, 0x00905CA0), 0x68c5, &error_data_guess, 8, 1);
				}
			}
		}
	}
}

// Progression selection window: loads the "ProgressionSelectionLayout" layout into its
// ProgressionTemplateTopLayout control (+0x180, slot 73). Done once in the constructor (0x0054A413).
// FUNCTION: TITANIUM 0x00549523
void CProgressionSelectionWndView_guess::LoadLayout_guess(void)
{
	if (progression != 0)
		progression->Slot73_guess(helper.FUN_00572300("ProgressionSelectionLayout"));
}

// Progression selection window: stores the layout under "ProgressionSelectionLayout"
// (ProgressionTemplateTopLayout, +0x180, slot 74). Done when the window closes (0x00549D55).
// FUNCTION: TITANIUM 0x00549550
void CProgressionSelectionWndView_guess::StoreLayout_guess(void)
{
	if (progression != 0)
		progression->Slot74_guess(helper.FUN_00572300("ProgressionSelectionLayout"));
}

// Description of the clicked AA (table 0x8511D8, probably the AA manager): string 3109 ("Type: Activated,
// OnProcessFrame Time:") with h:mm:ss, or 3110 (passive) at 0 seconds, then the AA's dbstr description
// (type 4). An AA the client doesn't have is requested with message 0x1A8 (8 bytes: template id, AA id).
// FUNCTION: TITANIUM 0x005496D3
// @early-stop: budget, structural ndiff=102
void CProgressionSelectionWndView_guess::ShowSelectedAbility_guess(void)
{
	if (field_174_guess != 0)
	{
		field_174_guess->SetSTMLText(CXStr(EQ_ARRAY(char, 0x0063F53F)), true, 0);

		if (field_1b8_guess != 0)
			field_1b8_guess->Slot48_guess(0, 1);

		if (field_170_guess != 0)
			((CListWnd*)field_170_guess)->SetCurSel(-1);

		if (field_16c_guess == 0 || field_168_guess == 0 || g_progressionRuntime_guess == 0)
			return;

		ProgressionEntry_guess* entry_guess;
		int currentValue_guess = ((CListWnd*)field_16c_guess)->GetItemData(
			((CListWnd*)field_16c_guess)->GetCurSel());
		entry_guess = g_progressionRuntime_guess->GetAltAbility(currentValue_guess);

		if (entry_guess == 0)
		{
			int values_guess[2];	// two integers sent to the progression request
			values_guess[0] = ((CListWnd*)field_168_guess)->GetItemData(
				((CListWnd*)field_168_guess)->GetCurSel());
			values_guess[1] = currentValue_guess;
			EQSendMessage(EQ_ARRAY(void, 0x00905CA0), 0x1a8, values_guess, 8, 1);
			return;
		}

		char timeText_guess[1024];
		CXStr text_guess;
		if (entry_guess->seconds_40_guess <= 0)
		{
			text_guess += pStringTable->getString(0xc26, 0);
		}
		else
		{
			unsigned int totalSeconds_guess = (unsigned int)entry_guess->seconds_40_guess;
			unsigned int hours_guess = totalSeconds_guess / 0xe10;
			unsigned int seconds_guess = totalSeconds_guess % 0x3c;
			unsigned int minutes_guess = (totalSeconds_guess / 0x3c) % 0x3c;
			text_guess += pStringTable->getString(0xc25, 0);
			sprintf(timeText_guess, " %d:%02d:%02d", hours_guess, minutes_guess, seconds_guess);
			text_guess += timeText_guess;
		}

		text_guess += EQ_ARRAY(char, 0x0064DD5C);
		g_progressionRuntime_guess->GetAbilityReqs_guess(timeText_guess, entry_guess);
		text_guess += timeText_guess;
		text_guess += EQ_ARRAY(char, 0x0064DD5C);
		text_guess += g_progressionDatabase_guess->FUN_004355f7_guess(entry_guess->stringId_14_guess, 4, 0);
		field_174_guess->SetSTMLText(text_guess, true, 0);
	}
}

// Sends the selected template id to the registry (0x79C120) when it is a positive (available) one.
// FUNCTION: TITANIUM 0x0054993E
void CProgressionSelectionWndAcceptView_guess::AcceptSelectedStep_guess(void)
{
	if (g_monsterTemplateRegistry_guess != 0 && progression_guess != 0)
	{
		int index_guess = progression_guess->GetCurSel();
		if (index_guess >= 0)
		{
			int value_guess = progression_guess->GetItemData(index_guess);
			if (value_guess > 0)
				g_monsterTemplateRegistry_guess->StartShroudTransform_guess(value_guess);
		}
	}
}

// Tells the registry (0x79C120) that the choice was dropped.
// FUNCTION: TITANIUM 0x00549977
void CProgressionSelectionWndView_guess::CancelSelection_guess(void)
{
	if (g_monsterTemplateRegistry_guess != 0)
		return g_monsterTemplateRegistry_guess->SendProgressionCancel_guess();
}

// Progression selection window: empties the branch list (+0x164, list slot 76), then the step list and
// info pane (0x00549501). Used before the branch list is refilled.
// FUNCTION: TITANIUM 0x00549987
void CProgressionSelectionWndView_guess::ClearBranches_guess(void)
{
	if (field_164_guess != 0)
		field_164_guess->Slot76_guess();
	return ClearSteps_guess();
}

// Progression selection window: empties the progression list (+0x160, list slot 76) and every list
// below it (0x00549987). Used before the progression list is refilled from the registry.
// FUNCTION: TITANIUM 0x005499A9
void CProgressionSelectionWndView_guess::ClearProgressions_guess(void)
{
	if (field_160_guess != 0)
		field_160_guess->Slot76_guess();
	return ClearBranches_guess();
}

struct ProgressionNode_005499cb_guess
{
	ProgressionNode_005499cb_guess* next_guess;
	ProgressionNode_005499cb_guess* prev_guess;
	int id_guess;
	char pad_0c[4];
	union
	{
		char buf_guess[16];
		char* ptr_guess;
	} text_guess;
	int size_guess;
	unsigned int cap_guess;
	char pad_28[0x1c];
	int field_44_guess;
	int field_48_guess;
};

// Refills the progression list from the registry (0x79C120), clearing the dependent lists first.
// FUNCTION: TITANIUM 0x005499CB
// @early-stop: budget, structural ndiff=17
void CProgressionSelectionWndView_guess::FillProgressionList_guess(void)
{
	ClearProgressions_guess();
	Object_00549977_guess* object_guess = g_monsterTemplateRegistry_guess;
	if (object_guess != 0)
	{
		int counter_guess = 0;
		ProgressionNode_005499cb_guess** head_addr_guess = reinterpret_cast<ProgressionNode_005499cb_guess**>(&object_guess->list_14_guess);
		ProgressionNode_005499cb_guess* node_guess = (*head_addr_guess)->next_guess;
		if (node_guess != *head_addr_guess)
		{
			do
			{
				CXStr label_guess;
				FUN_005738b0_guess(&label_guess, "%d/%d", node_guess->field_44_guess, node_guess->field_48_guess);
				char* name_guess;
				if (node_guess->cap_guess >= 0x10)
					name_guess = node_guess->text_guess.ptr_guess;
				else
					name_guess = node_guess->text_guess.buf_guess;
				reinterpret_cast<CProgressionSelectionWndRowsView_guess*>(this)->AddProgressionRow_guess(reinterpret_cast<void*>(counter_guess), node_guess->id_guess, name_guess, label_guess);
				++counter_guess;
				node_guess = node_guess->next_guess;
			} while (node_guess != *head_addr_guess);
		}
	}
}

// VC7.1 std::string shape: 0x04 buffer or pointer, 0x14 size, 0x18 capacity.
struct String_00549a6d_guess
{
	char pad_00[4];
	union
	{
		char buf_guess[16];
		char* ptr_guess;
	} data_guess;
	int size_guess;
	unsigned int cap_guess;

	const char* c_str_guess() const
	{
		return 0x10 <= cap_guess ? data_guess.ptr_guess : data_guess.buf_guess;
	}
};

// Entry of the sub-list at item +0x50.
struct ProgressionSub_00549a6d_guess
{
	ProgressionSub_00549a6d_guess* next_guess;	// 0x00
	char pad_04[4];
	int amount_guess;							// 0x08
	String_00549a6d_guess name_guess;			// 0x0C
	char pad_28[0x1C];
	int state_guess;							// 0x44
};

// Entry of the global list at owner +0x14.
struct ProgressionItem_00549a6d_guess
{
	ProgressionItem_00549a6d_guess* next_guess;	// 0x00
	char pad_04[4];
	int key_guess;								// 0x08
	char pad_0c[0x1C];
	String_00549a6d_guess text_guess;			// 0x28
	char pad_44[0xC];
	ProgressionSub_00549a6d_guess* sub_head_guess;	// 0x50
};

struct ProgressionOwner_00549a6d_guess
{
	char pad[0x14];
	ProgressionItem_00549a6d_guess* head_guess;	// 0x14
};

#define g_00549a6d_owner_guess EQ_GLOBAL(ProgressionOwner_00549a6d_guess*, 0x0079C120)

// Fills the branch list for the selected progression: progress 0 "locked", 100 "unlocked", else "n%".
// An id no longer in the registry rebuilds the progression list instead.
// FUNCTION: TITANIUM 0x00549A6D
void CProgressionSelectionWndView_guess::ShowSelectedProgression_guess(void)
{
	ClearBranches_guess();
	if (g_monsterTemplateRegistry_guess != 0 && field_160_guess != 0)
	{
		int index_guess = ((CListWnd*)field_160_guess)->GetCurSel();
		if (index_guess >= 0)
		{
			int value_guess = ((CListWnd*)field_160_guess)->GetItemData(index_guess);
			ProgressionItem_00549a6d_guess* head_guess = g_00549a6d_owner_guess->head_guess;
			for (ProgressionItem_00549a6d_guess* item_guess = head_guess->next_guess; item_guess != head_guess; item_guess = item_guess->next_guess)
			{
				if (item_guess->key_guess == value_guess)
				{
					if (field_174_guess != 0)
						field_174_guess->SetSTMLText(CXStr(item_guess->text_guess.c_str_guess()), false, 0);
					int counter_guess = 0;
					ProgressionSub_00549a6d_guess* sub_guess = item_guess->sub_head_guess->next_guess;
					if (sub_guess == item_guess->sub_head_guess)
						return;
					do
					{
						{
							int flag_guess = 0;
							CXStr text_guess;
							if (sub_guess->state_guess == 0)
							{
								text_guess = "locked";
							}
							else if (sub_guess->state_guess == 0x64)
							{
								text_guess = "unlocked";
								flag_guess = 2;
							}
							else
							{
								FUN_005738b0_guess(&text_guess, EQ_ARRAY(char, 0x0064DD78), sub_guess->state_guess);
								flag_guess = 1;
							}
							const char* name_guess = sub_guess->name_guess.c_str_guess();
							((CProgressionSelectionWndBranchRowsView_guess*)this)->AddBranchRow_guess((void*)counter_guess, sub_guess->amount_guess, name_guess, text_guess, flag_guess);
							counter_guess++;
						}
						sub_guess = sub_guess->next_guess;
					} while (sub_guess != item_guess->sub_head_guess);
					return;
				}
			}
			FillProgressionList_guess();
		}
	}
}

// Fills the step list for the selected progression and branch; unknown ids rebuild the progression list.
// FUNCTION: TITANIUM 0x00549BC2
// @early-stop: budget, structural ndiff=37
void CProgressionSelectionWndView_guess::ShowSelectedBranch_guess(void)
{
	ClearSteps_guess();
	if (g_monsterTemplateRegistry_guess != 0 && field_160_guess != 0 && field_164_guess != 0)
	{
		int index_164_guess;
		int index_160_guess = ((CListWnd*)field_160_guess)->GetCurSel();
		index_164_guess = ((CListWnd*)field_164_guess)->GetCurSel();
		if (index_160_guess >= 0 && index_164_guess >= 0)
		{
			int key_160_guess = ((CListWnd*)field_160_guess)->GetItemData(index_160_guess);
			int key_164_guess = ((CListWnd*)field_164_guess)->GetItemData(index_164_guess);
			OuterNode_00549bc2_guess* head_guess = g_monsterTemplateRegistry_guess->list_14_guess;
			for (OuterNode_00549bc2_guess* outer_guess = head_guess->next_guess; outer_guess != head_guess; outer_guess = outer_guess->next_guess)
			{
				if (outer_guess->key_guess == key_160_guess)
				{
					Inner_00549bc2_guess* inner_head_guess = outer_guess->sub_guess;
					for (Inner_00549bc2_guess* inner_guess = inner_head_guess->next_guess; inner_guess != inner_head_guess; inner_guess = inner_guess->next_guess)
					{
						if (inner_guess->key_guess == key_164_guess)
						{
							if (field_174_guess != 0)
								field_174_guess->SetSTMLText(CXStr(inner_guess->text_guess.cap_guess < 16 ? inner_guess->text_guess.data_guess.buf_guess : inner_guess->text_guess.data_guess.ptr_guess), false, 0);
							Leaf_00549bc2_guess* leaf_guess = inner_guess->sub_guess->next_guess;
							if (leaf_guess == inner_guess->sub_guess)
								return;
							int index_guess = 0;
							do
							{
								AddStepRow_guess(index_guess, leaf_guess->amount_guess, leaf_guess->text_guess.cap_guess < 16 ? leaf_guess->text_guess.data_guess.buf_guess : leaf_guess->text_guess.data_guess.ptr_guess, leaf_guess->label_guess, leaf_guess->flag_guess);
								leaf_guess = leaf_guess->next_guess;
								index_guess++;
							} while (leaf_guess != inner_guess->sub_guess);
							return;
						}
					}
					break;
				}
			}
			FillProgressionList_guess();
		}
	}
}

// Saves the layout and unregisters from the registry. Closed without accepting, it also drops the choice
// and lowers the counters 0x9248D4 / 0x9248D0 (clamped at 0).
// FUNCTION: TITANIUM 0x00549D55
char CProgressionSelectionWndView_guess::AboutToHide_guess(void)
{
	StoreLayout_guess();
	if (flag_214_guess == 0)
	{
		if (--g_counter_009248d4_guess < 0)
			g_counter_009248d4_guess = 0;
		if (--g_counter_009248d0_guess < 0)
			g_counter_009248d0_guess = 0;
		CancelSelection_guess();
	}
	if (g_monsterTemplateRegistry_guess != 0)
	{
		int value_guess = (int)&helper.field_15c_guess;
		g_monsterTemplateRegistry_guess->FUN_00518b72_guess(&value_guess);
	}
	return 1;
}

struct ProgressionListControl_guess : ProgressionWindow_guess
{
	char pad_004[0x150];
	int field_154_guess;
	char field_158_guess;
};

struct ProgressionIdPair_guess
{
	int key_guess;
	int textId_guess;
};

struct ProgressionTextPair_guess
{
	int key_guess;
	char text_guess[0x40];
};

struct ProgressionIterator_guess
{
	char pad[0x10];

	// EXTERNAL: TITANIUM 0x004466FA ProgressionIterator_guess::begin_guess
	void* begin_guess(void);
	// EXTERNAL: TITANIUM 0x0042EC1A ProgressionIterator_guess::next_guess
	void* next_guess(void* iterator_guess);
};

struct ProgressionRecord_guess
{
	char pad_000[0x44];
	char text_044_guess[1];
	char pad_045[0xfa7];
	int textId_fec_guess;
	char pad_ff0[4];
	int value_ff4_guess;
	char pad_ff8[4];
	int value_ffc_guess;
	int value_1000_guess;
	int value_1004_guess;
	int value_1008_guess;
	int value_100c_guess;
	int value_1010_guess;
	int value_1014_guess;
	int value_1018_guess;
	int value_101c_guess;
	int value_1020_guess;
	char pad_1024[4];
	ProgressionIterator_guess collection_1028_guess;
	ProgressionIterator_guess collection_1038_guess;
};

struct AnimationTarget_guess
{
	char pad_000[0x2d];
	char flag_02d_guess;

	// EXTERNAL: TITANIUM 0x004DBB3B AnimationTarget_guess::FUN_004dbb3b_guess
	void FUN_004dbb3b_guess(void* resource_guess);
};

struct AnimationOwner_guess
{
	char pad_000[0x64];
	AnimationTarget_guess* target_064_guess;
};

struct WindowManager_guess
{
	// EXTERNAL: TITANIUM 0x005B44A0 WindowManager_guess::FUN_005b44a0_guess
	void* FUN_005b44a0_guess(CXStr* name_guess);
};

#define g_windowManager_guess EQ_GLOBAL(WindowManager_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x00416C2C ClassName_guess
char* __cdecl ClassName_guess(int textId_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, int stringId_guess, const char* value_guess,
	int zero_0_guess, int zero_1_guess, int zero_2_guess, int zero_3_guess,
	int zero_4_guess, int zero_5_guess, int zero_6_guess, int zero_7_guess);

// Shows the selected template (`value_guess`: 1 from a click, 0 when pushed): class name and the
// A_ClassAnim<class> animation, "level %1" (string 4556), HP, mana, endurance and the seven stats, the AA
// list (dbstr type 1 names) and the equipment list; the accept button follows the sign of the item data.
// FUNCTION: TITANIUM 0x00549DCD
void CProgressionSelectionWndView_guess::ShowSelectedStep_guess(int value_guess)
{
	ClearTemplateInfo_guess();
	if (g_monsterTemplateRegistry_guess == 0 || field_168_guess == 0)
		return;

	int selectedIndex_guess = ((CListWnd*)field_168_guess)->GetCurSel();
	if (selectedIndex_guess < 0)
		return;

	// A negative item id marks a step that cannot be taken: the id is flipped for the lookup and Accept is
	// disabled at the end.
	char positive_guess = 1;
	int selectedValue_guess = (int)((CListWnd*)field_168_guess)->GetItemData(selectedIndex_guess);
	if (selectedValue_guess < 0)
	{
		selectedValue_guess = -selectedValue_guess;
		positive_guess = 0;
	}

	ProgressionRecord_guess* record_guess = g_monsterTemplateRegistry_guess->GetProgressionRecord_guess(selectedValue_guess, value_guess);
	if (record_guess == 0)
		return;

	CXStr formatted_guess;
	if (field_184_guess != 0)
	{
		CXStr text_guess(ClassName_guess(record_guess->textId_fec_guess));
		field_184_guess->Slot63_guess(text_guess);
	}

	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_ff4_guess);
	char description_guess[0x80];
	// The level line through string 4556; the stats from HP to WIS follow as plain numbers.
	FUN_0046da4a_guess(description_guess, 0x11cc, (char*)formatted_guess, 0, 0, 0, 0, 0, 0, 0, 0);
	if (field_188_guess != 0)
	{
		CXStr text_guess(description_guess);
		field_188_guess->Slot63_guess(text_guess);
	}

	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_ffc_guess);
	if (field_18c_guess != 0)
		field_18c_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1000_guess);
	if (field_190_guess != 0)
		field_190_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1004_guess);
	if (field_194_guess != 0)
		field_194_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1008_guess);
	if (field_198_guess != 0)
		field_198_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_100c_guess);
	if (field_19c_guess != 0)
		field_19c_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1010_guess);
	if (field_1a0_guess != 0)
		field_1a0_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1014_guess);
	if (field_1a4_guess != 0)
		field_1a4_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1018_guess);
	if (field_1a8_guess != 0)
		field_1a8_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_101c_guess);
	if (field_1ac_guess != 0)
		field_1ac_guess->Slot63_guess(formatted_guess);
	FUN_005738b0_guess(&formatted_guess, EQ_ARRAY(char, 0x0063F53C), record_guess->value_1020_guess);
	if (field_1b0_guess != 0)
		field_1b0_guess->Slot63_guess(formatted_guess);

	// Abilities list, then sorted by column 0 ascending (list slot 78, as for a column click).
	if (field_16c_guess != 0)
	{
		void* iterator_guess = record_guess->collection_1028_guess.begin_guess();
		while (iterator_guess != 0)
		{
			ProgressionIdPair_guess* pair_guess = *(ProgressionIdPair_guess**)iterator_guess;
			int row_guess;
			{
				CXStr text_guess(g_progressionDatabase_guess->FUN_004355f7_guess(pair_guess->textId_guess, 1, 0));
				row_guess = ((CListWnd*)field_16c_guess)->AddString(text_guess, 0xffffffff, 0, 0);
			}
			((CListWnd*)field_16c_guess)->SetItemData(row_guess, pair_guess->key_guess);
			iterator_guess = record_guess->collection_1028_guess.next_guess(iterator_guess);
		}
		((ProgressionListControl_guess*)field_16c_guess)->field_154_guess = 0;
		((ProgressionListControl_guess*)field_16c_guess)->field_158_guess = 1;
		((ProgressionListControl_guess*)field_16c_guess)->Slot78_guess();
	}

	if (field_170_guess != 0)
	{
		void* iterator_guess = record_guess->collection_1038_guess.begin_guess();
		while (iterator_guess != 0)
		{
			ProgressionTextPair_guess* pair_guess = *(ProgressionTextPair_guess**)iterator_guess;
			int row_guess;
			{
				CXStr label_guess(EQ_ARRAY(char, 0x0063F53F));
				row_guess = ((CListWnd*)field_170_guess)->AddString(label_guess, 0xffffffff, 0, 0);
			}
			((CListWnd*)field_170_guess)->SetItemData(row_guess, pair_guess->key_guess);
			{
				CXStr text_guess(pair_guess->text_guess);
				((CListWnd*)field_170_guess)->SetItemText(row_guess, 0, text_guess);
			}
			iterator_guess = record_guess->collection_1038_guess.next_guess(iterator_guess);
		}
	}

	if (field_174_guess != 0)
		field_174_guess->SetSTMLText(CXStr(record_guess->text_044_guess), true, 0);

	// The class animation A_ClassAnim%02d for the template's class id.
	if (field_208_guess != 0 && field_208_guess->target_064_guess != 0)
	{
		CXStr animationName_guess;
		FUN_005738b0_guess(&animationName_guess, EQ_ARRAY(char, 0x0065674C), record_guess->textId_fec_guess);
		void* animation_guess = g_windowManager_guess->FUN_005b44a0_guess(&animationName_guess);
		if (animation_guess != 0)
		{
			field_208_guess->target_064_guess->FUN_004dbb3b_guess(animation_guess);
			field_208_guess->target_064_guess->flag_02d_guess = 0;
		}
	}

	if (field_178_guess != 0)
		field_178_guess->flag_5d_guess = positive_guess;
}

struct PrimaryBase_00549ccc_guess
{
	// EXTERNAL: TITANIUM 0x005A3100 PrimaryBase_00549ccc_guess::~PrimaryBase_00549ccc_guess
	virtual ~PrimaryBase_00549ccc_guess();
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
	virtual void Slot48_guess(int first_guess, int second_guess);	// vtable +0xC0
	char pad[0x158];

	// EXTERNAL: TITANIUM 0x005A3900 ??0PrimaryBase_00549ccc_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
	PrimaryBase_00549ccc_guess(CXWnd* parent_guess, const CXStr& screen_guess);
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7SecondaryBase_00549ccc_guess@@6B@
struct SecondaryBase_00549ccc_guess
{
	virtual void Slot00_guess(void);
};

// CTextureAnimation (0x4C bytes); slot 0 is its deleting destructor.
struct Callback_00549ccc_guess
{
	virtual void Slot00_guess(int value);
	char pad_04[0x48];
	// EXTERNAL: TITANIUM 0x005B1D90 ??0Callback_00549ccc_guess@@QAE@XZ
	Callback_00549ccc_guess();
	// EXTERNAL: TITANIUM 0x005B1730 Callback_00549ccc_guess::Restart_guess
	void Restart_guess(int zero_guess);
};

struct Point_00549ccc_guess
{
	int x_guess;
	int y_guess;
	Point_00549ccc_guess(int x, int y) : x_guess(x), y_guess(y) {}
};

struct Owner_00549ccc_guess;

struct StatsPane_00549ccc_guess
{
	char pad_00[0x20];
	Point_00549ccc_guess pos_20_guess;	// 0x20
	char pad_28[0x3C];
	unsigned int style_64_guess;		// 0x64
	// EXTERNAL: TITANIUM 0x005A2490 StatsPane_00549ccc_guess::GetChild_guess
	Owner_00549ccc_guess* GetChild_guess(const CXStr& name_guess);
};

struct ProgressionListWnd_guess : CListWnd
{
	char pad_140[0x2C];
	unsigned long color_16c_guess;	// 0x16C
};

struct Owner_00549ccc_guess
{
	char pad[0x64];
	Callback_00549ccc_guess* callback_64_guess;
};

struct Member_00549ccc_guess
{
	char pad[0x4C];
	Owner_00549ccc_guess* owner_208_guess;

	// EXTERNAL: TITANIUM 0x005B1D90 ??0Member_00549ccc_guess@@QAE@XZ
	Member_00549ccc_guess();
	// EXTERNAL: TITANIUM 0x004DBB3B ??4Member_00549ccc_guess@@QAEAAU0@ABU0@@Z
	Member_00549ccc_guess& operator=(const Member_00549ccc_guess& other);
	// EXTERNAL: TITANIUM 0x005B1EB0 Member_00549ccc_guess::~Member_00549ccc_guess
	~Member_00549ccc_guess();
};

struct AnimMgr_00549ccc_guess
{
	// EXTERNAL: TITANIUM 0x005B44A0 AnimMgr_00549ccc_guess::Find_guess
	Member_00549ccc_guess* Find_guess(const CXStr& name_guess);
};

#define g_animMgr_00549ccc_guess EQ_GLOBAL(AnimMgr_00549ccc_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x0065AE78 ??_7CProgressionSelectionWnd_guess@@6BPrimaryBase_00549ccc_guess@@@
// EXTERNAL: TITANIUM 0x0065AE74 ??_7CProgressionSelectionWnd_guess@@6BSecondaryBase_00549ccc_guess@@@
struct CProgressionSelectionWnd_guess : PrimaryBase_00549ccc_guess, SecondaryBase_00549ccc_guess
{
	ProgressionListWnd_guess* list_160_guess;
	ProgressionListWnd_guess* list_164_guess;
	ProgressionListWnd_guess* list_168_guess;
	ProgressionListWnd_guess* list_16c_guess;
	ProgressionListWnd_guess* list_170_guess;
	CXWnd* info_174_guess;
	CXWnd* accept_178_guess;
	CXWnd* cancel_17c_guess;
	CXWnd* topLayout_180_guess;
	CXWnd* labels_184_guess[12];
	StatsPane_00549ccc_guess* statsPane_1b4_guess;
	CXWnd* iconButton_1b8_guess;
	Member_00549ccc_guess member_1bc_guess;
	unsigned int field_20c_guess;
	unsigned int field_210_guess;
	char flag_214_guess;

	CProgressionSelectionWnd_guess(CXWnd* parent_guess);
	virtual ~CProgressionSelectionWnd_guess();
	void* DeletingDestructor_guess(unsigned char flags_guess);
	// EXTERNAL: TITANIUM 0x0059DD30 CProgressionSelectionWnd_guess::IsReady_guess
	char IsReady_guess();
	// EXTERNAL: TITANIUM 0x00549A6D CProgressionSelectionWnd_guess::ShowSelectedProgression_guess
	void ShowSelectedProgression_guess(void);
	// EXTERNAL: TITANIUM 0x00549BC2 CProgressionSelectionWnd_guess::ShowSelectedBranch_guess
	void ShowSelectedBranch_guess(void);
	// EXTERNAL: TITANIUM 0x00549DCD CProgressionSelectionWnd_guess::ShowSelectedStep_guess
	void ShowSelectedStep_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x005A0E50 CProgressionSelectionWnd_guess::OnProcessFrame
	int OnProcessFrame();
	void ProcessFrame_guess(void);
};

// Unregisters from the registry (0x79C120) and frees the class-animation texture made by the ctor.
// FUNCTION: TITANIUM 0x00549CCC
CProgressionSelectionWnd_guess::~CProgressionSelectionWnd_guess()
{
	if (g_monsterTemplateRegistry_guess != 0)
	{
		int secondary_guess = (int)static_cast<SecondaryBase_00549ccc_guess*>(this);
		g_monsterTemplateRegistry_guess->FUN_00518b72_guess(&secondary_guess);
	}
	if (member_1bc_guess.owner_208_guess != 0 && member_1bc_guess.owner_208_guess->callback_64_guess != 0)
	{
		Callback_00549ccc_guess* callback_guess = member_1bc_guess.owner_208_guess->callback_64_guess;
		callback_guess->Slot00_guess(1);
		member_1bc_guess.owner_208_guess->callback_64_guess = 0;
	}
}

// Binds the SIDL children (lists, value labels, stats pane), gives the five lists the same colours and the
// ClassAnim slot its own animation (A_DragItem as the template), starts with accept disabled.
// FUNCTION: TITANIUM 0x0054A413
CProgressionSelectionWnd_guess::CProgressionSelectionWnd_guess(CXWnd* parent_guess)
	: PrimaryBase_00549ccc_guess(parent_guess, "ProgressionSelectionWnd")
{
	list_160_guess = 0;
	list_164_guess = 0;
	list_168_guess = 0;
	list_16c_guess = 0;
	list_170_guess = 0;
	info_174_guess = 0;
	accept_178_guess = 0;
	cancel_17c_guess = 0;
	topLayout_180_guess = 0;
	labels_184_guess[0] = 0;
	labels_184_guess[1] = 0;
	labels_184_guess[2] = 0;
	labels_184_guess[3] = 0;
	labels_184_guess[4] = 0;
	labels_184_guess[5] = 0;
	labels_184_guess[6] = 0;
	labels_184_guess[7] = 0;
	labels_184_guess[8] = 0;
	labels_184_guess[9] = 0;
	labels_184_guess[10] = 0;
	labels_184_guess[11] = 0;
	statsPane_1b4_guess = 0;
	iconButton_1b8_guess = 0;
	member_1bc_guess.owner_208_guess = 0;
	field_20c_guess = 0;
	flag_214_guess = 0;
	CSidlScreenWnd* sidl_guess = (CSidlScreenWnd*)(PrimaryBase_00549ccc_guess*)this;
	if (sidl_guess->SidlPiece == 0)
		return;
	sidl_guess->CreateChildrenFromSidl();
	info_174_guess = sidl_guess->GetChildItem("ProgressionSelectionInfo");
	list_160_guess = (ProgressionListWnd_guess*)sidl_guess->GetChildItem("ProgressionList");
	list_164_guess = (ProgressionListWnd_guess*)sidl_guess->GetChildItem("ProgressionBranchList");
	list_168_guess = (ProgressionListWnd_guess*)sidl_guess->GetChildItem("ProgressionStepList");
	list_16c_guess = (ProgressionListWnd_guess*)sidl_guess->GetChildItem("ProgressionSelectionAbilitiesList");
	list_170_guess = (ProgressionListWnd_guess*)sidl_guess->GetChildItem("ProgressionSelectionEquipmentList");
	accept_178_guess = sidl_guess->GetChildItem("ProgressionTemplateSelectAcceptButton");
	cancel_17c_guess = sidl_guess->GetChildItem("ProgressionTemplateSelectCancelButton");
	topLayout_180_guess = sidl_guess->GetChildItem("ProgressionTemplateTopLayout");
	labels_184_guess[0] = sidl_guess->GetChildItem("ClassValueLabel");
	labels_184_guess[1] = sidl_guess->GetChildItem("LevelValueLabel");
	labels_184_guess[2] = sidl_guess->GetChildItem("HitPointsValueLabel");
	labels_184_guess[3] = sidl_guess->GetChildItem("ManaValueLabel");
	labels_184_guess[4] = sidl_guess->GetChildItem("EnduranceValueLabel");
	labels_184_guess[5] = sidl_guess->GetChildItem("StrengthValueLabel");
	labels_184_guess[6] = sidl_guess->GetChildItem("StaminaValueLabel");
	labels_184_guess[7] = sidl_guess->GetChildItem("CharismaValueLabel");
	labels_184_guess[8] = sidl_guess->GetChildItem("DexterityValueLabel");
	labels_184_guess[9] = sidl_guess->GetChildItem("IntelligenceValueLabel");
	labels_184_guess[10] = sidl_guess->GetChildItem("AgilityValueLabel");
	labels_184_guess[11] = sidl_guess->GetChildItem("WisdomValueLabel");
	statsPane_1b4_guess = (StatsPane_00549ccc_guess*)sidl_guess->GetChildItem("ProgressionSelectionStatsPane");
	iconButton_1b8_guess = sidl_guess->GetChildItem("ProgressionSelectionItemIconButton");
	// The item icon draws with a copy of A_DragItem; the stats pane's ClassAnim gets its own animation object.
	Member_00549ccc_guess* anim_guess = g_animMgr_00549ccc_guess->Find_guess("A_DragItem");
	if (anim_guess != 0)
		member_1bc_guess = *anim_guess;
	if (statsPane_1b4_guess != 0)
	{
		member_1bc_guess.owner_208_guess = statsPane_1b4_guess->GetChild_guess("ClassAnim");
		if (member_1bc_guess.owner_208_guess != 0)
			member_1bc_guess.owner_208_guess->callback_64_guess = new Callback_00549ccc_guess;
		statsPane_1b4_guess->style_64_guess &= ~0x800;
	}
	// Progression, branch and step lists share one colour set with column 1 right-justified; the abilities
	// and equipment lists use the same colours with style 0x40000.
	if (list_160_guess != 0)
	{
		list_160_guess->SetColors(0xffffffff, 0xffffff00, 0xff324080);
		list_160_guess->color_16c_guess = 0xff8aa3ff;
		list_160_guess->SetColumnJustification(1, 2);
	}
	if (list_164_guess != 0)
	{
		list_164_guess->SetColors(0xffffffff, 0xffffff00, 0xff324080);
		list_164_guess->color_16c_guess = 0xff8aa3ff;
		list_164_guess->SetColumnJustification(1, 2);
	}
	if (list_168_guess != 0)
	{
		list_168_guess->SetColors(0xffffffff, 0xffffff00, 0xff324080);
		list_168_guess->color_16c_guess = 0xff8aa3ff;
		list_168_guess->SetColumnJustification(1, 2);
	}
	if (list_16c_guess != 0)
	{
		list_16c_guess->WindowStyle |= 0x40000;
		list_16c_guess->SetColors(0xffffffff, 0xffffff00, 0xff324080);
		list_16c_guess->color_16c_guess = 0xff8aa3ff;
	}
	if (list_170_guess != 0)
	{
		list_170_guess->WindowStyle |= 0x40000;
		list_170_guess->SetColors(0xffffffff, 0xffffff00, 0xff324080);
		list_170_guess->color_16c_guess = 0xff8aa3ff;
	}
	if (statsPane_1b4_guess != 0)
		statsPane_1b4_guess->pos_20_guess = Point_00549ccc_guess(0x6c, 0);
	if (cancel_17c_guess != 0)
		cancel_17c_guess->Enabled = 1;
	// Accept stays off until a step is selected.
	if (accept_178_guess != 0)
		accept_178_guess->Enabled = 0;
	field_210_guess = 0;
	((CProgressionSelectionWndView_guess*)(PrimaryBase_00549ccc_guess*)this)->LoadLayout_guess();
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Scalar deleting destructor of the progression selection window (vtable 0x65AE78 slot 1): runs the
// destructor (0x00549CCC) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0054AC1F
void* CProgressionSelectionWnd_guess::DeletingDestructor_guess(unsigned char flags_guess)
{
	this->CProgressionSelectionWnd_guess::~CProgressionSelectionWnd_guess();
	if ((flags_guess & 1) != 0)
		free(this);
	return this;
}

#define g_00905ce4_guess EQ_GLOBAL(int, 0x00905CE4)

struct Display_guess
{
	char pad_000[0x148];
	unsigned int frameTime_0148_guess;
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

// Each frame: restarts the class animation every 5 s; once a second asks the registry whether the player
// can still use the window, else prints 4555 and closes; selects row 0 of an unselected list.
// FUNCTION: TITANIUM 0x0054AC3B
void CProgressionSelectionWnd_guess::ProcessFrame_guess(void)
{
	if (IsReady_guess())
	{
		if (member_1bc_guess.owner_208_guess != 0 && member_1bc_guess.owner_208_guess->callback_64_guess != 0)
		{
			if (g_display_guess->frameTime_0148_guess > field_20c_guess)
			{
				field_20c_guess = g_display_guess->frameTime_0148_guess + 5000;
				member_1bc_guess.owner_208_guess->callback_64_guess->Restart_guess(0);
			}
		}
		if (g_display_guess->frameTime_0148_guess > field_210_guess)
		{
			field_210_guess = g_display_guess->frameTime_0148_guess + 1000;
			if (g_monsterTemplateRegistry_guess == 0 || !g_monsterTemplateRegistry_guess->IsWithinRange_guess(g_00905ce4_guess))
			{
				pEverQuest->dsp_chat(pStringTable->getString(0x11CB, 0));
				Slot48_guess(0, 1);
			}
		}
		if (list_160_guess != 0 && list_160_guess->GetCurSel() == -1 && list_160_guess->ItemsCount != 0)
		{
			list_160_guess->SetCurSel(0);
			ShowSelectedProgression_guess();
		}
		if (list_164_guess != 0 && list_164_guess->GetCurSel() == -1 && list_164_guess->ItemsCount != 0)
		{
			list_164_guess->SetCurSel(0);
			ShowSelectedBranch_guess();
		}
		if (list_168_guess != 0 && list_168_guess->GetCurSel() == -1 && list_168_guess->ItemsCount != 0)
		{
			list_168_guess->SetCurSel(0);
			ShowSelectedStep_guess(1);
		}
	}
	OnProcessFrame();
}

struct CProgressionSelectionWndOpenView_guess : ProgressionWindow_guess
{
	// EXTERNAL: TITANIUM 0x005499CB CProgressionSelectionWndOpenView_guess::FillProgressionList_guess
	void FillProgressionList_guess(void);
	// EXTERNAL: TITANIUM 0x0059D080 CProgressionSelectionWndOpenView_guess::FUN_0059d080_guess
	void FUN_0059d080_guess(int value_guess);

	void Open_guess(void);
};

// Fills the progression list and shows the window.
// FUNCTION: TITANIUM 0x00549DB0
void CProgressionSelectionWndOpenView_guess::Open_guess(void)
{
	FillProgressionList_guess();
	Slot33_guess();
	FUN_0059d080_guess(1);
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message_guess);

struct ProgressionMsg_0054ad79_guess
{
	unsigned int field_00_guess;	// 0x00: GetItemData of the selected row
	unsigned int flags_04_guess;	// 0x04: |= 2 with keyboard flag 1
	char name_08_guess[0x40];		// 0x08: text of the selected row
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Selection (message 1) in a list drives the cascade; accept sends the template and closes, cancel closes.
// Message 3 on an equipment row asks the server for the item (OP_ItemLinkResponse, 0x48 bytes: item id,
// flags with 2 when keyboard flag 1 is held, name).
// FUNCTION: TITANIUM 0x0054AD79
int CProgressionSelectionWndView_guess::WndNotification_guess(void* target_guess, int msg_guess, int data_guess)
{
	if (msg_guess == 1)
	{
		if (target_guess == field_160_guess)
			ShowSelectedProgression_guess();
		else if (target_guess == field_164_guess)
			ShowSelectedBranch_guess();
		else if (target_guess == field_168_guess)
			ShowSelectedStep_guess(1);
		else if (target_guess == field_170_guess)
			ShowSelectedEquipment_guess();
		else if (target_guess == field_16c_guess)
			ShowSelectedAbility_guess();
		else if (target_guess == field_178_guess)
		{
			flag_214_guess = 1;
			((CProgressionSelectionWndAcceptView_guess*)this)->AcceptSelectedStep_guess();
			((ProgressionWindow_guess*)this)->Slot48_guess(0, 1);
		}
		else if (target_guess == field_17c_guess)
			((ProgressionWindow_guess*)this)->Slot48_guess(0, 1);
	}
	else if (msg_guess == 3 && target_guess == field_170_guess)
	{
		if (field_170_guess != 0)
		{
			ProgressionMsg_0054ad79_guess msg_buf_guess;
			memset(&msg_buf_guess, 0, 0x48);
			if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0)
				msg_buf_guess.flags_04_guess |= 2;
			int row_guess = ((CListWnd*)field_170_guess)->GetCurSel();
			msg_buf_guess.field_00_guess = ((CListWnd*)field_170_guess)->GetItemData(row_guess);
			strcpy(msg_buf_guess.name_08_guess, ((CListWnd*)field_170_guess)->GetItemText(row_guess, 0));
			EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_ItemLinkResponse, &msg_buf_guess, 0x48, 1);
		}
		return 0;
	}
	return ((CSidlScreenWnd*)this)->WndNotification((CXWnd*)target_guess, msg_guess, (void*)data_guess);
}

struct CProgressionSelectionWndTemplateView_guess
{
	// EXTERNAL: TITANIUM 0x00549DCD CProgressionSelectionWndTemplateView_guess::ShowSelectedStep_guess
	void ShowSelectedStep_guess(int value_guess);

	void ShowTemplate_guess(int unused_guess, unsigned char viewable_guess);
};

// Shows a template the server pushed; non-viewable ones are only logged.
// FUNCTION: TITANIUM 0x0054AF10
void CProgressionSelectionWndTemplateView_guess::ShowTemplate_guess(int unused_guess, unsigned char viewable_guess)
{
	if (viewable_guess == 0)
		FUN_00574110_guess("Monster Alt: tried to display an non-viewable template.");
	else
		ShowSelectedStep_guess(0);
}

struct OwnerPrefix_0054af2e_guess
    : PrimaryBase_00549ccc_guess
{
};

struct Event_0054af2e_guess
{
	int kind_guess;
	int first_guess;
	int second_guess;
};

struct CProgressionSelectionWndCallbackView_guess
{
	virtual void HandleEvent_guess(int enabled_guess, Event_0054af2e_guess* event_guess);
	char pad_04[0x08];
	CListWnd* firstList_guess;
	CListWnd* secondList_guess;
	CListWnd* thirdList_guess;
};

struct Owner_0054af2e_guess : OwnerPrefix_0054af2e_guess, CProgressionSelectionWndCallbackView_guess
{
	void Call49db0_guess()
	{
		reinterpret_cast<CProgressionSelectionWndOpenView_guess*>(this)->Open_guess();
	}
	void Call54af10_guess(int first_guess, unsigned char second_guess)
	{
		reinterpret_cast<CProgressionSelectionWndTemplateView_guess*>(this)->ShowTemplate_guess(first_guess, second_guess);
	}
	void Call4957d_guess()
	{
		reinterpret_cast<CProgressionSelectionWndView_guess*>(this)->ShowSelectedEquipment_guess();
	}
	void Call496d3_guess()
	{
		reinterpret_cast<CProgressionSelectionWndView_guess*>(this)->ShowSelectedAbility_guess();
	}
};

// Registry events: 0 open, 1 show a template, 3 / 4 an item or AA the server just sent, redrawn only if it
// belongs to the selected template (first id) and row (second id).
// FUNCTION: TITANIUM 0x0054AF2E
// @early-stop: budget, structural ndiff=25
void CProgressionSelectionWndCallbackView_guess::HandleEvent_guess(int enabled_guess, Event_0054af2e_guess* event_guess)
{
	if (enabled_guess != 0 && event_guess != 0)
	{
		switch (event_guess->kind_guess)
		{
		case 0:
			static_cast<Owner_0054af2e_guess&>(*this).Call49db0_guess();
			break;
		case 1:
			static_cast<Owner_0054af2e_guess&>(*this).Call54af10_guess(
				event_guess->first_guess, (unsigned char)event_guess->second_guess);
			break;
		case 3:
			if (firstList_guess != 0 && thirdList_guess != 0)
			{
				int firstValue_guess = firstList_guess->GetItemData(firstList_guess->GetCurSel());
				if (firstValue_guess < 0)
					firstValue_guess = -firstValue_guess;
				int secondValue_guess = thirdList_guess->GetItemData(thirdList_guess->GetCurSel());
				if (firstValue_guess == event_guess->first_guess && secondValue_guess == event_guess->second_guess)
					static_cast<Owner_0054af2e_guess&>(*this).Call4957d_guess();
			}
			break;
		case 4:
			if (firstList_guess != 0 && secondList_guess != 0)
			{
				int firstValue_guess = firstList_guess->GetItemData(firstList_guess->GetCurSel());
				if (firstValue_guess < 0)
					firstValue_guess = -firstValue_guess;
				int thirdValue_guess = secondList_guess->GetItemData(secondList_guess->GetCurSel());
				if (firstValue_guess == event_guess->first_guess && thirdValue_guess == event_guess->second_guess)
					static_cast<Owner_0054af2e_guess&>(*this).Call496d3_guess();
			}
			break;
		}
	}
}

