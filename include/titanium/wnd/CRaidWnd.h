/* CRaidWnd: window, constructor 0x0054EFB5 (tu_205_RaidWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CRAIDWND_H
#define TITANIUM_WND_CRAIDWND_H

#include "titanium/wnd_views.h"

struct CRaidWnd_guess : CSidlScreenWndVirtuals_guess {
    /*0x15C*/ unsigned char pad_15C[0x290 - 0x15C];

    // EXTERNAL: TITANIUM 0x0054EFB5 CRaidWnd_guess::CRaidWnd_guess
    CRaidWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0054E1D9 CRaidWnd_guess::SetPlayerCount_guess
    void SetPlayerCount_guess(int value);
    // EXTERNAL: TITANIUM 0x0054E2AD CRaidWnd_guess::SetLevelAverage_guess
    void SetLevelAverage_guess(int value);
    // EXTERNAL: TITANIUM 0x0054EB91 CRaidWnd_guess::SetClassColorValue_guess
    void SetClassColorValue_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x0054ED28 CRaidWnd_guess::SetMotd_guess
    void SetMotd_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0054EDD1 CRaidWnd_guess::SetNoteText_guess
    void SetNoteText_guess(const char* name_guess, const char* text_guess);
    // EXTERNAL: TITANIUM 0x0054F8FA CRaidWnd_guess::DumpRoster_guess
    void DumpRoster_guess(const char* fileName);
    // EXTERNAL: TITANIUM 0x0054FEC9 CRaidWnd_guess::Refresh_54FEC9_guess
    void Refresh_54FEC9_guess();
    // EXTERNAL: TITANIUM 0x0055011D CRaidWnd_guess::UpdateThunk_54E316_guess
    void UpdateThunk_54E316_guess();
    // EXTERNAL: TITANIUM 0x00550AAC CRaidWnd_guess::AddPlayer_guess
    void AddPlayer_guess(const char* leader_guess, const char* name_guess, const char* class_guess, const char* level_guess, const char* empty_guess, int key_guess, int classId_guess, unsigned char leaderFlag_guess, const char* group_guess);
    // EXTERNAL: TITANIUM 0x00550FD4 CRaidWnd_guess::RemovePlayerFromList_guess
    void RemovePlayerFromList_guess(const char* name_guess, int group_guess);
    // EXTERNAL: TITANIUM 0x00551123 CRaidWnd_guess::SetMemberFlagsText_guess
    void SetMemberFlagsText_guess(const char* name_guess, int group_guess, bool first_guess, bool second_guess, int unused_guess);
    // EXTERNAL: TITANIUM 0x005511DB CRaidWnd_guess::SetMemberRankText_guess
    void SetMemberRankText_guess(const char* name_guess, const char* leader_guess, int group_guess);
    // EXTERNAL: TITANIUM 0x0055126C CRaidWnd_guess::ChangePosition
    void ChangePosition(const char* name_guess, int group_guess, int key_guess, int classId_guess, unsigned char leaderFlag_guess);
    // EXTERNAL: TITANIUM 0x0055160D CRaidWnd_guess::ChangeRaidGroupLeader
    void ChangeRaidGroupLeader(const char* newLeader, int group, const char* oldLeader);
    // EXTERNAL: TITANIUM 0x00551CBC CRaidWnd_guess::RenamePlayer_guess
    void RenamePlayer_guess(const char* value_guess, const char* name_guess, int group_guess);
    // EXTERNAL: TITANIUM 0x00551DCF CRaidWnd_guess::SetHighlight_guess
    void SetHighlight_guess(const char* leader_guess, int leaderGroup_guess, const char* name_guess, int group_guess);
    // EXTERNAL: TITANIUM 0x00551E5F CRaidWnd_guess::SetPlayerClassColor_guess
    void SetPlayerClassColor_guess(const char* name_guess, int classIndex_guess, int group_guess);
};
#define pinstCRaidWnd_guess EQ_GLOBAL(CRaidWnd_guess*, 0x00850BF0)

#endif
