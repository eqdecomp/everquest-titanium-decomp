// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 171: a hint from compare/tumap.py.
// One small constructor (vtable 0x656770), matched in the Mac map (low) to CInvSlot::CInvSlot.
// CInvSlot_guess is probably CInvSlot.
#include "titanium/eqaddr.h"

struct BaseState_guess {
    int field04_guess;
    int field08_guess;
    int field0c_guess;

    BaseState_guess() {
        field0c_guess = -1;
        field04_guess = 0;
        field08_guess = 0;
    }
};

// EXTERNAL: TITANIUM 0x00656770 ??_7CInvSlot_guess@@6B@
struct CInvSlot_guess : BaseState_guess {
    char padding10_guess[4];
    unsigned char flag14_guess;

    CInvSlot_guess();
    virtual void Slot00_guess();
};

// Constructor of an inventory slot object (vtable 0x656770): no item or window bound (+4, +8 = 0), slot
// id -1 (+0xC), +0x14 flag on (the slot window draws and answers only while it is set). The slot
// manager makes these when a slot window needs one
// and for the cursor slot.
// FUNCTION: TITANIUM 0x00518E10
CInvSlot_guess::CInvSlot_guess() : BaseState_guess() {
    flag14_guess = 1;
}

