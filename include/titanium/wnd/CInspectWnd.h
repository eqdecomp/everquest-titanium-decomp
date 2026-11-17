/* CInspectWnd: window, constructor 0x0051675E (tu_169_InspectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CINSPECTWND_H
#define TITANIUM_WND_CINSPECTWND_H

#include "titanium/wnd_views.h"

struct CInspectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x164 - 0x15C];
    /*0x164*/ void* slots_164_guess[22];    /* 22 entries (0x0051639A) */
    /*0x1BC*/ unsigned char pad_1BC[0x1C4 - 0x1BC];

    // EXTERNAL: TITANIUM 0x0051675E CInspectWnd_guess::CInspectWnd_guess
    CInspectWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00516747 CInspectWnd_guess::PlayerBeingDeleted_guess
    void PlayerBeingDeleted_guess(void* value);
};
#define pinstCInspectWnd_guess EQ_GLOBAL(CInspectWnd_guess*, 0x00850C68)

#endif
