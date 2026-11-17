// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 151: a hint from compare/tumap.py.
// Three windows: CDynamicZoneWnd ("DynamicZoneWnd", the expedition window: PanelOwner_guess,
// CallbackOwner_guess), CDynamicZoneSwitchListWnd (SwitchListWnd_guess, MessageOwner_guess,
// MessageCallback_guess, EventOwner_guess) and the CEditLabelWnd constructor. The expedition data is at
// 0x9231C8: in-expedition flag +0x49, leader +0x4A, zone name +0x8A; members 0x9232D8, timers 0x9232DC.
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct GlobalLink_guess {
    char pad[4];
    int vbaseOffset_0004_guess;
};

struct NameData_guess {
    char pad[0x120];
    char text[1];
};

struct GlobalState_guess {
    char pad[8];
    GlobalLink_guess* link;
    char pad_00c_guess[0xc27c];
    NameData_guess* pSpawn_c288_guess;
};

struct Listener_guess {
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
    virtual Listener_guess** Slot76_guess();
    // EXTERNAL: TITANIUM 0x0059B9D0 Listener_guess::AddString
    int AddString(const CXStr& name_guess, unsigned long a_guess, unsigned int b_guess, const CTextureAnimation* c_guess);
    // EXTERNAL: TITANIUM 0x0059B360 Listener_guess::SetItemText
    void SetItemText(int index_guess, int which_guess, const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x00598620 Listener_guess::SetItemData
    void SetItemData(int index_guess, unsigned int key_guess);
    // EXTERNAL: TITANIUM 0x0059B3E0 Listener_guess::SetCell_guess
    void SetCell_guess(int index_guess, int slot_guess, unsigned long color_guess);
};

struct Helper_guess {
    char pad[0x10];
    // EXTERNAL: TITANIUM 0x004467BE Helper_guess::Advance_guess
    void Advance_guess();
    // EXTERNAL: TITANIUM 0x00446DC5 Helper_guess::Insert_guess
    void Insert_guess(void* entry_guess, int key_guess);
};

struct HashTable_guess;

struct EventOwner_guess {
    char pad[0x15c];
    Helper_guess helper;
    Listener_guess* listener;
    void Dispatch_guess();
    void Walk_guess(HashTable_guess* table_guess);
    const char* GetTextById_guess(int id_guess);
};

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(char* first, char* second);

struct HashEntry_guess {
    int field_000_guess;
    int pad_004_guess;
    int field_008_guess;
    char pad_00c_guess[4];
    char text_010_guess[0x80];
    char text_090_guess[0x40];
    unsigned int key;
    HashEntry_guess* next;
};

struct HashTable_guess {
    HashEntry_guess** buckets;
    unsigned int bucketCount;
    // EXTERNAL: TITANIUM 0x004466FA HashTable_guess::First_guess
    HashEntry_guess* First_guess();
    HashEntry_guess* Find_guess(unsigned int key);
    HashEntry_guess* Next_guess(HashEntry_guess* entry_guess);
};

struct MessageOwner_guess {
    char pad_000_15b_guess[0x15c];
    HashTable_guess table;
    char pad_164_16b_guess[8];
    CListWnd* source;
    void SendChooseZoneReply_guess();
};

struct MessageCallback_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess);
    char pad_004_16f_guess[0x16c];
    int field_170_guess;
    int field_174_guess;
    void Dispatch_guess(int key_guess, int type_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005A2230 MessageCallback_guess::WndNotification
    void WndNotification(int key_guess, int type_guess, int value_guess);
};

struct MessageEntry_guess {
    int unknown_000_guess;
    int field_004_guess;
    int field_008_guess;
    int field_00c_guess;
};

struct MessageData_guess {
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    int field_00c_guess;
    int field_010_guess;
    int field_014_guess;
    int unused_018_guess[6];
};

#define g_voidConnection_guess EQ_GLOBAL(int, 0x00905CA0)

struct CallbackOwner_guess {
    char pad_005c[0x5c];
    char enabled_005c; // 0x5c

    // EXTERNAL: TITANIUM 0x005A1880 CallbackOwner_guess::OnShow
    void OnShow();

    void Dispatch_guess();
};

#define g_emptyText_guess EQ_GLOBAL(char, 0x0065368C)

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory);

struct ChildEntry_guess {
    char pad[0xd4];
    ChildEntry_guess* next;
};

struct Child_guess {
    ChildEntry_guess** buckets;
    int bucketCount;
    int nodeCount;
    int usedCount;
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00446D94 Child_guess::Child_guess
    Child_guess(int bucketCount_guess);
    ~Child_guess();
};

// Frees every node of every bucket and empties the buckets, keeping the node and used-bucket counts
// in step.
// FUNCTION: TITANIUM 0x004467BE
void Child_guess::Clear_guess() {
    for (int index = 0; index < bucketCount; index++) {
        ChildEntry_guess* node = buckets[index];
        if (node != 0) {
            usedCount--;
            do {
                ChildEntry_guess* next = node->next;
                free(node);
                nodeCount--;
                node = next;
            } while (node != 0);
            buckets[index] = node;
        }
    }
}

// Destructor of the zone-choice table (a hash table of choices by key): frees every node (0x004467BE),
// then the bucket array. The choose-zone handler (0x0044717E) and the switch list window destructor use
// it.
// FUNCTION: TITANIUM 0x00446DB3
Child_guess::~Child_guess() {
    Clear_guess();
    FreeArray_guess(buckets);
}

// Name of zone-choice kind 1-5 (strings 0xDF8-0xDFC); empty for anything else.
// FUNCTION: TITANIUM 0x004FE00D
const char* EventOwner_guess::GetTextById_guess(int id_guess) {
    switch (id_guess) {
    case 1:
        return pStringTable->getString(0xdf8, 0);
    case 2:
        return pStringTable->getString(0xdf9, 0);
    case 3:
        return pStringTable->getString(0xdfa, 0);
    case 4:
        return pStringTable->getString(0xdfb, 0);
    case 5:
        return pStringTable->getString(0xdfc, 0);
    }
    return &g_emptyText_guess;
}

#define g_childVtable_guess EQ_GLOBAL(void*, 0x00653690)
#define g_childResetVtable_guess EQ_GLOBAL(void*, 0x0063FD9C)

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CTipWnd.h"

// EXTERNAL: TITANIUM 0x0063FD9C ??_7WindowBase1_guess@@6B@
struct WindowBase1_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005482A0 WindowBase1_guess::Stop_guess
    void Stop_guess(int value_guess);
    virtual ~WindowBase1_guess() {
        Stop_guess(-1);
    }
};

// EXTERNAL: TITANIUM 0x00653698 ??_7WindowOwner_guess@@6BCSidlScreenWndBase@@@
// EXTERNAL: TITANIUM 0x00653690 ??_7WindowOwner_guess@@6BWindowBase1_guess@@@
struct WindowOwner_guess : CSidlScreenWndBase, WindowBase1_guess {
    virtual void Slot00_guess();
    WindowOwner_guess* ScalarDeletingDestructor_guess(unsigned char flags);
    virtual ~WindowOwner_guess();
};

// Destructor of the expedition window (CDynamicZoneWnd, vtable 0x653698): expires every confirmation
// dialog its dialog-owner part (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd
// destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004FE060
WindowOwner_guess::~WindowOwner_guess() {
}

// Scalar deleting destructor of the expedition window (vtable 0x653698 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x004FE9CD
WindowOwner_guess* WindowOwner_guess::ScalarDeletingDestructor_guess(unsigned char flags) {
    this->WindowOwner_guess::~WindowOwner_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Closing while shown tells 0x9928E0 about window id 0x2F (the id the constructor stores at +0x158).
// FUNCTION: TITANIUM 0x004FE0AC
void CallbackOwner_guess::Dispatch_guess() {
    if (enabled_005c != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x2f, 0);
        }
    }
    return OnShow();
}

// Answer of the quit confirmation (dialog id 0x486D): a yes (flags 1 or 4) sends OP_DzQuit.
// FUNCTION: TITANIUM 0x004FE0D0
// @early-stop: unknown, structural ndiff=8
void __stdcall HandleMessage_guess(int message_guess, unsigned char flags_guess,
                                   int unused_guess) {
    if (message_guess == 0x486d && (flags_guess & 5) != 0) {
        EQSendMessage(&g_voidConnection_guess, OP_DzQuit, &message_guess, 4, 1);
    }
}

struct Panel_guess {
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
    virtual void Apply_guess(char state_guess, int mode_guess);
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
    virtual void Slot63_guess(CXStr* text_guess);
    // EXTERNAL: TITANIUM 0x004D22D7 Panel_guess::GetText_guess
    CXStr GetText_guess();
    char pad_004_05c_guess[0x59];
    char state_05d_guess;
};

// EXTERNAL: TITANIUM 0x00653698 ??_7PanelOwner_guess@@6BCSidlScreenWndBase@@@
// EXTERNAL: TITANIUM 0x00653690 ??_7PanelOwner_guess@@6BWindowBase1_guess@@@
struct PanelOwner_guess : CSidlScreenWndBase, WindowBase1_guess {
    CXWnd* currentDZValue_0160_guess;
    CXWnd* leaderValue_0164_guess;
    CListWnd* list_168_guess;
    Panel_guess* dzLeaderSection_016c_guess;
    Panel_guess* leaderTarget_0170_guess;
    Panel_guess* leaderTargetValue_0174_guess;
    Panel_guess* numPlayersValue_0178_guess;
    Panel_guess* maxPlayersValue_017c_guess;
    Panel_guess* leaderAdd_0180_guess;
    Panel_guess* leaderRemove_0184_guess;
    Panel_guess* quit_0188_guess;
    Panel_guess* leaderMakeLeader_018c_guess;
    Panel_guess* first_guess;
    Panel_guess* second_guess;
    Listener_guess* list_198_guess;
    int lastUpdateTick_19c_guess;
    PanelOwner_guess(CXWnd* parent_guess);
    void Refresh_guess();
    int OnProcessFrame_guess();
    // FUNCTION declared on the definition below.
    int WndNotification(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
    void Update_4FE0FD_guess();
    void UpdateIfShown_4FE0FD_guess();
    // EXTERNAL: TITANIUM 0x004FF21C PanelOwner_guess::Update_4FF21C_guess
    void Update_4FF21C_guess();
    void UpdateIfShown_4FF21C_guess();
    void Update_4FF146_guess(char flag_guess);
    bool Update_4FF526_guess();
    void Update_4FE3E3_guess();
    // EXTERNAL: TITANIUM 0x004FEA23 PanelOwner_guess::Update_4FEA23_guess
    void Update_4FEA23_guess();
    void Update_4FF11E_guess();
};

#define g_refreshMode_guess EQ_GLOBAL(char, 0x00923211)
#define g_refreshText_guess EQ_GLOBAL(char*, 0x00985C88)

struct SetupGlobal_guess {
    char pad_000_11f_guess[0x120];
    char text_120_guess[0x124];
    char flag_244_guess;
};

// Puts a name in DZ_Leader_TargetValue: your target's (0x905D04 +0x120) unless its type (+0x244) is 1,
// probably an NPC; else the selected member.
// FUNCTION: TITANIUM 0x004FE3E3
void PanelOwner_guess::Update_4FE3E3_guess() {
    SetupGlobal_guess* global = EQ_GLOBAL(SetupGlobal_guess*, 0x00905D04);
    if (global != 0 && leaderTargetValue_0174_guess != 0 && global->flag_244_guess != 1) {
        CXStr text(&global->text_120_guess[0]);
        leaderTargetValue_0174_guess->Slot63_guess(&text);
        if (list_168_guess != 0) {
            list_168_guess->ClearAllSel();
        }
    } else {
        CXStr text;
        if (list_168_guess != 0) {
            if (list_168_guess->GetCurSel() >= 0) {
                text = list_168_guess->GetItemText(list_168_guess->GetCurSel(), 0);
            }
        }
        if (leaderTargetValue_0174_guess != 0) {
            leaderTargetValue_0174_guess->Slot63_guess(&text);
        }
    }
}

// Enables the two buttons at +0x190 and +0x194 only inside an expedition, and lights one of them by the
// first byte of the 0x985C88 object. The constructor never fetches these two, so they stay 0 unless
// something else sets them.
// FUNCTION: TITANIUM 0x004FE347
void PanelOwner_guess::Refresh_guess() {
    char mode_guess = g_refreshMode_guess;
    if (first_guess != 0 && second_guess != 0) {
        char state_guess;
        first_guess->state_05d_guess = 0;
        second_guess->state_05d_guess = 0;
        if (mode_guess != 0) {
            if (g_refreshText_guess == 0) {
                return;
            }
            first_guess->state_05d_guess = 1;
            second_guess->state_05d_guess = 1;
            state_guess = *g_refreshText_guess;
            first_guess->Apply_guess(state_guess == 0, 1);
            second_guess->Apply_guess(state_guess, 1);
        } else {
            first_guess->Apply_guess(1, 1);
            state_guess = 0;
            second_guess->Apply_guess(state_guess, 1);
        }
    }
}

// Zone-choice table: returns the entry with `key` (bucket key % bucket count, then the chain), or 0.
// The choose-zone reply (0x004FE5A9) finds the selected row's entry with it.
// FUNCTION: TITANIUM 0x004FE4F3
HashEntry_guess* HashTable_guess::Find_guess(unsigned int key) {
    HashEntry_guess* entry = buckets[key % bucketCount];
    while (entry != 0 && entry->key != key) {
        entry = entry->next;
    }
    return entry;
}

// Hash table iteration: the entry after `entry_guess`, either its chain successor or the head of the
// next non-empty bucket; 0 at the end.
// FUNCTION: TITANIUM 0x004FE51C
HashEntry_guess* HashTable_guess::Next_guess(HashEntry_guess* entry_guess) {
    int bucket_guess = entry_guess->key % bucketCount;
    HashEntry_guess* next_guess = entry_guess->next;
    if (next_guess == 0) {
        int index_guess = bucket_guess + 1;
        if (bucket_guess + 1 < (int)bucketCount) {
            HashEntry_guess** current_guess = buckets + index_guess;
            do {
                HashEntry_guess* current_entry_guess = *current_guess;
                if (current_entry_guess != 0) {
                    return current_entry_guess;
                }
                ++index_guess;
                ++current_guess;
            } while (index_guess < (int)bucketCount);
        }
        next_guess = 0;
    }
    return next_guess;
}

// True when the name at +0x4A of the object is yours; with 0x9231C8 it means you lead the expedition.
// FUNCTION: TITANIUM 0x004FE558
bool __fastcall NameMatch_guess(int objectAddress) {
    char* first = (char*)(objectAddress + 0x4a);
    if (first != 0) {
        GlobalState_guess* global = EQ_GLOBAL(GlobalState_guess*, 0x00905D00);
        char* second = (char*)global + global->link->vbaseOffset_0004_guess + 0x44;
        if (second != 0) {
            return __stricmp(first, second) == 0;
        }
    }
    return 0;
}

// Empties the zone-choice table and DZSwitchList_List.
// FUNCTION: TITANIUM 0x004FE582
void EventOwner_guess::Dispatch_guess() {
    helper.Advance_guess();
    if (listener != 0) {
        listener->Slot76_guess();
    }
}

// SendChooseZoneReply_guess is misnamed: answers the zone choice with the selected row (OP_DzChooseZoneReply 0x20E7:
// -1, -1, then the entry's fields and its key).
// FUNCTION: TITANIUM 0x004FE5A9
void MessageOwner_guess::SendChooseZoneReply_guess() {
    if (source != 0) {
        int index_guess = source->GetItemData(source->GetCurSel());
        HashEntry_guess* found_guess = table.Find_guess(index_guess);
        if (found_guess != 0) {
            MessageEntry_guess* entry_guess = (MessageEntry_guess*)found_guess;
            MessageData_guess message_guess;
            message_guess.field_004_guess = -1;
            message_guess.field_000_guess = -1;
            message_guess.field_008_guess = entry_guess->field_004_guess;
            message_guess.field_00c_guess = index_guess;
            message_guess.field_010_guess = entry_guess->field_008_guess;
            message_guess.field_014_guess = entry_guess->field_00c_guess;
            EQSendMessage(&g_voidConnection_guess, OP_DzChooseZoneReply, &message_guess, 0x30, 1);
        }
    }
}

// Expedition window constructor: finds the current expedition and leader values, the member list, the
// leader section with its target, add, remove and make-leader controls, Quit, the timer list and the
// player count and maximum values.
// FUNCTION: TITANIUM 0x004FE619
// @early-stop: budget, diff ndiff=12
PanelOwner_guess::PanelOwner_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "DynamicZoneWnd") {
    currentDZValue_0160_guess = 0;
    leaderValue_0164_guess = 0;
    list_168_guess = 0;
    dzLeaderSection_016c_guess = 0;
    leaderTarget_0170_guess = 0;
    leaderTargetValue_0174_guess = 0;
    numPlayersValue_0178_guess = 0;
    maxPlayersValue_017c_guess = 0;
    leaderAdd_0180_guess = 0;
    leaderRemove_0184_guess = 0;
    quit_0188_guess = 0;
    leaderMakeLeader_018c_guess = 0;
    first_guess = 0;
    second_guess = 0;
    list_198_guess = 0;
    lastUpdateTick_19c_guess = 0;

    if (((CSidlScreenWnd*)this)->SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->WindowStyle |= 0x10000;
        // Window id 0x2F, reported to 0x9928E0 when the window closes.
        ((CSidlScreenWnd*)this)->pad_144[5] = 0x2f;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        currentDZValue_0160_guess = ((CSidlScreenWnd*)this)->GetChildItem("DZ_CurrentDZValue");
        list_168_guess = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("DZ_MemberList");
        leaderValue_0164_guess = ((CSidlScreenWnd*)this)->GetChildItem("DZ_LeaderValue");
        dzLeaderSection_016c_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZLeaderSection");
        leaderTarget_0170_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Leader_Target");
        leaderTargetValue_0174_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Leader_TargetValue");
        leaderAdd_0180_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Leader_Add");
        leaderRemove_0184_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Leader_Remove");
        quit_0188_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Quit");
        leaderMakeLeader_018c_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_Leader_MakeLeader");
        list_198_guess = (Listener_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_TimerList");
        numPlayersValue_0178_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_NumPlayersValue");
        maxPlayersValue_017c_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("DZ_MaxPlayersValue");
    }
}

// EXTERNAL: TITANIUM 0x00576E80 GetClientTime_guess
int __cdecl GetClientTime_guess();

// EXTERNAL: TITANIUM 0x0046D607 GetDaysHoursMinutesSeconds_guess
void __cdecl GetDaysHoursMinutesSeconds_guess(int seconds_guess, int* days_guess, int* hours_guess,
                                int* minutes_guess, int* rest_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, int id_guess, const char* a_guess,
                              const char* b_guess, const char* c_guess, int zero1_guess,
                              int zero2_guess, int zero3_guess, int zero4_guess,
                              int zero5_guess, int zero6_guess);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer_guess, const char* format_guess, ...);

struct TimerEntry_guess {
    char text_000_guess[0x80];
    char text_080_guess[0x100];
    int time_180_guess;
    int pad_184_guess;
    TimerEntry_guess* next_188_guess;
};

// Lists your lockout timers (0x9232DC) that have more than a minute left: "days hours minutes" (string
// 0xDD4) and two names, probably the expedition and the event, all in red.
// FUNCTION: TITANIUM 0x004FE0FD
void PanelOwner_guess::Update_4FE0FD_guess() {
    if (list_198_guess != 0) {
        GetClientTime_guess();
        list_198_guess->Slot76_guess();
        for (TimerEntry_guess* entry_guess = EQ_GLOBAL(TimerEntry_guess*, 0x009232DC);
             entry_guess != 0; entry_guess = entry_guess->next_188_guess) {
            int remaining_guess = entry_guess->time_180_guess - GetClientTime_guess();
            if (remaining_guess > 60) {
                int days_guess;
                int hours_guess;
                int minutes_guess;
                int rest_guess;
                GetDaysHoursMinutesSeconds_guess(remaining_guess, &days_guess, &hours_guess, &minutes_guess,
                                   &rest_guess);
                char days_text_guess[0x20];
                char minutes_text_guess[0x20];
                char hours_text_guess[0x20];
                char message_guess[0x4c4];
                sprintf(days_text_guess, EQ_ARRAY(char, 0x0063F53C), days_guess);
                sprintf(hours_text_guess, EQ_ARRAY(char, 0x0063F53C), hours_guess);
                sprintf(minutes_text_guess, EQ_ARRAY(char, 0x0063F53C), minutes_guess);
                FormatText_guess(message_guess, 0xdd4, days_text_guess, hours_text_guess,
                                 minutes_text_guess, 0, 0, 0, 0, 0, 0);
                CXStr text_guess(message_guess);
                int index_guess = list_198_guess->AddString(text_guess, 0xffff0000, 0, 0);
                {
                    CXStr name_guess(entry_guess->text_000_guess);
                    list_198_guess->SetItemText(index_guess, 1, name_guess);
                }
                list_198_guess->SetCell_guess(index_guess, 1, 0xffff0000);
                {
                    CXStr desc_guess(entry_guess->text_080_guess);
                    list_198_guess->SetItemText(index_guess, 2, desc_guess);
                }
                list_198_guess->SetCell_guess(index_guess, 2, 0xffff0000);
            }
        }
    }
}

// While shown, refreshes the timer list once a minute (client time is in seconds).
// FUNCTION: TITANIUM 0x004FE9E9
int PanelOwner_guess::OnProcessFrame_guess() {
    if (((CSidlScreenWnd*)this)->Show != 0) {
        int now_guess = GetClientTime_guess();
        if (now_guess - lastUpdateTick_19c_guess >= 60) {
            lastUpdateTick_19c_guess = now_guess;
            Update_4FE0FD_guess();
        }
    }
    return ((CSidlScreenWnd*)this)->OnProcessFrame();
}

// Expedition window: redraws the lockout timer list (0x004FE0FD) when the window is shown. Called after
// OP_DzExpeditionLockoutTimers replaces the timers.
// FUNCTION: TITANIUM 0x004FEA17
void PanelOwner_guess::UpdateIfShown_4FE0FD_guess() {
    if (((CSidlScreenWnd*)this)->Show) {
        Update_4FE0FD_guess();
    }
}

struct CurrentModeOwner_guess {
    // EXTERNAL: TITANIUM 0x00446B4C CurrentModeOwner_guess::Get_guess
    int Get_guess();
    // EXTERNAL: TITANIUM 0x004463F0 CurrentModeOwner_guess::Matches_guess
    bool Matches_guess(const char* text_guess);
};

#define g_currentModeOwner_guess EQ_GLOBAL(CurrentModeOwner_guess, 0x009231C8)

// Leader only, for the name in DZ_Leader_TargetValue: a member (0x4463F0) enables Remove and
// MakeLeader, anyone else Add; your own name enables nothing.
// FUNCTION: TITANIUM 0x004FEA23
void PanelOwner_guess::Update_4FEA23_guess() {
    char state_184_guess;
    char state_18c_guess;
    char state_180_guess;
    state_184_guess = 0;
    state_180_guess = 0;
    state_18c_guess = 0;

    if (leaderTargetValue_0174_guess != 0) {
        CurrentModeOwner_guess* owner_guess = &g_currentModeOwner_guess;
        if (NameMatch_guess((int)owner_guess)) {
            CXStr text_guess = leaderTargetValue_0174_guess->GetText_guess();
            int length_guess = text_guess.Ptr != 0 ? text_guess.Ptr->length : 0;
            if (length_guess > 0) {
                char* name_guess = text_guess;
                if (name_guess != 0) {
                    GlobalState_guess* global_guess = EQ_GLOBAL(GlobalState_guess*, 0x00905D00);
                    if (global_guess == 0 || global_guess->pSpawn_c288_guess == 0 ||
                        __stricmp(global_guess->pSpawn_c288_guess->text, name_guess) != 0) {
                        if (owner_guess->Matches_guess(name_guess)) {
                            state_184_guess = 1;
                            state_18c_guess = 1;
                        } else {
                            state_180_guess = 1;
                        }
                    }
                }
            }
        }
    }

    if (leaderAdd_0180_guess != 0) {
        leaderAdd_0180_guess->state_05d_guess = state_180_guess;
    }
    if (leaderMakeLeader_018c_guess != 0) {
        leaderMakeLeader_018c_guess->state_05d_guess = state_18c_guess;
    }
    if (leaderRemove_0184_guess != 0) {
        leaderRemove_0184_guess->state_05d_guess = state_184_guess;
    }
}

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess();
};

// EXTERNAL: TITANIUM 0x006538F0 ??_7Target_guess@@6B@
struct Target_guess {
    virtual ~Target_guess();
    char pad[0x158];
    char childStorage_guess[0x10];
    Target_guess* ScalarDeletingDestructor_guess(unsigned char flags);
};

// Destructor of the zone-choice (switch list) window (vtable 0x6538F0): destroys its choice table
// (+0x15C, 0x00446DB3), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004FEC5F
Target_guess::~Target_guess() {
    ((Child_guess*)childStorage_guess)->Child_guess::~Child_guess();
    ((Base_guess*)this)->Base_guess::~Base_guess();
}

// EXTERNAL: TITANIUM 0x006538F0 ??_7SwitchListWnd_guess@@6B@
struct SwitchListWnd_guess : CSidlScreenWndBase {
    Child_guess table_15c_guess;
    CXWnd* list_16c_guess;
    CXWnd* ok_170_guess;
    CXWnd* cancel_174_guess;
    SwitchListWnd_guess(CXWnd* parent_guess);
};

// The zone-choice list a dynamic zone offers (DZSwitchList_List, OK, Cancel); the table has 50 buckets.
// FUNCTION: TITANIUM 0x004FEB25
SwitchListWnd_guess::SwitchListWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "DynamicZoneSwitchListWnd"), table_15c_guess(0x32) {
    list_16c_guess = 0;
    ok_170_guess = 0;
    cancel_174_guess = 0;

    if (((CSidlScreenWnd*)this)->SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        list_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("DZSwitchList_List");
        ok_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("DZSwitchList_OK");
        cancel_174_guess = ((CSidlScreenWnd*)this)->GetChildItem("DZSwitchList_Cancel");
    }
}

// Fills DZSwitchList_List from the zone-choice table: the kind, two texts, and the key as row data.
// FUNCTION: TITANIUM 0x004FEC7B
void EventOwner_guess::Walk_guess(HashTable_guess* table_guess) {
    Dispatch_guess();
    if (table_guess != 0 && listener != 0) {
        for (HashEntry_guess* entry_guess = table_guess->First_guess(); entry_guess != 0;
             entry_guess = table_guess->Next_guess(entry_guess)) {
            helper.Insert_guess(entry_guess, entry_guess->field_000_guess);
            int index_guess = listener->AddString(GetTextById_guess(entry_guess->field_008_guess),
                                                   -1, 0, 0);
            listener->SetItemText(index_guess, 1, entry_guess->text_010_guess);
            listener->SetItemText(index_guess, 2, entry_guess->text_090_guess);
            listener->SetItemData(index_guess, entry_guess->field_000_guess);
        }
    }
}

// Zone-choice notifications: OK sends the choice and closes, Cancel only closes; notification 4
// (probably a double click) sends and closes.
// FUNCTION: TITANIUM 0x004FEDB5
void MessageCallback_guess::Dispatch_guess(int key_guess, int type_guess, int value_guess) {
    if (type_guess == 1) {
        if (key_guess == field_174_guess) {
            Slot48_guess(0, 1);
        } else if (key_guess == field_170_guess) {
            ((MessageOwner_guess*)this)->SendChooseZoneReply_guess();
            Slot48_guess(0, 1);
        }
    } else if (type_guess == 4) {
        ((MessageOwner_guess*)this)->SendChooseZoneReply_guess();
        Slot48_guess(0, 1);
    }
    WndNotification(key_guess, type_guess, value_guess);
}

struct TextMessagePacket_guess {
    int unused_guess;
    char text_guess[0x40];
};

struct RefreshTextOwner_guess {
    char first_guess;
    // EXTERNAL: TITANIUM 0x004C13D7 RefreshTextOwner_guess::Cancel_guess
    void Cancel_guess();
};

#define g_refreshTextOwner_guess EQ_GLOBAL(RefreshTextOwner_guess*, 0x00985C88)

// EXTERNAL: TITANIUM 0x0060D750 _memset
void* __cdecl _memset(void* destination_guess, int value_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060E620 _strncpy
char* __cdecl _strncpy(char* destination_guess, char* source_guess, unsigned int size_guess);

// DZ_Quit asks first (dialog 0x486D, string 0xDD3). The +0x190 button sends 0x1728 (no EQEmu name)
// with a value from 0x9231C8. Add, Remove and MakeLeader send the name in DZ_Leader_TargetValue
// (OP_DzAddPlayer, OP_DzRemovePlayer, OP_DzMakeLeader: 64-byte name). A click on a member copies its name.
// FUNCTION: TITANIUM 0x004FEE04
int PanelOwner_guess::WndNotification(CXWnd* sender_guess, unsigned int message_guess,
                                      void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == (CXWnd*)quit_0188_guess) {
            char* title_guess = pStringTable->getString(0xdd3, 0);
            pConfirmationDialogPool_guess->Activate(
                (WindowBase1_guess*)this, 0x486d, title_guess, 0xc, -1, 0, 1);
        } else if (sender_guess == (CXWnd*)first_guess) {
            RefreshTextOwner_guess* refresh_guess = g_refreshTextOwner_guess;
            if (refresh_guess != 0) {
                if (refresh_guess->first_guess != 0) {
                    refresh_guess->Cancel_guess();
                } else {
                    int current_guess = g_currentModeOwner_guess.Get_guess();
                    EQSendMessage(&g_voidConnection_guess, 0x1728, &current_guess, 4, 1);
                    first_guess->Apply_guess(0, 1);
                    if (second_guess != 0) {
                        second_guess->Apply_guess(1, 1);
                    }
                }
            }
        } else if (sender_guess == (CXWnd*)second_guess) {
            RefreshTextOwner_guess* refresh_guess = g_refreshTextOwner_guess;
            if (refresh_guess != 0) {
                if (refresh_guess->first_guess != 0) {
                    refresh_guess->Cancel_guess();
                    second_guess->Apply_guess(0, 1);
                    if (first_guess != 0) {
                        first_guess->Apply_guess(1, 1);
                    }
                }
            }
        } else if (sender_guess == (CXWnd*)leaderAdd_0180_guess) {
            if (leaderTargetValue_0174_guess != 0) {
                CXStr text_guess = leaderTargetValue_0174_guess->GetText_guess();
                char* source_guess = text_guess;
                if (source_guess != 0) {
                    TextMessagePacket_guess packet_guess;
                    _memset(packet_guess.text_guess, 0, 0x40);
                    _strncpy(packet_guess.text_guess, source_guess, 0x3f);
                    EQSendMessage(&g_voidConnection_guess, OP_DzAddPlayer, &packet_guess, 0x44, 1);
                }
            }
        } else if (sender_guess == (CXWnd*)leaderRemove_0184_guess) {
            if (leaderTargetValue_0174_guess != 0) {
                CXStr text_guess = leaderTargetValue_0174_guess->GetText_guess();
                char* source_guess = text_guess;
                if (source_guess != 0) {
                    TextMessagePacket_guess packet_guess;
                    _memset(packet_guess.text_guess, 0, 0x40);
                    _strncpy(packet_guess.text_guess, source_guess, 0x3f);
                    EQSendMessage(&g_voidConnection_guess, OP_DzRemovePlayer, &packet_guess, 0x44, 1);
                }
            }
        } else if (sender_guess == (CXWnd*)leaderMakeLeader_018c_guess) {
            if (leaderTargetValue_0174_guess != 0) {
                CXStr text_guess = leaderTargetValue_0174_guess->GetText_guess();
                char* source_guess = text_guess;
                if (source_guess != 0) {
                    TextMessagePacket_guess packet_guess;
                    _memset(packet_guess.text_guess, 0, 0x40);
                    _strncpy(packet_guess.text_guess, source_guess, 0x3f);
                    EQSendMessage(&g_voidConnection_guess, OP_DzMakeLeader, &packet_guess, 0x44, 1);
                }
            }
        } else if (sender_guess == (CXWnd*)list_168_guess) {
            if (list_168_guess->GetCurSel() >= 0 && leaderTargetValue_0174_guess != 0) {
                CXStr text_guess = list_168_guess->GetItemText(list_168_guess->GetCurSel(), 0);
                leaderTargetValue_0174_guess->Slot63_guess(&text_guess);
                Update_4FEA23_guess();
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}

// Enables or disables the leader controls; enabling refreshes them when you lead, disabling clears the
// target name.
// FUNCTION: TITANIUM 0x004FF146
void PanelOwner_guess::Update_4FF146_guess(char flag_guess) {
    if (leaderTarget_0170_guess != 0) {
        leaderTarget_0170_guess->state_05d_guess = flag_guess;
    }
    if (leaderTargetValue_0174_guess != 0) {
        leaderTargetValue_0174_guess->state_05d_guess = flag_guess;
    }
    if (leaderAdd_0180_guess != 0) {
        leaderAdd_0180_guess->state_05d_guess = flag_guess;
    }
    if (leaderRemove_0184_guess != 0) {
        leaderRemove_0184_guess->state_05d_guess = flag_guess;
    }
    if (leaderMakeLeader_018c_guess != 0) {
        leaderMakeLeader_018c_guess->state_05d_guess = flag_guess;
    }
    if (flag_guess != 0) {
        if (NameMatch_guess((int)EQ_ARRAY(char, 0x009231C8))) {
            Update_4FE3E3_guess();
            Update_4FEA23_guess();
        }
    } else if (leaderTargetValue_0174_guess != 0) {
        CXStr text_guess;
        leaderTargetValue_0174_guess->Slot63_guess(&text_guess);
    }
}

// Scalar deleting destructor of the zone-choice (switch list) window (vtable 0x6538F0 slot 1): destroys
// it and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004FF200
Target_guess* Target_guess::ScalarDeletingDestructor_guess(unsigned char flags) {
    this->Target_guess::~Target_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

struct NumericText_guess {
    CStrRep* rep_guess;
    // EXTERNAL: TITANIUM 0x005724C0 NumericText_guess::NumericText_guess
    NumericText_guess(int value_guess, int flags_guess, int capacity_guess);
    ~NumericText_guess() {
        if (rep_guess != 0) {
            ((CXStr*)this)->FreeRep(rep_guess);
        }
        rep_guess = 0;
    }
};

struct ColoredList_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059B3E0 ColoredList_guess::SetItemColor_guess
    void SetItemColor_guess(int index_guess, int column_guess, unsigned long color_guess);
};

struct StatusNode_guess {
    char name_guess[0x40];
    int state_guess;
    StatusNode_guess* next_guess;
};

// Redraws the expedition: leader, zone name, the members with their status, the member count and the
// maximum (0x9232D4).
// FUNCTION: TITANIUM 0x004FF21C
// @early-stop: budget, structural ndiff=137
void PanelOwner_guess::Update_4FF21C_guess() {
    if (leaderValue_0164_guess != 0) {
        CXStr text_guess(EQ_ARRAY(char, 0x00923212));
        ((Panel_guess*)leaderValue_0164_guess)->Slot63_guess(&text_guess);
    }

    if (NameMatch_guess((int)EQ_ARRAY(char, 0x009231C8))) {
        Update_4FF11E_guess();
    } else {
        Update_4FF146_guess(0);
    }

    if (quit_0188_guess != 0) {
        quit_0188_guess->state_05d_guess = g_refreshMode_guess;
    }
    Refresh_guess();

    if (currentDZValue_0160_guess != 0) {
        CXStr text_guess(EQ_ARRAY(char, 0x00923252));
        ((Panel_guess*)currentDZValue_0160_guess)->Slot63_guess(&text_guess);
    }

    int rowCount_guess = 0;
    if (list_168_guess != 0) {
        ((Listener_guess*)list_168_guess)->Slot76_guess();

        for (StatusNode_guess* node_guess = EQ_GLOBAL(StatusNode_guess*, 0x009232D8);
             node_guess != 0; node_guess = node_guess->next_guess) {
            CXStr rowName_guess(node_guess->name_guess);
            // Member status: 1 online, 2 offline, 3 in the dynamic zone, 4 link dead.
            CXStr stateText_guess("unknown");
            unsigned long color_guess = 0xffffff00;

            if (node_guess->state_guess == 2) {
                stateText_guess = "Offline";
                color_guess = 0xff0000ff;
            } else if (node_guess->state_guess == 3) {
                stateText_guess = "In Dynamic Zone";
                color_guess = 0xff00ff00;
            } else if (node_guess->state_guess == 1) {
                stateText_guess = "Online";
                color_guess = 0xffffff00;
            } else if (node_guess->state_guess == 4) {
                stateText_guess = "Link Dead";
                color_guess = 0xffff0000;
            }

            int index_guess = list_168_guess->AddString(rowName_guess, color_guess, 0, 0);
            ((ColoredList_guess*)list_168_guess)->SetItemColor_guess(index_guess, 0, color_guess);
            list_168_guess->SetItemText(index_guess, 1, stateText_guess);
            ((ColoredList_guess*)list_168_guess)->SetItemColor_guess(index_guess, 1, color_guess);
            ++rowCount_guess;
        }
    }

    CXStr emptyText_guess;
    if (numPlayersValue_0178_guess != 0) {
        if (rowCount_guess < 1) {
            numPlayersValue_0178_guess->Slot63_guess(&emptyText_guess);
        } else {
            NumericText_guess countText_guess(rowCount_guess, -1, 0x20);
            numPlayersValue_0178_guess->Slot63_guess((CXStr*)&countText_guess);
        }
    }

    if (maxPlayersValue_017c_guess != 0) {
        int totalCount_guess = EQ_GLOBAL(int, 0x009232D4);
        if (totalCount_guess < 1) {
            maxPlayersValue_017c_guess->Slot63_guess(&emptyText_guess);
        } else {
            NumericText_guess countText_guess(totalCount_guess, -1, 0x20);
            maxPlayersValue_017c_guess->Slot63_guess((CXStr*)&countText_guess);
        }
    }
}

// Full refresh: leader controls, members and timers. Always returns true.
// FUNCTION: TITANIUM 0x004FF526
bool PanelOwner_guess::Update_4FF526_guess() {
    Update_4FF146_guess(NameMatch_guess((int)EQ_ARRAY(char, 0x009231C8)));
    Update_4FF21C_guess();
    Update_4FE0FD_guess();
    return true;
}

// Expedition window: redraws leader, zone, members and counts (0x004FF21C) when the window is shown.
// The expedition info, leader, member list, member status and member name handlers call it.
// FUNCTION: TITANIUM 0x004FF54D
void PanelOwner_guess::UpdateIfShown_4FF21C_guess() {
    if (((CSidlScreenWnd*)this)->Show) {
        Update_4FF21C_guess();
    }
}

struct EditControl_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x004D7EBC EditControl_guess::SetMaxChars_guess
    void SetMaxChars_guess(int count_guess);
};


// EXTERNAL: TITANIUM 0x00653B00 ??_7EditLabelWnd_guess@@6B@
struct EditLabelWnd_guess : CSidlScreenWndBase {
    int field_15c_guess;
    int color_160_guess;
    int field_164_guess;
    EditControl_guess* textEdit_168_guess;
    CButtonWnd* chooseColor_16c_guess;
    CButtonWnd* large_170_guess;
    CButtonWnd* medium_174_guess;
    CButtonWnd* small_178_guess;
    CButtonWnd* cancel_17c_guess;
    CButtonWnd* done_180_guess;

    EditLabelWnd_guess(CXWnd* parent_guess);
};

// CEditLabelWnd, the map's label editor: text of up to 255 characters, a colour (opaque black to
// start) and Large, Medium or Small size (Small checked).
// FUNCTION: TITANIUM 0x004FF559
EditLabelWnd_guess::EditLabelWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "EditLabelWnd", -1, 1, 0) {
    field_15c_guess = 0;
    field_164_guess = 1;
    color_160_guess = (int)0xff000000;
    textEdit_168_guess = 0;
    chooseColor_16c_guess = 0;
    large_170_guess = 0;
    medium_174_guess = 0;
    small_178_guess = 0;
    cancel_17c_guess = 0;
    done_180_guess = 0;

    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        textEdit_168_guess = (EditControl_guess*)((CSidlScreenWnd*)this)->GetChildItem("ELW_LabelTextEditbox");
        textEdit_168_guess->SetMaxChars_guess(0xff);
        chooseColor_16c_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_ChooseColorButton");
        large_170_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_LabelLargeButton");
        if (large_170_guess != 0) {
            large_170_guess->SetCheck(false);
        }
        medium_174_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_LabelMediumButton");
        if (medium_174_guess != 0) {
            medium_174_guess->SetCheck(false);
        }
        small_178_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_LabelSmallButton");
        if (small_178_guess != 0) {
            small_178_guess->SetCheck(true);
        }
        cancel_17c_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_CancelButton");
        done_180_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("ELW_DoneButton");
    }
}

// Expedition window: when shown and you lead the expedition (0x004FE558), refreshes the target name
// field (0x004FE3E3) and the leader buttons (0x004FEA23). Called by character upkeep when the target
// changes, by expedition member changes and from the full redraw.
// FUNCTION: TITANIUM 0x004FF11E
void PanelOwner_guess::Update_4FF11E_guess() {
    if (((CSidlScreenWnd*)this)->Show) {
        if (NameMatch_guess((int)EQ_ARRAY(char, 0x009231C8))) {
            Update_4FE3E3_guess();
            Update_4FEA23_guess();
        }
    }
}
