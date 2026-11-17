// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 153: a hint from compare/tumap.py.
// The rest of CEQMainWnd (vtable 0x653C60; ctor 0x4FFC7F in tu_152): its EQButton toggles the EQ menu kept
// by the cascade-menu manager 0x991758 (tu_138). CEQMainWnd_guess is CEQMainWnd (node_guess the EQButton,
// value_guess the menu id); EQWndManagerView_guess is the game's CXWndManager subclass, the one at 0x99D3EC.
#include "titanium/eqaddr.h"

#define g_constructorData_guess EQ_GLOBAL(int, 0x009889BC)

struct Node_guess {
    char pad0000_guess[0x128];
    char active_guess;
    // EXTERNAL: TITANIUM 0x005BB140 Node_guess::SetCheck
    void SetCheck(bool value);
};

struct CascadeMenuManagerView_guess {
    // EXTERNAL: TITANIUM 0x004EAE22 CascadeMenuManagerView_guess::Check
    char Check(int value);
    // EXTERNAL: TITANIUM 0x004EABC3 CascadeMenuManagerView_guess::OpenSubmenu_guess
    void OpenSubmenu_guess(int value, int state);
    // EXTERNAL: TITANIUM 0x004EACFA CascadeMenuManagerView_guess::Disable
    void Disable(int value);
    // EXTERNAL: TITANIUM 0x004EB20E CascadeMenuManagerView_guess::Remove_guess
    void Remove_guess(int value);
};

#define pinstCascadeMenuList_guess EQ_GLOBAL(CascadeMenuManagerView_guess*, 0x00991758)

struct PointerArray_guess {
    // EXTERNAL: TITANIUM 0x0050F3F6 PointerArray_guess::Reset
    void Reset();
};

struct DispatchBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 DispatchBase_guess::~DispatchBase_guess
    ~DispatchBase_guess();
    virtual void Slot00_guess();
};

// EXTERNAL: TITANIUM 0x0059D960 GetState_guess
int __stdcall GetState_guess(void* output);

// EXTERNAL: TITANIUM 0x00653C60 ??_7CEQMainWnd_guess@@6B@
struct CEQMainWnd_guess : DispatchBase_guess {
    char pad0000_guess[0x58];
    char enabled_guess;
    char pad005d_guess[0xff];
    Node_guess* node_guess;
    PointerArray_guess* storage_guess;
    int value_guess;

    // EXTERNAL: TITANIUM 0x005A0E50 CEQMainWnd_guess::OnProcessFrame
    void OnProcessFrame();
    // EXTERNAL: TITANIUM 0x005A2230 CEQMainWnd_guess::WndNotification
    int WndNotification(int node, int event, int value);
    void OnProcessFrame_guess();
    int WndNotification_guess(int node, int event, int value);
    ~CEQMainWnd_guess();
    CEQMainWnd_guess* Delete_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Per-frame (OnProcessFrame override): pops the EQ button back out once its menu has closed.
// FUNCTION: TITANIUM 0x004FFD6E
void CEQMainWnd_guess::OnProcessFrame_guess() {
    if (enabled_guess != 0 && node_guess != 0 && node_guess->active_guess != 0) {
        if (pinstCascadeMenuList_guess->Check(value_guess) == 0) {
            node_guess->SetCheck(0);
        }
    }
    OnProcessFrame();
}

// EQButton click: opens the EQ menu at the button's screen rect (CXWnd::GetScreenRect 0x59D960) when
// the button is now checked, closes it otherwise; everything else goes to CSidlScreenWnd::WndNotification.
// FUNCTION: TITANIUM 0x004FFDB4
int CEQMainWnd_guess::WndNotification_guess(int node, int event, int value) {
    if (event == 1 && node == (int)node_guess) {
        if (node_guess->active_guess != 0) {
            int state_guess[4];
            int state = GetState_guess(state_guess);
            pinstCascadeMenuList_guess->OpenSubmenu_guess(value_guess, state);
        } else {
            pinstCascadeMenuList_guess->Disable(value_guess);
        }
        return 0;
    }
    return WndNotification(node, event, value);
}

// Destructor: drops the EQ menu from the manager and frees the menu definition (+0x160).
// FUNCTION: TITANIUM 0x004FFE1E
CEQMainWnd_guess::~CEQMainWnd_guess() {
    pinstCascadeMenuList_guess->Remove_guess(value_guess);
    PointerArray_guess* storage = storage_guess;
    if (storage != 0) {
        storage->Reset();
        free(storage);
    }
}

// Scalar deleting destructor (names.tsv CTrainWnd::~CTrainWnd is a low-confidence miss).
// FUNCTION: TITANIUM 0x004FFE7C
CEQMainWnd_guess* CEQMainWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->~CEQMainWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x004CD510 GetMouseClientPos_guess
__int64 __cdecl GetMouseClientPos_guess();

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005AF020 Base_guess::Base_guess
    Base_guess(int value, void* data, __int64 extra);
    virtual void Slot00_guess();
};

// EXTERNAL: TITANIUM 0x00653DA0 ??_7EQWndManagerView_guess@@6B@
struct EQWndManagerView_guess : Base_guess {
    EQWndManagerView_guess(int value);
};

// Game window manager: CXWndManager::CXWndManager (0x5AF020) with the resource set, 0x9889BC and the value
// from 0x4CD510, then vtable 0x653DA0; tu_029 stores it at 0x99D3EC.
// FUNCTION: TITANIUM 0x004FFE98
EQWndManagerView_guess::EQWndManagerView_guess(int value)
    : Base_guess(value, &g_constructorData_guess, GetMouseClientPos_guess()) {
}

