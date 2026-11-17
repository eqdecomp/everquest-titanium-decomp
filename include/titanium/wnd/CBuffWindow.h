/* CBuffWindow: window, constructor 0x004E955B (tu_136_BuffWindow). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBUFFWINDOW_H
#define TITANIUM_WND_CBUFFWINDOW_H

#include "titanium/wnd_views.h"

struct CBuffWindow_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x24C - 0x15C];

    // EXTERNAL: TITANIUM 0x004E955B CBuffWindow_guess::CBuffWindow_guess
    CBuffWindow_guess(CXWnd* parent, int kind);
    // EXTERNAL: TITANIUM 0x004E8BA8 CBuffWindow_guess::SetBuffIcon_guess
    void SetBuffIcon_guess(void* target_guess, int value_guess, int type_guess);
};
#define pinstCBuffWindowNORMAL_guess EQ_GLOBAL(CBuffWindow_guess*, 0x00850C18)
#define pinstCBuffWindowSHORT_guess EQ_GLOBAL(CBuffWindow_guess*, 0x00850C1C)

#endif
