/* CAdventureLeaderboardWnd: window, constructor 0x004D5770 (tu_101_AdventureLeaderboardWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CADVENTURELEADERBOARDWND_H
#define TITANIUM_WND_CADVENTURELEADERBOARDWND_H

#include "titanium/wnd_views.h"

struct CAdventureLeaderboardWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x18C - 0x15C];

    // EXTERNAL: TITANIUM 0x004D5770 CAdventureLeaderboardWnd_guess::CAdventureLeaderboardWnd_guess
    CAdventureLeaderboardWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D5BD6 CAdventureLeaderboardWnd_guess::SendLeaderboardRequest_guess
    void SendLeaderboardRequest_guess();
    // EXTERNAL: TITANIUM 0x004D5C99 CAdventureLeaderboardWnd_guess::Activate_guess
    void Activate_guess();
    // EXTERNAL: TITANIUM 0x004D5D1D CAdventureLeaderboardWnd_guess::Handle_OP_AdventureLeaderboardReply_guess
    void Handle_OP_AdventureLeaderboardReply_guess(int sender, unsigned int msg, char* data, int extra);
};
#define pinstCAdventureLeaderboardWnd_guess EQ_GLOBAL(CAdventureLeaderboardWnd_guess*, 0x009913B8)

#endif
