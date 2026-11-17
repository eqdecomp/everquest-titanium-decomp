/* CCastSpellWnd: window, constructor 0x004EC8B4 (tu_140_CastSpellWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCASTSPELLWND_H
#define TITANIUM_WND_CCASTSPELLWND_H

#include "titanium/wnd_views.h"

struct CCastSpellWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x1B4 - 0x15C];

    // EXTERNAL: TITANIUM 0x004EC8B4 CCastSpellWnd_guess::CCastSpellWnd_guess
    CCastSpellWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004EB590 CCastSpellWnd_guess::Method_guess
    void Method_guess();
    // EXTERNAL: TITANIUM 0x004EB5A2 CCastSpellWnd_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x004EBF26 CCastSpellWnd_guess::Dispatch_guess
    void Dispatch_guess(int index);
    // EXTERNAL: TITANIUM 0x004EC163 CCastSpellWnd_guess::Tail_guess
    void Tail_guess(int start);
    // EXTERNAL: TITANIUM 0x004EC497 CCastSpellWnd_guess::Refresh_guess
    void Refresh_guess(int value);
    // EXTERNAL: TITANIUM 0x004EC7D8 CCastSpellWnd_guess::Rebuild_guess
    void Rebuild_guess();
    // EXTERNAL: TITANIUM 0x004ECB56 CCastSpellWnd_guess::Select_guess
    void Select_guess(int index);
};
#define pinstCCastSpellWnd_guess EQ_GLOBAL(CCastSpellWnd_guess*, 0x00850C2C)

#endif
