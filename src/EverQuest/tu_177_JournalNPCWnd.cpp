// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 177: a hint from compare/tumap.py.
// CJournalNPCWnd, the NPC conversation journal ("JournalNPCWnd"): an NPC list (name, zone, last seen) and,
// for the selected NPC, its logged dialog, saved per character and server as userdata\CJ_<name>_<server>
// plus .hdr/.txt. CJournalNPCWndView_guess (Object_guess) is a second view of the window.
#include "titanium/types.h"
#include "titanium/crt.h"
#include <windows.h>
#include "titanium/wnd/CJournalCatWnd.h"
#include "titanium/wnd/CTextEntryWnd.h"

struct JournalItem_guess;
struct NameTable_guess;
struct Record_guess;
struct Collection_guess;

struct Ini_guess {
    char pad_000[0x20];
    NameTable_guess* table_020;
    union {
        int journal_index_guess;  // Object +0x164
        Collection_guess* collection_024;
    };
    char pad_028[4];
    // EXTERNAL: TITANIUM 0x00572300 Ini_guess::GetSection_guess
    const char* GetSection_guess();
};

struct LookupManager_guess {
    // EXTERNAL: TITANIUM 0x005F6ED0 LookupManager_guess::FUN_005f6ed0_guess
    void FUN_005f6ed0_guess(int value_guess, char* output_guess);
    // EXTERNAL: TITANIUM 0x005FA1C0 LookupManager_guess::GetZoneName_guess
    void GetZoneName_guess(int zone_guess, char* output_guess, int long_guess);
};

struct LocationEntry_guess {
    char name_000[0x40];
    int zone_040;
    time_t time_044;
};
#define g_lookupManager_guess EQ_GLOBAL(LookupManager_guess*, 0x00905CC0)

struct JournalEntry_guess {
    char pad_000[0x40];
    int name_guess;
};

struct BufferPart_guess {
    int count_0000_guess;
    JournalItem_guess** data_004;
    char pad_008[8];
    // EXTERNAL: TITANIUM 0x00405492 BufferPart_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    JournalItem_guess*& Get_guess(int index_guess) {
        if (index_guess < count_0000_guess && index_guess >= 0 && data_004 != 0) {
            return data_004[index_guess];
        }
        Fail_guess();
    }
    // EXTERNAL: TITANIUM 0x0050F3F6 BufferPart_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x004EB924 BufferPart_guess::At_guess
    JournalItem_guess** At_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0050319B BufferPart_guess::Add_guess
    void Add_guess(int value_guess, Record_guess** record_guess);
};

struct Text_guess {
    CStrRep* rep;
    Text_guess() : rep(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 Text_guess::Text_guess
    Text_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Text_guess@@QAE@ABU0@@Z
    Text_guess(const Text_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00571F70 ??4Text_guess@@QAEAAU0@ABU0@@Z
    Text_guess& operator=(const Text_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00572C10 Text_guess::Append_guess
    void Append_guess(const Text_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00572E00 Text_guess::AppendText_guess
    void AppendText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0050176F Text_guess::Left_guess
    Text_guess Left_guess(int count_guess);
    // EXTERNAL: TITANIUM 0x005722D0 Text_guess::Unique_guess
    void Unique_guess(int mode_guess);
    // EXTERNAL: TITANIUM 0x00571D00 ?FreeRep@Text_guess@@QAEXPAUCStrRep@@@Z
    void FreeRep(CStrRep* text_guess);
    int Length_guess() const {
        return rep != 0 ? rep->length : 0;
    }
    // EXTERNAL: TITANIUM 0x00572300 ??BText_guess@@QBEPADXZ
    operator char*() const;
    ~Text_guess() {
        if (rep != 0) {
            FreeRep(rep);
        }
        rep = 0;
    }
};

struct JournalList_guess {
    int count_guess;
    int pad_004[6];
    JournalList_guess() {
        Initialize_guess(0x20);
    }
    // EXTERNAL: TITANIUM 0x0047C3AF JournalList_guess::Initialize_guess
    void Initialize_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E JournalList_guess::Free_guess
    void Free_guess();
    ~JournalList_guess() {
        Free_guess();
    }
};

struct JournalListBuffer_guess {
    int count_guess;
    int pad_004;
    unsigned int mask_008;
    unsigned int shift_00c;
    int** blocks_010;
    int pad_014[3];
};

struct Widget_guess {
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
    virtual void Slot63_guess(Text_guess* text_guess);
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
    virtual void Invoke_guess();
    // EXTERNAL: TITANIUM 0x00598580 Widget_guess::ClearAllSel
    void ClearAllSel();
    // EXTERNAL: TITANIUM 0x0059BB50 Widget_guess::Fill_guess
    void Fill_guess(JournalList_guess* list_guess);
    // EXTERNAL: TITANIUM 0x0059C360 Widget_guess::SetCurSel_guess
    void SetCurSel_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005229CA Widget_guess::ClearControls_guess
    void ClearControls_guess();
};

struct JournalItem_guess {
    char pad_000[4];
    int textHash_0004_guess;
    char pad_008[0xc];
    int index_014;
};

struct LookupName_guess {
    int pad_000;
    char text_004[1];
};

struct Record_guess {
    // EXTERNAL: TITANIUM 0x0042E525 Record_guess::FindEntryByCategory_guess
    int FindEntryByCategory_guess(int selection_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0042EC6C Record_guess::MatchesText_guess
    int MatchesText_guess(char* text_guess, int one_guess, int zero_guess);
};

struct Collection_guess {
    char pad_000[0x4c];
    int count_04c;
    // EXTERNAL: TITANIUM 0x0042EC6C Collection_guess::Find_guess
    int Find_guess(char* text_guess, int mode_guess, int start_guess);
    // EXTERNAL: TITANIUM 0x0042E4DC Collection_guess::At_guess
    Record_guess* At_guess(int index_guess);
};

struct NameTable_guess {
    char pad_000[0x808];
    int count_808;
    // EXTERNAL: TITANIUM 0x0042E76B NameTable_guess::At_guess
    Record_guess* At_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0042E8F3 NameTable_guess::Find_guess
    LookupName_guess* Find_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0042EE9A NameTable_guess::AddEntry_guess
    int AddEntry_guess(char* name_guess, int key_guess, int rank_guess, float x_guess, float y_guess,
                       float z_guess, const char* entry_guess, int extra_guess);
    // EXTERNAL: TITANIUM 0x0042F146 NameTable_guess::Load_guess
    void Load_guess(const char* path_guess);
    // EXTERNAL: TITANIUM 0x0042F6CC NameTable_guess::LoadText_guess
    int LoadText_guess(const char* path_guess);
};

struct NameSource_guess {
    char pad_000[0x160];
    NameTable_guess* table_160;
};
#define pinstCJournalNPCWnd_guess EQ_GLOBAL(NameSource_guess*, 0x00850CA4)

struct ChoiceWnd_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x0059C3A0 ChoiceWnd_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C3B0 ChoiceWnd_guess::GetChoice_guess
    CXStr GetChoice_guess();
};

struct CJournalNPCWndView_guess {
    int vtable;
    char pad_004[0x120];
    int value_124;
    char pad_128[0x18];
    Ini_guess ini_140;
    BufferPart_guess part_16c;
    int dialogCount_017c_guess;
    int selectedItem_0180_guess;
    int nextRotateTime_0184_guess;
    int rotateMinutes_0188_guess;
    int field_18c;
    int npcSortColumn_0190_guess;
    unsigned char npcSortAscending_0194_guess;
    char pad_195[3];
    int dialogSortColumn_0198_guess;
    unsigned char dialogSortAscending_019c_guess;
    char pad_19d[3];
    int selected_1a0;
    bool flag_1a4;
    bool flag_1a5;
    char pad_1a6[2];
    Text_guess text_1a8;
    char pad_1ac[4];
    BufferPart_guess part_1b0;
    int count_1c0;
    CXWnd* window_1c4;
    CXWnd* window_1c8;
    char pad_1cc[8];
    CButtonWnd* button_1d4;
    Widget_guess* widget_1d8;
    char pad_1dc[4];
    Widget_guess* widget_1e0;
    Widget_guess* widget_1e4;
    Widget_guess* widget_1e8;
    CStmlWnd* sink_1ec;

    // EXTERNAL: TITANIUM 0x005BD730 CJournalNPCWndView_guess::Setup_guess
    void Setup_guess(int first, int second, int* third);
    CJournalNPCWndView_guess* Initialize_guess(int first, int second, int third,
                                   int fourth, int fifth, int sixth, int seventh);
    // EXTERNAL: TITANIUM 0x005245FF ??1CJournalNPCWndView_guess@@QAE@XZ
    ~CJournalNPCWndView_guess();
    void* DeletingDtor_guess(unsigned char flags_guess);
    void FilterDialogList_guess();
    void FilterNpcList_guess();
    void SortNpcList_guess(int first_guess, unsigned char second_guess);
    // EXTERNAL: TITANIUM 0x0052384F CJournalNPCWndView_guess::FillCategoryCombos_guess
    void FillCategoryCombos_guess();
    void SortDialogList_guess(int first_guess, unsigned char second_guess);
    void UpdateDialogList_guess(bool select_guess);
    void SelectNpc_guess(int index_guess);
    void LoadIniInfo_guess();
    void SaveJournal_guess();
    void StoreIniInfo_guess();
    void ClearDialogList_guess();
    void RefreshJournal_guess();
    void SelectJournalItem_guess(int index_guess);
    void FillJournalList_guess(bool select_guess);
    void FillLocationList_guess(bool select_guess);
    void RotateLogs_guess(Text_guess name_guess);
    void AddDialogEntry_guess(char* name_guess, float x_guess, float y_guess, float z_guess,
                              const char* entry_guess);
    void RefreshAll_guess(bool mode_guess);
    bool AboutToShow_guess();
    // EXTERNAL: TITANIUM 0x00525034 CJournalNPCWndView_guess::LoadJournalFiles_guess
    void LoadJournalFiles_guess(int mode_guess);
    void ReloadJournal_guess();
};

struct Display_guess {
    char pad_000[0x148];
    int ticks_148_guess;
};
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

struct Source_guess {
    char pad_000[0x120];
    char text_120[0xe4];
    int value_204_guess;
};
#define g_source_guess EQ_GLOBAL(Source_guess*, 0x00905CE4)

struct Buffer_guess {
    // EXTERNAL: TITANIUM 0x00493B8F Buffer_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
    // EXTERNAL: TITANIUM 0x00493ADA Buffer_guess::FUN_00493ada_guess
    void FUN_00493ada_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x004982C6 Buffer_guess::dsp_chat
    void dsp_chat(NameTable_guess* table_guess, int mode_guess,
                            int enabled_guess);
};
#define g_buffer_guess EQ_GLOBAL(Buffer_guess*, 0x00988DF0)

// The character data as a virtual base: vbptr at +8, name at 0x3C of the base.
struct CharacterPrefix_guess {
    virtual void Slot00_guess();
    int field04_guess;
};

struct CharacterBase_guess {
    char pad_000[0x3c];
    char name_03c[0x40];
};

struct CharacterView_guess : CharacterPrefix_guess, virtual CharacterBase_guess {
};
#define g_charData_guess EQ_GLOBAL(CharacterView_guess*, 0x00905D00)

#define g_extTxt_guess EQ_ARRAY(char, 0x0063FE34)
#define g_extHdr_guess EQ_ARRAY(char, 0x00641B0C)
#define g_fmtInt_guess EQ_ARRAY(char, 0x0063F53C)
#define g_vtable_guess EQ_GLOBAL(int, 0x00657100)
#define g_journalDefault_guess EQ_ARRAY(char, 0x00645EB4)
#define g_journalOther_guess EQ_ARRAY(char, 0x006410A8)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)
#define g_suffix_guess EQ_ARRAY(char, 0x00657048)
#define g_journalPrefix_guess EQ_ARRAY(char, 0x00656F18)

// EXTERNAL: TITANIUM 0x00612662 DeleteJournalFile_guess
void __cdecl DeleteJournalFile_guess(const char* path_guess);

// EXTERNAL: TITANIUM 0x00576670 JournalFileExists_guess
char __cdecl JournalFileExists_guess(const char* path_guess);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
unsigned int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
                                const char* defaultValue, char* value,
                                int size, char useDefault);

// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key,
                                const char* value);

// EXTERNAL: TITANIUM 0x0042EC50 GetJournalText_guess
const char* __cdecl GetJournalText_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00572300 FUN_00572300_guess
char* __cdecl FUN_00572300_guess(char* buffer_guess, int size_guess);

// EXTERNAL: TITANIUM 0x00574720 FUN_00574720_guess
void __cdecl FUN_00574720_guess(char* text_guess);

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x004D9090 Join_guess
Text_guess __cdecl Join_guess(const Text_guess& left_guess, const Text_guess& right_guess);

// Keeps rolling backups of the journal files: at most once per +0x188 minutes (60), drops backup +0x18C
// (3) and renames <name><n-1> to <name><n> for both .txt and .hdr, the live file becoming backup 1.
// FUNCTION: TITANIUM 0x00523A10
void CJournalNPCWndView_guess::RotateLogs_guess(Text_guess name_guess) {
    Text_guess from_guess;
    Text_guess to_guess;
    int now_guess = g_display_guess->ticks_148_guess;
    if (now_guess > nextRotateTime_0184_guess) {
        char count_text[12];
        _sprintf_guess(count_text, g_fmtInt_guess, field_18c);
        from_guess = Join_guess(Join_guess(name_guess, Text_guess(count_text)), Text_guess(g_extTxt_guess));
        DeleteFileA(from_guess);
        from_guess = Join_guess(Join_guess(name_guess, Text_guess(count_text)), Text_guess(g_extHdr_guess));
        DeleteFileA(from_guess);
        for (int i = field_18c - 1; i >= 0; --i) {
            char suffix[12];
            suffix[0] = 0;
            if (i != 0) {
                _sprintf_guess(suffix, g_fmtInt_guess, i);
            }
            from_guess = Join_guess(Join_guess(name_guess, Text_guess(suffix)), Text_guess(g_extTxt_guess));
            to_guess = Join_guess(Join_guess(name_guess, Text_guess(count_text)), Text_guess(g_extTxt_guess));
            MoveFileA(from_guess, to_guess);
            from_guess = Join_guess(Join_guess(name_guess, Text_guess(suffix)), Text_guess(g_extHdr_guess));
            to_guess = Join_guess(Join_guess(name_guess, Text_guess(count_text)), Text_guess(g_extHdr_guess));
            MoveFileA(from_guess, to_guess);
            strcpy(count_text, suffix);
        }
        nextRotateTime_0184_guess = rotateMinutes_0188_guess * 60000 + now_guess;
    }
}

// NPC sort by zone name, A to Z: entry +0x40 is the zone id, not the NPC name.
// FUNCTION: TITANIUM 0x00524034
int __cdecl CompareNpcZonesAsc_guess(JournalEntry_guess** first_guess,
                         JournalEntry_guess** second_guess) {
    char left_guess[32];
    char right_guess[32];
    JournalEntry_guess* other_guess = *second_guess;
    g_lookupManager_guess->FUN_005f6ed0_guess((*first_guess)->name_guess,
                                              left_guess);
    g_lookupManager_guess->FUN_005f6ed0_guess(other_guess->name_guess,
                                              right_guess);
    return __stricmp(left_guess, right_guess);
}

// NPC sort by zone name, Z to A.
// FUNCTION: TITANIUM 0x0052408B
int __cdecl CompareNpcZonesDesc_guess(JournalEntry_guess** first_guess,
                         JournalEntry_guess** second_guess) {
    char left_guess[32];
    char right_guess[32];
    JournalEntry_guess* other_guess = *second_guess;
    g_lookupManager_guess->FUN_005f6ed0_guess((*first_guess)->name_guess,
                                              left_guess);
    g_lookupManager_guess->FUN_005f6ed0_guess(other_guess->name_guess,
                                              right_guess);
    return -__stricmp(left_guess, right_guess);
}

// Reads the enable setting (JournalLog) from the UI ini; 1, t or T is on. The LoadIniInfo partner of
// StoreIniInfo_guess.
// FUNCTION: TITANIUM 0x0052417A
void CJournalNPCWndView_guess::LoadIniInfo_guess() {
    char defaultValue[512];
    char value[512];
    if (NewUIINI() != 0) {
        _sprintf_guess(defaultValue, "%s", g_journalDefault_guess);
        LoadStringFromUIIniFile_guess(ini_140.GetSection_guess(), "JournalLog",
                           defaultValue, value, 0x1ff, 1);
        flag_1a4 = (value[0] == '1' || value[0] == 't' || value[0] == 'T');
    }
}

// Writes the enable setting (JournalLog) to the UI ini.
// FUNCTION: TITANIUM 0x00524211
void CJournalNPCWndView_guess::StoreIniInfo_guess() {
    char value[256];
    if (NewUIINI() != 0) {
        const char* text = flag_1a4 != 0 ? g_journalDefault_guess
                                         : g_journalOther_guess;
        _sprintf_guess(value, "%s", text);
        FUN_0060bf20_guess(ini_140.GetSection_guess(), "JournalLog", value);
    }
}

// Empties the dialog list and text and forgets the dialog entries and the selected one.
// FUNCTION: TITANIUM 0x00524281
void CJournalNPCWndView_guess::ClearDialogList_guess() {
    if (widget_1e8 != 0) {
        widget_1e8->ClearAllSel();
        widget_1e8->Invoke_guess();
    }
    if (sink_1ec != 0) {
        sink_1ec->SetSTMLText(g_emptyText_guess, 1, 0);
    }
    selectedItem_0180_guess = 0;
    dialogCount_017c_guess = 0;
    return part_16c.Reset_guess();
}

// Saves the journal (0x42F146 writes the .txt and .hdr files) to CJ_<name>_<server>,
// rotating backups first unless a load failed. Only while journaling is on. The Save button and the UI
// deactivation (0x00437BCD) call it.
// FUNCTION: TITANIUM 0x005242E8
void CJournalNPCWndView_guess::SaveJournal_guess() {
    if (g_source_guess != 0 && flag_1a4) {
        char buffer_guess[0x80];
        Text_guess path_guess(".\\");
        path_guess.Append_guess(Text_guess("userdata"));
        path_guess.Append_guess(Text_guess("\\CJ_"));
        path_guess.Append_guess(Text_guess(g_charData_guess->name_03c));
        path_guess.Append_guess(Text_guess("_"));
        g_buffer_guess->GetServerShortName_guess(buffer_guess);
        path_guess.Append_guess(Text_guess(buffer_guess));
        if (flag_1a5) {
            RotateLogs_guess(path_guess);
        }
        ini_140.table_020->Load_guess(path_guess);
    }
}

typedef int (__cdecl* JournalCompare_guess)(JournalEntry_guess**, JournalEntry_guess**);
typedef int (__cdecl* QsortCompare_guess)(const void*, const void*);

// EXTERNAL: TITANIUM 0x00523F6E FUN_00523f6e_guess
int __cdecl FUN_00523f6e_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00523F93 FUN_00523f93_guess
int __cdecl FUN_00523f93_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00523FBB FUN_00523fbb_guess
int __cdecl FUN_00523fbb_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00523FD0 FUN_00523fd0_guess
int __cdecl FUN_00523fd0_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00523FE7 FUN_00523fe7_guess
int __cdecl FUN_00523fe7_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x0052400C FUN_0052400c_guess
int __cdecl FUN_0052400c_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x005240E4 FUN_005240e4_guess
int __cdecl FUN_005240e4_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00524107 FUN_00524107_guess
int __cdecl FUN_00524107_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x0052412D FUN_0052412d_guess
int __cdecl FUN_0052412d_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00524155 FUN_00524155_guess
int __cdecl FUN_00524155_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// Same bodies as the two above, folded by the linker.
// EXTERNAL: TITANIUM 0x0052412D FUN_0052412d_b_guess
int __cdecl FUN_0052412d_b_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);
// EXTERNAL: TITANIUM 0x00524155 FUN_00524155_b_guess
int __cdecl FUN_00524155_b_guess(JournalEntry_guess** first_guess, JournalEntry_guess** second_guess);

// Sorts the filtered NPC list; `second_guess` picks ascending. The column clicks give mode 0 (name),
// 2 (zone, 0x524034) and 3 (the default case; last seen, probably); mode 1 is never passed.
// FUNCTION: TITANIUM 0x005244F0
void CJournalNPCWndView_guess::SortNpcList_guess(int first_guess, unsigned char second_guess) {
    JournalCompare_guess compare_guess;
    switch (first_guess) {
    case 0:
        compare_guess = second_guess != 0 ? FUN_00523fbb_guess : FUN_00523fd0_guess;
        break;
    case 1:
        compare_guess = second_guess != 0 ? FUN_00523fe7_guess : FUN_0052400c_guess;
        break;
    case 2:
        compare_guess = second_guess != 0 ? CompareNpcZonesAsc_guess : CompareNpcZonesDesc_guess;
        break;
    default:
        compare_guess = second_guess != 0 ? FUN_00523f6e_guess : FUN_00523f93_guess;
        break;
    }
    if (count_1c0 > 0) {
        qsort(&part_1b0.Get_guess(0), count_1c0, 4, (QsortCompare_guess)compare_guess);
    }
}

// Sorts the selected NPC's dialog. Modes 1 and 2 use the same comparators (the _b names are the same
// addresses); there is no default case, but the callers pass only 0 and 2.
// FUNCTION: TITANIUM 0x00524580
void CJournalNPCWndView_guess::SortDialogList_guess(int first_guess, unsigned char second_guess) {
    JournalCompare_guess compare_guess = 0;
    switch (first_guess) {
    case 0:
        compare_guess = second_guess != 0 ? FUN_005240e4_guess : FUN_00524107_guess;
        break;
    case 1:
        compare_guess = second_guess != 0 ? FUN_00524155_b_guess : FUN_0052412d_b_guess;
        break;
    case 2:
        compare_guess = second_guess != 0 ? FUN_00524155_guess : FUN_0052412d_guess;
        break;
    }
    if (dialogCount_017c_guess > 0) {
        qsort(&part_16c.Get_guess(0), dialogCount_017c_guess, 4, (QsortCompare_guess)compare_guess);
    }
}

// Rebuilds the NPC list from the journal: an NPC stays when it matches the category filter (+0x1A0,
// -1 = all) and, with a search text set (+0x1A8), contains that text. The 0x572300 call copies the search
// text into the buffer (its this is not visible in this source).
// FUNCTION: TITANIUM 0x0052494D
// @early-stop: budget, structural ndiff=37
void CJournalNPCWndView_guess::FilterNpcList_guess() {
    count_1c0 = 0;
    int count_guess = ini_140.table_020->count_808;
    int selected_guess = selected_1a0;
    int ownerValue_guess = text_1a8.Length_guess();
    char text_guess[128];
    Record_guess* record_guess;
    int index_guess = 0;

    text_guess[0] = 0;
    FUN_00574720_guess(FUN_00572300_guess(text_guess, 0x7f));
    part_1b0.Reset_guess();

    while (index_guess < count_guess) {
        record_guess = ini_140.table_020->At_guess(index_guess);
        if (selected_guess == -1 ||
            record_guess->FindEntryByCategory_guess(selected_guess, 0) != 0) {
            if (ownerValue_guess == 0 ||
                record_guess->MatchesText_guess(text_guess, 1, 0) != -1) {
                part_1b0.Add_guess(part_1b0.count_0000_guess, &record_guess);
                ++count_1c0;
            }
        }
        ++index_guess;
    }
}

struct Allocation_guess {
    // EXTERNAL: TITANIUM 0x0042F6C7 Allocation_guess::Cleanup_guess
    void Cleanup_guess();
};

struct Base_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess();
};

struct TargetBuffer_guess {
    char pad_000[0x10];
    // EXTERNAL: TITANIUM 0x0050F3F6 TargetBuffer_guess::~TargetBuffer_guess
    ~TargetBuffer_guess();
};

struct CleanupPart_guess {
    int value_000;
    // EXTERNAL: TITANIUM 0x004482FB CleanupPart_guess::~CleanupPart_guess
    ~CleanupPart_guess();
};

// EXTERNAL: TITANIUM 0x00656F28 ??_7Target_guess@@6B@
struct Target_guess : Base_guess {
    virtual void Slot01_guess();
    char pad_004[0x15c];
    Allocation_guess* allocation_160;
    char pad_164[0x8];
    TargetBuffer_guess part_16c;
    int field_17c;
    int field_180;
    char pad_184[0x20];
    bool flag_1a4;
    char pad_1a5[3];
    CleanupPart_guess cleanup_1a8;
    CleanupPart_guess cleanup_1ac;
    TargetBuffer_guess part_1b0;

    ~Target_guess();
};

// CJournalNPCWnd's destructor body: frees the journal data (+0x160).
// FUNCTION: TITANIUM 0x005245FF
// @early-stop: budget, structural ndiff=2
Target_guess::~Target_guess() {
    Allocation_guess* allocation_guess = allocation_160;
    if (allocation_guess != 0) {
        allocation_guess->Cleanup_guess();
        ::operator delete(allocation_guess);
    }
}

// Enables the two Delete buttons only when their list has a selection and ticks Enable. The Search button
// shows the search text, cut to 7 characters plus a suffix (0x657048) past 8, or "Search" (0xC71).
// FUNCTION: TITANIUM 0x00524683
void CJournalNPCWndView_guess::RefreshJournal_guess() {
    Widget_guess* source_guess = widget_1e4;
    if (source_guess != 0 && window_1c4 != 0) {
        JournalList_guess list_guess;
        source_guess->Fill_guess(&list_guess);
        CXWnd* window_guess = window_1c4;
        window_guess->Enabled = list_guess.count_guess > 0;
    }
    source_guess = widget_1e8;
    if (source_guess != 0 && window_1c8 != 0) {
        JournalList_guess list_guess;
        source_guess->Fill_guess(&list_guess);
        CXWnd* window_guess = window_1c8;
        window_guess->Enabled = list_guess.count_guess > 0;
    }
    if (button_1d4 != 0) {
        button_1d4->SetCheck(flag_1a4);
    }
    if (widget_1d8 != 0) {
        if (text_1a8.Length_guess() != 0) {
            ((CButtonWnd*)widget_1d8)->SetCheck(true);
            Text_guess text_guess(text_1a8);
            text_guess.Unique_guess(1);
            if (text_guess.Length_guess() > 8) {
                text_guess = text_guess.Left_guess(7);
                text_guess.Append_guess(Text_guess(g_suffix_guess));
            }
            widget_1d8->Slot63_guess(&text_guess);
        } else {
            ((CButtonWnd*)widget_1d8)->SetCheck(false);
            Text_guess text_guess(pStringTable->getString(0xc71, 0));
            widget_1d8->Slot63_guess(&text_guess);
        }
    }
}

// Collects the selected NPC's dialog entries, all of them or those that contain the search text.
// FUNCTION: TITANIUM 0x00524A3A
// @early-stop: budget, structural ndiff=24
void CJournalNPCWndView_guess::FilterDialogList_guess() {
    int index_guess = 0;
    char text_guess[128];

    dialogCount_017c_guess = 0;
    part_16c.Reset_guess();
    if (ini_140.collection_024 != 0) {
        int count_guess = ini_140.collection_024->count_04c;
        text_guess[0] = '\0';
        FUN_00574720_guess(FUN_00572300_guess(text_guess, 0x7f));
        int length_guess = strlen(text_guess);
        if (count_guess > 0) {
            do {
                if (index_guess == -1) {
                    return;
                }
                if (length_guess < 1 ||
                    (index_guess = ini_140.collection_024->Find_guess(text_guess, 1, index_guess)) != -1) {
                    Record_guess* record_guess = ini_140.collection_024->At_guess(index_guess);
                    part_16c.Add_guess(part_16c.count_0000_guess, &record_guess);
                    ++dialogCount_017c_guess;
                    ++index_guess;
                }
            } while (index_guess < count_guess);
        }
    }
}

// Scalar deleting destructor of the journal NPC window (vtable 0x656F28 slot 1): runs the destructor
// (0x005245FF, which frees the journal data) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00524876
void* CJournalNPCWndView_guess::DeletingDtor_guess(unsigned char flags_guess) {
    this->CJournalNPCWndView_guess::~CJournalNPCWndView_guess();
    if ((flags_guess & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

// Shows the selected dialog entry's text and its category; -1 deselects.
// FUNCTION: TITANIUM 0x00524892
void CJournalNPCWndView_guess::SelectJournalItem_guess(int index_guess) {
    if (widget_1e8 != 0) {
        if (index_guess != -1) {
            JournalItem_guess* item_guess =
                (JournalItem_guess*)((CListWnd*)widget_1e8)->GetItemData(index_guess);
            CXStr text_guess(GetJournalText_guess(item_guess->textHash_0004_guess));
            if (sink_1ec != 0) {
                ((CStmlWnd*)sink_1ec)->SetSTMLText(text_guess, true, 0);
            }
            if (widget_1e0 != 0) {
                widget_1e0->SetCurSel_guess(item_guess->index_014 + 1);
            }
            selectedItem_0180_guess = (int)item_guess;
        } else {
            selectedItem_0180_guess = 0;
        }
    }
    RefreshJournal_guess();
}

// Fills the dialog list: time, category name ("None", 0x4C0, when unknown) and the text's last 64
// characters. With `select_guess` the previous selection is kept.
// FUNCTION: TITANIUM 0x00524B03
void CJournalNPCWndView_guess::FillJournalList_guess(bool select_guess) {
    int selected_guess = -1;
    if (widget_1e8 != 0) {
        widget_1e8->Invoke_guess();
        int i = 0;
        if (dialogCount_017c_guess > 0) {
            do {
                JournalItem_guess* entry = *part_16c.At_guess(i);
                int row_guess;
                {
                    CXStr time_guess(ctime((time_t*)entry));
                    row_guess = ((CListWnd*)widget_1e8)->AddString(
                        time_guess, 0xffffffff, (unsigned int)entry, 0);
                }
                LookupName_guess* name_guess = ini_140.table_020->Find_guess(entry->index_014);
                {
                    CXStr text_guess(name_guess == 0 ? pStringTable->getString(0x4c0, 0) : name_guess->text_004);
                    ((CListWnd*)widget_1e8)->SetItemText(row_guess, 1, text_guess);
                }
                Text_guess value_guess(GetJournalText_guess(entry->textHash_0004_guess));
                value_guess = value_guess.Left_guess(0x40);
                {
                    CXStr text_guess((char*)value_guess);
                    ((CListWnd*)widget_1e8)->SetItemText(row_guess, 2, text_guess);
                }
                if (select_guess && (int)entry == selectedItem_0180_guess) {
                    selected_guess = row_guess;
                }
            } while (++i < dialogCount_017c_guess);
            if (selected_guess != -1) {
                ((CListWnd*)widget_1e8)->SetCurSel(selected_guess);
            }
        }
        if (select_guess) {
            SelectJournalItem_guess(selected_guess);
        }
    }
}

// Refreshes the dialog side for the selected NPC: filter, sort, fill, buttons.
// FUNCTION: TITANIUM 0x00524CF0
void CJournalNPCWndView_guess::UpdateDialogList_guess(bool select_guess) {
    FilterDialogList_guess();
    SortDialogList_guess(dialogSortColumn_0198_guess, dialogSortAscending_019c_guess);
    FillJournalList_guess(select_guess);
    RefreshJournal_guess();
}

// Selects the NPC on list row `index_guess` (-1 clears the dialog side) and reloads its dialog when it
// changed.
// FUNCTION: TITANIUM 0x00524D24
void CJournalNPCWndView_guess::SelectNpc_guess(int index_guess) {
    if (index_guess == -1) {
        ini_140.journal_index_guess = 0;
        if (widget_1e8 != 0) {
            widget_1e8->ClearAllSel();
            widget_1e8->Invoke_guess();
        }
        if (sink_1ec != 0) {
            sink_1ec->SetSTMLText(g_emptyText_guess, 1, 0);
            selectedItem_0180_guess = 0;
        }
    } else {
        int old_guess = ini_140.journal_index_guess;
        int new_guess = (int)*part_1b0.At_guess(index_guess);
        ini_140.journal_index_guess = new_guess;
        if (old_guess != new_guess) {
            UpdateDialogList_guess(false);
        }
    }
    RefreshJournal_guess();
}

// Fills the NPC list: name, long zone name, last-seen time (blank when 0); then reselects the NPC.
// FUNCTION: TITANIUM 0x00524DB8
void CJournalNPCWndView_guess::FillLocationList_guess(bool select_guess) {
    int selected_guess = -1;
    if (widget_1e4 != 0) {
        widget_1e4->ClearAllSel();
        int count_guess = count_1c0;
        widget_1e4->Invoke_guess();
        int i = 0;
        if (count_guess > 0) {
            do {
                LocationEntry_guess* entry = (LocationEntry_guess*)*part_1b0.At_guess(i);
                char zone_guess[80];
                g_lookupManager_guess->GetZoneName_guess(entry->zone_040, zone_guess, 1);
                int row_guess;
                {
                    CXStr name_guess(entry->name_000);
                    row_guess = ((CListWnd*)widget_1e4)->AddString(
                        name_guess, 0xffffffff, (unsigned int)entry, 0);
                }
                {
                    CXStr text_guess(zone_guess);
                    ((CListWnd*)widget_1e4)->SetItemText(row_guess, 1, text_guess);
                }
                if (entry->time_044 == 0) {
                    CXStr text_guess(g_emptyText_guess);
                    ((CListWnd*)widget_1e4)->SetItemText(row_guess, 2, text_guess);
                } else {
                    CXStr text_guess(ctime(&entry->time_044));
                    ((CListWnd*)widget_1e4)->SetItemText(row_guess, 2, text_guess);
                }
                if (select_guess && (int)entry == ini_140.journal_index_guess) {
                    selected_guess = row_guess;
                }
            } while (++i < count_guess);
            if (selected_guess != -1) {
                ((CListWnd*)widget_1e4)->SetCurSel(selected_guess);
            }
        }
        SelectNpc_guess(selected_guess);
    }
}

// Rebuilds the whole window (NPC list, dialog, category window).
// FUNCTION: TITANIUM 0x00524F87
void CJournalNPCWndView_guess::RefreshAll_guess(bool mode_guess) {
    FilterNpcList_guess();
    SortNpcList_guess(npcSortColumn_0190_guess, npcSortAscending_0194_guess);
    FillLocationList_guess(mode_guess);
    UpdateDialogList_guess(mode_guess);
    FillCategoryCombos_guess();
}

// Logs one line an NPC said (name, position, text) while journaling is on, under the player's zone
// (+0x204) and the category window's current category, then rebuilds the window.
// FUNCTION: TITANIUM 0x00524FC6
void CJournalNPCWndView_guess::AddDialogEntry_guess(char* name_guess, float x_guess, float y_guess, float z_guess,
                                        const char* entry_guess) {
    if (flag_1a4) {
        int key_guess = g_source_guess->value_204_guess;
        time_t now_guess = time(&now_guess);
        ini_140.table_020->AddEntry_guess(name_guess, key_guess, now_guess,
                                          x_guess, y_guess, z_guess, entry_guess,
                                          pinstCJournalCatWnd_guess->field_180_guess);
        RefreshAll_guess(1);
    }
}

// Loads the journal of the current character and server. Files named after the old, world-host-derived
// server name (0x493ADA) are first copied to the new name (0x493B8F) and kept as *_old.
// `mode_guess` > 0 loads that backup instead. A load error is reported (chat colour 15 for -1, else 13);
// below -1 it also stops backup rotation, probably so the bad file can't push good backups out.
// FUNCTION: TITANIUM 0x00525034
// @early-stop: budget, normalised ndiff=0
void CJournalNPCWndView_guess::LoadJournalFiles_guess(int mode_guess) {
    if (g_source_guess != 0) {
        Text_guess path_guess;
        Text_guess full_path_guess;
        char header_path_guess[512];
        char text_path_guess[512];
        char source_header_guess[512];
        char source_text_guess[512];
        char old_path_guess[512];
        char zone_guess[0x80];

        path_guess = Text_guess(".\\");
        path_guess.Append_guess(Text_guess("userdata"));
        path_guess.Append_guess(Text_guess(g_journalPrefix_guess));
        path_guess.Append_guess(Text_guess(g_source_guess->text_120));
        path_guess.Append_guess(Text_guess("_"));
        full_path_guess = path_guess;
        g_buffer_guess->GetServerShortName_guess(zone_guess);
        path_guess.Append_guess(Text_guess(zone_guess));

        _sprintf_guess(header_path_guess, "%s%s.hdr", (char*)full_path_guess,
                       zone_guess);
        _sprintf_guess(text_path_guess, "%s%s.txt", (char*)full_path_guess,
                       zone_guess);
        g_buffer_guess->FUN_00493ada_guess(zone_guess);
        _sprintf_guess(source_header_guess, "%s%s.hdr", (char*)full_path_guess,
                       zone_guess);
        _sprintf_guess(source_text_guess, "%s%s.txt", (char*)full_path_guess,
                       zone_guess);

        if (!JournalFileExists_guess(header_path_guess) &&
            JournalFileExists_guess(source_header_guess)) {
            CopyFileA(source_header_guess, header_path_guess, TRUE);
            CopyFileA(source_text_guess, text_path_guess, TRUE);
            if (JournalFileExists_guess(header_path_guess)) {
                _sprintf_guess(old_path_guess, "%s_old", source_header_guess);
                CopyFileA(source_header_guess, old_path_guess, TRUE);
                DeleteJournalFile_guess(source_header_guess);
            }
            if (JournalFileExists_guess(text_path_guess)) {
                _sprintf_guess(old_path_guess, "%s_old", source_text_guess);
                CopyFileA(source_text_guess, old_path_guess, TRUE);
                DeleteJournalFile_guess(source_text_guess);
            }
        }

        if (mode_guess > 0) {
            char number_guess[12];
            _sprintf_guess(number_guess, g_fmtInt_guess, mode_guess);
            path_guess.AppendText_guess(number_guess);
        }

        int result_guess = ini_140.table_020->LoadText_guess((char*)path_guess);
        if (result_guess < 0) {
            g_buffer_guess->dsp_chat(
                ini_140.table_020, result_guess == -1 ? 0xf : 0xd, 1);
            if (result_guess < -1) {
                flag_1a5 = false;
            }
        }
        RefreshAll_guess(false);
        if (pinstCJournalCatWnd_guess != 0) {
            pinstCJournalCatWnd_guess->Reload_guess(0);
        }
    }
}

// Reads the enable setting and, when on, loads the journal.
// FUNCTION: TITANIUM 0x00525484
void CJournalNPCWndView_guess::ReloadJournal_guess() {
    LoadIniInfo_guess();
    if (flag_1a4) {
        LoadJournalFiles_guess(0);
    }
}

// Drops the search text and rebuilds; always true.
// FUNCTION: TITANIUM 0x005254A0
bool CJournalNPCWndView_guess::AboutToShow_guess() {
    ((CXStr*)&text_1a8)->~CXStr();
    RefreshAll_guess(0);
    return true;
}

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct JournalSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1JournalSidlBase_guess@@UAE@XZ
    virtual ~JournalSidlBase_guess();
    char pad_004[0x60];
    unsigned int windowStyle_064;
    char pad_068[0xbc];
    void* sidlPiece_124;
    char pad_128[0x30];
    int field_158;
    // EXTERNAL: TITANIUM 0x005A2230 JournalSidlBase_guess::WndNotification
    int WndNotification(CXWnd* sender_guess, unsigned int message_guess,
                              void* data_guess);
    // EXTERNAL: TITANIUM 0x005A3850 ??0JournalSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    JournalSidlBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
};

struct JournalArray_guess {
    int data_000;
    int count_004;
    int alloc_008;
    bool owns_00c;
    // EXTERNAL: TITANIUM 0x004EB924 JournalArray_guess::At_guess
    JournalItem_guess** At_guess(int index_guess);
    JournalArray_guess() {
        count_004 = 0;
        data_000 = 0;
        alloc_008 = 0;
        owns_00c = true;
    }
    ~JournalArray_guess();
};

struct JournalData_guess {
    char pad_000[0x818];
    // EXTERNAL: TITANIUM 0x0042E660 JournalData_guess::JournalData_guess
    JournalData_guess();
    // EXTERNAL: TITANIUM 0x0042F0B1 JournalData_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0042E929 JournalData_guess::FindCategoryByName_guess
    LookupName_guess* FindCategoryByName_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x0042EE0A JournalData_guess::RemoveEntry_guess
    void RemoveEntry_guess(JournalEntry_guess* entry_guess, int name_guess);
};

struct JournalListWnd_guess : CListWnd {
    char pad_140[0x1c];
    unsigned char flag_15c;
    char pad_15d[0xf];
    unsigned long color_16c;
    // EXTERNAL: TITANIUM 0x0059BB50 JournalListWnd_guess::Fill_guess
    void Fill_guess(JournalList_guess* list_guess);
};

struct DataAction_guess;

// EXTERNAL: TITANIUM 0x00656F28 ??_7CJournalNPCWnd_guess@@6B@
struct CJournalNPCWnd_guess : JournalSidlBase_guess {
    int pad_15c;
    JournalData_guess* data_160;
    DataAction_guess* action_164;
    int field_168;
    JournalArray_guess entries_16c;
    int field_17c;
    int field_180;
    int field_184;
    int field_188;
    int field_18c;
    int npcSortColumn_0190_guess;
    bool flag_194;
    int dialogSortColumn_0198_guess;
    bool flag_19c;
    int categoryId_01a0_guess;
    bool flag_1a4;
    bool flag_1a5;
    CXStr text_1a8;
    CXStr text_1ac;
    JournalArray_guess locations_1b0;
    int field_1c0;
    CXWnd* deleteNpcButton_1c4;
    CXWnd* deleteTextButton_1c8;
    CXWnd* saveButton_1cc;
    CXWnd* categoryButton_1d0;
    CXWnd* enableButton_1d4;
    CXWnd* searchButton_1d8;
    CXWnd* categoryFilter_1dc;
    CXWnd* categorySelect_1e0;
    JournalListWnd_guess* npcList_1e4;
    JournalListWnd_guess* dialogList_1e8;
    CXWnd* text_1ec;
    int HandleNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                                 void* data_pointer_guess);
    CJournalNPCWnd_guess(CXWnd* parent);
};

struct DataAction_guess {
    // EXTERNAL: TITANIUM 0x0042EDD7 DataAction_guess::Remove_guess
    void Remove_guess(int value_guess);
};

// The window's WndNotification. Clicks (1): Enable toggles journaling ("Journal Logging Enabled",
// 0x1A46, or "disabled", 0x1A47); turning it off saves first, by setting the flag for the one
// SaveJournal_guess call. CategorySelect sets the selected dialog lines' category; CategoryFilter filters
// NPCs; the Delete buttons remove the selected NPCs or lines. Search clears the search text when there
// is one, else opens a text box ("Enter text to search for", 0xC72, 32 characters) seeded with the last
// one. Column clicks (0xF) sort, a second click on the same column reversing; the text box answers with
// 0x21. 0x59C3A0 is the combo's current choice, not a count.
// FUNCTION: TITANIUM 0x005254BB
// @early-stop: budget, structural ndiff=204
int CJournalNPCWnd_guess::HandleNotification_guess(CXWnd* sender_guess,
                                                   unsigned int message_guess,
                                                   void* data_pointer_guess) {
    CJournalNPCWndView_guess* state_guess = (CJournalNPCWndView_guess*)this;
    int data_guess = (int)data_pointer_guess;

    if (message_guess == 1) {
        if (sender_guess == enableButton_1d4) {
            flag_1a4 = ((CButtonWnd*)enableButton_1d4)->Checked;
            state_guess->StoreIniInfo_guess();
            StringTable* string_table_guess = pStringTable;
            if (flag_1a4) {
                pEverQuest->dsp_chat(string_table_guess->getString(0x1a46, (bool*)0), 0xf, 1);
                data_160->Reset_guess();
                state_guess->LoadJournalFiles_guess(0);
            } else {
                pEverQuest->dsp_chat(string_table_guess->getString(0x1a47, (bool*)0), 0xf, 1);
                flag_1a4 = true;
                state_guess->SaveJournal_guess();
                flag_1a4 = false;
                state_guess->ClearDialogList_guess();
                if (pinstCJournalCatWnd_guess != 0) {
                    pinstCJournalCatWnd_guess->ClearControls_guess();
                }
                data_160->Reset_guess();
                state_guess->RefreshAll_guess(false);
            }
        }

        if (sender_guess == saveButton_1cc) {
            state_guess->SaveJournal_guess();
            return 0;
        }
        if (sender_guess == npcList_1e4) {
            state_guess->SelectNpc_guess(((CListWnd*)npcList_1e4)->GetCurSel());
            return 0;
        }
        if (sender_guess == dialogList_1e8) {
            state_guess->SelectJournalItem_guess(((CListWnd*)dialogList_1e8)->GetCurSel());
            return 0;
        }
        if (sender_guess == categorySelect_1e0) {
            JournalList_guess list_guess;
            if (dialogList_1e8 != 0) {
                JournalListBuffer_guess* buffer_guess = (JournalListBuffer_guess*)&list_guess;
                int index_guess = ((ChoiceWnd_guess*)categorySelect_1e0)->GetCurChoice_guess() - 1;
                LookupName_guess* name_guess = pinstCJournalNPCWnd_guess->table_160->Find_guess(index_guess);
                int value_guess = name_guess != 0 ? name_guess->pad_000 : -1;
                dialogList_1e8->Fill_guess(&list_guess);
                for (int i_guess = 0; i_guess < buffer_guess->count_guess; ++i_guess) {
                    int* block_guess = buffer_guess->blocks_010[i_guess >> buffer_guess->shift_00c];
                    int item_index_guess = block_guess[buffer_guess->mask_008 & i_guess];
                    JournalItem_guess* item_guess = *entries_16c.At_guess(item_index_guess);
                    item_guess->index_014 = value_guess;
                }
            }
            state_guess->UpdateDialogList_guess(true);
            return 0;
        }
        if (sender_guess == categoryFilter_1dc) {
            if (((ChoiceWnd_guess*)categoryFilter_1dc)->GetCurChoice_guess() == 0) {
                categoryId_01a0_guess = -1;
            } else {
                CXStr choice_guess = ((ChoiceWnd_guess*)categoryFilter_1dc)->GetChoice_guess();
                LookupName_guess* name_guess = data_160->FindCategoryByName_guess((char*)choice_guess);
                categoryId_01a0_guess = name_guess != 0 ? name_guess->pad_000 : -1;
            }
            state_guess->RefreshAll_guess(false);
            return 0;
        }
        if (sender_guess == deleteNpcButton_1c4) {
            if (npcList_1e4 != 0) {
                JournalList_guess list_guess;
                JournalListBuffer_guess* buffer_guess = (JournalListBuffer_guess*)&list_guess;
                npcList_1e4->Fill_guess(&list_guess);
                for (int i_guess = 0; i_guess < buffer_guess->count_guess; ++i_guess) {
                    int* block_guess = buffer_guess->blocks_010[i_guess >> buffer_guess->shift_00c];
                    int row_guess = block_guess[buffer_guess->mask_008 & i_guess];
                    JournalEntry_guess* entry_guess = (JournalEntry_guess*)
                        ((CListWnd*)npcList_1e4)->GetItemData(row_guess);
                    data_160->RemoveEntry_guess(entry_guess, entry_guess->name_guess);
                }
                state_guess->ClearDialogList_guess();
                state_guess->RefreshAll_guess(false);
            }
            return 0;
        }
        if (sender_guess == deleteTextButton_1c8) {
            if (npcList_1e4 != 0) {
                JournalList_guess list_guess;
                JournalListBuffer_guess* buffer_guess = (JournalListBuffer_guess*)&list_guess;
                if (dialogList_1e8 != 0) {
                    dialogList_1e8->Fill_guess(&list_guess);
                    for (int i_guess = 0; i_guess < buffer_guess->count_guess; ++i_guess) {
                        int* block_guess = buffer_guess->blocks_010[i_guess >> buffer_guess->shift_00c];
                        int row_guess = block_guess[buffer_guess->mask_008 & i_guess];
                        JournalItem_guess* item_guess = *entries_16c.At_guess(row_guess);
                        action_164->Remove_guess(item_guess->textHash_0004_guess);
                    }
                }
                // Unlike the block above, this does not check that the dialog list exists.
                ((CListWnd*)dialogList_1e8)->ClearAllSel();
                field_180 = 0;
                state_guess->RefreshAll_guess(false);
            }
            return 0;
        }
        if (sender_guess == categoryButton_1d0) {
            pinstCJournalCatWnd_guess->Activate();
            return 0;
        }
        if (sender_guess == searchButton_1d8) {
            if (text_1a8.Ptr != 0) {
                text_1ac = text_1a8;
                text_1a8.~CXStr();
                state_guess->RefreshAll_guess(true);
            } else {
                pinstCTextEntryWnd_guess->Activate_guess(
                    this, 0, pStringTable->getString(0xc72, 0), 1, 0x20,
                    (char*)text_1ac);
            }
            return 0;
        }
    } else if (message_guess == 0xf) {
        if (sender_guess == npcList_1e4) {
            int mode_guess = 0;
            if (data_guess != 0) {
                mode_guess = data_guess == 1 ? 2 : 3;
            }
            bool toggle_guess = true;
            if (npcSortColumn_0190_guess == mode_guess) {
                toggle_guess = !flag_194;
            }
            npcSortColumn_0190_guess = mode_guess;
            flag_194 = toggle_guess;
            state_guess->SortNpcList_guess(mode_guess, toggle_guess);
            state_guess->FillLocationList_guess(false);
            return 0;
        }
        if (sender_guess == dialogList_1e8) {
            int mode_guess = data_guess == 1 ? 2 : 0;
            bool toggle_guess = true;
            if (dialogSortColumn_0198_guess == mode_guess) {
                toggle_guess = !flag_19c;
            }
            dialogSortColumn_0198_guess = mode_guess;
            flag_19c = toggle_guess;
            state_guess->SortDialogList_guess(mode_guess, toggle_guess);
            state_guess->FillJournalList_guess(false);
            return 0;
        }
        return 0;
    } else if (message_guess == 0x21) {
        if (data_guess != 0) {
            {
                CXStr event_text_guess = pinstCTextEntryWnd_guess->GetEntryText_guess();
                text_1a8 = event_text_guess;
            }
            state_guess->RefreshAll_guess(false);
        } else if (searchButton_1d8 != 0) {
            ((CButtonWnd*)searchButton_1d8)->SetCheck(false);
        }
        return 0;
    }

    return ((JournalSidlBase_guess*)this)->WndNotification(
        sender_guess, message_guess, data_pointer_guess);
}

// CJournalNPCWnd::CJournalNPCWnd. Defaults: backups every 60 minutes, 3 kept; NPCs sorted by time
// (mode 3), dialog by time (mode 0), both ascending. Both lists get the same colours and multi-select
// (0x20000); then the saved setting and journal are loaded.
// FUNCTION: TITANIUM 0x005259CA
CJournalNPCWnd_guess::CJournalNPCWnd_guess(CXWnd* parent)
    : JournalSidlBase_guess(parent, "JournalNPCWnd", -0x201, 1, 0) {
    deleteNpcButton_1c4 = 0;
    deleteTextButton_1c8 = 0;
    saveButton_1cc = 0;
    categoryButton_1d0 = 0;
    searchButton_1d8 = 0;
    categoryFilter_1dc = 0;
    categorySelect_1e0 = 0;
    npcList_1e4 = 0;
    dialogList_1e8 = 0;
    text_1ec = 0;
    data_160 = 0;
    data_160 = new JournalData_guess;
    categoryId_01a0_guess = -1;
    field_168 = 0;
    field_184 = 0;
    field_188 = 0x3c;
    field_18c = 3;
    field_1c0 = 0;
    action_164 = 0;
    field_17c = 0;
    field_180 = 0;
    flag_1a4 = false;
    flag_1a5 = true;
    npcSortColumn_0190_guess = 3;
    flag_194 = true;
    dialogSortColumn_0198_guess = 0;
    flag_19c = true;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= 0x10800;
        field_158 = 0xe;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        deleteNpcButton_1c4 = ((CSidlScreenWnd*)this)->GetChildItem("DeleteNPCButton");
        deleteTextButton_1c8 = ((CSidlScreenWnd*)this)->GetChildItem("DeleteTextButton");
        saveButton_1cc = ((CSidlScreenWnd*)this)->GetChildItem("SaveButton");
        categoryButton_1d0 = ((CSidlScreenWnd*)this)->GetChildItem("CategoryButton");
        enableButton_1d4 = ((CSidlScreenWnd*)this)->GetChildItem("EnableButton");
        searchButton_1d8 = ((CSidlScreenWnd*)this)->GetChildItem("SearchButton");
        categoryFilter_1dc = ((CSidlScreenWnd*)this)->GetChildItem("CategoryFilter");
        categorySelect_1e0 = ((CSidlScreenWnd*)this)->GetChildItem("CategorySelect");
        npcList_1e4 = (JournalListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("NPCList");
        dialogList_1e8 = (JournalListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("DialogList");
        text_1ec = ((CSidlScreenWnd*)this)->GetChildItem("Text");
        if (npcList_1e4 != 0) {
            npcList_1e4->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            npcList_1e4->color_16c = 0xff8aa3ff;
            npcList_1e4->flag_15c = 1;
            npcList_1e4->WindowStyle |= 0x20000;
        }
        if (dialogList_1e8 != 0) {
            dialogList_1e8->color_16c = 0xff8aa3ff;
            dialogList_1e8->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            dialogList_1e8->flag_15c = 1;
            dialogList_1e8->WindowStyle |= 0x20000;
        }
        text_1a8.~CXStr();
        text_1ac.~CXStr();
        ((CJournalNPCWndView_guess*)this)->ReloadJournal_guess();
    }
}

// Constructor tail of another window (vtable 0x657100): base setup, then +0x124 from the last argument.
// FUNCTION: TITANIUM 0x00525E53
CJournalNPCWndView_guess* CJournalNPCWndView_guess::Initialize_guess(int first, int second, int third,
                                             int fourth, int fifth, int sixth, int seventh) {
    Setup_guess(first, second, &third);
    value_124 = seventh;
    vtable = (int)&g_vtable_guess;
    return this;
}
