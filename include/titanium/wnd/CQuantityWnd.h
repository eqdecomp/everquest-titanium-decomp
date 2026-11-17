/* CQuantityWnd: window, constructor 0x0054D5AC (tu_203_QuantityWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CQUANTITYWND_H
#define TITANIUM_WND_CQUANTITYWND_H

#include "titanium/wnd_views.h"

struct CQuantityWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x174 - 0x15C];

    // EXTERNAL: TITANIUM 0x0054D5AC CQuantityWnd_guess::CQuantityWnd_guess
    CQuantityWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054D976 CQuantityWnd_guess::Function_0054d976_guess
    void Function_0054d976_guess(void* owner_guess, int maxQuantity_guess, int initialValue_guess, int x_guess, int y_guess, char randomize_guess);
};
#define pinstCQuantityWnd_guess EQ_GLOBAL(CQuantityWnd_guess*, 0x00850C3C)

#endif
