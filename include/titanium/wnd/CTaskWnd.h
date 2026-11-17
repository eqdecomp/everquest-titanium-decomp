/* CTaskWnd: window, constructor 0x0055FC8B (tu_223_TaskWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTASKWND_H
#define TITANIUM_WND_CTASKWND_H

#include "titanium/wnd_views.h"

struct CTaskWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* dialogNotifierVftable_15C_guess;    /* vptr of the confirmation-notifier base (0x0063FD9C family) */
    /*0x160*/ unsigned char pad_160[0x890 - 0x160];

    // EXTERNAL: TITANIUM 0x0055FC8B CTaskWnd_guess::CTaskWnd_guess
    CTaskWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0055F192 CTaskWnd_guess::FillQuestHistory_guess
    void FillQuestHistory_guess(void* state_guess);
    // EXTERNAL: TITANIUM 0x0055F706 CTaskWnd_guess::RequestRefresh_guess
    void RequestRefresh_guess();
    // EXTERNAL: TITANIUM 0x0055FA4C CTaskWnd_guess::RefreshSharedTaskMembers_guess
    void RefreshSharedTaskMembers_guess();
};
#define pinstCTaskWnd_guess EQ_GLOBAL(CTaskWnd_guess*, 0x00992858)

#endif
