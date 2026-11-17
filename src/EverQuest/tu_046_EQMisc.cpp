// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 46: a hint from compare/tumap.py.
// Slash-command handlers (the do_*/cmd_* targets of the slash-command table; EQMisc.cpp in the earlier sibling
// decomp) and the socials, plus the helpers EQMisc keeps beside them: inventory/material slot maps, group-name
// records, the teleport-index loader, physics pack/unpack, RandNbr (lagged Fibonacci), combat hit/miss
// messages, missile hits and spell-description text. gConnection_guess (0x905CE4) is the local player,
// gIncomingMessage_guess (0x905D04) the target and gFriendsList_guess (0x95A1B4) the friends list.
#include "titanium/eqaddr.h"
#include "titanium/bounded_array.h"
#include "titanium/types.h"
#include "titanium/slots.h"
#include "titanium/classes.h"
#include "titanium/opcodes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <new>
#include <winsock2.h>
#include <windows.h>
#include <mmsystem.h>
#include "titanium/wnd/CBarterWnd.h"
#include "titanium/wnd/CBazaarSearchWnd.h"
#include "titanium/wnd/CFriendsWnd.h"
#include "titanium/wnd/CGuildBankWnd.h"
#include "titanium/wnd/CGuildManagementWnd.h"
#include "titanium/wnd/CLoadskinWnd.h"
#include "titanium/wnd/CSoulmarkWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CBarterSearchWnd.h"
#include "titanium/wnd/CBazaarWnd.h"
#include "titanium/wnd/CBodyTintWnd.h"
#include "titanium/wnd/CCastSpellWnd.h"
#include "titanium/wnd/CCursorAttachment.h"
#include "titanium/wnd/CGemsGameWnd.h"
#include "titanium/wnd/CGiveWnd.h"
#include "titanium/wnd/CGroupSearchWnd.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/COptionsWnd.h"
#include "titanium/wnd/CRaidWnd.h"
#include "titanium/wnd/CTicketWnd.h"
#include "titanium/wnd/CTrackingWnd.h"
#include "titanium/wnd/CTradeWnd.h"
#include "titanium/wnd/CTradeskillWnd.h"

struct RefObject_464C94_guess;
struct Slot_474597_guess;
struct Holder_474597_guess;
struct Table_475855_guess;
struct DateText_guess;
struct Spawn_472313_guess;

struct Actor_472313_guess {
    char pad_000_guess[0xc8];
    float z_c8_guess;
    char pad_0cc_guess[0x90];
    Spawn_472313_guess* spawn_15c_guess;
    char pad_160_guess[0xe88];
    Spawn_472313_guess* spawn_fe8_guess;
};

struct Spawn_472313_guess {
    char pad_000_guess[0x48];
    float speedRun_0048_guess;
    char pad_04c_guess[0xd4];
    char name_120_guess[0x40];
    char pad_160_guess[0x48];
    Actor_472313_guess* actor_1a8_guess;
    char pad_1ac_guess[0x6];
    unsigned char linkdead_01b2_guess;
    char pad_1b3_guess[0x91];
    unsigned char type_244_guess;
    char pad_245_guess[0xb];
    unsigned char anonymous_250_guess;
    char standState_0251_guess;
    char pad_252_guess[6];
    unsigned short spawnId_0258_guess;
    // EXTERNAL: TITANIUM 0x0047C10D Spawn_472313_guess::SetHideMode_guess
    void SetHideMode_guess(bool value_guess);
    // EXTERNAL: TITANIUM 0x004793B5 Spawn_472313_guess::GetNameText_guess
    const char* GetNameText_guess();
};

#define gTarget_472313_guess EQ_GLOBAL(Spawn_472313_guess*, 0x00905D04)
#define gLocal_472313_guess EQ_GLOBAL(Spawn_472313_guess*, 0x00905CE4)
#define gControlled_472313_guess EQ_GLOBAL(Spawn_472313_guess*, 0x00905CF8)

struct MessagePacket_46ee28_guess {
    char text_000_guess[0x40];
    char text_040_guess[0x40];
    char text_080_guess[0x44];
    int value_0c4_guess;
};

void __cdecl ConvertItemTags(CXStr* text_guess, char expand_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 _atol
long __cdecl atol(const char* text);

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
int __cdecl atoi(const char* text);

// EXTERNAL: TITANIUM 0x0060E31B atol_guess
long __cdecl atol_guess(const char* text);

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

#define gRandomIndex_guess EQ_GLOBAL(int, 0x009005C8)
#define gRandomOffset_guess EQ_GLOBAL(int, 0x009005CC)
#define gRandomTable_guess EQ_ARRAY(int, 0x009005D0)
#define gTeleportParseCursor_guess EQ_GLOBAL(int, 0x009006B4)
#define gLineEnd_guess EQ_GLOBAL(int, 0x0078C588)
#define gFormat5X_guess EQ_ARRAY(char, 0x006470C4)
#define gFormat1D_guess EQ_ARRAY(char, 0x006470C0)
#define gFormat4X_guess EQ_ARRAY(char, 0x006470BC)
#define gFormatField_guess EQ_ARRAY(char, 0x006470B8)
#define gFormat8X_guess EQ_ARRAY(char, 0x006470B4)

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0060F520 FUN_0060f520_guess
char* __cdecl FUN_0060f520_guess(const char* text, int value);

// EXTERNAL: TITANIUM 0x00576FA0 FUN_00576fa0_guess
void __cdecl FUN_00576fa0_guess(char* destination, const char* source, int count);

// EXTERNAL: TITANIUM 0x0042DD82 GrabFirstWord_guess
int __cdecl GrabFirstWord_guess(const char* source, char* destination, int capacity);

// EXTERNAL: TITANIUM 0x004912B1 FUN_004912b1_guess
int __cdecl FUN_004912b1_guess(int* target, int message, void* data, int length, int flags);

// EXTERNAL: TITANIUM 0x0062202C __strnicmp
int __cdecl __strnicmp(const char* text1, const char* text2, size_t count);

struct Record_guess {
    char pad_000[0x168];
    int chatType_168_guess;
    int channel_16c_guess;
    char text_170_guess[0x40];
    char pad_1b0[0x1400];
    char records_15b0_guess[0x180];
    char text_1730_guess[0x40];
    void SetGroupMemberName_guess(int index, const char* source);
    void Clear_guess(int index);
    void SetGroupLeaderName_guess(const char* source);
    void Copy170_guess(const char* source);
    // EXTERNAL: TITANIUM 0x00451A65 Record_guess::ClearGroupMemberNames_guess
    void ClearGroupMemberNames_guess();
    // EXTERNAL: TITANIUM 0x00451A7C Record_guess::ClearGroupLeaderName_guess
    void ClearGroupLeaderName_guess();
};

// EXTERNAL: TITANIUM 0x00645E5C ??_7DestroyedObject_648BE_guess@@6B@
struct DestroyedObject_648BE_guess {
    virtual ~DestroyedObject_648BE_guess();
    DestroyedObject_648BE_guess* Destroy_guess(unsigned char flags_guess);
};

struct GateEntry_guess {
    char pad_000[0xc];
    int state_00c_guess;
};

struct Gate_guess {
    // EXTERNAL: TITANIUM 0x005F6F20 Gate_guess::FUN_005f6f20_guess
    int FUN_005f6f20_guess(const char* zone_guess);
    // EXTERNAL: TITANIUM 0x005F6D80 Gate_guess::Allows_guess
    char Allows_guess(int value);
    // EXTERNAL: TITANIUM 0x005F6D40 Gate_guess::FUN_005f6d40_guess
    char FUN_005f6d40_guess(int value);
    // EXTERNAL: TITANIUM 0x005F6ED0 Gate_guess::FUN_005f6ed0_guess
    bool FUN_005f6ed0_guess(int value, char* destination);
    // EXTERNAL: TITANIUM 0x005FA1C0 Gate_guess::GetName_guess
    void GetName_guess(int zone_guess, char* name_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0043A6BF Gate_guess::GetEntry_guess
    GateEntry_guess* GetEntry_guess(int index);
    // EXTERNAL: TITANIUM 0x005F6B90 Gate_guess::FUN_005f6b90_guess
    int FUN_005f6b90_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F6E40 Gate_guess::FUN_005f6e40_guess
    char FUN_005f6e40_guess(int value_guess);
};
#define gGate_guess EQ_GLOBAL(Gate_guess*, 0x00905CC0)

// EXTERNAL: TITANIUM 0x0060E460 FUN_0060e460_guess
void __cdecl FUN_0060e460_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x00576670 FUN_00576670_guess
bool __cdecl FUN_00576670_guess(const char* path);

struct Criteria_guess {
    // EXTERNAL: TITANIUM 0x0040D8E0 Criteria_guess::IsActive_guess
    char IsActive_guess();
};

struct RecordFlag_guess {
    char pad_000[0x190];
    char flag_190_guess;
};

typedef CXStr Str_guess;

struct Base_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00573250 Base_guess::Get_guess
    Str_guess Get_guess(int a, int b);
};

struct W_guess : Base_guess {
    Str_guess F_guess(int a, int b);
};

struct Slot_46_guess {
    int key_00_guess;    // 0x0
    float a_04_guess;    // 0x4
    float b_08_guess;    // 0x8
    float c_0c_guess;    // 0xc
};

struct Block_46_guess {
    int words_000_guess[0x40]; // 0x000
    int value_100_guess;       // 0x100
    int value_104_guess;       // 0x104
    int value_108_guess;       // 0x108
    Slot_46_guess slots_10c_guess[3]; // 0x10c
    void Reset_guess();
};

// Zeroes the 64 dwords at +0, the three dwords at +0x100..+0x108 and the three 16-byte slots from
// +0x10C (an int and three floats each).
// FUNCTION: TITANIUM 0x004647A4
// @early-stop: budget, diff ndiff=3
void Block_46_guess::Reset_guess() {
    int count_guess;
    for (count_guess = 0; count_guess < 0x40; ++count_guess) {
        words_000_guess[count_guess] = 0;
    }
    value_100_guess = 0;
    value_104_guess = 0;
    count_guess = 3;
    value_108_guess = 0;
    float* cursor_guess = &slots_10c_guess[0].b_08_guess;
    do {
        ((int*)cursor_guess)[-2] = 0;
        cursor_guess[-1] = 0.0f;
        *cursor_guess = 0.0f;
        --count_guess;
        cursor_guess[1] = 0.0f;
        cursor_guess += 4;
    } while (count_guess != 0);
}

// Thunk: forwards to the CXStr base call 0x573250.
// FUNCTION: TITANIUM 0x004647E6
Str_guess W_guess::F_guess(int a, int b) {
    return Base_guess::Get_guess(a, b);
}

// 1 when |value| < FLT_EPSILON (1.1920929e-07).
// FUNCTION: TITANIUM 0x00464803
int __cdecl IsNearlyZero_guess(float value) {
    if (value > -1.1920929e-07f && value < 1.1920929e-07f)
        return 1;
    return 0;
}

struct Vector3_46_guess {
    float x_guess; // 0x0
    float y_guess; // 0x4
    float z_guess; // 0x8
    void Scale_guess(float scale);
    float Normalize_guess();
};

// Multiplies the vector by `scale`.
// FUNCTION: TITANIUM 0x0046482C
void Vector3_46_guess::Scale_guess(float scale) {
    x_guess = scale * x_guess;
    y_guess = scale * y_guess;
    z_guess = scale * z_guess;
}

// EXTERNAL: TITANIUM 0x00435B36 FUN_00435b36_guess
double __cdecl FUN_00435b36_guess(void);

// EXTERNAL: TITANIUM 0x00610884 FUN_00610884_guess
double __cdecl FUN_00610884_guess(double value);

#define gNearZeroResult_guess EQ_GLOBAL(float, 0x0063F4CC)

// Normalizes in place and returns the old length; a near-zero vector becomes (0,0,0).
// MoverCalc_46_guess::GetRate_guess is this same function.
// FUNCTION: TITANIUM 0x0046D66E
// @early-stop: budget, diff ndiff=2
float Vector3_46_guess::Normalize_guess() {
    float length_guess = (float)FUN_00610884_guess(FUN_00435b36_guess());
    char nearZero_guess = (char)IsNearlyZero_guess(length_guess);
    if (nearZero_guess) {
        z_guess = 0.0f;
        y_guess = 0.0f;
        x_guess = 0.0f;
        return gNearZeroResult_guess;
    }
    Scale_guess(1.0f / length_guess);
    return length_guess;
}

// Sets group member name `index` (+0x15B0, 64 chars); the profile load and the group messages
// (0x00464F44, 0x00464F9E) use it.
// FUNCTION: TITANIUM 0x0046484B
void Record_guess::SetGroupMemberName_guess(int index, const char* source) {
    FUN_00576fa0_guess(records_15b0_guess + index * 0x40, source, 0x40);
}

// Clears group member name `index` (+0x15B0).
// FUNCTION: TITANIUM 0x0046486B
void Record_guess::Clear_guess(int index) {
    memset(records_15b0_guess + index * 0x40, 0, 0x40);
}

// Sets the group leader's name (+0x1730, 64 chars); the profile load fills it.
// FUNCTION: TITANIUM 0x00464889
void Record_guess::SetGroupLeaderName_guess(const char* source) {
    FUN_00576fa0_guess(text_1730_guess, source, 0x40);
}

// Copies up to 64 chars of `source` into the name at +0x170; the chat manager names its windows with
// it.
// FUNCTION: TITANIUM 0x004648A1
void Record_guess::Copy170_guess(const char* source) {
    strncpy(text_170_guess, source, 0x40);
}

DestroyedObject_648BE_guess::~DestroyedObject_648BE_guess() {
}

// Scalar deleting destructor.
// FUNCTION: TITANIUM 0x004648BE
DestroyedObject_648BE_guess* DestroyedObject_648BE_guess::Destroy_guess(unsigned char flags_guess) {
    this->DestroyedObject_648BE_guess::~DestroyedObject_648BE_guess();
    if ((flags_guess & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

struct VlongValue_46_guess {
    unsigned int* data_guess;
    int capacity_guess;
    int count_guess;
    int refs_guess;
};

struct PairHolder_46_guess {
    VlongValue_46_guess* values_guess;
    int unknown04_guess;
    // EXTERNAL: TITANIUM 0x004CA70F PairHolder_46_guess::PairHolder_46_guess
    PairHolder_46_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004CA75F PairHolder_46_guess::~PairHolder_46_guess
    ~PairHolder_46_guess();
    // EXTERNAL: TITANIUM 0x004CA749 ??0PairHolder_46_guess@@QAE@ABU0@@Z
    PairHolder_46_guess(const PairHolder_46_guess& other_guess);
    // EXTERNAL: TITANIUM 0x004CA9C3 ??4PairHolder_46_guess@@QAEAAU0@U0@@Z
    PairHolder_46_guess& operator=(PairHolder_46_guess other_guess);
};

struct vlong_public_key_guess {
    PairHolder_46_guess first_guess;
    PairHolder_46_guess second_guess;
    vlong_public_key_guess();
    ~vlong_public_key_guess();
    // EXTERNAL: TITANIUM 0x00447474 vlong_public_key_guess::Encrypt_guess
    PairHolder_46_guess Encrypt_guess(const PairHolder_46_guess& plain_guess);
};

// vlong public_key constructor: both numbers (modulus and exponent) zero.
// FUNCTION: TITANIUM 0x004648DB
vlong_public_key_guess::vlong_public_key_guess()
    : first_guess(0, 0), second_guess(0, 0) {
}

// Empty vlong public_key destructor; the two numbers release themselves.
// FUNCTION: TITANIUM 0x00464913
vlong_public_key_guess::~vlong_public_key_guess() {
}

// Reads one line (no length limit; callers pass 2048 bytes). Returns its length, or -1 at EOF.
// FUNCTION: TITANIUM 0x004650C8
int __cdecl readLineFromFile_guess(FILE* file_guess, char* destination_guess) {
    int index = 0;
    int status = 0;
    // ANDing with the 0 in `index` is how the original resets the parse cursor (match shape).
    gTeleportParseCursor_guess &= index;
    while (status == 0) {
        char character = (char)fgetc(file_guess);
        if (character == -1) {
            status = -1;
        } else {
            if (character == '\n') {
                status = 1;
            } else {
                destination_guess[index] = character;
                ++index;
            }
        }
    }
    destination_guess[index] = 0;
    if (status < 0) {
        return -1;
    }
    return index;
}

struct ManagerData_guess {
    char pad_000[0x15c];
    int mount_015c_guess;
    char pad_160[0xf98 - 0x160];
    int castingSpellId_0f98_guess;
};

struct Connection_guess {
    char pad_000[0x120];
    char text_120_guess[0x88];
    ManagerData_guess* pActorInfo_01a8_guess;
    char pad_1ac[0x204 - 0x1ac];
    int field_204_guess;
    char pad_208[0x24c - 0x208];
    unsigned char byte_24c_guess;
    char pad_24d[4];
    char standState_0251_guess;
    unsigned char playerClass_0252_guess;
    char pad_253[3];
    char gm_0256_guess;
    char pad_257;
    int spawnId_0258_guess;
    char pad_25c_guess[0x10];
    int afk_26c_guess;
    // EXTERNAL: TITANIUM 0x0047E900 Connection_guess::SetAFK_guess
    void SetAFK_guess(int value);
    // EXTERNAL: TITANIUM 0x0047C007 Connection_guess::HasPlayerState_guess
    char HasPlayerState_guess(int value);
    // EXTERNAL: TITANIUM 0x0047BFF8 Connection_guess::RemovePlayerState_guess
    void RemovePlayerState_guess(int value);
    // EXTERNAL: TITANIUM 0x0047BFEB Connection_guess::AddPlayerState_guess
    void AddPlayerState_guess(int value);
    // EXTERNAL: TITANIUM 0x00479EA3 Connection_guess::IsGroupInvitePending_guess
    char IsGroupInvitePending_guess();
    // EXTERNAL: TITANIUM 0x00481DC7 Connection_guess::Dismount_guess
    void Dismount_guess();
};

#define gConnection_guess EQ_GLOBAL(Connection_guess*, 0x00905CE4)
#define gPlayerStateAggressive_guess EQ_GLOBAL(int, 0x00647CB4)
#define gSendTarget_guess EQ_GLOBAL(int, 0x00905CA0)

struct Payload_guess {
    int spawnId_0000_guess;
    int message;
};

struct PostAction_guess;

struct GlobalContext_guess {
    char pad_00000_guess[0x8];
    int owner_008_guess;
    char pad_00c_guess[0x17ba8];
    char text_17bb4_guess;
    // EXTERNAL: TITANIUM 0x00492968 GlobalContext_guess::FUN_00492968_guess
    void FUN_00492968_guess();
    // EXTERNAL: TITANIUM 0x004A56B1 GlobalContext_guess::ProcessMBox_guess
    void ProcessMBox_guess();
    // EXTERNAL: TITANIUM 0x004A19D1 GlobalContext_guess::send_private_guess
    void send_private_guess();
    // EXTERNAL: TITANIUM 0x004A1953 GlobalContext_guess::send_petition_guess
    void send_petition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004A1350 GlobalContext_guess::SavePC_guess
    void SavePC_guess(int value1_guess, int value2_guess, int value3_guess);
    // EXTERNAL: TITANIUM 0x00495F81 GlobalContext_guess::MoveMoney_guess
    void MoveMoney_guess(int value1_guess, int value2_guess, int value3_guess,
                            int value4_guess, int value5_guess, int value6_guess);
    // EXTERNAL: TITANIUM 0x00495250 GlobalContext_guess::GetMailManager_guess
    PostAction_guess* GetMailManager_guess();
    // EXTERNAL: TITANIUM 0x00498449 GlobalContext_guess::Emote_guess
    void Emote_guess();
    // EXTERNAL: TITANIUM 0x0049C800 GlobalContext_guess::Dispatch_guess
    void Dispatch_guess(int value);
    // EXTERNAL: TITANIUM 0x0049C20E GlobalContext_guess::GuildRemove_guess
    void GuildRemove_guess(int value);
    // EXTERNAL: TITANIUM 0x0049C618 GlobalContext_guess::GuildLeader_guess
    void GuildLeader_guess(int value);
    // EXTERNAL: TITANIUM 0x0049C74E GlobalContext_guess::GuildSay_guess
    void GuildSay_guess(int value);
    // EXTERNAL: TITANIUM 0x004982C6 GlobalContext_guess::SetText_guess
    void SetText_guess(const char* text, int value, int flags);
    // EXTERNAL: TITANIUM 0x004982C6 GlobalContext_guess::Show_guess
    void Show_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00492EC2 GlobalContext_guess::trimName_guess
    const char* trimName_guess(const void* value_guess);
    // EXTERNAL: TITANIUM 0x00499824 GlobalContext_guess::LootCorpse_guess
    void LootCorpse_guess(int value, int flags);
    // EXTERNAL: TITANIUM 0x00491438 GlobalContext_guess::ChatServerMessage_guess
    void ChatServerMessage_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00493FC0 GlobalContext_guess::ConfirmKill_guess
    void ConfirmKill_guess(const char* name, const char* text);
    // EXTERNAL: TITANIUM 0x004A95FF GlobalContext_guess::SendMailServerCommand_guess
    void SendMailServerCommand_guess(char* text);
    // EXTERNAL: TITANIUM 0x00492F68 GlobalContext_guess::DoPercentConvert_guess
    void DoPercentConvert_guess(char* text, int flags);
    // EXTERNAL: TITANIUM 0x00498720 GlobalContext_guess::send_gsay_guess
    void send_gsay_guess();
    // EXTERNAL: TITANIUM 0x004988B1 GlobalContext_guess::send_auction_guess
    void send_auction_guess();
    // EXTERNAL: TITANIUM 0x00498977 GlobalContext_guess::send_ooc_guess
    void send_ooc_guess();
    // EXTERNAL: TITANIUM 0x004A18F2 GlobalContext_guess::send_tell_guess
    void send_tell_guess(char* text, int length);
    // EXTERNAL: TITANIUM 0x00498436 GlobalContext_guess::dsp_chat
    void dsp_chat(const char* text);
    // EXTERNAL: TITANIUM 0x00496D39 GlobalContext_guess::SendLFGCommand_guess
    void SendLFGCommand_guess(void* data_guess);
    // EXTERNAL: TITANIUM 0x00494B3D GlobalContext_guess::SetGameState
    void SetGameState(int value);
    // EXTERNAL: TITANIUM 0x0049DB44 GlobalContext_guess::GuildWar
    void GuildWar(char* text, int value);
    // EXTERNAL: TITANIUM 0x0049BF15 GlobalContext_guess::GuildInvite_guess
    void GuildInvite_guess(char* text, int length);
    // EXTERNAL: TITANIUM 0x0049E0C1 GlobalContext_guess::send_social_guess
    void send_social_guess(const char* text, char* buffer, int length);
    // EXTERNAL: TITANIUM 0x004AE848 GlobalContext_guess::WriteCharIniString_guess
    void WriteCharIniString_guess(const char* value, const char* section, const char* key);
    // EXTERNAL: TITANIUM 0x0049975B GlobalContext_guess::IssuePetCommand_guess
    void IssuePetCommand_guess(int code_guess, int extra_guess);
    // EXTERNAL: TITANIUM 0x004AE514 GlobalContext_guess::WriteInt_guess
    void WriteInt_guess(int value, const char* section, const char* key);
    // EXTERNAL: TITANIUM 0x004AE5AF GlobalContext_guess::WriteFlag_guess
    void WriteFlag_guess(int value, const char* section, const char* key);
    // EXTERNAL: TITANIUM 0x00493F1B GlobalContext_guess::ConfirmBuff_guess
    void ConfirmBuff_guess(EQPlayer* character_guess, CXStr* name_guess,
                            int level_guess);
    // EXTERNAL: TITANIUM 0x0049D3CC GlobalContext_guess::Invite_guess
    void Invite_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0049DC19 GlobalContext_guess::FUN_0049dc19_guess
    void FUN_0049dc19_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0049D7B6 GlobalContext_guess::AcceptGroupInvite_guess
    void AcceptGroupInvite_guess();
    // EXTERNAL: TITANIUM 0x0049D8BD GlobalContext_guess::Disband_guess
    void Disband_guess();
    // EXTERNAL: TITANIUM 0x0049DCFA GlobalContext_guess::ToggleSit_guess
    void ToggleSit_guess();
    // EXTERNAL: TITANIUM 0x0049DDA6 GlobalContext_guess::PrepareToCamp_guess
    void PrepareToCamp_guess();
};

struct PostAction_guess {
    // EXTERNAL: TITANIUM 0x0042B34A PostAction_guess::FUN_0042b34a_guess
    void FUN_0042b34a_guess();
};

#define gGlobalContext_guess EQ_GLOBAL(GlobalContext_guess*, 0x00988DF0)

struct QuitState_guess {
    unsigned char pad_000_guess[0xB50];
    int quit_b50_guess;
    unsigned char pad_b54_guess[0x39400 - 0xB54];
    int quit_39400_guess;
};
#define gQuitState_guess EQ_GLOBAL(QuitState_guess*, 0x00988DF0)

struct QuitChannel_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    // EXTERNAL: TITANIUM 0x0040BE64 QuitChannel_guess::FUN_0040be64_guess
    void FUN_0040be64_guess(int value);
    // EXTERNAL: TITANIUM 0x0040BEAE QuitChannel_guess::FUN_0040beae_guess
    void FUN_0040beae_guess(int value);
};
#define gWorldConnection_guess EQ_GLOBAL(QuitChannel_guess*, 0x00905CA0)
#define gDisconnectStatus_guess EQ_GLOBAL(char, 0x00923D7B)
#define gQuitCode_guess EQ_GLOBAL(int, 0x00923794)

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* text);

#define gLookupCount_guess EQ_GLOBAL(int, 0x00905CAC)
#define gTeleportKeys_guess EQ_ARRAY(int, 0x009043E8)
#define gLookupValues_guess EQ_ARRAY(int, 0x009043FC)

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::FindText_guess
    const char* FindText_guess(int value, int flags);
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::FindTextTyped_guess
    const char* FindTextTyped_guess(int value, int zero, int type, int enabled);
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::FindTextWithOptions_guess
    const char* FindTextWithOptions_guess(int value, int zero, int type,
                                          int timeout, int flag1, int flag2);
};
#define gTextLookup_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::PostCompact_guess
    void PostCompact_guess(int* owner_guess, int code_guess,
                           const char* text_guess);
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Post_guess
    void Post_guess(int* owner_guess, int code_guess, const char* text_guess,
                    int type_guess, int timeout_guess, int target_guess,
                    int flag_guess);
};
#define gDispatch_475BAB_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)

struct State_466965_guess {
    char pad_000_guess[0xe10];
    unsigned char state_0e10_guess;
};
#define gState_466965_guess EQ_GLOBAL(State_466965_guess*, 0x00905D00)

struct GlobalHead_475BAB_guess {
    int pad_000_guess[2];
    int link_008_guess;
};
#define gGlobalHead_475BAB_guess EQ_GLOBAL(GlobalHead_475BAB_guess*, 0x00988DF0)

#define gShownNpcNamesOn_guess EQ_ARRAY(char, 0x00646E64)
#define gShownNpcNamesOff_guess EQ_ARRAY(char, 0x00646E78)

struct NpcNameState_guess {
    char pad_000_guess[0x10];
    char flag_10_guess;
    char flag_11_guess;
    // EXTERNAL: TITANIUM 0x004389FB NpcNameState_guess::SetPCloudDensity_guess
    void SetPCloudDensity_guess(int density_guess);
    // EXTERNAL: TITANIUM 0x00439AC7 NpcNameState_guess::SetNPCNameSpriteState_guess
    void SetNPCNameSpriteState_guess(int shown_guess);
    // EXTERNAL: TITANIUM 0x0043DD14 NpcNameState_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(Holder_474597_guess* holder_guess, int index_guess,
                            RefObject_464C94_guess* object_guess,
                            Slot_474597_guess* slot_guess);
    // EXTERNAL: TITANIUM 0x00439A93 NpcNameState_guess::SetPCNameSpriteState_guess
    void SetPCNameSpriteState_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00439D16 NpcNameState_guess::PlayerDistance_guess
    float PlayerDistance_guess(const void* first_guess, const void* second_guess, float scale_guess);
    // EXTERNAL: TITANIUM 0x00439DB8 NpcNameState_guess::UpdateGrassDisplacement_guess
    void UpdateGrassDisplacement_guess();
    // EXTERNAL: TITANIUM 0x00439D89 NpcNameState_guess::ClearGrassDisplacement_guess
    void ClearGrassDisplacement_guess();
};
#define gNpcNameState_guess EQ_GLOBAL(NpcNameState_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00574990 FUN_00574990_guess
int __cdecl FUN_00574990_guess(const char* text_guess, const char* target_guess, int mode_guess);

struct DispatchTarget99E368_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess(int value);
};
#define g_dispatch99E368_guess EQ_GLOBAL(DispatchTarget99E368_guess*, 0x0099E368)

struct IncomingMessage_guess {
    char pad_000_guess[0x120];
    char text_120_guess[0x124];
    unsigned char byte_244_guess;
    char pad_245_guess[0x252 - 0x245];
    unsigned char classId_0252_guess;
    char pad_253_guess[3];
    unsigned char byte_256_guess;
    char pad_257_guess;
    int value_258_guess;
    char pad_25c_guess[0x27c - 0x25c];
    int value_27c_guess;
    char pad_280_guess[8];
    int index_288_guess;
};
#define gIncomingMessage_guess EQ_GLOBAL(IncomingMessage_guess*, 0x00905D04)

struct OutgoingMessage_guess {
    int index_guess;
    char text_guess[0x284];
};

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int minimum_guess, int maximum_guess);


// EXTERNAL: TITANIUM 0x004912B1 SendMessage_guess
void __cdecl SendMessage_guess(void* target, int message, void* data, int size, int flags);

struct PartState_guess {
    int unused_guess;
    int index_guess; // 0x04
};

struct CommandContext_guess {
    int unused_guess;
    // EXTERNAL: TITANIUM 0x0040EBC3 CommandContext_guess::SpellDuration_guess
    int SpellDuration_guess(Table_475855_guess* table_guess, int value_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x0040F339 CommandContext_guess::CalcAffectChange_guess
    int CalcAffectChange_guess(Table_475855_guess* table_guess, int state_guess, int index_guess,
                           int flags_guess);
    // EXTERNAL: TITANIUM 0x0040F8A0 CommandContext_guess::Handle_guess
    void Handle_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041F4A0 CommandContext_guess::FUN_0041f4a0_guess
    void FUN_0041f4a0_guess(unsigned char value_guess, IncomingMessage_guess* message_guess);
    // EXTERNAL: TITANIUM 0x0040DB0B CommandContext_guess::IsBardSong_guess
    int IsBardSong_guess(int key_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x004192AA CommandContext_guess::CanUseItem_guess
    int CanUseItem_guess(RefObject_464C94_guess* object_guess, int value_guess);
};

struct CurrentAction_guess;

struct OffsetBlock_471267_guess {
    char pad_000_guess[4];
    int vbaseOffset_0004_guess;
};

struct StateHolder_guess {
    unsigned char pad_0000_guess[8];
    OffsetBlock_471267_guess* offsetBlock_008_guess;
    unsigned char pad_00c_guess[0x44 - 0xC];
    char text_044_guess[1];
    unsigned char pad_045_guess[0xc280 - 0x45];
    CommandContext_guess command_c280_guess;
    PartState_guess* part_guess; // 0xc284
    CurrentAction_guess* pSpawn_c288_guess;
    unsigned char pad_c28c_guess[0xc38c - 0xc28c];
    unsigned char stateFlags_guess[1]; // 0xc38c
    // EXTERNAL: TITANIUM 0x004BAF5E StateHolder_guess::RemovePotionBeltItem_guess
    void RemovePotionBeltItem_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BEDCA StateHolder_guess::UsePotionBeltItem_guess
    void UsePotionBeltItem_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BEC4E StateHolder_guess::SaveBandolier_guess
    void SaveBandolier_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x004BAEEE StateHolder_guess::DeleteBandolier_guess
    void DeleteBandolier_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BF5BA StateHolder_guess::UseBandolier_guess
    void UseBandolier_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F0C30 StateHolder_guess::FUN_005f0c30_guess
    const char* FUN_005f0c30_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F0760 StateHolder_guess::FUN_005f0760_guess
    int FUN_005f0760_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004BAB19 StateHolder_guess::IsInGroup_guess
    char IsInGroup_guess();
    // EXTERNAL: TITANIUM 0x004BAB25 StateHolder_guess::IsInRaid_guess
    char IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x004BAB58 StateHolder_guess::FUN_004bab58_guess
    char FUN_004bab58_guess();
    // EXTERNAL: TITANIUM 0x004BABAA StateHolder_guess::IsRaidMarkNpcDelegate_guess
    char IsRaidMarkNpcDelegate_guess();
    // EXTERNAL: TITANIUM 0x004BB282 StateHolder_guess::IsGroupLeader_guess
    char IsGroupLeader_guess();
    // EXTERNAL: TITANIUM 0x004BAB62 StateHolder_guess::IsGroupMarkNpcDelegate_guess
    char IsGroupMarkNpcDelegate_guess();
};
#define g_stateHolder_guess EQ_GLOBAL(StateHolder_guess*, 0x00905D00)

struct ActionContext_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 ActionContext_guess::IsInRaid_guess
    char IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x0042FCF9 ActionContext_guess::CanDisplay_guess
    char CanDisplay_guess();
    // EXTERNAL: TITANIUM 0x00430CE5 ActionContext_guess::InviteToRaid_guess
    void InviteToRaid_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x00430FEA ActionContext_guess::MakeLeader_guess
    void MakeLeader_guess(char* text_guess);
};
#define gActionContext_guess EQ_GLOBAL(ActionContext_guess, 0x0091D708)
#define gTestServer_guess EQ_GLOBAL(int, 0x00923D60)

// EXTERNAL: TITANIUM 0x00490F27 CapitalizeFirstLetter_guess
void __cdecl CapitalizeFirstLetter_guess(char* source_guess, char* destination_guess, int size_guess);

// EXTERNAL: TITANIUM 0x00416C2C ClassName_guess
const char* __cdecl ClassName_guess(int classId_guess);

// EXTERNAL: TITANIUM 0x0060F60D _fabs
extern "C" double __cdecl _fabs(double value_guess);

struct ScaleSource_46_guess {
    char pad_000_guess[0xc4];
    float value_0c4_guess;
};

struct Actor_46_guess {
    char pad_000_guess[0x30];
    float x_30_guess;
    float y_34_guess;
    float z_38_guess;
    char pad_3c_guess[0x120 - 0x3c];
    char name_120_guess[0x80];
    float scale_1a0_guess;
    char pad_1a4_guess[4];
    ScaleSource_46_guess* source_1a8_guess;
    char pad_1ac_guess[0x238 - 0x1ac];
    float heightOffset_0238_guess;
    char pad_23c_guess[0x260 - 0x23c];
    int race_0260_guess;
    char pad_264_guess[0x28c - 0x264];
    int mode_28c_guess;
    // EXTERNAL: TITANIUM 0x0047C2D4 Actor_46_guess::FUN_0047c2d4_guess
    float FUN_0047c2d4_guess();
    // EXTERNAL: TITANIUM 0x0048A6F2 Actor_46_guess::FUN_0048a6f2_guess
    void FUN_0048a6f2_guess();
};

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_printf_guess
void __cdecl FUN_00574110_printf_guess(const char* format_guess, ...);

#define gPhysicsDebug_guess EQ_GLOBAL(int, 0x009006AC)

// Decodes a position update laid out like EQEmu PlayerPositionUpdateServer_Struct (after the spawn id):
// coordinates 19-bit at 1/8 unit, deltas 13-bit at 1/64, heading 12-bit at 1/4, animation 10-bit at
// 1/40, delta heading 10-bit at 1/20. In mode 2 z is taken only when it moved more than 5 units.
// Actor states 0x48, 0x49 and 0x194 keep z and zero vz; the vz warning prints only when 0x9006AC is 0.
// FUNCTION: TITANIUM 0x00465304
void __cdecl unpack_physics_guess(float* pose_guess, int* packed_guess, Actor_46_guess* actor_guess) {
    float original_z_guess = pose_guess[2];
    pose_guess[0] = (float)((packed_guess[1] << 13) >> 13) * 0.125f;
    pose_guess[3] = (float)(packed_guess[2] >> 19) * 0.015625f;
    pose_guess[1] = (float)((packed_guess[0] << 3) >> 13) * 0.125f;
    pose_guess[4] = (float)((packed_guess[3] << 19) >> 19) * 0.015625f;
    float z_guess = (float)((packed_guess[2] << 13) >> 13) * 0.125f;
    pose_guess[5] = (float)((packed_guess[4] << 19) >> 19) * 0.015625f;
    pose_guess[7] = (float)((packed_guess[3] << 7) >> 20) * 0.25f;
    pose_guess[6] = (float)((packed_guess[1] << 3) >> 22) * 0.025f;
    pose_guess[10] = (float)((packed_guess[0] << 22) >> 22) * 0.05f;

    if (actor_guess->mode_28c_guess == 2) {
        float current_z_guess = pose_guess[2];
        float distance_guess = (float)_fabs(z_guess - current_z_guess);
        if (distance_guess > 5.0f) {
            pose_guess[2] = z_guess;
        }
    } else {
        pose_guess[2] = z_guess;
    }

    int state_guess = actor_guess->race_0260_guess;
    if (gPhysicsDebug_guess == 0) {
        if (state_guess == 0x48 || state_guess == 0x49 || state_guess == 0x194) {
            if (pose_guess[5] != 0.0f) {
                FUN_00574110_printf_guess("%s's player_phys->vz = %f!\n", actor_guess->name_120_guess,
                                          (double)pose_guess[5]);
            }
            pose_guess[2] = original_z_guess;
            pose_guess[5] = 0.0f;
        }
    } else if (state_guess == 0x48 || state_guess == 0x49 || state_guess == 0x194) {
        pose_guess[5] = 0.0f;
    }
    actor_guess->FUN_0048a6f2_guess();
}

// Squared 3D distance with z measured at the feet (z minus the height offset +0x238).
// FUNCTION: TITANIUM 0x0046591B
float __cdecl get_range_squared_guess(Actor_46_guess* first_guess, Actor_46_guess* second_guess) {
    float dx_guess = first_guess->x_30_guess - second_guess->x_30_guess;
    float dy_guess = first_guess->y_34_guess - second_guess->y_34_guess;
    float dz_guess = (first_guess->z_38_guess - first_guess->heightOffset_0238_guess) -
                     (second_guess->z_38_guess - second_guess->heightOffset_0238_guess);
    return dz_guess * dz_guess + dy_guess * dy_guess + dx_guess * dx_guess;
}

// Melee reach: (size A + size B) * 0.75, at least 14, plus the height difference + 2, capped at 75;
// 14 when either spawn has no actor.
// FUNCTION: TITANIUM 0x0046595A
// @early-stop: budget, structural ndiff=16
float __cdecl get_melee_range(Actor_46_guess* first_guess, Actor_46_guess* second_guess) {
    if (first_guess == 0 || second_guess == 0 || first_guess->source_1a8_guess == 0 ||
        second_guess->source_1a8_guess == 0) {
        return 14.0f;
    }
    float first_scale_guess = first_guess->FUN_0047c2d4_guess();
    float second_scale_guess = second_guess->FUN_0047c2d4_guess();
    float diff_guess = (float)_fabs(first_guess->heightOffset_0238_guess - second_guess->heightOffset_0238_guess);
    float value_guess = (second_scale_guess + first_scale_guess) * 0.75f;
    if (value_guess < 14.0f) {
        value_guess = 14.0f;
    }
    value_guess = diff_guess + value_guess;
    value_guess = value_guess + 2.0f;
    if (value_guess > 75.0f) {
        value_guess = 75.0f;
    }
    return value_guess;
}

// /adventure <text>: sends the text (under 128 chars, at +4 of 0x84 bytes) as OP_SlashAdventure 0x571A.
// FUNCTION: TITANIUM 0x00465A10
void __cdecl do_adventure_guess(int unused_guess, char* text_guess) {
    char packet[0x84];
    memset(packet, 0, sizeof(packet));
    if (strlen(text_guess) < 0x80) {
        FUN_0060e450_guess(packet + 4, text_guess);
        SendMessage_guess(&gSendTarget_guess, OP_SlashAdventure, packet, sizeof(packet), 1);
    }
}

// /webupdate: sends the player's name with opcode 0x2A95 (not in patch_Titanium.conf).
// FUNCTION: TITANIUM 0x00465A7E
void __cdecl do_webupdate_guess() {
    if (gConnection_guess != 0) {
        char* text_guess = gConnection_guess->text_120_guess;
        size_t length_guess = strlen(text_guess);
        SendMessage_guess(&gSendTarget_guess, 0x2a95, text_guess,
                          length_guess + 1, 1);
    }
}

// /testbuffme: OP_TestBuff 0x6AB0, no payload.
// FUNCTION: TITANIUM 0x00465AAD
void __cdecl do_testbuffme_guess() {
    SendMessage_guess(&gSendTarget_guess, OP_TestBuff, 0, 0, 1);
}

// Raid commands: allowed with expansion bit 8 (probably Planes of Power) or the test-server flag
// 0x923D60 (the one /betabuff requires); eqstr 0x22A5 refuses while the raid object is locked.
// /makeraidleader [name]: defaults to the target.
// FUNCTION: TITANIUM 0x00465AFB
void __cdecl do_makeraidleader_guess(int unused_guess, char* text_guess) {
    ActionContext_guess* actionContext_guess = &gActionContext_guess;
    if ((g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 8) != 0 ||
        gTestServer_guess != 0) {
        if (actionContext_guess->CanDisplay_guess() != 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x22a5, 0), 0xd, 1);
        } else {
            char buffer[0x40];
            if (*text_guess == '\0' && gIncomingMessage_guess != 0) {
                actionContext_guess->MakeLeader_guess(gIncomingMessage_guess->text_120_guess);
            } else {
                CapitalizeFirstLetter_guess(text_guess, buffer, 0x40);
                actionContext_guess->MakeLeader_guess(buffer);
            }
        }
    }
}

// /raidinvite <name>.
// FUNCTION: TITANIUM 0x00465B9C
void __cdecl do_raidinvite_guess(int unused_guess, char* text_guess) {
    ActionContext_guess* actionContext_guess = &gActionContext_guess;
    if ((g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 8) != 0 ||
        gTestServer_guess != 0) {
        if (actionContext_guess->CanDisplay_guess() != 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x22a5, 0), 0xd, 1);
            return;
        } else {
            actionContext_guess->InviteToRaid_guess(text_guess);
            return;
        }
    }
}

// Tradeskills: 57 tinkering, 59 alchemy, 60 baking, 61 tailoring, 63 blacksmithing, 64 fletching,
// 65 brewing, 68 jewelry making, 69 pottery (not 58 research or 62 sense traps).
// FUNCTION: TITANIUM 0x00464983
int __cdecl IsTradeSkill_guess(int value) {
    if ((value != 0x39) &&
        (value <= 0x3a ||
         (value > 0x3d &&
          (value <= 0x3e ||
           (value > 0x41 && (value <= 0x43 || value > 0x45)))))) {
        return 0;
    }
    return 1;
}

// Prints string-table text `arg2` in chat colour `arg3`; `arg1` is unused.
// FUNCTION: TITANIUM 0x004649B1
void __cdecl token_string_to_client_guess(int arg1, int arg2, int arg3) {
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(arg2, 0), arg3, 1);
}

// Twin of token_string_to_client_guess for a raw text pointer.
// FUNCTION: TITANIUM 0x004649D5
void __cdecl text_to_client_guess(int arg1, int arg2, int arg3) {
    gGlobalContext_guess->SetText_guess((const char*)arg2, arg3, 1);
}

// Sends the petition text, NUL included, as OP_Petition 0x251F; refused (0) when NULL or over 1023 chars.
// FUNCTION: TITANIUM 0x004649EB
int __cdecl UserPetitions_guess(char* text) {
    if (text == 0) {
        return 0;
    }
    size_t length = strlen(text);
    if (length > 0x3ff) {
        return 0;
    }
    length = strlen(text);
    SendMessage_guess(&gSendTarget_guess, OP_Petition, text, length + 1, 1);
    return 1;
}

// strncpy that always terminates; unlike the earlier sibling decomp's version it writes the NUL at count - 1.
// FUNCTION: TITANIUM 0x00464A28
void __cdecl steve_strncpy_guess(char* destination, const char* source, size_t count) {
    strncpy(destination, source, count);
    destination[count - 1] = '\0';
}

// EXTERNAL: TITANIUM 0x00574A30 FUN_00574a30_guess
void __cdecl FUN_00574a30_guess(char* text_guess, int max_guess);

#define gCorpseFormat_guess EQ_ARRAY(char, 0x00645E88)

// Turns an NPC name into its corpse name in place: drops up to three trailing digits (the spawn number),
// trims the name so name + suffix fit 64 bytes, then appends "'s_corpse<id>". Returns 1.
// FUNCTION: TITANIUM 0x00464A48
// @early-stop: budget, diff ndiff=8
int __cdecl MakeNPCCorpseName_guess(int type_guess, char* text_guess, unsigned int id_guess) {
    char buffer_guess[0x40];
    // Type 62 (probably the LDoN treasure class) uses the other suffix format at 0x645E88.
    if (type_guess == 0x3e) {
        sprintf(buffer_guess, gCorpseFormat_guess, id_guess);
    } else {
        sprintf(buffer_guess, "'s_corpse%u", id_guess);
    }
    int suffixLength_guess = (int)strlen(buffer_guess);
    int threshold_guess = 0x40 - suffixLength_guess;
    if ((int)strlen(text_guess) >= threshold_guess) {
        FUN_00574a30_guess(text_guess, threshold_guess - 1);
    }
    size_t textLength_guess = strlen(text_guess);
    if (textLength_guess > 2) {
        if (text_guess[textLength_guess - 3] >= '0' && text_guess[textLength_guess - 3] <= '9')
            text_guess[textLength_guess - 3] = '\0';
        if (text_guess[textLength_guess - 2] >= '0' && text_guess[textLength_guess - 2] <= '9')
            text_guess[textLength_guess - 2] = '\0';
        if (text_guess[textLength_guess - 1] >= '0' && text_guess[textLength_guess - 1] <= '9')
            text_guess[textLength_guess - 1] = '\0';
    }
    FUN_0060e460_guess(text_guess, buffer_guess);
    return 1;
}

// Inventory slot -> material (texture) slot 0..8, -1 for slots that show no model texture.
// FUNCTION: TITANIUM 0x00464AFB
int __cdecl GetMaterialSlotFromInvSlot_guess(int value) {
    int result = -1;
    switch (value) {
    case 13:
        result = 7;
        break;
    case 2:
        result = 0;
        break;
    case 7:
        result = 2;
        break;
    case 9:
    case 10:
        result = 3;
        break;
    case 12:
        result = 4;
        break;
    case 14:
        result = 8;
        break;
    case 17:
        result = 1;
        break;
    case 18:
        result = 5;
        break;
    case 19:
        result = 6;
        break;
    }
    return result;
}

// Inverse of GetMaterialSlotFromInvSlot_guess; wrists map back to slot 10 only.
// FUNCTION: TITANIUM 0x00464B55
int __cdecl GetInvSlotFromMaterialSlot_guess(int value) {
    int result = -1;
    switch (value) {
    case 1:
        result = 0x11;
        break;
    case 2:
        result = 7;
        break;
    case 3:
        result = 10;
        break;
    case 4:
        result = 0xc;
        break;
    case 5:
        result = 0x12;
        break;
    case 6:
        result = 0x13;
        break;
    case 0:
        result = 2;
        break;
    case 7:
        result = 0xd;
        break;
    case 8:
        result = 0xe;
        break;
    }
    return result;
}

// The race's native language id as a decimal string; human, half elf and unknown races get "0"
// (common tongue). 0x80 is Iksar, 0x82 Vah Shir.
// FUNCTION: TITANIUM 0x00464BB0
char* __cdecl GetDefaultLanguageForRace_guess(int value) {
    switch (value) {
    case 1:
        return EQ_ARRAY(char, 0x006410A8);
    case 2:
        return EQ_ARRAY(char, 0x00645EB4);
    case 3:
        return EQ_ARRAY(char, 0x00645EB0);
    case 4:
    case 5:
        return EQ_ARRAY(char, 0x00645EAC);
    case 6:
        return EQ_ARRAY(char, 0x00645EA8);
    case 7:
        return EQ_ARRAY(char, 0x006410A8);
    case 8:
        return EQ_ARRAY(char, 0x00645EA4);
    case 9:
        return EQ_ARRAY(char, 0x00645EA0);
    case 10:
        return EQ_ARRAY(char, 0x00645E9C);
    case 11:
        return EQ_ARRAY(char, 0x00645E98);
    case 12:
        return EQ_ARRAY(char, 0x00645E94);
    case 0x80:
        return EQ_ARRAY(char, 0x00645E90);
    case 0x82:
        return EQ_ARRAY(char, 0x00645E8C);
    default:
        return EQ_ARRAY(char, 0x006410A8);
    }
}

// Writes the three strings back to back, each NUL-terminated (the NULs are the separators). Returns 1.
// FUNCTION: TITANIUM 0x00464C4B
int __cdecl ConcatenateStringsWithSeparators_guess(char* destination, const char* first, const char* second, const char* third) {
    FUN_0060e450_guess(destination, first);
    size_t firstLength = strlen(first) + 1;
    FUN_0060e450_guess(destination + firstLength, second);
    size_t secondLength = strlen(second);
    FUN_0060e450_guess(destination + firstLength + secondLength + 1, third);
    return 1;
}

struct RefObject_464C94_guess {
    virtual void Release_guess(int flags);
    virtual RefObject_464C94_guess* Create_guess();
    char pad_004[0x44];
    int count_048_guess;
    char pad_04c_guess[0x10];
    int value_5c_guess;
    // EXTERNAL: TITANIUM 0x005ECD80 RefObject_464C94_guess::SetStackCount_guess
    void SetStackCount_guess(int amount);
    // EXTERNAL: TITANIUM 0x005EC760 RefObject_464C94_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005EC820 RefObject_464C94_guess::FUN_005ec820_guess
    int FUN_005ec820_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 RefObject_464C94_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 RefObject_464C94_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005ECD50 RefObject_464C94_guess::GetCapacity_guess
    int GetCapacity_guess();
};

struct TransferMessage_guess {
    int value_guess;
    int data_guess;
    int amount_guess;
};

// MoveItemQty (as in the earlier sibling decomp): moves `amount` from stack *first to *second; an empty *second gets
// a copy of *first first, else both must be valid and of the same kind. Emptied items are released.
// Kept original shape: when *second ends empty the call returns 0 without writing either pointer back,
// so a *first released on the way is left dangling in the caller (the earlier sibling decomp does the same).
// FUNCTION: TITANIUM 0x00464C94
// @early-stop: budget, diff ndiff=13
int __cdecl MoveItemQty_guess(RefObject_464C94_guess** firstAddress, RefObject_464C94_guess** secondAddress, int amount) {
    RefObject_464C94_guess* first = *firstAddress;
    RefObject_464C94_guess* second = *secondAddress;
    if (second == 0) {
        second = first->Create_guess();
        first->count_048_guess -= amount;
        second->SetStackCount_guess(amount);
    } else {
        if (first->IsStackable_guess() == 0) {
            return 0;
        }
        if (second->IsStackable_guess() == 0) {
            return 0;
        }
        if (second->GetItemId_guess() != first->GetItemId_guess()) {
            return 0;
        }
        first->count_048_guess -= amount;
        second->count_048_guess += amount;
    }
    if (first->count_048_guess <= 0) {
        first->Release_guess(1);
        first = 0;
    }
    if (second->count_048_guess <= 0) {
        second->Release_guess(1);
        return 0;
    }
    *firstAddress = first;
    *secondAddress = second;
    return 1;
}

// Adds `amount` (may be negative) to an item's stack count, releasing the item at 0 or below.
// Adjust_guess is given the new total, so it really sets the count (misnamed).
// FUNCTION: TITANIUM 0x00464D26
char __cdecl AdjustItemStackCount_guess(RefObject_464C94_guess** objectAddress, int amount) {
    RefObject_464C94_guess* object = *objectAddress;
    if (object == 0) {
        return 0;
    }
    if (!object->IsStackable_guess()) {
        return 0;
    }
    int total = object->count_048_guess + amount;
    if (total <= 0) {
        object->Release_guess(1);
        object = 0;
    } else {
        object->SetStackCount_guess(total);
    }
    *objectAddress = object;
    return 1;
}

// SwapCombine (as in the earlier sibling decomp): tops up stack *second from *first up to its capacity; when the from
// slot `value` is >= 0 and something moved, reports it with OP_MoveItem 0x420F (from, to, count). Only *first is
// checked with IsStackable_guess, as in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x00464D65
int __cdecl SwapCombine_guess(RefObject_464C94_guess** firstAddress, RefObject_464C94_guess** secondAddress, int value, int data) {
    RefObject_464C94_guess* first = *firstAddress;
    RefObject_464C94_guess* second = *secondAddress;
    if (first == 0 || second == 0) {
        return 0;
    }
    if (first->IsStackable_guess() == 0) {
        return 0;
    }
    int secondKind = second->GetItemId_guess();
    if (first->GetItemId_guess() != secondKind) {
        return 0;
    }
    int moved;
    int used = second->count_048_guess;
    int amount = second->GetCapacity_guess() - used;
    if (first->count_048_guess > amount) {
        first->count_048_guess -= amount;
        second->count_048_guess += amount;
        moved = amount;
    } else {
        second->count_048_guess += first->count_048_guess;
        moved = first->count_048_guess;
        first->Release_guess(1);
        first = 0;
    }
    if (value >= 0 && moved > 0) {
        TransferMessage_guess message;
        message.value_guess = value;
        message.data_guess = data;
        message.amount_guess = moved;
        SendMessage_guess(&gSendTarget_guess, OP_MoveItem, &message, 0xc, 1);
    }
    *firstAddress = first;
    *secondAddress = second;
    return moved != 0;
}

// GetTextureSlot (as in the earlier sibling decomp): equipment slot -> model texture
// part, with shoulders/back folded into chest (1) and waist into legs (5). Titanium adds face 3 -> 9.
// FUNCTION: TITANIUM 0x00464E25
char __cdecl GetTextureSlot_guess(int value) {
    switch (value) {
    case 0xd:
        return 7;
    case 0xe:
        return 8;
    case 6:
    case 8:
    case 0x11:
        return 1;
    case 7:
        return 2;
    case 9:
    case 0xa:
        return 3;
    case 3:
        return 9;
    case 0xc:
        return 4;
    case 0x13:
        return 6;
    case 0x12:
    case 0x14:
        return 5;
    case 2:
        return 0;
    }
    return 0;
}

// Callers are the spell-effect code (InitializeSpellAffects/ApplySpellEffects); meaning unclear.
// 1 when the zone gate 0x5F6D80 allows `value` or `criteria` is active, and the record byte +0x190 is set.
// FUNCTION: TITANIUM 0x00464E9C
char __cdecl FUN_00464e9c_guess(int value, Criteria_guess* criteria, RecordFlag_guess* record) {
    char result = 0;
    if (gGate_guess->Allows_guess(value) != 0 || criteria->IsActive_guess() != 0) {
        if (record->flag_190_guess != result) {
            result = 1;
        }
    }
    return result;
}

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first, const char* second);

// Group update kind 0 (member joined): adds the name to the first empty of the 6 group-name slots
// (+0x15B0, 64 bytes each) unless already present. Returns 1 when added.
// FUNCTION: TITANIUM 0x00464ED1
int __cdecl ProcessMSG_WLDGROUP_guess(Record_guess* record, const char* source) {
    if (*source == '\0') {
        return 0;
    }
    if (record == 0) {
        return 0;
    }
    int i = 0;
    char* text = record->records_15b0_guess;
    do {
        if (__stricmp(source, text) == 0) {
            return 0;
        }
        ++i;
        text += 0x40;
    } while (i < 6);
    for (int j = 0; j < 6; ++j) {
        if (record->records_15b0_guess[j * 0x40] == '\0') {
            FUN_0060e450_guess(record->records_15b0_guess + j * 0x40, source);
            return 1;
        }
    }
    return 0;
}

struct Copy79Owner_guess {
    // EXTERNAL: TITANIUM 0x004B4102 Copy79Owner_guess::SetGroupLeaderBlock_guess
    void SetGroupLeaderBlock_guess(Record_guess* record, const char* source);
    // EXTERNAL: TITANIUM 0x004B3FFE Copy79Owner_guess::ClearGroupLeaderData_guess
    void ClearGroupLeaderData_guess(Record_guess* record);
};
#define gCopy79Owner_guess EQ_GLOBAL(Copy79Owner_guess*, 0x009859EC)

// Group update kind 7: copies 5 member names (packet +0x44, 64 bytes apart) and the leader (+0x184).
// FUNCTION: TITANIUM 0x00464F44
int __cdecl SetGroupMemberNames_guess(Record_guess* record, const char* source) {
    if (record == 0) {
        return 0;
    }
    for (int i = 0; i < 5; ++i) {
        record->SetGroupMemberName_guess(i, source + 0x44 + i * 0x40);
    }
    record->SetGroupLeaderName_guess(source + 0x184);
    if (gCopy79Owner_guess != 0) {
        gCopy79Owner_guess->SetGroupLeaderBlock_guess(record, source + 0x1c4);
    }
    return 1;
}

// Group update kind 3: renames every group-name slot equal to `name` to `source`.
// FUNCTION: TITANIUM 0x00464F9E
int __cdecl msg_wldgroup4_guess(Record_guess* record, const char* name, const char* source) {
    int result = 0;
    if (*name == '\0') {
        return 0;
    }
    if (record == 0) {
        return 0;
    }
    int index = 0;
    char* text = record->records_15b0_guess;
    do {
        if (__stricmp(name, text) == 0) {
            record->SetGroupMemberName_guess(index, source);
            result = 1;
        }
        ++index;
        text += 0x40;
    } while (index < 6);
    return result;
}

// Copies one field of a teleport-file line, from the global parse cursor 0x9006B4 to a NUL, newline
// or the delimiter at 0x78C588, and advances the cursor. gTeleportParseCursor_guess is that cursor.
// FUNCTION: TITANIUM 0x00464FF8
void __cdecl copyStringUntilDelimiter_guess(const char* text, char* output) {
    int status = 0;
    char* current = output;
    do {
        char character = text[gTeleportParseCursor_guess];
        *current = character;
        if (character == '\0' || character == '\n' || character == gLineEnd_guess) {
            status = 1;
            *current = '\0';
        }
        ++current;
        ++gTeleportParseCursor_guess;
        if (gTeleportParseCursor_guess >= strlen(text)) {
            *current = '\0';
            status = 2;
        }
    } while (status == 0);
    strlen(output);
}

// Next field of the teleport file (0x00464FF8) as an integer.
// FUNCTION: TITANIUM 0x00465056
int __cdecl ParseNumber_guess(const char* input_guess) {
    char buffer_guess[256];
    copyStringUntilDelimiter_guess(input_guess, buffer_guess);
    return atoi(buffer_guess);
}

// Next field of the teleport file (0x00464FF8) as a floating-point number.
// FUNCTION: TITANIUM 0x0046508F
double __cdecl ParseAlternateNumber_guess(const char* input_guess) {
    char buffer_guess[256];
    copyStringUntilDelimiter_guess(input_guess, buffer_guess);
    return atof(buffer_guess);
}

struct LookupEntry_guess {
    int key_guess;
    float first_guess;
    float second_guess;
    float third_guess;
    float fourth_guess;
    int value_guess;
};
#define gLookupEntries_guess EQ_ARRAY(LookupEntry_guess, 0x009043E8)

// msg_teleport_index (the Mac name, in EverQuest.cpp of the earlier sibling decomp): loads
// <zone>_tp.txt rows (index, four floats, zone id) into the teleport table at 0x9043E8.
// A missing file only waits a second; a file with no header line waits 5 s and exits the client.
// FUNCTION: TITANIUM 0x00465108
// @early-stop: budget, structural ndiff=20
// Reads <name>_tp.txt into the lookup table.
void __cdecl msg_teleport_index_guess(const char* name_guess) {
    char path_guess[256];
    char line_guess[2048];
    int count_guess = 0;
    bool done_guess = false;
    FUN_0060e450_guess(path_guess, name_guess);
    FUN_0060e460_guess(path_guess, "_tp.txt");
    FILE* file_guess = fopen(path_guess, "rt");
    if (file_guess == 0) {
        Sleep(1000);
    } else {
        if (readLineFromFile_guess(file_guess, line_guess) <= 0) {
            Sleep(5000);
            fclose(file_guess);
            exit(0);
        }
        LookupEntry_guess* entry_guess = gLookupEntries_guess;
        do {
            if (readLineFromFile_guess(file_guess, line_guess) <= 0) {
                done_guess = true;
            } else {
                entry_guess->key_guess = ParseNumber_guess(line_guess);
                entry_guess->first_guess = (float)ParseAlternateNumber_guess(line_guess);
                entry_guess->second_guess = (float)ParseAlternateNumber_guess(line_guess);
                entry_guess->third_guess = (float)ParseAlternateNumber_guess(line_guess);
                entry_guess->fourth_guess = (float)ParseAlternateNumber_guess(line_guess);
                entry_guess->value_guess = ParseNumber_guess(line_guess);
                ++count_guess;
                ++entry_guess;
            }
        } while (!done_guess);
        fclose(file_guess);
        gLookupCount_guess = count_guess;
    }
}

#define gFloat65244Upper_guess EQ_GLOBAL(float, 0x00645ECC)
#define gFloat65244Lower_guess EQ_GLOBAL(float, 0x00645EC8)
#define gFloat65244Add_guess EQ_GLOBAL(float, 0x00645EC4)
#define gFloat65244FirstScale_guess EQ_GLOBAL(float, 0x00642650)
#define gFloat65244SecondScale_guess EQ_GLOBAL(float, 0x00645EC0)
#define gFloat65244ThirdScale_guess EQ_GLOBAL(float, 0x00644368)

struct TransformSource_65244_guess {
    float first_000_guess;
    int value_004_guess;
    int value_008_guess;
    int value_00c_guess;
    int value_010_guess;
    int value_014_guess;
    float clamp_018_guess;
    float seed_01c_guess;
    char pad_020_guess[8];
    float seed_028_guess;
};

struct TransformDestination_65244_guess {
    float first_000_guess;
    int value_004_guess;
    int value_008_guess;
    int value_00c_guess;
    unsigned int low_010_guess : 10;
    unsigned int high_010_guess : 10;
    int value_014_guess;
    int value_018_guess;
    unsigned int bits_01c_guess : 12;
};

// Inverse of unpack_physics_guess: copies the coordinates and deltas into the bit-packed update,
// clamping the animation speed (+0x18) to the floats at 0x645EC8..0x645ECC first.
// FUNCTION: TITANIUM 0x00465244
// @early-stop: budget, diff ndiff=2
void __cdecl pack_physics_guess(TransformSource_65244_guess* source_guess,
                          TransformDestination_65244_guess* destination_guess) {
    if (source_guess->clamp_018_guess > gFloat65244Upper_guess) {
        source_guess->clamp_018_guess = gFloat65244Upper_guess;
    }
    if (source_guess->clamp_018_guess < gFloat65244Lower_guess) {
        source_guess->clamp_018_guess = gFloat65244Lower_guess;
    }
    destination_guess->first_000_guess = source_guess->first_000_guess;
    destination_guess->value_00c_guess = source_guess->value_00c_guess;
    destination_guess->value_014_guess = source_guess->value_004_guess;
    destination_guess->value_008_guess = source_guess->value_010_guess;
    destination_guess->value_018_guess = source_guess->value_008_guess;
    destination_guess->value_004_guess = source_guess->value_014_guess;
    destination_guess->bits_01c_guess =
        (int)((source_guess->seed_01c_guess + gFloat65244Add_guess) * 4.0f) % 0x800;
    destination_guess->low_010_guess = (int)(source_guess->clamp_018_guess * 40.0f);
    destination_guess->high_010_guess = (int)(source_guess->seed_028_guess * 20.0f);
}

// Whether the zone's <shortname>.s3d exists.
// FUNCTION: TITANIUM 0x00465490
bool __cdecl DoesS3dZoneFileExist_guess(int value) {
    char path[128];
    bool result = gGate_guess->FUN_005f6ed0_guess(value, path);
    if (result) {
        FUN_0060e460_guess(path, ".s3d");
        result = FUN_00576670_guess(path);
    }
    return result;
}

// Whether the zone's <shortname>.eqg exists.
// FUNCTION: TITANIUM 0x004654E4
bool __cdecl DoesEqgZoneFileExist_guess(int value) {
    char path[128];
    bool result = gGate_guess->FUN_005f6ed0_guess(value, path);
    if (result) {
        FUN_0060e460_guess(path, ".eqg");
        result = FUN_00576670_guess(path);
    }
    return result;
}

// The zone id (last field) of the teleport row with this index, -1 when there is none.
// FUNCTION: TITANIUM 0x00465538
int __cdecl GetZoneNbrFromTableIndex_guess(int value) {
    int index = 0;
    if (gLookupCount_guess > 0) {
        int* key = gTeleportKeys_guess;
        do {
            if (*key == value) {
                return gLookupValues_guess[index * 6];
            }
            ++index;
            key += 6;
        } while (index < gLookupCount_guess);
    }
    return -1;
}

struct FileStat_guess {
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    int field_00c_guess;
    int field_010_guess;
    unsigned int size_014_guess;
    int field_018_guess;
    int field_01c_guess;
    int field_020_guess;
};

// EXTERNAL: TITANIUM 0x006104F0 __stat
int __cdecl __stat(const char* path, FileStat_guess* status);

// Copies a file through memory; when the destination won't open it retries every 2 s and after
// 4 tries asks with a retry/cancel box (0x40005), Cancel giving the 'Read-only' hint. 1 ok, -1 failed.
// FUNCTION: TITANIUM 0x0046556B
// @early-stop: budget, diff ndiff=2
int __cdecl copyFileWithRetry_guess(char* source_guess, char* destination_guess,
                               char* message_guess) {
    FileStat_guess status_guess;
    void* data_guess;
    int result_guess;
    FILE* file_guess;
    int retry_guess;

    if (__stat(source_guess, &status_guess) != 0) {
        sprintf(message_guess, "ERROR: Couldn't find file %s!\n", source_guess);
        return -1;
    }

    data_guess = GlobalAlloc(0x40, status_guess.size_014_guess);
    file_guess = fopen(source_guess, "rb");
    if (file_guess == 0) {
        sprintf(message_guess, "ERROR: Couldn't open file %s for reading!\n",
                source_guess);
        GlobalFree(data_guess);
        return -1;
    }

    if (fread(data_guess, status_guess.size_014_guess, 1, file_guess) != 1) {
        sprintf(message_guess, "ERROR: Couldn't read file %s!\n", source_guess);
        result_guess = -1;
    } else {
        fclose(file_guess);
        retry_guess = 0;
        file_guess = fopen(destination_guess, "wb");
        while (file_guess == 0) {
            sprintf(message_guess, "ERROR: Couldn't open dest file %s!\n",
                    destination_guess);
            Sleep(2000);
            ++retry_guess;
            if (retry_guess > 3) {
                retry_guess = 0;
                if (MessageBoxA(0, message_guess, "EverQuest", 0x40005) == 2) {
                    sprintf(message_guess,
                            "ERROR: Unable to update %s! Please look at the Properties of this file to ensure that 'Read-only' is NOT checked, then try again.\n",
                            destination_guess);
                    GlobalFree(data_guess);
                    return -1;
                }
            }
            file_guess = fopen(destination_guess, "wb");
        }
        result_guess = 1;
        if (fwrite(data_guess, status_guess.size_014_guess, 1, file_guess) != 1) {
            sprintf(message_guess, "ERROR: Couldn't write to dest file %s!\n",
                    destination_guess);
            result_guess = -1;
        }
    }
    fclose(file_guess);
    GlobalFree(data_guess);
    return result_guess;
}

// EXTERNAL: TITANIUM 0x004B6C04 MemChecker0
int __cdecl MemChecker0(void* data, unsigned int size);

// Checksums a whole file with 0x4B6C04 into *result; 1 ok, -1 when it can't be read.
// FUNCTION: TITANIUM 0x004656C2
// @early-stop: budget, diff ndiff=25
int __cdecl calculateFileCRC32_guess(const char* path, int* result) {
    FileStat_guess status;
    if (__stat(path, &status) != 0) {
        return -1;
    }
    HGLOBAL data = GlobalAlloc(0x40, status.size_014_guess);
    FILE* file = fopen(path, "rb");
    if (file != 0) {
        size_t count = fread(data, status.size_014_guess, 1, file);
        if (count == 1) {
            fclose(file);
            int value = MemChecker0(data, status.size_014_guess);
            GlobalFree(data);
            *result = value;
            return 1;
        }
        fclose(file);
    }
    GlobalFree(data);
    return -1;
}

struct FileRecord_guess {
    char pad_000[0x16];
    unsigned char type_016_guess;
};

// Same skill list as the older client's function plus 74 (frenzy).
// FUNCTION: TITANIUM 0x00465750
// @early-stop: budget, structural ndiff=25
int __cdecl IsWeaponAttackDamageType_guess(FileRecord_guess* record) {
    int value = record->type_016_guess;
    if (value <= 0x1a) {
        if (value == 0x1a) {
            return 1;
        }
        if (value < 0) {
            return 0;
        }
        if (value <= 3) {
            return 1;
        }
        if (value == 8) {
            return 1;
        }
        if (value == 10) {
            return 1;
        }
        if (value == 0x15) {
            return 1;
        }
        return value == 0x17;
    }
    if (value == 0x1c) {
        return 1;
    }
    if (value == 0x1e) {
        return 1;
    }
    if (value <= 0x23) {
        return 0;
    }
    if (value <= 0x26) {
        return 1;
    }
    if (value <= 0x32) {
        return 0;
    }
    if (value <= 0x34) {
        return 1;
    }
    return value == 0x4a;
}

struct Random_guess {
    int index_guess;    // 0x0
    int offset_guess;   // 0x4
    int table_guess[55]; // 0x8
};
#define gRandom_guess EQ_GLOBAL(Random_guess, 0x009005C8)

// RandNbr (as in the earlier sibling decomp): additive lagged-Fibonacci generator over the 55-entry table at
// 0x9005D0, two indexes walking it in step; returns a 24-bit value.
// FUNCTION: TITANIUM 0x004657A6
int __cdecl RandNbr_guess(void) {
    Random_guess* random = &gRandom_guess;
    int index = random->index_guess;
    int offset = random->offset_guess;
    int* slot = &random->table_guess[random->index_guess];
    // Entries keep 30 bits; the result drops the low 6.
    int result = (random->table_guess[offset] + *slot) & 0x3fffffff;
    *slot = result;
    if (++index == 0x37) {
        index = 0;
    }
    if (++offset == 0x37) {
        offset = 0;
    }
    random->index_guess = index;
    random->offset_guess = offset;
    return result >> 6;
}

// Random percentage roll, 1-100 (RandNbr).
// FUNCTION: TITANIUM 0x004657EC
int __cdecl number_percent_guess(void) {
    return RandNbr_guess() % 100 + 1;
}

struct LookupCheck_46_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 LookupCheck_46_guess::Check_guess
    int Check_guess(int value_guess);
};
#define g_lookupCheck_46_guess EQ_GLOBAL(LookupCheck_46_guess, 0x009248E0)

// EXTERNAL: TITANIUM 0x00574860 FUN_00574860_guess
int __cdecl FUN_00574860_guess(const char* text, int* length);

// EXTERNAL: TITANIUM 0x004788E1 ContainsProfanity_guess
char __cdecl ContainsProfanity_guess(const char* value, int length);

// With option 6 (probably the profanity filter) on, copies the text and stars out every word the
// bad-word list 0x4788E1 matches; otherwise a plain copy.
// FUNCTION: TITANIUM 0x004657FB
void __cdecl FilterBadWords_guess(const char* source, char* destination) {
    if (source != 0 && destination != 0) {
        if (g_lookupCheck_46_guess.Check_guess(6) == 1) {
            FUN_0060e450_guess(destination, source);
            char* current = destination;
            do {
                int length;
                while (FUN_00574860_guess(current, &length) != 0) {
                    current += length;
                }
                int wordLength = 0;
                char* start = current;
                if (*current == '\0') {
                    return;
                }
                do {
                    if (FUN_00574860_guess(current, &length) != 0) {
                        break;
                    }
                    current += length;
                    wordLength += length;
                } while (*current != '\0');
                if (wordLength > 0 && ContainsProfanity_guess(start, wordLength) != 0) {
                    for (int i = 0; i < wordLength; ++i) {
                        start[i] = '*';
                    }
                }
            } while (*current != '\0');
        } else {
            FUN_0060e450_guess(destination, source);
        }
    }
}

// EXTERNAL: TITANIUM 0x0062202C strnicmp_guess
int __cdecl strnicmp_guess(const char* first, const char* second, size_t count);

// True when `first` is a case-insensitive prefix of `second`; false when either is empty.
// FUNCTION: TITANIUM 0x004658AC
int __cdecl IsStringPrefix_guess(char* first, char* second) {
    if (*first == '\0' || *second == '\0') {
        return false;
    }
    return strnicmp_guess(first, second, strlen(first)) == 0;
}

// EXTERNAL: TITANIUM 0x00574830 FUN_00574830_guess
int __cdecl FUN_00574830_guess(char* text, int* offset);

// Optional sign, then digits only (UTF-8 aware). A lone "+" or "-" counts as a number.
// FUNCTION: TITANIUM 0x004658DD
int __cdecl is_number_guess(char* text) {
    char* current = text;
    if (*current == '\0') {
        return 0;
    }
    if (*current == '+' || *current == '-') {
        ++current;
    }
    int offset = 0;
    while (*current != '\0') {
        if (FUN_00574830_guess(current, &offset) == 0) {
            return 0;
        }
        current += offset;
    }
    return 1;
}

struct FontService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess(char* text_guess, float value_guess, int* data_guess);
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess(int index, int value, const char* name);
};

#define gFontService_guess EQ_GLOBAL(FontService_guess*, 0x0099E360)
#define gFontIndex_guess EQ_GLOBAL(int, 0x00923D74)
#define gFontNames_guess EQ_ARRAY(const char*, 0x00799830)
#define gPlayerStateSheathe_guess EQ_GLOBAL(int, 0x00647CAC)

struct FlagIndex_465CD6_guess {
    char pad_000_guess[4];
    int index_004_guess;
};

struct FlagState_465CD6_guess {
    char pad_000_guess[0xc284];
    FlagIndex_465CD6_guess* index_284_guess;
    char pad_c288_guess[0x104];
    unsigned char flags_c38c_guess[1];
};

struct MenuHandler_465CD6_guess {
    // EXTERNAL: TITANIUM 0x0042FCF9 MenuHandler_465CD6_guess::CanDisplay_guess
    char CanDisplay_guess();
    // EXTERNAL: TITANIUM 0x00430F03 MenuHandler_465CD6_guess::RespondToInvite_guess
    void RespondToInvite_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004310A3 MenuHandler_465CD6_guess::RemoveSelectedOrLeave_guess
    void RemoveSelectedOrLeave_guess();
    // EXTERNAL: TITANIUM 0x00431136 MenuHandler_465CD6_guess::RequestLootType_guess
    void RequestLootType_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004311CC MenuHandler_465CD6_guess::RequestAddLooter_guess
    void RequestAddLooter_guess();
    // EXTERNAL: TITANIUM 0x00431258 MenuHandler_465CD6_guess::RequestRemoveLooter_guess
    void RequestRemoveLooter_guess();
    // EXTERNAL: TITANIUM 0x0042FF95 MenuHandler_465CD6_guess::RaidSay_guess
    void RaidSay_guess(int value_guess);
};

#define gFlagState_465CD6_guess EQ_GLOBAL(FlagState_465CD6_guess*, 0x00905D00)
#define gFlagFallback_465CD6_guess EQ_GLOBAL(int, 0x00923D60)
#define pMenuHandler_465CD6_guess EQ_ARRAY(MenuHandler_465CD6_guess, 0x0091D708)

// /raiddecline: answers the raid invite with 0.
// FUNCTION: TITANIUM 0x00465BFF
void __cdecl do_raiddecline_guess() {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0 ||
        gFlagFallback_465CD6_guess != 0) {
        pMenuHandler_465CD6_guess->RespondToInvite_guess(0);
    }
}

// /raidaccept: answers with 1; no test-server bypass.
// FUNCTION: TITANIUM 0x00465C2D
void __cdecl do_raidaccept_guess() {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0) {
        MenuHandler_465CD6_guess* handler_guess = pMenuHandler_465CD6_guess;
        if (handler_guess->CanDisplay_guess() != 0) {
            gGlobalContext_guess->SetText_guess(
                gTextLookup_guess->FindText_guess(0x22a5, 0), 0xd, 1);
        } else {
            handler_guess->RespondToInvite_guess(1);
        }
    }
}

// /raiddisband.
// FUNCTION: TITANIUM 0x00465C83
void __cdecl do_raiddisband_guess() {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0 ||
        gFlagFallback_465CD6_guess != 0) {
        pMenuHandler_465CD6_guess->RemoveSelectedOrLeave_guess();
    }
}

// /setloottype <n>: no test-server bypass.
// FUNCTION: TITANIUM 0x00465CAF
void __cdecl do_setloottype_guess(int unused_guess, int value_guess) {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0) {
        pMenuHandler_465CD6_guess->RequestLootType_guess(value_guess);
    }
}

// /addraidlooter: no test-server bypass.
// FUNCTION: TITANIUM 0x00465CD6
void __cdecl do_addraidlooter_guess() {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0) {
        pMenuHandler_465CD6_guess->RequestAddLooter_guess();
    }
}

// /removeraidlooter.
// FUNCTION: TITANIUM 0x00465CF9
void __cdecl do_removeraidlooter_guess() {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0 ||
        gFlagFallback_465CD6_guess != 0) {
        pMenuHandler_465CD6_guess->RequestRemoveLooter_guess();
    }
}

// /rsay <text>: raid chat, the same call InterpretCmd uses.
// FUNCTION: TITANIUM 0x00465D25
void __cdecl do_rsay_guess(int unused_guess, int value_guess) {
    if ((gFlagState_465CD6_guess->flags_c38c_guess[
             gFlagState_465CD6_guess->index_284_guess->index_004_guess] & 8) != 0 ||
        gFlagFallback_465CD6_guess != 0) {
        pMenuHandler_465CD6_guess->RaidSay_guess(value_guess);
    }
}

// /fontface <face>: saves [Fonts] Font.<current font>.0 and applies it; usage eqstr 0xD32 when empty.
// FUNCTION: TITANIUM 0x00465D55
void __cdecl do_fontface_guess(int unused, char* text) {
    char buffer[0x100];
    if (*text == '\0') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0xd32, 0), 0xf, 1);
    } else {
        sprintf(buffer, "Font.%s.0", gFontNames_guess[gFontIndex_guess]);
        gGlobalContext_guess->WriteCharIniString_guess(text, "Fonts", buffer);
        gFontService_guess->Slot30_guess(gFontIndex_guess, -1, text);
    }
}

// /sheathe: toggles player state 0x647CAC, sending OP_PlayerStateRemove 0x381D when it was set and
// OP_PlayerStateAdd 0x63DA when not (spawn id, state). AddPlayerState_guess
// (0x47BFEB) sets it.
// FUNCTION: TITANIUM 0x00465DEA
void __cdecl do_sheathe_guess(void) {
    Payload_guess payload;
    payload.spawnId_0000_guess = gConnection_guess->spawnId_0258_guess;
    payload.message = gPlayerStateSheathe_guess;
    if (gConnection_guess->HasPlayerState_guess(payload.message)) {
        gConnection_guess->RemovePlayerState_guess(gPlayerStateSheathe_guess);
        SendMessage_guess(&gSendTarget_guess, OP_PlayerStateRemove, &payload, 8, 1);
    } else {
        gConnection_guess->AddPlayerState_guess(gPlayerStateSheathe_guess);
        SendMessage_guess(&gSendTarget_guess, OP_PlayerStateAdd, &payload, 8, 1);
    }
}

// /aggressive: the same toggle for player state 0x647CB4.
// FUNCTION: TITANIUM 0x00465E51
void __cdecl do_aggressive_guess(void) {
    Payload_guess payload;
    payload.spawnId_0000_guess = gConnection_guess->spawnId_0258_guess;
    payload.message = gPlayerStateAggressive_guess;
    if (gConnection_guess->HasPlayerState_guess(payload.message)) {
        gConnection_guess->RemovePlayerState_guess(gPlayerStateAggressive_guess);
        SendMessage_guess(&gSendTarget_guess, OP_PlayerStateRemove, &payload, 8, 1);
    } else {
        gConnection_guess->AddPlayerState_guess(gPlayerStateAggressive_guess);
        SendMessage_guess(&gSendTarget_guess, OP_PlayerStateAdd, &payload, 8, 1);
    }
}

struct CommandState_65eb8_guess {
    // EXTERNAL: TITANIUM 0x004CB2B7 CommandState_65eb8_guess::Enabled_guess
    char Enabled_guess();
    // EXTERNAL: TITANIUM 0x004CB2CB CommandState_65eb8_guess::HasMacro_guess
    char HasMacro_guess(long value_guess);
    // EXTERNAL: TITANIUM 0x004CB42F CommandState_65eb8_guess::Apply_guess
    void Apply_guess(long value_guess, long flags_guess);
    // EXTERNAL: TITANIUM 0x004CB2F6 CommandState_65eb8_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x004CB2DD CommandState_65eb8_guess::GetCount_guess
    int GetCount_guess(long value_guess);
};

#define gCommandState65eb8_guess EQ_GLOBAL(CommandState_65eb8_guess*, 0x00985D90)

// /vplay <n>: plays voice macro n when voice macros are available; usage eqstr 0x1781.
// FUNCTION: TITANIUM 0x00465EB8
void __cdecl do_vplay_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x200];
    if (gCommandState65eb8_guess->Enabled_guess()) {
        if (text_guess == 0 || *text_guess == '\0') {
            gGlobalContext_guess->SetText_guess(
                gTextLookup_guess->FindText_guess(0x1781, 0), 0, 1);
        } else {
            GrabFirstWord_guess(text_guess, buffer_guess, 0x32);
            long value_guess = atol(buffer_guess);
            if (gCommandState65eb8_guess->HasMacro_guess(value_guess)) {
                gCommandState65eb8_guess->Apply_guess(value_guess, -1);
            }
        }
    }
}

struct SpellbookPanel_guess {
    // EXTERNAL: TITANIUM 0x00557A73 SpellbookPanel_guess::SaveSpellbookFile_guess
    void SaveSpellbookFile_guess(char* buffer_guess);
};

#define gSpellbookPanel_guess EQ_GLOBAL(SpellbookPanel_guess*, 0x00850C30)
#define gGuildText_guess EQ_ARRAY(char, 0x00646080)
#define gGateFlag_guess EQ_GLOBAL(int, 0x00924470)

// EXTERNAL: TITANIUM 0x0059DD30 FUN_0059dd30_guess
char __cdecl FUN_0059dd30_guess();

// /raidwindow: toggles the raid window (0x850BF0).
// FUNCTION: TITANIUM 0x00465AC6
void __cdecl do_raidwindow_guess() {
    if (pinstCRaidWnd_guess != 0) {
        if (pinstCRaidWnd_guess->IsVisible_guess() != 0) {
            pinstCRaidWnd_guess->Deactivate();
        } else {
            pinstCRaidWnd_guess->Activate();
        }
        pinstCRaidWnd_guess->StoreIniVis();
    }
}

// Dispatches a /command with a text argument to the matching panel.
// /outputfile guild|raid|spellbook|inventory|guildbank [file]: dumps that list to a file; usage eqstr
// 0xD9F. guildbank needs the zone gate check on 0x924470, else eqstr 0x188C.
// FUNCTION: TITANIUM 0x00465F51
void __cdecl do_outputfile_guess(int unused_guess, const char* text_guess) {
    char argument_guess[0x200];
    char command_guess[0x100];
    if (text_guess == 0 || *text_guess == '\0') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0xd9f, 0), 0, 1);
        return;
    }
    int rest_guess = GrabFirstWord_guess(text_guess, command_guess, 0x32);
    GrabFirstWord_guess((const char*)rest_guess, argument_guess, 0x100);
    if (__stricmp(command_guess, "guild") == 0) {
        if (pinstCGuildManagementWnd_guess == 0) {
            return;
        }
        pinstCGuildManagementWnd_guess->DumpList_guess(argument_guess, gGuildText_guess);
        return;
    }
    if (__stricmp(command_guess, "raid") == 0) {
        if (pinstCRaidWnd_guess == 0) {
            return;
        }
        pinstCRaidWnd_guess->DumpRoster_guess(argument_guess);
        return;
    }
    if (__stricmp(command_guess, "spellbook") == 0) {
        if (gSpellbookPanel_guess == 0) {
            return;
        }
        gSpellbookPanel_guess->SaveSpellbookFile_guess(argument_guess);
        return;
    }
    if (__stricmp(command_guess, "inventory") == 0) {
        if (pinstCInventoryWnd_guess == 0) {
            return;
        }
        pinstCInventoryWnd_guess->WriteInventoryFile_guess(argument_guess);
        return;
    }
    if (__stricmp(command_guess, "guildbank") != 0) {
        return;
    }
    if (gGate_guess->FUN_005f6d40_guess(gGateFlag_guess) != 0 && pinstCGuildBankWnd_guess != 0) {
        pinstCGuildBankWnd_guess->SaveGuildBank_guess(argument_guess);
        return;
    }
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x188c, 0), 0, 1);
}

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00494473 IsTransactionWindowOpen_guess
char __cdecl IsTransactionWindowOpen_guess();

struct KeyLookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 KeyLookup_guess::GetKey_guess
    int GetKey_guess(int value_guess);
};

#define gKeyLookup_guess EQ_GLOBAL(KeyLookup_guess*, 0x00985CC8)

struct ShadowState_guess {
    // EXTERNAL: TITANIUM 0x00436156 ShadowState_guess::Enable_guess
    void Enable_guess(int value);
    // EXTERNAL: TITANIUM 0x00436129 ShadowState_guess::SetShadowClipPlane_guess
    void SetShadowClipPlane_guess(int value);
};
#define gShadowState_guess EQ_GLOBAL(ShadowState_guess*, 0x00905D24)

struct ShadowArgs_guess {
    char value_guess[0x28];
    char mode_guess[0x28];
};

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* text, const char* value);

// /shadows on [clip 0-100] | off: eqstr 0x3293/0x3292 are the on/off words; saves [Defaults] Shadows
// and [Options] ShadowClipPlane; eqstr 0x1B5A on, 0x1B5B off, 0x1B59 usage.
// FUNCTION: TITANIUM 0x004660EA
// @early-stop: budget, structural ndiff=24
void __cdecl do_shadows_guess(int unused_guess, const char* text_guess) {
    ShadowArgs_guess args_guess;
    char* mode_guess = args_guess.mode_guess;
    char* value_guess = args_guess.value_guess;
    int remainder_guess = GrabFirstWord_guess(text_guess, mode_guess, 0x28);
    GrabFirstWord_guess((const char*)remainder_guess, value_guess, 0x28);
    if (FUN_00574950_guess(mode_guess, gTextLookup_guess->FindText_guess(0x3293, 0)) != 0) {
        if (FUN_00574950_guess(mode_guess, gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
            gShadowState_guess->Enable_guess(0);
            gGlobalContext_guess->WriteFlag_guess(0, "Defaults", "Shadows");
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x1b5b, 0));
        } else {
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x1b59, 0));
        }
    } else {
        gShadowState_guess->Enable_guess(1);
        gGlobalContext_guess->WriteFlag_guess(1, "Defaults", "Shadows");
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x1b5a, 0));
        if (is_number_guess(value_guess) != 0) {
            long clip_guess = atol(value_guess);
            if (clip_guess > 100) {
                clip_guess = 100;
            } else if (clip_guess < 0) {
                clip_guess = 0;
            }
            gShadowState_guess->SetShadowClipPlane_guess(clip_guess);
            gGlobalContext_guess->WriteInt_guess(clip_guess, "Options", "ShadowClipPlane");
        }
    }
}

// Mac allowslashcommand: 0 with a message when the interface is safelocked (0x95A174, eqstr 0x2F3F),
// the player is stunned (stand state 'f' 0x66, eqstr 0x3050), the spell being cast isn't usable by the
// class (eqstr 0x328A) or 0x494473 reports busy (eqstr 0x2F34).
// FUNCTION: TITANIUM 0x00466244
int __cdecl allowslashcommand_guess(void) {
    if (EQ_GLOBAL(char, 0x0095A174) != 0) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2f3f, 0), 0x111, 1);
    } else if (gConnection_guess != 0 && gConnection_guess->standState_0251_guess == 'f') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x3050, 0), 0x111, 1);
    } else if (IsValidSpellIndex_guess(gConnection_guess->pActorInfo_01a8_guess->castingSpellId_0f98_guess) != 0 &&
               g_stateHolder_guess->command_c280_guess.IsBardSong_guess(
                   gKeyLookup_guess->GetKey_guess(gConnection_guess->pActorInfo_01a8_guess->castingSpellId_0f98_guess),
                   gConnection_guess->playerClass_0252_guess) == 0) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x328a, 0), 0x111, 1);
    } else {
        if (IsTransactionWindowOpen_guess() != 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2f34, 0), 0x111, 1);
        } else {
            return 1;
        }
    }
    return 0;
}

// /setstartcity <text>: OP_SetStartCity 0x41DC.
// FUNCTION: TITANIUM 0x00466317
void __cdecl do_setstartcity_guess(int unused, char* text) {
    if (text != 0) {
        size_t size = strlen(text);
        SendMessage_guess(&gSendTarget_guess, OP_SetStartCity, text, size + 1, 1);
    }
}

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* text, const char* value);

// /potionbelt <keyword> <slot>: needs expansion bit 0x100 (probably Dragons of Norrath); keywords are
// eqstr 0x245D/0x245E (Delete/Activate per usage 0x248C); slot is 1-based.
// FUNCTION: TITANIUM 0x0046633F
void __cdecl do_potionbelt_guess(int unused_guess, const char* text_guess) {
    char command_guess[0x28];
    char number_guess[0x28];
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        int remainder_guess = GrabFirstWord_guess(text_guess, command_guess, 0x28);
        GrabFirstWord_guess((const char*)remainder_guess, number_guess, 0x28);
        long value_guess = atol(number_guess) - 1;
        if (FUN_00574950_guess(command_guess,
                               gTextLookup_guess->FindText_guess(0x245d, 0)) == 0) {
            g_stateHolder_guess->RemovePotionBeltItem_guess(value_guess);
        } else if (FUN_00574950_guess(command_guess,
                                      gTextLookup_guess->FindText_guess(0x245e, 0)) == 0) {
            g_stateHolder_guess->UsePotionBeltItem_guess(value_guess);
        } else {
            gGlobalContext_guess->SetText_guess(
                gTextLookup_guess->FindText_guess(0x248c, 0), 0xf, 1);
        }
    }
}

// /bandolier <keyword> <set>: keywords eqstr 0x245A (add) and 0x245D/0x245E; the set is matched by
// name among the 20 sets, else used as the number typed (0-based, unlike /potionbelt). Usage 0x2471.
// FUNCTION: TITANIUM 0x00466428
void __cdecl do_bandolier_guess(int unused_guess, const char* text_guess) {
    char command_guess[0x28];
    char number_guess[0x28];
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        int remainder_guess = GrabFirstWord_guess(text_guess, command_guess, 0x28);
        GrabFirstWord_guess((const char*)remainder_guess, number_guess, 0x28);
        long value_guess = atol(number_guess);
        if (FUN_00574950_guess(command_guess,
                               gTextLookup_guess->FindText_guess(0x245a, 0)) == 0) {
            g_stateHolder_guess->SaveBandolier_guess(number_guess);
        } else if (FUN_00574950_guess(command_guess,
                                      gTextLookup_guess->FindText_guess(0x245d, 0)) == 0) {
            int index_guess = value_guess;
            for (int i = 0; i < 0x14; ++i) {
                if (FUN_00574950_guess(number_guess,
                                       g_stateHolder_guess->FUN_005f0c30_guess(i)) == 0) {
                    index_guess = i;
                    break;
                }
            }
            g_stateHolder_guess->DeleteBandolier_guess(index_guess);
        } else if (FUN_00574950_guess(command_guess,
                                      gTextLookup_guess->FindText_guess(0x245e, 0)) == 0) {
            int index_guess = value_guess;
            for (int i = 0; i < 0x14; ++i) {
                if (FUN_00574950_guess(number_guess,
                                       g_stateHolder_guess->FUN_005f0c30_guess(i)) == 0) {
                    index_guess = i;
                    break;
                }
            }
            g_stateHolder_guess->UseBandolier_guess(index_guess);
        } else {
            gGlobalContext_guess->Show_guess(
                gTextLookup_guess->FindTextTyped_guess(0x2471, 0, 0xf, 1));
        }
    }
}

struct Connection_4665_guess {
    char pad_000_guess[0x258];
    int field_258_guess;
};
#define gConnection_4665_guess EQ_GLOBAL(Connection_4665_guess*, 0x00905CE4)

// /servers (GM): OP_GMServers 0x3387 with the player's spawn id.
// FUNCTION: TITANIUM 0x004665B3
void __cdecl do_servers_guess() {
    if (gConnection_4665_guess != 0) {
        FUN_004912b1_guess(&gSendTarget_guess, OP_GMServers,
                           &gConnection_4665_guess->field_258_guess, 4, 1);
    }
}

// /selfkill: confirmation popup 0x7E, eqstr 0x1822, 10 s timeout.
// FUNCTION: TITANIUM 0x004665D9
void __cdecl do_selfkill_guess() {
    gDispatch_475BAB_guess->PostCompact_guess(
        gGlobalHead_475BAB_guess ? &gGlobalHead_475BAB_guess->link_008_guess : 0,
        0x7e,
        gTextLookup_guess->FindTextWithOptions_guess(0x1822, 0, 0xc, 0x2710,
                                                     0, 0));
}

// /delcorpse [name] (GM): OP_GMDelCorpse 0xB2F with the corpse name and the GM's name (64 bytes each);
// no name means the target, which must be a corpse (spawn type 2 or 3), else eqstr 0x32A2.
// FUNCTION: TITANIUM 0x00466615
void __cdecl do_delcorpse_guess(int unused_guess, char* text_guess) {
    char message_guess[0x81];
    memset(message_guess, 0, sizeof(message_guess));
    if (strcmp(text_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
        FUN_0060e450_guess(message_guess, text_guess);
        FUN_0060e450_guess(message_guess + 0x40, gConnection_guess->text_120_guess);
        SendMessage_guess(&gSendTarget_guess, OP_GMDelCorpse, message_guess, sizeof(message_guess), 1);
    } else {
        if (gIncomingMessage_guess == 0 || gIncomingMessage_guess->byte_244_guess <= 1) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x32a2, 0));
            return;
        }
        FUN_0060e450_guess(message_guess, gIncomingMessage_guess->text_120_guess);
        FUN_0060e450_guess(message_guess + 0x40, gConnection_guess->text_120_guess);
        SendMessage_guess(&gSendTarget_guess, OP_GMDelCorpse, message_guess, sizeof(message_guess), 1);
    }
}

// /who: forwards the arguments to the Who handler 0x49C800.
// FUNCTION: TITANIUM 0x004666D3
void __cdecl cmd_who_guess(int arg1, int arg2) {
    gGlobalContext_guess->Dispatch_guess(arg2);
}

struct MessagePacket_4666E3_guess {
    int index_000_guess;
    char text_004_guess[0x84];
    char text_088_guess[0x200];
};

// /guildmotd [text]: OP_SetGuildMOTD 0x591C (guild id, name, MOTD up to 511 chars; empty clears it).
// Needs a guild (eqstr 0x32A6) and a rank above member (eqstr 0x1401).
// FUNCTION: TITANIUM 0x004666E3
void __cdecl do_guildmotd_guess(IncomingMessage_guess* input_guess, char* text_guess) {
    // Guild ids are below 1500; -1 means no guild.
    if (input_guess->index_288_guess == -1 || input_guess->index_288_guess >= 0x5dc) {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x32a6, 0));
    } else {
        if (input_guess->value_27c_guess <= 0) {
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x1401, 0));
        } else {
            MessagePacket_4666E3_guess packet_guess;
            memset(&packet_guess, 0, sizeof(packet_guess));
            if (strlen(text_guess) == 0 || strlen(text_guess) >= 0x200) {
                packet_guess.text_088_guess[0] = 0;
            } else {
                FUN_0060e450_guess(packet_guess.text_088_guess, text_guess);
            }
            FUN_0060e450_guess(packet_guess.text_004_guess, input_guess->text_120_guess);
            packet_guess.index_000_guess = input_guess->index_288_guess;
            FUN_004912b1_guess(&gSendTarget_guess, OP_SetGuildMOTD, &packet_guess, sizeof(packet_guess), 1);
        }
    }
}

// /getguildmotd: OP_GetGuildMOTD 0x7FEC (guild id, name).
// FUNCTION: TITANIUM 0x004667DC
void __cdecl do_getguildmotd_guess(IncomingMessage_guess* input) {
    if (input->index_288_guess == -1 || input->index_288_guess >= 0x5dc) {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x32a6, 0));
    } else {
        OutgoingMessage_guess message;
        memset(&message, 0, sizeof(message));
        FUN_0060e450_guess(message.text_guess, input->text_120_guess);
        message.index_guess = input->index_288_guess;
        SendMessage_guess(&gSendTarget_guess, OP_GetGuildMOTD, &message, sizeof(message), 1);
    }
}

// /guildwar [guild] [days]: days 1..14, anything else 14; no name means the target.
// FUNCTION: TITANIUM 0x0046687F
void __cdecl do_guildwar_guess(int unused, const char* input) {
    char text[0x20];
    int value = (int)atol((char*)GrabFirstWord_guess(input, text, sizeof(text)));
    if (value <= 0) {
        value = 0xe;
    }
    if (value > 0xe) {
        value = 0xe;
    }
    if (text[0] == '\0' && gIncomingMessage_guess != 0) {
        FUN_0060e450_guess(text, gIncomingMessage_guess->text_120_guess);
    }
    gGlobalContext_guess->GuildWar(text, value);
}

// /guildpeace [guild]: no name means the target.
// FUNCTION: TITANIUM 0x004668F1
void __cdecl do_guildpeace_guess(int unused_guess, const char* text_guess) {
    if (text_guess[0] == '\0' && gIncomingMessage_guess != 0) {
        gGlobalContext_guess->FUN_0049dc19_guess(
            gIncomingMessage_guess->text_120_guess);
    } else {
        gGlobalContext_guess->FUN_0049dc19_guess(text_guess);
    }
}

// /guildinvite <name>.
// FUNCTION: TITANIUM 0x00466918
void __cdecl do_guildinvite_guess(int unused, const char* input) {
    char text[0x40];
    text[0] = '\0';
    int length = GrabFirstWord_guess(input, text, sizeof(text));
    gGlobalContext_guess->GuildInvite_guess(text, length);
}

// /guildremove <name>.
// FUNCTION: TITANIUM 0x00466955
void __cdecl do_guildremove_guess(int arg1, int arg2) {
    gGlobalContext_guess->GuildRemove_guess(arg2);
}

// /guilddelete: rank below 2 (leader) gets eqstr 0x2363; otherwise confirmation popup 0x6D, eqstr
// 0x2364, 20 s.
// FUNCTION: TITANIUM 0x00466965
// @early-stop: budget, structural ndiff=6
void __cdecl do_guilddelete_guess() {
    GlobalContext_guess* context_guess = gGlobalContext_guess;
    if (gState_466965_guess->state_0e10_guess < 2) {
        context_guess->Show_guess(
            gTextLookup_guess->FindTextTyped_guess(0x2363, 0, 0x111, 1));
        return;
    }

    const char* text_guess = gTextLookup_guess->FindTextWithOptions_guess(
        0x2364, 0, 0xc, 20000, 0, 0);
    int* owner_guess = gGlobalContext_guess != 0
        ? &gGlobalContext_guess->owner_008_guess : 0;
    gDispatch_475BAB_guess->PostCompact_guess(
        owner_guess, 0x6d, text_guess);
}

// /guildleader <name>.
// FUNCTION: TITANIUM 0x00466980
void __cdecl do_guildleader_guess(int arg1, int arg2) {
    gGlobalContext_guess->GuildLeader_guess(arg2);
}

// /guildsay <text>.
// FUNCTION: TITANIUM 0x00466990
void __cdecl do_guildsay_guess(int arg1, int arg2) {
    gGlobalContext_guess->GuildSay_guess(arg2);
}

// /random [low] high: OP_RandomReq 0x5534 (low, high), swapped into order. Each number at most 6 digits
// (eqstr 0x3304), not negative (0x3305), high at most 32000 (0x3306).
// FUNCTION: TITANIUM 0x004669AB
void __cdecl do_random_guess(int unused, const char* input) {
    char text[0x40];
    const char* converted = (const char*)GrabFirstWord_guess(input, text, sizeof(text));
    if (strlen(converted) <= 6 && strlen(text) <= 6) {
        long first = atol_guess(converted);
        long second = atol_guess(text);
        if (first < 0 || second < 0) {
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3305, 0));
        } else {
            long high;
            if (first > second) {
                high = first;
                first = second;
            } else {
                high = second;
            }
            if (high > 0x7d00) {
                gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3306, 0));
            } else {
                int values[2];
                values[0] = first;
                values[1] = high;
                FUN_004912b1_guess(&gSendTarget_guess, OP_RandomReq, values, sizeof(values), 1);
            }
        }
    } else {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3304, 0));
    }
}

struct Session_guess {
    char pad_000_guess[0x1b6];
    char flag_1b6_guess;
    char pad_1b7_guess[0x244 - 0x1b7];
    unsigned char spawnType_0244_guess;
    char pad_245_guess[0x258 - 0x245];
    int value_258_guess;
};

// /consider: the target (or the given spawn) gets OP_Consider 0x65CA, a corpse OP_ConsiderCorpse 0x773F.
// No target eqstr 0x3307; spawns flagged +0x1B6 eqstr 0x3308. spawnType_0244_guess is the spawn type
// (0 PC, 1 NPC, 2/3 corpse).
// FUNCTION: TITANIUM 0x00466A73
// @early-stop: budget, structural ndiff=24
void __cdecl do_consider_guess(int session_arg, char* text_guess) {
    struct Packet_guess {
        int value_0;
        int value_4;
        int value_8;
        int value_c;
        int value_10;
        int value_14;
        int value_18;
    } packet;
    Session_guess* session_guess = (Session_guess*)session_arg;
    int error_id = 0;
    if (session_arg == 0 || *text_guess == '\0') {
        session_guess = (Session_guess*)gIncomingMessage_guess;
    }
    if (session_guess == 0) {
        error_id = 0x3307;
    } else if (session_guess->spawnType_0244_guess >= 2) {
        packet.value_0 = gConnection_guess->spawnId_0258_guess;
        packet.value_4 = session_guess->value_258_guess;
        SendMessage_guess(&gSendTarget_guess, OP_ConsiderCorpse, &packet, sizeof(packet), 1);
        return;
    } else if (session_guess->flag_1b6_guess != 0) {
        error_id = 0x3308;
    } else {
        packet.value_0 = gConnection_guess->spawnId_0258_guess;
        packet.value_4 = session_guess->value_258_guess;
        SendMessage_guess(&gSendTarget_guess, OP_Consider, &packet, sizeof(packet), 1);
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x1d, 0);
        }
        return;
    }
    pEverQuest->dsp_chat(gTextLookup_guess->FindText_guess(error_id, 0));
}

// /chat <text>: prefixes ';' and sends the line to the chat server; usage eqstr 0x3309.
// FUNCTION: TITANIUM 0x00466B46
void __cdecl do_chat_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x800];
    if (text_guess == 0 || *text_guess == '\0') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x3309, 0), 0x111, 1);
    } else {
        if (*text_guess != ';') {
            buffer_guess[0] = ';';
            buffer_guess[1] = 0;
            FUN_0060e460_guess(buffer_guess, text_guess);
        } else {
            FUN_0060e450_guess(buffer_guess, text_guess);
        }
        gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, 1);
        gGlobalContext_guess->ChatServerMessage_guess(buffer_guess);
    }
}

// InterpretCmd channel case 0x14: prefixes '[' and hands the line to the mail-server command 0x4A95FF.
// FUNCTION: TITANIUM 0x00466BE3
void __cdecl SendMailChannelText_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x800];
    if (text_guess == 0 || *text_guess == '\0') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x3309, 0), 0x111, 1);
    } else {
        if (*text_guess != '[') {
            buffer_guess[0] = '[';
            buffer_guess[1] = 0;
            FUN_0060e460_guess(buffer_guess, text_guess);
        } else {
            FUN_0060e450_guess(buffer_guess, text_guess);
        }
        gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, 1);
        gGlobalContext_guess->SendMailServerCommand_guess(buffer_guess);
    }
}

// EXTERNAL: TITANIUM 0x0060E590 FUN_0060e590_guess
int __cdecl FUN_0060e590_guess(const char* text, const char* source);

// EXTERNAL: TITANIUM 0x00574270 FUN_00574270_guess
int __cdecl FUN_00574270_guess(const char* text_guess);

// EXTERNAL: TITANIUM 0x00574700 FUN_00574700_guess
char* __cdecl FUN_00574700_guess(char* text);

// EXTERNAL: TITANIUM 0x00574800 FUN_00574800_guess
int __cdecl FUN_00574800_guess(char* text, int* offset);

#define gSuffix_guess EQ_ARRAY(char, 0x0063FDE0)

// /emote <text>: refused (eqstr 0x330B, 0x330C) when over 511 chars, two spaces in a row, or the
// lower-cased text holds eqstr 0x330A and the player isn't a GM. Adds the suffix at 0x63FDE0 after
// a final letter or digit.
// FUNCTION: TITANIUM 0x00466C80
void __cdecl do_emote_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x400];
    int offset_guess;
    char* start = text_guess;
    int length_guess = strlen(start);
    if (length_guess > 0x1ff) {
        length_guess = 0;
    }
    FUN_0060e450_guess(buffer_guess, start);
    _strlwr(buffer_guess);
    if (FUN_0060e590_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x330a, 0)) != 0 &&
        gConnection_guess->gm_0256_guess == 0) {
        length_guess = 0;
    }
    char* cursor = start;
    char character = *start;
    do {
        if (character == 0) {
            break;
        }
        if (FUN_00574860_guess(cursor, &offset_guess) != 0) {
            cursor += offset_guess;
            if (*cursor == 0) {
                break;
            }
            if (FUN_00574860_guess(cursor, 0) != 0) {
                length_guess = 0;
                break;
            }
        } else {
            cursor += FUN_00574270_guess(cursor);
        }
        character = *cursor;
    } while (true);
    if (length_guess < 1) {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x330b, 0));
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x330c, 0));
    } else {
        FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, start);
        char* last = FUN_00574700_guess(start + length_guess - 1);
        if (FUN_00574800_guess(last, 0) != 0 || FUN_00574830_guess(last, 0) != 0) {
            FUN_0060e460_guess(&gGlobalContext_guess->text_17bb4_guess, gSuffix_guess);
        }
        gGlobalContext_guess->Emote_guess();
    }
}

// Shared body of the socials (/smile through /flex): each handler passes its social id, 0 to 0x57, as
// `text` (an id, not a string), and this splits off the first word (0x42DD82, GrabFirstWord) and calls
// send_social 0x49E0C1. /frown, /wave, /cheer and /gesture work only while standing still (stand
// state 'd', speed < 0.1), else eqstr 0x330D.
// FUNCTION: TITANIUM 0x00466DEA
void __cdecl DoSocial_guess(const char* text, const char* source) {
    char buffer[0x840];
    int length = GrabFirstWord_guess(source, buffer, 0x840);
    gGlobalContext_guess->send_social_guess(text, buffer, length);
}

// /smile: sends social 0 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466E32
void __cdecl social_smile_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess(0, source_guess);
}

// /laugh: sends social 2 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466E9B
void __cdecl social_laugh_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)2, source_guess);
}

// /cry: sends social 3 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EA9
void __cdecl social_cry_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)3, source_guess);
}

// /chuckle: sends social 4 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EB7
void __cdecl social_chuckle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)4, source_guess);
}

// /hug: sends social 5 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EC5
void __cdecl social_hug_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)5, source_guess);
}

// /poke: sends social 6 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466ED3
void __cdecl social_poke_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)6, source_guess);
}

// /bow: sends social 7 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EE1
void __cdecl social_bow_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)7, source_guess);
}

// /bounce: sends social 8 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EEF
void __cdecl social_bounce_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)8, source_guess);
}

// /panic: sends social 9 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466EFD
void __cdecl social_panic_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)9, source_guess);
}

// /nod: sends social 10 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466F0B
void __cdecl social_nod_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)10, source_guess);
}

// /rofl: sends social 11 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00466F19
void __cdecl social_rofl_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)11, source_guess);
}

// Social 0x0C; refused with eqstr 0x330D unless standing still (stand state 'd', speed < 0.1). See
// 0x00466DEA.
// FUNCTION: TITANIUM 0x00466F27
// @early-stop: budget, structural ndiff=5
void __cdecl social_wave_guess(int unused_guess, const char* source_guess) {
    if (gControlled_472313_guess->standState_0251_guess == 'd' &&
        _fabs(gControlled_472313_guess->speedRun_0048_guess) < 0.1) {
        DoSocial_guess((const char*)0xc, source_guess);
        return;
    }
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0x330d, 0));
}

// Social 0x0D; refused with eqstr 0x330D unless standing still (stand state 'd', speed < 0.1). See
// 0x00466DEA.
// FUNCTION: TITANIUM 0x00466F82
// @early-stop: budget, structural ndiff=5
void __cdecl social_cheer_guess(int unused_guess, const char* source_guess) {
    if (gControlled_472313_guess->standState_0251_guess == 'd' &&
        _fabs(gControlled_472313_guess->speedRun_0048_guess) < 0.1) {
        DoSocial_guess((const char*)0xd, source_guess);
        return;
    }
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0x330d, 0));
}

// /adriver and /sdriver: prints eqstr 0x305B (sound card info).
// FUNCTION: TITANIUM 0x00466FDD
// @early-stop: budget, structural ndiff=2
void __cdecl do_adriver_guess() {
    pEverQuest->dsp_chat(pStringTable->getString(0x305b, 0), 4, true);
}

// /gesture: social 14, only while standing still (see 0x00466DEA).
// FUNCTION: TITANIUM 0x00466FE8
void __cdecl social_gesture_guess(int unused_guess, const char* source_guess) {
    if (gControlled_472313_guess->standState_0251_guess == 'd') {
        float speed_guess = (float)_fabs(gControlled_472313_guess->speedRun_0048_guess);
        if (speed_guess < 0.1f) {
            DoSocial_guess((const char*)0xe, source_guess);
            return;
        }
    }
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0x330d, 0));
}

// /agree: sends social 15 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467043
void __cdecl social_agree_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0xf, source_guess);
}

// /amaze: sends social 16 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467051
void __cdecl social_amaze_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x10, source_guess);
}

// /apologize: sends social 17 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046705F
void __cdecl social_apologize_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x11, source_guess);
}

// /applaud: sends social 18 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046706D
void __cdecl social_applaud_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x12, source_guess);
}

// /plead: sends social 19 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046707B
void __cdecl social_plead_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x13, source_guess);
}

// /bite: sends social 20 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467089
void __cdecl social_bite_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x14, source_guess);
}

// /bleed: sends social 21 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467097
void __cdecl social_bleed_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x15, source_guess);
}

// /blink: sends social 22 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670A5
void __cdecl social_blink_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x16, source_guess);
}

// /blush: sends social 23 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670B3
void __cdecl social_blush_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x17, source_guess);
}

// /boggle: sends social 24 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670C1
void __cdecl social_boggle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x18, source_guess);
}

// /bonk: sends social 25 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670CF
void __cdecl social_bonk_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x19, source_guess);
}

// /bored: sends social 26 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670DD
void __cdecl social_bored_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1a, source_guess);
}

// /brb: sends social 27 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670EB
void __cdecl social_brb_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1b, source_guess);
}

// /burp: sends social 28 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004670F9
void __cdecl social_burp_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1c, source_guess);
}

// /bye: sends social 29 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467107
void __cdecl social_bye_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1d, source_guess);
}

// /cackle: sends social 30 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467115
void __cdecl social_cackle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1e, source_guess);
}

// /calm: sends social 31 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467123
void __cdecl social_calm_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x1f, source_guess);
}

// /clap: sends social 32 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467131
void __cdecl social_clap_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x20, source_guess);
}

// /comfort: sends social 33 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046713F
void __cdecl social_comfort_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x21, source_guess);
}

// /congratulate: sends social 34 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046714D
void __cdecl social_congratulate_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x22, source_guess);
}

// /cough: sends social 35 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046715B
void __cdecl social_cough_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x23, source_guess);
}

// /cringe: sends social 36 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467169
void __cdecl social_cringe_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x24, source_guess);
}

// /curious: sends social 37 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467177
void __cdecl social_curious_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x25, source_guess);
}

// /dance: sends social 38 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467185
void __cdecl social_dance_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x26, source_guess);
}

// /drool: sends social 39 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467193
void __cdecl social_drool_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x27, source_guess);
}

// /duck: sends social 40 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671A1
void __cdecl social_duck_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x28, source_guess);
}

// /eye: sends social 41 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671AF
void __cdecl social_eye_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x29, source_guess);
}

// /gasp: sends social 42 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671BD
void __cdecl social_gasp_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2a, source_guess);
}

// /giggle: sends social 43 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671CB
void __cdecl social_giggle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2b, source_guess);
}

// /glare: sends social 44 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671D9
void __cdecl social_glare_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2c, source_guess);
}

// /grin: sends social 45 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671E7
void __cdecl social_grin_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2d, source_guess);
}

// /groan: sends social 46 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004671F5
void __cdecl social_groan_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2e, source_guess);
}

// /grovel: sends social 47 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467203
void __cdecl social_grovel_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x2f, source_guess);
}

// /happy: sends social 48 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467211
void __cdecl social_happy_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x30, source_guess);
}

// /hungry: sends social 49 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046721F
void __cdecl social_hungry_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x31, source_guess);
}

// /introduce: sends social 50 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046722D
void __cdecl social_introduce_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x32, source_guess);
}

// /jk: sends social 51 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046723B
void __cdecl social_jk_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x33, source_guess);
}

// /kneel: sends social 52 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467249
void __cdecl social_kneel_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x34, source_guess);
}

// /lost: sends social 53 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467257
void __cdecl social_lost_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x35, source_guess);
}

// /massage: sends social 54 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467265
void __cdecl social_massage_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x36, source_guess);
}

// /moan: sends social 55 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467273
void __cdecl social_moan_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x37, source_guess);
}

// /mourn: sends social 56 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467281
void __cdecl social_mourn_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x38, source_guess);
}

// /peer: sends social 57 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046728F
void __cdecl social_peer_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x39, source_guess);
}

// /point: sends social 58 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046729D
void __cdecl social_point_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3a, source_guess);
}

// /ponder: sends social 59 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672AB
void __cdecl social_ponder_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3b, source_guess);
}

// /puzzle: sends social 60 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672B9
void __cdecl social_puzzle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3c, source_guess);
}

// /raise: sends social 61 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672C7
void __cdecl social_raise_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3d, source_guess);
}

// /ready: sends social 62 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672D5
void __cdecl social_ready_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3e, source_guess);
}

// /roar: sends social 63 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672E3
void __cdecl social_roar_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x3f, source_guess);
}

// /salute: sends social 64 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672F1
void __cdecl social_salute_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x40, source_guess);
}

// /shiver: sends social 65 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004672FF
void __cdecl social_shiver_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x41, source_guess);
}

// /shrug: sends social 66 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046730D
void __cdecl social_shrug_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x42, source_guess);
}

// /sigh: sends social 67 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046731B
void __cdecl social_sigh_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x43, source_guess);
}

// /smirk: sends social 68 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467329
void __cdecl social_smirk_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x44, source_guess);
}

// /snarl: sends social 69 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467337
void __cdecl social_snarl_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x45, source_guess);
}

// /snicker: sends social 70 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467345
void __cdecl social_snicker_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x46, source_guess);
}

// /stare: sends social 71 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467353
void __cdecl social_stare_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x47, source_guess);
}

// /tap: sends social 72 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467361
void __cdecl social_tap_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x48, source_guess);
}

// /tease: sends social 73 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046736F
void __cdecl social_tease_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x49, source_guess);
}

// /thank: sends social 74 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046737D
void __cdecl social_thank_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4a, source_guess);
}

// /thirsty: sends social 75 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x0046738B
void __cdecl social_thirsty_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4b, source_guess);
}

// /veto: sends social 76 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467399
void __cdecl social_veto_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4c, source_guess);
}

// /welcome: sends social 77 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673A7
void __cdecl social_welcome_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4d, source_guess);
}

// /whine: sends social 78 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673B5
void __cdecl social_whine_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4e, source_guess);
}

// /whistle: sends social 79 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673C3
void __cdecl social_whistle_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x4f, source_guess);
}

// /yawn: sends social 80 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673D1
void __cdecl social_yawn_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x50, source_guess);
}

// /smack: sends social 81 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673DF
void __cdecl social_smack_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x51, source_guess);
}

// /pat: sends social 82 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673ED
void __cdecl social_pat_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x52, source_guess);
}

// /fidget: sends social 84 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x004673FB
void __cdecl social_fidget_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x54, source_guess);
}

// /nudge: sends social 83 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467409
void __cdecl social_nudge_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x53, source_guess);
}

// /purr: sends social 85 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467417
void __cdecl social_purr_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x55, source_guess);
}

// /kiss: sends social 86 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467425
void __cdecl social_kiss_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x56, source_guess);
}

// /flex: sends social 87 (shared body 0x00466DEA).
// FUNCTION: TITANIUM 0x00467433
void __cdecl social_flex_guess(int unused_guess, const char* source_guess) {
    DoSocial_guess((const char*)0x57, source_guess);
}

// /inquire: GM only (player +0x256); forwarded to the guide object 0x850C9C.
// FUNCTION: TITANIUM 0x004691AF
void __cdecl do_inquire_guess(int arg1, int arg2) {
    if (gConnection_guess->gm_0256_guess != 0 && pinstCSoulmarkWnd_guess != 0) {
        pinstCSoulmarkWnd_guess->DoInquireCommand_guess(arg2);
    }
}

// /praise: GM only.
// FUNCTION: TITANIUM 0x004691D1
void __cdecl do_praise_guess(int arg1_guess, int arg2_guess) {
    if (gConnection_guess->gm_0256_guess != 0 && pinstCSoulmarkWnd_guess != 0) {
        pinstCSoulmarkWnd_guess->DoPraiseCommand_guess(arg2_guess);
    }
}

// /warn: GM only.
// FUNCTION: TITANIUM 0x004691F3
void __cdecl do_warn_guess(int arg1_guess, int arg2_guess) {
    if (gConnection_guess->gm_0256_guess != 0 && pinstCSoulmarkWnd_guess != 0) {
        pinstCSoulmarkWnd_guess->DoWarnCommand_guess(arg2_guess);
    }
}

// /quit: refused while safelocked (eqstr 0x2F3F) and ignored while stunned; drops the world connection.
// FUNCTION: TITANIUM 0x00469215
void __cdecl do_quit_guess(int unused_guess, char* command_guess) {
    if (command_guess == 0 || *command_guess == 0) {
        if (EQ_GLOBAL(char, 0x0095A174) != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x2f3f, 0));
            return;
        }
        if (gConnection_guess->standState_0251_guess != 'f') {
            FUN_00574110_guess("*** DISCONNECTING: Quit command received.\n");
            int one_guess = 1;
            gDisconnectStatus_guess = (char)one_guess;
            gQuitState_guess->quit_39400_guess = one_guess;
            gGlobalContext_guess->SetGameState(0xff);
            gQuitCode_guess = 0xfd;
            gQuitState_guess->quit_b50_guess = one_guess;
            if (gWorldConnection_guess != 0) {
                gWorldConnection_guess->FUN_0040be64_guess(0);
                gWorldConnection_guess->FUN_0040beae_guess(10000);
                gWorldConnection_guess->Slot01_guess();
                gWorldConnection_guess = 0;
            }
            gDisconnectStatus_guess = 2;
        }
    }
}

// EXTERNAL: TITANIUM 0x00611859 __exit
__declspec(noreturn) void __cdecl __exit(int status);

// /exit: /quit plus a 500 ms wait and _exit(0).
// FUNCTION: TITANIUM 0x004692E1
void __cdecl do_exit_guess(int unused_guess, char* command_guess) {
    if (command_guess == 0 || *command_guess == 0) {
        if (EQ_GLOBAL(char, 0x0095A174) != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x2f3f, 0));
            return;
        }
        if (gConnection_guess->standState_0251_guess != 'f') {
            FUN_00574110_guess("*** DISCONNECTING: Exit command received.\n");
            int one_guess = 1;
            gDisconnectStatus_guess = (char)one_guess;
            gQuitState_guess->quit_39400_guess = one_guess;
            gGlobalContext_guess->SetGameState(0xff);
            gQuitCode_guess = 0xfd;
            gQuitState_guess->quit_b50_guess = one_guess;
            if (gWorldConnection_guess != 0) {
                gWorldConnection_guess->FUN_0040be64_guess(0);
                gWorldConnection_guess->FUN_0040beae_guess(10000);
                gWorldConnection_guess->Slot01_guess();
                gWorldConnection_guess = 0;
            }
            gDisconnectStatus_guess = 2;
            Sleep(500);
            __exit(0);
        }
    }
}

struct NetStats_4693b7_guess {
    int f00_guess, f04_guess, f08_guess, f0c_guess, f10_guess, f14_guess;
    int f18_guess, f1c_guess, f20_guess, f24_guess, f28_guess, f2c_guess;
    int f30_guess, f34_guess, f38_guess, f3c_guess, f40_guess, f44_guess;
    int f48_guess, f4c_guess, f50_guess, f54_guess, f58_guess, f5c_guess;
    int f60_guess, f64_guess, f68_guess;
    long master_6c_guess;
    long average_70_guess;
    long low_74_guess;
    long high_78_guess;
    long last_7c_guess;
    long reliable_80_guess;
    int f84_guess, f88_guess, f8c_guess, f90_guess, f94_guess, f98_guess;
    int f9c_guess, fa0_guess, fa4_guess;
    float sent_a8_guess;
    float rcvd_ac_guess;
};

struct NetConn_4693b7_guess {
    // EXTERNAL: TITANIUM 0x005E5200 NetConn_4693b7_guess::GetStats_guess
    void GetStats_guess(NetStats_4693b7_guess* output_guess);
};
#define gNetConn_4693b7_guess EQ_GLOBAL(NetConn_4693b7_guess*, 0x00905CA0)

struct ChatSink_4693b7_guess {
    // EXTERNAL: TITANIUM 0x004F2F8A ChatSink_4693b7_guess::AddChat_guess
    void AddChat_guess(CXStr text_guess, int color_guess);
};
#define gChatSink_4693b7_guess EQ_GLOBAL(ChatSink_4693b7_guess*, 0x009917E4)

// /netstats: ping times and packet loss (1 - ratio, in percent) of the world connection.
// FUNCTION: TITANIUM 0x004693B7
void __cdecl do_netstats_guess(int unused_guess, char* command_guess) {
    NetStats_4693b7_guess stats_guess;
    char buffer_guess[120];

    gNetConn_4693b7_guess->GetStats_guess(&stats_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr((const char*)EQ_ARRAY(char, 0x0063F53F)), 10);
    gChatSink_4693b7_guess->AddChat_guess(CXStr("\nPing Times"), 15);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;master=%ld", stats_guess.master_6c_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;average=%ld", stats_guess.average_70_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;low=%ld", stats_guess.low_74_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;high=%ld", stats_guess.high_78_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;last=%ld", stats_guess.last_7c_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;reliable avg=%ld", stats_guess.reliable_80_guess);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    gChatSink_4693b7_guess->AddChat_guess(CXStr((const char*)EQ_ARRAY(char, 0x0063F53F)), 10);
    gChatSink_4693b7_guess->AddChat_guess(CXStr("\nPacket Loss"), 15);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;sent=%0.2f%%\n", (1.0f - stats_guess.sent_a8_guess) * 100.0f);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    sprintf(buffer_guess, "&NBSP;&NBSP;&NBSP;rcvd=%0.2f%%\n", (1.0f - stats_guess.rcvd_ac_guess) * 100.0f);
    gChatSink_4693b7_guess->AddChat_guess(CXStr(buffer_guess), 10);
    gChatSink_4693b7_guess->AddChat_guess(CXStr((const char*)EQ_ARRAY(char, 0x0063F53F)), 10);
}

// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section, const char* key,
                                const char* value, const char* filename);

#define gShowGrass_guess EQ_GLOBAL(int, 0x00924824)
#define gGrassInitialized_guess EQ_GLOBAL(int, 0x00924828)
#define gGrassAmount_guess EQ_GLOBAL(float, 0x0092482C)
#define gGrassLimit_guess EQ_GLOBAL(int, 0x00850B90)

// /rewind: OP_Rewind 0x4CFA.
// FUNCTION: TITANIUM 0x00469609
void __cdecl do_rewind_guess() {
    FUN_004912b1_guess(&gSendTarget_guess, OP_Rewind, 0, 0, 1);
}

// /showgrass on|off: [Defaults] ShowGrass; loads the zone's grass on first use (eqstr 0x337C without a
// player); 0x3380 usage.
// FUNCTION: TITANIUM 0x00469622
void __cdecl do_showgrass_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x20];

    if (*text_guess != '\0') {
        if (FUN_00574950_guess(text_guess,
                               pStringTable->getString(0x3293, 0)) == 0) {
            if (gShowGrass_guess == 0) {
                gShowGrass_guess = 1;
                pEverQuest->dsp_chat(pStringTable->getString(0x337b, 0));
                FUN_0060beb0_guess("Defaults", "ShowGrass", "TRUE",
                                   ".\\eqclient.ini");
                if (gGrassInitialized_guess == 0) {
                    if (gConnection_guess != 0) {
                        gGate_guess->FUN_005f6ed0_guess(
                            gConnection_guess->field_204_guess, buffer_guess);
                        gFontService_guess->Slot25_guess(
                            buffer_guess, gGrassAmount_guess, &gGrassLimit_guess);
                        gGrassInitialized_guess = 1;
                    } else {
                        pEverQuest->dsp_chat(
                            pStringTable->getString(0x337c, 0));
                        return;
                    }
                }
                gNpcNameState_guess->UpdateGrassDisplacement_guess();
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x337d, 0));
            }
        } else if (FUN_00574950_guess(
                       text_guess, pStringTable->getString(0x3292, 0)) == 0) {
            if (gShowGrass_guess == 1) {
                gShowGrass_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x337e, 0));
                FUN_0060beb0_guess("Defaults", "ShowGrass", "FALSE",
                                   ".\\eqclient.ini");
                gNpcNameState_guess->ClearGrassDisplacement_guess();
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x337f, 0));
            }
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x3380, 0));
            if (gShowGrass_guess != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x337b, 0));
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x337e, 0));
            }
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x3380, 0));
        if (gShowGrass_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x337b, 0));
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x337e, 0));
        }
    }
}


// /barter: opens the window at 0x9915EC.
// FUNCTION: TITANIUM 0x00469812
void __cdecl do_barter_guess() {
    CBarterSearchWnd_guess* action_guess = pinstCBarterSearchWnd_guess;
    if (action_guess != 0) {
        action_guess->Show(1, 1);
    }
}

// /buyer: opens the window at 0x991608.
// FUNCTION: TITANIUM 0x00469829
void __cdecl do_buyer_guess() {
    CBarterWnd_guess* action_guess = pinstCBarterWnd_guess;
    if (action_guess != 0) {
        action_guess->Show(1, 1);
    }
}

// /consent <name>: OP_Consent 0x1081; eqstr 0x2523 'To remove consent, use /deny'.
// FUNCTION: TITANIUM 0x0046985C
void __cdecl do_consent_guess(int unused_guess, char* text_guess) {
    if (strlen(text_guess) != 0) {
        gGlobalContext_guess->SetText_guess(pStringTable->getString(0x2523, 0), 0xf, 1);
        size_t sendLength_guess = strlen(text_guess);
        FUN_004912b1_guess(&gSendTarget_guess, OP_Consent, text_guess,
                           sendLength_guess + 1, 1);
    }
}

// /deny <name>: OP_ConsentDeny 0x4E8C.
// FUNCTION: TITANIUM 0x004698AD
void __cdecl do_deny_guess(int unused_guess, char* text_guess) {
    size_t length_guess = strlen(text_guess);
    if (length_guess != 0) {
        size_t sendLength_guess = strlen(text_guess);
        FUN_004912b1_guess(&gSendTarget_guess, OP_ConsentDeny, text_guess,
                           sendLength_guess + 1, 1);
    }
}

struct AfkPacket_guess {
    short value_guess;
    short tag_guess;
    int afk_guess;
};

#define gAfkText_guess EQ_GLOBAL(char, 0x00924688)

// /afk [off|message]: no text toggles; sets the chat-server AFK silently and sends OP_SpawnAppearance
// 0x7C32 type 0x18 (AFK).
// FUNCTION: TITANIUM 0x004699A9
void __cdecl do_afk_guess(int unused_guess, char* text_guess) {
    AfkPacket_guess packet_guess;
    if (FUN_00574990_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
        gConnection_guess->SetAFK_guess(0);
        gAfkText_guess = 0;
    } else if (strlen(text_guess) > 0) {
        gConnection_guess->SetAFK_guess(1);
        if (strlen(text_guess) < 0x100) {
            FUN_0060e450_guess(&gAfkText_guess, text_guess);
        }
    } else {
        gConnection_guess->SetAFK_guess(1 - gConnection_guess->afk_26c_guess);
        gAfkText_guess = 0;
    }
    if (gConnection_guess->afk_26c_guess != 0) {
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x338f, 0), 0x111, 1);
        gGlobalContext_guess->ChatServerMessage_guess(";afk on silent");
    } else {
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x3390, 0), 0x111, 1);
        gGlobalContext_guess->ChatServerMessage_guess(";afk off silent");
    }
    packet_guess.tag_guess = 0x18;
    packet_guess.value_guess = (short)gConnection_guess->spawnId_0258_guess;
    packet_guess.afk_guess = gConnection_guess->afk_26c_guess;
    SendMessage_guess(&gSendTarget_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
}

// /loot: loots the target; eqstr 0x3391 without one.
// FUNCTION: TITANIUM 0x00469AC4
void __cdecl do_loot_guess(void) {
    int state_guess = EQ_GLOBAL(int, 0x00905D04);
    if (state_guess == 0) {
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x3391, state_guess), 0x111, 1);
    } else {
        gGlobalContext_guess->LootCorpse_guess(state_guess, 0);
    }
}

struct ActiveFlags_46_guess {
    char pad_000_guess[0x14];
    unsigned char active_014_guess;
};

struct VirtualAction_46_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(int value_guess);
};

struct ActorObject_46_guess {
    VirtualAction_46_guess* action_000_guess;
    char pad_004_guess[0xec4];
    int flag_ec8_guess;
};

struct Spawn_46_guess {
    char pad_000_guess[0x120];
    char name_120_guess[0x40];
    char pad_160_guess[0x48];
    ActorObject_46_guess* actor_1a8_guess;
    char pad_1ac_guess[0x68];
    Spawn_46_guess* next_214_guess;
    char pad_218_guess[0x2c];
    unsigned char type_244_guess;
    // EXTERNAL: TITANIUM 0x004793B5 Spawn_46_guess::GetNameText_guess
    const char* GetNameText_guess();
};

#define gActiveFlags_46_guess EQ_GLOBAL(ActiveFlags_46_guess*, 0x00905D24)
#define gSpawnList_46_guess EQ_GLOBAL(Spawn_46_guess*, 0x00905CC4)

struct CharData_46_guess {
    // EXTERNAL: TITANIUM 0x004BB226 CharData_46_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(const char* text_guess);
};
#define gCharData_46_guess EQ_GLOBAL(CharData_46_guess*, 0x00905D00)

// /hidecorpses <eqstr 0x3395|0x3397|0x33F6|other>: hide every other corpse, every corpse but the
// group's, flag new corpses hidden (+0x14 of 0x905D24), or show all. Usage 0x3392..0x3394.
// FUNCTION: TITANIUM 0x00469B01
void __cdecl do_hidecorpses_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x40];
    if (*text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x3392, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x3393, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x3394, 0));
    } else {
        gActiveFlags_46_guess->active_014_guess = 0;
        Spawn_46_guess* spawn_guess = gSpawnList_46_guess;
        if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3395, 0)) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x3396, 0), 0xf, 1);
            for (; spawn_guess != 0; spawn_guess = spawn_guess->next_214_guess) {
                if (spawn_guess->type_244_guess == 2 || spawn_guess->type_244_guess == 3) {
                    FUN_0060e450_guess(buffer_guess, spawn_guess->GetNameText_guess());
                    if (__stricmp(buffer_guess, gConnection_guess->text_120_guess) != 0) {
                        if (spawn_guess->actor_1a8_guess != 0 &&
                            spawn_guess->actor_1a8_guess->action_000_guess != 0) {
                            spawn_guess->actor_1a8_guess->flag_ec8_guess = 1;
                            spawn_guess->actor_1a8_guess->action_000_guess->Slot06_guess(1);
                        }
                    }
                }
            }
        } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3397, 0)) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x3398, 0), 0xf, 1);
            for (; spawn_guess != 0; spawn_guess = spawn_guess->next_214_guess) {
                if (spawn_guess->type_244_guess == 2 || spawn_guess->type_244_guess == 3) {
                    FUN_0060e450_guess(buffer_guess, spawn_guess->GetNameText_guess());
                    if (__stricmp(buffer_guess, gConnection_guess->text_120_guess) != 0) {
                        for (int count_guess = 6; count_guess != 0; --count_guess) {
                            if (__stricmp(buffer_guess, gConnection_guess->text_120_guess) != 0) {
                                if (gCharData_46_guess->IsAGroupMember_guess(buffer_guess) == 0) {
                                    if (spawn_guess->actor_1a8_guess != 0 &&
                                        spawn_guess->actor_1a8_guess->action_000_guess != 0) {
                                        spawn_guess->actor_1a8_guess->flag_ec8_guess = 1;
                                        spawn_guess->actor_1a8_guess->action_000_guess->Slot06_guess(1);
                                    }
                                } else if (spawn_guess->actor_1a8_guess != 0 &&
                                           spawn_guess->actor_1a8_guess->action_000_guess != 0) {
                                    spawn_guess->actor_1a8_guess->flag_ec8_guess = 0;
                                    spawn_guess->actor_1a8_guess->action_000_guess->Slot06_guess(0);
                                }
                            }
                        }
                    }
                }
            }
        } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x33f6, 0)) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33f7, 0), 0xf, 1);
            gActiveFlags_46_guess->active_014_guess = 1;
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x3399, 0), 0xf, 1);
            for (; spawn_guess != 0; spawn_guess = spawn_guess->next_214_guess) {
                if (spawn_guess->type_244_guess == 2 || spawn_guess->type_244_guess == 3) {
                    if (spawn_guess->actor_1a8_guess != 0 &&
                        spawn_guess->actor_1a8_guess->action_000_guess != 0) {
                        spawn_guess->actor_1a8_guess->flag_ec8_guess = 0;
                        spawn_guess->actor_1a8_guess->action_000_guess->Slot06_guess(0);
                    }
                }
            }
        }
    }
}

// Empty: the handler of /reverb, /resetwindows and /popmail, and an ICF-folded no-op in many vtables.
// FUNCTION: TITANIUM 0x00469DD7
void __cdecl NoOp_guess(void) {
}

// /inspect: on a class-62 (LDoN treasure) target within 20 units sends opcode 0x46BE, no payload
// (not in patch_Titanium.conf; probably the LDoN inspect). eqstr 0x2144/0x2145/0x214F refusals.
// FUNCTION: TITANIUM 0x00469DD8
void __cdecl do_inspect_guess(void) {
    if (gIncomingMessage_guess == 0) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2144, 0), 0x10e, 1);
        return;
    }
    if (gIncomingMessage_guess->classId_0252_guess != '>') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2145, 0), 0x10e, 1);
    } else if (gNpcNameState_guess->PlayerDistance_guess(gIncomingMessage_guess, gConnection_guess, 1.0f) > 20.0f) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x214f, 0), 0x10e, 1);
    } else {
        SendMessage_guess(&gSendTarget_guess, 0x46be, 0, 0, 1);
    }
}

// /open: OP_LDoNOpen 0x083B under the same checks; refusals eqstr 0x2146/0x2147/0x2150.
// FUNCTION: TITANIUM 0x00469E6C
void __cdecl do_open_guess(void) {
    if (gIncomingMessage_guess == 0) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2146, 0), 0x10e, 1);
        return;
    }
    if (gIncomingMessage_guess->classId_0252_guess != '>') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2147, 0), 0x10e, 1);
    } else if (gNpcNameState_guess->PlayerDistance_guess(gIncomingMessage_guess, gConnection_guess, 1.0f) > 20.0f) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2150, 0), 0x10e, 1);
    } else {
        SendMessage_guess(&gSendTarget_guess, OP_LDoNOpen, 0, 0, 1);
    }
}

#define gInspectOthers_guess EQ_GLOBAL(int, 0x00924848)

// /toggleinspect on|off: [Defaults] InspectOthers.
// FUNCTION: TITANIUM 0x00469F00
void __cdecl do_toggleinspect_guess(int unused_guess, char* text_guess) {
    int zero_guess = 0;
    if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3293, 0)) == zero_guess) {
        gInspectOthers_guess = 1;
        FUN_0060beb0_guess("Defaults", "InspectOthers", "TRUE", ".\\eqclient.ini");
    } else if (__stricmp(text_guess, pStringTable->getString(0x3292, 0)) == zero_guess) {
        gInspectOthers_guess = zero_guess;
        FUN_0060beb0_guess("Defaults", "InspectOthers", "FALSE", ".\\eqclient.ini");
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x339a, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x339b, 0));
    }
    if (gInspectOthers_guess != zero_guess) {
        pEverQuest->dsp_chat(pStringTable->getString(0x339c, 0));
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x339d, 0));
    }
}

// /emotezone <text> (GM): OP_GMEmoteZone 0x39F2, 512 bytes.
// FUNCTION: TITANIUM 0x00469FE7
void __cdecl do_emotezone_guess(int unused, const char* source) {
    char buffer[0x200];
    memset(buffer, 0, 0x200);
    FUN_0060e450_guess(buffer, source);
    buffer[0x1ff] = 0;
    SendMessage_guess(&gSendTarget_guess, OP_GMEmoteZone, buffer, 0x200, 1);
}

// /emoteworld <text> (GM): OP_GMEmoteWorld 0x3383, 512 bytes.
// FUNCTION: TITANIUM 0x0046A047
void __cdecl do_emoteworld_guess(int unused, const char* source) {
    char buffer[0x200];
    memset(buffer, 0, 0x200);
    FUN_0060e450_guess(buffer, source);
    buffer[0x1ff] = 0;
    SendMessage_guess(&gSendTarget_guess, OP_GMEmoteWorld, buffer, 0x200, 1);
}

#define gReverseSound_guess EQ_GLOBAL(int, 0x009254E4)

// /reversesound <eqstr 0x3340|0x33A0>: [Options] ReverseSound; usage 0x339E/0x339F.
// FUNCTION: TITANIUM 0x0046A0A7
void __cdecl do_reversesound_guess(int unused_guess, char* text_guess) {
    int zero_guess = 0;

    if (*text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x339e, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x339f, 0));
    } else if (FUN_00574990_guess(text_guess,
                                  pStringTable->getString(0x3340, 0), 4) == zero_guess) {
        gReverseSound_guess = zero_guess;
    } else if (__strnicmp(text_guess,
                          pStringTable->getString(0x33a0, 0), 3) == zero_guess) {
        gReverseSound_guess = 1;
    }

    if (gReverseSound_guess == 1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x33a1, 0));
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x33a2, 0));
    }
    gGlobalContext_guess->WriteInt_guess(gReverseSound_guess, "Options", "ReverseSound");
}

// /movelog: OP_MoveLogRequest 0x7510.
// FUNCTION: TITANIUM 0x0046A18A
void __cdecl do_movelog_guess() {
    FUN_004912b1_guess(EQ_ARRAY(int, 0x00905ca0), OP_MoveLogRequest, 0, 0, 1);
}

#define gToggleState_46A1A3_guess EQ_GLOBAL(int, 0x00924788)

// /log [on|off]: toggles the chat-log flag 0x924788.
// FUNCTION: TITANIUM 0x0046A1A3
// @early-stop: budget, structural ndiff=27
void __cdecl do_log_guess(int unused_guess, const char* text_guess) {
    bool* result_guess = 0;
    if (FUN_00574990_guess(text_guess, pStringTable->getString(0x3292, result_guess), 3) == 0) {
        gToggleState_46A1A3_guess = 0;
        gGlobalContext_guess->SetText_guess(
            pStringTable->getString(0x33a6, result_guess), 0x111, 1);
    } else {
        StringTable* table_guess = pStringTable;
        if (FUN_00574990_guess(text_guess, table_guess->getString(0x3293, result_guess), 2) == 0) {
            gToggleState_46A1A3_guess = 1;
        } else {
            gToggleState_46A1A3_guess = 1 - gToggleState_46A1A3_guess;
        }
        if (gToggleState_46A1A3_guess == 0) {
            gGlobalContext_guess->SetText_guess(
                pStringTable->getString(0x33a6, result_guess), 0x111, 1);
        } else {
            gGlobalContext_guess->SetText_guess(
                pStringTable->getString(0x33a5, result_guess), 0x111, 1);
        }
    }
}

struct OptionsPacket_46A265_guess {
    short field_0_guess;
    short type_2_guess;
    int flags_4_guess;
};

struct Options_46A265_guess {
    char pad_000_guess[0x258];
    short field_258_guess;
    char pad_25a_guess[0x264 - 0x25a];
    int flags_264_guess;
    // EXTERNAL: TITANIUM 0x00479E97 Options_46A265_guess::IsOn_guess
    bool IsOn_guess();
    // EXTERNAL: TITANIUM 0x0047AA0B Options_46A265_guess::Refresh_guess
    void Refresh_guess();
};
#define gOptions_46A265_guess EQ_GLOBAL(Options_46A265_guess*, 0x00905CE4)

struct CharFlags_46A265_guess {
    char pad_000_guess[0xe24];
    bool flag_e24_guess;
};
#define gCharFlags_46A265_guess EQ_GLOBAL(CharFlags_46A265_guess*, 0x00905D00)
#define gPhase_46A265_guess EQ_GLOBAL(int, 0x00923D58)
#define gLastFlags_46A265_guess EQ_GLOBAL(int, 0x00924954)
#define gTimer_46A265_guess EQ_GLOBAL(int, 0x00923D94)

// /filter: opens the chat filter options.
// FUNCTION: TITANIUM 0x0046A245
void __cdecl do_filter_guess() {
    pinstCOptionsWnd_guess->Show(1, 1);
    pinstCOptionsWnd_guess->Dispatch_guess(4);
}

// /roleplay [on|off]: sets bit 2 of the anon flags and sends OP_SpawnAppearance 0x7C32 type 0x15
// (anon); refused while anonymous (bit 1, eqstr 0x22A9). Saves [Options] Anonymous.
// FUNCTION: TITANIUM 0x0046A265
// @early-stop: budget, structural ndiff=30
void __cdecl do_roleplay_guess(Options_46A265_guess* opts_guess, const char* text_guess) {
    if (gPhase_46A265_guess == 6) {
        return;
    }
    bool off_guess = true;
    char state_guess;
    if (FUN_00574990_guess(text_guess, pStringTable->getString(0x3292, 0), 3) != 0) {
        off_guess = false;
        if (FUN_00574990_guess(text_guess, pStringTable->getString(0x3293, 0), 2) != 0) {
            state_guess = 1 - (opts_guess->IsOn_guess() != 0);
            off_guess = state_guess == 0;
        }
    }
    if (!off_guess) {
        if (!opts_guess->IsOn_guess() && (opts_guess->flags_264_guess & 1) != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x22a9, 0), 0x111, 1);
            return;
        }
        gOptions_46A265_guess->flags_264_guess |= 2;
    } else {
        gOptions_46A265_guess->flags_264_guess &= ~2;
    }
    char text[256];
    if (gOptions_46A265_guess->IsOn_guess() == 0) {
        sprintf(text, pStringTable->getString(0x33b2, 0));
    } else {
        sprintf(text, pStringTable->getString(0x33b1, 0));
    }
    pEverQuest->dsp_chat(text, 0x111, 1);
    OptionsPacket_46A265_guess packet;
    packet.field_0_guess = opts_guess->field_258_guess;
    packet.flags_4_guess = opts_guess->flags_264_guess;
    packet.type_2_guess = 0x15;
    SendMessage_guess(&gSendTarget_guess, OP_SpawnAppearance, &packet, 8, 1);
    gCharFlags_46A265_guess->flag_e24_guess = gOptions_46A265_guess->flags_264_guess != 0;
    gTimer_46A265_guess = 5;
    gGlobalContext_guess->SavePC_guess(0, 1, 10);
    gLastFlags_46A265_guess = gOptions_46A265_guess->flags_264_guess;
    gGlobalContext_guess->WriteInt_guess(gLastFlags_46A265_guess, "Options", "Anonymous");
    gOptions_46A265_guess->Refresh_guess();
}

struct MessageState_guess {
    unsigned char pad_000_guess[0x15c];
    int state_15c_guess;
};

struct CurrentAction_guess {
    unsigned char pad_000_guess[0x1a8];
    MessageState_guess* messageState_1a8_guess;
    unsigned char pad_1ac_guess[0xa6];
    unsigned char type_252_guess;
};

struct CostService_guess {
    // EXTERNAL: TITANIUM 0x004B4617 CostService_guess::FindPathToPlayer_guess
    void FindPathToPlayer_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x004B4795 CostService_guess::UseAbility_guess
    void UseAbility_guess(int first_guess, int second_guess);
};
#define g_costService_guess EQ_GLOBAL(CostService_guess*, 0x009859EC)

struct OptionArgument_46A445_guess {
    char pad_000_guess[0x251];
    char standState_0251_guess;
};

// /sit [off]: toggles sitting; 'off' acts only while sitting (stand state 'n' 0x6E).
// FUNCTION: TITANIUM 0x0046A445
void __cdecl do_sit_guess(OptionArgument_46A445_guess* option_guess,
                                const char* text_guess) {
    if (allowslashcommand_guess() != 0 &&
        (FUN_00574990_guess(text_guess, gTextLookup_guess->FindText_guess(0x3292, 0), 3) != 0 ||
         option_guess->standState_0251_guess == 'n')) {
        gGlobalContext_guess->ToggleSit_guess();
    }
}

struct CallbackOwner_46A48C_guess {
    // EXTERNAL: TITANIUM 0x00483556 CallbackOwner_46A48C_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
};

// /stand: stand state 100.
// FUNCTION: TITANIUM 0x0046A48C
void __cdecl do_stand_guess(CallbackOwner_46A48C_guess* owner_guess) {
    if (allowslashcommand_guess() != 0) {
        owner_guess->ChangePosition_guess(100);
    }
}

// /marknpc and /gmarknpc <1-3>: needs expansion bit 0x40 (probably Gates of Discord, eqstr 0x2264);
// bad number eqstr 0x2265.
// FUNCTION: TITANIUM 0x0046A4A1
void __cdecl do_marknpc_guess(int unused, const char* source) {
    char text[12];
    if ((g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
        GrabFirstWord_guess(source, text, 10);
        if (is_number_guess(text) != 0) {
            long value = atol(text);
            if (value >= 1 && value <= 3) {
                if (g_costService_guess != 0) {
                    g_costService_guess->UseAbility_guess(0, value);
                }
                return;
            }
        }
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2265, 0), 0xf, 1);
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2264, 0), 0xf, 1);
    }
}

// /rmarknpc <1-3>: raid mark (kind 0x10); bad number eqstr 0x2266.
// FUNCTION: TITANIUM 0x0046A546
void __cdecl do_rmarknpc_guess(int unused, const char* source) {
    char text[12];
    if ((g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
        GrabFirstWord_guess(source, text, 10);
        if (is_number_guess(text) != 0) {
            long value = atol(text);
            if (value >= 1 && value <= 3) {
                if (g_costService_guess != 0) {
                    g_costService_guess->UseAbility_guess(0x10, value);
                }
                return;
            }
        }
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2266, 0), 0xf, 1);
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2264, 0), 0xf, 1);
    }
}

// /clearmarks: raid marks via OP_RaidClearNPCMarks 0x1794, group marks via OP_ClearNPCMarks 0x3EF6,
// by which of the four leadership checks passes. The int return is match shape, not a result.
// FUNCTION: TITANIUM 0x0046A5EB
// @early-stop: budget, structural ndiff=30
int __cdecl do_clearmarks_guess() {
    StateHolder_guess* state_guess = g_stateHolder_guess;
    unsigned char (&stateFlags_guess)[1] = state_guess->stateFlags_guess;
    if ((stateFlags_guess[state_guess->part_guess->index_guess] & 0x40) == 0 ||
        EQ_GLOBAL(int, 0x009859EC) == 0) {
        return (int)state_guess;
    }
    char result_guess = state_guess->FUN_004bab58_guess();
    if (result_guess == 0) {
        result_guess = state_guess->IsRaidMarkNpcDelegate_guess();
        if (result_guess == 0) {
            result_guess = state_guess->IsGroupLeader_guess();
            if (result_guess == 0) {
                result_guess = state_guess->IsGroupMarkNpcDelegate_guess();
                if (result_guess == 0) {
                    return (int)result_guess;
                }
            }
            return FUN_004912b1_guess(&gSendTarget_guess, OP_ClearNPCMarks, 0, 0, 1);
        }
    }
    return FUN_004912b1_guess(&gSendTarget_guess, OP_RaidClearNPCMarks, 0, 0, 1);
}

// /findpc <name>: at least 4 chars (eqstr 0x2273); needs expansion bit 0x40.
// FUNCTION: TITANIUM 0x0046A613
void __cdecl do_findpc_guess(int unused, const char* source) {
    char text[0x40];
    if ((g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
        GrabFirstWord_guess(source, text, 0x40);
        if (strlen(text) < 4) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2273, 0), 0xf, 1);
        } else {
            if (g_costService_guess == 0) {
                return;
            }
            g_costService_guess->FindPathToPlayer_guess(text);
            return;
        }
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2264, 0), 0xf, 1);
    }
}

// /stopcast: a bard stops its song locally; other classes send an empty OP_ManaChange 0x4839,
// probably the cast interrupt. eqstr 0xDE6 when there is nothing to stop.
// FUNCTION: TITANIUM 0x0046A75A
void __cdecl do_stopcast_guess(void) {
    StateHolder_guess* holder = g_stateHolder_guess;
    CurrentAction_guess* current = holder->pSpawn_c288_guess;
    if (current != 0 && current->messageState_1a8_guess != 0 &&
        current->messageState_1a8_guess->state_15c_guess == 0) {
        if (current->type_252_guess == 8) {
            holder->command_c280_guess.Handle_guess(0);
            return;
        }
        SendMessage_guess(&gSendTarget_guess, OP_ManaChange, 0, 0, 1);
        return;
    }
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0xde6, 0), 0xd, 1);
}

union CommandOption_46a7d1_guess {
    int value_guess;
    unsigned char option_guess;
};

// /doability <1-10>: presses that ability button; usage eqstr 0x33C8/0x33C9.
// FUNCTION: TITANIUM 0x0046A7D1
void __cdecl do_doability_guess(int unused_guess, const char* text_guess) {
    if (allowslashcommand_guess() == 0) {
        return;
    }

    int index_guess = atoi(text_guess) - 1;
    if (index_guess >= 0) {
        if (index_guess < 6) {
            CommandOption_46a7d1_guess* option_guess =
                EQ_ARRAY(CommandOption_46a7d1_guess, 0x0095D424) + index_guess;
            if (option_guess->value_guess != -1) {
                g_stateHolder_guess->command_c280_guess.FUN_0041f4a0_guess(
                    option_guess->option_guess, gIncomingMessage_guess);
            }
        } else if (index_guess < 10) {
            CommandOption_46a7d1_guess* option_guess =
                // With index 6..9 this reads 0x95D414..0x95D420, the slots just below the 1-6 table.
                EQ_ARRAY(CommandOption_46a7d1_guess, 0x0095D3FC) + index_guess;
            if (option_guess->value_guess != -1) {
                g_stateHolder_guess->command_c280_guess.FUN_0041f4a0_guess(
                    option_guess->option_guess, gIncomingMessage_guess);
            }
        } else {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33c8, 0), 0x111, 1);
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33c9, 0), 0x111, 1);
            return;
        }
        return;
    }

    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33c8, 0), 0x111, 1);
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33c9, 0), 0x111, 1);
}

// /whotarget: /who on the target's name.
// FUNCTION: TITANIUM 0x0046A871
void __cdecl do_whotarget_guess(int arg_guess) {
    if (gIncomingMessage_guess != 0) {
        cmd_who_guess(arg_guess, (int)gIncomingMessage_guess->text_120_guess);
    }
}

// /invite [name]: invites, or accepts a pending invite.
// FUNCTION: TITANIUM 0x0046A908
void __cdecl do_invite_guess(int unused_guess, char* text_guess) {
    if (allowslashcommand_guess() == 0) {
        return;
    }
    if (EQ_GLOBAL(char, 0x00985808) == 0 && gConnection_guess->IsGroupInvitePending_guess() == 0) {
        gGlobalContext_guess->Invite_guess(text_guess);
        return;
    }
    gGlobalContext_guess->AcceptGroupInvite_guess();
}

// /disband.
// FUNCTION: TITANIUM 0x0046A944
void __cdecl do_disband_guess(void) {
    if (allowslashcommand_guess() != 0) {
        gGlobalContext_guess->Disband_guess();
    }
}

struct ModeControl_46a959_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A ModeControl_46a959_guess::Reset_guess
    void Reset_guess(bool value_guess);
    // EXTERNAL: TITANIUM 0x0049994C ModeControl_46a959_guess::Set_guess
    void Set_guess(int value_guess);
};

#define gModeControl_46a959_guess EQ_GLOBAL(ModeControl_46a959_guess, 0x00923770)

// /attack [on|off]: auto attack; refused on yourself (eqstr 0x3198); no word toggles.
// FUNCTION: TITANIUM 0x0046A959
void __cdecl do_attack_guess(int unused_guess, const char* text_guess) {
    if (allowslashcommand_guess() != 0) {
        if (EQ_GLOBAL(char, 0x0092384C) != 0) {
            gModeControl_46a959_guess.Reset_guess(0);
            gModeControl_46a959_guess.Set_guess(0);
            return;
        }
        if (__strnicmp(text_guess, gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
            gModeControl_46a959_guess.Reset_guess(0);
        } else if (__strnicmp(text_guess, gTextLookup_guess->FindText_guess(0x3293, 0), 2) == 0) {
            if (EQ_GLOBAL(int, 0x00905D04) == EQ_GLOBAL(int, 0x00905CE4)) {
                gGlobalContext_guess->SetText_guess(
                    gTextLookup_guess->FindText_guess(0x3198, 0), 0xd, 1);
                return;
            }
            gModeControl_46a959_guess.Reset_guess(1);
        } else {
            char alternate_guess = EQ_GLOBAL(char, 0x009858C7);
            if (alternate_guess == 0 &&
                EQ_GLOBAL(int, 0x00905D04) == EQ_GLOBAL(int, 0x00905CE4)) {
                gGlobalContext_guess->SetText_guess(
                    gTextLookup_guess->FindText_guess(0x3198, 0), 0xd, 1);
                return;
            }
            gModeControl_46a959_guess.Reset_guess(alternate_guess == 0);
        }
    }
}

struct LookupResult_guess {
    char pad_000_guess[0x258];
    int spawnId_0258_guess;
};

// EXTERNAL: TITANIUM 0x0047C8DF get_player_partial_name_guess
LookupResult_guess* __cdecl get_player_partial_name_guess(const char* text_guess, void* context_guess, int mode_guess);

// EXTERNAL: TITANIUM 0x0047981D FindPlayerByPartialDisplayName_guess
LookupResult_guess* __cdecl FindPlayerByPartialDisplayName_guess(char* text_guess, int flags_guess);

// /shield [name]: OP_Shielding 0x3FE6 with the spawn id; warriors of level 30+ only (eqstr 0xFC1),
// not yourself (0xCCE/0xFBE); no name and no target eqstr 0xFBF/0xFC2.
// FUNCTION: TITANIUM 0x0046AA32
// @early-stop: budget, structural ndiff=31
void __cdecl do_shield_guess(Connection_guess* connection_guess,
                                char* text_guess) {
    int value_guess;
    char buffer_guess[0x80];

    if (allowslashcommand_guess() == 0) {
        return;
    }

    memset(&value_guess, 0, sizeof(value_guess));
    if (EQ_GLOBAL(int, 0x00905D10) != 0 ||
        EQ_GLOBAL(int, 0x00905D1C) != 0 ||
        EQ_GLOBAL(int, 0x00905D14) != 0) {
        return;
    }

    int one_guess = 1;
    if (connection_guess->playerClass_0252_guess == one_guess &&
        connection_guess->byte_24c_guess >= 0x1e) {
        if (strlen(text_guess) > 0) {
            FUN_00576fa0_guess(buffer_guess, text_guess, 0x80);
            gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, one_guess);
            LookupResult_guess* result_guess = FindPlayerByPartialDisplayName_guess(buffer_guess, 0);
            if (result_guess == 0) {
                return;
            }
            if (result_guess == (LookupResult_guess*)gConnection_guess) {
                value_guess = 0xcce;
            } else {
                value_guess = result_guess->spawnId_0258_guess;
                FUN_004912b1_guess(&gSendTarget_guess, OP_Shielding,
                                   &value_guess, 4, one_guess);
                return;
            }
        } else {
            Connection_guess* current_guess = (Connection_guess*)EQ_GLOBAL(int, 0x00905D04);
            if (current_guess != 0) {
                if (current_guess != gConnection_guess) {
                    value_guess = current_guess->spawnId_0258_guess;
                    FUN_004912b1_guess(&gSendTarget_guess, OP_Shielding,
                                       &value_guess, 4, one_guess);
                    return;
                }
                value_guess = 0xfbe;
            } else {
                gGlobalContext_guess->SetText_guess(
                    gTextLookup_guess->FindText_guess(0xfbf, 0), 0x111, one_guess);
                gGlobalContext_guess->SetText_guess(
                    gTextLookup_guess->FindText_guess(0xfc2, 0), 0x111, one_guess);
                return;
            }
        }
    } else {
        value_guess = 0xfc1;
    }

    gGlobalContext_guess->SetText_guess(
        gTextLookup_guess->FindText_guess(value_guess, 0), 0x111, one_guess);
}

struct RoleService_46abc4_guess {
    // EXTERNAL: TITANIUM 0x004B424F RoleService_46abc4_guess::SelectAssistTarget_guess
    LookupResult_guess* SelectAssistTarget_guess(int role_guess);
};
#define gRoleService_46abc4_guess EQ_GLOBAL(RoleService_46abc4_guess*, 0x009859EC)
#define gAttackOnAssist_guess EQ_GLOBAL(int, 0x009247C0)
#define gTarget_46abc4_guess EQ_GLOBAL(LookupResult_guess*, 0x00905D04)
#define gLocal_46abc4_guess EQ_GLOBAL(LookupResult_guess*, 0x00905CE4)

// /assist [name|on|off|role]: OP_Assist 0x7709 with the spawn id (default the target; eqstr 0x57B on
// yourself). on/off saves [Defaults] AttackOnAssist; role words 0x2252/0x2253/0x223D send OP_AssistGroup
// 0x5104 for leadership roles 0-2. Those keywords then fall through to the name lookup too.
// FUNCTION: TITANIUM 0x0046ABC4
// @early-stop: budget, structural ndiff=183
void __cdecl do_assist_guess(int unused_guess, char* text_guess) {
    int targetId_guess;
    int roleId_guess;
    char buffer_guess[0x80];

    if (allowslashcommand_guess() == 0) {
        return;
    }
    if (EQ_GLOBAL(int, 0x00905D10) != 0 ||
        EQ_GLOBAL(int, 0x00905D1C) != 0 ||
        EQ_GLOBAL(int, 0x00905D14) != 0) {
        return;
    }

    if (strlen(text_guess) > 0) {
        if (__stricmp(text_guess, gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
            gAttackOnAssist_guess = 1;
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x33cf, 0));
            FUN_0060beb0_guess("Defaults", "AttackOnAssist", "TRUE", ".\\eqclient.ini");
        }
        if (__stricmp(text_guess, gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
            gAttackOnAssist_guess = 0;
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x33d0, 0));
            FUN_0060beb0_guess("Defaults", "AttackOnAssist", "FALSE", ".\\eqclient.ini");
        }
        if (__stricmp(text_guess, gTextLookup_guess->FindText_guess(0x2252, 0)) == 0 &&
            gRoleService_46abc4_guess != 0 &&
            (g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
            LookupResult_guess* role_guess = gRoleService_46abc4_guess->SelectAssistTarget_guess(0);
            if (role_guess != 0) {
                roleId_guess = role_guess->spawnId_0258_guess;
                FUN_004912b1_guess(&gSendTarget_guess, OP_AssistGroup, &roleId_guess, 4, 1);
            }
        }
        if (__stricmp(text_guess, gTextLookup_guess->FindText_guess(0x2253, 0)) == 0 &&
            gRoleService_46abc4_guess != 0 &&
            (g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
            LookupResult_guess* role_guess = gRoleService_46abc4_guess->SelectAssistTarget_guess(1);
            if (role_guess != 0) {
                roleId_guess = role_guess->spawnId_0258_guess;
                FUN_004912b1_guess(&gSendTarget_guess, OP_AssistGroup, &roleId_guess, 4, 1);
            }
        }
        if (__stricmp(text_guess, gTextLookup_guess->FindText_guess(0x223d, 0)) == 0 &&
            gRoleService_46abc4_guess != 0 &&
            (g_stateHolder_guess->stateFlags_guess[g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
            LookupResult_guess* role_guess = gRoleService_46abc4_guess->SelectAssistTarget_guess(2);
            if (role_guess != 0) {
                roleId_guess = role_guess->spawnId_0258_guess;
                FUN_004912b1_guess(&gSendTarget_guess, OP_AssistGroup, &roleId_guess, 4, 1);
            }
        }

        FUN_00576fa0_guess(buffer_guess, text_guess, 0x80);
        gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, 1);
        LookupResult_guess* spawn_guess = FindPlayerByPartialDisplayName_guess(buffer_guess, 0);
        if (spawn_guess == 0) {
            return;
        }
        if (spawn_guess != gLocal_46abc4_guess) {
            targetId_guess = spawn_guess->spawnId_0258_guess;
            FUN_004912b1_guess(&gSendTarget_guess, OP_Assist, &targetId_guess, 4, 1);
            return;
        }
    } else {
        if (gTarget_46abc4_guess == 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33d1, 0), 0x111, 1);
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33d2, 0), 0x111, 1);
            return;
        }
        if (gTarget_46abc4_guess != gLocal_46abc4_guess) {
            targetId_guess = gTarget_46abc4_guess->spawnId_0258_guess;
            FUN_004912b1_guess(&gSendTarget_guess, OP_Assist, &targetId_guess, 4, 1);
            return;
        }
    }
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x57b, 0), 0x111, 1);
}

// /target <name>: OP_TargetCommand 0x1477 with the spawn id, 0 when no spawn matches; usage 0x33D3.
// FUNCTION: TITANIUM 0x0046AF19
void __cdecl do_target_guess(int unused_guess, char* text_guess) {
    if (allowslashcommand_guess() != 0) {
        if (strlen(text_guess) > 0) {
            LookupResult_guess* result_guess = get_player_partial_name_guess(text_guess, gConnection_guess, 3);
            int value_guess;
            if (result_guess == 0) {
                value_guess = 0;
            } else {
                value_guess = result_guess->spawnId_0258_guess;
            }
            SendMessage_guess(&gSendTarget_guess, OP_TargetCommand, &value_guess, 4, 1);
        } else {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33d3, 0), 0x111, 1);
        }
    }
}

#define gShowDynamicLights_guess EQ_GLOBAL(int, 0x00924818)

// /dynamiclights [on|off]: [Defaults] ShowDynamicLights.
// FUNCTION: TITANIUM 0x0046AF9B
// @early-stop: budget, diff ndiff=44
void __cdecl do_dynamiclights_guess(int unused_guess, char* text_guess) {
    if (FUN_00574990_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
        gShowDynamicLights_guess = 0;
        FUN_0060beb0_guess("Defaults", "ShowDynamicLights", "FALSE",
                           ".\\eqclient.ini");
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33d5, 0), 0x111, 1);
        return;
    }

    if (FUN_00574990_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3293, 0), 2) == 0) {
        gShowDynamicLights_guess = 1;
    } else {
        gShowDynamicLights_guess = gShowDynamicLights_guess != 1;
    }

    if (gShowDynamicLights_guess == 0) {
        FUN_0060beb0_guess("Defaults", "ShowDynamicLights", "FALSE",
                           ".\\eqclient.ini");
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33d5, 0), 0x111, 1);
    } else {
        FUN_0060beb0_guess("Defaults", "ShowDynamicLights", "TRUE",
                           ".\\eqclient.ini");
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33d4, 0), 0x111, 1);
    }
}

struct TextArg_guess {
    char* p_guess;
    // EXTERNAL: TITANIUM 0x00571E00 TextArg_guess::Init_guess
    void Init_guess(const char* text_guess);
    TextArg_guess(const char* text_guess) {
        Init_guess(text_guess);
    }
    ~TextArg_guess() {}
};

struct ReceiverAction_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess(int value_guess) = 0;
    char pad_004_guess[0x104];
    int field_108_guess;
    // EXTERNAL: TITANIUM 0x005A8B00 ReceiverAction_guess::SetSTMLText
    void SetSTMLText(TextArg_guess text_guess, int enabled_guess,
                            int zero_guess);
    // EXTERNAL: TITANIUM 0x005AC670 ReceiverAction_guess::FUN_005ac670_guess
    void FUN_005ac670_guess();
};

struct Receiver_guess {
    // EXTERNAL: TITANIUM 0x004F7FC6 Receiver_guess::Select_guess
    void Select_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004F6A90 Receiver_guess::AddOutputText_guess
    void AddOutputText_guess(TextArg_guess text_guess, int mode_guess);
    char pad_000_guess[0x164];
    ReceiverAction_guess* action_164_guess;
};

struct ReceiverOwner_guess {
    // EXTERNAL: TITANIUM 0x004F288C ReceiverOwner_guess::GetActiveChatWindow_guess
    Receiver_guess* GetActiveChatWindow_guess();
};

#define gReceiverOwner_guess EQ_GLOBAL(ReceiverOwner_guess*, 0x009917E4)

// /clearchat: empties the active chat window.
// FUNCTION: TITANIUM 0x0046B082
// @early-stop: budget, structural ndiff=23
void __cdecl do_clearchat_guess() {
    if (gReceiverOwner_guess != 0) {
        Receiver_guess* receiver_guess =
            gReceiverOwner_guess->GetActiveChatWindow_guess();
        if (receiver_guess->action_164_guess != 0) {
            TextArg_guess text_guess(
                (const char*)EQ_ARRAY(char, 0x0063F53F));
            receiver_guess->action_164_guess->SetSTMLText(
                text_guess, 1, 0);
            receiver_guess->action_164_guess->FUN_005ac670_guess();
            receiver_guess->action_164_guess->Slot64_guess(
                receiver_guess->action_164_guess->field_108_guess);
        }
    }
}

// /chatfontsize <0-6>: the active chat window; usage eqstr 0x33D6.
// FUNCTION: TITANIUM 0x0046B099
void __cdecl do_chatfontsize_guess(int unused_guess, char* text_guess) {
    if (gReceiverOwner_guess != 0) {
        Receiver_guess* receiver_guess = gReceiverOwner_guess->GetActiveChatWindow_guess();
        if (strlen(text_guess) > 0) {
            long value_guess = atol(text_guess);
            if (value_guess >= 0 && value_guess <= 6) {
                receiver_guess->Select_guess(value_guess);
                return;
            }
        }
        receiver_guess->AddOutputText_guess(gTextLookup_guess->FindText_guess(0x33d6, 0), 0x111);
    }
}

#define gInvWinLabels_guess EQ_GLOBAL(int, 0x009247C8)

// /invwinlabels [on|off]: [Defaults] InvWinLabels.
// FUNCTION: TITANIUM 0x0046B105
void __cdecl do_invwinlabels_guess(int unused_guess, char* text_guess) {
    if (strnicmp_guess(text_guess, "off", 3) == 0) {
        gInvWinLabels_guess = 0;
    } else if (strnicmp_guess(text_guess, "on", 2) == 0) {
        gInvWinLabels_guess = 1;
    } else {
        gInvWinLabels_guess = gInvWinLabels_guess != 1;
    }

    if (gInvWinLabels_guess == 1) {
        gGlobalContext_guess->SetText_guess(
            "Inventory Window Labels *ON*", 0x111, 1);
        FUN_0060beb0_guess("Defaults", "InvWinLabels", "TRUE",
                           ".\\eqclient.ini");
    } else {
        gGlobalContext_guess->SetText_guess(
            "Inventory Window Labels *OFF*", 0x111, 1);
        FUN_0060beb0_guess("Defaults", "InvWinLabels", "FALSE",
                           ".\\eqclient.ini");
    }
}

// EXTERNAL: TITANIUM 0x00438BD4 GetDefaultUserDefinedColor_guess
void __cdecl GetDefaultUserDefinedColor_guess(int index_guess, int* red_guess, int* green_guess, int* blue_guess);

// EXTERNAL: TITANIUM 0x00438CF7 SetUserDefinedColor_guess
void __cdecl SetUserDefinedColor_guess(int index_guess, int red_guess, int green_guess, int blue_guess);

// /usercolor <n> <r> <g> <b> | <n> reset | help | page1-7: saves [TextColors] User_<n>_Red etc.
// FUNCTION: TITANIUM 0x0046B1B2
void __cdecl do_usercolor_guess(int unused_guess, char* text_guess) {
    char number_guess[64];
    char red_text_guess[64];
    char green_text_guess[64];
    char blue_text_guess[64];
    char prefix_guess[16];
    char key_guess[32];
    char value_guess[16];
    int index_guess = -1;
    int red_guess = -1;
    int green_guess = -1;
    int blue_guess = -1;

    if (strlen(text_guess) > 0) {
        const char* rest_guess = (const char*)GrabFirstWord_guess(text_guess, number_guess, 0x40);
        rest_guess = (const char*)GrabFirstWord_guess(rest_guess, red_text_guess, 0x40);
        rest_guess = (const char*)GrabFirstWord_guess(rest_guess, green_text_guess, 0x40);
        GrabFirstWord_guess(rest_guess, blue_text_guess, 0x40);
        if (is_number_guess(number_guess) != 0) {
            index_guess = atol(number_guess);
        }
        if (__stricmp(red_text_guess, "reset") == 0) {
            GetDefaultUserDefinedColor_guess(index_guess - 1, &red_guess, &green_guess, &blue_guess);
        } else if (__stricmp(number_guess, "help") == 0 || __stricmp(number_guess, "page1") == 0) {
            pEverQuest->dsp_chat("Here is a list of usercolor numbers:", 0x111, 1);
            pEverQuest->dsp_chat(" 1 - Say", 0x111, 1);
            pEverQuest->dsp_chat(" 2 - Tell", 0x111, 1);
            pEverQuest->dsp_chat(" 3 - Group", 0x111, 1);
            pEverQuest->dsp_chat(" 4 - Guild", 0x111, 1);
            pEverQuest->dsp_chat(" 5 - OOC", 0x111, 1);
            pEverQuest->dsp_chat(" 6 - Auction", 0x111, 1);
            pEverQuest->dsp_chat(" 7 - Shout", 0x111, 1);
            pEverQuest->dsp_chat(" 8 - Emote", 0x111, 1);
            pEverQuest->dsp_chat(" 9 - Spells (meming, scribing, casting, etc.)", 0x111, 1);
            pEverQuest->dsp_chat(" 10 - You hit other", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page2 for numbers 11 - 20", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page2") == 0) {
            pEverQuest->dsp_chat(" 11 - Other hits you", 0x111, 1);
            pEverQuest->dsp_chat(" 12 - You miss other", 0x111, 1);
            pEverQuest->dsp_chat(" 13 - Other misses you", 0x111, 1);
            pEverQuest->dsp_chat(" 14 - Some broadcasts (duels)", 0x111, 1);
            pEverQuest->dsp_chat(" 15 - Skills (ups, non-combat use, etc.)", 0x111, 1);
            pEverQuest->dsp_chat(" 16 - Disciplines or special abilities", 0x111, 1);
            pEverQuest->dsp_chat(" 17 - Unused at this time", 0x111, 1);
            pEverQuest->dsp_chat(" 18 - Default text and stuff you type", 0x111, 1);
            pEverQuest->dsp_chat(" 19 - Unused at this time", 0x111, 1);
            pEverQuest->dsp_chat(" 20 - Merchant Offer Price", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page3 for numbers 21 - 30", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page3") == 0) {
            pEverQuest->dsp_chat(" 21 - Merchant Buy/Sell", 0x111, 1);
            pEverQuest->dsp_chat(" 22 - Your death message", 0x111, 1);
            pEverQuest->dsp_chat(" 23 - Others death message", 0x111, 1);
            pEverQuest->dsp_chat(" 24 - Other damage other", 0x111, 1);
            pEverQuest->dsp_chat(" 25 - Other miss other", 0x111, 1);
            pEverQuest->dsp_chat(" 26 - /who command", 0x111, 1);
            pEverQuest->dsp_chat(" 27 - yell for help", 0x111, 1);
            pEverQuest->dsp_chat(" 28 - Hit for non-melee", 0x111, 1);
            pEverQuest->dsp_chat(" 29 - Spell worn off", 0x111, 1);
            pEverQuest->dsp_chat(" 30 - Money splits", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page4 for numbers 31 - 40", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page4") == 0) {
            pEverQuest->dsp_chat(" 31 - Loot message", 0x111, 1);
            pEverQuest->dsp_chat(" 32 - Dice Roll (/random)", 0x111, 1);
            pEverQuest->dsp_chat(" 33 - Others spells", 0x111, 1);
            pEverQuest->dsp_chat(" 34 - Spell Failures (resists, fizzles, missing component, bad target, etc.)", 0x111, 1);
            pEverQuest->dsp_chat(" 35 - Chat Channel Messages", 0x111, 1);
            pEverQuest->dsp_chat(" 36 - Chat Channel 1", 0x111, 1);
            pEverQuest->dsp_chat(" 37 - Chat Channel 2", 0x111, 1);
            pEverQuest->dsp_chat(" 38 - Chat Channel 3", 0x111, 1);
            pEverQuest->dsp_chat(" 39 - Chat Channel 4", 0x111, 1);
            pEverQuest->dsp_chat(" 40 - Chat Channel 5", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page5 for numbers 41 - 50", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page5") == 0) {
            pEverQuest->dsp_chat(" 41 - Chat Channel 6", 0x111, 1);
            pEverQuest->dsp_chat(" 42 - Chat Channel 7", 0x111, 1);
            pEverQuest->dsp_chat(" 43 - Chat Channel 8", 0x111, 1);
            pEverQuest->dsp_chat(" 44 - Chat Channel 9", 0x111, 1);
            pEverQuest->dsp_chat(" 45 - Chat Channel 10", 0x111, 1);
            pEverQuest->dsp_chat(" 46 - Melee Crits", 0x111, 1);
            pEverQuest->dsp_chat(" 47 - Spell Crits", 0x111, 1);
            pEverQuest->dsp_chat(" 48 - Too far away (melee)", 0x111, 1);
            pEverQuest->dsp_chat(" 49 - NPC Rampage", 0x111, 1);
            pEverQuest->dsp_chat(" 50 - NPC Flurry", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page6 for numbers 51 and up", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page6") == 0) {
            pEverQuest->dsp_chat(" 51 - NPC Enrage", 0x111, 1);
            pEverQuest->dsp_chat(" 52 - Say echo", 0x111, 1);
            pEverQuest->dsp_chat(" 53 - Tell echo", 0x111, 1);
            pEverQuest->dsp_chat(" 54 - Group echo", 0x111, 1);
            pEverQuest->dsp_chat(" 55 - Guild echo", 0x111, 1);
            pEverQuest->dsp_chat(" 56 - OOC echo", 0x111, 1);
            pEverQuest->dsp_chat(" 57 - Auction echo", 0x111, 1);
            pEverQuest->dsp_chat(" 58 - Shout echo", 0x111, 1);
            pEverQuest->dsp_chat(" 59 - Emote echo", 0x111, 1);
            pEverQuest->dsp_chat(" 60 - Chat Channel 1 echo", 0x111, 1);
            pEverQuest->dsp_chat(" Type /usercolor page7 for numbers 61 and up", 0x111, 1);
            return;
        } else if (__stricmp(number_guess, "page7") == 0) {
            pEverQuest->dsp_chat(" 61 - Chat Channel 2 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 62 - Chat Channel 3 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 63 - Chat Channel 4 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 64 - Chat Channel 5 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 65 - Chat Channel 6 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 66 - Chat Channel 7 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 67 - Chat Channel 8 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 68 - Chat Channel 9 echo", 0x111, 1);
            pEverQuest->dsp_chat(" 69 - Chat Channel 10 echo", 0x111, 1);
            return;
        } else if (is_number_guess(red_text_guess) != 0) {
            red_guess = atol(red_text_guess);
            if (is_number_guess(green_text_guess) != 0) {
                green_guess = atol(green_text_guess);
            }
            if (is_number_guess(blue_text_guess) != 0) {
                blue_guess = atol(blue_text_guess);
            }
        }

        if (red_guess >= 0 && red_guess <= 255 && green_guess >= 0 && green_guess <= 255 &&
            // Accepts 0..86 though the help says 1 to 69; 0 writes colour slot -1.
            blue_guess >= 0 && blue_guess <= 255 && index_guess >= 0 && index_guess <= 0x56) {
            SetUserDefinedColor_guess(index_guess - 1, red_guess, green_guess, blue_guess);
            sprintf(prefix_guess, "User_%d_", index_guess);
            strcpy(key_guess, prefix_guess);
            strcat(key_guess, "Red");
            sprintf(value_guess, "%d", red_guess);
            FUN_0060beb0_guess("TextColors", key_guess, value_guess, ".\\eqclient.ini");
            strcpy(key_guess, prefix_guess);
            strcat(key_guess, "Green");
            sprintf(value_guess, "%d", green_guess);
            FUN_0060beb0_guess("TextColors", key_guess, value_guess, ".\\eqclient.ini");
            strcpy(key_guess, prefix_guess);
            strcat(key_guess, "Blue");
            sprintf(value_guess, "%d", blue_guess);
            FUN_0060beb0_guess("TextColors", key_guess, value_guess, ".\\eqclient.ini");
            return;
        }
    }

    pEverQuest->dsp_chat("Format: /usercolor <number> <red> <green> <blue>", 0x111, 1);
    pEverQuest->dsp_chat("<number> -> 1 to 69", 0x111, 1);
    pEverQuest->dsp_chat("<red> <green> <blue> -> 0 to 255", 0x111, 1);
    pEverQuest->dsp_chat("To reset a user color use /usercolor <number> reset", 0x111, 1);
    pEverQuest->dsp_chat("To display a list of usercolor #'s use /usercolor help", 0x111, 1);
}

// /particledensity 0-3 | OFF|LOW|MED|HIGH; the confirmation echoes the text as typed.
// FUNCTION: TITANIUM 0x0046BACB
// @early-stop: budget, structural ndiff=41
void __cdecl do_pclouddensity_guess(int unused_guess, char* text_guess) {
    char message_guess[252];
    int numeric_guess;
    long density_guess;
    density_guess = atol(text_guess);
    numeric_guess = is_number_guess(text_guess);

    if (numeric_guess == 0 || density_guess > 3 || density_guess < 0) {
        if (strnicmp_guess(text_guess, "OFF", 3) == 0) {
            density_guess = 0;
        } else if (strnicmp_guess(text_guess, "LOW", 3) == 0) {
            density_guess = 1;
        } else if (strnicmp_guess(text_guess, "MED", 3) == 0) {
            density_guess = 2;
        } else if (strnicmp_guess(text_guess, "HIG", 3) == 0) {
            density_guess = 3;
        } else {
            gGlobalContext_guess->dsp_chat(
                "Please choose either OFF, LOW, MED, or HIGH.");
            return;
        }
    }

    gNpcNameState_guess->SetPCloudDensity_guess((int)density_guess);
    sprintf(message_guess, "Particle Cloud Density is currently: %s", text_guess);
    gGlobalContext_guess->dsp_chat(message_guess);
}

#define g_targetGroupBuffOff_guess EQ_ARRAY(char, 0x006410A8)
#define g_targetGroupBuffOn_guess EQ_ARRAY(char, 0x00645EB4)

// /targetgroupbuff and /tgb [on|off]: [Defaults] TargetGroupBuff, OP_TGB 0xC11 with 0 or 1, then
// always with 2 (the server reports the current state). Does nothing with a zero first argument.
// FUNCTION: TITANIUM 0x0046BBA2
void __cdecl do_targetgroupbuff_guess(int param_1, const char* param_2) {
    if (param_1 == 0) {
        return;
    }
    if (FUN_00574990_guess(param_2,
                           gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
        FUN_0060beb0_guess("Defaults", "TargetGroupBuff",
                           g_targetGroupBuffOff_guess, ".\\eqclient.ini");
        param_1 = 0;
        FUN_004912b1_guess(&gSendTarget_guess, OP_TGB, &param_1, 4, 1);
    } else if (FUN_00574990_guess(param_2,
                                  gTextLookup_guess->FindText_guess(0x3293, 0),
                                  2) == 0) {
        FUN_0060beb0_guess("Defaults", "TargetGroupBuff",
                           g_targetGroupBuffOn_guess, ".\\eqclient.ini");
        param_1 = 1;
        FUN_004912b1_guess(&gSendTarget_guess, OP_TGB, &param_1, 4, 1);
    }
    param_1 = 2;
    FUN_004912b1_guess(&gSendTarget_guess, OP_TGB, &param_1, 4, 1);
}

// The 50-slot tell list (newest name first); slot 0 is the /rtarget and /reply name.
struct NameSlot_guess {
    char text_guess[0x40];
};
#define gNameSlots_guess EQ_ARRAY(NameSlot_guess, 0x00925920)

struct StringRecord_46_guess {
    char name_guess[0x10];
    char value_guess[0x100];
    char pad_110_guess[0x400];
    char type_guess;
};

#define gStringRecords_46_guess EQ_ARRAY(StringRecord_46_guess, 0x0095D4D4)
#define gStringFlags_46_guess EQ_ARRAY(char, 0x0095D45C)

// SetSocial_guess stores a social: the 120 socials at 0x95D4D4 are 10 pages of 12
// (see tu_063/tu_168). Takes the first free or same-named slot from `start`, sets name, first line and
// colour, marks it dirty and, when start is 0, refreshes the button. Returns the index or -1.
// FUNCTION: TITANIUM 0x0046BC70
// @early-stop: budget, diff ndiff=2
int __cdecl SetSocial_guess(char* name_guess, char* value_guess,
                              char type_guess, int start_guess) {
    if (start_guess < 0 || start_guess >= 0x78) {
        start_guess = 0;
    }
    int page_guess = start_guess / 0xc;
    int slot_guess = start_guess % 0xc;
    if (page_guess < 10) {
        int group_guess = page_guess * 0xc;
        do {
            if (slot_guess < 0xc) {
                StringRecord_46_guess* record_guess =
                    gStringRecords_46_guess + group_guess + slot_guess;
                do {
                    if (record_guess->name_guess[0] == '\0' ||
                        __stricmp(record_guess->name_guess, name_guess) == 0) {
                        int index_guess = slot_guess + page_guess * 0xc;
                        strncpy(gStringRecords_46_guess[index_guess].name_guess,
                                name_guess, 0xf);
                        gStringRecords_46_guess[index_guess].type_guess = type_guess;
                        gStringRecords_46_guess[index_guess].name_guess[0xf] = 0;
                        strncpy(gStringRecords_46_guess[index_guess].value_guess,
                                value_guess, 0xff);
                        gStringRecords_46_guess[index_guess].value_guess[0xff] = 0;
                        gStringFlags_46_guess[index_guess] = 1;
                        if (start_guess != 0) {
                            return index_guess;
                        }
                        pinstCCursorAttachment_guess->Post_guess(
                            0, 4, index_guess, name_guess, -1);
                        return index_guess;
                    }
                    ++slot_guess;
                    ++record_guess;
                } while (slot_guess < 0xc);
            }
            slot_guess = 0;
            group_guess += 0xc;
            ++page_guess;
        } while (group_guess < 0x78);
    }
    return -1;
}

// /rtarget [name]: targets the last tell partner; channel entries drop the prefix and the text up to
// the last '.'. eqstr 0x33E6 when nobody told you anything.
// FUNCTION: TITANIUM 0x0046BE40
void __cdecl do_rtarget_guess(int unused_guess, char* text_guess) {
    if (text_guess == 0 || *text_guess == '\0') {
        if (gNameSlots_guess[0].text_guess[0] == '\0') {
            gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x33e6, 0));
            return;
        }
        if (gNameSlots_guess[0].text_guess[0] == ';' || gNameSlots_guess[0].text_guess[0] == '[') {
            char* name_guess = strrchr(gNameSlots_guess[0].text_guess, '.');
            if (name_guess != 0) {
                do_target_guess(unused_guess, name_guess + 1);
            } else {
                do_target_guess(unused_guess, gNameSlots_guess[0].text_guess + 1);
            }
        } else {
            do_target_guess(unused_guess, gNameSlots_guess[0].text_guess);
        }
    } else {
        do_target_guess(unused_guess, text_guess);
    }
}

// /mcicontrol <command>: raw mciSendString, echoing the result and any error text (only while
// 0x923D74 is 0).
// FUNCTION: TITANIUM 0x0046BF63
void __cdecl do_mcicontrol_guess(int unused_guess, char* command_guess) {
    char message_guess[512];
    char result_guess[256];

    if (EQ_GLOBAL(int, 0x00923D74) == 0) {
        FUN_0060e450_guess(result_guess, EQ_ARRAY(char, 0x0063FAF8));
        if (strlen(command_guess) > 0) {
            unsigned int error_guess =
                mciSendStringA(command_guess, result_guess, 0x100, 0);
            if (result_guess[0] != '*' && result_guess[0] != '\0') {
                FUN_0060e450_guess(message_guess, EQ_ARRAY(char, 0x00646E40));
                FUN_0060e460_guess(message_guess, result_guess);
                pEverQuest->dsp_chat(message_guess, 0x111, true);
            }
            if (error_guess != 0) {
                FUN_0060e450_guess(result_guess, EQ_ARRAY(char, 0x0063FAF8));
                mciGetErrorStringA(error_guess, result_guess, 0x100);
                if (result_guess[0] != '*' && result_guess[0] != '\0') {
                    FUN_0060e450_guess(message_guess, EQ_ARRAY(char, 0x00646E34));
                    FUN_0060e460_guess(message_guess, result_guess);
                    pEverQuest->dsp_chat(message_guess, 0x111, true);
                }
                FUN_0060e450_guess(result_guess, EQ_ARRAY(char, 0x0063FAF8));
                mciGetErrorStringA(error_guess, result_guess, 0x100);
                if (result_guess[0] != '*' && result_guess[0] != '\0') {
                    FUN_0060e450_guess(message_guess, EQ_ARRAY(char, 0x00646E34));
                    FUN_0060e460_guess(message_guess, result_guess);
                    pEverQuest->dsp_chat(message_guess, 0x111, true);
                }
            }
        }
    }
}

#define gShowNamesLevel_guess EQ_GLOBAL(int, 0x00924860)
#define gShowNamesState_guess EQ_GLOBAL(int, 0x00924978)
#define gShowNamesLevelOff_guess EQ_ARRAY(char, 0x006410A8)
#define gShowNamesFormat_guess EQ_ARRAY(char, 0x0063F53C)

// /shownames [off|1-6]: player-name detail level, saved as [Defaults] ShowNamesLevel and
// [Options] PCNames; out-of-range levels become 4. Each level echoes its own eqstr (0x33EE-0x33F1,
// 0x22AA, 0x22AB); no argument prints 0x33F2.
// FUNCTION: TITANIUM 0x0046C10A
// @early-stop: budget, diff ndiff=26
void __cdecl do_shownames_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x40];
    char level_text_guess[16];
    GrabFirstWord_guess(text_guess, buffer_guess, 0x40);
    if (buffer_guess[0] != '\0') {
        if (FUN_00574990_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33ed, 0), 0x111, 1);
            gNpcNameState_guess->SetPCNameSpriteState_guess(0);
            gShowNamesState_guess = 0;
            FUN_0060beb0_guess("Defaults", "ShowNamesLevel", gShowNamesLevelOff_guess, ".\\eqclient.ini");
        } else {
            int level_guess = atol(buffer_guess);
            if (level_guess <= 0 || level_guess >= 7) {
                level_guess = 4;
            }
            gShowNamesLevel_guess = level_guess;
            gNpcNameState_guess->SetPCNameSpriteState_guess(1);
            gShowNamesState_guess = 1;
            sprintf(level_text_guess, gShowNamesFormat_guess, level_guess);
            FUN_0060beb0_guess("Defaults", "ShowNamesLevel", level_text_guess, ".\\eqclient.ini");
            switch (level_guess) {
            case 1:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33ee, 0), 0x111, 1);
                break;
            case 2:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33ef, 0), 0x111, 1);
                break;
            case 3:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33f0, 0), 0x111, 1);
                break;
            case 4:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33f1, 0), 0x111, 1);
                break;
            case 5:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x22aa, 0), 0x111, 1);
                break;
            case 6:
                gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x22ab, 0), 0x111, 1);
                break;
            }
        }
        gGlobalContext_guess->WriteInt_guess(gShowNamesState_guess, "Options", "PCNames");
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x33f2, 0), 0x111, 1);
    }
}

// /shownpcnames [off]: anything but 'off' (eqstr 0x3292) turns NPC names on.
// FUNCTION: TITANIUM 0x0046C2D2
void __cdecl do_shownpcnames_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x40];
    GrabFirstWord_guess(text_guess, buffer_guess, 0x40);
    if (FUN_00574990_guess(
            buffer_guess, gTextLookup_guess->FindText_guess(0x3292, 0), 3) == 0) {
        gGlobalContext_guess->SetText_guess(gShownNpcNamesOff_guess, 0x111, 1);
        gNpcNameState_guess->SetNPCNameSpriteState_guess(0);
    } else {
        gGlobalContext_guess->SetText_guess(gShownNpcNamesOn_guess, 0x111, 1);
        gNpcNameState_guess->SetNPCNameSpriteState_guess(1);
    }
}

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key, const char* fallback,
                                char* value, int size, int flags);

#define gScreenWidth_guess EQ_GLOBAL(int, 0x0092379C)
#define gScreenHeight_guess EQ_GLOBAL(int, 0x009237A0)
#define gViewLeft_guess EQ_GLOBAL(int, 0x00923778)
#define gViewTop_guess EQ_GLOBAL(int, 0x0092377C)
#define gViewRight_guess EQ_GLOBAL(int, 0x00923780)
#define gViewBottom_guess EQ_GLOBAL(int, 0x00923784)
#define gOffsetXKey_guess EQ_ARRAY(char, 0x00646EA8)
#define gOffsetYKey_guess EQ_ARRAY(char, 0x00646EA4)
#define gWidthKey_guess EQ_ARRAY(char, 0x00641BA0)
#define gHeightKey_guess EQ_ARRAY(char, 0x00646EA0)

void __cdecl FUN_0060bf20_guess(const char* section_guess, const char* key_guess, const char* value_guess);

struct ViewportDisplay_guess {
    // EXTERNAL: TITANIUM 0x00439212 ViewportDisplay_guess::ApplyVideoMode_guess
    void ApplyVideoMode_guess();
};
#define gViewportDisplay_guess EQ_GLOBAL(ViewportDisplay_guess*, 0x00905D24)

// /viewport [x y w h | reset]: clamps the 3D view rectangle to the screen and, when 0x559545 allows
// (probably the save-window-positions option), stores it under [ViewPort<w>x<h>]. Without valid
// numbers it prints the current rectangle and the usage line 0x3AA0.
// FUNCTION: TITANIUM 0x0046C352
// @early-stop: budget, diff ndiff=2
void __cdecl do_viewport_guess(int unused_guess, char* text_guess) {
    char x_text_guess[64];
    char y_text_guess[64];
    char w_text_guess[64];
    char h_text_guess[64];
    char section_guess[128];
    char value_guess[16];
    int x_guess = -1;
    int y_guess = -1;
    int w_guess = -1;
    int h_guess = -1;

    if (strlen(text_guess) > 0) {
        if (FUN_0060e590_guess(text_guess, "reset") != 0) {
            x_guess = 0;
            y_guess = 0;
            w_guess = gScreenWidth_guess;
            h_guess = gScreenHeight_guess;
        } else {
            int rest_guess = GrabFirstWord_guess(text_guess, x_text_guess, 0x40);
            rest_guess = GrabFirstWord_guess((const char*)rest_guess, y_text_guess, 0x40);
            rest_guess = GrabFirstWord_guess((const char*)rest_guess, w_text_guess, 0x40);
            GrabFirstWord_guess((const char*)rest_guess, h_text_guess, 0x40);
            if (is_number_guess(x_text_guess) != 0) {
                x_guess = atol(x_text_guess);
            }
            if (is_number_guess(y_text_guess) != 0) {
                y_guess = atol(y_text_guess);
            }
            if (is_number_guess(w_text_guess) != 0) {
                w_guess = atol(w_text_guess);
            }
            if (is_number_guess(h_text_guess) != 0) {
                h_guess = atol(h_text_guess);
            }
        }
        if (x_guess > -1 && y_guess > -1 && w_guess > -1 && h_guess > -1) {
            if (w_guess > gScreenWidth_guess) {
                w_guess = gScreenWidth_guess;
            }
            if (h_guess > gScreenHeight_guess) {
                h_guess = gScreenHeight_guess;
            }
            if (w_guess + x_guess > gScreenWidth_guess) {
                x_guess = gScreenWidth_guess - w_guess;
            }
            if (h_guess + y_guess > gScreenHeight_guess) {
                y_guess = gScreenHeight_guess - h_guess;
            }
            gViewRight_guess = w_guess + x_guess;
            gViewLeft_guess = x_guess;
            gViewTop_guess = y_guess;
            gViewBottom_guess = h_guess + y_guess;
            gViewportDisplay_guess->ApplyVideoMode_guess();
            if (NewUIINI() != 0) {
                sprintf(section_guess, "ViewPort%dx%d", gScreenWidth_guess, gScreenHeight_guess);
                sprintf(value_guess, "%d", x_guess);
                FUN_0060bf20_guess(section_guess, gOffsetXKey_guess, value_guess);
                sprintf(value_guess, "%d", y_guess);
                FUN_0060bf20_guess(section_guess, gOffsetYKey_guess, value_guess);
                sprintf(value_guess, "%d", w_guess);
                FUN_0060bf20_guess(section_guess, gWidthKey_guess, value_guess);
                sprintf(value_guess, "%d", h_guess);
                FUN_0060bf20_guess(section_guess, gHeightKey_guess, value_guess);
            }
            return;
        }
    }
    sprintf(section_guess, "x=%d y=%d w=%d h=%d", gViewLeft_guess, gViewTop_guess,
            gViewRight_guess - gViewLeft_guess, gViewBottom_guess - gViewTop_guess);
    pEverQuest->dsp_chat(section_guess, 0x111, 1);
    pEverQuest->dsp_chat(pStringTable->getString(0x3aa0, 0), 0x111, 1);
}

// Loads the /viewport rectangle for the current resolution from [ViewPort<w>x<h>], clamped to the
// screen; full screen when 0x559545 says positions aren't saved.
// FUNCTION: TITANIUM 0x0046C627
// @early-stop: budget, structural ndiff=61
void __cdecl LoadViewportRect_guess(void) {
    char section_guess[128];
    char value_guess[16];
    long offset_y_guess;
    int offset_x_guess;
    int size_w_guess;
    int size_h_guess;

    if (NewUIINI() == 0) {
        gViewRight_guess = gScreenWidth_guess;
        gViewLeft_guess = 0;
        size_h_guess = gScreenHeight_guess;
        offset_y_guess = 0;
    } else {
        sprintf(section_guess, "ViewPort%dx%d", gScreenWidth_guess, gScreenHeight_guess);
        LoadStringFromUIIniFile_guess(section_guess, gOffsetXKey_guess, "*NULL*", value_guess, 16, 1);
        offset_y_guess = 0;
        if (value_guess[0] != 0x2a) {
            offset_x_guess = atol(value_guess);
        } else {
            offset_x_guess = 0;
        }
        LoadStringFromUIIniFile_guess(section_guess, gOffsetYKey_guess, "*NULL*", value_guess, 16, 1);
        if (value_guess[0] != 0x2a) {
            offset_y_guess = atol(value_guess);
        }
        LoadStringFromUIIniFile_guess(section_guess, gWidthKey_guess, "*NULL*", value_guess, 16, 1);
        size_w_guess = gScreenWidth_guess;
        if (value_guess[0] != 0x2a) {
            size_w_guess = atol(value_guess);
        }
        LoadStringFromUIIniFile_guess(section_guess, gHeightKey_guess, "*NULL*", value_guess, 16, 1);
        size_h_guess = gScreenHeight_guess;
        if (value_guess[0] != 0x2a) {
            size_h_guess = atol(value_guess);
        }
        if (gScreenWidth_guess < size_w_guess) {
            size_w_guess = gScreenWidth_guess;
        }
        if (gScreenHeight_guess < size_h_guess) {
            size_h_guess = gScreenHeight_guess;
        }
        if (gScreenWidth_guess < size_w_guess + offset_x_guess) {
            offset_x_guess = gScreenWidth_guess - size_w_guess;
        }
        if (gScreenHeight_guess < size_h_guess + offset_y_guess) {
            offset_y_guess = gScreenHeight_guess - size_h_guess;
        }
        gViewRight_guess = size_w_guess + offset_x_guess;
        gViewLeft_guess = offset_x_guess;
    }
    gViewTop_guess = offset_y_guess;
    gViewBottom_guess = size_h_guess + offset_y_guess;
}

// Level-of-detail switch from the options: echoes 0x19FA (on) or 0x19FB (off) and passes the flag to
// slot 37 of the renderer object at 0x99E368.
// FUNCTION: TITANIUM 0x0046C7A7
void __cdecl setLOD_guess(int param_guess) {
    if (param_guess != 0) {
        if (gGlobalContext_guess != 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x19fa, 0), 0x111, 1);
        }
        g_dispatch99E368_guess->Slot37_guess(1);
    } else {
        if (gGlobalContext_guess != 0) {
            gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x19fb, 0), 0x111, 1);
        }
        g_dispatch99E368_guess->Slot37_guess(0);
    }
}

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int value_guess, int enabled_guess, int flags_guess);


// /facepick: hands key 0x104 to 0x4619CD, probably the face-selection mode toggle.
// FUNCTION: TITANIUM 0x0046C81D
void __cdecl do_facepick_guess() {
    ExecuteCmd(0x104, 1, 0);
}

// /bodytint: toggles the window at 0x850CAC (slot 34 hides it, slot 33 shows it).
// FUNCTION: TITANIUM 0x0046C82F
// @early-stop: budget, structural ndiff=4
void __cdecl do_bodytint_guess() {
    if (pinstCBodyTintWnd_guess != 0) {
        if (FUN_0059dd30_guess() != 0) {
            pinstCBodyTintWnd_guess->Deactivate();
        } else {
            pinstCBodyTintWnd_guess->Activate();
        }
    }
}

// /dopropertinting [on|off]: writes [Defaults] DoProperTinting; no argument prints 0x1A73/0x1A74.
// FUNCTION: TITANIUM 0x0046C857
void __cdecl do_dopropertinting_guess(int unused_guess, const char* text_guess) {
    if (text_guess == 0 || *text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x1a73, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x1a74, 0), 0x111, 1);
    } else if (FUN_00574950_guess(
                   text_guess, pStringTable->getString(0x3292, 0)) == 0) {
        FUN_0060beb0_guess("Defaults", "DoProperTinting", "FALSE",
                           ".\\eqclient.ini");
        pEverQuest->dsp_chat(pStringTable->getString(0x1a76, 0), 0x111, 1);
    } else if (FUN_00574950_guess(
                   text_guess, pStringTable->getString(0x3293, 0)) == 0) {
        FUN_0060beb0_guess("Defaults", "DoProperTinting", "TRUE",
                           ".\\eqclient.ini");
        pEverQuest->dsp_chat(pStringTable->getString(0x1a75, 0), 0x111, 1);
    }
}

// /autojoin <channel[:password],...>: stores [ChatManager] ChannelAutoJoin for the next login.
// FUNCTION: TITANIUM 0x0046C949
void __cdecl do_autojoin_guess(int unused_guess, const char* text_guess) {
    if (text_guess != 0 && *text_guess != '\0') {
        gGlobalContext_guess->WriteCharIniString_guess(
            text_guess, "ChatManager", "ChannelAutoJoin");
        pEverQuest->dsp_chat("Set channels to be joined at login.", 0x111, 1);
        return;
    }
    pEverQuest->dsp_chat("Usage: /autojoin <channel name>", 0x111, 1);
    pEverQuest->dsp_chat("   or  /autojoin <channel name>:<password>", 0x111, 1);
    pEverQuest->dsp_chat(
        "You can also specify multiple channels using commas (e.g. /autojoin <channel name>,<channel name>).",
        0x111, 1);
}

// /join, /leave, /list and /announce pass ';<command> [args]' to the chat server (0x491438).
// FUNCTION: TITANIUM 0x0046C9C5
void __cdecl do_join(int unused, const char* text) {
    char buffer[1024];
    if (text == 0 || *text == '\0') {
        gGlobalContext_guess->SetText_guess("Usage: /join <channel name>", 0x111, 1);
        gGlobalContext_guess->SetText_guess("   or  /join <channel name>:<password>", 0x111, 1);
        gGlobalContext_guess->SetText_guess("You can also specify multiple channels using commas (e.g. /join <channel name>,<channel name>).", 0x111, 1);
    } else {
        sprintf(buffer, ";join %s", text);
        gGlobalContext_guess->ChatServerMessage_guess(buffer);
    }
}

// /leave [channel]; bare ';leave' leaves every channel.
// FUNCTION: TITANIUM 0x0046CA55
void __cdecl do_leave(int unused, const char* text) {
    char buffer[1024];
    if (text == 0 || *text == '\0') {
        gGlobalContext_guess->ChatServerMessage_guess(";leave");
    } else {
        sprintf(buffer, ";leave %s", text);
        gGlobalContext_guess->ChatServerMessage_guess(buffer);
    }
}

// /list [channel]: lists channels or a channel's members.
// FUNCTION: TITANIUM 0x0046CABB
void __cdecl do_list(int unused, const char* text) {
    char buffer[1024];
    if (text == 0 || *text == '\0') {
        gGlobalContext_guess->ChatServerMessage_guess(";list");
    } else {
        sprintf(buffer, ";list %s", text);
        gGlobalContext_guess->ChatServerMessage_guess(buffer);
    }
}

// /announce [channel]: toggles join/leave announcements.
// FUNCTION: TITANIUM 0x0046CB10
void __cdecl do_announce(int unused, const char* text) {
    char buffer[1024];
    if (text == 0 || *text == '\0') {
        gGlobalContext_guess->ChatServerMessage_guess(";announce");
    } else {
        sprintf(buffer, ";announce %s", text);
        gGlobalContext_guess->ChatServerMessage_guess(buffer);
    }
}

// EXTERNAL: TITANIUM 0x00577000 FormatText_guess
int __cdecl FormatText_guess(char* destination_guess, size_t count_guess,
                             const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x00478951 SpeakBabel_guess
void __cdecl SpeakBabel_guess(const char* source_guess, char* destination_guess,
                               int start_guess, int limit_guess, int context_guess);

// Shared body of /1../10: sends ';<n> text' to the chat server and echoes it locally (0x492F68).
// With font index 0 the text first goes through 0x478951 (100-char limit), else it is copied as is.
// The ten thunks below differ only in the channel number they pass.
// FUNCTION: TITANIUM 0x0046CB65
void __cdecl SendToChannel_guess(int command_guess, char* message_guess) {
    char text_guess[0x800];
    char converted_guess[0x800];
    char usage_guess[0x40];
    if (message_guess == 0 || *message_guess == '\0') {
        FormatText_guess(usage_guess, 0x40, "Usage: /%d <msg>", command_guess);
        gGlobalContext_guess->SetText_guess(usage_guess, 0x111, 1);
    } else {
        if (gFontIndex_guess == 0) {
            SpeakBabel_guess(message_guess, converted_guess, 0, 100,
                              g_lookupCheck_46_guess.Check_guess(6));
        } else {
            FUN_00576fa0_guess(converted_guess, message_guess, 0x800);
        }
        FormatText_guess(text_guess, 0x800, ";%d %s", command_guess, converted_guess);
        gGlobalContext_guess->DoPercentConvert_guess(text_guess, 1);
        gGlobalContext_guess->ChatServerMessage_guess(text_guess);
    }
}

// /1: says `message` on chat channel 1 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC51
void __cdecl do_channel1_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(1, message_guess);
}

// /2: says `message` on chat channel 2 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC5F
void __cdecl do_channel2_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(2, message_guess);
}

// /3: says `message` on chat channel 3 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC6D
void __cdecl do_channel3_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(3, message_guess);
}

// /4: says `message` on chat channel 4 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC7B
void __cdecl do_channel4_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(4, message_guess);
}

// /5: says `message` on chat channel 5 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC89
void __cdecl do_channel5_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(5, message_guess);
}

// /6: says `message` on chat channel 6 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CC97
void __cdecl do_channel6_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(6, message_guess);
}

// /7: says `message` on chat channel 7 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CCA5
void __cdecl do_channel7_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(7, message_guess);
}

// /8: says `message` on chat channel 8 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CCB3
void __cdecl do_channel8_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(8, message_guess);
}

// /9: says `message` on chat channel 9 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CCC1
void __cdecl do_channel9_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(9, message_guess);
}

// /10: says `message` on chat channel 10 (0x0046CB65).
// FUNCTION: TITANIUM 0x0046CCCF
void __cdecl do_channel10_guess(int unused_guess, char* message_guess) {
    SendToChannel_guess(10, message_guess);
}

// /dzaddplayer <name>: OP_DzAddPlayer (0x7FBA); no argument prints usage 0xDCB.
// The /dz* commands send a 0x44-byte packet whose first 4 bytes are left unset.
// FUNCTION: TITANIUM 0x0046CCDD
void __cdecl do_dzaddplayer_guess(int unused, const char* text) {
    char message[0x44];
    if (text == 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0xdcb, 0));
    } else {
        memset(message + 4, 0, 0x40);
        GrabFirstWord_guess(text, message + 4, 0x3f);
        SendMessage_guess(&gSendTarget_guess, OP_DzAddPlayer, message, 0x44, 1);
    }
}

// /dzremoveplayer <name>: OP_DzRemovePlayer (0x540B); usage 0xDCC.
// FUNCTION: TITANIUM 0x0046CD4F
void __cdecl do_dzremoveplayer_guess(int unused, const char* text) {
    char message[0x44];
    if (text == 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0xdcc, 0));
    } else {
        memset(message + 4, 0, 0x40);
        GrabFirstWord_guess(text, message + 4, 0x3f);
        SendMessage_guess(&gSendTarget_guess, OP_DzRemovePlayer, message, 0x44, 1);
    }
}

struct TwoTextMessage_guess {
    int unused_guess;
    char text_004_guess[0x40];
    char text_044_guess[0x40];
};

// /dzswapplayer <old> <new>: OP_DzSwapPlayer (0x794A); the first name goes to +0x44 and the second
// to +0x04. Usage 0xDCD.
// FUNCTION: TITANIUM 0x0046CDC1
void __cdecl do_dzswapplayer_guess(int unused_guess, const char* text_guess) {
    TwoTextMessage_guess message_guess;
    if (text_guess == 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0xdcd, 0));
    } else {
        memset(message_guess.text_044_guess, 0, 0x40);
        char* remainder_guess =
            (char*)GrabFirstWord_guess(text_guess, message_guess.text_044_guess, 0x3f);
        memset(message_guess.text_004_guess, 0, 0x40);
        GrabFirstWord_guess(remainder_guess, message_guess.text_004_guess, 0x3f);
        SendMessage_guess(&gSendTarget_guess, OP_DzSwapPlayer, &message_guess, 0x84, 1);
    }
}

// /dzmakeleader <name>: OP_DzMakeLeader (0xCE9); usage 0xDCE.
// FUNCTION: TITANIUM 0x0046CE60
void __cdecl do_dzmakeleader_guess(int unused_guess, const char* text_guess) {
    char message[0x44];
    if (text_guess == 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0xdce, 0));
    } else {
        memset(message + 4, 0, 0x40);
        GrabFirstWord_guess(text_guess, message + 4, 0x3f);
        SendMessage_guess(&gSendTarget_guess, OP_DzMakeLeader, message, 0x44, 1);
    }
}

// /dzplayerlist: OP_DzPlayerList (0xADA0) with 4 unset bytes.
// FUNCTION: TITANIUM 0x0046CED2
void __cdecl do_dzplayerlist_guess() {
    int data_guess;
    FUN_004912b1_guess(&gSendTarget_guess, OP_DzPlayerList, &data_guess, 4, 1);
}

// /dzlisttimers: OP_DzListTimers (0x39AA) with 4 unset bytes.
// FUNCTION: TITANIUM 0x0046CEEF
void __cdecl do_dzlisttimers_guess() {
    int data_guess;
    FUN_004912b1_guess(&gSendTarget_guess, OP_DzListTimers, &data_guess, 4, 1);
}

// /dzquit: OP_DzQuit (0x486D) with 4 unset bytes.
// FUNCTION: TITANIUM 0x0046CF0C
void __cdecl do_dzquit_guess() {
    int data_guess;
    FUN_004912b1_guess(&gSendTarget_guess, OP_DzQuit, &data_guess, 4, 1);
}

// /dzhelp: header lines 0xDD1/0xDD0/0xDCF, then the four /dz usage lines 0xDCB-0xDCE.
// FUNCTION: TITANIUM 0x0046CF29
void __cdecl do_dzhelp_guess() {
    int zero_guess = 0;
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdd1, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdd0, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdcf, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdcb, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdcc, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdcd, zero_guess));
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0xdce, zero_guess));
}

// /taskaddplayer <name>: OP_TaskAddPlayer (0x6BC4), 0x48 bytes with the name at +8; usage 0x22C2.
// The /task* commands except /tasktimers run only when bit 0 of the pCharData flag byte
// (stateFlags_guess[index + 1]) is set; the raid commands test bit 3 of the byte before it.
// FUNCTION: TITANIUM 0x0046CFF9
void __cdecl do_taskaddplayer_guess(int unused_guess, const char* text_guess) {
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        if (text_guess == 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x22c2, 0));
        } else {
            char message[0x48];
            memset(message + 8, 0, 0x40);
            GrabFirstWord_guess(text_guess, message + 8, 0x3f);
            SendMessage_guess(&gSendTarget_guess, OP_TaskAddPlayer, message, 0x48, 1);
        }
    }
}

// /taskremoveplayer <name>: OP_TaskRemovePlayer (0x37B9); usage 0x22C3.
// FUNCTION: TITANIUM 0x0046D087
void __cdecl do_taskremoveplayer_guess(int unused_guess, const char* text_guess) {
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        if (text_guess == 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x22c3, 0));
        } else {
            char message[0x48];
            memset(message + 8, 0, 0x40);
            GrabFirstWord_guess(text_guess, message + 8, 0x3f);
            SendMessage_guess(&gSendTarget_guess, 0x37b9, message, 0x48, 1);
        }
    }
}

// /taskplayerlist: OP_SharedTaskPlayerList (0x3961) with 8 unset bytes.
// FUNCTION: TITANIUM 0x0046D115
void __cdecl do_taskplayerlist_guess() {
    int data_guess[2];
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        FUN_004912b1_guess(&gSendTarget_guess, OP_SharedTaskPlayerList, data_guess, 8, 1);
    }
}

// /taskmakeleader <name>: OP_TaskMakeLeader (0x1B25); usage 0x22C4.
// FUNCTION: TITANIUM 0x0046D151
void __cdecl do_taskmakeleader_guess(int unused_guess, const char* text_guess) {
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        if (text_guess == 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x22c4, 0));
        } else {
            char message[0x48];
            memset(message + 8, 0, 0x40);
            GrabFirstWord_guess(text_guess, message + 8, 0x3f);
            SendMessage_guess(&gSendTarget_guess, 0x1b25, message, 0x48, 1);
        }
    }
}

// /tasktimers: opcode 0x30D with no payload (not in patch_Titanium.conf); unlike the other /task
// commands it skips the flag test.
// FUNCTION: TITANIUM 0x0046D1DF
void __cdecl do_tasktimers_guess() {
    if (g_stateHolder_guess != 0) {
        SendMessage_guess(&gSendTarget_guess, 0x30d, 0, 0, 1);
    }
}

// /taskquit: OP_SharedTaskQuit (0x35DD) with 8 unset bytes.
// FUNCTION: TITANIUM 0x0046D200
void __cdecl do_taskquit_guess() {
    int messageData_guess[2];
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        SendMessage_guess(&gSendTarget_guess, OP_SharedTaskQuit, messageData_guess,
                          sizeof(messageData_guess), 1);
    }
}

// /taskhelp: header 0x22C6, then the usage lines 0x22C2-0x22C5.
// FUNCTION: TITANIUM 0x0046D23C
void __cdecl do_taskhelp_guess() {
    if (g_stateHolder_guess != 0 &&
        (g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess + 1] & 1) != 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x22c6, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x22c2, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x22c3, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x22c4, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x22c5, 0));
    }
}

// EXTERNAL: TITANIUM 0x004CC98F rdtsc_elapsed
__int64 __cdecl rdtsc_elapsed(void);

struct MessagePacket_46D2F6_guess {
    int message_guess;
    char flag_guess;
    char text_guess[0x103];
};

struct ParsedRecord_46D3A3_guess {
    unsigned int values_000_guess[6];
    unsigned int value_018_guess;
    char pad_01c_guess[4];
    char flag_020_guess;
    char pad_021_guess[3];
    unsigned int value_024_guess;
    unsigned int value_028_guess;
};

// /resetCreationServer <text>: opcode 0x6934 with {1, 0, text[0x100]} (EQEmu's conf calls 0x6934
// OP_SharedTaskAddPlayer, which doesn't fit this payload); no text prints 0xE28.
// FUNCTION: TITANIUM 0x0046D2F6
void __cdecl do_resetCreationServer_guess(int unused_guess, const char* text_guess) {
    MessagePacket_46D2F6_guess packet_guess;
    if (text_guess != 0 && strlen(text_guess) > 0) {
        packet_guess.message_guess = 1;
        packet_guess.flag_guess = 0;
        FUN_00576fa0_guess(packet_guess.text_guess, text_guess, 0x100);
        FUN_004912b1_guess(&gSendTarget_guess, OP_SharedTaskAddPlayer, &packet_guess, 0x108, 1);
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0xe28, 0), 0xd, 1);
    }
}

// Returns 0 when all 10 fields parse: item id and five augment ids (5 hex digits each), a 1-digit
// flag, 4 hex, one more field, then the 8-hex link hash.
// FUNCTION: TITANIUM 0x0046D3A3
int __cdecl ParseItemLink_guess(const char* text_guess, ParsedRecord_46D3A3_guess* record_guess) {
    // An item link body is exactly 44 characters.
    if (strlen(text_guess) != 0x2c) {
        return 1;
    }
    int total_guess = sscanf(text_guess, gFormat5X_guess, &record_guess->values_000_guess[0]);
    const char* cursor_guess = text_guess + 5;
    unsigned int* destination_guess = &record_guess->values_000_guess[1];
    int remaining_guess = 5;
    do {
        total_guess += sscanf(cursor_guess, gFormat5X_guess, destination_guess);
        destination_guess++;
        cursor_guess += 5;
        remaining_guess--;
    } while (remaining_guess != 0);
    int flagValue_guess;
    total_guess += sscanf(cursor_guess, gFormat1D_guess, &flagValue_guess);
    cursor_guess++;
    record_guess->flag_020_guess = (char)(flagValue_guess != 0);
    total_guess += sscanf(cursor_guess, gFormat4X_guess, &record_guess->value_024_guess);
    cursor_guess += 4;
    total_guess += sscanf(cursor_guess, gFormatField_guess, &record_guess->value_028_guess);
    cursor_guess++;
    total_guess += sscanf(cursor_guess, gFormat8X_guess, &record_guess->value_018_guess);
    return total_guess != 10;
}

struct Text_46D46D_guess : W_guess {
    // EXTERNAL: TITANIUM 0x005715D0 Text_46D46D_guess::GetAt_guess
    unsigned short GetAt_guess(int index_guess) const;
    // EXTERNAL: TITANIUM 0x00572130 Text_46D46D_guess::Delete_guess
    void Delete_guess(int index_guess, int count_guess);
    // EXTERNAL: TITANIUM 0x00572F20 Text_46D46D_guess::Insert_guess
    void Insert_guess(int index_guess, const CXStr& text_guess);
    int Length_guess() const {
        return Ptr != 0 ? Ptr->length : 0;
    }
};

#define gLengthTable_46D46D_guess EQ_ARRAY(int, 0x00665340)

// EXTERNAL: TITANIUM 0x005A4190 FUN_005a4190_guess
CXStr __cdecl FUN_005a4190_guess(int type_guess, CXStr* first_guess, CXStr* second_guess);

// Item links are wrapped in 0x12 bytes, a type digit picking the header length (0x665340). With
// `expand` each link becomes 0x5A4190's markup (kind 0x1B); without it only the link text stays.
// An unclosed 0x12 is dropped.
// FUNCTION: TITANIUM 0x0046D46D
// @early-stop: budget, diff ndiff=10
void __cdecl ConvertItemTags(CXStr* source_guess, char expand_guess) {
    Text_46D46D_guess* text_guess = static_cast<Text_46D46D_guess*>(source_guess);
    for (int i = 0; i < text_guess->Length_guess(); ++i) {
        if (text_guess->GetAt_guess(i) != 0x12)
            continue;
        int end_guess;
        for (end_guess = i + 2;; ++end_guess) {
            if (end_guess >= text_guess->Length_guess()) {
                end_guess = -1;
                break;
            }
            if (text_guess->GetAt_guess(end_guess) == 0x12)
                break;
        }
        if (end_guess == -1) {
            text_guess->Delete_guess(i, 1);
            --i;
            continue;
        }
        int digit_guess = text_guess->GetAt_guess(i + 1) - '0';
        if (expand_guess) {
            int* tokenLength_guess = &gLengthTable_46D46D_guess[digit_guess];
            CXStr first_guess = text_guess->F_guess(i + 2, *tokenLength_guess - 3);
            int length_guess = *tokenLength_guess;
            CXStr second_guess = text_guess->F_guess(length_guess + i - 1, end_guess - length_guess - i + 1);
            CXStr replacement_guess = FUN_005a4190_guess(0x1b, &second_guess, &first_guess);
            (char*)replacement_guess;
            text_guess->Delete_guess(i, end_guess - i + 1);
            text_guess->Insert_guess(i, replacement_guess);
            i += (replacement_guess.Ptr != 0 ? replacement_guess.Ptr->length : 0) - 1;
        } else {
            text_guess->Delete_guess(end_guess, 1);
            text_guess->Delete_guess(i, gLengthTable_46D46D_guess[digit_guess] - 1);
            --i;
        }
    }
}

// Splits a number of seconds into days, hours, minutes and seconds; zero or negative input gives all
// zeros.
// FUNCTION: TITANIUM 0x0046D607
void __cdecl GetDaysHoursMinutesSeconds_guess(int value, int* days, int* hours, int* minutes, int* seconds) {
    *days = 0;
    *hours = 0;
    *minutes = 0;
    *seconds = 0;
    if (value > 0) {
        *days = value / 0x15180;
        int remainder = value % 0x15180;
        *hours = remainder / 0xe10;
        remainder %= 0xe10;
        *minutes = remainder / 0x3c;
        *seconds = remainder % 0x3c;
    }
}

struct Transform_46D6C3_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    float deltaX_guess;
    float deltaY_guess;
    union {
        float deltaZ_guess;
        unsigned int deltaZBits_guess;
    };
    void SetDeltaTo_guess(const Transform_46D6C3_guess* source_guess);
    void Copy_guess(const Transform_46D6C3_guess* source_guess,
                    const Transform_46D6C3_guess* target_guess);
};

union Difference_46D6C3_guess {
    struct {
        float x_guess;
        float y_guess;
        float z_guess;
    } value_guess;
    unsigned int bits_guess[3];
};

// Stores `target` minus this point as the delta (+0xC); the z word goes over as raw bits (match shape).
// FUNCTION: TITANIUM 0x0046D6C3
void Transform_46D6C3_guess::SetDeltaTo_guess(
    const Transform_46D6C3_guess* source_guess) {
    Difference_46D6C3_guess difference_guess;
    difference_guess.value_guess.x_guess = source_guess->x_guess - x_guess;
    difference_guess.value_guess.y_guess = source_guess->y_guess - y_guess;
    difference_guess.value_guess.z_guess = source_guess->z_guess - z_guess;
    unsigned int* deltaZBitsSlot_guess = &deltaZBits_guess;
    *deltaZBitsSlot_guess = difference_guess.bits_guess[2];
    deltaX_guess = difference_guess.value_guess.x_guess;
    deltaY_guess = difference_guess.value_guess.y_guess;
}

// Milliseconds: the rdtsc count over the ticks-per-millisecond value at 0x988C68.
// FUNCTION: TITANIUM 0x0046D655
__int64 __cdecl EqGetTime(void) {
    return rdtsc_elapsed() / EQ_GLOBAL(__int64, 0x00988C68);
}

// Takes `source`'s position, then stores `target` minus it as the delta (0x0046D6C3).
// FUNCTION: TITANIUM 0x0046D6F3
void Transform_46D6C3_guess::Copy_guess(
    const Transform_46D6C3_guess* source_guess,
    const Transform_46D6C3_guess* target_guess) {
    x_guess = source_guess->x_guess;
    y_guess = source_guess->y_guess;
    z_guess = source_guess->z_guess;
    SetDeltaTo_guess(target_guess);
}

struct SerialVlong_guess {
    int negative_guess;
    int refs_guess;
    unsigned int data_guess[64];
    int capacity_guess;
    int count_guess;
};

struct SerialKey_guess {
    SerialVlong_guess first_guess;
    SerialVlong_guess second_guess;
};

#define gKey_46_guess EQ_GLOBAL(vlong_public_key_guess, 0x009006EC)

// This file's `free` is bound to operator delete; the CRT free is 0x0060E07D.
// EXTERNAL: TITANIUM 0x0060E07D CrtFree_46_guess
extern "C" void __cdecl CrtFree_46_guess(void* memory_guess);

// Encrypts 8 random bytes with the given public key (copied into 0x9006EC) and sends the result as
// opcode 0x3C25 (EQEmu: OP_ApproveWorld). Always returns 1.
// FUNCTION: TITANIUM 0x0046D7D4
int __cdecl SendEncryptedSeed_guess(SerialKey_guess* key_guess, int connection_guess) {
    PairHolder_46_guess result_guess(0, 0);
    PairHolder_46_guess unused_guess(0, 0);
    unsigned __int64 seed_guess;
    seed_guess = RandomRange_guess(0, 0xff);
    seed_guess |= RandomRange_guess(0, 0xff) << 8;
    seed_guess |= RandomRange_guess(0, 0xff) << 16;
    seed_guess |= RandomRange_guess(0, 0xff) << 24;
    seed_guess |= (__int64)RandomRange_guess(0, 0xff) << 32;
    seed_guess |= (__int64)RandomRange_guess(0, 0xff) << 40;
    seed_guess |= (__int64)RandomRange_guess(0, 0xff) << 48;
    seed_guess |= (__int64)RandomRange_guess(0, 0xff) << 56;

    gKey_46_guess.first_guess.unknown04_guess = key_guess->first_guess.negative_guess;
    gKey_46_guess.first_guess.values_guess->refs_guess = key_guess->first_guess.refs_guess;
    gKey_46_guess.first_guess.values_guess->count_guess = key_guess->first_guess.count_guess;
    int count_guess = gKey_46_guess.first_guess.values_guess->count_guess;
    gKey_46_guess.first_guess.values_guess->capacity_guess = key_guess->first_guess.capacity_guess;
    gKey_46_guess.first_guess.values_guess->data_guess = (unsigned int*)malloc(0x100);
    int i;
    for (i = 0; i < count_guess; ++i) {
        gKey_46_guess.first_guess.values_guess->data_guess[i] = key_guess->first_guess.data_guess[i];
    }

    gKey_46_guess.second_guess.unknown04_guess = key_guess->second_guess.negative_guess;
    gKey_46_guess.second_guess.values_guess->refs_guess = key_guess->second_guess.refs_guess;
    gKey_46_guess.second_guess.values_guess->count_guess = key_guess->second_guess.count_guess;
    count_guess = gKey_46_guess.second_guess.values_guess->count_guess;
    gKey_46_guess.second_guess.values_guess->capacity_guess = key_guess->second_guess.capacity_guess;
    gKey_46_guess.second_guess.values_guess->data_guess = (unsigned int*)malloc(0x100);
    for (i = 0; i < count_guess; ++i) {
        gKey_46_guess.second_guess.values_guess->data_guess[i] = key_guess->second_guess.data_guess[i];
    }

    PairHolder_46_guess plain_guess((int)seed_guess, (int)(seed_guess >> 32));
    result_guess = gKey_46_guess.Encrypt_guess(plain_guess);

    SerialVlong_guess message_guess;
    message_guess.negative_guess = result_guess.unknown04_guess;
    message_guess.refs_guess = result_guess.values_guess->refs_guess;
    count_guess = result_guess.values_guess->count_guess;
    message_guess.count_guess = count_guess;
    message_guess.capacity_guess = result_guess.values_guess->capacity_guess;
    for (i = 0; i < count_guess; ++i) {
        message_guess.data_guess[i] = result_guess.values_guess->data_guess[i];
    }
    SendMessage_guess(&connection_guess, OP_ApproveWorld, &message_guess, sizeof(message_guess), 1);

    if (gKey_46_guess.first_guess.values_guess->data_guess != 0) {
        CrtFree_46_guess(gKey_46_guess.first_guess.values_guess->data_guess);
    }
    if (gKey_46_guess.second_guess.values_guess->data_guess != 0) {
        CrtFree_46_guess(gKey_46_guess.second_guess.values_guess->data_guess);
    }
    return 1;
}

// EXTERNAL: TITANIUM 0x00467441 ReplaceTokens_guess
void __cdecl ReplaceTokens_guess(char* destination_guess, const char* text_guess,
                                 const char** params_guess, int length_guess, int flags_guess);

// Expands eqstr `token` with up to nine %1..%9 parameters into `buffer` and returns it.
// FUNCTION: TITANIUM 0x0046DA4A
char* __cdecl build_token_string_PARAM_guess(char* buffer_guess, int token_guess,
                                             const char* p0_guess, const char* p1_guess,
                                             const char* p2_guess, const char* p3_guess,
                                             const char* p4_guess, const char* p5_guess,
                                             const char* p6_guess, const char* p7_guess,
                                             const char* p8_guess) {
    const char* params_guess[9];
    params_guess[0] = p0_guess;
    params_guess[1] = p1_guess;
    params_guess[2] = p2_guess;
    params_guess[3] = p3_guess;
    params_guess[4] = p4_guess;
    params_guess[5] = p5_guess;
    params_guess[6] = p6_guess;
    params_guess[7] = p7_guess;
    params_guess[8] = p8_guess;
    ReplaceTokens_guess(buffer_guess, gTextLookup_guess->FindText_guess(token_guess, 0), params_guess, -1, 0);
    return buffer_guess;
}

// Prints eqstr `token` with up to nine parameters in chat colour `color`
// (token_string_to_client in the earlier sibling decomp); the first argument and the tenth parameter are unused.
// FUNCTION: TITANIUM 0x0046DC2E
void __cdecl FormatTokenStringToClient_guess(void* unused_guess, int token_guess, int color_guess,
                                const char* p0_guess, const char* p1_guess,
                                const char* p2_guess, const char* p3_guess,
                                const char* p4_guess, const char* p5_guess,
                                const char* p6_guess, const char* p7_guess,
                                const char* p8_guess, const char* p9_guess) {
    const char* params_guess[9];
    char buffer_guess[0x400];
    params_guess[0] = p0_guess;
    params_guess[1] = p1_guess;
    params_guess[2] = p2_guess;
    params_guess[3] = p3_guess;
    params_guess[4] = p4_guess;
    params_guess[5] = p5_guess;
    params_guess[6] = p6_guess;
    params_guess[7] = p7_guess;
    params_guess[8] = p8_guess;
    ReplaceTokens_guess(buffer_guess, pStringTable->getString(token_guess, 0), params_guess, -1, 0);
    pEverQuest->dsp_chat(buffer_guess, color_guess, true);
}

struct PropertyHolder_guess {
    unsigned char padding_guess[4];
    int vbaseOffset_0004_guess;
};

struct PropertyData_guess {
    unsigned char padding_guess[0x119c];
    unsigned char mode_119c_guess;
    unsigned char padding_119d_guess[7];
    int level_11a4_guess;
};

struct PropertyLocator_guess {
    // EXTERNAL: TITANIUM 0x005EC220 PropertyLocator_guess::GetCharInfo2
    PropertyData_guess* GetCharInfo2();
};

struct PropertyOwner_guess {
    unsigned char padding_guess[4];
    PropertyLocator_guess locator_guess;
    // EXTERNAL: TITANIUM 0x00455023 PropertyOwner_guess::Set11a4_guess
    void Set11a4_guess(int value_guess);
};

struct PropertyHost_guess {
    unsigned char padding_guess[8];
    union {
        PropertyHolder_guess* holder_guess;
        unsigned char embedded_guess[1];
    };
    // EXTERNAL: TITANIUM 0x005ED510 PropertyHost_guess::FUN_005ed510_guess
    unsigned char FUN_005ed510_guess();
    // EXTERNAL: TITANIUM 0x005ED530 PropertyHost_guess::FUN_005ed530_guess
    void FUN_005ed530_guess(unsigned char value_guess);
};

// Sets the profile level (+0x11A4), then lowers the host's byte value (0x5ED510/0x5ED530) to it when it
// is higher; the meaning of that value is unknown.
// FUNCTION: TITANIUM 0x0046DCDC
void __cdecl SetCharacterLevel_guess(PropertyHost_guess* host_guess, unsigned char value_guess) {
    PropertyOwner_guess* owner_guess;
    owner_guess = (PropertyOwner_guess*)&host_guess->embedded_guess[host_guess->holder_guess->vbaseOffset_0004_guess];
    owner_guess->Set11a4_guess(value_guess);
    owner_guess = (PropertyOwner_guess*)&host_guess->embedded_guess[host_guess->holder_guess->vbaseOffset_0004_guess];
    int limit_guess = owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess;
    if (limit_guess > (unsigned char)host_guess->FUN_005ed510_guess()) {
        owner_guess = (PropertyOwner_guess*)&host_guess->embedded_guess[host_guess->holder_guess->vbaseOffset_0004_guess];
        host_guess->FUN_005ed530_guess((unsigned char)owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess);
    }
}

// /gsay <text>: through the CEverQuest chat buffer (+0x17BB4).
// FUNCTION: TITANIUM 0x004678D8
void __cdecl do_gsay_guess(int unused, const char* source) {
    FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, source);
    gGlobalContext_guess->send_gsay_guess();
}

// /yell: eqstr 0x331F 'You yell for help.' and OP_YellForHelp 0x61EF.
// FUNCTION: TITANIUM 0x0046791A
void __cdecl do_yell_guess() {
    const char* text_guess = gTextLookup_guess->FindTextTyped_guess(0x331f, 0, 0xd, 1);
    gGlobalContext_guess->Show_guess(text_guess);
    FUN_004912b1_guess(&gSendTarget_guess, OP_YellForHelp, 0, 0, 1);
}

// /auction <text>.
// FUNCTION: TITANIUM 0x00467955
void __cdecl do_auction_guess(int unused, const char* source) {
    FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, source);
    gGlobalContext_guess->send_auction_guess();
}

// /ooc <text>.
// FUNCTION: TITANIUM 0x00467976
void __cdecl do_ooc_guess(int unused, const char* source) {
    FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, source);
    gGlobalContext_guess->send_ooc_guess();
}

// /tell, /msg, /send <name> <text>.
// FUNCTION: TITANIUM 0x00467997
void __cdecl do_tell_guess(int unused, const char* source) {
    char buffer[0x840];
    int length = GrabFirstWord_guess(source, buffer, 0x840);
    gGlobalContext_guess->send_tell_guess(buffer, length);
}

// /ttell <text>: tells the target; a corpse name is cut at the apostrophe, and names with '#' or '_'
// (NPCs) are refused with eqstr 0x3322.
// FUNCTION: TITANIUM 0x004679DC
void __cdecl do_ttell_guess(int unused_guess, const char* source_guess) {
    if (source_guess == 0 || source_guess[0] == '\0')
        return;

    if (gIncomingMessage_guess != 0) {
        char buffer_guess[512];
        bool useIncomingText_guess = true;
        if (gIncomingMessage_guess->text_120_guess[0] == '\0' ||
            gIncomingMessage_guess->byte_244_guess == 1)
            useIncomingText_guess = false;

        FUN_0060e450_guess(buffer_guess, gIncomingMessage_guess->text_120_guess);
        if (gIncomingMessage_guess->byte_244_guess == 2 ||
            gIncomingMessage_guess->byte_244_guess != 3) {
            if (FUN_0060f520_guess(buffer_guess, 0x23) == 0 &&
                FUN_0060f520_guess(buffer_guess, 0x5f) == 0)
                useIncomingText_guess = true;
            else
                useIncomingText_guess = false;

            char* apostrophe_guess = FUN_0060f520_guess(buffer_guess, 0x27);
            if (apostrophe_guess != 0)
                *apostrophe_guess = '\0';
        }

        if (!useIncomingText_guess)
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x3322, 0));
        else
            gGlobalContext_guess->send_tell_guess(buffer_guess, (int)source_guess);
    }
}

#define gTellListCursor_guess EQ_GLOBAL(int, 0x009265A0)

// Pushes a name onto the 50-slot tell list at 0x925920 (most recent first, 64 bytes each); a duplicate
// further down is removed and the slot that fell off the end comes back.
// FUNCTION: TITANIUM 0x00467AD1
void __cdecl AddNameToTellList_guess(const char* name_guess) {
    char saved_guess[0x40];
    if (gNameSlots_guess[49].text_guess[0] != '\0')
        FUN_0060e450_guess(saved_guess, gNameSlots_guess[49].text_guess);
    else
        saved_guess[0] = '\0';

    int i;
    for (i = 49; i >= 1; --i)
        FUN_0060e450_guess(gNameSlots_guess[i].text_guess, gNameSlots_guess[i - 1].text_guess);

    FUN_0060e450_guess(gNameSlots_guess[0].text_guess, name_guess);
    gTellListCursor_guess = 0;
    for (i = 1; i < 50; ++i) {
        if (__stricmp(gNameSlots_guess[0].text_guess, gNameSlots_guess[i].text_guess) == 0) {
            for (; i < 49; ++i)
                FUN_0060e450_guess(gNameSlots_guess[i].text_guess, gNameSlots_guess[i + 1].text_guess);
            if (saved_guess[0] != '\0')
                FUN_0060e450_guess(gNameSlots_guess[49].text_guess, saved_guess);
            return;
        }
    }
}

struct Entry_467d40_guess {
    char pad_000_guess[0x244];
    char flag_244_guess;
    char pad_245_guess[0x258 - 0x245];
    int value_258_guess;
};
#define gEntryList_467d40_guess EQ_GLOBAL(Entry_467d40_guess*, 0x00905CE4)
#define gActiveEntry_467d40_guess EQ_GLOBAL(Entry_467d40_guess*, 0x00905D04)

// EXTERNAL: TITANIUM 0x005742E0 FUN_005742e0_guess
char* __cdecl FUN_005742e0_guess(const char* text_guess, int length_guess);

#define gStateBusy_467b95_guess EQ_GLOBAL(char, 0x00926560)

// Moves the tell-list cursor 0x9265A0 (1 = back, else forward) over non-empty slots; eqstr 0x304C
// when the list is empty.
// FUNCTION: TITANIUM 0x00467B95
// @early-stop: budget, structural ndiff=17
void __cdecl CycleNamesInTellList_guess(int value_guess) {
    if (gNameSlots_guess[0].text_guess[0] == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x304c, 0));
        return;
    }
    if (value_guess == 1) {
        if (gTellListCursor_guess > 0) {
            --gTellListCursor_guess;
            return;
        }
        gTellListCursor_guess = 0x31;
        if (gStateBusy_467b95_guess != 0) {
            return;
        }
        while (--gTellListCursor_guess >= 0 && gTellListCursor_guess < 0x32) {
            if (gNameSlots_guess[gTellListCursor_guess].text_guess[0] != '\0') {
                return;
            }
        }
    } else if (gTellListCursor_guess < 0x31 &&
               gNameSlots_guess[gTellListCursor_guess + 1].text_guess[0] != '\0') {
        ++gTellListCursor_guess;
        return;
    }
    gTellListCursor_guess = 0;
}

// /reply <text>: tells the last name on the tell list; channel entries (';' chat server, '[' mail
// server) are rebuilt as "<prefix><eqstr 0x3696 minus its first char> name text". Empty list 0x304C.
// FUNCTION: TITANIUM 0x00467C25
void __cdecl do_reply_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x800];
    if (gNameSlots_guess[0].text_guess[0] == '\0') {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x304c, 0));
    } else if (gNameSlots_guess[0].text_guess[0] == ';') {
        sprintf(buffer_guess, "%c%s %s %s", gNameSlots_guess[0].text_guess[0],
                gTextLookup_guess->FindText_guess(0x3696, 0) + 1, gNameSlots_guess[0].text_guess + 1, text_guess);
        gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, 1);
        gGlobalContext_guess->ChatServerMessage_guess(buffer_guess);
    } else if (gNameSlots_guess[0].text_guess[0] == '[') {
        sprintf(buffer_guess, "%c%s %s %s", gNameSlots_guess[0].text_guess[0],
                gTextLookup_guess->FindText_guess(0x3696, 0) + 1, gNameSlots_guess[0].text_guess + 1, text_guess);
        gGlobalContext_guess->DoPercentConvert_guess(buffer_guess, 1);
        gGlobalContext_guess->SendMailServerCommand_guess(buffer_guess);
    } else {
        gGlobalContext_guess->send_tell_guess(gNameSlots_guess[0].text_guess, (int)text_guess);
    }
}

// /pet <command>: maps the word (eqstr 0x1D4C..0x1D61 and friends) to a pet command code. The attack
// words 0x3324..0x332D take a name, tried as typed, '#'-prefixed, 'a_' and '#a_' (spaces become '_').
// FUNCTION: TITANIUM 0x00467D40
void __cdecl do_pet_guess(int unused_guess, const char* text_guess) {
    int code_guess = 0;
    int extra_guess = 0;
    char candidate_guess[256];
    char name_guess[256];

    if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d4c, 0)) == 0 ||
        FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d4d, 0)) == 0) {
        code_guess = 1;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d4e, 0)) == 0) {
        code_guess = 0xb;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5a, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d4f, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d55, 0)) == 0) {
        code_guess = 0xe;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5d, 0)) == 0) {
        code_guess = 0xd;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d50, 0)) == 0) {
        code_guess = 2;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d51, 0)) == 0) {
        code_guess = 3;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d52, 0)) == 0) {
        code_guess = 5;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d53, 0)) == 0) {
        code_guess = 6;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d54, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x17ff, 0)) == 0) {
        code_guess = 8;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x2453, 0)) == 0) {
        code_guess = 0x13;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x2454, 0)) == 0) {
        code_guess = 0x12;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d56, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5e, 0)) == 0) {
        code_guess = 9;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d57, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5f, 0)) == 0) {
        code_guess = 0xa;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d58, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5b, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1800, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d5c, 0)) == 0) {
        code_guess = 4;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d59, 0)) == 0) {
        code_guess = 0xc;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x332f, 0)) == 0) {
        code_guess = 0xf;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d61, 0)) == 0 ||
               FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0x1d60, 0)) == 0) {
        code_guess = 0x10;
        if (gActiveEntry_467d40_guess != 0 && gActiveEntry_467d40_guess->flag_244_guess == 1)
            extra_guess = gActiveEntry_467d40_guess->value_258_guess;
    } else if (FUN_00574950_guess(text_guess, gTextLookup_guess->FindText_guess(0xcc8, 0)) == 0) {
        code_guess = 0x11;
    } else {
        // Attack words (code 7): the named spawn's id, else the current target's (+0x258).
        int ids_guess[10] = {0x3324, 0x3325, 0x3326, 0x3327, 0x3328,
                             0x3329, 0x332a, 0x332b, 0x332c, 0x332d};
        const char* label_guess;
        int length_guess;
        for (unsigned int i = 0; i < 10; ++i) {
            label_guess = gTextLookup_guess->FindText_guess(ids_guess[i], 0);
            length_guess = FUN_00574270_guess(label_guess);
            if (FUN_00574990_guess(text_guess, label_guess, length_guess) == 0) {
                char* rest_guess = FUN_005742e0_guess(text_guess, length_guess);
                if (rest_guess != 0 && *rest_guess != '\0') {
                    while (*rest_guess == ' ')
                        rest_guess++;
                    FUN_00576fa0_guess(name_guess, rest_guess, 0x100);
                    for (char* p = name_guess; *p != '\0'; ++p) {
                        if (*p == ' ')
                            *p = '_';
                    }
                    LookupResult_guess* hit_guess = get_player_partial_name_guess(name_guess, gEntryList_467d40_guess, 1);
                    if (hit_guess == 0) {
                        sprintf(candidate_guess, "#%s", name_guess);
                        hit_guess = get_player_partial_name_guess(candidate_guess, gEntryList_467d40_guess, 1);
                    }
                    if (hit_guess == 0) {
                        sprintf(candidate_guess, "a_%s", name_guess);
                        hit_guess = get_player_partial_name_guess(candidate_guess, gEntryList_467d40_guess, 1);
                    }
                    if (hit_guess == 0) {
                        sprintf(candidate_guess, "#a_%s", name_guess);
                        hit_guess = get_player_partial_name_guess(candidate_guess, gEntryList_467d40_guess, 1);
                    }
                    if (hit_guess != 0) {
                        code_guess = 7;
                        extra_guess = hit_guess->spawnId_0258_guess;
                    }
                } else if (gActiveEntry_467d40_guess != 0 && gActiveEntry_467d40_guess != gEntryList_467d40_guess) {
                    code_guess = 7;
                    extra_guess = gActiveEntry_467d40_guess->value_258_guess;
                }
                break;
            }
        }
    }
    // Unknown words leave code 0; the pet command goes out as (code, spawn id).
    gGlobalContext_guess->IssuePetCommand_guess(code_guess, extra_guess);
}

#define gModeFlag_4683af_guess EQ_GLOBAL(bool, 0x00923D64)

// /petition <text>: eqstr 0x3332 when blank. With the flag 0x923D64 set it toggles the window at
// 0x9928A8 instead (probably the petition queue).
// FUNCTION: TITANIUM 0x004683AF
void __cdecl do_petition_guess(int unused_guess, const char* text_guess) {
    if (gModeFlag_4683af_guess != 0) {
        if (pinstCTicketWnd_guess != 0) {
            if (pinstCTicketWnd_guess->IsVisible_guess() != 0) {
                pinstCTicketWnd_guess->Deactivate();
            } else {
                pinstCTicketWnd_guess->Activate();
                pinstCTicketWnd_guess->ShowPage_guess(1);
            }
            pinstCTicketWnd_guess->StoreIniVis();
        }
        return;
    }
    if (text_guess != 0 && *text_guess != '\0') {
        FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, text_guess);
        gGlobalContext_guess->send_petition_guess(0);
        return;
    }
    gGlobalContext_guess->Show_guess(
        gTextLookup_guess->FindTextTyped_guess(0x3332, 0, 0xf, 1));
}

// /guidehelp <text>: the petition send with kind 1; usage eqstr 0xDE3.
// FUNCTION: TITANIUM 0x0046844E
void __cdecl do_guidehelp_guess(int unused_guess, const char* text_guess) {
    if (text_guess != 0 && *text_guess != '\0') {
        FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, text_guess);
        gGlobalContext_guess->send_petition_guess(1);
        return;
    }
    gGlobalContext_guess->Show_guess(
        gTextLookup_guess->FindTextTyped_guess(0xde3, 0, 0xf, 1));
}

// /keys: OP_KeyRing 0x68C4 with the 4 bytes at 0x6460B0.
// FUNCTION: TITANIUM 0x004684AF
void __cdecl do_keys_guess(void) {
    FUN_004912b1_guess(&gSendTarget_guess, OP_KeyRing,
                      EQ_ARRAY(char, 0x006460B0), 4, 1);
}

// /private <text>: GM only (player +0x256).
// FUNCTION: TITANIUM 0x004684CB
void __cdecl do_private_guess(int unused_guess, const char* text_guess) {
    if (gConnection_guess->gm_0256_guess == 0)
        return;
    FUN_0060e450_guess(&gGlobalContext_guess->text_17bb4_guess, text_guess);
    gGlobalContext_guess->send_private_guess();
}

struct Packet_4684FB_guess {
    char pad_000_guess[0x40];
    char text_040_guess[0x40];
    int value_080_guess;
};

// /searchcorpse <name> (GM): OP_GMSearchCorpse 0x3C32, name at +0x40; usage eqstr 0x3339.
// FUNCTION: TITANIUM 0x004684FB
void __cdecl do_searchcorpse_guess(int unused_guess, char* text_guess) {
    if (gConnection_guess->gm_0256_guess != 0) {
        if (text_guess == 0 || *text_guess == '\0') {
            gGlobalContext_guess->SetText_guess(
                gTextLookup_guess->FindText_guess(0x3339, 0), 0xf, 1);
        } else {
            Packet_4684FB_guess packet_guess;
            memset(&packet_guess, 0, sizeof(packet_guess));
            FUN_0060e450_guess(packet_guess.text_040_guess, text_guess);
            packet_guess.value_080_guess = 0;
            FUN_004912b1_guess(&gSendTarget_guess, OP_GMSearchCorpse, &packet_guess,
                               sizeof(packet_guess), 1);
            gGlobalContext_guess->SetText_guess(
                gTextLookup_guess->FindText_guess(0x333b, 0), 0xf, 1);
        }
    }
}

#define gNoSafeDrop_guess EQ_GLOBAL(int, 0x009254DC)

// /fastdrop on|off|<eqstr 0x32BD>: [Options] NoSafeDrop 1, 0 or -1.
// FUNCTION: TITANIUM 0x004685BA
void __cdecl do_fastdrop_guess(int unused, const char* text) {
    if (FUN_00574950_guess(text, gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
        gNoSafeDrop_guess = 1;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x333c, 0));
    } else if (FUN_00574950_guess(text, gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
        gNoSafeDrop_guess = 0;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x333d, 0));
    } else if (FUN_00574950_guess(text, gTextLookup_guess->FindText_guess(0x32bd, 0)) == 0) {
        gNoSafeDrop_guess = -1;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x333e, 0));
    } else {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x333f, 0));
        return;
    }
    gGlobalContext_guess->WriteInt_guess(gNoSafeDrop_guess, "Options", "NoSafeDrop");
}

#pragma pack(push, 1)
struct ErrorMessage_468694_guess {
    char pad_000_guess[4];
    char flag_004_guess;
    char pad_005_guess[3];
    int value_008_guess;
    int value_00c_guess;
    char pad_010_guess[0x40];
};

#pragma pack(pop)


// /lfg on|off: 0x50-byte LFG packet (flag at +4, 100 at +0xC, the shape EQEmu logs for OP_LFG);
// anything else opens the LFG window; without one, eqstr 0x3350 when the first arg is nonzero.
// FUNCTION: TITANIUM 0x00468694
void __cdecl do_lfg_guess(int enabled_guess, const char* text_guess) {
    char state_guess;
    ErrorMessage_468694_guess message_guess;

    if (FUN_00574950_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
        state_guess = 1;
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x334e, 0));
    } else {
        if (FUN_00574950_guess(text_guess,
                               gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
            state_guess = 0;
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x334f, 0));
        } else {
            if (pinstCGroupSearchWnd_guess != 0) {
                pinstCGroupSearchWnd_guess->Activate();
            } else if (enabled_guess != 0) {
                gGlobalContext_guess->dsp_chat(
                    gTextLookup_guess->FindText_guess(0x3350, 0));
            }
            return;
        }
    }

    memset(&message_guess, 0, sizeof(message_guess));
    message_guess.flag_004_guess = state_guess;
    message_guess.value_008_guess = 0;
    message_guess.value_00c_guess = 100;
    gGlobalContext_guess->SendLFGCommand_guess(&message_guess);
}

#define gTrackPlayers_guess EQ_GLOBAL(int, 0x00923CA8)

// /trackplayers on|off|group (eqstr 0x335C): [Defaults] TrackPlayers 1, 0, 2; refreshes tracking.
// FUNCTION: TITANIUM 0x00468781
void __cdecl do_trackplayers_guess(int unused, const char* text) {
    if (__stricmp(text, gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
        gTrackPlayers_guess = 1;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3354, 0));
        FUN_0060beb0_guess("Defaults", "TrackPlayers", "TRUE", ".\\eqclient.ini");
    } else if (__stricmp(text, gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
        gTrackPlayers_guess = 0;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3355, 0));
        FUN_0060beb0_guess("Defaults", "TrackPlayers", "FALSE", ".\\eqclient.ini");
    } else if (__stricmp(text, gTextLookup_guess->FindText_guess(0x335c, 0)) == 0) {
        gTrackPlayers_guess = 2;
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3356, 0));
        FUN_0060beb0_guess("Defaults", "TrackPlayers", "GROUP", ".\\eqclient.ini");
    } else {
        gGlobalContext_guess->dsp_chat(gTextLookup_guess->FindText_guess(0x3357, 0));
    }
    pinstCTrackingWnd_guess->ApplyTrackingFilters_guess(1);
}

#define gCombatMusic_guess EQ_GLOBAL(int, 0x009248D8)
#define gCombatMusicOn_guess EQ_ARRAY(char, 0x00645EB4)
#define gCombatMusicOff_guess EQ_ARRAY(char, 0x006410A8)
#define gShowSpellEffects_guess EQ_GLOBAL(int, 0x0092484C)

// /showspelleffects on|off: any word but off turns it on; [Defaults] ShowSpellEffects.
// FUNCTION: TITANIUM 0x004688B3
void __cdecl do_showspelleffects_guess(int unused_guess, const char* text_guess) {
    char buffer[256];
    if (*text_guess != '\0') {
        if (FUN_00574950_guess(text_guess,
                               gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
            gShowSpellEffects_guess = 0;
            FUN_0060beb0_guess("Defaults", "ShowSpellEffects", gCombatMusicOff_guess,
                               ".\\eqclient.ini");
        } else {
            gShowSpellEffects_guess = 1;
            FUN_0060beb0_guess("Defaults", "ShowSpellEffects", gCombatMusicOn_guess,
                               ".\\eqclient.ini");
        }
    } else {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3370, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3371, 0));
    }
    if (gShowSpellEffects_guess != 0) {
        FUN_0060e450_guess(buffer,
                           gTextLookup_guess->FindText_guess(0x3372, 0));
    } else {
        FUN_0060e450_guess(buffer,
                           gTextLookup_guess->FindText_guess(0x3373, 0));
    }
    gGlobalContext_guess->dsp_chat(buffer);
}

// /combatmusic on|off: any word but off turns it on; [Defaults] CombatMusic.
// FUNCTION: TITANIUM 0x004689A2
void __cdecl do_combatmusic_guess(int unused_guess, const char* text_guess) {
    char buffer[256];
    if (*text_guess != '\0') {
        if (FUN_00574950_guess(text_guess,
                               gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
            gCombatMusic_guess = 0;
            FUN_0060beb0_guess("Defaults", "CombatMusic", gCombatMusicOff_guess,
                               ".\\eqclient.ini");
        } else {
            gCombatMusic_guess = 1;
            FUN_0060beb0_guess("Defaults", "CombatMusic", gCombatMusicOn_guess,
                               ".\\eqclient.ini");
        }
    } else {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x1d63, 0));
    }
    if (gCombatMusic_guess != 0) {
        FUN_0060e450_guess(buffer,
                           gTextLookup_guess->FindText_guess(0x1d64, 0));
    } else {
        FUN_0060e450_guess(buffer,
                           gTextLookup_guess->FindText_guess(0x1d65, 0));
    }
    gGlobalContext_guess->dsp_chat(buffer);
}

struct LightSet_468a74_guess {
    // EXTERNAL: TITANIUM 0x00532D83 LightSet_468a74_guess::SetCurrentColor_guess
    void SetCurrentColor_guess(unsigned long color_guess);
    // EXTERNAL: TITANIUM 0x0053354E LightSet_468a74_guess::AddPoint_guess
    void AddPoint_guess(float x_guess, float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x0053245B LightSet_468a74_guess::AddB_guess
    void AddB_guess(float x_guess, float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x00533455 LightSet_468a74_guess::AddC_guess
    void AddC_guess(float x_guess, float y_guess, float z_guess);
};

struct LightWnd_468a74_guess {
    /*0x000*/ unsigned char pad_000[0x15c];
    /*0x15c*/ unsigned char flag_15c_guess;
    /*0x15d*/ unsigned char pad_15d[0x1ec - 0x15d];
    /*0x1ec*/ LightSet_468a74_guess set_1ec_guess;

    // EXTERNAL: TITANIUM 0x0059DD30 LightWnd_468a74_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x00534497 LightWnd_468a74_guess::StopAutoMap_guess
    void StopAutoMap_guess();
    // EXTERNAL: TITANIUM 0x00533238 LightWnd_468a74_guess::StartAutoMap_guess
    void StartAutoMap_guess();
};
#define pinstCMapViewWnd_guess EQ_GLOBAL(LightWnd_468a74_guess*, 0x00850BFC)

// /map <command>: only with the map window open. 'color r g b' (eqstr 0x3AD1) sets the line colour,
// clamped 0..255, alpha 0xFF; eqstr 0x3AC3..0x3AC5 add a point at the player, 0x3ACD shows/hides.
// FUNCTION: TITANIUM 0x00468A74
void __cdecl do_map_guess(int unused_guess, const char* text_guess) {
    char command_guess[64];
    char blue_guess[64];
    char green_guess[64];
    char red_guess[64];
    if (pinstCMapViewWnd_guess == 0 || !pinstCMapViewWnd_guess->IsActive_guess()) {
        return;
    }
    char* textA_guess = pStringTable->getString(0x3ac3, 0);
    char* textB_guess = pStringTable->getString(0x3ac4, 0);
    char* textC_guess = pStringTable->getString(0x3ac5, 0);
    char* textD_guess = pStringTable->getString(0x3acd, 0);
    char* textColor_guess = pStringTable->getString(0x3ad1, 0);
    if (FUN_00574990_guess(text_guess, textColor_guess, FUN_00574270_guess(textColor_guess)) == 0) {
        int rest_guess = GrabFirstWord_guess(text_guess, command_guess, 0x40);
        rest_guess = GrabFirstWord_guess((const char*)rest_guess, red_guess, 0x40);
        rest_guess = GrabFirstWord_guess((const char*)rest_guess, green_guess, 0x40);
        GrabFirstWord_guess((const char*)rest_guess, blue_guess, 0x40);
        if (strlen(red_guess) <= 0 || strlen(green_guess) <= 0 || strlen(blue_guess) <= 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x3ad3, 0));
        } else {
            int red = atol(red_guess);
            int green = atol(green_guess);
            int blue = atol(blue_guess);
            if (red > 0xff) {
                red = 0xff;
            }
            if (red < 0) {
                red = 0;
            }
            if (green > 0xff) {
                green = 0xff;
            }
            if (green < 0) {
                green = 0;
            }
            if (blue > 0xff) {
                blue = 0xff;
            }
            if (blue < 0) {
                blue = 0;
            }
            pinstCMapViewWnd_guess->set_1ec_guess.SetCurrentColor_guess(
                (((red | 0xffffff00) << 8) | green) << 8 | blue);
            pEverQuest->dsp_chat(pStringTable->getString(0x3ad2, 0));
        }
    } else if (FUN_00574950_guess(text_guess, textA_guess) == 0) {
        pinstCMapViewWnd_guess->set_1ec_guess.AddPoint_guess(
            -pinstLocalPlayer->X, -pinstLocalPlayer->Y, pinstLocalPlayer->Z);
        pEverQuest->dsp_chat(pStringTable->getString(0x3aca, 0));
    } else if (FUN_00574950_guess(text_guess, textB_guess) == 0) {
        pinstCMapViewWnd_guess->set_1ec_guess.AddB_guess(
            -pinstLocalPlayer->X, -pinstLocalPlayer->Y, pinstLocalPlayer->Z);
        pEverQuest->dsp_chat(pStringTable->getString(0x3ac8, 0));
    } else if (FUN_00574950_guess(text_guess, textC_guess) == 0) {
        pinstCMapViewWnd_guess->set_1ec_guess.AddC_guess(
            -pinstLocalPlayer->X, -pinstLocalPlayer->Y, pinstLocalPlayer->Z);
        pEverQuest->dsp_chat(pStringTable->getString(0x3ac9, 0));
    } else if (FUN_00574950_guess(text_guess, textD_guess) == 0) {
        if (pinstCMapViewWnd_guess->flag_15c_guess != 0) {
            pinstCMapViewWnd_guess->StopAutoMap_guess();
            pEverQuest->dsp_chat(pStringTable->getString(0x3acc, 0));
        } else {
            pinstCMapViewWnd_guess->StartAutoMap_guess();
            pEverQuest->dsp_chat(pStringTable->getString(0x3acb, 0));
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x3ac6, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x3ac7, 0));
    }
}

// Prints the /betabuff usage in chat (dsp_chat, color 13): the syntax, the 15 class names (0x00416C2C,
// which returns them from a 10-slot ring buffer) and the allowed levels 20-65 in steps of 5.
// FUNCTION: TITANIUM 0x00468DD3
void __cdecl PrintBetaBuffUsage_guess() {
    char buffer_guess[512];
    sprintf(buffer_guess, "USAGE:  /betabuff <class-name> <level>");
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
    sprintf(buffer_guess, "\t<class-name> = %s, %s, %s, %s, %s",
            ClassName_guess(1), ClassName_guess(2),
            ClassName_guess(3), ClassName_guess(4),
            ClassName_guess(5));
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
    sprintf(buffer_guess, "\t<class-name> = %s, %s, %s, %s, %s",
            ClassName_guess(6), ClassName_guess(7),
            ClassName_guess(8), ClassName_guess(9),
            ClassName_guess(10));
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
    sprintf(buffer_guess, "\t<class-name> = %s, %s, %s, %s, %s",
            ClassName_guess(11), ClassName_guess(12),
            ClassName_guess(13), ClassName_guess(14),
            ClassName_guess(15));
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
    sprintf(buffer_guess,
            "\t<level> = 20, 25, 30, 35, 40, 45, 50, 55, 60, 65");
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
}

struct BetaStr_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00573610 BetaStr_guess::MakeLower_guess
    void MakeLower_guess();
    // EXTERNAL: TITANIUM 0x00572650 BetaStr_guess::Compare_guess
    int Compare_guess(const BetaStr_guess& other_guess) const;
};

#define pLocalPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)

// /betabuff <class> <level>: needs the test-server flag 0x923D60 and a level-1 character; a class
// matched by name 1..16, level a multiple of 5 in 20..70, then sent by 0x493F1B.
// Kept quirks: the message and usage say 20 to 65, and the index 0 branch can't be reached.
// FUNCTION: TITANIUM 0x00468F31
// @early-stop: budget, structural ndiff=38
void __cdecl do_betabuff_guess(EQPlayer* player_guess, char* text_guess) {
    if (gTestServer_guess == 0) {
        gGlobalContext_guess->SetText_guess(
            "<SERVER> This command can only be used on the Beta Test Server.",
            0xd, 1);
        return;
    }
    unsigned char levelCheck_guess = player_guess->Level;
    if (levelCheck_guess != 1) {
        gGlobalContext_guess->SetText_guess(
            "<SERVER> This command can only be used on the Beta Test Server.",
            0xd, 1);
        return;
    }
    unsigned int index_guess;
    CXStr name_guess;
    long level_guess = 0;
    char* space_guess = strrchr(text_guess, ' ');
    if (space_guess != 0) {
        *space_guess = '\0';
        level_guess = atol(space_guess + 1);
        name_guess = text_guess;
    }
    CXStr match_guess(name_guess);
    ((BetaStr_guess&)match_guess).MakeLower_guess();
    for (index_guess = 1; index_guess <= 16; index_guess++) {
        CXStr class_guess(ClassName_guess(index_guess));
        ((BetaStr_guess&)class_guess).MakeLower_guess();
        if (((BetaStr_guess&)match_guess).Compare_guess(
                (BetaStr_guess&)class_guess) != 0) {
            name_guess = ClassName_guess(index_guess);
            break;
        }
    }
    if (index_guess > 16) {
        gGlobalContext_guess->SetText_guess(
            "<SERVER> Bad class name submitted.  Unable to complete your Beta "
            "Buffing request.",
            0xd, 1);
        PrintBetaBuffUsage_guess();
    } else if (index_guess == 0) {
        gGlobalContext_guess->SetText_guess(
            "<SERVER> Bad class name submitted.  Unable to complete your Beta "
            "Buffing request.",
            0xd, 1);
        PrintBetaBuffUsage_guess();
    } else if (level_guess < 20 || level_guess > 70 ||
               level_guess % 5 != 0) {
        gGlobalContext_guess->SetText_guess(
            "<SERVER> Bad level submitted.  Please enter a level from 20 to "
            "65, divisible by 5.  Unable to complete your Beta Buffing "
            "request.",
            0xd, 1);
        PrintBetaBuffUsage_guess();
    } else {
        gGlobalContext_guess->ConfirmBuff_guess(
            pLocalPlayer_guess, &name_guess, (int)level_guess);
    }
}

struct Message_4690E4_guess {
    char text_040_guess[0x40];
    int value_040_guess;
};

// /toggletell on|off (GM): OP_GMToggle 0x7FEA, toggle at +0x40 of 0x44 bytes.
// FUNCTION: TITANIUM 0x004690E4
void __cdecl do_toggletell_guess(int unused_guess, const char* text_guess) {
    Message_4690E4_guess message_guess;
    memset(&message_guess, 0, sizeof(message_guess));
    if (FUN_00574950_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
        message_guess.value_040_guess = 1;
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3374, 0));
    } else if (FUN_00574950_guess(text_guess,
                                  gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
        message_guess.value_040_guess = 0;
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3375, 0));
    } else {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3376, 0));
        return;
    }
    SendMessage_guess(&gSendTarget_guess, OP_GMToggle, &message_guess, 0x44, 1);
}

// Command table entries: 28 bytes each.
struct CommandEntry_471028_guess {
    int id_guess;
    const char* name_guess;
    char* text_guess;
    void* handler_guess;
    int field10_guess;
    int category_guess;
    int flags_guess;
};

#define gCommandTable_471028_guess EQ_ARRAY(CommandEntry_471028_guess, 0x0078A0C8)

// EXTERNAL: TITANIUM 0x0046D38D GetCommandText_guess
const char* __cdecl GetCommandText_guess(CommandEntry_471028_guess* entry_guess);

// /help <class>: lists the slash commands of help category 1-4 or 6 (names 0x3340-0x3344) from the
// 336-entry command table; anything else prints 0x3345-0x334A.
// FUNCTION: TITANIUM 0x00471028
// @early-stop: budget, diff ndiff=1
void __cdecl do_help_guess(void* unused_guess, const char* text_guess) {
    int category_guess;
    char buffer_guess[256];
    if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3340, 0)) == 0) {
        category_guess = 1;
    } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3341, 0)) == 0) {
        category_guess = 2;
    } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3342, 0)) == 0) {
        category_guess = 3;
    } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3343, 0)) == 0) {
        category_guess = 4;
    } else if (FUN_00574950_guess(text_guess, pStringTable->getString(0x3344, 0)) == 0) {
        category_guess = 6;
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x3345, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3346, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3347, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3348, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3349, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x334a, 0), 0x111, 1);
        return;
    }
    pEverQuest->dsp_chat(pStringTable->getString(0x334b, 0), 0x111, 1);
    pEverQuest->dsp_chat(
        "--------------------------------------------------------------------------------",
        0x111, 1);
    for (CommandEntry_471028_guess* entry_guess = gCommandTable_471028_guess;
         entry_guess < gCommandTable_471028_guess + 336; entry_guess++) {
        if (entry_guess->category_guess == category_guess) {
            sprintf(buffer_guess, "  %s", GetCommandText_guess(entry_guess));
            pEverQuest->dsp_chat(buffer_guess, 0x111, 1);
        }
    }
}

struct StatePacket_471267_guess {
    char text_000_guess[0x40];
    int state_040_guess;
};

#define gStoredState_guess EQ_GLOBAL(int, 0x009247BC)

// /approval <on|off> (GM-only): OP_GMApproval (0xC0F) with your name and the state, sent only on a
// change (last value 0x9247BC). `param_1` == 0 is the silent call: no echo, always sent.
// FUNCTION: TITANIUM 0x00471267
void __cdecl do_approval_guess(int param_1, const char* param_2) {
    StatePacket_471267_guess packet_guess;
    memset(&packet_guess, 0, sizeof(packet_guess));
    if (FUN_00574950_guess(
            param_2, gTextLookup_guess->FindText_guess(0x3293, 0)) == 0) {
        packet_guess.state_040_guess = 0;
        if (param_1 != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x3351, 0));
        }
    } else if (FUN_00574950_guess(
                   param_2, gTextLookup_guess->FindText_guess(0x3292, 0)) == 0) {
        packet_guess.state_040_guess = 1;
        if (param_1 != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x3352, 0));
        }
    } else {
        if (param_1 != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x3353, 0));
        }
        return;
    }
    if ((gStoredState_guess != packet_guess.state_040_guess || param_1 == 0) &&
        g_stateHolder_guess != 0) {
        FUN_0060e450_guess(
            packet_guess.text_000_guess,
            &g_stateHolder_guess->text_044_guess[
                g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess]);
        FUN_004912b1_guess(&gSendTarget_guess, OP_GMApproval, &packet_guess, 0x44, 1);
        gStoredState_guess = packet_guess.state_040_guess;
    }
}

struct ModeRecord_47137E_guess {
    char pad_000_guess[0x119c];
    unsigned char mode_119c_guess;
};

struct ModeBase_47137E_guess {
    int field0_guess;
};

struct ModeBaseWithProfile_47137E_guess
    : ModeBase_47137E_guess, EQ_CharacterProfile_guess {
};

struct ModeRootPrefix_47137E_guess {
    int field0_guess;
    int field4_guess;
};

struct ModeRoot_47137E_guess
    : ModeRootPrefix_47137E_guess,
      virtual ModeBaseWithProfile_47137E_guess {
};

#define gModeRoot_47137E_guess EQ_GLOBAL(ModeRoot_47137E_guess*, 0x00905D00)
#define gTrackSortType_47137E_guess EQ_GLOBAL(int, 0x00923CAC)

// /tracksort <normal|distance|consider|rdistance|rconsider>: rangers (class 4) only; saved as
// [Defaults] TrackSortType and the tracking window resorted.
// FUNCTION: TITANIUM 0x0047137E
void __cdecl do_tracksort_guess(int unused_guess, char* text_guess) {
    if (gModeRoot_47137E_guess == 0) {
        return;
    }
    ModeBaseWithProfile_47137E_guess* base_guess = gModeRoot_47137E_guess;
    ModeRecord_47137E_guess* record_guess = reinterpret_cast<ModeRecord_47137E_guess*>(
        base_guess->GetCharInfo2());
    if (record_guess->mode_119c_guess == 4) {
        if (text_guess[0] == 'N' || text_guess[0] == 'n' ||
            FUN_00574950_guess(text_guess, pStringTable->getString(0x3340, 0)) == 0) {
            gTrackSortType_47137E_guess = 0;
            pEverQuest->dsp_chat(pStringTable->getString(0x335d, 0));
            FUN_0060beb0_guess("Defaults", "TrackSortType", "NORMAL",
                               ".\\eqclient.ini");
        } else if (text_guess[0] == 'D' || text_guess[0] == 'd' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3358, 0)) == 0) {
            gTrackSortType_47137E_guess = 1;
            pEverQuest->dsp_chat(pStringTable->getString(0x335e, 0));
            FUN_0060beb0_guess("Defaults", "TrackSortType", "DISTANCE",
                               ".\\eqclient.ini");
        } else if (text_guess[0] == 'C' || text_guess[0] == 'c' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3359, 0)) == 0) {
            gTrackSortType_47137E_guess = 2;
            pEverQuest->dsp_chat(pStringTable->getString(0x335f, 0));
            FUN_0060beb0_guess("Defaults", "TrackSortType", "CONSIDER",
                               ".\\eqclient.ini");
        } else if (((text_guess[0] == 'R' || text_guess[0] == 'r') &&
                    (text_guess[1] == 'D' || text_guess[1] == 'd')) ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x335a, 0)) == 0) {
            gTrackSortType_47137E_guess = 3;
            pEverQuest->dsp_chat(pStringTable->getString(0x3360, 0));
            FUN_0060beb0_guess("Defaults", "TrackSortType", "RDISTANCE",
                               ".\\eqclient.ini");
        } else if (((text_guess[0] == 'R' || text_guess[0] == 'r') &&
                    (text_guess[1] == 'C' || text_guess[1] == 'c')) ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x335b, 0)) == 0) {
            gTrackSortType_47137E_guess = 4;
            pEverQuest->dsp_chat(pStringTable->getString(0x3361, 0));
            FUN_0060beb0_guess("Defaults", "TrackSortType", "RCONSIDER",
                               ".\\eqclient.ini");
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x3362, 0));
            return;
        }
        pinstCTrackingWnd_guess->SortTrackingList_guess(1);
        return;
    }
    pEverQuest->dsp_chat(pStringTable->getString(0x3363, 0));
}

#define gPropertyHost_71607_guess EQ_GLOBAL(PropertyHost_guess*, 0x00905D00)
#define gNotifyFlagsByte_71607_guess EQ_GLOBAL(unsigned char, 0x00923CB0)
#define gNotifyFlagsWord_71607_guess EQ_GLOBAL(int, 0x00923CB0)

// /trackfilter <colour>: rangers only; toggles one consider colour in the tracking filter 0x923CB0
// (green 1, blue 2, white 4, yellow 8, red 0x10, light blue 0x20).
// FUNCTION: TITANIUM 0x00471607
// @early-stop: budget, structural ndiff=157
void __cdecl do_trackfilter_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x400];
    char token_guess[0x80];
    if (gPropertyHost_71607_guess == 0) {
        return;
    }
    PropertyOwner_guess* owner_guess =
        (PropertyOwner_guess*)&gPropertyHost_71607_guess->embedded_guess[
            gPropertyHost_71607_guess->holder_guess->vbaseOffset_0004_guess];
    if (owner_guess->locator_guess.GetCharInfo2()->mode_119c_guess == 4) {
        int messageId_guess = 0x336a;
        int flag_guess = 0;
        if (*text_guess == 'G' || *text_guess == 'g' ||
        FUN_00574950_guess(text_guess, pStringTable->getString(0x3364, 0)) == 0) {
            flag_guess = 1;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3364, 0));
        } else if (*text_guess == 'B' || *text_guess == 'b' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3365, 0)) == 0) {
            flag_guess = 2;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3365, 0));
        } else if (*text_guess == 'W' || *text_guess == 'w' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3366, 0)) == 0) {
            flag_guess = 4;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3366, 0));
        } else if (*text_guess == 'Y' || *text_guess == 'y' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3368, 0)) == 0) {
            flag_guess = 8;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3368, 0));
        } else if (*text_guess == 'R' || *text_guess == 'r' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3367, 0)) == 0) {
            flag_guess = 0x10;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3367, 0));
        } else if (*text_guess == 'L' || *text_guess == 'l' ||
                   FUN_00574950_guess(text_guess, pStringTable->getString(0x3369, 0)) == 0) {
            flag_guess = 0x20;
            FUN_0060e450_guess(token_guess, pStringTable->getString(0x3369, 0));
        }

        if (flag_guess == 0) {
            gGlobalContext_guess->dsp_chat(pStringTable->getString(0x336a, 0));
        } else {
            if ((gNotifyFlagsByte_71607_guess & flag_guess) != 0) {
                gNotifyFlagsWord_71607_guess &= ~flag_guess;
                messageId_guess = 0x336b;
            } else {
                gNotifyFlagsWord_71607_guess |= flag_guess;
                messageId_guess = 0x336c;
            }
            build_token_string_PARAM_guess(buffer_guess, messageId_guess, token_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
            gGlobalContext_guess->dsp_chat(buffer_guess);
        }
        pinstCTrackingWnd_guess->ApplyTrackingFilters_guess(1);
    } else {
        gGlobalContext_guess->dsp_chat(pStringTable->getString(0x3363, 0));
    }
}

#define gMousePointerSpeedMod_guess EQ_GLOBAL(int, 0x009237E0)
#define gMousePointerDigits_guess EQ_ARRAY(char, 0x0099DB00)

// /mousespeed <n>: [Defaults] MousePointerSpeedMod; always echoes the value (0x336F).
// FUNCTION: TITANIUM 0x00471974
void __cdecl do_mousespeed_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x100];
    if (*text_guess != '\0' && is_number_guess(text_guess) != 0) {
        gMousePointerSpeedMod_guess = atol(text_guess);
        FUN_0060beb0_guess("Defaults", "MousePointerSpeedMod", text_guess,
                           ".\\eqclient.ini");
    } else {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x336d, 0));
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x336e, 0));
    }
    build_token_string_PARAM_guess(
        buffer_guess, 0x336f,
        __itoa(gMousePointerSpeedMod_guess, gMousePointerDigits_guess, 10),
        0, 0, 0, 0, 0, 0, 0, 0);
    gGlobalContext_guess->dsp_chat(buffer_guess);
}

#define gSoundMixAhead_guess EQ_GLOBAL(int, 0x009248DC)

struct MixAhead_guess {
    // EXTERNAL: TITANIUM 0x0044A742 MixAhead_guess::SetMixAhead_guess
    void SetMixAhead_guess(int value);
    // EXTERNAL: TITANIUM 0x0044A537 MixAhead_guess::WavePlay_guess
    void WavePlay_guess(int value, int unused);
};
#define gMixAhead_guess EQ_GLOBAL(MixAhead_guess*, 0x00851390)

// /mixahead <1-100>: [Defaults] SoundMixAhead, passed to the sound manager (0x851390).
// FUNCTION: TITANIUM 0x00471A4C
void __cdecl do_mixahead_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x100];
    char number_guess[0x10];
    if (*text_guess != '\0') {
        long value_guess = atol(text_guess);
        if (value_guess >= 1 && value_guess <= 100) {
            gSoundMixAhead_guess = value_guess;
            sprintf(number_guess, "%d", value_guess);
            FUN_0060beb0_guess("Defaults", "SoundMixAhead", number_guess,
                               ".\\eqclient.ini");
            gMixAhead_guess->SetMixAhead_guess(gSoundMixAhead_guess);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x1d68, 0));
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x1d68, 0));
    }
    sprintf(number_guess, "%d", gSoundMixAhead_guess);
    build_token_string_PARAM_guess(buffer_guess, 0x1d69, number_guess, 0, 0, 0, 0,
                                   0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);
}

struct MusicPlayer_471b27_guess {
    // EXTERNAL: TITANIUM 0x004C71B6 MusicPlayer_471b27_guess::AddFile_guess
    int AddFile_guess(char* path_guess);
    // EXTERNAL: TITANIUM 0x004C705F MusicPlayer_471b27_guess::Play_guess
    void Play_guess();
    // EXTERNAL: TITANIUM 0x004C70CE MusicPlayer_471b27_guess::PlayIndex_guess
    void PlayIndex_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004C70FD MusicPlayer_471b27_guess::ClearPlaylist_guess
    void ClearPlaylist_guess();
    // EXTERNAL: TITANIUM 0x004C713C MusicPlayer_471b27_guess::RemoveTrack_guess
    void RemoveTrack_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004C66D1 MusicPlayer_471b27_guess::Pause_guess
    void Pause_guess();
    // EXTERNAL: TITANIUM 0x004C703E MusicPlayer_471b27_guess::Stop_guess
    void Stop_guess();
    // EXTERNAL: TITANIUM 0x004C7314 MusicPlayer_471b27_guess::SetShuffle_guess
    void SetShuffle_guess(int on_guess);
    // EXTERNAL: TITANIUM 0x004C5EDB MusicPlayer_471b27_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x004C5EC1 MusicPlayer_471b27_guess::GetName_guess
    char* GetName_guess(int index_guess);
};
#define gMusicPlayer_471b27_guess EQ_GLOBAL(MusicPlayer_471b27_guess**, 0x00851390)

struct MusicWnd_471b27_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual void Slot1C_guess();
    virtual void Slot20_guess();
    virtual void Slot24_guess();
    virtual void Slot28_guess();
    virtual void Slot2C_guess();
    virtual void Slot30_guess();
    virtual void Slot34_guess();
    virtual void Slot38_guess();
    virtual void Slot3C_guess();
    virtual void Slot40_guess();
    virtual void Slot44_guess();
    virtual void Slot48_guess();
    virtual void Slot4C_guess();
    virtual void Slot50_guess();
    virtual void Slot54_guess();
    virtual void Slot58_guess();
    virtual void Slot5C_guess();
    virtual void Slot60_guess();
    virtual void Slot64_guess();
    virtual void Slot68_guess();
    virtual void Slot6C_guess();
    virtual void Slot70_guess();
    virtual void Slot74_guess();
    virtual void Slot78_guess();
    virtual void Slot7C_guess();
    virtual void Slot80_guess();
    virtual void Show_guess();
};
#define gMusicWnd_471b27_guess EQ_GLOBAL(MusicWnd_471b27_guess*, 0x00850BE0)

// /mp3 <load file|play [n]|remove [n]|pause|stop|shuffle on|shuffle off|list>: the MP3 player; no
// argument opens its window. load/play/remove match as prefixes, the rest exactly.
// FUNCTION: TITANIUM 0x00471B27
// @early-stop: budget, diff ndiff=22
void __cdecl do_mp3_guess(int unused_guess, char* text_guess) {
    char line_guess[0x100];
    char buffer_guess[0x100];
    char number_guess[0x10];
    if (*gMusicPlayer_471b27_guess == 0) {
        return;
    }
    if (*text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x1d6b, 0));
        if (gMusicWnd_471b27_guess != 0) {
            gMusicWnd_471b27_guess->Show_guess();
        }
        return;
    }
    char* pause_guess;
    char* shuffleOff_guess;
    char* stop_guess;
    char* list_guess;
    char* shuffleOn_guess;
    char* szPlay_guess;
    char* szRemove_guess;
    char* load_guess;
    szRemove_guess = pStringTable->getString(0x1d71, 0);
    load_guess = pStringTable->getString(0x1d72, 0);
    szPlay_guess = pStringTable->getString(0x1d6d, 0);
    pause_guess = pStringTable->getString(0x1d6e, 0);
    list_guess = pStringTable->getString(0x1d70, 0);
    stop_guess = pStringTable->getString(0x1d6f, 0);
    shuffleOn_guess = pStringTable->getString(0x1d7b, 0);
    shuffleOff_guess = pStringTable->getString(0x1d7c, 0);
    if (FUN_00574990_guess(text_guess, load_guess, strlen(load_guess)) == 0) {
        char* arg_guess = text_guess + strlen(load_guess);
        while (*arg_guess == ' ') {
            arg_guess++;
        }
        int count_guess = (*gMusicPlayer_471b27_guess)->AddFile_guess(arg_guess);
        if (count_guess > 0) {
            sprintf(number_guess, "%d", count_guess);
            build_token_string_PARAM_guess(buffer_guess, 0x1d74, number_guess, 0, 0, 0, 0,
                                           0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x1d75, 0));
        }
    } else if (FUN_00574990_guess(text_guess, szPlay_guess, strlen(szPlay_guess)) == 0) {
        char* arg_guess = text_guess + strlen(szPlay_guess);
        while (*arg_guess == ' ') {
            arg_guess++;
        }
        if (*arg_guess == '\0') {
            (*gMusicPlayer_471b27_guess)->Play_guess();
        } else {
            (*gMusicPlayer_471b27_guess)->PlayIndex_guess(atol(arg_guess) - 1);
        }
        pEverQuest->dsp_chat(pStringTable->getString(0x1d77, 0));
    } else if (FUN_00574990_guess(text_guess, szRemove_guess, strlen(szRemove_guess)) == 0) {
        char* arg_guess = text_guess + strlen(szRemove_guess);
        while (*arg_guess == ' ') {
            arg_guess++;
        }
        if (*arg_guess == '\0') {
            (*gMusicPlayer_471b27_guess)->ClearPlaylist_guess();
            pEverQuest->dsp_chat(pStringTable->getString(0x1d7a, 0));
        } else {
            (*gMusicPlayer_471b27_guess)->RemoveTrack_guess(atol(arg_guess) - 1);
            pEverQuest->dsp_chat(pStringTable->getString(0x1d79, 0));
        }
    } else if (FUN_00574950_guess(text_guess, pause_guess) == 0) {
        (*gMusicPlayer_471b27_guess)->Pause_guess();
        pEverQuest->dsp_chat(pStringTable->getString(0x1d78, 0));
    } else if (FUN_00574950_guess(text_guess, stop_guess) == 0) {
        (*gMusicPlayer_471b27_guess)->Stop_guess();
        pEverQuest->dsp_chat(pStringTable->getString(0x1d76, 0));
    } else if (FUN_00574950_guess(text_guess, shuffleOn_guess) == 0) {
        (*gMusicPlayer_471b27_guess)->SetShuffle_guess(1);
        pEverQuest->dsp_chat(pStringTable->getString(0x1d7e, 0));
    } else if (FUN_00574950_guess(text_guess, shuffleOff_guess) == 0) {
        (*gMusicPlayer_471b27_guess)->SetShuffle_guess(0);
        pEverQuest->dsp_chat(pStringTable->getString(0x1d7d, 0));
    } else if (FUN_00574950_guess(text_guess, list_guess) == 0) {
        int count_guess = (*gMusicPlayer_471b27_guess)->GetCount_guess();
        sprintf(number_guess, "%d", count_guess);
        build_token_string_PARAM_guess(line_guess, 0x1d73, number_guess, 0, 0, 0, 0, 0, 0,
                                       0, 0);
        pEverQuest->dsp_chat(line_guess);
        for (int i_guess = 0; i_guess < count_guess; i_guess++) {
            char* name_guess = (*gMusicPlayer_471b27_guess)->GetName_guess(i_guess);
            if (name_guess != 0) {
                sprintf(line_guess, "  %d = %s", i_guess + 1, name_guess);
                pEverQuest->dsp_chat(line_guess);
            }
        }
    }
}

struct Spawn_471ed6_guess {
    char pad_000_guess[0x30];
    float x_guess; // 0x30
    float y_guess; // 0x34
    float z_guess; // 0x38
    char pad_03c_guess[0x120 - 0x3c];
    char name_120_guess[0x40];
};
IncomingMessage_guess* __cdecl GetSpawnByName_guess(const char* name_guess);
#define gTarget_471ed6_guess EQ_GLOBAL(Spawn_471ed6_guess*, 0x00905D04)

struct TargetPacket_471ed6_guess {
    char target_guess[0x40];
    char self_guess[0x58];
};

// /goto [name] (GM-only): OP_GMGoto (0x1CEE). A name is resolved to a spawn when possible and that
// spawn becomes the target (none clears it); no name uses the target and prints its location.
// FUNCTION: TITANIUM 0x00471ED6
void __cdecl do_goto_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x80];
    TargetPacket_471ed6_guess packet_guess;
    memset(&packet_guess, 0, 0x98);
    if (gConnection_guess->gm_0256_guess == 0) {
        return;
    }
    if (strcmp(text_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
        strcpy(packet_guess.target_guess, text_guess);
        Spawn_471ed6_guess* spawn_guess = (Spawn_471ed6_guess*)GetSpawnByName_guess(text_guess);
        if (spawn_guess != 0 ||
            (spawn_guess = (Spawn_471ed6_guess*)FindPlayerByPartialDisplayName_guess(text_guess, (int)gTarget_471ed6_guess)) != 0) {
            strcpy(packet_guess.target_guess, spawn_guess->name_120_guess);
        }
        strcpy(packet_guess.self_guess, gConnection_guess->text_120_guess);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GMGoto, &packet_guess, 0x98, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x3377, packet_guess.target_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
        gTarget_471ed6_guess = spawn_guess;
    } else {
        if (gTarget_471ed6_guess == 0) {
            return;
        }
        strcpy(packet_guess.target_guess, gTarget_471ed6_guess->name_120_guess);
        strcpy(packet_guess.self_guess, gConnection_guess->text_120_guess);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GMGoto, &packet_guess, 0x98, 1);
        sprintf(EQ_ARRAY(char, 0x0099DB00), "%6.2f", gTarget_471ed6_guess->x_guess);
        sprintf(EQ_ARRAY(char, 0x0099DAE0), "%6.2f", gTarget_471ed6_guess->y_guess);
        sprintf(EQ_ARRAY(char, 0x0099DF60), "%6.2f", gTarget_471ed6_guess->z_guess);
        build_token_string_PARAM_guess(buffer_guess, 0x3378, packet_guess.target_guess,
                                       EQ_ARRAY(char, 0x0099DB00), EQ_ARRAY(char, 0x0099DAE0),
                                       EQ_ARRAY(char, 0x0099DF60), 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0xd, 1);
    }
}

struct LocSource_4720bb_guess {
    char pad_000_guess[0x30];
    float x_guess; // 0x30
    float y_guess; // 0x34
    float z_guess; // 0x38
};

#define gLocXText_guess EQ_ARRAY(char, 0x0099DB00)
#define gLocYText_guess EQ_ARRAY(char, 0x0099DAE0)
#define gLocZText_guess EQ_ARRAY(char, 0x0099DF60)

// /location: 'Your Location is %1, %2, %3' (0x3379) from +0x30/+0x34/+0x38.
// FUNCTION: TITANIUM 0x004720BB
void __cdecl do_location_guess(LocSource_4720bb_guess* source_guess) {
    char buffer_guess[200];
    sprintf(gLocXText_guess, "%1.2f", source_guess->x_guess);
    sprintf(gLocYText_guess, "%1.2f", source_guess->y_guess);
    sprintf(gLocZText_guess, "%1.2f", source_guess->z_guess);
    build_token_string_PARAM_guess(buffer_guess, 0x3379, gLocXText_guess,
                                   gLocYText_guess, gLocZText_guess, 0, 0, 0, 0, 0,
                                   0);
    gGlobalContext_guess->dsp_chat(buffer_guess);
}

struct PropertyLocatorOwner_472156_guess {
    int unused_000_guess;
    PropertyLocator_guess locator_004_guess;
    PropertyData_guess* Find_guess() {
        return locator_004_guess.GetCharInfo2();
    }
};

struct PropertyAction_472156_guess : virtual PropertyLocatorOwner_472156_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x0040F8A0 PropertyAction_472156_guess::Handle_guess
    void Handle_guess(int value_guess);
};

struct PropertyState_472156_guess {
    unsigned char pad_000_guess[0x119c];
    unsigned char class_119c_guess;
};

struct CommandTarget_472156_guess {
    char pad_000_guess[0x1a8];
    ManagerData_guess* data_1a8_guess;
    char pad_1ac_guess[0x6c];
    PropertyAction_472156_guess* action_218_guess;
    // EXTERNAL: TITANIUM 0x0047E8E0 CommandTarget_472156_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x00484909 CommandTarget_472156_guess::SetValue_guess
    void SetValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004828DE CommandTarget_472156_guess::GetCount_guess
    int GetCount_guess();
};

struct CommandState_472156_guess {
    char pad_000_guess[4];
    PropertyAction_472156_guess action_004_guess;
    char pad_010_guess[0xc280 - 4 - sizeof(PropertyAction_472156_guess)];
    CommandContext_guess command_c280_guess;
};
#define gCommandState_472156_guess EQ_GLOBAL(CommandState_472156_guess*, 0x00905D00)

struct NotesWnd_4722a2_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual void Slot1C_guess();
    virtual void Slot20_guess();
    virtual void Slot24_guess();
    virtual void Slot28_guess();
    virtual void Slot2C_guess();
    virtual void Slot30_guess();
    virtual void Slot34_guess();
    virtual void Slot38_guess();
    virtual void Slot3C_guess();
    virtual void Slot40_guess();
    virtual void Slot44_guess();
    virtual void Slot48_guess();
    virtual void Slot4C_guess();
    virtual void Slot50_guess();
    virtual void Slot54_guess();
    virtual void Slot58_guess();
    virtual void Slot5C_guess();
    virtual void Slot60_guess();
    virtual void Slot64_guess();
    virtual void Slot68_guess();
    virtual void Slot6C_guess();
    virtual void Slot70_guess();
    virtual void Slot74_guess();
    virtual void Slot78_guess();
    virtual void Slot7C_guess();
    virtual void Slot80_guess();
    virtual void Toggle_84_guess();
    // EXTERNAL: TITANIUM 0x00544A29 NotesWnd_4722a2_guess::AddText_guess
    void AddText_guess(char* text_guess);
};
#define pinstCPlayerNotesWnd_guess EQ_GLOBAL(NotesWnd_4722a2_guess*, 0x00850C8C)

// /note [text]: no text toggles the notes window (0x850C8C), else appends it with link tags stripped.
// FUNCTION: TITANIUM 0x004722A2
void __cdecl do_note_guess(int unused_guess, char* text_guess) {
    if (*text_guess == 0) {
        pinstCPlayerNotesWnd_guess->Toggle_84_guess();
    } else {
        CXStr note_guess(text_guess);
        ConvertItemTags(&note_guess, 0);
        pinstCPlayerNotesWnd_guess->AddText_guess(note_guess);
    }
}

// /melody <gem> ...: bards only; while a song from the gems is playing it stops it, otherwise it
// queues the listed gem numbers and starts the first.
// FUNCTION: TITANIUM 0x00472156
// @early-stop: budget, structural ndiff=34
void __cdecl do_melody_guess(int value_guess, char* text_guess) {
    int target_guess;
    char zero_guess = 0;
    target_guess = value_guess;
    PropertyAction_472156_guess* action_guess;
    int parsed_guess;
    if (target_guess != zero_guess &&
        (action_guess = ((CommandTarget_472156_guess*)target_guess)->action_218_guess) != 0 &&
        ((PropertyState_472156_guess*)action_guess->Find_guess())->class_119c_guess == 8) {
        ((CommandTarget_472156_guess*)target_guess)->Prepare_guess();
        if (IsValidSpellIndex_guess(((CommandTarget_472156_guess*)target_guess)->data_1a8_guess->castingSpellId_0f98_guess) != zero_guess) {
            int key_guess = gKeyLookup_guess->GetKey_guess(
                gConnection_guess->pActorInfo_01a8_guess->castingSpellId_0f98_guess);
            unsigned char state_guess =
                ((PropertyState_472156_guess*)gCommandState_472156_guess->action_004_guess.Find_guess())->class_119c_guess;
            if (gCommandState_472156_guess->command_c280_guess.IsBardSong_guess(key_guess, state_guess) != zero_guess) {
                action_guess->Handle_guess(zero_guess);
            }
        } else {
            while (*text_guess != zero_guess) {
                while (*text_guess != zero_guess && isdigit((int)*text_guess) == zero_guess) {
                    ++text_guess;
                }
                if (*text_guess == zero_guess) {
                    break;
                }
                if (sscanf(text_guess, "%d", &parsed_guess) == 1) {
                    if (parsed_guess > zero_guess) {
                        ((CommandTarget_472156_guess*)target_guess)->SetValue_guess(parsed_guess);
                    }
                    while (*text_guess != zero_guess && isdigit((int)*text_guess) != zero_guess) {
                        ++text_guess;
                    }
                }
            }
            int count_guess = ((CommandTarget_472156_guess*)target_guess)->GetCount_guess();
            if (count_guess > zero_guess && count_guess < 10) {
                pinstCCastSpellWnd_guess->Select_guess(count_guess - 1);
            }
        }
    }
}

// Social 1; refused with eqstr 0x330D unless standing still (stand state 'd', speed < 0.1). See
// 0x00466DEA.
// FUNCTION: TITANIUM 0x00466E40
// @early-stop: budget, structural ndiff=5
void __cdecl social_frown_guess(int unused_guess, const char* source_guess) {
    if (gControlled_472313_guess->standState_0251_guess == 'd' &&
        _fabs(gControlled_472313_guess->speedRun_0048_guess) < 0.1) {
        DoSocial_guess((const char*)1, source_guess);
        return;
    }
    gGlobalContext_guess->dsp_chat(
        gTextLookup_guess->FindText_guess(0x330d, 0));
}

// /follow: the target must be another PC that pCharData's IsAGroupMember_guess accepts (probably a group member),
// you above z -1000 and standing; a mounted target makes your mount follow its mount.
// FUNCTION: TITANIUM 0x00472313
void __cdecl do_follow_guess(void) {
    char buffer_guess[0x100];
    Spawn_472313_guess* target_guess = gTarget_472313_guess;
    if (target_guess != 0 && target_guess->type_244_guess == 0) {
        if (target_guess == gLocal_472313_guess) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33aa, 0), 0x111, 1);
            return;
        }
        if (gCharData_46_guess->IsAGroupMember_guess(target_guess->name_120_guess) != 0) {
            if (gLocal_472313_guess->actor_1a8_guess->z_c8_guess < -1000.0f) {
                pEverQuest->dsp_chat(pStringTable->getString(0x33ab, 0), 0x111, 1);
                return;
            }
            if (gLocal_472313_guess->standState_0251_guess == 'f' || gLocal_472313_guess->linkdead_01b2_guess != 0) {
                gGlobalContext_guess->dsp_chat(pStringTable->getString(0x33ac, 0));
                return;
            }
            if (gLocal_472313_guess->standState_0251_guess != 'd') {
                pEverQuest->dsp_chat(pStringTable->getString(0x33ad, 0), 0x111, 1);
                return;
            }
            build_token_string_PARAM_guess(buffer_guess, 0x33ae, gTarget_472313_guess->GetNameText_guess(),
                                           0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0x111, 1);
            pEverQuest->dsp_chat(pStringTable->getString(0x33af, 0), 0xd, 1);
            pEverQuest->dsp_chat(pStringTable->getString(0x33b0, 0), 0xd, 1);
            if (gTarget_472313_guess->actor_1a8_guess != 0 &&
                gTarget_472313_guess->actor_1a8_guess->spawn_15c_guess != 0) {
                gControlled_472313_guess->actor_1a8_guess->spawn_fe8_guess =
                    gTarget_472313_guess->actor_1a8_guess->spawn_15c_guess;
                gLocal_472313_guess->actor_1a8_guess->spawn_fe8_guess = gTarget_472313_guess;
            } else {
                gLocal_472313_guess->actor_1a8_guess->spawn_fe8_guess = gTarget_472313_guess;
            }
            return;
        }
    }
    pEverQuest->dsp_chat(pStringTable->getString(0x33a9, 0), 0x111, 1);
}

struct AnonymousState_4724fc_guess {
    char pad_000_guess[0x120];
    char data_120_guess[0x124];
    unsigned char blocked_244_guess;
    char pad_245_guess[0x11];
    unsigned char redirect_256_guess;
    char pad_257_guess;
    unsigned short value_258_guess;
    char pad_25a_guess[0xa];
    union {
        unsigned char flags_264_guess;
        int anonymous_264_guess;
    } state_264_guess;
    // EXTERNAL: TITANIUM 0x0047D776 AnonymousState_4724fc_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
};

struct AnonymousPacket_4724fc_guess {
    unsigned short spawnId_0000_guess;
    unsigned short type_guess;
    int state_guess;
};

struct AnonymousSettings_4724fc_guess {
    char pad_000_guess[0xe24];
    unsigned char anonymous_e24_guess;
};

#define gAnonymousPlayer_4724fc_guess EQ_GLOBAL(AnonymousState_4724fc_guess*, 0x00905CE4)
#define gAnonymousSettings_4724fc_guess EQ_GLOBAL(AnonymousSettings_4724fc_guess*, 0x00905D00)
#define gAnonymousMode_4724fc_guess EQ_GLOBAL(int, 0x00923D58)
#define gAnonymousMenu_4724fc_guess EQ_GLOBAL(int, 0x00923D94)
#define gAnonymousStatus_4724fc_guess EQ_GLOBAL(int, 0x00924954)

// /anonymous [on|off]: no argument toggles. Acts on yourself unless you are a GM (+0x256) acting on
// another spawn; sends OP_SpawnAppearance (0x7C32, type 0x15) and saves [Options] Anonymous.
// FUNCTION: TITANIUM 0x004724FC
void __cdecl do_anonymous_guess(AnonymousState_4724fc_guess* state_guess,
                          const char* text_guess) {
    AnonymousPacket_4724fc_guess packet_guess;
    char buffer_guess[256];

    if (state_guess == 0 || state_guess->blocked_244_guess != 0) {
        return;
    }
    if (state_guess != gAnonymousPlayer_4724fc_guess &&
        gAnonymousPlayer_4724fc_guess->redirect_256_guess == 0) {
        state_guess = gAnonymousPlayer_4724fc_guess;
    }
    if ((state_guess->state_264_guess.flags_264_guess & 2) != 0) {
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33b3, 0), 0x111, 1);
        return;
    }
    if (gAnonymousMode_4724fc_guess == 6) {
        return;
    }

    if (FUN_00574990_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x3292, 0), 3) != 0) {
        char desiredState_guess = 1;
        if (FUN_00574990_guess(text_guess,
                               gTextLookup_guess->FindText_guess(0x3293, 0), 2) != 0) {
            desiredState_guess = (char)(
                state_guess->state_264_guess.anonymous_264_guess == 0);
        }
        if (desiredState_guess == 0) {
            state_guess->state_264_guess.anonymous_264_guess = 0;
        } else {
            state_guess->state_264_guess.anonymous_264_guess = 1;
        }
    } else {
        state_guess->state_264_guess.anonymous_264_guess = 0;
    }

    if (state_guess->state_264_guess.anonymous_264_guess != 0) {
        if (state_guess == gAnonymousPlayer_4724fc_guess) {
            sprintf(buffer_guess, gTextLookup_guess->FindText_guess(0x33b4, 0));
        } else {
            build_token_string_PARAM_guess(
                buffer_guess, 0x33b6,
                gGlobalContext_guess->trimName_guess(state_guess->data_120_guess),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (state_guess == gAnonymousPlayer_4724fc_guess) {
            sprintf(buffer_guess, gTextLookup_guess->FindText_guess(0x33b5, 0));
        } else {
            build_token_string_PARAM_guess(
                buffer_guess, 0x33b7,
                gGlobalContext_guess->trimName_guess(state_guess->data_120_guess),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
    }

    gGlobalContext_guess->SetText_guess(buffer_guess, 0x111, 1);
    packet_guess.type_guess = 0x15;
    packet_guess.spawnId_0000_guess = state_guess->value_258_guess;
    packet_guess.state_guess = state_guess->state_264_guess.anonymous_264_guess;
    FUN_004912b1_guess(EQ_ARRAY(int, 0x00905CA0), OP_SpawnAppearance, &packet_guess, 8, 1);
    if (state_guess == gAnonymousPlayer_4724fc_guess) {
        gAnonymousSettings_4724fc_guess->anonymous_e24_guess =
            gAnonymousPlayer_4724fc_guess->state_264_guess.flags_264_guess;
        gAnonymousMenu_4724fc_guess = 5;
        gGlobalContext_guess->SavePC_guess(0, 1, 0xb);
        gAnonymousStatus_4724fc_guess =
            gAnonymousPlayer_4724fc_guess->state_264_guess.anonymous_264_guess;
        gGlobalContext_guess->WriteInt_guess(
            gAnonymousStatus_4724fc_guess, "Options", "Anonymous");
    }
    state_guess->RefreshNameSprite_guess();
}

#define gDueling_guess EQ_GLOBAL(char, 0x009238E0)
#define gDuelOpponentId_guess EQ_GLOBAL(int, 0x009238D8)
#define gDuelChallengerId_guess EQ_GLOBAL(int, 0x009238DC)

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
EQPlayer* __cdecl FUN_00401b28_guess(unsigned int spawn_id_guess);

struct SpawnNamePacket_47297a_guess {
    unsigned int source_id_guess;
    unsigned int target_id_guess;
    unsigned char value_guess;
};

// /decline: refuses the pending duel challenge (0x9238DC) with opcode 0x3EA0 (not in
// patch_Titanium.conf); refused while already dueling (0x9238E0). gHeld*_guess are the duel state.
// FUNCTION: TITANIUM 0x0047297A
// @early-stop: budget, diff ndiff=10
void __cdecl do_decline_guess(void) {
    SpawnNamePacket_47297a_guess packet_guess;
    char buffer_guess[128];
    if (gDueling_guess != 0) {
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33bd, 0), 0xf, 1);
    } else {
        if (gDuelChallengerId_guess != 0) {
            EQPlayer* spawn_guess = FUN_00401b28_guess(gDuelChallengerId_guess);
            if (spawn_guess != 0) {
                build_token_string_PARAM_guess(buffer_guess, 0x33be, spawn_guess->Name,
                                               0, 0, 0, 0, 0, 0, 0, 0);
                gGlobalContext_guess->SetText_guess(buffer_guess, 0x111, 1);
                packet_guess.source_id_guess = spawn_guess->SpawnID;
                packet_guess.target_id_guess = pinstLocalPlayer->SpawnID;
                packet_guess.value_guess = 0;
                FUN_004912b1_guess(&gSendTarget_guess, 0x3ea0, &packet_guess, 0xc, 1);
            }
            gDuelChallengerId_guess = 0;
            return;
        }
        gGlobalContext_guess->SetText_guess(
            gTextLookup_guess->FindText_guess(0x33bf, 0), 0x111, 1);
    }
}

// /duel: challenges the target PC (OP_RequestDuel 0x28E1), or accepts its challenge (0x28E1 then
// OP_DuelAccept 0x1B09). gIncomingMessage_guess is the target (0x905D04) and gConnection_guess the
// local player (0x905CE4), both misnamed.
// FUNCTION: TITANIUM 0x00472A67
// @early-stop: budget, structural ndiff=15
void __cdecl do_duel_guess(void) {
    Payload_guess payload_guess;
    char buffer_guess[128];
    if (gIncomingMessage_guess == 0 || gIncomingMessage_guess->byte_244_guess != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x33c0, 0), 0x111, 1);
    } else if (gIncomingMessage_guess == (IncomingMessage_guess*)gConnection_guess) {
        pEverQuest->dsp_chat(pStringTable->getString(0x33c1, 0), 0x111, 1);
    } else if (gDueling_guess != 0) {
        if (gDuelOpponentId_guess == gIncomingMessage_guess->value_258_guess) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33c2, 0), 0xf, 1);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x33c3, 0), 0xf, 1);
        }
    } else {
        if (gDuelChallengerId_guess == gIncomingMessage_guess->value_258_guess) {
            gDueling_guess = 1;
            gDuelOpponentId_guess = gIncomingMessage_guess->value_258_guess;
            build_token_string_PARAM_guess(buffer_guess, 0x33c4, gIncomingMessage_guess->text_120_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0xf, 1);
            payload_guess.spawnId_0000_guess = gIncomingMessage_guess->value_258_guess;
            payload_guess.message = gConnection_guess->spawnId_0258_guess;
            EQSendMessage(&gSendTarget_guess, OP_RequestDuel, &payload_guess, 8, 1);
            EQSendMessage(&gSendTarget_guess, OP_DuelAccept, &payload_guess, 8, 1);
        } else if (gDuelChallengerId_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33c5, 0), 0xf, 1);
        } else {
            gDuelOpponentId_guess = gIncomingMessage_guess->value_258_guess;
            build_token_string_PARAM_guess(buffer_guess, 0x33c6, gIncomingMessage_guess->text_120_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0xf, 1);
            payload_guess.spawnId_0000_guess = gIncomingMessage_guess->value_258_guess;
            payload_guess.message = gConnection_guess->spawnId_0258_guess;
            EQSendMessage(&gSendTarget_guess, OP_RequestDuel, &payload_guess, 8, 1);
        }
    }
}

struct DisplayState_guess {
    char pad_000_guess[0x22c];
    int mode_22c_guess; // 0x22C
};
#define gDisplayState_guess EQ_GLOBAL(DisplayState_guess*, 0x009917E4)
#define gDebugFlag_guess EQ_GLOBAL(int, 0x00924788)

// EXTERNAL: TITANIUM 0x00491125 eqlog_guess
void __cdecl eqlog_guess(const char* message_guess);

struct DisplayMode_guess {
    char pad_000_guess[0x218];
    int mode_218_guess;
};
#define gDisplayMode_guess EQ_GLOBAL(DisplayMode_guess*, 0x009917E4)

struct DisplayMode21c_guess {
    char pad_000_guess[0x21c];
    int mode_21c_guess;
};
#define gDisplayMode21c_guess EQ_GLOBAL(DisplayMode21c_guess*, 0x009917E4)

struct DisplayMode224_guess {
    char pad_000_guess[0x224];
    int mode_224_guess;
};
#define gDisplayMode224_guess EQ_GLOBAL(DisplayMode224_guess*, 0x009917E4)

// You miss other: option +0x21C, brief 0x3ABF, colour 0x10B.
// FUNCTION: TITANIUM 0x00473AE4
void __cdecl ShowYouMissOtherMessage_guess(char* text_guess, int unused_guess, const char* arg3_guess) {
    char buffer_guess[256];

    switch (gDisplayMode21c_guess->mode_21c_guess) {
    case 0:
        gGlobalContext_guess->SetText_guess(text_guess, 0x10b, 0);
        break;
    case 1:
        build_token_string_PARAM_guess(buffer_guess, 0x3abf, arg3_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0x10b, 0);
        break;
    case 2:
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2f7c, 0), 0x10b, 0);
        break;
    }
    if (gDebugFlag_guess == 1) {
        eqlog_guess(text_guess);
    }
}

// Other misses you: option +0x224, brief 0x3AC0, colour 0x10C.
// FUNCTION: TITANIUM 0x00473B85
void __cdecl ShowOtherMissesYouMessage_guess(char* text_guess, int unused_guess, int unused3_guess,
                                const char* arg4_guess) {
    char buffer_guess[256];

    switch (gDisplayMode224_guess->mode_224_guess) {
    case 0:
        gGlobalContext_guess->SetText_guess(text_guess, 0x10c, 0);
        break;
    case 1:
        build_token_string_PARAM_guess(buffer_guess, 0x3ac0, arg4_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0x10c, 0);
        break;
    case 2:
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x2f7c, 0), 0x10c, 0);
        break;
    }
    if (gDebugFlag_guess == 1) {
        eqlog_guess(text_guess);
    }
}

struct Item_473216_guess {
    char pad_000_guess[0x10];
    int name_010_guess;
    int lore_014_guess;
    char pad_018_guess[4];
    int cost_01c_guess;
    int id_020_guess;
    // EXTERNAL: TITANIUM 0x0044791F Item_473216_guess::CanClassUse_guess
    bool CanClassUse_guess(unsigned char mode_guess);
};

struct Entry_473216_guess {
    int id_000_guess;
    char pad_004_guess[0x30];
    int key_034_guess;
};

struct ItemDb_473216_guess {
    // EXTERNAL: TITANIUM 0x00447D07 ItemDb_473216_guess::GetAltAbility
    Item_473216_guess* GetAltAbility(int index_guess);
    // EXTERNAL: TITANIUM 0x00447D1F ItemDb_473216_guess::Find_guess
    Entry_473216_guess* Find_guess(void* character_guess, int id_guess);
    // EXTERNAL: TITANIUM 0x00448122 ItemDb_473216_guess::Check_guess
    bool Check_guess(void* character_guess, Item_473216_guess* item_guess, int flags_guess);
};
#define gItemDb_473216_guess EQ_GLOBAL(ItemDb_473216_guess*, 0x008511D8)

struct DbStrings_473216_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DbStrings_473216_guess::GetString_guess
    char* GetString_guess(int index_guess, int category_guess, int flags_guess);
};
#define gDbStrings_473216_guess EQ_GLOBAL(DbStrings_473216_guess*, 0x00850398)

struct KeyInfo_473216_guess {
    char pad_000_guess[0x1fc];
    char flag_1fc_guess;
};

struct KeyLookup_473216_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 KeyLookup_473216_guess::GetKey_guess
    KeyInfo_473216_guess* GetKey_guess(int value_guess);
};
#define gKeyLookup_473216_guess EQ_GLOBAL(KeyLookup_473216_guess*, 0x00985CC8)

struct Player_473216_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x00483556 Player_473216_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
};
#define gLocalPlayer_473216_guess EQ_GLOBAL(Player_473216_guess*, 0x00905CE4)
#define gFlag_473216_guess EQ_GLOBAL(char, 0x009254F7)
#define gDigits_473216_guess EQ_ARRAY(char, 0x0099DB00)

struct PcPrefix_473216_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct CharBase_473216_guess {
    void* vftable_guess;
    PropertyLocator_guess locator_guess;
    PropertyData_guess* GetInfo_guess() { return locator_guess.GetCharInfo2(); }
};

struct PcView_473216_guess : PcPrefix_473216_guess, virtual CharBase_473216_guess {
    char pad_00C_guess[0xE2D - 0x0C];
    unsigned char flag_e2d_guess;
    char pad_e2e_guess[0xC384 - 0xE2E];
};
#define gPcView_473216_guess EQ_GLOBAL(PcView_473216_guess*, 0x00905D00)

struct Packet_473216_guess {
    int type_guess;
    int id_guess;
    int target_guess;
    int value_guess;
};

// /alternateadv <on [pct]|off|list|buy <id>|act <id>>: OP_AAAction (0x681) with action 1 (AA
// experience on, at pct), 2 (off), 3 (buy) or 0 (activate, at the target); 'list' prints every
// ability your class can buy.
// FUNCTION: TITANIUM 0x00473216
void __cdecl do_alternateadv_guess(int unused_guess, char* line_guess) {
    char command_guess[0x40];
    char argument_guess[0x40];
    char number_guess[20];
    char buffer_guess[0x200];
    Packet_473216_guess packet_guess;

    int rest_guess = GrabFirstWord_guess(line_guess, command_guess, 0x40);
    GrabFirstWord_guess((const char*)rest_guess, argument_guess, 0x40);
    memset(&packet_guess, 0, sizeof(packet_guess));
    if (FUN_00574990_guess(command_guess, pStringTable->getString(0x3293, 0), 2) == 0) {
        gPcView_473216_guess->flag_e2d_guess = 1;
        packet_guess.type_guess = 1;
        packet_guess.value_guess = atol(argument_guess);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AAAction, &packet_guess, 0x10, 1);
        return;
    }
    if (FUN_00574990_guess(command_guess, pStringTable->getString(0x3292, 0), 3) == 0) {
        gPcView_473216_guess->flag_e2d_guess = 0;
        packet_guess.type_guess = 2;
    } else if (FUN_00574990_guess(command_guess, pStringTable->getString(0x33d7, 0), 4) == 0) {
        for (int i_guess = 0; i_guess < 10000; i_guess++) {
            Item_473216_guess* item_guess = gItemDb_473216_guess->GetAltAbility(i_guess);
            if (item_guess != 0 &&
                item_guess->CanClassUse_guess(gPcView_473216_guess->GetInfo_guess()->mode_119c_guess)) {
                __itoa(item_guess->id_020_guess, number_guess, 10);
                int name_guess = item_guess->name_010_guess;
                build_token_string_PARAM_guess(
                    buffer_guess, 0x33da, number_guess,
                    gDbStrings_473216_guess->GetString_guess(name_guess, 1, 0),
                    0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buffer_guess);
                int lore_guess = item_guess->lore_014_guess;
                build_token_string_PARAM_guess(
                    buffer_guess, 0x33db,
                    gDbStrings_473216_guess->GetString_guess(lore_guess, 4, 0),
                    0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buffer_guess);
                int cost_guess = item_guess->cost_01c_guess;
                build_token_string_PARAM_guess(
                    buffer_guess, 0x33dc, __itoa(cost_guess, gDigits_473216_guess, 10),
                    0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buffer_guess);
            }
        }
        return;
    } else if (FUN_00574990_guess(command_guess, pStringTable->getString(0x33d8, 0), 3) == 0) {
        packet_guess.type_guess = 3;
        packet_guess.id_guess = atol(argument_guess);
        Item_473216_guess* item_guess = gItemDb_473216_guess->GetAltAbility(packet_guess.id_guess);
        if (item_guess == 0 || !gItemDb_473216_guess->Check_guess(pCharData, item_guess, 0)) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33dd, 0), 0xd, true);
            return;
        }
    } else if (FUN_00574990_guess(command_guess, pStringTable->getString(0x33d9, 0), 3) == 0) {
        Entry_473216_guess* entry_guess = gItemDb_473216_guess->Find_guess(pCharData, atol(argument_guess));
        if (entry_guess != 0) {
            KeyInfo_473216_guess* key_guess = gKeyLookup_473216_guess->GetKey_guess(entry_guess->key_034_guess);
            if ((key_guess == 0 || key_guess->flag_1fc_guess == 0) &&
                gLocalPlayer_473216_guess->StandState == 'n' && gFlag_473216_guess != 0) {
                gLocalPlayer_473216_guess->ChangePosition_guess(100);
            }
            packet_guess.type_guess = 0;
            packet_guess.id_guess = entry_guess->id_000_guess;
            if (pinstTarget != 0) {
                packet_guess.target_guess = pinstTarget->SpawnID;
            }
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x1836, 0), 0xd, true);
            return;
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x1a2, 0), 10, true);
        return;
    }
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AAAction, &packet_guess, 0x10, 1);
}

// /hotbutton <name> [colour] <text>: makes a hot button; a numeric second word is the colour,
// otherwise part of the text. 0x33E2 on success, 0x33E3 when it fails.
// FUNCTION: TITANIUM 0x004735CC
// @early-stop: budget, diff ndiff=22
void __cdecl do_hotbutton_guess(int unused_guess, char* input_guess) {
    int step_guess;
    char* rest_guess;
    long value_guess = 0;
    CXStr text_guess(input_guess);
    char buffer_guess[0x100];
    char first_guess[0x40];
    char second_guess[0x40];

    ConvertItemTags(&text_guess, 0);
    char* chars_guess = text_guess;
    rest_guess = (char*)GrabFirstWord_guess(chars_guess, first_guess, 0x40);
    input_guess = (char*)GrabFirstWord_guess(rest_guess, second_guess, 0x40);
    if (first_guess[0] == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x33de, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x33df, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x33e0, 0));
        pEverQuest->dsp_chat(pStringTable->getString(0x33e1, 0));
    } else {
        bool valid_guess = true;
        int total_guess = 0;
        while (second_guess[total_guess] != '\0') {
            if (FUN_00574830_guess(second_guess + total_guess, &step_guess) == 0) {
                valid_guess = false;
                break;
            }
            total_guess += step_guess;
        }
        if (valid_guess) {
            FUN_0060e450_guess(buffer_guess, input_guess);
            value_guess = atoi(second_guess);
        } else {
            FUN_0060e450_guess(buffer_guess, rest_guess);
        }
        if (SetSocial_guess(first_guess, buffer_guess, value_guess, -1) >= 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33e2, 0));
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x33e3, 0));
        }
    }
}

struct RaceText_472c5e_guess {
    // EXTERNAL: TITANIUM 0x0049273D RaceText_472c5e_guess::GetRaceDesc
    const char* GetRaceDesc(int race_guess);
};
#define gRaceText_472c5e_guess EQ_GLOBAL(RaceText_472c5e_guess*, 0x00988DF0)
#define gNpcFlag_472c5e_guess EQ_GLOBAL(char, 0x00923798)
#define gNpcMode_472c5e_guess EQ_GLOBAL(int, 0x00923884)

void __cdecl do_height_guess(int unused_guess, const char* text_guess);

struct ActorInfo_472c5e_guess {
    char pad_000_guess[0x1040];
    long level_max_1040_guess;
};

struct BecomeNpcPacket_472c5e_guess {
    unsigned int spawn_id_guess;
    char name_guess[0x40];
    long race_guess;
    unsigned char gender_guess;
    unsigned char texture_guess;
    unsigned char helm_guess;
    unsigned char pad_4b_guess;
    long face_guess;
    unsigned char tint_50_guess;
    unsigned char tint_51_guess;
    unsigned char tint_52_guess;
    unsigned char tint_53_guess;
    float size_guess;
    char pad_58_guess[0x48];
    int value_a0_guess;
    int value_a4_guess;
};

struct LevelPacket_472c5e_guess {
    unsigned int spawn_id_guess;
    long level_guess;
};

// /becomenpc <race#> [sex] [material#] [head#] [face#] [height] [level max] (GM-only): changes the
// target PC with OP_Illusion (0x448D), then OP_GMBecomeNPC (0x7864) with the level cap (70 default).
// FUNCTION: TITANIUM 0x00472C5E
// @early-stop: budget, structural ndiff=47
void __cdecl do_becomenpc_guess(int unused_guess, char* text_guess) {
    LevelPacket_472c5e_guess level_packet_guess;
    char buffer_guess[0x200];
    char race_text_guess[0x40];
    char gender_text_guess[0x40];
    char texture_text_guess[0x40];
    char helm_text_guess[0x40];
    char face_text_guess[0x40];
    char height_text_guess[0x40];
    char level_text_guess[0x40];
    char name_guess[0x40];
    BecomeNpcPacket_472c5e_guess packet_guess;
    long race_guess;
    long face_guess = -1;
    unsigned char texture_guess = 0xff;
    unsigned char helm_guess = 0xff;
    unsigned char gender_guess = 2;

    if (gNpcFlag_472c5e_guess == 0 && gNpcMode_472c5e_guess == 0) {
    if (*text_guess == '\0') {
        pEverQuest->dsp_chat("FORMAT: /becomenpc <race#> [sex (M, F, N, N is default)] [material#] [head#] [face#] [height] [level max]");
        pEverQuest->dsp_chat("level max is the highest level character that can attack you, and the highest level character that you can attack (70 is default).");
    } else if (pinstTarget == 0) {
        pEverQuest->dsp_chat("You must first select a target to change.", 0xd, true);
    } else {
    strcpy(name_guess, pinstTarget->Name);
    char* last_guess = FUN_00574700_guess(name_guess + strlen(name_guess) - 1);
    if (pinstTarget->Type != 0 && FUN_00574830_guess(last_guess, 0) != 0) {
        pEverQuest->dsp_chat("You can only change PCs.", 0xd, true);
    } else {
    int rest_guess = GrabFirstWord_guess(text_guess, race_text_guess, 0x40);
    rest_guess = GrabFirstWord_guess((const char*)rest_guess, gender_text_guess, 0x40);
    rest_guess = GrabFirstWord_guess((const char*)rest_guess, texture_text_guess, 0x40);
    rest_guess = GrabFirstWord_guess((const char*)rest_guess, helm_text_guess, 0x40);
    rest_guess = GrabFirstWord_guess((const char*)rest_guess, face_text_guess, 0x40);
    rest_guess = GrabFirstWord_guess((const char*)rest_guess, height_text_guess, 0x40);
    GrabFirstWord_guess((const char*)rest_guess, level_text_guess, 0x40);
    race_guess = atol(race_text_guess);
    if (gender_text_guess[0] != '\0') {
        if (__strnicmp(gender_text_guess, "M", 1) == 0) {
            gender_guess = 0;
        } else if (__strnicmp(gender_text_guess, "F", 1) == 0) {
            gender_guess = 1;
        }
    }
    if (texture_text_guess[0] != '\0') {
        texture_guess = (unsigned char)atol(texture_text_guess);
    }
    if (helm_text_guess[0] != '\0') {
        helm_guess = (unsigned char)atol(helm_text_guess);
    }
    if (face_text_guess[0] != '\0') {
        face_guess = atol(face_text_guess);
    }
    packet_guess.spawn_id_guess = pinstTarget->SpawnID;
    strcpy(packet_guess.name_guess, pinstTarget->Name);
    packet_guess.value_a0_guess = -1;
    packet_guess.value_a4_guess = 0;
    packet_guess.gender_guess = gender_guess;
    packet_guess.texture_guess = texture_guess;
    packet_guess.helm_guess = helm_guess;
    packet_guess.face_guess = face_guess;
    packet_guess.race_guess = race_guess;
    packet_guess.tint_52_guess = 0xff;
    packet_guess.tint_53_guess = 0xff;
    packet_guess.tint_50_guess = 0xff;
    packet_guess.tint_51_guess = 0xff;
    packet_guess.size_guess = -1.0f;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Illusion, &packet_guess, 0xa8, 1);
    sprintf(buffer_guess, "Changing %s to race: %s.", pinstTarget->Name,
            gRaceText_472c5e_guess->GetRaceDesc(race_guess));
    pEverQuest->dsp_chat(buffer_guess, 0x111, true);
    if (height_text_guess[0] != '\0') {
        do_height_guess((int)pinstTarget, height_text_guess);
    }
    if (level_text_guess[0] != '\0') {
        level_packet_guess.level_guess = atol(level_text_guess);
    } else {
        level_packet_guess.level_guess = 70;
    }
    ((ActorInfo_472c5e_guess*)pinstTarget->pActorInfo)->level_max_1040_guess =
        level_packet_guess.level_guess;
    level_packet_guess.spawn_id_guess = pinstTarget->SpawnID;
    sprintf(buffer_guess, "%s is now able to kill anyone (or be killed) as if they were an NPC.",
            pinstTarget->Name);
    pEverQuest->dsp_chat(buffer_guess, 0x111, true);
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GMBecomeNPC, &level_packet_guess, 8, 1);
    }
    }
    }
}

// Virtual base of pCharData (0x00905D00) at +0xC384; the status lookup is a member of it.
struct StatusBase_47377A_guess {
    // EXTERNAL: TITANIUM 0x004167E2 StatusBase_47377A_guess::GetStatus_guess
    int GetStatus_guess();
};

struct PcPrefix_47377A_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct PcStatusView_47377A_guess : PcPrefix_47377A_guess, virtual StatusBase_47377A_guess {
    char pad_0C_guess[0xC384 - 0x0C];
};
#define gStatusChar_47377A_guess EQ_GLOBAL(PcStatusView_47377A_guess*, 0x00905D00)
#define pTargetPlayer_47377A_guess EQ_GLOBAL(EQPlayer*, 0x00905D04)
#define gActionFlag_47377A_guess EQ_GLOBAL(int, 0x00923D60)

struct Char1_4730a8_guess {
    // EXTERNAL: TITANIUM 0x00417DAF Char1_4730a8_guess::IsReady_guess
    int IsReady_guess();
};

struct PcView_4730a8_guess : PcPrefix_47377A_guess, virtual StatusBase_47377A_guess {
    char pad_0C_guess[0xC280 - 0x0C];
    Char1_4730a8_guess char1_C280_guess;
    char pad_C281_guess[0xC384 - 0xC281];
};
#define gPcView_4730a8_guess EQ_GLOBAL(PcView_4730a8_guess*, 0x00905D00)

struct BookWnd_4730a8_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Show_guess();
    virtual void Hide_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 BookWnd_4730a8_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x00558361 BookWnd_4730a8_guess::SetPage_guess
    void SetPage_guess(int page_guess);
};
#define gBookWnd_4730a8_guess EQ_GLOBAL(BookWnd_4730a8_guess*, 0x00850C30)

struct Controlled_4730a8_guess {
    char pad_000_guess[0x48];
    float speed_048_guess;
};
#define gControlled_4730a8_guess EQ_GLOBAL(Controlled_4730a8_guess*, 0x00905CF8)
#define gLocalPlayer_4730a8_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)

// /book [page|close]: opens the spell book (0x850C30) at the even page before `page`; not while
// moving (0x2F35). The second _stricmp result is never used (kept).
// FUNCTION: TITANIUM 0x004730A8
void __cdecl do_book_guess(int unused_guess, char* text_guess) {
    if (allowslashcommand_guess() == 0) {
        return;
    }
    if (gPcView_4730a8_guess->GetStatus_guess() != 0) {
        return;
    }
    if (gBookWnd_4730a8_guess->IsActive_guess() && *text_guess == '\0') {
        gBookWnd_4730a8_guess->Hide_guess();
        return;
    }
    if (strlen(text_guess) > 0) {
        if (_stricmp(text_guess, pStringTable->getString(0x22b3, 0)) == 0) {
            if (gBookWnd_4730a8_guess->IsActive_guess()) {
                gBookWnd_4730a8_guess->Hide_guess();
            }
            return;
        }
        _stricmp(text_guess, pStringTable->getString(0x22b2, 0));
    }
    if (gPcView_4730a8_guess->char1_C280_guess.IsReady_guess() == 0) {
        return;
    }
    if (gControlled_4730a8_guess != 0 && gControlled_4730a8_guess->speed_048_guess > 0.01f) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2f35, 0));
        return;
    }
    if (gLocalPlayer_4730a8_guess->StandState == 'i') {
        return;
    }
    if (!gBookWnd_4730a8_guess->IsActive_guess()) {
        gBookWnd_4730a8_guess->Show_guess();
    }
    if (strlen(text_guess) > 0) {
        int page_guess = atol(text_guess) - 1;
        if (page_guess < 1) {
            page_guess = 0;
        } else if (page_guess % 2 != 0) {
            page_guess--;
        }
        gBookWnd_4730a8_guess->SetPage_guess(page_guess);
    }
}

struct CommandName_472fd0_guess {
    char text_000_guess[0x19];
    char active_019_guess;
    char pad_01a_guess[0x26];
};

struct CommandEntry_472fd0_guess {
    char pad_000_guess[0x24];
    char text_024_guess[0x19];
    char active_03d_guess;
    char pad_03e_guess[2];
};

struct CommandSelection_472fd0_guess {
    // EXTERNAL: TITANIUM 0x00557CD8 CommandSelection_472fd0_guess::Select_guess
    void Select_guess(CommandEntry_472fd0_guess* entry_guess, int value_guess);
};

#define pSpellBookWnd_guess EQ_GLOBAL(CommandSelection_472fd0_guess*, 0x00850C30)

// /memspellset <n|name>: loads one of the 10 saved spell sets (0x984828, 0x40 bytes each) through
// the spell book window; otherwise prints 0xD0E. pSpellBookWnd_guess is that window.
// FUNCTION: TITANIUM 0x00472FD0
// @early-stop: budget, structural ndiff=35
void __cdecl do_memspellset_guess(int unused_guess, char* text_guess) {
    if (allowslashcommand_guess() == 0) {
        return;
    }
    if (gStatusChar_47377A_guess->GetStatus_guess() != 0) {
        return;
    }

    if (text_guess != 0 && *text_guess != '\0') {
        int selection_guess;
        int found_guess = 0;
        if (is_number_guess(text_guess) != 0) {
            selection_guess = (int)atol(text_guess) - 1;
            if (selection_guess >= 0 && selection_guess < 10 &&
                EQ_ARRAY(CommandName_472fd0_guess, 0x00984828)[selection_guess]
                        .active_019_guess != '\0') {
                found_guess = 1;
            }
        } else {
            int index_guess = 0;
            CommandName_472fd0_guess* name_guess =
                EQ_ARRAY(CommandName_472fd0_guess, 0x00984828);
            CommandName_472fd0_guess* end_guess =
                EQ_ARRAY(CommandName_472fd0_guess, 0x00984AA8);
            do {
                if (name_guess->active_019_guess != '\0' &&
                    __strnicmp(text_guess, name_guess->text_000_guess,
                               strlen(text_guess)) == 0) {
                    selection_guess = index_guess;
                    found_guess = 1;
                    break;
                }
                ++name_guess;
                ++index_guess;
            } while (name_guess < end_guess);
        }

        if (found_guess != 0) {
            if (pSpellBookWnd_guess != 0 && selection_guess >= 0) {
                pSpellBookWnd_guess->Select_guess(
                    &EQ_ARRAY(CommandEntry_472fd0_guess, 0x00984804)[selection_guess], 9);
            }
            return;
        }
    }

    gGlobalContext_guess->Show_guess(
        gTextLookup_guess->FindTextTyped_guess(0xD0E, 0, 0x108, 1));
}

struct Packet_47377A_guess {
    char first_guess[0x40];
    char second_guess[0x40];
    int type_guess;
    int pad_guess;
};

// /spellscribe: opcode 0x425C (not in patch_Titanium.conf), type 4. Both names are overwritten
// with your own and the two numeric arguments are parsed and dropped (probably debug leftovers).
// FUNCTION: TITANIUM 0x0047377A
// @early-stop: budget, structural ndiff=7
void __cdecl do_spellscribe_guess(EQPlayer* player_guess, const char* text_guess) {
    char token1_guess[0x40];
    char token2_guess[0x40];
    char token3_guess[0x40];
    Packet_47377A_guess packet_guess;

    if (pLocalPlayer_guess != 0 && player_guess != 0 &&
        gStatusChar_47377A_guess->GetStatus_guess() == 0 && gActionFlag_47377A_guess != 0) {
        EQPlayer* target_guess = pTargetPlayer_47377A_guess;
        if (target_guess == 0) {
            target_guess = pLocalPlayer_guess;
        }
        memset(&packet_guess, 0, sizeof(packet_guess));
        int rest_guess = GrabFirstWord_guess(text_guess, token1_guess, 0x40);
        rest_guess = GrabFirstWord_guess((const char*)rest_guess, token2_guess, 0x40);
        GrabFirstWord_guess((const char*)rest_guess, token3_guess, 0x40);
        atoi(token2_guess);
        atoi(token3_guess);
        FUN_0060e450_guess(packet_guess.first_guess, player_guess->Name);
        FUN_0060e450_guess(packet_guess.second_guess, target_guess->Name);
        FUN_0060e450_guess(packet_guess.first_guess, pLocalPlayer_guess->Name);
        FUN_0060e450_guess(packet_guess.second_guess, pLocalPlayer_guess->Name);
        packet_guess.type_guess = 4;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x425c, &packet_guess, 0x88, 1);
    }
}

// Combat message filters: each kind has an option on the chat manager 0x9917E4 (0 full text, 1 brief
// eqstr, 2 the number only), and with 0x924788 == 1 the full text is also logged (hits only above -41).
// You hit other: option +0x218, brief 0x852, colour 0x109.
// FUNCTION: TITANIUM 0x004738AF
void __cdecl ShowYouHitOtherMessage_guess(const char* text_guess, const char* arg2_guess, const char* arg3_guess,
                          const char* arg4_guess, int value_guess) {
    char buffer_guess[256];
    char number_guess[16];

    switch (gDisplayMode_guess->mode_218_guess) {
    case 0:
        pEverQuest->dsp_chat(text_guess, 0x109, false);
        break;
    case 1:
        sprintf(number_guess, "%d", value_guess);
        build_token_string_PARAM_guess(buffer_guess, 0x852, arg2_guess, arg3_guess,
                                       number_guess, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x109, false);
        break;
    case 2:
        sprintf(number_guess, "%d", value_guess);
        pEverQuest->dsp_chat(number_guess, 0x109, false);
        break;
    }
    if (gDebugFlag_guess == 1 && value_guess > -0x29) {
        eqlog_guess(text_guess);
    }
}

struct DisplayMode220_guess {
    char pad_000_guess[0x220];
    int mode_220_guess; // 0x220
};
#define gDisplayMode220_guess EQ_GLOBAL(DisplayMode220_guess*, 0x009917E4)

// Other hits you: option +0x220, brief 0x83C, colour 0x10A.
// FUNCTION: TITANIUM 0x0047396C
void __cdecl ShowOtherHitsYouMessage_guess(const char* text_guess, const char* arg2_guess,
                                const char* arg3_guess, const char* arg4_guess,
                                int value_guess) {
    char buffer_guess[256];
    char number_guess[16];

    switch (gDisplayMode220_guess->mode_220_guess) {
    case 0:
        pEverQuest->dsp_chat(text_guess, 0x10a, false);
        break;
    case 1:
        sprintf(number_guess, "%d", value_guess);
        build_token_string_PARAM_guess(buffer_guess, 0x83c, arg4_guess, arg2_guess,
                                       number_guess, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x10a, false);
        break;
    case 2:
        sprintf(number_guess, "%d", value_guess);
        pEverQuest->dsp_chat(number_guess, 0x10a, false);
        break;
    }
    if (gDebugFlag_guess == 1 && value_guess > -0x29) {
        eqlog_guess(text_guess);
    }
}

struct DisplayMode228_guess {
    char pad_000_guess[0x228];
    int mode_228_guess; // 0x228
};
#define gDisplayMode228_guess EQ_GLOBAL(DisplayMode228_guess*, 0x009917E4)

// Other hits other: option +0x228, brief 0x850, caller's colour.
// FUNCTION: TITANIUM 0x00473A29
void __cdecl ShowOtherHitsOtherMessage_guess(char* text_guess, const char* arg2_guess, const char* arg3_guess,
                          const char* arg4_guess, int value_guess, int arg6_guess) {
    char buffer_guess[256];
    char number_guess[16];
    switch (gDisplayMode228_guess->mode_228_guess) {
    case 0:
        gGlobalContext_guess->SetText_guess(text_guess, arg6_guess, 0);
        break;
    case 1:
        sprintf(number_guess, "%d", value_guess);
        build_token_string_PARAM_guess(buffer_guess, 0x850, arg4_guess, arg2_guess,
                                       arg3_guess, number_guess, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, arg6_guess, 0);
        break;
    case 2:
        sprintf(number_guess, "%d", value_guess);
        gGlobalContext_guess->SetText_guess(number_guess, arg6_guess, 0);
        break;
    }
    if (gDebugFlag_guess == 1 && value_guess > -0x29) {
        eqlog_guess(text_guess);
    }
}

// Other misses other: option +0x22C, brief 0x3AC1, caller's colour.
// FUNCTION: TITANIUM 0x00473C26
void __cdecl ShowOtherMissesOtherMessage_guess(char* text_guess, int unused_guess, const char* arg3_guess,
                          const char* arg4_guess, int color_guess) {
    char buffer_guess[256];

    switch (gDisplayState_guess->mode_22c_guess) {
    case 0:
        pEverQuest->dsp_chat(text_guess, color_guess, false);
        break;
    case 1:
        build_token_string_PARAM_guess(buffer_guess, 0x3ac1, arg4_guess, arg3_guess,
                                       0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, color_guess, false);
        break;
    case 2:
        pEverQuest->dsp_chat(pStringTable->getString(0x2f7c, 0), color_guess, false);
        break;
    }
    if (gDebugFlag_guess == 1) {
        eqlog_guess(text_guess);
    }
}

// Rewrites English server suffixes in place with eqstr forms: familiar 0x4C5, Mount 0x4C6, warder
// 0x4C4, pet's corpse 0x4C7 + 0x4C9, corpse 0x4C7, pet 0x4C9, 'Eye of' 0x4C8.
// FUNCTION: TITANIUM 0x00473CC3
void __cdecl ConvertNameToLocal_guess(char* text_guess) {
    char output_guess[64];
    char scratch_guess[64];
    char* suffix_guess;

    if (text_guess == 0) {
        return;
    }

    suffix_guess = text_guess + strlen(text_guess) - 10;
    // 'familer' is the client's spelling (original string).
    if (suffix_guess > text_guess && strcmp(suffix_guess, "`s familer") == 0) {
        *suffix_guess = 0;
        strncpy(output_guess, text_guess, 0x3f);
        build_token_string_PARAM_guess(text_guess, 0x4c5, output_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        suffix_guess = text_guess + strlen(text_guess) - 8;
        if (suffix_guess > text_guess && strcmp(suffix_guess, "`s Mount") == 0) {
            *suffix_guess = 0;
            strncpy(output_guess, text_guess, 0x3f);
            build_token_string_PARAM_guess(text_guess, 0x4c6, output_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            suffix_guess = text_guess + strlen(text_guess) - 9;
            if (suffix_guess > text_guess && strcmp(suffix_guess, "`s warder") == 0) {
                *suffix_guess = 0;
                strncpy(output_guess, text_guess, 0x3f);
                build_token_string_PARAM_guess(text_guess, 0x4c4, output_guess,
                                               0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                suffix_guess = text_guess + strlen(text_guess) - 13;
                if (suffix_guess > text_guess && strcmp(suffix_guess, " pet's corpse") == 0) {
                    *suffix_guess = 0;
                    strncpy(output_guess, text_guess, 0x3f);
                    build_token_string_PARAM_guess(scratch_guess, 0x4c9, output_guess,
                                                   0, 0, 0, 0, 0, 0, 0, 0);
                    build_token_string_PARAM_guess(text_guess, 0x4c7, scratch_guess,
                                                   0, 0, 0, 0, 0, 0, 0, 0);
                    return;
                } else {
                    suffix_guess = text_guess + strlen(text_guess) - 9;
                    if (suffix_guess > text_guess && strcmp(suffix_guess, "'s corpse") == 0) {
                        *suffix_guess = 0;
                        strncpy(output_guess, text_guess, 0x3f);
                        build_token_string_PARAM_guess(text_guess, 0x4c7, output_guess,
                                                       0, 0, 0, 0, 0, 0, 0, 0);
                    } else {
                        suffix_guess = text_guess + strlen(text_guess) - 4;
                        if (suffix_guess > text_guess && strcmp(suffix_guess, " pet") == 0) {
                            *suffix_guess = 0;
                            strncpy(output_guess, text_guess, 0x3f);
                            build_token_string_PARAM_guess(text_guess, 0x4c9, output_guess,
                                                           0, 0, 0, 0, 0, 0, 0, 0);
                        } else {
                            if (strncmp(text_guess, "Eye of ", 7) != 0) {
                                return;
                            }
                            strncpy(output_guess, text_guess + 7, 0x3f);
                            build_token_string_PARAM_guess(text_guess, 0x4c8, output_guess,
                                                           0, 0, 0, 0, 0, 0, 0, 0);
                        }
                    }
                }
            }
        }
    }

}

// The profile data returned by GetCharInfo2; the 100-entry value array is at 0xF70.
struct CharValues_46_guess {
    int values_guess[100];                  // 0xF70
    int Get_guess(int index_guess) {
        return values_guess[index_guess];
    }
    void Put_guess(int index_guess, int value_guess) {
        values_guess[index_guess] = value_guess;
    }
};

struct CHARINFO2 {
    unsigned char pad_000_guess[0xF70];
    CharValues_46_guess values_0F70_guess;  // 0xF70
    unsigned char pad_1100_guess[0x98];
    int race_1198_guess;                   // 0x1198
    unsigned char class_119c_guess;         // 0x119C
    unsigned char pad_119D_guess[7];
    int level_11a4_guess;                   // 0x11A4
};

struct Profile_46_guess : EQ_CharacterProfile_guess {
    virtual void VSlot00_guess();
    CHARINFO2* Info_guess() {
        return GetCharInfo2();
    }
    // EXTERNAL: TITANIUM 0x0045511F Profile_46_guess::Set11f8_guess
    void Set11f8_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041AA6A Profile_46_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
};

struct PcPrefix_46_guess {
    virtual void PSlot00_guess();
    int field_004_guess;
};

// pCharData's object: the profile is one virtual base reached through the vbptr at +8.
struct PcProfile_46_guess : PcPrefix_46_guess, virtual Profile_46_guess {
    unsigned char pad_00C_guess[0xC280 - 0x00C];
};

struct PcCharacter1_46_guess : virtual Profile_46_guess {
    virtual void CSlot00_guess();
    EQPlayer* spawn_008_guess;              // 0xC288
    unsigned char pad_00C_guess[0x104 - 0x00C];
};

struct PcFull_46_guess : PcProfile_46_guess, PcCharacter1_46_guess {
};

struct Spell_46_guess {
    // EXTERNAL: TITANIUM 0x0044A335 Spell_46_guess::GetFourth_guess
    int GetFourth_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0044A2E4 Spell_46_guess::GetFirst_guess
    int GetFirst_guess(int index_guess);
};

#define g_spells_46_guess EQ_ARRAY(Spell_46_guess*, 0x00851200)

// EXTERNAL: TITANIUM 0x0044A448 GetSkillCap_guess
int __cdecl GetSkillCap_guess(int level_guess, int class_guess, int slot_guess,
                                PcFull_46_guess* pc_guess);

// Raises every class skill to its cap for the level (0x44A448; 0 below the skill's level) and
// passes (level + 1) * 5 to 0x45511F. Non-GMs keep their tradeskills (55-65, 68, 69). Casters get the
// five specialisations (43-47) at 49: priests from 30, int casters (11-14) from 20. Racial skills by
// race: forage/hide, hide, sneak/hide, tinkering, swimming 100, sneak/safe fall, swimming 125 (330).
// Sense heading becomes 200.
// FUNCTION: TITANIUM 0x00473EEF
// @early-stop: budget, structural ndiff=217
int __cdecl SetSkillsToCap_guess(PcFull_46_guess* pc_guess) {
    int slot_guess;
    // Tradeskill values (55-61, 63-65, 68, 69) are saved first so a non-GM keeps them.
    int saved_45_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x45);
    int saved_44_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x44);
    int saved_40_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x40);
    int saved_37_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x37);
    int saved_41_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x41);
    int saved_3F_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x3F);
    int saved_3D_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x3D);
    int saved_3C_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x3C);
    int saved_38_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x38);
    int saved_39_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x39);
    int saved_3A_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x3A);
    int saved_3B_guess = pc_guess->Info_guess()->values_0F70_guess.Get_guess(0x3B);

    pc_guess->Info_guess();
    pc_guess->Set11f8_guess((pc_guess->Info_guess()->level_11a4_guess + 1) * 5);
    int value_guess = 0;
    // Every skill to its cap for the level (0 below the skill's level).
    for (slot_guess = 0; slot_guess < 100; ++slot_guess) {
        if (g_spells_46_guess[slot_guess]->GetFourth_guess(
                pc_guess->Info_guess()->class_119c_guess) != 0) {
            int level_guess = pc_guess->Info_guess()->level_11a4_guess;
            pc_guess->SetValue_guess(slot_guess,
                level_guess - g_spells_46_guess[slot_guess]->GetFirst_guess(
                                  pc_guess->Info_guess()->class_119c_guess) < 0
                    ? 0
                    : GetSkillCap_guess(pc_guess->Info_guess()->level_11a4_guess,
                                         pc_guess->Info_guess()->class_119c_guess,
                                         slot_guess, pc_guess));
        }
    }
    if (pc_guess->spawn_008_guess->GM == 0) {
        pc_guess->SetValue_guess(0x45, saved_45_guess);
        pc_guess->SetValue_guess(0x44, saved_44_guess);
        pc_guess->SetValue_guess(0x40, saved_40_guess);
        pc_guess->SetValue_guess(0x37, saved_37_guess);
        pc_guess->SetValue_guess(0x41, saved_41_guess);
        pc_guess->SetValue_guess(0x3F, saved_3F_guess);
        pc_guess->SetValue_guess(0x3D, saved_3D_guess);
        pc_guess->SetValue_guess(0x3C, saved_3C_guess);
        pc_guess->SetValue_guess(0x38, saved_38_guess);
        pc_guess->SetValue_guess(0x39, saved_39_guess);
        pc_guess->SetValue_guess(0x3A, saved_3A_guess);
        pc_guess->SetValue_guess(0x3B, saved_3B_guess);
    }
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2B, 0);
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2C, 0);
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2D, 0);
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2E, 0);
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2F, 0);
    unsigned char classValue_guess = pc_guess->Info_guess()->class_119c_guess;
    // Specialisations 43-47 start at 0 and are set to 49 for priests (2, 6, 10) from level 30 and for int
    // casters (11-14) from level 20.
    if (classValue_guess == 2 || classValue_guess == 6 || classValue_guess == 0xA) {
        if (pc_guess->Info_guess()->level_11a4_guess >= 0x1E)
            value_guess = 0x31;
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2B, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2C, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2D, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2E, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2F, value_guess);
    } else if (classValue_guess > 0xA && classValue_guess <= 0xE) {
        if (pc_guess->Info_guess()->level_11a4_guess >= 0x14)
            value_guess = 0x31;
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2B, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2C, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2D, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2E, value_guess);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2F, value_guess);
    }
    // Racial skills by race (+0x1198).
    switch (pc_guess->Info_guess()->race_1198_guess) {
    case 4:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x1B, 0x32);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x1D, 0x32);
        break;
    case 6:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x1D, 0x32);
        break;
    case 0xB:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2A, 0x32);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x1D, 0x32);
        break;
    case 0xC:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x39, 0x32);
        break;
    case 0x80:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x32, 100);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x1B, 0x32);
        break;
    case 0x82:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x2A, 0x32);
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x27, 0x32);
        break;
    case 0x14A:
        pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x32, 0x7D);
        break;
    }
    pc_guess->Info_guess()->values_0F70_guess.Put_guess(0x28, 200);
    return 1;
}

struct ProfileName_46_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 ProfileName_46_guess::FUN_005e0f00_guess
    const char* FUN_005e0f00_guess();
};

struct ProfileNames46_guess {
    char pad_000_guess[0x2c];
    ProfileName_46_guess* first_2c_guess;
    char pad_030_guess[4];
    ProfileName_46_guess* second_34_guess;
    ProfileName_46_guess* third_38_guess;
    char pad_03c_guess[0x3c];
    int value_78_guess;
    ProfileName_46_guess* GetFirst_guess() {
        return first_2c_guess;
    }
    ProfileName_46_guess* GetSecond_guess() {
        return second_34_guess;
    }
    ProfileName_46_guess* GetThird_guess() {
        return third_38_guess;
    }
    int GetValue78_guess() {
        return value_78_guess;
    }
};

struct CharInfo46_guess {
    char pad_000_guess[0x10];
    ProfileNames46_guess names_010_guess;
    char pad_08c_guess[0x11a4 - 0x8c];
    int level_11a4_guess;
    char pad_11a8_guess[0x11d4 - 0x11a8];
    int platinum_11d4_guess;
    int gold_11d8_guess;
    int silver_11dc_guess;
    int copper_11e0_guess;
    int cursorPlatinum_11e4_guess;
    int cursorGold_11e8_guess;
    int cursorSilver_11ec_guess;
    int cursorCopper_11f0_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    CharInfo46_guess* GetCharInfo2();
};

struct Slot_474597_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 Slot_474597_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0D40 Slot_474597_guess::Level_guess
    int Level_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Slot_474597_guess::GetItemId_guess
    int GetItemId_guess();
};

struct SlotTable_474597_guess {
    void* vftable_guess;
    EQ_CharacterProfileView_guess profile_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 SlotTable_474597_guess::Get_guess
    Slot_474597_guess* Get_guess(int index);
    // EXTERNAL: TITANIUM 0x00434777 SlotTable_474597_guess::GetSlot_guess
    RefObject_464C94_guess** GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x0041AA84 SlotTable_474597_guess::FUN_0041aa84_guess
    void FUN_0041aa84_guess(int index, RefObject_464C94_guess* object);
};

struct NameCheck_474597_guess {
    // EXTERNAL: TITANIUM 0x00439546 NameCheck_474597_guess::Check_guess
    unsigned char Check_guess(int value);
};
#define gNameCheck_474597_guess EQ_GLOBAL(NameCheck_474597_guess*, 0x00905D24)

struct ActionData_474597_guess {
    char pad_000_guess[0xad];
    char flag_ad_guess;
};

struct Action_474597_guess {
    char pad_000_guess[0x1a8];
    ActionData_474597_guess* pActorInfo_01a8_guess;
    char pad_1ac_guess[0x253 - 0x1ac];
    char light_0253_guess;
    // EXTERNAL: TITANIUM 0x0047BCE2 Action_474597_guess::UpdateLight_guess
    void UpdateLight_guess();
    // EXTERNAL: TITANIUM 0x0048083A Action_474597_guess::FUN_0048083a_guess
    void FUN_0048083a_guess(char value_guess, const char* text_guess, int flag_guess);
};

struct Prefix_474597_guess {
    int unused_000_guess;
    int unused_004_guess;
};

struct Holder_474597_guess : Prefix_474597_guess, virtual SlotTable_474597_guess {
    char pad_00c_guess[0xc280 - 0xc];
    CommandContext_guess command_c280_guess;
    PartState_guess* part_guess;
    Action_474597_guess* current_c288_guess;
    char flag_c28c_guess;
    char pad_c28d_guess[0xc348 - 0xc28d];
    char flag_c348_guess;
    SlotTable_474597_guess& GetSlotTable_guess() {
        return *this;
    }
    // EXTERNAL: TITANIUM 0x004BC5EB Holder_474597_guess::FitsEquipSlot_guess
    char FitsEquipSlot_guess(int index_guess, RefObject_464C94_guess* object_guess);
    // EXTERNAL: TITANIUM 0x004BCF0B Holder_474597_guess::AutoInventoryItem_guess
    void AutoInventoryItem_guess(RefObject_464C94_guess** object_guess, int value_guess,
                            int unused_guess, int flag_guess);
};

// Light source from the 21 worn slots (brightest by 0x439546), then the 8 inventory slots 22-29,
// where only types 9-13 count and win whenever the type number exceeds their own brightness
// (same test in the older client, kept). Types 1, 2, 4, 6 are ignored with night vision (+0xAD).
// FUNCTION: TITANIUM 0x00474597
void __cdecl UpdateLight_guess(Holder_474597_guess* holder_guess) {
    if (holder_guess != 0 && holder_guess->current_c288_guess != 0 &&
        holder_guess->current_c288_guess->pActorInfo_01a8_guess != 0) {
        unsigned char best_guess = 0;
        unsigned char result_guess = 0;
        char flag_guess = holder_guess->current_c288_guess->light_0253_guess;
        for (int i = 0; i < 0x15; ++i) {
            if (holder_guess->Get_guess(i) != 0) {
                if (holder_guess->Get_guess(i)->GetItemClass_guess() == 0) {
                    unsigned char value = gNameCheck_474597_guess->Check_guess(
                        holder_guess->Get_guess(i)->Level_guess());
                    if (value > best_guess) {
                        best_guess = value;
                        result_guess = holder_guess->Get_guess(i)->Level_guess();
                    }
                }
            }
        }
        for (int i = 0x16; i <= 0x1d; ++i) {
            if (holder_guess->Get_guess(i) != 0) {
                if (holder_guess->Get_guess(i)->GetItemClass_guess() == 0) {
                    best_guess = gNameCheck_474597_guess->Check_guess(
                        holder_guess->Get_guess(i)->Level_guess());
                    if (holder_guess->Get_guess(i)->Level_guess() >= 9) {
                        if (holder_guess->Get_guess(i)->Level_guess() <= 13) {
                            if (holder_guess->Get_guess(i)->Level_guess() > best_guess) {
                                result_guess = holder_guess->Get_guess(i)->Level_guess();
                            }
                        }
                    }
                }
            }
        }
        Action_474597_guess* action_guess = holder_guess->current_c288_guess;
        if (action_guess != 0 && action_guess->pActorInfo_01a8_guess != 0 &&
            action_guess->pActorInfo_01a8_guess->flag_ad_guess != 0 && result_guess > 0) {
            if (result_guess <= 2 || result_guess == 4 || result_guess == 6) {
                result_guess = 0;
            }
        }
        action_guess->light_0253_guess = result_guess;
        if (holder_guess->current_c288_guess->light_0253_guess != flag_guess) {
            holder_guess->current_c288_guess->UpdateLight_guess();
        }
    }
}

// Auto-equip: first offers the item to worn slots 0-21 holding the same kind (0x464D65, probably
// stacking), then puts the item in the first empty worn
// slot it fits (OP_MoveItem 0x420F from `value`), updating the primary/secondary (13/14) or range (11)
// models and the light. Anything left goes to 0x4BCF0B (probably the bags). `index < 0x16` is always
// true there (kept).
// FUNCTION: TITANIUM 0x0047477F
void __cdecl AutoEquipItem_guess(Holder_474597_guess* holder_guess,
                          RefObject_464C94_guess** objectAddress_guess,
                          int value_guess) {
    if (objectAddress_guess == 0) {
        return;
    }
    int index_guess;
    RefObject_464C94_guess* object_guess = *objectAddress_guess;
    if (object_guess == 0) {
        return;
    }
    if (holder_guess == 0) {
        return;
    }
    if (gNpcNameState_guess->flag_11_guess != 0) {
        return;
    }
    if (object_guess->IsStackable_guess() != 0) {
        for (index_guess = 0; index_guess <= 0x15; ++index_guess) {
            if (object_guess != 0 &&
                holder_guess->FitsEquipSlot_guess(index_guess, object_guess) != 0 &&
                holder_guess->command_c280_guess.CanUseItem_guess(object_guess, 1) != 0 &&
                holder_guess->Get_guess(index_guess) != 0 &&
                holder_guess->Get_guess(index_guess)->GetItemId_guess() ==
                    object_guess->GetItemId_guess()) {
                SwapCombine_guess(&object_guess, holder_guess->GetSlot_guess(index_guess),
                             value_guess, index_guess);
            }
        }
    }
    char flag_guess = 1;
    if (object_guess != 0) {
        if (object_guess->FUN_005ec820_guess() != 0 &&
            object_guess->value_5c_guess == 0) {
            flag_guess = 0;
        }
        if (object_guess != 0) {
            if (object_guess->GetItemClass_guess() == 0 && flag_guess != 0) {
                index_guess = 0;
                const char* empty_guess = EQ_ARRAY(char, 0x006410A8);
                do {
                    if (object_guess != 0 &&
                        holder_guess->FitsEquipSlot_guess(index_guess, object_guess) != 0 &&
                        holder_guess->command_c280_guess.CanUseItem_guess(
                            object_guess, 1) != 0 &&
                        holder_guess->Get_guess(index_guess) == 0) {
                        if (index_guess < InvSlot_EquipmentCount) {
                            gMixAhead_guess->WavePlay_guess(0x92, 0);
                        }
                        gNpcNameState_guess->UpdateItemSlot_guess(
                            holder_guess, index_guess, object_guess,
                            holder_guess->Get_guess(index_guess));
                        holder_guess->FUN_0041aa84_guess(index_guess, object_guess);
                        TransferMessage_guess message_guess;
                        message_guess.value_guess = value_guess;
                        message_guess.data_guess = index_guess;
                        message_guess.amount_guess = 0;
                        SendMessage_guess(&gSendTarget_guess, OP_MoveItem,
                                          &message_guess, 0xc, 1);
                        if (object_guess->FUN_005ec820_guess() != 0) {
                            object_guess->value_5c_guess = 1;
                        }
                        object_guess = 0;
                        if (index_guess == 0xd) {
                            if (holder_guess->current_c288_guess != 0) {
                                holder_guess->current_c288_guess->FUN_0048083a_guess(
                                    GetTextureSlot_guess(0xd),
                                    holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetSecond_guess()->FUN_005e0f00_guess(),
                                    0);
                            }
                            if (holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetThird_guess() != 0) {
                                if (holder_guess->current_c288_guess != 0) {
                                    holder_guess->current_c288_guess->FUN_0048083a_guess(
                                        GetTextureSlot_guess(0xe),
                                        holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetThird_guess()->FUN_005e0f00_guess(),
                                        0);
                                }
                            } else if (holder_guess->current_c288_guess != 0) {
                                holder_guess->current_c288_guess
                                    ->FUN_0048083a_guess(GetTextureSlot_guess(0xe),
                                                         empty_guess, 0);
                            }
                        } else if (index_guess == 0xe) {
                            if (holder_guess->current_c288_guess != 0) {
                                holder_guess->current_c288_guess->FUN_0048083a_guess(
                                    GetTextureSlot_guess(0xe),
                                    holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetThird_guess()->FUN_005e0f00_guess(),
                                    0);
                            }
                            if (holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetSecond_guess() != 0) {
                                if (holder_guess->current_c288_guess != 0) {
                                    holder_guess->current_c288_guess->FUN_0048083a_guess(
                                        GetTextureSlot_guess(0xd),
                                        holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetSecond_guess()->FUN_005e0f00_guess(),
                                        0);
                                }
                            } else if (holder_guess->current_c288_guess != 0) {
                                holder_guess->current_c288_guess
                                    ->FUN_0048083a_guess(GetTextureSlot_guess(0xd),
                                                         empty_guess, 0);
                            }
                        } else if (index_guess == 0xb &&
                                   holder_guess->current_c288_guess != 0) {
                            holder_guess->current_c288_guess->FUN_0048083a_guess(
                                7, empty_guess, 0);
                            holder_guess->current_c288_guess->FUN_0048083a_guess(
                                8, empty_guess, 0);
                            holder_guess->current_c288_guess->FUN_0048083a_guess(
                                8,
                                holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetFirst_guess()->FUN_005e0f00_guess(),
                                0);
                        }
                        UpdateLight_guess(holder_guess);
                    }
                    ++index_guess;
                } while (index_guess <= 0x15);
            }
            if (object_guess != 0) {
                holder_guess->AutoInventoryItem_guess(&object_guess, value_guess, 0, 1);
            }
        }
    }
    *objectAddress_guess = object_guess;
    gNpcNameState_guess->flag_10_guess =
        (holder_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()->names_010_guess.GetValue78_guess() != 0);
    if (pinstCTradeskillWnd_guess != 0) {
        pinstCTradeskillWnd_guess->Flush_guess();
    }
    holder_guess->flag_c28c_guess = 1;
    holder_guess->flag_c348_guess = 0;
}

struct Destructible_47614B_guess {
    // EXTERNAL: TITANIUM 0x0048BB3B Destructible_47614B_guess::~Destructible_47614B_guess
    ~Destructible_47614B_guess();
    Destructible_47614B_guess* Delete_47614B_guess(unsigned char flags);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// Scalar deleting destructor.
// FUNCTION: TITANIUM 0x0047614B
Destructible_47614B_guess* Destructible_47614B_guess::Delete_47614B_guess(unsigned char flags) {
    this->Destructible_47614B_guess::~Destructible_47614B_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

struct PropertyRow46_guess {
    unsigned char padding_guess[0x119c];
    unsigned char kind_guess;       // 0x119c
    unsigned char padding2_guess[7];
    int level_guess;                // 0x11a4
};

struct EQ_CharacterProfileView2_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView2_guess::GetCharInfo2
    PropertyRow46_guess* GetCharInfo2();
};

struct PropertyOwner46_guess {
    unsigned char padding_guess[4];
    EQ_CharacterProfileView2_guess locator_guess;
};

struct PropertyHostVtable46_guess {
    virtual void Slot00_guess();
};

struct PropertyHost46_guess : PropertyHostVtable46_guess, virtual PropertyOwner46_guess {
};

struct Rank46_guess {
    // EXTERNAL: TITANIUM 0x005ECC00 Rank46_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0E90 Rank46_guess::GetLevel_guess
    int GetLevel_guess();
};

// EQEmu's GetWeaponDamageBonus: melee classes from level 28 get (level - 28) / 3 + 1; two-handers
// (item types 1, 4, 35) add more with weapon delay; class 16 throwing (type 19) has its own formula.
// FUNCTION: TITANIUM 0x0046E0A5
// @early-stop: budget, structural ndiff=45
int __cdecl GetWeaponDamageBonus_guess(PropertyHost46_guess* host_guess, Rank46_guess* value_guess) {
    PropertyOwner46_guess* owner_guess;

    if (host_guess != 0) {
        owner_guess = host_guess;
        if (owner_guess->locator_guess.GetCharInfo2()->level_guess >= 0x1c) {
            value_guess->GetItemType_guess();
            owner_guess = host_guess;
            unsigned char kind_guess = owner_guess->locator_guess.GetCharInfo2()->kind_guess;
            int total_guess;
    if (kind_guess == 1 ||
                (kind_guess > 2 && (kind_guess <= 5 || (kind_guess > 6 && (kind_guess <= 9 ||
                                    (kind_guess > 0xe && kind_guess <= 0x10)))))) {
        owner_guess = host_guess;
        total_guess = (owner_guess->locator_guess.GetCharInfo2()->level_guess - 0x1c) / 3 + 1;

        owner_guess = host_guess;
        if (owner_guess->locator_guess.GetCharInfo2()->kind_guess == 0x10 &&
            value_guess->GetItemType_guess() == 0x13) {
            owner_guess = host_guess;
            if (owner_guess->locator_guess.GetCharInfo2()->level_guess >= 0x28) {
                owner_guess = host_guess;
                int level_guess = owner_guess->locator_guess.GetCharInfo2()->level_guess;
                int rank_guess = value_guess->GetLevel_guess();
                return (((level_guess - 0x28) / 2) + 1) * rank_guess / 0x1e;
            }
        }

        if (value_guess->GetItemType_guess() == 1 || value_guess->GetItemType_guess() == 4 ||
            value_guess->GetItemType_guess() == 0x23) {
            if (value_guess->GetLevel_guess() < 0x1c) {
                total_guess++;
            } else {
                owner_guess = host_guess;
                if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x1d) {
                    owner_guess = host_guess;
                    int ebx_guess = (owner_guess->locator_guess.GetCharInfo2()->level_guess - 0x1e) / 5 + 1;
                    owner_guess = host_guess;
                    if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x32) {
                        ebx_guess++;
                    }
                    owner_guess = host_guess;
                    if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x32) {
                        owner_guess = host_guess;
                        int count_guess = owner_guess->locator_guess.GetCharInfo2()->level_guess - 0x32;
                        owner_guess = host_guess;
                        if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x36) {
                            count_guess++;
                        }
                        owner_guess = host_guess;
                        if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x38) {
                            count_guess++;
                        }
                        owner_guess = host_guess;
                        if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x3a) {
                            count_guess++;
                        }
                        owner_guess = host_guess;
                        if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x3b) {
                            count_guess++;
                        }
                        owner_guess = host_guess;
                        if (owner_guess->locator_guess.GetCharInfo2()->level_guess > 0x43) {
                            count_guess++;
                        }
                        ebx_guess += (value_guess->GetLevel_guess() * count_guess) / 0x28;
                    }
                    total_guess += ebx_guess;
                }
            }
        }

    if (value_guess->GetLevel_guess() >= 0x28) {
        int step_guess = (value_guess->GetLevel_guess() - 0x28) / 3 + 1;
        if (value_guess->GetLevel_guess() >= 0x2b) {
            step_guess++;
        }
        if (value_guess->GetLevel_guess() >= 0x2d) {
            step_guess++;
        }
        total_guess += step_guess;
    }
            } else {
                total_guess = 0;
            }
            return total_guess;
        }
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_fmt_guess
void __cdecl FUN_00574110_fmt_guess(const char* format_guess, ...);

// packet sent to the client: checksum, size, 256 index/value pairs
struct SpellFile_46dd41_guess {
    int checksum_guess;
    int size_guess;
    int index_guess[256];
    int value_guess[256];
};

// OP_World_Client_CRC1 (0x5072): checksum and size of spells_<lang>.txt plus 256 randomly sampled
// dwords and their indexes; sent to `target`, or the world connection when 0.
// FUNCTION: TITANIUM 0x0046DD41
// @early-stop: budget, structural ndiff=21
int __cdecl SendSpellChecksum_guess(int target_guess) {
    SpellFile_46dd41_guess packet_guess;
    FileStat_guess stat_guess;
    char path_guess[256];
    sprintf(path_guess, "spells_%s.txt", gFontNames_guess[gFontIndex_guess]);
    if (__stat(path_guess, &stat_guess) != 0) {
        return 0;
    }
    HGLOBAL buffer_guess;
    FILE* file_guess;
    int last_guess;
    buffer_guess = (int*)GlobalAlloc(GMEM_ZEROINIT, stat_guess.size_014_guess);
    file_guess = fopen(path_guess, "rb");
    if (file_guess == 0) {
        GlobalFree(buffer_guess);
        return 0;
    }
    if (fread(buffer_guess, stat_guess.size_014_guess, 1, file_guess) != 1) {
        fclose(file_guess);
        GlobalFree(buffer_guess);
        return 0;
    }
    fclose(file_guess);
    int checksum_guess = MemChecker0(buffer_guess, stat_guess.size_014_guess);
    FUN_00574110_fmt_guess("Check 1sa. 0x%08x\n", checksum_guess);
    packet_guess.checksum_guess = checksum_guess;
    packet_guess.size_guess = stat_guess.size_014_guess;
    // Files under 1 KB return here without GlobalFree: the buffer leaks (original).
    if ((int)stat_guess.size_014_guess < 0x400) {
        return 0;
    }
    last_guess = ((unsigned int)stat_guess.size_014_guess >> 2) - 1;
    for (int i = 0; i < 256; ++i) {
        int index_guess = RandomRange_guess(0, last_guess);
        packet_guess.index_guess[i] = index_guess;
        packet_guess.value_guess[i] = ((int*)buffer_guess)[index_guess];
    }
    if (target_guess == 0) {
        SendMessage_guess(&gSendTarget_guess, OP_World_Client_CRC1, &packet_guess, 0x808, 1);
    } else {
        SendMessage_guess(&target_guess, OP_World_Client_CRC1, &packet_guess, 0x808, 1);
    }
    GlobalFree(buffer_guess);
    return 1;
}

// OP_World_Client_CRC2 (0x5B18): the same checksum and samples for the running executable. The
// command-line sscanf is overwritten by GetModuleFileNameA right after (kept).
// FUNCTION: TITANIUM 0x0046DEA9
// @early-stop: budget, structural ndiff=30
int __cdecl SendExeChecksum_guess(int target_guess) {
    SpellFile_46dd41_guess packet_guess;
    FileStat_guess stat_guess;
    char file_guess[512];
    char path_guess[512];
    int result_guess;

    LPSTR commandLine_guess = GetCommandLineA();
    sscanf(commandLine_guess, "%s ", path_guess);
    if (GetModuleFileNameA(0, path_guess, 0x200) == 0) {
        FUN_00574110_fmt_guess("ERROR: Unable to get filename (SEC).\n");
        GetLastError();
    }
    size_t length_guess = strlen(path_guess);
    if (path_guess[0] == '"') {
        if ((int)length_guess > 0) {
            for (int i = 0; i < (int)length_guess; ++i) {
                path_guess[i] = path_guess[i + 1];
            }
        }
        --length_guess;
    }
    if (length_guess > 0) {
        if (path_guess[length_guess - 1] == '\\') {
            path_guess[length_guess - 1] = '\0';
            --length_guess;
        }
        if (length_guess > 0 && path_guess[length_guess - 1] == '"') {
            path_guess[length_guess - 1] = '\0';
        }
    }
    FUN_0060e450_guess(file_guess, path_guess);
    if (__stat(file_guess, &stat_guess) != 0) {
        FUN_00574110_fmt_guess("File not found (SEC) %s\n", file_guess);
        return 0;
    }
    HGLOBAL buffer_guess = GlobalAlloc(GMEM_ZEROINIT, stat_guess.size_014_guess);
    FILE* stream_guess = fopen(file_guess, "rb");
    if (stream_guess != 0) {
        if (fread(buffer_guess, stat_guess.size_014_guess, 1, stream_guess) == 1) {
            fclose(stream_guess);
            int checksum_guess = MemChecker0(buffer_guess, stat_guess.size_014_guess);
            FUN_00574110_fmt_guess("Check 1x. 0x%08x\n", checksum_guess);
            packet_guess.size_guess = stat_guess.size_014_guess;
            int last_guess = (stat_guess.size_014_guess >> 2) - 1;
            packet_guess.checksum_guess = checksum_guess;
            for (int i = 0; i < 256; ++i) {
                int index_guess = RandomRange_guess(0, last_guess);
                packet_guess.index_guess[i] = index_guess;
                packet_guess.value_guess[i] = ((int*)buffer_guess)[index_guess];
            }
            if (target_guess == 0) {
                SendMessage_guess(&gSendTarget_guess, OP_World_Client_CRC2, &packet_guess, 0x808, 1);
            } else {
                SendMessage_guess(&target_guess, OP_World_Client_CRC2, &packet_guess, 0x808, 1);
            }
            result_guess = 1;
        } else {
            fclose(stream_guess);
            result_guess = 0;
        }
    } else {
        result_guess = 0;
    }
    GlobalFree(buffer_guess);
    return result_guess;
}

// Seeds the random table (0x3FFFFFFF mask) from QueryPerformanceCounter, or EqGetTime without one,
// then discards 5-100 numbers.
// FUNCTION: TITANIUM 0x0046E370
// @early-stop: budget, diff ndiff=10
void __cdecl init_mm_guess(void) {
    LARGE_INTEGER counter_guess;
    DWORD seed_guess;
    if (QueryPerformanceCounter(&counter_guess) != 0) {
        seed_guess = counter_guess.LowPart;
    } else {
        seed_guess = (DWORD)EqGetTime();
    }
    gRandomIndex_guess = 0;
    gRandomTable_guess[0] = seed_guess & 0x3fffffff;
    gRandomOffset_guess = 0x1f;
    gRandomTable_guess[1] = 1;
    int* entry_guess = gRandomTable_guess;
    int* end_guess = EQ_ARRAY(int, 0x009006A4);
    do {
        int* next_guess = entry_guess + 1;
        entry_guess[2] = (*entry_guess + *next_guess) & 0x3fffffff;
        entry_guess = next_guess;
    } while ((int)entry_guess < (int)end_guess);
    int count_guess = RandomRange_guess(5, 100);
    if (count_guess > 0) {
        do {
            RandNbr_guess();
            --count_guess;
        } while (count_guess != 0);
    }
}

// Returns a random one of its -1-terminated int arguments (32 at most), or -1 when there are none.
// FUNCTION: TITANIUM 0x0046E3EB
int __cdecl PickRandomValue_guess(int value) {
    int values[32];
    int count = 0;
    if (value != -1) {
        int* argument = &value;
        int current = value;
        do {
            if (count >= 32) {
                break;
            }
            argument = argument + 1;
            values[count] = current;
            current = *argument;
            count = count + 1;
        } while (current != -1);
        if (count > 0) {
            count = RandomRange_guess(0, count - 1);
            return values[count];
        }
    }
    return -1;
}

#define g_digits_guess EQ_ARRAY(char, 0x0099DB00)

// Copper total to ' %1 platinum gold silver copper' text (eqstr 0x969-0x96C, zero parts left out),
// in the static buffer 0x900700: the result is overwritten by the next call.
// FUNCTION: TITANIUM 0x0046DAAF
// @early-stop: budget, diff ndiff=2
char* __cdecl CopperToMoneyText_guess(int value_guess) {
    char thousands_text_guess[24];
    char hundreds_text_guess[24];
    char tens_text_guess[24];
    char ones_text_guess[24];
    int thousands_guess = value_guess / 1000;
    int remainder_guess = value_guess + thousands_guess * -1000;
    int hundreds_guess = remainder_guess / 100;
    remainder_guess += hundreds_guess * -100;
    int tens_guess = remainder_guess / 10;
    int ones_guess = remainder_guess + tens_guess * -10;

    if (thousands_guess > 0) {
        build_token_string_PARAM_guess(thousands_text_guess, 0x969, __itoa(thousands_guess, g_digits_guess, 10),
                                       0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        FUN_0060e450_guess(thousands_text_guess, EQ_ARRAY(char, 0x0063F53F));
    }
    if (hundreds_guess > 0) {
        build_token_string_PARAM_guess(hundreds_text_guess, 0x96a, __itoa(hundreds_guess, g_digits_guess, 10),
                                       0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        FUN_0060e450_guess(hundreds_text_guess, EQ_ARRAY(char, 0x0063F53F));
    }
    if (tens_guess > 0) {
        build_token_string_PARAM_guess(tens_text_guess, 0x96b, __itoa(tens_guess, g_digits_guess, 10),
                                      0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        FUN_0060e450_guess(tens_text_guess, EQ_ARRAY(char, 0x0063F53F));
    }
    if (ones_guess > 0) {
        build_token_string_PARAM_guess(ones_text_guess, 0x96c, __itoa(ones_guess, g_digits_guess, 10),
                                       0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        FUN_0060e450_guess(ones_text_guess, EQ_ARRAY(char, 0x0063F53F));
    }
    sprintf(EQ_ARRAY(char, 0x00900700), "%s%s%s%s", thousands_text_guess, hundreds_text_guess,
            tens_text_guess, ones_text_guess);
    return EQ_ARRAY(char, 0x00900700);
}

#define g_zoneName_guess EQ_ARRAY(char, 0x00923F98)

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

struct TextPacket_guess {
    int type_00_guess;
    char text_04_guess[0x40];
    char text_44_guess[0x180];
};

// /makeleader [name]: group leader only (0x9043A4 must be your name); passes leadership to the
// named or targeted group member with OP_GroupUpdate (0x2DD6), action 8. A non-member prints 0x13B2.
// FUNCTION: TITANIUM 0x0046E50A
// @early-stop: budget, structural ndiff=63
void __cdecl do_makeleader_guess(int unused_guess, char* text_guess) {
    int zero_guess = 0;
    const char* message_guess;
    char buffer_guess[0x200] = {0};
    TextPacket_guess packet_guess;
    if (EQ_GLOBAL(char, 0x009043A4) == zero_guess) {
        return;
    }
    if (FUN_00574950_guess(EQ_ARRAY(char, 0x009043A4),
                           g_stateHolder_guess->text_044_guess + g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess) != 0) {
        return;
    }
    ActionContext_guess* panel_guess = EQ_ARRAY(ActionContext_guess, 0x0091D708);
    if (panel_guess->IsInRaid_guess() && panel_guess->CanDisplay_guess()) {
        pEverQuest->dsp_chat(pStringTable->getString(0x22a5, 0), 0xd, true);
        return;
    }
    memset(&packet_guess, zero_guess, sizeof(packet_guess));
    strcpy(packet_guess.text_04_guess,
           g_stateHolder_guess->text_044_guess + g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess);
    packet_guess.type_00_guess = 8;
    if (*text_guess == zero_guess && gIncomingMessage_guess != 0) {
        char* entry_guess = EQ_ARRAY(char, 0x0090424D);
        do {
            if (FUN_00574950_guess(gIncomingMessage_guess->text_120_guess, entry_guess) == 0) {
                strcpy(packet_guess.text_44_guess, gIncomingMessage_guess->text_120_guess);
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GroupUpdate, &packet_guess, sizeof(packet_guess), 1);
                return;
            }
            entry_guess += 0x40;
        } while (entry_guess < EQ_ARRAY(char, 0x0090438D));
        message_guess = gIncomingMessage_guess->text_120_guess;
    } else {
        char* entry_guess = EQ_ARRAY(char, 0x0090424D);
        do {
            if (FUN_00574950_guess(text_guess, entry_guess) == 0) {
                char name_guess[0x40] = {0};
                CapitalizeFirstLetter_guess(text_guess, name_guess, 0x40);
                strcpy(packet_guess.text_44_guess, name_guess);
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GroupUpdate, &packet_guess, sizeof(packet_guess), 1);
                return;
            }
            entry_guess += 0x40;
        } while (entry_guess < EQ_ARRAY(char, 0x009043CD));
        message_guess = text_guess;
    }
    ReplaceTokens_guess(buffer_guess, pStringTable->getString(0x13b2, 0), &message_guess, -1, 0);
    pEverQuest->dsp_chat(buffer_guess, 0x111, true);
}

// EXTERNAL: TITANIUM 0x006120A0 atan2_guess
double __cdecl atan2_guess(double y_guess, double x_guess);

// Bearing from (x1,y1) to (x2,y2) as an EQ heading: the atan2 angle of the absolute differences is put in
// its quadrant (degrees), then scaled to heading units.
// FUNCTION: TITANIUM 0x0046E42F
double __cdecl get_bearing_guess(float x1_guess, float y1_guess, float x2_guess, float y2_guess) {
    double xDiff_guess = _fabs(x1_guess - x2_guess);
    double yDiff_guess = _fabs(y1_guess - y2_guess);
    if (xDiff_guess < 0.000001f) {
        xDiff_guess = 0.000001f;
    }
    double angle_guess = (float)(atan2_guess(yDiff_guess, xDiff_guess) * 180.0f) * 0.3183099014828645;
    if (x1_guess >= x2_guess && y2_guess >= y1_guess) {
        angle_guess = (90.0f - angle_guess) + 90.0f;
    } else if (x1_guess >= x2_guess && y1_guess >= y2_guess) {
        angle_guess = angle_guess + 180.0f;
    } else if (x2_guess >= x1_guess && y1_guess >= y2_guess) {
        angle_guess = (90.0f - angle_guess) + 270.0f;
    }
    // Degrees to EQ heading units (512 a turn; the client scales by 511.5).
    return (float)((float)angle_guess * 511.5f) * 0.0027777778f;
}

struct TokenPacket_guess {
    char pad_00_guess[0x40];
    int type_40_guess;
    char text_44_guess[0x40];
    int value_84_guess;
    int id_88_guess;
};

// /vtell <name> <macro#>: voice macro (OP_VoiceMacroIn 0x2866, type 1) while voice macros are on
// (0x985D90); you can't tell yourself (0x3023), a refused macro prints 0x1782.
// FUNCTION: TITANIUM 0x0046E708
void __cdecl do_vtell_guess(int unused_guess, const char* text_guess) {
    // Command with an id argument; the reply text goes to the chat window.
    char buffer_guess[0x200];
    TokenPacket_guess packet_guess;
    if (!gCommandState65eb8_guess->Enabled_guess()) {
        return;
    }
    if (text_guess == 0 || *text_guess == '\0') {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x1781, 0), 0, 1);
        return;
    }
    int rest_guess = GrabFirstWord_guess(text_guess, buffer_guess, 0x40);
    FUN_0060e450_guess(packet_guess.text_44_guess, buffer_guess);
    if (strcmp(packet_guess.text_44_guess,
               g_stateHolder_guess->text_044_guess + g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess) == 0) {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x3023, 0), 0, 1);
        return;
    }
    GrabFirstWord_guess((const char*)rest_guess, buffer_guess, 0x32);
    long id_guess = atol(buffer_guess);
    if (gCommandState65eb8_guess->HasMacro_guess(id_guess)) {
        packet_guess.type_40_guess = 1;
        packet_guess.value_84_guess = gCommandState65eb8_guess->GetValue_guess();
        packet_guess.id_88_guess = id_guess;
        SendMessage_guess(&gSendTarget_guess, OP_VoiceMacroIn, &packet_guess, sizeof(packet_guess), 1);
        gCommandState65eb8_guess->Apply_guess(id_guess, -1);
        build_token_string_PARAM_guess(buffer_guess, 0x1785, packet_guess.text_44_guess,
                                       (const char*)gCommandState65eb8_guess->GetCount_guess(id_guess),
                                       0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0x101, 1);
    } else {
        gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0x1782, 0), 0xf, 1);
    }
}

// /vgroup <macro#>: voice macro type 2, group only (0x3039). The packet's name (+0x44) is never set,
// so stack bytes are sent and printed in 0x1786.
// FUNCTION: TITANIUM 0x0046E87D
void __cdecl do_vgroup_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x200];
    TokenPacket_guess packet_guess;
    if (!gCommandState65eb8_guess->Enabled_guess()) {
        return;
    }
    if (!g_stateHolder_guess->IsInGroup_guess()) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3039, 0), 0, true);
        return;
    }
    if (text_guess == 0 || *text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x1781, 0), 0, true);
        return;
    }
    GrabFirstWord_guess(text_guess, buffer_guess, 0x32);
    long id_guess = atol(buffer_guess);
    if (gCommandState65eb8_guess->HasMacro_guess(id_guess)) {
        packet_guess.type_40_guess = 2;
        packet_guess.value_84_guess = gCommandState65eb8_guess->GetValue_guess();
        packet_guess.id_88_guess = id_guess;
        gCommandState65eb8_guess->Apply_guess(id_guess, -1);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_VoiceMacroIn, &packet_guess, 0x8c, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x1786, packet_guess.text_44_guess,
                                       (const char*)gCommandState65eb8_guess->GetCount_guess(id_guess),
                                       0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x102, true);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x1782, 0), 0xf, true);
    }
}

// /vraid <macro#>: voice macro type 3, raid only (0x1784); same unset name as /vgroup.
// FUNCTION: TITANIUM 0x0046E9C2
void __cdecl do_vraid_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x200];
    TokenPacket_guess packet_guess;
    if (!gCommandState65eb8_guess->Enabled_guess()) {
        return;
    }
    if (!g_stateHolder_guess->IsInRaid_guess()) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1784, 0), 0, true);
        return;
    }
    if (text_guess == 0 || *text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x1781, 0), 0, true);
        return;
    }
    GrabFirstWord_guess(text_guess, buffer_guess, 0x32);
    long id_guess = atol(buffer_guess);
    if (gCommandState65eb8_guess->HasMacro_guess(id_guess)) {
        packet_guess.type_40_guess = 3;
        packet_guess.value_84_guess = gCommandState65eb8_guess->GetValue_guess();
        packet_guess.id_88_guess = id_guess;
        gCommandState65eb8_guess->Apply_guess(id_guess, -1);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_VoiceMacroIn, &packet_guess, 0x8c, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x1787, packet_guess.text_44_guess,
                                       (const char*)gCommandState65eb8_guess->GetCount_guess(id_guess),
                                       0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x147, true);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x1782, 0), 0xf, true);
    }
}

// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z
// EXTERNAL: TITANIUM 0x0060E450 strcpy

struct ReportText_guess : CXStr {
    using CXStr::operator=;
    // EXTERNAL: TITANIUM 0x00572060 ReportText_guess::AppendChar_guess
    void AppendChar_guess(char value_guess);
    // EXTERNAL: TITANIUM 0x00572C10 ReportText_guess::AppendText_guess
    void AppendText_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x00572570 ReportText_guess::Truncate_guess
    void Truncate_guess(int length_guess, int flags_guess);
};

struct ReportSource_guess {
    // EXTERNAL: TITANIUM 0x004F2E69 ReportSource_guess::GetAllVisibleText_guess
    CXStr GetAllVisibleText_guess(CXStr text_guess);
};
#define gReportSource_guess EQ_GLOBAL(ReportSource_guess*, 0x009917E4)
#define gReportState_guess EQ_GLOBAL(int, 0x00923788)

// pCharData (0x00905D00) is an EQ_PC: the profile is a virtual base at +0xC384, reached through the vbptr at +8.
struct PcPrefix46_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct CharBase46_guess {
    void* vftable_guess;                  // +0x00
    PropertyLocator_guess locator_guess;  // +0x04: GetCharInfo2 gets this+4
    char pad_05_guess[0x7C - 0x05];
    unsigned char flag_07c_guess;         // +0x7C
    PropertyData_guess* GetInfo_guess() { return locator_guess.GetCharInfo2(); }
};

struct PcView46_guess : PcPrefix46_guess, virtual CharBase46_guess {
    char pad_0C_guess[0xC384 - 0x0C];
};
#define gPcView46_guess EQ_GLOBAL(PcView46_guess*, 0x00905D00)

struct TimerBase46_guess {
    void* vftable_guess;
    PropertyLocator_guess locator_guess;
    char pad_05_043_guess[0x44 - 0x05 - 8];
    char name_044_guess[0x38];
    char pad_07c_083_guess[8];
};

struct TimerView46_guess : PcPrefix46_guess, virtual TimerBase46_guess {
    char pad_00c_e17_guess[0xE18 - 0x0C];
    long time_e18_guess;
    char pad_e1c_e1f_guess[4];
    unsigned int minutes_e20_guess;
    char pad_e24_1a17_guess[0x1A18 - 0xE24];
    int days_1a18_guess;
    char pad_1a1c_c383_guess[0xC384 - 0x1A1C];
};
#define gTimerView46_guess EQ_GLOBAL(TimerView46_guess*, 0x00905D00)

struct EverQuestCall_46_guess {
    // EXTERNAL: TITANIUM 0x00493E92 EverQuestCall_46_guess::ConfirmLastName_guess
    void ConfirmLastName_guess(const char* text_guess);
};
#define gEverQuestCall_46_guess EQ_GLOBAL(EverQuestCall_46_guess*, 0x00988DF0)

// /surname [name]: level 20 or more (0x328C); with no name and a surname set (+0x7C), asks to clear
// it (popup 0x75, 0x1423, 10 s); over 31 characters prints 0x8BF. The result of strlen is unused (kept).
// FUNCTION: TITANIUM 0x0046EB07
void __cdecl do_surname_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x20];
    if (gPcView46_guess->GetInfo_guess()->level_11a4_guess < 0x14) {
        pEverQuest->dsp_chat(pStringTable->getString(0x328c, 0), 0xf, true);
        return;
    }
    if (*text_guess == '\0') {
        if (gPcView46_guess->flag_07c_guess == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x328d, 0), 0xf, true);
            return;
        }
        pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x75,
                                                pStringTable->getString(0x1423, 0), 0xc, 10000, 0, true);
        return;
    }
    int length_guess = (int)strlen(text_guess);
    if (length_guess > 0x1f) {
        pEverQuest->dsp_chat(pStringTable->getString(0x8bf, 0), 0xf, true);
        return;
    }
    GrabFirstWord_guess(text_guess, buffer_guess, 0x14);
    FUN_00574a30_guess(buffer_guess, 0x1f);
    strlen(buffer_guess);
    gEverQuestCall_46_guess->ConfirmLastName_guess(buffer_guess);
}

// /report <name>: once per report state (0x923788 == 1, then 2) sends OP_Report (0x7F9D) as
// 'name|you|<0x4F2E69 text>' (probably the recent chat), capped at 0x2004 bytes; else 0x3291.
// FUNCTION: TITANIUM 0x0046EC2E
void __cdecl do_report_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x200];
    if (*text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x328f, 0), 0xf, true);
    } else if (gReportState_guess == 1) {
        gReportState_guess = 2;
        ReportText_guess report_guess;
        ReportText_guess extra_guess;
        report_guess = text_guess;
        report_guess.AppendChar_guess('|');
        report_guess += g_stateHolder_guess->text_044_guess +
                        g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess;
        report_guess.AppendChar_guess('|');
        report_guess.AppendText_guess(gReportSource_guess->GetAllVisibleText_guess(extra_guess));
        int length_guess = strlen(report_guess) + 1;
        if (length_guess > 0x2004) {
            report_guess.Truncate_guess(0x2004, 0);
        }
        char* copy_guess = new char[(report_guess.Ptr != 0 ? report_guess.Ptr->length : 0) + 1];
        if (copy_guess != 0) {
            strcpy(copy_guess, report_guess);
            int size_guess = strlen(copy_guess);
            SendMessage_guess(&gSendTarget_guess, OP_Report, copy_guess, size_guess + 1, 1);
            delete[] copy_guess;
        }
        build_token_string_PARAM_guess(buffer_guess, 0x3290, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xf, true);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x3291, 0), 0xf, true);
    }
}

// /lastname <player> <surname> (GM-only): OP_GMLastName (0x23A1), echoed with 0x3299.
// FUNCTION: TITANIUM 0x0046EE28
void __cdecl do_lastname_guess(int unused_guess, const char* text_guess) {
    char message_guess[0x100];
    MessagePacket_46ee28_guess packet_guess;
    char first_guess[0x40];
    char second_guess[0x20];

    memset(&packet_guess, 0, sizeof(packet_guess));
    if (text_guess == 0 || *text_guess == '\0') {
        gGlobalContext_guess->SetText_guess(pStringTable->getString(0x3298, 0), 0xf, 1);
    } else {
        int parsed_guess = GrabFirstWord_guess(text_guess, first_guess, 0x40);
        GrabFirstWord_guess((const char*)parsed_guess, second_guess, 0x20);
        FUN_0060e450_guess(packet_guess.text_000_guess, first_guess);
        FUN_0060e450_guess(packet_guess.text_040_guess, gConnection_guess->text_120_guess);
        FUN_0060e450_guess(packet_guess.text_080_guess, second_guess);
        packet_guess.value_0c4_guess = 0;
        FUN_004912b1_guess(&gSendTarget_guess, OP_GMLastName, &packet_guess, 0xc8, 1);
        build_token_string_PARAM_guess(message_guess, 0x3299, first_guess, second_guess,
                                       0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(message_guess, 0xd, 1);
    }
}

// /changename <name>: 4-14 characters; asks to confirm (popup 0x7B, 10 s) with a heap copy of
// the name as the popup's data.
// FUNCTION: TITANIUM 0x0046EF2F
void __cdecl do_changename_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x200];
    char name_guess[0x40];
    if (*text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x1752, 0), 0xf, true);
        return;
    }
    int length_guess = (int)strlen(text_guess);
    if (length_guess < 4) {
        pEverQuest->dsp_chat(pStringTable->getString(0x175f, 0));
        return;
    }
    if (length_guess > 14) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1754, 0), 0xf, true);
        return;
    }
    GrabFirstWord_guess(text_guess, name_guess, 0x14);
    FUN_00574a30_guess(name_guess, 0x3f);
    build_token_string_PARAM_guess(buffer_guess, 0x1753, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    char* copy_guess = (char*)operator new[](strlen(name_guess) + 1);
    strcpy(copy_guess, name_guess);
    pConfirmationDialogPool_guess->Activate(pEverQuest ? &pEverQuest->vftable_08 : 0, 0x7b,
                                            buffer_guess, 0xc, 10000, (int)copy_guess, 1);
}

struct ChatMessage_46_guess {
    char text_guess[0x40];
    char name_guess[0x41];
};

// /kick [name] (GM-only, slash table 0x78B658): OP_GMKick (0x692C) for the name or the target, echoed
// with 0x329F.
// FUNCTION: TITANIUM 0x0046F041
void __cdecl do_kick_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x80];
    ChatMessage_46_guess message_guess;
    memset(&message_guess, 0, 0x81);
    if (strcmp(text_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
        strcpy(message_guess.text_guess, text_guess);
        strcpy(message_guess.name_guess, gConnection_guess->text_120_guess);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GMKick, &message_guess, 0x81, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x329f, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xd, true);
    } else {
        if (gIncomingMessage_guess == 0) {
            return;
        }
        strcpy(message_guess.text_guess, gIncomingMessage_guess->text_120_guess);
        strcpy(message_guess.name_guess, gConnection_guess->text_120_guess);
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GMKick, &message_guess, 0x81, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x329f, gIncomingMessage_guess->text_120_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xd, true);
    }
}

// EXTERNAL: TITANIUM 0x0047C88E GetSpawnByName_guess
IncomingMessage_guess* __cdecl GetSpawnByName_guess(const char* name_guess);

struct ZoneRequest_guess {
    char pad_000_guess[0x40];
    int zone_040_guess;
    char pad_044_guess[0x14];
};

#define gZoneRequest_guess EQ_GLOBAL(int, 0x0092467C)
#define gZoneState_guess EQ_GLOBAL(int, 0x00924678)

// EXTERNAL: TITANIUM 0x0060F3DC isdigit
extern "C" int __cdecl isdigit(int value);

// /zone <name|id> (GM-only): OP_GMZoneRequest (0x1306), then pumps messages until the reply sets
// 0x924678 (-5 pending). Success sends OP_GMZoneRequest2 (0x244C); -2/-3/-6/-7 print their own
// strings, anything else 0x32A0.
// FUNCTION: TITANIUM 0x0046F157
// @early-stop: budget, structural ndiff=25
void __cdecl do_switchzone_guess(int unused_guess, const char* zone_guess) {
    if (*zone_guess == '\0') {
        gGlobalContext_guess->FUN_00492968_guess();
        return;
    }
    if (strlen(zone_guess) < 1 || strlen(zone_guess) > 0x1f) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3295, 0));
        return;
    }
    FUN_00574110_guess("in do_switchzone, getting safe coords\n");
    ZoneRequest_guess request_guess;
    char message_guess[0x100];
    char text_guess[0x200];
    int start_guess;
    int zoneId_guess;
    char changed_guess = 0;
    memset(&request_guess, 0, sizeof(request_guess));
    if (isdigit(*zone_guess) != 0) {
        zoneId_guess = atol(zone_guess);
    } else {
        zoneId_guess = gGate_guess->FUN_005f6f20_guess(zone_guess);
    }
    if (zoneId_guess == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3295, 0));
        return;
    }
    sprintf(message_guess, "zone %s converted to id %d\n", zone_guess, zoneId_guess);
    FUN_00574110_guess(message_guess);
    request_guess.zone_040_guess = zoneId_guess;
    gZoneRequest_guess = zoneId_guess;
    start_guess = (int)EqGetTime();
    gZoneState_guess = -5;
    EQSendMessage(&gSendTarget_guess, OP_GMZoneRequest, &request_guess, 0x58, 1);
    do {
        gGlobalContext_guess->ProcessMBox_guess();
        if (gZoneState_guess == 1) {
            gZoneRequest_guess = 0;
            break;
        }
        if (gZoneState_guess != -5) {
            changed_guess = true;
        }
        int now_guess = (int)EqGetTime();
        // Gives up after 60 seconds.
        if (60000u < (unsigned int)(now_guess - start_guess)) {
            break;
        }
        Sleep(10);
    } while (!changed_guess);
    if (gZoneState_guess == 1) {
        EQSendMessage(&gSendTarget_guess, OP_GMZoneRequest2, &zoneId_guess, 4, 1);
        return;
    }
    if (gZoneState_guess == -2) {
        pEverQuest->dsp_chat(pStringTable->getString(0x13b9, 0), 0xd, true);
    } else if (gZoneState_guess == -3) {
        pEverQuest->dsp_chat(pStringTable->getString(0x13ba, 0), 0xd, true);
    } else if (gZoneState_guess == -6) {
        pEverQuest->dsp_chat(pStringTable->getString(0x13bc, 0), 0xd, true);
    } else if (gZoneState_guess == -7) {
        pEverQuest->dsp_chat(pStringTable->getString(0xfc, 0), 0xd, true);
    } else {
        build_token_string_PARAM_guess(text_guess, 0x32a0, zone_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(text_guess, 0xd, true);
    }
    gGlobalContext_guess->SavePC_guess(0, 1, 0x1f);
}

// /kill [name] (GM-only): an NPC (+0x244 != 0) gets OP_GMKill (0x6980); a PC or an unknown name goes
// to 0x493FC0 instead.
// FUNCTION: TITANIUM 0x0046F379
void __cdecl do_kill_guess(int unused_guess, const char* name_guess) {
    char buffer_guess[0x80];
    char message_guess[0x81];
    memset(message_guess, 0, sizeof(message_guess));
    if (strcmp(name_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
        IncomingMessage_guess* incoming_guess = GetSpawnByName_guess(name_guess);
        if (incoming_guess != 0 && incoming_guess->byte_244_guess != 0) {
            strcpy(message_guess, name_guess);
            strcpy(message_guess + 0x40, gConnection_guess->text_120_guess);
            EQSendMessage(&gSendTarget_guess, OP_GMKill, message_guess, sizeof(message_guess), 1);
            build_token_string_PARAM_guess(buffer_guess, 0x32a1, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0xd, true);
            return;
        }
        gGlobalContext_guess->ConfirmKill_guess(name_guess, gConnection_guess->text_120_guess);
        return;
    }
    if (!gIncomingMessage_guess) {
        return;
    }
    if (gIncomingMessage_guess->byte_244_guess == 0) {
        gGlobalContext_guess->ConfirmKill_guess(gIncomingMessage_guess->text_120_guess,
                                                 gConnection_guess->text_120_guess);
    } else {
        build_token_string_PARAM_guess(buffer_guess, 0x32a1, gIncomingMessage_guess->text_120_guess, 0, 0, 0, 0, 0,
                                       0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xd, true);
        strcpy(message_guess, gIncomingMessage_guess->text_120_guess);
        strcpy(message_guess + 0x40, gConnection_guess->text_120_guess);
        EQSendMessage(&gSendTarget_guess, OP_GMKill, message_guess, sizeof(message_guess), 1);
    }
}

struct SizeSpawn_46f512_guess {
    char pad_000_guess[0x120];
    char name_120_guess[0x40];
    char pad_160_guess[0xdc];
    float size_23c_guess;
    char pad_240_guess[0x18];
    unsigned short id_258_guess;
    // EXTERNAL: TITANIUM 0x00481D5D SizeSpawn_46f512_guess::SetAvatarHeight_guess
    void SetAvatarHeight_guess(float size_guess);
};

struct SizePacket_46f512_guess {
    unsigned short id_guess;
    unsigned short type_guess;
    int value_guess;
};

#define gSizeTarget_46f512_guess EQ_GLOBAL(SizeSpawn_46f512_guess*, 0x00905D04)
#define gSizeLocal_46f512_guess EQ_GLOBAL(SizeSpawn_46f512_guess*, 0x00905CE4)
#define gSizeFlag_46f512_guess EQ_GLOBAL(char, 0x00923798)
#define gSizeMode_46f512_guess EQ_GLOBAL(int, 0x00923884)
#define gSizeOld_46f512_guess EQ_ARRAY(char, 0x0099DB00)
#define gSizeNew_46f512_guess EQ_ARRAY(char, 0x0099DAE0)

// /height <size> (GM-only): resizes the target, or yourself, with OP_SpawnAppearance (0x7C32,
// type 0x1D, size cut to an int). While 0x923798 or 0x923884 is set (the pair /becomenpc also
// checks) the size is only applied locally.
// FUNCTION: TITANIUM 0x0046F512
void __cdecl do_height_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x200];
    SizePacket_46f512_guess packet_guess;
    SizeSpawn_46f512_guess* spawn_guess = gSizeTarget_46f512_guess;
    float size_guess = (float)atof(text_guess);
    if (spawn_guess == 0) {
        spawn_guess = gSizeLocal_46f512_guess;
    }
    if (!(size_guess <= 0.0f)) {
        if (gSizeFlag_46f512_guess == 0 && gSizeMode_46f512_guess == 0) {
            sprintf(gSizeOld_46f512_guess, "%f", spawn_guess->size_23c_guess);
            sprintf(gSizeNew_46f512_guess, "%f", size_guess);
            build_token_string_PARAM_guess(buffer_guess, 0x32a4, spawn_guess->name_120_guess,
                                           gSizeOld_46f512_guess, gSizeNew_46f512_guess, 0, 0, 0, 0, 0, 0);
            gGlobalContext_guess->dsp_chat(buffer_guess);
            packet_guess.id_guess = spawn_guess->id_258_guess;
            packet_guess.type_guess = 0x1d;
            packet_guess.value_guess = (int)size_guess;
            FUN_004912b1_guess(EQ_ARRAY(int, 0x00905CA0), OP_SpawnAppearance, &packet_guess, 8, 1);
        } else {
            sprintf(gSizeOld_46f512_guess, "%f", spawn_guess->size_23c_guess);
            sprintf(gSizeNew_46f512_guess, "%f", size_guess);
            build_token_string_PARAM_guess(buffer_guess, 0x32a3, spawn_guess->name_120_guess,
                                           gSizeOld_46f512_guess, gSizeNew_46f512_guess, 0, 0, 0, 0, 0, 0);
            gGlobalContext_guess->dsp_chat(buffer_guess);
            spawn_guess->SetAvatarHeight_guess(size_guess);
        }
    }
}

// /motd: reprints eqstr 0x32A5 with the text kept at 0x923F98.
// FUNCTION: TITANIUM 0x0046F698
void __cdecl do_motd_guess(void) {
    char buffer_guess[0x400];
    build_token_string_PARAM_guess(buffer_guess, 0x32a5, g_zoneName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    gGlobalContext_guess->SetText_guess(buffer_guess, 0xf, 1);
}

// /charinfo: 'You are currently bound in: %1' (0x32A7).
// FUNCTION: TITANIUM 0x0046F6EC
void __cdecl do_charinfo_guess(void) {
    if (g_stateHolder_guess != 0 && gGate_guess != 0) {
        char name_guess[0x50];
        char buffer_guess[0x400];
        gGate_guess->GetName_guess(g_stateHolder_guess->FUN_005f0760_guess(0), name_guess, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x32a7, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->dsp_chat(buffer_guess);
    }
}

// Joins the non-zero days, hours, minutes and seconds (singular/plural eqstr 0x32A9-0x32AE,
// 0x1A1E/0x1A1F) with 0x1A20-0x1A23; all zero gives '0 seconds'.
// FUNCTION: TITANIUM 0x0046F767
void __cdecl GetTimeString_guess(char* buffer_guess, unsigned int value2_guess, unsigned int value3_guess,
                          unsigned int value4_guess, unsigned int value5_guess) {
    char text5_guess[64];
    char text4_guess[64];
    char text3_guess[64];
    char text2_guess[64];
    const char* parts_guess[4];
    int count_guess;

    if (buffer_guess != 0) {
        if (value2_guess == 1) {
            build_token_string_PARAM_guess(text2_guess, 0x32a9, __itoa(1, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            build_token_string_PARAM_guess(text2_guess, 0x32aa, __itoa(value2_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        if (value3_guess == 1) {
            build_token_string_PARAM_guess(text3_guess, 0x32ab, __itoa(1, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            build_token_string_PARAM_guess(text3_guess, 0x32ac, __itoa(value3_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        if (value4_guess == 1) {
            build_token_string_PARAM_guess(text4_guess, 0x32ad, __itoa(1, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            build_token_string_PARAM_guess(text4_guess, 0x32ae, __itoa(value4_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        if (value5_guess == 1) {
            build_token_string_PARAM_guess(text5_guess, 0x1a1e, __itoa(1, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            build_token_string_PARAM_guess(text5_guess, 0x1a1f, __itoa(value5_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        }

        count_guess = 0;
        parts_guess[3] = 0;
        parts_guess[2] = 0;
        parts_guess[1] = 0;
        parts_guess[0] = 0;
        if (value5_guess > 0) {
            parts_guess[count_guess] = text5_guess;
            count_guess = count_guess + 1;
        }
        if (value4_guess > 0) {
            parts_guess[count_guess] = text4_guess;
            count_guess = count_guess + 1;
        }
        if (value3_guess > 0) {
            parts_guess[count_guess] = text3_guess;
            count_guess = count_guess + 1;
        }
        if (value2_guess > 0) {
            parts_guess[count_guess] = text2_guess;
            count_guess = count_guess + 1;
        }

        if (count_guess == 4) {
            build_token_string_PARAM_guess(buffer_guess, 0x1a23, parts_guess[3], parts_guess[2], parts_guess[1],
                                           parts_guess[0], 0, 0, 0, 0, 0);
        } else if (count_guess == 3) {
            build_token_string_PARAM_guess(buffer_guess, 0x1a22, parts_guess[2], parts_guess[1], parts_guess[0],
                                           0, 0, 0, 0, 0, 0);
        } else if (count_guess == 2) {
            build_token_string_PARAM_guess(buffer_guess, 0x1a21, parts_guess[1], parts_guess[0], 0, 0, 0, 0, 0, 0, 0);
        } else if (count_guess == 1) {
            build_token_string_PARAM_guess(buffer_guess, 0x1a20, parts_guess[0], 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            build_token_string_PARAM_guess(buffer_guess, 0x1a20, text5_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    }
}

// Writes `seconds` as days, hours, minutes and seconds text (0x0046F767); the item display shows
// durations with it.
// FUNCTION: TITANIUM 0x0046F97F
void __cdecl GetTimeStringFromSeconds_guess(char* buffer_guess, int seconds_guess) {
    GetTimeString_guess(buffer_guess, seconds_guess / 86400, (seconds_guess % 86400) / 3600, (seconds_guess % 3600) / 60,
                 seconds_guess % 60);
}

// EXTERNAL: TITANIUM 0x00576E80 GetClientTime_guess
int __cdecl GetClientTime_guess();

// EXTERNAL: TITANIUM 0x00612227 localtime
// EXTERNAL: TITANIUM 0x006120B4 wcsftime

#define gClockStart_guess EQ_GLOBAL(int, 0x00988C20)
#define gTimerFlag_guess EQ_GLOBAL(char, 0x0099140C)
#define gTimerEnd_guess EQ_GLOBAL(int, 0x00991410)

struct DateText_guess {
    void* Ptr_guess;
    // EXTERNAL: TITANIUM 0x00571F00 DateText_guess::DateText_guess
    DateText_guess(const wchar_t* text_guess);
    // EXTERNAL: TITANIUM 0x00571E00 ??0DateText_guess@@QAE@PBD@Z
    DateText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x005722D0 DateText_guess::FUN_005722d0_guess
    void FUN_005722d0_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00572300 ??BDateText_guess@@QBEPADXZ
    operator char*() const;
    // EXTERNAL: TITANIUM 0x00571D00 DateText_guess::FreeRep
    void FreeRep(void* rep_guess);
    ~DateText_guess() {
        if (Ptr_guess != 0) {
            FreeRep(Ptr_guess);
        }
        Ptr_guess = 0;
    }
};

#define gIgnoreList_guess EQ_ARRAY(char, 0x0095BAB4)
#define gServerNameListEnd_472739_guess EQ_ARRAY(char, 0x0095D3B4)

// /played output: birth date (0x32A8), total play time from minutes (0x32AF), this session
// (0x1A1B), the timer at 0x991410 while 0x99140C is set (0x1A1C), and age in years (0xE24).
// FUNCTION: TITANIUM 0x0046F9CB
void __cdecl ShowPlayedTime_guess(const char* name_guess, long time_guess, unsigned int minutes_guess, int days_guess) {
    char buffer_guess[0x200];
    char duration_guess[0x200];
    char years_guess[0x100];
    wchar_t date_guess[0x80];

    wcsftime(date_guess, 0x100, L"%#c", localtime(&time_guess));
    DateText_guess dateText_guess(date_guess);
    dateText_guess.FUN_005722d0_guess(0);
    build_token_string_PARAM_guess(buffer_guess, 0x32a8, name_guess, dateText_guess, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);

    unsigned int rest_guess = minutes_guess % 1440;
    GetTimeString_guess(duration_guess, minutes_guess / 1440, rest_guess / 60, rest_guess % 60, 0);
    build_token_string_PARAM_guess(buffer_guess, 0x32af, name_guess, duration_guess, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);

    GetTimeStringFromSeconds_guess(duration_guess, GetClientTime_guess() - gClockStart_guess);
    build_token_string_PARAM_guess(buffer_guess, 0x1a1b, duration_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);

    if (gTimerFlag_guess != 0) {
        int timerEnd_guess = gTimerEnd_guess;
        GetTimeStringFromSeconds_guess(duration_guess, timerEnd_guess - GetClientTime_guess());
        build_token_string_PARAM_guess(buffer_guess, 0x1a1c, duration_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess);
    }

    // Days / 365.
    sprintf(years_guess, "%-0.1f", (double)((float)days_guess * 0.002739726f));
    build_token_string_PARAM_guess(buffer_guess, 0xe24, years_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);
}

// Shows the /played text (0x0046F9CB) from the character's name, birth date, minutes played and
// +0x1A18.
// FUNCTION: TITANIUM 0x0046FBF0
void __cdecl do_played_guess() {
    ShowPlayedTime_guess(gTimerView46_guess->name_044_guess,
                 gTimerView46_guess->time_e18_guess,
                 gTimerView46_guess->minutes_e20_guess,
                 gTimerView46_guess->days_1a18_guess);
}

struct FriendName_guess {
    char name_guess[0x40];
};
struct FriendsList_guess {
    FriendName_guess names_guess[100];
};
#define gFriendsList_guess EQ_GLOBAL(FriendsList_guess, 0x0095A1B4).names_guess

struct IgnoreOwner_guess {
    // EXTERNAL: TITANIUM 0x004AB7F1 IgnoreOwner_guess::ProcessLocalPCIni_guess
    void ProcessLocalPCIni_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004AB692 IgnoreOwner_guess::Refresh_guess
    void Refresh_guess();
};
#define gIgnoreOwner_guess EQ_GLOBAL(IgnoreOwner_guess*, 0x00988DF0)

// /ignore [name]: lists, removes or adds (100 names of 0x40 bytes); GMs (+0x256) can't be ignored
// (0x33BA). gIgnoreList_guess is 0x95BAB4.
// FUNCTION: TITANIUM 0x00472739
// @early-stop: budget, structural ndiff=67
void __cdecl do_ignore_guess(int unused_guess, char* input_guess) {
    if (input_guess[0] == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x33b8, 0), 0xd, true);
        char* name_guess = gIgnoreList_guess;
        do {
            if (name_guess[0] != 0) {
                pEverQuest->dsp_chat(name_guess, 0xf, true);
            }
            name_guess += 0x40;
        } while (name_guess < gServerNameListEnd_472739_guess);
    } else {
        CXStr dateText_guess(input_guess);
        char buffer_guess[0x100];
        ConvertItemTags(&dateText_guess, 0);
        input_guess = dateText_guess;

        int foundIndex_guess = -1;
        int emptyIndex_guess = -1;
        int index_guess = 0;
        char* entry_guess = gIgnoreList_guess;
        do {
            if (__stricmp(entry_guess, input_guess) == 0) {
                foundIndex_guess = index_guess;
            }
            if (entry_guess[0] == 0) {
                emptyIndex_guess = index_guess;
            }
            entry_guess += 0x40;
            ++index_guess;
        } while (entry_guess < gServerNameListEnd_472739_guess);

        const char* message_guess;
        if (foundIndex_guess >= 0) {
            gIgnoreList_guess[foundIndex_guess * 0x40] = 0;
            gIgnoreOwner_guess->ProcessLocalPCIni_guess(0);
            build_token_string_PARAM_guess(buffer_guess, 0x33b9, input_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            message_guess = buffer_guess;
        } else if (emptyIndex_guess < 0) {
            char* number_guess = __itoa(100, EQ_ARRAY(char, 0x0099DB00), 10);
            build_token_string_PARAM_guess(buffer_guess, 0x33bc, number_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            message_guess = buffer_guess;
        } else {
            IncomingMessage_guess* incoming_guess = GetSpawnByName_guess(input_guess);
            if (incoming_guess == 0 || incoming_guess->byte_256_guess == 0) {
                FUN_0060e450_guess(gIgnoreList_guess + emptyIndex_guess * 0x40,
                                   input_guess);
                gIgnoreOwner_guess->ProcessLocalPCIni_guess(0);
                build_token_string_PARAM_guess(buffer_guess, 0x33bb, input_guess,
                                               0, 0, 0, 0, 0, 0, 0, 0);
                message_guess = buffer_guess;
            } else {
                message_guess = pStringTable->getString(0x33ba, 0);
            }
        }
        pEverQuest->dsp_chat(message_guess, 0xf, true);
    }

    if (pinstCFriendsWnd_guess != 0) {
        pinstCFriendsWnd_guess->RefreshIgnoreList_guess();
    }
    if (gGlobalContext_guess != 0 && gGlobalContext_guess->GetMailManager_guess() != 0) {
        gGlobalContext_guess->GetMailManager_guess()->FUN_0042b34a_guess();
    }
}

template <class T, unsigned int N>
struct BoundedArray_475855_guess {
    T data[N];
    T& operator[](int index_guess) {
        if ((unsigned int)index_guess >= N) {
            __debugbreak();
        }
        return data[index_guess];
    }
};

struct Table_475855_guess {
    char pad_000_guess[0x24];
    int value_24_guess;
    char pad_028_guess[0x30 - 0x28];
    BoundedArray_475855_guess<int, 12> values_30_guess;
    char pad_060_guess[0x90 - 0x60];
    BoundedArray_475855_guess<int, 12> values_90_guess;
    char pad_0c0_guess[0xf0 - 0xc0];
    BoundedArray_475855_guess<int, 12> values_f0_guess;
    BoundedArray_475855_guess<int, 12> values_120_guess;
    char pad_150_guess[0x18c - 0x150];
    int stringId_18c_guess;
    // EXTERNAL: TITANIUM 0x0044E755 Table_475855_guess::GetSpellLevelNeeded_guess
    unsigned char GetSpellLevelNeeded_guess(int index_guess);
};

struct DatabaseStringManager_475855_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DatabaseStringManager_475855_guess::GetString_guess
    char* GetString_guess(int index_guess, int category_guess, int flags_guess);
};
#define g_databaseStringManager_475855_guess EQ_GLOBAL(DatabaseStringManager_475855_guess*, 0x00850398)
#define g_playerState_475855_guess EQ_GLOBAL(Holder_474597_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x0060F81E FUN_0060f81e_guess
int __cdecl FUN_0060f81e_guess(int value_guess);

struct CharacterState46_guess {
    char pad_0000_guess[0x119c];
    unsigned char state_119c_guess;
};

struct CharacterPrefix46_guess {
    virtual void PrefixVSlot_guess();
    int field_004_guess;
};

struct CharacterBase46_guess : EQ_Character {
    CHARINFO2* Profile_guess() { return GetCharInfo2(); }
};

struct CharacterTimerOps46_guess : CharacterPrefix46_guess, virtual CharacterBase46_guess {
    char pad_000c_guess[0xc280 - 0x0c];
    int timer_context_c280_guess;

    // EXTERNAL: TITANIUM 0x005F0A00 CharacterTimerOps46_guess::GetTimerId_guess
    int GetTimerId_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004BAC08 CharacterTimerOps46_guess::GetDisciplineTimer_guess
    unsigned int GetDisciplineTimer_guess(unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x004BB39D CharacterTimerOps46_guess::DoCombatAbility
    void DoCombatAbility(int key_guess);
};
#define gCharacterOwner46_guess EQ_GLOBAL(CharacterTimerOps46_guess*, 0x00905D00)

struct TimedEntry46_guess {
    int key_000_guess;
    char pad_004_guess[0x1c0 - 0x04];
    unsigned int value_1c0_guess;
    char pad_1c4_guess[0x208 - 0x1c4];
    const char* name_208_guess;
};

// /discipline [name]: for classes 1, 3-5, 7-9, 15, 16 only (0x16D0). No name lists the running
// discipline timers (0x16AF, or 0x16B0 under an hour); a name prefix passes the matching entry to
// 0x4BB39D, probably to use it.
// FUNCTION: TITANIUM 0x0046FC1B
// @early-stop: budget, structural ndiff=59
void __cdecl do_discipline_guess(int unused_guess, const char* name_guess) {
    char hours_text_guess[0x20];
    char minutes_text_guess[0x20];
    char seconds_text_guess[0x20];
    TimedEntry46_guess* entry_guess;
    unsigned int expires_guess;
    int index_guess;
    unsigned int hours_guess;
    int length_guess;

    if (((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 1 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 7 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 9 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 3 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 4 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 5 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 8 ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 0xf ||
        ((CharacterState46_guess*)gCharacterOwner46_guess->Profile_guess())->state_119c_guess == 0x10) {
        length_guess = (int)strlen(name_guess);
        for (index_guess = 0; index_guess < 100; ++index_guess) {
            if (gCharacterOwner46_guess->GetTimerId_guess(index_guess) != 0) {
                entry_guess = (TimedEntry46_guess*)gKeyLookup_guess->GetKey_guess(
                    gCharacterOwner46_guess->GetTimerId_guess(index_guess));
                if (entry_guess != 0) {
                    if (length_guess < 1) {
                        expires_guess = gCharacterOwner46_guess->GetDisciplineTimer_guess(
                            entry_guess->value_1c0_guess);
                        if (expires_guess > (unsigned int)GetClientTime_guess()) {
                            expires_guess = gCharacterOwner46_guess->GetDisciplineTimer_guess(
                                entry_guess->value_1c0_guess);
                            expires_guess -= GetClientTime_guess();
                            hours_guess = expires_guess / 0xe10;
                            expires_guess %= 0xe10;
                            __itoa((int)hours_guess, hours_text_guess, 10);
                            __itoa((int)(expires_guess / 0x3c), minutes_text_guess, 10);
                            __itoa((int)(expires_guess % 0x3c), seconds_text_guess, 10);
                            if (hours_guess == 0) {
                                FormatTokenStringToClient_guess(
                                    gCharacterOwner46_guess != 0 ? &gCharacterOwner46_guess->timer_context_c280_guess : 0,
                                    0x16b0, 0x10f, entry_guess->name_208_guess, minutes_text_guess,
                                    seconds_text_guess, 0, 0, 0, 0, 0, 0, 0);
                            } else {
                                FormatTokenStringToClient_guess(
                                    gCharacterOwner46_guess != 0 ? &gCharacterOwner46_guess->timer_context_c280_guess : 0,
                                    0x16af, 0x10f, entry_guess->name_208_guess, hours_text_guess,
                                    minutes_text_guess, seconds_text_guess, 0, 0, 0, 0, 0, 0);
                            }
                        }
                    } else if (strnicmp_guess(entry_guess->name_208_guess, name_guess, length_guess) == 0) {
                        gCharacterOwner46_guess->DoCombatAbility(entry_guess->key_000_guess);
                        return;
                    }
                }
            }
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x16d0, 0));
    }
}

// /friends [name]: lists, adds or removes (a known name toggles off) a friend; 100 names of
// 0x40 bytes, 15 characters at most, in gFriendsList_guess (0x95A1B4); the ignore list is
// 0x95BAB4.
// FUNCTION: TITANIUM 0x0046FEFE
void __cdecl do_friends_guess(int unused_guess, char* text_guess) {
    char buffer_guess[0x100];
    int i_guess;
    int count_guess = 0;
    int free_guess = -1;
    if (*text_guess == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x32b3, 0));
        pEverQuest->dsp_chat("-----------------");
        for (i_guess = 0; i_guess < 100; i_guess++) {
            if (gFriendsList_guess[i_guess].name_guess[0] != 0) {
                count_guess++;
                pEverQuest->dsp_chat(gFriendsList_guess[i_guess].name_guess);
            }
        }
        if (count_guess == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x32b1, 0));
            pEverQuest->dsp_chat(pStringTable->getString(0x32b2, 0));
        } else {
            build_token_string_PARAM_guess(buffer_guess, 0x32b4, __itoa(count_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess);
        }
    } else {
        DateText_guess name_guess(text_guess);
        ConvertItemTags((CXStr*)&name_guess, 0);
        text_guess = name_guess;
        if (strlen(text_guess) > 15) {
            pEverQuest->dsp_chat(pStringTable->getString(0x32b5, 0), 0xd, 1);
            return;
        }
        for (i_guess = 0; i_guess < 100; i_guess++) {
            if (gFriendsList_guess[i_guess].name_guess[0] == 0) {
                free_guess = i_guess;
            } else if (__stricmp(gFriendsList_guess[i_guess].name_guess, text_guess) == 0) {
                build_token_string_PARAM_guess(buffer_guess, 0x32b6, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buffer_guess);
                gFriendsList_guess[i_guess].name_guess[0] = 0;
                gIgnoreOwner_guess->ProcessLocalPCIni_guess(0);
                if (pinstCFriendsWnd_guess != 0) {
                    pinstCFriendsWnd_guess->RefreshFriendsList_guess();
                    gIgnoreOwner_guess->Refresh_guess();
                }
                return;
            }
        }
        if (free_guess == -1) {
            build_token_string_PARAM_guess(buffer_guess, 0x32b7, __itoa(100, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess);
            return;
        }
        FUN_0060e450_guess(gFriendsList_guess[free_guess].name_guess, text_guess);
        build_token_string_PARAM_guess(buffer_guess, 0x32b8, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess);
        gIgnoreOwner_guess->ProcessLocalPCIni_guess(0);
        gIgnoreOwner_guess->Refresh_guess();
    }
    if (pinstCFriendsWnd_guess != 0) {
        pinstCFriendsWnd_guess->RefreshFriendsList_guess();
    }
}

#define gMoneyTokenMode_guess EQ_GLOBAL(int, 0x00923D74)
#define gPlatinumDigits_guess EQ_ARRAY(char, 0x0099DB00)
#define gGoldDigits_guess EQ_ARRAY(char, 0x0099DAE0)
#define gSilverDigits_guess EQ_ARRAY(char, 0x0099DF60)
#define gCopperDigits_guess EQ_ARRAY(char, 0x0099DB40)

// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section_guess, const char* key_guess, const char* value_guess);

#define gSkinFlagA_guess EQ_GLOBAL(char, 0x00988C77)
#define gSkinFlagB_guess EQ_GLOBAL(char, 0x00988C78)

// /bazaar: opens the bazaar window.
// FUNCTION: TITANIUM 0x0046BD61
void __cdecl do_bazaar_guess(int enabled_guess) {
    if (enabled_guess != 0) {
        if (pinstCBazaarSearchWnd_guess->IsVisible_guess() == 0) {
            pinstCBazaarSearchWnd_guess->Activate();
        }
    }
}

// /trader: opens the trader window.
// FUNCTION: TITANIUM 0x0046BD86
void __cdecl do_trader_guess(int enabled_guess) {
    if (enabled_guess != 0) {
        if (pinstCBazaarWnd_guess->IsVisible_guess() == 0) {
            pinstCBazaarWnd_guess->Activate();
        }
    }
}

// /stopsong: bards (class 8) only; readies the player (0x47E8E0) and stops the current song.
// FUNCTION: TITANIUM 0x0047020E
void __cdecl do_stopsong_guess(int target_guess) {
    if (gCommandState_472156_guess->action_004_guess.Find_guess()->mode_119c_guess == 8) {
        if (target_guess != 0) {
            ((CommandTarget_472156_guess*)target_guess)->Prepare_guess();
        }
        gCommandState_472156_guess->command_c280_guess.Handle_guess(0);
    }
}

#define gLootNoDrop_guess EQ_GLOBAL(int, 0x009254E0)

struct LootActor_47024F_guess {
    char pad_000_guess[0x218];
    int field_218_guess;            // 0x218
};

// /lootnodrop [never|sometimes|always]
// /lootnodrop [never|sometimes|always|0-2]: NO DROP loot confirmation, saved as
// [Options] LootNoDrop; no argument shows the choice (0x32BE) and the current one.
// FUNCTION: TITANIUM 0x0047024F
void __cdecl do_lootnodrop_guess(LootActor_47024F_guess* actor_guess, const char* text_guess) {
    char buffer_guess[0x100];
    int active_guess = 0;
    if (actor_guess != 0) {
        active_guess = actor_guess->field_218_guess;
    }
    if (gLootNoDrop_guess > 2 || gLootNoDrop_guess < 0) {
        gLootNoDrop_guess = 0;
    }
    if (*text_guess == '\0') {
        if (active_guess == 0) {
            return;
        }
        build_token_string_PARAM_guess(buffer_guess, 0x32be,
                                       gTextLookup_guess->FindText_guess(0x32bb, 0),
                                       gTextLookup_guess->FindText_guess(0x32bc, 0),
                                       gTextLookup_guess->FindText_guess(0x32bd, 0),
                                       0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->dsp_chat(buffer_guess);
        FUN_0060e450_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32bf, 0));
        switch (gLootNoDrop_guess) {
        case 0:
            FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c0, 0));
            break;
        case 1:
            FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c1, 0));
            break;
        case 2:
            FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c2, 0));
            break;
        default:
            buffer_guess[0] = '\0';
            break;
        }
        gGlobalContext_guess->dsp_chat(buffer_guess);
        return;
    }
    FUN_0060e450_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c3, 0));
    if (FUN_00574990_guess(text_guess, gTextLookup_guess->FindText_guess(0x32bd, 0), 4) == 0 ||
        *text_guess == '2') {
        FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c2, 0));
        gLootNoDrop_guess = 2;
        gGlobalContext_guess->dsp_chat(buffer_guess);
    } else if (FUN_00574990_guess(text_guess, gTextLookup_guess->FindText_guess(0x32bc, 0), 4) == 0 ||
               *text_guess == '1') {
        FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c1, 0));
        gLootNoDrop_guess = 1;
        gGlobalContext_guess->dsp_chat(buffer_guess);
    } else if (FUN_00574990_guess(text_guess, gTextLookup_guess->FindText_guess(0x32bb, 0), 4) == 0 ||
               *text_guess == '0') {
        FUN_0060e460_guess(buffer_guess, gTextLookup_guess->FindText_guess(0x32c0, 0));
        gLootNoDrop_guess = 0;
        gGlobalContext_guess->dsp_chat(buffer_guess);
    }
    gGlobalContext_guess->WriteInt_guess(gLootNoDrop_guess, "Options", "LootNoDrop");
}

struct ChannelList_4704c1_guess {
    // EXTERNAL: TITANIUM 0x0040C027 ChannelList_4704c1_guess::Find_guess
    int Find_guess(const char* name_guess);
};

struct ChannelListB_4704c1_guess {
    // EXTERNAL: TITANIUM 0x005FF6A0 ChannelListB_4704c1_guess::Find_guess
    int Find_guess(const char* name_guess);
};

struct ChatLists_4704c1_guess {
    char pad_000_guess[0x290];
    ChannelList_4704c1_guess* list_290_guess;
    char pad_294_guess[0x834 - 0x294];
    ChannelListB_4704c1_guess* list_834_guess;
};

struct ChatOwner_4704c1_guess {
    // EXTERNAL: TITANIUM 0x004F288C ChatOwner_4704c1_guess::GetActiveChatWindow_guess
    Record_guess* GetActiveChatWindow_guess();
};

#define gChatLists_4704c1_guess EQ_GLOBAL(ChatLists_4704c1_guess*, 0x00988DF0)
#define gChatOwner_4704c1_guess EQ_GLOBAL(ChatOwner_4704c1_guess*, 0x009917E4)
#define gChatType_guess EQ_GLOBAL(unsigned char, 0x009237EC)
#define gChatChannel_guess EQ_ARRAY(char, 0x009237F4)

// Sets the default chat channel from /chatdefault <channel> [name].
// /channel <guild|group|raid|tell <name>|auction|ooc|shout|chat <name>> (the line above says
// /chatdefault; the table entry is /channel): sets the chat window's default channel (types 0, 2, 15,
// 7, 4, 5, 8, 19). The global 0x9237EC is restored afterwards; only the window record keeps it.
// FUNCTION: TITANIUM 0x004704C1
void __cdecl do_channel_guess(int unused_guess, const char* text_guess) {
    char out_guess[128];
    char message_guess[128];
    char name_guess[32];
    char command_guess[64];
    int saved_guess = gChatType_guess;
    if (text_guess == 0 || *text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x3318, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3319, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x331a, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x331b, 0), 0x111, 1);
        return;
    }
    const char* rest_guess = (const char*)GrabFirstWord_guess(text_guess, command_guess, 0x40);
    GrabFirstWord_guess(rest_guess, name_guess, 0x20);
    if (__stricmp(pStringTable->getString(0x330e, 0), command_guess) == 0 ||
        __stricmp("gu", command_guess) == 0) {
        gChatType_guess = 0;
        strcpy(message_guess, pStringTable->getString(0x330e, 0));
    } else if (__stricmp(pStringTable->getString(0x330f, 0), command_guess) == 0 ||
               __stricmp("g", command_guess) == 0) {
        gChatType_guess = 2;
        strcpy(message_guess, pStringTable->getString(0x330f, 0));
    } else if (__stricmp(pStringTable->getString(0x13f7, 0), command_guess) == 0 ||
               __stricmp("rs", command_guess) == 0) {
        gChatType_guess = 0xf;
        strcpy(message_guess, pStringTable->getString(0x13f7, 0));
    } else if (__stricmp(pStringTable->getString(0x3310, 0), command_guess) == 0 ||
               __stricmp("t", command_guess) == 0) {
        gChatType_guess = 7;
        strcpy(gChatChannel_guess, name_guess);
        build_token_string_PARAM_guess(message_guess, 0x3311, gChatChannel_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    } else if (__stricmp(pStringTable->getString(0x3312, 0), command_guess) == 0 ||
               __stricmp("auc", command_guess) == 0) {
        gChatType_guess = 4;
        strcpy(message_guess, pStringTable->getString(0x3312, 0));
    } else if (__stricmp(pStringTable->getString(0x3313, 0), command_guess) == 0) {
        gChatType_guess = 5;
        strcpy(message_guess, pStringTable->getString(0x3313, 0));
    } else if (__stricmp(pStringTable->getString(0x3314, 0), command_guess) == 0) {
        gChatType_guess = 8;
        strcpy(message_guess, pStringTable->getString(0x3314, 0));
    } else if (__stricmp(pStringTable->getString(0x3315, 0), command_guess) != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3318, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x3319, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x331a, 0), 0x111, 1);
        pEverQuest->dsp_chat(pStringTable->getString(0x331b, 0), 0x111, 1);
        return;
    } else {
        gChatType_guess = 0x13;
        strcpy(gChatChannel_guess, name_guess);
        build_token_string_PARAM_guess(message_guess, 0x3316, gChatChannel_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    build_token_string_PARAM_guess(out_guess, 0x3317, message_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(out_guess, 0x111, 1);
    if (gChatOwner_4704c1_guess != 0) {
        Record_guess* record_guess = gChatOwner_4704c1_guess->GetActiveChatWindow_guess();
        record_guess->chatType_168_guess = gChatType_guess;
        if (gChatType_guess == 0x13) {
            if (gChatLists_4704c1_guess->list_290_guess != 0) {
                record_guess->channel_16c_guess =
                    gChatLists_4704c1_guess->list_290_guess->Find_guess(gChatChannel_guess);
            }
        } else if (gChatType_guess == 0x14) {
            if (gChatLists_4704c1_guess->list_834_guess != 0) {
                record_guess->channel_16c_guess =
                    gChatLists_4704c1_guess->list_834_guess->Find_guess(gChatChannel_guess);
            }
        } else if (gChatType_guess == 7) {
            record_guess->Copy170_guess(gChatChannel_guess);
        }
    }
    gChatType_guess = (unsigned char)saved_guess;
}

// Sets the UI skin from /uiskin <name> <flag>.
// /loadskin <name> [flag] (the line above says /uiskin): writes [Main] UISkin and sets the reload
// flag 0x988C77; 0x988C78 is set unless the flag starts with f, F or 0. Refused in game states
// 0xBC/0xBD and while either window 0x850C60/0x850C50 is open (0xC78).
// FUNCTION: TITANIUM 0x00470897
void __cdecl do_loadskin_guess(int unused_guess, const char* text_guess) {
    int flag_guess = gGateFlag_guess;
    Gate_guess* gate_guess = gGate_guess;
    if (gate_guess->GetEntry_guess(flag_guess)->state_00c_guess == 0xbc ||
        gate_guess->GetEntry_guess(flag_guess)->state_00c_guess == 0xbd) {
        pEverQuest->dsp_chat(pStringTable->getString(0x178c, 0));
        return;
    }
    if (text_guess == 0 || *text_guess == '\0') {
        if (pinstCLoadskinWnd_guess != 0) {
            pinstCLoadskinWnd_guess->Activate();
        }
        return;
    }
    if ((pinstCGiveWnd_guess != 0 && pinstCGiveWnd_guess->IsVisible_guess() != 0) ||
        (pinstCTradeWnd_guess != 0 && pinstCTradeWnd_guess->IsVisible_guess() != 0)) {
        pEverQuest->dsp_chat(pStringTable->getString(0xc78, 0), 0xf, true);
        return;
    }
    char name_guess[0x80];
    char value_guess[0x80];
    value_guess[0] = '\0';
    name_guess[0] = '\0';
    int rest_guess = GrabFirstWord_guess(text_guess, name_guess, 0x80);
    GrabFirstWord_guess((const char*)rest_guess, value_guess, 0x80);
    if (name_guess[0] == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0xc34, 0));
        return;
    }
    FUN_0060bf20_guess("Main", "UISkin", name_guess);
    char buffer_guess[0x400];
    build_token_string_PARAM_guess(buffer_guess, 0xc35, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);
    gSkinFlagA_guess = 1;
    if (value_guess[0] != 'f' && value_guess[0] != 'F' && value_guess[0] != '0') {
        gSkinFlagB_guess = 1;
        return;
    }
    gSkinFlagB_guess = 0;
}

// 0x98-byte message record sent with opcode 0x1EDC.
struct Record470A42_guess {
    char name_guess[0x40];          // 0x00
    char text_guess[0x44];          // 0x40
    int field_84_guess;             // 0x84: pCharData virtual base +0x100
    int field_88_guess;             // 0x88: local player +0x30 (float bits)
    int field_8c_guess;             // 0x8C: local player +0x34 (float bits)
    int field_90_guess;             // 0x90: local player +0x38 (float bits)
    int pad_94_guess;               // 0x94
};

struct PcPrefix470A42_guess {
    void* vftable_guess;
    int field_04_guess;
};
struct CharBase470A42_guess {
    void* vftable_guess;
    char pad_04_guess[0x100 - 0x04];
    int field_100_guess;
};
// The profile is a virtual base at +0xC384 (same shape as PcView46_guess), reached through the vbptr at +8.
struct PcView470A42_guess : PcPrefix470A42_guess, virtual CharBase470A42_guess {
    char pad_0C_guess[0xC384 - 0x0C];
};
#define gPcView470A42_guess EQ_GLOBAL(PcView470A42_guess*, 0x00905D00)

// /summon [name] (GM-only): OP_GMSummon (0x1EDC) with the name or target, your name, zone id
// (profile +0x100) and your y/x/z.
// FUNCTION: TITANIUM 0x00470A42
void __cdecl do_summon_guess(int unused_guess, const char* text_guess) {
    char buffer_guess[0x80];
    Record470A42_guess record_guess;
    memset(&record_guess, 0, 0x98);
    if (strcmp(text_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
        FUN_0060e450_guess(record_guess.name_guess, text_guess);
        FUN_0060e450_guess(record_guess.text_guess, pLocalPlayer_guess->Name);
        record_guess.field_84_guess = gPcView470A42_guess->field_100_guess;
        record_guess.field_88_guess = *(int*)&pLocalPlayer_guess->Y;
        record_guess.field_8c_guess = *(int*)&pLocalPlayer_guess->X;
        record_guess.field_90_guess = *(int*)&pLocalPlayer_guess->Z;
        SendMessage_guess(&gSendTarget_guess, OP_GMSummon, &record_guess, 0x98, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x3331, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xd, true);
    } else {
        if (pTargetPlayer_47377A_guess == 0) {
            return;
        }
        FUN_0060e450_guess(record_guess.name_guess, pTargetPlayer_47377A_guess->Name);
        FUN_0060e450_guess(record_guess.text_guess, pLocalPlayer_guess->Name);
        record_guess.field_84_guess = gPcView470A42_guess->field_100_guess;
        record_guess.field_88_guess = *(int*)&pLocalPlayer_guess->Y;
        record_guess.field_8c_guess = *(int*)&pLocalPlayer_guess->X;
        record_guess.field_90_guess = *(int*)&pLocalPlayer_guess->Z;
        SendMessage_guess(&gSendTarget_guess, OP_GMSummon, &record_guess, 0x98, 1);
        build_token_string_PARAM_guess(buffer_guess, 0x3331, pTargetPlayer_47377A_guess->Name,
                                       0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0xd, true);
    }
}

// /summoncorpse <name> (GM-only): opcode 0x3038 (not in patch_Titanium.conf) with the name;
// unlike /summon it never uses the target.
// FUNCTION: TITANIUM 0x00470BAD
void __cdecl do_summoncorpse_guess(int unused_guess, const char* text_guess) {
    char record_guess[0x98];
    char message_guess[0x80];
    char name_guess[0x40];
    memset(record_guess, 0, 0x98);
    if (text_guess == 0 || *text_guess == '\0') {
        pEverQuest->dsp_chat(pStringTable->getString(0x255, 0), 0xf, true);
    } else {
        if (strcmp(text_guess, EQ_ARRAY(char, 0x0063F53F)) == 0) {
            return;
        }
        FUN_0060e450_guess(name_guess, text_guess);
        SendMessage_guess(&gSendTarget_guess, 0x3038, name_guess, 0x40, 1);
        build_token_string_PARAM_guess(message_guess, 0x254, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message_guess, 0xd, true);
    }
}

// /viewpetition: in GM mode (0x923D64) toggles the window at 0x9928A8 on page 3; otherwise sends
// your name with opcode 0x19D8 (not in patch_Titanium.conf).
// FUNCTION: TITANIUM 0x00470C6A
void __cdecl do_viewpetition_guess() {
    if (gModeFlag_4683af_guess != 0) {
        if (pinstCTicketWnd_guess != 0) {
            if (pinstCTicketWnd_guess->IsVisible_guess() != 0) {
                pinstCTicketWnd_guess->Deactivate();
            } else {
                pinstCTicketWnd_guess->Activate();
                pinstCTicketWnd_guess->ShowPage_guess(3);
            }
            pinstCTicketWnd_guess->StoreIniVis();
        }
        return;
    }

    char* text_guess = &g_stateHolder_guess->text_044_guess[
        g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess];
    int length_guess = strlen(text_guess) + 1;
    SendMessage_guess(&gSendTarget_guess, 0x19d8, text_guess, length_guess, 1);
}

// /deletepetition: in GM mode toggles the same window; otherwise OP_PetitionDelete (0x5692) with
// your name.
// FUNCTION: TITANIUM 0x00470CE3
void __cdecl do_deletepetition_guess() {
    if (gModeFlag_4683af_guess != 0) {
        if (pinstCTicketWnd_guess != 0) {
            if (pinstCTicketWnd_guess->IsVisible_guess() != 0) {
                pinstCTicketWnd_guess->Deactivate();
            } else {
                pinstCTicketWnd_guess->Activate();
            }
            pinstCTicketWnd_guess->StoreIniVis();
        }
        return;
    }

    char* text_guess = &g_stateHolder_guess->text_044_guess[
        g_stateHolder_guess->offsetBlock_008_guess->vbaseOffset_0004_guess];
    int length_guess = strlen(text_guess) + 1;
    SendMessage_guess(&gSendTarget_guess, OP_PetitionDelete, text_guess, length_guess, 1);
}

// '1 platinum, 2 gold and 3 copper' style text, or eqstr 0x3334 when 0x923D74 is set.
// FUNCTION: TITANIUM 0x00470D4F
void __cdecl BuildMoneyText_guess(int platinum_guess, int gold_guess, int silver_guess, int copper_guess, char* out_guess) {
    char buffer_guess[0x80];
    if (gMoneyTokenMode_guess != 0) {
        build_token_string_PARAM_guess(out_guess, 0x3334,
                                       __itoa(platinum_guess, gPlatinumDigits_guess, 10),
                                       __itoa(gold_guess, gGoldDigits_guess, 10),
                                       __itoa(silver_guess, gSilverDigits_guess, 10),
                                       __itoa(copper_guess, gCopperDigits_guess, 10),
                                       0, 0, 0, 0, 0);
        return;
    }
    *out_guess = '\0';
    memset(buffer_guess, 0, 0x80);
    if (platinum_guess > 0) {
        sprintf(out_guess, "%1d platinum", platinum_guess);
    }
    const char* separator_guess = ", ";
    if (gold_guess > 0) {
        if (platinum_guess != 0) {
            if (silver_guess != 0) {
                FUN_0060e460_guess(out_guess, separator_guess);
            } else if (copper_guess != 0) {
                FUN_0060e460_guess(out_guess, separator_guess);
            } else {
                FUN_0060e460_guess(out_guess, " and ");
            }
        }
        sprintf(buffer_guess, "%1d gold", gold_guess);
        FUN_0060e460_guess(out_guess, buffer_guess);
    }
    if (silver_guess > 0) {
        if (platinum_guess != 0 || gold_guess != 0) {
            if (copper_guess != 0) {
                FUN_0060e460_guess(out_guess, separator_guess);
            } else if (platinum_guess != 0 || gold_guess != 0) {
                FUN_0060e460_guess(out_guess, " and ");
            }
        }
        sprintf(buffer_guess, "%1d silver", silver_guess);
        FUN_0060e460_guess(out_guess, buffer_guess);
    }
    if (copper_guess > 0) {
        if (platinum_guess != 0 || silver_guess != 0 || gold_guess != 0) {
            FUN_0060e460_guess(out_guess, " and ");
        }
        sprintf(buffer_guess, "%1d copper", copper_guess);
        FUN_0060e460_guess(out_guess, buffer_guess);
    }
}

// EXTERNAL: TITANIUM 0x0047C88E GetSpawnByName_guess
IncomingMessage_guess* __cdecl GetSpawnByName_guess(const char* name_guess);

struct ChatMessage_470ef3_guess {
    char first_guess[0x40];
    char second_guess[0x58];
};

// /find [name] (GM-only, and the local player's GM flag +0x256): OP_GMFind (0x5930); a known name
// also becomes the target.
// FUNCTION: TITANIUM 0x00470EF3
void __cdecl do_find_guess(void* unused_guess, const char* name_guess) {
    ChatMessage_470ef3_guess message_guess;
    char buffer_guess[0x80];
    memset(&message_guess, 0, 0x98);
    if (gConnection_guess->gm_0256_guess != 0) {
        if (strcmp(name_guess, EQ_ARRAY(char, 0x0063F53F)) != 0) {
            if (GetSpawnByName_guess(name_guess) != 0) {
                gIncomingMessage_guess = GetSpawnByName_guess(name_guess);
            }
            strcpy(message_guess.first_guess, name_guess);
            strcpy(message_guess.second_guess, gConnection_guess->text_120_guess);
            SendMessage_guess(&gSendTarget_guess, OP_GMFind, &message_guess, 0x98, 1);
            build_token_string_PARAM_guess(buffer_guess, 0x333a, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0xd, 1);
        } else {
            if (gIncomingMessage_guess == 0) {
                return;
            }
            strcpy(message_guess.first_guess, gIncomingMessage_guess->text_120_guess);
            strcpy(message_guess.second_guess, gConnection_guess->text_120_guess);
            SendMessage_guess(&gSendTarget_guess, OP_GMFind, &message_guess, 0x98, 1);
            build_token_string_PARAM_guess(buffer_guess, 0x333a, gIncomingMessage_guess->text_120_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0xd, 1);
        }
    }
}

struct Named_474d17_guess {
    char pad_000_guess[0x3c];
    char name_3c_guess[0x40];
};

struct Prefix_474d17_guess {
    int unused_000_guess;
    int unused_004_guess;
};

struct Thing_474d17_guess {
    // EXTERNAL: TITANIUM 0x004647A4 Thing_474d17_guess::Reset_guess
    void Reset_guess();
};

struct Block_474d17_guess {
    char pad_000_guess[0x170];
    int value_170_guess;
    char pad_174_guess[0x180 - 0x174];
    int slots_180_guess[3];
    char pad_18c_guess[0x198 - 0x18c];
    int value_198_guess;
};

struct Action_474d17_guess {
    char pad_000_guess[0x1a8];
    Block_474d17_guess* data_1a8_guess;
};

struct Holder_474d17_guess : Prefix_474d17_guess, virtual Named_474d17_guess {
    // EXTERNAL: TITANIUM 0x0046486B Holder_474d17_guess::Clear_guess
    void Clear_guess(int index);
    // EXTERNAL: TITANIUM 0x00451A65 Holder_474d17_guess::ClearGroupMemberNames_guess
    void ClearGroupMemberNames_guess();
    // EXTERNAL: TITANIUM 0x0045871F Holder_474d17_guess::FUN_0045871f_guess
    void FUN_0045871f_guess();
    // EXTERNAL: TITANIUM 0x00451A7C Holder_474d17_guess::ClearGroupLeaderName_guess
    void ClearGroupLeaderName_guess();
    char pad_00c_guess[0x15b0 - 0xc];
    char records_15b0_guess[0x180];
    char pad_1730_guess[0x40];
    Thing_474d17_guess member_1770_guess;
    char pad_1771_guess[0xc288 - 0x1771];
    Action_474d17_guess* current_c288_guess;
};

// Your own name disbands the whole group record; another name clears each matching group slot (6).
// FUNCTION: TITANIUM 0x00474D17
int __cdecl RemoveGroupMemberByName_guess(Holder_474d17_guess* holder_guess, const char* name_guess) {
    int result_guess = 0;
    if (*name_guess == '\0') {
        return 0;
    }
    if (holder_guess == 0) {
        return 0;
    }
    if (__stricmp(name_guess, holder_guess->name_3c_guess) == 0) {
        holder_guess->ClearGroupMemberNames_guess();
        holder_guess->FUN_0045871f_guess();
        holder_guess->ClearGroupLeaderName_guess();
        holder_guess->member_1770_guess.Reset_guess();
        if (holder_guess->current_c288_guess != 0 &&
            holder_guess->current_c288_guess->data_1a8_guess != 0) {
            for (int i = 0; i < 3; ++i) {
                holder_guess->current_c288_guess->data_1a8_guess->slots_180_guess[i] = 0;
            }
            holder_guess->current_c288_guess->data_1a8_guess->value_170_guess = 0;
            holder_guess->current_c288_guess->data_1a8_guess->value_198_guess = 0;
        }
    } else {
        for (int i = 0; i < 6; ++i) {
            if (__stricmp(name_guess, holder_guess->records_15b0_guess + i * 0x40) == 0) {
                holder_guess->Clear_guess(i);
                result_guess = 1;
            }
        }
    }
    return result_guess;
}

struct Command_474e01_guess {
    int kind_guess;
    char pad_004_guess[0x40];
    char text_44_guess[0x40];
    char text_84_guess[0x40];
};

// Group update (OP_GroupUpdate) by kind: 0 join, 1 leave, 3 rename, 5/6 disband, 7 member list,
// 8/9 new leader, 10 leader only; unknown kinds return 0.
// FUNCTION: TITANIUM 0x00474E01
// @early-stop: budget, diff ndiff=29
int __cdecl DispatchGroupUpdateOperation_guess(Record_guess* record, const Command_474e01_guess* command) {
    if (record == 0) {
        return 0;
    }
    int kind = command->kind_guess;
    int result = 0;
    if (kind == 0) {
        result = ProcessMSG_WLDGROUP_guess(record, command->text_44_guess);
    } else if (kind == 1) {
        if (gCopy79Owner_guess != 0) {
            gCopy79Owner_guess->SetGroupLeaderBlock_guess(record, command->text_84_guess);
        }
        result = RemoveGroupMemberByName_guess((Holder_474d17_guess*)record, command->text_44_guess);
    } else if (kind == 3) {
        return msg_wldgroup4_guess(record, command->text_44_guess, command->text_84_guess);
    } else if (kind == 7) {
        result = SetGroupMemberNames_guess(record, (const char*)command);
    } else if (kind == 5 || kind == 6) {
        record->ClearGroupMemberNames_guess();
        record->ClearGroupLeaderName_guess();
        if (gCopy79Owner_guess != 0) {
            gCopy79Owner_guess->ClearGroupLeaderData_guess(record);
        }
        return 1;
    } else {
        if (kind == 8 || kind == 9) {
            record->SetGroupLeaderName_guess(command->text_44_guess);
        } else if (kind != 10) {
            return 0;
        }
        if (gCopy79Owner_guess != 0) {
            gCopy79Owner_guess->SetGroupLeaderBlock_guess(record, command->text_84_guess);
        }
        result = 1;
    }
    return result;
}

// Handle reached from a GetCharInfo2 entry (0x0047503E).
struct Handle_47503e_guess {
    // EXTERNAL: TITANIUM 0x005E0770 Handle_47503e_guess::Apply_guess
    bool Apply_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ECC00 Handle_47503e_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Handle_47503e_guess::GetItemId_guess
    int GetItemId_guess();
};

struct Item_47503e_guess {
    // EXTERNAL: TITANIUM 0x005ED770 Item_47503e_guess::Flag_guess
    bool Flag_guess();
};

// The GetCharInfo2 entry; the code reads its fields 0x10 bytes in (view_010_guess).
struct CharView_47503e_guess {
    unsigned char pad_000_guess[0x18];
    Handle_47503e_guess* handle_018_guess;
    unsigned char pad_01c_guess[0x30 - 0x1c];
    Handle_47503e_guess* handle_030_guess;
    Handle_47503e_guess* handle_034_guess;
    Handle_47503e_guess* handle_038_guess;
    unsigned char pad_03c_guess[0x4c - 0x3c];
    Handle_47503e_guess* handle_04c_guess;
};

struct CharEntry_47503e_guess {
    unsigned char pad_000_guess[0x10];
    CharView_47503e_guess view_010_guess;
};

struct CharList_47503e_guess {
    void* list_guess;
    int key_guess;
    // EXTERNAL: TITANIUM 0x005EC220 CharList_47503e_guess::GetCharInfo2
    CharEntry_47503e_guess* GetCharInfo2();
};

// EQ_PC virtual base observed at +0xC280; the list follows its vfptr at +4.
struct CharBase_47503e_guess {
    virtual ~CharBase_47503e_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual Item_47503e_guess* Slot16_guess();
    CharList_47503e_guess list_guess;
    // EXTERNAL: TITANIUM 0x0040E934 CharBase_47503e_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int a_guess, int b_guess);
    // EXTERNAL: TITANIUM 0x00411F2F CharBase_47503e_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(int value_guess);
};

// EQPlayer::pCharInfo points to this object; the selected CharBase subobject is at +0xC280.
struct PlayerCharOwner_47503e_guess {
    unsigned char pad_000_guess[0xC280];
    CharBase_47503e_guess charBase_c280_guess;
    // EXTERNAL: TITANIUM 0x0040E934 PlayerCharOwner_47503e_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int a_guess, int b_guess);
    // EXTERNAL: TITANIUM 0x004106A3 PlayerCharOwner_47503e_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int a_guess, int b_guess, int c_guess, int d_guess);
};

#define gCharData_46bdab_guess EQ_GLOBAL(PlayerCharOwner_47503e_guess*, 0x00905D00)

// /dismount: eqstr 0x33E4 and drops the mount; 0x33E5 when not mounted.
// FUNCTION: TITANIUM 0x0046BDAB
void __cdecl do_dismount_guess(int enabled_guess) {
    if (enabled_guess != 0) {
        if (gConnection_guess->pActorInfo_01a8_guess != 0 &&
            gConnection_guess->pActorInfo_01a8_guess->mount_015c_guess != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33e4, 0));
            if (gCharData_46bdab_guess != 0) {
                gCharData_46bdab_guess->charBase_c280_guess.RemovePCAffect_guess(
                    gCharData_46bdab_guess->charBase_c280_guess.FindBuffWithEffect_guess(
                        0x71, 0));
            }
            return gConnection_guess->Dismount_guess();
        }
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x33e5, 0));
    }
}

// /safelock <password>: locks the interface (password under 32 chars at 0x95A174, eqstr 0x33EB);
// the same password unlocks it (0x33E9), a wrong one 0x33EA.
// FUNCTION: TITANIUM 0x0046BEAE
void __cdecl do_safelock_guess(int unused_guess, const char* text_guess) {
    if (*text_guess == '\0') {
        if (EQ_GLOBAL(char, 0x0095A174) != 0) {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x2f3f, 0));
        } else {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33e7, 0));
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33e8, 0));
        }
    } else if (EQ_GLOBAL(char, 0x0095A174) != 0) {
        if (FUN_00574950_guess(text_guess,
                               (const char*)EQ_ARRAY(char, 0x0095A174)) == 0) {
            EQ_GLOBAL(char, 0x0095A174) = 0;
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33e9, 0));
        } else {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33ea, 0));
        }
    } else {
        if (strlen(text_guess) < 0x20) {
            FUN_0060e450_guess((char*)EQ_ARRAY(char, 0x0095A174), text_guess);
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33eb, 0));
        } else {
            gGlobalContext_guess->dsp_chat(
                gTextLookup_guess->FindText_guess(0x33ec, 0));
        }
    }
}

// Whether `player` can use a combat skill (`param1` 0x16 with skill `param2`): monk kicks and punches,
// bash with a shield or allowed two-hander, hand to hand by gear; other kinds pass when `param3` or AA
// 0x75 says so. Probably CanUseSkill-like; DoMissileHit ignores the result.
// FUNCTION: TITANIUM 0x0047503E
// @early-stop: budget, structural ndiff=250
bool __cdecl IsAttackMagical_guess(int param1_guess, int param2_guess, bool param3_guess, EQPlayer* player_guess) {
    PlayerCharOwner_47503e_guess* owner_guess = (PlayerCharOwner_47503e_guess*)player_guess->pCharInfo;
    if (owner_guess == 0) {
        return false;
    }
    if (param1_guess != 0x16) {
        if (param1_guess == 9) {
            return true;
        }
        if (param3_guess) {
            return true;
        }
        return owner_guess->FindBuffWithEffect_guess(0x75, 0) != 0;
    }
    if ((player_guess->Class == Class_Beastlord || player_guess->Class == Class_Bard) && param2_guess == 0x1c) {
        if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_030_guess != 0 &&
            owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_030_guess->Apply_guess(1)) {
            return true;
        }
    }
    if (player_guess->Class == Class_Monk) {
        if (param2_guess == 0x15 || param2_guess == 0x17 || param2_guess == 0x1a) {
            return true;
        }
        if (param2_guess == 0x1c) {
            if (player_guess->Level > 0x1d) {
                return true;
            }
            if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_030_guess != 0 &&
                owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_030_guess->Apply_guess(1)) {
                return true;
            }
        } else if (param2_guess == 0x26 || param2_guess == 0x34 || param2_guess == 0x4a) {
            return true;
        }
    }
    if (param2_guess == 0x0a) {
        if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_038_guess != 0 &&
            owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_038_guess->Apply_guess(1)) {
            return true;
        }
        if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess != 0) {
            if (owner_guess->TotalSpellAffects_guess(0xe2, 1, 0, 1) != 0) {
                if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemType_guess() == 1) {
                    return true;
                }
                if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemType_guess() == 4) {
                    return true;
                }
                if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemType_guess() == 0x23) {
                    return true;
                }
            }
            if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemId_guess() == 0x2b2a) {
                return true;
            }
            if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemId_guess() == 0x2773) {
                return true;
            }
            if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->GetItemId_guess() == 0x382f) {
                return true;
            }
        }
        if (player_guess->Race != 0x0a && player_guess->Race != 9 && player_guess->Race != 2) {
            return false;
        }
        if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_018_guess == 0) {
            return false;
        }
        return owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_018_guess->Apply_guess(1);
    }
    if (param2_guess == 0x1c) {
        Item_47503e_guess* item_guess = owner_guess->charBase_c280_guess.Slot16_guess();
        if (item_guess == 0) {
            return false;
        }
        return item_guess->Flag_guess();
    }
    if (param2_guess != 0x1e) {
        if (param2_guess == 0x4a || param2_guess == 0x08) {
            if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess == 0) {
                return false;
            }
            return owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_034_guess->Apply_guess(1);
        }
        if (param2_guess != 0x47) {
            return false;
        }
    }
    if (owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_04c_guess == 0) {
        return false;
    }
    return owner_guess->charBase_c280_guess.list_guess.GetCharInfo2()->view_010_guess.handle_04c_guess->Apply_guess(1);
}

struct Item_4753f0_guess {
    unsigned char pad_000_guess[0x17d];
    unsigned char flag_17d_guess;
};

struct Sink_4753f0_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess(unsigned int code_guess, int state_guess, int zero_guess,
                              unsigned char* buffer_guess, unsigned int kind_guess);
};

struct Session_4753f0_guess {
    // EXTERNAL: TITANIUM 0x005E0540 Session_4753f0_guess::Probe_guess
    int Probe_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0770 Session_4753f0_guess::Lookup_guess
    bool Lookup_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0E90 Session_4753f0_guess::Read_guess
    int Read_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 Session_4753f0_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Session_4753f0_guess::Pick_guess
    int Pick_guess(int value_guess);
};

struct VBasePad_4753f0_guess {
    unsigned char pad_000_guess[4];
};

struct VBase_4753f0_guess : VBasePad_4753f0_guess, PropertyLocator_guess {
};

struct Link_4753f0_guess : virtual VBase_4753f0_guess {
    virtual void Slot00_guess();
    EQPlayer* peer_8_guess;
    // EXTERNAL: TITANIUM 0x0041A877 Link_4753f0_guess::Check_guess
    void Check_guess(Link_4753f0_guess* self_guess, int* mode_guess, unsigned int kind_guess);
    // EXTERNAL: TITANIUM 0x0041EBB3 Link_4753f0_guess::offense_guess
    void offense_guess(unsigned int code_guess);
    // EXTERNAL: TITANIUM 0x0041EAB3 Link_4753f0_guess::compute_tohit_guess
    void compute_tohit_guess(unsigned int code_guess);
};

struct Owner_4753f0_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x004795BC Owner_4753f0_guess::Init_guess
    void Init_guess(EQPlayer* source_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x00479D99 Owner_4753f0_guess::Thing_guess
    unsigned char Thing_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047C08E Owner_4753f0_guess::GetAnimation_guess
    Sink_4753f0_guess* GetAnimation_guess();
};

// Missile hit from `source` on `owner`: picks the attack skill, updates the skill and, except for
// kinds 0xD/0xE, sends OP_CombatAbility (0x5EE8). `session` is null-checked, then used anyway.
// FUNCTION: TITANIUM 0x004753F0
// @early-stop: budget, structural ndiff=14
int __cdecl DoMissileHit_guess(Owner_4753f0_guess* owner_guess, EQPlayer* source_guess,
                               Session_4753f0_guess* session_guess, unsigned int kind_guess) {
    if (source_guess == 0 || owner_guess == 0 || source_guess->Type > 1 || owner_guess->Type > 1) {
        return 0;
    }
    Link_4753f0_guess* link_guess = (Link_4753f0_guess*)owner_guess->pCharInfo;
    if (link_guess == 0) {
        return 0;
    }
    if ((unsigned char)kind_guess == 0xb) {
        owner_guess->Init_guess(source_guess, 0);
    }
    int mode_guess;
    if (session_guess != 0) {
        mode_guess = session_guess->Probe_guess(1);
    } else {
        mode_guess = 2;
    }
    if (session_guess != 0 && session_guess->GetItemType_guess() != 9 &&
        ((unsigned char)kind_guess == 0xd || (unsigned char)kind_guess == 0xe) &&
        (session_guess->GetItemType_guess() != 0x16 || session_guess->Read_guess() == 0x1c) &&
        link_guess->peer_8_guess != 0 && link_guess->peer_8_guess->Type == 0) {
        link_guess->Check_guess(link_guess, &mode_guess, (unsigned char)kind_guess);
    }
    IsAttackMagical_guess(session_guess->GetItemType_guess(), session_guess->Read_guess(),
                       session_guess->Lookup_guess(1), owner_guess);
    if (session_guess != 0 && session_guess->GetItemType_guess() != 9) {
        if (IsValidSpellIndex_guess(session_guess->Pick_guess(2)) != 0) {
            Item_4753f0_guess* item_guess =
                (Item_4753f0_guess*)gKeyLookup_guess->GetKey_guess(session_guess->Pick_guess(2));
            if (item_guess != 0 && item_guess->flag_17d_guess == 0) {
                session_guess->Pick_guess(2);
            }
        } else if (session_guess->GetItemType_guess() == 0x16) {
            session_guess->Read_guess();
        }
    }
    int state_guess = session_guess->GetItemType_guess();
    unsigned int code_guess;
    if (state_guess == 9) {
        link_guess->GetCharInfo2();
        session_guess->Probe_guess(1);
        code_guess = 0xe7;
    } else {
        if (state_guess == 0x16) {
            code_guess = session_guess->Read_guess();
        } else {
            code_guess = owner_guess->Thing_guess(session_guess->GetItemType_guess());
        }
        link_guess->offense_guess(code_guess);
    }
    ((Link_4753f0_guess*)owner_guess->pCharInfo)->compute_tohit_guess(code_guess);
    Sink_4753f0_guess* sink_guess = owner_guess->GetAnimation_guess();
    unsigned char buffer_guess[4];
    sink_guess->Slot11_guess(code_guess, state_guess, 0, buffer_guess, kind_guess);
    int packet_guess[3];
    packet_guess[0] = (int)source_guess->SpawnID;
    packet_guess[2] = code_guess;
    packet_guess[1] = (unsigned char)kind_guess;
    if ((unsigned char)kind_guess != 0xd && (unsigned char)kind_guess != 0xe) {
        FUN_004912b1_guess(&gSendTarget_guess, OP_CombatAbility, packet_guess, 0xc, 1);
    }
    return 1;
}

// Spell description (dbstr type 6) with tokens filled: #n base and @n max value of effect n (1-9,
// A-C for 10-12; HP effects 0, 79, 334 computed by level), %Y duration at your level and %Z the
// +0x24 duration, both in 6-second ticks shown as h:mm:ss. The level loop stores the class number,
// not its level (see bugs).
// FUNCTION: TITANIUM 0x00475855
// @early-stop: budget, structural ndiff=176
char* __cdecl FormatSpellDescription_guess(char* output_guess, Table_475855_guess* table_guess) {
    struct Scratch_475855_guess {
        char buffer_guess[1024];
        char timeText_guess[16];
        char numberText_guess[16];
    } scratch_guess;
    char* destination_guess = scratch_guess.buffer_guess;
    strcpy(output_guess, g_databaseStringManager_475855_guess->GetString_guess(
                             table_guess->stringId_18c_guess, 6, 0));
    char* cursor_guess = output_guess;
    while (*cursor_guess != 0) {
        char character_guess = *cursor_guess;
        if (character_guess == '#' || character_guess == '@') {
            int index_guess = -1;
            char code_guess = cursor_guess[1];
            if (code_guess == 'A' || code_guess == 'B' || code_guess == 'C') {
                index_guess = code_guess - 0x38;
            } else if (code_guess == 'a' || code_guess == 'b' || code_guess == 'c') {
                index_guess = code_guess - 0x58;
            } else if (code_guess >= '1' && code_guess <= '9') {
                index_guess = code_guess - '1';
            }
            if (index_guess >= 0) {
                int value_guess;
                if (character_guess == '#') {
                    value_guess = table_guess->values_30_guess[index_guess];
                    if (table_guess->values_120_guess[index_guess] == 0 ||
                        table_guess->values_120_guess[index_guess] == 0x4f ||
                        table_guess->values_120_guess[index_guess] == 0x14e) {
                        int best_guess = 0x46;
                        for (int state_guess = 1; state_guess <= 0x10; ++state_guess) {
                            if (table_guess->GetSpellLevelNeeded_guess(state_guess) < best_guess) {
                                best_guess = state_guess;
                            }
                        }
                        value_guess = g_playerState_475855_guess->command_c280_guess.CalcAffectChange_guess(
                            table_guess, best_guess, index_guess, 0);
                        if (table_guess->values_120_guess[index_guess] == 0 &&
                            table_guess->values_f0_guess[index_guess] == 0x7b) {
                            value_guess = table_guess->values_30_guess[index_guess];
                        }
                    }
                } else {
                    value_guess = table_guess->values_90_guess[index_guess];
                    if (table_guess->values_120_guess[index_guess] == 0 ||
                        table_guess->values_120_guess[index_guess] == 0x4f ||
                        table_guess->values_120_guess[index_guess] == 0x14e) {
                        value_guess = g_playerState_475855_guess->command_c280_guess.CalcAffectChange_guess(
                            table_guess, 0x46, index_guess, 0);
                        if (table_guess->values_120_guess[index_guess] == 0 &&
                            table_guess->values_f0_guess[index_guess] == 0x7b) {
                            value_guess = table_guess->values_90_guess[index_guess];
                        }
                    }
                }
                sprintf(scratch_guess.numberText_guess, "%d", FUN_0060f81e_guess(value_guess));
                char* numberCursor_guess = scratch_guess.numberText_guess;
                char numberCharacter_guess = *numberCursor_guess;
                while (numberCharacter_guess != 0) {
                    ++numberCursor_guess;
                    *destination_guess = numberCharacter_guess;
                    ++destination_guess;
                    numberCharacter_guess = *numberCursor_guess;
                }
            }
            cursor_guess += 2;
        } else if (character_guess == '%') {
            int value_guess;
            if (cursor_guess[1] == 'Y' || cursor_guess[1] == 'y') {
                value_guess = g_playerState_475855_guess->GetSlotTable_guess()
                                  .profile_guess.GetCharInfo2()->level_11a4_guess;
                value_guess = g_playerState_475855_guess->command_c280_guess.SpellDuration_guess(
                    table_guess, value_guess, 0);
            } else if (cursor_guess[1] == 'Z' || cursor_guess[1] == 'z') {
                value_guess = table_guess->value_24_guess;
            } else {
                value_guess = 0;
            }
            unsigned int timeValue_guess = (unsigned int)value_guess * 6;
            sprintf(scratch_guess.timeText_guess, " %d:%02d:%02d", timeValue_guess / 0xe10,
                    (timeValue_guess / 0x3c) % 0x3c, timeValue_guess % 0x3c);
            char* timeCursor_guess = scratch_guess.timeText_guess;
            char timeCharacter_guess = *timeCursor_guess;
            while (timeCharacter_guess != 0) {
                ++timeCursor_guess;
                *destination_guess = timeCharacter_guess;
                ++destination_guess;
                timeCharacter_guess = *timeCursor_guess;
            }
            cursor_guess += 2;
        } else {
            *destination_guess = character_guess;
            ++destination_guess;
            ++cursor_guess;
        }
    }
    *destination_guess = 0;
    strcpy(output_guess, scratch_guess.buffer_guess);
    return output_guess;
}

struct Pose_46_guess {
    float x_guess;   // 0x0
    float y_guess;   // 0x4
    float z_guess;   // 0x8
    float dx_guess;  // 0xC
    float dy_guess;  // 0x10
    float dz_guess;  // 0x14
    // EXTERNAL: TITANIUM 0x00458649 Pose_46_guess::CopyFrom_guess
    void CopyFrom_guess(const Pose_46_guess* source_guess);
};

struct Sum_46_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    Sum_46_guess(float x, float y, float z) : x_guess(x), y_guess(y), z_guess(z) {}
    // EXTERNAL: TITANIUM 0x00435B13 Sum_46_guess::CopyPose_guess
    void CopyPose_guess(float* destination_guess, const Pose_46_guess* source_guess) const;
};

struct MoverCalc_46_guess {
    float vector_000_guess[3];
    float rate_00c_guess;
    float one_010_guess;
    float pad_014_guess[3];
    float values_020_guess[4];
    unsigned char flag_030_guess;
    unsigned char flag_031_guess;
    unsigned short pad_032_guess;
    int pad_034_guess;
    unsigned char flag_038_guess;
    unsigned char flag_039_guess;
    unsigned char flag_03a_guess;
    unsigned char flag_03b_guess;
    // EXTERNAL: TITANIUM 0x0046D66E MoverCalc_46_guess::GetRate_guess
    float GetRate_guess();
};

// EXTERNAL: TITANIUM 0x00645E5C ??_7Mover_46_guess@@6B@
struct Mover_46_guess {
    virtual void Slot00_guess();
    Vector3_46_guess position_guess;  // 0x4
    float values_010_guess[3]; // 0x10
    float pose_01c_guess[3]; // 0x1c
    MoverCalc_46_guess calc_028_guess; // 0x28
    char active_064_guess; // 0x64
    char pad_065_guess;
    short pad_066_guess;
    int unknown_068_guess;
    int unknown_06c_guess;
    Mover_46_guess(const Pose_46_guess* source_guess, const Sum_46_guess& position_guess);
};

// Movement step from `source` towards `position`: its rate is the delta length, kept with its
// reciprocal; inactive when the length is 0.
// FUNCTION: TITANIUM 0x0046D713
// @early-stop: budget, diff ndiff=36
Mover_46_guess::Mover_46_guess(const Pose_46_guess* source_guess,
                               const Sum_46_guess& position_guess) {
    this->position_guess.x_guess = source_guess->x_guess;
    this->position_guess.y_guess = source_guess->y_guess;
    this->position_guess.z_guess = source_guess->z_guess;
    values_010_guess[0] = position_guess.x_guess;
    values_010_guess[1] = position_guess.y_guess;
    values_010_guess[2] = position_guess.z_guess;
    position_guess.CopyPose_guess(pose_01c_guess, source_guess);

    calc_028_guess.values_020_guess[0] = 0.0f;
    char zero_guess = 0;
    calc_028_guess.values_020_guess[1] = 0.0f;
    calc_028_guess.values_020_guess[2] = 0.0f;
    unknown_068_guess = -1;
    unknown_06c_guess = -1;
    calc_028_guess.values_020_guess[3] = 0.0f;
    calc_028_guess.flag_030_guess = zero_guess;
    calc_028_guess.flag_031_guess = zero_guess;
    calc_028_guess.one_010_guess = 1.0f;
    calc_028_guess.flag_038_guess = zero_guess;
    calc_028_guess.flag_039_guess = zero_guess;
    calc_028_guess.flag_03a_guess = 1;
    calc_028_guess.flag_03b_guess = 1;

    calc_028_guess.vector_000_guess[0] = pose_01c_guess[0];
    calc_028_guess.vector_000_guess[1] = pose_01c_guess[1];
    calc_028_guess.vector_000_guess[2] = pose_01c_guess[2];
    float rate_guess = calc_028_guess.GetRate_guess();
    float reciprocal_guess;
    if (rate_guess <= 0.0f) {
        reciprocal_guess = 0.0f;
    } else {
        reciprocal_guess = 1.0f / rate_guess;
    }
    calc_028_guess.rate_00c_guess = reciprocal_guess;
    char active_guess = zero_guess;
    if (0.0f < rate_guess) {
        active_guess = 1;
    }
    active_064_guess = active_guess;
}

struct Stamped_46_guess : Mover_46_guess {
    // EXTERNAL: TITANIUM 0x00647534 ??_7Stamped_46_guess@@6B@
    virtual void Slot00_guess();
    Pose_46_guess words_070_guess;  // 0x70
    unsigned char flag_088_guess;   // 0x88
    Stamped_46_guess(const Pose_46_guess* source_guess);
    ~Stamped_46_guess() {}
};

// Mover from `source` to source + delta, plus a copy of the pose.
// FUNCTION: TITANIUM 0x004760FC
Stamped_46_guess::Stamped_46_guess(const Pose_46_guess* source_guess)
    : Mover_46_guess(source_guess, Sum_46_guess(source_guess->dx_guess + source_guess->x_guess,
                                                source_guess->dy_guess + source_guess->y_guess,
                                                source_guess->dz_guess + source_guess->z_guess)) {
    words_070_guess.CopyFrom_guess(source_guess);
    flag_088_guess = 0;
}

struct Vector3_476167_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct Actor_476167_guess {
    unsigned char unused_000_guess[0x30];
    float x_030_guess;
    float y_034_guess;
    float z_038_guess;
    unsigned char unused_03c_guess[0x260 - 0x3c];
    int type_260_guess;
};

struct QueryTarget_476167_guess {
    virtual char Test_guess(Stamped_46_guess* query_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual char IsReady_guess();
};

#define gQueryTarget_476167_guess EQ_GLOBAL(QueryTarget_476167_guess*, 0x0099E370)
#define gCacheX_476167_guess EQ_GLOBAL(float, 0x009006B8)
#define gCacheY_476167_guess EQ_GLOBAL(float, 0x009006BC)
#define gCacheZ_476167_guess EQ_GLOBAL(float, 0x009006C0)
#define gCacheInputX_476167_guess EQ_GLOBAL(float, 0x009006C4)
#define gCacheInputY_476167_guess EQ_GLOBAL(float, 0x009006C8)
#define gCacheInputZ_476167_guess EQ_GLOBAL(float, 0x009006CC)
#define gCacheResult_476167_guess EQ_GLOBAL(int, 0x009006D0)

// Line of sight from the actor (raised 1 unit for types 8, 0xB, 0xC) to a point; 1 when clear. The
// last query and result are cached at 0x9006B8.
// FUNCTION: TITANIUM 0x00476167
// @early-stop: budget, structural ndiff=51
int __cdecl CastRay(Actor_476167_guess* actor_guess, float input_x_guess,
                               float input_y_guess, float input_z_guess) {
    if (actor_guess == 0)
        return 0;
    Vector3_476167_guess actor_position_guess;
    actor_position_guess.x_guess = actor_guess->x_030_guess;
    actor_position_guess.z_guess = actor_guess->z_038_guess;
    actor_position_guess.y_guess = actor_guess->y_034_guess;
    int actor_type_guess = actor_guess->type_260_guess;
    if (actor_type_guess == 0xb || actor_type_guess == 0xc || actor_type_guess == 8)
        actor_position_guess.z_guess += 1.0f;

    if (input_x_guess == gCacheInputX_476167_guess &&
        input_y_guess == gCacheInputY_476167_guess &&
        input_z_guess == gCacheInputZ_476167_guess &&
        actor_position_guess.x_guess == gCacheX_476167_guess &&
        actor_position_guess.y_guess == gCacheY_476167_guess &&
        actor_position_guess.z_guess == gCacheZ_476167_guess)
        return gCacheResult_476167_guess;

    gCacheZ_476167_guess = actor_position_guess.z_guess;
    gCacheInputX_476167_guess = input_x_guess;
    gCacheX_476167_guess = actor_position_guess.x_guess;
    gCacheInputZ_476167_guess = input_z_guess;
    gCacheY_476167_guess = actor_position_guess.y_guess;
    gCacheInputY_476167_guess = input_y_guess;

    Vector3_476167_guess input_position_guess;
    input_position_guess.x_guess = input_x_guess;
    input_position_guess.z_guess = input_z_guess;
    input_position_guess.y_guess = input_y_guess;

    if (gGate_guess->FUN_005f6b90_guess(gGateFlag_guess) != 0 &&
        gGate_guess->FUN_005f6b90_guess(gGateFlag_guess) != 1)
        gGate_guess->FUN_005f6b90_guess(gGateFlag_guess);

    if (gGate_guess->FUN_005f6e40_guess(gGateFlag_guess) == 0) {
        Transform_46D6C3_guess bounds_guess;
        bounds_guess.Copy_guess((const Transform_46D6C3_guess*)&actor_position_guess,
                                (const Transform_46D6C3_guess*)&input_position_guess);
        Stamped_46_guess query_guess((const Pose_46_guess*)&bounds_guess);
        query_guess.calc_028_guess.flag_03b_guess = 0;
        query_guess.calc_028_guess.flag_03a_guess = 1;
        query_guess.active_064_guess = 0;
        char hit_guess;
        if (gQueryTarget_476167_guess->IsReady_guess() == 0)
            hit_guess = 0;
        else
            hit_guess = gQueryTarget_476167_guess->Test_guess(&query_guess);
        if (hit_guess != 0) {
            gCacheResult_476167_guess = 0;
            return 0;
        }
    }
    gCacheResult_476167_guess = 1;
    return 1;
}

struct Node_474BC5_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 Node_474BC5_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Node_474BC5_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Node_474BC5_guess::At_guess
    Node_474BC5_guess* At_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0F30 Node_474BC5_guess::GetItemId_guess
    Node_474BC5_guess* GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC790 Node_474BC5_guess::HasItems_guess
    char HasItems_guess();
    // EXTERNAL: TITANIUM 0x005ACF60 Node_474BC5_guess::Identity_guess
    Node_474BC5_guess* Identity_guess();
    // EXTERNAL: TITANIUM 0x00601F10 Node_474BC5_guess::Matches_guess
    char Matches_guess(Node_474BC5_guess* other_guess);
};

union SlotsData_474BC5_guess {
    Node_474BC5_guess* slots_guess[2];
};

struct Slots_474BC5_guess {
    char pad_000_guess[0xd30];
    SlotsData_474BC5_guess data_guess;
};

// Whether `node`, or anything inside it (bags recurse), matches an item in `root`'s two slots at
// +0xD30 or their contents; probably the lore duplicate test. `match` is never read.
// FUNCTION: TITANIUM 0x00474BC5
// @early-stop: budget, structural ndiff=75
int __cdecl ContainsMatchingItem_guess(Slots_474BC5_guess* root_guess,
                         Node_474BC5_guess* match_guess,
                         Node_474BC5_guess* node_guess) {
    if (node_guess == 0)
        return 0;
    if (node_guess->GetItemClass_guess() == 1) {
        int index_guess = 0;
        int count_guess = node_guess->Count_guess();
        if (count_guess > 0) {
            do {
                if (node_guess->At_guess(index_guess) != 0) {
                    Node_474BC5_guess* child_guess = node_guess->At_guess(index_guess);
                    Node_474BC5_guess* nested_guess =
                        node_guess->At_guess(index_guess)->GetItemId_guess();
                    if (ContainsMatchingItem_guess(root_guess, nested_guess, child_guess) == 1)
                        return 1;
                }
                ++index_guess;
            } while (index_guess < node_guess->Count_guess());
        }
    }
    if (node_guess->HasItems_guess()) {
        int byteOffset_guess = 0;
        do {
            if (root_guess->data_guess.slots_guess[byteOffset_guess / 4] != 0) {
                Node_474BC5_guess* slot_guess =
                    root_guess->data_guess.slots_guess[byteOffset_guess / 4];
                if (slot_guess->Identity_guess()->Matches_guess(node_guess->Identity_guess()))
                    return 1;
                if (root_guess->data_guess.slots_guess[byteOffset_guess / 4]->GetItemClass_guess() == 1) {
                    Node_474BC5_guess* nested_guess =
                        root_guess->data_guess.slots_guess[byteOffset_guess / 4];
                    int index_guess = 0;
                    int count_guess = nested_guess->Count_guess();
                    if (count_guess > 0) {
                        do {
                            if (nested_guess->At_guess(index_guess) != 0) {
                                if (nested_guess->At_guess(index_guess)->Identity_guess()->Matches_guess(
                                        node_guess->Identity_guess()))
                                    return 1;
                            }
                            ++index_guess;
                        } while (index_guess < nested_guess->Count_guess());
                    }
                }
            }
            byteOffset_guess += 4;
        } while (byteOffset_guess < 8);
    }
    return 0;
}

struct ProfileDest_00474EDD_guess {
    int key_000_guess;
    int value_004_guess;
    int value_008_guess;
    int value_00c_guess;
    int value_010_guess;
    int value_014_guess;
    int value_018_guess;
    int value_01c_guess;
    int value_020_guess;
    int value_024_guess;
    int value_028_guess;
    int values_02c_guess[12];
    int values_05c_guess[12];
    int values_08c_guess[4];
    int values_09c_guess[4];
    int values_0ac_guess[4];
    int values_0bc_guess[12];
    int values_0ec_guess[12];
    char value_11c_guess;
    char value_11d_guess;
    char value_11e_guess;
    char values_11f_guess[0x24];
};

struct ProfileSrc_00474EDD_guess {
    int unused_000_guess;
    int value_004_guess;
    int unused_008_guess;
    int value_00c_guess;
    int value_010_guess;
    int value_014_guess;
    int value_018_guess;
    int value_01c_guess;
    int value_020_guess;
    int value_024_guess;
    int value_028_guess;
    int value_02c_guess;
    BoundedArray_guess<int, 12> values_030_guess;
    BoundedArray_guess<int, 12> values_060_guess;
    BoundedArray_guess<int, 12> values_090_guess;
    BoundedArray_guess<int, 4> values_0c0_guess;
    BoundedArray_guess<int, 4> values_0d0_guess;
    BoundedArray_guess<int, 4> values_0e0_guess;
    BoundedArray_guess<int, 12> values_0f0_guess;
    BoundedArray_guess<int, 12> values_120_guess;
    BoundedArray_guess<int, 12> values_150_guess;
    char value_180_guess;
    char value_181_guess;
    char value_182_guess;
    // EXTERNAL: TITANIUM 0x0044E755 ProfileSrc_00474EDD_guess::GetValue_guess
    char GetValue_guess(int index_guess);
};

// Packs spell `key`'s effect fields into a zeroed 0x144-byte record; 0 for an unknown spell.
// FUNCTION: TITANIUM 0x00474EDD
int __cdecl CopySpellData_guess(int key_guess, ProfileDest_00474EDD_guess* destination_guess) {
    memset(destination_guess, 0, 0x144);
    if (!IsValidSpellIndex_guess(key_guess)) {
        return 0;
    }
    ProfileSrc_00474EDD_guess* source_guess =
        (ProfileSrc_00474EDD_guess*)gKeyLookup_guess->GetKey_guess(key_guess);
    if (source_guess == 0) {
        return 0;
    }
    destination_guess->key_000_guess = key_guess;
    destination_guess->value_004_guess = source_guess->value_004_guess;
    destination_guess->value_008_guess = source_guess->value_00c_guess;
    destination_guess->value_00c_guess = source_guess->value_010_guess;
    destination_guess->value_010_guess = source_guess->value_014_guess;
    destination_guess->value_014_guess = source_guess->value_018_guess;
    destination_guess->value_018_guess = source_guess->value_01c_guess;
    destination_guess->value_01c_guess = source_guess->value_020_guess;
    destination_guess->value_020_guess = source_guess->value_024_guess;
    destination_guess->value_024_guess = source_guess->value_028_guess;
    destination_guess->value_028_guess = source_guess->value_02c_guess;
    for (int i = 0; i < 12; ++i) {
        destination_guess->values_02c_guess[i] = source_guess->values_030_guess[i];
        destination_guess->values_05c_guess[i] = source_guess->values_090_guess[i];
        destination_guess->values_0bc_guess[i] = source_guess->values_0f0_guess[i];
        destination_guess->values_0ec_guess[i] = source_guess->values_120_guess[i];
    }
    for (int i = 0; i < 4; ++i) {
        destination_guess->values_08c_guess[i] = source_guess->values_0c0_guess[i];
        destination_guess->values_09c_guess[i] = source_guess->values_0d0_guess[i];
    }
    for (int i = 0; i < 4; ++i) {
        destination_guess->values_0ac_guess[i] = source_guess->values_0e0_guess[i];
    }
    destination_guess->value_11c_guess = source_guess->value_180_guess;
    destination_guess->value_11d_guess = source_guess->value_181_guess;
    destination_guess->value_11e_guess = source_guess->value_182_guess;
    for (int i = 0; i <= 0x23; ++i) {
        destination_guess->values_11f_guess[i] = source_guess->GetValue_guess(i);
    }
    return 1;
}

struct StringTableView2_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView2_guess::FindText_guess
    const char* FindText_guess(int id_guess, int zero_guess, int type_guess,
                               int enabled_guess);
};
#define gTextLookup_475607_guess EQ_GLOBAL(StringTableView2_guess*, 0x00905CB0)

struct ActionControl_475607_guess {
    // EXTERNAL: TITANIUM 0x0048083A ActionControl_475607_guess::ApplyThree_guess
    void ApplyThree_guess(int index_guess, const char* text_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0048083A ActionControl_475607_guess::ApplyTwo_guess
    void ApplyTwo_guess(int index_guess, const char* text_guess);
};

struct ProfileNameCall_475607_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 ProfileNameCall_475607_guess::GetName_guess
    const char* GetName_guess(int zero_guess);
};

struct CharInfo_475607_guess {
    char pad_000_guess[0x10];
    ProfileNames46_guess names_010_guess;
};

struct ModeControl_475607_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A ModeControl_475607_guess::Reset_guess
    void Reset_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049994C ModeControl_475607_guess::Set_guess
    void Set_guess(int value_guess);
};
#define gModeControl_475607_guess EQ_GLOBAL(ModeControl_475607_guess, 0x00923770)
#define gAutoFire_guess EQ_GLOBAL(char, 0x009858C8)

// /autofire: needs a target (0x3199). On turns it
// off; off turns auto attack off, autofire on and shows the ranged item in the weapon models.
// FUNCTION: TITANIUM 0x00475607
void __cdecl do_autofire_guess(void) {
    if (pinstTarget == 0) {
        gGlobalContext_guess->Show_guess(
            gTextLookup_475607_guess->FindText_guess(0x3199, 0, 0x12f, 1));
        return;
    }
    if (gAutoFire_guess != 0) {
        gModeControl_475607_guess.Set_guess(0);
        return;
    }

    gModeControl_475607_guess.Reset_guess(0);
    gModeControl_475607_guess.Set_guess(1);
    if (g_stateHolder_guess->pSpawn_c288_guess != 0) {
        ((ActionControl_475607_guess*)g_stateHolder_guess->pSpawn_c288_guess)
            ->ApplyThree_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
        ((ActionControl_475607_guess*)g_stateHolder_guess->pSpawn_c288_guess)
            ->ApplyThree_guess(8, EQ_ARRAY(char, 0x006410A8), 0);
        ProfileNames46_guess* names_guess =
            &((CharInfo_475607_guess*)gPcView46_guess->GetInfo_guess())->names_010_guess;
        if (names_guess->first_2c_guess != 0) {
            names_guess =
                &((CharInfo_475607_guess*)gPcView46_guess->GetInfo_guess())
                     ->names_010_guess;
            ProfileNameCall_475607_guess* name_guess =
                (ProfileNameCall_475607_guess*)names_guess->first_2c_guess;
            ((ActionControl_475607_guess*)g_stateHolder_guess->pSpawn_c288_guess)
                ->ApplyTwo_guess(8, name_guess->GetName_guess(0));
        }
    }
}

#define gAnonymousState_4756_guess EQ_GLOBAL(int, 0x0092378C)
#define gAnonymousCommandText_4756_guess EQ_ARRAY(char, 0x00641A5C)

// /hideme (GM-only): toggles the target's invisibility (0x3296/0x3297; turning invisible also runs
// /anonymous); for yourself OP_GMHideMe (0x15B2) goes out with the packet still unset (same in the
// older client). Ends with OP_SpawnAppearance (0x7C32, type 3).
// FUNCTION: TITANIUM 0x004756EF
void __cdecl do_hideme_guess(void) {
    AnonymousPacket_4724fc_guess packet_guess;
    char buffer_guess[256];

    if (gTarget_472313_guess == 0) {
        gGlobalContext_guess->dsp_chat(
            gTextLookup_guess->FindText_guess(0x3294, 0));
        return;
    }

    gTarget_472313_guess->SetHideMode_guess(
        gTarget_472313_guess->anonymous_250_guess == 0);
    if (gTarget_472313_guess->anonymous_250_guess != 0) {
        build_token_string_PARAM_guess(
            buffer_guess, 0x3296,
            gGlobalContext_guess->trimName_guess(
                gTarget_472313_guess->name_120_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0xf, 1);
        do_anonymous_guess((AnonymousState_4724fc_guess*)gTarget_472313_guess,
                     gAnonymousCommandText_4756_guess);
    } else {
        build_token_string_PARAM_guess(
            buffer_guess, 0x3297,
            gGlobalContext_guess->trimName_guess(
                gTarget_472313_guess->name_120_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
        gGlobalContext_guess->SetText_guess(buffer_guess, 0xf, 1);
    }

    if (gTarget_472313_guess == gLocal_472313_guess) {
        gAnonymousState_4756_guess =
            gTarget_472313_guess->anonymous_250_guess;
        FUN_004912b1_guess(&gSendTarget_guess, OP_GMHideMe, &packet_guess, 8, 1);
    }

    packet_guess.spawnId_0000_guess = gTarget_472313_guess->spawnId_0258_guess;
    packet_guess.type_guess = 3;
    packet_guess.state_guess = gTarget_472313_guess->anonymous_250_guess;
    FUN_004912b1_guess(&gSendTarget_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
}

struct Pre_475BAB_guess {
    int pad_000_guess;
    int pad_004_guess;
};

struct Probe_475BAB_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 Probe_475BAB_guess::Find_guess
    int Find_guess(int slot_guess);
};

// The vbptr sits at +8, so the probe is reached through the vbase offset.
struct Holder_475BAB_guess : Pre_475BAB_guess, virtual Probe_475BAB_guess {
};
#define gHolder_475BAB_guess EQ_GLOBAL(Holder_475BAB_guess*, 0x00905D00)

struct EntryList_475BAB_guess {
    int count_000_guess;
    // EXTERNAL: TITANIUM 0x004EB924 EntryList_475BAB_guess::At_guess
    int* At_guess(int index_guess);
};
#define gEntryList_475BAB_guess EQ_GLOBAL(EntryList_475BAB_guess, 0x0095D3B4)

struct Packet_475BAB_guess {
    char text_000_guess[0x44];
    int value_044_guess;
    int pad_048_guess;
};

// /claim [id]: needs a free inventory slot (22-29, else 0xD14). A listed reward id asks to confirm
// (popup 0x6C, 0xD13, 60 s); otherwise OP_VetClaimRequest (0x6BA0) with your name and -1.
// FUNCTION: TITANIUM 0x00475BAB
// @early-stop: budget, structural ndiff=37
void __cdecl do_claim_guess(int unused_guess, const char* text_guess) {
    Packet_475BAB_guess packet_guess;
    if (gHolder_475BAB_guess != 0) {
        for (int slot_guess = InvSlot_General1; slot_guess <= InvSlot_General8; slot_guess++) {
            if (gHolder_475BAB_guess->Find_guess(slot_guess) == 0) {
                int target_guess = -1;
                if (text_guess != 0 && *text_guess != 0) {
                    sscanf(text_guess, "%d", &target_guess);
                    for (int i_guess = 0; i_guess < gEntryList_475BAB_guess.count_000_guess; i_guess++) {
                        if (target_guess == *gEntryList_475BAB_guess.At_guess(i_guess)) {
                            if (target_guess == -1) {
                                break;
                            } else {
                                gDispatch_475BAB_guess->Post_guess(
                                    gGlobalHead_475BAB_guess ? &gGlobalHead_475BAB_guess->link_008_guess : 0,
                                    0x6c,
                                    gTextLookup_guess->FindText_guess(0xd13, 0),
                                    0xc, 60000, target_guess, 1);
                                return;
                            }
                        }
                    }
                }
                packet_guess.value_044_guess = -1;
                FUN_0060e450_guess(packet_guess.text_000_guess,
                                   gConnection_guess ? gConnection_guess->text_120_guess
                                                     : EQ_ARRAY(char, 0x0063F53F));
                FUN_004912b1_guess(&gSendTarget_guess, OP_VetClaimRequest, &packet_guess, 0x4c, 1);
                return;
            }
        }
    }
    gGlobalContext_guess->SetText_guess(gTextLookup_guess->FindText_guess(0xd14, 0), 0xf, 1);
}

#define g_charData_475CE4_guess EQ_GLOBAL(Holder_474597_guess*, 0x00905D00)

// /autoinventory: a cursor item is auto-equipped from the cursor slot (30); cursor coin (0x905D24
// +0x11 = 1-4 platinum..copper) is added to the purse unless the sum would pass 1,000,000,000.
// FUNCTION: TITANIUM 0x00475CE4
// @early-stop: budget, structural ndiff=50
void __cdecl do_autoinventory_guess(void) {
    if (g_charData_475CE4_guess == 0) {
        return;
    }
    int mode_guess = pinstCCursorAttachment_guess->mode_15c_guess;
    if (mode_guess == 2) {
        ProfileNames46_guess* names_guess =
            &g_charData_475CE4_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()
                 ->names_010_guess;
        if (names_guess->value_78_guess == 0) {
            return;
        }
        gMixAhead_guess->WavePlay_guess(0x92, 0);
        names_guess =
            &g_charData_475CE4_guess->GetSlotTable_guess().profile_guess.GetCharInfo2()
                 ->names_010_guess;
        AutoEquipItem_guess(g_charData_475CE4_guess,
                     (RefObject_464C94_guess**)&names_guess->value_78_guess, 0x1e);
        return;
    }
    if (mode_guess != 3) {
        return;
    }
    if (gNpcNameState_guess->flag_11_guess == 0) {
        return;
    }
    unsigned char kind_guess = gNpcNameState_guess->flag_11_guess;
    int index_guess = kind_guess - 1;
    int value_guess = 0;
    switch (kind_guess) {
    case 1: {
        value_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                          .profile_guess.GetCharInfo2()
                          ->cursorPlatinum_11e4_guess;
        int limit_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->platinum_11d4_guess;
        int total_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->cursorPlatinum_11e4_guess;
        if (total_guess + limit_guess > 1000000000) {
            return;
        }
        break;
    }
    case 2: {
        value_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                          .profile_guess.GetCharInfo2()
                          ->cursorGold_11e8_guess;
        int limit_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->gold_11d8_guess;
        int total_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->cursorGold_11e8_guess;
        if (total_guess + limit_guess > 1000000000) {
            return;
        }
        break;
    }
    case 3: {
        value_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                          .profile_guess.GetCharInfo2()
                          ->cursorSilver_11ec_guess;
        int limit_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->silver_11dc_guess;
        int total_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->cursorSilver_11ec_guess;
        if (total_guess + limit_guess > 1000000000) {
            return;
        }
        break;
    }
    case 4: {
        value_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                          .profile_guess.GetCharInfo2()
                          ->cursorCopper_11f0_guess;
        int limit_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->copper_11e0_guess;
        int total_guess = g_charData_475CE4_guess->GetSlotTable_guess()
                              .profile_guess.GetCharInfo2()
                              ->cursorCopper_11f0_guess;
        if (total_guess + limit_guess > 1000000000) {
            return;
        }
        break;
    }
    }
    gGlobalContext_guess->MoveMoney_guess(0, 1, index_guess, index_guess, value_guess, 0);
}

struct CharFlagsPrefix_47f14_guess {
    int pad_0_guess;
    int pad_4_guess;
};

struct CharFlagsBase_47f14_guess {
    void* vftable_guess;
    int list_guess;
    int key_guess;
    BoundedArray_475855_guess<unsigned char, 32> flags_guess;
};

struct CharFlagsRoot_47f14_guess : CharFlagsPrefix_47f14_guess, virtual CharFlagsBase_47f14_guess {
};

#define pCharFlags_47f14_guess EQ_GLOBAL(CharFlagsRoot_47f14_guess*, 0x00905D00)

struct ModeRoot_47f14_guess {
    char pad_0000_guess[0x1b0];
    int field_1b0_guess;
};

struct ModeProvider_47f14_guess {
    // EXTERNAL: TITANIUM 0x004F288C ModeProvider_47f14_guess::GetActiveChatWindow_guess
    ModeRoot_47f14_guess* GetActiveChatWindow_guess();
};

#define pModeProvider_47f14_guess EQ_GLOBAL(ModeProvider_47f14_guess*, 0x009917E4)

struct EverQuestText_47f14_guess {
    // EXTERNAL: TITANIUM 0x00492595 EverQuestText_47f14_guess::GetLangDesc_guess
    char* GetLangDesc_guess(int value_guess);
};

#define pEverQuestText_47f14_guess EQ_GLOBAL(EverQuestText_47f14_guess*, 0x00988DF0)

// /language [list|n]: picks the n-th language with skill > 0 for the chat window (+0x1B0);
// always echoes the current one (0x33CE).
// FUNCTION: TITANIUM 0x00475F14
// @early-stop: budget, diff ndiff=8
void __cdecl do_language_guess(int unused_guess, char* name_guess) {
    int indices_guess[32];
    int count_guess = 0;
    char text_guess[128];
    if (pCharFlags_47f14_guess != 0) {
        for (int i = 0; i < 32; ++i) {
            indices_guess[i] = -1;
        }
        for (int i = 0; i < 32; ++i) {
            if (pCharFlags_47f14_guess->flags_guess[i] > 0) {
                indices_guess[count_guess++] = i;
            }
        }
    }
    if (__stricmp(name_guess, pStringTable->getString(0x33f4, 0)) == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x33cc, 0), 0x111, 1);
        for (int i = 0; i < count_guess; ++i) {
            sprintf(text_guess, "%d - %s", i + 1, pEverQuestText_47f14_guess->GetLangDesc_guess(indices_guess[i]));
            pEverQuest->dsp_chat(text_guess, 0x111, 1);
        }
    } else if (strlen(name_guess) != 0) {
        int index = atoi(name_guess) - 1;
        if (index < 0 || index >= count_guess) {
            pEverQuest->dsp_chat(pStringTable->getString(0x33cd, 0), 0x111, 1);
        } else if (pModeProvider_47f14_guess != 0) {
            pModeProvider_47f14_guess->GetActiveChatWindow_guess()->field_1b0_guess = index;
        }
    }
    if (pModeProvider_47f14_guess != 0) {
        int current = pModeProvider_47f14_guess->GetActiveChatWindow_guess()->field_1b0_guess;
        build_token_string_PARAM_guess(text_guess, 0x33ce,
                                       pEverQuestText_47f14_guess->GetLangDesc_guess(indices_guess[current]),
                                       __itoa(current + 1, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0);
    } else {
        text_guess[0] = '\0';
    }
    pEverQuest->dsp_chat(text_guess, 0x111, 1);
}

// /veteranReward: popup 0x7D with eqstr 0xE0F, 60 s.
// FUNCTION: TITANIUM 0x00468D7D
void __cdecl do_veteranreward_guess() {
    gDispatch_475BAB_guess->Post_guess(
        gGlobalHead_475BAB_guess ? &gGlobalHead_475BAB_guess->link_008_guess : 0,
        0x7d, gTextLookup_guess->FindText_guess(0xe0f, 0), 0xc, 60000, 0, 1);
}

// /beta: opcode 0x6627, no payload (not in patch_Titanium.conf).
// FUNCTION: TITANIUM 0x00468DBA
void __cdecl do_beta_guess() {
    FUN_004912b1_guess(&gSendTarget_guess, 0x6627, 0, 0, 1);
}


// /gems: toggles the window at 0x850C90.
// FUNCTION: TITANIUM 0x004690BC
void __cdecl do_gems_guess() {
    if (pinstCGemsGameWnd_guess != 0) {
        if (pinstCGemsGameWnd_guess->IsVisible_guess() != 0) {
            pinstCGemsGameWnd_guess->Deactivate();
        } else {
            pinstCGemsGameWnd_guess->Activate();
        }
    }
}

#define gCommandTarget_46a6f5_guess EQ_GLOBAL(CommandTarget_472156_guess*, 0x00905CE4)

// /inspectbuffs: needs expansion bit 0x40, else eqstr 0x2264.
// FUNCTION: TITANIUM 0x0046A6A6
void __cdecl do_inspectbuffs_guess() {
    if ((g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess] & 0x40) != 0) {
        if (g_costService_guess != 0) {
            g_costService_guess->UseAbility_guess(6, 1);
        }
        return;
    }
    gGlobalContext_guess->Show_guess(
        gTextLookup_guess->FindTextTyped_guess(0x2264, 0, 0xf, 1));
}

// /cast <1-9>: casts that spell gem; usage eqstr 0x33C7.
// FUNCTION: TITANIUM 0x0046A6F5
void __cdecl do_cast_guess(int value_guess, const char* text_guess) {
    if (allowslashcommand_guess() != 0) {
        long index_guess = atol(text_guess) - 1;
        if (index_guess >= 0 && index_guess <= 8) {
            if (value_guess != 0) {
                gCommandTarget_46a6f5_guess->Prepare_guess();
            }
            pinstCCastSpellWnd_guess->Select_guess((int)index_guess);
            return;
        }
        gGlobalContext_guess->Show_guess(
            gTextLookup_guess->FindTextTyped_guess(0x33c7, 0, 0x111, 1));
    }
}

#define gModeGuess_46a88c_guess EQ_GLOBAL(int, 0x00905D28)

// /camp [eqstr 0x33CA|0x33CB]: camp mode 1 or 2 (probably desktop or server select), else 0.
// FUNCTION: TITANIUM 0x0046A88C
void __cdecl do_camp_guess(int unused_guess, const char* text_guess) {
    if (allowslashcommand_guess() == 0) {
        return;
    }

    gModeGuess_46a88c_guess = 0;
    if (FUN_00574990_guess(text_guess,
                           gTextLookup_guess->FindText_guess(0x33ca, 0), 4) == 0) {
        gModeGuess_46a88c_guess = 1;
    } else if (FUN_00574990_guess(text_guess,
                                  gTextLookup_guess->FindText_guess(0x33cb, 0), 4) == 0) {
        gModeGuess_46a88c_guess = 2;
    }

    gGlobalContext_guess->PrepareToCamp_guess();
}

