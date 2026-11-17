/* CMailAddressBookWnd: window, constructor 0x0052BB96 (tu_183_MailAddressBookWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMAILADDRESSBOOKWND_H
#define TITANIUM_WND_CMAILADDRESSBOOKWND_H

#include "titanium/wnd_views.h"

struct CMailAddressBookWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x188 - 0x15C];

    // EXTERNAL: TITANIUM 0x0052BB96 CMailAddressBookWnd_guess::CMailAddressBookWnd_guess
    CMailAddressBookWnd_guess(CXWnd* parent);
};
#define pinstCMailAddressBookWnd_guess EQ_GLOBAL(CMailAddressBookWnd_guess*, 0x00850BEC)

#endif
