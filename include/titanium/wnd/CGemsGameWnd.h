/* CGemsGameWnd: window, constructor 0x00506AE5 (tu_160_GemsGameWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGEMSGAMEWND_H
#define TITANIUM_WND_CGEMSGAMEWND_H

#include "titanium/wnd_views.h"

struct CGemsGameWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char field_15C_guess;
    /*0x15D*/ unsigned char pad_15D[0xEC0 - 0x15D];

    // EXTERNAL: TITANIUM 0x00506AE5 CGemsGameWnd_guess::CGemsGameWnd_guess
    CGemsGameWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00505205 CGemsGameWnd_guess::SetInputCommand_guess
    void SetInputCommand_guess(int value);
};
#define pinstCGemsGameWnd_guess EQ_GLOBAL(CGemsGameWnd_guess*, 0x00850C90)

#endif
