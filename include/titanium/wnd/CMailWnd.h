/* CMailWnd: window, constructor 0x0052E9C3 (tu_185_MailWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMAILWND_H
#define TITANIUM_WND_CMAILWND_H

#include "titanium/wnd_views.h"

struct CMailWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1BC - 0x15C];

    // EXTERNAL: TITANIUM 0x0052E9C3 CMailWnd_guess::CMailWnd_guess
    CMailWnd_guess(CXWnd* parent);
};
#define pinstCMailWnd_guess EQ_GLOBAL(CMailWnd_guess*, 0x00850BE4)

#endif
