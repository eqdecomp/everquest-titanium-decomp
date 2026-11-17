// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 216: a hint from compare/tumap.py.
// CSpellGemWnd (SpellGemWnd.cpp in the draw failure log, vtable 0x0065D220): one spell gem.
// field_188 is the spell icon (-1 empty), field_194 the "A_SpellGems" icon animation, field_190 the fade step
// (0-10) with field_18c its direction. field_11c bit 1/2: left/right button held; field_120: pressed.
// g_globalPair_guess (0x0099D334) is the window manager; its +0x48 is the mouse-capture window.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct CSpellGemWnd_guess;
struct SpellGemSink_guess;

#include "titanium/layouts/geometry.h"

struct Bounds_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;

    // EXTERNAL: TITANIUM 0x004EA5BF Bounds_guess::Contains_guess
    char Contains_guess(const CXPoint* point_guess);
};

struct SharedField_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571F70 SharedField_guess::Assign_guess
    void Assign_guess(const SharedField_guess* source_guess);
};

struct Event_guess {
    char unknown_000[0x8];
    int type_guess;
    char unknown_00c[0x80];
    SharedField_guess field_8c;
    char unknown_090[0x78];
    int field_108;
    int field_10c;
    int field_110;
    int field_114;
    int field_118;
};

struct Wnd_guess {
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
    virtual int Notify_guess(CSpellGemWnd_guess* sender_guess, int code_guess, int data_guess);
};

struct Str_guess {
    char* data_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* source_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* data_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x005B47A0 Manager_guess::GetValue_guess
    int GetValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005B44A0 Manager_guess::GetValueByKey_guess
    int GetValueByKey_guess(const Str_guess& key_guess);
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

struct SpellGemSink_guess {
    virtual void Slot00_guess(int value_guess);
    char unknown_004[0x2c];
    int width_guess;
    int height_guess;
    char unknown_038[0x14];
    // EXTERNAL: TITANIUM 0x005B1910 SpellGemSink_guess::Draw_guess
    int Draw_guess(const CXRect* area_guess, const CXRect* clip_guess, unsigned int color_guess,
        unsigned int back_guess);
    // EXTERNAL: TITANIUM 0x005B1AB0 SpellGemSink_guess::Update_guess
    void Update_guess(int value);
    // EXTERNAL: TITANIUM 0x005B1D90 ??0SpellGemSink_guess@@QAE@XZ
    SpellGemSink_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B SpellGemSink_guess::Set_guess
    void Set_guess(int value_guess);
};

struct SpellGemRect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;

    SpellGemRect_guess(const SpellGemRect_guess& other)
        : left_guess(other.left_guess), top_guess(other.top_guess),
          right_guess(other.right_guess), bottom_guess(other.bottom_guess) {}
    ~SpellGemRect_guess() {}
};

struct SpellGemWndBase_guess {
    // EXTERNAL: TITANIUM 0x005A1290 SpellGemWndBase_guess::SpellGemWndBase_guess
    SpellGemWndBase_guess(int first_guess, int second_guess,
        SpellGemRect_guess rect_guess);
    // EXTERNAL: TITANIUM 0x005A0940 ??1SpellGemWndBase_guess@@UAE@XZ
    virtual ~SpellGemWndBase_guess();
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
    virtual CXRect GetClientRect_guess();
};

struct SpellGemData_guess {
    CXStr field_0_guess;
    int background_0004_guess;
    int field_8_guess;
    int field_c_guess;

    SpellGemData_guess()
        : field_0_guess(), background_0004_guess(0), field_8_guess(0), field_c_guess(0) {}
};

// EXTERNAL: TITANIUM 0x0065D220 ??_7CSpellGemWnd_guess@@6B@
struct CSpellGemWnd_guess : SpellGemWndBase_guess {
    char unknown_000[0x24];
    Wnd_guess* notifyReceiver_0028_guess;
    char unknown_02c[0x36];
    char field_62;
    char unknown_063[0x11];
    SharedField_guess field_74;
    char unknown_078[0xa4];
    int mouseFlags_011c_guess;
    char field_120;
    char unknown_121[3];
    int field_124;
    int gemTint_0128_guess;
    int field_12c_guess[10];
    int gemAlpha_0154_guess;
    int field_158_guess[10];
    int offsetX_0180_guess;
    int offsetY_0184_guess;
    int spellIcon_0188_guess;
    int fadeMode_018c_guess;
    int fadeStep_0190_guess;
    SpellGemSink_guess* gemIconAnim_0194_guess;
    SpellGemData_guess field_198_guess;

    // EXTERNAL: TITANIUM 0x005A0E50 CSpellGemWnd_guess::OnProcessFrame
    int OnProcessFrame();
    // EXTERNAL: TITANIUM 0x005A0780 CSpellGemWnd_guess::Prepare_guess
    void Prepare_guess(Event_guess* event_guess);
    int Draw_guess();
    virtual ~CSpellGemWnd_guess();
    CSpellGemWnd_guess* Delete_guess(unsigned char flags_guess);
    void SetSpellGemTint_guess(int value_guess);
    CSpellGemWnd_guess(int first_guess, int second_guess,
        SpellGemRect_guess rect_guess, int value70_guess, int value74_guess,
        int value78_guess, int value7c_guess, int value80_guess, int last_guess);

    void SetPressed_guess(char value);
    void SetFadeMode_guess(int value);
    void SetSpellIcon_guess(int value);
    int OnProcessFrame_guess();
    void OnEvent_guess(Event_guess* event_guess);
    int HandleLButtonUpAfterHeld_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleRButtonDown_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleRButtonUp_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleRButtonHeld_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleRButtonUpAfterHeld_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleLButtonUp_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleLButtonDown_guess(CXPoint* point_guess, unsigned int flags_guess);
    int HandleLButtonHeld_guess(CXPoint* point_guess, unsigned int flags_guess);
    void InitGemAnimation_guess();
};

struct GlobalPair_guess {
    char unknown_000[0x48];
    CSpellGemWnd_guess* field_48;
    char unknown_04c[0x20];
    int field_6c;

    // EXTERNAL: TITANIUM 0x00435AA7 GlobalPair_guess::Activate_guess
    void Activate_guess(CSpellGemWnd_guess* sender_guess);
};

#define g_globalPair_guess EQ_GLOBAL(GlobalPair_guess**, 0x0099D334)
#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x0059D960 GetState_guess
void __stdcall GetState_guess(void* output_guess);

// Deletes the spell icon drawn on the gem (+0x194, updated by 0x00558984).
// FUNCTION: TITANIUM 0x0055892A
CSpellGemWnd_guess::~CSpellGemWnd_guess() {
    if (gemIconAnim_0194_guess != 0) {
        gemIconAnim_0194_guess->Slot00_guess(1);
        gemIconAnim_0194_guess = 0;
    }
}

// Stores the gem tint and builds the 10-step fade: each step darkens every channel by tint/11, and the
// icon alpha falls from 0xFF by 0x15 per step (0xEA down to 0x2D).
// FUNCTION: TITANIUM 0x005589AB
// @early-stop: budget, structural ndiff=25
void CSpellGemWnd_guess::SetSpellGemTint_guess(int value_guess) {
    unsigned int value = value_guess;
    gemTint_0128_guess = value;
    gemAlpha_0154_guess = 0xff;
    unsigned char red = (unsigned char)(((value >> 16) & 0xff) / 11);
    unsigned char green = (unsigned char)(((value >> 8) & 0xff) / 11);
    unsigned char blue = (unsigned char)((value & 0xff) / 11);
    int packed = (red << 16) | (green << 8) | blue;
    int step = 0xea;
    int* p = field_12c_guess;
    do {
        p[0xb] = step;
        *p = p[-1] - packed;
        step -= 0x15;
        p++;
    } while (step > 0x18);
}

// EXTERNAL: TITANIUM 0x005C0C30 DebugLog_guess
void __cdecl DebugLog_guess(const char* format_guess, ...);

#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

struct SpellGemArea_guess : CXRect {
    SpellGemArea_guess(int l, int t, int r, int b) {
        left = l;
        top = t;
        right = r;
        bottom = b;
    }
};

// An empty gem draws only the empty texture. Otherwise the background in the fade colour (white while
// pressed, +0x202020 when field_62 is set, probably mouse-over), then the icon at its offset with the
// step's alpha, then the overlay.
// The 0x96-0xD1 numbers are SpellGemWnd.cpp line numbers for the failure log.
// FUNCTION: TITANIUM 0x00558A3A
// @early-stop: tiebreak, diff ndiff=10
int CSpellGemWnd_guess::Draw_guess() {
    int result_guess = -1;
    CXRect rect_guess = GetClientRect_guess();
    CXRect clip_guess = ((CXWnd*)this)->GetClientClipRect();
    CXStr text_guess;

    do {
        if (spellIcon_0188_guess < 0) {
            if (field_198_guess.field_8_guess != 0 &&
                ((SpellGemSink_guess*)field_198_guess.field_8_guess)->Draw_guess(
                    &rect_guess, &clip_guess, 0xffffffff, 0xff000000) < 0) {
                DebugLog_guess("%s at: %s, %d\n", g_emptyText_guess,
                    "C:\\EQ\\EverQuest\\SpellGemWnd.cpp", 0x96);
                break;
            }
        } else {
            unsigned int color_guess = (&gemTint_0128_guess)[fadeStep_0190_guess];
            unsigned int bright_guess = color_guess + 0x202020;
            SpellGemSink_guess* background_guess = (SpellGemSink_guess*)field_198_guess.background_0004_guess;
            if (background_guess != 0) {
                int status_guess;
                if (field_120) {
                    status_guess = background_guess->Draw_guess(&rect_guess, &clip_guess,
                        0xffffffff, 0xff000000);
                } else if (field_62) {
                    status_guess = background_guess->Draw_guess(&rect_guess, &clip_guess,
                        bright_guess, 0xff000000);
                } else {
                    status_guess = background_guess->Draw_guess(&rect_guess, &clip_guess,
                        color_guess, 0xff000000);
                }
                if (status_guess < 0) {
                    DebugLog_guess("%s at: %s, %d\n", g_emptyText_guess,
                        "C:\\EQ\\EverQuest\\SpellGemWnd.cpp", 0xb0);
                    break;
                }
            }
            if (gemIconAnim_0194_guess != 0) {
                int left_guess = offsetX_0180_guess + rect_guess.left;
                int top_guess = offsetY_0184_guess + rect_guess.top;
                SpellGemArea_guess area_guess(left_guess, top_guess,
                    gemIconAnim_0194_guess->width_guess + left_guess,
                    gemIconAnim_0194_guess->height_guess + top_guess);
                int status_guess;
                if (fadeStep_0190_guess == 0) {
                    status_guess = gemIconAnim_0194_guess->Draw_guess(&area_guess, &clip_guess,
                        0xffffffff, 0xff000000);
                } else {
                    status_guess = gemIconAnim_0194_guess->Draw_guess(&area_guess, &clip_guess,
                        ((&gemAlpha_0154_guess)[fadeStep_0190_guess] << 24) | 0xffffff, 0xff000000);
                }
                if (status_guess < 0) {
                    DebugLog_guess("%s at: %s, %d\n", g_emptyText_guess,
                        "C:\\EQ\\EverQuest\\SpellGemWnd.cpp", 0xc9);
                    break;
                }
            }
            if (field_198_guess.field_c_guess != 0 &&
                ((SpellGemSink_guess*)field_198_guess.field_c_guess)->Draw_guess(
                    &rect_guess, &clip_guess, 0xffffffff, 0xff000000) < 0) {
                DebugLog_guess("%s at: %s, %d\n", g_emptyText_guess,
                    "C:\\EQ\\EverQuest\\SpellGemWnd.cpp", 0xd1);
                break;
            }
        }
        result_guess = 0;
    } while (0);
    return result_guess;
}

// 1 fades the gem in, 2 jumps to full and fades out; 0 is idle.
// FUNCTION: TITANIUM 0x00558A18
void CSpellGemWnd_guess::SetFadeMode_guess(int value) {
    if (value != fadeMode_018c_guess) {
        if (value == 2) {
            fadeStep_0190_guess = 10;
        }
        fadeMode_018c_guess = value;
    }
}

// Pressed flag (field_120): white background while set.
// FUNCTION: TITANIUM 0x00558ECE
void CSpellGemWnd_guess::SetPressed_guess(char value) {
    char* field = &field_120;
    if (*field != value) {
        *field = value;
    }
}

// Scalar deleting destructor of a spell gem window (vtable 0x65D220 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x00558EE1
CSpellGemWnd_guess* CSpellGemWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->CSpellGemWnd_guess::~CSpellGemWnd_guess();
    if ((flags_guess & 1) != 0) {
        operator delete(this);
    }
    return this;
}

// Mouse-handler family: each checks the hit with the screen rect (0x0059D960), skips flag 0x10000 and
// notifies the parent with a code; releases also drop the counted mouse capture.
// Left release: code 1 (left click).
// FUNCTION: TITANIUM 0x00558EFD
int CSpellGemWnd_guess::HandleLButtonUp_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 1) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        SetPressed_guess(0);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 1, 0);
        }
        GlobalPair_guess* pair_guess = *g_globalPair_guess;
        if (pair_guess->field_48 == this) {
            pair_guess->field_6c--;
            if (pair_guess->field_6c <= 0) {
                pair_guess->field_48 = 0;
            }
        }
        mouseFlags_011c_guess &= ~1;
    }
    return 0;
}

// Sets the spell icon; any negative id becomes -1 (empty).
// FUNCTION: TITANIUM 0x00558984
void CSpellGemWnd_guess::SetSpellIcon_guess(int value) {
    int* field = &spellIcon_0188_guess;
    *field = value;
    if (value < 0) {
        *field |= -1;
    }
    if (gemIconAnim_0194_guess != 0) {
        gemIconAnim_0194_guess->Update_guess(*field);
    }
}

// Per-frame: the base tick, then one fade step toward 10 (fading in) or toward 0 (fading out, then idle).
// FUNCTION: TITANIUM 0x00558BE1
int CSpellGemWnd_guess::OnProcessFrame_guess() {
    int result_guess = -1;
    if (OnProcessFrame() >= 0) {
        result_guess = 0;
        if (fadeMode_018c_guess != 0) {
            if (fadeMode_018c_guess == 1) {
                if (fadeStep_0190_guess < 10) {
                    ++fadeStep_0190_guess;
                }
            } else if (fadeStep_0190_guess < 1) {
                fadeMode_018c_guess = 0;
            } else {
                --fadeStep_0190_guess;
            }
        }
    }
    return result_guess;
}

// From the screen template (type 0x19, the spell gem piece): the background, empty and overlay textures
// and the icon offset.
// FUNCTION: TITANIUM 0x00558C27
void CSpellGemWnd_guess::OnEvent_guess(Event_guess* event_guess) {
    Prepare_guess(event_guess);
    if (event_guess->type_guess == 0x19) {
        field_74.Assign_guess(&event_guess->field_8c);
        field_198_guess.background_0004_guess = g_manager_guess->GetValue_guess(event_guess->field_10c);
        field_198_guess.field_8_guess = g_manager_guess->GetValue_guess(event_guess->field_108);
        field_198_guess.field_c_guess = g_manager_guess->GetValue_guess(event_guess->field_110);
        offsetX_0180_guess = event_guess->field_114;
        offsetY_0184_guess = event_guess->field_118;
    }
}

// Left release, code 0x19; unlike HandleLButtonUp_guess it keeps the pressed look. Probably the
// release after a hold.
// FUNCTION: TITANIUM 0x00558CAC
int CSpellGemWnd_guess::HandleLButtonUpAfterHeld_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 1) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 0x19, 0);
        }
        GlobalPair_guess* pair_guess = *g_globalPair_guess;
        if (pair_guess->field_48 == this) {
            pair_guess->field_6c--;
            if (pair_guess->field_6c <= 0) {
                pair_guess->field_48 = 0;
            }
        }
        mouseFlags_011c_guess &= ~1;
    }
    return 0;
}

// Right press: captures the mouse; code 5 only with flag 0x10.
// FUNCTION: TITANIUM 0x00558D20
int CSpellGemWnd_guess::HandleRButtonDown_guess(CXPoint* point_guess, unsigned int flags_guess) {
    int result_guess = -1;
    Bounds_guess bounds_guess;
    GetState_guess(&bounds_guess);
    mouseFlags_011c_guess |= 2;
    (*g_globalPair_guess)->Activate_guess(this);

    if (!bounds_guess.Contains_guess(point_guess) ||
        (flags_guess & 0xffff0000) == 0x10000 ||
        notifyReceiver_0028_guess == 0 ||
        (flags_guess & 0x10) == 0 ||
        notifyReceiver_0028_guess->Notify_guess(this, 5, 0) >= 0) {
        result_guess = 0;
    }
    return result_guess;
}

// Right release: code 3 (right click).
// FUNCTION: TITANIUM 0x00558D90
int CSpellGemWnd_guess::HandleRButtonUp_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 2) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 3, 0);
        }
        GlobalPair_guess* pair_guess = *g_globalPair_guess;
        if (pair_guess->field_48 == this) {
            pair_guess->field_6c--;
            if (pair_guess->field_6c <= 0) {
                pair_guess->field_48 = 0;
            }
        }
        mouseFlags_011c_guess &= ~2;
    }
    return 0;
}

// Right held: code 0x18, no release (the left twin is HandleLButtonHeld_guess, 0x17).
// FUNCTION: TITANIUM 0x00558E04
int CSpellGemWnd_guess::HandleRButtonHeld_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 2) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 0x18, 0);
        }
    }
    return 0;
}

// Right release, code 0x1A: the right twin of HandleLButtonUpAfterHeld_guess (0x19).
// FUNCTION: TITANIUM 0x00558E5A
int CSpellGemWnd_guess::HandleRButtonUpAfterHeld_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 2) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 0x1a, 0);
        }
        GlobalPair_guess* pair_guess = *g_globalPair_guess;
        if (pair_guess->field_48 == this) {
            pair_guess->field_6c--;
            if (pair_guess->field_6c <= 0) {
                pair_guess->field_48 = 0;
            }
        }
        mouseFlags_011c_guess &= ~2;
    }
    return 0;
}

// Left press: pressed look, captures the mouse; code 4 only with flag 0x10.
// FUNCTION: TITANIUM 0x00558F7A
int CSpellGemWnd_guess::HandleLButtonDown_guess(CXPoint* point_guess, unsigned int flags_guess) {
    int result_guess = -1;
    Bounds_guess bounds_guess;
    GetState_guess(&bounds_guess);
    mouseFlags_011c_guess |= 1;
    SetPressed_guess(1);
    (*g_globalPair_guess)->Activate_guess(this);

    if (!bounds_guess.Contains_guess(point_guess) ||
        (flags_guess & 0xffff0000) == 0x10000 ||
        notifyReceiver_0028_guess == 0 ||
        (flags_guess & 0x10) == 0 ||
        notifyReceiver_0028_guess->Notify_guess(this, 4, 0) >= 0) {
        result_guess = 0;
    }
    return result_guess;
}

// Left held: code 0x17 and the pressed look cleared, no release.
// FUNCTION: TITANIUM 0x00558FF3
int CSpellGemWnd_guess::HandleLButtonHeld_guess(CXPoint* point_guess, unsigned int flags_guess) {
    if ((mouseFlags_011c_guess & 1) != 0) {
        Bounds_guess bounds_guess;
        GetState_guess(&bounds_guess);
        SetPressed_guess(0);
        if (bounds_guess.Contains_guess(point_guess) &&
            (flags_guess & 0xffff0000) != 0x10000 &&
            notifyReceiver_0028_guess != 0) {
            notifyReceiver_0028_guess->Notify_guess(this, 0x17, 0);
        }
    }
    return 0;
}

// Creates the icon animation from the "A_SpellGems" set and resets fade and button state.
// FUNCTION: TITANIUM 0x00559052
void CSpellGemWnd_guess::InitGemAnimation_guess() {
    int value_guess;
    {
        Str_guess name_guess("A_SpellGems");
        value_guess = g_manager_guess->GetValueByKey_guess(name_guess);
    }
    gemIconAnim_0194_guess = new SpellGemSink_guess();
    gemIconAnim_0194_guess->Set_guess(value_guess);
    fadeMode_018c_guess = 0;
    fadeStep_0190_guess = 0;
    field_124 = 0;
    field_120 = 0;
    mouseFlags_011c_guess = 0;
}

// Textures (background, empty, overlay), icon offset and tint, then an empty gem.
// FUNCTION: TITANIUM 0x005590FD
CSpellGemWnd_guess::CSpellGemWnd_guess(int first_guess, int second_guess,
    SpellGemRect_guess rect_guess, int value70_guess, int value74_guess,
    int value78_guess, int value7c_guess, int value80_guess, int last_guess)
    : SpellGemWndBase_guess(first_guess, second_guess, rect_guess),
      field_198_guess() {
    field_198_guess.background_0004_guess = value70_guess;
    field_198_guess.field_8_guess = value74_guess;
    field_198_guess.field_c_guess = value78_guess;
    offsetX_0180_guess = value7c_guess;
    offsetY_0184_guess = value80_guess;
    SetSpellGemTint_guess(last_guess);
    spellIcon_0188_guess = -1;
    InitGemAnimation_guess();
}
