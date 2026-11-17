// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 224: a hint from compare/tumap.py.
// CTextEntryWnd constructor (screen "TextEntryWnd", vtable 0x65E0B8): a one-line text prompt with OK and
// Cancel. CTextEntryWndView_guess is CTextEntryWnd; CXStrView_guess (+0x164) is a CXStr.
#include "titanium/types.h"

/* CTextEntryWnd layout (types.h, 0x17C): base CSidlScreenWnd ends at 0x15C. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

/* 0x164: a 4-byte member with a destructor (EH state), out-of-line at 0x004482FB. */
struct CXStrView_guess {
    int raw_164;
    CXStrView_guess() : raw_164(0) {}
    // EXTERNAL: TITANIUM 0x004482FB ??1CXStrView_guess@@QAE@XZ
    ~CXStrView_guess();
};

// EXTERNAL: TITANIUM 0x0065E0B8 ??_7CTextEntryWndView_guess@@6B@
struct CTextEntryWndView_guess : CSidlScreenWndBase {
    int field_15c;                      // 0x15c
    int field_160;                      // 0x160
    CXStrView_guess field_164;     // 0x164
    int field_168;                      // 0x168
    CXWnd* entry_16c;                   // 0x16c Entry
    CXWnd* prompt_170;                  // 0x170 Prompt
    CXWnd* ok_174;                      // 0x174 OK
    CXWnd* cancel_178;                  // 0x178 Cancel
    CTextEntryWndView_guess(CXWnd* parent);
};

// Mac: CTextEntryWnd::CTextEntryWnd. Binds Entry, Prompt, OK and Cancel.
// FUNCTION: TITANIUM 0x00560A6C
CTextEntryWndView_guess::CTextEntryWndView_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "TextEntryWnd") {
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        entry_16c = ((CSidlScreenWnd*)this)->GetChildItem("Entry");
        prompt_170 = ((CSidlScreenWnd*)this)->GetChildItem("Prompt");
        ok_174 = ((CSidlScreenWnd*)this)->GetChildItem("OK");
        cancel_178 = ((CSidlScreenWnd*)this)->GetChildItem("Cancel");
        // 0x59DB90 with 199, probably the Z layer, as CQuantityWnd does.
        FUN_0059db90_guess(199);
        field_168 = 0;
        field_15c = 1;
        field_160 = 10;
        // Empties the CXStr at +0x164 through its destructor (0x4482FB); kept as compiled.
        field_164.~CXStrView_guess();
    }
}
