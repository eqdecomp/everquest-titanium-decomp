// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 225: a hint from compare/tumap.py.
// The generic text-entry dialog (CTextEntryWndView_guess, MQ2 CTextEntryWnd: Activate, Callback,
// UpdateButtons, GetEntryText) and the ctor of the GM ticket comment window (TicketCommentWindow,
// 4000-character box).
#include "titanium/types.h"

struct QueryRecord_guess {
	unsigned char pad_0000_guess[8];
	int value_8_guess;
};

struct QueryResult_guess {
	QueryRecord_guess* data_guess;
	// EXTERNAL: TITANIUM 0x00407D68 ??0QueryResult_guess@@QAE@ABU0@@Z
	QueryResult_guess(const QueryResult_guess& other_guess);
	// EXTERNAL: TITANIUM 0x00571D00 QueryResult_guess::FreeRep
	void FreeRep(QueryRecord_guess* value_guess);
};

struct CString_guess {
	int data_guess;
	// EXTERNAL: TITANIUM 0x00407D68 ??0CString_guess@@QAE@ABU0@@Z
	CString_guess(const CString_guess& other_guess);
	// EXTERNAL: TITANIUM 0x00571F70 ??4CString_guess@@QAEAAU0@ABU0@@Z
	CString_guess& operator=(const CString_guess& other_guess);
	~CString_guess() {
		if (data_guess != 0)
			reinterpret_cast<QueryResult_guess*>(this)->FreeRep(reinterpret_cast<QueryRecord_guess*>(data_guess));
		data_guess = 0;
	}
};

struct QuerySource_guess {
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
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess(); virtual void Slot3F_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
	virtual QueryResult_guess Query_guess();
};

struct CStringQuerySource_guess {
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
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess(); virtual void Slot3F_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
	virtual CString_guess QueryText_guess();
};

struct ResultWindow_guess {
	unsigned char pad_0000_guess[0x5d];
	bool enabled_005d_guess;
};

struct CTextEntryWndView_guess;

struct ResultNotifier_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Notify_guess(CTextEntryWndView_guess* target_guess, int event_guess, int enabled_guess);
};

struct TargetVTable_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess();
	virtual void Refresh_guess();
};

struct EditWnd_guess;

struct CTextEntryWndView_guess {
	unsigned char pad_0000_guess[0x15c];
	int minLength_015c_guess;
	int maxLength_0160_guess;
	CString_guess text_0164_guess;
	ResultNotifier_guess* notifyTarget_0168_guess;
	int entryEditBox_016c_guess;
	EditWnd_guess* promptLabel_0170_guess;
	ResultWindow_guess* okButton_0174_guess;
	int field_178_guess;
	int WndNotification_guess(int sender_guess, unsigned int message_guess, void* data_guess);
	void UpdateButtons_guess();
	void NotifyEntryResult_guess(char enabled_guess);
	CString_guess GetEntryText_guess();
	void Set_guess(CString_guess value_guess);
	void Activate_guess(ResultNotifier_guess* sender_guess, int type_guess, const char* text_guess,
		int minLength_guess, int maxLength_guess, const char* extra_guess);
	// EXTERNAL: TITANIUM 0x005A0480 CTextEntryWndView_guess::Measure_guess
	void Measure_guess();
};

struct EditWnd_guess {
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
	virtual void SetWindowText_guess(const CXStr& text_guess); // 0xFC
	unsigned char pad_004_guess[0x124];
	int maxChars_guess; // 0x128
	unsigned char pad_12c_guess[0x230 - 0x12c];
	int field_230_guess; // 0x230
	// EXTERNAL: TITANIUM 0x004D7EBC EditWnd_guess::SetMaxChars_guess
	void SetMaxChars_guess(int maxChars_guess);
	// EXTERNAL: TITANIUM 0x005BA1A0 EditWnd_guess::SetSel_guess
	void SetSel_guess(int start_guess, int end_guess);
};

struct TargetVTable30_guess {
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
	virtual void Slot30_guess(int first_guess, int second_guess);
};

// Destructor view of CTextEntryWnd, truncated at 0x168 (the full CTextEntryWnd in types.h is 0x17C).
// Vtable 0x0065E0B8 is stored by the ctor 0x00560A6C in tu_224. The base is core_decls'
// CSidlScreenWnd (dtor 0x005A3100), not the polymorphic CSidlScreenWndBase: the dtors here store no vtable.
struct CTextEntryWnd_guess : CSidlScreenWnd {
	/*0x15C*/ char pad_15C_guess[0x8];
	/*0x164*/ CXStr text_guess;
	~CTextEntryWnd_guess();
	CTextEntryWnd_guess* ScalarDeletingDestructor_guess(unsigned int flags_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x005AE150 FUN_005ae150
int __fastcall FUN_005ae150(void* object_guess);

#define pinstCXWndManager_guess EQ_GLOBAL(void*, 0x0099D3EC)

// Closes the dialog: on OK (`enabled_guess`) takes the edit text, then tells the window that opened it
// (message 0x21, data 1 for OK, 0 for cancel) and hides itself. MQ2 CTextEntryWnd::Callback.
// FUNCTION: TITANIUM 0x00560C16
void CTextEntryWndView_guess::NotifyEntryResult_guess(char enabled_guess)
{
	if (enabled_guess) {
		text_0164_guess = reinterpret_cast<CStringQuerySource_guess*>(entryEditBox_016c_guess)->QueryText_guess();
	}
	if (notifyTarget_0168_guess != 0)
		notifyTarget_0168_guess->Notify_guess(this, 0x21, enabled_guess != 0);
	reinterpret_cast<TargetVTable_guess*>(this)->Refresh_guess();
}

// Enables OK only while the text is at least the minimum length (+0x15C). MQ2 CTextEntryWnd::UpdateButtons.
// FUNCTION: TITANIUM 0x00560C9E
void CTextEntryWndView_guess::UpdateButtons_guess()
{
	if (entryEditBox_016c_guess != 0 && okButton_0174_guess != 0) {
		QueryResult_guess result_guess = reinterpret_cast<QuerySource_guess*>(entryEditBox_016c_guess)->Query_guess();
		int value_guess = result_guess.data_guess != 0 ? result_guess.data_guess->value_8_guess : 0;
		okButton_0174_guess->enabled_005d_guess = value_guess >= minLength_015c_guess;
		if (result_guess.data_guess != 0)
			result_guess.FreeRep(result_guess.data_guess);
	}
}

// AboutToHide of the text entry window (vtable slot 50, ctor 0x00560A6C "TextEntryWnd"): when +0x16C has
// the keyboard focus (CXWndManager 0x99D3EC, +0x44), gives the focus to +0x168 (CXWnd::SetFocus); always
// true, so it never cancels anything.
// FUNCTION: TITANIUM 0x00560BF1
char __fastcall HideTextEntryWindow_guess(CTextEntryWndView_guess* self)
{
	if (FUN_005ae150(pinstCXWndManager_guess) == self->entryEditBox_016c_guess)
		((CXWnd*)self->notifyTarget_0168_guess)->SetFocus();
	return 1;
}

// Edit box: 0xE (text changed) re-checks OK; 6 (probably Enter) accepts when OK is enabled.
// OK and Cancel are left clicks (1); 10 (close) cancels.
// FUNCTION: TITANIUM 0x00560CFB
int CTextEntryWndView_guess::WndNotification_guess(int sender_guess, unsigned int message_guess, void* data_guess)
{
	if (message_guess == 0xe) {
		if (sender_guess == entryEditBox_016c_guess) {
			UpdateButtons_guess();
			return 0;
		}
	} else if (message_guess == 6) {
		if (sender_guess == entryEditBox_016c_guess) {
			if (okButton_0174_guess == 0)
				return 0;
			if (okButton_0174_guess->enabled_005d_guess == 0)
				return 0;
			NotifyEntryResult_guess(1);
			return 0;
		}
	} else if (message_guess == 1) {
		if (sender_guess == reinterpret_cast<int>(okButton_0174_guess)) {
			NotifyEntryResult_guess(1);
			return 0;
		}
		if (sender_guess == field_178_guess) {
			NotifyEntryResult_guess(0);
			return 0;
		}
	} else if (message_guess == 10) {
		NotifyEntryResult_guess(0);
	}
	return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(reinterpret_cast<CXWnd*>(sender_guess),
		message_guess, data_guess);
}

// The entered text. MQ2 CTextEntryWnd::GetEntryText.
// FUNCTION: TITANIUM 0x00560D80
CString_guess CTextEntryWndView_guess::GetEntryText_guess()
{
	return text_0164_guess;
}

// Text entry window: copies `value` into its text string (+0x164, 0x00571F70) and releases the
// argument. The spell book's edit-box handler (0x00556472) sets the text this way.
// FUNCTION: TITANIUM 0x00560D9E
void CTextEntryWndView_guess::Set_guess(CString_guess value_guess)
{
	text_0164_guess = value_guess;
}

// Probably the text-entry window's deleting destructor, folded with others under an MFC name.
// FUNCTION: TITANIUM 0x00560DDE
CTextEntryWnd_guess* CTextEntryWnd_guess::ScalarDeletingDestructor_guess(unsigned int flags_guess)
{
	this->~CTextEntryWnd_guess();
	if (flags_guess & 1)
		free(this);
	return this;
}

// Destructor of the text entry window (vtable 0x65E0B8, ctor 0x00560A6C): destroys its text string
// (+0x164), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00560DFA
CTextEntryWnd_guess::~CTextEntryWnd_guess()
{
}

// Opens the dialog for `sender_guess`: prompt text, edit style `type_guess`, starting text, length limits;
// selects all and takes focus. Without an edit box it cancels at once. MQ2 CTextEntryWnd::Activate.
// FUNCTION: TITANIUM 0x00560E32
void CTextEntryWndView_guess::Activate_guess(ResultNotifier_guess* sender_guess, int type_guess, const char* text_guess,
	int minLength_guess, int maxLength_guess, const char* extra_guess)
{
	notifyTarget_0168_guess = sender_guess;
	minLength_015c_guess = minLength_guess;
	maxLength_0160_guess = maxLength_guess;
	reinterpret_cast<CXStr*>(&text_0164_guess)->~CXStr();
	if (promptLabel_0170_guess != 0)
		promptLabel_0170_guess->SetWindowText_guess(text_guess);
	if (entryEditBox_016c_guess != 0) {
		reinterpret_cast<EditWnd_guess*>(entryEditBox_016c_guess)->field_230_guess = type_guess;
		reinterpret_cast<EditWnd_guess*>(entryEditBox_016c_guess)->SetWindowText_guess(extra_guess);
		reinterpret_cast<EditWnd_guess*>(entryEditBox_016c_guess)->SetMaxChars_guess(maxLength_guess);
		reinterpret_cast<EditWnd_guess*>(entryEditBox_016c_guess)->SetSel_guess(0, -1);
		reinterpret_cast<CXWnd*>(entryEditBox_016c_guess)->SetFocus();
		reinterpret_cast<CXStr*>(&text_0164_guess)->~CXStr();
		UpdateButtons_guess();
		Measure_guess();
		reinterpret_cast<TargetVTable30_guess*>(this)->Slot30_guess(1, 1);
	} else {
		NotifyEntryResult_guess(0);
	}
}

struct SidlPiece_00560f5b_guess {
	char pad_000_guess[0x60];
	unsigned int style_060_guess;	// 0x60
};

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct TicketCommentBase_guess {
	char pad_004_guess[0x14];
	// EXTERNAL: TITANIUM 0x005A3850 ??0TicketCommentBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
	TicketCommentBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess,
		int iniVersion_guess, char* blockName_guess);
	// EXTERNAL: TITANIUM 0x005A3100 ??1TicketCommentBase_guess@@UAE@XZ
	virtual ~TicketCommentBase_guess();
	unsigned char flag_018_guess;	// 0x18
	char pad_019_guess[0x4b];
	unsigned int style_064_guess;	// 0x64 (CXWnd::WindowStyle)
	char pad_068_guess[0xbc];
	SidlPiece_00560f5b_guess* sidlPiece_124_guess;	// 0x124 (CSidlScreenWnd::SidlPiece)
	char pad_128_guess[0x34];
	// EXTERNAL: TITANIUM 0x0059DD20 TicketCommentBase_guess::Init_guess
	void Init_guess();
};

// EXTERNAL: TITANIUM 0x0065E238 ??_7TicketCommentWnd_guess@@6B@
struct TicketCommentWnd_guess : TicketCommentBase_guess {
	CXWnd* submitButton_15c_guess;	// 0x15C
	CXWnd* cancelButton_160_guess;	// 0x160
	EditWnd_guess* commentBox_164_guess;	// 0x164
	TicketCommentWnd_guess(CXWnd* parent_guess);
};

// Style 0x800 is added to the SIDL style; the comment box takes up to 4000 characters.
// FUNCTION: TITANIUM 0x00560F5B
TicketCommentWnd_guess::TicketCommentWnd_guess(CXWnd* parent_guess)
	: TicketCommentBase_guess(parent_guess, "TicketCommentWindow", -1, 1, 0)
{
	submitButton_15c_guess = 0;
	cancelButton_160_guess = 0;
	commentBox_164_guess = 0;
	if (sidlPiece_124_guess != 0) {
		style_064_guess |= sidlPiece_124_guess->style_060_guess | 0x800;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		submitButton_15c_guess = ((CSidlScreenWnd*)this)->GetChildItem("TCW_SubmitButton");
		cancelButton_160_guess = ((CSidlScreenWnd*)this)->GetChildItem("TCW_CancelButton");
		commentBox_164_guess = reinterpret_cast<EditWnd_guess*>(
			((CSidlScreenWnd*)this)->GetChildItem("TCW_CommentBox"));
		if (commentBox_164_guess != 0)
			commentBox_164_guess->SetMaxChars_guess(4000);
		Init_guess();
	}
}

