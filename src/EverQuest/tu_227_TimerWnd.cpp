// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 227: a hint from compare/tumap.py.
// A screen-wide countdown drawn at the top right (vtable 0x65E800, pointer 0x850C94), probably CTimeLeftWnd
// (Mac match on its Draw): tu_029 creates it when the end time at 0x985840 is set. CTimeLeftWnd_guess is that
// window; g_clock_guess is CDisplay (+0x148 ms clock), g_timerSettings_guess the CXWndManager (0x99D3EC).
#include "titanium/eqaddr.h"

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

struct Rect_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_c_guess;
};

struct RectValue_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_c_guess;

    RectValue_guess(int first_guess, int second_guess,
        int third_guess, int fourth_guess)
        : field_0_guess(first_guess), field_4_guess(second_guess),
          field_8_guess(third_guess), field_c_guess(fourth_guess) {}
};

struct Str_guess {
    char* text_guess;
    // EXTERNAL: TITANIUM 0x004482FB Str_guess::~Str_guess
    ~Str_guess();
};

struct CTextureFont_guess {
    // EXTERNAL: TITANIUM 0x005A3A00 CTextureFont_guess::Measure_guess
    int Measure_guess(Str_guess* text_guess);
};

struct TextWnd_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(Str_guess* text_guess);
    virtual void Slot02_guess(int first_guess, int second_guess, int third_guess,
        int fourth_guess, Rect_guess* rect_guess, int color_guess,
        int fifth_guess, int sixth_guess);
};

struct Service_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual TextWnd_guess* Slot13_guess();
    virtual void Slot14_guess(TextWnd_guess* window_guess);
};

struct Display_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(TextWnd_guess* window_guess);
};

struct CDisplayView_guess {
    char pad_0000_guess[0x148];
    unsigned int tick_guess; // 0x148
};

#define g_clock_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x0099E364)
#define g_service_guess EQ_GLOBAL(Service_guess*, 0x0099E360)

// EXTERNAL: TITANIUM 0x005A0710 GetScreenRect_guess
void __stdcall GetScreenRect_guess(Rect_guess* rect_guess);

// EXTERNAL: TITANIUM 0x00405492 ThrowSelf_guess
__declspec(noreturn) void __cdecl ThrowSelf_guess();

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(Str_guess* text_guess, const char* format_guess, ...);

struct WidgetBase_guess {
    // EXTERNAL: TITANIUM 0x00525E53 WidgetBase_guess::WidgetBase_guess
    WidgetBase_guess(int first_guess, int second_guess,
        RectValue_guess rect_guess, int fourth_guess);
    // EXTERNAL: TITANIUM 0x00525E7E ??1WidgetBase_guess@@UAE@XZ
    virtual ~WidgetBase_guess();
};

struct CXWndManagerView_guess {
    char pad_0000_guess[0xf4];
    int fontCount_00f4_guess;       // 0xf4
    void* fonts_00f8_guess;   // 0xf8
};

struct SetupObject_guess {
    char pad_0000_guess[0x18];
    void* field_18_guess; // 0x18
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x0065E800 ??_7CTimeLeftWnd_guess@@6B@
struct CTimeLeftWnd_guess : WidgetBase_guess {
    char pad_0000_guess[0x64];
    CTextureFont_guess* measureSource_guess; // 0x68
    char pad_006c_guess[0x128 - 0x6c];
    int lastTick_guess;            // 0x128
    int endTick_guess;             // 0x12c
    Str_guess text_guess;          // 0x130
    int color_guess;               // 0x134
    TextWnd_guess* textWnd_guess;  // 0x138

    ~CTimeLeftWnd_guess();

    CTimeLeftWnd_guess* Delete_guess(unsigned int flags_guess);

    // EXTERNAL: TITANIUM 0x0059D6C0 CTimeLeftWnd_guess::GetClientClipRect
    Rect_guess* GetClientClipRect(Rect_guess* rect_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 CTimeLeftWnd_guess::IsReady_guess
    char IsReady_guess();

    int Draw_guess();
    int UpdateCaption_guess();

    // EXTERNAL: TITANIUM 0x00407A38 CTimeLeftWnd_guess::SetDrawTemplate_guess
    void SetDrawTemplate_guess(void* object_guess);
    // EXTERNAL: TITANIUM 0x0059DB90 CTimeLeftWnd_guess::SetState_guess
    void SetState_guess(int state_guess);

    CTimeLeftWnd_guess(int duration_guess);
};

// Releases the text sprite (0x99E360 slot 14); the caption CXStr and CXWnd base follow.
// FUNCTION: TITANIUM 0x00563E2A
CTimeLeftWnd_guess::~CTimeLeftWnd_guess() {
    g_service_guess->Slot14_guess(textWnd_guess);
}

// Draw: right-aligns the caption against the screen clip rect and draws it in the current colour
// (sprite from 0x99E360, drawn by 0x99E364 slot 30).
// FUNCTION: TITANIUM 0x00563E80
int CTimeLeftWnd_guess::Draw_guess() {
    Rect_guess screen_guess;
    Rect_guess rect_guess;
    GetScreenRect_guess(&screen_guess);
    int x_guess = screen_guess.field_8_guess -
        measureSource_guess->Measure_guess(&text_guess);
    textWnd_guess->Slot01_guess(&text_guess);
    int width_guess = screen_guess.field_8_guess - screen_guess.field_0_guess;
    TextWnd_guess* wnd_guess = textWnd_guess;
    wnd_guess->Slot02_guess(2, x_guess, 0, width_guess,
        GetClientClipRect(&rect_guess), color_guess, 0, 0);
    g_display_guess->Slot30_guess(textWnd_guess);
    return 0;
}

// Every 500 ms while visible, rewrites the caption as h:mm:ss left: green from 30 minutes, yellow from 1
// minute, red below.
// FUNCTION: TITANIUM 0x00563F04
int CTimeLeftWnd_guess::UpdateCaption_guess() {
    if (IsReady_guess()) {
        int now_guess = g_clock_guess->tick_guess;
        if (now_guess - lastTick_guess >= 500) {
            lastTick_guess = now_guess;
            int seconds_guess = (endTick_guess - now_guess) / 1000;
            if (seconds_guess < 0) {
                seconds_guess = 0;
            }
            int hours_guess = seconds_guess / 3600;
            int minutes_guess = seconds_guess / 60 % 60;
            FormatString_guess(&text_guess, "%d:%02d:%02d", hours_guess,
                minutes_guess, seconds_guess % 60);
            if (hours_guess < 1 && minutes_guess < 30) {
                // ARGB yellow; 0xFFFF0000 red, 0xFF00FF00 green.
                color_guess = (minutes_guess >= 1) ? 0xFFFFFF00 : 0xFFFF0000;
            } else {
                color_guess = 0xFF00FF00;
            }
        }
    }
    return 0;
}

// Counts down `duration_guess` seconds over a 640x480 window in font 6 of the window manager's font
// list (+0xF4 count, +0xF8 array), throwing (0x405492) when there are 6 fonts or fewer.
// FUNCTION: TITANIUM 0x00563FBB
// @early-stop: unknown, structural ndiff=37
CTimeLeftWnd_guess::CTimeLeftWnd_guess(int duration_guess)
    : WidgetBase_guess(0, 0,
        RectValue_guess(0, 0, 0x280, 0x1e0), 0) {
    text_guess.text_guess = 0;
    lastTick_guess = g_clock_guess->tick_guess;
    endTick_guess = duration_guess * 1000 + g_clock_guess->tick_guess;
    if (pinstCXWndManager_guess->fontCount_00f4_guess > 6 &&
        pinstCXWndManager_guess->fonts_00f8_guess != 0) {
        SetDrawTemplate_guess(((SetupObject_guess*)pinstCXWndManager_guess->fonts_00f8_guess)->field_18_guess);
        // Z layer 999, above the other windows (0x59DB90, Mac SetZLayer, low).
        SetState_guess(0x3e7);
        textWnd_guess = g_service_guess->Slot13_guess();
        return;
    }
    ThrowSelf_guess();
}

// Scalar deleting destructor.
// FUNCTION: TITANIUM 0x00564089
CTimeLeftWnd_guess* CTimeLeftWnd_guess::Delete_guess(unsigned int flags_guess) {
    this->CTimeLeftWnd_guess::~CTimeLeftWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}
