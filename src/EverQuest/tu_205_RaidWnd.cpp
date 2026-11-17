// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 205: a hint from compare/tumap.py.
// CRaidWnd (screen "RaidWindow", vtable 0x0065BEB8). RaidWindow_guess, ListOwner_guess and EntryOwner_guess
// are views of the same window. RAID_PlayerList has 83 rows: 12 groups of 6 member rows, with separators
// between groups, so group g starts at row g * 7. Columns: 0 group, 1 name, 2 level, 3 class, 4 flags ("A",
// "M"), 5 rank text. g_raidPanel_guess (0x0091D708) is the raid object.
#include "titanium/types.h"
#include "titanium/crt.h"

struct Str_guess;

struct TextControl_guess {
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
    virtual void Slot0A_guess();
    virtual void Slot0B_guess();
    virtual void Slot0C_guess();
    virtual void Slot0D_guess();
    virtual void Slot0E_guess();
    virtual void Slot0F_guess();
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
    virtual void Slot1A_guess();
    virtual void Slot1B_guess();
    virtual void Slot1C_guess();
    virtual void Slot1D_guess();
    virtual void Slot1E_guess();
    virtual void Slot1F_guess();
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
    virtual void Slot2A_guess();
    virtual void Slot2B_guess();
    virtual void Slot2C_guess();
    virtual void Slot2D_guess();
    virtual void Slot2E_guess();
    virtual void Slot2F_guess();
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
    virtual void Slot3A_guess();
    virtual void Slot3B_guess();
    virtual void Slot3C_guess();
    virtual void Slot3D_guess();
    virtual void Slot3E_guess();
    virtual void Slot3F_guess(Str_guess* text_guess);
};

struct Str_guess {
    char* data_guess;
    Str_guess() : data_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00571FC0 ??4Str_guess@@QAEAAU0@PBD@Z
    Str_guess& operator=(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571F70 ??4Str_guess@@QAEAAU0@ABU0@@Z
    Str_guess& operator=(const Str_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00572300 ??BStr_guess@@QBEPADXZ
    operator char*() const;
    // EXTERNAL: TITANIUM 0x00572E00 ??YStr_guess@@QAEXPBD@Z
    void operator+=(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00572650 Str_guess::Equals_guess
    int Equals_guess(const Str_guess& text_guess);
    // EXTERNAL: TITANIUM 0x00573B10 Str_guess::Compare_guess
    int Compare_guess(const Str_guess& text_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::Release_guess
    void Release_guess(char* value_guess);
    int GetLength_guess() const { return data_guess != 0 ? *(int*)(data_guess + 8) : 0; }
    ~Str_guess() {
        if (data_guess != 0) {
            Release_guess(data_guess);
        }
        data_guess = 0;
    }
};

struct RaidFindList_guess {
    char pad_0000_guess[0x11c];
    int count_011c_guess;
    // EXTERNAL: TITANIUM 0x00597F10 RaidFindList_guess::GetItemText
    Str_guess GetItemText(int index_guess, int column_guess);
    // EXTERNAL: TITANIUM 0x00597BE0 RaidFindList_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x0059B360 RaidFindList_guess::SetItemText
    void SetItemText(int index_guess, int column_guess, const CXStr& text_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(Str_guess* text_guess, const char* format_guess,
                                ...);

// EXTERNAL: TITANIUM 0x0060ACA0 FUN_0060aca0_guess
Str_guess FUN_0060aca0_guess(const Str_guess& source_guess);

struct EntryOwner_guess {
    char pad_0000_guess[0x124];
    int enabled_guess;
    char pad_0128_guess[0xD8];
    int values_guess[1];
    void SetClassColorValue_guess(int index, int value);
};

struct ColorTarget_guess {
    // EXTERNAL: TITANIUM 0x0059B3E0 ColorTarget_guess::SetValue_guess
    void SetValue_guess(int index, int flag, int value);
    // EXTERNAL: TITANIUM 0x0059B9D0 ColorTarget_guess::AddString
    int AddString(const Str_guess& text_guess, int index_guess,
                       int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00598620 ColorTarget_guess::SetItemData
    void SetItemData(int index_guess, int flag_guess);
};

struct CStmlWndView_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 CStmlWndView_guess::SetSTMLText
    void SetSTMLText(Str_guess text_guess, int first_guess, int second_guess);
};

struct RaidWindow_guess {
    char pad_0000_guess[0x124];
    int enabled_guess;
    char pad_0128_guess[0x34];
    ColorTarget_guess* playerList_guess;
    int pad_0160_guess;
    ColorTarget_guess* ungroupedPlayerList_guess;
    char pad_0168_guess[4];
    TextControl_guess* textTarget_016c_guess;
    TextControl_guess* progressTarget_0170_guess;
    char pad_0174_guess[0x80];
    CStmlWndView_guess* sink_01f4_guess;
    TextControl_guess* textTarget_01f8_guess;
    int pad_01fc_guess;
    int classColors_guess[16];
    void InitializeClassColors_guess();
    void SetRowClassColor_guess(int index, int classIndex, int group);
    void SetPlayerCount_guess(int value);
    void AddSeparatorRow_guess();
    void SetLevelAverage_guess(int value);
    void SetMotd_guess(const char* text_guess);
    int FindIndexNotInGroupList_guess(const char* name_guess);
};

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* destination_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message_guess, ...);

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
                                const char* defaultValue, char* value,
                                int size, char useDefault);

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key,
                                const char* value);

// EXTERNAL: TITANIUM 0x0060E3A3 atol
long __cdecl atol(const char* value);

// Sets RAID_PlayerCountLabel (+0x16C) to `value`.
// FUNCTION: TITANIUM 0x0054E1D9
void RaidWindow_guess::SetPlayerCount_guess(int value) {
    if (enabled_guess != 0) {
        Str_guess text;
        FormatString_guess(&text, EQ_ARRAY(char, 0x0063F53C), value);
        textTarget_016c_guess->Slot3F_guess(&text);
    }
}

// Appends the separator row after a group (flag 0x40000000).
// FUNCTION: TITANIUM 0x0054E242
void RaidWindow_guess::AddSeparatorRow_guess() {
    int index =
        playerList_guess->AddString(Str_guess(EQ_ARRAY(char, 0x0063F53F)),
                                         -1, 0, 0);
    playerList_guess->SetItemData(index, 0x40000000);
}

// Sets RAID_LevelAverageLabel (+0x170) to `value`.
// FUNCTION: TITANIUM 0x0054E2AD
void RaidWindow_guess::SetLevelAverage_guess(int value) {
    if (progressTarget_0170_guess != 0) {
        Str_guess text;
        FormatString_guess(&text, EQ_ARRAY(char, 0x0063F53C), value);
        progressTarget_0170_guess->Slot3F_guess(&text);
    }
}

// [RaidWindow] ClassColor0-15 from the UI ini; a missing key is written back as -1 (no colour).
// FUNCTION: TITANIUM 0x0054E9CB
void RaidWindow_guess::InitializeClassColors_guess() {
    char number_guess[128];
    char name_guess[128];
    char value_guess[128];
    if (enabled_guess != 0) {
        for (int i = 0; i < 16; ++i) {
            _sprintf(name_guess, "ClassColor%d", i);
            LoadStringFromUIIniFile_guess("RaidWindow", name_guess, "*NULL*", value_guess,
                               0x80, 1);
            if (value_guess[0] == '*') {
                __itoa(-1, number_guess, 10);
                FUN_0060bf20_guess("RaidWindow", name_guess, number_guess);
                classColors_guess[i] = -1;
            } else {
                classColors_guess[i] = (int)atol(value_guess);
            }
        }
    }
}

// Class-colour family. The colour table is in alphabetical class order (Bard 0, Beastlord 1, Cleric 2 ...
// Wizard 14), with Berserker added last (15); the switch maps class ids 1-16 into it. Column 3.
// This one takes a row index and picks the list by `group` (-1 = not in a group).
// FUNCTION: TITANIUM 0x0054EA8B
void RaidWindow_guess::SetRowClassColor_guess(int index, int classIndex, int group) {
    if (enabled_guess == 0) {
        return;
    }
    ColorTarget_guess* list = group == -1 ? ungroupedPlayerList_guess
                                          : playerList_guess;
    switch (classIndex) {
    case 1:
        list->SetValue_guess(index, 3, classColors_guess[13]);
        break;
    case 2:
        list->SetValue_guess(index, 3, classColors_guess[2]);
        break;
    case 3:
        list->SetValue_guess(index, 3, classColors_guess[8]);
        break;
    case 5:
        list->SetValue_guess(index, 3, classColors_guess[11]);
        break;
    case 4:
        list->SetValue_guess(index, 3, classColors_guess[9]);
        break;
    case 6:
        list->SetValue_guess(index, 3, classColors_guess[3]);
        break;
    case 7:
        list->SetValue_guess(index, 3, classColors_guess[6]);
        break;
    case 8:
        list->SetValue_guess(index, 3, classColors_guess[0]);
        break;
    case 9:
        list->SetValue_guess(index, 3, classColors_guess[10]);
        break;
    case 10:
        list->SetValue_guess(index, 3, classColors_guess[12]);
        break;
    case 11:
        list->SetValue_guess(index, 3, classColors_guess[7]);
        break;
    case 12:
        list->SetValue_guess(index, 3, classColors_guess[14]);
        break;
    case 13:
        list->SetValue_guess(index, 3, classColors_guess[5]);
        break;
    case 14:
        list->SetValue_guess(index, 3, classColors_guess[4]);
        break;
    case 15:
        list->SetValue_guess(index, 3, classColors_guess[1]);
        break;
    case 16:
        list->SetValue_guess(index, 3, classColors_guess[15]);
        break;
    }
}

struct ListOwner_guess {
    char pad_0000_guess[0x15C];
    int playerList_guess;
    int pad_0160_guess;
    int ungroupedPlayerList_guess;
    char pad_0168_guess[0x80];
    int noteList_guess;
    int noteEdit_guess;
    // EXTERNAL: TITANIUM 0x005A1EF0 ListOwner_guess::LoadIniListWnd
    void LoadIniListWnd(int list, const char* name);
    // EXTERNAL: TITANIUM 0x005A1FE0 ListOwner_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(int list, const char* name);
    void RegisterListLayouts_guess();
    void ClearLists_guess();
    int FindNote_guess(const char* name_guess);
    void SetNoteText_guess(const char* name_guess, const char* text_guess);
};

// Sets class colour `index` (+0x200 is the colour table; EntryOwner_guess is a misnamed view).
// FUNCTION: TITANIUM 0x0054EB91
void EntryOwner_guess::SetClassColorValue_guess(int index, int value) {
    if (enabled_guess != 0) {
        values_guess[index] = value;
    }
}

// RAID_NoteList row whose name column matches, or -1.
// FUNCTION: TITANIUM 0x0054EBAC
int ListOwner_guess::FindNote_guess(const char* name_guess) {
    if (noteList_guess != 0) {
        Str_guess name(name_guess);
        int count = ((RaidFindList_guess*)noteList_guess)->count_011c_guess;
        for (int i = 0; i < count; ++i) {
            if (name.Equals_guess(((RaidFindList_guess*)noteList_guess)->GetItemText(i, 1))) {
                return i;
            }
        }
    }
    return -1;
}

// RAID_NotInGroupPlayerList row with that name, or -1.
// FUNCTION: TITANIUM 0x0054EC6E
int RaidWindow_guess::FindIndexNotInGroupList_guess(const char* name_guess) {
    Str_guess name(name_guess);
    int count = ((RaidFindList_guess*)ungroupedPlayerList_guess)->count_011c_guess;
    int index = 0;
    while (index < count) {
        if (name.Equals_guess(
                ((RaidFindList_guess*)ungroupedPlayerList_guess)
                    ->GetItemText(index, 1))) {
            return index;
        }
        ++index;
    }
    return -1;
}

// Sets the raid MOTD in both MOTDViewer and MOTDInput.
// FUNCTION: TITANIUM 0x0054ED28
void RaidWindow_guess::SetMotd_guess(const char* text_guess) {
    Str_guess text = FUN_0060aca0_guess(text_guess);
    if (sink_01f4_guess != 0) {
        sink_01f4_guess->SetSTMLText(text, 1, 0);
    }
    if (textTarget_01f8_guess != 0) {
        textTarget_01f8_guess->Slot3F_guess(&text);
    }
}

// Updates the member's note; the note edit box follows when that row is selected.
// FUNCTION: TITANIUM 0x0054EDD1
void ListOwner_guess::SetNoteText_guess(const char* name_guess, const char* text_guess) {
    if (noteList_guess != 0) {
        int found = -1;
        for (int i = 0; i < ((RaidFindList_guess*)noteList_guess)->count_011c_guess; ++i) {
            bool matched;
            {
                Str_guess name(name_guess);
                matched = ((RaidFindList_guess*)noteList_guess)->GetItemText(i, 1).Compare_guess(name, 0) == 0;
            }
            if (matched) {
                found = i;
                ((RaidFindList_guess*)noteList_guess)->SetItemText(i, 2, text_guess);
                break;
            }
        }
        int selected = ((RaidFindList_guess*)noteList_guess)->GetCurSel();
        if (found != -1 && selected == found && noteEdit_guess != 0) {
            Str_guess text(text_guess);
            ((TextControl_guess*)noteEdit_guess)->Slot3F_guess(&text);
        }
    }
}

// LoadIniInfo side: loads the column layouts of NoteList, PlayerList and UngroupedPlayerList from the INI
// (CSidlScreenWnd::LoadIniListWnd, 0x005A1EF0); ClearLists_guess (0x0054EF6D) stores them.
// FUNCTION: TITANIUM 0x0054EF25
void ListOwner_guess::RegisterListLayouts_guess() {
    if (noteList_guess != 0) {
        LoadIniListWnd(noteList_guess, "NoteList");
    }
    if (playerList_guess != 0) {
        LoadIniListWnd(playerList_guess, "PlayerList");
    }
    if (ungroupedPlayerList_guess != 0) {
        LoadIniListWnd(ungroupedPlayerList_guess, "UngroupedPlayerList");
    }
}

// StoreIniInfo side: saves NoteList, PlayerList and UngroupedPlayerList through the list INI store
// (0x005A1FE0).
// FUNCTION: TITANIUM 0x0054EF6D
void ListOwner_guess::ClearLists_guess() {
    if (noteList_guess != 0) {
        StoreIniListWnd_guess(noteList_guess, "NoteList");
    }
    if (playerList_guess != 0) {
        StoreIniListWnd_guess(playerList_guess, "PlayerList");
    }
    if (ungroupedPlayerList_guess != 0) {
        StoreIniListWnd_guess(ungroupedPlayerList_guess, "UngroupedPlayerList");
    }
}


// A list window as the raid window configures it (fields past the header's CListWnd 0x140).
struct RaidListWnd_guess : CListWnd {
    char pad_140[0x14];
    int field_154;                      // 0x154
    unsigned char field_158_guess;            // 0x158
    char pad_159[3];
    unsigned char field_15c;            // 0x15c
    char pad_15d[0xf];
    unsigned int color_16c;             // 0x16c
    // EXTERNAL: TITANIUM 0x00597F10 RaidListWnd_guess::GetItemText
    Str_guess GetItemText(int index_guess, int column_guess);
    // EXTERNAL: TITANIUM 0x0059B360 RaidListWnd_guess::SetItemText
    void SetItemText(int index_guess, int column_guess, const Str_guess& text_guess);
    // EXTERNAL: TITANIUM 0x00597BE0 RaidListWnd_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x005980B0 RaidListWnd_guess::GetItemColor_guess
    int GetItemColor_guess(int index_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0059B3E0 RaidListWnd_guess::SetItemColor_guess
    void SetItemColor_guess(int index_guess, int flag_guess, int color_guess);
    // EXTERNAL: TITANIUM 0x0059B9D0 RaidListWnd_guess::AddString
    int AddString(const Str_guess& text_guess, int color_guess, int data_guess, int icon_guess);
    // EXTERNAL: TITANIUM 0x0059C130 RaidListWnd_guess::RemoveLineThunk_guess
    void RemoveLineThunk_guess(int index_guess);
};

struct RaidEditWnd_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x004D7EBC RaidEditWnd_guess::SetMaxChars
    void SetMaxChars(int count);
    // EXTERNAL: TITANIUM 0x005B7EA0 RaidEditWnd_guess::SetFlag_guess
    void SetFlag_guess(bool value_guess);
};

struct RaidMotdViewer_guess {
    // EXTERNAL: TITANIUM 0x004F6895 RaidMotdViewer_guess::GetSTMLText
    Str_guess GetSTMLText();
};

struct RaidSpawn_guess {
    char pad_000[0x244];
    unsigned char field_244;            // 0x244
};
#define g_raidTarget_guess EQ_GLOBAL(RaidSpawn_guess*, 0x00905D04)
#define g_raidLocalSpawn_guess EQ_GLOBAL(RaidSpawn_guess*, 0x00905CE4)

struct RaidCharIndex_guess {
    int field_0;
    int index_4;                        // 0x4
};
struct RaidCharData_guess {
    char pad_0000[0xc284];
    RaidCharIndex_guess* index_c284;    // 0xc284
    char pad_c288[0x104];
    unsigned char flags_c38c[1];        // 0xc38c
};
#define g_raidCharData_guess EQ_GLOBAL(RaidCharData_guess*, 0x00905D00)

struct RaidButtonWnd_guess {
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
    virtual void Slot48_guess(int value, int flag);
    char pad_004[0x59];
    unsigned char Enabled;              // 0x05d
};

/* ---- CRaidWnd::CRaidWnd(CXWnd*) (0x0054EFB5) --------------------------------------------------------
 * Layout: include/titanium/types.h CRaidWnd (0x290); this file's RaidWindow_guess / ListOwner_guess
 * functions view the same object. The ctor needs a polymorphic class with the real CSidlScreenWnd
 * base ctor/dtor, so it derives from CSidlScreenWndBase. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CRaidOptionsWnd.h"

struct ClientState_guess {
    char pad_0000_guess[0x148];
    int tick_0148_guess;
};
#define g_clientState_guess EQ_GLOBAL(ClientState_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x0065BEB8 ??_7CRaidWndView_guess@@6B@
struct CRaidWndView_guess : CSidlScreenWndBase {
    RaidListWnd_guess* playerList_15c;          // 0x15c RAID_PlayerList
    CXWnd* playerListLabel_160;                 // 0x160
    RaidListWnd_guess* notInGroupList_164;      // 0x164 RAID_NotInGroupPlayerList
    CXWnd* notInGroupListLabel_168;             // 0x168
    CXWnd* playerCountLabel_16c;                // 0x16c
    CXWnd* levelAverageLabel_170;               // 0x170
    CXWnd* inviteButton_174;                    // 0x174
    CXWnd* disbandButton_178;                   // 0x178
    CXWnd* acceptButton_17c;                    // 0x17c
    CXWnd* declineButton_180;                   // 0x180
    CXWnd* makeLeaderButton_184;                // 0x184
    CXWnd* optionsButton_188;                   // 0x188
    CXWnd* addLooterButton_18c;                 // 0x18c
    CXWnd* removeLooterButton_190;              // 0x190
    CXWnd* dumpButton_194;                      // 0x194
    CXWnd* mainAssistButton_198;                // 0x198
    CXWnd* markNpcButton_19c;                   // 0x19c
    CXWnd* pad_1a0;
    CXWnd* findPcButton_1a4;                    // 0x1a4
    CXWnd* lockButton_1a8;                      // 0x1a8
    RaidButtonWnd_guess* unlockButton_1ac;      // 0x1ac
    CXWnd* removeLeaderButton_1b0;              // 0x1b0
    CXWnd* noGroupButton_1b4;                   // 0x1b4
    CXWnd* groupButtons_1b8[12];                // 0x1b8 RAID_Group1Button .. RAID_Group12Button
    RaidListWnd_guess* noteList_1e8;            // 0x1e8
    RaidEditWnd_guess* noteEdit_1ec;            // 0x1ec
    CXWnd* noteUpdateButton_1f0;                // 0x1f0
    CXWnd* motdViewer_1f4;                      // 0x1f4
    RaidEditWnd_guess* motdInput_1f8;           // 0x1f8
    CXWnd* updateMotdButton_1fc;                // 0x1fc
    char pad_200[0x40];
    int field_240;                              // 0x240
    char pad_244[0x48];
    unsigned char field_28c;                    // 0x28c
    char pad_28d[3];
    CRaidWndView_guess(CXWnd* parent);
    void CloseGroupGap_guess(int first_guess, int group_guess);
    int FindPlayerIndexInGroup_guess(const char* name_guess, int group_guess);
    int FindEmptySlotInGroup_guess(int group_guess);
    void AddPlayer_guess(const char* leader_guess, const char* name_guess, const char* class_guess,
                         const char* level_guess, const char* empty_guess, int key_guess,
                         int classId_guess, unsigned char leaderFlag_guess, const char* group_guess);
    void RemovePlayerFromList_guess(const char* name_guess, int group_guess);
    void SetMemberFlagsText_guess(const char* name_guess, int group_guess, bool first_guess,
                             bool second_guess, int unused_guess);
    void SetMemberRankText_guess(const char* name_guess, const char* leader_guess, int group_guess);
    void ChangePosition(const char* name_guess, int group_guess, int key_guess,
                              int classId_guess, unsigned char leaderFlag_guess);
    void ChangeRaidGroupLeader(const char* newLeader, int group, const char* oldLeader);
    void RenamePlayer_guess(const char* value_guess, const char* name_guess, int group_guess);
    void SetHighlight_guess(const char* leader_guess, int leaderGroup_guess,
                            const char* name_guess, int group_guess);
    void SetPlayerClassColor_guess(const char* name_guess, int classIndex_guess,
                                   int group_guess);
    void Update_54E316_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CRaidWndView_guess::OnProcessFrame
    int OnProcessFrame();
    int OnProcessFrame_guess();
    void UpdateThunk_54E316_guess();
    bool Activate_guess();
    void DumpRoster_guess(const char* fileName);
    void Refresh_54FEC9_guess();
    void Refresh_550A6C_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                              void* data_guess);
};

struct RaidPanel_guess {
    // EXTERNAL: TITANIUM 0x00430048 RaidPanel_guess::RebuildRaidList_guess
    void RebuildRaidList_guess();
    // EXTERNAL: TITANIUM 0x00430CE5 RaidPanel_guess::InviteToRaid_guess
    void InviteToRaid_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00430F03 RaidPanel_guess::RespondToInvite_guess
    void RespondToInvite_guess(char state_guess);
    // EXTERNAL: TITANIUM 0x00430FEA RaidPanel_guess::MakeLeader_guess
    void MakeLeader_guess(char* value_guess);
    // EXTERNAL: TITANIUM 0x004310A3 RaidPanel_guess::RemoveSelectedOrLeave_guess
    void RemoveSelectedOrLeave_guess();
    // EXTERNAL: TITANIUM 0x004311CC RaidPanel_guess::RequestAddLooter_guess
    void RequestAddLooter_guess();
    // EXTERNAL: TITANIUM 0x00431258 RaidPanel_guess::RequestRemoveLooter_guess
    void RequestRemoveLooter_guess();
    // EXTERNAL: TITANIUM 0x0042FCC2 RaidPanel_guess::IsInRaid_guess
    unsigned char IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x0042FCCE RaidPanel_guess::IsInvitePending_guess
    unsigned char IsInvitePending_guess();
    // EXTERNAL: TITANIUM 0x004302D2 RaidPanel_guess::GetMemberCount_guess
    int GetMemberCount_guess();
    // EXTERNAL: TITANIUM 0x0042FCF9 RaidPanel_guess::IsLocked_guess
    unsigned char IsLocked_guess();
    // EXTERNAL: TITANIUM 0x0042FD00 RaidPanel_guess::IsRaidLeader_guess
    unsigned char IsRaidLeader_guess();
    // EXTERNAL: TITANIUM 0x0042FD07 RaidPanel_guess::GetSelectedMember_guess
    int GetSelectedMember_guess();
    // EXTERNAL: TITANIUM 0x004307A4 RaidPanel_guess::SetTargetRaidPlayer_guess
    void SetTargetRaidPlayer_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x0042FE70 RaidPanel_guess::SendMotd_guess
    void SendMotd_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x0042FF0B RaidPanel_guess::SendMemberNote_guess
    void SendMemberNote_guess(const char* first_guess, const char* second_guess);
    // EXTERNAL: TITANIUM 0x004312BE RaidPanel_guess::Dispatch6_guess
    void Dispatch6_guess(const char* text_guess, int options_guess);
    // EXTERNAL: TITANIUM 0x004312E9 RaidPanel_guess::Dispatch7_guess
    void Dispatch7_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00431312 RaidPanel_guess::RequestLock_guess
    void RequestLock_guess();
    // EXTERNAL: TITANIUM 0x0043133E RaidPanel_guess::RequestUnlock_guess
    void RequestUnlock_guess();
};
#define g_raidPanel_guess EQ_GLOBAL(RaidPanel_guess, 0x0091D708)

struct RaidDataController_guess {
    // EXTERNAL: TITANIUM 0x004B4171 RaidDataController_guess::SendRaidDelegateAbility_guess
    void SendRaidDelegateAbility_guess(unsigned int value_guess, const char* message_guess);
    // EXTERNAL: TITANIUM 0x004B4617 RaidDataController_guess::FindPathToPlayer_guess
    void FindPathToPlayer_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x004B44C6 RaidDataController_guess::CanUseAbility_guess
    bool CanUseAbility_guess(void* target_guess, unsigned int action_guess, int amount_guess);
};
#define g_raidDataController_guess EQ_GLOBAL(RaidDataController_guess*, 0x009859EC)

struct RaidControl_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot0A_guess(); virtual void Slot0B_guess();
    virtual void Slot0C_guess(); virtual void Slot0D_guess();
    virtual void Slot0E_guess(); virtual void Slot0F_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot1A_guess(); virtual void Slot1B_guess();
    virtual void Slot1C_guess(); virtual void Slot1D_guess();
    virtual void Slot1E_guess(); virtual void Slot1F_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot2A_guess(); virtual void Slot2B_guess();
    virtual void Slot2C_guess(); virtual void Slot2D_guess();
    virtual void Slot2E_guess(); virtual void Slot2F_guess();
    virtual void Show_guess(bool show_guess, bool flag_guess); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess();
    virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess();
    virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot3A_guess(); virtual void Slot3B_guess();
    virtual void Slot3C_guess(); virtual void Slot3D_guess();
    virtual void Slot3E_guess();
    virtual void Slot3F_guess(const Str_guess& text_guess);
    virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess();
    virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess();
    virtual void Slot4A_guess(); virtual void Slot4B_guess();
    virtual Str_guess Slot4C_guess();
    virtual void Slot4D_guess();
    virtual void Slot4E_guess();
};

struct ListSlots_guess {
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
    virtual void Slot4C_guess();
};

#define RAID_SHOW(wnd, show, flag) ((RaidControl_guess*)(wnd))->Show_guess(show, flag)

// Button states, every 250 ms (OnProcessFrame_guess). Accept/Decline replace Invite/Disband while an invite
// is pending. Invite needs a player target other than yourself, and as raid leader fewer than 72 members.
// While locked, only the leader may move members (group buttons, No Group, Remove Leader).
// Find PC, Main Assist and Mark NPC need a delegate bit (0x40) and abilities 0x1C, 0x13 and 0x14.
// Only the leader may edit the MOTD and notes; Update is enabled once the text differs.
// FUNCTION: TITANIUM 0x0054E316
// @early-stop: budget, structural ndiff=132
void CRaidWndView_guess::Update_54E316_guess() {
    if (SidlPiece == 0 || acceptButton_17c == 0 || declineButton_180 == 0) {
        return;
    }
    makeLeaderButton_184->Enabled = 0;
    optionsButton_188->Enabled = g_raidPanel_guess.IsInRaid_guess();
    // Invite pending (+0x55E4 bit 1): Accept and Decline take the places of Invite and Disband; bit 2
    // enables Options and Disband.
    if (g_raidPanel_guess.IsInvitePending_guess()) {
        RAID_SHOW(acceptButton_17c, 1, 1);
        RAID_SHOW(declineButton_180, 1, 1);
        RAID_SHOW(inviteButton_174, 0, 1);
        RAID_SHOW(disbandButton_178, 0, 1);
    } else {
        RAID_SHOW(acceptButton_17c, 0, 1);
        RAID_SHOW(declineButton_180, 0, 1);
        RAID_SHOW(inviteButton_174, 1, 1);
        RAID_SHOW(disbandButton_178, 1, 1);
    }
    disbandButton_178->Enabled = g_raidPanel_guess.IsInRaid_guess();
    inviteButton_174->Enabled = 0;
    // With +0x55B8 set Accept, Decline and Invite are all off.
    if (g_raidPanel_guess.IsLocked_guess()) {
        acceptButton_17c->Enabled = 0;
        declineButton_180->Enabled = 0;
        inviteButton_174->Enabled = 0;
        if (g_raidPanel_guess.IsRaidLeader_guess()) {
            if (lockButton_1a8 != 0) {
                RAID_SHOW(lockButton_1a8, 0, 1);
                lockButton_1a8->Enabled = 0;
            }
            if (unlockButton_1ac != 0) {
                RAID_SHOW(unlockButton_1ac, 1, 1);
                unlockButton_1ac->Enabled = 1;
            }
            if (noGroupButton_1b4 != 0) {
                noGroupButton_1b4->Enabled = 1;
            }
            if (removeLeaderButton_1b0 != 0) {
                removeLeaderButton_1b0->Enabled = 1;
            }
            for (int i = 0; i < 12; ++i) {
                if (groupButtons_1b8[i] != 0) {
                    groupButtons_1b8[i]->Enabled = 1;
                }
            }
        } else {
            if (lockButton_1a8 != 0) {
                RAID_SHOW(lockButton_1a8, 1, 1);
                lockButton_1a8->Enabled = 0;
            }
            if (unlockButton_1ac != 0) {
                RAID_SHOW(unlockButton_1ac, 0, 1);
                unlockButton_1ac->Enabled = 0;
            }
            if (noGroupButton_1b4 != 0) {
                noGroupButton_1b4->Enabled = 0;
            }
            if (removeLeaderButton_1b0 != 0) {
                removeLeaderButton_1b0->Enabled = 0;
            }
            for (int i = 0; i < 12; ++i) {
                if (groupButtons_1b8[i] != 0) {
                    groupButtons_1b8[i]->Enabled = 0;
                }
            }
        }
    } else {
        acceptButton_17c->Enabled = 1;
        declineButton_180->Enabled = 1;
        if (g_raidPanel_guess.IsRaidLeader_guess()) {
            if (lockButton_1a8 != 0) {
                RAID_SHOW(lockButton_1a8, 1, 1);
                lockButton_1a8->Enabled = 1;
            }
            if (unlockButton_1ac != 0) {
                RAID_SHOW(unlockButton_1ac, 0, 1);
                unlockButton_1ac->Enabled = 0;
            }
        } else {
            if (lockButton_1a8 != 0) {
                RAID_SHOW(lockButton_1a8, 1, 1);
                lockButton_1a8->Enabled = 0;
            }
            if (unlockButton_1ac != 0) {
                RAID_SHOW(unlockButton_1ac, 0, 1);
                unlockButton_1ac->Enabled = 0;
            }
        }
        if (noGroupButton_1b4 != 0) {
            noGroupButton_1b4->Enabled = 0;
        }
        if (removeLeaderButton_1b0 != 0) {
            removeLeaderButton_1b0->Enabled = 0;
        }
        for (int i = 0; i < 12; ++i) {
            if (groupButtons_1b8[i] != 0) {
                groupButtons_1b8[i]->Enabled = 0;
            }
        }
        RaidSpawn_guess* target = g_raidTarget_guess;
        if (target != 0 && target->field_244 == 0) {
            bool notSelf = target != g_raidLocalSpawn_guess;
            if (!g_raidPanel_guess.IsInRaid_guess()) {
                inviteButton_174->Enabled = notSelf;
            } else if (g_raidPanel_guess.IsRaidLeader_guess()) {
                if (g_raidPanel_guess.GetMemberCount_guess() < 0x48) {
                    inviteButton_174->Enabled = notSelf;
                }
                makeLeaderButton_184->Enabled = notSelf;
            }
        }
    }
    // Delegated abilities: Main Assist, Mark NPC and Find PC.
    if (mainAssistButton_198 != 0) {
        mainAssistButton_198->Enabled = 0;
    }
    if (markNpcButton_19c != 0) {
        markNpcButton_19c->Enabled = 0;
    }
    if (findPcButton_1a4 != 0) {
        findPcButton_1a4->Enabled = 0;
        if (g_raidPanel_guess.IsInRaid_guess() && g_raidDataController_guess != 0 &&
            (g_raidCharData_guess->flags_c38c[g_raidCharData_guess->index_c284->index_4] & 0x40) != 0 &&
            g_raidDataController_guess->CanUseAbility_guess(g_raidCharData_guess, 0x1c, 1)) {
            findPcButton_1a4->Enabled = 1;
        }
    }
    if (g_raidPanel_guess.IsInRaid_guess() && g_raidPanel_guess.IsRaidLeader_guess()) {
        addLooterButton_18c->Enabled = 1;
        removeLooterButton_190->Enabled = 1;
        if (g_raidDataController_guess != 0 &&
            (g_raidCharData_guess->flags_c38c[g_raidCharData_guess->index_c284->index_4] & 0x40) != 0) {
            if (g_raidDataController_guess->CanUseAbility_guess(g_raidCharData_guess, 0x13, 1) &&
                mainAssistButton_198 != 0) {
                mainAssistButton_198->Enabled = 1;
            }
            if (g_raidDataController_guess->CanUseAbility_guess(g_raidCharData_guess, 0x14, 1) &&
                markNpcButton_19c != 0) {
                markNpcButton_19c->Enabled = 1;
            }
        }
    } else {
        addLooterButton_18c->Enabled = 0;
        removeLooterButton_190->Enabled = 0;
    }
    // MOTD and notes: leader only, Update once the text differs.
    bool motdChanged = false;
    if (motdInput_1f8 != 0 && motdViewer_1f4 != 0) {
        motdChanged = ((RaidControl_guess*)motdInput_1f8)->Slot4C_guess().Compare_guess(
                          ((RaidMotdViewer_guess*)motdViewer_1f4)->GetSTMLText(), 0) != 0;
    }
    if (updateMotdButton_1fc != 0) {
        updateMotdButton_1fc->Enabled = g_raidPanel_guess.IsRaidLeader_guess() && motdChanged;
        RAID_SHOW(updateMotdButton_1fc, g_raidPanel_guess.IsRaidLeader_guess(), 1);
    }
    if (motdInput_1f8 != 0) {
        motdInput_1f8->Enabled = g_raidPanel_guess.IsRaidLeader_guess();
        RAID_SHOW(motdInput_1f8, g_raidPanel_guess.IsRaidLeader_guess(), 1);
    }
    if (motdViewer_1f4 != 0) {
        motdViewer_1f4->Enabled = !g_raidPanel_guess.IsRaidLeader_guess();
        RAID_SHOW(motdViewer_1f4, !g_raidPanel_guess.IsRaidLeader_guess(), 1);
    }
    bool noteChanged = false;
    bool hasSelection = false;
    if (noteEdit_1ec != 0) {
        if (noteList_1e8 != 0) {
            int sel = noteList_1e8->GetCurSel();
            if (sel != -1) {
                hasSelection = true;
                noteChanged = noteList_1e8->GetItemText(sel, 2).Compare_guess(
                                  ((RaidControl_guess*)noteEdit_1ec)->Slot4C_guess(), 0) != 0;
            }
        }
        if (noteEdit_1ec != 0) {
            noteEdit_1ec->SetFlag_guess(g_raidPanel_guess.IsRaidLeader_guess() && hasSelection);
        }
    }
    if (noteUpdateButton_1f0 != 0) {
        noteUpdateButton_1f0->Enabled = g_raidPanel_guess.IsRaidLeader_guess() && noteChanged;
    }
}

// Full rebuild: buttons, the empty grid, then the raid object's member list.
// FUNCTION: TITANIUM 0x00550A6C
void CRaidWndView_guess::Refresh_550A6C_guess() {
    if (SidlPiece != 0) {
        Update_54E316_guess();
        Refresh_54FEC9_guess();
        g_raidPanel_guess.RebuildRaidList_guess();
    }
}

// AboutToShow (vtable slot 49): full rebuild, then context tip 0x37 on CTipWnd (0x009928E0).
// FUNCTION: TITANIUM 0x00550A91
bool CRaidWndView_guess::Activate_guess() {
    Refresh_550A6C_guess();
    if (pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x37, 0);
    }
    return true;
}

// Window id 0x37 (+0x158). Notes are capped at 63 characters and the MOTD at 1023; every list uses
// white text, yellow highlight and grey selection.
// FUNCTION: TITANIUM 0x0054EFB5
CRaidWndView_guess::CRaidWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "RaidWindow", -0x201, 1, 0) {
    WindowStyle |= 0x10000;
    noteList_1e8 = 0;
    noteEdit_1ec = 0;
    noteUpdateButton_1f0 = 0;
    motdViewer_1f4 = 0;
    motdInput_1f8 = 0;
    updateMotdButton_1fc = 0;
    field_158_guess = 0x37;
    if (SidlPiece != 0) {
        unsigned int style = SidlPiece->style_guess | 0x800;
        WindowStyle |= style;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        playerList_15c = (RaidListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("RAID_PlayerList");
        playerListLabel_160 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_PlayerListLabel");
        notInGroupList_164 = (RaidListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("RAID_NotInGroupPlayerList");
        notInGroupListLabel_168 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_NotInGroupPlayerListLabel");
        playerCountLabel_16c = ((CSidlScreenWnd*)this)->GetChildItem("RAID_PlayerCountLabel");
        levelAverageLabel_170 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_LevelAverageLabel");
        inviteButton_174 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_InviteButton");
        disbandButton_178 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_DisbandButton");
        acceptButton_17c = ((CSidlScreenWnd*)this)->GetChildItem("RAID_AcceptButton");
        declineButton_180 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_DeclineButton");
        makeLeaderButton_184 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_MakeLeaderButton");
        optionsButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_OptionsButton");
        addLooterButton_18c = ((CSidlScreenWnd*)this)->GetChildItem("RAID_AddLooterButton");
        removeLooterButton_190 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_RemoveLooterButton");
        dumpButton_194 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_DumpButton");
        mainAssistButton_198 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_MainAssistButton");
        markNpcButton_19c = ((CSidlScreenWnd*)this)->GetChildItem("RAID_MarkNPCButton");
        lockButton_1a8 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_LockButton");
        unlockButton_1ac = (RaidButtonWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("RAID_UnlockButton");
        removeLeaderButton_1b0 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_RemoveLeaderButton");
        noGroupButton_1b4 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_NoGroupButton");
        findPcButton_1a4 = ((CSidlScreenWnd*)this)->GetChildItem("RAID_FindPCButton");
        if (lockButton_1a8 != 0) {
            lockButton_1a8->Enabled = 0;
        }
        if (unlockButton_1ac != 0) {
            unlockButton_1ac->Enabled = 0;
            unlockButton_1ac->Slot48_guess(0, 1);
        }
        char name[0x20];
        for (int i = 0; i < 12; ++i) {
            _sprintf(name, "RAID_Group%dButton", i + 1);
            groupButtons_1b8[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            if (groupButtons_1b8[i] != 0) {
                groupButtons_1b8[i]->Enabled = 0;
            }
        }
        if (noGroupButton_1b4 != 0) {
            noGroupButton_1b4->Enabled = 0;
        }
        if (removeLeaderButton_1b0 != 0) {
            removeLeaderButton_1b0->Enabled = 0;
        }
        noteList_1e8 = (RaidListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("RAID_NoteList");
        noteEdit_1ec = (RaidEditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("NoteEdit");
        noteUpdateButton_1f0 = ((CSidlScreenWnd*)this)->GetChildItem("NoteUpdateButton");
        motdViewer_1f4 = ((CSidlScreenWnd*)this)->GetChildItem("MOTDViewer");
        motdInput_1f8 = (RaidEditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("MOTDInput");
        updateMotdButton_1fc = ((CSidlScreenWnd*)this)->GetChildItem("UpdateMOTDButton");
        if (noteList_1e8 != 0) {
            noteList_1e8->SetColors(-1, 0xffffff00, 0xff808080);
            noteList_1e8->SetColumnJustification(0, 1);
            noteList_1e8->SetColumnJustification(1, 0);
            noteList_1e8->SetColumnJustification(2, 0);
            noteList_1e8->color_16c = 0xff8aa3ff;
            noteList_1e8->field_15c = 1;
            noteList_1e8->field_154 = 1;
            noteList_1e8->field_158_guess = 0;
        }
        if (noteEdit_1ec != 0) {
            noteEdit_1ec->SetMaxChars(0x3f);
        }
        if (motdInput_1f8 != 0) {
            motdInput_1f8->SetMaxChars(0x3ff);
        }
        if (playerList_15c != 0) {
            playerList_15c->SetColors(-1, 0xffffff00, 0xff808080);
            playerList_15c->SetColumnJustification(0, 1);
            playerList_15c->SetColumnJustification(1, 0);
            playerList_15c->SetColumnJustification(2, 1);
            playerList_15c->SetColumnJustification(3, 0);
            playerList_15c->SetColumnJustification(4, 1);
            playerList_15c->SetColumnJustification(5, 0);
            playerList_15c->color_16c = 0xff8aa3ff;
            playerList_15c->field_15c = 1;
        }
        if (notInGroupList_164 != 0) {
            notInGroupList_164->SetColors(-1, 0xffffff00, 0xff808080);
            notInGroupList_164->SetColumnJustification(0, 1);
            notInGroupList_164->SetColumnJustification(1, 0);
            notInGroupList_164->SetColumnJustification(2, 1);
            notInGroupList_164->SetColumnJustification(3, 0);
            notInGroupList_164->SetColumnJustification(4, 1);
            notInGroupList_164->SetColumnJustification(5, 0);
            notInGroupList_164->color_16c = 0xff8aa3ff;
            notInGroupList_164->field_15c = 1;
        }
        field_28c = 0;
        field_240 = 0;
        ((ListOwner_guess*)this)->RegisterListLayouts_guess();
        ((RaidWindow_guess*)this)->InitializeClassColors_guess();
    }
}

// Dump button: writes the raid roster (group, name, level, class, rank, note per line) to `fileName`,
// or to RaidRoster-YYYYMMDD-HHMMSS.txt when none is given; the ungrouped list follows with group 0.
// FUNCTION: TITANIUM 0x0054F8FA
void CRaidWndView_guess::DumpRoster_guess(const char* fileName) {
    char stamp[0x100];
    char defaultName[0x200];
    if (fileName == 0 || *fileName == '\0') {
        time_t now = time(0);
        tm* local = localtime(&now);
        sprintf(stamp, "%04d%02d%02d-%02d%02d%02d", local->tm_year + 1900, local->tm_mon + 1,
                local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
        sprintf(defaultName, "RaidRoster-%s.txt", stamp);
        fileName = defaultName;
    }
    FILE* file = fopen(fileName, "w");
    if (file != 0) {
        int count = playerList_15c->ItemsCount;
        for (int i = 0; i < count; ++i) {
            Str_guess name = playerList_15c->GetItemText(i, 1);
            Str_guess empty(pStringTable->getString(0x1a2b, 0));
            int note = ((ListOwner_guess*)this)->FindNote_guess(name);
            Str_guess noteText;
            if (note != -1) {
                noteText = noteList_1e8->GetItemText(note, 2);
            }
            if (name.GetLength_guess() > 0 && name.Compare_guess(empty, 0) != 0) {
                fprintf(file, "%d\t%s\t%s\t%s\t%s\t%s\n", i / 6 + 1,
                        (char*)playerList_15c->GetItemText(i, 1),
                        (char*)playerList_15c->GetItemText(i, 2),
                        (char*)playerList_15c->GetItemText(i, 3),
                        (char*)playerList_15c->GetItemText(i, 5), (char*)noteText);
            }
        }
        count = notInGroupList_164->ItemsCount;
        for (int j = 0; j < count; ++j) {
            Str_guess name = notInGroupList_164->GetItemText(j, 1);
            if (name.GetLength_guess() > 0) {
                int note = ((ListOwner_guess*)this)->FindNote_guess(name);
                Str_guess noteText;
                if (note != -1) {
                    noteText = noteList_1e8->GetItemText(note, 2);
                }
                fprintf(file, "%d\t%s\t%s\t%s\t%s\t%s\n", 0,
                        (char*)notInGroupList_164->GetItemText(j, 1),
                        (char*)notInGroupList_164->GetItemText(j, 2),
                        (char*)notInGroupList_164->GetItemText(j, 3),
                        (char*)notInGroupList_164->GetItemText(j, 5), (char*)noteText);
            }
        }
        fclose(file);
    }
}

// Clears lists, notes and MOTD and lays out the 83-row grid: every member row "empty" (string 0x1A2B,
// grey) with its group number; the count label reads "0" (0x006410A8).
// FUNCTION: TITANIUM 0x0054FEC9
// @early-stop: budget, structural ndiff=49
void CRaidWndView_guess::Refresh_54FEC9_guess() {
    if (SidlPiece != 0) {
        Str_guess name;
        ((ListSlots_guess*)playerList_15c)->Slot4C_guess();
        ((ListSlots_guess*)notInGroupList_164)->Slot4C_guess();
        if (noteList_1e8 != 0) {
            ((ListSlots_guess*)noteList_1e8)->Slot4C_guess();
        }
        if (noteEdit_1ec != 0) {
            Str_guess text(EQ_ARRAY(char, 0x0063F53F));
            ((RaidControl_guess*)noteEdit_1ec)->Slot3F_guess(text);
        }
        if (motdViewer_1f4 != 0) {
            ((CStmlWndView_guess*)motdViewer_1f4)->SetSTMLText(
                Str_guess(EQ_ARRAY(char, 0x0063F53F)), 1, 0);
        }
        if (motdInput_1f8 != 0) {
            Str_guess text(EQ_ARRAY(char, 0x0063F53F));
            ((RaidControl_guess*)motdInput_1f8)->Slot3F_guess(text);
        }
        int group = 1;
        int column = 0;
        for (int i = 0; i < 0x53; ++i) {
            if (column == 6) {
                ((RaidWindow_guess*)this)->AddSeparatorRow_guess();
                ++group;
                column = 0;
            } else {
                playerList_15c->AddString(
                    Str_guess(EQ_ARRAY(char, 0x0063F53F)), -1, 0, 0);
                char number[20];
                __itoa(group, number, 10);
                name = number;
                playerList_15c->SetItemText(i, 0, name);
                {
                    Str_guess label(pStringTable->getString(0x1a2b, 0));
                    playerList_15c->SetItemText(i, 1, label);
                }
                playerList_15c->SetItemColor_guess(i, 1, 0xff808080);
                ++column;
            }
        }
        Str_guess text(EQ_ARRAY(char, 0x006410A8));
        ((RaidControl_guess*)playerCountLabel_16c)->Slot3F_guess(text);
    }
}

// Raid window: re-checks which buttons and fields are enabled (0x0054E316). The raid handlers call it
// when the raid is locked or unlocked, after the full raid update and when you form a new raid.
// FUNCTION: TITANIUM 0x0055011D
void CRaidWndView_guess::UpdateThunk_54E316_guess() {
    Update_54E316_guess();
}

// Raid window per frame: refreshes the window (0x0054E316) at most every 250 ms, then runs the base
// per-frame code (0x005A0E50).
// FUNCTION: TITANIUM 0x00550122
int CRaidWndView_guess::OnProcessFrame_guess() {
    if (SidlPiece == 0) {
        return 0;
    }
    int tick_guess = g_clientState_guess->tick_0148_guess;
    if (tick_guess - field_240 > 250) {
        Update_54E316_guess();
        field_240 = tick_guess;
    }
    return OnProcessFrame();
}

// WndNotification. 1 (click): each button calls its raid action; a click on any list row targets that
// member, and a note row also loads its note. RAID_Group1-12Button move the selected member there (leader
// only). 15 (header click) sorts the note list, flipping the order on a second click of the same column.
// FUNCTION: TITANIUM 0x00550163
int CRaidWndView_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                                         void* data_guess) {
    if (SidlPiece == 0) {
        return 0;
    }
    if (message_guess == 1) {
        if (sender_guess == dumpButton_194) {
            DumpRoster_guess(0);
            return 1;
        } else if (sender_guess == acceptButton_17c) {
            g_raidPanel_guess.RespondToInvite_guess(1);
            return 1;
        } else if (sender_guess == inviteButton_174) {
            g_raidPanel_guess.InviteToRaid_guess(0);
            return 1;
        } else if (sender_guess == declineButton_180) {
            g_raidPanel_guess.RespondToInvite_guess(0);
            return 1;
        } else if (sender_guess == disbandButton_178) {
            g_raidPanel_guess.RemoveSelectedOrLeave_guess();
            return 1;
        } else if (sender_guess == playerList_15c) {
            Str_guess text_guess = playerList_15c->GetItemText((int)data_guess, 1);
            g_raidPanel_guess.SetTargetRaidPlayer_guess(text_guess);
        } else if (sender_guess == noteList_1e8) {
            Str_guess text_guess = noteList_1e8->GetItemText((int)data_guess, 1);
            g_raidPanel_guess.SetTargetRaidPlayer_guess(text_guess);
            if (noteEdit_1ec != 0) {
                ((RaidControl_guess*)noteEdit_1ec)->Slot3F_guess(
                    noteList_1e8->GetItemText((int)data_guess, 2));
            }
        } else if (sender_guess == notInGroupList_164) {
            Str_guess text_guess = notInGroupList_164->GetItemText((int)data_guess, 1);
            g_raidPanel_guess.SetTargetRaidPlayer_guess(text_guess);
        } else if (sender_guess == makeLeaderButton_184) {
            g_raidPanel_guess.MakeLeader_guess(0);
        } else if (sender_guess == optionsButton_188) {
            if (pinstCRaidOptionsWnd_guess != 0) {
                pinstCRaidOptionsWnd_guess->Activate();
            }
        } else if (sender_guess == addLooterButton_18c) {
            g_raidPanel_guess.RequestAddLooter_guess();
        } else if (sender_guess == removeLooterButton_190) {
            g_raidPanel_guess.RequestRemoveLooter_guess();
        } else if (sender_guess == mainAssistButton_198) {
            if (g_raidDataController_guess != 0) {
                g_raidDataController_guess->SendRaidDelegateAbility_guess(
                    3, (char*)g_raidPanel_guess.GetSelectedMember_guess());
            }
        } else if (sender_guess == markNpcButton_19c) {
            if (g_raidDataController_guess != 0) {
                g_raidDataController_guess->SendRaidDelegateAbility_guess(
                    4, (char*)g_raidPanel_guess.GetSelectedMember_guess());
            }
        } else if (sender_guess == findPcButton_1a4) {
            if (g_raidDataController_guess != 0) {
                g_raidDataController_guess->FindPathToPlayer_guess(
                    (char*)g_raidPanel_guess.GetSelectedMember_guess());
            }
        } else if (sender_guess == updateMotdButton_1fc) {
            if (motdInput_1f8 != 0) {
                Str_guess text_guess = FUN_0060aca0_guess(
                    ((RaidControl_guess*)motdInput_1f8)->Slot4C_guess());
                g_raidPanel_guess.SendMotd_guess(text_guess);
            }
        } else if (sender_guess == noteUpdateButton_1f0) {
            if (noteEdit_1ec != 0 && noteList_1e8 != 0) {
                int index_guess = noteList_1e8->GetCurSel();
                if (index_guess != -1) {
                    g_raidPanel_guess.SendMemberNote_guess(
                        noteList_1e8->GetItemText(index_guess, 1),
                        ((RaidControl_guess*)noteEdit_1ec)->Slot4C_guess());
                }
            }
        } else if (sender_guess == lockButton_1a8) {
            if (g_raidPanel_guess.IsRaidLeader_guess() != 0 &&
                g_raidPanel_guess.IsLocked_guess() == 0) {
                g_raidPanel_guess.RequestLock_guess();
            }
        } else if (sender_guess == (CXWnd*)unlockButton_1ac) {
            if (g_raidPanel_guess.IsRaidLeader_guess() != 0 &&
                g_raidPanel_guess.IsLocked_guess() != 0) {
                g_raidPanel_guess.RequestUnlock_guess();
            }
        } else if (sender_guess == removeLeaderButton_1b0) {
            if (g_raidPanel_guess.IsRaidLeader_guess() != 0) {
                char* entry_guess = (char*)g_raidPanel_guess.GetSelectedMember_guess();
                if (entry_guess != 0) {
                    g_raidPanel_guess.Dispatch7_guess(entry_guess);
                }
            }
        } else if (sender_guess == noGroupButton_1b4) {
            if (g_raidPanel_guess.IsRaidLeader_guess() != 0) {
                char* entry_guess = (char*)g_raidPanel_guess.GetSelectedMember_guess();
                if (entry_guess != 0) {
                    g_raidPanel_guess.Dispatch6_guess(entry_guess, -1);
                }
            }
        } else {
            if (g_raidPanel_guess.IsRaidLeader_guess() != 0) {
                int index_guess = 0;
                CXWnd** button_guess = groupButtons_1b8;
                do {
                    if (sender_guess == *button_guess) {
                        char* entry_guess = (char*)g_raidPanel_guess.GetSelectedMember_guess();
                        if (entry_guess != 0) {
                            g_raidPanel_guess.Dispatch6_guess(entry_guess, index_guess);
                        }
                    }
                    ++index_guess;
                    ++button_guess;
                } while (index_guess < 12);
            }
        }
    } else if (message_guess == 2) {
        // nothing
    } else if (message_guess == 15) {
        if (sender_guess == noteList_1e8) {
            int* column_guess = &noteList_1e8->field_154;
            if (*column_guess == (int)data_guess) {
                unsigned char* ascending_guess = &noteList_1e8->field_158_guess;
                *ascending_guess = *ascending_guess == 0;
            } else {
                *column_guess = (int)data_guess;
                noteList_1e8->field_158_guess = 1;
            }
            ((RaidControl_guess*)noteList_1e8)->Slot4E_guess();
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}

// After a removal, moves the group's later members up a row and leaves the last one "empty".
// FUNCTION: TITANIUM 0x00550684
void CRaidWndView_guess::CloseGroupGap_guess(int first_guess, int group_guess) {
    Str_guess blank_guess;
    int limit_guess = group_guess * 7 + 5;
    for (int index_guess = first_guess; index_guess < limit_guess; ++index_guess) {
        int next_guess = index_guess + 1;
        playerList_15c->SetItemText(index_guess, 1, playerList_15c->GetItemText(next_guess, 1));
        playerList_15c->SetItemColor_guess(index_guess, 1, playerList_15c->GetItemColor_guess(next_guess, 1));
        playerList_15c->SetItemText(index_guess, 2, playerList_15c->GetItemText(next_guess, 2));
        playerList_15c->SetItemText(index_guess, 3, playerList_15c->GetItemText(next_guess, 3));
        playerList_15c->SetItemText(index_guess, 4, playerList_15c->GetItemText(next_guess, 4));
        playerList_15c->SetItemColor_guess(index_guess, 3, playerList_15c->GetItemColor_guess(next_guess, 3));
        playerList_15c->SetItemText(index_guess, 5, playerList_15c->GetItemText(next_guess, 5));
        {
            Str_guess placeholder_guess(pStringTable->getString(0x1a2b, 0));
            playerList_15c->SetItemText(next_guess, 1, placeholder_guess);
        }
        playerList_15c->SetItemColor_guess(next_guess, 1, 0xff808080);
        playerList_15c->SetItemText(next_guess, 2, blank_guess);
        playerList_15c->SetItemText(next_guess, 3, blank_guess);
        playerList_15c->SetItemText(next_guess, 4, blank_guess);
        playerList_15c->SetItemText(next_guess, 5, blank_guess);
    }
}

// First "empty" row of the group, or -1 when the group is full.
// FUNCTION: TITANIUM 0x00550901
int CRaidWndView_guess::FindEmptySlotInGroup_guess(int group_guess) {
    int index = group_guess * 7;
    int end = index + 6;
    while (index < end) {
        int matches;
        matches = playerList_15c->GetItemText(index, 1)
                      .Equals_guess(Str_guess(pStringTable->getString(0x1a2b, 0)));
        if (matches != 0) {
            return index;
        }
        ++index;
    }
    return -1;
}

// Row of `name_guess` within the group's six member rows, or -1.
// FUNCTION: TITANIUM 0x005509B8
int CRaidWndView_guess::FindPlayerIndexInGroup_guess(const char* name_guess, int group_guess) {
    Str_guess name(name_guess);
    int end;
    int index = group_guess * 7;
    end = index + 6;
    if (index < end) {
        do {
            int matches;
            matches = name.Equals_guess(
                playerList_15c->GetItemText(index, 1));
            if (matches != 0) {
                return index;
            }
            ++index;
        }
        while (index < end);
    }
    return -1;
}

// Adds a member: `key_guess` is the group index (-1 = not in a group). The parameters are misnamed:
// `rank_guess` is the rank text (column 5), `flags_guess` the flags (column 4), `note_guess` the note.
// A group leader takes the group's first row; whoever held it moves to the free row. With a note it also
// adds a note row ("%02d" group number, name, note).
// FUNCTION: TITANIUM 0x00550AAC
void CRaidWndView_guess::AddPlayer_guess(const char* rank_guess, const char* name_guess,
                                    const char* class_guess, const char* level_guess,
                                    const char* flags_guess, int key_guess, int classId_guess,
                                    unsigned char leaderFlag_guess, const char* note_guess) {
    if (SidlPiece == 0) {
        return;
    }
    Str_guess text;
    char number[12];
    number[0] = 0;
    if (key_guess == -1) {
        int row;
        {
            Str_guess blank(EQ_ARRAY(char, 0x0063F53F));
            row = notInGroupList_164->AddString(blank, -1, 0, 0);
        }
        text = name_guess;
        notInGroupList_164->SetItemText(row, 1, text);
        notInGroupList_164->SetItemColor_guess(row, 1, -1);
        text = level_guess;
        notInGroupList_164->SetItemText(row, 2, text);
        text = class_guess;
        notInGroupList_164->SetItemText(row, 3, text);
        text = flags_guess;
        notInGroupList_164->SetItemText(row, 4, text);
        text = rank_guess;
        notInGroupList_164->SetItemText(row, 5, text);
        ((RaidWindow_guess*)this)->SetRowClassColor_guess(row, classId_guess, key_guess);
    } else {
        _sprintf(number, "%02d", key_guess + 1);
        int slot = FindEmptySlotInGroup_guess(key_guess);
        if (slot == -1) {
            FUN_00574110_guess("CRaidWnd::AddPlayertoList, no spot found");
            return;
        }
        int base = key_guess * 7;
        if (leaderFlag_guess == 0 || slot == base) {
            text = name_guess;
            playerList_15c->SetItemText(slot, 1, text);
            playerList_15c->SetItemColor_guess(slot, 1, -1);
            text = level_guess;
            playerList_15c->SetItemText(slot, 2, text);
            text = class_guess;
            playerList_15c->SetItemText(slot, 3, text);
            text = flags_guess;
            playerList_15c->SetItemText(slot, 4, text);
            text = rank_guess;
            playerList_15c->SetItemText(slot, 5, text);
            ((RaidWindow_guess*)this)->SetRowClassColor_guess(slot, classId_guess, key_guess);
        } else {
            Str_guess oldName = playerList_15c->GetItemText(base, 1);
            Str_guess oldLevel = playerList_15c->GetItemText(base, 2);
            Str_guess oldClass = playerList_15c->GetItemText(base, 3);
            Str_guess oldEmpty = playerList_15c->GetItemText(base, 4);
            Str_guess oldLeader = playerList_15c->GetItemText(base, 5);
            int oldColor = playerList_15c->GetItemColor_guess(base, 3);
            text = name_guess;
            playerList_15c->SetItemText(base, 1, text);
            playerList_15c->SetItemColor_guess(base, 1, -1);
            text = level_guess;
            playerList_15c->SetItemText(base, 2, text);
            text = class_guess;
            playerList_15c->SetItemText(base, 3, text);
            text = flags_guess;
            playerList_15c->SetItemText(base, 4, text);
            text = rank_guess;
            playerList_15c->SetItemText(base, 5, text);
            playerList_15c->SetItemText(slot, 1, oldName);
            playerList_15c->SetItemColor_guess(slot, 1, -1);
            playerList_15c->SetItemText(slot, 2, oldLevel);
            playerList_15c->SetItemText(slot, 3, oldClass);
            playerList_15c->SetItemText(slot, 4, oldEmpty);
            playerList_15c->SetItemText(slot, 5, oldLeader);
            playerList_15c->SetItemColor_guess(slot, 3, oldColor);
            ((RaidWindow_guess*)this)->SetRowClassColor_guess(base, classId_guess, key_guess);
        }
    }
    if (note_guess != 0 && noteList_1e8 != 0) {
        int noteRow;
        {
            Str_guess number_text(number);
            noteRow = noteList_1e8->AddString(number_text, -1, 0, 0);
        }
        {
            Str_guess name_text(name_guess);
            noteList_1e8->SetItemText(noteRow, 1, name_text);
        }
        {
            Str_guess group_text(note_guess);
            noteList_1e8->SetItemText(noteRow, 2, group_text);
        }
    }
}

// Removes a member from either list and from the notes; grid rows close up behind it.
// FUNCTION: TITANIUM 0x00550FD4
void CRaidWndView_guess::RemovePlayerFromList_guess(const char* name_guess, int group_guess) {
    if (SidlPiece != 0) {
        Str_guess blank_guess;
        if (group_guess == -1) {
            int index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index != -1) {
                notInGroupList_164->RemoveLineThunk_guess(index);
            }
        } else {
            int index = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index != -1) {
                {
                    Str_guess placeholder_guess(pStringTable->getString(0x1a2b, 0));
                    playerList_15c->SetItemText(index, 1, placeholder_guess);
                }
                playerList_15c->SetItemColor_guess(index, 1, 0xff808080);
                playerList_15c->SetItemText(index, 2, blank_guess);
                playerList_15c->SetItemText(index, 3, blank_guess);
                playerList_15c->SetItemText(index, 4, blank_guess);
                playerList_15c->SetItemText(index, 5, blank_guess);
                CloseGroupGap_guess(index, group_guess);
            }
        }
        int note = ((ListOwner_guess*)this)->FindNote_guess(name_guess);
        if (note != -1) {
            noteList_1e8->RemoveLine(note);
        }
    }
}

// Column 4 flags: "A" for `first_guess`, "M" for `second_guess` (probably main assist and NPC marker).
// FUNCTION: TITANIUM 0x00551123
void CRaidWndView_guess::SetMemberFlagsText_guess(const char* name_guess, int group_guess, bool first_guess,
                                        bool second_guess, int unused_guess) {
    if (SidlPiece != 0) {
        Str_guess text(EQ_ARRAY(char, 0x0063F53F));
        if (first_guess) {
            text += EQ_ARRAY(char, 0x00641BA8);
        }
        if (second_guess) {
            text += EQ_ARRAY(char, 0x00641BA4);
        }
        if (group_guess == -1) {
            int index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index != -1) {
                notInGroupList_164->SetItemText(index, 4, text);
            }
        } else {
            int index = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index != -1) {
                playerList_15c->SetItemText(index, 4, text);
            }
        }
    }
}

// Column 5, the rank text (raid leader, group leader ...).
// FUNCTION: TITANIUM 0x005511DB
void CRaidWndView_guess::SetMemberRankText_guess(const char* name_guess, const char* leader_guess,
                                        int group_guess) {
    if (SidlPiece != 0) {
        Str_guess text;
        text = leader_guess;
        if (group_guess == -1) {
            int index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index != -1) {
                notInGroupList_164->SetItemText(index, 5, text);
            }
        } else {
            int index = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index != -1) {
                playerList_15c->SetItemText(index, 5, text);
            }
        }
    }
}

// Moves a member to group `key_guess`: removes and re-adds the row, keeping its texts and note.
// FUNCTION: TITANIUM 0x0055126C
void CRaidWndView_guess::ChangePosition(const char* name_guess, int group_guess, int key_guess,
                                         int classId_guess, unsigned char leaderFlag_guess) {
    if (SidlPiece != 0) {
        Str_guess name_text;
        Str_guess level_text;
        Str_guess class_text;
        Str_guess empty_text;
        Str_guess leader_text;
        Str_guess note_text;
        int index;
        if (group_guess == -1) {
            index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index != -1) {
                name_text = notInGroupList_164->GetItemText(index, 1);
                level_text = notInGroupList_164->GetItemText(index, 2);
                class_text = notInGroupList_164->GetItemText(index, 3);
                empty_text = notInGroupList_164->GetItemText(index, 4);
                leader_text = notInGroupList_164->GetItemText(index, 5);
            }
        } else {
            index = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index != -1) {
                name_text = playerList_15c->GetItemText(index, 1);
                level_text = playerList_15c->GetItemText(index, 2);
                class_text = playerList_15c->GetItemText(index, 3);
                empty_text = playerList_15c->GetItemText(index, 4);
                leader_text = playerList_15c->GetItemText(index, 5);
            }
        }
        int note = ((ListOwner_guess*)this)->FindNote_guess(name_guess);
        if (note != -1) {
            note_text = noteList_1e8->GetItemText(note, 2);
        }
        if (index != -1) {
            RemovePlayerFromList_guess(name_text, group_guess);
            AddPlayer_guess(leader_text, name_text, class_text, level_text, empty_text, key_guess,
                            classId_guess, leaderFlag_guess, note_text);
        } else {
            FUN_00574110_guess("CRaidWnd::ChangePosition - player not found, currGroup = %d , %s",
                               group_guess, name_guess);
        }
    }
}

// Swaps the new leader's row with the old leader's, or with the group's first row when there is none.
// FUNCTION: TITANIUM 0x0055160D
void CRaidWndView_guess::ChangeRaidGroupLeader(const char* newLeader, int group, const char* oldLeader) {
    int oldIndex = -1;
    int color;
    Str_guess name;
    Str_guess level;
    Str_guess className;
    Str_guess empty;
    Str_guess leader;
    int newIndex = FindPlayerIndexInGroup_guess(newLeader, group);
    if (oldLeader != 0) {
        oldIndex = FindPlayerIndexInGroup_guess(oldLeader, group);
    }
    // Columns 1-5 of both rows trade places (and column 3's colour); a missing new leader is only logged.
    if (newIndex != -1) {
        if (oldIndex != -1) {
            name = playerList_15c->GetItemText(oldIndex, 1);
            level = playerList_15c->GetItemText(oldIndex, 2);
            className = playerList_15c->GetItemText(oldIndex, 3);
            empty = playerList_15c->GetItemText(oldIndex, 4);
            leader = playerList_15c->GetItemText(oldIndex, 5);
            color = playerList_15c->GetItemColor_guess(oldIndex, 3);
            playerList_15c->SetItemText(oldIndex, 1, playerList_15c->GetItemText(newIndex, 1));
            playerList_15c->SetItemText(oldIndex, 2, playerList_15c->GetItemText(newIndex, 2));
            playerList_15c->SetItemText(oldIndex, 3, playerList_15c->GetItemText(newIndex, 3));
            playerList_15c->SetItemText(oldIndex, 4, playerList_15c->GetItemText(newIndex, 4));
            playerList_15c->SetItemText(oldIndex, 5, playerList_15c->GetItemText(newIndex, 5));
            playerList_15c->SetItemColor_guess(oldIndex, 3, playerList_15c->GetItemColor_guess(newIndex, 3));
            playerList_15c->SetItemText(newIndex, 1, name);
            playerList_15c->SetItemText(newIndex, 2, level);
            playerList_15c->SetItemText(newIndex, 3, className);
            playerList_15c->SetItemText(newIndex, 4, empty);
            playerList_15c->SetItemText(newIndex, 5, leader);
            playerList_15c->SetItemColor_guess(newIndex, 3, color);
        } else {
            int row = group * 7;
            Str_guess blank;
            if (row != newIndex) {
                name = playerList_15c->GetItemText(row, 1);
                level = playerList_15c->GetItemText(row, 2);
                className = playerList_15c->GetItemText(row, 3);
                empty = playerList_15c->GetItemText(row, 4);
                leader = playerList_15c->GetItemText(row, 5);
                color = playerList_15c->GetItemColor_guess(row, 3);
                playerList_15c->SetItemText(row, 1, playerList_15c->GetItemText(newIndex, 1));
                playerList_15c->SetItemText(row, 2, playerList_15c->GetItemText(newIndex, 2));
                playerList_15c->SetItemText(row, 3, playerList_15c->GetItemText(newIndex, 3));
                playerList_15c->SetItemText(row, 4, playerList_15c->GetItemText(newIndex, 4));
                playerList_15c->SetItemText(row, 5, playerList_15c->GetItemText(newIndex, 5));
                playerList_15c->SetItemColor_guess(row, 3, playerList_15c->GetItemColor_guess(newIndex, 3));
                playerList_15c->SetItemText(newIndex, 1, name);
                playerList_15c->SetItemText(newIndex, 2, level);
                playerList_15c->SetItemText(newIndex, 3, className);
                playerList_15c->SetItemText(newIndex, 4, empty);
                playerList_15c->SetItemColor_guess(newIndex, 3, color);
                playerList_15c->SetItemText(newIndex, 5, leader);
            }
        }
    } else {
        FUN_00574110_guess("CRaidWnd::ChangeRaidGroupLeader - new leader not found group# %d, newleader %s", group, newLeader);
    }
}

// Replaces the name column with `value_guess`.
// FUNCTION: TITANIUM 0x00551CBC
void CRaidWndView_guess::RenamePlayer_guess(const char* value_guess, const char* name_guess,
                                        int group_guess) {
    if (SidlPiece != 0) {
        Str_guess value_copy_guess(value_guess);
        Str_guess name_copy_guess(name_guess);
        if (group_guess == -1) {
            int index_guess = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index_guess != -1) {
                Str_guess value_guess_copy(value_guess);
                notInGroupList_164->SetItemText(index_guess, 1, value_guess_copy);
            }
        } else {
            int index_guess = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index_guess != -1) {
                Str_guess value_guess_copy(value_guess);
                playerList_15c->SetItemText(index_guess, 1, value_guess_copy);
            }
        }
    }
}

// Name colours: `name_guess` back to white, `leader_guess` red (0xFFFF0000).
// FUNCTION: TITANIUM 0x00551DCF
void CRaidWndView_guess::SetHighlight_guess(const char* leader_guess, int leaderGroup_guess,
                                       const char* name_guess, int group_guess) {
    if (name_guess != 0) {
        if (group_guess == -1) {
            int index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            if (index != -1) {
                notInGroupList_164->SetItemColor_guess(index, 1, -1);
            }
        } else {
            int index = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            if (index != -1) {
                playerList_15c->SetItemColor_guess(index, 1, -1);
            }
        }
    }
    if (leader_guess != 0) {
        if (leaderGroup_guess == -1) {
            int index = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(leader_guess);
            if (index != -1) {
                notInGroupList_164->SetItemColor_guess(index, 1, 0xffff0000);
            }
        } else {
            int index = FindPlayerIndexInGroup_guess(leader_guess, leaderGroup_guess);
            if (index != -1) {
                playerList_15c->SetItemColor_guess(index, 1, 0xffff0000);
            }
        }
    }
}

// Same mapping, by member name; logs when the name is not found.
// FUNCTION: TITANIUM 0x00551E5F
void CRaidWndView_guess::SetPlayerClassColor_guess(const char* name_guess, int classIndex_guess,
                                               int group_guess) {
    if (SidlPiece != 0) {
        int index_guess;
        RaidListWnd_guess* list_guess;
        if (group_guess == -1) {
            index_guess = ((RaidWindow_guess*)this)->FindIndexNotInGroupList_guess(name_guess);
            list_guess = notInGroupList_164;
        } else {
            index_guess = FindPlayerIndexInGroup_guess(name_guess, group_guess);
            list_guess = playerList_15c;
        }
        if (index_guess != -1) {
            int* colors_guess = ((RaidWindow_guess*)this)->classColors_guess;
            switch (classIndex_guess) {
            case 1:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[13]);
                break;
            case 2:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[2]);
                break;
            case 3:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[8]);
                break;
            case 5:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[11]);
                break;
            case 4:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[9]);
                break;
            case 6:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[3]);
                break;
            case 7:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[6]);
                break;
            case 8:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[0]);
                break;
            case 9:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[10]);
                break;
            case 10:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[12]);
                break;
            case 11:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[7]);
                break;
            case 12:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[14]);
                break;
            case 13:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[5]);
                break;
            case 14:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[4]);
                break;
            case 15:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[1]);
                break;
            case 16:
                list_guess->SetItemColor_guess(index_guess, 3, colors_guess[15]);
                break;
            }
        } else {
            FUN_00574110_guess("CRaidWnd::SetPlayerClassColor - player not found, %s", name_guess);
        }
    }
}
