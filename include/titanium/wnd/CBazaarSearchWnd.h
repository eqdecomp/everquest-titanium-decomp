/* CBazaarSearchWnd: window, constructor 0x004E272F (tu_131_BazaarSearchWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBAZAARSEARCHWND_H
#define TITANIUM_WND_CBAZAARSEARCHWND_H

#include "titanium/wnd_views.h"

struct CBazaarSearchWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x3D58 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E272F CBazaarSearchWnd_guess::CBazaarSearchWnd_guess
    CBazaarSearchWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004E335A CBazaarSearchWnd_guess::EnableUpdatePlayerButton_guess
    void EnableUpdatePlayerButton_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x004E3ECA CBazaarSearchWnd_guess::IsHideTraders_guess
    bool IsHideTraders_guess();
    // EXTERNAL: TITANIUM 0x004E3EE4 CBazaarSearchWnd_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x004E455A CBazaarSearchWnd_guess::HandleBazaarMsg
    void HandleBazaarMsg(int* data, unsigned int size);
};
#define pinstCBazaarSearchWnd_guess EQ_GLOBAL(CBazaarSearchWnd_guess*, 0x00850C5C)

#endif
