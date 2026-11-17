// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 191: a hint from compare/tumap.py.
// CNoteWnd (screen "NoteWindow", vtable 0x659210): shows a note or book's text with a Done button.
// CNoteWndView_guess is CNoteWnd and KeyChild_guess its "Note" STML child.
#include "titanium/types.h"
#include <string.h>

// EXTERNAL: TITANIUM 0x005E0EC0 GetName_guess
const char* __cdecl GetName_guess();

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag_guess
CXStr __cdecl ColorTag_guess(unsigned int color);

// EXTERNAL: TITANIUM 0x0042E3D9 Concat_guess
CXStr __cdecl Concat_guess(const char* first, const CXStr& second);

// EXTERNAL: TITANIUM 0x004B1357 Join_guess
CXStr __cdecl Join_guess(const CXStr& left, const char* right);

// Vtable view of CNoteWndView_guess: the object's vptr is at +0.
struct NamedItemSlots_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess(int on_guess, int flag_guess);
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual void Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(const CXStr& text_guess);
};

// Child object at NamedItem+0x15C: vptr at 0, a field at 0x10C, scroll slot 64.
struct KeyChild_guess : NamedItemSlots_guess {
    char pad_0004_guess[0x108];
    int field_10c_guess;                  // 0x10C
    virtual void Slot64_guess(int offset_guess);
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x00659210 ??_7CNoteWndView_guess@@6B@
struct CNoteWndView_guess : CSidlScreenWndBase {
    KeyChild_guess* note_015c_guess;      // 0x15C
    CXStr text_160_guess;                 // 0x160
    CXWnd* doneButton_164_guess;          // 0x164 DoneButton
    char name_168_guess[0x400];
    int id_568_guess;
    // EXTERNAL: TITANIUM 0x0059DD30 CNoteWndView_guess::IsActive_guess
    bool IsActive_guess();
    bool SetId_guess(int id);
    void SetText_guess(const char* text);
    // EXTERNAL: TITANIUM 0x0059D770 CNoteWndView_guess::Dispatch_guess
    int Dispatch_guess(int key, unsigned int mods, bool down);
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
    int HandleKeyboardMsg_guess(int key, unsigned int mods, bool down);
    CNoteWndView_guess(CXWnd* parent);
};

// Toggle for note `id`: the note already shown clears the id and returns false (close); another stores the
// id and the name from 0x5E0EC0 and returns true.
// FUNCTION: TITANIUM 0x0053A87E
bool CNoteWndView_guess::SetId_guess(int id) {
    if (id == id_568_guess) {
        id_568_guess = 0;
        return false;
    }
    id_568_guess = id;
    strncpy(name_168_guess, GetName_guess(), 0x3ff);
    return true;
}

// Called from the OP_ReadBook branch: wraps `text` in a black colour tag, turns every '`' into
// <BR>, titles the window with the stored name and, if visible, redraws it (hide then show).
// FUNCTION: TITANIUM 0x0053A8B8
void CNoteWndView_guess::SetText_guess(const char* text) {
    // Opaque black (ARGB).
    text_160_guess = Join_guess(Concat_guess("<c ", ColorTag_guess(0xff000000)), ">");
    text_160_guess += text;
    text_160_guess += "</c>";
    int length = text_160_guess.Ptr ? text_160_guess.Ptr->length : 0;
    for (int i = 0; i < length; ++i) {
        if (EQ_METHOD(1, char, 0x004CC626, (CXStr, int), &text_160_guess)(i) == '`') {
            EQ_METHOD(2, void, 0x00572130, (CXStr, int, int), &text_160_guess)(i, 1);
            CXStr br_guess("<BR>");
            EQ_METHOD(2, void, 0x00572F20, (CXStr, int, const CXStr&), &text_160_guess)(i, br_guess);
        }
    }
    ((NamedItemSlots_guess*)this)->Slot63_guess(name_168_guess);
    if (IsActive_guess()) {
        ((NamedItemSlots_guess*)this)->Slot48_guess(0, 1);
        ((NamedItemSlots_guess*)this)->Slot48_guess(1, 1);
    }
}

// Done closes the window (slot 34).
// FUNCTION: TITANIUM 0x0053AA4C
int CNoteWndView_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1 && sender == doneButton_164_guess) {
        ((NamedItemSlots_guess*)this)->Slot34_guess();
        return 1;
    }
    return ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(sender, message, data);
}

// HandleKeyboardMsg: Page Down / Page Up (DirectInput 0xD1 / 0xC9) with only modifier flag 1 scroll the
// note by 98 px; every other key goes to CXWnd::HandleKeyboardMsg.
// FUNCTION: TITANIUM 0x0053AA7D
int CNoteWndView_guess::HandleKeyboardMsg_guess(int key, unsigned int mods, bool down) {
    bool bit2 = ((mods >> 2) & 1) != 0;
    bool bit0 = (mods & 1) != 0;
    bool bit1 = ((mods >> 1) & 1) != 0;
    if (down) {
        switch (key) {
        case 0xD1:
            if (bit0 && !bit1 && !bit2) {
                if (note_015c_guess != 0) {
                    note_015c_guess->Slot64_guess(note_015c_guess->field_10c_guess + 0x62);
                }
                return 0;
            }
            break;
        case 0xC9:
            if (bit0 && !bit1 && !bit2) {
                if (note_015c_guess != 0) {
                    note_015c_guess->Slot64_guess(note_015c_guess->field_10c_guess - 0x62);
                }
                return 0;
            }
            break;
        }
    }
    return Dispatch_guess(key, mods, down);
}

// Binds Note and DoneButton and reserves 2 KB for the text.
// FUNCTION: TITANIUM 0x0053AB19
CNoteWndView_guess::CNoteWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "NoteWindow") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        EQ_METHOD(1, void, 0x00572040, (CXStr, int), &text_160_guess)(0x800);
        note_015c_guess = (KeyChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("Note");
        doneButton_164_guess = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        name_168_guess[0] = 0;
        id_568_guess = 0;
    }
}
