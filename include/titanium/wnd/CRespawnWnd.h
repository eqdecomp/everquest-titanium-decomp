/* CRespawnWnd: window, constructor 0x00551F98 (tu_206_RespawnWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CRESPAWNWND_H
#define TITANIUM_WND_CRESPAWNWND_H

#include "titanium/wnd_views.h"

struct CRespawnWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];
    /*0x168*/ int field_168_guess;

    // EXTERNAL: TITANIUM 0x00551F98 CRespawnWnd_guess::CRespawnWnd_guess
    CRespawnWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0055220A CRespawnWnd_guess::InitRespawnList_guess
    void InitRespawnList_guess(int first, int second);
};
#define pinstCRespawnWnd_guess EQ_GLOBAL(CRespawnWnd_guess*, 0x00850BC4)

#endif
