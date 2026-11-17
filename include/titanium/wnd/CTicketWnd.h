/* CTicketWnd: window, constructor 0x005633E9 (tu_226_TicketWindow). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTICKETWND_H
#define TITANIUM_WND_CTICKETWND_H

#include "titanium/wnd_views.h"

struct CTicketWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* dialogNotifierVftable_15C_guess;    /* vptr of the confirmation-notifier base (0x0063FD9C family) */
    /*0x160*/ unsigned char pad_160[0x5F0 - 0x160];

    // EXTERNAL: TITANIUM 0x005633E9 CTicketWnd_guess::CTicketWnd_guess
    CTicketWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056115A CTicketWnd_guess::Toggle_guess
    void Toggle_guess(char enabled_guess);
    // EXTERNAL: TITANIUM 0x005612E7 CTicketWnd_guess::ShowPage_guess
    void ShowPage_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00561310 CTicketWnd_guess::ShowHelpPage_guess
    void ShowHelpPage_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0056150D CTicketWnd_guess::ShowTicketDetail_guess
    void ShowTicketDetail_guess();
    // EXTERNAL: TITANIUM 0x0056176F CTicketWnd_guess::UpdateGuess_guess
    void UpdateGuess_guess(void* input_guess);
    // EXTERNAL: TITANIUM 0x00562710 CTicketWnd_guess::ShowTicket_guess
    void ShowTicket_guess(void* object_guess);
    // EXTERNAL: TITANIUM 0x00562FED CTicketWnd_guess::ShowKBResults_guess
    void ShowKBResults_guess(void* object_guess);
    // EXTERNAL: TITANIUM 0x005631F4 CTicketWnd_guess::ShowKBArticle_guess
    void ShowKBArticle_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x005632FB CTicketWnd_guess::ShowCategories_guess
    void ShowCategories_guess();
    // EXTERNAL: TITANIUM 0x00563E25 CTicketWnd_guess::ShowTicketThunk_guess
    void ShowTicketThunk_guess(void* object_guess);
};
#define pinstCTicketWnd_guess EQ_GLOBAL(CTicketWnd_guess*, 0x009928A8)

#endif
