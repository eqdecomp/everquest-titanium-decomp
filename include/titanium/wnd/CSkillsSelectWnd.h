/* CSkillsSelectWnd: window, constructor 0x00553CBD (tu_211_SkillsSelectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSKILLSSELECTWND_H
#define TITANIUM_WND_CSKILLSSELECTWND_H

#include "titanium/wnd_views.h"

struct CSkillsSelectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ void* owner_015c_guess;
    /*0x160*/ unsigned char pad_160[0x164 - 0x160];
    /*0x164*/ void* list_0164_guess;
    /*0x168*/ unsigned char pad_168[0x16C - 0x168];

    // EXTERNAL: TITANIUM 0x00553CBD CSkillsSelectWnd_guess::CSkillsSelectWnd_guess
    CSkillsSelectWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00553F90 CSkillsSelectWnd_guess::FillList_guess
    void FillList_guess(int mask);
    // EXTERNAL: TITANIUM 0x00554190 CSkillsSelectWnd_guess::Refresh_guess
    void Refresh_guess();
};
#define pinstCSkillsSelectWnd_guess EQ_GLOBAL(CSkillsSelectWnd_guess*, 0x00850BB8)

#endif
