/* CMapToolbarWnd: window, constructor 0x005317CC (tu_186_MapToolbarWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMAPTOOLBARWND_H
#define TITANIUM_WND_CMAPTOOLBARWND_H

#include "titanium/wnd_views.h"

struct CMapToolbarWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* field_15C_guess;
    /*0x160*/ unsigned char pad_160[0x19C - 0x160];

    // EXTERNAL: TITANIUM 0x005317CC CMapToolbarWnd_guess::CMapToolbarWnd_guess
    CMapToolbarWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00531779 CMapToolbarWnd_guess::SetAutoMapCheck_guess
    void SetAutoMapCheck_guess(int argument);
};
#define pinstCMapToolbarWnd_guess EQ_GLOBAL(CMapToolbarWnd_guess*, 0x00850C00)

#endif
