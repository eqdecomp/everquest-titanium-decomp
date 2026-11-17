/* CMerchantWnd: window, constructor 0x00536D26 (tu_188_MerchantWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CMERCHANTWND_H
#define TITANIUM_WND_CMERCHANTWND_H

#include "titanium/wnd_views.h"

struct CMerchantWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x2D4 - 0x15C];

    // EXTERNAL: TITANIUM 0x00536D26 CMerchantWnd_guess::CMerchantWnd_guess
    CMerchantWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00537096 CMerchantWnd_guess::OpenForMerchant_guess
    void OpenForMerchant_guess(void* first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00537691 CMerchantWnd_guess::AddMerchantItem_guess
    void AddMerchantItem_guess(void* item_guess);
    // EXTERNAL: TITANIUM 0x00537E10 CMerchantWnd_guess::FinishBuyingItem_guess
    void FinishBuyingItem_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x00537FCE CMerchantWnd_guess::SelectBuySellSlot
    void SelectBuySellSlot(int key, void* element);
    // EXTERNAL: TITANIUM 0x005384E2 CMerchantWnd_guess::FinishSellingItem_guess
    void FinishSellingItem_guess(void* value_guess);
};
#define pinstCMerchantWnd_guess EQ_GLOBAL(CMerchantWnd_guess*, 0x00850C4C)

#endif
