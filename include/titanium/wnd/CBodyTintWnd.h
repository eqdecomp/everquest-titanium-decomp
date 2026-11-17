/* CBodyTintWnd: window, constructor 0x004E6E5D (tu_133_BodyTintWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBODYTINTWND_H
#define TITANIUM_WND_CBODYTINTWND_H

#include "titanium/wnd_views.h"

struct CBodyTintWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1C8 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E6E5D CBodyTintWnd_guess::CBodyTintWnd_guess
    CBodyTintWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004E7703 CBodyTintWnd_guess::UpdateBrush_guess
    void UpdateBrush_guess(bool visible_guess);
    // EXTERNAL: TITANIUM 0x004E7992 CBodyTintWnd_guess::UpdateReagents_guess
    void UpdateReagents_guess();
};
#define pinstCBodyTintWnd_guess EQ_GLOBAL(CBodyTintWnd_guess*, 0x00850CAC)

#endif
