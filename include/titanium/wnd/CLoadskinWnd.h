/* CLoadskinWnd: window, constructor 0x0052AA42 (tu_181_LoadskinWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CLOADSKINWND_H
#define TITANIUM_WND_CLOADSKINWND_H

#include "titanium/wnd_views.h"

struct CLoadskinWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];

    // EXTERNAL: TITANIUM 0x0052AA42 CLoadskinWnd_guess::CLoadskinWnd_guess
    CLoadskinWnd_guess(CXWnd* parent);
};
#define pinstCLoadskinWnd_guess EQ_GLOBAL(CLoadskinWnd_guess*, 0x00850BD8)

#endif
