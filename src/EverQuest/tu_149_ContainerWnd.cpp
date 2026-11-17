// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 149: a hint from compare/tumap.py.
// CContainerWnd ("ContainerWindow": bags, world tradeskill containers, the Augmentation Sealer) and the
// container manager CContainerMgrView_guess (0x850CBC: 26 bag windows, the open world container at +0x6C
// and its object's drop id at +0x70). CContainerWndView_guess, Handler_guess,
// Initializer_guess and Selector_guess
// are CContainerWnd views; WindowTitleMenu_guess is the standard window menu. Container type names are at the top.
#include "titanium/types.h"
#include "titanium/slots.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include <string.h>
#include "titanium/wnd/CColorPickerWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CQuantityWnd.h"

#define g_vtable_guess EQ_GLOBAL(char, 0x006533D8)
#define g_vtable2_guess EQ_GLOBAL(char, 0x006531A0)
#define pinstCXWndManager_guess EQ_GLOBAL(struct GlobalMode_guess*, 0x0099D3EC)

struct Entry_guess {
    char pad_guess[0x120];
    int flags_guess;
    char pad2_guess[0x1c];
    struct EntryPayload_guess* payload_guess;
    unsigned char IsAvailable_guess();
    void* GetValue_guess(struct Value_guess* result_guess);
    void Apply_guess(struct Payload_guess* payload_guess);
};

struct EntryPayload_guess {
    char pad_guess[0x10];
    int* value_guess;
};

struct Value_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
};

struct Payload_guess {
    int first_guess;
    int second_guess;
};

struct State_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    void Copy_guess(Value_guess* source_guess, void* value_guess);
};

struct GlobalMode_guess {
    unsigned char GetFlags_guess();
};

struct Handler_guess {
    char pad0_guess[0x15];
    char firstFlag_guess;
    char pad1_guess[0x4c];
    char secondFlag_guess;
    char pad2_guess[0xfd];
    Entry_guess* entries_guess[10];
    int Update_guess();
};

struct ActiveEntry_guess {
    char pad_guess[0x16c];
    int flags_guess;
};

struct Initializer_guess {
    void* vtable_guess;
    char pad_guess[0x15c];
    Entry_guess* entries_guess[10];
    char pad2_guess[8];
    ActiveEntry_guess* active_guess;
    // EXTERNAL: TITANIUM 0x005A3100 Initializer_guess::Finish_guess
    void Finish_guess();
    void Destruct_guess();
    void* Destroy_guess(unsigned char flags_guess);
};

struct Object_guess {
    void* vtable_guess;
    // EXTERNAL: TITANIUM 0x005ADE60 Object_guess::Continue_guess
    void Continue_guess();
    // EXTERNAL: TITANIUM 0x004FCE01 Object_guess::Reset_guess
    void Reset_guess();
    void* Destroy_guess(unsigned char flags_guess);
};

struct ResetBody_guess {
    void* vtable_guess;
    // EXTERNAL: TITANIUM 0x005ADE60 ResetBody_guess::Continue_guess
    void Continue_guess();
    void Reset_guess();
};

struct Node_guess {
    // EXTERNAL: TITANIUM 0x005E06A0 Node_guess::IsActive_guess
    int IsActive_guess();
};

struct Child_guess {
    // EXTERNAL: TITANIUM 0x005EC630 Child_guess::GetEntry_guess
    Node_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 Child_guess::GetEntryEx_guess
    Node_guess* GetEntryEx_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005ECC30 Child_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC640 Child_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005EC650 Child_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC660 Child_guess::Select_guess
    void Select_guess(int value_guess);
};

struct Owner_guess {
    char pad_guess[0x6c];
    Child_guess* child_guess;
    void SetValue_guess(int value_guess, int index_guess);
    int GetValue_guess(int index_guess);
    void Update_guess(int value_guess);
};

struct Rect_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    Rect_guess* Merge_guess(Rect_guess* result_guess, const Rect_guess* other_guess);
    // EXTERNAL: TITANIUM 0x004D9160 Rect_guess::Assign_guess
    void Assign_guess(Rect_guess* temp_guess, const Rect_guess* source_guess);
};

struct CheckerPart_guess {
    char pad_guess[0x5d];
    char value_guess; // 0x5d
};

struct CheckerMask_guess {
    char pad_guess[0x60];
    int mask_guess; // 0x60
};

struct CContainerWndView_guess {
    char pad0_guess[0x64];
    int flags_guess; // 0x64
    char pad1_guess[0xbc];
    CheckerMask_guess* mask_guess; // 0x124
    char pad2_guess[0x34];
    Child_guess* child_guess; // 0x15c
    char pad3_guess[0x2c];
    CheckerPart_guess* part_guess; // 0x18c
    char pad4_guess[0x21];
    char active_guess; // 0x1b1
    char IsActive_guess();
    void Refresh_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x005ADF60 GlobalMode_guess::GetFlags_guess
// EXTERNAL: TITANIUM 0x0059FEC0 Entry_guess::IsAvailable_guess
// EXTERNAL: TITANIUM 0x0059D960 Entry_guess::GetValue_guess
// EXTERNAL: TITANIUM 0x005A02F0 Entry_guess::Apply_guess
// EXTERNAL: TITANIUM 0x004D9160 State_guess::Copy_guess

#define g_table_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::Lookup_guess
    int Lookup_guess(int id_guess, int zero_guess);
};

struct Catalog_guess {
    int GetContainerTypeName_guess(unsigned char key_guess);
};

struct RequestData_guess {
    char pad_000[0x14];
    unsigned char value_014_guess;
    char pad_015[0x6b];
    int value_080_guess;
    char pad_084[0x2c];
    unsigned char value_0b0_guess;
};

struct GaugeOwner_guess;

struct RequestOwner_guess {
    char pad_000[0x114c];
    RequestData_guess* request_guess;
    int requestType_guess;
    int HandleWindowMenu_guess(RequestData_guess* request_guess, int type_guess);
    // EXTERNAL: TITANIUM 0x005AD720 RequestOwner_guess::FUN_005ad720_guess
    int FUN_005ad720_guess(RequestData_guess* request_guess, int type_guess);
};

struct GaugeOwner_guess {
    // EXTERNAL: TITANIUM 0x0054D976 GaugeOwner_guess::FUN_0054d976_guess
    void FUN_0054d976_guess(RequestOwner_guess* owner_guess, int amount_guess,
        int percent_guess, int first_guess, int second_guess, int zero_guess);
};


// Display name of container type `key_guess` (string ids 3400 on): 0-9 bags, chests, quiver, medicine bag;
// 0x18-0x1B the four class lexicons; 0x1F-0x2D the racial forges, kits and pottery wheel; 0x34 Gukta Forge;
// 0x35 Augmentation Sealer. Types 8, 0x1C, 0x1D, 0x25, 0x33 and 0x36 up have no name (0).
// FUNCTION: TITANIUM 0x004FA39A
int Catalog_guess::GetContainerTypeName_guess(unsigned char key_guess) {
    int result_guess;
    switch (key_guess) {
    case 0: result_guess = g_table_guess->Lookup_guess(0xd48, 0); break;
    case 1: result_guess = g_table_guess->Lookup_guess(0xd49, 0); break;
    case 2: result_guess = g_table_guess->Lookup_guess(0xd4a, 0); break;
    case 3: result_guess = g_table_guess->Lookup_guess(0xd4b, 0); break;
    case 4: result_guess = g_table_guess->Lookup_guess(0xd4c, 0); break;
    case 5: result_guess = g_table_guess->Lookup_guess(0xd4d, 0); break;
    case 6: result_guess = g_table_guess->Lookup_guess(0xd4e, 0); break;
    case 7: result_guess = g_table_guess->Lookup_guess(0xd4f, 0); break;
    case 9: result_guess = g_table_guess->Lookup_guess(0xd50, 0); break;
    case 0xa: result_guess = g_table_guess->Lookup_guess(0xd51, 0); break;
    case 0xb: result_guess = g_table_guess->Lookup_guess(0xd52, 0); break;
    case 0xc: result_guess = g_table_guess->Lookup_guess(0xd53, 0); break;
    case 0xd: result_guess = g_table_guess->Lookup_guess(0xd54, 0); break;
    case 0xe: result_guess = g_table_guess->Lookup_guess(0xd55, 0); break;
    case 0xf: result_guess = g_table_guess->Lookup_guess(0xd56, 0); break;
    case 0x10: result_guess = g_table_guess->Lookup_guess(0xd57, 0); break;
    case 0x11: result_guess = g_table_guess->Lookup_guess(0xd58, 0); break;
    case 0x12: result_guess = g_table_guess->Lookup_guess(0xd59, 0); break;
    case 0x13: result_guess = g_table_guess->Lookup_guess(0xd5a, 0); break;
    case 0x14: result_guess = g_table_guess->Lookup_guess(0xd5b, 0); break;
    case 0x15: result_guess = g_table_guess->Lookup_guess(0xd5c, 0); break;
    case 0x16: result_guess = g_table_guess->Lookup_guess(0xd5d, 0); break;
    case 0x17: result_guess = g_table_guess->Lookup_guess(0xd5e, 0); break;
    case 0x18: result_guess = g_table_guess->Lookup_guess(0xd5f, 0); break;
    case 0x19: result_guess = g_table_guess->Lookup_guess(0xd60, 0); break;
    case 0x1a: result_guess = g_table_guess->Lookup_guess(0xd61, 0); break;
    case 0x1b: result_guess = g_table_guess->Lookup_guess(0xd62, 0); break;
    case 0x1e: result_guess = g_table_guess->Lookup_guess(0xd63, 0); break;
    case 0x1f: result_guess = g_table_guess->Lookup_guess(0xd64, 0); break;
    case 0x20: result_guess = g_table_guess->Lookup_guess(0xd65, 0); break;
    case 0x21: result_guess = g_table_guess->Lookup_guess(0xd66, 0); break;
    case 0x22: result_guess = g_table_guess->Lookup_guess(0xd67, 0); break;
    case 0x23: result_guess = g_table_guess->Lookup_guess(0xd68, 0); break;
    case 0x24: result_guess = g_table_guess->Lookup_guess(0xd69, 0); break;
    case 0x26: result_guess = g_table_guess->Lookup_guess(0xd6a, 0); break;
    case 0x27: result_guess = g_table_guess->Lookup_guess(0xd6b, 0); break;
    case 0x28: result_guess = g_table_guess->Lookup_guess(0xd6c, 0); break;
    case 0x2d: result_guess = g_table_guess->Lookup_guess(0xd6d, 0); break;
    case 0x2a: result_guess = g_table_guess->Lookup_guess(0xd6e, 0); break;
    case 0x29: result_guess = g_table_guess->Lookup_guess(0xd6f, 0); break;
    case 0x2b: result_guess = g_table_guess->Lookup_guess(0xd70, 0); break;
    case 0x2c: result_guess = g_table_guess->Lookup_guess(0xd71, 0); break;
    case 0x2e: result_guess = g_table_guess->Lookup_guess(0xd72, 0); break;
    case 0x2f: result_guess = g_table_guess->Lookup_guess(0xd73, 0); break;
    case 0x31: result_guess = g_table_guess->Lookup_guess(0xd74, 0); break;
    case 0x30: result_guess = g_table_guess->Lookup_guess(0xd75, 0); break;
    case 0x32: result_guess = g_table_guess->Lookup_guess(0xd76, 0); break;
    case 0x34: result_guess = g_table_guess->Lookup_guess(0x1699, 0); break;
    case 0x35: result_guess = g_table_guess->Lookup_guess(0xd1f, 0); break;
    default: result_guess = 0; break;
    }
    return result_guess;
}

// Three world-container wrappers (Owner_guess is a CContainerMgrView_guess view, +0x6C the container);
// the index is checked against its slot count.
// Sets item `index_guess` to `value_guess`.
// FUNCTION: TITANIUM 0x004FA6B6
void Owner_guess::SetValue_guess(int value_guess, int index_guess) {
    if (child_guess != 0 && index_guess >= 0) {
        int count_guess = child_guess->GetCount_guess();
        if (index_guess < count_guess) {
            child_guess->SetValue_guess(index_guess, value_guess);
        }
    }
}

// Reads item `index_guess`, 0 when out of range.
// FUNCTION: TITANIUM 0x004FA6E6
int Owner_guess::GetValue_guess(int index_guess) {
    if (child_guess != 0 && index_guess >= 0) {
        int count_guess = child_guess->GetCount_guess();
        if (index_guess < count_guess) {
            return child_guess->GetValue_guess(index_guess);
        }
    }
    return 0;
}

// Selects item `value_guess` (no lower bound check).
// FUNCTION: TITANIUM 0x004FA77F
void Owner_guess::Update_guess(int value_guess) {
    if (child_guess != 0) {
        int count_guess = child_guess->GetCount_guess();
        if (value_guess < count_guess) {
            child_guess->Select_guess(value_guess);
        }
    }
}

// Union (bounding box) of two rects, into `result_guess`.
// FUNCTION: TITANIUM 0x004FACE1
Rect_guess* Rect_guess::Merge_guess(Rect_guess* result_guess, const Rect_guess* other_guess) {
    int first_guess = this->first_guess < other_guess->first_guess ? this->first_guess : other_guess->first_guess;
    int second_guess = this->second_guess < other_guess->second_guess ? this->second_guess : other_guess->second_guess;
    int third_guess = this->third_guess > other_guess->third_guess ? this->third_guess : other_guess->third_guess;
    int fourth_guess = this->fourth_guess > other_guess->fourth_guess ? this->fourth_guess : other_guess->fourth_guess;
    result_guess->first_guess = first_guess;
    result_guess->second_guess = second_guess;
    result_guess->third_guess = third_guess;
    result_guess->fourth_guess = fourth_guess;
    return result_guess;
}

// While keyboard flags 0xC are down (and +0x15, +0x62 are set), calls 0x5A02F0 on every visible item slot
// that holds something, with a point near its corner: x right - 5, y top + 2 for slots sharing the first
// such slot's component 0, else + 22. Probably draws a per-slot overlay; always returns 0.
// FUNCTION: TITANIUM 0x004FAD69
int Handler_guess::Update_guess() {
    if ((pinstCXWndManager_guess->GetFlags_guess() & 0x0c) != 0 && firstFlag_guess != 0 && secondFlag_guess != 0) {
        int remembered_guess = -1;
        Payload_guess payload_guess = { 0, 0 };
        State_guess state_guess;
        state_guess.fourth_guess = 0;
        state_guess.third_guess = 0;
        state_guess.second_guess = 0;
        state_guess.first_guess = 0;
        Value_guess result_guess;
        Value_guess source_guess;
        Entry_guess** current_guess = entries_guess;
        int count_guess = 10;
        do {
            if (*current_guess != 0 && (*current_guess)->IsAvailable_guess() != 0) {
                int* value_guess = (*current_guess)->payload_guess->value_guess;
                if ((value_guess != 0 ? *value_guess : 0) != 0) {
                    state_guess.Copy_guess(&source_guess, (*current_guess)->GetValue_guess(&result_guess));
                    if (remembered_guess == -1) {
                        remembered_guess = state_guess.first_guess;
                    }
                    payload_guess.first_guess = state_guess.third_guess - 5;
                    if (state_guess.first_guess == remembered_guess) {
                        payload_guess.second_guess = state_guess.second_guess + 2;
                    } else {
                        payload_guess.second_guess = state_guess.second_guess + 0x16;
                    }
                    (*current_guess)->Apply_guess(&payload_guess);
                }
            }
            ++current_guess;
            --count_guess;
        } while (count_guess != 0);
    }
    return 0;
}

// Window-menu choices (ids from WindowTitleMenu_guess::Initialize_guess) on `request_guess`'s window: 0xB Tint Color
// opens the colour picker (0x850C0C, probably) on its background colour (+0x80); 0xC Normal Level and
// 0xD Faded Level open the slider (0x850C3C, Activate_guess) at alpha +0xB0 or +0x14, as a percent of 255.
// Other ids go to the base menu (0x5AD720).
// FUNCTION: TITANIUM 0x004FD1CC
int RequestOwner_guess::HandleWindowMenu_guess(RequestData_guess* request_guess, int type_guess) {
    if (request_guess == 0) {
        return 0;
    }
    int value_guess;
    switch (type_guess) {
    case 0xd:
        this->request_guess = request_guess;
        this->requestType_guess = 0xd;
        value_guess = request_guess->value_014_guess;
        break;
    case 0xc:
        this->request_guess = request_guess;
        this->requestType_guess = 0xc;
        value_guess = request_guess->value_0b0_guess;
        break;
    default:
        return FUN_005ad720_guess(request_guess, type_guess);
    case 0xb:
        this->request_guess = request_guess;
        this->requestType_guess = 0xb;
        pinstCColorPickerWnd_guess->Activate_guess(this, request_guess->value_080_guess);
        return 1;
    }
    pinstCQuantityWnd_guess->Function_0054d976_guess(this, 100, value_guess * 100 / 0xff, -1, -1, 0);
    return 1;
}

// Deleting destructor of the window menu (WindowTitleMenu_guess).
// FUNCTION: TITANIUM 0x004FD2AC
void* Object_guess::Destroy_guess(unsigned char flags_guess) {
    Reset_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// WindowTitleMenu_guess destructor body: restores its vtable (0x6533D8), then the base destructor (0x5ADE60).
// FUNCTION: TITANIUM 0x004FCE01
void ResetBody_guess::Reset_guess() {
    vtable_guess = &g_vtable_guess;
    Continue_guess();
}

// Really ~CContainerWnd: clears each item window's slot id (+0x120 = -1) and the icon's animation (+0x16C),
// then CSidlScreenWnd's destructor. The A_DragItem copy (+0x1A0) is not freed here.
// FUNCTION: TITANIUM 0x004FAD2F
void Initializer_guess::Destruct_guess() {
    int count_guess = 10;
    vtable_guess = &g_vtable2_guess;
    Entry_guess** entry_guess = entries_guess;
    do {
        Entry_guess* value_guess = *entry_guess;
        if (value_guess != 0) {
            value_guess->flags_guess |= -1;
        }
        ++entry_guess;
        --count_guess;
    } while (count_guess != 0);
    if (active_guess != 0) {
        active_guess->flags_guess = 0;
    }
    return Finish_guess();
}

// True when some item in the container (+0x15C) fails 0x5E06A0 (GetEntryEx_guess's item, flag 1).
// FUNCTION: TITANIUM 0x004FBD0F
char CContainerWndView_guess::IsActive_guess() {
    int index_guess = 0;
    if (child_guess != 0) {
        do {
            if (child_guess->GetEntry_guess(index_guess) != 0) {
                if (child_guess->GetEntryEx_guess(index_guess, 1)->IsActive_guess() == 0) {
                    return 1;
                }
            }
            ++index_guess;
        } while (index_guess < 10);
    }
    return 0;
}

// Deleting destructor (Initialize_guess is ~CContainerWnd).
// FUNCTION: TITANIUM 0x004FBD6D
void* Initializer_guess::Destroy_guess(unsigned char flags_guess) {
    Destruct_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// The Done button (+0x18C) is enabled only while IsActive_guess is false; meanwhile style bit 8 is cleared,
// and put back from the SIDL style (+0x124) afterwards. Process_guess runs it for world containers.
// FUNCTION: TITANIUM 0x004FBD89
void CContainerWndView_guess::Refresh_guess() {
    char enabled_guess = IsActive_guess() == 0;
    if (part_guess != 0) {
        part_guess->value_guess = enabled_guess;
    }
    if (!enabled_guess) {
        flags_guess &= 0xfffffff7;
        active_guess = enabled_guess;
        return;
    }
    if (active_guess == 0) {
        flags_guess |= mask_guess->mask_guess;
        active_guess = 1;
    }
}

/* ---- CContainerWnd::CContainerWnd(CXWnd*) (0x004FC9A4) ---------------------------------------------
 * Layout: include/titanium/types.h CContainerWnd (size not in the window table: new is elsewhere). */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// A child window called through its vtable (slot 48 at +0xC0, called with (0, 1)).
struct ContainerChildWnd_guess {
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
    virtual void Slot48_guess(int value, int flag);
    char pad_004[0x59];
    char field_05d_guess;
    char pad_05e[6];
    unsigned int WindowStyle;           // 0x064 (CXWnd::WindowStyle)
    char pad_068[0x18];
    unsigned int bgColor_080;               // 0x080 (MQ2 BGColor)
    char pad_084[0x10];
    unsigned int bgType_094;                // 0x094 (MQ2 BGType)
    char pad_098[0xd4];
    void* animation_16c;                    // 0x16c
    // EXTERNAL: TITANIUM 0x0059DD30 ContainerChildWnd_guess::IsReady_guess
    unsigned char IsReady_guess();
};

// CTextureAnimation (0x4C bytes).
struct ContainerAnimation_guess {
    char data[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0ContainerAnimation_guess@@QAE@XZ
    ContainerAnimation_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ??4ContainerAnimation_guess@@QAEAAU0@ABU0@@Z
    ContainerAnimation_guess& operator=(const ContainerAnimation_guess& other);
    // EXTERNAL: TITANIUM 0x005B1AB0 ContainerAnimation_guess::FUN_005b1ab0_guess
    void FUN_005b1ab0_guess(int value);
};

struct ContainerSidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 ContainerSidlManager_guess::FindAnimation_guess
    ContainerAnimation_guess* FindAnimation_guess(const CXStr& name);
};

#define g_containerSidlManager_guess EQ_GLOBAL(ContainerSidlManager_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x006531A0 ??_7ContainerWnd_guess@@6B@
struct ContainerWnd_guess : CSidlScreenWndBase {
    struct ContainerContents_guess* field_15c;  // 0x15c
    CXWnd* slots_160[10];                   // 0x160 ContainerSlot1..10
    CXWnd* combineButton_188;               // 0x188 Container_Combine
    CXWnd* doneButton_18c;                  // 0x18c DoneButton
    ContainerChildWnd_guess* icon_190;      // 0x190 Container_Icon
    ContainerChildWnd_guess* insertButton_194;  // 0x194 InsertButton
    ContainerChildWnd_guess* removeButton_198;  // 0x198 RemoveButton
    ContainerChildWnd_guess* deleteButton_19c;  // 0x19c DeleteButton
    ContainerAnimation_guess* dragAnim_1a0;     // 0x1a0 copy of A_DragItem
    CXWnd* label_1a4;                       // 0x1a4 Container_Label
    ContainerChildWnd_guess* augmentList_1a8;   // 0x1a8 AugmentList
    ContainerChildWnd_guess* augmentInfo_1ac;   // 0x1ac AugmentInfoLabel
    unsigned char field_1b0;                // 0x1b0
    unsigned char field_1b1;                // 0x1b1
    ContainerWnd_guess(CXWnd* parent);
    void Confirm_guess(int mode_guess);
    void SetContainer_guess(struct ContainerContents_guess* contents_guess, int slot_guess);
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
    void UpdateAugments_guess();
    void HandleCombine();
};

struct ContainerItem_guess {
    char pad_guess[0x48];
    int count_guess;                        // 0x48
    // EXTERNAL: TITANIUM 0x005EC760 ContainerItem_guess::IsStackable_guess
    bool IsStackable_guess();
};

struct ContainerContents_guess {
    // EXTERNAL: TITANIUM 0x005EC630 ContainerContents_guess::GetItem_guess
    ContainerItem_guess* GetItem_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005ECC30 ContainerContents_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ContainerContents_guess::GetName_guess
    char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005E0F60 ContainerContents_guess::GetIcon_guess
    int GetIcon_guess();
    // EXTERNAL: TITANIUM 0x005ECCF0 ContainerContents_guess::GetType_guess
    int GetType_guess();
};

struct ContainerCharInfo_guess {
    char pad_guess[0x88];
    int busy_guess;                         // 0x88
};

struct ContainerCharPrefix_guess {
    virtual void slot00_guess() = 0;
    int field04_guess;
};

struct ContainerCharVirtual_guess {
    void* vftable_guess;
    EQ_CharacterProfile_guess profile_guess;
    CHARINFO2* Lookup_guess() {
        return profile_guess.GetCharInfo2();
    }
    // EXTERNAL: TITANIUM 0x0040CC50 ContainerCharVirtual_guess::GetInventorySlot_guess
    ContainerContents_guess* GetInventorySlot_guess(int index_guess);
};

struct ContainerCharData_guess : ContainerCharPrefix_guess, virtual ContainerCharVirtual_guess {
};

#define g_containerCharData_guess EQ_GLOBAL(ContainerCharData_guess*, 0x00905D00)

struct ContainerDisplay_guess {
    char pad_guess[0x11];
    char busy_guess;                        // 0x11
    char pad2_guess[0x136];
    unsigned int time_guess;                // 0x148
    // EXTERNAL: TITANIUM 0x00439C41 ContainerDisplay_guess::TrueDistance_guess
    float TrueDistance_guess(float x1_guess, float y1_guess, float z1_guess,
        float z2_guess, float y2_guess, float x2_guess, float scale_guess);
};

#define g_containerDisplay_guess EQ_GLOBAL(ContainerDisplay_guess*, 0x00905D24)

struct ContainerCursor_guess {
    char pad_guess[0x6c];
    ContainerContents_guess* held_guess;    // 0x6c
};

#define g_containerCursor_guess EQ_GLOBAL(ContainerCursor_guess*, 0x00850CBC)
#define g_containerMessageCount_guess EQ_GLOBAL(int, 0x009248D0)

// EXTERNAL: TITANIUM 0x0046DA4A ContainerFormat_guess
char* __cdecl ContainerFormat_guess(char* buffer_guess, int token_guess,
    const char* p0_guess, const char* p1_guess, const char* p2_guess,
    const char* p3_guess, const char* p4_guess, const char* p5_guess,
    const char* p6_guess, const char* p7_guess, const char* p8_guess);

struct ContainerRequest_guess {
    int slot_guess;
    int selection_guess;
};

// Asks before an Augmentation Sealer action, naming the augment selected in AugmentList: mode 0 insert
// (string 5880, dialog 0x77), 1 destroy (5878, 0x76), 2 remove (5879, 0x78). The dialog carries a new
// {container slot, list row}. Checks as HandleCombine: free hands (12024), no stacks (8504), an item
// (12025). Slot 1000 is the world container (EQEmu SLOT_TRADESKILL_EXPERIMENT_COMBINE); else the
// inventory slot (0-30) of the bag, and an unfound bag does nothing. 0x9248D0 counts pending requests.
// FUNCTION: TITANIUM 0x004FBDD0
void ContainerWnd_guess::Confirm_guess(int mode_guess) {
    if (field_1b0 == 0 || g_containerCharData_guess == 0) {
        return;
    }
    ContainerCharInfo_guess* info_guess =
        (ContainerCharInfo_guess*)g_containerCharData_guess->Lookup_guess();
    if (info_guess->busy_guess == 0 && g_containerDisplay_guess->busy_guess == 0) {
    int slot_guess = 0;
    if (g_containerCursor_guess->held_guess != 0 && g_containerCursor_guess->held_guess == field_15c) {
        slot_guess = 1000;
    } else {
        for (int i = 0; i < 31; i++) {
            if (g_containerCharData_guess->GetInventorySlot_guess(i) == field_15c) {
                slot_guess = i;
            }
        }
        if (slot_guess == 0) {
            return;
        }
    }
    int i;
    for (i = 0; i < 10; i++) {
        ContainerItem_guess* item_guess = field_15c->GetItem_guess(i);
        if (item_guess != 0 && item_guess->IsStackable_guess() && item_guess->count_guess > 1) {
            pConfirmationDialogPool_guess->Activate(0, 0xb, pStringTable->getString(0x2138, 0), 1, 20000, 0, 0);
            return;
        }
    }
    int count_guess = 0;
    for (int j = 0; j < 10; j++) {
        if (j < field_15c->GetCount_guess() && field_15c->GetItem_guess(j) != 0) {
            count_guess++;
        }
    }
    if (count_guess > 0) {
    char text_guess[256] = { 0 };
    char name_guess[128] = { 0 };
    g_containerMessageCount_guess++;
    ContainerRequest_guess* request_guess = new ContainerRequest_guess;
    request_guess->slot_guess = slot_guess;
    request_guess->selection_guess = 0;
    if (augmentList_1a8 != 0) {
        int selection_guess = ((CListWnd*)augmentList_1a8)->GetCurSel();
        request_guess->selection_guess = selection_guess;
        strcpy(name_guess, ((CListWnd*)augmentList_1a8)->GetItemText(selection_guess, 0));
    }
    switch (mode_guess) {
    case 0:
        ContainerFormat_guess(text_guess, 0x16f8, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x77, text_guess, 0xc, -1, (int)request_guess, 1);
        break;
    case 1:
        ContainerFormat_guess(text_guess, 0x16f6, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x76, text_guess, 0xc, -1, (int)request_guess, 1);
        break;
    case 2:
        ContainerFormat_guess(text_guess, 0x16f7, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x78, text_guess, 0xc, -1, (int)request_guess, 1);
        break;
    }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef9, 0));
    }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef8, 0), 0xf, 1);
    }
}

struct ContainerCharState_guess {
    char pad_guess[0x78];
    int busy_guess;                         // 0x78 (0x88 of the info)
    int IsBusy_guess() { return busy_guess; }
};

struct ContainerCharInfoFull_guess {
    char pad_guess[0x10];
    ContainerCharState_guess state_guess;   // 0x10
    char pad2_guess[0x1198 - 0x10 - sizeof(ContainerCharState_guess)];
    int race_1198_guess;                        // 0x1198
    unsigned char classId_119c_guess;               // 0x119c
};

#define CONTAINER_INFO_guess ((ContainerCharInfoFull_guess*)g_containerCharData_guess->Lookup_guess())

// Combine button. Lexicons (0x18-0x1B) need Wizard, Magician, Necromancer or Enchanter (string 12010); the
// racial forges, kits and wheel (0x1F-0x2D) need the race (12011-12023). race_guess (+0x119C) is really the
// class and deity_guess (+0x1198) the race. Gukta Forge (0x34) is not checked here.
// Then the Confirm_guess checks, and OP_TradeSkillCombine with the container slot (4 bytes).
// FUNCTION: TITANIUM 0x004FC106
void ContainerWnd_guess::HandleCombine() {
    if (field_1b0 == 0 || g_containerCharData_guess == 0) {
        return;
    }
    if (field_15c->GetType_guess() == 0x18 && CONTAINER_INFO_guess->classId_119c_guess != 0x0c) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x19 && CONTAINER_INFO_guess->classId_119c_guess != 0x0d) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x1a && CONTAINER_INFO_guess->classId_119c_guess != 0x0b) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x1b && CONTAINER_INFO_guess->classId_119c_guess != 0x0e) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x1f && CONTAINER_INFO_guess->race_1198_guess != 5) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eeb, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x20 && CONTAINER_INFO_guess->race_1198_guess != 6) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eec, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x21 && CONTAINER_INFO_guess->race_1198_guess != 10) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eed, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x22 && CONTAINER_INFO_guess->race_1198_guess != 8) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eee, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x23 && CONTAINER_INFO_guess->race_1198_guess != 0xc) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2eef, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x24 && CONTAINER_INFO_guess->race_1198_guess != 2) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef0, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x26 && CONTAINER_INFO_guess->race_1198_guess != 0x80) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef1, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x27 && CONTAINER_INFO_guess->race_1198_guess != 1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef2, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x28 && CONTAINER_INFO_guess->race_1198_guess != 1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef2, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x2d && CONTAINER_INFO_guess->race_1198_guess != 0x80) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef3, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x2a && CONTAINER_INFO_guess->race_1198_guess != 3) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef4, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x29 && CONTAINER_INFO_guess->race_1198_guess != 0xb) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef5, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x2b && CONTAINER_INFO_guess->race_1198_guess != 4) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef6, 0), 0xf, 1);
        return;
    }
    if (field_15c->GetType_guess() == 0x2c && CONTAINER_INFO_guess->race_1198_guess != 4) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef7, 0), 0xf, 1);
        return;
    }
    if (CONTAINER_INFO_guess->state_guess.IsBusy_guess() != 0 || g_containerDisplay_guess->busy_guess != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ef8, 0), 0xf, 1);
        return;
    }
    {
        int slot_guess = 0;
        // The container's slot: 1000 on the cursor, else its inventory slot; one not found (0) ends here.
        if (g_containerCursor_guess->held_guess != 0 && g_containerCursor_guess->held_guess == field_15c) {
            slot_guess = 1000;
        } else {
            for (int i = 0; i < 31; i++) {
                if (g_containerCharData_guess->GetInventorySlot_guess(i) == field_15c) {
                    slot_guess = i;
                }
            }
            if (slot_guess == 0) {
                return;
            }
        }
        for (int i = 0; i < 10; i++) {
            ContainerItem_guess* item_guess = field_15c->GetItem_guess(i);
            // A stack of more than one inside stops the combine with a 20 s notice (string 8504).
            if (item_guess != 0 && item_guess->IsStackable_guess() && item_guess->count_guess > 1) {
                pConfirmationDialogPool_guess->Activate(0, 0xb, pStringTable->getString(0x2138, 0), 1, 20000, 0, 0);
                return;
            }
        }
        int count_guess = 0;
        for (int j = 0; j < 10; j++) {
            if (j < field_15c->GetCount_guess() && field_15c->GetItem_guess(j) != 0) {
                count_guess++;
            }
        }
        // An empty container gets string 12025 instead of OP_TradeSkillCombine (0xB40).
        if (count_guess > 0) {
            g_containerMessageCount_guess++;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_TradeSkillCombine, &slot_guess, 4, 1);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef9, 0));
        }
    }
}

// The augment controls (Insert/Remove/Delete buttons, AugmentList, AugmentInfoLabel) start hidden;
// SetContainer_guess shows them for the sealer. AugmentList: yellow text, grey highlight, black back.
// FUNCTION: TITANIUM 0x004FC9A4
ContainerWnd_guess::ContainerWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "ContainerWindow") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        field_017_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        label_1a4 = ((CSidlScreenWnd*)this)->GetChildItem("Container_Label");
        icon_190 = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("Container_Icon");
        ContainerAnimation_guess* drag = g_containerSidlManager_guess->FindAnimation_guess("A_DragItem");
        dragAnim_1a0 = new ContainerAnimation_guess;
        if (dragAnim_1a0 != 0) {
            *dragAnim_1a0 = *drag;
            dragAnim_1a0->FUN_005b1ab0_guess(-1);
        }
        if (icon_190 != 0) {
            icon_190->animation_16c = dragAnim_1a0;
        }
        char name[0x80];
        for (int i = 0; i < 10; ++i) {
            sprintf(name, "ContainerSlot%d", i + 1);
            slots_160[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        combineButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("Container_Combine");
        doneButton_18c = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        insertButton_194 = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("InsertButton");
        if (insertButton_194 != 0) {
            insertButton_194->Slot48_guess(0, 1);
        }
        removeButton_198 = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("RemoveButton");
        if (removeButton_198 != 0) {
            removeButton_198->Slot48_guess(0, 1);
        }
        deleteButton_19c = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        if (deleteButton_19c != 0) {
            deleteButton_19c->Slot48_guess(0, 1);
        }
        augmentList_1a8 = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AugmentList");
        if (augmentList_1a8 != 0) {
            ((CListWnd*)augmentList_1a8)->SetColors(-1, 0xffffff00, 0xff808080);
            augmentList_1a8->bgColor_080 = 0xff000000;
            augmentList_1a8->bgType_094 = 2;
            ((CListWnd*)augmentList_1a8)->SetColumnJustification(0, 0);
            augmentList_1a8->WindowStyle &= ~0x200000;
            augmentList_1a8->Slot48_guess(0, 1);
        }
        augmentInfo_1ac = (ContainerChildWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AugmentInfoLabel");
        if (augmentInfo_1ac != 0) {
            augmentInfo_1ac->Slot48_guess(0, 1);
        }
        field_15c = 0;
        field_1b0 = 0;
        FUN_0059db90_guess(100);
        field_1b1 = 1;
    }
}

struct ContainerPoint_guess {
    int x_guess;
    int y_guess;
};

// A window seen through its vtable: slot 48 Show, 63 SetWindowText, 70 layout.
struct ContainerView_guess {
    virtual void V00_guess(); virtual void V01_guess(); virtual void V02_guess(); virtual void V03_guess();
    virtual void V04_guess(); virtual void V05_guess(); virtual void V06_guess(); virtual void V07_guess();
    virtual void V08_guess(); virtual void V09_guess(); virtual void V10_guess(); virtual void V11_guess();
    virtual void V12_guess(); virtual void V13_guess(); virtual void V14_guess(); virtual void V15_guess();
    virtual void V16_guess(); virtual void V17_guess(); virtual void V18_guess(); virtual void V19_guess();
    virtual void V20_guess(); virtual void V21_guess(); virtual void V22_guess(); virtual void V23_guess();
    virtual void V24_guess(); virtual void V25_guess(); virtual void V26_guess(); virtual void V27_guess();
    virtual void V28_guess(); virtual void V29_guess(); virtual void V30_guess(); virtual void V31_guess();
    virtual void V32_guess(); virtual void V33_guess(); virtual void V34_guess(); virtual void V35_guess();
    virtual void V36_guess(); virtual void V37_guess(); virtual void V38_guess(); virtual void V39_guess();
    virtual void V40_guess(); virtual void V41_guess(); virtual void V42_guess(); virtual void V43_guess();
    virtual void V44_guess(); virtual void V45_guess(); virtual void V46_guess(); virtual void V47_guess();
    virtual void Show_guess(int show_guess, int flag_guess);
    virtual void V49_guess(); virtual void V50_guess(); virtual void V51_guess(); virtual void V52_guess();
    virtual void V53_guess(); virtual void V54_guess(); virtual void V55_guess(); virtual void V56_guess();
    virtual void V57_guess(); virtual void V58_guess(); virtual void V59_guess(); virtual void V60_guess();
    virtual void V61_guess(); virtual void V62_guess();
    virtual void SetWindowText_guess(const CXStr& text_guess);
    virtual void V64_guess(); virtual void V65_guess(); virtual void V66_guess(); virtual void V67_guess();
    virtual void V68_guess(); virtual void V69_guess();
    virtual void Layout_guess();
    virtual void V71_guess(); virtual void V72_guess(); virtual void V73_guess(); virtual void V74_guess();
    virtual void V75_guess();
    virtual void DeleteAll_guess();
    char pad_004[0x38];
    int left_guess;                         // 0x3c
    int top_guess;                          // 0x40
    int right_guess;                        // 0x44
    int bottom_guess;                       // 0x48
    char pad_04c[0xd4];
    int index_guess;                        // 0x120
    // EXTERNAL: TITANIUM 0x0059D860 ContainerView_guess::GetRect_guess
    Rect_guess* GetRect_guess(Rect_guess* out_guess) const;
    // EXTERNAL: TITANIUM 0x0059FB00 ContainerView_guess::Move_guess
    void Move_guess(const Rect_guess& rect_guess);
    // EXTERNAL: TITANIUM 0x0059FA70 ContainerView_guess::MoveTo_guess
    void MoveTo_guess(const ContainerPoint_guess& point_guess);
    // EXTERNAL: TITANIUM 0x005A0850 ContainerView_guess::Resize_guess
    void Resize_guess(int width_guess, int height_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 ContainerPrintf_guess
void __cdecl ContainerPrintf_guess(CXStr* text_guess, const char* format_guess, ...);

// Shows `contents_guess`, opened from inventory slot `slot_guess`, or hides the window for 0. The slot
// picks the ini section (BagInv1-8, BagBank, SharedBank, BagTrade, BagWorld, BagViewPC*), a cascade offset
// and the slot ids of the 10 item windows: 251 + 10 x (slot - 22) for the 8 general bags, 2031, 2531 and
// 3031 up for bank, shared bank and trade bags, 9031/10031/10531 up for the BagViewPC* views (probably
// another character's bags); a world container (4000-4030) uses its own slot. Only general and world
// containers may combine (+0x1B0). Combine shows for types 9 up except 0x33 and the sealer (0x35),
// whose AugmentList widens the window. The offsets' signs differ per range; kept as decompiled.
// FUNCTION: TITANIUM 0x004FB700
// @early-stop: budget, structural ndiff=76
void ContainerWnd_guess::SetContainer_guess(ContainerContents_guess* contents_guess, int slot_guess) {
    field_15c = contents_guess;
    if (contents_guess == 0) {
        if (combineButton_188 != 0) {
            ((ContainerView_guess*)combineButton_188)->Show_guess(0, 1);
        }
        if (doneButton_18c != 0) {
            ((ContainerView_guess*)doneButton_18c)->Show_guess(0, 1);
        }
        for (int i = 0; i < 10; i++) {
            ContainerView_guess* slotWnd_guess = (ContainerView_guess*)slots_160[i];
            if (slotWnd_guess != 0) {
                slotWnd_guess->index_guess = -1;
                ((ContainerView_guess*)slots_160[i])->Show_guess(0, 1);
            }
        }
        ((ContainerView_guess*)this)->Resize_guess(0, 0);
        return;
    }
    int base_guess = -1;
    field_1b0 = 0;
    CXStr name_guess("Bag");
    int dx_guess = 0;
    int dy_guess = 0;
    // Ini section, slot-id base and cascade offset by the opening slot's range (see the function comment).
    if (slot_guess != -1) {
        if (slot_guess >= InvSlot_General1 && slot_guess <= InvSlot_General8) {
            base_guess = slot_guess * 10 + 31;
            field_1b0 = 1;
            ContainerPrintf_guess(&name_guess, "BagInv%d", slot_guess - 21);
            dx_guess = (slot_guess - InvSlot_General1) * 5;
            dy_guess = (slot_guess - InvSlot_General1) * 2;
        } else if (slot_guess >= InvSlot_BankBegin && slot_guess < 2031) {
            base_guess = (slot_guess - InvSlot_BankBegin) * 10 + 2031;
            ContainerPrintf_guess(&name_guess, "BagBank%d", slot_guess - 1999);
            dx_guess = (InvSlot_BankBegin - slot_guess) * 5;
            dy_guess = (slot_guess - InvSlot_BankBegin) * 2;
        } else if (slot_guess >= InvSlot_SharedBankBegin && slot_guess < 2531) {
            base_guess = (slot_guess - InvSlot_SharedBankBegin) * 10 + 2531;
            ContainerPrintf_guess(&name_guess, "SharedBank%d", slot_guess - 2499);
            dx_guess = (InvSlot_SharedBankBegin - slot_guess) * 5;
            dy_guess = (slot_guess - InvSlot_SharedBankBegin) * 2;
        } else if (slot_guess >= InvSlot_TradeBegin && slot_guess < 3031) {
            base_guess = (slot_guess - InvSlot_TradeBegin) * 10 + 3031;
            ContainerPrintf_guess(&name_guess, "BagTrade%d", slot_guess - 2999);
            dx_guess = (InvSlot_TradeBegin - slot_guess) * 5;
            dy_guess = (InvSlot_TradeBegin - slot_guess) * 2;
        } else if (slot_guess >= InvSlot_WorldBegin && slot_guess < 4031) {
            ContainerPrintf_guess(&name_guess, "BagWorld%d", slot_guess - 3999);
            base_guess = slot_guess;
            field_1b0 = 1;
            dx_guess = (slot_guess - InvSlot_WorldBegin) * 3;
            dy_guess = (InvSlot_WorldBegin - slot_guess) * 2;
        } else if (slot_guess >= 9000 && slot_guess < 9031) {
            base_guess = (slot_guess - 9000) * 10 + 9031;
            ContainerPrintf_guess(&name_guess, "BagViewPC%d", slot_guess - 8999);
            dx_guess = (9000 - slot_guess) * 5;
            dy_guess = (9000 - slot_guess) * 2;
        } else if (slot_guess >= 10000 && slot_guess < 10031) {
            base_guess = (slot_guess - 10000) * 10 + 10031;
            ContainerPrintf_guess(&name_guess, "BagViewPCBank%d", slot_guess - 9999);
            dx_guess = (10000 - slot_guess) * 5;
            dy_guess = (10000 - slot_guess) * 2;
        } else if (slot_guess >= 10500 && slot_guess < 10531) {
            base_guess = (slot_guess - 10500) * 10 + 10531;
            ContainerPrintf_guess(&name_guess, "BagViewPCSharedBank%d", slot_guess - 10499);
            dx_guess = (10500 - slot_guess) * 5;
            dy_guess = (10500 - slot_guess) * 2;
        }
    }
    // Position is saved per section, so each bag remembers its own place.
    ((CSidlScreenWnd*)this)->EnableIniStorage(0x19, name_guess);
    Rect_guess rect_guess;
    ((ContainerView_guess*)this)->GetRect_guess(&rect_guess);
    rect_guess.first_guess += dx_guess;
    rect_guess.third_guess += dx_guess;
    rect_guess.second_guess += dy_guess;
    rect_guess.fourth_guess += dy_guess;
    ((ContainerView_guess*)this)->Move_guess(rect_guess);
    ((ContainerView_guess*)this)->Layout_guess();
    if (label_1a4 != 0) {
        CXStr text_guess(field_15c->GetName_guess());
        ((ContainerView_guess*)label_1a4)->SetWindowText_guess(text_guess);
    }
    if (dragAnim_1a0 != 0) {
        dragAnim_1a0->FUN_005b1ab0_guess(field_15c->GetIcon_guess() - 500);
    }
    Rect_guess bounds_guess;
    bounds_guess.fourth_guess = 0;
    bounds_guess.third_guess = 0;
    bounds_guess.second_guess = 0;
    bounds_guess.first_guess = 0;
    if (label_1a4 != 0 && icon_190 != 0) {
        Rect_guess iconRect_guess;
        Rect_guess labelRect_guess;
        Rect_guess merged_guess;
        Rect_guess temp_guess;
        bounds_guess.Assign_guess(&temp_guess,
            ((ContainerView_guess*)label_1a4)->GetRect_guess(&labelRect_guess)->Merge_guess(&merged_guess,
                ((ContainerView_guess*)icon_190)->GetRect_guess(&iconRect_guess)));
    }
    for (int i = 0; i < 10; i++) {
        if (slots_160[i] != 0) {
            // Item windows up to the container's slot count get slot id base + i; the rest are hidden.
            if (base_guess != -1 && i < field_15c->GetCount_guess()) {
                ((ContainerView_guess*)slots_160[i])->index_guess = i + base_guess;
                ((ContainerView_guess*)slots_160[i])->Show_guess(1, 1);
                Rect_guess slotRect_guess;
                Rect_guess merged_guess;
                Rect_guess temp_guess;
                bounds_guess.Assign_guess(&temp_guess, bounds_guess.Merge_guess(&merged_guess,
                    ((ContainerView_guess*)slots_160[i])->GetRect_guess(&slotRect_guess)));
            } else {
                ((ContainerView_guess*)slots_160[i])->index_guess = -1;
                ((ContainerView_guess*)slots_160[i])->Show_guess(0, 1);
            }
        }
    }
    int savedRight_guess = bounds_guess.third_guess;
    if (field_15c->GetType_guess() == 0x35) {
        ContainerView_guess* list_guess = (ContainerView_guess*)augmentList_1a8;
        if (list_guess != 0) {
            bounds_guess.third_guess += list_guess->right_guess - list_guess->left_guess + 8;
            list_guess->Show_guess(1, 1);
        }
        UpdateAugments_guess();
    }
    if (field_15c->GetType_guess() < 9 || field_15c->GetType_guess() == 0x33 ||
        field_15c->GetType_guess() == 0x35) {
        if (combineButton_188 != 0) {
            ((ContainerView_guess*)combineButton_188)->Show_guess(0, 1);
        }
    } else {
        ContainerView_guess* combine_guess = (ContainerView_guess*)combineButton_188;
        if (combine_guess != 0) {
            bounds_guess.fourth_guess += combine_guess->bottom_guess - combine_guess->top_guess + 4;
            ContainerPoint_guess point_guess;
            point_guess.x_guess = (bounds_guess.third_guess - bounds_guess.first_guess) / 2 -
                (combine_guess->right_guess - combine_guess->left_guess) / 2;
            point_guess.y_guess = combine_guess->top_guess - combine_guess->bottom_guess + bounds_guess.fourth_guess;
            combine_guess->MoveTo_guess(point_guess);
            ((ContainerView_guess*)combineButton_188)->Show_guess(1, 1);
        }
    }
    ContainerView_guess* done_guess = (ContainerView_guess*)doneButton_18c;
    if (done_guess != 0) {
        ContainerPoint_guess point_guess;
        point_guess.x_guess = 0;
        point_guess.y_guess = 0;
        bounds_guess.fourth_guess += done_guess->bottom_guess - done_guess->top_guess + 4;
        if (field_15c->GetType_guess() == 0x35) {
            point_guess.x_guess = savedRight_guess / 2 -
                (((ContainerView_guess*)doneButton_18c)->right_guess - ((ContainerView_guess*)doneButton_18c)->left_guess) / 2;
        } else {
            point_guess.x_guess = (bounds_guess.third_guess - bounds_guess.first_guess) / 2 -
                (((ContainerView_guess*)doneButton_18c)->right_guess - ((ContainerView_guess*)doneButton_18c)->left_guess) / 2;
        }
        done_guess = (ContainerView_guess*)doneButton_18c;
        point_guess.y_guess = done_guess->top_guess - done_guess->bottom_guess + bounds_guess.fourth_guess;
        done_guess->MoveTo_guess(point_guess);
        ((ContainerView_guess*)doneButton_18c)->Show_guess(1, 1);
    }
    // The window is sized to its visible children plus a 14 x 36 frame.
    if (bounds_guess.second_guess < bounds_guess.fourth_guess && bounds_guess.first_guess < bounds_guess.third_guess) {
        ((ContainerView_guess*)this)->Resize_guess(bounds_guess.third_guess - bounds_guess.first_guess + 14,
            bounds_guess.fourth_guess - bounds_guess.second_guess + 36);
    }
}

// An item or bag (EQ_Item-like) as UpdateAugments_guess sees it.
struct AugItem_guess {
    virtual void V00_guess(); virtual void V01_guess(); virtual void V02_guess(); virtual void V03_guess();
    virtual bool IsReady_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005ECC30 AugItem_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 AugItem_guess::GetItem_guess
    AugItem_guess* GetItem_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005ECCC0 AugItem_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 AugItem_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E10B0 AugItem_guess::GetAugType_guess
    int GetAugType_guess();
    // EXTERNAL: TITANIUM 0x005E15A0 AugItem_guess::CountSlots_guess
    int CountSlots_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0D00 AugItem_guess::HasSlot_guess
    bool HasSlot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0CC0 AugItem_guess::IsSlotVisible_guess
    bool IsSlotVisible_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 AugItem_guess::GetName_guess
    char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 AugItem_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E3C40 AugItem_guess::CanInsert_guess
    int CanInsert_guess(AugItem_guess* aug_guess, int flag_guess, int* out_guess);
};

struct AugChecker_guess {
    // EXTERNAL: TITANIUM 0x004192AA AugChecker_guess::CanUseItem_guess
    int CanUseItem_guess(AugItem_guess* item_guess, int flag_guess);
};

struct AugCharData_guess {
    char pad_guess[0xc280];
    AugChecker_guess checker_guess;         // 0xc280
};

#define g_augCharData_guess EQ_GLOBAL(AugCharData_guess*, 0x00905D00)

// Augmentation Sealer: finds the augmentable item (not lore, not item type 54-56, no aug type, aug slots),
// the augment (type 54), solvent (55) or distiller (56), and lists the item's 10 slots ("Empty" when
// open). A solvent enables Delete (5884). A distiller selects the one augment whose 0x5E10B0 value equals
// the distiller's item id (5885), asks to pick when several match (5886), or says none (5887). An augment
// enables Insert (5888) unless CanInsert_guess fails (3362, 3365-3367, 3371, 6193 by result) or neither
// item can be used (3364). The hint starts at 5882, and 5883 once an item is in.
// FUNCTION: TITANIUM 0x004FAE39
void ContainerWnd_guess::UpdateAugments_guess() {
    AugItem_guess* target_guess = 0;
    AugItem_guess* solvent_guess = 0;
    AugItem_guess* distiller_guess = 0;
    AugItem_guess* augment_guess = 0;
    if (augmentList_1a8 != 0) {
        ((ContainerView_guess*)augmentList_1a8)->DeleteAll_guess();
    }
    if (deleteButton_19c != 0) {
        deleteButton_19c->Slot48_guess(0, 1);
    }
    if (removeButton_198 != 0) {
        removeButton_198->Slot48_guess(0, 1);
    }
    if (insertButton_194 != 0) {
        insertButton_194->Slot48_guess(0, 1);
    }
    if (augmentInfo_1ac != 0) {
        {
            CXStr text_guess(pStringTable->getString(0x16fa, 0));
            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
        }
        augmentInfo_1ac->Slot48_guess(1, 1);
    }
    for (int i = 0; i < ((AugItem_guess*)field_15c)->GetCount_guess(); i++) {
        if (((AugItem_guess*)field_15c)->GetItem_guess(i) != 0) {
            AugItem_guess* item_guess = ((AugItem_guess*)field_15c)->GetItem_guess(i);
            if (item_guess->GetItemClass_guess() == 0 && item_guess->GetItemType_guess() != 0x37 &&
                item_guess->GetItemType_guess() != 0x38 && item_guess->GetItemType_guess() != 0x36 &&
                item_guess->GetAugType_guess() == 0 && item_guess->CountSlots_guess(1) > 0) {
                target_guess = item_guess;
            } else if (item_guess->GetItemType_guess() == 0x37) {
                solvent_guess = item_guess;
            } else if (item_guess->GetItemType_guess() == 0x36) {
                augment_guess = item_guess;
            } else if (item_guess->GetItemType_guess() == 0x38) {
                distiller_guess = item_guess;
            }
        }
    }
    int augTypes_guess[10] = { 0 };
    if (target_guess != 0) {
        for (int i = 0; i < 10; i++) {
            char name_guess[1024] = { 0 };
            if (target_guess->HasSlot_guess(i) && target_guess->IsSlotVisible_guess(i)) {
                if (target_guess->GetItem_guess(i) != 0) {
                    strcpy(name_guess, target_guess->GetItem_guess(i)->GetName_guess());
                    augTypes_guess[i] = target_guess->GetItem_guess(i)->GetAugType_guess();
                } else {
                    strcpy(name_guess, "Empty");
                }
            }
            if (augmentList_1a8 != 0) {
                CXStr text_guess(name_guess);
                ((CListWnd*)augmentList_1a8)->AddString(text_guess, 0xffffffff, 0, 0);
            }
        }
        if (augmentInfo_1ac != 0) {
            CXStr text_guess(pStringTable->getString(0x16fb, 0));
            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
        }
    }
    if (solvent_guess != 0 && target_guess != 0) {
        if (deleteButton_19c != 0) {
            deleteButton_19c->Slot48_guess(1, 1);
            ((CXWnd*)deleteButton_19c)->Enabled = 0;
            if (augmentList_1a8 != 0) {
                ((CListWnd*)augmentList_1a8)->ClearAllSel();
            }
        }
        if (augmentInfo_1ac != 0) {
            CXStr text_guess(pStringTable->getString(0x16fc, 0));
            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
        }
    }
    if (distiller_guess != 0) {
        int matches_guess = 0;
        if (augmentInfo_1ac != 0) {
            CXStr text_guess(pStringTable->getString(0x16ff, 0));
            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
        }
        for (int i = 0; i < 10; i++) {
            if (augTypes_guess[i] == distiller_guess->GetItemId_guess()) {
                matches_guess++;
                if (augmentList_1a8 != 0) {
                    if (matches_guess == 1) {
                        ((CListWnd*)augmentList_1a8)->SetCurSel(i);
                        if (augmentInfo_1ac != 0) {
                            CXStr text_guess(pStringTable->getString(0x16fd, 0));
                            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
                        }
                    } else if (matches_guess > 1) {
                        ((CListWnd*)augmentList_1a8)->ClearAllSel();
                        if (augmentInfo_1ac != 0) {
                            CXStr text_guess(pStringTable->getString(0x16fe, 0));
                            ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
                        }
                    }
                }
            }
        }
        if (removeButton_198 != 0 && matches_guess != 0) {
            removeButton_198->Slot48_guess(1, 1);
            ((CXWnd*)removeButton_198)->Enabled = 1;
            if (augmentList_1a8 != 0 && ((CListWnd*)augmentList_1a8)->GetCurSel() < 0) {
                ((CXWnd*)removeButton_198)->Enabled = 0;
                if (augmentInfo_1ac != 0) {
                    CXStr text_guess(pStringTable->getString(0x16fe, 0));
                    ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
                }
            }
        }
    }
    if (augment_guess != 0 && target_guess != 0) {
        int message_guess = 0;
        int ok_guess = 1;
        int slot_guess;
        int result_guess = target_guess->CanInsert_guess(augment_guess, 1, &slot_guess);
        if (result_guess != 0) {
            message_guess = 0xd22;
            ok_guess = 0;
            switch (result_guess) {
            case 1:
            case 2:
            case 3:
            case 4: message_guess = 0xd25; break;
            case 5: message_guess = 0xd26; break;
            case 6: message_guess = 0xd27; break;
            case 7: message_guess = 0xd2b; break;
            case 8: message_guess = 0x1831; break;
            }
        }
        if (!(target_guess->IsReady_guess(0) && augment_guess->IsReady_guess(0)) &&
            !(g_augCharData_guess->checker_guess.CanUseItem_guess(target_guess, 1) &&
              g_augCharData_guess->checker_guess.CanUseItem_guess(augment_guess, 1))) {
            message_guess = 0xd24;
            ok_guess = 0;
        }
        if (ok_guess != 0) {
            if (insertButton_194 != 0) {
                insertButton_194->Slot48_guess(1, 1);
                ((CXWnd*)insertButton_194)->Enabled = 1;
                if (augmentInfo_1ac != 0) {
                    CXStr text_guess(pStringTable->getString(0x1700, 0));
                    ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
                }
            }
        } else {
            if (insertButton_194 != 0) {
                insertButton_194->Slot48_guess(1, 1);
                ((CXWnd*)insertButton_194)->Enabled = 0;
                if (augmentInfo_1ac != 0) {
                    CXStr text_guess(pStringTable->getString(message_guess, 0));
                    ((ContainerView_guess*)augmentInfo_1ac)->SetWindowText_guess(text_guess);
                }
            }
        }
    }
}

struct ControlRect_guess {
    int x_guess;
    int y_guess;
    int width_guess;
    int height_guess;
    ControlRect_guess(int x_guess, int y_guess, int width_guess, int height_guess)
        : x_guess(x_guess), y_guess(y_guess), width_guess(width_guess), height_guess(height_guess) {}
};

struct Control_guess {
    char data_guess[0x1a8];
    // EXTERNAL: TITANIUM 0x005BFAE0 Control_guess::Control_guess
    Control_guess(int x_guess, int y_guess, const ControlRect_guess& rect_guess);
    // EXTERNAL: TITANIUM 0x005BFCF0 Control_guess::Add_guess
    int Add_guess(CXStr* text_guess, int index_guess, int zero_guess, int data_guess);
    // EXTERNAL: TITANIUM 0x005BFE60 Control_guess::Clear_guess
    void Clear_guess();
};

struct FormBase_guess {
    virtual void Slot_guess() = 0;
    char pad_guess[0x1150];
    ~FormBase_guess() {}
    // EXTERNAL: TITANIUM 0x005ADD50 FormBase_guess::FormBase_guess
    FormBase_guess(int first_guess, int second_guess, int& third_guess);
};

// EXTERNAL: TITANIUM 0x006533D8 ??_7WindowTitleMenu_guess@@6B@
struct WindowTitleMenu_guess : FormBase_guess {
    int registered_guess;
    int firstIndex_guess;
    int thirdIndex_guess;
    int lastIndex_guess;
    int secondIndex_guess;
    // EXTERNAL: TITANIUM 0x005AD5A0 WindowTitleMenu_guess::Register_guess
    int Register_guess(Control_guess* control_guess);
    WindowTitleMenu_guess(int first_guess, int second_guess, int third_guess,
        int fourth_guess, int fifth_guess, int sixth_guess);
    void Initialize_guess();
};

// The standard window menu; its items are built in Initialize_guess.
// FUNCTION: TITANIUM 0x004FD26A
WindowTitleMenu_guess::WindowTitleMenu_guess(int first_guess, int second_guess, int third_guess,
    int fourth_guess, int fifth_guess, int sixth_guess)
    : FormBase_guess(first_guess, second_guess, third_guess) {
    Initialize_guess();
}

// Window menu items (strings 15000-15007, 6649): Background > Texture (10) / Tint Color (11), Alpha >
// Normal Level (12) / Faded Level (13), Lock (16), Minimize (14), Close (15). A submenu entry's id is
// 0x80000000 + its registered menu.
// FUNCTION: TITANIUM 0x004FCE0C
void WindowTitleMenu_guess::Initialize_guess() {
    int firstResult_guess;
    {
        Control_guess* firstControl_guess = new Control_guess(0, 0, ControlRect_guess(0, 0, 0x32, 10));
        {
            CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9e, 0));
            firstControl_guess->Add_guess(&text_guess, 10, 0, -1);
        }
        {
            CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9f, 0));
            firstControl_guess->Add_guess(&text_guess, 0xb, 0, -1);
        }
        firstResult_guess = Register_guess(firstControl_guess);
    }

    int secondResult_guess;
    {
        Control_guess* secondControl_guess = new Control_guess(0, 0, ControlRect_guess(0, 0, 0x32, 10));
        {
            CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9c, 0));
            secondControl_guess->Add_guess(&text_guess, 0xc, 0, -1);
        }
        {
            CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9d, 0));
            secondControl_guess->Add_guess(&text_guess, 0xd, 0, -1);
        }
        secondResult_guess = Register_guess(secondControl_guess);
    }

    Control_guess* control_guess = new Control_guess(0, 0, ControlRect_guess(0, 0, 0x32, 10));
    {
        CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9a, 0));
        firstIndex_guess = control_guess->Add_guess(&text_guess, firstResult_guess + 0x80000000, 0, -1);
    }
    {
        CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a9b, 0));
        control_guess->Add_guess(&text_guess, secondResult_guess + 0x80000000, 0, -1);
    }
    control_guess->Clear_guess();
    {
        CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x19f9, 0));
        secondIndex_guess = control_guess->Add_guess(&text_guess, 0x10, 0, -1);
    }
    control_guess->Clear_guess();
    {
        CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a99, 0));
        thirdIndex_guess = control_guess->Add_guess(&text_guess, 0xe, 0, -1);
    }
    control_guess->Clear_guess();
    {
        CXStr text_guess((const char*)g_table_guess->Lookup_guess(0x3a98, 0));
        lastIndex_guess = control_guess->Add_guess(&text_guess, 0xf, 0, -1);
    }
    registered_guess = Register_guess(control_guess);
}

struct Selector_guess {
    virtual void RefreshCounts_guess();
    virtual void Release_guess(int value_guess);
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
    virtual void Slot48_guess(int value_guess, int flag_guess);
    char pad_guess[0x158];
    int selected_guess;
    // EXTERNAL: TITANIUM 0x004FB700 Selector_guess::Select_guess
    void Select_guess(int first_guess, int second_guess);
    void OnSelect_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x004FAE39 Selector_guess::Unlink_guess
    void Unlink_guess();
};

struct Widget_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
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
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess();
    virtual void Slot1f_guess();
    virtual void Slot20_guess();
    virtual void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004FB700 Widget_guess::Select_guess
    void Select_guess(int first_guess, int second_guess);
};

struct ThingHost_guess {
    // EXTERNAL: TITANIUM 0x004FA2D4 ThingHost_guess::GetFreeContainerWnd_guess
    Widget_guess* GetFreeContainerWnd_guess();
    void Select_guess(int first_guess, int second_guess);
};

// Shows a container in the window 0x4FA2D4 returns (probably the first free one) and refreshes it.
// FUNCTION: TITANIUM 0x004FA7A4
void ThingHost_guess::Select_guess(int first_guess, int second_guess) {
    Widget_guess* widget_guess = GetFreeContainerWnd_guess();
    if (widget_guess != 0) {
        widget_guess->Select_guess(first_guess, second_guess);
        widget_guess->Refresh_guess();
    }
}

// Empties this window when it shows container `id_guess`.
// FUNCTION: TITANIUM 0x004FBD55
void Selector_guess::OnSelect_guess(int id_guess) {
    if (id_guess == selected_guess) {
        Select_guess(0, -1);
    }
}

struct Part_guess {
    // EXTERNAL: TITANIUM 0x004B1D0B Part_guess::ClearOpen_guess
    bool ClearOpen_guess();
    // EXTERNAL: TITANIUM 0x004B1CF4 Part_guess::SetOpen_guess
    bool SetOpen_guess();
};

struct Slot_guess {
    virtual void Destroy_guess(int flags_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual Part_guess* Slot0a_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Slot_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC660 Slot_guess::Select_guess
    void Select_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ECCF0 Slot_guess::GetState_guess
    int GetState_guess();
};


// EXTERNAL: TITANIUM 0x00653184 ??_7CContainerMgrView_guess@@6B@
struct CContainerMgrView_guess {
    virtual ~CContainerMgrView_guess();
    Selector_guess* slots_guess[26];
    Slot_guess* extra_guess;                // 0x6c
    int value_guess;                        // 0x70
    unsigned int lastUpdate_guess;          // 0x74
    void ClearSlots_guess();
    void Release_guess();
    unsigned char Flush_guess();
    void CloseEQContainer_guess(Slot_guess* extra);
    void CloseContainer_guess(int id_guess, unsigned char flag_guess);
    void Process_guess();
    // EXTERNAL: TITANIUM 0x004FA714 CContainerMgrView_guess::Reselect_guess
    void Reselect_guess();
    // EXTERNAL: TITANIUM 0x004FA2D4 CContainerMgrView_guess::GetFreeContainerWnd_guess
    Widget_guess* GetFreeContainerWnd_guess();
    // EXTERNAL: TITANIUM 0x004FA7CD CContainerMgrView_guess::Bind_guess
    void Bind_guess(Slot_guess* extra_guess, int delay_guess, char flag_guess);
    void Attach_guess(Slot_guess* extra_arg, int value_arg);
    void* Destroy_guess(unsigned char flags_guess);
};

// Calls 0x5EC660 for every item of the world container; for an Augmentation Sealer it also refreshes the
// augment list of each window showing a sealer (Unlink_guess is really UpdateAugments_guess).
// FUNCTION: TITANIUM 0x004FA714
void CContainerMgrView_guess::Reselect_guess() {
    if (extra_guess != 0) {
        int index_guess = 0;
        if (extra_guess->GetCount_guess() > 0) {
            do {
                extra_guess->Select_guess(index_guess);
                ++index_guess;
            } while (index_guess < extra_guess->GetCount_guess());
        }
        if (extra_guess->GetState_guess() == 0x35) {
            Selector_guess** slot_guess = slots_guess;
            int count_guess = 26;
            do {
                if (*slot_guess != 0 && (*slot_guess)->selected_guess != 0) {
                    if (((Slot_guess*)(*slot_guess)->selected_guess)->GetState_guess() == 0x35) {
                        (*slot_guess)->Unlink_guess();
                    }
                }
                ++slot_guess;
                --count_guess;
            } while (count_guess != 0);
        }
    }
}

// The global object: a Selector with an IsReady() method at 0x0059DD30.
struct ReadyHost_guess : Selector_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 ReadyHost_guess::IsReady_guess
    unsigned char IsReady_guess();
    // EXTERNAL: TITANIUM 0x00567634 ReadyHost_guess::IsTradeskillContainerType_guess
    unsigned char IsTradeskillContainerType_guess(int state_guess);
    // EXTERNAL: TITANIUM 0x00567FE5 ReadyHost_guess::SetExtra_guess
    void SetExtra_guess(Slot_guess* extra_guess, int delay_guess);
    char pad2_guess[0x364 - 0x160];
    int pending_guess;   // 0x364
    int pendingFlag_guess; // 0x368
};

#define pinstCTradeskillWnd_guess EQ_GLOBAL(ReadyHost_guess*, 0x00992940)

// A global object with a virtual at slot 34 (+0x88), called with no arguments.


// Closes and frees all 26 bag windows (CloseEQContainer_guess for each shown container) and hides the
// TradeskillWnd (0x992940); true when a container was open.
// FUNCTION: TITANIUM 0x004FAABA
unsigned char CContainerMgrView_guess::Flush_guess() {
    unsigned char changed_guess = 0;
    Selector_guess** slot_guess = slots_guess;
    int count_guess = 26;
    do {
        if (*slot_guess != 0) {
            int selected_guess = (*slot_guess)->selected_guess;
            if (selected_guess != 0) {
                CloseEQContainer_guess((Slot_guess*)selected_guess);
                changed_guess = 1;
            }
            (*slot_guess)->Slot48_guess(0, 1);
            if (*slot_guess != 0) {
                (*slot_guess)->Release_guess(1);
            }
            *slot_guess = 0;
        }
        ++slot_guess;
        --count_guess;
    } while (count_guess != 0);
    if (pinstCTradeskillWnd_guess != 0 && pinstCTradeskillWnd_guess->IsReady_guess() != 0) {
        pinstCTradeskillWnd_guess->Slot48_guess(0, 1);
    }
    return changed_guess;
}

// Container manager destructor: deletes the 26 container windows (virtual slot 0 with flag 1); a still
// open world container is closed first (0x004FA948, which tells the server with OP_ClickObjectAction),
// then dropped (0x004FA92D).
// FUNCTION: TITANIUM 0x004FAB3A
CContainerMgrView_guess::~CContainerMgrView_guess() {
    for (int i = 0; i < 26; i++) {
        if (slots_guess[i] != 0) {
            slots_guess[i]->Release_guess(1);
            slots_guess[i] = 0;
        }
    }
    if (extra_guess != 0) {
        CloseEQContainer_guess(extra_guess);
        Release_guess();
    }
}

// Scalar deleting destructor of the container manager (vtable 0x653184 slot 0): runs its destructor
// (0x004FAB3A, which deletes the 26 container windows) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004FACC5
void* CContainerMgrView_guess::Destroy_guess(unsigned char flags_guess) {
    this->CContainerMgrView_guess::~CContainerMgrView_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Empties every window that shows the world container.
// FUNCTION: TITANIUM 0x004FA90A
void CContainerMgrView_guess::ClearSlots_guess() {
    for (int i = 0; i < 26; i++) {
        if (slots_guess[i] != 0) {
            slots_guess[i]->OnSelect_guess((int)extra_guess);
        }
    }
}

// Empties the world container's windows and deletes the container object.
// FUNCTION: TITANIUM 0x004FA92D
void CContainerMgrView_guess::Release_guess() {
    ClearSlots_guess();
    if (extra_guess != 0) {
        extra_guess->Destroy_guess(1);
    }
    extra_guess = 0;
}

struct Msg_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    char rest_guess[0x50];
};

struct Env_guess {
    char pad_guess[0x258];
    int value258_guess;
};

#define g_env_guess EQ_GLOBAL(Env_guess*, 0x00905CE4)
#define g_detachFlag_guess EQ_GLOBAL(int, 0x009248D4)

struct NoticeRenderer_guess {
    // EXTERNAL: TITANIUM 0x0044A537 NoticeRenderer_guess::Show_guess
    void Show_guess(int id_guess, int zero_guess);
};

#define g_noticeRenderer_guess EQ_GLOBAL(NoticeRenderer_guess*, 0x00851390)

struct LookupSubobject_guess {
    // EXTERNAL: TITANIUM 0x0041B0DE LookupSubobject_guess::HasSkill_guess
    int HasSkill_guess(int value_guess);
};

struct Lookup_guess {
    char pad_guess[0xc280];
    LookupSubobject_guess subobject_guess;
    // EXTERNAL: TITANIUM 0x004BB89C Lookup_guess::GetContainerTradeskill_guess
    int GetContainerTradeskill_guess(int state_guess, Slot_guess* slot_guess);
};

#define g_lookup_guess EQ_GLOBAL(Lookup_guess*, 0x00905D00)

// Opens container `extra_guess` from slot `delay_guess`: sound 0x86 for chests and stations (types 6-7,
// 10, 15, 18-20, 22), else 0x91. A general bag (slots 22-29) or the world container (4000) that is a
// tradeskill container whose skill the player has (GetContainerTradeskill_guess, 0x41B0DE) opens in the
// TradeskillWnd instead when `flag_guess` is set and it is not up already. Marks the item open (0x4B1CF4).
// FUNCTION: TITANIUM 0x004FA7CD
// @early-stop: budget, structural ndiff=63
void CContainerMgrView_guess::Bind_guess(Slot_guess* extra_guess, int delay_guess, char flag_guess) {
    int code_guess;
    Widget_guess* widget_guess;
    if ((widget_guess = GetFreeContainerWnd_guess()) != 0) {
        int state_guess;
        code_guess = 0x91;
        state_guess = extra_guess->GetState_guess();
        if (state_guess >= 6 && (state_guess <= 7 || state_guess == 0xa || state_guess == 0xf ||
                                 (state_guess > 0x11 && (state_guess <= 0x14 || state_guess == 0x16)))) {
            code_guess = 0x86;
        }
        g_noticeRenderer_guess->Show_guess(code_guess, 0);
        if (pinstCTradeskillWnd_guess != 0 && pinstCTradeskillWnd_guess->IsReady_guess() == 0 && flag_guess != 0 &&
            ((delay_guess > 0x15 && delay_guess < 0x1e) || delay_guess == 4000)) {
            unsigned char hasState_guess = pinstCTradeskillWnd_guess->IsTradeskillContainerType_guess(extra_guess->GetState_guess());
            int classification_guess = g_lookup_guess->GetContainerTradeskill_guess(extra_guess->GetState_guess(), extra_guess);
            bool unavailable_guess = classification_guess == 0xff ||
                g_lookup_guess->subobject_guess.HasSkill_guess(classification_guess) == 0;
            if (hasState_guess != 0 && !unavailable_guess) {
                extra_guess->Slot0a_guess()->SetOpen_guess();
                pinstCTradeskillWnd_guess->SetExtra_guess(extra_guess, delay_guess);
                pinstCTradeskillWnd_guess->Slot48_guess(1, 1);
                return;
            }
        }
        extra_guess->Slot0a_guess()->SetOpen_guess();
        ((ContainerWnd_guess*)widget_guess)->SetContainer_guess((ContainerContents_guess*)extra_guess, delay_guess);
        widget_guess->Refresh_guess();
    }
}

// Clears the container item's open flag (0x4B1D0B) and plays the close sound (0x85 chests and stations,
// else 0x91). For the world container also sends OP_ClickObjectAction (0x5C bytes: player spawn +0x258,
// the object's drop id, 0 = close) and drops it.
// FUNCTION: TITANIUM 0x004FA948
void CContainerMgrView_guess::CloseEQContainer_guess(Slot_guess* extra) {
    extra->Slot0a_guess()->ClearOpen_guess();
    int code_guess = 0x91;
    int state_guess = extra->GetState_guess();
    if (state_guess >= 6 && (state_guess <= 7 || state_guess == 0xa || state_guess == 0xf ||
                             (state_guess > 0x11 && (state_guess <= 0x14 || state_guess == 0x16)))) {
        code_guess = 0x85;
    }
    g_noticeRenderer_guess->Show_guess(code_guess, 0);
    if (extra_guess != 0 && extra_guess == extra) {
        Msg_guess msg_guess;
        msg_guess.first_guess = g_env_guess->value258_guess;
        msg_guess.second_guess = value_guess;
        msg_guess.third_guess = 0;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_ClickObjectAction, &msg_guess, 0x5c, 1);
        Reselect_guess();
        Release_guess();
        value_guess = 0;
        g_detachFlag_guess = 0;
    }
}

// Closes container `id_guess`; with `flag_guess` also frees its bag window and cancels a TradeskillWnd use
// of it (+0x364, +0x368). It first closes the quantity window (0x850C3C, Deactivate).
// FUNCTION: TITANIUM 0x004FAA17
void CContainerMgrView_guess::CloseContainer_guess(int id_guess, unsigned char flag_guess) {
    if (pinstCQuantityWnd_guess != 0) {
        pinstCQuantityWnd_guess->Deactivate();
    }
    if (flag_guess != 0) {
        for (int i = 0; i < 26; i++) {
            if (slots_guess[i] != 0 && slots_guess[i]->selected_guess == id_guess) {
                slots_guess[i]->Slot48_guess(0, 1);
                if (slots_guess[i] != 0) {
                    slots_guess[i]->Release_guess(1);
                }
                slots_guess[i] = 0;
                break;
            }
        }
        if (pinstCTradeskillWnd_guess != 0) {
            int* pending_guess = &pinstCTradeskillWnd_guess->pending_guess;
            if (*pending_guess == id_guess) {
                pinstCTradeskillWnd_guess->pendingFlag_guess = -1;
                *pending_guess = 0;
                pinstCTradeskillWnd_guess->Slot48_guess(0, 1);
            }
        }
    }
    CloseEQContainer_guess((Slot_guess*)id_guess);
}

struct TargetPoint_guess {
    char pad_guess[0x20];
    float x_guess;
    float y_guess;
    float z_guess;
};

struct TargetList_guess {
    // EXTERNAL: TITANIUM 0x00464770 TargetList_guess::FindByDropId_guess
    TargetPoint_guess* FindByDropId_guess(int id_guess);
};

#define g_targetList_guess EQ_GLOBAL(TargetList_guess*, 0x00905CC8)

struct Origin_guess {
    char pad_guess[0x30];
    float x_guess;
    float y_guess;
    float z_guess;
};

#define g_origin_guess EQ_GLOBAL(Origin_guess*, 0x00905CF8)

// World-container tick: every 500 ms, closes it once the player is over 20 units from its object
// (FindByDropId_guess, TrueDistance_guess); then refreshes the Done button of its windows.
// FUNCTION: TITANIUM 0x004FAB7E
void CContainerMgrView_guess::Process_guess() {
    if (extra_guess != 0) {
        if (g_containerDisplay_guess->time_guess > lastUpdate_guess + 500) {
            TargetPoint_guess* target_guess = g_targetList_guess->FindByDropId_guess(value_guess);
            if (target_guess != 0) {
                float originZ_guess = g_origin_guess->z_guess;
                float originY_guess = g_origin_guess->y_guess;
                float originX_guess = g_origin_guess->x_guess;
                if (g_containerDisplay_guess->TrueDistance_guess(
                        originX_guess, originY_guess, originZ_guess,
                        target_guess->z_guess, target_guess->y_guess, target_guess->x_guess, 1.0f) > 20.0f) {
                    CloseContainer_guess((int)extra_guess, 1);
                }
            }
            lastUpdate_guess = g_containerDisplay_guess->time_guess;
        }
        Selector_guess** slot_guess = slots_guess;
        int count_guess = 26;
        do {
            Selector_guess* entry_guess = *slot_guess;
            if (entry_guess != 0 && (void*)((CContainerWndView_guess*)entry_guess)->child_guess == (void*)extra_guess) {
                ((CContainerWndView_guess*)entry_guess)->Refresh_guess();
            }
            ++slot_guess;
            --count_guess;
        } while (count_guess != 0);
    }
}

// Opens world container `extra_arg` (object drop id `value_arg`) as slot 4000, closing the previous one,
// then shows tip 0x23 (Augmentation Sealer) or 0x1B in the tips window (0x9928E0).
// FUNCTION: TITANIUM 0x004FAC58
void CContainerMgrView_guess::Attach_guess(Slot_guess* extra_arg, int value_arg) {
    if (extra_guess != 0) {
        CloseEQContainer_guess(extra_guess);
        Reselect_guess();
        Release_guess();
        value_guess = 0;
    }
    extra_guess = extra_arg;
    value_guess = value_arg;
    Bind_guess(extra_arg, 4000, 1);
    if (pinstCTipWndCONTEXT_guess != 0) {
        int state_guess = extra_arg->GetState_guess();
        if (state_guess == 0x35) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x23, 0);
        } else {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x1b, 0);
        }
    }
}

struct ContainerPartCheckHost_guess {
    // EXTERNAL: TITANIUM 0x004B1D0B ContainerPartCheckHost_guess::ClearOpen_guess
    bool ClearOpen_guess();
};

struct ContainerContentsSlotHost_guess {
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
    virtual void* Slot10_guess();
};

struct ContainerWndSlotHost_guess {
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
};

#define g_containerSelectionOwner_guess EQ_GLOBAL(CContainerMgrView_guess*, 0x00850CBC)

// Notification 10 and Done close the container (Done also calls vtable slot 34). Combine works on types
// 9 up except 0x33; Insert, Delete and Remove go to Confirm_guess modes 0, 1 and 2. An AugmentList click
// enables Delete and Remove (+0x5D) unless the row is "Empty"; in a sealer any item-slot notification
// refreshes the augment list.
// FUNCTION: TITANIUM 0x004FC6F5
// @early-stop: budget, structural ndiff=148
int ContainerWnd_guess::WndNotification_guess(CXWnd* sender_guess,
    unsigned int message_guess, void* data_guess) {
    char selected_guess;
    if (message_guess == 10) {
        ContainerContents_guess** contentsSlot_guess = &field_15c;
        if (*contentsSlot_guess != 0) {
            g_containerSelectionOwner_guess->CloseContainer_guess((int)*contentsSlot_guess, 0);
            if (*contentsSlot_guess != 0) {
                void* part_guess = ((ContainerContentsSlotHost_guess*)*contentsSlot_guess)->Slot10_guess();
                ((ContainerPartCheckHost_guess*)part_guess)->ClearOpen_guess();
            }
            SetContainer_guess(0, -1);
            return 0;
        }
    } else {
        int one_guess = 1;
        if (message_guess == one_guess) {
            if (sender_guess == combineButton_188) {
                if (field_15c->GetType_guess() >= 9) {
                    if (field_15c->GetType_guess() != 0x33) {
                        HandleCombine();
                        return 0;
                    }
                }
            } else if (sender_guess == doneButton_18c) {
                if (field_15c != 0) {
                    ((ContainerWndSlotHost_guess*)this)->Slot34_guess();
                    g_containerSelectionOwner_guess->CloseContainer_guess((int)field_15c, 0);
                    if (field_15c != 0) {
                        void* part_guess = ((ContainerContentsSlotHost_guess*)field_15c)->Slot10_guess();
                        ((ContainerPartCheckHost_guess*)part_guess)->ClearOpen_guess();
                    }
                    SetContainer_guess(0, -1);
                    return 0;
                }
            } else if (sender_guess == (CXWnd*)insertButton_194) {
                Confirm_guess(0);
            } else if (sender_guess == (CXWnd*)deleteButton_19c) {
                Confirm_guess(one_guess);
            } else if (sender_guess == (CXWnd*)removeButton_198) {
                Confirm_guess(2);
            } else if (sender_guess == (CXWnd*)augmentList_1a8) {
                if (augmentList_1a8 != 0) {
                    CListWnd* list_guess = (CListWnd*)augmentList_1a8;
                    list_guess->SetCurSel((int)data_guess);
                    {
                        CXStr firstText_guess = list_guess->GetItemText((int)data_guess, 0);
                        if (firstText_guess.Ptr != 0 && firstText_guess.Ptr->length > 0) {
                            CXStr secondText_guess = list_guess->GetItemText((int)data_guess, 0);
                            selected_guess = 1;
                            if (_stricmp((char*)secondText_guess, "Empty") == 0) {
                                selected_guess = 0;
                            }
                        } else {
                            selected_guess = 0;
                        }
                    }
                    if (selected_guess == 0) {
                        list_guess->ClearAllSel();
                        if (deleteButton_19c != 0 && deleteButton_19c->IsReady_guess() != 0) {
                            deleteButton_19c->field_05d_guess = 0;
                        }
                        if (removeButton_198 != 0 && removeButton_198->IsReady_guess() != 0) {
                            removeButton_198->field_05d_guess = 0;
                        }
                    } else {
                        if (deleteButton_19c != 0 && deleteButton_19c->IsReady_guess() != 0) {
                            deleteButton_19c->field_05d_guess = 1;
                        }
                        if (removeButton_198 != 0 && removeButton_198->IsReady_guess() != 0) {
                            removeButton_198->field_05d_guess = 1;
                        }
                    }
                }
            } else if (field_15c->GetType_guess() == 0x35) {
                CXWnd** slot_guess = slots_160;
                int remaining_guess = 10;
                do {
                    if (sender_guess == *slot_guess) {
                        UpdateAugments_guess();
                    }
                    ++slot_guess;
                    --remaining_guess;
                } while (remaining_guess != 0);
            }
        }
    }
    return ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(
        sender_guess, message_guess, data_guess);
}
