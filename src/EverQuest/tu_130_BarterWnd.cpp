// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 130: a hint from compare/tumap.py.
// CBarterWnd_guess ("BarterWnd"): the Titanium buyer (barter) window, the UI side of BarterManager_guess
// (0x79C198, tu_009): item search, the player's 50 buy lines (0x70 bytes each: item, quantity,
// compensation in copper and up to 10 items) and the general inventory to offer from. Requests go out as
// OP_Barter with an action word first. The small *_guess owner structs here are views of CBarterWnd_guess.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CChatManager.h"

struct Point130_guess {
    int x_guess;
    int y_guess;
};

struct Rect130_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9160 ??4Rect130_guess@@QAE?AU0@ABU0@@Z
    Rect130_guess operator=(const Rect130_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004DC02D Rect130_guess::CenterPoint
    Point130_guess CenterPoint() const;
};

struct OnQuantityAnswer_guess {
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
    virtual void Slot48_guess(char value_guess, int update_guess);
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual Rect130_guess Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(void* value_guess);
    virtual void Slot64_guess(int value_guess);
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess(void* value_guess);
    virtual void Slot74_guess(void* value_guess);
    virtual void Slot75_guess();
    virtual void Slot76_guess();
    virtual void Slot77_guess();
    virtual void Slot78_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 OnQuantityAnswer_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x0054D976 OnQuantityAnswer_guess::Open_guess
    void Open_guess(void* owner_guess, int width_guess, int height_guess,
                    Point130_guess at_guess, int flag_guess);
};

struct LayoutContainer_guess {
    char pad_guess[0x20];
    // EXTERNAL: TITANIUM 0x00572300 LayoutContainer_guess::Find_guess
    void* Find_guess(const char* name_guess);
};

struct ListPanel_guess {
    char pad140_guess[0x140];
    LayoutContainer_guess layoutContainer_guess;
    void* searchList_guess;
    void* inventoryList_guess;
    void* compList_guess;
    void* buyLinesList_guess;
    char pad170_guess[0x4C];
    OnQuantityAnswer_guess* mainCallback_guess;
    OnQuantityAnswer_guess* statusCallback_guess;
    char pad1c4_guess[8];
    int state_guess;
    // EXTERNAL: TITANIUM 0x005A1EF0 ListPanel_guess::LoadIniListWnd
    void LoadIniListWnd(void* list_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x005A1FE0 ListPanel_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(void* list_guess, const char* name_guess);
    char AboutToHide_guess();
    void LoadListLayouts_guess();
    void StoreListLayouts_guess();
};

struct Owner_guess {
    char pad_guess[0x160];
    OnQuantityAnswer_guess* dispatch_guess;
    void Update_guess();
};

struct CListWndView_guess {
    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView_guess::GetItemData
    int GetItemData(int index_guess);
};

struct Entry208_guess;

struct GlobalHandler_guess {
    // EXTERNAL: TITANIUM 0x00408F4D GlobalHandler_guess::FindFreeBuyLine_guess
    int FindFreeBuyLine_guess();
    // EXTERNAL: TITANIUM 0x00409E84 GlobalHandler_guess::UpdateBuyLine_guess
    void UpdateBuyLine_guess(const Entry208_guess* source_guess);
    // EXTERNAL: TITANIUM 0x00408FF3 GlobalHandler_guess::SetBuyerMode_guess
    void SetBuyerMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00409D7E GlobalHandler_guess::Reset_guess
    void Reset_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040903B GlobalHandler_guess::Handle_guess
    void Handle_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00409600 GlobalHandler_guess::RemoveBuyLine_guess
    void RemoveBuyLine_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004FFBE9 GlobalHandler_guess::GetIcon_guess
    int GetIcon_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004096EF GlobalHandler_guess::WriteBarterLog_guess
    void WriteBarterLog_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x0040A03F GlobalHandler_guess::LoadBuyLines_guess
    void LoadBuyLines_guess();
    // EXTERNAL: TITANIUM 0x00409C5B GlobalHandler_guess::SetWelcomeMessage_guess
    void SetWelcomeMessage_guess(char* text_guess);
};

#define g_globalHandler_guess EQ_GLOBAL(GlobalHandler_guess, 0x0079C198)
#define g_transform_guess EQ_GLOBAL(GlobalHandler_guess*, 0x00991910)
#define pQuantityWnd_guess EQ_GLOBAL(struct OnQuantityAnswer_guess*, 0x00850C3C)

struct TargetOwner_guess {
    char pad_guess[0x16C];
    CListWndView_guess* lookup_guess;
    void ToggleSelectedBuyLine_guess();
};

// BuyLineActiveButton: turns the selected buy line on or off.
// FUNCTION: TITANIUM 0x004DFF1F
void TargetOwner_guess::ToggleSelectedBuyLine_guess() {
    int index_guess = lookup_guess->GetCurSel();
    int value_guess = lookup_guess->GetItemData(index_guess);
    g_globalHandler_guess.Handle_guess(value_guess);
}

// Finishes the search-result list (vtable slot 78) after tu_009 has added a server answer's rows.
// FUNCTION: TITANIUM 0x004DFE0B
void Owner_guess::Update_guess() {
    if (dispatch_guess != 0) {
        dispatch_guess->Slot78_guess();
    }
}

// Restores the four lists' column layouts and the two layouts from the ini (probably; 0x5A1EF0).
// FUNCTION: TITANIUM 0x004DFF42
void ListPanel_guess::LoadListLayouts_guess() {
    if (searchList_guess != 0) {
        LoadIniListWnd(searchList_guess, "SearchList");
    }
    if (inventoryList_guess != 0) {
        LoadIniListWnd(inventoryList_guess, "InventoryList");
    }
    if (compList_guess != 0) {
        LoadIniListWnd(compList_guess, "CompList");
    }
    if (buyLinesList_guess != 0) {
        LoadIniListWnd(buyLinesList_guess, "BuyLinesList");
    }
    if (mainCallback_guess != 0) {
        mainCallback_guess->Slot73_guess(layoutContainer_guess.Find_guess("MainLayout"));
    }
    if (statusCallback_guess != 0) {
        statusCallback_guess->Slot73_guess(layoutContainer_guess.Find_guess("StatusLayout"));
    }
}

// Saves what LoadListLayouts_guess restores (0x5A1FE0).
// FUNCTION: TITANIUM 0x004DFFF5
void ListPanel_guess::StoreListLayouts_guess() {
    if (searchList_guess != 0) {
        StoreIniListWnd_guess(searchList_guess, "SearchList");
    }
    if (inventoryList_guess != 0) {
        StoreIniListWnd_guess(inventoryList_guess, "InventoryList");
    }
    if (compList_guess != 0) {
        StoreIniListWnd_guess(compList_guess, "CompList");
    }
    if (buyLinesList_guess != 0) {
        StoreIniListWnd_guess(buyLinesList_guess, "BuyLinesList");
    }
    if (mainCallback_guess != 0) {
        mainCallback_guess->Slot74_guess(layoutContainer_guess.Find_guess("MainLayout"));
    }
    if (statusCallback_guess != 0) {
        statusCallback_guess->Slot74_guess(layoutContainer_guess.Find_guess("StatusLayout"));
    }
}

struct Record_guess {
    char active_guess;
    char pad_guess[0x23];
    char ready_guess;
    char tail_guess[0x4B];
};

struct CopyRecord_guess {
    int words_guess[0x13];
};

struct RecordArray_guess {
    int count_guess;
    CopyRecord_guess* data_guess;
    int capacity_guess;
    // EXTERNAL: TITANIUM 0x004092BD RecordArray_guess::Allocate_guess
    void Allocate_guess(int count_guess);
    RecordArray_guess(const RecordArray_guess& source_guess);
    void Remove_guess(int index_guess);
};

// Copy constructor of the compensation-item array (0x4C-byte elements).
// FUNCTION: TITANIUM 0x004E00A8
RecordArray_guess::RecordArray_guess(const RecordArray_guess& source_guess) {
    data_guess = 0;
    count_guess = 0;
    capacity_guess = 0;
    if (source_guess.count_guess != 0) {
        Allocate_guess(source_guess.count_guess);
        if (data_guess != 0) {
            for (int i_guess = 0; i_guess < source_guess.count_guess; ++i_guess) {
                data_guess[i_guess] = source_guess.data_guess[i_guess];
            }
        }
        count_guess = source_guess.count_guess;
    }
}

// Removes record `index_guess`, shifting the later records down one; out-of-range indexes are ignored.
// FUNCTION: TITANIUM 0x004E00FD
void RecordArray_guess::Remove_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < count_guess && data_guess != 0) {
        int i_guess = index_guess;
        if (i_guess < count_guess - 1) {
            for (; i_guess < count_guess - 1; ++i_guess) {
                data_guess[i_guess] = data_guess[i_guess + 1];
            }
        }
        --count_guess;
    }
}

struct RecordList_guess {
    Record_guess records_guess[1];
    int Check_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004096EF RecordList_guess::WriteBarterLog_guess
    void WriteBarterLog_guess(char* text_guess);
};

#define g_recordList_guess EQ_GLOBAL(RecordList_guess, 0x0079C198)

struct NameList_guess {
    // EXTERNAL: TITANIUM 0x00409D5E NameList_guess::GetBuyLineText_guess
    CXStr GetBuyLineText_guess(int index_guess);
};

#define g_nameList_guess EQ_GLOBAL(NameList_guess, 0x0079C198)

// True when buy line `index_guess` exists and is turned on (+0x24).
// FUNCTION: TITANIUM 0x004E0143
int RecordList_guess::Check_guess(int index_guess) {
    Record_guess* record_guess = &records_guess[index_guess];
    if (record_guess->active_guess != 0 && record_guess->ready_guess != 0) {
        int result_guess = 0;
        ++result_guess;
        return result_guess;
    }
    return 0;
}

// On close: closes the quantity window unless none was asked for (mode 6), leaves buyer mode, saves
// the buy lines and the list layouts.
// FUNCTION: TITANIUM 0x004E0161
char ListPanel_guess::AboutToHide_guess() {
    if (state_guess != 6 && pQuantityWnd_guess != 0 && pQuantityWnd_guess->Check_guess()) {
        pQuantityWnd_guess->Slot34_guess();
    }
    g_globalHandler_guess.SetBuyerMode_guess(0);
    g_globalHandler_guess.Reset_guess(-1);
    StoreListLayouts_guess();
    return 1;
}

struct Chunk_guess {
    int words_guess[19];
};

struct Pool_guess {
    int count_guess;              // 0x00
    int blockSize_guess;          // 0x04
    int mask_guess;               // 0x08
    int shift_guess;              // 0x0C
    Chunk_guess** chunks_guess;   // 0x10
    int chunkCount_guess;         // 0x14
    char valid_guess;             // 0x18
    // EXTERNAL: TITANIUM 0x0051DA09 Pool_guess::RoundUp_guess
    int RoundUp_guess(int count_guess);
    // EXTERNAL: TITANIUM 0x004B73EE Pool_guess::Release_guess
    void Release_guess();
    // EXTERNAL: TITANIUM 0x00405492 Pool_guess::Fail_guess
    void Fail_guess();
    void Grow_guess(int count_guess);
    void Set_guess(int index_guess, const Chunk_guess* value_guess);
};

// EXTERNAL: TITANIUM 0x0060E985 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D682 FreeMemory_guess
void __cdecl FreeMemory_guess(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

struct Str_guess {
    char* data_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571FC0 Str_guess::Assign_guess
    void Assign_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00572E00 ??YStr_guess@@QAEXPBD@Z
    void operator+=(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_joinText_guess EQ_ARRAY(char, 0x00641684)
#define g_prefixText_guess EQ_ARRAY(char, 0x0064AF8C)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x00576E80 GetClientTime_guess
int __cdecl GetClientTime_guess();

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag130_guess
Str_guess __cdecl ColorTag130_guess(unsigned int color_guess);
// EXTERNAL: TITANIUM 0x0042E3D9 Concat130_guess
Str_guess __cdecl Concat130_guess(const char* first_guess, const Str_guess& second_guess);
// EXTERNAL: TITANIUM 0x004B1357 Join130_guess
Str_guess __cdecl Join130_guess(const Str_guess& left_guess, const char* right_guess);

struct Sink130_guess : OnQuantityAnswer_guess {
    char pad004_guess[0x104];       // 0x004 .. 0x107
    int field108_guess;             // 0x108
    // EXTERNAL: TITANIUM 0x005AC2A0 Sink130_guess::Append_guess
    void Append_guess(int* link_guess, Str_guess text_guess);
};

struct Panel_guess {
    char pad_guess[0x160];
    OnQuantityAnswer_guess* dispatch160_guess;   // 0x160
    char pad164_guess[0xC];              // 0x164
    OnQuantityAnswer_guess* dispatch170_guess;   // 0x170
    char pad174_guess[0x54];             // 0x174
    int state_guess;                     // 0x1C8
    char pad1cc_guess[0x20];             // 0x1CC
    Pool_guess second_guess;             // 0x1EC
    void Reset_guess();
};

// Clears the search list, the search box and the results; a new search is allowed 3 seconds later.
// FUNCTION: TITANIUM 0x004E01B2
void Panel_guess::Reset_guess() {
    if (dispatch160_guess != 0) {
        dispatch160_guess->Slot76_guess();
    }
    if (dispatch170_guess != 0) {
        Str_guess text_guess(g_emptyString_guess);
        dispatch170_guess->Slot63_guess(&text_guess);
    }
    second_guess.Release_guess();
    state_guess = GetClientTime_guess() - 2;
}

// Chunked array of 0x4C-byte records: grows the chunk table to hold `count_guess`; on failure frees
// everything and throws (ThrowSelf_guess).
// FUNCTION: TITANIUM 0x004E08D7
void Pool_guess::Grow_guess(int count_guess) {
    if (valid_guess != 0 && count_guess > 0) {
        int newCount_guess = RoundUp_guess(count_guess);
        if (newCount_guess > chunkCount_guess) {
            Chunk_guess** newChunks_guess =
                (Chunk_guess**)operator new(newCount_guess * 4);
            if (newChunks_guess == 0) {
                valid_guess = 0;
            } else {
                for (int i_guess = 0; i_guess < chunkCount_guess; ++i_guess) {
                    newChunks_guess[i_guess] = chunks_guess[i_guess];
                }
                for (int j_guess = chunkCount_guess; j_guess < newCount_guess; ++j_guess) {
                    if ((newChunks_guess[j_guess] = (Chunk_guess*)operator new(
                            blockSize_guess * 0x4C)) == 0) {
                        valid_guess = 0;
                        break;
                    }
                }
                if (valid_guess != 0) {
                    FreeMemory_guess(chunks_guess);
                    chunks_guess = newChunks_guess;
                    chunkCount_guess = newCount_guess;
                }
            }
        }
        if (valid_guess == 0) {
            Release_guess();
            Fail_guess();
        }
    }
}

struct BigBase_guess {
    char field0_guess;   // 0x00
    int field4_guess;    // 0x04
    int field8_guess;    // 0x08
    BigBase_guess() {}
    BigBase_guess(const BigBase_guess& source_guess) {
        field0_guess = source_guess.field0_guess;
        field4_guess = source_guess.field4_guess;
        field8_guess = source_guess.field8_guess;
    }
};

struct Block64_guess {
    int words_guess[16];
};

#pragma pack(push, 1)
struct Big_guess : BigBase_guess, RecordArray_guess {
    int pad18_guess;                 // 0x18
    int field1C_guess;               // 0x1C
    int field20_guess;               // 0x20
    char field24_guess;              // 0x24
    Block64_guess block_guess;       // 0x25
    char pad65_guess[3];             // 0x65
    int field68_guess;               // 0x68
    int field6C_guess;               // 0x6C
    Big_guess(const Big_guess& source_guess);
    // EXTERNAL: TITANIUM 0x005E4260 ??1Big_guess@@QAE@XZ
    ~Big_guess();
};
#pragma pack(pop)

// Copies a 0x70-byte buy line, compensation items included.
// FUNCTION: TITANIUM 0x004E0986
Big_guess::Big_guess(const Big_guess& source_guess)
    : BigBase_guess(source_guess), RecordArray_guess(source_guess) {
    field1C_guess = source_guess.field1C_guess;
    field20_guess = source_guess.field20_guess;
    field24_guess = source_guess.field24_guess;
    block_guess = source_guess.block_guess;
    field68_guess = source_guess.field68_guess;
    field6C_guess = source_guess.field6C_guess;
}

struct Record80_guess;

struct Table130_guess {
    int count_guess;
    int blockSize_guess;
    int mask_guess;
    int shift_guess;
    Chunk_guess** chunks_guess;
    int chunkCount_guess;
    char valid_guess;
    char pad19_guess[3];
    // EXTERNAL: TITANIUM 0x0047C3AF Table130_guess::Initialize_guess
    void Initialize_guess(int blockSize_guess);
    Table130_guess(int blockSize_guess) { Initialize_guess(blockSize_guess); }
    // EXTERNAL: TITANIUM 0x004DEB39 Table130_guess::Get_guess
    Record80_guess* Get_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004B73EE Table130_guess::~Table130_guess
    // fake match: throw() lever
    ~Table130_guess() throw();
};

struct Item130_guess {
    int field0_guess;          // 0x00
    int number_guess;          // 0x04
    int color_guess;           // 0x08
    char name_guess[0x40];     // 0x0C
};

struct ItemArray130_guess {
    int count_guess;           // 0x00
    char pad04_guess[0xC];     // 0x04
    // EXTERNAL: TITANIUM 0x00409340 ItemArray130_guess::GetAt_guess
    Item130_guess* GetAt_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004099FC ItemArray130_guess::Set_guess
    void Set_guess(int index_guess, const Item130_guess* value_guess);
};

struct Entry208_guess {
    char active_guess;              // 0x00
    char pad01_guess[3];            // 0x01
    int id_guess;                   // 0x04
    int value_guess;                // 0x08
    ItemArray130_guess items_guess; // 0x0C
    int count_guess;                // 0x1C
    // EXTERNAL: TITANIUM 0x005E41E0 Entry208_guess::Entry208_guess
    Entry208_guess();
    // EXTERNAL: TITANIUM 0x005E4260 Entry208_guess::~Entry208_guess
    ~Entry208_guess();
    // EXTERNAL: TITANIUM 0x005E3FE0 Entry208_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00409BFD ?Assign_guess@Entry208_guess@@QAEXABUBig_guess@@@Z
    void Assign_guess(const Big_guess& source_guess);
};

struct Big130Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0Big130Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    Big130Base_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess,
                     int iniVersion_guess, char* blockName_guess);
    // EXTERNAL: TITANIUM 0x005A3100 Big130Base_guess::~Big130Base_guess
    virtual ~Big130Base_guess();
    // EXTERNAL: TITANIUM 0x005A2230 Big130Base_guess::WndNotification
    int WndNotification(OnQuantityAnswer_guess* sender_guess, int message_guess, void* data_guess);
};

struct Release_guess {
    // EXTERNAL: TITANIUM 0x00598580 Release_guess::ClearAllSel
    void ClearAllSel();
};

struct StringTarget130_guess {
    // EXTERNAL: TITANIUM 0x005A8BF0 StringTarget130_guess::SetWindowTextA
    void SetWindowTextA(Str_guess* value_guess);
};

struct Toggle130_guess {
    char pad_guess[0x5D];
    char flag5D_guess;   // 0x5D
};

struct TextDispatch130_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void SetText_guess(CXStr* text_guess) = 0;
    virtual void Slot64_guess(int value_guess) = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess(void* value_guess) = 0;
    virtual void Slot74_guess(void* value_guess) = 0;
    virtual void Slot75_guess() = 0;
    virtual CXStr GetText_guess() = 0;
    virtual void Slot77_guess() = 0;
    virtual void Slot78_guess() = 0;
};

struct EditText130_guess {
    // EXTERNAL: TITANIUM 0x004D22D7 EditText130_guess::GetText_guess
    CXStr* GetText_guess(CXStr* output_guess);
};

struct TextSource130_guess {
    // EXTERNAL: TITANIUM 0x00572300 TextSource130_guess::Ptr_guess
    char* Ptr_guess();
};

struct Button130_guess {
    char pad_guess[0x7C];
    unsigned int color_guess;       // 0x7C
};

#define g_fieldText_guess EQ_ARRAY(char, 0x0063FE10)
#define g_textSource130_guess EQ_GLOBAL(TextSource130_guess, 0x0079D77C)

// EXTERNAL: TITANIUM 0x00650428 ??_7CBarterWnd_guess@@6B@
struct CBarterWnd_guess : Big130Base_guess {
    char pad004_guess[0x60];        // 0x004
    unsigned int windowStyle_guess; // 0x064
    char pad068_guess[0xBC];        // 0x068
    void* sidlPiece_guess;          // 0x124
    char pad128_guess[0x30];        // 0x128
    int field158_guess;             // 0x158
    StringTarget130_guess* field15C_guess; // 0x15C
    union {
        OnQuantityAnswer_guess* dispatch160_guess; // 0x160
        Release_guess* release160_guess;
        CListWndView_guess* lookup160_guess;
    };
    union {
        Release_guess* release164_guess; // 0x164
        CListWndView_guess* lookup164_guess;
    };
    CListWnd* list168_guess;        // 0x168
    union {
        Release_guess* release_guess;   // 0x16C
        CListWndView_guess* lookup_guess;     // 0x16C
    };
    TextDispatch130_guess* textDispatch170_guess; // 0x170
    Toggle130_guess* toggle174_guess;              // 0x174
    OnQuantityAnswer_guess* wnd178_guess;   // 0x178
    OnQuantityAnswer_guess* control17c_guess; // 0x17C
    OnQuantityAnswer_guess* digit3_guess;   // 0x180
    OnQuantityAnswer_guess* digit2_guess;   // 0x184
    OnQuantityAnswer_guess* digit1_guess;   // 0x188
    OnQuantityAnswer_guess* digit0_guess;   // 0x18C
    OnQuantityAnswer_guess* control190_guess; // 0x190
    OnQuantityAnswer_guess* count194_guess; // 0x194
    OnQuantityAnswer_guess* control198_guess; // 0x198
    OnQuantityAnswer_guess* control19c_guess; // 0x19C
    OnQuantityAnswer_guess* control1a0_guess; // 0x1A0
    OnQuantityAnswer_guess* control1a4_guess; // 0x1A4
    OnQuantityAnswer_guess* control1a8_guess; // 0x1A8
    OnQuantityAnswer_guess* control1ac_guess; // 0x1AC
    union {
        TextDispatch130_guess* textDispatch1b0_guess; // 0x1B0
        OnQuantityAnswer_guess* dispatch1B0_guess;
    };
    Toggle130_guess* toggle1B4_guess;  // 0x1B4
    OnQuantityAnswer_guess* dispatch1b8_guess; // 0x1B8
    OnQuantityAnswer_guess* layout1bc_guess; // 0x1BC
    OnQuantityAnswer_guess* layout1c0_guess; // 0x1C0
    int field1C4_guess;             // 0x1C4
    int field1C8_guess;             // 0x1C8
    int mode_guess;                 // 0x1CC
    Table130_guess first_guess;     // 0x1D0
    Table130_guess second_guess;    // 0x1EC
    Entry208_guess entry_guess;     // 0x208
    int field228_guess;             // 0x228
    CBarterWnd_guess(CXWnd* parent_guess);
    ~CBarterWnd_guess();
    CBarterWnd_guess* Delete_guess(unsigned int flags_guess);
    void ShowEditedLine_guess(bool keepSel_guess);
    void ClearEditedLine_guess();
    void UpdateButtons_guess();
    void Teardown_guess();
    void ModifyBuyLine_guess();
    void RemoveBuyLine_guess();
    void Close_guess();
    void ClearSearchResults_guess();
    void AppendColoredText_guess(char* text_guess, int value_guess);
    void SearchItems_guess(const CXStr& text_guess);
    void AddCompensationItem_guess(int amount_guess);
    void RemoveCompensationItem_guess(int amount_guess);
    void SelectSearchResult_guess(int value_guess);
    void SelectBuyLine_guess(int value_guess);
    void Activate_guess();
    void PrintActiveLines_guess();
    // EXTERNAL: TITANIUM 0x004E18AE CBarterWnd_guess::AddBuyLine_guess
    void AddBuyLine_guess();
    int WndNotification_guess(OnQuantityAnswer_guess* sender_guess, int message_guess, void* data_guess);
};

// Enables the buttons for the current selection. Search: 5 seconds after the last one. BuyLineAdd shows
// while no buy line is selected, Modify otherwise. Inventory add/remove need a line being edited and a
// row selected. StartStopButton reads stop in red while in buyer mode (0x79D778).
// FUNCTION: TITANIUM 0x004DFC22
// @early-stop: budget, structural ndiff=24
void CBarterWnd_guess::UpdateButtons_guess() {
    char update_guess = 0;
    char controlMode_guess;
    char visible_guess = 0;
    char firstLookup_guess = 0;
    char secondLookup_guess = 0;
    Str_guess text_guess("Start Barter");
    char fieldMode_guess;
    unsigned int color_guess = 0xff00ff00;

    if (GetClientTime_guess() > field1C8_guess + 5) {
        update_guess = 1;
    }
    fieldMode_guess = entry_guess.active_guess;
    controlMode_guess = fieldMode_guess;
    if (lookup160_guess != 0) {
        firstLookup_guess = lookup160_guess->GetCurSel() != -1;
    }
    if (lookup_guess != 0) {
        visible_guess = lookup_guess->GetCurSel() == -1;
        secondLookup_guess = lookup_guess->GetCurSel() != -1;
    }
    if (list168_guess != 0) {
        if (fieldMode_guess != 0 &&
            (firstLookup_guess != 0 || secondLookup_guess != 0)) {
            if (((CListWndView_guess*)list168_guess)->GetCurSel() == -1) {
                controlMode_guess = 0;
            } else {
                controlMode_guess = 1;
            }
        } else {
            controlMode_guess = 0;
        }
    }
    if (lookup164_guess != 0) {
        if (fieldMode_guess != 0 &&
            (firstLookup_guess != 0 || secondLookup_guess != 0)) {
            if (lookup164_guess->GetCurSel() != -1) {
                fieldMode_guess = 1;
            } else {
                fieldMode_guess = 0;
            }
        } else {
            fieldMode_guess = 0;
        }
    }
    if (EQ_GLOBAL(char, 0x0079D778) != 0) {
        text_guess.Assign_guess("Stop Barter");
        color_guess = 0xffff0000;
    }
    if (toggle174_guess != 0) {
        toggle174_guess->flag5D_guess = update_guess;
    }
    if (wnd178_guess != 0) {
        ((Toggle130_guess*)wnd178_guess)->flag5D_guess = fieldMode_guess;
    }
    if (control17c_guess != 0) {
        ((Toggle130_guess*)control17c_guess)->flag5D_guess = controlMode_guess;
    }
    if (control190_guess != 0) {
        control190_guess->Slot48_guess(visible_guess, 1);
        ((Toggle130_guess*)control190_guess)->flag5D_guess = firstLookup_guess;
    }
    if (control19c_guess != 0) {
        control19c_guess->Slot48_guess(visible_guess == 0, 1);
        ((Toggle130_guess*)control19c_guess)->flag5D_guess = secondLookup_guess;
    }
    if (control198_guess != 0) {
        ((Toggle130_guess*)control198_guess)->flag5D_guess = secondLookup_guess;
    }
    if (control1a0_guess != 0) {
        ((Toggle130_guess*)control1a0_guess)->flag5D_guess = secondLookup_guess;
    }
    if (control1ac_guess != 0) {
        control1ac_guess->Slot63_guess(&text_guess);
        ((Button130_guess*)control1ac_guess)->color_guess = color_guess;
    }
}

// Appends `text_guess` to StatusText in colour index `value_guess` and scrolls to the end.
// FUNCTION: TITANIUM 0x004DFE23
void CBarterWnd_guess::AppendColoredText_guess(char* text_guess, int value_guess) {
    if (field15C_guess != 0) {
        int link_guess[2];
        Str_guess line_guess = Join130_guess(
            Concat130_guess(g_prefixText_guess,
                            ColorTag130_guess(pinstCChatManager_guess->GetRGBAFromIndex(value_guess))),
            g_joinText_guess);
        line_guess += text_guess;
        line_guess += "</c><br>";
        ((Sink130_guess*)field15C_guess)->Append_guess(link_guess, line_guess);
        int field108_guess = ((Sink130_guess*)field15C_guess)->field108_guess;
        ((Sink130_guess*)field15C_guess)->Slot64_guess(field108_guess);
    }
}

// Shows the line being edited: its copper price split into plat (the rest, uncapped), gold, silver,
// copper; the compensation items (icon, name, count); the quantity.
// FUNCTION: TITANIUM 0x004E049E
void CBarterWnd_guess::ShowEditedLine_guess(bool keepSel_guess) {
    int value_guess = entry_guess.value_guess;
    if (digit0_guess != 0) {
        CXStr text_guess(_itoa(value_guess % 10, g_itoaBuffer_guess, 10));
        digit0_guess->Slot63_guess(&text_guess);
    }
    value_guess /= 10;
    if (digit1_guess != 0) {
        CXStr text_guess(_itoa(value_guess % 10, g_itoaBuffer_guess, 10));
        digit1_guess->Slot63_guess(&text_guess);
    }
    value_guess /= 10;
    if (digit2_guess != 0) {
        CXStr text_guess(_itoa(value_guess % 10, g_itoaBuffer_guess, 10));
        digit2_guess->Slot63_guess(&text_guess);
    }
    value_guess /= 10;
    if (digit3_guess != 0) {
        CXStr text_guess(_itoa(value_guess, g_itoaBuffer_guess, 10));
        digit3_guess->Slot63_guess(&text_guess);
    }
    if (list168_guess != 0) {
        int sel_guess = list168_guess->GetCurSel();
        ((OnQuantityAnswer_guess*)list168_guess)->Slot76_guess();
        for (int index_guess = 0; index_guess < entry_guess.items_guess.count_guess; ++index_guess) {
            int row_guess;
            {
                CXStr empty_guess(g_emptyString_guess);
                row_guess = list168_guess->AddString(empty_guess, 0xffffffff, index_guess, 0);
            }
            EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list168_guess)(
                row_guess, 0,
                g_transform_guess->GetIcon_guess(
                    entry_guess.items_guess.GetAt_guess(index_guess)->color_guess));
            {
                CXStr name_guess(entry_guess.items_guess.GetAt_guess(index_guess)->name_guess);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list168_guess)(
                    row_guess, 1, name_guess);
            }
            {
                CXStr number_guess(_itoa(entry_guess.items_guess.GetAt_guess(index_guess)->number_guess,
                                         g_itoaBuffer_guess, 10));
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list168_guess)(
                    row_guess, 2, number_guess);
            }
        }
        if (keepSel_guess) {
            list168_guess->SetCurSel(sel_guess);
        }
    }
    if (count194_guess != 0) {
        CXStr text_guess(_itoa(entry_guess.count_guess, g_itoaBuffer_guess, 10));
        count194_guess->Slot63_guess(&text_guess);
    }
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* dest_guess, const char* src_guess);
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer_guess, const char* format_guess, ...);

// ListLinesButton: writes every active buy line to the status window and the barter log.
// FUNCTION: TITANIUM 0x004E07DA
// @early-stop: budget, structural ndiff=3
void CBarterWnd_guess::PrintActiveLines_guess() {
    char buf_guess[0x800];
    strcpy(buf_guess, "Listing Active Lines:");
    AppendColoredText_guess(buf_guess, 0);
    g_recordList_guess.WriteBarterLog_guess(buf_guess);
    int i_guess = 0;
    do {
        if ((char)g_recordList_guess.Check_guess(i_guess)) {
            sprintf(buf_guess, "%s", (char*)g_nameList_guess.GetBuyLineText_guess(i_guess));
            AppendColoredText_guess(buf_guess, 0);
            g_recordList_guess.WriteBarterLog_guess(buf_guess);
        }
        ++i_guess;
    } while (i_guess < 50);
}

// Empties the line being edited.
// FUNCTION: TITANIUM 0x004E141E
void CBarterWnd_guess::ClearEditedLine_guess() {
    entry_guess.Clear_guess();
    ShowEditedLine_guess(0);
}

struct ListView130_guess : CListWnd {
    char pad140_guess[0x14];        // 0x140
    int field154_guess;             // 0x154
    char pad158_guess;              // 0x158
    char fixedRows_guess;           // 0x159
    char pad15a_guess[2];           // 0x15A
    char flag15c_guess;             // 0x15C
    char pad15d_guess[3];           // 0x15D
    int rowHeight_guess;            // 0x160
    char pad164_guess[8];           // 0x164
    unsigned int highlight_guess;   // 0x16C
    void SetRowHeight_guess(int height_guess) {
        fixedRows_guess = 1;
        rowHeight_guess = height_guess;
    }
    // EXTERNAL: TITANIUM 0x005981F0 ListView130_guess::Apply_guess
    void Apply_guess(int column_guess, int height_guess);
};

struct StmlView130_guess {
    char pad_guess[0x1C0];
    int maxLines_guess;             // 0x1C0
};

struct Edit130_guess {
    char pad_guess[0x230];
    int field230_guess;             // 0x230
    // EXTERNAL: TITANIUM 0x004D7EBC Edit130_guess::SetMaxChars_guess
    void SetMaxChars_guess(int count_guess);
};

#define CHILD130(name) ((CSidlScreenWnd*)this)->GetChildItem(name)

// Finds the 26 children. StatusText keeps 200 lines; the lists get 24-pixel rows; the search box takes
// 64 characters and CountEdit 3 digits. Mode 6 = no quantity request pending.
// The WelcomeEdit test is followed by SetMaxChars(0x100) on the search box, not WelcomeEdit (original),
// so the search box ends up taking 256 characters and WelcomeEdit keeps its default.
// FUNCTION: TITANIUM 0x004E09DF
// @early-stop: budget, structural ndiff=39
CBarterWnd_guess::CBarterWnd_guess(CXWnd* parent_guess)
    : Big130Base_guess(parent_guess, "BarterWnd", -1, 1, 0),
      first_guess(0x20), second_guess(0x20) {
    field15C_guess = 0;
    dispatch160_guess = 0;
    release164_guess = 0;
    list168_guess = 0;
    release_guess = 0;
    textDispatch170_guess = 0;
    toggle174_guess = 0;
    wnd178_guess = 0;
    control17c_guess = 0;
    digit3_guess = 0;
    digit2_guess = 0;
    digit1_guess = 0;
    digit0_guess = 0;
    count194_guess = 0;
    control190_guess = 0;
    control198_guess = 0;
    control19c_guess = 0;
    control1a0_guess = 0;
    control1a4_guess = 0;
    control1a8_guess = 0;
    control1ac_guess = 0;
    layout1bc_guess = 0;
    layout1c0_guess = 0;
    toggle1B4_guess = 0;
    textDispatch1b0_guess = 0;
    dispatch1b8_guess = 0;
    if (sidlPiece_guess != 0) {
        windowStyle_guess |= 0x10000;
        field158_guess = 0x3A;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        field15C_guess = (StringTarget130_guess*)CHILD130("StatusText");
        dispatch160_guess = (OnQuantityAnswer_guess*)CHILD130("ItemSearchList");
        release164_guess = (Release_guess*)CHILD130("InventoryList");
        list168_guess = (CListWnd*)CHILD130("CompensationList");
        release_guess = (Release_guess*)CHILD130("BuyLineList");
        textDispatch170_guess = (TextDispatch130_guess*)CHILD130("ItemSearchEdit");
        toggle174_guess = (Toggle130_guess*)CHILD130("ItemSearchButton");
        wnd178_guess = (OnQuantityAnswer_guess*)CHILD130("InventoryAddButton");
        control17c_guess = (OnQuantityAnswer_guess*)CHILD130("InventoryRemoveButton");
        digit3_guess = (OnQuantityAnswer_guess*)CHILD130("CompensationPlat");
        digit2_guess = (OnQuantityAnswer_guess*)CHILD130("CompensationGold");
        digit1_guess = (OnQuantityAnswer_guess*)CHILD130("CompensationSilver");
        digit0_guess = (OnQuantityAnswer_guess*)CHILD130("CompensationCopper");
        count194_guess = (OnQuantityAnswer_guess*)CHILD130("CountEdit");
        control190_guess = (OnQuantityAnswer_guess*)CHILD130("BuyLineAddButton");
        control198_guess = (OnQuantityAnswer_guess*)CHILD130("BuyLineRemoveButton");
        control19c_guess = (OnQuantityAnswer_guess*)CHILD130("BuyLineModifyButton");
        control1a0_guess = (OnQuantityAnswer_guess*)CHILD130("BuyLineActiveButton");
        control1a4_guess = (OnQuantityAnswer_guess*)CHILD130("ListLinesButton");
        control1a8_guess = (OnQuantityAnswer_guess*)CHILD130("ClearStatusButton");
        control1ac_guess = (OnQuantityAnswer_guess*)CHILD130("StartStopButton");
        layout1bc_guess = (OnQuantityAnswer_guess*)CHILD130("Layout");
        layout1c0_guess = (OnQuantityAnswer_guess*)CHILD130("StatusLayout");
        textDispatch1b0_guess = (TextDispatch130_guess*)CHILD130("WelcomeEdit");
        toggle1B4_guess = (Toggle130_guess*)CHILD130("UpdateWelcomeButton");
        dispatch1b8_guess = (OnQuantityAnswer_guess*)CHILD130("InventoryRefreshButton");
        if (field15C_guess != 0) {
            ((StmlView130_guess*)field15C_guess)->maxLines_guess = 200;
        }
        if (dispatch160_guess != 0) {
            ((ListView130_guess*)dispatch160_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ListView130_guess*)dispatch160_guess)->SetColumnJustification(0, 0);
            ((ListView130_guess*)dispatch160_guess)->SetColumnJustification(1, 0);
            ((ListView130_guess*)dispatch160_guess)->highlight_guess = 0xff8aa3ff;
            ((ListView130_guess*)dispatch160_guess)->flag15c_guess = 1;
            ((ListView130_guess*)dispatch160_guess)->SetRowHeight_guess(0x18);
            ((ListView130_guess*)dispatch160_guess)->Apply_guess(0, 0x18);
            ((ListView130_guess*)dispatch160_guess)->WindowStyle |= 0x40000;
            ((ListView130_guess*)dispatch160_guess)->field154_guess = 1;
        }
        if (release164_guess != 0) {
            ((ListView130_guess*)release164_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ListView130_guess*)release164_guess)->SetColumnJustification(0, 0);
            ((ListView130_guess*)release164_guess)->SetColumnJustification(1, 0);
            ((ListView130_guess*)release164_guess)->SetColumnJustification(2, 1);
            ((ListView130_guess*)release164_guess)->highlight_guess = 0xff8aa3ff;
            ((ListView130_guess*)release164_guess)->flag15c_guess = 1;
            ((ListView130_guess*)release164_guess)->SetRowHeight_guess(0x18);
            ((ListView130_guess*)release164_guess)->Apply_guess(0, 0x18);
            ((ListView130_guess*)release164_guess)->WindowStyle |= 0x40000;
            ((ListView130_guess*)release164_guess)->field154_guess = 1;
        }
        if (list168_guess != 0) {
            ((ListView130_guess*)list168_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ListView130_guess*)list168_guess)->SetColumnJustification(0, 0);
            ((ListView130_guess*)list168_guess)->SetColumnJustification(1, 0);
            ((ListView130_guess*)list168_guess)->SetColumnJustification(2, 1);
            ((ListView130_guess*)list168_guess)->highlight_guess = 0xff8aa3ff;
            ((ListView130_guess*)list168_guess)->flag15c_guess = 1;
            ((ListView130_guess*)list168_guess)->SetRowHeight_guess(0x18);
            ((ListView130_guess*)list168_guess)->Apply_guess(0, 0x18);
        }
        if (release_guess != 0) {
            ((ListView130_guess*)release_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ListView130_guess*)release_guess)->SetColumnJustification(0, 1);
            ((ListView130_guess*)release_guess)->SetColumnJustification(1, 1);
            ((ListView130_guess*)release_guess)->SetColumnJustification(2, 0);
            ((ListView130_guess*)release_guess)->SetColumnJustification(3, 1);
            ((ListView130_guess*)release_guess)->SetColumnJustification(4, 1);
            ((ListView130_guess*)release_guess)->highlight_guess = 0xff8aa3ff;
            ((ListView130_guess*)release_guess)->flag15c_guess = 1;
            ((ListView130_guess*)release_guess)->SetRowHeight_guess(0x18);
            ((ListView130_guess*)release_guess)->Apply_guess(1, 0x18);
        }
        if (control1ac_guess != 0) {
            {
                CXStr text_guess("Start Barter");
                control1ac_guess->Slot63_guess(&text_guess);
            }
            ((Button130_guess*)control1ac_guess)->color_guess = 0xff00ff00;
        }
        if (textDispatch170_guess != 0) {
            ((Edit130_guess*)textDispatch170_guess)->SetMaxChars_guess(0x40);
        }
        if (textDispatch1b0_guess != 0) {
            ((Edit130_guess*)textDispatch170_guess)->SetMaxChars_guess(0x100);
        }
        if (count194_guess != 0) {
            ((Edit130_guess*)count194_guess)->SetMaxChars_guess(3);
            ((Edit130_guess*)count194_guess)->field230_guess = 3;
        }
        field1C4_guess = 0;
        mode_guess = 6;
        entry_guess.active_guess = 0;
        ((ListPanel_guess*)this)->LoadListLayouts_guess();
    }
}

// Empty: the members and the CSidlScreenWnd base clean up.
// FUNCTION: TITANIUM 0x004E13C7
CBarterWnd_guess::~CBarterWnd_guess() {
}

struct Record80_guess {
    int words_guess[4];        // 0x00
    char name_guess[0x40];     // 0x10
};

struct RecordPool_guess {
    int count_guess;              // 0x00
    char pad04_guess[0x14];       // 0x04
    char valid_guess;             // 0x18
    // EXTERNAL: TITANIUM 0x004B73EE RecordPool_guess::Release_guess
    void Release_guess();
    // EXTERNAL: TITANIUM 0x004DEC3B RecordPool_guess::Grow_guess
    void Grow_guess(int count_guess);
    // EXTERNAL: TITANIUM 0x004DEB39 RecordPool_guess::Get_guess
    Record80_guess* Get_guess(int index_guess);
    void Set_guess(int index_guess, const Record80_guess* value_guess);
};

// Stores record `index_guess` of the inventory list (0x50 bytes), growing the array as needed.
// FUNCTION: TITANIUM 0x004E16E1
void RecordPool_guess::Set_guess(int index_guess, const Record80_guess* value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= count_guess) {
            Grow_guess(index_guess + 1);
            if (valid_guess == 0) {
                return;
            }
            count_guess = index_guess + 1;
        }
        if (valid_guess != 0) {
            Record80_guess* record_guess = Get_guess(index_guess);
            *record_guess = *value_guess;
        }
    }
}

// Stores record `index_guess` of the search results (0x4C bytes), growing the array as needed.
// FUNCTION: TITANIUM 0x004E1722
void Pool_guess::Set_guess(int index_guess, const Chunk_guess* value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= count_guess) {
            Grow_guess(index_guess + 1);
            if (valid_guess == 0) {
                return;
            }
            count_guess = index_guess + 1;
        }
        if (valid_guess != 0) {
            chunks_guess[index_guess >> shift_guess][index_guess & mask_guess] = *value_guess;
        }
    }
}

struct BigArray_guess {
    Big_guess items_guess[1];
    Big_guess Get_guess(int index_guess);
};

// A copy of buy line `index_guess` of BarterManager_guess.
// FUNCTION: TITANIUM 0x004E1770
Big_guess BigArray_guess::Get_guess(int index_guess) {
    return items_guess[index_guess];
}

// Scalar deleting destructor; frees with free(), not operator delete.
// FUNCTION: TITANIUM 0x004E1790
CBarterWnd_guess* CBarterWnd_guess::Delete_guess(unsigned int flags_guess) {
    this->CBarterWnd_guess::~CBarterWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Unselects the search and inventory lists and empties the line being edited.
// FUNCTION: TITANIUM 0x004E17AC
void CBarterWnd_guess::Close_guess() {
    if (release160_guess) {
        release160_guess->ClearAllSel();
    }
    if (release164_guess) {
        release164_guess->ClearAllSel();
    }
    ClearEditedLine_guess();
    UpdateButtons_guess();
}

// Before a new search answer: as Close_guess, then drops the old results and their rows.
// FUNCTION: TITANIUM 0x004E1EE9
void CBarterWnd_guess::ClearSearchResults_guess() {
    Close_guess();
    second_guess.~Table130_guess();
    if (dispatch160_guess) {
        dispatch160_guess->Slot76_guess();
    }
}

// Unselects the buy-line list and empties the line being edited.
// FUNCTION: TITANIUM 0x004E17DC
void CBarterWnd_guess::Teardown_guess() {
    if (release_guess) {
        release_guess->ClearAllSel();
    }
    ClearEditedLine_guess();
    UpdateButtons_guess();
}

// BuyLineModifyButton: needs a quantity (string 6122) and some compensation (6123), then saves the line
// over the selected one.
// FUNCTION: TITANIUM 0x004E17FD
void CBarterWnd_guess::ModifyBuyLine_guess() {
    CXStr msg_guess;
    if (entry_guess.count_guess <= 0) {
        msg_guess = pStringTable->getString(0x17ea, 0);
    } else if (entry_guess.value_guess == 0 && entry_guess.items_guess.count_guess == 0) {
        msg_guess = pStringTable->getString(0x17eb, 0);
    }
    int len_guess = msg_guess.Ptr != 0 ? msg_guess.Ptr->length : 0;
    if (len_guess > 0) {
        AppendColoredText_guess(msg_guess, 0xf);
        return;
    }
    g_globalHandler_guess.UpdateBuyLine_guess(&entry_guess);
    Teardown_guess();
}

// BuyLineAddButton: as ModifyBuyLine_guess, plus a free line among the 50 (string 6124, too many), then
// saves the line into it (+0x228 = its index).
// FUNCTION: TITANIUM 0x004E18AE
// @early-stop: budget, diff ndiff=25
void CBarterWnd_guess::AddBuyLine_guess() {
    CXStr msg_guess;
    int zero_guess = 0;
    GlobalHandler_guess* handler_guess = &g_globalHandler_guess;
    if (entry_guess.count_guess <= zero_guess) {
        msg_guess = pStringTable->getString(0x17ea, 0);
    } else if (entry_guess.value_guess == zero_guess &&
               entry_guess.items_guess.count_guess == zero_guess) {
        msg_guess = pStringTable->getString(0x17eb, 0);
    } else if (handler_guess->FindFreeBuyLine_guess() == -1) {
        msg_guess = pStringTable->getString(0x17ec, 0);
    }
    int len_guess = msg_guess.Ptr != 0 ? msg_guess.Ptr->length : 0;
    if (len_guess > 0) {
        AppendColoredText_guess(msg_guess, 0xf);
    } else {
        field228_guess = handler_guess->FindFreeBuyLine_guess();
        handler_guess->UpdateBuyLine_guess(&entry_guess);
        Close_guess();
    }
}

// BuyLineRemoveButton: removes the selected buy line.
// FUNCTION: TITANIUM 0x004E1ACC
void CBarterWnd_guess::RemoveBuyLine_guess() {
    if (lookup_guess != 0) {
        int index_guess = lookup_guess->GetCurSel();
        if (index_guess != -1) {
            int value_guess = lookup_guess->GetItemData(index_guess);
            g_globalHandler_guess.RemoveBuyLine_guess(value_guess);
            Teardown_guess();
        }
    }
}

// InventoryAddButton. With -1 it asks the quantity window for up to the count held (at most 20), mode 4;
// the answer comes back here. The item being bought can't be offered (string 6127). The count is added
// to that item's row, or a new row while there are fewer than 10.
// FUNCTION: TITANIUM 0x004E1B05
void CBarterWnd_guess::AddCompensationItem_guess(int amount_guess) {
    if (lookup164_guess != 0) {
        int index_guess = lookup164_guess->GetCurSel();
        if (index_guess != -1) {
            int record_guess = lookup164_guess->GetItemData(index_guess);
            if (first_guess.Get_guess(record_guess)->words_guess[0] == entry_guess.id_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x17ef, 0), 0xf, 1);
            } else if (amount_guess == -1) {
                int size_guess = first_guess.Get_guess(record_guess)->words_guess[2];
                if (size_guess > 20) {
                    size_guess = 20;
                }
                Rect130_guess rect_guess;
                rect_guess.bottom_guess = 0;
                rect_guess.right_guess = 0;
                rect_guess.top_guess = 0;
                rect_guess.left_guess = 0;
                if (wnd178_guess != 0) {
                    rect_guess = wnd178_guess->Slot57_guess();
                }
                Point130_guess at_guess;
                at_guess = rect_guess.CenterPoint();
                mode_guess = 4;
                pQuantityWnd_guess->Open_guess(this, size_guess, size_guess, at_guess, 1);
            } else {
                for (int i_guess = 0; i_guess < entry_guess.items_guess.count_guess; ++i_guess) {
                    Record80_guess* source_guess = first_guess.Get_guess(record_guess);
                    if (entry_guess.items_guess.GetAt_guess(i_guess)->field0_guess ==
                            source_guess->words_guess[0]) {
                        entry_guess.items_guess.GetAt_guess(i_guess)->number_guess += amount_guess;
                        ShowEditedLine_guess(0);
                        return;
                    }
                }
                if (entry_guess.items_guess.count_guess < 10) {
                    Item130_guess item_guess;
                    item_guess.field0_guess = first_guess.Get_guess(record_guess)->words_guess[0];
                    item_guess.number_guess = amount_guess;
                    item_guess.color_guess = first_guess.Get_guess(record_guess)->words_guess[3];
                    strcpy(item_guess.name_guess, first_guess.Get_guess(record_guess)->name_guess);
                    entry_guess.items_guess.Set_guess(entry_guess.items_guess.count_guess, &item_guess);
                    ShowEditedLine_guess(0);
                }
            }
        }
    }
}

// InventoryRemoveButton: with -1 asks for up to the row's count (mode 5); the answer lowers the count,
// or removes the row when it takes them all.
// FUNCTION: TITANIUM 0x004E1437
// @early-stop: budget, diff ndiff=3
void CBarterWnd_guess::RemoveCompensationItem_guess(int amount_guess) {
    if (list168_guess != 0) {
        int index_guess = list168_guess->GetCurSel();
        if (index_guess != -1) {
            int data_guess = list168_guess->GetItemData(index_guess);
            if (amount_guess == -1) {
                int size_guess = entry_guess.items_guess.GetAt_guess(data_guess)->number_guess;
                Rect130_guess rect_guess;
                rect_guess.bottom_guess = 0;
                rect_guess.right_guess = 0;
                rect_guess.top_guess = 0;
                rect_guess.left_guess = 0;
                if (control17c_guess != 0) {
                    rect_guess = control17c_guess->Slot57_guess();
                }
                Point130_guess at_guess;
                at_guess = rect_guess.CenterPoint();
                mode_guess = 5;
                pQuantityWnd_guess->Open_guess(this, size_guess, size_guess, at_guess, 1);
            } else if (entry_guess.items_guess.GetAt_guess(data_guess)->number_guess > amount_guess) {
                entry_guess.items_guess.GetAt_guess(data_guess)->number_guess -= amount_guess;
                ShowEditedLine_guess(1);
            } else {
                ((RecordArray_guess*)&entry_guess.items_guess)->Remove_guess(data_guess);
                ShowEditedLine_guess(0);
            }
        }
    }
}

struct CharEntry_guess;

struct RefreshList_guess {
    char pad_guess[0x164];
    CListWnd* list_guess;         // 0x164
    char pad168_guess[0x68];      // 0x168
    RecordPool_guess pool_guess;  // 0x1D0
    void Add_guess(CharEntry_guess* entry_guess);
    void Refresh_guess();
    void RebuildInventoryList_guess();
};

// Refills InventoryList (icon, name, count) from the inventory records.
// FUNCTION: TITANIUM 0x004E1CB9
void RefreshList_guess::Refresh_guess() {
    if (list_guess != 0) {
        ((OnQuantityAnswer_guess*)list_guess)->Slot76_guess();
        for (int index_guess = 0; index_guess < pool_guess.count_guess; ++index_guess) {
            int row_guess;
            {
                CXStr empty_guess(g_emptyString_guess);
                row_guess = list_guess->AddString(empty_guess, 0xffffffff, index_guess, 0);
            }
            EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list_guess)(
                row_guess, 0,
                g_transform_guess->GetIcon_guess(pool_guess.Get_guess(index_guess)->words_guess[3]));
            {
                CXStr name_guess(pool_guess.Get_guess(index_guess)->name_guess);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                    row_guess, 1, name_guess);
            }
            {
                CXStr value_guess(_itoa(pool_guess.Get_guess(index_guess)->words_guess[2],
                                        g_itoaBuffer_guess, 10));
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                    row_guess, 2, value_guess);
            }
        }
        ((OnQuantityAnswer_guess*)list_guess)->Slot78_guess();
    }
}

struct Entry_guess {
    char name_guess[0x44];     // 0x00: text, read as a C string
    int value_guess;           // 0x44: colour index, through GlobalHandler::Transform
    char tail_guess[4];        // 0x48
};

struct ListOwner_guess {
    char pad_guess[0x160];
    CListWnd* list_guess;      // 0x160
    char pad164_guess[0x1EC - 0x164];
    Pool_guess pool_guess;     // 0x1EC: entries, appended by index = count
    void AddSearchResult_guess(Entry_guess* entry_guess);
};

// Appends one search result from the server (name, icon) to ItemSearchList.
// FUNCTION: TITANIUM 0x004E1F15
void ListOwner_guess::AddSearchResult_guess(Entry_guess* entry_guess) {
    if (list_guess != 0) {
        int data_guess = pool_guess.count_guess;
        pool_guess.Set_guess(data_guess, (Chunk_guess*)entry_guess);
        int index_guess;
        {
            CXStr empty_guess(g_emptyString_guess);
            index_guess = list_guess->AddString(empty_guess, 0xffffffff, data_guess, 0);
        }
        {
            CXStr name_guess(entry_guess->name_guess);
            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                index_guess, 1, name_guess);
        }
        EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list_guess)(
            index_guess, 0, g_transform_guess->GetIcon_guess(entry_guess->value_guess));
    }
}

struct ModeDispatch_guess {
    char pad000_guess[0x180];
    OnQuantityAnswer_guess* control180_guess;  // 0x180
    OnQuantityAnswer_guess* control184_guess;  // 0x184
    OnQuantityAnswer_guess* control188_guess;  // 0x188
    OnQuantityAnswer_guess* control18c_guess;  // 0x18C
    char pad190_guess[0x3c];
    int mode_guess;                    // 0x1CC
    char pad1d0_guess[0x40];
    unsigned int value210_guess;       // 0x210
    // EXTERNAL: TITANIUM 0x004E1437 ModeDispatch_guess::RemoveCompensationItem_guess
    void RemoveCompensationItem_guess(int arg_guess);
    // EXTERNAL: TITANIUM 0x004E1B05 ModeDispatch_guess::AddCompensationItem_guess
    void AddCompensationItem_guess(int arg_guess);
    void SetCompensationCoin_guess(struct OnQuantityAnswer_guess* control_guess, int digit_guess, int value_guess);
    void OnQuantityAnswer_guess(int arg_guess);
};

// Compensation coin buttons: `digit_guess` 0-3 = plat, gold, silver, copper. With -1 it asks the quantity
// window (up to 1,000,000); the answer replaces that coin's digit(s) in the copper price (+0x210),
// capped at 1,000,000,000.
// FUNCTION: TITANIUM 0x004E1521
// @early-stop: budget, structural ndiff=72
void ModeDispatch_guess::SetCompensationCoin_guess(struct OnQuantityAnswer_guess* control_guess,
    int digit_guess, int value_guess) {
    if (value_guess == -1) {
        mode_guess = digit_guess;
        Rect130_guess rect_guess;
        rect_guess.bottom_guess = 0;
        rect_guess.right_guess = 0;
        rect_guess.top_guess = 0;
        rect_guess.left_guess = 0;
        if (control_guess != 0) {
            rect_guess = control_guess->Slot57_guess();
        }
        pQuantityWnd_guess->Open_guess(this, 1000000, 1,
            rect_guess.CenterPoint(), 1);
    } else {
        struct OnQuantityAnswer_guess* selected_guess = 0;
        if (mode_guess == 0) {
            selected_guess = control180_guess;
            value210_guess = value210_guess % 1000 + value_guess * 1000;
        } else if (mode_guess == 1) {
            selected_guess = control184_guess;
            value210_guess = (value_guess + (value210_guess / 1000) * 10) * 100
                + value210_guess % 100;
        } else if (mode_guess == 2) {
            selected_guess = control188_guess;
            value210_guess = value210_guess % 10
                + (value_guess + (value210_guess / 100) * 10) * 10;
        } else if (mode_guess == 3) {
            selected_guess = control18c_guess;
            value210_guess = value210_guess - value210_guess % 10 + value_guess;
        }
        if (value210_guess > 1000000000U) {
            value210_guess = 1000000000U;
        }
        if (selected_guess != 0) {
            Str_guess text_guess(_itoa(value_guess, g_itoaBuffer_guess, 10));
            selected_guess->Slot63_guess(&text_guess);
        }
        ((CBarterWnd_guess*)this)->ShowEditedLine_guess(0);
    }
}

// A quantity-window answer (notification 31), routed by the mode that asked: 0-3 coins, 4 add, 5 remove.
// FUNCTION: TITANIUM 0x004E1FE7
void ModeDispatch_guess::OnQuantityAnswer_guess(int arg_guess) {
    int mode = mode_guess;
    if (mode >= 0) {
        if (mode > 3) {
            if (mode != 4) {
                if (mode == 5) {
                    RemoveCompensationItem_guess(arg_guess);
                }
            } else {
                AddCompensationItem_guess(arg_guess);
            }
        } else {
            SetCompensationCoin_guess(0, mode, arg_guess);
        }
    }
}

struct CharEntry_guess {
    // EXTERNAL: TITANIUM 0x005DFC40 CharEntry_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x005DFC50 CharEntry_guess::IsValid_guess
    char IsValid_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 CharEntry_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005ECC90 CharEntry_guess::GetTotal_guess
    int GetTotal_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 CharEntry_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0F60 CharEntry_guess::GetKind_guess
    int GetKind_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 CharEntry_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x005EC630 CharEntry_guess::GetChild_guess
    CharEntry_guess* GetChild_guess(int index_guess);
    char pad_guess[0x48];
    int field48_guess;             // 0x48
    char pad4c_guess[0xC];
    int field58_guess;             // 0x58
};

// Adds an inventory item to the records, summing the counts of items with the same id.
// FUNCTION: TITANIUM 0x004E1E1E
void RefreshList_guess::Add_guess(CharEntry_guess* entry_guess) {
    CharEntry_guess* source_guess = entry_guess;
    if (source_guess->IsValid_guess()) {
        for (int index_guess = 0; index_guess < pool_guess.count_guess; ++index_guess) {
            entry_guess = (CharEntry_guess*)pool_guess.Get_guess(index_guess);
            if (source_guess->GetItemId_guess() == ((Record80_guess*)entry_guess)->words_guess[0]) {
                pool_guess.Get_guess(index_guess)->words_guess[2] += source_guess->field48_guess;
                return;
            }
        }
        Record80_guess rec_guess;
        memset(&rec_guess, 0, 0x50);
        rec_guess.words_guess[0] = source_guess->GetItemId_guess();
        rec_guess.words_guess[3] = source_guess->GetKind_guess();
        if (source_guess->GetTotal_guess() > 0) {
            rec_guess.words_guess[1] = source_guess->field58_guess;
        }
        rec_guess.words_guess[2] = source_guess->field48_guess;
        strcpy(rec_guess.name_guess, source_guess->GetText_guess());
        pool_guess.Set_guess(pool_guess.count_guess, &rec_guess);
    }
}

// pCharData: vfptr and int at +0, vbptr at +8, the profile in the virtual base.
struct CharDataPrefix130_guess {
    virtual void Slot00_guess() = 0;
    int field04_guess;
};

struct CharDataVirtual130_guess {
    void* vftable_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 CharDataVirtual130_guess::GetEntry_guess
    CharEntry_guess* GetEntry_guess(int index_guess);
};

struct CharDataRoot130_guess : CharDataPrefix130_guess, virtual CharDataVirtual130_guess {
};

#define g_charData130_guess EQ_GLOBAL(CharDataRoot130_guess*, 0x00905D00)

// Rebuilds the inventory records from the general slots 22-29 and the contents of bags there.
// FUNCTION: TITANIUM 0x004E2019
void RefreshList_guess::RebuildInventoryList_guess() {
    pool_guess.Release_guess();
    for (int index_guess = 0x16; index_guess <= 0x1d; ++index_guess) {
        CharEntry_guess* entry_guess = g_charData130_guess->GetEntry_guess(index_guess);
        if (entry_guess != 0) {
            Add_guess(entry_guess);
            if (entry_guess->IsReady_guess()) {
                for (int child_guess = 0; child_guess < entry_guess->GetCount_guess();
                        ++child_guess) {
                    CharEntry_guess* value_guess = entry_guess->GetChild_guess(child_guess);
                    if (value_guess != 0) {
                        Add_guess(value_guess);
                    }
                }
            }
        }
    }
    Refresh_guess();
}

struct Row_guess {
    char active_guess;        // 0x00
    char pad01_guess[0x1B];   // 0x01
    int number_guess;         // 0x1C
    char pad20_guess[4];      // 0x20
    char ready_guess;         // 0x24
    char name_guess[0x43];    // 0x25
    int color_guess;          // 0x68
    char tail_guess[4];       // 0x6C
};

struct RowTable_guess {
    Row_guess rows_guess[1];
    // EXTERNAL: TITANIUM 0x00409226 RowTable_guess::FormatPrice_guess
    CXStr FormatPrice_guess(const Row_guess* row_guess);
};

#define g_rows_guess EQ_GLOBAL(RowTable_guess, 0x0079C198)

struct RowOwner_guess {
    char pad_guess[0x16C];
    CListWnd* list_guess;     // 0x16C
    void RefreshBuyLineList_guess(bool keepSel_guess);
};

// Fills BuyLineList with the used lines of the 50: column 0 is blanked for inactive lines, then icon,
// name, quantity and price (FormatPrice_guess).
// FUNCTION: TITANIUM 0x004E02A8
void RowOwner_guess::RefreshBuyLineList_guess(bool keepSel_guess) {
    if (list_guess != 0) {
        int sel_guess = list_guess->GetCurSel();
        ((OnQuantityAnswer_guess*)list_guess)->Slot76_guess();
        int index_guess = 0;
        int remaining_guess = 50;
        do {
            if (g_rows_guess.rows_guess[index_guess].active_guess != 0) {
                int row_guess;
                {
                    CXStr empty_guess(EQ_ARRAY(char, 0x00646EA8));
                    row_guess = list_guess->AddString(empty_guess, 0xffffffff, index_guess, 0);
                }
                if ((char)EQ_GLOBAL(RecordList_guess, 0x0079C198).Check_guess(index_guess) == 0) {
                    CXStr empty2_guess(g_emptyString_guess);
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                        row_guess, 0, empty2_guess);
                }
                EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list_guess)(
                    row_guess, 1, g_transform_guess->GetIcon_guess(g_rows_guess.rows_guess[index_guess].color_guess));
                {
                    CXStr name_guess(g_rows_guess.rows_guess[index_guess].name_guess);
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                        row_guess, 2, name_guess);
                }
                {
                    CXStr value_guess(_itoa(g_rows_guess.rows_guess[index_guess].number_guess,
                                            g_itoaBuffer_guess, 10));
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                        row_guess, 3, value_guess);
                }
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                    row_guess, 4, g_rows_guess.FormatPrice_guess(&g_rows_guess.rows_guess[index_guess]));
            }
            ++index_guess;
            --remaining_guess;
        } while (remaining_guess != 0);
        if (keepSel_guess) {
            list_guess->SetCurSel(sel_guess);
        }
    }
}

struct Msg68_guess {
    int id_guess;               // 0x00
    char text_guess[0x40];      // 0x04
};

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
char* __cdecl FUN_0046da4a_guess(char* output_guess, int string_guess,
    const char* value_guess, const char* zero1_guess, const char* zero2_guess,
    const char* zero3_guess, const char* zero4_guess, const char* zero5_guess,
    const char* zero6_guess, const char* zero7_guess, const char* zero8_guess);

// Item search: OP_Barter action 0 with the text (64 bytes), "Searching for items to buy with string
// '%1'" (string 6057) to the status window and log, and the time for the 5-second search delay.
// FUNCTION: TITANIUM 0x004E2099
void CBarterWnd_guess::SearchItems_guess(const CXStr& text_guess) {
    Close_guess();
    Teardown_guess();
    ClearSearchResults_guess();
    Msg68_guess msg_guess;
    msg_guess.id_guess = 0;
    strcpy(msg_guess.text_guess, text_guess);
    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_Barter, &msg_guess, 0x44, 1);
    if (field15C_guess != 0) {
        char buf_guess[0x400];
        FUN_0046da4a_guess(buf_guess, 0x17a9, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        AppendColoredText_guess(buf_guess, 0xf);
        g_globalHandler_guess.WriteBarterLog_guess(buf_guess);
    }
    field1C8_guess = GetClientTime_guess();
}

// Big130 fields 0x208..0x273 as Load writes them, through this.
struct LoadFields_guess {
    char pad000_guess[0x208];
    char active208_guess;       // 0x208
    char pad209_guess[3];       // 0x209
    int field20c_guess;         // 0x20C
    char pad210_guess[0x1C];    // 0x210
    char flag22c_guess;         // 0x22C
    char name22d_guess[0x43];   // 0x22D
    int value270_guess;         // 0x270
};

// Pool element fields read by Load (0x4C bytes).
struct ChunkFields_guess {
    char name_guess[0x40];      // 0x00
    int field40_guess;          // 0x40
    int value44_guess;          // 0x44
    char tail_guess[4];         // 0x48
};

static ChunkFields_guess* ChunkAt_guess(Pool_guess* pool_guess, int index_guess) {
    return (ChunkFields_guess*)&pool_guess->chunks_guess[index_guess >> pool_guess->shift_guess]
        [index_guess & pool_guess->mask_guess];
}

// A clicked search result starts a new buy line: item id, icon and name copied, turned on.
// FUNCTION: TITANIUM 0x004E1984
void CBarterWnd_guess::SelectSearchResult_guess(int value_guess) {
    Teardown_guess();
    entry_guess.Clear_guess();
    LoadFields_guess* self_guess = (LoadFields_guess*)this;
    self_guess->active208_guess = 1;
    self_guess->flag22c_guess = 1;
    int index_guess = ((CListWndView_guess*)dispatch160_guess)->GetItemData(value_guess);
    self_guess->field20c_guess = ChunkAt_guess((Pool_guess*)&second_guess, index_guess)->field40_guess;
    self_guess->value270_guess = ChunkAt_guess((Pool_guess*)&second_guess, index_guess)->value44_guess;
    strcpy(self_guess->name22d_guess, ChunkAt_guess((Pool_guess*)&second_guess, index_guess)->name_guess);
    if (release164_guess != 0) {
        release164_guess->ClearAllSel();
    }
    ShowEditedLine_guess(0);
    UpdateButtons_guess();
}

// A clicked buy line is copied in for editing.
// FUNCTION: TITANIUM 0x004E1A54
void CBarterWnd_guess::SelectBuyLine_guess(int value_guess) {
    Close_guess();
    entry_guess.Clear_guess();
    int index_guess = lookup_guess->GetItemData(value_guess);
    entry_guess.Assign_guess(EQ_GLOBAL(BigArray_guess, 0x0079C198).Get_guess(index_guess));
    ShowEditedLine_guess(0);
    UpdateButtons_guess();
}

// On open: loads the buy lines, rebuilds the inventory, clears the search and status, shows the welcome
// message (0x79D77C) and disables UpdateWelcomeButton until it is edited.
// FUNCTION: TITANIUM 0x004E2159
void CBarterWnd_guess::Activate_guess() {
    g_globalHandler_guess.LoadBuyLines_guess();
    entry_guess.Clear_guess();
    ((RefreshList_guess*)this)->RebuildInventoryList_guess();
    ((Panel_guess*)this)->Reset_guess();
    ShowEditedLine_guess(false);
    UpdateButtons_guess();
    if (field15C_guess != 0) {
        Str_guess text_guess(g_fieldText_guess);
        field15C_guess->SetWindowTextA(&text_guess);
    }
    if (dispatch1B0_guess != 0) {
        Str_guess text_guess(g_textSource130_guess.Ptr_guess());
        dispatch1B0_guess->Slot63_guess(&text_guess);
    }
    if (toggle1B4_guess != 0) {
        toggle1B4_guess->flag5D_guess = 0;
    }
}

struct MessageChunk130_guess {
    char pad_guess[0x40];
    int first_guess;
    int second_guess;
    int third_guess;
};

struct CompareData130_guess {
    int pad_guess;
    CXStr first_guess;
    int pad08_guess;
    CXStr second_guess;
    int pad10_guess;
    int result_guess;
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_modeToggle130_guess EQ_GLOBAL(char, 0x0079D778)

// EXTERNAL: TITANIUM 0x0060ACA0 CopyCXStr130_guess
void __cdecl CopyCXStr130_guess(CXStr* destination_guess, const CXStr* source_guess);

// EXTERNAL: TITANIUM 0x00574460 CompareText130_guess
int __cdecl CompareText130_guess(char* first_guess, char* second_guess);

// WndNotification. Right click (3) on a search result sends OP_Barter action 21 with the record's +0x40 and
// +0x48 words, flag 2 when keyboard flag 1 is held (CXWndManager::GetKeyboardFlags on 0x99D3EC). Enter (6)
// in the search box searches. Clicks (1) go to the buttons above; 16 compares two strings for a list sort;
// 31 is a quantity answer. A change (14) in WelcomeEdit enables UpdateWelcomeButton; in CountEdit it clamps
// the quantity to 0-999.
// FUNCTION: TITANIUM 0x004E223B
// @early-stop: budget, structural ndiff=142
int CBarterWnd_guess::WndNotification_guess(OnQuantityAnswer_guess* sender_guess, int message_guess,
    void* data_guess) {
    if (message_guess != 14 ||
        (sender_guess == (OnQuantityAnswer_guess*)textDispatch1b0_guess &&
         toggle1B4_guess != 0 && (toggle1B4_guess->flag5D_guess = 1))) {
    if (message_guess == 3) {
            if (sender_guess == dispatch160_guess) {
            CListWndView_guess** lookupLink_guess = &lookup160_guess;
            int index_guess = (*lookupLink_guess)->GetCurSel();
                if (index_guess != -1) {
                int record_guess = (*lookupLink_guess)->GetItemData(index_guess);
                    int values_guess[4];
                    int offset_guess =
                        (record_guess & second_guess.mask_guess) * 0x4C;
                    int row_guess = record_guess >> second_guess.shift_guess;
                    values_guess[0] = 0x15;
                    int* words_guess = (int*)second_guess.chunks_guess[row_guess];
                    values_guess[1] = words_guess[offset_guess / 4 + 16];
                    offset_guess = (record_guess & second_guess.mask_guess) * 0x4C;
                    row_guess = record_guess >> second_guess.shift_guess;
                    words_guess = (int*)second_guess.chunks_guess[row_guess];
                    values_guess[2] = words_guess[offset_guess / 4 + 18];
                    values_guess[3] = 0;
                    if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0) {
                        values_guess[3] |= 2;
                    }
                    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_Barter,
                        values_guess, 0x10, 1);
                }
            } else {
                return Big130Base_guess::WndNotification(sender_guess, message_guess, data_guess);
            }
        }

        if (message_guess == 6) {
            if (sender_guess == (OnQuantityAnswer_guess*)textDispatch170_guess &&
                toggle174_guess != 0 && toggle174_guess->flag5D_guess != 0) {
                SearchItems_guess(textDispatch170_guess->GetText_guess());
            } else {
                return Big130Base_guess::WndNotification(sender_guess, message_guess, data_guess);
            }
        }

        if (message_guess == 1) {
            if (sender_guess == dispatch1b8_guess) {
                ((RefreshList_guess*)this)->RebuildInventoryList_guess();
                return 0;
            }

            if (sender_guess == (OnQuantityAnswer_guess*)toggle1B4_guess) {
                toggle1B4_guess->flag5D_guess = 0;
                if (textDispatch1b0_guess != 0) {
                    CXStr sourceText_guess = textDispatch1b0_guess->GetText_guess();
                    CXStr text_guess;
                    CopyCXStr130_guess(&text_guess, &sourceText_guess);
                    g_globalHandler_guess.SetWelcomeMessage_guess(text_guess);
                }
            }

            if (sender_guess == (OnQuantityAnswer_guess*)toggle174_guess &&
                textDispatch170_guess != 0) {
                SearchItems_guess(textDispatch170_guess->GetText_guess());
            } else if (sender_guess == dispatch160_guess) {
                SelectSearchResult_guess(((CListWndView_guess*)dispatch160_guess)->GetCurSel());
            } else if (sender_guess == (OnQuantityAnswer_guess*)lookup_guess) {
                SelectBuyLine_guess(lookup_guess->GetCurSel());
            } else if (sender_guess == wnd178_guess) {
                AddCompensationItem_guess(-1);
            } else if (sender_guess == control17c_guess) {
                ((ModeDispatch_guess*)this)->RemoveCompensationItem_guess(-1);
            } else if (sender_guess == digit3_guess) {
                ((ModeDispatch_guess*)this)->SetCompensationCoin_guess(sender_guess, 0, -1);
            } else if (sender_guess == digit2_guess) {
                ((ModeDispatch_guess*)this)->SetCompensationCoin_guess(sender_guess, 1, -1);
            } else if (sender_guess == digit1_guess) {
                ((ModeDispatch_guess*)this)->SetCompensationCoin_guess(sender_guess, 2, -1);
            } else if (sender_guess == digit0_guess) {
                ((ModeDispatch_guess*)this)->SetCompensationCoin_guess(sender_guess, 3, -1);
            } else if (sender_guess == control190_guess) {
                AddBuyLine_guess();
            } else if (sender_guess == control19c_guess) {
                ModifyBuyLine_guess();
            } else if (sender_guess == control1a0_guess) {
                ((TargetOwner_guess*)this)->ToggleSelectedBuyLine_guess();
            } else if (sender_guess == control198_guess) {
                RemoveBuyLine_guess();
            } else if (sender_guess == control1a8_guess) {
                if (field15C_guess != 0) {
                    Str_guess text_guess(g_fieldText_guess);
                    field15C_guess->SetWindowTextA(&text_guess);
                }
            } else if (sender_guess == control1a4_guess) {
                PrintActiveLines_guess();
            } else if (sender_guess == control1ac_guess) {
                g_globalHandler_guess.SetBuyerMode_guess(g_modeToggle130_guess == 0);
            }
        }

        if (message_guess != 15) {
            if (message_guess == 16) {
                CompareData130_guess* compare_guess = (CompareData130_guess*)data_guess;
                compare_guess->result_guess = CompareText130_guess(
                    compare_guess->first_guess, compare_guess->second_guess);
            } else if (message_guess == 31) {
                ((ModeDispatch_guess*)this)->OnQuantityAnswer_guess(*(int*)data_guess);
            }
        }

    }

    if (message_guess == 14 && sender_guess == count194_guess) {
        int value_guess;
        {
            CXStr countText_guess;
            CXStr* resultText_guess =
                ((EditText130_guess*)sender_guess)->GetText_guess(&countText_guess);
            value_guess = atoi(*resultText_guess);
        }
        if (value_guess < 0) {
            value_guess = 0;
        }
        if (999 < value_guess) {
            value_guess = 999;
        }
        entry_guess.count_guess = value_guess;
        {
            CXStr display_guess(_itoa(value_guess, g_itoaBuffer_guess, 10));
            ((TextDispatch130_guess*)sender_guess)->SetText_guess(&display_guess);
        }
        UpdateButtons_guess();
    }

    return Big130Base_guess::WndNotification(sender_guess, message_guess, data_guess);
}

