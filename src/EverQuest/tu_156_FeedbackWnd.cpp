// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 156: a hint from compare/tumap.py.
// CFeedbackWnd constructor (screen "FeedbackWindow", vtable 0x654270): the /feedback form. CFeedbackWndView_guess
// is CFeedbackWnd; g_charData_guess is pCharData, whose name sits in the virtual base (+0x3C there).
#include "titanium/types.h"

struct FeedbackSidlTemplate_guess {
    char pad_000[0x60];
    unsigned int style_060;             // 0x060
};

struct FeedbackSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1FeedbackSidlBase_guess@@UAE@XZ
    virtual ~FeedbackSidlBase_guess();
    char pad_004[0x60];
    unsigned int windowStyle_064;       // 0x064 (CXWnd::WindowStyle)
    char pad_068[0xbc];
    FeedbackSidlTemplate_guess* sidlPiece_124;  // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_128[0x34];
    // EXTERNAL: TITANIUM 0x005A3850 ??0FeedbackSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    FeedbackSidlBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x0059DD20 FeedbackSidlBase_guess::Finish_guess
    void Finish_guess();
};

// Text box / edit window: virtual slot 0xFC is SetWindowText, the edit's SetMaxChars is direct.
struct CEditBaseWnd_guess {
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
    virtual void SetWindowText_guess(const CXStr& text);    // 0xFC
    // EXTERNAL: TITANIUM 0x004D7EBC CEditBaseWnd_guess::SetMaxChars
    void SetMaxChars(int maxChars);
};

// Character data: the name sits in the virtual base, reached through the vbptr at +8.
struct FeedbackCharPrefix_guess {
    virtual void Slot00_guess();
    int field04_guess;
};

#include "titanium/layouts/core.h"

struct EQ_CharacterView_guess : FeedbackCharPrefix_guess, virtual FeedbackCharBase_guess {
};

// EXTERNAL: TITANIUM 0x00654270 ??_7CFeedbackWndView_guess@@6B@
struct CFeedbackWndView_guess : FeedbackSidlBase_guess {
    CXWnd* userName_15c;                // 0x15c FBKW_UserName
    CXWnd* feedbackInput_160;           // 0x160 FBKW_FeedbackInput
    CXWnd* cancelButton_164;            // 0x164 FBKW_CancelButton
    CXWnd* sendButton_168;              // 0x168 FBKW_SendButton
    CFeedbackWndView_guess(CXWnd* parent);
};

#define g_charData_guess EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)

// Mac: CFeedbackWnd::CFeedbackWnd. Binds the four FBKW_ children, fills the user name with the
// character's name and caps the feedback text at 1023 characters (CEditBaseWnd::SetMaxChars).
// FUNCTION: TITANIUM 0x005013C9
CFeedbackWndView_guess::CFeedbackWndView_guess(CXWnd* parent)
    : FeedbackSidlBase_guess(parent, "FeedbackWindow", -1, 1, 0) {
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        userName_15c = ((CSidlScreenWnd*)this)->GetChildItem("FBKW_UserName");
        feedbackInput_160 = ((CSidlScreenWnd*)this)->GetChildItem("FBKW_FeedbackInput");
        cancelButton_164 = ((CSidlScreenWnd*)this)->GetChildItem("FBKW_CancelButton");
        sendButton_168 = ((CSidlScreenWnd*)this)->GetChildItem("FBKW_SendButton");
        ((CEditBaseWnd_guess*)userName_15c)->SetWindowText_guess(g_charData_guess->Name);
        ((CEditBaseWnd_guess*)feedbackInput_160)->SetMaxChars(0x3ff);
        Finish_guess();
    }
}
