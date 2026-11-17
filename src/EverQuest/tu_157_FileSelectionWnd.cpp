// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 157: a hint from compare/tumap.py.
// CFeedbackWnd's send handler, then CFileSelectionWnd ("FileSelectionWnd"): a file picker over the Windows
// shell namespace, starting at My Computer, with a stack of up to 128 open folders (IShellFolder, name,
// PIDL). CFileSelectionWnd_guess, RequestState_guess, RefreshState_guess, FileBrowser_guess, QueryOwner_guess and
// Big_guess all view that window; the TAKP names in names.tsv (updateFileDialogButtonStates, ...) agree with
// the bodies.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <windows.h>
#include <shlobj.h>

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
// EXTERNAL: TITANIUM 0x0060EE40 qsort
extern "C" void __cdecl qsort(void* base_guess, unsigned int count_guess, unsigned int size_guess,
    int (__cdecl* compare_guess)(const void*, const void*));
// EXTERNAL: TITANIUM 0x005018B8 CompareEntries_guess
int __cdecl CompareEntries_guess(const void* left_guess, const void* right_guess);

#define g_hwnd_guess EQ_GLOBAL(HWND, 0x00923770)

struct EnumList_guess;
typedef unsigned long (__stdcall *EnumRelease_guess)(EnumList_guess*);
typedef int (__stdcall *EnumNext_guess)(EnumList_guess*, unsigned long, int*, unsigned long*);

struct EnumVtable_guess {
    void* slots00_guess[2];
    EnumRelease_guess Release_guess;
    EnumNext_guess Next_guess;
};

struct EnumList_guess {
    EnumVtable_guess* vtable_guess;
};

struct CFileSelectionWnd_guess;
struct ResourceList_guess;
struct StringValue_guess;
struct Tiny_guess;

struct QueryBuffer_guess {
    int result_guess;
    union {
        char* pointer_guess;
        int text_guess[0x41];
    } value_guess;
};

struct QueryInterface_guess;
typedef void (__stdcall *QueryRelease_guess)(QueryInterface_guess*);
typedef void (__stdcall *QueryCall_guess)(QueryInterface_guess*, int, unsigned int, QueryBuffer_guess*);
typedef int (__stdcall *QueryAcquire_guess)(QueryInterface_guess*, int, int, const char*, QueryInterface_guess**);
typedef int (__stdcall *QueryEnum_guess)(QueryInterface_guess*, HWND, unsigned long, EnumList_guess**);
typedef int (__stdcall *QueryAttributes_guess)(QueryInterface_guess*, unsigned int, int*, unsigned long*);

struct QueryVtable_guess {
    void* slots00_guess[4];
    QueryEnum_guess Slot04_guess;
    QueryAcquire_guess Slot05_guess;
    void* slots06_guess[3];
    QueryAttributes_guess Slot09_guess;
    void* slot10_guess;
    QueryCall_guess Slot11_guess;
};

struct QueryInterface_guess {
    QueryVtable_guess* vtable_guess;
};

struct EventView_guess {
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
    virtual CXStr Get_guess();
};

struct StringValue_guess;

struct CXStrView_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 CXStrView_guess::CXStrView_guess
    CXStrView_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571DC0 ??0CXStrView_guess@@QAE@D@Z
    CXStrView_guess(char value_guess);
    // EXTERNAL: TITANIUM 0x00573B10 CXStrView_guess::Check_guess
    int Check_guess(const StringValue_guess& value_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00571D00 CXStrView_guess::Release_guess
    void Release_guess(void* value_guess);
    ~CXStrView_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
        value_guess = 0;
    }
};

struct StringValue_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0StringValue_guess@@QAE@PBD@Z
    StringValue_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571DC0 StringValue_guess::StringValue_guess
    StringValue_guess(char value_guess);
    StringValue_guess() : value_guess(0) {}
    // EXTERNAL: TITANIUM 0x00572200 StringValue_guess::Insert_guess
    void Insert_guess(int index_guess, char value_guess);
    // EXTERNAL: TITANIUM 0x00572C10 ?Append_guess@StringValue_guess@@QAEXABU1@@Z
    void Append_guess(const StringValue_guess& value_guess);
    // EXTERNAL: TITANIUM 0x00572C10 ?Append_guess@StringValue_guess@@QAEXABUCXStrView_guess@@@Z
    void Append_guess(const CXStrView_guess& value_guess);
    // EXTERNAL: TITANIUM 0x00572300 StringValue_guess::Text_guess
    const char* Text_guess();
    // EXTERNAL: TITANIUM 0x00571D00 StringValue_guess::Release_guess
    void Release_guess(void* value_guess);
    ~StringValue_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
    }
};

struct TempString_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00571F00 TempString_guess::TempString_guess
    TempString_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571D00 TempString_guess::Release_guess
    void Release_guess(void* value_guess);
    ~TempString_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
    }
};

struct Tiny_guess {
    // EXTERNAL: TITANIUM 0x004482FB Tiny_guess::~Tiny_guess
    ~Tiny_guess();
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571FC0 Tiny_guess::SetText_guess
    void SetText_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571F70 Tiny_guess::SetValue_guess
    void SetValue_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x00573B10 Tiny_guess::Compare_guess
    int Compare_guess(const CXStrView_guess& value_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00572380 Tiny_guess::Find_guess
    bool Find_guess(int id_guess, void** value_guess);
};

struct Entry_guess {
    Tiny_guess name_guess;
    int id_guess;
    unsigned long attributes_guess;
    Entry_guess() { name_guess.value_guess = 0; }
};

struct Child_guess {
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
    virtual void Slot32_guess(CFileSelectionWnd_guess*, int, int*);
    // EXTERNAL: TITANIUM 0x0059EDF0 Child_guess::SetFocus
    void SetFocus();
};

struct Service_guess {
    // EXTERNAL: TITANIUM 0x005AE150 Service_guess::Value_guess
    int Value_guess();
};

#define pinstCXWndManager_guess EQ_GLOBAL(Service_guess*, 0x0099D3EC)

struct CFileSelectionWnd_guess {
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
    char padding_guess[0x15c];
    Child_guess* child_guess;
    ResourceList_guess* list_guess;
    int state_guess;
    CXStrView_guess Left_guess(int argument_guess);
    void Close_guess(int argument_guess);
    void ClearFileList_guess();
    bool Update_guess();
};

struct ResourceList_guess {
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
    char padding_guess[0x118];
    int count_guess;
    void* entries_guess;
    // EXTERNAL: TITANIUM 0x00597ED0 ResourceList_guess::GetItemData
    void* GetItemData(int index_guess);
    // EXTERNAL: TITANIUM 0x00598580 ResourceList_guess::ClearAllSel
    void ClearAllSel();
    // EXTERNAL: TITANIUM 0x0059C3A0 ResourceList_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059BB50 ResourceList_guess::Collect_guess
    void Collect_guess(void* entries_guess);
    // EXTERNAL: TITANIUM 0x0059C130 ResourceList_guess::Commit_guess
    void Commit_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0059C3E0 ResourceList_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 ResourceList_guess::AddPath_guess
    void AddPath_guess(Tiny_guess* path_guess);
    // EXTERNAL: TITANIUM 0x0059C360 ResourceList_guess::Select_guess
    void Select_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0059B9D0 ResourceList_guess::AddString
    int AddString(Entry_guess* entry_guess, unsigned long color_guess, int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00598620 ResourceList_guess::SetItemData
    void SetItemData(int handle_guess, int data_guess);
};

struct Malloc_guess;
typedef void (__stdcall *MallocRelease_guess)(Malloc_guess*);
typedef void (__stdcall *MallocFree_guess)(Malloc_guess*, void*);

struct MallocVtable_guess {
    void* slots00_guess[2];
    MallocRelease_guess Release_guess;
    void* slots03_guess[2];
    MallocFree_guess Free_guess;
};

struct Malloc_guess {
    MallocVtable_guess* lpVtbl_guess;
};

typedef int (__stdcall *SHGetMalloc_guess)(Malloc_guess**);
#define g_SHGetMalloc_guess EQ_GLOBAL(SHGetMalloc_guess, 0x0063F22C)

struct QueryResult_guess;

struct QueryResult_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00573B10 QueryResult_guess::Check_guess
    int Check_guess(StringValue_guess* value_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00571D00 QueryResult_guess::Release_guess
    void Release_guess(void* value_guess);
    ~QueryResult_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
        value_guess = 0;
    }
};

struct QuerySource_guess {
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
    virtual void Slot63_guess(StringValue_guess& value_guess);
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
    virtual QueryResult_guess Slot76_guess();
    // EXTERNAL: TITANIUM 0x0059EDF0 QuerySource_guess::SetFocus
    void SetFocus();
};

struct StateFlag_guess {
    char padding_guess[0x5d];
    unsigned char enabled_guess;
};

struct RefreshState_guess {
    char padding_000_guess[0x168];
    QuerySource_guess* source_guess;
    char padding_16c_guess[4];
    StateFlag_guess* secondary_guess;
    StateFlag_guess* primary_guess;
    char padding_178_guess[0x67c];
    int count_guess;
    void UpdateButtons_guess();
};

// EXTERNAL: TITANIUM 0x00573250 MakeResult_guess
CXStrView_guess __stdcall MakeResult_guess(int first_guess, int second_guess);

struct RequestState_guess {
    char padding_000_guess[0x164];
    ResourceList_guess* list_guess;      // 0x164
    QuerySource_guess* view_guess;       // 0x168
    ResourceList_guess* tree_guess;      // 0x16c
    int selected_guess;                  // 0x170
    CXWnd* primary_guess;                // 0x174
    CXWnd* secondary_guess;              // 0x178
    char padding_17c_guess[4];
    Tiny_guess label_guess;              // 0x180
    QueryInterface_guess* source_guess;
    Tiny_guess current_guess;
    char padding_18c_guess[0x68];
    QueryInterface_guess* sources_guess[0x80];
    Tiny_guess values_guess[0x80];
    int ids_guess[0x80];
    int count_guess;
    Tiny_guess message_guess;
    int GetDisplayName_guess(QueryInterface_guess* source_guess, int id_guess, bool wide_guess, Tiny_guess* result_guess);
    void EnterFolder_guess(int id_guess);
    bool IsFolderEmpty_guess(QueryInterface_guess* source_guess, int id_guess);
    void Populate_guess();
    void BuildFolderPath_guess();
    // EXTERNAL: TITANIUM 0x005A2230 RequestState_guess::WndNotification
    int WndNotification(void* item_guess, int event_guess, int data_guess);
    int WndNotification_guess(CXWnd* item_guess, int event_guess, int data_guess);
};

/* ---- FeedbackWnd: 0x0050157C (input 0x160, cancel 0x164, send 0x168) ---- */

// EXTERNAL: TITANIUM 0x0060E450 strcpy

struct FeedbackString_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0FeedbackString_guess@@QAE@PBD@Z
    FeedbackString_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571D00 FeedbackString_guess::Release_guess
    void Release_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x00572300 ??BFeedbackString_guess@@QBEPADXZ
    operator char*() const;
    ~FeedbackString_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
    }
};

// Same four-byte string, without the automatic destructor: the condition releases it explicitly.
struct FeedbackText_guess {
    void* value_guess;
    // EXTERNAL: TITANIUM 0x00571D00 FeedbackText_guess::Release_guess
    void Release_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x004D95D0 FeedbackText_guess::IsEmpty_guess
    bool IsEmpty_guess();
};

struct FeedbackPacket_guess {
    char name_000_guess[0x40];          // 0x000
    char field_040_guess[0x20];         // 0x040
    float y_060_guess;                  // 0x060
    float x_064_guess;                  // 0x064
    float z_068_guess;                  // 0x068
    int heading_06c_guess;              // 0x06C
    int field_070_guess[2];             // 0x070
    char text_078_guess[0x404];         // 0x078
};

// pCharData (0x00905D00): the character name is in the virtual base, reached through the vbptr at +8.
struct FeedbackCharPrefix_guess {
    virtual void Slot00_guess();
    int field_004_guess;
};

#include "titanium/layouts/core.h"

struct FeedbackCharData_guess : FeedbackCharPrefix_guess, virtual FeedbackCharBase_guess {
};

#define g_feedbackCharData_guess EQ_GLOBAL(FeedbackCharData_guess*, 0x00905D00)
#define g_feedbackPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_feedbackConnection_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_feedbackEmpty_guess EQ_ARRAY(char, 0x0063F53F)

// Virtual view of the feedback edit box: slot 63 (+0xFC) sets its text, slot 76 (+0x130) returns it.
struct FeedbackInputVt_guess {
    virtual void S00(); virtual void S01(); virtual void S02(); virtual void S03();
    virtual void S04(); virtual void S05(); virtual void S06(); virtual void S07();
    virtual void S08(); virtual void S09(); virtual void S10(); virtual void S11();
    virtual void S12(); virtual void S13(); virtual void S14(); virtual void S15();
    virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23();
    virtual void S24(); virtual void S25(); virtual void S26(); virtual void S27();
    virtual void S28(); virtual void S29(); virtual void S30(); virtual void S31();
    virtual void S32(); virtual void S33(); virtual void S34(); virtual void S35();
    virtual void S36(); virtual void S37(); virtual void S38(); virtual void S39();
    virtual void S40(); virtual void S41(); virtual void S42(); virtual void S43();
    virtual void S44(); virtual void S45(); virtual void S46(); virtual void S47();
    virtual void S48(); virtual void S49(); virtual void S50(); virtual void S51();
    virtual void S52(); virtual void S53(); virtual void S54(); virtual void S55();
    virtual void S56(); virtual void S57(); virtual void S58(); virtual void S59();
    virtual void S60(); virtual void S61(); virtual void S62();
    virtual void Slot63_guess(const FeedbackString_guess& text_guess);
    virtual void S64(); virtual void S65(); virtual void S66(); virtual void S67();
    virtual void S68(); virtual void S69(); virtual void S70(); virtual void S71();
    virtual void S72(); virtual void S73(); virtual void S74(); virtual void S75();
    virtual FeedbackString_guess Slot76_guess();
};

struct FeedbackInputCondVt_guess {
    virtual void S00(); virtual void S01(); virtual void S02(); virtual void S03();
    virtual void S04(); virtual void S05(); virtual void S06(); virtual void S07();
    virtual void S08(); virtual void S09(); virtual void S10(); virtual void S11();
    virtual void S12(); virtual void S13(); virtual void S14(); virtual void S15();
    virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23();
    virtual void S24(); virtual void S25(); virtual void S26(); virtual void S27();
    virtual void S28(); virtual void S29(); virtual void S30(); virtual void S31();
    virtual void S32(); virtual void S33(); virtual void S34(); virtual void S35();
    virtual void S36(); virtual void S37(); virtual void S38(); virtual void S39();
    virtual void S40(); virtual void S41(); virtual void S42(); virtual void S43();
    virtual void S44(); virtual void S45(); virtual void S46(); virtual void S47();
    virtual void S48(); virtual void S49(); virtual void S50(); virtual void S51();
    virtual void S52(); virtual void S53(); virtual void S54(); virtual void S55();
    virtual void S56(); virtual void S57(); virtual void S58(); virtual void S59();
    virtual void S60(); virtual void S61(); virtual void S62(); virtual void S63();
    virtual void S64(); virtual void S65(); virtual void S66(); virtual void S67();
    virtual void S68(); virtual void S69(); virtual void S70(); virtual void S71();
    virtual void S72(); virtual void S73(); virtual void S74(); virtual void S75();
    virtual FeedbackText_guess Slot76_guess();
};

struct FeedbackInputClearVt_guess {
    virtual void S00(); virtual void S01(); virtual void S02(); virtual void S03();
    virtual void S04(); virtual void S05(); virtual void S06(); virtual void S07();
    virtual void S08(); virtual void S09(); virtual void S10(); virtual void S11();
    virtual void S12(); virtual void S13(); virtual void S14(); virtual void S15();
    virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23();
    virtual void S24(); virtual void S25(); virtual void S26(); virtual void S27();
    virtual void S28(); virtual void S29(); virtual void S30(); virtual void S31();
    virtual void S32(); virtual void S33(); virtual void S34(); virtual void S35();
    virtual void S36(); virtual void S37(); virtual void S38(); virtual void S39();
    virtual void S40(); virtual void S41(); virtual void S42(); virtual void S43();
    virtual void S44(); virtual void S45(); virtual void S46(); virtual void S47();
    virtual void S48(); virtual void S49(); virtual void S50(); virtual void S51();
    virtual void S52(); virtual void S53(); virtual void S54(); virtual void S55();
    virtual void S56(); virtual void S57(); virtual void S58(); virtual void S59();
    virtual void S60(); virtual void S61(); virtual void S62();
    virtual void Slot63_guess(const CXStr& text_guess);
};

struct FeedbackWndBase_guess {
    virtual void S00(); virtual void S01(); virtual void S02(); virtual void S03();
    virtual void S04(); virtual void S05(); virtual void S06(); virtual void S07();
    virtual void S08(); virtual void S09(); virtual void S10(); virtual void S11();
    virtual void S12(); virtual void S13(); virtual void S14(); virtual void S15();
    virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23();
    virtual void S24(); virtual void S25(); virtual void S26(); virtual void S27();
    virtual void S28(); virtual void S29(); virtual void S30(); virtual void S31();
    virtual void S32(); virtual void S33();
    virtual void Slot34_guess();
    char padding_guess[0x15c];
};

struct FeedbackWnd_guess : FeedbackWndBase_guess {
    CXWnd* input_160_guess;             // 0x160
    CXWnd* cancel_164_guess;            // 0x164
    CXWnd* send_168_guess;              // 0x168
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
};

// Send: with text typed, sends OP_Feedback (0x5306) with name, position, heading and text, then clears and
// hides; Cancel clears and hides.
// FUNCTION: TITANIUM 0x0050157C
// @early-stop: name-conflict, diff ndiff=1
int FeedbackWnd_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess) {
    if (sender_guess == send_168_guess && message_guess == 1) {
        bool not_empty_guess;
        {
            FeedbackText_guess text_guess(((FeedbackInputCondVt_guess*)input_160_guess)->Slot76_guess());
            not_empty_guess = !text_guess.IsEmpty_guess();
            if (text_guess.value_guess != 0) {
                text_guess.Release_guess(text_guess.value_guess);
            }
        }
        if (not_empty_guess) {
            FeedbackPacket_guess packet_guess;
            strcpy(packet_guess.name_000_guess, g_feedbackCharData_guess->Name);
            strcpy(packet_guess.field_040_guess, g_feedbackEmpty_guess);
            packet_guess.y_060_guess = g_feedbackPlayer_guess->Y;
            packet_guess.x_064_guess = g_feedbackPlayer_guess->X;
            packet_guess.z_068_guess = g_feedbackPlayer_guess->Z;
            packet_guess.heading_06c_guess = (int)g_feedbackPlayer_guess->Heading;
            strcpy(packet_guess.text_078_guess, ((FeedbackInputVt_guess*)input_160_guess)->Slot76_guess());
            // 0x47C bytes: name 0x40, an empty 0x20 field, y/x/z, heading, 8 unused, text 0x404.
            EQSendMessage(&g_feedbackConnection_guess, OP_Feedback, &packet_guess, 0x47c, 1);
            ((FeedbackInputVt_guess*)input_160_guess)->Slot63_guess(g_feedbackEmpty_guess);
        }
        Slot34_guess();
        return 0;
    }
    if (sender_guess == cancel_164_guess && message_guess == 1) {
        {
            CXStr empty_guess(g_feedbackEmpty_guess);
            ((FeedbackInputClearVt_guess*)input_160_guess)->Slot63_guess(empty_guess);
        }
        Slot34_guess();
        return 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}

// The first `argument_guess` characters of a CXStr (Mid(0, n)); not a CFileSelectionWnd_guess method (misnamed view).
// FUNCTION: TITANIUM 0x0050176F
CXStrView_guess CFileSelectionWnd_guess::Left_guess(int argument_guess) {
    return MakeResult_guess(0, argument_guess);
}

struct LengthData_guess {
    int pad_guess[2];
    int length_guess;
};

struct LengthHolder_guess {
    LengthData_guess* data_guess;
    int Length_guess() { return data_guess ? data_guess->length_guess : 0; }
    CXStrView_guess Right_guess(int start_guess);
    // EXTERNAL: TITANIUM 0x00573250 LengthHolder_guess::Mid_guess
    CXStrView_guess Mid_guess(int start_guess, int count_guess);
};

// The last `start_guess` characters (the whole string when it is shorter).
// FUNCTION: TITANIUM 0x0050178B
CXStrView_guess LengthHolder_guess::Right_guess(int start_guess) {
    if (start_guess >= Length_guess()) {
        return Mid_guess(0, 0xffff);
    }
    return Mid_guess(Length_guess() - start_guess, 0xffff);
}

// Closes the picker: sends the requester (+0x160) notification 0x22 with 1 (accepted) or 0 (cancelled),
// then hides.
// FUNCTION: TITANIUM 0x005017D1
void CFileSelectionWnd_guess::Close_guess(int argument_guess) {
    if (child_guess != 0) {
        child_guess->Slot32_guess(this, 0x22, &argument_guess);
    }
    Slot34_guess();
}

// OK is enabled unless Entry shows the computer root; UpButton once below the top folder.
// FUNCTION: TITANIUM 0x005017FF
void RefreshState_guess::UpdateButtons_guess() {
    if (primary_guess != 0) {
        bool enabled_guess = true;
        if (source_guess != 0) {
            StringValue_guess name_guess("My Computer");
            enabled_guess = source_guess->Slot76_guess().Check_guess(&name_guess, 0);
        }
        primary_guess->enabled_guess = enabled_guess;
    }
    if (secondary_guess != 0) {
        secondary_guess->enabled_guess = count_guess > 0;
    }
}

// Frees the PIDL kept as each FileList row's item data, then empties the list.
// FUNCTION: TITANIUM 0x005018FC
void CFileSelectionWnd_guess::ClearFileList_guess() {
    int index_guess = 0;
    if (list_guess != 0) {
        if (list_guess->count_guess > 0) {
            Malloc_guess* allocator_guess;
            g_SHGetMalloc_guess(&allocator_guess);
            if (list_guess->count_guess > 0) {
                do {
                    void* item_guess = list_guess->GetItemData(index_guess);
                    allocator_guess->lpVtbl_guess->Free_guess(allocator_guess, item_guess);
                    ++index_guess;
                } while (index_guess < list_guess->count_guess);
            }
            allocator_guess->lpVtbl_guess->Release_guess(allocator_guess);
        }
        list_guess->ClearAllSel();
        list_guess->Slot76_guess();
    }
}

// Display name of item `id_guess` in a folder (IShellFolder::GetDisplayNameOf); returns 1 on an unknown
// STRRET type.
// FUNCTION: TITANIUM 0x00501975
int RequestState_guess::GetDisplayName_guess(QueryInterface_guess* source_guess, int id_guess, bool wide_guess, Tiny_guess* result_guess) {
    int status_guess = 0;
    QueryBuffer_guess buffer_guess;
    result_guess->~Tiny_guess();
    if (wide_guess) {
        // SHGDN_FORPARSING (full path) when `wide_guess`, else SHGDN_INFOLDER (1).
        source_guess->vtable_guess->Slot11_guess(source_guess, id_guess, 0x8000, &buffer_guess);
    }
    else {
        source_guess->vtable_guess->Slot11_guess(source_guess, id_guess, 1, &buffer_guess);
    }
    switch (buffer_guess.result_guess) {
    // STRRET_WSTR: the shell's string is copied but never CoTaskMemFree'd.
    case 0: {
        TempString_guess value_guess(buffer_guess.value_guess.pointer_guess);
        result_guess->SetValue_guess(&value_guess);
        break;
    }
    case 1:
        result_guess->SetText_guess(buffer_guess.value_guess.pointer_guess + id_guess);
        break;
    case 2:
        result_guess->SetText_guess(reinterpret_cast<const char*>(buffer_guess.value_guess.text_guess));
        break;
    default:
        status_guess = 1;
    }
    return status_guess;
}

// Hide hook: hands the focus back to the requester if Entry has it, and frees the list.
// FUNCTION: TITANIUM 0x00501A2C
bool CFileSelectionWnd_guess::Update_guess() {
    if (pinstCXWndManager_guess->Value_guess() == state_guess && child_guess != 0) {
        child_guess->SetFocus();
    }
    ClearFileList_guess();
    return true;
}

// Builds the chosen folder's path in +0x7F8 with a trailing separator; at the top it asks Windows for
// the CSIDL_DRIVES path.
// FUNCTION: TITANIUM 0x00501A5C
void RequestState_guess::BuildFolderPath_guess() {
    CXStr error_guess("error");
    message_guess.~Tiny_guess();
    if (count_guess == 0) {
        char path_guess[260];
        // CSIDL_DRIVES (My Computer), which has no file-system path, so this probably fails.
        SHGetSpecialFolderPathA(g_hwnd_guess, path_guess, 0x11, 0);
        strcat(path_guess, EQ_ARRAY(char, 0x0064217C));
        message_guess.SetText_guess(path_guess);
        error_guess = path_guess;
    }
    else {
        GetDisplayName_guess(sources_guess[count_guess - 1], ids_guess[count_guess], true,
            reinterpret_cast<Tiny_guess*>(&error_guess));
        bool ok_guess = reinterpret_cast<LengthHolder_guess*>(&error_guess)->Right_guess(1).Check_guess(
            EQ_ARRAY(char, 0x0064217C), 0) != 0;
        if (ok_guess) {
            reinterpret_cast<StringValue_guess*>(&error_guess)->Append_guess(
                CXStrView_guess(EQ_ARRAY(char, 0x0064217C)));
        }
        message_guess.SetValue_guess(&error_guess);
    }
}

// Opens subfolder `id_guess` (BindToObject, IID_IShellFolder at 0x66C968) and pushes it on the stack.
// FUNCTION: TITANIUM 0x00501C21
void RequestState_guess::EnterFolder_guess(int id_guess) {
    QueryInterface_guess* next_guess = 0;
    int status_guess = source_guess->vtable_guess->Slot05_guess(
        source_guess, id_guess, 0, EQ_ARRAY(char, 0x0066C968), &next_guess);
    if (status_guess >= 0) {
        ++count_guess;
        GetDisplayName_guess(source_guess, id_guess, false, &current_guess);
        source_guess = next_guess;
        sources_guess[count_guess] = next_guess;
        values_guess[count_guess].SetValue_guess(&current_guess);
        ids_guess[count_guess] = id_guess;
    }
}

// Whether a folder should be hidden: true when listing it with FindFirstFile finds nothing. Paths whose
// first two characters match 0x6543CC (probably drive or network roots) are always kept.
// FUNCTION: TITANIUM 0x00501CA7
bool RequestState_guess::IsFolderEmpty_guess(QueryInterface_guess* source_guess, int id_guess) {
    bool missing_guess = true;
    StringValue_guess path_guess;
    int status_guess = GetDisplayName_guess(source_guess, id_guess, true, reinterpret_cast<Tiny_guess*>(&path_guess));
    if (status_guess >= 0) {
        if (reinterpret_cast<CFileSelectionWnd_guess*>(&path_guess)->Left_guess(2).Check_guess(
                StringValue_guess(EQ_ARRAY(char, 0x006543CC)), 0) == 0) {
            return false;
        }
        if (reinterpret_cast<LengthHolder_guess*>(&path_guess)->Right_guess(1).Check_guess(
                '\\', 0) != 0) {
            path_guess.Append_guess(StringValue_guess('\\'));
        }
        path_guess.Append_guess(CXStrView_guess(EQ_ARRAY(char, 0x006543C8)));
        WIN32_FIND_DATAA data_guess;
        HANDLE find_guess = FindFirstFileA(path_guess.Text_guess(), &data_guess);
        if (find_guess != INVALID_HANDLE_VALUE) {
            FindClose(find_guess);
            missing_guess = false;
        }
    }
    return missing_guess;
}

struct FileSelectionTable_guess {
    int count_guess;
    int pad_004_guess[6];
    FileSelectionTable_guess() { Initialize_guess(0x20); }
    // EXTERNAL: TITANIUM 0x0047C3AF FileSelectionTable_guess::Initialize_guess
    void Initialize_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E FileSelectionTable_guess::~FileSelectionTable_guess
    ~FileSelectionTable_guess();
};

struct FileSelectionText_guess {
    int value_guess;
    FileSelectionText_guess() : value_guess(0) {}
    // EXTERNAL: TITANIUM 0x004482FB FileSelectionText_guess::~FileSelectionText_guess
    ~FileSelectionText_guess();
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x00654408 ??_7FileSelectionWnd_guess@@6B@
struct FileSelectionWnd_guess : CSidlScreenWndBase {
    int field_15c_guess;                    // 0x15c
    int folder_160_guess;                   // 0x160
    CXWnd* fileList_guess;                  // 0x164
    CXWnd* entry_guess;                     // 0x168
    CXWnd* dirHistory_guess;                // 0x16c
    CXWnd* upButton_guess;                  // 0x170
    CXWnd* okButton_guess;                  // 0x174
    CXWnd* cancelButton_guess;              // 0x178
    int field_17c_guess;                    // 0x17c
    FileSelectionText_guess label_guess;    // 0x180
    IShellFolder* source_guess;             // 0x184
    CXStr current_guess;                    // 0x188
    char gap_18c_guess[0x68];
    IShellFolder* sources_guess[0x80];      // 0x1f4
    CXStr values_guess[0x80];               // 0x3f4
    LPITEMIDLIST ids_guess[0x80];           // 0x5f4
    int count_guess;                        // 0x7f4
    CXStr message_guess;                    // 0x7f8
    FileSelectionTable_guess table_guess;   // 0x7fc
    FileSelectionWnd_guess(CXWnd* parent_guess);
};

// Starts at My Computer (CSIDL_DRIVES) as stack entry 0, then finds the seven controls.
// FUNCTION: TITANIUM 0x00501EA9
// @early-stop: budget, structural ndiff=9
FileSelectionWnd_guess::FileSelectionWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "FileSelectionWnd") {
    fileList_guess = 0;
    entry_guess = 0;
    dirHistory_guess = 0;
    upButton_guess = 0;
    okButton_guess = 0;
    cancelButton_guess = 0;
    folder_160_guess = 0;
    count_guess = 0;
    IMalloc* allocator_guess;
    IShellFolder* desktop_guess;
    SHGetMalloc(&allocator_guess);
    SHGetDesktopFolder(&desktop_guess);
    label_guess.~FileSelectionText_guess();
    LPITEMIDLIST pidl_guess = 0;
    SHGetSpecialFolderLocation(g_hwnd_guess, CSIDL_DRIVES, &pidl_guess);
    IShellFolder* folder_guess;
    desktop_guess->BindToObject(pidl_guess, 0, *(const IID*)EQ_ARRAY(char, 0x0066C968),
        (void**)&folder_guess);
    ((RequestState_guess*)this)->GetDisplayName_guess((QueryInterface_guess*)desktop_guess,
        (int)pidl_guess, false, (Tiny_guess*)&current_guess);
    source_guess = folder_guess;
    sources_guess[0] = folder_guess;
    values_guess[0] = current_guess;
    ids_guess[0] = pidl_guess;
    desktop_guess->Release();
    allocator_guess->Free(pidl_guess);
    allocator_guess->Release();
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        fileList_guess = ((CSidlScreenWnd*)this)->GetChildItem("FileList");
        entry_guess = ((CSidlScreenWnd*)this)->GetChildItem("Entry");
        dirHistory_guess = ((CSidlScreenWnd*)this)->GetChildItem("DirHistory");
        upButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("UpButton");
        okButton_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x006543D8));
        cancelButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("Cancel");
        FUN_0059db90_guess(199);
        if (fileList_guess != 0) {
            ((CListWnd*)fileList_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            fileList_guess->WindowStyle &= ~0x200000;
        }
    }
}

// Shows the current folder: empties Entry, rebuilds DirHistory from the stack, then lists up to 10240
// items, folders as [name] (empty ones skipped), sorted except at My Computer, each row keeping its PIDL.
// FUNCTION: TITANIUM 0x005021A4
void RequestState_guess::Populate_guess() {
    if (view_guess != 0) {
        {
            StringValue_guess text_guess(EQ_ARRAY(char, 0x0063F53F));
            view_guess->Slot63_guess(text_guess);
        }
        label_guess.~Tiny_guess();
        view_guess->SetFocus();
    }
    if (tree_guess != 0) {
        tree_guess->Reset_guess();
        for (int i = 0; i < count_guess; ++i) {
            tree_guess->AddPath_guess(&values_guess[i]);
        }
        tree_guess->AddPath_guess(&current_guess);
        tree_guess->Select_guess(count_guess);
    }
    if (list_guess == 0) {
        return;
    }
    reinterpret_cast<CFileSelectionWnd_guess*>(this)->ClearFileList_guess();
    QueryInterface_guess* folder_guess = source_guess;
    IMalloc* malloc_guess;
    SHGetMalloc(&malloc_guess);
    EnumList_guess* enum_guess;
    // SHCONTF_FOLDERS | SHCONTF_NONFOLDERS.
    if (folder_guess->vtable_guess->Slot04_guess(folder_guess, g_hwnd_guess, 0x60, &enum_guess) < 0) {
        malloc_guess->Release();
        return;
    }
    Entry_guess* entries_guess[0x2800];
    int id_guess;
    int count_guess = 0;
    for (int hr_guess = enum_guess->vtable_guess->Next_guess(enum_guess, 1, &id_guess, 0);
         hr_guess == 0 && count_guess < 0x2800;
         hr_guess = enum_guess->vtable_guess->Next_guess(enum_guess, 1, &id_guess, 0)) {
        StringValue_guess name_guess;
        GetDisplayName_guess(folder_guess, id_guess, false, reinterpret_cast<Tiny_guess*>(&name_guess));
        unsigned long attributes_guess = 0x20000000;
        folder_guess->vtable_guess->Slot09_guess(folder_guess, 1, &id_guess, &attributes_guess);
        if ((attributes_guess & 0x20000000) != 0) {
            if (IsFolderEmpty_guess(folder_guess, id_guess)) {
                continue;
            }
            name_guess.Insert_guess(0, '[');
            name_guess.Append_guess(CXStrView_guess(']'));
        }
        entries_guess[count_guess] = new Entry_guess;
        entries_guess[count_guess]->name_guess.SetValue_guess(&name_guess);
        entries_guess[count_guess]->attributes_guess = attributes_guess;
        entries_guess[count_guess++]->id_guess = id_guess;
    }
    bool sort_guess;
    {
        CXStrView_guess root_guess("My Computer");
        sort_guess = current_guess.Compare_guess(root_guess, 0) != 0;
    }
    if (sort_guess) {
        qsort(entries_guess, count_guess, 4, CompareEntries_guess);
    }
    for (int j = 0; j < count_guess; ++j) {
        int handle_guess = list_guess->AddString(entries_guess[j],
            // Folders in light blue, files in white. A skipped folder's PIDL is not freed.
            (entries_guess[j]->attributes_guess & 0x20000000) ? 0xFF8AA3FF : 0xFFFFFFFF, 0, 0);
        list_guess->SetItemData(handle_guess, entries_guess[j]->id_guess);
        delete entries_guess[j];
    }
    malloc_guess->Release();
    enum_guess->vtable_guess->Release_guess(enum_guess);
}

struct Holder_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x004482FB Holder_guess::Cleanup_guess
    void Cleanup_guess();
};

struct ArrayOwner_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00406E7E ArrayOwner_guess::Clear_guess
    void Clear_guess();
};

struct Base_guess {
    char padding_guess[0x180];
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    ~Base_guess();
};

// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z
struct Big_guess : Base_guess {
    Tiny_guess first_guess;         // 0x180
    char gap_184_guess[4];
    Tiny_guess second_guess;        // 0x188
    char gap_18c_guess[0x268];      // 0x18c..0x3f4
    Tiny_guess array_guess[0x80];   // 0x3f4
    char gap_5f4_guess[0x204];      // 0x5f4..0x7f8
    Holder_guess holder_guess;      // 0x7f8
    ArrayOwner_guess owner_guess;   // 0x7fc
    ~Big_guess();
    Big_guess* Delete_guess(unsigned char flags_guess);
};

#define g_chatEnabled_guess EQ_GLOBAL(unsigned char, 0x00988C79)

struct PathView_guess {
    virtual void S00(); virtual void S01(); virtual void S02(); virtual void S03();
    virtual void S04(); virtual void S05(); virtual void S06(); virtual void S07();
    virtual void S08(); virtual void S09(); virtual void S10(); virtual void S11();
    virtual void S12(); virtual void S13(); virtual void S14(); virtual void S15();
    virtual void S16(); virtual void S17(); virtual void S18(); virtual void S19();
    virtual void S20(); virtual void S21(); virtual void S22(); virtual void S23();
    virtual void S24(); virtual void S25(); virtual void S26(); virtual void S27();
    virtual void S28(); virtual void S29(); virtual void S30(); virtual void S31();
    virtual void S32(); virtual void S33(); virtual void S34(); virtual void S35();
    virtual void S36(); virtual void S37(); virtual void S38(); virtual void S39();
    virtual void S40(); virtual void S41(); virtual void S42(); virtual void S43();
    virtual void S44(); virtual void S45(); virtual void S46(); virtual void S47();
    virtual void S48(); virtual void S49(); virtual void S50(); virtual void S51();
    virtual void S52(); virtual void S53(); virtual void S54(); virtual void S55();
    virtual void S56(); virtual void S57(); virtual void S58(); virtual void S59();
    virtual void S60(); virtual void S61(); virtual void S62();
    virtual void SetText_guess(CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x005BA1A0 PathView_guess::SetSel_guess
    void SetSel_guess(int start_guess, int end_guess);
};

struct StyleWnd_guess {
    char padding_guess[0x66];
    unsigned char style_guess;
};

struct FileBrowser_guess {
    char padding_000_guess[0x160];
    int folder_guess;                    // 0x160
    StyleWnd_guess* list_guess;          // 0x164
    PathView_guess* view_guess;          // 0x168
    char padding_16c_guess[0x14];
    Tiny_guess label_guess;              // 0x180
    // EXTERNAL: TITANIUM 0x005A0A80 FileBrowser_guess::Show_guess
    int Show_guess(int show_guess, int focus_guess);
    int Open_guess(int folder_guess, int flags_guess);
};

struct CountedObject_guess {
    char padding_guess[8];
    int value_guess;
};

struct TemporaryResult_guess {
    int value_guess;
    int padding_guess[6];
    // EXTERNAL: TITANIUM 0x0047C3AF TemporaryResult_guess::TemporaryResult_guess
    TemporaryResult_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E TemporaryResult_guess::~TemporaryResult_guess
    ~TemporaryResult_guess();
};

struct QueryProvider_guess {
    // EXTERNAL: TITANIUM 0x0059BB50 QueryProvider_guess::Read_guess
    void Read_guess(TemporaryResult_guess* result_guess);
};

struct QueryOwner_guess {
    char padding_guess[0x164];
    QueryProvider_guess* provider_guess;   // 0x164
    char gap_guess[0x18];
    CountedObject_guess* counted_guess;    // 0x180
    int HasSelection_guess();
};

// Whether something is chosen: a typed name, else the FileList selection count.
// FUNCTION: TITANIUM 0x005024B7
// @early-stop: budget, structural ndiff=4
int QueryOwner_guess::HasSelection_guess() {
    int count_guess = counted_guess != 0 ? counted_guess->value_guess : 0;
    if (count_guess > 0) {
        return 1;
    }
    QueryProvider_guess* provider_local_guess = provider_guess;
    if (provider_local_guess != 0) {
        TemporaryResult_guess result_guess(0x20);
        provider_local_guess->Read_guess(&result_guess);
        return result_guess.value_guess;
    }
    return 0;
}

// Opens the picker for `folder_guess` (the window told on close); flag 0x100 allows multiple selection.
// Returns -1 without a requester.
// FUNCTION: TITANIUM 0x005025BC
int FileBrowser_guess::Open_guess(int folder_guess, int flags_guess) {
    if (g_chatEnabled_guess) {
        // Only when byte 0x988C79 is set; probably a debug or help switch.
        pEverQuest->dsp_chat(pStringTable->getString(0xc52, 0), 0xd, 1);
    }
    if (folder_guess != 0) {
    this->folder_guess = folder_guess;
    if (list_guess != 0) {
        if (flags_guess & 0x100) {
            list_guess->style_guess |= 2;
        }
        else {
            list_guess->style_guess &= ~2;
        }
    }
    reinterpret_cast<RequestState_guess*>(this)->Populate_guess();
    if (view_guess != 0) {
        label_guess.~Tiny_guess();
        {
            CXStr text_guess(EQ_ARRAY(char, 0x0063F53F));
            view_guess->SetText_guess(text_guess);
        }
        view_guess->SetSel_guess(0, -1);
        reinterpret_cast<CXWnd*>(view_guess)->SetFocus();
    }
    reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
    return Show_guess(1, 1);
    }
    return -1;
}

// Scalar deleting destructor of the file selection window (vtable 0x654408 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00502520
Big_guess* Big_guess::Delete_guess(unsigned char flags_guess) {
    this->~Big_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the file selection window: frees the folder table (+0x7FC, 0x00406E7E) and the strings
// (+0x7F8, the 128 folder names at +0x3F4, +0x188, +0x180), then runs the CSidlScreenWnd destructor
// (0x005A3100).
// FUNCTION: TITANIUM 0x0050253C
Big_guess::~Big_guess() {
    owner_guess.Clear_guess();
    holder_guess.Cleanup_guess();
}

struct SelectionArray_guess {
    int count_guess;
    int padding_004_guess[3];
    void** entries_guess;
    int padding_014_guess;
    // EXTERNAL: TITANIUM 0x0047C3AF SelectionArray_guess::SelectionArray_guess
    SelectionArray_guess(int capacity_guess);
    // EXTERNAL: TITANIUM 0x00406E7E SelectionArray_guess::~SelectionArray_guess
    ~SelectionArray_guess();
};

// WndNotification. 0xE: Entry edited (name kept); 6: Enter in Entry accepts if OK is enabled. Clicks:
// UpButton goes up, DirHistory jumps to that level, OK accepts, Cancel cancels, a FileList click copies the
// name into Entry (several rows show string 0xC75). 4 (double-click) on a row opens a folder or accepts a
// file; 0xA cancels.
// FUNCTION: TITANIUM 0x005026B3
// @early-stop: budget, structural ndiff=86
int RequestState_guess::WndNotification_guess(CXWnd* item_guess, int event_guess, int data_guess) {
    if (event_guess == 0xe) {
        if (item_guess == reinterpret_cast<CXWnd*>(view_guess)) {
            if (list_guess != 0) {
                reinterpret_cast<CListWnd*>(list_guess)->ClearAllSel();
            }
            *reinterpret_cast<CXStr*>(&label_guess) =
                reinterpret_cast<EventView_guess*>(view_guess)->Get_guess();
            reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
            return 0;
        }
    }
    else if (event_guess == 6) {
        if (item_guess == reinterpret_cast<CXWnd*>(view_guess)) {
            if (primary_guess != 0 && primary_guess->Enabled != 0) {
                BuildFolderPath_guess();
                if (label_guess.Find_guess(0x3a, reinterpret_cast<void**>(&item_guess))) {
                    message_guess.~Tiny_guess();
                }
                reinterpret_cast<CFileSelectionWnd_guess*>(this)->Close_guess(1);
            }
            return 0;
        }
    }
    else if (event_guess == 1) {
        if (item_guess == reinterpret_cast<CXWnd*>(selected_guess)) {
            if (count_guess > 0) {
                IMalloc* allocator_guess;
                SHGetMalloc(&allocator_guess);
                reinterpret_cast<QueryRelease_guess>(source_guess->vtable_guess->slots00_guess[2])(
                    source_guess);
                allocator_guess->Free(reinterpret_cast<void*>(
                    static_cast<unsigned int>(ids_guess[count_guess])));
                --count_guess;
                source_guess = sources_guess[count_guess];
                current_guess.SetValue_guess(&values_guess[count_guess]);
                allocator_guess->Release();
                Populate_guess();
                reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
                return 0;
            }
            return 0;
        }
        else if (item_guess == reinterpret_cast<CXWnd*>(tree_guess)) {
            int next_count_guess = tree_guess->GetCurChoice_guess();
            if (next_count_guess != count_guess) {
                IMalloc* allocator_guess;
                SHGetMalloc(&allocator_guess);
                if (next_count_guess < count_guess) {
                    int index_guess = count_guess;
                    int remaining_guess = count_guess - next_count_guess;
                    do {
                        QueryInterface_guess* old_source_guess = sources_guess[index_guess];
                        reinterpret_cast<QueryRelease_guess>(
                            old_source_guess->vtable_guess->slots00_guess[2])(old_source_guess);
                        allocator_guess->Free(reinterpret_cast<void*>(
                            static_cast<unsigned int>(ids_guess[index_guess])));
                        --index_guess;
                        --remaining_guess;
                    } while (remaining_guess != 0);
                }
                count_guess = next_count_guess;
                source_guess = sources_guess[count_guess];
                current_guess.SetValue_guess(&values_guess[count_guess]);
                allocator_guess->Release();
                Populate_guess();
                reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
            }
        }
        else if (item_guess == reinterpret_cast<CXWnd*>(primary_guess)) {
            if (view_guess != 0) {
                BuildFolderPath_guess();
                if (label_guess.Find_guess(0x3a, reinterpret_cast<void**>(&item_guess))) {
                    message_guess.~Tiny_guess();
                }
            }
            reinterpret_cast<CFileSelectionWnd_guess*>(this)->Close_guess(1);
            return 0;
        }
        else if (item_guess == reinterpret_cast<CXWnd*>(secondary_guess)) {
            reinterpret_cast<CFileSelectionWnd_guess*>(this)->Close_guess(0);
            return 0;
        }
        else if (item_guess == reinterpret_cast<CXWnd*>(list_guess)) {
            SelectionArray_guess entries_guess(0x20);
            list_guess->Collect_guess(&entries_guess);
            if (entries_guess.count_guess > 0) {
                if (entries_guess.count_guess == 1) {
                    CXStr value_guess = reinterpret_cast<CListWnd*>(list_guess)->GetItemText(
                        *reinterpret_cast<int*>(entries_guess.entries_guess[0]), 0);
                    reinterpret_cast<QuerySource_guess*>(view_guess)->Slot63_guess(
                        reinterpret_cast<StringValue_guess&>(value_guess));
                    *reinterpret_cast<CXStr*>(&label_guess) = value_guess;
                }
                else {
                    label_guess.~Tiny_guess();
                    // Several rows selected: Entry shows this text instead of a name.
                    CXStr error_guess(pStringTable->getString(0xc75, 0));
                    reinterpret_cast<QuerySource_guess*>(view_guess)->Slot63_guess(
                        reinterpret_cast<StringValue_guess&>(error_guess));
                }
            }
            reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
        }
    }
    else if (event_guess == 4) {
        if (item_guess == reinterpret_cast<CXWnd*>(list_guess)) {
            label_guess.~Tiny_guess();
            unsigned int value_guess = reinterpret_cast<CListWnd*>(list_guess)->GetItemData(data_guess);
            unsigned long attributes_guess = 0x20000000;
            source_guess->vtable_guess->Slot09_guess(source_guess, 1,
                reinterpret_cast<int*>(&value_guess), &attributes_guess);
            if ((attributes_guess & 0x20000000) == 0) {
                BuildFolderPath_guess();
                reinterpret_cast<CFileSelectionWnd_guess*>(this)->Close_guess(1);
                return 0;
            }
            EnterFolder_guess(static_cast<int>(value_guess));
            list_guess->Commit_guess(data_guess);
            Populate_guess();
            reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
            reinterpret_cast<RefreshState_guess*>(this)->UpdateButtons_guess();
            return 0;
        }
    }
    else if (event_guess == 0xa) {
        reinterpret_cast<CFileSelectionWnd_guess*>(this)->Close_guess(0);
    }
    return WndNotification(item_guess, event_guess, data_guess);
}

