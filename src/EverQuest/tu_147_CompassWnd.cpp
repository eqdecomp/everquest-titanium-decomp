// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 147: a hint from compare/tumap.py.
// The compass window (CompassWindow, CCompassWnd_guess): two scrolling strip labels, a needle that drifts
// with
// low skill, and coloured markers (CompassMarker_guess) drawn as 2-pixel vertical lines at their bearing.
// Headings are 0-512 per turn; the "level" read from the character (+0x1010 of the info tail) caps at 200,
// probably the Sense Heading skill.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct FUN_0050f3f6_guess {
    int count_0000_guess;
    void* data_guess;
    int extra_guess;
    unsigned char flag_000c_guess;
    FUN_0050f3f6_guess() {
        data_guess = 0;
        count_0000_guess = 0;
        extra_guess = 0;
        flag_000c_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x004EB924 FUN_0050f3f6_guess::FUN_004eb924_guess
    int* FUN_004eb924_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0050319B FUN_0050f3f6_guess::FUN_0050319b_guess
    void FUN_0050319b_guess(int value_guess, int* output_guess);
    // EXTERNAL: TITANIUM 0x00564298 FUN_0050f3f6_guess::DeleteElement_guess
    void DeleteElement_guess(int index);
    ~FUN_0050f3f6_guess();
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct CompassMarker_guess {
    // EXTERNAL: TITANIUM 0x00446318 CompassMarker_guess::CompassMarker_guess
    CompassMarker_guess();
    int r_0000_guess;
    int g_0004_guess;
    int b_0008_guess;
    char pad_000c_guess[0x0C];
    char state_0018_guess;
    char pad_0019_guess[0x03];
    int x_001c_guess;
    char flag_0020_guess;
    char pad_0021_guess[0x03];
    char (__cdecl *callback_0024_guess)(int);
    int argument_0028_guess;

    char Invoke_guess();
};

// Frame blocks of the draw loop: a 16-byte block (x at 0, y at 4, z at 0xC) and two float points.
struct PosBlock_guess {
    int x_guess;
    int y_guess;
    int pad_guess;
    int z_guess;
};

struct Vec3f_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct CompassState_guess {
    char pad_0000_guess[0x30];
    float x_0030_guess;
    float y_0034_guess;
    char pad_0038_guess[0x14];
    float heading_004c_guess;
};

struct CompassClock_guess {
    char pad_0000_guess[0x148];
    int frame_0148_guess;
};

struct CompassHeading_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual float GetHeading_guess(float x_guess, float y_guess, int* quadrant_guess);
};

struct CompassStripInner_guess {
    // EXTERNAL: TITANIUM 0x004E8DFA CompassStripInner_guess::GetSize_guess
    void GetSize_guess(int* rect_guess);
};

struct CompassStrip_guess {
    char pad_0000_guess[0x48];
    CompassStripInner_guess inner_0048_guess;
};

#define g_compassState_guess EQ_GLOBAL(CompassState_guess*, 0x00905CE4)
#define g_compassClock_guess EQ_GLOBAL(CompassClock_guess*, 0x00905D24)
#define g_compassHeading_guess EQ_GLOBAL(CompassHeading_guess*, 0x0099E374)
#define g_compassTurn_guess EQ_GLOBAL(double, 0x006410C0)
#define g_compassScale_guess EQ_GLOBAL(double, 0x00653138)
#define g_compassOffset_guess EQ_GLOBAL(double, 0x00653130)
#define g_compassBias_guess EQ_GLOBAL(float, 0x0065312C)
#define g_compassFullCircle_guess EQ_GLOBAL(float, 0x0064113C)
#define g_compassZero_guess EQ_GLOBAL(float, 0x0063F4CC)
#define g_compassHalfCircle_guess EQ_GLOBAL(float, 0x00653128)
#define g_compassTimeScale_guess EQ_GLOBAL(float, 0x00653124)
#define g_compassTimeBias_guess EQ_GLOBAL(float, 0x00653120)
#define g_compassTimeOffset_guess EQ_GLOBAL(double, 0x006410A0)

union ColorBytes_guess {
    int packed_guess;
    unsigned char bytes_guess[4];
};

// DAT_0099E364: the draw object, DrawLine is vtable slot 0x70 (28).
struct Renderer_guess {
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
    virtual void DrawLine_guess(Vec3f_guess* a_guess, Vec3f_guess* b_guess, int color_guess);
};

#define g_renderer_guess EQ_GLOBAL(Renderer_guess*, 0x0099E364)

// EXTERNAL: TITANIUM 0x00653000 ??_7CCompassWnd_guess@@6B@
struct CCompassWnd_guess : CSidlScreenWndBase {
    CCompassWnd_guess(CXWnd* parent_guess);
    CXWnd* strip1_015c_guess;            // 0x15c
    CXWnd* strip2_0160_guess;            // 0x160
    int value_0164_guess;
    int value_0168_guess;
    int value_016c_guess;
    double value_0170_guess;
    int value_0178_guess;
    CompassMarker_guess element_017c_guess;   // 0x17c, 0x2C bytes
    void (__cdecl *fnptr_01a8_guess)(void);  // 0x1a8
    FUN_0050f3f6_guess member_01ac_guess;

    // EXTERNAL: TITANIUM 0x005A2490 CCompassWnd_guess::GetChildLabel_guess
    CXWnd* GetChildLabel_guess(const CXStr& name_guess);

    void UpdateNeedleSpeed_guess();
    void OnProcessFrame_guess();
    void Reset_guess();
    void RemoveMarkerAt_guess(int index);
    void RemoveMarker_guess(int value_guess);
    int CalculateNeedleVariation_guess();
    CCompassWnd_guess* DeletingDestructor_guess(unsigned char flags_guess);
    int AddMarker_guess(int value_guess);
    int PostDraw_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CCompassWnd_guess::OnProcessFrame
    void OnProcessFrame();
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
    // slot 0xE0: fills a position block for this object
    virtual void GetPos_guess(PosBlock_guess* out_guess);
    virtual ~CCompassWnd_guess() ;
};

// EXTERNAL: TITANIUM 0x004F9BEA FUN_004f9bea_guess
char __cdecl FUN_004f9bea_guess(int arg_guess);

// EXTERNAL: TITANIUM 0x004F9BF0 FUN_004f9bf0_guess
void __cdecl FUN_004f9bf0_guess(void);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060F81E FUN_0060f81e_guess
int __cdecl FUN_0060f81e_guess(int value);

// EXTERNAL: TITANIUM 0x0060F5EB rand
int __cdecl rand(void);

// Profile info block reached through GetCharInfo2 (the tail at +0xF70 is returned as an address).
struct CharInfoTail_guess {
    char pad_0000_guess[0xA0];
    int field_1010_guess;
};

struct CHARINFO2 {
    char pad_0000_guess[0xF70];
    CharInfoTail_guess tail_0f70_guess;
};

// pCharData (0x00905D00) is an EQ_PC: the profile is a virtual base, reached through the vbptr at +8.
struct CharViewPrefix_guess {
    int pad_0000_guess;
    int pad_0004_guess;
};

// The character base as a virtual base; its inline method reaches GetCharInfo2 from the base's address.
struct CharBase_guess : EQ_Character {
    CHARINFO2* Info_guess() {
        return GetCharInfo2();
    }
};

struct CharView_guess : CharViewPrefix_guess, virtual CharBase_guess {
};

#define g_charView_guess EQ_GLOBAL(CharView_guess*, 0x00905D00)

#define g_initialValue_guess EQ_GLOBAL(double, 0x00652FF8)
#define g_largerValue_guess EQ_GLOBAL(double, 0x00652FF0)

// Holds a point and an optional callback that fills three float outputs.
struct PointSource_guess {
    char pad_0000_guess[0x0C];
    float x_000c_guess;
    float y_0010_guess;
    float z_0014_guess;
    char pad_0018_guess[0x14];
    void (__cdecl *fill_002c_guess)(float* a_guess, float* b_guess, float* c_guess);

    void Fill_guess(float* a_guess, float* b_guess, float* c_guess);
};

// Marker position: from its callback when set, else the stored Y/X/Z.
// FUNCTION: TITANIUM 0x004F9B9C
void PointSource_guess::Fill_guess(float* a_guess, float* b_guess, float* c_guess) {
    if (fill_002c_guess != 0) {
        fill_002c_guess(a_guess, b_guess, c_guess);
    } else {
        *a_guess = x_000c_guess;
        *b_guess = y_0010_guess;
        *c_guess = z_0014_guess;
    }
}

// Whether the marker is shown: refreshed from its callback when it has one, else the last stored state.
// FUNCTION: TITANIUM 0x004F9BD2
char CompassMarker_guess::Invoke_guess() {
    if (callback_0024_guess != 0) {
        state_0018_guess = callback_0024_guess(argument_0028_guess);
    }
    return state_0018_guess;
}

// Needle speed: the slow rate, or the fast one when the error is over 50 units or the settle timer runs;
// negative when the needle must turn back.
// FUNCTION: TITANIUM 0x004F9C15
void CCompassWnd_guess::UpdateNeedleSpeed_guess() {
    value_0170_guess = g_initialValue_guess;
    int difference = FUN_0060f81e_guess(value_0164_guess - value_0168_guess);
    if (difference > 50 || value_0178_guess > 0) {
        value_0170_guess = g_largerValue_guess;
    }
    if (value_0168_guess > value_0164_guess) {
        value_0170_guess = -value_0170_guess;
    }
}

// Clears the needle offset and starts a 5000 ms settle timer.
// FUNCTION: TITANIUM 0x004F9C6F
void CCompassWnd_guess::Reset_guess() {
    value_0168_guess = 0;
    value_0178_guess = 5000;
}

// Draws each visible marker that lies ahead (flag +0x20) as two adjacent lines in its RGB colour, full alpha.
// FUNCTION: TITANIUM 0x004F9C81
// @early-stop: unknown, diff ndiff=38
int CCompassWnd_guess::PostDraw_guess() {
    CCompassWnd_guess* self_guess = this;
    PosBlock_guess pos;
    Vec3f_guess b;
    Vec3f_guess a;
    int i = 0;
    if (self_guess->member_01ac_guess.count_0000_guess > 0) {
        do {
            if (((CompassMarker_guess*)*self_guess->member_01ac_guess.FUN_004eb924_guess(i))->Invoke_guess()) {
                if (((CompassMarker_guess*)*self_guess->member_01ac_guess.FUN_004eb924_guess(i))->flag_0020_guess != 0) {
                    self_guess->GetPos_guess(&pos);
                    ColorBytes_guess color;
                    CompassMarker_guess* e = (CompassMarker_guess*)*self_guess->member_01ac_guess.FUN_004eb924_guess(i);
                    int r = e->r_0000_guess;
                    int g = e->g_0004_guess;
                    int bl = e->b_0008_guess;
                    color.bytes_guess[2] = (unsigned char)r;
                    color.bytes_guess[0] = (unsigned char)bl;
                    color.bytes_guess[1] = (unsigned char)g;
                    color.bytes_guess[3] = 0xff;
                    a.x_guess = (float)(((CompassMarker_guess*)*self_guess->member_01ac_guess.FUN_004eb924_guess(i))->x_001c_guess + pos.x_guess);
                    a.y_guess = (float)(pos.y_guess + 4);
                    b.x_guess = (float)(((CompassMarker_guess*)*self_guess->member_01ac_guess.FUN_004eb924_guess(i))->x_001c_guess + pos.x_guess);
                    b.y_guess = (float)pos.z_guess;
                    g_renderer_guess->DrawLine_guess(&a, &b, color.packed_guess);
                    a.x_guess = a.x_guess + 1.0f;
                    b.x_guess = b.x_guess + 1.0f;
                    g_renderer_guess->DrawLine_guess(&a, &b, color.packed_guess);
                }
            }
            ++i;
        } while (i < self_guess->member_01ac_guess.count_0000_guess);
    }
    return 0;
}

// Compass window: deletes marker `index` from the marker list (+0x1AC) when it is in range. Used by the
// remove-by-value helper (0x004F9DA6), which expeditions and tasks call to take their markers away.
// FUNCTION: TITANIUM 0x004F9D8F
void CCompassWnd_guess::RemoveMarkerAt_guess(int index) {
    if (index < member_01ac_guess.count_0000_guess) {
        member_01ac_guess.DeleteElement_guess(index);
    }
}

// Removes the first compass marker whose value is `value_guess` (0x004F9D8F); nothing if none matches.
// FUNCTION: TITANIUM 0x004F9DA6
void CCompassWnd_guess::RemoveMarker_guess(int value_guess) {
    int index_guess = 0;
    if (member_01ac_guess.count_0000_guess > 0) {
        do {
            if (*member_01ac_guess.FUN_004eb924_guess(index_guess) == value_guess) {
                RemoveMarkerAt_guess(index_guess);
                return;
            }
            ++index_guess;
        } while (index_guess < member_01ac_guess.count_0000_guess);
    }
}

// Destructor of the compass window (vtable 0x653000): frees the marker list (+0x1AC), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004F9DDC
CCompassWnd_guess::~CCompassWnd_guess()  {
}

// Picks a new random needle target: the spread shrinks from a full turn at skill 0 to none at 200, and the
// error is at least 51 - skill/5 units either way. At 200 the needle is exact.
// FUNCTION: TITANIUM 0x004F9DF8
// @early-stop: budget, diff ndiff=24
int CCompassWnd_guess::CalculateNeedleVariation_guess() {
    int max_guess = 200;
    int level_guess;
    if (g_charView_guess == 0) {
        level_guess = 1;
    } else {
        CHARINFO2* info_guess = g_charView_guess->Info_guess();
        level_guess = info_guess->tail_0f70_guess.field_1010_guess;
        int tail_guess = (int)&info_guess->tail_0f70_guess;
        if (level_guess >= max_guess) {
            value_0164_guess = 0;
            return tail_guess;
        }
    }
    int range_guess = ((max_guess - level_guess) * 0x200) / max_guess;
    value_0164_guess = rand() % range_guess - range_guess / 2;
    int limit_guess = 0x33 - level_guess / 5;
    int result_guess = FUN_0060f81e_guess(value_0164_guess);
    if (result_guess < limit_guess) {
        value_0164_guess = (value_0164_guess >= 0 ? 1 : -1) * limit_guess;
        return value_0164_guess;
    }
    return result_guess;
}

// Scalar deleting destructor of the compass window (vtable 0x653000 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x004F9E91
CCompassWnd_guess* CCompassWnd_guess::DeletingDestructor_guess(unsigned char flags_guess) {
    this->CCompassWnd_guess::~CCompassWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Per frame: moves the needle toward its target unless skill is 200, scrolls both strips to the heading
// (180 pixels per strip, wrapped), and places each marker by its bearing; only the front half is drawn.
// The `== 0` reset of the settle timer is a no-op kept for the match.
// FUNCTION: TITANIUM 0x004F9EB5
// @early-stop: budget, structural ndiff=75
void CCompassWnd_guess::OnProcessFrame_guess() {
    int previousFrame_guess = g_compassClock_guess->frame_0148_guess;

    if (Show != 0 && g_charView_guess != 0) {
        if (value_0178_guess <= 0) {
            int level_guess = g_charView_guess->Info_guess()->tail_0f70_guess.field_1010_guess;
            if (level_guess < 200) {
                int elapsed_guess = previousFrame_guess - value_016c_guess;
                int movement_guess = (int)(elapsed_guess * value_0170_guess * g_compassTurn_guess);
                int difference_guess = FUN_0060f81e_guess(value_0164_guess - value_0168_guess);

                if (difference_guess < movement_guess) {
                    value_0168_guess = value_0164_guess;
                    CalculateNeedleVariation_guess();
                } else {
                    value_0168_guess += movement_guess;
                    if (value_0168_guess > 0x100) {
                        value_0168_guess -= 0x200;
                    } else if (value_0168_guess < -0x100) {
                        value_0168_guess += 0x200;
                    }
                }
                UpdateNeedleSpeed_guess();
            } else {
                value_0168_guess = 0;
            }
        }

        int phase_guess = ((int)g_compassState_guess->heading_004c_guess + value_0168_guess) % 0x200;
        int index_guess = (int)((double)phase_guess * g_compassScale_guess - g_compassOffset_guess) + 0x2f;
        if (index_guess > 0) {
            index_guess += ((unsigned)(index_guess - 1) / 0xb4) * -0xb4 - 0xb4;
        }

        int rect_guess[2];
        rect_guess[1] = 0;
        if (strip1_015c_guess != 0) {
            rect_guess[0] = index_guess;
            ((CompassStrip_guess*)strip1_015c_guess)->inner_0048_guess.GetSize_guess(rect_guess);
        }
        rect_guess[0] = index_guess + 0xb4;
        if (strip2_0160_guess != 0) {
            ((CompassStrip_guess*)strip2_0160_guess)->inner_0048_guess.GetSize_guess(rect_guess);
        }

        int index = 0;
        if (member_01ac_guess.count_0000_guess > 0) {
            do {
                if (((CompassMarker_guess*)*member_01ac_guess.FUN_004eb924_guess(index))->Invoke_guess() != 0) {
                    float x_guess;
                    float y_guess;
                    float z_guess;
                    ((PointSource_guess*)*member_01ac_guess.FUN_004eb924_guess(index))->Fill_guess(
                        &x_guess, &y_guess, &z_guess);

                    float relative_guess = g_compassState_guess->heading_004c_guess -
                        g_compassHeading_guess->GetHeading_guess(
                            y_guess - g_compassState_guess->y_0034_guess,
                            x_guess - g_compassState_guess->x_0030_guess, &rect_guess[1]) + g_compassBias_guess;
                    if (relative_guess > g_compassFullCircle_guess) {
                        relative_guess -= g_compassFullCircle_guess;
                    }
                    if (relative_guess < g_compassZero_guess) {
                        relative_guess += g_compassFullCircle_guess;
                    }

                    ((CompassMarker_guess*)*member_01ac_guess.FUN_004eb924_guess(index))->flag_0020_guess =
                        (relative_guess < g_compassHalfCircle_guess);
                    ((CompassMarker_guess*)*member_01ac_guess.FUN_004eb924_guess(index))->x_001c_guess =
                        (int)(relative_guess * g_compassTimeScale_guess * g_compassTimeBias_guess + g_compassTimeOffset_guess);
                }
                ++index;
            } while (index < member_01ac_guess.count_0000_guess);
        }
    }

    value_0178_guess += value_016c_guess - previousFrame_guess;
    if (value_0178_guess == 0) {
        value_0178_guess = 0;
    }
    value_016c_guess = previousFrame_guess;
    OnProcessFrame();
}

// Appends a marker and returns its index.
// FUNCTION: TITANIUM 0x004FA167
int CCompassWnd_guess::AddMarker_guess(int value_guess) {
    member_01ac_guess.FUN_0050319b_guess(member_01ac_guess.count_0000_guess, &value_guess);
    return member_01ac_guess.count_0000_guess - 1;
}

// The built-in marker is blue (0, 0, 255) with its own visibility callback.
// FUNCTION: TITANIUM 0x004FA183
// @early-stop: budget, structural ndiff=4
CCompassWnd_guess::CCompassWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "CompassWindow", -1, 1, 0) {
    strip1_015c_guess = 0;
    strip2_0160_guess = 0;
    if (SidlPiece != 0) {
        CompassMarker_guess* element_guess = &element_017c_guess;
        element_guess->r_0000_guess = 0;
        element_guess->g_0004_guess = 0;
        element_guess->b_0008_guess = 0xff;
        fnptr_01a8_guess = FUN_004f9bf0_guess;
        element_guess->callback_0024_guess = FUN_004f9bea_guess;
        element_guess->argument_0028_guess = 0;
        AddMarker_guess((int)element_guess);
        field_018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        strip1_015c_guess = GetChildLabel_guess("CompassStrip1");
        strip2_0160_guess = GetChildLabel_guess("CompassStrip2");
        value_0168_guess = 0;
        value_016c_guess = 0;
        value_0178_guess = 0;
    }
}

// Destructor of the client's growable array: frees the element buffer and zeroes the pointer, capacity
// and count. Shared by many owners (window lists, compass markers, menu nodes, rule sets).
// FUNCTION: TITANIUM 0x0050F3F6
FUN_0050f3f6_guess::~FUN_0050f3f6_guess() {
    if (data_guess != 0) {
        FreeArray_guess(data_guess);
    }
    data_guess = 0;
    extra_guess = 0;
    count_0000_guess = 0;
}
