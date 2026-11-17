/* CCombatAbilityWnd: window, constructor 0x004F9AE1 (tu_146_CombatAbilityWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCOMBATABILITYWND_H
#define TITANIUM_WND_CCOMBATABILITYWND_H

#include "titanium/wnd_views.h"

struct CCombatAbilityWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1B0 - 0x15C];

    // EXTERNAL: TITANIUM 0x004F9AE1 CCombatAbilityWnd_guess::CCombatAbilityWnd_guess
    CCombatAbilityWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004F8AAB CCombatAbilityWnd_guess::UseAbilitySlot_guess
    char UseAbilitySlot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004F9A46 CCombatAbilityWnd_guess::Run_guess
    void Run_guess();
};
#define pinstCCombatAbilityWnd_guess EQ_GLOBAL(CCombatAbilityWnd_guess*, 0x00850C48)

#endif
