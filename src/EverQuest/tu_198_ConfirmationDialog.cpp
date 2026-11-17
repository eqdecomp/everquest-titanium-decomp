// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 198: a hint from compare/tumap.py.
// CConfirmationDialog, the pooled yes/no/OK prompt, and its manager. Node_guess, EventOwner_guess and
// ConfirmationDialog_guess are all CConfirmationDialog views (same +0x15C-0x184 fields, vtable 0x65AB70).
// ArrayClass2_guess is a chunked ArrayClass2; CConfirmationDialogManager_guess (global 0x991E44) holds the dialogs plus their open
// times. Button mask (+0x174) and result codes share bits: 1 OK, 2 button +0x168 or expiry, 4 Yes, 8 No.
#include <new>
#include "titanium/types.h"
#include "titanium/crt.h"
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z

// EXTERNAL: TITANIUM 0x0060E985 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* value_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 Free_guess
void __cdecl Free_guess(void* value_guess);

struct CXStrView_guess {
    // EXTERNAL: TITANIUM 0x00571FC0 CXStrView_guess::Set_guess
    void Set_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x004482FB CXStrView_guess::~CXStrView_guess
    ~CXStrView_guess();
};

struct CMiniDockBase_guess {
    char pad_guess[0x170];
    // EXTERNAL: TITANIUM 0x005A3100 CMiniDockBase_guess::~CMiniDockBase_guess
    ~CMiniDockBase_guess();
};

struct CMiniDockFrameWnd_guess : CMiniDockBase_guess {
    CXStrView_guess text170_guess;
    CMiniDockFrameWnd_guess* Delete_guess(unsigned int flags);
    ~CMiniDockFrameWnd_guess();
};

struct Action_guess {
    virtual void Slot00_guess(int value, int kind, unsigned int flags);
    void Purge_guess(int value);
};

struct Callback_guess {
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
    virtual void Slot48_guess(char value, int kind);
};

struct FlagState_guess {
    int count;
    union {
        unsigned char low;
        unsigned int flags;
    } value;
};

struct Rel_guess {
    // EXTERNAL: TITANIUM 0x005A8BF0 Rel_guess::SetWindowTextA
    void SetWindowTextA(void* state);
};

struct EventOwner_guess {
    char pad00[0x15c];
    Rel_guess* present15c;
    Callback_guess* callback160;
    Callback_guess* callback164;
    Callback_guess* callback168;
    Callback_guess* callback16c;
    FlagState_guess state;
    void ShowButtons_guess();
};

struct Node_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value);
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
    virtual void Slot48_guess(int value, int kind);
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
    virtual void Slot63_guess();
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess(int a, int b, int c, int d, int e, int f);
    char pad04[0x58];
    unsigned char enabled5c;
    char pad5d[0x103];
    int event160_guess;
    int event164_guess;
    int event168_guess;
    int event16c_guess;
    CXStrView_guess text170_guess;
    int value174_guess;
    Action_guess* action178;
    int action17c;
    int unknown180;
    unsigned int flags184;
    void Activate_guess(Action_guess* action, int value, const char* name, int field174,
                    int offset, unsigned int flags);
    void Expire_guess();
    void Deactivate_guess();
    void OnProcessFrame_guess();
    int WndNotification_guess(int value, int kind, int extra);
    // EXTERNAL: TITANIUM 0x005A0E50 Node_guess::OnProcessFrame
    void OnProcessFrame();
    // EXTERNAL: TITANIUM 0x0059DD30 Node_guess::CheckEnabled_guess
    char CheckEnabled_guess();
};

// EXTERNAL: TITANIUM 0x0046D655 CurrentValue_guess
int __cdecl CurrentValue_guess();

// EXTERNAL: TITANIUM 0x005A2230 UnknownEvent_guess
int __stdcall UnknownEvent_guess(int value, int kind, int extra);

struct ArrayClass2_guess {
    int count;
    int chunkSize;
    unsigned mask;
    int shift;
    Node_guess*** buckets;
    int chunkCount;
    char enabled;
    char pad19[7];
    int Find_guess(Action_guess* action, int value);
    char ExpireAt_guess(int index);
    void Prepare_guess(int count);
    // EXTERNAL: TITANIUM 0x0051DA09 ArrayClass2_guess::RoundUp_guess
    int RoundUp_guess(int count);
    // EXTERNAL: TITANIUM 0x0047C3AF ArrayClass2_guess::Init_guess
    void Init_guess(int value);
    // EXTERNAL: TITANIUM 0x004B73EE ArrayClass2_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00405492 ArrayClass2_guess::Fail_guess
    void Fail_guess();
    // EXTERNAL: TITANIUM 0x0040600C ArrayClass2_guess::Set_guess
    void Set_guess(int index, int* value);
    ~ArrayClass2_guess() ;
};

struct CConfirmationDialogManager_guess : ArrayClass2_guess {
    ArrayClass2_guess table20;
    CConfirmationDialogManager_guess* Init_guess();
    ~CConfirmationDialogManager_guess();
    void ExpireAll_guess();
    int Index_guess(int action, int value);
    Node_guess* Activate(int p2, int p3, int p4, int p5, int p6, int p7, int p8);
};

// 0x004B73EE (landed in tu_077_ItemMoveQueue.cpp). This file keeps the body so that 0x0054815C sees it (nothrow:
// delete[] only); tests/unicorn/crt_defaults.json maps the symbol to 0x004B73EE.
ArrayClass2_guess::~ArrayClass2_guess() {
    for (int i = 0; i < chunkCount; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
    buckets = 0;
    chunkCount = 0;
    count = 0;
}

/* ---- CConfirmationDialog::CConfirmationDialog(CXWnd*) (0x00547C3D) ----------------------------------
 * Layout: include/titanium/types.h CConfirmationDialog (0x188). The ctor needs a polymorphic class with the
 * real CSidlScreenWnd base ctor/dtor, so it derives from CSidlScreenWndBase; header methods are called through the
 * CSidlScreenWnd layout view. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065AB70 ??_7ConfirmationDialog_guess@@6B@
struct ConfirmationDialog_guess : CSidlScreenWndBase {
    CXWnd* textOutput_15c;              // 0x15c TextOutput
    CXWnd* yesButton_160;               // 0x160 Yes_Button
    CXWnd* noButton_164;                // 0x164 No_Button
    CXWnd* button_168;                  // 0x168
    CXWnd* okButton_16c;                // 0x16c OK_Button
    CXStr text_170;                     // 0x170
    int value_174;                      // 0x174
    Action_guess* action_178;           // 0x178
    int actionValue_17c;                // 0x17c
    int timeout_180;                    // 0x180
    unsigned int flags_184;             // 0x184
    // EXTERNAL: TITANIUM 0x0060D071 ??2ConfirmationDialog_guess@@SAPAXI@Z
    static void* operator new(unsigned int size);
    // EXTERNAL: TITANIUM 0x0059FA70 ConfirmationDialog_guess::Move_guess
    void Move_guess(const struct Point_guess& pos);
    ConfirmationDialog_guess(CXWnd* parent);
};

struct Point_guess {
    int x;
    int y;
    Point_guess(int x_, int y_) : x(x_), y(y_) {}
};

// Confirmation dialog constructor: no timeout (-1), finds Yes_Button, No_Button, OK_Button and
// TextOutput.
// FUNCTION: TITANIUM 0x00547C3D
ConfirmationDialog_guess::ConfirmationDialog_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "ConfirmationDialogBox") {
    timeout_180 = -1;
    action_178 = 0;
    yesButton_160 = 0;
    noButton_164 = 0;
    button_168 = 0;
    okButton_16c = 0;
    textOutput_15c = 0;
    if (SidlPiece != 0) {
        field_018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        yesButton_160 = ((CSidlScreenWnd*)this)->GetChildItem("Yes_Button");
        noButton_164 = ((CSidlScreenWnd*)this)->GetChildItem("No_Button");
        okButton_16c = ((CSidlScreenWnd*)this)->GetChildItem("OK_Button");
        textOutput_15c = ((CSidlScreenWnd*)this)->GetChildItem("TextOutput");
        if (textOutput_15c != 0) {
            // Placeholder until Activate supplies the prompt text.
            textOutput_15c->SetWindowTextA("Error, no text set.");
        }
        FUN_0059db90_guess(200);
    }
}

// Shows only the buttons named in the mask (+0x174), then puts the prompt text (+0x170) in TextOutput.
// Rel_guess::SetWindowTextA is probably CStmlWnd::SetSTMLTextWithoutHistory (Mac match, low).
// FUNCTION: TITANIUM 0x00547E07
void EventOwner_guess::ShowButtons_guess() {
    int one = 1;
    if (callback16c != 0) {
        callback16c->Slot48_guess((int)(state.value.low & one), one);
    }
    if (callback168 != 0) {
        callback168->Slot48_guess((state.value.flags >> 1) & one, one);
    }
    if (callback160 != 0) {
        callback160->Slot48_guess((state.value.flags >> 2) & one, one);
    }
    if (callback164 != 0) {
        callback164->Slot48_guess((state.value.flags >> 3) & one, one);
    }
    if (present15c != 0) {
        present15c->SetWindowTextA(&state.count);
    }
}

// CConfirmationDialog::Deactivate (vtable slot 34): forgets the owner, timeout and buttons, and hides.
// FUNCTION: TITANIUM 0x00547EAF
void Node_guess::Deactivate_guess() {
    unknown180 = -1;
    action178 = 0;
    flags184 = 0;
    Slot48_guess(0, 1);
}

// Expires a shown dialog: deactivates it, then tells the owner result 2.
// FUNCTION: TITANIUM 0x00547ED0
void Node_guess::Expire_guess() {
    if (enabled5c != 0) {
        unsigned int flags = flags184;
        Action_guess* action = action178;
        int value = action17c;
        Slot34_guess();
        // Owner message id 11 is never called back; which prompt that is is not known.
        if (value != 0xb && action != 0) {
            action->Slot00_guess(value, 2, flags);
        }
    }
}

// OnProcessFrame: expires the dialog once EqGetTime passes its deadline (+0x180, -1 = none).
// FUNCTION: TITANIUM 0x00547F0A
void Node_guess::OnProcessFrame_guess() {
    int value = CurrentValue_guess();
    if (unknown180 != -1 && value > unknown180) {
        Expire_guess();
    }
    OnProcessFrame();
}

// WndNotification: a click (kind 1) on a button calls the owner back with that button's mask bit and
// closes the dialog; anything else goes to CSidlScreenWnd::WndNotification.
// FUNCTION: TITANIUM 0x00547F30
int Node_guess::WndNotification_guess(int value, int kind, int extra) {
    int one = 1;
    int matched = 0;
    if (kind == one) {
        if (value == event160_guess) {
            kind = 4;
            matched = 1;
        } else if (value == event164_guess) {
            kind = 8;
            matched = 1;
        } else if (value == event16c_guess) {
            kind = one;
            matched = 1;
        } else if (value == event168_guess) {
            kind = 2;
            matched = 1;
        }
    }
    if (matched != 0) {
        int flags = flags184;
        Action_guess* action = action178;
        int actionValue = action17c;
        Slot34_guess();
        if (actionValue != 0xb && action != 0) {
            action->Slot00_guess(actionValue, kind, flags);
        }
        return 0;
    }
    return UnknownEvent_guess(value, kind, extra);
}

// Scalar deleting destructor of a confirmation dialog (vtable 0x65AB70 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00547FC4
CMiniDockFrameWnd_guess* CMiniDockFrameWnd_guess::Delete_guess(unsigned int flags) {
    this->~CMiniDockFrameWnd_guess();
    if ((flags & 1) != 0) {
        Free_guess(this);
    }
    return this;
}

// Destructor of a confirmation dialog: destroys the prompt text (+0x170), then runs the CSidlScreenWnd
// destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00547FE0
CMiniDockFrameWnd_guess::~CMiniDockFrameWnd_guess() {
}

// CConfirmationDialog::Activate (vtable slot 72): expires any prompt still open (its owner gets result 2),
// then stores the owner, its message id, the text, the button mask (`field174`, 0xC = Yes and No), the
// deadline `offset` ms from now (-1 = never) and `flags`, which goes back to the owner with the result.
// FUNCTION: TITANIUM 0x00548018
void Node_guess::Activate_guess(Action_guess* action, int value, const char* name, int field174,
                            int offset, unsigned int flags) {
    if (CheckEnabled_guess()) {
        Expire_guess();
    }
    action178 = action;
    action17c = value;
    text170_guess.Set_guess(name);
    value174_guess = field174;
    unknown180 = CurrentValue_guess() + offset;
    if (offset == -1) {
        unknown180 = -1;
    }
    flags184 = flags;
    ((EventOwner_guess*)this)->ShowButtons_guess();
    Slot48_guess(1, 1);
}

// ArrayClass2 Assure: grows the chunk table to hold `count` entries; on allocation failure empties the array
// and reports it through Fail_guess.
// FUNCTION: TITANIUM 0x00548095
void ArrayClass2_guess::Prepare_guess(int count) {
    if (enabled != 0 && count > 0) {
        int newCount = RoundUp_guess(count);
        if (newCount > chunkCount) {
            Node_guess*** newChunks = (Node_guess***)operator new(newCount << 2);
            if (newChunks == 0) {
                enabled = 0;
            } else {
                for (int i = 0; i < chunkCount; ++i) {
                    newChunks[i] = buckets[i];
                }
                for (int j = chunkCount; j < newCount; ++j) {
                    Node_guess** block = (Node_guess**)operator new(chunkSize << 2);
                    newChunks[j] = block;
                    if (block == 0) {
                        enabled = 0;
                        break;
                    }
                }
                if (enabled != 0) {
                    _free(buckets);
                    buckets = newChunks;
                    chunkCount = newCount;
                }
            }
        }
        if (enabled == 0) {
            Clear_guess();
            Fail_guess();
        }
    }
}

// Constructs the manager: dialog array and open-time array, 32 entries per chunk.
// FUNCTION: TITANIUM 0x00548144
CConfirmationDialogManager_guess* CConfirmationDialogManager_guess::Init_guess() {
    ArrayClass2_guess::Init_guess(0x20);
    table20.Init_guess(0x20);
    return this;
}

// Expires every dialog (owners get result 2) and deletes it.
// FUNCTION: TITANIUM 0x0054815C
CConfirmationDialogManager_guess::~CConfirmationDialogManager_guess() {
    int index = 0;
    if (count > 0) {
        do {
            Node_guess* node = buckets[index >> shift][index & mask];
            node->Expire_guess();
            // Null test after the Expire_guess call on the same pointer: original order, keep it.
            if (node != 0) {
                node->Slot01_guess(1);
            }
            ++index;
        } while (index < count);
    }
    this->ArrayClass2_guess::~ArrayClass2_guess();
}

// Index of the dialog opened by `action` for message `value` (-1 = any message), or -1.
// FUNCTION: TITANIUM 0x005481CF
int ArrayClass2_guess::Find_guess(Action_guess* action, int value) {
    int count = this->count;
    int index = 0;
    if (count > 0) {
        do {
            Node_guess* node = buckets[index >> shift][index & mask];
            if (node->action178 == action) {
                if (value == -1 || value == node->action17c) {
                    return index;
                }
            }
            ++index;
        } while (index < count);
    }
    return -1;
}

// Expires the dialog at `index`; returns whether the index was valid.
// FUNCTION: TITANIUM 0x00548225
char ArrayClass2_guess::ExpireAt_guess(int index) {
    char result = 0;
    if (index >= 0 && index < count) {
        Node_guess* node = buckets[index >> shift][index & mask];
        node->Expire_guess();
        result = 1;
    }
    return result;
}

// Expires every dialog still shown.
// FUNCTION: TITANIUM 0x00548256
void CConfirmationDialogManager_guess::ExpireAll_guess() {
    int index = 0;
    if (count > 0) {
        do {
            if (buckets[index >> shift][index & mask]->CheckEnabled_guess()) {
                buckets[index >> shift][index & mask]->Expire_guess();
            }
            ++index;
        } while (index < count);
    }
}

#define g_table_guess EQ_GLOBAL(ArrayClass2_guess*, 0x00991E44)

// Expires every dialog this owner opened for message `value` (-1 = all of them); for an owner going away.
// FUNCTION: TITANIUM 0x005482A0
void Action_guess::Purge_guess(int value) {
    if (g_table_guess != 0) {
        int index;
        while ((index = g_table_guess->Find_guess(this, value)) != -1) {
            g_table_guess->ExpireAt_guess(index);
        }
    }
}

// Picks a dialog for `action`: the last hidden one, or, when `value` (a bool) is set, the owner's own open
// one, expired first. With none free it creates PopDialog<n>, offset 20 px per dialog, with INI storage.
// Returns the index.
// FUNCTION: TITANIUM 0x005482D4
// @early-stop: tiebreak, diff ndiff=3
int CConfirmationDialogManager_guess::Index_guess(int action, int value) {
    int found = -1;
    for (int index = 0; index < count; ++index) {
        if (!buckets[index >> shift][index & mask]->CheckEnabled_guess()) {
            found = index;
        } else if ((char)value != 0
                   && action == (int)buckets[index >> shift][index & mask]->action178) {
            buckets[index >> shift][index & mask]->Expire_guess();
            found = index;
        }
    }
    if (found == -1) {
        ConfirmationDialog_guess* node = new ConfirmationDialog_guess(0);
        Node_guess* entry = (Node_guess*)node;
        int slot = count;
        found = slot;
        char name[256];
        // The INI section name for the new dialog's position.
        sprintf(name, "PopDialog%d", slot);
        int offset = slot * 20;
        node->Move_guess(Point_guess(((CXWnd*)node)->GetScreenRect().left + offset,
                                     ((CXWnd*)node)->GetScreenRect().top + offset));
        ((CSidlScreenWnd*)node)->EnableIniStorage(-259, name);
        Set_guess(count, (int*)&entry);
        value = -1;
        table20.Set_guess(table20.count, &value);
    }
    return found;
}

// Opens a prompt: picks a dialog, activates it with the six arguments and stamps its open time; returns
// the dialog. p8 = reuse the owner's open dialog.
// FUNCTION: TITANIUM 0x00548460
Node_guess* CConfirmationDialogManager_guess::Activate(int p2, int p3, int p4, int p5, int p6, int p7, int p8) {
    int index = Index_guess(p2, p8);
    buckets[index >> shift][index & mask]->Slot72_guess(p2, p3, p4, p5, p6, p7);
    Node_guess** slot = &table20.buckets[index >> table20.shift][index & table20.mask];
    *slot = (Node_guess*)CurrentValue_guess();
    return buckets[index >> shift][index & mask];
}
