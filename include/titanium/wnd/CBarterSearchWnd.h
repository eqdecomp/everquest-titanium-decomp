/* CBarterSearchWnd: window, constructor 0x004DEEB6 (tu_129_BarterSearchWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBARTERSEARCHWND_H
#define TITANIUM_WND_CBARTERSEARCHWND_H

#include "titanium/wnd_views.h"

struct CBarterSearchWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D0 - 0x15C];
    /*0x1D0*/ int field_1D0_guess;
    /*0x1D4*/ char field_1D4_guess;
    /*0x1D5*/ unsigned char pad_1D5[0x1D8 - 0x1D5];

    // EXTERNAL: TITANIUM 0x004DEEB6 CBarterSearchWnd_guess::CBarterSearchWnd_guess
    CBarterSearchWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004DF70E CBarterSearchWnd_guess::AddBuyLine_guess
    void AddBuyLine_guess(int value_guess, void* buffer_guess);
};
#define pinstCBarterSearchWnd_guess EQ_GLOBAL(CBarterSearchWnd_guess*, 0x009915EC)

#endif
