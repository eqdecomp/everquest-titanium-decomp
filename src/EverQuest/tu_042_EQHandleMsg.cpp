// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 42: a hint from compare/tumap.py.
// Zone packet handling: EverQuestB8F0_guess::HandleWorldMessage_guess (0x0045B8F0, last in the file) is the
// client's opcode switch, and most functions above it are the handlers it calls. Case values are Titanium
// wire opcodes; trailing names are EQEmu's patch_Titanium.conf OP_ names, structs per its titanium_structs.h.
// The per-function globals are views of a few known objects: 0x00905D00 pCharData, 0x00905CE4 the local
// player, 0x00905D04 the target, 0x00905D24 CDisplay (+0x148 = now in ms), 0x00988DF0 pEverQuest,
// 0x00905CB0 pStringTable, 0x00905CA0 the world connection.
// DispatchTarget_guess and the other spawn views are EQPlayer (+0x120 name, +0x258 spawn id, +0x30 y/x/z);
// ResolveDispatch_guess (0x00401B28) finds one by spawn id. Every dsp_chat at 0x004982C6 is dsp_chat,
// and FormatNotice_guess formats a string-table entry with %1..%9.
#include "titanium/eqaddr.h"
#include "titanium/bounded_array.h"
#include "titanium/types.h"
#include "titanium/slots.h"
#include "titanium/opcodes.h"

struct Entry451E54_guess {
    int id_guess;
    int key_guess;
    int flag_guess;
    int value0C_guess;
    char name_guess[0x60];
    int value70_guess;
    unsigned char padding74_guess[0x40];
    unsigned tail_guess;
};

struct List451E54_guess {
    unsigned char padding_guess[0xbac];
    Entry451E54_guess entries_guess[512];
    int current_guess;
    int count_guess;
};

struct RebuildOwner451E54_guess {
    // EXTERNAL: TITANIUM 0x005433CE RebuildOwner451E54_guess::UpdatePetitionList_guess
    void UpdatePetitionList_guess();
};

#define g_list451E54_guess EQ_GLOBAL(List451E54_guess*, 0x00988DF0)
#define g_rebuildOwner451E54_guess EQ_GLOBAL(RebuildOwner451E54_guess*, 0x00850C98)

extern "C" unsigned __cdecl strlen(const char* text_guess);

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x00574830 FUN_00574830_guess
int __cdecl FUN_00574830_guess(const char* text_guess, int mode_guess);

// EXTERNAL: TITANIUM 0x00574700 FUN_00574700_guess
char* __cdecl FUN_00574700_guess(char* text_guess);

// EXTERNAL: TITANIUM 0x00478951 SpeakBabel_guess
void __cdecl SpeakBabel_guess(const char* source_guess, char* destination_guess,
                                int zero_guess, int capacity_guess, int seed_guess);

struct ListNode519E8_guess {
    unsigned char padding00_guess[0x58];
    ListNode519E8_guess* previous_guess;
    ListNode519E8_guess* next_guess;
    unsigned char padding60_guess[8];
    void* value68_guess;
    void* value6C_guess;

    void Remove_guess();
};

struct ListCleanup519E8_guess {
    // EXTERNAL: TITANIUM 0x004395C4 ListCleanup519E8_guess::DeleteLight_guess
    void DeleteLight_guess(void* value_guess);

    // EXTERNAL: TITANIUM 0x00439A46 ListCleanup519E8_guess::DeleteActor_guess
    void DeleteActor_guess(void* value_guess);
};

#define g_listNodeHead_guess EQ_GLOBAL(ListNode519E8_guess*, 0x00905CDC)
#define g_listCleanup_guess EQ_GLOBAL(ListCleanup519E8_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* operator new(unsigned size_guess);

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

struct UpdateValue_guess {
    int index_guess;
    int seconds_guess;
};

struct UpdateSettings_guess {
    unsigned char padding_guess[0x148];
    int frameTime_0148_guess;

    // EXTERNAL: TITANIUM 0x00439C41 UpdateSettings_guess::TrueDistance_guess
    float TrueDistance_guess(float first_guess, float second_guess,
                             float third_guess, float fourth_guess,
                             float fifth_guess, float sixth_guess, float zero_guess);

    // EXTERNAL: TITANIUM 0x00436628 UpdateSettings_guess::HeadingDiff_guess
    float HeadingDiff_guess(float first_guess, float second_guess,
                             float* output_guess);

    // EXTERNAL: TITANIUM 0x0043745D UpdateSettings_guess::GetValue2cf8_guess
    int GetValue2cf8_guess();

    // EXTERNAL: TITANIUM 0x0043910D UpdateSettings_guess::SetViewActor_guess
    void SetViewActor_guess(void* actor_guess);
};

#define g_updateEnabled_guess EQ_GLOBAL(int, 0x00905D00)
#define g_updateSettings_guess EQ_GLOBAL(UpdateSettings_guess*, 0x00905D24)
#define g_updateValues_guess EQ_ARRAY(int, 0x0092447C)
#define g_messageBuffer_guess EQ_ARRAY(char, 0x00905CA0)
#define g_propertyOwnerCurrent_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905CE4)

struct Target4521Receiver_guess {
    // EXTERNAL: TITANIUM 0x00537096 Target4521Receiver_guess::OpenForMerchant_guess
    void OpenForMerchant_guess(void* result_guess, float value_guess);

    // EXTERNAL: TITANIUM 0x005384E2 Target4521Receiver_guess::FinishSellingItem_guess
    void FinishSellingItem_guess(void* value_guess);

    // EXTERNAL: TITANIUM 0x00537E10 Target4521Receiver_guess::Handle_guess
    void Handle_guess(void* value_guess);
};

#define g_target4521Receiver_guess EQ_GLOBAL(Target4521Receiver_guess*, 0x00850C4C)

struct Target4521Dispatch_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual void Slot88_guess() = 0;
};

#define g_target4521Dispatch_guess EQ_GLOBAL(Target4521Dispatch_guess*, 0x00850C4C)
#define g_target4521Busy_guess EQ_GLOBAL(int, 0x00905D10)
#define g_target4521Result_guess EQ_GLOBAL(int, 0x009248D4)

struct Argument453E5D_guess {
    int value0_guess;
    unsigned char padding4_guess[4];
    float value8_guess;
    unsigned char enabledC_guess;
};

struct Argument453E9B_guess {
    int value0_guess;
    unsigned char padding4_guess[4];
    unsigned char enabled8_guess;
    unsigned char padding9_guess[3];
    float valueC_guess;
};

struct Argument453EEA_guess {
    unsigned char padding0_guess[4];
    int value4_guess;
    int value8_guess;
    unsigned char paddingC_guess[0x44];
    int value50_guess;
    int value54_guess;
    int value58_guess;
};

struct UpdateState4534ED_guess {
    unsigned char padding1A8_guess[0x1A8];
    int value1A8_guess;
};

struct Target4521State_guess {
    unsigned char padding_guess[0xE90];
    double valueE90_guess;
    double valueE98_guess;
    int valueEA0_guess;
    int valueEA4_guess;
    unsigned char paddingEA8_guess[0xC288 - 0xEA8];
    UpdateState4534ED_guess* pSpawn_c288_guess;
    unsigned char valueC28C_guess;
    unsigned char paddingC28D_guess[0xBB];
    unsigned char valueC348_guess;
    unsigned char paddingC349_guess[7];
    unsigned char valueC350_guess;

    // EXTERNAL: TITANIUM 0x005F0C00 Target4521State_guess::Update_guess
    void Update_guess(int index_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x005F09A0 Target4521State_guess::Set4534EDSecond_guess
    void Set4534EDSecond_guess(int index_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x005F0940 Target4521State_guess::Set4534EDFirst_guess
    void Set4534EDFirst_guess(int index_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x004BAE1C Target4521State_guess::ReapplyAltAbilities_guess
    void ReapplyAltAbilities_guess();
};

#define g_target4521State_guess EQ_GLOBAL(Target4521State_guess*, 0x00905D00)

struct UpdateReceiver453A24_guess {
    // EXTERNAL: TITANIUM 0x004D1484 UpdateReceiver453A24_guess::Finish_guess
    void Finish_guess();
};

#define g_updateObject453A24Ready_guess EQ_GLOBAL(UpdateReceiver453A24_guess*, 0x00850BD0)

struct NotifyArgument_guess {
    unsigned char padding_guess[8];
    int value8_guess;
};

struct NotifyReceiver_guess {
    // EXTERNAL: TITANIUM 0x0052B3D8 NotifyReceiver_guess::HandleLootItemReply_guess
    void HandleLootItemReply_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0052B026 NotifyReceiver_guess::FinishLoot_guess
    void FinishLoot_guess();
};

#define g_notifyReceiver_guess EQ_GLOBAL(NotifyReceiver_guess*, 0x00850C40)

struct Target4520A1Receiver_guess {
    // EXTERNAL: TITANIUM 0x004EC163 Target4520A1Receiver_guess::Reset_guess
    void Reset_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004EC497 Target4520A1Receiver_guess::Update_guess
    void Update_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x004EC7D8 Target4520A1Receiver_guess::Finish_guess
    void Finish_guess();

    // EXTERNAL: TITANIUM 0x004ECB56 Target4520A1Receiver_guess::Select_guess
    void Select_guess(int index_guess);
};

#define pinstCCastSpellWnd_guess EQ_GLOBAL(Target4520A1Receiver_guess*, 0x00850C2C)
#define g_target4520A1Count_guess EQ_GLOBAL(int, 0x009248D0)

struct Target4520E5Data_guess {
    unsigned char padding120_guess[0x120];
    char value120_guess[0x88];
    unsigned char padding1A8_guess[0xB0];
    int value258_guess;
    unsigned char padding25C_guess[0xB50 - 0x25C];
    int valueB50_guess;
    int valueB54_guess;
    unsigned char paddingB58_guess[0x39400 - 0xB58];
    int value39400_guess;
    unsigned char padding39404_guess[0xC];
    unsigned char data39410_guess[0x6A8];

    // EXTERNAL: TITANIUM 0x00494B3D Target4520E5Data_guess::SetGameState
    void SetGameState(unsigned value_guess);

    // EXTERNAL: TITANIUM 0x0049297B Target4520E5Data_guess::BeingIgnored_guess
    int BeingIgnored_guess(const char* name_guess);

    // EXTERNAL: TITANIUM 0x00494430 Target4520E5Data_guess::CopyFirstWord_guess
    void CopyFirstWord_guess(const char* source_guess, char* destination_guess);

    // EXTERNAL: TITANIUM 0x00494C09 Target4520E5Data_guess::IsOkToTransact_guess
    char IsOkToTransact_guess();

    // EXTERNAL: TITANIUM 0x00497BE2 Target4520E5Data_guess::GetCurrentLanguage_guess
    int GetCurrentLanguage_guess();

    // EXTERNAL: TITANIUM 0x004982C6 Target4520E5Data_guess::dsp_chat
    void dsp_chat(const char* message_guess, int category_guess, bool flag_guess);

    // EXTERNAL: TITANIUM 0x00492EC2 Target4520E5Data_guess::GetText_guess
    char* GetText_guess(const char* source_guess);
};

#define g_target4520E5Data_guess EQ_GLOBAL(Target4520E5Data_guess*, 0x00988DF0)

struct RandomSource454CCD_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 RandomSource454CCD_guess::Next_guess
    int Next_guess(int limit_guess);
};

#define g_randomSource454CCD_guess EQ_GLOBAL(RandomSource454CCD_guess, 0x009248E0)
#define g_textMode454CCD_guess EQ_GLOBAL(int, 0x00923D74)

struct Target4520E5Progress_guess {
    // EXTERNAL: TITANIUM 0x004F0FB5 Target4520E5Progress_guess::Reset_guess
    void Reset_guess();

    // EXTERNAL: TITANIUM 0x004F1A03 Target4520E5Progress_guess::Set_guess
    void Set_guess(int first_guess, int second_guess);
};

#define g_target4520E5Progress_guess EQ_GLOBAL(Target4520E5Progress_guess*, 0x00850B9C)

struct Target4520E5Message_guess {
    // EXTERNAL: TITANIUM 0x0042500C Target4520E5Message_guess::Send_guess
    void Send_guess(const char* value_guess);
};

#define g_target4520E5Message_guess EQ_GLOBAL(Target4520E5Message_guess*, 0x0079DBD8)

// EXTERNAL: TITANIUM 0x0046DD41 SendSpellChecksum_guess
int __cdecl SendSpellChecksum_guess(int value_guess);

// EXTERNAL: TITANIUM 0x0046DEA9 SendExeChecksum_guess
int __cdecl SendExeChecksum_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00574110 LogDataFileError_guess
void __cdecl LogDataFileError_guess(const char* value_guess);

// EXTERNAL: TITANIUM 0x00576E80 GetClientTime_guess
int __cdecl GetClientTime_guess();

extern "C" void* __cdecl memcpy(void* destination_guess, const void* source_guess,
                                 unsigned size_guess);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
extern "C" int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

struct Target452198Node_guess {
    unsigned char padding1B3_guess[0x1B3];
    unsigned char value1B3_guess;
    unsigned char padding1B4_guess[0x214 - 0x1B4];
    Target452198Node_guess* next214_guess;
    unsigned char padding218_guess[0x258 - 0x218];
    int value258_guess;
    int value25C_guess;
    int value260_guess;

    // EXTERNAL: TITANIUM 0x0047BFD0 Target452198Node_guess::Check_guess
    char Check_guess();
};

struct Target452198Target_guess {
    unsigned char padding1A8_guess[0x1A8];
    void* pActorInfo_01a8_guess;
    unsigned char padding1AC_guess[0x258 - 0x1AC];
    int spawnId_0258_guess;
};

struct Target452198Output_guess {
    unsigned char padding16C_guess[0x16C];
    int value16C_guess;
};

#define g_target452198First_guess EQ_GLOBAL(Target452198Node_guess*, 0x00905CC4)

// EXTERNAL: TITANIUM 0x004CD2EC ChecksumCodeRangesA_guess
int __cdecl ChecksumCodeRangesA_guess(int message_guess);

// EXTERNAL: TITANIUM 0x00548095 PrepareUpdate_guess
void __stdcall PrepareUpdate_guess(int value_guess);

struct MessageRecord_guess {
    int original_guess;
    int resolved_guess;
};

struct ToggleArgument_guess {
    unsigned char padding_guess[4];
    unsigned char enabled_guess;
};

struct GlobalController_guess {
    unsigned char padding_guess[0x1d4];
    int values1d4_guess[4];
    unsigned char padding1e4_guess[0x52];
    unsigned char active_guess;

    // EXTERNAL: TITANIUM 0x00569D94 GlobalController_guess::SetHisReadyTrade_guess
    void SetHisReadyTrade_guess(int enabled_guess);

    // EXTERNAL: TITANIUM 0x00569802 GlobalController_guess::Refresh_guess
    void Refresh_guess();

    // EXTERNAL: TITANIUM 0x00569DB3 GlobalController_guess::SetHisMoney_guess
    void SetHisMoney_guess(int index_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x00569639 GlobalController_guess::Deactivate_guess
    void Deactivate_guess();

    // EXTERNAL: TITANIUM 0x0056A380 GlobalController_guess::Activate_guess
    void Activate_guess(void* target_guess, int flag_guess);
};

#define g_globalController_guess EQ_GLOBAL(GlobalController_guess*, 0x00850C50)

struct BufferOwner_guess {
    unsigned char padding_guess[0x1730];
    unsigned char buffer_guess[0x40];

    void ClearGroupLeaderName_guess();
};

struct ReturnOwner_guess {
    // EXTERNAL: TITANIUM 0x004B20D3 ReturnOwner_guess::Finish_guess
    void Finish_guess();

    void* Release_guess(unsigned char free_guess);
};

struct PropertyData_guess {
    unsigned char padding_guess[0x1198];
    int race_1198_guess;
    unsigned char padding119c_guess[8];
    int level_11a4_guess;
    int mana_11a8_guess;
    unsigned char padding11ac_guess[8];
    int baseStr_11b4_guess;
    int baseSta_11b8_guess;
    int baseCha_11bc_guess;
    int baseDex_11c0_guess;
    int baseInt_11c4_guess;
    int baseAgi_11c8_guess;
    int baseWis_11cc_guess;
    unsigned char padding11d0_guess[0x14];
    int cursorPlatinum_11e4_guess;
    int cursorGold_11e8_guess;
    int cursorSilver_11ec_guess;
    int cursorCopper_11f0_guess;
    unsigned char padding11f4_guess[4];
    int practicePoints_11f8_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    PropertyData_guess* GetCharInfo2();
};

struct PropertyOwnerClear_guess {
    // EXTERNAL: TITANIUM 0x0040E25C PropertyOwnerClear_guess::Clear_guess
    void Clear_guess(char* text_guess);
};

struct PropertyOwner_guess {
    unsigned char padding_guess[4];
    EQ_CharacterProfileView_guess locator_guess;

    void Set11a4_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0040E293 PropertyOwner_guess::Set11a8_guess
    void Set11a8_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417CB3 PropertyOwner_guess::Set11ac_guess
    void Set11ac_guess(int value_guess);

    void Set11b4_guess(int value_guess);
    void Set11b8_guess(int value_guess);
    void Set11bc_guess(int value_guess);
    void Set11c0_guess(int value_guess);
    void Set11c4_guess(int value_guess);
    void Set11c8_guess(int value_guess);
    void Set11cc_guess(int value_guess);
    void Set11e4_guess(int value_guess);
    void SetGoldCursor_guess(int value_guess);
    void SetSilverCursor_guess(int value_guess);
    void SetCopperCursor_guess(int value_guess);
    void Set11f8_guess(int value_guess);
};

struct ClearRegionOwner_guess {
    unsigned char padding_guess[0x15b0];
    unsigned char region_guess[0x180];

    void ClearGroupMemberNames_guess();
};

struct IndexedValues_guess {
    unsigned char padding_guess[0x730];
    unsigned values730_guess[0x200];
    unsigned valuesF30_guess[0x10];

    void Set730_guess(unsigned index_guess, unsigned value_guess);
    void SetF30_guess(unsigned index_guess, unsigned value_guess);
};

struct EQ_CharacterProfileView2_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView2_guess::GetCharInfo2
    IndexedValues_guess* GetCharInfo2();
};

struct IndexedOwner_guess {
    unsigned char padding_guess[4];
    EQ_CharacterProfileView2_guess lookup_guess;

    void Set730_guess(unsigned index_guess, unsigned value_guess);
    void SetF30_guess(unsigned index_guess, unsigned value_guess);
};

struct SixWords_guess {
    unsigned word0_guess;
    unsigned word4_guess;
    unsigned word8_guess;
    unsigned wordC_guess;
    unsigned word10_guess;
    unsigned word14_guess;

    void CopyFrom_guess(const SixWords_guess* source_guess);
};

struct SevenWords_guess : SixWords_guess {
    unsigned word18_guess;

    // EXTERNAL: TITANIUM 0x00458649 SevenWords_guess::CopyBase_guess
    void CopyBase_guess(const SixWords_guess* source_guess);
    void CopyFrom_guess(const SevenWords_guess* source_guess);
};

struct DispatchRequest_guess {
    int operation_guess;
    int first_guess;
    int second_guess;
};

struct LookupValue454415_guess;

struct ProbeTable458ED8_guess {
    // EXTERNAL: TITANIUM 0x004B76A6 ProbeTable458ED8_guess::Find_guess
    LookupValue454415_guess** Find_guess(void* key_guess);
};

struct DispatchTarget_guess {
    union {
        char embedded_guess[0x30];
        unsigned char padding00_guess[0x30];
    };
    float value30_guess;
    float value34_guess;
    float value38_guess;
    float value3c_guess;
    float value40_guess;
    float value44_guess;
    float speedRun_0048_guess;
    float heading_004c_guess;
    unsigned char padding50_guess[4];
    float value54_guess;
    float value58_guess;
    unsigned char padding5c_guess[0x120 - 0x5c];
    char name_0120_guess[0x88];
    struct DispatchState_guess {
        unsigned char padding00_guess[0x48];
        float value48_guess;
        unsigned char padding4c_guess[0x30];
        int value7c_guess;
        unsigned char padding80_guess[0xE8 - 0x80];
        int valuesE8_guess[10];
        int value110_guess;
        unsigned char padding114_guess[0x44];
        int value158_guess;
        DispatchTarget_guess* value15c_guess;
        int value160_guess;
        unsigned char padding164_guess[0xEBC - 0x164];
        int valueEbc_guess;
        unsigned char paddingEC0_guess[0xF90 - 0xEC0];
        int valueF90_guess;
        unsigned char paddingF94_guess[0xF9C - 0xF94];
        unsigned char valueF9C_guess;
        unsigned char paddingF9D_guess[0xFA0 - 0xF9D];
        int valueFA0_guess;
        unsigned char paddingFA4_guess[0x1030 - 0xFA4];
        int value1030_guess;
        unsigned char padding1034_guess[0x1048 - 0x1034];
        LookupValue454415_guess* value1048_guess;
        unsigned char padding104c_guess[4];
        ProbeTable458ED8_guess probe1050_guess;
        unsigned char padding1054_guess[0x106c - 0x1054];
        int value106c_guess;
    }* pActorInfo_01a8_guess;
    unsigned char padding1ac_guess[8];
    unsigned char lfg_01b4_guess;
    unsigned char padding1b5_guess[0x204 - 0x1b5];
    int value204_guess;
    unsigned char padding208_guess[0x238 - 0x208];
    float heightOffset_0238_guess;
    unsigned char padding23c_guess[0x258 - 0x23c];
    int spawnId_0258_guess;
    unsigned char padding25c_guess[4];
    int race_0260_guess;
    unsigned char padding264_guess[8];
    int afk_026c_guess;
    unsigned char padding270_guess[4];
    int hpCurrent_0274_guess;

    // EXTERNAL: TITANIUM 0x004828DE DispatchTarget_guess::Next_guess
    int Next_guess();

    // EXTERNAL: TITANIUM 0x004849B2 DispatchTarget_guess::FUN_004849b2_guess
    void FUN_004849b2_guess();

    // EXTERNAL: TITANIUM 0x0047E900 DispatchTarget_guess::SetAFK_guess
    void SetAFK_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0047BFEB DispatchTarget_guess::AddPlayerState_guess
    void AddPlayerState_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0047BFF8 DispatchTarget_guess::RemovePlayerState_guess
    void RemovePlayerState_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0047C0C2 DispatchTarget_guess::ApplyTwo_guess
    void ApplyTwo_guess(int first_guess, int second_guess, int zero_guess);

    // EXTERNAL: TITANIUM 0x0047D776 DispatchTarget_guess::Continue_guess
    void Continue_guess();

    // EXTERNAL: TITANIUM 0x00485873 DispatchTarget_guess::ApplyIllusion_guess
    void ApplyIllusion_guess(void* argument_guess);

    // EXTERNAL: TITANIUM 0x00489955 DispatchTarget_guess::FUN_00489955_guess
    void FUN_00489955_guess();

    // EXTERNAL: TITANIUM 0x0048A6F2 DispatchTarget_guess::FUN_0048a6f2_guess
    void FUN_0048a6f2_guess();

    // EXTERNAL: TITANIUM 0x0048A945 DispatchTarget_guess::FUN_0048a945_guess
    unsigned FUN_0048a945_guess();

    // EXTERNAL: TITANIUM 0x0048083A DispatchTarget_guess::Refresh4548083A_guess
    void Refresh4548083A_guess(int value_guess, const char* text_guess,
                               int flag_guess);

    // EXTERNAL: TITANIUM 0x00479EE8 DispatchTarget_guess::PlaySound_guess
    void PlaySound_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0048BB5A DispatchTarget_guess::UpdateSharedValuesIfLocal_guess
    void UpdateSharedValuesIfLocal_guess();

    // EXTERNAL: TITANIUM 0x00479EB0 DispatchTarget_guess::SetGroupInvitePending_guess
    void SetGroupInvitePending_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0048C130 DispatchTarget_guess::SetPosition_guess
    void SetPosition_guess(float* position_guess, int count_guess);

    // EXTERNAL: TITANIUM 0x0048A0FC DispatchTarget_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float x_guess, float y_guess, float z_guess, int mode_guess);
};

// EXTERNAL: TITANIUM 0x0047C88E ResolveTarget_guess
DispatchTarget_guess* __cdecl ResolveTarget_guess(void* value_guess);

// EXTERNAL: TITANIUM 0x00401B28 ResolveDispatch_guess
DispatchTarget_guess* __cdecl ResolveDispatch_guess(int operation_guess);

// EXTERNAL: TITANIUM 0x00465304 unpack_physics_guess
void __cdecl unpack_physics_guess(float* destination_guess, const unsigned* source_guess,
                                DispatchTarget_guess* target_guess);

// EXTERNAL: TITANIUM 0x004BF9B2 TransformPassengersToBoatSpace_guess
void __cdecl TransformPassengersToBoatSpace_guess(DispatchTarget_guess* target_guess);

// EXTERNAL: TITANIUM 0x004BFC71 TransformPassengersToWorldSpace_guess
void __cdecl TransformPassengersToWorldSpace_guess(DispatchTarget_guess* target_guess);

struct PositionUpdate_guess {
    // EXTERNAL: TITANIUM 0x004B70DB PositionUpdate_guess::Apply_guess
    void Apply_guess(float* position_guess, int count_guess);
};

// EXTERNAL: TITANIUM 0x004B718D BeginPositionUpdate_guess
PositionUpdate_guess* __cdecl BeginPositionUpdate_guess(float* position_guess);

#pragma pack(push, 1)
struct Packet451ABA_guess {
    unsigned short value0_guess;   // 0x0
    union {
        unsigned value2_guess;                  // 0x2
        unsigned short value2Words_guess[2];    // 0x2
    };
    union {
        unsigned value6_guess;                  // 0x6
        unsigned short value6Words_guess[2];    // 0x6, [1] at 0x8
    };
    unsigned short valueA_guess;   // 0xA
    unsigned short valueC_guess;   // 0xC
    unsigned valueE_guess;         // 0xE
    unsigned value12_guess;        // 0x12
};
#pragma pack(pop)

struct DispatchPayload454415_guess {
    unsigned char padding_guess[0x30];
    int value30_guess;
    int value34_guess;
    int value38_guess;
};

struct LookupValue454415_guess {
    unsigned char padding00_guess[0x18];
    int value18_guess;
    int value1c_guess;
    unsigned char padding20_guess[0x30 - 0x20];
    int value30_guess;
    unsigned char padding34_guess[0x54 - 0x34];
    int value54_guess;
    unsigned char padding58_guess[0x208 - 0x58];
    const char* value208_guess;
    unsigned char padding20C_guess[0x234 - 0x20C];
    void* value234_guess;

    // EXTERNAL: TITANIUM 0x0044E77B LookupValue454415_guess::Check_guess
    char Check_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x005E05B0 LookupValue454415_guess::GetRecastTime_guess
    unsigned int GetRecastTime_guess();
};

struct Lookup454415_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 Lookup454415_guess::Find_guess
    LookupValue454415_guess* Find_guess(int value_guess);
};

#define g_lookup454415_guess EQ_GLOBAL(Lookup454415_guess*, 0x00985CC8)

struct Record45448B_guess {
    unsigned char bytes_guess[0x10c];
};

#define g_recordCount45448B_guess EQ_GLOBAL(int, 0x0085139C)
#define g_recordBase45448B_guess EQ_GLOBAL(Record45448B_guess*, 0x00851398)

// EXTERNAL: TITANIUM 0x00495CC3 SubmitEffectEmitters_guess
void __cdecl SubmitEffectEmitters_guess(int value_guess, int kind_guess,
                                      void* lookupValue_guess,
                                      void* firstSource_guess,
                                      void* secondSource_guess,
                                      int* payload_guess,
                                      int zero1_guess, int zero2_guess,
                                      int flag_guess);

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FormatNotice_guess
void __cdecl FormatNotice_guess(char* destination_guess, int code_guess,
                                const char* name_guess, const char* source_guess,
                                const char* text_guess, int zero6_guess,
                                int zero7_guess, int zero8_guess, int zero9_guess,
                                int zero10_guess, int zero11_guess);

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value_guess);

extern "C" char* __cdecl _itoa(int value_guess, char* destination_guess,
                                int radix_guess);

struct Argument453571_guess {
    int operation_guess;
    int value4_guess;
    int value8_guess;
};

struct Handler453571A_guess {
    // EXTERNAL: TITANIUM 0x004E6A81 Handler453571A_guess::Handle_guess
    void Handle_guess(Argument453571_guess* argument_guess);
};

struct Handler453571B_guess {
    // EXTERNAL: TITANIUM 0x004E455A Handler453571B_guess::HandleBazaarMsg
    void HandleBazaarMsg(Argument453571_guess* argument_guess, int value_guess);
};

#define g_handler453571A_guess EQ_GLOBAL(Handler453571A_guess*, 0x00850C58)
#define g_handler453571B_guess EQ_GLOBAL(Handler453571B_guess*, 0x00850C5C)

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(unsigned value_guess, int code_guess, char* message_guess,
                    int size_guess, int timeout_guess, void* data_guess,
                    int zero7_guess);
};

#define g_noticeSender_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)
#define g_noticeValue_guess EQ_GLOBAL(unsigned, 0x00988DF0)

struct Notice_guess {
    // EXTERNAL: TITANIUM 0x004E335A Notice_guess::Update_guess
    void Update_guess(int value_guess);
};

#define g_noticeEnabled_guess EQ_GLOBAL(Notice_guess*, 0x00850C5C)

struct EQ_Item_guess;

struct StateManager_guess {
    unsigned char padding00_guess[0x6C];
    int value6C_guess;

    // EXTERNAL: TITANIUM 0x004FA77F StateManager_guess::Apply_guess
    void Apply_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x004FA714 StateManager_guess::Reset_guess
    void Reset_guess();

    // EXTERNAL: TITANIUM 0x004FA39A StateManager_guess::GetContainerTypeName_guess
    char* GetContainerTypeName_guess(unsigned char kind_guess);

    // EXTERNAL: TITANIUM 0x004FAC58 StateManager_guess::Attach453681_guess
    void Attach453681_guess(EQ_Item_guess* object_guess, int value_guess);
};

#define g_stateManager_guess EQ_GLOBAL(StateManager_guess*, 0x00850CBC)

struct StateRequest_guess {
    char state_guess;
    unsigned char padding_guess[3];
    int value4_guess;
};

struct Target454DD7_guess {
    // EXTERNAL: TITANIUM 0x005396FB Target454DD7_guess::Update_guess
    void Update_guess(int value_guess);

    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual void Slot88_guess() = 0;
    virtual void Slot8C_guess() = 0;
    virtual void Slot90_guess() = 0;
    virtual void Slot94_guess() = 0;
    virtual void Slot98_guess() = 0;
    virtual void Slot9C_guess() = 0;
    virtual void SlotA0_guess() = 0;
    virtual void SlotA4_guess() = 0;
    virtual void SlotA8_guess() = 0;
    virtual void SlotAC_guess() = 0;
    virtual void SlotB0_guess() = 0;
    virtual void SlotB4_guess() = 0;
    virtual void SlotB8_guess() = 0;
    virtual void SlotBC_guess() = 0;
    virtual void SlotC0_guess(int first_guess, int second_guess) = 0;
};

#define pinstCMIZoneSelectWnd_guess EQ_GLOBAL(Target454DD7_guess*, 0x00991D64)

struct Target454B65_guess {
    // EXTERNAL: TITANIUM 0x00564E7E Target454B65_guess::Run_guess
    void Run_guess(int first_guess, int second_guess);
};

#define g_target454B65_guess EQ_GLOBAL(Target454B65_guess*, 0x009928E0)

struct FloatBlock4519AC_guess {
    float value0_guess;
    float value4_guess;
    float value8_guess;
    float valueC_guess;
    float value10_guess;
    float value14_guess;
    float value18_guess;
    float value1C_guess;
    float value20_guess;
    float value24_guess;
    float value28_guess;
    float value2C_guess;

    void Clear_guess();
};

// Motion block reset (player and missile motion): zeroes position, speed, run speed, heading and the four
// floats after them (+0x00 to +0x2C); the two ints at +0x30 and +0x34 are left as they are.
// FUNCTION: TITANIUM 0x004519AC
void FloatBlock4519AC_guess::Clear_guess() {
    value0_guess = 0.0f;
    value4_guess = 0.0f;
    value8_guess = 0.0f;
    value1C_guess = 0.0f;
    value20_guess = 0.0f;
    value18_guess = 0.0f;
    valueC_guess = 0.0f;
    value10_guess = 0.0f;
    value14_guess = 0.0f;
    value28_guess = 0.0f;
    value24_guess = 0.0f;
    value2C_guess = 0.0f;
}

// Unlinks this node from the global list (head 0x00905CDC), then deletes its light (+0x6C) and actor
// (+0x68) through the display.
// FUNCTION: TITANIUM 0x004519E8
void ListNode519E8_guess::Remove_guess() {
    if (previous_guess != 0 && next_guess != 0) {
        previous_guess->next_guess = next_guess;
        next_guess->previous_guess = previous_guess;
    } else if (previous_guess == 0 && next_guess != 0) {
        next_guess->previous_guess = 0;
        g_listNodeHead_guess = next_guess;
    } else if (next_guess == 0 && previous_guess != 0) {
        previous_guess->next_guess = 0;
    } else {
        next_guess = 0;
        previous_guess = 0;
        g_listNodeHead_guess = 0;
    }

    if (value6C_guess != 0) {
        g_listCleanup_guess->DeleteLight_guess(value6C_guess);
    }
    if (value68_guess != 0) {
        g_listCleanup_guess->DeleteActor_guess(value68_guess);
    }
}

// Clears the six group member names (+0x15B0, 64 chars each); the profile load and the group update
// handlers call it.
// FUNCTION: TITANIUM 0x00451A65
void ClearRegionOwner_guess::ClearGroupMemberNames_guess() {
    memset(region_guess, 0, 0x180);
}

// Clears the group leader's name (+0x1730, 64 chars).
// FUNCTION: TITANIUM 0x00451A7C
void BufferOwner_guess::ClearGroupLeaderName_guess() {
    memset(buffer_guess, 0, 0x40);
}

// Returns `second`; the Enhanced Root AA check passes its name ("POP_AA_EnhancedRootOnMe") and value.
// FUNCTION: TITANIUM 0x00451A94
unsigned __stdcall ReturnSecond_guess(unsigned first_guess, unsigned second_guess) {
    return second_guess;
}

// FUNCTION: TITANIUM 0x00451A9E
// Scalar deleting destructor.
void* ReturnOwner_guess::Release_guess(unsigned char free_guess) {
    Finish_guess();
    if ((free_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// FUNCTION: TITANIUM 0x00451ABA
// Position update for one spawn (also opcodes 0x3A2B and 0x4BB4). For an unknown spawn id, while
// pEverQuest+0xB54 is 5, it sends the id back as 0x3838 at most every 15 s and returns 0.
int __cdecl Handle_OP_ClientUpdate_guess(Packet451ABA_guess* packet_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(packet_guess->value0_guess);
    if (target_guess == 0) {
        if (g_target4520E5Data_guess->valueB54_guess == 5 &&
            g_propertyOwnerCurrent_guess != 0) {
            DispatchTarget_guess::DispatchState_guess* state_guess =
                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess;
            if (state_guess != 0) {
                int now_guess = g_updateSettings_guess->frameTime_0148_guess;
                if ((unsigned)(now_guess - state_guess->value7c_guess) >= 15000) {
                    state_guess->value7c_guess = now_guess;
                    EQSendMessage(g_messageBuffer_guess, OP_ConfirmDelete, packet_guess, 2, 1);
                }
            }
        }
        return 0;
    }

    DispatchTarget_guess::DispatchState_guess* state_guess = target_guess->pActorInfo_01a8_guess;
    if (state_guess != 0) {
        if (state_guess->value15c_guess != 0) {
            unpack_physics_guess(&target_guess->value30_guess, &packet_guess->value2_guess,
                               target_guess);
            target_guess->pActorInfo_01a8_guess->valueEbc_guess =
                g_updateSettings_guess->frameTime_0148_guess;
            target_guess = target_guess->pActorInfo_01a8_guess->value15c_guess;
        } else if (state_guess->value160_guess != 0) {
            return 1;
        }
    }

    if ((packet_guess->value6_guess & 0x1ff80000) == 0x2100000 &&
        (packet_guess->value2_guess & 0x3ff) == 0x42) {
        target_guess->pActorInfo_01a8_guess->value1030_guess = 6;
        target_guess->FUN_00489955_guess();
        TransformPassengersToBoatSpace_guess(target_guess);
        packet_guess->value6Words_guess[1] = packet_guess->value6Words_guess[1] & 0xe007;
        packet_guess->value2Words_guess[0] =
            packet_guess->value2Words_guess[0] & 0xfc00;
        packet_guess->valueC_guess = packet_guess->valueC_guess & 7;
        packet_guess->valueE_guess = packet_guess->valueE_guess & 0xffffe000;
        packet_guess->value12_guess = packet_guess->value12_guess & 0xffffe000;
        unpack_physics_guess(&target_guess->value30_guess, &packet_guess->value2_guess,
                           target_guess);
        TransformPassengersToWorldSpace_guess(target_guess);
        unsigned elapsed_guess = (unsigned)(g_updateSettings_guess->frameTime_0148_guess -
                                           target_guess->pActorInfo_01a8_guess->valueEbc_guess);
        if (elapsed_guess > 0x2ee0) {
            target_guess->FUN_0048a6f2_guess();
        }
    } else {
        target_guess->FUN_00489955_guess();
        target_guess->pActorInfo_01a8_guess->value1030_guess = 0;
        TransformPassengersToBoatSpace_guess(target_guess);
        unpack_physics_guess(&target_guess->value30_guess, &packet_guess->value2_guess,
                           target_guess);
        TransformPassengersToWorldSpace_guess(target_guess);
        target_guess->FUN_0048a6f2_guess();
    }

    target_guess->pActorInfo_01a8_guess->valueEbc_guess = g_updateSettings_guess->frameTime_0148_guess;
    target_guess->FUN_0048a945_guess();
    return 1;
}

// FUNCTION: TITANIUM 0x00451D07
// Makes a spawn name readable: '_' becomes ' ' and the two digits before the first space are cut
// ("a_rat01 says" -> "a rat says"). Text starting with '[' plus a number is left alone.
int __cdecl StripSpawnNameDigits_guess(char* input_guess) {
    unsigned index_guess = 0;
    int stop_guess = 0;
    if (input_guess[0] == '[' && FUN_00574830_guess(input_guess + 1, 0) != 0) {
        return 0;
    }

    unsigned length_guess = strlen(input_guess);
    if (length_guess < 4) {
        return 0;
    }

    int split_guess = -1;
    do {
        char character_guess = input_guess[index_guess];
        if (character_guess == ' ') {
            split_guess = index_guess;
            stop_guess = 1;
        } else if (character_guess == '_') {
            input_guess[index_guess] = ' ';
        }
        ++index_guess;
        if (index_guess >= length_guess) {
            stop_guess = 1;
        }
    } while (stop_guess == 0);

    if (split_guess > 2) {
        char* suffix_guess = FUN_00574700_guess(input_guess + split_guess - 2);
        if (FUN_00574830_guess(suffix_guess, 0) != 0) {
            unsigned start_guess = split_guess - 2;
            unsigned end_guess = length_guess - 2;
            if (start_guess < end_guess) {
                for (unsigned i_guess = start_guess; i_guess < end_guess; ++i_guess) {
                    input_guess[i_guess] = input_guess[i_guess + 2];
                }
            }
            input_guess[length_guess - 2] = 0;
        }
    }
    return 1;
}

// FUNCTION: TITANIUM 0x00451C6D
// Copies the next line (up to CR/LF or capacity - 1) from *position_guess; '@' is shown as an apostrophe.
// Returns nonzero while more text follows.
int __cdecl ReadNextTextLine_guess(char* input_guess, unsigned char* output_guess, unsigned* position_guess, int capacity_guess) {
    unsigned outputIndex_guess = 0;
    int state_guess = 0;
    unsigned length_guess = strlen(input_guess);
    output_guess[0] = 0;

    if (*position_guess >= length_guess) {
        return false;
    }

    do {
        char character_guess = input_guess[*position_guess];
        ++*position_guess;
        if (character_guess == '\0') {
            state_guess = 2;
        } else if (character_guess == '\n' || character_guess == '\r') {
            state_guess = 1;
            if (*position_guess >= length_guess) {
                state_guess = 2;
            }
        } else {
            if (character_guess == '@') {
                character_guess = '\'';
            }
            output_guess[outputIndex_guess] = character_guess;
            ++outputIndex_guess;
            if (outputIndex_guess >= capacity_guess - 1U) {
                state_guess = 1;
            }
            if (*position_guess >= length_guess) {
                    state_guess = 2;
            }
        }
    } while (state_guess == 0);

    output_guess[outputIndex_guess] = 0;
    if (state_guess == 2) {
        return false;
    }
    return input_guess[*position_guess] != '\0';
}

struct PositionRequest451DB3_guess {
    int operation_guess;
    float x_guess;
    float y_guess;
    float z_guess;
};

// FUNCTION: TITANIUM 0x00451DB3
// @early-stop: budget, structural ndiff=25
// Moves the dying spawn to the corpse position and drops its velocity; -1e27 is "no floor found".
void __cdecl Handle_OP_BecomeCorpse_guess(PositionRequest451DB3_guess* request_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(request_guess->operation_guess);
    if (target_guess == 0) {
        return;
    }
    target_guess->value30_guess = request_guess->x_guess;
    target_guess->value34_guess = request_guess->y_guess;
    target_guess->speedRun_0048_guess = 0.0f;
    target_guess->value38_guess = request_guess->z_guess;
    target_guess->value3c_guess = 0.0f;
    target_guess->value40_guess = 0.0f;
    target_guess->value44_guess = 0.0f;
    target_guess->value58_guess = 0.0f;
    float height_guess = target_guess->GetFloorHeightAt_guess(
        target_guess->value30_guess, target_guess->value34_guess,
        target_guess->value38_guess + 1.0f, 0);
    if (height_guess != -1e27f) {
        target_guess->pActorInfo_01a8_guess->value48_guess = height_guess;
    }
    target_guess->FUN_0048a945_guess();
}

// FUNCTION: TITANIUM 0x00451E54
// @early-stop: budget, structural ndiff=42
// Opcode 0x504, one petition: merges it into pEverQuest's 512-entry queue at +0xBAC (flag -1 or 1 removes
// it), re-sorts by +4 descending, then +0xB4 ascending, then id, and refreshes the petition window.
// Entries are 0xB8 bytes; g_list451E54_guess is pEverQuest.
int __cdecl UpdatePetitionQueue_guess(Entry451E54_guess* source_guess) {
    int index_guess = 0;
    Entry451E54_guess copies_guess[513];
    if (source_guess->name_guess[0] == 0) {
        strcpy(source_guess->name_guess, "Unknown User");
    }
    if (source_guess->tail_guess == 0) {
        source_guess->tail_guess = source_guess->value0C_guess;
    }
    g_list451E54_guess->current_guess = source_guess->value70_guess;
    g_list451E54_guess->count_guess = 0;

    copies_guess[512].id_guess = -1;
    int matched_guess = 0;
    for (index_guess = 0; index_guess < 512; ++index_guess) {
        if (g_list451E54_guess->entries_guess[index_guess].id_guess == source_guess->id_guess) {
            matched_guess = 1;
            memcpy(&g_list451E54_guess->entries_guess[index_guess], source_guess, 0xb8);
            if (source_guess->flag_guess == -1 || source_guess->flag_guess == 1) {
                g_list451E54_guess->entries_guess[index_guess].id_guess = -1;
            }
        }
    }

    for (index_guess = 0; index_guess < 512; ++index_guess) {
        memcpy(&copies_guess[index_guess], &g_list451E54_guess->entries_guess[index_guess], 0xb8);
        g_list451E54_guess->entries_guess[index_guess].id_guess = -1;
        g_list451E54_guess->entries_guess[index_guess].key_guess = 0;
        g_list451E54_guess->entries_guess[index_guess].value0C_guess = 0;
    }

    if (matched_guess == 0) {
        memcpy(&copies_guess[512], source_guess, 0xb8);
        if (source_guess->flag_guess == -1 || source_guess->flag_guess == 1) {
            copies_guess[512].id_guess = -1;
        }
    }

    for (int slot_guess = 0; slot_guess < 512; ++slot_guess) {
        int bestKey_guess;
        int bestId_guess = 0;
        int best_guess = -1;
        unsigned bestTail_guess;
        bestTail_guess = 0xffffffff;
        bestKey_guess = -1;
        for (index_guess = 0; index_guess < 513; ++index_guess) {
            Entry451E54_guess* candidate_guess = &copies_guess[index_guess];
            if (candidate_guess->id_guess >= 0) {
                if (candidate_guess->key_guess > bestKey_guess) {
                    bestKey_guess = candidate_guess->key_guess;
                    bestId_guess = candidate_guess->id_guess;
                    bestTail_guess = candidate_guess->tail_guess;
                    best_guess = index_guess;
                } else if (candidate_guess->key_guess == bestKey_guess) {
                    if (candidate_guess->tail_guess < bestTail_guess) {
                        bestId_guess = candidate_guess->id_guess;
                        bestTail_guess = candidate_guess->tail_guess;
                        best_guess = index_guess;
                    } else if (candidate_guess->tail_guess == bestTail_guess &&
                               candidate_guess->id_guess <= bestId_guess) {
                        bestId_guess = candidate_guess->id_guess;
                        best_guess = index_guess;
                    }
                }
            }
        }

        if (best_guess != -1) {
            memcpy(&g_list451E54_guess->entries_guess[slot_guess], &copies_guess[best_guess], 0xb8);
            copies_guess[best_guess].id_guess = -1;
        }
        if (g_list451E54_guess->entries_guess[slot_guess].id_guess > -1) {
            ++g_list451E54_guess->count_guess;
        }
    }

    if (g_rebuildOwner451E54_guess != 0) {
        g_rebuildOwner451E54_guess->UpdatePetitionList_guess();
    }
    return 1;
}

// FUNCTION: TITANIUM 0x004520A1
// Memorizes each listed spell id (-1 = leave the gem) and releases one pending-request count (0x009248D0).
int __cdecl Handle_OP_LoadSpellSet_guess(int* values_guess, int count_guess) {
    if (g_target4520A1Count_guess > 0) {
        --g_target4520A1Count_guess;
    } else {
        g_target4520A1Count_guess = 0;
    }

    int index_guess = 0;
    if (count_guess > 0) {
        do {
            int value_guess = values_guess[index_guess];
            if (value_guess >= 0) {
                pinstCCastSpellWnd_guess->Update_guess(value_guess);
            }
            ++index_guess;
        } while (index_guess < count_guess);
    }
    return 1;
}

// FUNCTION: TITANIUM 0x004520E5
// Character-select list: keeps the 0x6A8-byte CharacterSelect_Struct at pEverQuest+0x39410. Either data
// file check failing aborts with error 0xFF; both log the spell data file name (original text).
void __cdecl Handle_OP_SendCharInfo_guess(int dataFile_guess, int unused_guess, void* data_guess) {
    int state_guess = 0;
    if (SendSpellChecksum_guess(dataFile_guess) == 0) {
        LogDataFileError_guess("ERROR: Missing or corrupt datafile: Spdat.eff\n");
        ++state_guess;
        g_target4520E5Data_guess->value39400_guess = state_guess;
        g_target4520E5Data_guess->SetGameState(0xFF);
        EQ_GLOBAL(int, 0x00923794) = 0xFD;
        g_target4520E5Data_guess->valueB50_guess = state_guess;
        g_target4520E5Message_guess->Send_guess(g_messageBuffer_guess);
        return;
    } else {
        if (SendExeChecksum_guess(dataFile_guess) == 0) {
            LogDataFileError_guess("ERROR: Missing or corrupt datafile: Spdat.eff\n");
            ++state_guess;
            g_target4520E5Data_guess->value39400_guess = state_guess;
            g_target4520E5Data_guess->SetGameState(0xFF);
            EQ_GLOBAL(int, 0x00923794) = 0xFD;
            g_target4520E5Data_guess->valueB50_guess = state_guess;
            g_target4520E5Message_guess->Send_guess(g_messageBuffer_guess);
            return;
        } else {
            memcpy(g_target4520E5Data_guess->data39410_guess, data_guess, 0x6A8);
            if (g_target4520E5Progress_guess != 0) {
                g_target4520E5Progress_guess->Reset_guess();
                g_target4520E5Progress_guess->Set_guess(0x3EA, 1);
            }
            EQ_GLOBAL(int, 0x00923880) = 0;
        }
    }
}

// FUNCTION: TITANIUM 0x00452198
// Finds the spawn whose owner id (+0x25C) is the target's id and records it as the target's pet id
// (+0x16C of its +0x1A8 block), skipping race 0x6C (+0x260). Handle_OP_Charm_guess uses the same filter.
void __cdecl SetPetIdFromSpawnList_guess(Target452198Target_guess* target_guess) {
    if (target_guess != 0) {
        Target452198Node_guess* node_guess = g_target452198First_guess;
        while (node_guess != 0) {
            if (node_guess->value25C_guess == target_guess->spawnId_0258_guess &&
                node_guess->value1B3_guess == 0 && node_guess->Check_guess() == 0 &&
                node_guess->value260_guess != 0x6C && target_guess->pActorInfo_01a8_guess != 0) {
                ((Target452198Output_guess*)target_guess->pActorInfo_01a8_guess)->value16C_guess =
                    node_guess->value258_guess;
                return;
            }
            node_guess = node_guess->next214_guess;
        }
    }
}

// OP_ShopPlayerSell: the merchant window reports the sale (0x005384E2), then the character's +0xC28C is
// set and +0xC348 cleared.
// FUNCTION: TITANIUM 0x004521FF
void __cdecl Handle_OP_ShopPlayerSell_guess(int first_guess, int second_guess, void* third_guess) {
    g_target4521Receiver_guess->FinishSellingItem_guess(third_guess);
    g_target4521State_guess->valueC28C_guess = 1;
    g_target4521State_guess->valueC348_guess = 0;
}

struct PropertyValues452227_guess {
    float first_guess;
    float second_guess;
    float third_guess;
};

#define g_propertyValues452227_guess EQ_GLOBAL(PropertyValues452227_guess, 0x00923BCC)
#define g_propertyOwnerOther452227_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905CF8)

// FUNCTION: TITANIUM 0x00452227
// @early-stop: budget, structural ndiff=36
// Opcode 0x3B40: puts the player, and the controlled spawn at 0x00905CF8 if different, at the saved
// position 0x00923BCC and snaps them to the floor (probably a server-forced warp).
unsigned __cdecl MoveToSafePoint_guess() {
    if (g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value158_guess != 0) {
        g_propertyOwnerCurrent_guess->value34_guess =
            g_propertyValues452227_guess.second_guess;
        ((unsigned*)&g_propertyOwnerCurrent_guess->value30_guess)[0] =
            ((unsigned*)&g_propertyValues452227_guess.first_guess)[0];
        g_propertyOwnerCurrent_guess->value38_guess =
            g_propertyValues452227_guess.third_guess;

        float height_guess = g_propertyOwnerCurrent_guess->GetFloorHeightAt_guess(
            g_propertyValues452227_guess.first_guess,
            g_propertyValues452227_guess.second_guess,
            g_propertyValues452227_guess.third_guess + *EQ_ARRAY(float, 0x0063F4D0), 1);
        if (height_guess != *EQ_ARRAY(float, 0x00640EA0)) {
            g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value48_guess = height_guess;
            g_propertyOwnerCurrent_guess->value38_guess =
                height_guess + g_propertyOwnerCurrent_guess->heightOffset_0238_guess;
        }
        g_propertyOwnerCurrent_guess->FUN_0048a945_guess();
    }

    if (g_propertyOwnerOther452227_guess != 0 &&
        g_propertyOwnerOther452227_guess != g_propertyOwnerCurrent_guess &&
        g_propertyOwnerOther452227_guess->pActorInfo_01a8_guess->value158_guess != 0) {
        g_propertyOwnerOther452227_guess->value34_guess =
            g_propertyValues452227_guess.second_guess;
        ((unsigned*)&g_propertyOwnerOther452227_guess->value30_guess)[0] =
            ((unsigned*)&g_propertyValues452227_guess.first_guess)[0];
        g_propertyOwnerOther452227_guess->value38_guess =
            g_propertyValues452227_guess.third_guess;

        float height_guess = g_propertyOwnerOther452227_guess->GetFloorHeightAt_guess(
            g_propertyValues452227_guess.first_guess,
            g_propertyValues452227_guess.second_guess,
            g_propertyValues452227_guess.third_guess + *EQ_ARRAY(float, 0x0063F4D0), 1);
        if (height_guess != *EQ_ARRAY(float, 0x00640EA0)) {
            g_propertyOwnerOther452227_guess->pActorInfo_01a8_guess->value48_guess = height_guess;
            g_propertyOwnerOther452227_guess->value38_guess =
                height_guess + g_propertyOwnerOther452227_guess->heightOffset_0238_guess;
        }
        return g_propertyOwnerOther452227_guess->FUN_0048a945_guess();
    }
    return (unsigned)g_propertyOwnerOther452227_guess;
}

struct Target452387_guess {
    int value0_guess;
    unsigned char padding04_guess[0x8 - 0x4];
    unsigned char value8_guess[0x198 - 0x8];
    float value198_guess;
    unsigned char value19C_guess;
    unsigned char value19D_guess[1];
};

struct Message452387_guess {
    int value0_guess;
    int value4_guess;
    int value8_guess;
    int padding0C_guess[(0x5C - 0x0C) / 4];
};

struct Interface452387_guess {
    // EXTERNAL: TITANIUM 0x0056B897 Interface452387_guess::SetGMData_guess
    void SetGMData_guess(void* first_guess, void* second_guess, float value_guess);

    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
};

#define g_interface452387_guess EQ_GLOBAL(Interface452387_guess*, 0x00850BB0)
#define g_dispatch452387_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D1C)

// FUNCTION: TITANIUM 0x00452387
// Opens the trainer window on the GM spawn. With byte +0x19C clear no window opens; message 0x841
// (not in patch_Titanium.conf) goes out instead.
void __cdecl Handle_OP_GMTraining_guess(int first_guess, int second_guess,
                                Target452387_guess* target_guess) {
    DispatchTarget_guess* dispatch_guess = ResolveDispatch_guess(target_guess->value0_guess);
    if (dispatch_guess != 0) {
        if (target_guess->value19C_guess == 0) {
            int count_guess;
            if (g_target4521Result_guess > 0) {
                count_guess = g_target4521Result_guess - 1;
            } else {
                count_guess = 0;
            }
            g_target4521Result_guess = count_guess;
            if (count_guess != 0) {
                Message452387_guess message_guess;
                message_guess.value4_guess = count_guess;
                message_guess.value0_guess = -4;
                message_guess.value8_guess = 9;
                EQSendMessage(g_messageBuffer_guess, 0x841, &message_guess, 0x5c, 1);
            }
            g_target4521Result_guess = 0;
        } else {
            g_dispatch452387_guess = dispatch_guess;
            if (g_interface452387_guess != 0) {
                g_interface452387_guess->SetGMData_guess(target_guess->value8_guess,
                                                    target_guess->value19D_guess,
                                                    target_guess->value198_guess);
                g_interface452387_guess->Slot84_guess();
            }
        }
    }
}

#pragma pack(push, 1)
struct Argument452C54_guess {
    unsigned short word0_guess;       // 0x0
    unsigned short word2_guess;       // 0x2
    char byte4_guess;                 // 0x4
    unsigned char padding5_guess[2];  // 0x5
    int value7_guess;                 // 0x7
};
#pragma pack(pop)

struct Gate452C54_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 Gate452C54_guess::Check_guess
    char Check_guess();
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
    virtual void Slot34_guess();  // vtable +0x88
};
#define g_gate452C54_guess EQ_GLOBAL(Gate452C54_guess*, 0x00850C30)

struct SpellCalc452C54_guess {
    // EXTERNAL: TITANIUM 0x00439CA3 SpellCalc452C54_guess::PlayerSimpleDistance_guess
    float PlayerSimpleDistance_guess(DispatchTarget_guess* target_guess,
                         DispatchTarget_guess* resolved_guess, float scale_guess);
};
#define g_spellCalc452C54_guess EQ_GLOBAL(SpellCalc452C54_guess*, 0x00905D24)

struct CostView452C54_guess {
    // EXTERNAL: TITANIUM 0x0041AB7E CostView452C54_guess::ModifyCurHP_guess
    void ModifyCurHP_guess(int value_guess, int unused_guess);
    // EXTERNAL: TITANIUM 0x00417E07 CostView452C54_guess::Cur_HP
    int Cur_HP(int mode_guess);
};

struct CharacterCost452C54_guess {
    unsigned char padding0_guess[0xC280];  // 0x0
    CostView452C54_guess view_guess;       // 0xC280
};
#define g_characterCost452C54_guess EQ_GLOBAL(CharacterCost452C54_guess*, 0x00905D00)
#define g_propertyOwnerCurrent_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905CE4)

struct EverQuestNotice452C54_guess {
    // EXTERNAL: TITANIUM 0x004A56E3 EverQuestNotice452C54_guess::Handle_guess
    void Handle_guess(Argument452C54_guess* argument_guess, bool flag_guess,
                      int zero_guess);
};
#define g_everQuestNotice452C54_guess EQ_GLOBAL(EverQuestNotice452C54_guess*, 0x00988DF0)

// FUNCTION: TITANIUM 0x00452C54
// @early-stop: budget, structural ndiff=23
// CombatDamage_Struct {u16 target, u16 source, u8 type, u16 spell, u32 damage}, packed. Damage to the
// player lowers HP at once, except type 0xE7 (probably EQEmu's spell-damage type); hits between other
// spawns are passed on flagged off beyond 75 units.
void __cdecl Handle_OP_Damage_guess(Argument452C54_guess* argument_guess) {
    DispatchTarget_guess* target_guess = g_propertyOwnerCurrent_guess;
    bool flag_guess = true;
    if (argument_guess->word2_guess == target_guess->spawnId_0258_guess ||
        argument_guess->word0_guess == target_guess->spawnId_0258_guess) {
        if (argument_guess->word0_guess == target_guess->spawnId_0258_guess &&
            argument_guess->word2_guess != target_guess->spawnId_0258_guess) {
            char byte4_guess = argument_guess->byte4_guess;
            if (!(byte4_guess != -25 && argument_guess->value7_guess <= 0 &&
                  byte4_guess != -25)) {
                int value_guess = argument_guess->value7_guess;
                if (value_guess > 0) {
                    if (g_gate452C54_guess->Check_guess() != 0) {
                        g_gate452C54_guess->Slot34_guess();
                    }
                    if (argument_guess->byte4_guess == -25) {
                        value_guess = 0;
                    } else {
                        value_guess = argument_guess->value7_guess;
                    }
                }
                if (value_guess != 0) {
                    g_characterCost452C54_guess->view_guess.ModifyCurHP_guess(-value_guess, 0);
                    g_propertyOwnerCurrent_guess->hpCurrent_0274_guess =
                        g_characterCost452C54_guess->view_guess.Cur_HP(0);
                }
            }
        }
    } else {
        DispatchTarget_guess* resolved_guess =
            ResolveDispatch_guess(argument_guess->word0_guess);
        if (g_spellCalc452C54_guess->PlayerSimpleDistance_guess(target_guess, resolved_guess, 1.0f) >
            75.0f) {
            flag_guess = false;
        }
    }
    g_everQuestNotice452C54_guess->Handle_guess(argument_guess, flag_guess, 0);
}

struct Packet45242F_guess {
    unsigned short id_guess;
    short type_guess;
    int value_guess;
};

struct Spawn45242F_guess;

struct ActorInfo45242F_guess {
    unsigned char padding000_guess[0x15C];
    Spawn45242F_guess* mount15C_guess;
    unsigned char padding160_guess[0x106C - 0x160];
    int value106C_guess;
};

struct Display45242F_guess {
    // EXTERNAL: TITANIUM 0x0040D8FA Display45242F_guess::SetFlag_guess
    void SetFlag_guess(bool flag_guess);
};

struct Spawn45242F_guess {
    unsigned char padding000_guess[0x24];
    float value24_guess;
    float value28_guess;
    float value2C_guess;
    unsigned char padding030_guess[0x120 - 0x30];
    char name120_guess[0x88];
    ActorInfo45242F_guess* info1A8_guess;
    unsigned char padding1AC_guess[4];
    unsigned char flags1B0_guess;
    unsigned char value1B1_guess;
    unsigned char linkdead_01b2_guess;
    unsigned char padding1B3_guess[2];
    unsigned char isPet_01b5_guess;
    unsigned char padding1B6_guess[2];
    unsigned char showHelm_01b8_guess;
    unsigned char padding1B9_guess[0x218 - 0x1B9];
    Display45242F_guess* display218_guess;
    unsigned char padding21C_guess[0x244 - 0x21C];
    unsigned char type_0244_guess;
    unsigned char padding245_guess[0x24C - 0x245];
    unsigned char level_024c_guess;
    unsigned char padding24D_guess[2];
    unsigned char pvpFlag_024f_guess;
    unsigned char hideMode_0250_guess;
    unsigned char padding251_guess[2];
    unsigned char light_0253_guess;
    unsigned char padding254_guess[2];
    unsigned char gm_0256_guess;
    unsigned char padding257_guess;
    int spawnId_0258_guess;
    int masterId_025c_guess;
    unsigned char padding260_guess[4];
    int anon_0264_guess;
    unsigned char padding268_guess[0x274 - 0x268];
    int hpCurrent_0274_guess;
    int aaTitle_0278_guess;
    int guildRank_027c_guess;
    unsigned char padding280_guess[4];
    int hpMax_0284_guess;
    int guildId_0288_guess;
    unsigned char padding28C_guess[0x298 - 0x28C];
    int value298_guess;

    // EXTERNAL: TITANIUM 0x0047A64D Spawn45242F_guess::SetLevitate_guess
    void SetLevitate_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047A705 Spawn45242F_guess::SetSpawnId_guess
    void SetSpawnId_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047AA0B Spawn45242F_guess::SetNameSpriteTint
    void SetNameSpriteTint();
    // EXTERNAL: TITANIUM 0x0047BCE2 Spawn45242F_guess::UpdateLight_guess
    void UpdateLight_guess();
    // EXTERNAL: TITANIUM 0x0047C10D Spawn45242F_guess::SetHideMode_guess
    void SetHideMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047D776 Spawn45242F_guess::Continue_guess
    void Continue_guess();
    // EXTERNAL: TITANIUM 0x0047E900 Spawn45242F_guess::SetAFK_guess
    void SetAFK_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00480409 Spawn45242F_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
    // EXTERNAL: TITANIUM 0x00481D5D Spawn45242F_guess::SetAvatarHeight_guess
    void SetAvatarHeight_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x00482722 Spawn45242F_guess::SwapNPCMaterials_guess
    void SwapNPCMaterials_guess();
    // EXTERNAL: TITANIUM 0x00483556 Spawn45242F_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0048A945 Spawn45242F_guess::Update_guess
    void Update_guess();
};

// EXTERNAL: TITANIUM 0x00401B28 GetSpawn45242F_guess
Spawn45242F_guess* __cdecl GetSpawn45242F_guess(int id_guess);

struct Options45242F_guess {
    // EXTERNAL: TITANIUM 0x004106A3 Options45242F_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
    // EXTERNAL: TITANIUM 0x0040F8A0 Options45242F_guess::Apply_guess
    void Apply_guess(int value_guess);
};

struct CharData45242F_guess {
    unsigned char padding000_guess[0xE0C];
    int valueE0C_guess;
    unsigned char valueE10_guess;
    unsigned char paddingE11_guess[0xE24 - 0xE11];
    unsigned char valueE24_guess;
    unsigned char valueE25_guess;
    unsigned char paddingE26_guess[0xC280 - 0xE26];
    Options45242F_guess optionsC280_guess;

    // EXTERNAL: TITANIUM 0x005ED4F0 CharData45242F_guess::SetFlag_guess
    void SetFlag_guess(bool flag_guess);
};

struct Group45242F_guess {
    // EXTERNAL: TITANIUM 0x0040A77A Group45242F_guess::IsGuildValid_guess
    char IsGuildValid_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0040AC55 Group45242F_guess::GetName_guess
    char* GetName_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0040B8CB Group45242F_guess::Handle_guess
    void Handle_guess(int zero_guess, int second_guess, void* data_guess, int fourth_guess);
};

struct Game45242F_guess {
    // EXTERNAL: TITANIUM 0x004966EE Game45242F_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004A1350 Game45242F_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x004A1CE4 Game45242F_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x004AE514 Game45242F_guess::WriteIni_guess
    void WriteIni_guess(int value_guess, const char* section_guess, const char* key_guess);
};

struct Zone45242F_guess {
    // EXTERNAL: TITANIUM 0x005F6D00 Zone45242F_guess::CheckA_guess
    char CheckA_guess(int zone_guess);
    // EXTERNAL: TITANIUM 0x005F6CC0 Zone45242F_guess::CheckB_guess
    char CheckB_guess(int zone_guess);
};

struct Notify45242F_guess {
    // EXTERNAL: TITANIUM 0x004E335A Notify45242F_guess::Refresh_guess
    void Refresh_guess(int value_guess);
};

struct Tracker45242F_guess {
    // EXTERNAL: TITANIUM 0x005032E3 Tracker45242F_guess::Remove_guess
    void Remove_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0050353E Tracker45242F_guess::Add_guess
    void Add_guess(Spawn45242F_guess* spawn_guess);
};

#define g_player45242F_guess EQ_GLOBAL(Spawn45242F_guess*, 0x00905CE4)
#define g_target45242F_guess EQ_GLOBAL(Spawn45242F_guess*, 0x00905D04)
#define g_charData45242F_guess EQ_GLOBAL(CharData45242F_guess*, 0x00905D00)
#define g_group45242F_guess EQ_GLOBAL(Group45242F_guess, 0x00905D38)
#define g_game45242F_guess EQ_GLOBAL(Game45242F_guess*, 0x00988DF0)
#define g_zone45242F_guess EQ_GLOBAL(Zone45242F_guess*, 0x00905CC0)
#define g_zoneId45242F_guess EQ_GLOBAL(int, 0x00924470)
#define g_connection45242F_guess EQ_GLOBAL(char, 0x00905CA0)
#define g_notify45242F_guess EQ_GLOBAL(Notify45242F_guess*, 0x00850C5C)
#define pinstCFindLocationWnd_guess EQ_GLOBAL(Tracker45242F_guess*, 0x009919C4)
#define g_optionId45242F_guess EQ_GLOBAL(int, 0x00923D94)
#define g_anonymous45242F_guess EQ_GLOBAL(int, 0x00924954)

// OP_SpawnAppearance (0x7C32): {spawn id (0 = us), type, value}; each type sets one spawn property.
// FUNCTION: TITANIUM 0x0045242F
// @early-stop: budget, structural ndiff=110
// SpawnAppearance_Struct {spawn id (0 = self), type, parameter}. Types per EQEmu's appearance numbering:
// 3 invisible (drops the target), 4 PvP, 5 light, 0xE animation, 0xF sneak, 0x10 spawn id (and re-asks
// bazaar 0x1EE9 / barter 0x7460 state), 0x11 HP, 0x12 linkdead, 0x13 levitate, 0x14 GM, 0x15 anonymous
// (saved to eqclient.ini), 0x16 guild id, 0x17 guild rank, 0x18 AFK, 0x19 pet owner, 0x1D size,
// 0x23-0x25 area HP/mana/endurance regen in thousandths, 0x2B show helm.
void __cdecl Handle_OP_SpawnAppearance_guess(int first_guess, int second_guess, void* data_guess,
                                int fourth_guess) {
    Packet45242F_guess packet_guess;
    char message_guess[256];
    memcpy(&packet_guess, data_guess, 8);

    Spawn45242F_guess* player_guess = g_player45242F_guess;
    Spawn45242F_guess* spawn_guess;
    if (packet_guess.id_guess == 0) {
        spawn_guess = player_guess;
    } else {
        spawn_guess = GetSpawn45242F_guess(packet_guess.id_guess);
    }
    if (spawn_guess == 0) {
        return;
    }

    switch (packet_guess.type_guess) {
    case 0x2B:
        spawn_guess->showHelm_01b8_guess = packet_guess.value_guess == 1;
        break;
    case 0x23:
        spawn_guess->value24_guess = (float)packet_guess.value_guess * 0.001f;
        break;
    case 0x24:
        spawn_guess->value2C_guess = (float)packet_guess.value_guess * 0.001f;
        break;
    case 0x25:
        spawn_guess->value28_guess = (float)packet_guess.value_guess * 0.001f;
        break;
    case 0x1D:
        spawn_guess->SetAvatarHeight_guess((float)packet_guess.value_guess);
        break;
    case 0x1B:
        spawn_guess->isPet_01b5_guess = packet_guess.value_guess != 0;
        break;
    case 0x1F:
        if (spawn_guess->info1A8_guess != 0) {
            spawn_guess->info1A8_guess->value106C_guess = packet_guess.value_guess;
            if (g_notify45242F_guess != 0) {
                g_notify45242F_guess->Refresh_guess(1);
            }
        }
        break;
    case 0x18:
        spawn_guess->SetAFK_guess(packet_guess.value_guess);
        break;
    // Guild membership changes, told in chat (strings 12878-12882) for us or for a member of our guild.
    case 0x16:
        if (player_guess != 0 && spawn_guess == player_guess) {
            if (g_charData45242F_guess != 0 &&
                g_charData45242F_guess->valueE0C_guess != packet_guess.value_guess) {
                if (packet_guess.value_guess >= 0) {
                    FormatNotice_guess(message_guess, 0x324E,
                                       g_group45242F_guess.GetName_guess(
                                           packet_guess.value_guess),
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message_guess, 0x111, 1);
                } else if (g_group45242F_guess.IsGuildValid_guess(
                               g_charData45242F_guess->valueE0C_guess)) {
                    FormatNotice_guess(message_guess, 0x3250,
                                       g_group45242F_guess.GetName_guess(
                                           g_charData45242F_guess->valueE0C_guess),
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message_guess, 0x111, 1);
                } else {
                    pEverQuest->dsp_chat(pStringTable->getString(0x324F, 0), 0x111, 1);
                }
                g_charData45242F_guess->valueE0C_guess = packet_guess.value_guess;
            }
        } else if (g_charData45242F_guess != 0) {
            int old_guess = spawn_guess->guildId_0288_guess;
            if (old_guess != packet_guess.value_guess) {
                if (g_charData45242F_guess->valueE0C_guess == packet_guess.value_guess &&
                    packet_guess.value_guess >= 0) {
                    FormatNotice_guess(message_guess, 0x3251, spawn_guess->name120_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message_guess, 0x111, 1);
                } else if (g_charData45242F_guess->valueE0C_guess == old_guess &&
                           old_guess >= 0) {
                    FormatNotice_guess(message_guess, 0x3252, spawn_guess->name120_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message_guess, 0x111, 1);
                }
            }
        }
        spawn_guess->guildId_0288_guess = packet_guess.value_guess;
        spawn_guess->Continue_guess();
        g_group45242F_guess.Handle_guess(0, second_guess, data_guess, fourth_guess);
        break;
    // Guild rank 0-2 (member, officer, leader), strings 12883-12888.
    case 0x17:
        if (player_guess != 0 && spawn_guess == player_guess) {
            if (g_charData45242F_guess != 0 &&
                g_charData45242F_guess->valueE10_guess != packet_guess.value_guess &&
                packet_guess.value_guess >= 0 && packet_guess.value_guess <= 2) {
                switch (packet_guess.value_guess) {
                case 0:
                    pEverQuest->dsp_chat(pStringTable->getString(0x3253, 0), 0x111, 1);
                    break;
                case 1:
                    pEverQuest->dsp_chat(pStringTable->getString(0x3254, 0), 0x111, 1);
                    break;
                case 2:
                    pEverQuest->dsp_chat(pStringTable->getString(0x3255, 0), 0x111, 1);
                    break;
                }
                g_charData45242F_guess->valueE10_guess = (unsigned char)packet_guess.value_guess;
            }
        } else if (g_charData45242F_guess != 0 &&
                   spawn_guess->guildRank_027c_guess != packet_guess.value_guess &&
                   g_charData45242F_guess->valueE0C_guess == spawn_guess->guildId_0288_guess &&
                   spawn_guess->guildId_0288_guess >= 0 && packet_guess.value_guess >= 0 &&
                   packet_guess.value_guess <= 2) {
            switch (packet_guess.value_guess) {
            case 0:
                FormatNotice_guess(message_guess, 0x3256, spawn_guess->name120_guess,
                                   0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message_guess, 0x111, 1);
                break;
            case 1:
                FormatNotice_guess(message_guess, 0x3257, spawn_guess->name120_guess,
                                   0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message_guess, 0x111, 1);
                break;
            case 2:
                FormatNotice_guess(message_guess, 0x3258, spawn_guess->name120_guess,
                                   0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message_guess, 0x111, 1);
                break;
            }
        }
        spawn_guess->guildRank_027c_guess = (unsigned char)packet_guess.value_guess;
        spawn_guess->Continue_guess();
        break;
    case 0x1E:
        if (spawn_guess != player_guess) {
            spawn_guess->type_0244_guess = 1;
            spawn_guess->Continue_guess();
        }
        break;
    case 1:
        spawn_guess->level_024c_guess = (char)packet_guess.value_guess;
        break;
    // Type 0x10 also refreshes the bazaar view: in a zone that passes CheckA it sends OP_BazaarSearch
    // (0x1EE9, request 9), in one that passes CheckB OP_Barter (0x7460, code 0x11).
    case 0x10:
        spawn_guess->SetSpawnId_guess(packet_guess.value_guess);
        g_game45242F_guess->Refresh_guess();
        if (g_zone45242F_guess->CheckA_guess(g_zoneId45242F_guess)) {
            int request_guess[5];
            memset(request_guess, 0, sizeof(request_guess));
            request_guess[0] = 9;
            EQSendMessage(&g_connection45242F_guess, OP_BazaarSearch, request_guess, 0x14, 1);
        }
        if (g_zone45242F_guess->CheckB_guess(g_zoneId45242F_guess)) {
            int code_guess = 0x11;
            EQSendMessage(&g_connection45242F_guess, OP_Barter, &code_guess, 4, 1);
        }
        break;
    case 0xE:
        spawn_guess->ChangePosition_guess(packet_guess.value_guess);
        break;
    case 3:
        if (spawn_guess == g_target45242F_guess && spawn_guess != player_guess &&
            packet_guess.value_guess != 0 && spawn_guess->hideMode_0250_guess == 0 &&
            g_charData45242F_guess != 0 &&
            g_charData45242F_guess->optionsC280_guess.TotalSpellAffects_guess(0xD, 1, 0, 1) < 1) {
            g_target45242F_guess = 0;
        }
        spawn_guess->SetHideMode_guess(packet_guess.value_guess);
        spawn_guess->UpdatePlayerVisibility_guess();
        break;
    case 0x19:
        spawn_guess->masterId_025c_guess = packet_guess.value_guess;
        break;
    case 0xF:
        spawn_guess->value1B1_guess = packet_guess.value_guess != 0;
        break;
    case 0x21:
        if (spawn_guess == player_guess) {
            g_game45242F_guess->Reset_guess();
        }
        break;
    case 5:
        if (spawn_guess->light_0253_guess != (unsigned char)packet_guess.value_guess) {
            spawn_guess->light_0253_guess = (unsigned char)packet_guess.value_guess;
            spawn_guess->UpdateLight_guess();
        }
        break;
    case 0x20:
        spawn_guess->aaTitle_0278_guess = packet_guess.value_guess;
        break;
    case 4:
        spawn_guess->pvpFlag_024f_guess = (char)packet_guess.value_guess;
        if (spawn_guess == g_player45242F_guess) {
            g_charData45242F_guess->SetFlag_guess(packet_guess.value_guess != 0);
        }
        spawn_guess->SetNameSpriteTint();
        break;
    case 0x11:
        spawn_guess->hpCurrent_0274_guess = packet_guess.value_guess;
        break;
    case 2:
        spawn_guess->hpMax_0284_guess = packet_guess.value_guess;
        break;
    case 0x12:
        spawn_guess->linkdead_01b2_guess = packet_guess.value_guess != 0;
        spawn_guess->Continue_guess();
        if (spawn_guess == g_player45242F_guess && spawn_guess->linkdead_01b2_guess == 0 &&
            g_charData45242F_guess != 0) {
            g_charData45242F_guess->optionsC280_guess.Apply_guess(1);
        }
        break;
    case 0x14:
        spawn_guess->gm_0256_guess = (char)packet_guess.value_guess;
        spawn_guess->SetNameSpriteTint();
        spawn_guess->Continue_guess();
        if (spawn_guess == g_player45242F_guess && g_charData45242F_guess != 0) {
            g_charData45242F_guess->valueE25_guess =
                g_player45242F_guess->gm_0256_guess != 0;
            g_optionId45242F_guess = 0x16;
            g_game45242F_guess->SavePC_guess(0, 1, 2);
        }
        break;
    case 0x26:
        spawn_guess->display218_guess->SetFlag_guess(packet_guess.value_guess != 0);
        break;
    // Anonymous/roleplay state; for us it is also saved as [Options] Anonymous.
    case 0x15:
        spawn_guess->anon_0264_guess = (unsigned char)packet_guess.value_guess;
        spawn_guess->SetNameSpriteTint();
        spawn_guess->Continue_guess();
        if (spawn_guess == g_player45242F_guess && g_charData45242F_guess != 0) {
            g_charData45242F_guess->valueE24_guess =
                (unsigned char)g_player45242F_guess->anon_0264_guess;
            g_optionId45242F_guess = 5;
            g_game45242F_guess->SavePC_guess(0, 1, 3);
            g_anonymous45242F_guess = g_player45242F_guess->anon_0264_guess;
            g_game45242F_guess->WriteIni_guess(g_anonymous45242F_guess, "Options",
                                               "Anonymous");
        }
        break;
    case 0x13:
        spawn_guess->SetLevitate_guess(packet_guess.value_guess);
        if (spawn_guess->info1A8_guess->mount15C_guess != 0) {
            spawn_guess->info1A8_guess->mount15C_guess->SetLevitate_guess(
                packet_guess.value_guess);
        }
        break;
    case 0x22:
        if (packet_guess.value_guess == 1) {
            spawn_guess->flags1B0_guess |= 1;
            if (pinstCFindLocationWnd_guess != 0) {
                pinstCFindLocationWnd_guess->Add_guess(spawn_guess);
            }
        } else {
            spawn_guess->flags1B0_guess = 0;
            if (pinstCFindLocationWnd_guess != 0) {
                pinstCFindLocationWnd_guess->Remove_guess(spawn_guess->spawnId_0258_guess);
            }
        }
        break;
    case 0x27:
        spawn_guess->value298_guess = packet_guess.value_guess;
        spawn_guess->SwapNPCMaterials_guess();
        break;
    }
    spawn_guess->Update_guess();
}


struct Argument453134_guess {
    int operation_guess;
    unsigned char value4_guess;
};

struct Argument452D41_guess {
    int value0_guess;
    int index4_guess;
    int elapsed8_guess;
};

// FUNCTION: TITANIUM 0x00452D41
// Probably EQEmu's UseAA_Struct: starts reuse timer `index` (0-29) from the server's begin time.
void __cdecl Handle_OP_AAAction_guess(Argument452D41_guess* argument_guess) {
    int time_guess = GetClientTime_guess();
    time_guess -= argument_guess->elapsed8_guess;
    EQ_GLOBAL(int, 0x00900480) = time_guess;

    if (g_target4521State_guess != 0) {
        int index_guess = argument_guess->index4_guess;
        if (index_guess >= 0 && index_guess < 0x1E) {
            g_target4521State_guess->Update_guess(
                index_guess, argument_guess->value0_guess + time_guess);
        }
    }

    if (g_updateObject453A24Ready_guess != 0) {
        g_updateObject453A24Ready_guess->Finish_guess();
    }
}

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    char* getString(int code_guess, int zero_guess);
};

#define g_catalog452D85_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
struct Argument452D85_guess {
    int value0_guess;
    int value4_guess;
};

// FUNCTION: TITANIUM 0x00452D85
// Nonzero +4: "You successfully applied the poison." (0x3269), else the failure text (0x326A).
void __cdecl Handle_OP_ApplyPoison_guess(Argument452D85_guess* argument_guess) {
    g_target4521Result_guess = 0;
    g_target4520A1Count_guess = 0;
    if (argument_guess->value4_guess != 0) {
        pEverQuest->dsp_chat(g_catalog452D85_guess->getString(0x3269, 0),
                                             0x10e, 1);
    } else {
        pEverQuest->dsp_chat(g_catalog452D85_guess->getString(0x326a, 0),
                                             0x10e, 1);
    }
}

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float first_guess, float second_guess,
                                 float third_guess, float fourth_guess);

// FUNCTION: TITANIUM 0x00452DC6
// @early-stop: budget, structural ndiff=162
// "%1 yells for help from ..." with the direction from the player's heading: the relative angle
// (0-256, half the 512-unit circle) picks ahead (0x326B), behind (0x326C) or one of the six sides.
void __cdecl Handle_OP_YellForHelp_guess(int* argument_guess) {
    char message_guess[256];
    float local_10c_guess;
    float local_110_guess;
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(*argument_guess);
    int zero_guess = 0;

    if (target_guess == (DispatchTarget_guess*)zero_guess ||
        g_propertyOwnerCurrent_guess == (DispatchTarget_guess*)zero_guess) {
        return;
    }

    local_110_guess = g_propertyOwnerCurrent_guess->value34_guess;
    local_10c_guess = g_propertyOwnerCurrent_guess->value30_guess;
    local_10c_guess = get_bearing_guess(
        local_10c_guess, local_110_guess, target_guess->value30_guess,
        target_guess->value34_guess);
    g_updateSettings_guess->TrueDistance_guess(
        g_propertyOwnerCurrent_guess->value30_guess,
        g_propertyOwnerCurrent_guess->value34_guess,
        g_propertyOwnerCurrent_guess->value38_guess,
        target_guess->value30_guess, target_guess->value34_guess,
        target_guess->value38_guess, 0.0f);

    float angle_guess = g_updateSettings_guess->HeadingDiff_guess(
        g_propertyOwnerCurrent_guess->heading_004c_guess, local_10c_guess,
        &local_110_guess);
    int messageId_guess;
    bool side_guess =
        (g_propertyOwnerCurrent_guess->heading_004c_guess < local_10c_guess &&
         local_110_guess < 0.0f) ||
        (local_10c_guess < g_propertyOwnerCurrent_guess->heading_004c_guess &&
         0.0f < local_110_guess);

    if (angle_guess < 0.0f || angle_guess > 32.0f) {
        if (!(angle_guess <= 224.0f || angle_guess > 256.0f)) {
            messageId_guess = 0x326c;
        } else if (side_guess) {
            if (angle_guess <= 32.0f || angle_guess > 96.0f) {
                if (angle_guess <= 96.0f || angle_guess > 160.0f) {
                    if (angle_guess <= 160.0f) {
                        return;
                    }
                    if (angle_guess > 224.0f) {
                        return;
                    }
                    messageId_guess = 0x326f;
                } else {
                    messageId_guess = 0x326e;
                }
            } else {
                messageId_guess = 0x326d;
            }
        } else if (angle_guess <= 32.0f || angle_guess > 96.0f) {
            if (angle_guess <= 96.0f || angle_guess > 160.0f) {
                if (angle_guess <= 160.0f) {
                    return;
                }
                if (angle_guess > 224.0f) {
                    return;
                }
                messageId_guess = 0x3272;
            } else {
                messageId_guess = 0x3271;
            }
        } else {
            messageId_guess = 0x3270;
        }
    } else {
        messageId_guess = 0x326b;
    }

    char* text_guess = g_target4520E5Data_guess->GetText_guess(target_guess->name_0120_guess);
    FormatNotice_guess(message_guess, messageId_guess, text_guess,
                       (const char*)zero_guess, (const char*)zero_guess,
                       zero_guess, zero_guess, zero_guess, zero_guess,
                       zero_guess, zero_guess);
    g_target4520E5Data_guess->dsp_chat(message_guess, 0x11a, 1);
}

struct Argument453062_guess {
    int operation_guess;
};

// FUNCTION: TITANIUM 0x00453062
// Asks "Die & lose exp?" (0x235E) in a yes/no box (type 0x65) that stays up for an hour.
void __cdecl Handle_OP_Sacrifice_guess(Argument453062_guess* argument_guess) {
    char message_guess[512];
    char name_guess[64];
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess == 0) {
        strcpy(name_guess, "Someone");
    } else {
        strcpy(name_guess, target_guess->name_0120_guess);
    }
    FormatNotice_guess(message_guess, 0x235e, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    g_noticeSender_guess->Activate(g_noticeValue_guess != 0 ? g_noticeValue_guess + 8 : 0,
                                     0x65, message_guess, 0xc,
                                     3600000, 0, 0);
}

struct Argument4530F6_guess {
    int operation_guess;
    int value4_guess;
};

// FUNCTION: TITANIUM 0x004530F6
// Sets the spawn's trader flag and refreshes the bazaar window.
void __cdecl Handle_OP_BecomeTrader_guess(Argument4530F6_guess* argument_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess != 0 && target_guess->pActorInfo_01a8_guess != 0) {
        target_guess->pActorInfo_01a8_guess->value106c_guess = argument_guess->value4_guess;
        target_guess->Continue_guess();
        if (g_noticeEnabled_guess != 0) {
            g_noticeEnabled_guess->Update_guess(1);
        }
    }
}

// OP_LFGAppearance: stores the spawn's LFG flag (+0x1B4) and refreshes its name sprite.
// FUNCTION: TITANIUM 0x00453134
void __cdecl Handle_OP_LFGAppearance_guess(Argument453134_guess* argument_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess != 0) {
        target_guess->lfg_01b4_guess = argument_guess->value4_guess;
        return target_guess->Continue_guess();
    }
}

struct PropertyOwner453158_guess {
    unsigned char padding00_guess[0x30];
    float value30_guess;
    float value34_guess;
    unsigned char padding38_guess[0x4C - 0x38];
    float value4C_guess;
};

#define g_propertyOwner453158_guess EQ_GLOBAL(PropertyOwner453158_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float x_guess, float y_guess, float x2_guess, float y2_guess);

struct Point453158_guess {
    float x_guess;
    float y_guess;
};

// FUNCTION: TITANIUM 0x00453158
// @early-stop: budget, structural ndiff=3
// Opcode 0x76B1: turns the player toward the trap and says "You sense a trap in this direction."
void __cdecl Handle_SenseTrapsReply_guess(Point453158_guess* point_guess) {
    if (g_propertyOwner453158_guess != 0) {
        float y_guess = g_propertyOwner453158_guess->value34_guess;
        float x_guess = g_propertyOwner453158_guess->value30_guess;
        g_propertyOwner453158_guess->value4C_guess =
            get_bearing_guess(x_guess, y_guess, point_guess->x_guess, point_guess->y_guess);
        pEverQuest->dsp_chat(pStringTable->getString(0x559, 0), 0x10e, 1);
    }
}

// FUNCTION: TITANIUM 0x004531C0
// Opcode 0x6259: sets timer `index` to expire `seconds` from now.
void __cdecl UpdateValueNow_guess(UpdateValue_guess* value_guess) {
    if (g_updateEnabled_guess != 0) {
        g_updateValues_guess[value_guess->index_guess] =
            value_guess->seconds_guess * 1000 + g_updateSettings_guess->frameTime_0148_guess;
    }
}

// FUNCTION: TITANIUM 0x004531EC
// OP_LootItem from the server: tells the loot window about the item at +8.
void __cdecl Handle_OP_LootItem_guess(NotifyArgument_guess* argument_guess) {
    g_notifyReceiver_guess->HandleLootItemReply_guess(argument_guess->value8_guess);
}

// FUNCTION: TITANIUM 0x004531FF
// OP_QueryResponseThing (0x1974): answers the server's query with the value and its resolved code.
void __cdecl SendMetadata_guess(int* value_guess) {
    MessageRecord_guess local_message_guess;

    local_message_guess.original_guess = *value_guess;
    local_message_guess.resolved_guess = ChecksumCodeRangesA_guess(local_message_guess.original_guess);
    EQSendMessage(g_messageBuffer_guess, 0x1974, &local_message_guess, 8, 1);
}

struct Argument453231_guess {
    unsigned char padding0_guess[4];
    int operation_guess;
};

struct PropertyNotice453231_guess {
    int property_guess;
    int spawnId_0004_guess;
    unsigned char mode_guess;
};

#define g_propertyNoticeMode_guess EQ_GLOBAL(unsigned char, 0x009238E0)
#define g_previousProperty_guess EQ_GLOBAL(int, 0x009238D8)
#define g_lastProperty_guess EQ_GLOBAL(int, 0x009238DC)

struct PropertyNoticeService_guess {
    // EXTERNAL: TITANIUM 0x00564E7E PropertyNoticeService_guess::FUN_00564e7e_guess
    void FUN_00564e7e_guess(int message_guess, int value_guess);
};

#define g_propertyNoticeEnabled_guess EQ_GLOBAL(PropertyNoticeService_guess*, 0x009928E0)

// EXTERNAL: TITANIUM 0x0046DA4A FormatPropertyNotice_guess
void __cdecl FormatPropertyNotice_guess(char* buffer_guess, int message_guess,
                                        const char* name_guess, int zero3_guess,
                                        int zero4_guess, int zero5_guess, int zero6_guess,
                                        int zero7_guess, int zero8_guess, int zero9_guess,
                                        int zero10_guess);

// FUNCTION: TITANIUM 0x00453231
// Shows "%1 has challenged you" (0x592), or "has accepted your challenge" (0x590) when it answers the
// player's own. Otherwise auto-declines with 0x3EA0: mode 0 ignored sender, 1 already dueling, 2 busy.
void __cdecl Handle_OP_RequestDuel_guess(Argument453231_guess* argument_guess) {
    PropertyNotice453231_guess notice_guess;
    char message_guess[512];
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(argument_guess->operation_guess);

    if (target_guess == 0) {
        return;
    }

    if (g_target4520E5Data_guess->BeingIgnored_guess(target_guess->name_0120_guess) != 0) {
        notice_guess.property_guess = target_guess->spawnId_0258_guess;
        notice_guess.spawnId_0004_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
        notice_guess.mode_guess = 0;
    } else if (g_propertyNoticeMode_guess != 0) {
        int property_guess = target_guess->spawnId_0258_guess;
        if (g_previousProperty_guess == property_guess) {
            return;
        }
        notice_guess.property_guess = property_guess;
        notice_guess.spawnId_0004_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
        notice_guess.mode_guess = 1;
    } else {
        int property_guess = target_guess->spawnId_0258_guess;
        if (g_previousProperty_guess == property_guess) {
            g_lastProperty_guess = property_guess;
            g_propertyNoticeMode_guess = 1;
            FormatPropertyNotice_guess(message_guess, 0x590, target_guess->name_0120_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0xf, 1);
            return;
        }
        if (g_previousProperty_guess == 0) {
            if (g_lastProperty_guess == 0) {
                g_lastProperty_guess = property_guess;
                FormatPropertyNotice_guess(message_guess, 0x592, target_guess->name_0120_guess,
                                           0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message_guess, 0xf, 1);
                if (g_propertyNoticeEnabled_guess != 0) {
                    g_propertyNoticeEnabled_guess->FUN_00564e7e_guess(0x1a, 0);
                }
                return;
            }
            if (g_lastProperty_guess == property_guess) {
                return;
            }
        }
        notice_guess.property_guess = property_guess;
        notice_guess.spawnId_0004_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
        notice_guess.mode_guess = 2;
    }

    EQSendMessage(g_messageBuffer_guess, 0x3ea0, &notice_guess, 0xc, 1);
}

struct Argument4533B6_guess {
    char name0_guess[0x40];
    char name40_guess[0x40];
    unsigned char flag80_guess;
    char text81_guess[0x80];
};

// FUNCTION: TITANIUM 0x004533B6
// Also OP_DenyResponse (0x7C66). Prints "You have given/denied %1 permission to drag your corpse" when the
// player gave consent, or the "You have been given/denied" text when someone else did.
void __cdecl Handle_OP_ConsentResponse_guess(Argument4533B6_guess* argument_guess) {
    char message_guess[512];

    if (g_updateEnabled_guess == 0) {
        return;
    }
    if (__stricmp(g_propertyOwnerCurrent_guess->name_0120_guess,
                  argument_guess->name40_guess) == 0) {
        if (argument_guess->flag80_guess != 0) {
            FormatNotice_guess(message_guess, 0x593, argument_guess->name0_guess,
                               argument_guess->text81_guess,
                               0, 0, 0, 0, 0, 0, 0);
        } else {
            FormatNotice_guess(message_guess, 0x594, argument_guess->name0_guess,
                               argument_guess->text81_guess,
                               0, 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (g_target4520E5Data_guess->BeingIgnored_guess(argument_guess->name40_guess) != 0) {
            return;
        }
        if (argument_guess->flag80_guess != 0) {
            FormatNotice_guess(message_guess, 0x820, argument_guess->name40_guess,
                               argument_guess->text81_guess,
                               0, 0, 0, 0, 0, 0, 0);
            if (g_target454B65_guess != 0) {
                g_target454B65_guess->Run_guess(0x1c, 0);
            }
        } else {
            FormatNotice_guess(message_guess, 0x837, argument_guess->name40_guess,
                               argument_guess->text81_guess,
                               0, 0, 0, 0, 0, 0, 0);
        }
    }
    g_target4520E5Data_guess->dsp_chat(message_guess, 0x111, 1);
}

struct Argument4534AB_guess {
    int operation_guess;
    char name4_guess[1];
};

// OP_Illusion: applies the illusion to the spawn by id, or to the player when the name matches it
// (0x00485873).
// FUNCTION: TITANIUM 0x004534AB
void __cdecl Handle_OP_Illusion_guess(Argument4534AB_guess* argument_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess == 0) {
        if (g_propertyOwnerCurrent_guess == 0) {
            return;
        }
        if (strcmp(argument_guess->name4_guess,
                   g_propertyOwnerCurrent_guess->name_0120_guess) != 0) {
            return;
        }
        target_guess = g_propertyOwnerCurrent_guess;
        if (target_guess == 0) {
            return;
        }
    }
    target_guess->ApplyIllusion_guess(argument_guess);
}

struct UpdatePair4534ED_guess {
    int value0_guess;
    int value4_guess;
};

// FUNCTION: TITANIUM 0x004534ED
// Loads the 240 (0xF0) AA rank pairs into pCharData and refreshes the AA window.
void __cdecl Handle_OP_RespondAA_guess(int unused1_guess, int unused2_guess,
                                UpdatePair4534ED_guess* values_guess) {
    if (g_target4521State_guess != 0 && g_target4521State_guess->pSpawn_c288_guess != 0 &&
        g_target4521State_guess->pSpawn_c288_guess->value1A8_guess != 0) {
        for (int index_guess = 0; index_guess < 0xF0; ++index_guess) {
            g_target4521State_guess->Set4534EDSecond_guess(
                index_guess, values_guess[index_guess].value4_guess);
            g_target4521State_guess->Set4534EDFirst_guess(
                index_guess, values_guess[index_guess].value0_guess);
        }
        g_target4521State_guess->valueC28C_guess = 1;
        g_target4521State_guess->valueC350_guess = 0;
        g_target4521State_guess->ReapplyAltAbilities_guess();
    }
    if (g_updateObject453A24Ready_guess != 0) {
        return g_updateObject453A24Ready_guess->Finish_guess();
    }
}

// FUNCTION: TITANIUM 0x00453571
// Also OP_BazaarSearch (0x1EE9). Action 9 is the bazaar welcome (strings 0x1A6A-0x1A6C with trader and
// item counts); other OP_Trader actions go to the trader window, bazaar searches to the bazaar window.
void __cdecl Handle_OP_Trader_guess(int unused_guess, int operation_guess,
                                Argument453571_guess* argument_guess,
                                int value_guess) {
    int saved_value_guess;
    char noticeBuffer_guess[512];
    int zero_guess = 0;

    if (g_updateEnabled_guess != 0) {
        if (argument_guess->operation_guess == 9) {
            pEverQuest->dsp_chat(
                g_catalog452D85_guess->getString(0x1a6a, zero_guess), 10, 1);

            saved_value_guess = argument_guess->value4_guess;
            int source_value_guess = argument_guess->value8_guess;
            FormatNotice_guess(
                noticeBuffer_guess, 0x1a6b,
                _itoa(saved_value_guess, (char*)EQ_ARRAY(char, 0x0099DB00), 10),
                _itoa(source_value_guess,
                      (char*)EQ_ARRAY(char, 0x0099DAE0), 10),
                (const char*)zero_guess, zero_guess, zero_guess, zero_guess,
                zero_guess, zero_guess, zero_guess);
            pEverQuest->dsp_chat(noticeBuffer_guess, 10, 1);
            pEverQuest->dsp_chat(
                g_catalog452D85_guess->getString(0x1a6c, zero_guess), 10, 1);
        } else if (operation_guess == 0x524e) {
            g_handler453571A_guess->Handle_guess(argument_guess);
        } else if (operation_guess == 0x1ee9) {
            g_handler453571B_guess->HandleBazaarMsg(argument_guess, value_guess);
        }
    }
}

struct Argument453681_guess {
    int key0_guess;
    int value4_guess;
    int value8_guess;
    unsigned char valueC_guess;
    unsigned char padding_guess[3];
    unsigned char value10_guess;
    unsigned char padding11_guess[3];
    int value14_guess;
    int value18_guess;
};

struct ItemInfo_guess {
    char text0_guess[0xB0];
    int valueB0_guess;
    unsigned char paddingB4_guess[8];
    int valueBC_guess;
    unsigned char paddingC0_guess[0x26C - 0xC0];
    unsigned char value26C_guess;
    unsigned char value26D_guess;
    unsigned char value26E_guess;
    unsigned char value26F_guess;
    unsigned char padding270_guess[0x2C4 - 0x270];

    // EXTERNAL: TITANIUM 0x00601F60 ItemInfo_guess::ItemInfo_guess
    ItemInfo_guess();
};

struct EQ_ItemBase_guess {
    // EXTERNAL: TITANIUM 0x005ECE20 EQ_ItemBase_guess::EQ_ItemBase_guess
    EQ_ItemBase_guess();
};

// EXTERNAL: TITANIUM 0x00644780 ??_7EQ_Item_guess@@6B@
struct EQ_Item_guess : EQ_ItemBase_guess {
    EQ_Item_guess() : EQ_ItemBase_guess() {}
    virtual void Slot00_guess();
    unsigned char padding04_guess[0xA8 - 4];

    // EXTERNAL: TITANIUM 0x005EC620 EQ_Item_guess::Bind453681_guess
    void Bind453681_guess(ItemInfo_guess* object_guess);

    // EXTERNAL: TITANIUM 0x004B1CF4 EQ_Item_guess::SetOpen_guess
    void SetOpen_guess();
};

// FUNCTION: TITANIUM 0x00453681
// @early-stop: budget, structural ndiff=38
// Opens a world container (forge, oven...) for the player: builds a bag item of the object's type
// ('5' gets 2 slots instead of 10). Refuses with 0x57E when in use, 0x5A3 when one is already open.
void __cdecl Handle_OP_ClickObjectAction_guess(Argument453681_guess* argument_guess) {
    if (g_target4520A1Count_guess > 0) {
        --g_target4520A1Count_guess;
    } else {
        g_target4520A1Count_guess = 0;
    }
    if (g_propertyOwnerCurrent_guess != 0 &&
        g_propertyOwnerCurrent_guess->spawnId_0258_guess == argument_guess->key0_guess) {
        if (argument_guess->value8_guess != 0) {
            if (g_stateManager_guess->value6C_guess == 0) {
                ItemInfo_guess* second_guess;
                EQ_Item_guess* first_guess = new EQ_Item_guess;
                second_guess = new ItemInfo_guess;
                second_guess->value26D_guess = argument_guess->value10_guess;
                second_guess->valueBC_guess = argument_guess->value14_guess;
                unsigned char* kindSlot_guess = &second_guess->value26C_guess;
                *kindSlot_guess = argument_guess->valueC_guess;
                unsigned char kind_guess = *kindSlot_guess;
                second_guess->value26D_guess = 10;
                second_guess->value26F_guess = 0;
                second_guess->value26E_guess = 4;
                second_guess->valueB0_guess = argument_guess->value18_guess;
                if (kind_guess == '5') {
                    second_guess->value26D_guess = 2;
                }
                strcpy(second_guess->text0_guess,
                       g_stateManager_guess->GetContainerTypeName_guess(kind_guess));
                first_guess->Bind453681_guess(second_guess);
                first_guess->SetOpen_guess();
                g_stateManager_guess->Attach453681_guess(first_guess,
                                                         argument_guess->value4_guess);
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x5a3, 0));
            }
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x57e, 0));
        }
    }
    g_target4521Result_guess = 0;
}

// OP_PlayerStateAdd: sets the given PlayerState bits on the spawn by id.
// FUNCTION: TITANIUM 0x004537EA
void __cdecl Handle_OP_PlayerStateAdd_guess(DispatchRequest_guess* request_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(request_guess->operation_guess);
    if (target_guess != 0) {
        target_guess->AddPlayerState_guess(request_guess->first_guess);
    }
}

// OP_PlayerStateRemove: clears the given PlayerState bits on the spawn by id.
// FUNCTION: TITANIUM 0x00453807
void __cdecl Handle_OP_PlayerStateRemove_guess(DispatchRequest_guess* request_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(request_guess->operation_guess);
    if (target_guess != 0) {
        target_guess->RemovePlayerState_guess(request_guess->first_guess);
    }
}

// OP_WeaponEquip1: stores the spawn's weapon value for the index, without echoing it (0x0047C0C2).
// FUNCTION: TITANIUM 0x00453824
void __cdecl Handle_OP_WeaponEquip1_guess(DispatchRequest_guess* request_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(request_guess->operation_guess);
    if (target_guess != 0) {
        target_guess->ApplyTwo_guess(request_guess->first_guess, request_guess->second_guess, 0);
    }
}

// FUNCTION: TITANIUM 0x00453846
// Closes the open world container.
void __cdecl Handle_OP_ClearObject_guess(StateRequest_guess* request_guess) {
    if (request_guess != 0 && request_guess->state_guess == 0) {
        g_stateManager_guess->Apply_guess(request_guess->value4_guess);
        return;
    }
    g_stateManager_guess->Reset_guess();
}

#define g_flags45386DValue_guess EQ_GLOBAL(unsigned, 0x009247B8)
#define g_flags45386D0_guess EQ_GLOBAL(int, 0x00924790)
#define g_flags45386D1_guess EQ_GLOBAL(int, 0x00924794)
#define g_flags45386D2_guess EQ_GLOBAL(int, 0x00924798)
#define g_flags45386D3_guess EQ_GLOBAL(int, 0x0092479C)
#define g_flags45386D4_guess EQ_GLOBAL(int, 0x009247A0)
#define g_flags45386D5_guess EQ_GLOBAL(int, 0x009247A4)
#define g_flags45386D6_guess EQ_GLOBAL(int, 0x009247A8)
#define g_flags45386D7_guess EQ_GLOBAL(int, 0x009247AC)
#define g_flags45386D8_guess EQ_GLOBAL(int, 0x009247B0)
#define g_flags45386D9_guess EQ_GLOBAL(int, 0x009247B4)
#define g_flags45386DClear_guess EQ_GLOBAL(int, 0x0092485C)

// FUNCTION: TITANIUM 0x0045386D
// @early-stop: budget, structural ndiff=21
// Splits the account's expansion bits into flags 0x00924790..: 1 Kunark, 2 Velious, 4 Luclin, 8 PoP,
// 0x10 LoY, 0x20 LDoN, 0x40 GoD, 0x80 OoW, 0x100 DoN, 0x200 DoD. The `&= 0` on 0x0092485C is original.
void __cdecl Handle_OP_ExpansionInfo(unsigned* value_guess) {
    g_flags45386DValue_guess = *value_guess;
    g_flags45386D0_guess = ((int)(char)*value_guess) & 1;
    g_flags45386D1_guess = (unsigned)(((int)(char)*value_guess) & 2) >> 1;
    g_flags45386D2_guess = (unsigned)(((int)(char)*value_guess) & 4) >> 2;
    g_flags45386D3_guess = (unsigned)(((int)(char)*value_guess) & 8) >> 3;
    g_flags45386D4_guess = (unsigned)(((int)(char)*value_guess) & 0x10) >> 4;
    g_flags45386D5_guess = (unsigned)(((int)(char)*value_guess) & 0x20) >> 5;
    g_flags45386D6_guess = (unsigned)(((int)(char)*value_guess) & 0x40) >> 6;
    g_flags45386D7_guess = (((unsigned char)*value_guess & 0x80) != 0);
    g_flags45386D8_guess = (*value_guess >> 8) & 1;
    g_flags45386DClear_guess &= 0;
    g_flags45386D9_guess = (*value_guess >> 9) & 1;
}

struct UpdateObject453A24_guess {
    unsigned char padding_guess[0xE10];
    unsigned char valueE10_guess;
    unsigned char paddingE11_guess[0x17];
    int valueE28_guess;
    unsigned char paddingE2C_guess;
    unsigned char valueE2D_guess;

    // EXTERNAL: TITANIUM 0x005ED750 UpdateObject453A24_guess::SetValue_guess
    void SetValue_guess(int value_guess);
};

#define g_updateObject453A24_guess EQ_GLOBAL(UpdateObject453A24_guess*, 0x00905D00)

struct Controller453912_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 Controller453912_guess::Check_guess
    char Check_guess();

    // EXTERNAL: TITANIUM 0x0054407F Controller453912_guess::Run_guess
    void Run_guess(int* argument_guess, int second_guess);
};

struct StringTableView2_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView2_guess::getString
    char* getString(int code_guess, int zero_guess);
};

#define g_controller453912_guess EQ_GLOBAL(Controller453912_guess*, 0x00850C98)
#define g_catalog453912_guess EQ_GLOBAL(StringTableView2_guess*, 0x00905CB0)
// EXTERNAL: TITANIUM 0x00467441 FormatText453962_guess
void __cdecl FormatText453962_guess(char* destination_guess, char* text_guess,
                                    char** cursor_guess, int fourth_guess,
                                    int fifth_guess);

extern "C" char* __cdecl strncpy(char* destination_guess, const char* source_guess,
                                 unsigned count_guess);

struct State4539D3_guess {
    unsigned char padding_guess[0x1A10];
    int value1A10_guess;
    int value1A14_guess;
};

struct Argument4539D3_guess {
    unsigned value0_guess;
    int value4_guess;
};

#define g_state4539D3_guess EQ_GLOBAL(State4539D3_guess*, 0x00905D00)

// FUNCTION: TITANIUM 0x00453912
// Opcode 0x10A6 (GM): opens the checked-out petition, or says it is taken or deleted (id -1, 0x55C).
void __cdecl Handle_PetitionCheckout_guess(int* value_guess, int second_guess) {
    if (g_controller453912_guess != 0) {
        if (g_controller453912_guess->Check_guess()) {
            if (*value_guess == -1) {
                pEverQuest->dsp_chat(
                    g_catalog453912_guess->getString(0x55C, 0), 0x12, 1);
                return;
            }
            g_controller453912_guess->Run_guess(value_guess, second_guess);
        }
    }
}

// FUNCTION: TITANIUM 0x00453962
// Opcode 0x71F8: "Your petition text is : %1"; the text is the second string of the payload.
void __cdecl ShowPetitionText_guess(char* text_guess) {
    char buffer_guess[2048];
    char* original_guess = text_guess;
    text_guess = original_guess + strlen(original_guess) + 1;
    FormatText453962_guess(buffer_guess,
                           g_catalog453912_guess->getString(0x13C2, 0),
                           &text_guess, -1, 0);
    pEverQuest->dsp_chat(buffer_guess, 0x111, 1);
}

// FUNCTION: TITANIUM 0x004539D3
// ExpUpdate_Struct {exp, type}: type 2 with exp > 0 also fires window event 9 (probably party exp).
void __cdecl Handle_OP_ExpUpdate_guess(Argument4539D3_guess* argument_guess) {
    if (g_state4539D3_guess != 0) {
        g_state4539D3_guess->value1A10_guess = argument_guess->value0_guess;
        g_state4539D3_guess->value1A14_guess = 0;
        if (g_updateObject453A24Ready_guess != 0) {
            g_updateObject453A24Ready_guess->Finish_guess();
        }
        if (argument_guess->value4_guess == 2 &&
            g_target454B65_guess != 0 && argument_guess->value0_guess > 0) {
            g_target454B65_guess->Run_guess(9, 0);
        }
    }
}

struct Argument453A24_guess {
    int value0_guess;
    int value4_guess;
    unsigned char value8_guess;
};

// FUNCTION: TITANIUM 0x00453A24
// AltAdvStats_Struct: unspent points, AA exp, and the percent going to AA.
void __cdecl Handle_OP_AAExpUpdate_guess(Argument453A24_guess* argument_guess) {
    if (g_updateObject453A24_guess != 0) {
        g_updateObject453A24_guess->valueE28_guess = argument_guess->value0_guess;
        g_updateObject453A24_guess->SetValue_guess(argument_guess->value4_guess);
        g_updateObject453A24_guess->valueE2D_guess = argument_guess->value8_guess;
        if (g_updateObject453A24Ready_guess != 0) {
            return g_updateObject453A24Ready_guess->Finish_guess();
        }
    }
}

struct Argument453A68_guess {
    double value0_guess;
    int value8_guess;
    double value10_guess;
    int value18_guess;
};

struct UpdateProcessor453A68_guess {
    // EXTERNAL: TITANIUM 0x00527130 UpdateProcessor453A68_guess::UpdateRows_guess
    void UpdateRows_guess();
};

#define g_updateProcessor453A68_guess EQ_GLOBAL(UpdateProcessor453A68_guess*, 0x00991C24)

// OP_LeadershipExpUpdate (0x596E): stores group leadership exp and points and raid leadership exp and
// points in pCharData (+0xE90, +0xEA0, +0xE98, +0xEA4), then redraws the leadership window
// (0x00991C24; 0x00527130 rewrites its rank and cost rows).
// FUNCTION: TITANIUM 0x00453A68
void __cdecl Handle_OP_LeadershipExpUpdate_guess(Argument453A68_guess* argument_guess) {
    if (g_target4521State_guess != 0) {
        g_target4521State_guess->valueE90_guess = argument_guess->value0_guess;
        g_target4521State_guess->valueEA0_guess = argument_guess->value8_guess;
        g_target4521State_guess->valueE98_guess = argument_guess->value10_guess;
        g_target4521State_guess->valueEA4_guess = argument_guess->value18_guess;
        if (g_updateProcessor453A68_guess != 0) {
            g_updateProcessor453A68_guess->UpdateRows_guess();
        }
    }
}

struct Argument453ABB_guess {
    unsigned char padding00_guess[0x40];
    char name40_guess[0x40];
    int value80_guess;
    int value84_guess;
    int value88_guess;
};

// FUNCTION: TITANIUM 0x00453ABB
// Opcode 0x186D: result -2 "%1 has denied your request for war.", -5 "Could not declare war ...".
void __cdecl Handle_GuildWarFailed_guess(Argument453ABB_guess* argument_guess) {
    char message_guess[256];

    if (argument_guess->value88_guess != -5) {
        if (argument_guess->value88_guess != -2) {
            return;
        }
        FormatNotice_guess(message_guess, 0x1A2E, argument_guess->name40_guess,
                           0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message_guess, 0x111, 1);
    } else {
        pEverQuest->dsp_chat(
            g_catalog452D85_guess->getString(0x1A2F, 0), 0x111, 1);
    }
}

struct TextLookup453B3F_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 TextLookup453B3F_guess::Lookup_guess
    char* Lookup_guess(int key_guess);
};

#define g_textLookup453B3F_guess EQ_GLOBAL(TextLookup453B3F_guess, 0x00905D38)

extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// FUNCTION: TITANIUM 0x00453B3F
// To a guild leader (rank 2): yes/no box (type 0x68, 10 s) for a war declaration of `days` days;
// the box keeps a 0x8C-byte copy of the packet to send back.
void __cdecl Handle_OP_GuildWar_guess(Argument453ABB_guess* argument_guess) {
    char message_guess[512];
    char copy_guess[0x8C];
    char digits_guess[64];

    memset(copy_guess, 0, sizeof(copy_guess));
    if (argument_guess->value88_guess != 0 &&
        g_updateObject453A24_guess->valueE10_guess == 2) {
        FormatNotice_guess(message_guess, 0x2358, argument_guess->name40_guess,
                           g_textLookup453B3F_guess.Lookup_guess(argument_guess->value80_guess),
                           _itoa(argument_guess->value84_guess, digits_guess, 10),
                           0, 0, 0, 0, 0, 0);
        void* copyPointer_guess = operator new(0x8C);
        memcpy(copyPointer_guess, argument_guess, 0x8C);
        g_noticeSender_guess->Activate(
            g_noticeValue_guess != 0 ? g_noticeValue_guess + 8U : 0U, 0x68,
            message_guess, 0xC, 10000, copyPointer_guess, 0);
    }
}

// FUNCTION: TITANIUM 0x00453C24
// Peace offer; same shape as Handle_OP_GuildWar_guess, box type 0x69.
void __cdecl Handle_OP_GuildPeace_guess(Argument453ABB_guess* argument_guess) {
    char message_guess[512];
    char copy_guess[0x8C];

    memset(copy_guess, 0, sizeof(copy_guess));
    if (argument_guess->value88_guess != 0 &&
        g_updateObject453A24_guess->valueE10_guess == 2) {
        FormatNotice_guess(message_guess, 0x2359, argument_guess->name40_guess,
                           g_textLookup453B3F_guess.Lookup_guess(argument_guess->value80_guess),
                           0, 0, 0, 0, 0, 0, 0);
        void* copyPointer_guess = operator new(0x8C);
        memcpy(copyPointer_guess, argument_guess, 0x8C);
        g_noticeSender_guess->Activate(
            g_noticeValue_guess != 0 ? g_noticeValue_guess + 8U : 0U, 0x69,
            message_guess, 0xC, 10000, copyPointer_guess, 0);
    }
}

struct SplitRecord453CF1_guess {
    char prefix_guess[8];
    char* fields_guess[10];
};

// FUNCTION: TITANIUM 0x00453CF1
// @early-stop: budget, structural ndiff=6
// Parses {u32 color, u32 string id, then NUL-separated %1..%9 arguments} into an id plus up to 9 pointers
// (unused ones 0). Used by OP_InterruptCast and the formatted emote. Always returns 0.
int __cdecl SplitStringIdPacket_guess(int source_guess, int length_guess, void* output_guess) {
    char* current_guess = (char*)source_guess;
    char* destination_guess = (char*)output_guess;
    char value_guess = *current_guess++;
    *destination_guess = value_guess;
    value_guess = *current_guess;
    char* nextDestination_guess = destination_guess + 1;
    *nextDestination_guess = value_guess;
    ++nextDestination_guess;
    ++current_guess;
    value_guess = *current_guess;
    *nextDestination_guess = value_guess;
    ++current_guess;
    value_guess = *current_guess;
    nextDestination_guess[1] = value_guess;
    ++current_guess;
    value_guess = *current_guess;
    nextDestination_guess = destination_guess + 4;
    *nextDestination_guess = value_guess;
    ++nextDestination_guess;
    ++current_guess;
    value_guess = *current_guess;
    *nextDestination_guess = value_guess;
    ++nextDestination_guess;
    ++current_guess;
    value_guess = *current_guess;
    *nextDestination_guess = value_guess;
    ++current_guess;
    value_guess = *current_guess;
    nextDestination_guess[1] = value_guess;
    int count_guess = 1;
    ++current_guess;
    length_guess -= 6;
    SplitRecord453CF1_guess* record_guess = (SplitRecord453CF1_guess*)output_guess;
    record_guess->fields_guess[0] = current_guess;
    unsigned index_guess = 0;
    if (length_guess != 0) {
        char** next_guess = &record_guess->fields_guess[1];
        do {
            if (current_guess[index_guess] == 0 && index_guess < length_guess - 1) {
                *next_guess = current_guess + index_guess + 1;
                ++count_guess;
                ++next_guess;
            }
            ++index_guess;
        } while (index_guess < length_guess);
        if (count_guess >= 10) {
            return 0;
        }
    }
    char** field_guess = &record_guess->fields_guess[count_guess];
    int remaining_guess = 10 - count_guess;
    for (; remaining_guess != 0; --remaining_guess) {
        *field_guess++ = 0;
    }
    return 0;
}

struct Argument453D7B_guess {
    int first_guess;
    int second_guess;
    unsigned char enabled_guess;
};

#define g_target453D7BBusy_guess EQ_GLOBAL(int, 0x00850BAC)

// EXTERNAL: TITANIUM 0x005422B5 Continue453D7B_guess
void __cdecl Continue453D7B_guess();

// FUNCTION: TITANIUM 0x00453D7B
// @early-stop: budget, structural ndiff=26
// Charm_Struct {owner, pet, on}: sets or clears (-1) the owner's pet id.
void __cdecl Handle_OP_Charm_guess(Argument453D7B_guess* argument_guess) {
    Target452198Target_guess* target_guess =
        (Target452198Target_guess*)ResolveDispatch_guess(argument_guess->first_guess);
    Target452198Node_guess* node_guess =
        (Target452198Node_guess*)ResolveDispatch_guess(argument_guess->second_guess);
    if (target_guess != 0 && node_guess != 0 && node_guess->value1B3_guess == 0 &&
        node_guess->Check_guess() == 0 && node_guess->value260_guess != 0x6C) {
        Target452198Output_guess* output_guess =
            (Target452198Output_guess*)target_guess->pActorInfo_01a8_guess;
        if (argument_guess->enabled_guess == 1) {
            if (output_guess != 0) {
                output_guess->value16C_guess = node_guess->value258_guess;
            }
        } else if (output_guess != 0) {
            output_guess->value16C_guess |= 0xFFFFFFFF;
        }
        if (g_target453D7BBusy_guess != 0) {
            Continue453D7B_guess();
        }
    }
}

// FUNCTION: TITANIUM 0x00453DFB
// String `id_guess` from pStringTable with up to nine %n arguments.
void __cdecl FormatStringWithParameters_guess(char* destination_guess, int id_guess, int a3_guess,
                                int a4_guess, int a5_guess, int a6_guess, int a7_guess,
                                int a8_guess, int a9_guess, int a10_guess, int a11_guess) {
    int args_guess[9];
    args_guess[0] = a3_guess;
    args_guess[1] = a4_guess;
    args_guess[2] = a5_guess;
    args_guess[3] = a6_guess;
    args_guess[4] = a7_guess;
    args_guess[5] = a8_guess;
    args_guess[6] = a9_guess;
    args_guess[7] = a10_guess;
    args_guess[8] = a11_guess;
    FormatText453962_guess(destination_guess, pStringTable->getString(id_guess, 0),
                           (char**)args_guess, -1, 0);
}

// FUNCTION: TITANIUM 0x00453E5D
// The server's answer to opening a trader: opens the merchant window on it unless +0xC refuses.
void __cdecl Handle_OP_TraderShop_guess(Argument453E5D_guess* argument_guess) {
    if (g_target4521Busy_guess == 0) {
        DispatchTarget_guess* result_guess = ResolveDispatch_guess(argument_guess->value0_guess);
        if (result_guess != 0) {
            if (argument_guess->enabledC_guess == 0) {
                g_target4521Result_guess = 0;
                return;
            }
            g_target4521Receiver_guess->OpenForMerchant_guess(result_guess, argument_guess->value8_guess);
        }
    }
}

// FUNCTION: TITANIUM 0x00453E9B
// Merchant_Click_Struct reply: opens the merchant window at the given rate, or closes it when refused.
void __cdecl Handle_OP_ShopRequest_guess(Argument453E9B_guess* argument_guess) {
    if (g_target4521Busy_guess == 0) {
        DispatchTarget_guess* result_guess = ResolveDispatch_guess(argument_guess->value0_guess);
        if (result_guess != 0) {
            if (argument_guess->enabled8_guess == 0) {
                Target4521Dispatch_guess* receiver_guess = g_target4521Dispatch_guess;
                g_target4521Result_guess = 0;
                if (receiver_guess != 0) {
                    return receiver_guess->Slot88_guess();
                }
            } else {
                g_target4521Receiver_guess->OpenForMerchant_guess(result_guess, argument_guess->valueC_guess);
            }
        }
    }
}

// FUNCTION: TITANIUM 0x00453EEA
// Repacks TraderBuy_Struct into the merchant window's 0x18-byte purchase record.
void __cdecl Handle_OP_TraderBuy_guess(Argument453EEA_guess* argument_guess) {
    SixWords_guess message_guess;
    memset(&message_guess, 0, 0x18);
    message_guess.word0_guess = argument_guess->value8_guess;
    message_guess.word10_guess = argument_guess->value58_guess;
    message_guess.word14_guess = argument_guess->value4_guess;
    message_guess.word8_guess = argument_guess->value50_guess;
    message_guess.wordC_guess = argument_guess->value54_guess;
    g_target4521Receiver_guess->Handle_guess(&message_guess);
    g_target4521State_guess->valueC28C_guess = 1;
    g_target4521State_guess->valueC348_guess = 0;
}

// OP_ShopPlayerBuy: the merchant window reports the purchase (0x00537E10), then the character's +0xC28C
// is set and +0xC348 cleared.
// FUNCTION: TITANIUM 0x00453F4A
void __cdecl Handle_OP_ShopPlayerBuy_guess(void* value_guess) {
    g_target4521Receiver_guess->Handle_guess(value_guess);
    g_target4521State_guess->valueC28C_guess = 1;
    g_target4521State_guess->valueC348_guess = 0;
}

struct Argument453F72_guess {
    int padding0_guess;
    int operation_guess;
};

struct Payload453F72_guess {
    char currentName_guess[0x40];
    char resolvedName_guess[0x40];
    int time_guess;
    int mode_guess;
    unsigned char padding88_guess[8];
    int size_guess;
    char formatted_guess[0x800];
};

// FUNCTION: TITANIUM 0x00453F72
// If the player can't trade now, auto-replies "I'm busy right now." as a tell (0x1004, channel 7), then
// cancels (0x2DC1); otherwise opens the trade window.
void __cdecl Handle_OP_TradeRequestAck_guess(Argument453F72_guess* argument_guess) {
    int values_guess[2];
    char message_guess[512];
    Payload453F72_guess payload_guess;
    DispatchTarget_guess* target_guess =
        ResolveDispatch_guess(argument_guess->operation_guess);

    if (target_guess != 0) {
        if (g_target4520E5Data_guess->IsOkToTransact_guess() == 0) {
            memset(&payload_guess, 0, sizeof(payload_guess));
            strcpy(payload_guess.resolvedName_guess,
                   g_propertyOwnerCurrent_guess->name_0120_guess);
            strcpy(payload_guess.currentName_guess, target_guess->name_0120_guess);
            FormatNotice_guess(payload_guess.formatted_guess, 0x5A6,
                               g_propertyOwnerCurrent_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            payload_guess.mode_guess = 7;
            payload_guess.time_guess = g_target4520E5Data_guess->GetCurrentLanguage_guess();
            payload_guess.size_guess = 100;
            unsigned length_guess = strlen(payload_guess.formatted_guess);
            EQSendMessage(g_messageBuffer_guess, OP_ChannelMessage, &payload_guess,
                              length_guess + 0x99, 1);
            values_guess[0] = target_guess->spawnId_0258_guess;
            values_guess[1] = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
            EQSendMessage(g_messageBuffer_guess, OP_CancelTrade, values_guess, 8, 1);
            FormatNotice_guess(message_guess, 0x5A7, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            g_target4520E5Data_guess->dsp_chat(message_guess, 0x111, 1);
        } else {
            g_globalController_guess->Activate_guess(target_guess, 1);
        }
    }
}

// FUNCTION: TITANIUM 0x00454123
// "%1 has cancelled the trade." / "The trade has been cancelled." / "You have cancelled the trade."
void __cdecl Handle_OP_CancelTrade_guess(int* value_guess) {
    char message_guess[512];

    if (g_globalController_guess->active_guess == 0) {
        return;
    }
    if (*value_guess != g_propertyOwnerCurrent_guess->spawnId_0258_guess) {
        DispatchTarget_guess* target_guess = ResolveDispatch_guess(*value_guess);
        if (target_guess != 0) {
            FormatNotice_guess(message_guess, 0x5A8, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0x111, 1);
        } else {
            pEverQuest->dsp_chat(
                g_catalog453912_guess->getString(0x5A9, 0), 0x111, 1);
        }
    } else {
        pEverQuest->dsp_chat(
            g_catalog453912_guess->getString(0x5AA, 0), 0x111, 1);
    }
    g_globalController_guess->Deactivate_guess();
}

struct Argument4541E0_guess {
    unsigned char padding0_guess[4];
    int operation_guess;
};

struct Message4541E0_guess {
    int operation_guess;
    int spawnId_0004_guess;
    char mode_guess;
};

// FUNCTION: TITANIUM 0x004541E0
// Trade invitation. The trade filter (0x0092495C) may answer OP_TradeBusy: 'b' nobody, 'c' group only
// (the five group slots at 0x00904390), 1 busy; otherwise the trade window opens.
void __cdecl Handle_OP_TradeRequest_guess(Argument4541E0_guess* argument_guess) {
    char message_guess[512];
    Message4541E0_guess packet_guess;
    DispatchTarget_guess* target_guess =
        ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess == 0) {
        return;
    }

    packet_guess.mode_guess = 0;
    if (EQ_GLOBAL(int, 0x0092495C) == 0) {
        packet_guess.mode_guess = 'b';
    } else if (EQ_GLOBAL(int, 0x0092495C) == 1) {
        packet_guess.mode_guess = 'c';
        if (EQ_GLOBAL(unsigned char, 0x009043A4) != 0) {
            DispatchTarget_guess** current_guess =
                EQ_ARRAY(DispatchTarget_guess*, 0x00904390);
            DispatchTarget_guess** end_guess =
                EQ_ARRAY(DispatchTarget_guess*, 0x009043A4);
            do {
                if (target_guess == *current_guess) {
                    packet_guess.mode_guess = 0;
                }
                ++current_guess;
            } while ((int)current_guess < (int)end_guess);
        }
    }

    if (packet_guess.mode_guess == 0 &&
        (g_target4520E5Data_guess->IsOkToTransact_guess() == 0 ||
         EQ_GLOBAL(unsigned char, 0x009858C7) != 0)) {
        packet_guess.mode_guess = 1;
    }

    if (packet_guess.mode_guess != 0) {
        packet_guess.operation_guess = argument_guess->operation_guess;
        packet_guess.spawnId_0004_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
        EQSendMessage(g_messageBuffer_guess, OP_TradeBusy, &packet_guess, 0xc, 1);
        FormatNotice_guess(message_guess, 0x5a7, target_guess->name_0120_guess,
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_target4520E5Data_guess->dsp_chat(message_guess, 0x111, 1);
    } else {
        g_globalController_guess->Activate_guess(target_guess, 0);
    }
}

struct Argument4542FB_guess {
    int value0_guess;
    int operation_guess;
    char mode_guess;
};

// FUNCTION: TITANIUM 0x004542FB
// The other side refused: 'b' not trading at all, 'c' group only, else busy (strings 0x5A4-0x5A6).
void __cdecl Handle_OP_TradeBusy_guess(Argument4542FB_guess* argument_guess) {
    char message_guess[512];
    DispatchTarget_guess* target_guess =
        ResolveDispatch_guess(argument_guess->operation_guess);
    if (target_guess != 0) {
        if (argument_guess->mode_guess == 'b') {
            FormatNotice_guess(message_guess, 0x5a4, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
        } else if (argument_guess->mode_guess == 'c') {
            FormatNotice_guess(message_guess, 0x5a5, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            FormatNotice_guess(message_guess, 0x5a6, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(message_guess, 0x111, 1);
    }
}

struct Argument4540EF_guess {
    unsigned char padding_guess[4];
    unsigned char index_guess;
    unsigned char padding5_guess[3];
    int value_guess;
};

#define g_updateAvailable_guess EQ_GLOBAL(int, 0x00905CE0)

// FUNCTION: TITANIUM 0x004540EF
// Adds coins to the other side of the trade; the coin type indexes the array from the end (3 - type).
void __cdecl Handle_OP_TradeCoins_guess(Argument4540EF_guess* argument_guess) {
    if (argument_guess != 0 && g_updateAvailable_guess != 0) {
        int index_guess = 3 - argument_guess->index_guess;
        g_globalController_guess->SetHisMoney_guess(
            index_guess,
            g_globalController_guess->values1d4_guess[index_guess] +
                argument_guess->value_guess);
    }
}

// OP_TradeAcceptClick: sets or clears the trade partner's accept flag in the trade window.
// FUNCTION: TITANIUM 0x00454380
void __cdecl Handle_OP_TradeAcceptClick_guess(ToggleArgument_guess* argument_guess) {
    if (argument_guess->enabled_guess != 0) {
        g_globalController_guess->SetHisReadyTrade_guess(1);
    } else {
        g_globalController_guess->SetHisReadyTrade_guess(0);
    }
}

// OP_FinishTrade: refreshes the trade window when it is open.
// FUNCTION: TITANIUM 0x0045439C
void __cdecl Handle_OP_FinishTrade_guess() {
    if (g_globalController_guess->active_guess != 0) {
        g_globalController_guess->Refresh_guess();
    }
}

struct ForwardTargetB1_guess {
    // EXTERNAL: TITANIUM 0x005163A9 ForwardTargetB1_guess::Run_guess
    void Run_guess(unsigned value_guess);
};

#define pinstCInspectWnd_guess EQ_GLOBAL(ForwardTargetB1_guess*, 0x00850C68)

// OP_InspectAnswer: fills the inspect window from the answer (0x005163A9).
// FUNCTION: TITANIUM 0x004543B1
void __cdecl Handle_OP_InspectAnswer_guess(unsigned value_guess) {
    pinstCInspectWnd_guess->Run_guess(value_guess);
}

struct ForwardArgument_guess {
    unsigned char padding_guess[8];
    unsigned value8_guess;
    unsigned valueC_guess;
};

struct ForwardTargetC1_guess {
    // EXTERNAL: TITANIUM 0x00537777 ForwardTargetC1_guess::Run_guess
    void Run_guess(unsigned first_guess, unsigned second_guess);
};

#define g_forwardTargetC1_guess EQ_GLOBAL(ForwardTargetC1_guess*, 0x00850C4C)

// Message 0xDA9: removes the merchant item with that id from the merchant window (0x00537777).
// FUNCTION: TITANIUM 0x004543C1
void __cdecl Handle_OP_ShopDelItem_guess(ForwardArgument_guess* value_guess) {
    g_forwardTargetC1_guess->Run_guess(value_guess->value8_guess, value_guess->valueC_guess);
}

struct SecondForwardArgument_guess {
    unsigned value0_guess;
    unsigned value4_guess;
};

struct ForwardTargetD7_guess {
    // EXTERNAL: TITANIUM 0x005219F6 ForwardTargetD7_guess::Run_guess
    void Run_guess(int result_guess, unsigned value_guess);
};

#define g_forwardTargetD7_guess EQ_GLOBAL(ForwardTargetD7_guess*, 0x00991B88)

// EXTERNAL: TITANIUM 0x004B232E MakeForwardValue_guess
int __cdecl MakeForwardValue_guess(const unsigned* value_guess);

// OP_ItemLinkResponse: builds the linked item from its text record and opens an item display for it.
// FUNCTION: TITANIUM 0x004543D7
void __cdecl Handle_OP_ItemLinkResponse_guess(SecondForwardArgument_guess* value_guess) {
    int result_guess = MakeForwardValue_guess(&value_guess->value4_guess);
    if (result_guess != 0) {
        g_forwardTargetD7_guess->Run_guess(result_guess, value_guess->value0_guess);
    }
}

struct PackedDispatcher_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void HandleS2CRaidMessage_guess(int value_guess) = 0;
};

#define g_packedDispatcher_guess EQ_GLOBAL(PackedDispatcher_guess*, 0x0099E36C)

// FUNCTION: TITANIUM 0x004543FA
// Opcode 0x1D43: packs two words as (first << 16) | second for the dispatcher at 0x0099E36C.
void __cdecl DispatchPackedIdPacket_guess(int* value_guess) {
    g_packedDispatcher_guess->HandleS2CRaidMessage_guess((value_guess[0] << 16) | value_guess[1]);
}

// FUNCTION: TITANIUM 0x00454415
// {spawn id, spell id} pairs: plays each spell's effect at the spawn (opcodes 0x1A87, 0x525D). 0x00985CC8
// is probably the spell manager.
void __cdecl EmitSpellEffectsOnSpawns_guess(int* values_guess, int count_guess) {
    if (count_guess > 0) {
        int* current_guess = values_guess + 1;
        int remaining_guess = count_guess;
        do {
            DispatchPayload454415_guess* source_guess =
                (DispatchPayload454415_guess*)ResolveDispatch_guess(current_guess[-1]);
            int value_guess = *current_guess;
            LookupValue454415_guess* lookupValue_guess =
                g_lookup454415_guess->Find_guess(value_guess);
            if (source_guess != 0 && lookupValue_guess != 0) {
                int payload_guess[3];
                payload_guess[0] = source_guess->value30_guess;
                payload_guess[1] = source_guess->value34_guess;
                payload_guess[2] = source_guess->value38_guess;
                SubmitEffectEmitters_guess(value_guess, 3,
                                         lookupValue_guess->value234_guess,
                                         source_guess, source_guess,
                                         payload_guess, 0, 0, 1);
            }
            current_guess += 2;
        } while (--remaining_guess != 0);
    }
}

// FUNCTION: TITANIUM 0x0045448B
// Plays effect `index` from the table at 0x00851398 on the spawn (opcodes 0xA8, 0x395E).
void __cdecl EmitTableEffectOnSpawn_guess(int value_guess, int index_guess) {
    if (index_guess > 0 && index_guess < g_recordCount45448B_guess) {
        DispatchPayload454415_guess* source_guess =
            (DispatchPayload454415_guess*)ResolveDispatch_guess(value_guess);
        Record45448B_guess* record_guess = g_recordBase45448B_guess + index_guess;
        if (source_guess != 0 && record_guess != 0) {
            int payload_guess[3];
            payload_guess[0] = source_guess->value30_guess;
            payload_guess[1] = source_guess->value34_guess;
            payload_guess[2] = source_guess->value38_guess;
            SubmitEffectEmitters_guess(index_guess, 2, record_guess,
                                     source_guess, source_guess,
                                     payload_guess, 0, 0, 0);
        }
    }
}

// FUNCTION: TITANIUM 0x004544ED
// Opcode 0x60A0; same packing as DispatchPackedIdPacket_guess.
void __cdecl DispatchPackedIdPair_guess(int high_guess, unsigned low_guess) {
    g_packedDispatcher_guess->HandleS2CRaidMessage_guess((high_guess << 16) | low_guess);
}

struct Record454505_guess {
    char first_guess[0x40];
    char second_guess[0x40];
    int values_guess[5];
};

struct RecordHandler454505_guess {
    // EXTERNAL: TITANIUM 0x00509618 RecordHandler454505_guess::Prepare_guess
    void Prepare_guess();

    // EXTERNAL: TITANIUM 0x0050ADB2 RecordHandler454505_guess::Process_guess
    void Process_guess(Record454505_guess* record_guess);
};

#define g_recordHandler454505_guess EQ_GLOBAL(RecordHandler454505_guess*, 0x00991A58)

// FUNCTION: TITANIUM 0x00454505
// After a 4-byte header, records of {name, guild, then five shorts} until the end of the packet.
void __cdecl Handle_OP_LFGGetMatchesResponse_guess(const char* data_guess, int size_guess) {
    if (g_recordHandler454505_guess != 0) {
        Record454505_guess record_guess;
        g_recordHandler454505_guess->Prepare_guess();

        const char* end_guess = data_guess + size_guess;
        const char* current_guess = data_guess + 4;
        while (current_guess < end_guess) {
            memset(&record_guess, 0, 0x94);
            strcpy(record_guess.first_guess, current_guess);
            current_guess += strlen(current_guess) + 1;
            strcpy(record_guess.second_guess, current_guess);
            current_guess += strlen(current_guess) + 1;

            record_guess.values_guess[0] = *(const short*)current_guess;
            current_guess += 2;
            record_guess.values_guess[1] = *(const short*)current_guess;
            current_guess += 2;
            record_guess.values_guess[2] = *(const short*)current_guess;
            current_guess += 2;
            record_guess.values_guess[3] = *(const short*)current_guess;
            current_guess += 2;
            record_guess.values_guess[4] = *(const short*)current_guess;
            current_guess += 2;

            record_guess.first_guess[0x3f] = 0;
            record_guess.second_guess[0x3f] = 0;
            g_recordHandler454505_guess->Process_guess(&record_guess);
        }
    }
}

struct Payload4545C8_guess {
    char name_guess[64];
    int first_guess;
    int second_guess;
    int third_guess;
    int count_guess;
    union Entry_guess {
        char name_guess[64];
        int words_guess[21];
    } entries_guess[6];
};

struct RecordHandler4545C8_guess {
    // EXTERNAL: TITANIUM 0x0050957F RecordHandler4545C8_guess::Prepare_guess
    void Prepare_guess();

    // EXTERNAL: TITANIUM 0x0050B634 RecordHandler4545C8_guess::Process_guess
    void Process_guess(Payload4545C8_guess* payload_guess);
};

#define g_recordHandler4545C8_guess EQ_GLOBAL(RecordHandler4545C8_guess*, 0x00991A58)

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination_guess, const char* source_guess);

// FUNCTION: TITANIUM 0x004545C8
// After a 4-byte header, per group: leader name, two shorts, an int, a member count, then per member a
// name and four shorts.
void __cdecl Handle_OP_LFPGetMatchesResponse_guess(const char* data_guess, int size_guess) {
    if (g_recordHandler4545C8_guess != 0) {
        g_recordHandler4545C8_guess->Prepare_guess();

        const char* current_guess = data_guess;
        const char* end_guess = current_guess + size_guess;
        current_guess += 4;
        while (current_guess < end_guess) {
            Payload4545C8_guess payload_guess;
            memset(&payload_guess, 0, sizeof(payload_guess));
            FUN_0060e450_guess(payload_guess.name_guess, current_guess);
            current_guess += strlen(current_guess) + 1;

            int count_guess = 0;
            payload_guess.first_guess = *(const short*)current_guess;
            current_guess += 2;
            payload_guess.second_guess = *(const short*)current_guess;
            current_guess += 2;
            payload_guess.third_guess = *(const int*)current_guess;
            current_guess += 4;
            payload_guess.count_guess = *(const short*)current_guess;
            current_guess += 2;
            payload_guess.name_guess[63] = 0;

            Payload4545C8_guess::Entry_guess* entry_guess = payload_guess.entries_guess;
            int* values_guess = entry_guess->words_guess + 14;
            while (count_guess < payload_guess.count_guess) {
                int value_guess;
                FUN_0060e450_guess(entry_guess->name_guess, current_guess);
                current_guess += strlen(current_guess) + 1;
                value_guess = *(const short*)current_guess;
                current_guess += 2;
                values_guess[2] = value_guess;
                value_guess = *(const short*)current_guess;
                current_guess += 2;
                values_guess[3] = value_guess;
                value_guess = *(const short*)current_guess;
                current_guess += 2;
                values_guess[4] = value_guess;
                value_guess = *(const short*)current_guess;
                current_guess += 2;
                ++count_guess;
                values_guess[5] = value_guess;
                entry_guess->name_guess[63] = 0;
                ++entry_guess;
                values_guess += 0x15;
            }

            g_recordHandler4545C8_guess->Process_guess(&payload_guess);
        }
    }
}

struct Argument4546E2_guess {
    unsigned char padding00_guess[0x40];
    char name40_guess[0x20];
    char name60_guess[0x20];
    unsigned char padding80_guess[0x20];
    int valueA0_guess;
    int valueA4_guess;
    unsigned char paddingA8_guess[0x44];
};

struct NoticeSource4546E2_guess {
    // EXTERNAL: TITANIUM 0x00491E5B NoticeSource4546E2_guess::GetClassDesc
    const char* GetClassDesc(int value_guess);

    // EXTERNAL: TITANIUM 0x0049273D NoticeSource4546E2_guess::GetRaceDesc
    const char* GetRaceDesc(int value_guess);
};

#define g_noticeSource4546E2_guess EQ_GLOBAL(NoticeSource4546E2_guess*, 0x00988DF0)

// FUNCTION: TITANIUM 0x004546E2
// Opcode 0x46B1 (GM): "Player handle %1 has requested name approval on name %2." plus race and class,
// in a 25 s approve/deny box (type 0x6A) that keeps a 0xEC-byte copy of the request.
void __cdecl Handle_NameApprovalRequest_guess(Argument4546E2_guess* argument_guess) {
    char message_guess[1024];
    char second_guess[512];
    char first_guess[512];

    FormatNotice_guess(first_guess, 0x877, argument_guess->name40_guess,
                       argument_guess->name60_guess, 0, 0, 0, 0, 0, 0, 0);
    FormatNotice_guess(second_guess, 0x878,
                       g_noticeSource4546E2_guess->GetRaceDesc(argument_guess->valueA0_guess),
                       g_noticeSource4546E2_guess->GetClassDesc(argument_guess->valueA4_guess),
                       0, 0, 0, 0, 0, 0, 0);
    sprintf(message_guess, "%s<BR>%s", first_guess, second_guess);

    void* copy_guess = operator new(0xec);
    memcpy(copy_guess, argument_guess, 0xec);
    g_noticeSender_guess->Activate(
        g_noticeValue_guess != 0 ? g_noticeValue_guess + 8 : 0, 0x6a,
        message_guess, 0xc, 25000, copy_guess, 1);
}

// FUNCTION: TITANIUM 0x004547D0
// Opcode 0x9C (GM): the name-change version (string 0x1756, box type 0x7C).
void __cdecl Handle_NameChangeApprovalRequest_guess(Argument4546E2_guess* argument_guess) {
    char message_guess[1024];
    char second_guess[512];
    char first_guess[512];

    FormatNotice_guess(first_guess, 0x1756, argument_guess->name40_guess,
                       (const char*)argument_guess, argument_guess->name60_guess,
                       0, 0, 0, 0, 0, 0);
    FormatNotice_guess(second_guess, 0x878,
                       g_noticeSource4546E2_guess->GetRaceDesc(argument_guess->valueA0_guess),
                       g_noticeSource4546E2_guess->GetClassDesc(argument_guess->valueA4_guess),
                       0, 0, 0, 0, 0, 0, 0);
    sprintf(message_guess, "%s<BR>%s", first_guess, second_guess);

    void* copy_guess = operator new(0xec);
    memcpy(copy_guess, argument_guess, 0xec);
    g_noticeSender_guess->Activate(
        g_noticeValue_guess != 0 ? g_noticeValue_guess + 8 : 0, 0x7c,
        message_guess, 0xc, 25000, copy_guess, 1);
}

struct ErrorCode548BE_guess {
    unsigned char padding_guess[0x80];
    int code_guess;
};

// FUNCTION: TITANIUM 0x004548BE
// Opcode 0x3274: 1 success, 0 denied, -1 timed out, -2 server error, -3 too soon, -4 not eligible.
void __cdecl Handle_NameChangeResult_guess(ErrorCode548BE_guess* argument_guess) {
    int code_guess = argument_guess->code_guess;
    if (code_guess == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x142f, 0), 0xf, 1);
    } else if (code_guess == 1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1758, 0), 0xf, 1);
    } else if (code_guess == -1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1759, 0), 0xf, 1);
    } else if (code_guess == -2) {
        pEverQuest->dsp_chat(pStringTable->getString(0x175a, 0), 0xf, 1);
    } else if (code_guess == -3) {
        pEverQuest->dsp_chat(pStringTable->getString(0x175b, 0), 0xf, 1);
    } else if (code_guess == -4) {
        pEverQuest->dsp_chat(pStringTable->getString(0x175c, 0), 0xf, 1);
    }
}

// EXTERNAL: TITANIUM 0x0040C0F2 ParseField54942_guess
void __cdecl ParseField54942_guess(char* output_guess, int capacity_guess,
                                   const int* value_guess, int separator_guess);

struct ErrorDisplay54942_guess {
    // EXTERNAL: TITANIUM 0x00495720 ErrorDisplay54942_guess::Show_guess
    void Show_guess(char* first_guess, long number_guess,
                    char* second_guess, char* third_guess);
};

#define g_errorDisplay54942_guess EQ_GLOBAL(ErrorDisplay54942_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0060E3A3 atol
extern "C" long __cdecl atol(const char* text_guess);


// FUNCTION: TITANIUM 0x00454942
// @early-stop: budget, structural ndiff=23
// Payload is text "host,port,world.character,key"; pEverQuest connects to the chat server with it.
void __cdecl Handle_OP_SetChatServer_guess(int value_guess) {
    char third_guess[256];
    char fourth_guess[256];
    char first_guess[256];
    char second_guess[256];
    int copy_guess;
    first_guess[0] = 0;
    third_guess[0] = 0;
    fourth_guess[0] = 0;
    second_guess[0] = 0;
    copy_guess = value_guess;
    ParseField54942_guess(first_guess, 0x100, &copy_guess, 0x2c);
    ParseField54942_guess(second_guess, 0x100, &copy_guess, 0x2c);
    ParseField54942_guess(third_guess, 0x100, &copy_guess, 0x2c);
    ParseField54942_guess(fourth_guess, 0x100, &copy_guess, 0x2c);
    g_errorDisplay54942_guess->Show_guess(first_guess, atol(second_guess),
                                          third_guess, fourth_guess);
}

// EXTERNAL: TITANIUM 0x005FF7B0 ParseField454A0C_guess
void __cdecl ParseField454A0C_guess(char* output_guess, int capacity_guess,
                                    const int* value_guess, int separator_guess);

struct ErrorDisplay454A0C_guess {
    // EXTERNAL: TITANIUM 0x00495972 ErrorDisplay454A0C_guess::Show_guess
    void Show_guess(char* first_guess, long number_guess,
                    char* second_guess, char* third_guess);
};

#define g_errorDisplay454A0C_guess EQ_GLOBAL(ErrorDisplay454A0C_guess*, 0x00988DF0)

struct ParseScratch454A0C_guess {
    int value_guess;
    char second_guess[256];
    char first_guess[256];
    char fourth_guess[256];
    char third_guess[256];
};

struct Text454AD6_guess {
    int category_guess;
    char text_guess[1];
};

struct Scan454AD6_guess {
    unsigned position_guess;
    char buffer_guess[0x800];
};

// FUNCTION: TITANIUM 0x00454A0C
// @early-stop: budget, structural ndiff=22
// Same format as OP_SetChatServer, for the mail server.
void __cdecl Handle_OP_SetChatServer2_guess(int value_guess) {
    ParseScratch454A0C_guess scratch_guess;
    scratch_guess.first_guess[0] = 0;
    scratch_guess.third_guess[0] = 0;
    scratch_guess.fourth_guess[0] = 0;
    scratch_guess.second_guess[0] = 0;
    scratch_guess.value_guess = value_guess;
    ParseField454A0C_guess(scratch_guess.first_guess, 0x100, &scratch_guess.value_guess, 0x2c);
    ParseField454A0C_guess(scratch_guess.second_guess, 0x100, &scratch_guess.value_guess, 0x2c);
    ParseField454A0C_guess(scratch_guess.third_guess, 0x100, &scratch_guess.value_guess, 0x2c);
    ParseField454A0C_guess(scratch_guess.fourth_guess, 0x100, &scratch_guess.value_guess, 0x2c);
    g_errorDisplay454A0C_guess->Show_guess(scratch_guess.first_guess,
                                           atol(scratch_guess.second_guess),
                                           scratch_guess.third_guess,
                                           scratch_guess.fourth_guess);
}

// FUNCTION: TITANIUM 0x00454AD6
// ColoredText_Struct {color, text}: prints the text a line at a time in that chat color.
void __cdecl Handle_OP_ColoredText_guess(Text454AD6_guess* text_guess) {
    Scan454AD6_guess scan_guess;
    int done_guess = 0;
    scan_guess.position_guess = 0;
    char* text_pointer_guess = text_guess->text_guess;
    do {
        if (ReadNextTextLine_guess(text_pointer_guess,
                               (unsigned char*)scan_guess.buffer_guess,
                               &scan_guess.position_guess, 0x800) != 0) {
            pEverQuest->dsp_chat(scan_guess.buffer_guess,
                                                text_guess->category_guess, 1);
        } else {
            if (strlen(scan_guess.buffer_guess) != 0) {
                pEverQuest->dsp_chat(scan_guess.buffer_guess,
                                                    text_guess->category_guess, 1);
            }
            done_guess = 1;
        }
    } while (done_guess == 0);
}

// FUNCTION: TITANIUM 0x00454B65
// Strings 0x1D5-0x1D8 are the "faction standing got better/worse" lines; they fire window event 0x1E.
void __cdecl NotifyFactionStringEvent_guess(int value_guess, int unused_guess) {
    if (value_guess >= 0x1d5 && value_guess <= 0x1d8 && g_target454B65_guess != 0) {
        g_target454B65_guess->Run_guess(0x1e, 0);
    }
}

struct Record454B8D_guess {
    int value0_guess;               // -0x80
    int id_guess;                   // -0x7C
    int args_guess[9];              // -0x78
};

// FUNCTION: TITANIUM 0x00454B8D
// Opcode 0x60F4: an emote given as a string id with arguments, shown like Handle_OP_Emote_guess.
void __cdecl Handle_FormattedEmote_guess(int first_guess, int second_guess) {
    Record454B8D_guess record_guess;
    int position_guess = 0;
    char text_guess[1024];
    char line_guess[1024];
    int done_guess = 0;

    SplitStringIdPacket_guess(first_guess, second_guess, &record_guess);
    FormatText453962_guess(line_guess,
                           pStringTable->getString(record_guess.id_guess, 0),
                           (char**)record_guess.args_guess, -1, 0);
    if (g_target4520E5Data_guess->BeingIgnored_guess(line_guess) == 0) {
        if (g_textMode454CCD_guess == 0) {
            SpeakBabel_guess(line_guess, text_guess, 0, 100, g_randomSource454CCD_guess.Next_guess(6));
        } else {
            FUN_0060e450_guess(text_guess, line_guess);
        }
        StripSpawnNameDigits_guess(line_guess);
        do {
            if (ReadNextTextLine_guess(text_guess, (unsigned char*)line_guess,
                                   (unsigned*)&position_guess, 0x800) != 0) {
                g_target4520E5Data_guess->dsp_chat(line_guess, 0x107, 1);
            } else {
                if (strlen(line_guess) != 0) {
                    g_target4520E5Data_guess->dsp_chat(line_guess, 0x107, 1);
                }
                done_guess = 1;
            }
        } while (done_guess == 0);
    }
}

// FUNCTION: TITANIUM 0x00454CCD
// Skips the 4-byte header, drops emotes whose name fails CheckName_guess (probably the ignore list) and
// prints the rest in color 0x107. With 0x00923D74 clear the text first goes through FUN_00478951, the
// language garbler Handle_OP_ChannelMessage_guess also uses.
void __cdecl Handle_OP_Emote_guess(const char* value_guess) {
    int position_guess = 0;
    char text_guess[1024];
    char line_guess[1024];
    const char* input_guess = value_guess + 4;
    int done_guess = 0;

    g_target4520E5Data_guess->CopyFirstWord_guess(input_guess, line_guess);
    if (g_target4520E5Data_guess->BeingIgnored_guess(line_guess) == 0) {
        if (g_textMode454CCD_guess == 0) {
            int random_guess = g_randomSource454CCD_guess.Next_guess(6);
            SpeakBabel_guess(input_guess, text_guess, 0, 100, random_guess);
        } else {
            FUN_0060e450_guess(text_guess, input_guess);
        }
        StripSpawnNameDigits_guess(line_guess);

        do {
            if (ReadNextTextLine_guess(text_guess, (unsigned char*)line_guess,
                                   (unsigned*)&position_guess, 0x800) != 0) {
                g_target4520E5Data_guess->dsp_chat(line_guess, 0x107, 1);
            } else {
                if (strlen(line_guess) != 0) {
                    g_target4520E5Data_guess->dsp_chat(line_guess, 0x107, 1);
                }
                done_guess = 1;
            }
        } while (done_guess == 0);
    }
}

// FUNCTION: TITANIUM 0x00454DD7
// Opcode 0x161C: passes the value to the window at 0x00991D64 and refreshes it.
void __cdecl UpdateMIZoneSelectWnd_guess(int value_guess) {
    if (pinstCMIZoneSelectWnd_guess != 0) {
        pinstCMIZoneSelectWnd_guess->Update_guess(value_guess);
        pinstCMIZoneSelectWnd_guess->SlotC0_guess(1, 1);
    }
}

// FUNCTION: TITANIUM 0x00454DFD
// Opcode 0x5B16: 0 approved (0xE13), 1 error (0xE14), 2 all rewards claimed elsewhere (0xE2D), 3 this
// character already claimed (0xE2C).
void __cdecl Handle_VeteranRewardResult_guess(int state_guess) {
    int category_guess = 0xD;
    char found_guess = 0;
    char* message_guess;
    switch (state_guess) {
    case 0:
        message_guess = g_catalog453912_guess->getString(0xE13, (int)&found_guess);
        category_guess = 0xF;
        break;
    case 1:
        message_guess = g_catalog453912_guess->getString(0xE14, (int)&found_guess);
        break;
    case 3:
        message_guess = g_catalog453912_guess->getString(0xE2C, (int)&found_guess);
        break;
    case 2:
        message_guess = g_catalog453912_guess->getString(0xE2D, (int)&found_guess);
        break;
    default:
        return;
    }
    if (found_guess != 0) {
        pEverQuest->dsp_chat(message_guess, category_guess, 1);
    }
}

// FUNCTION: TITANIUM 0x00454E75
// A positive value prints "Items cannot be /claim'ed at this time" (0xD17), else "Your claim has been
// approved" (0xD1A).
void __cdecl Handle_OP_VetClaimReply_guess(int value_guess) {
    if (value_guess > 0) {
        pEverQuest->dsp_chat(g_catalog453912_guess->getString(0xD17, 0), 0xD, 1);
    } else {
        pEverQuest->dsp_chat(g_catalog453912_guess->getString(0xD1A, 0), 0xF, 1);
    }
}

// EXTERNAL: TITANIUM 0x0040D830 ValidateSource_guess
void __cdecl ValidateSource_guess(const char* source_guess);

struct Target454EA9_guess {
    char buffer_guess[0x20];

    char Copy_guess(const char* source_guess);
};

// FUNCTION: TITANIUM 0x00454EA9
// Bounded copy into a 32-byte buffer; returns 0 when it had to truncate.
char Target454EA9_guess::Copy_guess(const char* source_guess) {
    ValidateSource_guess(source_guess);

    unsigned index_guess = 0;
    char* destination_guess = buffer_guess;
    do {
        char value_guess = source_guess[index_guess];
        *destination_guess = value_guess;
        if (value_guess == 0) {
            return 1;
        }
        ++index_guess;
        ++destination_guess;
    } while (index_guess < 0x20);

    buffer_guess[0x1f] = 0;
    return 0;
}

struct HashPayload_guess {
    unsigned words_guess[22];
};

struct HashNode_guess {
    HashPayload_guess payload_guess;
    unsigned key_guess;
    HashNode_guess* next_guess;
};

struct HashTable_guess {
    HashNode_guess** buckets_guess;
    unsigned bucketCount_guess;
    unsigned entryCount_guess;
    unsigned nonemptyCount_guess;

    void Insert_guess(const HashPayload_guess* payload_guess, unsigned key_guess);
};

// FUNCTION: TITANIUM 0x00454EE0
// Chains a new node at the front of bucket key % bucketCount (opcode 0x5CC0, after Clear_guess).
void HashTable_guess::Insert_guess(const HashPayload_guess* payload_guess, unsigned key_guess) {
    HashNode_guess* node_guess = new HashNode_guess;
    node_guess->payload_guess = *payload_guess;
    node_guess->key_guess = key_guess;

    unsigned bucket_guess = key_guess % bucketCount_guess;
    HashNode_guess* old_guess = buckets_guess[bucket_guess];
    if (old_guess == 0) {
        node_guess->next_guess = 0;
        buckets_guess[bucket_guess] = node_guess;
        ++nonemptyCount_guess;
    } else {
        node_guess->next_guess = old_guess;
        buckets_guess[bucket_guess] = node_guess;
    }
    ++entryCount_guess;
}

struct ChainNode454F3F_guess {
    unsigned char padding_guess[0x5c];
    ChainNode454F3F_guess* next_guess;
};

struct ChainArray454F3F_guess {
    int* entries_guess;
    int count_guess;
    int activeCount_guess;
    int nodeCount_guess;

    void Clear_guess();
};

// FUNCTION: TITANIUM 0x00454F3F
// Frees every chained node and empties the buckets.
void ChainArray454F3F_guess::Clear_guess() {
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            ChainNode454F3F_guess* node_guess =
                (ChainNode454F3F_guess*)entries_guess[index_guess];
            if (node_guess != 0) {
                --nodeCount_guess;
                do {
                    ChainNode454F3F_guess* next_guess = node_guess->next_guess;
                    free(node_guess);
                    --activeCount_guess;
                    node_guess = next_guess;
                } while (node_guess != 0);
                entries_guess[index_guess] = 0;
            }
            ++index_guess;
        } while (index_guess < count_guess);
    }
}

struct StringReader454F79_guess {
    char* data_guess;
    unsigned capacity_guess;
    unsigned position_guess;

    bool ReadString_guess(char* destination_guess, unsigned size_guess);
};

// FUNCTION: TITANIUM 0x00454F79
// Reads one NUL-terminated string from the packet cursor; false (and "") if it would run past the end.
bool StringReader454F79_guess::ReadString_guess(char* destination_guess,
                                                unsigned size_guess) {
    unsigned length_guess = strlen(data_guess + position_guess) + 1;
    if (position_guess + length_guess <= capacity_guess) {
        strncpy(destination_guess, data_guess + position_guess, size_guess);
        destination_guess[size_guess - 1] = 0;
        position_guess += length_guess;
        return true;
    }
    destination_guess[0] = 0;
    return false;
}

struct Reader454FCD_guess {
    // EXTERNAL: TITANIUM 0x004250AA Reader454FCD_guess::Read_guess
    void Read_guess(void* destination_guess, unsigned size_guess);
};

struct FiveWords454FCD_guess {
    unsigned word0_guess;
    unsigned word4_guess;
    unsigned word8_guess;
    unsigned wordC_guess;
    unsigned word10_guess;

    void Read_guess(Reader454FCD_guess* reader_guess);
};

// FUNCTION: TITANIUM 0x00454FCD
// Five dwords from the packet cursor (opcodes 0x11D and 0x385E).
void FiveWords454FCD_guess::Read_guess(Reader454FCD_guess* reader_guess) {
    unsigned first_guess;
    reader_guess->Read_guess(&first_guess, 4);
    word0_guess = first_guess;
    reader_guess->Read_guess(&word4_guess, 4);
    reader_guess->Read_guess(&word8_guess, 4);
    reader_guess->Read_guess(&wordC_guess, 4);
    reader_guess->Read_guess(&word10_guess, 4);
}

// Spawn record the function reads: name at +7, level at +0x97, id at +0x154, heading at +0x158.
struct PlayerSource4554E5_guess {
    unsigned char padding000_guess[7];
    char name007_guess[0x40];
    unsigned char padding047_guess[0x97 - 0x47];
    unsigned char level_0097_guess;
    unsigned char padding098_guess[0x154 - 0x98];
    int spawnId_0154_guess;
    int boundingRadius_0158_guess;
};

struct Owner4554E5_guess {
    // EXTERNAL: TITANIUM 0x0047A387 Owner4554E5_guess::FUN_0047a387_guess
    char FUN_0047a387_guess();
};

struct ActorInfo4554E5_guess {
    void* value00_guess;
    unsigned char padding04_guess[0x160 - 0x04];
    Owner4554E5_guess* value160_guess;
    unsigned char padding164_guess[0xEBC - 0x164];
    int valueEbc_guess;
};

// EQPlayer, 0x348 (types.h); the ctor is in tu_053.
struct EQPlayer4554E5_guess {
    unsigned char padding000_guess[0x120];
    char name120_guess[0x40];
    unsigned char padding160_guess[0x1A0 - 0x160];
    int boundingRadius_01a0_guess;
    unsigned char padding1A4_guess[0x1A8 - 0x1A4];
    ActorInfo4554E5_guess* pActorInfo_guess;
    unsigned char padding1AC_guess[0x244 - 0x1AC];
    unsigned char type244_guess;
    unsigned char padding245_guess[0x24C - 0x245];
    unsigned char level24C_guess;
    unsigned char faceHair24D_guess;
    unsigned char padding24E_guess[0x251 - 0x24E];
    unsigned char standState251_guess;
    unsigned char class252_guess;
    unsigned char padding253_guess;
    unsigned char equipChest2_0254_guess;
    unsigned char padding255_guess[0x348 - 0x255];

    // EXTERNAL: TITANIUM 0x004850A0 EQPlayer4554E5_guess::EQPlayer4554E5_guess
    EQPlayer4554E5_guess(PlayerSource4554E5_guess* source_guess, unsigned char gender_guess,
                         int race_guess, unsigned char class_guess, const char* name_guess);

    // EXTERNAL: TITANIUM 0x0047C3EF EQPlayer4554E5_guess::SetName_guess
    void SetName_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x00482722 EQPlayer4554E5_guess::SwapNPCMaterials_guess
    void SwapNPCMaterials_guess();
    // EXTERNAL: TITANIUM 0x0047DEC4 EQPlayer4554E5_guess::SwapFace_guess
    void SwapFace_guess(int value_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0048A6F2 EQPlayer4554E5_guess::FUN_0048a6f2_guess
    void FUN_0048a6f2_guess();
    // EXTERNAL: TITANIUM 0x0048A945 EQPlayer4554E5_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
    // EXTERNAL: TITANIUM 0x0047CEE4 EQPlayer4554E5_guess::IsHorseUsingHumanModel_guess
    char IsHorseUsingHumanModel_guess();
    // EXTERNAL: TITANIUM 0x0047A3B3 EQPlayer4554E5_guess::FUN_0047a3b3_guess
    void FUN_0047a3b3_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047BFD0 EQPlayer4554E5_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x00480409 EQPlayer4554E5_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
};

// pCharData: the profile is a virtual base at +0xC384, reached through the vbptr at +8.
struct CharacterBase4554E5_guess {
    void* vftable_guess;
    unsigned char padding004_guess[0x3C - 0x04];
    char name03C_guess[0x40];
    unsigned char padding07C_guess[0x104 - 0x7C];
    unsigned char value104_guess;
    unsigned char padding105_guess[0x14C - 0x105];
};

struct CharacterPrefix4554E5_guess {
    void* vftable_guess;
    int field04_guess;
};

struct CharacterView4554E5_guess : CharacterPrefix4554E5_guess, virtual CharacterBase4554E5_guess {
    unsigned char padding0C_guess[0xC384 - 0x0C];
};

struct EverQuest4554E5_guess {
    unsigned char padding000_guess[0xB50];
    int valueB50_guess;
};

#define g_playerHead4554E5_guess EQ_GLOBAL(EQPlayer4554E5_guess*, 0x00905CC4)
#define g_currentPlayer4554E5_guess EQ_GLOBAL(EQPlayer4554E5_guess*, 0x00905CE4)
#define g_cachedPlayer4554E5_guess EQ_GLOBAL(EQPlayer4554E5_guess*, 0x00905CF8)
#define g_cachedIndex4554E5_guess EQ_GLOBAL(int, 0x00905CFC)
#define g_loaded4554E5_guess EQ_GLOBAL(int, 0x00905C00)
#define g_charView4554E5_guess EQ_GLOBAL(CharacterView4554E5_guess*, 0x00905D00)
#define g_everQuest4554E5_guess EQ_GLOBAL(EverQuest4554E5_guess*, 0x00988DF0)

// FUNCTION: TITANIUM 0x004554E5
// One Spawn_Struct (0x181 bytes). A known spawn id only refreshes name, level and +0x1A0; otherwise the
// new EQPlayer is linked to its group slot (names at 0x0090424D, 5 x 0x40) and its pet, and the spawn
// named like pCharData becomes the local player (0x00905CE4), standing (100) and in view.
void __cdecl Handle_OP_NewSpawn_guess(PlayerSource4554E5_guess* source_guess) {
    if (source_guess != 0) {
        EQPlayer4554E5_guess* found_guess = 0;
        if (g_playerHead4554E5_guess != 0 &&
            (found_guess = (EQPlayer4554E5_guess*)ResolveDispatch_guess(source_guess->spawnId_0154_guess)) != 0) {
            found_guess->SetName_guess(source_guess->name007_guess);
            found_guess->level24C_guess = source_guess->level_0097_guess;
            found_guess->boundingRadius_01a0_guess = source_guess->boundingRadius_0158_guess;
        } else {
            EQPlayer4554E5_guess* player_guess =
                new EQPlayer4554E5_guess(source_guess, 0, 0, 0, 0);
            if (player_guess == 0) {
                g_everQuest4554E5_guess->valueB50_guess = 1;
            } else {
                if (player_guess->class252_guess == 0x1a) {
                    player_guess->equipChest2_0254_guess = 4;
                    player_guess->SwapNPCMaterials_guess();
                    if (player_guess->faceHair24D_guess > 0) {
                        player_guess->SwapFace_guess(player_guess->faceHair24D_guess, 0);
                    }
                }
                if (12000u < (unsigned int)(g_updateSettings_guess->frameTime_0148_guess -
                                            player_guess->pActorInfo_guess->valueEbc_guess)) {
                    player_guess->FUN_0048a6f2_guess();
                }
                player_guess->pActorInfo_guess->valueEbc_guess = g_updateSettings_guess->frameTime_0148_guess;
                player_guess->FUN_0048a945_guess();
                if (player_guess->type244_guess == 0 && EQ_GLOBAL(unsigned char, 0x009043A4) != 0) {
                    EQPlayer4554E5_guess** slot_guess = EQ_ARRAY(EQPlayer4554E5_guess*, 0x00904390);
                    char* name_guess = EQ_ARRAY(char, 0x0090424D);
                    do {
                        if (*name_guess != 0 &&
                            strcmp(name_guess, player_guess->name120_guess) == 0) {
                            *slot_guess = player_guess;
                        }
                        slot_guess++;
                        name_guess += 0x40;
                    } while ((int)name_guess < (int)EQ_ARRAY(char, 0x0090438D));
                }
                SetPetIdFromSpawnList_guess((Target452198Target_guess*)player_guess);
                if (g_charView4554E5_guess != 0 &&
                    strcmp(g_charView4554E5_guess->name03C_guess, player_guess->name120_guess) == 0) {
                    g_currentPlayer4554E5_guess = player_guess;
                    player_guess->standState251_guess = 100;
                    g_charView4554E5_guess->value104_guess = 100;
                    g_cachedPlayer4554E5_guess = g_currentPlayer4554E5_guess;
                    g_cachedIndex4554E5_guess = 0;
                    g_updateSettings_guess->SetViewActor_guess(player_guess->pActorInfo_guess->value00_guess);
                    g_loaded4554E5_guess = 1;
                }
                if (player_guess->IsHorseUsingHumanModel_guess() != 0) {
                    player_guess->FUN_0047a3b3_guess(1);
                }
                if (player_guess->IsHorseRace_guess() != 0 &&
                    player_guess->pActorInfo_guess->value160_guess != 0 &&
                    player_guess->pActorInfo_guess->value160_guess->FUN_0047a387_guess() != 0) {
                    player_guess->FUN_0047a3b3_guess(1);
                }
                g_currentPlayer4554E5_guess->UpdatePlayerVisibility_guess();
            }
        }
    }
}

#pragma pack(push, 1)
struct SpawnRecord455710_guess {
    unsigned char padding000_guess[7];
    char name007_guess[0x40];
    unsigned char padding047_guess[0x50];
    unsigned char level097_guess;
    unsigned char padding098_guess[0xbc];
    unsigned int id154_guess;
    unsigned int boundingRadius_0158_guess;
    unsigned char padding15c_guess[0x181 - 0x15c];
};
#pragma pack(pop)

struct NameSlot455710_guess {
    char name_guess[0x40];
};

struct SpawnPlayer455710_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x004850A0 SpawnPlayer455710_guess::SpawnPlayer455710_guess
    SpawnPlayer455710_guess(SpawnRecord455710_guess* source_guess,
                            unsigned char gender_guess, int race_guess,
                            unsigned char class_guess, const char* name_guess);

    // EXTERNAL: TITANIUM 0x00482722 SpawnPlayer455710_guess::SwapNPCMaterials_guess
    void SwapNPCMaterials_guess();

    // EXTERNAL: TITANIUM 0x0047DEC4 SpawnPlayer455710_guess::SwapFace_guess
    void SwapFace_guess(int value_guess, int zero_guess);

    // EXTERNAL: TITANIUM 0x0048A6F2 SpawnPlayer455710_guess::FUN_0048a6f2_guess
    void FUN_0048a6f2_guess();

    // EXTERNAL: TITANIUM 0x0048A945 SpawnPlayer455710_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
};

// FUNCTION: TITANIUM 0x00455710
// @early-stop: budget, structural ndiff=72
// The zone's spawn list: an array of 0x181-byte Spawn_Structs, each set up as in Handle_OP_NewSpawn_guess.
void __cdecl Handle_OP_ZoneSpawns_guess(int first_guess, int second_guess,
                                SpawnRecord455710_guess* record_guess,
                                unsigned bytes_guess) {
    SpawnPlayer455710_guess* player_guess;
    SpawnRecord455710_guess* current_guess = record_guess;
    unsigned count_guess;
    if (current_guess != 0 && (count_guess = bytes_guess / 0x181) != 0) {
        do {
            if (EQ_GLOBAL(EQPlayer*, 0x00905CC4) == 0 ||
                ResolveDispatch_guess(current_guess->id154_guess) == 0) {
                player_guess = new SpawnPlayer455710_guess(current_guess, 0, 0, 0, 0);
                if (player_guess == 0) {
                    EQ_GLOBAL(EverQuest4554E5_guess*, 0x00988DF0)->valueB50_guess = 1;
                    break;
                }
                if (player_guess->Class == 0x1a) {
                    player_guess->InNonPCRaceIllusion = 4;
                    player_guess->SwapNPCMaterials_guess();
                    if (player_guess->FaceHair != 0) {
                        player_guess->SwapFace_guess(player_guess->FaceHair, 0);
                    }
                }
                ActorInfo4554E5_guess* actor_guess =
                    (ActorInfo4554E5_guess*)player_guess->pActorInfo;
                if ((unsigned)(g_updateSettings_guess->frameTime_0148_guess -
                               actor_guess->valueEbc_guess) > 12000) {
                    player_guess->FUN_0048a6f2_guess();
                }
                actor_guess->valueEbc_guess = g_updateSettings_guess->frameTime_0148_guess;
                player_guess->FUN_0048a945_guess();
                if (player_guess->Type == 0 &&
                    EQ_GLOBAL(unsigned char, 0x009043A4) != 0) {
                    NameSlot455710_guess* name_guess =
                        EQ_ARRAY(NameSlot455710_guess, 0x0090424D);
                    EQPlayer** slot_guess = EQ_ARRAY(EQPlayer*, 0x00904390);
                    do {
                        if (name_guess->name_guess[0] != 0 &&
                            strcmp(name_guess->name_guess, player_guess->Name) == 0) {
                            *slot_guess = player_guess;
                        }
                        ++name_guess;
                        ++slot_guess;
                    } while (name_guess <
                             EQ_ARRAY(NameSlot455710_guess, 0x0090438D));
                }
                SetPetIdFromSpawnList_guess((Target452198Target_guess*)player_guess);
                CharacterView4554E5_guess* character_guess =
                    EQ_GLOBAL(CharacterView4554E5_guess*, 0x00905D00);
                if (character_guess != 0 &&
                    strcmp(character_guess->name03C_guess, player_guess->Name) == 0) {
                    EQ_GLOBAL(EQPlayer*, 0x00905CE4) = player_guess;
                    player_guess->StandState = 100;
                    character_guess->value104_guess = 100;
                    EQ_GLOBAL(EQPlayer*, 0x00905CF8) =
                        EQ_GLOBAL(EQPlayer*, 0x00905CE4);
                    EQ_GLOBAL(int, 0x00905CFC) = 0;
                    g_updateSettings_guess->SetViewActor_guess(actor_guess->value00_guess);
                    EQ_GLOBAL(int, 0x00905C00) = 1;
                }
            }
            --count_guess;
            ++current_guess;
        } while (count_guess != 0);
    }
}

// FUNCTION: TITANIUM 0x00455023
// Setters on pCharData's profile block (locator_guess finds it). Field meanings come from the callers:
// +0x11A4 level (Ext455D86_guess), +0x11B4..+0x11CC the stats in wire order STR STA CHA DEX INT AGI
// WIS (Handle_OP_IncreaseStats_guess), +0x11F8 probably practice points (+5 per level gained).
// Level.
void PropertyOwner_guess::Set11a4_guess(int value_guess) {
    locator_guess.GetCharInfo2()->level_11a4_guess = value_guess;
}

// FUNCTION: TITANIUM 0x00455038
// STR.
void PropertyOwner_guess::Set11b4_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseStr_11b4_guess = value_guess;
}

// FUNCTION: TITANIUM 0x0045504D
// STA.
void PropertyOwner_guess::Set11b8_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseSta_11b8_guess = value_guess;
}

// FUNCTION: TITANIUM 0x00455062
// CHA.
void PropertyOwner_guess::Set11bc_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseCha_11bc_guess = value_guess;
}

// FUNCTION: TITANIUM 0x00455077
// DEX.
void PropertyOwner_guess::Set11c0_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseDex_11c0_guess = value_guess;
}

// FUNCTION: TITANIUM 0x0045508C
// INT.
void PropertyOwner_guess::Set11c4_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseInt_11c4_guess = value_guess;
}

// FUNCTION: TITANIUM 0x004550A1
// AGI.
void PropertyOwner_guess::Set11c8_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseAgi_11c8_guess = value_guess;
}

// FUNCTION: TITANIUM 0x004550B6
// WIS.
void PropertyOwner_guess::Set11cc_guess(int value_guess) {
    locator_guess.GetCharInfo2()->baseWis_11cc_guess = value_guess;
}

// FUNCTION: TITANIUM 0x004550CB
// +0x11E4..+0x11F0: four values set together by opcode 0x46D9, after the carried coins at +0x11D4.
void PropertyOwner_guess::Set11e4_guess(int value_guess) {
    locator_guess.GetCharInfo2()->cursorPlatinum_11e4_guess = value_guess;
}

// Sets the gold on the cursor (profile +0x11E8); the profile load fills it.
// FUNCTION: TITANIUM 0x004550E0
void PropertyOwner_guess::SetGoldCursor_guess(int value_guess) {
    locator_guess.GetCharInfo2()->cursorGold_11e8_guess = value_guess;
}

// Sets the silver on the cursor (profile +0x11EC); the profile load fills it.
// FUNCTION: TITANIUM 0x004550F5
void PropertyOwner_guess::SetSilverCursor_guess(int value_guess) {
    locator_guess.GetCharInfo2()->cursorSilver_11ec_guess = value_guess;
}

// Sets the copper on the cursor (profile +0x11F0); the profile load fills it.
// FUNCTION: TITANIUM 0x0045510A
void PropertyOwner_guess::SetCopperCursor_guess(int value_guess) {
    locator_guess.GetCharInfo2()->cursorCopper_11f0_guess = value_guess;
}

// FUNCTION: TITANIUM 0x0045511F
// Probably practice points.
void PropertyOwner_guess::Set11f8_guess(int value_guess) {
    locator_guess.GetCharInfo2()->practicePoints_11f8_guess = value_guess;
}

struct Request455134_guess {
    char target00_guess[0x40];
    char text40_guess[0x40];
    int id80_guess;
    int kind84_guess;
};

struct Message455134_guess {
    char text00_guess[0x40];
    char name40_guess[0x40];
    int status80_guess;
    int id84_guess;
};

struct CharacterHead455134_guess {
    void* vftable_guess;
    int field04_guess;
};

struct CharacterName455134_guess {
    unsigned char padding00_guess[0x3C];
    char name3C_guess[0x40];
};

struct Character455134_guess : CharacterHead455134_guess, virtual CharacterName455134_guess {
    unsigned char padding0C_guess[0xE0C - 0xC];
    int value0E0C_guess;
    unsigned char value0E10_guess;
};

#define g_character455134_guess EQ_GLOBAL(Character455134_guess*, 0x00905D00)
#define g_noticeOverride455134_guess EQ_GLOBAL(int, 0x00924960)

struct ConfirmationPool455134_guess {
    // EXTERNAL: TITANIUM 0x005481CF ConfirmationPool455134_guess::Find_guess
    int Find_guess(void* parent_guess, int type_guess);
};

#define g_confirmationPool455134_guess EQ_GLOBAL(ConfirmationPool455134_guess*, 0x00991E44)

// EXTERNAL: TITANIUM 0x0046DC2E Notice455134_guess
void __cdecl Notice455134_guess(int zero1_guess, int code_guess, int color_guess,
                                const char* text_guess, const char* source_guess,
                                int zero6_guess, int zero7_guess, int zero8_guess,
                                int zero9_guess, int zero10_guess, int zero11_guess,
                                int zero12_guess, int zero13_guess);

// FUNCTION: TITANIUM 0x00455134
// @early-stop: budget, structural ndiff=109
// GuildCommand_Struct {othername, myname, guild id, officer} for this player only. Answers with
// OP_GuildInviteAccept (0x61D0; response 0-2 rank, +10 same rank, 3 in another guild, 4 another box is
// open, 5 invites off, i.e. 0x00924960 clear) or asks first in a 10 s yes/no box.
// Rank 0-2 picks strings 0x216-0x218 (invite), 0x224/0x225 (promotion), 0x21F-0x221 (auto-declined).
void __cdecl Handle_OP_GuildInvite_guess(int unused1_guess, int unused2_guess,
                                char* text_guess) {
    Message455134_guess message_guess;
    char notice_guess[512];
    char alternate_guess[512];

    memset(&message_guess, 0, sizeof(message_guess));
    if (__stricmp(g_character455134_guess->name3C_guess, text_guess) != 0) {
        return;
    }
    Request455134_guess* request_guess = (Request455134_guess*)text_guess;
    if (g_propertyNoticeEnabled_guess != 0) {
        g_propertyNoticeEnabled_guess->FUN_00564e7e_guess(0x19, 0);
    }
    text_guess = request_guess->text40_guess;
    strcpy(message_guess.text00_guess, text_guess);
    strcpy(message_guess.name40_guess, g_character455134_guess->name3C_guess);
    message_guess.id84_guess = request_guess->id80_guess;

    if (g_character455134_guess->value0E0C_guess == message_guess.id84_guess ||
        g_noticeOverride455134_guess != 0) {
        switch (request_guess->kind84_guess) {
        case 0:
            FormatNotice_guess(notice_guess, 0x216, text_guess,
                               g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                               0, 0, 0, 0, 0, 0, 0);
            break;
        case 1:
            FormatNotice_guess(notice_guess, 0x217, text_guess,
                               g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                               0, 0, 0, 0, 0, 0, 0);
            break;
        case 2:
            FormatNotice_guess(notice_guess, 0x218, text_guess,
                               g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                               0, 0, 0, 0, 0, 0, 0);
            break;
        }
        if (g_character455134_guess->value0E0C_guess < 0 ||
            g_character455134_guess->value0E0C_guess == request_guess->id80_guess) {
            int found_guess = g_confirmationPool455134_guess->Find_guess(
                pEverQuest ? &pEverQuest->vftable_08 : 0, 100);
            if (found_guess == -1) {
                void* copy_guess;
                if (g_character455134_guess->value0E0C_guess == -1 &&
                    request_guess->kind84_guess >= 0 && request_guess->kind84_guess < 3) {
                    copy_guess = operator new(0x88);
                    memcpy(copy_guess, request_guess, 0x88);
                    pConfirmationDialogPool_guess->Activate(
                        pEverQuest ? &pEverQuest->vftable_08 : 0, 100, notice_guess, 12, 10000,
                        (int)copy_guess, 1);
                    return;
                }
                if (g_character455134_guess->value0E0C_guess != request_guess->id80_guess) {
                    return;
                }
                if (request_guess->kind84_guess == g_character455134_guess->value0E10_guess) {
                    message_guess.status80_guess = request_guess->kind84_guess + 10;
                    EQSendMessage(g_messageBuffer_guess, OP_GuildInviteAccept, &message_guess, 0x88, 1);
                    return;
                }
                if (request_guess->kind84_guess < g_character455134_guess->value0E10_guess) {
                    if (request_guess->kind84_guess == 0) {
                        Notice455134_guess(0, 0x223, 0x111, text_guess, 0,
                                           0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    message_guess.status80_guess = request_guess->kind84_guess;
                    EQSendMessage(g_messageBuffer_guess, OP_GuildInviteAccept, &message_guess, 0x88, 1);
                    return;
                }
                switch (request_guess->kind84_guess) {
                case 1:
                    FormatNotice_guess(alternate_guess, 0x224, text_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    break;
                case 2:
                    FormatNotice_guess(alternate_guess, 0x225, text_guess,
                                       0, 0, 0, 0, 0, 0, 0, 0);
                    break;
                }
                copy_guess = operator new(0x88);
                memcpy(copy_guess, request_guess, 0x88);
                pConfirmationDialogPool_guess->Activate(
                    pEverQuest ? &pEverQuest->vftable_08 : 0, 100, alternate_guess, 12, 10000,
                    (int)copy_guess, 1);
                return;
            }
            message_guess.status80_guess = 4;
        } else {
            message_guess.status80_guess = 3;
        }
        EQSendMessage(g_messageBuffer_guess, OP_GuildInviteAccept, &message_guess, 0x88, 1);
        pEverQuest->dsp_chat(notice_guess, 0x111, 1);
        return;
    }

    message_guess.status80_guess = 5;
    EQSendMessage(g_messageBuffer_guess, OP_GuildInviteAccept, &message_guess, 0x88, 1);
    switch (request_guess->kind84_guess) {
    case 0:
        Notice455134_guess(0, 0x21f, 0x111, text_guess,
                           g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 1:
        Notice455134_guess(0, 0x220, 0x111, text_guess,
                           g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 2:
        Notice455134_guess(0, 0x221, 0x111, text_guess,
                           g_textLookup453B3F_guess.Lookup_guess(request_guess->id80_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        break;
    }
    pEverQuest->dsp_chat(pStringTable->getString(0x222, 0), 0x111, 1);
}

struct ResurrectEntry_guess {
    unsigned char type0_guess;
    unsigned char type1_guess;
    unsigned char type2_guess;
    unsigned char padding3_guess;
    int value4_guess;
    int value8_guess;
    int valueC_guess;
};

struct CommandContext456FD1_guess {
    unsigned char padding_guess[4];

    // EXTERNAL: TITANIUM 0x0040D933 CommandContext456FD1_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();

    // EXTERNAL: TITANIUM 0x0040E7AC CommandContext456FD1_guess::GetBuff_guess
    ResurrectEntry_guess* GetBuff_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00416963 CommandContext456FD1_guess::GetValue_guess
    int GetValue_guess(int zero_guess);

    // EXTERNAL: TITANIUM 0x0040F06D CommandContext456FD1_guess::StopSpellCast_guess
    void StopSpellCast_guess(int first_guess, int second_guess);

    // EXTERNAL: TITANIUM 0x0040F8A0 CommandContext456FD1_guess::Handle_guess
    void Handle_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x004106A3 CommandContext456FD1_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first_guess, int second_guess,
                           int third_guess, int fourth_guess);
};

struct PropertyOwnerOffset_guess {
    unsigned char padding_guess[4];
    int vbaseOffset_0004_guess;
};

struct PropertyOwnerRoot_guess {
    unsigned char padding_guess[8];
    union {
        PropertyOwnerOffset_guess* vbtable_0008_guess;
        unsigned char embedded_guess[0xC278];
    };
    CommandContext456FD1_guess command_guess;

    // EXTERNAL: TITANIUM 0x004BD9B8 PropertyOwnerRoot_guess::CheckDupLoreItems_guess
    int CheckDupLoreItems_guess();

    // EXTERNAL: TITANIUM 0x005F07C0 PropertyOwnerRoot_guess::FUN_005f07c0_guess
    float FUN_005f07c0_guess(int zero_guess);

    // EXTERNAL: TITANIUM 0x005F0820 PropertyOwnerRoot_guess::FUN_005f0820_guess
    float FUN_005f0820_guess(int zero_guess);

    // EXTERNAL: TITANIUM 0x005F0880 PropertyOwnerRoot_guess::FUN_005f0880_guess
    float FUN_005f0880_guess(int zero_guess);
};

struct ResurrectRootState_guess {
    unsigned char padding00_guess[0xC28C];
    unsigned char valueC28c_guess;
    unsigned char paddingC28d_guess[0xC348 - 0xC28d];
    unsigned char valueC348_guess;
};

#define g_resurrectRootState_guess EQ_GLOBAL(ResurrectRootState_guess*, 0x00905D00)

struct PropertyOwnerCallback_guess {
    // EXTERNAL: TITANIUM 0x00417CC8 PropertyOwnerCallback_guess::Update_guess
    void Update_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417CDD PropertyOwnerCallback_guess::Update00_guess
    void Update00_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D07 PropertyOwnerCallback_guess::Update04_guess
    void Update04_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D31 PropertyOwnerCallback_guess::Update08_guess
    void Update08_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D5B PropertyOwnerCallback_guess::Update0C_guess
    void Update0C_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417CF2 PropertyOwnerCallback_guess::Apply00_guess
    void Apply00_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D1C PropertyOwnerCallback_guess::Apply04_guess
    void Apply04_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D46 PropertyOwnerCallback_guess::Apply08_guess
    void Apply08_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D70 PropertyOwnerCallback_guess::Apply0C_guess
    void Apply0C_guess(int value_guess);
};

struct ApplyRequest457A91_guess {
    unsigned char padding0_guess[4];
    unsigned char type4_guess;
    unsigned char padding5_guess[3];
    int value8_guess;
};

struct PropertyOwnerState457A91_guess {
    unsigned char padding_guess[0xC28C];
    unsigned char valueC28C_guess;
};

struct ErrorDisplay_guess {
    // EXTERNAL: TITANIUM 0x004982C6 ErrorDisplay_guess::dsp_chat
    void dsp_chat(const char* message_guess, int category_guess, bool flag_guess);

    // EXTERNAL: TITANIUM 0x004AB056 ErrorDisplay_guess::MoveToZone_guess
    void MoveToZone_guess(int object_guess, char* message_guess, int zero_guess,
                                int category_guess, float x_guess, float y_guess,
                                float z_guess, int value_guess);
};

#define g_propertyOwnerGlobal_guess EQ_GLOBAL(PropertyOwnerRoot_guess*, 0x00905D00)
#define g_propertyOwnerState457A91_guess EQ_GLOBAL(PropertyOwnerState457A91_guess*, 0x00905D00)
#define g_errorDisplay_guess EQ_GLOBAL(ErrorDisplay_guess*, 0x00988DF0)

struct NoticeRenderer_guess {
    // EXTERNAL: TITANIUM 0x0044A537 NoticeRenderer_guess::Show_guess
    void Show_guess(int id_guess, int zero_guess);
};

#define g_noticeRenderer_guess EQ_GLOBAL(NoticeRenderer_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x00470D4F BuildMoneyText_guess
void __cdecl BuildMoneyText_guess(int first_guess, int second_guess, int third_guess,
                               int fourth_guess, char* text_guess);

struct Target570Argument_guess {
    unsigned char padding80_guess[0x80];
    char text80_guess[0x20];
    unsigned char paddingA0_guess[0x24];
    int enabledC4_guess;
};

struct Target5718FArgument_guess {
    unsigned char padding40_guess[0x40];
    int value40_guess;
    char name44_guess[1];
};

struct Request455900_guess {
    unsigned char padding0C_guess[0xC];
    char typeC_guess;
    unsigned char paddingD_guess[3];
    int value10_guess;
};

// FUNCTION: TITANIUM 0x00455900
// Result +0xC: 0 failed (0x325C), 1-4 begged platinum/gold/silver/copper, amount +0x10 added at once.
void __cdecl Handle_OP_Begging_guess(int unused1_guess, int unused2_guess,
                                Request455900_guess* request_guess) {
    char message_guess[256];

    if (g_target4520A1Count_guess > 0) {
        --g_target4520A1Count_guess;
    } else {
        g_target4520A1Count_guess = 0;
    }

    switch (request_guess->typeC_guess) {
    case 4:
        FormatNotice_guess(message_guess, 0x3260,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply0C_guess(request_guess->value10_guess);
        break;
    case 3:
        FormatNotice_guess(message_guess, 0x325f,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply08_guess(request_guess->value10_guess);
        break;
    case 2:
        FormatNotice_guess(message_guess, 0x325e,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply04_guess(request_guess->value10_guess);
        break;
    case 1:
        FormatNotice_guess(message_guess, 0x325d,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply00_guess(request_guess->value10_guess);
        break;
    case 0:
        g_errorDisplay_guess->dsp_chat(
            pStringTable->getString(0x325c, 0), 0x10e, 1);
        break;
    }
}

struct Packet455B05_guess {
    unsigned char header_guess[0xC];
    char text_guess[0x814];
    char message_guess[0x100];
};

struct Request455B05_guess {
    unsigned char padding0C_guess[0xC];
    char typeC_guess;
    unsigned char paddingD_guess[3];
    int value10_guess;
    char name14_guess[1];
};

// FUNCTION: TITANIUM 0x00455B05
// Result +0xC: -1 ignored, 0 failed (0x3262), 1-4 stole platinum..copper (amount +0x10), 5 stole the
// item named at +0x14. Same shape as Handle_OP_Begging_guess.
void __cdecl Handle_OP_PickPocket_guess(int unused1_guess, int unused2_guess,
                                Request455B05_guess* request_guess) {
    Packet455B05_guess packet_guess;

    memset(packet_guess.text_guess, 0, 0x814);
    memset(packet_guess.header_guess, 0, 0xC);

    if (request_guess->typeC_guess == -1) {
        return;
    }

    if (g_target4520A1Count_guess > 0) {
        --g_target4520A1Count_guess;
    } else {
        g_target4520A1Count_guess = 0;
    }

    switch (request_guess->typeC_guess) {
    case 5:
        FormatNotice_guess(packet_guess.message_guess, 0x3267,
                           request_guess->name14_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(packet_guess.message_guess, 0x10e, 1);
        break;
    case 4:
        FormatNotice_guess(packet_guess.message_guess, 0x3266,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(packet_guess.message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply0C_guess(request_guess->value10_guess);
        break;
    case 3:
        FormatNotice_guess(packet_guess.message_guess, 0x3265,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(packet_guess.message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply08_guess(request_guess->value10_guess);
        break;
    case 2:
        FormatNotice_guess(packet_guess.message_guess, 0x3264,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(packet_guess.message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply04_guess(request_guess->value10_guess);
        break;
    case 1:
        FormatNotice_guess(packet_guess.message_guess, 0x3263,
                           _itoa(request_guess->value10_guess,
                                 EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(packet_guess.message_guess, 0x10e, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply00_guess(request_guess->value10_guess);
        break;
    case 0:
        g_errorDisplay_guess->dsp_chat(
            pStringTable->getString(0x3262, 0), 0x10e, 1);
        break;
    }

    g_propertyOwnerGlobal_guess->CheckDupLoreItems_guess();
}

struct LevelOwner455D86_guess {
    unsigned char padding_guess[0x1A10];
    int value1A10_guess;
    int value1A14_guess;

    // EXTERNAL: TITANIUM 0x005ED510 LevelOwner455D86_guess::Get5861_guess
    unsigned char Get5861_guess();

    // EXTERNAL: TITANIUM 0x005ED530 LevelOwner455D86_guess::Set5861_guess
    void Set5861_guess(unsigned char value_guess);
};

#define g_levelOwner455D86_guess EQ_GLOBAL(LevelOwner455D86_guess*, 0x00905D00)

struct CharacterChatWriter455D86_guess {
    // EXTERNAL: TITANIUM 0x00424642 CharacterChatWriter455D86_guess::UpdateAutoJoinChannels_guess
    void UpdateAutoJoinChannels_guess(PropertyOwnerRoot_guess* owner_guess);
};

#define g_characterChatWriter455D86_guess EQ_GLOBAL(CharacterChatWriter455D86_guess*, 0x0079DBD4)

struct UpdateGate455D86_guess {
    // EXTERNAL: TITANIUM 0x00554190 UpdateGate455D86_guess::Flush_guess
    void Flush_guess();
};

#define pinstCSkillsSelectWnd_guess EQ_GLOBAL(UpdateGate455D86_guess*, 0x00850BB8)

struct CurrentPlayer455D86_guess {
    unsigned char padding_guess[0x24C];
    unsigned char value24c_guess;

    // EXTERNAL: TITANIUM 0x0047A085 CurrentPlayer455D86_guess::InitSneakMod_guess
    void InitSneakMod_guess();
};

#define g_currentPlayer455D86_guess EQ_GLOBAL(CurrentPlayer455D86_guess*, 0x00905CE4)

// FUNCTION: TITANIUM 0x00455D86
// @early-stop: tiebreak, structural ndiff=36
// OP_LevelUpdate {level, level_old, exp}: prints "You LOST a level" texts on a drop, else sets the level,
// adds 5 practice points per gain, plays the level-up effect (0x8B) and stores exp.
void __cdecl Handle_OP_LevelUpdate_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                             unsigned size_guess) {
    int* values_guess = (int*)data_guess;
    char message_guess[0x400];

    if (g_propertyOwnerGlobal_guess != 0) {
        PropertyOwner_guess* owner_guess =
            (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
        if (*values_guess < owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess) {
            owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
            int difference_guess = owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess;
            difference_guess -= *values_guess;
            message_guess[0] = 0;
            if (difference_guess == 1) {
                FormatNotice_guess(message_guess, 0x1ba,
                                   _itoa(*values_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                                   0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FormatNotice_guess(message_guess, 0x1bb,
                                   _itoa(difference_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                                   _itoa(*values_guess, EQ_ARRAY(char, 0x0099DAE0), 10),
                                   0, 0, 0, 0, 0, 0, 0);
            }
            g_errorDisplay_guess->dsp_chat(message_guess, 0xd, 1);
        }

        if (g_updateProcessor453A68_guess != 0) {
            g_updateProcessor453A68_guess->UpdateRows_guess();
        }

        owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
        if (owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess != *values_guess) {
            if (*values_guess > values_guess[1]) {
                owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
                owner_guess->locator_guess.GetCharInfo2()->practicePoints_11f8_guess += 5;
            }
            if (*values_guess == 10 && g_propertyNoticeEnabled_guess != 0) {
                g_propertyNoticeEnabled_guess->FUN_00564e7e_guess(0x18, 0);
            }

            owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
            if (owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess < *values_guess) {
                g_noticeRenderer_guess->Show_guess(0x8b, 0);
            }

            owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
            owner_guess->Set11a4_guess(*values_guess);
            g_characterChatWriter455D86_guess->UpdateAutoJoinChannels_guess(g_propertyOwnerGlobal_guess);
            if (*values_guess > g_levelOwner455D86_guess->Get5861_guess()) {
                g_levelOwner455D86_guess->Set5861_guess((unsigned char)*values_guess);
            }

            g_levelOwner455D86_guess->value1A10_guess = values_guess[2];
            g_levelOwner455D86_guess->value1A14_guess = values_guess[2] >> 31;

            if (pinstCSkillsSelectWnd_guess != 0) {
                pinstCSkillsSelectWnd_guess->Flush_guess();
            }
            if (g_currentPlayer455D86_guess != 0) {
                owner_guess = (PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
                g_currentPlayer455D86_guess->value24c_guess =
                    (unsigned char)owner_guess->locator_guess.GetCharInfo2()->level_11a4_guess;
                g_currentPlayer455D86_guess->InitSneakMod_guess();
            }
        }
    }
}

// FUNCTION: TITANIUM 0x00455FC0
// Opcode 0xE37: sets a spawn's HP (+0x274); for the player also pCharData's current HP.
void __cdecl SetSpawnHitPoints_guess(DispatchRequest_guess* request_guess) {
    DispatchTarget_guess* target_guess = ResolveDispatch_guess(request_guess->operation_guess);
    if (target_guess == 0) {
        return;
    }
    target_guess->hpCurrent_0274_guess = request_guess->first_guess;
    if (target_guess != g_propertyOwnerCurrent_guess) {
        return;
    }
    PropertyOwnerRoot_guess* root_guess = g_propertyOwnerGlobal_guess;
    if (root_guess != 0) {
        PropertyOwnerOffset_guess* offset_guess = root_guess->vbtable_0008_guess;
        PropertyOwnerCallback_guess* callback_guess =
            (PropertyOwnerCallback_guess*)&root_guess->embedded_guess[offset_guess->vbaseOffset_0004_guess];
        callback_guess->Update_guess(request_guess->first_guess);
    }
}

// FUNCTION: TITANIUM 0x00455FFF
// GM stat change. For the player, stat 1-7 is AGI CHA DEX INT STA STR WIS (alphabetical); for another
// spawn it is the GM's result: value < 0 "Ability change operation failed" (0x3273), else 0x3274.
void __cdecl Handle_OP_IncreaseStats_guess(DispatchRequest_guess* request_guess) {
    if (request_guess->operation_guess == g_propertyOwnerCurrent_guess->spawnId_0258_guess) {
        if (request_guess->second_guess > 0) {
            switch (request_guess->first_guess) {
            case 1:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11c8_guess(
                        request_guess->second_guess);
                return;
            case 2:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11bc_guess(
                        request_guess->second_guess);
                return;
            case 3:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11c0_guess(
                        request_guess->second_guess);
                return;
            case 4:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11c4_guess(
                        request_guess->second_guess);
                return;
            case 5:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11b8_guess(
                        request_guess->second_guess);
                return;
            case 6:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11b4_guess(
                        request_guess->second_guess);
                return;
            case 7:
                ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11cc_guess(
                        request_guess->second_guess);
                return;
            }
        }
    } else {
        if (request_guess->second_guess < 0) {
            g_errorDisplay_guess->dsp_chat(
                pStringTable->getString(0x3273, 0), 0xf, 1);
        } else {
            g_errorDisplay_guess->dsp_chat(
                pStringTable->getString(0x3274, 0), 0xf, 1);
        }
    }
}

struct ResurrectRequest_guess {
    int value0_guess;
    int object4_guess;
    float x8_guess;
    float yC_guess;
    float z10_guess;
    int level14_guess;
    unsigned char padding18_guess[0xC8];
    int stateE0_guess;
};

struct ResurrectOwner_guess {
    unsigned char padding00_guess[4];
    EQ_CharacterProfileView_guess locator_guess;
    unsigned char padding08_guess[0x2c - 8];
    float value2c_guess;
    float value30_guess;
    float value34_guess;
    unsigned char padding38_guess[0xbc - 0x38];
    PropertyOwnerClear_guess clearBC_guess;

    // EXTERNAL: TITANIUM 0x0040E293 ResurrectOwner_guess::Set11a8_guess
    void Set11a8_guess(int value_guess);
};

struct ResurrectOptionsVtable_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual int GetVirtualValue_guess() = 0;
};

struct ZoneCommand456110_guess {
    int object0_guess;
    int zone4_guess;  // spell id (Translocate_Struct)
    unsigned char padding8_guess[4];
    char flagC_guess;  // caster name, 64 bytes
    unsigned char paddingD_guess[0x3f];
    float x4c_guess;
    float y50_guess;
    float z54_guess;
    int state58_guess;  // complete: 0 offer, 1 do it
};

struct ZoneNames456110_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneNames456110_guess::GetLongName_guess
    void GetLongName_guess(int zone_guess, char* name_guess, int flag_guess);
};

#define g_zoneNames456110_guess EQ_GLOBAL(ZoneNames456110_guess*, 0x00905CC0)

// FUNCTION: TITANIUM 0x00456110
// @early-stop: budget, structural ndiff=68
// Translocate_Struct {zone id, spell id, unknown, caster[64], y, x, z, complete (+0x58)}; zone4_guess is
// the spell id. Not complete: a 5-minute yes/no box; spells 1334, 1422 and 3243 (0x536, 0x58E, 0xCAB) go
// to the bind point ("... to your bind point?"), others to the named zone. Complete: moves or zones there.
void __cdecl Handle_OP_Translocate_guess(ZoneCommand456110_guess* argument_guess) {
    float y_guess;
    float x_guess;
    char message_guess[512];
    char zoneName_guess[128];
    float z_guess;

    if (argument_guess->state58_guess != 1) {
        int zone_guess = argument_guess->zone4_guess;
        if (zone_guess == 0x58e || zone_guess == 0x536 || zone_guess == 0xcab) {
            strcpy(message_guess, pStringTable->getString(0x2366, 0));
        } else {
            g_zoneNames456110_guess->GetLongName_guess(argument_guess->object0_guess,
                                                        zoneName_guess, 1);
            FormatNotice_guess(message_guess, 0x2367,
                               g_target4520E5Data_guess->GetText_guess(
                                   (const char*)&argument_guess->flagC_guess),
                               zoneName_guess, 0, 0, 0, 0, 0, 0, 0);
        }
        g_noticeSender_guess->Activate(
            g_errorDisplay_guess == 0
                ? 0U
                : (unsigned)g_errorDisplay_guess + 8U,
            0x66, message_guess, 0xc, 300000, 0, 0);
        return;
    }

    g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value158_guess = 0;
    ((ResurrectOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
        g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
        ->clearBC_guess.Clear_guess(EQ_ARRAY(char, 0x0063F53F));

    int zone_guess = argument_guess->zone4_guess;
    if (zone_guess == 0x536 || zone_guess == 0x58e || zone_guess == 0xcab) {
        x_guess = g_propertyOwnerGlobal_guess->FUN_005f07c0_guess(0);
        y_guess = g_propertyOwnerGlobal_guess->FUN_005f0820_guess(0);
        z_guess = g_propertyOwnerGlobal_guess->FUN_005f0880_guess(0);
    } else {
        x_guess = argument_guess->x4c_guess;
        y_guess = argument_guess->y50_guess;
        z_guess = argument_guess->z54_guess;
    }

    g_propertyOwnerCurrent_guess->PlaySound_guess(0x89);
    if (argument_guess->flagC_guess == 0) {
        if (argument_guess->object0_guess == g_propertyOwnerCurrent_guess->value204_guess) {
            ResurrectOwner_guess* owner_guess = (ResurrectOwner_guess*)
                &g_propertyOwnerGlobal_guess->embedded_guess[
                    g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
            owner_guess->value2c_guess = g_propertyOwnerCurrent_guess->value30_guess;
            owner_guess->value30_guess = g_propertyOwnerCurrent_guess->value34_guess;
            owner_guess->value34_guess = g_propertyOwnerCurrent_guess->value38_guess;
            x_guess = g_propertyOwnerCurrent_guess->value30_guess;
            y_guess = g_propertyOwnerCurrent_guess->value34_guess;
            z_guess = g_propertyOwnerCurrent_guess->value38_guess;
        }
        g_errorDisplay_guess->MoveToZone_guess(
            argument_guess->object0_guess, EQ_ARRAY(char, 0x0064481C), 0, 4,
            x_guess, y_guess, z_guess, (int)g_propertyOwnerCurrent_guess->heading_004c_guess);
    } else if (argument_guess->object0_guess == g_propertyOwnerCurrent_guess->value204_guess) {
        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value158_guess = 0;
        ((ResurrectOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->clearBC_guess.Clear_guess(EQ_ARRAY(char, 0x0063F53F));
        g_propertyOwnerCurrent_guess->value3c_guess = 0.0f;
        g_propertyOwnerCurrent_guess->value40_guess = 0.0f;
        g_propertyOwnerCurrent_guess->value44_guess = 0.0f;
        g_propertyOwnerCurrent_guess->value58_guess = 0.0f;
        g_propertyOwnerCurrent_guess->value54_guess = 0.0f;
        g_propertyOwnerCurrent_guess->speedRun_0048_guess = 0.0f;

        ResurrectOwner_guess* owner_guess = (ResurrectOwner_guess*)
            &g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess];
        owner_guess->value2c_guess = x_guess;
        g_propertyOwnerCurrent_guess->value30_guess = x_guess;
        owner_guess->value30_guess = y_guess;
        g_propertyOwnerCurrent_guess->value34_guess = y_guess;
        owner_guess->value34_guess = z_guess;
        g_propertyOwnerCurrent_guess->value38_guess = z_guess;
        BeginPositionUpdate_guess(&g_propertyOwnerCurrent_guess->value30_guess)->Apply_guess(
            &g_propertyOwnerCurrent_guess->value30_guess, 3);

        float height_guess = g_propertyOwnerCurrent_guess->GetFloorHeightAt_guess(
            x_guess, y_guess, z_guess + *EQ_ARRAY(float, 0x0063F4D0), 1);
        if (height_guess != *EQ_ARRAY(float, 0x00640EA0)) {
            g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value48_guess = height_guess;
            g_propertyOwnerCurrent_guess->value38_guess =
                height_guess + g_propertyOwnerCurrent_guess->heightOffset_0238_guess;
        }
        g_propertyOwnerCurrent_guess->FUN_0048a945_guess();
    } else {
        g_errorDisplay_guess->MoveToZone_guess(
            argument_guess->object0_guess, EQ_ARRAY(char, 0x0064481C), 0, 8,
            x_guess, y_guess, z_guess, (int)g_propertyOwnerCurrent_guess->heading_004c_guess);
    }
    g_propertyOwnerCurrent_guess->UpdateSharedValuesIfLocal_guess();
}

// FUNCTION: TITANIUM 0x004564BA
// @early-stop: budget, structural ndiff=139
// Resurrect_Struct, action at +0xE0 (1 = success). Clears every buff; when +0x14 is below 100 it also
// cuts HP and adds buff 756 or 757 (0x2F4/0x2F5 by +0x1198, probably the resurrection-sickness spells).
// EQEmu puts y at +8 and x at +0xC. Note: +0x30 and +0x34 of the saved position both get x below,
// unlike Handle_OP_Translocate_guess (not checked against the asm).
void __cdecl Handle_OP_RezzComplete_guess(ResurrectRequest_guess* request_guess) {
    if (request_guess->stateE0_guess == 1) {
        g_errorDisplay_guess->dsp_chat(
            pStringTable->getString(0x3275, 0), 0x108, 1);

        PropertyOwnerRoot_guess* root_guess = g_propertyOwnerGlobal_guess;
        ResurrectRootState_guess* rootState_guess = g_resurrectRootState_guess;
        CommandContext456FD1_guess* options_guess = &root_guess->command_guess;
        ResurrectOwner_guess* owner_guess = (ResurrectOwner_guess*)&root_guess->embedded_guess[
            root_guess->vbtable_0008_guess->vbaseOffset_0004_guess];

        int optionIndex_guess = 0;
        if (options_guess->GetMaxBuffs_guess() != 0) {
            do {
                ResurrectEntry_guess* option_guess =
                    options_guess->GetBuff_guess(optionIndex_guess);
                option_guess->value4_guess = -1;
                option_guess->type0_guess = 0;
                option_guess->type2_guess = 0;
                option_guess->type1_guess = 0;
                option_guess->value8_guess = 0;
                option_guess->valueC_guess = 0;
                ++optionIndex_guess;
            } while (optionIndex_guess < options_guess->GetMaxBuffs_guess());
        }

        rootState_guess->valueC348_guess = 0;
        if (request_guess->level14_guess < 100) {
            ResurrectEntry_guess* option_guess = options_guess->GetBuff_guess(0);
            owner_guess->locator_guess.GetCharInfo2()->mana_11a8_guess = 0;
            int optionValue_guess = options_guess->GetValue_guess(0);
            ((PropertyOwnerCallback_guess*)owner_guess)->Update_guess(optionValue_guess / 3);

            if (owner_guess->locator_guess.GetCharInfo2()->race_1198_guess == 10 ||
                owner_guess->locator_guess.GetCharInfo2()->race_1198_guess == 9 ||
                owner_guess->locator_guess.GetCharInfo2()->race_1198_guess == 2 ||
                owner_guess->locator_guess.GetCharInfo2()->race_1198_guess == 8) {
                option_guess->value4_guess = 0x2f5;
            } else {
                option_guess->value4_guess = 0x2f4;
            }
            option_guess->value8_guess = 0x28;
            option_guess->valueC_guess = 0;
            option_guess->type0_guess = 2;
            option_guess->type2_guess = 10;
            option_guess->type1_guess = 0x34;
            rootState_guess->valueC28c_guess = 1;
            rootState_guess->valueC348_guess = 0;
        } else {
            owner_guess->Set11a8_guess(
                ((ResurrectOptionsVtable_guess*)options_guess)->GetVirtualValue_guess());
            int optionValue_guess = options_guess->GetValue_guess(0);
            ((PropertyOwnerCallback_guess*)owner_guess)->Update_guess(optionValue_guess);
        }

        int currentValue_guess = (int)g_propertyOwnerCurrent_guess->heading_004c_guess;
        float x_guess = request_guess->x8_guess;
        float y_guess = request_guess->yC_guess;
        float z_guess = request_guess->z10_guess;
        if (request_guess->object4_guess == g_propertyOwnerCurrent_guess->value204_guess) {
            g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value158_guess = 0;
            owner_guess->clearBC_guess.Clear_guess(EQ_ARRAY(char, 0x0063F53F));
            g_propertyOwnerCurrent_guess->value3c_guess = 0.0f;
            g_propertyOwnerCurrent_guess->value40_guess = 0.0f;
            g_propertyOwnerCurrent_guess->value44_guess = 0.0f;
            g_propertyOwnerCurrent_guess->value58_guess = 0.0f;
            g_propertyOwnerCurrent_guess->value54_guess = 0.0f;
            g_propertyOwnerCurrent_guess->speedRun_0048_guess = 0.0f;

            float position_guess[3];
            position_guess[0] = x_guess;
            position_guess[1] = y_guess;
            position_guess[2] = z_guess;
            g_propertyOwnerCurrent_guess->SetPosition_guess(position_guess, 3);

            owner_guess->value2c_guess = x_guess;
            g_propertyOwnerCurrent_guess->value30_guess = x_guess;
            owner_guess->value30_guess = x_guess;
            g_propertyOwnerCurrent_guess->value34_guess = y_guess;
            owner_guess->value34_guess = x_guess;
            g_propertyOwnerCurrent_guess->value38_guess = z_guess;

            float height_guess = g_propertyOwnerCurrent_guess->GetFloorHeightAt_guess(
                x_guess, y_guess, z_guess + *EQ_ARRAY(float, 0x0063F4D0), 1);
            if (height_guess != *EQ_ARRAY(float, 0x00640EA0)) {
                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value48_guess = height_guess;
                g_propertyOwnerCurrent_guess->value38_guess =
                    height_guess + g_propertyOwnerCurrent_guess->heightOffset_0238_guess;
            }
            g_propertyOwnerCurrent_guess->FUN_0048a945_guess();
        } else {
            g_errorDisplay_guess->MoveToZone_guess(
                request_guess->object4_guess, EQ_ARRAY(char, 0x0064482C), 0, 9,
                x_guess, y_guess, z_guess, currentValue_guess);
        }
        return;
    }

    g_errorDisplay_guess->dsp_chat(
        pStringTable->getString(0x3276, 0), 0x108, 1);
}

// FUNCTION: TITANIUM 0x0045686E
// MoneyUpdate_Struct: sets carried platinum, gold, silver, copper.
void __cdecl Handle_OP_MoneyUpdate_guess(int* values_guess) {
    if (g_propertyOwnerGlobal_guess != 0) {
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Update00_guess(values_guess[0]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Update04_guess(values_guess[1]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Update08_guess(values_guess[2]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Update0C_guess(values_guess[3]);
    }
}

// FUNCTION: TITANIUM 0x004568D4
// Opcode 0x56D4: adds platinum, gold, silver, copper and prints "You receive %1." (0x1735).
void __cdecl Handle_MoneyReceived_guess(int* values_guess) {
    char text_guess[256];
    char output_guess[512];

    if (g_propertyOwnerGlobal_guess != 0) {
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Apply00_guess(values_guess[0]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Apply04_guess(values_guess[1]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Apply08_guess(values_guess[2]);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Apply0C_guess(values_guess[3]);

        if (values_guess[1] + values_guess[2] + values_guess[3] + values_guess[0] > 0) {
            g_noticeRenderer_guess->Show_guess(0x8a, 0);
            text_guess[0] = 0;
            BuildMoneyText_guess(values_guess[0], values_guess[1], values_guess[2],
                              values_guess[3], text_guess);
            FormatNotice_guess(output_guess, 0x1735, text_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            g_errorDisplay_guess->dsp_chat(output_guess, 0x11d, 1);
        }
    }
}

struct Slot4569D4_guess {
    virtual void Slot00_guess(int value_guess) = 0;
};

struct Holder4569D4_guess {
    Slot4569D4_guess* value0_guess;
};

struct Target4569D4_guess {
    char name_guess[0x40];
    int value40_guess;
};

struct Offset4569D4_guess {
    unsigned char padding_guess[4];
    int vbaseOffset_0004_guess;
};

struct Root4569D4_guess {
    union {
        char embedded_guess[8];
        unsigned char padding_guess[8];
    };
    Offset4569D4_guess* value8_guess;

    // EXTERNAL: TITANIUM 0x004BE443 Root4569D4_guess::Resolve_guess
    Holder4569D4_guess* Resolve_guess(int value_guess);
};

#define g_root4569D4_guess EQ_GLOBAL(Root4569D4_guess*, 0x00905D00)

// FUNCTION: TITANIUM 0x004569D4
// Opcode 0x167D, for the player only (name check): releases the object held in slot +0x40.
void __cdecl FUN_004569d4_guess(Target4569D4_guess* target_guess) {
    if (g_root4569D4_guess == 0) {
        return;
    }
    if (strcmp(&g_root4569D4_guess->embedded_guess[
                   g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess + 0x44],
               target_guess->name_guess) != 0) {
        return;
    }
    Holder4569D4_guess* holder_guess =
        g_root4569D4_guess->Resolve_guess(target_guess->value40_guess);
    if (holder_guess == 0 || holder_guess->value0_guess == 0) {
        return;
    }
    holder_guess->value0_guess->Slot00_guess(1);
    holder_guess->value0_guess = 0;
}

struct Command456A1E_guess {
    char name_guess[0x40];
    int kind_guess;   // 0x40
    int amount_guess; // 0x44
};

struct Values456A1E_guess {
    unsigned char padding_guess[0x11d4];
    int platinum_11d4_guess;
    int gold_11d8_guess;
    int silver_11dc_guess;
    int copper_11e0_guess;
};

struct EQ_CharacterProfileView3_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView3_guess::GetCharInfo2
    Values456A1E_guess* GetCharInfo2();
};

struct Owner456A1E_guess {
    unsigned char padding_guess[4];
    EQ_CharacterProfileView3_guess locator_guess;
};

// Owner object at root + offset + 8
static Owner456A1E_guess* Owner456A1E_guess_Get() {
    return (Owner456A1E_guess*)&g_root4569D4_guess->embedded_guess[
        g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess + 8];
}

// FUNCTION: TITANIUM 0x00456A1E
// Three server commands of one shape remove coins (type 1-4 = platinum..copper, capped at what is
// there) and echo the 0x48-byte request with the amount actually taken. This one: carried coins
// (+0x11D4), opcode 0x3E52, reply 0x2A54.
void __cdecl DeductCarriedCoins_guess(Command456A1E_guess* command_guess) {
    Command456A1E_guess message_guess;

    memset(&message_guess, 0, 0x48);
    if (g_root4569D4_guess != 0 &&
        strcmp(&g_root4569D4_guess->embedded_guess[
                   g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess + 0x44],
               command_guess->name_guess) == 0) {
        FUN_0060e450_guess(message_guess.name_guess, (const char*)command_guess);
        int amount_guess = command_guess->amount_guess;
        int kind_guess = command_guess->kind_guess;
        message_guess.kind_guess = kind_guess;
        message_guess.amount_guess = amount_guess;

        switch (kind_guess) {
        case 1: {
            Owner456A1E_guess* owner_guess = Owner456A1E_guess_Get();
            Values456A1E_guess* values_guess = owner_guess->locator_guess.GetCharInfo2();
            if (message_guess.amount_guess > values_guess->platinum_11d4_guess) {
                owner_guess = Owner456A1E_guess_Get();
                message_guess.amount_guess =
                    owner_guess->locator_guess.GetCharInfo2()->platinum_11d4_guess;
                owner_guess = Owner456A1E_guess_Get();
                owner_guess->locator_guess.GetCharInfo2()->platinum_11d4_guess = 0;
            } else {
                ((PropertyOwnerCallback_guess*)Owner456A1E_guess_Get())->Apply00_guess(
                    -message_guess.amount_guess);
            }
            break;
        }
        case 2: {
            Owner456A1E_guess* owner_guess = Owner456A1E_guess_Get();
            Values456A1E_guess* values_guess = owner_guess->locator_guess.GetCharInfo2();
            if (message_guess.amount_guess > values_guess->gold_11d8_guess) {
                owner_guess = Owner456A1E_guess_Get();
                message_guess.amount_guess =
                    owner_guess->locator_guess.GetCharInfo2()->gold_11d8_guess;
                owner_guess = Owner456A1E_guess_Get();
                owner_guess->locator_guess.GetCharInfo2()->gold_11d8_guess = 0;
            } else {
                ((PropertyOwnerCallback_guess*)Owner456A1E_guess_Get())->Apply04_guess(
                    -message_guess.amount_guess);
            }
            break;
        }
        case 3: {
            Owner456A1E_guess* owner_guess = Owner456A1E_guess_Get();
            Values456A1E_guess* values_guess = owner_guess->locator_guess.GetCharInfo2();
            if (message_guess.amount_guess > values_guess->silver_11dc_guess) {
                owner_guess = Owner456A1E_guess_Get();
                message_guess.amount_guess =
                    owner_guess->locator_guess.GetCharInfo2()->silver_11dc_guess;
                owner_guess = Owner456A1E_guess_Get();
                owner_guess->locator_guess.GetCharInfo2()->silver_11dc_guess = 0;
            } else {
                ((PropertyOwnerCallback_guess*)Owner456A1E_guess_Get())->Apply08_guess(
                    -message_guess.amount_guess);
            }
            break;
        }
        case 4: {
            Owner456A1E_guess* owner_guess = Owner456A1E_guess_Get();
            Values456A1E_guess* values_guess = owner_guess->locator_guess.GetCharInfo2();
            if (message_guess.amount_guess > values_guess->copper_11e0_guess) {
                owner_guess = Owner456A1E_guess_Get();
                message_guess.amount_guess =
                    owner_guess->locator_guess.GetCharInfo2()->copper_11e0_guess;
                owner_guess = Owner456A1E_guess_Get();
                owner_guess->locator_guess.GetCharInfo2()->copper_11e0_guess = 0;
            } else {
                ((PropertyOwnerCallback_guess*)Owner456A1E_guess_Get())->Apply0C_guess(
                    -message_guess.amount_guess);
            }
            break;
        }
        default:
            return;
        }
        EQSendMessage(g_messageBuffer_guess, 0x2a54, &message_guess, 0x48, 1);
    }
}

struct Values456CA5_guess {
    unsigned char padding_guess[0x144];
    int value144_guess;
    int value148_guess;
    int value14c_guess;
    int value150_guess;
};

// Values object at root + offset
static Values456CA5_guess* Values456CA5_Get() {
    return (Values456CA5_guess*)&g_root4569D4_guess->embedded_guess[
        g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess];
}

// FUNCTION: TITANIUM 0x00456CA5
// @early-stop: budget, structural ndiff=74
// Coins at +0x144..+0x150 (probably the bank), opcode 0x4642, reply 0x61B1.
void __cdecl FUN_00456ca5_guess(Command456A1E_guess* command_guess) {
    Command456A1E_guess message_guess;

    memset(&message_guess, 0, 0x48);
    if (g_root4569D4_guess != 0 &&
        strcmp(&g_root4569D4_guess->embedded_guess[
                   g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess + 0x44],
               command_guess->name_guess) == 0) {
        FUN_0060e450_guess(message_guess.name_guess, (const char*)command_guess);
        message_guess.kind_guess = command_guess->kind_guess;
        message_guess.amount_guess = command_guess->amount_guess;

        switch (message_guess.kind_guess) {
        case 1: {
            Values456CA5_guess* values_guess = Values456CA5_Get();
            if (message_guess.amount_guess > values_guess->value144_guess) {
                message_guess.amount_guess = values_guess->value144_guess;
                values_guess->value144_guess = 0;
            } else {
                values_guess->value144_guess -= message_guess.amount_guess;
            }
            break;
        }
        case 2: {
            Values456CA5_guess* values_guess = Values456CA5_Get();
            if (message_guess.amount_guess > values_guess->value148_guess) {
                message_guess.amount_guess = values_guess->value148_guess;
                values_guess->value148_guess = 0;
            } else {
                values_guess->value148_guess -= message_guess.amount_guess;
            }
            break;
        }
        case 3: {
            Values456CA5_guess* values_guess = Values456CA5_Get();
            if (message_guess.amount_guess > values_guess->value14c_guess) {
                message_guess.amount_guess = values_guess->value14c_guess;
                values_guess->value14c_guess = 0;
            } else {
                values_guess->value14c_guess -= message_guess.amount_guess;
            }
            break;
        }
        case 4: {
            Values456CA5_guess* values_guess = Values456CA5_Get();
            if (message_guess.amount_guess > values_guess->value150_guess) {
                message_guess.amount_guess = values_guess->value150_guess;
                values_guess->value150_guess = 0;
            } else {
                values_guess->value150_guess -= message_guess.amount_guess;
            }
            break;
        }
        default:
            return;
        }
        EQSendMessage(g_messageBuffer_guess, 0x61b1, &message_guess, 0x48, 1);
    }
}

struct Argument456FD1_guess {
    int value0_guess;
    int value4_guess;
    int value8_guess;
    unsigned char valueC_guess;
};

struct Argument456E3B_guess {
    char name_guess[0x40];
    int type_guess;
    int amount_guess;
};

struct State456E3B_guess {
    unsigned char padding00_guess[0x134];
    int value134_guess;
    int value138_guess;
    int value13C_guess;
    int value140_guess;
};

struct Message456E3B_guess {
    char name_guess[0x40];
    int type_guess;
    int amount_guess;
};

// FUNCTION: TITANIUM 0x00456E3B
// @early-stop: budget, structural ndiff=37
// Coins at +0x134..+0x140 (probably the cursor), opcode 0x7DF1, reply 0x3B0E.
void __cdecl FUN_00456e3b_guess(Argument456E3B_guess* argument_guess) {
    Message456E3B_guess message_guess;
    memset(&message_guess, 0, 0x48);

    if (g_root4569D4_guess == 0) {
        return;
    }
    if (strcmp(&g_root4569D4_guess->embedded_guess[
                   g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess + 0x44],
               argument_guess->name_guess) != 0) {
        return;
    }

    strcpy(message_guess.name_guess, argument_guess->name_guess);

    int type_guess = argument_guess->type_guess;
    int amount_guess = argument_guess->amount_guess;
    message_guess.type_guess = type_guess;
    message_guess.amount_guess = amount_guess;
    switch (type_guess) {
    case 1:
        if (amount_guess > ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value134_guess) {
            message_guess.amount_guess = ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value134_guess;
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value134_guess = 0;
        } else {
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value134_guess -= amount_guess;
        }
        break;
    case 2:
        if (amount_guess > ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value138_guess) {
            message_guess.amount_guess = ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value138_guess;
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value138_guess = 0;
        } else {
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value138_guess -= amount_guess;
        }
        break;
    case 3:
        if (amount_guess > ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value13C_guess) {
            message_guess.amount_guess = ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value13C_guess;
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value13C_guess = 0;
        } else {
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value13C_guess -= amount_guess;
        }
        break;
    case 4:
        if (amount_guess > ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value140_guess) {
            message_guess.amount_guess = ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value140_guess;
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value140_guess = 0;
        } else {
            ((State456E3B_guess*)&g_root4569D4_guess->embedded_guess[
                g_root4569D4_guess->value8_guess->vbaseOffset_0004_guess])->value140_guess -= amount_guess;
        }
        break;
    default:
        return;
    }

    EQSendMessage(g_messageBuffer_guess, 0x3B0E, &message_guess, 0x48, 1);
}

// FUNCTION: TITANIUM 0x00456FD1
// ManaChange_Struct {mana, endurance, spell id, keepcasting}. A full 0x10-byte packet with keepcasting
// clear ends the cast (spell -1 = none) and releases the pending-request counts.
void __cdecl Handle_OP_ManaChange_guess(Argument456FD1_guess* argument_guess, int type_guess) {
    if (g_propertyOwnerGlobal_guess == 0) {
        return;
    }

    ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
        g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11a8_guess(
            argument_guess->value0_guess);
    ((PropertyOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
        g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Set11ac_guess(
            argument_guess->value4_guess);

    if (g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valueF9C_guess <= 8) {
        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valuesE8_guess[
            g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valueF9C_guess] =
            g_updateSettings_guess->frameTime_0148_guess;
        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value110_guess =
            g_updateSettings_guess->frameTime_0148_guess;
    }

    if (type_guess == 0x10) {
        if (argument_guess->valueC_guess == 0) {
            CommandContext456FD1_guess* context_guess =
                &g_propertyOwnerGlobal_guess->command_guess;
            int value_guess = argument_guess->value8_guess;
            if (value_guess != -1) {
                context_guess->StopSpellCast_guess(3, value_guess);
                return;
            }
            context_guess->Handle_guess(3);
            return;
        } else {
            if (g_target4521Result_guess > 0) {
                --g_target4521Result_guess;
            } else {
                g_target4521Result_guess = 0;
            }
            if (g_target4520A1Count_guess > 0) {
                --g_target4520A1Count_guess;
            } else {
                g_target4520A1Count_guess = 0;
            }
            return;
        }
    }

    g_propertyOwnerGlobal_guess->command_guess.Handle_guess(3);
}

// FUNCTION: TITANIUM 0x004570CA
// Opcode 0x5619: copies the text at +0x80 to the player's profile +0x9C (32 bytes, probably the title).
void __cdecl FUN_004570ca_guess(Target570Argument_guess* argument_guess) {
    if (g_updateEnabled_guess == 0) {
        return;
    }

    DispatchTarget_guess* result_guess = ResolveTarget_guess(argument_guess);
    if (result_guess != 0 && argument_guess->enabledC4_guess != 0 &&
        result_guess->spawnId_0258_guess == g_propertyOwnerCurrent_guess->spawnId_0258_guess) {
        ((Target454EA9_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess + 0x9c])
            ->Copy_guess(argument_guess->text80_guess);
    }
}

// FUNCTION: TITANIUM 0x00457120
// Sets a spawn's surname; for the player also the profile copy at +0x7C.
void __cdecl Handle_OP_GMLastName_guess(Target570Argument_guess* argument_guess) {
    if (g_updateEnabled_guess == 0) {
        return;
    }

    DispatchTarget_guess* result_guess = ResolveTarget_guess(argument_guess);
    if (result_guess == 0 || argument_guess->enabledC4_guess == 0) {
        return;
    }

    strcpy(&result_guess->embedded_guess[1], argument_guess->text80_guess);
    if (result_guess->spawnId_0258_guess == g_propertyOwnerCurrent_guess->spawnId_0258_guess) {
        ((Target454EA9_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess + 0x7c])
            ->Copy_guess(argument_guess->text80_guess);
    }
    result_guess->Continue_guess();
}

// FUNCTION: TITANIUM 0x0045718F
// Surname approval: +0x40 zero is "rejected" (0x55E), else "Congratulations, %1 %2" (0x55F).
void __cdecl Handle_OP_Surname_guess(Target5718FArgument_guess* argument_guess) {
    char message_guess[0x100];
    if (argument_guess->value40_guess == 0) {
        g_errorDisplay_guess->dsp_chat(
            pStringTable->getString(0x55e, 0), 0xf, 1);
    } else {
        FormatNotice_guess(
            message_guess, 0x55f,
            (const char*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess + 0x3c],
            argument_guess->name44_guess, 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0xf, 1);
    }
}

struct PropertyData57210_guess {
    unsigned char padding_guess[0x1218];
    int thirst_1218_guess;
    int hunger_121c_guess;
};

struct EQ_CharacterProfileView4_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView4_guess::GetCharInfo2
    PropertyData57210_guess* GetCharInfo2();
};

struct PropertyOwner57210_guess {
    unsigned char padding_guess[4];
    EQ_CharacterProfileView4_guess locator_guess;

    // EXTERNAL: TITANIUM 0x00417D9A PropertyOwner57210_guess::UpdateFirst_guess
    void UpdateFirst_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00417D85 PropertyOwner57210_guess::UpdateSecond_guess
    void UpdateSecond_guess(int value_guess);
};

struct PropertyOwnerOffset57210_guess {
    unsigned char padding_guess[4];
    int vbaseOffset_0004_guess;
};

struct UpdateRoot57210_guess {
    unsigned char padding_guess[8];
    union {
        PropertyOwnerOffset57210_guess* ownerOffset_guess;
        unsigned char ownerRegion_guess[1];
    };
};

#define g_updateRoot57210_guess EQ_GLOBAL(UpdateRoot57210_guess*, 0x00905D00)

// FUNCTION: TITANIUM 0x00457210
// Stamina_Struct {food, water}, each clamped to 0..32000 (0x7D00).
void __cdecl Handle_OP_Stamina_guess(int* values_guess) {
    if (g_updateRoot57210_guess != 0) {
        ((PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
            g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess])
            ->UpdateFirst_guess(values_guess[0]);
        ((PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
            g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess])
            ->UpdateSecond_guess(values_guess[1]);
        if (values_guess[0] > 0x7d00) {
            PropertyOwner57210_guess* owner_guess =
                (PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
                    g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess];
            owner_guess->locator_guess.GetCharInfo2()->hunger_121c_guess = 0x7d00;
        }
        if (values_guess[1] > 0x7d00) {
            PropertyOwner57210_guess* owner_guess =
                (PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
                    g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess];
            owner_guess->locator_guess.GetCharInfo2()->thirst_1218_guess = 0x7d00;
        }
        if (values_guess[0] < 0) {
            PropertyOwner57210_guess* owner_guess =
                (PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
                    g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess];
            owner_guess->locator_guess.GetCharInfo2()->hunger_121c_guess = 0;
        }
        if (values_guess[1] < 0) {
            PropertyOwner57210_guess* owner_guess =
                (PropertyOwner57210_guess*)&g_updateRoot57210_guess->ownerRegion_guess[
                    g_updateRoot57210_guess->ownerOffset_guess->vbaseOffset_0004_guess];
            owner_guess->locator_guess.GetCharInfo2()->thirst_1218_guess = 0;
        }
    }
}

struct Report4572DD_guess {
    int padding0_guess;
    int textId4_guess;
    char text8_guess[0x20];
    int type28_guess;
    int value2c_guess;
    int value30_guess;
    int value34_guess;
    int value38_guess;
    int count3c_guess;
    char data40_guess[1];
};

struct Skills4572DD_guess {
    // EXTERNAL: TITANIUM 0x004195B8 Skills4572DD_guess::GetName_guess
    const char* GetName_guess(int id_guess);

    // EXTERNAL: TITANIUM 0x0041BF2B Skills4572DD_guess::Describe_guess
    char* Describe_guess(int a_guess, int b_guess, int c_guess);
};

struct CharData4572DD_guess {
    unsigned char padding0_guess[0xc280];
    Skills4572DD_guess skills_guess;

    // EXTERNAL: TITANIUM 0x004BB181 CharData4572DD_guess::IsPlayerRace_guess
    bool IsPlayerRace_guess(int id_guess);
};

struct ZoneNames4572DD_guess {
    // EXTERNAL: TITANIUM 0x005F6ED0 ZoneNames4572DD_guess::GetName_guess
    void GetName_guess(int zone_guess, char* name_guess);

    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneNames4572DD_guess::GetLongName_guess
    void GetLongName_guess(int zone_guess, char* name_guess, int flag_guess);
};

#define g_charData4572DD_guess EQ_GLOBAL(CharData4572DD_guess*, 0x00905D00)
#define g_zoneNames4572DD_guess EQ_GLOBAL(ZoneNames4572DD_guess*, 0x00905CC0)
#define g_zoneMode4572DD_guess EQ_GLOBAL(int, 0x00923D74)

// EXTERNAL: TITANIUM 0x00576FA0 CopyBounded4572DD_guess
void __cdecl CopyBounded4572DD_guess(char* destination_guess, const char* source_guess,
                                     int size_guess);

// EXTERNAL: TITANIUM 0x00622113 _ltoa
extern "C" char* __cdecl _ltoa(long value_guess, char* destination_guess, int radix_guess);

// Prints a /who reply (OP_WhoAllResponse, 0x757B, from the dispatcher) on chat channel 0x119: an optional
// header, one line per row, then the totals line.
// FUNCTION: TITANIUM 0x004572DD
// @early-stop: budget, diff ndiff=147
// /who all results. Each entry starts with a string id: 0x13A2/0x13A3 "ZONE: %1 is UP / isn't ready",
// 0x139E/0x13A1 anonymous-roleplay / normal line, 0x139F/0x13A0 anonymous; the trailer id at +0x28
// (0x13A4-0x13AC) is the "There are %1 players" summary. Text goes out in color 0x119.
void __cdecl Handle_OP_WhoAllResponse_guess(Report4572DD_guess* report_guess) {
    int offset_guess = 0;
    if (report_guess->textId4_guess != -1) {
        pEverQuest->dsp_chat(pStringTable->getString(report_guess->textId4_guess, 0), 0x119, 1);
        pEverQuest->dsp_chat(report_guess->text8_guess, 0x119, 1);
    }
    for (int i_guess = 0; i_guess < report_guess->count3c_guess; i_guess++) {
        char message_guess[1024] = "";
        int type_guess;
        memcpy(&type_guess, &report_guess->data40_guess[offset_guess], 4);
        offset_guess += 4;
        // Each row starts with its string id. 5026/5027 are zone-server rows (the zone is up or not ready);
        // the others are player rows read field by field from the packed data.
        if (type_guess == 0x13a2 || type_guess == 0x13a3) {
            int zone_guess;
            memcpy(&zone_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            char zoneName_guess[120] = "";
            g_zoneNames4572DD_guess->GetName_guess(zone_guess, zoneName_guess);
            FormatStringWithParameters_guess(message_guess, type_guess, (int)zoneName_guess, 0, 0, 0, 0, 0, 0,
                               0, 0);
        } else {
            char name_guess[64] = "";
            char target_guess[64] = "";
            char item_guess[64] = "";
            char skill_guess[256] = "";
            char number_guess[100] = "";
            const char* text_guess = "";
            int reasonId_guess;
            int number878_guess;
            long value8a8_guess;
            int textId_guess;
            int zoneTextId_guess;
            int zone_guess;
            int a89c_guess;
            int b890_guess;
            int skillId_guess;
            int c8a0_guess;
            memcpy(&reasonId_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            char* string_guess = &report_guess->data40_guess[offset_guess];
            size_t length_guess = strlen(string_guess);
            strcpy(name_guess, string_guess);
            offset_guess += length_guess + 1;
            memcpy(&number878_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            string_guess = &report_guess->data40_guess[offset_guess];
            length_guess = strlen(string_guess);
            strcpy(target_guess, string_guess);
            offset_guess += length_guess + 1;
            memcpy(&value8a8_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&textId_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&zoneTextId_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&zone_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&a89c_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&b890_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            memcpy(&skillId_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            string_guess = &report_guess->data40_guess[offset_guess];
            length_guess = strlen(string_guess);
            strcpy(item_guess, string_guess);
            offset_guess += length_guess + 1;
            memcpy(&c8a0_guess, &report_guess->data40_guess[offset_guess], 4);
            offset_guess += 4;
            if (textId_guess != -1) {
                text_guess = pStringTable->getString(textId_guess, 0);
            }
            CopyBounded4572DD_guess(
                skill_guess,
                g_charData4572DD_guess->IsPlayerRace_guess(skillId_guess)
                    ? g_charData4572DD_guess->skills_guess.GetName_guess(skillId_guess)
                    : g_noticeSource4546E2_guess->GetRaceDesc(skillId_guess),
                0x100);
            switch (type_guess) {
            // 5022 and 5025 are the full player rows (5022 for a roleplaying player), 5023 and 5024 the
            // anonymous ones.
            case 0x139e:
            case 0x13a1: {
                char reason_guess[120] = "";
                char zoneText_guess[120] = "";
                char count_guess[5] = "";
                char zoneName_guess[120] = "";
                if (reasonId_guess != -1) {
                    if (reasonId_guess == 0x138b) {
                        char value_guess[50] = "";
                        _ltoa(value8a8_guess, value_guess, 10);
                        FormatStringWithParameters_guess(reason_guess, reasonId_guess, (int)value_guess,
                                           (int)item_guess, 0, 0, 0, 0, 0, 0, 0);
                    } else if (reasonId_guess == 0x138c) {
                        FormatStringWithParameters_guess(reason_guess, 0x138c, (int)item_guess, 0, 0, 0, 0, 0,
                                           0, 0, 0);
                    }
                }
                if (number878_guess != -1) {
                    _itoa(number878_guess, number_guess, 10);
                }
                if (zoneTextId_guess != -1) {
                    if (g_zoneMode4572DD_guess == 1) {
                        g_zoneNames4572DD_guess->GetLongName_guess(zone_guess, zoneName_guess, 1);
                    } else {
                        g_zoneNames4572DD_guess->GetName_guess(zone_guess, zoneName_guess);
                    }
                    FormatStringWithParameters_guess(zoneText_guess, zoneTextId_guess, (int)zoneName_guess, 0,
                                       0, 0, 0, 0, 0, 0, 0);
                }
                _itoa(b890_guess, count_guess, 10);
                if (type_guess == 0x139e) {
                    FormatStringWithParameters_guess(message_guess, type_guess, (int)number_guess,
                                       (int)count_guess,
                                       (int)g_charData4572DD_guess->skills_guess.Describe_guess(
                                           a89c_guess, b890_guess, c8a0_guess),
                                       (int)name_guess, (int)skill_guess, (int)zoneText_guess,
                                       (int)reason_guess, (int)text_guess, 0);
                } else {
                    FormatStringWithParameters_guess(message_guess, type_guess, (int)number_guess,
                                       (int)count_guess,
                                       (int)g_charData4572DD_guess->skills_guess.Describe_guess(
                                           a89c_guess, b890_guess, c8a0_guess),
                                       (int)name_guess, (int)skill_guess, (int)target_guess,
                                       (int)zoneText_guess, (int)reason_guess, (int)text_guess);
                }
                break;
            }
            case 0x139f:
                if (number878_guess != -1) {
                    _itoa(number878_guess, number_guess, 10);
                }
                FormatStringWithParameters_guess(message_guess, type_guess, (int)number_guess,
                                   (int)name_guess, (int)target_guess, (int)text_guess, 0, 0, 0,
                                   0, 0);
                break;
            case 0x13a0:
                if (number878_guess != -1) {
                    _itoa(number878_guess, number_guess, 10);
                }
                FormatStringWithParameters_guess(message_guess, type_guess, (int)number_guess,
                                   (int)name_guess, (int)text_guess, 0, 0, 0, 0, 0, 0);
                break;
            }
        }
        pEverQuest->dsp_chat(message_guess, 0x119, 1);
    }
    // Totals line by string id: player counts (5028-5032, 5036), the cut-short notice (5033) and the
    // zone-server counts (5034, 5035).
    if (report_guess->type28_guess != -1) {
    char text_guess[256];
    char value34_guess[12];
    char value38_guess[12];
    char value2c_guess[12];
    char value30_guess[12];
    switch (report_guess->type28_guess) {
    case 0x13a4:
    case 0x13aa:
    case 0x13ab:
    case 0x13ac:
        _itoa(report_guess->value34_guess, value34_guess, 10);
        FormatStringWithParameters_guess(text_guess, report_guess->type28_guess, (int)value34_guess, 0, 0, 0,
                           0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(text_guess, 0x119, 1);
        break;
    case 0x13a5:
    case 0x13a9:
        pEverQuest->dsp_chat(pStringTable->getString(report_guess->type28_guess, 0), 0x119, 1);
        break;
    case 0x13a6:
        _itoa(report_guess->value34_guess, value34_guess, 10);
        _itoa(report_guess->value38_guess, value38_guess, 10);
        _itoa(report_guess->value30_guess, value30_guess, 10);
        FormatStringWithParameters_guess(text_guess, report_guess->type28_guess, (int)value38_guess,
                           (int)value34_guess, (int)value30_guess, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(text_guess, 0x119, 1);
        break;
    case 0x13a7:
        _itoa(report_guess->value34_guess, value34_guess, 10);
        _itoa(report_guess->value38_guess, value38_guess, 10);
        _itoa(report_guess->value2c_guess, value2c_guess, 10);
        FormatStringWithParameters_guess(text_guess, report_guess->type28_guess, (int)value38_guess,
                           (int)value34_guess, (int)value2c_guess, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(text_guess, 0x119, 1);
        break;
    case 0x13a8:
        _itoa(report_guess->value34_guess, value34_guess, 10);
        _itoa(report_guess->value38_guess, value38_guess, 10);
        _itoa(report_guess->value2c_guess, value2c_guess, 10);
        _itoa(report_guess->value30_guess, value30_guess, 10);
        FormatStringWithParameters_guess(text_guess, report_guess->type28_guess, (int)value38_guess,
                           (int)value34_guess, (int)value30_guess, (int)value2c_guess, 0, 0, 0,
                           0, 0);
        pEverQuest->dsp_chat(text_guess, 0x119, 1);
        break;
    }
    }
}

// FUNCTION: TITANIUM 0x00457A91
// Opcode 0x224D: adds coins of type 0-3 = copper, silver, gold, platinum.
void __cdecl AddCoinsByType_guess(ApplyRequest457A91_guess* request_guess) {
    if (request_guess != 0 && g_propertyOwnerGlobal_guess != 0) {
        switch (request_guess->type4_guess) {
        case 0:
            ((PropertyOwnerCallback_guess*)(
                (char*)g_propertyOwnerGlobal_guess->embedded_guess +
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess))
                ->Apply0C_guess(request_guess->value8_guess);
            break;
        case 1:
            ((PropertyOwnerCallback_guess*)(
                (char*)g_propertyOwnerGlobal_guess->embedded_guess +
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess))
                ->Apply08_guess(request_guess->value8_guess);
            break;
        case 2:
            ((PropertyOwnerCallback_guess*)(
                (char*)g_propertyOwnerGlobal_guess->embedded_guess +
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess))
                ->Apply04_guess(request_guess->value8_guess);
            break;
        case 3:
            ((PropertyOwnerCallback_guess*)(
                (char*)g_propertyOwnerGlobal_guess->embedded_guess +
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess))
                ->Apply00_guess(request_guess->value8_guess);
            break;
        }
        g_propertyOwnerState457A91_guess->valueC28C_guess = 1;
    }
}

struct Packet457B0F_guess {
    int value0_guess;
    int value4_guess;
    char strings_guess[22][0x40];
    int values_guess[22];
    char message_guess[0x100];
    char name_guess[0x20];
};

struct Argument457B0F_guess {
    unsigned char padding00_guess[4];
    int value4_guess;
};

struct TextOffset457B0F_guess {
    unsigned char padding00_guess[4];
    int vbaseOffset_0004_guess;
};

struct TextRoot457B0F_guess {
    unsigned char padding00_guess[8];
    TextOffset457B0F_guess* offsetSource_guess;
    unsigned char padding0C_guess[0xA4 - 0x0C];
    char textA4_guess[1];
};

struct UpdateClock457B0F_guess {
    unsigned char padding00_guess[0x148];
    unsigned int value148_guess;
};

#define g_lastUpdate457B0F_guess EQ_GLOBAL(unsigned int, 0x0098580C)
#define g_updateClock457B0F_guess EQ_GLOBAL(UpdateClock457B0F_guess*, 0x00905D24)
#define g_textRoot457B0F_guess EQ_GLOBAL(TextRoot457B0F_guess*, 0x00905D00)
#define g_updateFlag457B0F_guess EQ_GLOBAL(int, 0x009247C4)

// FUNCTION: TITANIUM 0x00457B0F
// Answers an inspect at most once a second: OP_InspectAnswer (0x2403, 0x700 bytes) with 22 empty item
// slots, the inspect message (0x00985708) and the player's name. 0x57C says who is looking.
void __cdecl Handle_OP_InspectRequest_guess(Argument457B0F_guess* argument_guess) {
    int index_guess;
    char message_guess[0x200];
    Packet457B0F_guess packet_guess;

    memset(&packet_guess, 0, 0x700);
    unsigned int now_guess = g_updateClock457B0F_guess->value148_guess;
    if (g_lastUpdate457B0F_guess + 1000 <= now_guess) {
        g_lastUpdate457B0F_guess = now_guess;
        packet_guess.value0_guess = argument_guess->value4_guess;
        packet_guess.value4_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
        strcpy(packet_guess.message_guess, EQ_ARRAY(char, 0x0063F53F));
        strcpy(packet_guess.message_guess, EQ_ARRAY(char, 0x00985708));
        strcpy(packet_guess.name_guess,
               &g_textRoot457B0F_guess->textA4_guess[
                   g_textRoot457B0F_guess->offsetSource_guess->vbaseOffset_0004_guess]);
        index_guess = 0;
        do {
            strcpy(packet_guess.strings_guess[index_guess], EQ_ARRAY(char, 0x0063F53F));
            packet_guess.values_guess[index_guess] = -1;
            ++index_guess;
        } while (index_guess < 22);

        DispatchTarget_guess* target_guess =
            ResolveDispatch_guess(argument_guess->value4_guess);
        if (target_guess != 0 && target_guess != g_propertyOwnerCurrent_guess &&
            g_updateFlag457B0F_guess == 1) {
            FormatNotice_guess(message_guess, 0x57C, target_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            g_errorDisplay_guess->dsp_chat(message_guess, 0x111, 1);
        }
        EQSendMessage(g_messageBuffer_guess, OP_InspectAnswer, &packet_guess, 0x700, 1);
    }
}

// FUNCTION: TITANIUM 0x00457C7F
// {copper, silver, gold, platinum}: "You receive %1 copper ..." per nonzero coin, added to the purse.
void __cdecl Handle_OP_CashReward_guess(int* values_guess) {
    int value0_guess = *values_guess++;
    int value1_guess = *values_guess++;
    int value2_guess = *values_guess++;
    int value3_guess = *values_guess;
    char message_guess[0x200];
    char digits_guess[0x20];

    if (value0_guess > 0) {
        FormatNotice_guess(message_guess, 0x59e,
                           _itoa(value0_guess, digits_guess, 10),
                           EQ_ARRAY(char, 0x0063F53F), 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x111, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply0C_guess(value0_guess);
    }
    if (value1_guess > 0) {
        FormatNotice_guess(message_guess, 0x5a0,
                           _itoa(value1_guess, digits_guess, 10),
                           EQ_ARRAY(char, 0x0063F53F), 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x111, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply08_guess(value1_guess);
    }
    if (value2_guess > 0) {
        FormatNotice_guess(message_guess, 0x5a1,
                           _itoa(value2_guess, digits_guess, 10),
                           EQ_ARRAY(char, 0x0063F53F), 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x111, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply04_guess(value2_guess);
    }
    if (value3_guess > 0) {
        FormatNotice_guess(message_guess, 0x5a2,
                           _itoa(value3_guess, digits_guess, 10),
                           EQ_ARRAY(char, 0x0063F53F), 0, 0, 0, 0, 0, 0, 0);
        g_errorDisplay_guess->dsp_chat(message_guess, 0x111, 1);
        ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->Apply00_guess(value3_guess);
    }
}

struct UpdateState457E57_guess {
    unsigned char padding_guess[0x1B8];
    unsigned char value1B8_guess;
};

struct UpdateTarget457E57_guess {
    unsigned char padding1A8_guess[0x1A8];
    UpdateState457E57_guess* pActorInfo_01a8_guess;
    unsigned char padding1AC_guess[0x244 - 0x1AC];
    unsigned char type_0244_guess;
    unsigned char padding245_guess[0x274 - 0x245];
    int hpCurrent_0274_guess;
    unsigned char padding278_guess[0x284 - 0x278];
    int hpMax_0284_guess;

    // EXTERNAL: TITANIUM 0x0047D776 UpdateTarget457E57_guess::Continue_guess
    void Continue_guess();
};

struct UpdateService457E57_guess {
    // EXTERNAL: TITANIUM 0x004B44C6 UpdateService457E57_guess::CanUseAbility_guess
    char CanUseAbility_guess(void* value_guess, int first_guess, int second_guess);
};

#define g_updateService457E57_guess EQ_GLOBAL(UpdateService457E57_guess*, 0x009859EC)

// FUNCTION: TITANIUM 0x00457E57
// HP update {id, current, max} (OP_HPUpdate, OP_MobHealth, OP_InitialMobHealth, 0x217B): exact for the
// player, a percent for others (current * 100 / max, at least 1 when alive; corpses floor at -126).
void __cdecl UpdateSpawnHitPoints_guess(int operation_guess, int value_guess, int divisor_guess,
                                char flag_guess) {
    UpdateTarget457E57_guess* target_guess =
        (UpdateTarget457E57_guess*)ResolveDispatch_guess(operation_guess);
    if (target_guess == 0) {
        return;
    }

    if (flag_guess != 0) {
        target_guess->pActorInfo_01a8_guess->value1B8_guess = 1;
    }

    if ((DispatchTarget_guess*)target_guess == g_propertyOwnerCurrent_guess) {
        target_guess->hpCurrent_0274_guess = value_guess;
        if (g_propertyOwnerGlobal_guess != 0) {
            ((PropertyOwnerCallback_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->Update_guess(value_guess);
        }
    } else {
        if (target_guess->type_0244_guess == 1 && value_guess <= 0x64 &&
            divisor_guess == 100) {
            target_guess->hpCurrent_0274_guess = value_guess;
            if (g_updateService457E57_guess != 0 &&
                g_updateService457E57_guess->CanUseAbility_guess(
                    g_propertyOwnerGlobal_guess, 1, 1) != 0) {
                target_guess->Continue_guess();
            }
        } else if (value_guess <= 0) {
            if (value_guess < -0x7e) {
                target_guess->hpCurrent_0274_guess = -0x7e;
            } else {
                target_guess->hpCurrent_0274_guess = value_guess;
            }
        } else {
            target_guess->hpCurrent_0274_guess = value_guess * 100 / divisor_guess;
            if (target_guess->hpCurrent_0274_guess <= 0) {
                target_guess->hpCurrent_0274_guess = 1;
            }
        }
        target_guess->hpMax_0284_guess = 100;
    }
}

struct PlayerName4581B7_guess {
    char text_guess[0x40];
};

struct PlayerNotice4581B7_guess {
    int property_guess;
    int spawnId_0004_guess;
};

struct EverQuestPlayerState4581B7_guess {
    // EXTERNAL: TITANIUM 0x00491853 EverQuestPlayerState4581B7_guess::CloseBankWnd_guess
    void CloseBankWnd_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00491845 EverQuestPlayerState4581B7_guess::CloseTrainWindow_guess
    void CloseTrainWindow_guess();
};

struct PopupManager4581B7_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A PopupManager4581B7_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x0049994C PopupManager4581B7_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value_guess);
};

#define g_playerState4581B7_guess EQ_GLOBAL(EverQuestPlayerState4581B7_guess*, 0x00988DF0)
#define g_popupManager4581B7_guess EQ_GLOBAL(PopupManager4581B7_guess, 0x00923770)
#define g_spawn905CE0_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905CE0)
#define g_spawn905D10_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D10)
#define g_spawn905D14_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D14)
#define g_spawn905D18_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D18)
#define g_spawn905D1C_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D1C)
#define g_spawn905D04_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00905D04)
#define g_spawn923CD4_guess EQ_GLOBAL(DispatchTarget_guess*, 0x00923CD4)
#define g_value923CC4_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_targetNames4581B7_guess EQ_ARRAY(PlayerName4581B7_guess, 0x0090424D)
#define g_targetNamesEnd4581B7_guess EQ_ARRAY(PlayerName4581B7_guess, 0x0090438D)
#define g_targetRecords4581B7_guess EQ_ARRAY(DispatchTarget_guess*, 0x00904390)

struct Root457F32_guess {
    // EXTERNAL: TITANIUM 0x004B9111 Root457F32_guess::UpdateZoneEnvironment_guess
    void UpdateZoneEnvironment_guess();
};

#define g_root457F32_guess EQ_GLOBAL(Root457F32_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x00574110 LogFormat457F32_guess
void __cdecl LogFormat457F32_guess(const char* format_guess, ...);

// FUNCTION: TITANIUM 0x00457F32
// The player's own Spawn_Struct when entering the zone; any size but 0x181 disconnects. Sets up the
// local player like Handle_OP_NewSpawn_guess and logs that it arrived.
char __cdecl Handle_OP_ZoneEntry_guess(char* data_guess, int size_guess) {
    PlayerSource4554E5_guess* source_guess = (PlayerSource4554E5_guess*)data_guess;
    if (size_guess != 0x181) {
        LogDataFileError_guess("ERROR: Corrupt addplayer, disconnecting.\n");
        g_target4520E5Data_guess->value39400_guess = 1;
        g_target4520E5Data_guess->SetGameState(0xFF);
        EQ_GLOBAL(int, 0x00923794) = 0xFD;
        g_target4520E5Data_guess->valueB50_guess = 1;
        g_target4520E5Message_guess->Send_guess(g_messageBuffer_guess);
        LogDataFileError_guess("ERROR: in receive add player, LEN failure.\n");
        return 0;
    }

    EQPlayer4554E5_guess* found_guess = 0;
    if (g_playerHead4554E5_guess != 0 &&
        (found_guess = (EQPlayer4554E5_guess*)ResolveDispatch_guess(source_guess->spawnId_0154_guess)) != 0) {
        LogFormat457F32_guess("ERROR: in receive add player, player (%s) already exists.\n",
                              found_guess->name120_guess);
        return 0;
    }

    EQPlayer4554E5_guess* player_guess = new EQPlayer4554E5_guess(source_guess, 0, 0, 0, 0);
    if (player_guess == 0) {
        g_everQuest4554E5_guess->valueB50_guess = 1;
        LogDataFileError_guess("ERROR: in receive zone info, couldn't create new player. (MEM1)\n");
        return 0;
    }

    if (player_guess->pActorInfo_guess != 0 && player_guess->pActorInfo_guess->value00_guess != 0) {
        if (12000u < (unsigned int)(g_updateSettings_guess->frameTime_0148_guess -
                                    player_guess->pActorInfo_guess->valueEbc_guess)) {
            player_guess->FUN_0048a6f2_guess();
        }
        player_guess->FUN_0048a945_guess();
        player_guess->pActorInfo_guess->valueEbc_guess = g_updateSettings_guess->frameTime_0148_guess;
    }

    if (player_guess->type244_guess == 0 && EQ_GLOBAL(unsigned char, 0x009043A4) != 0) {
        size_guess = (int)EQ_ARRAY(EQPlayer4554E5_guess*, 0x00904390);
        char* name_guess = EQ_ARRAY(char, 0x0090424D);
        do {
            if (*name_guess != 0 && strcmp(name_guess, player_guess->name120_guess) == 0) {
                *(EQPlayer4554E5_guess**)size_guess = player_guess;
            }
            size_guess += 4;
            name_guess += 0x40;
        } while ((int)name_guess < (int)EQ_ARRAY(char, 0x0090438D));
    }

    int ok_guess = 1;
    if (g_charView4554E5_guess != 0 &&
        strcmp(g_charView4554E5_guess->name03C_guess, player_guess->name120_guess) == 0) {
        g_currentPlayer4554E5_guess = player_guess;
        player_guess->standState251_guess = 100;
        g_charView4554E5_guess->value104_guess = 100;
        g_cachedPlayer4554E5_guess = g_currentPlayer4554E5_guess;
        g_cachedIndex4554E5_guess = 0;
        g_updateSettings_guess->SetViewActor_guess(player_guess->pActorInfo_guess->value00_guess);
        g_loaded4554E5_guess = 1;
        LogFormat457F32_guess("Received our EQPlayer from zone. MSG_EQ_NETPLAYERBUFF is next.");
        char zone_guess[0x80];
        g_zoneNames456110_guess->GetLongName_guess(g_propertyOwnerCurrent_guess->value204_guess,
                                                   zone_guess, 1);
        g_root457F32_guess->UpdateZoneEnvironment_guess();
        LogFormat457F32_guess("Player = %s, zone = %s", g_currentPlayer4554E5_guess->name120_guess,
                              zone_guess);
    }
    return (char)ok_guess;
}

// FUNCTION: TITANIUM 0x004581B7
// Removes a spawn and every reference to it: the duel partner (0x580/0x581, OP_DuelDecline 0x3BAD), the
// trade partner (0x00905CE0), group slots, merchant (0x00905D10), loot corpse (0x00905D18), trainer
// (0x00905D1C), the target. Marker races 0x8CD-0x8D2 get a debug line. Never deletes the player.
char __cdecl Handle_OP_DeleteSpawn_guess(int* operation_guess) {
    PlayerNotice4581B7_guess notice_guess;
    char message_guess[512];

    DispatchTarget_guess* player_guess = ResolveDispatch_guess(*operation_guess);
    if (player_guess == 0) {
        return 1;
    }

    if (player_guess->spawnId_0258_guess == g_previousProperty_guess) {
        if (g_propertyNoticeMode_guess != 0) {
            FormatNotice_guess(message_guess, 0x580,
                               g_propertyOwnerCurrent_guess->name_0120_guess,
                               player_guess->name_0120_guess,
                               player_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0x10d, 1);
            notice_guess.property_guess = player_guess->spawnId_0258_guess;
            notice_guess.spawnId_0004_guess = g_propertyOwnerCurrent_guess->spawnId_0258_guess;
            EQSendMessage(g_messageBuffer_guess, OP_DuelDecline, &notice_guess, 8, 1);
        } else {
            FormatNotice_guess(message_guess, 0x581, player_guess->name_0120_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0xf, 1);
        }
        g_propertyNoticeMode_guess = 0;
        g_previousProperty_guess = 0;
        g_lastProperty_guess = 0;
    }

    if (g_spawn905CE0_guess != 0 && g_spawn905CE0_guess == player_guess) {
        g_globalController_guess->Deactivate_guess();
    }

    if (EQ_GLOBAL(unsigned char, 0x009043A4) != 0) {
        DispatchTarget_guess** record_guess = g_targetRecords4581B7_guess;
        PlayerName4581B7_guess* name_guess = g_targetNames4581B7_guess;
        do {
            if (name_guess->text_guess[0] != 0 && *record_guess != 0 &&
                *record_guess == player_guess) {
                *record_guess = 0;
            }
            ++name_guess;
            ++record_guess;
        } while ((int)name_guess < (int)g_targetNamesEnd4581B7_guess);
    }

    if (player_guess == g_spawn905D10_guess) {
        g_target4521Dispatch_guess->Slot88_guess();
    }
    if (player_guess == g_spawn905D14_guess) {
        g_playerState4581B7_guess->CloseBankWnd_guess(0);
    }
    if (player_guess == g_spawn905D18_guess) {
        g_notifyReceiver_guess->FinishLoot_guess();
    }
    if (player_guess == g_spawn905D1C_guess) {
        g_playerState4581B7_guess->CloseTrainWindow_guess();
    }

    if (g_value923CC4_guess != -1 && g_spawn923CD4_guess == player_guess) {
        g_value923CC4_guess = -1;
        g_spawn923CD4_guess = 0;
        pEverQuest->dsp_chat(pStringTable->getString(0x2f46, 0));
    }

    if (player_guess == g_spawn905D04_guess) {
        g_popupManager4581B7_guess.SetAutoAttack_guess(0);
        g_popupManager4581B7_guess.SetAutoFire_guess(0);
        g_spawn905D04_guess = 0;
    }

    if (player_guess == g_propertyOwnerCurrent_guess) {
        return 1;
    }

    if (g_updateSettings_guess->GetValue2cf8_guess() != 0) {
        if (player_guess->race_0260_guess == 0x8cd) {
            sprintf(message_guess, "%s ppoint has been deleted.",
                    player_guess->name_0120_guess);
            pEverQuest->dsp_chat(message_guess);
        } else if (player_guess->race_0260_guess >= 0x8ce) {
            sprintf(message_guess, "%s zonecmd has been deleted.",
                    player_guess->name_0120_guess);
            pEverQuest->dsp_chat(message_guess);
        }
        if (player_guess->race_0260_guess == 0x8d2) {
            sprintf(message_guess, "%s emitter has been deleted.",
                    player_guess->name_0120_guess);
            pEverQuest->dsp_chat(message_guess);
        }
    }

    player_guess->FUN_004849b2_guess();
    free(player_guess);
    return 1;
}

// EXTERNAL: TITANIUM 0x00473CC3 ConvertNameToLocal_guess
void __cdecl ConvertNameToLocal_guess(char* text_guess);

// FUNCTION: TITANIUM 0x00458466
// FormattedMessage {unknown, string id, color, then nine NUL-separated %1..%9 arguments}. A missing id
// prints a missing-string error naming the world server (word 0 == 1) or the zone server.
void __cdecl Handle_OP_FormattedMessage_guess(char* packet_guess) {
    int stride_guess = 4;
    int server_guess;
    unsigned length_guess;
    int category_guess;
    char strings_guess[9][0x800];
    char* sourceTable_guess[9];
    char* formatTable_guess[9];
    char output_guess[1024];
    char* source_guess = packet_guess;

    memcpy(&server_guess, source_guess, stride_guess);
    source_guess += stride_guess;
    memcpy(&packet_guess, source_guess, stride_guess);
    source_guess += stride_guess;
    memcpy(&category_guess, source_guess, stride_guess);

    char* text_guess = source_guess + stride_guess;
    for (int index_guess = 0; index_guess < 9; ++index_guess) {
        char* slot_guess = strings_guess[index_guess];
        length_guess = strlen(text_guess);
        strcpy(slot_guess, text_guess);
        sourceTable_guess[index_guess] = slot_guess;
        text_guess += length_guess + 1;
        ConvertNameToLocal_guess(slot_guess);
        formatTable_guess[index_guess] = slot_guess;
    }

    char* result_guess = g_catalog452D85_guess->getString((int)packet_guess, 0);
    if (result_guess != 0) {
        FormatText453962_guess(output_guess, result_guess, formatTable_guess, -1, 0);
    } else if (server_guess == 1) {
        sprintf(output_guess, "* Error: Can't find string #%d from worldserver.",
                (int)packet_guess);
    } else {
        sprintf(output_guess, "* Error: Can't find string #%d from zone server.",
                (int)packet_guess);
    }

    pEverQuest->dsp_chat(output_guess, category_guess, 1);
    NotifyFactionStringEvent_guess((int)packet_guess, (int)formatTable_guess);
}

struct Argument45858E_guess {
    int value0_guess;
    int value4_guess;
    int value8_guess;
};

// FUNCTION: TITANIUM 0x0045858E
// SimpleMessage {string id, color, unknown}: prints string `id`. Its error text spells the world server
// as two words where Handle_OP_FormattedMessage_guess uses one; both are original.
void __cdecl Handle_OP_SimpleMessage_guess(Argument45858E_guess* argument_guess) {
    char buffer_guess[1024];

    char* result_guess = g_catalog452D85_guess->getString(argument_guess->value0_guess, 0);
    if (result_guess != 0) {
        strcpy(buffer_guess, result_guess);
    } else {
        if (argument_guess->value8_guess == 1) {
            sprintf(buffer_guess, "* Error: Can't find string #%d from world server.",
                    argument_guess->value0_guess);
        } else {
            sprintf(buffer_guess, "* Error: Can't find string #%d from zone server.",
                    argument_guess->value0_guess);
        }
    }
    pEverQuest->dsp_chat(buffer_guess, argument_guess->value4_guess, 1);
    NotifyFactionStringEvent_guess(argument_guess->value0_guess, 0);
}

// FUNCTION: TITANIUM 0x00458617
// Bounds-checked array setters on pCharData's profile: an index past the end hits __debugbreak (the
// original's assert). +0x730 is the spellbook (512 slots, Handle_SpellBookUpdate_guess), +0xF30 the
// memorized gems (16, -1 = empty; Handle_OP_MemorizeSpell_guess).
// Spellbook slot.
void IndexedValues_guess::Set730_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 0x200) {
        __debugbreak();
    }
    values730_guess[index_guess] = value_guess;
}

// FUNCTION: TITANIUM 0x00458631
// Memorized spell gem.
void IndexedValues_guess::SetF30_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 0x10) {
        __debugbreak();
    }
    valuesF30_guess[index_guess] = value_guess;
}

// Copies the six dwords (0x00458649), then the seventh (+0x18).
// FUNCTION: TITANIUM 0x00458672
void SevenWords_guess::CopyFrom_guess(const SevenWords_guess* source_guess) {
    CopyBase_guess(source_guess);
    word18_guess = source_guess->word18_guess;
}

// FUNCTION: TITANIUM 0x0045868B
// Spellbook slot, through the profile locator.
void IndexedOwner_guess::Set730_guess(unsigned index_guess, unsigned value_guess) {
    lookup_guess.GetCharInfo2()->Set730_guess(index_guess, value_guess);
}

// FUNCTION: TITANIUM 0x004586A5
// Spell gem, through the profile locator.
void IndexedOwner_guess::SetF30_guess(unsigned index_guess, unsigned value_guess) {
    lookup_guess.GetCharInfo2()->SetF30_guess(index_guess, value_guess);
}

// Copies six dwords.
// FUNCTION: TITANIUM 0x00458649
void SixWords_guess::CopyFrom_guess(const SixWords_guess* source_guess) {
    word0_guess = source_guess->word0_guess;
    word4_guess = source_guess->word4_guess;
    word8_guess = source_guess->word8_guess;
    wordC_guess = source_guess->wordC_guess;
    word10_guess = source_guess->word10_guess;
    word14_guess = source_guess->word14_guess;
}

struct Settings_guess {
    unsigned char padding_guess[0xbf0];
    unsigned valuesBF0_guess[0x40];
    unsigned values_586d7_guess[16];
    unsigned values_586ef_guess[2];
    unsigned valuesD38_guess[0x24];
    unsigned char paddingDC8_guess[0xC354 - 0xDC8];
    BoundedArray_guess<unsigned, 6> valuesC354_guess;

    void SetBF0_guess(unsigned index_guess, unsigned value_guess);
    void Set586d7_guess(unsigned index_guess, unsigned value_guess);
    void Set586ef_guess(unsigned index_guess, unsigned value_guess);
    void SetD38_guess(unsigned index_guess, unsigned value_guess);
    void ClearC354_guess();
};

// FUNCTION: TITANIUM 0x004586BF
// More bounds-checked setters (sizes 64, 16, 2, 36). +0xD38 holds the 36 queued cursor items
// (AddItemToCursorQueue_guess).
void Settings_guess::SetBF0_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 0x40) {
        __debugbreak();
    }
    valuesBF0_guess[index_guess] = value_guess;
}

// Stores bank item `index` (slots 2000-2015; 16 slots, larger traps).
// FUNCTION: TITANIUM 0x004586D7
void Settings_guess::Set586d7_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 16) {
        __debugbreak();
    }
    values_586d7_guess[index_guess] = value_guess;
}

// Stores shared bank item `index` (slots 2500-2501; 2 slots, larger traps).
// FUNCTION: TITANIUM 0x004586EF
void Settings_guess::Set586ef_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 2) {
        __debugbreak();
    }
    values_586ef_guess[index_guess] = value_guess;
}

// FUNCTION: TITANIUM 0x00458707
// Cursor queue entry.
void Settings_guess::SetD38_guess(unsigned index_guess, unsigned value_guess) {
    if (index_guess >= 0x24) {
        __debugbreak();
    }
    valuesD38_guess[index_guess] = value_guess;
}

// Zeroes the six dwords at +0xC354 of the character.
// FUNCTION: TITANIUM 0x0045871F
void Settings_guess::ClearC354_guess() {
    for (unsigned i_guess = 0; i_guess < 6; ++i_guess) {
        valuesC354_guess[i_guess] = 0;
    }
}

struct Input58738_guess {
    int command_guess;
    unsigned char padding04_guess[0x40];
    char names44_guess[5][0x40];
    union {
        struct {
            char name184_guess[0x3c];
            int value1c0_guess;
        } route_guess;
        unsigned char raw184_guess[0x40];
    };
    char extra1c4_guess[0x40];
};

struct NameOffset58738_guess {
    unsigned char padding00_guess[4];
    int vbaseOffset_0004_guess;
};

struct ClientRoot58738_guess {
    unsigned char padding00_guess[8];
    NameOffset58738_guess* nameOffset8_guess;
    unsigned char padding0C_guess[0x44 - 0x0C];
    char names44_guess[0x1000];
};

struct ResetOwner58738_guess {
    // EXTERNAL: TITANIUM 0x0050A167 ResetOwner58738_guess::Reset_guess
    void Reset_guess();
};

struct Finalizer58738_guess {
    // EXTERNAL: TITANIUM 0x0042FCD9 Finalizer58738_guess::ClearPendingInvite_guess
    void ClearPendingInvite_guess();
};

struct Backend58738_guess {
    // EXTERNAL: TITANIUM 0x004B3FFE Backend58738_guess::ClearGroupLeaderData_guess
    void ClearGroupLeaderData_guess(ClientRoot58738_guess* owner_guess);

    // EXTERNAL: TITANIUM 0x004B4102 Backend58738_guess::Update_guess
    void Update_guess(ClientRoot58738_guess* owner_guess, const char* value_guess);
};

// EXTERNAL: TITANIUM 0x00474E01 DispatchGroupUpdateOperation_guess
void __cdecl DispatchGroupUpdateOperation_guess(ClientRoot58738_guess* owner_guess,
                                Input58738_guess* input_guess);

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* destination_guess, int code_guess,
                                const char* first_guess, ...);

// EXTERNAL: TITANIUM 0x00468694 do_lfg_guess
void __cdecl do_lfg_guess(DispatchTarget_guess* owner_guess,
                                char* text_guess);

#define g_client58738_guess EQ_GLOBAL(ClientRoot58738_guess*, 0x00905D00)
#define g_recordFlags58738_guess EQ_ARRAY(unsigned char, 0x00904248)
#define g_recordNames58738_guess EQ_ARRAY(char, 0x0090424D)
#define g_recordValues58738_guess EQ_ARRAY(DispatchTarget_guess*, 0x00904390)
#define g_savedName58738_guess EQ_ARRAY(char, 0x009043A4)
#define g_initialize58738_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_blocked58738_guess EQ_GLOBAL(int, 0x00923884)
#define g_backend58738_guess EQ_GLOBAL(Backend58738_guess*, 0x009859EC)
#define g_notify58738_guess EQ_GLOBAL(ResetOwner58738_guess*, 0x00991A58)
#define g_finalizer58738_guess EQ_ARRAY(Finalizer58738_guess, 0x0091D708)
#define g_finalFlags58738_guess EQ_ARRAY(unsigned char, 0x00985808)

// FUNCTION: TITANIUM 0x00458738
// @early-stop: budget, structural ndiff=215
// GroupUpdate_Struct {action, yourname, membername[5], leader}. Actions as EQEmu's groupAct*: 0 a member
// joined (0x577), 1 one left (0x2EE5), 3 a member renamed (0x13AF), 5 removed / 6 disbanded, 7 you
// joined (0x2EE4), 8 new leader (0x13B0/0x13B1), 9 you formed the group (0x2EE3).
void __cdecl Handle_OP_GroupUpdate_guess(Input58738_guess* input_guess) {
    char message_guess[0x200] = {0};

    if (g_initialize58738_guess != 0 || g_blocked58738_guess != 0 ||
        input_guess == 0) {
        return;
    }

    DispatchGroupUpdateOperation_guess(g_client58738_guess, input_guess);

    switch (input_guess->command_guess) {
    case 5:
    case 6: {
        ((Settings_guess*)g_client58738_guess)->ClearC354_guess();
        ((ClearRegionOwner_guess*)g_client58738_guess)->ClearGroupMemberNames_guess();
        ((BufferOwner_guess*)g_client58738_guess)->ClearGroupLeaderName_guess();
        if (g_backend58738_guess != 0) {
            g_backend58738_guess->ClearGroupLeaderData_guess(g_client58738_guess);
        }
        memset(g_recordFlags58738_guess, 0, 0x19c);
        g_propertyOwnerCurrent_guess->SetGroupInvitePending_guess(0);
        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valueF90_guess |= 0xffffffff;
        if (input_guess->command_guess == 5) {
            int code_guess = input_guess->route_guess.value1c0_guess;
            if (code_guess == 0) {
                return;
            }
            pEverQuest->dsp_chat(
                g_catalog452D85_guess->getString(code_guess, 0), 0x111, 1);
        } else {
            pEverQuest->dsp_chat(
                g_catalog452D85_guess->getString(0x2ee2, 0), 0x111, 1);
        }
        return;
    }
    case 0: {
        int index_guess = 0;
        do {
            if (g_recordFlags58738_guess[index_guess] == 0) {
                char* record_guess = g_recordNames58738_guess + index_guess * 0x40;
                g_recordFlags58738_guess[index_guess] = 1;
                FUN_0060e450_guess(record_guess, input_guess->names44_guess[0]);
                g_recordValues58738_guess[index_guess] =
                    ResolveTarget_guess(record_guess);
                FUN_0046da4a_guess(message_guess, 0x577, record_guess,
                                   0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message_guess, 0x111, 1);
                return;
            }
            ++index_guess;
        } while (index_guess < 5);
        return;
    }
    case 1: {
        char* name_guess = input_guess->names44_guess[0];
        if (FUN_00574950_guess(
                name_guess, g_client58738_guess->names44_guess +
                    g_client58738_guess->nameOffset8_guess->vbaseOffset_0004_guess) != 0) {
            int index_guess = 0;
            do {
                char* record_guess = g_recordNames58738_guess + index_guess * 0x40;
                if (FUN_00574950_guess(name_guess, record_guess) == 0) {
                    g_recordFlags58738_guess[index_guess] = 0;
                    memset(record_guess, 0, 0x40);
                    g_recordValues58738_guess[index_guess] = 0;
                    char* formatArgument_guess = name_guess;
                    FormatText453962_guess(
                        message_guess, g_catalog452D85_guess->getString(0x2ee5, 0),
                        &formatArgument_guess, -1, 0);
                    pEverQuest->dsp_chat(message_guess, 0x111, 1);
                    if (index_guess < 4) {
                        do {
                            char* destination_guess =
                                g_recordNames58738_guess + index_guess * 0x40;
                            char* source_guess = destination_guess + 0x40;
                            FUN_0060e450_guess(destination_guess, source_guess);
                            g_recordValues58738_guess[index_guess] =
                                g_recordValues58738_guess[index_guess + 1];
                            g_recordFlags58738_guess[index_guess] =
                                g_recordFlags58738_guess[index_guess + 1];
                            ++index_guess;
                        } while (index_guess < 4);
                    }
                    g_recordFlags58738_guess[4] = 0;
                    g_recordNames58738_guess[4 * 0x40] = 0;
                    g_recordValues58738_guess[4] = 0;
                    return;
                }
                ++index_guess;
            } while (index_guess < 5);
            return;
        }

        ((Settings_guess*)g_client58738_guess)->ClearC354_guess();
        ((ClearRegionOwner_guess*)g_client58738_guess)->ClearGroupMemberNames_guess();
        ((BufferOwner_guess*)g_client58738_guess)->ClearGroupLeaderName_guess();
        if (g_backend58738_guess != 0) {
            g_backend58738_guess->ClearGroupLeaderData_guess(g_client58738_guess);
        }
        memset(g_recordFlags58738_guess, 0, 0x19c);
        pEverQuest->dsp_chat(
            g_catalog452D85_guess->getString(0x2ee1, 0), 0x111, 1);
        return;
    }
    case 3: {
        char* formatArguments_guess[2];
        formatArguments_guess[0] = input_guess->names44_guess[0];
        formatArguments_guess[1] = input_guess->names44_guess[1];
        FormatText453962_guess(
            message_guess, g_catalog452D85_guess->getString(0x13af, 0),
            formatArguments_guess, -1, 0);
        pEverQuest->dsp_chat(message_guess, 0x111, 1);

        if (__stricmp(g_savedName58738_guess, input_guess->names44_guess[0]) == 0) {
            FUN_0060e450_guess(g_savedName58738_guess,
                               input_guess->names44_guess[1]);
        }
        if (__stricmp(input_guess->names44_guess[0],
                      g_client58738_guess->names44_guess +
                          g_client58738_guess->nameOffset8_guess->vbaseOffset_0004_guess) != 0) {
            for (int index_guess = 0; index_guess < 5; ++index_guess) {
                char* record_guess = g_recordNames58738_guess + index_guess * 0x40;
                if (FUN_00574950_guess(input_guess->names44_guess[0], record_guess) == 0) {
                    FUN_0060e450_guess(record_guess, input_guess->names44_guess[1]);
                }
            }
        }
        return;
    }
    case 7: {
        for (int index_guess = 0; index_guess < 5; ++index_guess) {
            char* record_guess = g_recordNames58738_guess + index_guess * 0x40;
            FUN_0060e450_guess(record_guess, input_guess->names44_guess[index_guess]);
            if (record_guess[0] == 0) {
                g_recordFlags58738_guess[index_guess] = 0;
                g_recordValues58738_guess[index_guess] = 0;
            } else {
                g_recordFlags58738_guess[index_guess] = 1;
                g_recordValues58738_guess[index_guess] =
                    ResolveTarget_guess(record_guess);
            }
        }
        FUN_0060e450_guess(g_savedName58738_guess,
                           input_guess->route_guess.name184_guess);
        if (g_backend58738_guess != 0) {
            g_backend58738_guess->Update_guess(
                g_client58738_guess, input_guess->extra1c4_guess);
        }
        pEverQuest->dsp_chat(
            g_catalog452D85_guess->getString(0x2ee4, 0), 0x111, 1);
        if (g_propertyOwnerCurrent_guess->lfg_01b4_guess != 0) {
            do_lfg_guess(
                g_propertyOwnerCurrent_guess,
                g_catalog452D85_guess->getString(0x3292, 0));
        }
        g_finalizer58738_guess->ClearPendingInvite_guess();
        return;
    }
    case 8: {
        FUN_0060e450_guess(g_savedName58738_guess, input_guess->names44_guess[0]);
        if (FUN_00574950_guess(
                input_guess->names44_guess[0], g_client58738_guess->names44_guess +
                    g_client58738_guess->nameOffset8_guess->vbaseOffset_0004_guess) == 0) {
            FUN_0046da4a_guess(message_guess, 0x13b0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            FUN_0046da4a_guess(message_guess, 0x13b1, g_savedName58738_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(message_guess, 0x111, 1);
        return;
    }
    case 9: {
        FUN_0060e450_guess(g_savedName58738_guess, input_guess->names44_guess[0]);
        pEverQuest->dsp_chat(
            g_catalog452D85_guess->getString(0x2ee3, 0), 0x111, 1);
        if (g_notify58738_guess == 0) {
            do_lfg_guess(
                g_propertyOwnerCurrent_guess,
                g_catalog452D85_guess->getString(0x3292, 0));
        } else {
            g_notify58738_guess->Reset_guess();
        }
        g_propertyOwnerCurrent_guess->SetGroupInvitePending_guess(0);
        g_finalFlags58738_guess[0] = 0;
        g_finalFlags58738_guess[0x3d] = 0;
        g_finalFlags58738_guess[0x7d] = 0;
        g_finalizer58738_guess->ClearPendingInvite_guess();
        return;
    }
    }
}

struct RankEntry458CD1_guess {
    unsigned char padding_guess[0x58];
    int value58_guess;

    // EXTERNAL: TITANIUM 0x005ECCC0 RankEntry458CD1_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005EC630 RankEntry458CD1_guess::HasValue_guess
    int HasValue_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x005EC650 RankEntry458CD1_guess::GetValue_guess
    RankEntry458CD1_guess** GetValue_guess(int index_guess);
};

struct RankTable458CD1_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 RankTable458CD1_guess::GetEntry_guess
    RankEntry458CD1_guess* GetEntry_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00434777 RankTable458CD1_guess::GetSlot_guess
    RankEntry458CD1_guess** GetSlot_guess(int index_guess);
};

// FUNCTION: TITANIUM 0x00458CD1
// {slot, unused, -charges}: lowers the item's charges (+0x48). Titanium slot ids: 0-21 worn, 22-29
// general, 30 cursor, 31 + 10*parent + i for item i in the bag in slot `parent` (251-330 for the
// general bags). Returns 0 for a bad slot; the caller prints 0x56E.
int __cdecl Handle_OP_DeleteCharge_guess(int index_guess, int unused_guess, int delta_guess) {
    RankEntry458CD1_guess** slot_guess;

    if (delta_guess > -1) {
        return 0;
    }
    if (index_guess < 0x1f) {
        if (((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(index_guess) != 0) {
            slot_guess = ((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->GetSlot_guess(index_guess);
        } else {
            return 0;
        }
    } else {
        int group_guess = (index_guess - 0x1f) / 10;
        int sub_guess = (index_guess - 0x1f) % 10;
        if (((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess) != 0 &&
            ((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetItemClass_guess() == 1 &&
            ((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->HasValue_guess(sub_guess) != 0) {
            slot_guess = ((RankTable458CD1_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetValue_guess(sub_guess);
        } else {
            return 0;
        }
    }
    (*slot_guess)->value58_guess += delta_guess;
    g_propertyOwnerState457A91_guess->valueC28C_guess = 1;
    return 1;
}

struct RankEntry458DC2_guess {
    virtual void Release_guess(int flags_guess);
    unsigned char padding04_guess[0x44];
    int value48_guess;

    // EXTERNAL: TITANIUM 0x005ECCC0 RankEntry458DC2_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005EC630 RankEntry458DC2_guess::HasValue_guess
    int HasValue_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x005EC650 RankEntry458DC2_guess::GetValue_guess
    RankEntry458DC2_guess** GetValue_guess(int index_guess);
};

struct RankTable458DC2_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 RankTable458DC2_guess::GetEntry_guess
    RankEntry458DC2_guess* GetEntry_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00434777 RankTable458DC2_guess::GetSlot_guess
    RankEntry458DC2_guess** GetSlot_guess(int index_guess);
};

struct RankSettings458DC2_guess {
    unsigned char padding_guess[0x10];
    unsigned char enabled10_guess;
};

#define g_rankSettings458DC2_guess EQ_GLOBAL(RankSettings458DC2_guess*, 0x00905D24)

// FUNCTION: TITANIUM 0x00458DC2
// DeleteItem_Struct {from, to, count}: like Handle_OP_DeleteCharge_guess, and to == -1 at 0 charges
// destroys the item (emptying the cursor, slot 30, clears its flag).
int __cdecl Handle_OP_DeleteItem_guess(int index_guess, int operation_guess, int delta_guess) {
    RankEntry458DC2_guess** slot_guess;

    if (delta_guess > -1) {
        return 0;
    }
    if (index_guess < 0x1f) {
        if (((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(index_guess) != 0) {
            slot_guess = ((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->GetSlot_guess(index_guess);
        } else {
            return 0;
        }
    } else {
        int group_guess = (index_guess - 0x1f) / 10;
        int sub_guess = (index_guess - 0x1f) % 10;
        if (((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess) != 0 &&
            ((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetItemClass_guess() == 1 &&
            ((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->HasValue_guess(sub_guess) != 0) {
            slot_guess = ((RankTable458DC2_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetValue_guess(sub_guess);
        } else {
            return 0;
        }
    }
    (*slot_guess)->value48_guess += delta_guess;
    if ((*slot_guess)->value48_guess == 0 && operation_guess == -1) {
        if (*slot_guess != 0) {
            (*slot_guess)->Release_guess(1);
        }
        *slot_guess = 0;
        if (index_guess == 0x1e) {
            g_rankSettings458DC2_guess->enabled10_guess = 0;
        }
    }
    return 1;
}

struct CHARINFO2 {
    unsigned char padding_guess[0x119C];
    unsigned char class_119c_guess;
};

struct CharacterPrefix458ED8_guess {
    int pad0_guess;
    int pad4_guess;
};

// The character base is a virtual base of the object at 0x00905D00; reaching
// GetCharInfo2 through it walks the vbptr at +8.
struct CharacterBase458ED8_guess : EQ_Character {
    CHARINFO2* Info_guess() { return GetCharInfo2(); }
};

struct CharacterView458ED8_guess : CharacterPrefix458ED8_guess,
                                   virtual CharacterBase458ED8_guess {
};

#define g_characterView458ED8_guess EQ_GLOBAL(CharacterView458ED8_guess*, 0x00905D00)

struct SpellBook458ED8_guess {
    // EXTERNAL: TITANIUM 0x005581DE SpellBook458ED8_guess::Set_guess
    void Set_guess(int index_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x0055712B SpellBook458ED8_guess::Apply_guess
    void Apply_guess(int index_guess, int value_guess);
};

#define g_spellBook458ED8_guess EQ_GLOBAL(SpellBook458ED8_guess*, 0x00850C30)

// FUNCTION: TITANIUM 0x00458ED8
// @early-stop: budget, structural ndiff=45
// MemorizeSpell_Struct {slot, spell id, scribing, reduction}, called as (scribing, slot, spell, ...):
// 0 scribed and 1 memorized refresh the spellbook, 2 forgets gem `slot`, 3 starts the recast timers
// (gems 0-8; slot 9 is the 0x127 ability), -1 only releases the pending-request count.
int __cdecl Handle_OP_MemorizeSpell_guess(int operation_guess, int index_guess, int value_guess,
                                int amount_guess) {
    switch (operation_guess) {
    case -1:
        if (g_target4520A1Count_guess > 0) {
            --g_target4520A1Count_guess;
        } else {
            g_target4520A1Count_guess = 0;
        }
        break;
    case 0:
        if (g_target4520A1Count_guess > 0) {
            --g_target4520A1Count_guess;
        } else {
            g_target4520A1Count_guess = 0;
        }
        if (g_spellBook458ED8_guess != 0) {
            g_spellBook458ED8_guess->Set_guess(index_guess, value_guess);
        }
        break;
    case 1:
        if (g_target4520A1Count_guess > 0) {
            --g_target4520A1Count_guess;
        } else {
            g_target4520A1Count_guess = 0;
        }
        if (g_spellBook458ED8_guess != 0) {
            g_spellBook458ED8_guess->Apply_guess(index_guess, value_guess);
        }
        break;
    case 2:
        if (g_target4520A1Count_guess > 0) {
            --g_target4520A1Count_guess;
        } else {
            g_target4520A1Count_guess = 0;
        }
        if (pinstCCastSpellWnd_guess != 0) {
            pinstCCastSpellWnd_guess->Update_guess(index_guess);
        } else if (g_propertyOwnerGlobal_guess != 0) {
            ((IndexedOwner_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->SetF30_guess(index_guess, 0xffffffff);
        }
        break;
    case 3:
        if (g_propertyOwnerCurrent_guess != 0) {
            if (g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess != 0 &&
                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value1048_guess != 0 &&
                g_propertyOwnerGlobal_guess != 0 &&
                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->probe1050_guess.Find_guess(
                    g_propertyOwnerGlobal_guess != 0
                        ? &g_propertyOwnerGlobal_guess->command_guess
                        : 0) != 0) {
                LookupValue454415_guess* record_guess =
                    g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value1048_guess;
                if (*g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->probe1050_guess
                        .Find_guess(
                            g_propertyOwnerGlobal_guess != 0
                                ? &g_propertyOwnerGlobal_guess->command_guess
                                : 0) == record_guess) {
                    LookupValue454415_guess* duration_guess =
                        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value1048_guess;
                    if (g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valueFA0_guess == 0 &&
                        duration_guess->GetRecastTime_guess() > 0) {
                        duration_guess->value54_guess =
                            duration_guess->GetRecastTime_guess() +
                            g_updateSettings_guess->frameTime_0148_guess;
                    }
                }
            }
            if (index_guess <= 8 || index_guess == 9) {
                if (IsValidSpellIndex_guess(value_guess) != 0) {
                    LookupValue454415_guess* record_guess =
                        g_lookup454415_guess->Find_guess(value_guess);
                    if (record_guess != 0) {
                        amount_guess = record_guess->value1c_guess - amount_guess;
                        if (index_guess == 9) {
                            amount_guess = record_guess->value1c_guess -
                                g_propertyOwnerGlobal_guess->command_guess
                                    .TotalSpellAffects_guess(0x127, 1, 0, 1) * 1000;
                        }
                        g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valuesE8_guess[index_guess] =
                            g_updateSettings_guess->frameTime_0148_guess + amount_guess;
                        if (index_guess <= 8) {
                            g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->valueF9C_guess = 0xff;
                            if (g_characterView458ED8_guess->Info_guess()->class_119c_guess == 8) {
                                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value110_guess =
                                    g_updateSettings_guess->frameTime_0148_guess;
                            } else {
                                g_propertyOwnerCurrent_guess->pActorInfo_01a8_guess->value110_guess =
                                    g_updateSettings_guess->frameTime_0148_guess +
                                    record_guess->value18_guess;
                            }
                            if (g_characterView458ED8_guess->Info_guess()->class_119c_guess == 8) {
                                int next_guess = g_propertyOwnerCurrent_guess->Next_guess();
                                if (next_guess > 0 && next_guess < 10) {
                                    g_propertyOwnerGlobal_guess->command_guess.Handle_guess(0);
                                    pinstCCastSpellWnd_guess->Select_guess(next_guess - 1);
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    }
    return 1;
}

struct RankValue4591FD_guess;

struct RankPropertyValue4591FD_guess {
    unsigned char padding_guess[0x78];
    int value78_guess;
};

struct RankPropertyData4591FD_guess {
    unsigned char padding_guess[0x10];
    RankPropertyValue4591FD_guess value10_guess;
};

struct EQ_CharacterProfileView5_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView5_guess::GetCharInfo2
    RankPropertyData4591FD_guess* GetCharInfo2();
};

struct RankEntry4591FD_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 RankEntry4591FD_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005EC630 RankEntry4591FD_guess::HasValue_guess
    int HasValue_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x005EC650 RankEntry4591FD_guess::GetValue_guess
    RankValue4591FD_guess** GetValue_guess(int index_guess);
};

struct RankTable4591FD_guess {
    unsigned char padding00_guess[4];
    EQ_CharacterProfileView5_guess locator_guess;

    // EXTERNAL: TITANIUM 0x0040CC50 RankTable4591FD_guess::GetEntry_guess
    RankEntry4591FD_guess* GetEntry_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00434777 RankTable4591FD_guess::GetSlot_guess
    RankValue4591FD_guess** GetSlot_guess(int index_guess);
};

struct RankValue4591FD_guess {
    virtual void Release_guess(int flags_guess);

    // EXTERNAL: TITANIUM 0x005ECCC0 RankValue4591FD_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005EC760 RankValue4591FD_guess::IsStackable_guess
    char IsStackable_guess();

    // EXTERNAL: TITANIUM 0x005E0F30 RankValue4591FD_guess::GetItemId_guess
    int GetItemId_guess();
};

struct RankSettings4591FD_guess {
    unsigned char padding_guess[0x10];
    unsigned char enabled10_guess;
};

#define g_rankSettings4591FD_guess EQ_GLOBAL(RankSettings4591FD_guess*, 0x00905D24)

struct RankDispatchState4591FD_guess {
    unsigned char padding_guess[0x1048];
    RankValue4591FD_guess* value1048_guess;
};

struct RankCurrentOwner4591FD_guess {
    unsigned char padding_guess[0x1a8];
    RankDispatchState4591FD_guess* value1a8_guess;
};

struct RankStateManager4591FD_guess {
    // EXTERNAL: TITANIUM 0x004FAA17 RankStateManager4591FD_guess::Apply_guess
    void Apply_guess(int value_guess, int one_guess);
};

#define g_rankStateManager4591FD_guess EQ_GLOBAL(RankStateManager4591FD_guess*, 0x00850CBC)

// EXTERNAL: TITANIUM 0x00464AFB GetMaterialSlotFromInvSlot_guess
int __cdecl GetMaterialSlotFromInvSlot_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00464C94 MoveItemQty_guess
int __cdecl MoveItemQty_guess(int* first_guess, int* second_guess,
                               int operation_guess, int zero1_guess, int zero2_guess);

// FUNCTION: TITANIUM 0x004591FD
// @early-stop: budget, structural ndiff=53
// MoveItem_Struct {from, to, count} in the slot numbering of Handle_OP_DeleteCharge_guess; to == -1
// deletes. Stacks merge when both sides can stack. Returns 0 on a bad slot; the caller prints 0x56D.
int __cdecl Handle_OP_MoveItem_guess(int firstIndex_guess, int secondIndex_guess,
                               int operation_guess) {
    RankValue4591FD_guess** firstSlot_guess;
    RankValue4591FD_guess** secondSlot_guess;
    RankValue4591FD_guess* firstValue_guess = 0;
    RankValue4591FD_guess* secondValue_guess = 0;

    if (firstIndex_guess < 0x1f) {
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(firstIndex_guess) == 0) {
            return 0;
        }
        firstSlot_guess = ((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->GetSlot_guess(firstIndex_guess);
    } else {
        int group_guess = (firstIndex_guess - 0x1f) / 10;
        int sub_guess = (firstIndex_guess - 0x1f) % 10;
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess) == 0) {
            return 0;
        }
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetItemClass_guess() != 1) {
            return 0;
        }
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->HasValue_guess(sub_guess) == 0) {
            return 0;
        }
        firstSlot_guess = ((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->GetEntry_guess(group_guess)->GetValue_guess(sub_guess);
    }

    if (secondIndex_guess == -1) {
        if ((*firstSlot_guess)->GetItemClass_guess() == 1) {
            g_rankStateManager4591FD_guess->Apply_guess((int)*firstSlot_guess, 1);
        }
        RankDispatchState4591FD_guess* state_guess =
            ((RankCurrentOwner4591FD_guess*)g_propertyOwnerCurrent_guess)->value1a8_guess;
        if (*firstSlot_guess == state_guess->value1048_guess) {
            state_guess->value1048_guess = 0;
        }
        if (*firstSlot_guess != 0) {
            (*firstSlot_guess)->Release_guess(1);
        }
        *firstSlot_guess = 0;
        if (firstIndex_guess == 0x1e) {
            g_rankSettings4591FD_guess->enabled10_guess = 0;
        }
        if (g_propertyOwnerCurrent_guess == 0) {
            return 1;
        }
        int id_guess = GetMaterialSlotFromInvSlot_guess(firstIndex_guess);
        g_propertyOwnerCurrent_guess->Refresh4548083A_guess(
            id_guess, EQ_ARRAY(char, 0x006410A8), 0);
        return 1;
    }

    if (secondIndex_guess < 0x1f) {
        secondSlot_guess = ((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->GetSlot_guess(secondIndex_guess);
    } else {
        int group_guess = (secondIndex_guess - 0x1f) / 10;
        int sub_guess = (secondIndex_guess - 0x1f) % 10;
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess) == 0) {
            return 0;
        }
        if (((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                ->GetEntry_guess(group_guess)->GetItemClass_guess() != 1) {
            return 0;
        }
        secondSlot_guess = ((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->GetEntry_guess(group_guess)->GetValue_guess(sub_guess);
    }

    if (firstSlot_guess == 0) {
        return 0;
    }
    if (secondSlot_guess == 0) {
        return 0;
    }
    firstValue_guess = *firstSlot_guess;
    secondValue_guess = *secondSlot_guess;
    if (firstValue_guess == 0 && secondValue_guess == 0) {
        return 0;
    }
    if (firstValue_guess == 0) {
        RankValue4591FD_guess* temp_guess = firstValue_guess;
        firstValue_guess = secondValue_guess;
        secondValue_guess = temp_guess;
    } else {
        if (secondValue_guess != 0) {
            if (firstValue_guess->IsStackable_guess() != 0 &&
                secondValue_guess->GetItemId_guess() == firstValue_guess->GetItemId_guess()) {
                if (MoveItemQty_guess((int*)&firstValue_guess, (int*)&secondValue_guess,
                                       operation_guess, 0, 0) == 0) {
                    return 0;
                }
            } else {
                RankValue4591FD_guess* temp_guess = firstValue_guess;
                firstValue_guess = secondValue_guess;
                secondValue_guess = temp_guess;
            }
        } else if (firstValue_guess->IsStackable_guess() != 0) {
            if (MoveItemQty_guess((int*)&firstValue_guess, (int*)&secondValue_guess,
                                   operation_guess, 0, 0) == 0) {
                return 0;
            }
        } else {
            RankValue4591FD_guess* temp_guess = firstValue_guess;
            firstValue_guess = secondValue_guess;
            secondValue_guess = temp_guess;
        }
    }

    *firstSlot_guess = firstValue_guess;
    *secondSlot_guess = secondValue_guess;
    g_rankSettings4591FD_guess->enabled10_guess =
        ((RankTable4591FD_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
            g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
            ->locator_guess.GetCharInfo2()
            ->value10_guess.value78_guess != 0;
    return 1;
}

struct UpdateQueue_guess {
    int value0_guess;
    unsigned char padding_guess[0xC];
    int enabled10_guess;

    void SetValue_guess(int value_guess);
};

// FUNCTION: TITANIUM 0x0045AEE0
// Stores the value only when the queue is enabled (+0x10).
void UpdateQueue_guess::SetValue_guess(int value_guess) {
    PrepareUpdate_guess(value_guess);
    if (enabled10_guess != 0) {
        value0_guess = value_guess;
    }
}

struct Values45AEFB_guess {
    int count_guess;

    // EXTERNAL: TITANIUM 0x00432806 Values45AEFB_guess::Get_guess
    void* Get_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00432BCC Values45AEFB_guess::Set_guess
    void Set_guess(int index_guess, void* value_guess);
};

struct CopyBlock45AEFB_guess {
    unsigned words_guess[0x1b];
};

struct CopyObject45AEFB_guess {
    int value0_guess;
    unsigned char value4_guess;
    unsigned char padding5_guess[3];
    CopyBlock45AEFB_guess block8_guess;
    Values45AEFB_guess values74_guess;

    CopyObject45AEFB_guess* Copy_guess(CopyObject45AEFB_guess* source_guess);
};

// FUNCTION: TITANIUM 0x0045AEFB
// Copy assignment; opcode 0x3981 copies a 0x8C-byte record into pCharData with it.
CopyObject45AEFB_guess* CopyObject45AEFB_guess::Copy_guess(
    CopyObject45AEFB_guess* source_guess) {
    value0_guess = source_guess->value0_guess;
    value4_guess = source_guess->value4_guess;
    block8_guess = source_guess->block8_guess;

    int count_guess = values74_guess.count_guess;
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            void* value_guess = source_guess->values74_guess.Get_guess(index_guess);
            values74_guess.Set_guess(values74_guess.count_guess, value_guess);
            ++index_guess;
        } while (index_guess < count_guess);
    }
    return this;
}

struct IndexedTableB31C_guess {
    int count_guess; // 0x00
    unsigned char padding04_guess[4];
    unsigned int mask_guess; // 0x08
    unsigned int shift_guess; // 0x0C
    int** pages_guess; // 0x10
    unsigned char padding14_guess[4];
    unsigned char enabled_guess; // 0x18

    // EXTERNAL: TITANIUM 0x0045AEE0 IndexedTableB31C_guess::SetCount_guess
    void SetCount_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00548095 IndexedTableB31C_guess::Prepare_guess
    void Prepare_guess(int count_guess);

    IndexedTableB31C_guess* Copy_guess(IndexedTableB31C_guess* source_guess);
};

struct IndexedOwnerRoot459985_guess {
    unsigned char padding00_guess[8];
    union {
        PropertyOwnerOffset_guess* offset_guess;
        unsigned char region_guess[0xC278];
    };
};

struct Argument459985_guess {
    int value0_guess;
    int value4_guess;
    int value8_guess;
    unsigned valuesC_guess[0x200];
};

struct ValueAccessor459985_guess {
    // EXTERNAL: TITANIUM 0x0040E705 ValueAccessor459985_guess::GetMemorizedSpell_guess
    int GetMemorizedSpell_guess(int index_guess);
};

#define g_indexedOwnerRoot459985_guess EQ_GLOBAL(IndexedOwnerRoot459985_guess*, 0x00905D00)

struct LocaleOffset459A46_guess {
    unsigned char padding00_guess[4];
    int value4_guess;
};

struct LocaleRoot459A46_guess {
    unsigned char padding00_guess[8];
    LocaleOffset459A46_guess* vbtable_0008_guess;
    unsigned char padding0C_guess[0x44 - 0x0C];
    char strings44_guess[0x1000];
};

struct Argument459A46_guess {
    unsigned char padding00_guess[0x18];
    char name18_guess[0x40];
    unsigned char padding58_guess[4];
    char text5C_guess[0x40];
    int value9C_guess;
    unsigned char paddingA0_guess[0x44];
};

#define g_localeRoot459A46_guess EQ_GLOBAL(LocaleRoot459A46_guess*, 0x00905D00)

// FUNCTION: TITANIUM 0x00459A46
// Resurrect_Struct offer for this player: "%1 wants to RESURRECT you" (0x2356), the call-to-corpse text
// (0xDEB) for spells with flag 0x14C, else "%1 wants to cast %2 (%3 percent)" (0x2357). Box type 0x67.
void __cdecl Handle_OP_RezzRequest_guess(Argument459A46_guess* argument_guess) {
    char message_guess[0x200];
    char digits_guess[0x40];
    int id_guess = argument_guess->value9C_guess;

    LocaleRoot459A46_guess* locale_guess = g_localeRoot459A46_guess;
    if (__stricmp(argument_guess->name18_guess,
                  locale_guess->strings44_guess + locale_guess->vbtable_0008_guess->value4_guess) != 0) {
        return;
    }

    LookupValue454415_guess* value_guess = 0;
    if (IsValidSpellIndex_guess(id_guess) != 0) {
        value_guess = g_lookup454415_guess->Find_guess(id_guess);
    }

    if (value_guess == 0) {
        FormatNotice_guess(
            message_guess, 0x2356,
            g_target4520E5Data_guess->GetText_guess(argument_guess->text5C_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
    } else if (value_guess->Check_guess(0x14C) != 0) {
        FormatNotice_guess(
            message_guess, 0xDEB,
            g_target4520E5Data_guess->GetText_guess(argument_guess->text5C_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        _itoa(value_guess->value30_guess, digits_guess, 10);
        FormatNotice_guess(
            message_guess, 0x2357,
            g_target4520E5Data_guess->GetText_guess(argument_guess->text5C_guess),
            value_guess->value208_guess, digits_guess, 0, 0, 0, 0, 0, 0);
    }

    void* copy_guess = operator new(0xE4);
    memcpy(copy_guess, argument_guess, 0xE4);
    g_noticeSender_guess->Activate(
        g_noticeValue_guess != 0 ? g_noticeValue_guess + 8 : 0, 0x67, message_guess,
        0xC, 300000, copy_guess, 0);
}

struct ChannelTextResolver4595F7_guess {
    // EXTERNAL: TITANIUM 0x00492595 ChannelTextResolver4595F7_guess::Resolve_guess
    char* Resolve_guess(int channel_guess);
};

// EXTERNAL: TITANIUM 0x00478F73 GarbleText_guess
char __cdecl GarbleText_guess(const char* source_guess, char* destination_guess,
                                unsigned char channel_guess);

struct SoundNotify4595F7_guess {
    // EXTERNAL: TITANIUM 0x00524FC6 SoundNotify4595F7_guess::Notify_guess
    void Notify_guess(const char* text_guess, float x_guess, float y_guess,
                      float z_guess, const char* message_guess);
};

#define g_chatCharacter4595F7_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_chatPaused4595F7_guess EQ_GLOBAL(int, 0x00923D74)
#define pinstCJournalNPCWnd_guess EQ_GLOBAL(SoundNotify4595F7_guess*, 0x00850CA4)

// FUNCTION: TITANIUM 0x004595F7
// @early-stop: budget, structural ndiff=139
// SpecialMesg text. channel_guess is the language: 0 is common, others get an "in <language>," prefix
// and are garbled to the player's skill. Mode 0 raw, 1 says, 2 shouts, 3 "%2", 4 "%1 %2". Say or
// self-targeted text also goes to the window at 0x00850CA4 with the speaker's position.
void __cdecl Handle_OP_SpecialMesg_guess(int mode_guess, unsigned int channel_guess,
                                const char* text_guess, int x_guess, int y_guess,
                                int z_guess, int spawnId_guess, const char* source_guess,
                                int messageType_guess, int color_guess) {
    char message_guess[0x100];
    char channelText_guess[0x1000];
    char convertedText_guess[0x1000];
    char converted_guess = 0;

    if (channel_guess != 0) {
        unsigned char (&channelValues_guess)[0xC000] =
            *(unsigned char (*)[0xC000])&g_chatCharacter4595F7_guess->pad_000C[0];
        if ((channel_guess < 32
                 ? channelValues_guess[g_chatCharacter4595F7_guess->vbtable[1] + 8 +
                                       channel_guess]
                 : (__debugbreak(),
                    channelValues_guess[g_chatCharacter4595F7_guess->vbtable[1] + 8 +
                                        channel_guess])) <= 0x18) {
            FUN_0060e450_guess(message_guess, pStringTable->getString(0x584, 0));
        } else {
            FUN_0046da4a_guess(
                message_guess, 0x583,
                ((ChannelTextResolver4595F7_guess*)pEverQuest)
                    ->Resolve_guess(channel_guess),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
        if (g_chatPaused4595F7_guess == 0) {
            unsigned char (&channelValues_guess)[0xC000] =
                *(unsigned char (*)[0xC000])&g_chatCharacter4595F7_guess->pad_000C[0];
            unsigned char channelValue_guess =
                channel_guess < 32
                    ? channelValues_guess[g_chatCharacter4595F7_guess->vbtable[1] + 8 +
                                          channel_guess]
                    : (__debugbreak(),
                       channelValues_guess[g_chatCharacter4595F7_guess->vbtable[1] + 8 +
                                           channel_guess]);
            converted_guess = GarbleText_guess(
                source_guess, convertedText_guess, channelValue_guess);
            source_guess = convertedText_guess;
        }
    }

    if (mode_guess == 0) {
        FUN_0060e450_guess(channelText_guess, source_guess);
    } else {
        const char* alternate_guess = source_guess;
        const char* third_guess = source_guess;
        int stringId_guess;
        if (mode_guess == 2) {
            if (channel_guess == 0) {
                stringId_guess = 0x40a;
                alternate_guess = 0;
                third_guess = 0;
            } else {
                stringId_guess = 0x58c;
                source_guess = message_guess;
            }
        } else if (mode_guess == 3) {
            stringId_guess = 0x40b;
            third_guess = 0;
        } else if (mode_guess == 4) {
            stringId_guess = 0x40c;
            third_guess = 0;
        } else if (channel_guess == 0) {
            stringId_guess = 0x408;
            third_guess = 0;
        } else {
            stringId_guess = 0x582;
            source_guess = message_guess;
        }
        FUN_0046da4a_guess(channelText_guess, stringId_guess, text_guess,
                           source_guess, third_guess, 0, 0, 0, 0, 0, 0);
    }

    pEverQuest->dsp_chat(channelText_guess, color_guess, true);
    if (converted_guess == 0 && *text_guess != 0 &&
        (messageType_guess == 2 ||
         (messageType_guess == 1 &&
          spawnId_guess == g_chatCharacter4595F7_guess->pSpawn->SpawnID)) &&
        pinstCJournalNPCWnd_guess != 0) {
        pinstCJournalNPCWnd_guess->Notify_guess(
            text_guess, (float)x_guess, (float)y_guess, (float)z_guess,
            channelText_guess);
    }
}

struct UpdateRootOffset4597D8_guess {
    unsigned char padding00_guess[4];
    int regionOffset_guess;
};

struct UpdateRegion4597D8_guess {
    // EXTERNAL: TITANIUM 0x0040E722 UpdateRegion4597D8_guess::GetValue_guess
    int GetValue_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x0041AA6A UpdateRegion4597D8_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
};

struct UpdateRoot4597D8_guess {
    unsigned char padding00_guess[8];
    union {
        UpdateRootOffset4597D8_guess* offset_guess;
        unsigned char region_guess[1];
    };
};

struct Argument4597D8_guess {
    int index_guess;
    int value_guess;
};

struct MessageBuffer4597D8_guess {
    char text_guess[0x100];
};

struct UpdateHandler4597D8_guess {
    // EXTERNAL: TITANIUM 0x00554E07 UpdateHandler4597D8_guess::Handle_guess
    void Handle_guess(int index_guess);
};

struct UpdateProcessor4597D8_guess {
    // EXTERNAL: TITANIUM 0x0056B400 UpdateProcessor4597D8_guess::Apply_guess
    void Apply_guess(int index_guess, int value_guess);
};

struct UpdateNotifier4597D8_guess {
    // EXTERNAL: TITANIUM 0x00567E44 UpdateNotifier4597D8_guess::Notify_guess
    void Notify_guess(int index_guess, int value_guess);
};

#define g_updateRoot4597D8_guess EQ_GLOBAL(UpdateRoot4597D8_guess*, 0x00905D00)
#define pinstCSkillsWnd_guess EQ_GLOBAL(UpdateHandler4597D8_guess*, 0x00850BB4)
#define g_updateProcessor4597D8_guess EQ_GLOBAL(UpdateProcessor4597D8_guess*, 0x00850BB0)
#define g_updateNotifier4597D8_guess EQ_GLOBAL(UpdateNotifier4597D8_guess*, 0x00992940)

// FUNCTION: TITANIUM 0x004597D8
// @early-stop: budget, structural ndiff=120
// SkillUpdate_Struct {id, value}: ids 0-99 are skills, 100-131 languages. Prints "You have become
// better at %1! (%2)" (0x2F3B) and refreshes the skill windows.
void __cdecl Handle_OP_SkillUpdate_guess(Argument4597D8_guess* argument_guess) {
    int zero_guess = 0;
    char message_guess[0x100];

    if ((int)g_updateRoot4597D8_guess != zero_guess && argument_guess->index_guess >= zero_guess) {
        int index_guess = argument_guess->index_guess;
        Argument4597D8_guess* original_guess = argument_guess;

        if (index_guess < 100) {
            argument_guess = (Argument4597D8_guess*)((UpdateRegion4597D8_guess*)&g_updateRoot4597D8_guess->region_guess[
                g_updateRoot4597D8_guess->offset_guess->regionOffset_guess])->GetValue_guess(index_guess);
            ((UpdateRegion4597D8_guess*)&g_updateRoot4597D8_guess->region_guess[
                g_updateRoot4597D8_guess->offset_guess->regionOffset_guess])->SetValue_guess(
                    index_guess, original_guess->value_guess);
        } else {
            index_guess -= 100;
            if (index_guess >= 0x20) {
                return;
            }
            argument_guess = (Argument4597D8_guess*)g_updateRoot4597D8_guess->region_guess[
                g_updateRoot4597D8_guess->offset_guess->regionOffset_guess +
                0x0c + index_guess];
            g_updateRoot4597D8_guess->region_guess[
                g_updateRoot4597D8_guess->offset_guess->regionOffset_guess +
                0x0c + index_guess] = (unsigned char)original_guess->value_guess;
        }

        int displayValue_guess;
        char* digits_guess;
        char* localizedText_guess;
        if (original_guess->index_guess < 100) {
            displayValue_guess =
                ((UpdateRegion4597D8_guess*)&g_updateRoot4597D8_guess->region_guess[
                    g_updateRoot4597D8_guess->offset_guess->regionOffset_guess])
                    ->GetValue_guess(original_guess->index_guess);
        } else {
            displayValue_guess = g_updateRoot4597D8_guess->region_guess[
                g_updateRoot4597D8_guess->offset_guess->regionOffset_guess + 0x0c +
                index_guess];
        }
        digits_guess = _itoa(displayValue_guess, (char*)EQ_ARRAY(char, 0x0099DB00), 10);
        if (original_guess->index_guess < 100) {
            localizedText_guess = g_catalog452D85_guess->getString(
                *EQ_ARRAY(int*, 0x00851200)[original_guess->index_guess], 0);
        } else {
            localizedText_guess =
                ((ChannelTextResolver4595F7_guess*)pEverQuest)->Resolve_guess(
                    index_guess);
        }
        FormatNotice_guess(message_guess, 0x2f3b, localizedText_guess, digits_guess,
                           (const char*)zero_guess, zero_guess, zero_guess, zero_guess,
                           zero_guess, zero_guess, zero_guess);
        pEverQuest->dsp_chat(message_guess, 0x10e, 1);
        if ((int)pinstCSkillsWnd_guess != zero_guess) {
            pinstCSkillsWnd_guess->Handle_guess(original_guess->index_guess);
        }
        if ((int)g_updateProcessor4597D8_guess != zero_guess) {
            g_updateProcessor4597D8_guess->Apply_guess(original_guess->index_guess,
                                                       (int)argument_guess);
        }
        if ((int)g_updateNotifier4597D8_guess != zero_guess) {
            g_updateNotifier4597D8_guess->Notify_guess(original_guess->index_guess,
                                                       original_guess->value_guess);
        }
    }
}

// FUNCTION: TITANIUM 0x00459985
// Opcode 0xA2A: replaces all 512 spellbook slots, says "Your Spell Book has been updated!" and refreshes
// the gems (with +8 == 3 only the gem holding spell +4).
void __cdecl Handle_SpellBookUpdate_guess(Argument459985_guess* argument_guess) {
    if (g_indexedOwnerRoot459985_guess != 0) {
        int index_guess = 0;
        unsigned* value_guess = argument_guess->valuesC_guess;
        do {
            ((IndexedOwner_guess*)&g_indexedOwnerRoot459985_guess->region_guess[
                g_indexedOwnerRoot459985_guess->offset_guess->vbaseOffset_0004_guess])
                ->Set730_guess(index_guess, *value_guess);
            ++index_guess;
            ++value_guess;
        } while (index_guess < 0x200);

        pEverQuest->dsp_chat(
            g_catalog452D85_guess->getString(0x2349, 0), 0xD, 1);

        int index2_guess = 0;
        do {
            int result_guess =
                ((ValueAccessor459985_guess*)&g_indexedOwnerRoot459985_guess->region_guess[
                    g_indexedOwnerRoot459985_guess->offset_guess->vbaseOffset_0004_guess])
                    ->GetMemorizedSpell_guess(index2_guess);
            if (result_guess != -1) {
                if (argument_guess->value8_guess != 3 ||
                    argument_guess->value4_guess ==
                        ((ValueAccessor459985_guess*)&g_indexedOwnerRoot459985_guess->region_guess[
                            g_indexedOwnerRoot459985_guess->offset_guess->vbaseOffset_0004_guess])
                            ->GetMemorizedSpell_guess(index2_guess)) {
                    pinstCCastSpellWnd_guess->Update_guess(index2_guess);
                }
            }
            ++index2_guess;
        } while (index2_guess <= 8);

        if (pinstCCastSpellWnd_guess != 0) {
            pinstCCastSpellWnd_guess->Finish_guess();
        }
    }
}

struct ChatMessage459B94_guess {
    char target_guess[0x40];
    char sender_guess[0x40];
    unsigned channel_guess;  // language (ChannelMessage_Struct +0x80)
    int type_guess;  // channel number (+0x84)
    int value88_guess;
    unsigned char value8C_guess;
    int value90_guess;  // speaker's skill in the language
    char text_guess[0x800];
};

struct ChatRelay459B94_guess {
    char self_guess[0x40];
    char target_guess[0x40];
    char sender_guess[0x40];
    int type_guess;
    char text_guess[0x800];
};

struct CharBase459B94_guess {
    void* vftable_guess;
    int padding04_guess[2];
    BoundedArray_guess<unsigned char, 32> channels_guess;
    unsigned char padding2C_guess[0x10];
    char name_guess[0x40];
};

struct CharPrefix459B94_guess {
    void* vftable_guess;
    int field04_guess;
};

struct Char459B94_guess : CharPrefix459B94_guess, virtual CharBase459B94_guess {
};

struct Ignore459B94_guess {
    // EXTERNAL: TITANIUM 0x004F26C6 Ignore459B94_guess::Check_guess
    char Check_guess(const char* name_guess);
};

struct Chat459B94_guess {
    // EXTERNAL: TITANIUM 0x00496782 Chat459B94_guess::Show_guess
    void Show_guess(const char* text_guess, const char* sender_guess,
                    const char* target_guess, const char* prefix_guess, int color_guess,
                    int flag_guess);
};

// EXTERNAL: TITANIUM 0x00467AD1 AddNameToTellList_guess
void __cdecl AddNameToTellList_guess(const char* name_guess);

// EXTERNAL: TITANIUM 0x0060E550 strncmp
extern "C" int __cdecl strncmp(const char* first_guess, const char* second_guess,
                               unsigned count_guess);

// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* destination_guess, const char* source_guess);

#define g_char459B94_guess EQ_GLOBAL(Char459B94_guess*, 0x00905D00)
#define g_player459B94_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_ignore459B94_guess EQ_GLOBAL(Ignore459B94_guess*, 0x009917E4)
#define g_ignoreEnabled459B94_guess EQ_GLOBAL(unsigned char, 0x009254F4)
#define g_relayName459B94_guess EQ_ARRAY(char, 0x00923898)
#define g_gmQuiet459B94_guess EQ_GLOBAL(unsigned char, 0x0092419C)
struct IgnoreName459B94_guess {
    char name_guess[0x40];
};

#define g_ignoreNames459B94_guess EQ_ARRAY(IgnoreName459B94_guess, 0x0095BAB4)
#define g_afkText459B94_guess EQ_ARRAY(char, 0x00924688)

// FUNCTION: TITANIUM 0x00459B94
// @early-stop: budget, structural ndiff=239
// ChannelMessage_Struct; channel_guess is really the language and type_guess the channel number.
// The player's own tells come back as "You told %1, '%2'". Otherwise: relays to 0x33DC when a relay name
// is set, garbles by language skill, answers tells with the AFK reply (0x58A/0x58B) and formats by
// channel: 0/0x11 guild, 2 group, 3 shout, 4 auction, 5 OOC, 6 broadcast, 7/14 tell, 8 say,
// 10 petition, 11/0x12 GM say, 15 raid.
void __cdecl Handle_OP_ChannelMessage_guess(ChatMessage459B94_guess* argument_guess) {
    char prefix_guess[0x40];
    ChatMessage459B94_guess message_guess;
    char line_guess[0x840];
    ChatRelay459B94_guess relay_guess;
    memset(&relay_guess, 0, sizeof(relay_guess));
    int forced_guess = 0;
    memset(&message_guess, 0, sizeof(message_guess));
    message_guess.channel_guess = argument_guess->channel_guess;
    message_guess.value8C_guess = argument_guess->value8C_guess;
    message_guess.value90_guess = argument_guess->value90_guess;
    message_guess.type_guess = argument_guess->type_guess;
    strcpy(message_guess.sender_guess, argument_guess->sender_guess);
    strcpy(message_guess.target_guess, argument_guess->target_guess);
    strcpy(message_guess.text_guess, argument_guess->text_guess);

    // Our own message coming back: only tells (7 and the echo 14) show, as "You told %1, '%2'".
    if (__stricmp(message_guess.sender_guess, g_char459B94_guess->name_guess) == 0) {
        if (message_guess.type_guess != 7 && message_guess.type_guess != 14) {
            return;
        }
        if (FUN_00574830_guess(
                FUN_00574700_guess(
                    &message_guess.target_guess[(int)strlen(message_guess.target_guess) - 1]),
                0) != 0) {
            FormatNotice_guess(
                line_guess, 0x578,
                g_target4520E5Data_guess->GetText_guess(message_guess.target_guess),
                g_target4520E5Data_guess->GetText_guess(message_guess.text_guess),
                0, 0, 0, 0, 0, 0, 0);
        } else {
            if (g_ignoreEnabled459B94_guess != 0 &&
                g_ignore459B94_guess->Check_guess(message_guess.target_guess) != 0) {
                ((Chat459B94_guess*)pEverQuest)
                    ->Show_guess(message_guess.text_guess, message_guess.sender_guess,
                                 message_guess.target_guess, "", 0x134, 1);
                return;
            }
            FormatNotice_guess(line_guess, 0x578, message_guess.target_guess,
                               message_guess.text_guess, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(line_guess, 0x134, 1);
        return;
    }

    // With a relay name set, other people's messages are forwarded as 0x33DC.
    if (g_relayName459B94_guess[0] != 0) {
        strcpy(relay_guess.self_guess, g_relayName459B94_guess);
        strcpy(relay_guess.sender_guess, message_guess.sender_guess);
        strcpy(relay_guess.target_guess, message_guess.target_guess);
        strcpy(relay_guess.text_guess, message_guess.text_guess);
        relay_guess.type_guess = message_guess.type_guess;
        unsigned size_guess = strlen(relay_guess.text_guess) + 0xC9;
        if (__stricmp(message_guess.sender_guess, g_relayName459B94_guess) != 0 ||
            __stricmp(message_guess.target_guess, g_relayName459B94_guess) != 0) {
            EQSendMessage(g_messageBuffer_guess, 0x33DC, &relay_guess, size_guess, 1);
        }
    }

    // type_guess is EQEmu's ChatChannel: 0 guild, 2 group, 3 shout, 4 auction, 5 OOC, 6 broadcast, 7 tell, 8
    // say, 10 petition, 11 GMSay, 14 tell echo, 15 raid. Filtered channels 0-5 are dropped; petition and
    // GMSay reach GMs only (and not with GM quiet on).
    if (message_guess.type_guess < 6 &&
        g_randomSource454CCD_guess.Next_guess(message_guess.type_guess) == 1) {
        return;
    }
    if (message_guess.type_guess == 10 || message_guess.type_guess == 11) {
        if (g_player459B94_guess != 0 && g_player459B94_guess->GM == 0) {
            return;
        }
        if (g_player459B94_guess->GM != 0 && g_gmQuiet459B94_guess != 0) {
            return;
        }
    }
    if ((message_guess.type_guess == 0x11 || message_guess.type_guess == 0) &&
        g_randomSource454CCD_guess.Next_guess(0) == 1) {
        return;
    }

    EQPlayer* sender_guess = (EQPlayer*)ResolveTarget_guess(message_guess.sender_guess);
    if (sender_guess != 0 && sender_guess->GM != 0) {
        forced_guess = 1;
    }
    if (message_guess.type_guess != 6 && message_guess.type_guess != 14) {
        // The 100-name ignore list (not for broadcasts or tell echoes); a GM gets through and leaves the
        // list.
        for (int index_guess = 0; index_guess < 100; index_guess++) {
            if (FUN_00574950_guess(message_guess.sender_guess,
                                   g_ignoreNames459B94_guess[index_guess].name_guess) == 0) {
                if (sender_guess == 0 || sender_guess->GM == 0) {
                    return;
                }
                g_ignoreNames459B94_guess[index_guess].name_guess[0] = 0;
                forced_guess = 1;
                break;
            }
        }
    }

    int color_guess = 0x111;
    // Languages: unless a GM is involved, the text is garbled by our skill in its language and the listener
    // may learn a little.
    if (g_textMode454CCD_guess == 0 && g_player459B94_guess != 0 &&
        message_guess.type_guess != 6 && g_player459B94_guess->GM == 0 &&
        message_guess.type_guess != 14 && forced_guess == 0) {
        char converted_guess[0x800];
        SpeakBabel_guess(message_guess.text_guess, converted_guess,
                           message_guess.channel_guess, message_guess.value90_guess,
                           g_randomSource454CCD_guess.Next_guess(6));
        GarbleText_guess(converted_guess, message_guess.text_guess,
                           g_char459B94_guess->channels_guess[message_guess.channel_guess]);
    }

    // Common tongue has no prefix; otherwise "in <language>" once our skill is over 24, else 0x584 (an
    // unknown tongue).
    if (message_guess.channel_guess == 0) {
        prefix_guess[0] = 0;
    } else if (g_char459B94_guess->channels_guess[message_guess.channel_guess] > 0x18 ||
               message_guess.type_guess == 14 || forced_guess != 0) {
        FormatNotice_guess(prefix_guess, 0x583,
                           ((ChannelTextResolver4595F7_guess*)pEverQuest)
                               ->Resolve_guess(message_guess.channel_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        strcpy(prefix_guess, pStringTable->getString(0x584, 0));
    }

    switch (message_guess.type_guess) {
    case 0:
    case 0x11:
        color_guess = 0x103;
        FormatNotice_guess(line_guess, 0x587, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 2:
        color_guess = 0x102;
        FormatNotice_guess(line_guess, 0x586, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 3:
        color_guess = 0x106;
        FormatNotice_guess(line_guess, 0x58C, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 4:
        color_guess = 0x105;
        FormatNotice_guess(line_guess, 0x58D, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 5:
        color_guess = 0x104;
        FormatNotice_guess(line_guess, 0x58E, message_guess.sender_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 6:
        color_guess = 0x10D;
        FormatNotice_guess(line_guess, 0x585, message_guess.sender_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 7:
    case 14:
        AddNameToTellList_guess(message_guess.sender_guess);
        color_guess = 0x101;
        // A tell while AFK sends the AFK reply (0x58A, or 0x58B) back as OP_ChannelMessage, unless it is an
        // auto-reply itself.
        if (g_player459B94_guess->AFK != 0 &&
            strncmp(message_guess.text_guess, pStringTable->getString(0x589, 0),
                    strlen(pStringTable->getString(0x589, 0))) != 0 &&
            strncmp(message_guess.text_guess, pStringTable->getString(0x58A, 0),
                    strlen(pStringTable->getString(0x58A, 0))) != 0) {
            ChatMessage459B94_guess reply_guess;
            memset(&reply_guess, 0, sizeof(reply_guess));
            strcpy(reply_guess.sender_guess, g_player459B94_guess->Name);
            strcpy(reply_guess.target_guess, message_guess.sender_guess);
            if (g_afkText459B94_guess[0] != 0) {
                strcpy(reply_guess.text_guess, pStringTable->getString(0x58A, 0));
                strcat(reply_guess.text_guess, g_afkText459B94_guess);
            } else {
                strcpy(reply_guess.text_guess, pStringTable->getString(0x58B, 0));
            }
            reply_guess.type_guess = 7;
            reply_guess.channel_guess = g_target4520E5Data_guess->GetCurrentLanguage_guess();
            reply_guess.value90_guess =
                g_char459B94_guess->channels_guess[reply_guess.channel_guess];
            if (g_player459B94_guess->GM != 0) {
                reply_guess.value90_guess = 100;
            }
            EQSendMessage(g_messageBuffer_guess, OP_ChannelMessage, &reply_guess,
                          strlen(reply_guess.text_guess) + 0x99, 1);
        }
        if (g_ignoreEnabled459B94_guess != 0 &&
            g_ignore459B94_guess->Check_guess(message_guess.sender_guess) != 0) {
            ((Chat459B94_guess*)pEverQuest)
                ->Show_guess(message_guess.text_guess, message_guess.sender_guess,
                             message_guess.sender_guess, prefix_guess, color_guess, 1);
            return;
        }
        FormatNotice_guess(line_guess, 0x588, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 8:
        color_guess = 0x100;
        FormatNotice_guess(line_guess, 0x582,
                           g_target4520E5Data_guess->GetText_guess(message_guess.sender_guess),
                           prefix_guess, message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    case 10:
        color_guess = 0xF;
        FormatNotice_guess(line_guess, 0x58F, message_guess.sender_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 11:
    case 0x12:
        color_guess = 0x116;
        FormatNotice_guess(line_guess, 0x591, message_guess.sender_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 15:
        color_guess = 0x147;
        FormatNotice_guess(line_guess, 0x13F8, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    default:
        FormatNotice_guess(line_guess, 0x582, message_guess.sender_guess, prefix_guess,
                           message_guess.text_guess, 0, 0, 0, 0, 0, 0);
        break;
    }
    pEverQuest->dsp_chat(line_guess, color_guess, 1);
}

struct Item45A817_guess {
    virtual ~Item45A817_guess();
    unsigned char padding04_guess[0x44];
    int value48_guess;
    int slot4C_guess;

    // EXTERNAL: TITANIUM 0x005ECC00 Item45A817_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Item45A817_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC760 Item45A817_guess::IsStackable_guess
    bool IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005E39A0 Item45A817_guess::GetName_guess
    void GetName_guess(char* buffer_guess, int size_guess);
    // EXTERNAL: TITANIUM 0x005DFC40 Item45A817_guess::IsContainer_guess
    bool IsContainer_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Item45A817_guess::GetSlotCount_guess
    int GetSlotCount_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 Item45A817_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Item45A817_guess::GetContent_guess
    Item45A817_guess* GetContent_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC640 Item45A817_guess::SetContent_guess
    void SetContent_guess(int index_guess, Item45A817_guess* item_guess);
};

struct CharInfoFlags45A817_guess {
    unsigned char padding00_guess[0x78];
    int value78_guess;
};

struct CharInfo45A817_guess {
    unsigned char padding00_guess[0x10];
    CharInfoFlags45A817_guess flags10_guess;

    CharInfoFlags45A817_guess* GetFlags_guess() { return &flags10_guess; }
};

struct Inventory45A817_guess : EQ_Character {
    // EXTERNAL: TITANIUM 0x004167E2 Inventory45A817_guess::CheckUpdate_guess
    int CheckUpdate_guess();
    // EXTERNAL: TITANIUM 0x0040CC50 Inventory45A817_guess::GetItem_guess
    Item45A817_guess* GetItem_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 Inventory45A817_guess::SetItem_guess
    void SetItem_guess(int slot_guess, Item45A817_guess* item_guess);
    // EXTERNAL: TITANIUM 0x0040CC6B Inventory45A817_guess::GetBankItem_guess
    Item45A817_guess* GetBankItem_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x00434792 Inventory45A817_guess::SetTributeItem_guess
    void SetTributeItem_guess(int slot_guess, Item45A817_guess* item_guess);
};

struct SharedBank45A817_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual Item45A817_guess* GetItem_guess(int slot_guess);
    unsigned char padding04_guess[8];
    unsigned char dirty0C_guess;

    // EXTERNAL: TITANIUM 0x004212B3 SharedBank45A817_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00417DAF SharedBank45A817_guess::IsReady_guess
    int IsReady_guess();
};

struct RootPrefix45A817_guess {
    void* vftable_guess;
    int field04_guess;
};

struct Root45A817_guess : RootPrefix45A817_guess, virtual Inventory45A817_guess {
    unsigned char padding0C_guess[0xCF0 - 0x0C];
    BoundedArray_guess<Item45A817_guess*, 16> bagsCF0_guess;
    BoundedArray_guess<Item45A817_guess*, 2> bagsD30_guess;
    unsigned char paddingD38_guess[0xC280 - 0xD38];
    SharedBank45A817_guess bankC280_guess;
    unsigned char paddingC290_guess[0xC348 - 0xC290];
    unsigned char valueC348_guess;
    unsigned char paddingC349_guess[0xC384 - 0xC349];

    // EXTERNAL: TITANIUM 0x004BD9B8 Root45A817_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x004B9741 Root45A817_guess::LoadBaseProfile_guess
    void LoadBaseProfile_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x004B9111 Root45A817_guess::UpdateZoneEnvironment_guess
    void UpdateZoneEnvironment_guess();
    // EXTERNAL: TITANIUM 0x005EE500 Root45A817_guess::HasIndex_guess
    int HasIndex_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005F0E20 Root45A817_guess::SetSharedItem_guess
    void SetSharedItem_guess(int slot_guess, Item45A817_guess* item_guess);
};

struct Display45A817_guess {
    // EXTERNAL: TITANIUM 0x00496DCD Display45A817_guess::ReleasePendingRequest_guess
    void ReleasePendingRequest_guess(int mode_guess);
    // EXTERNAL: TITANIUM 0x004966EE Display45A817_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x004982C6 Display45A817_guess::dsp_chat
    void dsp_chat(const char* message_guess, int category_guess, bool flag_guess);
    // EXTERNAL: TITANIUM 0x00497F42 Display45A817_guess::RefreshWornAppearance_guess
    void RefreshWornAppearance_guess(int slot_guess);
};

struct DispatchCallC0_45AFDC_guess : Target4521Dispatch_guess {
    virtual void Slot8C_guess() = 0;
    virtual void Slot90_guess() = 0;
    virtual void Slot94_guess() = 0;
    virtual void Slot98_guess() = 0;
    virtual void Slot9C_guess() = 0;
    virtual void SlotA0_guess() = 0;
    virtual void SlotA4_guess() = 0;
    virtual void SlotA8_guess() = 0;
    virtual void SlotAC_guess() = 0;
    virtual void SlotB0_guess() = 0;
    virtual void SlotB4_guess() = 0;
    virtual void SlotB8_guess() = 0;
    virtual void SlotBC_guess() = 0;
    virtual void ApplyC0_guess(unsigned value_guess, int flag_guess) = 0;
};

struct DispatchCall1A4_45AFDC_guess : DispatchCallC0_45AFDC_guess {
    virtual void SlotC4_guess() = 0;
    virtual void SlotC8_guess() = 0;
    virtual void SlotCC_guess() = 0;
    virtual void SlotD0_guess() = 0;
    virtual void SlotD4_guess() = 0;
    virtual void SlotD8_guess() = 0;
    virtual void SlotDC_guess() = 0;
    virtual void SlotE0_guess() = 0;
    virtual void SlotE4_guess() = 0;
    virtual void SlotE8_guess() = 0;
    virtual void SlotEC_guess() = 0;
    virtual void SlotF0_guess() = 0;
    virtual void SlotF4_guess() = 0;
    virtual void SlotF8_guess() = 0;
    virtual void SlotFC_guess() = 0;
    virtual void Slot100_guess() = 0;
    virtual void Slot104_guess() = 0;
    virtual void Slot108_guess() = 0;
    virtual void Slot10C_guess() = 0;
    virtual void Slot110_guess() = 0;
    virtual void Slot114_guess() = 0;
    virtual void Slot118_guess() = 0;
    virtual void Slot11C_guess() = 0;
    virtual void Slot120_guess() = 0;
    virtual void Slot124_guess() = 0;
    virtual void Slot128_guess() = 0;
    virtual void Slot12C_guess() = 0;
    virtual void Slot130_guess() = 0;
    virtual void Slot134_guess() = 0;
    virtual void Slot138_guess() = 0;
    virtual void Slot13C_guess() = 0;
    virtual void Slot140_guess() = 0;
    virtual void Slot144_guess() = 0;
    virtual void Slot148_guess() = 0;
    virtual void Slot14C_guess() = 0;
    virtual void Slot150_guess() = 0;
    virtual void Slot154_guess() = 0;
    virtual void Slot158_guess() = 0;
    virtual void Slot15C_guess() = 0;
    virtual void Slot160_guess() = 0;
    virtual void Slot164_guess() = 0;
    virtual void Slot168_guess() = 0;
    virtual void Slot16C_guess() = 0;
    virtual void Slot170_guess() = 0;
    virtual void Slot174_guess() = 0;
    virtual void Slot178_guess() = 0;
    virtual void Slot17C_guess() = 0;
    virtual void Slot180_guess() = 0;
    virtual void Slot184_guess() = 0;
    virtual void Slot188_guess() = 0;
    virtual void Slot18C_guess() = 0;
    virtual void Slot190_guess() = 0;
    virtual void Slot194_guess() = 0;
    virtual void Slot198_guess() = 0;
    virtual void Slot19C_guess() = 0;
    virtual void Slot1A0_guess() = 0;
    virtual void Apply1A4_guess(int code_guess, int value_guess, int flag_guess) = 0;
};

struct RemoteValues45AFDC_guess {
    DispatchCall1A4_45AFDC_guess* object_guess;
    unsigned char padding04_guess[0xFB4 - 4];
    int valueFB4_guess;
    int valueFB8_guess;
};

struct ResolvedTarget45AFDC_guess {
    unsigned char padding00_guess[0x1A8];
    RemoteValues45AFDC_guess* value1A8_guess;
};

struct PacketData45AFDC_guess {
    unsigned char padding00_guess[0x185];
    unsigned char after185_guess[0x340D - 0x185];
    char after340D_guess[1];
};

struct RootDispatch45AFDC_guess {
    virtual void HandleS2CRaidMessage_guess() = 0;
};

struct StreamManager45AFDC_guess {
    // EXTERNAL: TITANIUM 0x004FAABA StreamManager45AFDC_guess::Reset_guess
    void Reset_guess();
};

struct UpdateEntry45AFDC_guess {
    // EXTERNAL: TITANIUM 0x00518E4E UpdateEntry45AFDC_guess::Apply_guess
    void Apply_guess(unsigned value_guess);
};

struct UpdateManager45AFDC_guess {
    // EXTERNAL: TITANIUM 0x0051B201 UpdateManager45AFDC_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x0051A84D UpdateManager45AFDC_guess::FindInvSlot
    UpdateEntry45AFDC_guess* FindInvSlot(int index_guess);
};

struct AnimationManager45AFDC_guess {
    // EXTERNAL: TITANIUM 0x00518BF3 AnimationManager45AFDC_guess::Refresh_guess
    void Refresh_guess();
};

struct UpdateReady45AFDC_guess {
    // EXTERNAL: TITANIUM 0x00469DD7 UpdateReady45AFDC_guess::Initialize_guess
    void Initialize_guess();
};

#define g_streamManager45AFDC_guess EQ_GLOBAL(StreamManager45AFDC_guess*, 0x00850CBC)
#define pinstCInvSlotMgr_guess EQ_GLOBAL(UpdateManager45AFDC_guess*, 0x00850CB8)
#define pinstCInventoryWnd_guess EQ_GLOBAL(AnimationManager45AFDC_guess*, 0x00850C34)
#define pinstCCursorAttachment_guess EQ_GLOBAL(Target4521Dispatch_guess*, 0x00850C24)
#define g_updateReady45AFDC_guess EQ_GLOBAL(UpdateReady45AFDC_guess*, 0x00850BD0)

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

struct Merchant45A817_guess {
    // EXTERNAL: TITANIUM 0x00569FA8 Merchant45A817_guess::AddEqItemToHisTradeArray_guess
    int AddEqItemToHisTradeArray_guess(Item45A817_guess* item_guess);
};

struct Trade45A817_guess {
    // EXTERNAL: TITANIUM 0x00537691 Trade45A817_guess::Add_guess
    void Add_guess(Item45A817_guess* item_guess);
};

struct Loot45A817_guess {
    // EXTERNAL: TITANIUM 0x0052B35F Loot45A817_guess::Add_guess
    void Add_guess(Item45A817_guess* item_guess);
};

struct Tribute45A817_guess {
    // EXTERNAL: TITANIUM 0x004FA6B6 Tribute45A817_guess::Set_guess
    void Set_guess(Item45A817_guess* item_guess, int slot_guess);
};

struct DisplayState45A817_guess {
    unsigned char padding00_guess[0x10];
    unsigned char dirty10_guess;
};

#define g_root45A817_guess EQ_GLOBAL(Root45A817_guess*, 0x00905D00)
#define g_display45A817_guess EQ_GLOBAL(Display45A817_guess*, 0x00988DF0)
#define g_merchant45A817_guess EQ_GLOBAL(Merchant45A817_guess*, 0x00850C50)
#define g_trade45A817_guess EQ_GLOBAL(Trade45A817_guess*, 0x00850C4C)
#define g_loot45A817_guess EQ_GLOBAL(Loot45A817_guess*, 0x00850C40)
#define g_tribute45A817_guess EQ_GLOBAL(Tribute45A817_guess*, 0x00850CBC)
#define g_spawn45A817_guess EQ_GLOBAL(EQPlayer*, 0x00905CE0)
#define g_displayState45A817_guess EQ_GLOBAL(DisplayState45A817_guess*, 0x00905D24)
#define g_weatherPending45A817_guess EQ_GLOBAL(int, 0x00923D24)
#define g_savePending45A817_guess EQ_GLOBAL(int, 0x009238F8)

// EXTERNAL: TITANIUM 0x00574110 LogItem45A817_guess
void __cdecl LogItem45A817_guess(const char* format_guess, ...);

struct Message4594A3_guess {
    int value_guess;
    int field4_guess;
    int field8_guess;
};

struct FoundBase4594A3_guess {
    unsigned char padding00_guess[0x10];
};

struct FoundSub4594A3_guess {
    unsigned char padding00_guess[0x78];
    Item45A817_guess* item78_guess;
};

struct Found4594A3_guess : FoundBase4594A3_guess, FoundSub4594A3_guess {
};

struct EQ_CharacterProfileView6_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView6_guess::GetCharInfo2
    Found4594A3_guess* GetCharInfo2();
};

struct Owner4594A3_guess {
    unsigned char padding00_guess[4];
    EQ_CharacterProfileView6_guess locator_guess;
};

struct SlotArray4594A3_guess {
    Item45A817_guess* values_guess[0x24];

    Item45A817_guess* GetValue_guess(unsigned index_guess) {
        if (index_guess >= 0x24) {
            __debugbreak();
        }
        return values_guess[index_guess];
    }
};

struct Settings4594A3_guess {
    unsigned char padding00_guess[0xd38];
    SlotArray4594A3_guess slots_guess;
};

// FUNCTION: TITANIUM 0x004594A3
// @early-stop: budget, structural ndiff=75
// Puts the item in the first free of the 36 cursor-queue slots. Without `flag_guess`, an item already on
// the cursor or queued is refused by sending MoveItem {slot, -1, 0} (0x420F) to delete the copy.
bool __cdecl AddItemToCursorQueue_guess(Item45A817_guess* setting_guess, char flag_guess) {
    bool result_guess = false;

    if (setting_guess == 0) {
        return false;
    }
    if (flag_guess == 0) {
        bool matched_guess = false;
        if (g_propertyOwnerGlobal_guess != 0) {
            Found4594A3_guess* found_guess =
                ((Owner4594A3_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                     g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                    ->locator_guess.GetCharInfo2();
            if (found_guess->item78_guess != 0) {
                Found4594A3_guess* found2_guess =
                    ((Owner4594A3_guess*)&g_propertyOwnerGlobal_guess->embedded_guess[
                         g_propertyOwnerGlobal_guess->vbtable_0008_guess->vbaseOffset_0004_guess])
                        ->locator_guess.GetCharInfo2();
                matched_guess = found2_guess->item78_guess->GetItemId_guess() ==
                                setting_guess->GetItemId_guess();
            }
        }
        if (!matched_guess) {
            for (unsigned index_guess = 0; index_guess < 0x24; ++index_guess) {
                Settings4594A3_guess* settings_guess = (Settings4594A3_guess*)g_propertyOwnerGlobal_guess;
                if (settings_guess->slots_guess.GetValue_guess(index_guess) != 0 &&
                    settings_guess->slots_guess.GetValue_guess(index_guess)->slot4C_guess < 30000 &&
                    settings_guess->slots_guess.GetValue_guess(index_guess)->GetItemId_guess() ==
                        setting_guess->GetItemId_guess()) {
                    matched_guess = true;
                    break;
                }
            }
        }
        if (matched_guess) {
            Message4594A3_guess message_guess;

            message_guess.value_guess = setting_guess->slot4C_guess;
            message_guess.field4_guess = -1;
            message_guess.field8_guess = 0;
            EQSendMessage(g_messageBuffer_guess, OP_MoveItem, &message_guess, 0xc, 1);
            return false;
        }
    }
    for (unsigned index_guess = 0; index_guess < 0x24; ++index_guess) {
        Settings4594A3_guess* settings_guess = (Settings4594A3_guess*)g_propertyOwnerGlobal_guess;
        if (settings_guess->slots_guess.GetValue_guess(index_guess) == 0) {
            ((Settings_guess*)g_propertyOwnerGlobal_guess)
                ->SetD38_guess(index_guess, (unsigned)setting_guess);
            result_guess = true;
            break;
        }
    }
    return result_guess;
}

// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(Root45A817_guess* root_guess);

struct Value45A74B_guess {
    unsigned char padding00_guess[0x98];
    int value98_guess;

    // EXTERNAL: TITANIUM 0x005ECCC0 Value45A74B_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005E0F30 Value45A74B_guess::GetItemId_guess
    int GetItemId_guess();

    // EXTERNAL: TITANIUM 0x005EC630 Value45A74B_guess::GetAt_guess
    Value45A74B_guess* GetAt_guess(int index_guess);
};

struct IndexedOwner45A74B_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 IndexedOwner45A74B_guess::Get_guess
    Value45A74B_guess* Get_guess(int index_guess);
};

struct Argument45A74B_guess {
    int value0_guess;
    int value4_guess;
    int value8_guess;
};

struct IndexedOwnerRoot45A74B_guess {
    unsigned char padding00_guess[8];
    union {
        PropertyOwnerOffset_guess* offset_guess;
        unsigned char region_guess[0xC278];
    };
    unsigned char paddingC280_guess[0xC];
    unsigned char valueC28C_guess;
    unsigned char paddingC28D_guess[0xBB];
    unsigned char valueC348_guess;
};

#define g_indexedOwnerRoot45A74B_guess EQ_GLOBAL(IndexedOwnerRoot45A74B_guess*, 0x00905D00)

struct ResetItem45A4A5_guess {
    virtual ~ResetItem45A4A5_guess();
};

struct ResetOffset45A4A5_guess {
    unsigned char padding00_guess[4];
    int value4_guess;
};

struct ResetByte45A4A5_guess {
    unsigned char value0_guess;
};

struct ResetState45A4A5_guess {
    unsigned char padding00_guess[0x11D4];
    int platinum_11d4_guess;
    int gold_11d8_guess;
    int silver_11dc_guess;
    int copper_11e0_guess;
    int cursorPlatinum_11e4_guess;
    int cursorGold_11e8_guess;
    int cursorSilver_11ec_guess;
    int cursorCopper_11f0_guess;
};

struct EQ_CharacterProfileView7_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView7_guess::GetCharInfo2
    ResetState45A4A5_guess* GetCharInfo2();
};

struct ResetArray45A4A5_guess {
    unsigned char padding00_guess[4];
    EQ_CharacterProfileView7_guess control_guess;
    unsigned char padding05_guess[0x13C - 5];
    int value13C_guess;
    int value140_guess;
    int value144_guess;
    int value148_guess;

    // EXTERNAL: TITANIUM 0x0040CC50 ResetArray45A4A5_guess::Get_guess
    ResetItem45A4A5_guess* Get_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x0041AA84 ResetArray45A4A5_guess::Set_guess
    void Set_guess(int index_guess, int value_guess);
};

struct ResetRoot45A4A5_guess {
    unsigned char padding00_guess[8];
    union {
        ResetOffset45A4A5_guess* vbtable_0008_guess;
        ResetByte45A4A5_guess storage08_guess[0xCE8];
    };
    BoundedArray_guess<unsigned char, 0x40> cleanupBytesCF0_guess;
};

#define g_resetRoot45A4A5_guess EQ_GLOBAL(ResetRoot45A4A5_guess*, 0x00905D00)
#define pinstCQuantityWnd_guess EQ_GLOBAL(ResetProbe45A4A5_guess*, 0x00850C3C)
#define g_resetProbeTwo45A4A5_guess EQ_GLOBAL(ResetProbe45A4A5_guess*, 0x00850BA8)
#define g_resetProbeThree45A4A5_guess EQ_GLOBAL(ResetProbe45A4A5_guess*, 0x00850BA4)
#define g_resetCleanup45A4A5_guess EQ_GLOBAL(ResetCleanup45A4A5_guess*, 0x00850CBC)
#define g_resetFinalizer45A4A5_guess EQ_GLOBAL(ResetFinalizer45A4A5_guess*, 0x00988DF0)
#define g_resetSetting45A4A5_guess EQ_GLOBAL(ResetSetting45A4A5_guess*, 0x00905D24)
#define g_resetCode45A4A5_guess EQ_GLOBAL(unsigned, 0x00923D94)

struct ResetProbe45A4A5_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual void Slot88_guess() = 0;

    // EXTERNAL: TITANIUM 0x0059DD30 ResetProbe45A4A5_guess::IsEnabled_guess
    bool IsEnabled_guess();
};

struct ResetCleanup45A4A5_guess {
    // EXTERNAL: TITANIUM 0x004FAABA ResetCleanup45A4A5_guess::Reset_guess
    void Reset_guess();
};

struct ResetFinalizer45A4A5_guess {
    // EXTERNAL: TITANIUM 0x00497F42 ResetFinalizer45A4A5_guess::Finish_guess
    void Finish_guess(int value_guess);
};

struct ResetSetting45A4A5_guess {
    unsigned char padding00_guess[0x10];
    unsigned char value10_guess;
    unsigned char value11_guess;
};

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
int __cdecl strcmp(const char* first_guess, const char* second_guess);

// FUNCTION: TITANIUM 0x0045A4A5
// @early-stop: budget, structural ndiff=29
// Opcode 0x6136 for the player: closes three windows, empties inventory and coins, then sends 0x5027.
void __cdecl ClearOwnInventoryAndCoins_guess(char* name_guess) {
    if (g_resetRoot45A4A5_guess == 0 ||
        EQ_GLOBAL(DispatchTarget_guess*, 0x00905CE4) == 0) {
        return;
    }
    if (strcmp(name_guess,
               EQ_GLOBAL(DispatchTarget_guess*, 0x00905CE4)->name_0120_guess) != 0) {
        return;
    }

    if (pinstCQuantityWnd_guess->IsEnabled_guess() != 0) {
        pinstCQuantityWnd_guess->Slot88_guess();
    }
    if (g_resetProbeTwo45A4A5_guess->IsEnabled_guess() != 0) {
        g_resetProbeTwo45A4A5_guess->Slot88_guess();
    }
    if (g_resetProbeThree45A4A5_guess->IsEnabled_guess() != 0) {
        g_resetProbeThree45A4A5_guess->Slot88_guess();
    }

    g_resetCleanup45A4A5_guess->Reset_guess();
    g_resetFinalizer45A4A5_guess->Finish_guess(-1);

    for (int index_guess = 0; index_guess <= 0x1D; ++index_guess) {
        if (((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
                 g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
                ->Get_guess(index_guess) != 0) {
            ResetItem45A4A5_guess* item_guess =
                ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
                    g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
                    ->Get_guess(index_guess);
            if (item_guess != 0) {
                delete item_guess;
            }
            ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
                 g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
                ->Set_guess(index_guess, 0);
        }
    }

    UpdateLight_guess((Root45A817_guess*)g_resetRoot45A4A5_guess);

    for (int offset_guess = 0; offset_guess < 0x40; offset_guess += 4) {
        ResetItem45A4A5_guess* item_guess =
            *(ResetItem45A4A5_guess**)&
                g_resetRoot45A4A5_guess->cleanupBytesCF0_guess[offset_guess];
        if (item_guess != 0) {
            delete item_guess;
        }
        *(ResetItem45A4A5_guess**)&
            g_resetRoot45A4A5_guess->cleanupBytesCF0_guess[offset_guess] = 0;
    }

    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->gold_11d8_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->platinum_11d4_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->silver_11dc_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->copper_11e0_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->value140_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->value148_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->value144_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->value13C_guess = 0;
    g_resetSetting45A4A5_guess->value10_guess = 0;
    g_resetSetting45A4A5_guess->value11_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->cursorGold_11e8_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->cursorPlatinum_11e4_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->cursorSilver_11ec_guess = 0;
    ((ResetArray45A4A5_guess*)&g_resetRoot45A4A5_guess->storage08_guess[
         g_resetRoot45A4A5_guess->vbtable_0008_guess->value4_guess])
        ->control_guess.GetCharInfo2()->cursorCopper_11f0_guess = 0;

    g_resetCode45A4A5_guess = 0x10;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x5027, 0, 0, 1);
}

// FUNCTION: TITANIUM 0x0045A74B
// @early-stop: budget, diff ndiff=16
// Opcode 0x2DD2 {item id, ?, value}: sets +0x98 on every carried item (and bag content) with that id.
void __cdecl SetInventoryItemValue98_guess(unsigned argument_guess) {
    Argument45A74B_guess* arg_guess = (Argument45A74B_guess*)argument_guess;
    for (int index_guess = 0; index_guess < 0x1F; ++index_guess) {
        Value45A74B_guess* value_guess =
            ((IndexedOwner45A74B_guess*)&g_indexedOwnerRoot45A74B_guess->region_guess[
                g_indexedOwnerRoot45A74B_guess->offset_guess->vbaseOffset_0004_guess])
                ->Get_guess(index_guess);
        if (value_guess != 0) {
            if (value_guess->GetItemClass_guess() == 0) {
                if (value_guess->GetItemId_guess() == arg_guess->value0_guess) {
                    value_guess->value98_guess = arg_guess->value8_guess;
                }
                for (argument_guess = 0; (int)argument_guess < 10;
                     argument_guess = argument_guess + 1) {
                    if (value_guess->GetAt_guess(argument_guess) != 0) {
                        if (value_guess->GetAt_guess(argument_guess)->GetItemClass_guess() == 0) {
                            if (value_guess->GetAt_guess(argument_guess)->GetItemId_guess() ==
                                arg_guess->value0_guess) {
                                int storedValue_guess = arg_guess->value8_guess;
                                value_guess->GetAt_guess(argument_guess)->value98_guess =
                                    storedValue_guess;
                            }
                        }
                    }
                }
            }
        }
    }

    g_indexedOwnerRoot45A74B_guess->valueC28C_guess = 1;
    g_indexedOwnerRoot45A74B_guess->valueC348_guess = 0;
}

// Places an item that arrived in an item packet (`value_guess`) by the packet's kind (`mode_guess`).
// FUNCTION: TITANIUM 0x0045A817
// @early-stop: budget, structural ndiff=452
// OP_ItemPacket by EQEmu's ItemPacketType: 0x64 merchant, 0x65 trade offer ("%1 has offered you a %2"),
// 0x66 loot, 0x67 trade / 0x69 character inventory (into its slot), 0x6A summoned (cursor queue),
// 0x6B world container, 0x6C tribute (slots 400-404), 0x6D guild tribute (450-451), 0x6E replace in place.
// The globals are named backwards: g_trade45A817_guess (0x00850C4C) is the merchant window,
// g_merchant45A817_guess (0x00850C50) the trade window, g_tribute45A817_guess the world container.
void __cdecl PlaceReceivedItem_guess(int mode_guess, int value_guess) {
    char unused_guess[0x5C];
    char name_guess[0x100];
    char message_guess[0x100];

    memset(unused_guess, 0, sizeof(unused_guess));
    Item45A817_guess* item_guess = (Item45A817_guess*)value_guess;
    if (item_guess == 0) {
        return;
    }
    // Bad items are dropped: type 0xD or no count (string 1366), a stackable without charges (1368).
    if (item_guess->GetItemType_guess() == 0xD || item_guess->GetItemId_guess() < 1) {
        g_display45A817_guess->dsp_chat(
            pStringTable->getString(0x556, 0), 0xD, 1);
        delete item_guess;
        return;
    }
    if (item_guess->IsStackable_guess() && item_guess->value48_guess <= 0) {
        FormatNotice_guess(message_guess, 0x558,
                           _itoa(item_guess->GetItemId_guess(), EQ_ARRAY(char, 0x0099DB00), 10),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_display45A817_guess->dsp_chat(message_guess, 0xD, 1);
        delete item_guess;
        return;
    }

    int slot_guess = item_guess->slot4C_guess;
    // Kinds: 100 and 0x65 two offer windows (0x65 also announces the offer, string 9028), 0x66 loot,
    // 0x67 a new item into the inventory and 0x69 the login inventory, 0x6A placed by 0x004594A3, 0x6B the
    // tribute slots, 0x6C (slots 400-404) and 0x6D (450-451) the 5- and 2-entry extra item lists that
    // 0x004212B3 counts, 0x6E an in-place replacement.
    switch (mode_guess) {
    case 100:
        g_trade45A817_guess->Add_guess(item_guess);
        break;
    case 0x65:
        if (g_merchant45A817_guess->AddEqItemToHisTradeArray_guess(item_guess) != 0) {
            item_guess->GetName_guess(name_guess, 0x100);
            FormatNotice_guess(message_guess, 0x2344, g_spawn45A817_guess->Name, name_guess,
                               0, 0, 0, 0, 0, 0, 0);
            g_display45A817_guess->dsp_chat(message_guess, 10, 1);
        }
        break;
    case 0x66:
        g_loot45A817_guess->Add_guess(item_guess);
        break;
    case 0x67:
    case 0x69:
        if (mode_guess == 0x69) {
            if (g_weatherPending45A817_guess != 0 || g_savePending45A817_guess != 0) {
                delete item_guess;
                LogItem45A817_guess(
                    "Error, received weather or tried to save before finished receiving items.");
                return;
            }
            LogItem45A817_guess("Received an item via EQI_STARTING_ITEM at loc %d", slot_guess);
        }
        if (slot_guess < InvSlot_PossessionsCount) {
            g_root45A817_guess->SetItem_guess(slot_guess, item_guess);
            if (mode_guess == 0x67) {
                g_noticeRenderer_guess->Show_guess(0x92, 0);
            }
            if (slot_guess > 0 && slot_guess < InvSlot_Ammo && mode_guess != 0x69) {
                g_display45A817_guess->RefreshWornAppearance_guess(slot_guess);
            }
        } else if (slot_guess <= 0x155) {
            int group_guess = (slot_guess - 0x1F) / 10;
            int index_guess = (slot_guess - 0x1F) % 10;
            Item45A817_guess* bag_guess;
            if (g_root45A817_guess->GetItem_guess(group_guess) == 0 ||
                g_root45A817_guess->GetItem_guess(group_guess)->GetItemClass_guess() != 1 ||
                (bag_guess = g_root45A817_guess->GetItem_guess(group_guess)) == 0) {
                delete item_guess;
                return;
            }
            bag_guess->SetContent_guess(index_guess, item_guess);
            if (mode_guess == 0x67) {
                g_noticeRenderer_guess->Show_guess(0x92, 0);
            }
        } else if (slot_guess >= 2000 && slot_guess < 0x7E0) {
            ((Settings_guess*)g_root45A817_guess)
                ->Set586d7_guess(slot_guess - 2000, (unsigned)item_guess);
        } else if (slot_guess >= 0x7EF && slot_guess < 0x88F) {
            int group_guess = (slot_guess - 0x7EF) / 10;
            int index_guess = (slot_guess - 0x7EF) % 10;
            Item45A817_guess* bag_guess;
            if (g_root45A817_guess->bagsCF0_guess[group_guess] == 0 ||
                g_root45A817_guess->bagsCF0_guess[group_guess]->GetItemClass_guess() != 1 ||
                (bag_guess = g_root45A817_guess->bagsCF0_guess[group_guess]) == 0) {
                delete item_guess;
                return;
            }
            bag_guess->SetContent_guess(index_guess, item_guess);
        } else if (slot_guess >= 0x9C4 && slot_guess < 0x9C6) {
            ((Settings_guess*)g_root45A817_guess)
                ->Set586ef_guess(slot_guess - 0x9C4, (unsigned)item_guess);
        } else if (slot_guess >= 0x9E3 && slot_guess < 0x9F7) {
            int group_guess = (slot_guess - 0x9E3) / 10;
            int index_guess = (slot_guess - 0x9E3) % 10;
            Item45A817_guess* bag_guess;
            if (g_root45A817_guess->bagsD30_guess[group_guess] == 0 ||
                g_root45A817_guess->bagsD30_guess[group_guess]->GetItemClass_guess() != 1 ||
                (bag_guess = g_root45A817_guess->bagsD30_guess[group_guess]) == 0) {
                delete item_guess;
                return;
            }
            bag_guess->SetContent_guess(index_guess, item_guess);
        } else {
            delete item_guess;
            return;
        }
        break;
    case 0x6A:
        if (!AddItemToCursorQueue_guess(item_guess, 1)) {
            delete item_guess;
        }
        break;
    case 0x6B:
        if (slot_guess >= 0 && slot_guess < 10) {
            g_tribute45A817_guess->Set_guess(item_guess, slot_guess);
        }
        break;
    case 0x6C:
        if (g_root45A817_guess != 0) {
            slot_guess -= 400;
            if (slot_guess < 5) {
                if (g_root45A817_guess->GetBankItem_guess(slot_guess) != 0) {
                    delete g_root45A817_guess->GetBankItem_guess(slot_guess);
                }
                g_root45A817_guess->SetTributeItem_guess(slot_guess, item_guess);
            }
        }
        break;
    case 0x6D:
        if (g_root45A817_guess != 0) {
            slot_guess -= 0x1C2;
            if (slot_guess < 2) {
                if (g_root45A817_guess->bankC280_guess.GetItem_guess(slot_guess) != 0) {
                    delete g_root45A817_guess->bankC280_guess.GetItem_guess(slot_guess);
                }
                g_root45A817_guess->SetSharedItem_guess(slot_guess, item_guess);
            }
        }
        break;
    case 0x6E:
        if (slot_guess < InvSlot_PossessionsCount) {
            delete g_root45A817_guess->GetItem_guess(slot_guess);
            g_root45A817_guess->SetItem_guess(slot_guess, item_guess);
            if (slot_guess >= 0 && slot_guess <= InvSlot_Ammo) {
                g_display45A817_guess->RefreshWornAppearance_guess(slot_guess);
            }
        } else if (slot_guess <= 0x155) {
            int index_guess = (slot_guess - 0x1F) % 10;
            Item45A817_guess* bag_guess =
                g_root45A817_guess->GetItem_guess((slot_guess - 0x1F) / 10);
            if (bag_guess != 0 && bag_guess->IsContainer_guess() &&
                index_guess < bag_guess->GetSlotCount_guess()) {
                delete bag_guess->GetContent_guess(index_guess);
                bag_guess->SetContent_guess(index_guess, item_guess);
            }
        }
        break;
    }

    // Inventory kinds mark the character's item totals dirty for the next stat rebuild.
    if (g_root45A817_guess != 0 &&
        (mode_guess == 0x67 || mode_guess == 0x69 || mode_guess == 0x65 ||
         mode_guess == 0x6C || mode_guess == 0x6D || mode_guess == 0x6E)) {
        g_root45A817_guess->bankC280_guess.dirty0C_guess = 1;
        g_root45A817_guess->valueC348_guess = 0;
        if (mode_guess == 0x69) {
            g_root45A817_guess->bankC280_guess.Refresh_guess();
        }
    }
    g_root45A817_guess->Update_guess();
    UpdateLight_guess(g_root45A817_guess);
    if (((CharInfo45A817_guess*)g_root45A817_guess->GetCharInfo2())
            ->GetFlags_guess()->value78_guess != 0) {
        g_displayState45A817_guess->dirty10_guess = 1;
    }
}

// EXTERNAL: TITANIUM 0x004B232E FUN_004b232e_guess
int __cdecl FUN_004b232e_guess(const char* text_guess);

// FUNCTION: TITANIUM 0x0045AF4E
// A run of NUL-terminated serialized items: OP_CharInventory (0x5394) places them as type 0x69,
// opcode 0x15FF and the Handle_RecreateSpawn_guess tail as 0x67.
void __cdecl ReceiveSerializedItems_guess(int mode_guess, char* text_guess, int length_guess) {
    char buffer_guess[20000];
    if (text_guess != 0) {
        int channel_guess = (mode_guess == 0x5394) * 2 + 'g';
        char* end_guess = text_guess + length_guess;
        while (text_guess < end_guess) {
            memset(buffer_guess, 0, 20000);
            FUN_0060e450_guess(buffer_guess, text_guess);
            text_guess = text_guess + strlen(text_guess) + 1;
            int result_guess = FUN_004b232e_guess(buffer_guess);
            if (result_guess != 0) {
                PlaceReceivedItem_guess(channel_guess, result_guess);
            }
        }
    }
}

// FUNCTION: TITANIUM 0x0045AFDC
// @early-stop: budget, structural ndiff=98
// Opcode 0x12B2 {spawn id, Spawn_Struct}. For another spawn (0x185 bytes) it deletes and re-adds it;
// for the player it rebuilds the EQPlayer through Handle_OP_ZoneEntry_guess, restores the windows,
// and loads the item strings after +0x340D.
char __cdecl Handle_RecreateSpawn_guess(unsigned opcode_guess, unsigned* data_guess,
                                unsigned length_guess) {
    char name_guess[64];
    if (opcode_guess != 0x12B2 || data_guess == 0 || length_guess < 0x185) {
        return 0;
    }

    DispatchTarget_guess* dispatch_guess = ResolveDispatch_guess(data_guess[0]);
    if (dispatch_guess == 0) {
        return 0;
    }
    strncpy(name_guess, dispatch_guess->name_0120_guess, 0x40);

    if (dispatch_guess == g_propertyOwnerCurrent_guess) {
        if (g_streamManager45AFDC_guess != 0) {
            g_streamManager45AFDC_guess->Reset_guess();
        }
        DispatchTarget_guess* current_guess = g_propertyOwnerCurrent_guess;
        unsigned char currentMode_guess =
            (unsigned char)(current_guess->afk_026c_guess != 0);
        unsigned char savedState_guess = (unsigned char)current_guess->lfg_01b4_guess;
        current_guess->FUN_004849b2_guess();
        operator delete(current_guess);
        g_propertyOwnerCurrent_guess = 0;
        g_root45A817_guess->LoadBaseProfile_guess(
            (char*)((PacketData45AFDC_guess*)data_guess)->after185_guess);

        if (!Handle_OP_ZoneEntry_guess((char*)(data_guess + 1), 0x181)) {
            return 0;
        }

        g_propertyOwnerCurrent_guess->lfg_01b4_guess = savedState_guess;
        g_propertyOwnerCurrent_guess->SetAFK_guess((int)currentMode_guess);
        if (pinstCInvSlotMgr_guess != 0) {
            pinstCInvSlotMgr_guess->Refresh_guess();
        }
        if (pinstCCursorAttachment_guess != 0) {
            pinstCCursorAttachment_guess->Slot88_guess();
        }
        EQ_GLOBAL(int, 0x00905D04) = 0;
        if (pinstCInventoryWnd_guess != 0) {
            pinstCInventoryWnd_guess->Refresh_guess();
        }
        if (pinstCCastSpellWnd_guess != 0) {
            pinstCCastSpellWnd_guess->Reset_guess(-1);
            int ready_guess = g_root45A817_guess->bankC280_guess.IsReady_guess();
            if (ready_guess != 0 && g_root45A817_guess->CheckUpdate_guess() == 0) {
                ready_guess = 1;
            } else {
                ready_guess = 0;
            }
            ((DispatchCallC0_45AFDC_guess*)pinstCCastSpellWnd_guess)
                ->ApplyC0_guess((unsigned)ready_guess, 1);
            pinstCCastSpellWnd_guess->Finish_guess();
        }
        if (pinstCInvSlotMgr_guess != 0) {
            for (int index_guess = 0; index_guess < 0x1E; ++index_guess) {
                UpdateEntry45AFDC_guess* entry_guess =
                    pinstCInvSlotMgr_guess->FindInvSlot(index_guess);
                if (entry_guess != 0) {
                    entry_guess->Apply_guess(
                        (unsigned)g_root45A817_guess->HasIndex_guess(index_guess));
                }
            }
        }
        if (g_updateReady45AFDC_guess != 0) {
            g_updateReady45AFDC_guess->Initialize_guess();
            if (g_root45A817_guess->CheckUpdate_guess() != 0) {
                ((Target4521Dispatch_guess*)g_updateReady45AFDC_guess)->Slot84_guess();
            }
        }
        if ((int)(length_guess - 0x340D) > 0) {
            ReceiveSerializedItems_guess(0x15FF,
                               ((PacketData45AFDC_guess*)data_guess)->after340D_guess,
                               length_guess - 0x340D);
        }
        g_root45A817_guess->bankC280_guess.dirty0C_guess = 1;
        g_root45A817_guess->bankC280_guess.Refresh_guess();
        ((RootDispatch45AFDC_guess*)g_root45A817_guess)->HandleS2CRaidMessage_guess();
        g_display45A817_guess->ReleasePendingRequest_guess(1);
        g_display45A817_guess->Finish_guess();
        g_root45A817_guess->UpdateZoneEnvironment_guess();
    } else if (length_guess == 0x185) {
        opcode_guess = data_guess[0];
        ((char(__cdecl*)(int*, int))Handle_OP_DeleteSpawn_guess)((int*)&opcode_guess, 4);
        ((void(__cdecl*)(char*, int))Handle_OP_NewSpawn_guess)((char*)(data_guess + 1), 0x181);
    } else {
        return 0;
    }

    ResolvedTarget45AFDC_guess* target_guess =
        (ResolvedTarget45AFDC_guess*)ResolveTarget_guess(name_guess);
    if (target_guess == 0) {
        return 1;
    }
    RemoteValues45AFDC_guess* remote_guess = target_guess->value1A8_guess;
    if (remote_guess == 0 || remote_guess->object_guess == 0) {
        return 1;
    }

    int firstValue_guess = remote_guess->valueFB4_guess;
    int secondValue_guess = remote_guess->valueFB8_guess;
    if (firstValue_guess != 0) {
        remote_guess->object_guess->Apply1A4_guess(0x4D, firstValue_guess, 0);
    }
    if (secondValue_guess != 0) {
        remote_guess->object_guess->Apply1A4_guess(0x4E, secondValue_guess, 0);
    }
    if (firstValue_guess != 0) {
        remote_guess->object_guess->Apply1A4_guess(0x4F, firstValue_guess, 1);
        remote_guess->object_guess->Apply1A4_guess(0x50, firstValue_guess, 1);
    }
    if (secondValue_guess != 0) {
        remote_guess->object_guess->Apply1A4_guess(0x51, secondValue_guess, 0);
    }
    return 1;
}

// FUNCTION: TITANIUM 0x0045B31C
// Copy assignment for a paged array (page = index >> shift, entry = index & mask).
IndexedTableB31C_guess* IndexedTableB31C_guess::Copy_guess(
    IndexedTableB31C_guess* source_guess) {
    if (this != source_guess) {
        SetCount_guess(0);
        if (source_guess->count_guess != 0) {
            Prepare_guess(source_guess->count_guess);
            if (enabled_guess != 0) {
                for (int index_guess = 0; index_guess < source_guess->count_guess;
                     ++index_guess) {
                    pages_guess[index_guess >> shift_guess][index_guess & mask_guess] =
                        source_guess->pages_guess[index_guess >> source_guess->shift_guess]
                                                    [index_guess & source_guess->mask_guess];
                }
            }
            count_guess = source_guess->count_guess;
        }
    }
    return this;
}

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

struct StateSourceB86D_guess {
    int value0_guess;
};

struct StateListB86D_guess {
    int head_guess;
    int count_guess;
    int tail_guess;
    int current_guess;

    // EXTERNAL: TITANIUM 0x00447B7F StateListB86D_guess::Clear_guess
    void Clear_guess();
};

struct StateB86D_guess {
    int key_guess;
    unsigned char padding04_guess[0x58];
    StateListB86D_guess list5C_guess;

    // EXTERNAL: TITANIUM 0x00447B98 StateB86D_guess::StateB86D_guess
    StateB86D_guess();

    // EXTERNAL: TITANIUM 0x00447A14 StateB86D_guess::Load_guess
    void Load_guess(StateSourceB86D_guess* source_guess, int value_guess);
};

struct TextViewB86D_guess {
    // EXTERNAL: TITANIUM 0x00447CD3 TextViewB86D_guess::InsertValue_guess
    char InsertValue_guess(int* value_guess);
};

struct GlobalStateB86D_guess {
    unsigned char padding_guess[0xC350];
    unsigned char fieldC350_guess;
};

#define g_tableViewB86D_guess EQ_GLOBAL(TextViewB86D_guess*, 0x008511D8)
#define g_globalStateB86D_guess EQ_GLOBAL(GlobalStateB86D_guess*, 0x00905D00)

// FUNCTION: TITANIUM 0x0045B86D
// One AA definition per packet, added to the AA table; dropped if the insert fails.
void __cdecl Handle_OP_SendAATable_guess(StateSourceB86D_guess* source_guess,
                                int value_guess) {
    if (source_guess != 0) {
        StateB86D_guess* state_guess = new StateB86D_guess;
        state_guess->Load_guess(source_guess, value_guess);
        if (!g_tableViewB86D_guess->InsertValue_guess((int*)state_guess)) {
            if (state_guess != 0) {
                state_guess->list5C_guess.Clear_guess();
                operator delete(state_guess);
            }
        }
        if (g_globalStateB86D_guess != 0) {
            g_globalStateB86D_guess->fieldC350_guess = 0;
        }
    }
}

struct CopyUnitB393_guess {
    unsigned words_guess[14];

    // EXTERNAL: TITANIUM 0x00494593 CopyUnitB393_guess::Copy_guess
    void Copy_guess(CopyUnitB393_guess* source_guess);
};

struct TripleB393_guess {
    unsigned first_guess;
    unsigned second_guess;
    unsigned third_guess;
};

struct LargeCopyB393_guess {
    unsigned char value0_guess;
    unsigned char values1_guess[0x20];
    unsigned char padding21_guess[3];
    unsigned value24_guess;
    unsigned value28_guess;
    unsigned value2C_guess;
    CopyUnitB393_guess value30_guess;
    CopyUnitB393_guess value68_guess;
    unsigned valueA0_guess;
    unsigned valueA4_guess;
    unsigned char valueA8_guess;
    unsigned char paddingA9_guess[7];
    CopyUnitB393_guess valueB0_guess;
    CopyUnitB393_guess valueE8_guess;
    unsigned char values120_guess[0x40];
    unsigned char values160_guess[0x40];
    unsigned value1A0_guess;
    unsigned value1A4_guess;
    unsigned value1A8_guess;
    unsigned value1AC_guess;
    unsigned char values1B0_guess[9];
    unsigned char padding1B9_guess[3];
    unsigned values1BC_guess[9];
    unsigned values1E0_guess[9];
    unsigned value204_guess;
    unsigned value208_guess;
    unsigned values20C_guess[2];
    unsigned value214_guess;
    unsigned value218_guess;
    unsigned value21C_guess;
    unsigned value220_guess;
    unsigned value224_guess;
    unsigned value228_guess;
    unsigned value22C_guess;
    unsigned value230_guess;
    unsigned value234_guess;
    unsigned value238_guess;
    unsigned value23C_guess;
    unsigned value240_guess;
    unsigned char values244_guess[0x13];
    unsigned char padding257_guess;
    unsigned value258_guess;
    unsigned value25C_guess;
    unsigned value260_guess;
    unsigned value264_guess;
    unsigned value268_guess;
    unsigned value26C_guess;
    unsigned value270_guess;
    unsigned value274_guess;
    unsigned value278_guess;
    unsigned value27C_guess;
    unsigned value280_guess;
    unsigned value284_guess;
    unsigned value288_guess;
    unsigned value28C_guess;
    unsigned value290_guess;
    unsigned value294_guess;
    unsigned value298_guess;
    unsigned value29C_guess;
    unsigned value2A0_guess;
    unsigned char values2A4_guess[0x20];
    unsigned char values2C4_guess[0x20];
    unsigned char value2E4_guess;
    unsigned char value2E5_guess;
    unsigned char value2E6_guess;
    unsigned char padding2E7_guess;
    unsigned value2E8_guess;
    TripleB393_guess value2EC_guess;
    unsigned value2F8_guess;
    TripleB393_guess value2FC_guess;
    unsigned value308_guess;
    SevenWords_guess value30C_guess;
    IndexedTableB31C_guess value328_guess;
    unsigned value344_guess;

    LargeCopyB393_guess* CopyFrom_guess(LargeCopyB393_guess& source_reference_guess);
};

// FUNCTION: TITANIUM 0x0045B393
// @early-stop: budget, structural ndiff=211
// Member-wise copy assignment.
LargeCopyB393_guess* LargeCopyB393_guess::CopyFrom_guess(
    LargeCopyB393_guess& source_reference_guess) {
    value0_guess = source_reference_guess.value0_guess;
    for (int index_guess = 0; index_guess < 0x20; ++index_guess) {
        values1_guess[index_guess] = source_reference_guess.values1_guess[index_guess];
    }
    value24_guess = source_reference_guess.value24_guess;
    value28_guess = source_reference_guess.value28_guess;
    value2C_guess = source_reference_guess.value2C_guess;
    value30_guess.Copy_guess(&source_reference_guess.value30_guess);
    value68_guess.Copy_guess(&source_reference_guess.value68_guess);
    valueA0_guess = source_reference_guess.valueA0_guess;
    valueA4_guess = source_reference_guess.valueA4_guess;
    valueA8_guess = source_reference_guess.valueA8_guess;
    valueB0_guess.Copy_guess(&source_reference_guess.valueB0_guess);
    valueE8_guess.Copy_guess(&source_reference_guess.valueE8_guess);
    for (int index_guess = 0; index_guess < 0x40; ++index_guess) {
        values120_guess[index_guess] = source_reference_guess.values120_guess[index_guess];
    }
    for (int index_guess = 0; index_guess < 0x40; ++index_guess) {
        values160_guess[index_guess] = source_reference_guess.values160_guess[index_guess];
    }
    value1A0_guess = source_reference_guess.value1A0_guess;
    value1A4_guess = source_reference_guess.value1A4_guess;
    value1A8_guess = source_reference_guess.value1A8_guess;
    value1AC_guess = source_reference_guess.value1AC_guess;
    values1B0_guess[0] = source_reference_guess.values1B0_guess[0];
    values1B0_guess[1] = source_reference_guess.values1B0_guess[1];
    values1B0_guess[2] = source_reference_guess.values1B0_guess[2];
    values1B0_guess[3] = source_reference_guess.values1B0_guess[3];
    values1B0_guess[4] = source_reference_guess.values1B0_guess[4];
    values1B0_guess[5] = source_reference_guess.values1B0_guess[5];
    values1B0_guess[6] = source_reference_guess.values1B0_guess[6];
    values1B0_guess[7] = source_reference_guess.values1B0_guess[7];
    values1B0_guess[8] = source_reference_guess.values1B0_guess[8];
    for (int index_guess = 0; index_guess < 9; ++index_guess) {
        values1BC_guess[index_guess] = source_reference_guess.values1BC_guess[index_guess];
    }
    for (int index_guess = 0; index_guess < 9; ++index_guess) {
        values1E0_guess[index_guess] = source_reference_guess.values1E0_guess[index_guess];
    }
    value204_guess = source_reference_guess.value204_guess;
    value208_guess = source_reference_guess.value208_guess;
    int index20C_guess = 0;
    do {
        values20C_guess[index20C_guess] = source_reference_guess.values20C_guess[index20C_guess];
        ++index20C_guess;
    } while (index20C_guess != 2);
    value214_guess = source_reference_guess.value214_guess;
    value218_guess = source_reference_guess.value218_guess;
    value21C_guess = source_reference_guess.value21C_guess;
    value220_guess = source_reference_guess.value220_guess;
    value224_guess = source_reference_guess.value224_guess;
    value228_guess = source_reference_guess.value228_guess;
    value22C_guess = source_reference_guess.value22C_guess;
    value230_guess = source_reference_guess.value230_guess;
    value234_guess = source_reference_guess.value234_guess;
    value238_guess = source_reference_guess.value238_guess;
    value23C_guess = source_reference_guess.value23C_guess;
    value240_guess = source_reference_guess.value240_guess;
    values244_guess[0] = source_reference_guess.values244_guess[0];
    values244_guess[1] = source_reference_guess.values244_guess[1];
    values244_guess[2] = source_reference_guess.values244_guess[2];
    values244_guess[3] = source_reference_guess.values244_guess[3];
    values244_guess[4] = source_reference_guess.values244_guess[4];
    values244_guess[5] = source_reference_guess.values244_guess[5];
    values244_guess[6] = source_reference_guess.values244_guess[6];
    values244_guess[7] = source_reference_guess.values244_guess[7];
    values244_guess[8] = source_reference_guess.values244_guess[8];
    values244_guess[9] = source_reference_guess.values244_guess[9];
    values244_guess[10] = source_reference_guess.values244_guess[10];
    values244_guess[11] = source_reference_guess.values244_guess[11];
    values244_guess[12] = source_reference_guess.values244_guess[12];
    values244_guess[13] = source_reference_guess.values244_guess[13];
    values244_guess[14] = source_reference_guess.values244_guess[14];
    values244_guess[15] = source_reference_guess.values244_guess[15];
    values244_guess[16] = source_reference_guess.values244_guess[16];
    values244_guess[17] = source_reference_guess.values244_guess[17];
    values244_guess[18] = source_reference_guess.values244_guess[18];
    value258_guess = source_reference_guess.value258_guess;
    value25C_guess = source_reference_guess.value25C_guess;
    value260_guess = source_reference_guess.value260_guess;
    value264_guess = source_reference_guess.value264_guess;
    value268_guess = source_reference_guess.value268_guess;
    value26C_guess = source_reference_guess.value26C_guess;
    value270_guess = source_reference_guess.value270_guess;
    value274_guess = source_reference_guess.value274_guess;
    value278_guess = source_reference_guess.value278_guess;
    value27C_guess = source_reference_guess.value27C_guess;
    value280_guess = source_reference_guess.value280_guess;
    value284_guess = source_reference_guess.value284_guess;
    value288_guess = source_reference_guess.value288_guess;
    value28C_guess = source_reference_guess.value28C_guess;
    value290_guess = source_reference_guess.value290_guess;
    value294_guess = source_reference_guess.value294_guess;
    value298_guess = source_reference_guess.value298_guess;
    value29C_guess = source_reference_guess.value29C_guess;
    value2A0_guess = source_reference_guess.value2A0_guess;
    for (int index_guess = 0; index_guess < 0x20; ++index_guess) {
        values2A4_guess[index_guess] = source_reference_guess.values2A4_guess[index_guess];
    }
    for (int index_guess = 0; index_guess < 0x20; ++index_guess) {
        values2C4_guess[index_guess] = source_reference_guess.values2C4_guess[index_guess];
    }
    value2E4_guess = source_reference_guess.value2E4_guess;
    value2E5_guess = source_reference_guess.value2E5_guess;
    value2E6_guess = source_reference_guess.value2E6_guess;
    value2E8_guess = source_reference_guess.value2E8_guess;
    value2EC_guess = source_reference_guess.value2EC_guess;
    value2F8_guess = source_reference_guess.value2F8_guess;
    value2FC_guess = source_reference_guess.value2FC_guess;
    value308_guess = source_reference_guess.value308_guess;
    value30C_guess.CopyFrom_guess(&source_reference_guess.value30C_guess);
    value328_guess.Copy_guess(&source_reference_guess.value328_guess);
    value344_guess = source_reference_guess.value344_guess;
    return this;
}

// ---- 0x0045B8F0: the message dispatcher -------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

struct ActorB8F0_guess;
struct ObjB8F0_guess;
struct PlayerB8F0_guess;

struct Buff14B8F0_guess {
    char b0_guess;
    int i4_guess;
    unsigned char rest_guess[0xC];
};

#pragma pack(push, 1)
struct Popup108B8F0_guess {
    int kind_guess;
    char flag_guess;
    char name_guess[0x103];
};
#pragma pack(pop)

// The window object's third base, at +8.
struct NotifyHead0B8F0_guess {
    void* vftable0_guess;
};
struct NotifyHead4B8F0_guess {
    void* vftable4_guess;
};
struct NotifyBaseB8F0_guess {
    void* vftable8_guess;
};
struct NotifyViewB8F0_guess : NotifyHead0B8F0_guess, NotifyHead4B8F0_guess, NotifyBaseB8F0_guess {
};

void __cdecl Handle_OP_LevelUpdate_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                             unsigned size_guess);
// EXTERNAL: TITANIUM 0x00457F32 Handle_OP_ZoneEntry_guess
char __cdecl Handle_OP_ZoneEntry_guess(char* data_guess, unsigned size_guess);
// EXTERNAL: TITANIUM 0x00469DD7 Ext469DD7_guess
void __cdecl Ext469DD7_guess(int value_guess);
// EXTERNAL: TITANIUM 0x004241DD Handle_EvolvingItemUpdate_guess
void __cdecl Handle_EvolvingItemUpdate_guess(char* data_guess);

// Free functions of the rest of the client, as this function calls them.
// EXTERNAL: TITANIUM 0x0046DA4A Ext46DA4A_guess
void __cdecl Ext46DA4A_guess(char* destination_guess, int id_guess, const char* a3_guess,
                             const char* a4_guess, const char* a5_guess, const char* a6_guess,
                             const char* a7_guess, const char* a8_guess, const char* a9_guess,
                             const char* a10_guess, const char* a11_guess);
// EXTERNAL: TITANIUM 0x00574110 Ext574110_guess
void __cdecl Ext574110_guess(const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x00576FA0 Ext576FA0_guess
void __cdecl Ext576FA0_guess(char* destination_guess, const char* source_guess, int size_guess);
// EXTERNAL: TITANIUM 0x0047C88E Ext47C88E_guess
PlayerB8F0_guess* __cdecl Ext47C88E_guess(const char* name_guess);
// EXTERNAL: TITANIUM 0x00401B28 Ext401B28_guess
PlayerB8F0_guess* __cdecl Ext401B28_guess(int id_guess);
// EXTERNAL: TITANIUM 0x004C94AE Ext4C94AE_guess
ObjB8F0_guess* __cdecl Ext4C94AE_guess();
// EXTERNAL: TITANIUM 0x0056FC86 GetCameraShake_guess
ObjB8F0_guess* __cdecl GetCameraShake_guess();
// EXTERNAL: TITANIUM 0x00467441 Ext467441_guess
void __cdecl Ext467441_guess(char* destination_guess, char* text_guess, char* arguments_guess,
                             int fourth_guess, int fifth_guess);
// EXTERNAL: TITANIUM 0x0046DCDC SetCharacterLevel_guess
void __cdecl SetCharacterLevel_guess(void* character_guess, int value_guess);
// EXTERNAL: TITANIUM 0x00576E80 Ext576E80_guess
int __cdecl Ext576E80_guess();
// EXTERNAL: TITANIUM 0x0046D655 Ext46D655_guess
int __cdecl Ext46D655_guess();
// EXTERNAL: TITANIUM 0x00407DC9 Ext407DC9_guess
ObjB8F0_guess* __cdecl Ext407DC9_guess();
struct New490A43B8F0_guess {
    unsigned char padding00_guess[0x22];
    char b22_guess;
    unsigned char padding23_guess[0x90 - 0x23];
    int i90_guess;
    unsigned char padding94_guess[0xC4 - 0x94];
    // EXTERNAL: TITANIUM 0x00490A43 New490A43B8F0_guess::New490A43B8F0_guess
    New490A43B8F0_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0048F9C7 New490A43B8F0_guess::~New490A43B8F0_guess
    ~New490A43B8F0_guess();
};
struct New4790D0B8F0_guess {
    unsigned char padding00_guess[0x54];
    int i54_guess;
    // EXTERNAL: TITANIUM 0x004790D0 New4790D0B8F0_guess::New4790D0B8F0_guess
    New4790D0B8F0_guess(char* data_guess, int second_guess, char* third_guess, char* fourth_guess);
    // EXTERNAL: TITANIUM 0x00479305 New4790D0B8F0_guess::~New4790D0B8F0_guess
    ~New4790D0B8F0_guess();
};
// EXTERNAL: TITANIUM 0x00491373 Handle_OP_SendZonepoints_guess
void __cdecl Handle_OP_SendZonepoints_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                             unsigned size_guess);
// EXTERNAL: TITANIUM 0x004CC6B7 fillEvilProcessNames_guess
void __cdecl fillEvilProcessNames_guess(char* data_guess);
// EXTERNAL: TITANIUM 0x004B8AA2 Handle_OP_MoveMultipleItems_guess
void __cdecl Handle_OP_MoveMultipleItems_guess(void* character_guess, char* data_guess, unsigned size_guess);
// EXTERNAL: TITANIUM 0x00473EEF SetSkillsToCap_guess
void __cdecl SetSkillsToCap_guess(void* character_guess);
struct ProfileB8F0_guess {
    unsigned char padding0000_guess[0x11A4];
    int level_11a4_guess;
    int padding11A8_guess[2];
    int i11B0_guess;
    unsigned char padding11B4_guess[0x11E4 - 0x11B4];
    int i11E4_guess;
    int i11E8_guess;
    int i11EC_guess;
    int i11F0_guess;
    int padding11F4_guess;
    int i11F8_guess;
};
struct WorldB8F0_guess {
    int padding00_guess;
    unsigned char b04_guess;
    unsigned char b05_guess;
    unsigned char b06_guess;
    unsigned char b07_guess;
    int i08_guess;
    unsigned char b0C_guess;
    unsigned char b0D_guess;
    unsigned char b0E_guess;
    unsigned char b0F_guess;
    int i10_guess;
    int i14_guess;
    int i18_guess;
};
#define gWorldB8F0_guess EQ_GLOBAL(WorldB8F0_guess*, 0x00905CC0)
// EXTERNAL: TITANIUM 0x004C32FF Ext4C32FF_guess
ObjB8F0_guess* __cdecl Ext4C32FF_guess();
// EXTERNAL: TITANIUM 0x0057F6A0 ntohs
extern "C" unsigned short __stdcall ntohs(unsigned short value_guess);
// EXTERNAL: TITANIUM 0x004B611D Ext4B611D_guess
int __cdecl Ext4B611D_guess(char* address_guess);
// EXTERNAL: TITANIUM 0x004CD211 ChecksumCodeRangesB_guess
int __cdecl ChecksumCodeRangesB_guess(int value_guess);
// EXTERNAL: TITANIUM 0x00471267 do_approval_guess
void __cdecl do_approval_guess(int first_guess, char* text_guess);
// EXTERNAL: TITANIUM 0x004B6A36 Ext4B6A36_guess
ObjB8F0_guess* __cdecl Ext4B6A36_guess();
struct New46469FB8F0_guess {
    int i00_guess;
    int i04_guess;
    int i08_guess;
    int padding0C_guess[2];
    int actor_0014_guess;
    int padding18_guess;
    float fl1C_guess;
    float fl20_guess;
    float fl24_guess;
    float fl28_guess;
    char t2C_guess[0x24];
    int i50_guess;
    int padding54_guess[2];
    // EXTERNAL: TITANIUM 0x0046469F New46469FB8F0_guess::New46469FB8F0_guess
    New46469FB8F0_guess();
    // EXTERNAL: TITANIUM 0x0046471B New46469FB8F0_guess::~New46469FB8F0_guess
    ~New46469FB8F0_guess();
    // EXTERNAL: TITANIUM 0x00464770 New46469FB8F0_guess::FindByDropId_guess
    New46469FB8F0_guess* FindByDropId_guess(int id_guess);
};
struct New477AD3B8F0_guess {
    int i00_guess;
    int i04_guess;
    int i08_guess;
    int i0C_guess;
    int i10_guess;
    int i14_guess;
    int padding18_guess[7];
    int actor_0034_guess;
    float fl38_guess;
    float fl3C_guess;
    float fl40_guess;
    float fl44_guess;
    int padding48_guess[2];
    char t50_guess[0x20];
    // EXTERNAL: TITANIUM 0x00477AD3 New477AD3B8F0_guess::New477AD3B8F0_guess
    New477AD3B8F0_guess();
    // EXTERNAL: TITANIUM 0x00477B4B New477AD3B8F0_guess::~New477AD3B8F0_guess
    ~New477AD3B8F0_guess();
    // EXTERNAL: TITANIUM 0x00477BA0 New477AD3B8F0_guess::M477BA0_guess
    New477AD3B8F0_guess* M477BA0_guess(int id_guess);
};
struct New476F34B8F0_guess {
    unsigned char storage_guess[0x88];
    // EXTERNAL: TITANIUM 0x00476F34 New476F34B8F0_guess::New476F34B8F0_guess
    New476F34B8F0_guess(int a1_guess, int a2_guess, char* data_guess, int a4_guess, int a5_guess,
                        int a6_guess);
};
#pragma pack(push, 1)
struct Packed3A2BB8F0_guess {
    unsigned short id_guess;
    __int64 a_guess : 19;
    __int64 c_guess : 19;
    __int64 b_guess : 19;
    short d_guess : 12;
};
struct Unpacked3A2BB8F0_guess {
    unsigned short id_guess;
    unsigned padding2_guess : 10;
    int b_guess : 19;
    unsigned padding2b_guess : 3;
    int a_guess : 19;
    unsigned padding6_guess : 13;
    int c_guess : 19;
    unsigned paddingA_guess : 13;
    unsigned paddingE_guess : 13;
    int d_guess : 12;
    unsigned paddingEb_guess : 7;
    unsigned value12_guess;
};
#pragma pack(pop)
// EXTERNAL: TITANIUM 0x004250F0 ReturnOne_guess
void __cdecl ReturnOne_guess(void* character_guess, float value_guess);
// EXTERNAL: TITANIUM 0x00574890 Ext574890_guess
unsigned __cdecl Ext574890_guess(char* text_guess);
struct Block58B8F0_guess {
    int words_guess[0x16];
};
// EXTERNAL: TITANIUM 0x0046DC2E Ext46DC2E_guess
void __cdecl Ext46DC2E_guess(void* owner_guess, int id_guess, int color_guess,
                             const char* a4_guess, const char* a5_guess, const char* a6_guess,
                             const char* a7_guess, const char* a8_guess, const char* a9_guess,
                             const char* a10_guess, const char* a11_guess, const char* a12_guess,
                             const char* a13_guess);
// EXTERNAL: TITANIUM 0x00576670 Ext576670_guess
char __cdecl Ext576670_guess(char* name_guess);
struct Emit4C5C39B8F0_guess {
    int padding00_guess[4];
    float y_guess;
    float x_guess;
    float z_guess;
    float fl1C_guess;
    float fl20_guess;
    int padding24_guess[5];
    // EXTERNAL: TITANIUM 0x004C5C39 Emit4C5C39B8F0_guess::Emit4C5C39B8F0_guess
    Emit4C5C39B8F0_guess();
};

// Vtable view: slots named by offset.
struct VirtB8F0_guess {
    virtual void V000_guess() = 0;
    virtual void V004_guess() = 0;
    virtual void V008_guess(int a1_guess, int a2_guess, int a3_guess, float a4_guess,
                            int a5_guess) = 0;
    virtual void V00C_guess() = 0;
    virtual void V010_guess() = 0;
    virtual void V014_guess() = 0;
    virtual void V018_guess() = 0;
    virtual void V01C_guess() = 0;
    virtual void V020_guess() = 0;
    virtual void V024_guess() = 0;
    virtual void V028_guess() = 0;
    virtual void V02C_guess() = 0;
    virtual void V030_guess() = 0;
    virtual void V034_guess() = 0;
    virtual void V038_guess() = 0;
    virtual void V03C_guess() = 0;
    virtual void V040_guess() = 0;
    virtual void V044_guess() = 0;
    virtual void V048_guess() = 0;
    virtual void V04C_guess() = 0;
    virtual void V050_guess(float a1_guess, int a2_guess) = 0;
    virtual void V054_guess() = 0;
    virtual void V058_guess() = 0;
    virtual void V05C_guess() = 0;
    virtual void V060_guess() = 0;
    virtual void V064_guess() = 0;
    virtual void V068_guess() = 0;
    virtual void V06C_guess() = 0;
    virtual void V070_guess() = 0;
    virtual void V074_guess() = 0;
    virtual void V078_guess() = 0;
    virtual void V07C_guess() = 0;
    virtual void V080_guess() = 0;
    virtual void V084_guess() = 0;
    virtual void V088_guess() = 0;
    virtual void V08C_guess() = 0;
    virtual void V090_guess() = 0;
    virtual void V094_guess() = 0;
    virtual void V098_guess() = 0;
    virtual void V09C_guess() = 0;
    virtual void V0A0_guess() = 0;
    virtual void V0A4_guess() = 0;
    virtual void V0A8_guess() = 0;
    virtual void V0AC_guess() = 0;
    virtual void V0B0_guess() = 0;
    virtual void V0B4_guess() = 0;
    virtual void V0B8_guess() = 0;
    virtual void V0BC_guess() = 0;
    virtual void V0C0_guess(int a1_guess, int a2_guess) = 0;
};

// Catch-all view of the window and manager objects the dispatcher forwards to.
struct ObjB8F0_guess {
    unsigned char padding000_guess[0x5C];
    unsigned char b05C_guess;
    unsigned char padding05D_guess[9];
    short w066_guess;
    unsigned char padding068_guess[0xF0 - 0x68];
    int i0F0_guess;
    unsigned char padding0F4_guess[0x1D8 - 0xF4];
    unsigned char b1D8_guess;

    // EXTERNAL: TITANIUM 0x00565D94 ObjB8F0_guess::SetTitle_guess
    void SetTitle_guess(int first_guess, char* text_guess);
    // EXTERNAL: TITANIUM 0x00565DD0 ObjB8F0_guess::SetSuffix_guess
    void SetSuffix_guess(int first_guess, char* text_guess);
    // EXTERNAL: TITANIUM 0x004089B2 ObjB8F0_guess::M4089B2_guess
    void M4089B2_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0040E293 ObjB8F0_guess::M40E293_guess
    void M40E293_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004050D0 ObjB8F0_guess::M4050D0_guess
    void M4050D0_guess(unsigned opcode_guess, char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x00401C53 ObjB8F0_guess::SendProgressionCancel_guess
    void SendProgressionCancel_guess();
    // EXTERNAL: TITANIUM 0x004DB5D5 ObjB8F0_guess::M4DB5D5_guess
    void M4DB5D5_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x0052B79C ObjB8F0_guess::HandleLootResponse_guess
    void HandleLootResponse_guess(int a1_guess, int a2_guess, int a3_guess, int a4_guess, int a5_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 ObjB8F0_guess::M59DD30_guess
    bool M59DD30_guess();
    // EXTERNAL: TITANIUM 0x004E7992 ObjB8F0_guess::M4E7992_guess
    void M4E7992_guess();
    // EXTERNAL: TITANIUM 0x0055220A ObjB8F0_guess::InitRespawnList_guess
    void InitRespawnList_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0055222F ObjB8F0_guess::AddRespawnOption_guess
    void AddRespawnOption_guess(bool same_guess, int id_guess, FiveWords454FCD_guess words_guess,
                       char* text_guess);
    // EXTERNAL: TITANIUM 0x0050319B ObjB8F0_guess::M50319B_guess
    void M50319B_guess(void* where_guess, void* value_guess);
    // EXTERNAL: TITANIUM 0x0050F3F6 ObjB8F0_guess::M50F3F6_guess
    void M50F3F6_guess();
    // EXTERNAL: TITANIUM 0x004B76A6 ObjB8F0_guess::GetInventorySlot_guess
    int* GetInventorySlot_guess(void* owner_guess);
    // EXTERNAL: TITANIUM 0x0040E25C ObjB8F0_guess::M40E25C_guess
    void M40E25C_guess(const char* source_guess);
    // EXTERNAL: TITANIUM 0x0056FC58 ObjB8F0_guess::StartShake_guess
    void StartShake_guess(float first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0042500C ObjB8F0_guess::M42500C_guess
    void M42500C_guess(void* connection_guess);
    // EXTERNAL: TITANIUM 0x005563C6 ObjB8F0_guess::UpdateSoulmarks_guess
    void UpdateSoulmarks_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0053A8B8 ObjB8F0_guess::M53A8B8_guess
    void M53A8B8_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x004E87EF ObjB8F0_guess::SetBookText_guess
    void SetBookText_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0051E099 ObjB8F0_guess::M51E099_guess
    void M51E099_guess(char* data_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x00529EEA ObjB8F0_guess::M529EEA_guess
    void M529EEA_guess(unsigned opcode_guess, char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0040812F ObjB8F0_guess::DisplayText
    void DisplayText(char* text_guess, int a2_guess, int a3_guess, int a4_guess, int a5_guess,
                       int a6_guess, int a7_guess);
    // EXTERNAL: TITANIUM 0x00490547 ObjB8F0_guess::M490547_guess
    ObjB8F0_guess* M490547_guess(int id_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0049058F ObjB8F0_guess::M49058F_guess
    void M49058F_guess(ObjB8F0_guess* entry_guess);
    // EXTERNAL: TITANIUM 0x00490449 ObjB8F0_guess::M490449_guess
    void M490449_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x00490580 ObjB8F0_guess::M490580_guess
    void M490580_guess(void* entry_guess);
    // EXTERNAL: TITANIUM 0x00417D70 ObjB8F0_guess::M417D70_guess
    void M417D70_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D46 ObjB8F0_guess::M417D46_guess
    void M417D46_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D1C ObjB8F0_guess::M417D1C_guess
    void M417D1C_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417CF2 ObjB8F0_guess::M417CF2_guess
    void M417CF2_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00431CF2 ObjB8F0_guess::HandleS2CRaidMessage_guess
    void HandleS2CRaidMessage_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0055828A ObjB8F0_guess::SwapSpellBookSlots_guess
    void SwapSpellBookSlots_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004C334D ObjB8F0_guess::M4C334D_guess
    void M4C334D_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x004CB562 ObjB8F0_guess::HandleVoiceMacroOut_guess
    void HandleVoiceMacroOut_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x004A2F7A ObjB8F0_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049994C ObjB8F0_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00567B79 ObjB8F0_guess::Handle_OP_RecipeReply_guess
    void Handle_OP_RecipeReply_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x005F6ED0 ObjB8F0_guess::M5F6ED0_guess
    void M5F6ED0_guess(int zone_guess, char* name_guess);
    // EXTERNAL: TITANIUM 0x004EFEF1 ObjB8F0_guess::HandleApproveName_guess
    void HandleApproveName_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004C9C57 ObjB8F0_guess::HandleTicketMessage_guess
    void HandleTicketMessage_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x004EB924 ObjB8F0_guess::M4EB924_guess
    int* M4EB924_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0056875D ObjB8F0_guess::M56875D_guess
    void M56875D_guess();
    // EXTERNAL: TITANIUM 0x004E6109 ObjB8F0_guess::M4E6109_guess
    void M4E6109_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00568B39 ObjB8F0_guess::M568B39_guess
    void M568B39_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0054210E ObjB8F0_guess::SetPetBuffs_guess
    void SetPetBuffs_guess(char* first_guess, char* second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00564F92 ObjB8F0_guess::RequestTitles_guess
    void RequestTitles_guess();
    // EXTERNAL: TITANIUM 0x005579C8 ObjB8F0_guess::HandleDeleteSpellReply_guess
    void HandleDeleteSpellReply_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0044A537 ObjB8F0_guess::WavePlay_guess
    void WavePlay_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0060CA90 ObjB8F0_guess::M60CA90_guess
    int M60CA90_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004C270D ObjB8F0_guess::Handle_OP_FindPersonReply_guess
    void Handle_OP_FindPersonReply_guess(char* data_guess, unsigned count_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x004D8E35 ObjB8F0_guess::M4D8E35_guess
    void M4D8E35_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x0044826B ObjB8F0_guess::M44826B_guess
    void M44826B_guess();
    // EXTERNAL: TITANIUM 0x0056728A ObjB8F0_guess::HandleTrackReply_guess
    void HandleTrackReply_guess(char* data_guess, unsigned count_guess);
    // EXTERNAL: TITANIUM 0x00435163 ObjB8F0_guess::HandleGuildTributeMessage_guess
    void HandleGuildTributeMessage_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x00433887 ObjB8F0_guess::HandleTaskMessage_guess
    void HandleTaskMessage_guess(unsigned opcode_guess, char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x00424FB5 ObjB8F0_guess::WaitForDisconnect_guess
    bool WaitForDisconnect_guess(void* connection_guess, int timeout_guess);
    // EXTERNAL: TITANIUM 0x00417D5B ObjB8F0_guess::M417D5B_guess
    void M417D5B_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D31 ObjB8F0_guess::M417D31_guess
    void M417D31_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D07 ObjB8F0_guess::M417D07_guess
    void M417D07_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417CDD ObjB8F0_guess::M417CDD_guess
    void M417CDD_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004DC5AA ObjB8F0_guess::UpdateMoneyLabels_guess
    void UpdateMoneyLabels_guess();
    // EXTERNAL: TITANIUM 0x00434D9A ObjB8F0_guess::HandleTributeMessage_guess
    void HandleTributeMessage_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x00447575 ObjB8F0_guess::M447575_guess
    void M447575_guess(char* data_guess, int second_guess, float x_guess, float y_guess,
                       float z_guess);
    // EXTERNAL: TITANIUM 0x0048FC2E ObjB8F0_guess::M48FC2E_guess
    void M48FC2E_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00527130 ObjB8F0_guess::UpdateRows_guess
    void UpdateRows_guess();
    // EXTERNAL: TITANIUM 0x005536FE ObjB8F0_guess::SetServerList_guess
    void SetServerList_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0040A180 ObjB8F0_guess::Handle_OP_Barter_guess
    void Handle_OP_Barter_guess(unsigned opcode_guess, char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x004909CE ObjB8F0_guess::M4909CE_guess
    void M4909CE_guess();
    // EXTERNAL: TITANIUM 0x004B5145 ObjB8F0_guess::HandleLeadershipMessage_guess
    void HandleLeadershipMessage_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0050DC08 ObjB8F0_guess::M50DC08_guess
    void M50DC08_guess(unsigned opcode_guess, char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0055C13B ObjB8F0_guess::M55C13B_guess
    void M55C13B_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x00547115 ObjB8F0_guess::HandleSellReply_guess
    void HandleSellReply_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x00447364 ObjB8F0_guess::M447364_guess
    void M447364_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0044A617 ObjB8F0_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0055377E ObjB8F0_guess::M55377E_guess
    void M55377E_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0052B026 ObjB8F0_guess::FinishLoot_guess
    void FinishLoot_guess();
    // EXTERNAL: TITANIUM 0x004B6BC5 ObjB8F0_guess::M4B6BC5_guess
    void M4B6BC5_guess(int a1_guess, int a2_guess, int a3_guess, int a4_guess, int a5_guess,
                       int a6_guess);
    // EXTERNAL: TITANIUM 0x004B6B1B ObjB8F0_guess::CancelEffect_guess
    void CancelEffect_guess(int a1_guess, int a2_guess, int a3_guess);
    // EXTERNAL: TITANIUM 0x0054B657 ObjB8F0_guess::M54B657_guess
    void M54B657_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x004EE824 ObjB8F0_guess::M4EE824_guess
    void M4EE824_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0052613B ObjB8F0_guess::GetMp3Volume_guess
    float GetMp3Volume_guess();
    // EXTERNAL: TITANIUM 0x0044B741 ObjB8F0_guess::PlayMp3_guess
    void PlayMp3_guess(char* data_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x00554E7A ObjB8F0_guess::M554E7A_guess
    void M554E7A_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0040B8CB ObjB8F0_guess::M40B8CB_guess
    void M40B8CB_guess(void* connection_guess, unsigned opcode_guess, char* data_guess,
                       unsigned size_guess);
    // EXTERNAL: TITANIUM 0x0041AA6A ObjB8F0_guess::M41AA6A_guess
    void M41AA6A_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x004C251B ObjB8F0_guess::M4C251B_guess
    void M4C251B_guess(PlayerB8F0_guess* player_guess);
    // EXTERNAL: TITANIUM 0x00565CD2 ObjB8F0_guess::Handle_OP_SendTitleList_guess
    void Handle_OP_SendTitleList_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x00546A64 ObjB8F0_guess::M546A64_guess
    void M546A64_guess();
    // EXTERNAL: TITANIUM 0x00546E80 ObjB8F0_guess::M546E80_guess
    void M546E80_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0040A7FD ObjB8F0_guess::M40A7FD_guess
    void M40A7FD_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0054C4CC ObjB8F0_guess::M54C4CC_guess
    void M54C4CC_guess();
};

struct DisplayB8F0_guess {
    unsigned char padding0000_guess[0x11];
    unsigned char b0011_guess;
    unsigned char padding0012_guess[0x2D2C - 0x12];
    unsigned char b2D2C_guess;

    // EXTERNAL: TITANIUM 0x0043A650 DisplayB8F0_guess::M43A650_guess
    void M43A650_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x0043A68B DisplayB8F0_guess::SetSecondarySkyName_guess
    void SetSecondarySkyName_guess(char* text_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x004439C0 DisplayB8F0_guess::SetSkyBackground_guess
    void SetSkyBackground_guess();
    // EXTERNAL: TITANIUM 0x0043D7C5 DisplayB8F0_guess::MoveLocalPlayerToSafeCoords_guess
    void MoveLocalPlayerToSafeCoords_guess();
    // EXTERNAL: TITANIUM 0x0043C783 DisplayB8F0_guess::RestoreCameraMode_guess
    void RestoreCameraMode_guess();
    // EXTERNAL: TITANIUM 0x004364B0 DisplayB8F0_guess::M4364B0_guess
    void M4364B0_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004363A0 DisplayB8F0_guess::M4363A0_guess
    void M4363A0_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0043745D DisplayB8F0_guess::M43745D_guess
    int M43745D_guess();
    // EXTERNAL: TITANIUM 0x00439F26 DisplayB8F0_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float first_guess, float second_guess, float third_guess);
    // EXTERNAL: TITANIUM 0x0043972A DisplayB8F0_guess::CreateActor_guess
    int CreateActor_guess(char* name_guess, float a2_guess, float a3_guess, float a4_guess,
                      float a5_guess, float a6_guess, float a7_guess, int a8_guess, int a9_guess);
};

struct ActorB8F0_guess {
    VirtB8F0_guess* actorInstance_0000_guess;
    unsigned char padding0004_guess[0x68 - 0x4];
    int i068_guess;
    unsigned char padding006C_guess[0xC4 - 0x6C];
    float fl0C4_guess;
    unsigned char padding00C8_guess[0x158 - 0xC8];
    int i158_guess;
    int mount_015c_guess;
    unsigned char padding0160_guess[0x1A8 - 0x160];
    int i1A8_guess;
    unsigned char padding01AC_guess[0x1048 - 0x1AC];
    int i1048_guess;
    unsigned char b104C_guess;
    unsigned char padding104D_guess[3];
    int i1050_guess;
    unsigned char padding1054_guess[0x1060 - 0x1054];
    int i1060_guess;
};

struct PlayerB8F0_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x0047C3EF PlayerB8F0_guess::M47C3EF_guess
    void M47C3EF_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x0047D776 PlayerB8F0_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
    // EXTERNAL: TITANIUM 0x0047FA9E PlayerB8F0_guess::SetHeights_guess
    void SetHeights_guess();
    // EXTERNAL: TITANIUM 0x00478474 PlayerB8F0_guess::WarpToPosition_guess
    void WarpToPosition_guess(float* position_guess, float heading_guess);
    // EXTERNAL: TITANIUM 0x0048C11B PlayerB8F0_guess::M48C11B_guess
    void M48C11B_guess();
    // EXTERNAL: TITANIUM 0x0048BB5A PlayerB8F0_guess::UpdateSharedValuesIfLocal_guess
    void UpdateSharedValuesIfLocal_guess();
    // EXTERNAL: TITANIUM 0x0047A085 PlayerB8F0_guess::InitSneakMod_guess
    void InitSneakMod_guess();
    // EXTERNAL: TITANIUM 0x0048492C PlayerB8F0_guess::ChangeTextures_guess
    void ChangeTextures_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00483556 PlayerB8F0_guess::ChangePosition_guess
    void ChangePosition_guess(int state_guess);
    // EXTERNAL: TITANIUM 0x0048A945 PlayerB8F0_guess::M48A945_guess
    void M48A945_guess();
    // EXTERNAL: TITANIUM 0x0047C08E PlayerB8F0_guess::GetAnimation_guess
    VirtB8F0_guess* GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x0047C11A PlayerB8F0_guess::PlayLevelAppearance_guess
    void PlayLevelAppearance_guess(char* data_guess);
    // EXTERNAL: TITANIUM 0x0047F614 PlayerB8F0_guess::IWasHit_guess
    void IWasHit_guess(unsigned char* packet_guess);
    // EXTERNAL: TITANIUM 0x004849B2 PlayerB8F0_guess::M4849B2_guess
    void M4849B2_guess();
    // EXTERNAL: TITANIUM 0x004793B5 PlayerB8F0_guess::M4793B5_guess
    char* M4793B5_guess();
    // EXTERNAL: TITANIUM 0x0048083A PlayerB8F0_guess::M48083A_guess
    void M48083A_guess(int kind_guess, char* name_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0047DEC4 PlayerB8F0_guess::SwapFace_guess
    void SwapFace_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004845D8 PlayerB8F0_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int a1_guess, int a2_guess, int a3_guess, int a4_guess, int a5_guess);
    // EXTERNAL: TITANIUM 0x0047A3D0 PlayerB8F0_guess::GetArmorType_guess
    int GetArmorType_guess(int kind_guess);
    // EXTERNAL: TITANIUM 0x0048AAA6 PlayerB8F0_guess::WarpPlayer_guess
    bool WarpPlayer_guess(int zone_guess, float a2_guess, float a3_guess, float a4_guess,
                       float a5_guess, const char* reason_guess, int a7_guess);
    // EXTERNAL: TITANIUM 0x0048C130 PlayerB8F0_guess::M48C130_guess
    void M48C130_guess(float* position_guess, int value_guess);
    ActorB8F0_guess* Actor_guess() { return (ActorB8F0_guess*)pActorInfo; }
};

// The character object: two bases that share one virtual base.
struct PcBaseB8F0_guess {
    void* vftableBase_guess;
    void* p004_guess;
    int key008_guess;
    unsigned char t00C_guess[0x20];
    float fl02C_guess;
    float fl030_guess;
    float fl034_guess;
    float fl038_guess;
    char t03C_guess[0x40];
    char padding07C_guess[0x40];
    char t0BC_guess[0x40];
    signed char b0FC_guess;
    unsigned char padding0FD_guess[3];
    int zoneId_0100_guess;
    int padding104_guess;
    int i108_guess;
    unsigned char b10C_guess;
    unsigned char padding10D_guess[0x13C - 0x10D];
    int i13C_guess;
    int i140_guess;
    int i144_guess;
    int i148_guess;
};

struct PcHeadB8F0_guess {
    void* vftable_guess;
    unsigned field4_guess;
};

struct PcFirstB8F0_guess : PcHeadB8F0_guess, virtual PcBaseB8F0_guess {
    unsigned char padding000C_guess[0xBF0 - 0xC];
    int t0BF0_guess[0x40];
    unsigned char padding0CF0_guess[0xE18 - 0xCF0];
    int i0E18_guess;
    int padding0E1C_guess;
    int i0E20_guess;
    unsigned char padding0E24_guess[0xEAC - 0xE24];
    int i0EAC_guess;
    int i0EB0_guess;
    int i0EB4_guess;
    int i0EB8_guess;
    int i0EBC_guess;
    int i0EC0_guess;
    int i0EC4_guess;
    Block58B8F0_guess s0EC8_guess;
    Block58B8F0_guess s0F20_guess;
    char t0F78_guess[0x10];
    int i0F88_guess;
    int i0F8C_guess;
    unsigned char padding0F90_guess[0xFA4 - 0xF90];
    int i0FA4_guess;
    int i0FA8_guess;
    int i0FAC_guess;
    int i0FB0_guess;
    int i0FB4_guess;
    int i0FB8_guess;
    unsigned char padding0FBC_guess[0x10C0 - 0xFBC];
    char t10C0_guess[0xC280 - 0x10C0];

    // EXTERNAL: TITANIUM 0x004BACCB PcFirstB8F0_guess::SetLinkedReuseTimer_guess
    void SetLinkedReuseTimer_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004BAC0D PcFirstB8F0_guess::SetItemRecastTimer_guess
    void SetItemRecastTimer_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x004BC834 PcFirstB8F0_guess::ConsumeSlotItem_guess
    void ConsumeSlotItem_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005EE550 PcFirstB8F0_guess::M5EE550_guess
    unsigned M5EE550_guess();
    // EXTERNAL: TITANIUM 0x005F0A30 PcFirstB8F0_guess::M5F0A30_guess
    void* M5F0A30_guess();
    // EXTERNAL: TITANIUM 0x004BDC13 PcFirstB8F0_guess::M4BDC13_guess
    void M4BDC13_guess();
    // EXTERNAL: TITANIUM 0x004BA899 PcFirstB8F0_guess::Handle_OP_PlayerProfile_guess
    void Handle_OP_PlayerProfile_guess(char* data_guess, unsigned size_guess);
    // EXTERNAL: TITANIUM 0x004BABF2 PcFirstB8F0_guess::SetDisciplineTimer_guess
    void SetDisciplineTimer_guess(int first_guess, int second_guess);
};

struct PcSecondHeadB8F0_guess {
    void* vftableC280_guess;
};

struct PcSecondB8F0_guess : PcSecondHeadB8F0_guess, virtual PcBaseB8F0_guess {
    PlayerB8F0_guess* pC288_guess;
    unsigned char bC28C_guess;
    unsigned char paddingC28D_guess[0xC348 - 0xC28D];
    unsigned char bC348_guess;
    unsigned char paddingC349_guess[3];

    // EXTERNAL: TITANIUM 0x0041DB52 PcSecondB8F0_guess::RemoveOneItem_guess
    void RemoveOneItem_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00417839 PcSecondB8F0_guess::StunMe_guess
    void StunMe_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00417E07 PcSecondB8F0_guess::Cur_HP
    int Cur_HP(int value_guess);
    // EXTERNAL: TITANIUM 0x0040E7AC PcSecondB8F0_guess::GetBuff_guess
    Buff14B8F0_guess* GetBuff_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0040D933 PcSecondB8F0_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();
    // EXTERNAL: TITANIUM 0x00411161 PcSecondB8F0_guess::RemovePCAffectex_guess
    void RemovePCAffectex_guess(Buff14B8F0_guess* buff_guess, int second_guess);
};

struct PcB8F0_guess : PcFirstB8F0_guess, PcSecondB8F0_guess {
};

struct ReaderB8F0_guess {
    char* data_guess;
    unsigned size_guess;
    unsigned position_guess;
};

struct Text804B8F0_guess {
    char text_guess[0x800];
    int kind_guess;
};

struct Entry108B8F0_guess {
    int value_guess;
    int id_guess;
    char name_guess[0x100];
};

struct ZoneHeaderB8F0_guess {
    unsigned char padding000_guess[0x177];
    unsigned char b177_guess;
    unsigned char padding178_guess[3];
    unsigned char b17B_guess;
    unsigned char padding17C_guess[3];
    unsigned char b17F_guess;
    unsigned char padding180_guess[4];
    float fl184_guess;
    unsigned char padding188_guess[0x194 - 0x188];
    float fl194_guess;
    unsigned char padding198_guess[0x1DA - 0x198];
    unsigned char b1DA_guess;
    unsigned char padding1DB_guess[0x200 - 0x1DB];
    float fl200_guess;
    float fl204_guess;
    unsigned char padding208_guess[0x250 - 0x208];
    int i250_guess;
    unsigned char padding254_guess[0x25C - 0x254];
    char t25C_guess[0x20];
    char t27C_guess[0x20];
    unsigned char padding29C_guess[0x2BC - 0x29C];
};

struct EverQuestB8F0_guess {
    unsigned char padding00000_guess[0xB50];
    int i00B50_guess;
    int i00B54_guess;
    unsigned char padding00B58_guess[0x39400 - 0xB58];
    int i39400_guess;
    unsigned char padding39404_guess[0x3A1BC - 0x39404];
    HWND window3A1BC_guess;

    // EXTERNAL: TITANIUM 0x004A8CD5 EverQuestB8F0_guess::ReportDeath_guess
    void ReportDeath_guess(int* packet_guess);
    // EXTERNAL: TITANIUM 0x00494C09 EverQuestB8F0_guess::IsOkToTransact_guess
    bool IsOkToTransact_guess();
    // EXTERNAL: TITANIUM 0x0049297B EverQuestB8F0_guess::BeingIgnored_guess
    int BeingIgnored_guess(char* name_guess);

    // EXTERNAL: TITANIUM 0x00492E6E EverQuestB8F0_guess::StripShipName_guess
    char* StripShipName_guess(char* source_guess, char* destination_guess);
    // EXTERNAL: TITANIUM 0x004AB056 EverQuestB8F0_guess::MoveToZone_guess
    void MoveToZone_guess(int zone_guess, const char* reason_guess, int third_guess, int fourth_guess,
                       float y_guess, float x_guess, float z_guess, int heading_guess);
    // EXTERNAL: TITANIUM 0x00494B3D EverQuestB8F0_guess::SetGameState
    void SetGameState(int value_guess);
    // EXTERNAL: TITANIUM 0x00491C04 EverQuestB8F0_guess::PrepareLocalPCForRepop_guess
    void PrepareLocalPCForRepop_guess();
    // EXTERNAL: TITANIUM 0x0049B39D EverQuestB8F0_guess::StartCasting_guess
    void StartCasting_guess(int* packet_guess);
    // EXTERNAL: TITANIUM 0x004A1CE4 EverQuestB8F0_guess::CancelSneakHide
    void CancelSneakHide();
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestB8F0_guess::M492EC2_guess
    char* M492EC2_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x004932AB EverQuestB8F0_guess::DisplayScreen_guess
    void DisplayScreen_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x0049BEB8 EverQuestB8F0_guess::Consider
    void Consider(PlayerB8F0_guess* player_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x00496DCD EverQuestB8F0_guess::ReleasePendingRequest_guess
    void ReleasePendingRequest_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049D654 EverQuestB8F0_guess::HandleGroupInvite_guess
    void HandleGroupInvite_guess(unsigned opcode_guess, char* data_guess);
    // EXTERNAL: TITANIUM 0x0049D300 EverQuestB8F0_guess::doUnInvite_guess
    void doUnInvite_guess(char* data_guess);

    unsigned char HandleWorldMessage_guess(void* connection_guess, unsigned opcode_guess,
                                      char* data_guess, unsigned size_guess);
};

#define gPcB8F0_guess EQ_GLOBAL(PcB8F0_guess*, 0x00905D00)
#define gPlayerB8F0_guess EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CE4)
#define gTargetB8F0_guess EQ_GLOBAL(PlayerB8F0_guess*, 0x00905D04)
#define gDisplayB8F0_guess EQ_GLOBAL(DisplayB8F0_guess*, 0x00905D24)
#define gZoneB8F0_guess EQ_GLOBAL(ZoneHeaderB8F0_guess, 0x009239E0)
#define gPcBaseB8F0_guess (&gPcB8F0_guess->vftableBase_guess)
#define gPcSecondB8F0_guess ((PcSecondB8F0_guess*)&gPcB8F0_guess->vftableC280_guess)
#define gProfileB8F0_guess \
    ((ProfileB8F0_guess*)((EQ_CharacterProfile_guess*)&gPcB8F0_guess->p004_guess)->GetCharInfo2())

#define pinstCRespawnWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850BC4)
#define pinstCBandolierWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850BC8)
#define pinstCCharacterCreation_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850C20)
#define pinstCTrackingWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850C64)
#define pinstCSoulmarkWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850C9C)
#define pinstCBodyTintWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850CAC)
#define pinstCServerListWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00850CB0)
#define pinstCAltStorageWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991434)
#define pinstCGuildBankWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991A90)
#define pinstCLFGuildWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991C40)
#define pinstCPointMerchantWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991E28)
#define pinstCProgressionSelectionWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991E78)
#define pinstCPvpLeaderboardWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991E94)
#define pinstCPvPStatsWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991EB0)
#define pinstCLargeDialogWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00991F5C)
#define pinstCTaskSelectWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x00992820)
#define pinstCTitleWnd_guess EQ_GLOBAL(ObjB8F0_guess*, 0x009928FC)

// FUNCTION: TITANIUM 0x0045B8F0
// @early-stop: budget, structural ndiff=5086
// The zone message dispatcher: one case per Titanium opcode, payload in data_guess/size_guess. Case labels
// are EQEmu's OP_ names (patch_Titanium.conf); a literal label has no unique name there (a trailing comment
// gives the candidates). Returns 1, except 0 when OP_ZoneEntry's handler fails.
unsigned char EverQuestB8F0_guess::HandleWorldMessage_guess(void* connection_guess, unsigned opcode_guess,
                                                       char* data_guess, unsigned size_guess) {
    // The OP_ names on the cases below are EQEmu names (patch_Titanium.conf); a case without one has only its
    // number. The client's own names survive in a few log strings (MSG_ZONE_ADDRESS, MSG_SEND_PC,
    // MSG_TIME_STAMP...). Two switches: this one always runs; the second, further down, only once the display
    // object reports the world as loaded (0x0043745D).
    int* words_guess = (int*)data_guess;
    float* floats_guess = (float*)data_guess;
    unsigned char* bytes_guess = (unsigned char*)data_guess;
    CEverQuest* chat_guess = (CEverQuest*)this;

    switch (opcode_guess) {
    // Cases are in the order of the original code, not by topic. Cases by area (opcode values, hex):
    // - zone connect: 0x61B6 OP_ZoneServerInfo, 0x75DF OP_PlayerProfile, 0x7213 OP_ZoneEntry, 0x920
    //   OP_NewZone, 0x1580 OP_TimeOfDay, 0x254D OP_Weather, 0x2E78 OP_ZoneSpawns; refusals 0x3A80, 0x4BC6,
    //   0x407C OP_ZoneUnavail, 0x436A OP_CharInacessable, 0x583B OP_WorldLevelTooHigh.
    // - leaving: logout 0xF66, zone drop 0x2BAF, OP_GMKick 0x692C, 0x7D37 OP_WorldChecksumFailure; zone
    //   changes 0xB71 (boat), 0x1CEE OP_GMGoto, 0x1EDC OP_GMSummon, 0x385E OP_ZonePlayerToBind, 0x1306
    //   OP_GMZoneRequest.
    // - spawns: 0x1860 OP_NewSpawn, 0x55BC OP_DeleteSpawn, 0x498 OP_MobRename, 0x15B8 and 0x4B09 levels,
    //   targets 0x1477 OP_TargetCommand / 0x5104 OP_AssistGroup / 0x7709 OP_Assist, 0x65CA OP_Consider,
    //   0x2C81 OP_ControlBoat.
    // - items and coin: 0x3397 OP_ItemPacket, 0x420F OP_MoveItem, 0x4D81 OP_DeleteItem, 0x1C4A
    //   OP_DeleteCharge, 0x5394 OP_CharInventory, 0x463B OP_MoveMultipleItems, 0x4848 OP_Split, 0x541E
    //   OP_Sound, 0x1FA3, 0x6A5B OP_BankerChange, 0x267C OP_MoneyUpdate.
    // - spells: 0x308E OP_MemorizeSpell, 0x3990 OP_BeginCast, 0xB97 OP_InterruptCast, 0x6A53 OP_Buff, 0x4839
    //   OP_ManaChange, 0xA2A spellbook, 0x2126 OP_SwapSpell, 0x4F37 OP_DeleteSpell, 0x403E OP_LoadSpellSet.
    // - doors (list at 0x00903E84): 0x4C24 OP_SpawnDoor, 0x1BFE, 0x5A4D, 0x5B71, 0x700D OP_MoveDoor, 0x77D0
    //   OP_RemoveAllDoors.
    // - GM tools: 0x10A6 / 0x504 petitions, 0x9C / 0x46B1 name approval, 0x5930 OP_GMFind, 0x6980 OP_GMKill,
    //   0x3C32 OP_GMSearchCorpse, 0x7864 OP_GMBecomeNPC.
    // - whole families go to their subsystem: tasks (0x0079DC78), tribute and guild tribute (0x00850350),
    //   leadership (0x009859EC, GoD accounts only), 0xF40.. (0x00985CF0, after OP_LogServer allows it).
    case OP_Dye:
        if (pinstCBodyTintWnd_guess != 0 && pinstCBodyTintWnd_guess->M59DD30_guess()) {
            pinstCBodyTintWnd_guess->M4E7992_guess();
        }
        break;
    case OP_SetChatServer:
        Handle_OP_SetChatServer_guess((int)data_guess);
        break;
    case 0x9c:
        Handle_NameChangeApprovalRequest_guess((Argument4546E2_guess*)data_guess);
        break;
    case 0xb7:
        break;
    // Opcode 0x11D (not in patch_Titanium.conf): {current id, two words, count, then per entry an id, five
    // words and a string} for the window at 0x00850BC4. The window is RespawnWnd (tu_207); with it closed
    // only the current id is read and sent back as 0x11D (4 bytes), so the server's marked option stands.
    case 0x11d: {
        ReaderB8F0_guess reader_guess;
        int first_guess = 0;
        int second_guess = 0;
        int third_guess = 0;
        unsigned count_guess = 0;
        reader_guess.size_guess = size_guess;
        reader_guess.data_guess = data_guess;
        reader_guess.position_guess = 0;
        ((Reader454FCD_guess*)&reader_guess)->Read_guess(&first_guess, 4);
        if (pinstCRespawnWnd_guess != 0) {
            ((Reader454FCD_guess*)&reader_guess)->Read_guess(&second_guess, 4);
            ((Reader454FCD_guess*)&reader_guess)->Read_guess(&third_guess, 4);
            pinstCRespawnWnd_guess->InitRespawnList_guess(third_guess, second_guess);
            ((Reader454FCD_guess*)&reader_guess)->Read_guess(&count_guess, 4);
            for (unsigned index_guess = 0; index_guess < count_guess; index_guess++) {
                char text_guess[0x200] = "";
                int id_guess;
                FiveWords454FCD_guess five_guess;
                ((Reader454FCD_guess*)&reader_guess)->Read_guess(&id_guess, 4);
                five_guess.Read_guess((Reader454FCD_guess*)&reader_guess);
                ((StringReader454F79_guess*)&reader_guess)->ReadString_guess(text_guess, 0x200);
                pinstCRespawnWnd_guess->AddRespawnOption_guess(id_guess == first_guess, id_guess,
                                                         five_guess, text_guess);
            }
            ((VirtB8F0_guess*)pinstCRespawnWnd_guess)->V084_guess();
        } else {
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x11d, &first_guess, 4, 1);
        }
        break;
    }
    case 0x2fe:
        if (gPlayerB8F0_guess != 0 && gPlayerB8F0_guess->Actor_guess() != 0) {
            gPlayerB8F0_guess->Actor_guess()->i1060_guess = 1;
        }
        break;
    case 0x261:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            EQ_GLOBAL(unsigned char, 0x0092384D) = 0;
        }
        break;
    case 0x13d: {
        Text804B8F0_guess* entry_guess = new Text804B8F0_guess();
        Ext576FA0_guess(entry_guess->text_guess, pStringTable->getString(0x11cf, 0), 0x800);
        entry_guess->kind_guess = 0xd;
        EQ_GLOBAL(ObjB8F0_guess, 0x0095D3C4).M50319B_guess(EQ_GLOBAL(void*, 0x0095D3C4),
                                                          &entry_guess);
        break;
    }
    case 0x504:
        UpdatePetitionQueue_guess((Entry451E54_guess*)data_guess);
        break;
    case OP_ExpansionInfo:
        Handle_OP_ExpansionInfo((unsigned*)data_guess);
        break;
    case OP_MobRename: {
        PlayerB8F0_guess* player_guess = Ext47C88E_guess(data_guess);
        if (player_guess != 0 && words_guess[0x31] != 0) {
            player_guess->M47C3EF_guess(data_guess + 0x80);
            if (player_guess->SpawnID == gPlayerB8F0_guess->SpawnID) {
                ((ObjB8F0_guess*)gPcB8F0_guess->t03C_guess)->M40E25C_guess(data_guess + 0x80);
            }
            player_guess->RefreshNameSprite_guess();
        }
        break;
    }
    case 0x37f:
        if (gPcB8F0_guess != 0 && gPlayerB8F0_guess != 0 && gPlayerB8F0_guess->Actor_guess() != 0
            && gPlayerB8F0_guess->Actor_guess()->i1048_guess != 0
            && ((ObjB8F0_guess*)&gPlayerB8F0_guess->Actor_guess()->i1050_guess)
                   ->GetInventorySlot_guess((PcSecondB8F0_guess*)gPcB8F0_guess) != 0) {
            int current_guess = gPlayerB8F0_guess->Actor_guess()->i1048_guess;
            if (*((ObjB8F0_guess*)&gPlayerB8F0_guess->Actor_guess()->i1050_guess)
                     ->GetInventorySlot_guess((PcSecondB8F0_guess*)gPcB8F0_guess) == current_guess) {
                gPcB8F0_guess->SetItemRecastTimer_guess(
                    gPlayerB8F0_guess->Actor_guess()->b104C_guess != 0
                        ? gPlayerB8F0_guess->Actor_guess()->i1048_guess : 0,
                    words_guess[0], words_guess[1]);
            }
        }
        break;
    // OP_VetRewardsAvaliable: 0x108-byte rewards. Each reward id is printed once; a second entry with the
    // same id is folded into the line as the second name (0xE23 instead of 0xE22) and blanked.
    case OP_VetRewardsAvaliable: {
        EQ_GLOBAL(ObjB8F0_guess, 0x0095D3B4).M50F3F6_guess();
        int count_guess = size_guess / 0x108;
        if (count_guess > 0) {
            chat_guess->dsp_chat(pStringTable->getString(0xd15, 0), 0xf, 1);
            Entry108B8F0_guess* entries_guess = (Entry108B8F0_guess*)data_guess;
            for (int index_guess = 0; index_guess < count_guess; index_guess++) {
                Entry108B8F0_guess* entry_guess = &entries_guess[index_guess];
                if (entry_guess->id_guess != 0) {
                    char* names_guess[2];
                    char number_guess[0x20];
                    char line_guess[0x10000];
                    int found_guess = 1;
                    names_guess[0] = entry_guess->name_guess;
                    for (int other_guess = index_guess + 1; other_guess < count_guess;
                         other_guess++) {
                        if (found_guess >= 2) {
                            break;
                        }
                        if (entries_guess[other_guess].id_guess == entry_guess->id_guess) {
                            names_guess[found_guess++] = entries_guess[other_guess].name_guess;
                            entries_guess[other_guess].id_guess = 0;
                        }
                    }
                    if (found_guess > 2) {
                        continue;
                    }
                    _itoa(entry_guess->value_guess, number_guess, 10);
                    EQ_GLOBAL(ObjB8F0_guess, 0x0095D3B4).M50319B_guess(
                        EQ_GLOBAL(void*, 0x0095D3B4), &entry_guess->value_guess);
                    if (found_guess == 1) {
                        Ext46DA4A_guess(line_guess, 0xe22, number_guess, names_guess[0], 0, 0, 0,
                                        0, 0, 0, 0);
                    } else if (found_guess == 2) {
                        Ext46DA4A_guess(line_guess, 0xe23, number_guess, names_guess[0],
                                        names_guess[1], 0, 0, 0, 0, 0, 0);
                    }
                    chat_guess->dsp_chat(line_guess, 0xf, 1);
                }
            }
        }
        break;
    }
    case OP_LFPGetMatchesResponse:
        Handle_OP_LFPGetMatchesResponse_guess(data_guess, size_guess);
        break;
    case OP_AAAction:
        Handle_OP_AAAction_guess((Argument452D41_guess*)data_guess);
        break;
    case 0x721:
        if (gPcB8F0_guess != 0) {
            gPcB8F0_guess->RemoveOneItem_guess(words_guess[0], words_guess[1]);
        }
        break;
    case 0x7e0:
        break;
    case 0x8df:
        pEverQuest->dsp_chat(data_guess, 0x145, 1);
        break;
    // OP_NewZone: the 0x2BC-byte NewZone_Struct lands in the zone header at 0x009239E0. A zone that sends no
    // fog planes gets 500/600 and grey 0xC0. The near clip (+0x200) is kept at least 50; a far clip (+0x204)
    // under 51 becomes 4 x the fog end, and one below the near clip 4 x the near clip. When +0x250 changes
    // every actor is refreshed so the new value takes effect at once.
    case OP_NewZone: {
        int previous_guess = gZoneB8F0_guess.i250_guess;
        memcpy(&gZoneB8F0_guess, data_guess, 0x2bc);
        if (gZoneB8F0_guess.fl184_guess == 0.0f && gZoneB8F0_guess.fl194_guess == 0.0f) {
            gZoneB8F0_guess.fl184_guess = 500.0f;
            gZoneB8F0_guess.fl194_guess = 600.0f;
            gZoneB8F0_guess.b177_guess = 0xc0;
            gZoneB8F0_guess.b17B_guess = 0xc0;
            gZoneB8F0_guess.b17F_guess = 0xc0;
        }
        if (gZoneB8F0_guess.fl200_guess < 50.0f) {
            gZoneB8F0_guess.fl200_guess = 50.0f;
        }
        if (gZoneB8F0_guess.fl204_guess < EQ_GLOBAL(const float, 0x00644F70)) {
            gZoneB8F0_guess.fl204_guess = gZoneB8F0_guess.fl194_guess * 4.0f;
        }
        if (gZoneB8F0_guess.fl204_guess < gZoneB8F0_guess.fl200_guess) {
            gZoneB8F0_guess.fl204_guess = gZoneB8F0_guess.fl200_guess * 4.0f;
        }
        gDisplayB8F0_guess->M43A650_guess(gZoneB8F0_guess.t25C_guess);
        gDisplayB8F0_guess->SetSecondarySkyName_guess(gZoneB8F0_guess.t27C_guess, 0.0f);
        gDisplayB8F0_guess->b2D2C_guess = gZoneB8F0_guess.b1DA_guess != 0;
        gDisplayB8F0_guess->SetSkyBackground_guess();
        EQ_GLOBAL(unsigned char, 0x00923C9C) = 1;
        if (previous_guess != gZoneB8F0_guess.i250_guess) {
            for (PlayerB8F0_guess* player_guess = EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CC4);
                 player_guess != 0; player_guess = (PlayerB8F0_guess*)player_guess->pNext) {
                if (player_guess->Actor_guess() != 0) {
                    player_guess->SetHeights_guess();
                    if (player_guess->Actor_guess()->actorInstance_0000_guess != 0) {
                        ActorB8F0_guess* actor_guess = player_guess->Actor_guess();
                        actor_guess->actorInstance_0000_guess->V050_guess(actor_guess->fl0C4_guess, 1);
                    }
                }
            }
        }
        break;
    }
    // Opcode 0xAC0: word 0 == 0 ends the zone-in wait like OP_ZoneUnavail does (0x00904228, 0x00923880).
    case 0xac0:
        if (words_guess[0] == 0) {
            EQ_GLOBAL(int, 0x00904228) = 1;
            EQ_GLOBAL(int, 0x00923880) = 0;
        }
        EQ_GLOBAL(int, 0x00905CB4) = 1;
        break;
    case 0xa2a:
        Handle_SpellBookUpdate_guess((Argument459985_guess*)data_guess);
        break;
    case OP_CameraEffect:
        GetCameraShake_guess()->StartShake_guess(floats_guess[1], words_guess[0]);
        break;
    // Boat transfer (0xB71): when the name is this character's, zone to `zone_guess` at the current spot with
    // a vehicle-transfer reason.
    case 0xb71: {
        struct {
            char name_guess[0x40];
            int zone_guess;
        } transfer_guess;
        char first_guess[0x100];
        char second_guess[0x100];
        memcpy(&transfer_guess, data_guess, 0x44);
        char* own_guess = gPcB8F0_guess->t0BC_guess;
        if (__stricmp(StripShipName_guess(own_guess, first_guess),
                      StripShipName_guess(transfer_guess.name_guess, second_guess)) == 0) {
            EQ_GLOBAL(unsigned char, 0x00924675) = 1;
            float z_guess = gPcB8F0_guess->fl034_guess;
            float x_guess = gPcB8F0_guess->fl030_guess;
            float y_guess = gPcB8F0_guess->fl02C_guess;
            MoveToZone_guess(transfer_guess.zone_guess, "vehicle xfr", 0, 2, y_guess, x_guess,
                          z_guess, (int)gPcB8F0_guess->fl038_guess);
            ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x0099E364))->V094_guess();
            ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x0099E364))->V094_guess();
        }
        break;
    }
    case OP_ApplyPoison:
        Handle_OP_ApplyPoison_guess((Argument452D85_guess*)data_guess);
        break;
    case OP_GuildWar:
        Handle_OP_GuildWar_guess((Argument453ABB_guess*)data_guess);
        break;
    case 0xe37:
        SetSpawnHitPoints_guess((DispatchRequest_guess*)data_guess);
        break;
    // 0xF66; the client's own log text calls it MSG_LOGOUT_PLAYER.
    case 0xf66:
        Ext574110_guess("****MSG_LOGOUT_PLAYER RECVD:DISCONNECTING (RECV_PKT)");
        EQ_GLOBAL(ObjB8F0_guess*, 0x0079DBD8)->M42500C_guess(EQ_ARRAY(char, 0x00905CA0));
        MessageBoxA(window3A1BC_guess, "Logout", "Window", 0);
        DestroyWindow(window3A1BC_guess);
        break;
    // OP_LogServer: world settings at login. Byte +0x104 (0x00923D64) gates the subsystem behind the 0xF40
    // family at the end of this switch.
    case OP_LogServer:
        EQ_GLOBAL(int, 0x00900478) = words_guess[1];
        EQ_GLOBAL(int, 0x0090047C) = words_guess[0];
        EQ_GLOBAL(int, 0x00923D58) = EQ_GLOBAL(int, 0x00900478);
        EQ_GLOBAL(int, 0x00923D5C) = EQ_GLOBAL(int, 0x0090047C);
        EQ_GLOBAL(int, 0x00923D68) = words_guess[2];
        EQ_GLOBAL(int, 0x00923D6C) = words_guess[3];
        EQ_GLOBAL(int, 0x00923D70) = words_guess[4];
        EQ_GLOBAL(int, 0x00923D60) = words_guess[5];
        EQ_GLOBAL(unsigned char, 0x00923D64) = bytes_guess[0x104];
        EQ_GLOBAL(unsigned char, 0x00923D65) = bytes_guess[0x106];
        EQ_GLOBAL(unsigned char, 0x00923D66) = bytes_guess[0x107];
        break;
    case OP_ChannelMessage:
        Handle_OP_ChannelMessage_guess((ChatMessage459B94_guess*)data_guess);
        break;
    case OP_RezzRequest:
        Handle_OP_RezzRequest_guess((Argument459A46_guess*)data_guess);
        break;
    case 0x10a6:
        Handle_PetitionCheckout_guess((int*)data_guess, size_guess);
        break;
    case 0x128c:
        if (pinstCSoulmarkWnd_guess != 0) {
            pinstCSoulmarkWnd_guess->UpdateSoulmarks_guess(data_guess);
        }
        break;
    // The server picks the target (OP_TargetCommand, OP_AssistGroup) when the spawn id is known; the old
    // target's spawn id is saved at +0xF0 of the object returned by 0x004C94AE.
    case OP_TargetCommand:
    case OP_AssistGroup: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
        if (player_guess != 0) {
            if (gTargetB8F0_guess != 0) {
                unsigned id_guess = gTargetB8F0_guess->SpawnID;
                Ext4C94AE_guess()->i0F0_guess = id_guess;
            }
            gTargetB8F0_guess = player_guess;
        }
        break;
    }
    // OP_GMZoneRequest reply: on success (+0x54 == 1) for the zone this character asked for (0x0092467C), it
    // is placed at the reply's position with all motion cleared; otherwise the result is stored.
    case OP_GMZoneRequest:
        if (gPcB8F0_guess != 0) {
            if (__stricmp(gPcB8F0_guess->t03C_guess, data_guess) == 0
                && EQ_GLOBAL(int, 0x0092467C) == words_guess[0x10] && words_guess[0x15] == 1) {
                gPlayerB8F0_guess->Actor_guess()->i158_guess = 0;
                ((ObjB8F0_guess*)gPcB8F0_guess->t0BC_guess)
                    ->M40E25C_guess(EQ_ARRAY(char, 0x0063F53F));
                gPlayerB8F0_guess->Y = floats_guess[0x11];
                gPlayerB8F0_guess->X = floats_guess[0x12];
                gPlayerB8F0_guess->Z = floats_guess[0x13];
                gPlayerB8F0_guess->Heading = floats_guess[0x14];
                gPlayerB8F0_guess->field_50 = 0.0f;
                gPlayerB8F0_guess->SpeedY = 0.0f;
                gPlayerB8F0_guess->SpeedX = 0.0f;
                gPlayerB8F0_guess->SpeedZ = 0.0f;
                gPlayerB8F0_guess->field_58 = 0.0f;
                gPlayerB8F0_guess->field_54 = 0.0f;
                gPlayerB8F0_guess->SpeedRun = 0.0f;
                EQ_GLOBAL(int, 0x00924678) = 1;
            } else {
                EQ_GLOBAL(int, 0x00924678) = words_guess[0x15];
                EQ_GLOBAL(int, 0x0092467C) = 0;
            }
        }
        break;
    case OP_Charm:
        Handle_OP_Charm_guess((Argument453D7B_guess*)data_guess);
        break;
    // OP_ReadBook: byte 1 picks the window: 0 the note window (0x00850BA4, tu_191 NoteWnd), 1 the book window
    // (0x00850BA8, tu_134 BookWnd), 2 the item display at 0x00991B88.
    case OP_ReadBook: {
        int first_guess = (signed char)data_guess[0];
        int kind_guess = (signed char)data_guess[1];
        char* body_guess = data_guess + 2;
        if (kind_guess == 0) {
            if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA4) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA4)->M53A8B8_guess(body_guess);
                ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA4))->V084_guess();
            }
        } else if (kind_guess == 1) {
            if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA8) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA8)->SetBookText_guess(body_guess);
                ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x00850BA8))->V084_guess();
            }
        } else if (kind_guess == 2) {
            if (EQ_GLOBAL(ObjB8F0_guess*, 0x00991B88) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00991B88)->M51E099_guess(body_guess, first_guess);
            }
        }
        break;
    }
    case 0x15b8:
        if (gPlayerB8F0_guess != 0 && gPcB8F0_guess != 0
            && (unsigned)words_guess[0] == gPlayerB8F0_guess->SpawnID) {
            SetCharacterLevel_guess(gPcB8F0_guess, bytes_guess[4]);
            gPlayerB8F0_guess->Level = (unsigned char)gProfileB8F0_guess->level_11a4_guess;
        }
        break;
    // OP_TimeOfDay (MSG_TIME_STAMP in the client's log text): four bytes and a word (EQEmu: hour, minute,
    // day, month, year) go to both the current and the base game time; +0x14 and +0x18 take the local clocks
    // (0x0046D655 in ms, and time()).
    case OP_TimeOfDay: {
        struct {
            unsigned char b0_guess;
            unsigned char b1_guess;
            unsigned char b2_guess;
            unsigned char b3_guess;
            int value4_guess;
        } stamp_guess;
        Ext574110_guess("MSG_TIME_STAMP received.\n");
        memcpy(&stamp_guess, data_guess, 8);
        gWorldB8F0_guess->b04_guess = stamp_guess.b0_guess;
        gWorldB8F0_guess->b05_guess = stamp_guess.b1_guess;
        gWorldB8F0_guess->b06_guess = stamp_guess.b2_guess;
        gWorldB8F0_guess->b07_guess = stamp_guess.b3_guess;
        gWorldB8F0_guess->i08_guess = stamp_guess.value4_guess;
        gWorldB8F0_guess->b0C_guess = gWorldB8F0_guess->b04_guess;
        gWorldB8F0_guess->b0D_guess = gWorldB8F0_guess->b05_guess;
        gWorldB8F0_guess->b0E_guess = gWorldB8F0_guess->b06_guess;
        gWorldB8F0_guess->b0F_guess = gWorldB8F0_guess->b07_guess;
        gWorldB8F0_guess->i10_guess = gWorldB8F0_guess->i08_guess;
        gWorldB8F0_guess->i18_guess = Ext576E80_guess();
        gWorldB8F0_guess->i14_guess = Ext46D655_guess();
        gDisplayB8F0_guess->SetSkyBackground_guess();
        Ext574110_guess("MSG_TIME_STAMP received. (Items inc).\n");
        break;
    }
    case 0x167d:
        FUN_004569d4_guess((Target4569D4_guess*)data_guess);
        break;
    case 0x161c:
        UpdateMIZoneSelectWnd_guess((int)data_guess);
        break;
    case OP_LFGuild:
        if (pinstCLFGuildWnd_guess != 0) {
            pinstCLFGuildWnd_guess->M529EEA_guess(0x1858, data_guess, size_guess);
        }
        break;
    case OP_DuelAccept:
        break;
    // OP_QueryResponseThing.
    case 0x1974:  // OP_QueryResponseThing
        SendMetadata_guess((int*)data_guess);
        break;
    case OP_GuildInvite:
        Handle_OP_GuildInvite_guess((int)connection_guess, 0x18b7, data_guess);
        break;
    case 0x186d:
        Handle_GuildWarFailed_guess((Argument453ABB_guess*)data_guess);
        break;
    case OP_NewSpawn:
        Handle_OP_NewSpawn_guess((PlayerSource4554E5_guess*)data_guess);
        break;
    case 0x1a87:
        EmitSpellEffectsOnSpawns_guess((int*)data_guess, 1);
        break;
    case OP_LFGAppearance:
        Handle_OP_LFGAppearance_guess((Argument453134_guess*)data_guess);
        break;
    case OP_Marquee:
        Ext407DC9_guess()->DisplayText(data_guess + 0x18, words_guess[0], words_guess[1],
                                         words_guess[2], words_guess[3], words_guess[4],
                                         words_guess[5]);
        break;
    case 0x1d43:
        DispatchPackedIdPacket_guess((int*)data_guess);
        break;
    // OP_GMGoto: 0x857 when there is no player. Ignored in a character state other than 0 (+0xFC), without
    // control (StandState 0x66) or while controlling another spawn; same zone moves at once, another zone is
    // a zone change with a goto-player reason.
    case OP_GMGoto: {
        if (gPlayerB8F0_guess == 0) {
            char line_guess[0x200];
            sprintf(line_guess, pStringTable->getString(0x857, 0));
            pEverQuest->dsp_chat(line_guess, 0xa, 1);
            break;
        }
        PlayerB8F0_guess* other_guess = EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CF8);
        if (other_guess != gPlayerB8F0_guess && gPlayerB8F0_guess->Actor_guess()->mount_015c_guess == 0) {
            break;
        }
        if (gPcB8F0_guess->b0FC_guess > 0) {
            break;
        }
        if (other_guess->StandState == 0x66) {
            break;
        }
        float x_guess = floats_guess[0x22];
        float y_guess = floats_guess[0x23];
        float z_guess = floats_guess[0x24];
        int zone_guess = words_guess[0x21];
        if (zone_guess == gPcB8F0_guess->zoneId_0100_guess) {
            float position_guess[3];
            position_guess[0] = x_guess;
            position_guess[1] = y_guess;
            position_guess[2] = z_guess;
            gPlayerB8F0_guess->WarpToPosition_guess(position_guess, 0.0f);
        } else {
            MoveToZone_guess(zone_guess, "goto player", 0, 5, x_guess, y_guess, z_guess,
                          (int)gPlayerB8F0_guess->Heading);
        }
        break;
    }
    // Opcode 0x1C91 lists this account's expansions (bits as in Handle_OP_ExpansionInfo); 0x5FEC is the
    // version for another character.
    case 0x1c91: {
        char text_guess[0x200];
        unsigned flags_guess = words_guess[0x11];
        sprintf(text_guess, "Your expansion settings are: ", flags_guess);
        if (flags_guess == 0) {
            strcat(text_guess, "None");
        } else {
            if (flags_guess & 1) {
                strcat(text_guess, "Kunark ");
            }
            if (flags_guess & 2) {
                strcat(text_guess, "Velious ");
            }
            if (flags_guess & 4) {
                strcat(text_guess, "Luclin ");
            }
            if (flags_guess & 8) {
                strcat(text_guess, "PoP ");
            }
            if (flags_guess & 0x10) {
                strcat(text_guess, "Ykesha ");
            }
            if (flags_guess & 0x20) {
                strcat(text_guess, "LDoN ");
            }
            if (flags_guess & 0x40) {
                strcat(text_guess, "Gates ");
            }
            if (flags_guess & 0x80) {
                strcat(text_guess, "Omens ");
            }
            if (flags_guess & 0x100) {
                strcat(text_guess, EQ_ARRAY(char, 0x00644E64));
            }
            if (flags_guess & 0x200) {
                strcat(text_guess, "Darkhollow");
            }
        }
        gPcB8F0_guess->i108_guess = flags_guess;
        pEverQuest->dsp_chat(text_guess);
        break;
    }
    case OP_DeleteCharge:
        if (Handle_OP_DeleteCharge_guess(words_guess[0], words_guess[1], words_guess[2]) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x56e, 0), 0xf, 1);
        }
        break;
    // One door by id (byte +0x3C): flag +0x4F clear removes it, set updates or adds it. New doors with +0x90
    // == 0 are dropped unless their type (+0x22) is 0x35.
    case 0x1bfe: {
        ObjB8F0_guess* found_guess = EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490547_guess(bytes_guess[0x3c], 0);
        if (found_guess != 0) {
            if (bytes_guess[0x4f] == 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M49058F_guess(found_guess);
            } else {
                found_guess->M490449_guess(data_guess);
            }
        } else if (bytes_guess[0x4f] != 0) {
            New490A43B8F0_guess* entry_guess = new New490A43B8F0_guess(data_guess);
            if (entry_guess->i90_guess == 0 && entry_guess->b22_guess != 0x35) {
                delete entry_guess;
            } else {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490580_guess(entry_guess);
            }
        }
        break;
    }
    case 0x5a4d: {
        New490A43B8F0_guess* entry_guess = new New490A43B8F0_guess(data_guess);
        if (entry_guess->i90_guess == 0 && entry_guess->b22_guess != 0x35) {
            delete entry_guess;
        } else {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490580_guess(entry_guess);
        }
        break;
    }
    case OP_Stun:
        if (gPcB8F0_guess != 0) {
            gPcB8F0_guess->StunMe_guess(words_guess[0], 0, 0);
        }
        break;
    case 0x1fa3: {
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D70_guess(words_guess[3]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D46_guess(words_guess[2]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D1C_guess(words_guess[1]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417CF2_guess(words_guess[0]);
        break;
    }
    // OP_RaidJoin / OP_RaidUpdate.
    case 0x1f21:  // OP_RaidJoin / OP_RaidUpdate
        EQ_GLOBAL(ObjB8F0_guess, 0x0091D708).HandleS2CRaidMessage_guess(data_guess);
        break;
    // OP_GMSummon: string 0x571 (summoned), then the move or a zone change with a summon reason.
    case OP_GMSummon:
        if (gPlayerB8F0_guess != 0) {
            float x_guess = floats_guess[0x22];
            float y_guess = floats_guess[0x23];
            float z_guess = floats_guess[0x24];
            int heading_guess = (int)gPlayerB8F0_guess->Heading;
            if (words_guess[0x21] == gPcB8F0_guess->zoneId_0100_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x571, 0), 0xf, 1);
                float position_guess[3];
                position_guess[0] = x_guess;
                position_guess[1] = y_guess;
                position_guess[2] = z_guess;
                gPlayerB8F0_guess->WarpToPosition_guess(position_guess, (float)heading_guess);
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x571, 0), 0xf, 1);
                MoveToZone_guess(words_guess[0x21], "summon player", 0, 3, x_guess, y_guess, z_guess,
                              heading_guess);
                gPlayerB8F0_guess->M48C11B_guess();
            }
            gPlayerB8F0_guess->UpdateSharedValuesIfLocal_guess();
        }
        break;
    case 0x201d:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            EQ_GLOBAL(unsigned char, 0x00923898) = 0;
        }
        break;
    case OP_GuildPeace:
        Handle_OP_GuildPeace_guess((Argument453ABB_guess*)data_guess);
        break;
    case OP_SwapSpell:
        EQ_GLOBAL(ObjB8F0_guess*, 0x00850C30)->SwapSpellBookSlots_guess(words_guess[0], words_guess[1]);
        break;
    case OP_ClearObject:
        Handle_OP_ClearObject_guess((StateRequest_guess*)data_guess);
        break;
    case OP_InspectAnswer:
        Handle_OP_InspectAnswer_guess((unsigned)data_guess);
        break;
    case OP_GMLastName:
        Handle_OP_GMLastName_guess((Target570Argument_guess*)data_guess);
        break;
    // OP_Weather; the client's own log text calls it MSG_WEATHER_EVENT.
    case OP_Weather:
        Ext574110_guess("Item done, MSG_WEATHER_EVENT received.\n");
        EQ_GLOBAL(int, 0x00923D24) = 1;
        Ext4C32FF_guess()->M4C334D_guess(data_guess);
        break;
    case OP_MoneyUpdate:
        Handle_OP_MoneyUpdate_guess((int*)data_guess);
        break;
    // 0x25AA, 0x3013: the named character is stunned: frozen (stand state 0x66), +0xFC = 2, no running.
    // 0x210B / 0x583D below undo it.
    case 0x25aa:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            gPlayerB8F0_guess->StandState = 0x66;
            gPcB8F0_guess->b0FC_guess = 2;
            gPlayerB8F0_guess->SpeedRun = 0.0f;
            gPlayerB8F0_guess->field_58 = 0.0f;
            EQ_GLOBAL(int, 0x0092478C) = 1;
        }
        break;
    // OP_ControlBoat: byte 4 == 1 hands the player control of the spawn (0x00905CF8), with 0x57F for a boat
    // (race 0x8D).
    case OP_ControlBoat: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
        if (player_guess != 0 && bytes_guess[4] == 1) {
            if (EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CF8) != 0) {
                EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CF8)->SpeedRun = 0.0f;
                EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CF8)->field_58 = 0.0f;
            }
            if (player_guess->Race == 0x8d) {
                pEverQuest->dsp_chat(pStringTable->getString(0x57f, 0), 0x111, 1);
            }
            EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CF8) = player_guess;
        }
        break;
    }
    // Zone dropped the player (0x2BAF): leave code 0xFD (0x00923794), then the connection is closed.
    case 0x2baf:
        Ext574110_guess("Disconnected from zone (bc2).\n");
        if (gPcB8F0_guess != 0) {
            Ext574110_guess("Character is %s.\n", gPcB8F0_guess->t03C_guess);
        }
        EQ_GLOBAL(unsigned char, 0x00923D7B) = 1;
        i39400_guess = 1;
        ((EverQuestB8F0_guess*)pEverQuest)->SetGameState(0xff);
        EQ_GLOBAL(int, 0x00923794) = 0xfd;
        i00B50_guess = 1;
        EQ_GLOBAL(ObjB8F0_guess*, 0x0079DBD8)->M42500C_guess(EQ_ARRAY(char, 0x00905CA0));
        break;
    case OP_RequestDuel:
        Handle_OP_RequestDuel_guess((Argument453231_guess*)data_guess);
        break;
    case OP_BecomeTrader:
        Handle_OP_BecomeTrader_guess((Argument4530F6_guess*)data_guess);
        break;
    case 0x2dd2:
        SetInventoryItemValue98_guess((unsigned)data_guess);
        break;
    case OP_VoiceMacroOut:
        EQ_GLOBAL(ObjB8F0_guess*, 0x00985D90)->HandleVoiceMacroOut_guess(0x2ec6, data_guess);
        break;
    // OP_ZoneSpawns; the client's own log text calls it MSG_EQ_NETPLAYERBUFF.
    case OP_ZoneSpawns:
        Ext574110_guess("MSG_EQ_NETPLAYERBUFF received started.");
        Handle_OP_ZoneSpawns_guess((int)connection_guess, 0x2e78, (SpawnRecord455710_guess*)data_guess,
                           size_guess);
        Ext574110_guess("MSG_EQ_NETPLAYERBUFF finished.");
        break;
    case OP_GroupUpdate:
        if (gPcB8F0_guess != 0) {
            Handle_OP_GroupUpdate_guess((Input58738_guess*)data_guess);
        }
        break;
    case 0x2f28:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            EQ_GLOBAL(unsigned char, 0x0092384D) = 1;
        }
        break;
    case 0x3352:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            EQ_GLOBAL(unsigned char, 0x0092384C) = 1;
            EQ_GLOBAL(ObjB8F0_guess, 0x00923770).SetAutoAttack_guess(0);
            EQ_GLOBAL(ObjB8F0_guess, 0x00923770).SetAutoFire_guess(0);
        }
        break;
    case 0x3274:
        Handle_NameChangeResult_guess((ErrorCode548BE_guess*)data_guess);
        break;
    case OP_RecipeReply:
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->Handle_OP_RecipeReply_guess(data_guess);
        }
        break;
    case OP_MemorizeSpell:
        Handle_OP_MemorizeSpell_guess(words_guess[2], words_guess[0], words_guess[1], words_guess[3]);
        break;
    case 0x3013:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            gPlayerB8F0_guess->StandState = 0x66;
            gPcB8F0_guess->b0FC_guess = 2;
            gPlayerB8F0_guess->SpeedRun = 0.0f;
            gPlayerB8F0_guess->field_58 = 0.0f;
        }
        break;
    case 0x3367:
        EQ_GLOBAL(int, 0x0092485C) = 1;
        break;
    case 0x36f4:
        if (words_guess[0x22] == -5) {
            pEverQuest->dsp_chat(pStringTable->getString(0x1a31, 0), 0x111, 1);
        } else if (words_guess[0x22] == -2) {
            char line_guess[0x200];
            Ext46DA4A_guess(line_guess, 0x1a30, data_guess + 0x40, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0x111, 1);
        }
        break;
    case OP_BecomePVPPrompt:
        pConfirmationDialogPool_guess->Activate(
            (NotifyBaseB8F0_guess*)EQ_GLOBAL(NotifyViewB8F0_guess*, 0x00988DF0), 0x6b,
            pStringTable->getString(0x215, 0), 0xc, 0x4e20, 0, 0);
        break;
    case OP_SendAATable:
        Handle_OP_SendAATable_guess((StateSourceB86D_guess*)data_guess, size_guess);
        break;
    case OP_ItemPacket: {
        int mode_guess = words_guess[0];
        int value_guess = FUN_004b232e_guess(data_guess + 4);
        if (value_guess != 0) {
            PlaceReceivedItem_guess(mode_guess, value_guess);
        }
        break;
    }
    case 0x383a:
        break;
    // OP_ZonePlayerToBind {zone, y, x, z, heading, zone name}: "returning to bind" (0x21B), then a zone
    // change with a repop-to-bind reason.
    case OP_ZonePlayerToBind:
        if (size_guess > 0x14) {
            char line_guess[0x400] = "";
            char text_guess[0x200] = "";
            ReaderB8F0_guess reader_guess;
            struct {
                int zone_guess;
                float y_guess;
                float x_guess;
                float z_guess;
                float heading_guess;
            } home_guess;
            reader_guess.size_guess = size_guess;
            reader_guess.data_guess = data_guess;
            reader_guess.position_guess = 0;
            ((FiveWords454FCD_guess*)&home_guess)->Read_guess((Reader454FCD_guess*)&reader_guess);
            ((StringReader454F79_guess*)&reader_guess)->ReadString_guess(text_guess, 0x200);
            Ext46DA4A_guess(line_guess, 0x21b, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0xd, 1);
            ((EverQuestB8F0_guess*)pEverQuest)->PrepareLocalPCForRepop_guess();
            ((EverQuestB8F0_guess*)pEverQuest)->MoveToZone_guess(
                home_guess.zone_guess, "repop to home at death", 1, 0xa, home_guess.y_guess,
                home_guess.x_guess, home_guess.z_guess, (int)home_guess.heading_guess);
            gDisplayB8F0_guess->MoveLocalPlayerToSafeCoords_guess();
            gDisplayB8F0_guess->RestoreCameraMode_guess();
        }
        break;
    case OP_PlayerStateRemove:
        Handle_OP_PlayerStateRemove_guess((DispatchRequest_guess*)data_guess);
        break;
    case OP_RespondAA:
        Handle_OP_RespondAA_guess((int)connection_guess, 0x3af4, (UpdatePair4534ED_guess*)data_guess);
        break;
    case 0x3a80:
        Ext574110_guess("Error:Zone Rejected this PC.. getting disconnected\n");
        break;
    case OP_BeginCast: {
        int packet_guess[2];
        memcpy(packet_guess, data_guess, 8);
        StartCasting_guess(packet_guess);
        break;
    }
    // Reply to our duel challenge (0x3EA0) for the spawn we asked (0x009238D8): 0x567 / 0x568 / 0x569 by the
    // reason byte, then the request is cleared.
    case 0x3ea0: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[1]);
        if (player_guess != 0 && player_guess->SpawnID == EQ_GLOBAL(unsigned, 0x009238D8)) {
            char line_guess[0x200];
            char kind_guess = data_guess[8];
            if (kind_guess == 0) {
                Ext46DA4A_guess(line_guess, 0x567, player_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(line_guess, 0xf, 1);
            } else if (kind_guess == 1) {
                Ext46DA4A_guess(line_guess, 0x568, player_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(line_guess, 0xf, 1);
            } else if (kind_guess == 2) {
                Ext46DA4A_guess(line_guess, 0x569, player_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(line_guess, 0xf, 1);
            }
            EQ_GLOBAL(unsigned char, 0x009238E0) = 0;
            EQ_GLOBAL(int, 0x009238D8) = 0;
        }
        break;
    }
    case 0x3e52:
        DeductCarriedCoins_guess((Command456A1E_guess*)data_guess);
        break;
    case OP_GMSearchCorpse: {
        char zone_guess[0x20];
        char line_guess[0x200];
        ((ObjB8F0_guess*)gWorldB8F0_guess)->M5F6ED0_guess(words_guess[0x20], zone_guess);
        sprintf(line_guess, "Corpse: %s in zone: %s", data_guess + 0x40, zone_guess);
        pEverQuest->dsp_chat(line_guess, 0xf, 1);
        break;
    }
    case OP_ApproveName:
        pinstCCharacterCreation_guess->HandleApproveName_guess(bytes_guess[0]);
        break;
    case 0x3f0d:
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00985CF0) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00985CF0)->HandleTicketMessage_guess(connection_guess, 0x3f0d, data_guess,
                                                     size_guess);
        }
        break;
    case OP_SendZonepoints:
        Handle_OP_SendZonepoints_guess(connection_guess, 0x3eba, data_guess, size_guess);
        break;
    case OP_LoadSpellSet:
        Handle_OP_LoadSpellSet_guess((int*)data_guess, words_guess[9]);
        break;
    case 0x417a:
        if (words_guess[0x31] != 0) {
            if (strcmp(gPlayerB8F0_guess->Name, data_guess + 0x44) == 0) {
                break;
            }
            if (words_guess[0x31] != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x574, 0), 0xf, 1);
                break;
            }
        }
        pEverQuest->dsp_chat(pStringTable->getString(0x575, 0), 0xf, 1);
        break;
    case OP_VetClaimReply: {
        Handle_OP_VetClaimReply_guess(words_guess[0x12]);
        for (int index_guess = 0; index_guess < EQ_GLOBAL(int, 0x0095D3B4); index_guess++) {
            if (*EQ_GLOBAL(ObjB8F0_guess, 0x0095D3B4).M4EB924_guess(index_guess)
                == words_guess[0x10]) {
                *EQ_GLOBAL(ObjB8F0_guess, 0x0095D3B4).M4EB924_guess(index_guess) = 0;
                break;
            }
        }
        break;
    }
    case OP_ZoneUnavail:
        EQ_GLOBAL(int, 0x00904228) = 1;
        EQ_GLOBAL(int, 0x00923880) = 0;
        break;
    // OP_MoveItem; 0x56D when the slot is bad. Open inventory and bag windows are refreshed.
    case OP_MoveItem:
        if (Handle_OP_MoveItem_guess(words_guess[0], words_guess[1], words_guess[2]) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x56d, 0), 0xf, 1);
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M56875D_guess();
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M4E6109_guess(0);
        }
        if (gPcB8F0_guess != 0) {
            gPcB8F0_guess->bC28C_guess = 1;
        }
        break;
    case OP_AugmentInfo:
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00991B88) != 0) {
            char line_guess[0x200];
            Ext46DA4A_guess(line_guess, 0x16f9, data_guess + 8, 0, 0, 0, 0, 0, 0, 0, 0);
            EQ_GLOBAL(ObjB8F0_guess*, 0x00991B88)->M51E099_guess(line_guess, words_guess[1]);
        }
        break;
    case OP_LFGGetMatchesResponse:
        Handle_OP_LFGGetMatchesResponse_guess(data_guess, size_guess);
        break;
    case 0x4519:
        fillEvilProcessNames_guess(data_guess);
        break;
    case OP_SendCharInfo:
        Handle_OP_SendCharInfo_guess((int)connection_guess, 0x4513, data_guess);
        break;
    case OP_Illusion:
        Handle_OP_Illusion_guess((Argument4534AB_guess*)data_guess);
        break;
    case OP_CharInacessable:
        EQ_GLOBAL(int, 0x00904228) = 1;
        EQ_GLOBAL(int, 0x00923880) = 0;
        EQ_GLOBAL(int, 0x00905CBC) = 1;
        break;
    case OP_MoveMultipleItems:
        Handle_OP_MoveMultipleItems_guess(gPcB8F0_guess, data_guess, size_guess);
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M56875D_guess();
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M4E6109_guess(0);
        }
        break;
    case 0x46b1:
        Handle_NameApprovalRequest_guess((Argument4546E2_guess*)data_guess);
        break;
    case OP_Surname:
        Handle_OP_Surname_guess((Target5718FArgument_guess*)data_guess);
        break;
    case 0x4642:
        FUN_00456ca5_guess((Command456A1E_guess*)data_guess);
        break;
    case 0x4719: {
        New4790D0B8F0_guess* created_guess =
            new New4790D0B8F0_guess(data_guess, 0, data_guess + 0xc, data_guess + 0x20);
        if (created_guess != 0 && created_guess->i54_guess == 0) {
            delete created_guess;
        }
        break;
    }
    // OP_Split: applies the four coin counts and prints the share received (0x2F27).
    case OP_Split: {
        char text_guess[0x80];
        char line_guess[0x200];
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417CF2_guess(words_guess[0]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D1C_guess(words_guess[1]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D46_guess(words_guess[2]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D70_guess(words_guess[3]);
        text_guess[0] = 0;
        BuildMoneyText_guess(words_guess[0], words_guess[1], words_guess[2], words_guess[3],
                          text_guess);
        Ext46DA4A_guess(line_guess, 0x2f27, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(line_guess, 0x11d, 1);
        break;
    }
    case OP_ManaChange:
        Handle_OP_ManaChange_guess((Argument456FD1_guess*)data_guess, size_guess);
        break;
    case 0x47c9:
        pEverQuest->dsp_chat(pStringTable->getString(0x563, 0), 0x108, 1);
        break;
    case OP_CancelSneakHide:
        CancelSneakHide();
        break;
    case 0x4c0e:
        break;
    case 0x4bc6:
        Ext574110_guess("Error:Zone Rejected add player.. getting disconnected\n");
        break;
    // Opcode 0x4B09: this player's level from the server (byte 4), "You are now level %1" (0x3284).
    case 0x4b09:
        if (gPlayerB8F0_guess != 0 && gPcB8F0_guess != 0
            && (unsigned)words_guess[0] == gPlayerB8F0_guess->SpawnID) {
            char line_guess[0x200];
            gProfileB8F0_guess->i11F8_guess = 0;
            ((PropertyOwner_guess*)gPcBaseB8F0_guess)->Set11a4_guess(bytes_guess[4]);
            gPlayerB8F0_guess->Level = (unsigned char)gProfileB8F0_guess->level_11a4_guess;
            gPlayerB8F0_guess->InitSneakMod_guess();
            Ext46DA4A_guess(line_guess, 0x3284,
                            _itoa(bytes_guess[4], EQ_ARRAY(char, 0x0099DB00), 10), 0, 0, 0, 0, 0,
                            0, 0, 0);
            pEverQuest->dsp_chat(line_guess);
            SetSkillsToCap_guess(gPcB8F0_guess);
        }
        break;
    case OP_RezzComplete:
        Handle_OP_RezzComplete_guess((ResurrectRequest_guess*)data_guess);
        break;
    case 0x4c62:
        break;
    case OP_CashReward:
        Handle_OP_CashReward_guess((int*)data_guess);
        break;
    // OP_SpawnDoor: an array of 0x50-byte Door_Structs, kept under the same rule as 0x1BFE.
    case OP_SpawnDoor: {
        int count_guess = size_guess / 0x50;
        if (count_guess > 0) {
            char* cursor_guess = data_guess;
            do {
                New490A43B8F0_guess* entry_guess = new New490A43B8F0_guess(cursor_guess);
                if (entry_guess->i90_guess == 0 && entry_guess->b22_guess != 0x35) {
                    delete entry_guess;
                } else {
                    EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490580_guess(entry_guess);
                }
                cursor_guess += 0x50;
            } while (--count_guess != 0);
        }
        break;
    }
    case OP_DeleteItem:
        if (Handle_OP_DeleteItem_guess(words_guess[0], words_guess[1], words_guess[2]) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x56e, 0), 0xf, 1);
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M56875D_guess();
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850C58)->M4E6109_guess(0);
        }
        if (gPcB8F0_guess != 0) {
            gPcB8F0_guess->bC28C_guess = 1;
        }
        break;
    case OP_RecipeDetails:
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M568B39_guess(data_guess);
        }
        break;
    case OP_PetBuffWindow:
        if (Ext401B28_guess(words_guess[0]) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00850BAC) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850BAC)->SetPetBuffs_guess(data_guess + 4, data_guess + 0x7c,
                                                     words_guess[0x3d]);
        }
        break;
    case OP_BecomeCorpse:
        Handle_OP_BecomeCorpse_guess((PositionRequest451DB3_guess*)data_guess);
        break;
    case OP_NewTitlesAvailable:
        if (pinstCTitleWnd_guess != 0 && pinstCTitleWnd_guess->b1D8_guess != 0) {
            pConfirmationDialogPool_guess->Activate(0, 0x4eca, pStringTable->getString(0xdee, 0),
                                                    1, 0x2710, 0, 0);
            if (pinstCTitleWnd_guess != 0 && pinstCTitleWnd_guess->b05C_guess != 0) {
                EQ_GLOBAL(ObjB8F0_guess, 0x00992918).RequestTitles_guess();
            }
        }
        break;
    case OP_DeleteSpell:
        EQ_GLOBAL(ObjB8F0_guess*, 0x00850C30)->HandleDeleteSpellReply_guess(words_guess[0], words_guess[1]);
        break;
    case 0x524f:
        if (gPlayerB8F0_guess != 0 && gPlayerB8F0_guess->Actor_guess() != 0) {
            gPlayerB8F0_guess->Actor_guess()->i1060_guess = 0;
        }
        break;
    case OP_BazaarSearch:
    case OP_Trader:
        Handle_OP_Trader_guess((int)connection_guess, opcode_guess, (Argument453571_guess*)data_guess,
                           size_guess);
        break;
    case 0x525d:
        EmitSpellEffectsOnSpawns_guess((int*)data_guess, size_guess >> 3);
        break;
    // OP_Sound (0x541E), used here for coins handed to the player: words 5-8 = copper, silver, gold,
    // platinum, each printed with its own string (0x59E-0x5A2) and applied to the purse.
    case OP_Sound: {
        char who_guess[0x40];
        char line_guess[0x200];
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
        if (player_guess != 0) {
            Ext46DA4A_guess(who_guess, 0x59f,
                            ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(player_guess->Name),
                            0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            who_guess[0] = 0;
        }
        if (words_guess[5] > 0) {
            Ext46DA4A_guess(line_guess, 0x59e,
                            _itoa(words_guess[5], EQ_ARRAY(char, 0x0099DB00), 10), who_guess, 0, 0,
                            0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0x111, 1);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D70_guess(words_guess[5]);
        }
        if (words_guess[6] > 0) {
            Ext46DA4A_guess(line_guess, 0x5a0,
                            _itoa(words_guess[6], EQ_ARRAY(char, 0x0099DB00), 10), who_guess, 0, 0,
                            0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0x111, 1);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D46_guess(words_guess[6]);
        }
        if (words_guess[7] > 0) {
            Ext46DA4A_guess(line_guess, 0x5a1,
                            _itoa(words_guess[7], EQ_ARRAY(char, 0x0099DB00), 10), who_guess, 0, 0,
                            0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0x111, 1);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D1C_guess(words_guess[7]);
        }
        if (words_guess[8] > 0) {
            Ext46DA4A_guess(line_guess, 0x5a2,
                            _itoa(words_guess[8], EQ_ARRAY(char, 0x0099DB00), 10), who_guess, 0, 0,
                            0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0x111, 1);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417CF2_guess(words_guess[8]);
        }
        EQ_GLOBAL(ObjB8F0_guess*, 0x00851390)->WavePlay_guess(0x8d, 0);
        break;
    }
    case 0x15ff:
    case OP_CharInventory:
        ReceiveSerializedItems_guess(opcode_guess, data_guess, size_guess);
        break;
    case 0x5265:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            strcpy(EQ_ARRAY(char, 0x00923898), data_guess + 0x40);
        }
        break;
    case 0x5a56:
        break;
    case 0x5619:
        FUN_004570ca_guess((Target570Argument_guess*)data_guess);
        break;
    case OP_DeleteSpawn:
        Handle_OP_DeleteSpawn_guess((int*)data_guess);
        break;
    case 0x56d4:
        Handle_MoneyReceived_guess((int*)data_guess);
        break;
    case OP_InterruptCast:
    // Spell text seen by others (0x5663 raw, OP_InterruptCast 0xB97 as a string id plus arguments). Options 9
    // (bard songs) and 7/8 (other spells) at 0x009248E0 filter it by caster: self, group or anyone.
    case 0x5663: {
        struct TextMessageB8F0_guess {
            int id_guess;
            char text_guess[0x200];
        };
        TextMessageB8F0_guess formatted_guess;
        TextMessageB8F0_guess* message_guess;
        if (opcode_guess == OP_InterruptCast) {
            struct {
                int id_guess;
                int string_guess;
                char text_guess[0x24];
            } split_guess;
            SplitStringIdPacket_guess((int)data_guess, size_guess, &split_guess);
            Ext467441_guess(formatted_guess.text_guess,
                            pStringTable->getString(split_guess.string_guess, 0),
                            split_guess.text_guess, -1, 0);
            formatted_guess.id_guess = split_guess.id_guess;
            message_guess = &formatted_guess;
        } else {
            message_guess = (TextMessageB8F0_guess*)data_guess;
        }
        PlayerB8F0_guess* speaker_guess = Ext401B28_guess(message_guess->id_guess);
        if (speaker_guess == 0) {
            break;
        }
        bool grouped_guess = false;
        if (speaker_guess != gPlayerB8F0_guess) {
            for (PlayerB8F0_guess** member_guess = EQ_ARRAY(PlayerB8F0_guess*, 0x00904390);
                 member_guess < EQ_ARRAY(PlayerB8F0_guess*, 0x009043A4); member_guess++) {
                if (speaker_guess == *member_guess) {
                    grouped_guess = true;
                    break;
                }
            }
        }
        if (speaker_guess->Class == 8) {
            if (speaker_guess == gPlayerB8F0_guess) {
                if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(9) == 1) {
                    break;
                }
            } else if (!grouped_guess) {
                if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(9) != 2) {
                    break;
                }
            } else if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(9) != 2) {
                if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(9) != 4) {
                    break;
                }
            }
        } else if (speaker_guess != gPlayerB8F0_guess) {
            if (grouped_guess) {
                if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(7) != 2) {
                    if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(7) != 4) {
                        break;
                    }
                }
            } else if (speaker_guess->Type == 0) {
                if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(7) != 2) {
                    break;
                }
            } else if (EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(8) != 0) {
                break;
            }
        }
        chat_guess->dsp_chat(message_guess->text_guess, 0x108, 1);
        break;
    }
    case OP_FindPersonReply:
        EQ_GLOBAL(ObjB8F0_guess*, 0x00985C88)->Handle_OP_FindPersonReply_guess(data_guess, size_guess / 0xc, 1);
        break;
    case 0x58ff:
        if (pinstCAltStorageWnd_guess != 0) {
            pinstCAltStorageWnd_guess->M4D8E35_guess(0x58ff, data_guess);
        }
        break;
    case 0x210b:
    // 0x210B, 0x583D: the named character recovers: standing (0x64), stun cleared.
    case 0x583d:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            if (gPcB8F0_guess->Cur_HP(0) > 0) {
                gPcB8F0_guess->b0FC_guess = 0;
            }
            gPlayerB8F0_guess->StandState = 0x64;
            EQ_GLOBAL(int, 0x0092478C) = 0;
        }
        break;
    case OP_WorldLevelTooHigh:
        EQ_GLOBAL(int, 0x00904228) = 1;
        EQ_GLOBAL(int, 0x00923880) = 0;
        EQ_GLOBAL(int, 0x00905CB8) = 1;
        break;
    case OP_ClearAA:
        EQ_GLOBAL(ObjB8F0_guess*, 0x008511D8)->M44826B_guess();
        break;
    case OP_LeadershipExpUpdate:
        Handle_OP_LeadershipExpUpdate_guess((Argument453A68_guess*)data_guess);
        break;
    // OP_GMFind: zone and rounded location (0x856), or not found (0x857).
    case OP_GMFind: {
        char line_guess[0x200];
        if (bytes_guess[0x80] != 0) {
            char zone_guess[0x20];
            ((ObjB8F0_guess*)gWorldB8F0_guess)->M5F6ED0_guess(words_guess[0x21], zone_guess);
            Ext46DA4A_guess(line_guess, 0x856, zone_guess,
                            _itoa((int)floats_guess[0x22], EQ_ARRAY(char, 0x0099DB00), 10),
                            _itoa((int)floats_guess[0x23], EQ_ARRAY(char, 0x0099DAE0), 10),
                            _itoa((int)floats_guess[0x24], EQ_ARRAY(char, 0x0099DF60), 10), 0, 0,
                            0, 0, 0);
        } else {
            sprintf(line_guess, pStringTable->getString(0x857, 0));
        }
        pEverQuest->dsp_chat(line_guess, 0xa, 1);
        break;
    }
    case 0x5ce6:
        if (gPlayerB8F0_guess != 0) {
            PlayerB8F0_guess* player_guess = gPlayerB8F0_guess;
            float position_guess[3];
            int heading_guess = (int)floats_guess[4];
            position_guess[0] = floats_guess[1];
            position_guess[1] = floats_guess[2];
            position_guess[2] = floats_guess[3];
            player_guess->WarpToPosition_guess(position_guess, (float)heading_guess);
            gPlayerB8F0_guess->UpdateSharedValuesIfLocal_guess();
        }
        break;
    case 0x5c44:
        EQ_GLOBAL(int, 0x00923D08) += words_guess[0];
        EQ_GLOBAL(int, 0x00923D0C) += words_guess[1];
        EQ_GLOBAL(int, 0x00923D10) += words_guess[2];
        EQ_GLOBAL(int, 0x00923D14) += words_guess[3];
        break;
    case 0x5b71: {
        ObjB8F0_guess* found_guess = EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490547_guess(words_guess[0], 0);
        if (found_guess != 0) {
            found_guess->w066_guess = ((short*)data_guess)[2];
        }
        break;
    }
    case 0x5b16:
        Handle_VeteranRewardResult_guess(words_guess[0x10]);
        break;
    case OP_Track:
        pinstCTrackingWnd_guess->HandleTrackReply_guess(data_guess, size_guess >> 3);
        break;
    case 0x5d85:
        break;
    // 0xCFC OP_GuildOptInOut; 0x1A29 OP_GuildSendActiveTributes; 0x32C0 OP_GuildTributeDonateItem; 0x3312
    // OP_GuildTributeToggleReply; 0x44C4 OP_GuildTributeDonatePlat; 0x4EEF OP_GuildModifyBenefits; 0x5E3D
    // OP_GuildTributeInfo / OP_SendGuildTributes; 0x60B6 OP_OpenGuildTributeMaster; 0x67EA
    // OP_GuildTributeFavorAndTimer; 0x704F OP_GuildSelectTribute.
    case OP_GuildOptInOut:
    case OP_GuildSendActiveTributes:
    case OP_GuildTributeDonateItem:
    case OP_GuildTributeToggleReply:
    case OP_GuildTributeDonatePlat:
    case OP_GuildModifyBenefits:
    case 0x5e3d:  // OP_GuildTributeInfo / OP_SendGuildTributes
    case OP_OpenGuildTributeMaster:
    case OP_GuildTributeFavorAndTimer:
    case OP_GuildSelectTribute:
        EQ_GLOBAL(ObjB8F0_guess, 0x00850350).HandleGuildTributeMessage_guess(opcode_guess, data_guess);
        break;
    case 0x5e04:
        if (strcmp(data_guess, gPlayerB8F0_guess->Name) == 0) {
            EQ_GLOBAL(unsigned char, 0x0092384C) = 0;
        }
        break;
    case 0x5fec: {
        char text_guess[0x200];
        unsigned flags_guess = words_guess[0x11];
        sprintf(text_guess, "The expansion settings for %s are: ", data_guess + 4, flags_guess);
        if (flags_guess == 0) {
            strcat(text_guess, "None");
        } else {
            if (flags_guess & 1) {
                strcat(text_guess, "Kunark ");
            }
            if (flags_guess & 2) {
                strcat(text_guess, "Velious ");
            }
            if (flags_guess & 4) {
                strcat(text_guess, "Luclin ");
            }
            if (flags_guess & 8) {
                strcat(text_guess, "PoP ");
            }
            if (flags_guess & 0x10) {
                strcat(text_guess, "Ykesha ");
            }
            if (flags_guess & 0x20) {
                strcat(text_guess, "LDoN ");
            }
            if (flags_guess & 0x40) {
                strcat(text_guess, "Gates ");
            }
            if (flags_guess & 0x80) {
                strcat(text_guess, "Omens ");
            }
            if (flags_guess & 0x100) {
                strcat(text_guess, "DON ");
            }
            if (flags_guess & 0x200) {
                strcat(text_guess, "Darkhollow ");
            }
        }
        pEverQuest->dsp_chat(text_guess);
        break;
    }
    case OP_AAExpUpdate:
        Handle_OP_AAExpUpdate_guess((Argument453A24_guess*)data_guess);
        break;
    case 0x5f4e:
        if (gPcB8F0_guess != 0) {
            gPcB8F0_guess->ConsumeSlotItem_guess(words_guess[0], words_guess[1]);
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00992940) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M59DD30_guess()) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00992940)->M56875D_guess();
        }
        break;
    case 0x5f43: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
        if (player_guess != 0) {
            player_guess->ChangeTextures_guess(words_guess[1], words_guess[2]);
        }
        break;
    }
    case OP_ExpUpdate:
        Handle_OP_ExpUpdate_guess((Argument4539D3_guess*)data_guess);
        break;
    // OP_Bind_Wound result word 1: 0/1 and 4-7 print 0x598-0x59C; 3 and 8 release the pending-request counts
    // (0x009248D0, 0x009248D4). Every result but 0 and 3 also stands a binding player (0x69) up.
    case OP_Bind_Wound:
        if (gPcB8F0_guess != 0 && gPlayerB8F0_guess != 0) {
            if (words_guess[1] != 0 && words_guess[1] != 3) {
                EQ_GLOBAL(int, 0x00923CC4) = -1;
                EQ_GLOBAL(int, 0x00923CD4) = 0;
                if (gPlayerB8F0_guess->StandState == 0x69) {
                    gPlayerB8F0_guess->ChangePosition_guess(0x64);
                }
            }
            int result_guess = words_guess[1];
            if (result_guess == 0 || result_guess == 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x598, 0), 0xf, 1);
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            } else if (result_guess == 3) {
                if (EQ_GLOBAL(int, 0x009248D4) > 0) {
                    EQ_GLOBAL(int, 0x009248D4)--;
                } else {
                    EQ_GLOBAL(int, 0x009248D4) = 0;
                }
                if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                    EQ_GLOBAL(int, 0x009248D0)--;
                } else {
                    EQ_GLOBAL(int, 0x009248D0) = 0;
                }
            } else if (result_guess == 4) {
                pEverQuest->dsp_chat(pStringTable->getString(0x599, 0), 0xf, 1);
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            } else if (result_guess == 5) {
                pEverQuest->dsp_chat(pStringTable->getString(0x59a, 0), 0xf, 1);
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            } else if (result_guess == 6) {
                pEverQuest->dsp_chat(pStringTable->getString(0x59b, 0), 0xf, 1);
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            } else if (result_guess == 7) {
                pEverQuest->dsp_chat(pStringTable->getString(0x59c, 0), 0xf, 1);
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            } else if (result_guess == 8) {
                if (EQ_GLOBAL(int, 0x009248D4) > 0) {
                    EQ_GLOBAL(int, 0x009248D4)--;
                } else {
                    EQ_GLOBAL(int, 0x009248D4) = 0;
                }
                if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                    EQ_GLOBAL(int, 0x009248D0)--;
                } else {
                    EQ_GLOBAL(int, 0x009248D0) = 0;
                }
                EQ_GLOBAL(unsigned char, 0x00924615) = 1;
            }
        }
        break;
    // Trade-skill combine replies only release one pending-request count.
    case OP_RecipeAutoCombine:
    case OP_TradeSkillCombine:
        if (EQ_GLOBAL(int, 0x009248D0) > 0) {
            EQ_GLOBAL(int, 0x009248D0)--;
        } else {
            EQ_GLOBAL(int, 0x009248D0) = 0;
        }
        break;
    case OP_YellForHelp:
        Handle_OP_YellForHelp_guess((int*)data_guess);
        break;
    // OP_ZoneServerInfo: acknowledge with OP_WorldComplete (0x509D), wait up to 30 s for world to drop us,
    // then connect to the zone at host:port. On failure the status is 5 or the connect result, and
    // Respond.bmp is shown for 2 s.
    case OP_ZoneServerInfo: {
        struct {
            char host_guess[0x80];
            short port_guess;
        } address_guess;
        int result_guess;
        memcpy(&address_guess, data_guess, 0x82);
        ntohs(address_guess.port_guess);
        Ext574110_guess("Zone Connect -- 0 -- Received MSG_ZONE_ADDRESS");
        Ext574110_guess("Zone addr [%s:%d] received...", address_guess.host_guess,
                        ntohs(address_guess.port_guess));
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_WorldComplete, 0, 0, 1);
        if (!EQ_GLOBAL(ObjB8F0_guess*, 0x0079DBD8)->WaitForDisconnect_guess(EQ_GLOBAL(void*, 0x00905CA0), 0x7530)) {
            Ext574110_guess("ERROR: World did not drop the connection.");
            result_guess = 5;
        } else {
            Ext574110_guess("ZONING");
            result_guess = Ext4B611D_guess(address_guess.host_guess);
            if (result_guess == 0) {
                EQ_GLOBAL(int, 0x00905C98) = 1;
                Ext574110_guess("Connected to %s:%d...\n", address_guess.host_guess,
                                ntohs(address_guess.port_guess));
                break;
            }
        }
        EQ_GLOBAL(int, 0x00905C98) = 0;
        Ext574110_guess(
            "Failed to connect to zoneserver (%s, port %d), result = %d, for MSG_ZONE_ADDRESS.\n",
            address_guess.host_guess, (int)address_guess.port_guess, result_guess);
        DisplayScreen_guess("Respond.bmp");
        Sleep(2000);
        break;
    }
    case 0x6136:
        ClearOwnInventoryAndCoins_guess(data_guess);
        break;
    case 0x6259:
        UpdateValueNow_guess((UpdateValue_guess*)data_guess);
        break;
    case OP_ConsentResponse:
        Handle_OP_ConsentResponse_guess((Argument4533B6_guess*)data_guess);
        break;
    case 0x6273:
        if (words_guess[1] > 0 && gPcB8F0_guess != 0) {
            char line_guess[0x200];
            sprintf(line_guess, pStringTable->getString(0x573, 0));
            pEverQuest->dsp_chat(line_guess, 0xf, 1);
        }
        break;
    case OP_PlayerStateAdd:
        Handle_OP_PlayerStateAdd_guess((DispatchRequest_guess*)data_guess);
        break;
    case 0x63fe:
        break;
    case OP_Consider: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[1]);
        if (player_guess != 0) {
            Consider(player_guess, data_guess);
        }
        break;
    }
    case OP_SetChatServer2:
        Handle_OP_SetChatServer2_guess((int)data_guess);
        break;
    case OP_ItemLinkResponse:
        Handle_OP_ItemLinkResponse_guess((SecondForwardArgument_guess*)data_guess);
        break;
    // 0x397D OP_TaskHistoryReply; 0x3BA8 OP_CancelTask; 0x54EB OP_TaskActivityComplete; 0x5E7C
    // OP_TaskSelectWindow; 0x5EF7 OP_TaskDescription; 0x682D OP_TaskActivity; 0x6A1D OP_TaskRequestTimer /
    // OP_TaskTimers; 0x76A2 OP_CompletedTasks; 1 more without an EQEmu name.
    case 0x1d6e:
    case OP_TaskHistoryReply:
    case OP_CancelTask:
    case OP_TaskActivityComplete:
    case OP_TaskSelectWindow:
    case OP_TaskDescription:
    case OP_TaskActivity:
    case 0x6a1d:  // OP_TaskRequestTimer / OP_TaskTimers
    case OP_CompletedTasks:
        EQ_GLOBAL(ObjB8F0_guess, 0x0079DC78).HandleTaskMessage_guess(opcode_guess, data_guess, size_guess);
        break;
    // 0x66BD: a query naming us with both reply words empty; it is sent back with our name and the two
    // profile values filled in.
    case 0x66bd:
        if (gPcB8F0_guess != 0 && words_guess[0x20] == 0 && words_guess[0x21] == 0) {
            strcpy(data_guess, data_guess + 0x40);
            strcpy(data_guess + 0x40, gPcB8F0_guess->t03C_guess);
            words_guess[0x20] = gPcB8F0_guess->i0E18_guess;
            words_guess[0x21] = gPcB8F0_guess->i0E20_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x66bd, data_guess, 0x88, 1);
        }
        break;
    // OP_GMKick of this character: same disconnect path as 0x2BAF, with 0x570 shown first.
    case OP_GMKick:
        if (__stricmp(gPlayerB8F0_guess->Name, data_guess) == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x570, 0), 0xa, 1);
            Ext574110_guess("*** DISCONNECTING: %s\n", pStringTable->getString(0x570, 0));
            EQ_GLOBAL(unsigned char, 0x00923D7B) = 1;
            i39400_guess = 1;
            ((EverQuestB8F0_guess*)pEverQuest)->SetGameState(0xff);
            EQ_GLOBAL(int, 0x00923794) = 0xfd;
            i00B50_guess = 1;
            EQ_GLOBAL(ObjB8F0_guess*, 0x0079DBD8)->M42500C_guess(EQ_ARRAY(char, 0x00905CA0));
        }
        break;
    case 0x69c8:
        if (words_guess[1] != -1) {
            int reply_guess[2];
            reply_guess[0] = words_guess[1];
            reply_guess[1] = ChecksumCodeRangesB_guess(words_guess[1]);
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x7754, reply_guess, 8, 1);
        }
        break;
    // OP_GMKill of this character: 0x56F, then HP -10000 in both the profile and the spawn.
    case OP_GMKill:
        if (__stricmp(gPlayerB8F0_guess->Name, data_guess) == 0) {
            char line_guess[0x200];
            Ext46DA4A_guess(line_guess, 0x56f,
                            ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(data_guess), 0, 0, 0,
                            0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0xa, 1);
            EQ_GLOBAL(ObjB8F0_guess*, 0x00851390)->WavePlay_guess(0x8f, 0);
            gProfileB8F0_guess->i11B0_guess = -10000;
            gPlayerB8F0_guess->HPCurrent = -10000;
            gPlayerB8F0_guess->Actor_guess()->i068_guess = 0;
        }
        break;
    case OP_ClickObjectAction:
        Handle_OP_ClickObjectAction_guess((Argument453681_guess*)data_guess);
        break;
    // OP_SharedTaskAddPlayer: invitation box (string 0xE27, 20 s) that remembers the inviter's name.
    case OP_SharedTaskAddPlayer: {
        char line_guess[0x400];
        Popup108B8F0_guess* popup_guess = new Popup108B8F0_guess();
        popup_guess->flag_guess = 0;
        popup_guess->kind_guess = 1;
        Ext576FA0_guess(popup_guess->name_guess, data_guess + 5, 0x100);
        Ext46DA4A_guess(line_guess, 0xe27, popup_guess->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(
            (NotifyBaseB8F0_guess*)EQ_GLOBAL(NotifyViewB8F0_guess*, 0x00988DF0), 0x6934,
            line_guess, 0xc, 0x4e20, (int)popup_guess, 0);
        break;
    }
    // OP_BankerChange: new bank coins (+0x13C..+0x148) and carried coins, then the bank window refreshes.
    case OP_BankerChange:
        gPcB8F0_guess->i148_guess = words_guess[7];
        gPcB8F0_guess->i144_guess = words_guess[6];
        gPcB8F0_guess->i140_guess = words_guess[5];
        gPcB8F0_guess->i13C_guess = words_guess[4];
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D5B_guess(words_guess[3]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D31_guess(words_guess[2]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D07_guess(words_guess[1]);
        ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417CDD_guess(words_guess[0]);
        if (EQ_GLOBAL(int, 0x009248D0) > 0) {
            EQ_GLOBAL(int, 0x009248D0)--;
        } else {
            EQ_GLOBAL(int, 0x009248D0) = 0;
        }
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00850C38) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850C38)->UpdateMoneyLabels_guess();
        }
        gPcB8F0_guess->bC28C_guess = 1;
        break;
    // OP_Buff: action 3 writes the 0x14-byte buff into slot `words_guess[6]`; otherwise every slot with the
    // same kind byte and spell id is removed (action 1) or overwritten.
    case OP_Buff:
        if (gPcB8F0_guess != 0) {
            if (words_guess[7] == 3) {
                memcpy(gPcB8F0_guess->GetBuff_guess(words_guess[6]),
                       data_guess + 4, 0x14);
                gPcB8F0_guess->bC348_guess = 0;
            } else {
                for (int index_guess = 0;
                     index_guess < gPcB8F0_guess->GetMaxBuffs_guess();
                     index_guess++) {
                    Buff14B8F0_guess* buff_guess =
                        gPcB8F0_guess->GetBuff_guess(index_guess);
                    if (buff_guess->b0_guess != 0 && buff_guess->b0_guess == data_guess[4]
                        && buff_guess->i4_guess == words_guess[2]) {
                        if (words_guess[7] == 1) {
                            gPcB8F0_guess->RemovePCAffectex_guess(buff_guess, 0);
                        } else {
                            memcpy(buff_guess, data_guess + 4, 0x14);
                            gPcB8F0_guess->bC348_guess = 0;
                        }
                    }
                }
            }
        }
        break;
    case OP_SkillUpdate:
        Handle_OP_SkillUpdate_guess((Argument4597D8_guess*)data_guess);
        break;
    // 0x67A OP_SendTributes; 0x152D OP_TributeInfo; 0x27B3 OP_OpenTributeReply / OP_TributeMoney; 0x4665
    // OP_TributeTimer; 0x512E OP_OpenTributeMaster; 0x5639 OP_TributeUpdate; 0x625D OP_SelectTribute; 0x6463
    // OP_TributePointUpdate; 0x6F6C OP_TributeItem.
    case OP_SendTributes:
    case OP_TributeInfo:
    case 0x27b3:  // OP_OpenTributeReply / OP_TributeMoney
    case OP_TributeTimer:
    case OP_OpenTributeMaster:
    case OP_TributeUpdate:
    case OP_SelectTribute:
    case OP_TributePointUpdate:
    case OP_TributeItem:
        EQ_GLOBAL(ObjB8F0_guess, 0x00850350).HandleTributeMessage_guess(opcode_guess, data_guess);
        break;
    case 0x6ef8:
        gDisplayB8F0_guess->M4364B0_guess(words_guess[1], words_guess[2]);
        break;
    case 0x6ee7:
        EQ_GLOBAL(ObjB8F0_guess, 0x00850DC8).M447575_guess(data_guess, words_guess[0x13],
                                                         floats_guess[0x10], floats_guess[0x11],
                                                         floats_guess[0x12]);
        break;
    case 0x6d87:
        gDisplayB8F0_guess->M4363A0_guess(words_guess[0], words_guess[1]);
        break;
    case OP_LevelUpdate:
        Handle_OP_LevelUpdate_guess(connection_guess, 0x6d44, data_guess, size_guess);
        break;
    case OP_WeaponEquip1:
        Handle_OP_WeaponEquip1_guess((DispatchRequest_guess*)data_guess);
        break;
    case OP_MoveDoor: {
        ObjB8F0_guess* found_guess = EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M490547_guess(bytes_guess[0], 0);
        if (found_guess != 0) {
            found_guess->M48FC2E_guess(bytes_guess[1], 0, 0);
        }
        break;
    }
    // OP_DisciplineUpdate: copied whole, but only when the size matches the client's own block.
    case OP_DisciplineUpdate:
        if (size_guess == gPcB8F0_guess->M5EE550_guess()) {
            memcpy(gPcB8F0_guess->M5F0A30_guess(), data_guess, gPcB8F0_guess->M5EE550_guess());
        }
        break;
    case OP_LootItem:
        Handle_OP_LootItem_guess((NotifyArgument_guess*)data_guess);
        break;
    case 0x71f8:
        ShowPetitionText_guess(data_guess);
        break;
    case 0x738e:
        Ext469DD7_guess(bytes_guess[0]);
        break;
    case OP_Sacrifice:
        Handle_OP_Sacrifice_guess((Argument453062_guess*)data_guess);
        break;
    // OP_ZoneEntry; the client's own log text calls it MSG_EQ_ADDPLAYER.
    case OP_ZoneEntry:
        Ext574110_guess("Zone Connect -- 4 -- Received MSG_EQ_ADDPLAYER");
        if (!Handle_OP_ZoneEntry_guess(data_guess, size_guess)) {
            return 0;
        }
        break;
    case OP_ClearLeadershipAbilities:
        gPcB8F0_guess->M4BDC13_guess();
        if (EQ_GLOBAL(ObjB8F0_guess*, 0x00991C24) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00991C24)->UpdateRows_guess();
        }
        break;
    // OP_PlayerProfile; the client's own log text calls it MSG_SEND_PC.
    case OP_PlayerProfile:
        Ext574110_guess("Zone Connect -- 3 -- Received MSG_SEND_PC");
        gPcB8F0_guess->Handle_OP_PlayerProfile_guess(data_guess, size_guess);
        break;
    case OP_MoveLogRequest:
        if (pinstCServerListWnd_guess != 0) {
            pinstCServerListWnd_guess->SetServerList_guess(data_guess);
            ((VirtB8F0_guess*)pinstCServerListWnd_guess)->V084_guess();
        }
        break;
    case OP_Barter:
        EQ_GLOBAL(ObjB8F0_guess, 0x0079C198).Handle_OP_Barter_guess(0x7460, data_guess, size_guess);
        break;
    case OP_InspectRequest:
        Handle_OP_InspectRequest_guess((Argument457B0F_guess*)data_guess);
        break;
    // OP_Assist: as OP_TargetCommand (0x1477), and with auto-attack-on-assist (0x009247C0) attack starts
    // unless 0x0092384C is set.
    case OP_Assist: {
        PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
        if (player_guess != 0) {
            if (gTargetB8F0_guess != 0) {
                unsigned id_guess = gTargetB8F0_guess->SpawnID;
                Ext4C94AE_guess()->i0F0_guess = id_guess;
            }
            gTargetB8F0_guess = player_guess;
            if (EQ_GLOBAL(int, 0x009247C0) == 1 && EQ_GLOBAL(unsigned char, 0x0092384C) == 0) {
                EQ_GLOBAL(ObjB8F0_guess, 0x00923770).SetAutoAttack_guess(1);
            }
        }
        break;
    }
    case 0x76b1:
        Handle_SenseTrapsReply_guess((Point453158_guess*)data_guess);
        break;
    case OP_RemoveAllDoors:
        EQ_GLOBAL(ObjB8F0_guess*, 0x00903E84)->M4909CE_guess();
        break;
    case 0x7d4a:
        break;
    // 0x7F1 OP_UpdateLeadershipAA; 0x10F4 OP_DelegateAbility; 0x1794 OP_RaidClearNPCMarks; 0x3EEC
    // OP_SetGroupTarget; 0x3EF6 OP_ClearNPCMarks; 0x5483 OP_MarkNPC; 0x4FB6 OP_InspectBuffs; 0x56EB
    // OP_RaidDelegateAbility; 0x6A12 OP_TargetHoTT; 8 more without an EQEmu name.
    case OP_UpdateLeadershipAA:
    case 0x844:
    case OP_DelegateAbility:
    case OP_RaidClearNPCMarks:
    case 0x23b9:
    case OP_SetGroupTarget:
    case OP_ClearNPCMarks:
    case OP_MarkNPC:
    case 0x4ffe:
    case OP_InspectBuffs:
    case 0x552c:
    case OP_RaidDelegateAbility:
    case 0x5871:
    case OP_TargetHoTT:
    case 0x7822:
    case 0x7a75:
    case 0x7e49:
        if ((gPcSecondB8F0_guess->i108_guess & 0x40)
            && EQ_GLOBAL(ObjB8F0_guess*, 0x009859EC) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x009859EC)->HandleLeadershipMessage_guess(connection_guess, opcode_guess, data_guess,
                                                     size_guess);
        }
        break;
    case OP_GMBecomeNPC:
        pEverQuest->dsp_chat(pStringTable->getString(0x566, 0), 0xd, 1);
        gPcB8F0_guess->b10C_guess = 1;
        break;
    case OP_Stamina:
        Handle_OP_Stamina_guess((int*)data_guess);
        break;
    case OP_WorldChecksumFailure:
        Ext574110_guess("World disconnecting (bc).\n");
        break;
    case OP_DenyResponse:
        Handle_OP_ConsentResponse_guess((Argument4533B6_guess*)data_guess);
        break;
    case 0x7ba3:
        gPlayerB8F0_guess->ChangePosition_guess(0x64);
        pEverQuest->dsp_chat(pStringTable->getString(0x572, 0), 4, 1);
        EQ_GLOBAL(int, 0x009248D0) = 0;
        EQ_GLOBAL(int, 0x009248D4) = 0;
        break;
    case OP_GuildBank:
        if (pinstCGuildBankWnd_guess != 0) {
            pinstCGuildBankWnd_guess->M50DC08_guess(0xb4ab, data_guess, size_guess);
        }
        break;
    case OP_Translocate:
        Handle_OP_Translocate_guess((ZoneCommand456110_guess*)data_guess);
        break;
    // Opcode 0x7F98: new sky and fog settings, as in OP_NewZone.
    case 0x7f98:
        gDisplayB8F0_guess->M43A650_guess(data_guess + 4);
        gDisplayB8F0_guess->SetSecondarySkyName_guess(data_guess + 0x24, EQ_GLOBAL(const float, 0x0063FDA4));
        gZoneB8F0_guess.b1DA_guess = bytes_guess[0];
        gDisplayB8F0_guess->b2D2C_guess = bytes_guess[0] != 0;
        gDisplayB8F0_guess->SetSkyBackground_guess();
        break;
    case 0x7e61:
        Handle_EvolvingItemUpdate_guess(data_guess);
        break;
    case 0x7df1:
        FUN_00456e3b_guess((Argument456E3B_guess*)data_guess);
        break;
    case 0xf40:
    case 0x1525:
    case 0x19cc:
    case 0x2217:
    case 0x3813:
    case 0x3b0c:
    case 0x4a52:
    case 0x5f11:
    case 0x6ea9:
    // Forwarded to the subsystem at 0x00985CF0 only when OP_LogServer enabled it (0x00923D64).
    case 0x70ff:
        if (EQ_GLOBAL(unsigned char, 0x00923D64) != 0 && EQ_GLOBAL(ObjB8F0_guess*, 0x00985CF0) != 0) {
            EQ_GLOBAL(ObjB8F0_guess*, 0x00985CF0)->HandleTicketMessage_guess(connection_guess, opcode_guess, data_guess,
                                                     size_guess);
        }
        break;
    }

    // The opcodes below are handled only while CDisplay check 0x0043745D passes (probably once the
    // world is loaded); the first switch has already run for every opcode.
    if (gDisplayB8F0_guess->M43745D_guess() != 0) {
        switch (opcode_guess) {
        // Cases that need the world drawn: OP_MOTD 0x24D, OP_SpecialMesg 0x2372, OP_FormattedMessage 0x5A48,
        // OP_SimpleMessage 0x673C, OP_Emote 0x547A, OP_Damage 0x5C78, OP_Action 0x497C, OP_Animation 0x2ACF,
        // HP updates 0x695 OP_MobHealth / 0x3BCF OP_HPUpdate / 0x3D2D OP_InitialMobHealth / 0x217B, position
        // updates 0x14CB OP_ClientUpdate / 0x3A2B / 0x4BB4, ground items 0xF47 OP_GroundSpawn / 0x3BC2
        // OP_ClickObject and dropped coins 0x3C4B / 0x46D9, trade and merchant, guild lists, Dz and adventure
        // families, and OP_RequestClientZoneChange 0x7834.
        case OP_SharedTaskSelectWindow:
            if (pinstCTaskSelectWnd_guess != 0) {
                pinstCTaskSelectWnd_guess->M55C13B_guess(data_guess);
                ((VirtB8F0_guess*)pinstCTaskSelectWnd_guess)->V0C0_guess(1, 1);
            }
            break;
        // 0xA4, 0x1CB1, 0x32FB, OP_ClickObject (0x3BC2), 0x46D9: each logs an event code with the time in a
        // 10-slot ring (codes 0x00923964, times 0x0092393C, index 0x0092398C) and most release a pending
        // request.
        case 0xa4:
            if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                EQ_GLOBAL(int, 0x009248D0)--;
            } else {
                EQ_GLOBAL(int, 0x009248D0) = 0;
            }
            EQ_GLOBAL(int, 0x0092398C)++;
            if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                EQ_GLOBAL(int, 0x0092398C) = 0;
            }
            EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 0xb;
            EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
            break;
        case OP_AdventureMerchantSell:
            pinstCPointMerchantWnd_guess->HandleSellReply_guess(data_guess);
            gPcB8F0_guess->bC348_guess = 0;
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546A64_guess();
            }
            break;
        case OP_TradeAcceptClick:
            Handle_OP_TradeAcceptClick_guess((ToggleArgument_guess*)data_guess);
            break;
        // OP_MOTD: kept at 0x00923D98 (copy at 0x00923F98); a leading '~' marks text already shown. It is
        // printed (0x3047) only once the UI is up (0x009917E4).
        case OP_MOTD: {
            if (size_guess > 0) {
                data_guess[size_guess - 1] = 0;
            } else {
                data_guess[0] = 0;
            }
            char* motd_guess = EQ_ARRAY(char, 0x00923D98);
            if (motd_guess[0] == 0x7e) {
                strcpy(motd_guess, data_guess);
            } else {
                motd_guess[0] = 0;
            }
            strcpy(EQ_ARRAY(char, 0x00923F98), motd_guess);
            if (motd_guess[0] != 0x7e && EQ_GLOBAL(int, 0x009917E4) != 0) {
                char line_guess[0x200];
                Ext46DA4A_guess(line_guess, 0x3047, motd_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                chat_guess->dsp_chat(line_guess, 0xf, 1);
                motd_guess[0] = 0x7e;
            }
            break;
        }
        case OP_DzExpeditionInfo:
        case OP_DzMemberList:
        case OP_DzChooseZone:
        case OP_DzMemberListName:
        case OP_DzExpeditionEndsWarning:
        case OP_DzCompass:
        case OP_DzMemberListStatus:
        case OP_DzExpeditionInvite:
        case OP_DzSetLeaderName:
        case OP_DzExpeditionLockoutTimers:
            EQ_GLOBAL(ObjB8F0_guess, 0x009231C8).M447364_guess(connection_guess, opcode_guess,
                                                             data_guess, size_guess);
            break;
        case OP_MobHealth:
            UpdateSpawnHitPoints_guess(((short*)data_guess)[0], (signed char)data_guess[2], 0x64, 0);
            break;
        // OP_SendExpZonein: the zone says we are in the world (MSG_READY_ENTER_WORLD); windows refresh.
        case OP_SendExpZonein:
            Ext574110_guess("Zone Connect -- Received MSG_READY_ENTER_WORLD");
            EQ_GLOBAL(int, 0x00923788) = 1;
            if (EQ_GLOBAL(int, 0x009247BC) == 1) {
                do_approval_guess(0, pStringTable->getString(0x3292, 0));
            }
            if (gPcB8F0_guess != 0) {
                gPcB8F0_guess->bC28C_guess = 1;
                gPcB8F0_guess->bC348_guess = 0;
                if (gPcB8F0_guess->pC288_guess != 0) {
                    gPcB8F0_guess->pC288_guess->M48C11B_guess();
                }
            }
            EQ_GLOBAL(ObjB8F0_guess*, 0x00851390)->SetMusicSelection_guess(8, 0);
            break;
        case OP_CrystalCountUpdate:
            if (size_guess == 0x10 && gPcB8F0_guess != 0) {
                gPcB8F0_guess->i0FAC_guess = words_guess[0];
                gPcB8F0_guess->i0FB0_guess = words_guess[2];
                gPcB8F0_guess->i0FB4_guess = words_guess[1];
                gPcB8F0_guess->i0FB8_guess = words_guess[3];
            }
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546A64_guess();
            }
            break;
        case OP_ColoredText:
            Handle_OP_ColoredText_guess((Text454AD6_guess*)data_guess);
            break;
        // OP_ShopDelItem / OP_TraderDelItem.
        case 0xda9:
            Handle_OP_ShopDelItem_guess((ForwardArgument_guess*)data_guess);
            break;
        // OP_GroundSpawn: a 0x5C-byte object put on the floor under its position (the original height when no
        // floor is found). The constructor links it into 0x00905CC8; that head and the two link words survive
        // the copy.
        case OP_GroundSpawn: {
            New46469FB8F0_guess* placed_guess = new New46469FB8F0_guess;
            if (placed_guess != 0) {
                int saved_guess = EQ_GLOBAL(int, 0x00905CC8);
                int first_guess = placed_guess->i00_guess;
                int second_guess = placed_guess->i04_guess;
                memcpy(placed_guess, data_guess, 0x5c);
                EQ_GLOBAL(int, 0x00905CC8) = saved_guess;
                placed_guess->i00_guess = first_guess;
                placed_guess->i04_guess = second_guess;
                placed_guess->i08_guess = 0;
                float height_guess = gDisplayB8F0_guess->GetFloorHeight_guess(
                    placed_guess->fl28_guess, placed_guess->fl24_guess,
                    placed_guess->fl20_guess + EQ_GLOBAL(const float, 0x0063F4D0));
                if (height_guess == EQ_GLOBAL(const float, 0x00640EA0)) {
                    height_guess = placed_guess->fl20_guess;
                } else {
                    height_guess += EQ_GLOBAL(const float, 0x006410BC);
                }
                placed_guess->actor_0014_guess = gDisplayB8F0_guess->CreateActor_guess(
                    placed_guess->t2C_guess, placed_guess->fl28_guess, placed_guess->fl24_guess,
                    height_guess, placed_guess->fl1C_guess, 0.0f, 0.0f, 1, 1);
            }
            break;
        }
        case OP_ShopPlayerSell:
            Handle_OP_ShopPlayerSell_guess((int)connection_guess, 0xe13, data_guess);
            break;
        case OP_Begging:
            Handle_OP_Begging_guess((int)connection_guess, 0x13e7, (Request455900_guess*)data_guess);
            break;
        case 0x12b2:
            Handle_RecreateSpawn_guess(0x12b2, (unsigned*)data_guess, size_guess);
            break;
        case OP_ClientUpdate:
            Handle_OP_ClientUpdate_guess((Packet451ABA_guess*)data_guess);
            break;
        case 0x1781:
            ((EverQuestB8F0_guess*)pEverQuest)->ReleasePendingRequest_guess(0);
            break;
        case OP_GroupInvite2:
        case OP_GroupInvite:
            HandleGroupInvite_guess(opcode_guess, data_guess);
            break;
        // 0x1A64: a full spawn record for an existing spawn (+0x120 name); list links, actor and char info
        // survive the copy. Skipped when byte +0x244 is 2 or more.
        case 0x1a64:
            if (bytes_guess[0x244] < 2) {
                PlayerB8F0_guess* player_guess = Ext47C88E_guess(data_guess + 0x120);
                if (player_guess != 0) {
                    PlayerB8F0_guess* head_guess = EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CC4);
                    EQPlayer* previous_guess = player_guess->pPrev;
                    EQPlayer* next_guess = player_guess->pNext;
                    void* actor_guess = player_guess->pActorInfo;
                    void* info_guess = player_guess->pCharInfo;
                    ((LargeCopyB393_guess*)player_guess)
                        ->CopyFrom_guess(*(LargeCopyB393_guess*)data_guess);
                    EQ_GLOBAL(PlayerB8F0_guess*, 0x00905CC4) = head_guess;
                    player_guess->pPrev = previous_guess;
                    player_guess->pNext = next_guess;
                    player_guess->pActorInfo = actor_guess;
                    player_guess->pCharInfo = info_guess;
                    if (i00B54_guess == 5) {
                        player_guess->M48A945_guess();
                    }
                }
            }
            break;
        case OP_GroupCancelInvite:
            doUnInvite_guess(data_guess);
            break;
        case OP_OnLevelMessage:
            if (pinstCLargeDialogWnd_guess != 0) {
                pinstCLargeDialogWnd_guess->M55377E_guess(data_guess);
            }
            break;
        case 0x1cb1:
            if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                EQ_GLOBAL(int, 0x009248D0)--;
            } else {
                EQ_GLOBAL(int, 0x009248D0) = 0;
            }
            EQ_GLOBAL(int, 0x0092398C)++;
            if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                EQ_GLOBAL(int, 0x0092398C) = 0;
            }
            EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 0xe;
            EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
            break;
        // Opcode 0x1F46 {spawn id, index 0-31, value 0-100} for the player: one entry of the table at +0xC.
        case 0x1f46:
            if (size_guess == 0xc && gPcB8F0_guess != 0 && gPlayerB8F0_guess != 0) {
                int index_guess = words_guess[1];
                if (index_guess >= 0 && index_guess < 0x20) {
                    unsigned char value_guess = bytes_guess[8];
                    if (value_guess <= 0x64
                        && (unsigned)words_guess[0] == gPlayerB8F0_guess->SpawnID) {
                        gPcB8F0_guess->t00C_guess[index_guess] = value_guess;
                    }
                }
            }
            break;
        case 0x1f5f:
            break;
        case 0x217b:
            UpdateSpawnHitPoints_guess(((unsigned short*)data_guess)[4], words_guess[0], words_guess[1], 1);
            break;
        case 0x1ffa:
            pEverQuest->dsp_chat(data_guess, 0x145, 1);
            break;
        case 0x1fed: {
            PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
            if (player_guess != 0) {
                player_guess->Actor_guess()->i1A8_guess = words_guess[1];
            }
            break;
        }
        case OP_ShopPlayerBuy:
            Handle_OP_ShopPlayerBuy_guess(data_guess);
            break;
        // OP_SpecialMesg: {mode, type, channel bytes, color, spawn id, text, three words, then a name}.
        case OP_SpecialMesg: {
            char* cursor_guess = data_guess;
            int mode_guess = (signed char)*cursor_guess++;
            int type_guess = (signed char)*cursor_guess++;
            int channel_guess = (signed char)*cursor_guess++;
            int color_guess = *(int*)cursor_guess;
            cursor_guess += 4;
            int spawn_guess = *(int*)cursor_guess;
            cursor_guess += 4;
            char* text_guess = cursor_guess;
            int* tail_guess = (int*)(text_guess + strlen(text_guess) + 1);
            Handle_OP_SpecialMesg_guess(mode_guess, channel_guess, text_guess, tail_guess[0], tail_guess[1],
                               tail_guess[2], spawn_guess, (char*)&tail_guess[3], type_guess,
                               color_guess);
            break;
        }
        case OP_LootComplete:
        case OP_EndLootRequest:
            EQ_GLOBAL(ObjB8F0_guess*, 0x00850C40)->FinishLoot_guess();
            break;
        case OP_SpellEffect:
            if (bytes_guess[0x18] != 0) {
                Ext4B6A36_guess()->M4B6BC5_guess(words_guess[1], words_guess[2], words_guess[0],
                                                 words_guess[3], words_guess[4], words_guess[5]);
            } else {
                Ext4B6A36_guess()->CancelEffect_guess(words_guess[1], words_guess[2], words_guess[0]);
            }
            break;
        case 0x224d:
            AddCoinsByType_guess((ApplyRequest457A91_guess*)data_guess);
            break;
        case OP_GMTraining:
            Handle_OP_GMTraining_guess((int)connection_guess, 0x238f, (Target452387_guess*)data_guess);
            break;
        case OP_PVPLeaderBoardReply:
        case OP_PVPLeaderBoardDetailsReply:
            if (pinstCPvpLeaderboardWnd_guess != 0) {
                pinstCPvpLeaderboardWnd_guess->M54B657_guess(connection_guess, opcode_guess,
                                                         data_guess, size_guess);
            }
            break;
        case OP_RandomNameGenerator:
            if (pinstCCharacterCreation_guess != 0) {
                pinstCCharacterCreation_guess->M4EE824_guess(data_guess + 8);
            }
            break;
        case OP_PlayMP3:
            if (pinstCLargeDialogWnd_guess != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00851390)->PlayMp3_guess(
                    data_guess, pinstCLargeDialogWnd_guess->GetMp3Volume_guess());
            }
            break;
        case 0x26b3:
            break;
        case OP_CustomTitles:
            if (EQ_GLOBAL(ObjB8F0_guess*, 0x00991FA8) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00991FA8)->M554E7A_guess(data_guess);
            }
            break;
        case OP_Animation: {
            struct {
                unsigned short id_guess;
                unsigned char b2_guess;
                unsigned char b3_guess;
            } sound_guess;
            memcpy(&sound_guess, data_guess, 4);
            PlayerB8F0_guess* player_guess = Ext401B28_guess(sound_guess.id_guess);
            if (player_guess != 0) {
                VirtB8F0_guess* emitter_guess = player_guess->GetAnimation_guess();
                emitter_guess->V008_guess(sound_guess.b3_guess, 1, 0,
                                          (float)sound_guess.b2_guess
                                              * EQ_GLOBAL(const float, 0x00640E38),
                                          1);
            }
            break;
        }
        case OP_PickPocket:
            Handle_OP_PickPocket_guess((int)connection_guess, 0x2ad8, (Request455B05_guess*)data_guess);
            break;
        case OP_CancelTrade:
            Handle_OP_CancelTrade_guess((int*)data_guess);
            break;
        // 0xF4D OP_GuildMemberDetails / OP_GuildMemberUpdate; 0x147D OP_GuildMemberList; 0x3230
        // OP_GuildDeleteGuild; 0x32CF OP_GuildMemberPublicNote; 0x461A OP_GuildMemberLevel; 0x4CC7
        // OP_GuildRenameGuild; 0x6957 OP_GuildsList / OP_ZoneGuildList; 0x6966 OP_GuildMemberRankAltBanker /
        // OP_SetGuildRank; 0x712A OP_GuildMemberDelete; 0x754E OP_GuildMemberAdd; 0x7C59
        // OP_GuildMemberRename; 1 more without an EQEmu name.
        case 0xf4d:  // OP_GuildMemberUpdate / OP_GuildMemberDetails
        case OP_GuildMemberList:
        case 0x2ec9:
        case OP_GuildDeleteGuild:
        case 0x32cf:  // OP_GuildMemberPublicNote
        case OP_GuildMemberLevel:
        case OP_GuildRenameGuild:
        case OP_GuildsList:  // OP_GuildsList / OP_ZoneGuildList
        case 0x6966:  // OP_SetGuildRank / OP_GuildMemberRankAltBanker
        case OP_GuildMemberDelete:
        case OP_GuildMemberAdd:
        case OP_GuildMemberRename:
            EQ_GLOBAL(ObjB8F0_guess, 0x00905D38).M40B8CB_guess(connection_guess, opcode_guess,
                                                             data_guess, size_guess);
            break;
        case 0x2f2e:
            if ((unsigned)words_guess[0] == gPlayerB8F0_guess->SpawnID
                && floats_guess[1] >= EQ_GLOBAL(const float, 0x0063F4D0)
                && floats_guess[1] < EQ_GLOBAL(const float, 0x00644F70)) {
                char line_guess[0x200];
                ReturnOne_guess(gPcB8F0_guess, floats_guess[1]);
                Ext46DA4A_guess(line_guess, 0xfa1,
                                _itoa(gProfileB8F0_guess->level_11a4_guess, EQ_ARRAY(char, 0x0099DB00),
                                      10),
                                0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(line_guess, 0xf, 1);
            }
            break;
        case OP_GetGuildMOTDReply: {
            char line_guess[0x400];
            Ext46DA4A_guess(line_guess, 0x1d4, data_guess + 0x44, data_guess + 0x88, 0, 0, 0, 0,
                            0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0xf, 1);
            break;
        }
        case OP_TradeCoins:
            Handle_OP_TradeCoins_guess((Argument4540EF_guess*)data_guess);
            break;
        case 0x32fb:
            if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                EQ_GLOBAL(int, 0x009248D0)--;
            } else {
                EQ_GLOBAL(int, 0x009248D0) = 0;
            }
            EQ_GLOBAL(int, 0x0092398C)++;
            if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                EQ_GLOBAL(int, 0x0092398C) = 0;
            }
            EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 0xf;
            EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
            break;
        case OP_LevelAppearance: {
            PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
            if (player_guess != 0) {
                player_guess->PlayLevelAppearance_guess(data_guess);
            }
            break;
        }
        case 0x3739: {
            PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
            if (player_guess != 0
                && EQ_GLOBAL(ObjB8F0_guess, 0x009248E0).M60CA90_guess(2) == 0) {
                char line_guess[0x200];
                Ext46DA4A_guess(line_guess, 0x5ab, player_guess->Name, data_guess + 4, 0, 0, 0, 0,
                                0, 0, 0);
                pEverQuest->dsp_chat(line_guess, 0x102, 1);
            }
            break;
        }
        case OP_TradeRequest:
            Handle_OP_TradeRequest_guess((Argument4541E0_guess*)data_guess);
            break;
        case OP_TraderShop:
            Handle_OP_TraderShop_guess((Argument453E5D_guess*)data_guess);
            break;
        case 0x35dc:
            if ((unsigned)words_guess[0] == gPlayerB8F0_guess->SpawnID && words_guess[2] >= 0
                && words_guess[1] >= 0 && words_guess[1] < 0x4a) {
                ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M41AA6A_guess(words_guess[1], words_guess[2]);
            }
            break;
        case 0x38dd:
            break;
        case 0x3981:
            if (size_guess == 0x8c && gPcB8F0_guess != 0) {
                ((CopyObject45AEFB_guess*)gPcB8F0_guess->t10C0_guess)
                    ->Copy_guess((CopyObject45AEFB_guess*)(data_guess + 8));
            }
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546A64_guess();
            }
            break;
        case 0x395e:
            if (data_guess != 0) {
                PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
                if (player_guess != 0) {
                    EQ_GLOBAL(ObjB8F0_guess*, 0x00985C88)->M4C251B_guess(player_guess);
                }
            }
            EmitTableEffectOnSpawn_guess(words_guess[0], words_guess[1]);
            break;
        case 0xa8:
            EmitTableEffectOnSpawn_guess(words_guess[0], words_guess[1]);
            break;
        // Packed position update (0x3A2B) widened to the 0x16-byte form Handle_OP_ClientUpdate takes.
        case 0x3a2b: {
            Unpacked3A2BB8F0_guess unpacked_guess;
            Packed3A2BB8F0_guess* packed_guess = (Packed3A2BB8F0_guess*)data_guess;
            memset(&unpacked_guess, 0, 0x16);
            unpacked_guess.id_guess = packed_guess->id_guess;
            unpacked_guess.a_guess = (int)packed_guess->a_guess;
            unpacked_guess.b_guess = (int)packed_guess->b_guess;
            unpacked_guess.c_guess = (int)packed_guess->c_guess;
            unpacked_guess.d_guess = packed_guess->d_guess;
            Handle_OP_ClientUpdate_guess((Packet451ABA_guess*)&unpacked_guess);
            break;
        }
        case OP_InitialMobHealth:
            UpdateSpawnHitPoints_guess(((short*)data_guess)[0], (signed char)data_guess[2], 0x64, 1);
            break;
        // Dropped coins on the ground: like OP_GroundSpawn, but in the list at 0x00905CCC.
        case 0x3c4b: {
            New477AD3B8F0_guess* placed_guess = new New477AD3B8F0_guess;
            if (placed_guess != 0) {
                int first_guess = placed_guess->i00_guess;
                int saved_guess = EQ_GLOBAL(int, 0x00905CCC);
                int second_guess = placed_guess->i04_guess;
                *placed_guess = *(New477AD3B8F0_guess*)data_guess;
                EQ_GLOBAL(int, 0x00905CCC) = saved_guess;
                placed_guess->i00_guess = first_guess;
                placed_guess->i04_guess = second_guess;
                float height_guess = gDisplayB8F0_guess->GetFloorHeight_guess(
                                         placed_guess->fl38_guess, placed_guess->fl3C_guess,
                                         placed_guess->fl40_guess
                                             + EQ_GLOBAL(const float, 0x0063F4D0))
                                     + EQ_GLOBAL(const float, 0x006410BC);
                placed_guess->actor_0034_guess = gDisplayB8F0_guess->CreateActor_guess(
                    placed_guess->t50_guess, placed_guess->fl38_guess, placed_guess->fl3C_guess,
                    height_guess, placed_guess->fl44_guess, 0.0f, 0.0f, 1, 1);
            }
            break;
        }
        case OP_HPUpdate:
            UpdateSpawnHitPoints_guess(((unsigned short*)data_guess)[4], words_guess[0], words_guess[1], 0);
            break;
        // OP_ClickObject reply: for us (id 0 or ours) log codes 8 and 0xA; the clicked object leaves the
        // list.
        case OP_ClickObject:
            if (gPlayerB8F0_guess != 0) {
                if (words_guess[1] == 0
                    || (unsigned)words_guess[1] == gPlayerB8F0_guess->SpawnID) {
                    EQ_GLOBAL(int, 0x0092398C)++;
                    if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                        EQ_GLOBAL(int, 0x0092398C) = 0;
                    }
                    EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 8;
                    EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
                    if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                        EQ_GLOBAL(int, 0x009248D0)--;
                    } else {
                        EQ_GLOBAL(int, 0x009248D0) = 0;
                    }
                    if (EQ_GLOBAL(int, 0x009248D4) > 0) {
                        EQ_GLOBAL(int, 0x009248D4)--;
                    } else {
                        EQ_GLOBAL(int, 0x009248D4) = 0;
                    }
                    EQ_GLOBAL(int, 0x0092398C)++;
                    if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                        EQ_GLOBAL(int, 0x0092398C) = 0;
                    }
                    EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 0xa;
                    EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
                }
                New46469FB8F0_guess* found_guess =
                    EQ_GLOBAL(New46469FB8F0_guess*, 0x00905CC8)->FindByDropId_guess(words_guess[0]);
                if (found_guess != 0 && found_guess->i50_guess >= 0) {
                    delete found_guess;
                }
            }
            break;
        case 0x3b40:
            MoveToSafePoint_guess();
            break;
        case OP_SendTitleList:
            EQ_GLOBAL(ObjB8F0_guess, 0x00992918).Handle_OP_SendTitleList_guess(data_guess);
            break;
        case OP_TradeRequestAck:
            Handle_OP_TradeRequestAck_guess((Argument453F72_guess*)data_guess);
            break;
        // OP_SomeItemPacketMaybe (EQEmu's name): a missile from the server. The packet has the 0x88-byte
        // layout this client sends as 0x4033 when it shoots, and 0x00476F34 builds the missile from it as a
        // copy.
        case 0x4033:  // OP_SomeItemPacketMaybe
            new New476F34B8F0_guess(0, 0, data_guess, 0, 0, 0);
            break;
        case 0x402b:
            if (size_guess == 8 && gPcB8F0_guess != 0) {
                gPcB8F0_guess->i0FA4_guess = words_guess[0];
                gPcB8F0_guess->i0FA8_guess = words_guess[1];
            }
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546A64_guess();
            }
            break;
        case OP_PickLockSuccess:
            if (words_guess[0] == 0x11) {
                pEverQuest->dsp_chat(pStringTable->getString(0x5b2, 0), 0x10e, 1);
            } else if (words_guess[0] == 0x23) {
                pEverQuest->dsp_chat(pStringTable->getString(0x5b1, 0), 0x10e, 1);
            }
            break;
        case OP_AdventureMerchantResponse:
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546E80_guess(data_guess);
            }
            break;
        case OP_ShopRequest:
            Handle_OP_ShopRequest_guess((Argument453E9B_guess*)data_guess);
            break;
        // Coin pickup (0x46D9): if we picked it up with an empty coin cursor, the coins go to the cursor
        // (+0x11E4.. +0x11F0) and the cursor type 1-4 is set; the ground object is deleted either way.
        case 0x46d9:
            if (gPlayerB8F0_guess != 0) {
                if (words_guess[1] != 0
                    && (unsigned)words_guess[1] == gPlayerB8F0_guess->SpawnID) {
                    if (EQ_GLOBAL(int, 0x009248D0) > 0) {
                        EQ_GLOBAL(int, 0x009248D0)--;
                    } else {
                        EQ_GLOBAL(int, 0x009248D0) = 0;
                    }
                    EQ_GLOBAL(int, 0x0092398C)++;
                    if (EQ_GLOBAL(int, 0x0092398C) > 9) {
                        EQ_GLOBAL(int, 0x0092398C) = 0;
                    }
                    EQ_ARRAY(int, 0x00923964)[EQ_GLOBAL(int, 0x0092398C)] = 9;
                    EQ_ARRAY(int, 0x0092393C)[EQ_GLOBAL(int, 0x0092398C)] = Ext576E80_guess();
                }
                New477AD3B8F0_guess* found_guess =
                    EQ_GLOBAL(New477AD3B8F0_guess*, 0x00905CCC)->M477BA0_guess(words_guess[0]);
                if (found_guess != 0) {
                    int who_guess = words_guess[1];
                    if (who_guess != 0 && (unsigned)who_guess == gPlayerB8F0_guess->SpawnID
                        && gDisplayB8F0_guess->b0011_guess == 0
                        && gProfileB8F0_guess->i11E4_guess == 0
                        && gProfileB8F0_guess->i11E8_guess == 0
                        && gProfileB8F0_guess->i11EC_guess == 0
                        && gProfileB8F0_guess->i11F0_guess == 0) {
                        gDisplayB8F0_guess->b0011_guess = 0;
                        if (found_guess->i08_guess != 0) {
                            ((PropertyOwner_guess*)gPcBaseB8F0_guess)
                                ->Set11e4_guess(found_guess->i08_guess);
                        } else if (found_guess->i0C_guess != 0) {
                            ((PropertyOwner_guess*)gPcBaseB8F0_guess)
                                ->SetGoldCursor_guess(found_guess->i0C_guess);
                        } else if (found_guess->i10_guess != 0) {
                            ((PropertyOwner_guess*)gPcBaseB8F0_guess)
                                ->SetSilverCursor_guess(found_guess->i10_guess);
                        } else if (found_guess->i14_guess != 0) {
                            ((PropertyOwner_guess*)gPcBaseB8F0_guess)
                                ->SetCopperCursor_guess(found_guess->i14_guess);
                        }
                        if (gProfileB8F0_guess->i11E4_guess > 0) {
                            gDisplayB8F0_guess->b0011_guess = 1;
                        } else if (gProfileB8F0_guess->i11E8_guess > 0) {
                            gDisplayB8F0_guess->b0011_guess = 2;
                        } else if (gProfileB8F0_guess->i11EC_guess > 0) {
                            gDisplayB8F0_guess->b0011_guess = 3;
                        } else if (gProfileB8F0_guess->i11F0_guess > 0) {
                            gDisplayB8F0_guess->b0011_guess = 4;
                        }
                    }
                    delete found_guess;
                }
            }
            break;
        case OP_GuildMOTD:
            EQ_GLOBAL(ObjB8F0_guess, 0x00905D38).M40A7FD_guess(data_guess);
            break;
        case OP_Action: {
            unsigned char packet_guess[0x20];
            memcpy(packet_guess, data_guess, 0x1f);
            PlayerB8F0_guess* player_guess =
                Ext401B28_guess(((unsigned short*)packet_guess)[0]);
            if (player_guess != 0) {
                player_guess->IWasHit_guess(packet_guess);
            }
            break;
        }
        // Opcode 0x47A7 {name, platinum, gold, silver, copper}: one line for the largest coin (0x5AC-0x5AF)
        // naming the giver, then all four are applied to the purse.
        case 0x47a7: {
            struct {
                char name_guess[0x28];
                int v28_guess;
                int v2C_guess;
                int v30_guess;
                int v34_guess;
            } split_guess;
            char line_guess[0x200];
            memcpy(&split_guess, data_guess, 0x38);
            if (split_guess.v28_guess > 0) {
                Ext46DA4A_guess(
                    line_guess, 0x5ac,
                    _itoa(split_guess.v28_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(split_guess.name_guess), 0,
                    0, 0, 0, 0, 0, 0);
            } else if (split_guess.v2C_guess > 0) {
                Ext46DA4A_guess(
                    line_guess, 0x5ad,
                    _itoa(split_guess.v2C_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(split_guess.name_guess), 0,
                    0, 0, 0, 0, 0, 0);
            } else if (split_guess.v30_guess > 0) {
                Ext46DA4A_guess(
                    line_guess, 0x5ae,
                    _itoa(split_guess.v30_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(split_guess.name_guess), 0,
                    0, 0, 0, 0, 0, 0);
            } else if (split_guess.v34_guess > 0) {
                Ext46DA4A_guess(
                    line_guess, 0x5af,
                    _itoa(split_guess.v34_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    ((EverQuestB8F0_guess*)pEverQuest)->M492EC2_guess(split_guess.name_guess), 0,
                    0, 0, 0, 0, 0, 0);
            }
            pEverQuest->dsp_chat(line_guess, 2, 1);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417CF2_guess(split_guess.v28_guess);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D1C_guess(split_guess.v2C_guess);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D46_guess(split_guess.v30_guess);
            ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M417D70_guess(split_guess.v34_guess);
            break;
        }
        // A batch of 0x16-byte position updates (0x4BB4). The loop runs to the larger of the header count and
        // the entries that fit (confirmed in the binary at 0x00460CC6), so a packet whose count is too big is
        // read past its end: an original bug.
        case 0x4bb4: {
            unsigned count_guess = (size_guess - 4) / 0x16;
            char* entry_guess = data_guess + 4;
            if (count_guess > (unsigned)words_guess[0]) {
                words_guess[0] = count_guess;
            }
            for (unsigned index_guess = 0; index_guess < (unsigned)words_guess[0];
                 index_guess++) {
                Handle_OP_ClientUpdate_guess((Packet451ABA_guess*)entry_guess);
                entry_guess += 0x16;
            }
            break;
        }
        case OP_DisciplineTimer:
            gPcB8F0_guess->SetDisciplineTimer_guess(words_guess[0],
                                         Ext576E80_guess() + (words_guess[1] - words_guess[2]));
            break;
        case 0x519e:
            pEverQuest->dsp_chat(pStringTable->getString(0x22b1, 0), 0xf, 1);
            break;
        case 0x4f05: {
            char line_guess[0x200];
            Ext46DA4A_guess(line_guess, 0x5b3, data_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(line_guess, 0xf, 1);
            break;
        }
        case OP_Emote:
            Handle_OP_Emote_guess(data_guess);
            break;
        case 0x5811:
            break;
        case 0x59d6:
            pConfirmationDialogPool_guess->Activate(
                (NotifyBaseB8F0_guess*)EQ_GLOBAL(NotifyViewB8F0_guess*, 0x00988DF0), 0x82,
                pStringTable->getString(0x1447, 0), 0, 0xafc8, 0, 0);
            EQ_GLOBAL(int, 0x009248D0)++;
            EQ_GLOBAL(int, 0x009248D4)++;
            break;
        case OP_FormattedMessage:
            Handle_OP_FormattedMessage_guess(data_guess);
            break;
        case 0x5dde: {
            PlayerB8F0_guess* player_guess = Ext47C88E_guess(data_guess);
            if (player_guess != 0) {
                if (player_guess == EQ_GLOBAL(PlayerB8F0_guess*, 0x00905D18)) {
                    ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x00850C40))->V088_guess();
                }
                player_guess->M4849B2_guess();
                operator delete(player_guess);
            }
            break;
        }
        // OP_PVPStats (0x5CC0, 0x1204 bytes): counters at +0xEAC.., two 0x58-byte blocks, and up to 50 named
        // 0x58-byte entries rehashed into the table at +0xF78.
        case OP_PVPStats:
            if (size_guess == 0x1204 && gPcB8F0_guess != 0) {
                gPcB8F0_guess->i0EB4_guess = words_guess[2];
                gPcB8F0_guess->i0EB0_guess = words_guess[1];
                gPcB8F0_guess->i0EAC_guess = words_guess[0];
                gPcB8F0_guess->i0EB8_guess = words_guess[3];
                gPcB8F0_guess->i0EC0_guess = words_guess[5];
                gPcB8F0_guess->i0EBC_guess = words_guess[4];
                gPcB8F0_guess->i0EC4_guess = words_guess[6];
                gPcB8F0_guess->i0F88_guess = words_guess[7];
                gPcB8F0_guess->i0F8C_guess = words_guess[8];
                Block58B8F0_guess block_guess;
                block_guess = *(Block58B8F0_guess*)(data_guess + 0x24);
                gPcB8F0_guess->s0F20_guess = block_guess;
                block_guess = *(Block58B8F0_guess*)(data_guess + 0x7c);
                gPcB8F0_guess->s0EC8_guess = block_guess;
                ((ChainArray454F3F_guess*)gPcB8F0_guess->t0F78_guess)->Clear_guess();
                char* entry_guess = data_guess + 0xd4;
                for (int left_guess = 0x32; left_guess != 0; left_guess--) {
                    if (entry_guess[0] != 0) {
                        ((HashTable_guess*)gPcB8F0_guess->t0F78_guess)
                            ->Insert_guess((HashPayload_guess*)entry_guess,
                                           Ext574890_guess(entry_guess));
                    }
                    entry_guess += 0x58;
                }
            }
            if (pinstCPvPStatsWnd_guess != 0) {
                pinstCPvPStatsWnd_guess->M54C4CC_guess();
            }
            if (pinstCPointMerchantWnd_guess != 0) {
                pinstCPointMerchantWnd_guess->M546A64_guess();
            }
            break;
        case OP_Damage:
            Handle_OP_Damage_guess((Argument452C54_guess*)data_guess);
            break;
        case OP_IncreaseStats:
            Handle_OP_IncreaseStats_guess((DispatchRequest_guess*)data_guess);
            break;
        case OP_SetTitleReply:
            if (words_guess[0] == 0) {
                EQ_GLOBAL(ObjB8F0_guess, 0x00992918).SetTitle_guess(words_guess[9], data_guess + 4);
            } else {
                EQ_GLOBAL(ObjB8F0_guess, 0x00992918).SetSuffix_guess(words_guess[9], data_guess + 4);
            }
            break;
        // 0x677 OP_AdventureData; 0xD0F OP_AdventureLeaderboardReply; 0x1DB5 OP_AdventureInfo; 0x3906
        // OP_AdventureFinish; 0x3F26 OP_AdventureDetails; 0x420A OP_AdventurePointsUpdate; 0x56CD
        // OP_AdventureStatsReply; 0x64AC OP_AdventureUpdate; 4 more without an EQEmu name.
        case OP_AdventureData:
        case OP_AdventureLeaderboardReply:
        case 0xff1:
        case 0x16c6:
        case OP_AdventureInfo:
        case OP_AdventureFinish:
        case OP_AdventureDetails:
        case OP_AdventurePointsUpdate:
        case 0x475e:
        case 0x49a5:
        case OP_AdventureStatsReply:
        case OP_AdventureUpdate:
            if (gPcSecondB8F0_guess->i108_guess & 0x20) {
                EQ_GLOBAL(ObjB8F0_guess, 0x009232F0).M4089B2_guess(connection_guess, opcode_guess,
                                                                 data_guess, size_guess);
            }
            break;
        case OP_Death: {
            int packet_guess[8];
            memcpy(packet_guess, data_guess, 0x20);
            ReportDeath_guess(packet_guess);
            break;
        }
        case 0x60f4:
            Handle_FormattedEmote_guess((int)data_guess, size_guess);
            break;
        case 0x60a0:
            DispatchPackedIdPair_guess(words_guess[0], words_guess[1]);
            break;
        case OP_FinishTrade:
            Handle_OP_FinishTrade_guess();
            break;
        case OP_SimpleMessage:
            Handle_OP_SimpleMessage_guess((Argument45858E_guess*)data_guess);
            break;
        case 0x66f9:
            if (gPcB8F0_guess != 0) {
                ((ObjB8F0_guess*)gPcBaseB8F0_guess)->M40E293_guess(words_guess[1]);
            }
            break;
        case 0x65b1:
            if (IsOkToTransact_guess()) {
                if (words_guess[1] == 0 && pinstCProgressionSelectionWnd_guess != 0) {
                    ((VirtB8F0_guess*)pinstCProgressionSelectionWnd_guess)->V0C0_guess(1, 1);
                }
                EQ_GLOBAL(ObjB8F0_guess*, 0x0079C120)->M4050D0_guess(0x65b1, data_guess, size_guess);
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x1835, 0), 0xf, 1);
                EQ_GLOBAL(ObjB8F0_guess*, 0x0079C120)->SendProgressionCancel_guess();
            }
            break;
        case OP_TradeBusy:
            Handle_OP_TradeBusy_guess((Argument4542FB_guess*)data_guess);
            break;
        // 0x5886 OP_SharedTaskMemberChange / OP_TaskMemberChange; 0x722F OP_SharedTaskMemberList; 0x729C
        // OP_AnnoyingZoneUnknown; 0x79B4 OP_SharedTaskInvite / OP_TaskMemberInvite; 9 more without an EQEmu
        // name.
        case 0x16f0:
        case 0x24f0:
        case 0x2568:
        case 0x4562:
        case 0x46aa:
        case 0x5886:  // OP_TaskMemberChange / OP_SharedTaskMemberChange
        case 0x64d7:
        case 0x67c6:
        case 0x6c97:
        case 0x7135:
        case OP_SharedTaskMemberList:
        case 0x729c:  // OP_AnnoyingZoneUnknown
        case 0x79b4:  // OP_TaskMemberInvite / OP_SharedTaskInvite
            EQ_GLOBAL(ObjB8F0_guess, 0x0079DC78).HandleTaskMessage_guess(opcode_guess, data_guess,
                                                             size_guess);
            break;
        case OP_LinkedReuse:
            gPcB8F0_guess->SetLinkedReuseTimer_guess(words_guess[0],
                                         Ext576E80_guess() + (words_guess[1] - words_guess[2]));
            break;
        // OP_RandomReply: unless the roller is on the ignore list (0x0049297B scans 0x0095BAB4), "%1 rolls"
        // (0x43E) and the low/high/result line (0x43F).
        case OP_RandomReply:
            if (((EverQuestB8F0_guess*)pEverQuest)->BeingIgnored_guess(data_guess + 0xc) == 0) {
                char first_guess[0x20];
                char second_guess[0x20];
                char third_guess[0x20];
                _itoa(words_guess[0], first_guess, 10);
                _itoa(words_guess[1], second_guess, 10);
                _itoa(words_guess[2], third_guess, 10);
                Ext46DC2E_guess((PcSecondB8F0_guess*)gPcB8F0_guess, 0x43e, 0x11f, data_guess + 0xc,
                                0, 0, 0, 0, 0, 0, 0, 0, 0);
                Ext46DC2E_guess((PcSecondB8F0_guess*)gPcB8F0_guess, 0x43f, 0x11f, first_guess,
                                second_guess, third_guess, 0, 0, 0, 0, 0, 0, 0);
            }
            break;
        case OP_Bandolier:
            if (pinstCBandolierWnd_guess != 0) {
                pinstCBandolierWnd_guess->M4DB5D5_guess(0x6f0c, data_guess);
            }
            break;
        case 0x6e07:
            break;
        case OP_TraderBuy:
            Handle_OP_TraderBuy_guess((Argument453EEA_guess*)data_guess);
            break;
        case 0x732c: {
            // The original copies 8 bytes over a 4-byte local next to the saved `this`, and then
            // passes that slot on: the second word is what the callee gets.
            int ids_guess[2];
            memcpy(ids_guess, data_guess, 8);
            PlayerB8F0_guess* player_guess = Ext401B28_guess(ids_guess[0]);
            if (player_guess != 0) {
                Emit4C5C39B8F0_guess emit_guess;
                emit_guess.fl20_guess = emit_guess.fl1C_guess = EQ_GLOBAL(const float, 0x00640E20);
                emit_guess.y_guess = player_guess->Y;
                emit_guess.x_guess = player_guess->X;
                emit_guess.z_guess = player_guess->Z;
                EQ_GLOBAL(ObjB8F0_guess*, 0x00851390)->WavePlay_guess(ids_guess[1], (int)&emit_guess);
            }
            break;
        }
        case OP_ClearLeadershipAbilities:
            for (int index_guess = 0; index_guess < 0x40; index_guess++) {
                gPcB8F0_guess->t0BF0_guess[index_guess] = 0;
            }
            if (EQ_GLOBAL(ObjB8F0_guess*, 0x00991C24) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00991C24)->UpdateRows_guess();
            }
            break;
        case OP_WhoAllResponse:
            Handle_OP_WhoAllResponse_guess((Report4572DD_guess*)data_guess);
            break;
        // OP_FeignDeath: our own feign stops auto-attack (0x00923770). Byte 8 set prints the two-name text
        // 0x2F52, else "%1 has fallen" (0x5B0).
        case OP_FeignDeath: {
            PlayerB8F0_guess* player_guess = Ext401B28_guess(words_guess[0]);
            if (player_guess != 0) {
                char line_guess[0x200];
                if (player_guess == gPlayerB8F0_guess) {
                    EQ_GLOBAL(ObjB8F0_guess, 0x00923770).SetAutoAttack_guess(0);
                    EQ_GLOBAL(ObjB8F0_guess, 0x00923770).SetAutoFire_guess(0);
                }
                if (bytes_guess[8] != 0) {
                    PlayerB8F0_guess* other_guess = Ext401B28_guess(words_guess[1]);
                    if (other_guess == 0) {
                        break;
                    }
                    Ext46DA4A_guess(line_guess, 0x2f52, player_guess->M4793B5_guess(),
                                    other_guess->M4793B5_guess(), 0, 0, 0, 0, 0, 0, 0);
                } else {
                    Ext46DA4A_guess(line_guess, 0x5b0, player_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0);
                }
                pEverQuest->dsp_chat(line_guess);
            }
            break;
        }
        // OP_WearChange: material slots 7 and 8 (primary, secondary) load model "IT<n>"; the others apply
        // only while the spawn is not in a non-player illusion (0xFF), slot 9 is the face
        // (0x0047DEC4 swaps the head texture "%sHE%02d%d1_MDF" from the spawn's FaceHair).
        case OP_WearChange: {
            unsigned short* shorts_guess = (unsigned short*)data_guess;
            PlayerB8F0_guess* player_guess = Ext401B28_guess(shorts_guess[0]);
            if (player_guess != 0) {
                unsigned char kind_guess = bytes_guess[8];
                if (kind_guess == 7 || kind_guess == 8) {
                    char line_guess[0x200];
                    sprintf(line_guess, "IT%u", shorts_guess[1]);
                    if (bytes_guess[8] == 7) {
                        player_guess->pad_290[3] = words_guess[1];
                    } else {
                        player_guess->pad_290[4] = words_guess[1];
                    }
                    player_guess->M48083A_guess(bytes_guess[8], line_guess, 1);
                } else if (player_guess->InNonPCRaceIllusion == 0xff) {
                    if (kind_guess == 9) {
                        player_guess->SwapFace_guess(shorts_guess[1], player_guess->FaceHair);
                    } else {
                        player_guess->HandleMaterialEx_guess(bytes_guess[8], shorts_guess[1],
                                                    player_guess->GetArmorType_guess(kind_guess),
                                                    words_guess[1], 1);
                    }
                }
            }
            break;
        }
        // OP_RequestClientZoneChange (MSG_TELEPORT_PC in the client's own text): only when the zone's .s3d or
        // .eqg exists; a refused move snaps back.
        case OP_RequestClientZoneChange: {
            char zone_guess[0x80];
            char other_guess[0x80];
            ((ObjB8F0_guess*)gWorldB8F0_guess)->M5F6ED0_guess(words_guess[0], zone_guess);
            strcpy(other_guess, zone_guess);
            strcat(zone_guess, ".s3d");
            strcat(other_guess, ".eqg");
            if (Ext576670_guess(zone_guess) == 1 || Ext576670_guess(other_guess) == 1) {
                if (!gPlayerB8F0_guess->WarpPlayer_guess(words_guess[0], floats_guess[1],
                                                      floats_guess[2], floats_guess[3],
                                                      floats_guess[4], "MSG_TELEPORT_PC",
                                                      words_guess[5])) {
                    gPlayerB8F0_guess->M48C130_guess(&gPlayerB8F0_guess->Y, 5);
                }
            }
            break;
        }
        case OP_SpawnAppearance:
            Handle_OP_SpawnAppearance_guess((int)connection_guess, 0x7c32, data_guess, size_guess);
            break;
        case OP_ShopEndConfirm:
        case OP_ShopEnd:
            ((VirtB8F0_guess*)EQ_GLOBAL(ObjB8F0_guess*, 0x00850C4C))->V088_guess();
            break;
        // 0x7F63 OP_LockoutTimerInfo; 5 more without an EQEmu name.
        case 0x1573:
        case 0x18cb:
        case 0x455f:
        case 0x4625:
        case 0x6d32:
        case OP_LockoutTimerInfo:
            EQ_GLOBAL(ObjB8F0_guess*, 0x0079C120)->M4050D0_guess(opcode_guess, data_guess, size_guess);
            break;
        case OP_MoneyOnCorpse:
            if (EQ_GLOBAL(PlayerB8F0_guess*, 0x00905D18) != 0) {
                EQ_GLOBAL(ObjB8F0_guess*, 0x00850C40)->HandleLootResponse_guess(bytes_guess[0], words_guess[1],
                                                         words_guess[2], words_guess[3],
                                                         words_guess[4]);
            }
            break;
        // Opcode 0xD743: a server-driven zone change "ZoneTransfer".
        case 0xd743:
            ((EverQuestB8F0_guess*)pEverQuest)->MoveToZone_guess(
                words_guess[0], "ZoneTransfer", 0, words_guess[5], floats_guess[1],
                floats_guess[2], floats_guess[3], (int)floats_guess[4]);
            break;
        }
    }
    return 1;
}

