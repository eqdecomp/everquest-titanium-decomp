/* CSoulmarkWnd: window, constructor 0x00555679 (tu_214_SoulmarkWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSOULMARKWND_H
#define TITANIUM_WND_CSOULMARKWND_H

#include "titanium/wnd_views.h"

struct CSoulmarkWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x18F4 - 0x15C];

    // EXTERNAL: TITANIUM 0x00555679 CSoulmarkWnd_guess::CSoulmarkWnd_guess
    CSoulmarkWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005561C2 CSoulmarkWnd_guess::DoInquireCommand_guess
    void DoInquireCommand_guess(int token_guess);
    // EXTERNAL: TITANIUM 0x00556240 CSoulmarkWnd_guess::DoPraiseCommand_guess
    void DoPraiseCommand_guess(int input_guess);
    // EXTERNAL: TITANIUM 0x005562F5 CSoulmarkWnd_guess::DoWarnCommand_guess
    void DoWarnCommand_guess(int input_guess);
    // EXTERNAL: TITANIUM 0x005563C6 CSoulmarkWnd_guess::UpdateSoulmarks_guess
    void UpdateSoulmarks_guess(char* data_guess);
};
#define pinstCSoulmarkWnd_guess EQ_GLOBAL(CSoulmarkWnd_guess*, 0x00850C9C)

#endif
