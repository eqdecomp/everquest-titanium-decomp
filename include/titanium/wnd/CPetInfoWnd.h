/* CPetInfoWnd: window, constructor 0x00542620 (tu_193_PetInfoWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPETINFOWND_H
#define TITANIUM_WND_CPETINFOWND_H

#include "titanium/wnd_views.h"

struct CPetInfoWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x288 - 0x15C];
    /*0x288*/ int spells_288_guess[30];
    /*0x300*/ unsigned char pad_300[0x305 - 0x300];
    /*0x305*/ char field_305_guess;
    /*0x306*/ unsigned char pad_306[0x380 - 0x306];

    // EXTERNAL: TITANIUM 0x00542620 CPetInfoWnd_guess::CPetInfoWnd_guess
    CPetInfoWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054209C CPetInfoWnd_guess::GetButton_guess
    int GetButton_guess(int index);
    // EXTERNAL: TITANIUM 0x0054210E CPetInfoWnd_guess::SetPetBuffs_guess
    void SetPetBuffs_guess(int* ids, int* durations, int count);
    // EXTERNAL: TITANIUM 0x005422B5 CPetInfoWnd_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x005425E9 CPetInfoWnd_guess::SetShownPopup_guess
    void SetShownPopup_guess(char shown);
};
#define pinstCPetInfoWnd_guess EQ_GLOBAL(CPetInfoWnd_guess*, 0x00850BAC)

#endif
