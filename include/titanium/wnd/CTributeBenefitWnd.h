/* CTributeBenefitWnd: window, constructor 0x0056C231 (tu_234_TributeBenefitWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRIBUTEBENEFITWND_H
#define TITANIUM_WND_CTRIBUTEBENEFITWND_H

#include "titanium/wnd_views.h"

struct CTributeBenefitWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1C4 - 0x15C];

    // EXTERNAL: TITANIUM 0x0056C231 CTributeBenefitWnd_guess::CTributeBenefitWnd_guess
    CTributeBenefitWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056BB49 CTributeBenefitWnd_guess::SetFirst_guess
    void SetFirst_guess();
    // EXTERNAL: TITANIUM 0x0056BB51 CTributeBenefitWnd_guess::SetSecond_guess
    void SetSecond_guess();
    // EXTERNAL: TITANIUM 0x0056C185 CTributeBenefitWnd_guess::SelectActive_guess
    void SelectActive_guess(int id, const char* name);
    // EXTERNAL: TITANIUM 0x0056C1DB CTributeBenefitWnd_guess::SelectGuild_guess
    void SelectGuild_guess(int id, const char* name);
};
#define pinstCTributeBenefitWnd_guess EQ_GLOBAL(CTributeBenefitWnd_guess*, 0x0099298C)

#endif
