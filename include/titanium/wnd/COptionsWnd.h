/* COptionsWnd: window, constructor 0x0053F8DC (tu_192_OptionsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_COPTIONSWND_H
#define TITANIUM_WND_COPTIONSWND_H

#include "titanium/wnd_views.h"

struct COptionsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0xAE8 - 0x15C];

    // EXTERNAL: TITANIUM 0x0053F8DC COptionsWnd_guess::COptionsWnd_guess
    COptionsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0053ACDF COptionsWnd_guess::Dispatch_guess
    void Dispatch_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0053CA42 COptionsWnd_guess::UpdateAction_guess
    void UpdateAction_guess(char value_guess);
    // EXTERNAL: TITANIUM 0x0053F1F4 COptionsWnd_guess::Update_guess
    void Update_guess();
};
#define pinstCOptionsWnd_guess EQ_GLOBAL(COptionsWnd_guess*, 0x00850C14)

#endif
