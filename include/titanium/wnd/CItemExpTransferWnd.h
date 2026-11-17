/* CItemExpTransferWnd: window, constructor 0x0052201C (tu_175_ItemExpTransferWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CITEMEXPTRANSFERWND_H
#define TITANIUM_WND_CITEMEXPTRANSFERWND_H

#include "titanium/wnd_views.h"

struct CItemExpTransferWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1B8 - 0x15C];

    // EXTERNAL: TITANIUM 0x0052201C CItemExpTransferWnd_guess::CItemExpTransferWnd_guess
    CItemExpTransferWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00521C1B CItemExpTransferWnd_guess::InvalidateItem_guess
    void InvalidateItem_guess(int x, int y);
    // EXTERNAL: TITANIUM 0x00522213 CItemExpTransferWnd_guess::HandlePreview_guess
    void HandlePreview_guess(void* message_guess);
};
#define pinstCItemExpTransferWnd_guess EQ_GLOBAL(CItemExpTransferWnd_guess*, 0x00991BA8)

#endif
