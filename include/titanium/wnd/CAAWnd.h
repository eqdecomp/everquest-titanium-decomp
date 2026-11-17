/* CAAWnd: window, constructor 0x004D0A8F (tu_098_AAWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CAAWND_H
#define TITANIUM_WND_CAAWND_H

#include "titanium/wnd_views.h"

struct CAAWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* dialogNotifierVftable_15C_guess;    /* vptr of the confirmation-notifier base (0x0063FD9C family) */
    /*0x160*/ unsigned char pad_160[0x1384 - 0x160];

    // EXTERNAL: TITANIUM 0x004D0A8F CAAWnd_guess::CAAWnd_guess
    CAAWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D1484 CAAWnd_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004D1CC9 CAAWnd_guess::SelectAbility_guess
    void SelectAbility_guess(int id_guess);
};
#define pinstCAAWnd_guess EQ_GLOBAL(CAAWnd_guess*, 0x00850BD0)

#endif
