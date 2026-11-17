// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 150: a hint from compare/tumap.py.
// CCursorAttachment ("CursorAttachment", 0x850C24): what rides on the mouse cursor. CCursorAttachmentView_guess and
// Gate_guess are both this window (+0x15C kind, +0x160 value, +0x164 count, +0x168 label). Kinds: 2 item,
// 3 coins, 4 social, 5 menu button, 6-7 action buttons, 8 item hot button, 9 spell gem, 10 pet command,
// 11 skill, 12 combat ability, 13 leadership ability (the hot button types of tu_168, renumbered).
#include "titanium/types.h"

// CTextureAnimation (0x4C bytes, ctor 0x005B1D90).
struct Rect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9160 Rect_guess::Combine_guess
    void Combine_guess(Rect_guess* first_guess, const Rect_guess* second_guess);
};

struct AnimName_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x004482FB AnimName_guess::Clear_guess
    void Clear_guess();
};

struct AnimFrames_guess {
    int data_guess[4];
    // EXTERNAL: TITANIUM 0x004DBACA AnimFrames_guess::Clear_guess
    void Clear_guess();
};

struct CTextureAnimationView_guess {
    int field_00_guess;                 // 0x00
    AnimName_guess name_04_guess;       // 0x04
    AnimFrames_guess frames_08_guess;   // 0x08
    int field_18_guess;                 // 0x18
    int field_1c_guess;                 // 0x1C
    int field_20_guess;                 // 0x20
    int field_24_guess;                 // 0x24
    int cell_28_guess;                  // 0x28
    unsigned char flag_2c_guess;        // 0x2C
    unsigned char flag_2d_guess;        // 0x2D
    unsigned char flag_2e_guess;        // 0x2E
    unsigned char flag_2f_guess;        // 0x2F
    int field_30_guess;                 // 0x30
    int field_34_guess;                 // 0x34
    int field_38_guess;                 // 0x38
    Rect_guess rect_3c_guess;           // 0x3C
    // EXTERNAL: TITANIUM 0x005B1D90 ??0CTextureAnimationView_guess@@QAE@XZ
    CTextureAnimationView_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B CTextureAnimationView_guess::Apply_guess
    void Apply_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005B1AB0 CTextureAnimationView_guess::SetIndex_guess
    void SetIndex_guess(int value_guess);
    void Reset_guess();
};

struct RectSource_guess {
    char pad_00_guess[0x48];
    Rect_guess rect_guess;
    char pad_58_guess[0x0c];
    CTextureAnimationView_guess* animation_64_guess;
};

struct ObjectState_guess {
    char pad_00_guess[0x64];
    CTextureAnimationView_guess* animation_64_guess;
};

struct RectPair_guess {
    Rect_guess source_guess;
    Rect_guess built_guess;
};

struct Child_guess {
    int value_guess;
    Child_guess() : value_guess(0) {}
    // EXTERNAL: TITANIUM 0x004D95D0 Child_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x004482FB ??1Child_guess@@QAE@XZ
    ~Child_guess();
};

struct Primary_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1Primary_guess@@UAE@XZ
    virtual ~Primary_guess();
    // EXTERNAL: TITANIUM 0x005A3900 ??0Primary_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    Primary_guess(CXWnd* parent_guess, const CXStr& screen_guess);
    // EXTERNAL: TITANIUM 0x005A2490 Primary_guess::GetChildLabel_guess
    CXWnd* GetChildLabel_guess(const CXStr& name_guess);
    // EXTERNAL: TITANIUM 0x0059DB90 Primary_guess::FUN_0059db90_guess
    void FUN_0059db90_guess(int value_guess);
};

struct Releaser_guess {
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
    virtual int Slot13_guess();
    virtual void Slot14_guess(void* value_guess);
};

#define g_releaser_guess EQ_GLOBAL(Releaser_guess*, 0x0099E360)

struct Interface_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(void* value_guess);
    virtual void Slot02_guess();
    virtual void Slot03_guess(int kind_guess, Rect_guess* first_guess,
                              Rect_guess* second_guess, int a_guess,
                              int b_guess, int c_guess);
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
    virtual void Slot30_guess(void* value_guess);
};

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CQuantityWnd.h"

// CA_SpellGem: a child window called through its vtable slot at +0xC0.
struct CSpellGemWnd_guess {
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
    // EXTERNAL: TITANIUM 0x00558984 CSpellGemWnd_guess::SetSpellIcon_guess
    void SetSpellIcon_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005589AB CSpellGemWnd_guess::SetSpellGemTint_guess
    void SetSpellGemTint_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x00653510 ??_7CCursorAttachmentView_guess@@6B@
struct CCursorAttachmentView_guess : Primary_guess {
    virtual ~CCursorAttachmentView_guess();
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
    virtual void GetRect_guess(Rect_guess* rect_guess);

    // FUNCTION marked on the definition below
    void* Deleter_guess(unsigned char flags_guess);

    char pad_04_guess[0x58];                // 0x004
    char flag_guess;                        // 0x05C
    char pad_5d_guess[0x07];                // 0x05D
    unsigned int windowStyle_064_guess;     // 0x064
    char pad_068_guess[0x49];               // 0x068
    unsigned char fades_0b1_guess;          // 0x0B1
    char pad_0b2_guess[0x72];               // 0x0B2
    void* sidlPiece_124_guess;              // 0x124
    char pad_128_guess[0x28];               // 0x128
    int field_150_guess;                    // 0x150
    char pad_154_guess[0x08];               // 0x154
    int attachmentType_015c_guess;                    // 0x15C
    int field_160_guess;                    // 0x160
    int quantity_0164_guess;                    // 0x164
    Child_guess child_168_guess;            // 0x168
    RectSource_guess* source_16c_guess;     // 0x16C
    ObjectState_guess* state_170_guess;     // 0x170
    CSpellGemWnd_guess* child_174_guess;     // 0x174
    void* ptr_178_guess;                    // 0x178
    Interface_guess* interface_17c_guess;   // 0x17C
    int field_180_guess;                    // 0x180

    CCursorAttachmentView_guess(CXWnd* parent_guess);
    // EXTERNAL: TITANIUM 0x0059D6C0 CCursorAttachmentView_guess::GetClientClipRect
    void GetClientClipRect(Rect_guess* rect_guess);
    // EXTERNAL: TITANIUM 0x0059D960 CCursorAttachmentView_guess::GetScreenRect
    int* GetScreenRect(Rect_guess* rect_guess);
    void DrawButtonText_guess();
    void DrawQuantity_guess();
    int Draw();
};

#define g_manager_guess EQ_GLOBAL(Interface_guess*, 0x0099E364)
#define g_fontIndex_guess EQ_GLOBAL(int, 0x00923D74)

// EXTERNAL: TITANIUM 0x004AE49C IsDoubleByteLanguage_guess
char __cdecl IsDoubleByteLanguage_guess(int value_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void free(void* memory_guess);

struct LabelHolder_guess {
    CXStr text_guess;
    // EXTERNAL: TITANIUM 0x004482FB LabelHolder_guess::~LabelHolder_guess
    ~LabelHolder_guess();
};

struct Gate_guess {
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
    char pad_04_guess[0x14];            // 0x004
    unsigned char active_18_guess;      // 0x018
    char pad_19_guess[0x143];           // 0x019
    int kind_015c_guess;                 // 0x15C
    int value_0160_guess;                // 0x160
    int count_0164_guess;                // 0x164
    LabelHolder_guess label_168_guess;  // 0x168
    RectSource_guess* source_16c_guess; // 0x16C
    ObjectState_guess* state_170_guess; // 0x170
    CSpellGemWnd_guess* child_174_guess; // 0x174
    // EXTERNAL: TITANIUM 0x0059DD30 Gate_guess::Ready_guess
    char Ready_guess();
    char IsOkToActivate_guess(int value_guess);
    char Check_guess();
    void Post_guess(int first_guess, int kind_guess, int third_guess,
                    int fourth_guess, int fifth_guess);
    // EXTERNAL: TITANIUM 0x0059FA70 Gate_guess::Move_guess
    void Move_guess(struct Pos_guess* pos_guess);
    // EXTERNAL: TITANIUM 0x0059D080 Gate_guess::SetState_guess
    void SetState_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005A0E50 Gate_guess::OnProcessFrame
    void OnProcessFrame();
    void OnProcessFrame_guess();
};

// Unhooks the two icon animations (not deleted here) and frees the two text objects (0x99E360).
// FUNCTION: TITANIUM 0x004FD2C8
CCursorAttachmentView_guess::~CCursorAttachmentView_guess() {
    if (source_16c_guess != 0 && source_16c_guess->animation_64_guess != 0) {
        source_16c_guess->animation_64_guess = 0;
    }
    if (state_170_guess != 0 && state_170_guess->animation_64_guess != 0) {
        state_170_guess->animation_64_guess = 0;
    }
    g_releaser_guess->Slot14_guess(ptr_178_guess);
    g_releaser_guess->Slot14_guess(interface_17c_guess);
}


// Not while window 0x850C3C is shown, nor over an item or coins already on the cursor (kinds 2-3).
// FUNCTION: TITANIUM 0x004FD36C
char Gate_guess::IsOkToActivate_guess(int value_guess) {
    if (pinstCQuantityWnd_guess->IsVisible_guess() != 0) {
        return 0;
    }
    if (Ready_guess() && (kind_015c_guess == 3 || kind_015c_guess == 2)) {
        return 0;
    }
    return 1;
}

// Drops a shown attachment when that is allowed; returns whether it did.
// FUNCTION: TITANIUM 0x004FD3A3
char Gate_guess::Check_guess() {
    if (Ready_guess() != 0) {
        if (IsOkToActivate_guess(-1) != 0) {
            Slot34_guess();
            return 1;
        }
    }
    return 0;
}

// Cursor attachment constructor: starts empty (kind and value -1), gives CA_Anim and CA_Anim2 a new
// animation each, starts CA_SpellGem off (virtual slot 48), takes two text objects from 0x99E360, and
// clears +0x180 for language ids 1-3 and 6 (0x004AE49C on 0x923D74).
// FUNCTION: TITANIUM 0x004FD3CE
CCursorAttachmentView_guess::CCursorAttachmentView_guess(CXWnd* parent_guess)
    : Primary_guess(parent_guess, "CursorAttachment") {
    attachmentType_015c_guess = -1;
    field_160_guess = -1;
    if (sidlPiece_124_guess != 0) {
        windowStyle_064_guess |= ((CScreenPieceTemplate*)sidlPiece_124_guess)->style_guess;
        fades_0b1_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        source_16c_guess = (RectSource_guess*)GetChildLabel_guess("CA_Anim");
        if (source_16c_guess != 0) {
            source_16c_guess->animation_64_guess = new CTextureAnimationView_guess;
        }
        state_170_guess = (ObjectState_guess*)GetChildLabel_guess("CA_Anim2");
        if (state_170_guess != 0) {
            state_170_guess->animation_64_guess = new CTextureAnimationView_guess;
        }
        child_174_guess = (CSpellGemWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("CA_SpellGem");
        if (child_174_guess != 0) {
            child_174_guess->Slot48_guess(0, 0);
        }
        FUN_0059db90_guess(300);
        int flag_guess = 1;
        if (IsDoubleByteLanguage_guess(g_fontIndex_guess) != 0) {
            flag_guess = 0;
        }
        child_168_guess.~Child_guess();
        field_150_guess = -1;
        ptr_178_guess = (void*)g_releaser_guess->Slot13_guess();
        field_180_guess = flag_guess;
        interface_17c_guess = (Interface_guess*)g_releaser_guess->Slot13_guess();
    }
}

// Scalar deleting destructor of the cursor attachment window (vtable 0x653510 slot 1): runs the
// destructor (0x004FD2C8) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004FD5DF
void* CCursorAttachmentView_guess::Deleter_guess(unsigned char flags_guess) {
    this->CCursorAttachmentView_guess::~CCursorAttachmentView_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Draws the label text over the attachment when it has one.
// FUNCTION: TITANIUM 0x004FD5FB
void CCursorAttachmentView_guess::DrawButtonText_guess() {
    Rect_guess bounds_guess;
    RectPair_guess pair_guess;

    if (!child_168_guess.IsReady_guess() && flag_guess) {
        GetRect_guess(&bounds_guess);
        GetClientClipRect(&pair_guess.built_guess);
        if (source_16c_guess != 0) {
            bounds_guess.Combine_guess(&pair_guess.source_guess,
                                       &source_16c_guess->rect_guess);
            int x_guess = *GetScreenRect(&pair_guess.source_guess);
            bounds_guess.left_guess += x_guess;
            bounds_guess.right_guess += x_guess;
            int y_guess = GetScreenRect(&pair_guess.source_guess)[1];
            bounds_guess.top_guess += y_guess;
            bounds_guess.bottom_guess += y_guess;
            pair_guess.built_guess.Combine_guess(&pair_guess.source_guess,
                                                 &bounds_guess);
        }
        interface_17c_guess->Slot01_guess(&child_168_guess);
        interface_17c_guess->Slot03_guess(2, &bounds_guess, &bounds_guess,
                                          -1, 0x30, 0);
        g_manager_guess->Slot30_guess(interface_17c_guess);
    }
}

struct Font_guess {
    // EXTERNAL: TITANIUM 0x005A3A00 Font_guess::MeasureText_guess
    int MeasureText_guess(CXStr* text_guess);
    // EXTERNAL: TITANIUM 0x005A3A20 Font_guess::Height_guess
    int Height_guess();
};

struct FontSlots_guess {
    // EXTERNAL: TITANIUM 0x004EB924 FontSlots_guess::Slot_guess
    Font_guess** Slot_guess(int index_guess);
};

struct SlotHolder_guess {
    char pad_00_guess[0xf4];
    FontSlots_guess slots_f4_guess;
};

#define g_slotHolder_guess EQ_GLOBAL(SlotHolder_guess*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x0059D2E0 FUN_0059d2e0_guess
void __cdecl FUN_0059d2e0_guess(Rect_guess* out_guess, unsigned int color_guess,
                                Rect_guess* in_guess);

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text_guess, const char* format_guess,
                                ...);

struct Text_guess {
    char* data_guess;
    // EXTERNAL: TITANIUM 0x005724C0 Text_guess::Text_guess
    Text_guess(int value_guess, int flag_guess, int width_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Text_guess::FreeRep
    void FreeRep(char* data_guess);
    ~Text_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct TextSink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(const Text_guess& text_guess);
};

// Draws the count when above 0: for items (kinds 2 and 8) right-aligned in the bottom corner on a dark box
// (0xFF404040), for the rest along the bottom edge.
// FUNCTION: TITANIUM 0x004FD6C6
void CCursorAttachmentView_guess::DrawQuantity_guess() {
    if (quantity_0164_guess >= 1) {
        char flag_copy_guess = flag_guess;
        if (flag_copy_guess != 0) {
            Rect_guess built_guess;
            Rect_guess bounds_guess;
            GetRect_guess(&bounds_guess);
            GetClientClipRect(&built_guess);
            if (attachmentType_015c_guess == 2 || attachmentType_015c_guess == 8) {
                CXStr text_guess;
                FormatString_guess(&text_guess, "%d", quantity_0164_guess);
                int width_guess = 0;
                Font_guess* font_guess =
                    *g_slotHolder_guess->slots_f4_guess.Slot_guess(field_180_guess);
                if (font_guess != 0) {
                    width_guess = font_guess->MeasureText_guess(&text_guess);
                    if (width_guess < 10) {
                        width_guess = 10;
                    }
                }
                bounds_guess.bottom_guess -= 6;
                int top_guess = bounds_guess.bottom_guess - 10;
                bounds_guess.right_guess -= 6;
                bounds_guess.left_guess = bounds_guess.right_guess - width_guess;
                bounds_guess.top_guess = top_guess;
                FUN_0059d2e0_guess(&bounds_guess, 0xff404040, &bounds_guess);
                ((Interface_guess*)ptr_178_guess)->Slot01_guess(&text_guess);
                ((Interface_guess*)ptr_178_guess)->Slot03_guess(
                    field_180_guess, &bounds_guess, &built_guess, -1, 0, 0);
                g_manager_guess->Slot30_guess(ptr_178_guess);
            } else {
                bounds_guess.top_guess = bounds_guess.bottom_guess - 4;
                Font_guess* font_guess =
                    *g_slotHolder_guess->slots_f4_guess.Slot_guess(field_180_guess);
                bounds_guess.bottom_guess =
                    font_guess->Height_guess() + bounds_guess.top_guess;
                FUN_0059d2e0_guess(&bounds_guess, 0xff404040, &bounds_guess);
                ((TextSink_guess*)ptr_178_guess)->Slot01_guess(
                    Text_guess(quantity_0164_guess, 2, 0x20));
                ((Interface_guess*)ptr_178_guess)->Slot03_guess(
                    field_180_guess, &bounds_guess, &bounds_guess, -1, 0x11, 0);
                g_manager_guess->Slot30_guess(ptr_178_guess);
            }
        }
    }
}

// Draw: the label, then the count.
// FUNCTION: TITANIUM 0x004FD8A9
int CCursorAttachmentView_guess::Draw() {
    DrawButtonText_guess();
    DrawQuantity_guess();
    return 0;
}

struct Pos_guess {
    int x_guess;
    int y_guess;
};

struct SlotPos_guess {
    char pad_00_guess[0x74];
    int x_74_guess;
    int y_78_guess;
};
#define g_slotPos_guess EQ_GLOBAL(SlotPos_guess*, 0x0099D3EC)

struct Flags_guess {
    char pad_00_guess[0x10];
    unsigned char itemOnCursor_10_guess;
    unsigned char coinOnCursor_11_guess;
};
#define g_flags_guess EQ_GLOBAL(Flags_guess*, 0x00905D24)

struct GameState_guess {
    char pad_00_guess[0xB54];
    int state_b54_guess;
};
#define g_everQuest_guess EQ_GLOBAL(GameState_guess*, 0x00988DF0)

// pCharData (0x00905D00): the profile is a virtual base at +0xC384, reached through the vbptr at +8.
struct PcPrefix_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct CharInfoSub_guess {
    char pad_00_guess[0x78];
    int field_78_guess;
    int Field78_guess() { return field_78_guess; }
};

struct CharInfo_guess {
    char pad_00_guess[0x10];
    CharInfoSub_guess sub_10_guess;
    char pad_08c_guess[0x1158];
    int cursorPlatinum_11e4_guess;
    int cursorGold_11e8_guess;
    int cursorSilver_11ec_guess;
    int cursorCopper_11f0_guess;
};

struct CharProfile_guess {
    void* list_guess;
    int key_guess;
    // EXTERNAL: TITANIUM 0x005EC220 CharProfile_guess::GetCharInfo2
    CharInfo_guess* GetCharInfo2();
};

struct CharBase_guess {
    void* vftable_guess;
    CharProfile_guess profile_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 CharBase_guess::GetInventorySlot_guess
    int GetInventorySlot_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x0040E705 CharBase_guess::GetMemorizedSpell_guess
    int GetMemorizedSpell_guess(int slot_guess);
};

struct PcView_guess2 : PcPrefix_guess, virtual CharBase_guess {
    char pad_0C_guess[0xC384 - 0x0C];
};
#define g_pcView_guess2 EQ_GLOBAL(PcView_guess2*, 0x00905D00)

struct CSidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 CSidlManager_guess::Find_guess
    int Find_guess(CXStr* name_guess);
};
#define g_itemManager_guess EQ_GLOBAL(CSidlManager_guess*, 0x0099D3F4)

struct ItemRecord_guess {
    char pad_00_guess[0x248];
    int icon_0248_guess;
    // EXTERNAL: TITANIUM 0x0044D103 ItemRecord_guess::GetSpellColor_guess
    int GetSpellColor_guess();
};

struct SpellManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 SpellManager_guess::Find_guess
    ItemRecord_guess* Find_guess(int item_guess);
};
#define g_itemCatalog_guess EQ_GLOBAL(SpellManager_guess*, 0x00985CC8)

struct ItemState_guess {
    char pad_00_guess[0x48];
    int value_48_guess;
    // EXTERNAL: TITANIUM 0x005E0F60 ItemState_guess::Timer_guess
    int Timer_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ItemState_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC760 ItemState_guess::IsStackable_guess
    char IsStackable_guess();
};

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value_guess);

// EXTERNAL: TITANIUM 0x004DBACA FUN_004dbaca_guess
void __cdecl FUN_004dbaca_guess();

// Resets an animation: clears its name and frame list and zeroes its state (cell +0x28 = 0, +0x38 = -1,
// +0x2D = 1, rectangle +0x3C empty).
// FUNCTION: TITANIUM 0x004FD8BC
// @early-stop: tiebreak, structural ndiff=3
void CTextureAnimationView_guess::Reset_guess() {
    name_04_guess.Clear_guess();
    frames_08_guess.Clear_guess();
    field_38_guess = -1;
    field_18_guess = 0;
    field_1c_guess = 0;
    field_20_guess = 0;
    field_24_guess = 0;
    flag_2c_guess = 0;
    flag_2e_guess = 0;
    flag_2f_guess = 0;
    field_34_guess = 0;
    field_30_guess = 0;
    Rect_guess zero_guess = { 0, 0, 0, 0 };
    Rect_guess out_guess;
    cell_28_guess = 0;
    flag_2d_guess = 1;
    rect_3c_guess.Combine_guess(&out_guess, &zero_guess);
}

// pCharData (0x00905D00): the profile is a virtual base at +0xC384, reached through the vbptr at +8.

// Picks up `kind_guess` with icon `first_guess`, slot or value `third_guess`, label `fourth_guess` and
// count `fifth_guess`, then shows itself at the mouse. Coins take A_DragItem cells 0x90-0x93 (platinum to
// copper, type at pinstCDisplay +0x11) and the amount on the character; a cursor item shows icon id - 500
// and its stack count. Kind 9 shows the gem's spell icon and tint in CA_SpellGem.
// FUNCTION: TITANIUM 0x004FD91E
// @early-stop: budget, structural ndiff=251
void Gate_guess::Post_guess(int first_guess, int kind_guess, int third_guess,
                            int fourth_guess, int fifth_guess) {
    int first_copy_guess = first_guess;
    Pos_guess pos_guess;
    active_18_guess = 1;
    if (pinstCQuantityWnd_guess != 0 && pinstCQuantityWnd_guess->IsVisible_guess() != 0) {
        pinstCQuantityWnd_guess->Deactivate();
    }

    label_168_guess.~LabelHolder_guess();
    if (fourth_guess != 0) {
        label_168_guess.text_guess = (const char*)fourth_guess;
    }
    if (child_174_guess != 0) {
        child_174_guess->Slot48_guess(0, 1);
    }

    if (source_16c_guess != 0 && source_16c_guess->animation_64_guess != 0) {
        if (first_copy_guess != 0 && kind_guess != 8) {
            source_16c_guess->animation_64_guess->Apply_guess(first_copy_guess);
        // Coins (kind 3): the A_DragItem cell by coin type, the amount as the label.
        } else if (kind_guess == 3) {
            int selection_guess = g_flags_guess->coinOnCursor_11_guess;
            if (selection_guess == 1) {
                fifth_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                    .GetCharInfo2()->cursorPlatinum_11e4_guess;
            } else if (selection_guess == 2) {
                fifth_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                    .GetCharInfo2()->cursorGold_11e8_guess;
            } else if (selection_guess == 3) {
                fifth_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                    .GetCharInfo2()->cursorSilver_11ec_guess;
            } else if (selection_guess == 4) {
                fifth_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                    .GetCharInfo2()->cursorCopper_11f0_guess;
            }

            if (fifth_guess < 1) {
                g_flags_guess->coinOnCursor_11_guess = 0;
                return;
            }

            int item_guess;
            {
                CXStr name_guess("A_DragItem");
                item_guess = g_itemManager_guess->Find_guess(&name_guess);
            }
            source_16c_guess->animation_64_guess->Apply_guess(item_guess);
            source_16c_guess->animation_64_guess->SetIndex_guess(
                g_flags_guess->coinOnCursor_11_guess + 0x8f);
            active_18_guess = 0;
        } else if (kind_guess == 2) {
            CharInfo_guess* info_guess = ((CharBase_guess*)g_pcView_guess2)
                ->profile_guess.GetCharInfo2();
            if (info_guess->sub_10_guess.field_78_guess == 0) {
                return;
            }
            int item_guess;
            {
                CXStr name_guess("A_DragItem");
                item_guess = g_itemManager_guess->Find_guess(&name_guess);
            }
            source_16c_guess->animation_64_guess->Apply_guess(item_guess);
            info_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                .GetCharInfo2();
            ItemState_guess* state_guess = (ItemState_guess*)
                info_guess->sub_10_guess.field_78_guess;
            int timer_guess = state_guess->Timer_guess();
            if (timer_guess - 500 >= 0) {
                source_16c_guess->animation_64_guess->SetIndex_guess(timer_guess - 500);
                info_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                    .GetCharInfo2();
                state_guess = (ItemState_guess*)info_guess->sub_10_guess.field_78_guess;
                if (state_guess->GetItemClass_guess() == 0) {
                    info_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                        .GetCharInfo2();
                    state_guess = (ItemState_guess*)info_guess->sub_10_guess.field_78_guess;
                    if (state_guess->IsStackable_guess() != 0) {
                        info_guess = ((CharBase_guess*)g_pcView_guess2)->profile_guess
                            .GetCharInfo2();
                        fifth_guess = ((ItemState_guess*)info_guess->sub_10_guess.field_78_guess)
                            ->value_48_guess;
                    }
                }
                active_18_guess = 0;
            } else {
                return;
            }
        // Kinds 4, 12 and 13 (with their label) and kinds 5-7 and 11 draw the plain A_SquareBtnNormal
        // button.
        } else if (kind_guess == 12 || kind_guess == 13 || kind_guess == 4) {
            int item_guess;
            {
                CXStr name_guess("A_SquareBtnNormal");
                item_guess = g_itemManager_guess->Find_guess(&name_guess);
            }
            source_16c_guess->animation_64_guess->Apply_guess(item_guess);
        } else if ((kind_guess > 4 && kind_guess < 8) || kind_guess == 11) {
            int item_guess;
            {
                CXStr name_guess("A_SquareBtnNormal");
                item_guess = g_itemManager_guess->Find_guess(&name_guess);
            }
            source_16c_guess->animation_64_guess->Apply_guess(item_guess);
        // Kind 8: icon `first_guess` as given.
        } else if (kind_guess == 8) {
            if (first_guess != 0) {
                source_16c_guess->animation_64_guess->Apply_guess(first_guess);
            }
            if (state_170_guess != 0 && state_170_guess->animation_64_guess != 0) {
                int item_guess = ((CharBase_guess*)g_pcView_guess2)
                    ->GetInventorySlot_guess(third_guess);
                if (item_guess != 0) {
                    int item_name_guess;
                    {
                        CXStr name_guess("A_DragItem");
                        item_name_guess = g_itemManager_guess->Find_guess(&name_guess);
                    }
                    state_170_guess->animation_64_guess->Apply_guess(item_name_guess);
                    int timer_item_guess = ((CharBase_guess*)g_pcView_guess2)
                        ->GetInventorySlot_guess(third_guess);
                    int timer_guess = ((ItemState_guess*)timer_item_guess)->Timer_guess();
                    if (timer_guess - 500 >= 0) {
                        state_170_guess->animation_64_guess->SetIndex_guess(timer_guess - 500);
                        kind_015c_guess = kind_guess;
                        value_0160_guess = third_guess;
                        count_0164_guess = fifth_guess;
                        SetState_guess(1);
                        pos_guess.x_guess = g_slotPos_guess->x_74_guess + 1;
                        pos_guess.y_guess = g_slotPos_guess->y_78_guess + 1;
                        Move_guess(&pos_guess);
                        Slot48_guess(1, 1);
                        return;
                    } else {
                        return;
                    }
                } else {
                    state_170_guess->animation_64_guess->Apply_guess(
                        (int)source_16c_guess->animation_64_guess);
                }
            }
        } else if (kind_guess == 9) {
            int item_index_guess = ((CharBase_guess*)g_pcView_guess2)
                ->GetMemorizedSpell_guess(third_guess);
            int color_guess = -1;
            int alpha_guess = 0xff000000;
            if (IsValidSpellIndex_guess(item_index_guess) != 0) {
                ItemRecord_guess* record_guess = g_itemCatalog_guess->Find_guess(
                    ((CharBase_guess*)g_pcView_guess2)->GetMemorizedSpell_guess(third_guess));
                color_guess = record_guess->icon_0248_guess;
                alpha_guess = record_guess->GetSpellColor_guess();
            }
            if (child_174_guess != 0) {
                child_174_guess->SetSpellIcon_guess(color_guess);
                child_174_guess->SetSpellGemTint_guess(alpha_guess);
                child_174_guess->Slot48_guess(1, 1);
            }
            source_16c_guess->animation_64_guess->Reset_guess();
        } else if (kind_guess == 10) {
            int item_guess;
            {
                CXStr name_guess("A_SquareBtnNormal");
                item_guess = g_itemManager_guess->Find_guess(&name_guess);
            }
            source_16c_guess->animation_64_guess->Apply_guess(item_guess);
            fourth_guess = 0;
        } else {
            return;
        }

        if (state_170_guess != 0 && state_170_guess->animation_64_guess != 0 &&
            kind_guess != 8) {
            state_170_guess->animation_64_guess->Apply_guess(
                (int)source_16c_guess->animation_64_guess);
        }
    }
    kind_015c_guess = kind_guess;
    value_0160_guess = third_guess;
    count_0164_guess = fifth_guess;
    SetState_guess(1);
    pos_guess.x_guess = g_slotPos_guess->x_74_guess + 1;
    pos_guess.y_guess = g_slotPos_guess->y_78_guess + 1;
    Move_guess(&pos_guess);
    Slot48_guess(1, 1);
}

// OnProcessFrame: follows the mouse and drops coins or an item once they leave the cursor. In game (state
// 5) with nothing shown, an item or coins on the cursor attach themselves (kinds 2 and 3).
// FUNCTION: TITANIUM 0x004FDF33
void Gate_guess::OnProcessFrame_guess() {
    if (Ready_guess() != 0) {
        if ((kind_015c_guess == 3 && g_flags_guess->coinOnCursor_11_guess == 0) ||
            (kind_015c_guess == 2 && g_flags_guess->itemOnCursor_10_guess == 0)) {
            Slot34_guess();
        } else {
            Pos_guess pos_guess;
            pos_guess.x_guess = g_slotPos_guess->x_74_guess;
            int y_guess = g_slotPos_guess->y_78_guess;
            pos_guess.x_guess++;
            pos_guess.y_guess = y_guess + 1;
            Move_guess(&pos_guess);
        }
    } else if (g_everQuest_guess->state_b54_guess == 5) {
        if (g_flags_guess->coinOnCursor_11_guess != 0) {
            Post_guess(0, 3, -1, 0, -1);
        } else if (g_flags_guess->itemOnCursor_10_guess != 0 ||
                   (g_pcView_guess2 != 0 &&
                    ((CharBase_guess*)g_pcView_guess2)->profile_guess.GetCharInfo2()->sub_10_guess.Field78_guess() != 0)) {
            Post_guess(0, 2, -1, 0, -1);
            g_flags_guess->itemOnCursor_10_guess = 1;
        }
    }
    OnProcessFrame();
}

