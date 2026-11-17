/* CServerListWnd: window, constructor 0x00553500 (tu_208_ServerListWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSERVERLISTWND_H
#define TITANIUM_WND_CSERVERLISTWND_H

#include "titanium/wnd_views.h"

struct CServerListWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x17C - 0x15C];

    // EXTERNAL: TITANIUM 0x00553500 CServerListWnd_guess::CServerListWnd_guess
    CServerListWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005536FE CServerListWnd_guess::SetServerList_guess
    void SetServerList_guess(char* data_guess);
};
#define pinstCServerListWnd_guess EQ_GLOBAL(CServerListWnd_guess*, 0x00850CB0)

#endif
