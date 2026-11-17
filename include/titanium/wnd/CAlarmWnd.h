/* CAlarmWnd: window, constructor 0x004D7EEF (tu_104_AlarmWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CALARMWND_H
#define TITANIUM_WND_CALARMWND_H

#include "titanium/wnd_views.h"

struct CAlarmWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x170 - 0x15C];

    // EXTERNAL: TITANIUM 0x004D7EEF CAlarmWnd_guess::CAlarmWnd_guess
    CAlarmWnd_guess(CXWnd* parent);
};
#define pinstCAlarmWnd_guess EQ_GLOBAL(CAlarmWnd_guess*, 0x00850BDC)

#endif
