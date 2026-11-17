// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 206: a hint from compare/tumap.py.
// CRespawnWnd constructor (screen "RespawnWnd", vtable 0x65C120): the list of respawn options after death.
// CRespawnWnd_guess is CRespawnWnd.
#include "titanium/types.h"

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100);
// ListFields_guess (layouts/ui.h): the two CListWnd fields the ctor writes.
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065C120 ??_7CRespawnWnd_guess@@6B@
struct CRespawnWnd_guess : CSidlScreenWndBase {
    CXWnd* selectButton_15c;                // 0x15C
    CListWnd* optionsList_160;              // 0x160
    CRespawnWnd_guess(CXWnd* parent);
};

// Binds SelectButton and OptionsList and colours the list like the other selection lists.
// FUNCTION: TITANIUM 0x00551F98
CRespawnWnd_guess::CRespawnWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "RespawnWnd", -1, 1, 0) {
    selectButton_15c = 0;
    optionsList_160 = 0;
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        selectButton_15c = ((CSidlScreenWnd*)this)->GetChildItem("SelectButton");
        optionsList_160 = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsList");
        if (optionsList_160 != 0) {
            optionsList_160->SetColors(-1, 0xffffff00, 0xff808080);
            // Light blue (ARGB) at list +0x16C, as in CMIZoneSelectWnd and CAvaZoneWnd.
            ((ListFields_guess*)optionsList_160)->textColor_guess = 0xff8aa3ff;
            ((ListFields_guess*)optionsList_160)->flag_guess = 1;
        }
    }
}
