/* CInvSlotMgr: object, constructor 0x0051A8E2 (tu_172_InvSlotMgr). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CINVSLOTMGR_H
#define TITANIUM_WND_CINVSLOTMGR_H

#include "titanium/eqaddr.h"

struct CInvSlotMgr_guess {
    /*0x000*/ virtual void Slot00_guess(int value);
    // EXTERNAL: TITANIUM 0x0051A69B CInvSlotMgr_guess::OpenAllBags_guess
    void OpenAllBags_guess();
    // EXTERNAL: TITANIUM 0x0051A6E6 CInvSlotMgr_guess::CloseAllBags_guess
    void CloseAllBags_guess();
    // EXTERNAL: TITANIUM 0x0051A730 CInvSlotMgr_guess::Add_guess
    int Add_guess(int argument);
    // EXTERNAL: TITANIUM 0x0051A891 CInvSlotMgr_guess::SetSelection_guess
    void SetSelection_guess(int value);
    // EXTERNAL: TITANIUM 0x0051A9A8 CInvSlotMgr_guess::MoveItem
    int MoveItem(int from, int to, int arg, int tryMerge);
    // EXTERNAL: TITANIUM 0x0051B201 CInvSlotMgr_guess::RunDueEntries_guess
    void RunDueEntries_guess();
    // EXTERNAL: TITANIUM 0x0051B2AE CInvSlotMgr_guess::Refresh_guess
    unsigned int Refresh_guess(char force);
};
#define pinstCInvSlotMgr_guess EQ_GLOBAL(CInvSlotMgr_guess*, 0x00850CB8)

#endif
