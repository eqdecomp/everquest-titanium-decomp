/* CTradeskillWnd: window, constructor 0x00568BDB (tu_231_TradeskillWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRADESKILLWND_H
#define TITANIUM_WND_CTRADESKILLWND_H

#include "titanium/wnd_views.h"

struct CTradeskillWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x364 - 0x15C];
    /*0x364*/ void* pendingItem_364_guess;
    /*0x368*/ int pendingSlot_368_guess;
    /*0x36C*/ unsigned char pad_36C[0xB64 - 0x36C];

    // EXTERNAL: TITANIUM 0x00568BDB CTradeskillWnd_guess::CTradeskillWnd_guess
    CTradeskillWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00567634 CTradeskillWnd_guess::IsTradeskillContainerType_guess
    unsigned char IsTradeskillContainerType_guess(int state_guess);
    // EXTERNAL: TITANIUM 0x00567B79 CTradeskillWnd_guess::Handle_OP_RecipeReply_guess
    void Handle_OP_RecipeReply_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x00567E44 CTradeskillWnd_guess::SetCurrent_guess
    void SetCurrent_guess(int key, int value);
    // EXTERNAL: TITANIUM 0x00567FE5 CTradeskillWnd_guess::Begin_guess
    void Begin_guess(void* extra_guess, int delay_guess);
    // EXTERNAL: TITANIUM 0x0056875D CTradeskillWnd_guess::Flush_guess
    void Flush_guess();
    // EXTERNAL: TITANIUM 0x00568B39 CTradeskillWnd_guess::ApplyPacket_guess
    void ApplyPacket_guess(const char* packet);
};
#define pinstCTradeskillWnd_guess EQ_GLOBAL(CTradeskillWnd_guess*, 0x00992940)

#endif
