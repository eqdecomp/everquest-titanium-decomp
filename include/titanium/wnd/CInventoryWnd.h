/* CInventoryWnd: window, constructor 0x00516E9A (tu_170_InventoryWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CINVENTORYWND_H
#define TITANIUM_WND_CINVENTORYWND_H

#include "titanium/wnd_views.h"

struct CInventoryWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x264 - 0x15C];
    /*0x264*/ unsigned char dirty_guess;
    /*0x265*/ unsigned char pad_265[0x268 - 0x265];

    // EXTERNAL: TITANIUM 0x00516E9A CInventoryWnd_guess::CInventoryWnd_guess
    CInventoryWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0051802A CInventoryWnd_guess::WriteInventoryFile_guess
    void WriteInventoryFile_guess(const char* path);
    // EXTERNAL: TITANIUM 0x00518BF3 CInventoryWnd_guess::Refresh_guess
    void Refresh_guess();
};
#define pinstCInventoryWnd_guess EQ_GLOBAL(CInventoryWnd_guess*, 0x00850C34)

#endif
