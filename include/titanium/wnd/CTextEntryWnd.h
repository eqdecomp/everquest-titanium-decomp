/* CTextEntryWnd: window, constructor 0x00560A6C (tu_224_TextEntryWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTEXTENTRYWND_H
#define TITANIUM_WND_CTEXTENTRYWND_H

#include "titanium/wnd_views.h"

struct CXStr;

struct CTextEntryWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x168 - 0x15C];
    /*0x168*/ CXWnd* notificationTarget_168_guess;
    /*0x16C*/ unsigned char pad_16C[0x17C - 0x16C];

    // EXTERNAL: TITANIUM 0x00560A6C CTextEntryWnd_guess::CTextEntryWnd_guess
    CTextEntryWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00560D80 CTextEntryWnd_guess::GetEntryText_guess
    CXStr GetEntryText_guess();
    // EXTERNAL: TITANIUM 0x00560D9E CTextEntryWnd_guess::Set_guess
    void Set_guess(CXStr text);
    // EXTERNAL: TITANIUM 0x00560E32 CTextEntryWnd_guess::Activate_guess
    void Activate_guess(void* notificationTarget, int type, const char* prompt, int minLength, int maxLength, const char* initialText);
};
#define pinstCTextEntryWnd_guess EQ_GLOBAL(CTextEntryWnd_guess*, 0x00850C80)

#endif
