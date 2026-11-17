// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 128: a hint from compare/tumap.py.
// The barter merchant window, CBarterMerchantWnd ("BarterMerchantWnd"): a buyer's buy lines (BuyLineList),
// the items each line accepts (DetailList), and selling into a line with OP_Barter. The first function
// belongs to another window (it sends OP_BankerChange). ElementArray_guess is the client's chunked array of
// 0x70-byte buy lines.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CQuantityWnd.h"

struct View_guess {
    virtual void RefreshCounts_guess();
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
    virtual void Slot63_guess(void* data);       // vtable +0xFC
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess(void* data);
    virtual void Load_guess(void* data);
    virtual void Slot75_guess();
    virtual void Slot76_guess();
};

struct Layout_guess {
    char opaque[0x18];
    // EXTERNAL: TITANIUM 0x00572300 Layout_guess::Get_guess
    void* Get_guess(const char* name);
};

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct BarterStr_guess {
    void* Ptr;
    // EXTERNAL: TITANIUM 0x00571E00 BarterStr_guess::BarterStr_guess
    BarterStr_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00571D00 BarterStr_guess::FreeRep
    void FreeRep(void* rep);
    ~BarterStr_guess() {
        if (Ptr != 0)
            FreeRep(Ptr);
    }
};

struct BarterSidlBase_guess {
    virtual void RefreshCounts_guess();
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
    virtual void Slot48_guess(int a, int b);     // vtable +0xC0
    char pad_004[0x60];                  // 0x004
    unsigned int windowStyle_064;        // 0x064 (CXWnd::WindowStyle)
    char pad_068[0xbc];                  // 0x068
    void* sidlPiece_124;                 // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_128[0x14];                  // 0x128
    // EXTERNAL: TITANIUM 0x005A3850 ??0BarterSidlBase_guess@@QAE@PAUCXWnd@@ABUBarterStr_guess@@HHPAD@Z
    BarterSidlBase_guess(CXWnd* parent, const BarterStr_guess& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1BarterSidlBase_guess@@QAE@XZ
    ~BarterSidlBase_guess();
};

// ArrayClass2-style table (init 0x0047C3AF).
struct PowerTable_guess {
    int field_000;                       // 0x00
    int alloc_004;                       // 0x04
    int mask_008;                        // 0x08
    int shift_00c;                       // 0x0c
    void* blocks_010;                    // 0x10
    int blockCount_014;                  // 0x14
    unsigned char flag_018;              // 0x18
    char pad_019[3];
    int cursor_01c;                      // 0x1c
    // EXTERNAL: TITANIUM 0x0047C3AF PowerTable_guess::Initialize_guess
    void Initialize_guess(int size);
};

struct Element_guess;

struct BarterRow_guess {
    char pad_000[4];
    int value_004;                       // 0x04
    int id_008;                          // 0x08
    char name_00c[0x40];                 // 0x0c
};

struct BarterRows_guess {
    int count;                           // 0x00
    BarterRow_guess* data;               // 0x04
    int capacity_guess;                  // 0x08
    unsigned char flag_guess;            // 0x0c
    // EXTERNAL: TITANIUM 0x00409340 BarterRows_guess::GetEntry_guess
    BarterRow_guess* GetEntry_guess(int index);
};

struct BarterGroup_guess {
    char pad_000[0x0c];
    BarterRows_guess rows;               // 0x0c
    char pad_01c[4];
    int field_020;                       // 0x20
    char pad_024[0x4c];
};

struct BarterTable_guess {
    int count_0000_guess;                       // 0x00
    int alloc_004;                       // 0x04
    int mask_008;                        // 0x08
    int shift_00c;                       // 0x0c
    void* blocks_010;                    // 0x10
    int blockCount_014;                  // 0x14
    unsigned char flag_018;              // 0x18
    char pad_019[3];
    int cursor_01c;                      // 0x1c
    BarterTable_guess(int size) { ((PowerTable_guess*)this)->Initialize_guess(size); }
    ~BarterTable_guess();
    int GetCount_guess() { return count_0000_guess; }
    Element_guess* Get_guess(int index);
    BarterGroup_guess* Group_guess(int index) {
        return ((BarterGroup_guess**)blocks_010)[index >> shift_00c] + (mask_008 & index);
    }
};

// A list child window as this window configures it (fields past CListWnd 0x140).
struct BarterListWnd_guess : CListWnd {
    char pad_140[0x14];                  // 0x140
    int field_154;                       // 0x154
    char pad_158;                        // 0x158
    unsigned char field_159;             // 0x159
    char pad_15a[2];                     // 0x15a
    unsigned char field_15c;             // 0x15c
    char pad_15d[3];                     // 0x15d
    int field_160;                       // 0x160
    char pad_164[8];                     // 0x164
    unsigned int color_16c;              // 0x16c
    // EXTERNAL: TITANIUM 0x0059B2E0 BarterListWnd_guess::SetItemValue_guess
    void SetItemValue_guess(int row, int column, unsigned int value);
    // EXTERNAL: TITANIUM 0x0059B3E0 BarterListWnd_guess::SetItemColor_guess
    void SetItemColor_guess(int row, int column, unsigned int color);
    void SetRowHeight(int height) {
        field_159 = 1;
        field_160 = height;
    }
    // EXTERNAL: TITANIUM 0x005981F0 BarterListWnd_guess::SetColumnWidth_guess
    void SetColumnWidth_guess(int column, int width);
    // EXTERNAL: TITANIUM 0x0059B2E0 BarterListWnd_guess::SetItemText_guess
    void SetItemText_guess(int row, int column, const char* text);
};

struct Handler_guess {
    // EXTERNAL: TITANIUM 0x005F6CC0 Handler_guess::CanReset_guess
    char CanReset_guess(int value);
};
#define g_handler_guess EQ_GLOBAL(Handler_guess*, 0x00905CC0)
#define g_resetArg_guess EQ_GLOBAL(int, 0x00924470)

// EXTERNAL: TITANIUM 0x0064FEF0 ??_7CBarterMerchantWnd_guess@@6B@
struct CBarterMerchantWnd_guess : BarterSidlBase_guess {
    char pad_13c[4];                     // 0x13c
    Layout_guess layout;                 // 0x140
    int field_158;                       // 0x158
    CXWnd* label_15c;                    // 0x15c
    int itemListB;                       // 0x160 (DetailList)
    int itemListA;                       // 0x164 (BuyLineList)
    int unused168;                       // 0x168
    View_guess* view;                    // 0x16c (BuyLineLayout)
    unsigned char flag_170;              // 0x170
    char pad_171[3];
    int field_174;                       // 0x174
    BarterTable_guess table;             // 0x178
    int lastPollTime_0198_guess;                       // 0x198
    int field_19c;                       // 0x19c
    CBarterMerchantWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005A1EF0 CBarterMerchantWnd_guess::LoadItemList_guess
    void LoadItemList_guess(int item, const char* name);
    // EXTERNAL: TITANIUM 0x005A1FE0 CBarterMerchantWnd_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(int item, const char* name);
    void SaveLayout_guess();
    void LoadLayout_guess();
    char AboutToHide_guess();
    void UpdateBuyLine_guess(const Element_guess* source);
    // EXTERNAL: TITANIUM 0x004DDD05 CBarterMerchantWnd_guess::Rebuild_guess
    void Rebuild_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
    void Update_guess(int flags);
    void Poll_guess();
    void ClearLines_guess();
    void Tick_guess();
    char AboutToShow_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 FreeDelete_guess
void __cdecl FreeDelete_guess(void* memory);
// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
void __cdecl FreeArray_guess(void* memory);
typedef void (__cdecl *ElementDtor_guess)(void*);
// EXTERNAL: TITANIUM 0x0060D6E5 VectorDtorIter_guess
void __stdcall VectorDtorIter_guess(void* data, unsigned size, int count, ElementDtor_guess dtor);

struct Element_guess {
    char opaque_000[0x20];               // 0x00
    int field_020;                       // 0x20
    unsigned char field_024;             // 0x24
    char opaque_025[0x4b];               // 0x25
    // EXTERNAL: TITANIUM 0x005E41E0 Element_guess::Element_guess
    Element_guess();
    // EXTERNAL: TITANIUM 0x005E4260 Element_guess::~Element_guess
    ~Element_guess();
    // EXTERNAL: TITANIUM 0x005E4260 Element_guess::Destroy_guess
    void Destroy_guess();
    void* Delete_guess(unsigned char flags);
    // EXTERNAL: TITANIUM 0x00409BFD Element_guess::CopyFrom_guess
    Element_guess* CopyFrom_guess(const Element_guess* source);
};

inline Element_guess* BarterTable_guess::Get_guess(int index) {
    return ((Element_guess**)blocks_010)[index >> shift_00c] + (index & mask_008);
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

// EXTERNAL: TITANIUM 0x005E4260 ElementDtorFn_guess
void __cdecl ElementDtorFn_guess(void* element);

struct ElementArray_guess {
    int head;
    int chunkSize_guess; // 0x4
    unsigned int mask_guess; // 0x8
    unsigned int shift_guess; // 0xC
    Element_guess** items;
    int count;
    unsigned char enabled_guess; // 0x18

    // EXTERNAL: TITANIUM 0x0051DA09 ElementArray_guess::RoundCount_guess
    int RoundCount_guess(int wanted);
    // EXTERNAL: TITANIUM 0x00405492 ElementArray_guess::ThrowSelf_guess
    void ThrowSelf_guess();
    void Reserve_guess(int wanted);
    void Remove_guess(int index);
    void Store_guess(int index, const Element_guess* source);
    void Clear_guess();
    ~ElementArray_guess() ;
};

struct ArrayTable_guess {
    int count_000;
    int alloc_004;
    int mask_008;
    int shift_00c;
    void* blocks_010;
    int blockCount_014;
    int flag_018;
    ArrayTable_guess(int size) { ((PowerTable_guess*)this)->Initialize_guess(size); }
    // EXTERNAL: TITANIUM 0x004B73EE ArrayTable_guess::~ArrayTable_guess
    ~ArrayTable_guess();
};

struct ItemRow_guess {
    char pad_000[4];
    int id_004;
    char pad_008[0x14];
    int count_01c;
    int key_020;
    char pad_024;
    char text_025[0x43];
    int value_068;
    char pad_06c[4];
};

struct PriceFmt_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 PriceFmt_guess::GetIcon_guess
    unsigned int GetIcon_guess(int value);
};
#define pPriceFmt_guess EQ_GLOBAL(PriceFmt_guess*, 0x00991910)

struct TextFmt_guess {
    // EXTERNAL: TITANIUM 0x00408F64 TextFmt_guess::EndBuyerInspect_guess
    void EndBuyerInspect_guess();
    // EXTERNAL: TITANIUM 0x00409226 TextFmt_guess::Format_guess
    CXStr Format_guess(const ItemRow_guess* row);
};
#define pTextFmt_guess EQ_ARRAY(TextFmt_guess, 0x0079C198)

// EXTERNAL: TITANIUM 0x004B85AE FindItemsById_guess
bool __cdecl FindItemsById_guess(void* charData, unsigned int id, int flag, int limit, ArrayTable_guess* out, int extra);
// EXTERNAL: TITANIUM 0x006220E9 Itoa_guess
char* __cdecl Itoa_guess(int value, char* buffer, int radix);

struct Aux_guess {
    // EXTERNAL: TITANIUM 0x004D8D48 Aux_guess::Action_guess
    void Action_guess(int value, int flag);
};

struct Object_guess {
    char opaque[0x258];
    int value;
};

struct Dispatcher_guess {
    virtual void RefreshCounts_guess();
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
    virtual void Slot48_guess(int first, int second);
    char opaque15c[0x15c - 4];
    int pending;
    char opaque160[8];
    int entries[5];
    char opaque17c[0x1c8 - 0x17c];
    int field72;
    int field73;
    int field74;
    int field75;
    // EXTERNAL: TITANIUM 0x004DCF17 Dispatcher_guess::AutoBank_guess
    void AutoBank_guess(int value);
    // EXTERNAL: TITANIUM 0x004DCD85 Dispatcher_guess::OnMoneyClick_guess
    void OnMoneyClick_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x005A2230 Dispatcher_guess::Process_guess
    int Process_guess(int item, int action, int* value);
    int WndNotification_guess(int item, int action, int* value);
};

// EXTERNAL: TITANIUM 0x0059DD30 Ready_guess
char __cdecl Ready_guess();
// EXTERNAL: TITANIUM 0x004912B1 Send_guess
void __cdecl Send_guess(int* connection, int message, int* value, int size, int flag);

#define pinstCAltStorageWnd_guess EQ_GLOBAL(int, 0x00991434)

// Button clicks of a nearby window (probably the bank): close, an action on the object at 0x905D14, reset,
// and Change, which sends OP_BankerChange (4-byte payload) and counts a pending request at 0x9248D0. Five
// more buttons apply their slot.
// FUNCTION: TITANIUM 0x004DD386
// @early-stop: budget, structural ndiff=27
int Dispatcher_guess::WndNotification_guess(int item, int action, int* value) {
    if (Ready_guess() == 0)
        return 1;

    if (action == 1) {
        if (item == field72) {
            Slot48_guess(0, 1);
            return 0;
        }
        if (item == field75) {
            if (pinstCAltStorageWnd_guess != 0 && EQ_GLOBAL(int, 0x00905D14) != 0) {
                Aux_guess* aux = reinterpret_cast<Aux_guess*>(pinstCAltStorageWnd_guess);
                Object_guess* object = reinterpret_cast<Object_guess*>(EQ_GLOBAL(int, 0x00905D14));
                aux->Action_guess(object->value, 1);
            }
            return 0;
        }
        if (item == field74) {
            AutoBank_guess(1);
            return 0;
        }
        if (item == field73) {
            ++EQ_GLOBAL(int, 0x009248D0);
            // The payload is the address of `item`, i.e. the button pointer; may be a decomp error.
            Send_guess(&EQ_GLOBAL(int, 0x00905CA0), OP_BankerChange, &item, 4, 1);
        } else {
            for (int i = 0; i < 5; ++i) {
                if (item == entries[i]) {
                    OnMoneyClick_guess(i, -1);
                    return 0;
                }
            }
        }
    } else if (action == 0x1F) {
        if (pending != -1) {
            OnMoneyClick_guess(pending, *value);
            pending = -1;
            return 0;
        }
    }

    return Process_guess(item, action, value);
}

// Loads the two lists' column layout and the buy-line layout under the names at 0x64ED38 / 0x64FE9C (probably
// INI keys).
// FUNCTION: TITANIUM 0x004DD497
void CBarterMerchantWnd_guess::LoadLayout_guess() {
    if (itemListA != 0)
        LoadItemList_guess(itemListA, EQ_ARRAY(char, 0x0064ED38));
    if (itemListB != 0)
        LoadItemList_guess(itemListB, EQ_ARRAY(char, 0x0064ED38));
    if (view != 0)
        view->Slot73_guess(layout.Get_guess(EQ_ARRAY(char, 0x0064FE9C)));
}

// Saves the same layouts back (the pair of Configure_guess).
// FUNCTION: TITANIUM 0x004DD4F1
void CBarterMerchantWnd_guess::SaveLayout_guess() {
    if (itemListA != 0)
        StoreIniListWnd_guess(itemListA, EQ_ARRAY(char, 0x0064ED38));
    if (itemListB != 0)
        StoreIniListWnd_guess(itemListB, EQ_ARRAY(char, 0x0064ED38));
    if (view != 0)
        view->Load_guess(layout.Get_guess(EQ_ARRAY(char, 0x0064FE9C)));
}

// Compiler vector deleting destructor for 0x70-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x004DD54B
void* Element_guess::Delete_guess(unsigned char flags) {
    if (flags & 2) {
        char* base = reinterpret_cast<char*>(this) - 4;
        VectorDtorIter_guess(this, 0x70, *reinterpret_cast<int*>(base), ElementDtorFn_guess);
        if (flags & 1)
            FreeArray_guess(base);
        return base;
    }
    Destroy_guess();
    if (flags & 1)
        FreeDelete_guess(this);
    return this;
}

// On close: saves the layout and ends the buyer inspection (EndBuyerInspect_guess).
// FUNCTION: TITANIUM 0x004DD596
char CBarterMerchantWnd_guess::AboutToHide_guess() {
    SaveLayout_guess();
    pTextFmt_guess->EndBuyerInspect_guess();
    return 1;
}

// Frees the chunked array: deletes every block (vector delete, 0x004DD54B with flags 3), then the block
// table, and zeroes the counts.
// FUNCTION: TITANIUM 0x004DD5A8
void ElementArray_guess::Clear_guess() {
    int i = 0;
    if (count > 0) {
        do {
            if (items[i] != 0)
                items[i]->Delete_guess(3);
            ++i;
        } while (i < count);
    }
    FreeArray_guess(items);
    items = 0;
    count = 0;
    head = 0;
}

// Grows the chunk table to hold `wanted` lines; a failed allocation turns the array off (enabled_guess 0) for
// good.
// FUNCTION: TITANIUM 0x004DD5E1
void ElementArray_guess::Reserve_guess(int wanted) {
    if (enabled_guess != 0 && wanted > 0) {
        wanted = RoundCount_guess(wanted);
        if (wanted > count) {
            Element_guess** newItems = new Element_guess*[wanted];
            if (newItems == 0) {
                enabled_guess = 0;
            } else {
                if (count > 0) {
                    int index = 0;
                    do {
                        newItems[index] = items[index];
                        ++index;
                    } while (index < count);
                }
                int index = count;
                if (index < wanted) {
                    do {
                        Element_guess* chunk = new Element_guess[chunkSize_guess];
                        newItems[index] = chunk;
                        if (chunk == 0) {
                            enabled_guess = 0;
                            break;
                        }
                        ++index;
                    } while (index < wanted);
                }
                if (enabled_guess != 0) {
                    FreeArray_guess(items);
                    items = newItems;
                    count = wanted;
                }
            }
        }
        if (enabled_guess == 0) {
            Clear_guess();
            ThrowSelf_guess();
        }
    }
}

// Destructor of the chunked buy-line array: deletes every block and the block table (0x004DD5A8).
// Reached only from exception-unwind code.
// FUNCTION: TITANIUM 0x004DD6F0
ElementArray_guess::~ElementArray_guess()  {
    Clear_guess();
}

// Removes element `index` of the chunked array: shifts the later elements down one (0x70-byte copies)
// and drops the count; out-of-range indexes are ignored.
// FUNCTION: TITANIUM 0x004DD6F5
void ElementArray_guess::Remove_guess(int index) {
    if (index >= 0 && index < head && items != 0) {
        if (index < head - 1) {
            int i = index;
            do {
                int next = i + 1;
                Element_guess* src = items[next >> shift_guess] + (next & mask_guess);
                Element_guess* dst = items[i >> shift_guess] + (i & mask_guess);
                dst->CopyFrom_guess(src);
                i++;
            } while (i < head - 1);
        }
        head--;
    }
}

// Stores a copy of `source` at `index`, growing the chunked array (0x004DD5E1) and its count when the
// index is past the end; nothing happens if the growth failed.
// FUNCTION: TITANIUM 0x004DD754
void ElementArray_guess::Store_guess(int index, const Element_guess* source) {
    if (index >= 0) {
        if (index >= head) {
            Reserve_guess(index + 1);
            if (enabled_guess != 0)
                head = index + 1;
        }
        if (enabled_guess != 0) {
            Element_guess* e = items[index >> shift_guess] + (index & mask_guess);
            e->CopyFrom_guess(source);
        }
    }
}

// Binds MerchantNameLabel, BuyLineList, DetailList, SellButton and BuyLineLayout; both lists get yellow text,
// grey lines, highlight 0xFF8AA3FF and 24-pixel rows.
// FUNCTION: TITANIUM 0x004DD7A0
CBarterMerchantWnd_guess::CBarterMerchantWnd_guess(CXWnd* parent)
    : BarterSidlBase_guess(parent, "BarterMerchantWnd", -1, 1, 0), table(0x20), field_19c(-1) {
    itemListB = 0;
    itemListA = 0;
    unused168 = 0;
    view = 0;
    lastPollTime_0198_guess = 0;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= 0x10000;
        field_158 = 0x3c;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        label_15c = ((CSidlScreenWnd*)this)->GetChildItem("MerchantNameLabel");
        itemListB = (int)((CSidlScreenWnd*)this)->GetChildItem("DetailList");
        itemListA = (int)((CSidlScreenWnd*)this)->GetChildItem("BuyLineList");
        unused168 = (int)((CSidlScreenWnd*)this)->GetChildItem("SellButton");
        view = (View_guess*)((CSidlScreenWnd*)this)->GetChildItem("BuyLineLayout");
        if (itemListA != 0) {
            ((BarterListWnd_guess*)itemListA)->SetColors(-1, 0xffffff00, 0xff808080);
            ((BarterListWnd_guess*)itemListA)->SetColumnJustification(0, 0);
            ((BarterListWnd_guess*)itemListA)->SetColumnJustification(1, 0);
            ((BarterListWnd_guess*)itemListA)->SetColumnJustification(2, 1);
            ((BarterListWnd_guess*)itemListA)->SetColumnJustification(3, 1);
            ((BarterListWnd_guess*)itemListA)->color_16c = 0xff8aa3ff;
            ((BarterListWnd_guess*)itemListA)->field_15c = 1;
            ((BarterListWnd_guess*)itemListA)->SetRowHeight(0x18);
            ((BarterListWnd_guess*)itemListA)->SetColumnWidth_guess(0, 0x18);
        }
        if (itemListB != 0) {
            ((BarterListWnd_guess*)itemListB)->SetColors(-1, 0xffffff00, 0xff808080);
            ((BarterListWnd_guess*)itemListB)->SetColumnJustification(0, 0);
            ((BarterListWnd_guess*)itemListB)->SetColumnJustification(1, 0);
            ((BarterListWnd_guess*)itemListB)->SetColumnJustification(2, 1);
            ((BarterListWnd_guess*)itemListB)->color_16c = 0xff8aa3ff;
            ((BarterListWnd_guess*)itemListB)->field_15c = 1;
            ((BarterListWnd_guess*)itemListB)->SetRowHeight(0x18);
            ((BarterListWnd_guess*)itemListB)->SetColumnWidth_guess(0, 0x18);
        }
        field_174 = -1;
        LoadLayout_guess();
    }
}

struct ResizeBarBase_guess {
    char opaque[0x174];
    // EXTERNAL: TITANIUM 0x005A3100 ResizeBarBase_guess::~ResizeBarBase_guess
    virtual ~ResizeBarBase_guess();
};

struct ElementArrayMember_guess {
    int head;
    char opaque[0x0c];
    Element_guess** items;
    int count;
    ~ElementArrayMember_guess() {
        reinterpret_cast<ElementArray_guess*>(this)->Clear_guess();
    }
};

// EXTERNAL: TITANIUM 0x0064FEF0 ??_7COleResizeBar_guess@@6B@
struct COleResizeBar_guess : ResizeBarBase_guess {
    ElementArrayMember_guess elements;
    virtual ~COleResizeBar_guess();
    void* ScalarDeletingDestructor_guess(unsigned int flags);
};

// Destructor of the barter merchant window (vtable 0x64FEF0, ctor 0x004DD7A0): frees its buy-line array
// (+0x178, 0x004DD5A8), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004DDA93
COleResizeBar_guess::~COleResizeBar_guess() {
}

// Enables Sell only when no request is pending and the player has the selected line's item
// (FindItemsById_guess).
// FUNCTION: TITANIUM 0x004DDAD1
// @early-stop: budget, structural ndiff=6
void CBarterMerchantWnd_guess::Poll_guess() {
    bool shown = false;
    if (EQ_GLOBAL(int, 0x009248D0) == 0 && itemListA != 0) {
        int index = ((CListWnd*)itemListA)->GetCurSel();
        if (index >= 0 && index < table.count_0000_guess) {
            ArrayTable_guess buf(0x20);
            shown = FindItemsById_guess(pCharData,
                (((ItemRow_guess**)table.blocks_010)[index >> table.shift_00c] + (table.mask_008 & index))->id_004,
                1, 0x100, &buf, 0);
        }
    }
    if (unused168 != 0)
        ((CXWnd*)unused168)->Enabled = shown;
}

struct TextSource_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 TextSource_guess::GetIcon_guess
    char* GetIcon_guess(int id);
};

// Fills DetailList with line `index`'s accepted items: icon, name, count.
// FUNCTION: TITANIUM 0x004DDB80
// @early-stop: budget, structural ndiff=56
void CBarterMerchantWnd_guess::Update_guess(int index) {
    if (itemListB != 0) {
        ((View_guess*)itemListB)->Slot76_guess();
        if (index >= 0 && index < table.count_0000_guess) {
            int i = 0;
            BarterGroup_guess* group = table.Group_guess(index);
            field_174 = group->field_020;
            BarterRows_guess* rows = &group->rows;
            for (; i < rows->count; ++i) {
                BarterRow_guess* row = rows->GetEntry_guess(i);
                int line = ((BarterListWnd_guess*)itemListB)->AddString(CXStr(EQ_ARRAY(char, 0x0063F53F)), 0xffffffff, 0, 0);
                ((BarterListWnd_guess*)itemListB)->SetItemText_guess(line, 0, EQ_GLOBAL(TextSource_guess*, 0x00991910)->GetIcon_guess(row->id_008));
                ((BarterListWnd_guess*)itemListB)->SetItemText(line, 1, CXStr(row->name_00c));
                ((BarterListWnd_guess*)itemListB)->SetItemText(line, 2, CXStr(Itoa_guess(row->value_004, EQ_ARRAY(char, 0x0099DB00), 10)));
            }
        }
    }
}

// Scalar deleting destructor of the barter merchant window (vtable 0x64FEF0 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004DDFDC
void* COleResizeBar_guess::ScalarDeletingDestructor_guess(unsigned int flags) {
    this->COleResizeBar_guess::~COleResizeBar_guess();
    if (flags & 1)
        FreeDelete_guess(this);
    return this;
}

// EXTERNAL: TITANIUM 0x00401B28 FindEntry_guess
void* __cdecl FindEntry_guess(int id);
// EXTERNAL: TITANIUM 0x0046D655 GetTick_guess
unsigned int __cdecl GetTick_guess();

struct BarterEntry_guess {
    char pad_000[0x120];
    char text_120[4];                    // 0x120
};

struct Meter_guess {
    // EXTERNAL: TITANIUM 0x00439D16 Meter_guess::PlayerDistance_guess
    float PlayerDistance_guess(int a, int b, float c);
};
#define g_meter_guess EQ_GLOBAL(Meter_guess*, 0x00905D24)
#define g_busy_guess EQ_GLOBAL(int, 0x00905D10)
#define g_busyArg_guess EQ_GLOBAL(int, 0x00905CE4)

// Clears the lines and both lists and shows the buyer's name (spawn field_19c, trimmed) in the title label.
// FUNCTION: TITANIUM 0x004DDFF8
void CBarterMerchantWnd_guess::ClearLines_guess() {
    ((ElementArray_guess*)&table)->Clear_guess();
    Rebuild_guess();
    Update_guess(-1);
    if (unused168 != 0)
        ((CXWnd*)unused168)->Enabled = 0;
    if (label_15c != 0) {
        BarterEntry_guess* entry = (BarterEntry_guess*)FindEntry_guess(field_19c);
        if (entry != 0) {
            CXStr text(entry->text_120);
            ((View_guess*)label_15c)->Slot63_guess(&text);
        }
    }
}

// Every 300 ms rebuilds the list if lines changed and rechecks Sell. Closes when the buyer is gone or more
// than 20 units away.
// FUNCTION: TITANIUM 0x004DE08E
void CBarterMerchantWnd_guess::Tick_guess() {
    if (((CXWnd*)this)->Show != 0) {
        unsigned int now = GetTick_guess();
        if (now > lastPollTime_0198_guess + 300U) {
            lastPollTime_0198_guess = now;
            if (flag_170 != 0)
                Rebuild_guess();
            Poll_guess();
        }
        if (g_busy_guess == 0 || g_meter_guess->PlayerDistance_guess(g_busy_guess, g_busyArg_guess, 0.0f) > 20.0f)
            ((BarterSidlBase_guess*)this)->Slot48_guess(0, 1);
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Rebuilds BuyLineList: price, item name, count and the line text per buy line; lines whose item the player
// lacks are drawn pink (0xFFC08080).
// FUNCTION: TITANIUM 0x004DDD05
// @early-stop: budget, diff ndiff=31
void CBarterMerchantWnd_guess::Rebuild_guess() {
    int found = -1;
    flag_170 = 0;
    if (itemListA != 0) {
        ((View_guess*)itemListA)->Slot76_guess();
        for (int i = 0; i < table.count_0000_guess; ++i) {
            int color = -1;
            ArrayTable_guess tbl(0x20);
            if (!FindItemsById_guess(pCharData, (((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))->id_004, 1, 0x100, &tbl, 0))
                color = 0xffc08080;
            int row;
            {
                CXStr text(EQ_ARRAY(char, 0x0063F53F));
                row = ((BarterListWnd_guess*)itemListA)->AddString(text, color, i, 0);
            }
            ((BarterListWnd_guess*)itemListA)->SetItemValue_guess(row, 0, pPriceFmt_guess->GetIcon_guess((((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))->value_068));
            {
                CXStr name((((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))->text_025);
                ((BarterListWnd_guess*)itemListA)->SetItemText(row, 1, name);
            }
            ((BarterListWnd_guess*)itemListA)->SetItemColor_guess(row, 1, color);
            {
                CXStr count(Itoa_guess((((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))->count_01c, EQ_ARRAY(char, 0x0099DB00), 10));
                ((BarterListWnd_guess*)itemListA)->SetItemText(row, 2, count);
            }
            ((BarterListWnd_guess*)itemListA)->SetItemColor_guess(row, 2, color);
            ((BarterListWnd_guess*)itemListA)->SetItemText(row, 3, pTextFmt_guess->Format_guess((((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))));
            ((BarterListWnd_guess*)itemListA)->SetItemColor_guess(row, 3, color);
            if ((((ItemRow_guess**)table.blocks_010)[i >> table.shift_00c] + (table.mask_008 & i))->key_020 == field_174)
                found = row;
        }
        ((BarterListWnd_guess*)itemListA)->SetCurSel(found);
        Update_guess(found);
    }
}

// EXTERNAL: TITANIUM 0x00492EC2 TextStore_guess::Store_guess
struct TextStore_guess {
    char* Store_guess(const char* text);
};
#define g_textStore_guess EQ_GLOBAL(TextStore_guess*, 0x00988DF0)

struct BusyTarget_guess {
    char pad_000[0x120];
    char text_120[1];                    // 0x120
};
#define g_busyTarget_guess EQ_GLOBAL(BusyTarget_guess*, 0x00905D10)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, unsigned int id, const char* p0, const char* p1,
                              const char* p2, const char* p3, const char* p4, const char* p5,
                              const char* p6, const char* p7, const char* p8);

// Sell-select note (type 0xe): 0x18 bytes.
struct BarterNotify_guess {
    int type;          // 0x00 = 0xe
    int field19c;      // 0x04
    int key;           // 0x08
    void* data;        // 0x0c
    int value;         // 0x10
    int flag;          // 0x14
};

// Packed row message (type 7): 12-byte header, then the row body.
struct BarterPack_guess {
    int type;          // 0x00 = 7
    int value;         // 0x04
    int id;            // 0x08
    char body[0x3a4];  // 0x0c
};

struct RowPack_guess {
    // EXTERNAL: TITANIUM 0x005E4020 RowPack_guess::Pack_guess
    int Pack_guess(char* buf, int size);
};

// EXTERNAL: TITANIUM 0x004DC02D RectOps_guess::CenterPoint
// EXTERNAL: TITANIUM 0x004D9160 RectOps_guess::Assign_guess
struct RectOps_guess {
    int* CenterPoint(int* out);
    void Assign_guess(int* unused, const CXRect* src);
};

#define g_connection_guess EQ_GLOBAL(int, 0x00905CA0)

// Virtual slots of a window (slot 57 at +0xE4 returns a pointer to a 4-int rect).
struct SenderSlots_guess {
    virtual void RefreshCounts_guess();
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
    virtual int* Slot57_guess(char* buf);
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Sell click: with a request pending shows string 12063 ("Whoa! Hold your horses there!...", from the buyer);
// else opens a quantity prompt for at most 20 (or the line's count). A DetailList pick (message 3) sends
// OP_Barter type 14 (flag 2 with shift held); the prompt's answer (message 0x1F) sends OP_Barter type 7 with
// the packed line.
// FUNCTION: TITANIUM 0x004DE10B
// @early-stop: unknown, structural ndiff=85
int CBarterMerchantWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if ((int)sender == itemListA) {
            Update_guess(((CListWnd*)itemListA)->GetItemData(((CListWnd*)itemListA)->GetCurSel()));
        } else if ((int)sender == unused168) {
            if (EQ_GLOBAL(int, 0x009248D0) != 0) {
                char buf[512];
                FormatText_guess(buf, 0x2f1f, g_textStore_guess->Store_guess(g_busyTarget_guess->text_120),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buf, 0x111, 1);
            } else {
                if (itemListA != 0) {
                    int sel = ((CListWnd*)itemListA)->GetCurSel();
                    if (sel != -1) {
                        unsigned int id = ((CListWnd*)itemListA)->GetItemData(sel);
                        int count = ((ItemRow_guess*)table.Get_guess(id))->count_01c;
                        if (count > 0x14)
                            count = 0x14;
                        CXRect rect;
                        rect.left = rect.top = rect.right = rect.bottom = 0;
                        if (sender != 0) {
                            char buf[8];
                            int* src = ((SenderSlots_guess*)sender)->Slot57_guess(buf);
                            CXRect tmp;
                            ((RectOps_guess*)&rect)->Assign_guess((int*)&tmp, (const CXRect*)src);
                        }
                        int center[2];
                        int* c = ((RectOps_guess*)&rect)->CenterPoint(center);
                        pinstCQuantityWnd_guess->Function_0054d976_guess(this, count, 1, c[0], c[1], 1);
                    }
                }
            }
        }
    } else if (message == 3) {
        if ((int)sender == itemListB && itemListA != 0) {
            int sel = ((CListWnd*)itemListA)->GetCurSel();
            unsigned int id = ((CListWnd*)itemListA)->GetItemData(sel);
            BarterNotify_guess note;
            note.data = data;
            note.type = 0xe;
            note.key = table.Get_guess(id)->field_020;
            note.field19c = field_19c;
            BarterGroup_guess* group = table.Group_guess(id);
            BarterRow_guess* row = group->rows.GetEntry_guess((int)data);
            note.value = *(int*)row;
            if (pinstCXWndManager_guess->GetKeyboardFlags() & 1)
                note.flag = 2;
            Send_guess(&g_connection_guess, OP_Barter, (int*)&note, 0x18, 1);
        }
    } else if (message == 0x1f) {
        int value = *(int*)data;
        if (itemListA != 0) {
            int sel = ((CListWnd*)itemListA)->GetCurSel();
            if (sel != -1) {
                unsigned int id = ((CListWnd*)itemListA)->GetItemData(sel);
                BarterPack_guess pack;
                pack.id = field_19c;
                pack.value = value;
                pack.type = 7;
                int n = ((RowPack_guess*)table.Get_guess(id))->Pack_guess(pack.body, 0x3a4);
                Send_guess(&g_connection_guess, OP_Barter, (int*)&pack, n + 0xc, 1);
            }
        }
        ((CXWnd*)unused168)->Enabled = 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// Buy line from the server: replaces the line with the same id, removes it when its count (+0x24) is 0, else
// appends it. Marks the list for rebuild.
// FUNCTION: TITANIUM 0x004DE41A
// @early-stop: budget, diff ndiff=38
void CBarterMerchantWnd_guess::UpdateBuyLine_guess(const Element_guess* source) {
    for (int i = 0; i < table.GetCount_guess(); ++i) {
        if (table.Get_guess(i)->field_020 == source->field_020) {
            if (source->field_024 == 0)
                ((ElementArray_guess*)&table)->Remove_guess(i);
            else
                table.Get_guess(i)->CopyFrom_guess(source);
            flag_170 = 1;
            return;
        }
    }
    ((ElementArray_guess*)&table)->Store_guess(table.GetCount_guess(), source);
    flag_170 = 1;
}

// On open: only when the buyer can be inspected; then clears and refills.
// FUNCTION: TITANIUM 0x004DE4A4
char CBarterMerchantWnd_guess::AboutToShow_guess() {
    char result = g_handler_guess->CanReset_guess(g_resetArg_guess);
    if (result != 0)
        ClearLines_guess();
    return result;
}

