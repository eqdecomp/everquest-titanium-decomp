/* CAdventureStatsWnd: window, constructor 0x004D7BB4 (tu_103_AdventureStatsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CADVENTURESTATSWND_H
#define TITANIUM_WND_CADVENTURESTATSWND_H

#include "titanium/wnd_views.h"

struct CAdventureStatsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x190 - 0x15C];

    // EXTERNAL: TITANIUM 0x004D7BB4 CAdventureStatsWnd_guess::CAdventureStatsWnd_guess
    CAdventureStatsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D73F2 CAdventureStatsWnd_guess::Send_guess
    void Send_guess();
    // EXTERNAL: TITANIUM 0x004D743F CAdventureStatsWnd_guess::Handle_OP_AdventureStatsReply_guess
    void Handle_OP_AdventureStatsReply_guess(int sender, unsigned int msg, char* data, int extra);
};
#define pinstCAdventureStatsWnd_guess EQ_GLOBAL(CAdventureStatsWnd_guess*, 0x009913F0)

#endif
