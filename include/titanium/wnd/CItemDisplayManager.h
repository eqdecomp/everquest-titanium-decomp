/* CItemDisplayManager: object, constructor 0x0051DF88 (tu_174_ItemDisplayWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CITEMDISPLAYMANAGER_H
#define TITANIUM_WND_CITEMDISPLAYMANAGER_H

#include "titanium/eqaddr.h"

struct CItemDisplayManager_guess {
    // EXTERNAL: TITANIUM 0x0051DE5D CItemDisplayManager_guess::RequestEvolvingFinalResult_guess
    void RequestEvolvingFinalResult_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0051E099 CItemDisplayManager_guess::ShowEntryInfo_guess
    void ShowEntryInfo_guess(const char* text_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x0051E0EA CItemDisplayManager_guess::CloseNewestItemDisplay_guess
    char CloseNewestItemDisplay_guess();
    // EXTERNAL: TITANIUM 0x0051E180 CItemDisplayManager_guess::CloseAllItemDisplays_guess
    void CloseAllItemDisplays_guess();
    // EXTERNAL: TITANIUM 0x005217B6 CItemDisplayManager_guess::Set_guess
    void Set_guess(int first_guess, bool key_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x005219F6 CItemDisplayManager_guess::SetRaw_guess
    void SetRaw_guess(void* first_guess, unsigned int key_guess);
};
#define pinstCItemDisplayManager_guess EQ_GLOBAL(CItemDisplayManager_guess*, 0x00991B88)

#endif
