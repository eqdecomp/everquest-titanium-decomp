// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 195: a hint from compare/tumap.py.
// Two GM/player text windows: the petition queue (CPetitionQWndView_guess, really CPetitionQWnd) and the
// player notes window (CPlayerNotesWnd_guess, saved to notes.txt). CPetitionQWndView_guess +0x1E0..+0xA8B is
// EQEmu's Petition_Struct: number, urgency (0 normal, 1 urgent, 2 emergency), account, last GM, zone, name,
// level, class, race, checkouts, unavailable count, sent time, then the user and GM texts (1024 bytes each).
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"

struct Notification_guess {
	// EXTERNAL: TITANIUM 0x005B90E0 Notification_guess::SetText_guess
	void SetText_guess(CXStr text, int flags);
};

#define g_notificationText_guess EQ_ARRAY(char, 0x00641588)

struct Slot_guess {
	unsigned char pad_0000[0x5d];
	unsigned char flag_005d;
	unsigned char pad_005e[0xca];
	bool value_0128;
	// EXTERNAL: TITANIUM 0x005BB140 Slot_guess::SetCheck
	void SetCheck(bool value);
};

struct LookupTable_guess {
	// EXTERNAL: TITANIUM 0x005F6ED0 LookupTable_guess::Find_guess
	bool Find_guess(int id, char* out);
};
#define g_lookupTable_guess EQ_GLOBAL(LookupTable_guess*, 0x00905CC0)

struct EverQuestText_guess {
	// EXTERNAL: TITANIUM 0x00491E5B EverQuestText_guess::GetClassDesc
	char* GetClassDesc(int id);
	// EXTERNAL: TITANIUM 0x0049273D EverQuestText_guess::GetRaceDesc
	char* GetRaceDesc(int id);
	// EXTERNAL: TITANIUM 0x0049C800 EverQuestText_guess::Who_guess
	void Who_guess(char* text);
};
#define g_everQuestText_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0060ACA0 Parse_guess
CXStr __cdecl Parse_guess(const CXStr& text);
// EXTERNAL: TITANIUM 0x0046D46D ConvertItemTags
void __cdecl ConvertItemTags(CXStr& text, int flag);

struct Control_guess {
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
	virtual void SetValue_guess(int value, int flags);
	unsigned char pad_0004[0x59];
	unsigned char flag_005d;
};

struct Entry_guess {
	int value_000;
	int kind_004;
	unsigned char pad_008[8];
	char name_010[0x64];
	char text_074[0x44];
};

struct EverQuestData_guess {
	unsigned char pad_0000[0xbac];
	Entry_guess entries_0bac[512];
	int value_17bac;
	int count_17bb0;
};

#define g_everQuestData_guess EQ_GLOBAL(EverQuestData_guess*, 0x00988DF0)
#define g_format_guess EQ_ARRAY(char, 0x0063F53C)
#define g_separator_guess EQ_ARRAY(char, 0x0063FE10)

struct WindowVtable_guess {
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
	virtual void Slot3F_guess(CXStr* text);
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
	virtual void Slot76_guess();
};

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text, const char* format, ...);

struct Base_guess {
	// EXTERNAL: TITANIUM 0x005A3100 ??1Base_guess@@UAE@XZ
	virtual ~Base_guess();
	// EXTERNAL: TITANIUM 0x005A3900 ??0Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
	Base_guess(CXWnd* parent, const CXStr& screen);
	unsigned char pad_0004[0x60];
	unsigned int style_0064;
	unsigned char pad_0068[0xbc];
	int value_0124;
	unsigned char pad_0128[0x34];
};

struct SidlPiece_guess {
	unsigned char pad_0000[0x60];
	unsigned int flags_0060;
};

struct EditWnd_guess {
	// EXTERNAL: TITANIUM 0x004D7EBC ?SetMaxChars_guess@EditWnd_guess@@QAEXH@Z
	void SetMaxChars_guess(int max);
};

struct Source_guess {
	// EXTERNAL: TITANIUM 0x004F6895 Source_guess::GetText_guess
	CXStr GetText_guess();
	// EXTERNAL: TITANIUM 0x005A8B00 Source_guess::SetSTMLText
	void SetSTMLText(CXStr text, bool flags, SLinkInfo* value);
};

struct TextWnd_guess {
	// EXTERNAL: TITANIUM 0x005B7ED0 TextWnd_guess::GetText_guess
	CXStr GetText_guess();
};

struct Named_guess {
	unsigned char pad_0000[0x120];
	char text_0120[0x40];
};

struct StrAppend_guess {
	// EXTERNAL: TITANIUM 0x00572C10 StrAppend_guess::Append_guess
	void Append_guess(const CXStr& text);
};

// EXTERNAL: TITANIUM 0x00491125 eqlog_guess
void __cdecl eqlog_guess(const char* text);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, int textId, const char* p0, const char* p1,
	const char* p2, const char* p3, const char* p4, const char* p5, const char* p6,
	const char* p7, const char* p8);

#define g_logPetitions_guess EQ_GLOBAL(int, 0x00924788)

struct ColorText_guess {
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
	unsigned char pad_0004[0x78];
	unsigned int color_007c;
};

// EXTERNAL: TITANIUM 0x0065A468 ??_7CPetitionQWndView_guess@@6B@
struct CPetitionQWndView_guess : Base_guess {
	Notification_guess* notification_015c[1];
	CXWnd* text_0160;
	Control_guess* control_0164;
	Source_guess* source_0168;
	Source_guess* source_016c;
	WindowVtable_guess* window_0170;
	Slot_guess* slot_0174;
	Slot_guess* slot_0178;
	Slot_guess* slot_017c;
	Slot_guess* slot_0180;
	Slot_guess* slot_0184;
	Slot_guess* slot_0188;
	ColorText_guess* text_018c;
	Slot_guess* slot_0190;
	WindowVtable_guess* window_0194;
	WindowVtable_guess* window_0198;
	WindowVtable_guess* window_019c;
	WindowVtable_guess* window_01a0;
	WindowVtable_guess* window_01a4;
	WindowVtable_guess* window_01a8;
	WindowVtable_guess* window_01ac;
	WindowVtable_guess* window_01b0;
	Slot_guess* slot_01b4;
	Control_guess* control_01b8;
	Slot_guess* slot_01bc;
	Slot_guess* slot_01c0;
	Control_guess* control_01c4;
	Control_guess* control_01c8;
	WindowVtable_guess* window_01cc;
	WindowVtable_guess* window_01d0;
	Slot_guess* slots_01d4[3];
	int state_01e0;
	int value_01e4;
	unsigned char flag_01e8;
	unsigned char pad_01e9[0x1f];
	unsigned char flag_0208;
	unsigned char pad_0209[0x1f];
	int value_0228;
	unsigned char result_022c;
	unsigned char pad_022d[0x3f];
	int value_026c;
	int playerClass_0270_guess;
	int race_0274_guess;
	unsigned char pad_0278[4];
	int value_027c;
	int value_0280;
	int timestamp_0284_guess;
	unsigned char pad_0288[4];
	unsigned char flag_028c;
	unsigned char pad_028d[0x3ff];
	union {
		unsigned char flag_068c;
		char name_068c[0x400];
	};
	bool output_0a8c[3];
	char name_0a8f[0x40];

	virtual ~CPetitionQWndView_guess();
	void* ScalarDeletingDestructor_guess(unsigned int flags);
	void UndoCheckout_guess();
	void UpdatePetitionList_guess();
	void AddGMText_guess();
	bool AboutToShow_guess();
	bool PlayerNotesAboutToShow_guess();
	unsigned char* GetPetitionerName_guess();
	void EnableFilters_guess(unsigned char value);
	void ReadFilters_guess();
	void SetCheckedOutMode_guess(int value, int flag);
	void WndNotification_guess(int first, int kind, int third);
	void LogPetitionText_guess();
	// EXTERNAL: TITANIUM 0x005A2230 CPetitionQWndView_guess::WndNotification
	int WndNotification(int first, int kind, int third);
	int WndNotification_guess(void* sender, int msg, void* data);
	void ClearPetition_guess();
	void ShowPetition_guess();
	void SetPriorityDisplay_guess();
	void CheckedOut_guess(const void* src, size_t size);
};

// Refills the petition list from pEverQuest's table (+0xBAC, 512 records of 0xB8 bytes, count at +0x17BB0):
// green normal, yellow urgent, red emergency; the three filter checkboxes hide a level. Reselects the row
// whose name matches the last checked-out petitioner and puts the queue count in the title.
// FUNCTION: TITANIUM 0x005433CE
void CPetitionQWndView_guess::UpdatePetitionList_guess() {
	CXStr title;
	int selected = -1;
	int i = 0;
	do {
		if (slots_01d4[i] != 0)
			((CButtonWnd*)slots_01d4[i])->SetCheck(output_0a8c[i]);
		++i;
	} while (i < 3);

	((CListWnd*)notification_015c[0])->ClearAllSel();
	((WindowVtable_guess*)notification_015c[0])->Slot76_guess();

	i = 0;
	if (g_everQuestData_guess->count_17bb0 > 0) {
		do {
			if (g_everQuestData_guess->entries_0bac[i].value_000 > -1) {
				char show;
				unsigned long color;
				if (g_everQuestData_guess->entries_0bac[i].kind_004 == 1) {
					color = 0xFFFFFF00;
					show = output_0a8c[1] == 0;
				} else if (g_everQuestData_guess->entries_0bac[i].kind_004 >= 2) {
					color = 0xFFFF0000;
					show = output_0a8c[2] == 0;
				} else {
					color = 0xFF00FF00;
					show = output_0a8c[0] == 0;
				}
				if (show) {
					CXStr text(g_everQuestData_guess->entries_0bac[i].name_010);
					text += g_separator_guess;
					text += g_everQuestData_guess->entries_0bac[i].text_074;
					int index = ((CListWnd*)notification_015c[0])->AddString(text, color, 0, 0);
					((CListWnd*)notification_015c[0])->SetItemData(index, i);
					if (strcmp(name_0a8f, g_everQuestData_guess->entries_0bac[i].name_010) == 0)
						selected = index;
				}
			}
			++i;
		} while (i < g_everQuestData_guess->count_17bb0);
		if (selected != -1)
			((CListWnd*)notification_015c[0])->SetCurSel(selected);
	}

	FormatString_guess(&title, g_format_guess, g_everQuestData_guess->value_17bac);
	((WindowVtable_guess*)text_0160)->Slot3F_guess(&title);
}

// Shows the urgency as NORMAL/URGENT/EMERGENCY (strings 2153-2155) in green/yellow/red, and enables the
// upgrade button below 2 and the downgrade button above 0.
// FUNCTION: TITANIUM 0x005435B5
// @early-stop: budget, diff ndiff=13
void CPetitionQWndView_guess::SetPriorityDisplay_guess() {
	CXStr text;
	unsigned int color;
	{
		Slot_guess* slot = slot_0190;
		slot->flag_005d = value_01e4 < 2;
	}
	{
		Slot_guess* slot = slot_0188;
		slot->flag_005d = value_01e4 > 0;
	}
	text = pStringTable->getString(0x869, 0);
	color = 0xff00ff00;
	if (value_01e4 == 1) {
		color = 0xffffff00;
		text = pStringTable->getString(0x86a, 0);
	}
	if (value_01e4 >= 2) {
		color = 0xffff0000;
		text = pStringTable->getString(0x86b, 0);
	}
	text_018c->color_007c = color;
	text_018c->Slot63_guess(text);
}

// Appends "<BR><GM name>: <input>" to the petition's GM text (1024-byte limit, string 3143 when it would
// overflow), clears the input and echoes "GM Text added:" (string 3142) to chat.
// FUNCTION: TITANIUM 0x0054369F
// @early-stop: budget, structural ndiff=35
void CPetitionQWndView_guess::AddGMText_guess() {
	CXStr src = ((TextWnd_guess*)window_0170)->GetText_guess();
	CXStr msg;
	if ((src.Ptr ? src.Ptr->length : 0) > 0) {
		char* name = name_068c;
		size_t nameLen = strlen(name);
		if (strlen(EQ_GLOBAL(Named_guess*, 0x00905CE4)->text_0120) + 10 + nameLen +
				(src.Ptr ? src.Ptr->length : 0) < 0x400) {
			msg = name;
			if ((msg.Ptr ? msg.Ptr->length : 0) > 0)
				msg += "<BR>";
			msg += EQ_GLOBAL(Named_guess*, 0x00905CE4)->text_0120;
			msg += EQ_ARRAY(char, 0x006584EC);
			((StrAppend_guess*)&msg)->Append_guess(src);
			{
				CXStr t(EQ_ARRAY(char, 0x0063F53F));
				window_0170->Slot3F_guess(&t);
			}
			((CStmlWnd*)source_016c)->SetSTMLText(msg, true, 0);
			strcpy(name, msg);
			msg = pStringTable->getString(0xc46, 0);
			msg += g_separator_guess;
			msg += EQ_GLOBAL(Named_guess*, 0x00905CE4)->text_0120;
			msg += EQ_ARRAY(char, 0x006584EC);
			((StrAppend_guess*)&msg)->Append_guess(src);
			pEverQuest->dsp_chat(msg);
		} else {
			pEverQuest->dsp_chat(pStringTable->getString(0xc47, 0), 0xd, true);
		}
	}
}

// Forgets the last selection, rebuilds the list and asks the server for a fresh queue (no payload). The
// opcode pass names the value OP_ClientReady (EQEmu's name for it); here it is probably the petition refresh.
// FUNCTION: TITANIUM 0x0054403B
bool CPetitionQWndView_guess::AboutToShow_guess() {
	name_0a8f[0] = 0;
	UpdatePetitionList_guess();
	if (state_01e0 != -1)
		SetCheckedOutMode_guess(0, 1);
	else
		SetCheckedOutMode_guess(1, 0);
	EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_ClientReady, 0, 0, 1);
	return true;
}

// Fills the detail fields from the checked-out petition: text with item links converted, GM text, zone
// name ("Unknown" when not in the zone list), level, class, race, name, checkouts, account, last GM, sent
// time and unavailable count; the three log buttons are reset.
// FUNCTION: TITANIUM 0x005438AC
void CPetitionQWndView_guess::ShowPetition_guess() {
	CXStr a(reinterpret_cast<const char*>(&flag_028c));
	CXStr b = Parse_guess(a);
	ConvertItemTags(b, 1);
	source_0168->SetSTMLText(b, 1, 0);
	source_016c->SetSTMLText(CXStr(reinterpret_cast<const char*>(&flag_068c)), 1, 0);
	slot_017c->SetCheck(0);
	slot_0180->SetCheck(0);
	slot_0184->SetCheck(0);
	char buf[1024];
	bool found = g_lookupTable_guess->Find_guess(value_0228, buf);
	{
		CXStr tmp("Unknown");
		window_01a0->Slot3F_guess(&tmp);
	}
	if (found) {
		CXStr tmp(buf);
		window_01a0->Slot3F_guess(&tmp);
	}
	sprintf(buf, g_format_guess, value_026c);
	{
		CXStr tmp(buf);
		window_01a8->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(g_everQuestText_guess->GetClassDesc(playerClass_0270_guess));
		window_01ac->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(g_everQuestText_guess->GetRaceDesc(race_0274_guess));
		window_01b0->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(reinterpret_cast<const char*>(&result_022c));
		window_01a4->Slot3F_guess(&tmp);
	}
	sprintf(buf, g_format_guess, value_027c);
	{
		CXStr tmp(buf);
		window_019c->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(reinterpret_cast<const char*>(&flag_01e8));
		window_0194->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(reinterpret_cast<const char*>(&flag_0208));
		window_0198->Slot3F_guess(&tmp);
	}
	time_t t = timestamp_0284_guess;
	{
		CXStr tmp(ctime(&t));
		window_01cc->Slot3F_guess(&tmp);
	}
	{
		CXStr tmp(EQ_ARRAY(char, 0x0063F53F));
		window_0170->Slot3F_guess(&tmp);
	}
	sprintf(buf, g_format_guess, value_0280);
	{
		CXStr tmp(buf);
		window_01d0->Slot3F_guess(&tmp);
	}
}

// Writes "USER TEXT: %1" and "GM TEXT: %1" (strings 1373 and 6680) to the log when the flag at 0x924788 is 1.
// FUNCTION: TITANIUM 0x00543DC0
void CPetitionQWndView_guess::LogPetitionText_guess() {
	char buf[1024];
	if (g_logPetitions_guess == 1) {
		FormatText_guess(buf, 0x55d, source_0168->GetText_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
		eqlog_guess(buf);
		FormatText_guess(buf, 0x1a18, source_016c->GetText_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
		eqlog_guess(buf);
	}
}

// The checked-out petitioner's name, or 0 when no petition is checked out (number -1).
// FUNCTION: TITANIUM 0x00543ED1
unsigned char* CPetitionQWndView_guess::GetPetitionerName_guess() {
	unsigned char* result = 0;
	if (state_01e0 != -1)
		result = &result_022c;
	return result;
}

// Enables or disables the three urgency filter checkboxes.
// FUNCTION: TITANIUM 0x00543EE3
void CPetitionQWndView_guess::EnableFilters_guess(unsigned char value) {
	Slot_guess** slot = slots_01d4;
	int count = 3;
	do {
		if (*slot)
			(*slot)->flag_005d = value;
		++slot;
		--count;
	} while (count != 0);
}

// Reads the three urgency filter checkboxes into the hide flags (+0xA8C).
// FUNCTION: TITANIUM 0x00543F04
void CPetitionQWndView_guess::ReadFilters_guess() {
	int i = 0;
	Slot_guess** slot = slots_01d4;
	do {
		if (*slot)
			output_0a8c[i] = (*slot)->value_0128;
		++i;
		++slot;
	} while (i < 3);
}

// Clears the petition record (number -1) and blanks the detail fields. Level resets to 61 (0x3D), not 0;
// that is what the original stores.
// FUNCTION: TITANIUM 0x00543F2B
void CPetitionQWndView_guess::ClearPetition_guess() {
	state_01e0 = -1;
	result_022c = 0;
	flag_0208 = 0;
	flag_068c = 0;
	value_026c = 0x3d;
	value_027c = 0;
	value_01e4 = 0;
	flag_01e8 = 0;
	flag_028c = 0;
	value_0280 = 0;
	ShowPetition_guess();
}

// `value` 1: list mode (filters and Check Out usable); `flag` 1: a petition is checked out and its
// buttons (urgency, log, check in, delete, resolve, add text, ...) are enabled.
// FUNCTION: TITANIUM 0x00543F73
void CPetitionQWndView_guess::SetCheckedOutMode_guess(int value, int flag) {
	control_0164->SetValue_guess(value, 1);
	control_01b8->SetValue_guess(flag, 1);
	if (slot_01bc)
		slot_01bc->flag_005d = (unsigned char)flag;
	slot_01c0->flag_005d = (unsigned char)flag;
	slot_01b4->flag_005d = (unsigned char)flag;
	slot_017c->flag_005d = (unsigned char)flag;
	slot_0180->flag_005d = (unsigned char)flag;
	slot_0184->flag_005d = (unsigned char)flag;
	slot_0174->flag_005d = (unsigned char)flag;
	slot_0188->flag_005d = (unsigned char)flag;
	slot_0190->flag_005d = (unsigned char)flag;
	slot_0178->flag_005d = (unsigned char)flag;
	control_01c8->SetValue_guess(0, 1);
	control_01c4->SetValue_guess(1, 1);
	control_01c4->flag_005d = (unsigned char)flag;
	EnableFilters_guess((unsigned char)value);
}

// The server sent the checked-out petition: copies the whole Petition_Struct, switches to petition mode and
// fills, colours and logs it.
// FUNCTION: TITANIUM 0x0054407F
void CPetitionQWndView_guess::CheckedOut_guess(const void* src, size_t size) {
	memcpy(&state_01e0, src, size);
	SetCheckedOutMode_guess(0, 1);
	ShowPetition_guess();
	SetPriorityDisplay_guess();
	LogPetitionText_guess();
}

// Gives the petition back unchanged ("UNDOING CHECK OUT", string 17034): OP_PetitionQue with its number.
// Also runs when the window closes or is destroyed with a petition still checked out.
// FUNCTION: TITANIUM 0x005440BD
void CPetitionQWndView_guess::UndoCheckout_guess() {
	if (pStringTable != 0)
		pEverQuest->dsp_chat(pStringTable->getString(0x428a, 0), 0x12, 1);
	EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_PetitionQue, &state_01e0, 4, 1);
	SetCheckedOutMode_guess(1, 0);
	ClearPetition_guess();
}

// Destructor of the petition queue window (vtable 0x65A468): with a petition still checked out (+0x1E0
// not -1), gives it back unchanged (0x005440BD); then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00544116
CPetitionQWndView_guess::~CPetitionQWndView_guess() {
	if (state_01e0 != -1)
		UndoCheckout_guess();
}

struct TextGetter_guess {
	virtual void V00_guess(); virtual void V01_guess(); virtual void V02_guess(); virtual void V03_guess();
	virtual void V04_guess(); virtual void V05_guess(); virtual void V06_guess(); virtual void V07_guess();
	virtual void V08_guess(); virtual void V09_guess(); virtual void V10_guess(); virtual void V11_guess();
	virtual void V12_guess(); virtual void V13_guess(); virtual void V14_guess(); virtual void V15_guess();
	virtual void V16_guess(); virtual void V17_guess(); virtual void V18_guess(); virtual void V19_guess();
	virtual void V20_guess(); virtual void V21_guess(); virtual void V22_guess(); virtual void V23_guess();
	virtual void V24_guess(); virtual void V25_guess(); virtual void V26_guess(); virtual void V27_guess();
	virtual void V28_guess(); virtual void V29_guess(); virtual void V30_guess(); virtual void V31_guess();
	virtual void V32_guess(); virtual void V33_guess(); virtual void V34_guess(); virtual void V35_guess();
	virtual void V36_guess(); virtual void V37_guess(); virtual void V38_guess(); virtual void V39_guess();
	virtual void V40_guess(); virtual void V41_guess(); virtual void V42_guess(); virtual void V43_guess();
	virtual void V44_guess(); virtual void V45_guess(); virtual void V46_guess(); virtual void V47_guess();
	virtual void V48_guess(); virtual void V49_guess(); virtual void V50_guess(); virtual void V51_guess();
	virtual void V52_guess(); virtual void V53_guess(); virtual void V54_guess(); virtual void V55_guess();
	virtual void V56_guess(); virtual void V57_guess(); virtual void V58_guess(); virtual void V59_guess();
	virtual void V60_guess(); virtual void V61_guess(); virtual void V62_guess(); virtual void V63_guess();
	virtual void V64_guess(); virtual void V65_guess(); virtual void V66_guess(); virtual void V67_guess();
	virtual void V68_guess(); virtual void V69_guess(); virtual void V70_guess(); virtual void V71_guess();
	virtual void V72_guess(); virtual void V73_guess(); virtual void V74_guess(); virtual void V75_guess();
	virtual CXStr GetText_guess();
};

struct LinkData_guess {
	int values_0000[7];
	unsigned int flags_001c;
	int values_0020[3];
};

// EXTERNAL: TITANIUM 0x0046D3A3 ParseItemLink_guess
int __cdecl ParseItemLink_guess(const char* text, LinkData_guess* out);
// EXTERNAL: TITANIUM 0x004691AF do_inquire_guess
void __cdecl do_inquire_guess(Named_guess* target, const char* text);

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

static int Length_guess(const CXStr& text) {
	return text.Ptr ? text.Ptr->length : 0;
}

// Petition window events. 10 close (undo checkout), 6 Enter in the GM input, 0x1B item link clicked in the
// petition text (OP_ItemLinkClick, flag 2 with Shift), 0xE input edited (enables Add), 1 button click.
// Buttons: urgency down/up (strings 17020-17027), log to bug file 0x72B0, feedback 0x17F, guide log 0x193C
// (all send the record up to the end of the GM text), Check Out 0x10A6 (then /who all <name>), Check In
// 0x588B, Delete 0x3CB4, Resolve 0x42EB, unavailable +/- and do_inquire_guess on "<name> <account>".
// None of these opcodes is named in opcodes.h; their meanings come from the strings next to them.
// FUNCTION: TITANIUM 0x00544157
// @early-stop: budget, structural ndiff=202
int CPetitionQWndView_guess::WndNotification_guess(void* sender, int msg, void* data) {
	char buf[1024];
	char line[256];
	if (msg == 10) {
		UndoCheckout_guess();
	} else if (msg == 6) {
		if (sender == window_0170) {
			AddGMText_guess();
			return 0;
		}
	// An item link clicked in the petition text goes to the server as OP_ItemLinkClick (0x53E5).
	} else if (msg == 0x1b) {
		if (sender == source_0168) {
			LinkData_guess link;
			memset(&link, 0, sizeof(link));
			if (ParseItemLink_guess((const char*)data, &link) == 0) {
				if (pinstCXWndManager_guess->GetKeyboardFlags() & 1)
					link.flags_001c |= 2;
				EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_ItemLinkClick, &link, sizeof(link), 1);
			}
		}
	} else if (msg == 0xe) {
		if (sender == window_0170) {
			slot_0174->flag_005d = Length_guess(((TextGetter_guess*)window_0170)->GetText_guess()) != 0;
			return 0;
		}
	} else if (msg == 1) {
		if (sender == slots_01d4[0] || sender == slots_01d4[1] || sender == slots_01d4[2]) {
			ReadFilters_guess();
			UpdatePetitionList_guess();
			return 0;
		}
		if (sender == notification_015c[0] && state_01e0 == -1) {
			control_0164->flag_005d = 1;
			EnableFilters_guess(1);
			CListWnd* list = (CListWnd*)notification_015c[0];
			strcpy(name_0a8f, g_everQuestData_guess->entries_0bac[list->GetItemData(list->GetCurSel())].name_010);
			return 0;
		}
		if (sender == slot_0174) {
			AddGMText_guess();
			return 0;
		}
		// Urgency down and up within 0-2, with a chat line for each step and an error line at the ends.
		if (sender == slot_0188) {
			if (value_01e4 != 0) {
				if (--value_01e4 < 0)
					value_01e4 = 0;
				strcpy(buf, pStringTable->getString(0x427c, 0));
				if (value_01e4 == 1)
					strcpy(buf, pStringTable->getString(0x427d, 0));
				if (value_01e4 == 2)
					strcpy(buf, pStringTable->getString(0x427e, 0));
				pEverQuest->dsp_chat(buf, 0x12, 1);
			} else {
				pEverQuest->dsp_chat(pStringTable->getString(0x427f, 0), 0xd, 1);
			}
			SetPriorityDisplay_guess();
			return 0;
		}
		if (sender == slot_0190) {
			if (value_01e4 < 2) {
				if (++value_01e4 > 2)
					value_01e4 = 2;
				strcpy(buf, pStringTable->getString(0x4280, 0));
				if (value_01e4 == 1)
					strcpy(buf, pStringTable->getString(0x4281, 0));
				if (value_01e4 == 2)
					strcpy(buf, pStringTable->getString(0x4282, 0));
				pEverQuest->dsp_chat(buf, 0x12, 1);
			} else {
				pEverQuest->dsp_chat(pStringTable->getString(0x4283, 0), 0xd, 1);
			}
			SetPriorityDisplay_guess();
			return 0;
		}
		// Report buttons (0x72B0, 0x17F, 0x193C): the record goes up to the end of the GM text, and the
		// button turns off until the next selection.
		if (sender == slot_017c) {
			pEverQuest->dsp_chat(pStringTable->getString(0x4286, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x72b0, &state_01e0, strlen(name_068c) + 0x4b0, 1);
			slot_017c->flag_005d = 0;
			return 0;
		}
		if (sender == slot_0180) {
			pEverQuest->dsp_chat(pStringTable->getString(0x4287, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x17f, &state_01e0, strlen(name_068c) + 0x4b0, 1);
			slot_0180->flag_005d = 0;
			return 0;
		}
		if (sender == slot_0184) {
			pEverQuest->dsp_chat(pStringTable->getString(0x4288, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x193c, &state_01e0, strlen(name_068c) + 0x4b0, 1);
			slot_0184->flag_005d = 0;
			return 0;
		}
		// Check Out (0x10A6) the selected petition, then a /who all on the petitioner.
		if (sender == control_0164) {
			CListWnd* list = (CListWnd*)notification_015c[0];
			int sel = list->GetCurSel();
			int index = list->GetItemData(sel);
			if (sel != -1) {
				SetCheckedOutMode_guess(0, 0);
				list->SetCurSel(-1);
				pEverQuest->dsp_chat(pStringTable->getString(0x4276, 0), 0x12, 1);
				EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x10a6,
					&g_everQuestData_guess->entries_0bac[index].value_000, 4, 1);
				sprintf(buf, "%s %s", pStringTable->getString(0x3395, 0),
					g_everQuestData_guess->entries_0bac[index].name_010);
				g_everQuestText_guess->Who_guess(buf);
			}
			return 0;
		}
		if (sender == control_01b8) {
			strcpy(name_0a8f, (char*)&flag_01e8);
			UndoCheckout_guess();
			return 0;
		}
		if (sender == slot_01b4) {
			strcpy(name_0a8f, (char*)&flag_01e8);
			pEverQuest->dsp_chat(pStringTable->getString(0x4289, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x588b, &state_01e0, strlen(name_068c) + 0x4b0, 1);
			SetCheckedOutMode_guess(1, 0);
			ClearPetition_guess();
			return 0;
		}
		if (sender == slot_01c0) {
			pEverQuest->dsp_chat(pStringTable->getString(0x428b, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x3cb4, &state_01e0, 4, 1);
			SetCheckedOutMode_guess(1, 0);
			ClearPetition_guess();
			return 0;
		}
		if (sender == slot_01bc) {
			pEverQuest->dsp_chat(pStringTable->getString(0x4295, 0), 0x12, 1);
			EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x42eb, &state_01e0, 4, 1);
			SetCheckedOutMode_guess(1, 0);
			ClearPetition_guess();
			return 0;
		}
		if (sender == control_01c4) {
			control_01c4->SetValue_guess(0, 1);
			control_01c8->SetValue_guess(1, 1);
			++value_0280;
			sprintf(buf, g_format_guess, value_0280);
			CXStr text(buf);
			window_01d0->Slot3F_guess(&text);
			return 0;
		}
		if (sender == control_01c8) {
			control_01c4->SetValue_guess(1, 1);
			control_01c8->SetValue_guess(0, 1);
			--value_0280;
			sprintf(buf, g_format_guess, value_0280);
			CXStr text(buf);
			window_01d0->Slot3F_guess(&text);
			return 0;
		}
		if (sender == slot_0178) {
			sprintf(line, "%s %s", (char*)&result_022c, (char*)&flag_01e8);
			do_inquire_guess(EQ_GLOBAL(Named_guess*, 0x00905CE4), line);
		}
	}
	return WndNotification((int)sender, msg, (int)data);
}

// Scalar deleting destructor of the petition queue window (vtable 0x65A468 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x005448EA
void* CPetitionQWndView_guess::ScalarDeletingDestructor_guess(unsigned int flags) {
	this->CPetitionQWndView_guess::~CPetitionQWndView_guess();
	if (flags & 1)
		operator delete(this);
	return this;
}

// AboutToShow of the player notes window (slot 49 of vtable 0x65A5E0, ctor 0x00544C73 "PlayerNotesWindow"):
// false, with the notes.txt read-only error (string 13224), when +0x124 is 0; the same guard as
// CPlayerNotesWnd_guess::AppendText_guess.
// FUNCTION: TITANIUM 0x00544906
bool CPetitionQWndView_guess::PlayerNotesAboutToShow_guess() {
	if (value_0124 == 0) {
		pEverQuest->dsp_chat(pStringTable->getString(0x33a8, 0));
		return false;
	}
	return true;
}

// Passes the call on to the base window; for kind 6 it first sets the list's text to a newline.
// FUNCTION: TITANIUM 0x00544933
void CPetitionQWndView_guess::WndNotification_guess(int first, int kind, int third) {
	if (kind == 6 && notification_015c[0] != 0)
		notification_015c[0]->SetText_guess(g_notificationText_guess, 1);
	WndNotification(first, kind, third);
	}

struct CText_guess {
	// EXTERNAL: TITANIUM 0x005722D0 CText_guess::Reserve_guess
	void Reserve_guess(int size);
	// EXTERNAL: TITANIUM 0x00571590 CText_guess::GetAt_guess
	char GetAt_guess(int index);
	// EXTERNAL: TITANIUM 0x00572570 CText_guess::SetAt_guess
	void SetAt_guess(int index, char value);
	// EXTERNAL: TITANIUM 0x00572130 CText_guess::SetMarker_guess
	void SetMarker_guess(int index, char value);
	// EXTERNAL: TITANIUM 0x00572380 CText_guess::Find_guess
	bool Find_guess(char value, int* index);
};

struct TextSource_guess {
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
	// slot 76 (0x130): hidden CXStr return
	virtual CXStr GetText_guess();
};

// EXTERNAL: TITANIUM 0x0065A5E0 ??_7CPlayerNotesWnd_guess@@6B@
struct CPlayerNotesWnd_guess : Base_guess {
	/*0x15C*/ TextSource_guess* source_015c;
	CPlayerNotesWnd_guess(CXWnd* parent);
	void SaveNotes_guess();
	void AddText_guess(const CXStr& text);
	virtual ~CPlayerNotesWnd_guess();
};

// EXTERNAL: TITANIUM 0x00576E80 CurrentTime_guess
unsigned long __cdecl CurrentTime_guess(void);

// EXTERNAL: TITANIUM 0x0042E3D9 JoinPrefix_guess
CXStr __cdecl JoinPrefix_guess(const char* format, const CXStr& text);
// EXTERNAL: TITANIUM 0x004B1357 JoinSuffix_guess
CXStr __cdecl JoinSuffix_guess(const CXStr& text, const char* format);

#define g_noteDateFormat_guess EQ_ARRAY(char, 0x0063F9FC)
#define g_notePrefix_guess EQ_ARRAY(char, 0x0065A5C4)
#define g_noteSuffix_guess EQ_ARRAY(char, 0x0065A5C0)

// Appends "[<ctime>] <text>" to the notes and saves notes.txt; item links (0x12 '0'...0x12) get their
// delimiters replaced with marker bytes 8 and 1. Refuses past 10000 characters with string 13224.
// FUNCTION: TITANIUM 0x00544A29
// @early-stop: budget, structural ndiff=39
void CPlayerNotesWnd_guess::AddText_guess(const CXStr& text) {
	if (value_0124 == 0 || source_015c == 0) {
		pEverQuest->dsp_chat(pStringTable->getString(0x33a8, 0));
	} else {
		unsigned long timestamp = CurrentTime_guess();
		CXStr date;
		CXStr result;
		int index = 0;
		FormatString_guess(&date, g_noteDateFormat_guess, ctime((time_t*)&timestamp));
		if (((CText_guess*)&date)->GetAt_guess((date.Ptr ? date.Ptr->length : 0) - 1) == '\n')
			((CText_guess*)&date)->SetAt_guess((date.Ptr ? date.Ptr->length : 0) - 1, ' ');

		{
			CXStr prefix = JoinPrefix_guess(g_notePrefix_guess, date);
			CXStr suffix = JoinSuffix_guess(prefix, g_noteSuffix_guess);
			result = suffix;
		}
		FormatString_guess(&date, EQ_ARRAY(char, 0x0065A5B8), &text);
		while (((CText_guess*)&date)->Find_guess(0x12, &index)) {
			if (((CText_guess*)&date)->GetAt_guess(index + 1) == '0') {
				((CText_guess*)&date)->SetMarker_guess(index, 8);
				if (((CText_guess*)&date)->Find_guess(0x12, &index))
					((CText_guess*)&date)->SetMarker_guess(index, 1);
			}
		}
		((StrAppend_guess*)&result)->Append_guess(date);
		date = source_015c->GetText_guess();
		((StrAppend_guess*)&date)->Append_guess(result);
		if ((date.Ptr ? date.Ptr->length : 0) < 10000) {
			source_015c->Slot63_guess(date);
			SaveNotes_guess();
		} else {
			pEverQuest->dsp_chat(pStringTable->getString(0x33a8, 0));
		}
	}
}

// Builds PlayerNotesWindow and loads notes.txt into its PlayerNotesInput box (10000 characters max).
// FUNCTION: TITANIUM 0x00544C73
CPlayerNotesWnd_guess::CPlayerNotesWnd_guess(CXWnd* parent)
	: Base_guess(parent, "PlayerNotesWindow") {
	if (value_0124 != 0) {
		style_0064 |= ((SidlPiece_guess*)value_0124)->flags_0060;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		source_015c = (TextSource_guess*)((CSidlScreenWnd*)this)->GetChildItem("PlayerNotesInput");
		if (source_015c != 0)
			((EditWnd_guess*)source_015c)->SetMaxChars_guess(10000);
		FILE* file = fopen("notes.txt", "r");
		if (file != 0 && source_015c != 0) {
			if (fseek(file, 0, SEEK_END) == 0) {
				long size = ftell(file);
				fseek(file, 0, SEEK_SET);
				if (size > 0) {
					char* buf = new char[size + 1];
					memset(buf, 0, size + 1);
					fread(buf, 1, size, file);
					{
						CXStr text(buf);
						((WindowVtable_guess*)source_015c)->Slot3F_guess(&text);
					}
					delete[] buf;
				}
			}
			fclose(file);
		}
	}
}

// Writes the whole notes text to notes.txt, one byte at a time.
// FUNCTION: TITANIUM 0x0054497B
void CPlayerNotesWnd_guess::SaveNotes_guess() {
	FILE* file = fopen("notes.txt", "w");
	if (file != 0 && source_015c != 0) {
		CXStr text = source_015c->GetText_guess();
		((CText_guess*)&text)->Reserve_guess(0);
		for (int i = 0; i < (text.Ptr != 0 ? text.Ptr->length : 0); ++i) {
			char ch = ((CText_guess*)&text)->GetAt_guess(i);
			fwrite(&ch, 1, 1, file);
		}
		fclose(file);
	}
}

// Destructor of the player notes window (vtable 0x65A5E0): saves the notes to notes.txt (0x0054497B)
// when the window has its template (+0x124), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00544DFE
CPlayerNotesWnd_guess::~CPlayerNotesWnd_guess() {
	if (value_0124 != 0)
		SaveNotes_guess();
}

