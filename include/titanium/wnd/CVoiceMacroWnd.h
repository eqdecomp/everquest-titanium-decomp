/* CVoiceMacroWnd: window, constructor 0x004CBB56 (tu_096_VoiceMacroWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CVOICEMACROWND_H
#define TITANIUM_WND_CVOICEMACROWND_H

#include "titanium/wnd_views.h"

struct CVoiceMacroWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x180 - 0x15C];

    // EXTERNAL: TITANIUM 0x004CBB56 CVoiceMacroWnd_guess::CVoiceMacroWnd_guess
    CVoiceMacroWnd_guess(CXWnd* parent);
};
#define pinstCVoiceMacroWnd_guess EQ_GLOBAL(CVoiceMacroWnd_guess*, 0x00985D94)

#endif
