// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 25: a hint from compare/tumap.py.
// CRaid, the client's raid state; CRaid_guess is CRaid (its log text names CRaid::AddRaidMember).
// 72 member records of 0x118 bytes at +0x19C (in-use flags at +0x154), leader name +0x5064, MOTD +0x51A4,
// 19 looter names +0x55F4. Requests go out as OP_RaidInvite (0x5891) with a command id; HandleS2CRaidMessage_guess takes
// the server's. OptionalService_guess (0x850BF0) is CRaidWnd (tu_205); 0x850BF4 is probably its looter list.
#include "titanium/types.h"
#include <string.h>

// EXTERNAL: TITANIUM 0x0060E3A3 atol
extern "C" long __cdecl atol(const char* value);
// EXTERNAL: TITANIUM 0x0060F3DC isdigit
extern "C" int __cdecl isdigit(int value);

union StateFlags_guess {
    unsigned char flags_guess;
    int reset_guess;
};

#pragma pack(push, 1)
struct Entry_guess {
    unsigned char occupied_guess;
    unsigned char pad_0001_guess[6];
    int key_guess;
    unsigned char pad_000b_guess[0x118 - 0x0b];
};
#pragma pack(pop)

struct EntryCollection_guess {
    unsigned char pad_0000_guess[0x2a9];
    Entry_guess entries_guess[0x48];
};

struct EntryRecord_guess {
    unsigned char flag_guess;
    unsigned char pad_0001_guess[0x108 - 1];
    int field_0108_guess;
    unsigned char pad_010c_guess[0x10d - 0x10c];
    unsigned char active_guess;
    unsigned char markerA_010e_guess;
    unsigned char markerM_010f_guess;
    unsigned char markerW_0110_guess;
    unsigned char pad_0111_guess[3];
    int key_guess;
};

struct EntryRecordArray_guess {
    unsigned char pad_0000_guess[0x19c];
    EntryRecord_guess records_guess[0x48];
};

#pragma pack(push, 1)
struct EntryStride_guess {
    unsigned char bytes_guess[0x118];
};

struct EntryUpdateView_guess {
    unsigned char pad_0000_guess[0x19c];
    char text_guess[0x40];
    unsigned char pad_01dc_guess[0x21c - 0x1dc];
    char value_guess[0x40];
    unsigned char pad_025c_guess[0x2a4 - 0x25c];
    int groupNumber_02a4_guess;
    unsigned char pad_02a8_guess[0x2a9 - 0x2a8];
    unsigned char active_guess;
    unsigned char pad_02aa_guess[0x2b0 - 0x2aa];
    int key_guess;
};
#pragma pack(pop)

struct EntrySlot_guess {
    unsigned char pad_0000_guess[0x19c];
    EntryRecord_guess record_guess;
};

struct EntrySlotArray_guess {
    EntryRecord_guess slots_guess[0x48];
};

struct OwnerLink_guess {
    unsigned char pad_0000_guess[4];
    int vbaseOffset_0004_guess;
};

struct OwnerRoot_guess {
    unsigned char pad_0000_guess[8];
    OwnerLink_guess* link_guess;
};

struct OwnerValueRecord_guess {
    unsigned char pad_0000_guess[0x44];
    char text_guess[0x40];
    char value_guess[0x40];
};

struct OwnerKeyRecord_guess {
    unsigned char pad_0000_guess[0x44];
    char text_guess[0x40];
    int key_guess;
};

template <class T, int N>
struct CheckedArray_guess {
    T data[N];
    T& operator[](int index) {
        if ((unsigned int)index < (unsigned int)N) {
            return data[index];
        }
        __debugbreak();
        return data[index];
    }
};

struct ServerDataBase_guess {
    virtual void Slot00_guess();
    int field_0004_guess;
};

struct ServerProfile_guess {
    unsigned char pad_0000_guess[0x3c];
    char name_guess[0x40];
};

struct ServerData_guess : ServerDataBase_guess, virtual ServerProfile_guess {
    unsigned char pad_000c_guess[0xbf0 - 0xc];
    CheckedArray_guess<int, 0x40> values_guess;
};

#define g_serverData_guess EQ_GLOBAL(ServerData_guess*, 0x00905D00)

struct LeaderChange_guess {
    unsigned char pad_0000_guess[0x84];
    int leader_guess;
};

struct StatusView_guess;
struct RaidMember_guess;

struct PayloadView_guess {
    unsigned char pad_0000_guess[0x5064];
    char payload_guess[0x40];
};

struct TextSlotsView_guess {
    unsigned char pad_0000_guess[0x55f4];
    char slots_guess[0x13][0x40];
};

struct ContentService_guess {
    // EXTERNAL: TITANIUM 0x0054DBDD ContentService_guess::ClearLooterList_guess
    void ClearLooterList_guess();
    // EXTERNAL: TITANIUM 0x0054DB7C ContentService_guess::AddLooterToList_guess
    void AddLooterToList_guess(const void* value);
};

// EXTERNAL: TITANIUM 0x00574950 CompareRecord_guess
int __cdecl CompareRecord_guess(const char* value, const void* record);

struct DispatchMessage_guess {
    int type_guess;
    unsigned char pad_0004_guess[0x40];
    char text_guess[0x40];
    int value_guess;
    char data_guess[0x400];
};

struct GroupEntry_guess {
    char name_guess[0x40];
    char value_guess[0x40];
    char levelText_guess[8];
    char className_guess[0x80];
    int classId_guess;
    unsigned char pad_010c_guess;
    unsigned char active_guess;
    unsigned char field_010e_guess;
    unsigned char field_010f_guess;
    unsigned char field_0110_guess;
    unsigned char pad_0111_guess[3];
    int key_guess;
};

struct GroupEntryArray_guess {
    unsigned char pad_0000_guess[0x19c];
    GroupEntry_guess entries_guess[0x48];
};

struct OwnerFlag_guess {
    // EXTERNAL: TITANIUM 0x00479EA3 OwnerFlag_guess::IsGroupInvitePending_guess
    char IsGroupInvitePending_guess();
    // EXTERNAL: TITANIUM 0x00479EB0 OwnerFlag_guess::SetGroupInvitePending_guess
    void SetGroupInvitePending_guess(int value);
};

struct EntryRecordText_guess {
    unsigned char pad_0000_guess[0x40];
    char text_guess[0x40];
};

struct CRaid_guess {
    unsigned char pad_0000_guess[0x154];
    unsigned char memberUsed_0154_guess[0x48];
    unsigned char pad_019c_guess[0x505c - 0x19c];
    int leaderSpawnId_505c_guess;
    int memberCount_5060_guess;
    unsigned char pad_5064_guess[0x50a4 - 0x5064];
    int leaderRanks_50a4_guess[0x40];
    unsigned char raidMotd_51a4_guess;
    unsigned char pad_51a5_guess[0x55a4 - 0x51a5];
    unsigned char inviterName_55a4_guess;
    unsigned char pad_55a5_guess[0x55e4 - 0x55a5];
    StateFlags_guess stateFlags_55e4_guess;
    unsigned char invitePending_55e8_guess;
    unsigned char isRaidLeader_55e9_guess;
    unsigned char pad_55ea_guess[2];
    int selectedMember_55ec_guess;
    int lootType_55f0_guess;
    unsigned char pad_55f4_guess[0x5ab4 - 0x55f4];
    int totalMemberLevels_5ab4_guess;
    unsigned char locked_5ab8_guess;

    CRaid_guess();
    char IsInRaid_guess();
    char IsInvitePending_guess();
    void ClearPendingInvite_guess();
    int GetMemberCount_guess();
    int GetMember_guess(int index);
    int FindMemberIndex_guess(const char* value);
    void SetTargetRaidPlayer_guess(const char* value);
    char IsMember_guess(const char* value);
    void CopyData_guess(void* data);
    void CopyPrefix_guess(void* data);
    unsigned char IsLocked_guess();
    unsigned char IsRaidLeader_guess();
    int GetSelectedMember_guess();
    int GetLootType_guess();
    void SetLootTypeResponse_guess(StatusView_guess* status);
    void AddRaidLooter_guess(const char* value);
    void UpdateOptionsWindow_guess();
    char IsLooter_guess(const char* value);
    int FindOpenIndex_guess();
    int FindGroupLeaderIndex_guess(int key);
    void ReportRosterChanges_guess(char* data);
    void SendRaidCommand_guess(int id, const char* name, const char* text, int options);
    void Dispatch6_guess(const char* text, int options);
    void Dispatch7_guess(const char* value);
    void RequestLock_guess();
    void RequestUnlock_guess();
    void SendMotd_guess(const char* value);
    void SendMemberNote_guess(const char* first, const char* second);
    void SetLootType_guess(int state);
    void RemoveRaidLooter_guess(const char* value);
    void SetLocked_guess();
    void SetUnlocked_guess();
    void UpdateAverageLevel_guess();
    char IsPlayerGroupLeader_guess();
    void RenameMember_guess(OwnerValueRecord_guess* owner);
    void SetMemberGroup_guess(OwnerKeyRecord_guess* owner);
    void DispatchEntry_guess(const char* value);
    void InviteToRaid_guess(char* name);
    void RespondToInvite_guess(char state);
    void MakeLeader_guess(char* value);
    void RemoveSelectedOrLeave_guess();
    void RequestLootType_guess(const char* value);
    void RaidSay_guess(const char* value);
    void UpdateClassColor_guess(int classId, int color);
    void UpdateEntryFlag_guess(const char* value, int state);
    void UpdateEntryMode_guess(const char* value, int state);
    void SetRaidLeader_guess(const char* value);
    void UpdateEntryState_guess(const char* value, int state);
    void ResetRaid_guess();
    void RequestAddLooter_guess();
    void RequestRemoveLooter_guess();
    void HandleNewLeader_guess(const char* value, void* data);
    void CopyServerData_guess(ServerData_guess* data);
    void ChangeLeader_guess(LeaderChange_guess* change);
    void AddRaidMember(RaidMember_guess* member);
    void RebuildRaidList_guess();
    void RaidGroupLeaderChange_guess(DispatchMessage_guess* message);
    void HandleCreateInviteRaid_guess(DispatchMessage_guess* message);
    void HandleFullRaid_guess(int data);
    void DeleteRaidMember_guess(DispatchMessage_guess* message);
    void HandleS2CRaidMessage_guess(DispatchMessage_guess* message);
};

struct DataController_guess {
    // EXTERNAL: TITANIUM 0x004B40D1 DataController_guess::SetRaidLeaderRanks_guess
    void SetRaidLeaderRanks_guess(void* owner, void* data);
    // EXTERNAL: TITANIUM 0x004B412F DataController_guess::SetRaidLeaderBlock_guess
    void SetRaidLeaderBlock_guess(void* owner, void* data);
    // EXTERNAL: TITANIUM 0x004B404D DataController_guess::ClearRaidLeaderData_guess
    void ClearRaidLeaderData_guess(void* owner);
};

struct OptionalService_guess {
    // EXTERNAL: TITANIUM 0x0054E2AD OptionalService_guess::SetLevelAverage_guess
    void SetLevelAverage_guess(int value);
    // EXTERNAL: TITANIUM 0x0054FEC9 OptionalService_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0054E1D9 OptionalService_guess::SetEntryCount_guess
    void SetEntryCount_guess(int value);
    // EXTERNAL: TITANIUM 0x00550FD4 OptionalService_guess::RemovePlayerFromList_guess
    void RemovePlayerFromList_guess(const char* text, int key);
    // EXTERNAL: TITANIUM 0x0055011D OptionalService_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x005511DB OptionalService_guess::SetMemberRankText_guess
    void SetMemberRankText_guess(void* entry, const char* text, int key);
    // EXTERNAL: TITANIUM 0x0055160D OptionalService_guess::ChangeRaidGroupLeader
    void ChangeRaidGroupLeader(const char* text, int key, void* entry);
    // EXTERNAL: TITANIUM 0x00551123 OptionalService_guess::UpdateEntryState_guess
    void UpdateEntryState_guess(const char* value, int key, unsigned char field10e, int state,
        unsigned char field110);
    // EXTERNAL: TITANIUM 0x00551123 OptionalService_guess::UpdateEntryStateRaw_guess
    void UpdateEntryStateRaw_guess(const char* value, int key, int state,
        unsigned char field10f, unsigned char field110);
    // EXTERNAL: TITANIUM 0x00551123 OptionalService_guess::UpdateEntryMode_guess
    void UpdateEntryMode_guess(const char* value, int key, unsigned char field10e,
        unsigned char field10f, int state);
    // EXTERNAL: TITANIUM 0x00551DCF OptionalService_guess::ClearEntry_guess
    void ClearEntry_guess(const char* text, int key, const char* previousText, int previousKey);
    // EXTERNAL: TITANIUM 0x0055126C OptionalService_guess::ChangePosition
    void ChangePosition(void* entry, int oldKey, int newKey, int field_02a4,
        unsigned char active);
    // EXTERNAL: TITANIUM 0x00551CBC OptionalService_guess::RenamePlayer_guess
    void RenamePlayer_guess(const char* value, const char* text, int key);
    // EXTERNAL: TITANIUM 0x0054E1D9 OptionalService_guess::SetPlayerCount_guess
    void SetPlayerCount_guess(int value);
    // EXTERNAL: TITANIUM 0x0054ED28 OptionalService_guess::SetMotd_guess
    void SetMotd_guess(const void* text);
    // EXTERNAL: TITANIUM 0x0054FEC9 OptionalService_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0054EDD1 OptionalService_guess::SetNoteText_guess
    void SetNoteText_guess(const char* name, const char* text);
    // EXTERNAL: TITANIUM 0x00550AAC OptionalService_guess::AddPlayer_guess
    void AddPlayer_guess(const char* leader, const char* name, const char* className,
        const char* levelText, const char* empty, int key, int classId,
        unsigned char leaderFlag, const char* group);
    // EXTERNAL: TITANIUM 0x0054EB91 OptionalService_guess::SetClassColorValue_guess
    void SetClassColorValue_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x00551E5F OptionalService_guess::SetPlayerClassColor_guess
    void SetPlayerClassColor_guess(void* member, int colorIndex, int key);
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::Lookup_guess
    char* Lookup_guess(int id, int zero, int type, int enabled);
};

struct MessageService_guess {
    // EXTERNAL: TITANIUM 0x004982C6 MessageService_guess::Show_guess
    void Show_guess(char* message);
    // EXTERNAL: TITANIUM 0x00497C5B MessageService_guess::SendNewText_guess
    void SendNewText_guess(int type, int zero, const char* value, int flags);
};

struct StatusView_guess {
    unsigned char pad_0000_guess[0x84];
    int state_guess;
};

// EXTERNAL: TITANIUM 0x006220E9 ConvertInteger_guess
char* __cdecl ConvertInteger_guess(int value, char* output, int radix);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, int textId, const char* value,
    const char* arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10,
    int arg11);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x00574310 CopyBuffer_guess
void __cdecl CopyBuffer_guess(char* destination, const char* source, unsigned int size);
extern "C" void __cdecl SubmitPayload(void* owner, unsigned int message, void* data, unsigned int size, int flags);

struct LargeRequest_guess {
    int id_guess;
    char first_guess[64];
    char second_guess[68];
    char data_guess[0x400];
};

struct SmallRequest_guess {
    int id_guess;
    char first_guess[64];
    char second_guess[68];
    char data_guess[0x40];
};

#define g_dataController_guess EQ_GLOBAL(DataController_guess*, 0x009859EC)
#define g_dataOwner_guess EQ_GLOBAL(void*, 0x00905D00)
#define pinstCRaidOptionsWnd_guess EQ_GLOBAL(ContentService_guess*, 0x00850BF4)
#define pinstCRaidWnd_guess EQ_GLOBAL(OptionalService_guess*, 0x00850BF0)
#define g_lookupService_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_messageService_guess EQ_GLOBAL(MessageService_guess*, 0x00988DF0)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_payloadOwner_guess EQ_ARRAY(char, 0x00905CA0)
#define g_messageTemplate_guess EQ_GLOBAL(char*, 0x00905CE4)
#define g_ownerState_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_zoneState_guess EQ_GLOBAL(unsigned char, 0x0092384D)
#define g_statusFlag_guess EQ_GLOBAL(int, 0x00923884)
#define g_entryPending_guess EQ_GLOBAL(char, 0x00985808)
#define g_ownerFlag_guess EQ_GLOBAL(OwnerFlag_guess*, 0x00905CE4)
#define g_stateB_guess EQ_GLOBAL(unsigned char, 0x00985845)
#define g_stateC_guess EQ_GLOBAL(unsigned char, 0x00985885)

// State +0x55E4: 1 = no raid, 2 = invite pending (inviter at +0x55A4), 4 = in raid. +0x55E9 = we lead,
// +0x55EC = selected member (-1 none), +0x55F0 = loot type 1-3, +0x5AB4 = level total, +0x5AB8 = locked.
// Member record: name +0, note +0x40, level text +0x80, class name +0x88, class id +0x108, group leader
// +0x10D, three marker flags +0x10E-0x110, group number +0x114.
// FUNCTION: TITANIUM 0x0042FC15
CRaid_guess::CRaid_guess() {
    leaderSpawnId_505c_guess = 0;
    memset(pad_019c_guess, 0, 0x4ec0);
    memset(memberUsed_0154_guess, 0, 0x48);
    memset(pad_5064_guess, 0, 0x40);
    memberCount_5060_guess = 0;
    invitePending_55e8_guess = 0;
    stateFlags_55e4_guess.reset_guess = 1;
    memset(&inviterName_55a4_guess, 0, 0x40);
    selectedMember_55ec_guess = -1;
    isRaidLeader_55e9_guess = 0;
    lootType_55f0_guess = 1;
    memset(pad_55f4_guess, 0, 0x4c0);
    totalMemberLevels_5ab4_guess = 0;
    memset(this, 0, 0x154);
    raidMotd_51a4_guess = 0;
    locked_5ab8_guess = 0;
}

// Whether we are in a raid (state 4).
// FUNCTION: TITANIUM 0x0042FCC2
char CRaid_guess::IsInRaid_guess() {
    unsigned char value = stateFlags_55e4_guess.flags_guess;
    value >>= 2;
    value &= 1;
    return value;
}

// Whether a raid invite is pending (state 2).
// FUNCTION: TITANIUM 0x0042FCCE
char CRaid_guess::IsInvitePending_guess() {
    unsigned char value = stateFlags_55e4_guess.flags_guess;
    value >>= 1;
    value &= 1;
    return value;
}

// Drops a pending invite: back to no raid.
// FUNCTION: TITANIUM 0x0042FCD9
void CRaid_guess::ClearPendingInvite_guess() {
    StateFlags_guess* flags = &stateFlags_55e4_guess;
    if ((flags->flags_guess & 2) != 0) {
        flags->reset_guess = 1;
        invitePending_55e8_guess = 0;
        inviterName_55a4_guess = 0;
    }
}

// Whether the raid is locked; reads +0x5AB8 (the 55b8 in the name is a slip).
// FUNCTION: TITANIUM 0x0042FCF9
unsigned char CRaid_guess::IsLocked_guess() {
    return locked_5ab8_guess;
}

// Whether we lead the raid.
// FUNCTION: TITANIUM 0x0042FD00
unsigned char CRaid_guess::IsRaidLeader_guess() {
    return isRaidLeader_55e9_guess;
}

// The selected member's record, or 0.
// FUNCTION: TITANIUM 0x0042FD07
int CRaid_guess::GetSelectedMember_guess() {
    int index = selectedMember_55ec_guess;
    if (index == -1) {
        return 0;
    }
    return (int)this + index * 0x118 + 0x19c;
}

// Command 11: announces the loot type (string 0x13EC). Types 1-3 pass string ids 0x13ED-0x13EF as decimal
// text, which FormatText_guess probably expands; any other type leaves `number` uninitialised (original).
// FUNCTION: TITANIUM 0x0042FD23
void CRaid_guess::SetLootTypeResponse_guess(StatusView_guess* status) {
    char buffer[512];
    char number[52];
    switch (status->state_guess) {
    case 1:
        ConvertInteger_guess(0x13ed, number, 10);
        break;
    case 2:
        ConvertInteger_guess(0x13ee, number, 10);
        break;
    case 3:
        ConvertInteger_guess(0x13ef, number, 10);
        break;
    }
    FormatText_guess(buffer, 0x13ec, number, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer, 0x111, 1);
}

// Command 33: adds a looter to the list and to the first free of the 19 name slots.
// FUNCTION: TITANIUM 0x0042FDBA
void CRaid_guess::AddRaidLooter_guess(const char* value) {
    pinstCRaidOptionsWnd_guess->AddLooterToList_guess(value);
    int index = 0;
    char* slot = ((TextSlotsView_guess*)this)->slots_guess[0];
    do {
        if (*slot == 0) {
            CopyText_guess(((TextSlotsView_guess*)this)->slots_guess[index], value);
            return;
        }
        ++index;
        slot += 0x40;
    } while (index < 0x13);
}

// Command 17: the raid is locked (string 0x22A6). Busy is a misname for locked.
// FUNCTION: TITANIUM 0x0042FDFE
void CRaid_guess::SetLocked_guess() {
    locked_5ab8_guess = 1;
    if (pinstCRaidWnd_guess != 0) {
        pinstCRaidWnd_guess->Refresh_guess();
    }
    char* message = g_lookupService_guess->Lookup_guess(0x22a6, 0, 0xd, 1);
    g_messageService_guess->Show_guess(message);
}

// Command 18: the raid is unlocked (string 0x22A7).
// FUNCTION: TITANIUM 0x0042FE37
void CRaid_guess::SetUnlocked_guess() {
    locked_5ab8_guess = 0;
    if (pinstCRaidWnd_guess != 0) {
        pinstCRaidWnd_guess->Refresh_guess();
    }
    char* message = g_lookupService_guess->Lookup_guess(0x22a7, 0, 0xd, 1);
    g_messageService_guess->Show_guess(message);
}

// Sends the raid MOTD (command 0x23, up to 1024 bytes).
// FUNCTION: TITANIUM 0x0042FE70
void CRaid_guess::SendMotd_guess(const char* value) {
    LargeRequest_guess request;
    memset(&request, 0, sizeof(request));
    CopyText_guess(request.first_guess, g_messageTemplate_guess + 0x120);
    CopyText_guess(request.second_guess, g_messageTemplate_guess + 0x120);
    CopyBuffer_guess(request.data_guess, value, 0x400);
    request.id_guess = 0x23;
    SubmitPayload(g_payloadOwner_guess, 0x5891, &request, sizeof(request), 1);
}

// Sends the note for member `first` (command 0x24, 64 bytes).
// FUNCTION: TITANIUM 0x0042FF0B
void CRaid_guess::SendMemberNote_guess(const char* first, const char* second) {
    SmallRequest_guess request;
    memset(&request, 0, sizeof(request));
    CopyText_guess(request.first_guess, g_messageTemplate_guess + 0x120);
    CopyText_guess(request.second_guess, first);
    CopyBuffer_guess(request.data_guess, second, 0x40);
    request.id_guess = 0x24;
    SubmitPayload(g_payloadOwner_guess, 0x5891, &request, sizeof(request), 1);
}

// The loot type.
// FUNCTION: TITANIUM 0x0042FF8E
int CRaid_guess::GetLootType_guess() {
    return lootType_55f0_guess;
}

// Raid say (RaidSay_guess is a misname): echoes the line (string 0x13F5) and sends it on chat channel
// 15, the raid channel. 0x13F4 when not in a raid; nothing while 0x923798, 0x92384D or 0x923884 is set.
// FUNCTION: TITANIUM 0x0042FF95
void CRaid_guess::RaidSay_guess(const char* value) {
    char buffer[2112];
    if ((stateFlags_55e4_guess.flags_guess & 4) == 0) {
        char* message = g_lookupService_guess->Lookup_guess(0x13f4, 0, 0x147, 1);
        g_messageService_guess->Show_guess(message);
    } else if (g_ownerState_guess == 0 && g_zoneState_guess == 0 && g_statusFlag_guess == 0) {
        FormatText_guess(buffer, 0x13f5, value, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0x147, 1);
        g_messageService_guess->SendNewText_guess(0xf, 0, value, 0);
    }
}

// Re-adds every member to the raid window, labelled group leader or raid leader, with one marker string
// per flag +0x10E-0x110.
// FUNCTION: TITANIUM 0x00430048
void CRaid_guess::RebuildRaidList_guess() {
    char leader[0x80];
    int index;
    leader[0] = 0;
    index = 0;
    char* entry = (char*)&((EntryRecordArray_guess*)this)->records_guess[0].markerM_010f_guess;
    do {
        if (memberUsed_0154_guess[index] == 1) {
            if ((unsigned char)entry[-2] != 0) {
                CopyText_guess(leader, "Group Leader");
            }
            if (CompareRecord_guess(entry - 0x10f, ((PayloadView_guess*)this)->payload_guess) == 0) {
                CopyText_guess(leader, "Raid Leader");
            }
            CXStr str(g_emptyString_guess);
            if (entry[-1] != 0) {
                str += EQ_ARRAY(char, 0x00641BA8);
            }
            if (entry[0] != 0) {
                str += EQ_ARRAY(char, 0x00641BA4);
            }
            if (entry[1] != 0) {
                str += EQ_ARRAY(char, 0x00641BA0);
            }
            pinstCRaidWnd_guess->AddPlayer_guess(leader, entry - 0x10f, entry - 0x87,
                entry - 0x8f, str, *(int*)(entry + 5), *(int*)(entry - 7),
                (unsigned char)entry[-2], entry - 0xcf);
            leader[0] = 0;
        }
        ++index;
        entry += 0x118;
    } while (index < 0x48);
    pinstCRaidWnd_guess->SetPlayerCount_guess(memberCount_5060_guess);
    pinstCRaidWnd_guess->SetMotd_guess(&raidMotd_51a4_guess);
}

// Sets the colour of class row `row_guess` and recolours that class's members. The rows are alphabetical
// (Bard, Beastlord, Cleric ... Warrior, Wizard, then Berserker); the switch turns a row into the EQ class
// id (1 Warrior ... 16 Berserker), so `row_guess` is really the row and `classId` the class (misnamed).
// FUNCTION: TITANIUM 0x004301E4
void CRaid_guess::UpdateClassColor_guess(int row_guess, int color) {
    int classId = 0;
    switch (row_guess) {
    case 0:
        classId = 8;
        break;
    case 1:
        classId = 0xf;
        break;
    case 2:
        classId = 2;
        break;
    case 3:
        classId = 6;
        break;
    case 4:
        classId = 0xe;
        break;
    case 5:
        classId = 0xd;
        break;
    case 6:
        classId = 7;
        break;
    case 7:
        classId = 0xb;
        break;
    case 8:
        classId = 3;
        break;
    case 9:
        classId = 4;
        break;
    case 10:
        classId = 9;
        break;
    case 11:
        classId = 5;
        break;
    case 12:
        classId = 10;
        break;
    case 13:
        classId = 1;
        break;
    case 14:
        classId = 12;
        break;
    case 15:
        classId = 0x10;
        break;
    }
    pinstCRaidWnd_guess->SetClassColorValue_guess(row_guess, color);
    int index = 0;
    EntryStride_guess* entry = (EntryStride_guess*)this;
    do {
        EntryUpdateView_guess* view = (EntryUpdateView_guess*)entry;
        if (memberUsed_0154_guess[index] == 1 && view->groupNumber_02a4_guess == classId) {
            pinstCRaidWnd_guess->SetPlayerClassColor_guess(view->text_guess, classId,
                view->key_guess);
        }
        ++index;
        ++entry;
    } while (index < 0x48);
}

// Member count.
// FUNCTION: TITANIUM 0x004302D2
int CRaid_guess::GetMemberCount_guess() {
    return memberCount_5060_guess;
}

// Member record `index` (0-71), or 0 when the slot is free.
// FUNCTION: TITANIUM 0x004302D9
int CRaid_guess::GetMember_guess(int index) {
    if (index < 0 || index >= 0x48 || memberUsed_0154_guess[index] == 0) {
        return 0;
    }
    return (int)this + index * 0x118 + 0x19c;
}

// Stores the 64 raid leadership ability ranks (+0x50A4) and copies them into the character's raid
// leader block (0x004B40D1); used when the player becomes raid leader.
// FUNCTION: TITANIUM 0x00430304
void CRaid_guess::CopyData_guess(void* data) {
    memcpy(leaderRanks_50a4_guess, data, 0x100);
    if (g_dataController_guess != 0) {
        g_dataController_guess->SetRaidLeaderRanks_guess(g_dataOwner_guess, data);
    }
}

// Stores the raid's leadership block (0x154 bytes at +0: 64 ranks and the role ids) and copies it into
// the character's raid leader block (0x004B412F); the full raid update calls it.
// FUNCTION: TITANIUM 0x00430338
void CRaid_guess::CopyPrefix_guess(void* data) {
    memcpy(this, data, 0x154);
    if (g_dataController_guess != 0) {
        g_dataController_guess->SetRaidLeaderBlock_guess(g_dataOwner_guess, data);
    }
}

// Member index by name, -1 if not in the raid.
// FUNCTION: TITANIUM 0x00430366
int CRaid_guess::FindMemberIndex_guess(const char* value) {
    if (memberCount_5060_guess > 0) {
        int index = 0;
        EntryRecord_guess* entry = ((EntryRecordArray_guess*)this)->records_guess;
        do {
            if (entry->flag_guess != 0 && CompareRecord_guess(value, entry) == 0) {
                return index;
            }
            ++index;
            ++entry;
        } while (index < 0x48);
    }
    return -1;
}

// True when the named character is in the raid (0x00430366).
// FUNCTION: TITANIUM 0x004303A6
char CRaid_guess::IsMember_guess(const char* value) {
    return FindMemberIndex_guess(value) != -1;
}

// First free member slot, -1 when all 72 are taken.
// FUNCTION: TITANIUM 0x004303B8
int CRaid_guess::FindOpenIndex_guess() {
    int index = 0;
    do {
        if (memberUsed_0154_guess[index] == 0) {
            return index;
        }
        ++index;
    } while (index < 0x48);
    return -1;
}

// The leader of group `key`: the member in that group with +0x10D set; -1 if none.
// FUNCTION: TITANIUM 0x004303CE
int CRaid_guess::FindGroupLeaderIndex_guess(int key) {
    int index = 0;
    Entry_guess* entry = ((EntryCollection_guess*)this)->entries_guess;
    do {
        if (entry->key_guess == key && entry->occupied_guess != 0) {
            return index;
        }
        ++index;
        ++entry;
    } while (index < 0x48);
    return -1;
}

// EXTERNAL: TITANIUM 0x00433D68 ReadBigEndianUInt32_guess
int __cdecl ReadBigEndianUInt32_guess(const char* data);
extern "C" void __cdecl ClearPayload(void* destination, int value, unsigned int size);
extern "C" void __cdecl CopyPayloadText(char* destination, const char* source);

// Called with a full raid update while we are already in the raid: reports a new leader (0x13CE), each
// name the update adds (0x13C3) and each member it drops (0x13C7). Same layout as HandleFullRaid_guess.
// FUNCTION: TITANIUM 0x004303F6
// @early-stop: budget, structural ndiff=68
void CRaid_guess::ReportRosterChanges_guess(char* data) {
    char found[0x48];
    char name[0x40];
    char message[0x200];
    char names[0x48][0x40];
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0) {
        memset(found, 0, 0x48);
        char* body = data + 4;
        body = body + strlen(body) + 1;
        if (g_dataController_guess != 0) {
            g_dataController_guess->SetRaidLeaderBlock_guess(g_dataOwner_guess, body);
        }
        int count = ReadBigEndianUInt32_guess(body + 0x158);
        char* record = body + 0x15c;
        if (count > 0) {
            char* out = names[0];
            int left = count;
            do {
                CopyText_guess(out, record + 4);
                int nameLen = strlen(record + 4);
                char* value = record + nameLen + 5;
                int valueLen = strlen(value);
                out += 0x40;
                --left;
                record = value + valueLen + 8;
            } while (left != 0);
        }
        int skip = ReadBigEndianUInt32_guess(record + 4);
        record += 8;
        if (skip > 0) {
            do {
                record += strlen(record) + 1;
                --skip;
            } while (skip != 0);
        }
        int len = strlen(record);
        CopyText_guess(name, record + len + 1);
        char* payload = ((PayloadView_guess*)this)->payload_guess;
        if (CompareRecord_guess(payload, name) != 0) {
            FormatText_guess(message, 0x13ce, payload, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message, 0x111, 1);
        }
        if (count > 0) {
            char* in = names[0];
            int left = count;
            do {
                int index = FindMemberIndex_guess(in);
                if (index == -1) {
                    FormatText_guess(message, 0x13c3, in, 0, 0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message, 0x111, 1);
                } else {
                    found[index] = 1;
                }
                in += 0x40;
                --left;
            } while (left != 0);
        }
        EntryRecord_guess* entry = ((EntryRecordArray_guess*)this)->records_guess;
        for (int i = 0; i < 0x48; ++i) {
            if (memberUsed_0154_guess[i] == 1 && found[i] == 0) {
                FormatText_guess(message, 0x13c7, (const char*)entry, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message, 0x111, 1);
            }
            ++entry;
        }
    }
}

struct Payload_guess {
    int id_guess;
    char name_guess[64];
    char text_guess[64];
    int options_guess;
};

// Sends raid command `id` (OP_RaidInvite, 0x88 bytes: id, two names, a parameter). Ids sent here: 1/4
// accept an invite, 5 leave or remove, 6/7 member moves (probably groups), 8/9 lock/unlock, 0x1E new leader,
// 0x1F decline, 0x20 loot type, 0x21/0x22 add/remove a looter.
// FUNCTION: TITANIUM 0x0043060E
void CRaid_guess::SendRaidCommand_guess(int id, const char* name, const char* text, int options) {
    Payload_guess payload;
    ClearPayload(&payload, 0, sizeof(payload));
    CopyPayloadText(payload.name_guess, name);
    CopyPayloadText(payload.text_guess, text);
    payload.id_guess = id;
    payload.options_guess = options;
    SubmitPayload(g_payloadOwner_guess, 0x5891, &payload, 0x88, 1);
}

// Refills the looter list for the loot type: the leader always, type 2 adds the group leaders, type 3 the
// named looters.
// FUNCTION: TITANIUM 0x00430680
void CRaid_guess::UpdateOptionsWindow_guess() {
    pinstCRaidOptionsWnd_guess->ClearLooterList_guess();
    char* payload = ((PayloadView_guess*)this)->payload_guess;
    if (*payload != 0) {
        pinstCRaidOptionsWnd_guess->AddLooterToList_guess(payload);
    }

    switch (lootType_55f0_guess) {
    case 3: {
        int count = 0x13;
        char* slot = ((TextSlotsView_guess*)this)->slots_guess[0];
        do {
            if (*slot != 0) {
                pinstCRaidOptionsWnd_guess->AddLooterToList_guess(slot);
            }
            slot += 0x40;
            --count;
        } while (count != 0);
        break;
    }
    case 2: {
        int index = 0;
        EntryRecord_guess* record = ((EntryRecordArray_guess*)this)->records_guess;
        do {
            if (record->active_guess != 0 && memberUsed_0154_guess[index] != 0 &&
                CompareRecord_guess(payload, record) != 0) {
                pinstCRaidOptionsWnd_guess->AddLooterToList_guess(record);
            }
            ++index;
            ++record;
        } while (index < 0x48);
        break;
    }
    }
}

// Whether `value` is a named looter.
// FUNCTION: TITANIUM 0x0043071C
char CRaid_guess::IsLooter_guess(const char* value) {
    int index = 0;
    char* slot = ((TextSlotsView_guess*)this)->slots_guess[0];
    while (index < 0x13) {
        if (*slot != 0 && CompareRecord_guess(value, slot) == 0) {
            return 1;
        }
        ++index;
        slot += 0x40;
    }
    return 0;
}

// Shows the raid's average level.
// FUNCTION: TITANIUM 0x0043074F
void CRaid_guess::UpdateAverageLevel_guess() {
    if (pinstCRaidWnd_guess != 0) {
        int value = 0;
        int count = memberCount_5060_guess;
        if (count > 0) {
            value = totalMemberLevels_5ab4_guess / count;
        }
        pinstCRaidWnd_guess->SetLevelAverage_guess(value);
    }
}

// Whether the player is a group leader. No -1 check: if the player is missing it reads the record before
// slot 0.
// FUNCTION: TITANIUM 0x0043077B
char CRaid_guess::IsPlayerGroupLeader_guess() {
    OwnerRoot_guess* owner = (OwnerRoot_guess*)g_dataOwner_guess;
    const char* value = (const char*)owner + owner->link_guess->vbaseOffset_0004_guess + 0x44;
    int index = FindMemberIndex_guess(value);
    return ((EntryRecordArray_guess*)this)->records_guess[index].active_guess;
}

// EXTERNAL: TITANIUM 0x0046AF19 do_target_guess
void __cdecl do_target_guess(int zero, char* text);

// Selects member `value` in the raid window; 0 clears the selection.
// FUNCTION: TITANIUM 0x004307A4
void CRaid_guess::SetTargetRaidPlayer_guess(const char* value) {
    if (value == 0) {
        if (selectedMember_55ec_guess != -1) {
            EntryUpdateView_guess* entry =
                (EntryUpdateView_guess*)((EntryStride_guess*)this + selectedMember_55ec_guess);
            pinstCRaidWnd_guess->ClearEntry_guess(0, -1, entry->text_guess, entry->key_guess);
        }
        selectedMember_55ec_guess = -1;
    } else {
        int index = FindMemberIndex_guess(value);
        if (index != -1) {
            EntryUpdateView_guess* rows = (EntryUpdateView_guess*)this;
            if (((EntryUpdateView_guess*)((EntryStride_guess*)rows + index))->text_guess[0] != 0) {
                if (selectedMember_55ec_guess != -1) {
                    pinstCRaidWnd_guess->ClearEntry_guess(value,
                        ((EntryUpdateView_guess*)((EntryStride_guess*)rows + index))->key_guess,
                        ((EntryUpdateView_guess*)((EntryStride_guess*)rows + selectedMember_55ec_guess))->text_guess,
                        ((EntryUpdateView_guess*)((EntryStride_guess*)rows + selectedMember_55ec_guess))->key_guess);
                } else {
                    pinstCRaidWnd_guess->ClearEntry_guess(value,
                        ((EntryUpdateView_guess*)((EntryStride_guess*)rows + index))->key_guess, 0, -1);
                }
                selectedMember_55ec_guess = index;
                do_target_guess(0,
                    ((EntryUpdateView_guess*)((EntryStride_guess*)rows + index))->text_guess);
            }
        }
    }
}

struct RaidMember_guess {
    unsigned char pad_0000_guess[0x44];
    char name_guess[0x40];
    int key_guess;
    unsigned char classId_guess;
    unsigned char level_guess;
    unsigned char leader_guess;
};

#pragma pack(push, 1)
struct RaidEntryView_guess {
    unsigned char pad_0000_guess[0x19c];
    char name_guess[0x40];
    char group_guess[0x40];
    char levelText_guess[8];
    char className_guess[0x40];
    unsigned char pad_0264_guess[0x40];
    int classId_guess;
    unsigned char pad_02a8_guess[1];
    unsigned char leader_guess;
    unsigned char pad_02aa_guess[6];
    int key_guess;
};
#pragma pack(pop)

struct RaidNamingService_guess {
    // EXTERNAL: TITANIUM 0x00419631 RaidNamingService_guess::KunarkClass_guess
    char* KunarkClass_guess(int classId, int level, int textId, int enabled);
};

struct OwnerDataContainer_guess {
    unsigned char pad_0000_guess[0xc280];
    RaidNamingService_guess naming_guess;
};

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* message, ...);

// Command 0: a member joined. Fills a free slot, adds the level to the total and announces the name
// (0x13C3).
// FUNCTION: TITANIUM 0x0043085D
void CRaid_guess::AddRaidMember(RaidMember_guess* member) {
    char text[512];
    char leader[100];
    if (memberCount_5060_guess != 0x48) {
        int index = FindOpenIndex_guess();
        if (index != -1) {
            CopyText_guess(
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->name_guess,
                member->name_guess);
            ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->leader_guess =
                member->leader_guess;
            ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->key_guess =
                member->key_guess;
            ++memberCount_5060_guess;
            memberUsed_0154_guess[index] = 1;
            if (((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->leader_guess != 0) {
                CopyText_guess(leader, "Group Leader");
            } else {
                leader[0] = 0;
            }
            char* className =
                ((OwnerDataContainer_guess*)g_dataOwner_guess)->naming_guess
                    .KunarkClass_guess(member->classId_guess, member->level_guess, 0x18c, 1);
            CopyText_guess(
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->className_guess,
                className);
            ConvertInteger_guess(member->level_guess,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->levelText_guess,
                10);
            ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->classId_guess =
                member->classId_guess;
            totalMemberLevels_5ab4_guess += member->level_guess;
            UpdateAverageLevel_guess();
            pinstCRaidWnd_guess->AddPlayer_guess(leader, member->name_guess,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->className_guess,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->levelText_guess,
                g_emptyString_guess, member->key_guess, member->classId_guess,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->leader_guess,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->group_guess);
            pinstCRaidWnd_guess->SetPlayerCount_guess(memberCount_5060_guess);
            FormatText_guess(text, 0x13c3,
                ((RaidEntryView_guess*)(((EntryStride_guess*)this) + index))->name_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(text, 0x111, 1);
        } else {
            Log_guess("CRaid::AddRaidMember - FindOpenIndex return -1");
        }
    }
}

// Command 2: member `text` is renamed `value` (0x13CC), the leader name too if it was them.
// FUNCTION: TITANIUM 0x00430A34
void CRaid_guess::RenameMember_guess(OwnerValueRecord_guess* owner) {
    char buffer[512];
    int index = FindMemberIndex_guess(owner->text_guess);
    if (index != -1) {
        CopyText_guess(
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->text_guess,
            owner->value_guess);
        FormatText_guess(buffer, 0x13cc, owner->text_guess, owner->value_guess,
            0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0x111, 1);
        if (__stricmp((char*)this + 0x5064, owner->text_guess) == 0) {
            CopyText_guess((char*)this + 0x5064, owner->value_guess);
        }
        pinstCRaidWnd_guess->RenamePlayer_guess(owner->value_guess, owner->text_guess,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->key_guess);
    }
}

// Command 3: moves member `text` to group `key`.
// FUNCTION: TITANIUM 0x00430AFA
void CRaid_guess::SetMemberGroup_guess(OwnerKeyRecord_guess* owner) {
    int index = FindMemberIndex_guess(owner->text_guess);
    if (index != -1) {
        pinstCRaidWnd_guess->ChangePosition(
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->text_guess,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->key_guess,
            owner->key_guess,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->groupNumber_02a4_guess,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->active_guess);
        ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + index))->key_guess =
            owner->key_guess;
    }
}

// Command 13: member `text` leads group `value`; the group's old leader loses the label unless they lead
// the raid.
// FUNCTION: TITANIUM 0x00430B56
void CRaid_guess::RaidGroupLeaderChange_guess(DispatchMessage_guess* message) {
    void* entry;
    int value = message->value_guess;
    const char* text = message->text_guess;
    int index = FindMemberIndex_guess(text);
    entry = 0;
    if (index != -1) {
        int slot = FindGroupLeaderIndex_guess(value);
        if (slot != -1) {
            entry = &((EntryRecordArray_guess*)this)->records_guess[slot];
        }
        ((EntryCollection_guess*)this)->entries_guess[index].occupied_guess = 1;
        pinstCRaidWnd_guess->ChangeRaidGroupLeader(text, value, entry);
        int leader = FindMemberIndex_guess((const char*)pad_5064_guess);
        if (slot != -1) {
            EntryUpdateView_guess* view = (EntryUpdateView_guess*)(((EntryStride_guess*)this) + slot);
            view->active_guess = 0;
            if (leader != slot) {
                pinstCRaidWnd_guess->SetMemberRankText_guess(view->text_guess, g_emptyString_guess, value);
            }
        }
        if (leader != index) {
            pinstCRaidWnd_guess->SetMemberRankText_guess(
                &((EntryRecordArray_guess*)this)->records_guess[index], "Group Leader", value);
        }
    }
}

// Command 16: clears member `value`'s label in the raid window.
// FUNCTION: TITANIUM 0x00430CAC
void CRaid_guess::DispatchEntry_guess(const char* value) {
    int index = FindMemberIndex_guess(value);
    if (index != -1) {
        EntryRecord_guess* base = ((EntrySlotArray_guess*)this)->slots_guess + index;
        EntrySlot_guess* slot = (EntrySlot_guess*)base;
        pinstCRaidWnd_guess->SetMemberRankText_guess(&slot->record_guess,
            g_emptyString_guess, slot->record_guess.key_guess);
    }
}

struct ActorView_guess {
    unsigned char pad_0000_guess[0x120];
    char name_guess[0x40];
    unsigned char pad_0160_guess[0x244 - 0x160];
    unsigned char field_0244_guess;
};

struct TellRequest_guess {
    int id_guess;
    char first_guess[64];
    char second_guess[68];
};

// EXTERNAL: TITANIUM 0x00574460 CompareName_guess
int __cdecl CompareName_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0047994F NotOnSameDeity_guess
int __stdcall NotOnSameDeity_guess(void* target, int zero);

#define g_selfActor_guess EQ_GLOBAL(ActorView_guess*, 0x00905CE4)
#define g_targetActor_guess EQ_GLOBAL(ActorView_guess*, 0x00905D04)
#define g_gameState_guess EQ_GLOBAL(int, 0x00900478)

// Raid invite (InviteToRaid_guess is a misname): invites `name`, or the target when no name is given. Command 3
// starts a raid, 0 invites into ours. Refused with: an invite pending, not the leader (0x13D1), full
// (0x13B8), self (0x13D4), no target (0x13D2), an NPC (0x13D3, target +0x244), a check that runs only in
// game state 4 (0x18B), already in the raid (0x13D5), in our group (0x2FF0). Echoes 0x13C8.
// FUNCTION: TITANIUM 0x00430CE5
// @early-stop: budget, structural ndiff=25
void CRaid_guess::InviteToRaid_guess(char* name) {
    char buffer[512];
    TellRequest_guess request;
    memset(&request, 0, sizeof(request));
    if ((stateFlags_55e4_guess.reset_guess & 2) != 0) {
        return;
    }
    if ((stateFlags_55e4_guess.reset_guess & 4) != 0 &&
        CompareRecord_guess(((PayloadView_guess*)this)->payload_guess,
            ((OwnerValueRecord_guess*)((unsigned int)g_dataOwner_guess +
                ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess))->text_guess) != 0) {
        ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d1, 0));
        return;
    }
    if (memberCount_5060_guess >= 0x48) {
        ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13b8, 0));
        return;
    }
    if (name != 0 && *name != 0) {
        if (__stricmp(g_selfActor_guess->name_guess, name) == 0) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d4, 0));
            return;
        }
        // Always true here (tested just above), so the else is dead.
        if (*name != 0) {
            CopyText_guess(request.first_guess, name);
        } else {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d2, 0));
            return;
        }
    } else {
        if (g_targetActor_guess == 0) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d2, 0));
            return;
        }
        if (g_targetActor_guess->field_0244_guess != 0) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d3, 0));
            return;
        }
        if (g_targetActor_guess == g_selfActor_guess) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d4, 0));
            return;
        }
        if (g_gameState_guess == 4 && NotOnSameDeity_guess(g_targetActor_guess, 0) != 0) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x18b, 0));
            return;
        }
        if (FindMemberIndex_guess(g_targetActor_guess->name_guess) != -1) {
            ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x13d5, 0));
            return;
        }
        char* slot = EQ_ARRAY(char, 0x0090424D);
        do {
            if (*slot != 0 && CompareName_guess(g_targetActor_guess->name_guess, slot) == 0) {
                ((CEverQuest*)pEverQuest)->dsp_chat(pStringTable->getString(0x2ff0, 0));
                return;
            }
            slot += 0x40;
        // The other five group members' names, 0x40 apart from 0x90424D.
        } while (slot < EQ_ARRAY(char, 0x0090438D));
        name = g_targetActor_guess->name_guess;
        CopyText_guess(request.first_guess, name);
    }
    CopyText_guess(request.second_guess, g_selfActor_guess->name_guess);
    request.id_guess = 3;
    if ((stateFlags_55e4_guess.flags_guess & 1) == 0) {
        request.id_guess = 0;
    }
    SubmitPayload(EQ_ARRAY(char, 0x00905CA0), 0x5891, &request, sizeof(request), 1);
    FormatText_guess(buffer, 0x13c8, request.first_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    ((CEverQuest*)pEverQuest)->dsp_chat(buffer);
}

#undef g_selfActor_guess
#undef g_targetActor_guess
#undef g_gameState_guess

// Answers the pending invite: `state` != 0 accepts (command 1, or 4 for a type-22 invite,
// string 0x13D7); otherwise declines (command 0x1F with reason 0x13D9, string 0x13D8).
// FUNCTION: TITANIUM 0x00430F03
void CRaid_guess::RespondToInvite_guess(char state) {
    char buffer[512];
    if ((stateFlags_55e4_guess.flags_guess & 2) != 0) {
        char* destination_guess = (char*)&inviterName_55a4_guess;
        if (state != 0) {
            FormatText_guess(buffer, 0x13d7, destination_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer);
            int request_guess = 1;
            if (invitePending_55e8_guess != 0) {
                request_guess = 4;
                invitePending_55e8_guess = 0;
            }
            const char* ownerText_guess = (const char*)g_dataOwner_guess +
                ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44;
            SendRaidCommand_guess(request_guess, destination_guess, ownerText_guess, 0);
        } else {
            FormatText_guess(buffer, 0x13d8, destination_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer);
            ClearPendingInvite_guess();
            const char* ownerText_guess = (const char*)g_dataOwner_guess +
                ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44;
            SendRaidCommand_guess(0x1f, destination_guess, ownerText_guess, 0x13d9);
        }
        memset(destination_guess, 0, 0x40);
    }
}

// Leader only: hands the raid to `value`, or to the selected member when `value` is 0 (command 0x1E).
// String 0x13DA when `value` is not in the raid.
// FUNCTION: TITANIUM 0x00430FEA
void CRaid_guess::MakeLeader_guess(char* value) {
    char buffer[512];
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0 && isRaidLeader_55e9_guess != 0) {
        if (value == 0) {
            if (selectedMember_55ec_guess < 0) {
                return;
            }
            char* text_guess = ((EntryUpdateView_guess*)(((EntryStride_guess*)this) +
                selectedMember_55ec_guess))->text_guess;
            if (text_guess[0] == 0) {
                return;
            }
            SendRaidCommand_guess(0x1e,
                (const char*)g_dataOwner_guess +
                    ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44,
                text_guess, 0);
        } else if (IsMember_guess(value) != 0) {
            SendRaidCommand_guess(0x1e,
                (const char*)g_dataOwner_guess +
                    ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44,
                value, 0);
        } else {
            FormatText_guess(buffer, 0x13da, value, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer);
        }
    }
}

// Command 34: removes looter `value`.
// FUNCTION: TITANIUM 0x00430C6F
void CRaid_guess::RemoveRaidLooter_guess(const char* value) {
    char* slot = ((TextSlotsView_guess*)this)->slots_guess[0];
    int count = 0x13;
    do {
        if (CompareRecord_guess(slot, value) == 0) {
            memset(slot, 0, 0x40);
        }
        slot += 0x40;
        --count;
    } while (count != 0);
    UpdateOptionsWindow_guess();
}

// Command 32: sets the loot type; types 1 and 2 drop the named looters.
// FUNCTION: TITANIUM 0x00430C37
void CRaid_guess::SetLootType_guess(int state) {
    lootType_55f0_guess = state;
    if (state == 1 || state == 2) {
        memset(((TextSlotsView_guess*)this)->slots_guess, 0, 0x4c0);
    }
    UpdateOptionsWindow_guess();
}

// Command 5: the leader removes the selected member; anyone else, or a leader with no selection, leaves.
// FUNCTION: TITANIUM 0x004310A3
// @early-stop: unknown, diff ndiff=2
void CRaid_guess::RemoveSelectedOrLeave_guess() {
    if (isRaidLeader_55e9_guess != 0 && selectedMember_55ec_guess >= 0 &&
        ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + selectedMember_55ec_guess))->text_guess[0] != 0) {
        SendRaidCommand_guess(5,
            (const char*)g_dataOwner_guess +
                ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + selectedMember_55ec_guess))->text_guess, 0);
        pinstCRaidWnd_guess->ClearEntry_guess(
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + selectedMember_55ec_guess))->text_guess,
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + selectedMember_55ec_guess))->key_guess,
            0, -1);
        selectedMember_55ec_guess = -1;
    } else {
        const char* ownerText_guess = (const char*)g_dataOwner_guess +
            ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44;
        SendRaidCommand_guess(5, ownerText_guess, ownerText_guess, 0);
    }
}

// Leader only: sets the loot type from a one-digit string, 1-3 (command 0x20); 0x13E6 otherwise.
// FUNCTION: TITANIUM 0x00431136
void CRaid_guess::RequestLootType_guess(const char* value) {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0) {
        if (isRaidLeader_55e9_guess != 0 && strlen(value) == 1 && isdigit(*value) != 0) {
            int mode_guess = (int)atol(value);
            if (mode_guess >= 1 && mode_guess <= 3 && mode_guess != lootType_55f0_guess) {
                lootType_55f0_guess = mode_guess;
                const char* text_guess = (const char*)g_dataOwner_guess +
                    ((OwnerRoot_guess*)g_dataOwner_guess)->link_guess->vbaseOffset_0004_guess + 0x44;
                SendRaidCommand_guess(0x20, text_guess, text_guess, mode_guess);
            }
        } else {
            char* message_guess = pStringTable->getString(0x13e6, 0);
            pEverQuest->dsp_chat(message_guess);
        }
    }
}

// Leader, loot type 3: adds the selected member as a looter (command 0x21); 0x13E7 otherwise.
// FUNCTION: TITANIUM 0x004311CC
// @early-stop: budget, structural ndiff=16
void CRaid_guess::RequestAddLooter_guess() {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0) {
        if (isRaidLeader_55e9_guess != 0 && lootType_55f0_guess == 3 && selectedMember_55ec_guess >= 0 &&
            ((EntryRecordArray_guess*)this)->records_guess[selectedMember_55ec_guess].flag_guess != 0) {
            if (!IsLooter_guess(
                    (const char*)&((EntryRecordArray_guess*)this)->records_guess[selectedMember_55ec_guess])) {
                SendRaidCommand_guess(0x21, (const char*)pad_5064_guess,
                    (const char*)&((EntryRecordArray_guess*)this)->records_guess[selectedMember_55ec_guess], 0);
            }
        } else {
            char* message = pStringTable->getString(0x13e7, 0);
            pEverQuest->dsp_chat(message);
        }
    }
}

// Leader, loot type 3: removes the selected member as a looter (command 0x22); 0x13E8 otherwise.
// FUNCTION: TITANIUM 0x00431258
void CRaid_guess::RequestRemoveLooter_guess() {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0) {
        if (isRaidLeader_55e9_guess != 0 && lootType_55f0_guess == 3 && selectedMember_55ec_guess >= 0 &&
            ((EntryRecordArray_guess*)this)->records_guess[selectedMember_55ec_guess].flag_guess != 0) {
            SendRaidCommand_guess(0x22, (const char*)pad_5064_guess,
                (const char*)&((EntryRecordArray_guess*)this)->records_guess[selectedMember_55ec_guess], 0);
            return;
        }
        char* message = pStringTable->getString(0x13e8, 0);
        pEverQuest->dsp_chat(message);
    }
}

// Leader only: command 6 for member `text` with `options` (probably a group number).
// FUNCTION: TITANIUM 0x004312BE
void CRaid_guess::Dispatch6_guess(const char* text, int options) {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0 && isRaidLeader_55e9_guess != 0) {
        const char* payload = (const char*)pad_5064_guess;
        SendRaidCommand_guess(6, payload, text, options);
    }
}

// Leader only: command 7 for member `value`.
// FUNCTION: TITANIUM 0x004312E9
void CRaid_guess::Dispatch7_guess(const char* value) {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0 && isRaidLeader_55e9_guess != 0) {
        const char* payload = (const char*)pad_5064_guess;
        SendRaidCommand_guess(7, payload, value, 0);
    }
}

// Leader: locks the raid (command 8).
// FUNCTION: TITANIUM 0x00431312
void CRaid_guess::RequestLock_guess() {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0 && isRaidLeader_55e9_guess != 0 && locked_5ab8_guess == 0) {
        SendRaidCommand_guess(8, (const char*)pad_5064_guess, (const char*)pad_5064_guess, 0);
    }
}

// Leader: unlocks the raid (command 9).
// FUNCTION: TITANIUM 0x0043133E
void CRaid_guess::RequestUnlock_guess() {
    if ((stateFlags_55e4_guess.flags_guess & 4) != 0 && isRaidLeader_55e9_guess != 0 && locked_5ab8_guess != 0) {
        SendRaidCommand_guess(9, (const char*)pad_5064_guess, (const char*)pad_5064_guess, 0);
    }
}

// Sets the raid leader's name and relabels the old and new leaders.
// FUNCTION: TITANIUM 0x0043144B
void CRaid_guess::SetRaidLeader_guess(const char* value) {
    int payloadIndex = FindMemberIndex_guess((const char*)pad_5064_guess);
    int valueIndex = FindMemberIndex_guess(value);
    CopyText_guess((char*)pad_5064_guess, value);
    if (payloadIndex != -1) {
        if (((EntryUpdateView_guess*)(((EntryStride_guess*)this) + payloadIndex))->active_guess != 0) {
            pinstCRaidWnd_guess->SetMemberRankText_guess(
                ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + payloadIndex))->text_guess,
                "Group Leader",
                ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + payloadIndex))->key_guess);
        } else {
            pinstCRaidWnd_guess->SetMemberRankText_guess(
                ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + payloadIndex))->text_guess,
                g_emptyString_guess,
                ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + payloadIndex))->key_guess);
        }
    }
    if (valueIndex != -1) {
        pinstCRaidWnd_guess->SetMemberRankText_guess(
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + valueIndex))->text_guess,
            "Raid Leader",
            ((EntryUpdateView_guess*)(((EntryStride_guess*)this) + valueIndex))->key_guess);
    }
    UpdateOptionsWindow_guess();
}

// UpdateEntryState/Flag/Mode_guess each set one of a member's marker flags and update the raid window.
// This one: +0x10E.
// FUNCTION: TITANIUM 0x004314EA
void CRaid_guess::UpdateEntryState_guess(const char* value, int state) {
    int index = FindMemberIndex_guess(value);
    if (index != -1) {
        EntryRecord_guess* record = ((EntryRecordArray_guess*)this)->records_guess + index;
        record->markerA_010e_guess = (unsigned char)state;
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->UpdateEntryStateRaw_guess(value, record->key_guess,
                state, record->markerM_010f_guess, record->markerW_0110_guess);
        }
    }
}

// Commands 20 and 22: an invite from `text` (0x13C9). Declined at once (command 0x1F) with reason 0x13CA
// while one is pending, 0x13C4 when in a raid, 0x2FE8 while 0x985808 is set; else it becomes the pending
// invite.
// FUNCTION: TITANIUM 0x0043136A
void CRaid_guess::HandleCreateInviteRaid_guess(DispatchMessage_guess* message) {
    char buffer[512];
    FormatText_guess(buffer, 0x13c9, message->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer);
    if ((stateFlags_55e4_guess.reset_guess & 2) != 0) {
        SendRaidCommand_guess(0x1f, message->text_guess, g_messageTemplate_guess + 0x120, 0x13ca);
        return;
    }
    if ((stateFlags_55e4_guess.reset_guess & 4) != 0) {
        SendRaidCommand_guess(0x1f, message->text_guess, g_messageTemplate_guess + 0x120, 0x13c4);
        return;
    }
    if (g_entryPending_guess != 0) {
        SendRaidCommand_guess(0x1f, message->text_guess, g_messageTemplate_guess + 0x120, 0x2fe8);
        return;
    }
    char* error = pStringTable->getString(0x13cb, 0);
    pEverQuest->dsp_chat(error);
    stateFlags_55e4_guess.reset_guess = 2;
    CopyText_guess((char*)&inviterName_55a4_guess, message->text_guess);
    if (message->type_guess == 0x16) {
        invitePending_55e8_guess = 1;
    }
}

// Marker flag +0x10F.
// FUNCTION: TITANIUM 0x00431544
void CRaid_guess::UpdateEntryFlag_guess(const char* value, int state) {
    int index = FindMemberIndex_guess(value);
    if (index != -1) {
        EntryRecord_guess* record = ((EntryRecordArray_guess*)this)->records_guess + index;
        record->markerM_010f_guess = (unsigned char)state;
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->UpdateEntryState_guess(value, record->key_guess,
                record->markerA_010e_guess, state, record->markerW_0110_guess);
        }
    }
}

// Marker flag +0x110.
// FUNCTION: TITANIUM 0x0043159E
void CRaid_guess::UpdateEntryMode_guess(const char* value, int state) {
    int index = FindMemberIndex_guess(value);
    if (index != -1) {
        EntryRecord_guess* record = ((EntryRecordArray_guess*)this)->records_guess + index;
        record->markerW_0110_guess = (unsigned char)state;
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->UpdateEntryMode_guess(value, record->key_guess,
                record->markerA_010e_guess, record->markerM_010f_guess, state);
        }
    }
}

// Back to no raid: clears members, looters, leader, totals and the lock.
// FUNCTION: TITANIUM 0x004315F6
void CRaid_guess::ResetRaid_guess() {
    memset(((EntryRecordArray_guess*)this)->records_guess, 0, 0x4ec0);
    memset(memberUsed_0154_guess, 0, 0x48);
    memset(pad_5064_guess, 0, 0x40);
    memset(((TextSlotsView_guess*)this)->slots_guess, 0, 0x4c0);
    selectedMember_55ec_guess = -1;
    raidMotd_51a4_guess = 0;
    memberCount_5060_guess = 0;
    stateFlags_55e4_guess.reset_guess = 1;
    isRaidLeader_55e9_guess = 0;
    leaderSpawnId_505c_guess = 0;
    lootType_55f0_guess = 1;
    totalMemberLevels_5ab4_guess = 0;
    UpdateOptionsWindow_guess();
    UpdateAverageLevel_guess();
    locked_5ab8_guess = 0;
    if (g_dataController_guess != 0) {
        g_dataController_guess->ClearRaidLeaderData_guess(g_dataOwner_guess);
    }
}

// Command 6: the whole raid. After the leading string: 0x154 bytes, an int (+0x505C), the member count, per
// member group, name, note, class, level and five flag bytes; then loot type, looter count and names, MOTD,
// leader name and a lock byte. Announces 0x13DB when we were not in a raid before.
// FUNCTION: TITANIUM 0x004316A1
// @early-stop: budget, structural ndiff=21
void CRaid_guess::HandleFullRaid_guess(int data) {
    char leader[0x64];
    unsigned int savedFlags = (unsigned int)stateFlags_55e4_guess.reset_guess;
    if (g_ownerFlag_guess->IsGroupInvitePending_guess() != 0) {
        g_ownerFlag_guess->SetGroupInvitePending_guess(0);
        g_entryPending_guess = 0;
        g_stateB_guess = 0;
        g_stateC_guess = 0;
    }
    ReportRosterChanges_guess((char*)data);
    pinstCRaidWnd_guess->Reset_guess();
    ResetRaid_guess();

    const char* cursor = (const char*)data;
    cursor += 4;
    cursor += strlen(cursor) + 1;
    CopyPrefix_guess((void*)cursor);
    cursor += 0x154;
    leaderSpawnId_505c_guess = ReadBigEndianUInt32_guess(cursor);
    cursor += 4;
    int count = ReadBigEndianUInt32_guess(cursor);
    data = 0;
    cursor += 4;
    memberCount_5060_guess = count;
    if (count > 0) {
        int entry = (int)this + 0x2a8;
        do {
            GroupEntry_guess* record = (GroupEntry_guess*)(entry - 0x10c);
            int id = ReadBigEndianUInt32_guess(cursor);
            cursor += 4;
            record->key_guess = id;
            CopyText_guess(record->name_guess, cursor);
            cursor += strlen(cursor) + 1;
            CopyText_guess(record->value_guess, cursor);
            cursor += strlen(cursor) + 1;
            unsigned char level;
            unsigned char classId;
            memcpy(&classId, cursor, 1);
            cursor += 1;
            memcpy(&level, cursor, 1);
            cursor += 1;
            record->pad_010c_guess = *cursor != 0;
            cursor += 1;
            record->active_guess = *cursor != 0;
            cursor += 1;
            record->field_010e_guess = *cursor != 0;
            cursor += 1;
            record->field_010f_guess = *cursor != 0;
            cursor += 1;
            record->field_0110_guess = *cursor != 0;
            cursor += 1;
            ConvertInteger_guess(level, record->levelText_guess, 10);
            char* className = ((OwnerDataContainer_guess*)g_dataOwner_guess)->naming_guess.KunarkClass_guess(classId, level, 0x18c, 1);
            CopyText_guess(record->className_guess, className);
            record->classId_guess = classId;
            totalMemberLevels_5ab4_guess += level;
            memberUsed_0154_guess[data] = 1;
            if (record->active_guess != 0) {
                CopyText_guess(leader, "Group Leader");
            } else {
                leader[0] = 0;
            }
            pinstCRaidWnd_guess->AddPlayer_guess(leader, record->name_guess, record->className_guess,
                record->levelText_guess, g_emptyString_guess, id, classId, record->active_guess,
                record->value_guess);
            ++data;
            entry += 0x118;
        } while (data < memberCount_5060_guess);
    }
    pinstCRaidWnd_guess->SetPlayerCount_guess(memberCount_5060_guess);
    lootType_55f0_guess = ReadBigEndianUInt32_guess(cursor);
    int slotCount = ReadBigEndianUInt32_guess(cursor + 4);
    cursor += 8;
    if (slotCount > 0) {
        char* slot = ((TextSlotsView_guess*)this)->slots_guess[0];
        data = slotCount;
        do {
            CopyText_guess(slot, cursor);
            cursor += strlen(cursor) + 1;
            slot += 0x40;
        } while (--data != 0);
    }
    CopyText_guess((char*)&raidMotd_51a4_guess, cursor);
    cursor += strlen(cursor) + 1;
    UpdateOptionsWindow_guess();
    UpdateAverageLevel_guess();
    SetRaidLeader_guess(cursor);
    const char* end = cursor + (strlen(cursor) + 1);
    if (*end != 0) {
        locked_5ab8_guess = 1;
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->Refresh_guess();
        }
    } else {
        locked_5ab8_guess = 0;
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->Refresh_guess();
        }
    }
    stateFlags_55e4_guess.reset_guess = 4;
    OwnerRoot_guess* owner = (OwnerRoot_guess*)g_dataOwner_guess;
    const char* ownerText = (const char*)owner + owner->link_guess->vbaseOffset_0004_guess + 0x44;
    if (CompareRecord_guess((const char*)pad_5064_guess, ownerText) == 0) {
        isRaidLeader_55e9_guess = 1;
    }
    if (pinstCRaidWnd_guess != 0) {
        int textIndex = FindMemberIndex_guess((const char*)pad_5064_guess);
        if (textIndex != -1) {
            GroupEntry_guess* entry = ((GroupEntryArray_guess*)this)->entries_guess + textIndex;
            pinstCRaidWnd_guess->SetMemberRankText_guess(entry->name_guess, "Raid Leader", entry->key_guess);
        }
        pinstCRaidWnd_guess->SetMotd_guess(&raidMotd_51a4_guess);
    }
    if ((savedFlags & 4) == 0) {
        char* message = g_lookupService_guess->Lookup_guess(0x13db, 0, 0x111, 1);
        g_messageService_guess->Show_guess(message);
    }
}

// Command 1: member `text` left; if it is us the raid is gone (0x13C6).
// FUNCTION: TITANIUM 0x00431A2C
// @early-stop: budget, diff ndiff=33
void CRaid_guess::DeleteRaidMember_guess(DispatchMessage_guess* message) {
    char buffer[512];
    const char* text_guess = message->text_guess;
    OwnerRoot_guess* owner = (OwnerRoot_guess*)g_dataOwner_guess;
    if (CompareRecord_guess(text_guess,
            (const char*)owner + owner->link_guess->vbaseOffset_0004_guess + 0x44) == 0) {
        ResetRaid_guess();
        pinstCRaidWnd_guess->Clear_guess();
        char* error_guess = g_lookupService_guess->Lookup_guess(0x13c6, 0, 0x111, 1);
        g_messageService_guess->Show_guess(error_guess);
    } else {
        int index_guess = FindMemberIndex_guess(text_guess);
        if (index_guess != -1) {
            int* count_guess = &memberCount_5060_guess;
            EntryStride_guess* entry_guess = ((EntryStride_guess*)this) + index_guess;
            memberUsed_0154_guess[index_guess] = 0;
            --*count_guess;
            EntryUpdateView_guess* view_guess = (EntryUpdateView_guess*)entry_guess;
            pinstCRaidWnd_guess->RemovePlayerFromList_guess(view_guess->text_guess, view_guess->key_guess);
            pinstCRaidWnd_guess->SetEntryCount_guess(*count_guess);
            totalMemberLevels_5ab4_guess -= atol(view_guess->value_guess);
            UpdateAverageLevel_guess();
            memset(view_guess->text_guess, 0, 0x118);
            FormatText_guess(buffer, 0x13c7, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer, 0x111, 1);
            UpdateOptionsWindow_guess();
        }
    }
}

// Command 30: `value` now leads the raid: 0x13CD if that is us, else 0x13CE.
// FUNCTION: TITANIUM 0x00431B71
void CRaid_guess::HandleNewLeader_guess(const char* value, void* data) {
    char buffer[512];
    SetRaidLeader_guess(value);
    CopyData_guess(data);

    OwnerRoot_guess* owner = (OwnerRoot_guess*)g_dataOwner_guess;
    const char* ownerText = (const char*)owner + owner->link_guess->vbaseOffset_0004_guess + 0x44;
    if (CompareRecord_guess(value, ownerText) == 0) {
        FormatText_guess(buffer, 0x13cd, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        isRaidLeader_55e9_guess = 1;
    } else {
        FormatText_guess(buffer, 0x13ce, (const char*)pad_5064_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        isRaidLeader_55e9_guess = 0;
    }
    pEverQuest->dsp_chat(buffer, 0x111, 1);
}

// Copies the 64 leadership ability ranks at +0xBF0 of `data` (the player's character, 0x00905D00) into the
// raid's leader ranks (+0x50A4), then into the character's raid leader block via 0x004B40D1. Run when the
// player becomes raid leader (0x00431C6B).
// FUNCTION: TITANIUM 0x00431C23
// @early-stop: budget, structural ndiff=9
void CRaid_guess::CopyServerData_guess(ServerData_guess* data) {
    for (int index = 0; index < 0x40; ++index) {
        leaderRanks_50a4_guess[index] = data->values_guess[index];
    }
    if (g_dataController_guess != 0) {
        g_dataController_guess->SetRaidLeaderRanks_guess(g_dataOwner_guess, leaderRanks_50a4_guess);
    }
}

// Command 8: we lead a new, unlocked raid (0x13C5). +0x84 of the message goes to +0x505C.
// FUNCTION: TITANIUM 0x00431C6B
void CRaid_guess::ChangeLeader_guess(LeaderChange_guess* change) {
    SetRaidLeader_guess(g_serverData_guess->name_guess);
    CopyServerData_guess(g_serverData_guess);
    leaderSpawnId_505c_guess = change->leader_guess;
    stateFlags_55e4_guess.reset_guess = 4;
    isRaidLeader_55e9_guess = 1;
    locked_5ab8_guess = 0;
    if (pinstCRaidWnd_guess != 0) {
        pinstCRaidWnd_guess->Refresh_guess();
    }
    pEverQuest->dsp_chat(pStringTable->getString(0x13c5, 0), 0x111, 1);
}

// Server raid messages, by command id; most cases are described on their handlers.
// FUNCTION: TITANIUM 0x00431CF2
void CRaid_guess::HandleS2CRaidMessage_guess(DispatchMessage_guess* message) {
    char buffer[512];
    switch (message->type_guess) {
    // MOTD, up to 1024 bytes.
    case 35: {
        char* dest = (char*)&raidMotd_51a4_guess;
        CopyBuffer_guess(dest, message->data_guess, 0x400);
        if (pinstCRaidWnd_guess != 0) {
            pinstCRaidWnd_guess->SetMotd_guess(dest);
        }
        break;
    }
    // Note for one member.
    case 36: {
        int index = FindMemberIndex_guess(message->text_guess);
        if (index != -1) {
            EntryRecord_guess* record = ((EntryRecordArray_guess*)this)->records_guess + index;
            char* dest = ((EntryRecordText_guess*)record)->text_guess;
            CopyBuffer_guess(dest, message->data_guess, 0x40);
            if (pinstCRaidWnd_guess != 0) {
                pinstCRaidWnd_guess->SetNoteText_guess(message->text_guess, dest);
            }
        }
        break;
    }
    case 8:
        ChangeLeader_guess((LeaderChange_guess*)message);
        break;
    case 0:
        AddRaidMember((RaidMember_guess*)message);
        break;
    case 1:
        DeleteRaidMember_guess(message);
        break;
    case 2:
        RenameMember_guess((OwnerValueRecord_guess*)message);
        break;
    // Raid disbanded (0x13CF); 10 announces it only when we were in one, 5 always.
    case 10:
        if ((stateFlags_55e4_guess.flags_guess & 4) != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x13cf, 0), 0x111, 1);
        }
        ResetRaid_guess();
        pinstCRaidWnd_guess->Reset_guess();
        break;
    case 5:
        pEverQuest->dsp_chat(pStringTable->getString(0x13cf, 0), 0x111, 1);
        ResetRaid_guess();
        pinstCRaidWnd_guess->Reset_guess();
        break;
    case 6:
        HandleFullRaid_guess((int)message);
        break;
    case 20:
    case 22:
        HandleCreateInviteRaid_guess(message);
        break;
    // A server string id in `value`; 12 and 31 below do the same with the other colour.
    case 19:
        FormatText_guess(buffer, message->value_guess, message->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0xd, 1);
        break;
    // Our invite is gone: back to no raid.
    case 4:
        stateFlags_55e4_guess.reset_guess = 1;
        memset(pad_5064_guess, 0, 0x40);
        break;
    case 7:
        FormatText_guess(buffer, 0x13d0, message->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0x111, 1);
        break;
    case 30:
        HandleNewLeader_guess(message->text_guess, &message->value_guess);
        break;
    case 14:
        if (g_dataController_guess != 0) {
            g_dataController_guess->SetRaidLeaderRanks_guess(g_dataOwner_guess, &message->value_guess);
        }
        break;
    case 15:
        if (g_dataController_guess != 0) {
            g_dataController_guess->SetRaidLeaderBlock_guess(g_dataOwner_guess, &message->value_guess);
        }
        break;
    case 3:
        SetMemberGroup_guess((OwnerKeyRecord_guess*)message);
        break;
    case 11:
        SetLootTypeResponse_guess((StatusView_guess*)message);
        break;
    case 12:
    case 31:
        FormatText_guess(buffer, message->value_guess, message->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0x111, 1);
        break;
    case 32:
        SetLootType_guess(message->value_guess);
        break;
    case 33:
        AddRaidLooter_guess(message->text_guess);
        break;
    case 34:
        RemoveRaidLooter_guess(message->text_guess);
        break;
    case 13:
        RaidGroupLeaderChange_guess(message);
        break;
    case 16:
        DispatchEntry_guess(message->text_guess);
        break;
    case 17:
        SetLocked_guess();
        break;
    case 18:
        SetUnlocked_guess();
        break;
    }
}

