/* CPlayerNotesWnd: window, constructor 0x00544C73 (tu_195_PlayerNotesWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CPLAYERNOTESWND_H
#define TITANIUM_WND_CPLAYERNOTESWND_H

#include "titanium/wnd_views.h"

struct CXStr;

struct CPlayerNotesWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x160 - 0x15C];

    // EXTERNAL: TITANIUM 0x00544C73 CPlayerNotesWnd_guess::CPlayerNotesWnd_guess
    CPlayerNotesWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00544A29 CPlayerNotesWnd_guess::AddText_guess
    void AddText_guess(const CXStr& text);
};
#define pinstCPlayerNotesWnd_guess EQ_GLOBAL(CPlayerNotesWnd_guess*, 0x00850C8C)

#endif
