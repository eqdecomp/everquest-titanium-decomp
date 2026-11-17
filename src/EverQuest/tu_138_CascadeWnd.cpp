// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 138: a hint from compare/tumap.py.
// Cascading menus (the EQ button menu): CascadeTopWnd/CascadeSubWnd windows built from menu records, with
// submenu, command and separator items, kept by id in a manager at 0x991758. Messages between them: 0x24 open
// a submenu, 0x25 close it, 0x26 a command ran. Many _guess classes here are views of the same few windows.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct Setter_guess {
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
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Refresh_guess();
    char padding_guess[0x158];
    int field_15c_guess;
    void Set_guess(int value_guess);
};

#include "titanium/layouts/geometry.h"

struct Bounds_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    char Contains_guess(const CXPoint* point_guess);
};

// Point in rect, right and bottom edges excluded.
// FUNCTION: TITANIUM 0x004EA5BF
char Bounds_guess::Contains_guess(const CXPoint* point_guess) {
    if (point_guess->x < left_guess || point_guess->x >= right_guess ||
        point_guess->y < top_guess || point_guess->y >= bottom_guess) {
        return 0;
    }
    return 1;
}

struct Inner_guess {
    // EXTERNAL: TITANIUM 0x004D9160 Inner_guess::Copy_guess
    void Copy_guess(int* destination, const int* source);
};

struct Owner_guess {
    char padding[0x140];
    Inner_guess inner;
    void Build_guess(const int* source);
};

// Menu item window: sets its rect (+0x140) to `source` (copy 0x004D9160). The command and submenu item
// setup (0x004EA87C, 0x004EB344) call it to size the item's button.
// FUNCTION: TITANIUM 0x004EA5E4
void Owner_guess::Build_guess(const int* source) {
    int local[4];
    inner.Copy_guess(local, source);
}

struct Callback_at_28_guess;

struct Base_constructed_guess {
    virtual void Anchor_guess();
    // EXTERNAL: TITANIUM 0x005A3100 Base_constructed_guess::~Base_constructed_guess
    virtual ~Base_constructed_guess();
    char padding[0x24];
    struct Callback_at_28_guess* callback_at_28_guess;
    char padding_2c_guess[0xf8];
    unsigned int field_124_guess;
    char padding_128_guess[0x34];
    // EXTERNAL: TITANIUM 0x005A3850 Base_constructed_guess::Base_constructed_guess
    Base_constructed_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, int fifth);
    // EXTERNAL: TITANIUM 0x005A25B0 Base_constructed_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
};

struct Constructed_guess : Base_constructed_guess {
    unsigned int state;
    unsigned int value;
    Constructed_guess(CXWnd* parent, const CXStr& screen, unsigned int third);
};

// EXTERNAL: TITANIUM 0x006519E0 ??_7Constructed_guess@@6B@

// Constructor of the cascade menu item base (vtable 0x6519E0): a CSidlScreenWnd for `screen` under
// `parent`, +0x15C cleared and +0x160 = `third`. The separator, submenu and command item constructors
// start here.
// FUNCTION: TITANIUM 0x004EA600
Constructed_guess::Constructed_guess(CXWnd* parent, const CXStr& screen, unsigned int third)
    : Base_constructed_guess(parent, screen, 0, 1, 0), state(0), value(third) {
}

// Virtual (slot 72 of the four menu item vtables): stores `value` at +0x15C, then calls virtual slot
// 73 to refresh the item (empty for the base and separator items, 0x004EB344 for a submenu,
// 0x004EA87C for a command).
// FUNCTION: TITANIUM 0x004EA633
void Setter_guess::Set_guess(int value_guess) {
    field_15c_guess = value_guess;
    Refresh_guess();
}

struct CascadeSeparatorItemWnd_guess : Constructed_guess {
    CascadeSeparatorItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third);
};

// EXTERNAL: TITANIUM 0x00651B08 ??_7CascadeSeparatorItemWnd_guess@@6B@

// Constructor of a separator item (CascadeSeparatorItemWnd, vtable 0x651B08); runs the template setup
// (0x005A25B0) when the screen has a template (+0x124). The menu rebuild (0x004EAE5D) makes one for
// each type-2 record.
// FUNCTION: TITANIUM 0x004EA674
CascadeSeparatorItemWnd_guess::CascadeSeparatorItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third)
    : Constructed_guess(parent, screen, third) {
    if (field_124_guess != 0) {
        CreateChildrenFromSidl();
    }
}

struct ChildWindow_guess {
    char pad_0000_guess[0x5d];
    char flag_5d_guess;  // 0x5d
    char pad_005e_guess[0xf2];
    int field_150_guess;  // 0x150
};

struct Callback_at_28_guess {
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
    virtual void Slot32_guess(void* owner_guess, int event_guess, int* value_guess) = 0;
};

// EXTERNAL: TITANIUM 0x00651C40 ??_7CascadeSubmenuItemWnd_guess@@6B@
struct CascadeSubmenuItemWnd_guess : Constructed_guess {
    int field_164_guess;              // 0x164
    ChildWindow_guess* button_guess;  // 0x168
    ChildWindow_guess* arrow_guess;   // 0x16c
    // EXTERNAL: TITANIUM 0x005A1E10 CascadeSubmenuItemWnd_guess::GetChildItem
    ChildWindow_guess* GetChildItem(const CXStr& name_guess);
    CascadeSubmenuItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third);
    ~CascadeSubmenuItemWnd_guess();
    CascadeSubmenuItemWnd_guess* Destroy_guess(unsigned char flags_guess);
};

// Submenu item (CascadeSubmenuItemWnd): the label button plus a disabled arrow.
// FUNCTION: TITANIUM 0x004EA6BE
CascadeSubmenuItemWnd_guess::CascadeSubmenuItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third)
    : Constructed_guess(parent, screen, third), button_guess(0), arrow_guess(0) {
    if (field_124_guess != 0) {
        CreateChildrenFromSidl();
        {
            CXStr name_guess("Button");
            button_guess = GetChildItem(name_guess);
        }
        {
            CXStr name_guess("Arrow");
            arrow_guess = GetChildItem(name_guess);
        }
        if (arrow_guess != 0) {
            arrow_guess->flag_5d_guess = 0;
        }
        if (button_guess != 0) {
            button_guess->field_150_guess = 0x21;
        }
    }
}

// EXTERNAL: TITANIUM 0x00651D68 ??_7CascadeCommandItemWnd_guess@@6B@
struct CascadeCommandItemWnd_guess : Constructed_guess {
    int field_164_guess;                 // 0x164
    ChildWindow_guess* button_guess;     // 0x168
    // EXTERNAL: TITANIUM 0x005A1E10 CascadeCommandItemWnd_guess::GetChildItem
    ChildWindow_guess* GetChildItem(const CXStr& name_guess);
    CascadeCommandItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third);
    int Handle_guess(ChildWindow_guess* sender_guess, unsigned int message_guess, int* data_guess);
    // EXTERNAL: TITANIUM 0x005A2230 CascadeCommandItemWnd_guess::WndNotification
    int WndNotification(ChildWindow_guess* sender_guess, unsigned int message_guess, int* data_guess);
};

// Command item (CascadeCommandItemWnd): one label button.
// FUNCTION: TITANIUM 0x004EA7E1
CascadeCommandItemWnd_guess::CascadeCommandItemWnd_guess(CXWnd* parent, const CXStr& screen, unsigned int third)
    : Constructed_guess(parent, screen, third), button_guess(0) {
    if (field_124_guess != 0) {
        CreateChildrenFromSidl();
        {
            CXStr name_guess("Button");
            button_guess = GetChildItem(name_guess);
        }
        if (button_guess != 0) {
            button_guess->field_150_guess = 0x21;
        }
    }
}

// Local polymorphic base for the CSidlScreenWnd ctor (0x005A3850), 0x15C bytes (as tu_190 does).
struct CascadeBase_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005A3100 ??1CascadeBase_guess@@UAE@XZ
    virtual ~CascadeBase_guess();
    // EXTERNAL: TITANIUM 0x005A3850 CascadeBase_guess::CascadeBase_guess
    CascadeBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    char pad_0004_guess[0x16 - 0x04];
    unsigned char field_16_guess;  // 0x16
    unsigned char field_17_guess;  // 0x17
    unsigned char field_18_guess;  // 0x18
    char pad_0019_guess[0x65 - 0x19];
    unsigned char field_65_guess;  // 0x65
    char pad_0066_guess[0x150 - 0x66];
    int field_150_guess;           // 0x150
    char pad_0154_guess[0x15c - 0x154];
};

// EXTERNAL: TITANIUM 0x00651E90 ??_7CascadeWnd_guess@@6B@
struct CascadeWnd_guess : CascadeBase_guess {
    int field_15c_guess;           // 0x15c
    int field_160_guess;           // 0x160
    unsigned char field_164_guess; // 0x164
    int field_168_guess;           // 0x168
    int field_16c_guess;           // 0x16c
    unsigned char field_170_guess; // 0x170
    int field_174_guess;           // 0x174
    CascadeWnd_guess(CXWnd* parent, int flag);
};

// `flag` -1 makes a top-level menu (CascadeTopWnd), else a submenu whose parent menu id is `flag`.
// FUNCTION: TITANIUM 0x004EAA99
CascadeWnd_guess::CascadeWnd_guess(CXWnd* parent, int flag)
    : CascadeBase_guess(parent, flag == -1 ? "CascadeTopWnd" : "CascadeSubWnd", 0, 1, 0) {
    field_150_guess = -1;
    field_160_guess = 0;
    field_15c_guess = 0;
    field_168_guess = 0;
    field_170_guess = 0;
    field_174_guess = 0;
    field_16c_guess = flag;
    field_164_guess = 1;
    if (field_17_guess != 0) {
        field_16_guess = 1;
    }
    field_65_guess &= 0xfd;
    field_18_guess = flag == -1;
}

struct Callback_dispatch_guess {
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
    virtual void Slot32_guess(void* owner_guess, int event_guess, int* value_guess);
};

struct CallbackOwner2_guess {
    char padding[0x28];
    Callback_dispatch_guess* dispatch;
    char padding2[0x36];
    char active;
    // EXTERNAL: TITANIUM 0x0059D960 CallbackOwner2_guess::GetScreenRect
    void GetScreenRect(int* output_guess);
    // EXTERNAL: TITANIUM 0x0059DB70 CallbackOwner2_guess::Finish_guess
    void Finish_guess(int first, int second);
    void Invoke_guess(int first, int second);
    void BuildMessage_guess(int first, int second);
};

// Mouse left a submenu item: tells the menu to close its open submenu (0x25).
// FUNCTION: TITANIUM 0x004EA648
void CallbackOwner2_guess::Invoke_guess(int first, int second) {
    if (active != 0) {
        dispatch->Slot32_guess(this, 0x25, 0);
    }
    Finish_guess(first, second);
}

// Mouse over a submenu item: asks the menu to open it at the item's rect (0x24).
// FUNCTION: TITANIUM 0x004EA7A5
void CallbackOwner2_guess::BuildMessage_guess(int first, int second) {
    int message[4];
    if (active != 0) {
        GetScreenRect(message);
        dispatch->Slot32_guess(this, 0x24, message);
    }
    Finish_guess(first, second);
}

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int first_guess, int second_guess, int third_guess);

// Command item click: reports 0x26 (close the menus), then runs the command (ExecuteCmd).
// FUNCTION: TITANIUM 0x004EAA49
int CascadeCommandItemWnd_guess::Handle_guess(ChildWindow_guess* sender_guess, unsigned int message_guess, int* data_guess) {
    if (message_guess == 1 && sender_guess == button_guess) {
        callback_at_28_guess->Slot32_guess(this, 0x26, 0);
        ExecuteCmd(field_164_guess, 1, 0);
        return 0;
    }
    return WndNotification(sender_guess, message_guess, data_guess);
}

struct Activator_guess {
    char padding[0x10];
    unsigned int active;
    // EXTERNAL: TITANIUM 0x0042F092 Activator_guess::Initialize_guess
    void Initialize_guess(int value);
    Activator_guess* Activate_guess();
};

struct Base2_guess {
    virtual void Anchor_guess();
    // EXTERNAL: TITANIUM 0x005A3100 Base2_guess::~Base2_guess
    virtual ~Base2_guess();
};

struct Constructed2_guess : Base2_guess {
    // EXTERNAL: TITANIUM 0x005A0A80 Constructed2_guess::Initialize_guess
    void Initialize_guess(int first, int second);
    virtual ~Constructed2_guess();
    Constructed2_guess* Destroy_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x00651E90 ??_7Constructed2_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// Destructor of a cascade menu window (vtable 0x651E90): hides it (Show(0, 1), 0x005A0A80), then runs
// the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004EAB53
Constructed2_guess::~Constructed2_guess() {
    Initialize_guess(0, 1);
}

// Scalar deleting destructor of a cascade menu window (vtable 0x651E90 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x004EAB8F
Constructed2_guess* Constructed2_guess::Destroy_guess(unsigned char flags_guess) {
    this->Constructed2_guess::~Constructed2_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x004FF9C9 FindEntry_guess
int* __stdcall FindEntry_guess(int value);

// Menu manager (0x991758): returns the menu window registered under id `value` (hash lookup
// 0x004FF9C9), or 0. Every by-id operation here (open, close, hide, destroy, remove) starts with it.
// FUNCTION: TITANIUM 0x004EABAB
int __stdcall FindEntryValue_guess(int value) {
    int result = 0;
    int* entry = FindEntry_guess(value);
    if (entry != 0) {
        result = *entry;
    }
    return result;
}

struct Dispatch_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value_guess);
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
    char pad_0004[0x38];
    int x_3c_guess;
    int y_40_guess;
    int x_44_guess;
    int y_48_guess;
    char pad_004c[0x10];
    char active_5c;
    char pad_005d[0xff];
    int value_15c;
    char pad_0160[0xc];
    int id_16c;
    char flag_170_guess;
    char pad_0171[3];
    int value_174_guess;
    // EXTERNAL: TITANIUM 0x0059D960 Dispatch_guess::GetScreenRect
    Bounds_guess* GetScreenRect(int* state_guess);
    // EXTERNAL: TITANIUM 0x0059FA70 Dispatch_guess::SetPosition_guess
    void SetPosition_guess(CXPoint* position_guess);
};

// EXTERNAL: TITANIUM 0x005595DB GetEQScreenRes_guess
void __cdecl GetEQScreenRes_guess(int* width_guess, int* height_guess);

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x004EABAB Manager_guess::Find_guess
    Dispatch_guess* Find_guess(int value_guess);
    void OpenSubmenu_guess(int value_guess, int* point_guess);
    void CloseMenuChain_guess(int value_guess);
};

// Opens menu `value_guess` beside its parent item (`point_guess` is the item rect), flipping to the left when
// it would leave the screen and keeping it on screen vertically.
// FUNCTION: TITANIUM 0x004EABC3
// @early-stop: budget, diff ndiff=23
void Manager_guess::OpenSubmenu_guess(int value_guess, int* point_guess) {
    CXPoint position_guess;
    int width_guess;
    int height_guess;
    Dispatch_guess* object_guess = Find_guess(value_guess);
    if (object_guess != 0 && object_guess->active_5c == 0) {
        GetEQScreenRes_guess(&width_guess, &height_guess);
        char flag_guess = 0;
        Dispatch_guess* parent_guess = 0;
        if (object_guess->id_16c != -1 &&
            (parent_guess = Find_guess(object_guess->id_16c)) != 0 &&
            (flag_guess = parent_guess->flag_170_guess) != 0) {
            position_guess.x = (object_guess->x_3c_guess - object_guess->x_44_guess) + point_guess[0];
        } else {
            position_guess.x = point_guess[2];
        }
        char result_guess = 0;
        if (position_guess.x < 0) {
            position_guess.x = point_guess[2];
        } else if ((object_guess->x_44_guess - object_guess->x_3c_guess) + position_guess.x > width_guess) {
            result_guess = 1;
            position_guess.x = (point_guess[0] - object_guess->x_44_guess) + object_guess->x_3c_guess;
        } else {
            result_guess = flag_guess;
        }
        position_guess.y = point_guess[1];
        if ((object_guess->y_48_guess - object_guess->y_40_guess) + position_guess.y > height_guess) {
            position_guess.y = (object_guess->y_40_guess - object_guess->y_48_guess) + height_guess;
        }
        if (position_guess.y < 0) {
            position_guess.y = 0;
        }
        object_guess->flag_170_guess = result_guess;
        object_guess->SetPosition_guess(&position_guess);
        object_guess->Slot48_guess(1, 1);
        object_guess->value_174_guess = 0;
    }
}

// Walks up to the top-level menu and hides it, which closes the whole chain.
// FUNCTION: TITANIUM 0x004EACB7
void Manager_guess::CloseMenuChain_guess(int value_guess) {
    Dispatch_guess* object_guess = Find_guess(value_guess);
    int id_guess = object_guess->id_16c;
    while (id_guess != -1) {
        Dispatch_guess* parent_guess = Find_guess(id_guess);
        if (parent_guess == 0) {
            break;
        }
        id_guess = object_guess->id_16c;
        object_guess = parent_guess;
    }
    object_guess->Slot48_guess(0, 1);
}

struct Cursor_guess {
    Dispatch_guess* object_guess;
};

struct ListStorage_guess {
    int* entries_guess;
    // EXTERNAL: TITANIUM 0x004C9745 ListStorage_guess::~ListStorage_guess
    ~ListStorage_guess();
};

struct List_guess {
    ListStorage_guess storage_guess;
    // EXTERNAL: TITANIUM 0x004466FA List_guess::First_guess
    Cursor_guess* First_guess();
    // EXTERNAL: TITANIUM 0x004EABAB List_guess::Find_guess
    Dispatch_guess* Find_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0042EC1A List_guess::Next_guess
    Cursor_guess* Next_guess(Cursor_guess* cursor_guess);
    // EXTERNAL: TITANIUM 0x0047C339 List_guess::RemoveEntry_guess
    void RemoveEntry_guess(Dispatch_guess* const* object_guess, int value_guess);
    void ClearAll_guess();
    void Remove_guess(int value_guess);
    void Purge_guess(int value_guess);
    void HitTest_guess(int x_guess, int y_guess);
    ~List_guess();
};

// Menu manager: hides menu `value` (Show(0, 1)) when it exists. Used when a submenu closes (message
// 0x25), when a menu is removed (0x004EB20E), by AboutToHide (0x004EAE39) and by the EQ button.
// FUNCTION: TITANIUM 0x004EACFA
void __stdcall FUN_004eacfa_guess(int value) {
    int object = FindEntryValue_guess(value);
    if (object != 0) {
        ((Dispatch_guess*)object)->Slot48_guess(0, 1);
    }
}

// Turns every registered menu off (virtual slot 48 with 0).
// FUNCTION: TITANIUM 0x004EAD18
void List_guess::ClearAll_guess() {
    Cursor_guess* cursor = First_guess();
    while (cursor != 0) {
        Dispatch_guess* object = cursor->object_guess;
        cursor = Next_guess(cursor);
        object->Slot48_guess(0, 1);
    }
}

// A click outside every visible menu closes them all.
// FUNCTION: TITANIUM 0x004EAD4A
void List_guess::HitTest_guess(int x_guess, int y_guess) {
    CXPoint point;
    point.x = x_guess;
    point.y = y_guess;
    Cursor_guess* cursor = First_guess();
    bool tested = false;
    if (cursor != 0) {
        do {
            Dispatch_guess* object = cursor->object_guess;
            if (object->active_5c != 0) {
                int state_guess[4];
                tested = true;
                if (object->GetScreenRect(state_guess)->Contains_guess(&point) != 0) {
                    return;
                }
            }
            cursor = Next_guess(cursor);
        } while (cursor != 0);
        if (tested) {
            ClearAll_guess();
        }
    }
}

// Destroys every submenu whose parent is `value_guess`, recursively.
// FUNCTION: TITANIUM 0x004EADB0
// @early-stop: budget, structural ndiff=34
void List_guess::Remove_guess(int value_guess) {
    if (FindEntryValue_guess(value_guess) != 0) {
        Cursor_guess* cursor = First_guess();
        if (cursor != 0) {
            do {
                Dispatch_guess* object = cursor->object_guess;
                cursor = Next_guess(cursor);
                if (object->id_16c == value_guess) {
                    Remove_guess(object->value_15c);
                    RemoveEntry_guess(&object, object->value_15c);
                    object->Slot01_guess(1);
                }
            } while (cursor != 0);
        }
    }
}

struct CallbackContext_guess {
    // EXTERNAL: TITANIUM 0x004EACFA CallbackContext_guess::Notify_guess
    void Notify_guess(int value);
};

struct CallbackOwner_guess {
    char padding[0x168];
    int pending;
    int reserved;
    char active;
    char Finish_guess();
};

// Cascade menu AboutToHide (vtable 0x651E90 slot 50): hides its open submenu (+0x168) through the
// manager and clears the open flag (+0x170); never vetoes.
// FUNCTION: TITANIUM 0x004EAE39
char CallbackOwner_guess::Finish_guess() {
    if (pending != 0) {
        EQ_GLOBAL(CallbackContext_guess*, 0x00991758)->Notify_guess(pending);
    }
    active = 0;
    return 1;
}

struct EntryRecord_guess {
    char padding[0x5c];
    char value;
};

struct Target_guess {
    char Read_guess(int value);
};

// Menu manager: whether menu `value` is shown (window +0x5C); 0 when it does not exist. The EQ button
// polls it each frame to pop back out once its menu has closed (0x004FFD6E).
// FUNCTION: TITANIUM 0x004EAE22
char Target_guess::Read_guess(int value) {
    int entry = FindEntryValue_guess(value);
    char result;
    if (entry != 0) {
        result = ((EntryRecord_guess*)entry)->value;
    } else {
        result = 0;
    }
    return result;
}

struct Sender_guess : CXWnd {
    char pad_11c_guess[0x164 - 0x11C];
    int field_164_guess;  // 0x164
};

struct Window_guess : CSidlScreenWnd {
    int field_15c_guess;  // 0x15c
    char pad_160_guess[0x8];
    int field_168_guess;  // 0x168
    int Handle_guess(Sender_guess* sender_guess, unsigned int message_guess, int* data_guess);
};

// Menu side of the item messages: 0x24 closes the previously open submenu and opens the item's, 0x25 closes
// it, 0x26 closes the chain.
// FUNCTION: TITANIUM 0x004EB0F2
int Window_guess::Handle_guess(Sender_guess* sender_guess, unsigned int message_guess, int* data_guess) {
    if (message_guess == 0x24) {
        int value_guess = field_168_guess;
        if (value_guess != -1 && sender_guess->field_164_guess != value_guess) {
            EQ_GLOBAL(CallbackContext_guess*, 0x00991758)->Notify_guess(value_guess);
            field_168_guess = -1;
        }
        EQ_GLOBAL(Manager_guess*, 0x00991758)->OpenSubmenu_guess(sender_guess->field_164_guess, data_guess);
        field_168_guess = sender_guess->field_164_guess;
        return 0;
    } else if (message_guess == 0x25) {
        int value_guess = field_168_guess;
        if (value_guess != -1) {
            EQ_GLOBAL(CallbackContext_guess*, 0x00991758)->Notify_guess(value_guess);
            field_168_guess = -1;
        }
    } else if (message_guess == 0x26) {
        EQ_GLOBAL(Manager_guess*, 0x00991758)->CloseMenuChain_guess(field_15c_guess);
    } else {
        return CSidlScreenWnd::WndNotification(sender_guess, message_guess, data_guess);
    }
    return 0;
}

struct Record_guess {
    char pad_0000_guess[0x0C];
    int id_guess;           // 0x0c
    CXStr text_guess;       // 0x10
    int value_guess;        // 0x14
};

struct Text_guess : CXStr {
    // EXTERNAL: TITANIUM 0x004CC626 Text_guess::GetChar_guess
    char GetChar_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005BA560 Text_guess::Normalize_guess
    void Normalize_guess();
};

struct Key_guess {
    CStrRep* ptr_guess;
    ~Key_guess() {
        reinterpret_cast<Text_guess*>(this)->~Text_guess();
    }
};

struct RefreshLookup_guess {
    // EXTERNAL: TITANIUM 0x004B244F RefreshLookup_guess::Fill_guess
    Text_guess* Fill_guess(int id_guess, Key_guess* out_guess);
};
#define pRefreshLookup_guess EQ_GLOBAL(RefreshLookup_guess*, 0x0098599C)

struct Index_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 Index_guess::Find_guess
    int Find_guess(int id_guess);
};

// EXTERNAL: TITANIUM 0x004B1357 ??H@YA?AUCXStr@@ABU0@PBD@Z
CXStr operator+(const CXStr& left_guess, const char* right_guess);
// EXTERNAL: TITANIUM 0x004D9090 ??H@YA?AUCXStr@@ABU0@0@Z
CXStr operator+(const CXStr& left_guess, const CXStr& right_guess);

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
    virtual void Slot63_guess(CXStr* text_guess);
    char pad_0004_guess[0x74];
    CXStr text_78_guess;    // 0x78
    char pad_007C_guess[0xB8];
    int field_134_guess;    // 0x134
    char pad_0138_guess[0x34];
    int field_16c_guess;    // 0x16c
};

struct Panel_guess {
    char pad_0000_guess[0x15C];
    Record_guess* record_guess;     // 0x15c
    char pad_0160_guess[0x4];
    int field_164_guess;            // 0x164
    Child_guess* child_guess;       // 0x168
    void Refresh_guess();
};

// Command label: the item text plus its bound key (between the strings at 0x641688/0x641684) unless the key
// text starts with '-' (unbound); the icon comes from the record's id.
// FUNCTION: TITANIUM 0x004EA87C
// @early-stop: budget, structural ndiff=24
void Panel_guess::Refresh_guess() {
    Record_guess* record = record_guess;
    if (record == 0 || child_guess == 0) {
        return;
    }
    int id_guess = record->value_guess;
    Key_guess key_guess;
    Text_guess& key = *reinterpret_cast<Text_guess*>(&key_guess);
    pRefreshLookup_guess->Fill_guess(field_164_guess = id_guess, &key_guess)->Normalize_guess();
    CXStr text_guess = record->text_guess;
    CXStr result_guess = text_guess;
    if (key.GetChar_guess(0) != '-') {
        result_guess = ((text_guess + EQ_ARRAY(char, 0x00641688)) + key) + EQ_ARRAY(char, 0x00641684);
    }
    child_guess->Slot63_guess(&text_guess);
    child_guess->text_78_guess = result_guess;
    if (record->id_guess == -1) {
        child_guess->field_16c_guess = 0;
    } else {
        child_guess->field_16c_guess = EQ_GLOBAL(Index_guess*, 0x00991914)->Find_guess(record->id_guess);
    }
    int args_guess[4];
    args_guess[0] = child_guess->field_134_guess + 4;
    args_guess[1] = 0;
    args_guess[2] = 0;
    args_guess[3] = 0;
    ((Owner_guess*)child_guess)->Build_guess(args_guess);
}

// Constructor of the cascade menu manager (0x991758, created during UI setup in 0x0043EFDD): a table
// of menus by id with 16 buckets requested (0x0042F092, rounded up to 17) and the next id (+0x10) =
// 1.
// FUNCTION: TITANIUM 0x004EB19D
Activator_guess* Activator_guess::Activate_guess() {
    Initialize_guess(0x10);
    active = 1;
    return this;
}

// Destructor: turns every registered menu off (0x004EAD18, virtual slot 48 with 0), then deletes each
// one (virtual slot 1 with flag 1).
// FUNCTION: TITANIUM 0x004EB1B2
// @early-stop: budget, structural ndiff=1
List_guess::~List_guess() {
    ClearAll_guess();
    Cursor_guess* cursor_guess = First_guess();
    while (cursor_guess != 0) {
        Dispatch_guess* object_guess = cursor_guess->object_guess;
        cursor_guess = Next_guess(cursor_guess);
        if (object_guess != 0) {
            object_guess->Slot01_guess(1);
        }
    }
}

// Removes menu `value_guess`: turns it off (0x004EACFA), drops it from both lookups and deletes the
// window (virtual slot 1 with flag 1).
// FUNCTION: TITANIUM 0x004EB20E
void List_guess::Purge_guess(int value_guess) {
    FUN_004eacfa_guess(value_guess);
    Dispatch_guess* window_guess = Find_guess(value_guess);
    Dispatch_guess* object_guess = window_guess;
    if (window_guess != 0) {
        Remove_guess(value_guess);
        RemoveEntry_guess(&object_guess, value_guess);
        window_guess->Slot01_guess(1);
    }
}

// Destructor of a submenu item (CascadeSubmenuItemWnd, vtable 0x651C40): removes its submenu (+0x164)
// from the menu manager (0x004EB20E), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004EB254
CascadeSubmenuItemWnd_guess::~CascadeSubmenuItemWnd_guess() {
    EQ_GLOBAL(List_guess*, 0x00991758)->Purge_guess(field_164_guess);
}

struct Selector_guess : CSidlScreenWnd {
    int selected_guess;      // 0x15c
    int menuCollection_0160_guess;     // 0x160
    char dirty_guess;        // 0x164
    void BuildItems_guess();
    // EXTERNAL: TITANIUM 0x0059D110 Selector_guess::FirstChild_guess
    CXWnd* FirstChild_guess();
    // EXTERNAL: TITANIUM 0x0059FEE0 Selector_guess::NextChild_guess
    CXWnd* NextChild_guess(CXWnd* child_guess);
    // EXTERNAL: TITANIUM 0x0059FB00 Selector_guess::SetBounds_guess
    void SetBounds_guess(CXRect* bounds_guess);
    int Select_guess(int value_guess);
};

struct MenuRecord_guess {
    int id_guess;
    int type_guess;
};

struct MenuCollection_guess {
    int count_guess;
    // EXTERNAL: TITANIUM 0x004EB905 MenuCollection_guess::GetRecord_guess
    MenuRecord_guess* GetRecord_guess(int index_guess);
};

struct ChildDispatcher_guess {
    // EXTERNAL: TITANIUM 0x005AEA70 ChildDispatcher_guess::Visit_guess
    void Visit_guess(CXWnd* child_guess);
};

struct ChildContext_guess {
    ChildDispatcher_guess* dispatcher_guess;
};

struct PositionWindow_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x0059FA70 PositionWindow_guess::SetPosition_guess
    void SetPosition_guess(CXPoint* position_guess);
};

struct MenuVTable_guess {
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
    virtual CXRect GetParentBounds_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void SetRecord_guess(MenuRecord_guess* record_guess) = 0;
};

// EXTERNAL: TITANIUM 0x00574110 Report_guess
void __cdecl Report_guess(const char* format_guess, int value_guess);

// Rebuilds the menu from its record list: one item window per record (0 submenu, 1 command, 2 separator),
// stacked and sized to the widest. Unknown types are logged and skipped.
// FUNCTION: TITANIUM 0x004EAE5D
// @early-stop: budget, structural ndiff=77
void Selector_guess::BuildItems_guess() {
    EQ_GLOBAL(List_guess*, 0x00991758)->Remove_guess(selected_guess);

    CXWnd* child_guess = FirstChild_guess();
    while (child_guess != 0) {
        EQ_GLOBAL(ChildContext_guess*, 0x0099D334)->dispatcher_guess->Visit_guess(child_guess);
        child_guess = NextChild_guess(child_guess);
    }

    MenuCollection_guess* collection_guess = (MenuCollection_guess*)menuCollection_0160_guess;
    if (collection_guess != 0) {
        CXPoint position_guess;
        position_guess.x = 0;
        position_guess.y = 0;
        int max_width_guess = 0;
        int total_height_guess = 0;
        for (int index_guess = 0; index_guess < collection_guess->count_guess; ++index_guess) {
            MenuRecord_guess* record_guess = collection_guess->GetRecord_guess(index_guess);
            Base_constructed_guess* item_guess = 0;
            switch (record_guess->type_guess) {
            case 0:
                item_guess = new CascadeSubmenuItemWnd_guess(this, CXStr("CascadeSubmenuItemWnd"),
                    selected_guess);
                break;
            case 1:
                item_guess = new CascadeCommandItemWnd_guess(this, CXStr("CascadeCommandItemWnd"),
                    selected_guess);
                break;
            case 2:
                item_guess = new CascadeSeparatorItemWnd_guess(this, CXStr("CascadeSeparatorItemWnd"),
                    selected_guess);
                break;
            default:
                Report_guess("Unknown menu item type %d in CascadeMenu, skipping.",
                    record_guess->type_guess);
                break;
            }

            ((MenuVTable_guess*)item_guess)->SetRecord_guess(record_guess);
            position_guess.y = total_height_guess;
            ((PositionWindow_guess*)item_guess)->SetPosition_guess(&position_guess);
            CXWnd* window_guess = (CXWnd*)item_guess;
            total_height_guess += window_guess->Location.bottom - window_guess->Location.top;
            int width_guess = window_guess->Location.right - window_guess->Location.left;
            if (max_width_guess < width_guess) {
                max_width_guess = width_guess;
            }
        }

        CXRect parent_bounds_guess = ((MenuVTable_guess*)this)->GetParentBounds_guess();
        CXRect bounds_guess = GetScreenRect();
        bounds_guess.right = bounds_guess.left +
            ((bounds_guess.right - parent_bounds_guess.right) - bounds_guess.left) +
            parent_bounds_guess.left + max_width_guess;
        bounds_guess.bottom = bounds_guess.top +
            ((parent_bounds_guess.top - bounds_guess.top) - parent_bounds_guess.bottom) +
            bounds_guess.bottom + total_height_guess;
        SetBounds_guess(&bounds_guess);
    }
}

// Cascade menu window: sets its record list (+0x160) and rebuilds the items from it (0x004EAE5D);
// returns the previous list. The menu creation (0x004EB2B9) calls it on each new window.
// FUNCTION: TITANIUM 0x004EB298
int Selector_guess::Select_guess(int value_guess) {
    int old_guess = menuCollection_0160_guess;
    menuCollection_0160_guess = value_guess;
    dirty_guess = 1;
    BuildItems_guess();
    return old_guess;
}

// Scalar deleting destructor of a submenu item (vtable 0x651C40 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x004EB328
CascadeSubmenuItemWnd_guess* CascadeSubmenuItemWnd_guess::Destroy_guess(unsigned char flags_guess) {
    this->CascadeSubmenuItemWnd_guess::~CascadeSubmenuItemWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

struct Rec_guess {
    char pad_0000_guess[0xc];
    int id_guess;        // 0x0c
    CXStr text_guess;    // 0x10
    int field_14_guess;  // 0x14
};

struct Extent_guess {
    char pad_0000_guess[0x3c];
    int field_3c_guess;  // 0x3c
    char pad_0040_guess[4];
    int field_44_guess;  // 0x44
};

struct Holder_guess {
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
    virtual void Slot63_guess(const CXStr& text_guess);  // 0xfc
    char pad_0004_guess[0x74];
    CXStr text_78_guess;       // 0x78
    char pad_007c_guess[0xb8];
    int field_134_guess;       // 0x134
    char pad_0138_guess[0x34];
    void* field_16c_guess;     // 0x16c
};

struct Lookup_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 Lookup_guess::Find_guess
    void* Find_guess(int id_guess);
};

struct Table_guess {
    char pad_0000_guess[0x10];
    int next_id_guess;  // 0x10
    int Resolve_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00447C66 Table_guess::Insert_guess
    void Insert_guess(CascadeWnd_guess* const* window_guess, int key_guess);
};

// Creates a menu window for record list `first_guess` with parent `second_guess`; returns its new id.
// FUNCTION: TITANIUM 0x004EB2B9
// @early-stop: tiebreak, structural ndiff=7
int Table_guess::Resolve_guess(int first_guess, int second_guess) {
    CascadeWnd_guess* created_guess = new CascadeWnd_guess(0, second_guess);
    int id_guess = next_id_guess++;
    CascadeWnd_guess* window_guess = created_guess;
    window_guess->field_15c_guess = id_guess;
    ((Selector_guess*)window_guess)->Select_guess(first_guess);
    Insert_guess(&window_guess, id_guess);
    return id_guess;
}

struct Pick_guess {
    char pad_0000_guess[0x15c];
    Rec_guess* rec_guess;        // 0x15c
    int field_160_guess;         // 0x160
    int field_164_guess;         // 0x164
    Holder_guess* holder_guess;  // 0x168
    Extent_guess* extent_guess;  // 0x16c
    void Update_guess();
};

// Submenu item: sets label and icon, then creates its submenu (Resolve_guess) and sizes the button.
// FUNCTION: TITANIUM 0x004EB344
void Pick_guess::Update_guess() {
    Rec_guess* rec = rec_guess;
    if (rec != 0 && holder_guess != 0) {
        holder_guess->Slot63_guess(rec->text_guess);
        holder_guess->text_78_guess = rec->text_guess;
        if (rec->id_guess != -1) {
            holder_guess->field_16c_guess = EQ_GLOBAL(Lookup_guess*, 0x00991914)->Find_guess(rec->id_guess);
        } else {
            holder_guess->field_16c_guess = 0;
        }
        int second_guess = field_160_guess;
        int first_guess = rec->field_14_guess;
        field_164_guess = EQ_GLOBAL(Table_guess*, 0x00991758)->Resolve_guess(first_guess, second_guess);
        Extent_guess* extent = extent_guess;
        int extent_size = 0;
        if (extent != 0) {
            extent_size = extent->field_44_guess - extent->field_3c_guess;
        }
        int local[4];
        local[0] = holder_guess->field_134_guess + 4;
        local[1] = 0;
        local[3] = 0;
        local[2] = extent_size + 4;
        ((Owner_guess*)holder_guess)->Build_guess(local);
    }
}

