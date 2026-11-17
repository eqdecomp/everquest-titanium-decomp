/* CGuildBankWnd: window, constructor 0x0050CCE5 (tu_165_GuildBankWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGUILDBANKWND_H
#define TITANIUM_WND_CGUILDBANKWND_H

#include "titanium/wnd_views.h"

struct CGuildBankWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0xBEC0 - 0x15C];

    // EXTERNAL: TITANIUM 0x0050CCE5 CGuildBankWnd_guess::CGuildBankWnd_guess
    CGuildBankWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0050C6B1 CGuildBankWnd_guess::Activate_guess
    void Activate_guess(const unsigned char* resource_guess);
    // EXTERNAL: TITANIUM 0x0050D339 CGuildBankWnd_guess::SaveGuildBank_guess
    void SaveGuildBank_guess(const char* filename_guess);
};
#define pinstCGuildBankWnd_guess EQ_GLOBAL(CGuildBankWnd_guess*, 0x00991A90)

#endif
