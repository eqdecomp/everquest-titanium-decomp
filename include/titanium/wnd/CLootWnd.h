/* CLootWnd: window, constructor 0x0052B4C9 (tu_182_LootWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CLOOTWND_H
#define TITANIUM_WND_CLOOTWND_H

#include "titanium/wnd_views.h"

struct CLootWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1E8 - 0x15C];
    /*0x1E8*/ void* table_1e8_guess[31];
    /*0x264*/ unsigned char pad_264[0x2F0 - 0x264];

    // EXTERNAL: TITANIUM 0x0052B4C9 CLootWnd_guess::CLootWnd_guess
    CLootWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0052B026 CLootWnd_guess::FinishLoot_guess
    void FinishLoot_guess();
    // EXTERNAL: TITANIUM 0x0052B35F CLootWnd_guess::AddLootItem_guess
    void AddLootItem_guess(void* item_guess);
    // EXTERNAL: TITANIUM 0x0052B3D8 CLootWnd_guess::HandleLootItemReply_guess
    void HandleLootItemReply_guess(int value);
    // EXTERNAL: TITANIUM 0x0052B79C CLootWnd_guess::HandleLootResponse_guess
    int HandleLootResponse_guess(char mode, int a, int b, int c, int d);
    // EXTERNAL: TITANIUM 0x0052B9D5 CLootWnd_guess::RequestLootSlot_guess
    void RequestLootSlot_guess(int index, char enabled);
};
#define pinstCLootWnd_guess EQ_GLOBAL(CLootWnd_guess*, 0x00850C40)

#endif
