/* CGiveWnd: window, constructor 0x0050752B (tu_161_GiveWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGIVEWND_H
#define TITANIUM_WND_CGIVEWND_H

#include "titanium/wnd_views.h"

struct CGiveWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x18C - 0x15C];

    // EXTERNAL: TITANIUM 0x0050752B CGiveWnd_guess::CGiveWnd_guess
    CGiveWnd_guess(CXWnd* parent);
};
#define pinstCGiveWnd_guess EQ_GLOBAL(CGiveWnd_guess*, 0x00850C60)

#endif
