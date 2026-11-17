/* CSocialEditWnd: window, constructor 0x00555363 (tu_213_SocialEditWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSOCIALEDITWND_H
#define TITANIUM_WND_CSOCIALEDITWND_H

#include "titanium/wnd_views.h"

struct CSocialEditWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D8 - 0x15C];

    // EXTERNAL: TITANIUM 0x00555363 CSocialEditWnd_guess::CSocialEditWnd_guess
    CSocialEditWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00555224 CSocialEditWnd_guess::GetColor_guess
    unsigned int GetColor_guess(int index);
    // EXTERNAL: TITANIUM 0x005555E1 CSocialEditWnd_guess::Run_guess
    void Run_guess(int value);
};
#define pinstCSocialEditWnd_guess EQ_GLOBAL(CSocialEditWnd_guess*, 0x00850C6C)

#endif
