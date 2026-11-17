/* CTrainWnd: window, constructor 0x0056A4FF (tu_233_TrainWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTRAINWND_H
#define TITANIUM_WND_CTRAINWND_H

#include "titanium/wnd_views.h"

struct CTrainWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x7D4 - 0x15C];

    // EXTERNAL: TITANIUM 0x0056A4FF CTrainWnd_guess::CTrainWnd_guess
    CTrainWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0056B400 CTrainWnd_guess::Post_guess
    void Post_guess(int id, int flag);
    // EXTERNAL: TITANIUM 0x0056B897 CTrainWnd_guess::SetGMData_guess
    void SetGMData_guess(int* ids, unsigned char* flags, int value);
};
#define pinstCTrainWnd_guess EQ_GLOBAL(CTrainWnd_guess*, 0x00850BB0)

#endif
