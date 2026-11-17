/* CMailCompositionWnd: window, constructor 0x0052D28D (tu_184_MailCompositionWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMAILCOMPOSITIONWND_H
#define TITANIUM_WND_CMAILCOMPOSITIONWND_H

#include "titanium/wnd_views.h"

struct CXStr;

struct CMailCompositionWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x188 - 0x15C];

    // EXTERNAL: TITANIUM 0x0052D28D CMailCompositionWnd_guess::CMailCompositionWnd_guess
    CMailCompositionWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0052DE40 CMailCompositionWnd_guess::Compose_guess
    void Compose_guess(const CXStr& title_guess, const CXStr& recipient_guess, const CXStr& subject_guess, const CXStr& body_guess);
};
#define pinstCMailCompositionWnd_guess EQ_GLOBAL(CMailCompositionWnd_guess*, 0x00850BE8)

#endif
