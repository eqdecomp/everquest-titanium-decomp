/* CBookWnd: window, constructor 0x004E84E8 (tu_134_BookWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBOOKWND_H
#define TITANIUM_WND_CBOOKWND_H

#include "titanium/wnd_views.h"

struct CBookWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x718 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E84E8 CBookWnd_guess::CBookWnd_guess
    CBookWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004E7FA3 CBookWnd_guess::SelectBook_guess
    char SelectBook_guess(void* owner);
    // EXTERNAL: TITANIUM 0x004E87EF CBookWnd_guess::SetBookText_guess
    void SetBookText_guess(const char* text);
};
#define pinstCBookWnd_guess EQ_GLOBAL(CBookWnd_guess*, 0x00850BA8)

#endif
