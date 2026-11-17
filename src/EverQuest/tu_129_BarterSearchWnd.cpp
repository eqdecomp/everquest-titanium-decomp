// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 129: a hint from compare/tumap.py.
// The Barter search window (OP_Barter 0x7460 traffic): your inventory, the buy lines other players post,
// and selling to them. CBarterSearchWnd_guess, Outer_guess and TrackerLayouts_guess are views of one window
// (vtable 0x6500E8), probably CBarterSearchWnd (the file sits between CAlarmWnd and CBazaarSearchWnd).
// Lists: +0x15C inventory, +0x160 buy lines, +0x164 the selected line's wanted items.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct Flag_guess {
    char pad00_guess[0x5d];
    bool enabled_005d_guess;
};

struct CListWndView_guess {
    char pad000_guess[0x11c];
    int count_guess;  // 0x11c
    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView_guess::GetItemData
    int GetItemData(int index_guess);
};

struct EntryIndex_guess {
    int count_guess;
    // EXTERNAL: TITANIUM 0x00409340 EntryIndex_guess::Get_guess
    int* Get_guess(int index_guess);
};

struct E70_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    EntryIndex_guess index0c_guess;
    char pad10_guess[0x0c];
    unsigned int field1c_guess;
    unsigned int field20_guess;
    char pad24_guess[1];
    char name25_guess[0x43];
    unsigned int field68_guess;
    unsigned int field6c_guess;
    // EXTERNAL: TITANIUM 0x005E41E0 E70_guess::E70_guess
    E70_guess();
    // EXTERNAL: TITANIUM 0x005E4260 E70_guess::~E70_guess
    ~E70_guess();
    // EXTERNAL: TITANIUM 0x00409BFD E70_guess::CopyFrom_guess
    E70_guess* CopyFrom_guess(const E70_guess* source_guess);
    // EXTERNAL: TITANIUM 0x004DD54B E70_guess::DeleteVector_guess
    void* DeleteVector_guess(unsigned int flags_guess);
};

struct Throw_guess {
    // EXTERNAL: TITANIUM 0x00405492 Throw_guess::Fail
    __declspec(noreturn) void Fail();
};

struct Cc_guess : Throw_guess {
    int count;
    E70_guess* data;
    int capacity_guess;
    unsigned char flag_guess;
    E70_guess& Get(int i);
    // EXTERNAL: TITANIUM 0x004DEB5A Cc_guess::Reserve_guess
    void Reserve_guess(int requested_guess);
    // EXTERNAL: TITANIUM 0x004DEB1B Cc_guess::Clear_guess
    void Clear_guess();
    void Assign_guess(int index_guess, const E70_guess* row_guess);
};

struct Manager_guess {
    char bytes_guess[0x1c];
    // EXTERNAL: TITANIUM 0x00572300 Manager_guess::Find_guess
    void* Find_guess(const char* name_guess);
};

struct Receiver_guess {
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
    virtual void SetLayout_guess(void* layout_guess);
};

struct ReceiverLayouts_guess {
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
    virtual void SetLayout_guess(void* layout_guess);
};

struct CBarterSearchWnd_guess {
    char pad000_guess[0x5c];
    bool flag05c_guess;
    char pad05d_guess[0x140 - 0x5d];
    Manager_guess manager_guess;
    void* unused15c_guess;
    CListWndView_guess* check160_guess;
    CListWndView_guess* check164_guess;
    char pad168_guess[8];
    Flag_guess* flag170_guess;
    char pad174_guess[4];
    Flag_guess* flag178_guess;
    char pad17c_guess[4];
    Flag_guess* flag180_guess;
    Receiver_guess* receiver184_guess;
    Receiver_guess* receiver188_guess;
    bool flag18c_guess;
    char pad18d_guess[3];
    Cc_guess cc190_guess;
    char pad1a0_guess[0x1c];
    int state1bc_guess;
    unsigned int time1c0_guess;
    unsigned int time1c4_guess;
    int field1c8_guess;
    unsigned int time1cc_guess;
    unsigned int field1d0_guess;

    // EXTERNAL: TITANIUM 0x005A1EF0 CBarterSearchWnd_guess::LoadIniListWnd
    void LoadIniListWnd(void* item_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 CBarterSearchWnd_guess::IsReady_guess
    char IsReady_guess();
    void UpdateButtons_guess();
    void LoadIniInfo_guess();
    void SellToBuyer_guess(int message_guess);
    void AddBuyLine_guess(int id_guess, const E70_guess* row_guess);
    void SearchBuyLines_guess(const char* source_guess);
    void ShowBuyLine_guess(int index_guess);
    void GoToBuyer_guess(int index_guess);
    void RebuildList_guess();
    void Reset_guess();
    bool RefreshCondition_guess();
    int OnProcessFrame_guess();
};

struct ConditionOwner_guess {
    // EXTERNAL: TITANIUM 0x005F6CC0 ConditionOwner_guess::CListWndView_guess
    char CListWndView_guess(unsigned int value_guess);
};

#define g_conditionOwner_guess EQ_GLOBAL(ConditionOwner_guess*, 0x00905CC0)
#define g_conditionValue_guess EQ_GLOBAL(unsigned int, 0x00924470)

struct TrackerLayouts_guess {
    char pad000_guess[0x140];
    Manager_guess manager_guess;
    void* unused15c_guess;
    void* unused160_guess;
    void* detail164_guess;
    char pad168_guess[0x1c];
    ReceiverLayouts_guess* receiver184_guess;
    ReceiverLayouts_guess* receiver188_guess;

    // EXTERNAL: TITANIUM 0x005A1FE0 TrackerLayouts_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(void* item_guess, const char* name_guess);
    void StoreIniInfo_guess();
};

// EXTERNAL: TITANIUM 0x0046D655 ReadClock_guess
unsigned int __cdecl ReadClock_guess();

// Button states: Search (+0x170), Sell (+0x180, needs a picked wanted item) and Find (+0x178).
// FUNCTION: TITANIUM 0x004DE4CB
void CBarterSearchWnd_guess::UpdateButtons_guess()
{
    bool first_guess = false;
    bool second_guess = false;
    bool third_guess = false;
    unsigned int now_guess = ReadClock_guess();
    // Search re-enables 4 s after the last search.
    if (now_guess > time1c4_guess + 4000) first_guess = true;
    if (check164_guess != 0)
        second_guess = check164_guess->GetCurSel() != -1;
    now_guess = ReadClock_guess();
    // Find: 15 s after the last find, with a buy line selected.
    if (now_guess > time1cc_guess + 15000)
        third_guess = state1bc_guess != -1;
    if (flag170_guess != 0) flag170_guess->enabled_005d_guess = first_guess;
    if (flag180_guess != 0) flag180_guess->enabled_005d_guess = second_guess;
    if (flag178_guess != 0) flag178_guess->enabled_005d_guess = third_guess;
}

// LoadIniInfo side: restores the three lists' columns (LoadIniListWnd 0x5A1EF0) and both layouts.
// FUNCTION: TITANIUM 0x004DE55A
void CBarterSearchWnd_guess::LoadIniInfo_guess()
{
    if (check160_guess != 0) LoadIniListWnd(check160_guess, "ItemList");
    if (unused15c_guess != 0) LoadIniListWnd(unused15c_guess, "InventoryList");
    if (check164_guess != 0) LoadIniListWnd(check164_guess, "DetailList");
    if (receiver184_guess != 0)
        receiver184_guess->SetLayout_guess(manager_guess.Find_guess("MainLayout"));
    if (receiver188_guess != 0)
        receiver188_guess->SetLayout_guess(manager_guess.Find_guess("MatchLayout"));
}

// StoreIniInfo side: saves the same lists and layouts (0x5A1FE0).
// FUNCTION: TITANIUM 0x004DE5F6
void TrackerLayouts_guess::StoreIniInfo_guess()
{
    if (unused160_guess != 0) StoreIniListWnd_guess(unused160_guess, "ItemList");
    if (unused15c_guess != 0) StoreIniListWnd_guess(unused15c_guess, "InventoryList");
    if (detail164_guess != 0) StoreIniListWnd_guess(detail164_guess, "DetailList");
    if (receiver184_guess != 0)
        receiver184_guess->SetLayout_guess(manager_guess.Find_guess("MainLayout"));
    if (receiver188_guess != 0)
        receiver188_guess->SetLayout_guess(manager_guess.Find_guess("MatchLayout"));
}

// Buy-line array: returns the 0x70-byte buy line at index `i`; an index out of range (or no storage)
// throws (0x00405492). The sell, wanted-items, list-fill and double-click handlers read lines through
// it.
// FUNCTION: TITANIUM 0x004DE692
E70_guess& Cc_guess::Get(int i)
{
    if (i < count && i >= 0 && data) return data[i];
    Fail();
}

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_messageTarget_guess EQ_GLOBAL(unsigned int, 0x00905CA0)

// Sells to the selected buy line (24 bytes): buyer spawn id (+0x6C), +0x20, wanted-item row
// `message_guess`, and that row's first word, or the line's own (+0x04) for -1.
// FUNCTION: TITANIUM 0x004DE6C2
void CBarterSearchWnd_guess::SellToBuyer_guess(int message_guess)
{
    if (check160_guess != 0) {
        int index_guess = check160_guess->GetCurSel();
        if (index_guess != -1) {
            int slot_guess = check160_guess->GetItemData(index_guess);
            int messageData_guess[6];
            // Barter action 0xE: sell to a buyer.
            messageData_guess[0] = 0xe;
            messageData_guess[3] = message_guess;
            messageData_guess[2] = cc190_guess.Get(slot_guess).field20_guess;
            messageData_guess[1] = cc190_guess.Get(slot_guess).field6c_guess;
            if (message_guess != -1) {
                messageData_guess[4] = *cc190_guess.Get(slot_guess).index0c_guess.Get_guess(message_guess);
            } else {
                messageData_guess[4] = cc190_guess.Get(slot_guess).field04_guess;
            }
            if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0)
                // Shift held: 2, probably the whole stack. Without shift this word goes out uninitialized.
                messageData_guess[5] = 2;
            EQSendMessage(&g_messageTarget_guess, OP_Barter, messageData_guess, 0x18, 1);
        }
    }
}

struct ExpandTable_guess {
    char pad00_guess[4];
    int blockSize_guess;
    char pad08_guess[4];
    unsigned int shift_guess;
    void** buckets_guess;
    int bucketCount_guess;
    bool enabled_guess;

    // EXTERNAL: TITANIUM 0x0051DA09 ExpandTable_guess::GetCapacity_guess
    int GetCapacity_guess(int requested_guess);
    // EXTERNAL: TITANIUM 0x004B73EE ExpandTable_guess::ClearBuckets_guess
    void ClearBuckets_guess();
    // EXTERNAL: TITANIUM 0x00405492 ExpandTable_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    void Grow_guess(int requested_guess);
};

// EXTERNAL: TITANIUM 0x0060E985 operator_new_guess
void* __cdecl operator_new_guess(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* block_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free_guess
extern "C" void __cdecl free_guess(void* memory_guess);

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// Grows the chunked array to hold `requested_guess` elements: ((n - 1) >> shift) + 1 blocks (0x0051DA09);
// a larger block-pointer table takes the old pointers and new blocks of blockSize * 80 bytes. On a failed
// allocation the array is freed (0x004B73EE) and the error path throws (0x00405492).
// FUNCTION: TITANIUM 0x004DEC3B
void ExpandTable_guess::Grow_guess(int requested_guess)
{
    if (enabled_guess && requested_guess > 0) {
        requested_guess = GetCapacity_guess(requested_guess);
        if (requested_guess > bucketCount_guess) {
            void** newBuckets_guess = (void**)operator_new_guess(requested_guess * 4);
            if (newBuckets_guess == 0) {
                enabled_guess = false;
            } else {
                int copyIndex_guess = 0;
                while (copyIndex_guess < bucketCount_guess) {
                    newBuckets_guess[copyIndex_guess] = buckets_guess[copyIndex_guess];
                    ++copyIndex_guess;
                }
                int bucket_guess = bucketCount_guess;
                while (bucket_guess < requested_guess) {
                    newBuckets_guess[bucket_guess] = operator_new_guess(blockSize_guess * 80);
                    if (newBuckets_guess[bucket_guess] == 0) {
                        enabled_guess = false;
                        break;
                    }
                    ++bucket_guess;
                }
                if (enabled_guess) {
                    _free(buckets_guess);
                    buckets_guess = newBuckets_guess;
                    bucketCount_guess = requested_guess;
                }
            }
        }
        if (!enabled_guess) {
            ClearBuckets_guess();
            Fail_guess();
        }
    }
}

struct VectorContents_guess {
    // EXTERNAL: TITANIUM 0x004DD54B VectorContents_guess::Destroy_guess
    void Destroy_guess(unsigned int flags_guess);
};

struct Table_guess {
    int field00_guess;
    VectorContents_guess* field04_guess;
    unsigned int field08_guess;
    int field0c_guess;
    int* field10_guess;

    void Clear_guess();
    void ClearForward_guess();
    int GetIndex_guess(int index_guess);
};

struct Record_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0c_guess;
    char name_guess[0x40];  // 0x10
};

// Frees the buy-line array (vector delete, flag 3) and zeroes its pointer, capacity and count. A new
// search, the results reset and the window destructor call it.
// FUNCTION: TITANIUM 0x004DEB1B
void Table_guess::Clear_guess()
{
    if (field04_guess != 0) {
        field04_guess->Destroy_guess(3);
    }
    field04_guess = 0;
    field08_guess = 0;
    field00_guess = 0;
}

// Chunked array of 0x50-byte inventory rows: returns the address of row `index` (block index >> shift,
// slot index & mask). The inventory list code here and in the barter window uses it.
// FUNCTION: TITANIUM 0x004DEB39
int Table_guess::GetIndex_guess(int index_guess)
{
    return (field08_guess & index_guess) * 80 +
        field10_guess[index_guess >> field0c_guess];
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

// Grows the buy-line array to twice the request plus 8 (0x70-byte rows), copying the old rows over.
// FUNCTION: TITANIUM 0x004DEB5A
void Cc_guess::Reserve_guess(int requested_guess)
{
    if (requested_guess == 0 || (requested_guess <= capacity_guess && data != 0)) {
        return;
    }

    int newCapacity_guess = requested_guess * 2 + 8;
    E70_guess* newData_guess = new E70_guess[newCapacity_guess];

    if (newData_guess != 0) {
        if (data != 0) {
            for (int index_guess = 0; index_guess < count; ++index_guess) {
                newData_guess[index_guess].CopyFrom_guess(&data[index_guess]);
            }
        }
        if (data != 0) {
            data->DeleteVector_guess(3);
        }
        data = newData_guess;
        capacity_guess = newCapacity_guess;
    } else {
        if (data != 0) {
            data->DeleteVector_guess(3);
        }
        data = 0;
        capacity_guess = 0;
        flag_guess = 0;
    }
}

// EXTERNAL: TITANIUM 0x0060E620 strncpy
extern "C" char* __cdecl strncpy(char* destination_guess, const char* source_guess, unsigned int count_guess);

struct Message_guess {
    int kind_guess;
    char name_guess[64];
    unsigned int time_guess;
};

struct Panel_guess {
    // EXTERNAL: TITANIUM 0x004797D5 Panel_guess::FacePlayer_guess
    void FacePlayer_guess(void* item_guess);
};

#define g_panel_guess EQ_GLOBAL(Panel_guess*, 0x00905CE4)

struct Window_guess {
    // EXTERNAL: TITANIUM 0x004C13D7 Window_guess::Cancel_guess
    void Cancel_guess();
    // EXTERNAL: TITANIUM 0x004C251B Window_guess::Show_guess
    void Show_guess(void* item_guess);
};

#define g_playerPath_guess EQ_GLOBAL(Window_guess*, 0x00985C88)

// EXTERNAL: TITANIUM 0x00401B28 Lookup_guess
void* __cdecl Lookup_guess(unsigned int id_guess);

// Every 300 ms while shown: button states, and the buy-line list when new lines came in.
// FUNCTION: TITANIUM 0x004DECED
int CBarterSearchWnd_guess::OnProcessFrame_guess()
{
    if (flag05c_guess) {
        unsigned int now_guess = ReadClock_guess();
        if (now_guess > time1c0_guess + 300) {
            time1c0_guess = now_guess;
            UpdateButtons_guess();
            if (flag18c_guess) RebuildList_guess();
        }
    }
    return ((CXWnd*)this)->OnProcessFrame();
}

// Searches buy lines for item name `source_guess` (Barter action 1, 72 bytes: name and a timestamp that
// tags the replies), dropping the old results.
// FUNCTION: TITANIUM 0x004DED2E
void CBarterSearchWnd_guess::SearchBuyLines_guess(const char* source_guess)
{
    Message_guess message_guess;
    message_guess.kind_guess = 1;
    strncpy(message_guess.name_guess, source_guess, 0x3f);
    message_guess.name_guess[63] = 0;
    unsigned int now_guess = ReadClock_guess();
    time1c4_guess = now_guess;
    message_guess.time_guess = now_guess;
    field1c8_guess = now_guess;
    EQSendMessage(&g_messageTarget_guess, OP_Barter, &message_guess, 0x48, 1);
    flag170_guess->enabled_005d_guess = false;
    ShowBuyLine_guess(-1);
    cc190_guess.Clear_guess();
    flag18c_guess = true;
}

// Double-click on buy line `index_guess`: selects it, hands the buyer to the local player (0x905CE4,
// 0x4797D5, probably targeting) and, at most every 15 s, starts Find Path to them (0x985C88).
// FUNCTION: TITANIUM 0x004DEDB8
void CBarterSearchWnd_guess::GoToBuyer_guess(int index_guess)
{
    if (index_guess < check160_guess->count_guess) {
        int slot_guess = check160_guess->GetItemData(index_guess);
        ShowBuyLine_guess(slot_guess);
        if (slot_guess >= 0 && slot_guess < cc190_guess.count) {
            void* item_guess = Lookup_guess(cc190_guess.Get(slot_guess).field6c_guess);
            if (item_guess != 0) {
                field1d0_guess = cc190_guess.Get(slot_guess).field6c_guess;
                g_panel_guess->FacePlayer_guess(item_guess);
                g_playerPath_guess->Cancel_guess();
                unsigned int now_guess = ReadClock_guess();
                if (now_guess > time1cc_guess + 15000) {
                    g_playerPath_guess->Show_guess(item_guess);
                    flag178_guess->enabled_005d_guess = false;
                    time1cc_guess = ReadClock_guess();
                }
            }
        }
    }
}

// Tail call to the buy-line array clear (0x004DEB1B); reached only from exception-unwind code.
// FUNCTION: TITANIUM 0x004DEE72
void Table_guess::ClearForward_guess()
{
    Clear_guess();
}

// Stores buy line `value` at `index` (copy 0x00409BFD), first growing the array (0x004DEB5A) when
// `index` is past the end; negative indexes are ignored. Used when a buy line arrives (0x004DF70E).
// FUNCTION: TITANIUM 0x004DEE77
void Cc_guess::Assign_guess(int index_guess, const E70_guess* row_guess)
{
    if (index_guess < 0) return;
    if (index_guess >= count) {
        Reserve_guess(index_guess + 1);
        if (data != 0) count = index_guess + 1;
    }
    if (data != 0) data[index_guess].CopyFrom_guess(row_guess);
}

struct Source_guess {
    char pad00_guess[0x1c];
    void* inner1c_guess;
    char pad20_guess[0x28];
    int field48_guess;  // 0x48
    char pad4c_guess[0x0c];
    int field58_guess;  // 0x58

    // EXTERNAL: TITANIUM 0x005DFC50 Source_guess::IsValid_guess
    bool IsValid_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Source_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0F60 Source_guess::GetKind_guess
    int GetKind_guess();
    // EXTERNAL: TITANIUM 0x005ECC90 Source_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Source_guess::GetName_guess
    char* GetName_guess();
};

struct OuterBase_guess {
    char pad004_guess[0x62];
    unsigned char flags66_guess;
    char pad067_guess[0x124 - 0x67];
    void* sidlPiece_guess;            // 0x124
    char pad128_guess[0x158 - 0x128];
    int field158_guess;
    // EXTERNAL: TITANIUM 0x005A3850 OuterBase_guess::OuterBase_guess
    OuterBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int iniVersion_guess,
        char* block_guess);
    // EXTERNAL: TITANIUM 0x005A3100 OuterBase_guess::~OuterBase_guess
    virtual ~OuterBase_guess();
};

struct Table190_guess {
    int field00_guess;
    void* field04_guess;
    unsigned int field08_guess;
    bool field0c_guess;
    char pad0d_guess[3];

    Table190_guess() {
        field04_guess = 0;
        field00_guess = 0;
        field08_guess = 0;
        field0c_guess = true;
    }
    // EXTERNAL: TITANIUM 0x004DEB1B Table190_guess::Clear_guess
    void Clear_guess();
};

struct Expand1a0_guess : Table_guess {
    // EXTERNAL: TITANIUM 0x0047C3AF Expand1a0_guess::Expand1a0_guess
    Expand1a0_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x004B73EE Expand1a0_guess::ClearBuckets_guess
    void ClearBuckets_guess();
    // EXTERNAL: TITANIUM 0x004E16E1 Expand1a0_guess::Add_guess
    void Add_guess(int index_guess, Record_guess* record_guess);
};

struct WndFlags_guess {
    char pad000_guess[0x66];
    unsigned char flags66_guess;
};

struct ListBox_guess : CListWnd {
    char pad140_guess[0x14];
    int field154_guess;
    bool flag158_guess;
    unsigned char field159_guess;
    char pad15a_guess[2];
    unsigned char field15c_guess;
    char pad15d_guess[3];
    int field160_guess;
    char pad164_guess[8];
    int field16c_guess;
    // EXTERNAL: TITANIUM 0x005981F0 ListBox_guess::SetRowHeight_guess
    void SetRowHeight_guess(int row_guess, int height_guess);
    // EXTERNAL: TITANIUM 0x00597C00 ListBox_guess::GetCount_guess
    int GetCount_guess();
};

struct EditBox_guess {
    // EXTERNAL: TITANIUM 0x004D7EBC EditBox_guess::SetMaxChars_guess
    void SetMaxChars_guess(int max_guess);
};

struct EverQuestFind_guess {
    // EXTERNAL: TITANIUM 0x004AE919 EverQuestFind_guess::ReadFlag_guess
    int ReadFlag_guess(const char* window_guess, const char* key_guess, int a_guess, int b_guess);
};

// EXTERNAL: TITANIUM 0x006500E8 ??_7Outer_guess@@6B@
struct Outer_guess : OuterBase_guess {
    union {
        ListBox_guess* inventory_guess; // 0x15c
        CListWnd* list15c_guess;
    };
    ListBox_guess* buyLine_guess;     // 0x160
    ListBox_guess* details_guess;    // 0x164
    EditBox_guess* itemSearch_guess; // 0x168
    CXWnd* refresh_guess;            // 0x16c
    CXWnd* search_guess;             // 0x170
    CXWnd* welcome_guess;            // 0x174
    CXWnd* find_guess;               // 0x178
    CButtonWnd* hide_guess;           // 0x17c
    CXWnd* request_guess;            // 0x180
    CXWnd* layout_guess;             // 0x184
    CXWnd* buyLineLayout_guess;      // 0x188
    char pad18c_guess[4];
    Table190_guess table190_guess;    // 0x190
    Expand1a0_guess expand1a0_guess;  // 0x1a0
    char pad1b4_guess[0xc];
    int field1c0_guess;
    int field1c4_guess;
    char pad1c8_guess[4];
    int field1cc_guess;
    int field1d0_guess;
    bool field1d4_guess;

    Outer_guess(CXWnd* parent_guess);
    ~Outer_guess();
    Outer_guess* ScalarDeletingDestructor_guess(unsigned int flags_guess);
    void AddInventoryItem_guess(Source_guess* source_guess);
    void RebuildList_guess();
    void RefreshInventory_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
};

// BarterSearchWnd constructor: sets up the inventory, buy-line and detail lists (colours, 24-pixel rows),
// limits the item search box to 64 characters, restores the HideBuyers check box from the UI INI
// (0x004AE919, copied to +0x1D4), then the saved lists and layouts (0x004DE55A).
// FUNCTION: TITANIUM 0x004DEEB6
// @early-stop: budget, structural ndiff=46
Outer_guess::Outer_guess(CXWnd* parent_guess)
    : OuterBase_guess(parent_guess, EQ_ARRAY(char, 0x00650208), -1, 1, 0),
      table190_guess(), expand1a0_guess(0x20)
{
    field1d0_guess |= -1;
    inventory_guess = 0;
    buyLine_guess = 0;
    details_guess = 0;
    itemSearch_guess = 0;
    search_guess = 0;
    welcome_guess = 0;
    find_guess = 0;
    hide_guess = 0;
    request_guess = 0;
    refresh_guess = 0;
    layout_guess = 0;
    buyLineLayout_guess = 0;
    field1c0_guess = 0;
    field1c4_guess = 0;
    field1cc_guess = 0;
    field1d4_guess = false;
    if (sidlPiece_guess != 0) {
        flags66_guess |= 1;
        field158_guess = 0x3b;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        inventory_guess = (ListBox_guess*)((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650044));
        buyLine_guess = (ListBox_guess*)((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0064FEC4));
        details_guess = (ListBox_guess*)((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x006500DC));
        itemSearch_guess = (EditBox_guess*)((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x006500CC));
        refresh_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x006500B4));
        welcome_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x006500A4));
        find_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650098));
        hide_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065008C));
        request_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650078));
        search_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650068));
        layout_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650060));
        buyLineLayout_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0064FEA8));
        if (itemSearch_guess != 0) {
            itemSearch_guess->SetMaxChars_guess(0x40);
        }
        if (inventory_guess != 0) {
            inventory_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            inventory_guess->SetColumnJustification(0, 0);
            inventory_guess->SetColumnJustification(1, 0);
            inventory_guess->SetColumnJustification(2, 1);
            inventory_guess->field16c_guess = 0xff8aa3ff;
            inventory_guess->field15c_guess = 1;
            inventory_guess->field159_guess = 1;
            inventory_guess->field160_guess = 0x18;
            inventory_guess->SetRowHeight_guess(0, 0x18);
            ((WndFlags_guess*)inventory_guess)->flags66_guess |= 4;
            inventory_guess->field154_guess = 1;
        }
        if (buyLine_guess != 0) {
            buyLine_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            buyLine_guess->SetColumnJustification(0, 0);
            buyLine_guess->SetColumnJustification(1, 0);
            buyLine_guess->SetColumnJustification(2, 1);
            buyLine_guess->SetColumnJustification(3, 1);
            buyLine_guess->field16c_guess = 0xff8aa3ff;
            buyLine_guess->field15c_guess = 1;
            buyLine_guess->field159_guess = 1;
            buyLine_guess->field160_guess = 0x18;
            buyLine_guess->SetRowHeight_guess(0, 0x18);
            ((WndFlags_guess*)buyLine_guess)->flags66_guess |= 4;
            buyLine_guess->field154_guess = 1;
        }
        if (details_guess != 0) {
            details_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            details_guess->SetColumnJustification(0, 0);
            details_guess->SetColumnJustification(1, 0);
            details_guess->SetColumnJustification(2, 1);
            details_guess->field16c_guess = 0xff8aa3ff;
            details_guess->field15c_guess = 1;
            details_guess->field159_guess = 1;
            details_guess->field160_guess = 0x18;
            details_guess->SetRowHeight_guess(0, 0x18);
        }
        if (hide_guess != 0) {
            int hideChecked_guess = ((EverQuestFind_guess*)pEverQuest)->ReadFlag_guess(
                EQ_ARRAY(char, 0x00650208), EQ_ARRAY(char, 0x00650054), 0, 1);
            hide_guess->SetCheck(hideChecked_guess);
            field1d4_guess = hide_guess->Checked;
        }
        ((CBarterSearchWnd_guess*)this)->LoadIniInfo_guess();
    }
}

// Adds an inventory item to the inventory rows, merging stacks of the same id (+0x48 is the stack count).
// FUNCTION: TITANIUM 0x004DF643
void Outer_guess::AddInventoryItem_guess(Source_guess* source_guess)
{
    if (!source_guess->IsValid_guess()) return;
    for (int index_guess = 0; index_guess < expand1a0_guess.field00_guess; ++index_guess) {
        int entry_guess = expand1a0_guess.GetIndex_guess(index_guess);
        if (source_guess->GetItemId_guess() == *(int*)entry_guess) {
            ((Record_guess*)expand1a0_guess.GetIndex_guess(index_guess))->field08_guess +=
                source_guess->field48_guess;
            return;
        }
    }
    Record_guess record_guess;
    memset(&record_guess, 0, 0x50);
    record_guess.field00_guess = source_guess->GetItemId_guess();
    record_guess.field0c_guess = source_guess->GetKind_guess();
    if (source_guess->GetCount_guess() > 0)
        record_guess.field04_guess = source_guess->field58_guess;
    record_guess.field08_guess = source_guess->field48_guess;
    strcpy(record_guess.name_guess, source_guess->GetName_guess());
    expand1a0_guess.Add_guess(expand1a0_guess.field00_guess, &record_guess);
}

// Destructor of the barter search window (vtable 0x6500E8): empties the inventory row table (+0x1A0,
// 0x004B73EE) and frees the buy-line array (+0x190), then the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004DF479
Outer_guess::~Outer_guess()
{
    expand1a0_guess.ClearBuckets_guess();
    table190_guess.Clear_guess();
}

struct GlobalHandler_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 GlobalHandler_guess::GetIcon_guess
    int GetIcon_guess(int value_guess);
};

struct ListVt_guess {
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();
};

#define g_transform_guess EQ_GLOBAL(GlobalHandler_guess*, 0x00991910)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

struct Entry_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    char name0c_guess[0x40];
};

// Shows buy line `index_guess`'s wanted items: icon, name and +0x04 each.
// FUNCTION: TITANIUM 0x004DE785
// @early-stop: budget, structural ndiff=46
void CBarterSearchWnd_guess::ShowBuyLine_guess(int index_guess)
{
    if (index_guess != state1bc_guess) {
        int state_guess = -1;
        field1d0_guess = -1;
        if (check164_guess != 0) {
            ((ListVt_guess*)check164_guess)->Slot76_guess();
            if (index_guess >= 0 && index_guess < cc190_guess.count) {
                state_guess = index_guess;
                E70_guess& entry_guess = cc190_guess.Get(index_guess);
                field1d0_guess = entry_guess.field6c_guess;
                if (entry_guess.index0c_guess.count_guess > 0) {
                    int sub_guess = 0;
                    do {
                        Entry_guess* detail_guess = (Entry_guess*)entry_guess.index0c_guess.Get_guess(sub_guess);
                        int row_guess;
                        {
                            CXStr empty_guess(g_emptyString_guess);
                            row_guess = ((CListWnd*)check164_guess)->AddString(empty_guess, 0xffffffff, 0, 0);
                        }
                        EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), (CListWnd*)check164_guess)(
                            row_guess, 0, g_transform_guess->GetIcon_guess(detail_guess->field08_guess));
                        {
                            CXStr name_guess(detail_guess->name0c_guess);
                            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)check164_guess)(
                                row_guess, 1, name_guess);
                        }
                        {
                            CXStr value_guess(_itoa(detail_guess->field04_guess, g_itoaBuffer_guess, 10));
                            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)check164_guess)(
                                row_guess, 2, value_guess);
                        }
                        ++sub_guess;
                    } while (sub_guess < entry_guess.index0c_guess.count_guess);
                }
            }
        }
        state1bc_guess = state_guess;
    }
}

struct ItemName_guess {
    char pad000_guess[0x120];
    char name120_guess[1];
};

struct RowTable_guess {
    // EXTERNAL: TITANIUM 0x00409226 RowTable_guess::FormatPrice_guess
    CXStr FormatPrice_guess(const E70_guess* row_guess);
};

#define g_rows_guess EQ_GLOBAL(RowTable_guess, 0x0079C198)

// Fills the buy-line list: icon (+0x68), name with +0x1C in brackets, 0x409226's text, buyer name.
// FUNCTION: TITANIUM 0x004DE91E
void CBarterSearchWnd_guess::RebuildList_guess()
{
    flag18c_guess = false;
    if (check160_guess != 0) {
        ((ListVt_guess*)check160_guess)->Slot76_guess();
        for (int index_guess = 0; index_guess < cc190_guess.count; ++index_guess) {
            cc190_guess.Get(index_guess);
            ItemName_guess* item_guess =
                (ItemName_guess*)Lookup_guess(cc190_guess.Get(index_guess).field6c_guess);
            if (item_guess != 0) {
                int row_guess;
                {
                    CXStr empty_guess(g_emptyString_guess);
                    row_guess = ((CListWnd*)check160_guess)->AddString(empty_guess, 0xffffffff, index_guess, 0);
                }
                EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), (CListWnd*)check160_guess)(
                    row_guess, 0,
                    g_transform_guess->GetIcon_guess(cc190_guess.Get(index_guess).field68_guess));
                CXStr name_guess(cc190_guess.Get(index_guess).name25_guess);
                name_guess += "(";
                name_guess += _itoa(cc190_guess.Get(index_guess).field1c_guess, g_itoaBuffer_guess, 10);
                name_guess += ")";
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)check160_guess)(
                    row_guess, 1, name_guess);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)check160_guess)(
                    row_guess, 2, g_rows_guess.FormatPrice_guess(&cc190_guess.Get(index_guess)));
                CXStr value_guess(item_guess->name120_guess);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)check160_guess)(
                    row_guess, 3, value_guess);
            }
        }
        ((ListVt_guess*)check160_guess)->Slot78_guess();
    }
}

// Fills the inventory list: icon, name, total count.
// FUNCTION: TITANIUM 0x004DF4C2
void Outer_guess::RebuildList_guess()
{
    if (list15c_guess != 0) {
        ((ListVt_guess*)list15c_guess)->Slot76_guess();
        for (int index_guess = 0; index_guess < expand1a0_guess.field00_guess; ++index_guess) {
            int row_guess;
            {
                CXStr empty_guess(g_emptyString_guess);
                row_guess = list15c_guess->AddString(empty_guess, 0xffffffff, index_guess, 0);
            }
            EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list15c_guess)(
                row_guess, 0,
                g_transform_guess->GetIcon_guess(
                    ((Record_guess*)expand1a0_guess.GetIndex_guess(index_guess))->field0c_guess));
            {
                CXStr name_guess(((Record_guess*)expand1a0_guess.GetIndex_guess(index_guess))->name_guess);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list15c_guess)(
                    row_guess, 1, name_guess);
            }
            {
                CXStr value_guess(_itoa(
                    ((Record_guess*)expand1a0_guess.GetIndex_guess(index_guess))->field08_guess,
                    g_itoaBuffer_guess, 10));
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list15c_guess)(
                    row_guess, 2, value_guess);
            }
        }
        ((ListVt_guess*)list15c_guess)->Slot78_guess();
    }
}

// Scalar deleting destructor of the barter search window (vtable 0x6500E8 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004DF627
Outer_guess* Outer_guess::ScalarDeletingDestructor_guess(unsigned int flags_guess)
{
    Outer_guess::~Outer_guess();
    if ((flags_guess & 1) != 0) {
        free_guess(this);
    }
    return this;
}

// A buy line arrived: kept while 0x59DD30 holds (probably shown) and if it answers the current search
// (timestamp +0x1C8).
// FUNCTION: TITANIUM 0x004DF70E
void CBarterSearchWnd_guess::AddBuyLine_guess(int id_guess, const E70_guess* row_guess)
{
    if (IsReady_guess() && field1c8_guess == id_guess) {
        cc190_guess.Assign_guess(cc190_guess.count, row_guess);
        flag18c_guess = true;
    }
}

struct EQ_Item_guess {
    // EXTERNAL: TITANIUM 0x005DFC40 EQ_Item_guess::IsBlocked_guess
    char IsBlocked_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 EQ_Item_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 EQ_Item_guess::GetEntry_guess
    Source_guess* GetEntry_guess(int index_guess);
};

struct GroupPrefix_guess {
    virtual void Slot00_guess();
    int field04_guess;
};

struct GroupBase_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 GroupBase_guess::GetInventorySlot_guess
    EQ_Item_guess* GetInventorySlot_guess(unsigned int index_guess);
};

struct GroupOwner_guess : GroupPrefix_guess, virtual GroupBase_guess {
};

#define g_groupOwner_guess EQ_GLOBAL(GroupOwner_guess*, 0x00905D00)

// Rebuilds the inventory rows.
// FUNCTION: TITANIUM 0x004DF742
void Outer_guess::RefreshInventory_guess()
{
    expand1a0_guess.ClearBuckets_guess();
    // Slots 0-30, plus the contents of any bag among them.
    for (int row_guess = 0; row_guess <= 0x1e; ++row_guess) {
        EQ_Item_guess* group_guess = g_groupOwner_guess->GetInventorySlot_guess(row_guess);
        if (group_guess != 0) {
            AddInventoryItem_guess(reinterpret_cast<Source_guess*>(group_guess));
            if (group_guess->IsBlocked_guess()) {
                for (int sub_guess = 0; sub_guess < group_guess->GetCount_guess(); ++sub_guess) {
                    Source_guess* entry_guess = group_guess->GetEntry_guess(sub_guess);
                    if (entry_guess != 0) AddInventoryItem_guess(entry_guess);
                }
            }
        }
    }
    RebuildList_guess();
}

// Resets the window when the 0x5F6CC0 check on 0x924470 passes; returns whether it did.
// FUNCTION: TITANIUM 0x004DFBF4
bool CBarterSearchWnd_guess::RefreshCondition_guess()
{
    bool result_guess = false;
    if (g_conditionOwner_guess->CListWndView_guess(g_conditionValue_guess) != 0) {
        ++result_guess;
        Reset_guess();
    }
    return result_guess;
}

// Drops the search results and selection, then rebuilds the inventory list.
// FUNCTION: TITANIUM 0x004DFBC9
void CBarterSearchWnd_guess::Reset_guess()
{
    ShowBuyLine_guess(-1);
    cc190_guess.Clear_guess();
    RebuildList_guess();
    field1d0_guess = 0xffffffff;
    ((Outer_guess*)this)->RefreshInventory_guess();
}

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* left_guess, const char* right_guess);
// EXTERNAL: TITANIUM 0x00574460 Compare_guess
int __cdecl Compare_guess(const char* left_guess, const char* right_guess);

struct EverQuestSet_guess {
    // EXTERNAL: TITANIUM 0x004AE82A EverQuestSet_guess::Set_guess
    void Set_guess(bool value_guess, const char* window_guess, const char* key_guess);
};

struct EditVt_guess {
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
    virtual void Slot63_guess(const CXStr& text_guess);
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

struct CompareReq_guess {
    int kind_guess;
    CXStr left_guess;
    int leftIndex_guess;
    CXStr right_guess;
    int rightIndex_guess;
    int result_guess;
};

// Clicks: Refresh rebuilds inventory; an inventory row copies its name to ItemSearch; Search or Enter (6)
// searches; Sell sells the picked wanted item; Find paths to the buyer; Hide saves its check to the ini.
// Double-click (3): a wanted item sells it; a buy line sells at once when it is the only one, else is
// picked. 0xF/0x10 sort: name columns as text, the count column by +0x08, item count, then name.
// FUNCTION: TITANIUM 0x004DF7C1
// @early-stop: budget, structural ndiff=72
int Outer_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess)
{
    if (message_guess == 1) {
        if (sender_guess == refresh_guess) {
            RefreshInventory_guess();
            return 0;
        }
        if (sender_guess == inventory_guess) {
            int sel_guess = inventory_guess->GetCurSel();
            int data_guess2 = inventory_guess->GetItemData(sel_guess);
            if (itemSearch_guess != 0) {
                CXStr text_guess(((Record_guess*)expand1a0_guess.GetIndex_guess(data_guess2))->name_guess);
                ((EditVt_guess*)itemSearch_guess)->Slot63_guess(text_guess);
            }
        } else if (sender_guess == buyLine_guess) {
            ((CBarterSearchWnd_guess*)this)->ShowBuyLine_guess(buyLine_guess->GetItemData(buyLine_guess->GetCurSel()));
        } else if (sender_guess == search_guess) {
            if (itemSearch_guess != 0) {
                ((CBarterSearchWnd_guess*)this)->SearchBuyLines_guess(((EditVt_guess*)itemSearch_guess)->Slot76_guess());
            }
        } else if (sender_guess == welcome_guess) {
            // Welcome button: Barter action 0x11 (meaning not known).
            int code_guess = 0x11;
            EQSendMessage(&g_messageTarget_guess, OP_Barter, &code_guess, 4, 1);
        } else if (sender_guess == request_guess) {
            if (details_guess != 0) {
                int sel_guess = details_guess->GetCurSel();
                if (sel_guess != -1) ((CBarterSearchWnd_guess*)this)->SellToBuyer_guess(sel_guess);
            }
        } else if (sender_guess == find_guess) {
            int sel_guess = buyLine_guess->GetCurSel();
            if (sel_guess != -1) {
                int data_guess2 = buyLine_guess->GetItemData(sel_guess);
                void* item_guess = Lookup_guess(((CBarterSearchWnd_guess*)this)->cc190_guess.Get(data_guess2).field6c_guess);
                if (item_guess != 0) {
                    field1d0_guess = ((CBarterSearchWnd_guess*)this)->cc190_guess.Get(data_guess2).field6c_guess;
                    g_playerPath_guess->Cancel_guess();
                    g_playerPath_guess->Show_guess(item_guess);
                    find_guess->Enabled = 0;
                    field1cc_guess = ReadClock_guess();
                }
            }
        } else if (sender_guess == (CXWnd*)hide_guess) {
            ((EverQuestSet_guess*)pEverQuest)->Set_guess(hide_guess->Checked,
                EQ_ARRAY(char, 0x00650208), EQ_ARRAY(char, 0x00650054));
            field1d0_guess = -1;
            field1d4_guess = hide_guess->Checked;
            return 0;
        }
    } else if (message_guess == 6) {
        if (sender_guess == (CXWnd*)itemSearch_guess && search_guess != 0 && search_guess->Enabled != 0) {
            CXStr text_guess = ((EditVt_guess*)itemSearch_guess)->Slot76_guess();
            ((CBarterSearchWnd_guess*)this)->SearchBuyLines_guess(text_guess);
        }
    } else if (message_guess == 3) {
        if (sender_guess == details_guess) {
            ((CBarterSearchWnd_guess*)this)->SellToBuyer_guess((int)data_guess);
        }
        if (sender_guess == buyLine_guess) {
            if (buyLine_guess->GetCount_guess() < 2) {
                ((CBarterSearchWnd_guess*)this)->SellToBuyer_guess(-1);
            } else {
                ((CBarterSearchWnd_guess*)this)->GoToBuyer_guess((int)data_guess);
            }
        }
    } else if (message_guess == 0xf) {
        ListBox_guess* list_guess = (ListBox_guess*)sender_guess;
        if (sender_guess == buyLine_guess && data_guess != 0) {
            if (list_guess->field154_guess == (int)data_guess) {
                list_guess->flag158_guess = !list_guess->flag158_guess;
            } else {
                list_guess->field154_guess = (int)data_guess;
                list_guess->flag158_guess = true;
            }
            ((ListVt_guess*)list_guess)->Slot78_guess();
        }
    } else if (message_guess == 0x10 && sender_guess == buyLine_guess) {
        CompareReq_guess* req_guess = (CompareReq_guess*)data_guess;
        E70_guess& a_guess = ((CBarterSearchWnd_guess*)this)->cc190_guess.Get(req_guess->leftIndex_guess);
        E70_guess& b_guess = ((CBarterSearchWnd_guess*)this)->cc190_guess.Get(req_guess->rightIndex_guess);
        switch (req_guess->kind_guess) {
        case 1:
        case 3:
            req_guess->result_guess = Compare_guess(req_guess->left_guess, req_guess->right_guess);
            break;
        case 2: {
            int diff_guess = a_guess.field08_guess - b_guess.field08_guess;
            int r_guess;
            if (diff_guess > 0) {
                r_guess = 1;
            } else {
                r_guess = (diff_guess >= 0) - 1;
                if (r_guess == 0) {
                    diff_guess = a_guess.index0c_guess.count_guess - b_guess.index0c_guess.count_guess;
                    if (diff_guess > 0) {
                        r_guess = 1;
                    } else {
                        r_guess = (diff_guess >= 0) - 1;
                        if (r_guess == 0) r_guess = strcmp(a_guess.name25_guess, b_guess.name25_guess);
                    }
                }
            }
            req_guess->result_guess = r_guess;
        }
            break;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}
