/* CBazaarWnd: window, constructor 0x004E66C2 (tu_132_BazaarWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBAZAARWND_H
#define TITANIUM_WND_CBAZAARWND_H

#include "titanium/wnd_views.h"

struct CBazaarWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x2E4 - 0x15C];
    /*0x2E4*/ void* table_2e4_guess[80];
    /*0x424*/ unsigned char pad_424[0x5F8 - 0x424];

    // EXTERNAL: TITANIUM 0x004E66C2 CBazaarWnd_guess::CBazaarWnd_guess
    CBazaarWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004E5A35 CBazaarWnd_guess::SetSelected_guess
    void SetSelected_guess(int value, int unused_guess);
    // EXTERNAL: TITANIUM 0x004E6109 CBazaarWnd_guess::UpdateSellItems_guess
    void UpdateSellItems_guess(char param_2);
    // EXTERNAL: TITANIUM 0x004E6A81 CBazaarWnd_guess::HandleMessage_guess
    void HandleMessage_guess(int* message);
};
#define pinstCBazaarWnd_guess EQ_GLOBAL(CBazaarWnd_guess*, 0x00850C58)

#endif
