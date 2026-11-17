/* CSpellBookWnd: window, constructor 0x00558521 (tu_215_SpellBookWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CSPELLBOOKWND_H
#define TITANIUM_WND_CSPELLBOOKWND_H

#include "titanium/wnd_views.h"

struct CSpellBookWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x2A8 - 0x15C];

    // EXTERNAL: TITANIUM 0x00558521 CSpellBookWnd_guess::CSpellBookWnd_guess
    CSpellBookWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0055697D CSpellBookWnd_guess::GetSpellScribeTicksLeft_guess
    int GetSpellScribeTicksLeft_guess();
    // EXTERNAL: TITANIUM 0x00556B72 CSpellBookWnd_guess::GetSpellMemTicksLeft_guess
    int GetSpellMemTicksLeft_guess();
    // EXTERNAL: TITANIUM 0x00556FA1 CSpellBookWnd_guess::StartMemorize_guess
    char StartMemorize_guess(int spellId, int gemIndex, char flag);
    // EXTERNAL: TITANIUM 0x0055712B CSpellBookWnd_guess::FinishMemorize_guess
    void FinishMemorize_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x005579C8 CSpellBookWnd_guess::HandleDeleteSpellReply_guess
    void HandleDeleteSpellReply_guess(int index, int mode);
    // EXTERNAL: TITANIUM 0x00557A73 CSpellBookWnd_guess::SaveSpellbookFile_guess
    void SaveSpellbookFile_guess(char* buffer_guess);
    // EXTERNAL: TITANIUM 0x00557CD8 CSpellBookWnd_guess::MemorizeSet
    void MemorizeSet(int* values_guess, int count_guess);
    // EXTERNAL: TITANIUM 0x00557E55 CSpellBookWnd_guess::MemorizeSpellById_guess
    void MemorizeSpellById_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x005581DE CSpellBookWnd_guess::FinishScribe_guess
    void FinishScribe_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x0055828A CSpellBookWnd_guess::SwapSpellBookSlots_guess
    void SwapSpellBookSlots_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x00558361 CSpellBookWnd_guess::SetPage_guess
    void SetPage_guess(int value);
};
#define pinstCSpellBookWnd_guess EQ_GLOBAL(CSpellBookWnd_guess*, 0x00850C30)

#endif
