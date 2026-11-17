/* CAdvancedDisplayOptionsWnd: window, constructor 0x004D53E2 (tu_100_AdvancedDisplayOptionsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CADVANCEDDISPLAYOPTIONSWND_H
#define TITANIUM_WND_CADVANCEDDISPLAYOPTIONSWND_H

#include "titanium/wnd_views.h"

struct CAdvancedDisplayOptionsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x18C - 0x15C];

    // EXTERNAL: TITANIUM 0x004D53E2 CAdvancedDisplayOptionsWnd_guess::CAdvancedDisplayOptionsWnd_guess
    CAdvancedDisplayOptionsWnd_guess(CXWnd* parent);
};
#define pinstCAdvancedDisplayOptionsWnd_guess EQ_GLOBAL(CAdvancedDisplayOptionsWnd_guess*, 0x00850C7C)

#endif
