/* CTargetOfTargetWnd: window, constructor 0x0055B772 (tu_219_TargetOfTargetWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTARGETOFTARGETWND_H
#define TITANIUM_WND_CTARGETOFTARGETWND_H

#include "titanium/wnd_views.h"

struct CTargetOfTargetWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];

    // EXTERNAL: TITANIUM 0x0055B772 CTargetOfTargetWnd_guess::CTargetOfTargetWnd_guess
    CTargetOfTargetWnd_guess(CXWnd* parent);
};
#define pinstCTargetOfTargetWnd_guess EQ_GLOBAL(CTargetOfTargetWnd_guess*, 0x009927EC)

#endif
