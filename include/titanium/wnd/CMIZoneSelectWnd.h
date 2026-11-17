/* CMIZoneSelectWnd: window, constructor 0x00539260 (tu_189_MIZoneSelectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMIZONESELECTWND_H
#define TITANIUM_WND_CMIZONESELECTWND_H

#include "titanium/wnd_views.h"

struct CMIZoneSelectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x248 - 0x15C];

    // EXTERNAL: TITANIUM 0x00539260 CMIZoneSelectWnd_guess::CMIZoneSelectWnd_guess
    CMIZoneSelectWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005396FB CMIZoneSelectWnd_guess::SetData_guess
    void SetData_guess(const void* data);
};
#define pinstCMIZoneSelectWnd_guess EQ_GLOBAL(CMIZoneSelectWnd_guess*, 0x00991D64)

#endif
