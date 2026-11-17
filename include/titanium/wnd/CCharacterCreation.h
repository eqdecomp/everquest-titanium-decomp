/* CCharacterCreation: window, constructor 0x004EF965 (tu_141_CharacterCreation). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCHARACTERCREATION_H
#define TITANIUM_WND_CCHARACTERCREATION_H

#include "titanium/wnd_views.h"

struct CCharacterCreation_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x418 - 0x15C];
    /*0x418*/ int field_418_guess;
    /*0x41C*/ unsigned char pad_41C[0x420 - 0x41C];
    /*0x420*/ unsigned char field_420_guess;

    // EXTERNAL: TITANIUM 0x004EE824 CCharacterCreation_guess::ApplyName_guess
    void ApplyName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x004EE8CA CCharacterCreation_guess::Transfer_guess
    void Transfer_guess(void* character);
    // EXTERNAL: TITANIUM 0x004EE978 CCharacterCreation_guess::OnBackButton_guess
    void OnBackButton_guess();
    // EXTERNAL: TITANIUM 0x004EFEF1 CCharacterCreation_guess::HandleApproveName_guess
    void HandleApproveName_guess(int mode);
    // EXTERNAL: TITANIUM 0x004F01D0 CCharacterCreation_guess::OnNextButton_guess
    void OnNextButton_guess();
    // EXTERNAL: TITANIUM 0x004F04EC CCharacterCreation_guess::Reset_guess
    void Reset_guess();
};
#define pinstCCharacterCreation_guess EQ_GLOBAL(CCharacterCreation_guess*, 0x00850C20)

#endif
