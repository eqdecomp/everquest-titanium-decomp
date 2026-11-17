// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 136: a hint from compare/tumap.py.
// The buff windows, CBuffWindow: "BuffWindow" (25 slots) and "ShortDurationBuffWindow" (12, song buffs). Each
// slot shows the spell icon on a blue (beneficial) or red (detrimental) background, the name and time left as
// tooltip, and blinks in its last ticks. Wnd_guess and Thing_guess are views of it.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct CXRectView_guess {
    int left;
    int top;
    int right;
    int bottom;

    CXRectView_guess() {}
    CXRectView_guess(int left_guess, int top_guess, int right_guess, int bottom_guess) {
        left = left_guess;
        top = top_guess;
        right = right_guess;
        bottom = bottom_guess;
    }
    CXRectView_guess(const CXRectView_guess& other) {
        left = other.left;
        top = other.top;
        right = other.right;
        bottom = other.bottom;
    }

    // EXTERNAL: TITANIUM 0x004D9139 CXRectView_guess::SetSize_guess
    void SetSize_guess(int* origin, int* size);

    void GetSize_guess(int* size);
    void GetBorderSize_guess(int* out);
};

// EXTERNAL: TITANIUM 0x005C03E0 FUN_005c03e0_guess
void __stdcall FUN_005c03e0_guess(CXRectView_guess* out, CXRectView_guess rect);

// Border thickness: how much a 100x100 rect shrinks when the frame is applied, per axis.
// FUNCTION: TITANIUM 0x004E89FA
void CXRectView_guess::GetBorderSize_guess(int* out) {
    CXRectView_guess local;

    FUN_005c03e0_guess(&local, CXRectView_guess(0, 0, 100, 100));
    out[0] = (local.left - local.right) + 100;
    out[1] = (local.top - local.bottom) + 100;
}

struct Quad_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_C_guess;

    // EXTERNAL: TITANIUM 0x004D9160 Quad_guess::CopyTo_guess
    Quad_guess* CopyTo_guess(Quad_guess* destination, Quad_guess* source);
};

struct Entry_guess {
    unsigned char field_0_guess;
    unsigned char field_1_guess;
    char pad_2_guess[2];
    int field_4_guess;
    int field_8_guess;
};

struct ItemData_guess {
    char pad_000_guess[0x17d];
    unsigned char field_17d_guess;
    char pad_17e_guess[0x8a];
    const char* field_208_guess;
    char pad_20c_guess[0x3c];
    int field_248_guess;
};

struct ItemManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 ItemManager_guess::GetSpell_guess
    ItemData_guess* GetSpell_guess(int itemId_guess);
};

struct Inner_guess {
    // EXTERNAL: TITANIUM 0x0040DB4E Inner_guess::FUN_0040db4e_guess
    int FUN_0040db4e_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00410DB0 Inner_guess::FUN_00410db0_guess
    int FUN_00410db0_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x0040E893 Inner_guess::FUN_0040e893_guess
    char FUN_0040e893_guess(int index);
    // EXTERNAL: TITANIUM 0x0040E7AC Inner_guess::GetBuff_guess
    Entry_guess* GetBuff_guess(int index);
    // EXTERNAL: TITANIUM 0x0040DB0B Inner_guess::IsBardSong_guess
    int IsBardSong_guess(ItemData_guess* item_guess, unsigned char language_guess);
    // EXTERNAL: TITANIUM 0x0040EBC3 Inner_guess::SpellDuration_guess
    int SpellDuration_guess(ItemData_guess* item_guess, unsigned char value_guess,
                           int mode_guess);
};

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
bool __cdecl IsValidSpellIndex_guess(int itemId_guess);

struct CharacterInfo2View_guess {
    char pad_000_guess[0x119c];
    unsigned char field_119c_guess;
};

struct Outer_guess {
    char pad_0_guess[0xC280];
    Inner_guess inner_c280_guess;

    // EXTERNAL: TITANIUM 0x004BAD6A Outer_guess::RemoveMyAffect_guess
    void RemoveMyAffect_guess(int index);
};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::FUN_005adf60_guess
    unsigned char FUN_005adf60_guess(int first, int second);
};

struct ActionManager_guess {
    // EXTERNAL: TITANIUM 0x0051E0EA ActionManager_guess::CloseNewestItemDisplay_guess
    void CloseNewestItemDisplay_guess();
    // EXTERNAL: TITANIUM 0x005217B6 ActionManager_guess::FUN_005217b6_guess
    void FUN_005217b6_guess(int value, unsigned char color);
};

struct SpellGemSink_guess {
    virtual ~SpellGemSink_guess();
    char pad_004_guess[0x48];
    // EXTERNAL: TITANIUM 0x005B1D90 SpellGemSink_guess::SpellGemSink_guess
    SpellGemSink_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B SpellGemSink_guess::SetIcon_guess
    void SetIcon_guess(int icon_guess);
    // EXTERNAL: TITANIUM 0x005B1AB0 SpellGemSink_guess::Update_guess
    void Update_guess(int value);
};

struct SizePair_guess {
    int first_guess;
    int second_guess;
};

struct RectSource_guess {
    char pad_0_guess[0x3c];
    int field_3c_guess;
    int field_40_guess;
    int field_44_guess;
    int field_48_guess;
};

struct NestedCall_guess {
    // EXTERNAL: TITANIUM 0x0059CDB0 NestedCall_guess::FUN_0059cdb0_guess
    int* FUN_0059cdb0_guess(int* out);
};

struct CallOwner_guess {
    char pad_0_guess[0x20];
    NestedCall_guess call_20_guess;
};

struct TextureSet_guess {
    char pad_000_guess[0x60];
    int field_60_guess;
};

struct CBuffWindowView_guess {
    // EXTERNAL: TITANIUM 0x005A3850 CBuffWindowView_guess::CBuffWindowView_guess
    CBuffWindowView_guess(CXWnd* parent_guess, const CXStr& name_guess,
              int flags_guess, int ini_version_guess, char* block_guess);
    // EXTERNAL: TITANIUM 0x005A3100 ??1CBuffWindowView_guess@@QAE@XZ
    ~CBuffWindowView_guess();

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
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess(Quad_guess* out_guess);
    virtual Quad_guess* GetQuad_guess(Quad_guess* out);

    char pad_004_guess[0x14];
    unsigned char field_18_guess;
    char pad_019_guess[0x43];
    unsigned char show_005c_guess;
    unsigned char field_5d_guess;
    unsigned char field_5e_guess;
    char pad_5f_guess[1];
    unsigned char field_60_guess;
    char pad_61_guess;
    unsigned char mouseOver_0062_guess;
    char pad_63_guess;
    union {
        int windowStyle_0064_guess;
        struct {
            unsigned char field_64_byte_guess;
            unsigned char field_65_guess;
            unsigned char pad_66_guess[2];
        };
    };
    char pad_068_guess[0x10];
    CXStr field_078_guess;
    char pad_07c_guess[0x34];
    unsigned char alpha_00b0_guess;
    char pad_0b1_guess[0x17];
    CallOwner_guess* field_c8_guess;
    char pad_cc_guess[0x58];
    TextureSet_guess* field_124_guess;
    char pad_128_guess[0x30];
    int field_158_guess;
    unsigned char field_15c_guess;
    char pad_15d_guess[3];
    int field_160_guess;
    int field_164_guess;
    union {
        SpellGemSink_guess* field_168_guess[25];
        struct {
            int pad_168_guess;
            SpellGemSink_guess* field_16c_guess;
            char pad_170_guess[0x5c];
        };
    };
    union {
        int field_1cc_guess[25];
        RectSource_guess* field_1cc_ptr_guess;
    };
    int nextUpdateTime_0230_guess;
    int field_234_guess;
    int field_238_guess;
    int field_23c_guess;
    int field_240_guess;
    int field_244_guess;
    int buffSlotCount_0248_guess;

    void InitLayout_guess();
    bool AboutToShow_guess();
    void HandleSpellInfoDisplay_guess(int value);
    void SetBuffIcon_guess(CBuffWindowView_guess* target, int first, int second);
    void GetMinSize_guess(int* out);
    int PostDraw_guess();
    void WndNotification_guess(int value, int kind, int extra);
    // EXTERNAL: TITANIUM 0x005A02F0 CBuffWindowView_guess::FUN_005a02f0_guess
    void FUN_005a02f0_guess(int* point);
    // EXTERNAL: TITANIUM 0x0059FB00 CBuffWindowView_guess::FUN_0059fb00_guess
    void FUN_0059fb00_guess(Quad_guess* quad_guess);
    // EXTERNAL: TITANIUM 0x0059FF80 CBuffWindowView_guess::FUN_0059ff80_guess
    void FUN_0059ff80_guess(int* out);
    // EXTERNAL: TITANIUM 0x0059D790 CBuffWindowView_guess::FUN_0059d790_guess
    CXRectView_guess* FUN_0059d790_guess();
    void OnProcessFrame_guess();

    void RefreshBuffDisplay_guess();
    void RefreshIconArrangement_guess();

    // EXTERNAL: TITANIUM 0x005A1E10 CBuffWindowView_guess::FindChild_guess
    CBuffWindowView_guess* FindChild_guess(CXStr* name_guess);
    // EXTERNAL: TITANIUM 0x005A25B0 CBuffWindowView_guess::FUN_005a25b0_guess
    void FUN_005a25b0_guess();

    // EXTERNAL: TITANIUM 0x005A2230 CBuffWindowView_guess::FUN_005a2230_guess
    void FUN_005a2230_guess(int value, int kind, int extra);
};

struct ResourceManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 ResourceManager_guess::Load_guess
    int Load_guess(CXStr* name_guess);
};

#define g_outer_guess EQ_GLOBAL(Outer_guess*, 0x00905D00)
#define g_itemManager_guess EQ_GLOBAL(ItemManager_guess*, 0x00985CC8)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)
#define pinstCItemDisplayManager_guess EQ_GLOBAL(ActionManager_guess*, 0x00991B88)
#define g_resourceManager_guess EQ_GLOBAL(ResourceManager_guess*, 0x0099D3F4)

// Resets the refresh timer and records the window size, which makes the next frame re-lay out the icons.
// FUNCTION: TITANIUM 0x004E8AB0
void CBuffWindowView_guess::InitLayout_guess() {
    struct Locals_guess {
        Quad_guess local_34_guess;
        Quad_guess local_24_guess;
        Quad_guess local_14_guess;
    } local_guess;

    local_guess.local_14_guess.field_C_guess = 0;
    local_guess.local_14_guess.field_8_guess = 0;
    local_guess.local_14_guess.field_4_guess = 0;
    local_guess.local_14_guess.field_0_guess = 0;
    nextUpdateTime_0230_guess = 0;
    Quad_guess* quad_guess = GetQuad_guess(&local_guess.local_24_guess);
    local_guess.local_14_guess.CopyTo_guess(&local_guess.local_34_guess,
                                             quad_guess);
    field_15c_guess = 1;
    field_234_guess = local_guess.local_14_guess.field_8_guess -
                      local_guess.local_14_guess.field_0_guess;
    field_238_guess = local_guess.local_14_guess.field_C_guess -
                      local_guess.local_14_guess.field_4_guess;
}

// Buff window AboutToShow (vtable 0x6515E0 slot 49): vetoes the show while the window has no template
// (+0x124); otherwise forces a re-layout of the buff icons (0x004E8AB0) and allows it.
// FUNCTION: TITANIUM 0x004E8B0A
bool CBuffWindowView_guess::AboutToShow_guess() {
    if (field_124_guess == 0) {
        return false;
    }
    InitLayout_guess();
    return true;
}

// Shows spell info for the buff under icon `value`; the flag bit says whether to open a new info window
// (probably shift-click).
// FUNCTION: TITANIUM 0x004E8B1E
void CBuffWindowView_guess::HandleSpellInfoDisplay_guess(int value) {
    for (int i_guess = 0; i_guess < buffSlotCount_0248_guess; i_guess++) {
        if (value == field_1cc_guess[i_guess]) {
            if (g_outer_guess->inner_c280_guess.FUN_0040e893_guess(
                    field_240_guess + i_guess)) {
                pinstCItemDisplayManager_guess->FUN_005217b6_guess(
                    g_outer_guess->inner_c280_guess.GetBuff_guess(
                        field_240_guess + i_guess)->field_4_guess,
                    !(pinstCXWndManager_guess->FUN_005adf60_guess(0, -1) & 1));
            }
            return;
        }
    }
}

// Shows icon `first` on button `target`, on the blue background when `second` is set (beneficial), red when
// 0, none when -1. `first` -1 empties the button.
// FUNCTION: TITANIUM 0x004E8BA8
void CBuffWindowView_guess::SetBuffIcon_guess(CBuffWindowView_guess* target, int first, int second) {
    if (target != 0) {
        if (first > -1) {
            if (second == -1) {
                target->field_158_guess = 0;
            } else if (second != 0) {
                target->field_158_guess = field_160_guess;
            } else {
                target->field_158_guess = field_164_guess;
            }
            target->field_16c_guess->Update_guess(first);
        } else {
            target->field_158_guess = 0;
            target->field_16c_guess->Update_guess(-1);
        }
    }
}

// Smallest window size: one icon plus the border and, with a title bar (style bit 1), its height.
// FUNCTION: TITANIUM 0x004E8BFD
// @early-stop: budget, structural ndiff=18
void CBuffWindowView_guess::GetMinSize_guess(int* out) {
    SizePair_guess pair_guess;
    int local_14_guess[2];

    FUN_0059ff80_guess(&pair_guess.first_guess);
    if (field_1cc_ptr_guess != 0 && field_5e_guess == 0 &&
        show_005c_guess != 0) {
        pair_guess.first_guess = (field_1cc_ptr_guess->field_44_guess -
                                  field_1cc_ptr_guess->field_3c_guess) + 1;
        pair_guess.second_guess += field_1cc_ptr_guess->field_48_guess -
                                   field_1cc_ptr_guess->field_40_guess;
        CXRectView_guess* rect_guess = FUN_0059d790_guess();
        if (rect_guess != 0) {
            rect_guess->GetBorderSize_guess(local_14_guess);
            pair_guess.first_guess += local_14_guess[0];
        }
        if ((field_64_byte_guess & 1) != 0 && field_c8_guess != 0) {
            int* result_guess =
                field_c8_guess->call_20_guess.FUN_0059cdb0_guess(local_14_guess);
            pair_guess.first_guess += *result_guess;
        }
    }
    out[0] = pair_guess.first_guess;
    out[1] = pair_guess.second_guess;
}

// With a modifier held (notification flags 0x0C) and the mouse over a visible window, draws the icon grid
// outline, probably as a move/resize guide.
// FUNCTION: TITANIUM 0x004E8C95
// @early-stop: unknown, structural ndiff=73
int CBuffWindowView_guess::PostDraw_guess() {
    Quad_guess tempA_guess;
    Quad_guess tempB_guess;
    Quad_guess boundsA_guess;
    Quad_guess boundsB_guess;
    int point_guess[2];
    int step_guess;
    int rows_guess;
    int columns_guess;
    int x_guess;
    int idx_guess;
    int inner_guess;
    int outer_guess;

    if ((((CXWndManager*)pinstCXWndManager_guess)->GetKeyboardFlags() & 0x0c) == 0) {
        return 0;
    }
    if (mouseOver_0062_guess == 0) {
        return 0;
    }
    if (show_005c_guess == 0) {
        return 0;
    }

    boundsB_guess.field_C_guess = 0;
    boundsB_guess.field_8_guess = 0;
    boundsB_guess.field_4_guess = 0;
    boundsB_guess.field_0_guess = 0;
    boundsA_guess.field_C_guess = 0;
    boundsA_guess.field_8_guess = 0;
    boundsA_guess.field_4_guess = 0;
    boundsA_guess.field_0_guess = 0;
    point_guess[0] = 0;
    point_guess[1] = 0;

    if (field_1cc_guess[0] != 0) {
        boundsA_guess.CopyTo_guess(&tempA_guess,
                                   GetQuad_guess(&tempB_guess));
        CBuffWindowView_guess* first_guess = (CBuffWindowView_guess*)field_1cc_guess[0];
        boundsB_guess.CopyTo_guess(&tempB_guess,
                                   first_guess->GetQuad_guess(&tempA_guess));

        columns_guess = (boundsA_guess.field_8_guess -
                         boundsA_guess.field_0_guess) /
                        ((boundsB_guess.field_8_guess -
                          boundsB_guess.field_0_guess) + 1);
        rows_guess = (boundsA_guess.field_C_guess -
                      boundsA_guess.field_4_guess) /
                     ((boundsB_guess.field_C_guess -
                       boundsB_guess.field_4_guess) + 1);
        step_guess = ((boundsB_guess.field_8_guess -
                       boundsB_guess.field_0_guess) + 1) / columns_guess;

        idx_guess = 0;
        x_guess = 0;
        if (columns_guess > 0) {
            for (outer_guess = 0; outer_guess < columns_guess; outer_guess++) {
                for (inner_guess = 0; inner_guess < rows_guess; inner_guess++) {
                    if (idx_guess >= buffSlotCount_0248_guess) {
                        break;
                    }
                    if (field_1cc_guess[idx_guess] != 0) {
                        CBuffWindowView_guess* child_guess =
                            (CBuffWindowView_guess*)field_1cc_guess[idx_guess];
                        boundsB_guess.CopyTo_guess(
                            &tempB_guess,
                            child_guess->GetQuad_guess(&tempA_guess));
                        point_guess[0] =
                            (boundsB_guess.field_8_guess - x_guess) - 5;
                        point_guess[1] =
                            (outer_guess % 3) * 15 + boundsB_guess.field_4_guess;
                        child_guess->FUN_005a02f0_guess(point_guess);
                        idx_guess++;
                    }
                }
                x_guess += step_guess;
            }
        }
    }
    return 0;
}

// Width and height of the rect.
// FUNCTION: TITANIUM 0x004E8DFA
void CXRectView_guess::GetSize_guess(int* size) {
    int local[2];

    local[0] = right - left;
    local[1] = bottom - top;
    SetSize_guess(size, local);
}

// EXTERNAL: TITANIUM 0x006515E0 ??_7CBuffWindowDtorView_guess@@6B@
struct CBuffWindowDtorView_guess : CBuffWindowView_guess {
    ~CBuffWindowDtorView_guess();

    void* Destroy_guess(unsigned char flags);
};

// Buff window destructor: for each buff slot with a button, detaches the button's icon (+0x16C) and
// deletes the slot's animation copy (+0x168[i]).
// FUNCTION: TITANIUM 0x004E8A3C
// @early-stop: budget, structural ndiff=16
CBuffWindowDtorView_guess::~CBuffWindowDtorView_guess() {
    if (field_124_guess != 0 && buffSlotCount_0248_guess > 0) {
        SpellGemSink_guess** gem_guess = field_168_guess;
        for (int i_guess = 0; i_guess < buffSlotCount_0248_guess; i_guess++) {
            if (field_1cc_guess[i_guess] != 0) {
                ((CBuffWindowView_guess*)field_1cc_guess[i_guess])->field_16c_guess = 0;
                delete *gem_guess;
            }
            gem_guess++;
        }
    }
}

// Scalar deleting destructor of the buff window (vtable 0x6515E0 slot 1): runs the destructor
// (0x004E8A3C) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004E8E20
void* CBuffWindowDtorView_guess::Destroy_guess(unsigned char flags) {
    this->CBuffWindowDtorView_guess::~CBuffWindowDtorView_guess();
    if ((flags & 1) != 0) {
        operator delete(this);
    }
    return this;
}

// Icon left click: with a modifier, spell info; else removes the buff (RemoveMyAffect_guess) if it may be
// clicked off. Message 0x18 (probably right click) also shows spell info; 0x1A goes to the action manager.
// FUNCTION: TITANIUM 0x004E8E3C
void CBuffWindowView_guess::WndNotification_guess(int value, int kind, int extra) {
    if (show_005c_guess != 0) {
        if (kind == 1) {
            if ((((CXWndManager*)pinstCXWndManager_guess)->GetKeyboardFlags() & 0x0c) != 0) {
                HandleSpellInfoDisplay_guess(value);
            } else {
                for (int i_guess = 0; i_guess < buffSlotCount_0248_guess; ++i_guess) {
                    if (value == field_1cc_guess[i_guess]) {
                        if (g_outer_guess->inner_c280_guess.FUN_0040e893_guess(
                                field_240_guess + i_guess)) {
                            g_outer_guess->RemoveMyAffect_guess(
                                field_240_guess + i_guess);
                        }
                        break;
                    }
                }
            }
        } else {
            if (kind == 0x18) {
                HandleSpellInfoDisplay_guess(value);
            } else if (kind == 0x1a) {
                pinstCItemDisplayManager_guess->CloseNewestItemDisplay_guess();
            }
        }
    }
    FUN_005a2230_guess(value, kind, extra);
}

// Arranges the icons in as many columns as the client width allows, row by row, after a resize.
// FUNCTION: TITANIUM 0x004E8EF1
// @early-stop: budget, structural ndiff=45
void CBuffWindowView_guess::RefreshIconArrangement_guess() {
    struct Locals_guess {
        Quad_guess quad_64_guess;
        Quad_guess quad_54_guess;
        Quad_guess quad_44_guess;
        Quad_guess quad_34_guess;
        int origin_guess[2];
        int step_guess;
        int rows_guess;
        int columns_guess;
        int x_guess;
        int i_guess;
    } local_guess;
    int y_guess;
    int index_guess;

    local_guess.quad_34_guess.field_C_guess = 0;
    local_guess.quad_34_guess.field_8_guess = 0;
    local_guess.quad_34_guess.field_4_guess = 0;
    local_guess.quad_34_guess.field_0_guess = 0;
    local_guess.quad_44_guess.field_C_guess = 0;
    local_guess.quad_44_guess.field_8_guess = 0;
    local_guess.quad_44_guess.field_4_guess = 0;
    local_guess.quad_44_guess.field_0_guess = 0;
    local_guess.origin_guess[0] = 0;
    local_guess.origin_guess[1] = 0;

    if (field_1cc_guess[0] == 0) {
        return;
    }

    local_guess.quad_44_guess.CopyTo_guess(
        &local_guess.quad_64_guess, GetQuad_guess(&local_guess.quad_54_guess));
    local_guess.quad_34_guess.CopyTo_guess(
        &local_guess.quad_54_guess,
        ((CBuffWindowView_guess*)field_1cc_guess[0])
            ->GetQuad_guess(&local_guess.quad_64_guess));

    int step_x_guess = local_guess.quad_34_guess.field_8_guess -
                       local_guess.quad_34_guess.field_0_guess + 1;
    local_guess.columns_guess = (local_guess.quad_44_guess.field_8_guess -
                                 local_guess.quad_44_guess.field_0_guess) /
                                step_x_guess;
    int step_y_guess = local_guess.quad_34_guess.field_C_guess -
                       local_guess.quad_34_guess.field_4_guess + 1;
    index_guess = 0;
    local_guess.rows_guess = (local_guess.quad_44_guess.field_C_guess -
                              local_guess.quad_44_guess.field_4_guess) /
                             step_y_guess;

    if (field_15c_guess != 0) {
        Slot56_guess(&local_guess.quad_64_guess);
        if (local_guess.columns_guess > 0) {
            local_guess.step_guess = -step_x_guess;
            local_guess.x_guess = local_guess.quad_44_guess.field_8_guess -
                                  step_x_guess -
                                  local_guess.quad_44_guess.field_0_guess;
            do {
                local_guess.i_guess = 0;
                if (local_guess.rows_guess > 0) {
                    y_guess = 0;
                    while (local_guess.i_guess < local_guess.rows_guess) {
                        if (index_guess >= buffSlotCount_0248_guess) {
                            break;
                        }
                        if (field_1cc_guess[index_guess] != 0) {
                            local_guess.quad_34_guess.CopyTo_guess(
                                &local_guess.quad_54_guess,
                                ((CBuffWindowView_guess*)field_1cc_guess[index_guess])
                                    ->GetQuad_guess(&local_guess.quad_64_guess));
                            local_guess.origin_guess[0] = local_guess.x_guess;
                            local_guess.origin_guess[1] = y_guess;
                            ((CXRectView_guess*)&local_guess.quad_34_guess)
                                ->GetSize_guess(local_guess.origin_guess);
                            ((CBuffWindowView_guess*)field_1cc_guess[index_guess])
                                ->FUN_0059fb00_guess(&local_guess.quad_34_guess);
                            index_guess++;
                        }
                        local_guess.i_guess++;
                        y_guess += step_y_guess;
                    }
                }
                local_guess.x_guess += local_guess.step_guess;
            } while (--local_guess.columns_guess != 0);
        }
    } else {
        if (local_guess.rows_guess > 0) {
            local_guess.step_guess = local_guess.rows_guess;
            local_guess.rows_guess = 0;
            do {
                local_guess.i_guess = 0;
                if (local_guess.columns_guess > 0) {
                    local_guess.x_guess = 0;
                    while (local_guess.i_guess < local_guess.columns_guess) {
                        if (index_guess >= buffSlotCount_0248_guess) {
                            break;
                        }
                        if (field_1cc_guess[index_guess] != 0) {
                            local_guess.quad_34_guess.CopyTo_guess(
                                &local_guess.quad_54_guess,
                                ((CBuffWindowView_guess*)field_1cc_guess[index_guess])
                                    ->GetQuad_guess(&local_guess.quad_64_guess));
                            local_guess.origin_guess[0] = local_guess.x_guess;
                            local_guess.origin_guess[1] =
                                local_guess.rows_guess;
                            ((CXRectView_guess*)&local_guess.quad_34_guess)
                                ->GetSize_guess(local_guess.origin_guess);
                            ((CBuffWindowView_guess*)field_1cc_guess[index_guess])
                                ->FUN_0059fb00_guess(&local_guess.quad_34_guess);
                            index_guess++;
                        }
                        local_guess.i_guess++;
                        local_guess.x_guess += step_x_guess;
                    }
                }
                local_guess.rows_guess += step_y_guess;
            } while (--local_guess.step_guess != 0);
        }
    }

    for (; index_guess < buffSlotCount_0248_guess; index_guess++) {
        if (field_1cc_guess[index_guess] != 0) {
            ((CBuffWindowView_guess*)field_1cc_guess[index_guess])->Slot48_guess(0, 0);
        }
    }
}

struct Clock_guess {
    char pad_0_guess[0x148];
    int frameTime_0148_guess;
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)

// Refreshes the icons every 50 ms and re-lays them out after a size change.
// FUNCTION: TITANIUM 0x004E950F
void CBuffWindowView_guess::OnProcessFrame_guess() {
    if (show_005c_guess != 0) {
        if ((unsigned int)g_clock_guess->frameTime_0148_guess >= (unsigned int)nextUpdateTime_0230_guess) {
            nextUpdateTime_0230_guess = g_clock_guess->frameTime_0148_guess + 0x32;
            RefreshBuffDisplay_guess();
        }
        if (field_234_guess != 0 || field_238_guess != 0) {
            RefreshIconArrangement_guess();
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Fills each icon from the character's buffs (slots field_240-field_244): icon, background and
// "Name (m:ss)"
// tooltip, with time left in 6-second ticks. Under 4 ticks left the icon fades each second, unless the
// class's own full duration of that spell is itself under 4 ticks.
// FUNCTION: TITANIUM 0x004E912F
// @early-stop: budget, diff ndiff=94
void CBuffWindowView_guess::RefreshBuffDisplay_guess() {
    if (g_outer_guess != 0) {
        int currentValue_guess = alpha_00b0_guess;
        int reducedValue_guess =
            (100 - (int)(((unsigned int)g_clock_guess->frameTime_0148_guess % 1000) /
                         10)) * currentValue_guess / 100;

        for (int itemIndex_guess = field_240_guess;
             itemIndex_guess <= field_244_guess; ++itemIndex_guess) {
            if (itemIndex_guess - field_240_guess >= buffSlotCount_0248_guess) {
                break;
            }

            if (field_1cc_guess[itemIndex_guess - field_240_guess] == 0) {
                continue;
            }

            if (g_outer_guess->inner_c280_guess.GetBuff_guess(
                    itemIndex_guess)->field_0_guess == 0 ||
                !IsValidSpellIndex_guess(
                    g_outer_guess->inner_c280_guess.GetBuff_guess(
                        itemIndex_guess)->field_4_guess)) {
                SetBuffIcon_guess(
                    (CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                field_240_guess],
                    -1, 0);
                {
                    CXStr message_guess("");
                    ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                 field_240_guess])
                        ->field_078_guess = message_guess;
                }
                continue;
            }

            ItemData_guess* item_guess =
                g_itemManager_guess->GetSpell_guess(
                    g_outer_guess->inner_c280_guess.GetBuff_guess(
                        itemIndex_guess)->field_4_guess);
            if (item_guess == 0) {
                SetBuffIcon_guess(
                    (CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                field_240_guess],
                    -1, 0);
                {
                    CXStr message_guess("");
                    ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                 field_240_guess])
                        ->field_078_guess = message_guess;
                }
                continue;
            }

            int icon_guess = item_guess->field_248_guess;
            if (icon_guess < 0) {
                icon_guess = 0;
            }
            SetBuffIcon_guess(
                (CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                            field_240_guess],
                icon_guess, item_guess->field_17d_guess);

            int duration_guess =
                g_outer_guess->inner_c280_guess.GetBuff_guess(
                    itemIndex_guess)->field_8_guess;
            char text_buffer_guess[256];
            if (duration_guess < 0) {
                sprintf(text_buffer_guess, "%s", item_guess->field_208_guess);
            } else {
                // Ticks to minutes:seconds (10 ticks a minute).
                sprintf(text_buffer_guess, "%s (%d:%02d)",
                        item_guess->field_208_guess, duration_guess / 10,
                        (duration_guess % 10) * 6);
            }
            {
                CXStr message_guess(text_buffer_guess);
                ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                             field_240_guess])
                    ->field_078_guess = message_guess;
            }

            if (((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                            field_240_guess])
                    ->show_005c_guess == 0) {
                ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                             field_240_guess])
                    ->Slot48_guess(1, 0);
            } else if (
                g_outer_guess->inner_c280_guess.GetBuff_guess(
                    itemIndex_guess)->field_8_guess < 4 &&
                g_outer_guess->inner_c280_guess.GetBuff_guess(
                    itemIndex_guess)->field_8_guess != -1) {
                CharacterInfo2View_guess* characterInfo_guess =
                    (CharacterInfo2View_guess*)pCharData->GetCharInfo2();
                if (g_outer_guess->inner_c280_guess.IsBardSong_guess(
                        item_guess,
                        characterInfo_guess->field_119c_guess) != 0) {
                    if (g_outer_guess->inner_c280_guess.SpellDuration_guess(
                            item_guess,
                            g_outer_guess->inner_c280_guess
                                .GetBuff_guess(itemIndex_guess)
                                ->field_1_guess,
                            1) < 4) {
                        ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                    field_240_guess])
                            ->alpha_00b0_guess =
                            (unsigned char)currentValue_guess;
                    } else {
                        ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                    field_240_guess])
                            ->alpha_00b0_guess =
                            (unsigned char)reducedValue_guess;
                    }
                } else {
                    ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                                field_240_guess])
                        ->alpha_00b0_guess =
                        (unsigned char)reducedValue_guess;
                }
            } else {
                ((CBuffWindowView_guess*)field_1cc_guess[itemIndex_guess -
                                            field_240_guess])
                    ->alpha_00b0_guess =
                    (unsigned char)currentValue_guess;
            }
        }
    }
}

// EXTERNAL: TITANIUM 0x006515E0 ??_7CBuffWindow_guess@@6B@
struct CBuffWindow_guess : CBuffWindowView_guess {
    CBuffWindow_guess(CXWnd* parent_guess, int short_duration_guess);
};

// `short_duration_guess` 1 builds the short-duration (song) window with 12 slots, else the 25-slot one. Loads
// the blue and red icon backgrounds and A_SpellIcons, then binds Buff0-BuffN.
// FUNCTION: TITANIUM 0x004E955B
// @early-stop: budget, structural ndiff=80
CBuffWindow_guess::CBuffWindow_guess(CXWnd* parent_guess,
                                   int short_duration_guess)
    : CBuffWindowView_guess(parent_guess,
                CXStr(short_duration_guess == 1
                          ? "ShortDurationBuffWindow"
                          : "BuffWindow"),
                -1, 1, 0) {
    buffSlotCount_0248_guess = short_duration_guess == 0 ? 25 : 12;
    if (buffSlotCount_0248_guess > 25) {
        buffSlotCount_0248_guess = 25;
    }

    if (field_124_guess != 0) {
        windowStyle_0064_guess |= field_124_guess->field_60_guess | 0x800;
        field_18_guess = 0;
        FUN_005a25b0_guess();

        int blue_guess;
        {
            CXStr name_guess("BlueIconBackground");
            blue_guess = g_resourceManager_guess->Load_guess(&name_guess);
        }
        field_160_guess = blue_guess;

        int red_guess;
        {
            CXStr name_guess("RedIconBackground");
            red_guess = g_resourceManager_guess->Load_guess(&name_guess);
        }
        field_164_guess = red_guess;

        int icons_guess;
        {
            CXStr name_guess("A_SpellIcons");
            icons_guess = g_resourceManager_guess->Load_guess(&name_guess);
        }

        for (int index_guess = 0; index_guess < buffSlotCount_0248_guess;
             ++index_guess) {
            char name_buffer_guess[128];
            sprintf(name_buffer_guess, "Buff%d", index_guess);
            CBuffWindowView_guess* child_guess;
            {
                CXStr name_guess(name_buffer_guess);
                child_guess = FindChild_guess(&name_guess);
            }
            field_1cc_guess[index_guess] = (int)child_guess;
            if (child_guess != 0) {
                SpellGemSink_guess* gem_guess = new SpellGemSink_guess;
                field_168_guess[index_guess] = gem_guess;
                gem_guess->SetIcon_guess(icons_guess);
                child_guess->field_16c_guess = gem_guess;
                child_guess->field_60_guess = 0;
                child_guess->field_65_guess |= 8;
                SetBuffIcon_guess(child_guess, -1, 0);
            } else {
                field_168_guess[index_guess] = 0;
            }
        }

        field_23c_guess = short_duration_guess;
        bool normalized_guess = short_duration_guess == 1;
        field_240_guess = g_outer_guess->inner_c280_guess.FUN_0040db4e_guess(
            normalized_guess, 0);
        field_244_guess = g_outer_guess->inner_c280_guess.FUN_00410db0_guess(
            normalized_guess, 0, 1);
        InitLayout_guess();
    }
}
