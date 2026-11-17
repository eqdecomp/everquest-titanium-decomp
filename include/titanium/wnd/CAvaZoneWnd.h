/* CAvaZoneWnd: window, constructor 0x004DAA44 (tu_125_AvaZoneWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CAVAZONEWND_H
#define TITANIUM_WND_CAVAZONEWND_H

#include "titanium/wnd_views.h"

struct CAvaZoneWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x3F90C - 0x15C];

    // EXTERNAL: TITANIUM 0x004DAA44 CAvaZoneWnd_guess::CAvaZoneWnd_guess
    CAvaZoneWnd_guess(CXWnd* parent);
};
#define pinstCAvaZoneWnd_guess EQ_GLOBAL(CAvaZoneWnd_guess*, 0x00850CB4)

#endif
