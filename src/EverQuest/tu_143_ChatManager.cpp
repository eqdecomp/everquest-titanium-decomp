// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 143: a hint from compare/tumap.py.
// CChatManager: owns up to 32 chat windows (window 0 is the main chat) and routes each of the 54 chat
// filters (ChannelMap0-53) to one of them; it saves all of it under [ChatManager] in the character INI.
// Selector_guess, FinishOwner_guess and ColorTable_guess are this manager. values_guess[0x20] is the window
// count, [0x21] the active window and [0x22] the locked one. 0x988DF0 (g_ini_guess) is pEverQuest.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/bounded_array.h"
#include <algorithm>
#include <new>

struct Value_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value);
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
    virtual void Slot63_guess(const CXStr& text);
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess(); // 0x118
};

struct Str_guess {
    int data_guess; // 0x00

    Str_guess() { data_guess = 0; }

    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571FC0 Str_guess::Assign_guess
    void Assign_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x00572E00 Str_guess::Append_guess
    void Append_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(int value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct Text_guess {
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
    virtual int Slot57_guess(int* index_guess);
    // EXTERNAL: TITANIUM 0x005A6890 Text_guess::Describe_guess
    Str_guess Describe_guess(Str_guess prefix_guess, int id_guess);
};

struct MenuRect_guess : CXRect {
    MenuRect_guess(int left_guess, int top_guess, int right_guess, int bottom_guess)
    {
        left = left_guess;
        top = top_guess;
        right = right_guess;
        bottom = bottom_guess;
    }
};

struct Control_guess {
    char pad_00_guess[0x11c];
    int count_guess; // 0x11c
    char pad_120_guess[0x1a8 - 0x120];

    // EXTERNAL: TITANIUM 0x005BFAE0 Control_guess::Control_guess
    Control_guess(CXWnd* parent_guess, unsigned int id_guess, const CXRect& rect_guess);
    // EXTERNAL: TITANIUM 0x005BFCF0 Control_guess::AddItem_guess
    int AddItem_guess(const CXStr& text_guess, int id_guess, bool flag_guess, int color_guess);
    // EXTERNAL: TITANIUM 0x005BFF70 Control_guess::CheckItem_guess
    void CheckItem_guess(int index_guess, bool check_guess, bool flag_guess);
    // EXTERNAL: TITANIUM 0x005BFF10 Control_guess::EnableItem_guess
    void EnableItem_guess(int index_guess, bool enable_guess);
    // EXTERNAL: TITANIUM 0x005BFE60 Control_guess::AddSeparator_guess
    void AddSeparator_guess();
    // EXTERNAL: TITANIUM 0x005BFEF0 Control_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x005BFCF0 Control_guess::AddText_guess
    int AddText_guess(Str_guess* text_guess, int id_guess, int flag_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x005BFF70 Control_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x005BFF10 Control_guess::SetActive_guess
    void SetActive_guess(int control_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00598620 Control_guess::SetItemData
    void SetItemData(int control_guess, unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x00597ED0 Control_guess::GetItemData
    int GetItemData(int index_guess);
};

struct EntryTable_guess {
    // EXTERNAL: TITANIUM 0x004C9C1E EntryTable_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x0040C059 EntryTable_guess::GetText_guess
    const char* GetText_guess(int index_guess);
};

struct GlobalStrings_guess {
    // EXTERNAL: TITANIUM 0x00492595 GlobalStrings_guess::GetString_guess
    const char* GetString_guess(int id_guess);
    char pad_00_guess[0x290];
    EntryTable_guess* entries_guess; // 0x290
};

struct FormattedCXStr_guess : CXStr {
    // EXTERNAL: TITANIUM 0x005724C0 FormattedCXStr_guess::Format_guess
    CXStr& Format_guess(int value_guess, int radix_guess, int width_guess);
};

// EXTERNAL: TITANIUM 0x0042E3D9 WrapCXStr_guess
CXStr WrapCXStr_guess(const char* text_guess, const CXStr& prefix_guess);
// EXTERNAL: TITANIUM 0x004D9090 CombineCXStr_guess
CXStr CombineCXStr_guess(const CXStr& left_guess, const CXStr& right_guess);

struct ChatWindow_guess : CXWnd {
    char pad_11c_guess[0x164 - 0x11c];
    struct ScrollBar_guess {
        char pad_00_guess[0x64];
        unsigned int flags_guess; // 0x64
    };
    ScrollBar_guess* scroll_guess; // 0x164
    int default_channel_guess; // 0x168
    int chat_channel_guess; // 0x16c
    char tell_target_guess[0x40]; // 0x170
    int language_guess; // 0x1b0
    char pad_1b4_guess;
    char flag_guess; // 0x1b5
    char pad_1b6_guess[0x1c0 - 0x1b6];
    int field_1c0_guess;
    char pad_1c4_guess[0x260 - 0x1c4];
    int font_style_guess; // 0x260
    int field_264_guess; // 0x264

    // EXTERNAL: TITANIUM 0x004D22D7 ChatWindow_guess::GetName_guess
    CXStr GetName_guess();
};

struct SelectorBitsData_guess {
    int pad_00_guess;
    char* bytes_guess; // 0x04
};

struct SelectorBits_guess {
    int pad_00_guess[2];
    SelectorBitsData_guess* data_guess; // 0x08
};

struct SelectionFlags_guess {
    char pad_00_guess[0x64];
    int value_guess; // 0x64
};

struct SelectedItem_guess {
    char pad_00_guess[0x164];
    SelectionFlags_guess* flags_guess; // 0x164
    int type_guess; // 0x168
    int index_guess; // 0x16c
    char pad_170_guess[0x40];
    int selected_guess; // 0x1b0
};

#define g_selectorBits_guess EQ_GLOBAL(SelectorBits_guess*, 0x00905D00)
#define g_globalStrings_guess EQ_GLOBAL(GlobalStrings_guess*, 0x00988DF0)
// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int NewUIINI();

// EXTERNAL: TITANIUM 0x0060BF20 WriteIniString_guess
void __cdecl WriteIniString_guess(const char* section_guess, const char* key_guess, const char* value_guess);

struct IniFile_guess {
    // EXTERNAL: TITANIUM 0x004AE7DE IniFile_guess::WriteCharIniInt_guess
    void WriteCharIniInt_guess(int value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE848 IniFile_guess::WriteCharIniString_guess
    void WriteCharIniString_guess(const char* value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE64C IniFile_guess::ReadClientIniInt_guess
    int ReadClientIniInt_guess(const char* section_guess, const char* key_guess, int default_guess);
    // EXTERNAL: TITANIUM 0x004AE865 IniFile_guess::ReadString_guess
    char* ReadString_guess(const char* section_guess, const char* key_guess, const char* default_guess,
        char* out_guess, int size_guess, char client_guess);
    // EXTERNAL: TITANIUM 0x004AE8D9 IniFile_guess::ReadInt_guess
    int ReadInt_guess(const char* section_guess, const char* key_guess, int default_guess, char client_guess);
};

#define g_ini_guess EQ_GLOBAL(IniFile_guess*, 0x00988DF0)

struct Receiver_guess {
    // EXTERNAL: TITANIUM 0x004F6A90 Receiver_guess::ShowText_guess
    void ShowText_guess(Str_guess text_guess, int type_guess);
};

struct Message_guess {
    // EXTERNAL: TITANIUM 0x004063F2 Message_guess::CheckChatText_guess
    void CheckChatText_guess();
};

// EXTERNAL: TITANIUM 0x00406AEF CreateMessage_guess
Message_guess* __stdcall CreateMessage_guess(const char* text_guess);
// EXTERNAL: TITANIUM 0x004B1357 Join_guess
Str_guess Join_guess(const Str_guess& left_guess, const char* right_guess);
// EXTERNAL: TITANIUM 0x004D9090 Combine_guess
Str_guess Combine_guess(const Str_guess& left_guess, const Str_guess& right_guess);

struct Count_guess {
    int count_guess; // 0x00

    int Get_guess() { return count_guess; }
};

struct FinishString_guess {
    int data_guess; // 0x00

    // EXTERNAL: TITANIUM 0x00571E00 ??0FinishString_guess@@QAE@PBD@Z
    FinishString_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 FinishString_guess::FreeRep
    void FreeRep(int value_guess);
    ~FinishString_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
    }
};

struct FinishList_guess {
    // EXTERNAL: TITANIUM 0x005BFEF0 FinishList_guess::BeginUpdate_guess
    void BeginUpdate_guess();
    // EXTERNAL: TITANIUM 0x005BFCF0 FinishList_guess::SetItem_guess
    void SetItem_guess(const FinishString_guess& text_guess, int index_guess, int flags_guess, int data_guess);
};

struct FinishState_guess {
    // EXTERNAL: TITANIUM 0x005BFF10 FinishState_guess::UpdateList_guess
    void UpdateList_guess(FinishList_guess* list_guess, int changed_guess);
};

struct FinishInput_guess {
    char pad_00_guess[0x150];
    int index_guess; // 0x150
};

struct FinishStringTable_guess {
    // EXTERNAL: TITANIUM 0x004302D9 FinishStringTable_guess::Get_guess
    const char* Get_guess(int index_guess);
};

struct FinishOwner_guess {
    char pad_00_guess[0x1f4];
    FinishList_guess* primaryList_guess; // 0x1f4
    int pad_1f8_guess;
    FinishList_guess* secondaryList_guess; // 0x1fc
    int pad_200_guess;
    FinishList_guess* tertiaryList_guess; // 0x204
    int pad_208_guess;
    FinishList_guess* primaryView_guess; // 0x20c
    FinishList_guess* secondaryView_guess; // 0x210
    FinishList_guess* tertiaryView_guess; // 0x214

    void Finish_guess(FinishInput_guess* input_guess);
};

struct FinishState_guess;

struct Selector_guess {
    int values_guess[0x20]; // 0x00
    Count_guess count_guess; // 0x80
    int index_guess; // 0x84
    int selected_guess; // 0x88
    int filterWindows_guess[0x36]; // 0x8c
    Control_guess* field_164_guess; // 0x164
    int field_168_guess; // 0x168
    Control_guess* field_16c_guess; // 0x16c
    int field_170_guess; // 0x170
    Control_guess* field_174_guess; // 0x174
    int field_178_guess; // 0x178
    int field_17c_guess; // 0x17c
    int field_180_guess; // 0x180
    int field_184_guess; // 0x184
    Control_guess* field_188_guess; // 0x188
    int field_18c_guess; // 0x18c
    Control_guess* field_190_guess; // 0x190
    int field_194_guess; // 0x194
    Control_guess* field_198_guess; // 0x198
    int field_19c_guess; // 0x19c
    Control_guess* field_1a0_guess; // 0x1a0
    int field_1a4_guess; // 0x1a4
    int field_1a8_guess; // 0x1a8
    Control_guess* field_1ac_guess; // 0x1ac
    int field_1b0_guess; // 0x1b0
    int pairs_guess[0x16]; // 0x1b4
    int field_20c_guess; // 0x20c
    int field_210_guess; // 0x210
    int field_214_guess; // 0x214
    int hit_modes_guess[8]; // 0x218
    int defaultChannel_0238_guess; // 0x238
    int defaultLanguage_023c_guess; // 0x23c

    Selector_guess();
    void AddBlankChat_guess();
    void SaveSettings_guess();
    void CallValuesWithOne_guess();
    void CallAll_guess();
    Value_guess* FindTellWindow_guess(int input_guess);
    int HasValue_guess(int value);
    Value_guess* AddChat_guess(const char* name);
    int GetActiveChatWindow_guess();
    void SetChannelMap_guess(int index, int value);
    void Copy_guess(int index);
    int GetChannelMap_guess(int index);
    void ReplaceSlot_guess(int value);
    void SelectValue_guess(int value);
    void SelectIndex_guess(int value);
    char Contains_guess(int value);
    void Remove_guess(int value);
    void Clear_guess();
    void ShowText_guess(Str_guess text_guess, int type_guess);
    Str_guess GetAllVisibleText_guess(Str_guess title_guess);
    void ShowFor_guess(Str_guess text_guess, int type_guess, const char* who_guess, const char* name_guess);
    void Update_guess(SelectedItem_guess* selected_guess);
    int InitContextMenu(Value_guess* value_guess);
    void AddChatWindow_guess(const char* name_guess, char* ini_guess, int tab_guess, int slot_guess, int depth_guess, const char* title_guess, int setup_guess, char focus_guess);
    // EXTERNAL: TITANIUM 0x004F2CA2 Selector_guess::Finish_guess
    void Finish_guess(SelectedItem_guess* selected_guess);
};

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x005AD7F0 Manager_guess::Apply_guess
    void Apply_guess(int value, int flag);
    // EXTERNAL: TITANIUM 0x004DAFEA Manager_guess::GetMenu_guess
    FinishState_guess* GetMenu_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005AD5A0 Manager_guess::AddMenu_guess
    int AddMenu_guess(Control_guess* menu_guess);

    char pad_00_guess[0x1154];
    int field_1154_guess; // 0x1154
};

#define pinstCContextMenuManager_guess EQ_GLOBAL(Manager_guess*, 0x0099D414)

struct ValueData_guess {
    char pad_guess[0x150];
    int value_guess; // 0x150
};

struct Chat_guess : Value_guess {
    // EXTERNAL: TITANIUM 0x004F68B3 ??0Chat_guess@@QAE@H@Z
    Chat_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x004648A1 Chat_guess::SetName_guess
    void SetName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x0059FD80 Chat_guess::Pause_guess
    void Pause_guess(int ms_guess);
    // EXTERNAL: TITANIUM 0x004F7FC6 Chat_guess::SetChatFont_guess
    void SetChatFont_guess(int value_guess);

    char pad_04_guess[0x15c - 4]; // 0x04
    Selector_guess* owner_guess; // 0x15c
    int pad_160_guess; // 0x160
    ChatWindow_guess* window_guess; // 0x164
    int field_168_guess; // 0x168
    int field_16c_guess; // 0x16c
    int pad_170_guess[(0x1b0 - 0x170) / 4]; // 0x170
    int field_1b0_guess; // 0x1b0
    unsigned char field_1b4_guess; // 0x1b4
    unsigned char field_1b5_guess; // 0x1b5
    char pad_1b6_guess[0x268 - 0x1b6]; // 0x1b6
};

// Destroys every chat window and its menu and resets the filter routing.
// FUNCTION: TITANIUM 0x004F2141
void Selector_guess::Clear_guess()
{
    for (int i = 0; i < count_guess.Get_guess(); ++i) {
        if (values_guess[i] != 0) {
            int value = ((ValueData_guess*)(void*)values_guess[i])->value_guess;
            if (value != -1) {
                pinstCContextMenuManager_guess->Apply_guess(value, 1);
            }
            if (values_guess[i] != 0) {
                ((Value_guess*)(void*)values_guess[i])->Slot01_guess(1);
            }
            values_guess[i] = 0;
        }
    }
    count_guess.count_guess = 0;
    for (int i = 0; i < 0x36; ++i) {
        filterWindows_guess[i] = 0;
    }
    index_guess = 0;
}

// Chat manager: shows every chat window it holds (Show(1, 1), slot 48; up to 32, count at +0x80). Part
// of bringing the game windows back after a UI rebuild (0x0043BA81).
// FUNCTION: TITANIUM 0x004F21A7
void Selector_guess::CallValuesWithOne_guess()
{
    for (int i = 0; i < values_guess[0x20]; ++i) {
        if (values_guess[i] != 0) {
            ((Value_guess*)(void*)values_guess[i])->Slot48_guess(1, 1);
        }
    }
}

// Writes the windows, the filter routing and the hit modes to [ChatManager].
// FUNCTION: TITANIUM 0x004F21D6
// @early-stop: budget, structural ndiff=77
void Selector_guess::SaveSettings_guess()
{
    char value_guess[0x80];
    char window_guess[0x100];
    char key_guess[0x20];
    int i;

    if (NewUIINI() != 0) {
        int windows = values_guess[0x20];
        for (i = 0; i < values_guess[0x20]; ++i) {
            if (values_guess[i] != 0 && ((ChatWindow_guess*)(void*)values_guess[i])->flag_guess != 0) {
                --windows;
            }
        }
        sprintf(value_guess, "%d", windows - 1);
        // Neither the main window nor tell windows (flag set) are counted.
        WriteIniString_guess("ChatManager", "NumWindows", value_guess);
        sprintf(value_guess, "%d", selected_guess);
        WriteIniString_guess("ChatManager", "LockedActiveWindow", value_guess);

        for (i = 0; i < values_guess[0x20]; ++i) {
            sprintf(window_guess, "ChatWindow%d", i);
            ChatWindow_guess** slot = (ChatWindow_guess**)(void*)&values_guess[i];
            if (*slot == 0 && i != 0) {
                sprintf(key_guess, "%s_Language", window_guess);
                // "@42" marks a closed window, so later windows keep their numbers.
                g_ini_guess->WriteCharIniString_guess(EQ_ARRAY(char, 0x006529B0), "ChatManager", key_guess);
            } else if (*slot == 0 || (*slot)->flag_guess == 0) {
                sprintf(key_guess, "%s_Language", window_guess);
                g_ini_guess->WriteCharIniInt_guess((*slot)->language_guess, "ChatManager", key_guess);
                sprintf(key_guess, "%s_DefaultChannel", window_guess);
                g_ini_guess->WriteCharIniInt_guess((*slot)->default_channel_guess, "ChatManager", key_guess);
                sprintf(key_guess, "%s_ChatChannel", window_guess);
                g_ini_guess->WriteCharIniInt_guess((*slot)->chat_channel_guess, "ChatManager", key_guess);
                sprintf(key_guess, "%s_TellTarget", window_guess);
                g_ini_guess->WriteCharIniString_guess((*slot)->tell_target_guess, "ChatManager", key_guess);
                sprintf(key_guess, "%s_Scrollbar", window_guess);
                g_ini_guess->WriteCharIniInt_guess((*slot)->scroll_guess->flags_guess & 1, "ChatManager", key_guess);
                sprintf(key_guess, "%s_FontStyle", window_guess);
                g_ini_guess->WriteCharIniInt_guess((*slot)->font_style_guess, "ChatManager", key_guess);
                sprintf(key_guess, "%s_Name", window_guess);
                CXStr name_guess = (*slot)->GetName_guess();
                g_ini_guess->WriteCharIniString_guess(name_guess, "ChatManager", key_guess);
            }
        }

        for (i = 0; i < 0x36; ++i) {
            sprintf(key_guess, "ChannelMap%d", i);
            for (int j = 0; j < values_guess[0x20]; ++j) {
                if (values_guess[j] == filterWindows_guess[i]) {
                    if (j > -1) {
                        g_ini_guess->WriteCharIniInt_guess(j, "ChatManager", key_guess);
                    }
                    break;
                }
            }
        }

        for (i = 0; i < 8; ++i) {
            sprintf(key_guess, "HitMode%d", i);
            g_ini_guess->WriteCharIniInt_guess(hit_modes_guess[i], "ChatManager", key_guess);
        }
    }

    for (i = 0; i < values_guess[0x20]; ++i) {
        if (values_guess[i] != 0) {
            ((Value_guess*)(void*)values_guess[i])->Slot48_guess(0, 1);
        }
    }
}

// Returns the tell window for `input_guess` (a name; first letter upper case, the rest lower), or 0.
// FUNCTION: TITANIUM 0x004F25BC
// @early-stop: budget, structural ndiff=49
Value_guess* Selector_guess::FindTellWindow_guess(int input_guess)
{
    char name_guess[0x40];
    if (input_guess != 0) {
        strcpy(name_guess, (const char*)input_guess);
        name_guess[0] = (char)toupper(name_guess[0]);
        size_t index_guess = 1;
        if (strlen(name_guess) > index_guess) {
            do {
                name_guess[index_guess] = (char)tolower(name_guess[index_guess]);
                ++index_guess;
            } while (index_guess < strlen(name_guess));
        }
    }

    for (int index_guess = 0; index_guess < count_guess.Get_guess(); ++index_guess) {
        ChatWindow_guess* value_guess = (ChatWindow_guess*)(void*)values_guess[index_guess];
        char matches_guess;
        if (value_guess != 0 && value_guess->flag_guess != 0) {
            CXStr text_guess = value_guess->GetName_guess();
            matches_guess = 1;
            if (strcmp(text_guess, name_guess) != 0) {
                matches_guess = 0;
            }
        } else {
            matches_guess = 0;
        }
        if (matches_guess != 0) {
            return (Value_guess*)(void*)values_guess[index_guess];
        }
    }
    return 0;
}

// Chat manager: every chat window it holds reloads its INI settings (slot 70, LoadIniInfo). Called in
// the UI rebuild (0x0043BA81) before the windows are shown again.
// FUNCTION: TITANIUM 0x004F2591
void Selector_guess::CallAll_guess()
{
    for (int i = 0; i < values_guess[0x20]; ++i) {
        if (values_guess[i] != 0) {
            ((Value_guess*)(void*)values_guess[i])->Slot70_guess();
        }
    }
}

// True when a tell window for the name exists or there is room (32 windows) for one.
// FUNCTION: TITANIUM 0x004F26C6
int Selector_guess::HasValue_guess(int value)
{
    if (count_guess.Get_guess() >= 0x20 && FindTellWindow_guess(value) == 0) {
        return 0;
    }
    return 1;
}

// Opens a tell window for `name`: default and chat channel 7 (tell, probably) and the tell flag (+0x1B5).
// FUNCTION: TITANIUM 0x004F26E2
Value_guess* Selector_guess::AddChat_guess(const char* name)
{
    char buf[64];
    if (name != 0) {
        strcpy(buf, name);
        buf[0] = toupper(buf[0]);
        for (int i = 1; i < strlen(buf); ++i) {
            buf[i] = tolower(buf[i]);
        }
    }
    int slot = -1;
    for (int i = 0; i < count_guess.Get_guess(); ++i) {
        if (values_guess[i] == 0) {
            slot = i;
            break;
        }
    }
    if (slot == -1 && count_guess.Get_guess() < 0x20) {
        slot = count_guess.count_guess++;
    }
    if (slot != -1) {
        Chat_guess* chat = new Chat_guess(0);
        values_guess[slot] = (int)chat;
        chat->owner_guess = this;
        ((Value_guess*)(void*)values_guess[slot])->Slot63_guess(buf);
        ((Chat_guess*)(void*)values_guess[slot])->field_1b0_guess = defaultLanguage_023c_guess;
        ((Chat_guess*)(void*)values_guess[slot])->field_168_guess = 7;
        ((Chat_guess*)(void*)values_guess[slot])->field_16c_guess = 7;
        ((Chat_guess*)(void*)values_guess[slot])->SetName_guess(name);
        ((Chat_guess*)(void*)values_guess[slot])->field_1b5_guess = 1;
        ((Value_guess*)(void*)values_guess[slot])->Slot48_guess(1, 1);
        return (Value_guess*)(void*)values_guess[slot];
    }
    return 0;
}

// Returns the window typed text goes to: the locked one when set, else the active one.
// FUNCTION: TITANIUM 0x004F288C
int Selector_guess::GetActiveChatWindow_guess()
{
    int index = values_guess[0x22];
    if (index == -1) {
        index = values_guess[0x21];
    }
    return values_guess[index];
}

// Routes filter `index` (0-53) to window `value`.
// FUNCTION: TITANIUM 0x004F28A1
void Selector_guess::SetChannelMap_guess(int filterIndex, int window_guess)
{
    if (filterIndex >= 0 && filterIndex < 0x36) {
        filterWindows_guess[filterIndex] = window_guess;
    }
}

// Routes filter `index` back to the main window.
// FUNCTION: TITANIUM 0x004F28BC
void Selector_guess::Copy_guess(int index)
{
    if (index >= 0 && index < 0x36) {
        filterWindows_guess[index] = values_guess[0];
    }
}

// Maps a chat colour type (0x100 and up) to its filter index 0-53. 0x133-0x144 are second types for the
// filters of 0x100-0x12C.
// FUNCTION: TITANIUM 0x004F28D5
int __stdcall GetSlotForType_guess(int type)
{
    switch (type) {
    case 0x100:
    case 0x133:
        return 0;
    case 0x101:
    case 0x134:
        return 1;
    case 0x102:
    case 0x135:
        return 2;
    case 0x147:
        return 3;
    case 0x103:
    case 0x136:
        return 4;
    case 0x104:
    case 0x137:
        return 5;
    case 0x105:
    case 0x138:
        return 6;
    case 0x106:
    case 0x139:
        return 7;
    case 0x107:
    case 0x13a:
        return 8;
    case 0x123:
    case 0x13b:
        return 0xc;
    case 0x124:
    case 0x13c:
        return 0xd;
    case 0x125:
    case 0x13d:
        return 0xe;
    case 0x126:
    case 0x13e:
        return 0xf;
    case 0x127:
    case 0x13f:
        return 0x10;
    case 0x128:
    case 0x140:
        return 0x11;
    case 0x129:
    case 0x141:
        return 0x12;
    case 0x12a:
    case 0x142:
        return 0x13;
    case 0x12b:
    case 0x143:
        return 0x14;
    case 0x12c:
    case 0x144:
        return 0x15;
    case 0x10e:
        return 0xb;
    case 0x108:
        return 0xa;
    case 0x120:
        return 0x24;
    case 0x121:
        return 0x25;
    case 0x12e:
        return 0x26;
    case 0x11c:
        return 0x27;
    case 0x11b:
        return 0x28;
    case 0x109:
        return 9;
    case 0x10b:
        return 0x17;
    case 0x10a:
        return 0x18;
    case 0x10c:
        return 0x19;
    case 0x117:
        return 0x1a;
    case 0x118:
        return 0x1b;
    case 0x115:
        return 0x1c;
    case 0x116:
        return 0x1d;
    case 0x12d:
        return 0x1e;
    case 0x10f:
        return 0x1f;
    case 0x12f:
        return 0x20;
    case 0x130:
        return 0x21;
    case 0x131:
        return 0x22;
    case 0x132:
        return 0x23;
    case 0x11f:
        return 0x2a;
    case 0x148:
        return 0x2b;
    case 0x149:
        return 0x2e;
    case 0x14b:
        return 0x2c;
    case 0x14c:
        return 0x2d;
    case 0x14d:
        return 0x29;
    case 0x14e:
        return 0x2f;
    case 0x14f:
        return 0x31;
    case 0x119:
        return 0x32;
    case 0x150:
        return 0x33;
    case 0x151:
        return 0x34;
    case 0x152:
        return 0x35;
    // Unlisted types go to filter 22, probably the catch-all.
    default:
        return 0x16;
    }
}

// Chat manager: the chat window that filter `index` (0..0x35) is routed to (+0x8C table), or 0 out of
// range. The chat window menu uses it to tick the filters routed to a window.
// FUNCTION: TITANIUM 0x004F2B2F
int Selector_guess::GetChannelMap_guess(int index)
{
    if (index < 0 || index >= 0x36) {
        return 0;
    }
    return filterWindows_guess[index];
}

// A window is closing: its filters go back to the main window.
// FUNCTION: TITANIUM 0x004F2B4A
void Selector_guess::ReplaceSlot_guess(int value)
{
    if (value != values_guess[0]) {
        for (int i = 0; i < 0x36; ++i) {
            if (filterWindows_guess[i] == value) {
                filterWindows_guess[i] = values_guess[0];
            }
        }
    }
}

// Makes window `value` the active one.
// FUNCTION: TITANIUM 0x004F2B70
void Selector_guess::SelectValue_guess(int value)
{
    for (int i = 0; i < values_guess[0x20]; ++i) {
        if (values_guess[i] == value) {
            values_guess[0x21] = i;
            return;
        }
    }
}

// Locks window `value` as the one typed text goes to.
// FUNCTION: TITANIUM 0x004F2B97
void Selector_guess::SelectIndex_guess(int value)
{
    for (int i = 0; i < count_guess.Get_guess(); ++i) {
        if (values_guess[i] == value) {
            selected_guess = i;
            return;
        }
    }
}

// Appends every window's text to `title_guess`, separated by a line of '=' (0x6529F0).
// FUNCTION: TITANIUM 0x004F2E69
// @early-stop: budget, diff ndiff=9
Str_guess Selector_guess::GetAllVisibleText_guess(Str_guess title_guess)
{
    int i = 0;
    Str_guess prefix_guess;
    int index_guess[4];
    for (; i < count_guess.Get_guess(); ++i) {
        if (values_guess[i] != 0) {
            title_guess.Append_guess(
                ((Text_guess*)((Chat_guess*)(void*)values_guess[i])->window_guess)->Describe_guess(
                    prefix_guess,
                    ((Text_guess*)((Chat_guess*)(void*)values_guess[i])->window_guess)->Slot57_guess(index_guess))
                    .GetText_guess());
            title_guess.Append_guess(EQ_ARRAY(char, 0x006529F0));
        }
    }
    return title_guess;
}

struct ColorTable_guess {
    unsigned int GetRGBAFromIndex(int value);
};

// EXTERNAL: TITANIUM 0x00438BA7 GetUserDefinedColor
unsigned int __cdecl GetUserDefinedColor(int value);

// Text colour for chat colour `value`: the fixed colours below 0x100, else the user's colour for type
// `value` (0x438BA7, light grey when unset).
// FUNCTION: TITANIUM 0x004F2BBE
// @early-stop: budget, structural ndiff=39
unsigned int ColorTable_guess::GetRGBAFromIndex(int value)
{
    if (value > 0xff) {
        value = GetUserDefinedColor(value - 0x100);
        if (value == 0) {
            value = 0x00f0f0f0;
        }
        return ((value >> 16) & 0xff) |
               // The user colour is 0x00BBGGRR; this makes it opaque 0xAARRGGBB.
               ((value | 0xffffff00) << 16) |
               (value & 0xff00);
    }

    switch (value) {
    case 0:
        return 0xfff0f0f0;
    case 2:
        return 0xff008000;
    case 4:
        return 0xff0040ff;
    case 5:
        return 0xfff000f0;
    case 6:
        return 0xff808080;
    case 7:
        return 0xffe0e0e0;
    case 10:
        return 0xfff0f0f0;
    case 12:
        return 0xffa0a0a0;
    case 13:
        return 0xfff00000;
    case 14:
        return 0xff00f000;
    case 15:
        return 0xfff0f000;
    case 16:
        return 0xff0000f0;
    case 18:
        return 0xff00f0f0;
    case 20:
        return 0xff000000;
    default:
        return 0xff606060;
    }
}

// Refills the three list submenus (+0x20C, +0x210, +0x214) with the names at 0x925920 (50, ids 500+),
// 0x95A1B4 (100, ids 0x28A+) and the 72-entry table at 0x91D708 (ids 0x226+). What the lists are is not
// known yet.
// FUNCTION: TITANIUM 0x004F2CA2
// @early-stop: budget, structural ndiff=71
void FinishOwner_guess::Finish_guess(FinishInput_guess* input_guess)
{
    FinishState_guess* state_guess = pinstCContextMenuManager_guess->GetMenu_guess(input_guess->index_guess);

    if (primaryList_guess != 0) {
        primaryList_guess->BeginUpdate_guess();
        int changed_guess = 0;
        int itemIndex_guess = 0;
        char* text_guess = EQ_ARRAY(char, 0x00925920);
        do {
            if (*text_guess == 0) {
                break;
            }
            {
                FinishString_guess value_guess(text_guess);
                primaryList_guess->SetItem_guess(value_guess, itemIndex_guess + 0x1f4, 0, -1);
            }
            ++changed_guess;
            ++itemIndex_guess;
            text_guess += 0x40;
        } while (text_guess < EQ_ARRAY(char, 0x009265a0));
        state_guess->UpdateList_guess(primaryView_guess, changed_guess != 0);
    }

    if (secondaryList_guess != 0) {
        secondaryList_guess->BeginUpdate_guess();
        int changed_guess = 0;
        int itemIndex_guess = 0;
        char* text_guess = EQ_ARRAY(char, 0x0095a1b4);
        do {
            if (*text_guess != 0) {
                {
                    FinishString_guess value_guess(text_guess);
                    secondaryList_guess->SetItem_guess(value_guess, itemIndex_guess + 0x28a, 0, -1);
                }
                ++changed_guess;
            }
            text_guess += 0x40;
            ++itemIndex_guess;
        } while (text_guess < EQ_ARRAY(char, 0x0095bab4));
        state_guess->UpdateList_guess(secondaryView_guess, changed_guess != 0);
    }

    if (tertiaryList_guess != 0) {
        tertiaryList_guess->BeginUpdate_guess();
        int changed_guess = 0;
        for (int index_guess = 0; index_guess < 0x48; ++index_guess) {
            const char* text_guess =
                ((FinishStringTable_guess*)(void*)EQ_ARRAY(char, 0x0091d708))->Get_guess(index_guess);
            if (text_guess != 0) {
                {
                    FinishString_guess value_guess(text_guess);
                    tertiaryList_guess->SetItem_guess(value_guess, index_guess + 0x226, 0, -1);
                }
                ++changed_guess;
            }
        }
        state_guess->UpdateList_guess(tertiaryView_guess, changed_guess != 0);
    }
}

// Chat manager: whether window `value` is one of its chat windows. The explore-mode window check
// (0x004FFEC9) uses it to recognise chat windows.
// FUNCTION: TITANIUM 0x004F2F65
char Selector_guess::Contains_guess(int value)
{
    for (int i = 0; i < values_guess[0x20]; ++i) {
        if (value == values_guess[i]) {
            return 1;
        }
    }
    return 0;
}

// Shows a chat line in the window its filter is routed to, then passes it to the tu_005 singleton
// (0x406AEF), probably the audio triggers.
// FUNCTION: TITANIUM 0x004F2F8A
void Selector_guess::ShowText_guess(Str_guess text_guess, int type_guess)
{
    int index = GetSlotForType_guess(type_guess);
    if (filterWindows_guess[index] != 0) {
        ((Receiver_guess*)(void*)filterWindows_guess[index])->ShowText_guess(text_guess, type_guess);
    }
    CreateMessage_guess(text_guess.GetText_guess())->CheckChatText_guess();
}

// Forgets window `value` (never the main window, index 0) and unlocks it if it was locked.
// FUNCTION: TITANIUM 0x004F2859
void Selector_guess::Remove_guess(int value)
{
    int index = 0;
    ++index;
    while (index < values_guess[0x20]) {
        if (values_guess[index] == value) {
            if (values_guess[0x22] == index) {
                values_guess[0x22] = -1;
            }
            values_guess[index] = 0;
            return;
        }
        ++index;
    }
}

struct Node_guess {
    int key_guess;
    int vbaseOffset_0004_guess;
    int pad_guess;
    Node_guess* next_guess;
};

// Shows a tell as "<who>:  <text>" in the tell window for `name_guess`, opening one if needed.
// FUNCTION: TITANIUM 0x004F2FFF
void Selector_guess::ShowFor_guess(Str_guess text_guess, int type_guess, const char* who_guess, const char* name_guess)
{
    Str_guess who_str_guess(who_guess);
    Str_guess msg_guess = Combine_guess(Join_guess(who_str_guess, EQ_ARRAY(char, 0x00652A18)), text_guess);
    Chat_guess* chat_guess = (Chat_guess*)FindTellWindow_guess((int)name_guess);
    if (chat_guess == 0) {
        chat_guess = (Chat_guess*)AddChat_guess(name_guess);
    }
    if (chat_guess != 0) {
        ((Receiver_guess*)chat_guess)->ShowText_guess(msg_guess, type_guess);
        if (chat_guess->field_1b5_guess != 0) {
            // pCharData+8 holds the node pointer (the profile's int at +4)
            Node_guess* node_guess = (Node_guess*)pCharData->key;
            const char* my_name_guess = (const char*)((int)pCharData + 0x44 + node_guess->vbaseOffset_0004_guess);
            if (strcmp(who_guess, my_name_guess) != 0) {
                // Flashes the window for 5 seconds (probably) unless you sent the line yourself.
                chat_guess->Pause_guess(5000);
            }
        }
    }
}

struct LanguageHead_guess {
    int pad_00_guess[2];
};

// the virtual base of the object behind 0x00905D00
struct LanguageBase_guess {
    int pad_00_guess[3];
    BoundedArray_guess<unsigned char, 0x20> languages_guess; // 0x0c

    unsigned char& Language_guess(int index_guess) { return languages_guess[index_guess]; }
};

struct LanguageOwner_guess : LanguageHead_guess, virtual LanguageBase_guess {
};

#define g_languageOwner_guess EQ_GLOBAL(LanguageOwner_guess*, 0x00905D00)

// Builds the right-click menu of chat window `value_guess` and returns its menu index. The shared
// submenus are made once: filters (item id 100 + filter index; Update_guess checks GetSlot(id - 100)),
// chat-server channels (0x70 + n routes, 0xCF + n talks), default channel (200+), languages (300 + n) and
// hit modes (400 + 10 * kind + mode 0-2).
// FUNCTION: TITANIUM 0x004F3120
// @early-stop: budget, structural ndiff=79
int Selector_guess::InitContextMenu(Value_guess* value_guess)
{
    int entryCount_guess = 0;
    if (g_globalStrings_guess->entries_guess != 0) {
        entryCount_guess = g_globalStrings_guess->entries_guess->GetCount_guess();
    }

    // Shared submenus are built once and reused by every chat window. First the joined chat-server channels,
    // twice: items 0x70 + n route a filter there, 0xCF + n talk in it.
    if (field_198_guess == 0 || field_1ac_guess == 0) {
        field_198_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        field_1ac_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        if (entryCount_guess > 0) {
            for (int i = 0; i < entryCount_guess; ++i) {
                CXStr name_guess(g_globalStrings_guess->entries_guess->GetText_guess(i));
                field_198_guess->AddItem_guess(name_guess, i + 0x70, 0, -1);
                field_1ac_guess->AddItem_guess(name_guess, i + 0xcf, 0, -1);
            }
        }
        field_19c_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_198_guess);
        field_1b0_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_1ac_guess);
    }

    // The chat-filter menu: items 100 and up per message type (Say, Tell..., strings 6630 on), with Chat
    // Channel, Melee and Spells opening submenus (the melee one: Your Hits, Your Misses..., strings 0x3AA6
    // on).
    if (field_174_guess == 0) {
        field_188_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aa6, 0), 0x6d, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aa7, 0), 0x7b, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aa8, 0), 0x7c, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aa9, 0), 0x7d, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aaa, 0), 0x7e, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aab, 0), 0x7f, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0xd10, 0), 0x8f, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x16ec, 0), 0x90, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x16ed, 0), 0x91, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aac, 0), 0x82, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aad, 0), 0x83, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aae, 0), 0x84, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3aaf, 0), 0x85, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3ab0, 0), 0x86, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3ab1, 0), 0x87, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3ab2, 0), 0x80, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3ab3, 0), 0x81, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0xd30, 0), 0x92, 0, -1);
        field_188_guess->AddItem_guess(pStringTable->getString(0x3395, 0), 0x9b, 0, -1);
        field_18c_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_188_guess);

        field_190_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab4, 0), 0x6e, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab5, 0), 0x88, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab6, 0), 0x89, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab7, 0), 0x8a, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab8, 0), 0x8b, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3ab9, 0), 0x8c, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x16eb, 0), 0x8d, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x17f4, 0), 0x97, 0, -1);
        field_190_guess->AddItem_guess(pStringTable->getString(0x3395, 0), 0x9c, 0, -1);
        field_194_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_190_guess);

        field_174_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        field_174_guess->AddItem_guess(pStringTable->getString(0x19e6, 0), 100, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19e7, 0), 0x65, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19e8, 0), 0x66, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x13f9, 0), 0x67, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19e9, 0), 0x68, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19ea, 0), 0x69, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19eb, 0), 0x6a, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19ec, 0), 0x6b, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19ed, 0), 0x6c, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x16ee, 0), 0x95, 0, -1);
        if (entryCount_guess > 0) {
            field_17c_guess = field_174_guess->AddItem_guess(pStringTable->getString(0x19ee, 0),
                field_19c_guess - 0x80000000, 0, -1);
            field_174_guess->EnableItem_guess(field_17c_guess, true);
        } else {
            field_17c_guess = field_174_guess->AddItem_guess(pStringTable->getString(0x19ee, 0), 0, 0, -1);
            field_174_guess->EnableItem_guess(field_17c_guess, false);
        }
        field_180_guess = field_174_guess->AddItem_guess(pStringTable->getString(0x19ef, 0),
            field_18c_guess - 0x80000000, 0, -1);
        field_184_guess = field_174_guess->AddItem_guess(pStringTable->getString(0x19f0, 0),
            field_194_guess - 0x80000000, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19f1, 0), 0x6f, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0xd0f, 0), 0x8e, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x19f2, 0), 0x7a, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x16ef, 0), 0x93, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x367e, 0), 0x96, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x17f5, 0), 0x98, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x1808, 0), 0x99, 0, -1);
        field_174_guess->AddItem_guess(pStringTable->getString(0x3395, 0), 0x9a, 0, -1);
        field_178_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_174_guess);
    }

    // pairs_guess holds (menu, manager index) pairs from 0x1b4
    // Seven display-style submenus (Normal / Abbreviated / Number Only or Miss Only), one per melee message
    // group, under one parent (pairs_guess[14]). An item id of manager index minus
    // 0x80000000 links a submenu rather than an action.
    if (pairs_guess[14] == 0) {
        pairs_guess[0] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[0])->AddItem_guess(pStringTable->getString(0x3aba, 0), 400, 0, -1);
        ((Control_guess*)pairs_guess[0])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x191, 0, -1);
        ((Control_guess*)pairs_guess[0])->AddItem_guess(pStringTable->getString(0x3abc, 0), 0x192, 0, -1);
        pairs_guess[1] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[0]);

        pairs_guess[2] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[2])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x19a, 0, -1);
        ((Control_guess*)pairs_guess[2])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x19b, 0, -1);
        ((Control_guess*)pairs_guess[2])->AddItem_guess(pStringTable->getString(0x3abd, 0), 0x19c, 0, -1);
        pairs_guess[3] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[2]);

        pairs_guess[4] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[4])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x1a4, 0, -1);
        ((Control_guess*)pairs_guess[4])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x1a5, 0, -1);
        ((Control_guess*)pairs_guess[4])->AddItem_guess(pStringTable->getString(0x3abc, 0), 0x1a6, 0, -1);
        pairs_guess[5] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[4]);

        pairs_guess[6] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[6])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x1ae, 0, -1);
        ((Control_guess*)pairs_guess[6])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x1af, 0, -1);
        ((Control_guess*)pairs_guess[6])->AddItem_guess(pStringTable->getString(0x3abd, 0), 0x1b0, 0, -1);
        pairs_guess[7] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[6]);

        pairs_guess[8] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[8])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x1b8, 0, -1);
        ((Control_guess*)pairs_guess[8])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x1b9, 0, -1);
        ((Control_guess*)pairs_guess[8])->AddItem_guess(pStringTable->getString(0x3abc, 0), 0x1ba, 0, -1);
        pairs_guess[9] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[8]);

        pairs_guess[10] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[10])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x1c2, 0, -1);
        ((Control_guess*)pairs_guess[10])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x1c3, 0, -1);
        ((Control_guess*)pairs_guess[10])->AddItem_guess(pStringTable->getString(0x3abd, 0), 0x1c4, 0, -1);
        pairs_guess[11] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[10]);

        pairs_guess[12] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[12])->AddItem_guess(pStringTable->getString(0x3aba, 0), 0x1cc, 0, -1);
        ((Control_guess*)pairs_guess[12])->AddItem_guess(pStringTable->getString(0x3abb, 0), 0x1cd, 0, -1);
        ((Control_guess*)pairs_guess[12])->AddItem_guess(pStringTable->getString(0x3abc, 0), 0x1ce, 0, -1);
        pairs_guess[13] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[12]);

        pairs_guess[14] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aa6, 0),
            pairs_guess[1] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aa7, 0),
            pairs_guess[3] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aa8, 0),
            pairs_guess[5] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aa9, 0),
            pairs_guess[7] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aaa, 0),
            pairs_guess[9] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3aab, 0),
            pairs_guess[11] - 0x80000000, 0, -1);
        ((Control_guess*)pairs_guess[14])->AddItem_guess(pStringTable->getString(0x3395, 0),
            pairs_guess[13] - 0x80000000, 0, -1);
        pairs_guess[15] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[14]);
    }

    if (field_1a0_guess == 0) {
        field_1a0_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x19e6, 0), 200, 0, -1);
        field_1a0_guess->EnableItem_guess(
            field_1a0_guess->AddItem_guess(pStringTable->getString(0x19e7, 0), 0xc9, 0, -1), false);
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x19e8, 0), 0xca, 0, -1);
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x13f9, 0), 0xd9, 0, -1);
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x19e9, 0), 0xcb, 0, -1);
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x19ea, 0), 0xcc, 0, -1);
        field_1a0_guess->AddItem_guess(pStringTable->getString(0x19eb, 0), 0xcd, 0, -1);
        if (entryCount_guess > 0) {
            field_1a8_guess = field_1a0_guess->AddItem_guess(pStringTable->getString(0x19ee, 0),
                field_1b0_guess - 0x80000000, 0, -1);
            field_1a0_guess->EnableItem_guess(field_1a8_guess, true);
        } else {
            field_1a8_guess = field_1a0_guess->AddItem_guess(pStringTable->getString(0x19ee, 0), 0, 0, -1);
            field_1a0_guess->EnableItem_guess(field_1a8_guess, false);
        }
        field_1a4_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_1a0_guess);
    }

    // Only the languages the character has some skill in (items 300 + n).
    if (field_16c_guess == 0) {
        field_16c_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        CXStr text_guess;
        int known_guess = 0;
        int ids_guess[0x20];
        if (g_languageOwner_guess != 0) {
            std::fill_n(ids_guess, 0x20, -1);
            for (int i = 0; i < 0x20; ++i) {
                if (g_languageOwner_guess->Language_guess(i) > 0) {
                    ids_guess[known_guess++] = i;
                }
            }
        }
        for (int i = 0; i < known_guess; ++i) {
            text_guess =g_globalStrings_guess->GetString_guess(ids_guess[i]);
            field_16c_guess->AddItem_guess(text_guess, i + 300, 0, -1);
        }
        field_170_guess = pinstCContextMenuManager_guess->AddMenu_guess(field_16c_guess);
    }

    if (pairs_guess[16] == 0) {
        pairs_guess[16] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        pairs_guess[17] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[16]);
    }
    if (pairs_guess[18] == 0) {
        pairs_guess[18] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        pairs_guess[19] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[18]);
    }
    if (pairs_guess[20] == 0) {
        pairs_guess[20] = (int)new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        pairs_guess[21] = pinstCContextMenuManager_guess->AddMenu_guess((Control_guess*)pairs_guess[20]);
    }

    // The window's own menu is new each time: links to the shared submenus plus this window's check marks.
    Control_guess* menu_guess = new Control_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
    menu_guess->AddItem_guess(pStringTable->getString(0x19f3, 0),
        pinstCContextMenuManager_guess->field_1154_guess + 0x80000000, 0, -1);
    // 0x2D toggles the scroll bar.
    field_168_guess = menu_guess->AddItem_guess(pStringTable->getString(0x179f, 0), 0x2d, 0, -1);
    menu_guess->CheckItem_guess(field_168_guess,
        (((ChatWindow_guess*)(void*)value_guess)->scroll_guess->flags_guess & 1) != 0, false);
    menu_guess->AddSeparator_guess();
    menu_guess->AddItem_guess(pStringTable->getString(0x19f4, 0), 0x2a, 0, -1);
    menu_guess->AddItem_guess(pStringTable->getString(0xc44, 0), 0x2c, 0, -1);
    ((ChatWindow_guess*)(void*)value_guess)->field_264_guess =
        menu_guess->AddItem_guess(pStringTable->getString(0x3aa1, 0), 0x2b, 0, -1);
    menu_guess->AddSeparator_guess();
    field_20c_guess = menu_guess->AddItem_guess(pStringTable->getString(0xc4b, 0),
        pairs_guess[17] - 0x80000000, 0, -1);
    field_210_guess = menu_guess->AddItem_guess(pStringTable->getString(0xc4c, 0),
        pairs_guess[19] - 0x80000000, 0, -1);
    field_214_guess = menu_guess->AddItem_guess(pStringTable->getString(0xc4d, 0),
        pairs_guess[21] - 0x80000000, 0, -1);
    menu_guess->AddSeparator_guess();
    menu_guess->AddItem_guess(pStringTable->getString(0x19f5, 0), field_178_guess - 0x80000000, 0, -1);
    menu_guess->AddItem_guess(pStringTable->getString(0x19f6, 0), field_1a4_guess - 0x80000000, 0, -1);
    menu_guess->AddItem_guess(pStringTable->getString(0x19f7, 0), field_170_guess - 0x80000000, 0, -1);
    menu_guess->AddItem_guess(pStringTable->getString(0x3abe, 0), pairs_guess[15] - 0x80000000, 0, -1);
    field_164_guess = menu_guess;
    return pinstCContextMenuManager_guess->AddMenu_guess(menu_guess);
}

// Ticks the menu items that apply to the window `selected_guess`: its language, the filters routed to it,
// the chat channels and its default channel.
// FUNCTION: TITANIUM 0x004F5728
// @early-stop: budget, structural ndiff=145
void Selector_guess::Update_guess(SelectedItem_guess* selected_guess)
{
    int count_guess;
    if (field_16c_guess != 0) {
        Str_guess text_guess;
        int ids_guess[0x20];
        field_16c_guess->Reset_guess();
        count_guess = 0;
        SelectorBits_guess* bits_guess = g_selectorBits_guess;
        if (bits_guess != 0) {
            std::fill_n(ids_guess, 0x20, -1);
            for (int index_guess = 0; index_guess < 0x20; ++index_guess) {
                if ((unsigned int)index_guess >= 0x20) {
                    __debugbreak();
                }
                if ((bits_guess->data_guess->bytes_guess + (int)bits_guess + 8)[index_guess + 12] != 0) {
                    ids_guess[count_guess] = index_guess;
                    ++count_guess;
                }
            }
        }
        for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
            const char* label_guess = g_globalStrings_guess->GetString_guess(ids_guess[index_guess]);
            text_guess.Assign_guess(label_guess);
            int item_guess = field_16c_guess->AddText_guess(&text_guess, index_guess + 300, 0, -1);
            if (selected_guess != 0 && index_guess == selected_guess->selected_guess) {
                field_16c_guess->SetValue_guess(item_guess, 1, 0);
            }
        }
    }

    field_164_guess->SetValue_guess(field_168_guess,
        selected_guess->flags_guess->value_guess & 0xffffff01, 0);

    if (g_globalStrings_guess->entries_guess != 0) {
        int stringCount_guess = g_globalStrings_guess->entries_guess->GetCount_guess();
        if (stringCount_guess > 0) {
            if (field_198_guess != 0 && field_1ac_guess != 0) {
                field_198_guess->Reset_guess();
                field_1ac_guess->Reset_guess();
                for (int index_guess = 0; index_guess < stringCount_guess; ++index_guess) {
                    Str_guess text_guess;
                    new (&text_guess) Str_guess(g_globalStrings_guess->entries_guess->GetText_guess(index_guess));
                    int firstItem_guess = field_198_guess->AddText_guess(&text_guess, index_guess + 0x70, 0, -1);
                    int slot_guess = GetChannelMap_guess(index_guess + 0x0c);
                    if ((int)selected_guess == slot_guess) {
                        field_198_guess->SetValue_guess(firstItem_guess, 1, 0);
                    }
                    int secondItem_guess = field_1ac_guess->AddText_guess(&text_guess, index_guess + 0xcf, 0, -1);
                    if ((selected_guess->type_guess == 0x13 || selected_guess->type_guess == 0x14) &&
                        selected_guess->index_guess == index_guess) {
                        field_1ac_guess->SetValue_guess(secondItem_guess, 1, 0);
                    }
                }
                {
                    Str_guess error_guess(pStringTable->getString(0x3395, 0));
                    field_198_guess->AddText_guess(&error_guess, 0x9d, 0, -1);
                }
                field_174_guess->SetItemData((int)field_17c_guess, field_19c_guess - 0x80000000);
                field_174_guess->SetActive_guess((int)field_17c_guess, 1);
                field_1a0_guess->SetItemData((int)field_1a8_guess, field_1b0_guess - 0x80000000);
                field_1a0_guess->SetActive_guess((int)field_1a8_guess, 1);
            }
        } else {
            field_174_guess->SetActive_guess((int)field_17c_guess, 0);
            field_174_guess->SetItemData((int)field_17c_guess, 0);
            field_1a0_guess->SetActive_guess((int)field_1a8_guess, 0);
            field_1a0_guess->SetItemData((int)field_1a8_guess, 0);
        }
    } else {
        field_174_guess->SetActive_guess((int)field_17c_guess, 0);
        field_174_guess->SetItemData((int)field_17c_guess, 0);
        field_1a0_guess->SetActive_guess((int)field_1a8_guess, 0);
        field_1a0_guess->SetItemData((int)field_1a8_guess, 0);
    }

    count_guess = field_174_guess->count_guess;
    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        int value_guess = field_174_guess->GetItemData(index_guess);
        int show_guess = value_guess >= 1 && value_guess < 0x4000000 &&
            GetChannelMap_guess(value_guess - 100) == (int)selected_guess;
        field_174_guess->SetValue_guess(index_guess, show_guess, 0);
    }

    count_guess = field_188_guess->count_guess;
    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        int value_guess = field_188_guess->GetItemData(index_guess);
        int show_guess = value_guess >= 1 && value_guess < 0x4000000 &&
            GetChannelMap_guess(value_guess - 100) == (int)selected_guess;
        field_188_guess->SetValue_guess(index_guess, show_guess, 0);
    }

    count_guess = field_190_guess->count_guess;
    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        int value_guess = field_190_guess->GetItemData(index_guess);
        int show_guess = value_guess >= 1 && value_guess < 0x4000000 &&
            GetChannelMap_guess(value_guess - 100) == (int)selected_guess;
        field_190_guess->SetValue_guess(index_guess, show_guess, 0);
    }

    count_guess = field_1a0_guess->count_guess;
    int type_guess = selected_guess->type_guess;
    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        int value_guess = field_1a0_guess->GetItemData(index_guess);
        if (value_guess > 0 && value_guess < 0x4000000 &&
            ((value_guess == 200 && type_guess == 8) ||
             (value_guess == 0xc9 && type_guess == 7) ||
             (value_guess == 0xca && type_guess == 2) ||
             (value_guess == 0xd9 && type_guess == 0xf) ||
             (value_guess == 0xcb && type_guess == 0) ||
             (value_guess == 0xce && type_guess == 3) ||
             (value_guess == 0xcd && type_guess == 4) ||
             (value_guess == 0xcc && type_guess == 5))) {
            field_1a0_guess->SetValue_guess(index_guess, 1, 1);
            break;
        }
    }
    Finish_guess(selected_guess);
}

// Placeholder for a closed window ("@42" in the INI) so the next windows keep their numbers; the
// constructor deletes it again. String 0x19F8 says all 32 windows are in use.
// FUNCTION: TITANIUM 0x004F5C21
// @early-stop: unknown, structural ndiff=93
void Selector_guess::AddBlankChat_guess()
{
    int slot = -1;
    for (int i = 1; i < count_guess.Get_guess(); ++i) {
        if (values_guess[i] == 0) {
            slot = i;
            break;
        }
    }
    if (slot == -1 && count_guess.Get_guess() < 0x20) {
        slot = count_guess.count_guess++;
    }
    if (slot != -1) {
        Chat_guess* chat = new Chat_guess(0);
        int* entry_guess = &values_guess[slot];
        *entry_guess = (int)chat;
        chat->owner_guess = this;
        {
            FormattedCXStr_guess number_holder;
            CXStr& number = number_holder.Format_guess(slot, 2, 0x20);
            CXStr blank(EQ_ARRAY(char, 0x0063FE10));
            ((Value_guess*)(void*)*entry_guess)->Slot63_guess(
                CombineCXStr_guess(WrapCXStr_guess(pStringTable->getString(0x19e0, 0), blank), number));
        }
        ((Chat_guess*)(void*)*entry_guess)->field_1b0_guess = defaultLanguage_023c_guess;
        ((Chat_guess*)(void*)*entry_guess)->field_168_guess = defaultChannel_0238_guess;
        ((Value_guess*)(void*)*entry_guess)->Slot48_guess(1, 1);
        {
            FormattedCXStr_guess window_holder;
            CXStr& window_number = window_holder.Format_guess(slot, 2, 0x20);
            CXStr chat_name(EQ_ARRAY(char, 0x00652A1C));
            ((CSidlScreenWnd*)(void*)*entry_guess)->EnableIniStorage(0xfffffeff,
                (char*)CombineCXStr_guess(chat_name, window_number));
        }
        ((ValueData_guess*)(void*)*entry_guess)->value_guess = InitContextMenu((Value_guess*)(void*)*entry_guess);
    } else {
        ((Receiver_guess*)(void*)values_guess[0])->ShowText_guess(Str_guess(pStringTable->getString(0x19f8, 0)), 0xd);
    }
}

// Creates a saved chat window. The parameter names are off: they are the INI name, the INI section,
// language, default channel, chat channel, tell target, font style and the scroll bar flag.
// FUNCTION: TITANIUM 0x004F5E72
// @early-stop: budget, structural ndiff=117
void Selector_guess::AddChatWindow_guess(const char* name_guess, char* ini_guess, int tab_guess, int slot_guess, int depth_guess, const char* title_guess, int setup_guess, char focus_guess)
{
    int slot_guess_local = -1;
    for (int index_guess = 1; index_guess < count_guess.Get_guess(); ++index_guess) {
        if (values_guess[index_guess] == 0) {
            slot_guess_local = index_guess;
            break;
        }
    }
    if (slot_guess_local == -1 && count_guess.Get_guess() < 0x20) {
        slot_guess_local = count_guess.count_guess++;
    }
    if (slot_guess_local != -1) {
        Chat_guess* chat_guess = new Chat_guess(0);
        values_guess[slot_guess_local] = (int)chat_guess;
        chat_guess->owner_guess = this;
        {
            FormattedCXStr_guess number_guess;
            CXStr& number = number_guess.Format_guess(slot_guess_local, 2, 0x20);
            CXStr left_guess;
            ((Value_guess*)(void*)values_guess[slot_guess_local])->Slot63_guess(
                CombineCXStr_guess(
                    WrapCXStr_guess(pStringTable->getString(0x19e0, 0), CXStr(EQ_ARRAY(char, 0x0063FE10))),
                    number));
        }
        chat_guess->field_1b0_guess = tab_guess;
        chat_guess->field_168_guess = slot_guess;
        chat_guess->field_16c_guess = depth_guess;
        chat_guess->SetName_guess(title_guess);
        ((Value_guess*)(void*)values_guess[slot_guess_local])->Slot48_guess(1, 1);
        chat_guess->SetChatFont_guess(setup_guess);
        ((CSidlScreenWnd*)(void*)values_guess[slot_guess_local])->EnableIniStorage(0xfffffeff, ini_guess);
        if (focus_guess == 0) {
            chat_guess->window_guess->WindowStyle &= ~1;
        } else {
            chat_guess->window_guess->WindowStyle |= 1;
            chat_guess->window_guess->field_1c0_guess = 400;
        }
        ((ValueData_guess*)(void*)values_guess[slot_guess_local])->value_guess = InitContextMenu((Value_guess*)(void*)values_guess[slot_guess_local]);
    } else {
        ((Receiver_guess*)(void*)values_guess[0])->ShowText_guess(Str_guess(pStringTable->getString(0x19f8, 0)), 0xd);
    }
    if (name_guess[0] != 0) {
        Str_guess name_str_guess(name_guess);
        ((Value_guess*)(void*)values_guess[slot_guess_local])->Slot63_guess(*(const CXStr*)(void*)&name_str_guess);
    }
}

#define g_chatDefaultChannel_guess EQ_GLOBAL(char, 0x009237EC)
#define g_chatLanguage_guess EQ_GLOBAL(int, 0x009237F0)
#define g_chatTellTarget_guess EQ_ARRAY(char, 0x009237F4)

// Chat manager constructor: reads the default channel and language from [Defaults] (defaults.ini, then
// eqclient.ini), creates the main chat window 0 and windows 1 to NumWindows (at most 32) from the
// [ChatManager] keys, then LockedActiveWindow, the 54 ChannelMap routes and the 8 HitMode settings.
// FUNCTION: TITANIUM 0x004F60C5
// @early-stop: budget, structural ndiff=60
Selector_guess::Selector_guess()
{
    char window_guess[0x80];
    char key_guess[0x80];
    char value_guess[0x80];
    char name_guess[0x80];
    char tell_guess[0x80];
    char title_guess[0x100];
    int blank_guess[0x20];
    int i;

    field_170_guess = -1;
    field_178_guess = -1;
    field_17c_guess = -1;
    field_19c_guess = -1;
    field_1a4_guess = -1;
    field_1a8_guess = -1;
    field_1b0_guess = -1;
    field_18c_guess = -1;
    field_194_guess = -1;
    pairs_guess[1] = -1;
    pairs_guess[3] = -1;
    pairs_guess[5] = -1;
    pairs_guess[7] = -1;
    pairs_guess[9] = -1;
    pairs_guess[11] = -1;
    pairs_guess[13] = -1;
    pairs_guess[15] = -1;
    pairs_guess[17] = -1;
    pairs_guess[19] = -1;
    pairs_guess[21] = -1;
    field_16c_guess = 0;
    field_174_guess = 0;
    field_198_guess = 0;
    field_1a0_guess = 0;
    field_1ac_guess = 0;
    field_188_guess = 0;
    field_190_guess = 0;
    pairs_guess[0] = 0;
    pairs_guess[2] = 0;
    pairs_guess[4] = 0;
    pairs_guess[6] = 0;
    pairs_guess[8] = 0;
    pairs_guess[10] = 0;
    pairs_guess[12] = 0;
    pairs_guess[14] = 0;
    pairs_guess[16] = 0;
    pairs_guess[18] = 0;
    pairs_guess[20] = 0;
    for (i = 0; i < 8; ++i) {
        hit_modes_guess[i] = 0;
    }
    defaultChannel_0238_guess = g_ini_guess->ReadClientIniInt_guess("Defaults", "DefaultChannel", 8);
    defaultLanguage_023c_guess = g_ini_guess->ReadClientIniInt_guess("Defaults", "DefaultLanguage", 0);

    int windows_guess = g_ini_guess->ReadInt_guess("ChatManager", "NumWindows", 1, 1);
    if (windows_guess > 0x20) {
        windows_guess = 0x20;
    }
    if (windows_guess < 1) {
        windows_guess = 1;
    }
    int blanks_guess = 0;
    sprintf(window_guess, "ChatWindow0", 8);

    Chat_guess* chat_guess = new Chat_guess(0);
    index_guess = 0;
    selected_guess = -1;
    values_guess[0] = (int)chat_guess;
    count_guess.count_guess = 1;
    if (chat_guess != 0) {
        chat_guess->owner_guess = this;
        g_ini_guess->ReadString_guess("ChatManager", "ChatWindow0_Name",
            pStringTable->getString(0x19df, 0), value_guess, 0x80, 1);
        {
            CXStr text_guess(value_guess);
            ((Value_guess*)(void*)values_guess[0])->Slot63_guess(text_guess);
        }
        ((Chat_guess*)(void*)values_guess[0])->field_1b4_guess = 1;
        ((CXWnd*)(void*)values_guess[0])->WindowStyle &= ~0x28;
        ((Chat_guess*)(void*)values_guess[0])->field_1b0_guess =
            g_ini_guess->ReadInt_guess("ChatManager", "ChatWindow0_Language", defaultLanguage_023c_guess, 1);
        ((Chat_guess*)(void*)values_guess[0])->field_168_guess =
            g_ini_guess->ReadInt_guess("ChatManager", "ChatWindow0_DefaultChannel", defaultChannel_0238_guess, 1);
        g_ini_guess->ReadString_guess("ChatManager", "ChatWindow0_TellTarget",
            EQ_ARRAY(char, 0x0063F53F), value_guess, 0x80, 1);
        ((Chat_guess*)(void*)values_guess[0])->SetName_guess(value_guess);
        ((Chat_guess*)(void*)values_guess[0])->field_16c_guess =
            g_ini_guess->ReadInt_guess("ChatManager", "ChatWindow0_ChatChannel", 0, 1);
        // Window 0 is the main chat; it keeps its position under its own INI name.
        ((CSidlScreenWnd*)(void*)values_guess[0])->EnableIniStorage(0xfffffeff, "MainChat");
        if (g_ini_guess->ReadInt_guess("ChatManager", "ChatWindow0_Scrollbar", 1, 1) != 0) {
            ((Chat_guess*)(void*)values_guess[0])->window_guess->WindowStyle |= 1;
            ((Chat_guess*)(void*)values_guess[0])->window_guess->field_1c0_guess = 400;
        } else {
            ((Chat_guess*)(void*)values_guess[0])->window_guess->WindowStyle &= ~1;
        }
        ((ValueData_guess*)(void*)values_guess[0])->value_guess = InitContextMenu((Value_guess*)(void*)values_guess[0]);
        ((Chat_guess*)(void*)values_guess[0])->SetChatFont_guess(
            g_ini_guess->ReadInt_guess("ChatManager", "ChatWindow0_FontStyle", 3, 1));
        g_chatDefaultChannel_guess = (char)((ChatWindow_guess*)(void*)values_guess[0])->default_channel_guess;
        g_chatLanguage_guess = ((ChatWindow_guess*)(void*)values_guess[0])->language_guess;
        strcpy(g_chatTellTarget_guess, ((ChatWindow_guess*)(void*)values_guess[0])->tell_target_guess);
    }

    for (i = 0; i < 0x36; ++i) {
        // Every filter starts on the main window; ChannelMap<n> below may move it.
        filterWindows_guess[i] = values_guess[0];
    }

    for (i = 1; i <= windows_guess; ++i) {
        // Windows 1..NumWindows; a closed one ("@42") gets a placeholder, removed after the loop.
        sprintf(window_guess, "ChatWindow%d", i);
        sprintf(key_guess, "%s_Language", window_guess);
        g_ini_guess->ReadString_guess("ChatManager", key_guess, EQ_ARRAY(char, 0x006529B0), value_guess, 0x80, 1);
        if (strcmp(value_guess, EQ_ARRAY(char, 0x006529B0)) == 0) {
            AddBlankChat_guess();
            blank_guess[blanks_guess++] = i;
        } else {
            int language_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, defaultLanguage_023c_guess, 1);
            sprintf(key_guess, "%s_DefaultChannel", window_guess);
            int channel_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, defaultChannel_0238_guess, 1);
            sprintf(key_guess, "%s_ChatChannel", window_guess);
            int chat_channel_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, 0, 1);
            sprintf(key_guess, "%s_TellTarget", window_guess);
            g_ini_guess->ReadString_guess("ChatManager", key_guess, EQ_ARRAY(char, 0x0063F53F), tell_guess, 0x80, 1);
            sprintf(key_guess, "%s_Name", window_guess);
            g_ini_guess->ReadString_guess("ChatManager", key_guess, window_guess, name_guess, 0x80, 1);
            sprintf(key_guess, "%s_Scrollbar", window_guess);
            bool scroll_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, 1, 1) != 0;
            sprintf(key_guess, "%s_FontStyle", window_guess);
            int font_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, 3, 1);
            if (font_guess < 0 || font_guess > 7) {
                font_guess = 3;
            }
            sprintf(title_guess, "Chat %d", i);
            AddChatWindow_guess(name_guess, title_guess, language_guess, channel_guess, chat_channel_guess,
                tell_guess, font_guess, scroll_guess);
        }
    }
    if (blanks_guess > 0) {
        for (int j = 0; j < blanks_guess; ++j) {
            int* slot_guess = &values_guess[blank_guess[j]];
            ((Value_guess*)(void*)*slot_guess)->Slot34_guess();
            // The placeholders go again; 0x004F2859 empties their slot.
            Remove_guess(*slot_guess);
        }
    }

    int locked_guess = g_ini_guess->ReadInt_guess("ChatManager", "LockedActiveWindow", -1, 1);
    if (locked_guess < 0 || locked_guess >= count_guess.count_guess) {
        locked_guess = -1;
    }
    selected_guess = locked_guess;

    for (i = 0; i < 0x36; ++i) {
        sprintf(key_guess, "ChannelMap%d", i);
        int window_index_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, -1, 1);
        if (window_index_guess > -1 && window_index_guess < count_guess.count_guess) {
            SetChannelMap_guess(i, values_guess[window_index_guess]);
        }
    }

    for (i = 0; i < 8; ++i) {
        // 8 hit-message groups, mode 0-2 each.
        sprintf(key_guess, "HitMode%d", i);
        int mode_guess = g_ini_guess->ReadInt_guess("ChatManager", key_guess, 0, 1);
        if (mode_guess >= 0 && mode_guess <= 2) {
            hit_modes_guess[i] = mode_guess;
        }
    }
}

