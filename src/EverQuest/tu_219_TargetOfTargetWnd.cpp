// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 219: a hint from compare/tumap.py.
// The end of CSystemInfoDialogBox (its ctor 0x0055B4D1 is in another file) and CTargetOfTargetWnd's ctor.
// Handler_guess is a view, not one class: the size (0x168) and the two child pointers at
// +0x15C/+0x160
// fit both windows. The click handler is the system-info dialog's (Yes/No buttons); 0x0055B709 is
// probably the target-of-target window's frame update, since its ctor primes +0x164 with 0x12.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct Settings_guess {
    // EXTERNAL: TITANIUM 0x004AE5AF Settings_guess::SetValue_guess
    void SetValue_guess(int value, const char* section, const char* key);
    // EXTERNAL: TITANIUM 0x00493BEA Settings_guess::SendSystemInfo_guess
    void SendSystemInfo_guess();
};

#define g_settings_guess EQ_GLOBAL(Settings_guess*, 0x00988DF0)
#define g_sendSystemInfo_guess EQ_GLOBAL(char, 0x009254EE)

struct EnvironmentPart_guess {
    char pad_guess[0x198];
    int state_guess;
};

struct Environment_guess {
    char pad_guess[0x1a8];
    EnvironmentPart_guess* part_guess;
};

#define g_environment_guess EQ_GLOBAL(Environment_guess*, 0x00905CE4)

struct StateSink_guess {
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
    virtual void Slot48_guess(bool state, int notify);
};

// EXTERNAL: TITANIUM 0x0059DD30 FUN_0059dd30_guess
char __cdecl FUN_0059dd30_guess();

struct Handler_guess {
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
    // EXTERNAL: TITANIUM 0x005A0E50 Handler_guess::OnProcessFrame
    void OnProcessFrame();
    void OnYes_guess();
    void OnNo_guess();
    // EXTERNAL: TITANIUM 0x005A2230 Handler_guess::WndNotification
    int WndNotification(StateSink_guess* sender_guess, int message_guess, void* data_guess);
    int WndNotification_guess(StateSink_guess* sender_guess, int message_guess, void* data_guess);
    void OnProcessFrame_guess();
    char pad_guess[0x158];
    StateSink_guess* firstSink_guess;
    StateSink_guess* secondSink_guess;
    int lastState_guess;
};

// Opts in to sending system info: sets 0x009254EE (the options window's SendSystemInfo flag), saves
// [Defaults] SendSystemInfo=1, then runs pEverQuest's 0x00493BEA, probably the report itself.
// FUNCTION: TITANIUM 0x0055B65F
void EnableSendSystemInfo_guess() {
    g_sendSystemInfo_guess = 1;
    g_settings_guess->SetValue_guess(1, "Defaults", "SendSystemInfo");
    return g_settings_guess->SendSystemInfo_guess();
}

// Opts out; unlike EnableSendSystemInfo_guess it sends nothing.
// FUNCTION: TITANIUM 0x0055B688
void DisableSendSystemInfo_guess() {
    g_sendSystemInfo_guess = 0;
    g_settings_guess->SetValue_guess(0, "Defaults", "SendSystemInfo");
}

// Yes button: enables sending system info, then Deactivate (vtable slot 34).
// FUNCTION: TITANIUM 0x0055B6A7
void Handler_guess::OnYes_guess() {
    EnableSendSystemInfo_guess();
    return Slot34_guess();
}

// No button: disable, then close as above.
// FUNCTION: TITANIUM 0x0055B6BA
void Handler_guess::OnNo_guess() {
    DisableSendSystemInfo_guess();
    return Slot34_guess();
}

// WndNotification: a click (message 1) on the first or second button answers the dialog; everything
// else goes to the base handler (0x005A2230).
// FUNCTION: TITANIUM 0x0055B6CD
int Handler_guess::WndNotification_guess(StateSink_guess* sender_guess, int message_guess, void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == firstSink_guess) {
            OnYes_guess();
            return 0;
        }
        if (sender_guess == secondSink_guess) {
            OnNo_guess();
            return 0;
        }
    }
    return WndNotification(sender_guess, message_guess, data_guess);
}

// OnProcessFrame (base 0x005A0E50 is CXWnd::OnProcessFrame). While visible, shows or hides both child
// windows (slot 48, probably CXWnd::Show(bool, bool)) when the int at pinstLocalPlayer +0x1A8 -> +0x198
// changes; the 0x12 the ctor stores in lastState_guess forces the first update.
// FUNCTION: TITANIUM 0x0055B709
void Handler_guess::OnProcessFrame_guess() {
    if (FUN_0059dd30_guess()) {
        int state_guess = g_environment_guess->part_guess->state_guess;
        if (lastState_guess != state_guess) {
            if (firstSink_guess != 0) {
                firstSink_guess->Slot48_guess(state_guess != 0, 1);
            }
            if (secondSink_guess != 0) {
                secondSink_guess->Slot48_guess(state_guess != 0, 1);
            }
            lastState_guess = state_guess;
        }
    }
    return OnProcessFrame();
}

#include "titanium/layouts/ui.h"

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065D548 ??_7TargetOfTargetWnd_guess@@6B@
struct TargetOfTargetWnd_guess : CSidlScreenWndBase {
    CXWnd* hpLabel_15c;             // 0x15C "TargetOfTarget_HPLabel"
    CXWnd* hpPercLabel_160;         // 0x160 "TargetOfTarget_HPPercLabel"
    int field_164_guess;            // 0x164
    TargetOfTargetWnd_guess(CXWnd* parent);
};

// Screen TargetOfTargetWindow; finds the HP and HP-percent labels. 0x800 is added to the SIDL style.
// FUNCTION: TITANIUM 0x0055B772
TargetOfTargetWnd_guess::TargetOfTargetWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "TargetOfTargetWindow", -1, 1, 0) {
    hpPercLabel_160 = 0;
    hpLabel_15c = 0;
    field_164_guess = 0x12;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        field_018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        hpPercLabel_160 = ((CSidlScreenWnd*)this)->GetChildItem("TargetOfTarget_HPPercLabel");
        hpLabel_15c = ((CSidlScreenWnd*)this)->GetChildItem("TargetOfTarget_HPLabel");
    }
}

