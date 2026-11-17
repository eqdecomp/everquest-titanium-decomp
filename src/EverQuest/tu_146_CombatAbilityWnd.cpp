// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 146: a hint from compare/tumap.py.
// Mostly CCombatAbilityWnd (screen "CombatAbilityWnd", vtable 0x652EA0): 8 ability buttons, the active
// discipline display and a right-click menu of all combat abilities; the Unknown_*_guess views are that
// window. Button slots live at 0x95D43C as ability + 0x84 (0 or -1 = empty). 0x4F898E belongs to
// CColorPickerWnd and 0x4F89E0 to CCursorAttachment.
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/wnd/CCombatSkillSelectWnd.h"
#include "titanium/wnd/CTipWnd.h"

#define g_004F8A3B_parallel_guess EQ_ARRAY(int, 0x0095D2D4)
#define g_004F8A3B_manager_guess EQ_GLOBAL(struct Unknown_004B244F_guess*, 0x0098599C)
#define g_004F8AAB_values_guess EQ_ARRAY(int, 0x0095D43C)
#define g_004F8AAB_resolver_guess EQ_GLOBAL(struct Unknown_005F0A00_guess*, 0x00905D00)
#define g_004F8AAB_lookup_guess EQ_GLOBAL(struct Unknown_0040CBD6_guess*, 0x00985CC8)

typedef CXStr Unknown_00407D68_guess;

struct Unknown_004F89E0_guess {
    char pad_00[0x168];
    Unknown_00407D68_guess lock_guess;
    Unknown_00407D68_guess GetButtonText_guess();
};

struct Unknown_004F898E_child_guess {
    char pad_00[0x7c];
    int source_guess;
    char pad_80[0xbc];
    int destination_guess;
};

struct Unknown_004F898E_guess {
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
    virtual void Begin_guess(int first_guess, int second_guess);
    char pad_04[0x160];
    int field_164_guess;
    Unknown_004F898E_child_guess* entries_guess[15];
    // EXTERNAL: TITANIUM 0x004F86D9 Unknown_004F898E_guess::Update_guess
    void Update_guess(int value_guess);
    void Activate_guess(int first_guess, int second_guess);
};

struct Unknown_004F8A17_guess {
    char pad_00[0x5c];
    char enabled_guess;
    // EXTERNAL: TITANIUM 0x005A1880 Unknown_004F8A17_guess::OnShow
    void OnShow();
    void Run_guess();
};

struct Unknown_005BA300_guess {
    // EXTERNAL: TITANIUM 0x005BA300 Unknown_005BA300_guess::GetValue_guess
    int GetValue_guess();
};

struct Unknown_004B244F_guess {
    // EXTERNAL: TITANIUM 0x004B244F Unknown_004B244F_guess::GetObject_guess
    Unknown_005BA300_guess* GetObject_guess(int index_guess);
};

struct Unknown_0059DBF0_guess {
    // EXTERNAL: TITANIUM 0x0059DBF0 Unknown_0059DBF0_guess::SetValues_guess
    void SetValues_guess(int first_guess, int second_guess);
};

struct Unknown_004F8A3B_guess {
    char pad_00[0x168];
    Unknown_0059DBF0_guess* slots_guess[8];
    void UpdateKeyTooltips_guess();
};

struct Unknown_005F0A00_guess {
    // EXTERNAL: TITANIUM 0x005F0A00 Unknown_005F0A00_guess::Resolve_guess
    void* Resolve_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BB39D Unknown_005F0A00_guess::Apply_guess
    void Apply_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BAC08 Unknown_005F0A00_guess::GetDisciplineTimer_guess
    unsigned int GetDisciplineTimer_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x00576E80 Unknown_00576E80_guess
unsigned int Unknown_00576E80_guess();

struct Unknown_0040CBD6_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 Unknown_0040CBD6_guess::Find_guess
    int* Find_guess(void* value_guess);
};

struct Unknown_004F8AAB_guess {
    char UseAbilitySlot_guess(int index_guess);
};

// CColorPickerWnd::Activate (Mac direct match): hides, stores the caller (+0x164), sets the colour,
// copies +0x7C to +0x13C on the 15 children, then shows.
// FUNCTION: TITANIUM 0x004F898E
void Unknown_004F898E_guess::Activate_guess(int first_guess, int second_guess) {
    Begin_guess(0, 1);
    field_164_guess = first_guess;
    Update_guess(second_guess);
    Unknown_004F898E_child_guess** current_guess = entries_guess;
    int count_guess = 15;
    do {
        Unknown_004F898E_child_guess* child_guess = *current_guess;
        child_guess->destination_guess = child_guess->source_guess;
        ++current_guess;
        --count_guess;
    } while (count_guess != 0);
    Begin_guess(1, 1);
}

// CCursorAttachment's button text (+0x168), by value.
// FUNCTION: TITANIUM 0x004F89E0
Unknown_00407D68_guess Unknown_004F89E0_guess::GetButtonText_guess() {
    return lock_guess;
}

// Close hook: if shown (+0x5C), reports window id 0x2E (+0x158) to the 0x9928E0 object, then the base
// call; CStoryWnd's 0x4C7781 is the same with id 0x10.
// FUNCTION: TITANIUM 0x004F8A17
void Unknown_004F8A17_guess::Run_guess() {
    if (enabled_guess && pinstCTipWndCONTEXT_guess) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x2e, 0);
    }
    OnShow();
}

// Gives each button the key tooltip of bind 0xCC + i (probably Combat Ability 1-8) through
// CXWnd::SetKeyTooltip; empty slots get -1.
// FUNCTION: TITANIUM 0x004F8A3B
void Unknown_004F8A3B_guess::UpdateKeyTooltips_guess() {
    int* flags_guess = g_004F8A3B_parallel_guess + 0x5A;
    for (int i = 0; i < 8; ++i) {
        int index_guess = 0xcc + i;
        int first_guess = -1;
        int second_guess = -1;
        if (slots_guess[i] != 0) {
            if (flags_guess[i] > 0) {
                first_guess = g_004F8A3B_manager_guess->GetObject_guess(index_guess)->GetValue_guess();
                second_guess = g_004F8A3B_manager_guess->GetObject_guess(index_guess)->GetValue_guess();
            }
            slots_guess[i]->SetValues_guess(first_guess, second_guess);
        }
    }
}

// Uses the ability in button `index_guess` (EQ_Character::DoCombatAbility, MQ2); 1 if one was there.
// FUNCTION: TITANIUM 0x004F8AAB
char Unknown_004F8AAB_guess::UseAbilitySlot_guess(int index_guess) {
    char result_guess = 0;
    if (g_004F8AAB_values_guess[index_guess] > 0) {
        void* value_guess = g_004F8AAB_resolver_guess->Resolve_guess(g_004F8AAB_values_guess[index_guess] - 0x84);
        int* found_guess = g_004F8AAB_lookup_guess->Find_guess(value_guess);
        if (found_guess != 0) {
            g_004F8AAB_resolver_guess->Apply_guess(*found_guess);
            ++result_guess;
        }
    }
    return result_guess;
}

struct Unknown_004F8AF3_guess : CSidlScreenWnd {
    int field_15c;
    int field_160;
    int field_164;
    int slots_168[8];
    int field_188;
    int field_18c;
    char pad_190[0x14];
    int field_1a4;
    int field_1a8;
    int field_1ac;
    int WndNotification(CXWnd* sender_guess, int message_guess, int data_guess);
    void Clear_guess();
    void UpdateActiveDiscipline_guess();
};

// Clears the control pointers, including the eight CAW_Button slots at +0x168.
// FUNCTION: TITANIUM 0x004F8AF3
void Unknown_004F8AF3_guess::Clear_guess() {
    field_15c = 0;
    field_160 = 0;
    field_164 = 0;
    for (int i = 0; i < 8; i++) {
        slots_168[i] = 0;
    }
    field_188 = 0;
    field_18c = 0;
}

// Object at +0x15c: slot 48 (0xC0) is Begin. Object at +0x160: slot 63 (0xFC) is Sink.
struct Unknown_004F8CBC_vtbl_guess {
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
    virtual void Begin_guess(int first_guess, int second_guess);
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
    virtual void Sink_guess(CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 Unknown_004F8CBC_vtbl_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x004FD36C Unknown_004F8CBC_vtbl_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004FD91E Unknown_004F8CBC_vtbl_guess::Send_guess
    void Send_guess(int first_guess, int second_guess, int third_guess, char* text_guess,
        int flag_guess);
    char pad_04[0x154];
    int field_158_guess;                // 0x158
    int field_15c_guess;                // 0x15c
    int field_160_guess;                // 0x160
    char pad_164[0x8];
    int field_16c_guess;                // 0x16c
};

struct Unknown_004BB01D_entry_guess {
    char flag_00_guess;                 // 0x0
    void* value_04_guess;               // 0x4
};

struct Unknown_004BB039_guess {
    // EXTERNAL: TITANIUM 0x004BB039 Unknown_004BB039_guess::IsUsingDiscipline_guess
    bool IsUsingDiscipline_guess();
    // EXTERNAL: TITANIUM 0x004BB01D Unknown_004BB039_guess::GetDisciplineEffect_guess
    Unknown_004BB01D_entry_guess* GetDisciplineEffect_guess();
    // EXTERNAL: TITANIUM 0x004BAD6A Unknown_004BB039_guess::Apply_guess
    void Apply_guess(int value_guess);
};

struct Unknown_0040DB4E_player_guess {
    // EXTERNAL: TITANIUM 0x0040DB4E Unknown_0040DB4E_player_guess::Get_guess
    int Get_guess(int first_guess, int second_guess);
};

struct Unknown_0040DB4E_client_guess : EQ_Character {
    char pad_008[0xc280 - sizeof(EQ_Character)];
    Unknown_0040DB4E_player_guess player_guess;
};

#define g_004F8F3D_character_guess EQ_GLOBAL(Unknown_0040DB4E_client_guess*, 0x00905D00)

struct Unknown_004B06FA_everquest_guess : CEverQuest {
    // EXTERNAL: TITANIUM 0x004B06FA Unknown_004B06FA_everquest_guess::Run_guess
    void Run_guess();
};

struct Unknown_004D22D7_widget_guess {
    // EXTERNAL: TITANIUM 0x004D22D7 Unknown_004D22D7_widget_guess::GetText_guess
    CXStr GetText_guess();
};

struct Unknown_004DC02D_point_guess {
    int x_guess;
    int y_guess;
};

struct Unknown_004DC02D_rect_guess {
    // EXTERNAL: TITANIUM 0x004DC02D Unknown_004DC02D_rect_guess::CenterPoint
    Unknown_004DC02D_point_guess* CenterPoint(Unknown_004DC02D_point_guess* point_guess);
};

struct Unknown_0040CBD6_hit_guess {
    char pad_000[0x19c];
    int field_19c_guess;
    int field_1a0_guess;
    int field_1a4_guess;
    char pad_1a8[0x1c0 - 0x1a8];
    int field_1c0_guess;                // 0x1c0
    char pad_1c4[0x208 - 0x1c4];
    char* text_208_guess;               // 0x208
    char pad_20c[0x248 - 0x20c];
    int field_248_guess;                // 0x248
    // EXTERNAL: TITANIUM 0x0044E755 Unknown_0040CBD6_hit_guess::Map_guess
    unsigned char Map_guess(unsigned char value_guess);
};

struct Unknown_004F95AC_charinfo_guess {
    char pad_000[0x119c];
    unsigned char classId_119c_guess;
};

struct Unknown_004F95AC_builder_args_guess {
    int first_guess;
    int second_guess;
    int capacity_guess;
    int increment_guess;
};

struct Unknown_004F95AC_builder_guess {
    char pad_000[0x1a8];
    // EXTERNAL: TITANIUM 0x005BFAE0 Unknown_004F95AC_builder_guess::Unknown_004F95AC_builder_guess
    Unknown_004F95AC_builder_guess(int first_guess, int second_guess,
        Unknown_004F95AC_builder_args_guess* args_guess);
    // EXTERNAL: TITANIUM 0x005BFCF0 Unknown_004F95AC_builder_guess::Add_guess
    void Add_guess(CXStr& text_guess, int id_guess, int flags_guess, int icon_guess);
};

struct Unknown_004F95AC_item_guess {
    int id_guess;
    int number_guess;
};

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* buffer_guess, const char* format_guess, ...);

struct Unknown_005B1AB0_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Unknown_005B1AB0_guess::Attach_guess
    void Attach_guess(int value_guess);
};

#define g_004F8CBC_owner_guess EQ_GLOBAL(Unknown_004BB039_guess*, 0x00905D00)

// Active discipline display: while one runs (0x4BB039, 0x4BB01D), its name and spell icon (+0x248);
// otherwise string 0x1A9F and no icon.
// FUNCTION: TITANIUM 0x004F8CBC
void Unknown_004F8AF3_guess::UpdateActiveDiscipline_guess() {
    CXStr text_guess(pStringTable->getString(0x1a9f, 0));
    int index_guess = -1;
    if (g_004F8CBC_owner_guess->IsUsingDiscipline_guess()) {
        Unknown_004BB01D_entry_guess* entry_guess = g_004F8CBC_owner_guess->GetDisciplineEffect_guess();
        if (entry_guess->flag_00_guess != 0) {
            Unknown_0040CBD6_hit_guess* hit_guess = (Unknown_0040CBD6_hit_guess*)g_004F8AAB_lookup_guess->Find_guess(entry_guess->value_04_guess);
            if (hit_guess != 0) {
                index_guess = hit_guess->field_248_guess;
                text_guess = hit_guess->text_208_guess;
            }
        }
    }
    if (field_160 != 0) {
        reinterpret_cast<Unknown_004F8CBC_vtbl_guess*>(field_160)->Sink_guess(text_guess);
    }
    Unknown_004F8CBC_vtbl_guess* child_guess = (Unknown_004F8CBC_vtbl_guess*)field_15c;
    if (child_guess != 0) {
        if (index_guess < 0 || field_18c == 0) {
            child_guess->field_158_guess = 0;
            reinterpret_cast<Unknown_004F8CBC_vtbl_guess*>(field_15c)->field_16c_guess = 0;
            reinterpret_cast<Unknown_004F8CBC_vtbl_guess*>(field_15c)->Begin_guess(0, 1);
        } else {
            int value_guess = field_188;
            child_guess->field_158_guess = value_guess;
            reinterpret_cast<Unknown_005B1AB0_guess*>(field_18c)->Attach_guess(index_guess);
            int obj_guess = field_18c;
            reinterpret_cast<Unknown_004F8CBC_vtbl_guess*>(field_15c)->field_16c_guess = obj_guess;
            reinterpret_cast<Unknown_004F8CBC_vtbl_guess*>(field_15c)->Begin_guess(1, 1);
        }
    }
}

#define g_004F8DDA_owner_guess EQ_GLOBAL(Object_guess*, 0x00905D00)

struct Object_guess {
    // EXTERNAL: TITANIUM 0x004BC547 Object_guess::IsMeleeClass_guess
    char IsMeleeClass_guess();
};

struct Unknown_004F8DDA_guess {
    char Run_guess();
};

// Refreshes the key tooltips when pCharData's 0x4BC547 check passes.
// FUNCTION: TITANIUM 0x004F8DDA
char Unknown_004F8DDA_guess::Run_guess() {
    char result_guess = 0;
    if (g_004F8DDA_owner_guess != 0) {
        if (g_004F8DDA_owner_guess->IsMeleeClass_guess()) {
            result_guess = 1;
            reinterpret_cast<Unknown_004F8A3B_guess*>(this)->UpdateKeyTooltips_guess();
        }
    }
    return result_guess;
}

struct Unknown_004F924D_guess;

struct Unknown_004F924D_child_guess {
    int count;                          // 0x0
    Unknown_004F924D_guess** entries;   // 0x4
    int capacity;                       // 0x8
    // EXTERNAL: TITANIUM 0x0050F3F6 Unknown_004F924D_child_guess::Run_guess
    void Run_guess();
    // EXTERNAL: TITANIUM 0x004EB905 Unknown_004F924D_child_guess::Value_guess
    Unknown_004F924D_guess* Value_guess(int index);
    // EXTERNAL: TITANIUM 0x004EB924 Unknown_004F924D_child_guess::GetSlot_guess
    void** GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x00564487 Unknown_004F924D_child_guess::Insert_guess
    void Insert_guess(int index, Unknown_004F924D_guess** value);
    // EXTERNAL: TITANIUM 0x0050319B Unknown_004F924D_child_guess::Set_guess
    void Set_guess(int index, Unknown_004F924D_guess** value);
    ~Unknown_004F924D_child_guess() {
        Run_guess();
    }
};

struct Unknown_004F924D_guess {
    int field_00_guess;
    char text_04_guess[0x40];
    Unknown_004F924D_child_guess child;
    char owned_50_guess;
    Unknown_004F924D_guess() {
        child.entries = 0;
        child.count = 0;
        child.capacity = 0;
        owned_50_guess = 1;
    }
    ~Unknown_004F924D_guess();
};

// Destructor of a right-click menu category node: frees its subnode array (+0x44, 0x0050F3F6). The
// memorize menu and combat ability menu teardown (0x004EC711, 0x004F949F) run it on each category.
// FUNCTION: TITANIUM 0x004F924D
Unknown_004F924D_guess::~Unknown_004F924D_guess() {
}

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* pointer);

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// Group list plus its owned flag (0x194..0x1a4).
struct GroupList_guess : Unknown_004F924D_child_guess {
    unsigned char owned_guess;
    GroupList_guess() {
        entries = 0;
        count = 0;
        capacity = 0;
        owned_guess = 1;
    }
};

struct Unknown_005AD7F0_guess {
    // EXTERNAL: TITANIUM 0x005AD7F0 Unknown_005AD7F0_guess::Release_guess
    void Release_guess(int handle, int flag);
    // EXTERNAL: TITANIUM 0x005AD5A0 Unknown_005AD7F0_guess::Create_guess
    int Create_guess(Unknown_004F95AC_builder_guess* value_guess);
    // EXTERNAL: TITANIUM 0x005ADC20 Unknown_005AD7F0_guess::Register_guess
    void Register_guess(int handle_guess, Unknown_004DC02D_point_guess* point_guess,
        Unknown_004F8AF3_guess* owner_guess);
};

#define pinstCContextMenuManager_guess EQ_GLOBAL(Unknown_005AD7F0_guess*, 0x0099D414)

struct Unknown_004F9A56_child_guess {
    char pad_00[0x60];
    char flag_60_guess;
    char pad_61[0x158 - 0x61];
    int field_158_guess;
    char pad_15c[0x16c - 0x15c];
    int field_16c_guess;
};

struct Unknown_004F9A56_source_guess {
    char pad_000[0x148];
    int field_148_guess;
};

#define g_004F9A56_source_guess EQ_GLOBAL(Unknown_004F9A56_source_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00652EA0 ??_7CCombatAbilityWnd_guess@@6B@
struct CCombatAbilityWnd_guess : CSidlScreenWndBase {
    Unknown_004F9A56_child_guess* child_15c_guess; // 0x15c
    char pad_160[0x190 - 0x160];
    int field_190_guess;
    GroupList_guess groups;               // 0x194
    int handle_1a4;                       // 0x1a4
    int field_1a8_guess;
    int field_1ac_guess;
    virtual ~CCombatAbilityWnd_guess();
    CCombatAbilityWnd_guess(CXWnd* parent);
    void FindChildren_guess();
    void FreeAbilityMenu_guess();
    void UpdateButtons_guess();
    void BuildAbilityMenu_guess();
    void AddAbilityMenuItem_guess(int index_guess, int id_guess, int value_guess, int color_guess);
    void* Delete_guess(unsigned char flags);
    void Run_guess();
    void Setup_guess();
};

struct Unknown_004F9255_pair_guess {
    int index_guess;
    int level_guess;
};

struct Unknown_004355F7_guess {
    // EXTERNAL: TITANIUM 0x004355F7 Unknown_004355F7_guess::GetString_guess
    char* GetString_guess(int id_guess, int kind_guess, int flag_guess);
};

#define g_004F9255_db_guess EQ_GLOBAL(Unknown_004355F7_guess*, 0x00850398)

// EXTERNAL: TITANIUM 0x00574460 CompareName_guess
int __cdecl CompareName_guess(const char* left_guess, const char* right_guess);

// Adds ability `index_guess` to the menu tree under category `id_guess` and subcategory `value_guess`
// (dbstr kind-5 names, kept alphabetical); within a subcategory, higher `color_guess` (the level) first.
// FUNCTION: TITANIUM 0x004F9255
// @early-stop: budget, structural ndiff=100
void CCombatAbilityWnd_guess::AddAbilityMenuItem_guess(int index_guess, int id_guess,
    int value_guess, int color_guess) {
    Unknown_004F9255_pair_guess* pair_guess = new Unknown_004F9255_pair_guess();
    pair_guess->index_guess = index_guess;
    pair_guess->level_guess = color_guess;
    index_guess = -1;

    char name_guess[64];
    strncpy(name_guess, g_004F9255_db_guess->GetString_guess(id_guess, 5, 0), 63);
    name_guess[63] = 0;

    Unknown_004F924D_guess* group_guess = 0;
    for (int i_guess = 0; i_guess < groups.count; ++i_guess) {
        if ((*(Unknown_004F924D_guess**)groups.GetSlot_guess(i_guess))->field_00_guess == id_guess) {
            group_guess = *(Unknown_004F924D_guess**)groups.GetSlot_guess(i_guess);
            break;
        }
        if (index_guess == -1 &&
            CompareName_guess(name_guess,
                (*(Unknown_004F924D_guess**)groups.GetSlot_guess(i_guess))->text_04_guess) < 0) {
            index_guess = i_guess;
        }
    }

    if (group_guess == 0) {
        group_guess = new Unknown_004F924D_guess();
        group_guess->field_00_guess = id_guess;
        strcpy(group_guess->text_04_guess, name_guess);
        if (index_guess == -1) {
            groups.Set_guess(groups.count, &group_guess);
        } else {
            groups.Insert_guess(index_guess, &group_guess);
        }
    }

    strncpy(name_guess, g_004F9255_db_guess->GetString_guess(value_guess, 5, 0), 63);
    name_guess[63] = 0;
    index_guess = -1;
    for (int i_guess = 0; i_guess < group_guess->child.count; ++i_guess) {
        if ((*(Unknown_004F924D_guess**)group_guess->child.GetSlot_guess(i_guess))->field_00_guess == value_guess) {
            Unknown_004F924D_guess* item_guess =
                *(Unknown_004F924D_guess**)group_guess->child.GetSlot_guess(i_guess);
            for (int j_guess = 0; j_guess < item_guess->child.count; ++j_guess) {
                Unknown_004F9255_pair_guess** pair_slot_guess =
                    (Unknown_004F9255_pair_guess**)item_guess->child.GetSlot_guess(j_guess);
                if ((*pair_slot_guess)->level_guess < pair_guess->level_guess) {
                    item_guess->child.Insert_guess(j_guess,
                        (Unknown_004F924D_guess**)&pair_guess);
                    return;
                }
            }
            item_guess->child.Set_guess(item_guess->child.count,
                (Unknown_004F924D_guess**)&pair_guess);
            return;
        }
        if (index_guess == -1 &&
            CompareName_guess(name_guess,
                (*(Unknown_004F924D_guess**)group_guess->child.GetSlot_guess(i_guess))->text_04_guess) < 0) {
            index_guess = i_guess;
        }
    }

    Unknown_004F924D_guess* item_guess = new Unknown_004F924D_guess();
    item_guess->field_00_guess = value_guess;
    strncpy(item_guess->text_04_guess,
        g_004F9255_db_guess->GetString_guess(value_guess, 5, 0), 63);
    item_guess->text_04_guess[63] = 0;
    item_guess->child.Set_guess(item_guess->child.count,
        (Unknown_004F924D_guess**)&pair_guess);
    if (index_guess == -1) {
        group_guess->child.Set_guess(group_guess->child.count, &item_guess);
    } else {
        group_guess->child.Insert_guess(index_guess, &item_guess);
    }
}

// Labels the 8 buttons with their ability names and checks the ones not ready (empty, or reuse timer
// +0x1C0 not yet past 0x576E80's now).
// FUNCTION: TITANIUM 0x004F8E01
void CCombatAbilityWnd_guess::UpdateButtons_guess() {
    Unknown_004F8AF3_guess* self_guess = reinterpret_cast<Unknown_004F8AF3_guess*>(this);
    self_guess->UpdateActiveDiscipline_guess();
    CXStr text_guess;
    for (int i = 0; i < 8; ++i) {
        bool flag_guess = true;
        text_guess.~CXStr();
        if (self_guess->slots_168[i] != 0) {
            if (g_004F8A3B_parallel_guess[0x5A + i] > 0) {
                int id_guess = (int)g_004F8AAB_resolver_guess->Resolve_guess(g_004F8A3B_parallel_guess[0x5A + i] - 0x84);
                if (id_guess > 0) {
                    Unknown_0040CBD6_hit_guess* hit_guess = (Unknown_0040CBD6_hit_guess*)g_004F8AAB_lookup_guess->Find_guess((void*)id_guess);
                    if (hit_guess != 0) {
                        text_guess = hit_guess->text_208_guess;
                        unsigned int timer_guess = g_004F8AAB_resolver_guess->GetDisciplineTimer_guess(hit_guess->field_1c0_guess);
                        if (timer_guess < Unknown_00576E80_guess()) {
                            flag_guess = false;
                        }
                    }
                }
            }
        }
        if (self_guess->slots_168[i] != 0) {
            ((Unknown_004F8CBC_vtbl_guess*)self_guess->slots_168[i])->Sink_guess(text_guess);
            ((CButtonWnd*)self_guess->slots_168[i])->SetCheck(flag_guess);
        }
    }
}

// Frees the ability menu tree and its context menu (0x99D414).
// FUNCTION: TITANIUM 0x004F949F
void CCombatAbilityWnd_guess::FreeAbilityMenu_guess() {
    if (handle_1a4 != -1) {
        pinstCContextMenuManager_guess->Release_guess(handle_1a4, 1);
        handle_1a4 = -1;
    }
    int group_index = 0;
    if (group_index < groups.count) {
        Unknown_004F924D_guess* empty_group = 0;
        do {
            Unknown_004F924D_guess* group = groups.Value_guess(group_index);
            groups.Set_guess(group_index, &empty_group);
            int item_index = 0;
            if (item_index < group->child.count) {
                Unknown_004F924D_guess* empty_item = 0;
                do {
                    Unknown_004F924D_guess* item = group->child.Value_guess(item_index);
                    group->child.Set_guess(item_index, &empty_item);
                    delete item;
                } while (++item_index < group->child.count);
            }
            delete group;
        } while (++group_index < groups.count);
    }
    groups.Run_guess();
}

// Destructor of the combat ability window (vtable 0x652EA0): frees the ability menu tree and its
// context menu (0x004F949F), the array at +0x194, then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004F9566
// @early-stop: inline, structural ndiff=1
CCombatAbilityWnd_guess::~CCombatAbilityWnd_guess() {
    FreeAbilityMenu_guess();
}

// Builds the right-click menu: each known ability (of 100) under its category (spell +0x19C) and its
// subcategories (+0x1A0, +0x1A4), as "level - name".
// FUNCTION: TITANIUM 0x004F95AC
void CCombatAbilityWnd_guess::BuildAbilityMenu_guess() {
    FreeAbilityMenu_guess();
    for (int index_guess = 0; index_guess < 100; ++index_guess) {
        int resolved_guess = (int)g_004F8AAB_resolver_guess->Resolve_guess(index_guess);
        if (resolved_guess > 0) {
            Unknown_0040CBD6_hit_guess* hit_guess = (Unknown_0040CBD6_hit_guess*)
                g_004F8AAB_lookup_guess->Find_guess((void*)resolved_guess);
            if (hit_guess != 0) {
                int first_guess = hit_guess->field_1a0_guess;
                int source_guess = hit_guess->field_19c_guess;
                int second_guess = hit_guess->field_1a4_guess;
                EQ_PC* pc_guess = (EQ_PC*)pCharData;
                EQ_Character* char_guess = (EQ_Character*)
                    ((int)pc_guess + pc_guess->vbtable[1] + 8);
                Unknown_004F95AC_charinfo_guess* info_guess =
                    (Unknown_004F95AC_charinfo_guess*)char_guess->GetCharInfo2();
                int color_guess = hit_guess->Map_guess(info_guess->classId_119c_guess);
                if (source_guess != 0) {
                    if (first_guess != 0) {
                        AddAbilityMenuItem_guess(index_guess, source_guess, first_guess, color_guess);
                    }
                    if (second_guess != 0) {
                        AddAbilityMenuItem_guess(index_guess, source_guess, second_guess, color_guess);
                    }
                }
            }
        }
    }

    if (groups.count > 0) {
        Unknown_004F95AC_builder_args_guess args_guess;
        Unknown_004F95AC_builder_guess* root_guess =
            new Unknown_004F95AC_builder_guess(0, 0,
                (args_guess.first_guess = 0, args_guess.second_guess = 0,
                args_guess.capacity_guess = 0x32, args_guess.increment_guess = 10, &args_guess));

        for (int group_index_guess = 0; group_index_guess < groups.count; ++group_index_guess) {
            Unknown_004F924D_guess* group_guess =
                (Unknown_004F924D_guess*)*groups.GetSlot_guess(group_index_guess);
            Unknown_004F95AC_builder_guess* group_builder_guess =
                new Unknown_004F95AC_builder_guess(0, 0,
                    (args_guess.first_guess = 0, args_guess.second_guess = 0,
                    args_guess.capacity_guess = 0x32, args_guess.increment_guess = 10, &args_guess));

            for (int subgroup_index_guess = 0; subgroup_index_guess < group_guess->child.count;
                ++subgroup_index_guess) {
                Unknown_004F924D_guess* subgroup_guess = (Unknown_004F924D_guess*)
                    *group_guess->child.GetSlot_guess(subgroup_index_guess);
                Unknown_004F95AC_builder_args_guess subgroup_args_guess;
                Unknown_004F95AC_builder_guess* subgroup_builder_guess =
                    new Unknown_004F95AC_builder_guess(0, 0,
                        (subgroup_args_guess.first_guess = 0, subgroup_args_guess.second_guess = 0,
                        subgroup_args_guess.capacity_guess = 0x32,
                        subgroup_args_guess.increment_guess = 10, &subgroup_args_guess));

                for (int item_index_guess = 0; item_index_guess < subgroup_guess->child.count;
                    ++item_index_guess) {
                    Unknown_004F95AC_item_guess* item_guess = (Unknown_004F95AC_item_guess*)
                        *subgroup_guess->child.GetSlot_guess(item_index_guess);
                    void* item_data_guess =
                        g_004F8AAB_resolver_guess->Resolve_guess(item_guess->id_guess);
                    Unknown_0040CBD6_hit_guess* item_hit_guess = (Unknown_0040CBD6_hit_guess*)
                        g_004F8AAB_lookup_guess->Find_guess(item_data_guess);
                    char item_buffer_guess[128];
                    _sprintf(item_buffer_guess, "%02d - %s", item_guess->number_guess,
                        item_hit_guess->text_208_guess);
                    CXStr item_text_guess(item_buffer_guess);
                    subgroup_builder_guess->Add_guess(item_text_guess,
                        // Item id = ability + 10000; submenus go in as handle + 0x80000000.
                        item_guess->id_guess + 10000, 0, -1);
                }

                int subgroup_handle_guess = pinstCContextMenuManager_guess->Create_guess(subgroup_builder_guess);
                CXStr subgroup_text_guess(subgroup_guess->text_04_guess);
                group_builder_guess->Add_guess(subgroup_text_guess,
                    subgroup_handle_guess + 0x80000000, 0, -1);
            }

            int group_handle_guess = pinstCContextMenuManager_guess->Create_guess(group_builder_guess);
            CXStr group_text_guess(group_guess->text_04_guess);
            root_guess->Add_guess(group_text_guess, group_handle_guess + 0x80000000, 0, -1);
        }

        handle_1a4 = pinstCContextMenuManager_guess->Create_guess(root_guess);
    }
}

// Scalar deleting destructor of the combat ability window (vtable 0x652EA0 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004F9A2A
void* CCombatAbilityWnd_guess::Delete_guess(unsigned char flags) {
    this->CCombatAbilityWnd_guess::~CCombatAbilityWnd_guess();
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}

// Rebuilds the ability menu.
// FUNCTION: TITANIUM 0x004F9A46
void CCombatAbilityWnd_guess::Run_guess() {
    FreeAbilityMenu_guess();
    BuildAbilityMenu_guess();
}



// Init after SIDL: no menu open, effect button cleared, then labels and menu.
// FUNCTION: TITANIUM 0x004F9A56
void CCombatAbilityWnd_guess::Setup_guess() {
    CXStr text_guess;
    field_1ac_guess = -1;
    handle_1a4 = -1;
    field_190_guess = 0;
    field_1a8_guess = g_004F9A56_source_guess->field_148_guess;
    Unknown_004F9A56_child_guess** slot_guess = &child_15c_guess;
    if (*slot_guess != 0) {
        (*slot_guess)->flag_60_guess = 0;
        (*slot_guess)->field_158_guess = 0;
        (*slot_guess)->field_16c_guess = 0;
    }
    UpdateButtons_guess();
    BuildAbilityMenu_guess();
}

// EXTERNAL: TITANIUM 0x005738B0 Unknown_005738B0_guess
void Unknown_005738B0_guess(CXStr* out_guess, const char* format_guess, ...);

struct Unknown_005B44A0_owner_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 Unknown_005B44A0_owner_guess::Find_guess
    int Find_guess(const CXStr& name_guess);
};

#define g_004F8B27_owner_guess EQ_GLOBAL(Unknown_005B44A0_owner_guess*, 0x0099D3F4)

// Finds the children: effect button and label, the Combat Skill Select opener, CAW_Button1-8, and the
// icon background and spell-icon animations.
// FUNCTION: TITANIUM 0x004F8B27
void CCombatAbilityWnd_guess::FindChildren_guess() {
    Unknown_004F8AF3_guess* self_guess = reinterpret_cast<Unknown_004F8AF3_guess*>(this);
    self_guess->field_15c = (int)((CSidlScreenWnd*)this)->GetChildItem("CAW_CombatEffectButton");
    self_guess->field_160 = (int)((CSidlScreenWnd*)this)->GetChildItem("CAW_CombatEffectLabel");
    self_guess->field_164 = (int)((CSidlScreenWnd*)this)->GetChildItem("CAW_OpenCombatSkillSelectWnd");
    CXStr name_guess;
    int index_guess = 0;
    int* slot_guess = self_guess->slots_168;
    do {
        Unknown_005738B0_guess(&name_guess, "CAW_Button%d", index_guess + 1);
        *slot_guess = (int)((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        ++slot_guess;
        ++index_guess;
    } while (index_guess < 8);
    self_guess->field_188 = g_004F8B27_owner_guess->Find_guess("BlueIconBackground");
    self_guess->field_18c = g_004F8B27_owner_guess->Find_guess("A_SpellIcons");
}

// Combat ability window constructor: clears the control pointers (0x004F8AF3), builds the children, finds
// them (0x004F8B27) and sets up the labels and menu (0x004F9A56).
// FUNCTION: TITANIUM 0x004F9AE1
CCombatAbilityWnd_guess::CCombatAbilityWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "CombatAbilityWnd", 0xfffffdff, 1, 0) {
    reinterpret_cast<Unknown_004F8AF3_guess*>(this)->Clear_guess();
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10800;
        field_158_guess = 0x2e;
        field_018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        FindChildren_guess();
        Setup_guess();
    }
}

#define pinstCCursorAttachment_guess EQ_GLOBAL(Unknown_004F8CBC_vtbl_guess*, 0x00850C24)

// Hides the Combat Skill Select window (0x850BBC).
// FUNCTION: TITANIUM 0x004F89FE
bool HideCombatSkillSelectWnd_guess() {
    if (pinstCCombatSkillSelectWnd_guess != 0) {
        pinstCCombatSkillSelectWnd_guess->Show(0, 1);
    }
    return true;
}

// Effect button: with a discipline running, 0x4BAD6A (probably stops it). Opener: shows the Combat Skill
// Select window. Right-click (3) on a button opens the ability menu at its centre for that button (+0x1AC).
// FUNCTION: TITANIUM 0x004F8F3D
// @early-stop: budget, structural ndiff=142
int Unknown_004F8AF3_guess::WndNotification(CXWnd* sender_guess, int message_guess, int data_guess) {
    if (sender_guess != 0) {
        if (sender_guess == (CXWnd*)field_15c && message_guess == 1) {
            if (g_004F8CBC_owner_guess->IsUsingDiscipline_guess()) {
                int value_guess = g_004F8F3D_character_guess->player_guess.Get_guess(0, 1);
                g_004F8CBC_owner_guess->Apply_guess(value_guess);
            }
            return 0;
        }

        if (sender_guess == (CXWnd*)field_164 && message_guess == 1) {
            CCombatSkillSelectWnd_guess* other_state_guess = pinstCCombatSkillSelectWnd_guess;
            if (other_state_guess != 0) {
                other_state_guess->Show(1, 1);
            }
            return 0;
        }

        if (message_guess == 0x14) {
            if (data_guess > 9999) {
                if (field_1ac != -1) {
                    // Menu id - 9868 = ability + 0x84 (menu ids are ability + 10000).
                    g_004F8AAB_values_guess[field_1ac] = data_guess - 0x268c;
                    reinterpret_cast<Unknown_004B06FA_everquest_guess*>(pEverQuest)->Run_guess();
                }
                return 0;
            }
        } else {
            for (int index_guess = 0; index_guess < 8; ++index_guess) {
                if (sender_guess == (CXWnd*)slots_168[index_guess]) {
                    Unknown_004F8CBC_vtbl_guess* state_guess = pinstCCursorAttachment_guess;
                    if (message_guess == 1) {
                        // Cursor holds a combat-ability hotkey (type 0xC): it goes in the slot,
                        // the old one onto the cursor (or the cursor clears). Else: use it.
                        if (state_guess->IsActive_guess() && state_guess->field_15c_guess == 0xc) {
                            message_guess = g_004F8AAB_values_guess[index_guess];
                            Unknown_004D22D7_widget_guess* widget_guess =
                                (Unknown_004D22D7_widget_guess*)sender_guess;
                            CXStr widget_text_guess = widget_guess->GetText_guess();
                            g_004F8AAB_values_guess[index_guess] = state_guess->field_160_guess;
                            {
                                CXStr selected_text_guess =
                                    ((Unknown_004F89E0_guess*)state_guess)->GetButtonText_guess();
                                ((Unknown_004F8CBC_vtbl_guess*)sender_guess)->Sink_guess(selected_text_guess);
                            }
                            reinterpret_cast<Unknown_004B06FA_everquest_guess*>(pEverQuest)->Run_guess();
                            if (message_guess < 1) {
                                state_guess->Begin_guess(0, 1);
                            } else {
                                state_guess->Send_guess(0, 0xc, message_guess,
                                    (char*)widget_text_guess, -1);
                            }
                        } else if (g_004F8AAB_values_guess[index_guess] > 0) {
                            ((Unknown_004F8AAB_guess*)this)->UseAbilitySlot_guess(index_guess);
                        }
                        return 0;
                    }

                    // Pick-up: the slot's ability goes on the cursor and the slot empties.
                    if (message_guess == 0x17) {
                        if (state_guess->IsOkToActivate_guess(0xc)) {
                            data_guess = g_004F8AAB_values_guess[index_guess];
                            if (data_guess > 0) {
                                Unknown_004D22D7_widget_guess* widget_guess =
                                    (Unknown_004D22D7_widget_guess*)sender_guess;
                                {
                                    CXStr widget_text_guess = widget_guess->GetText_guess();
                                    state_guess->Send_guess(0, 0xc, data_guess,
                                        (char*)widget_text_guess, -1);
                                }
                                g_004F8AAB_values_guess[index_guess] = -1;
                                {
                                    CXStr empty_text_guess((const char*)EQ_ARRAY(char, 0x0063F53F));
                                    ((Unknown_004F8CBC_vtbl_guess*)sender_guess)->Sink_guess(empty_text_guess);
                                }
                                reinterpret_cast<Unknown_004B06FA_everquest_guess*>(pEverQuest)->Run_guess();
                            }
                        }
                        return 0;
                    }

                    if (message_guess == 3 && field_1a4 >= 0) {
                        Unknown_004DC02D_point_guess point_guess = { 0, 0 };
                        CXRect rect_guess = ((CXWnd*)sender_guess)->GetScreenRect();
                        Unknown_004DC02D_point_guess returned_point_guess;
                        Unknown_004DC02D_point_guess* center_guess =
                            ((Unknown_004DC02D_rect_guess*)&rect_guess)->CenterPoint(&returned_point_guess);
                        point_guess = *center_guess;
                        field_1ac = index_guess;
                        pinstCContextMenuManager_guess->Register_guess(field_1a4, &point_guess, this);
                    }
                    return 0;
                }
            }
        }
    }

    return CSidlScreenWnd::WndNotification(sender_guess, message_guess, (void*)data_guess);
}
