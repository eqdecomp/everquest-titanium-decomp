// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 135: a hint from compare/tumap.py.
// CBreathWnd (screen "BreathWindow", vtable 0x651498): the breath meter shown while the player can't
// breathe. Wnd_guess and Breath_guess are CBreathWnd; g_outer_guess is pCharData, g_clock_guess CDisplay.
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct Object_guess {
    // EXTERNAL: TITANIUM 0x004E877F Object_guess::~Object_guess
    ~Object_guess();
    void* Delete_guess(unsigned char flags);
};

// Scalar deleting destructor around 0x4E877F, which writes vtable 0x651358 (CBookWnd in the first-pass name list), so
// probably CBookWnd's rather than CBreathWnd's.
// FUNCTION: TITANIUM 0x004E88C1
void* Object_guess::Delete_guess(unsigned char flags) {
    this->~Object_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

struct Inner_guess {
    // EXTERNAL: TITANIUM 0x0041A753 Inner_guess::CanBreathe_guess
    unsigned char CanBreathe_guess();
};

struct EQ_CharacterView_guess {
    char pad_0000_guess[0xC280];
    Inner_guess inner_c280_guess;
};

struct Clock_guess {
    char pad_0000_guess[0x148];
    unsigned int tick_guess; // 0x148
};

#define g_outer_guess EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)
#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)

struct Wnd_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(int first_guess, int second_guess);

    char pad_0004_guess[0x58];       // 0x04
    unsigned char flag_5c_guess;     // 0x5C
    char pad_005d_guess[0xFF];       // 0x5D
    unsigned int time_15c_guess;     // 0x15C

    // EXTERNAL: TITANIUM 0x005A0E50 Wnd_guess::OnProcessFrame
    void OnProcessFrame();

    bool AboutToShow_guess();
    void OnProcessFrame_guess();
};

// Activate (vtable slot 49): restarts the 500 ms check clock.
// FUNCTION: TITANIUM 0x004E88DD
bool Wnd_guess::AboutToShow_guess() {
    time_15c_guess = g_clock_guess->tick_guess;
    return true;
}

// OnProcessFrame: every 500 ms shows the window when the player can't breathe and hides it when they can,
// then CXWnd::OnProcessFrame.
// FUNCTION: TITANIUM 0x004E88F1
void Wnd_guess::OnProcessFrame_guess() {
    if (g_clock_guess->tick_guess > time_15c_guess + 500) {
        // 0x41A753 on pCharData +0xC280 (tu_013): not underwater, a water-breathing race, or a Water
        // Breathing effect (spell effect 14).
        int check_guess = g_outer_guess->inner_c280_guess.CanBreathe_guess();
        if ((flag_5c_guess == 0) & (check_guess == 0)) {
            Slot48_guess(1, 1);
        } else if (check_guess == 1 && flag_5c_guess != 0) {
            Slot48_guess(0, 1);
        }
        time_15c_guess = g_clock_guess->tick_guess;
    }
    return OnProcessFrame();
}

struct Breath_guess : CSidlScreenWndBase {
    unsigned int lastUpdateTick_15c_guess;         // 0x15C
    Breath_guess(void* parent_guess);
};

// EXTERNAL: TITANIUM 0x00651498 ??_7Breath_guess@@6B@

// Mac: CBreathWnd::CBreathWnd. Takes the template's style, builds the children and records the display tick
// (+0x15C) for the 500 ms check.
// FUNCTION: TITANIUM 0x004E896D
Breath_guess::Breath_guess(void* parent_guess)
    : CSidlScreenWndBase((CXWnd*)parent_guess, "BreathWindow") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        lastUpdateTick_15c_guess = g_clock_guess->tick_guess;
        field_018_guess = 0;
    }
}
