/* CProgressionSelectionWnd: window, constructor 0x0054A413 (tu_200_ProgressionSelectionWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPROGRESSIONSELECTIONWND_H
#define TITANIUM_WND_CPROGRESSIONSELECTIONWND_H

#include "titanium/wnd_views.h"

struct CProgressionSelectionWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x218 - 0x15C];

    // EXTERNAL: TITANIUM 0x0054A413 CProgressionSelectionWnd_guess::CProgressionSelectionWnd_guess
    CProgressionSelectionWnd_guess(CXWnd* parent);
};
#define pinstCProgressionSelectionWnd_guess EQ_GLOBAL(CProgressionSelectionWnd_guess*, 0x00991E78)

#endif
