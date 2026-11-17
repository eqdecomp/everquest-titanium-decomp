/* CTitleWnd: window, constructor 0x005652C6 (tu_229_TitleWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTITLEWND_H
#define TITANIUM_WND_CTITLEWND_H

#include "titanium/wnd_views.h"

struct CTitleWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D8 - 0x15C];
    /*0x1D8*/ unsigned char b1D8_guess;
    /*0x1D9*/ unsigned char pad_1D9[0x1DC - 0x1D9];

    // EXTERNAL: TITANIUM 0x005652C6 CTitleWnd_guess::CTitleWnd_guess
    CTitleWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056513B CTitleWnd_guess::GetTitlePrefix_guess
    char* GetTitlePrefix_guess();
    // EXTERNAL: TITANIUM 0x00565142 CTitleWnd_guess::GetTitleSuffix_guess
    char* GetTitleSuffix_guess();
    // EXTERNAL: TITANIUM 0x005659C1 CTitleWnd_guess::UpdateNamePreview_guess
    void UpdateNamePreview_guess(bool mode_guess);
};
#define pinstCTitleWnd_guess EQ_GLOBAL(CTitleWnd_guess*, 0x009928FC)

#endif
