/* CFriendsWnd: window, constructor 0x005035EA (tu_159_FriendsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CFRIENDSWND_H
#define TITANIUM_WND_CFRIENDSWND_H

#include "titanium/wnd_views.h"

struct CFriendsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x188 - 0x15C];

    // EXTERNAL: TITANIUM 0x005035EA CFriendsWnd_guess::CFriendsWnd_guess
    CFriendsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00503A0D CFriendsWnd_guess::RefreshFriendsList_guess
    void RefreshFriendsList_guess();
    // EXTERNAL: TITANIUM 0x00503AAB CFriendsWnd_guess::RefreshIgnoreList_guess
    void RefreshIgnoreList_guess();
};
#define pinstCFriendsWnd_guess EQ_GLOBAL(CFriendsWnd_guess*, 0x00850BC0)

#endif
