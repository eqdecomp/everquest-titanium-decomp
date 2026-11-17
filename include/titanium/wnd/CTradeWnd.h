/* CTradeWnd: window, constructor 0x0056982F (tu_232_TradeWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRADEWND_H
#define TITANIUM_WND_CTRADEWND_H

#include "titanium/wnd_views.h"

struct CTradeWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1D4 - 0x15C];
    /*0x1D4*/ int field_1D4_guess[4];
    /*0x1E4*/ int coins_guess[4];
    /*0x1F4*/ void* slots_1f4_guess[8];
    /*0x214*/ unsigned char pad_214[0x236 - 0x214];
    /*0x236*/ unsigned char active_guess;
    /*0x237*/ unsigned char pad_237[0x238 - 0x237];

    // EXTERNAL: TITANIUM 0x0056982F CTradeWnd_guess::CTradeWnd_guess
    CTradeWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00569639 CTradeWnd_guess::Deactivate_guess
    void Deactivate_guess();
    // EXTERNAL: TITANIUM 0x00569773 CTradeWnd_guess::ClickedCancelButton_guess
    void ClickedCancelButton_guess();
    // EXTERNAL: TITANIUM 0x00569802 CTradeWnd_guess::CompleteTrade_guess
    void CompleteTrade_guess();
    // EXTERNAL: TITANIUM 0x00569D94 CTradeWnd_guess::SetHisReadyTrade_guess
    void SetHisReadyTrade_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x00569E4E CTradeWnd_guess::ClickedTradeButton_guess
    void ClickedTradeButton_guess();
    // EXTERNAL: TITANIUM 0x00569E9C CTradeWnd_guess::ClickedMoneyButton_guess
    void ClickedMoneyButton_guess(int param_guess);
    // EXTERNAL: TITANIUM 0x00569F63 CTradeWnd_guess::TradeItemChanged_guess
    void TradeItemChanged_guess(int from, int to);
    // EXTERNAL: TITANIUM 0x00569FA8 CTradeWnd_guess::AddEqItemToHisTradeArray_guess
    int AddEqItemToHisTradeArray_guess(void* item_guess);
    // EXTERNAL: TITANIUM 0x0056A029 CTradeWnd_guess::DropItemIntoTrade_guess
    void DropItemIntoTrade_guess();
    // EXTERNAL: TITANIUM 0x0056A2B8 CTradeWnd_guess::DropMoneyIntoTrade_guess
    void DropMoneyIntoTrade_guess();
    // EXTERNAL: TITANIUM 0x0056A380 CTradeWnd_guess::Activate_guess
    void Activate_guess(void* target_guess, unsigned char flag_guess);
};
#define pinstCTradeWnd_guess EQ_GLOBAL(CTradeWnd_guess*, 0x00850C50)

#endif
