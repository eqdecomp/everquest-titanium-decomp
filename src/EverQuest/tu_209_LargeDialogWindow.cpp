// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 209: a hint from compare/tumap.py.
// The constructor of the server-popup window (instance 0x991F5C, vtable 0x65C7E0): a CLargeDialogWindow
// (base ctor 0x5264BF, tu_178) that shows OP_OnLevelMessage (0x1DDE) and answers with OP_PopupResponse
// (0x3816); the rest of the class is in tu_210. PopupMessageWnd_guess is this subclass, not the base.
#include "titanium/eqaddr.h"

#define g_vtable_guess EQ_GLOBAL(char, 0x0065C7E0)

struct PopupMessageWnd_guess {
    void* vtable;           // 0x0
    char pad_0004[0x180];   // 0x4
    int field_0184;         // 0x184
    int field_0188;         // 0x188
    int field_018c;         // 0x18c

    // EXTERNAL: TITANIUM 0x005264BF PopupMessageWnd_guess::InitBase_guess
    void InitBase_guess(void* arg);
    PopupMessageWnd_guess* Init_guess(void* arg);
};

// Constructor: the CLargeDialogWindow base, three extra fields (+0x184-0x18C) zeroed, then this class's
// vtable. Built once by the UI setup in tu_029.
// FUNCTION: TITANIUM 0x00553747
PopupMessageWnd_guess* PopupMessageWnd_guess::Init_guess(void* arg) {
    InitBase_guess(arg);
    field_0184 = 0;
    field_0188 = 0;
    field_018c = 0;
    vtable = &g_vtable_guess;
    return this;
}
