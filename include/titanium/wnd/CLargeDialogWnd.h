/* CLargeDialogWnd: window, constructor 0x00553747 (tu_209_LargeDialogWindow). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CLARGEDIALOGWND_H
#define TITANIUM_WND_CLARGEDIALOGWND_H

#include "titanium/wnd_views.h"

struct CLargeDialogWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x190 - 0x15C];

    // EXTERNAL: TITANIUM 0x00553747 CLargeDialogWnd_guess::CLargeDialogWnd_guess
    CLargeDialogWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0052613B CLargeDialogWnd_guess::GetMp3Volume_guess
    float GetMp3Volume_guess();
    // EXTERNAL: TITANIUM 0x0055377E CLargeDialogWnd_guess::Init_guess
    void Init_guess(char* data_guess);
};
#define pinstCLargeDialogWnd_guess EQ_GLOBAL(CLargeDialogWnd_guess*, 0x00991F5C)

#endif
