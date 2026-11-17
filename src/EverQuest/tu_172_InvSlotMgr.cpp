// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// The inventory slot manager: one slot object per UI item slot (up to 1024), drag icons (A_DragItem), item
// moves between every slot range (MoveItem, OP_MoveItem), right-click use (eat, drink, cast, OP_Consume)
// and the bank/shared-bank rules. Client slot ids: 0-21 worn, 22-29 packs, 30 cursor, 31-330 bag slots (10
// per pack), 2000-2023 bank, 2031-2190 bank bags, 2500-2501 shared bank and 2531-2550 its bags, 3000-3007
// trade and 3031-3340 its bags, 4000-4030 world container, 5000+ and 8000+ other windows' slots (as the
// slot binder decodes them; MoveItem's own bounds differ in places).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/bounded_array.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CMerchantWnd.h"
#include "titanium/wnd/CPointMerchantWnd.h"
#include "titanium/wnd/CGiveWnd.h"
#include "titanium/wnd/CGuildTributeMasterWnd.h"
#include "titanium/wnd/CItemDisplayManager.h"
#include "titanium/wnd/CTradeskillWnd.h"
#include "titanium/wnd/CTributeMasterWnd.h"

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct Referenced_guess {
    char pad_000[0x78];
    struct TextSlot_guess {
        // EXTERNAL: TITANIUM 0x00571F70 Referenced_guess::TextSlot_guess::Set_guess
        void Set_guess(struct CXStr* value);
    } text_078;
    char pad_07c[0xa4];
    int value_120;
    char pad_124[8];
    int value_12c;
    int value_130;
    char pad_134[0x1c];
    int color_150[2];
};

struct DragItemStore_guess {
    char pad_000[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 DragItemStore_guess::DragItemStore_guess
    DragItemStore_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B DragItemStore_guess::Attach_guess
    void Attach_guess(int value);
    // EXTERNAL: TITANIUM 0x005B1AB0 DragItemStore_guess::SetState_guess
    void SetState_guess(int value);
};

struct DragDataSource_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 DragDataSource_guess::Read_guess
    int Read_guess(CXStr* value);
};

struct DragController_guess {
    char pad_000[4];
    Referenced_guess* referenced_004;
    DragItemStore_guess* itemStore_008;
    int index_00c;
    void* input_010;
    void Update_guess(struct InputReference_guess* value);
    void SetDragItem_guess(Referenced_guess* referenced);
};

#define g_dragDataSource_guess EQ_GLOBAL(DragDataSource_guess*, 0x0099D3F4)

struct ItemData_guess {
    char pad_000[0x48];
    int value_048;
    char pad_04c[0x14];
    unsigned char flag_060;
    char pad_061[0x17];
    unsigned char flag_078;
    char pad_079[0x43];
    // EXTERNAL: TITANIUM 0x005E0F60 ItemData_guess::GetValue_guess
    unsigned int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ItemData_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC760 ItemData_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ItemData_guess::GetText_guess
    const char* GetText_guess();
};

struct InputReference_guess {
    ItemData_guess* item_000;
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    const char* getString(const char* id, int flags);
};

#define g_stringTable_guess EQ_GLOBAL(StringTableView_guess*, 0x00905cb0)

struct Element_guess;

struct CharSub_guess {
    char pad_000[0x78];
    Element_guess* field_078;
};

struct CounterValue_guess {
    char pad_000[0x10];
    CharSub_guess sub_010;
    char pad_08c[0x1078 - 0x8c];
    int value_1078;
    char pad_107c[0x119c - 0x107c];
    unsigned char class_119c_guess;
    char pad_119d[0x1218 - 0x119d];
    int thirst_1218_guess;
    int hunger_121c_guess;
    void AddFirst_guess(int amount) {
        thirst_1218_guess += amount;
    }
    void AddSecond_guess(int amount) {
        hunger_121c_guess += amount;
    }
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    CounterValue_guess& GetCharInfo2();
};

struct CounterOwner_guess {
    int pad_000;
    EQ_CharacterProfileView_guess provider;
    void IncrementFirst_guess(int amount);
    void IncrementSecond_guess(int amount);
};

struct Element_guess;

struct SelectionTarget_guess {
    char pad_000[0x134];
    unsigned char active_134;
};

struct Selection_guess {
    int pad_000;
    SelectionTarget_guess* target_004;
};

struct SelectionManager_guess {
    void SetSelection_guess(Selection_guess* selection);
};

struct LookupData_guess {
    virtual void V00_guess() = 0; virtual void V01_guess() = 0; virtual void V02_guess() = 0;
    virtual void V03_guess() = 0; virtual void V04_guess() = 0; virtual void V05_guess() = 0;
    virtual void V06_guess() = 0; virtual void V07_guess() = 0; virtual void V08_guess() = 0;
    virtual void V09_guess() = 0; virtual void V10_guess() = 0; virtual void V11_guess() = 0;
    virtual void V12_guess() = 0; virtual void V13_guess() = 0; virtual void V14_guess() = 0;
    virtual void V15_guess() = 0; virtual void V16_guess() = 0; virtual void V17_guess() = 0;
    virtual void V18_guess() = 0; virtual void V19_guess() = 0; virtual void V20_guess() = 0;
    virtual void V21_guess() = 0; virtual void V22_guess() = 0; virtual void V23_guess() = 0;
    virtual void V24_guess() = 0; virtual void V25_guess() = 0; virtual void V26_guess() = 0;
    virtual void V27_guess() = 0; virtual void V28_guess() = 0; virtual void V29_guess() = 0;
    virtual void V30_guess() = 0; virtual void V31_guess() = 0; virtual void V32_guess() = 0;
    virtual void V33_guess() = 0; virtual void V34_guess() = 0; virtual void V35_guess() = 0;
    virtual void V36_guess() = 0; virtual void V37_guess() = 0; virtual void V38_guess() = 0;
    virtual void V39_guess() = 0; virtual void V40_guess() = 0; virtual void V41_guess() = 0;
    virtual void V42_guess() = 0; virtual void V43_guess() = 0; virtual void V44_guess() = 0;
    virtual void V45_guess() = 0; virtual void V46_guess() = 0; virtual void V47_guess() = 0;
    virtual void V48_guess() = 0; virtual void V49_guess() = 0; virtual void V50_guess() = 0;
    virtual void V51_guess() = 0; virtual void V52_guess() = 0; virtual void V53_guess() = 0;
    virtual void V54_guess() = 0; virtual void V55_guess() = 0; virtual void V56_guess() = 0;
    virtual CXRect GetScreenRect_guess() = 0;
    char pad_004[0x118];
    int value_11c;
    int key_120;
    char pad_124[0xc];
    int remainingStackQuantity_0130_guess;
};

struct LookupEntry_guess {
    int pad_000;
    LookupData_guess* data_004;
};

struct LookupTable_guess {
    int pad_000;
    LookupEntry_guess* entries_004[1024];
    int count_1004;
    LookupEntry_guess* FindInvSlot(int key);
};

// EXTERNAL: TITANIUM 0x00656770 ??_7CInvSlotView_guess@@6B@
struct CInvSlotView_guess {
    virtual ~CInvSlotView_guess();
    // EXTERNAL: TITANIUM 0x00518E10 CInvSlotView_guess::CInvSlotView_guess
    CInvSlotView_guess();
    // EXTERNAL: TITANIUM 0x00518E5C CInvSlotView_guess::Bind_guess
    void Bind_guess(Element_guess** value);
    // EXTERNAL: TITANIUM 0x0051A5A5 CInvSlotView_guess::SetDragItem_guess
    void SetDragItem_guess(Referenced_guess* referenced);
    void SetFlag(unsigned char value);
    unsigned char GetFlag();
    void* DestroyAndMaybeFree_guess(unsigned char flags);
    Referenced_guess* referenced;
    void* secondary;
    int state;
    char pad_010[4];
    unsigned char flag;
    void RunIfFlag_guess(int);
};

// EXTERNAL: TITANIUM 0x00656788 ??_7CInvSlotMgrView_guess@@6B@
struct CInvSlotMgrView_guess {
    virtual ~CInvSlotMgrView_guess();
    CInvSlotMgrView_guess();
    struct Entry_guess {
        virtual void* Release_guess(unsigned char flags);
    } *entries[1024];
    int count;
    CInvSlotView_guess* Add_guess(Referenced_guess* referenced);
    int time_1008;
    unsigned int Refresh_guess(char force);
    void RunDueEntries_guess();
    void* DestroyAndMaybeFree_guess(unsigned char flags);
};

struct ClientObject_guess {
    char pad_000[0x5c];
    char flag_05c;
    // EXTERNAL: TITANIUM 0x004DC831 ClientObject_guess::GetNumBankSlots
    unsigned int GetNumBankSlots();
};

struct PendingAction_guess;

struct Element_guess {
    virtual void Slot00_guess() = 0;
    virtual PendingAction_guess* Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual char IsOkToActivate_guess(int value) = 0;
    virtual char Slot05_guess(Element_guess* page, int value) = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual PendingAction_guess* Slot0A_guess(int value) = 0;
    // EXTERNAL: TITANIUM 0x005ECCC0 Element_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005DFC40 Element_guess::FirstCheck_guess
    char FirstCheck_guess();
    // EXTERNAL: TITANIUM 0x005DFCC0 Element_guess::SecondCheck_guess
    char SecondCheck_guess();
    // EXTERNAL: TITANIUM 0x005EC760 Element_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 Element_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Element_guess::Text_guess
    char* Text_guess();
    // EXTERNAL: TITANIUM 0x005E0D70 Element_guess::Metric_guess
    int Metric_guess();
    // EXTERNAL: TITANIUM 0x005E0BF0 Element_guess::Flag_guess
    int Flag_guess();
    // EXTERNAL: TITANIUM 0x005E0BC0 Element_guess::Limit_guess
    int Limit_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Element_guess::Child_guess
    int Child_guess(int index);
    // EXTERNAL: TITANIUM 0x005EC650 Element_guess::GetSlot_guess
    Element_guess** GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x005E0F30 Element_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC820 Element_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x005ECD50 Element_guess::GetLimit_guess
    int GetLimit_guess();
    // EXTERNAL: TITANIUM 0x005E0A30 Element_guess::HasFlagA_guess
    char HasFlagA_guess(int value);
    // EXTERNAL: TITANIUM 0x005E0620 Element_guess::HasFlagB_guess
    int HasFlagB_guess(int value);
    char pad_004[0x44];
    int chargesOrStackCount_0048_guess;
    char pad_04c[0x10];
    int value_05c;
};

// 16 bytes passed by copy.
struct Span_guess {
    int a_000;
    int b_004;
    int c_008;
    int d_00c;
    // EXTERNAL: TITANIUM 0x004B7215 Span_guess::SetFromSlotId_guess
    void SetFromSlotId_guess(int value);
};

struct ElementCollection_guess {
    // EXTERNAL: TITANIUM 0x0041DE16 ElementCollection_guess::GetItemBySlot_guess
    Element_guess* GetItemBySlot_guess(int index);
    // EXTERNAL: TITANIUM 0x0040DB0B ElementCollection_guess::IsBardSong_guess
    int IsBardSong_guess(int value);
    // EXTERNAL: TITANIUM 0x0041B0DE ElementCollection_guess::HasSkill_guess
    int HasSkill_guess(int kind);
    // EXTERNAL: TITANIUM 0x00411F3D ElementCollection_guess::Post_guess
    void Post_guess(int kind, int zero, struct ElementRef_guess* ref, Span_guess span, int tail);
    // EXTERNAL: TITANIUM 0x004192AA ElementCollection_guess::CanUseItem_guess
    int CanUseItem_guess(Element_guess* item, int flag);
};

struct ElementRoot_guess {
    char pad_000[0xc280];
    ElementCollection_guess elements;
    char pad_c281[0xb];
    unsigned char flag_c28c;
    char pad_c28d[0xbb];
    unsigned char flag_c348;
    // EXTERNAL: TITANIUM 0x004BCE5F ElementRoot_guess::IsBlocked_guess
    int IsBlocked_guess(Element_guess* element);
    // EXTERNAL: TITANIUM 0x004BC5EB ElementRoot_guess::FitsEquipSlot_guess
    char FitsEquipSlot_guess(int key, Element_guess* item);
    // EXTERNAL: TITANIUM 0x005EE500 ElementRoot_guess::FlagTest_guess
    bool FlagTest_guess(int key);
};

struct CleanupFlagCall_guess {
    // EXTERNAL: TITANIUM 0x00518E4E CleanupFlagCall_guess::SetFlag_guess
    void SetFlag_guess(unsigned char value);
};

struct ElementManager_guess {
    // EXTERNAL: TITANIUM 0x004FA7CD ElementManager_guess::ApplyFirst_guess
    void ApplyFirst_guess(Element_guess* element, int index, bool flags);
    // EXTERNAL: TITANIUM 0x004FAA17 ElementManager_guess::CloseContainer_guess
    void CloseContainer_guess(Element_guess* element, int flags);
};

#define g_selection_guess EQ_GLOBAL(Selection_guess*, 0x00991b54)
#define g_elementRoot_guess EQ_GLOBAL(ElementRoot_guess*, 0x00905d00)
#define g_elementManager_guess EQ_GLOBAL(ElementManager_guess*, 0x00850cbc)
#define g_clientObject_guess EQ_GLOBAL(ClientObject_guess*, 0x00850c38)
#define g_busy_guess EQ_GLOBAL(int, 0x009248D0)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_keyFlag_guess EQ_GLOBAL(unsigned char, 0x009254F5)

// Reuses the first free slot object or makes a new one (at most 1024) for the UI slot `referenced`;
// worn slots 0-29 also get their +0x14 flag from the profile bit (0x005EE500).
// FUNCTION: TITANIUM 0x0051A730
CInvSlotView_guess* CInvSlotMgrView_guess::Add_guess(Referenced_guess* referenced) {
    for (int index = 0; index < count; ++index) {
        if (((CInvSlotView_guess*)entries[index])->referenced == 0) {
            ((CInvSlotView_guess*)entries[index])->state = index;
            ((CInvSlotView_guess*)entries[index])->SetDragItem_guess(referenced);
            ((CInvSlotView_guess*)entries[index])->Bind_guess(0);
            if (g_elementRoot_guess != 0 && referenced != 0 && referenced->value_120 >= 0 &&
                referenced->value_120 < 0x1e) {
                ((CleanupFlagCall_guess*)entries[index])->SetFlag_guess(
                    g_elementRoot_guess->FlagTest_guess(referenced->value_120));
            }
            return (CInvSlotView_guess*)entries[index];
        }
    }
    if (count < 0x400) {
        CInvSlotView_guess* cleanup = new CInvSlotView_guess;
        cleanup->state = count;
        cleanup->SetDragItem_guess(referenced);
        cleanup->Bind_guess(0);
        if (g_elementRoot_guess != 0 && referenced != 0 && referenced->value_120 >= 0 &&
            referenced->value_120 < 0x1e) {
            ((CleanupFlagCall_guess*)cleanup)->SetFlag_guess(
                g_elementRoot_guess->FlagTest_guess(referenced->value_120));
        }
        entries[count] = (CInvSlotMgrView_guess::Entry_guess*)cleanup;
        ++count;
        return cleanup;
    }
    return 0;
}

// Slot object for slot id `key`, or 0.
// FUNCTION: TITANIUM 0x0051A84D
LookupEntry_guess* LookupTable_guess::FindInvSlot(int key) {
    int index = 0;
    if (count_1004 > 0) {
        LookupEntry_guess** entry = entries_004;
        do {
            if (*entry != 0) {
                LookupData_guess* data = (*entry)->data_004;
                int value = -1;
                if (data != 0) {
                    value = data->key_120;
                }
                if (value == key) {
                    return entries_004[index];
                }
            }
            ++index;
            ++entry;
        } while (index < count_1004);
    }
    return 0;
}

// Destructor of an inventory slot object (vtable 0x656770): slot id back to -1, and the bound slot
// window's back pointer (+0x12C) cleared before both links are dropped.
// FUNCTION: TITANIUM 0x00518E29
CInvSlotView_guess::~CInvSlotView_guess() {
    state = -1;
    if (referenced != 0) {
        referenced->value_12c = 0;
        referenced = 0;
    }
    if (secondary != 0) {
        secondary = 0;
    }
}

// Sets an inventory slot object's +0x14 flag (the slot window draws only while it is set). After the
// profile loads and when the slot
// manager makes slot objects for worn slots 0-29, it is set from the character's per-slot flags
// (0x005EE500).
// FUNCTION: TITANIUM 0x00518E4E
void CInvSlotView_guess::SetFlag(unsigned char value) {
    flag = value;
}

// Returns an inventory slot object's +0x14 flag. While it is clear the slot window draws nothing and
// ignores queries (0x0051BC61, 0x0051B7B5).
// FUNCTION: TITANIUM 0x00518E58
unsigned char CInvSlotView_guess::GetFlag() {
    return flag;
}

// Sets the slot's icon from the item (icon id - 500) and, for worn slots 0-21, a frame colour: green when the
// item fits, red when it does not, grey when empty.
// FUNCTION: TITANIUM 0x00518E5C
// @early-stop: budget, structural ndiff=35
void DragController_guess::Update_guess(InputReference_guess* value) {
    int state = -1;
    input_010 = value;
    if (referenced_004 != 0 && referenced_004->value_12c != 0) {
        ItemData_guess* item = value != 0 ? value->item_000 : 0;
        if (item != 0) {
            int itemValue = item->GetValue_guess();
            DragItemStore_guess* store =
                (DragItemStore_guess*)referenced_004->value_12c;
            itemValue -= 500;
            state = itemValue;
            store->SetState_guess(itemValue);
            if (index_00c <= 0x15) {
                referenced_004->color_150[1] = (int)0xffc0c0c0;
                referenced_004->color_150[0] = -1;
                if (item->flag_060 != 0) {
                    if (item->flag_078 != 0) {
                        referenced_004->color_150[1] = (int)0xff009600;
                        referenced_004->color_150[0] = (int)0xff00ff00;
                    } else {
                        referenced_004->color_150[1] = (int)0xff960000;
                        referenced_004->color_150[0] = (int)0xffff0000;
                    }
                }
            }
            referenced_004->value_130 = 0;
            if (item->GetItemClass_guess() == 0) {
                int icon = 0;
                if (item->IsStackable_guess() != 0) {
                    icon = item->value_048;
                }
                referenced_004->value_130 = icon;
            }
            CXStr text(item->GetText_guess());
            referenced_004->text_078.Set_guess(&text);
        } else {
            if (referenced_004->value_120 < 0x16) {
                CXStr text(g_stringTable_guess->getString(
                    EQ_ARRAY(const char*, 0x006674c8)[referenced_004->value_120], 0));
                referenced_004->text_078.Set_guess(&text);
            } else {
                CXStr text(EQ_ARRAY(const char, 0x0063f53f));
                referenced_004->text_078.Set_guess(&text);
            }
            referenced_004->color_150[1] = (int)0xffc0c0c0;
            referenced_004->color_150[0] = -1;
            referenced_004->value_130 = 0;
            ((DragItemStore_guess*)referenced_004->value_12c)->SetState_guess(-1);
        }
    }
    if (itemStore_008 != 0) {
        itemStore_008->SetState_guess(state);
    }
}

// On a slot window's release (parent code 0x1A): when the slot's +0x14 flag is set (the profile bit
// for its equipment slot, 0x005EE500), closes the newest open item display window (0x00991B88
// manager, 0x0051E0EA).
// FUNCTION: TITANIUM 0x005190D3
void CInvSlotView_guess::RunIfFlag_guess(int) {
    if (flag != 0) {
        pinstCItemDisplayManager_guess->CloseNewestItemDisplay_guess();
    }
}

// True for a bank slot (2000-2271, bank bags mapped to their bank slot) beyond the number of bank slots the
// account has (default 8).
// FUNCTION: TITANIUM 0x005190E7
char __stdcall IsBankSlotLocked_guess(int value) {
    if (value >= 2000 && value < 0x88f) {
        int level = value - 2000;
        int limit = 8;
        if (g_clientObject_guess != 0) {
            limit = g_clientObject_guess->GetNumBankSlots();
        }
        if (level >= 0x1f) {
            level = (level - 0x1f) / 10;
        }
        if (level >= limit) {
            return 1;
        }
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Adds `amount` to the character's drink level (+0x1218 of 0x005EC220's record). Right-click on a drink
// (item type 0xF) adds half its value x 100.
// FUNCTION: TITANIUM 0x00519134
void CounterOwner_guess::IncrementFirst_guess(int amount) {
    provider.GetCharInfo2().AddFirst_guess(amount);
}

// Adds `amount` to the character's food level (+0x121C of 0x005EC220's record). Right-click on food
// (item type 0xE) adds half its value x 100.
// FUNCTION: TITANIUM 0x00519149
void CounterOwner_guess::IncrementSecond_guess(int amount) {
    provider.GetCharInfo2().AddSecond_guess(amount);
}

// Scalar deleting destructor of an inventory slot object (vtable 0x656770 slot 0): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0051915E
void* CInvSlotView_guess::DestroyAndMaybeFree_guess(unsigned char flags) {
    this->CInvSlotView_guess::~CInvSlotView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Moves the selection highlight to `selection`.
// FUNCTION: TITANIUM 0x0051A891
void SelectionManager_guess::SetSelection_guess(Selection_guess* selection) {
    if (g_selection_guess != 0 && g_selection_guess->target_004 != 0) {
        g_selection_guess->target_004->active_134 = 0;
    }
    g_selection_guess = selection;
    if (selection != 0 && selection->target_004 != 0) {
        selection->target_004->active_134 = 1;
    }
}

// Releases every entry (virtual slot 0 with flag 1, the deleting destructor), nulls the slots and sets
// the count to 0.
// FUNCTION: TITANIUM 0x0051A65D
CInvSlotMgrView_guess::~CInvSlotMgrView_guess() {
    int index = 0;
    if (count > 0) {
        CInvSlotMgrView_guess::Entry_guess** entry = entries;
        do {
            if (*entry != 0) {
                (*entry)->Release_guess(1);
                *entry = 0;
            }
            ++index;
            ++entry;
        } while (index < count);
    }
    count = 0;
}

// Scalar deleting destructor of the inventory slot manager (vtable 0x656788 slot 0): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0051A8C6
void* CInvSlotMgrView_guess::DestroyAndMaybeFree_guess(unsigned char flags) {
    this->CInvSlotMgrView_guess::~CInvSlotMgrView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Opens every closed bag in pack slots 22-29.
// FUNCTION: TITANIUM 0x0051A69B
void __cdecl OpenAllBags_guess() {
    for (int index = 0x16; index <= 0x1d; ++index) {
        Element_guess* element = g_elementRoot_guess->elements.GetItemBySlot_guess(index);
        if (element != 0 && element->FirstCheck_guess() && !element->SecondCheck_guess()) {
            g_elementManager_guess->ApplyFirst_guess(element, index, 0);
        }
    }
}

// Closes every open bag in pack slots 22-29.
// FUNCTION: TITANIUM 0x0051A6E6
void __cdecl CloseAllBags_guess() {
    for (int index = 0x16; index <= 0x1d; ++index) {
        Element_guess* element = g_elementRoot_guess->elements.GetItemBySlot_guess(index);
        if (element != 0 && element->FirstCheck_guess() && element->SecondCheck_guess()) {
            g_elementManager_guess->CloseContainer_guess(element, 1);
        }
    }
}

struct PendingAction_guess {
    // EXTERNAL: TITANIUM 0x004B1DB0 PendingAction_guess::SendReadBook_guess
    void SendReadBook_guess();
    // EXTERNAL: TITANIUM 0x005ECD80 PendingAction_guess::SetStackCount_guess
    void SetStackCount_guess(int amount);
    char pad_000[0x48];
    int field_048;
};

struct PlayerInfo_guess {
    char pad_000[0xf98];
    int id_f98;
};

struct PlayerRef_guess {
    char pad_000[0x1a8];
    PlayerInfo_guess* info_1a8;
    char pad_1ac[0x252 - 0x1ac];
    unsigned char class_252;
    // EXTERNAL: TITANIUM 0x0048127E PlayerRef_guess::UpdateEquipmentDisplay_guess
    void UpdateEquipmentDisplay_guess(int key);
};

struct LookupDb_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 LookupDb_guess::GetSpell_guess
    int GetSpell_guess(int value, int kind);
};

struct Dispatcher_guess {
    // EXTERNAL: TITANIUM 0x0052B9D5 Dispatcher_guess::Post_guess
    void Post_guess(int value, int flag);
};

struct UiHandle_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 UiHandle_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x004E6109 UiHandle_guess::Show_guess
    void Show_guess(int value);
    // EXTERNAL: TITANIUM 0x0056875D UiHandle_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004E5A35 UiHandle_guess::UseA_guess
    void UseA_guess(int key, int value);
    // EXTERNAL: TITANIUM 0x00537FCE UiHandle_guess::SelectBuySellSlot
    void SelectBuySellSlot(int key, Element_guess* element);
    // EXTERNAL: TITANIUM 0x0056DDAA UiHandle_guess::SelectDonationItem_guess
    void SelectDonationItem_guess(int key, int value);
    // EXTERNAL: TITANIUM 0x0051256A UiHandle_guess::UseC_guess
    void UseC_guess(int key, int value);
    // EXTERNAL: TITANIUM 0x005456BC UiHandle_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x00546FA5 UiHandle_guess::UseD_guess
    void UseD_guess(int key);
};

struct ElementRef_guess {
    Element_guess* element_000;
};

struct ActionQueue_guess {
    int pad_000;
    LookupData_guess* data_004;
    int value_008;
    char pad_00c[4];
    ElementRef_guess* ref_010;
    unsigned char enabled_014;
    // EXTERNAL: TITANIUM 0x005190E7 ActionQueue_guess::IsBankSlotLocked_guess
    char IsBankSlotLocked_guess(int level);
    void UseItem_guess(Element_guess* element, int index);
    void Process_guess(int unused);
    void ProcessFast_guess(int unused);
    void ProcessEvent_guess(int unused);
    void PickUpQuantity_guess(int amount);
    void HandleLButtonUp_guess(int unused, bool hotkey);
};

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value);

#define g_player_guess EQ_GLOBAL(PlayerRef_guess*, 0x00905CE4)
#define g_lookupDb_guess EQ_GLOBAL(LookupDb_guess*, 0x00985CC8)
#define g_dispatcher_guess EQ_GLOBAL(Dispatcher_guess*, 0x00850C40)
#define g_uiMain_guess EQ_GLOBAL(UiHandle_guess*, 0x00850C58)

struct ActionClient_guess {
    // EXTERNAL: TITANIUM 0x004FD36C ActionClient_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int value);
    // EXTERNAL: TITANIUM 0x004FD91E ActionClient_guess::Post_guess
    void Post_guess(int a, int b, int c, int d, int e);
};

#define g_actionClient_guess EQ_GLOBAL(ActionClient_guess*, 0x00850C24)

// Passes the slot's item to the action manager, with ~keyboard flags & 1 (probably "no shift") as its flag;
// skipped for slots 8000-8031 and locked bank slots.
// FUNCTION: TITANIUM 0x0051917A
void ActionQueue_guess::ProcessFast_guess(int) {
    if (enabled_014 != 0) {
        Element_guess* element;
        if (ref_010 != 0) {
            element = ref_010->element_000;
        } else {
            element = 0;
        }
        if (element != 0 && data_004 != 0) {
            int key = data_004->key_120;
            if (key != -1 && IsBankSlotLocked_guess(key) != 1 && (key < 8000 || key > 0x1f5f)) {
                unsigned int flags = pinstCXWndManager_guess->GetKeyboardFlags();
                pinstCItemDisplayManager_guess->SetRaw_guess(element, (~flags) & 1);
            }
        }
    }
}

// Uses the slot's item (probably on right click) unless busy, a modifier is held, or the slot is 8000-8031.
// FUNCTION: TITANIUM 0x0051A3A0
void ActionQueue_guess::Process_guess(int) {
    if (enabled_014 != 0) {
        Element_guess* element;
        if (ref_010 != 0) {
            element = ref_010->element_000;
        } else {
            element = 0;
        }
        if (g_busy_guess == 0 && data_004 != 0) {
            int key = data_004->key_120;
            if (key != -1 && (key < 8000 || key > 0x1f5f) && IsBankSlotLocked_guess(key) != 1 &&
                (pinstCXWndManager_guess->GetKeyboardFlags() & 1) == 0 &&
                (pinstCXWndManager_guess->GetKeyboardFlags() & 0xc) == 0) {
                int target = g_player_guess->info_1a8->id_f98;
                if (target != -1 && IsValidSpellIndex_guess(target) != 0) {
                    int info = g_lookupDb_guess->GetSpell_guess(g_player_guess->info_1a8->id_f98, g_player_guess->class_252);
                    if (g_elementRoot_guess->elements.IsBardSong_guess(info) == 0) {
                        return;
                    }
                }
                if (element != 0) {
                    g_elementRoot_guess->flag_c28c = 1;
                    g_elementRoot_guess->flag_c348 = 0;
                    if (key >= 5000 && key < 0x13a7) {
                        g_dispatcher_guess->Post_guess(key - 5000, 1);
                        return;
                    }
                    if (element->GetItemClass_guess() == 1) {
                        if (element->SecondCheck_guess() != 0) {
                            g_elementManager_guess->CloseContainer_guess(element, 1);
                        } else {
                            unsigned int flags = pinstCXWndManager_guess->GetKeyboardFlags();
                            g_elementManager_guess->ApplyFirst_guess(element, key, g_keyFlag_guess != (unsigned char)((flags >> 1) & 1));
                        }
                    } else if (key < 1000) {
                        if (element->GetItemClass_guess() == 2) {
                            element->Slot0A_guess(-1)->SendReadBook_guess();
                        } else if (element->GetItemClass_guess() == 0 && key <= 0x1f) {
                            UseItem_guess(element, key);
                        }
                    }
                }
                if (g_uiMain_guess != 0 && g_uiMain_guess->IsActive_guess()) {
                    g_uiMain_guess->Show_guess(1);
                }
                if (pinstCTradeskillWnd_guess != 0 && pinstCTradeskillWnd_guess->IsVisible_guess()) {
                    pinstCTradeskillWnd_guess->Flush_guess();
                }
            }
        }
    }
}

// Click effect on a worn slot (0-30): casts the item's spell (CastSpell, type 8) when activation is allowed.
// FUNCTION: TITANIUM 0x00519061
void ActionQueue_guess::ProcessEvent_guess(int) {
    if (enabled_014 != 0) {
        Element_guess* element = (ref_010 != 0) ? ref_010->element_000 : 0;
        LookupData_guess* data = data_004;
        if (data != 0) {
            int value = data->value_11c;
            int key = data->key_120;
            if (key != -1 && key < 0x1f && g_actionClient_guess->IsOkToActivate_guess(8)) {
                int limit = -1;
                if (element != 0 && element->IsStackable_guess()) {
                    limit = element->chargesOrStackCount_0048_guess;
                }
                g_actionClient_guess->Post_guess(value, 8, key, 0, limit);
            }
        }
    }
}

// Attaches the shared drag icon (A_DragItem) to the slot.
// FUNCTION: TITANIUM 0x0051A5A5
void DragController_guess::SetDragItem_guess(Referenced_guess* referenced) {
    referenced_004 = referenced;
    if (referenced != 0) {
        if (itemStore_008 == 0) {
            itemStore_008 = new DragItemStore_guess;
        }
        int result;
        {
            CXStr value("A_DragItem");
            result = g_dragDataSource_guess->Read_guess(&value);
        }
        if (result != 0) {
            itemStore_008->Attach_guess(result);
            itemStore_008->SetState_guess(-1);
        }
        referenced_004->value_12c = (int)itemStore_008;
    }
}

typedef CounterValue_guess CharInfo_guess;

// pCharData: vfptr and int at +0, vbptr at +8, the profile in the virtual base.
struct CharDataPrefix_guess {
    virtual void Slot00_guess() = 0;
    int field04_guess;
};

struct Node_guess {
    virtual void Slot00_guess(int flags);
};

struct CharDataVirtual_guess : CounterOwner_guess {
    CharInfo_guess* Lookup_guess() {
        return &provider.GetCharInfo2();
    }
    // EXTERNAL: TITANIUM 0x0040CC50 CharDataVirtual_guess::Find_guess
    Node_guess* Find_guess(int key);
    // EXTERNAL: TITANIUM 0x00434777 CharDataVirtual_guess::GetSlot_guess
    Element_guess** GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x0041AA84 CharDataVirtual_guess::Apply_guess
    void Apply_guess(int key, int flags);
};

struct CharDataRoot_guess : CharDataPrefix_guess, virtual CharDataVirtual_guess {
    // EXTERNAL: TITANIUM 0x005ED550 CharDataRoot_guess::GetStat_guess
    int GetStat_guess();
    // EXTERNAL: TITANIUM 0x005ED570 CharDataRoot_guess::SetStat_guess
    void SetStat_guess(int value);
};

#define g_charData_guess EQ_GLOBAL(CharDataRoot_guess*, 0x00905D00)

// Starts with one slot object bound to the cursor item.
// FUNCTION: TITANIUM 0x0051A8E2
CInvSlotMgrView_guess::CInvSlotMgrView_guess() : count(0) {
    for (int i = 0; i < 1024; ++i) {
        entries[i] = 0;
    }
    CInvSlotView_guess* cleanup = new CInvSlotView_guess;
    cleanup->state = count;
    cleanup->SetDragItem_guess(0);
    if (g_charData_guess != 0) {
        CharSub_guess* sub = &g_charData_guess->Lookup_guess()->sub_010;
        if (sub->field_078 != 0) {
            cleanup->Bind_guess(&g_charData_guess->Lookup_guess()->sub_010.field_078);
        }
    }
    entries[count] = (CInvSlotMgrView_guess::Entry_guess*)cleanup;
    ++count;
}

struct EverQuestCalls_guess {
    // EXTERNAL: TITANIUM 0x0049908D EverQuestCalls_guess::Reset_guess
    void Reset_guess(int value);
};
#define g_everQuestCalls_guess EQ_GLOBAL(EverQuestCalls_guess*, 0x00988DF0)

struct UiSound_guess {
    // EXTERNAL: TITANIUM 0x0044A537 UiSound_guess::WavePlay_guess
    void WavePlay_guess(int id, int flag);
};
#define g_uiSound_guess EQ_GLOBAL(UiSound_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x00576E40 IsSomething_guess
char __cdecl IsSomething_guess(char value);
// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* out, int id, const char* a1, const char* a2, const char* a3,
                          const char* a4, const char* a5, const char* a6, const char* a7,
                          const char* a8, const char* a9);

// Right-click use by item type: 0x2A poison (ApplyPoison_guess); 0xE food and 0xF drink with the full
// messages (12074, 12077), the bite/drink text and OP_Consume; alcohol with 12080 when too drunk and
// OP_DeleteItem {slot, -1, -1}: one drink of the stack is used up (the last one leaves the inventory);
// spells refuse while singing (12082).
// FUNCTION: TITANIUM 0x00519DA6
// @early-stop: budget, structural ndiff=128
void ActionQueue_guess::UseItem_guess(Element_guess* element, int index) {
    char name[64];
    char msg[256];
    char ok;
    int msg4[4];
    Span_guess span;
    int m[3];
    if (element->GetItemType_guess() == 0x2a) {
        g_everQuestCalls_guess->Reset_guess(index);
        return;
    }
    // Food (type 0xE) and drink (0xF): refused when already full (6000 at +0x121C / +0x1218); otherwise the
    // bite or sip text and +item value * 50, capped at 6000. Both end in OP_Consume below.
    if (element->GetItemType_guess() == 0xe) {
        if (g_charData_guess->Lookup_guess()->hunger_121c_guess >= 6000) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f2a, 0), 0x111, true);
            return;
        }
        strcpy(name, element->Text_guess());
        if (IsSomething_guess(name[0])) {
            Format_guess(msg, 0x2135, element->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            Format_guess(msg, 0x2f2b, element->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(msg, 0x111, true);
        g_charData_guess->IncrementSecond_guess(element->Metric_guess() * 100 / 2);
        if (g_charData_guess->Lookup_guess()->hunger_121c_guess > 6000) {
            g_charData_guess->Lookup_guess()->hunger_121c_guess = 6000;
        }
        pEverQuest->dsp_chat(pStringTable->getString(0x2f2c, 0), 0x111, true);
        msg4[3] = 1;
    } else if (element->GetItemType_guess() == 0xf) {
        if (g_charData_guess->Lookup_guess()->thirst_1218_guess >= 6000) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f2d, 0), 0x111, true);
            return;
        }
        strcpy(name, element->Text_guess());
        if (IsSomething_guess(name[0])) {
            Format_guess(msg, 0x2136, element->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            Format_guess(msg, 0x2f2e, element->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(msg, 0x111, true);
        g_charData_guess->IncrementFirst_guess(element->Metric_guess() * 100 / 2);
        if (g_charData_guess->Lookup_guess()->thirst_1218_guess > 6000) {
            g_charData_guess->Lookup_guess()->thirst_1218_guess = 6000;
        }
        g_uiSound_guess->WavePlay_guess(0x95, 0);
        pEverQuest->dsp_chat(pStringTable->getString(0x2f2f, 0), 0x111, true);
        msg4[3] = 2;
    // Alcohol (0x26): drunkenness up to 200, +40, or less with the alcohol-tolerance flag set (10-40 by the
    // value at +0x1078); the drink is used up with OP_DeleteItem (0x4D81 {slot, -1, -1}).
    } else if (element->GetItemType_guess() == 0x26) {
        if (g_charData_guess->GetStat_guess() >= 200) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f30, 0), 0x111, true);
            return;
        }
        Format_guess(msg, 0x2f31, element->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(msg, 0x111, true);
        int add = 40;
        if (g_elementRoot_guess->elements.HasSkill_guess(0x42)) {
            add = (200 - g_charData_guess->Lookup_guess()->value_1078) * 30 / 200 + 10;
        }
        g_charData_guess->SetStat_guess(g_charData_guess->GetStat_guess() + add);
        if (g_charData_guess->GetStat_guess() > 200) {
            g_charData_guess->SetStat_guess(200);
        }
        m[0] = index;
        m[1] = -1;
        m[2] = -1;
        EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_DeleteItem, m, 0xc, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x2f2f, 0), 0x111, true);
        if (element->chargesOrStackCount_0048_guess != 1) {
            element->chargesOrStackCount_0048_guess--;
            return;
        }
        Node_guess* node = g_charData_guess->Find_guess(index);
        if (node != 0) {
            node->Slot00_guess(1);
        }
        g_charData_guess->Apply_guess(index, 0);
        return;
    } else {
        // Anything else with a spell clicks it: not without charges when it needs them, not for a bard
        // mid-song (0x2F32), and only when nothing is being cast.
        if (!IsValidSpellIndex_guess(element->Child_guess(0))) {
            return;
        }
        ok = 1;
        if (element->Flag_guess() != 0 && element->Limit_guess() <= 0) {
            ok = 0;
        }
        if (g_charData_guess->Lookup_guess()->class_119c_guess == 8 && g_player_guess->info_1a8->id_f98 != -1) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f32, 0), 0x108, true);
            return;
        }
        if (g_player_guess->info_1a8->id_f98 == -1 && ok) {
            span.a_000 = 0;
            span.b_004 = -1;
            span.c_008 = -1;
            span.d_00c = 0;
            span.SetFromSlotId_guess(index);
            g_elementRoot_guess->elements.Post_guess(10, 0, ref_010, span, 0);
            if (element->GetItemType_guess() == 0x15) {
                g_uiSound_guess->WavePlay_guess(0x95, 0);
            }
        }
        return;
    }
    msg4[0] = index;
    msg4[1] = 999;
    msg4[2] = -1;
    // OP_Consume (0x77D6) {slot, 999, -1, 1 food / 2 drink}; then one is taken off the stack.
    EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_Consume, msg4, 0x10, 1);
    if (element->chargesOrStackCount_0048_guess != 1) {
        element->chargesOrStackCount_0048_guess--;
        return;
    }
    Node_guess* node = g_charData_guess->Find_guess(index);
    if (node != 0) {
        node->Slot00_guess(1);
    }
    g_charData_guess->Apply_guess(index, 0);
}

struct CharBanks_guess {
    char pad_000[0xcf0];
    BoundedArray_guess<Element_guess*, 16> bank_cf0;
    BoundedArray_guess<Element_guess*, 2> bank_d30;
};
#define g_charBanks_guess EQ_GLOBAL(CharBanks_guess*, 0x00905D00)

#define pinstCInventoryWnd_guess EQ_GLOBAL(int, 0x00850C34)
#define g_eqBase_guess EQ_GLOBAL(int, 0x00988DF0)

struct NotifierTable_guess {
    // EXTERNAL: TITANIUM 0x005481CF NotifierTable_guess::Find_guess
    int Find_guess(int owner, int kind);
    // EXTERNAL: TITANIUM 0x00548225 NotifierTable_guess::ExpireAt_guess
    void ExpireAt_guess(int handle);
};
#define g_notifierTable_guess EQ_GLOBAL(NotifierTable_guess*, 0x00991E44)

struct PcFields_guess {
    char pad_000[0x244];
    char flag_244;
};
#define g_pcFields_guess EQ_GLOBAL(PcFields_guess*, 0x00905CE0)

struct BankMgr_guess {
    char pad_000[0x6c];
    Element_guess* elem_06c;
};
#define g_bankMgr_guess EQ_GLOBAL(BankMgr_guess*, 0x00850CBC)

struct InvFlags_guess {
    char pad_000[0x10];
    bool flag_010;
};
#define g_invFlags_guess EQ_GLOBAL(InvFlags_guess*, 0x00905D24)

struct TradeBoard_guess {
    char pad_000[0x1f4];
    Element_guess* slots_1f4[8];
    // EXTERNAL: TITANIUM 0x00569F63 TradeBoard_guess::TradeItemChanged_guess
    void TradeItemChanged_guess(int from, int to);
};
#define g_tradeBoard_guess EQ_GLOBAL(TradeBoard_guess*, 0x00850C50)

// EXTERNAL: TITANIUM 0x00464D65 SwapCombine_guess
int __cdecl SwapCombine_guess(Element_guess** from, Element_guess** to, int fromSlot, int toSlot);

struct ItemMover_guess {
    int MoveItem(int from, int to, int arg, int tryMerge);
};

// Moves an item between two slot ids, handling every range above, trades and merchants; refuses moves into
// 5000-5030 and any 8000-8031 slot, and stacks to NPCs (537). Returns 1 when the move was made.
// FUNCTION: TITANIUM 0x0051A9A8
// @early-stop: budget, structural ndiff=667
int ItemMover_guess::MoveItem(int from, int to, int arg, int tryMerge) {
    bool trade = false;
    // Never into 5000-5030, the loot window (a loot slot as source is posted to LootWnd 0x00850C40
    // below) or from/to 8000-8030.
    if (to >= 5000 && to < 0x13a7) {
        return 0;
    }
    if ((from >= 8000 && from < 0x1f5f) || (to >= 8000 && to < 0x1f5f)) {
        return 0;
    }
    Element_guess** slotA = 0;
    Element_guess** slotB = 0;
    Element_guess* pageA = 0;
    Element_guess* pageB = 0;
    int limit = 8;
    if (g_clientObject_guess != 0) {
        limit = g_clientObject_guess->GetNumBankSlots();
    }
    g_notifierTable_guess->ExpireAt_guess(g_notifierTable_guess->Find_guess(pinstCInventoryWnd_guess ? pinstCInventoryWnd_guess + 0x15c : 0, -1));
    g_notifierTable_guess->ExpireAt_guess(g_notifierTable_guess->Find_guess(g_eqBase_guess ? g_eqBase_guess + 8 : 0, 0x6e));

    // The source slot (and its bag): 0-30 character, 31-341 pack bags, 2000-2015 bank (count from the client
    // object, 8 by default), 2031-2271 bank bags, 2500-2501 shared bank and 2531-2551 its bags, 4000+ the
    // open world container. Trade slots are never a source; a loot slot is looted through the dispatcher.
    if (from >= 0 && from < 0x1f) {
        slotA = g_charData_guess->GetSlot_guess(from);
    } else if (from >= 0x1f && from <= 0x155) {
        int bag = (from - 0x1f) / 10;
        int pos = (from - 0x1f) % 10;
        if (g_charData_guess->Find_guess(bag) == 0) {
            return 0;
        }
        if (((Element_guess*)g_charData_guess->Find_guess(bag))->GetItemClass_guess() != 1) {
            return 0;
        }
        pageA = (Element_guess*)g_charData_guess->Find_guess(bag);
        slotA = pageA->GetSlot_guess(pos);
    } else if (from >= 2000 && from < 0x7ef) {
        int index = from - 2000;
        if (index >= limit) {
            return 0;
        }
        slotA = &g_charBanks_guess->bank_cf0[index];
    } else if (from >= 0x7ef && from <= 0x88f) {
        int index = (from - 0x7ef) / 10;
        int pos = (from - 0x7ef) % 10;
        if (index >= limit) {
            return 0;
        }
        if (g_charBanks_guess->bank_cf0[index] == 0) {
            return 0;
        }
        if (g_charBanks_guess->bank_cf0[index]->GetItemClass_guess() != 1) {
            return 0;
        }
        pageA = g_charBanks_guess->bank_cf0[index];
        slotA = pageA->GetSlot_guess(pos);
    } else if (from >= 0x9c4 && from < 0x9c6) {
        slotA = &g_charBanks_guess->bank_d30[from - 0x9c4];
    } else if (from >= 0x9e3 && from <= 0x9f7) {
        int index = (from - 0x9e3) / 10;
        int pos = (from - 0x9e3) % 10;
        if (g_charBanks_guess->bank_d30[index] == 0) {
            return 0;
        }
        if (g_charBanks_guess->bank_d30[index]->GetItemClass_guess() != 1) {
            return 0;
        }
        pageA = g_charBanks_guess->bank_d30[index];
        slotA = pageA->GetSlot_guess(pos);
    } else if (from >= 4000 && from <= 0x10f5) {
        pageA = g_bankMgr_guess->elem_06c;
        slotA = pageA->GetSlot_guess((from - 4000) % 10);
    } else if (from >= 5000 && from < 0x13a7) {
        g_dispatcher_guess->Post_guess(from - 5000, 0);
        return 1;
    } else if (from >= 3000 && from < 0xbd7) {
        return 0;
    } else if (from >= 0xbd7 && from <= 0xd0d) {
        return 0;
    }

    // The target, the same ranges plus trade slots 3000-3007 and their bags 3031-3340; a stack can't be
    // handed to an NPC (0x219).
    if (to < 0x1f) {
        slotB = g_charData_guess->GetSlot_guess(to);
    } else if (to <= 0x155) {
        int bag = (to - 0x1f) / 10;
        int pos = (to - 0x1f) % 10;
        if (g_charData_guess->Find_guess(bag) == 0) {
            return 0;
        }
        if (((Element_guess*)g_charData_guess->Find_guess(bag))->GetItemClass_guess() != 1) {
            return 0;
        }
        pageB = (Element_guess*)g_charData_guess->Find_guess(bag);
        slotB = pageB->GetSlot_guess(pos);
    } else if (to >= 2000 && to < 0x7ef) {
        int index = to - 2000;
        int count = 8;
        if (g_clientObject_guess != 0) {
            count = g_clientObject_guess->GetNumBankSlots();
        }
        if (index >= count) {
            return 0;
        }
        slotB = &g_charBanks_guess->bank_cf0[index];
    } else if (to >= 0x7ef && to <= 0x88f) {
        int index = (to - 0x7ef) / 10;
        int pos = (to - 0x7ef) % 10;
        if (index >= limit) {
            return 0;
        }
        if (g_charBanks_guess->bank_cf0[index] == 0) {
            return 0;
        }
        if (g_charBanks_guess->bank_cf0[index]->GetItemClass_guess() != 1) {
            return 0;
        }
        pageB = g_charBanks_guess->bank_cf0[index];
        slotB = pageB->GetSlot_guess(pos);
    } else if (to >= 0x9c4 && to < 0x9e3) {
        int index = to - 0x9c4;
        if (index >= 2) {
            return 0;
        }
        slotB = &g_charBanks_guess->bank_d30[index];
    } else if (to >= 0x9e3 && to <= 0x9f7) {
        int index = (to - 0x9e3) / 10;
        int pos = (to - 0x9e3) % 10;
        if (index >= 2) {
            return 0;
        }
        if (g_charBanks_guess->bank_d30[index] == 0) {
            return 0;
        }
        if (g_charBanks_guess->bank_d30[index]->GetItemClass_guess() != 1) {
            return 0;
        }
        pageB = g_charBanks_guess->bank_d30[index];
        slotB = pageB->GetSlot_guess(pos);
    } else if (to >= 4000 && to <= 0x10f5) {
        pageB = g_bankMgr_guess->elem_06c;
        slotB = pageB->GetSlot_guess((to - 4000) % 10);
    } else if (to >= 3000 && to <= 0xd0d) {
        if (g_pcFields_guess != 0 && g_pcFields_guess->flag_244 == 1 && slotA != 0 && *slotA != 0 &&
            (*slotA)->chargesOrStackCount_0048_guess > 1) {
            pEverQuest->dsp_chat(pStringTable->getString(0x219, 0), 0xd, 1);
            return 0;
        }
        if (to < 0xbc0) {
            slotB = &g_tradeBoard_guess->slots_1f4[to - 3000];
            trade = true;
        } else if (to >= 0xbd7) {
            int index = (to - 0xbd7) / 10;
            int pos = (to - 0xbd7) % 10;
            if (g_tradeBoard_guess->slots_1f4[index] == 0 ||
                g_tradeBoard_guess->slots_1f4[index]->GetItemClass_guess() != 1) {
                return 0;
            }
            pageB = g_tradeBoard_guess->slots_1f4[index];
            slotB = pageB->GetSlot_guess(pos);
            trade = true;
        }
    }

    if (slotA == 0 || slotB == 0) {
        return 0;
    }
    if (*slotA == 0 && *slotB == 0) {
        return 0;
    }
    // Bag to bag in one step is refused; an item going into a bag must fit it (Slot05_guess).
    if (pageA != 0) {
        if (pageB != 0) {
            return 0;
        }
        if (*slotB != 0 && !(*slotB)->Slot05_guess(pageA, arg)) {
            return 0;
        }
    } else if (pageB != 0 && *slotA != 0 && !(*slotA)->Slot05_guess(pageB, arg)) {
        return 0;
    }

    // Stacking is tried first (SwapCombine_guess, 0x00464D65). Two items with the same id never swap.
    if (tryMerge != 0 && SwapCombine_guess(slotA, slotB, from, to) != 0) {
        if (trade) {
            g_tradeBoard_guess->TradeItemChanged_guess(from, to);
        }
        return 1;
    }
    if (*slotA != 0 && *slotB != 0 && (*slotA)->IsStackable_guess() &&
        (*slotA)->GetItemId_guess() == (*slotB)->GetItemId_guess()) {
        return 0;
    }

    // Swap locally, then OP_MoveItem {from, to, 0}. A worn item that moved gets +0x5C set (attuned:
    // the flag checked before the attune prompt, string 5912, on equipping).
    Element_guess* held = *slotA;
    *slotA = *slotB;
    *slotB = held;

    int msg[3];
    msg[0] = from;
    msg[1] = to;
    msg[2] = 0;
    EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_MoveItem, msg, 0xc, 1);
    if (trade) {
        g_tradeBoard_guess->TradeItemChanged_guess(from, to);
    }
    if (to >= 0 && to < 0x15 && g_charData_guess->Find_guess(to) != 0 &&
        ((Element_guess*)g_charData_guess->Find_guess(to))->Count_guess() != 0) {
        ((Element_guess*)g_charData_guess->Find_guess(to))->value_05c = 1;
    }
    if (from == 0x1e || to == 0x1e) {
        g_invFlags_guess->flag_010 = g_charData_guess->Lookup_guess()->sub_010.field_078 != 0;
    }
    return 1;
}

struct Point_guess {
    int x;
    int y;
    Point_guess() {}
};

struct Rect_guess {
    int left;
    int top;
    int right;
    int bottom;
    Rect_guess() {
        left = top = right = bottom = 0;
    }
    // EXTERNAL: TITANIUM 0x004D9160 Rect_guess::Assign_guess
    CXRect Assign_guess(const CXRect& other);
    // EXTERNAL: TITANIUM 0x004DC02D Rect_guess::CenterPoint
    Point_guess CenterPoint() const;
};

struct QuantityWnd_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 QuantityWnd_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x0054D976 QuantityWnd_guess::Open_guess
    void Open_guess(LookupData_guess* wnd, int count, int max, Point_guess at, int flag);
};

struct HotbarWnd_guess {
    virtual void V00_guess() = 0; virtual void V01_guess() = 0; virtual void V02_guess() = 0;
    virtual void V03_guess() = 0; virtual void V04_guess() = 0; virtual void V05_guess() = 0;
    virtual void V06_guess() = 0; virtual void V07_guess() = 0; virtual void V08_guess() = 0;
    virtual void V09_guess() = 0; virtual void V10_guess() = 0; virtual void V11_guess() = 0;
    virtual void V12_guess() = 0; virtual void V13_guess() = 0; virtual void V14_guess() = 0;
    virtual void V15_guess() = 0; virtual void V16_guess() = 0; virtual void V17_guess() = 0;
    virtual void V18_guess() = 0; virtual void V19_guess() = 0; virtual void V20_guess() = 0;
    virtual void V21_guess() = 0; virtual void V22_guess() = 0; virtual void V23_guess() = 0;
    virtual void V24_guess() = 0; virtual void V25_guess() = 0; virtual void V26_guess() = 0;
    virtual void V27_guess() = 0; virtual void V28_guess() = 0; virtual void V29_guess() = 0;
    virtual void V30_guess() = 0; virtual void V31_guess() = 0; virtual void V32_guess() = 0;
    virtual void V33_guess() = 0;
    virtual void Reset_guess() = 0;
    char pad_004[0x158];
    int state_15c;
    // EXTERNAL: TITANIUM 0x0059DD30 HotbarWnd_guess::IsActive_guess
    char IsActive_guess();
};

struct ModalWnd_guess {
    char pad_000[0x244];
    unsigned char flag_244;
};

struct UiState_guess {
    char pad_000[0x10];
    bool flag_10;
    unsigned char flag_11;
    unsigned char flag_12;
    // EXTERNAL: TITANIUM 0x0043DD14 UiState_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(ElementRoot_guess* root, int key, Element_guess* item, Element_guess* element);
};

// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(ElementRoot_guess* root);
// EXTERNAL: TITANIUM 0x00474BC5 ContainsMatchingItem_guess
int __cdecl ContainsMatchingItem_guess(ElementRoot_guess* root, int id, Element_guess* item);

#define pinstCQuantityWnd_guess EQ_GLOBAL(QuantityWnd_guess*, 0x00850C3C)
#define g_uiE_guess EQ_GLOBAL(UiHandle_guess*, 0x00850C50)
#define g_hotbar_guess EQ_GLOBAL(HotbarWnd_guess*, 0x00850C24)
#define g_modalA_guess EQ_GLOBAL(ModalWnd_guess*, 0x00905D10)
#define g_modalB_guess EQ_GLOBAL(ModalWnd_guess*, 0x00905CE0)
#define g_uiState_guess EQ_GLOBAL(UiState_guess*, 0x00905D24)
#define g_selectionMgr_guess EQ_GLOBAL(SelectionManager_guess*, 0x00850CB8)
#define g_itemMover_guess EQ_GLOBAL(ItemMover_guess*, 0x00850CB8)

static inline void FinishUse_guess(int key) {
    if (key == 0xd || key == 0xe || key == 0xb) {
        g_player_guess->UpdateEquipmentDisplay_guess(key);
    }
    if (key < 0x1f) {
        UpdateLight_guess(g_elementRoot_guess);
    }
    g_uiSound_guess->WavePlay_guess(0x92, 0);
}

// Quantity prompt answer: picks up `amount` from the stack; all of it moves the whole item to the cursor (and
// refreshes worn ranged/hand slots 11, 13, 14), a part is split with OP_MoveItem.
// FUNCTION: TITANIUM 0x005191E1
// @early-stop: budget, structural ndiff=11
void ActionQueue_guess::PickUpQuantity_guess(int amount) {
    int key = -1;
    if (data_004 != 0) {
        key = data_004->key_120;
    }
    Element_guess* element;
    if (ref_010 != 0) {
        element = ref_010->element_000;
    } else {
        element = 0;
    }
    if (key != -1 && element != 0) {
        int have = element->chargesOrStackCount_0048_guess;
        if (amount != 0) {
            if (amount >= have) {
                g_itemMover_guess->MoveItem(key, 0x1e, 1, 1);
                if (key == 0xd || key == 0xe || key == 0xb) {
                    g_player_guess->UpdateEquipmentDisplay_guess(key);
                }
            } else {
                PendingAction_guess* pending = element->Slot01_guess();
                pending->SetStackCount_guess(amount);
                g_charData_guess->Lookup_guess()->sub_010.field_078 = (Element_guess*)pending;
                element->chargesOrStackCount_0048_guess -= pending->field_048;
                int message[3];
                message[0] = key;
                message[1] = 0x1e;
                message[2] = amount;
                EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_MoveItem, message, 0xc, 1);
                data_004->remainingStackQuantity_0130_guess = have - amount;
            }
        }
        CharSub_guess* sub = &g_charData_guess->Lookup_guess()->sub_010;
        if (sub->field_078 != 0) {
            g_uiState_guess->flag_10 = 1;
        }
        if (g_uiMain_guess != 0 && g_uiMain_guess->IsActive_guess()) {
            g_uiMain_guess->Show_guess(1);
        }
        if (pinstCTradeskillWnd_guess != 0 && pinstCTradeskillWnd_guess->IsVisible_guess()) {
            pinstCTradeskillWnd_guess->Flush_guess();
        }
        g_elementRoot_guess->flag_c28c = 1;
    }
}

// Click on a slot: picks up, drops or swaps with the cursor, with the quantity prompt for stacks. Refusals
// include lore duplicates (379), gear the character can't wear (6611), NOTRANSFER items in the bank (6191),
// and lore or NO TRADE/temporary items in the shared bank (3194, 3195).
// FUNCTION: TITANIUM 0x00519356
// @early-stop: budget, structural ndiff=500
void ActionQueue_guess::HandleLButtonUp_guess(int, bool hotkey) {
    Element_guess* element;
    if (enabled_014 == 0) {
        return;
    }
    if (pinstCQuantityWnd_guess->IsActive_guess()) {
        return;
    }
    if (data_004 == 0) {
        return;
    }
    int key = data_004->key_120;
    if (key == -1) {
        return;
    }
    if (key >= 8000 && key <= 0x1f5f) {
        return;
    }
    if (IsBankSlotLocked_guess(key) == 1) {
        return;
    }
    if (ref_010 != 0) {
        element = ref_010->element_000;
    } else {
        element = 0;
    }
    // A modified click (keyboard flags 4/8) hands the item to the action manager instead of moving it.
    if ((pinstCXWndManager_guess->GetKeyboardFlags() & 0xc) != 0) {
        if (element != 0) {
            unsigned int flags = pinstCXWndManager_guess->GetKeyboardFlags();
            pinstCItemDisplayManager_guess->SetRaw_guess(element, (~flags) & 1);
        }
        return;
    }
    // 7000-7080 are merchant slots: selecting one goes to the merchant window.
    if (key >= 7000 && key <= 0x1ba8) {
        g_selectionMgr_guess->SetSelection_guess((Selection_guess*)this);
        g_uiMain_guess->UseA_guess(key, value_008);
        return;
    }
    if (g_busy_guess != 0) {
        return;
    }
    int target = g_player_guess->info_1a8->id_f98;
    if (target != -1 && IsValidSpellIndex_guess(target) != 0) {
        int info = g_lookupDb_guess->GetSpell_guess(g_player_guess->info_1a8->id_f98, g_player_guess->class_252);
        if (g_elementRoot_guess->elements.IsBardSong_guess(info) == 0) {
            return;
        }
    }
    // Open trade-type windows take the click first, in this order: give (0x00850C4C), then three others.
    if (pinstCMerchantWnd_guess->IsVisible_guess()) {
        if (g_modalA_guess != 0 && g_modalA_guess->flag_244 == 0) {
            return;
        }
        if (element == 0) {
            return;
        }
        g_selectionMgr_guess->SetSelection_guess((Selection_guess*)this);
        pinstCMerchantWnd_guess->SelectBuySellSlot(key, element);
        return;
    }
    if (pinstCTributeMasterWnd_guess != 0 && pinstCTributeMasterWnd_guess->IsVisible_guess()) {
        g_selectionMgr_guess->SetSelection_guess((Selection_guess*)this);
        pinstCTributeMasterWnd_guess->SelectDonationItem_guess(key, value_008);
        return;
    }
    if (pinstCGuildTributeMasterWnd_guess != 0 && pinstCGuildTributeMasterWnd_guess->IsVisible_guess()) {
        g_selectionMgr_guess->SetSelection_guess((Selection_guess*)this);
        pinstCGuildTributeMasterWnd_guess->SetSlot_guess(key, value_008);
        return;
    }
    if (pinstCPointMerchantWnd_guess != 0 && pinstCPointMerchantWnd_guess->IsVisible_guess() && pinstCPointMerchantWnd_guess->dispatch14_guess()) {
        g_selectionMgr_guess->SetSelection_guess((Selection_guess*)this);
        pinstCPointMerchantWnd_guess->setValue_guess(key);
        return;
    }
    if (g_elementRoot_guess == 0) {
        return;
    }
    g_elementRoot_guess->flag_c28c = 1;
    if (g_hotbar_guess->IsActive_guess()) {
        if (g_uiState_guess->flag_11 != 0) {
            return;
        }
        if (hotkey && g_hotbar_guess->state_15c >= 4 && g_hotbar_guess->state_15c <= 0xb) {
            return;
        }
        if (g_charData_guess->Lookup_guess()->sub_010.field_078 == 0) {
            g_hotbar_guess->Reset_guess();
            g_uiState_guess->flag_12 = 0;
        }
    }
    // Empty cursor: pick up. A stack outside trade, loot and world-container slots opens the quantity window;
    // blocked items in a world container or the shared bank say 0x17B; worn slots unequip first.
    bool moved = false;
    bool done = false;
    if (g_charData_guess->Lookup_guess()->sub_010.field_078 == 0) {
        if (element != 0 && (key < 3000 || key >= 4000)) {
            if (element->IsStackable_guess() && (key < 5000 || key >= 0x13a7) && (key < 4000 || key >= 0xfbf)) {
                int count = element->chargesOrStackCount_0048_guess;
                if (count > element->GetLimit_guess()) {
                    count = element->GetLimit_guess();
                }
                Rect_guess rect;
                rect.Assign_guess(data_004->GetScreenRect_guess());
                pinstCQuantityWnd_guess->Open_guess(data_004, count, count, rect.CenterPoint(), 1);
                return;
            }
            if ((key >= 4000 && key <= 0xfbf && g_elementRoot_guess != 0 &&
                 g_elementRoot_guess->IsBlocked_guess(element) != 0) ||
                (key >= 0x9c4 && key < 0x9f7 && g_elementRoot_guess->IsBlocked_guess(element) != 0)) {
                pEverQuest->dsp_chat(pStringTable->getString(0x17b, 0), 0xf, 1);
                return;
            }
            if (element->GetItemClass_guess() == 1 && element->SecondCheck_guess() != 0) {
                g_elementManager_guess->CloseContainer_guess(element, 1);
            }
            if (key < 0x16) {
                g_uiState_guess->UpdateItemSlot_guess(g_elementRoot_guess, key, 0, element);
            }
            done = g_itemMover_guess->MoveItem(key, 0x1e, 1, 1) != 0;
        }
    // Item on the cursor onto the body or packs: 0x19D3 when it can't be worn there. Equipping an item whose
    // +0x5C is clear asks first (0x1718, box type 0x79) and finishes from the dialog.
    } else if (key < 0x1f && key >= 0) {
        if (g_elementRoot_guess->FitsEquipSlot_guess(key, g_charData_guess->Lookup_guess()->sub_010.field_078) != 0) {
            if (key < 0x16 && g_elementRoot_guess->elements.CanUseItem_guess(g_charData_guess->Lookup_guess()->sub_010.field_078, 1) == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x19d3, 0), 0xd, 1);
            } else {
                if (element != 0 && element->GetItemClass_guess() == 1 && element->SecondCheck_guess() != 0) {
                    g_elementManager_guess->CloseContainer_guess(element, 1);
                }
                if (key < 0x16) {
                    if (g_charData_guess->Lookup_guess()->sub_010.field_078 != 0 && g_charData_guess->Lookup_guess()->sub_010.field_078->Count_guess() != 0 &&
                        g_charData_guess->Lookup_guess()->sub_010.field_078->value_05c == 0) {
                        int* pending = new int;
                        *pending = key;
                        ++g_busy_guess;
                        char text[512];
                        Format_guess(text, 0x1718, g_charData_guess->Lookup_guess()->sub_010.field_078->Text_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
                        pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x79, text,
                                                                0xc, -1, (int)pending, 0);
                        return;
                    }
                    g_uiState_guess->UpdateItemSlot_guess(g_elementRoot_guess, key, g_charData_guess->Lookup_guess()->sub_010.field_078, element);
                }
                moved = g_itemMover_guess->MoveItem(0x1e, key, 1, 1) != 0;
            }
        }
    // Trade slots: only into an empty slot, and only what the trade allows (anything for an NPC).
    } else if (key >= 3000 && key < 0xbd7) {
        if (element == 0 && (g_uiE_guess->IsActive_guess() || pinstCGiveWnd_guess->IsVisible_guess())) {
            if ((g_modalB_guess != 0 && g_modalB_guess->flag_244 == 1) || g_charData_guess->Lookup_guess()->sub_010.field_078->IsOkToActivate_guess(1)) {
                moved = g_itemMover_guess->MoveItem(0x1e, key, 1, 1) != 0;
            }
        }
    } else if (!(key >= 0xbd7 && key < 4000) && !(key >= 5000 && key < 0x13a7)) {
        if (element != 0 && key >= 4000 && key <= 0xfbf && g_elementRoot_guess != 0 &&
            g_elementRoot_guess->IsBlocked_guess(element) != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x17b, 0), 0xf, 1);
            return;
        }
        // Bank and shared-bank rules: NOTRANSFER items stay out of the bank (0x182F); the shared bank refuses
        // lore duplicates (0xC7A) and NO TRADE or temporary items (0xC7B).
        if (key >= 2000 && key <= 0x88f && g_elementRoot_guess != 0 && g_charData_guess->Lookup_guess()->sub_010.field_078->HasFlagA_guess(1)) {
            pEverQuest->dsp_chat(pStringTable->getString(0x182f, 0), 0xf, 1);
            return;
        }
        if (element != 0 && key >= 0x9c4 && key <= 0x9f7 && g_elementRoot_guess != 0 &&
            g_elementRoot_guess->IsBlocked_guess(element) != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x17b, 0), 0xf, 1);
            return;
        }
        if (key >= 0x9c4 && key <= 0x9f7) {
            if (g_elementRoot_guess != 0 &&
                ContainsMatchingItem_guess(g_elementRoot_guess, g_charData_guess->Lookup_guess()->sub_010.field_078->GetItemId_guess(), g_charData_guess->Lookup_guess()->sub_010.field_078) != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0xc7a, 0), 0xf, 1);
                return;
            }
            if (key < 0x9f7 && (!g_charData_guess->Lookup_guess()->sub_010.field_078->IsOkToActivate_guess(0x29a) || g_charData_guess->Lookup_guess()->sub_010.field_078->HasFlagB_guess(1) == 0 ||
                                g_charData_guess->Lookup_guess()->sub_010.field_078->HasFlagA_guess(1))) {
                pEverQuest->dsp_chat(pStringTable->getString(0xc7b, 0), 0xf, 1);
                return;
            }
        }
        if (key > 0x1f) {
            if (element != 0 && element->GetItemClass_guess() == 1 && element->SecondCheck_guess() != 0) {
                g_elementManager_guess->CloseContainer_guess(element, 1);
            }
            moved = g_itemMover_guess->MoveItem(0x1e, key, 1, 1) != 0;
        }
    }
    // After a move: clear the pending quantity, reset the hotbar, and play sound 0x92 (FinishUse_guess).
    if (moved) {
        data_004->remainingStackQuantity_0130_guess = -1;
        g_hotbar_guess->Reset_guess();
        done = true;
    }
    if (done) {
        FinishUse_guess(key);
    }
    g_uiState_guess->flag_10 = g_charData_guess->Lookup_guess()->sub_010.field_078 != 0;
    g_elementRoot_guess->flag_c348 = 0;
    if (g_uiMain_guess != 0 && g_uiMain_guess->IsActive_guess()) {
        g_uiMain_guess->Show_guess(1);
    }
    if (pinstCTradeskillWnd_guess != 0 && pinstCTradeskillWnd_guess->IsVisible_guess()) {
        pinstCTradeskillWnd_guess->Flush_guess();
    }
}

struct TimerRoot_guess {
    char pad_000[0x148];
    int time_148;
};

struct SlotHolderA_guess {
    char pad_000[0x5c];
    char flag_05c;
    char pad_05d[0x1f4 - 0x5d];
    Element_guess* table_1f4[32];
};

struct SlotHolderC_guess {
    char pad_000[0x5c];
    char flag_05c;
    char pad_05d[0x2e4 - 0x5d];
    Element_guess* table_2e4[80];
};

struct SlotHolderD_guess {
    char pad_000[0x5c];
    char flag_05c;
    char pad_05d[0x1e8 - 0x5d];
    Element_guess* table_1e8[31];
};

struct SlotHolderE_guess {
    char pad_000[0x5c];
    char flag_05c;
    char pad_05d[0x164 - 0x5d];
    Element_guess* table_164[31];
};

struct CharDataTables_guess {
    char pad_000[0xcf0];
    Element_guess* table_cf0[16];
    Element_guess* table_d30[2];
};

struct SlotHost_guess {
    // EXTERNAL: TITANIUM 0x004FA6E6 SlotHost_guess::Wrap_guess
    Element_guess** Wrap_guess(int index);
};

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

#define g_timeRoot_guess EQ_GLOBAL(TimerRoot_guess*, 0x00905D24)
#define g_slotHolderA_guess EQ_GLOBAL(SlotHolderA_guess*, 0x00850C50)
#define g_slotHolderC_guess EQ_GLOBAL(SlotHolderC_guess*, 0x00850C58)
#define g_slotHolderD_guess EQ_GLOBAL(SlotHolderD_guess*, 0x00850C40)
#define pinstCInspectWnd_guess EQ_GLOBAL(SlotHolderE_guess*, 0x00850C68)
#define g_charDataTables_guess EQ_GLOBAL(CharDataTables_guess*, 0x00905D00)
#define g_slotHost_guess EQ_GLOBAL(SlotHost_guess*, 0x00850CBC)

struct LookupOffset_guess {
    unsigned char padding_guess[4];
    int offset_guess;
};

struct LookupRankEntry_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 LookupRankEntry_guess::GetItemClass_guess
    int GetItemClass_guess();
};

struct LookupRankTable_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 LookupRankTable_guess::GetEntry_guess
    LookupRankEntry_guess* GetEntry_guess(int index);
};

struct LookupRankRoot_guess {
    unsigned char padding_guess[8];
    union {
        LookupOffset_guess* offset_guess;
        unsigned char embedded_guess[0xC278];
    };
};

#define g_lookupRankRoot_guess EQ_GLOBAL(LookupRankRoot_guess*, 0x00905D00)

// Before the player is rebuilt (OP_RecreateSpawn 0x12B2, 0x0045AFDC): with a character loaded,
// unbinds (Bind(0)) every slot object bound to slot 0-250 or 331-340, and to the pack slots 251-330
// only where the pack ((slot - 31) / 10) passes 0x005ECCC0.
// FUNCTION: TITANIUM 0x0051B201
// @early-stop: budget, structural ndiff=43
void CInvSlotMgrView_guess::RunDueEntries_guess() {
    int index = 0;
    if (count > 0) {
        CInvSlotMgrView_guess::Entry_guess** entry = entries;
        do {
            if (*entry != 0) {
                LookupData_guess* data = (LookupData_guess*)((CInvSlotView_guess*)*entry)->referenced;
                int key = -1;
                if (data != 0) {
                    key = data->key_120;
                }
                int group = 0;
                LookupRankEntry_guess* rank = 0;
                if (g_lookupRankRoot_guess != 0 && key != -1 &&
                    ((key >= 0 && key < 0x1e) ||
                     (key < 0x155 &&
                      ((group = (key - 0x1f) / 10) < 0x16 || group > 0x1d ||
                       ((rank = ((LookupRankTable_guess*)&g_lookupRankRoot_guess->embedded_guess[
                             g_lookupRankRoot_guess->offset_guess->offset_guess])->GetEntry_guess(group)) != 0 &&
                        rank->GetItemClass_guess() == 1))))) {
                    ((CInvSlotView_guess*)*entry)->Bind_guess(0);
                }
            }
            ++index;
            ++entry;
        } while (index < count);
    }
}

// Every 100 ms (or when forced) re-reads which windows are open and refreshes the slot objects.
// FUNCTION: TITANIUM 0x0051B2AE
// @early-stop: budget, structural ndiff=162
unsigned int CInvSlotMgrView_guess::Refresh_guess(char force) {
    if (force == 0) {
        unsigned int elapsed = g_timeRoot_guess->time_148 - time_1008;
        if (elapsed < 100) {
            return elapsed;
        }
    }
    {
        int level = 8;
        char flag11 = 0;
        force = 0;
        char flag10 = 0;
        char flagE = 0;
        char flagF = 0;
        char flagD = 0;
        if (g_clientObject_guess != 0) {
            level = g_clientObject_guess->GetNumBankSlots();
            flag11 = g_clientObject_guess->flag_05c;
        }
        if (g_slotHolderA_guess != 0) {
            force = g_slotHolderA_guess->flag_05c;
        }
        if (pinstCGiveWnd_guess != 0) {
            flag10 = pinstCGiveWnd_guess->dShow;
        }
        if (g_slotHolderC_guess != 0) {
            flagE = g_slotHolderC_guess->flag_05c;
        }
        if (g_slotHolderD_guess != 0) {
            flagF = g_slotHolderD_guess->flag_05c;
        }
        if (pinstCInspectWnd_guess != 0) {
            flagD = pinstCInspectWnd_guess->flag_05c;
        }
        time_1008 = FUN_0046d655_guess();
        int i = 0;
        if (count > 0) {
            do {
                CInvSlotView_guess* cleanup = (CInvSlotView_guess*)entries[i];
                if (cleanup != 0) {
                    int key = -1;
                    LookupData_guess* data = (LookupData_guess*)cleanup->referenced;
                    if (data != 0) {
                        key = data->key_120;
                    }
                    if (g_charData_guess != 0 && key != -1) {
                        if (key < 0x1e && key >= 0) {
                            cleanup->Bind_guess(g_charData_guess->GetSlot_guess(key));
                        } else if (key < 0x155) {
                            int row = (key - 0x1f) / 10;
                            int rem = (key - 0x1f) % 10;
                            if (row < 0x16 || row > 0x1d) {
                                cleanup->Bind_guess(0);
                            } else {
                                Node_guess* node = g_charData_guess->Find_guess(row);
                                Element_guess* element = (Element_guess*)node;
                                if (element != 0 && element->GetItemClass_guess() == 1) {
                                    cleanup->Bind_guess(element->GetSlot_guess(rem));
                                }
                            }
                        } else if (flag11 != 0 && key >= 2000 && key < 2031) {
                            int index = key - 2000;
                            if (index >= level) {
                                cleanup->Bind_guess(0);
                            } else {
                                cleanup->Bind_guess(&g_charDataTables_guess->table_cf0[index]);
                            }
                        } else if (flag11 != 0 && key >= 2031 && key < 2191) {
                            int row = (key - 2031) / 10;
                            int rem = (key - 2031) % 10;
                            if (row >= level) {
                                cleanup->Bind_guess(0);
                            } else {
                                Element_guess* element = g_charDataTables_guess->table_cf0[row];
                                if (element != 0 && element->GetItemClass_guess() == 1) {
                                    cleanup->Bind_guess(element->GetSlot_guess(rem));
                                }
                            }
                        } else if (flag11 != 0 && key >= 2500 && key < 2531) {
                            int index = key - 2500;
                            if (index >= 2) {
                                cleanup->Bind_guess(0);
                            } else {
                                cleanup->Bind_guess(&g_charDataTables_guess->table_d30[index]);
                            }
                        } else if (flag11 != 0 && key >= 2531 && key < 2551) {
                            int row = (key - 2531) / 10;
                            int rem = (key - 2531) % 10;
                            if (row >= 2) {
                                cleanup->Bind_guess(0);
                            } else {
                                Element_guess* element = g_charDataTables_guess->table_d30[row];
                                if (element != 0 && element->GetItemClass_guess() == 1) {
                                    cleanup->Bind_guess(element->GetSlot_guess(rem));
                                }
                            }
                        } else if ((force != 0 || flag10 != 0) && key >= 3000 && key < 3031) {
                            cleanup->Bind_guess(&g_slotHolderA_guess->table_1f4[key - 3000]);
                        } else if (force != 0 && key >= 3031 && key < 3341) {
                            int row = (key - 3031) / 10;
                            int rem = (key - 3031) % 10;
                            if (row < 0 || row >= 16) {
                                cleanup->Bind_guess(0);
                            } else {
                                Element_guess* element = g_slotHolderA_guess->table_1f4[row];
                                if (element != 0 && element->GetItemClass_guess() == 1) {
                                    cleanup->Bind_guess(element->GetSlot_guess(rem));
                                }
                            }
                        } else if (key >= 4000 && key <= 4030) {
                            cleanup->Bind_guess(g_slotHost_guess->Wrap_guess(key - 4000));
                        } else if (flagF != 0 && key >= 5000 && key < 5031) {
                            cleanup->Bind_guess(&g_slotHolderD_guess->table_1e8[key - 5000]);
                        } else if (flagE != 0 && key >= 7000 && key < 7080) {
                            cleanup->Bind_guess(&g_slotHolderC_guess->table_2e4[key - 7000]);
                        } else if (flagD != 0 && key >= 8000 && key < 8031) {
                            cleanup->Bind_guess(&pinstCInspectWnd_guess->table_164[key - 8000]);
                        }
                    }
                }
                ++i;
            } while (i < count);
            return (unsigned int)this;
        }
        return time_1008;
    }
}
