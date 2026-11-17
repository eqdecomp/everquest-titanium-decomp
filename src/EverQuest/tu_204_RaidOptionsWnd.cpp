// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 204: a hint from compare/tumap.py.
// Two windows share the Owner_guess view (names.tsv has TAKP names for most functions):
// CQuantityWnd, 0x54D702-0x54DB0D (+0x15C result, +0x160 max, +0x164 requester, +0x168 slider, +0x16C edit,
// +0x170 Accept), and CRaidOptionsWnd, 0x54DB7C on ("RaidOptionsWindow": looter list, loot type, 16 class
// colour buttons). g_panel_guess and g_config_guess are CRaid (0x91D708).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CColorPickerWnd.h"
#include "titanium/wnd/CTipWnd.h"

struct Owner_guess;
struct Child_guess;

struct ClassColor_guess {
    char reserved_000_guess[0x7c];
    int value_07c_guess;
};

struct Temp_guess;

struct Nested_guess {
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
    virtual void Slot76_guess();

    // EXTERNAL: TITANIUM 0x0059B9D0 Nested_guess::AddString
    void AddString(Temp_guess* value, int mode, int first, int second);
};

struct Temp_guess {
    int value_000_guess;

    Temp_guess() : value_000_guess(0) {}

    // EXTERNAL: TITANIUM 0x00571E00 Temp_guess::Temp_guess
    Temp_guess(const char* source);

    // EXTERNAL: TITANIUM 0x00571F70 Temp_guess::Assign_guess
    void Assign_guess(const Temp_guess& value);

    // EXTERNAL: TITANIUM 0x00572300 Temp_guess::GetString_guess
    char* GetString_guess();

    // EXTERNAL: TITANIUM 0x00571FC0 Temp_guess::Initialize_guess
    void Initialize_guess(const char* source);

    // EXTERNAL: TITANIUM 0x00571D00 Temp_guess::FreeRep
    void FreeRep(int value);

    ~Temp_guess() {
        if (value_000_guess != 0) {
            FreeRep(value_000_guess);
        }
        value_000_guess = 0;
    }
};

struct Interface_guess {
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
    virtual void Slot48_guess();
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
    virtual void Slot63_guess(Temp_guess* value);
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
    virtual Temp_guess Slot76_guess();

};

struct Support_guess {
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
    virtual void Slot32_guess(Owner_guess* owner, int value, Nested_guess** out);
};

struct CSliderWnd_guess {
    // EXTERNAL: TITANIUM 0x005BCB90 CSliderWnd_guess::GetNested_guess
    Nested_guess* GetNested_guess();

    // EXTERNAL: TITANIUM 0x005BCD10 CSliderWnd_guess::SetValue_guess
    void SetValue_guess(long value);

    // EXTERNAL: TITANIUM 0x005BD180 CSliderWnd_guess::SetCount_guess
    void SetCount_guess(int value);
};

struct Timer_guess {
    char reserved_000_guess[0x148];
    int value_148_guess;
};

struct Display_guess {
    char reserved_000_guess[0xec];
    int width_0ec_guess;
    int height_0f0_guess;
};

struct GraphicsRoot_guess {
    Display_guess* display_000_guess;
};

struct Owner_guess {
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

    char reserved_004_guess[0x58];
    char enabled_05c_guess;
    char reserved_05d_guess[0xc7];
    int state_124_guess;
    char reserved_128_guess[0x34];
    union {
        Nested_guess* nested_15c_guess;
        int mode_15c_guess;
    };
    union {
        int unknown_160_guess;
        int value_160_guess;
    };
    Support_guess* support_164_guess;
    CSliderWnd_guess* provider_168_guess;
    Interface_guess* interface_16c_guess;
    union {
        Child_guess* child_170_guess;
        ClassColor_guess* currentColor_170_guess;
    };
    char reserved_174_guess[0x4];
    ClassColor_guess* classColor_178_guess[16];
    ClassColor_guess* selectedColor_1b8_guess;
    int lastUpdate_1bc_guess;

    // EXTERNAL: TITANIUM 0x005A1880 Owner_guess::Complete_guess
    void Complete_guess();
    void Handle_guess();
    void CheckMaxEditWnd_guess();
    void ClearLooterList_guess();
    void Accept_guess();
    void LoadClassColors_guess();
    void UpdateEditWndFromSlider_guess();
    void UpdateSliderFromEditWnd_guess();
    void Function_0054d976_guess(Support_guess* support, int mode, int value,
                                 int x, int y, char randomize);
    void AddLooterToList_guess(const char* source);
    int WndNotification(int first, int second, int third);
    int Function_0054dca9_guess(ClassColor_guess* color_guess, int type_guess,
                                int value_guess);
    // EXTERNAL: TITANIUM 0x005A2230 Owner_guess::Forward_guess
    int Forward_guess(int first, int second, int third);
    void UpdateLootType_guess();
    void Function_0054e16b_guess();
    int OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 Owner_guess::Function_005a0e50_guess
    int Function_005a0e50_guess();

    // EXTERNAL: TITANIUM 0x0059D860 Owner_guess::GetRect_guess
    CXRect* GetRect_guess(CXRect* value);
    // EXTERNAL: TITANIUM 0x0059FA70 Owner_guess::SetRect_guess
    void SetRect_guess(int* value);
    // EXTERNAL: TITANIUM 0x005A0480 Owner_guess::ClearRect_guess
    void ClearRect_guess();
};

struct GlobalConfig_guess {
    // EXTERNAL: TITANIUM 0x00431136 GlobalConfig_guess::RequestLootType_guess
    void RequestLootType_guess(const char* value);

    // EXTERNAL: TITANIUM 0x004301E4 GlobalConfig_guess::UpdateClassColor_guess
    void UpdateClassColor_guess(int index, int value);
};

struct Child_guess {
    char reserved_000_guess[0x5d];
    char flag_05d_guess;

    // EXTERNAL: TITANIUM 0x0059C360 Child_guess::Method_guess
    void Method_guess(int value);
};

struct CRaid_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 CRaid_guess::IsInRaid_guess
    bool IsInRaid_guess();

    // EXTERNAL: TITANIUM 0x0042FD00 CRaid_guess::IsRaidLeader_guess
    bool IsRaidLeader_guess();

    // EXTERNAL: TITANIUM 0x0042FF8E CRaid_guess::GetLootType_guess
    int GetLootType_guess();

    // EXTERNAL: TITANIUM 0x00430680 CRaid_guess::UpdateOptionsWindow_guess
    void UpdateOptionsWindow_guess();
};

#define g_config_guess EQ_ARRAY(GlobalConfig_guess, 0x0091D708)
#define g_panel_guess EQ_GLOBAL(CRaid_guess, 0x0091D708)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_graphicsRoot_guess EQ_GLOBAL(GraphicsRoot_guess*, 0x0099D334)

// EXTERNAL: TITANIUM 0x005738B0 Format_guess
void __cdecl Format_guess(Temp_guess* out, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* destination_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
                                const char* defaultValue, char* value,
                                int size, char useDefault);

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key,
                                const char* value);

// EXTERNAL: TITANIUM 0x004F898E FUN_004f898e_guess
void __stdcall FUN_004f898e_guess(Owner_guess* owner_guess, int value_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 atol
long __cdecl atol(const char* value);

#define pinstCBazaarWnd_guess EQ_GLOBAL(Support_guess*, 0x00850C58)
#define g_timer_905d24_guess EQ_GLOBAL(Timer_guess*, 0x00905D24)

// CQuantityWnd::CheckMaxEditWnd: clamps a typed amount to the maximum (+0x160).
// FUNCTION: TITANIUM 0x0054D726
void Owner_guess::CheckMaxEditWnd_guess() {
    Temp_guess value_guess;
    value_guess.Assign_guess(interface_16c_guess->Slot76_guess());
    long value = atol(value_guess.GetString_guess());
    int limit = unknown_160_guess;
    if (value > limit) {
        provider_168_guess->SetValue_guess(limit);
        Format_guess(&value_guess, "%d", limit);
        interface_16c_guess->Slot63_guess(&value_guess);
    }
}

// CQuantityWnd::UpdateEditWndFromSlider; for the bazaar window (0x850C58) a 0 shows as blank.
// FUNCTION: TITANIUM 0x0054D7E0
void Owner_guess::UpdateEditWndFromSlider_guess() {
    char text_guess[256];
    if (support_164_guess == pinstCBazaarWnd_guess &&
        provider_168_guess->GetNested_guess() == 0) {
        _sprintf(text_guess, " ");
    } else {
        _sprintf(text_guess, "%d", provider_168_guess->GetNested_guess());
    }
    Temp_guess value_guess(text_guess);
    interface_16c_guess->Slot63_guess(&value_guess);
}

// CQuantityWnd::UpdateSliderFromEditWnd.
// FUNCTION: TITANIUM 0x0054D8AB
void Owner_guess::UpdateSliderFromEditWnd_guess() {
    Temp_guess value_guess;
    value_guess.Assign_guess(interface_16c_guess->Slot76_guess());
    provider_168_guess->SetValue_guess(atol(value_guess.GetString_guess()));
}

// CQuantityWnd::WndNotification: 0xE keeps slider and edit in step; Enter in the edit or the Accept
// button accepts.
// FUNCTION: TITANIUM 0x0054DB0D
int Owner_guess::WndNotification(int first, int second, int third) {
    if (second == 0xe) {
        if (first == (int)provider_168_guess) {
            UpdateEditWndFromSlider_guess();
            return 0;
        }
        if (first == (int)interface_16c_guess) {
            CheckMaxEditWnd_guess();
        }
    } else if (second == 6) {
        if (first == (int)interface_16c_guess) {
            UpdateSliderFromEditWnd_guess();
            Accept_guess();
            return 0;
        }
    } else if (second == 1 && first == (int)child_170_guess) {
        UpdateSliderFromEditWnd_guess();
        Accept_guess();
        return 0;
    }
    return Forward_guess(first, second, third);
}

// CRaidOptionsWnd::AddLooterToList.
// FUNCTION: TITANIUM 0x0054DB7C
void Owner_guess::AddLooterToList_guess(const char* source) {
    if (state_124_guess != 0) {
        Temp_guess value;
        value.Initialize_guess(source);
        nested_15c_guess->AddString(&value, -1, 0, 0);
    }
}

// CQuantityWnd show hook: pops context tip 40 (0x564E7E on 0x9928E0).
// FUNCTION: TITANIUM 0x0054D702
void Owner_guess::Handle_guess() {
    if (enabled_05c_guess != 0 && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x28, 0);
    }
    return Complete_guess();
}

// CQuantityWnd accept: takes the slider value, hides, and sends it to the requester as notification
// 0x1F with a pointer to the amount.
// FUNCTION: TITANIUM 0x0054D935
void Owner_guess::Accept_guess() {
    nested_15c_guess = provider_168_guess->GetNested_guess();
    Slot34_guess();
    if (support_164_guess != 0) {
        support_164_guess->Slot32_guess(this, 0x1f, &nested_15c_guess);
        support_164_guess = 0;
    }
}

// CQuantityWnd::Activate: asks `support_guess` for an amount up to `mode_guess` (0 closes; 1 answers 1 at
// once). With `randomize_guess` (really a "modifier keys" flag) shift takes the whole stack and ctrl one,
// without showing. Otherwise starts at `value_guess`, at (x, y) kept on screen or centred, focused.
// FUNCTION: TITANIUM 0x0054D976
// @early-stop: budget, structural ndiff=53
void Owner_guess::Function_0054d976_guess(Support_guess* support_guess,
                                           int mode_guess, int value_guess,
                                           int x_guess, int y_guess,
                                           char randomize_guess) {
    CXRect rect_guess;
    int position_guess[2] = { 0, 0 };
    support_164_guess = support_guess;
    value_160_guess = mode_guess;
    if (mode_guess == 0) {
        Slot34_guess();
    } else {
        mode_15c_guess = 0;
        if (mode_guess < 2) {
            mode_15c_guess = mode_guess;
        }
        if (randomize_guess != 0) {
            unsigned int flags_guess = pinstCXWndManager_guess->GetKeyboardFlags();
            if ((flags_guess & 1) != 0) {
                mode_15c_guess = mode_guess;
            } else {
                flags_guess = pinstCXWndManager_guess->GetKeyboardFlags();
                flags_guess >>= 1;
                if ((flags_guess & 1) != 0) {
                    mode_15c_guess = 1;
                }
            }
        }
        provider_168_guess->SetCount_guess(mode_guess + 1);
        provider_168_guess->SetValue_guess(mode_15c_guess);
        if (mode_15c_guess != 0) {
            Accept_guess();
        } else {
            provider_168_guess->SetValue_guess(value_guess);
            UpdateEditWndFromSlider_guess();
            if (x_guess <= -1 || y_guess <= -1) {
                ClearRect_guess();
            } else {
                CXRect* bounds_guess = GetRect_guess(&rect_guess);
                if (bounds_guess->right - bounds_guess->left + x_guess >
                    g_graphicsRoot_guess->display_000_guess->width_0ec_guess) {
                    x_guess = g_graphicsRoot_guess->display_000_guess->width_0ec_guess;
                    bounds_guess = GetRect_guess(&rect_guess);
                    x_guess = bounds_guess->left - bounds_guess->right + x_guess;
                }
                bounds_guess = GetRect_guess(&rect_guess);
                if (bounds_guess->bottom - bounds_guess->top + y_guess >
                    g_graphicsRoot_guess->display_000_guess->height_0f0_guess) {
                    y_guess = g_graphicsRoot_guess->display_000_guess->height_0f0_guess;
                    bounds_guess = GetRect_guess(&rect_guess);
                    y_guess = bounds_guess->top - bounds_guess->bottom + y_guess;
                }
                position_guess[0] = x_guess;
                position_guess[1] = y_guess;
                SetRect_guess(position_guess);
            }
            ((CXWnd*)interface_16c_guess)->SetFocus();
            Slot48_guess(1, 1);
        }
    }
    return;
}

// CRaidOptionsWnd::ClearLooterList (list vtable slot 76).
// FUNCTION: TITANIUM 0x0054DBDD
void Owner_guess::ClearLooterList_guess() {
    if (state_124_guess != 0) {
        nested_15c_guess->Slot76_guess();
    }
}

// Shows the raid loot type (+0x168) and its combo selection; the combo is enabled only when
// 0x42FD00 agrees, probably for the raid leader.
// FUNCTION: TITANIUM 0x0054DBF5
void Owner_guess::UpdateLootType_guess() {
    if (state_124_guess != 0) {
        child_170_guess->flag_05d_guess = 0;
        if (g_panel_guess.IsInRaid_guess()) {
            if (g_panel_guess.IsRaidLeader_guess()) {
                child_170_guess->flag_05d_guess = 1;
            }
            Temp_guess value_guess;
            Format_guess(&value_guess, "%d", g_panel_guess.GetLootType_guess());
            ((Interface_guess*)provider_168_guess)->Slot63_guess(&value_guess);
            child_170_guess->Method_guess(g_panel_guess.GetLootType_guess() - 1);
        }
    }
}

// CRaidOptionsWnd::WndNotification. A loot-type pick (0-2) goes to CRaid as "1"-"3" (0x431136); a class
// colour button opens the colour picker (0x4F898E on 0x850C0C) on its colour. 0x20, the picked colour,
// saves ClassColor<i> in [RaidWindow] and passes it to CRaid::UpdateClassColor.
// FUNCTION: TITANIUM 0x0054DCA9
// @early-stop: budget, structural ndiff=13
int Owner_guess::Function_0054dca9_guess(ClassColor_guess* color_guess,
                                         int type_guess, int value_guess) {
    if (state_124_guess == 0) {
        return 0;
    }

    int index_guess = 0;
    char number_guess[12];
    char className_guess[128];
    char colorValue_guess[128];

    if (type_guess == 1) {
        if (color_guess == currentColor_170_guess) {
            if (value_guess >= 0 && value_guess < 3) {
                __itoa(value_guess + 1, number_guess, 10);
                g_config_guess->RequestLootType_guess(number_guess);
            }
        } else {
            ClassColor_guess** entry_guess = classColor_178_guess;
            int count_guess = 16;
            do {
                if (color_guess == *entry_guess &&
                    pinstCColorPickerWnd_guess != 0) {
                    FUN_004f898e_guess(this,
                                       (*entry_guess)->value_07c_guess);
                    selectedColor_1b8_guess = *entry_guess;
                }
                ++entry_guess;
                --count_guess;
            } while (count_guess != 0);
        }
    } else if (type_guess == 0x20) {
        ClassColor_guess** entry_guess = classColor_178_guess;
        do {
            if (selectedColor_1b8_guess == *entry_guess) {
                __itoa(value_guess, colorValue_guess, 10);
                _sprintf(className_guess, "ClassColor%d", index_guess);
                FUN_0060bf20_guess("RaidWindow", className_guess,
                                   colorValue_guess);
                (*entry_guess)->value_07c_guess = value_guess;
                g_config_guess->UpdateClassColor_guess(index_guess, value_guess);
                selectedColor_1b8_guess = 0;
            }
            ++index_guess;
            ++entry_guess;
        } while (index_guess < 16);
    }

    return Forward_guess((int)color_guess, type_guess, value_guess);
}

// Loads ClassColor0-15 from [RaidWindow] in the UI INI file; a missing key is written as -1 (default).
// FUNCTION: TITANIUM 0x0054DDE2
void Owner_guess::LoadClassColors_guess() {
    char number_guess[128];
    char name_guess[128];
    char value_guess[128];
    if (state_124_guess != 0) {
        for (int i = 0; i < 16; ++i) {
            _sprintf(name_guess, "ClassColor%d", i);
            LoadStringFromUIIniFile_guess("RaidWindow", name_guess, "*NULL*", value_guess,
                               0x80, 1);
            if (value_guess[0] == '*') {
                __itoa(-1, number_guess, 10);
                FUN_0060bf20_guess("RaidWindow", name_guess, number_guess);
                if (classColor_178_guess[i] != 0) {
                    classColor_178_guess[i]->value_07c_guess = -1;
                }
            } else {
                long value = atol(value_guess);
                if (classColor_178_guess[i] != 0) {
                    classColor_178_guess[i]->value_07c_guess = (int)value;
                }
            }
        }
    }
}

/* ---- RaidOptionsWnd::RaidOptionsWnd(CXWnd*) (0x0054DEB0) -------------------------------------------------
 * Layout: the CSidlScreenWnd base (0x15C) plus the raid window's child pointers. The ctor needs a polymorphic
 * base with the real CSidlScreenWnd base ctor and dtor: CSidlScreenWndBase. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065BB28 ??_7RaidOptionsWnd_guess@@6B@
struct RaidOptionsWnd_guess : CSidlScreenWndBase {
    CListWnd* looterList_15c;               // 0x15C RAIDOPTIONS_LooterList
    CXWnd* looterListLabel_160;             // 0x160
    CXWnd* currentLootTypeLabel_164;        // 0x164
    CXWnd* currentLootType_168;             // 0x168
    CXWnd* setLootTypeLabel_16c;            // 0x16C
    CXWnd* setLootTypeCombo_170;            // 0x170
    CXWnd* classColorLabel_174;             // 0x174
    CXWnd* classColor_178[16];              // 0x178
    RaidOptionsWnd_guess(CXWnd* parent);
};

// Raid options window constructor: finds the looter list and labels, the loot type label and combo and
// the 16 class colour buttons RAIDOPTIONS_ClassColor0-15, sets up the looter list and loads the class
// colours from the UI INI (0x0054DDE2).
// FUNCTION: TITANIUM 0x0054DEB0
RaidOptionsWnd_guess::RaidOptionsWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "RaidOptionsWindow") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        looterList_15c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_LooterList");
        looterListLabel_160 = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_LooterListLabel");
        currentLootTypeLabel_164 = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_CurrentLootTypeLabel");
        currentLootType_168 = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_CurrentLootType");
        setLootTypeLabel_16c = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_SetLootTypeLabel");
        setLootTypeCombo_170 = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_SetLootTypeCombo");
        classColorLabel_174 = ((CSidlScreenWnd*)this)->GetChildItem("RAIDOPTIONS_ClassColorLabel");
        for (int i = 0; i < 16; ++i) {
            char name_guess[128];
            _sprintf(name_guess, "RAIDOPTIONS_ClassColor%d", i);
            classColor_178[i] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        looterList_15c->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        looterList_15c->SetColumnJustification(0, 0);
        looterList_15c->WindowStyle &= 0xffdfffff;
        ((Owner_guess*)this)->LoadClassColors_guess();
    }
}

// CRaidOptionsWnd refresh: loot type, cleared looter list, then CRaid::UpdateOptionsWindow refills it.
// FUNCTION: TITANIUM 0x0054E16B
void Owner_guess::Function_0054e16b_guess() {
    if (state_124_guess != 0) {
        UpdateLootType_guess();
        ClearLooterList_guess();
        return g_panel_guess.UpdateOptionsWindow_guess();
    }
}

// OnProcessFrame: refreshes the loot type every 250 ms.
// FUNCTION: TITANIUM 0x0054E198
int Owner_guess::OnProcessFrame_guess() {
    if (state_124_guess == 0) {
        return 0;
    }
    int value_guess = g_timer_905d24_guess->value_148_guess;
    if (value_guess - lastUpdate_1bc_guess > 0xfa) {
        UpdateLootType_guess();
        lastUpdate_1bc_guess = value_guess;
    }
    return Function_005a0e50_guess();
}
