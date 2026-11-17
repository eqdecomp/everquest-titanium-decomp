/* CPetitionQWnd: window, constructor 0x00542B35 (tu_194_PetitionQWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPETITIONQWND_H
#define TITANIUM_WND_CPETITIONQWND_H

#include "titanium/wnd_views.h"

struct CPetitionQWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0xB90 - 0x15C];

    // EXTERNAL: TITANIUM 0x00542B35 CPetitionQWnd_guess::CPetitionQWnd_guess
    CPetitionQWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005433CE CPetitionQWnd_guess::UpdatePetitionList_guess
    void UpdatePetitionList_guess();
    // EXTERNAL: TITANIUM 0x00543ED1 CPetitionQWnd_guess::GetPetitionerName_guess
    unsigned char* GetPetitionerName_guess();
    // EXTERNAL: TITANIUM 0x0054407F CPetitionQWnd_guess::CheckedOut_guess
    void CheckedOut_guess(int* argument_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005440BD CPetitionQWnd_guess::UndoCheckout_guess
    void UndoCheckout_guess();
};
#define pinstCPetitionQWnd_guess EQ_GLOBAL(CPetitionQWnd_guess*, 0x00850C98)

#endif
