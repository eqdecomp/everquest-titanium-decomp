// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 220: a hint from compare/tumap.py.
// CTargetWnd (screen "TargetWindow", vtable 0x65D6C0): the target's HP labels and the target box
// animation, tinted by how the target cons. CTargetWndView_guess is CTargetWnd; g_905d04_guess is pinstTarget,
// g_classifier_guess pCharData and g_info_guess (0x9917E4) CChatManager.
#include "titanium/types.h"

struct Timer_guess {
    char pad0[0x24];
    int bounds[2];
    char pad2c[1];
    char flag;
    // EXTERNAL: TITANIUM 0x005B1730 Timer_guess::Update
    void Update(int);
    // EXTERNAL: TITANIUM 0x005B1910 Timer_guess::Draw
    void Draw(int*, int, int, int);
};

struct Holder_guess {
    char pad0[0x64];
    Timer_guess* timer;
};

struct Interface_guess {
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48(bool, int);
};

struct EQ_CharacterView_guess {
    // EXTERNAL: TITANIUM 0x004BC20B EQ_CharacterView_guess::Classify
    int Classify(int);
};

struct SidlPiece_guess {
    char pad0[0x60];
    unsigned int style_060;                  // 0x060
};

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850).
struct TargetBase_guess {
    virtual void Slot00_guess();
    char pad_0004[0x14];
    unsigned char flag_018;                  // 0x018
    char pad_0019[0x4b];
    unsigned int windowStyle_064;            // 0x064 (CXWnd::WindowStyle)
    char pad_0068[0xbc];
    SidlPiece_guess* sidlPiece_124;          // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_0128[0x34];
    // EXTERNAL: TITANIUM 0x005A3850 ??0TargetBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    TargetBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1TargetBase_guess@@QAE@XZ
    ~TargetBase_guess();
};

struct CXPoint;

struct Rect_guess {
    int fields[4];
    // EXTERNAL: TITANIUM 0x004D9139 Rect_guess::Combine
    void Combine(const CXPoint&, const int*);
};

#include "titanium/layouts/geometry.h"
#include "titanium/wnd/CChatManager.h"

// EXTERNAL: TITANIUM 0x0065D6C0 ??_7CTargetWndView_guess@@6B@
struct CTargetWndView_guess : TargetBase_guess {
    Interface_guess* hpLabel_015c_guess;
    Interface_guess* hpPercLabel_0160_guess;
    Holder_guess* holder164;
    int lastTarget_0168_guess;
    int tintColor_016c_guess;
    CTargetWndView_guess(CXWnd* parent);
    void Reset();
    void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A2490 CTargetWndView_guess::FindHolder_guess
    Holder_guess* FindHolder_guess(const CXStr& name);
    // EXTERNAL: TITANIUM 0x005A0E50 CTargetWndView_guess::OnProcessFrame
    void OnProcessFrame();
    // EXTERNAL: TITANIUM 0x0059D6C0 CTargetWndView_guess::GetClientClipRect
    int GetClientClipRect(Rect_guess*);
    int Draw_guess();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual int* Slot57(Rect_guess*);
};

// EXTERNAL: TITANIUM 0x0059DD30 Check_guess
char __cdecl Check_guess();
// EXTERNAL: TITANIUM 0x00491E30 GetConColor_guess
int __cdecl GetConColor_guess(int);

#define g_classifier_guess EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)
#define g_905d04_guess EQ_GLOBAL(int, 0x00905D04)

// CTargetWnd constructor: binds HPLabel, HPPercLabel and the A_TargetBoxStaticAnim piece, then resets.
// FUNCTION: TITANIUM 0x0055BA0F
CTargetWndView_guess::CTargetWndView_guess(CXWnd* parent) : TargetBase_guess(parent, "TargetWindow", -1, 1, 0) {
    hpPercLabel_0160_guess = 0;
    hpLabel_015c_guess = 0;
    holder164 = 0;
    // Overwritten with 0 by Reset below whenever the SIDL piece exists (as original).
    lastTarget_0168_guess = 0x12;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060 | 0x800;
        flag_018 = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        hpPercLabel_0160_guess = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("HPPercLabel");
        hpLabel_015c_guess = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("HPLabel");
        holder164 = FindHolder_guess("A_TargetBoxStaticAnim");
        Reset();
    }
}

// No target: hides both labels, stops the box animation and drops the tint and the remembered target.
// FUNCTION: TITANIUM 0x0055B87E
void CTargetWndView_guess::Reset() {
    tintColor_016c_guess = 0;
    Holder_guess* holder = holder164;
    if (holder != 0) {
        Timer_guess* timer = holder->timer;
        if (timer != 0) {
            timer->flag = 0;
            timer->Update(0);
        }
    }
    lastTarget_0168_guess = 0;
    if (hpPercLabel_0160_guess != 0) {
        hpPercLabel_0160_guess->Slot48(false, 1);
    }
    if (hpLabel_015c_guess != 0) {
        hpLabel_015c_guess->Slot48(false, 1);
    }
}

// Per frame (OnProcessFrame override, vtable slot 43): on a target change shows or hides the labels and
// recomputes the tint, then the base CXWnd::OnProcessFrame.
// FUNCTION: TITANIUM 0x0055B8DF
void CTargetWndView_guess::OnProcessFrame_guess() {
    if (Check_guess() && lastTarget_0168_guess != g_905d04_guess) {
        if (hpLabel_015c_guess != 0) {
            hpLabel_015c_guess->Slot48(g_905d04_guess != 0, 1);
        }
        if (hpPercLabel_0160_guess != 0) {
            hpPercLabel_0160_guess->Slot48(g_905d04_guess != 0, 1);
        }
        if (g_classifier_guess != 0 && g_905d04_guess != 0) {
            int kind = g_classifier_guess->Classify(g_905d04_guess);
            // 0x4BC20B probably rates the target against the player (con level); kind 6 means no tint. The
            // kind maps through 0x491E30 to a colour index for CChatManager::GetRGBAFromIndex.
            if (kind != 6) {
                tintColor_016c_guess = pinstCChatManager_guess->GetRGBAFromIndex(GetConColor_guess(kind));
            } else {
                tintColor_016c_guess = 0;
            }
        }
        lastTarget_0168_guess = g_905d04_guess;
    }
    return OnProcessFrame();
}

// Draw override (vtable slot 3): with a target, draws the box animation (CTextureAnimation::Draw) at its
// offset inside the client clip rect, in the con colour.
// FUNCTION: TITANIUM 0x0055B98C
// @early-stop: unknown, diff ndiff=6
int CTargetWndView_guess::Draw_guess() {
    if (g_905d04_guess != 0 && holder164 != 0 && holder164->timer != 0) {
        Timer_guess* timer = holder164->timer;
        Rect_guess view;
        Rect_guess rect;
        rect.fields[3] = 0;
        rect.fields[2] = 0;
        rect.fields[1] = 0;
        rect.fields[0] = 0;
        CXPoint point = *(CXPoint*)Slot57(&view);
        rect.Combine(point, timer->bounds);
        timer->Draw(rect.fields, GetClientClipRect(&view), tintColor_016c_guess, 0xff000000);
    }
    return 0;
}
