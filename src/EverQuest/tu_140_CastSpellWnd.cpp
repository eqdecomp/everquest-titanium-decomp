// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 140: a hint from compare/tumap.py.
// CCastSpellWnd (screen "CastSpellWnd"): the nine spell gems CSPW_Spell0-8 and the spell book button.
// Callback_guess, Owner_guess and Panel_guess are this window. Key_guess is a spell (0x985CC8 is the spell
// manager, +0x208 the name), IsReady_guess (0x44D0D0) tests for a spell id 1-9999, and Fetch_guess(i)
// gives the spell in gem i. 0x850C30 is the spell book window, 0x850C24 the cursor attachment (tu_150).
#include <new>
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"

struct Callee_guess {
    // EXTERNAL: TITANIUM 0x005BB140 Callee_guess::SetCheck
    void SetCheck(bool value);
    // EXTERNAL: TITANIUM 0x0059DBF0 Callee_guess::Apply_guess
    void Apply_guess(unsigned int value);
};

struct Owner_guess {
    char pad_0000[0x184];
    Callee_guess* spellBookButton_0184_guess; // 0x184

    void Method_guess();
    void Update_guess();
};

struct Array_guess {
    int count; // 0x0
    void** entries; // 0x4
    int capacity; // 0x8
    unsigned char flag; // 0xC

    int Count() const { return count; }
    void* Value_guess(int index);
    void** Slot_guess(int index);
    void Grow_guess(int requested);
    // EXTERNAL: TITANIUM 0x0050319B Array_guess::Set_guess
    void Set_guess(int index, int* value);
    // EXTERNAL: TITANIUM 0x00564487 Array_guess::Insert_guess
    void Insert_guess(int index, int* value);
    // EXTERNAL: TITANIUM 0x0050F3F6 Array_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0050F3F6 ??1Array_guess@@QAE@XZ
    ~Array_guess();
};

struct Item_guess {
    int key; // 0x0
    int level; // 0x4
};

struct Node_guess {
    int id; // 0x0
    char name_004[0x40]; // 0x4
    Array_guess children; // 0x44

    Node_guess() {
        children.entries = 0;
        children.count = 0;
        children.capacity = 0;
        children.flag = 1;
    }

    // EXTERNAL: TITANIUM 0x004F924D Node_guess::~Node_guess
    ~Node_guess();
};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::GetKeyboardFlags
    unsigned char GetKeyboardFlags(int first, int second);
};

struct Receiver_guess {
    // EXTERNAL: TITANIUM 0x005217B6 Receiver_guess::Dispatch_guess
    void Dispatch_guess(int value, unsigned char flag);
    // EXTERNAL: TITANIUM 0x0051E0EA Receiver_guess::Notify_guess
    void Notify_guess();
};

struct Value_guess {
    int fields[4];
};

struct DispatchFrame_guess {
    Value_guess value;
    int message[2];
};

struct Point_guess {
    int x;
    int y;
    Point_guess() : x(0), y(0) {}
    Point_guess(int px, int py) : x(px), y(py) {}
};

struct EntrySlots_guess {
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
    virtual void Slot48_guess(int state, int flag);
};

struct Entry_guess : EntrySlots_guess {
    char pad_0004[0x59];
    unsigned char flag_05D; // 0x5D
    char pad_005E[0x78 - 0x5E];
    CXStr text_078; // 0x78
    // EXTERNAL: TITANIUM 0x0059D960 Entry_guess::GetScreenRect
    Value_guess* GetScreenRect(Value_guess* result);
    // EXTERNAL: TITANIUM 0x005A02F0 Entry_guess::Apply_guess
    void Apply_guess(void* value);
    // EXTERNAL: TITANIUM 0x00558A18 Entry_guess::SetFadeMode_guess
    void SetFadeMode_guess(int value);
    // EXTERNAL: TITANIUM 0x00558984 Entry_guess::SetSpellIcon_guess
    void SetSpellIcon_guess(int id);
    // EXTERNAL: TITANIUM 0x005589AB Entry_guess::SetSpellGemTint_guess
    void SetSpellGemTint_guess(int color);
    char pad_007C[0x188 - 0x7C];
    int state_188; // 0x188
    int state_18C; // 0x18C
};

struct Position_guess {
    int first;
    int second;
    int x;
    int y;
    int x2;
    int y2;

    // EXTERNAL: TITANIUM 0x004D9160 Position_guess::Copy_guess
    void Copy_guess(Value_guess* destination, const Value_guess& source);
};

struct Frame_guess {
    Value_guess destination;
    Value_guess source;
    Position_guess position;
};

struct Child_guess;

// EXTERNAL: TITANIUM 0x00652190 ??_7Callback_guess@@6B@
// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct Callback_guess : CSidlScreenWndBase {
    int field_15C; // 0x15C
    Entry_guess* entries[9];
    CXWnd* field_184;
    Array_guess values_188; // 0x188
    int field_198;
    int field_19C;
    int field_1A0;
    int field_1A4;
    Child_guess* child_1A8;
    Child_guess* child_1AC;
    Child_guess* child_1B0;

    int PostDraw_guess();
    bool AboutToShow_guess();
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
    void Dispatch_guess(int index);
    void Fill_guess(int index);
    void HandleEntry_guess(Entry_guess* entry);
    void Refresh_guess(int value);
    // EXTERNAL: TITANIUM 0x004EB9B7 Callback_guess::ShouldDispatch_guess
    bool ShouldDispatch_guess();
    void Tail_guess(int value);
    void RefreshSpellGemButtons_guess();
    void Select_guess(int index);
    void Clear_guess();
    void Rebuild_guess();
    void Place_guess(int value, int first, int second, int flag);
    void Settle_guess();

    virtual ~Callback_guess();
    void* ScalarDeletingDtor_guess(unsigned flags);
};

struct HandleLootResponse_guess {
    char pad_0000[4];
    int vbaseOffset_0004_guess;
};

#include "titanium/layouts/core.h"
#include "titanium/wnd/CSpellBookWnd.h"
#include "titanium/wnd/CTextEntryWnd.h"

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    ModeContext_guess* GetCharInfo2();
};

struct RootContext_guess {
    // EXTERNAL: TITANIUM 0x00417DAF RootContext_guess::Check_guess
    int Check_guess();
    // EXTERNAL: TITANIUM 0x0040DB0B RootContext_guess::IsBardSong_guess
    int IsBardSong_guess(int key, unsigned char mode);
    // EXTERNAL: TITANIUM 0x0040F8A0 RootContext_guess::Reset_guess
    void Reset_guess(int value);
    // EXTERNAL: TITANIUM 0x004106A3 RootContext_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int a, int b, int c, int d);
    // EXTERNAL: TITANIUM 0x00411F3D RootContext_guess::CastSpell
    void CastSpell(int index, int value, int a, Value_guess range, int c);
};

struct Target_guess;

struct Root_guess {
    char pad_0000[8];
    union {
        HandleLootResponse_guess* route_008;
        unsigned char target_008[0xc278];
    };

    Target_guess* TargetAt_guess(int offset) {
        return reinterpret_cast<Target_guess*>(&target_008[offset]);
    }

    // EXTERNAL: TITANIUM 0x004BACFB Root_guess::Check_guess
    unsigned char Check_guess(int key);
    RootContext_guess context_c280;
};

struct Target_guess {
    char pad_0000[4];
    EQ_CharacterProfileView_guess state_004;
    // EXTERNAL: TITANIUM 0x004167E2 Target_guess::Ready_guess
    int Ready_guess();
    // EXTERNAL: TITANIUM 0x0040E705 Target_guess::GetMemorizedSpell_guess
    int GetMemorizedSpell_guess(int value);
    // EXTERNAL: TITANIUM 0x0041AA54 Target_guess::Fetch2_guess
    int Fetch2_guess(int index);
    // EXTERNAL: TITANIUM 0x004586A5 Target_guess::Sync_guess
    void Sync_guess(int value, int limit);
};

struct ManagerData_guess {
    char pad_0000[0xe8];
    int array_e8[9]; // 0xe8
    char pad_010C[4];
    int field_110; // 0x110
    char pad_0114[0xe84];
    int castingSpellId_0f98_guess; // 0xf98
};

struct Manager_guess {
    char pad_0000[0x1a8];
    ManagerData_guess* data_1a8;

    // EXTERNAL: TITANIUM 0x0047E8E0 Manager_guess::Flush_guess
    void Flush_guess();
};

struct Limit_guess {
    char pad_0000[0x148];
    unsigned int count_148; // 0x148
};

struct Screen_guess {
    char pad_0000[0x15c];
    int state_15C; // 0x15C
    int field_160; // 0x160

    // EXTERNAL: TITANIUM 0x004FD36C Screen_guess::IsOkToActivate_guess
    unsigned char IsOkToActivate_guess(int id);
    // EXTERNAL: TITANIUM 0x004FD91E Screen_guess::Open_guess
    void Open_guess(int a, int id, int index, const char* name, int color);
};

struct Key_guess {
    char pad_0000[0x19c];
    int field_19C; // 0x19C
    int field_1A0; // 0x1A0
    int field_1A4; // 0x1A4
    char pad_01A8[0x60];
    int name_0208_guess; // 0x208
    char pad_020C[0x3c];
    int field_248; // 0x248

    // EXTERNAL: TITANIUM 0x0044E755 Key_guess::Map_guess
    unsigned char Map_guess(unsigned char mode);
    // EXTERNAL: TITANIUM 0x0044D103 Key_guess::GetSpellColor_guess
    unsigned long GetSpellColor_guess();
};

struct KeyLookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 KeyLookup_guess::GetKey_guess
    int GetKey_guess(int value);
    // EXTERNAL: TITANIUM 0x0040CBD6 KeyLookup_guess::Find_guess
    Key_guess* Find_guess(int value);
};

struct Dispatcher_guess {
    // EXTERNAL: TITANIUM 0x005ADC20 Dispatcher_guess::Apply_guess
    void Apply_guess(int index, int* value, Callback_guess* owner);
    // EXTERNAL: TITANIUM 0x005AD7F0 Dispatcher_guess::ReleaseIndex_guess
    void ReleaseIndex_guess(int index, int flag);
    // EXTERNAL: TITANIUM 0x005AD5A0 Dispatcher_guess::Lookup_guess
    int Lookup_guess(void* object);
};

struct Rect_guess {
    int left;
    int top;
    int right;
    int bottom;

    Rect_guess(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

struct Child_guess : CListWnd {
    char pad_0140[0x1a8 - 0x140];

    // EXTERNAL: TITANIUM 0x005BFAE0 Child_guess::Child_guess
    Child_guess(int a, int b, const Rect_guess& rect);
    // EXTERNAL: TITANIUM 0x005BFCF0 Child_guess::Text_guess
    void Text_guess(const CXStr& text, int value, int a, int b);
    // EXTERNAL: TITANIUM 0x005BFEF0 Child_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x005BFF10 Child_guess::SetFlag_guess
    void SetFlag_guess(int which, bool value);
};

struct Panel_guess {
    char pad_0000[0x1a0];
    int field_1A0;
    int pad_1A4;
    Child_guess* child_1A8;
    Child_guess* child_1AC;
    Child_guess* child_1B0;

    void Build_guess();
    void Refresh_guess();
};

struct Slot_guess {
    char text_000[0x19]; // 0x0
    unsigned char flag_019; // 0x19
    unsigned char flag_01A; // 0x1A
    char pad_01B[0x40 - 0x1B];
};

struct TextSource_guess {
    // EXTERNAL: TITANIUM 0x00560D80 TextSource_guess::GetEntryText_guess
    CXStr GetEntryText_guess();
};

struct Sorter_guess {
    // EXTERNAL: TITANIUM 0x00494DA9 Sorter_guess::Sort_guess
    void Sort_guess();
};

#define gSlots_guess EQ_ARRAY(Slot_guess, 0x00984828)

#define gMode_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define gStatus_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)
#define pinstCItemDisplayManager_guess EQ_GLOBAL(Receiver_guess*, 0x00991B88)
#define gConnection_guess EQ_GLOBAL(int, 0x00905CA0)
#define gConnectionState_guess EQ_GLOBAL(int, 0x009248D0)
#define gRoot_guess EQ_GLOBAL(Root_guess*, 0x00905D00)
#define pinstCContextMenuManager_guess EQ_GLOBAL(Dispatcher_guess*, 0x0099D414)
#define gManager_guess EQ_GLOBAL(Manager_guess*, 0x00905CE4)
#define gKeyLookup_guess EQ_GLOBAL(KeyLookup_guess*, 0x00985CC8)
#define pinstCCursorAttachment_guess EQ_GLOBAL(Screen_guess*, 0x00850C24)
#define gLimit_guess EQ_GLOBAL(Limit_guess*, 0x00905D24)
#define gConnectionState2_guess EQ_GLOBAL(int, 0x009248D4)
#define gSlotValues_guess EQ_ARRAY(int, 0x00984804)

// EXTERNAL: TITANIUM 0x0060E985 Allocate_guess
void* __cdecl Allocate_guess(unsigned int size);

// EXTERNAL: TITANIUM 0x0060D682 Release_guess
void __cdecl Release_guess(void* memory);

// EXTERNAL: TITANIUM 0x00405492 ThrowSelf_guess
__declspec(noreturn) void __cdecl ThrowSelf_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0046DA4A FormatInt_guess
void __cdecl FormatInt_guess(char* output, unsigned int id, int first, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);

// EXTERNAL: TITANIUM 0x0044D0D0 IsReady_guess
char __cdecl IsReady_guess(int value);

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0046DA4A FormatStr_guess
void __cdecl FormatStr_guess(char* output, unsigned int id, const char* text, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
char* __cdecl CopyText_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x00574950 CompareText_guess
int __cdecl CompareText_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060E620 strncpy
extern "C" char* __cdecl strncpy(char* destination, const char* source, unsigned int count);

// EXTERNAL: TITANIUM 0x00574460 CompareData_guess
int __cdecl CompareData_guess(const char* first, const char* second);

struct DbStringManager_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DbStringManager_guess::GetString_guess
    char* GetString_guess(int index, int category, int flags);
};

#define g_dbStringManager_guess EQ_GLOBAL(DbStringManager_guess*, 0x00850398)

struct Pair_guess {
    int first;
    int second;
};

struct WindowData_guess {
    char pad_0000[0x60];
    int flags_060;
};

struct WindowBase_guess {
    virtual ~WindowBase_guess();
    // EXTERNAL: TITANIUM 0x005A3100 WindowBase_guess::~WindowBase_guess
    // EXTERNAL: TITANIUM 0x005A3850 WindowBase_guess::WindowBase_guess
    WindowBase_guess(CXWnd* parent, const CXStr& name, int x, int y, int z);
};

// EXTERNAL: TITANIUM 0x00652190 ??_7CastSpellWnd_guess@@6B@
struct CastSpellWnd_guess : WindowBase_guess {
    char pad_0004[0x14];
    unsigned char field_018;
    char pad_0019[0x47];
    int field_060;
    int flags_064;
    char pad_0068[0xbc];
    WindowData_guess* data_124;
    char pad_0128[0x38];
    void* spellSlots_160[9];
    void* spellBook_184;
    int fields_188[3];
    unsigned char field_194;
    char pad_0195[3];
    int field_198;
    int field_19c;
    int field_1a0;
    int field_1a4;
    int field_1a8;
    int field_1ac;
    int field_1b0;

    CastSpellWnd_guess(CXWnd* parent);
};

// While the keys in mask 0x0C are held, gives each gem a point just right of its top-right corner
// (0x5A02F0), probably to place its name label.
// FUNCTION: TITANIUM 0x004EB4CA
int Callback_guess::PostDraw_guess() {
    if (gMode_guess->GetKeyboardFlags() & 0x0c) {
        Frame_guess frame;
        frame.position.x2 = 0;
        frame.position.y2 = 0;
        frame.position.y = 0;
        frame.position.x = 0;
        frame.position.second = 0;
        frame.position.first = 0;
        Entry_guess** current = entries;
        for (int count = 9; count != 0; --count, ++current) {
            if (*current != 0) {
                frame.position.Copy_guess(&frame.destination, *(*current)->GetScreenRect(&frame.source));
                frame.position.x2 = frame.position.x + 2;
                frame.position.y2 = frame.position.second + 2;
                (*current)->Apply_guess(&frame.position.x2);
            }
        }
    }
    return 0;
}

// Asks the server to memorize up to 9 spells (OP_LoadSpellSet 0x403E: 9 spell ids, then the count). Skipped
// while a memorize request is still unanswered (0x9248D0).
// FUNCTION: TITANIUM 0x004EB547
void __cdecl SendValues_guess(const int* values, int count) {
    if (gConnectionState_guess == 0) {
        int message[10];
        if (count > 9) {
            count = 9;
        }
        message[9] = count;
        if (count > 0) {
            for (int index = 0; index < count; ++index) {
                message[index] = values[index];
            }
        }
        EQSendMessage(&gConnection_guess, OP_LoadSpellSet, message, 0x28, 1);
    }
}

// Cast spell window: pops the CSPW_SpellBook button (+0x184) back out (0x005BB140 with 0). The spell
// book window calls it when it closes or refuses to open.
// FUNCTION: TITANIUM 0x004EB590
void Owner_guess::Method_guess() {
    if (spellBookButton_0184_guess != 0) {
        spellBookButton_0184_guess->SetCheck(0);
    }
}

struct State_guess {
    // EXTERNAL: TITANIUM 0x005BA300 State_guess::Value_guess
    unsigned int Value_guess();
};

struct Pool_guess {
    // EXTERNAL: TITANIUM 0x004B2459 Pool_guess::Acquire_guess
    State_guess* Acquire_guess(int value);
    // EXTERNAL: TITANIUM 0x004B244F Pool_guess::Release_guess
    State_guess* Release_guess(int value, unsigned int state);
};

#define g_pool_guess EQ_GLOBAL(Pool_guess*, 0x0098599C)

// Cast spell window: refreshes the CSPW_SpellBook button's hotkey text (0x0059DBF0) from the key map
// entries of command 0x81 (0x004B2459, 0x004B244F). Run when key bindings change (0x004382FC) and when
// the gems are rebuilt (0x004ECAB5).
// FUNCTION: TITANIUM 0x004EB5A2
// @early-stop: budget, diff ndiff=15
void Owner_guess::Update_guess() {
    if (spellBookButton_0184_guess == 0) {
        return;
    }
    int operation = 0x81;
    Pool_guess* pool = g_pool_guess;
    State_guess* state = pool->Acquire_guess(operation);
    state = pool->Release_guess(operation, state->Value_guess());
    spellBookButton_0184_guess->Apply_guess(state->Value_guess());
}

// Builds the spell book button's right-click menu: a load-set submenu (ids 0x13EC-0x13F5), Save (0x14B4)
// and a delete-set submenu (0x1450-0x1459).
// FUNCTION: TITANIUM 0x004EB5EA
void Panel_guess::Build_guess() {
    child_1A8 = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
    child_1AC = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
    child_1B0 = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
    int value = pinstCContextMenuManager_guess->Lookup_guess(child_1AC);
    child_1A8->Text_guess(pStringTable->getString(0xc7c, 0), value + 0x80000000, 0, -1);
    child_1A8->Text_guess(pStringTable->getString(0xc7d, 0), 0x14b4, 0, -1);
    value = pinstCContextMenuManager_guess->Lookup_guess(child_1B0);
    child_1A8->Text_guess(pStringTable->getString(0xc7e, 0), value + 0x80000000, 0, -1);
    field_1A0 = pinstCContextMenuManager_guess->Lookup_guess(child_1A8);
}

// Refills the load and delete submenus with the 10 saved spell sets (64-byte records at 0x984804: 9 spell
// ids, then the name and an in-use flag), and greys them out when there are none.
// FUNCTION: TITANIUM 0x004EB804
void Panel_guess::Refresh_guess() {
    child_1AC->Reset_guess();
    child_1B0->Reset_guess();
    int count = 0;
    int id = 0x1450;
    Slot_guess* slot = gSlots_guess;
    for (int remaining = 10; remaining != 0; --remaining) {
        if (slot->flag_019 != 0) {
            ++count;
            child_1AC->Text_guess(slot->text_000, id - 100, 0, -1);
            child_1B0->Text_guess(slot->text_000, id, 0, -1);
        }
        ++slot;
        ++id;
    }
    child_1A8->SetFlag_guess(0, count > 0);
    child_1A8->SetFlag_guess(2, count > 0);
}

// Pointer array: returns the entry at `index`; an index out of range (or no storage) throws
// (0x00405492). The cascade menu rebuild, the memorize and ability menus and the skills window's rank
// texts read their lists through it.
// FUNCTION: TITANIUM 0x004EB905
void* Array_guess::Value_guess(int index) {
    if (index < count && index >= 0 && entries != 0) {
        return entries[index];
    }
    ThrowSelf_guess();
}

// Pointer array: returns the address of the entry at `index`; an index out of range (or no storage)
// throws (0x00405492). A shared helper with over 200 callers across the client.
// FUNCTION: TITANIUM 0x004EB924
void** Array_guess::Slot_guess(int index) {
    if (index < count && index >= 0 && entries != 0) {
        return entries + index;
    }
    ThrowSelf_guess();
}

// Grows the pointer array to room for twice the request plus 8.
// FUNCTION: TITANIUM 0x004EB943
void Array_guess::Grow_guess(int requested) {
    if (requested != 0 && (requested > capacity || entries == 0)) {
        void** replacement = (void**)Allocate_guess(requested * 8 + 0x20);
        if (replacement != 0) {
            if (entries != 0) {
                int index = 0;
                if (count > index) {
                    do {
                        replacement[index] = entries[index];
                        ++index;
                    } while (index < count);
                }
            }
            Release_guess(entries);
            entries = replacement;
            capacity = requested * 2 + 8;
        } else {
            Release_guess(entries);
            entries = 0;
            capacity = 0;
            flag = 0;
        }
    }
}

// True while a song you may stop is playing: the player's +0x119C is 8 (probably the class, 8 = bard)
// and the spell being cast (+0xF98) passes 0x40DB0B. Gem clicks then stop the song instead of failing.
// FUNCTION: TITANIUM 0x004EB9B7
bool __cdecl ShouldDispatch_guess() {
    if (gRoot_guess != 0 && gManager_guess != 0 && gManager_guess->data_1a8 != 0) {
        ModeContext_guess* context;
        {
            Target_guess* target = reinterpret_cast<Target_guess*>(
                reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess);
            context = target->state_004.GetCharInfo2();
        }
        if (context->class_119c_guess == 8) {
            if (IsReady_guess(gManager_guess->data_1a8->castingSpellId_0f98_guess)) {
                int key = gKeyLookup_guess->GetKey_guess(gManager_guess->data_1a8->castingSpellId_0f98_guess);
                {
                    Target_guess* target = reinterpret_cast<Target_guess*>(
                        reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess);
                    context = target->state_004.GetCharInfo2();
                }
                if (gRoot_guess->context_c280.IsBardSong_guess(key, context->class_119c_guess)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Turns the category tree into the gem's memorize menu: category, subcategory, then "level - name" items
// with id spell id + 10000.
// FUNCTION: TITANIUM 0x004EBA70
void Callback_guess::Settle_guess() {
    if (values_188.Count() < 1) {
        return;
    }
    Child_guess* root = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
    for (int index = 0; index < values_188.Count(); ++index) {
        Node_guess* node = (Node_guess*)*values_188.Slot_guess(index);
        Child_guess* group = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
        for (int childIndex = 0; childIndex < node->children.Count(); ++childIndex) {
            Node_guess* child = (Node_guess*)*node->children.Slot_guess(childIndex);
            Child_guess* list = new Child_guess(0, 0, Rect_guess(0, 0, 50, 10));
            for (int itemIndex = 0; itemIndex < child->children.Count(); ++itemIndex) {
                Item_guess* item = (Item_guess*)*child->children.Slot_guess(itemIndex);
                Key_guess* key = gKeyLookup_guess->Find_guess(item->key);
                char buffer[128];
                sprintf(buffer, "%02d - %s", item->level, key->name_0208_guess);
                unsigned long color = key->GetSpellColor_guess();
                list->Text_guess(buffer, item->key + 10000, 0, color);
                list->SetColors(-1, -1, 0xffffff00);
            }
            int value = pinstCContextMenuManager_guess->Lookup_guess(list);
            group->Text_guess(child->name_004, value + 0x80000000, 0, -1);
        }
        int value = pinstCContextMenuManager_guess->Lookup_guess(group);
        root->Text_guess(node->name_004, value + 0x80000000, 0, -1);
    }
    field_198 = pinstCContextMenuManager_guess->Lookup_guess(root);
}

// Shows the spell in the clicked gem through 0x991B88 (tu_174), probably the spell info window.
// FUNCTION: TITANIUM 0x004EBE36
void Callback_guess::HandleEntry_guess(Entry_guess* entry) {
    int index = 0;
    do {
        if (entry == entries[index]) {
            int result = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index);
            if (IsReady_guess(result)) {
                pinstCItemDisplayManager_guess->Dispatch_guess(
                    reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index),
                    !(gStatus_guess->GetKeyboardFlags(1, -1) & 1));
            }
            return;
        }
        ++index;
    } while (index < 9);
}

// Forgets the spell in gem `value`: OP_MemorizeSpell 0x308E {gem, spell, 2 = forget}. Counts the request
// as pending (0x9248D0) until the server answers.
// FUNCTION: TITANIUM 0x004EBEAE
void __cdecl Notify_guess(int value) {
    int result = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(value);
    if (IsReady_guess(result) && gConnectionState_guess == 0) {
        int message[4];
        message[0] = value;
        message[1] = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(value);
        message[2] = 2;
        EQSendMessage(&gConnection_guess, OP_MemorizeSpell, message, 0x10, 1);
        ++gConnectionState_guess;
    }
}

// Right click on a gem: an empty gem pops the memorize menu at its right edge and remembers the gem
// (+0x19C); a loaded gem forgets its spell.
// FUNCTION: TITANIUM 0x004EBF26
void Callback_guess::Dispatch_guess(int index) {
    int result = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index);
    if (!IsReady_guess(result)) {
        if (field_198 >= 0) {
            Entry_guess* entry = entries[index];
            Point_guess point;
            Value_guess rect;
            entry->GetScreenRect(&rect);
            point = Point_guess(rect.fields[2], (rect.fields[3] - rect.fields[1]) / 2 + rect.fields[1]);
            field_19C = index;
            pinstCContextMenuManager_guess->Apply_guess(field_198, &point.x, this);
        }
    } else {
        Notify_guess(index);
    }
}

// Files spell `value` under category `first` and subcategory `second` (names are db strings of kind 5).
// Categories and subcategories stay in name order, spells in descending level (`flag`).
// FUNCTION: TITANIUM 0x004EC239
// @early-stop: budget, structural ndiff=92
void Callback_guess::Place_guess(int value, int first, int second, int flag) {
    if (second == 0)
        return;
    if (first == 0)
        return;
    Pair_guess* pair = new Pair_guess();
    pair->first = value;
    value = -1;
    pair->second = flag;
    char name[64];
    strncpy(name, g_dbStringManager_guess->GetString_guess(first, 5, 0), 0x3f);
    name[63] = 0;
    int index = 0;
    if (values_188.count > 0) {
        do {
            Node_guess* current = (Node_guess*)*values_188.Slot_guess(index);
            if (current->id == first) {
                break;
            }
            if (value == -1 && CompareData_guess(
                    name, ((Node_guess*)*values_188.Slot_guess(index))->name_004) < 0) {
                value = index;
            }
            ++index;
        } while (index < values_188.count);
    }
    Node_guess* node = 0;
    if (index < values_188.count) {
        Node_guess* found = (Node_guess*)*values_188.Slot_guess(index);
        if (found->id == first) {
            node = found;
        }
    }
    if (node == 0) {
        Node_guess* created = new Node_guess;
        created->id = first;
        CopyText_guess(created->name_004, name);
        if (value == -1)
            values_188.Set_guess(values_188.count, (int*)&created);
        else
            values_188.Insert_guess(value, (int*)&created);
        node = created;
    }
    Node_guess* parent = node;
    value = -1;
    strncpy(name, g_dbStringManager_guess->GetString_guess(second, 5, 0), 0x3f);
    name[63] = 0;
    int childIndex = 0;
    if (parent->children.count > 0) {
        do {
            Node_guess* child = (Node_guess*)*parent->children.Slot_guess(childIndex);
            if (child->id == second) {
                Array_guess* grand = &((Node_guess*)*parent->children.Slot_guess(childIndex))->children;
                int pairIndex = 0;
                if (grand->count > 0) {
                    do {
                        Pair_guess* existing = (Pair_guess*)*grand->Slot_guess(pairIndex);
                        if (existing->second < pair->second) {
                            grand->Insert_guess(pairIndex, (int*)&pair);
                            return;
                        }
                        ++pairIndex;
                    } while (pairIndex < grand->count);
                }
                grand->Set_guess(grand->count, (int*)&pair);
                return;
            }
            if (value == -1 && CompareData_guess(
                    name, ((Node_guess*)*parent->children.Slot_guess(childIndex))->name_004) < 0) {
                value = childIndex;
            }
            ++childIndex;
        } while (childIndex < parent->children.count);
    }
    Node_guess* created = new Node_guess;
    created->id = second;
    strncpy(created->name_004, g_dbStringManager_guess->GetString_guess(second, 5, 0), 0x3f);
    created->name_004[63] = 0;
    created->children.Set_guess(created->children.count, (int*)&pair);
    if (value == -1)
        parent->children.Set_guess(parent->children.count, (int*)&created);
    else
        parent->children.Insert_guess(value, (int*)&created);
}

// Sets each gem's text (+0x78, probably the tooltip): "<gem>) <spell name>", or string 0xD2D with the
// gem number for an empty gem. `index` -1 means all nine.
// FUNCTION: TITANIUM 0x004EBFB5
void Callback_guess::Fill_guess(int index) {
    int first = 0;
    int last = 9;
    if (gRoot_guess != 0) {
        if (index > -1) {
            first = index;
            last = index + 1;
        }
        for (int i = first; i < last; ++i) {
            if (entries[i] == 0) {
                break;
            }
            if (IsReady_guess(reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(i))) {
                Key_guess* key = gKeyLookup_guess->Find_guess(
                    reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(i));
                if (key != 0) {
                    char buffer[512];
                    sprintf(buffer, "%d) %s", i + 1, key->name_0208_guess);
                    CXStr text(buffer);
                    Entry_guess* entry = entries[i];
                    entry->text_078 = text;
                }
            } else {
                char buffer[256];
                FormatStr_guess(buffer, 0xd2d, _itoa(i + 1, EQ_ARRAY(char, 0x0099DB00), 10), 0, 0, 0, 0, 0, 0, 0, 0);
                CXStr text(buffer);
                Entry_guess* entry = entries[i];
                entry->text_078 = text;
            }
        }
    }
}

// Clears gem `value` (the server confirmed the forget, probably): a chat line naming the spell (string
// 0x30D0), then the gem is emptied and redrawn; a bard's song is also stopped.
// FUNCTION: TITANIUM 0x004EC497
void Callback_guess::Refresh_guess(int value) {
    char buffer[512];
    if (IsReady_guess(reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(value))) {
        if (gKeyLookup_guess->Find_guess(
                reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(value))->name_0208_guess != 0) {
            FormatInt_guess(buffer, 0x30d0, gKeyLookup_guess->Find_guess(
                reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(value))->name_0208_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer, 0x108, 1);
        }
        reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->Sync_guess(value, -1);
        if (ShouldDispatch_guess()) {
            gRoot_guess->context_c280.Reset_guess(0);
        }
    }
    Tail_guess(value);
}

// Redraws gem `start` (-1 = all): the spell's gem icon (+0x248) and colour, black when empty.
// FUNCTION: TITANIUM 0x004EC163
// @early-stop: budget, diff ndiff=24
void Callback_guess::Tail_guess(int start) {
    int index = 0;
    int end = 9;
    if (gRoot_guess != 0) {
        if (start > -1) {
            index = start;
            end = start + 1;
        }
        if (index < end) {
            do {
                if (entries[index] == 0) {
                    return;
                }
                start = 0xff000000;
                int id = -1;
                if (IsReady_guess(reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index))) {
                    Key_guess* key = gKeyLookup_guess->Find_guess(
                        reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index));
                    start = key->GetSpellColor_guess();
                    id = key->field_248;
                }
                entries[index]->SetSpellIcon_guess(id);
                entries[index]->SetSpellGemTint_guess(start);
                Fill_guess(index);
                ++index;
            } while (index < end);
        }
    }
}

// Per-frame gem state: lit (2) when the spell is off its own and the global recast timer and nothing is
// being cast, faded (1) otherwise.
// FUNCTION: TITANIUM 0x004EC5A6
// @early-stop: budget, structural ndiff=32
void Callback_guess::RefreshSpellGemButtons_guess() {
    if (gRoot_guess->TargetAt_guess(gRoot_guess->route_008->vbaseOffset_0004_guess)->Ready_guess() == 0) {
        for (int index = 0; index < 9; ++index) {
            if (entries[index] != 0) {
                if (!IsReady_guess(gManager_guess->data_1a8->castingSpellId_0f98_guess)
                    && IsReady_guess(gRoot_guess->TargetAt_guess(gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index))
                    && gLimit_guess->count_148 >= gManager_guess->data_1a8->array_e8[index]
                    && gLimit_guess->count_148 > gManager_guess->data_1a8->field_110
                    && gRoot_guess->Check_guess(gRoot_guess->TargetAt_guess(gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index))) {
                    if (entries[index]->state_188 == -1) {
                        Tail_guess(index);
                        entries[index]->SetFadeMode_guess(2);
                    } else if (entries[index]->state_18C == 1) {
                        entries[index]->SetFadeMode_guess(2);
                    }
                } else {
                    if (entries[index]->state_188 == -1) {
                        Tail_guess(index);
                    }
                    entries[index]->SetFadeMode_guess(1);
                }
            }
        }
        if (gRoot_guess != 0 && entries[8] != 0) {
            int result;
            Entry_guess* entry;
            // The ninth gem is enabled only with ability 0x146 (probably the Mnemonic Retention AA).
            result = gRoot_guess->context_c280.TotalSpellAffects_guess(0x146, 1, 0, 1);
            entry = entries[8];
            if (result != 0) {
                entry->flag_05D = 1;
                entry->Slot48_guess(1, 1);
            } else if (entry->flag_05D != 0) {
                entry->flag_05D = 0;
                entry->Slot48_guess(0, 1);
            }
        }
    }
}

// Frees the memorize menu: releases its menu id (+0x198) and deletes every category node in +0x188 with
// its subnodes.
// FUNCTION: TITANIUM 0x004EC711
void Callback_guess::Clear_guess() {
    if (field_198 != -1) {
        pinstCContextMenuManager_guess->ReleaseIndex_guess(field_198, 1);
        field_198 = -1;
    }
    int index = 0;
    if (values_188.count > 0) {
        int empty = 0;
        do {
            Node_guess* node = (Node_guess*)values_188.Value_guess(index);
            values_188.Set_guess(index, &empty);
            int childIndex = 0;
            if (node->children.count > 0) {
                int emptyChild = 0;
                do {
                    void* child = node->children.Value_guess(childIndex);
                    node->children.Set_guess(childIndex, &emptyChild);
                    if (child != 0) {
                        ((Node_guess*)child)->~Node_guess();
                        free(child);
                    }
                    ++childIndex;
                } while (childIndex < node->children.count);
            }
            node->~Node_guess();
            free(node);
            ++index;
        } while (index < values_188.count);
    }
    values_188.Clear_guess();
}

// Rebuilds the memorize menu from the 400 spell book slots: each spell goes under its category (+0x19C) and
// both of its subcategories (+0x1A0, +0x1A4), at its level for the player's class.
// FUNCTION: TITANIUM 0x004EC7D8
void Callback_guess::Rebuild_guess() {
    Clear_guess();
    for (int index = 0; index < 400; ++index) {
        int value = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->Fetch2_guess(index);
        if (IsReady_guess(value)) {
            int fetched = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->Fetch2_guess(index);
            Key_guess* key = gKeyLookup_guess->Find_guess(fetched);
            int first = key->field_19C;
            int third = key->field_1A0;
            int second = key->field_1A4;
            Target_guess* target = reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess);
            unsigned char flag = key->Map_guess(target->state_004.GetCharInfo2()->class_119c_guess);
            Place_guess(value, first, third, flag);
            Place_guess(value, first, second, flag);
        }
    }
    Settle_guess();
}

// Cast-spell window constructor: builds the children, finds the nine gems CSPW_Spell0-8 and the spell
// book button, then builds the memorize menu (0x004EC7D8) and the spell-set menu (0x004EB5EA).
// FUNCTION: TITANIUM 0x004EC8B4
// @early-stop: budget, structural ndiff=27
CastSpellWnd_guess::CastSpellWnd_guess(CXWnd* parent)
    : WindowBase_guess(parent, "CastSpellWnd", -1, 1, 0) {
    fields_188[0] = 0;
    fields_188[1] = 0;
    fields_188[2] = 0;
    field_194 = 1;
    WindowData_guess* data = data_124;
    field_198 = -1;
    field_19c = -1;
    field_1a0 = -1;
    field_1a8 = 0;
    field_1ac = 0;
    field_1b0 = 0;
    int spellIndex;
    if (data != 0) {
        flags_064 |= data->flags_060 | 0x800;
        field_018 = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        char buffer[256];
        void** slot = spellSlots_160;
        for (spellIndex = 0; spellIndex < 9; ++spellIndex, ++slot) {
            sprintf(buffer, "CSPW_Spell%d", spellIndex);
            *slot = ((CSidlScreenWnd*)this)->GetChildItem(buffer);
        }
        spellBook_184 = ((CSidlScreenWnd*)this)->GetChildItem("CSPW_SpellBook");
        reinterpret_cast<Callback_guess*>(this)->Rebuild_guess();
        reinterpret_cast<Panel_guess*>(this)->Build_guess();
    }
}

// Redraws the gems and rebuilds the menu when the spell list changed (0x417DAF); returns 1 when it did.
// FUNCTION: TITANIUM 0x004ECAB5
bool Callback_guess::AboutToShow_guess() {
    if (gRoot_guess->TargetAt_guess(gRoot_guess->route_008->vbaseOffset_0004_guess)->Ready_guess() != 0) {
        Tail_guess(-1);
        Rebuild_guess();
        return false;
    }
    if (!gRoot_guess->context_c280.Check_guess()) {
        return false;
    }
    field_15C = 0;
    Tail_guess(-1);
    Rebuild_guess();
    reinterpret_cast<Owner_guess*>(this)->Update_guess();
    return true;
}

// Left click on gem `index`. With a spell on the cursor (attachment state 1) it is memorized into the gem
// through the spell book. Otherwise the gem's spell is cast when its recast timers (+0xE8[index], +0x110)
// are past and nothing is being cast; a bard's song is stopped instead, else string 0x2EFD is shown.
// FUNCTION: TITANIUM 0x004ECB56
void Callback_guess::Select_guess(int index) {
    if (pinstCCursorAttachment_guess->state_15C == 1) {
        pinstCSpellBookWnd_guess->StartMemorize_guess(pinstCCursorAttachment_guess->field_160, index, 0);
        return;
    }
    if (IsReady_guess(reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index))) {
        ManagerData_guess* data = gManager_guess->data_1a8;
        unsigned int limit = gLimit_guess->count_148;
        if (limit > data->array_e8[index] && limit > data->field_110 && !IsReady_guess(data->castingSpellId_0f98_guess)) {
            if (gConnectionState_guess == 0 && gConnectionState2_guess == 0) {
                Value_guess range = {0, -1, -1, 0};
                gRoot_guess->context_c280.CastSpell(
                    index,
                    reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(gRoot_guess) + 8 + gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index),
                    0, range, 0);
            }
        } else {
            if (ShouldDispatch_guess()) {
                gManager_guess->Flush_guess();
                gRoot_guess->context_c280.Reset_guess(0);
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x2efd, 0), 0x108, 1);
            }
        }
        RefreshSpellGemButtons_guess();
    }
}

// Destructor of the cast spell window (vtable 0x652190): frees the memorize menu (0x004EC711), releases
// its context menu id (+0x1A0) at the context menu manager (0x99D414), frees the array at +0x188, then
// runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004ECA52
// @early-stop: unknown, structural ndiff=1
Callback_guess::~Callback_guess() {
    Clear_guess();
    if (field_1A0 != -1 && pinstCContextMenuManager_guess != 0) {
        pinstCContextMenuManager_guess->ReleaseIndex_guess(field_1A0, 1);
    }
}

// Scalar deleting destructor of the cast spell window (vtable 0x652190 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x004ECCAA
void* Callback_guess::ScalarDeletingDtor_guess(unsigned flags) {
    this->Callback_guess::~Callback_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Cast-spell window notifications: a gem's left click casts or memorizes (0x004ECB56), a right click
// opens its memorize menu or clears it (0x004EBF26), the book's opens the spell-set menu; drags, the
// set name entry (0x21) and menu picks (0x14) are handled below, the rest goes to CSidlScreenWnd.
// FUNCTION: TITANIUM 0x004ECCC6
// @early-stop: budget, structural ndiff=98
int Callback_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    char errorBuffer[0x204];
    char removeBuffer[0x200];
    char updateBuffer[0x200];
    if (message == 1) {
        // A gem click with the keys in mask 0x0C held opens the spell's info instead; the spell book button
        // toggles the spell book window.
        if (EQ_GLOBAL(CXWndManager*, 0x0099D3EC)->GetKeyboardFlags() & 0x0c) {
            HandleEntry_guess(reinterpret_cast<Entry_guess*>(sender));
            return 0;
        }
        if (sender == field_184) {
            if (pinstCSpellBookWnd_guess->IsVisible_guess()) {
                pinstCSpellBookWnd_guess->Deactivate();
            } else {
                pinstCSpellBookWnd_guess->Activate();
            }
            return 0;
        }
        for (int index = 0; index < 9; ++index) {
            if (sender == reinterpret_cast<CXWnd*>(entries[index])) {
                gManager_guess->Flush_guess();
                Select_guess(index);
                return 0;
            }
        }
    } else if (message == 3) {
        if (sender == field_184 && field_1A0 != -1) {
            reinterpret_cast<Panel_guess*>(this)->Refresh_guess();
            CXRect bounds = field_184->GetScreenRect();
            int position[2];
            position[0] = bounds.right;
            position[1] = (bounds.bottom - bounds.top) / 2 + bounds.top;
            pinstCContextMenuManager_guess->Apply_guess(field_1A0, position, this);
        }
        for (int index = 0; index < 9; ++index) {
            if (sender == reinterpret_cast<CXWnd*>(entries[index])) {
                Dispatch_guess(index);
                return 0;
            }
        }
    // 0x17: a drag starts; the book puts a "Spells" hot button on the cursor, a gem its own spell.
    } else if (message == 0x17) {
        if (sender == field_184) {
            if (pinstCCursorAttachment_guess->IsOkToActivate_guess(5)) {
                pinstCCursorAttachment_guess->Open_guess(0, 5, 10, "Spells", -1);
            }
            return 0;
        }
        for (int index = 0; index < 9; ++index) {
            if (sender == reinterpret_cast<CXWnd*>(entries[index])) {
                if (pinstCCursorAttachment_guess->IsOkToActivate_guess(9)) {
                    pinstCCursorAttachment_guess->Open_guess(0, 9, index, 0, -1);
                    return 0;
                }
                break;
            }
        }
    // 0x18 from a gem also opens the spell's info.
    } else if (message == 0x18) {
        HandleEntry_guess(reinterpret_cast<Entry_guess*>(sender));
        return 0;
    } else if (message == 0x1a) {
        pinstCItemDisplayManager_guess->Notify_guess();
        return 0;
    // 0x21: the set name from the text entry window. Saves the nine gems under that name, reusing a set of
    // the same name or the first free one of 10 (string 0xCA3 when all are used).
    } else if (message == 0x21) {
        if (reinterpret_cast<int>(data) == 1) {
            CXStr text = reinterpret_cast<TextSource_guess*>(sender)->GetEntryText_guess();
            field_1A4 = -1;
            for (int index = 0; index < 10; ++index) {
                if (gSlots_guess[index].flag_019 != 0) {
                    if (CompareText_guess(text, gSlots_guess[index].text_000) == 0) {
                        field_1A4 = index;
                        break;
                    }
                }
                if (field_1A4 == -1 && gSlots_guess[index].flag_019 == 0) {
                    field_1A4 = index;
                }
            }
            if (field_1A4 == -1) {
                FormatStr_guess(errorBuffer, 0xca3, _itoa(10, EQ_ARRAY(char, 0x0099DB00), 10),
                                0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(errorBuffer, 0xd, 1);
                return 0;
            }
            gSlots_guess[field_1A4].flag_019 = 1;
            gSlots_guess[field_1A4].flag_01A = 1;
            CopyText_guess(gSlots_guess[field_1A4].text_000, text);
            for (int index = 0; index < 9; ++index) {
                gSlotValues_guess[field_1A4 * 16 + index] = gRoot_guess->TargetAt_guess(
                    gRoot_guess->route_008->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index);
            }
            FormatStr_guess(updateBuffer, 0xca4, gSlots_guess[field_1A4].text_000,
                            0, 0, 0, 0, 0, 0, 0, 0);
            EQ_GLOBAL(Sorter_guess*, 0x00988DF0)->Sort_guess();
            reinterpret_cast<Panel_guess*>(this)->Refresh_guess();
            pEverQuest->dsp_chat(updateBuffer, 0xf, 1);
        }
    } else if (message == 0x14) {
        int value = reinterpret_cast<int>(data);
        // Menu ids 0x13EC-0x13F5: load saved set N; the spell book memorizes its nine spells (0x557CD8).
        if (value >= 0x13ec && value <= 0x13f5) {
            int index = value - 0x13ec;
            if (gSlots_guess[index].flag_019 != 0 && pinstCSpellBookWnd_guess != 0) {
                pinstCSpellBookWnd_guess->MemorizeSet(&gSlotValues_guess[index * 16], 9);
                FormatStr_guess(removeBuffer, 0x1f4e, gSlots_guess[index].text_000,
                                0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(removeBuffer, 0xf, 1);
            }
            return 0;
        }
        // Menu ids 0x1450-0x1459: delete saved set N.
        if (value >= 0x1450 && value <= 0x1459) {
            int index = value - 0x1450;
            if (gSlots_guess[index].flag_019 != 0) {
                FormatStr_guess(removeBuffer, 0x1f4c, gSlots_guess[index].text_000,
                                0, 0, 0, 0, 0, 0, 0, 0);
                gSlots_guess[index].flag_019 = 0;
                gSlots_guess[index].flag_01A = 1;
                EQ_GLOBAL(Sorter_guess*, 0x00988DF0)->Sort_guess();
                reinterpret_cast<Panel_guess*>(this)->Refresh_guess();
                pEverQuest->dsp_chat(removeBuffer, 0xf, 1);
            }
            return 0;
        }
        // Save: asks for a set name of at most 24 characters (prompt string 0xC7F).
        if (value == 0x14b4) {
            if (pinstCTextEntryWnd_guess != 0) {
                pinstCTextEntryWnd_guess->Activate_guess(this, 0, pStringTable->getString(0xc7f, 0),
                                         1, 0x18, EQ_ARRAY(char, 0x0063F53F));
            }
            return 0;
        }
        // Memorize-menu items: spell id + 10000, memorized into the gem that was right-clicked.
        if (value >= 10000) {
            int index = value - 10000;
            if (IsReady_guess(index)) {
                if (pinstCSpellBookWnd_guess != 0) {
                    pinstCSpellBookWnd_guess->MemorizeSpellById_guess(index, field_19C);
                }
                return 0;
            }
        }
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->CSidlScreenWnd::WndNotification(sender, message, data);
}

