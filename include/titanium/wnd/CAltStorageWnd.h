/* CAltStorageWnd: window, constructor 0x004D8AB5 (tu_105_AltStorageWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CALTSTORAGEWND_H
#define TITANIUM_WND_CALTSTORAGEWND_H

#include "titanium/wnd_views.h"

struct CAltStorageWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x190 - 0x15C];

    // EXTERNAL: TITANIUM 0x004D8AB5 CAltStorageWnd_guess::CAltStorageWnd_guess
    CAltStorageWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D8E35 CAltStorageWnd_guess::HandleMessage_guess
    void HandleMessage_guess(int unusedArg_guess, int* msg);
};
#define pinstCAltStorageWnd_guess EQ_GLOBAL(CAltStorageWnd_guess*, 0x00991434)

#endif
