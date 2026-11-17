/* CCompassWnd: window, constructor 0x004FA183 (tu_147_CompassWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCOMPASSWND_H
#define TITANIUM_WND_CCOMPASSWND_H

#include "titanium/wnd_views.h"

struct CCompassWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1C0 - 0x15C];

    // EXTERNAL: TITANIUM 0x004FA183 CCompassWnd_guess::CCompassWnd_guess
    CCompassWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004F9C6F CCompassWnd_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x004F9DA6 CCompassWnd_guess::RemoveMarker_guess
    void RemoveMarker_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x004FA167 CCompassWnd_guess::AddMarker_guess
    int AddMarker_guess(int value_guess);
};
#define pinstCCompassWnd_guess EQ_GLOBAL(CCompassWnd_guess*, 0x00850C88)

#endif
