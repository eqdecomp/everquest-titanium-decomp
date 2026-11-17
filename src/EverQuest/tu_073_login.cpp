// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 73: a hint from compare/tumap.py.
// Leadership abilities, then world-server login. LeadershipManager_guess holds the 31 ability definitions
// (MenuSelection_guess = LeadershipAbility_guess; 0-15 group, 16-30 raid). EQ_CharacterLeadershipView_guess and CharView_guess are
// pCharData, StringTableView_guess StringTable, CEverQuestView_guess CEverQuest. Actor slots (pActorInfo +0x170):
// 0 group assist, 1-3 raid assists, 4-6 group marks, 7-9 raid marks, 10 target's target.
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <new>
#include <string.h>
#include "titanium/wnd/CLeadershipWnd.h"
#include "titanium/wnd/CTargetOfTargetWnd.h"

struct Data79_guess {
	unsigned int values[79];
};

struct Data85_guess {
	unsigned int values[85];
};

struct Target79_guess {
	char pad[0x1770];
	Data79_guess data;
	Data85_guess data85;
};

struct Target85_guess {
	char pad[0x18ac];
	Data85_guess data;
};

struct TargetCheckData_guess {
	char pad[0x1770];
	int values79[79];
	int values85[85];
};

struct LeadershipAbility_guess {
	char pad00_guess[8];
	int value08_guess;
	char pad0c_guess[0x24 - 0xc];
	int base_guess;
	int multiplier_guess;
	int state;
	int value30_guess;
	int threshold;
	unsigned char flag;
	// EXTERNAL: TITANIUM 0x00469DD7 LeadershipAbility_guess::Release_guess
	void Release_guess();
};

struct ErrorPayload_guess {
	unsigned int value00_guess;
	unsigned int value04_guess;
	unsigned int value08_guess;
	unsigned int value0c_guess;
	unsigned int value10_guess;
	unsigned int value14_guess;
	unsigned int value18_guess;
	char text_guess[64];
};

struct MenuSelection_guess {
	int first_guess;
	int second_guess;
	int third_guess;
	int fourth_guess;
	int fifth_guess;
	int sixth_guess;
	int seventh_guess;
	int eighth_guess;
	int pad20_guess;
	int type_guess;
	int state_guess;
	int flag0_guess;
	int flag1_guess;
	int category_guess;
	unsigned char enabled_guess;
	// EXTERNAL: TITANIUM 0x004B3898 MenuSelection_guess::MenuSelection_guess
	MenuSelection_guess(unsigned int index);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyErrorText_guess
void __cdecl CopyErrorText_guess(char* output, const char* input);

// EXTERNAL: TITANIUM 0x004912B1 SendError_guess
void __cdecl SendError_guess(void* owner, int opcode, ErrorPayload_guess* payload,
	int size, int flag);

struct StringTableView_guess {
	// EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::Lookup_guess
	const char* Lookup_guess(int id, int value, int type, int flag);
};

struct CEverQuestView_guess {
	// EXTERNAL: TITANIUM 0x004982C6 CEverQuestView_guess::Show_guess
	void Show_guess(const char* message);
};

struct EQ_CharacterLeadershipView_guess {
	char pad00_guess[0x1794];
	int value1794_guess;
	int value1798_guess;
	int value179c_guess;
	int value17a0_guess;
	char pad17a4_guess[0x190c - 0x17a4];
	int value190c_guess;
	int value1910_guess;
	int value1914_guess;
	int value1918_guess;
	char pad191c_guess[0xc284 - 0x191c];
	struct StateIndex_guess {
		char pad00_guess[4];
		unsigned int index_guess;
	};
	StateIndex_guess* state_guess;
	char padC288_guess[0x104];
	unsigned char flags_guess[1];
	// EXTERNAL: TITANIUM 0x004BC9F8 EQ_CharacterLeadershipView_guess::HasGroupOfAtLeast_guess
	bool HasGroupOfAtLeast_guess(int id);
	// EXTERNAL: TITANIUM 0x004BB282 EQ_CharacterLeadershipView_guess::IsGroupLeader_guess
	bool IsGroupLeader_guess();
	// EXTERNAL: TITANIUM 0x004BAB62 EQ_CharacterLeadershipView_guess::IsGroupMarkNpcDelegate_guess
	bool IsGroupMarkNpcDelegate_guess();
	// EXTERNAL: TITANIUM 0x004BAB86 EQ_CharacterLeadershipView_guess::IsGroupMainAssist_guess
	bool IsGroupMainAssist_guess();
	// EXTERNAL: TITANIUM 0x004BAB58 EQ_CharacterLeadershipView_guess::CheckBase_guess
	bool CheckBase_guess();
	// EXTERNAL: TITANIUM 0x004BABAA EQ_CharacterLeadershipView_guess::IsRaidMarkNpcDelegate_guess
	bool IsRaidMarkNpcDelegate_guess();
	// EXTERNAL: TITANIUM 0x004BABCE EQ_CharacterLeadershipView_guess::IsRaidMainAssist_guess
	bool IsRaidMainAssist_guess();
	// EXTERNAL: TITANIUM 0x004BAB2F EQ_CharacterLeadershipView_guess::HasRaidOfAtLeast_guess
	bool HasRaidOfAtLeast_guess(int id);
	// EXTERNAL: TITANIUM 0x004BB226 EQ_CharacterLeadershipView_guess::IsAGroupMember_guess
	int IsAGroupMember_guess(const char* name);
};

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0046DA4A BuildErrorMessage_guess
void __cdecl BuildErrorMessage_guess(char* output, int messageId, const char* number,
	int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);

#define g_errorOwnerAddress_guess EQ_ARRAY(char, 0x00905CA0)
#define g_errorCatalog_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_errorDisplay_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)
#define g_errorCheck_guess EQ_GLOBAL(EQ_CharacterLeadershipView_guess*, 0x00905D00)

struct CRaid_guess {
	// EXTERNAL: TITANIUM 0x004303A6 CRaid_guess::IsMember_guess
	bool IsMember_guess(void* candidate);
};

#define g_candidateState_guess EQ_ARRAY(CRaid_guess, 0x0091D708)

struct PlayerPathView_guess {
	// EXTERNAL: TITANIUM 0x004C13D7 PlayerPathView_guess::Cancel_guess
	void Cancel_guess();
	// EXTERNAL: TITANIUM 0x004C25AE PlayerPathView_guess::FindRaidMember_guess
	void FindRaidMember_guess(int value);
	// EXTERNAL: TITANIUM 0x004C2566 PlayerPathView_guess::Clear_guess
	void Clear_guess(int value);
};

#define g_currentMode_guess EQ_GLOBAL(PlayerPathView_guess*, 0x00985C88)

// EXTERNAL: TITANIUM 0x0047C88E ResolveCandidate_guess
int __cdecl ResolveCandidate_guess(void* candidate);

struct ThresholdData_guess;

struct ValueSource_guess {
	char pad[0x1a58];
	int level_guess;
};

struct LeadershipManager_guess {
	LeadershipAbility_guess* elements[31];
	LeadershipManager_guess();
	int GetGroupLeadershipPointCap_guess(ValueSource_guess* source);
	int HighCategory_guess(ValueSource_guess* source);
	void SetGroupLeaderBlock_guess(Target79_guess* target, const Data79_guess* source);
	void SetRaidLeaderBlock_guess(Target85_guess* target, const Data85_guess* source);
	bool IsGroupAbility_guess(unsigned int index);
	void SendRaidDelegateAbility_guess(unsigned int value, const char* message);
	void WarnGroupTooSmall_guess();
	void WarnRaidTooSmall_guess();
	void FindPathToPlayer_guess(void* candidate);
	void UseAbility_guess(int kind, int value);
	void Clear_guess();
	bool HasSharedRank_guess(TargetCheckData_guess* target, unsigned int index, int amount);
	bool CanUseAbility_guess(EQ_CharacterLeadershipView_guess* target, unsigned int action, int amount);
	bool CheckActionAmount_guess(EQ_CharacterLeadershipView_guess* target, unsigned int action, int amount);
	int GetRegenBonus_guess(EQ_CharacterLeadershipView_guess* target);
	int GetOffenseBonus_guess(EQ_CharacterLeadershipView_guess* target);
	int GetHealthBonus_guess(EQ_CharacterLeadershipView_guess* target);
	int GetManaBonus_guess(EQ_CharacterLeadershipView_guess* target);
	void HandleLeadershipMessage_guess(void* connection, unsigned int opcode, void* data,
		unsigned int size);
	int CanBuyNextRank_guess(ThresholdData_guess* target, unsigned int index);
	int GetNextRankCost_guess(ThresholdData_guess* target, unsigned int index);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct ThresholdData_guess {
	char pad[0xbf0];
	int values[64];
	char pad0cf0_guess[0xea0 - 0xcf0];
	int valueEA0_guess;
	int valueEA4_guess;
};

typedef unsigned long (__stdcall *GetTickCountFunction_guess)();
#define g_getTickCount_guess EQ_GLOBAL(GetTickCountFunction_guess, 0x0063F180)

typedef void* (__cdecl *ElementConstructorFunction_guess)(void*);
#define g_constructElementAddress_guess EQ_ARRAY(char, 0x00451A9B)
// EXTERNAL: TITANIUM 0x00401000 VectorConstructorIterator_guess
void __stdcall VectorConstructorIterator_guess(void* first, unsigned int elementSize,
	int count, ElementConstructorFunction_guess constructor);

struct PositionHistory_guess {
	char pad[0x1e4];
	unsigned int lastUpdate;
	unsigned char flag;
	void UpdateTick_guess();
	void UpdateSharedValues_guess();
	void AddSharedValues_guess();
	PositionHistory_guess();
};

struct SharedValues_guess {
	float first;
	unsigned int second;
	unsigned int third;
};

struct Position_guess {
	char pad00_guess[0x30];
	float x_guess;
	float y_guess;
};

struct PositionList_guess {
	char pad00_guess[0x170];
	Position_guess* current_guess;
	Position_guess* entries_guess[3];
};

struct SharedSource_guess {
	char pad00_guess[0x30];
	float first_guess;
	float second_guess;
	unsigned int third_guess;
	char pad3c_guess[0x10];
	float last_guess;
	char pad50_guess[0x1a8 - 0x50];
	PositionList_guess* positions_guess;
};

#define g_sharedSource_guess EQ_GLOBAL(SharedSource_guess*, 0x00905CE4)
#define g_sharedOwner_guess EQ_GLOBAL(PositionHistory_guess, 0x00985A08)
#define g_sharedOwnerInit_guess EQ_GLOBAL(unsigned int, 0x00985BF4)

struct CopyRecord_guess {
	unsigned int values[3];
	// EXTERNAL: TITANIUM 0x0048F790 CopyRecord_guess::Distance_guess
	float Distance_guess(const CopyRecord_guess* other);
};

struct CDisplayView_guess {
	// EXTERNAL: TITANIUM 0x00439BD1 CDisplayView_guess::Distance_guess
	float Distance_guess(float x0, float y0, float z0, float x1, float y1,
		float z1, float extra);
};

#define g_distanceOwner_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)

struct Position2D_guess {
	float x_guess;
	float y_guess;
};

struct PositionSelector_guess {
	Position_guess* SelectAssistTarget_guess(int mode);
};

struct BulkDataOwner_guess {
	CopyRecord_guess records[30];
	unsigned int values[30];
	unsigned char flag0;
	char pad1e1_guess[7];
	unsigned char flag1;
	void Copy_guess(const unsigned int* source, float value);
	void Get_guess(SharedValues_guess* record, float* value);
	void Add_guess(const CopyRecord_guess* source, float value);
};


struct TargetResetValues_guess {
	char pad00_guess[0x170];
	int value170_guess;
	char pad174_guess[0x0c];
	int values180_guess[3];
};

struct TargetResetOwner_guess {
	char pad00_guess[0x1a8];
	TargetResetValues_guess* values_guess;
};

struct TargetResetSubobject_guess {
	// EXTERNAL: TITANIUM 0x004647A4 TargetResetSubobject_guess::Reset_guess
	void Reset_guess();
};

struct TargetResetObject_guess {
	char pad00_guess[0x1770];
	TargetResetSubobject_guess subobject_guess;
	char pad1771_guess[0xC288 - 0x1770 - sizeof(TargetResetSubobject_guess)];
	TargetResetOwner_guess* owner_guess;
};

struct TargetResetReceiver_guess {
	void ClearGroupLeaderData_guess(TargetResetObject_guess* target);
};

// Builds the 31 ability definitions.
// FUNCTION: TITANIUM 0x004B3F48
LeadershipManager_guess::LeadershipManager_guess()
{
	memset(this, 0, sizeof(*this));
	for (int i = 0; i < 31; ++i)
		elements[i] = (LeadershipAbility_guess*)new MenuSelection_guess(i);
}

// Group cap by level (+0x1A58; 65 without a character): 4 below 35, 6 below 51, else 8; probably the
// banked-point limit.
// FUNCTION: TITANIUM 0x004B3FA2
// @early-stop: budget, structural ndiff=8
int LeadershipManager_guess::GetGroupLeadershipPointCap_guess(ValueSource_guess* source)
{
	int level;
	int result;
	if (source != 0)
		level = source->level_guess;
	else
		level = 0x41;
	if (level < 0x23)
		result = 4;
	else
		result = (level >= 0x33) * 2 + 6;
	return result;
}

// Raid cap by level: 6 below 45, 8 below 55, else 10.
// FUNCTION: TITANIUM 0x004B3FD0
// @early-stop: budget, structural ndiff=8
int LeadershipManager_guess::HighCategory_guess(ValueSource_guess* source)
{
	int value;
	int result;
	if (source != 0)
		value = source->level_guess;
	else
		value = 0x41;
	if (value < 0x2d)
		result = 6;
	else
		result = (value >= 0x37) * 2 + 8;
	return result;
}

// Drops the group leader's data: the group block (pCharData +0x1770), the group assist target and the
// group marks.
// FUNCTION: TITANIUM 0x004B3FFE
void TargetResetReceiver_guess::ClearGroupLeaderData_guess(TargetResetObject_guess* target)
{
	if (target != 0) {
		target->subobject_guess.Reset_guess();
		TargetResetOwner_guess* owner = target->owner_guess;
		if (owner != 0) {
			TargetResetValues_guess* values = owner->values_guess;
			if (values != 0) {
				values->value170_guess = 0;
				for (int i = 0; i < 3; ++i)
					values->values180_guess[i] = 0;
			}
		}
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

// Stores the group leader's 64 ability ranks (pCharData +0x1770).
// FUNCTION: TITANIUM 0x004B40A0
void __stdcall SetGroupLeaderRanks_guess(Target79_guess* target, void* source)
{
	if (target != 0) {
		memcpy(&target->data, source, 0x100);
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

// Stores the raid leader's 64 ability ranks (pCharData +0x18AC).
// FUNCTION: TITANIUM 0x004B40D1
void __stdcall SetRaidLeaderRanks_guess(Target85_guess* target, void* source)
{
	if (target != 0) {
		memcpy(&target->data, source, 0x100);
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

struct ResetSlot_guess {
	unsigned int values00_guess[0x40];
	unsigned int values100_guess[9];
	struct Record_guess {
		int value_guess;
		float first_guess;
		float second_guess;
		float third_guess;
	} records_guess[3];
	void Clear_guess();
};

// Clears the raid block: 64 ranks, 9 delegated-role ids, three records.
// FUNCTION: TITANIUM 0x004B3EFA
void ResetSlot_guess::Clear_guess()
{
	for (int i = 0; i < 0x40; ++i)
		values00_guess[i] = 0;
	for (int i = 0; i < 3; ++i)
		values100_guess[i] = 0;
	for (int i = 3; i < 6; ++i)
		values100_guess[i] = 0;
	for (int i = 6; i < 9; ++i)
		values100_guess[i] = 0;
	for (int i = 0; i < 3; ++i) {
		records_guess[i].first_guess = 0.0f;
		records_guess[i].second_guess = 0.0f;
		records_guess[i].value_guess = 0;
		records_guess[i].third_guess = 0.0f;
	}
}

struct ResetValues_guess {
	char pad00_guess[0x174];
	int values174_guess[3];
	char pad180_guess[0x0c];
	int values18c_guess[3];
};

struct ResetOwner_guess {
	char pad00_guess[0x1a8];
	ResetValues_guess* values_guess;
};

struct ResetTarget_guess {
	char pad00_guess[0x18ac];
	ResetSlot_guess slot_guess;
	char pad18ad_guess[0xc288 - 0x18ac - sizeof(ResetSlot_guess)];
	ResetOwner_guess* owner_guess;
};

// Drops the raid leader's data: the raid block, the raid assist targets and the raid marks.
// FUNCTION: TITANIUM 0x004B404D
void __stdcall ClearRaidLeaderData_guess(ResetTarget_guess* target)
{
	if (target != 0) {
		target->slot_guess.Clear_guess();
		ResetOwner_guess* owner = target->owner_guess;
		if (owner != 0) {
			ResetValues_guess* values = owner->values_guess;
			if (values != 0) {
				for (int i = 0; i < 3; ++i)
					values->values174_guess[i] = 0;
				for (int i = 0; i < 3; ++i)
					values->values18c_guess[i] = 0;
			}
		}
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

// EXTERNAL: TITANIUM 0x0046D655 GetTickValue_guess
int __cdecl GetTickValue_guess();

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* message, ...);

struct Connection_guess {
	// EXTERNAL: TITANIUM 0x00424BE6 Connection_guess::SetState_guess
	void SetState_guess(int value);
	// EXTERNAL: TITANIUM 0x0040BE8B Connection_guess::Poll_guess
	int Poll_guess();
	// EXTERNAL: TITANIUM 0x00424BC3 Connection_guess::GetServerVersion_guess
	int GetServerVersion_guess();
	// EXTERNAL: TITANIUM 0x00424BA0 Connection_guess::GetClientVersion_guess
	int GetClientVersion_guess();
};

// EXTERNAL: TITANIUM 0x0045386D ReadWorldFlags_guess
void __cdecl ReadWorldFlags_guess(unsigned short* payload);
// EXTERNAL: TITANIUM 0x00451E54 UpdatePetitionQueue_guess
void __cdecl UpdatePetitionQueue_guess(unsigned short* payload);
// EXTERNAL: TITANIUM 0x0046D7D4 UpdateWorldConnection_guess
void __cdecl UpdateWorldConnection_guess(unsigned short* payload, int connection);
// EXTERNAL: TITANIUM 0x004520E5 Handle_OP_SendCharInfo_guess
void __cdecl Handle_OP_SendCharInfo_guess(int connection, int opcode,
	unsigned short* payload, int size);

struct WorldMessageProcessor_guess {
	// EXTERNAL: TITANIUM 0x0040B8CB WorldMessageProcessor_guess::Dispatch_guess
	void Dispatch_guess(int connection, int opcode, unsigned short* payload, int size);
};

#define g_worldMessageProcessor_guess EQ_GLOBAL(WorldMessageProcessor_guess, 0x00905D38)
#define g_worldRouteAddress_guess EQ_GLOBAL(unsigned int, 0x00900478)
#define g_worldRoutePort_guess EQ_GLOBAL(unsigned int, 0x0090047C)
#define g_worldServerAddress_guess EQ_GLOBAL(unsigned int, 0x00923D58)
#define g_worldServerPort_guess EQ_GLOBAL(unsigned int, 0x00923D5C)
#define g_worldServerValue08_guess EQ_GLOBAL(unsigned int, 0x00923D68)
#define g_worldServerValue0c_guess EQ_GLOBAL(unsigned int, 0x00923D6C)
#define g_worldServerValue10_guess EQ_GLOBAL(unsigned int, 0x00923D70)
#define g_worldServerValue14_guess EQ_GLOBAL(unsigned int, 0x00923D60)
#define g_worldServerName_guess EQ_ARRAY(char, 0x0095D3D4)
#define g_worldFlag0_guess EQ_GLOBAL(unsigned char, 0x00905CA8)
#define g_worldFlag1_guess EQ_GLOBAL(unsigned char, 0x00905CA9)
#define g_worldFlag2_guess EQ_GLOBAL(unsigned char, 0x00923D64)
#define g_worldFlag3_guess EQ_GLOBAL(unsigned char, 0x00923D65)
#define g_worldFlag4_guess EQ_GLOBAL(unsigned char, 0x00923D7C)
#define g_worldFlag5_guess EQ_GLOBAL(unsigned char, 0x00923D66)
#define g_worldAuthenticationStatus_guess EQ_GLOBAL(int, 0x00904208)
#define g_loginDialogFlag_guess EQ_GLOBAL(unsigned char, 0x00988C2C)

struct WorldPayload_guess {
	unsigned int value00_guess;
	unsigned int value04_guess;
	unsigned int value08_guess;
	unsigned int value0c_guess;
	unsigned int value10_guess;
	unsigned int value14_guess;
	char pad18_guess[8];
	char serverName_guess[0xd4];
	unsigned char flagf4_guess;
	unsigned char flagf5_guess;
	char padf6_guess[0xe];
	unsigned char flag104_guess;
	unsigned char flag105_guess;
	unsigned char flag106_guess;
	unsigned char flag107_guess;
};

struct WorldAuthenticate_guess {
	char pad00_guess[4];
	int* status_guess;
	int* accessGranted_guess;
	int* invalidLogin_guess;
	unsigned char lost_guess;
	char pad11_guess[3];
	int lastTick_guess;
	void WorldAuthenticate(int ignored_guess, unsigned short* message_guess, int size_guess);
	int Elapsed_guess();
	void ConnectionLost_guess(Connection_guess* connection);
	void Handle_OP_CharacterStillInZone_guess();
};

struct WorldState_guess {
	char pad00_guess[0xb50];
	int authenticationLost_guess;
};

#define g_worldState_guess EQ_GLOBAL(WorldState_guess*, 0x00988DF0)

struct AuthenticationState_guess {
	// EXTERNAL: TITANIUM 0x0042500C AuthenticationState_guess::Reset_guess
	void Reset_guess(int* status);
	// EXTERNAL: TITANIUM 0x00424F2E AuthenticationState_guess::Connect_guess
	Connection_guess* Connect_guess(const char* host, int port, int timeout);
};

#define g_authenticationState_guess EQ_GLOBAL(AuthenticationState_guess*, 0x0079DBD8)

struct ConnectRequest_guess {
	char host_guess[0x80];
	short port_guess;
};

#define g_activeConnection_guess EQ_GLOBAL(Connection_guess*, 0x00905CA0)

// EXTERNAL: TITANIUM 0x00600E40 Delay_guess
void __cdecl Delay_guess(int milliseconds);

// EXTERNAL: TITANIUM 0x005E5AF0 VersionName_guess
const char* __cdecl VersionName_guess(int version);

// Copies the whole group block: 64 ranks, then role ids from +0x1870 (79 ints).
// FUNCTION: TITANIUM 0x004B4102
void LeadershipManager_guess::SetGroupLeaderBlock_guess(Target79_guess* target, const Data79_guess* source)
{
	if (target != 0) {
		target->data = *source;
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

// Copies the whole raid block: 64 ranks, then role ids from +0x19AC (85 ints).
// FUNCTION: TITANIUM 0x004B412F
void LeadershipManager_guess::SetRaidLeaderBlock_guess(Target85_guess* target, const Data85_guess* source)
{
	if (target != 0) {
		target->data = *source;
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
	}
}

// Whether ability `index` is a group ability.
// FUNCTION: TITANIUM 0x004B415C
bool LeadershipManager_guess::IsGroupAbility_guess(unsigned int index)
{
	return elements[index]->state == 1;
}

// Delegates raid role `value` (3-5) to the named member (RaidDelegateAbility, 0x5C bytes); with no name
// prints string 0x222C. Not CEverQuest::GuildPeace, whatever the Mac match says.
// FUNCTION: TITANIUM 0x004B4171
void LeadershipManager_guess::SendRaidDelegateAbility_guess(unsigned int value, const char* message)
{
	if (message != 0) {
		ErrorPayload_guess payload;
		payload.value14_guess = 0;
		payload.value0c_guess = 0;
		payload.value04_guess = 0;
		payload.value10_guess = 0;
		payload.value00_guess = value;
		CopyErrorText_guess(payload.text_guess, message);
		SendError_guess(g_errorOwnerAddress_guess, OP_RaidDelegateAbility, &payload, 0x5c, 1);
	}
	else {
		const char* fallback = g_errorCatalog_guess->Lookup_guess(0x222c, 0, 0xd, 1);
		g_errorDisplay_guess->Show_guess(fallback);
	}
}

// Assist target: mode 0 the group assist (slot 0), 1 the nearest raid assist (slots 1-3), 2 the nearest of
// all four, measured on the ground plane from the player.
// FUNCTION: TITANIUM 0x004B424F
// @early-stop: budget, diff ndiff=16
Position_guess* PositionSelector_guess::SelectAssistTarget_guess(int mode)
{
	SharedSource_guess* source = g_sharedSource_guess;
	PositionList_guess* positions = source->positions_guess;
	float* sourcePosition = &source->first_guess;
	Position_guess* result = 0;
	float sourceX;
	float sourceY;
	float nearest = 1000000.0f;
	Position2D_guess coordinates;

	if (positions != 0 && &source->first_guess != 0) {
		if (mode == 0) {
			result = positions->current_guess;
		}
		else {
			if (mode == 2) {
				result = positions->current_guess;
				if (result != 0) {
					coordinates.y_guess = result->y_guess;
					coordinates.x_guess = result->x_guess;
					sourceY = sourcePosition[1];
					sourceX = sourcePosition[0];
					nearest = g_distanceOwner_guess->Distance_guess(
						sourceX, sourceY, 0.0f,
						coordinates.x_guess, coordinates.y_guess, 0.0f, 0.0f);
				}
			}
			Position_guess** entry = positions->entries_guess;
			int count = 3;
			do {
				Position_guess* candidate = *entry;
				if (candidate != 0 && &candidate->x_guess != 0) {
					coordinates.y_guess = candidate->y_guess;
					coordinates.x_guess = candidate->x_guess;
					sourceY = sourcePosition[1];
					sourceX = sourcePosition[0];
					float distance = g_distanceOwner_guess->Distance_guess(
						sourceX, sourceY, 0.0f,
						coordinates.x_guess, coordinates.y_guess, 0.0f, 0.0f);
					if (distance < nearest) {
						nearest = distance;
						result = candidate;
					}
				}
				++entry;
				--count;
			} while (count != 0);
		}
	}
	return result;
}

// Unless the group has at least 3 members (0x4BC9F8), prints string 0x2263 with the number 3.
// FUNCTION: TITANIUM 0x004B437C
void LeadershipManager_guess::WarnGroupTooSmall_guess()
{
	char message[256];
	char number[8];
	if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
		BuildErrorMessage_guess(message, 0x2263, __itoa(3, number, 10),
			0, 0, 0, 0, 0, 0, 0, 0);
		pEverQuest->dsp_chat(message, 0xd, 1);
	}
}

// Raid counterpart: at least 18 members, string 0x2262.
// FUNCTION: TITANIUM 0x004B43ED
void LeadershipManager_guess::WarnRaidTooSmall_guess()
{
	char message[256];
	char number[8];
	if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
		BuildErrorMessage_guess(message, 0x2262, __itoa(0x12, number, 10),
			0, 0, 0, 0, 0, 0, 0, 0);
		pEverQuest->dsp_chat(message, 0xd, 1);
	}
}

// Frees the 31 ability definitions.
// FUNCTION: TITANIUM 0x004B445E
void LeadershipManager_guess::Clear_guess()
{
	for (int i = 0; i < 31; ++i) {
		LeadershipAbility_guess* element = elements[i];
		if (element != 0) {
			element->Release_guess();
			free(element);
			elements[i] = 0;
		}
	}
}

// Whether the leader shares at least rank `amount` of ability `index` (group or raid block by its kind).
// FUNCTION: TITANIUM 0x004B4488
bool LeadershipManager_guess::HasSharedRank_guess(TargetCheckData_guess* target, unsigned int index, int amount)
{
	return target != 0 &&
	((elements[index]->state == 1 && target->values79[index] >= amount) ||
	 (elements[index]->state == 2 && target->values85[index] >= amount));
}

// Find Path to a named player (`candidate`, may be 0): picks group ability 13 or raid ability 28 by which
// the leader shares and where the name is, then starts the PlayerPath search (0x985C88). Strings: 0x2269 no
// ability, 0x226A not a member, 0x226B no such player.
// FUNCTION: TITANIUM 0x004B4617
// @early-stop: budget, structural ndiff=109
void LeadershipManager_guess::FindPathToPlayer_guess(void* candidate)
{
	char second;
	char first;
	first = HasSharedRank_guess((TargetCheckData_guess*)g_errorCheck_guess, 0xd, 1);
	second = HasSharedRank_guess((TargetCheckData_guess*)g_errorCheck_guess, 0x1c, 1);

	if (!second) {
		if (!first) {
			const char* message = g_errorCatalog_guess->Lookup_guess(0x2269, 0, 0xd, 1);
			g_errorDisplay_guess->Show_guess(message);
			return;
		}
		if (candidate == 0 || g_errorCheck_guess->IsAGroupMember_guess((const char*)candidate) == 0) {
			const char* message = g_errorCatalog_guess->Lookup_guess(0x226a, 0, 0xd, 1);
			g_errorDisplay_guess->Show_guess(message);
			return;
		}
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
	}
	else if (!first) {
		if (candidate == 0 || !g_candidateState_guess->IsMember_guess(candidate)) {
			const char* message = g_errorCatalog_guess->Lookup_guess(0x226a, 0, 0xd, 1);
			g_errorDisplay_guess->Show_guess(message);
			return;
		}
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
	}
	else if (candidate != 0) {
		if (!g_candidateState_guess->IsMember_guess(candidate) ||
			!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			if (g_errorCheck_guess->IsAGroupMember_guess((const char*)candidate) == 0 ||
				!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
				WarnGroupTooSmall_guess();
				return;
			}
			second = false;
		}
	}
	else {
		const char* message = g_errorCatalog_guess->Lookup_guess(0x226a, 0, 0xd, 1);
		g_errorDisplay_guess->Show_guess(message);
		return;
	}

	int result = ResolveCandidate_guess(candidate);
	if (result != 0) {
		g_currentMode_guess->Cancel_guess();
		if (second)
			g_currentMode_guess->FindRaidMember_guess(result);
		else
			g_currentMode_guess->Clear_guess(result);
		return;
	}
	const char* message = g_errorCatalog_guess->Lookup_guess(0x226b, 0, 0xd, 1);
	g_errorDisplay_guess->Show_guess(message);
}

// Whether pCharData may use ability `action` at rank `amount`: leadership bit 0x40, the shared rank, then
// a group of 3+ (abilities 0-14) or a raid of 18+ (16-29), and for some a leader or role check (CheckPrimary
// is probably group leader, CheckBase raid leader).
// FUNCTION: TITANIUM 0x004B44C6
bool LeadershipManager_guess::CanUseAbility_guess(EQ_CharacterLeadershipView_guess* target,
	unsigned int action, int amount)
{
	bool result = false;
	if (target == 0 ||
		(target->flags_guess[target->state_guess->index_guess] & 0x40) == 0 ||
		!HasSharedRank_guess((TargetCheckData_guess*)target, action, amount)) {
		result = false;
	}
	else {
	switch (action) {
	case 0:
		if (target->HasGroupOfAtLeast_guess(3)) {
			if (target->IsGroupLeader_guess() || target->IsGroupMarkNpcDelegate_guess())
				result = true;
		}
		break;
	case 2:
		if (target->HasGroupOfAtLeast_guess(3)) {
			if (target->IsGroupLeader_guess() || target->IsGroupMainAssist_guess())
				result = true;
		}
		break;
	case 3:
	case 4:
	case 5:
		if (target->HasGroupOfAtLeast_guess(3) && target->IsGroupLeader_guess())
			result = true;
		break;
	case 1:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
		if (target->HasGroupOfAtLeast_guess(3))
			result = true;
		break;
	case 0x10:
		if ((target->CheckBase_guess() || target->IsRaidMarkNpcDelegate_guess()) &&
			target->HasRaidOfAtLeast_guess(0x12))
			result = true;
		break;
	case 0x11:
	case 0x16:
	case 0x17:
	case 0x18:
	case 0x19:
	case 0x1a:
	case 0x1b:
	case 0x1c:
	case 0x1d:
		if (target->HasRaidOfAtLeast_guess(0x12))
			result = true;
		break;
	case 0x12:
		if ((target->CheckBase_guess() || target->IsRaidMainAssist_guess()) &&
			target->HasRaidOfAtLeast_guess(0x12))
			result = true;
		break;
	case 0x13:
	case 0x14:
	case 0x15:
		if (target->CheckBase_guess() && target->HasRaidOfAtLeast_guess(0x12))
			result = true;
		break;
	default:
		result = false;
		break;
	}
	}
	return result;
}

struct SelectedActor_guess {
	char pad00_guess[0x120];
	char name_guess[0x124];
	unsigned char flag244_guess;
};

#define g_selectedActor_guess EQ_GLOBAL(SelectedActor_guess*, 0x00905D04)

struct NameTable_guess {
	// EXTERNAL: TITANIUM 0x004303A6 NameTable_guess::IsMember_guess
	bool IsMember_guess(const char* name);
	// EXTERNAL: TITANIUM 0x004314EA NameTable_guess::UpdateState_guess
	void UpdateState_guess(const char* name, int state);
	// EXTERNAL: TITANIUM 0x00431544 NameTable_guess::UpdateFlag_guess
	void UpdateFlag_guess(const char* name, int state);
	// EXTERNAL: TITANIUM 0x0043159E NameTable_guess::UpdateMode_guess
	void UpdateMode_guess(const char* name, int state);
};

#define g_nameTable_guess EQ_GLOBAL(NameTable_guess, 0x0091D708)

struct UiObject_guess {
	// EXTERNAL: TITANIUM 0x004C13D7 UiObject_guess::Cancel_guess
	void Cancel_guess();
	// EXTERNAL: TITANIUM 0x004C2566 UiObject_guess::FindGroupMember_guess
	void FindGroupMember_guess(SelectedActor_guess* actor);
	// EXTERNAL: TITANIUM 0x004C25AE UiObject_guess::FindRaidMember_guess
	void FindRaidMember_guess(SelectedActor_guess* actor);
};

#define g_uiObject_guess EQ_GLOBAL(UiObject_guess*, 0x00985C88)


struct ValueTable_guess {
	char pad00_guess[0x17c];
	SelectedActor_guess* values17c_guess[3];
	SelectedActor_guess* values188_guess[3];
};

struct ValueOwner_guess {
	char pad00_guess[0x1a8];
	ValueTable_guess* table_guess;
};

#define g_valueOwner_guess EQ_GLOBAL(ValueOwner_guess*, 0x00905CE4)

struct OpcodeArgs_guess {
	int kind_guess;
	int value_guess;
};

// EXTERNAL: TITANIUM 0x004912B1 SendPair_guess
void __cdecl SendPair_guess(void* owner, int opcode, void* args, int size, int flag);

// Uses leadership ability `kind` with `value` (a mark or assist slot). Group: 0 mark NPC, 3-5 delegate a role
// to the target, 6 inspect buffs, 13 find path, 14 target's-target window; raid 16, 18-21, 28, 29 likewise.
// Most go out as DoGroupLeadershipAbility (kind, value).
// FUNCTION: TITANIUM 0x004B4795
// @early-stop: budget, structural ndiff=346
void LeadershipManager_guess::UseAbility_guess(int kind, int value)
{
	switch (kind) {
	case 0xe:
		if (pinstCTargetOfTargetWnd_guess != 0 && pinstCTargetOfTargetWnd_guess->dShow != 0) {
			pinstCTargetOfTargetWnd_guess->Show(false, 1);
			return;
		}
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0xe, 1)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		if (pinstCTargetOfTargetWnd_guess != 0)
			pinstCTargetOfTargetWnd_guess->Show(pinstCTargetOfTargetWnd_guess->dShow == 0, 1);
		return;
	case 0:
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->IsGroupLeader_guess() && !g_errorCheck_guess->IsGroupMarkNpcDelegate_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x2234, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess == 0) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21b7, 0), 0xd, 1);
			break;
		}
		if (g_valueOwner_guess != 0 && g_valueOwner_guess->table_guess != 0 &&
			// Marking the NPC already in that slot sends slot 0: unmark.
			g_valueOwner_guess->table_guess->values17c_guess[value] == g_selectedActor_guess)
			value = 0;
		{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
	case 2:
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->IsGroupLeader_guess() && !g_errorCheck_guess->IsGroupMainAssist_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x2234, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 2, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
	case 3:
	case 4:
	case 5:
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->IsGroupLeader_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c8, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, kind, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess != 0 && g_selectedActor_guess->flag244_guess == 0 &&
			g_errorCheck_guess->IsAGroupMember_guess(g_selectedActor_guess->name_guess)) {
			ErrorPayload_guess payload;
			payload.value14_guess = 0;
			payload.value0c_guess = 0;
			payload.value04_guess = 0;
			payload.value10_guess = 0;
			// Role 0-2 for abilities 3-5, sent as DelegateAbility with the target's name.
			payload.value00_guess = kind == 3 ? 0 : (kind != 4) + 1;
			CopyErrorText_guess(payload.text_guess, g_selectedActor_guess->name_guess);
			SendError_guess(g_errorOwnerAddress_guess, OP_DelegateAbility, &payload, 0x5c, 1);
			return;
		}
		pEverQuest->dsp_chat(pStringTable->getString(0x222b, 0), 0xd, 1);
		break;
	case 6:
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 6, 1)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess != 0 && g_selectedActor_guess->flag244_guess == 0 &&
			g_errorCheck_guess->IsAGroupMember_guess(g_selectedActor_guess->name_guess)) {
			{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
		}
		pEverQuest->dsp_chat(pStringTable->getString(0x225d, 0), 0xd, 1);
		break;
	case 0xd:
		if (!g_errorCheck_guess->HasGroupOfAtLeast_guess(3)) {
			WarnGroupTooSmall_guess();
			return;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0xd, 1)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c2, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess != 0 && g_selectedActor_guess->flag244_guess == 0 &&
			g_errorCheck_guess->IsAGroupMember_guess(g_selectedActor_guess->name_guess)) {
			g_uiObject_guess->Cancel_guess();
			// Group Find Path to the target (g_uiObject_guess is the PlayerPath object).
			g_uiObject_guess->FindGroupMember_guess(g_selectedActor_guess);
			return;
		}
		pEverQuest->dsp_chat(pStringTable->getString(0x21d4, 0), 0xd, 1);
		break;
	case 0x10:
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->CheckBase_guess() && !g_errorCheck_guess->IsRaidMarkNpcDelegate_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x2233, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0x10, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c1, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess == 0) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21b7, 0), 0xd, 1);
			break;
		}
		if (g_valueOwner_guess != 0 && g_valueOwner_guess->table_guess != 0 &&
			g_valueOwner_guess->table_guess->values188_guess[value] == g_selectedActor_guess)
			value = 0;
		{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
	case 0x12:
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->CheckBase_guess() && !g_errorCheck_guess->IsRaidMainAssist_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x2233, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0x12, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c1, 0), 0xd, 1);
			break;
		}
		{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
	case 0x13:
	case 0x14:
	case 0x15:
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
		if (!g_errorCheck_guess->CheckBase_guess()) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c9, 0), 0xd, 1);
			break;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, kind, value)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c1, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess != 0 && g_selectedActor_guess->flag244_guess == 0 &&
			g_nameTable_guess.IsMember_guess(g_selectedActor_guess->name_guess)) {
			// Raid roles 3-5 also go out as RaidDelegateAbility first.
			SendRaidDelegateAbility_guess(kind == 0x13 ? 3 : (kind != 0x14) + 4,
				g_selectedActor_guess->name_guess);
			{
		OpcodeArgs_guess args;
		args.kind_guess = kind;
		args.value_guess = value;
		SendPair_guess(g_errorOwnerAddress_guess, OP_DoGroupLeadershipAbility, &args, 8, 1);
		return;
		}
		}
		pEverQuest->dsp_chat(pStringTable->getString(0x222c, 0), 0xd, 1);
		break;
	case 0x1c:
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0x1c, 1)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c1, 0), 0xd, 1);
			break;
		}
		if (g_selectedActor_guess != 0 && g_selectedActor_guess->flag244_guess == 0 &&
			g_nameTable_guess.IsMember_guess(g_selectedActor_guess->name_guess)) {
			g_uiObject_guess->Cancel_guess();
			g_uiObject_guess->FindRaidMember_guess(g_selectedActor_guess);
			return;
		}
		pEverQuest->dsp_chat(pStringTable->getString(0x21d4, 0), 0xd, 1);
		break;
	case 0x1d:
		if (pinstCTargetOfTargetWnd_guess != 0 && pinstCTargetOfTargetWnd_guess->dShow != 0) {
			pinstCTargetOfTargetWnd_guess->Show(false, 1);
			return;
		}
		if (!g_errorCheck_guess->HasRaidOfAtLeast_guess(0x12)) {
			WarnRaidTooSmall_guess();
			return;
		}
		if (!CanUseAbility_guess(g_errorCheck_guess, 0x1d, 1)) {
			pEverQuest->dsp_chat(pStringTable->getString(0x21c1, 0), 0xd, 1);
			break;
		}
		if (pinstCTargetOfTargetWnd_guess != 0)
			pinstCTargetOfTargetWnd_guess->Show(pinstCTargetOfTargetWnd_guess->dShow == 0, 1);
		return;
	default:
		return;
	}
}

// Whether the player's own rank of ability `index` (pCharData +0xBF0) is at least `threshold`.
// FUNCTION: TITANIUM 0x004B4E12
bool __stdcall CheckThreshold_guess(ThresholdData_guess* data,
	unsigned int index, int threshold)
{
	if (index >= 0x40)
		__debugbreak();
	return data->values[index] >= threshold;
}

// Health bonus 0/30/60/100 by the shared rank of ability 11, plus the same for 26 (EQEmu: Health
// Enhancement).
// FUNCTION: TITANIUM 0x004B4E35
int LeadershipManager_guess::GetHealthBonus_guess(EQ_CharacterLeadershipView_guess* target)
{
	int result = 0;
	if (target != 0 &&
		(target->flags_guess[target->state_guess->index_guess] & 0x40) != 0) {
		if (CanUseAbility_guess(target, 0xb, 1)) {
			int value;
			int level = target->value179c_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 0x1e;
			else
				value = level == 2 ? 0x3c : 0x64;
			result = value;
		}
		if (CanUseAbility_guess(target, 0x1a, 1)) {
			int value;
			int level = target->value1914_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 0x1e;
			else
				value = level == 2 ? 0x3c : 0x64;
			result += value;
		}
	}
	return result;
}

// The shared ranks of abilities 12 and 27 added up (EQEmu: Health Regeneration).
// FUNCTION: TITANIUM 0x004B4ED1
int LeadershipManager_guess::GetRegenBonus_guess(EQ_CharacterLeadershipView_guess* target)
{
	int result = 0;
	if (target != 0 &&
		(target->flags_guess[target->state_guess->index_guess] & 0x40) != 0) {
		if (CanUseAbility_guess(target, 0xc, 1))
			result = target->value17a0_guess;
		if (CanUseAbility_guess(target, 0x1b, 1))
			result += target->value1918_guess;
	}
	return result;
}

// 0/7/15/22/30/37 by the shared rank of ability 9, plus 24 (EQEmu: Offense Enhancement).
// FUNCTION: TITANIUM 0x004B4F25
int LeadershipManager_guess::GetOffenseBonus_guess(EQ_CharacterLeadershipView_guess* target)
{
	int result = 0;
	if (target != 0 &&
		(target->flags_guess[target->state_guess->index_guess] & 0x40) != 0) {
		if (CanUseAbility_guess(target, 9, 1)) {
			int value;
			int level = target->value1794_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 7;
			else if (level == 2)
				value = 0xf;
			else if (level == 3)
				value = 0x16;
			else
				value = level == 4 ? 0x1e : 0x25;
			result = value;
		}
		if (CanUseAbility_guess(target, 0x18, 1)) {
			int value;
			int level = target->value190c_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 7;
			else if (level == 2)
				value = 0xf;
			else if (level == 3)
				value = 0x16;
			else
				value = level == 4 ? 0x1e : 0x25;
			result += value;
		}
	}
	return result;
}

// Mana bonus 0/30/60/100 for abilities 10 and 25 (EQEmu: Mana Enhancement).
// FUNCTION: TITANIUM 0x004B4FE9
int LeadershipManager_guess::GetManaBonus_guess(EQ_CharacterLeadershipView_guess* target)
{
	int result = 0;
	if (target != 0 &&
		(target->flags_guess[target->state_guess->index_guess] & 0x40) != 0) {
		if (CanUseAbility_guess(target, 0xa, 1)) {
			int value;
			int level = target->value1798_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 0x1e;
			else
				value = level == 2 ? 0x3c : 0x64;
			result = value;
		}
		if (CanUseAbility_guess(target, 0x19, 1)) {
			int value;
			int level = target->value1910_guess;
			if (level == 0)
				value = 0;
			else if (level == 1)
				value = 0x1e;
			else
				value = level == 2 ? 0x3c : 0x64;
			result += value;
		}
	}
	return result;
}

// Whether rank `amount` of `action` is usable here: never for the passive ones (1, 7-12, 17, 22-27);
// otherwise own or shared rank, at most +8 of the definition.
// FUNCTION: TITANIUM 0x004B50AA
bool LeadershipManager_guess::CheckActionAmount_guess(EQ_CharacterLeadershipView_guess* target,
	unsigned int action, int amount)
{
	bool result = false;
	if (action == 1 || action == 7 || action == 8 || action == 9 ||
		action == 10 || action == 0xb || action == 0xc || action == 0x11 ||
		action == 0x16 || action == 0x17 || action == 0x18 || action == 0x19 ||
		action == 0x1a || action == 0x1b) {
		result = false;
	}
	else if (CheckThreshold_guess((ThresholdData_guess*)target, action, amount) &&
		amount <= elements[action]->value08_guess) {
		result = true;
	}
	else if (CanUseAbility_guess(target, action, amount) &&
		amount <= elements[action]->value08_guess) {
		result = true;
	}
	return result;
}

struct SpellData_guess {
	char pad00_guess[0x208];
	const char* name_guess;
};

struct SpellManager_guess {
	// EXTERNAL: TITANIUM 0x0040CBD6 SpellManager_guess::GetSpell_guess
	SpellData_guess* GetSpell_guess(int id);
};

#define g_spellManager_guess EQ_GLOBAL(SpellManager_guess*, 0x00985CC8)

struct PlayerView_guess : EQPlayer {
	// EXTERNAL: TITANIUM 0x0047D776 PlayerView_guess::RefreshNameSprite_guess
	void RefreshNameSprite_guess();
	// EXTERNAL: TITANIUM 0x004793B5 PlayerView_guess::GetDisplayedName_guess
	char* GetDisplayedName_guess();
};

struct ActorSlots_guess {
	char pad00_guess[0x170];
	PlayerView_guess* slots_guess[11];
};

struct CharView_guess {
	char pad0000_guess[0xe54];
	int value0e54_guess;
	char pad0e58_guess[0xea0 - 0xe58];
	int groupLeadershipPoints_0ea0_guess;
	int raidLeadershipPoints_0ea4_guess;
	char pad0ea8_guess[0x1870 - 0xea8];
	int groupRoles_1870_guess[(0x19ac - 0x1870) / 4];
	int raidRoles_19ac_guess[9];
	char pad19d0_guess[0xc288 - 0x19d0];
	PlayerView_guess* pSpawn_c288_guess;
	// EXTERNAL: TITANIUM 0x004586BF CharView_guess::SetValue_guess
	void SetValue_guess(int index, int value);
};

#define g_charView_guess EQ_GLOBAL(CharView_guess*, 0x00905D00)
#define g_localPlayer_guess EQ_GLOBAL(PlayerView_guess*, 0x00905CE4)

struct EverQuestView_guess {
	// EXTERNAL: TITANIUM 0x00492438 EverQuestView_guess::GetBodyTypeDesc
	const char* GetBodyTypeDesc(int deity);
};

#define g_everQuestView_guess EQ_GLOBAL(EverQuestView_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x00401B28 FindPlayer_guess
PlayerView_guess* __cdecl FindPlayer_guess(int id);

// EXTERNAL: TITANIUM 0x00416C2C ClassName_guess
const char* __cdecl ClassName_guess(int classId);

// EXTERNAL: TITANIUM 0x0046DA4A FormatMessage_guess
void __cdecl FormatMessage_guess(char* output, int messageId, const char* first,
	const char* second, int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* destination, const char* source);

struct OptionMessage_guess {
	int index_guess;
	int value04_guess;
	int value08_guess;
};

struct CopyMessage_guess {
	char pad00_guess[0x40];
	unsigned int values_guess[0x40];
};

struct DelegateAbilityMessage_guess {
	int kind_guess;
	int slot_guess;
	int remove_guess;
	int pad0c_guess[2];
	int value14_guess;
	int pad18_guess;
	char name_guess[0x40];
};

struct SlotMessage_guess {
	int id_guess;
	unsigned int slot_guess;
};

struct SpellTimers_guess {
	int ids_guess[25];
	int ticks_guess[25];
};

struct InfoMessage_guess {
	int level_guess;
	int classId_guess;
	int bodyType_guess;
	int spells_guess[60];
	int kind_guess;
	int flags100_guess;
	int flags104_guess;
};

// Leadership packets from the server.
// FUNCTION: TITANIUM 0x004B5145
// @early-stop: budget, structural ndiff=276
void LeadershipManager_guess::HandleLeadershipMessage_guess(void* connection, unsigned int opcode, void* data,
	unsigned int size)
{
	char message[256];
	char number[8];
	char text[256];
	char minutes[4];

	switch (opcode) {
	case OP_UpdateLeadershipAA: {
		OptionMessage_guess* msg = (OptionMessage_guess*)data;
		if (msg == 0)
			return;
		int index = msg->index_guess;
		if (index < 0 || index >= 31)
			return;
		if (IsGroupAbility_guess(index))
			// UpdateLeadershipAA: new rank of `index`; points left go to +0xEA0 (group) or +0xEA4 (raid).
			g_charView_guess->groupLeadershipPoints_0ea0_guess = msg->value08_guess;
		else
			g_charView_guess->raidLeadershipPoints_0ea4_guess = msg->value08_guess;
		g_charView_guess->SetValue_guess(index, msg->value04_guess);
		if (pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
		break;
	}
	case 0x844: {
		CopyMessage_guess* msg = (CopyMessage_guess*)data;
		if (msg != 0)
			// The raid leader's ranks.
			SetRaidLeaderRanks_guess((Target85_guess*)g_charView_guess, msg->values_guess);
		break;
	}
	case OP_DelegateAbility: {
		DelegateAbilityMessage_guess* msg = (DelegateAbilityMessage_guess*)data;
		switch (msg->kind_guess) {
		case 0:
			if (msg->remove_guess == 1) {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess] = 0;
				if (g_charView_guess->pSpawn_c288_guess != 0) {
					ActorSlots_guess* actor =
						(ActorSlots_guess*)g_charView_guess->pSpawn_c288_guess->pActorInfo;
					if (actor != 0)
						actor->slots_guess[msg->slot_guess] = 0;
				}
				// DelegateAbility: group role given (0x2245-0x2247) or taken (0x223F-0x2241); the
				// holder's id goes to pCharData +0x1870 (skills1870_guess is a misname).
				FormatMessage_guess(text, 0x223f, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess] = msg->value14_guess;
				FormatMessage_guess(text, 0x2245, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			break;
		case 1:
			if (msg->remove_guess == 1) {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess + 1] = 0;
				FormatMessage_guess(text, 0x2240, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess + 1] = msg->value14_guess;
				FormatMessage_guess(text, 0x2246, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			break;
		case 2:
			if (msg->remove_guess == 1) {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess + 2] = 0;
				FormatMessage_guess(text, 0x2241, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->groupRoles_1870_guess[msg->slot_guess + 2] = msg->value14_guess;
				FormatMessage_guess(text, 0x2247, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			break;
		}
		if (msg->value14_guess == g_charView_guess->value0e54_guess && pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
		break;
	}
	case OP_RaidClearNPCMarks:
		for (int i = 7; i < 10; ++i)
			((ActorSlots_guess*)g_charView_guess->pSpawn_c288_guess->pActorInfo)->slots_guess[i] = 0;
		break;
	case 0x23b9: {
		OptionMessage_guess* msg = (OptionMessage_guess*)data;
		switch (msg->value04_guess) {
		case 0:
			// Leadership notices 0-6: strings 0x224B-0x2250 and 0x2258.
			pEverQuest->dsp_chat(pStringTable->getString(0x224b, 0), 0xd, true);
			break;
		case 1:
			pEverQuest->dsp_chat(pStringTable->getString(0x224c, 0), 0xd, true);
			break;
		case 2:
			pEverQuest->dsp_chat(pStringTable->getString(0x224d, 0), 0xd, true);
			break;
		case 3:
			pEverQuest->dsp_chat(pStringTable->getString(0x224e, 0), 0xd, true);
			break;
		case 4:
			pEverQuest->dsp_chat(pStringTable->getString(0x224f, 0), 0xd, true);
			break;
		case 5:
			pEverQuest->dsp_chat(pStringTable->getString(0x2250, 0), 0xd, true);
			break;
		case 6:
			pEverQuest->dsp_chat(pStringTable->getString(0x2258, 0), 0xd, true);
			break;
		}
		break;
	}
	case OP_SetGroupTarget: {
		SlotMessage_guess* msg = (SlotMessage_guess*)data;
		if (msg == 0)
			return;
		int slot = msg->slot_guess;
		PlayerView_guess* player = FindPlayer_guess(msg->id_guess);
		PlayerView_guess** entry =
			// SetGroupTarget: the group assist target.
			&((ActorSlots_guess*)g_localPlayer_guess->pActorInfo)->slots_guess[slot];
		PlayerView_guess* old = *entry;
		*entry = player;
		if (old != 0)
			old->RefreshNameSprite_guess();
		if (player != 0)
			player->RefreshNameSprite_guess();
		break;
	}
	case OP_ClearNPCMarks:
		for (int i = 4; i < 7; ++i)
			((ActorSlots_guess*)g_charView_guess->pSpawn_c288_guess->pActorInfo)->slots_guess[i] = 0;
		break;
	case OP_InspectBuffs: {
		SpellTimers_guess* msg = (SpellTimers_guess*)data;
		if (msg->ids_guess[0] > 0) {
			pEverQuest->dsp_chat(pStringTable->getString(0x2260, 0), 0x14a, true);
			for (int i = 0; i < 25; ++i) {
				int id = msg->ids_guess[i];
				int ticks = msg->ticks_guess[i];
				if (id > 0) {
					SpellData_guess* spell = g_spellManager_guess->GetSpell_guess(id);
					if (spell != 0) {
						if (ticks > 0) {
							FormatMessage_guess(message, 0x225f, spell->name_guess,
								// Ticks are 6 s; this rounds to whole minutes.
								__itoa((ticks + 5) * 6 / 60, minutes, 10), 0, 0, 0, 0, 0, 0, 0);
							pEverQuest->dsp_chat(message, 0x14a, true);
						}
						else
							pEverQuest->dsp_chat(spell->name_guess, 0x14a, true);
					}
				}
			}
		}
		else
			pEverQuest->dsp_chat(pStringTable->getString(0x225e, 0), 0x14a, true);
		break;
	}
	case 0x4ffe: {
		SlotMessage_guess* msg = (SlotMessage_guess*)data;
		if (msg == 0)
			return;
		PlayerView_guess* player = FindPlayer_guess(msg->id_guess);
		if (player == 0)
			return;
		ActorSlots_guess* actor = (ActorSlots_guess*)g_localPlayer_guess->pActorInfo;
		if (msg->slot_guess == 0) {
			for (int i = 4; i < 7; ++i)
				if (actor->slots_guess[i] == player)
					actor->slots_guess[i] = 0;
			player->RefreshNameSprite_guess();
			FormatMessage_guess(message, 0x2261, player->GetDisplayedName_guess(), 0,
				0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		else if (msg->slot_guess >= 1 && msg->slot_guess <= 3) {
			// Group mark 1-3 (slots 4-6); slot 0 unmarks.
			PlayerView_guess* old = actor->slots_guess[msg->slot_guess + 3];
			for (int i = 4; i < 7; ++i)
				if (actor->slots_guess[i] == player)
					actor->slots_guess[i] = 0;
			actor->slots_guess[msg->slot_guess + 3] = player;
			char slotText[4];
			sprintf(slotText, "%d", msg->slot_guess);
			FormatMessage_guess(message, 0x21be, player->GetDisplayedName_guess(), slotText,
				0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
			if (old != 0 && old != player)
				old->RefreshNameSprite_guess();
			player->RefreshNameSprite_guess();
		}
		break;
	}
	case OP_MarkNPC: {
		SlotMessage_guess* msg = (SlotMessage_guess*)data;
		if (msg == 0)
			return;
		PlayerView_guess* player = FindPlayer_guess(msg->id_guess);
		if (player == 0)
			return;
		ActorSlots_guess* actor = (ActorSlots_guess*)g_localPlayer_guess->pActorInfo;
		if (msg->slot_guess == 0) {
			for (int i = 7; i < 10; ++i)
				if (actor->slots_guess[i] == player)
					actor->slots_guess[i] = 0;
			player->RefreshNameSprite_guess();
			FormatMessage_guess(message, 0x2261, player->GetDisplayedName_guess(), 0,
				0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		else if (msg->slot_guess >= 1 && msg->slot_guess <= 3) {
			// MarkNPC fills the raid marks (slots 7-9, which RaidClearNPCMarks clears), so
			// EQEmu's group-sounding name does not fit this client.
			PlayerView_guess* old = actor->slots_guess[msg->slot_guess + 6];
			for (int i = 7; i < 10; ++i)
				if (actor->slots_guess[i] == player)
					actor->slots_guess[i] = 0;
			actor->slots_guess[msg->slot_guess + 6] = player;
			char slotText[4];
			sprintf(slotText, "%d", msg->slot_guess);
			FormatMessage_guess(message, 0x21be, player->GetDisplayedName_guess(), slotText,
				0, 0, 0, 0, 0, 0, 0);
			// Default colour here, unlike the group-mark case.
			pEverQuest->dsp_chat(message);
			if (old != 0 && old != player)
				old->RefreshNameSprite_guess();
			player->RefreshNameSprite_guess();
		}
		break;
	}
	case OP_RaidDelegateAbility: {
		DelegateAbilityMessage_guess* msg = (DelegateAbilityMessage_guess*)data;
		switch (msg->kind_guess) {
		case 3:
			if (msg->remove_guess == 1) {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess] = 0;
				if (g_charView_guess->pSpawn_c288_guess != 0) {
					ActorSlots_guess* actor =
						(ActorSlots_guess*)g_charView_guess->pSpawn_c288_guess->pActorInfo;
					if (actor != 0)
						actor->slots_guess[msg->slot_guess + 1] = 0;
				}
				// RaidDelegateAbility: raid roles 3-5 (given 0x2248-0x224A, taken 0x2242-0x2244) at
				// pCharData +0x19AC, mirrored into CRaid's member flags.
				FormatMessage_guess(text, 0x2242, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess] = msg->value14_guess;
				FormatMessage_guess(text, 0x2248, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			g_nameTable_guess.UpdateState_guess(msg->name_guess, msg->remove_guess == 0);
			break;
		case 4:
			if (msg->remove_guess == 1) {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess + 3] = 0;
				FormatMessage_guess(text, 0x2243, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess + 3] = msg->value14_guess;
				FormatMessage_guess(text, 0x2249, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			g_nameTable_guess.UpdateFlag_guess(msg->name_guess, msg->remove_guess == 0);
			break;
		case 5:
			if (msg->remove_guess == 1) {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess + 6] = 0;
				FormatMessage_guess(text, 0x2244, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				g_charView_guess->raidRoles_19ac_guess[msg->slot_guess + 6] = msg->value14_guess;
				FormatMessage_guess(text, 0x224a, msg->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			pEverQuest->dsp_chat(text, 0x14a, true);
			g_nameTable_guess.UpdateMode_guess(msg->name_guess, msg->remove_guess == 0);
			break;
		}
		if (msg->value14_guess == g_charView_guess->value0e54_guess && pinstCLeadershipWnd_guess != 0)
			pinstCLeadershipWnd_guess->UpdateRows_guess();
		break;
	}
	case 0x5871: {
		SlotMessage_guess* msg = (SlotMessage_guess*)data;
		if (msg == 0)
			return;
		int slot = msg->slot_guess;
		PlayerView_guess* player = FindPlayer_guess(msg->id_guess);
		PlayerView_guess** entry =
			// Raid assist target 1-3.
			&((ActorSlots_guess*)g_localPlayer_guess->pActorInfo)->slots_guess[slot + 1];
		PlayerView_guess* old = *entry;
		*entry = player;
		if (old != 0)
			old->RefreshNameSprite_guess();
		if (player != 0)
			player->RefreshNameSprite_guess();
		break;
	}
	case OP_TargetHoTT: {
		SlotMessage_guess* msg = (SlotMessage_guess*)data;
		// TargetHoTT: the target's target.
		((ActorSlots_guess*)g_charView_guess->pSpawn_c288_guess->pActorInfo)->slots_guess[10] =
			FindPlayer_guess(msg->id_guess);
		break;
	}
	case 0x7822: {
		CopyMessage_guess* msg = (CopyMessage_guess*)data;
		if (msg != 0)
			// The group leader's ranks.
			SetGroupLeaderRanks_guess((Target79_guess*)g_charView_guess, msg->values_guess);
		break;
	}
	case 0x7a75: {
		InfoMessage_guess* msg = (InfoMessage_guess*)data;
		message[0] = 0;
		if (msg == 0)
			return;
		// An NPC report: level and class, body type, spells (rank 3 of ability 7 or 22), then
		// two flag lists.
		if (msg->level_guess > 0 && msg->classId_guess > 0) {
			FormatMessage_guess(message, 0x2256, __itoa(msg->level_guess, number, 10),
				ClassName_guess(msg->classId_guess), 0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		if (msg->bodyType_guess > 0) {
			// Body type, not deity: 0x492438 is CEverQuest::GetBodyTypeDesc.
			FormatMessage_guess(message, 0x223e,
				g_everQuestView_guess->GetBodyTypeDesc(msg->bodyType_guess), 0,
				0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		if (CanUseAbility_guess(g_errorCheck_guess, 7, 3) ||
			CanUseAbility_guess(g_errorCheck_guess, 0x16, 3)) {
			text[0] = 0;
			bool found = false;
			for (int i = 0; i < 60; ++i) {
				if (msg->spells_guess[i] > 0) {
					SpellData_guess* spell =
						g_spellManager_guess->GetSpell_guess(msg->spells_guess[i]);
					if (spell != 0) {
						found = true;
						strcat(text, spell->name_guess);
						strcat(text, " ");
					}
				}
			}
			if (found) {
				FormatMessage_guess(message, 0x2237, text, 0, 0, 0, 0, 0, 0, 0, 0);
				pEverQuest->dsp_chat(message, 0x14a, true);
			}
			else
				pEverQuest->dsp_chat(pStringTable->getString(0x2236, 0), 0x14a, true);
		}
		if (msg->kind_guess > 0) {
			int kind = msg->kind_guess;
			int flags = msg->flags100_guess;
			text[0] = 0;
			int id;
			if (kind == 3)
				id = 0x21e9;
			else if (kind == 2)
				id = 0x2257;
			else
				id = kind == 1 ? 0x21ea : 0x21eb;
			if (flags & 1) {
				strcat(text, pStringTable->getString(0x21e2, 0));
				strcat(text, " ");
			}
			if (flags & 2) {
				strcat(text, pStringTable->getString(0x21e3, 0));
				strcat(text, " ");
			}
			if (flags & 4) {
				strcat(text, pStringTable->getString(0x21e5, 0));
				strcat(text, " ");
			}
			if (flags & 8) {
				strcat(text, pStringTable->getString(0x21e4, 0));
				strcat(text, " ");
			}
			if (flags & 0x10) {
				strcat(text, pStringTable->getString(0x21e6, 0));
				strcat(text, " ");
			}
			FormatMessage_guess(message, id, text, 0, 0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		int flags = msg->flags104_guess;
		if (flags > 0) {
			text[0] = 0;
			if (flags & 1) {
				strcat(text, pStringTable->getString(0x2238, 0));
				strcat(text, " ");
			}
			if (flags & 2) {
				strcat(text, pStringTable->getString(0x223b, 0));
				strcat(text, " ");
			}
			if (flags & 4) {
				strcat(text, pStringTable->getString(0x2239, 0));
				strcat(text, " ");
			}
			if (flags & 8) {
				strcat(text, pStringTable->getString(0x223a, 0));
				strcat(text, " ");
			}
			if (flags & 0x10) {
				strcat(text, pStringTable->getString(0x223c, 0));
				strcat(text, " ");
			}
			FormatMessage_guess(message, 0x2251, text, 0, 0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(message, 0x14a, true);
		}
		break;
	}
	}
}

// Cost of the next rank of ability `index`: own rank * step (+0x28) + base (+0x24).
// FUNCTION: TITANIUM 0x004B5085
// @early-stop: budget, structural ndiff=4
int LeadershipManager_guess::GetNextRankCost_guess(ThresholdData_guess* target, unsigned int index)
{
	if (index >= 0x40)
		__debugbreak();
	LeadershipAbility_guess* element = elements[index];
	return target->values[index] * element->multiplier_guess + element->base_guess;
}

// Whether the player can buy the next rank: purchasable, below the cap (+0x34), and enough group (+0xEA0)
// or raid (+0xEA4) points.
// FUNCTION: TITANIUM 0x004B5EB1
// @early-stop: budget, structural ndiff=29
int LeadershipManager_guess::CanBuyNextRank_guess(ThresholdData_guess* target, unsigned int index)
{
	if (target != 0) {
		LeadershipAbility_guess*& element = elements[index];
		if (element->flag != 0) {
			if (index >= 0x40)
				__debugbreak();
			if (target->values[index] < element->threshold) {
				if (element->state == 1) {
					int value = target->valueEA0_guess;
					if (value >= GetNextRankCost_guess(target, index))
						return 1;
				}
				if (element->state == 2) {
					int value = target->valueEA4_guess;
					if (value >= GetNextRankCost_guess(target, index))
						return 1;
				}
			}
		}
	}
	return 0;
}

// Stamps the position history's last update with the current tick count.
// FUNCTION: TITANIUM 0x004B5F2A
void PositionHistory_guess::UpdateTick_guess()
{
	lastUpdate = g_getTickCount_guess();
}

// A ring of the player's last 30 positions (static at 0x985A08).
// FUNCTION: TITANIUM 0x004B5F3B
PositionHistory_guess::PositionHistory_guess()
{
	VectorConstructorIterator_guess(this, 0x0c, 0x1e,
		(ElementConstructorFunction_guess)g_constructElementAddress_guess);
	lastUpdate = 0;
	flag = 0;
}

// Records a position once the player has moved more than 1 unit from the last one.
// FUNCTION: TITANIUM 0x004B5F5F
void BulkDataOwner_guess::Add_guess(const CopyRecord_guess* source, float value)
{
	CopyRecord_guess* last = &records[flag0];
	if (last->Distance_guess(source) > 1.0f) {
		flag0 = (flag0 + 1) % 0x1e;
		CopyRecord_guess* dest = &records[flag0];
		dest->values[0] = source->values[0];
		dest->values[1] = source->values[1];
		dest->values[2] = source->values[2];
		((float*)values)[flag0] = value;
		((PositionHistory_guess*)this)->UpdateTick_guess();
		flag1 = 1;
	}
}

// The oldest recorded position.
// FUNCTION: TITANIUM 0x004B5FD9
void BulkDataOwner_guess::Get_guess(SharedValues_guess* record, float* value)
{
	int index = (flag0 + 1) % 0x1e;
	SharedValues_guess* source = ((SharedValues_guess*)records) + index;
	record->first = source->first;
	record->second = source->second;
	record->third = source->third;
	*value = ((float*)values)[index];
}

// Fills the whole ring with one position.
// FUNCTION: TITANIUM 0x004B6015
void BulkDataOwner_guess::Copy_guess(const unsigned int* source, float value)
{
	flag0 = 0;
	for (int i = 0; i < 30; ++i) {
		records[i].values[0] = source[0];
		records[i].values[1] = source[1];
		records[i].values[2] = source[2];
		values[i] = *(unsigned int*)&value;
	}
	flag1 = 0;
}

// The player's position (pinstLocalPlayer +0x30) and its float at +0x40, probably the heading.
// FUNCTION: TITANIUM 0x004B605B
void __stdcall CopySharedValues_guess(SharedValues_guess* output, float* last)
{
	unsigned int* values = (unsigned int*)g_sharedSource_guess;
	values += 12;
	output->first = *(float*)values;
	output->second = values[1];
	output->third = values[2];
	*last = g_sharedSource_guess->last_guess;
}

// The position history singleton (a function-local static).
// FUNCTION: TITANIUM 0x004B6088
PositionHistory_guess* __cdecl GetSharedOwner_guess()
{
	static PositionHistory_guess owner;
	return &owner;
}

// Resets the ring to where the player stands.
// FUNCTION: TITANIUM 0x004B60C2
void PositionHistory_guess::UpdateSharedValues_guess()
{
	SharedValues_guess values;
	float last;
	CopySharedValues_guess(&values, &last);
	((BulkDataOwner_guess*)this)->Copy_guess((const unsigned int*)&values, last);
	UpdateTick_guess();
}

// Records where the player stands, if moved.
// FUNCTION: TITANIUM 0x004B60F2
void PositionHistory_guess::AddSharedValues_guess()
{
	SharedValues_guess values;
	float last;
	CopySharedValues_guess(&values, &last);
	((BulkDataOwner_guess*)this)->Add_guess((const CopyRecord_guess*)&values, last);
}

// Connects to `request` (60 s timeout) and polls every 100 ms until the handshake settles; 1 on failure.
// FUNCTION: TITANIUM 0x004B611D
int __cdecl ConnectToHost_guess(ConnectRequest_guess* request)
{
	int* status = (int*)&g_activeConnection_guess;
	g_authenticationState_guess->Reset_guess(status);
	g_activeConnection_guess = g_authenticationState_guess->Connect_guess(
		request->host_guess, request->port_guess, 60000);
	if (g_activeConnection_guess == 0) {
		Log_guess("Failed to establish connection to %s:%d\n",
			request->host_guess, request->port_guess);
		return 1;
	}

	int negotiations = 0;
	int result;
	while (g_activeConnection_guess != 0) {
		result = g_activeConnection_guess->Poll_guess();
		if (result != 0)
			break;
		++negotiations;
		Delay_guess(100);
	}

	if (g_activeConnection_guess == 0 ||
		g_activeConnection_guess->Poll_guess() != 1) {
		// Also reached with a null connection, which the version calls then dereference.
		Log_guess("Could not connect to %s:%d [client:%s,server:%s].  Negotiation count: %d.\n",
			request->host_guess, request->port_guess,
			VersionName_guess(g_activeConnection_guess->GetClientVersion_guess()),
			VersionName_guess(g_activeConnection_guess->GetServerVersion_guess()),
			negotiations);
		g_authenticationState_guess->Reset_guess(status);
		return 1;
	}
	return 0;
}

// Ms since the last world message; the first call starts the clock.
// FUNCTION: TITANIUM 0x004B6200
int WorldAuthenticate_guess::Elapsed_guess()
{
	if (lastTick_guess == 0)
		lastTick_guess = GetTickValue_guess();
	return GetTickValue_guess() - lastTick_guess;
}

// World connection dropped during world login: clears the caller's connection (*+4), sets the login
// failure code to 1 and the rejected flag (+0x10) that makes the login loop retry up to twice more
// (logging the rejection), then sets the connection to state 1.
// FUNCTION: TITANIUM 0x004B621B
void WorldAuthenticate_guess::ConnectionLost_guess(Connection_guess* connection)
{
	*status_guess = 0;
	Log_guess("WorldAuthenticate: connection lost during authentication.\n");
	g_worldState_guess->authenticationLost_guess = 1;
	lost_guess = 1;
	connection->SetState_guess(1);
}

// World messages during login (Mac: WorldAuthenticate). LogServer fills the world-server info and flags
// (0x923D64 is the ticket-service flag tu_093 also sets); PostEnterWorld grants access.
// FUNCTION: TITANIUM 0x004B624F
// @early-stop: budget, structural ndiff=29
void WorldAuthenticate_guess::WorldAuthenticate(int ignored_guess,
	unsigned short* message_guess, int size_guess)
{
	lastTick_guess = GetTickValue_guess();
	size_guess -= 2;
	int opcode_guess = *message_guess;
	unsigned short* payload_guess = message_guess + 1;
	Log_guess("WorldAuthenticate.  I got a message of type 0x%x (%d).",
		opcode_guess, opcode_guess);

	switch (opcode_guess) {
	case OP_ExpansionInfo:
		ReadWorldFlags_guess(payload_guess);
		break;
	case 0x0504:
		Log_guess("WorldAuthenticate.  P Update\n");
		UpdatePetitionQueue_guess(payload_guess);
		break;
	case OP_LogServer: {
		WorldPayload_guess* payload = (WorldPayload_guess*)payload_guess;
		unsigned int address_guess = payload->value04_guess;
		g_worldRouteAddress_guess = address_guess;
		unsigned int port_guess = payload->value00_guess;
		g_worldRoutePort_guess = port_guess;
		g_worldServerAddress_guess = address_guess;
		g_worldServerPort_guess = port_guess;
		g_worldServerValue08_guess = payload->value08_guess;
		g_worldServerValue0c_guess = payload->value0c_guess;
		g_worldServerValue10_guess = payload->value10_guess;
		g_worldServerValue14_guess = payload->value14_guess;
		CopyErrorText_guess(g_worldServerName_guess, payload->serverName_guess);
		Log_guess("WorldRPServer message: server name %s\n", payload->serverName_guess);
		g_worldFlag0_guess = payload->flagf4_guess;
		g_worldFlag1_guess = payload->flagf5_guess;
		g_worldFlag2_guess = payload->flag104_guess;
		g_worldFlag3_guess = payload->flag106_guess;
		g_worldFlag4_guess = payload->flag105_guess;
		g_worldFlag5_guess = payload->flag107_guess;
		break;
	}
	case OP_ApproveWorld:
		UpdateWorldConnection_guess(payload_guess, *status_guess);
		break;
	case OP_SendCharInfo:
		Handle_OP_SendCharInfo_guess(*status_guess, 0x4513, payload_guess, size_guess);
		break;
	case OP_PostEnterWorld:
		*accessGranted_guess = 1;
		Log_guess("WorldAuthenticate.  Access granted.\n");
		break;
	case OP_CharacterStillInZone:
		Handle_OP_CharacterStillInZone_guess();
		break;
	case OP_GuildsList:
		g_worldMessageProcessor_guess.Dispatch_guess(*status_guess, 0x6957,
			payload_guess, size_guess);
		break;
	case OP_EnterWorld:
		CopyErrorText_guess(EQ_ARRAY(char, 0x00905C18), (const char*)payload_guess);
		break;
	case OP_WorldChecksumFailure:
		Log_guess("World disconnecting because the checksums didn't match.\n");
		break;
	case OP_WorldLoginFailed:
		g_authenticationState_guess->Reset_guess(status_guess);
		if (g_loginDialogFlag_guess == 0)
			MessageBoxA(0, "Invalid Login or Password", "EverQuest", 0x40000);
		g_worldAuthenticationStatus_guess = 0;
		*invalidLogin_guess = 1;
		Log_guess("*** ERROR: WorldAuthenticate.  Invalid Login or Password.\n");
		break;
	default:
		Log_guess("*** ERROR: WorldAuthenticate.  ??? UNKNOWN MESSAGE \n");
		break;
	}
}

// Handle_OP_CharacterStillInZone: the last character is still held by a zone; fails the login (status 2).
// FUNCTION: TITANIUM 0x004B646E
void WorldAuthenticate_guess::Handle_OP_CharacterStillInZone_guess()
{
	g_authenticationState_guess->Reset_guess(status_guess);
	g_worldState_guess->authenticationLost_guess = 2;
	lost_guess = 1;
	Log_guess("*** ERROR: WorldAuthenticate.  WorldServer says that my last played character has not been released by the zone.");
}

// EXTERNAL: TITANIUM 0x00435A2A ShowErrorDialog_guess
void __cdecl ShowErrorDialog_guess(int instance, int owner, const char* title, const char* text);

// EXTERNAL: TITANIUM 0x0040BE64 Guard_guess
void __stdcall Guard_guess(void* scope);

// EXTERNAL: TITANIUM 0x005EB5B0 Pump_guess
void __stdcall Pump_guess(int milliseconds);

// EXTERNAL: TITANIUM 0x00464C4B ConcatenateStringsWithSeparators_guess
void __cdecl ConcatenateStringsWithSeparators_guess(void* output, const char* name, const char* password, const char* extra);

// EXTERNAL: TITANIUM 0x004912B1 SendLogin_guess
void __cdecl SendLogin_guess(Connection_guess** owner, int opcode, void* payload, int size, int flag);

struct ConnectionReady_guess {
	// EXTERNAL: TITANIUM 0x00490FDF ConnectionReady_guess::IsReady_guess
	int IsReady_guess();
};

struct AuthenticationFlags_guess {
	char pad00_guess[0x4c];
	int value4c_guess;
};

#define g_authenticationFlags_guess EQ_GLOBAL(AuthenticationFlags_guess*, 0x0079DBD8)
#define g_loginFlag_guess EQ_GLOBAL(unsigned char, 0x00923D7A)
#define g_host_guess EQ_ARRAY(char, 0x00904104)
#define g_port_guess EQ_GLOBAL(int, 0x00904204)
#define g_account_guess EQ_ARRAY(char, 0x00904004)
#define g_password_guess EQ_ARRAY(char, 0x00904084)
#define g_keycode_guess EQ_ARRAY(char, 0x00904184)
#define g_empty_guess EQ_ARRAY(char, 0x0063F53F)

// Same layout as WorldAuthenticate_guess, with its vtable at +0.
// EXTERNAL: TITANIUM 0x0064B138 ??_7WorldAuthScope_guess@@6B@
struct WorldAuthScope_guess {
	virtual void Slot00_guess();
	int* status_guess;
	int* reply_guess;
	int* timedOut_guess;
	unsigned char lost_guess;
	int lastTick_guess;
};

struct LoginPacket_guess {
	char credentials_guess[0xba];
	unsigned char flag_guess;
	char pad_guess;
	unsigned int value_guess;
	unsigned short tail_guess;
	char pad2_guess[0x1d0 - 0xc2];
};

struct KeycodePacket_guess {
	char name_guess[64];
	char password_guess[32];
	char keycode_guess[292];
};

// Connects to the world server and logs in: SendLoginInfo (account, password), or with a keycode of 25+
// chars the keycode login (0x184 bytes). Gives up after 3 rejections or 30 s without an answer. Returns the
// connection, or 0.
// FUNCTION: TITANIUM 0x004B649F
// @early-stop: budget, diff ndiff=147
int __cdecl AuthenticateWorld_guess(int owner_guess, int instance_guess)
{
	Connection_guess* connection = 0;
	int reply = 0;
	int timedOut = 0;
	int retries = 0;
	WorldAuthScope_guess auth;
	auth.status_guess = (int*)&connection;
	auth.reply_guess = &reply;
	auth.timedOut_guess = &timedOut;
	auth.lost_guess = 0;
	auth.lastTick_guess = 0;
	const char* title = "Can't Connect to Server";
	do {
		if (g_worldAuthenticationStatus_guess == 0) {
			if (g_loginDialogFlag_guess != 0)
				Log_guess("*** WorldAuthenticate.  Checkpoint 3.");
			g_worldAuthenticationStatus_guess = 1;
			g_worldState_guess->authenticationLost_guess = 1;
			return 0;
		}
		timedOut = 0;
		connection = g_authenticationState_guess->Connect_guess(g_host_guess, g_port_guess, 60000);
		if (connection == 0) {
			Log_guess("*** WorldAuthenticate.  Error connecting to %s:%d.", g_host_guess, g_port_guess);
			if (g_loginDialogFlag_guess != 0) {
				g_worldState_guess->authenticationLost_guess = 1;
				Log_guess("*** ERROR: WorldAuthenticate has failed establishing the connection.");
				return 0;
			}
			g_worldAuthenticationStatus_guess = 0;
			ShowErrorDialog_guess(instance_guess, owner_guess, title,
				"Try Again Later.  Cause May Be: \n\n1> Server Down  \n2> Your Internet Connection Down  \n3> Firewall/Network Problem Exists");
		}
		else {
			while (connection->Poll_guess() == 0)
				Delay_guess(50);
			if (connection->Poll_guess() != 1) {
				Log_guess("*** WorldAuthenticate.  Error connecting to %s:%d [client:%s,server:%s]\n",
					g_host_guess, g_port_guess,
					VersionName_guess(connection->GetClientVersion_guess()),
					VersionName_guess(connection->GetServerVersion_guess()));
				g_authenticationState_guess->Reset_guess((int*)&connection);
				if (g_loginDialogFlag_guess != 0) {
					g_worldState_guess->authenticationLost_guess = 1;
					Log_guess("*** ERROR: WorldAuthenticate has failed after attempting to connect.");
					return 0;
				}
				g_worldAuthenticationStatus_guess = 0;
				ShowErrorDialog_guess(instance_guess, owner_guess, title,
					"Try Again Later.  Cause May Be: \n\n1> Server Down  \n2> Your Internet Connection Down  \n3> Firewall/Network Problem Exists");
			}
			else {
				auth.lost_guess = 0;
				auth.lastTick_guess = 0;
				Guard_guess(&auth);
				if (strlen(g_keycode_guess) < 0x19) {
					if (strlen(g_password_guess) < 4) {
						if (g_loginDialogFlag_guess == 0)
							MessageBoxA(0, "Passwords must be at least 4 characters long.", "EverQuest", 0x40000);
						g_worldAuthenticationStatus_guess = 0;
						Log_guess("*** ERROR: Password entered was less than four characters. ldialog.laccount < 25.");
						g_worldState_guess->authenticationLost_guess = 1;
						continue;
					}
					else {
						LoginPacket_guess login;
						memset(&login, 0, 0x1d0);
						ConcatenateStringsWithSeparators_guess(&login, g_account_guess, g_password_guess, g_empty_guess);
						login.value_guess = g_loginFlag_guess;
						login.flag_guess = 0;
						login.tail_guess = 0xcc;
						Log_guess("WorldAuthenticate: Initiating Login.");
						SendLogin_guess(&connection, OP_SendLoginInfo, &login, 0x1d0, 1);
						if (connection == 0)
							Log_guess("*** ERROR: WorldAuthenticate.  Failed to send MSG_LOGIN.");
					}
				}
				else {
					if (strlen(g_password_guess) > 3) {
						KeycodePacket_guess keys;
						CopyErrorText_guess(keys.name_guess, g_account_guess);
						CopyErrorText_guess(keys.password_guess, g_password_guess);
						CopyErrorText_guess(keys.keycode_guess, g_keycode_guess);
						Log_guess("WorldAuthenticate.  Sending keycode.");
						SendLogin_guess(&connection, 0x34c7, &keys, 0x184, 1);
						if (connection == 0)
							Log_guess("*** ERROR: WorldAuthenticate.  Failed to send MSG_LOGIN_KEYCODE.");
					}
					else {
						if (g_loginDialogFlag_guess == 0)
							MessageBoxA(0, "Passwords must be at least 4 characters long.", "EverQuest", 0x40000);
						g_worldAuthenticationStatus_guess = 0;
						Log_guess("*** ERROR: Password entered was less than four characters.ldialog.laccount > 25.");
						g_worldState_guess->authenticationLost_guess = 1;
						continue;
					}
				}
				if (reply != 0)
					break;
				do {
					if (timedOut != 0 || connection == 0 ||
						((ConnectionReady_guess*)connection)->IsReady_guess() == 1)
						break;
					Delay_guess(50);
					if (g_authenticationFlags_guess->value4c_guess != 0)
						Pump_guess(500);
					if (auth.lost_guess != 0) {
						Delay_guess(1000);
						retries = retries + 1;
						if (retries > 2) {
							Log_guess("Rejected By World. abort abort\n");
							return 0;
						}
						Log_guess("Rejected By World. retrying\n");
						g_worldState_guess->authenticationLost_guess = 0;
						break;
					}
					unsigned int elapsed = (unsigned int)((WorldAuthenticate_guess*)&auth)->Elapsed_guess();
					if (elapsed > 30000) {
						if (connection != 0)
							g_authenticationState_guess->Reset_guess((int*)&connection);
						if (g_loginDialogFlag_guess == 0)
							ShowErrorDialog_guess(instance_guess, owner_guess, title,
								"Try Again Later.  Cause May Be: \n\n1> Server Down  \n2> Your Internet Connection Down  \n3> Firewall/Network Problem Exists");
						timedOut = 1;
						Log_guess("*** ERROR: WorldAuthenticate.  My message arrival was NULL, the net has been shutdown.");
						if (owner_guess == 0) {
							g_worldState_guess->authenticationLost_guess = 1;
							Log_guess("*** ERROR: WorldAuthenticate. world isn't there.");
							return 0;
						}
						g_worldAuthenticationStatus_guess = 0;
					}
				} while (reply == 0);
			}
		}
	} while (reply == 0);
	if (connection != 0 && reply == 0) {
		Log_guess("*** ERROR: WorldAuthenticate.  This connection failed its authentication.");
		g_authenticationState_guess->Reset_guess((int*)&connection);
	}
	return (int)connection;
}

