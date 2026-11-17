// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 181: a hint from compare/tumap.py.
// The tail of CLFGuildWnd (tu_180; its tab control at +0x638, current page +0x634, four pages +0x63C-0x648),
// then CLoadskinWnd (screen "LoadskinWnd", vtable 0x657B90; Mac map). C52A939_guess and CLFGuildWnd_guess are
// CLFGuildWnd, CLoadskinWndView_guess is CLoadskinWnd; the C52AA42 string views are CXStr.
#include "titanium/types.h"
#include <windows.h>

struct C52A9F3_handler_guess;

struct C52A939_guess {
	void RefreshAllTabs_guess();
	unsigned char Update_guess();
	// EXTERNAL: TITANIUM 0x00529ECE C52A939_guess::Handle_guess
	void Handle_guess();
	// EXTERNAL: TITANIUM 0x00529C66 C52A939_guess::Finish_guess
	void Finish_guess();
	char pad_00[0x124];
	int active_124_guess;
	char pad_128[0x510];
	C52A9F3_handler_guess* handler_638_guess;
	int value_63c_guess;
	// EXTERNAL: TITANIUM 0x0052947B C52A939_guess::Step1_guess
	void Step1_guess();
	// EXTERNAL: TITANIUM 0x005296FA C52A939_guess::Step2_guess
	void Step2_guess();
	// EXTERNAL: TITANIUM 0x00529CA1 C52A939_guess::Step3_guess
	void Step3_guess();
	// EXTERNAL: TITANIUM 0x00529DC8 C52A939_guess::Step4_guess
	void Step4_guess();
};

struct C52A9F3_handler_guess {
	// EXTERNAL: TITANIUM 0x005BC460 C52A9F3_handler_guess::Apply_guess
	void Apply_guess(int value_guess, int enabled_guess);
};

struct C52AA42_string_guess {
	char* value_guess;
	C52AA42_string_guess() {}
	C52AA42_string_guess(const char* value) { Set_guess(value); }
	// EXTERNAL: TITANIUM 0x00571E00 C52AA42_string_guess::Set_guess
	void Set_guess(const char* value);
	// EXTERNAL: TITANIUM 0x00571D00 C52AA42_string_guess::Release_guess
	void Release_guess(char* value);
	~C52AA42_string_guess() {
		if (value_guess != 0) {
			Release_guess(value_guess);
		}
	}
};

struct C52AA42_init_string_guess {
	char* value_guess;
	C52AA42_init_string_guess() {}
	C52AA42_init_string_guess(const char* value) { Set_guess(value); }
	// EXTERNAL: TITANIUM 0x00571E00 C52AA42_init_string_guess::Set_guess
	void Set_guess(const char* value);
	// EXTERNAL: TITANIUM 0x00571D00 C52AA42_init_string_guess::Release_guess
	void Release_guess(char* value);
	~C52AA42_init_string_guess() {
		if (value_guess != 0) {
			Release_guess(value_guess);
		}
		value_guess = 0;
	}
};

struct C52AA42_base_guess {
	virtual void BaseHook_guess() {}
	// EXTERNAL: TITANIUM 0x005A3100 C52AA42_base_guess::~C52AA42_base_guess
	~C52AA42_base_guess();
	// EXTERNAL: TITANIUM 0x005A3850 C52AA42_base_guess::C52AA42_base_guess
	C52AA42_base_guess(const char* resource_guess, const C52AA42_init_string_guess& name_guess,
		int index_guess, int flag_guess, int mode_guess);
};

struct C52AA42_window_guess {
	char pad_00[0x5d];
	unsigned char enabled_005d_guess;
	char pad_5e[2];
	unsigned long flags_60_guess;
	char pad_64[2];
	unsigned char list_flag_guess;
	// EXTERNAL: TITANIUM 0x005BB140 C52AA42_window_guess::SetCheck
	void SetCheck(bool enabled_guess);
	// EXTERNAL: TITANIUM 0x00597C60 C52AA42_window_guess::SetColors
	void SetColors(unsigned long foreground_guess, unsigned long background_guess,
		unsigned long border_guess);
	// EXTERNAL: TITANIUM 0x005982E0 C52AA42_window_guess::SetColumnJustification
	void SetColumnJustification(int x_guess, int y_guess);
};

// Only the list's vtable slot at +0x130 is called here (slot 76).
struct C52ABD8_list_guess {
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
	virtual void Slot63_guess();
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

// CLFGuildWnd: refills all four tabs (own entry, guild entry, guild-search and player-search defaults).
// FUNCTION: TITANIUM 0x0052A939
void C52A939_guess::RefreshAllTabs_guess() {
	Step1_guess();
	Step2_guess();
	Step3_guess();
	Step4_guess();
}

struct CLFGuildWnd_guess {
	char pad_00[0x634];
	int kind_634_guess;
	int focus_638_guess;
	int kind_63c_guess;
	int kind_640_guess;
	int kind_644_guess;
	int kind_648_guess;
	// EXTERNAL: TITANIUM 0x00529ECE CLFGuildWnd_guess::Handle_guess
	void Handle_guess();
	// EXTERNAL: TITANIUM 0x0052A2BF CLFGuildWnd_guess::Route63c_guess
	int Route63c_guess(int id_guess, int mode_guess, int extra_guess);
	// EXTERNAL: TITANIUM 0x0052A37F CLFGuildWnd_guess::Route640_guess
	int Route640_guess(int id_guess, int mode_guess, int extra_guess);
	// EXTERNAL: TITANIUM 0x0052A46C CLFGuildWnd_guess::Route644_guess
	int Route644_guess(int id_guess, int mode_guess, int extra_guess);
	// EXTERNAL: TITANIUM 0x0052A68C CLFGuildWnd_guess::Route648_guess
	int Route648_guess(int id_guess, int mode_guess, int extra_guess);
	// EXTERNAL: TITANIUM 0x005A2230 CLFGuildWnd_guess::WndNotification
	int WndNotification(int id_guess, int mode_guess, int extra_guess);
	int WndNotification_guess(int id_guess, int mode_guess, int extra_guess);
};

// CLFGuildWnd::WndNotification: a click on the tab control re-reads the shown tab; anything else goes to
// that tab's handler (tu_180), then to CSidlScreenWnd::WndNotification when it returns -1.
// FUNCTION: TITANIUM 0x0052A957
int CLFGuildWnd_guess::WndNotification_guess(int id_guess, int mode_guess, int extra_guess) {
	if (id_guess == focus_638_guess) {
		if (mode_guess == 1) {
			Handle_guess();
			return 1;
		}
	} else if (id_guess != 0) {
		int result = -1;
		if (kind_634_guess == kind_63c_guess) {
			result = Route63c_guess(id_guess, mode_guess, extra_guess);
		} else if (kind_634_guess == kind_640_guess) {
			result = Route640_guess(id_guess, mode_guess, extra_guess);
		} else if (kind_634_guess == kind_644_guess) {
			result = Route644_guess(id_guess, mode_guess, extra_guess);
		} else if (kind_634_guess == kind_648_guess) {
			result = Route648_guess(id_guess, mode_guess, extra_guess);
		}
		if (result >= 0) {
			return result;
		}
	}
	return WndNotification(id_guess, mode_guess, extra_guess);
}

#define g_active_52a9f3_guess EQ_GLOBAL(int, 0x009247B0)

// CLFGuildWnd: with flag 0x9247B0 set and the window built (+0x124), returns 1 and, when the tab control
// exists, refills the tabs and opens the first one (CTabWnd::SetPage). Else returns 0.
// FUNCTION: TITANIUM 0x0052A9F3
// @early-stop: unknown, structural ndiff=6
unsigned char C52A939_guess::Update_guess() {
	unsigned char result_guess = 0;
	if (g_active_52a9f3_guess != 0 && active_124_guess != 0) {
		++result_guess;
		if (handler_638_guess != 0) {
			RefreshAllTabs_guess();
			handler_638_guess->Apply_guess(value_63c_guess, 1);
			Handle_guess();
			// 0x529ECE already ran this button update; it runs twice.
			Finish_guess();
		}
	}
	return result_guess;
}

// EXTERNAL: TITANIUM 0x00657B90 ??_7CLoadskinWndView_guess@@6B@
struct CLoadskinWndView_guess : C52AA42_base_guess {
	CLoadskinWndView_guess(const char* resource_guess);
	virtual ~CLoadskinWndView_guess();
	void* Delete_guess(unsigned char flags);
	// EXTERNAL: TITANIUM 0x005A25B0 CLoadskinWndView_guess::CreateChildrenFromSidl
	void CreateChildrenFromSidl();
	// EXTERNAL: TITANIUM 0x005A1E10 CLoadskinWndView_guess::GetChildItem
	C52AA42_window_guess* GetChildItem(C52AA42_string_guess* name_guess);
	// EXTERNAL: TITANIUM 0x0052ABCD CLoadskinWndView_guess::DestroyExternal_guess
	void DestroyExternal_guess();
	void UpdateSkinList_guess();
	virtual int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
	char pad_04[0x60];
	unsigned long flags_64_guess;
	char pad_68[0xbc];
	C52AA42_window_guess* sidlPiece_0124_guess;
	char pad_128[0x34];
	C52AA42_window_guess* load_button_guess;
	C52AA42_window_guess* ini_button_guess;
	C52AA42_window_guess* skin_list_guess;
};

// CLoadskinWnd::CLoadskinWnd: Load starts disabled, the INI checkbox checked.
// FUNCTION: TITANIUM 0x0052AA42
CLoadskinWndView_guess::CLoadskinWndView_guess(const char* resource_guess)
	: C52AA42_base_guess(resource_guess,
		C52AA42_init_string_guess("LoadskinWnd"), -1, 1, 0) {
	C52AA42_window_guess* parent = sidlPiece_0124_guess;
	skin_list_guess = 0;
	load_button_guess = 0;
	ini_button_guess = 0;
	if (parent != 0) {
		flags_64_guess |= parent->flags_60_guess | 0x800;
		CreateChildrenFromSidl();
		{
			C52AA42_string_guess load_button_name("LoadButton");
			load_button_guess = GetChildItem(&load_button_name);
		}
		{
			C52AA42_string_guess ini_button_name("INIButton");
			ini_button_guess = GetChildItem(&ini_button_name);
		}
		if (load_button_guess != 0) {
			// +0x5D is the window's Enabled byte, not a text flag.
			load_button_guess->enabled_005d_guess = 0;
		}
		if (ini_button_guess != 0) {
			ini_button_guess->SetCheck(1);
		}
		{
			C52AA42_string_guess skin_list_name("SkinList");
			skin_list_guess = GetChildItem(&skin_list_name);
		}
		if (skin_list_guess != 0) {
			skin_list_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
			skin_list_guess->SetColumnJustification(0, 0);
			skin_list_guess->list_flag_guess &= 0xdf;
		}
	}
}

// CLoadskinWnd::UpdateSkinList (Mac): lists every folder under .\UIFiles (attribute 0x10, dot names
// skipped) and disables Load until a skin is picked.
// FUNCTION: TITANIUM 0x0052ABD8
void CLoadskinWndView_guess::UpdateSkinList_guess() {
	if (skin_list_guess != 0) {
		((CListWnd*)skin_list_guess)->ClearAllSel();
		((C52ABD8_list_guess*)skin_list_guess)->Slot76_guess();
		WIN32_FIND_DATAA find_data;
		HANDLE find = FindFirstFileA(".\\UIFiles\\*.*", &find_data);
		if (find != INVALID_HANDLE_VALUE) {
			do {
				if ((find_data.dwFileAttributes & 0x10) != 0 && find_data.cFileName[0] != '.') {
					CXStr name(find_data.cFileName);
					((CListWnd*)skin_list_guess)->AddString(name, 0xffffffff, 0, 0);
				}
			} while (FindNextFileA(find, &find_data) != 0);
		}
		// Called even when FindFirstFileA failed (original; FindClose just fails).
		FindClose(find);
	}
	if (load_button_guess != 0) {
		load_button_guess->enabled_005d_guess = 0;
	}
}

// Destructor of the load skin window (vtable 0x657B90): restores its vtable and runs the CSidlScreenWnd
// destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x0052ABCD
CLoadskinWndView_guess::~CLoadskinWndView_guess() {
}

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);
// EXTERNAL: TITANIUM 0x00470897 do_loadskin_guess
void __cdecl do_loadskin_guess(int unused_guess, const char* text_guess);
#define g_channel_guess EQ_GLOBAL(int, 0x00905CE4)

// CLoadskinWnd::WndNotification: picking a skin enables Load; Load runs the /loadskin handler (0x470897)
// with "<skin> <1|0>", the digit from the INI checkbox (probably: load its ini too).
// FUNCTION: TITANIUM 0x0052ACD6
int CLoadskinWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
	if (message == 1) {
		if ((CXWnd*)skin_list_guess == sender) {
			if (load_button_guess != 0) {
				load_button_guess->enabled_005d_guess = 1;
			}
		} else if (sender == (CXWnd*)load_button_guess) {
			bool flag = false;
			CXStr name;
			if (skin_list_guess != 0) {
				int index = ((CListWnd*)skin_list_guess)->GetCurSel();
				if (index != -1) {
					name = ((CListWnd*)skin_list_guess)->GetItemText(index, 0);
				}
			}
			if (ini_button_guess != 0) {
				flag = ((CButtonWnd*)ini_button_guess)->Checked;
			}
			char buf[512];
			sprintf(buf, "%s %c", (char*)name, (char)((flag != 0) + '0'));
			do_loadskin_guess(g_channel_guess, buf);
			return 1;
		}
	}
	return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Scalar deleting destructor of CLoadskinWnd.
// FUNCTION: TITANIUM 0x0052ADF8
void* CLoadskinWndView_guess::Delete_guess(unsigned char flags) {
	DestroyExternal_guess();
	if ((flags & 1) != 0) {
		free(this);
	}
	return this;
}

