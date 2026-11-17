// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 196: a hint from compare/tumap.py.
// CPlayerWnd ("PlayerWindow", CPlayerWndView_guess): the player window's pulsing attack indicator
// (A_AttackIndicatorAnim, shown while 0x9858C7 is set, probably auto-attack) and the pet health bar
// (PetHP), shown when you have a pet and the context menu's "Pet Display" option (ini key Petbars) is on.
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(void* value, const char* category, char* input, char* output, int size, int mode);

// EXTERNAL: TITANIUM 0x0060BF20 ApplySettingAlt_guess
void __cdecl ApplySettingAlt_guess(void* value, const char* category, char* input);

extern "C" int __cdecl sprintf(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x00401B28 LookupFlag_guess
int __cdecl LookupFlag_guess(int handle);

#define g_display_guess EQ_GLOBAL(Display_guess_guess*, 0x00905D24)
#define g_charData_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_flag_guess EQ_GLOBAL(unsigned char, 0x009858C7)

struct Display_guess_guess
{
    char pad_000[0x148];
    int ticks_148; // 0x148
};

struct ActorInfo_guess
{
    char pad_000[0x16C];
    int field_16C; // 0x16C
};

// Polymorphic view of the window at Container +0x160: only slot 48 (0xC0) is used.
struct PetHpWnd_guess
{
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
    virtual void Slot48_guess(bool on, int one);
};

struct Settings_guess
{
    void* field_000;

    // EXTERNAL: TITANIUM 0x00572300 Settings_guess::Get_guess
    void* Get_guess();
};

struct Point_guess
{
    int x;
    int y;

    Point_guess* SetX_guess(int value)
    {
        x = value;
        return this;
    }
};

struct Box_guess
{
    int left;
    int top;
    int right;
    int bottom;

    // EXTERNAL: TITANIUM 0x004D9139 Box_guess::Set_guess
    void Set_guess(Point_guess* first, Point_guess* second);
};

struct BoxTriplet_guess
{
    Box_guess late;    // 0x00
    Box_guess initial; // 0x10
    Box_guess helper;  // 0x20
};

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CContextMenuManager.h"

struct SidlBase_guess
{
    virtual void Slot00_guess();
    char pad_004[0x14];                     // 0x004..0x017
    unsigned char flag_018_guess;           // 0x018
    char pad_019[0x4b];                     // 0x019..0x063
    unsigned int windowStyle_064;           // 0x064 (CXWnd::WindowStyle)
    char pad_068[0xbc];                     // 0x068..0x123
    CScreenPieceTemplate* sidlPiece_124;      // 0x124 (CSidlScreenWnd::SidlPiece)
    // EXTERNAL: TITANIUM 0x005A3850 ??0SidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    SidlBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlBase_guess@@QAE@XZ
    ~SidlBase_guess();
};

// EXTERNAL: TITANIUM 0x0065A748 ??_7CPlayerWndView_guess@@6B@

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct CContextMenu_guess
{
    char pad_000[0x1A8];

    // EXTERNAL: TITANIUM 0x005BFAE0 ??0CContextMenu_guess@@QAE@HHABUBox_guess@@@Z
    CContextMenu_guess(int zero, int second, const Box_guess& box);

    // EXTERNAL: TITANIUM 0x005BFF70 CContextMenu_guess::Update_guess
    void Update_guess(unsigned int value, unsigned char flag, int zero);

    // EXTERNAL: TITANIUM 0x005BFCF0 CContextMenu_guess::Pick_guess
    unsigned int Pick_guess(CXStr* text, int id, int zero, int minus_one);

    // EXTERNAL: TITANIUM 0x005BFE60 CContextMenu_guess::Prepare_guess
    void Prepare_guess();
};

// A box filled in by its constructor, so it can be passed as a temporary.
struct BoxInit_guess : Box_guess
{
    BoxInit_guess()
    {
        left = 0;
        top = 0;
        right = 0x32;
        bottom = 10;
    }
};

struct CTextureAnimationView_guess
{
    char pad_000[0x24];
    Point_guess point; // 0x24
    char pad_02C;
    unsigned char stopped; // 0x2D

    // EXTERNAL: TITANIUM 0x005B1730 CTextureAnimationView_guess::Restart_guess
    void Restart_guess(int zero);

    // EXTERNAL: TITANIUM 0x005B1910 CTextureAnimationView_guess::Draw_guess
    void Draw_guess(Box_guess* output, Box_guess* texture, unsigned int color, unsigned int alpha);
};

struct Controller_guess
{
    char pad_000[0x64];
    CTextureAnimationView_guess* timer; // 0x64
};

struct CPlayerWndView_guess : SidlBase_guess
{
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
    virtual Box_guess* GetBox_guess(Box_guess* output);

    CPlayerWndView_guess(CXWnd* parent);

    char pad_128[0x18];
    Settings_guess settings; // 0x140
    char pad_144[0xC];
    unsigned int contextMenuId_0150_guess; // 0x150
    char pad_154[0x8];
    unsigned char showIndicator_015c_guess; // 0x15C
    char pad_15D[3];
    CXWnd* petHp_guess; // 0x160
    unsigned int field_164; // 0x164
    unsigned int field_168; // 0x168
    Controller_guess* controller; // 0x16C
    int pulsePhase_0170_guess; // 0x170
    CContextMenu_guess* contextMenu_0174_guess; // 0x174
    unsigned char petDisplay_0178_guess; // 0x178
    char pad_179[3];
    unsigned int value; // 0x17C

    // EXTERNAL: TITANIUM 0x0059D6C0 CPlayerWndView_guess::GetTexture_guess
    Box_guess* GetTexture_guess(Box_guess* output);

    int Draw_guess();

    // EXTERNAL: TITANIUM 0x00544DFE CPlayerWndView_guess::~CPlayerWndView_guess
    ~CPlayerWndView_guess();

    void ResetAttackIndicator_guess();
    void* Destroy_guess(unsigned int flags);
    void UpdatePetDisplayCheck_guess();
    // EXTERNAL: TITANIUM 0x005A2660 CPlayerWndView_guess::RefreshSetting_guess
    void RefreshSetting_guess();
    // EXTERNAL: TITANIUM 0x005A1890 CPlayerWndView_guess::RefreshSettingAlt_guess
    void RefreshSettingAlt_guess();
    void CreateContextMenu_guess();
    // EXTERNAL: TITANIUM 0x005A2490 CPlayerWndView_guess::GetChildAnimation_guess
    Controller_guess* GetChildAnimation_guess(const CXStr& name);
    void LoadIniInfo_guess();
    void StoreIniInfo_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CPlayerWndView_guess::IsActive_guess
    bool IsActive_guess();
    void OnProcessFrame_guess();

    // EXTERNAL: TITANIUM 0x005A2230 CPlayerWndView_guess::Fallback_guess
    int Fallback_guess(int first, int second, int third);
    int WndNotification_guess(int first, int second, int third);
};

// EXTERNAL: TITANIUM 0x005A00E0 DrawFallback_guess
void __cdecl DrawFallback_guess(Box_guess* first, unsigned int color, Box_guess* second);

// Scalar deleting destructor of the player notes window (vtable 0x65A5E0 slot 1): runs its destructor
// (0x00544DFE, which saves notes.txt) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00544E47
void* CPlayerWndView_guess::Destroy_guess(unsigned int flags)
{
    this->~CPlayerWndView_guess();
    if ((flags & 1) != 0)
        free(this);
    return this;
}

// Hides the attack indicator and restarts its animation and timers.
// FUNCTION: TITANIUM 0x00544E63
void CPlayerWndView_guess::ResetAttackIndicator_guess()
{
    pulsePhase_0170_guess = 0;
    field_164 = 0;
    field_168 = 0;
    showIndicator_015c_guess = 0;
    Controller_guess* c = controller;
    if (c != 0)
    {
        CTextureAnimationView_guess* t = c->timer;
        if (t != 0)
        {
            t->stopped = 0;
            t->Restart_guess(0);
        }
    }
}

// Draws the attack indicator tinted by the pulse phase (+0x170); without the animation, a plain rectangle.
// FUNCTION: TITANIUM 0x00544EA0
int CPlayerWndView_guess::Draw_guess()
{
    if (showIndicator_015c_guess == 0)
        return 0;

    BoxTriplet_guess buffers;
    Box_guess output;

    GetBox_guess(&buffers.initial);
    GetTexture_guess(&buffers.helper);

    unsigned int color = pulsePhase_0170_guess;
    // ARGB 0xFFFFpppp for phase pp: red at 0, white near 0xFF.
    color = ((color | 0xFFFFFF00) << 8) | (color & 0xFF);

    if (controller == 0 || controller->timer == 0)
    {
        DrawFallback_guess(&buffers.initial, color, &buffers.helper);
    }
    else
    {
        CTextureAnimationView_guess* timer = controller->timer;
        output.bottom = 0;
        output.right = 0;
        output.top = 0;
        output.left = 0;
        Box_guess* point_source = GetBox_guess(&buffers.late);
        Point_guess point;
        int x = point_source->left;
        point.y = point_source->top;
        output.Set_guess(point.SetX_guess(x), &timer->point);
        timer->Draw_guess(&output, GetTexture_guess(&buffers.late), color, 0xFF000000);
    }
    return 0;
}

// Advances the pulse phase (one 0-255 cycle per 250 ms); every 500 ms shows PetHP when the player's pet
// (actor +0x16C) exists and Pet Display is on.
// FUNCTION: TITANIUM 0x00544F69
void CPlayerWndView_guess::OnProcessFrame_guess()
{
    if (IsActive_guess())
    {
        int ticks = g_display_guess->ticks_148;
        int delta = ticks - (int)field_168;
        field_168 = ticks;
        pulsePhase_0170_guess += (unsigned int)(delta * 0xff) / 0xfa;
        while (pulsePhase_0170_guess >= 0xff)
            pulsePhase_0170_guess -= 0xff;
        if (ticks - (int)field_164 > 500)
        {
            bool active = false;
            if (g_charData_guess->pSpawn != 0)
            {
                ActorInfo_guess* info = (ActorInfo_guess*)g_charData_guess->pSpawn->pActorInfo;
                if (info != 0 && info->field_16C != -1)
                {
                    if (LookupFlag_guess(info->field_16C) != 0)
                        active = true;
                }
            }
            PetHpWnd_guess* pet = (PetHpWnd_guess*)petHp_guess;
            if (pet != 0)
            {
                pet->Slot48_guess(active && petDisplay_0178_guess, 1);
            }
            field_164 = ticks;
        }
        showIndicator_015c_guess = g_flag_guess != 0;
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Sets the Pet Display check in the context menu from +0x178.
// FUNCTION: TITANIUM 0x0054504D
void CPlayerWndView_guess::UpdatePetDisplayCheck_guess()
{
    contextMenu_0174_guess->Update_guess(value, petDisplay_0178_guess, 0);
}

// LoadIniInfo: reads Petbars (default true), then the base.
// FUNCTION: TITANIUM 0x0054506A
void CPlayerWndView_guess::LoadIniInfo_guess()
{
    if (NewUIINI() != 0)
    {
        char input[256];
        char output[256];
        sprintf(input, "%s", petDisplay_0178_guess != 0 ? "true" : "false");
        LoadStringFromUIIniFile_guess(settings.Get_guess(), "Petbars", input, output, 0x100, 1);
        petDisplay_0178_guess = (output[0] == 't' || output[0] == 'T' || output[0] == '1') ? 1 : 0;
        RefreshSetting_guess();
    }
}

// StoreIniInfo: writes Petbars, then the base.
// FUNCTION: TITANIUM 0x0054511B
void CPlayerWndView_guess::StoreIniInfo_guess()
{
    if (NewUIINI() != 0)
    {
        char value[256];
        sprintf(value, "%s", petDisplay_0178_guess != 0 ? "true" : "false");
        ApplySettingAlt_guess(settings.Get_guess(), "Petbars", value);
        RefreshSettingAlt_guess();
    }
}

// Context-menu item 0x32 (Pet Display) toggles the pet bar.
// FUNCTION: TITANIUM 0x00545192
int CPlayerWndView_guess::WndNotification_guess(int first, int second, int third)
{
    if (second == 0x14 && third == 0x32)
    {
        petDisplay_0178_guess ^= 1;
        UpdatePetDisplayCheck_guess();
        return 0;
    }
    return Fallback_guess(first, second, third);
}

// Builds the context menu: the standard window submenu (0x19F3, "Window") and Pet Display (0xC36, item
// 0x32).
// FUNCTION: TITANIUM 0x005451B9
// @early-stop: unknown, diff ndiff=1
void CPlayerWndView_guess::CreateContextMenu_guess()
{
    contextMenu_0174_guess = 0;
    contextMenu_0174_guess = new CContextMenu_guess(0, 0, BoxInit_guess());
    {
        CXStr label(pStringTable->getString(0x19f3, 0));
        contextMenu_0174_guess->Pick_guess(&label, pinstCContextMenuManager_guess->field_1154_guess + 0x80000000, 0, -1);
    }
    contextMenu_0174_guess->Prepare_guess();
    {
        CXStr label(pStringTable->getString(0xc36, 0));
        value = contextMenu_0174_guess->Pick_guess(&label, 0x32, 0, -1);
    }
    UpdatePetDisplayCheck_guess();
    contextMenuId_0150_guess = pinstCContextMenuManager_guess->AddMenu_guess(contextMenu_0174_guess);
}

// Player window constructor: finds PetHP and the A_AttackIndicatorAnim animation, builds the context menu
// (0x005451B9) and hides the attack indicator (0x00544E63).
// FUNCTION: TITANIUM 0x005452F7
CPlayerWndView_guess::CPlayerWndView_guess(CXWnd* parent)
    : SidlBase_guess(parent, "PlayerWindow", -1, 1, 0) {
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_guess | 0x800;
        flag_018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        petHp_guess = ((CSidlScreenWnd*)this)->GetChildItem("PetHP");
        controller = GetChildAnimation_guess("A_AttackIndicatorAnim");
        petDisplay_0178_guess = 1;
        CreateContextMenu_guess();
        ResetAttackIndicator_guess();
    }
}
