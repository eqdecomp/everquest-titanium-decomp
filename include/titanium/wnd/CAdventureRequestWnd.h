/* CAdventureRequestWnd: window, constructor 0x004D642B. Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CADVENTUREREQUESTWND_H
#define TITANIUM_WND_CADVENTUREREQUESTWND_H

#include "titanium/wnd_views.h"

struct CAdventureRequestWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x198 - 0x15C];

    // EXTERNAL: TITANIUM 0x004D642B CAdventureRequestWnd_guess::CAdventureRequestWnd_guess
    CAdventureRequestWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004D6986 CAdventureRequestWnd_guess::Apply_4d6986_guess
    void Apply_4d6986_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x004D69DD CAdventureRequestWnd_guess::ApplyLogged_guess
    void ApplyLogged_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x004D6A4B CAdventureRequestWnd_guess::Apply_4d6a4b_guess
    void Apply_4d6a4b_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x004D6AA3 CAdventureRequestWnd_guess::AdventureRequestSetRiskLevel_guess
    void AdventureRequestSetRiskLevel_guess(int value);
    // EXTERNAL: TITANIUM 0x004D6ABB CAdventureRequestWnd_guess::AdventureRequestSetAdventureTypeChoice_guess
    void AdventureRequestSetAdventureTypeChoice_guess(int value);
    // EXTERNAL: TITANIUM 0x004D6ACD CAdventureRequestWnd_guess::UpdateTimerValues_guess
    void UpdateTimerValues_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004D6BD9 CAdventureRequestWnd_guess::ClearFirstCountdown_guess
    void ClearFirstCountdown_guess();
    // EXTERNAL: TITANIUM 0x004D6C31 CAdventureRequestWnd_guess::ClearSecondCountdown_guess
    void ClearSecondCountdown_guess();
    // EXTERNAL: TITANIUM 0x004D6C89 CAdventureRequestWnd_guess::FormatTime_guess
    void FormatTime_guess(int time_guess);
    // EXTERNAL: TITANIUM 0x004D6D3D CAdventureRequestWnd_guess::FormatSecondTime_guess
    void FormatSecondTime_guess(int time_guess);
    // EXTERNAL: TITANIUM 0x004D7084 CAdventureRequestWnd_guess::SetMode_guess
    void SetMode_guess(int mode_guess);
};
#define pinstCAdventureRequestWnd_guess EQ_GLOBAL(CAdventureRequestWnd_guess*, 0x009913D4)

#endif
