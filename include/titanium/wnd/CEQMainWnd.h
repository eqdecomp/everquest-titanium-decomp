/* CEQMainWnd: window, constructor 0x004FFC7F (tu_152_EQMainWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CEQMAINWND_H
#define TITANIUM_WND_CEQMAINWND_H

#include "titanium/wnd_views.h"

struct CEQMainWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];

    // EXTERNAL: TITANIUM 0x004FFC7F CEQMainWnd_guess::CEQMainWnd_guess
    CEQMainWnd_guess(CXWnd* parent);
};
#define pinstCEQMainWnd_guess EQ_GLOBAL(CEQMainWnd_guess*, 0x00991930)

#endif
