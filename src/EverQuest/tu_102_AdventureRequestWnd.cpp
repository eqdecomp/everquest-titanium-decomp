// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 102: a hint from compare/tumap.py.
// CAdventureRequestWnd constructor (screen "AdventureRequestWnd", vtable 0x64E878): the LDoN adventure
// request window. CAdventureRequestWnd_guess is CAdventureRequestWnd; CComboWnd_guess is CComboWnd.
#include "titanium/types.h"

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    Base_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess() ;
};

struct CComboWnd_guess {
    // EXTERNAL: TITANIUM 0x0059C360 CComboWnd_guess::SetCurSel_guess
    void SetCurSel_guess(int index);
    // EXTERNAL: TITANIUM 0x0059C330 CComboWnd_guess::SetColors_guess
    void SetColors_guess(int a, int b, int c);
};

// EXTERNAL: TITANIUM 0x0064E878 ??_7CAdventureRequestWnd_guess@@6B@
struct CAdventureRequestWnd_guess : Base_guess {
    char pad_004[0x62];
    unsigned char flags_066;
    char pad_067[0xbd];
    void* sidlPiece_124;
    char pad_128[0x30];
    int field_158;
    CXWnd* npcLabel_15c;
    CXWnd* npcText_160;
    CXWnd* riskLabel_164;
    CComboWnd_guess* riskCombo_168;
    CComboWnd_guess* typeCombo_16c;
    CXWnd* requestButton_170;
    CXWnd* viewStatsButton_174;
    CXWnd* enterTimeLabel_178;
    CXWnd* enterTimeLeftLabel_17c;
    CXWnd* completeTimeLabel_180;
    CXWnd* completeTimeLeftLabel_184;
    CXWnd* progressLabel_188;
    CXWnd* progressTextLabel_18c;
    CXWnd* acceptButton_190;
    CXWnd* declineButton_194;

    CAdventureRequestWnd_guess(CXWnd* parent);
};

// Binds the 15 AdvRqst_ children and starts both the risk and the type combo box on their first choice.
// FUNCTION: TITANIUM 0x004D642B
CAdventureRequestWnd_guess::CAdventureRequestWnd_guess(CXWnd* parent)
    // Sidl flags: everything but 0x200; INI version 1.
    : Base_guess(parent, "AdventureRequestWnd", 0xfffffdff, 1, 0) {
    npcLabel_15c = 0;
    npcText_160 = 0;
    riskLabel_164 = 0;
    riskCombo_168 = 0;
    typeCombo_16c = 0;
    requestButton_170 = 0;
    viewStatsButton_174 = 0;
    enterTimeLabel_178 = 0;
    enterTimeLeftLabel_17c = 0;
    completeTimeLabel_180 = 0;
    completeTimeLeftLabel_184 = 0;
    progressLabel_188 = 0;
    progressTextLabel_18c = 0;
    acceptButton_190 = 0;
    declineButton_194 = 0;
    if (sidlPiece_124 != 0) {
        flags_066 |= 1;
        field_158 = 0x27;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        npcLabel_15c = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_NPCLabel");
        npcText_160 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_NPCText");
        riskLabel_164 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_RiskLabel");
        riskCombo_168 = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_RiskCombobox");
        typeCombo_16c = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_TypeCombobox");
        requestButton_170 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_RequestButton");
        viewStatsButton_174 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_ViewStatsButton");
        enterTimeLabel_178 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_EnterTimeLabel");
        enterTimeLeftLabel_17c = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_EnterTimeLeftLabel");
        completeTimeLabel_180 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_CompleteTimeLabel");
        completeTimeLeftLabel_184 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_CompleteTimeLeftLabel");
        progressLabel_188 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_ProgressLabel");
        progressTextLabel_18c = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_ProgressTextLabel");
        acceptButton_190 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_AcceptButton");
        declineButton_194 = ((CSidlScreenWnd*)this)->GetChildItem("AdvRqst_DeclineButton");
        if (riskCombo_168 != 0) {
            riskCombo_168->SetCurSel_guess(0);
            riskCombo_168->SetColors_guess(-1, 0xffffff00, 0xff808080);
        }
        if (typeCombo_16c != 0) {
            typeCombo_16c->SetCurSel_guess(0);
            typeCombo_16c->SetColors_guess(-1, 0xffffff00, 0xff808080);
        }
    }
}
