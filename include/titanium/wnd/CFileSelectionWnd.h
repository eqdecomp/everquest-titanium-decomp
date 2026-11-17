/* CFileSelectionWnd: window, constructor 0x00501EA9 (tu_157_FileSelectionWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CFILESELECTIONWND_H
#define TITANIUM_WND_CFILESELECTIONWND_H

#include "titanium/wnd_views.h"

struct CXStr;

struct CFileSelectionWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x120*/ virtual void Open_guess(void* wnd_guess, int zero_guess);
    /*0x15C*/ unsigned char pad_15C[0x818 - 0x15C];

    // EXTERNAL: TITANIUM 0x00501EA9 CFileSelectionWnd_guess::CFileSelectionWnd_guess
    CFileSelectionWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005024B7 CFileSelectionWnd_guess::HasSelection_guess
    int HasSelection_guess();
    // EXTERNAL: TITANIUM 0x00502AA1 CFileSelectionWnd_guess::GetLabel_guess
    CXStr GetLabel_guess(int index);
};
#define pinstCFileSelectionWnd_guess EQ_GLOBAL(CFileSelectionWnd_guess*, 0x00850C84)

#endif
