/* CBarterWnd: window, constructor 0x004E09DF (tu_130_BarterWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CBARTERWND_H
#define TITANIUM_WND_CBARTERWND_H

#include "titanium/wnd_views.h"

struct CBarterWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x278 - 0x15C];

    // EXTERNAL: TITANIUM 0x004E09DF CBarterWnd_guess::CBarterWnd_guess
    CBarterWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004DFE0B CBarterWnd_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x004DFE23 CBarterWnd_guess::AppendColoredText_guess
    void AppendColoredText_guess(char* text_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x004E02A8 CBarterWnd_guess::RefreshBuyLineList_guess
    void RefreshBuyLineList_guess(bool keepSel_guess);
    // EXTERNAL: TITANIUM 0x004E17DC CBarterWnd_guess::Teardown_guess
    void Teardown_guess();
    // EXTERNAL: TITANIUM 0x004E1EE9 CBarterWnd_guess::ClearSearchResults_guess
    void ClearSearchResults_guess();
    // EXTERNAL: TITANIUM 0x004E1F15 CBarterWnd_guess::AddSearchResult_guess
    void AddSearchResult_guess(void* item);
    // EXTERNAL: TITANIUM 0x004E2019 CBarterWnd_guess::RebuildInventoryList_guess
    void RebuildInventoryList_guess();
};
#define pinstCBarterWnd_guess EQ_GLOBAL(CBarterWnd_guess*, 0x00991608)

#endif
