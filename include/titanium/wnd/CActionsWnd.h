/* CActionsWnd: window, constructor 0x004D4277 (tu_099_ActionsWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CACTIONSWND_H
#define TITANIUM_WND_CACTIONSWND_H

#include "titanium/wnd_views.h"

struct CActionsWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x21C - 0x15C];

    // EXTERNAL: TITANIUM 0x004D4277 CActionsWnd_guess::CActionsWnd_guess
    CActionsWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D22F2 CActionsWnd_guess::ShowPage_guess
    void ShowPage_guess(int type);
    // EXTERNAL: TITANIUM 0x004D2344 CActionsWnd_guess::UpdateButtonLabels_guess
    void UpdateButtonLabels_guess();
    // EXTERNAL: TITANIUM 0x004D25E1 CActionsWnd_guess::GetCurrentPage_guess
    int GetCurrentPage_guess();
    // EXTERNAL: TITANIUM 0x004D262D CActionsWnd_guess::UpdateKeyCombos_guess
    void UpdateKeyCombos_guess();
    // EXTERNAL: TITANIUM 0x004D2A03 CActionsWnd_guess::GetCombatPageButton_guess
    int GetCombatPageButton_guess(int index);
    // EXTERNAL: TITANIUM 0x004D2A11 CActionsWnd_guess::GetMainPageButton_guess
    int GetMainPageButton_guess(int index);
};
#define pinstCActionsWnd_guess EQ_GLOBAL(CActionsWnd_guess*, 0x00850C44)

#endif
