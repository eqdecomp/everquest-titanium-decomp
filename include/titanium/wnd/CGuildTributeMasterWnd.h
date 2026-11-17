/* CGuildTributeMasterWnd: window, constructor 0x00513266 (tu_167_GuildTributeMasterWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGUILDTRIBUTEMASTERWND_H
#define TITANIUM_WND_CGUILDTRIBUTEMASTERWND_H

#include "titanium/wnd_views.h"

struct CGuildTributeMasterWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1E0 - 0x15C];

    // EXTERNAL: TITANIUM 0x00513266 CGuildTributeMasterWnd_guess::CGuildTributeMasterWnd_guess
    CGuildTributeMasterWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005117C3 CGuildTributeMasterWnd_guess::SetFlag_guess
    void SetFlag_guess();
    // EXTERNAL: TITANIUM 0x005117CB CGuildTributeMasterWnd_guess::SetSelectionState_guess
    void SetSelectionState_guess();
    // EXTERNAL: TITANIUM 0x0051208F CGuildTributeMasterWnd_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0051256A CGuildTributeMasterWnd_guess::SetSlot_guess
    void SetSlot_guess(int key, int value);
};
#define pinstCGuildTributeMasterWnd_guess EQ_GLOBAL(CGuildTributeMasterWnd_guess*, 0x00991AC8)

#endif
