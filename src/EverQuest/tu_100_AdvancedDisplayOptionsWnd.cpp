// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 100: a hint from compare/tumap.py.
// CAdvancedDisplayOptionsWnd ("AdvancedDisplayOptionsWindow", ADOW_* controls, vtable 0x64E328), after the
// last CActionsWnd function. CAdvancedDisplayOptionsWnd_guess and Pane_guess (0x4D4F58, 0x4D515D) are it; Game_guess is
// CDisplay (0x905D24), CEverQuestView_guess CEverQuest (0x988DF0), GraphicsDriverView_guess the graphics driver (0x99E364).
#include "titanium/eqaddr.h"
#include "titanium/types.h"

// Virtual table of the global controller at DAT_0099E364. Slot 0xD8 is index 54.
struct GraphicsDriverView_guess {
    virtual int Slot00_guess(int);
    virtual int Slot01_guess(int);
    virtual int Slot02_guess(int);
    virtual int Slot03_guess(int);
    virtual int Slot04_guess(int);
    virtual int Slot05_guess(int);
    virtual int Slot06_guess(int);
    virtual int Slot07_guess(int);
    virtual int Slot08_guess(int);
    virtual int Slot09_guess(int);
    virtual int Slot10_guess(int);
    virtual int Slot11_guess(int);
    virtual int Slot12_guess(int);
    virtual int Slot13_guess(int);
    virtual int Slot14_guess(int);
    virtual int Slot15_guess(int);
    virtual int Slot16_guess(int);
    virtual int Slot17_guess(int);
    virtual int Slot18_guess(int);
    virtual int Slot19_guess(int);
    virtual int Slot20_guess(int);
    virtual int Slot21_guess(int);
    virtual int Slot22_guess(int);
    virtual int Slot23_guess(int);
    virtual int Slot24_guess(int);
    virtual int Slot25_guess(int);
    virtual int Slot26_guess(int);
    virtual int Slot27_guess(int);
    virtual int Slot28_guess(int);
    virtual int Slot29_guess(int);
    virtual int Slot30_guess(int);
    virtual int Slot31_guess(int);
    virtual int Slot32_guess(int);
    virtual int Slot33_guess(int);
    virtual int Slot34_guess(int);
    virtual int Slot35_guess(int);
    virtual int Slot36_guess(int);
    virtual int Slot37_guess(int);
    virtual int Slot38_guess(int);
    virtual int Slot39_guess(int);
    virtual int Slot40_guess(int);
    virtual int Slot41_guess(int);
    virtual int Slot42_guess(int);
    virtual int Slot43_guess(int);
    virtual int Slot44_guess(int);
    virtual int Slot45_guess(int);
    virtual int Slot46_guess(int);
    virtual const char* Slot47_guess();
    virtual int Slot48_guess(int);
    virtual int Slot49_guess(int);
    virtual int Slot50_guess(int);
    virtual int Slot51_guess(int);
    virtual int Slot52_guess(int);
    virtual int Slot53_guess(int);
    virtual int Slot54_guess(int);
};

// Global client state at DAT_00905D24. Button bytes at 0x2D5F..0x2D65, dwords at 0x2D68 and 0x2D6C.
struct Game_guess {
    // EXTERNAL: TITANIUM 0x0043617D Game_guess::SetMultipass_guess
    void SetMultipass_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x00436156 Game_guess::SetShadows_guess
    void SetShadows_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x004361A4 Game_guess::SetWaterSwap_guess
    void SetWaterSwap_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x004361CB Game_guess::SetPixelShaders20_guess
    void SetPixelShaders20_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x00436219 Game_guess::SetPixelShaders14_guess
    void SetPixelShaders14_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x004361F2 Game_guess::SetPixelShaders1x_guess
    void SetPixelShaders1x_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x00436240 Game_guess::SetVertexShaders_guess
    void SetVertexShaders_guess(unsigned char on);
    // EXTERNAL: TITANIUM 0x004360D6 Game_guess::SetActorClipPlane_guess
    void SetActorClipPlane_guess(int value);
    // EXTERNAL: TITANIUM 0x00436129 Game_guess::SetShadowClipPlane_guess
    void SetShadowClipPlane_guess(int value);

    char pad0_guess[0x148];
    unsigned int tick_guess;
    char pad_guess[0x2D5F - 0x14C];
    unsigned char btn_guess[7];
    char gap_guess[2];
    int arg_guess[2];
};

// Ini file writer at DAT_00988DF0.
struct CEverQuestView_guess {
    // EXTERNAL: TITANIUM 0x004AE5AF CEverQuestView_guess::SetByte_guess
    void SetByte_guess(unsigned char value, const char* section, const char* key);
    // EXTERNAL: TITANIUM 0x004AE514 CEverQuestView_guess::SetInt_guess
    void SetInt_guess(int value, const char* section, const char* key);
};

// Setting object returned by Mgr_guess::Find_guess. Slot 17 (0x44) sets a value.
struct Setting_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess(unsigned int* out_guess);
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess(int value);
};

// Settings manager returned by Mgr_Get_guess.
struct Mgr_guess {
    // EXTERNAL: TITANIUM 0x00577110 Mgr_guess::Find_guess
    Setting_guess* Find_guess(const char* name);
};

// EXTERNAL: TITANIUM 0x004C398E Mgr_Get_guess
Mgr_guess* Mgr_Get_guess();

#define g_ctl_guess EQ_GLOBAL(GraphicsDriverView_guess*, 0x0099E364)
#define g_game_guess EQ_GLOBAL(Game_guess*, 0x00905D24)
#define g_ini_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)

// Child control. Byte at 0x5D is a state flag. Byte at 0x128 is the option value.
struct Widget_guess {
    // EXTERNAL: TITANIUM 0x005BB140 Widget_guess::SetCheck
    void SetCheck(int on);
    // EXTERNAL: TITANIUM 0x005BCD10 Widget_guess::SetValue_guess
    void SetValue_guess(int value);
    // EXTERNAL: TITANIUM 0x0059C3A0 Widget_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x005BC390 Widget_guess::GetHandle_guess
    int GetHandle_guess();

    char pad_guess[0x5D];
    unsigned char enabled_005d_guess;
    char pad2_guess[0x128 - 0x5E];
    unsigned char checked_0128_guess;
};

// Pane. Child pointers at 0x15C..0x184 (eleven of them).
struct Pane_guess {
    char pad_guess[0x15C];
    Widget_guess* w_guess[11];
    char pad3_guess[0x214 - 0x188];
    unsigned int last_tick_guess;

    // EXTERNAL: TITANIUM 0x0059DD30 Pane_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x004D473B Pane_guess::RefreshPage_guess
    void RefreshPage_guess(int handle);
    void OnProcessFrame_guess();

    // EXTERNAL: TITANIUM 0x005A0E50 Pane_guess::OnProcessFrame
    void OnProcessFrame();
    // EXTERNAL: TITANIUM 0x005A2230 Pane_guess::WndNotification
    void WndNotification(Widget_guess* w, int kind, int value);
    void AdvancedDisplayOnProcessFrame_guess();
    void WndNotification_guess(Widget_guess* child_guess, int kind_guess, int value_guess);
};

// CActionsWnd::OnProcessFrame, not this window: every 200 ms while shown it refreshes the current tab page
// (CTabWnd::GetCurrentPage at +0x15C, page dispatch 0x4D473B in tu_099), then CXWnd::OnProcessFrame.
// FUNCTION: TITANIUM 0x004D4783
void Pane_guess::OnProcessFrame_guess() {
    if (IsActive_guess() && g_game_guess->tick_guess > last_tick_guess + 200) {
        if (w_guess[0] != 0) {
            RefreshPage_guess(w_guess[0]->GetHandle_guess());
        }
        last_tick_guess = g_game_guess->tick_guess;
    }
    OnProcessFrame();
}

// OnProcessFrame: re-syncs the checkboxes and clip sliders with CDisplay each frame, as 0x4D47D8 does
// minus the card list. Caps (driver slot 54): 1/2 pixel-shader version, 3/4 vertex-shader version, 5 TnL.
// FUNCTION: TITANIUM 0x004D4F58
void Pane_guess::AdvancedDisplayOnProcessFrame_guess() {
    if (w_guess[0] != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 0) {
            w_guess[0]->SetCheck(g_game_guess->btn_guess[0]);
            w_guess[0]->enabled_005d_guess = 1;
        } else {
            w_guess[0]->SetCheck(0);
            w_guess[0]->enabled_005d_guess = 0;
        }
    }
    if (w_guess[1] != 0) {
        w_guess[1]->SetCheck(g_game_guess->btn_guess[1]);
    }
    if (w_guess[2] != 0) {
        w_guess[2]->SetCheck(g_game_guess->btn_guess[2]);
    }
    if (w_guess[3] != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 1) {
            w_guess[3]->SetCheck(g_game_guess->btn_guess[3]);
            w_guess[3]->enabled_005d_guess = 1;
        } else {
            w_guess[3]->SetCheck(0);
            w_guess[3]->enabled_005d_guess = 0;
        }
    }
    if (w_guess[4] != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 1 ||
            // 1.4 shaders need pixel shader 1.4 or 2.0+.
            (g_ctl_guess->Slot54_guess(1) == 1 && g_ctl_guess->Slot54_guess(2) == 4)) {
            w_guess[4]->SetCheck(g_game_guess->btn_guess[4]);
            w_guess[4]->enabled_005d_guess = 1;
        } else {
            w_guess[4]->SetCheck(0);
            w_guess[4]->enabled_005d_guess = 0;
        }
    }
    if (w_guess[5] != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 0) {
            w_guess[5]->SetCheck(g_game_guess->btn_guess[5]);
            w_guess[5]->enabled_005d_guess = 1;
        } else {
            w_guess[5]->SetCheck(0);
            w_guess[5]->enabled_005d_guess = 0;
        }
    }
    if (w_guess[6] != 0) {
        w_guess[6]->SetCheck(g_game_guess->btn_guess[6]);
    }
    if (w_guess[7] != 0) {
        w_guess[7]->SetValue_guess(g_game_guess->arg_guess[0]);
    }
    if (w_guess[8] != 0) {
        w_guess[8]->SetValue_guess(g_game_guess->arg_guess[1]);
    }
    OnProcessFrame();
}

// WndNotification: a checkbox click (code 1) applies the option to CDisplay and writes it to the
// [Defaults] ini section; slider moves (code 0xE) set the clip planes under [Options].
// FUNCTION: TITANIUM 0x004D515D
void Pane_guess::WndNotification_guess(Widget_guess* child_guess, int kind_guess, int value_guess) {
    if (kind_guess == 1) {
        Mgr_guess* mgr_guess = Mgr_Get_guess();
        if (child_guess == w_guess[0]) {
            g_game_guess->SetMultipass_guess(w_guess[0]->checked_0128_guess);
            g_ini_guess->SetByte_guess(w_guess[0]->checked_0128_guess, "Defaults", "MultipassLighting");
        }
        Widget_guess** slot_guess = &w_guess[1];
        // A separate if, not else-if: after Multipass the chain still runs (no effect).
        if (child_guess == *slot_guess) {
            g_game_guess->SetShadows_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "Shadows");
        } else if (child_guess == *(slot_guess = &w_guess[2])) {
            g_game_guess->SetWaterSwap_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "WaterSwap");
        } else if (child_guess == *(slot_guess = &w_guess[3])) {
            g_game_guess->SetPixelShaders20_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "20PixelShaders");
        } else if (child_guess == *(slot_guess = &w_guess[4])) {
            g_game_guess->SetPixelShaders14_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "14PixelShaders");
        } else if (child_guess == *(slot_guess = &w_guess[5])) {
            g_game_guess->SetPixelShaders1x_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "1xPixelShaders");
        } else if (child_guess == *(slot_guess = &w_guess[6])) {
            g_game_guess->SetVertexShaders_guess((*slot_guess)->checked_0128_guess);
            g_ini_guess->SetByte_guess((*slot_guess)->checked_0128_guess, "Defaults", "VertexShaders");
        } else if (child_guess == w_guess[9]) {
            Setting_guess* setting_guess = mgr_guess->Find_guess("Graphics.Scene.SkyCubeUpdateInterval");
            int ms_guess;
            switch (w_guess[9]->GetCurChoice_guess()) {
            case 1: ms_guess = 10000; break;
            case 2: ms_guess = 1000; break;
            case 3: ms_guess = 200; break;
            case 4: ms_guess = 100; break;
            // 33 ms, about 30 updates a second; 0 is every frame; the default 60 s.
            case 5: ms_guess = 0x21; break;
            case 6: ms_guess = 0; break;
            default: ms_guess = 60000; break;
            }
            setting_guess->Slot17_guess(ms_guess);
            g_ini_guess->SetInt_guess(ms_guess, "Defaults", "SkyUpdateInterval");
        } else if (child_guess == w_guess[10]) {
            Setting_guess* setting_guess = mgr_guess->Find_guess("Graphics.Scene.SkyCubeMapSizeNext");
            int size_guess = w_guess[10]->GetCurChoice_guess();
            // The driver setting is the choice + 5, probably log2 of the cube size (32 up); the ini keeps
            // the choice.
            setting_guess->Slot17_guess(size_guess + 5);
            g_ini_guess->SetInt_guess(size_guess, "Defaults", "SkyCubemapSize");
        }
    // Empty on purpose (match shape).
    } else if (kind_guess == 3) {
    } else if (kind_guess == 0xE) {
        if (child_guess == w_guess[7]) {
            g_game_guess->SetActorClipPlane_guess(value_guess);
            g_ini_guess->SetInt_guess(value_guess, "Options", "ActorClipPlane");
        } else if (child_guess == w_guess[8]) {
            g_game_guess->SetShadowClipPlane_guess(value_guess);
            g_ini_guess->SetInt_guess(value_guess, "Options", "ShadowClipPlane");
        }
    }
    WndNotification(child_guess, kind_guess, value_guess);
}


// Child control. Byte at 0x66 holds two cleared flags; SetValue is 0x005BD180.
struct AdvChild_guess {
    // EXTERNAL: TITANIUM 0x005BD180 AdvChild_guess::SetValue_guess
    void SetValue_guess(int value);
    // EXTERNAL: TITANIUM 0x0059C8D0 AdvChild_guess::InsertChoice_guess
    void InsertChoice_guess(const CXStr& text);
    // EXTERNAL: TITANIUM 0x0059C360 AdvChild_guess::SetChoice_guess
    void SetChoice_guess(int index);
    char pad_guess[0x66];
    unsigned char flags_guess; // 0x66
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0064E328 ??_7CAdvancedDisplayOptionsWnd_guess@@6B@
struct CAdvancedDisplayOptionsWnd_guess : CSidlScreenWndBase {
    CAdvancedDisplayOptionsWnd_guess(CXWnd* parent);
    void LoadSettings_guess();
    AdvChild_guess* advancedLighting_015c_guess;
    AdvChild_guess* shadows_0160_guess;
    AdvChild_guess* waterSwap_0164_guess;
    AdvChild_guess* pixelShaders20_0168_guess;
    AdvChild_guess* pixelShaders14_016c_guess;
    AdvChild_guess* pixelShaders11_0170_guess;
    AdvChild_guess* vertexShaders_0174_guess;
    AdvChild_guess* actorClipPlane_0178_guess;
    AdvChild_guess* shadowClipPlane_017c_guess;
    AdvChild_guess* skyUpdateInterval_0180_guess;
    AdvChild_guess* skyReflectionSize_0184_guess;
    AdvChild_guess* cardFeatures_0188_guess;
};

// CAdvancedDisplayOptionsWnd::CAdvancedDisplayOptionsWnd: finds the ADOW_* controls, presets both clip
// sliders to 100 and loads the settings.
// FUNCTION: TITANIUM 0x004D53E2
CAdvancedDisplayOptionsWnd_guess::CAdvancedDisplayOptionsWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "AdvancedDisplayOptionsWindow") {
    advancedLighting_015c_guess = 0;
    shadows_0160_guess = 0;
    waterSwap_0164_guess = 0;
    pixelShaders20_0168_guess = 0;
    pixelShaders14_016c_guess = 0;
    pixelShaders11_0170_guess = 0;
    vertexShaders_0174_guess = 0;
    cardFeatures_0188_guess = 0;
    actorClipPlane_0178_guess = 0;
    shadowClipPlane_017c_guess = 0;
    skyUpdateInterval_0180_guess = 0;
    skyReflectionSize_0184_guess = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        advancedLighting_015c_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_AdvancedLightingCheckbox");
        shadows_0160_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_ShadowsCheckbox");
        waterSwap_0164_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_WaterSwapCheckbox");
        pixelShaders20_0168_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_20PixelShadersCheckbox");
        pixelShaders14_016c_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_14PixelShadersCheckbox");
        pixelShaders11_0170_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_11PixelShadersCheckbox");
        vertexShaders_0174_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_VertexShadersCheckbox");
        cardFeatures_0188_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_CardFeaturesListbox");
        if (cardFeatures_0188_guess != 0) {
            // Clears two style bits of the card-features list (+0x66), probably selection and focus.
            cardFeatures_0188_guess->flags_guess &= 0xdf;
            cardFeatures_0188_guess->flags_guess &= 0xfe;
        }
        actorClipPlane_0178_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_ActorClipPlaneSlider");
        shadowClipPlane_017c_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_ShadowClipPlaneSlider");
        if (actorClipPlane_0178_guess != 0) {
            actorClipPlane_0178_guess->SetValue_guess(100);
        }
        if (shadowClipPlane_017c_guess != 0) {
            shadowClipPlane_017c_guess->SetValue_guess(100);
        }
        skyUpdateInterval_0180_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_SkyUpdateIntervalCombobox");
        skyReflectionSize_0184_guess =
            (AdvChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("ADOW_SkyReflectionSizeCombobox");
        LoadSettings_guess();
    }
}

// The same 0x00905D24 object, seen as option flags.
struct GameOpts_guess {
    char pad_guess[0x2D5F];
    bool multipass_guess;       // 0x2D5F
    bool shadows_guess;         // 0x2D60
    bool waterSwap_guess;       // 0x2D61
    bool pixelShaders20_guess;  // 0x2D62
    bool pixelShaders14_guess;  // 0x2D63
    bool pixelShaders1x_guess;  // 0x2D64
    bool vertexShaders_guess;   // 0x2D65
    char gap_guess[2];
    int actorClip_guess;        // 0x2D68
    int shadowClip_guess;       // 0x2D6C
};
#define g_opts_guess EQ_GLOBAL(GameOpts_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_guess
void __cdecl FormatCXStr_guess(CXStr* text_guess, const char* format_guess, ...);

// Fills the controls from CDisplay (0x2D5F-0x2D6C), disabling the shader options the card can't run;
// lists the card name, TnL and shader versions, and fills both sky combos.
// FUNCTION: TITANIUM 0x004D47D8
// @early-stop: tiebreak, structural ndiff=104
void CAdvancedDisplayOptionsWnd_guess::LoadSettings_guess() {
    if (advancedLighting_015c_guess != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 0) {
            ((CButtonWnd*)advancedLighting_015c_guess)->SetCheck(g_opts_guess->multipass_guess);
            ((CButtonWnd*)advancedLighting_015c_guess)->Enabled = 1;
        } else {
            ((CButtonWnd*)advancedLighting_015c_guess)->SetCheck(0);
            ((CButtonWnd*)advancedLighting_015c_guess)->Enabled = 0;
        }
    }
    if (shadows_0160_guess != 0) {
        ((CButtonWnd*)shadows_0160_guess)->SetCheck(g_opts_guess->shadows_guess);
    }
    if (waterSwap_0164_guess != 0) {
        ((CButtonWnd*)waterSwap_0164_guess)->SetCheck(g_opts_guess->waterSwap_guess);
    }
    if (pixelShaders20_0168_guess != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 1) {
            ((CButtonWnd*)pixelShaders20_0168_guess)->SetCheck(g_opts_guess->pixelShaders20_guess);
            ((CButtonWnd*)pixelShaders20_0168_guess)->Enabled = 1;
        } else {
            ((CButtonWnd*)pixelShaders20_0168_guess)->SetCheck(0);
            ((CButtonWnd*)pixelShaders20_0168_guess)->Enabled = 0;
        }
    }
    if (pixelShaders14_016c_guess != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 1 ||
            (g_ctl_guess->Slot54_guess(1) == 1 && g_ctl_guess->Slot54_guess(2) == 4)) {
            ((CButtonWnd*)pixelShaders14_016c_guess)->SetCheck(g_opts_guess->pixelShaders14_guess);
            ((CButtonWnd*)pixelShaders14_016c_guess)->Enabled = 1;
        } else {
            ((CButtonWnd*)pixelShaders14_016c_guess)->SetCheck(0);
            ((CButtonWnd*)pixelShaders14_016c_guess)->Enabled = 0;
        }
    }
    if (pixelShaders11_0170_guess != 0) {
        if (g_ctl_guess->Slot54_guess(1) > 0) {
            ((CButtonWnd*)pixelShaders11_0170_guess)->SetCheck(g_opts_guess->pixelShaders1x_guess);
            ((CButtonWnd*)pixelShaders11_0170_guess)->Enabled = 1;
        } else {
            ((CButtonWnd*)pixelShaders11_0170_guess)->SetCheck(0);
            ((CButtonWnd*)pixelShaders11_0170_guess)->Enabled = 0;
        }
    }
    if (vertexShaders_0174_guess != 0) {
        ((CButtonWnd*)vertexShaders_0174_guess)->SetCheck(g_opts_guess->vertexShaders_guess);
    }
    if (actorClipPlane_0178_guess != 0) {
        ((Widget_guess*)actorClipPlane_0178_guess)->SetValue_guess(g_opts_guess->actorClip_guess);
    }
    if (shadowClipPlane_017c_guess != 0) {
        ((Widget_guess*)shadowClipPlane_017c_guess)->SetValue_guess(g_opts_guess->shadowClip_guess);
    }
    if (cardFeatures_0188_guess != 0) {
        CListWnd* list_guess = (CListWnd*)cardFeatures_0188_guess;
        list_guess->AddString(g_ctl_guess->Slot47_guess(), -1, 0, 0);
        CXStr text_guess;
        FormatCXStr_guess(&text_guess, g_ctl_guess->Slot54_guess(5) == 1 ? "Hardware TnL" : "Software TnL");
        ((CListWnd*)cardFeatures_0188_guess)->AddString(text_guess, -1, 0, 0);
        if (g_ctl_guess->Slot54_guess(3) > 0) {
            FormatCXStr_guess(&text_guess, "Vertex Shader %d.%d", g_ctl_guess->Slot54_guess(3),
                              g_ctl_guess->Slot54_guess(4));
            ((CListWnd*)cardFeatures_0188_guess)->AddString(text_guess, -1, 0, 0);
        }
        if (g_ctl_guess->Slot54_guess(1) > 0) {
            FormatCXStr_guess(&text_guess, "Pixel Shader %d.%d", g_ctl_guess->Slot54_guess(1),
                              g_ctl_guess->Slot54_guess(2));
            ((CListWnd*)cardFeatures_0188_guess)->AddString(text_guess, -1, 0, 0);
        }
    }
    Mgr_guess* mgr_guess = Mgr_Get_guess();
    if (mgr_guess != 0) {
        if (skyUpdateInterval_0180_guess != 0) {
            // Interval labels 0xFE8-0xFEA, 0xFF1-0xFF3, 0xFEB: 60 s down to every frame (the
            // middle three ids probably added later).
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xfe8, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xfe9, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xfea, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xff1, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xff2, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xff3, 0));
            skyUpdateInterval_0180_guess->InsertChoice_guess(pStringTable->getString(0xfeb, 0));
            unsigned int ms_guess;
            mgr_guess->Find_guess("Graphics.Scene.SkyCubeUpdateInterval")->Slot09_guess(&ms_guess);
            int index_guess;
            if (ms_guess >= 60000) {
                index_guess = 0;
            } else if (ms_guess >= 10000) {
                index_guess = 1;
            } else if (ms_guess >= 1000) {
                index_guess = 2;
            } else if (ms_guess >= 200) {
                index_guess = 3;
            } else if (ms_guess >= 100) {
                index_guess = 4;
            } else {
                // 32-99 ms reads as choice 5 (33 ms), under 32 ms as choice 6 (every frame).
                index_guess = (ms_guess < 32) + 5;
            }
            skyUpdateInterval_0180_guess->SetChoice_guess(index_guess);
        }
        if (skyReflectionSize_0184_guess != 0) {
            // Five reflection sizes, strings 0xFEC-0xFF0; the setting is the choice + 5 (capped at 9).
            skyReflectionSize_0184_guess->InsertChoice_guess(pStringTable->getString(0xfec, 0));
            skyReflectionSize_0184_guess->InsertChoice_guess(pStringTable->getString(0xfed, 0));
            skyReflectionSize_0184_guess->InsertChoice_guess(pStringTable->getString(0xfee, 0));
            skyReflectionSize_0184_guess->InsertChoice_guess(pStringTable->getString(0xfef, 0));
            skyReflectionSize_0184_guess->InsertChoice_guess(pStringTable->getString(0xff0, 0));
            unsigned int size_guess;
            mgr_guess->Find_guess("Graphics.Scene.SkyCubeMapSizeNext")->Slot09_guess(&size_guess);
            if (size_guess > 8) {
                size_guess = 9;
            }
            skyReflectionSize_0184_guess->SetChoice_guess(size_guess > 4 ? size_guess - 5 : 0);
        }
    }
}
