/* CNoteWnd: window, constructor 0x0053AB19 (tu_191_NoteWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CNOTEWND_H
#define TITANIUM_WND_CNOTEWND_H

#include "titanium/wnd_views.h"

struct CNoteWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x56C - 0x15C];

    // EXTERNAL: TITANIUM 0x0053AB19 CNoteWnd_guess::CNoteWnd_guess
    CNoteWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0053A87E CNoteWnd_guess::SetId_guess
    bool SetId_guess(void* id);
    // EXTERNAL: TITANIUM 0x0053A8B8 CNoteWnd_guess::SetText_guess
    void SetText_guess(const char* text);
};
#define pinstCNoteWnd_guess EQ_GLOBAL(CNoteWnd_guess*, 0x00850BA4)

#endif
