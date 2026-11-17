/* CCombatSkillSelectWnd: window, constructor 0x0042D707 (tu_022_CombatSkillSelectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCOMBATSKILLSELECTWND_H
#define TITANIUM_WND_CCOMBATSKILLSELECTWND_H

#include "titanium/wnd_views.h"

struct CCombatSkillSelectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x17C - 0x15C];

    // EXTERNAL: TITANIUM 0x0042D707 CCombatSkillSelectWnd_guess::CCombatSkillSelectWnd_guess
    CCombatSkillSelectWnd_guess(CXWnd* parent);
};
#define pinstCCombatSkillSelectWnd_guess EQ_GLOBAL(CCombatSkillSelectWnd_guess*, 0x00850BBC)

#endif
