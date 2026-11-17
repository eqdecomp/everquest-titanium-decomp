/* CBugReportWnd: window, constructor 0x004E9980 (tu_137_BugReportWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBUGREPORTWND_H
#define TITANIUM_WND_CBUGREPORTWND_H

#include "titanium/wnd_views.h"

struct CBugReportWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1A8 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E9980 CBugReportWnd_guess::CBugReportWnd_guess
    CBugReportWnd_guess(CXWnd* parent);
};
#define pinstCBugReportWnd_guess EQ_GLOBAL(CBugReportWnd_guess*, 0x00850C74)

#endif
