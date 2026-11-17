/* CGroupSearchFiltersWnd: window, constructor 0x0050876B (tu_162_GroupSearchFiltersWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGROUPSEARCHFILTERSWND_H
#define TITANIUM_WND_CGROUPSEARCHFILTERSWND_H

#include "titanium/wnd_views.h"

struct CGroupSearchFiltersWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x198 - 0x15C];

    // EXTERNAL: TITANIUM 0x0050876B CGroupSearchFiltersWnd_guess::CGroupSearchFiltersWnd_guess
    CGroupSearchFiltersWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x00507E5B CGroupSearchFiltersWnd_guess::IsExclusiveSearch_guess
    unsigned char IsExclusiveSearch_guess();
    // EXTERNAL: TITANIUM 0x00508955 CGroupSearchFiltersWnd_guess::IsFilteredOut_guess
    unsigned char IsFilteredOut_guess(void* value, const char* name);
};
#define pinstCGroupSearchFiltersWnd_guess EQ_GLOBAL(CGroupSearchFiltersWnd_guess*, 0x00850BD4)

#endif
