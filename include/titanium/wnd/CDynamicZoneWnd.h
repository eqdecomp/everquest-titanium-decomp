/* CDynamicZoneWnd: window, constructor 0x004FE619 (tu_151_DynamicZoneWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CDYNAMICZONEWND_H
#define TITANIUM_WND_CDYNAMICZONEWND_H

#include "titanium/wnd_views.h"

struct CDynamicZoneWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1A0 - 0x15C];

    // EXTERNAL: TITANIUM 0x004FE619 CDynamicZoneWnd_guess::CDynamicZoneWnd_guess
    CDynamicZoneWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004FE347 CDynamicZoneWnd_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004FEA17 CDynamicZoneWnd_guess::UpdateIfShown_4FE0FD_guess
    void UpdateIfShown_4FE0FD_guess();
    // EXTERNAL: TITANIUM 0x004FF11E CDynamicZoneWnd_guess::Update_4FF11E_guess
    void Update_4FF11E_guess();
    // EXTERNAL: TITANIUM 0x004FF54D CDynamicZoneWnd_guess::UpdateIfShown_4FF21C_guess
    void UpdateIfShown_4FF21C_guess();
};
#define pinstCDynamicZoneWnd_guess EQ_GLOBAL(CDynamicZoneWnd_guess*, 0x009918C0)

#endif
