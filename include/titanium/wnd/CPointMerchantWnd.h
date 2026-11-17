/* CPointMerchantWnd: window, constructor 0x00545804 (tu_197_PointMerchantWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPOINTMERCHANTWND_H
#define TITANIUM_WND_CPOINTMERCHANTWND_H

#include "titanium/wnd_views.h"

struct CPointMerchantWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x20C - 0x15C];

    // EXTERNAL: TITANIUM 0x00545804 CPointMerchantWnd_guess::CPointMerchantWnd_guess
    CPointMerchantWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005456BC CPointMerchantWnd_guess::dispatch14_guess
    char dispatch14_guess();
    // EXTERNAL: TITANIUM 0x00546576 CPointMerchantWnd_guess::connect_guess
    void connect_guess(void* actor_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x00546A64 CPointMerchantWnd_guess::refreshStatus_guess
    void refreshStatus_guess();
    // EXTERNAL: TITANIUM 0x00546E80 CPointMerchantWnd_guess::reload_guess
    void reload_guess(void* arg_guess);
    // EXTERNAL: TITANIUM 0x00546FA5 CPointMerchantWnd_guess::setValue_guess
    void setValue_guess(int value_arg_guess);
    // EXTERNAL: TITANIUM 0x00547115 CPointMerchantWnd_guess::HandleSellReply_guess
    void HandleSellReply_guess(char* data_guess);
};
#define pinstCPointMerchantWnd_guess EQ_GLOBAL(CPointMerchantWnd_guess*, 0x00991E28)

#endif
