/* CEditLabelWnd: window, constructor 0x004FF559 (tu_151_DynamicZoneWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CEDITLABELWND_H
#define TITANIUM_WND_CEDITLABELWND_H

#include "titanium/wnd_views.h"

struct CEditLabelWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x160 - 0x15C];
    /*0x160*/ void* field_160_guess;
    /*0x164*/ void* field_164_guess;
    /*0x168*/ unsigned char pad_168[0x184 - 0x168];

    // EXTERNAL: TITANIUM 0x004FF559 CEditLabelWnd_guess::CEditLabelWnd_guess
    CEditLabelWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004FF7D2 CEditLabelWnd_guess::Activate_guess
    void Activate_guess(void* p1, const char* name, int state, int value);
};
#define pinstCEditLabelWnd_guess EQ_GLOBAL(CEditLabelWnd_guess*, 0x00850C04)

#endif
