/* CChatManager: object, constructor 0x004F60C5 (tu_143_ChatManager). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCHATMANAGER_H
#define TITANIUM_WND_CCHATMANAGER_H

#include "titanium/eqaddr.h"

struct CXStr;

struct CChatManager_guess {
    /*0x000*/ void* chatWindows_000_guess;    /* first entry of the chat-window pointer array */
    /*0x004*/ unsigned char pad_004[0x218 - 0x004];
    /*0x218*/ int hitModes_218_guess[8];    /* "HitMode%d" (0x004F2520) */

    // EXTERNAL: TITANIUM 0x004F21A7 CChatManager_guess::CallValuesWithOne_guess
    void CallValuesWithOne_guess();
    // EXTERNAL: TITANIUM 0x004F21D6 CChatManager_guess::SaveSettings_guess
    void SaveSettings_guess();
    // EXTERNAL: TITANIUM 0x004F2591 CChatManager_guess::CallAll_guess
    void CallAll_guess();
    // EXTERNAL: TITANIUM 0x004F26C6 CChatManager_guess::HasValue_guess
    int HasValue_guess(void* value);
    // EXTERNAL: TITANIUM 0x004F288C CChatManager_guess::GetActiveChatWindow_guess
    int GetActiveChatWindow_guess();
    // EXTERNAL: TITANIUM 0x004F2BBE CChatManager_guess::GetRGBAFromIndex
    unsigned int GetRGBAFromIndex(int value);
    // EXTERNAL: TITANIUM 0x004F2E69 CChatManager_guess::GetAllVisibleText_guess
    CXStr GetAllVisibleText_guess(CXStr text_guess);
    // EXTERNAL: TITANIUM 0x004F2F65 CChatManager_guess::Contains_guess
    char Contains_guess(void* value);
    // EXTERNAL: TITANIUM 0x004F2F8A CChatManager_guess::ShowText_guess
    void ShowText_guess(CXStr text_guess, int color_guess);
};
#define pinstCChatManager_guess EQ_GLOBAL(CChatManager_guess*, 0x009917E4)

#endif
