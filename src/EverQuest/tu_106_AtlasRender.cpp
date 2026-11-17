// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 106: a hint from compare/tumap.py.
// The map window's atlas page renderer (MVW_AtlasRenderArea, tu_187): loads an Atlas folder XML page
// (Background, Image, Label, Link, Rect) into child windows; errors go to chat and AtlasPageError.txt.
// AtlasRender_guess is that renderer (tu_187 AtlasRender_guess), AtlasLink_guess a Link button,
// Owner_guess its CXWnd view; Quad_guess is a rect (left, top, right, bottom).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <stdio.h>

// EXTERNAL: TITANIUM 0x0060E887 fopen
// EXTERNAL: TITANIUM 0x0060EC45 fprintf
// EXTERNAL: TITANIUM 0x0060E790 fclose

struct Quad_guess {
    unsigned int field_0_guess;
    unsigned int field_4_guess;
    unsigned int field_8_guess;
    unsigned int field_C_guess;
    Quad_guess() {}
    Quad_guess(const Quad_guess& source_guess) {
        field_0_guess = source_guess.field_0_guess;
        field_4_guess = source_guess.field_4_guess;
        field_8_guess = source_guess.field_8_guess;
        field_C_guess = source_guess.field_C_guess;
    }
    Quad_guess* Copy_guess(Quad_guess* source);
    Quad_guess* AddTo_guess(Quad_guess* source, Quad_guess* addend);
    void Add_guess(Quad_guess* source, Quad_guess* addend);
    Quad_guess* CopyTo_guess(Quad_guess* destination, Quad_guess* source);
    bool IsInverted_guess();
};

struct TextHandle_guess;

struct Offset184_guess {
    unsigned int value_guess;
    Offset184_guess() : value_guess(0) {}
    operator const TextHandle_guess&() const;
    // EXTERNAL: TITANIUM 0x00407D68 ??0Offset184_guess@@QAE@ABU0@@Z
    Offset184_guess(const Offset184_guess& source);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Offset184_guess@@QAE@PBD@Z
    Offset184_guess(const char* source);
    // EXTERNAL: TITANIUM 0x00572E00 Offset184_guess::Append_guess
    void Append_guess(const char* source_guess);
    // EXTERNAL: TITANIUM 0x00572C10 Offset184_guess::AppendText_guess
    void AppendText_guess(const Offset184_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00572300 ??BOffset184_guess@@QBEPADXZ
    operator char*() const;
    int Length_guess() const {
        return value_guess != 0 ? ((CStrRep*)value_guess)->length : 0;
    }
    // EXTERNAL: TITANIUM 0x00571D00 Offset184_guess::FreeRep
    void FreeRep(unsigned int value_guess);
    ~Offset184_guess() {
        if (value_guess != 0) {
            FreeRep(value_guess);
        }
        value_guess = 0;
    }
};

// String + string as a new string.
// FUNCTION: TITANIUM 0x004D9090
Offset184_guess FUN_004d9090_guess(const Offset184_guess& source_guess,
                                   const Offset184_guess& text_guess) {
    Offset184_guess local_guess(source_guess);
    local_guess.AppendText_guess(text_guess);
    return local_guess;
}

// EXTERNAL: TITANIUM 0x0042E3D9 FUN_0042e3d9_guess
Offset184_guess FUN_0042e3d9_guess(const char* prefix_guess,
                                   const Offset184_guess& text_guess);

// EXTERNAL: TITANIUM 0x004B1357 FUN_004b1357_guess
Offset184_guess FUN_004b1357_guess(const Offset184_guess& text_guess,
                                   const char* suffix_guess);

// Rect from a point (`source`) and a size (`addend`); AddTo_guess and Add_guess are the same code.
// FUNCTION: TITANIUM 0x004D90F1
Quad_guess* Quad_guess::AddTo_guess(Quad_guess* source, Quad_guess* addend) {
    field_0_guess = source->field_0_guess;
    field_4_guess = source->field_4_guess;
    field_8_guess = source->field_0_guess + addend->field_0_guess;
    field_C_guess = addend->field_4_guess + source->field_4_guess;
    return this;
}

// Rect assignment: copies left, top, right and bottom from `source` and returns this. Shared by many
// callers (SIDL control builders, gauge fills, map labels, the chase camera).
// FUNCTION: TITANIUM 0x004D911A
Quad_guess* Quad_guess::Copy_guess(Quad_guess* source) {
    field_0_guess = source->field_0_guess;
    field_4_guess = source->field_4_guess;
    field_8_guess = source->field_8_guess;
    field_C_guess = source->field_C_guess;
    return this;
}

// Builds a rect from an origin and a size: left/top from `source`, right = left + `addend`'s first
// value, bottom = top + its second. Used by the buff window size query and several draw routines.
// FUNCTION: TITANIUM 0x004D9139
void Quad_guess::Add_guess(Quad_guess* source, Quad_guess* addend) {
    field_0_guess = source->field_0_guess;
    field_4_guess = source->field_4_guess;
    field_8_guess = source->field_0_guess + addend->field_0_guess;
    field_C_guess = addend->field_4_guess + source->field_4_guess;
}

// Copies `source` into this and into `destination`; returns `destination`.
// FUNCTION: TITANIUM 0x004D9160
Quad_guess* Quad_guess::CopyTo_guess(Quad_guess* destination, Quad_guess* source) {
    field_0_guess = source->field_0_guess;
    field_4_guess = source->field_4_guess;
    field_8_guess = source->field_8_guess;
    field_C_guess = source->field_C_guess;
    destination->Copy_guess(this);
    return destination;
}

// True when the rect is inverted (left > right or top > bottom): the error value of ParseRect_guess.
// FUNCTION: TITANIUM 0x004D918B
bool Quad_guess::IsInverted_guess() {
    return (int)field_0_guess > (int)field_8_guess ||
        (int)field_4_guess > (int)field_C_guess;
}

struct TextHandle_guess {
    int value_guess;
    TextHandle_guess() : value_guess(0) {}
    operator const Offset184_guess&() const;
    // EXTERNAL: TITANIUM 0x00571F70 TextHandle_guess::Assign_guess
    void Assign_guess(const TextHandle_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004482FB TextHandle_guess::~TextHandle_guess
    ~TextHandle_guess();
};

inline TextHandle_guess::operator const Offset184_guess&() const {
    return *(const Offset184_guess*)this;
}

inline Offset184_guess::operator const TextHandle_guess&() const {
    return *(const TextHandle_guess*)this;
}

struct XMLElement_guess;

struct DocHeader_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_c_guess;
    int field_10_guess;
    int field_14_guess;
    int field_18_guess;
    int field_1c_guess;
    int field_20_guess;
    int field_24_guess;
    int field_28_guess;
    int field_2c_guess;
    int field_30_guess;
};

struct DocTail_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_c_guess;
};

struct XMLDoc_guess {
    DocHeader_guess header_guess;
    unsigned char errorFlag_guess;
    unsigned char unknown_35_guess;
    unsigned char unknown_36_guess;
    unsigned char unknown_37_guess;
    unsigned char unknown_38_guess;
    unsigned char unknown_39_guess;
    unsigned char unknown_3a_guess;
    unsigned char unknown_3b_guess;
    char* errorText_guess;
    int errorLength_guess;
    DocTail_guess tail_guess;
    // EXTERNAL: TITANIUM 0x005DCEB0 ??0XMLDoc_guess@@QAE@PBD@Z
    XMLDoc_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x005DDC40 XMLDoc_guess::Parse_guess
    void Parse_guess();
    // EXTERNAL: TITANIUM 0x005DCB60 XMLDoc_guess::FindElement_guess
    XMLElement_guess* FindElement_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004C9C05 ??1XMLDoc_guess@@QAE@XZ
    ~XMLDoc_guess();
    const char* GetError_guess() const {
        char* text_guess = errorText_guess;
        if (errorLength_guess == 0) {
            text_guess = EQ_ARRAY(char, 0x0063F53F);
        }
        return text_guess;
    }
};

struct XMLElement_guess {
    // EXTERNAL: TITANIUM 0x005DD9F0 XMLElement_guess::GetAttribute_guess
    const char* GetAttribute_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x005DDA20 XMLElement_guess::GetIntAttribute_guess
    int GetIntAttribute_guess(const char* name_guess, int* value_guess);
    // EXTERNAL: TITANIUM 0x005DCBA0 XMLElement_guess::FindNext_guess
    XMLElement_guess* FindNext_guess(const char* name_guess);
};

struct PointValue_guess {
    int x_guess;
    int y_guess;
};

struct TextCharField_guess {
    int value_guess;
    TextCharField_guess() : value_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571FC0 TextCharField_guess::Assign_guess
    void Assign_guess(const char* source_guess);
    // EXTERNAL: TITANIUM 0x00571F70 TextCharField_guess::AssignHandle_guess
    void AssignHandle_guess(const Offset184_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004482FB TextCharField_guess::~TextCharField_guess
    ~TextCharField_guess();
};

struct TextureInfo_guess {
    unsigned char valid_guess;
    unsigned char pad_1_guess;
    unsigned char pad_2_guess;
    unsigned char pad_3_guess;
    int field_4_guess;
    TextHandle_guess text_8_guess;
    int field_c_guess;
    int field_10_guess;
    int field_14_guess;
    TextureInfo_guess(const TextHandle_guess& text_guess,
                      const PointValue_guess* point_guess);
};

// Texture info: name `text_guess`, size `point_guess`, valid, texture id (+0x14) -1 until loaded.
// FUNCTION: TITANIUM 0x004D91A1
TextureInfo_guess::TextureInfo_guess(const TextHandle_guess& text_guess,
                                     const PointValue_guess* point_guess) {
    field_4_guess = 0;
    valid_guess = 1;
    text_8_guess.Assign_guess(text_guess);
    field_c_guess = point_guess->x_guess;
    field_10_guess = point_guess->y_guess;
    field_14_guess = -1;
}

struct Offset8_guess {
    // EXTERNAL: TITANIUM 0x004482FB Offset8_guess::Call_guess
    void Call_guess();
};

struct Owner8_guess {
    char unknown_0[8];
    Offset8_guess offset_8;
    void Forward_guess();
};

struct Renderer_guess {
    // EXTERNAL: TITANIUM 0x005BD430 Renderer_guess::Render_guess
    void Render_guess(void* buffer, Quad_guess* source, Quad_guess* color);
};

struct Cursor_guess;

struct ValuePair_guess {
    int first_guess;
    int second_guess;
};

struct GlobalPair_guess {
    char unknown_0[0x74];
    ValuePair_guess pair_74_guess;
};

#define g_global_pair_guess EQ_GLOBAL(GlobalPair_guess**, 0x0099D334)

// EXTERNAL: TITANIUM 0x0050F3F6 FUN_0050f3f6_guess
extern "C" void __fastcall FUN_0050f3f6_guess(unsigned int* param_1);

struct Owner184_guess;

struct Label_guess;

struct Entry184_guess {
    Owner184_guess* owner_guess;
};

struct Lookup184_guess {
    unsigned int count_0000_guess;
    void* data_4_guess;
    void* extra_8_guess;
    unsigned char valid_c_guess;
    char pad_d_guess[3];
    Lookup184_guess() {
        data_4_guess = 0;
        count_0000_guess = 0;
        extra_8_guess = 0;
        valid_c_guess = 1;
    }
    ~Lookup184_guess() {
        FUN_0050f3f6_guess((unsigned int*)this);
    }
    // EXTERNAL: TITANIUM 0x004EB924 Lookup184_guess::Lookup_guess
    Entry184_guess* Lookup_guess(int index);
    // EXTERNAL: TITANIUM 0x0050319B Lookup184_guess::Set_guess
    void Set_guess(int count_guess, Label_guess** value_guess);
};

struct Owner_guess {
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
    virtual Quad_guess* GetQuad_guess(Quad_guess* buffer) = 0;

    char unknown_4_guess[0x5e];
    unsigned char flags_64_guess;
    char unknown_63_guess[1];
    unsigned char flags_64_extra_guess;
    char unknown_65_guess[0x1b];
    unsigned int field_80_guess;
    char unknown_84_guess[0x84];
    int field_108_guess;
    int field_10c_guess;
    int field_110_guess;
    int field_114_guess;
    char unknown_118_guess[0x24];
    Lookup184_guess lookup_13c_guess;
    Renderer_guess renderer_14c_guess;

    // EXTERNAL: TITANIUM 0x0059D110 Owner_guess::Begin_guess
    Cursor_guess* Begin_guess();
    int DrawBackground_guess();
    void UpdateVScrollRange_guess();
    int Refresh_guess();
    void UpdateHScrollRange_guess();
    int Step_guess(int, int);
    int DrawAnimations_guess();
    // EXTERNAL: TITANIUM 0x005BB2B0 Owner_guess::GetResult_guess
    int GetResult_guess();
    // EXTERNAL: TITANIUM 0x005A02F0 Owner_guess::ApplyPair_guess
    void ApplyPair_guess(ValuePair_guess* values);
};

struct Frame941c_guess {
    Quad_guess local_4c_guess;
    Quad_guess local_3c_guess;
    Quad_guess local_2c_guess;
    Quad_guess local_1c_guess;
    Cursor_guess* local_c_guess;
    int local_8_guess;
};

struct RectProvider_guess {
    // EXTERNAL: TITANIUM 0x0059D6C0 RectProvider_guess::GetClientClipRect
    Quad_guess* GetClientClipRect(Quad_guess* buffer);
};

// EXTERNAL: TITANIUM 0x0059D6C0 FUN_0059d6c0_guess
void __stdcall FUN_0059d6c0_guess(void* buffer);

struct Cursor_guess {
    // EXTERNAL: TITANIUM 0x0059D860 Cursor_guess::GetQuad_guess
    Quad_guess* GetQuad_guess(Quad_guess* buffer);
    // EXTERNAL: TITANIUM 0x0059D130 Cursor_guess::Next_guess
    Cursor_guess* Next_guess();
};

// 8-byte extent passed by value.
struct Extent_guess {
    int width_guess;
    int height_guess;
    Extent_guess() : width_guess(0), height_guess(0) {}
};

// A 0x28-byte texture frame built from a NamedObject.
struct TextureFrame_guess {
    TextureInfo_guess object_guess;   // 0x00
    CXStr text_guess;                 // 0x18
    int field_1c_guess;               // 0x1c
    int field_20_guess;               // 0x20
    int field_24_guess;               // 0x24
    // EXTERNAL: TITANIUM 0x004D95E7 TextureFrame_guess::TextureFrame_guess
    TextureFrame_guess(const TextureInfo_guess& source_guess);
};

// CTextureAnimation (0x4C bytes, ctor 0x005B1D90).
struct TextureAnimation_guess {
    char data_guess[0x4c];
    // EXTERNAL: TITANIUM 0x005B1910 TextureAnimation_guess::Draw_guess
    void Draw_guess(Quad_guess* bounds, Quad_guess* source, int frame,
                    unsigned int color);
    // EXTERNAL: TITANIUM 0x005B1D90 ??0TextureAnimation_guess@@QAE@XZ
    TextureAnimation_guess();
    // EXTERNAL: TITANIUM 0x005B1F60 TextureAnimation_guess::AddFrame_guess
    void AddFrame_guess(TextureFrame_guess frame_guess, int value_guess,
                        Extent_guess extent_guess);
};

struct Owner184_guess {
    char unknown_0[0x48];
    Quad_guess rect_48_guess;
    char unknown_58[0xc];
    TextureAnimation_guess* animation_64_guess;
    char unknown_68[0x118];
    int field_180_guess;
    Offset184_guess field_184;
    Offset184_guess GetFileToOpen_guess();
};

// Texture-info teardown: releases the name string at +8 (0x4482FB is the string destructor).
// FUNCTION: TITANIUM 0x004D91ED
void Owner8_guess::Forward_guess() {
    offset_8.Call_guess();
}

// The link's FileToOpen (+0x184).
// FUNCTION: TITANIUM 0x004D91F5
Offset184_guess Owner184_guess::GetFileToOpen_guess() {
    return field_184;
}

// Base step (0x5BB2B0); when +0x62 is set, also hands it the pair at window manager 0x99D334 +0x74
// (probably the mouse position).
// FUNCTION: TITANIUM 0x004D9213
int Owner_guess::Refresh_guess() {
    ValuePair_guess values_guess;
    int result_guess = GetResult_guess();

    if (flags_64_guess != 0) {
        GlobalPair_guess* pair_guess = *g_global_pair_guess;
        ValuePair_guess* source_guess = &pair_guess->pair_74_guess;
        values_guess.first_guess = source_guess->first_guess;
        values_guess.second_guess = source_guess->second_guess;
        ApplyPair_guess(&values_guess);
    }
    return result_guess;
}

// Draws the window rect in the background colour (+0x80) with black (0xFF000000) as the second colour;
// probably fill and frame.
// FUNCTION: TITANIUM 0x004D93CB
int Owner_guess::DrawBackground_guess() {
    struct Locals_guess {
        Quad_guess local_34_guess;
        Quad_guess local_24_guess;
        Quad_guess local_14_guess;
    } local_guess;
    unsigned int value_guess;

    FUN_0059d6c0_guess(&local_guess.local_34_guess);
    local_guess.local_14_guess.field_0_guess = 0xff000000;
    local_guess.local_14_guess.field_4_guess = 0xff000000;
    local_guess.local_14_guess.field_8_guess = 0xff000000;
    local_guess.local_14_guess.field_C_guess = 0xff000000;
    value_guess = field_80_guess;
    local_guess.local_24_guess.field_0_guess = value_guess;
    local_guess.local_24_guess.field_4_guess = value_guess;
    local_guess.local_24_guess.field_8_guess = value_guess;
    local_guess.local_24_guess.field_C_guess = value_guess;
    renderer_14c_guess.Render_guess(&local_guess.local_34_guess,
                                    &local_guess.local_24_guess,
                                    &local_guess.local_14_guess);
    return 0;
}

// Vertical scroll range: when the children reach below the client rect, +0x108 becomes the overflow
// plus 5 pixels and +0x10C (the position) is clamped to it; otherwise both are 0. Only with style
// bit 0 of +0x64 (probably vertical scroll).
// FUNCTION: TITANIUM 0x004D941C
// @early-stop: budget, diff ndiff=4
void Owner_guess::UpdateVScrollRange_guess() {
    if ((flags_64_extra_guess & 1) != 0) {
        Frame941c_guess local_guess;
        Quad_guess* metric_guess;
        int delta_guess;

        local_guess.local_1c_guess.field_C_guess = 0;
        local_guess.local_1c_guess.field_8_guess = 0;
        local_guess.local_1c_guess.field_4_guess = 0;
        local_guess.local_1c_guess.field_0_guess = 0;
        local_guess.local_2c_guess.field_C_guess = 0;
        local_guess.local_2c_guess.field_8_guess = 0;
        local_guess.local_2c_guess.field_4_guess = 0;
        local_guess.local_2c_guess.field_0_guess = 0;
        metric_guess = GetQuad_guess(&local_guess.local_3c_guess);
        local_guess.local_1c_guess.CopyTo_guess(&local_guess.local_4c_guess,
                                                metric_guess);
        delta_guess = (int)local_guess.local_1c_guess.field_C_guess -
                      (int)local_guess.local_1c_guess.field_4_guess;
        local_guess.local_8_guess = delta_guess;
        local_guess.local_c_guess = Begin_guess();
        while (local_guess.local_c_guess != 0) {
            metric_guess = local_guess.local_c_guess->GetQuad_guess(
                &local_guess.local_4c_guess);
            local_guess.local_2c_guess.CopyTo_guess(
                &local_guess.local_3c_guess, metric_guess);
            if ((int)local_guess.local_2c_guess.field_C_guess >
                local_guess.local_8_guess) {
                local_guess.local_8_guess =
                    local_guess.local_2c_guess.field_C_guess;
            }
            local_guess.local_c_guess = local_guess.local_c_guess->Next_guess();
        }
        if (local_guess.local_8_guess <= delta_guess) {
            field_10c_guess = 0;
            field_108_guess = 0;
        } else {
            metric_guess = GetQuad_guess(&local_guess.local_4c_guess);
            local_guess.local_8_guess =
                (int)metric_guess->field_4_guess -
                (int)metric_guess->field_C_guess +
                local_guess.local_8_guess + 5;
            field_108_guess = local_guess.local_8_guess;
            if (field_10c_guess > local_guess.local_8_guess) {
                field_10c_guess = field_108_guess;
            }
        }
    }
}

// Horizontal twin of UpdateVScrollRange_guess: +0x110 range, +0x114 position, style bit 1.
// FUNCTION: TITANIUM 0x004D94F0
// @early-stop: budget, structural ndiff=99
void Owner_guess::UpdateHScrollRange_guess() {
    if ((flags_64_extra_guess & 2) != 0) {
        struct Frame_guess {
            Quad_guess temporary_44_guess;
            Quad_guess output_34_guess;
            Quad_guess iterator_24_guess;
            Quad_guess initial_14_guess;
            Cursor_guess* cursor_4_guess;
        } local_guess;
        int maximum_guess;
        int delta_guess;

        local_guess.initial_14_guess.field_C_guess = 0;
        local_guess.initial_14_guess.field_8_guess = 0;
        local_guess.initial_14_guess.field_4_guess = 0;
        local_guess.initial_14_guess.field_0_guess = 0;
        local_guess.iterator_24_guess.field_C_guess = 0;
        local_guess.iterator_24_guess.field_8_guess = 0;
        local_guess.iterator_24_guess.field_4_guess = 0;
        local_guess.iterator_24_guess.field_0_guess = 0;
        Quad_guess* initial_metric_guess =
            GetQuad_guess(&local_guess.output_34_guess);
        local_guess.initial_14_guess.CopyTo_guess(
            &local_guess.temporary_44_guess, initial_metric_guess);
        delta_guess = (int)local_guess.initial_14_guess.field_8_guess -
                      (int)local_guess.initial_14_guess.field_0_guess;
        maximum_guess = delta_guess;
        local_guess.cursor_4_guess = Begin_guess();
        if (local_guess.cursor_4_guess != 0) {
            do {
                local_guess.iterator_24_guess.CopyTo_guess(
                    &local_guess.output_34_guess,
                    local_guess.cursor_4_guess->GetQuad_guess(
                        &local_guess.temporary_44_guess));
                if ((int)local_guess.iterator_24_guess.field_8_guess >
                    maximum_guess) {
                    maximum_guess =
                        (int)local_guess.iterator_24_guess.field_8_guess;
                }
            } while ((local_guess.cursor_4_guess =
                          local_guess.cursor_4_guess->Next_guess()) != 0);
        }
        if (maximum_guess <= delta_guess) {
            field_114_guess &= (int)local_guess.cursor_4_guess;
            field_110_guess &= (int)local_guess.cursor_4_guess;
        } else {
            Quad_guess* metric_guess =
                GetQuad_guess(&local_guess.temporary_44_guess);
            int value_guess = maximum_guess -
                             (int)metric_guess->field_8_guess + 5 +
                             (int)metric_guess->field_0_guess;
            field_110_guess = value_guess;
            if (field_114_guess > value_guess) {
                field_114_guess = value_guess;
            }
        }
    }
}

// Recomputes both scroll ranges.
// FUNCTION: TITANIUM 0x004D95BB
int Owner_guess::Step_guess(int, int) {
    UpdateHScrollRange_guess();
    UpdateVScrollRange_guess();
    return 0;
}

struct Ref8_guess {
    char unknown_0[8];
    unsigned int field_8_guess;
};

struct RefHolder_guess {
    Ref8_guess* target_guess;
    bool IsEmpty_guess();
};

struct Slot4Object_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value_guess);
};

struct Slot0Object_guess {
    virtual void Slot00_guess(int value_guess);
};

struct Slot0FieldObject_guess {
    virtual void Slot00_guess(int value_guess);
    char unknown_4_guess[0x60];
    Slot0Object_guess* field_64_guess;
};

// EXTERNAL: TITANIUM 0x005A0940 ??1CleanupBase_guess@@UAE@XZ
struct CleanupBase_guess {
    // EXTERNAL: TITANIUM 0x005A1290 CleanupBase_guess::CleanupBase_guess
    CleanupBase_guess(int first_guess, int second_guess, Quad_guess rect_guess);
    virtual ~CleanupBase_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CleanupBase_guess::OnProcessFrame
    void OnProcessFrame();
};

// EXTERNAL: TITANIUM 0x0064F178 ??_7AtlasRender_guess@@6B@
struct AtlasRender_guess : CleanupBase_guess {
    char unknown_0_guess[0x24];
    RectProvider_guess* field_28_guess;
    char unknown_2c_guess[8];
    unsigned char flag_34_guess;
    char unknown_35_guess[7];
    Quad_guess field_3c_guess;
    char unknown_4c_guess[0x18];
    unsigned int field_64_guess;
    char unknown_68_guess[0x44];
    unsigned char flag_ac_guess;
    unsigned char flag_ad_guess;
    unsigned char flag_ae_guess;
    unsigned char flag_af_guess;
    char unknown_b0_guess[0x6c];
    Lookup184_guess lookup_11c_guess;
    Lookup184_guess lookup_12c_guess;
    Lookup184_guess lookup_13c_guess;
    unsigned char flag_14c_guess;
    char unknown_14d_guess[3];
    int field_150_guess;
    TextCharField_guess text_154_guess;
    int field_158_guess;
    int field_15c_guess;
    int field_160_guess;
    TextHandle_guess text_164_guess;
    int pickedIndex_0168_guess;
    AtlasRender_guess(int first_guess, int second_guess,
                       Quad_guess rect_guess);
    virtual ~AtlasRender_guess();
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
    virtual void SetSize_guess(int width_guess, int height_guess);
    AtlasRender_guess* Destroy_guess(unsigned char flags_guess);
    void Clear_guess();
    int OnLinkClicked_guess(Owner184_guess* owner_guess, int mode_guess, int arg_guess);
    bool SetFile_guess(TextHandle_guess* text_guess);
    // EXTERNAL: TITANIUM 0x004D9F03 AtlasRender_guess::ParseImage_guess
    Offset184_guess ParseImage_guess(XMLElement_guess* element_guess);
    // EXTERNAL: TITANIUM 0x004D9C7A AtlasRender_guess::ParseLabel_guess
    Offset184_guess ParseLabel_guess(XMLElement_guess* element_guess);
    CXStr ParseLink_guess(XMLElement_guess* element_guess);
    Quad_guess* ParseRect_guess(Quad_guess* bounds_guess, const void* image_guess,
                                void* message_guess);
    void Refresh_guess();
};

struct GlobalReset_guess {
    // EXTERNAL: TITANIUM 0x005ADF40 GlobalReset_guess::Reset_guess
    void Reset_guess();
};

struct GlobalAction_guess {
    // EXTERNAL: TITANIUM 0x0060C0C0 GlobalAction_guess::GetString_guess
    const Offset184_guess& GetString_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0060C310 GlobalAction_guess::Apply_guess
    void Apply_guess(int value_guess);
};

#define g_cleanup_reset_guess EQ_GLOBAL(GlobalReset_guess*, 0x0099D3EC)
#define g_cleanup_action_guess EQ_ARRAY(GlobalAction_guess, 0x0099E414)

struct IndexedOwner_guess {
    char unknown_0[0x11c];
    Lookup184_guess lookup_11c_guess;
    char unknown_120[0x3c];
    int index_168_guess;
    Offset184_guess GetClickedLinkFile_guess();
};

// Reads X, Y, CX, CY into {left, top, right, bottom}. A missing or non-integer attribute is added to `message_guess`
// as "Rect(<names>)" and the inverted rect (1, 1, -1, -1) is returned instead.
// FUNCTION: TITANIUM 0x004D924F
// @early-stop: budget, structural ndiff=26
Quad_guess* AtlasRender_guess::ParseRect_guess(Quad_guess* bounds_guess,
                                                const void* xmlElement_guess,
                                                void* message_guess) {
    int x_guess;
    int y_guess;
    int cx_guess;
    int cy_guess;
    bool valid_guess = true;
    Offset184_guess error_guess;
    XMLElement_guess* element_guess = (XMLElement_guess*)xmlElement_guess;

    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x0064EEC8),
                                              &cx_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEC4));
        valid_guess = false;
    }
    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x0064EEC0),
                                              &cy_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEBC));
        valid_guess = false;
    }
    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x00646EA8),
                                              &x_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEB8));
        valid_guess = false;
    }
    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x00646EA4),
                                              &y_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEB4));
        valid_guess = false;
    }
    if (valid_guess) {
        int left_guess = x_guess;
        int width_guess = cx_guess;
        int top_guess = y_guess;
        int height_guess = cy_guess;
        bounds_guess->field_0_guess = left_guess;
        bounds_guess->field_4_guess = top_guess;
        bounds_guess->field_8_guess = left_guess + width_guess;
        bounds_guess->field_C_guess = height_guess + top_guess;
        return bounds_guess;
    }
    ((Offset184_guess*)message_guess)->AppendText_guess(
        FUN_004b1357_guess(FUN_0042e3d9_guess("Rect(", error_guess),
                           EQ_ARRAY(char, 0x00641098)));
    bounds_guess->field_8_guess = (unsigned int)-1;
    bounds_guess->field_C_guess = (unsigned int)-1;
    bounds_guess->field_0_guess = 1;
    bounds_guess->field_4_guess = 1;
    return bounds_guess;
}

// True when the string is empty (rep +8 is the length).
// FUNCTION: TITANIUM 0x004D95D0
bool RefHolder_guess::IsEmpty_guess() {
    Ref8_guess* target = target_guess;
    return (target != 0 ? target->field_8_guess : 0) == 0;
}

struct TextureFrameView_guess {
    unsigned char field_0_guess;
    char pad_1_guess[3];
    int field_4_guess;
    TextHandle_guess text_8_guess;
    PointValue_guess field_C_guess;
    int field_14_guess;
    Quad_guess field_18_guess;
    // EXTERNAL: TITANIUM 0x00435A54 TextureFrameView_guess::Set_guess
    void Set_guess(int value_guess);
    TextureFrameView_guess(int value_guess);
};

// Animation frame from a texture info: copies it and takes the whole texture (0, 0, size) as the
// source rect. External elsewhere as TextureFrame_guess::TextureFrame_guess.
// FUNCTION: TITANIUM 0x004D95E7
// @early-stop: budget, diff ndiff=8
TextureFrameView_guess::TextureFrameView_guess(int value_guess) {
    Quad_guess* state_guess = &field_18_guess;
    field_14_guess = -1;
    field_4_guess = 0;
    field_0_guess = 0;
    state_guess->field_C_guess = 0;
    state_guess->field_8_guess = 0;
    state_guess->field_4_guess = 0;
    state_guess->field_0_guess = 0;
    Set_guess(value_guess);
    field_14_guess = -1;

    PointValue_guess origin_guess;
    Quad_guess result_guess;
    Quad_guess destination_guess;
    origin_guess.x_guess = 0;
    origin_guess.y_guess = 0;
    state_guess->CopyTo_guess(&destination_guess,
        result_guess.AddTo_guess((Quad_guess*)&origin_guess,
                                 (Quad_guess*)&field_C_guess));
}

// Empties the page: deletes the links (+0x11C), the images with their animations (+0x13C) and the
// labels (+0x12C), drops the background and the clicked link, and resizes the page to the parent.
// FUNCTION: TITANIUM 0x004D965C
void AtlasRender_guess::Clear_guess() {
    int index_guess;

    g_cleanup_reset_guess->Reset_guess();
    int zero_guess = 0;
    flag_34_guess = (unsigned char)zero_guess;
    index_guess = zero_guess;
    for (; index_guess < (int)lookup_11c_guess.count_0000_guess;
         ++index_guess) {
        Entry184_guess* entry_guess = lookup_11c_guess.Lookup_guess(index_guess);
        if (entry_guess->owner_guess != 0) {
            ((Slot4Object_guess*)entry_guess->owner_guess)->Slot01_guess(1);
        }
    }
    FUN_0050f3f6_guess((unsigned int*)&lookup_11c_guess);

    index_guess = 0;
    for (; index_guess < (int)lookup_13c_guess.count_0000_guess; ++index_guess) {
        Entry184_guess* entry_guess = lookup_13c_guess.Lookup_guess(index_guess);
        Slot0FieldObject_guess* object_guess =
            (Slot0FieldObject_guess*)entry_guess->owner_guess;
        Slot0Object_guess* child_guess = object_guess->field_64_guess;
        if (child_guess != 0) {
            child_guess->Slot00_guess(1);
        }
        entry_guess = lookup_13c_guess.Lookup_guess(index_guess);
        ((Slot0FieldObject_guess*)entry_guess->owner_guess)->field_64_guess = 0;
        entry_guess = lookup_13c_guess.Lookup_guess(index_guess);
        if (entry_guess->owner_guess != 0) {
            ((Slot0FieldObject_guess*)entry_guess->owner_guess)->Slot00_guess(1);
        }
    }
    FUN_0050f3f6_guess((unsigned int*)&lookup_13c_guess);

    index_guess = 0;
    for (; index_guess < (int)lookup_12c_guess.count_0000_guess; ++index_guess) {
        Entry184_guess* entry_guess = lookup_12c_guess.Lookup_guess(index_guess);
        if (entry_guess->owner_guess != 0) {
            ((Slot4Object_guess*)entry_guess->owner_guess)->Slot01_guess(1);
        }
    }
    FUN_0050f3f6_guess((unsigned int*)&lookup_12c_guess);

    pickedIndex_0168_guess = -1;
    text_154_guess.Assign_guess(EQ_ARRAY(char, 0x0063F53F));
    field_160_guess = -1;
    flag_14c_guess = 0;
    g_cleanup_action_guess->Apply_guess(1);
    if (field_28_guess != 0) {
        Quad_guess source_guess;
        Quad_guess destination_guess;

        Quad_guess* bounds_guess = field_28_guess->GetClientClipRect(&source_guess);
        int width_guess = bounds_guess->field_8_guess - bounds_guess->field_0_guess;
        int height_guess = bounds_guess->field_C_guess - bounds_guess->field_4_guess;
        source_guess.field_0_guess = 0;
        source_guess.field_4_guess = 0;
        source_guess.field_8_guess = width_guess;
        source_guess.field_C_guess = height_guess;
        field_3c_guess.CopyTo_guess(&destination_guess, &source_guess);
    }
}

struct Slot32Object_guess {
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
    virtual void Slot32_guess(AtlasRender_guess* owner_guess, int first_guess,
                              int second_guess);
};

// A link was clicked (`mode_guess` 1). ClickAction 1 queues its FileToOpen as the next page (loaded by
// Refresh_guess on the next tick); 2 forwards the click to the parent window's vslot 32 (probably
// WndNotification).
// FUNCTION: TITANIUM 0x004D97A9
int AtlasRender_guess::OnLinkClicked_guess(Owner184_guess* owner_guess,
                                   int mode_guess, int arg_guess) {
    if (mode_guess == 1) {
        for (int index_guess = 0;
             index_guess < (int)lookup_11c_guess.count_0000_guess; ++index_guess) {
            if (owner_guess == lookup_11c_guess.Lookup_guess(index_guess)->owner_guess) {
                pickedIndex_0168_guess = index_guess;
                if (lookup_11c_guess.Lookup_guess(index_guess)->owner_guess->field_180_guess == 1) {
                    text_164_guess.Assign_guess(
                        lookup_11c_guess.Lookup_guess(index_guess)->owner_guess->GetFileToOpen_guess());
                } else if (lookup_11c_guess.Lookup_guess(index_guess)->owner_guess->field_180_guess == 2
                           && field_28_guess != 0) {
                    ((Slot32Object_guess*)field_28_guess)->Slot32_guess(this, 1, arg_guess);
                }
            }
        }
    }
    return 1;
}

// FileToOpen of the last clicked link (+0x168), or "" when none.
// FUNCTION: TITANIUM 0x004D987A
Offset184_guess IndexedOwner_guess::GetClickedLinkFile_guess() {
    if (index_168_guess >= 0) {
        Entry184_guess* entry_guess = lookup_11c_guess.Lookup_guess(index_168_guess);
        return entry_guess->owner_guess->GetFileToOpen_guess();
    }
    return Offset184_guess(EQ_ARRAY(char, 0x0063F53F));
}

// Draws each Image element's animation at its rect, offset by the scroll positions (+0x114, +0x10C).
// FUNCTION: TITANIUM 0x004D98B8
// @early-stop: budget, structural ndiff=24
int Owner_guess::DrawAnimations_guess() {
    Quad_guess bounds_guess;
    Quad_guess source_guess;
    Quad_guess texture_guess;
    int index_guess = 0;

    if (index_guess < (int)lookup_13c_guess.count_0000_guess) {
        do {
            if (lookup_13c_guess.Lookup_guess(index_guess)->owner_guess != 0 &&
                lookup_13c_guess.Lookup_guess(index_guess)->owner_guess->animation_64_guess != 0) {
                Quad_guess* position_guess = GetQuad_guess(&source_guess);
                int x_guess = position_guess->field_0_guess;
                int y_guess = position_guess->field_4_guess;
                Owner184_guess* owner_guess =
                    lookup_13c_guess.Lookup_guess(index_guess)->owner_guess;
                int dx_guess = owner_guess->rect_48_guess.field_0_guess;
                int dy_guess = owner_guess->rect_48_guess.field_4_guess;
                x_guess += dx_guess;
                y_guess += dy_guess;
                owner_guess = lookup_13c_guess.Lookup_guess(index_guess)->owner_guess;
                bounds_guess.field_C_guess =
                    owner_guess->rect_48_guess.field_C_guess -
                    owner_guess->rect_48_guess.field_4_guess +
                    y_guess - field_10c_guess;
                bounds_guess.field_8_guess =
                    owner_guess->rect_48_guess.field_8_guess -
                    owner_guess->rect_48_guess.field_0_guess +
                    x_guess - field_114_guess;
                bounds_guess.field_0_guess = x_guess - field_114_guess;
                bounds_guess.field_4_guess = y_guess - field_10c_guess;
                lookup_13c_guess.Lookup_guess(index_guess)->owner_guess->animation_64_guess->Draw_guess(
                    &bounds_guess, GetQuad_guess(&texture_guess), -1, 0xff000000);
            }
            ++index_guess;
        } while (index_guess < (int)lookup_13c_guess.count_0000_guess);
    }
    return 0;
}

// Thunk to 0x0050F3F6: frees an owned array's buffer and zeroes its pointer and counts. Shared by many
// destructors and their exception-unwind paths.
// FUNCTION: TITANIUM 0x004D99C0
void __fastcall DestroyPtrArray_guess(unsigned int* param_1) {
    FUN_0050f3f6_guess(param_1);
}

struct Settings_guess;

// EXTERNAL: TITANIUM 0x005BAFA0 ??1TargetCleanupBase_guess@@UAE@XZ
struct TargetCleanupBase_guess {
    // EXTERNAL: TITANIUM 0x005BACE0 ??0TargetCleanupBase_guess@@QAE@HHABUQuad_guess@@@Z
    TargetCleanupBase_guess(int first_guess, int second_guess,
                            const Quad_guess& rect_guess);
    virtual ~TargetCleanupBase_guess();
    char unknown_4_guess[0x31];
    unsigned char field_35_guess;
    char unknown_36_guess[0x2b];
    unsigned char field_61_guess;
    char unknown_62_guess[2];
    unsigned int field_64_guess;
    char unknown_68_guess[0xc];
    CXStr text_74_guess;
    CXStr text_78_guess;
    char unknown_7c_guess[0x18];
    unsigned int field_94_guess;
    char unknown_98_guess[0xc0];
    // EXTERNAL: TITANIUM 0x005A0A80 TargetCleanupBase_guess::Show_guess
    void Show_guess(int first_guess, int second_guess);
};

struct Table188_guess {
    int field_0_guess;
    void* data_4_guess;
    void* extra_8_guess;
    unsigned char valid_c_guess;
    char pad_d_guess[3];
    Table188_guess() {
        data_4_guess = 0;
        field_0_guess = 0;
        extra_8_guess = 0;
        valid_c_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0050319B Table188_guess::Set_guess
    void Set_guess(int count_guess, TextureAnimation_guess** value_guess);
    ~Table188_guess() {
        FUN_0050f3f6_guess((unsigned int*)this);
    }
};

// EXTERNAL: TITANIUM 0x0064EED0 ??_7AtlasLink_guess@@6B@
struct AtlasLink_guess : TargetCleanupBase_guess {
    Slot0Object_guess* image_0158_guess;
    char unknown_15c_guess[0x24];
    int field_180_guess;
    CXStr text_184_guess;
    Table188_guess table_188_guess;
    CXStr text_198_guess;
    AtlasLink_guess(int first_guess, Quad_guess rect_guess,
                        Settings_guess* settings_guess);
    Slot0Object_guess* CreateImage_guess(int image_guess);
    virtual ~AtlasLink_guess();
    AtlasLink_guess* Destroy_guess(unsigned char flags_guess);
};

struct Settings_guess {
    // EXTERNAL: TITANIUM 0x005DDA20 Settings_guess::GetInt_guess
    int GetInt_guess(const char* name_guess, int* value_guess);
    // EXTERNAL: TITANIUM 0x005DD9F0 Settings_guess::GetString_guess
    const char* GetString_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x005DCB60 Settings_guess::GetImage_guess
    int GetImage_guess(const char* name_guess);
};

// Image object built by new(0x68) and its constructor (0x005BDEF0).
struct ImageObject_guess {
    char unknown_0_guess[0x48];
    Quad_guess bounds_48_guess;
    char unknown_58_guess[0xc];
    TextureAnimation_guess* payload_64_guess;
    // EXTERNAL: TITANIUM 0x005BDEF0 ImageObject_guess::ImageObject_guess
    ImageObject_guess(int flags_guess);
};

// One Image element (Rect child, File): a 0x68-byte image window holding a one-frame texture
// animation of File at the rect's size. Returns "" or "Image Error(<names>)".
// FUNCTION: TITANIUM 0x004D9F03
// @early-stop: unknown, structural ndiff=183
Offset184_guess AtlasRender_guess::ParseImage_guess(
    XMLElement_guess* element_guess) {
    Settings_guess* settings_guess = (Settings_guess*)element_guess;
    Offset184_guess error_guess;
    bool valid_guess = false;
    Quad_guess bounds_guess;
    bounds_guess.field_C_guess = 0;
    bounds_guess.field_8_guess = 0;
    bounds_guess.field_4_guess = 0;
    bounds_guess.field_0_guess = 0;
    Quad_guess copy_guess;

    int rect_guess = settings_guess->GetImage_guess("Rect");
    if (rect_guess == 0) {
        error_guess.Append_guess("Rect ");
    } else {
        Quad_guess parsed_guess;
        Quad_guess* result_guess = ParseRect_guess(
            &parsed_guess, (const void*)rect_guess, &error_guess);
        bounds_guess.CopyTo_guess(&copy_guess, result_guess);
        valid_guess = !bounds_guess.IsInverted_guess();
    }

    Offset184_guess file_guess(settings_guess->GetString_guess("File"));
    if (file_guess.Length_guess() <= 0) {
        error_guess.Append_guess("File ");
        valid_guess = false;
    }

    if (valid_guess) {
        ImageObject_guess* image_guess = new ImageObject_guess(0);
        lookup_13c_guess.Set_guess(lookup_13c_guess.count_0000_guess,
                                   (Label_guess**)&image_guess);
        image_guess->bounds_48_guess.CopyTo_guess(&copy_guess, &bounds_guess);

        image_guess->payload_64_guess = new TextureAnimation_guess();

        PointValue_guess size_guess;
        size_guess.x_guess = bounds_guess.field_8_guess - bounds_guess.field_0_guess;
        size_guess.y_guess = bounds_guess.field_C_guess - bounds_guess.field_4_guess;
        TextureInfo_guess named_guess((const TextHandle_guess&)file_guess,
                                      &size_guess);
        named_guess.field_4_guess = 1;
        image_guess->payload_64_guess->AddFrame_guess(
            TextureFrame_guess(named_guess), 0, Extent_guess());
        return error_guess;
    }
    Offset184_guess message_guess =
        FUN_004b1357_guess(FUN_0042e3d9_guess("Image Error(", error_guess), ")\n");
    return message_guess;
}

// Deletes the link's own image (+0x158).
// FUNCTION: TITANIUM 0x004D99C5
AtlasLink_guess::~AtlasLink_guess() {
    if (image_0158_guess != 0) {
        image_0158_guess->Slot00_guess(1);
        image_0158_guess = 0;
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void free(void* memory_guess);

// Scalar deleting destructor of an atlas Link button (vtable 0x64EED0 slot 1): runs the destructor
// (0x004D99C5, which deletes the link image) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004D9A48
AtlasLink_guess* AtlasLink_guess::Destroy_guess(unsigned char flags_guess) {
    this->AtlasLink_guess::~AtlasLink_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

struct LabelFont_guess {
    // EXTERNAL: TITANIUM 0x005A3A00 LabelFont_guess::Width_guess
    int Width_guess(const Offset184_guess& text_guess);
    // EXTERNAL: TITANIUM 0x005A3A20 LabelFont_guess::Height_guess
    int Height_guess();
};

struct LabelFontLookup_guess {
    char unknown_0_guess[0xF4];
    Lookup184_guess fonts_f4_guess;
};

struct LabelFontHolder_guess {
    LabelFontLookup_guess* target_guess;
};

#define g_label_font_a_guess EQ_GLOBAL(LabelFontLookup_guess*, 0x0099D3EC)
#define g_label_font_b_guess EQ_GLOBAL(LabelFontHolder_guess*, 0x0099D334)

struct Label_guess {
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
    virtual void Slot56_guess();
    virtual void Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void SetFont_guess(LabelFont_guess* font_guess);
    virtual void SetText_guess(const Offset184_guess& text_guess);

    char unknown_4_guess[0x5D];
    unsigned char flag_61_guess;
    char unknown_62_guess[2];
    unsigned int field_64_guess;
    char unknown_68_guess[0x14];
    int field_7c_guess;
    unsigned int field_80_guess;
    char unknown_84_guess[0x10];
    int field_94_guess;
    char unknown_98_guess[0x8C];

    // EXTERNAL: TITANIUM 0x005BD730 Label_guess::Label_guess
    Label_guess(AtlasRender_guess* parent_guess, int flags_guess,
                const Quad_guess* rect_guess);
};

// One Label element: X, Y, Text and Font (default 3, a font index in the window manager). The label is
// sized to the text in that font. Returns "" or a label error message.
// FUNCTION: TITANIUM 0x004D9C7A
// @early-stop: budget, structural ndiff=109
Offset184_guess AtlasRender_guess::ParseLabel_guess(
    XMLElement_guess* element_guess) {
    int x_guess;
    int y_guess;
    int font_id_guess = 3;
    Offset184_guess error_guess;
    bool valid_guess = true;

    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x00646EA8),
                                              &x_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEB8));
        valid_guess = false;
    }

    Quad_guess rect_guess;
    rect_guess.field_C_guess = 0;
    rect_guess.field_8_guess = 0;
    rect_guess.field_4_guess = 0;
    rect_guess.field_0_guess = 0;
    if (element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x00646EA4),
                                              &y_guess) != 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064EEB4));
        valid_guess = false;
    }

    Offset184_guess text_guess(element_guess->GetAttribute_guess(
        EQ_ARRAY(char, 0x0064AEC0)));
    if (text_guess.Length_guess() < 1) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064F074));
        valid_guess = false;
    }

    element_guess->GetIntAttribute_guess(EQ_ARRAY(char, 0x0064F06C),
                                         &font_id_guess);
    Entry184_guess* font_entry_guess =
        g_label_font_a_guess->fonts_f4_guess.Lookup_guess(font_id_guess);
    if (font_entry_guess->owner_guess == 0) {
        error_guess.Append_guess(EQ_ARRAY(char, 0x0064F064));
    } else {
        LabelFont_guess* font_guess =
            (LabelFont_guess*)font_entry_guess->owner_guess;
        int width_guess = font_guess->Width_guess(text_guess);
        int height_guess = font_guess->Height_guess();
        rect_guess.field_0_guess = x_guess;
        rect_guess.field_4_guess = y_guess;
        rect_guess.field_8_guess = x_guess + width_guess;
        rect_guess.field_C_guess = y_guess + height_guess;

        if (valid_guess) {
            Label_guess* label_guess = new Label_guess(this, 0, &rect_guess);
            lookup_12c_guess.Set_guess(lookup_12c_guess.count_0000_guess,
                                       &label_guess);
            label_guess->SetText_guess(text_guess);
            Entry184_guess* secondary_font_entry_guess =
                g_label_font_b_guess->target_guess->fonts_f4_guess.Lookup_guess(
                    font_id_guess);
            label_guess->SetFont_guess((LabelFont_guess*)
                secondary_font_entry_guess->owner_guess);
            label_guess->field_64_guess = 0x42080;
            label_guess->field_94_guess = 2;
            label_guess->field_80_guess = 0x64000000;
            label_guess->field_7c_guess |= -1;
            label_guess->flag_61_guess = 1;
            label_guess->Slot48_guess(1, 1);
            return error_guess;
        }
    }

    Offset184_guess message_guess = FUN_004b1357_guess(
        FUN_0042e3d9_guess(EQ_ARRAY(char, 0x0064F054), error_guess),
        EQ_ARRAY(char, 0x0064F050));
    return message_guess;
}

// One Link button: ClickAction (see OnLinkClicked_guess), FileToOpen, an optional Image child (CreateImage_guess),
// LinkName as its text and ToolTip. Missing attributes collect in +0x198 for ParseLink_guess.
// FUNCTION: TITANIUM 0x004DA15B
AtlasLink_guess::AtlasLink_guess(int first_guess, Quad_guess rect_guess,
                                         Settings_guess* settings_guess)
    : TargetCleanupBase_guess(first_guess, 0, rect_guess) {
    int action_guess;

    // When the attribute is missing the stored action is an uninitialised local.
    if (settings_guess->GetInt_guess("ClickAction", &action_guess) != 0) {
        text_198_guess += "ClickAction ";
    }
    field_180_guess = action_guess;
    text_184_guess = settings_guess->GetString_guess("FileToOpen");
    if ((text_184_guess.Ptr != 0 ? text_184_guess.Ptr->length : 0) <= 0) {
        text_198_guess += "FileToOpen ";
    }
    int image_guess = settings_guess->GetImage_guess("Image");
    if (image_guess != 0) {
        image_0158_guess = CreateImage_guess(image_guess);
    }
    field_64_guess = 0x42480;
    field_94_guess = 2;
    field_61_guess = 1;
    {
        CXStr linkName_guess(settings_guess->GetString_guess("LinkName"));
        text_74_guess = linkName_guess;
    }
    {
        CXStr toolTip_guess(settings_guess->GetString_guess("ToolTip"));
        text_78_guess = toolTip_guess;
    }
    Show_guess(1, 1);
    field_35_guess = 0;
}

struct TextAppend_guess : CXStr {
    using CXStr::operator=;
    // EXTERNAL: TITANIUM 0x00572C10 TextAppend_guess::Append_guess
    void Append_guess(const CXStr& source_guess);
};

// EXTERNAL: TITANIUM 0x0042E3D9 Concat_guess
CXStr __cdecl Concat_guess(const char* first_guess, const CXStr& second_guess);

// EXTERNAL: TITANIUM 0x004B1357 Join_guess
CXStr __cdecl Join_guess(const CXStr& first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// The link's Image child (CX, CY, File) as a one-frame texture animation; 0 with an
// image error note in +0x198 when an attribute is missing.
// FUNCTION: TITANIUM 0x004D9A64
// @early-stop: budget, structural ndiff=37
Slot0Object_guess* AtlasLink_guess::CreateImage_guess(int image_guess) {
    if (image_guess == 0) {
        return 0;
    }
    Settings_guess* node_guess = reinterpret_cast<Settings_guess*>(image_guess);
    bool valid_guess = true;
    CXStr error_guess;
    int cx_guess;
    int cy_guess;

    if (node_guess->GetInt_guess("CX", &cx_guess) != 0) {
        error_guess += "Invalid CX Attribute";
        valid_guess = false;
    }
    if (node_guess->GetInt_guess("CY", &cy_guess) != 0) {
        error_guess += "Invalid CY Attribute";
        valid_guess = false;
    }
    CXStr file_guess(node_guess->GetString_guess("File"));
    if ((file_guess.Ptr != 0 ? file_guess.Ptr->length : 0) <= 0) {
        error_guess += "Invalid File Attribute ";
        valid_guess = false;
    }
    if (!valid_guess) {
        text_198_guess = Join_guess(Concat_guess("Image Error(", error_guess),
                                    EQ_ARRAY(char, 0x0064EFEC));
        return 0;
    }

    TextureAnimation_guess* animation_guess = new TextureAnimation_guess;
    table_188_guess.Set_guess(table_188_guess.field_0_guess, &animation_guess);
    PointValue_guess point_guess;
    point_guess.x_guess = cx_guess;
    point_guess.y_guess = cy_guess;
    TextureInfo_guess object_guess(
        *reinterpret_cast<const TextHandle_guess*>(&file_guess), &point_guess);
    object_guess.field_4_guess = 1;
    animation_guess->AddFrame_guess(TextureFrame_guess(object_guess), 0,
                                    Extent_guess());
    return reinterpret_cast<Slot0Object_guess*>(animation_guess);
}

// One Link element: its Rect child places an AtlasLink_guess link; returns "" or a link error message.
// FUNCTION: TITANIUM 0x004DA2D8
// @early-stop: budget, structural ndiff=43
CXStr AtlasRender_guess::ParseLink_guess(XMLElement_guess* element_guess) {
    Quad_guess rect_guess;
    Quad_guess source_guess;
    Quad_guess destination_guess;
    TextAppend_guess error_guess;

    rect_guess.field_C_guess = 0;
    rect_guess.field_8_guess = 0;
    rect_guess.field_4_guess = 0;
    rect_guess.field_0_guess = 0;

    int image_guess = ((Settings_guess*)element_guess)->GetImage_guess(
        EQ_ARRAY(char, 0x0064F090));
    if (image_guess != 0) {
        rect_guess.CopyTo_guess(
            &destination_guess,
            ParseRect_guess(&source_guess, (const void*)image_guess,
                            &error_guess));
        if (!rect_guess.IsInverted_guess()) {
            AtlasLink_guess* target_guess = new AtlasLink_guess(
                (int)this, rect_guess, (Settings_guess*)element_guess);
            lookup_11c_guess.Set_guess(
                (int)lookup_11c_guess.count_0000_guess,
                (Label_guess**)&target_guess);
            error_guess.Append_guess(target_guess->text_198_guess);
        }
    } else {
        error_guess = "Rect ";
    }

    CXStr result_guess;
    if ((error_guess.Ptr != 0 ? error_guess.Ptr->length : 0) > 0) {
        result_guess = Join_guess(
            Concat_guess("Link Error (", error_guess),
            EQ_ARRAY(char, 0x0064F07C));
    }
    return result_guess;
}

// Loads page `text_guess` from the atlas folder (0x99E414 string 1): Background (Image, CX, CY), then every
// Image, Label and Link, then the optional page Rect. Any error is announced in chat and written to
// AtlasPageError.txt (overwritten each time).
// FUNCTION: TITANIUM 0x004DA486
// @early-stop: budget, structural ndiff=144
bool AtlasRender_guess::SetFile_guess(TextHandle_guess* text_guess) {
    Clear_guess();
    Offset184_guess message_guess;
    Offset184_guess xml_guess = FUN_004d9090_guess(
        g_cleanup_action_guess->GetString_guess(1), *text_guess);
    XMLDoc_guess doc_guess((const char*)xml_guess);
    doc_guess.Parse_guess();
    if (doc_guess.errorFlag_guess == 0) {
        // Background: a texture drawn at CX x CY behind the page.
        XMLElement_guess* background_guess = doc_guess.FindElement_guess("Background");
        if (background_guess != 0) {
            bool ok_guess = true;
            Offset184_guess error_guess;
            Offset184_guess image_guess(background_guess->GetAttribute_guess("Image"));
            if (image_guess.Length_guess() <= 0) {
                error_guess.Append_guess("Image ");
                ok_guess = false;
            }
            int first_guess;
            if (background_guess->GetIntAttribute_guess("CX", &first_guess) != 0) {
                error_guess.Append_guess("CX ");
                ok_guess = false;
            }
            int second_guess;
            if (background_guess->GetIntAttribute_guess("CY", &second_guess) != 0) {
                error_guess.Append_guess("CY ");
                ok_guess = false;
            }
            if (!ok_guess) {
                message_guess.AppendText_guess(FUN_004b1357_guess(
                    FUN_0042e3d9_guess("Background Error(", error_guess), ")\n"));
            } else {
                field_158_guess = first_guess;
                field_15c_guess = second_guess;
                text_154_guess.AssignHandle_guess(image_guess);
                flag_14c_guess = 1;
                field_150_guess = 1;
            }
        }
        XMLElement_guess* image_element_guess = doc_guess.FindElement_guess("Image");
        while (image_element_guess != 0) {
            message_guess.AppendText_guess(ParseImage_guess(image_element_guess));
            image_element_guess = image_element_guess->FindNext_guess("Image");
        }
        XMLElement_guess* label_element_guess = doc_guess.FindElement_guess("Label");
        while (label_element_guess != 0) {
            message_guess.AppendText_guess(ParseLabel_guess(label_element_guess));
            label_element_guess = label_element_guess->FindNext_guess("Label");
        }
        XMLElement_guess* link_element_guess = doc_guess.FindElement_guess("Link");
        while (link_element_guess != 0) {
            message_guess.AppendText_guess(
                (const Offset184_guess&)ParseLink_guess(link_element_guess));
            link_element_guess = link_element_guess->FindNext_guess("Link");
        }
        XMLElement_guess* rect_element_guess = doc_guess.FindElement_guess("Rect");
        if (rect_element_guess != 0) {
            Quad_guess bounds_guess;
            ParseRect_guess(&bounds_guess, rect_element_guess, &message_guess);
            if (!bounds_guess.IsInverted_guess()) {
                Quad_guess destination_guess;
                field_3c_guess.CopyTo_guess(&destination_guess, &bounds_guess);
            }
        }
    } else {
        message_guess.Append_guess(doc_guess.GetError_guess());
    }
    if (message_guess.Length_guess() > 0) {
        pEverQuest->dsp_chat("Atlas Page Error");
        FILE* file_guess = fopen("AtlasPageError.txt", "w");
        if (file_guess != 0) {
            fprintf(file_guess, "Page Error: \n%s", (char*)message_guess);
            fclose(file_guess);
        }
    }
    SetSize_guess(-1, -1);
    return true;
}

// Renderer ctor: style 0x183, an empty page, then the folder's Default.xml.
// FUNCTION: TITANIUM 0x004DA867
// @early-stop: budget, structural ndiff=18
AtlasRender_guess::AtlasRender_guess(int first_guess, int second_guess,
                                       Quad_guess rect_guess)
    : CleanupBase_guess(first_guess, second_guess, rect_guess),
      flag_14c_guess(0), field_150_guess(0), field_160_guess(-1) {
    flag_ac_guess = 1;
    flag_ad_guess = 0;
    flag_ae_guess = 1;
    flag_af_guess = 0;
    field_64_guess = 0x183;
    ((TargetCleanupBase_guess*)this)->Show_guess(1, 0);
    Clear_guess();
    Offset184_guess default_xml_guess("Default.xml");
    SetFile_guess((TextHandle_guess*)&default_xml_guess);
}

// Per tick: loads the page queued by a link click (+0x164) and clears the request, then the base tick.
// FUNCTION: TITANIUM 0x004DAA0D
void AtlasRender_guess::Refresh_guess() {
    if (!((RefHolder_guess*)&text_164_guess)->IsEmpty_guess()) {
        SetFile_guess(&text_164_guess);
        text_164_guess.~TextHandle_guess();
    }
    CleanupBase_guess::OnProcessFrame();
}

// Scalar deleting destructor of the atlas page renderer (vtable 0x64F178 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x004DA977
AtlasRender_guess* AtlasRender_guess::Destroy_guess(unsigned char flags_guess) {
    this->AtlasRender_guess::~AtlasRender_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the atlas page renderer: empties the page (0x004D965C: links, images, labels,
// background) then frees the member lists and strings and runs the CXWnd destructor (0x005A0940).
// FUNCTION: TITANIUM 0x004DA993
AtlasRender_guess::~AtlasRender_guess() {
    Clear_guess();
}

