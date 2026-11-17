/* CVideoModesWnd: window, constructor 0x0056F9FA (tu_236_VideoModesWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CVIDEOMODESWND_H
#define TITANIUM_WND_CVIDEOMODESWND_H

#include "titanium/wnd_views.h"

struct CVideoModesWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* dialogNotifierVftable_15C_guess;    /* vptr of the confirmation-notifier base (0x0063FD9C family) */
    /*0x160*/ unsigned char pad_160[0x170 - 0x160];

    // EXTERNAL: TITANIUM 0x0056F9FA CVideoModesWnd_guess::CVideoModesWnd_guess
    CVideoModesWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056F37D CVideoModesWnd_guess::OnModeChanged_guess
    void OnModeChanged_guess();
};
#define pinstCVideoModesWnd_guess EQ_GLOBAL(CVideoModesWnd_guess*, 0x00850C78)

#endif
