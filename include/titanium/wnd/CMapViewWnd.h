/* CMapViewWnd: window, constructor 0x00535CAA (tu_187_MapViewWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMAPVIEWWND_H
#define TITANIUM_WND_CMAPVIEWWND_H

#include "titanium/wnd_views.h"

struct CMapViewWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char field_15C_guess;
    /*0x15D*/ unsigned char pad_15D[0x180 - 0x15D];
    /*0x180*/ char field_180_guess[104];
    /*0x1E8*/ unsigned char pad_1E8[0x248 - 0x1E8];
    /*0x248*/ void* field_248_guess;
    /*0x24C*/ void* field_24C_guess;
    /*0x250*/ unsigned char pad_250[0x274 - 0x250];

    // EXTERNAL: TITANIUM 0x00535CAA CMapViewWnd_guess::CMapViewWnd_guess
    CMapViewWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00495A87 CMapViewWnd_guess::check_guess
    char check_guess();
    // EXTERNAL: TITANIUM 0x00533238 CMapViewWnd_guess::StartAutoMap_guess
    void StartAutoMap_guess();
    // EXTERNAL: TITANIUM 0x00534497 CMapViewWnd_guess::StopAutoMap_guess
    void StopAutoMap_guess();
    // EXTERNAL: TITANIUM 0x00536741 CMapViewWnd_guess::SelectMap_guess
    void SelectMap_guess();
};
#define pinstCMapViewWnd_guess EQ_GLOBAL(CMapViewWnd_guess*, 0x00850BFC)

#endif
