/* CJournalCatWnd: window, constructor 0x00522FA4 (tu_176_JournalCatWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CJOURNALCATWND_H
#define TITANIUM_WND_CJOURNALCATWND_H

#include "titanium/wnd_views.h"

struct CJournalCatWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x180 - 0x15C];
    /*0x180*/ int field_180_guess;
    /*0x184*/ unsigned char pad_184[0x1A0 - 0x184];

    // EXTERNAL: TITANIUM 0x00522FA4 CJournalCatWnd_guess::CJournalCatWnd_guess
    CJournalCatWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005229CA CJournalCatWnd_guess::ClearControls_guess
    void ClearControls_guess();
    // EXTERNAL: TITANIUM 0x005233D8 CJournalCatWnd_guess::Reload_guess
    void Reload_guess(bool flag_guess);
};
#define pinstCJournalCatWnd_guess EQ_GLOBAL(CJournalCatWnd_guess*, 0x00850CA8)

#endif
