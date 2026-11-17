/* CFindLocationWnd: window, constructor 0x005031D3 (tu_158_FindLocationWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CFINDLOCATIONWND_H
#define TITANIUM_WND_CFINDLOCATIONWND_H

#include "titanium/wnd_views.h"

struct CFindLocationWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x17C - 0x15C];

    // EXTERNAL: TITANIUM 0x005031D3 CFindLocationWnd_guess::CFindLocationWnd_guess
    CFindLocationWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00502F2F CFindLocationWnd_guess::getByte_guess
    char getByte_guess();
    // EXTERNAL: TITANIUM 0x00502F37 CFindLocationWnd_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x00502F3E CFindLocationWnd_guess::StartFind_guess
    char StartFind_guess();
    // EXTERNAL: TITANIUM 0x0050300F CFindLocationWnd_guess::FUN_0050300f_guess
    void FUN_0050300f_guess();
    // EXTERNAL: TITANIUM 0x00503020 CFindLocationWnd_guess::LoopAndClear_guess
    void LoopAndClear_guess();
    // EXTERNAL: TITANIUM 0x005032E3 CFindLocationWnd_guess::RemoveByValue_guess
    char RemoveByValue_guess(int value);
    // EXTERNAL: TITANIUM 0x0050353E CFindLocationWnd_guess::AddSpawn_guess
    void AddSpawn_guess(void* value);
};
#define pinstCFindLocationWnd_guess EQ_GLOBAL(CFindLocationWnd_guess*, 0x009919C4)

#endif
