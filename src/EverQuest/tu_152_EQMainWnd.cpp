// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 152: a hint from compare/tumap.py.
// Three pieces: CEditLabelWnd's Activate and notifications (the map label editor of tu_151: text, colour,
// size), the icon caches behind A_DragItem (0x991910, item icons 500-5000) and A_MenuIcons (0x991914),
// and the CEQMainWnd constructor. The *_004ff... structs are per-function views of these objects.
#include "titanium/types.h"
#include "titanium/wnd/CColorPickerWnd.h"

struct CEditLabelWnd_guess;

struct Child_004ff8fb_guess {
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
    virtual void Select_guess(CEditLabelWnd_guess*, int, int);
};

struct CEditLabelWnd_guess {
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
    virtual void HandleSelection_guess();

    char pad_004ff8fb_guess[0x158];
    Child_004ff8fb_guess* child_guess; // 0x15C
    int value_guess; // 0x160
    int state_guess; // 0x164
    int pad_168_guess; // 0x168
    int key_16c_guess; // 0x16C
    int key_170_guess; // 0x170
    int key_174_guess; // 0x174
    int key_178_guess; // 0x178
    int key_17c_guess; // 0x17C
    int key_180_guess; // 0x180

    // EXTERNAL: TITANIUM 0x0059DD30 CEditLabelWnd_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CEditLabelWnd_guess::WndNotification
    int WndNotification(int, int, int);
    int WndNotification_guess(int, int, int);
};


// Done (+0x180) reports back through the owner's virtual (code 6) and closes; Cancel (+0x17C) closes; the
// size buttons set +0x164; Choose Color (+0x16C) opens CColorPickerWnd (0x850C0C), whose pick comes back as
// notification 0x20.
// FUNCTION: TITANIUM 0x004FF8FB
int CEditLabelWnd_guess::WndNotification_guess(int token, int control, int extra) {
    if (!IsActive_guess())
        return 0;
    if (control == 0x20) {
        value_guess = extra;
        return 0;
    }
    if (control == 1) {
        if (token == key_180_guess) {
            if (child_guess != 0) {
                child_guess->Select_guess(this, 6, 0);
                HandleSelection_guess();
            }
        } else if (token == key_17c_guess) {
            HandleSelection_guess();
        } else if (token == key_170_guess) {
            state_guess = 3;
        } else if (token == key_174_guess) {
            state_guess = 2;
        } else if (token == key_178_guess) {
            state_guess = 1;
        } else if (token == key_16c_guess) {
            pinstCColorPickerWnd_guess->Activate_guess(this, value_guess);
        }
    }
    return WndNotification(token, control, extra);
}

struct HashNode_004ff9c9_guess {
    unsigned int unused;
    unsigned int key;
    HashNode_004ff9c9_guess* next;
};

struct HashTable_004ff9c9_guess {
    HashNode_004ff9c9_guess** buckets;
    unsigned int bucketCount;

    HashNode_004ff9c9_guess* FindNode_guess(unsigned int key);
};

// Hash table lookup: the node whose key is `key` (bucket key % bucket count, then the chain), or 0. A
// shared helper: journal text, database strings, AA abilities, the player-name hash, menus by id.
// FUNCTION: TITANIUM 0x004FF9C9
HashNode_004ff9c9_guess* HashTable_004ff9c9_guess::FindNode_guess(unsigned int key) {
    HashNode_004ff9c9_guess* node = buckets[key % bucketCount];
    while (node != 0 && node->key != key)
        node = node->next;
    return node;
}

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* operator new(unsigned size_guess);

struct CTextureAnimationView_guess {
    char pad_guess[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0CTextureAnimationView_guess@@QAE@XZ
    CTextureAnimationView_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B CTextureAnimationView_guess::Bind_guess
    void Bind_guess(int value);
    // EXTERNAL: TITANIUM 0x005B1AB0 CTextureAnimationView_guess::Adjust_guess
    void Adjust_guess(int delta);
};

struct Pool_004ffbe9_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 Pool_004ffbe9_guess::Lookup_guess
    int Lookup_guess(int* field);
};

#define g_pool_004ffbe9_guess EQ_GLOBAL(Pool_004ffbe9_guess*, 0x0099D3F4)

struct IconCache_guess : HashTable_004ff9c9_guess {
    char pad_08_guess[0x8];
    int field_10_guess; // 0x10
    int offset_14_guess; // 0x14
    int min_18_guess; // 0x18
    int max_1c_guess; // 0x1C

    // EXTERNAL: TITANIUM 0x00447C66 IconCache_guess::Insert_guess
    void Insert_guess(CTextureAnimationView_guess** slot, int key);
    int GetIcon_guess(int key);
};

// Icon `id` as a CTextureAnimation, made on first use: ids outside min..max (+0x18, +0x1C) fall back to
// min, and the cell is id - offset (+0x14).
// FUNCTION: TITANIUM 0x004FFBE9
int IconCache_guess::GetIcon_guess(int id) {
    if (id < min_18_guess || id > max_1c_guess)
        id = min_18_guess;
    CTextureAnimationView_guess** slot = (CTextureAnimationView_guess**)FindNode_guess(id);
    if (slot == 0) {
        CTextureAnimationView_guess* obj = new CTextureAnimationView_guess();
        // `stored` is read through `slot` after this block ends; hoisting it out of the block breaks the match.
        {
            CTextureAnimationView_guess* stored = obj;
            obj->Bind_guess(g_pool_004ffbe9_guess->Lookup_guess(&field_10_guess));
            obj->Adjust_guess(id - offset_14_guess);
            Insert_guess(&stored, id);
            slot = &stored;
        }
    }
    return (int)*slot;
}

struct Object_004ffa1a_guess {
    char pad[0x10];
    int state; // 0x10

    // EXTERNAL: TITANIUM 0x00435652 Object_004ffa1a_guess::Initialize_guess
    void Initialize_guess(unsigned int flags);
    Object_004ffa1a_guess* Reset_guess();
};

// Cache constructor: an empty hash table (0x435652, 0x100).
// FUNCTION: TITANIUM 0x004FFA1A
Object_004ffa1a_guess* Object_004ffa1a_guess::Reset_guess() {
    Initialize_guess(0x100);
    state = 0;
    return this;
}

struct Callback_004ff9ec_guess {
    virtual void Invoke_guess(int value);
};

struct Cursor_004ff9ec_guess {
    Callback_004ff9ec_guess* callback;
};

struct Base_004ffa2f_guess {
    char pad_guess[0x10];
    // EXTERNAL: TITANIUM 0x00490E9C Base_004ffa2f_guess::~Base_004ffa2f_guess
    ~Base_004ffa2f_guess();
};

struct Member_004ffa2f_guess {
    // EXTERNAL: TITANIUM 0x004482FB Member_004ffa2f_guess::~Member_004ffa2f_guess
    ~Member_004ffa2f_guess();
    // EXTERNAL: TITANIUM 0x00571F70 Member_004ffa2f_guess::Transfer_guess
    void Transfer_guess(int* value);
};

struct Value_004ffa70_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Value_004ffa70_guess@@QAE@PBD@Z
    Value_004ffa70_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00571D00 Value_004ffa70_guess::FreeRep
    void FreeRep(int value);
    ~Value_004ffa70_guess() {
        if (value_guess != 0)
            FreeRep(value_guess);
    }
};

struct Owner_004ff9ec_guess : Base_004ffa2f_guess {
    Member_004ffa2f_guess member_guess;
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x004466FA Owner_004ff9ec_guess::First_guess
    Cursor_004ff9ec_guess* First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A Owner_004ff9ec_guess::Next_guess
    Cursor_004ff9ec_guess* Next_guess(Cursor_004ff9ec_guess* cursor);
    // EXTERNAL: TITANIUM 0x0048F513 Owner_004ff9ec_guess::Finish_guess
    void Finish_guess();
    ~Owner_004ff9ec_guess();
    void SetAnimationName_guess(Value_004ffa70_guess value);
};

// Destructor of an icon animation cache (A_DragItem / A_MenuIcons): deletes every cached animation
// (0x004FF9EC), destroys the name string (+0x10), then frees the hash table (0x00490E9C).
// FUNCTION: TITANIUM 0x004FFA2F
Owner_004ff9ec_guess::~Owner_004ff9ec_guess() {
    Clear_guess();
}

// Sets the animation name and empties the cache.
// FUNCTION: TITANIUM 0x004FFA70
void Owner_004ff9ec_guess::SetAnimationName_guess(Value_004ffa70_guess value) {
    member_guess.Transfer_guess(&value.value_guess);
    Clear_guess();
}

// Deletes every cached animation and empties the table.
// FUNCTION: TITANIUM 0x004FF9EC
void Owner_004ff9ec_guess::Clear_guess() {
    Cursor_004ff9ec_guess* cursor = First_guess();
    while (cursor != 0) {
        if (cursor->callback != 0)
            cursor->callback->Invoke_guess(1);
        cursor = Next_guess(cursor);
    }
    Finish_guess();
}

struct Animation_004ffab8_guess {
    char pad_004ffab8_guess[0x10];
    Value_004ffa70_guess name_guess; // 0x10
    int field_14_guess; // 0x14
    int field_18_guess; // 0x18
    int field_1c_guess; // 0x1C

    // EXTERNAL: TITANIUM 0x004FFA1A ??0Animation_004ffab8_guess@@QAE@XZ
    Animation_004ffab8_guess();
    // EXTERNAL: TITANIUM 0x004FFA70 ?SetAnimationName_guess@Animation_004ffab8_guess@@QAEXUValue_004ffa70_guess@@@Z
    void SetAnimationName_guess(Value_004ffa70_guess value);
};

#define g_dragItemAnimation_004ffab8_guess EQ_GLOBAL(Animation_004ffab8_guess*, 0x00991910)
#define g_menuIconsAnimation_004ffab8_guess EQ_GLOBAL(Animation_004ffab8_guess*, 0x00991914)

// Creates the two icon caches: A_DragItem for ids 500-5000 (cell = id - 500) and A_MenuIcons for 0-35.
// FUNCTION: TITANIUM 0x004FFAB8
void __cdecl InitIconCaches_guess() {
    if (g_dragItemAnimation_004ffab8_guess == 0) {
        g_dragItemAnimation_004ffab8_guess = new Animation_004ffab8_guess;
        g_dragItemAnimation_004ffab8_guess->SetAnimationName_guess("A_DragItem");
        g_dragItemAnimation_004ffab8_guess->field_14_guess = 500;
        g_dragItemAnimation_004ffab8_guess->field_18_guess = 500;
        g_dragItemAnimation_004ffab8_guess->field_1c_guess = 5000;
    }
    if (g_menuIconsAnimation_004ffab8_guess == 0) {
        g_menuIconsAnimation_004ffab8_guess = new Animation_004ffab8_guess;
        g_menuIconsAnimation_004ffab8_guess->SetAnimationName_guess("A_MenuIcons");
        g_menuIconsAnimation_004ffab8_guess->field_14_guess = 0;
        g_menuIconsAnimation_004ffab8_guess->field_18_guess = 0;
        g_menuIconsAnimation_004ffab8_guess->field_1c_guess = 0x23;
    }
}

// Deletes the A_DragItem (0x991910) and A_MenuIcons (0x991914) icon caches and clears both globals. The
// last step of tearing down the in-game UI (0x0043AF46).
// FUNCTION: TITANIUM 0x004FFBA8
void __cdecl FreeIconCaches_guess() {
    delete (Owner_004ff9ec_guess*)g_dragItemAnimation_004ffab8_guess;
    g_dragItemAnimation_004ffab8_guess = 0;
    delete (Owner_004ff9ec_guess*)g_menuIconsAnimation_004ffab8_guess;
    g_menuIconsAnimation_004ffab8_guess = 0;
}

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CascadeMenuList.h"


// EXTERNAL: TITANIUM 0x00441AC6 CreateMainMenu_guess
void* CreateMainMenu_guess();

// EXTERNAL: TITANIUM 0x00653C60 ??_7CEQMainWnd_guess@@6B@
struct CEQMainWnd_guess : CSidlScreenWndBase {
    CXWnd* button_15c;                  // 0x15C
    void* value_160;                    // 0x160
    int state_164;                      // 0x164

    CEQMainWnd_guess(CXWnd* parent);
};

// EQ button window constructor: builds the EQ menu (0x00441AC6), registers it with the menu manager at
// 0x991758 (id kept at +0x164) and finds EQButton.
// FUNCTION: TITANIUM 0x004FFC7F
CEQMainWnd_guess::CEQMainWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "EQMainWnd", 0xfffffeff, 1, 0) {
    button_15c = 0;
    value_160 = 0;
    state_164 = 0;
    if (SidlPiece != 0) {
        field_018_guess = 0;
        value_160 = CreateMainMenu_guess();
        state_164 = pinstCascadeMenuList_guess->Resolve_guess(value_160, -1);
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        button_15c = ((CSidlScreenWnd*)this)->GetChildItem("EQButton");
    }
}

// Text sink: slot 63 takes a CXStr by reference.
struct Text_004ff7d2_guess {
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
    virtual void SetText_guess(const CXStr& text);
};

struct Panel_004ff7d2_guess {
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
    virtual void Refresh_guess(int a, int b);   // slot 48

    char pad_004_guess[0x158];
    int field_15c_guess;                      // 0x15C
    int field_160_guess;                      // 0x160
    int state_164_guess;                      // 0x164
    Text_004ff7d2_guess* text_168_guess;      // 0x168
    int pad_16c_guess;                        // 0x16C
    CButtonWnd* button_170_guess;             // 0x170
    CButtonWnd* button_174_guess;             // 0x174
    CButtonWnd* button_178_guess;             // 0x178

    void Activate_guess(int p1, const char* name, int state, int value);
};

// Opens the label editor for `p1` (told when Done is pressed) with text `name`, size `state` (1 small,
// 2 medium, 3 large) and colour `value`.
// FUNCTION: TITANIUM 0x004FF7D2
void Panel_004ff7d2_guess::Activate_guess(int p1, const char* name, int state, int value) {
    field_15c_guess = p1;
    state_164_guess = state;
    if (button_178_guess != 0 && button_174_guess != 0 && button_170_guess != 0) {
        switch (state) {
        case 1:
            button_178_guess->SetCheck(true);
            button_174_guess->SetCheck(false);
            button_170_guess->SetCheck(false);
            break;
        case 2:
            button_178_guess->SetCheck(false);
            button_174_guess->SetCheck(true);
            button_170_guess->SetCheck(false);
            break;
        case 3:
            button_178_guess->SetCheck(false);
            button_174_guess->SetCheck(false);
            button_170_guess->SetCheck(true);
            break;
        }
    }
    field_160_guess = value;
    if (name != 0) {
        CXStr text(name);
        text_168_guess->SetText_guess(text);
    } else {
        CXStr text(EQ_ARRAY(char, 0x0063F53F));   // the game's "" literal
        text_168_guess->SetText_guess(text);
    }
    Refresh_guess(1, 1);
}

