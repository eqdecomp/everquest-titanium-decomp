// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 77: a hint from compare/tumap.py.
// Three pieces. The position history (PositionHistory_guess, global 0x985C1C) that tu_055 sends as message
// 0x6A1B. OP_MoveMultipleItems: item moves between ItemLocation_guess (kind, slot, bag index, mode) records,
// taken, placed, rolled back and sent here; ItemInstance_guess and view here are item instances (misnamed).
// Then the net-status overlay and the npct.ini / itmt.ini tint tables.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"

struct QueueError_guess {
    char code_guess;
};

struct QueueSource_guess {
    char unknown00_guess[0xb54];
    int fieldB54_guess;
};

struct SoundState_guess {
    char unknown00_guess[0x244];
    unsigned char field244_guess;
    // EXTERNAL: TITANIUM 0x00489A32 SoundState_guess::GetFloat_guess
    float GetFloat_guess();
};

struct SoundPosition_guess {
    int x_guess;
    int y_guess;
    float z_guess;
};

#define g_queueSource_guess EQ_GLOBAL(QueueSource_guess*, 0x00988DF0)
#define g_queueGate_guess EQ_GLOBAL(int, 0x00905C98)
#define g_soundState_guess EQ_GLOBAL(SoundState_guess*, 0x00905CE4)
#define g_sampleQueue_guess EQ_GLOBAL(PositionHistory_guess*, 0x00985C1C)

struct R_guess {
    int a_guess;
    int b_guess;
    int c_guess;
    int d_guess;
    int e_guess;
    R_guess() : a_guess(0), b_guess(-1), c_guess(-1), d_guess(0) {}
};

struct T2_guess {
    R_guess r0_guess;
    int a14_guess;
    int b18_guess;
    int c1c_guess;
    int d20_guess;
    int e24_guess;
    T2_guess();
};

struct T3_guess : T2_guess {
    int a28_guess;
    int b2c_guess;
    int c30_guess;
    int d34_guess;
    T3_guess();
};

struct Result_guess {
    char unknown00_guess[0x1c];
    int value_guess;
};

struct Owner_guess {
    char unknown00_guess[0x10];
    Result_guess* result_guess;
    bool IsEmpty_guess();
    int GetValue_guess();
};

struct List_guess;

struct Node_guess {
    Node_guess* field00_guess;
    Node_guess* field04_guess;
    List_guess* owner_guess;
    // EXTERNAL: TITANIUM 0x004055CE Node_guess::Clear_guess
    void Clear_guess();
};

struct List_guess {
    Node_guess* first_guess;
    Node_guess* last_guess;
    void Remove_guess(Node_guess* node_guess);
    Node_guess* RemoveFirst_guess();
    // EXTERNAL: TITANIUM 0x00405B38 List_guess::Attach_guess
    void Attach_guess(Node_guess* node_guess);
};

struct Queue_guess {
    Node_guess* first_guess;
    Node_guess* last_guess;
    int growth_guess;
    int count_guess;
    Queue_guess(int amount_guess, int growth_guess);
    Node_guess* Pop_guess();
    // EXTERNAL: TITANIUM 0x00405B38 Queue_guess::Attach_guess
    void Attach_guess(Node_guess* node_guess);
    void Add_guess(Node_guess* node_guess);
    void Grow_guess(int amount_guess);
};

struct Record_guess;

struct PositionHistory_guess : Queue_guess {
    Node_guess* pendingFirst_guess;
    Node_guess* pendingLast_guess;
    unsigned short pushCount_0018_guess;
    unsigned short sequenceBase_001a_guess;
    char field1C_guess;
    char unknown1D_guess[0xc];
    char field29_guess;
    PositionHistory_guess();
    void Clear_guess();
    void Push_guess(SoundPosition_guess* position_guess, int flags_guess);
    int BuildMessage_guess(Record_guess* records_guess, char force_guess);
};

struct Array_guess {
    int* data_guess;
    int count_guess;
    // EXTERNAL: TITANIUM 0x004B903D Array_guess::Array_guess
    Array_guess();
    void Free_guess();
    int* Get_guess(int index_guess);
    void FreeThunk_guess();
    Array_guess* Load_guess(char* source_guess);
    Array_guess* LoadNpc_guess();
    Array_guess* LoadItem_guess();
};

struct ItemArray_guess {
    int* data_guess;
    int count_guess;
    // EXTERNAL: TITANIUM 0x004B904E ItemArray_guess::ItemArray_guess
    ItemArray_guess();
};

struct ValueWord_guess {
    union {
        int value_guess;
        struct {
            unsigned char byte00_guess[3];
            unsigned char flag_guess;
        } bytes_guess;
    };
};

struct TextParser_guess {
    char unknown00_guess[0x10];
    // EXTERNAL: TITANIUM 0x005764E0 TextParser_guess::TextParser_guess
    TextParser_guess(char* source_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x005761D0 TextParser_guess::~TextParser_guess
    ~TextParser_guess();
    // EXTERNAL: TITANIUM 0x00575070 TextParser_guess::Get_guess
    int Get_guess(const char* name_guess, int flags_guess, void* table_guess);
};

struct State_guess {
    int field00_guess;
    int field04_guess;
    char IsWornSlot_guess();
};

struct Condition_guess {
    int field00_guess;
    char unknown04_guess[8];
    int field0C_guess;
    int GetFirstAutoSlot_guess();
};

struct Triple_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0C_guess;
    int IsEqual_guess(Triple_guess* other_guess);
};

struct Row4_guess {
    int v_guess[4];
};

struct SelectionRow_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0C_guess;
    int value_guess;
};

struct Lookup_guess {
    int count_guess;
    int unknown04_guess;
    int mask_guess;
    int shift_guess;
    int* table_guess;
    int Get_guess(int value_guess);
};

struct Row9_guess {
    int v_guess[9];
};

struct Row14_guess {
    int v_guess[14];
};

struct Table_guess : Lookup_guess {
    int field14_guess;
    char flag18_guess;
    // EXTERNAL: TITANIUM 0x0047C3AF Table_guess::Table_guess
    Table_guess(int growth_guess);
    ~Table_guess();
    void Grow_guess(int amount_guess);
    // EXTERNAL: TITANIUM 0x0051DA09 Table_guess::RoundUp_guess
    int RoundUp_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00405492 Table_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    void GrowWide_guess(int amount_guess);
    void Set_guess(int index_guess, const int* values_guess);
    void SetWide_guess(int index_guess, const int* values_guess);
};

struct Service_guess {
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
    virtual __int64 Slot11_guess();
};

struct Context_guess {
    char unknown00_guess[0x210];
    Service_guess* service_guess;
    int Update_guess(__int64 value_guess);
};

struct Scope_guess {
    // EXTERNAL: TITANIUM 0x005E49A0 Scope_guess::Enter_guess
    void Enter_guess();
    // EXTERNAL: TITANIUM 0x005E49B0 Scope_guess::Leave_guess
    void Leave_guess();
};

struct ScopeProxy_guess {
    Scope_guess* scope_guess;
    ScopeProxy_guess(Scope_guess* scope_guess)
        : scope_guess(scope_guess) { scope_guess->Enter_guess(); }
    ~ScopeProxy_guess() { scope_guess->Leave_guess(); }
};

struct RequestStats_guess {
    unsigned __int64 first_guess;
    unsigned __int64 second_guess;
    int unknown10_guess[24];
    int milliseconds_guess;
    char unknown74_guess[0x38];
};

struct Request_guess {
    char unknown00_guess[0x8c];
    Context_guess* context_guess;
    char unknown90_guess[0x118];
    __int64 value_guess;
    char unknown1b0_guess[0x74];
    Scope_guess scope_guess;
    // EXTERNAL: TITANIUM 0x005E5200 Request_guess::GetStats_guess
    void GetStats_guess(RequestStats_guess* output_guess);
    int GetIdleTime_guess();
};

struct ItemInstance_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
    char unknown04_guess[0x44];
    int field48_guess;
    // EXTERNAL: TITANIUM 0x005EC760 ItemInstance_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005DFC50 ItemInstance_guess::CheckA_guess
    char CheckA_guess();
    // EXTERNAL: TITANIUM 0x005E00A0 ItemInstance_guess::CheckB_guess
    char CheckB_guess();
};

struct PointerList_guess {
    int field00_guess;
    char unknown04_guess[0xc];
    void** data_guess;
    int count_guess;
    void Clear_guess();
};

struct ItemLocationView_guess {
    int kind_guess;
    int base_guess;
    int extra_guess;
    int field0C_guess;
    void SetFromSlotId_guess(int value_guess);
    int GetSlotId_guess();
};

struct Gate_guess {
    // EXTERNAL: TITANIUM 0x005DFC40 Gate_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Gate_guess::GetLimit_guess
    int GetLimit_guess();
    // EXTERNAL: TITANIUM 0x005EC650 Gate_guess::GetByIndex_guess
    int* GetByIndex_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0F30 Gate_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Gate_guess::GetChild_guess
    Gate_guess* GetChild_guess(int index_guess);
};

struct GateArgument_guess {
    Gate_guess* gate_guess;
};

struct Kind_guess {
    int kind_guess;
    int GetSlotCount_guess();
};

struct SlotOffset_guess {
    int unknown00_guess;
    int offset_guess;
};

struct SlotCandidate_guess {
    int unknown00_guess;
    union {
        SlotOffset_guess* offset_guess;
        unsigned char embedded_guess[4];
    };
};

struct SlotTable_guess {
    // EXTERNAL: TITANIUM 0x00434777 SlotTable_guess::GetSlot_guess
    GateArgument_guess* GetSlot_guess(unsigned int index_guess);
};

struct ItemLocation_guess : Kind_guess {
    int field04_guess;
    int field08_guess;
    char IsValid_guess();
    int* Resolve_guess(GateArgument_guess* argument_guess);
    int* GetInventorySlot_guess(SlotCandidate_guess* candidate_guess);
};

struct view {
    virtual void Slot00_guess(int flag_guess);
    virtual view* Slot01_guess();
    virtual char Slot02_guess();
    virtual char Slot03_guess();
    virtual char Slot04_guess(int flag_guess);
    virtual char Slot05_guess(int value_guess, int flag_guess);
    char unknown04_guess[0x44];
    int field48_guess;
    // EXTERNAL: TITANIUM 0x005E0F30 view::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC760 view::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECD50 view::Get700_guess
    int Get700_guess();
    // EXTERNAL: TITANIUM 0x005ECD80 view::SetStackCount_guess
    void SetStackCount_guess(int value_guess);
};

struct SlotKey_guess : ItemLocation_guess {
    int type_guess;
};

struct SlotRecord_guess {
    int unknown00_guess[4];
    int field10_guess;
    SlotKey_guess key_guess;
    view* target_guess;
    int unknown28_guess[4];
};

struct Entry_guess : ItemLocation_guess {
    char unknown0C_guess[0x18];
    view* target_guess;
};

struct SlotHolder_guess {
    char unknown00_guess[0xc280];
    SlotCandidate_guess candidate_guess;
    // EXTERNAL: TITANIUM 0x004BC906 SlotHolder_guess::CanEquipItem_guess
    char CanEquipItem_guess(view* target_guess, int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x004BCE5F SlotHolder_guess::WouldDuplicateLore_guess
    int WouldDuplicateLore_guess(view* target_guess);
};

inline SlotRecord_guess* RecordAt_guess(Lookup_guess* lookup_guess, int index_guess) {
    return (SlotRecord_guess*)lookup_guess->table_guess[index_guess >> lookup_guess->shift_guess] +
        (lookup_guess->mask_guess & index_guess);
}

struct Vector3_guess {
    int x_guess;
    int y_guess;
    int z_guess;
};

struct FloatVector3_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    bool IsEqual_guess(const FloatVector3_guess* other_guess);
};

#include "titanium/layouts/math.h"

#include "titanium/core_decls.h"
struct DrawService_guess {
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
    virtual void WriteTextHD(CVector3* first_guess,
        CVector3* second_guess, unsigned int color_guess) = 0;
};

struct ColorChannels_guess {
    unsigned char blue_guess;
    unsigned char green_guess;
    unsigned char red_guess;
    unsigned char alpha_guess;
};

#define g_drawService_guess EQ_GLOBAL(DrawService_guess*, 0x0099E364)
#define g_firstColorLimit_guess EQ_GLOBAL(float, 0x006486E0)
#define g_secondColorLimit_guess EQ_GLOBAL(float, 0x00642014)
#define g_colorScale_guess EQ_GLOBAL(float, 0x006410BC)
#define g_one_guess EQ_GLOBAL(float, 0x0063F4D0)
#define g_accumulator_guess EQ_GLOBAL(int, 0x00985C20)
#define g_position_guess EQ_GLOBAL(unsigned short, 0x00985C24)
#define g_state_guess EQ_GLOBAL(unsigned int, 0x00985C28)
#define g_direction_guess EQ_GLOBAL(short, 0x0078E848)

struct Sample_guess {
    char unknown00_guess[0xc];
    Vector3_guess position_guess;
    int field18_guess;
    int time_guess;
    void Set_guess(const int* values_guess, int value_guess);
};

// EXTERNAL: TITANIUM 0x0040BCF2 SaturateDifference_guess
int __cdecl SaturateDifference_guess(__int64 first, __int64 second);

// EXTERNAL: TITANIUM 0x0046D655 Fallback_guess
int __cdecl Fallback_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* output_guess, const char* format_guess, ...);

struct Cleanup_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0C_guess;
    // EXTERNAL: TITANIUM 0x004B8F50 Cleanup_guess::~Cleanup_guess
    ~Cleanup_guess();
};

#define g_cleanupA_guess EQ_GLOBAL(Cleanup_guess*, 0x00985C50)
#define g_cleanupB_guess EQ_GLOBAL(Cleanup_guess*, 0x00985C54)

// True when all three components equal `other`'s.
// FUNCTION: TITANIUM 0x004B6DD5
bool FloatVector3_guess::IsEqual_guess(const FloatVector3_guess* other_guess) {
    return x_guess == other_guess->x_guess && y_guess == other_guess->y_guess && z_guess == other_guess->z_guess;
}

// History entry: position, type and the time stamp (Fallback_guess is the ms clock EqGetTime, tu_046).
// FUNCTION: TITANIUM 0x004B6E0E
void Sample_guess::Set_guess(const int* values_guess, int value_guess) {
    position_guess.x_guess = values_guess[0];
    position_guess.y_guess = values_guess[1];
    position_guess.z_guess = values_guess[2];
    field18_guess = value_guess;
    time_guess = Fallback_guess();
}

// True when no position-history entry is held (+0 null); movement checks it.
// FUNCTION: TITANIUM 0x004B6E39
bool Owner_guess::IsEmpty_guess() {
    return result_guess == 0;
}

// The result's time stamp (+0x1C), or now (EqGetTime) when there is no result.
// FUNCTION: TITANIUM 0x004B6E42
int Owner_guess::GetValue_guess() {
    if (result_guess == 0) {
        return Fallback_guess();
    }
    return result_guess->value_guess;
}

// Unlinks `node` from the doubly linked list, moving the head or tail past it when needed, and clears
// its links.
// FUNCTION: TITANIUM 0x004B6E52
void List_guess::Remove_guess(Node_guess* node_guess) {
    if (node_guess == first_guess) {
        first_guess = node_guess->field04_guess;
    }
    if (node_guess == last_guess) {
        last_guess = node_guess->field00_guess;
    }
    node_guess->Clear_guess();
}

// Removes and returns the first node of the list (+0 first, +4 last; last is cleared when it was the only
// node); the node's links are cleared by 0x004055CE. Null when the list is empty.
// FUNCTION: TITANIUM 0x004B6E73
Node_guess* List_guess::RemoveFirst_guess() {
    Node_guess* node_guess = first_guess;
    if (node_guess == 0) {
        return 0;
    }
    first_guess = node_guess->field04_guess;
    if (node_guess == last_guess) {
        last_guess = 0;
    }
    node_guess->Clear_guess();
    return node_guess;
}

// Returns a node to the free list, unlinking it from its current list first.
// FUNCTION: TITANIUM 0x004B6E97
void Queue_guess::Add_guess(Node_guess* node_guess) {
    if (node_guess->owner_guess != 0) {
        node_guess->owner_guess->Remove_guess(node_guess);
    }
    Attach_guess(node_guess);
    count_guess++;
}

// Adds `amount` fresh 32-byte nodes to the free list.
// FUNCTION: TITANIUM 0x004B6EBC
void Queue_guess::Grow_guess(int amount_guess) {
    if (amount_guess != 0) {
        count_guess += amount_guess;
        int remaining_guess = amount_guess;
        do {
            Node_guess* node_guess = (Node_guess*)operator new(0x20);
            if (node_guess != 0) {
                node_guess->field00_guess = 0;
                node_guess->field04_guess = 0;
                node_guess->owner_guess = 0;
            } else {
                node_guess = 0;
            }
            Attach_guess(node_guess);
            remaining_guess--;
        } while (remaining_guess != 0);
    }
}

// Moves every pending entry back to the free list. The counters are zeroed by AND-ing them with the
// loop's final (null) node: match shape, keep it.
// FUNCTION: TITANIUM 0x004B6EF8
void PositionHistory_guess::Clear_guess() {
    Node_guess* node_guess;
    while ((node_guess = ((List_guess*)&pendingFirst_guess)->RemoveFirst_guess()) != 0) {
        Add_guess(node_guess);
    }
    pushCount_0018_guess &= (unsigned short)node_guess;
    sequenceBase_001a_guess &= (unsigned short)node_guess;
}

#pragma pack(push, 1)
struct Tail_guess {
    unsigned char type_guess;
    short time_guess;
    short seq_guess;
};

struct Record_guess {
    Vector3_guess position_guess;
    unsigned char type_guess;
    short time_guess;
    short seq_guess;
};
#pragma pack(pop)

struct Pending_guess {
    char unknown00_guess[0xc];
    Vector3_guess position_guess;
    unsigned char type_guess;
    char unknown19_guess[3];
    int time_guess;
};

// Win32 import (kernel32), called by name.
unsigned long __stdcall GetTickCount();

// Packs pending entries older than 2 s (all of them with `force`) into 17-byte records, at most 10000
// written: x, y, z, type, time and a sequence number. A type-1 spot equal to the last one sent is dropped
// but still uses a number; types other than 1-5, 7 and 8 throw. Returns the byte count (17 per record + 1)
// or 0.
// FUNCTION: TITANIUM 0x004B6F1F
// @early-stop: budget, structural ndiff=113
int PositionHistory_guess::BuildMessage_guess(Record_guess* records_guess, char force_guess) {
    if (field1C_guess != 0 && pendingFirst_guess != 0) {
        int* out_guess;
        Node_guess* node_guess = pendingFirst_guess;
        unsigned int count_guess = 0;
        int seq_guess = sequenceBase_001a_guess - 1;
        sequenceBase_001a_guess = pushCount_0018_guess;
        // Entries are stamped with EqGetTime but aged against GetTickCount: two different clocks.
        unsigned long tick_guess = GetTickCount();
        out_guess = (int*)records_guess + 1;
        while (node_guess != 0) {
            if (count_guess >= 10000 || (force_guess == 0 && tick_guess - ((Pending_guess*)node_guess)->time_guess <= 0x7d0)) {
                break;
            }
            ((List_guess*)&pendingFirst_guess)->Remove_guess(node_guess);
            seq_guess++;
            ((Tail_guess*)(out_guess + 2))->type_guess = ((Pending_guess*)node_guess)->type_guess;
            ((Tail_guess*)(out_guess + 2))->time_guess = (short)((Pending_guess*)node_guess)->time_guess;
            ((Tail_guess*)(out_guess + 2))->seq_guess = (short)seq_guess;
            if (((Tail_guess*)(out_guess + 2))->type_guess == 1) {
                Vector3_guess* pos_guess = &((Pending_guess*)node_guess)->position_guess;
                out_guess[-1] = pos_guess->x_guess;
                out_guess[0] = pos_guess->y_guess;
                out_guess[1] = pos_guess->z_guess;
                if (field29_guess == 0 ||
                    !((FloatVector3_guess*)&unknown1D_guess)->IsEqual_guess((FloatVector3_guess*)pos_guess)) {
                    ((Vector3_guess*)&unknown1D_guess)->x_guess = pos_guess->x_guess;
                    ((Vector3_guess*)&unknown1D_guess)->y_guess = pos_guess->y_guess;
                    ((Vector3_guess*)&unknown1D_guess)->z_guess = pos_guess->z_guess;
                    field29_guess = 1;
                    count_guess++;
                    out_guess = (int*)((Record_guess*)(out_guess - 1) + 1) + 1;
                }
            } else {
                if (((Tail_guess*)(out_guess + 2))->type_guess != 2 && ((Tail_guess*)(out_guess + 2))->type_guess != 3 &&
                    ((Tail_guess*)(out_guess + 2))->type_guess != 4 && ((Tail_guess*)(out_guess + 2))->type_guess != 5 &&
                    ((Tail_guess*)(out_guess + 2))->type_guess != 7 && ((Tail_guess*)(out_guess + 2))->type_guess != 8) {
                    throw QueueError_guess();
                }
                out_guess[-1] = ((Pending_guess*)node_guess)->position_guess.x_guess;
                out_guess[0] = ((Pending_guess*)node_guess)->position_guess.y_guess;
                out_guess[1] = ((Pending_guess*)node_guess)->position_guess.z_guess;
                count_guess++;
                out_guess = (int*)((Record_guess*)(out_guess - 1) + 1) + 1;
            }
            Add_guess(node_guess);
            node_guess = pendingFirst_guess;
        }
        if (count_guess != 0) {
            return count_guess * 0x11 + 1;
        }
    }
    return 0;
}

// Node queue: empty, then `amount` nodes allocated up front (0x004B6EBC), refilled `growth` at a time;
// the position history uses 1000 and 100.
// FUNCTION: TITANIUM 0x004B7068
Queue_guess::Queue_guess(int amount_guess, int growth_guess) :
    first_guess(0), last_guess(0), growth_guess(growth_guess), count_guess(0) {
    Grow_guess(amount_guess);
}

// Takes a free node, refilling the pool by `growth` when it is empty; 0 when that fails.
// FUNCTION: TITANIUM 0x004B708D
Node_guess* Queue_guess::Pop_guess() {
    if (first_guess == 0) {
        Grow_guess(growth_guess);
        if (first_guess == 0) {
            return 0;
        }
    }
    Node_guess* node_guess = ((List_guess*)this)->RemoveFirst_guess();
    count_guess--;
    return node_guess;
}

// 1000 nodes up front, 100 per refill. Recording stays off until +0x1C is set elsewhere.
// FUNCTION: TITANIUM 0x004B70B2
PositionHistory_guess::PositionHistory_guess() :
    Queue_guess(1000, 100), pendingFirst_guess(0), pendingLast_guess(0),
    pushCount_0018_guess(0), sequenceBase_001a_guess(0),
    field1C_guess(0), field29_guess(0) {}

// Records a spot of type `flags`, only in game (pEverQuest +0xB54 GameState 5), while connected to a zone
// (0x905C98) and while the player's +0x244 is at most 1. Type 2 adds the model height (0x489A32).
// Callers: 2 with each OP_ClientUpdate and 3 on a direct position set (tu_055), 7 from spells (tu_012),
// 8 after the move to safe coordinates.
// FUNCTION: TITANIUM 0x004B70DB
void PositionHistory_guess::Push_guess(SoundPosition_guess* position_guess, int flags_guess) {
    if (field1C_guess == 0) {
        return;
    }
    if (g_queueSource_guess->fieldB54_guess != 5) {
        return;
    }
    if (g_queueGate_guess == 0) {
        return;
    }
    if (g_soundState_guess != 0 && g_soundState_guess->field244_guess > 1) {
        return;
    }
    Node_guess* node_guess = Pop_guess();
    if (node_guess == 0) {
        throw QueueError_guess();
    }
    SoundPosition_guess local_guess;
    local_guess.x_guess = position_guess->x_guess;
    local_guess.y_guess = position_guess->y_guess;
    local_guess.z_guess = position_guess->z_guess;
    if (flags_guess == 2) {
        local_guess.z_guess = g_soundState_guess->GetFloat_guess() + local_guess.z_guess;
    }
    ((Sample_guess*)node_guess)->Set_guess((const int*)&local_guess, flags_guess);
    ((List_guess*)&pendingFirst_guess)->Attach_guess(node_guess);
    pushCount_0018_guess++;
}

// The position history singleton (0x985C1C), created on first use.
// FUNCTION: TITANIUM 0x004B718D
PositionHistory_guess* __cdecl GetSampleQueue_guess() {
    if (g_sampleQueue_guess == 0) {
        g_sampleQueue_guess = new PositionHistory_guess;
        if (g_sampleQueue_guess == 0) {
            throw QueueError_guess();
        }
    }
    return g_sampleQueue_guess;
}

// Same location: kind, slot and bag index; the mode (+0x0C) is ignored.
// FUNCTION: TITANIUM 0x004B71F1
int Triple_guess::IsEqual_guess(Triple_guess* other_guess) {
    if (field00_guess == other_guess->field00_guess &&
        field04_guess == other_guess->field04_guess &&
        field08_guess == other_guess->field08_guess) {
        return true;
    }
    return false;
}

// Splits a Titanium slot id into (kind, slot, bag index): 0-1999 possessions, 2000 bank, 2500 shared bank,
// 3000 trade, 4000 world, 10000-10035 kind 5. Ids from 31 up within a range are bag slots: (id - 31) / 10
// is the bag's slot and the remainder the index (251 = slot 22, index 0). Anything else: kind 0, -1, -1.
// FUNCTION: TITANIUM 0x004B7215
// @early-stop: budget, diff ndiff=1
void ItemLocationView_guess::SetFromSlotId_guess(int value_guess) {
    field0C_guess = 0;
    if (value_guess >= 0 && value_guess < 2000) {
        kind_guess = 0;
    } else if (value_guess >= 2000 && value_guess < 2500) {
        value_guess -= 2000;
        kind_guess = 1;
    } else if (value_guess >= 2500 && value_guess < 3000) {
        kind_guess = 2;
        value_guess -= 2500;
    } else if (value_guess >= 3000 && value_guess < 4000) {
        value_guess -= 3000;
        kind_guess = 3;
    } else if (value_guess >= 4000 && value_guess < 5000) {
        kind_guess = 4;
        value_guess -= 4000;
    } else if (value_guess >= 10000 && value_guess < 10036) {
        kind_guess = 5;
        value_guess -= 10000;
    } else {
        kind_guess = 0;
        base_guess = -1;
        extra_guess = -1;
        return;
    }
    if (value_guess < 31) {
        base_guess = value_guess;
        extra_guess = -1;
    } else {
        value_guess += -31;
        base_guess = value_guess / 10;
        extra_guess = value_guess % 10;
    }
}

// The inverse: (kind, slot, bag index) back to the flat slot id.
// FUNCTION: TITANIUM 0x004B72D7
int ItemLocationView_guess::GetSlotId_guess() {
    int value_guess = base_guess;
    if (extra_guess >= 0) {
        value_guess = extra_guess + 0x1f + value_guess * 10;
    }
    switch (kind_guess) {
    case 1:
        return value_guess + 2000;
    case 2:
        return value_guess + 2500;
    case 3:
        return value_guess + 3000;
    case 4:
        return value_guess + 4000;
    case 5:
        return value_guess + 10000;
    }
    return value_guess;
}

// Slot pointer for this location in `argument`: the slot itself when there is no bag index (-1), else
// slot `index` inside the bag there (IsReady_guess: a container; GetLimit_guess: its size); 0 if none.
// FUNCTION: TITANIUM 0x004B7317
int* ItemLocation_guess::Resolve_guess(GateArgument_guess* argument_guess) {
    if (field08_guess < 0) {
        return (int*)argument_guess;
    }
    if (argument_guess != 0 && argument_guess->gate_guess != 0 &&
        argument_guess->gate_guess->IsReady_guess() != 0) {
        if (argument_guess->gate_guess->GetLimit_guess() > field08_guess) {
            return argument_guess->gate_guess->GetByIndex_guess(field08_guess);
        }
    }
    return 0;
}

// First slot an auto-placed item may take: 22 (general inventory) for possessions with mode 2, else 0.
// FUNCTION: TITANIUM 0x004B735D
int Condition_guess::GetFirstAutoSlot_guess() {
    if (field00_guess == 0 && field0C_guess == 2) {
        return 0x16;
    }
    return 0;
}

// Slot count of a location kind: possessions 31 (0-30, cursor last), bank 16, shared bank 2, trade 16,
// world 16, kind 5 36.
// FUNCTION: TITANIUM 0x004B736F
int Kind_guess::GetSlotCount_guess() {
    switch (kind_guess) {
    case 0:
        return 0x1f;
    case 1:
        return 0x10;
    case 2:
        return 2;
    case 3:
        return 0x10;
    case 4:
        return 0x10;
    case 5:
        return 0x24;
    }
    return 0;
}

// Worn slot: possessions slot 0-21 (charm to ammo).
// FUNCTION: TITANIUM 0x004B7398
char State_guess::IsWornSlot_guess() {
    if (field00_guess == 0 && field04_guess <= 0x15) {
        return 1;
    }
    return 0;
}

// Item filter for FindItemsById_guess: flag bits 1, 2 and 4 each demand one item test (vtable slot 4,
// 0x5DFC50, 0x5E00A0).
// FUNCTION: TITANIUM 0x004B73A9
char __cdecl MatchesItemFilter_guess(ItemInstance_guess* object_guess, unsigned char flags_guess) {
    if ((flags_guess & 1) != 0 && object_guess->Slot04_guess(0) == 0) {
        return 0;
    }
    if ((flags_guess & 2) != 0 && object_guess->CheckA_guess() == 0) {
        return 0;
    }
    if ((flags_guess & 4) != 0 && object_guess->CheckB_guess() == 0) {
        return 0;
    }
    return 1;
}

// Frees every page and the page table of an ArrayClass2 (tu_053) and empties it.
// FUNCTION: TITANIUM 0x004B73EE
void PointerList_guess::Clear_guess() {
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            _free(data_guess[index_guess]);
            index_guess++;
        } while (index_guess < count_guess);
    }
    _free(data_guess);
    data_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Valid location: bag index at most 10, slot inside the kind's count, and no bag index on a worn slot.
// FUNCTION: TITANIUM 0x004B7422
char ItemLocation_guess::IsValid_guess() {
    int index_guess = field08_guess;
    if (index_guess <= 0xa && field04_guess >= 0) {
        if (GetSlotCount_guess() > field04_guess &&
            (kind_guess != 0 || field04_guess > 0x15 || index_guess < 0)) {
            return 1;
        }
    }
    return 0;
}

// Empty item location at +0x14: kind 0, slot -1, bag index -1, mode 0.
// FUNCTION: TITANIUM 0x004B7451
T2_guess::T2_guess() : a14_guess(0), b18_guess(-1), c1c_guess(-1), d20_guess(0) {}

// Empty item location at +0x28: kind 0, slot -1, bag index -1, mode 0.
// FUNCTION: TITANIUM 0x004B7470
T3_guess::T3_guess() : a28_guess(0), b2c_guess(-1), c30_guess(-1), d34_guess(0) {}

// Row `value` of an ArrayClass2 of 36-byte wire move records.
// FUNCTION: TITANIUM 0x004B748C
int Lookup_guess::Get_guess(int value_guess) {
    return table_guess[value_guess >> shift_guess] + (mask_guess & value_guess) * 0x24;
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

struct Cell_guess {
    R_guess r0_guess;
    int a14_guess;
    int b18_guess;
    int c1c_guess;
    int d20_guess;
    // EXTERNAL: TITANIUM 0x004B7451 Cell_guess::Cell_guess
    Cell_guess();
};

// ArrayClass2 growth for 36-byte rows: adds pages up to `wanted` (rounded up). On an allocation failure it
// empties the old array and calls Fail_guess, which does not return; the half-built new table and its new
// pages leak.
// FUNCTION: TITANIUM 0x004B74AD
// @early-stop: budget, diff ndiff=1
void Table_guess::Grow_guess(int wanted_guess) {
    if (flag18_guess == 0 || wanted_guess <= 0) {
        return;
    }
    wanted_guess = RoundUp_guess(wanted_guess);
    if (wanted_guess > field14_guess) {
        Cell_guess** newBlocks_guess = new Cell_guess*[wanted_guess];
        if (newBlocks_guess == 0) {
            flag18_guess = 0;
        } else {
            for (int i_guess = 0; i_guess < field14_guess; i_guess++) {
                newBlocks_guess[i_guess] = ((Cell_guess**)table_guess)[i_guess];
            }
            int index_guess = field14_guess;
            if (index_guess < wanted_guess) {
                do {
                    Cell_guess* block_guess = new Cell_guess[unknown04_guess];
                    newBlocks_guess[index_guess] = block_guess;
                    if (block_guess == 0) {
                        flag18_guess = 0;
                        break;
                    }
                    index_guess++;
                } while (index_guess < wanted_guess);
            }
            if (flag18_guess != 0) {
                _free(table_guess);
                table_guess = (int*)newBlocks_guess;
                field14_guess = wanted_guess;
            }
        }
    }
    if (flag18_guess == 0) {
        ((PointerList_guess*)this)->Clear_guess();
        Fail_guess();
    }
}

// The same for the 56-byte working rows (T3_guess).
// FUNCTION: TITANIUM 0x004B75AA
// @early-stop: compiler-generated, diff ndiff=1
void Table_guess::GrowWide_guess(int wanted_guess) {
    if (flag18_guess == 0 || wanted_guess <= 0) {
        return;
    }
    wanted_guess = RoundUp_guess(wanted_guess);
    if (wanted_guess > field14_guess) {
        T3_guess** newBlocks_guess = new T3_guess*[wanted_guess];
        if (newBlocks_guess == 0) {
            flag18_guess = 0;
        } else {
            for (int i_guess = 0; i_guess < field14_guess; i_guess++) {
                newBlocks_guess[i_guess] = ((T3_guess**)table_guess)[i_guess];
            }
            int index_guess = field14_guess;
            if (index_guess < wanted_guess) {
                do {
                    T3_guess* block_guess = new T3_guess[unknown04_guess];
                    newBlocks_guess[index_guess] = block_guess;
                    if (block_guess == 0) {
                        flag18_guess = 0;
                        break;
                    }
                    index_guess++;
                } while (index_guess < wanted_guess);
            }
            if (flag18_guess != 0) {
                _free(table_guess);
                table_guess = (int*)newBlocks_guess;
                field14_guess = wanted_guess;
            }
        }
    }
    if (flag18_guess == 0) {
        ((PointerList_guess*)this)->Clear_guess();
        Fail_guess();
    }
}

// Stores a 36-byte row at `index`, growing the array first; SetWide_guess is the 56-byte twin.
// FUNCTION: TITANIUM 0x004B76E3
void Table_guess::Set_guess(int index_guess, const int* values_guess) {
    if (index_guess < 0) {
        return;
    }
    if (index_guess >= count_guess) {
        Grow_guess(index_guess + 1);
        if (flag18_guess == 0) {
            return;
        }
        count_guess = index_guess + 1;
    }
    if (flag18_guess != 0) {
        *(Row9_guess*)Get_guess(index_guess) = *(const Row9_guess*)values_guess;
    }
}

// SetElementIdx for 56-byte rows (14 ints) kept in blocks (block index >> shift, slot index & mask): grows
// the block table (0x004B75AA) and the length to index + 1 when needed. Negative indexes are ignored, and
// nothing is stored once an allocation has failed (+0x18 clear).
// FUNCTION: TITANIUM 0x004B7724
void Table_guess::SetWide_guess(int index_guess, const int* values_guess) {
    if (index_guess < 0) {
        return;
    }
    if (index_guess >= count_guess) {
        GrowWide_guess(index_guess + 1);
        if (flag18_guess == 0) {
            return;
        }
        count_guess = index_guess + 1;
    }
    if (flag18_guess != 0) {
        Row14_guess* dst_guess = (Row14_guess*)table_guess[index_guess >> shift_guess] + (mask_guess & index_guess);
        *dst_guess = *(const Row14_guess*)values_guess;
    }
}

// Item slot pointer for this location in `candidate` (the holder +0xC280), bags included; possessions
// (kind 0) only, 0 for every other kind or an invalid location.
// FUNCTION: TITANIUM 0x004B76A6
int* ItemLocation_guess::GetInventorySlot_guess(SlotCandidate_guess* candidate_guess) {
    if (candidate_guess != 0 && IsValid_guess() && kind_guess == 0) {
        return Resolve_guess(((SlotTable_guess*)&candidate_guess->embedded_guess[
            candidate_guess->offset_guess->offset_guess])->GetSlot_guess(field04_guess));
    }
    return 0;
}

// Move records: 36 bytes on the wire (from: kind, slot, bag index, mode; count; to: the same four).
// Working rows add the item (+0x24) and the requested destination (+0x28..+0x34), 56 bytes. A destination
// mode other than 0 lets the client pick the slot (2: general slots only).
// First row in [start, end) taking from location `key`; -1 if none.
// FUNCTION: TITANIUM 0x004B7772
int __cdecl FindLocationIndex_guess(Triple_guess key_guess,
    Lookup_guess* lookup_guess, int start_guess, int end_guess) {
    if (start_guess >= 0 && start_guess < lookup_guess->count_guess &&
        end_guess > 0 && end_guess <= lookup_guess->count_guess) {
        for (; start_guess < end_guess; start_guess++) {
            if ((char)key_guess.IsEqual_guess(
                    (Triple_guess*)lookup_guess->Get_guess(start_guess))) {
                return start_guess;
            }
        }
    }
    return -1;
}

// Undo of TakeItemsFromSlots_guess: puts each row's item back at its source, merging into a stack that
// is there now (and deleting the moved copy). Then empties the rows.
// FUNCTION: TITANIUM 0x004B77BB
void __cdecl RestoreTakenItems_guess(int param_1_guess, Lookup_guess* param_2_guess) {
    SlotCandidate_guess* candidate_guess;
    int count_guess;
    Lookup_guess* lookup_guess = param_2_guess;
    count_guess = lookup_guess->count_guess;
    param_2_guess = 0;
    if (count_guess > 0) {
        SlotHolder_guess* holder_guess = (SlotHolder_guess*)param_1_guess;
        candidate_guess = holder_guess ? &holder_guess->candidate_guess : 0;
        do {
            int* slot_guess = ((Entry_guess*)(lookup_guess->table_guess[(int)param_2_guess >> lookup_guess->shift_guess] +
                ((int)param_2_guess & lookup_guess->mask_guess) * 0x38))->GetInventorySlot_guess(candidate_guess);
            if (*slot_guess != 0) {
                ((view*)*slot_guess)->field48_guess +=
                    ((Entry_guess*)(lookup_guess->table_guess[(int)param_2_guess >> lookup_guess->shift_guess] +
                        ((int)param_2_guess & lookup_guess->mask_guess) * 0x38))->target_guess->field48_guess;
                view* target_guess = ((Entry_guess*)(lookup_guess->table_guess[(int)param_2_guess >> lookup_guess->shift_guess] +
                    ((int)param_2_guess & lookup_guess->mask_guess) * 0x38))->target_guess;
                if (target_guess != 0) {
                    target_guess->Slot00_guess(1);
                }
            } else {
                *slot_guess = (int)((Entry_guess*)(lookup_guess->table_guess[(int)param_2_guess >> lookup_guess->shift_guess] +
                    ((int)param_2_guess & lookup_guess->mask_guess) * 0x38))->target_guess;
            }
            param_2_guess = (Lookup_guess*)((int)param_2_guess + 1);
        } while ((int)param_2_guess < count_guess);
    }
    ((PointerList_guess*)lookup_guess)->Clear_guess();
}

// First row in [start, end) going to location `key`; -1 if none.
// FUNCTION: TITANIUM 0x004B7885
int __cdecl FindDestinationIndex_guess(SlotKey_guess key_guess,
    Lookup_guess* lookup_guess, int start_guess, int end_guess) {
    if (start_guess >= 0 && start_guess < lookup_guess->count_guess &&
        end_guess > 0 && end_guess <= lookup_guess->count_guess) {
        int index_guess = start_guess;
        if (index_guess < end_guess) {
            for (; index_guess < end_guess; index_guess++) {
                char* record_guess = (char*)lookup_guess->table_guess[
                    index_guess >> lookup_guess->shift_guess];
                record_guess += (lookup_guess->mask_guess & index_guess) * 0x38 + 0x14;
                if ((char)((Triple_guess*)&key_guess)->IsEqual_guess((Triple_guess*)record_guess)) {
                    return index_guess;
                }
            }
        }
    }
    return -1;
}

char __cdecl FindStackSlot_guess(SlotHolder_guess* holder_guess,
    SlotKey_guess key_guess, int lookup_value_guess, int index_guess);
char __cdecl FindFreeSlot_guess(SlotHolder_guess* holder_guess,
    SlotKey_guess key_guess, Lookup_guess* lookup_guess, int index_guess);
char __cdecl SwapMovedItem_guess(SlotHolder_guess* holder_guess,
    Lookup_guess* lookup_guess, int count_guess);

// Auto-places row `index` (destination mode set) in its destination kind, from the first allowed slot:
// first on a matching stack (FindStackSlot_guess), then in a free slot or bag (FindFreeSlot_guess; worn
// slots only when 0x4BC906 allows, probably the equip check), last by SwapMovedItem_guess.
// FUNCTION: TITANIUM 0x004B8796
// @early-stop: budget, structural ndiff=21
bool __cdecl PlaceMovedItem_guess(SlotHolder_guess* holder_guess,
    Lookup_guess* lookup_guess, int index_guess) {
    SlotRecord_guess* page_guess = (SlotRecord_guess*)lookup_guess->table_guess[
        index_guess >> lookup_guess->shift_guess];
    SlotRecord_guess* record_guess = page_guess +
        (lookup_guess->mask_guess & index_guess);
    if (record_guess->key_guess.type_guess == 0) {
        return 0;
    }

    int first_guess = ((Condition_guess*)&record_guess->key_guess)->GetFirstAutoSlot_guess();
    int end_guess = record_guess->key_guess.GetSlotCount_guess();
    if (record_guess->target_guess->IsStackable_guess() && first_guess < end_guess) {
        int current_guess = first_guess;
        do {
            SlotKey_guess key_guess;
            key_guess.kind_guess = ((SlotRecord_guess*)lookup_guess->table_guess[
                index_guess >> lookup_guess->shift_guess] +
                (lookup_guess->mask_guess & index_guess))->key_guess.kind_guess;
            key_guess.field04_guess = current_guess;
            key_guess.field08_guess = -1;
            key_guess.type_guess = 0;
            int* slot_guess = key_guess.GetInventorySlot_guess(
                holder_guess ? &holder_guess->candidate_guess : 0);
            if (slot_guess != 0 && *slot_guess != 0 &&
                FindStackSlot_guess(holder_guess, key_guess,
                    (int)lookup_guess, index_guess)) {
                return 1;
            }
            current_guess++;
        } while (current_guess < end_guess);
        }

    for (int current_guess = first_guess; current_guess < end_guess; current_guess++) {
        SlotKey_guess key_guess;
        key_guess.kind_guess = ((SlotRecord_guess*)lookup_guess->table_guess[
            index_guess >> lookup_guess->shift_guess] +
            (lookup_guess->mask_guess & index_guess))->key_guess.kind_guess;
        key_guess.field04_guess = current_guess;
        key_guess.field08_guess = -1;
        key_guess.type_guess = 0;
        if (!((State_guess*)&key_guess)->IsWornSlot_guess() ||
            holder_guess->CanEquipItem_guess(
                ((SlotRecord_guess*)lookup_guess->table_guess[
                    index_guess >> lookup_guess->shift_guess] +
                    (lookup_guess->mask_guess & index_guess))->target_guess,
                current_guess, 1)) {
            if (FindFreeSlot_guess(holder_guess, key_guess,
                    lookup_guess, index_guess)) {
                return 1;
            }
        }
    }

    return SwapMovedItem_guess(holder_guess, lookup_guess, index_guess);
}

// Takes the spot of an earlier auto-placed row (`count` is really the row index) and re-places that row;
// swaps back when it no longer fits. Rows with mode 2 never take a worn slot.
// FUNCTION: TITANIUM 0x004B78F2
// @early-stop: budget, structural ndiff=172
char __cdecl SwapMovedItem_guess(SlotHolder_guess* holder_guess,
    Lookup_guess* lookup_guess, int count_guess) {
    int index_guess = count_guess;
    do {
        index_guess--;
        if (index_guess < 0) {
            return 0;
        }

        if (RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[3] == 0) {
            continue;
        }
        SlotCandidate_guess* candidate_guess = holder_guess ?
            &holder_guess->candidate_guess : 0;
        int* slot_guess = RecordAt_guess(lookup_guess, index_guess)->key_guess
            .GetInventorySlot_guess(candidate_guess);
        if (*slot_guess != 0) {
            continue;
        }

        if (RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[0] !=
            RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[0]) {
            continue;
        }
        if (((State_guess*)&RecordAt_guess(lookup_guess, index_guess)->key_guess)->IsWornSlot_guess()) {
            if (RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[3] == 2 ||
                !holder_guess->CanEquipItem_guess(
                    RecordAt_guess(lookup_guess, count_guess)->target_guess,
                    RecordAt_guess(lookup_guess, index_guess)->key_guess.field04_guess, 1)) {
                continue;
            }
        }

        if (RecordAt_guess(lookup_guess, index_guess)->key_guess.field08_guess != -1) {
            int oldValue_guess = RecordAt_guess(lookup_guess, index_guess)->key_guess.field08_guess;
            slot_guess = RecordAt_guess(lookup_guess, index_guess)->key_guess
                .GetInventorySlot_guess(candidate_guess);
            if (RecordAt_guess(lookup_guess, count_guess)->target_guess
                    ->Slot05_guess(*slot_guess, 0)) {
                RecordAt_guess(lookup_guess, count_guess)->key_guess.field08_guess = oldValue_guess;
            }
        }

        RecordAt_guess(lookup_guess, count_guess)->key_guess =
            RecordAt_guess(lookup_guess, index_guess)->key_guess;
        RecordAt_guess(lookup_guess, index_guess)->key_guess.kind_guess =
            RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[0];
        RecordAt_guess(lookup_guess, index_guess)->key_guess.field04_guess =
            RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[1];
        RecordAt_guess(lookup_guess, index_guess)->key_guess.field08_guess =
            RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[2];
        RecordAt_guess(lookup_guess, index_guess)->key_guess.type_guess =
            RecordAt_guess(lookup_guess, index_guess)->unknown28_guess[3];
        if (PlaceMovedItem_guess(holder_guess, lookup_guess, index_guess)) {
            return 1;
        }

        RecordAt_guess(lookup_guess, index_guess)->key_guess =
            RecordAt_guess(lookup_guess, count_guess)->key_guess;
        RecordAt_guess(lookup_guess, count_guess)->key_guess.kind_guess =
            RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[0];
        RecordAt_guess(lookup_guess, count_guess)->key_guess.field04_guess =
            RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[1];
        RecordAt_guess(lookup_guess, count_guess)->key_guess.field08_guess =
            RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[2];
        RecordAt_guess(lookup_guess, count_guess)->key_guess.type_guess =
            RecordAt_guess(lookup_guess, count_guess)->unknown28_guess[3];
    } while (1);
}

// Claims an empty slot no other row targets, or recurses into the bag there when it accepts the item
// (vtable slot 5).
// FUNCTION: TITANIUM 0x004B7B74
char __cdecl FindFreeSlot_guess(SlotHolder_guess* holder_guess, SlotKey_guess key_guess,
    Lookup_guess* lookup_guess, int index_guess) {
    if (key_guess.IsValid_guess()) {
        SlotCandidate_guess* candidate_guess =
            holder_guess ? &holder_guess->candidate_guess : 0;
        int* slot_guess = key_guess.GetInventorySlot_guess(candidate_guess);
        if (slot_guess != 0) {
            if (*slot_guess == 0) {
                if (FindDestinationIndex_guess(key_guess, lookup_guess, 0,
                        lookup_guess->count_guess) == -1) {
                    SlotRecord_guess* record_guess = (SlotRecord_guess*)lookup_guess->table_guess[
                        index_guess >> lookup_guess->shift_guess] +
                        (lookup_guess->mask_guess & index_guess);
                    record_guess->key_guess = key_guess;
                    return 1;
                }
            } else {
                if (((Gate_guess*)*slot_guess)->IsReady_guess()) {
                    if (((SlotRecord_guess*)lookup_guess->table_guess[
                            index_guess >> lookup_guess->shift_guess] +
                            (lookup_guess->mask_guess & index_guess))->target_guess->Slot05_guess(*slot_guess, 0)) {
                        int limit_guess = ((Gate_guess*)*slot_guess)->GetLimit_guess();
                        for (int index2_guess = 0; index2_guess < limit_guess; index2_guess++) {
                            key_guess.field08_guess = index2_guess;
                            if (FindFreeSlot_guess(holder_guess, key_guess,
                                    lookup_guess, index_guess)) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

struct ProbeKey_guess {
    int kind_guess;
    int field04_guess;
    int field08_guess;
    int type_guess;
};

struct Probe2_guess {
    ProbeKey_guess r0_guess;
    int e_guess;
    int a14_guess;
    int b18_guess;
    int c1c_guess;
    int d20_guess;
    Probe2_guess() : a14_guess(0), b18_guess(-1), c1c_guess(-1), d20_guess(0) {
        r0_guess.kind_guess = 0;
        r0_guess.field04_guess = -1;
        r0_guess.field08_guess = -1;
        r0_guess.type_guess = 0;
    }
};

struct Link_guess {
    char unknown00_guess[4];
    int offset04_guess;
};

struct Holder_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 Holder_guess::Get_guess
    Gate_guess* Get_guess(int index_guess);
};

struct Ctx_guess {
    char unknown00_guess[8];
    Link_guess* link08_guess;
    Holder_guess* HolderOf_guess() {
        return (Holder_guess*)((int)&link08_guess + link08_guess->offset04_guess);
    }
};

// Adds a row taking from `entry`'s location toward `extra`: the item's count (+0x48) minus what earlier
// rows already take from there, capped at `amount`. Returns what is still wanted; a non-stack counts 1.
// FUNCTION: TITANIUM 0x004B8091
// @early-stop: budget, structural ndiff=14
int __cdecl CollectItemCount_guess(ItemInstance_guess* entry_guess, int amount_guess, int flags_guess,
        Probe2_guess* probe_guess, Table_guess* table_guess, int* extra_guess) {
    if (!MatchesItemFilter_guess(entry_guess, flags_guess)) {
        return amount_guess;
    }
    if (extra_guess != 0) {
        *(Row4_guess*)&probe_guess->a14_guess = *(Row4_guess*)extra_guess;
    }
    int remaining_guess = entry_guess->field48_guess;
    int index_guess = FindLocationIndex_guess(*(Triple_guess*)probe_guess, table_guess, 0, table_guess->count_guess);
    if (index_guess != -1) {
        if (!entry_guess->IsStackable_guess()) {
            return amount_guess;
        }
        do {
            SelectionRow_guess* row_guess = (SelectionRow_guess*)table_guess->Get_guess(index_guess);
            remaining_guess -= row_guess->value_guess;
            index_guess = FindLocationIndex_guess(*(Triple_guess*)probe_guess, table_guess,
                index_guess + 1, table_guess->count_guess);
            if (remaining_guess <= 0) {
                return amount_guess;
            }
        } while (index_guess != -1);
    }
    int stored_guess = remaining_guess;
    if (!entry_guess->IsStackable_guess()) {
        amount_guess--;
    } else if (amount_guess <= remaining_guess) {
        stored_guess = amount_guess;
        amount_guess = 0;
    } else {
        amount_guess -= remaining_guess;
    }
    probe_guess->e_guess = stored_guess;
    table_guess->Set_guess(table_guess->count_guess, (const int*)probe_guess);
    return amount_guess;
}

// Takes each source item into a working row: whole items leave their slot, part of a stack is split off
// (Slot01_guess clones it). Returns 1 for a missing or short source, 3 when vtable slot 4 refuses (only
// with `flag`), else 0.
// FUNCTION: TITANIUM 0x004B8165
// @early-stop: budget, structural ndiff=18
int __cdecl TakeItemsFromSlots_guess(SlotHolder_guess* holder_guess, Lookup_guess* lookup_guess,
    Table_guess* table_guess, char flag_guess) {
    int count_guess = lookup_guess->count_guess;
    int index_guess = 0;
    if (count_guess > 0) {
        SlotCandidate_guess* candidate_guess = holder_guess != 0 ? &holder_guess->candidate_guess : 0;
        do {
            T3_guess row_guess;
            Row9_guess* record_guess = (Row9_guess*)lookup_guess->Get_guess(index_guess);
            *(Row9_guess*)&row_guess = *record_guess;
            *(Row4_guess*)&row_guess.a28_guess = *(Row4_guess*)&row_guess.a14_guess;
            int* slot_guess = ((ItemLocation_guess*)&row_guess)->GetInventorySlot_guess(candidate_guess);
            if (slot_guess == 0 || *slot_guess == 0) {
                return 1;
            }
            if (flag_guess != 0 && ((view*)*slot_guess)->Slot04_guess(0) == 0) {
                return 3;
            }
            if (row_guess.r0_guess.e_guess == ((view*)*slot_guess)->field48_guess ||
                ((view*)*slot_guess)->IsStackable_guess() == 0) {
                row_guess.e24_guess = *slot_guess;
                table_guess->SetWide_guess(table_guess->count_guess, (const int*)&row_guess);
                *slot_guess = 0;
            } else {
                if (((view*)*slot_guess)->field48_guess <= row_guess.r0_guess.e_guess) {
                    return 1;
                }
                view* value_guess = ((view*)*slot_guess)->Slot01_guess();
                row_guess.e24_guess = (int)value_guess;
                value_guess->SetStackCount_guess(row_guess.r0_guess.e_guess);
                ((view*)*slot_guess)->field48_guess -= row_guess.r0_guess.e_guess;
                table_guess->SetWide_guess(table_guess->count_guess, (const int*)&row_guess);
            }
            index_guess++;
        } while (index_guess < count_guess);
    }
    return 0;
}

// Tops up a matching stack (same id, stackable) at the key, counting what other rows already send there
// (Get700_guess is probably the stack size). An overflow splits the item into a new row; full stacks
// fail. A container there is searched slot by slot.
// FUNCTION: TITANIUM 0x004B8269
// @early-stop: budget, structural ndiff=95
char __cdecl FindStackSlot_guess(SlotHolder_guess* holder_guess, SlotKey_guess key_guess,
    int lookup_value_guess, int index_guess) {
    Lookup_guess* table_guess = (Lookup_guess*)lookup_value_guess;
    if (RecordAt_guess(table_guess, index_guess)->target_guess->IsStackable_guess() == 0) {
        return 0;
    }
    if (key_guess.IsValid_guess() == 0) {
        return 0;
    }
    int* slot_guess = key_guess.GetInventorySlot_guess(
        holder_guess ? &holder_guess->candidate_guess : 0);
    if (slot_guess == 0 || *slot_guess == 0) {
        return 0;
    }
    if (((view*)*slot_guess)->GetItemId_guess() ==
        RecordAt_guess(table_guess, index_guess)->target_guess->GetItemId_guess()) {
        int offset_guess = ((view*)*slot_guess)->field48_guess;
        if (offset_guess < RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess()) {
            int start_guess = 0;
            int found_guess;
            do {
                found_guess = FindDestinationIndex_guess(key_guess, table_guess, start_guess, index_guess);
                start_guess = found_guess;
                if (found_guess >= 0) {
                    if (RecordAt_guess(table_guess, index_guess)->target_guess->GetItemId_guess() ==
                        RecordAt_guess(table_guess, found_guess)->target_guess->GetItemId_guess()) {
                        offset_guess += RecordAt_guess(table_guess, found_guess)->target_guess->field48_guess;
                        start_guess = found_guess + 1;
                    }
                }
            } while (start_guess >= 0);
        }
        if (offset_guess != 0) {
            int length_guess = RecordAt_guess(table_guess, index_guess)->target_guess->field48_guess;
            if (RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess() <
                length_guess + offset_guess) {
                if (RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess() <=
                    offset_guess) {
                    return 0;
                }
                SlotRecord_guess local_guess = *RecordAt_guess(table_guess, index_guess);
                local_guess.target_guess = local_guess.target_guess->Slot01_guess();
                local_guess.field10_guess += offset_guess -
                    RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess();
                local_guess.target_guess->SetStackCount_guess(local_guess.field10_guess);
                RecordAt_guess(table_guess, index_guess)->field10_guess =
                    RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess() - offset_guess;
                RecordAt_guess(table_guess, index_guess)->target_guess->SetStackCount_guess(
                    RecordAt_guess(table_guess, index_guess)->target_guess->Get700_guess() - offset_guess);
                ((Table_guess*)table_guess)->SetWide_guess(table_guess->count_guess,
                    (const int*)&local_guess);
                return 1;
            }
            RecordAt_guess(table_guess, index_guess)->key_guess = key_guess;
            return 1;
        }
    } else {
        if (((Gate_guess*)*slot_guess)->IsReady_guess()) {
            if (RecordAt_guess(table_guess, index_guess)->target_guess->Slot05_guess(
                    *slot_guess, 0)) {
                int limit_guess = ((Gate_guess*)*slot_guess)->GetLimit_guess();
                int value_guess = 0;
                if (limit_guess > 0) {
                    do {
                        key_guess.field08_guess = value_guess;
                        if (FindStackSlot_guess(holder_guess, key_guess,
                                (int)table_guess, index_guess)) {
                            return 1;
                        }
                        value_guess++;
                    } while (value_guess < limit_guess);
                }
            }
        }
    }
    return 0;
}

// Builds rows that bring `count` of item id `param_2` from possessions 0-30 (flag 0x100: general slots
// 22-29) and their bags. True when enough was found.
// FUNCTION: TITANIUM 0x004B85AE
// @early-stop: budget, structural ndiff=199
bool FindItemsById_guess(Ctx_guess* ctx_guess, int param_2_guess, int count_guess, unsigned int flags_guess,
    int p5_guess, int* p6_guess) {
    int i_guess = 0;
    int last_guess = 0x1e;
    int slot_guess;
    ProbeKey_guess key_guess;
    ProbeKey_guess key2_guess;
    if ((flags_guess & 0x100) != 0) {
        i_guess = 0x16;
        last_guess = 0x1d;
    }
    for (; i_guess <= last_guess; i_guess++) {
        if (count_guess < 1) {
            break;
        }
        slot_guess = i_guess;
        if (ctx_guess->HolderOf_guess()->Get_guess(i_guess) != 0) {
            Probe2_guess probe_guess;
            if (ctx_guess->HolderOf_guess()->Get_guess(i_guess)->GetItemId_guess() == param_2_guess) {
                key_guess.kind_guess = 0;
                key_guess.field04_guess = i_guess;
                key_guess.field08_guess = -1;
                key_guess.type_guess = 0;
                probe_guess.r0_guess = key_guess;
                count_guess = CollectItemCount_guess((ItemInstance_guess*)ctx_guess->HolderOf_guess()->Get_guess(slot_guess),
                    count_guess, flags_guess, &probe_guess, (Table_guess*)p5_guess, p6_guess);
                i_guess = slot_guess;
            } else {
                if (ctx_guess->HolderOf_guess()->Get_guess(i_guess)->IsReady_guess() != 0) {
                    int limit_guess = ctx_guess->HolderOf_guess()->Get_guess(i_guess)->GetLimit_guess();
                    for (int c_guess = 0; c_guess < limit_guess; c_guess++) {
                        if (count_guess < 1) {
                            break;
                        }
                        if (ctx_guess->HolderOf_guess()->Get_guess(i_guess)->GetChild_guess(c_guess) != 0) {
                            if (ctx_guess->HolderOf_guess()->Get_guess(i_guess)->GetChild_guess(c_guess)
                                    ->GetItemId_guess() == param_2_guess) {
                                key2_guess.kind_guess = 0;
                                key2_guess.field04_guess = i_guess;
                                key2_guess.field08_guess = c_guess;
                                key2_guess.type_guess = 0;
                                probe_guess.r0_guess = key2_guess;
                                count_guess = CollectItemCount_guess(
                                    (ItemInstance_guess*)ctx_guess->HolderOf_guess()->Get_guess(slot_guess)->GetChild_guess(c_guess),
                                    count_guess, flags_guess, &probe_guess, (Table_guess*)p5_guess, p6_guess);
                                i_guess = slot_guess;
                            }
                        }
                    }
                }
            }
        }
    }
    return count_guess < 1;
}

struct RowSet_guess {
    int count_guess;
};

inline Table_guess::~Table_guess() {
    ((PointerList_guess*)this)->Clear_guess();
}

struct SlotFlags_guess {
    char unknown00_guess[0xc28c];
    unsigned char field_c28c_guess;
    char unknownc28d_guess[0xbb];
    unsigned char field_c348_guess;
};

// Pre-check: every fixed destination is empty or holds a stackable item of the same id; rows without a
// valid destination must be placed by PlaceMovedItem_guess.
// FUNCTION: TITANIUM 0x004B8915
char __cdecl CanPlaceAllItems_guess(SlotHolder_guess* holder_guess, Lookup_guess* lookup_guess) {
    int index_guess = 0;
    if (lookup_guess->count_guess > 0) {
        do {
            if (((SlotRecord_guess*)lookup_guess->table_guess[index_guess >> lookup_guess->shift_guess] +
                    (lookup_guess->mask_guess & index_guess))->key_guess.IsValid_guess()) {
                int* slot_guess = ((SlotRecord_guess*)lookup_guess->table_guess[index_guess >> lookup_guess->shift_guess] +
                    (lookup_guess->mask_guess & index_guess))->key_guess.GetInventorySlot_guess(
                    holder_guess ? &holder_guess->candidate_guess : 0);
                if (slot_guess == 0) {
                    return 0;
                }
                if (*slot_guess != 0) {
                    SlotRecord_guess* record_guess = (SlotRecord_guess*)((index_guess & lookup_guess->mask_guess) * 0x38 +
                        lookup_guess->table_guess[index_guess >> lookup_guess->shift_guess]);
                    if (((view*)*slot_guess)->GetItemId_guess() != record_guess->target_guess->GetItemId_guess()) {
                        return 0;
                    }
                    if (!((SlotRecord_guess*)lookup_guess->table_guess[index_guess >> lookup_guess->shift_guess] +
                            (lookup_guess->mask_guess & index_guess))->target_guess->IsStackable_guess()) {
                        return 0;
                    }
                }
            } else {
                if (!PlaceMovedItem_guess(holder_guess, lookup_guess, index_guess)) {
                    return 0;
                }
            }
            index_guess++;
        } while (index_guess < lookup_guess->count_guess);
    }
    return 1;
}

// Puts every taken item at its destination, merging stacks. Fails with 2 (bad location, full or different
// stack, bag refuses), 5 (worn slot not allowed, 0x4BC906) or 4 (0x4BCE5F test on the item and its
// contents, tu_080).
// FUNCTION: TITANIUM 0x004B7C7C
// @early-stop: budget, structural ndiff=61
int __cdecl CommitMovedItems_guess(int ctx_guess, Table_guess* local_guess) {
    SlotHolder_guess* holder_guess = (SlotHolder_guess*)ctx_guess;
    int count_guess = local_guess->count_guess;
    int result_guess = 0;
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            if (!RecordAt_guess(local_guess, index_guess)->key_guess.IsValid_guess()) {
                result_guess = 2;
                break;
            }
            SlotCandidate_guess* candidate_guess = holder_guess ?
                &holder_guess->candidate_guess : 0;
            int* slot_guess = RecordAt_guess(local_guess, index_guess)->key_guess
                .GetInventorySlot_guess(candidate_guess);
            if (slot_guess == 0) {
                result_guess = 2;
                break;
            }
            if (((State_guess*)&RecordAt_guess(local_guess, index_guess)->key_guess)
                    ->IsWornSlot_guess()) {
                if (!holder_guess->CanEquipItem_guess(
                        RecordAt_guess(local_guess, index_guess)->target_guess,
                        RecordAt_guess(local_guess, index_guess)->key_guess.field04_guess,
                        1)) {
                    result_guess = 5;
                    break;
                }
            }
            if (holder_guess->WouldDuplicateLore_guess(
                    RecordAt_guess(local_guess, index_guess)->target_guess) != 0) {
                result_guess = 4;
                break;
            }
            if (RecordAt_guess(local_guess, index_guess)->key_guess.field08_guess >= 0) {
                SlotKey_guess probe_guess =
                    RecordAt_guess(local_guess, index_guess)->key_guess;
                probe_guess.field08_guess = -1;
                int* gate_slot_guess = probe_guess.GetInventorySlot_guess(candidate_guess);
                if (gate_slot_guess == 0) {
                    result_guess = 2;
                    break;
                }
                if (*gate_slot_guess == 0) {
                    result_guess = 2;
                    break;
                }
                if (!((Gate_guess*)*gate_slot_guess)->IsReady_guess()) {
                    result_guess = 2;
                    break;
                }
                if (!RecordAt_guess(local_guess, index_guess)->target_guess
                        ->Slot05_guess(*gate_slot_guess, 0)) {
                    result_guess = 2;
                    break;
                }
            }
            if (*slot_guess == 0) {
                *slot_guess = (int)RecordAt_guess(local_guess, index_guess)->target_guess;
            } else {
                if (!((view*)*slot_guess)->IsStackable_guess()) {
                    result_guess = 2;
                    break;
                }
                int field48_guess = ((view*)*slot_guess)->field48_guess;
                int target_field48_guess =
                    RecordAt_guess(local_guess, index_guess)->target_guess->field48_guess;
                int limit_guess =
                    RecordAt_guess(local_guess, index_guess)->target_guess->Get700_guess();
                if (limit_guess < target_field48_guess + field48_guess) {
                    result_guess = 2;
                    break;
                }
                if (RecordAt_guess(local_guess, index_guess)->target_guess->GetItemId_guess() !=
                    ((view*)*slot_guess)->GetItemId_guess()) {
                    result_guess = 2;
                    break;
                }
                ((view*)*slot_guess)->field48_guess +=
                    RecordAt_guess(local_guess, index_guess)->target_guess->field48_guess;
                view* target_guess =
                    RecordAt_guess(local_guess, index_guess)->target_guess;
                if (target_guess != 0) {
                    target_guess->Slot00_guess(1);
                }
            }
            RecordAt_guess(local_guess, index_guess)->target_guess = 0;
            index_guess++;
        } while (index_guess < count_guess);
    }
    return result_guess;
}
// Undo of CommitMovedItems_guess for the rows already placed: takes their items back off the destination,
// splitting a merged stack by the row's count.
// FUNCTION: TITANIUM 0x004B7F22
void __cdecl RollbackMovedItems_guess(int ctx_guess, Lookup_guess* lookup_guess) {
    int index_guess = 0;
    if (lookup_guess->count_guess > 0) {
        SlotCandidate_guess* candidate_guess = ctx_guess ?
            &((SlotHolder_guess*)ctx_guess)->candidate_guess : 0;
        do {
            int* slot_guess = RecordAt_guess(lookup_guess, index_guess)->key_guess
                .GetInventorySlot_guess(candidate_guess);
            if (slot_guess != 0 && *slot_guess != 0) {
                if (RecordAt_guess(lookup_guess, index_guess)->target_guess == 0) {
                    if (((view*)*slot_guess)->field48_guess ==
                        RecordAt_guess(lookup_guess, index_guess)->field10_guess) {
                        RecordAt_guess(lookup_guess, index_guess)->target_guess =
                            (view*)*slot_guess;
                        *slot_guess = 0;
                    } else {
                        RecordAt_guess(lookup_guess, index_guess)->target_guess =
                            ((view*)*slot_guess)->Slot01_guess();
                        RecordAt_guess(lookup_guess, index_guess)->target_guess->SetStackCount_guess(
                            RecordAt_guess(lookup_guess, index_guess)->field10_guess);
                        ((view*)*slot_guess)->field48_guess -=
                            RecordAt_guess(lookup_guess, index_guess)->field10_guess;
                    }
                }
            }
            index_guess++;
        } while (index_guess < lookup_guess->count_guess);
    }
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

// Sends OP_MoveMultipleItems (0x463B): the row count, then the 36-byte wire part of each row.
// FUNCTION: TITANIUM 0x004B8013
void __cdecl SendMoveMultipleItems_guess(int unused_guess, Lookup_guess* lookup_guess) {
    int size_guess = lookup_guess->count_guess * 9 * 4 + 4;
    int* buffer_guess = (int*)operator new[](size_guess);
    *buffer_guess = lookup_guess->count_guess;
    Row9_guess* out_guess = (Row9_guess*)(buffer_guess + 1);
    int index_guess = 0;
    if (lookup_guess->count_guess > 0) {
        do {
            *out_guess = *(const Row9_guess*)((Row14_guess*)lookup_guess->table_guess[
                index_guess >> lookup_guess->shift_guess] + (lookup_guess->mask_guess & index_guess));
            out_guess++;
            index_guess++;
        } while (index_guess < lookup_guess->count_guess);
    }
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_MoveMultipleItems, buffer_guess, size_guess, 1);
    _free(buffer_guess);
}

// Moves a batch: take, check, commit, rolling back on failure. Returns 0 or the failing step's code (1-5).
// With `flags` the batch is sent to the server; success sets +0xC28C and clears +0xC348 on `ctx`.
// FUNCTION: TITANIUM 0x004B89DE
int __cdecl MoveMultipleItems_guess(int ctx_guess, Table_guess* table_guess, bool flags_guess) {
    Table_guess local_guess(0x20);
    int result_guess = TakeItemsFromSlots_guess((SlotHolder_guess*)ctx_guess, table_guess, &local_guess, 0);
    if (result_guess != 0) {
        RestoreTakenItems_guess(ctx_guess, &local_guess);
        return result_guess;
    }
    if (!CanPlaceAllItems_guess((SlotHolder_guess*)ctx_guess, &local_guess)) {
        RestoreTakenItems_guess(ctx_guess, &local_guess);
        return 2;
    }
    result_guess = CommitMovedItems_guess(ctx_guess, &local_guess);
    if (result_guess != 0) {
        RollbackMovedItems_guess(ctx_guess, &local_guess);
        RestoreTakenItems_guess(ctx_guess, &local_guess);
        return result_guess;
    }
    if (flags_guess) {
        SendMoveMultipleItems_guess(ctx_guess, &local_guess);
    }
    SlotFlags_guess* flags_ptr = (SlotFlags_guess*)ctx_guess;
    flags_ptr->field_c28c_guess = 1;
    flags_ptr->field_c348_guess = 0;
    return 0;
}

// Server OP_MoveMultipleItems: count, then 36-byte rows; 7 when the payload is shorter than one row or
// than `count` rows. Applied without sending it back.
// FUNCTION: TITANIUM 0x004B8AA2
int __cdecl Handle_OP_MoveMultipleItems_guess(int ctx_guess, RowSet_guess* rows_guess, unsigned int size_guess) {
    if (size_guess < 0x28) {
        return 7;
    }
    Table_guess table_guess(0x20);
    int count_guess = rows_guess->count_guess;
    int i_guess = 0;
    Row9_guess* row_guess = (Row9_guess*)(rows_guess + 1);
    if (count_guess > 0) {
        unsigned int used_guess = (unsigned int)((int)row_guess - (int)rows_guess) + 0x24;
        do {
            if (size_guess < used_guess) {
                return 7;
            }
            table_guess.Set_guess(table_guess.count_guess, row_guess->v_guess);
            row_guess++;
            used_guess += 0x24;
            i_guess++;
        } while (i_guess < count_guess);
    }
    int result_guess = MoveMultipleItems_guess(ctx_guess, &table_guess, 0);
    return result_guess;
}

// SaturateDifference_guess of `value` and the clock (vtable slot 11).
// FUNCTION: TITANIUM 0x004B8B32
int Context_guess::Update_guess(__int64 value_guess) {
    return SaturateDifference_guess(value_guess, service_guess->Slot11_guess());
}

// Time since +0x1A8 under the connection's lock, probably since the last packet; 0 without a context.
// FUNCTION: TITANIUM 0x004B8B52
int Request_guess::GetIdleTime_guess() {
    ScopeProxy_guess cleanup_guess(&scope_guess);
    int result_guess;
    if (context_guess == 0) {
        result_guess = 0;
    } else {
        result_guess = context_guess->Update_guess(value_guess);
    }
    return result_guess;
}

// Net graph, `count` rows high: the first `fade` of the width green, yellow or red by the limits at
// 0x6486E0 / 0x642014, the rest black, top and bottom rows darker. A marker 1/10 wide bounces across,
// stepping 1, 2 or 5 per call with the traffic `delta`.
// FUNCTION: TITANIUM 0x004B8BB1
// @early-stop: budget, structural ndiff=143
void __cdecl DrawNetGraph_guess(unsigned short start_guess,
    unsigned short row_guess, unsigned short span_guess,
    unsigned short count_guess, float fade_guess, int delta_guess) {
    CVector3 first_guess;
    CVector3 second_guess;
    CVector3 third_guess;
    unsigned char alpha_guess = 0xff;
    ColorChannels_guess baseColor_guess;
    *(unsigned int*)&baseColor_guess = 0;
    baseColor_guess.alpha_guess = alpha_guess;
    int scaled_guess;
    ColorChannels_guess edge_guess;
    *(unsigned int*)&edge_guess = 0;
    edge_guess.alpha_guess = alpha_guess;
    if ((fade_guess > g_firstColorLimit_guess) ||
        ((edge_guess.red_guess = 0xff),
            fade_guess > g_secondColorLimit_guess)) {
        edge_guess.green_guess = 0xff;
    }
    scaled_guess = *(int*)&edge_guess;
    ColorChannels_guess* scaledChannels_guess = (ColorChannels_guess*)&scaled_guess;
    scaledChannels_guess->red_guess = (unsigned char)(int)
        ((float)scaledChannels_guess->red_guess * g_colorScale_guess);
    scaledChannels_guess->green_guess = (unsigned char)(int)
        ((float)scaledChannels_guess->green_guess * g_colorScale_guess);
    scaledChannels_guess->blue_guess = (unsigned char)(int)
        ((float)scaledChannels_guess->blue_guess * g_colorScale_guess);

    first_guess.x = (float)start_guess;
    first_guess.y = (float)row_guess;
    first_guess.z = 0.0f;
    second_guess.x = (float)((int)((float)span_guess * fade_guess) + start_guess - 1);
    second_guess.y = (float)row_guess;
    second_guess.z = 0.0f;
    third_guess.x = (float)((int)start_guess + (int)span_guess - 1);
    third_guess.y = (float)row_guess;
    third_guess.z = 0.0f;

    int index_guess = 0;
    if (count_guess != 0) {
        do {
            unsigned int color_guess = *(unsigned int*)&edge_guess;
            if (index_guess == 0 || index_guess == count_guess - 1) {
                color_guess = (unsigned int)scaled_guess;
            }
            g_drawService_guess->WriteTextHD(&first_guess, &second_guess, color_guess);
            g_drawService_guess->WriteTextHD(&second_guess, &third_guess,
                *(unsigned int*)&baseColor_guess);
            index_guess++;
            first_guess.y += g_one_guess;
            second_guess.y += g_one_guess;
            third_guess.y += g_one_guess;
        } while (index_guess < count_guess);
    }

    int spanStep_guess = span_guess / 10;
    int step_guess = 1;
    if ((g_state_guess & 1) == 0) {
        g_state_guess |= 1;
        g_position_guess = start_guess;
    }
    int pending_guess = g_accumulator_guess + delta_guess;
    if (pending_guess <= 0) {
        g_accumulator_guess = 0;
    } else {
        if (pending_guess > 1000) {
            step_guess = 5;
        } else if (pending_guess > 100) {
            step_guess = 2;
        }
        g_position_guess = (unsigned short)(g_position_guess +
            (short)step_guess * g_direction_guess);
        g_accumulator_guess = pending_guess - step_guess;
    }
    if (g_position_guess < start_guess) {
        g_direction_guess = 1;
        g_accumulator_guess = 0;
        g_position_guess = start_guess;
    } else if ((int)spanStep_guess + g_position_guess >
        (int)start_guess + (int)span_guess) {
        start_guess = (unsigned short)(start_guess - (short)spanStep_guess + span_guess);
        g_direction_guess = -1;
        g_accumulator_guess = 0;
        g_position_guess = start_guess;
    }

    first_guess.x = (float)g_position_guess;
    first_guess.y = (float)((count_guess >> 1) + row_guess);
    second_guess.x = (float)(spanStep_guess - 1 + g_position_guess);
    second_guess.y = first_guess.y;
    g_drawService_guess->WriteTextHD(&first_guess, &second_guess,
        (unsigned int)scaled_guess);
}

struct ClockSource_guess {
    char unknown00_guess[0x50];
    int interval_guess;
};

#define g_overlayEnabled_guess EQ_GLOBAL(int, 0x00905D24)
#define g_clockSource_guess EQ_GLOBAL(ClockSource_guess*, 0x0079DBD8)
#define g_previousTotal_guess EQ_GLOBAL(unsigned __int64, 0x00985C30)
#define g_zeroFloat_guess EQ_GLOBAL(float, 0x0063F4CC)
#define g_percentScale_guess EQ_GLOBAL(float, 0x00640E20)

// EXTERNAL: TITANIUM 0x0043C3E0 WriteTextHD2
void __cdecl WriteTextHD2(char* text_guess, int x_guess,
    int y_guess, int color_guess);

// Net status at (`x`, `y`), drawn at the mouse by tu_029: link health in percent (100% until 0.5 s
// without traffic, falling over the interval at 0x79DBD8 +0x50), the stats' milliseconds, then the graph
// fed with the byte total's change / 32.
// FUNCTION: TITANIUM 0x004B8DFD
// @early-stop: budget, structural ndiff=38
void __cdecl DrawNetStatus(unsigned short x_guess,
    unsigned short y_guess, Request_guess* request_guess) {
    if (g_overlayEnabled_guess != 0) {
        RequestStats_guess stats_guess;
        request_guess->GetStats_guess(&stats_guess);
        int interval_guess = g_clockSource_guess->interval_guess;
        int elapsed_guess = request_guess->GetIdleTime_guess() - 500;
        if (elapsed_guess < 0) {
            elapsed_guess = 0;
        }
        unsigned __int64 total_guess = stats_guess.first_guess + stats_guess.second_guess;
        int delta_guess = ((int)(unsigned int)total_guess -
            (int)(unsigned int)g_previousTotal_guess) / 0x20;
        float fraction_guess = 1.0f - (float)elapsed_guess / interval_guess;
        if (delta_guess != 0) {
            g_previousTotal_guess = total_guess;
        }
        char text_guess[80];
        sprintf(text_guess, "%0.2f%%", (double)(fraction_guess * g_percentScale_guess));
        WriteTextHD2(text_guess, x_guess, y_guess, 0xc);
        sprintf(text_guess, "%ldms", stats_guess.milliseconds_guess);
        WriteTextHD2(text_guess, x_guess + 0x40, y_guess, 0xc);
        DrawNetGraph_guess(x_guess, y_guess + 0x10, 0x80, 3,
            fraction_guess, delta_guess);
    }
}

// Frees the array's data, if any.
// FUNCTION: TITANIUM 0x004B8F2D
void Array_guess::Free_guess() {
    if (data_guess != 0) {
        free(data_guess);
    }
}

// Address of element `index`, or 0 past the count (negative indexes are not checked).
// FUNCTION: TITANIUM 0x004B8F3B
int* Array_guess::Get_guess(int index_guess) {
    if (index_guess < count_guess) {
        return data_guess + index_guess;
    }
    return 0;
}

// Frees the array's data (0x004B8F2D).
// FUNCTION: TITANIUM 0x004B8F50
void Array_guess::FreeThunk_guess() {
    Free_guess();
}

// Tint table from an ini: "Number" entries "Value1"..., default 0xFFFFFF; the top byte is forced to 0xFF.
// FUNCTION: TITANIUM 0x004B8F55
Array_guess* Array_guess::Load_guess(char* source_guess) {
    data_guess = 0;
    TextParser_guess* parser_guess = new TextParser_guess(source_guess, 0);
    count_guess = parser_guess->Get_guess("Number", 0, EQ_GLOBAL(void*, 0x0078E84C));
    if (count_guess > 0) {
        data_guess = (int*)::operator new(count_guess << 2);
        if (count_guess > 0) {
            char key_guess[64];
            int index_guess = 0;
            do {
                sprintf(key_guess, "Value%d", index_guess + 1);
                data_guess[index_guess] = parser_guess->Get_guess(
                    key_guess, 0xffffff, EQ_GLOBAL(void*, 0x0078E84C));
                ((ValueWord_guess*)data_guess)[index_guess].bytes_guess.flag_guess = 0xff;
                index_guess++;
            } while (index_guess < count_guess);
        }
    }
    if (parser_guess != 0) {
        delete parser_guess;
    }
    return this;
}

// The NPC tint table (Resources\npct.ini); also the Array_guess constructor.
// FUNCTION: TITANIUM 0x004B903D
Array_guess* Array_guess::LoadNpc_guess() {
    Load_guess("Resources\\npct.ini");
    return this;
}

// The item tint table (Resources\itmt.ini); also the ItemArray_guess constructor.
// FUNCTION: TITANIUM 0x004B904E
Array_guess* Array_guess::LoadItem_guess() {
    Load_guess("Resources\\itmt.ini");
    return this;
}

// Creates the NPC tint table (Resources\npct.ini, 0x004B903D; 0x00985C50) at startup.
// FUNCTION: TITANIUM 0x004B905F
void __cdecl CreateNpcTintTable_guess() {
    g_cleanupA_guess = (Cleanup_guess*)new Array_guess;
}

// Creates the item tint table (Resources\itmt.ini, 0x004B904E; 0x00985C54) at startup.
// FUNCTION: TITANIUM 0x004B9096
void __cdecl CreateItemTintTable_guess() {
    g_cleanupB_guess = (Cleanup_guess*)new ItemArray_guess;
}

// Deletes the NPC tint table (0x00985C50) and clears the pointer.
// FUNCTION: TITANIUM 0x004B90CD
void __cdecl DestroyNpcTintTable_guess() {
    delete g_cleanupA_guess;
    g_cleanupA_guess = 0;
}

// Deletes the item tint table (0x00985C54) and clears the pointer.
// FUNCTION: TITANIUM 0x004B90EF
void __cdecl DestroyItemTintTable_guess() {
    delete g_cleanupB_guess;
    g_cleanupB_guess = 0;
}

