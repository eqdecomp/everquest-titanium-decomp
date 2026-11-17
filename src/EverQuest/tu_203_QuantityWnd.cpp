// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 203: a hint from compare/tumap.py.
// CQuantityWnd constructor (screen "QuantityWnd", vtable 0x65B8E0): the slider that asks how many of a stack
// or how much coin to move. CQuantityWndView_guess is CQuantityWnd (layout in types.h).
#include "titanium/types.h"

/* ---- CQuantityWnd::CQuantityWnd(CXWnd*) (0x0054D5AC) ------------------------------------------------
 * Layout: include/titanium/types.h CQuantityWnd (0x174). The ctor needs a polymorphic class with the
 * real CSidlScreenWnd base ctor/dtor, so it derives from CSidlScreenWndBase; header methods are called through the
 * CSidlScreenWnd layout view. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct QuantitySliderInput_guess {
    char pad_000[0x230];
    int maxChars_230;                       // 0x230
};

// EXTERNAL: TITANIUM 0x0065B8E0 ??_7CQuantityWndView_guess@@6B@
struct CQuantityWndView_guess : CSidlScreenWndBase {
    void* value_15c;                        // 0x15c
    int field_160;                          // 0x160
    void* callback_164;                     // 0x164
    CXWnd* slider_168;                      // 0x168 QTYW_Slider
    QuantitySliderInput_guess* sliderInput_16c;  // 0x16c QTYW_SliderInput
    CXWnd* acceptButton_170;                // 0x170 QTYW_Accept_Button
    CQuantityWndView_guess(CXWnd* parent);
};

// Mac: CQuantityWnd::CQuantityWnd. Binds the slider, its text input and Accept; no reply callback yet
// (+0x164).
// FUNCTION: TITANIUM 0x0054D5AC
CQuantityWndView_guess::CQuantityWndView_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "QuantityWnd") {
    value_15c = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10000;
        field_158_guess = 0x28;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        slider_168 = ((CSidlScreenWnd*)this)->GetChildItem("QTYW_Slider");
        sliderInput_16c = (QuantitySliderInput_guess*)((CSidlScreenWnd*)this)->GetChildItem("QTYW_SliderInput");
        acceptButton_170 = ((CSidlScreenWnd*)this)->GetChildItem("QTYW_Accept_Button");
        // Three digits in the input: at most 999 by hand.
        sliderInput_16c->maxChars_230 = 3;
        // 0x59DB90 with 199, probably the Z layer (Mac SetZLayer, low): above ordinary windows.
        FUN_0059db90_guess(199);
        callback_164 = 0;
    }
}
