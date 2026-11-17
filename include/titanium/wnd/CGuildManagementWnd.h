/* CGuildManagementWnd: window, constructor 0x00510FDA (tu_166_GuildManagementWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CGUILDMANAGEMENTWND_H
#define TITANIUM_WND_CGUILDMANAGEMENTWND_H

#include "titanium/wnd_views.h"

struct CGuildManagementWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x40C - 0x15C];

    // EXTERNAL: TITANIUM 0x00510FDA CGuildManagementWnd_guess::CGuildManagementWnd_guess
    CGuildManagementWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0050E5B5 CGuildManagementWnd_guess::SetMOTD_guess
    void SetMOTD_guess(const char* first, const char* second);
    // EXTERNAL: TITANIUM 0x0050E6C2 CGuildManagementWnd_guess::SetPlayerCount_guess
    void SetPlayerCount_guess(int value);
    // EXTERNAL: TITANIUM 0x0050E7A3 CGuildManagementWnd_guess::RenameMember_guess
    void RenameMember_guess(const char* name, const char* value);
    // EXTERNAL: TITANIUM 0x0050EF1B CGuildManagementWnd_guess::DumpList_guess
    void DumpList_guess(char* filename, const char* separator);
    // EXTERNAL: TITANIUM 0x0050F4D2 CGuildManagementWnd_guess::RemoveMember_guess
    void RemoveMember_guess(void* value);
    // EXTERNAL: TITANIUM 0x0050F5CC CGuildManagementWnd_guess::UpdateMemberRow_guess
    void UpdateMemberRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x0050F9D2 CGuildManagementWnd_guess::UpdateNoteRow_guess
    void UpdateNoteRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x0050FB61 CGuildManagementWnd_guess::UpdateTributeRow_guess
    void UpdateTributeRow_guess(int id, int index);
    // EXTERNAL: TITANIUM 0x005101B6 CGuildManagementWnd_guess::SortMembers_guess
    void SortMembers_guess(int sortKey, char descending);
    // EXTERNAL: TITANIUM 0x0051059A CGuildManagementWnd_guess::AddMember_guess
    void AddMember_guess(int* value);
    // EXTERNAL: TITANIUM 0x00510D2F CGuildManagementWnd_guess::Clear_guess
    void Clear_guess();
};
#define pinstCGuildManagementWnd_guess EQ_GLOBAL(CGuildManagementWnd_guess*, 0x00991AAC)

#endif
