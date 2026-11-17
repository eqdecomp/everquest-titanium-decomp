/* CLFGuildWnd: window, constructor 0x0052929B (tu_180_LFGuildWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CLFGUILDWND_H
#define TITANIUM_WND_CLFGUILDWND_H

#include "titanium/wnd_views.h"

struct CLFGuildWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x764 - 0x15C];

    // EXTERNAL: TITANIUM 0x0052929B CLFGuildWnd_guess::CLFGuildWnd_guess
    CLFGuildWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00529B96 CLFGuildWnd_guess::Reset_00529b96_guess
    void Reset_00529b96_guess();
};
#define pinstCLFGuildWnd_guess EQ_GLOBAL(CLFGuildWnd_guess*, 0x00991C40)

#endif
