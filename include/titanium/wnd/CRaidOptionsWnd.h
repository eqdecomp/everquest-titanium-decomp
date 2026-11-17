/* CRaidOptionsWnd: window, constructor 0x0054DEB0 (tu_204_RaidOptionsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CRAIDOPTIONSWND_H
#define TITANIUM_WND_CRAIDOPTIONSWND_H

#include "titanium/wnd_views.h"

struct CRaidOptionsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1C0 - 0x15C];

    // EXTERNAL: TITANIUM 0x0054DEB0 CRaidOptionsWnd_guess::CRaidOptionsWnd_guess
    CRaidOptionsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054DB7C CRaidOptionsWnd_guess::AddLooterToList_guess
    void AddLooterToList_guess(const char* source);
    // EXTERNAL: TITANIUM 0x0054DBDD CRaidOptionsWnd_guess::ClearLooterList_guess
    void ClearLooterList_guess();
};
#define pinstCRaidOptionsWnd_guess EQ_GLOBAL(CRaidOptionsWnd_guess*, 0x00850BF4)

#endif
