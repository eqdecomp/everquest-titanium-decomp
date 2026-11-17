/* CTaskTemplateSelectWnd: window, constructor 0x0055D8CA (tu_222_TaskTemplateSelectWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CTASKTEMPLATESELECTWND_H
#define TITANIUM_WND_CTASKTEMPLATESELECTWND_H

#include "titanium/wnd_views.h"

struct CTaskTemplateSelectWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x210 - 0x15C];
    /*0x210*/ int field_210_guess;

    // EXTERNAL: TITANIUM 0x0055D8CA CTaskTemplateSelectWnd_guess::CTaskTemplateSelectWnd_guess
    CTaskTemplateSelectWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0055D0DD CTaskTemplateSelectWnd_guess::RebuildLists_guess
    void RebuildLists_guess();
    // EXTERNAL: TITANIUM 0x0055D1F3 CTaskTemplateSelectWnd_guess::Check_guess
    void Check_guess(void* value);
    // EXTERNAL: TITANIUM 0x0055D222 CTaskTemplateSelectWnd_guess::OnSelect_guess
    void OnSelect_guess(void* data_guess);
    // EXTERNAL: TITANIUM 0x0055D283 CTaskTemplateSelectWnd_guess::ShowTemplate_guess
    void ShowTemplate_guess();
    // EXTERNAL: TITANIUM 0x0055D8BA CTaskTemplateSelectWnd_guess::NotifyAndUpdate_guess
    void NotifyAndUpdate_guess();
};
#define pinstCTaskTemplateSelectWnd_guess EQ_GLOBAL(CTaskTemplateSelectWnd_guess*, 0x0099283C)

#endif
