/* CascadeMenuList: object. Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CASCADEMENULIST_H
#define TITANIUM_WND_CASCADEMENULIST_H

#include "titanium/eqaddr.h"

struct CascadeMenuList_guess {
    // EXTERNAL: TITANIUM 0x004EABC3 CascadeMenuList_guess::OpenSubmenu_guess
    void OpenSubmenu_guess(int value_guess, int* point_guess);
    // EXTERNAL: TITANIUM 0x004EACFA CascadeMenuList_guess::Disable
    void Disable(int value);
    // EXTERNAL: TITANIUM 0x004EAD4A CascadeMenuList_guess::HitTest_guess
    void HitTest_guess(int x_guess, int y_guess);
    // EXTERNAL: TITANIUM 0x004EAE22 CascadeMenuList_guess::Read_guess
    char Read_guess(int value);
    // EXTERNAL: TITANIUM 0x004EB20E CascadeMenuList_guess::Purge_guess
    void Purge_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004EB2B9 CascadeMenuList_guess::Resolve_guess
    int Resolve_guess(void* first_guess, int second_guess);
};
#define pinstCascadeMenuList_guess EQ_GLOBAL(CascadeMenuList_guess*, 0x00991758)

#endif
