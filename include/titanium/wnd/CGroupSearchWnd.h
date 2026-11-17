/* CGroupSearchWnd: window, constructor 0x0050AC61 (tu_163_GroupSearchWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGROUPSEARCHWND_H
#define TITANIUM_WND_CGROUPSEARCHWND_H

#include "titanium/wnd_views.h"

struct CGroupSearchWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0xE770 - 0x15C];

    // EXTERNAL: TITANIUM 0x0050AC61 CGroupSearchWnd_guess::CGroupSearchWnd_guess
    CGroupSearchWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00508A5A CGroupSearchWnd_guess::Handle_guess
    void Handle_guess(int value);
    // EXTERNAL: TITANIUM 0x0050957F CGroupSearchWnd_guess::ClearGroupSearchResults_guess
    void ClearGroupSearchResults_guess();
    // EXTERNAL: TITANIUM 0x00509618 CGroupSearchWnd_guess::ClearPlayerSearchResults_guess
    void ClearPlayerSearchResults_guess();
    // EXTERNAL: TITANIUM 0x0050A167 CGroupSearchWnd_guess::RemoveInfoOnGroupChange_guess
    void RemoveInfoOnGroupChange_guess();
    // EXTERNAL: TITANIUM 0x0050ADB2 CGroupSearchWnd_guess::NotifyObject_guess
    void NotifyObject_guess(void* record_guess);
    // EXTERNAL: TITANIUM 0x0050B634 CGroupSearchWnd_guess::ProcessEntry_guess
    void ProcessEntry_guess(void* payload_guess);
};
#define pinstCGroupSearchWnd_guess EQ_GLOBAL(CGroupSearchWnd_guess*, 0x00991A58)

#endif
