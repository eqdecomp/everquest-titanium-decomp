/* CPotionBeltWnd: window, constructor 0x00548B9D (tu_199_PotionBeltWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPOTIONBELTWND_H
#define TITANIUM_WND_CPOTIONBELTWND_H

#include "titanium/wnd_views.h"

struct CPotionBeltWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x190 - 0x15C];

    // EXTERNAL: TITANIUM 0x00548B9D CPotionBeltWnd_guess::CPotionBeltWnd_guess
    CPotionBeltWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00548564 CPotionBeltWnd_guess::Refresh_guess
    void Refresh_guess();
};
#define pinstCPotionBeltWnd_guess EQ_GLOBAL(CPotionBeltWnd_guess*, 0x00850BCC)

#endif
