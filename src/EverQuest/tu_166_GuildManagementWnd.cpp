// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 166: a hint from compare/tumap.py.
// CGuildMgmtWnd (SIDL "GuildManagementWnd"): the guild roster in three lists (members, notes, tribute),
// MOTD, rank buttons, banker flag and a list dump. Rows point at server member records (PointerArray_guess);
// personal notes live only on disk, in userdata\GN_<name>_<server>.txt. Ranks: 0 member, 1 officer, 2 leader.
#include "titanium/types.h"
#include "titanium/crt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "titanium/wnd/CTipWnd.h"

struct Entry_guess {
    char* data;
};

struct Record_guess {
    char unknown_000[0x10]; // 0x0
    char name_010[0x40]; // 0x10
    int value_050; // 0x50
    char unknown_054[4]; // 0x54
    int playerClass_0058_guess; // 0x58
    int value_05c; // 0x5c
    int value_060; // 0x60
    char text_064[0x100]; // 0x64
    char text_164[0x100]; // 0x164
    char flag_264; // 0x264
    char unknown_265[3]; // 0x265
    int value_268; // 0x268
    int value_26c; // 0x26c
};

struct Lookup_guess {
    // EXTERNAL: TITANIUM 0x00491E5B Lookup_guess::GetClassDesc
    const char* GetClassDesc(int value);
    // EXTERNAL: TITANIUM 0x00493B8F Lookup_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
};

#define g_lookup_guess EQ_GLOBAL(Lookup_guess*, 0x00988DF0)

// The spawn's guild id (EQPlayer +0x288) read through an inline getter (match shape).
struct GuildIdView_guess {
    int value_000; // 0x0
    int Get_guess() const { return value_000; }
};

struct Counted_guess {
    char unknown_000[0x12c];
    int count; // 0x12c
    int GetColumnCount_guess();
};

struct PersonalNote_guess;
struct Member_guess;

struct Buffer_guess {
    int count_0000_guess; // 0x0
    void* data; // 0x4
    int capacity_0008_guess; // 0x8
    void Release_guess();
    // EXTERNAL: TITANIUM 0x0050319B Buffer_guess::Insert_guess
    void Insert_guess(int index, struct Member_guess** value);
    // EXTERNAL: TITANIUM 0x00405492 Buffer_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    // EXTERNAL: TITANIUM 0x004EB924 Buffer_guess::Slot_guess
    PersonalNote_guess** Slot_guess(int index);
};

struct PersonalNote_guess {
    int timestamp_000; // 0x0
    unsigned int hash_004; // 0x4
    char name_008[0x40]; // 0x8
    char record_048[0x100]; // 0x48
};

struct ListLine_guess {
    // EXTERNAL: TITANIUM 0x0059C130 ListLine_guess::RemoveLineThunk_guess
    void RemoveLineThunk_guess(int index);
};

struct TextReceiver_guess;

struct Ini_guess {
    char unknown_000[0x18]; // 0x0
    int value_018; // 0x18 (Owner +0x158)
    int count_01c; // 0x1c (Owner +0x15c)
    char unknown_020[4]; // 0x20
    TextReceiver_guess* receiver_164; // 0x24 (Owner 0x164)
    int dumpButton_0028_guess; // 0x28 (Owner 0x168)
    // EXTERNAL: TITANIUM 0x00572300 Ini_guess::GetSection_guess
    const char* GetSection_guess();
};

struct MemberList_guess {
    char unknown_000[0x11c]; // 0x0
    int count_11c; // 0x11c
    char unknown_120[0xc]; // 0x120
    int columns_12c; // 0x12c
    // EXTERNAL: TITANIUM 0x00597BE0 MemberList_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 MemberList_guess::GetItemData
    int GetItemData(int index);
};

struct CXStrMatch_guess {
    // EXTERNAL: TITANIUM 0x00573B10 CXStrMatch_guess::Match_guess
    int Match_guess(const CXStr* key, int mode);
};

struct NoteRow_guess {
    char unknown_000[0x164]; // 0x0
    char flag_164; // 0x164
};

struct Temporary_guess {
    char* data_000; // 0x0
    // EXTERNAL: TITANIUM 0x00571D00 Temporary_guess::FreeRep
    void FreeRep(char* value);
    ~Temporary_guess() {
        if (data_000 != 0) {
            FreeRep(data_000);
        }
    }
};

struct TextReceiverBase_guess {
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
    virtual void Slot48_guess(bool flag, int value);
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
    virtual void Slot63_guess(Temporary_guess* value);
};

struct TextReceiver_guess : TextReceiverBase_guess {
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
};

struct ControlEntry_guess : TextReceiverBase_guess {
    virtual void Slot64_guess(int value);
    char unknown_004[0x108]; // 0x4
    int value_10c; // 0x10c
};

struct ListWndVCall_guess {
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

struct NameTable_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 NameTable_guess::Lookup_guess
    const char* Lookup_guess(int index);
    // EXTERNAL: TITANIUM 0x0040AE42 NameTable_guess::SendGuildBankerFlags_guess
    void SendGuildBankerFlags_guess(int value, int enabled, unsigned char state);
    // EXTERNAL: TITANIUM 0x0040AD67 NameTable_guess::SendGuildDemote_guess
    void SendGuildDemote_guess(int value);
    // EXTERNAL: TITANIUM 0x0040ACBF NameTable_guess::SendGuildPublicNote_guess
    void SendGuildPublicNote_guess(char* destination, const char* value);
    // EXTERNAL: TITANIUM 0x0040AB34 NameTable_guess::FUN_0040ab34_guess
    void FUN_0040ab34_guess(char* destination, int value);
};

#define g_guildList_guess EQ_GLOBAL(NameTable_guess, 0x00905D38)


// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct GuildMgmtBase_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005A3850 ??0GuildMgmtBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    GuildMgmtBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion,
                        char* blockName);
};

struct GuildListWnd_guess : CListWnd {
    char unknown_140[0x1c]; // 0x140
    bool flag_15c; // 0x15c
    char unknown_15d[0xf]; // 0x15d
    unsigned long color_16c; // 0x16c
};

struct GuildEditWnd_guess {
    // EXTERNAL: TITANIUM 0x004D7EBC GuildEditWnd_guess::SetMaxChars_guess
    void SetMaxChars_guess(int maxChars);
};

// EXTERNAL: TITANIUM 0x00655B68 ??_7GuildMgmtWnd_guess@@6B@
struct GuildMgmtWnd_guess : GuildMgmtBase_guess {
    virtual void Slot00_guess();
    char unknown_004[0x1c]; // 0x4
    int value_020; // 0x20
    int value_024; // 0x24
    char unknown_028[0x34]; // 0x28
    char enabled_05c; // 0x5c
    char unknown_05d[0xe3]; // 0x5d
    Ini_guess ini_140; // 0x140
    int membersList_16c; // 0x16c
    TextReceiver_guess* receiver_170; // 0x170
    TextReceiver_guess* receiver_174; // 0x174
    int updateMOTDButton_0178_guess; // 0x178
    CStmlWnd* stml_17c; // 0x17c
    int makeLeaderButton_0180_guess; // 0x180
    int promoteButton_0184_guess; // 0x184
    int demoteButton_0188_guess; // 0x188
    int removeButton_018c_guess; // 0x18c
    CButtonWnd* button_190; // 0x190
    int notesList_194; // 0x194
    TextReceiver_guess* receiver_198; // 0x198
    int updatePublicButton_019c_guess; // 0x19c
    TextReceiver_guess* receiver_1a0; // 0x1a0
    int updatePersonalButton_01a4_guess; // 0x1a4
    int tributeList_1a8; // 0x1a8
    int optOutButton_01ac_guess; // 0x1ac
    TextReceiver_guess* receiver_1b0; // 0x1b0
    int showOfflineButton_01b4_guess; // 0x1b4
    int subwindows_01b8_guess; // 0x1b8
    int tributePage_01bc_guess; // 0x1bc
    int sortKey_1c0; // 0x1c0
    char sortAscending_01c4_guess; // 0x1c4
    union {
        bool showOffline_1c5; // 0x1c5
        char showOfflineByte_1c5; // 0x1c5
    };
    char unknown_1c6[2]; // 0x1c6
    Buffer_guess buffer_1c8; // 0x1c8
    char unknown_1d4[4]; // 0x1d4
    int count_1d8; // 0x1d8
    int selectedMember_01dc_guess; // 0x1dc
    int playerRank_01e0_guess; // 0x1e0
    Buffer_guess buffer_1e4; // 0x1e4
    char valid_1f0; // 0x1f0
    char unknown_1f1[3]; // 0x1f1
    int count_1f4; // 0x1f4
    char filename_1f8[0x100]; // 0x1f8
    char unknown_2f8[0x100]; // 0x2f8
    char notesLoaded_03f8_guess; // 0x3f8
    char unknown_3f9[3]; // 0x3f9
    int value_3fc; // 0x3fc
    ControlEntry_guess* memberSlots_400[3]; // 0x400

    GuildMgmtWnd_guess(CXWnd* parent);
    ~GuildMgmtWnd_guess() ;
    void SetMOTD_guess(const char* first, const char* second);
    void SetPlayerCount_guess(int value);
    void BuildNotesFileName_guess();
    void RenameMember_guess(const char* name, const char* value);
    int FindMemberRow_guess(int value);
    bool UpdateGuildName_guess();
    GuildMgmtWnd_guess* Delete_guess(unsigned char flags);
    void LoadPersonalNotes_guess();
    // EXTERNAL: TITANIUM 0x005A3100 GuildMgmtWnd_guess::FUN_005a3100_guess
    void FUN_005a3100_guess();
    // EXTERNAL: TITANIUM 0x005A1EF0 GuildMgmtWnd_guess::FUN_005a1ef0_guess
    void FUN_005a1ef0_guess(int list, const char* name);
    // EXTERNAL: TITANIUM 0x005A1FE0 GuildMgmtWnd_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(int list, const char* name);

    void LoadSettings_guess();
    void SaveSettings_guess();
    void SavePersonalNotes_guess();
    void Clear_guess();
    void* FindPersonalNote_guess(const char* name);
    void RemoveMember_guess(int value);
    void OnShow_guess();
    void RefillLists_guess(char restoreSelection);
    void SortMembers_guess(int sortKey, char descending);
    void AddMember_guess(struct Member_guess* entry);
    void UpdateMemberRow_guess(struct Member_guess* entry, int row);
    void UpdateNoteRow_guess(struct Member_guess* entry, int row);
    void UpdateTributeRow_guess(struct Member_guess* entry, int row);
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
    void DumpList_guess(char* filename, const char* separator);
    void SetPersonalNote_guess(const char* key, const char* value);
    // EXTERNAL: TITANIUM 0x005A2230 GuildMgmtWnd_guess::FUN_005a2230_guess
    int FUN_005a2230_guess(CXWnd* sender, unsigned int message, void* data);
    void UpdateButtons_guess();
    // EXTERNAL: TITANIUM 0x005A1880 GuildMgmtWnd_guess::FUN_005a1880_guess
    void FUN_005a1880_guess();
};


// EXTERNAL: TITANIUM 0x0060D0D5 free_0060d0d5_guess
void __cdecl free_0060d0d5_guess(void* memory);

// EXTERNAL: TITANIUM 0x00574460 CompareData_guess
int __cdecl CompareData_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output, unsigned int id, const char* text,
    int zero1, int zero2, int zero3, int zero4, int zero5, int zero6, int zero7, int zero8);

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
    const char* defaultValue, char* value, int size, char useDefault);

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(Temporary_guess* destination, const char* source);

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* destination, int radix);

// Column count of a list window (+0x12C), at least 1.
// FUNCTION: TITANIUM 0x0050E2C3
int Counted_guess::GetColumnCount_guess() {
    int result = count;
    if (result < 1) {
        result = 1;
    }
    return result;
}

// Enables the buttons for the selected member (+0x1DC) by the player's own rank (+0x1E0): make leader,
// banker and demote (of an officer) for the leader; remove for a higher rank, or yourself to leave; opt-out
// for a tributer by an officer or the member; MOTD and the public note need officer; the note buttons
// also need a changed text. The Promote button is not touched (early-stop, unconfirmed).
// FUNCTION: TITANIUM 0x0050E2D2
// @early-stop: budget, diff ndiff=122
void GuildMgmtWnd_guess::UpdateButtons_guess() {
    if (ini_140.dumpButton_0028_guess != 0) {
        ((CXWnd*)ini_140.dumpButton_0028_guess)->Enabled =
            pinstLocalPlayer != 0 && pinstLocalPlayer->GuildID != -1;
    }
    bool selectedSame = false;
    bool flagE = false;
    bool flagF = false;
    bool flagD = false;
    bool flagG = false;
    if (selectedMember_01dc_guess != 0) {
        selectedSame = false;
        if (pinstLocalPlayer != 0 &&
            strcmp(pinstLocalPlayer->Name,
                   ((Record_guess*)selectedMember_01dc_guess)->name_010) == 0) {
            selectedSame = true;
        }
        int mode = playerRank_01e0_guess;
        flagG = mode == 2 && !selectedSame;
        int count = ((Record_guess*)selectedMember_01dc_guess)->value_05c;
        flagE = mode > count || (selectedSame && mode != 2);
        flagF = mode == 2 && count == 1;
        flagD = ((Record_guess*)selectedMember_01dc_guess)->flag_264 != 0 &&
                (mode > 0 || selectedSame);
        selectedSame = mode >= 2;
    }
    bool positive = playerRank_01e0_guess > 0;
    if (makeLeaderButton_0180_guess != 0) {
        ((CXWnd*)makeLeaderButton_0180_guess)->Enabled = flagG;
    }
    if (removeButton_018c_guess != 0) {
        ((CXWnd*)removeButton_018c_guess)->Enabled = flagE;
    }
    if (demoteButton_0188_guess != 0) {
        ((CXWnd*)demoteButton_0188_guess)->Enabled = flagF;
    }
    if (optOutButton_01ac_guess != 0) {
        ((CXWnd*)optOutButton_01ac_guess)->Enabled = flagD;
    }
    if (button_190 != 0) {
        button_190->Enabled = selectedSame;
    }
    if (receiver_174 != 0) {
        ((CXWnd*)receiver_174)->Enabled = positive;
        receiver_174->Slot48_guess(positive, 1);
        CXStr text = receiver_174->Slot76_guess();
    }
    if (updateMOTDButton_0178_guess != 0) {
        ((TextReceiverBase_guess*)updateMOTDButton_0178_guess)->Slot48_guess(positive, 1);
        ((CXWnd*)updateMOTDButton_0178_guess)->Enabled = positive;
    }
    if (stml_17c != 0) {
        ((TextReceiverBase_guess*)stml_17c)->Slot48_guess(!positive, 1);
    }
    bool changed = false;
    bool ran = false;
    if (selectedMember_01dc_guess != 0 && receiver_1a0 != 0) {
        CXStr text = receiver_1a0->Slot76_guess();
        changed = strcmp(text, ((Record_guess*)selectedMember_01dc_guess)->text_164) != 0;
        ran = true;
    }
    if (updatePersonalButton_01a4_guess != 0) {
        ((CXWnd*)updatePersonalButton_01a4_guess)->Enabled = changed;
    }
    if (receiver_1a0 != 0) {
        ((CXWnd*)receiver_1a0)->Enabled = ran;
    }
    changed = false;
    ran = false;
    if (selectedMember_01dc_guess != 0 && updatePublicButton_019c_guess != 0 && receiver_198 != 0) {
        ran = playerRank_01e0_guess > 0;
        if (ran) {
            CXStr text = receiver_198->Slot76_guess();
            changed = strcmp(text, ((Record_guess*)selectedMember_01dc_guess)->text_064) != 0;
        }
    }
    if (updatePublicButton_019c_guess != 0) {
        ((CXWnd*)updatePublicButton_019c_guess)->Enabled = changed;
    }
    if (receiver_198 != 0) {
        ((CXWnd*)receiver_198)->Enabled = ran;
    }
}

// EXTERNAL: TITANIUM 0x0060ACA0 FUN_0060aca0_guess
CXStr __cdecl FUN_0060aca0_guess(const CXStr& text);

// Shows MOTD `first` in the input and the STML viewer, and its author `second`.
// FUNCTION: TITANIUM 0x0050E5B5
void GuildMgmtWnd_guess::SetMOTD_guess(const char* first, const char* second) {
    if (receiver_174 != 0) {
        CXStr text(first);
        receiver_174->Slot63_guess((Temporary_guess*)&text);
    }
    if (stml_17c != 0) {
        CXStr out = FUN_0060aca0_guess(first);
        stml_17c->SetSTMLText(out, true, 0);
    }
    if (receiver_170 != 0) {
        CXStr text(second);
        receiver_170->Slot63_guess((Temporary_guess*)&text);
    }
}

// Shows `value` in the PlayerCount label.
// FUNCTION: TITANIUM 0x0050E6C2
void GuildMgmtWnd_guess::SetPlayerCount_guess(int value) {
    char text_020[16];
    Temporary_guess temporary_024 = { 0 };
    _itoa(value, text_020, 10);
    FUN_005738b0_guess(&temporary_024, text_020);
    if (receiver_1b0 != 0) {
        receiver_1b0->Slot63_guess(&temporary_024);
    }
}

// Personal-notes file name: .\userdata\GN_<player name>_<pEverQuest 0x493B8F, probably the server>.txt.
// FUNCTION: TITANIUM 0x0050E747
void GuildMgmtWnd_guess::BuildNotesFileName_guess() {
    char name_104[256];
    g_lookup_guess->GetServerShortName_guess(name_104);
    _sprintf_guess(filename_1f8, ".\\%s\\GN_%s_%s.txt", "userdata",
                   pinstLocalPlayer->Name, name_104);
}

// Renames member `name` to `value` in all three lists; the notes list also loses the personal note
// (column 2 and the record's +0x164).
// FUNCTION: TITANIUM 0x0050E7A3
void GuildMgmtWnd_guess::RenameMember_guess(const char* name, const char* value) {
    CXStr key(name);
    if (membersList_16c != 0) {
        int count = ((MemberList_guess*)membersList_16c)->count_11c;
        for (int index = 0; index < count; ++index) {
            CXStr item = ((CListWnd*)membersList_16c)->GetItemText(index, 0);
            if (((CXStrMatch_guess*)&item)->Match_guess(&key, 0) == 0) {
                ((CListWnd*)membersList_16c)->SetItemText(index, 0, value);
                break;
            }
        }
    }
    if (notesList_194 != 0) {
        int count = ((MemberList_guess*)notesList_194)->count_11c;
        for (int index = 0; index < count; ++index) {
            CXStr item = ((CListWnd*)notesList_194)->GetItemText(index, 0);
            if (((CXStrMatch_guess*)&item)->Match_guess(&key, 0) == 0) {
                ((CListWnd*)notesList_194)->SetItemText(index, 0, value);
                ((CListWnd*)notesList_194)->SetItemText(index, 2, EQ_ARRAY(char, 0x0063F53F));
                NoteRow_guess* row = (NoteRow_guess*)((CListWnd*)notesList_194)->GetItemData(index);
                if (row != 0) {
                    row->flag_164 = 0;
                }
                break;
            }
        }
    }
    if (tributeList_1a8 != 0) {
        int count = ((MemberList_guess*)tributeList_1a8)->count_11c;
        for (int index = 0; index < count; ++index) {
            CXStr item = ((CListWnd*)tributeList_1a8)->GetItemText(index, 0);
            if (((CXStrMatch_guess*)&item)->Match_guess(&key, 0) == 0) {
                ((CListWnd*)tributeList_1a8)->SetItemText(index, 0, value);
                break;
            }
        }
    }
}

// Members-list row of member `value`, or -1. The notes and tribute lists share its row order.
// FUNCTION: TITANIUM 0x0050EA43
int GuildMgmtWnd_guess::FindMemberRow_guess(int value) {
    int result = -1;
    if (membersList_16c != 0) {
        int count = ((MemberList_guess*)membersList_16c)->count_11c;
        for (int index = 0; index < count; ++index) {
            if (((MemberList_guess*)membersList_16c)->GetItemData(index) == value) {
                result = index;
                break;
            }
        }
    }
    return result;
}

// Shows the player's guild name (guild id +0x288, name from 0x905D38) in GuildName; blank without a guild.
// FUNCTION: TITANIUM 0x0050EA86
bool GuildMgmtWnd_guess::UpdateGuildName_guess() {
    if (ini_140.receiver_164 != 0 && pinstLocalPlayer != 0) {
        if (((GuildIdView_guess*)&pinstLocalPlayer->GuildID)->Get_guess() != -1) {
            CXStr text(g_guildList_guess.Lookup_guess(
                ((GuildIdView_guess*)&pinstLocalPlayer->GuildID)->Get_guess()));
            ini_140.receiver_164->Slot63_guess((Temporary_guess*)&text);
        } else {
            CXStr text(EQ_ARRAY(char, 0x0063F53F));
            ini_140.receiver_164->Slot63_guess((Temporary_guess*)&text);
        }
    }
    return true;
}

// qsort comparators for sort keys 0-10, each with a reversed twin; ties fall back to the name. Those
// declared void return nothing in C++ but leave the compare result in eax, which qsort reads: match shape.
// Name (+0x10).
// FUNCTION: TITANIUM 0x0050EBB6
int __cdecl Fallback_guess(Entry_guess* first, Entry_guess* second) {
    const char* firstData = first->data;
    const char* secondData = second->data;
    return CompareData_guess(firstData + 16, secondData + 16);
}

typedef int (__cdecl *SortCompare_guess)(const void*, const void*);

// Name, reversed.
// FUNCTION: TITANIUM 0x0050EBD2
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberNameReverse_guess(Entry_guess* first, Entry_guess* second) {
    return Fallback_guess(second, first);
}

// Level (+0x50).
// FUNCTION: TITANIUM 0x0050EBE4
int __cdecl CompareMemberLevel_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->value_050 == secondData->value_050) {
        return Fallback_guess(first, second);
    }
    int difference = firstData->value_050 - secondData->value_050;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Level, reversed.
// FUNCTION: TITANIUM 0x0050EC1D
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberLevelReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberLevel_guess(second, first);
}

// Class name (class +0x58).
// FUNCTION: TITANIUM 0x0050EC2F
void __cdecl CompareMemberClass_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->playerClass_0058_guess == secondData->playerClass_0058_guess) {
        Fallback_guess(first, second);
    } else {
        CompareData_guess(g_lookup_guess->GetClassDesc(firstData->playerClass_0058_guess),
                          g_lookup_guess->GetClassDesc(secondData->playerClass_0058_guess));
    }
}

// Class, reversed.
// FUNCTION: TITANIUM 0x0050EC72
// @early-stop: budget, structural ndiff=3
void __cdecl CompareMemberClassReverse_guess(Entry_guess* first, Entry_guess* second) {
    CompareMemberClass_guess(second, first);
}

// Rank (+0x5C).
// FUNCTION: TITANIUM 0x0050EC84
int __cdecl CompareMemberRank_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->value_05c == secondData->value_05c) {
        return Fallback_guess(first, second);
    }
    int difference = firstData->value_05c - secondData->value_05c;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Rank, reversed.
// FUNCTION: TITANIUM 0x0050ECBD
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberRankReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberRank_guess(second, first);
}

// Last on (+0x60, a time_t).
// FUNCTION: TITANIUM 0x0050ECCF
int __cdecl CompareMemberLastOn_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->value_060 == secondData->value_060) {
        return Fallback_guess(first, second);
    }
    int difference = firstData->value_060 - secondData->value_060;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Last on, reversed.
// FUNCTION: TITANIUM 0x0050ED08
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberLastOnReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberLastOn_guess(second, first);
}

// Public note (+0x64).
// FUNCTION: TITANIUM 0x0050ED1A
void __cdecl CompareMemberPublicNote_guess(Entry_guess* first, Entry_guess* second) {
    const char* firstData = first->data;
    const char* secondData = second->data;
    if (CompareData_guess(firstData + 100, secondData + 100) == 0) {
        Fallback_guess(first, second);
    }
}

// Public note, reversed.
// FUNCTION: TITANIUM 0x0050ED47
// @early-stop: budget, structural ndiff=3
void __cdecl CompareMemberPublicNoteReverse_guess(Entry_guess* first, Entry_guess* second) {
    CompareMemberPublicNote_guess(second, first);
}

// Personal note (+0x164).
// FUNCTION: TITANIUM 0x0050ED59
void __cdecl CompareMemberPersonalNote_guess(Entry_guess* first, Entry_guess* second) {
    const char* firstData = first->data;
    const char* secondData = second->data;
    if (CompareData_guess(firstData + 0x164, secondData + 0x164) == 0) {
        Fallback_guess(first, second);
    }
}

// Personal note, reversed.
// FUNCTION: TITANIUM 0x0050ED8B
// @early-stop: budget, structural ndiff=3
void __cdecl CompareMemberPersonalNoteReverse_guess(Entry_guess* first, Entry_guess* second) {
    CompareMemberPersonalNote_guess(second, first);
}

// Tribute on (+0x264).
// FUNCTION: TITANIUM 0x0050EE33
int __cdecl CompareMemberTributeFlag_guess(Entry_guess* first, Entry_guess* second) {
    char firstFlag = first->data[0x264];
    return firstFlag == second->data[0x264]
        ? Fallback_guess(first, second)
        : (firstFlag != 0 ? 1 : -1);
}

// Tribute on, reversed.
// FUNCTION: TITANIUM 0x0050EE67
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberTributeFlagReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberTributeFlag_guess(second, first);
}

// Tribute total (+0x268).
// FUNCTION: TITANIUM 0x0050EE79
int __cdecl CompareMemberTributeTotal_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->value_268 == secondData->value_268) {
        return Fallback_guess(first, second);
    }
    int difference = firstData->value_268 - secondData->value_268;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Tribute total, reversed.
// FUNCTION: TITANIUM 0x0050EEB8
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberTributeTotalReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberTributeTotal_guess(second, first);
}

// Last tribute (+0x26C, a time_t).
// FUNCTION: TITANIUM 0x0050EECA
int __cdecl CompareMemberLastDonation_guess(Entry_guess* first, Entry_guess* second) {
    Record_guess* firstData = (Record_guess*)first->data;
    Record_guess* secondData = (Record_guess*)second->data;
    if (firstData->value_26c == secondData->value_26c) {
        return Fallback_guess(first, second);
    }
    int difference = firstData->value_26c - secondData->value_26c;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Last tribute, reversed.
// FUNCTION: TITANIUM 0x0050EF09
// @early-stop: budget, structural ndiff=3
int __cdecl CompareMemberLastDonationReverse_guess(Entry_guess* first, Entry_guess* second) {
    return CompareMemberLastDonation_guess(second, first);
}

// Dump button: writes every row (members columns, then tribute and notes columns, joined by `separator`)
// to `filename`, by default "<guild>-YYYYMMDD-HHMMSS.txt", and prints string 0xC74 with the name.
// FUNCTION: TITANIUM 0x0050EF1B
// @early-stop: budget, structural ndiff=85
void GuildMgmtWnd_guess::DumpList_guess(char* filename, const char* separator) {
    int selection = pinstLocalPlayer->GuildID;
    if (selection != -1) {
        if (filename == 0 || *filename == 0) {
            time_t now = time(0);
            tm* local = localtime(&now);
            char stamp[0x100];
            _sprintf_guess(stamp, "%04d%02d%02d-%02d%02d%02d", local->tm_year + 1900,
                           local->tm_mon + 1, local->tm_mday, local->tm_hour,
                           local->tm_min, local->tm_sec);
            char prefix[0x4c];
            strcpy(prefix, g_guildList_guess.Lookup_guess(selection));
            char name[0x200];
            _sprintf_guess(name, "%s-%s.txt", prefix, stamp);
            filename = name;
        }
        char message[0x400];
        FUN_0046da4a_guess(message, 0xc74, filename, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message);
        if (membersList_16c != 0) {
            FILE* file = fopen(filename, "wt");
            if (file != 0) {
                int rows = ((MemberList_guess*)membersList_16c)->count_11c;
                for (int row = 0; row < rows; ++row) {
                    int cols = ((MemberList_guess*)membersList_16c)->columns_12c;
                    if (cols < 1) {
                        cols = 1;
                    }
                    for (int col = 0; col < cols - 1; ++col) {
                        fprintf(file, "%s", (char*)((CListWnd*)membersList_16c)->GetItemText(row, col));
                        if (col < cols - 2) {
                            fprintf(file, "%s", separator);
                        }
                    }
                    if (tributeList_1a8 != 0 && memberSlots_400[2] != 0) {
                        fprintf(file, "%s", separator);
                        cols = ((MemberList_guess*)tributeList_1a8)->columns_12c;
                        if (cols < 1) {
                            cols = 1;
                        }
                        for (int col = 1; col < cols; ++col) {
                            fprintf(file, "%s", (char*)((CListWnd*)tributeList_1a8)->GetItemText(row, col));
                            if (col < cols - 1) {
                                fprintf(file, "%s", separator);
                            }
                        }
                    }
                    if (notesList_194 != 0) {
                        fprintf(file, "%s", separator);
                        cols = ((MemberList_guess*)notesList_194)->columns_12c;
                        if (cols < 1) {
                            cols = 1;
                        }
                        for (int col = 1; col < cols; ++col) {
                            fprintf(file, "%s", (char*)((CListWnd*)notesList_194)->GetItemText(row, col));
                            if (col < cols - 1) {
                                fprintf(file, "%s", separator);
                            }
                        }
                    }
                    fprintf(file, "\n");
                }
                fclose(file);
            }
        }
    }
}

struct NamedRecord_guess {
    int unknown_000; // 0x0
    char hasName_004; // 0x4
    int nameId_008; // 0x8
};

struct NameService_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 NameService_guess::GetName_guess
    void GetName_guess(int id, char* output, int flag);
};

#define g_zoneList_guess EQ_GLOBAL(NameService_guess*, 0x00905CC0)

// Zone name (zone id +0x8, only while online +0x4); comparator for key 5.
// FUNCTION: TITANIUM 0x0050ED9D
void __cdecl CompareMemberZone_guess(Entry_guess* first, Entry_guess* second) {
    char firstName[512];
    char secondName[512];
    NamedRecord_guess* firstData = (NamedRecord_guess*)first->data;
    NamedRecord_guess* secondData = (NamedRecord_guess*)second->data;
    firstName[0] = 0;
    if (firstData->hasName_004 != 0) {
        g_zoneList_guess->GetName_guess(firstData->nameId_008, firstName, 1);
    }
    secondName[0] = 0;
    if (secondData->hasName_004 != 0) {
        g_zoneList_guess->GetName_guess(secondData->nameId_008, secondName, 1);
    }
    CompareData_guess(firstName, secondName);
}

// Zone, reversed.
// FUNCTION: TITANIUM 0x0050EE21
// @early-stop: budget, structural ndiff=3
void __cdecl CompareMemberZoneReverse_guess(Entry_guess* first, Entry_guess* second) {
    CompareMemberZone_guess(second, first);
}

// Loads ShowOffline (default 1) and the three lists' column layouts from the window's ini section.
// FUNCTION: TITANIUM 0x0050F2E1
void GuildMgmtWnd_guess::LoadSettings_guess() {
    char defaultValue[256];
    char value[256];
    _sprintf_guess(defaultValue, "1");
    LoadStringFromUIIniFile_guess(ini_140.GetSection_guess(), "ShowOffline", defaultValue,
                       value, 0xff, 1);
    showOffline_1c5 = (value[0] == '1' || value[0] == 't' || value[0] == 'T');
    if (membersList_16c != 0) {
        FUN_005a1ef0_guess(membersList_16c, "MembersList");
    }
    if (notesList_194 != 0) {
        FUN_005a1ef0_guess(notesList_194, "NotesList");
    }
    if (tributeList_1a8 != 0) {
        FUN_005a1ef0_guess(tributeList_1a8, "TributeList");
    }
}

// Saves the three lists' column layouts.
// FUNCTION: TITANIUM 0x0050F3AE
void GuildMgmtWnd_guess::SaveSettings_guess() {
    if (membersList_16c != 0) {
        StoreIniListWnd_guess(membersList_16c, "MembersList");
    }
    if (notesList_194 != 0) {
        StoreIniListWnd_guess(notesList_194, "NotesList");
    }
    if (tributeList_1a8 != 0) {
        StoreIniListWnd_guess(tributeList_1a8, "TributeList");
    }
}

// EXTERNAL: TITANIUM 0x0060D682 _free
void __cdecl _free(void* memory);

// EXTERNAL: TITANIUM 0x00574890 FUN_00574890_guess
unsigned int __cdecl FUN_00574890_guess(const char* text);

// EXTERNAL: TITANIUM 0x00574A30 FUN_00574a30_guess
void __cdecl FUN_00574a30_guess(char* text, int size);

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

// Frees the pointer array and zeroes it (the roster at +0x1C8, the notes at +0x1E4).
// FUNCTION: TITANIUM 0x0050F3F6
void Buffer_guess::Release_guess() {
    if (data != 0) {
        _free(data);
    }
    data = 0;
    capacity_0008_guess = 0;
    count_0000_guess = 0;
}

// Writes the personal notes as "time name note" lines, once they have been loaded (+0x3F8).
// FUNCTION: TITANIUM 0x0050F414
void GuildMgmtWnd_guess::SavePersonalNotes_guess() {
    if (notesLoaded_03f8_guess != 0) {
        int count = buffer_1e4.count_0000_guess;
        if (filename_1f8[0] == 0) {
            BuildNotesFileName_guess();
        }
        FILE* file = fopen(filename_1f8, "wt");
        if (file != 0) {
            for (int index = 0; index < count; ++index) {
                PersonalNote_guess* entry = *buffer_1e4.Slot_guess(index);
                fprintf(file, "%08X %s %s\n", entry->timestamp_000,
                        entry->name_008, &entry->record_048);
            }
            fclose(file);
        }
    }
}

// Personal note of member `name`, matched by name hash only; refreshes its time stamp. 0 if none.
// FUNCTION: TITANIUM 0x0050F485
void* GuildMgmtWnd_guess::FindPersonalNote_guess(const char* name) {
    unsigned int hash = FUN_00574890_guess(name);
    int index = 0;
    if (count_1f4 > 0) {
        do {
            PersonalNote_guess* entry = *buffer_1e4.Slot_guess(index);
            if (entry->hash_004 == hash) {
                entry->timestamp_000 = FUN_00576e80_guess();
                return &entry->record_048;
            }
            ++index;
        } while (index < count_1f4);
    }
    return 0;
}

// Removes member `value` from the roster and its row from all three lists; drops the selection if it
// was the selected member.
// FUNCTION: TITANIUM 0x0050F4D2
void GuildMgmtWnd_guess::RemoveMember_guess(int value) {
    if (value == selectedMember_01dc_guess) {
        selectedMember_01dc_guess = 0;
        if (membersList_16c != 0) {
            ((CListWnd*)membersList_16c)->ClearAllSel();
        }
        if (notesList_194 != 0) {
            ((CListWnd*)notesList_194)->ClearAllSel();
        }
        if (tributeList_1a8 != 0) {
            ((CListWnd*)tributeList_1a8)->ClearAllSel();
        }
    }
    int index = 0;
    if (count_1d8 > 0) {
        do {
            int* slot = (int*)buffer_1c8.Slot_guess(index);
            ++index;
            if (*slot == value) {
                for (; index < count_1d8; ++index) {
                    int* source = (int*)buffer_1c8.Slot_guess(index);
                    *(int*)buffer_1c8.Slot_guess(index - 1) = *source;
                }
                --count_1d8;
                break;
            }
        } while (index < count_1d8);
    }
    int removed = -1;
    if (membersList_16c != 0) {
        removed = FindMemberRow_guess(value);
        if (removed >= 0) {
            ((ListLine_guess*)membersList_16c)->RemoveLineThunk_guess(removed);
        }
    }
    if (notesList_194 != 0 && removed >= 0) {
        ((ListLine_guess*)notesList_194)->RemoveLineThunk_guess(removed);
    }
    if (tributeList_1a8 != 0 && removed >= 0) {
        ((ListLine_guess*)tributeList_1a8)->RemoveLineThunk_guess(removed);
    }
    UpdateButtons_guess();
}

struct Member_guess {
    int unknown_000; // 0x0
    char online_004; // 0x4
    char unknown_005[3]; // 0x5
    int zoneId_0008_guess; // 0x8
    char unknown_00c[4]; // 0xc
    char name_010[0x40]; // 0x10
    int level_0050_guess; // 0x50
    int flags_0054_guess; // 0x54
    int classId_0058_guess; // 0x58
    int rank_005c_guess; // 0x5c
    time_t time_060; // 0x60
    char publicNote_0064_guess[0x100]; // 0x64
    char personalNote_0164_guess[0x100]; // 0x164
    char tributeOn_0264_guess; // 0x264
    char unknown_265[3]; // 0x265
    int tributeTotal_0268_guess; // 0x268
    time_t lastTribute_026c_guess; // 0x26c
    char flag_270; // 0x270
};

struct ListColor_guess {
    // EXTERNAL: TITANIUM 0x0059B3E0 ListColor_guess::SetItemColor_guess
    void SetItemColor_guess(int row, int column, unsigned long color);
};

// Notes-list row: public and personal note; offline rows grey (0xFFC0C0C0), hidden without ShowOffline.
// FUNCTION: TITANIUM 0x0050F9D2
void GuildMgmtWnd_guess::UpdateNoteRow_guess(Member_guess* entry, int row) {
    if (notesList_194 == 0) {
        return;
    }
    if (row == -1) {
        row = FindMemberRow_guess((int)entry);
        if (row == -1) {
            if (entry->online_004 != 1 && !showOffline_1c5) {
                return;
            }
            row = ((CListWnd*)notesList_194)->AddString(entry->name_010, 0xffffffff,
                                                        (unsigned int)entry, 0);
            if (row == -1) {
                return;
            }
        }
    }
    if (entry->online_004 == 0 && !showOffline_1c5) {
        ((ListLine_guess*)notesList_194)->RemoveLineThunk_guess(row);
        return;
    }
    ((CListWnd*)((ListColor_guess*)notesList_194))->SetItemText(row, 1, entry->publicNote_0064_guess);
    ((CListWnd*)((ListColor_guess*)notesList_194))->SetItemText(row, 2, entry->personalNote_0164_guess);
    if (pinstLocalPlayer != 0 &&
        strcmp(pinstLocalPlayer->Name, entry->name_010) == 0) {
        playerRank_01e0_guess = entry->rank_005c_guess;
    }
    for (int column = 0; column < 2; ++column) {
        ((ListColor_guess*)notesList_194)->SetItemColor_guess(row, column,
            entry->online_004 != 0 ? 0xffffffff : 0xffc0c0c0);
    }
    UpdateButtons_guess();
}

// Members-list row: level, class, rank name (table 0x792AA4) plus a suffix per set flag bit (0x792AB0),
// last-on date, zone (string 0xC32 for zone id -1, blank offline) and public note; offline rows grey.
// `row` -1 looks the member up and adds it if shown. Also picks up the player's own rank (+0x1E0).
// FUNCTION: TITANIUM 0x0050F5CC
void GuildMgmtWnd_guess::UpdateMemberRow_guess(Member_guess* entry, int row) {
    char buf[512];
    if (membersList_16c == 0) {
        return;
    }
    if (row == -1) {
        row = FindMemberRow_guess((int)entry);
        if (row == -1) {
            if (entry->online_004 != 1 && !showOffline_1c5) {
                return;
            }
            row = ((CListWnd*)membersList_16c)->AddString(
                entry->name_010, 0xffffffff, (unsigned int)entry, 0);
            if (row == -1) {
                return;
            }
        }
    }
    if (entry->online_004 == 0 && !showOffline_1c5) {
        ((ListLine_guess*)membersList_16c)->RemoveLineThunk_guess(row);
        return;
    }
    {
        _sprintf_guess(buf, "%d", entry->level_0050_guess);
        CXStr text(buf);
        ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 1, text);
    }
    {
        CXStr text(g_lookup_guess->GetClassDesc(entry->classId_0058_guess));
        ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 2, text);
    }
    CXStr flags(EQ_ARRAY(const char*, 0x00792AA4)[entry->rank_005c_guess]);
    for (int bit = 0; bit < 32; ++bit) {
        if ((entry->flags_0054_guess & (1 << bit)) != 0) {
            flags += EQ_ARRAY(const char*, 0x00792AB0)[bit];
        }
    }
    ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 3, flags);
    time_t when = entry->time_060;
    if (when != 0) {
        tm* local = localtime(&when);
        if (local != 0) {
            _sprintf_guess(buf, "%02d/%02d/%02d", local->tm_mon + 1, local->tm_mday,
                           local->tm_year % 100);
            CXStr text(buf);
            ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 4, text);
        }
    } else {
        CXStr text(EQ_ARRAY(char, 0x0063F53F));
        ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 4, text);
    }
    buf[0] = 0;
    if (entry->online_004 != 0) {
        if (entry->zoneId_0008_guess == -1) {
            strcpy(buf, pStringTable->getString(0xc32, 0));
        } else {
            g_zoneList_guess->GetName_guess(entry->zoneId_0008_guess, buf, 1);
        }
    }
    {
        CXStr text(buf);
        ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 5, text);
    }
    {
        CXStr text(entry->publicNote_0064_guess);
        ((CListWnd*)((ListColor_guess*)membersList_16c))->SetItemText(row, 6, text);
    }
    if (pinstLocalPlayer != 0 &&
        strcmp(pinstLocalPlayer->Name, entry->name_010) == 0) {
        playerRank_01e0_guess = entry->rank_005c_guess;
    }
    for (int column = 0; column < 6; ++column) {
        ((ListColor_guess*)membersList_16c)->SetItemColor_guess(row, column,
            entry->online_004 != 0 ? 0xffffffff : 0xffc0c0c0);
    }
    UpdateButtons_guess();
}

// EXTERNAL: TITANIUM 0x00612227 localtime
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// Tribute-list row: on/off (strings 0x3292 / 0x3293, yellow while +0x270 is clear), total and the last
// tribute date.
// FUNCTION: TITANIUM 0x0050FB61
void GuildMgmtWnd_guess::UpdateTributeRow_guess(Member_guess* entry, int row) {
    char date[512];
    if (tributeList_1a8 == 0) {
        return;
    }
    if (row == -1) {
        row = FindMemberRow_guess((int)entry);
        if (row == -1) {
            if (entry->online_004 != 1 && !showOffline_1c5) {
                return;
            }
            row = ((CListWnd*)tributeList_1a8)->AddString(entry->name_010, 0xffffffff,
                                                          (unsigned int)entry, 0);
            if (row == -1) {
                return;
            }
        }
    }
    if (entry->online_004 == 0 && !showOffline_1c5) {
        ((ListLine_guess*)tributeList_1a8)->RemoveLineThunk_guess(row);
        return;
    }
    ((CListWnd*)((ListColor_guess*)tributeList_1a8))->SetItemText(row, 1,
        pStringTable->getString(0x3292 + (entry->tributeOn_0264_guess != 0), 0));
    ((CListWnd*)((ListColor_guess*)tributeList_1a8))->SetItemText(row, 2,
        _itoa(entry->tributeTotal_0268_guess, g_itoaBuffer_guess, 10));
    time_t when = entry->lastTribute_026c_guess;
    if (when != 0) {
        tm* local = localtime(&when);
        if (local != 0) {
            _sprintf_guess(date, "%02d/%02d/%02d", local->tm_mon + 1, local->tm_mday,
                           local->tm_year % 100);
            ((CListWnd*)((ListColor_guess*)tributeList_1a8))->SetItemText(row, 3, date);
        }
    } else {
        ((CListWnd*)((ListColor_guess*)tributeList_1a8))->SetItemText(row, 3, g_emptyString_guess);
    }
    ((ListColor_guess*)tributeList_1a8)->SetItemColor_guess(row, 0,
        entry->online_004 != 0 ? 0xffffffff : 0xffc0c0c0);
    ((ListColor_guess*)tributeList_1a8)->SetItemColor_guess(row, 1,
        entry->flag_270 != 0 ? 0xffffffff : 0xffffff00);
    ((ListColor_guess*)tributeList_1a8)->SetItemColor_guess(row, 2,
        entry->online_004 != 0 ? 0xffffffff : 0xffc0c0c0);
    ((ListColor_guess*)tributeList_1a8)->SetItemColor_guess(row, 3,
        entry->online_004 != 0 ? 0xffffffff : 0xffc0c0c0);
    UpdateButtons_guess();
}

// OnShow (vtable slot 35): on show, context tip 13 in the tip window (0x9928E0); on hide, saves the column
// layouts (0x0050F3AE); then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x0050FE6D
void GuildMgmtWnd_guess::OnShow_guess() {
    if (enabled_05c != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0xd, 0);
        }
    } else {
        SaveSettings_guess();
    }
    return FUN_005a1880_guess();
}

// Refills all three lists from the roster (online members, or all with ShowOffline), keeping the selected
// member when `restoreSelection`.
// FUNCTION: TITANIUM 0x0050FE9A
void GuildMgmtWnd_guess::RefillLists_guess(char restoreSelection) {
    int selected = -1;
    int index;
    if (membersList_16c != 0) {
        if (restoreSelection != 0) {
            selected = ((CListWnd*)membersList_16c)->GetItemData(
                ((CListWnd*)membersList_16c)->GetCurSel());
        }
        ((ListWndVCall_guess*)membersList_16c)->Slot76_guess();
        for (index = 0; index < count_1d8; ++index) {
            if (((Member_guess*)*buffer_1c8.Slot_guess(index))->online_004 == 1 ||
                showOffline_1c5) {
                int row = ((CListWnd*)membersList_16c)->AddString(
                    ((Member_guess*)*buffer_1c8.Slot_guess(index))->name_010,
                    0xffffffff, (unsigned int)*buffer_1c8.Slot_guess(index), 0);
                UpdateMemberRow_guess((Member_guess*)*buffer_1c8.Slot_guess(index), row);
                if (*(int*)buffer_1c8.Slot_guess(index) == selected) {
                    ((CListWnd*)membersList_16c)->SetCurSel(row);
                }
            }
        }
    }
    if (notesList_194 != 0) {
        if (restoreSelection != 0) {
            selected = ((CListWnd*)notesList_194)->GetItemData(
                ((CListWnd*)notesList_194)->GetCurSel());
        }
        ((ListWndVCall_guess*)notesList_194)->Slot76_guess();
        for (index = 0; index < count_1d8; ++index) {
            if (((Member_guess*)*buffer_1c8.Slot_guess(index))->online_004 == 1 ||
                showOffline_1c5) {
                int row = ((CListWnd*)notesList_194)->AddString(
                    ((Member_guess*)*buffer_1c8.Slot_guess(index))->name_010,
                    0xffffffff, (unsigned int)*buffer_1c8.Slot_guess(index), 0);
                UpdateNoteRow_guess((Member_guess*)*buffer_1c8.Slot_guess(index), row);
                if (*(int*)buffer_1c8.Slot_guess(index) == selected) {
                    ((CListWnd*)notesList_194)->SetCurSel(row);
                }
            }
        }
    }
    if (tributeList_1a8 != 0) {
        if (restoreSelection != 0) {
            selected = ((CListWnd*)tributeList_1a8)->GetItemData(
                ((CListWnd*)tributeList_1a8)->GetCurSel());
        }
        ((ListWndVCall_guess*)tributeList_1a8)->Slot76_guess();
        for (index = 0; index < count_1d8; ++index) {
            if (((Member_guess*)*buffer_1c8.Slot_guess(index))->online_004 == 1 ||
                showOffline_1c5) {
                int row = ((CListWnd*)tributeList_1a8)->AddString(
                    ((Member_guess*)*buffer_1c8.Slot_guess(index))->name_010,
                    0xffffffff, (unsigned int)*buffer_1c8.Slot_guess(index), 0);
                UpdateTributeRow_guess((Member_guess*)*buffer_1c8.Slot_guess(index), row);
                if (*(int*)buffer_1c8.Slot_guess(index) == selected) {
                    ((CListWnd*)tributeList_1a8)->SetCurSel(row);
                }
            }
        }
    }
    UpdateButtons_guess();
}

// Sorts the roster by `sortKey` (0 name, 1 level, 2 class, 3 rank, 4 last on, 5 zone, 6/7 public/personal
// note, 8-10 tribute on/total/last) and refills. `descending` 1 picks the plain comparator: ascending.
// FUNCTION: TITANIUM 0x005101B6
// @early-stop: compiler-generated, structural ndiff=19
void GuildMgmtWnd_guess::SortMembers_guess(int sortKey, char descending) {
    SortCompare_guess compare;
    switch (sortKey) {
    case 4:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberLastOn_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050ED08);
        }
        break;
    case 5:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberZone_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EE21);
        }
        break;
    case 3:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberRank_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050ECBD);
        }
        break;
    case 2:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberClass_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EC72);
        }
        break;
    case 1:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberLevel_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EC1D);
        }
        break;
    case 0:
        if (descending != 0) {
            compare = (SortCompare_guess)Fallback_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EBD2);
        }
        break;
    case 6:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberPublicNote_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050ED47);
        }
        break;
    case 7:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberPersonalNote_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050ED8B);
        }
        break;
    case 8:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberTributeFlag_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EE67);
        }
        break;
    case 9:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberTributeTotal_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EEB8);
        }
        break;
    case 10:
        if (descending != 0) {
            compare = (SortCompare_guess)CompareMemberLastDonation_guess;
        } else {
            compare = (SortCompare_guess)EQ_ARRAY(char, 0x0050EF09);
        }
        break;
    default:
        compare = (SortCompare_guess)0;
        break;
    }
    if (count_1d8 > 0 && compare != 0) {
        Buffer_guess* buffer = &buffer_1c8;
        if (buffer->count_0000_guess <= 0 || buffer->data == 0) {
            buffer->Fail_guess();
        }
        qsort(buffer->data, count_1d8, 4, compare);
    }
    sortKey_1c0 = sortKey;
    sortAscending_01c4_guess = descending;
    RefillLists_guess(1);
}

// Appends a server member record, fills its personal note from the notes file and shows it if visible.
// FUNCTION: TITANIUM 0x0051059A
// @early-stop: budget, structural ndiff=43
void GuildMgmtWnd_guess::AddMember_guess(Member_guess* entry) {
    buffer_1c8.Insert_guess(buffer_1c8.count_0000_guess, &entry);
    Member_guess* member = entry;
    if (void* record = FindPersonalNote_guess(member->name_010)) {
        strcpy(member->personalNote_0164_guess, (char*)record);
    }
    if (member->online_004 == 1 || showOffline_1c5) {
        if (membersList_16c != 0) {
            int row;
            {
                CXStr text(member->name_010);
                row = ((CListWnd*)membersList_16c)->AddString(
                    text, 0xffffffff, (unsigned int)member, 0);
            }
            UpdateMemberRow_guess(member, row);
        }
        if (notesList_194 != 0) {
            int row;
            {
                CXStr text(member->name_010);
                row = ((CListWnd*)notesList_194)->AddString(
                    text, 0xffffffff, (unsigned int)member, 0);
            }
            UpdateNoteRow_guess(member, row);
        }
        if (tributeList_1a8 != 0) {
            int row;
            {
                CXStr text(member->name_010);
                row = ((CListWnd*)tributeList_1a8)->AddString(
                    text, 0xffffffff, (unsigned int)member, 0);
            }
            UpdateTributeRow_guess(member, row);
        }
        UpdateButtons_guess();
    }
    ++count_1d8;
}

// Sets the personal note of member `key` in memory (a new entry is stamped with time()); the caller saves.
// FUNCTION: TITANIUM 0x005104FC
// @early-stop: budget, diff ndiff=18
void GuildMgmtWnd_guess::SetPersonalNote_guess(const char* key, const char* value) {
    int index = 0;
    unsigned int hash = FUN_00574890_guess(key);
    if (count_1f4 > 0) {
        do {
            PersonalNote_guess* entry = *buffer_1e4.Slot_guess(index);
            if (entry->hash_004 == hash) {
                strcpy(entry->record_048, value);
                return;
            }
            ++index;
        } while (index < count_1f4);
    }
    PersonalNote_guess* newEntry = new PersonalNote_guess;
    newEntry->hash_004 = hash;
    PersonalNote_guess* localEntry = newEntry;
    newEntry->timestamp_000 = time(0);
    strcpy(newEntry->name_008, key);
    strcpy(newEntry->record_048, value);
    buffer_1e4.Insert_guess(buffer_1e4.count_0000_guess, (Member_guess**)&localEntry);
    ++count_1f4;
}

// Destructor of the guild management window (vtable 0x655B68): frees the notes (+0x1E4) and roster
// (+0x1C8) pointer arrays (0x0050F3F6), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00510330
GuildMgmtWnd_guess::~GuildMgmtWnd_guess()  {
    buffer_1e4.Release_guess();
    buffer_1c8.Release_guess();
    FUN_005a3100_guess();
}

// Scalar deleting destructor of the guild management window (vtable 0x655B68 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00510357
GuildMgmtWnd_guess* GuildMgmtWnd_guess::Delete_guess(unsigned char flags) {
    GuildMgmtWnd_guess* result = this;
    this->~GuildMgmtWnd_guess();
    if ((flags & 1) != 0) {
        free_0060d0d5_guess(this);
    }
    return result;
}

// Reloads the personal-notes file: "%X name note" lines, names cut to 63 and notes to 255 characters;
// the first line per name wins. Marks the notes loaded (+0x3F8).
// FUNCTION: TITANIUM 0x00510373
// @early-stop: budget, diff ndiff=22
void GuildMgmtWnd_guess::LoadPersonalNotes_guess() {
    Buffer_guess* buffer = &buffer_1e4;
    int timestamp = buffer->count_0000_guess;
    FILE* file;
    int slot;
    char record[0x400];
    char name[0x400];
    char line[0x154];
    if (filename_1f8[0] == 0) {
        BuildNotesFileName_guess();
    }
    slot = 0;
    if (timestamp > 0) {
        do {
            free_0060d0d5_guess(*buffer->Slot_guess(slot));
            ++slot;
        } while (slot < timestamp);
    }
    buffer->Release_guess();
    count_1f4 = 0;
    notesLoaded_03f8_guess = 1;
    file = fopen(filename_1f8, "rt");
    if (file != 0) {
        while (!feof(file)) {
            line[0] = 0;
            fgets(line, 0x153, file);
            if (sscanf(line, "%X %s %[^\n", &timestamp, name, record) == 3) {
                FUN_00574a30_guess(name, 0x3f);
                FUN_00574a30_guess(record, 0xff);
                if (FindPersonalNote_guess(name) == 0) {
                    PersonalNote_guess* entry = new PersonalNote_guess;
                    slot = (int)entry;
                    strcpy(entry->name_008, name);
                    entry->timestamp_000 = timestamp;
                    entry->hash_004 = FUN_00574890_guess(name);
                    strcpy(entry->record_048, record);
                    buffer->Insert_guess(buffer->count_0000_guess,
                                         (struct Member_guess**)&slot);
                    ++count_1f4;
                }
            }
        }
        fclose(file);
    }
}

// EXTERNAL: TITANIUM 0x00466980 do_guildleader_guess
void __cdecl do_guildleader_guess(void* root, const char* text);
// EXTERNAL: TITANIUM 0x00466955 do_guildremove_guess
void __cdecl do_guildremove_guess(void* root, const char* text);
// EXTERNAL: TITANIUM 0x00466918 do_guildinvite_guess
void __cdecl do_guildinvite_guess(void* root, const char* text);
// EXTERNAL: TITANIUM 0x004666E3 do_guildmotd_guess
void __cdecl do_guildmotd_guess(void* root, const char* text);
// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key,
                                const char* value);
// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(void* destination, const char* value);

// Click (message 1): a list click selects the member in all three lists and fills the note inputs.
// Make leader, remove and promote run do_guildleader_guess, do_guildremove_guess and do_guildinvite_guess
// (an invite of a member promotes); demote sends OP_GuildDemote (0x4EB9), the banker flag
// OP_GuildManageBanker (0x3D1E), the public note message 0x17A2, opt-out message 0xCFC. Demote formats a
// command text it never uses. Header clicks (0x0F) sort: notes columns are keys 6-7, tribute 8-10.
// FUNCTION: TITANIUM 0x00510704
// @early-stop: budget, structural ndiff=64
int GuildMgmtWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        // Tab change: the new tab's list takes the old tab's selected row (+0x10C).
        if (sender == (CXWnd*)subwindows_01b8_guess) {
            int value = 0;
            if (memberSlots_400[((int*)data)[1]] != 0) {
                value = memberSlots_400[((int*)data)[1]]->value_10c;
            }
            if (memberSlots_400[((int*)data)[0]] != 0) {
                memberSlots_400[((int*)data)[0]]->Slot64_guess(value);
            }
        } else if ((int)sender == membersList_16c || (int)sender == notesList_194 ||
                   (int)sender == tributeList_1a8) {
            MemberList_guess* list = (MemberList_guess*)sender;
            selectedMember_01dc_guess = list->GetItemData(list->GetCurSel());
            if (selectedMember_01dc_guess != 0) {
                Member_guess* member = (Member_guess*)selectedMember_01dc_guess;
                int row = FindMemberRow_guess(selectedMember_01dc_guess);
                for (int index = 0; index < ini_140.count_01c; ++index) {
                    if (memberSlots_400[index] != 0) {
                        ((CListWnd*)memberSlots_400[index])->SetCurSel(row);
                    }
                }
                if (receiver_198 != 0) {
                    CXStr text(member->publicNote_0064_guess);
                    receiver_198->Slot63_guess((Temporary_guess*)&text);
                }
                if (receiver_1a0 != 0) {
                    CXStr text(member->personalNote_0164_guess);
                    receiver_1a0->Slot63_guess((Temporary_guess*)&text);
                }
                if (button_190 != 0) {
                    ((CButtonWnd*)button_190)->SetCheck(
                        ((unsigned char)member->flags_0054_guess) & 1);
                }
                UpdateButtons_guess();
            }
            return 0;
        // DumpButton: the member list is written out, tab-separated (0x0050EF1B).
        } else if (sender == (CXWnd*)ini_140.dumpButton_0028_guess) {
            DumpList_guess(0, EQ_ARRAY(char, 0x00646080));
            return 0;
        // ShowOfflineButton: refilters and re-sorts the member list and saves the choice as ShowOffline.
        } else if (sender == (CXWnd*)showOfflineButton_01b4_guess) {
            showOfflineByte_1c5 = ((CButtonWnd*)showOfflineButton_01b4_guess)->Checked;
            SortMembers_guess(sortKey_1c0, sortAscending_01c4_guess);
            char settingText[0x100];
            _sprintf_guess(settingText, EQ_ARRAY(char, 0x0063F53C),
                           showOfflineByte_1c5 != 0);
            FUN_0060bf20_guess(ini_140.GetSection_guess(),
                               EQ_ARRAY(char, 0x00655B40), settingText);
            return 0;
        // Member commands act on the selected member (+0x1DC).
        } else if (sender == (CXWnd*)makeLeaderButton_0180_guess) {
            Member_guess* member = (Member_guess*)selectedMember_01dc_guess;
            if (member != 0) {
                char text[0x200];
                _sprintf_guess(text, EQ_ARRAY(char, 0x0063F9FC), member->name_010);
                do_guildleader_guess(pinstLocalPlayer, text);
            }
            return 0;
        } else if (sender == (CXWnd*)removeButton_018c_guess) {
            Member_guess* member = (Member_guess*)selectedMember_01dc_guess;
            if (member != 0) {
                char text[0x200];
                _sprintf_guess(text, EQ_ARRAY(char, 0x0063F9FC), member->name_010);
                do_guildremove_guess(pinstLocalPlayer, text);
            }
            return 0;
        } else if (sender == button_190) {
            if (selectedMember_01dc_guess != 0) {
                g_guildList_guess.SendGuildBankerFlags_guess(
                    selectedMember_01dc_guess, 1,
                    ((CButtonWnd*)button_190)->Checked);
            }
        } else if (sender == (CXWnd*)promoteButton_0184_guess) {
            Member_guess* member = (Member_guess*)selectedMember_01dc_guess;
            if (member != 0) {
                char text[0x200];
                _sprintf_guess(text, EQ_ARRAY(char, 0x00655C98), member->name_010);
                do_guildinvite_guess(pinstLocalPlayer, text);
            }
            return 0;
        } else if (sender == (CXWnd*)demoteButton_0188_guess) {
            Member_guess* member = (Member_guess*)selectedMember_01dc_guess;
            if (member != 0) {
                char text[0x200];
                _sprintf_guess(text, EQ_ARRAY(char, 0x0063F9FC), member->name_010);
                g_guildList_guess.SendGuildDemote_guess(selectedMember_01dc_guess);
            }
            return 0;
        } else if (sender == (CXWnd*)updatePublicButton_019c_guess) {
            if (receiver_198 != 0) {
                CXStr text;
                if (playerRank_01e0_guess > 0) {
                    text = receiver_198->Slot76_guess();
                    g_guildList_guess.SendGuildPublicNote_guess(
                        ((Member_guess*)selectedMember_01dc_guess)->name_010,
                        text);
                }
            }
            return 0;
        } else if (sender == (CXWnd*)updateMOTDButton_0178_guess) {
            if (receiver_174 != 0) {
                CXStr text;
                if (playerRank_01e0_guess > 0) {
                    text = receiver_174->Slot76_guess();
                    int length = text.Ptr != 0 ? text.Ptr->length : 0;
                    char* copy = new char[length + 1];
                    if (copy != 0) {
                        FUN_0060e450_guess(copy, text);
                        do_guildmotd_guess(pinstLocalPlayer, copy);
                        delete [] copy;
                    }
                }
            }
            return 0;
        } else if (sender == (CXWnd*)updatePersonalButton_01a4_guess) {
            if (receiver_1a0 != 0) {
                CXStr text;
                text = receiver_1a0->Slot76_guess();
                SetPersonalNote_guess(((Member_guess*)selectedMember_01dc_guess)->name_010, text);
                FUN_0060e450_guess(((Member_guess*)selectedMember_01dc_guess)->personalNote_0164_guess, text);
                UpdateNoteRow_guess((Member_guess*)selectedMember_01dc_guess, -1);
                SavePersonalNotes_guess();
            }
            return 0;
        } else if (sender == (CXWnd*)optOutButton_01ac_guess) {
            g_guildList_guess.FUN_0040ab34_guess(
                ((Member_guess*)selectedMember_01dc_guess)->name_010, 0);
            return 0;
        }
    } else if (message == 0x0f) {
        int sortKey = -1;
        if ((int)sender == notesList_194) {
            sortKey = (int)(((unsigned int)data + 5) & (0u - (data != 0)));
        } else if ((int)sender == tributeList_1a8) {
            sortKey = (int)(((unsigned int)data + 7) & (0u - (data != 0)));
        } else if ((int)sender == membersList_16c) {
            sortKey = (int)data;
        }
        if (sortKey != -1) {
            if (sortKey == sortKey_1c0) {
                sortAscending_01c4_guess = sortAscending_01c4_guess == 0;
            } else {
                sortKey_1c0 = sortKey;
                sortAscending_01c4_guess = 1;
            }
            SortMembers_guess(sortKey_1c0, sortAscending_01c4_guess);
        }
    } else if (message == 0x0e) {
        UpdateButtons_guess();
        return 0;
    }
    return FUN_005a2230_guess(sender, message, data);
}

// Empties the roster, lists and inputs, restores the MOTD and author from 0x91D484 / 0x91D684 (probably
// the last ones received), then saves and reloads the personal notes.
// FUNCTION: TITANIUM 0x00510D2F
// @early-stop: budget, structural ndiff=41
void GuildMgmtWnd_guess::Clear_guess() {
    count_1d8 = 0;
    buffer_1c8.Release_guess();
    selectedMember_01dc_guess = 0;
    if (membersList_16c != 0) {
        ((CListWnd*)membersList_16c)->ClearAllSel();
        ((ListWndVCall_guess*)membersList_16c)->Slot76_guess();
    }
    if (notesList_194 != 0) {
        ((CListWnd*)notesList_194)->ClearAllSel();
        ((ListWndVCall_guess*)notesList_194)->Slot76_guess();
    }
    if (tributeList_1a8 != 0) {
        ((CListWnd*)tributeList_1a8)->ClearAllSel();
        ((ListWndVCall_guess*)tributeList_1a8)->Slot76_guess();
    }
    if (receiver_198 != 0) {
        CXStr text(g_emptyString_guess);
        receiver_198->Slot63_guess((Temporary_guess*)&text);
    }
    if (receiver_1a0 != 0) {
        CXStr text(g_emptyString_guess);
        receiver_1a0->Slot63_guess((Temporary_guess*)&text);
    }
    if (ini_140.receiver_164 != 0) {
        CXStr text(g_emptyString_guess);
        ini_140.receiver_164->Slot63_guess((Temporary_guess*)&text);
    }
    if (receiver_174 != 0) {
        CXStr text(EQ_ARRAY(const char, 0x0091D484));
        receiver_174->Slot63_guess((Temporary_guess*)&text);
    }
    if (stml_17c != 0) {
        CXStr text = FUN_0060aca0_guess(
            CXStr(EQ_ARRAY(const char, 0x0091D484)));
        stml_17c->SetSTMLText(text, true, 0);
    }
    if (receiver_170 != 0) {
        CXStr text(EQ_ARRAY(const char, 0x0091D684));
        receiver_170->Slot63_guess((Temporary_guess*)&text);
    }
    if (receiver_1b0 != 0) {
        CXStr text(g_emptyString_guess);
        receiver_1b0->Slot63_guess((Temporary_guess*)&text);
    }
    if (button_190 != 0) {
        button_190->SetCheck(false);
    }
    SavePersonalNotes_guess();
    LoadPersonalNotes_guess();
    UpdateButtons_guess();
}

// Builds the window from SIDL: list colours white, yellow and grey (0xFF808080), highlight 0xFF8AA3FF;
// note inputs take 255 characters, the MOTD 511.
// FUNCTION: TITANIUM 0x00510FDA
// @early-stop: budget, structural ndiff=695
GuildMgmtWnd_guess::GuildMgmtWnd_guess(CXWnd* parent)
    : GuildMgmtBase_guess(parent, "GuildManagementWnd", 0xfffffcff, 1, 0) {
    buffer_1c8.data = 0;
    buffer_1c8.count_0000_guess = 0;
    buffer_1c8.capacity_0008_guess = 0;
    unknown_1d4[0] = 1;
    buffer_1e4.data = 0;
    buffer_1e4.count_0000_guess = 0;
    buffer_1e4.capacity_0008_guess = 0;
    valid_1f0 = 1;
    ini_140.receiver_164 = 0;
    ini_140.dumpButton_0028_guess = 0;
    membersList_16c = 0;
    receiver_170 = 0;
    receiver_174 = 0;
    updateMOTDButton_0178_guess = 0;
    stml_17c = 0;
    makeLeaderButton_0180_guess = 0;
    promoteButton_0184_guess = 0;
    demoteButton_0188_guess = 0;
    removeButton_018c_guess = 0;
    button_190 = 0;
    notesList_194 = 0;
    receiver_198 = 0;
    updatePublicButton_019c_guess = 0;
    receiver_1a0 = 0;
    updatePersonalButton_01a4_guess = 0;
    tributeList_1a8 = 0;
    optOutButton_01ac_guess = 0;
    showOfflineButton_01b4_guess = 0;
    receiver_1b0 = 0;
    subwindows_01b8_guess = 0;
    tributePage_01bc_guess = 0;
    sortKey_1c0 = 0;
    sortAscending_01c4_guess = 1;
    showOffline_1c5 = false;
    count_1d8 = 0;
    selectedMember_01dc_guess = 0;
    playerRank_01e0_guess = 0;
    filename_1f8[0] = 0;
    notesLoaded_03f8_guess = 0;
    value_3fc = 0;
    for (int index = 0; index < 3; ++index) {
        memberSlots_400[index] = 0;
    }
    CSidlScreenWnd* screen = (CSidlScreenWnd*)this;
    if (screen->SidlPiece != 0) {
        screen->WindowStyle |= 0x10800;
        ini_140.value_018 = 0xd;
        // Children by SIDL name; the GuildName label and DumpButton live in the ini helper at +0x140.
        screen->CreateChildrenFromSidl();
        ini_140.receiver_164 = (TextReceiver_guess*)screen->GetChildItem("GuildName");
        ini_140.dumpButton_0028_guess = (int)screen->GetChildItem("DumpButton");
        membersList_16c = (int)screen->GetChildItem("MemberList");
        receiver_170 = (TextReceiver_guess*)screen->GetChildItem("MOTDAuthorLabel");
        receiver_174 = (TextReceiver_guess*)screen->GetChildItem("MOTDInput");
        updateMOTDButton_0178_guess = (int)screen->GetChildItem("UpdateMOTDButton");
        stml_17c = (CStmlWnd*)screen->GetChildItem("MOTDViewer");
        makeLeaderButton_0180_guess = (int)screen->GetChildItem("MakeLeaderButton");
        promoteButton_0184_guess = (int)screen->GetChildItem("PromoteButton");
        demoteButton_0188_guess = (int)screen->GetChildItem("DemoteButton");
        removeButton_018c_guess = (int)screen->GetChildItem("RemoveButton");
        button_190 = (CButtonWnd*)screen->GetChildItem("BankerFlagButton");
        notesList_194 = (int)screen->GetChildItem("NoteList");
        receiver_198 = (TextReceiver_guess*)screen->GetChildItem("PublicInput");
        updatePublicButton_019c_guess = (int)screen->GetChildItem("UpdatePublicButton");
        receiver_1a0 = (TextReceiver_guess*)screen->GetChildItem("PersonalInput");
        updatePersonalButton_01a4_guess = (int)screen->GetChildItem("UpdatePersonalButton");
        tributeList_1a8 = (int)screen->GetChildItem("TributeList");
        optOutButton_01ac_guess = (int)screen->GetChildItem("OptOutButton");
        tributePage_01bc_guess = (int)screen->GetChildItem("TributePage");
        receiver_1b0 = (TextReceiver_guess*)screen->GetChildItem("PlayerCount");
        showOfflineButton_01b4_guess = (int)screen->GetChildItem("ShowOfflineButton");
        subwindows_01b8_guess = (int)screen->GetChildItem("Subwindows");
        if (membersList_16c != 0) {
            ((GuildListWnd_guess*)membersList_16c)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((GuildListWnd_guess*)membersList_16c)->color_16c = 0xff8aa3ff;
            ((GuildListWnd_guess*)membersList_16c)->flag_15c = true;
            ((GuildListWnd_guess*)membersList_16c)->SetColumnJustification(1, 1);
            ((GuildListWnd_guess*)membersList_16c)->SetColumnJustification(2, 1);
            ((GuildListWnd_guess*)membersList_16c)->SetColumnJustification(3, 1);
            ((GuildListWnd_guess*)membersList_16c)->SetColumnJustification(4, 1);
        }
        if (notesList_194 != 0) {
            ((GuildListWnd_guess*)notesList_194)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((GuildListWnd_guess*)notesList_194)->color_16c = 0xff8aa3ff;
            ((GuildListWnd_guess*)notesList_194)->flag_15c = true;
        }
        if (tributeList_1a8 != 0) {
            ((GuildListWnd_guess*)tributeList_1a8)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((GuildListWnd_guess*)tributeList_1a8)->color_16c = 0xff8aa3ff;
            ((GuildListWnd_guess*)tributeList_1a8)->flag_15c = true;
            ((GuildListWnd_guess*)tributeList_1a8)->SetColumnJustification(1, 1);
            ((GuildListWnd_guess*)tributeList_1a8)->SetColumnJustification(2, 1);
            ((GuildListWnd_guess*)tributeList_1a8)->SetColumnJustification(3, 1);
        }
        if (receiver_198 != 0) {
            ((GuildEditWnd_guess*)receiver_198)->SetMaxChars_guess(0xff);
        }
        if (receiver_1a0 != 0) {
            ((GuildEditWnd_guess*)receiver_1a0)->SetMaxChars_guess(0xff);
        }
        if (receiver_174 != 0) {
            ((GuildEditWnd_guess*)receiver_174)->SetMaxChars_guess(0x1ff);
        }
        // The member, note and tribute lists by tab index, so the click handler can keep one member selected
        // across the tabs.
        memberSlots_400[0] = (ControlEntry_guess*)membersList_16c;
        memberSlots_400[1] = (ControlEntry_guess*)notesList_194;
        memberSlots_400[2] = (ControlEntry_guess*)tributeList_1a8;
        value_024 = 0xe6;
        ini_140.count_01c = 3;
        value_020 = 200;
        LoadSettings_guess();
        Clear_guess();
    }
}

