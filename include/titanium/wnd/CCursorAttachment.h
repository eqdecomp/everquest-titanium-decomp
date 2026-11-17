/* CCursorAttachment: window, constructor 0x004FD3CE (tu_150_CursorAttachment). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCURSORATTACHMENT_H
#define TITANIUM_WND_CCURSORATTACHMENT_H

#include "titanium/wnd_views.h"

struct CCursorAttachment_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ int mode_15c_guess;
    /*0x160*/ int field_160_guess;
    /*0x164*/ int count_164_guess;
    /*0x168*/ unsigned char pad_168[0x184 - 0x168];

    // EXTERNAL: TITANIUM 0x004FD3CE CCursorAttachment_guess::CCursorAttachment_guess
    CCursorAttachment_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x004FD36C CCursorAttachment_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004FD3A3 CCursorAttachment_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x004FD91E CCursorAttachment_guess::Post_guess
    void Post_guess(int first_guess, int kind_guess, int third_guess, void* fourth_guess, int fifth_guess);
};
#define pinstCCursorAttachment_guess EQ_GLOBAL(CCursorAttachment_guess*, 0x00850C24)

#endif
