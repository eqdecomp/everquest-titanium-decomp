/* CPvPStatsWnd: window, constructor 0x0054C020 (tu_202_PvPStatsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPVPSTATSWND_H
#define TITANIUM_WND_CPVPSTATSWND_H

#include "titanium/wnd_views.h"

struct CPvPStatsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1A4 - 0x15C];

    // EXTERNAL: TITANIUM 0x0054C020 CPvPStatsWnd_guess::CPvPStatsWnd_guess
    CPvPStatsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054C4CC CPvPStatsWnd_guess::Refresh_guess
    void Refresh_guess();
};
#define pinstCPvPStatsWnd_guess EQ_GLOBAL(CPvPStatsWnd_guess*, 0x00991EB0)

#endif
