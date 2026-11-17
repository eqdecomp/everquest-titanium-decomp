/* CTrackingWnd: window, constructor 0x005663A4 (tu_230_TrackingWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRACKINGWND_H
#define TITANIUM_WND_CTRACKINGWND_H

#include "titanium/wnd_views.h"

struct CTrackingWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x401C - 0x15C];

    // EXTERNAL: TITANIUM 0x005663A4 CTrackingWnd_guess::CTrackingWnd_guess
    CTrackingWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00566CB3 CTrackingWnd_guess::RequestTrackList_guess
    void RequestTrackList_guess();
    // EXTERNAL: TITANIUM 0x00566CE6 CTrackingWnd_guess::SortTrackingList_guess
    void SortTrackingList_guess(char notify_guess);
    // EXTERNAL: TITANIUM 0x00566FE6 CTrackingWnd_guess::ApplyTrackingFilters_guess
    void ApplyTrackingFilters_guess(char flag_guess);
    // EXTERNAL: TITANIUM 0x005672F6 CTrackingWnd_guess::RemoveSpawn_guess
    void RemoveSpawn_guess(void* player);
};
#define pinstCTrackingWnd_guess EQ_GLOBAL(CTrackingWnd_guess*, 0x00850C64)

#endif
