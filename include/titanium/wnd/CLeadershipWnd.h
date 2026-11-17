/* CLeadershipWnd: window, constructor 0x00526C4F (tu_179_LeadershipWindow). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CLEADERSHIPWND_H
#define TITANIUM_WND_CLEADERSHIPWND_H

#include "titanium/wnd_views.h"

struct CLeadershipWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x4D4 - 0x15C];

    // EXTERNAL: TITANIUM 0x00526C4F CLeadershipWnd_guess::CLeadershipWnd_guess
    CLeadershipWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00527130 CLeadershipWnd_guess::UpdateRows_guess
    void UpdateRows_guess();
};
#define pinstCLeadershipWnd_guess EQ_GLOBAL(CLeadershipWnd_guess*, 0x00991C24)

#endif
