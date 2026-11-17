/* CColorPickerWnd: window, constructor 0x004F83AC (tu_145_ColorPickerWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCOLORPICKERWND_H
#define TITANIUM_WND_CCOLORPICKERWND_H

#include "titanium/wnd_views.h"

struct CColorPickerWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D0 - 0x15C];

    // EXTERNAL: TITANIUM 0x004F83AC CColorPickerWnd_guess::CColorPickerWnd_guess
    CColorPickerWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004F8080 CColorPickerWnd_guess::SetPresetColor_guess
    void SetPresetColor_guess(int index_guess, unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x004F898E CColorPickerWnd_guess::Activate_guess
    void Activate_guess(void* first_guess, int second_guess);
};
#define pinstCColorPickerWnd_guess EQ_GLOBAL(CColorPickerWnd_guess*, 0x00850C0C)

#endif
