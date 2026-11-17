/* CTipWnd: window, constructor 0x00564B30 (tu_228_TipWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTIPWND_H
#define TITANIUM_WND_CTIPWND_H

#include "titanium/wnd_views.h"

struct CTipWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1CC - 0x15C];

    // EXTERNAL: TITANIUM 0x00564B30 CTipWnd_guess::CTipWnd_guess
    CTipWnd_guess(CXWnd* parent, int kind);
    // EXTERNAL: TITANIUM 0x00564141 CTipWnd_guess::EnableAllTips_guess
    void EnableAllTips_guess();
    // EXTERNAL: TITANIUM 0x00564E7E CTipWnd_guess::selectTip_guess
    char selectTip_guess(int value, char allowDisabled);
};
#define pinstCTipWndOFDAY_guess EQ_GLOBAL(CTipWnd_guess*, 0x009928DC)
#define pinstCTipWndCONTEXT_guess EQ_GLOBAL(CTipWnd_guess*, 0x009928E0)

#endif
