/* CFeedbackWnd: window, constructor 0x005013C9 (tu_156_FeedbackWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CFEEDBACKWND_H
#define TITANIUM_WND_CFEEDBACKWND_H

#include "titanium/wnd_views.h"

struct CFeedbackWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x16C - 0x15C];

    // EXTERNAL: TITANIUM 0x005013C9 CFeedbackWnd_guess::CFeedbackWnd_guess
    CFeedbackWnd_guess(CXWnd* parent);
};
#define pinstCFeedbackWnd_guess EQ_GLOBAL(CFeedbackWnd_guess*, 0x00850C70)

#endif
