/* CJournalNPCWnd: window, constructor 0x005259CA (tu_177_JournalNPCWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CJOURNALNPCWND_H
#define TITANIUM_WND_CJOURNALNPCWND_H

#include "titanium/wnd_views.h"

struct CJournalNPCWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x160 - 0x15C];
    /*0x160*/ void* array_160_guess;
    /*0x164*/ unsigned char pad_164[0x1F0 - 0x164];

    // EXTERNAL: TITANIUM 0x005259CA CJournalNPCWnd_guess::CJournalNPCWnd_guess
    CJournalNPCWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005242E8 CJournalNPCWnd_guess::SaveJournal_guess
    void SaveJournal_guess();
    // EXTERNAL: TITANIUM 0x00524F87 CJournalNPCWnd_guess::RefreshAll_guess
    void RefreshAll_guess(bool mode_guess);
    // EXTERNAL: TITANIUM 0x00524FC6 CJournalNPCWnd_guess::AddDialogEntry_guess
    void AddDialogEntry_guess(char* name_guess, float x_guess, float y_guess, float z_guess, const char* entry_guess);
};
#define pinstCJournalNPCWnd_guess EQ_GLOBAL(CJournalNPCWnd_guess*, 0x00850CA4)

#endif
