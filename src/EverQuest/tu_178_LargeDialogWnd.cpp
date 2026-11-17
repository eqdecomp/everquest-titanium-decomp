// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 178: a hint from compare/tumap.py.
// The large dialog window (LargeDialogWindow: text, OK or Yes/No, and mute/replay/volume controls for an MP3
// that plays with it), plus the label that tracks an EQ label value. The Object_005261bf/0052613b/005260fe
// views are all this window; the MP3 plays through the EQ sound manager at 0x851390.
#include "titanium/types.h"

struct Object_00525e7e_guess {
    char* vtable;
    void* release_guess(unsigned char freeMemory);
};

#define g_vtable_00525e7e_guess EQ_GLOBAL(char, 0x00657100)

// EXTERNAL: TITANIUM 0x005BD640 FUN_005bd640_guess
void __cdecl FUN_005bd640_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// A destructor body: restores this class's vtable, then runs the base window cleanup.
// FUNCTION: TITANIUM 0x00525E7E
void __fastcall FUN_00525e7e_guess(Object_00525e7e_guess* object) {
    object->vtable = &g_vtable_00525e7e_guess;
    FUN_005bd640_guess();
}

// EXTERNAL: TITANIUM 0x00525E7E FUN_00525e7e_external_guess
void __fastcall FUN_00525e7e_external_guess(Object_00525e7e_guess* object);

// Scalar deleting destructor of the window with vtable 0x657100 (constructor tail 0x00525E53): runs its
// destructor (0x00525E7E) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00525F53
void* Object_00525e7e_guess::release_guess(unsigned char freeMemory) {
    FUN_00525e7e_external_guess(this);
    if ((freeMemory & 1) != 0) {
        free(this);
    }
    return this;
}

struct Object_005260fe_guess {
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
    virtual void Slot48_guess(int first, int second);
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
    virtual void Slot63_guess();
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    char unknown_004[0x178];
    unsigned int autoCloseDeadline_17c_guess;
    void CheckAutoClose_guess();
};

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

// Per frame: past the deadline (+0x17C, ms) the dialog closes itself (the close hook, then hide).
// FUNCTION: TITANIUM 0x005260FE
void Object_005260fe_guess::CheckAutoClose_guess() {
    unsigned int now = FUN_0046d655_guess();
    if (autoCloseDeadline_17c_guess != 0 && now > autoCloseDeadline_17c_guess) {
        Slot75_guess();
        Slot48_guess(0, 1);
        autoCloseDeadline_17c_guess = 0;
    }
    ((CXWnd*)this)->OnProcessFrame();
}

struct Object_0052618c_guess {
    char unknown_000[0x15c];
    unsigned int unknown_15c;
    unsigned int unknown_160;
    unsigned int unknown_164;
    unsigned int unknown_168;
    unsigned int unknown_16c;
    unsigned int unknown_170;
    unsigned int unknown_174;
    unsigned int unknown_178;
};

struct Object_0052613b_child_guess {
    char unknown_000[0x128];
    char unknown_128;
};

struct Object_0052613b_value_guess {
    int Value_guess();
    // EXTERNAL: TITANIUM 0x005BD180 Object_0052613b_value_guess::Notify_guess
    void Notify_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005BCD10 Object_0052613b_value_guess::SetValue_guess
    void SetValue_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x005BCB90 Object_0052613b_value_guess::Value_guess

struct Object_0052613b_guess {
    char unknown_000[0x16c];
    Object_0052613b_child_guess* child_16c;
    unsigned int unknown_170;
    Object_0052613b_value_guess* value_174;
    float GetMp3Volume_guess();
};

// MP3 volume from the slider (0-100 percent); 0.01 when muted or at zero, never fully silent.
// FUNCTION: TITANIUM 0x0052613B
float Object_0052613b_guess::GetMp3Volume_guess() {
    float scale = 1.0f;
    if (child_16c == 0 || child_16c->unknown_128 == 0) {
        if (value_174 != 0) {
            int value = value_174->Value_guess();
            float scaled = value * 0.01f;
            if (scaled != 0.0f) {
                scale = scaled;
            } else {
                scale = 0.01f;
            }
        }
    } else {
        scale = 0.01f;
    }
    return scale;
}

// Clears the eight child pointers (+0x15C..+0x178) before the SIDL lookup.
// FUNCTION: TITANIUM 0x0052618C
void __fastcall ClearChildWindowPointers_guess(Object_0052618c_guess* object) {
    object->unknown_15c = 0;
    object->unknown_160 = 0;
    object->unknown_164 = 0;
    object->unknown_168 = 0;
    object->unknown_16c = 0;
    object->unknown_170 = 0;
    object->unknown_174 = 0;
    object->unknown_178 = 0;
}

struct Object_005261bf_guess {
    char unknown_000[0x15c];
    CXWnd* textBox_15c;
    CXWnd* okButton_160;
    CXWnd* yesButton_164;
    CXWnd* noButton_168;
    CXWnd* muteButton_16c;
    CXWnd* replayButton_170;
    CXWnd* soundVolumeSlider_174;
    CXWnd* soundVolumeValueLabel_178;
    unsigned int unknown_17c_guess;
    bool flag_180_guess;
    void Init_guess();
    void Refresh_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

// Finds the LDW_ controls: text box, OK, Yes, No, Mute, Replay, the sound volume slider and its label.
// FUNCTION: TITANIUM 0x005261BF
void Object_005261bf_guess::Init_guess() {
    textBox_15c = ((CSidlScreenWnd*)this)->GetChildItem("LDW_TextBox");
    okButton_160 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_OkButton");
    yesButton_164 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_YesButton");
    noButton_168 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_NoButton");
    muteButton_16c = ((CSidlScreenWnd*)this)->GetChildItem("LDW_MuteButton");
    replayButton_170 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_ReplayButton");
    soundVolumeSlider_174 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_SoundVolumeSlider");
    soundVolumeValueLabel_178 = ((CSidlScreenWnd*)this)->GetChildItem("LDW_SoundVolumeValueLabel");
}

struct Window_guess {
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
    virtual void Slot48_guess(bool first, bool second);
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
    virtual void Slot63_guess(const CXStr& text);
};

// EXTERNAL: TITANIUM 0x00559FB3 GetLabelFromEQ
void __cdecl GetLabelFromEQ(int count, CXStr* key, bool* flag, int* value);

// Temporary returned by value by GetText_guess: a CXStr with its inline dtor.
struct TextRef_00525e89_guess {
    CStrRep* Ptr;
    // EXTERNAL: TITANIUM 0x00573B10 TextRef_00525e89_guess::Match_guess
    int Match_guess(CXStr* key, int mode);
    // EXTERNAL: TITANIUM 0x00571D00 TextRef_00525e89_guess::FreeRep
    void FreeRep(CStrRep* rep);
    ~TextRef_00525e89_guess() {
        if (Ptr != 0) {
            FreeRep(Ptr);
        }
        Ptr = 0;
    }
};

struct Object_00525e89_guess : Window_guess {
    char unknown_004[0x78];
    int value_07c;
    char unknown_080[0xa4];
    int count_124;
    // EXTERNAL: TITANIUM 0x004D22D7 Object_00525e89_guess::GetText_guess
    TextRef_00525e89_guess GetText_guess();
    void Update_guess();
};

// Label tied to an EQ label value (type at +0x124, from GetLabelFromEQ): re-sets the text when it or the
// stored value changed.
// FUNCTION: TITANIUM 0x00525E89
void Object_00525e89_guess::Update_guess() {
    if (count_124 > 0) {
        CXStr key;
        bool flag;
        int value;
        GetLabelFromEQ(count_124, &key, &flag, &value);
        bool changed = GetText_guess().Match_guess(&key, 0) != 0 || value_07c != value;
        if (changed) {
            Slot63_guess(key);
            if (flag) {
                value_07c = value;
            }
        }
    }
}

// Same children as Object_005261bf_guess (+0x15C..+0x178) and the deadline at +0x17C; the base gives the vtable.
struct Dialog_00525fbc_guess : Window_guess {
    char unknown_004[0x158];
    CXWnd* textBox_15c;
    Window_guess* okButton_160;
    Window_guess* yesButton_164;
    Window_guess* noButton_168;
    Window_guess* muteButton_16c;
    Window_guess* replayButton_170;
    Window_guess* soundVolumeSlider_174;
    Window_guess* soundVolumeValueLabel_178;
    unsigned int timer_17c;
    void SetDialog_guess(bool flag, CXStr text, unsigned int timeout, CXStr title, bool value);
};

struct SidlPiece_005264bf_guess {
    char pad_0000[0x60];
    unsigned int style_060;                 // 0x060
};

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct LargeDialogBase_guess {
    virtual void Slot00_guess();
    char pad_0004[0x14];
    unsigned char flag_018;                 // 0x018
    char pad_0019[0x4b];
    unsigned int windowStyle_064;           // 0x064 (CXWnd::WindowStyle)
    char pad_0068[0xbc];
    SidlPiece_005264bf_guess* sidlPiece_124; // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_0128[0x54];
    int field_17c;                          // 0x17c
    // EXTERNAL: TITANIUM 0x005A3850 ??0LargeDialogBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    LargeDialogBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1LargeDialogBase_guess@@QAE@XZ
    ~LargeDialogBase_guess();
};

// EXTERNAL: TITANIUM 0x00657230 ??_7LargeDialog_guess@@6B@
struct LargeDialog_guess : LargeDialogBase_guess {
    LargeDialog_guess(CXWnd* parent);
    ~LargeDialog_guess();
    void* release_guess(unsigned char freeMemory);
};

struct Logger_guess {
    // EXTERNAL: TITANIUM 0x0044B741 Logger_guess::PlayMp3_guess
    void PlayMp3_guess(const char* text, float amount);
};

#define g_logger_guess EQ_GLOBAL(Logger_guess*, 0x00851390)

// Stops the dialog's MP3 by playing an empty name.
// FUNCTION: TITANIUM 0x00525F6F
LargeDialog_guess::~LargeDialog_guess() {
    if (g_logger_guess != 0) {
        g_logger_guess->PlayMp3_guess(EQ_ARRAY(char, 0x0063F53F), 1.0f);
    }
}

// Shows the dialog: `flag` picks Yes/No over OK, `value` shows the sound controls, `timeout` (ms) arms the
// auto-close deadline (0 = none).
// FUNCTION: TITANIUM 0x00525FBC
void Dialog_00525fbc_guess::SetDialog_guess(bool flag, CXStr text, unsigned int timeout, CXStr title, bool value) {
    Slot48_guess(0, 1);
    Slot63_guess(title);
    if (textBox_15c != 0) {
        textBox_15c->SetWindowTextA(text);
    }
    if (okButton_160 != 0) {
        okButton_160->Slot48_guess(!flag, 1);
    }
    if (yesButton_164 != 0) {
        yesButton_164->Slot48_guess(flag, 1);
    }
    if (noButton_168 != 0) {
        noButton_168->Slot48_guess(flag, 1);
    }
    if (muteButton_16c != 0) {
        muteButton_16c->Slot48_guess(value, 1);
    }
    if (soundVolumeSlider_174 != 0) {
        soundVolumeSlider_174->Slot48_guess(value, 1);
    }
    if (soundVolumeValueLabel_178 != 0) {
        soundVolumeValueLabel_178->Slot48_guess(value, 1);
    }
    if (replayButton_170 != 0) {
        replayButton_170->Slot48_guess(value, 1);
    }
    if (timeout > 0) {
        timer_17c = FUN_0046d655_guess() + timeout;
    } else {
        timer_17c = 0;
    }
    Slot48_guess(1, 1);
}

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* output, const char* format, ...);

// Default state: buttons hidden, sound controls shown, volume 100, label "Vol. 100 %", not muted.
// FUNCTION: TITANIUM 0x005263A0
void Object_005261bf_guess::Refresh_guess() {
    if (okButton_160 != 0) {
        ((Window_guess*)okButton_160)->Slot48_guess(0, 1);
    }
    if (yesButton_164 != 0) {
        ((Window_guess*)yesButton_164)->Slot48_guess(0, 1);
    }
    if (noButton_168 != 0) {
        ((Window_guess*)noButton_168)->Slot48_guess(0, 1);
    }
    if (muteButton_16c != 0) {
        ((Window_guess*)muteButton_16c)->Slot48_guess(1, 1);
    }
    if (replayButton_170 != 0) {
        ((Window_guess*)replayButton_170)->Slot48_guess(1, 1);
    }
    if (soundVolumeSlider_174 != 0) {
        ((Window_guess*)soundVolumeSlider_174)->Slot48_guess(1, 1);
        ((Object_0052613b_value_guess*)soundVolumeSlider_174)->Notify_guess(100);
        ((Object_0052613b_value_guess*)soundVolumeSlider_174)->SetValue_guess(100);
    }
    if (soundVolumeValueLabel_178 != 0) {
        CXStr text;
        FormatString_guess(&text, "Vol. %d %c",
            ((Object_0052613b_value_guess*)soundVolumeSlider_174)->Value_guess(), 0x25);
        ((Window_guess*)soundVolumeValueLabel_178)->Slot48_guess(1, 1);
        ((Window_guess*)soundVolumeValueLabel_178)->Slot63_guess(text);
    }
    flag_180_guess = 0;
}

// Scalar deleting destructor of the large dialog window (vtable 0x657230 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00526558
void* LargeDialog_guess::release_guess(unsigned char freeMemory) {
    this->LargeDialog_guess::~LargeDialog_guess();
    if ((freeMemory & 1) != 0) {
        free(this);
    }
    return this;
}

// Large dialog window constructor: clears the control pointers (0x0052618C), builds the children, finds
// them (0x005261BF) and sets the initial button state (0x005263A0).
// FUNCTION: TITANIUM 0x005264BF
LargeDialog_guess::LargeDialog_guess(CXWnd* parent)
    : LargeDialogBase_guess(parent, "LargeDialogWindow", 0, 1, 0) {
    field_17c = 0;
    ClearChildWindowPointers_guess((Object_0052618c_guess*)this);
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060;
        flag_018 = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        ((Object_005261bf_guess*)this)->Init_guess();
        ((Object_005261bf_guess*)this)->Refresh_guess();
    }
}

struct SoundObject_guess {
    // EXTERNAL: TITANIUM 0x0044A5C6 SoundObject_guess::ReplayMp3_guess
    void ReplayMp3_guess(float value);
    // EXTERNAL: TITANIUM 0x0044A5FE SoundObject_guess::SetMp3Volume_guess
    void SetMp3Volume_guess(float value);
};

#define g_soundObject_guess EQ_GLOBAL(SoundObject_guess*, 0x00851390)

// Yes, No and OK (left click, message 1) run their virtual hooks and hide the window; Replay replays the MP3
// at the slider volume; Mute toggles between 0.01 and the slider volume. Slider moves (0xE) relabel and set
// the volume; close (10) runs the close hook.
// The slider label shows the new value + 1 but the volume uses the value itself, and that path skips the
// null test on the MP3 player that the other paths make.
// FUNCTION: TITANIUM 0x00526574
// @early-stop: unknown, structural ndiff=78
int Object_005261bf_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (sender != 0) {
        if (message == 1) {
            if (sender == yesButton_164) {
                ((Object_005260fe_guess*)this)->Slot73_guess();
            } else if (sender == noButton_168) {
                ((Object_005260fe_guess*)this)->Slot74_guess();
            } else if (sender == okButton_160) {
                ((Object_005260fe_guess*)this)->Slot72_guess();
            } else if (sender == replayButton_170) {
                if (g_soundObject_guess != 0) {
                    g_soundObject_guess->ReplayMp3_guess(((Object_0052613b_guess*)this)->GetMp3Volume_guess());
                }
                return 0;
            } else if (sender == muteButton_16c) {
                flag_180_guess = !flag_180_guess;
                ((CButtonWnd*)muteButton_16c)->SetCheck(flag_180_guess);
                if (((CButtonWnd*)muteButton_16c)->Checked) {
                    if (g_soundObject_guess != 0) {
                        g_soundObject_guess->SetMp3Volume_guess(0.01f);
                    }
                } else {
                    if (g_soundObject_guess != 0) {
                        g_soundObject_guess->SetMp3Volume_guess(((Object_0052613b_guess*)this)->GetMp3Volume_guess());
                    }
                }
                return 0;
            } else {
                return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
            }
            ((Object_005260fe_guess*)this)->Slot48_guess(0, 1);
            return 0;
        } else if (message == 0xe) {
            if (sender == soundVolumeSlider_174) {
                CXStr text;
                FormatString_guess(&text, "Vol. %d %c", (int)data + 1, 0x25);
                if (soundVolumeValueLabel_178 != 0) {
                    ((Window_guess*)soundVolumeValueLabel_178)->Slot63_guess(text);
                }
                g_soundObject_guess->SetMp3Volume_guess(((Object_0052613b_guess*)this)->GetMp3Volume_guess());
            }
            return 0;
        } else if (message == 0xa) {
            ((Object_005260fe_guess*)this)->Slot75_guess();
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

