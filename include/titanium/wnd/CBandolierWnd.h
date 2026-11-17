/* CBandolierWnd: window, constructor 0x004DBBC0 (tu_126_BandolierWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBANDOLIERWND_H
#define TITANIUM_WND_CBANDOLIERWND_H

#include "titanium/wnd_views.h"

struct CBandolierWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x19C - 0x15C];

    // EXTERNAL: TITANIUM 0x004DBBC0 CBandolierWnd_guess::CBandolierWnd_guess
    CBandolierWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004DB1A2 CBandolierWnd_guess::RefreshRows_guess
    void RefreshRows_guess();
    // EXTERNAL: TITANIUM 0x004DB2D1 CBandolierWnd_guess::RebuildList_guess
    void RebuildList_guess();
    // EXTERNAL: TITANIUM 0x004DB5D5 CBandolierWnd_guess::Refresh_guess
    void Refresh_guess(int unused_guess, int* data_guess);
};
#define pinstCBandolierWnd_guess EQ_GLOBAL(CBandolierWnd_guess*, 0x00850BC8)

#endif
