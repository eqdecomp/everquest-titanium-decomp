/* CBreathWnd: window, constructor 0x004E896D (tu_135_BreathWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBREATHWND_H
#define TITANIUM_WND_CBREATHWND_H

#include "titanium/wnd_views.h"

struct CBreathWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x160 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E896D CBreathWnd_guess::CBreathWnd_guess
    CBreathWnd_guess(CXWnd* parent);
};
#define pinstCBreathWnd_guess EQ_GLOBAL(CBreathWnd_guess*, 0x00850BF8)

#endif
