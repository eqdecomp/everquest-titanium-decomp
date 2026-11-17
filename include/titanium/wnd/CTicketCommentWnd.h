/* CTicketCommentWnd: window, constructor 0x00560F5B (tu_225_TicketCommentWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTICKETCOMMENTWND_H
#define TITANIUM_WND_CTICKETCOMMENTWND_H

#include "titanium/wnd_views.h"

struct CTicketCommentWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];

    // EXTERNAL: TITANIUM 0x00560F5B CTicketCommentWnd_guess::CTicketCommentWnd_guess
    CTicketCommentWnd_guess(CXWnd* parent);
};
#define pinstCTicketCommentWnd_guess EQ_GLOBAL(CTicketCommentWnd_guess*, 0x0099288C)

#endif
