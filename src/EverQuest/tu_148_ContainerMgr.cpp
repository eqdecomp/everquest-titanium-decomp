// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 148: a hint from compare/tumap.py.
// CContainerMgr (Mac map: CContainerMgr::GetFreeContainerWnd): the pool of up to 26 open bag windows.
// CContainerMgr_guess is CContainerMgr, CContainerWndView_guess CContainerWnd (ctor 0x4FC9A4), Probe_guess the item a window
// shows (+0x15C).
#include "titanium/eqaddr.h"

struct Probe_guess {
    // EXTERNAL: TITANIUM 0x005DFCC0 Probe_guess::Check_guess
    char Check_guess();
};

struct CContainerWndView_guess {
    virtual void Slot00_guess();
    virtual void Release_guess(int value_guess);
    int fields_guess[86];
    Probe_guess* item_015c_guess;
    int tail_guess[21];
    // EXTERNAL: TITANIUM 0x004FC9A4 CContainerWndView_guess::CContainerWndView_guess
    CContainerWndView_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x00653184 ??_7CContainerMgr_guess@@6B@
struct CContainerMgr_guess {
    virtual void Slot00_guess();
    CContainerWndView_guess* containerWnds_0004_guess[26];
    int field6c_guess;
    int field70_guess;
    int createTime_074_guess;

    CContainerMgr_guess();
    CContainerWndView_guess* GetFreeContainerWnd_guess();
};

#define g_source_guess EQ_GLOBAL(int*, 0x00905D24)

// CContainerMgr::CContainerMgr: no windows yet; +0x74 takes the CDisplay clock (+0x148).
// FUNCTION: TITANIUM 0x004FA372
CContainerMgr_guess::CContainerMgr_guess() {
    int i_guess;
    for (i_guess = 0; i_guess < 26; ++i_guess) {
        containerWnds_0004_guess[i_guess] = 0;
    }
    field6c_guess = 0;
    createTime_074_guess = g_source_guess[0x52];
}

// CContainerMgr::GetFreeContainerWnd (Mac): first releases every window whose item is gone or fails the
// 0x5DFCC0 test, then returns a new CContainerWnd in the first empty slot, or 0 when all 26 are open.
// FUNCTION: TITANIUM 0x004FA2D4
CContainerWndView_guess* CContainerMgr_guess::GetFreeContainerWnd_guess() {
    CContainerWndView_guess** slot_guess = containerWnds_0004_guess;
    int count_guess = 26;

    for (; count_guess != 0; --count_guess, ++slot_guess) {
        if (*slot_guess != 0) {
            if ((*slot_guess)->item_015c_guess != 0 &&
                (*slot_guess)->item_015c_guess->Check_guess()) {
                continue;
            }
            // Re-tests a pointer already known non-null (match shape).
            if (*slot_guess != 0) {
                (*slot_guess)->Release_guess(1);
            }
            *slot_guess = 0;
        }
    }

    int index_guess = 0;
    do {
        if (containerWnds_0004_guess[index_guess] == 0) {
            return containerWnds_0004_guess[index_guess] = new CContainerWndView_guess(0);
        }
        ++index_guess;
    } while (index_guess < 26);

    return 0;
}

