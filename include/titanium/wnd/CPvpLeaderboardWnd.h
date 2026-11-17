/* CPvpLeaderboardWnd: window, constructor 0x0054B068 (tu_201_PvpLeaderboardWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPVPLEADERBOARDWND_H
#define TITANIUM_WND_CPVPLEADERBOARDWND_H

#include "titanium/wnd_views.h"

struct CPvpLeaderboardWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x18C - 0x15C];

    // EXTERNAL: TITANIUM 0x0054B068 CPvpLeaderboardWnd_guess::CPvpLeaderboardWnd_guess
    CPvpLeaderboardWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054B657 CPvpLeaderboardWnd_guess::OnServerMessage_guess
    void OnServerMessage_guess(void* sender, int message, void* data, int length);
};
#define pinstCPvpLeaderboardWnd_guess EQ_GLOBAL(CPvpLeaderboardWnd_guess*, 0x00991E94)

#endif
