/* CSkillsWnd: window, constructor 0x005541F4 (tu_212_SkillsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSKILLSWND_H
#define TITANIUM_WND_CSKILLSWND_H

#include "titanium/wnd_views.h"

struct CSkillsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x174 - 0x15C];

    // EXTERNAL: TITANIUM 0x005541F4 CSkillsWnd_guess::CSkillsWnd_guess
    CSkillsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00554E07 CSkillsWnd_guess::Run_554e07_guess
    void Run_554e07_guess(int target);
    // EXTERNAL: TITANIUM 0x00554E50 CSkillsWnd_guess::Run_554e50_guess
    void Run_554e50_guess();
};
#define pinstCSkillsWnd_guess EQ_GLOBAL(CSkillsWnd_guess*, 0x00850BB4)

#endif
