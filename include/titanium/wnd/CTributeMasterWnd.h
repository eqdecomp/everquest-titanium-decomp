/* CTributeMasterWnd: window, constructor 0x0056E855 (tu_235_TributeMasterWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRIBUTEMASTERWND_H
#define TITANIUM_WND_CTRIBUTEMASTERWND_H

#include "titanium/wnd_views.h"

struct CTributeMasterWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D4 - 0x15C];
    /*0x1D4*/ unsigned char field_1D4_guess;
    /*0x1D5*/ unsigned char pad_1D5[0x1D8 - 0x1D5];

    // EXTERNAL: TITANIUM 0x0056E855 CTributeMasterWnd_guess::CTributeMasterWnd_guess
    CTributeMasterWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056CE7C CTributeMasterWnd_guess::Mark_guess
    void Mark_guess();
    // EXTERNAL: TITANIUM 0x0056D2E7 CTributeMasterWnd_guess::UpdateDonateButton_guess
    void UpdateDonateButton_guess();
    // EXTERNAL: TITANIUM 0x0056D8CF CTributeMasterWnd_guess::ClearDonation_guess
    void ClearDonation_guess();
    // EXTERNAL: TITANIUM 0x0056DDAA CTributeMasterWnd_guess::SelectDonationItem_guess
    void SelectDonationItem_guess(int key, int value);
};
#define pinstCTributeMasterWnd_guess EQ_GLOBAL(CTributeMasterWnd_guess*, 0x009929A8)

#endif
