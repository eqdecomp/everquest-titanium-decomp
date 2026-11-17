/* CBarterMerchantWnd: window, constructor 0x004DD7A0 (tu_128_BarterMerchantWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBARTERMERCHANTWND_H
#define TITANIUM_WND_CBARTERMERCHANTWND_H

#include "titanium/wnd_views.h"

struct CBarterMerchantWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x19C - 0x15C];
    /*0x19C*/ int field_19C_guess;

    // EXTERNAL: TITANIUM 0x004DD7A0 CBarterMerchantWnd_guess::CBarterMerchantWnd_guess
    CBarterMerchantWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004DE41A CBarterMerchantWnd_guess::UpdateBuyLine_guess
    void UpdateBuyLine_guess(void* message);
};
#define pinstCBarterMerchantWnd_guess EQ_GLOBAL(CBarterMerchantWnd_guess*, 0x009915D0)

#endif
