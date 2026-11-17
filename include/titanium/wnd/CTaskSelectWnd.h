/* CTaskSelectWnd: window, constructor 0x0055C2B5 (tu_221_TaskSelectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTASKSELECTWND_H
#define TITANIUM_WND_CTASKSELECTWND_H

#include "titanium/wnd_views.h"

struct CTaskSelectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x649A8 - 0x15C];

    // EXTERNAL: TITANIUM 0x0055C2B5 CTaskSelectWnd_guess::CTaskSelectWnd_guess
    CTaskSelectWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0055C13B CTaskSelectWnd_guess::LoadTasks_guess
    void LoadTasks_guess(int* message_guess);
};
#define pinstCTaskSelectWnd_guess EQ_GLOBAL(CTaskSelectWnd_guess*, 0x00992820)

#endif
