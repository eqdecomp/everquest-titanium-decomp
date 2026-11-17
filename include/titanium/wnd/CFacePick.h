/* CFacePick: window, constructor 0x00500DF3 (tu_155_FacePick). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CFACEPICK_H
#define TITANIUM_WND_CFACEPICK_H

#include "titanium/wnd_views.h"

struct CFacePick_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1C0 - 0x15C];
    /*0x1C0*/ int field_1C0_guess;

    // EXTERNAL: TITANIUM 0x00500295 CFacePick_guess::SetFaceSelectionsFromPlayer_guess
    void SetFaceSelectionsFromPlayer_guess();
};
#define pinstCFacePick_guess EQ_GLOBAL(CFacePick_guess*, 0x00850BA0)

#endif
