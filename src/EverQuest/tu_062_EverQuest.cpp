// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 62: a hint from compare/tumap.py.
// CEverQuest, the client's central game object (pEverQuest 0x988DF0): login and char select, zoning
// (ProcessGame -> StartNetworkGame -> GetZoneInfoFromNetwork -> EnterZone -> DoMainLoop), chat and slash
// command sends, mouse and movement, the chat/mail server callbacks and the popup answers. Names follow
// the Mac/MQ2 CEverQuest symbols where known. GlobalState_guess, TargetOwner_guess, DisconnectOwner_guess,
// NamedSlotTable_guess, SlotOwner_guess and the EverQuest*_guess types are all views of it; +4 is its mail
// handler (vtable 0x649890), +8 its popup handler (0x64988C). DisplayState_guess is a door (EQSwitch).
// 0x4912B1 is SendMessage on the world connection 0x905CA0; OP_ names are EQEmu's patch_Titanium.conf.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/bounded_array.h"
#include "titanium/slots.h"
#include <stdarg.h>
#include <stdio.h>
#include <string>
#include <new>
#include <windows.h>

struct ActionPosition_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct MessageCounter_guess {
    int field0_guess;
    int matched_guess;
    int unmatched_guess;
    void HandleDisconnectWaitPacket_guess(int unused1_guess, short* data_guess, int unused2_guess);
};

struct PacketReceiver_guess {
    char padding_0000_guess[4];
    void* payload_guess; // +0x4
    char padding_0008_guess[4];
    unsigned char ready_guess; // +0xc
    unsigned char pending_guess; // +0xd
    void HandleZoneChangeWaitPacket_guess(int unused1_guess, short* packet_guess, int unused2_guess);
};

// EXTERNAL: TITANIUM 0x00459B94 Handle_OP_ChannelMessage_guess
void __cdecl Handle_OP_ChannelMessage_guess(short* data_guess);

struct TransferRecordA_guess {
    char padding_0000_guess[0x68];
    char attach_guess[0x20];
    int dagTypes_guess[3];
    int nodeTypes_guess[3];
    char padding_00a0_guess[0x224 - 0xA0];
    int field224_guess;
    char padding_0228_guess[0x248 - 0x228];
    ActionPosition_guess offsets_guess[3];
    char padding_026c_guess[0x3A0 - 0x26C];
};

struct DagSource_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess();
    virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot20_guess();
    virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess();
    virtual void Slot27_guess(); virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess(); virtual void Slot44_guess();
    virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess();
    virtual void Slot51_guess(); virtual void Slot52_guess(); virtual void Slot53_guess();
    virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(); virtual void Slot64_guess(); virtual void Slot65_guess();
    virtual void Slot66_guess(); virtual void Slot67_guess(); virtual void Slot68_guess();
    virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess();
    virtual void Slot75_guess(); virtual void Slot76_guess(); virtual void Slot77_guess();
    virtual void Slot78_guess(); virtual void Slot79_guess(); virtual void Slot80_guess();
    virtual void Slot81_guess(); virtual void Slot82_guess(); virtual void Slot83_guess();
    virtual void Slot84_guess(); virtual void Slot85_guess(); virtual void Slot86_guess();
    virtual void Slot87_guess(); virtual void Slot88_guess(); virtual void Slot89_guess();
    virtual int GetDefaultDag_guess(int side_guess);       // +0x168
    virtual int FindDag_guess(const char* name_guess);     // +0x16C
};

struct DagHolder_guess {
    DagSource_guess* source_guess;
    char padding_0004_guess[0x128];
    struct TransferScaleData_guess* scaleData_guess; // +0x12c
    char padding_0130_guess[0xfb0 - 0x130];
    int defaultNode_guess; // +0xfb0
    struct DagActor_guess* node2_guess; // +0xfb4
    int node3_guess; // +0xfb8
    int node4_guess; // +0xfbc
    int node5_guess; // +0xfc0
    int node6_guess; // +0xfc4
    int node7_guess; // +0xfc8
    int node9_guess; // +0xfcc
    int node10_guess; // +0xfd0
    int node11_guess; // +0xfd4
};

struct TransferScaleData_guess {
    char padding_0000_guess[0x38];
    float value38_guess;
};

struct DagPositionObject_guess {
    char padding_0000_guess[0x30];
    ActionPosition_guess position_guess;
};

struct DagActor_guess {
    virtual void RefreshCounts_guess();
    virtual DagPositionObject_guess* GetPosition_guess();
};

struct SpellNode_guess {
    virtual void RefreshCounts_guess();
    virtual void StartFade_guess(int dag_guess);
};

struct DagSlots_guess {
    int dag_guess;
    char padding_0004_guess[0xFD8 - 4];
    SpellNode_guess* nodes_guess[3];
};

struct DagTarget_guess {
    char padding_0000_guess[0x10];
    ActionPosition_guess position_guess;
    char padding_001c_guess[0x48 - 0x1C];
    DagSlots_guess* slots_guess;
};

struct TransferRecordB_guess {
    char padding_0000_guess[0x40];
    int field40_guess;
};

struct TransferObject_guess {
    int field00_guess;
    char padding_0004_guess[0x228];
    TransferRecordA_guess* field22c_guess;
    char padding_0230_guess[4];
    TransferRecordB_guess* field234_guess;
    // EXTERNAL: TITANIUM 0x0044CED9 TransferObject_guess::FUN_0044ced9_guess
    int FUN_0044ced9_guess();
};

struct TransferAction_guess {
    char padding_0000_guess[0x30];
    ActionPosition_guess position_guess;
    char padding_003c_guess[0x120 - 0x3C];
    char name120_guess[0x40]; // 0x120
    char padding_0160_guess[0x1A8 - 0x160];
    DagHolder_guess* dags_guess;
    char padding_01ac_guess[0x244 - 0x1AC];
    unsigned char type_guess;
    char padding_0245_guess[7];
    unsigned char level_guess;
    char padding_024d_guess[0x258 - 0x24d];
    int spawnId_0258_guess;
    // EXTERNAL: TITANIUM 0x0048A6BF TransferAction_guess::GetFloorHeightHere_guess
    float GetFloorHeightHere_guess(float scale_guess);
    // EXTERNAL: TITANIUM 0x00479EE8 TransferAction_guess::PlaySound_guess
    void PlaySound_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004798D7 TransferAction_guess::GetActorTag_guess
    void GetActorTag_guess(char* name_guess);
};

struct TransferPositionSource_guess {
    char padding_0000_guess[0x10];
    ActionPosition_guess position_guess;
    char padding_001c_guess[0x48 - 0x1c];
    int* field48_guess;
};

struct TransferManager_guess {
    virtual void RefreshCounts_guess();
    virtual char CheckActor_guess(int actorId_guess);
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual int Submit_guess(int actorId_guess, unsigned int packedValue_guess,
        int value7_guess, float firstValue_guess, float secondValue_guess,
        ActionPosition_guess* position_guess, int data_guess, int zero_guess,
        int selectedNode_guess, int* output_guess, float scale_guess, int one_guess);
};

struct MovementCoordinates_guess {
    float x_guess;
    float y_guess;
};

struct ActionRecord_guess {
    unsigned short actorId_guess;
    short actionId_guess;
    unsigned int value_guess;
};

struct ActionObjectView_guess {
    char padding_0000_guess[0x186];
    unsigned char field186_guess;
    char padding_0187_guess[0x81];
    const char* field208_guess;
    char padding_020c_guess[8];
    const char* field214_guess;
    const char* field218_guess;
};

struct ActionManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 ActionManager_guess::GetSpell_guess
    ActionObjectView_guess* GetSpell_guess(int id_guess);
};

struct ActionUI_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Apply_guess(int actorId_guess, int first_guess, int second_guess,
        float scale_guess, int enabled_guess);
};

struct ActorActionMethods_guess {
    // EXTERNAL: TITANIUM 0x0047C08E ActorActionMethods_guess::GetAnimation_guess
    ActionUI_guess* GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x0047DDD4 ActorActionMethods_guess::GetAnimationLength_guess
    int GetAnimationLength_guess(unsigned char field_guess);
};

struct DisplayAngle_guess {
    virtual float RefreshCounts_guess(float value_guess);
    virtual float Slot01_guess(float value_guess);
    virtual float Sin_guess(float value_guess);
    virtual float Cos_guess(float value_guess);
};

struct WorldServices_guess {
    char padding_0000_guess[0x148];
    int field148_guess;
    // EXTERNAL: TITANIUM 0x00439F26 WorldServices_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x_guess, float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x0043A292 WorldServices_guess::GetEnvironment_guess
    unsigned char GetEnvironment_guess(float x_guess, float y_guess, float z_guess,
        int flags_guess);
    // EXTERNAL: TITANIUM 0x0043D64B WorldServices_guess::FUN_0043d64b_guess
    float FUN_0043d64b_guess(float x_guess, float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x004395E2 WorldServices_guess::PlaySoundAtLocation_guess
    void PlaySoundAtLocation_guess(float x_guess, float y_guess, float z_guess, int value_guess);
};

struct OptionState_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 OptionState_guess::FUN_0060ca90_guess
    int FUN_0060ca90_guess(int option_guess);
};

struct CharacterFilter_guess {
    // EXTERNAL: TITANIUM 0x004B44C6 CharacterFilter_guess::CanUseAbility_guess
    char CanUseAbility_guess(EQ_PC* charData_guess, int action_guess, int flags_guess);
};

struct ActorControlData_guess {
    char padding_0000_guess[0xD8];
    int fieldd8_guess;
    char padding_00dc_guess[0xECC - 0xDC];
    int fieldecc_guess;
    int fielded0_guess;
    int fielded4_guess;
    char padding_0ed8_guess[0xF98 - 0xED8];
    int fieldf98_guess;
};

struct CharacterFlagView_guess {
    char padding_0000_guess[0x108];
    unsigned char field108_guess;
};

struct EQPCFlagData_guess {
    char padding_0000_guess[0xC38C];
    unsigned char fieldc38c_guess[0x200];
};

struct ActorTarget_guess;
ActorTarget_guess* __cdecl FUN_00401b28_guess(int actorId_guess);

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0040DA3B FUN_0040da3b_guess
int __cdecl FUN_0040da3b_guess(int value_guess);
void __cdecl FUN_00467441_guess(char* output_guess, const char* format_guess,
    const char** value_guess, int width_guess, int flags_guess);

#define g_actionManager_guess EQ_GLOBAL(ActionManager_guess*, 0x00985CC8)
#define g_displayAngle_guess EQ_GLOBAL(DisplayAngle_guess*, 0x0099E374)
#define g_worldServices_guess EQ_GLOBAL(WorldServices_guess*, 0x00905D24)
#define g_optionState_guess EQ_ARRAY(OptionState_guess, 0x009248E0)
#define g_displayFlag_0092446c_guess EQ_GLOBAL(int, 0x0092446C)
#define g_displayToggle_009859ec_guess EQ_GLOBAL(CharacterFilter_guess*, 0x009859EC)
#define g_displaySlots_guess EQ_ARRAY(int, 0x00904390)
#define g_displayPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_displayCharData_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_transferManager_guess EQ_GLOBAL(TransferManager_guess*, 0x0099E36C)

bool __cdecl CanShowSpellEffect_guess(int mode_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess);
int __cdecl SubmitEffectEmitters_guess(unsigned int objectValue_guess, int mode_guess,
    TransferRecordB_guess* records_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess, int value5_guess, int value6_guess,
    int value7_guess, char filter_guess);
SpellNode_guess* __cdecl DoParticleEffect_guess(int mode_guess, TransferRecordA_guess* records_guess,
    int objectValue_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess, int zero_guess, int value5_guess,
    int value6_guess, int value7_guess);
struct SlotName_guess {
    char text_guess[0x20];
};

union SlotFlags_guess {
    int value_guess;
    unsigned char bytes_guess[4];
};

struct SlotVec_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct SlotBody_guess {
    SlotName_guess names_guess[17];
    SlotFlags_guess flags_guess[3];
    float f22c_guess[3];
    SlotVec_guess vec238_guess[1];
    char padding_0244_guess[0x18];
    float f25c_guess[3];
    float f268_guess[3];
    int i274_guess[3];
    float f280_guess[3];
    int i28c_guess[3];
    float f298_guess[1];
    char padding_029c_guess[0xFC];
};

struct SlotRow_guess {
    char padding_0000_guess[8];
    SlotBody_guess body_guess;
};

struct CopiedBlock_guess;
struct DispatchSlots_guess {
    virtual void RefreshCounts_guess();
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
    virtual void Slot21_guess(char* buffer_guess, const char* name_guess,
        CopiedBlock_guess* block_guess, int value_guess, int* result_guess,
        int zero_guess, int zero2_guess);
};

#define g_copiedBlocks_00903ec0_guess EQ_ARRAY(CopiedBlock_guess*, 0x00903EC0)
#define g_zeroFloat_0063f4cc_guess EQ_GLOBAL(float, 0x0063F4CC)
#define g_dispatch_0099e368_guess EQ_GLOBAL(DispatchSlots_guess*, 0x0099E368)

SpellNode_guess* __cdecl MakePCloudInstance_guess(TransferRecordA_guess* records_guess,
    int objectValue_guess, int mode_guess, int index_guess, int nodeType_guess,
    ActionPosition_guess* position_guess, int value7_guess);

#define g_transferFloat_00985810_guess EQ_GLOBAL(float, 0x00985810)
#define g_transferFloat_00985814_guess EQ_GLOBAL(float, 0x00985814)
#define g_transferFlag_0092484c_guess EQ_GLOBAL(int, 0x0092484C)
#define g_transferResult_00905c04_guess EQ_GLOBAL(int, 0x00905C04)

#define g_flag_00905d2d_guess EQ_GLOBAL(unsigned char, 0x00905D2D)
#define g_flag_00905d2c_guess EQ_GLOBAL(unsigned char, 0x00905D2C)
#define g_flag_009239dc_guess EQ_GLOBAL(unsigned char, 0x009239DC)
#define g_value_00923cc4_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_time_00905d30_guess EQ_GLOBAL(unsigned int, 0x00905D30)
#define g_state_009237b0_guess EQ_GLOBAL(int, 0x009237B0)
#define g_value_009238fc_guess EQ_GLOBAL(unsigned int, 0x009238FC)
#define g_value_00923900_guess EQ_GLOBAL(unsigned int, 0x00923900)
#define g_value_00923904_guess EQ_GLOBAL(unsigned int, 0x00923904)
#define g_value_00923908_guess EQ_GLOBAL(unsigned int, 0x00923908)
#define g_value_0092390c_guess EQ_GLOBAL(unsigned int, 0x0092390C)
#define g_value_00923910_guess EQ_GLOBAL(unsigned int, 0x00923910)
#define g_flag_00923842_guess EQ_GLOBAL(unsigned char, 0x00923842)
#define g_flag_009237b7_guess EQ_GLOBAL(unsigned char, 0x009237B7)
#define g_value_0078d850_guess EQ_GLOBAL(int, 0x0078D850)
#define g_sortRecords_00984804_guess EQ_ARRAY(unsigned char, 0x00984804)
#define g_sortFlags_00984842_guess EQ_ARRAY(unsigned char, 0x00984842)
#define g_sortEnd_00984ac2_guess EQ_ARRAY(unsigned char, 0x00984AC2)
#define g_sortRecords_00984a84_guess EQ_ARRAY(unsigned char, 0x00984A84)
#define g_sortFlags_00984a9e_guess EQ_ARRAY(unsigned char, 0x00984A9E)
#define g_sortEnd_00984bde_guess EQ_ARRAY(unsigned char, 0x00984BDE)
#define g_sortCompare_00494d41_guess EQ_ARRAY(unsigned char, 0x00494D41)
#define g_sortCompare_00494d79_guess EQ_ARRAY(unsigned char, 0x00494D79)
#define g_text_0063fe10_guess EQ_ARRAY(char, 0x0063FE10)
#define g_sendDisabled_00923798_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_flag_00923884_guess EQ_GLOBAL(int, 0x00923884)
#define g_flag_0092384d_guess EQ_GLOBAL(unsigned char, 0x0092384D)
#define g_receivedRecordCount_00905cac_guess EQ_GLOBAL(int, 0x00905CAC)
#define g_selector_00924470_guess EQ_GLOBAL(int, 0x00924470)
#define g_value_00923994_guess EQ_GLOBAL(int, 0x00923994)
#define g_value_00905d28_guess EQ_GLOBAL(int, 0x00905D28)
#define g_value_00923998_guess EQ_GLOBAL(unsigned int, 0x00923998)
#define g_value_009239b4_guess EQ_GLOBAL(int, 0x009239B4)
#define g_flag_009239a0_guess EQ_GLOBAL(unsigned char, 0x009239A0)
#define g_value_00923864_guess EQ_GLOBAL(int, 0x00923864)
#define g_value_00923868_guess EQ_GLOBAL(int, 0x00923868)
#define g_value_009248d4_guess EQ_GLOBAL(int, 0x009248D4)
#define g_value_009248d0_guess EQ_GLOBAL(int, 0x009248D0)
#define g_value_00923d5c_guess EQ_GLOBAL(unsigned int, 0x00923D5C)
#define g_value_00923794_guess EQ_GLOBAL(int, 0x00923794)


struct OrientationState_guess {
    char padding_0000_guess[0x28];
    float field28_guess; // 0x28
    float field2c_guess; // 0x2C
    float field30_guess; // 0x30
    float field34_guess; // 0x34
    float field38_guess; // 0x38
    float field3c_guess; // 0x3C
    float field40_guess; // 0x40
    char padding_0044_guess[2]; // 0x44
    unsigned char field46_guess; // 0x46
    void Reset_guess();
};

// EXTERNAL: TITANIUM 0x005742A0 CompareText_guess
int __cdecl CompareText_guess(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x0060EE40 _qsort
void __cdecl _qsort(void* base_guess, unsigned int count_guess, unsigned int size_guess,
    int (__cdecl *compare_guess)(const void*, const void*));

struct SortedRecordsA_guess {
    // EXTERNAL: TITANIUM 0x004AFFC3 SortedRecordsA_guess::SaveSpellLoadouts_guess
    void SaveSpellLoadouts_guess();
    void Sort_guess();
};

struct SortedRecordsB_guess {
    // EXTERNAL: TITANIUM 0x004B010A SortedRecordsB_guess::SaveHotbuttonLoadouts_guess
    void SaveHotbuttonLoadouts_guess();
    void Sort_guess();
};

struct ResetStateValue_guess {
    char padding_0000_guess[0x260];
    int field260_guess;
};

struct ResetState_guess {
    char padding_0000_guess[0x68];
    int field68_guess;
    char padding_006c_guess[0xEC];
    union {
        int field158_guess;
        ResetStateValue_guess* value158_guess;
    };
    int field15c_guess;
    int field160_guess;
};

struct ResetOwner_guess {
    char padding_0000_guess[0x120];
    char name_0120_guess[0x80];
    char padding_01a0_guess[8];
    ResetState_guess* pActorInfo_01a8_guess;
    char padding_01ac_guess[5];
    unsigned char field1b1_guess; // 0x1B1
    char padding_01b2_guess[2];
    unsigned char lfg_01b4_guess;
    char padding_01b5_guess[0x98];
    unsigned char faceHair_024d_guess;
    char padding_024e_guess[3];
    unsigned char standState_0251_guess;
    char padding_0252_guess[2];
    unsigned char equipChest2_0254_guess;
    unsigned char helm_0255_guess;
    unsigned char gm_0256_guess; // 0x256
    char padding_0257_guess[1];
    unsigned short spawnId_0258_guess;
    char padding_025a_guess[0x1A];
    int hpCurrent_0274_guess;
    // EXTERNAL: TITANIUM 0x00479EA3 ResetOwner_guess::IsGroupInvitePending_guess
    char IsGroupInvitePending_guess();
    // EXTERNAL: TITANIUM 0x00479EB0 ResetOwner_guess::SetGroupInvitePending_guess
    void SetGroupInvitePending_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047D776 ResetOwner_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
    // EXTERNAL: TITANIUM 0x00483556 ResetOwner_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047DEC4 ResetOwner_guess::SwapFace_guess
    void SwapFace_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0047A3D0 ResetOwner_guess::GetArmorType_guess
    int GetArmorType_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004845D8 ResetOwner_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int index_guess, int value_guess, int bonus_guess,
        int other_guess, int one_guess);
    // EXTERNAL: TITANIUM 0x0048083A ResetOwner_guess::FUN_0048083a_guess
    void FUN_0048083a_guess(int value_guess, const char* text_guess, int zero_guess);
};

#define g_resetOwner_guess EQ_GLOBAL(ResetOwner_guess*, 0x00905CE4)
#define g_statDisplay_00905ce4_guess EQ_GLOBAL(ResetOwner_guess*, 0x00905CE4)

struct ContextNode_guess {
    char padding_0000_guess[4];
    unsigned int field04_guess;
};

struct ContextObject_guess;
struct ContextEntry_guess;

struct ContextAction_guess {
    // EXTERNAL: TITANIUM 0x0040E934 ContextAction_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int key_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x004106A3 ContextAction_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first_guess, int second_guess, int third_guess,
        int fourth_guess);
    // EXTERNAL: TITANIUM 0x0041B0DE ContextAction_guess::HasSkill_guess
    int HasSkill_guess(int mode_guess);
    // EXTERNAL: TITANIUM 0x00417E07 ContextAction_guess::Cur_HP
    int Cur_HP(int value_guess);
    // EXTERNAL: TITANIUM 0x0041A44A ContextAction_guess::UpdateInvisibility_guess
    void UpdateInvisibility_guess();
    // EXTERNAL: TITANIUM 0x00416963 ContextAction_guess::Max_HP_guess
    unsigned int Max_HP_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417A1D ContextAction_guess::RemoveInvisibility_guess
    void RemoveInvisibility_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004193C5 ContextAction_guess::encum_factor_guess
    float encum_factor_guess();
    // EXTERNAL: TITANIUM 0x00416A40 ContextAction_guess::Max_Endurance
    int Max_Endurance();
    // EXTERNAL: TITANIUM 0x0041C8F4 ContextAction_guess::HasSkillChecked_guess
    int HasSkillChecked_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417CF2 ContextAction_guess::SetValue0_guess
    void SetValue0_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D1C ContextAction_guess::SetValue1_guess
    void SetValue1_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D46 ContextAction_guess::SetValue2_guess
    void SetValue2_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00417D70 ContextAction_guess::SetValue3_guess
    void SetValue3_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00419601 ContextAction_guess::GetClassName_guess
    char* GetClassName_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004195B8 ContextAction_guess::RaceName_guess
    char* RaceName_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0041BF2B ContextAction_guess::BuildLabel_guess
    char* BuildLabel_guess(int cls_guess, int level_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x0043DD14 ContextAction_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(ContextObject_guess* object_guess, int index_guess,
        ContextEntry_guess* entry_guess, int zero_guess);
};

struct ContextObject_guess {
    char padding_0000_guess[8];
    ContextNode_guess* field08_guess;
    char field0c_guess[0x38]; // 0x0C, based at the selector, see field04 - 4
    char field44_guess[0xDC8]; // 0x44, indexed by ContextNode field04
    int field_e0c_guess; // 0xE0C
    char field_e10_guess; // 0xE10
    char padding_0e11_guess[0xC280 - 0xE11];
    ContextAction_guess fieldc280_guess; // 0xC280
    char padding_c281_guess[7];
    struct ContextCallData_guess* pSpawn_c288_guess; // 0xC288
    unsigned char fieldc28c_guess;
    // EXTERNAL: TITANIUM 0x005ED860 ContextObject_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED840 ContextObject_guess::FUN_005ed840_guess
    char FUN_005ed840_guess();
    // EXTERNAL: TITANIUM 0x005ED800 ContextObject_guess::FUN_005ed800_guess
    char FUN_005ed800_guess();
    // EXTERNAL: TITANIUM 0x004BCA2C ContextObject_guess::PrepareForRepop_guess
    void PrepareForRepop_guess(int value_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x004BE271 ContextObject_guess::GetArmorTint_guess
    int GetArmorTint_guess(int value_guess);
};

struct ContextCallData_guess {
    char padding_0000_guess[0x258];
    int field258_guess;
};

struct ContextSelectorStorage_guess {
    char padding_0000_guess[8];
    char selectorBytes_guess[0xC278];
};

#define g_contextObject_guess EQ_GLOBAL(ContextObject_guess*, 0x00905D00)
#define g_contextSelectorStorage_guess EQ_GLOBAL(ContextSelectorStorage_guess*, 0x00905D00)
#define g_contextAction_guess EQ_GLOBAL(ContextAction_guess*, 0x00905D24)

struct LookupManager_guess {
    // EXTERNAL: TITANIUM 0x005F6B90 LookupManager_guess::FUN_005f6b90_guess
    int FUN_005f6b90_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F6890 LookupManager_guess::FUN_005f6890_guess
    void FUN_005f6890_guess(char* output_guess);
    // EXTERNAL: TITANIUM 0x005F6ED0 LookupManager_guess::FUN_005f6ed0_guess
    void FUN_005f6ed0_guess(int value_guess, char* output_guess);
    // EXTERNAL: TITANIUM 0x005F6C80 LookupManager_guess::FUN_005f6c80_guess
    char FUN_005f6c80_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F6D40 LookupManager_guess::FUN_005f6d40_guess
    char FUN_005f6d40_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005FA1C0 LookupManager_guess::FUN_005fa1c0_guess
    void FUN_005fa1c0_guess(int id_guess, char* output_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x005FA1C0 LookupManager_guess::GetZoneName_guess
    void GetZoneName_guess(unsigned short zone_guess, char* output_guess, int flag_guess);
};

#define g_lookupManager_guess EQ_GLOBAL(LookupManager_guess*, 0x00905CC0)

struct TextProcessor_guess {
    // EXTERNAL: TITANIUM 0x0044C1BC TextProcessor_guess::SetCurrentZone_guess
    void SetCurrentZone_guess(char* text_guess);
    // EXTERNAL: TITANIUM 0x0044A537 TextProcessor_guess::WavePlay_guess
    void WavePlay_guess(int id_guess, int zero_guess);
};

#define g_textProcessor_guess EQ_GLOBAL(TextProcessor_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x00464681 EnableAllCommands_guess
void __cdecl EnableAllCommands_guess();
// EXTERNAL: TITANIUM 0x0046468A DisableCommand_guess
void __cdecl DisableCommand_guess(int value_guess);
// EXTERNAL: TITANIUM 0x00464696 DisableAllCommands_guess
void __cdecl DisableAllCommands_guess();
// EXTERNAL: TITANIUM 0x00464675 EnableCommand_guess
void __cdecl EnableCommand_guess(int value_guess);

#define g_text_0063f53f_guess EQ_ARRAY(char, 0x0063F53F)

struct TextReceiver_guess {
    // EXTERNAL: TITANIUM 0x0040E25C TextReceiver_guess::FUN_0040e25c_guess
    void FUN_0040e25c_guess(char* text_guess);
};

struct TailData_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    TailData_guess() {
        field00_guess = 0;
        field04_guess = 0;
        field08_guess = 0;
    }
};

struct InitData_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    TailData_guess tail_guess;
    InitData_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

struct NestedState_guess {
    char padding_0000_guess[0xD0];
    // EXTERNAL: TITANIUM 0x0040C1FA NestedState_guess::NestedState_guess
    NestedState_guess(char* table_guess, int value_guess, char* first_guess,
        char* second_guess, void* owner_guess, bool flag_guess, int zero_guess,
        const char* name_guess, int zero2_guess);
    // EXTERNAL: TITANIUM 0x0040BF0F NestedState_guess::FUN_0040bf0f_guess
    int FUN_0040bf0f_guess();
    // EXTERNAL: TITANIUM 0x0040BF3D NestedState_guess::FUN_0040bf3d_guess
    void FUN_0040bf3d_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040C544 NestedState_guess::GiveTime_guess
    void GiveTime_guess();
    // EXTERNAL: TITANIUM 0x0040C654 NestedState_guess::FUN_0040c654_guess
    void FUN_0040c654_guess();
};

struct TargetOwner_guess {
    char padding_0000_guess[4];
    char field04_guess[8];
    unsigned char field0c_guess;
    char padding_000d_guess[0x7F];
    unsigned int field8c_guess;
    unsigned char field90_guess;
    char padding_0091_guess[0xFF];
    unsigned char field190_guess;
    char padding_0191_guess[0xFF];
    NestedState_guess* field290_guess;
    unsigned char field294_guess;
    char padding_0295_guess[0x31B];
    unsigned char field5b0_guess;
    char padding_05b1_guess[0x7F];
    unsigned int field630_guess;
    unsigned char field634_guess;
    char padding_0635_guess[0xFF];
    unsigned char field734_guess;
    char padding_0735_guess[0xFF];
    struct CleanupPayload_guess* field834_guess;
    __int64 field838_guess;
    char padding_0840_guess[0x30C];
    int fieldb4c_guess;
    void MailServerGiveTime_guess();
    // EXTERNAL: TITANIUM 0x004A2FD7 TargetOwner_guess::ChatServerGiveTime_guess
    void ChatServerGiveTime_guess();
    int ProcessMBox_guess();
    // EXTERNAL: TITANIUM 0x0049A4F9 TargetOwner_guess::MailServerNotificationFlush_guess
    void MailServerNotificationFlush_guess();
    void ChatServerMessage_guess(int value_guess);
    void DisconnectChatServer_guess();
    void DisconnectMailServer_guess();
    void ConnectChatServer_guess(char* name_guess, int value_guess,
        char* first_guess, char* second_guess);
    void ConnectMailServer_guess(char* name_guess, int value_guess,
        char* first_guess, char* second_guess);
};

struct CleanupPayload_guess {
    char padding_0000_guess[0xD8];
    // EXTERNAL: TITANIUM 0x005FFE00 CleanupPayload_guess::FUN_005ffe00_guess
    void FUN_005ffe00_guess();
    // EXTERNAL: TITANIUM 0x005FF520 CleanupPayload_guess::FUN_005ff520_guess
    int FUN_005ff520_guess();
    // EXTERNAL: TITANIUM 0x005FFC60 CleanupPayload_guess::FUN_005ffc60_guess
    void FUN_005ffc60_guess();
    // EXTERNAL: TITANIUM 0x005FF880 CleanupPayload_guess::CleanupPayload_guess
    CleanupPayload_guess(char* table_guess, int value_guess, char* first_guess,
        char* second_guess, void* field04_guess, bool flag_guess, int zero_guess,
        const char* name_guess, int zero2_guess);
};

struct MailSender_guess {
    // EXTERNAL: TITANIUM 0x005FF560 MailSender_guess::Send_guess
    void Send_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x005FFC60 MailSender_guess::Cleanup_guess
    void Cleanup_guess();
};

struct OwnerWithWords_guess;

struct ItemNode_guess {
    OwnerWithWords_guess* item_guess;
};

struct ItemSource_guess {
    // EXTERNAL: TITANIUM 0x005E0F60 ItemSource_guess::FUN_005e0f60_guess
    int FUN_005e0f60_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ItemSource_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005ECB20 ItemSource_guess::FUN_005ecb20_guess
    int FUN_005ecb20_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E3850 ItemSource_guess::FUN_005e3850_guess
    void FUN_005e3850_guess(char* buffer_guess, unsigned int size_guess);
    virtual void RefreshCounts_guess(int value_guess);
};

struct ItemWords_guess {
    unsigned int field00_guess; // 0x00
    unsigned int field04_guess; // 0x04
    unsigned int field08_guess; // 0x08
    CXStr field0c_guess; // 0x0C
    CXStr field10_guess; // 0x10
    CXStr field14_guess; // 0x14
};

// EXTERNAL: TITANIUM 0x004B232E FUN_004b232e_guess
ItemSource_guess* __cdecl FUN_004b232e_guess(const char* name_guess);
// EXTERNAL: TITANIUM 0x0051EA25 BuildItemDescription_guess
CXStr __cdecl BuildItemDescription_guess(ItemSource_guess* source_guess, int zero_guess);

struct BufferHolder_guess {
    void* field00_guess;
    // EXTERNAL: TITANIUM 0x0048F513 BufferHolder_guess::FUN_0048f513_guess
    void FUN_0048f513_guess();
    // EXTERNAL: TITANIUM 0x00435652 BufferHolder_guess::FUN_00435652_guess
    void FUN_00435652_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004466FA BufferHolder_guess::FirstItem_guess
    ItemNode_guess* FirstItem_guess();
    // EXTERNAL: TITANIUM 0x004FF9C9 BufferHolder_guess::BucketForKey_guess
    ItemNode_guess* BucketForKey_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x0042EC1A BufferHolder_guess::NextItem_guess
    ItemNode_guess* NextItem_guess(ItemNode_guess* node_guess);
    int* FindCachedItem_guess(int key_guess);
    int* GetOrCreateCachedItem_guess(int key_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x00447C66 BufferHolder_guess::Insert_guess
    void Insert_guess(ItemWords_guess** item_guess, int key_guess);
    void DestroyTable_guess();
    BufferHolder_guess* InitWith100Buckets_guess();
    void ClearItems_guess();
};

struct CriticalSectionLock_guess {
    // EXTERNAL: TITANIUM 0x005E49A0 CriticalSectionLock_guess::Enter_guess
    void Enter_guess();
    // EXTERNAL: TITANIUM 0x005E49B0 CriticalSectionLock_guess::Leave_guess
    void Leave_guess();
};

struct LockedValues_guess {
    char padding_0000_guess[0x88];
    unsigned int field88_guess;
    char padding_008c_guess[0x170];
    unsigned int field1fc_guess;
    char padding_0200_guess[0x24];
    CriticalSectionLock_guess lock_guess; // 0x224
    unsigned int GetField1fc_guess();
    unsigned int GetField88_guess();
};

struct StringTable_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTable_guess::Lookup_guess
    char* Lookup_guess(int key_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x005DFA60 StringTable_guess::Load_guess
    void Load_guess(char* path_guess, int mode_guess);
};

#define g_stringTable_guess EQ_GLOBAL(StringTable_guess*, 0x00905CB0)

struct CharacterInfo_guess {
    char padding_0000_guess[0x120];
    char name_guess;
    char padding_0121_guess[0x137];
    unsigned int field258_guess;
};

struct BuffNameProvider_guess {
    // EXTERNAL: TITANIUM 0x00572300 BuffNameProvider_guess::FUN_00572300_guess
    const char* FUN_00572300_guess();
};

struct BuffData_guess {
    unsigned int field00_guess;
    char name_guess[0x20];
    unsigned char level_guess;
    char padding_0025_guess[3];
};

struct StatDisplay_guess;

struct SourceText_guess {
    char padding_0000_guess[0x40];
    char field40_guess[0x40];
    unsigned char field80_guess;
};

struct SourceRecord_guess {
    char padding_0000_guess[0x30];
    float x_guess;
    float y_guess;
    float z_guess;
    char padding_003c_guess[0xE4];
    char text_guess[0x124]; // 0x120
    unsigned char flag244_guess; // 0x244
    char padding_0245_guess[0x13];
    unsigned int field258_guess; // 0x258
};

#define g_sourceRecord_00905ce4_guess EQ_GLOBAL(SourceRecord_guess*, 0x00905CE4)

struct ConnectionStatus_guess;

struct LinkCounter_guess {
    // EXTERNAL: TITANIUM 0x004C9C1E LinkCounter_guess::Get_guess
    int Get_guess();
};

struct GlobalState_guess {
    char padding_0000_guess[0x290];
    LinkCounter_guess* field290_guess; // 0x290
    char padding_0294_guess[0x834 - 0x294];
    MailSender_guess* sender_834_guess;
    char padding_0838_guess[0xB50 - 0x838];
    int fieldb50_guess; // 0xB50
    int state_guess;
    void RMouseDown_guess(int x_guess, int y_guess);
    void MouseWheelScrolled_guess(int value_guess);
    void FUN_004a8ba2_guess(int x_guess, int y_guess);
    void DropHeldItemOnGround(int value_guess);
    void RefreshWornAppearance_guess(int value_guess);
    int ClickSwitchAtScreenPos_guess(int x_guess, int y_guess);
    void LMouseUp_guess(int x_guess, int y_guess);
    char padding_0b58_guess[4];
    float fieldb5c_guess; // 0xB5C
    unsigned char fieldb60_guess; // 0xB60
    char padding_0b61_guess[0x1705C - 9];
    char field17bb4_guess[1]; // 0x17BB4
    char padding_17bb5_guess[0x83F];
    int ringIndex_guess; // 0x183F4
    char padding_183f8_guess[1];
    char ringSlots_guess[0x40][0x840]; // 0x183F9
    char padding_393f9_guess[3]; // 0x393F9
    int field393fc_guess; // 0x393FC
    int field39400_guess; // 0x39400
    char padding_39404_guess[0xC]; // 0x39404
    int field39410_guess[10]; // 0x39410
    int field39438_guess[8][9]; // 0x39438
    char padding_39558_guess[0x48]; // 0x39558
    unsigned char field395a0_guess[10]; // 0x395A0
    unsigned char field395aa_guess[10]; // 0x395AA
    int field395b4_guess[8][9]; // 0x395B4
    char padding_396d4_guess[0x48]; // 0x396D4
    int field3971c_guess[10]; // 0x3971C
    unsigned char field39744_guess[10]; // 0x39744
    char padding_3974e_guess[0x3E]; // 0x3974E
    unsigned char field3978c_guess[10]; // 0x3978C
    unsigned char field39796_guess[10]; // 0x39796
    int field397a0_guess[10]; // 0x397A0
    unsigned char field397c8_guess[10]; // 0x397C8
    char padding_397d2_guess[2]; // 0x397D2
    int field397d4_guess[10]; // 0x397D4
    unsigned char field397fc_guess[10]; // 0x397FC
    unsigned char field39806_guess[10]; // 0x39806
    char charNames_guess[10][0x40]; // 0x39810
    unsigned char field39a90_guess[10]; // 0x39A90
    unsigned char field39a9a_guess[10]; // 0x39A9A
    unsigned char field39aa4_guess[10]; // 0x39AA4
    char padding_39aae_guess[0xA]; // 0x39AAE
    unsigned char field39ab8_guess; // 0x39AB8
    unsigned char field39ab9_guess; // 0x39AB9
    char padding_39aba_guess[0x600]; // 0x39ABA
    char logPath_guess[1]; // 0x3A0BA
    // EXTERNAL: TITANIUM 0x004AE5CD GlobalState_guess::WriteClientIniString_guess
    void WriteClientIniString_guess(int zero_guess, const char* section_guess, char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE5E9 GlobalState_guess::FUN_004ae5e9_guess
    void FUN_004ae5e9_guess(const char* section_guess, const char* key_guess,
        const char* default_guess, char* value_guess, unsigned int size_guess);
    // EXTERNAL: TITANIUM 0x004AED0E GlobalState_guess::saveOptions_guess
    void saveOptions_guess();
    // EXTERNAL: TITANIUM 0x004B07D8 GlobalState_guess::FUN_004b07d8_guess
    void FUN_004b07d8_guess();
    void CreateInitialActors_guess();
    void SendLightInfo_guess(int unused_guess, unsigned char flag_guess);
    void SetDefaultClassHotButtons_guess();
    void PrepareLocalPCForRepop_guess();
    char SendLFPCommand_guess(void* data_guess);
    char SendLFGGetMatchesRequest_guess(void* data_guess);
    char SendLFPGetMatchesRequest_guess(void* data_guess);
    void ReleasePendingRequest_guess(char flag_guess);
    int GetRaceDesc(unsigned int value_guess);
    char* GetDeityDesc(int value_guess);
    char* GetInnateDesc_guess(int value_guess);
    int BeingIgnored_guess(unsigned int value_guess);
    int IsFriend_guess(unsigned int value_guess);
    EQPlayer* ClickedPlayer(int first_guess, int second_guess);
    void SetGameState(int value_guess);
    int IsValidName_guess(char* text_guess);
    void SendLFGCommand_guess(void* data_guess);
    void CopyFirstWord_guess(char* source_guess, char* destination_guess);
    char* GetClassDesc(int value_guess);
    char* GetClassThreeLetterCode(int value_guess);
    char* GetItemClassDesc_guess(int value_guess);
    char* GetBodyTypeDesc(int value_guess);
    char* GetLangDesc_guess(int value_guess);
    char* trimName_guess(const char* text_guess);
    void SendSystemInfo_guess();
    void ConfirmLastName_guess(const char* text_guess);
    void ConfirmBuff_guess(CharacterInfo_guess* character_guess,
        BuffNameProvider_guess* buff_guess, int level_guess);
    void ConfirmKill_guess(const char* first_guess, const char* second_guess);
    void SetChatInputFocus_guess(int value_guess);
    void DoLoadScreen_guess(int cleanup_guess);
    void SetPlayerAppearanceFromPInfo_guess(StatDisplay_guess* display_guess, int index_guess,
        char update_guess);
    void ToggleChatInputFocus_guess();
    void doUnInvite_guess(SourceText_guess* source_guess);
    void Invite_guess(char* name_guess);
    void DoPercentConvert_guess(const char* text_guess, int flags_guess);
    void IssuePetCommand_guess(int param_guess, int value_guess);
    void HandleGroupInvite_guess(int action_guess, const char* source_guess);
    void send_social_guess(int emote_guess, const char* name_guess, const char* text_guess);
    void AcceptGroupInvite_guess();
    void ToggleSit_guess();
    void PrepareToCamp_guess();
    void Disband_guess();
    void SendNewText_guess(int mode_guess, int first_guess, int second_guess, int zero_guess);
    void GuildRemove_guess(const char* param_guess);
    void GuildLeader_guess(const char* param_guess);
    void GuildSay_guess(int param_guess);
    void Who_guess(char* args_guess);
    // EXTERNAL: TITANIUM 0x004920C6 GlobalState_guess::GetClassDescStringId_guess
    int GetClassDescStringId_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0049DEB6 GlobalState_guess::RequestTrade_guess
    void RequestTrade_guess(ActorTarget_guess* target_guess);
    void LeftClickedOnPlayer(ActorTarget_guess* target_guess);
    void send_tell_guess(int first_guess, int second_guess);
    void send_petition_guess(bool flag_guess);
    void send_private_guess();
    void CancelSneakHide();
    void DoTellWindow_guess(const char* text_guess, const char* first_guess,
        const char* second_guess, int unused_guess, int color_guess, char log_guess);
    void DspChat_guess(const char* line_guess, int color_guess, bool log_guess);
    void DspChat_guess(const char* line_guess);
    void SendMailServerCommand_guess(const char* text_guess);
    void RunCharacterSelectLoop_guess();
    void DoMainLoop(HWND window_guess);
    void ProcessGame_guess(HWND window_guess, int instance_guess);
    // EXTERNAL: TITANIUM 0x004B0DB5 GlobalState_guess::CreateIniFilenames_guess
    void CreateIniFilenames_guess();
    // EXTERNAL: TITANIUM 0x004B102D GlobalState_guess::FUN_004b102d_guess
    void FUN_004b102d_guess();
    void DoCharacterSelection_guess();
    void StartNetworkGame(int unused1_guess, int unused2_guess, char* name_guess);
    char MoveToZone_guess(int zone_guess, const char* reason_guess, int home_guess,
        int mode_guess, float y_guess, float x_guess, float z_guess, int heading_guess);
    int IsZoneAvailable_guess(int zone_guess, float y_guess, float x_guess, float z_guess,
        int mode_guess);
    void SavePCOnZone_guess(int home_guess);
void SavePC_guess(int first_guess, int second_guess, unsigned char flags_guess);
    // EXTERNAL: TITANIUM 0x00493978 GlobalState_guess::SetupCharSelectCamera_guess
    void SetupCharSelectCamera_guess();
    char IsInCharCreateTrigger_guess();
    void SetGameStateInline_guess(int value_guess) {
        state_guess = value_guess;
        switch (state_guess) {
        case 5:
            EnableAllCommands_guess();
            DisableCommand_guess(0x105);
            DisableCommand_guess(0x106);
            DisableCommand_guess(0x107);
            DisableCommand_guess(0x108);
            DisableCommand_guess(0x10a);
            DisableCommand_guess(0x109);
            break;
        case 2:
            DisableAllCommands_guess();
            EnableCommand_guess(0x10a);
            EnableCommand_guess(0x109);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        case 1:
            DisableAllCommands_guess();
            EnableCommand_guess(0x105);
            EnableCommand_guess(0x106);
            EnableCommand_guess(0x107);
            EnableCommand_guess(0x108);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        }
    }
    void ProcessControls_guess();
    // EXTERNAL: TITANIUM 0x004929DD GlobalState_guess::ApplyMouseLook_guess
    void ApplyMouseLook_guess(int active_guess);
    // EXTERNAL: TITANIUM 0x004AE865 GlobalState_guess::FUN_004ae865_guess
    void FUN_004ae865_guess(const char* section_guess, const char* key_guess,
        const char* default_guess, char* value_guess, unsigned int size_guess, int flag_guess);
    int GetCurrentLanguage_guess();
    void Emote_guess();
    void send_gsay_guess();
    void send_shout_guess();
    void send_auction_guess();
    void send_ooc_guess();
    void send_broadcast_guess();
    void send_chat_guess(int value_guess);
    void doInspect(SourceRecord_guess* source_guess);
    void InterpretCmd(void* target_guess, const char* text_guess);
    void StartCasting_guess(ActionRecord_guess* action_guess);
    // EXTERNAL: TITANIUM 0x00492F52 GlobalState_guess::ClearChatText_guess
    void ClearChatText_guess();
    void WhatTimeIsIt_guess();
    void ApplyPoison_guess(int value_guess);
    void ChatServerConnectionLost_guess(ConnectionStatus_guess* status_guess);
    int DoLogin_guess(HWND hwnd_guess, int value_guess);
    void ResetGameGlobals_guess();
    void SetDefaultVisionColors_guess();
    // EXTERNAL: TITANIUM 0x00499824 GlobalState_guess::LootCorpse_guess
    int LootCorpse_guess(struct Actor7356_guess* actor_guess, int zero_guess);
    void RightClickedOnPlayer(struct Actor7356_guess* actor_guess);
    // EXTERNAL: TITANIUM 0x004AE64C GlobalState_guess::ReadClientIniInt_guess
    int ReadClientIniInt_guess(const char* section_guess, const char* key_guess,
        int fallback_guess);
    // EXTERNAL: TITANIUM 0x004AE514 GlobalState_guess::FUN_004ae514_guess
    void FUN_004ae514_guess(int value_guess, const char* section_guess,
        const char* key_guess);
};

#define g_globalState_guess EQ_GLOBAL(GlobalState_guess*, 0x00988DF0)

#define g_keyMapNames_guess EQ_ARRAY(const char*, 0x0078D868)
#define g_keyMapSuffix_guess EQ_ARRAY(char, 0x0064915C)

struct KeyCharEntry_guess {
    char text_guess; // 0x0
    char padding_0001_guess[3];
    int value_guess; // 0x4
};

struct KeyNameEntry_guess {
    int value_guess; // 0x0
    const char* text_guess; // 0x4
};

#define g_keyCharTable_guess EQ_ARRAY(KeyCharEntry_guess, 0x0078DC48)
#define g_keyNameTable_guess EQ_ARRAY(KeyNameEntry_guess, 0x0078DDC0)

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, unsigned int id_guess,
    const char* text_guess, const char* zero1_guess, int zero2_guess, int zero3_guess,
    int zero4_guess, int zero5_guess, int zero6_guess, int zero7_guess,
    int zero8_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060E985 FUN_0060e985_guess
void* __cdecl FUN_0060e985_guess(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* destination_guess, const char* format_guess, ...);

struct DeliveryManager_guess {
    // EXTERNAL: TITANIUM 0x00548460 DeliveryManager_guess::Activate
    void Activate(unsigned int context_guess, unsigned int type_guess,
        char* text_guess, unsigned int size_guess, unsigned int timeout_guess,
        void* data_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x00548256 DeliveryManager_guess::ExpireAll_guess
    void ExpireAll_guess();
};

#define g_deliveryManager_guess EQ_GLOBAL(DeliveryManager_guess*, 0x00991E44)

struct ModeActions_guess {
    // EXTERNAL: TITANIUM 0x0059CDD0 ModeActions_guess::FUN_0059cdd0_guess
    void FUN_0059cdd0_guess();
    // EXTERNAL: TITANIUM 0x0059EDF0 ModeActions_guess::SetFocus
    void SetFocus();
};

struct ModeRoot_guess {
    char padding_0000_guess[0x160];
    ModeActions_guess* field160_guess;
};

struct ModeProvider_guess {
    // EXTERNAL: TITANIUM 0x004F288C ModeProvider_guess::GetActiveChatWindow_guess
    ModeRoot_guess* GetActiveChatWindow_guess();
};

#define g_modeProvider_guess EQ_GLOBAL(ModeProvider_guess*, 0x009917E4)
#define g_modeFlagA_guess EQ_GLOBAL(int, 0x00925528)
#define g_modeFlagB_guess EQ_GLOBAL(int, 0x0092552C)
#define g_modeFlagC_guess EQ_GLOBAL(int, 0x00925534)
#define g_modeFlagD_guess EQ_GLOBAL(int, 0x00925530)
#define g_modeFlagE_guess EQ_GLOBAL(unsigned char, 0x00923843)

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int zero_guess, int one_guess, unsigned int flags_guess);

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x00467AD1 AddNameToTellList_guess
void __cdecl AddNameToTellList_guess(char* text_guess);

// EXTERNAL: TITANIUM 0x00478F73 GarbleText_guess
void __cdecl GarbleText_guess(const char* source_guess, char* destination_guess,
    int size_guess);
// EXTERNAL: TITANIUM 0x0060E460 FUN_0060e460_guess
void __cdecl FUN_0060e460_guess(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x00576ED0 FUN_00576ed0_guess
void __cdecl FUN_00576ed0_guess(const char* path_guess);
// EXTERNAL: TITANIUM 0x0060ECBC _time32_guess
int __cdecl _time32_guess(int* time_guess);
// EXTERNAL: TITANIUM 0x0060ECA3 _ctime_guess
char* __cdecl _ctime_guess(const int* time_guess);

// EXTERNAL: TITANIUM 0x0040552D GetLanguageCodePage_guess
int __cdecl GetLanguageCodePage_guess(int value_guess);
// EXTERNAL: TITANIUM 0x005749F0 FUN_005749f0_guess
void __cdecl FUN_005749f0_guess(int value_guess, const char* buffer_guess,
    char* output_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x004798B7 FindSpawnByActor_guess
EQPlayer* __cdecl FindSpawnByActor_guess(int value_guess);

struct PlayerMotion_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned int field0c_guess;
    unsigned int field10_guess;
    unsigned int field14_guess;
    unsigned int field18_guess;
    unsigned int field1c_guess;
    unsigned int field20_guess;
    unsigned int field24_guess;
    unsigned int field28_guess;
    unsigned int field2c_guess;
    unsigned int field30_guess;
    unsigned int field34_guess;
    PlayerMotion_guess(const PlayerMotion_guess& source_guess);
};

struct LinkedNode_guess {
    LinkedNode_guess* field00_guess;
    LinkedNode_guess* field04_guess;
    LinkedNode_guess* field08_guess;
    void Unlink_guess();
};

struct FlagSetter_guess {
    void LMouseDown_guess(unsigned int first_guess, unsigned int second_guess);
};

#include "titanium/layouts/shared_classes.h"
#include "titanium/wnd/CAdventureLeaderboardWnd.h"
#include "titanium/wnd/CAdventureStatsWnd.h"
#include "titanium/wnd/CAvaZoneWnd.h"
#include "titanium/wnd/CBarterWnd.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CMerchantWnd.h"
#include "titanium/wnd/CPointMerchantWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CBarterMerchantWnd.h"
#include "titanium/wnd/CBazaarWnd.h"
#include "titanium/wnd/CCharacterCreation.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CCursorAttachment.h"
#include "titanium/wnd/CFacePick.h"
#include "titanium/wnd/CGroupSearchWnd.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CLootWnd.h"
#include "titanium/wnd/CPetInfoWnd.h"
#include "titanium/wnd/CSpellBookWnd.h"
#include "titanium/wnd/CTaskWnd.h"
#include "titanium/wnd/CTrackingWnd.h"
#include "titanium/wnd/CTradeWnd.h"
#include "titanium/wnd/CTrainWnd.h"
#include "titanium/wnd/CascadeMenuList.h"

// EXTERNAL: TITANIUM 0x004B6EF8 FUN_004b6ef8_guess
void __cdecl FUN_004b6ef8_guess();

struct ToggleState_guess {
    char padding_0000_guess[0x18];
    unsigned short field18_guess; // 0x18
    char padding_001a_guess[2];
    unsigned char field1c_guess;
    void SetPositionHistoryRecording_guess(char value_guess);
    // EXTERNAL: TITANIUM 0x004B70DB ToggleState_guess::FUN_004b70db_guess
    void FUN_004b70db_guess(void* position_guess, int mode_guess);
};

struct DisconnectWaitState_guess;

struct ConnectionStatus_guess {
    // EXTERNAL: TITANIUM 0x0040BE64 ConnectionStatus_guess::BeginWait_guess
    void BeginWait_guess(DisconnectWaitState_guess* state_guess);
    // EXTERNAL: TITANIUM 0x005E6EC0 ConnectionStatus_guess::Send_guess
    char Send_guess(int flags_guess, int result_guess, int totalSize_guess);
    // EXTERNAL: TITANIUM 0x00424BC3 ConnectionStatus_guess::GetStatus_guess
    int GetStatus_guess();
    // EXTERNAL: TITANIUM 0x00424BA0 ConnectionStatus_guess::ConvertStatus_guess
    int ConvertStatus_guess();
    // EXTERNAL: TITANIUM 0x0040BE8B ConnectionStatus_guess::FormatStatus_guess
    int FormatStatus_guess();
    // EXTERNAL: TITANIUM 0x005E5BD0 ConnectionStatus_guess::FUN_005e5bd0_guess
    int FUN_005e5bd0_guess(char* buffer_guess, unsigned int size_guess);
};

// EXTERNAL: TITANIUM 0x006007F0 FUN_006007f0_guess
int __cdecl FUN_006007f0_guess(int message_guess, int size_guess, void* data_guess);

struct ConnectionManager_guess {
    char padding_0000_guess[0x48];
    void* field48_guess;
    unsigned int field4c_guess;
    unsigned int field50_guess;
    unsigned int field54_guess;
    // EXTERNAL: TITANIUM 0x0042507B ConnectionManager_guess::ConnectionManager_guess
    ConnectionManager_guess();
    // EXTERNAL: TITANIUM 0x0042500C ConnectionManager_guess::Teardown_guess
    void Teardown_guess(ConnectionStatus_guess** connection_guess);
};

struct PumpHandler_guess {
    // EXTERNAL: TITANIUM 0x005EB5B0 PumpHandler_guess::Wait_guess
    void Wait_guess(int value_guess);
};

struct ConnectionPumpState_guess {
    char padding_0000_guess[0x4c];
    PumpHandler_guess* field4c_guess;
};

// EXTERNAL: TITANIUM 0x00649508 ??_7DisconnectWaitState_guess@@6B@
struct DisconnectWaitState_guess {
    int field04_guess;
    int field08_guess;
    DisconnectWaitState_guess() : field04_guess(0), field08_guess(0) {}
    virtual void RefreshCounts_guess();
};

// EXTERNAL: TITANIUM 0x00600E40 FUN_00600e40_guess
void __cdecl FUN_00600e40_guess(int value_guess);

#define g_connectionManager_guess EQ_GLOBAL(ConnectionManager_guess*, 0x0079DBD8)
#define g_connection_00905ca0_guess EQ_GLOBAL(ConnectionStatus_guess*, 0x00905CA0)

// EXTERNAL: TITANIUM 0x005E5AF0 FUN_005e5af0_guess
int __cdecl FUN_005e5af0_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format_guess, ...);

struct ReceivedRecord_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned int field0c_guess;
    unsigned int field10_guess;
    unsigned int field14_guess;
};

#define g_receivedRecords_009043e8_guess EQ_ARRAY(unsigned int, 0x009043E8)


#define g_clockData_guess EQ_GLOBAL(ClockData_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00649458 ??_7TimedEntry_guess@@6B@
struct TimedEntryCallback_guess {
    // EXTERNAL: TITANIUM 0x00424BE6 TimedEntryCallback_guess::FUN_00424be6_guess
    void FUN_00424be6_guess(int value_guess);
};

struct TimedEntry_guess {
    void* field04_guess;
    char padding_0008_guess[4];
    unsigned char active_guess;
    unsigned char expired_guess;
    unsigned short padding_000e_guess;
    unsigned int deadline_guess;
    virtual void RefreshCounts_guess();
    TimedEntry_guess(void* field04_guess, unsigned int duration_guess);
    int IsActive_guess();
    void FinishWait_guess(TimedEntryCallback_guess* callback_guess);
};

struct ResetWord_guess {
    unsigned int field00_guess;
    ResetWord_guess() : field00_guess(0) {}
    // EXTERNAL: TITANIUM 0x004482FB ResetWord_guess::Reset_guess
    void Reset_guess();
    ~ResetWord_guess() { Reset_guess(); }
};

struct MiddleState_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned int field0c_guess;
    // EXTERNAL: TITANIUM 0x0042F092 ??0MiddleState_guess@@QAE@H@Z
    MiddleState_guess(int value_guess);
    // The external release routine is nonthrowing.
    // EXTERNAL: TITANIUM 0x004C9745 ??1MiddleState_guess@@QAE@XZ
    // fake match: throw() lever
    ~MiddleState_guess() throw();
};

// The 0x14-byte db string manager: a MiddleState_guess base plus an int at +0x10.
struct DbStringManager_guess : MiddleState_guess {
    int field10_guess;
    DbStringManager_guess(int value_guess) : MiddleState_guess(value_guess) {
        field10_guess = 0;
    }
    // EXTERNAL: TITANIUM 0x004355F7 DbStringManager_guess::FUN_004355f7_guess
    int FUN_004355f7_guess(unsigned int value_guess, unsigned int type_guess, char* output_guess);
    // EXTERNAL: TITANIUM 0x004356CC DbStringManager_guess::FUN_004356cc_guess
    void FUN_004356cc_guess(char* path_guess);
    // EXTERNAL: TITANIUM 0x00435954 DbStringManager_guess::~DbStringManager_guess
    ~DbStringManager_guess();
};

#define g_dbStringManager_guess EQ_GLOBAL(DbStringManager_guess*, 0x00850398)

struct DisplayState_guess {
    unsigned int field00_guess;
    char padding_0004_guess[0x1e];
    unsigned char field22_guess;
    unsigned char field23_guess;
    char padding_0024_guess[0x28];
    unsigned char field4c_guess;
    char padding_004d_guess[9];
    unsigned char field56_guess;
    char padding_0057_guess[4];
    unsigned char field5b_guess;
    char padding_005c_guess[0x65];
    unsigned char fieldc1_guess;
    char padding_00c2_guess[0x366];
    ResetWord_guess field428_guess;
    MiddleState_guess field42c_guess;
    ResetWord_guess field43c_guess;
    // EXTERNAL: TITANIUM 0x0048FBC8 DisplayState_guess::GetSwitchDamage_guess
    int GetSwitchDamage_guess();
    // EXTERNAL: TITANIUM 0x00490500 DisplayState_guess::Resolve_guess
    int Resolve_guess(int candidate_guess);
    // EXTERNAL: TITANIUM 0x004906C5 DisplayState_guess::UseSwitch_guess
    void UseSwitch_guess(int first_guess, int second_guess,
        int third_guess, int fourth_guess);
    // EXTERNAL: TITANIUM 0x004909CE DisplayState_guess::FUN_004909ce_guess
    void FUN_004909ce_guess();
    // EXTERNAL: TITANIUM 0x00490A01 DisplayState_guess::FreeBucketEntries_guess
    void FreeBucketEntries_guess();
    void ToggleDoorState_guess();
    DisplayState_guess();
    ~DisplayState_guess();
};

// Moves a door's animation state toward its wanted state (0 -> 3, 1 -> 2, probably closing/opening);
// door types '(' and '-' are clicked through instead (0x4906C5 with key 0xFF).
// FUNCTION: TITANIUM 0x00490B20
void DisplayState_guess::ToggleDoorState_guess() {
    field56_guess = 1 - field5b_guess;
    if (fieldc1_guess != 0) {
        field23_guess = 1;
        return;
    }
    unsigned char state_guess = field4c_guess;
    if (field23_guess != state_guess) {
        if (field22_guess != '(' && field22_guess != '-') {
            if (state_guess == 0) {
                field23_guess = 3;
                return;
            }
            if (state_guess == 1) {
                field23_guess = 2;
                return;
            }
            field23_guess = state_guess;
            return;
        }
        UseSwitch_guess(0, 0, 0xff, 0);
        field56_guess = 1 - field5b_guess;
    }
}

// Door list constructor: no doors, the two state blocks reset and the door table at +0x42C created with
// 0x32 buckets.
// FUNCTION: TITANIUM 0x00490B82
DisplayState_guess::DisplayState_guess() : field42c_guess(0x32) {
    field00_guess = 0;
    field428_guess.Reset_guess();
    field43c_guess.Reset_guess();
}

// Door list destructor: frees every door (0x004909CE), then the door table (0x00490A01).
// FUNCTION: TITANIUM 0x00490BDE
DisplayState_guess::~DisplayState_guess() {
    FUN_004909ce_guess();
    FreeBucketEntries_guess();
}

// Empty item-cache entry for GetOrCreateCachedItem: no key (-1).
// FUNCTION: TITANIUM 0x00490C38
InitData_guess::InitData_guess() {
    field00_guess = 0xffffffff;
    field04_guess = 500;
    field08_guess = 0;
}

struct OwnedWord_guess {
    void* field00_guess;
    // EXTERNAL: TITANIUM 0x004482FB OwnedWord_guess::~OwnedWord_guess
    ~OwnedWord_guess();
};

struct OwnerWithWords_guess {
    char padding_0000_guess[0x0C];
    OwnedWord_guess field0c_guess;
    OwnedWord_guess field10_guess;
    OwnedWord_guess field14_guess;
    ~OwnerWithWords_guess();
};

// Empty destructor; the three owned CXStr members (+0xC, +0x10, +0x14) release themselves.
// FUNCTION: TITANIUM 0x00490C53
OwnerWithWords_guess::~OwnerWithWords_guess() {
}

struct RehashNode_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    RehashNode_guess* field08_guess;
};

struct BucketMap_guess {
    RehashNode_guess** buckets_guess;
    int bucketCount_guess;
    int threshold_guess;
    int occupiedBuckets_guess;
    void Rehash_guess(int requested_guess);
};

// EXTERNAL: TITANIUM 0x0042429E NextPrimeCandidate_guess
int __cdecl NextPrimeCandidate_guess(int requested_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);

// Re-buckets every node into a new table of 0x0042429E(`requested_guess`) buckets (an odd count; prime
// squares can pass), using the hash kept in node +4, and recounts the used buckets. With a zero count at +8
// only the table is replaced.
// FUNCTION: TITANIUM 0x00490C98
void BucketMap_guess::Rehash_guess(int requested_guess) {
    RehashNode_guess** oldBuckets_guess = buckets_guess;
    int oldCount_guess = bucketCount_guess;
    bucketCount_guess = NextPrimeCandidate_guess(requested_guess);
    buckets_guess = (RehashNode_guess**)operator new(bucketCount_guess << 2);
    memset(buckets_guess, 0, bucketCount_guess << 2);
    occupiedBuckets_guess = 0;
    if (threshold_guess > 0) {
        requested_guess = 0;
        if (oldCount_guess > 0) {
            do {
                RehashNode_guess* node_guess = oldBuckets_guess[requested_guess];
                while (node_guess != 0) {
                    RehashNode_guess* current_guess = node_guess;
                    unsigned int bucket_guess = current_guess->field04_guess;
                    RehashNode_guess** link_guess = &node_guess->field08_guess;
                    node_guess = *link_guess;
                    bucket_guess %= bucketCount_guess;
                    RehashNode_guess* head_guess = buckets_guess[bucket_guess];
                    if (head_guess == 0) {
                        // ANDing the link with the null head is how the original clears it (match shape).
                        *reinterpret_cast<unsigned int*>(link_guess) &=
                            reinterpret_cast<unsigned int>(head_guess);
                        buckets_guess[bucket_guess] = current_guess;
                        ++occupiedBuckets_guess;
                    } else {
                        *link_guess = head_guess;
                        buckets_guess[bucket_guess] = current_guess;
                    }
                }
                ++requested_guess;
            } while (requested_guess < oldCount_guess);
        }
    }
    free(oldBuckets_guess);
}

// Cached item whose key (first dword) is `key`, searched along its hash chain; 0 when not cached.
// FUNCTION: TITANIUM 0x00490D40
int* BufferHolder_guess::FindCachedItem_guess(int key_guess) {
    for (ItemNode_guess* node_guess = BucketForKey_guess(key_guess);
        node_guess != 0 && node_guess->item_guess != 0;
        node_guess = NextItem_guess(node_guess)) {
        if (*reinterpret_cast<int*>(node_guess->item_guess) == key_guess) {
            return reinterpret_cast<int*>(node_guess->item_guess);
        }
    }
    return 0;
}

// Returns the cached entry for an item key, building it from the item text on a miss:
// icon, link hash and two item properties.
// FUNCTION: TITANIUM 0x00490D71
// @early-stop: budget, structural ndiff=50
int* BufferHolder_guess::GetOrCreateCachedItem_guess(int key_guess, const char* name_guess) {
    ItemSource_guess* source_guess;
    char buffer_guess[0x400];
    if (name_guess != 0) {
        int* found_guess = FindCachedItem_guess(key_guess);
        if (found_guess != 0) {
            return found_guess;
        }
        source_guess = FUN_004b232e_guess(name_guess);
        if (source_guess != 0) {
            ItemWords_guess* item_guess = reinterpret_cast<ItemWords_guess*>(new InitData_guess());
            int* result_guess = reinterpret_cast<int*>(item_guess);
            item_guess->field00_guess = key_guess;
            item_guess->field0c_guess = BuildItemDescription_guess(source_guess, 0);
            // Item icon ids start at 500; the entry keeps the 0-based art index.
            item_guess->field04_guess = source_guess->FUN_005e0f60_guess() - 500;
            item_guess->field14_guess = source_guess->FUN_005e0ec0_guess();
            item_guess->field08_guess = source_guess->FUN_005ecb20_guess(1);
            source_guess->FUN_005e3850_guess(buffer_guess, 0x400);
            item_guess->field10_guess = buffer_guess;
            source_guess->RefreshCounts_guess(1);
            Insert_guess(&item_guess, key_guess);
            return result_guess;
        }
    }
    return 0;
}

// Frees every node of the hash table (0x0048F513), then its bucket array.
// FUNCTION: TITANIUM 0x00490E9C
void BufferHolder_guess::DestroyTable_guess() {
    FUN_0048f513_guess();
    free(field00_guess);
}

// Static initializer: gives the item cache 100 buckets.
// FUNCTION: TITANIUM 0x00490EAE
BufferHolder_guess* BufferHolder_guess::InitWith100Buckets_guess() {
    FUN_00435652_guess(100);
    return this;
}

// Destroys and frees every item held in the chain list, then releases the chains themselves (0x0048F513).
// FUNCTION: TITANIUM 0x00490EBC
void BufferHolder_guess::ClearItems_guess() {
    ItemNode_guess* node_guess = FirstItem_guess();
    while (node_guess != 0) {
        OwnerWithWords_guess* item_guess = node_guess->item_guess;
        node_guess = NextItem_guess(node_guess);
        if (item_guess != 0) {
            item_guess->~OwnerWithWords_guess();
            free(item_guess);
        }
    }
    FUN_0048f513_guess();
}

// EXTERNAL: TITANIUM 0x00574510 FUN_00574510_guess
int __cdecl FUN_00574510_guess(const char* source_guess, unsigned int* value_guess);
// EXTERNAL: TITANIUM 0x005745F0 FUN_005745f0_guess
int __cdecl FUN_005745f0_guess(unsigned int value_guess, char* output_guess,
    unsigned int size_guess);
// EXTERNAL: TITANIUM 0x00574790 FUN_00574790_guess
void __cdecl FUN_00574790_guess(const char* source_guess, char* destination_guess,
    int size_guess);

extern "C" int __cdecl _iswdigit(unsigned int value_guess);

// UTF-8 aware: upper-cases the first character and copies the rest, 64 bytes at most whatever `size`
// says. Returns the position after the first character, not the buffer start.
// FUNCTION: TITANIUM 0x00490F27
// @early-stop: budget, structural ndiff=6
char* __cdecl CapitalizeFirstLetter_guess(const char* source_guess, char* output_guess,
    unsigned int size_guess) {
    unsigned int capacity_guess = size_guess;
    int offset_guess;
    memset(output_guess, 0, capacity_guess);
    offset_guess = FUN_00574510_guess(source_guess, &size_guess);
    size_guess = towupper(size_guess);
    int written_guess = FUN_005745f0_guess(size_guess, output_guess, capacity_guess - 1);
    if (written_guess == 0) {
        *output_guess = 0;
    } else {
        char buffer_guess[64] = {0};
        output_guess += written_guess;
        FUN_00574790_guess(source_guess + offset_guess, buffer_guess, 0x40 - written_guess);
        FUN_0060e460_guess(output_guess, buffer_guess);
    }
    return output_guess;
}

// Reads the dword at +0x1FC under the object's lock.
// FUNCTION: TITANIUM 0x00490FBC
unsigned int LockedValues_guess::GetField1fc_guess() {
    lock_guess.Enter_guess();
    unsigned int value_guess = field1fc_guess;
    lock_guess.Leave_guess();
    return value_guess;
}

// Reads the dword at +0x88 under the object's lock; the login code polls it while waiting for the
// connection.
// FUNCTION: TITANIUM 0x00490FDF
unsigned int LockedValues_guess::GetField88_guess() {
    lock_guess.Enter_guess();
    unsigned int value_guess = field88_guess;
    lock_guess.Leave_guess();
    return value_guess;
}

// Creates the network connection manager (0x0079DBD8).
// FUNCTION: TITANIUM 0x0049101E
void __cdecl CreateConnectionManager_guess() {
    g_connectionManager_guess = new ConnectionManager_guess();
}

// Resets the object: +0x40 = 90.0, the six floats +0x28..+0x3C zeroed and the byte at +0x46 cleared.
// FUNCTION: TITANIUM 0x00491055
void OrientationState_guess::Reset_guess() {
    field40_guess = 90.0f;
    field28_guess = 0.0f;
    field46_guess = 0;
    field2c_guess = 0.0f;
    field30_guess = 0.0f;
    field34_guess = 0.0f;
    field38_guess = 0.0f;
    field3c_guess = 0.0f;
}

// EXTERNAL: TITANIUM 0x00649080 ??_7ObjectDtor_guess@@6B@
struct ObjectDtor_guess {
    virtual ~ObjectDtor_guess() {}
    ObjectDtor_guess* DeletingDestructor_guess(unsigned char flags_guess);
};

// Scalar deleting destructor (vtable 0x649080).
// FUNCTION: TITANIUM 0x004910DD
ObjectDtor_guess* ObjectDtor_guess::DeletingDestructor_guess(unsigned char flags_guess) {
    this->ObjectDtor_guess::~ObjectDtor_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Turns position-history recording on or off (+0x1C); switching it on first drops every pending entry
// (0x004B6EF8).
// FUNCTION: TITANIUM 0x004910FA
void ToggleState_guess::SetPositionHistoryRecording_guess(char value_guess) {
    if (field1c_guess == 0 && value_guess != 0) {
        FUN_004b6ef8_guess();
    }
    field1c_guess = value_guess;
}

// Calls `callback` with the address of a zero byte.
// FUNCTION: TITANIUM 0x0049128A
void __cdecl FUN_0049128a_guess(void (__cdecl *callback_guess)(char* value_guess)) {
    char value_guess = 0;
    callback_guess(&value_guess);
}

// EQ's SendMessage (send_message in the earlier sibling decomp): sends opcode `message` plus `size` payload bytes;
// `wait` sets send flag 4. On failure it logs the connection status and tears the connection down. Returns 1 when sent.
// FUNCTION: TITANIUM 0x004912B1
char __cdecl FUN_004912b1_guess(ConnectionStatus_guess** connection_guess, int message_guess,
    void* data_guess, int size_guess, char wait_guess) {
    if (connection_guess == 0 || *connection_guess == 0) {
        if (g_sendDisabled_00923798_guess == 0) {
            FUN_00574110_guess("Attempt to send message %d on a void connection.", message_guess);
        }
    } else {
        if ((*connection_guess)->Send_guess(wait_guess != 0 ? 4 : 0,
            // The 2 extra bytes are the opcode in front of the payload.
            FUN_006007f0_guess(message_guess, size_guess, data_guess), size_guess + 2) == 0) {
            FUN_00574110_guess("Failed to send message %d: connection lost.", message_guess);
            if (*connection_guess != 0) {
                FUN_00574110_guess("Connection status %d/%x [%s,%s] before teardown.",
                    (*connection_guess)->FormatStatus_guess(),
                    reinterpret_cast<LockedValues_guess*>(*connection_guess)->GetField88_guess(),
                    FUN_005e5af0_guess((*connection_guess)->ConvertStatus_guess()),
                    FUN_005e5af0_guess((*connection_guess)->GetStatus_guess()));
            }
            g_connectionManager_guess->Teardown_guess(connection_guess);
        } else {
            return 1;
        }
    }
    return 0;
}

// Keeps up to 127 zone points (OP_SendZonepoints 0x3EBA); a count of 0 or >= 128 is ignored.
// FUNCTION: TITANIUM 0x00491373
void __cdecl Handle_OP_SendZonepoints_guess(int unused1_guess, int unused2_guess,
    int* records_guess) {
    int count_guess = *records_guess;
    if (count_guess <= 0) {
        return;
    }
    if (count_guess >= 0x80) {
        return;
    }
    g_receivedRecordCount_00905cac_guess = count_guess;
    for (int i = 0; i < count_guess; ++i) {
        reinterpret_cast<ReceivedRecord_guess*>(g_receivedRecords_009043e8_guess)[i] =
            reinterpret_cast<ReceivedRecord_guess*>(records_guess + 1)[i];
    }
}

struct LookupRecord_guess {
    int key_guess;
    float f04_guess;
    float f08_guess;
    float f0c_guess;
    float f10_guess;
    int f14_guess;
};

#define g_lookupRecords_009043e8_guess EQ_ARRAY(LookupRecord_guess, 0x009043E8)

// Finds zone point `key` and returns its y/x/z, heading and target zone, or zeros and -1.
// CDisplay::DoTeleport (0x489CC2) uses it.
// FUNCTION: TITANIUM 0x004913AE
int __cdecl GetTPCoordsFromIndex_guess(int key_guess, float* a_guess, float* b_guess,
    float* c_guess, float* d_guess, int* e_guess) {
    int count_guess = g_receivedRecordCount_00905cac_guess;
    for (int i = 0; i < count_guess; ++i) {
        if (key_guess == g_lookupRecords_009043e8_guess[i].key_guess) {
            *a_guess = g_lookupRecords_009043e8_guess[i].f04_guess;
            *b_guess = g_lookupRecords_009043e8_guess[i].f08_guess;
            *c_guess = g_lookupRecords_009043e8_guess[i].f0c_guess;
            *d_guess = g_lookupRecords_009043e8_guess[i].f10_guess;
            *e_guess = g_lookupRecords_009043e8_guess[i].f14_guess;
            return i;
        }
    }
    *a_guess = 0.0f;
    *d_guess = 0.0f;
    *c_guess = 0.0f;
    *b_guess = 0.0f;
    *e_guess = -1;
    return -1;
}

// Sends a command on the chat-server connection (+0x290) and pumps it once.
// FUNCTION: TITANIUM 0x00491438
void TargetOwner_guess::ChatServerMessage_guess(int value_guess) {
    if (field290_guess != 0) {
        field290_guess->FUN_0040bf3d_guess(value_guess);
        field290_guess->GiveTime_guess();
    }
}

// Drops the chat-server connection (+0x290, shut down by 0x0040C654 and freed) and blanks the saved host
// (+0x0C), port (+0x8C) and both login strings (+0x90, +0x190), so the next OP_SetChatServer connects
// fresh (0x00495720).
// FUNCTION: TITANIUM 0x00491459
void TargetOwner_guess::DisconnectChatServer_guess() {
    NestedState_guess* old_guess = field290_guess;
    field290_guess = 0;
    field0c_guess = 0;
    field190_guess = 0;
    field8c_guess = 0;
    field90_guess = 0;
    if (old_guess != 0) {
        old_guess->FUN_0040c654_guess();
        free(old_guess);
    }
}

// Maps the mail library's 1-based status to the client's 0-based one; anything else is 0.
// FUNCTION: TITANIUM 0x0049148F
int __cdecl ConvertMailStatus_guess(int value_guess) {
    switch (value_guess) {
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    default:
        return 0;
    }
}

// Drops the mail-server connection (+0x834, shut down by 0x005FFE00 and freed) and blanks its saved host
// (+0x5B0), port (+0x630) and login strings (+0x634, +0x734).
// FUNCTION: TITANIUM 0x004914B5
void TargetOwner_guess::DisconnectMailServer_guess() {
    CleanupPayload_guess* memory_guess = field834_guess;
    if (memory_guess != 0) {
        memory_guess->FUN_005ffe00_guess();
        free(memory_guess);
        field834_guess = 0;
    }
    field5b0_guess = 0;
    field734_guess = 0;
    field630_guess = 0;
    field634_guess = 0;
}

// Deletes KEYMAP_<name> (plus the alternate-key suffix) from the [KeyMaps] ini section.
// FUNCTION: TITANIUM 0x004914F6
void __cdecl ClearKeyMapIniEntry_guess(int index_guess, int appendSuffix_guess) {
    char key_guess[256];
    FUN_0060e450_guess(key_guess, "KEYMAP_");
    FUN_0060e460_guess(key_guess, g_keyMapNames_guess[index_guess]);
    if (appendSuffix_guess == 1) {
        FUN_0060e460_guess(key_guess, g_keyMapSuffix_guess);
    }
    g_globalState_guess->WriteClientIniString_guess(0, "KeyMaps", key_guess);
}

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* first_guess, const char* second_guess);
// EXTERNAL: TITANIUM 0x0062202C _strnicmp
int __cdecl _strnicmp(const char* first_guess, const char* second_guess,
    unsigned int count_guess);
// EXTERNAL: TITANIUM 0x00621E9C _stricmp
int __cdecl _stricmp(const char* first_guess, const char* second_guess);

// Reads one key binding from [KeyMaps]: a key code plus modifier bits, -2 for *NONE* (unbound),
// -1 when the key name isn't in either key table.
// FUNCTION: TITANIUM 0x0049156D
unsigned int __cdecl readKeyMapFromIni_guess(int index_guess, int append_suffix_guess) {
    char key_guess[256];
    char map_guess[256];
    unsigned int flags_guess = 0;

    FUN_0060e450_guess(key_guess, "KEYMAP_");
    FUN_0060e460_guess(key_guess, g_keyMapNames_guess[index_guess]);
    if (append_suffix_guess == 1) {
        FUN_0060e460_guess(key_guess, g_keyMapSuffix_guess);
    }
    map_guess[0] = '\0';
    g_globalState_guess->FUN_004ae5e9_guess("KeyMaps", key_guess, "*NONE*",
        map_guess, 0x100);
    if (strcmp(map_guess, "*NONE*") == 0) {
        flags_guess = 0xfffffffe;
    } else {
        int tries_guess = 3;
        do {
            if (_strnicmp(map_guess, "SHIFT+", 6) == 0) {
                // Modifier bits: 0x40000000 shift, 0x20000000 control, 0x10000000 alt.
                flags_guess |= 0x40000000;
                FUN_0060e450_guess(map_guess, map_guess + 6);
            } else if (_strnicmp(map_guess, "CONTROL+", 8) == 0) {
                flags_guess |= 0x20000000;
                FUN_0060e450_guess(map_guess, map_guess + 8);
            } else if (_strnicmp(map_guess, "ALT+", 4) == 0) {
                flags_guess |= 0x10000000;
                FUN_0060e450_guess(map_guess, map_guess + 4);
            }
        } while (--tries_guess != 0);

        if (strlen(map_guess) == 1) {
            int count_guess = 0;
            for (; count_guess < 0x2f; ++count_guess) {
                if (g_keyCharTable_guess[count_guess].text_guess == map_guess[0]) {
                    flags_guess += g_keyCharTable_guess[count_guess].value_guess;
                    break;
                }
            }
            if (count_guess == 0x2f) {
                flags_guess = 0xffffffff;
            }
        } else {
            int count_guess = 0;
            for (; count_guess < 0x36; ++count_guess) {
                if (_stricmp(g_keyNameTable_guess[count_guess].text_guess,
                        map_guess) == 0) {
                    if (g_keyNameTable_guess[count_guess].value_guess == -1) {
                        flags_guess = 0xffffffff;
                    } else {
                        flags_guess += g_keyNameTable_guess[count_guess].value_guess;
                    }
                    break;
                }
            }
            if (count_guess == 0x36) {
                flags_guess = 0xffffffff;
            }
        }
    }
    return flags_guess;
}

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

// Reports activity to the world with opcode 0x6A5F (not in patch_Titanium.conf): 'A' after the first
// input since the last report, 'I' once after 15 minutes (900000 ms) idle.
// FUNCTION: TITANIUM 0x00491721
void __cdecl SendInactivityStatus_guess() {
    unsigned int data_guess[2];
    if (g_flag_00905d2d_guess != 0) {
        g_time_00905d30_guess = FUN_0046d655_guess();
        g_flag_00905d2d_guess = 0;
        ((char*)data_guess)[0] = 'A';
        if (g_flag_00905d2c_guess != 0 && g_globalState_guess != 0) {
            if (FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6a5f, data_guess, 8, 1) != 0) {
                g_flag_00905d2c_guess = 0;
            }
        }
    } else if (g_flag_00905d2c_guess == 0 && g_time_00905d30_guess != 0) {
        unsigned int elapsed_guess = FUN_0046d655_guess() - g_time_00905d30_guess;
        ((char*)data_guess)[0] = 'I';
        if (elapsed_guess > 900000 && g_globalState_guess != 0) {
            if (FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6a5f, data_guess, 8, 1) != 0) {
                g_flag_00905d2c_guess = 1;
            }
        }
    }
}

struct Interface_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 Interface_guess::FUN_0059dd30_guess
    char FUN_0059dd30_guess();
    // EXTERNAL: TITANIUM 0x00569639 Interface_guess::Deactivate_guess
    void Deactivate_guess();
    // EXTERNAL: TITANIUM 0x0052B026 Interface_guess::FinishLoot_guess
    void FinishLoot_guess();
    virtual void RefreshCounts_guess();
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
    char padding_0004_guess[0x232];
    char field236_guess; // 0x236
    // EXTERNAL: TITANIUM 0x0056A029 Interface_guess::DropItemIntoTrade_guess
    void DropItemIntoTrade_guess();
    // EXTERNAL: TITANIUM 0x0056A2B8 Interface_guess::DropMoneyIntoTrade_guess
    void DropMoneyIntoTrade_guess();
};

#define g_status_00850c38_guess EQ_GLOBAL(Interface_guess*, 0x00850C38)
#define g_status_00991a90_guess EQ_GLOBAL(Interface_guess*, 0x00991A90)


// EXTERNAL: TITANIUM 0x00574860 FUN_00574860_guess
int __cdecl FUN_00574860_guess(const char* text_guess, int* length_guess);

struct ChatSink_guess {
    char padding_0000_guess[0x218];
    // EXTERNAL: TITANIUM 0x00448314 ??1ChatSink_guess@@QAE@XZ
    ~ChatSink_guess();
    // EXTERNAL: TITANIUM 0x00448A0B ChatSink_guess::ChatSink_guess
    ChatSink_guess();
    // EXTERNAL: TITANIUM 0x0044861F ChatSink_guess::DrawLoadScreen_guess
    void DrawLoadScreen_guess();
    // EXTERNAL: TITANIUM 0x0044894C ChatSink_guess::SetProgressBar_guess
    void SetProgressBar_guess(int type_guess, char* text_guess);
};

#define g_chatSink_00905c9c_guess EQ_GLOBAL(ChatSink_guess*, 0x00905C9C)

extern "C" int __cdecl _vsprintf(char* destination_guess, const char* format_guess,
    va_list arguments_guess);

#define g_mode_0085097c_guess EQ_GLOBAL(unsigned char, 0x0085097C)
#define g_mode_00923b88_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_defaultStart_00923b64_guess EQ_GLOBAL(float, 0x00923B64)
#define g_defaultEnd_00923b74_guess EQ_GLOBAL(float, 0x00923B74)
#define g_defaultRed_00923b57_guess EQ_GLOBAL(unsigned char, 0x00923B57)
#define g_defaultGreen_00923b5b_guess EQ_GLOBAL(unsigned char, 0x00923B5B)
#define g_defaultBlue_00923b5f_guess EQ_GLOBAL(unsigned char, 0x00923B5F)

// CDisplay at 0x00905D24: fields at 0x12C, 0x130 and 0x14C are read by the color setter.
struct Display_guess {
    char padding_0000_guess[0x12c];
    float field12c_guess;
    float field130_guess;
    char padding_0134_guess[0x14c - 0x134];
    unsigned char field14c_guess;
    // EXTERNAL: TITANIUM 0x0044104C Display_guess::SetFogState_guess
    void SetFogState_guess(int one_guess, float start_guess, float end_guess, int red_guess,
        int green_guess, int blue_guess);
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

// The object at this = CEverQuest: its three colour ints sit at 0x39404, 0x39408, 0x3940C.
struct EverQuestColor_guess {
    char padding_0000_guess[0x39404];
    int red_guess;      // 0x39404
    int green_guess;    // 0x39408
    int blue_guess;     // 0x3940C

    void UpdateFog_guess(int unused_guess);
};

// Sets the fog range and colour: fixed ranges for environment modes 5-10, else the zone fog (at least
// 30/105 in modes 1, 2 and 5 of 0x923B88). Colour channels are clamped to 1..255.
// FUNCTION: TITANIUM 0x004940E1
void EverQuestColor_guess::UpdateFog_guess(int unused_guess) {
    unsigned char mode_guess = g_mode_0085097c_guess;
    int r_guess = red_guess;
    int g_guess = green_guess;
    int b_guess = blue_guess;
    float end_guess;
    float start_guess;
    if (mode_guess == 5) {
        start_guess = 0.0f;
        end_guess = 300.0f;
    } else if (mode_guess == 6 || mode_guess == 7 || mode_guess == 8) {
        start_guess = 0.0f;
        end_guess = 50.0f;
    } else if (mode_guess == 9) {
        start_guess = 90.0f;
        end_guess = 100.0f;
    } else if (mode_guess == 10) {
        start_guess = 0.0f;
        end_guess = 400.0f;
    } else {
        unsigned char mode2_guess = g_mode_00923b88_guess;
        if (mode2_guess == 2 || mode2_guess == 1 || mode2_guess == 5) {
            Display_guess* display_guess = g_display_guess;
            if (display_guess->field14c_guess != 0) {
                start_guess = display_guess->field12c_guess;
                end_guess = display_guess->field130_guess;
            } else {
                start_guess = g_defaultStart_00923b64_guess;
                end_guess = g_defaultEnd_00923b74_guess;
            }
            if (start_guess < 30.0f) {
                start_guess = 30.0f;
            }
            if (end_guess < 105.0f) {
                end_guess = 105.0f;
            }
        } else {
            start_guess = g_defaultStart_00923b64_guess;
            r_guess = g_defaultRed_00923b57_guess;
            g_guess = g_defaultGreen_00923b5b_guess;
            end_guess = g_defaultEnd_00923b74_guess;
            b_guess = g_defaultBlue_00923b5f_guess;
        }
    }
    if (r_guess < 1) {
        r_guess = 1;
    } else if (r_guess > 255) {
        r_guess = 255;
    }
    if (g_guess < 1) {
        g_guess = 1;
    } else if (g_guess > 255) {
        g_guess = 255;
    }
    if (b_guess < 1) {
        b_guess = 1;
    } else if (b_guess > 255) {
        b_guess = 255;
    }
    g_display_guess->SetFogState_guess(1, start_guess, end_guess, r_guess, g_guess, b_guess);
}

// printf-style status line onto the load screen (0x905C9C); dropped when there is none.
// FUNCTION: TITANIUM 0x00494236
void __cdecl DoLoadScreenProgressBar_guess(int unused_guess, int type_guess, const char* format_guess,
    ...) {
    char buffer_guess[0x800];
    if (g_chatSink_00905c9c_guess != 0) {
        va_list arguments_guess;
        va_start(arguments_guess, format_guess);
        _vsprintf(buffer_guess, format_guess, arguments_guess);
        g_chatSink_00905c9c_guess->SetProgressBar_guess(type_guess, buffer_guess);
    }
}

// Recreates the load-screen object. With `cleanup` set it deletes the new one straight away, which is
// how the load screen is torn down (original shape).
// FUNCTION: TITANIUM 0x00494285
void GlobalState_guess::DoLoadScreen_guess(int cleanup_guess) {
    if (g_chatSink_00905c9c_guess != 0) {
        delete g_chatSink_00905c9c_guess;
        g_chatSink_00905c9c_guess = 0;
    }
    g_chatSink_00905c9c_guess = new ChatSink_guess;
    if (g_chatSink_00905c9c_guess != 0) {
        g_chatSink_00905c9c_guess->DrawLoadScreen_guess();
        if (cleanup_guess != 0) {
            delete g_chatSink_00905c9c_guess;
            g_chatSink_00905c9c_guess = 0;
        }
    }
}

// EXTERNAL: TITANIUM 0x0062444B FUN_0062444b_guess
void __cdecl FUN_0062444b_guess(const char* name_guess);
// EXTERNAL: TITANIUM 0x00612638 FUN_00612638_guess
void __cdecl FUN_00612638_guess(const char* name_guess);

#define g_mssFiles_0078e00c_guess EQ_ARRAY(char*, 0x0078E00C)

// Moves Miles Sound System files (mss*.*) dated before July 2002, and the fixed list at 0x78E00C, into
// the backup folder; a file that can't be moved is deleted (0x612638, probably _unlink).
// FUNCTION: TITANIUM 0x00494319
// @early-stop: budget, structural ndiff=22
void __cdecl BackupMilesSoundSystemFiles_guess() {
    char buffer_guess[512];
    WIN32_FIND_DATAA findData_guess;
    SYSTEMTIME time_guess;
    HANDLE find_guess;

    FUN_0062444b_guess("backup");
    FUN_00574110_guess("Deleting obsolete files.");
    find_guess = FindFirstFileA("mss*.*", &findData_guess);
    if (find_guess != 0) {
        do {
            FileTimeToSystemTime(&findData_guess.ftLastWriteTime, &time_guess);
            if (time_guess.wYear < 2002 ||
                (time_guess.wYear == 2002 && time_guess.wMonth < 7)) {
                _sprintf(buffer_guess, "backup\\%s", findData_guess.cFileName);
                if (!MoveFileA(findData_guess.cFileName, buffer_guess)) {
                    FUN_00612638_guess(findData_guess.cFileName);
                }
            }
        } while (FindNextFileA(find_guess, &findData_guess));
        FindClose(find_guess);
    }
    char** files_guess = g_mssFiles_0078e00c_guess;
    char* name_guess = *files_guess;
    if (*name_guess != '\0') {
        do {
            _sprintf(buffer_guess, "backup\\%s", name_guess);
            MoveFileA(*files_guess, buffer_guess);
            FUN_00612638_guess(*files_guess);
            ++files_guess;
            name_guess = *files_guess;
        } while (*name_guess != '\0');
    }
}

// Copies `source` up to its first white space (UTF-8 aware); the Emote handler uses it for the name.
// FUNCTION: TITANIUM 0x00494430
void GlobalState_guess::CopyFirstWord_guess(char* source_guess, char* destination_guess) {
    char* current_guess = source_guess;
    unsigned int size_guess = 0;
    int length_guess;
    while (current_guess != 0 && FUN_00574860_guess(current_guess, &length_guess) == 0) {
        current_guess += length_guess;
        size_guess += length_guess;
    }
    memcpy(destination_guess, source_guess, size_guess);
    destination_guess[size_guess] = 0;
}

// True while the give/trade, loot or merchant window, or the 0x9915D0/0x850C38 windows, is visible;
// gates slash commands.
// FUNCTION: TITANIUM 0x00494473
char IsTransactionWindowOpen_guess() {
    char result_guess = 0;
    if (pinstCBarterMerchantWnd_guess != 0) {
        result_guess = pinstCBarterMerchantWnd_guess->IsVisible_guess();
    }
    if (pinstCMerchantWnd_guess != 0) {
        result_guess |= pinstCMerchantWnd_guess->IsVisible_guess();
    }
    if (pinstCLootWnd_guess != 0) {
        result_guess |= pinstCLootWnd_guess->IsVisible_guess();
    }
    if (pinstCTradeWnd_guess != 0) {
        result_guess |= pinstCTradeWnd_guess->IsVisible_guess();
    }
    if (g_status_00850c38_guess != 0) {
        result_guess |= g_status_00850c38_guess->FUN_0059dd30_guess();
    }
    return result_guess;
}

// Starts a wait that expires `duration` ms from now.
// FUNCTION: TITANIUM 0x004944CF
TimedEntry_guess::TimedEntry_guess(void* field04_guess, unsigned int duration_guess)
    : field04_guess(field04_guess) {
    active_guess = 1;
    expired_guess = 0;
    deadline_guess = g_clockData_guess->current_guess + duration_guess;
}

// True while the wait is active and its deadline has not passed.
// FUNCTION: TITANIUM 0x004944FC
int TimedEntry_guess::IsActive_guess() {
    int result_guess = 0;
    if (active_guess != 0 && g_clockData_guess->current_guess < deadline_guess) {
        ++result_guess;
    }
    return result_guess;
}

// Packet handler while waiting for a zone change (vtable 0x649458 slot 0): the reply is stored and
// marked pending, chat still shows.
// FUNCTION: TITANIUM 0x00494516
void PacketReceiver_guess::HandleZoneChangeWaitPacket_guess(
    int unused1_guess, short* packet_guess, int unused2_guess) {
    // OP_ZoneChange: the 0x58-byte ZoneChange_Struct (name, zone, y/x/z, reason, success).
    if (packet_guess[0] == 0x5dd8) {
        memcpy(payload_guess, packet_guess + 1, 0x58);
        pending_guess = 1;
        ready_guess = 0;
    // OP_ChannelMessage.
    } else if (packet_guess[0] == 0x1004) {
        Handle_OP_ChannelMessage_guess(packet_guess + 1);
    }
}

// Ends the wait and signals the callback with 1.
// FUNCTION: TITANIUM 0x00494557
void TimedEntry_guess::FinishWait_guess(
    TimedEntryCallback_guess* callback_guess) {
    active_guess = 0;
    callback_guess->FUN_00424be6_guess(1);
}

// A null name also counts as having one.
// FUNCTION: TITANIUM 0x00494569
int __cdecl NameHasApostrophe_guess(char* text_guess) {
    if (text_guess == 0) {
        return 1;
    }
    int length_guess = (int)strlen(text_guess);
    int index_guess = 0;
    if (0 < length_guess) {
        do {
            if (text_guess[index_guess] == '\'') {
                return 1;
            }
            ++index_guess;
        } while (index_guess < length_guess);
    }
    return 0;
}

// Marks input since the last activity report (SendInactivityStatus 0x491721 sends it).
// FUNCTION: TITANIUM 0x004917D5
void NoteUserActivity_guess() {
    g_flag_00905d2d_guess = 1;
}

// Infravision is a red tint (0x41,0x32,0x32), ultravision a blue one (0x50,0x50,0x78).
// FUNCTION: TITANIUM 0x004917DD
void GlobalState_guess::SetDefaultVisionColors_guess() {
    g_value_00923900_guess = 0x32;
    g_value_00923904_guess = 0x32;
    g_value_009238fc_guess = 0x41;
    g_value_00923908_guess = 0x50;
    g_value_0092390c_guess = 0x50;
    g_value_00923910_guess = 0x78;
}

// Zone 121 caps light radius at 25 and zone 158 at 100; elsewhere it is effectively unlimited.
// CDisplay::CreateLight uses it.
// FUNCTION: TITANIUM 0x0049180C
float __cdecl GetZoneMaxLightRadius_guess() {
    switch (g_selector_00924470_guess) {
    case 0x79:
        return 25.0f;
    case 0x9e:
        return 100.0f;
    default:
        return 10000.0f;
    }
}

// Empty vtable slot taking one argument (vtables 0x6490B8, 0x6498D4).
// FUNCTION: TITANIUM 0x00491839
void __stdcall EmptyCallback1_guess(void* arg_guess) {
}

// Empty vtable slot taking two arguments.
// FUNCTION: TITANIUM 0x0049183F
void __stdcall EmptyCallback2_guess(void* first_guess, void* second_guess) {
}


#define g_records_0095bab4_guess EQ_ARRAY(char, 0x0095BAB4)
#define g_records_0095d3b4_guess EQ_ARRAY(char, 0x0095D3B4)
#define gFriendsList_guess EQ_ARRAY(char, 0x0095A1B4)

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(unsigned int value_guess, char* record_guess);

// Calls virtual slot 33 of the adventure zone window (0x00850CB4) when it exists; /zone uses it.
// FUNCTION: TITANIUM 0x00492968
void FUN_00492968_guess() {
    if (pinstCAvaZoneWnd_guess != 0) {
        pinstCAvaZoneWnd_guess->Activate();
    }
}

// Case-insensitive match over the ignore list: 100 names of 64 bytes at 0x95BAB4.
// FUNCTION: TITANIUM 0x0049297B
int GlobalState_guess::BeingIgnored_guess(unsigned int value_guess) {
    char* record_guess = g_records_0095bab4_guess;
    for (;;) {
        if (*record_guess != 0 && FUN_00574950_guess(value_guess, record_guess) == 0) {
            return 1;
        }
        record_guess += 0x40;
        if ((int)record_guess >= (int)g_records_0095d3b4_guess) {
            return 0;
        }
    }
}

// The same match over the friends list at 0x95A1B4, which ends where the ignore list starts.
// FUNCTION: TITANIUM 0x004929AC
int GlobalState_guess::IsFriend_guess(unsigned int value_guess) {
    char* record_guess = gFriendsList_guess;
    for (;;) {
        if (*record_guess != 0 && FUN_00574950_guess(value_guess, record_guess) == 0) {
            return 1;
        }
        record_guess += 0x40;
        if ((int)record_guess >= (int)g_records_0095bab4_guess) {
            return 0;
        }
    }
}

struct PilotActor_guess;
struct PilotPlayer_guess;

struct PilotActor_guess {
    char padding_0000_guess[0xAD];
    unsigned char fieldad_guess; // 0xAD
    char padding_00ae_guess[0x1A];
    float fieldc8_guess; // 0xC8
    char padding_00cc_guess[0x90];
    PilotPlayer_guess* field15c_guess; // 0x15C
};

struct PilotPlayer_guess {
    char padding_0000_guess[0x58];
    float field58_guess; // 0x58
    float field5c_guess; // 0x5C
    char padding_0060_guess[0x148];
    PilotActor_guess* actor_guess; // 0x1A8
    char padding_01ac_guess[0xB4];
    int race_guess; // 0x260
    // EXTERNAL: TITANIUM 0x0047BFD0 PilotPlayer_guess::IsHorseRace_guess
    bool IsHorseRace_guess();
};

struct PilotMode_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0c_guess();
    virtual void Slot10_guess(float value_guess);
    virtual void Slot14_guess(float value_guess);
    virtual void Slot18_guess(float value_guess);
    virtual void Slot1c_guess();
    virtual void Slot20_guess(float value_guess);
    virtual float Slot24_guess();
    virtual void Slot28_guess();
    virtual char Slot2c_guess();
    char padding_0004_guess[0x28];
    float field2c_guess; // 0x2C
    float field30_guess; // 0x30
    float field34_guess; // 0x34
};

struct PilotDisplay_guess {
    // EXTERNAL: TITANIUM 0x004365DB PilotDisplay_guess::FixHeading_guess
    float FixHeading_guess(float angle_guess);
};

#define g_value_009237d4_guess EQ_GLOBAL(int, 0x009237D4)
#define g_value_009237d8_guess EQ_GLOBAL(int, 0x009237D8)
#define g_value_009237dc_guess EQ_GLOBAL(int, 0x009237DC)
#define g_value_00923780_guess EQ_GLOBAL(int, 0x00923780)
#define g_value_00923778_guess EQ_GLOBAL(int, 0x00923778)
#define g_value_00923784_guess EQ_GLOBAL(int, 0x00923784)
#define g_value_0092377c_guess EQ_GLOBAL(int, 0x0092377C)
#define g_flag_00923840_guess EQ_GLOBAL(unsigned char, 0x00923840)
#define g_pilotFlag_00923843_guess EQ_GLOBAL(unsigned char, 0x00923843)
#define g_value_00924858_guess EQ_GLOBAL(float, 0x00924858)
#define g_pilotMode_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_pilotModes_guess EQ_ARRAY(PilotMode_guess*, 0x009254FC)
#define g_pilotDisplay_guess EQ_GLOBAL(PilotDisplay_guess*, 0x00905D24)
#define g_controlledPlayer_guess EQ_GLOBAL(PilotPlayer_guess*, 0x00905CE4)
#define g_localPlayer_guess EQ_GLOBAL(PilotPlayer_guess*, 0x00905CF8)
#define g_const_00649228_guess EQ_GLOBAL(const float, 0x00649228)
#define g_const_006410d0_guess EQ_GLOBAL(const float, 0x006410D0)
#define g_const_006410bc_guess EQ_GLOBAL(const float, 0x006410BC)
#define g_const_00640fec_guess EQ_GLOBAL(float, 0x00640FEC)

// Turns this frame's mouse-look deltas into heading and pitch for the player, its boat (race 0x8D,
// at most 3 per frame) or the active camera; pitch is clamped per camera mode.
// FUNCTION: TITANIUM 0x004929DD
// @early-stop: budget, structural ndiff=73
void GlobalState_guess::ApplyMouseLook_guess(int active_guess) {
    float scaled_guess;
    float fStack_guess;
    float local_guess;
    float angle_guess;
    if (g_value_009237d4_guess != 0) {
        local_guess = (float)g_value_009237d4_guess;
        scaled_guess = local_guess / (float)(g_value_00923780_guess - g_value_00923778_guess)
            * 512.0f;
        fStack_guess = scaled_guess
            * ((float)(g_value_009237dc_guess - 1) * g_const_006410d0_guess
                * g_const_00649228_guess + g_const_006410bc_guess);
        if (g_value_009237d8_guess != 0
            && fabs((float)g_value_009237d4_guess / g_value_009237d8_guess)
                < g_const_00640fec_guess) {
            fStack_guess = 0.0f;
            local_guess = 0.0f;
        }
        if (g_pilotMode_guess <= 2 || g_pilotModes_guess[g_pilotMode_guess]->Slot2c_guess() == 0) {
            if (g_localPlayer_guess->race_guess == 0x8d) {
                if (local_guess > 3.0f) {
                    local_guess = 3.0f;
                } else if (local_guess < -3.0f) {
                    local_guess = -3.0f;
                }
                g_localPlayer_guess->field58_guess = -local_guess;
            } else if (g_pilotMode_guess <= 2 || g_pilotMode_guess == 6) {
                if (active_guess != 0) {
                    if (g_localPlayer_guess->IsHorseRace_guess()) {
                        if (fStack_guess > 8.0f) {
                            fStack_guess = 8.0f;
                        } else if (fStack_guess < -8.0f) {
                            fStack_guess = -8.0f;
                        }
                    }
                    g_localPlayer_guess->field58_guess = -fStack_guess;
                }
            } else if (g_pilotMode_guess == 5) {
                g_pilotModes_guess[g_pilotMode_guess]->Slot20_guess(
                    g_pilotDisplay_guess->FixHeading_guess(
                        g_pilotModes_guess[g_pilotMode_guess]->Slot24_guess() + fStack_guess));
            }
        } else {
            g_pilotFlag_00923843_guess = 0;
            g_pilotModes_guess[g_pilotMode_guess]->Slot20_guess(
                g_pilotDisplay_guess->FixHeading_guess(
                    g_pilotModes_guess[g_pilotMode_guess]->Slot24_guess() + fStack_guess));
        }
    }
    if (g_value_009237d8_guess == 0) {
        return;
    }
    if (g_localPlayer_guess->race_guess == 0x8d) {
        return;
    }
    if (g_flag_00923840_guess != 0) {
        g_value_009237d8_guess = -g_value_009237d8_guess;
    }
    local_guess = (float)g_value_009237d8_guess;
    angle_guess = local_guess / (float)(g_value_00923784_guess - g_value_0092377c_guess)
        * 256.0f;
    angle_guess *= (float)(g_value_009237dc_guess - 1) * g_const_00649228_guess
        * g_const_006410d0_guess + g_const_006410bc_guess;
    if (g_value_009237d4_guess != 0
        && fabs((float)g_value_009237d8_guess / g_value_009237d4_guess) < 0.2f) {
        angle_guess = 0.0f;
        local_guess = 0.0f;
    }
    if (g_pilotMode_guess > 2 && g_localPlayer_guess->actor_guess->fieldad_guess != 5) {
        if (g_pilotMode_guess != 5 && g_pilotMode_guess != 6) {
            if (g_pilotMode_guess == 0) {
                return;
            }
            if (local_guess > g_value_009237dc_guess * 0.5) {
                local_guess = (float)(g_value_009237dc_guess * 0.5);
            } else if (local_guess < -(g_value_009237dc_guess * 0.5)) {
                local_guess = (float)-(g_value_009237dc_guess * 0.5);
            }
            local_guess += g_pilotModes_guess[g_pilotMode_guess]->field34_guess;
            if (local_guess < 3.0f) {
                local_guess = 3.0f;
            }
            g_pilotModes_guess[g_pilotMode_guess]->Slot18_guess(local_guess);
            return;
        }
        float value_guess = g_pilotModes_guess[g_pilotMode_guess]->field30_guess - angle_guess;
        if (value_guess > 64.0f) {
            value_guess = 64.0f;
        } else if (value_guess < -120.0f) {
            value_guess = -120.0f;
        }
        g_pilotModes_guess[g_pilotMode_guess]->Slot14_guess(value_guess);
        return;
    }
    if (g_localPlayer_guess->actor_guess->fieldc8_guess < -1000.0f) {
        return;
    }
    if (g_pilotMode_guess == 0) {
        if (g_controlledPlayer_guess->actor_guess != 0
            && g_controlledPlayer_guess->actor_guess->field15c_guess != 0
            && g_controlledPlayer_guess->actor_guess->field15c_guess == g_localPlayer_guess) {
            g_controlledPlayer_guess->field5c_guess -= angle_guess;
            if (g_controlledPlayer_guess->field5c_guess > 128.0f) {
                g_controlledPlayer_guess->field5c_guess = 128.0f;
            } else if (g_controlledPlayer_guess->field5c_guess < -64.0f) {
                g_controlledPlayer_guess->field5c_guess = -64.0f;
            }
        } else {
            g_localPlayer_guess->field5c_guess -= angle_guess;
            if (g_localPlayer_guess->field5c_guess > 128.0f) {
                g_localPlayer_guess->field5c_guess = 128.0f;
            } else if (g_localPlayer_guess->field5c_guess < -128.0f) {
                g_localPlayer_guess->field5c_guess = -128.0f;
            }
        }
    } else {
        float limit_guess = (float)g_value_009237dc_guess * 0.3f;
        if (local_guess > limit_guess) {
            local_guess = limit_guess;
        } else if (local_guess < -limit_guess) {
            local_guess = -limit_guess;
        }
        if (g_pilotMode_guess == 2) {
            g_pilotModes_guess[g_pilotMode_guess]->Slot10_guess(
                g_pilotModes_guess[g_pilotMode_guess]->field2c_guess
                - g_value_00924858_guess * local_guess);
        } else {
            float value_guess = g_pilotModes_guess[g_pilotMode_guess]->field30_guess - angle_guess;
            if (value_guess > 128.0f) {
                value_guess = 128.0f;
            } else if (value_guess < -128.0f) {
                value_guess = -128.0f;
            }
            g_pilotModes_guess[g_pilotMode_guess]->Slot14_guess(value_guess);
        }
    }
}

// Calls slot 34 of the trainer window (0x850BB0), probably its close.
// FUNCTION: TITANIUM 0x00491845
void CloseTrainWindow_guess() {
    pinstCTrainWnd_guess->Deactivate();
}

struct ForwardedObject_guess {
    // EXTERNAL: TITANIUM 0x004DC160 ForwardedObject_guess::CloseBank_guess
    void CloseBank_guess();
};

#define g_forwardedObject_guess EQ_GLOBAL(ForwardedObject_guess*, 0x00850C38)

// Closes the bank window (0x004DC160).
// FUNCTION: TITANIUM 0x00491853
void CloseBankWnd_guess() {
    g_forwardedObject_guess->CloseBank_guess();
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// Default melee verb by race (claw, maul, bite, punch, hit ...) from eqstr 0x2F83..0x2F98;
// `flag` picks the second form of each pair. Races up to 12 and a few others punch, the rest hit.
// FUNCTION: TITANIUM 0x0049185E
void __stdcall SetDefaultDamageDescByRace_guess(char* dst_guess, int type_guess, char flag_guess) {
    switch (type_guess) {
    case 0xe:
    case 0x17:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x3f:
    case 0x4c:
    case 0x6f:
    case 0x77:
    case 0x9e:
    case 0xb8:
    case 0xc4:
    case 0xc8:
    case 0xdd:
    case 0x130:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f88, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f87, 0));
        }
        return;
    case 0x2b:
    case 0x131:
    case 0xb1:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f85, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f83, 0));
        }
        return;
    case 0x4f:
    case 0x6d:
    case 0x81:
    case 0x86:
    case 0xac:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f8c, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f8b, 0));
        }
        return;
    case 0x55:
    case 0x69:
    case 0xae:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f8d, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f8e, 0));
        }
        return;
    case 0x6b:
    case 0x87:
    case 0xa9:
    case 0xbf:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f8a, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f89, 0));
        }
        return;
    case 0xc7:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f94, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f93, 0));
        }
        return;
    case 0xdc:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f90, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f8f, 0));
        }
        return;
    case 0xe5:
        if (flag_guess != 0) {
            strcpy(dst_guess, pStringTable->getString(0x2f92, 0));
        } else {
            strcpy(dst_guess, pStringTable->getString(0x2f91, 0));
        }
        return;
    case 0x78:
    case 0x16:
    case 0x18:
    case 0x22:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x2a:
    case 0x3d:
    case 0x4a:
    case 0x53:
    case 0x54:
    case 0x57:
    case 0x5b:
    case 0x66:
    case 0x71:
    case 0x94:
    case 0xab:
    case 0xb0:
    case 0xc2:
    case 0xde:
    case 0xdf:
    case 0x146:
    case 0x147:
    case 0x19f:
    case 0x1a0:
        break;
    default:
        if (type_guess <= 0xc || type_guess == 0x80 || type_guess == 0x82 || type_guess == 0x14a) {
            if (flag_guess != 0) {
                strcpy(dst_guess, pStringTable->getString(0x2f96, 0));
            } else {
                strcpy(dst_guess, pStringTable->getString(0x2f95, 0));
            }
        } else {
            if (flag_guess != 0) {
                strcpy(dst_guess, pStringTable->getString(0x2f98, 0));
            } else {
                strcpy(dst_guess, pStringTable->getString(0x2f97, 0));
            }
        }
        return;
    }
    if (flag_guess != 0) {
        strcpy(dst_guess, pStringTable->getString(0x2f86, 0));
    } else {
        strcpy(dst_guess, pStringTable->getString(0x2f84, 0));
    }
}

struct CompareState_guess {
    char padding_0000_guess[0xF78];
    int fieldf78_guess;
    int fieldf7c_guess;
};

struct CompareOwner_guess {
    char padding_0000_guess[0x1A8];
    CompareState_guess* field1a8_guess;
};

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int first_guess, int second_guess);

// Sound id for a riposte: 0x84, or 0x78 when both sides have +0xF78 == 2, or 0x7D on a 1-in-2 roll
// when the defender's +0xF7C is 3 (probably armour or weapon materials).
// FUNCTION: TITANIUM 0x00491BAD
int __stdcall GetSoundEffectForRiposte_guess(CompareOwner_guess* first_guess, CompareOwner_guess* second_guess) {
    int result_guess = 0x84;
    if (first_guess->field1a8_guess->fieldf78_guess == 2 &&
        second_guess->field1a8_guess->fieldf78_guess == 2) {
        result_guess = 0x78;
    }
    if (second_guess->field1a8_guess->fieldf7c_guess == 3 &&
        RandomRange_guess(1, 2) == 1) {
        result_guess = 0x7d;
    }
    return result_guess;
}

// Saves the options and ini settings, then readies the PC for respawn; run on OP_ZonePlayerToBind.
// FUNCTION: TITANIUM 0x00491C04
void GlobalState_guess::PrepareLocalPCForRepop_guess() {
    saveOptions_guess();
    FUN_004b07d8_guess();
    g_contextObject_guess->PrepareForRepop_guess(g_value_0078d850_guess, 0);
}

struct DagNode_guess {
    char padding_0000_guess[0x34];
    unsigned char field34_guess;
};

struct DagPart_guess {
    char padding_0000_guess[0x12c];
    DagNode_guess* field12c_guess;
};

struct DagOwner_guess {
    char padding_0000_guess[0x1a8];
    DagPart_guess* field1a8_guess;
};

// Attachment-point dag name for an effect: 1 head, 2 right hand, 3 left hand, 4/5 right/left foot,
// else chest. Models with a bone set (+0x12C, +0x34) use the long names, older ones the short ones.
// FUNCTION: TITANIUM 0x00491C28
int __cdecl GetDagName_guess(DagOwner_guess* owner_guess,
    const char* prefix_guess, char* output_guess, int type_guess) {
    switch (type_guess) {
    case 1:
        _sprintf(output_guess, "%sHEAD_POINT_DAG", prefix_guess);
        break;
    case 2:
        _sprintf(output_guess, "%sR_POINT_DAG", prefix_guess);
        break;
    case 3:
        _sprintf(output_guess, "%sL_POINT_DAG", prefix_guess);
        break;
    case 4:
        if (owner_guess->field1a8_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess->field34_guess != 0) {
            _sprintf(output_guess, "%sBOFOOTR_DAG", prefix_guess);
        } else {
            _sprintf(output_guess, "%sBO_R_DAG", prefix_guess);
        }
        break;
    case 5:
        if (owner_guess->field1a8_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess->field34_guess != 0) {
            _sprintf(output_guess, "%sBOFOOTL_DAG", prefix_guess);
        } else {
            _sprintf(output_guess, "%sBO_L_DAG", prefix_guess);
        }
        break;
    default:
        if (owner_guess->field1a8_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess != 0 &&
            owner_guess->field1a8_guess->field12c_guess->field34_guess != 0) {
            _sprintf(output_guess, "%sCHEST_POINT_DAG", prefix_guess);
        } else {
            _sprintf(output_guess, "%sCH_DAG", prefix_guess);
        }
        break;
    }
    return 1;
}

struct NameMatcher_guess {
    // EXTERNAL: TITANIUM 0x00485DF1 NameMatcher_guess::MatchesAnyName_guess
    char MatchesAnyName_guess(const char* value_guess);
};

struct ContainsMatcher_guess {
    // EXTERNAL: TITANIUM 0x004303A6 ContainsMatcher_guess::IsMember_guess
    char IsMember_guess(const char* source_guess);
};

#define g_nameMatcher_00904248_guess EQ_GLOBAL(NameMatcher_guess, 0x00904248)
#define g_containsMatcher_0091d708_guess EQ_GLOBAL(ContainsMatcher_guess, 0x0091D708)
#define g_filterFlags_0098581c_guess EQ_GLOBAL(unsigned char, 0x0098581C)

// Spell-effect filter on the option byte 0x98581C (bits 2/4/8 widen it, 0x10 lets pets through):
// returns true only when neither side is the player or a filtered name. Low-confidence name: the
// callers' sense of the result isn't settled.
// FUNCTION: TITANIUM 0x00491CFF
// @early-stop: budget, diff ndiff=97
bool __cdecl CanShowSpellEffect_guess(int mode_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess) {
    unsigned char flags_guess = g_filterFlags_0098581c_guess;
    bool notMatch_guess = (flags_guess & 0x10) == 0;
    bool spawnContains_guess = false;
    bool targetEqual_guess = false;
    bool nameFlag_guess = false;
    bool targetContains_guess = false;
    bool spawnEqual_guess = false;
    bool reject_guess = false;
    if ((flags_guess & 8) != 0) {
        nameFlag_guess = true;
        spawnContains_guess = true;
        targetContains_guess = true;
        spawnEqual_guess = true;
        targetEqual_guess = true;
    } else if ((flags_guess & 4) != 0) {
        spawnContains_guess = true;
        targetContains_guess = true;
        spawnEqual_guess = true;
        targetEqual_guess = true;
    } else if ((flags_guess & 2) != 0) {
        spawnEqual_guess = true;
        targetEqual_guess = true;
    }
    if (first_guess == 0 && second_guess == 0) {
        reject_guess = true;
    }
    if (nameFlag_guess && !notMatch_guess) {
        reject_guess = true;
    }
    if (!reject_guess) {
        if (first_guess != 0) {
            unsigned char state_guess = first_guess->type_guess;
            if (state_guess == 1) {
                if (!notMatch_guess) {
                    reject_guess = true;
                }
            } else if (state_guess != 0) {
                reject_guess = true;
            } else if (nameFlag_guess ||
                (spawnContains_guess &&
                    g_containsMatcher_0091d708_guess.IsMember_guess(first_guess->name120_guess)) ||
                (spawnEqual_guess &&
                    g_nameMatcher_00904248_guess.MatchesAnyName_guess(first_guess->name120_guess)) ||
                first_guess == reinterpret_cast<TransferAction_guess*>(g_displayPlayer_guess)) {
                reject_guess = true;
            }
        }
        if (!reject_guess && second_guess != 0 && second_guess->type_guess == 0) {
            if (targetContains_guess &&
                g_containsMatcher_0091d708_guess.IsMember_guess(second_guess->name120_guess)) {
                reject_guess = true;
            } else if (targetEqual_guess &&
                g_nameMatcher_00904248_guess.MatchesAnyName_guess(second_guess->name120_guess)) {
                reject_guess = true;
            } else if (second_guess == reinterpret_cast<TransferAction_guess*>(g_displayPlayer_guess)) {
                reject_guess = true;
            }
        }
    }
    return !reject_guess;
}

// Maps a con level (1..5) to the chat colour PrintAssessment prints it in; others get colour 2.
// FUNCTION: TITANIUM 0x00491E30
int __cdecl GetConColor_guess(int value_guess) {
    switch (value_guess) {
    case 1:
        return 0x12;
    case 2:
        return 4;
    case 3:
        return 0xa;
    case 4:
        return 0xf;
    case 5:
        return 0xd;
    default:
        return 2;
    }
}

// Classes 1-16 are the player classes, 20-35 their GM trainers and 40/41 banker/merchant
// (EQEmu numbering); unknown ids give 'UNKNOWN CLASS' (0x998).
// FUNCTION: TITANIUM 0x00491E5B
char* GlobalState_guess::GetClassDesc(int value_guess) {
    switch (value_guess) {
    case 1:
        return pStringTable->getString(0x5de, 0);
    case 2:
        return pStringTable->getString(0x5e2, 0);
    case 3:
        return pStringTable->getString(0x5e6, 0);
    case 4:
        return pStringTable->getString(0x5ee, 0);
    case 5:
        return pStringTable->getString(0x5ea, 0);
    case 6:
        return pStringTable->getString(0x5f2, 0);
    case 7:
        return pStringTable->getString(0x5f6, 0);
    case 8:
        return pStringTable->getString(0x5fa, 0);
    case 9:
        return pStringTable->getString(0x5fe, 0);
    case 10:
        return pStringTable->getString(0x602, 0);
    case 11:
        return pStringTable->getString(0x606, 0);
    case 12:
        return pStringTable->getString(0x60a, 0);
    case 13:
        return pStringTable->getString(0x60e, 0);
    case 14:
        return pStringTable->getString(0x612, 0);
    case 15:
        return pStringTable->getString(0x616, 0);
    case 16:
        return pStringTable->getString(0x169f, 0);
    case 0x14:
        return pStringTable->getString(0x5cf, 0);
    case 0x15:
        return pStringTable->getString(0x5d0, 0);
    case 0x16:
        return pStringTable->getString(0x5d1, 0);
    case 0x18:
        return pStringTable->getString(0x5d2, 0);
    case 0x17:
        return pStringTable->getString(0x5d3, 0);
    case 0x19:
        return pStringTable->getString(0x5d4, 0);
    case 0x1a:
        return pStringTable->getString(0x5d5, 0);
    case 0x1b:
        return pStringTable->getString(0x5d6, 0);
    case 0x1c:
        return pStringTable->getString(0x5d7, 0);
    case 0x1d:
        return pStringTable->getString(0x5d8, 0);
    case 0x1e:
        return pStringTable->getString(0x5d9, 0);
    case 0x1f:
        return pStringTable->getString(0x5da, 0);
    case 0x20:
        return pStringTable->getString(0x5db, 0);
    case 0x21:
        return pStringTable->getString(0x5dc, 0);
    case 0x22:
        return pStringTable->getString(0x5dd, 0);
    case 0x23:
        return pStringTable->getString(0x16a0, 0);
    case 0x28:
        return pStringTable->getString(0x5ce, 0);
    case 0x29:
        return pStringTable->getString(0x5cd, 0);
    case 0x42:
        return pStringTable->getString(0x17de, 0);
    default:
        return pStringTable->getString(0x998, 0);
    }
}

// Three-letter class code from the string table: ids 3065-3079 for classes 1-15 (4 and 5 swapped in id
// order), 5810 for class 16, else 2456 (the unknown class).
// FUNCTION: TITANIUM 0x004922D5
char* GlobalState_guess::GetClassThreeLetterCode(int value_guess) {
    switch (value_guess) {
    case 1:
        return g_stringTable_guess->Lookup_guess(0xbf9, 0);
    case 2:
        return g_stringTable_guess->Lookup_guess(0xbfa, 0);
    case 3:
        return g_stringTable_guess->Lookup_guess(0xbfb, 0);
    case 4:
        return g_stringTable_guess->Lookup_guess(0xbfd, 0);
    case 5:
        return g_stringTable_guess->Lookup_guess(0xbfc, 0);
    case 6:
        return g_stringTable_guess->Lookup_guess(0xbfe, 0);
    case 7:
        return g_stringTable_guess->Lookup_guess(0xbff, 0);
    case 8:
        return g_stringTable_guess->Lookup_guess(0xc00, 0);
    case 9:
        return g_stringTable_guess->Lookup_guess(0xc01, 0);
    case 10:
        return g_stringTable_guess->Lookup_guess(0xc02, 0);
    case 11:
        return g_stringTable_guess->Lookup_guess(0xc03, 0);
    case 12:
        return g_stringTable_guess->Lookup_guess(0xc04, 0);
    case 13:
        return g_stringTable_guess->Lookup_guess(0xc05, 0);
    case 14:
        return g_stringTable_guess->Lookup_guess(0xc06, 0);
    case 15:
        return g_stringTable_guess->Lookup_guess(0xc07, 0);
    case 16:
        return g_stringTable_guess->Lookup_guess(0x16b2, 0);
    default:
        return g_stringTable_guess->Lookup_guess(0x998, 0);
    }
}

// Bard instrument type of an item: 23 wind, 24 stringed, 25 brass, 26 percussion, 50 singing,
// 51 all; other values give an empty string.
// FUNCTION: TITANIUM 0x004923D5
char* GlobalState_guess::GetItemClassDesc_guess(int value_guess) {
    switch (value_guess) {
    case 0x17:
        return g_stringTable_guess->Lookup_guess(0x3663, 0);
    case 0x18:
        return g_stringTable_guess->Lookup_guess(0x365c, 0);
    case 0x19:
        return g_stringTable_guess->Lookup_guess(0x3630, 0);
    case 0x1a:
        return g_stringTable_guess->Lookup_guess(0x364a, 0);
    case 0x32:
        return g_stringTable_guess->Lookup_guess(0x3654, 0);
    case 0x33:
        return g_stringTable_guess->Lookup_guess(0x1676, 0);
    }
    return g_text_0063f53f_guess;
}

// Body type name from the string table: ids 2437-2454 for the classic types, 5754, 5786 and 5841 for
// types 19, 20 and 34, else 2455 (the unknown body type).
// FUNCTION: TITANIUM 0x00492438
char* GlobalState_guess::GetBodyTypeDesc(int value_guess) {
    switch (value_guess) {
    case 0x1:
        return g_stringTable_guess->Lookup_guess(0x98b, 0);
    case 0x2:
        return g_stringTable_guess->Lookup_guess(0x98d, 0);
    case 0x3:
        return g_stringTable_guess->Lookup_guess(0x991, 0);
    case 0x4:
        return g_stringTable_guess->Lookup_guess(0x98a, 0);
    case 0x5:
        return g_stringTable_guess->Lookup_guess(0x986, 0);
    case 0x6:
        return g_stringTable_guess->Lookup_guess(0x989, 0);
    case 0x7:
        return g_stringTable_guess->Lookup_guess(0x98e, 0);
    case 0xc:
        return g_stringTable_guess->Lookup_guess(0x995, 0);
    case 0xd:
        return g_stringTable_guess->Lookup_guess(0x992, 0);
    case 0xe:
        return g_stringTable_guess->Lookup_guess(0x993, 0);
    case 0xf:
        return g_stringTable_guess->Lookup_guess(0x994, 0);
    case 0x13:
        return g_stringTable_guess->Lookup_guess(0x167a, 0);
    case 0x14:
        return g_stringTable_guess->Lookup_guess(0x169a, 0);
    case 0x15:
        return g_stringTable_guess->Lookup_guess(0x985, 0);
    case 0x16:
        return g_stringTable_guess->Lookup_guess(0x98c, 0);
    case 0x17:
        return g_stringTable_guess->Lookup_guess(0x98f, 0);
    case 0x18:
        return g_stringTable_guess->Lookup_guess(0x988, 0);
    case 0x19:
        return g_stringTable_guess->Lookup_guess(0x990, 0);
    case 0x1a:
        return g_stringTable_guess->Lookup_guess(0x987, 0);
    case 0x1c:
        return g_stringTable_guess->Lookup_guess(0x996, 0);
    case 0x22:
        return g_stringTable_guess->Lookup_guess(0x16d1, 0);
    default:
        return g_stringTable_guess->Lookup_guess(0x997, 0);
    }
}

struct LargeObject_guess {
    char padding_0000_guess[0x17BB4];
    unsigned char field_17bb4_guess;
    void ClearChatText_guess();
};

// Language 0 (common) has two strings, picked by 0x923D5C.
// FUNCTION: TITANIUM 0x00492595
char* GlobalState_guess::GetLangDesc_guess(int value_guess) {
    switch (value_guess) {
    case 0:
        if (g_value_00923d5c_guess)
            return g_stringTable_guess->Lookup_guess(0xc29, 0);
        return g_stringTable_guess->Lookup_guess(0xc2a, 0);
    case 1:
        return g_stringTable_guess->Lookup_guess(0xc80, 0);
    case 2:
        return g_stringTable_guess->Lookup_guess(0xc81, 0);
    case 3:
        return g_stringTable_guess->Lookup_guess(0xc82, 0);
    case 4:
        return g_stringTable_guess->Lookup_guess(0xc83, 0);
    case 5:
        return g_stringTable_guess->Lookup_guess(0xc84, 0);
    case 6:
        return g_stringTable_guess->Lookup_guess(0xc85, 0);
    case 7:
        return g_stringTable_guess->Lookup_guess(0xc86, 0);
    case 8:
        return g_stringTable_guess->Lookup_guess(0xc87, 0);
    case 9:
        return g_stringTable_guess->Lookup_guess(0xc88, 0);
    case 0xd:
        return g_stringTable_guess->Lookup_guess(0xc89, 0);
    case 0xe:
        return g_stringTable_guess->Lookup_guess(0xc8a, 0);
    case 0xf:
        return g_stringTable_guess->Lookup_guess(0xc8b, 0);
    case 0x10:
        return g_stringTable_guess->Lookup_guess(0xc8c, 0);
    case 0x11:
        return g_stringTable_guess->Lookup_guess(0xc8d, 0);
    case 0x12:
        return g_stringTable_guess->Lookup_guess(0xc8e, 0);
    case 0x13:
        return g_stringTable_guess->Lookup_guess(0xc8f, 0);
    case 0x14:
        return g_stringTable_guess->Lookup_guess(0xc90, 0);
    case 0xa:
        return g_stringTable_guess->Lookup_guess(0xc91, 0);
    case 0x15:
        return g_stringTable_guess->Lookup_guess(0xc92, 0);
    case 0xb:
        return g_stringTable_guess->Lookup_guess(0xc93, 0);
    case 0xc:
        return g_stringTable_guess->Lookup_guess(0xc94, 0);
    case 0x16:
        return g_stringTable_guess->Lookup_guess(0xc95, 0);
    case 0x17:
        return g_stringTable_guess->Lookup_guess(0xc96, 0);
    case 0x18:
        return g_stringTable_guess->Lookup_guess(0xc97, 0);
    default:
        return g_stringTable_guess->Lookup_guess(0xc2b, 0);
    }
}

// Race names come from dbstr (type 11), not eqstr. The int return is really the text pointer.
// FUNCTION: TITANIUM 0x0049273D
int GlobalState_guess::GetRaceDesc(unsigned int value_guess) {
    char output_guess = 0;
    return g_dbStringManager_guess->FUN_004355f7_guess(value_guess, 0xb, &output_guess);
}

// Deities 201-216 by name; everything else, 396 included, is Agnostic (0xCB2).
// FUNCTION: TITANIUM 0x0049275D
char* GlobalState_guess::GetDeityDesc(int value_guess) {
    // The odd `<= 0x18c && != 0x18c` test is original.
    if ((value_guess <= 0x18c) && (value_guess != 0x18c)) {
        switch (value_guess) {
        case 0xc9:
            return g_stringTable_guess->Lookup_guess(0xcb3, 0);
        case 0xcd:
            return g_stringTable_guess->Lookup_guess(0xcb4, 0);
        case 0xcb:
            return g_stringTable_guess->Lookup_guess(0xcb5, 0);
        case 0xce:
            return g_stringTable_guess->Lookup_guess(0xcb6, 0);
        case 0xcf:
            return g_stringTable_guess->Lookup_guess(0xcb7, 0);
        case 0xcc:
            return g_stringTable_guess->Lookup_guess(0xcb8, 0);
        case 0xd0:
            return g_stringTable_guess->Lookup_guess(0xcb9, 0);
        case 0xd4:
            return g_stringTable_guess->Lookup_guess(0xcba, 0);
        case 0xd1:
            return g_stringTable_guess->Lookup_guess(0xcbb, 0);
        case 0xd2:
            return g_stringTable_guess->Lookup_guess(0xcbc, 0);
        case 0xd5:
            return g_stringTable_guess->Lookup_guess(0xcbd, 0);
        case 0xca:
            return g_stringTable_guess->Lookup_guess(0xcbe, 0);
        case 0xd6:
            return g_stringTable_guess->Lookup_guess(0xcbf, 0);
        case 0xd7:
            return g_stringTable_guess->Lookup_guess(0xcc0, 0);
        case 0xd8:
            return g_stringTable_guess->Lookup_guess(0xcc1, 0);
        case 0xd3:
            return g_stringTable_guess->Lookup_guess(0xcc2, 0);
        }
    }
    return g_stringTable_guess->Lookup_guess(0xcb2, 0);
}

// Innate ability names (Awareness, Bash Door, Breathe Fire ...) for the skills window; 0 or > 15
// is an empty string.
// FUNCTION: TITANIUM 0x00492874
char* GlobalState_guess::GetInnateDesc_guess(int value_guess) {
    switch (value_guess) {
    case 1:
        return g_stringTable_guess->Lookup_guess(0x19d1, 0);
    case 2:
        return g_stringTable_guess->Lookup_guess(0x19d2, 0);
    case 3:
        return g_stringTable_guess->Lookup_guess(0x19d7, 0);
    case 4:
        return g_stringTable_guess->Lookup_guess(0x19d8, 0);
    case 5:
        return g_stringTable_guess->Lookup_guess(0x19ce, 0);
    case 6:
        return g_stringTable_guess->Lookup_guess(0x19d9, 0);
    case 7:
        return g_stringTable_guess->Lookup_guess(0x19cd, 0);
    case 8:
        return g_stringTable_guess->Lookup_guess(0x19da, 0);
    case 9:
        return g_stringTable_guess->Lookup_guess(0x19db, 0);
    case 10:
        return g_stringTable_guess->Lookup_guess(0x19dc, 0);
    case 11:
        return g_stringTable_guess->Lookup_guess(0x19cc, 0);
    case 12:
        return g_stringTable_guess->Lookup_guess(0x19dd, 0);
    case 13:
        return g_stringTable_guess->Lookup_guess(0x19de, 0);
    case 14:
        return g_stringTable_guess->Lookup_guess(0x2142, 0);
    case 15:
        return g_stringTable_guess->Lookup_guess(0x2143, 0);
    default:
        return g_text_0063f53f_guess;
    }
}

// EXTERNAL: TITANIUM 0x00473CC3 ConvertNameToLocal_guess
void __cdecl ConvertNameToLocal_guess(char* text_guess);

struct NameCleaner_guess {
    char* StripShipName_guess(const char* source_guess, char* destination_guess);
};

// Drops digits and '#' from a name (UTF-8 aware).
// FUNCTION: TITANIUM 0x00492E6E
char* NameCleaner_guess::StripShipName_guess(const char* source_guess,
    char* destination_guess) {
    char* output_guess = destination_guess;
    while (*source_guess != 0) {
        unsigned int ch_guess;
        unsigned int size_guess = FUN_00574510_guess(source_guess, &ch_guess);
        if (_iswdigit(ch_guess) == 0 && (unsigned short)ch_guess != '#') {
            memcpy(output_guess, source_guess, size_guess);
            output_guess += size_guess;
        }
        source_guess += size_guess;
    }
    *output_guess = 0;
    return destination_guess;
}

// Display form of a spawn name: digits and '#' dropped, '_' -> ' '. Writes into one of 64 rotating
// buffers so a caller can hold several results at once.
// FUNCTION: TITANIUM 0x00492EC2
char* GlobalState_guess::trimName_guess(const char* text_guess) {
    int index_guess = ringIndex_guess;
    char* result_guess = ringSlots_guess[index_guess];
    ringIndex_guess = (index_guess + 1) % 0x40;
    char* output_guess = result_guess;
    const char* current_guess = text_guess;
    while (*current_guess != 0) {
        unsigned int ch_guess;
        unsigned int size_guess = FUN_00574510_guess(current_guess, &ch_guess);
        if (_iswdigit(ch_guess) == 0 && (unsigned short)ch_guess != '#') {
            if ((unsigned short)ch_guess == '_') {
                *output_guess = ' ';
                ++output_guess;
            } else {
                memcpy(output_guess, current_guess, size_guess);
                output_guess += size_guess;
            }
        }
        current_guess += size_guess;
    }
    *output_guess = 0;
    ConvertNameToLocal_guess(result_guess);
    return result_guess;
}

// Clears the outgoing chat text (+0x17BB4), in game (state 5) only.
// FUNCTION: TITANIUM 0x00492F52
void LargeObject_guess::ClearChatText_guess() {
    if (g_globalState_guess->state_guess == 5) {
        field_17bb4_guess = 0;
    }
}

struct PlayerName_guess {
    // EXTERNAL: TITANIUM 0x004793B5 PlayerName_guess::FUN_004793b5_guess
    char* FUN_004793b5_guess();
};

#define g_percentSpawns_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)

// Expands chat shortcuts in place: %t target, %m pet, %s/%o/%p target pronouns, %r race. Only a '%'
// at the start or after a space or apostrophe counts; with `flags` set other '%' become '&PCT;'.
// FUNCTION: TITANIUM 0x00492F68
// @early-stop: budget, structural ndiff=187
void GlobalState_guess::DoPercentConvert_guess(const char* text_guess, int flags_guess) {
    char buffer_guess[2048];
    EQPlayer* entry_guess;
    char* percent_guess;
    int replaced_guess = 0;
    for (percent_guess = strchr(text_guess, '%'); percent_guess != 0;
        percent_guess = strchr(percent_guess, '%')) {
        int length_guess = percent_guess - text_guess;
        ++percent_guess;
        bool expanded_guess = true;
        const char* rest_guess;
        if (length_guess <= 1 || text_guess[length_guess - 1] == ' ' ||
            text_guess[length_guess - 1] == '\'') {
            if (replaced_guess > 10) {
                // After 10 expansions a '%' is turned into '@' rather than expanded.
                const_cast<char*>(text_guess)[length_guess] = '@';
                continue;
            }
            char code_guess = text_guess[length_guess + 1];
            if (code_guess == 't' || code_guess == 'T') {
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                if (pinstTarget != 0) {
                    strcat(buffer_guess,
                        ((PlayerName_guess*)pinstTarget)->FUN_004793b5_guess());
                } else {
                    strcat(buffer_guess, "Target");
                }
            } else if (code_guess == 'm' || code_guess == 'M') {
                entry_guess = g_percentSpawns_guess;
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                while (entry_guess != 0 &&
                    entry_guess->MasterID != pinstLocalPlayer->SpawnID) {
                    entry_guess = entry_guess->pNext;
                }
                if (entry_guess != 0) {
                    strcat(buffer_guess,
                        ((PlayerName_guess*)entry_guess)->FUN_004793b5_guess());
                } else {
                    strcat(buffer_guess, "Pet");
                }
            } else if (code_guess == 's' || code_guess == 'S') {
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                if (pinstTarget != 0) {
                    switch (pinstTarget->Gender) {
                    case 1:
                        strcat(buffer_guess, pStringTable->getString(0x2fb2, 0));
                        break;
                    case 0:
                        strcat(buffer_guess, pStringTable->getString(0x2fb1, 0));
                        break;
                    default:
                        strcat(buffer_guess, pStringTable->getString(0x2fb3, 0));
                        break;
                    }
                } else {
                    strcat(buffer_guess, pStringTable->getString(0x2fb3, 0));
                }
            } else if (code_guess == 'o' || code_guess == 'O') {
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                if (pinstTarget != 0) {
                    switch (pinstTarget->Gender) {
                    case 1:
                        strcat(buffer_guess, pStringTable->getString(0x300a, 0));
                        break;
                    case 0:
                        strcat(buffer_guess, pStringTable->getString(0x3009, 0));
                        break;
                    default:
                        strcat(buffer_guess, pStringTable->getString(0x1a6e, 0));
                        break;
                    }
                } else {
                    strcat(buffer_guess, pStringTable->getString(0x1a6e, 0));
                }
            } else if (code_guess == 'p' || code_guess == 'P') {
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                if (pinstTarget != 0) {
                    switch (pinstTarget->Gender) {
                    case 1:
                        strcat(buffer_guess, pStringTable->getString(0x300b, 0));
                        break;
                    case 0:
                        strcat(buffer_guess, pStringTable->getString(0x300d, 0));
                        break;
                    default:
                        strcat(buffer_guess, pStringTable->getString(0x300c, 0));
                        break;
                    }
                } else {
                    strcat(buffer_guess, pStringTable->getString(0x300c, 0));
                }
            } else if (code_guess == 'r' || code_guess == 'R') {
                strncpy(buffer_guess, text_guess, length_guess);
                buffer_guess[length_guess] = 0;
                if (pinstTarget != 0) {
                    if (pinstTarget->Type == 0) {
                        strcat(buffer_guess, (char*)g_globalState_guess->GetRaceDesc(
                            pinstTarget->Race));
                    } else if (pinstTarget->Type == 2) {
                        strcat(buffer_guess, pStringTable->getString(0x1a6f, 0));
                    } else {
                        strcat(buffer_guess, pStringTable->getString(0x1a70, 0));
                    }
                } else {
                    strcat(buffer_guess, pStringTable->getString(0x1a71, 0));
                }
            } else {
                expanded_guess = false;
            }
        } else {
            expanded_guess = false;
        }
        if (expanded_guess) {
            rest_guess = text_guess + length_guess + 2;
            strcat(buffer_guess, rest_guess);
            strcpy(const_cast<char*>(text_guess), buffer_guess);
            ++replaced_guess;
            text_guess = rest_guess;
        } else if ((char)flags_guess != 0) {
            strncpy(buffer_guess, text_guess, length_guess);
            buffer_guess[length_guess] = 0;
            strcat(buffer_guess, "&PCT;");
            rest_guess = text_guess + length_guess + 1;
            strcat(buffer_guess, rest_guess);
            strcpy(const_cast<char*>(text_guess), buffer_guess);
            text_guess = rest_guess;
        }
    }
}

// Copy constructor of the 0x38-byte motion block (position, speed, run speed, heading and the rest): all
// 14 dwords, including +0x30 and +0x34, which the reset 0x004519AC leaves alone.
// FUNCTION: TITANIUM 0x00494593
PlayerMotion_guess::PlayerMotion_guess(const PlayerMotion_guess& source_guess) {
    field00_guess = source_guess.field00_guess;
    field04_guess = source_guess.field04_guess;
    field08_guess = source_guess.field08_guess;
    field0c_guess = source_guess.field0c_guess;
    field10_guess = source_guess.field10_guess;
    field14_guess = source_guess.field14_guess;
    field18_guess = source_guess.field18_guess;
    field1c_guess = source_guess.field1c_guess;
    field20_guess = source_guess.field20_guess;
    field24_guess = source_guess.field24_guess;
    field28_guess = source_guess.field28_guess;
    field2c_guess = source_guess.field2c_guess;
    field30_guess = source_guess.field30_guess;
    field34_guess = source_guess.field34_guess;
}

// Mouse-button handler: while mouse-look is engaged (0x00923842), sets the flag at 0x009237B7.
// FUNCTION: TITANIUM 0x004945EE
void FlagSetter_guess::LMouseDown_guess(unsigned int first_guess, unsigned int second_guess) {
    if (g_flag_00923842_guess != 0) {
        g_flag_009237b7_guess = 1;
    }
}

struct CursorInput_guess {
    char padding_0000_guess[0x1E2];
    bool field1e2_guess; // 0x1E2
};

// POINT with constructors: the position is stored through a constructed temporary (match shape).
struct CursorPoint_guess {
    int x_guess;
    int y_guess;
    CursorPoint_guess() {}
    CursorPoint_guess(int x, int y) : x_guess(x), y_guess(y) {}
};

struct CursorPosition_guess {
    char padding_0000_guess[0x110];
    POINT position_guess; // 0x110
};

#define g_cursorMode_guess EQ_GLOBAL(int, 0x00850508)
#define g_cursorState_guess EQ_GLOBAL(bool, 0x009237B8)
#define g_cursorInput_guess EQ_GLOBAL(CursorInput_guess*, 0x00850B9C)
#define g_cursorPosition_guess EQ_GLOBAL(CursorPosition_guess*, 0x0099D3EC)

// Right-button press: in game, or char select with the matching mouse state, hides the cursor and
// remembers its position for mouse look.
// FUNCTION: TITANIUM 0x00494601
void GlobalState_guess::RMouseDown_guess(int x_guess, int y_guess) {
    POINT point_guess;
    if (g_clockData_guess->GetValue2cf8_guess() != 0 && g_flag_00923842_guess == 0) {
        if (g_cursorMode_guess == 3) {
            g_flag_00923842_guess = g_cursorState_guess;
        } else {
            g_clockData_guess->field12_guess = 0;
            g_flag_00923842_guess = g_cursorState_guess;
            if (g_cursorState_guess &&
                ((g_globalState_guess->state_guess == 1 &&
                  g_cursorInput_guess->field1e2_guess == 1) ||
                 g_globalState_guess->state_guess == 5)) {
                while (ShowCursor(0) >= 0) {
                }
                GetCursorPos(&point_guess);
                *(CursorPoint_guess*)&g_cursorPosition_guess->position_guess =
                    CursorPoint_guess(point_guess.x, point_guess.y);
            }
        }
    }
}

struct FadePlayerMinimum_guess {
    char padding_0000_guess[0x4c];
    float value_guess; // 0x4C
};

struct FadePlayerActorData_guess {
    char padding_0000_guess[0x12c];
    FadePlayerMinimum_guess* minimum_guess; // 0x12C
};

struct FadeTargetSettings_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess(float value_guess);
    virtual void Slot06_guess(float value_guess);
    char padding_0004_guess[0x2c];
    float field30_guess; // 0x30
    float field34_guess; // 0x34
};

struct FadeAgeSource_guess {
    // EXTERNAL: TITANIUM 0x005ED550 FadeAgeSource_guess::FUN_005ed550_guess
    int FUN_005ed550_guess();
};

struct FadeDisplayState_guess {
    // EXTERNAL: TITANIUM 0x004392DE FadeDisplayState_guess::SetCameraMode_guess
    void SetCameraMode_guess(int value_guess);
};

#define g_fadeTargetSettings_guess EQ_GLOBAL(FadeTargetSettings_guess*, 0x00925514)
#define g_fadeAgeSource_guess EQ_GLOBAL(FadeAgeSource_guess*, 0x00905D00)
#define g_fadeDisplayState_guess EQ_GLOBAL(FadeDisplayState_guess*, 0x00905D24)
#define g_fadeEnabled_guess EQ_GLOBAL(int, 0x009254BC)

// Wheel zoom: steps the wanted camera distance by 1 (5 when scrolling fast) between the model's
// minimum and 53, then eases toward it. Zooming fully in goes first person (camera 0); out, chase (6).
// FUNCTION: TITANIUM 0x004946AC
// @early-stop: tiebreak, structural ndiff=434
void GlobalState_guess::MouseWheelScrolled_guess(int direction_guess) {
    static unsigned int s_lastFrame_guess = FUN_0046d655_guess();
    static unsigned int s_lastStep_guess = FUN_0046d655_guess();

    float target_guess = g_fadeTargetSettings_guess->field34_guess;
    float minimum_guess = 3.0f;
    if (g_displayPlayer_guess != 0 && g_displayPlayer_guess->pActorInfo != 0) {
        FadePlayerMinimum_guess* source_guess = reinterpret_cast<FadePlayerActorData_guess*>(
            g_displayPlayer_guess->pActorInfo)->minimum_guess;
        if (source_guess != 0) {
            minimum_guess = source_guess->value_guess;
        }
    }

    float elapsed_guess = (float)(FUN_0046d655_guess() - s_lastFrame_guess) * 0.001f;
    s_lastFrame_guess = FUN_0046d655_guess();

    if (g_clockData_guess->GetValue2cf8_guess() == 0) {
        fieldb5c_guess = target_guess;
        return;
    }

    if (g_globalState_guess->state_guess == 1 || (g_pilotMode_guess != 6 && g_pilotMode_guess != 0)) {
        g_fadeTargetSettings_guess->Slot06_guess(0.0f);
        fieldb5c_guess = 0.0f;
        return;
    }

    if (g_fadeAgeSource_guess == 0 || g_fadeAgeSource_guess->FUN_005ed550_guess() >= 0x46) {
        g_fadeTargetSettings_guess->Slot06_guess(minimum_guess);
        fieldb5c_guess = minimum_guess;
        return;
    }

    if (g_fadeEnabled_guess == 0) {
        if (g_pilotMode_guess == 6) {
            g_fadeTargetSettings_guess->Slot06_guess(minimum_guess);
            fieldb5c_guess = minimum_guess;
            g_fadeDisplayState_guess->SetCameraMode_guess(0);
            if (g_displayPlayer_guess != 0) {
                g_displayPlayer_guess->CameraAngle = 0.0f;
            }
        }
        return;
    }

    float step_guess;
    if (direction_guess > 0) {
        step_guess = 1.0f;
        if (FUN_0046d655_guess() - s_lastStep_guess < 50) {
            step_guess = 5.0f;
        }
        s_lastStep_guess = FUN_0046d655_guess();
        fieldb5c_guess = (fieldb5c_guess < target_guess ? fieldb5c_guess : target_guess) - step_guess;
        if (fieldb5c_guess < 0.0f) {
            fieldb5c_guess = 0.0f;
        }
    } else if (direction_guess < 0) {
        step_guess = 1.0f;
        if (FUN_0046d655_guess() - s_lastStep_guess < 50) {
            step_guess = 5.0f;
        }
        s_lastStep_guess = FUN_0046d655_guess();
        fieldb5c_guess = (fieldb5c_guess > target_guess ? fieldb5c_guess : target_guess) + step_guess;
        if (fieldb5c_guess > 53.0f) {
            fieldb5c_guess = 53.0f;
        }
        if (fieldb5c_guess < minimum_guess) {
            fieldb5c_guess = minimum_guess;
        }
    }

    float speed_guess = 100.0f;
    double difference_guess = fabs(fieldb5c_guess - target_guess);
    if (difference_guess < 5.0f) {
        speed_guess = difference_guess * 0.2f * 90.0f + 10.0f;
    }
    speed_guess *= elapsed_guess;

    if (target_guess > fieldb5c_guess) {
        if (g_pilotMode_guess == 6) {
            if (target_guess > minimum_guess) {
                target_guess -= speed_guess;
                if (target_guess < minimum_guess) {
                    target_guess = minimum_guess;
                } else if (target_guess < fieldb5c_guess) {
                    target_guess = fieldb5c_guess;
                }
            } else {
                target_guess = 0.0f;
                g_fadeDisplayState_guess->SetCameraMode_guess(0);
                if (g_displayPlayer_guess != 0) {
                    g_displayPlayer_guess->CameraAngle = g_fadeTargetSettings_guess->field30_guess;
                }
            }
        }
    } else if (target_guess < fieldb5c_guess) {
        if (g_pilotMode_guess == 6) {
            if (target_guess < 53.0f) {
                target_guess += speed_guess;
                if (target_guess > 53.0f) {
                    target_guess = 53.0f;
                } else if (target_guess > fieldb5c_guess) {
                    target_guess = fieldb5c_guess;
                }
                if (target_guess < minimum_guess) {
                    target_guess = minimum_guess;
                }
            }
        } else if (g_pilotMode_guess == 0) {
            target_guess = minimum_guess;
            g_fadeDisplayState_guess->SetCameraMode_guess(6);
            if (g_displayPlayer_guess != 0) {
                g_fadeTargetSettings_guess->Slot05_guess(g_displayPlayer_guess->CameraAngle);
            }
        }
    } else {
        return;
    }
    g_fadeTargetSettings_guess->Slot06_guess(target_guess);
}

// Returns the spawn whose actor was picked at the screen point, or null.
// FUNCTION: TITANIUM 0x00494AC5
EQPlayer* GlobalState_guess::ClickedPlayer(int first_guess, int second_guess) {
    int firstOutput_guess[3];
    int secondOutput_guess[3];
    int result_guess = g_clockData_guess->PickActorAt_guess(
        first_guess, second_guess, 0, firstOutput_guess, secondOutput_guess);
    if (result_guess != 0) {
        result_guess = reinterpret_cast<int>(FindSpawnByActor_guess(result_guess));
    }
    return reinterpret_cast<EQPlayer*>(result_guess);
}

// Tells the sound manager the current zone's short name.
// FUNCTION: TITANIUM 0x00494AF5
void __cdecl UpdateSoundZone_guess() {
    char output_guess[32];
    g_lookupManager_guess->FUN_005f6ed0_guess(
        *reinterpret_cast<int*>(reinterpret_cast<char*>(g_contextObject_guess) +
            g_contextObject_guess->field08_guess->field04_guess + 0x108),
        output_guess);
    g_textProcessor_guess->SetCurrentZone_guess(output_guess);
}

// Stores the game state (5 = in game) and turns on the key bindings that state allows
// (commands 0x105..0x10A, 0xB9, 0x101).
// FUNCTION: TITANIUM 0x00494B3D
void GlobalState_guess::SetGameState(int value_guess) {
    state_guess = value_guess;
    switch (value_guess) {
    case 5:
        EnableAllCommands_guess();
        DisableCommand_guess(0x105);
        DisableCommand_guess(0x106);
        DisableCommand_guess(0x107);
        DisableCommand_guess(0x108);
        DisableCommand_guess(0x10a);
        DisableCommand_guess(0x109);
        break;
    case 2:
        DisableAllCommands_guess();
        EnableCommand_guess(0x10a);
        EnableCommand_guess(0x109);
        EnableCommand_guess(0xb9);
        EnableCommand_guess(0x101);
        break;
    case 1:
        DisableAllCommands_guess();
        EnableCommand_guess(0x105);
        EnableCommand_guess(0x106);
        EnableCommand_guess(0x107);
        EnableCommand_guess(0x108);
        EnableCommand_guess(0xb9);
        EnableCommand_guess(0x101);
        break;
    }
}

// False while +0x68 is set, a timed action or request is pending (0x923994, 0x9248D4, 0x9248D0),
// or any trade, merchant, bank, loot or similar window is open. On a vehicle, true only for a boat (0x8D).
// FUNCTION: TITANIUM 0x00494C09
char IsOkToTransact_guess() {
    ResetState_guess* state_guess = g_resetOwner_guess->pActorInfo_01a8_guess;
    if (state_guess->value158_guess != 0) {
        return state_guess->value158_guess->field260_guess == 0x8d;
    }
    if (state_guess->field68_guess != 0 ||
        g_value_00923994_guess != 0 ||
        g_value_009248d4_guess != 0 ||
        g_value_009248d0_guess != 0 ||
        (pinstCContainerMgr_guess != 0 &&
         pinstCContainerMgr_guess->attached_06C_guess != 0) ||
        (pinstCSpellBookWnd_guess != 0 &&
         pinstCSpellBookWnd_guess->IsVisible_guess() != 0) ||
        (pinstCTrainWnd_guess != 0 && pinstCTrainWnd_guess->IsVisible_guess() != 0) ||
        (pinstCBazaarWnd_guess != 0 &&
         pinstCBazaarWnd_guess->IsVisible_guess() != 0) ||
        (pinstCBarterWnd_guess != 0 &&
         pinstCBarterWnd_guess->IsVisible_guess() != 0) ||
        (pinstCTradeWnd_guess != 0 &&
         pinstCTradeWnd_guess->IsVisible_guess() != 0) ||
        (g_status_00850c38_guess != 0 &&
         g_status_00850c38_guess->FUN_0059dd30_guess() != 0) ||
        (pinstCMerchantWnd_guess != 0 &&
         pinstCMerchantWnd_guess->IsVisible_guess() != 0) ||
        (pinstCLootWnd_guess != 0 &&
         pinstCLootWnd_guess->IsVisible_guess() != 0) ||
        (pinstCBarterMerchantWnd_guess != 0 &&
         pinstCBarterMerchantWnd_guess->IsVisible_guess() != 0) ||
        (g_status_00991a90_guess != 0 &&
         g_status_00991a90_guess->FUN_0059dd30_guess() != 0)) {
        return false;
    }
    return true;
}

// Sorts the 10 records of 0x40 bytes at 0x984804 (cleared by initCustom) and marks each for saving.
// FUNCTION: TITANIUM 0x00494DA9
void SortedRecordsA_guess::Sort_guess() {
    _qsort(g_sortRecords_00984804_guess, 10, 0x40,
        reinterpret_cast<int (__cdecl *)(const void*, const void*)>(g_sortCompare_00494d41_guess));
    unsigned char* record_guess = g_sortFlags_00984842_guess;
    do {
        *record_guess = 1;
        record_guess += 0x40;
    } while ((int)record_guess < (int)g_sortEnd_00984ac2_guess);
    SaveSpellLoadouts_guess();
}

// The same for the 10 records of 0x20 bytes at 0x984A84.
// FUNCTION: TITANIUM 0x00494DDC
void SortedRecordsB_guess::Sort_guess() {
    _qsort(g_sortRecords_00984a84_guess, 10, 0x20,
        reinterpret_cast<int (__cdecl *)(const void*, const void*)>(g_sortCompare_00494d79_guess));
    unsigned char* record_guess = g_sortFlags_00984a9e_guess;
    do {
        *record_guess = 1;
        record_guess += 0x20;
    } while ((int)record_guess < (int)g_sortEnd_00984bde_guess);
    SaveHotbuttonLoadouts_guess();
}

// 0x511 bytes. Slot N's tail byte is the first byte of slot N+1, so the zero loop walks the tails.
struct SlotRecord_guess {
    unsigned char tail_guess;   // 0x00
    char name_guess[0x10];      // 0x01
    char text_guess[5][0x100];  // 0x11
};

struct SlotEntry_guess {
    unsigned char flag_guess;   // 0x00
    int value_guess;            // 0x04
};

#define g_slots_0095d4d3_guess EQ_ARRAY(SlotRecord_guess, 0x0095D4D3)
#define g_slotEnd_009839dc_guess EQ_ARRAY(SlotRecord_guess, 0x009839DC)
#define g_rowFlags_0095d45c_guess EQ_ARRAY(unsigned char, 0x0095D45C)
#define g_bytes_009839e5_guess EQ_ARRAY(unsigned char, 0x009839E5)
#define g_bytesEnd_00983b75_guess EQ_ARRAY(unsigned char, 0x00983B75)
#define g_entries_00983b7c_guess EQ_ARRAY(SlotEntry_guess, 0x00983B7C)
#define g_words_0095d414_guess EQ_ARRAY(unsigned int, 0x0095D414)
#define g_flag_00985708_guess EQ_GLOBAL(unsigned char, 0x00985708)

// Clears the socials and the 10x10 hotbutton table, then fills empty page-1 socials with the 12
// defaults (names eqstr 0x19FC.., commands 0x1A08..).
// FUNCTION: TITANIUM 0x00494E0F
// @early-stop: budget, structural ndiff=70
void initCustom_guess() {
    unsigned char* flags_guess = g_sortFlags_00984842_guess;
    do {
        flags_guess[-1] = 0;
        *flags_guess = 0;
        flags_guess += 0x40;
    } while ((int)flags_guess < (int)g_sortEnd_00984ac2_guess);
    flags_guess = g_sortFlags_00984a9e_guess;
    do {
        flags_guess[-1] = 0;
        *flags_guess = 0;
        flags_guess += 0x20;
    } while ((int)flags_guess < (int)g_sortEnd_00984bde_guess);

    unsigned char* row_guess = g_rowFlags_0095d45c_guess;
    SlotRecord_guess* slot_guess = g_slots_0095d4d3_guess;
    do {
        for (int col_guess = 0; col_guess < 12; ++col_guess) {
            slot_guess->name_guess[0] = 0;
            slot_guess[1].tail_guess = 0;
            char* text_guess = slot_guess->text_guess[0];
            for (int i_guess = 5; i_guess != 0; --i_guess) {
                *text_guess = 0;
                text_guess += 0x100;
            }
            *row_guess++ = 0;
            ++slot_guess;
        }
    } while ((int)&slot_guess[1] < (int)g_slotEnd_009839dc_guess);

    SlotEntry_guess* entry_guess = g_entries_00983b7c_guess;
    unsigned char* bytes_guess = g_bytes_009839e5_guess;
    do {
        for (int row_i = 10; row_i != 0; --row_i) {
            for (int col_i = 0; col_i < 10; ++col_i) {
                entry_guess->flag_guess = 0;
                entry_guess->value_guess = -1;
                bytes_guess[col_i] = 0;
                ++entry_guess;
            }
            bytes_guess += 10;
        }
    } while ((int)bytes_guess < (int)g_bytesEnd_00983b75_guess);

    unsigned int* words_guess = g_words_0095d414_guess;
    *words_guess++ = 0xFFFFFFFF;
    *words_guess++ = 0xFFFFFFFF;
    *words_guess++ = 0xFFFFFFFF;
    *words_guess++ = 0xFFFFFFFF;
    words_guess = &g_words_0095d414_guess[4];
    for (int i_guess = 6; i_guess != 0; --i_guess) {
        *words_guess++ = 0xFFFFFFFF;
    }
    words_guess = &g_words_0095d414_guess[10];
    for (int i_guess = 8; i_guess != 0; --i_guess) {
        *words_guess++ = 0xFFFFFFFF;
    }
    g_flag_00985708_guess = 0;

    if (g_slots_0095d4d3_guess[0].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[0].name_guess, pStringTable->getString(0x19fc, 0));
        strcpy(g_slots_0095d4d3_guess[0].text_guess[0], pStringTable->getString(0x1a08, 0));
        g_slots_0095d4d3_guess[1].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[1].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[1].name_guess, pStringTable->getString(0x19fd, 0));
        strcpy(g_slots_0095d4d3_guess[1].text_guess[0], pStringTable->getString(0x1a09, 0));
        g_slots_0095d4d3_guess[2].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[2].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[2].name_guess, pStringTable->getString(0x19fe, 0));
        strcpy(g_slots_0095d4d3_guess[2].text_guess[0], pStringTable->getString(0x1a0a, 0));
        g_slots_0095d4d3_guess[3].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[3].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[3].name_guess, pStringTable->getString(0x19ff, 0));
        strcpy(g_slots_0095d4d3_guess[3].text_guess[0], pStringTable->getString(0x1a0b, 0));
        g_slots_0095d4d3_guess[4].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[4].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[4].name_guess, pStringTable->getString(0x1a00, 0));
        strcpy(g_slots_0095d4d3_guess[4].text_guess[0], pStringTable->getString(0x1a0c, 0));
        g_slots_0095d4d3_guess[5].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[5].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[5].name_guess, pStringTable->getString(0x1a01, 0));
        strcpy(g_slots_0095d4d3_guess[5].text_guess[0], pStringTable->getString(0x1a0d, 0));
        g_slots_0095d4d3_guess[6].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[6].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[6].name_guess, pStringTable->getString(0x1a02, 0));
        strcpy(g_slots_0095d4d3_guess[6].text_guess[0], pStringTable->getString(0x1a0e, 0));
        g_slots_0095d4d3_guess[7].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[7].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[7].name_guess, pStringTable->getString(0x1a03, 0));
        strcpy(g_slots_0095d4d3_guess[7].text_guess[0], pStringTable->getString(0x1a0f, 0));
        g_slots_0095d4d3_guess[8].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[8].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[8].name_guess, pStringTable->getString(0x1a04, 0));
        strcpy(g_slots_0095d4d3_guess[8].text_guess[0], pStringTable->getString(0x1a10, 0));
        g_slots_0095d4d3_guess[9].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[9].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[9].name_guess, pStringTable->getString(0x1a05, 0));
        strcpy(g_slots_0095d4d3_guess[9].text_guess[0], pStringTable->getString(0x1a11, 0));
        g_slots_0095d4d3_guess[10].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[10].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[10].name_guess, pStringTable->getString(0x1a06, 0));
        strcpy(g_slots_0095d4d3_guess[10].text_guess[0], pStringTable->getString(0x1a12, 0));
        g_slots_0095d4d3_guess[11].tail_guess = 0;
    }
    if (g_slots_0095d4d3_guess[11].name_guess[0] == 0) {
        strcpy(g_slots_0095d4d3_guess[11].name_guess, pStringTable->getString(0x1a07, 0));
        strcpy(g_slots_0095d4d3_guess[11].text_guess[0], pStringTable->getString(0x1a13, 0));
        g_slots_0095d4d3_guess[12].tail_guess = 0;
    }
}

struct CleanupObject_guess {
    // EXTERNAL: TITANIUM 0x00424EF2 CleanupObject_guess::FUN_00424ef2_guess
    void FUN_00424ef2_guess();
};

#define g_cleanupObject_guess EQ_GLOBAL(CleanupObject_guess*, 0x0079DBD8)

struct ManagedObject_guess {
    char storage_guess[0xA0];
    // EXTERNAL: TITANIUM 0x0042C972 ManagedObject_guess::SetMailboxes_guess
    void SetMailboxes_guess(int first_guess, int second_guess, int* values_guess);
    // EXTERNAL: TITANIUM 0x0042B428 ManagedObject_guess::Set_guess
    void Set_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004275C7 ManagedObject_guess::At_guess
    std::string At_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x0042C115 ManagedObject_guess::ManagedObject_guess
    ManagedObject_guess();
    // EXTERNAL: TITANIUM 0x0042C1B2 ManagedObject_guess::FUN_0042c1b2_guess
    void FUN_0042c1b2_guess();
    // EXTERNAL: TITANIUM 0x0042B466 ManagedObject_guess::AddHeader_guess
    void AddHeader_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
        int p5_guess, int p6_guess, int p7_guess, int p8_guess);
    // EXTERNAL: TITANIUM 0x0042B557 ManagedObject_guess::NotifyNewMail_guess
    void NotifyNewMail_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
        int p5_guess, int p6_guess);
    // EXTERNAL: TITANIUM 0x0042CA9A ManagedObject_guess::FUN_0042ca9a_guess
    void FUN_0042ca9a_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess);
};

struct SlotOwner_guess {
    char padding_0000_guess[0x3A1C4];
    ManagedObject_guess* field3a1c4_guess;
    ManagedObject_guess* GetMailManager_guess();
    void DeleteMailManager_guess();
};

// Creates the mail list on first use, and only while mail is enabled (0x923D65).
// FUNCTION: TITANIUM 0x00495250
ManagedObject_guess* SlotOwner_guess::GetMailManager_guess() {
    if (EQ_GLOBAL(unsigned char, 0x00923D65) != 0 && field3a1c4_guess == 0) {
        field3a1c4_guess = new ManagedObject_guess;
    }
    return field3a1c4_guess;
}

// Unlinks this node from its neighbours (the links point at the owning items, whose node starts at +4) and
// clears its previous, next and list fields.
// FUNCTION: TITANIUM 0x004952B6
void LinkedNode_guess::Unlink_guess() {
    if (field00_guess != 0) {
        field00_guess->field08_guess = field04_guess;
    }
    if (field04_guess != 0) {
        field04_guess->field04_guess = field00_guess;
    }
    field04_guess = 0;
    field00_guess = 0;
    field08_guess = 0;
}

// x to an integer power by squaring; MoveMoney uses it for powers of 10.
// FUNCTION: TITANIUM 0x004952DB
double __cdecl IntPow_guess(double base_guess, int exponent_guess) {
    unsigned int power_guess = exponent_guess;
    if (exponent_guess < 0) {
        power_guess = -exponent_guess;
    }
    double result_guess = 1.0;
    for (;;) {
        if (power_guess & 1) {
            result_guess *= base_guess;
        }
        power_guess >>= 1;
        if (power_guess == 0) {
            break;
        }
        base_guess *= base_guess;
    }
    if (exponent_guess < 0) {
        result_guess = 1.0 / result_guess;
    }
    return result_guess;
}

// Deletes the network connection manager (0x00424EF2 first shuts its UDP manager down) and clears the
// pointer.
// FUNCTION: TITANIUM 0x0049530C
void DestroyConnectionManager_guess() {
    CleanupObject_guess* memory_guess = g_cleanupObject_guess;
    if (g_cleanupObject_guess != 0) {
        g_cleanupObject_guess->FUN_00424ef2_guess();
        free(memory_guess);
    }
    g_cleanupObject_guess = 0;
}

struct CopiedBlock_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0c_guess;
    int field10_guess;
    int field14_guess;
    int field18_guess;
    int field1c_guess;
    int field20_guess;
    int field24_guess;
    int field28_guess;
    int field2c_guess;
    int field30_guess;
    int field34_guess;
    int field38_guess;
    int field3c_guess;
    int field40_guess;
    int field44_guess;
    int field48_guess;
    int field4c_guess;
    int field50_guess;
    int field54_guess;
    int field58_guess;
    int field5c_guess;
    int field60_guess;
    int field64_guess;
    int field68_guess;
    int field6c_guess;
    int field70_guess;
    int field74_guess;
    int field78_guess;
    int field7c_guess;
    int field80_guess;
    CopiedBlock_guess(const CopiedBlock_guess& source_guess);
};

// Copy constructor for a particle-cloud definition (all dwords up to +0x80); emitter slots are
// instantiated from these copies.
// FUNCTION: TITANIUM 0x0049532E
CopiedBlock_guess::CopiedBlock_guess(const CopiedBlock_guess& source_guess)
    : field00_guess(source_guess.field00_guess),
      field04_guess(source_guess.field04_guess),
      field08_guess(source_guess.field08_guess),
      field0c_guess(source_guess.field0c_guess),
      field10_guess(source_guess.field10_guess),
      field14_guess(source_guess.field14_guess),
      field18_guess(source_guess.field18_guess),
      field1c_guess(source_guess.field1c_guess),
      field20_guess(source_guess.field20_guess),
      field24_guess(source_guess.field24_guess),
      field28_guess(source_guess.field28_guess),
      field2c_guess(source_guess.field2c_guess),
      field30_guess(source_guess.field30_guess),
      field34_guess(source_guess.field34_guess),
      field38_guess(source_guess.field38_guess),
      field3c_guess(source_guess.field3c_guess),
      field40_guess(source_guess.field40_guess),
      field44_guess(source_guess.field44_guess),
      field48_guess(source_guess.field48_guess),
      field4c_guess(source_guess.field4c_guess),
      field50_guess(source_guess.field50_guess),
      field54_guess(source_guess.field54_guess),
      field58_guess(source_guess.field58_guess),
      field5c_guess(source_guess.field5c_guess),
      field60_guess(source_guess.field60_guess),
      field64_guess(source_guess.field64_guess),
      field68_guess(source_guess.field68_guess),
      field6c_guess(source_guess.field6c_guess),
      field70_guess(source_guess.field70_guess),
      field74_guess(source_guess.field74_guess),
      field78_guess(source_guess.field78_guess),
      field7c_guess(source_guess.field7c_guess),
      field80_guess(source_guess.field80_guess) {
}

// Instantiates particle-cloud definition `nodeType` for one emitter slot, applying the slot's
// non-zero overrides (scale, offsets, colour ...). The instance is named '<name>_<obj>_<row>_<slot>_<def>'.
// FUNCTION: TITANIUM 0x00495AD4
// @early-stop: budget, structural ndiff=41
SpellNode_guess* __cdecl MakePCloudInstance_guess(TransferRecordA_guess* records_guess,
    int objectValue_guess, int mode_guess, int index_guess, int nodeType_guess,
    ActionPosition_guess* position_guess, int value7_guess) {
    int result_guess = 0;
    int sourceIndex_guess = nodeType_guess;
    CopiedBlock_guess* source_guess = g_copiedBlocks_00903ec0_guess[sourceIndex_guess];
    SlotRow_guess* rows_guess = reinterpret_cast<SlotRow_guess*>(records_guess);
    SlotBody_guess* slot_guess = &rows_guess[mode_guess].body_guess;
    if (source_guess == 0) {
        return 0;
    }
    {
        CopiedBlock_guess block_guess(*source_guess);
        if (slot_guess->f22c_guess[index_guess] != g_zeroFloat_0063f4cc_guess) {
            float value_guess = slot_guess->f22c_guess[index_guess];
            *reinterpret_cast<float*>(&block_guess.field10_guess) = value_guess;
            *reinterpret_cast<float*>(&block_guess.field14_guess) = value_guess;
            *reinterpret_cast<float*>(&block_guess.field18_guess) = value_guess;
        }
        SlotVec_guess* vec_guess = &slot_guess->vec238_guess[index_guess];
        if (vec_guess->x_guess != g_zeroFloat_0063f4cc_guess ||
            vec_guess->y_guess != g_zeroFloat_0063f4cc_guess ||
            vec_guess->z_guess != g_zeroFloat_0063f4cc_guess) {
            block_guess.field54_guess = *reinterpret_cast<int*>(&vec_guess->x_guess);
            block_guess.field58_guess = *reinterpret_cast<int*>(&vec_guess->y_guess);
            block_guess.field5c_guess = *reinterpret_cast<int*>(&vec_guess->z_guess);
        }
        if (slot_guess->f25c_guess[index_guess] != g_zeroFloat_0063f4cc_guess) {
            block_guess.field60_guess = *reinterpret_cast<int*>(&slot_guess->f25c_guess[index_guess]);
        }
        if (slot_guess->f268_guess[index_guess] != g_zeroFloat_0063f4cc_guess) {
            block_guess.field64_guess = *reinterpret_cast<int*>(&slot_guess->f268_guess[index_guess]);
        }
        if (slot_guess->i274_guess[index_guess] != 0) {
            block_guess.field68_guess = slot_guess->i274_guess[index_guess];
        }
        if (slot_guess->f280_guess[index_guess] != g_zeroFloat_0063f4cc_guess) {
            block_guess.field6c_guess = *reinterpret_cast<int*>(&slot_guess->f280_guess[index_guess]);
        }
        if (slot_guess->i28c_guess[index_guess] != 0) {
            block_guess.field70_guess = slot_guess->i28c_guess[index_guess];
        }
        if (slot_guess->f298_guess[index_guess] != g_zeroFloat_0063f4cc_guess) {
            block_guess.field74_guess = *reinterpret_cast<int*>(&slot_guess->f298_guess[index_guess]);
        }
        if (slot_guess->flags_guess[index_guess].bytes_guess[2] != 0 ||
            slot_guess->flags_guess[index_guess].bytes_guess[1] != 0 ||
            slot_guess->flags_guess[index_guess].bytes_guess[0] != 0) {
            block_guess.field7c_guess = slot_guess->flags_guess[index_guess].value_guess;
        }
        if (value7_guess != 0) {
            block_guess.field38_guess = value7_guess;
        }
        char buffer_guess[256];
        const char* name_guess = slot_guess->names_guess[index_guess].text_guess;
        _sprintf(buffer_guess, "%s_%d_%d_%d_%d", name_guess, objectValue_guess,
            mode_guess, index_guess, sourceIndex_guess);
        g_dispatch_0099e368_guess->Slot21_guess(buffer_guess, name_guess, &block_guess,
            (int)position_guess, &result_guess, 0, 0);
    }
    return reinterpret_cast<SpellNode_guess*>(result_guess);
}

struct WorldName_guess {
    void Read_guess(char* output_guess);
    void GetServerShortName_guess(char* output_guess);
};

struct LogContextText_guess {
    char padding_0000_guess[0x44];
    char text_guess[1];
};

struct ObjectVec_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    ObjectVec_guess() {
        z_guess = 0.0f;
        y_guess = 0.0f;
        x_guess = 0.0f;
    }
};

// EXTERNAL: TITANIUM 0x00649080 ??_7ObjectBase_guess@@6B@
struct ObjectBase_guess {
    virtual void Slot000_guess();
    ObjectVec_guess vecA_guess;
    ObjectVec_guess vecB_guess;
    ObjectVec_guess vecC_guess;
    char padding_0028_guess[0x1c];
    unsigned char field44_guess;
    unsigned char field45_guess;
    char padding_0046_guess[2];
    // EXTERNAL: TITANIUM 0x00491055 ObjectBase_guess::Reset_guess
    void Reset_guess();
    ObjectBase_guess();
};

// EXTERNAL: TITANIUM 0x00649080 ??_7Object_guess@@6B@
struct ObjectDtorAnchor_guess {
    ~ObjectDtorAnchor_guess() {}
};

struct Object_guess {
    ObjectDtorAnchor_guess anchor_guess;
    virtual ~Object_guess();
    Object_guess* Release_guess(unsigned char flags_guess);
};

// Base constructor (vtable 0x00649080): every field reset (0x00491055), then the bytes at +0x44 and
// +0x45 cleared.
// FUNCTION: TITANIUM 0x00495401
ObjectBase_guess::ObjectBase_guess() {
    Reset_guess();
    field44_guess = 0;
    field45_guess = 0;
}

// EXTERNAL: TITANIUM 0x00649470 ??_7ObjectHolder_guess@@6B@
struct ObjectHolder_guess : ObjectBase_guess {
    virtual void Slot000_guess();
    int field48_guess;
    ObjectHolder_guess();
};

// Constructor: the base, then +0x48 cleared (vtable 0x00649470).
// FUNCTION: TITANIUM 0x00495448
ObjectHolder_guess::ObjectHolder_guess() {
    field48_guess = 0;
}

// Scalar deleting destructor of the base object (vtable 0x00649080; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0049545E
Object_guess* Object_guess::Release_guess(unsigned char flags_guess) {
    this->Object_guess::~Object_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Empty destructor.
// FUNCTION: TITANIUM 0x0049547A
Object_guess::~Object_guess() {
}

// EXTERNAL: TITANIUM 0x006494B8 ??_7ObjectSlot_guess@@6B@
struct ObjectSlot_guess : ObjectBase_guess {
    virtual void Slot000_guess();
    int field48_guess;
    int field4c_guess;
    int field50_guess;
    ObjectSlot_guess();
};

// Constructor: the base, then +0x48, +0x4C and +0x50 cleared (vtable 0x006494B8).
// FUNCTION: TITANIUM 0x00495481
ObjectSlot_guess::ObjectSlot_guess() {
    field4c_guess = 0;
    field48_guess = 0;
    field50_guess = 0;
}

// Appends '[ctime] message' to the bazaar log, Logs/bzrlog_<world>_<character>.
// FUNCTION: TITANIUM 0x0049549E
void __cdecl WriteBazaarLog_guess(const char* message_guess) {
    int timestamp_guess;
    char line_guess[2048];
    char path_guess[256];
    char world_guess[64];

    timestamp_guess = _time32_guess(0);
    line_guess[0] = '[';
    line_guess[1] = 0;
    FUN_0060e460_guess(line_guess, _ctime_guess(&timestamp_guess));
    unsigned int length_guess = strlen(line_guess);
    if (line_guess[length_guess - 1] == '\n') {
        line_guess[length_guess - 1] = ']';
        line_guess[length_guess] = ' ';
        line_guess[length_guess + 1] = 0;
    } else {
        line_guess[length_guess] = ']';
        line_guess[length_guess + 1] = ' ';
        line_guess[length_guess + 2] = 0;
    }
    FUN_0060e460_guess(line_guess, message_guess);
    FUN_0060e460_guess(line_guess, EQ_ARRAY(char, 0x00641588));

    world_guess[0] = 0;
    FUN_00576ed0_guess("Logs");
    FUN_0060e450_guess(path_guess, "Logs\\bzrlog_");
    reinterpret_cast<WorldName_guess*>(g_globalState_guess)->GetServerShortName_guess(world_guess);
    FUN_0060e460_guess(path_guess, world_guess);
    FUN_0060e460_guess(path_guess, EQ_ARRAY(char, 0x0063FE48));

    ContextObject_guess* context_guess = g_contextObject_guess;
    if (context_guess == 0 ||
        reinterpret_cast<LogContextText_guess*>(context_guess)->text_guess[
            context_guess->field08_guess->field04_guess] == 0) {
        FUN_0060e460_guess(path_guess, EQ_ARRAY(char, 0x0063FE3C));
    } else {
        FUN_005749f0_guess(GetLanguageCodePage_guess(EQ_GLOBAL(int, 0x00923D74)),
            &reinterpret_cast<LogContextText_guess*>(context_guess)->text_guess[
                context_guess->field08_guess->field04_guess], world_guess, 0x100);
        FUN_0060e460_guess(path_guess, world_guess);
    }
    FUN_0060e460_guess(path_guess, EQ_ARRAY(char, 0x0063FE34));

    FILE* file_guess = fopen(path_guess, EQ_ARRAY(char, 0x0063FE30));
    if (file_guess != 0) {
        fwrite(line_guess, strlen(line_guess), 1, file_guess);
        fclose(file_guess);
    }
}

// The 4-byte sub-object at +4 of the SlotOwner (CEverQuest): the owner is at this-4.
struct SlotSubObject_guess {
    int field00_guess;
    void OnMailHeader_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
        int p5_guess, int p6_guess, int p7_guess, int p8_guess);
    void OnMailBody_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
        char flag_guess, int unused_guess);
    void OnNewMail_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
        int p5_guess, int p6_guess);
};

// Mail callback (vtable 0x649890 slot 10; `this` is CEverQuest+4): passes a message header to the
// mail list with its status made 0-based.
// FUNCTION: TITANIUM 0x004958AA
void SlotSubObject_guess::OnMailHeader_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
    int p5_guess, int p6_guess, int p7_guess, int p8_guess) {
    ManagedObject_guess* object_guess =
        reinterpret_cast<SlotOwner_guess*>(this - 1)->GetMailManager_guess();
    if (object_guess != 0) {
        object_guess->AddHeader_guess(p1_guess, p2_guess, p3_guess, p4_guess, p5_guess,
            ConvertMailStatus_guess(p6_guess), p7_guess, p8_guess);
    }
}

// Mail callback slot 12: a fetched message body to the mail list, or a log line when the fetch failed.
// FUNCTION: TITANIUM 0x004958E5
void SlotSubObject_guess::OnMailBody_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
    char flag_guess, int unused_guess) {
    ManagedObject_guess* object_guess =
        reinterpret_cast<SlotOwner_guess*>(this - 1)->GetMailManager_guess();
    if (object_guess != 0) {
        if (flag_guess != 0) {
            object_guess->FUN_0042ca9a_guess(p1_guess, p2_guess, p3_guess, p4_guess);
        } else {
            FUN_00574110_guess("Mail System: could not fetch message body.");
        }
    }
}

// Mail callback slot 11: a new-mail notice to the mail list, which shows 'New mail from %1' (0x11C3).
// FUNCTION: TITANIUM 0x0049593D
void SlotSubObject_guess::OnNewMail_guess(int p1_guess, int p2_guess, int p3_guess, int p4_guess,
    int p5_guess, int p6_guess) {
    ManagedObject_guess* object_guess =
        reinterpret_cast<SlotOwner_guess*>(this - 1)->GetMailManager_guess();
    if (object_guess != 0) {
        object_guess->NotifyNewMail_guess(p1_guess, p2_guess, p3_guess,
            ConvertMailStatus_guess(p4_guess), p5_guess, p6_guess);
    }
}

// Packet handler while waiting for a disconnect (vtable 0x649508 slot 0): chat (OP_ChannelMessage
// 0x1004) is still shown; everything is counted.
// FUNCTION: TITANIUM 0x0049564F
void MessageCounter_guess::HandleDisconnectWaitPacket_guess(int unused1_guess, short* data_guess, int unused2_guess) {
    if (*data_guess == 0x1004) {
        Handle_OP_ChannelMessage_guess(data_guess + 1);
        ++matched_guess;
    } else {
        ++unmatched_guess;
    }
}

// Waits for the world connection to report disconnected (status 1), logging a timeout, then tears
// it down.
// FUNCTION: TITANIUM 0x00495681
void WaitForDisconnectAndProcessMessages_guess() {
    if (g_connection_00905ca0_guess != 0) {
        DisconnectWaitState_guess state_guess;
        g_connection_00905ca0_guess->BeginWait_guess(&state_guess);
        int iteration_guess = 0;
        do {
            if (g_connection_00905ca0_guess == 0) {
                break;
            }
            if (reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)->GetField88_guess() == 1) {
                break;
            }
            if (reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess != 0) {
                reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess->Wait_guess(500);
            }
            FUN_00600e40_guess(100);
            ++iteration_guess;
        // 1200 rounds of 100 ms: the 120 s the log line reports.
        } while (iteration_guess < 0x4b0);
        if (g_connection_00905ca0_guess != 0) {
            if (reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)->GetField88_guess() != 1) {
                FUN_00574110_guess("WaitForDisconnectAndProcessMessages() timed out after %d seconds.\n", 0x78);
            }
        }
        g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
    }
}

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
extern "C" int __cdecl atoi(const char* text_guess);
// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section_guess, const char* key_guess,
    const char* default_guess, char* buffer_guess, unsigned int size_guess,
    const char* file_guess);

// Connects the chat-server API (+0x290) for OP_SetChatServer: host, port and two login strings.
// A live connection to the same host and port is kept. [Defaults] ChatKeepAlive turns on keep-alive.
// FUNCTION: TITANIUM 0x00495720
void TargetOwner_guess::ConnectChatServer_guess(char* name_guess, int value_guess,
    char* first_guess, char* second_guess) {
    if (*name_guess != 0 && value_guess != 0) {
        if (field290_guess != 0) {
            if (_stricmp(name_guess, (char*)&field0c_guess) != 0 ||
                value_guess != field8c_guess ||
                field290_guess->FUN_0040bf0f_guess() != 1) {
                NestedState_guess* old_guess = field290_guess;
                if (old_guess != 0) {
                    old_guess->FUN_0040c654_guess();
                    free(old_guess);
                }
                field290_guess = 0;
            }
            if (field290_guess != 0) {
                return;
            }
        }
        strcpy((char*)&field0c_guess, name_guess);
        field8c_guess = value_guess;
        strcpy((char*)&field90_guess, first_guess);
        strcpy((char*)&field190_guess, second_guess);
        char buffer_guess[0x20];
        FUN_0060be50_guess("Defaults", "ChatKeepAlive", EQ_ARRAY(char, 0x006410A8), buffer_guess, 0x20,
            ".\\eqclient.ini");
        field290_guess = new NestedState_guess((char*)&field0c_guess, field8c_guess,
            (char*)&field90_guess, (char*)&field190_guess, this,
            atoi(buffer_guess) != 0,
            0, EQ_ARRAY(const char*, 0x00799830)[EQ_GLOBAL(int, 0x00923D74)], 0);
        field294_guess = 0;
    }
}

// The same for the mail API (+0x834, OP_SetChatServer2), always reconnecting; its callbacks are
// the CEverQuest+4 mail handler.
// FUNCTION: TITANIUM 0x00495972
void TargetOwner_guess::ConnectMailServer_guess(char* name_guess, int value_guess,
    char* first_guess, char* second_guess) {
    if (*name_guess != 0 && value_guess != 0) {
        CleanupPayload_guess* memory_guess = field834_guess;
        if (memory_guess != 0) {
            memory_guess->FUN_005ffe00_guess();
            free(memory_guess);
            field834_guess = 0;
        }
        strcpy((char*)&field5b0_guess, name_guess);
        field630_guess = value_guess;
        strcpy((char*)&field634_guess, first_guess);
        strcpy((char*)&field734_guess, second_guess);
        char buffer_guess[0x20];
        FUN_0060be50_guess("Defaults", "ChatKeepAlive", EQ_ARRAY(char, 0x006410A8), buffer_guess, 0x20,
            ".\\eqclient.ini");
        field834_guess = new CleanupPayload_guess((char*)&field5b0_guess,
            field630_guess, (char*)&field634_guess, (char*)&field734_guess,
            field04_guess, atoi(buffer_guess) != 0, 0,
            EQ_ARRAY(const char*, 0x00799830)[EQ_GLOBAL(int, 0x00923D74)], 0);
    }
}

// Returns 1; shared by many vtables.
// FUNCTION: TITANIUM 0x00495A87
char AlwaysTrue_guess() {
    return 1;
}

struct CallbackState_guess {
    virtual void RefreshCounts_guess();
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
    virtual void UpdateMarker_guess(int value_guess);
    char padding_0004_guess[0x2c];
    int field30_guess;
    void SetPitchAndUpdate_guess(int value_guess);
};

// Camera (vtable 0x649654): sets the pitch (+0x30) and updates.
// FUNCTION: TITANIUM 0x00495A8A
void CallbackState_guess::SetPitchAndUpdate_guess(int value_guess) {
    field30_guess = value_guess;
    UpdateMarker_guess(0);
}

// Field at 0x30: clamped float (64.0 / -120.0 limits).
struct ClampedFloat_guess {
    char pad_guess[0x30];
    float value30_guess;  // +0x30
    void SetPitchClamped_guess(float value_guess);
};

// Camera (vtable 0x649694): sets the pitch, clamped to -120..64 as ApplyMouseLook does.
// FUNCTION: TITANIUM 0x00495A9B
void ClampedFloat_guess::SetPitchClamped_guess(float value_guess) {
    value30_guess = value_guess;
    if (value_guess > 64.0f) {
        value30_guess = 64.0f;
    } else if (value_guess < -120.0f) {
        value30_guess = -120.0f;
    }
}

// Submits the up-to-4 emitters of effect stage `mode`. Each row holds an emitter id, a minimum caster
// level, a source (0 point, 1 caster, 2 location object, 3 target) and a dag (1-11, 12 = ground under
// the actor). Returns the largest submit result.
// FUNCTION: TITANIUM 0x00495CC3
// @early-stop: budget, diff ndiff=192
int __cdecl SubmitEffectEmitters_guess(unsigned int objectValue_guess, int mode_guess,
    TransferRecordB_guess* records_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess, int value5_guess, int value6_guess,
    int value7_guess, char filter_guess) {
    int maximum_guess = 0;
    unsigned int packedValue_guess = 0;
    int output_guess = 0;
    int threshold_guess;
    if (first_guess == 0 || first_guess->type_guess != 0) {
        threshold_guess = 1;
    } else {
        threshold_guess = first_guess->level_guess;
    }

    int* record_guess = &records_guess[mode_guess].field40_guess + 2;
    for (int remaining_guess = 4; remaining_guess != 0;
        --remaining_guess, record_guess += 4) {
        int actorId_guess = record_guess[-1];
        if (actorId_guess < 1) continue;
        if (filter_guess != 0 &&
            g_transferManager_guess->CheckActor_guess(actorId_guess) == 0) continue;
        if (threshold_guess < record_guess[0]) continue;

        int sourceType_guess = record_guess[1];
        int data_guess = 0;
        int selectedNode_guess = 0;
        TransferAction_guess* action_guess = 0;
        ActionPosition_guess position_guess;
        if (sourceType_guess == 0) {
            if (value5_guess == 0) continue;
            position_guess = *(ActionPosition_guess*)value5_guess;
        } else if (sourceType_guess == 1) {
            action_guess = first_guess;
        } else if (sourceType_guess == 2) {
            TransferPositionSource_guess* source_guess =
                (TransferPositionSource_guess*)value6_guess;
            if (source_guess == 0) continue;
            position_guess = source_guess->position_guess;
            if (source_guess->field48_guess != 0) {
                data_guess = *source_guess->field48_guess;
            }
        } else if (sourceType_guess == 3) {
            action_guess = second_guess;
        } else {
            continue;
        }

        float scale_guess = 1.0f;
        if (action_guess != 0) {
            position_guess = action_guess->position_guess;
            if (action_guess->dags_guess != 0) {
                data_guess = (int)action_guess->dags_guess->source_guess;
            }
        }
        if ((sourceType_guess == 1 || sourceType_guess == 3) && action_guess == 0) continue;

        if (action_guess != 0 && action_guess->dags_guess != 0 &&
            action_guess->dags_guess->source_guess != 0) {
            DagHolder_guess* dags_guess = action_guess->dags_guess;
            switch (record_guess[2]) {
            case 0:
                data_guess = 0;
                break;
            case 1:
                selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 2:
                selectedNode_guess = (int)dags_guess->node2_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 3:
                selectedNode_guess = dags_guess->node3_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 4:
                selectedNode_guess = dags_guess->node4_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 5:
                selectedNode_guess = dags_guess->node5_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 6:
                selectedNode_guess = dags_guess->node6_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 7:
                selectedNode_guess = dags_guess->node7_guess;
                if (selectedNode_guess == 0) selectedNode_guess = dags_guess->defaultNode_guess;
                break;
            case 8:
                break;
            case 9:
                selectedNode_guess = dags_guess->node9_guess;
                if (selectedNode_guess == 0) continue;
                break;
            case 10:
                selectedNode_guess = dags_guess->node10_guess;
                if (selectedNode_guess == 0) continue;
                break;
            case 11:
                selectedNode_guess = dags_guess->node11_guess;
                break;
            case 12:
                if (dags_guess->node2_guess != 0) {
                    DagPositionObject_guess* positionObject_guess =
                        dags_guess->node2_guess->GetPosition_guess();
                    position_guess = positionObject_guess->position_guess;
                }
                position_guess.z_guess = action_guess->GetFloorHeightHere_guess(0.1f);
                scale_guess = dags_guess->scaleData_guess->value38_guess;
                selectedNode_guess = 0;
                break;
            default:
                continue;
            }
        }

        if (action_guess != 0) {
            packedValue_guess = (action_guess->spawnId_0258_guess << 16) | objectValue_guess;
        }
        int result_guess = g_transferManager_guess->Submit_guess(actorId_guess,
            packedValue_guess, value7_guess, g_transferFloat_00985810_guess,
            g_transferFloat_00985814_guess, &position_guess, data_guess, 0,
            selectedNode_guess, &output_guess, scale_guess, 1);
        if (maximum_guess < result_guess) maximum_guess = result_guess;
    }
    return maximum_guess;
}

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    int* GetCharInfo2();
};

struct ZoneDataReference_guess {
    char padding_0000_guess[4];
    int offset_guess;
};

struct ZoneStringValue_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 ZoneStringValue_guess::Get_guess
    char* Get_guess();
};

struct ZoneContextNames_guess {
    char padding_0000_guess[0x34];
    ZoneStringValue_guess* first_guess;
    ZoneStringValue_guess* second_guess;
};

struct ZoneFinderState_guess {
    char padding_0000_guess[0x11b0];
    int state11b0_guess;
};

struct ZoneDynamicRegion_guess {
    char padding_0000_guess[0x0c];
    EQ_CharacterProfileView_guess finder_guess;
    char padding_000d_guess[0x27];
    float x_guess;
    float y_guess;
    float z_guess;
    float heading_guess;
    char label_guess[0x40];
    char padding_0084_guess[0x40];
    union {
        TextReceiver_guess textObject_guess;
        char text_guess[0x40];
    };
    char state104_guess;
    char padding_0105_guess[0x2b];
    char state130_guess;
};

struct ZoneCharacterData_guess {
    char padding_0000_guess[8];
    ZoneDataReference_guess* reference_guess;
    char padding_000c_guess[0xe20 - 0x0c];
    int fielde20_guess;
    char padding_0e24_guess;
    char statee25_guess;
    char padding_0e26_guess[0x0a];
    int fielde30_guess;
    // EXTERNAL: TITANIUM 0x005ED8A0 ZoneCharacterData_guess::SetFirst_guess
    void SetFirst_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED8E0 ZoneCharacterData_guess::SetSecond_guess
    void SetSecond_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED880 ZoneCharacterData_guess::GetFirst_guess
    int GetFirst_guess();
    // EXTERNAL: TITANIUM 0x005ED8C0 ZoneCharacterData_guess::GetSecond_guess
    int GetSecond_guess();
    // EXTERNAL: TITANIUM 0x005F05E0 ZoneCharacterData_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005F06B0 ZoneCharacterData_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x004BE2DC ZoneCharacterData_guess::SetChoice_guess
    void SetChoice_guess(int index_guess, int value_guess);
};

struct ZonePlayerData_guess {
    char padding_0000_guess[0x30];
    float x_guess;
    float y_guess;
    float z_guess;
    char padding_003c_guess[0x10];
    float heading_guess;
    char padding_0050_guess[0x16c];
    int values_guess[9];
    char padding_01e0_guess[0x64];
    char state244_guess;
    char padding_0245_guess[0x11];
    char state256_guess;
};

struct ZoneSendData_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    int heading_guess;
    int values_guess[22];
    char name_guess[0x40];
    int field98_guess;
    int field9c_guess;
    int fielda0_guess;
    int fielda4_guess;
};

struct ZoneSendPacket_guess {
    int hash_guess;
    unsigned char flags_guess;
    unsigned char payload_guess[0xbb];
};

// EXTERNAL: TITANIUM 0x0047981D FindPlayerByPartialDisplayName_guess
int __cdecl FindPlayerByPartialDisplayName_guess(const char* name_guess, int zero_guess);
// EXTERNAL: TITANIUM 0x004BF9B2 TransformPassengersToBoatSpace_guess
void __cdecl TransformPassengersToBoatSpace_guess(void* value_guess);
// EXTERNAL: TITANIUM 0x004BFC71 TransformPassengersToWorldSpace_guess
void __cdecl TransformPassengersToWorldSpace_guess(void* value_guess);
// EXTERNAL: TITANIUM 0x004658DD is_number_guess
int __cdecl is_number_guess(const char* text_guess);

// EXTERNAL: TITANIUM 0x0060F81E abs
extern "C" int __cdecl abs(int value_guess);

// Result of Find: carried coins, then banked coins.
struct CoinPurse_guess {
    char padding_0000_guess[0x11D4];
    int bank_guess[4]; // 0x11D4
    int carried_guess[4]; // 0x11E4
};

struct CoinVBase_guess {
    char padding_0000_guess[4];
    EQ_CharacterProfileView_guess finder_guess; // 0x04
    char padding_0005_guess[0x12C - 5];
    int sharedBank_guess[4]; // 0x12C
    int cursor_guess[4]; // 0x13C
    CoinPurse_guess* GetPurse_guess() {
        return reinterpret_cast<CoinPurse_guess*>(finder_guess.GetCharInfo2());
    }
};

struct CoinCharHead_guess {
    char padding_0000_guess[8];
};

struct CoinChar_guess : CoinCharHead_guess, virtual CoinVBase_guess {
    char padding_000c_guess[0xC28C - 0xC];
    unsigned char coinsDirty_guess; // 0xC28C
};

struct CoinSound_guess {
    // EXTERNAL: TITANIUM 0x0044A537 CoinSound_guess::WavePlay_guess
    void WavePlay_guess(int id_guess, int zero_guess);
};

struct CoinDisplay_guess {
    char padding_0000_guess[0x11];
    unsigned char coinType_guess; // 0x11
};

struct CoinMover_guess {
    int MoveMoney_guess(int fromType_guess, int toType_guess, int fromSlot_guess,
        int toSlot_guess, int amount_guess, char quiet_guess);
};

struct CoinMovePacket_guess {
    int fromType_guess;
    int toType_guess;
    int fromSlot_guess;
    int toSlot_guess;
    int amount_guess;
};

#define g_coinChar_guess EQ_GLOBAL(CoinChar_guess*, 0x00905D00)
#define g_coinSound_guess EQ_GLOBAL(CoinSound_guess*, 0x00851390)
#define g_coinDisplay_guess EQ_GLOBAL(CoinDisplay_guess*, 0x00905D24)

// Moves coins between places (0 carried, 1 bank, 2 cursor, 3 trade window, 4 shared bank) and coins
// (0 platinum .. 3 copper). Changing coin type converts by powers of 10, only with window 0x850C38
// open (probably the bank); a stack is capped at 1,000,000,000.
// FUNCTION: TITANIUM 0x00495F81
// @early-stop: budget, structural ndiff=181
int CoinMover_guess::MoveMoney_guess(int fromType_guess, int toType_guess, int fromSlot_guess,
    int toSlot_guess, int amount_guess, char quiet_guess) {
    if (amount_guess == 0 || g_coinChar_guess == 0) {
        return 0;
    }
    int diff_guess = toSlot_guess - fromSlot_guess;
    int* from_guess = 0;
    int* to_guess = 0;
    int factor_guess = (int)IntPow_guess(10.0, abs(diff_guess));
    if (factor_guess != 1 && !g_status_00850c38_guess->FUN_0059dd30_guess()) {
        return 0;
    }
    if (fromType_guess == 0) {
        switch (fromSlot_guess) {
        case 0: from_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[0]; break;
        case 1: from_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[1]; break;
        case 2: from_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[2]; break;
        case 3: from_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[3]; break;
        }
    } else if (fromType_guess == 1) {
        switch (fromSlot_guess) {
        case 0: from_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[0]; break;
        case 1: from_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[1]; break;
        case 2: from_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[2]; break;
        case 3: from_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[3]; break;
        }
    } else if (fromType_guess == 2) {
        switch (fromSlot_guess) {
        case 0: from_guess = &g_coinChar_guess->cursor_guess[0]; break;
        case 1: from_guess = &g_coinChar_guess->cursor_guess[1]; break;
        case 2: from_guess = &g_coinChar_guess->cursor_guess[2]; break;
        case 3: from_guess = &g_coinChar_guess->cursor_guess[3]; break;
        }
    } else if (fromType_guess == 3) {
        switch (fromSlot_guess) {
        case 0: from_guess = &pinstCTradeWnd_guess->coins_guess[0]; break;
        case 1: from_guess = &pinstCTradeWnd_guess->coins_guess[1]; break;
        case 2: from_guess = &pinstCTradeWnd_guess->coins_guess[2]; break;
        case 3: from_guess = &pinstCTradeWnd_guess->coins_guess[3]; break;
        }
    } else if (fromType_guess == 4) {
        switch (fromSlot_guess) {
        case 0: from_guess = &g_coinChar_guess->sharedBank_guess[0]; break;
        case 1: from_guess = &g_coinChar_guess->sharedBank_guess[1]; break;
        case 2: from_guess = &g_coinChar_guess->sharedBank_guess[2]; break;
        case 3: from_guess = &g_coinChar_guess->sharedBank_guess[3]; break;
        }
    }
    if (toType_guess == 0) {
        if (quiet_guess == 0 && !pinstCCursorAttachment_guess->IsOkToActivate_guess(3)) {
            return 0;
        }
        g_coinSound_guess->WavePlay_guess(0x8a, 0);
        switch (toSlot_guess) {
        case 0: to_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[0]; break;
        case 1: to_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[1]; break;
        case 2: to_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[2]; break;
        case 3: to_guess = &g_coinChar_guess->GetPurse_guess()->carried_guess[3]; break;
        }
    } else if (toType_guess == 1) {
        switch (toSlot_guess) {
        case 0: to_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[0]; break;
        case 1: to_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[1]; break;
        case 2: to_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[2]; break;
        case 3: to_guess = &g_coinChar_guess->GetPurse_guess()->bank_guess[3]; break;
        }
    } else if (toType_guess == 2) {
        switch (toSlot_guess) {
        case 0: to_guess = &g_coinChar_guess->cursor_guess[0]; break;
        case 1: to_guess = &g_coinChar_guess->cursor_guess[1]; break;
        case 2: to_guess = &g_coinChar_guess->cursor_guess[2]; break;
        case 3: to_guess = &g_coinChar_guess->cursor_guess[3]; break;
        }
    } else if (toType_guess == 3) {
        switch (toSlot_guess) {
        case 0: to_guess = &pinstCTradeWnd_guess->coins_guess[0]; break;
        case 1: to_guess = &pinstCTradeWnd_guess->coins_guess[1]; break;
        case 2: to_guess = &pinstCTradeWnd_guess->coins_guess[2]; break;
        case 3: to_guess = &pinstCTradeWnd_guess->coins_guess[3]; break;
        }
    } else if (toType_guess == 4) {
        switch (toSlot_guess) {
        case 0: to_guess = &g_coinChar_guess->sharedBank_guess[0]; break;
        case 1: to_guess = &g_coinChar_guess->sharedBank_guess[1]; break;
        case 2: to_guess = &g_coinChar_guess->sharedBank_guess[2]; break;
        case 3: to_guess = &g_coinChar_guess->sharedBank_guess[3]; break;
        }
    }
    if (from_guess == 0 || from_guess == to_guess || amount_guess > *from_guess) {
        return 0;
    }
    if (diff_guess < 0) {
        if (amount_guess / factor_guess > 1000000000 - *to_guess) {
            return 0;
        }
    } else if ((1000000000 - *to_guess) / factor_guess < amount_guess) {
        return 0;
    }
    if (diff_guess < 0) {
        int converted_guess = amount_guess - amount_guess % factor_guess;
        *from_guess -= converted_guess;
        *to_guess += converted_guess / factor_guess;
        if (fromType_guess == 0 && pinstCCursorAttachment_guess->mode_15c_guess == 3) {
            pinstCCursorAttachment_guess->count_164_guess = *from_guess;
        }
    } else {
        *from_guess -= amount_guess;
        *to_guess += factor_guess * amount_guess;
    }
    switch (fromSlot_guess) {
    case 0: fromSlot_guess = 3; break;
    case 1: fromSlot_guess = 2; break;
    case 2: fromSlot_guess = 1; break;
    case 3: fromSlot_guess = 0; break;
    }
    switch (toSlot_guess) {
    case 0: toSlot_guess = 3; break;
    case 1: toSlot_guess = 2; break;
    case 2: toSlot_guess = 1; break;
    case 3: toSlot_guess = 0; break;
    }
    if (amount_guess > 0) {
        CoinMovePacket_guess packet_guess;
        packet_guess.fromType_guess = fromType_guess;
        packet_guess.toType_guess = toType_guess;
        packet_guess.fromSlot_guess = fromSlot_guess;
        packet_guess.toSlot_guess = toSlot_guess;
        packet_guess.amount_guess = amount_guess;
        // OP_MoveCoin: {from place, to place, from coin, to coin, amount}; the wire numbers coins the other
        // way round (3 = platinum).
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7657, &packet_guess, 0x14, 1);
        g_coinChar_guess->coinsDirty_guess = 1;
    }
    g_coinDisplay_guess->coinType_guess = 0;
    if (g_coinChar_guess->GetPurse_guess()->carried_guess[0] > 0) {
        g_coinDisplay_guess->coinType_guess = 1;
    } else if (g_coinChar_guess->GetPurse_guess()->carried_guess[1] > 0) {
        g_coinDisplay_guess->coinType_guess = 2;
    } else if (g_coinChar_guess->GetPurse_guess()->carried_guess[2] > 0) {
        g_coinDisplay_guess->coinType_guess = 3;
    } else if (g_coinChar_guess->GetPurse_guess()->carried_guess[3] > 0) {
        g_coinDisplay_guess->coinType_guess = 4;
    }
    return 1;
}

struct Message96731_guess {
    unsigned short value_guess;
    unsigned short type_guess;
    unsigned int flag_guess;
};

struct GlobalArray_guess {
    // EXTERNAL: TITANIUM 0x0060CA70 GlobalArray_guess::Get_guess
    unsigned int Get_guess(int index_guess);
};

#define g_globalArray_009248e0_guess reinterpret_cast<GlobalArray_guess*>(EQ_ARRAY(unsigned char, 0x009248E0))

struct SendFrame_guess {
    unsigned int value_guess;
    unsigned int values_guess[28];
};

// Sends the chat filters: 0x9237E4 then the 28 filter values (OP_SetServerFilter 0x6563, 0x74 bytes).
// FUNCTION: TITANIUM 0x004966EE
void send_update_filters_guess() {
    SendFrame_guess frame_guess;
    int index_guess = 0;
    do {
        frame_guess.values_guess[index_guess] = g_globalArray_009248e0_guess->Get_guess(index_guess);
        ++index_guess;
    } while (index_guess < 0x1c);
    frame_guess.value_guess = EQ_GLOBAL(unsigned int, 0x009237E4);
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6563, &frame_guess.value_guess, 0x74, 1);
}

// Tells the server the autosplit option (OP_SpawnAppearance 0x7C32, type 0x1C).
// FUNCTION: TITANIUM 0x00496731
void __cdecl SendAutoSplit_guess() {
    Message96731_guess data_guess;
    data_guess.type_guess = 0x1c;
    data_guess.value_guess = g_resetOwner_guess->spawnId_0258_guess;
    data_guess.flag_guess = *reinterpret_cast<unsigned char*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 0x120) != 0;
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7c32, &data_guess, 8, 1);
}

struct DisconnectOwner_guess {
    char padding_0000_guess[0xB50];
    int fieldb50_guess; // 0xB50
    int fieldb54_guess; // 0xB54
    char padding_0b58_guess[0x388A8];
    int field39400_guess; // 0x39400
    void GetZoneInfoFromNetwork(const char* name_guess);
    char CheckCharSelectDisconnect_guess(const char* address_guess, unsigned int port_guess,
        char flag_guess);
    // EXTERNAL: TITANIUM 0x004932AB DisconnectOwner_guess::DisplayScreen_guess
    void DisplayScreen_guess(char* name_guess);
};

// Returns 0 while the world connection is up. Otherwise logs where (`address` is really the source
// file, `port` the line), shows Discon.bmp for 3 s and returns 1; with `flag` it also quits (state 0xFF).
// FUNCTION: TITANIUM 0x00496932
char DisconnectOwner_guess::CheckCharSelectDisconnect_guess(const char* address_guess,
    unsigned int port_guess, char flag_guess) {
    char reason_guess[0x200];
    if (g_connection_00905ca0_guess != 0) {
        if (reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)->GetField88_guess() != 1) {
            return 0;
        }
    }
    if (g_connection_00905ca0_guess != 0) {
        if (g_connection_00905ca0_guess->FUN_005e5bd0_guess(reason_guess, 0x200) == 0) {
            FUN_0060e450_guess(reason_guess, "buffer too small to print reason");
        }
    } else {
        FUN_0060e450_guess(reason_guess, "g_world == NULL");
    }
    FUN_00574110_guess("disconnected at %s:%u (char. select) %s\n",
        address_guess, port_guess, reason_guess);
    if (g_contextObject_guess != 0) {
        FUN_00574110_guess("Character is %s.\n",
            reinterpret_cast<char*>(g_contextObject_guess) +
                g_contextObject_guess->field08_guess->field04_guess + 0x44);
    }
    field39400_guess = 1;
    DisplayScreen_guess("Discon.bmp");
    Sleep(3000);
    if (flag_guess != 0) {
        fieldb50_guess = 1;
        int* state_guess = &g_globalState_guess->state_guess;
        g_globalState_guess->state_guess = 0xff;
        switch (*state_guess) {
        case 1:
            DisableAllCommands_guess();
            EnableCommand_guess(0x105);
            EnableCommand_guess(0x106);
            EnableCommand_guess(0x107);
            EnableCommand_guess(0x108);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        case 2:
            DisableAllCommands_guess();
            EnableCommand_guess(0x10a);
            EnableCommand_guess(0x109);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        case 5:
            EnableAllCommands_guess();
            DisableCommand_guess(0x105);
            DisableCommand_guess(0x106);
            DisableCommand_guess(0x107);
            DisableCommand_guess(0x108);
            DisableCommand_guess(0x10a);
            DisableCommand_guess(0x109);
            break;
        }
        g_value_00923794_guess = 0xfd;
    }
    return 1;
}

// True when input mode 0x9237B0 is 0: the chat input has focus (see SetChatInputFocus 0x494051).
// FUNCTION: TITANIUM 0x00496AEF
bool IsChatInputFocused_guess() {
    return g_state_009237b0_guess == 0;
}

// True when input mode 0x9237B0 is 1: keys go to the game.
// FUNCTION: TITANIUM 0x00496AFB
bool IsGameInputFocused_guess() {
    return g_state_009237b0_guess == 1;
}

struct Message96B08_guess {
    unsigned short value_guess;
    unsigned short type_guess;
    unsigned int flag_guess;
};

// Tells the server the player's light (OP_SpawnAppearance 0x7C32, type 5); not sent while sending
// is off (0x923798) or 0x923884 is set.
// FUNCTION: TITANIUM 0x00496B08
void GlobalState_guess::SendLightInfo_guess(int unused_guess, unsigned char flag_guess) {
    Message96B08_guess data_guess;
    data_guess.type_guess = 5;
    data_guess.value_guess = g_resetOwner_guess->spawnId_0258_guess;
    data_guess.flag_guess = flag_guess;
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7c32, &data_guess, 8, 1);
    }
}

struct ActorNode_guess {
    char padding_0000_guess[0x120];
    char name_guess[0x88];
    int* pActorInfo_01a8_guess;
    char padding_01ac_guess[0x68];
    ActorNode_guess* next_guess;
    char padding_0218_guess[0x2C];
    unsigned char type_0244_guess;
    char padding_0245_guess[0xC];
    unsigned char standState_0251_guess;
    // EXTERNAL: TITANIUM 0x0047BCE2 ActorNode_guess::UpdateLight_guess
    void UpdateLight_guess();
    // EXTERNAL: TITANIUM 0x0048500B ActorNode_guess::MakeRiderMountUp_guess
    void MakeRiderMountUp_guess();
};

struct ActorDefinitionNode_guess {
    char padding_0000_guess[4];
    ActorDefinitionNode_guess* next_guess;
    char padding_0008_guess[0xC];
    int cached14_guess;
    char padding_0018_guess[4];
    float value1c_guess;
    float value20_guess;
    float value24_guess;
    float value28_guess;
    char name_guess[0x20];
};

struct ActorPartNode_guess {
    char padding_0000_guess[4];
    ActorPartNode_guess* next_guess;
    char padding_0008_guess[0x2C];
    int cached34_guess;
    float value38_guess;
    float value3c_guess;
    float value40_guess;
    float value44_guess;
    float value48_guess;
    char padding_004c_guess[4];
    char name_guess[0x20];
};

struct ActorDisplay_guess {
    // EXTERNAL: TITANIUM 0x0043C84B ActorDisplay_guess::FUN_0043c84b_guess
    void FUN_0043c84b_guess(ActorNode_guess* actor_guess);
    // EXTERNAL: TITANIUM 0x0043910D ActorDisplay_guess::FUN_0043910d_guess
    void FUN_0043910d_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0043972A ActorDisplay_guess::CreateActor_guess
    int CreateActor_guess(const char* name_guess, float first_guess,
        float second_guess, float third_guess, float fourth_guess,
        float fifth_guess, float sixth_guess, int firstFlag_guess,
        int secondFlag_guess);
};

#define g_actorHead_guess EQ_GLOBAL(ActorNode_guess*, 0x00905CC4)
#define g_actorDefinitionHead_guess EQ_GLOBAL(ActorDefinitionNode_guess*, 0x00905CC8)
#define g_actorPartHead_guess EQ_GLOBAL(ActorPartNode_guess*, 0x00905CCC)
#define g_actorDisplay_guess EQ_GLOBAL(ActorDisplay_guess*, 0x00905D24)
#define g_selectedActor_guess EQ_GLOBAL(ActorNode_guess*, 0x00905CE4)
#define g_actorStatus_guess EQ_GLOBAL(int, 0x00905CF8)
#define g_actorReset_guess EQ_GLOBAL(int, 0x00905CFC)

// EXTERNAL: TITANIUM 0x0047C88E GetSpawnByName_guess
int __cdecl GetSpawnByName_guess(int value_guess);

#define g_value_00905c00_guess EQ_GLOBAL(int, 0x00905C00)
#define g_value_00923d24_guess EQ_GLOBAL(int, 0x00923D24)
#define g_flag_00923d7b_guess EQ_GLOBAL(unsigned char, 0x00923D7B)
#define g_value_00923794_guess EQ_GLOBAL(int, 0x00923794)

// EXTERNAL: TITANIUM 0x004B6C04 MemChecker0
int __cdecl MemChecker0(void* data_guess, unsigned int length_guess);

struct ZoneConnectMessage_guess {
    int hash_guess;
    char name_guess[0x40];
};

struct GlobalObj923770_guess {
    char padding_0000_guess[0x62157];
    unsigned char field62157_guess;
    char field62158_guess;
    void SetAutoAttack_guess(unsigned char value_guess);
    void SetAutoFire_guess(char value_guess);
};

struct ChatRecord_guess {
    char padding_0000_guess[0xF0];
    unsigned int fieldf0_guess; // 0xF0
    unsigned int fieldf4_guess; // 0xF4
    unsigned int fieldf8_guess; // 0xF8
};

// EXTERNAL: TITANIUM 0x004C94AE FUN_004c94ae_guess
ChatRecord_guess* __cdecl FUN_004c94ae_guess();

#define g_promptBlocked_009043a4_guess EQ_GLOBAL(unsigned char, 0x009043A4)
#define g_value_0092386c_guess EQ_GLOBAL(int, 0x0092386C)
#define g_value_00923870_guess EQ_GLOBAL(int, 0x00923870)
#define g_value_0092378c_guess EQ_GLOBAL(int, 0x0092378C)
#define g_value_00923d28_guess EQ_GLOBAL(int, 0x00923D28)
#define g_value_00923cc8_guess EQ_GLOBAL(int, 0x00923CC8)
#define g_value_00923cd4_guess EQ_GLOBAL(int, 0x00923CD4)
#define g_value_00923ccc_guess EQ_GLOBAL(int, 0x00923CCC)
#define g_value_00923cd0_guess EQ_GLOBAL(int, 0x00923CD0)
#define g_value_00923cd8_guess EQ_GLOBAL(int, 0x00923CD8)
#define g_value_00923cdc_guess EQ_GLOBAL(int, 0x00923CDC)
#define g_value_00923d00_guess EQ_GLOBAL(int, 0x00923D00)
#define g_value_00923d04_guess EQ_GLOBAL(int, 0x00923D04)
#define g_value_0092387c_guess EQ_GLOBAL(unsigned int, 0x0092387C)
#define g_value_00924198_guess EQ_GLOBAL(int, 0x00924198)
#define g_value_00923cbc_guess EQ_GLOBAL(int, 0x00923CBC)
#define g_value_00923cb4_guess EQ_GLOBAL(int, 0x00923CB4)
#define g_value_009239b8_guess EQ_GLOBAL(int, 0x009239B8)
#define g_value_009239c0_guess EQ_GLOBAL(int, 0x009239C0)
#define g_value_009239c4_guess EQ_GLOBAL(int, 0x009239C4)
#define g_value_009239c8_guess EQ_GLOBAL(int, 0x009239C8)
#define g_value_009239cc_guess EQ_GLOBAL(int, 0x009239CC)
#define g_value_009239d0_guess EQ_GLOBAL(int, 0x009239D0)
#define g_value_009239d4_guess EQ_GLOBAL(int, 0x009239D4)
#define g_value_009239d8_guess EQ_GLOBAL(int, 0x009239D8)
#define g_value_009239a8_guess EQ_GLOBAL(int, 0x009239A8)
#define g_value_009239ac_guess EQ_GLOBAL(int, 0x009239AC)
#define g_value_009239b0_guess EQ_GLOBAL(int, 0x009239B0)
#define g_value_00923ca4_guess EQ_GLOBAL(int, 0x00923CA4)
#define g_value_00923ca0_guess EQ_GLOBAL(int, 0x00923CA0)
#define g_value_00923d40_guess EQ_GLOBAL(int, 0x00923D40)
#define g_value_00923d44_guess EQ_GLOBAL(int, 0x00923D44)
#define g_value_00923d48_guess EQ_GLOBAL(int, 0x00923D48)
#define g_value_00923d4c_guess EQ_GLOBAL(int, 0x00923D4C)
#define g_value_00923d50_guess EQ_GLOBAL(int, 0x00923D50)
#define g_value_00923d54_guess EQ_GLOBAL(int, 0x00923D54)
#define g_value_00923d88_guess EQ_GLOBAL(int, 0x00923D88)
#define g_value_00923d8c_guess EQ_GLOBAL(int, 0x00923D8C)
#define g_value_009238ec_guess EQ_GLOBAL(int, 0x009238EC)
#define g_value_009238f0_guess EQ_GLOBAL(int, 0x009238F0)
#define g_value_009238f8_guess EQ_GLOBAL(int, 0x009238F8)
#define g_value_00923860_guess EQ_GLOBAL(int, 0x00923860)
#define g_value_0092478c_guess EQ_GLOBAL(int, 0x0092478C)
#define g_value_00923cb8_guess EQ_GLOBAL(int, 0x00923CB8)
#define g_value_00924474_guess EQ_GLOBAL(unsigned int, 0x00924474)
#define g_value_00923850_guess EQ_GLOBAL(int, 0x00923850)
#define g_value_00923854_guess EQ_GLOBAL(int, 0x00923854)
#define g_value_00923858_guess EQ_GLOBAL(int, 0x00923858)
#define g_value_0092385c_guess EQ_GLOBAL(int, 0x0092385C)
#define g_value_00923888_guess EQ_GLOBAL(int, 0x00923888)
#define g_value_00923890_guess EQ_GLOBAL(int, 0x00923890)
#define g_value_0092388c_guess EQ_GLOBAL(int, 0x0092388C)
#define g_value_00923894_guess EQ_GLOBAL(int, 0x00923894)
#define g_value_009238d8_guess EQ_GLOBAL(int, 0x009238D8)
#define g_value_009238dc_guess EQ_GLOBAL(int, 0x009238DC)
#define g_value_009238e4_guess EQ_GLOBAL(int, 0x009238E4)
#define g_value_00924678_guess EQ_GLOBAL(int, 0x00924678)
#define g_value_0092467c_guess EQ_GLOBAL(int, 0x0092467C)
#define g_value_00924468_guess EQ_GLOBAL(int, 0x00924468)
#define g_value_00923d18_guess EQ_GLOBAL(int, 0x00923D18)
#define g_value_009237f0_guess EQ_GLOBAL(int, 0x009237F0)
#define g_value_0092398c_guess EQ_GLOBAL(int, 0x0092398C)
#define g_value_00923934_guess EQ_GLOBAL(int, 0x00923934)
#define g_value_00923938_guess EQ_GLOBAL(int, 0x00923938)
#define g_value_00923838_guess EQ_GLOBAL(int, 0x00923838)
#define g_value_0092383c_guess EQ_GLOBAL(int, 0x0092383C)
#define g_value_00924478_guess EQ_GLOBAL(int, 0x00924478)
#define g_value_00923d90_guess EQ_GLOBAL(float, 0x00923D90)
#define g_flag_00923874_guess EQ_GLOBAL(unsigned char, 0x00923874)
#define g_flag_00923875_guess EQ_GLOBAL(unsigned char, 0x00923875)
#define g_flag_00923877_guess EQ_GLOBAL(unsigned char, 0x00923877)
#define g_flag_00923876_guess EQ_GLOBAL(unsigned char, 0x00923876)
#define g_flag_00923d2c_guess EQ_GLOBAL(unsigned char, 0x00923D2C)
#define g_flag_00923d2d_guess EQ_GLOBAL(unsigned char, 0x00923D2D)
#define g_flag_00923d2e_guess EQ_GLOBAL(unsigned char, 0x00923D2E)
#define g_flag_00923d2f_guess EQ_GLOBAL(unsigned char, 0x00923D2F)
#define g_flag_00923d30_guess EQ_GLOBAL(unsigned char, 0x00923D30)
#define g_flag_00923d31_guess EQ_GLOBAL(unsigned char, 0x00923D31)
#define g_flag_00923d32_guess EQ_GLOBAL(unsigned char, 0x00923D32)
#define g_flag_00923d33_guess EQ_GLOBAL(unsigned char, 0x00923D33)
#define g_flag_00923d34_guess EQ_GLOBAL(unsigned char, 0x00923D34)
#define g_flag_00923cc0_guess EQ_GLOBAL(unsigned char, 0x00923CC0)
#define g_flag_0092384c_guess EQ_GLOBAL(unsigned char, 0x0092384C)
#define g_flag_00923d7a_guess EQ_GLOBAL(unsigned char, 0x00923D7A)
#define g_flag_009237b4_guess EQ_GLOBAL(unsigned char, 0x009237B4)
#define g_flag_00923d78_guess EQ_GLOBAL(unsigned char, 0x00923D78)
#define g_flag_00923d79_guess EQ_GLOBAL(unsigned char, 0x00923D79)
#define g_flag_00923d1c_guess EQ_GLOBAL(unsigned char, 0x00923D1C)
#define g_flag_00923845_guess EQ_GLOBAL(unsigned char, 0x00923845)
#define g_flag_00923992_guess EQ_GLOBAL(unsigned char, 0x00923992)
#define g_flag_00923991_guess EQ_GLOBAL(unsigned char, 0x00923991)
#define g_flag_00923990_guess EQ_GLOBAL(unsigned char, 0x00923990)
#define g_value_009237ec_guess EQ_GLOBAL(unsigned char, 0x009237EC)
#define g_flag_009237b5_guess EQ_GLOBAL(unsigned char, 0x009237B5)
#define g_flag_00924680_guess EQ_GLOBAL(unsigned char, 0x00924680)
#define g_flag_00924675_guess EQ_GLOBAL(unsigned char, 0x00924675)
#define g_flag_00924676_guess EQ_GLOBAL(unsigned char, 0x00924676)
#define g_flag_009238e0_guess EQ_GLOBAL(unsigned char, 0x009238E0)
#define g_flag_0095a174_guess EQ_GLOBAL(unsigned char, 0x0095A174)
#define g_char_009237f4_guess EQ_GLOBAL(char, 0x009237F4)

// First call of DoCharacterSelection: clears the per-session game globals, re-reads [Defaults]
// DefaultChannel, DefaultChannelTell, ShowSpellDescriptions and DefaultLanguage, and stops auto attack
// and auto fire (twice, as in the original).
// FUNCTION: TITANIUM 0x004A7CD3
// @early-stop: budget, structural ndiff=74
void GlobalState_guess::ResetGameGlobals_guess() {
    g_value_009248d0_guess = 0;
    g_value_0092386c_guess = -1;
    g_value_00923870_guess = -1;
    g_flag_00923874_guess = 0;
    g_flag_00923875_guess = 0;
    g_flag_00923877_guess = 0;
    g_flag_00923876_guess = 0;
    g_flag_00923d2c_guess = 0;
    g_flag_00923d2d_guess = 0;
    g_flag_00923d2e_guess = 0;
    g_flag_00923d2f_guess = 0;
    g_flag_00923d30_guess = 0;
    g_flag_00923d31_guess = 0;
    g_flag_00923d32_guess = 0;
    g_flag_00923d33_guess = 0;
    g_flag_00923d34_guess = 0;
    g_value_0092378c_guess = 0;
    g_value_00923d28_guess = 0;
    g_flag_00923842_guess = 0;
    g_flag_00923cc0_guess = 0;
    g_value_00923cc4_guess = -1;
    g_value_00923cc8_guess = 0;
    g_value_00923ccc_guess = 0;
    g_value_00923cd0_guess = 0;
    g_value_00923cd4_guess = 0;
    g_value_00923cd8_guess = 0;
    g_value_00923cdc_guess = 0;
    strcpy(EQ_ARRAY(char, 0x00923CE0), g_text_0063f53f_guess);
    g_value_00923d00_guess = 0;
    g_value_00923d04_guess = -1;
    strcpy(EQ_ARRAY(char, 0x00923D98), EQ_ARRAY(char, 0x00649F18));
    g_value_0092387c_guess = -1;
    g_value_00924198_guess = 1;
    g_value_00923cbc_guess = 0;
    g_flag_0092384c_guess = 0;
    strcpy(EQ_ARRAY(char, 0x00923898), g_text_0063f53f_guess);
    g_flag_0092384d_guess = 0;
    g_value_00923cb4_guess = 0;
    g_flag_009239dc_guess = 0;
    g_value_009239b8_guess = 0;
    g_state_009237b0_guess = 1;
    g_value_009239c0_guess = 0;
    g_value_009239c4_guess = 0;
    g_value_009239c8_guess = 0;
    g_value_009239cc_guess = 0;
    g_value_009239d0_guess = 0;
    g_value_009239d4_guess = 0;
    g_value_009239d8_guess = 0;
    FUN_004c94ae_guess()->fieldf4_guess = 0;
    FUN_004c94ae_guess()->fieldf0_guess = 0;
    g_value_00923998_guess = 0;
    g_value_00923994_guess = 0;
    g_value_009239a8_guess = 0;
    g_value_009239ac_guess = 0;
    g_value_009239b0_guess = 0;
    g_flag_00923d7b_guess = 0;
    g_value_00923ca4_guess = 0;
    g_value_00923ca0_guess = 0;
    g_flag_00923d7a_guess = 0;
    g_flag_00923d2c_guess = 0;
    g_flag_00923d2d_guess = 0;
    g_flag_00923d2e_guess = 0;
    g_flag_00923d2f_guess = 0;
    g_flag_00923d30_guess = 0;
    g_flag_00923d31_guess = 0;
    g_flag_00923d32_guess = 0;
    g_flag_00923d33_guess = 0;
    g_flag_00923d34_guess = 0;
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    g_flag_009237b4_guess = 1;
    g_value_00923d40_guess = 0;
    g_value_00923d44_guess = 0;
    g_value_00923d48_guess = 0;
    g_value_00923d4c_guess = 0;
    g_value_00923d50_guess = 0;
    g_value_00923d54_guess = 0;
    g_value_00923d88_guess = 0;
    g_value_00923d8c_guess = 0;
    g_value_009238ec_guess = 0;
    g_value_009238f0_guess = 0;
    g_flag_00923d78_guess = 0;
    g_flag_00923d79_guess = 0;
    g_flag_00923d1c_guess = 0;
    g_flag_009237b7_guess = 0;
    g_value_009238f8_guess = 0;
    g_value_00923860_guess = 0;
    g_value_00923868_guess = 0;
    g_value_00923864_guess = 0;
    g_value_0092478c_guess = 0;
    g_value_00923cb8_guess = 0;
    SetDefaultVisionColors_guess();
    int* block_guess = EQ_ARRAY(int, 0x00923D08);
    *block_guess++ = 0;
    *block_guess++ = 0;
    *block_guess++ = 0;
    *block_guess++ = 0;
    strcpy(field17bb4_guess, g_text_0063f53f_guess);
    g_value_00924474_guess = -1;
    g_value_00923d90_guess = 0.0f;
    g_value_00923850_guess = 0;
    g_value_00923854_guess = 0;
    g_value_00923858_guess = 0;
    g_value_0092385c_guess = 0;
    g_value_00923888_guess = 0;
    g_value_00923890_guess = 0;
    g_value_0092388c_guess = 0;
    g_value_00923894_guess = 0;
    g_value_009238d8_guess = 0;
    g_value_009238dc_guess = 0;
    g_value_009238e4_guess = 0;
    g_flag_009238e0_guess = 0;
    g_flag_00924675_guess = 0;
    g_flag_00924676_guess = 0;
    g_value_00924678_guess = 1;
    g_value_0092467c_guess = 0;
    int count_guess = 0x14;
    do {
        count_guess--;
        g_flag_0095a174_guess = 0;
    } while (count_guess != 0);
    g_value_00924468_guess = 0;
    char* dest_guess = EQ_ARRAY(char, 0x00926D74);
    int* local4_guess = EQ_ARRAY(int, 0x009265A4);
    do {
        sprintf(dest_guess, "@");
        dest_guess += 0x100;
        *local4_guess++ = 0;
    } while ((int)dest_guess < (int)EQ_ARRAY(char, 0x00946174));
    void** slot_guess = EQ_ARRAY(void*, 0x009265A4);
    char* buf_guess = EQ_ARRAY(char, 0x00926D74);
    do {
        slot_guess[-0x881] = buf_guess;
        slot_guess[-0x868] = slot_guess;
        buf_guess += 0x100;
        slot_guess++;
    } while ((int)buf_guess < (int)EQ_ARRAY(char, 0x00928674));
    g_value_00924478_guess = 0;
    int* clear_guess = EQ_ARRAY(int, 0x00925520);
    for (int clearCount_guess = 0x100; clearCount_guess != 0; clearCount_guess--) {
        *clear_guess++ = 0;
    }
    for (int i_guess = 0; i_guess < 100; i_guess++) {
        EQ_ARRAY(unsigned char, 0x0092460C)[i_guess] = 1;
        EQ_ARRAY(int, 0x0092447C)[i_guess] = 0;
    }
    g_flag_00923845_guess = 0;
    g_flag_00923992_guess = 0;
    g_flag_00923991_guess = 0;
    g_flag_00923990_guess = 1;
    g_value_009237ec_guess = 8;
    g_char_009237f4_guess = 0;
    g_value_009237ec_guess = ReadClientIniInt_guess("Defaults", "DefaultChannel", 8);
    FUN_004ae514_guess(g_value_009237ec_guess, "Defaults", "DefaultChannel");
    if (g_value_009237ec_guess == 7) {
        FUN_004ae5e9_guess("Defaults", "DefaultChannelTell", "*NULL*",
            &g_char_009237f4_guess, 0x20);
        // A tell channel (7) whose target starts with '*' (*NULL*) falls back to say (8).
        if (g_char_009237f4_guess == 0x2a) {
            g_value_009237ec_guess = 8;
            g_char_009237f4_guess = 0;
        }
    }
    g_value_00923d18_guess = ReadClientIniInt_guess("Defaults", "ShowSpellDescriptions", 1);
    g_value_009237f0_guess = ReadClientIniInt_guess("Defaults", "DefaultLanguage", 0);
    FUN_004ae514_guess(g_value_009237f0_guess, "Defaults", "DefaultLanguage");
    int* tab_guess = EQ_ARRAY(int, 0x00923964);
    do {
        tab_guess[-10] = 0;
        *tab_guess = 0;
        tab_guess++;
    } while ((int)tab_guess < (int)EQ_ARRAY(int, 0x0092398C));
    g_value_0092398c_guess = 0;
    g_value_00923934_guess = 0;
    g_value_00923938_guess = 0;
    g_value_00923838_guess = 0;
    g_value_0092383c_guess = 0;
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    g_state_009237b0_guess = 0;
    g_flag_00924680_guess = 1;
    g_flag_009237b5_guess = 1;
    g_promptBlocked_009043a4_guess = 0;
    char* slot5_guess = EQ_ARRAY(char, 0x0090424D);
    for (int i5_guess = 0; i5_guess < 5; i5_guess++) {
        EQ_ARRAY(char, 0x00904248)[i5_guess] = 0;
        EQ_ARRAY(int, 0x00904390)[i5_guess] = 0;
        *slot5_guess = 0;
        slot5_guess += 0x40;
    }
}

// Zone-in step 2: sends OP_ZoneEntry and waits in game state 4 for the server to spawn this character;
// that spawn becomes the local player and the state goes to 0xFD. Quitting, a lost connection or 180 s
// without the spawn ends in state 0xFF and a teardown.
// FUNCTION: TITANIUM 0x004A8193
// @early-stop: budget, diff ndiff=49
void DisconnectOwner_guess::GetZoneInfoFromNetwork(const char* name_guess) {
    ZoneConnectMessage_guess message_guess;
    unsigned int startTime_guess;

    g_value_00905c00_guess = 0;
    g_value_00923d24_guess = 0;
    FUN_0060e450_guess(message_guess.name_guess, name_guess);
    message_guess.hash_guess = MemChecker0(message_guess.name_guess, 0x20);
    g_connection_00905ca0_guess->BeginWait_guess(
        g_connectionManager_guess != 0
            ? reinterpret_cast<DisconnectWaitState_guess*>(&g_connectionManager_guess->field48_guess)
            : 0);
    FUN_00574110_guess("Zone Connect -- 2 -- Sending MSG_EQ_ADDPLAYER");
    // OP_ZoneEntry: ClientZoneEntry_Struct, a checksum and the 64-byte character name.
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7213, &message_guess, 0x44, 1);
    startTime_guess = FUN_0046d655_guess();
    {
        int* state_guess = &g_globalState_guess->state_guess;
        g_globalState_guess->state_guess = 4;
        switch (*state_guess) {
        case 5:
            EnableAllCommands_guess();
            DisableCommand_guess(0x105);
            DisableCommand_guess(0x106);
            DisableCommand_guess(0x107);
            DisableCommand_guess(0x108);
            DisableCommand_guess(0x10a);
            DisableCommand_guess(0x109);
            break;
        case 2:
            DisableAllCommands_guess();
            EnableCommand_guess(0x10a);
            EnableCommand_guess(0x109);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        case 1:
            DisableAllCommands_guess();
            EnableCommand_guess(0x105);
            EnableCommand_guess(0x106);
            EnableCommand_guess(0x107);
            EnableCommand_guess(0x108);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        }
    }
    for (;;) {
        if (fieldb54_guess != 4) {
            return;
        }
        reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
        if (g_sendDisabled_00923798_guess == 0 &&
            // The original source file and line, used only in the disconnect log.
            CheckCharSelectDisconnect_guess("C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4351, 1) != 0) {
            return;
        }
        if (g_value_00905c00_guess == 0 || g_value_00923d24_guess == 0) {
            if (g_flag_00923d7b_guess == 1) {
                FUN_00574110_guess("disconnect, user quitting at %s:%u (GetZoneInfo)\n",
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x436d);
                break;
            }
        } else if (g_actorHead_guess != 0) {
            g_selectedActor_guess = (ActorNode_guess*)GetSpawnByName_guess((int)name_guess);
            if (g_selectedActor_guess == 0 &&
                (g_contextObject_guess == 0 ||
                 (g_selectedActor_guess = (ActorNode_guess*)GetSpawnByName_guess((int)(
                     g_contextObject_guess->field44_guess +
                     g_contextObject_guess->field08_guess->field04_guess)),
                  g_selectedActor_guess == 0))) {
                FUN_00574110_guess("g_pLocalPlayer is NULL for %s\n", name_guess);
            }
            g_selectedActor_guess->standState_0251_guess = 100;
            g_contextObject_guess->field44_guess[0xC8 +
                g_contextObject_guess->field08_guess->field04_guess] = 100;
            g_actorReset_guess = 0;
            g_actorStatus_guess = (int)g_selectedActor_guess;
            {
                int* state_guess = &g_globalState_guess->state_guess;
                g_globalState_guess->state_guess = 0xfd;
                switch (*state_guess) {
                case 5:
                    EnableAllCommands_guess();
                    DisableCommand_guess(0x105);
                    DisableCommand_guess(0x106);
                    DisableCommand_guess(0x107);
                    DisableCommand_guess(0x108);
                    DisableCommand_guess(0x10a);
                    DisableCommand_guess(0x109);
                    break;
                case 2:
                    DisableAllCommands_guess();
                    EnableCommand_guess(0x10a);
                    EnableCommand_guess(0x109);
                    EnableCommand_guess(0xb9);
                    EnableCommand_guess(0x101);
                    break;
                case 1:
                    DisableAllCommands_guess();
                    EnableCommand_guess(0x105);
                    EnableCommand_guess(0x106);
                    EnableCommand_guess(0x107);
                    EnableCommand_guess(0x108);
                    EnableCommand_guess(0xb9);
                    EnableCommand_guess(0x101);
                    break;
                }
            }
            return;
        }
        if (FUN_0046d655_guess() - startTime_guess > 180000) {
            DisplayScreen_guess("Respond.bmp");
            Sleep(2000);
            FUN_00574110_guess(
                "TIMED OUT WAITING FOR MY EQPlayer (in GetZoneInfoFromNetwork())!! top = %d\n",
                g_actorHead_guess);
            break;
        }
        Sleep(10);
    }
    field39400_guess = 1;
    {
        int* state_guess = &g_globalState_guess->state_guess;
        g_globalState_guess->state_guess = 0xff;
        switch (*state_guess) {
        case 5:
            EnableAllCommands_guess();
            DisableCommand_guess(0x105);
            DisableCommand_guess(0x106);
            DisableCommand_guess(0x107);
            DisableCommand_guess(0x108);
            DisableCommand_guess(0x10a);
            DisableCommand_guess(0x109);
            break;
        case 2:
            DisableAllCommands_guess();
            EnableCommand_guess(0x10a);
            EnableCommand_guess(0x109);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        case 1:
            DisableAllCommands_guess();
            EnableCommand_guess(0x105);
            EnableCommand_guess(0x106);
            EnableCommand_guess(0x107);
            EnableCommand_guess(0x108);
            EnableCommand_guess(0xb9);
            EnableCommand_guess(0x101);
            break;
        }
    }
    g_value_00923794_guess = 0xfd;
    fieldb50_guess = 1;
    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
}

// Builds the 3D actors for the known spawns, makes the one named like the character the local player,
// then creates any missing '<name>_ACTORDEF' definitions and part actors.
// FUNCTION: TITANIUM 0x00496B5A
void GlobalState_guess::CreateInitialActors_guess() {
    char actorDefinitionName_guess[128];
    ActorNode_guess* actor_guess = g_actorHead_guess;
    for (; actor_guess != 0; actor_guess = actor_guess->next_guess) {
        if (*actor_guess->pActorInfo_01a8_guess == 0) {
            g_actorDisplay_guess->FUN_0043c84b_guess(actor_guess);
            actor_guess->UpdateLight_guess();
        }
    }
    actor_guess = g_actorHead_guess;
    for (; actor_guess != 0; actor_guess = actor_guess->next_guess) {
        if (g_contextObject_guess != 0 &&
            strcmp(g_contextObject_guess->field44_guess +
                g_contextObject_guess->field08_guess->field04_guess,
                actor_guess->name_guess) == 0) {
            g_selectedActor_guess = actor_guess;
            actor_guess->standState_0251_guess = 100;
            g_contextObject_guess->field44_guess[
                0xC8 + g_contextObject_guess->field08_guess->field04_guess] = 100;
            g_actorReset_guess = 0;
            g_actorStatus_guess = reinterpret_cast<int>(g_selectedActor_guess);
            g_actorDisplay_guess->FUN_0043910d_guess(
                *actor_guess->pActorInfo_01a8_guess);
        }
        if (actor_guess->type_0244_guess == 1) {
            actor_guess->MakeRiderMountUp_guess();
        }
    }
    ActorDefinitionNode_guess* definition_guess = g_actorDefinitionHead_guess;
    for (; definition_guess != 0; definition_guess = definition_guess->next_guess) {
        if (definition_guess->cached14_guess == 0) {
            _sprintf(actorDefinitionName_guess, "%s_ACTORDEF", definition_guess->name_guess);
            definition_guess->cached14_guess = g_actorDisplay_guess->CreateActor_guess(
                actorDefinitionName_guess, definition_guess->value28_guess,
                definition_guess->value24_guess, definition_guess->value20_guess,
                definition_guess->value1c_guess, 0.0f, 0.0f, 1, 1);
        }
    }
    ActorPartNode_guess* part_guess = g_actorPartHead_guess;
    for (; part_guess != 0; part_guess = part_guess->next_guess) {
        if (part_guess->cached34_guess == 0) {
            part_guess->cached34_guess = g_actorDisplay_guess->CreateActor_guess(
                part_guess->name_guess, part_guess->value38_guess,
                part_guess->value3c_guess, part_guess->value40_guess,
                part_guess->value44_guess, part_guess->value48_guess,
                0.0f, 1, 1);
        }
    }
}

// Before zoning (MoveToZone): drops the vehicle (+0x158) and its name, then moves the player to safe
// coordinates (0x43D7C5).
// FUNCTION: TITANIUM 0x00496D00
void ClearVehicleBeforeZone_guess() {
    g_resetOwner_guess->pActorInfo_01a8_guess->field158_guess = 0;
    reinterpret_cast<TextReceiver_guess*>(reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 0xC4)->FUN_0040e25c_guess(g_text_0063f53f_guess);
    g_clockData_guess->MoveLocalPlayerToSafeCoords_guess();
}

struct MessageData_guess {
    char padding_0000_guess[4];
    unsigned char field04_guess;
};

// Stores the LFG flag on the player and sends it (OP_LFGCommand 0x68AC, 0x50 bytes).
// FUNCTION: TITANIUM 0x00496D39
void GlobalState_guess::SendLFGCommand_guess(void* data_guess) {
    if (g_resetOwner_guess != 0) {
        g_resetOwner_guess->lfg_01b4_guess =
            reinterpret_cast<MessageData_guess*>(data_guess)->field04_guess;
        g_resetOwner_guess->RefreshNameSprite_guess();
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x68ac, data_guess, 0x50, 1);
    }
}

// Sends a looking-for-players update (OP_LFPCommand 0x6F82, 0x54 bytes).
// FUNCTION: TITANIUM 0x00496D76
char GlobalState_guess::SendLFPCommand_guess(void* data_guess) {
    return FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6f82, data_guess, 0x54, 1);
}

// Asks for LFG matches (OP_LFGGetMatchesRequest 0x022F, 0x10 bytes).
// FUNCTION: TITANIUM 0x00496D93
char GlobalState_guess::SendLFGGetMatchesRequest_guess(void* data_guess) {
    return FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x22f, data_guess, 0x10, 1);
}

// Asks for LFP matches (OP_LFPGetMatchesRequest 0x35A6, 0xC bytes).
// FUNCTION: TITANIUM 0x00496DB0
char GlobalState_guess::SendLFPGetMatchesRequest_guess(void* data_guess) {
    return FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x35a6, data_guess, 0xc, 1);
}

// The notifier subobject of CEverQuest sits at +8 (see CEverQuest_guess below).
struct EverQuestNotifierCall_guess {
    // EXTERNAL: TITANIUM 0x005482A0 EverQuestNotifierCall_guess::Purge_guess
    void Purge_guess(int value_guess);
};

struct EverQuestNotifierSlot_guess {
    char padding_0000_guess[8];
    EverQuestNotifierCall_guess notifier_guess;
};

// Releases one count each of the pending-request counters 0x9248D4 and 0x9248D0 (never below 0),
// drops queued popup 0x82 and, with `flag`, sends opcode 0x1781 (not in patch_Titanium.conf) empty.
// FUNCTION: TITANIUM 0x00496DCD
void GlobalState_guess::ReleasePendingRequest_guess(char flag_guess) {
    int zero_guess = 0;
    g_value_009248d4_guess = g_value_009248d4_guess - 1;
    if (g_value_009248d4_guess < 0) {
        g_value_009248d4_guess = zero_guess;
    }
    g_value_009248d0_guess = g_value_009248d0_guess - 1;
    if (g_value_009248d0_guess < 0) {
        g_value_009248d0_guess = zero_guess;
    }
    reinterpret_cast<EverQuestNotifierSlot_guess*>(pEverQuest)->notifier_guess.Purge_guess(0x82);
    if (flag_guess != 0) {
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1781, 0, 0, 1);
    }
}

#define g_value_00983b80_guess EQ_GLOBAL(int, 0x00983B80)
#define g_flag_00983b7c_guess EQ_GLOBAL(unsigned char, 0x00983B7C)
#define g_flag_009839e5_guess EQ_GLOBAL(unsigned char, 0x009839E5)
#define g_value_00983b84_guess EQ_GLOBAL(unsigned char, 0x00983B84)
#define g_value_00983b88_guess EQ_GLOBAL(int, 0x00983B88)
#define g_value_00983b8c_guess EQ_GLOBAL(unsigned char, 0x00983B8C)
#define g_flag_009839e6_guess EQ_GLOBAL(unsigned char, 0x009839E6)
#define g_value_00983b90_guess EQ_GLOBAL(int, 0x00983B90)
#define g_value_00983b94_guess EQ_GLOBAL(unsigned char, 0x00983B94)
#define g_value_00983b98_guess EQ_GLOBAL(int, 0x00983B98)
#define g_value_00983b9c_guess EQ_GLOBAL(unsigned char, 0x00983B9C)
#define g_value_00983ba0_guess EQ_GLOBAL(int, 0x00983BA0)
#define g_flag_00983ba4_guess EQ_GLOBAL(unsigned char, 0x00983BA4)
#define g_value_00983ba8_guess EQ_GLOBAL(int, 0x00983BA8)
#define g_flag_009839e7_guess EQ_GLOBAL(unsigned char, 0x009839E7)
#define g_flag_009839e8_guess EQ_GLOBAL(unsigned char, 0x009839E8)
#define g_flag_009839e9_guess EQ_GLOBAL(unsigned char, 0x009839E9)
#define g_flag_009839ea_guess EQ_GLOBAL(unsigned char, 0x009839EA)
#define g_value_00983bac_guess EQ_GLOBAL(unsigned char, 0x00983BAC)
#define g_value_00983bb0_guess EQ_GLOBAL(int, 0x00983BB0)
#define g_flag_009839eb_guess EQ_GLOBAL(unsigned char, 0x009839EB)
#define g_flag_009839ec_guess EQ_GLOBAL(unsigned char, 0x009839EC)
#define g_flag_009839ed_guess EQ_GLOBAL(unsigned char, 0x009839ED)
#define g_flag_009839ee_guess EQ_GLOBAL(unsigned char, 0x009839EE)
#define g_value_00983bb4_guess EQ_GLOBAL(unsigned char, 0x00983BB4)
#define g_value_00983bb8_guess EQ_GLOBAL(int, 0x00983BB8)
#define g_value_00983bbc_guess EQ_GLOBAL(unsigned char, 0x00983BBC)
#define g_value_00983bc0_guess EQ_GLOBAL(int, 0x00983BC0)
#define g_value_00983bc4_guess EQ_GLOBAL(unsigned char, 0x00983BC4)
#define g_value_00983bc8_guess EQ_GLOBAL(int, 0x00983BC8)

struct ContextEntry_guess {
    char padding_0000_guess[0x4C];
    int value4c_guess;
    // EXTERNAL: TITANIUM 0x005E0F00 ContextEntry_guess::FUN_005e0f00_guess
    char* FUN_005e0f00_guess();
};

struct ContextSelector_guess {
    char padding_0000_guess[4];
    EQ_CharacterProfileView_guess finder_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 ContextSelector_guess::GetInventorySlot_guess
    ContextEntry_guess* GetInventorySlot_guess(int index_guess);
};

struct ContextActorData_guess {
    char padding_0000_guess[0x11D0];
    unsigned char field11d0_guess;
};

struct ContextResult_guess {
    char padding_0000_guess[0x1198];
    int field1198_guess; // 0x1198
    unsigned char field119c_guess; // 0x119C
};

// Default hot buttons: skills by class (+0x119C; kick 0x1E, taunt 0x49 ...) and by race (+0x1198:
// forage 0x1B for wood elves and iksar, hide 0x1D for dark elves, sneak 0x2A for halflings, vah shir).
// FUNCTION: TITANIUM 0x00496E20
void GlobalState_guess::SetDefaultClassHotButtons_guess() {
    g_value_00983b80_guess = 0;
    g_flag_00983b7c_guess = 1;
    g_flag_009839e5_guess = 1;
    ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    unsigned char state_guess = reinterpret_cast<ContextResult_guess*>(
        selector_guess->finder_guess.GetCharInfo2())->field119c_guess;
    switch (state_guess) {
    case 1:
        g_value_00983b84_guess = 9;
        g_value_00983b88_guess = 10;
        g_flag_009839e6_guess = 1;
        g_value_00983b90_guess = 0x49;
        g_value_00983b94_guess = 9;
        g_value_00983b98_guess = 0x1e;
        g_value_00983b8c_guess = 9;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839e7_guess = 1;
        g_flag_009839e8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 16:
        g_value_00983b94_guess = 9;
        g_value_00983b98_guess = 0x1e;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839e8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 3:
        g_value_00983ba0_guess = 0x6b;
        g_value_00983b84_guess = 9;
        g_value_00983b88_guess = 10;
        g_flag_009839e6_guess = 1;
        g_value_00983b8c_guess = 9;
        g_value_00983b90_guess = 0x49;
        g_flag_009839e7_guess = 1;
        g_value_00983b9c_guess = 9;
        g_flag_009839e9_guess = 1;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 5:
        g_value_00983ba0_guess = 0x69;
        g_value_00983b84_guess = 9;
        g_value_00983b88_guess = 10;
        g_flag_009839e6_guess = 1;
        g_value_00983b8c_guess = 9;
        g_value_00983b90_guess = 0x49;
        g_flag_009839e7_guess = 1;
        g_value_00983b9c_guess = 9;
        g_flag_009839e9_guess = 1;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 4:
        g_value_00983b90_guess = 0x49;
        g_value_00983b94_guess = 9;
        g_value_00983b98_guess = 0x35;
        g_value_00983b8c_guess = 9;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839e7_guess = 1;
        g_flag_009839e8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 7:
        g_value_00983b90_guess = 0x1e;
        g_value_00983b9c_guess = 9;
        g_value_00983ba0_guess = 0x20;
        g_value_00983b8c_guess = 9;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839e7_guess = 1;
        g_flag_009839e8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 9:
        g_value_00983bac_guess = 9;
        g_value_00983bb0_guess = 0x2a;
        g_flag_009839eb_guess = 1;
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 15:
        g_flag_00983ba4_guess = 1;
        g_value_00983ba8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    case 8:
        g_value_00983b90_guess = 0;
        g_value_00983b84_guess = 9;
        g_value_00983b88_guess = 10;
        g_flag_009839e6_guess = 1;
        g_value_00983b8c_guess = 7;
        g_flag_009839e7_guess = 1;
        g_value_00983b94_guess = 7;
        g_value_00983b98_guess = 1;
        g_flag_009839e8_guess = 1;
        g_value_00983b9c_guess = 9;
        g_value_00983ba0_guess = 0x49;
        g_flag_009839e9_guess = 1;
        break;
    case 2:
    case 6:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        g_value_00983b90_guess = 0;
        g_value_00983b8c_guess = 7;
        g_value_00983b94_guess = 7;
        g_value_00983b98_guess = 1;
        g_value_00983b9c_guess = 7;
        g_value_00983ba0_guess = 2;
        g_flag_009839e9_guess = 1;
        g_flag_00983ba4_guess = 6;
        g_value_00983ba8_guess = 10;
        g_flag_009839e7_guess = 1;
        g_flag_009839e8_guess = 1;
        g_flag_009839ea_guess = 1;
        break;
    }
    ContextSelector_guess* selector2_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    int value_guess = reinterpret_cast<ContextResult_guess*>(
        selector2_guess->finder_guess.GetCharInfo2())->field1198_guess;
    switch (value_guess) {
    case 4:
        g_value_00983bb0_guess = 0x1b;
        g_value_00983bac_guess = 9;
        g_flag_009839eb_guess = 1;
        break;
    case 6:
        g_value_00983bb0_guess = 0x1d;
        g_value_00983bac_guess = 9;
        g_flag_009839eb_guess = 1;
        break;
    case 11:
        g_value_00983bb0_guess = 0x2a;
        g_value_00983bb4_guess = 9;
        g_value_00983bb8_guess = 0x1d;
        g_flag_009839ec_guess = 1;
        g_value_00983bac_guess = 9;
        g_flag_009839eb_guess = 1;
        break;
    case 0x80:
        g_value_00983bb0_guess = 0x1b;
        g_value_00983bac_guess = 9;
        g_flag_009839eb_guess = 1;
        break;
    case 0x82:
        g_value_00983bb0_guess = 0x2a;
        g_value_00983bac_guess = 9;
        g_flag_009839eb_guess = 1;
        break;
    }
    g_flag_009839ed_guess = 1;
    g_flag_009839ee_guess = 1;
    g_value_00983bbc_guess = 6;
    g_value_00983bc0_guess = 4;
    g_value_00983bc4_guess = 6;
    g_value_00983bc8_guess = 0xc;
}

// Deletes the mail list (see GetMailManager 0x495250); ~CEverQuest calls it.
// FUNCTION: TITANIUM 0x00497123
void SlotOwner_guess::DeleteMailManager_guess() {
    ManagedObject_guess** slot_guess = &field3a1c4_guess;
    ManagedObject_guess* object_guess = *slot_guess;
    if (object_guess != 0) {
        object_guess->FUN_0042c1b2_guess();
        free(object_guess);
        *slot_guess = 0;
    }
}

/* ---- CEverQuest::~CEverQuest (0x00497395) -----------------------------------------------------------
 * CEverQuest (0x3A1C8, include/titanium/types.h) has three polymorphic bases at +0, +4 and +8; only the
 * one at +8 has a destructor (inline: unregisters itself from the 0x00991E44 table, 0x005482A0). */

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

// The C runtime free (0x0060E07D). This file's `free` is bound to operator delete (0x0060D0D5) above.
// EXTERNAL: TITANIUM 0x0060E07D CrtFree_guess
void __cdecl CrtFree_guess(void* memory_guess);

struct EverQuestBase0_guess {
    virtual void RefreshCounts_guess();
};

// EXTERNAL: TITANIUM 0x00649190 ??_7EverQuestBase4_guess@@6B@
struct EverQuestBase4_guess {
    virtual void RefreshCounts_guess();
};

// Message block for the notifier handler below; the int* of the original, read at its offsets.
struct NotifyPacket_guess {
    int id00_guess;
    unsigned char flag04_guess;
    char pad05_guess[0x3B];
    char name40_guess[0x40];
    int f80_guess;
    int f84_guess;
    int f88_guess;
    char pad8c_guess[0x54];
    int flagE0_guess;
    char padE4_guess[4];
    unsigned char flagE8_guess;
};

struct NotifyBuf88_guess {
    char name00_guess[0x40];
    char charName40_guess[0x40];
    int f80_guess;
    int f84_guess;
};

struct NotifyBuf0C_guess {
    int zero00_guess;
    unsigned int field04_guess;
    int active08_guess;
};

struct NotifyBuf5C_guess {
    char pad00_guess[0x58];
    int f58_guess;
};

struct NotifyBuf44_guess {
    int f00_guess;
    char name04_guess[0x40];
};

struct NotifyBuf64_guess {
    char name00_guess[0x40];
    int zero40_guess;
    char text44_guess[0x14];
    char tail58_guess[0xC];
};

struct NotifyBuf84_guess {
    char text00_guess[0x40];
    char name40_guess[0x40];
    int zero80_guess;
};

struct NotifyCharInfo_guess {
    char pad00_guess[0x88];
    int f88_guess;
};

struct NotifyDisplay_guess {
    char pad00_guess[0x10];
    bool flag10_guess;
};

struct NotifyPlayer_guess {
    // EXTERNAL: TITANIUM 0x0048127E NotifyPlayer_guess::UpdateEquipmentDisplay_guess
    void UpdateEquipmentDisplay_guess(int id_guess);
};

// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(EQ_PC* pc_guess);

#define g_displayFlag_guess EQ_GLOBAL(NotifyDisplay_guess*, 0x00905D24)
#define g_playerAction_guess EQ_GLOBAL(NotifyPlayer_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x0063FD9C ??_7EverQuestNotifier_guess@@6B@
struct EverQuestNotifier_guess {
    virtual void RemoveBenefit_guess() = 0;
    ~EverQuestNotifier_guess() { Purge_guess(-1); }
    // EXTERNAL: TITANIUM 0x005482A0 EverQuestNotifier_guess::Purge_guess
    void Purge_guess(int value_guess);
    void DialogResponse_guess(int msg_guess, unsigned int flags_guess,
        NotifyPacket_guess* data_guess);
};

// One of the 0x200 records at CEverQuest+0xBAC (0xB8 bytes each).
struct EverQuestSlotEntry_guess {
    int id_guess;            // 0x00
    int field04_guess;       // 0x04
    int field08_guess;       // 0x08
    int field0c_guess;       // 0x0C
    char text10_guess[0x20]; // 0x10
    char text30_guess[0x44]; // 0x30
    char text74_guess[0x44]; // 0x74
};

// EXTERNAL: TITANIUM 0x006498D4 ??_7CEverQuest_guess@@6BEverQuestBase0_guess@@@
// EXTERNAL: TITANIUM 0x00649890 ??_7CEverQuest_guess@@6BEverQuestBase4_guess@@@
// EXTERNAL: TITANIUM 0x0064988C ??_7CEverQuest_guess@@6BEverQuestNotifier_guess@@@
struct CEverQuest_guess : EverQuestBase0_guess, EverQuestBase4_guess, EverQuestNotifier_guess {
    char field00c_guess[0x80];           // 0x00C
    int field08c_guess;                  // 0x08C
    char field090_guess[0x100];          // 0x090
    char field190_guess[0x100];          // 0x190
    int field290_guess;                  // 0x290
    char field294_guess;                 // 0x294
    int field298_guess;                  // 0x298
    int field29c_guess;                  // 0x29C
    char field2a0_guess;                 // 0x2A0
    char field2a1_guess[0x100];          // 0x2A1
    char field3a1_guess[0x1e0];          // 0x3A1
    int field584_guess[10];              // 0x584
    int field5ac_guess;                  // 0x5AC
    char field5b0_guess[0x80];           // 0x5B0
    int field630_guess;                  // 0x630
    char field634_guess[0x100];          // 0x634
    char field734_guess[0x100];          // 0x734
    int field834_guess;                  // 0x834
    int field838_guess;                  // 0x838
    int field83c_guess;                  // 0x83C
    char field840_guess;                 // 0x840
    char field841_guess[0x100];          // 0x841
    char field941_guess[0x1e0];          // 0x941
    int fieldb24_guess[10];              // 0xB24
    int fieldb4c_guess;                  // 0xB4C
    int fieldb50_guess;                  // 0xB50
    int fieldb54_guess;                  // 0xB54
    int fieldb58_guess;                  // 0xB58
    float fieldb5c_guess;                // 0xB5C
    char fieldb60_guess;                 // 0xB60
    char padding_0b61_guess[0xBAC - 0xB61];
    EverQuestSlotEntry_guess entries_guess[0x200]; // 0xBAC
    int field17bac_guess;                // 0x17BAC
    int field17bb0_guess;                // 0x17BB0
    char field17bb4_guess[0x840];        // 0x17BB4
    int field183f4_guess;                // 0x183F4
    char field183f8_guess;               // 0x183F8
    char padding_183f9_guess[0x393FC - 0x183F9];
    int field393fc_guess;                // 0x393FC
    int field39400_guess;                // 0x39400
    char padding_39404_guess[0x3971C - 0x39404];
    int field3971c_guess[10];            // 0x3971C
    char padding_39744_guess[0x397A0 - 0x39744];
    int field397a0_guess[10];            // 0x397A0
    char padding_397c8_guess[0x39810 - 0x397C8];
    char field39810_guess[10][0x40];     // 0x39810
    char padding_39a90_guess[0x39AB8 - 0x39A90];
    char field39ab8_guess;               // 0x39AB8
    char field39ab9_guess;               // 0x39AB9
    char field39aba_guess[0x200];        // 0x39ABA
    char field39cba_guess[0x400];        // 0x39CBA
    char field3a0ba_guess[0x100];        // 0x3A0BA
    char field3a1ba_guess;               // 0x3A1BA
    char field3a1bb_guess;               // 0x3A1BB
    int field3a1bc_guess;                // 0x3A1BC
    int field3a1c0_guess;                // 0x3A1C0
    int field3a1c4_guess;                // 0x3A1C4
    CEverQuest_guess(int window_guess);
    void LoadStringTables_guess();
    // EXTERNAL: TITANIUM 0x004AF32C CEverQuest_guess::loadOptions_guess
    void loadOptions_guess();
    virtual void RemoveBenefit_guess();
    void EnterZone(int unused_guess);
    char IFoundMyVehicle_guess();
    ~CEverQuest_guess();
};

struct Owned44C426_guess {
    char padding_0000_guess[0xBAFC];
    // EXTERNAL: TITANIUM 0x0044CA8F Owned44C426_guess::Owned44C426_guess
    Owned44C426_guess(bool disabled_guess, bool sound44k_guess, int speaker_guess);
    // EXTERNAL: TITANIUM 0x0044C426 ??1Owned44C426_guess@@QAE@XZ
    ~Owned44C426_guess();
};

struct Owned4CBAAF_guess {
    char padding_0000_guess[0x18];
    // EXTERNAL: TITANIUM 0x004CBA68 Owned4CBAAF_guess::Owned4CBAAF_guess
    Owned4CBAAF_guess();
    // EXTERNAL: TITANIUM 0x004CBAAF ??1Owned4CBAAF_guess@@QAE@XZ
    ~Owned4CBAAF_guess();
};

struct Owned4482A9_guess {
    char padding_0000_guess[0x404];
    // EXTERNAL: TITANIUM 0x004482A9 Owned4482A9_guess::Owned4482A9_guess
    Owned4482A9_guess(int first_guess, int second_guess);
};

struct Owned4C9AF0_guess {
    char padding_0000_guess[0x4F0E8];
    // EXTERNAL: TITANIUM 0x004C9AF0 Owned4C9AF0_guess::Owned4C9AF0_guess
    Owned4C9AF0_guess();
};

struct Owned424982_guess {
    char padding_0000_guess[0x10];
    // EXTERNAL: TITANIUM 0x00424631 Owned424982_guess::Owned424982_guess
    Owned424982_guess();
    // EXTERNAL: TITANIUM 0x00424A2C Owned424982_guess::LoadAutoJoinChannels_guess
    void LoadAutoJoinChannels_guess(const char* file_guess);
    // EXTERNAL: TITANIUM 0x00424982 ??1Owned424982_guess@@QAE@XZ
    ~Owned424982_guess();
    // EXTERNAL: TITANIUM 0x00424642 Owned424982_guess::UpdateAutoJoinChannels_guess
    void UpdateAutoJoinChannels_guess(void* value_guess);
};

struct OwnedStringTable_guess {
    char padding_0000_guess[0x10];
    // EXTERNAL: TITANIUM 0x005DF980 OwnedStringTable_guess::OwnedStringTable_guess
    OwnedStringTable_guess();
    // EXTERNAL: TITANIUM 0x005DF9B0 ??1OwnedStringTable_guess@@QAE@XZ
    ~OwnedStringTable_guess();
};

struct OwnedRecord_guess {
    char padding_0000_guess[0x2F4];
    // EXTERNAL: TITANIUM 0x00448D94 OwnedRecord_guess::OwnedRecord_guess
    OwnedRecord_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00469DD7 ??1OwnedRecord_guess@@QAE@XZ
    ~OwnedRecord_guess();
};

struct Owned4C7666_guess {
    char padding_0000_guess[0x138EC];
    // EXTERNAL: TITANIUM 0x004C7481 Owned4C7666_guess::Owned4C7666_guess
    Owned4C7666_guess(char* path_guess);
    // EXTERNAL: TITANIUM 0x004C7666 ??1Owned4C7666_guess@@QAE@XZ
    ~Owned4C7666_guess();
};

struct Owned4B445E_guess {
    char padding_0000_guess[0x7C];
    // EXTERNAL: TITANIUM 0x004B3F48 Owned4B445E_guess::Owned4B445E_guess
    Owned4B445E_guess();
    // EXTERNAL: TITANIUM 0x004B445E ??1Owned4B445E_guess@@QAE@XZ
    ~Owned4B445E_guess();
};

struct Owned554D6C_guess {
    char padding_0000_guess[0x10];
    // EXTERNAL: TITANIUM 0x0055474C Owned554D6C_guess::Owned554D6C_guess
    Owned554D6C_guess();
    // EXTERNAL: TITANIUM 0x00554D6C ??1Owned554D6C_guess@@QAE@XZ
    ~Owned554D6C_guess();
};

struct Owned4C9A90_guess {
    char padding_0000_guess[0x10];
    // EXTERNAL: TITANIUM 0x004C9807 Owned4C9A90_guess::Owned4C9A90_guess
    Owned4C9A90_guess();
    // EXTERNAL: TITANIUM 0x004C9A90 ??1Owned4C9A90_guess@@QAE@XZ
    ~Owned4C9A90_guess();
};

struct Owned404AA5_guess {
    char padding_0000_guess[0x28];
    // EXTERNAL: TITANIUM 0x00404A68 Owned404AA5_guess::Owned404AA5_guess
    Owned404AA5_guess();
    // EXTERNAL: TITANIUM 0x00404AA5 ??1Owned404AA5_guess@@QAE@XZ
    ~Owned404AA5_guess();
};

struct Owned448314_guess {
    // EXTERNAL: TITANIUM 0x00448314 ??1Owned448314_guess@@QAE@XZ
    ~Owned448314_guess();
};

struct CDisplay_guess {
    int error_guess; // 0x00
    char padding_0004_guess[0xC];
    char field10_guess; // 0x10
    char padding_0011_guess[0x113];
    int field124_guess;
    char padding_0128_guess[0x20];
    int field148_guess;
    char padding_014c_guess[0x2D70 - 0x14C];
    // EXTERNAL: TITANIUM 0x0043DA73 CDisplay_guess::CDisplay_guess
    CDisplay_guess(int window_guess);
    // EXTERNAL: TITANIUM 0x00438916 CDisplay_guess::LoadBMPFile_guess
    char LoadBMPFile_guess();
    // EXTERNAL: TITANIUM 0x00445A6C CDisplay_guess::Render_World_guess
    void Render_World_guess();
    // EXTERNAL: TITANIUM 0x00439D16 CDisplay_guess::PlayerDistance_guess
    float PlayerDistance_guess(void* source_guess, int value_guess, float threshold_guess);
    // EXTERNAL: TITANIUM 0x00443F8F CDisplay_guess::InitDisplay_guess
    void InitDisplay_guess();
    // EXTERNAL: TITANIUM 0x0043DF32 CDisplay_guess::InitWorld_guess
    void InitWorld_guess();
    // EXTERNAL: TITANIUM 0x0043DCA1 ??1CDisplay_guess@@QAE@XZ
    ~CDisplay_guess();
};

struct OwnedVirtual_guess {
    char padding_0004_guess[0xFBC - 4];
    // EXTERNAL: TITANIUM 0x005F7000 OwnedVirtual_guess::OwnedVirtual_guess
    OwnedVirtual_guess();
    virtual ~OwnedVirtual_guess();
};

// pCharData's class: the virtual base (vfptr at +0, virtual dtor in slot 1) via the vbptr at +8.
struct CharDataBase_guess : EQ_CharacterProfile_guess {
    virtual void RefreshCounts_guess();
    virtual ~CharDataBase_guess();
    CHARINFO2* Info_guess() { return GetCharInfo2(); }
    char padding_000c_guess[0x30];
    char name_guess[0x40]; // 0x3C
};

struct CharDataPrefix_guess {
    virtual void RefreshCounts_guess();
    int field04_guess;
};

struct CharData_guess : CharDataPrefix_guess, virtual CharDataBase_guess {
    // EXTERNAL: TITANIUM 0x004BC38C CharData_guess::IsMyClassGuildmaster_guess
    char IsMyClassGuildmaster_guess(ActorTarget_guess* target_guess);
};

// EXTERNAL: TITANIUM 0x00406B35 FreeAudioTriggerManager_guess
void __cdecl FreeAudioTriggerManager_guess();
// EXTERNAL: TITANIUM 0x004B90EF DestroyItemTintTable_guess
void __cdecl DestroyItemTintTable_guess();
// EXTERNAL: TITANIUM 0x004B90CD DestroyNpcTintTable_guess
void __cdecl DestroyNpcTintTable_guess();
// EXTERNAL: TITANIUM 0x004B6DB3 FUN_004b6db3_guess
void __cdecl FUN_004b6db3_guess();

#define g_displayState_00903e84_guess EQ_GLOBAL(DisplayState_guess*, 0x00903E84)
#define g_owned_00851390_guess EQ_GLOBAL(Owned44C426_guess*, 0x00851390)
#define g_owned_00985d90_guess EQ_GLOBAL(Owned4CBAAF_guess*, 0x00985D90)
#define g_owned_0079dbd4_guess EQ_GLOBAL(Owned424982_guess*, 0x0079DBD4)
#define g_ownedStringTable_guess EQ_GLOBAL(OwnedStringTable_guess*, 0x00905CB0)
#define g_ownedDisplay_guess EQ_GLOBAL(CDisplay_guess*, 0x00905D24)
#define g_charData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)
#define g_owned_00985cc8_guess EQ_GLOBAL(Owned4C7666_guess*, 0x00985CC8)
#define g_owned_009859ec_guess EQ_GLOBAL(Owned4B445E_guess*, 0x009859EC)
#define g_owned_00985cf0_guess EQ_GLOBAL(OwnedRecord_guess*, 0x00985CF0)
#define g_owned_00991fa8_guess EQ_GLOBAL(Owned554D6C_guess*, 0x00991FA8)
#define g_owned_00985cec_guess EQ_GLOBAL(Owned4C9A90_guess*, 0x00985CEC)
#define g_owned_0079c120_guess EQ_GLOBAL(Owned404AA5_guess*, 0x0079C120)
#define g_owned_00905c9c_guess EQ_GLOBAL(Owned448314_guess*, 0x00905C9C)
#define g_owned_00905cc0_guess EQ_GLOBAL(OwnedVirtual_guess*, 0x00905CC0)
#define g_value_00905ca0_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_value_00905cc4_guess EQ_GLOBAL(int, 0x00905CC4)
#define g_value_00905cc8_guess EQ_GLOBAL(int, 0x00905CC8)
#define g_value_00905ccc_guess EQ_GLOBAL(int, 0x00905CCC)
#define g_value_00905cd0_guess EQ_GLOBAL(int, 0x00905CD0)
#define g_value_00905cd4_guess EQ_GLOBAL(int, 0x00905CD4)
#define g_value_00905cd8_guess EQ_GLOBAL(int, 0x00905CD8)
#define g_value_00905cdc_guess EQ_GLOBAL(int, 0x00905CDC)
#define g_buffer_00924830_guess EQ_GLOBAL(void*, 0x00924830)
#define g_value_0092483c_guess EQ_GLOBAL(int, 0x0092483C)
#define g_value_00924840_guess EQ_GLOBAL(int, 0x00924840)
#define g_value_00924838_guess EQ_GLOBAL(int, 0x00924838)
#define g_value_00924844_guess EQ_GLOBAL(int, 0x00924844)

// A real array (0x00851200, 100 entries): tests/unicorn/crt_defaults.json maps the symbol (the loop
// compares the element address with the array's end, which EQ_ARRAY does not give).
extern OwnedRecord_guess* g_records_00851200_guess[100];

// Command table entries: 28 bytes each, from 0x0078A0C8 to 0x0078CEB8.
struct CommandEntry_guess {
    int id_guess;            // 0x00
    const char* name_guess;  // 0x04
    char* text_guess;        // 0x08
    void (__cdecl* handler_guess)(void*, const char*); // 0x0C
    int field10_guess;       // 0x10
    int field14_guess;       // 0x14
    unsigned char flags_guess; // 0x18
    char padding_0019_guess[3]; // 0x19
};

// Loads eqstr_<lang>.txt (plus betastr_<lang>.txt on the 'beta' world) and dbstr_<lang>.txt, then
// the localised /command names; a command missing from the table keeps its English name.
// FUNCTION: TITANIUM 0x004971AD
void CEverQuest_guess::LoadStringTables_guess() {
    FUN_00574110_guess("Loading string tables.");
    int lang_guess = EQ_GLOBAL(int, 0x00923D74);
    if (g_ownedStringTable_guess != 0) {
        delete g_ownedStringTable_guess;
    }
    g_ownedStringTable_guess = 0;
    g_ownedStringTable_guess = new OwnedStringTable_guess();
    bool beta_guess = false;
    char buf_guess[256];
    if (_stricmp(EQ_ARRAY(char, 0x0095D3D4), "beta") == 0) {
        beta_guess = true;
    }
    sprintf(buf_guess, "eqstr_%s.txt", EQ_ARRAY(const char*, 0x00799830)[lang_guess]);
    g_stringTable_guess->Load_guess(buf_guess, 3);
    if (beta_guess) {
        sprintf(buf_guess, "betastr_%s.txt", EQ_ARRAY(const char*, 0x00799830)[lang_guess]);
        g_stringTable_guess->Load_guess(buf_guess, 3);
    }
    if (g_dbStringManager_guess != 0) {
        delete g_dbStringManager_guess;
    }
    g_dbStringManager_guess = 0;
    g_dbStringManager_guess = new DbStringManager_guess(0x10);
    sprintf(buf_guess, "dbstr_%s.txt", EQ_ARRAY(const char*, 0x00799830)[lang_guess]);
    g_dbStringManager_guess->FUN_004356cc_guess(buf_guess);
    CommandEntry_guess* end_guess = EQ_ARRAY(CommandEntry_guess, 0x0078CEB8);
    for (int i_guess = 0; i_guess < EQ_GLOBAL(int, 0x006450B8); i_guess++) {
        CommandEntry_guess* entry_guess = &EQ_ARRAY(CommandEntry_guess, 0x0078A0C8)[i_guess];
        if (entry_guess != end_guess) {
            entry_guess->text_guess = 0;
        }
        if (entry_guess->id_guess != -1) {
            bool found_guess;
            char* text_guess = pStringTable->getString(entry_guess->id_guess, &found_guess);
            if (found_guess == true) {
                entry_guess->text_guess = text_guess;
            } else {
                sprintf(buf_guess,
                    // The message is formatted but never logged (original).
                    "/COMMANDERROR: Could not find /command %s (id %d) in stringtable.  Using english.\n",
                    entry_guess->name_guess, entry_guess->id_guess);
            }
        }
    }
}

// Tears the client's globals down in the original order; 'Cleanup N' are the original log markers.
// FUNCTION: TITANIUM 0x00497395
CEverQuest_guess::~CEverQuest_guess() {
    ((SlotOwner_guess*)this)->DeleteMailManager_guess();
    delete g_displayState_00903e84_guess;
    g_displayState_00903e84_guess = 0;
    FreeAudioTriggerManager_guess();
    delete g_owned_00851390_guess;
    g_owned_00851390_guess = 0;
    delete g_owned_00985d90_guess;
    g_owned_00985d90_guess = 0;
    delete g_owned_0079dbd4_guess;
    g_owned_0079dbd4_guess = 0;
    DestroyConnectionManager_guess();
    g_value_00905ca0_guess = 0;
    FUN_00574110_guess("Cleanup 4\n");
    ((TargetOwner_guess*)this)->DisconnectChatServer_guess();
    ((TargetOwner_guess*)this)->DisconnectMailServer_guess();
    DestroyItemTintTable_guess();
    DestroyNpcTintTable_guess();
    FUN_004b6db3_guess();
    if (g_ownedStringTable_guess != 0) {
        delete g_ownedStringTable_guess;
        g_ownedStringTable_guess = 0;
    }
    FUN_00574110_guess("Cleanup 5\n");
    if (g_ownedDisplay_guess->field124_guess != 0) {
        g_ownedDisplay_guess->field124_guess = 0;
    }
    FUN_00574110_guess("Cleanup 6\n");
    if (g_charData_guess != 0) {
        delete g_charData_guess;
        g_charData_guess = 0;
    }
    FUN_00574110_guess("Cleanup 7\n");
    FUN_00574110_guess("Cleanup 8\n");
    for (int index_guess = 0; index_guess < 100; ++index_guess) {
        if (g_records_00851200_guess[index_guess] != 0) {
            delete g_records_00851200_guess[index_guess];
            g_records_00851200_guess[index_guess] = 0;
        }
    }
    FUN_00574110_guess("Cleanup 9\n");
    delete g_owned_00985cc8_guess;
    g_owned_00985cc8_guess = 0;
    delete g_owned_009859ec_guess;
    g_owned_009859ec_guess = 0;
    delete g_owned_00985cf0_guess;
    g_owned_00985cf0_guess = 0;
    if (g_owned_00991fa8_guess != 0) {
        delete g_owned_00991fa8_guess;
        g_owned_00991fa8_guess = 0;
    }
    if (g_owned_00985cec_guess != 0) {
        delete g_owned_00985cec_guess;
        g_owned_00985cec_guess = 0;
    }
    delete g_owned_0079c120_guess;
    g_owned_0079c120_guess = 0;
    FUN_00574110_guess("Cleanup 10\n");
    if (g_owned_00905c9c_guess != 0) {
        delete g_owned_00905c9c_guess;
        g_owned_00905c9c_guess = 0;
    }
    if (g_ownedDisplay_guess != 0) {
        delete g_ownedDisplay_guess;
    }
    g_ownedDisplay_guess = 0;
    if (g_owned_00905cc0_guess != 0) {
        delete g_owned_00905cc0_guess;
        g_owned_00905cc0_guess = 0;
    }
    FUN_00574110_guess("Cleanup 11\n");
    g_value_00905cc4_guess = 0;
    g_value_00905cc8_guess = 0;
    g_value_00905ccc_guess = 0;
    g_value_00905cd0_guess = 0;
    g_value_00905cd4_guess = 0;
    g_value_00905cd8_guess = 0;
    g_value_00905cdc_guess = 0;
    if (g_buffer_00924830_guess != 0) {
        CrtFree_guess(g_buffer_00924830_guess);
        g_buffer_00924830_guess = 0;
        g_value_0092483c_guess = 0;
        g_value_00924840_guess = 0;
        g_value_00924838_guess = 0;
        g_value_00924844_guess = 0;
    }
}

struct ListItem_guess {
    virtual ~ListItem_guess() ;
    LinkedNode_guess node_guess;
};

struct List_guess {
    ListItem_guess* field00_guess;
    ListItem_guess* field04_guess;
    ListItem_guess* PopFront_guess();
    void DeleteAll_guess();
};

// Removes and returns the first item of the list (+0 head, +4 tail; the tail is cleared when it was the
// only item), unlinked by 0x004952B6. Null when the list is empty.
// FUNCTION: TITANIUM 0x00497145
ListItem_guess* List_guess::PopFront_guess() {
    ListItem_guess* item_guess = field00_guess;
    if (item_guess == 0) {
        return 0;
    }
    field00_guess = reinterpret_cast<ListItem_guess*>(item_guess->node_guess.field04_guess);
    if (item_guess == field04_guess) {
        field04_guess = 0;
    }
    item_guess->node_guess.Unlink_guess();
    return item_guess;
}

struct Record_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned char field0c_guess;
    Record_guess() {
        field04_guess = 0;
        field00_guess = 0;
        field08_guess = 0;
        field0c_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0050F3F6 Record_guess::Clear_guess
    void Clear_guess();
};

struct RecordOwner_guess {
    char padding_0000_guess[0x39C44];
    Record_guess first_guess;
    Record_guess second_guess;
    RecordOwner_guess();
    void Clear_guess();
};

struct ContextResultTail_guess {
    char padding_0000_guess[0x78];
    int field78_guess;
};

// Empty constructor; the two records at +0x39C44 construct themselves.
// FUNCTION: TITANIUM 0x0049716A
RecordOwner_guess::RecordOwner_guess() {
}

// Resets the two records at +0x39C44 (0x0050F3F6), second first.
// FUNCTION: TITANIUM 0x00497193
void RecordOwner_guess::Clear_guess() {
    second_guess.Clear_guess();
    first_guess.Clear_guess();
}

struct Window_guess {
    // EXTERNAL: TITANIUM 0x005E0EC0 Window_guess::GetName_guess
    const char* GetName_guess();
    virtual void RefreshCounts_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x0046DC2E FormatTokenStringToClient_guess
void __cdecl FormatTokenStringToClient_guess(int arg1_guess, int arg2_guess, int arg3_guess,
    const char* name_guess, int arg5_guess, int arg6_guess, int arg7_guess,
    int arg8_guess, int arg9_guess, int arg10_guess, int arg11_guess,
    int arg12_guess, int arg13_guess);

// Drops the cursor item: with `value` set it prints 'You just dropped your %1.' (eqstr 0x2362), then
// deletes the item locally and tells the server (OP_GroundSpawn 0xF47, no payload).
// FUNCTION: TITANIUM 0x00497AF4
// @early-stop: budget, structural ndiff=5
void GlobalState_guess::DropHeldItemOnGround(int value_guess) {
    ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    int* result_guess = selector_guess->finder_guess.GetCharInfo2();
    result_guess += 4;
    if (reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess == 0) {
        return;
    }
    g_clockData_guess->field10_guess = 0;
    if (value_guess != 0) {
        ContextSelector_guess* nameSelector_guess = reinterpret_cast<ContextSelector_guess*>(
            reinterpret_cast<char*>(g_contextObject_guess) +
            g_contextObject_guess->field08_guess->field04_guess + 8);
        int* nameResult_guess = nameSelector_guess->finder_guess.GetCharInfo2();
        nameResult_guess += 4;
        Window_guess* nameWindow_guess = reinterpret_cast<Window_guess*>(
            reinterpret_cast<ContextResultTail_guess*>(nameResult_guess)->field78_guess);
        FormatTokenStringToClient_guess(0, 0x2362, 0xf, nameWindow_guess->GetName_guess(),
            0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    ContextSelector_guess* windowSelector_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    int* windowResult_guess = windowSelector_guess->finder_guess.GetCharInfo2();
    windowResult_guess += 4;
    Window_guess* window_guess = reinterpret_cast<Window_guess*>(
        reinterpret_cast<ContextResultTail_guess*>(windowResult_guess)->field78_guess);
    if (window_guess != 0) {
        window_guess->RefreshCounts_guess(1);
    }
    ContextSelector_guess* clearSelector_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    int* clearResult_guess = clearSelector_guess->finder_guess.GetCharInfo2();
    clearResult_guess += 4;
    reinterpret_cast<ContextResultTail_guess*>(clearResult_guess)->field78_guess = 0;
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xf47, 0, 0, 1);
    }
    g_contextObject_guess->fieldc28c_guess = 1;
}

// Opcode 0x1004 packet: 0x94-byte header, then the text.
struct ChatPacket_guess {
    char from_guess[0x40];
    char to_guess[0x40];
    unsigned int index_guess;
    int type_guess;
    int value_guess;
    unsigned char flag_guess;
    int chance_guess;
    char text_guess[0x800];
};

// Opcode 0x33DC packet: 0xC4-byte header, then the text.
struct LogPacket_guess {
    char prefix_guess[0x40];
    char from_guess[0x40];
    char to_guess[0x40];
    int type_guess;
    char text_guess[0x800];
};

#define g_prefix_00923898_guess EQ_ARRAY(char, 0x00923898)

// EXTERNAL: TITANIUM 0x005ED550 FUN_005ed550_guess
int __cdecl FUN_005ed550_guess();

// EXTERNAL: TITANIUM 0x00464AFB GetMaterialSlotFromInvSlot_guess
int __cdecl GetMaterialSlotFromInvSlot_guess(int index_guess);
// EXTERNAL: TITANIUM 0x00464E25 GetTextureSlot_guess
int __cdecl GetTextureSlot_guess(int index_guess);

// Only while the player's +0x254 is 0xFF: sends OP_WearChange (0x7441) for wear slot 9 with +0x24D,
// then re-applies the look of worn slots 0..21, or just slot `value` when it is in range.
// FUNCTION: TITANIUM 0x00497F42
// @early-stop: budget, structural ndiff=41
void GlobalState_guess::RefreshWornAppearance_guess(int value_guess) {
    if (g_statDisplay_00905ce4_guess->equipChest2_0254_guess == 0xff) {
        ContextSelector_guess* initialSelector_guess =
            reinterpret_cast<ContextSelector_guess*>(
                &g_contextObject_guess->field0c_guess[
                    g_contextObject_guess->field08_guess->field04_guess - 4]);
        g_statDisplay_00905ce4_guess->faceHair_024d_guess =
            reinterpret_cast<ContextActorData_guess*>(
                initialSelector_guess->finder_guess.GetCharInfo2())->field11d0_guess;
        g_statDisplay_00905ce4_guess->SwapFace_guess(
            g_statDisplay_00905ce4_guess->faceHair_024d_guess, 0);

        struct MessageData_guess {
            unsigned short field00_guess;
            unsigned short field02_guess;
            unsigned int field04_guess;
            unsigned char field08_guess;
        } message_guess;
        message_guess.field00_guess = g_statDisplay_00905ce4_guess->spawnId_0258_guess;
        message_guess.field08_guess = 9;
        message_guess.field02_guess = g_statDisplay_00905ce4_guess->faceHair_024d_guess;
        message_guess.field04_guess = 0;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7441,
            &message_guess, 9, 1);

        int limit_guess = 0x15;
        int index_guess = 0;
        if (value_guess >= 0 && value_guess <= limit_guess) {
            index_guess = value_guess;
            limit_guess = value_guess;
        }
        if (index_guess <= limit_guess) {
            do {
                ContextSelector_guess* selector_guess =
                    reinterpret_cast<ContextSelector_guess*>(
                        &g_contextObject_guess->field0c_guess[
                            g_contextObject_guess->field08_guess->field04_guess - 4]);
                ContextEntry_guess* entry_guess =
                    selector_guess->GetInventorySlot_guess(index_guess);
                if (entry_guess == 0) {
                    value_guess = 0;
                    int result_guess = GetMaterialSlotFromInvSlot_guess(index_guess);
                    if (g_contextObject_guess != 0) {
                        value_guess =
                            g_contextObject_guess->GetArmorTint_guess(result_guess);
                    }
                    if (result_guess != -1) {
                        g_statDisplay_00905ce4_guess->HandleMaterialEx_guess(
                            result_guess, 0,
                            g_statDisplay_00905ce4_guess->GetArmorType_guess(
                                result_guess), value_guess, 0);
                    }
                } else if (index_guess == 0xd || index_guess == 0xe) {
                    ContextSelector_guess* selector_guess =
                        reinterpret_cast<ContextSelector_guess*>(
                            &g_contextObject_guess->field0c_guess[
                                g_contextObject_guess->field08_guess->field04_guess - 4]);
                    g_statDisplay_00905ce4_guess->FUN_0048083a_guess(
                        GetTextureSlot_guess(index_guess),
                        (entry_guess = selector_guess->GetInventorySlot_guess(index_guess))->
                            FUN_005e0f00_guess(), 0);
                } else {
                    ContextSelector_guess* selector_guess =
                        reinterpret_cast<ContextSelector_guess*>(
                            &g_contextObject_guess->field0c_guess[
                                g_contextObject_guess->field08_guess->field04_guess - 4]);
                    g_contextAction_guess->UpdateItemSlot_guess(g_contextObject_guess,
                        index_guess, selector_guess->GetInventorySlot_guess(index_guess), 0);
                }
                ++index_guess;
            } while (index_guess <= limit_guess);
        }
    }
}

// Toggles the chat input's focus (input mode 0x009237B0).
// FUNCTION: TITANIUM 0x004980D2
void GlobalState_guess::ToggleChatInputFocus_guess() {
    if (g_state_009237b0_guess == 0) {
        SetChatInputFocus_guess(1);
    } else {
        SetChatInputFocus_guess(0);
    }
}

// Clears +0x10 of the object at 0x00905D24 when the character's mode value (+0x78 of its found record)
// is 0, then calls virtual slot 34 of the spell book window when it answers 0x0059DD30.
// FUNCTION: TITANIUM 0x004980E7
void FUN_004980e7_guess() {
    ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
        reinterpret_cast<char*>(g_contextObject_guess) +
        g_contextObject_guess->field08_guess->field04_guess + 8);
    int* result_guess = selector_guess->finder_guess.GetCharInfo2();
    result_guess += 4;
    if (reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess == 0) {
        g_clockData_guess->field10_guess = 0;
    }
    if (pinstCSpellBookWnd_guess->IsVisible_guess() != 0) {
        pinstCSpellBookWnd_guess->Deactivate();
    }
}

struct ContextMode_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 ContextMode_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ContextMode_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 ContextMode_guess::GetItemId_guess
    int GetItemId_guess();
};

// Clicks the door or switch under the screen point for the controlled spawn (+0xC288) or the player,
// passing the cursor item's id as the key. Returns the switch, or 0.
// FUNCTION: TITANIUM 0x0049812E
// @early-stop: budget, structural ndiff=44
int GlobalState_guess::ClickSwitchAtScreenPos_guess(int first_guess, int second_guess) {
    int firstOutput_guess[3];
    int secondOutput_guess[3];
    int value_guess = -1;
    int action_guess = 0;
    int candidate_guess = g_clockData_guess->PickActorAt_guess(
        first_guess, second_guess, 0, firstOutput_guess, secondOutput_guess);
    if (candidate_guess == 0) {
        return 0;
    }
    int state_guess = g_displayState_00903e84_guess->Resolve_guess(candidate_guess);
    if (state_guess != 0) {
        if (reinterpret_cast<DisplayState_guess*>(state_guess)->GetSwitchDamage_guess() != 0) {
            action_guess = g_contextObject_guess->fieldc280_guess.HasSkill_guess(0x11);
        } else {
            ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
                &g_contextSelectorStorage_guess->selectorBytes_guess[
                    g_contextObject_guess->field08_guess->field04_guess]);
            int* result_guess = selector_guess->finder_guess.GetCharInfo2();
            result_guess += 4;
            ContextMode_guess* mode_guess = reinterpret_cast<ContextMode_guess*>(
                reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
            if (mode_guess != 0) {
                selector_guess = reinterpret_cast<ContextSelector_guess*>(
                    &g_contextSelectorStorage_guess->selectorBytes_guess[
                        g_contextObject_guess->field08_guess->field04_guess]);
                result_guess = selector_guess->finder_guess.GetCharInfo2();
                result_guess += 4;
                mode_guess = reinterpret_cast<ContextMode_guess*>(
                    reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
                if (mode_guess->GetItemClass_guess() == 0) {
                    selector_guess = reinterpret_cast<ContextSelector_guess*>(
                        &g_contextSelectorStorage_guess->selectorBytes_guess[
                            g_contextObject_guess->field08_guess->field04_guess]);
                    result_guess = selector_guess->finder_guess.GetCharInfo2();
                    result_guess += 4;
                    mode_guess = reinterpret_cast<ContextMode_guess*>(
                        reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
                    if (mode_guess->GetItemType_guess() == 0xc) {
                        selector_guess = reinterpret_cast<ContextSelector_guess*>(
                            &g_contextSelectorStorage_guess->selectorBytes_guess[
                                g_contextObject_guess->field08_guess->field04_guess]);
                        result_guess = selector_guess->finder_guess.GetCharInfo2();
                        result_guess += 4;
                        mode_guess = reinterpret_cast<ContextMode_guess*>(
                            reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
                        value_guess = mode_guess->GetItemId_guess();
                        action_guess = g_contextObject_guess->fieldc280_guess.
                            HasSkill_guess(0x23);
                    } else {
                        selector_guess = reinterpret_cast<ContextSelector_guess*>(
                            &g_contextSelectorStorage_guess->selectorBytes_guess[
                                g_contextObject_guess->field08_guess->field04_guess]);
                        result_guess = selector_guess->finder_guess.GetCharInfo2();
                        result_guess += 4;
                        mode_guess = reinterpret_cast<ContextMode_guess*>(
                            reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
                        value_guess = mode_guess->GetItemId_guess();
                        action_guess = 0;
                    }
                } else {
                    selector_guess = reinterpret_cast<ContextSelector_guess*>(
                        &g_contextSelectorStorage_guess->selectorBytes_guess[
                            g_contextObject_guess->field08_guess->field04_guess]);
                    result_guess = selector_guess->finder_guess.GetCharInfo2();
                    result_guess += 4;
                    mode_guess = reinterpret_cast<ContextMode_guess*>(
                        reinterpret_cast<ContextResultTail_guess*>(result_guess)->field78_guess);
                    value_guess = mode_guess->GetItemId_guess();
                    action_guess = 0;
                }
            }
        }
        if (g_contextObject_guess->pSpawn_c288_guess == 0) {
            reinterpret_cast<DisplayState_guess*>(state_guess)->UseSwitch_guess(
                g_sourceRecord_00905ce4_guess->field258_guess,
                value_guess, action_guess, reinterpret_cast<int>(firstOutput_guess));
        } else {
            reinterpret_cast<DisplayState_guess*>(state_guess)->UseSwitch_guess(
                g_contextObject_guess->pSpawn_c288_guess->field258_guess,
                value_guess, action_guess, reinterpret_cast<int>(firstOutput_guess));
        }
    }
    return state_guess;
}

// Deletes every item of the list, front first.
// FUNCTION: TITANIUM 0x004982AC
void List_guess::DeleteAll_guess() {
    ListItem_guess* item_guess;
    while ((item_guess = PopFront_guess()) != 0) {
        delete item_guess;
    }
}

struct CXStrRep_guess;

struct CXStr_guess {
    CXStrRep_guess* rep_guess; // 0x0
    CXStr_guess() : rep_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 ??0CXStr_guess@@QAE@PBD@Z
    CXStr_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0CXStr_guess@@QAE@ABU0@@Z
    CXStr_guess(const CXStr_guess& other_guess);
    ~CXStr_guess() {
        if (rep_guess != 0) {
            FreeRep(rep_guess);
        }
        rep_guess = 0;
    }
    // EXTERNAL: TITANIUM 0x00571F70 ??4CXStr_guess@@QAEAAU0@ABU0@@Z
    CXStr_guess& operator=(const CXStr_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00571D00 CXStr_guess::FreeRep
    void FreeRep(CXStrRep_guess* rep_guess);
    // EXTERNAL: TITANIUM 0x00572300 ??BCXStr_guess@@QBEPADXZ
    operator char*() const;
};

struct WideCXStr_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00571F00 WideCXStr_guess::WideCXStr_guess
    WideCXStr_guess(const wchar_t* text_guess);
    // EXTERNAL: TITANIUM 0x005722D0 WideCXStr_guess::FUN_005722d0_guess
    void FUN_005722d0_guess(int zero_guess);
};

// EXTERNAL: TITANIUM 0x006120B4 _wcsftime
size_t __cdecl _wcsftime(wchar_t* buffer_guess, size_t size_guess,
    const wchar_t* format_guess, const struct tm* time_guess);

// EXTERNAL: TITANIUM 0x0060ACA0 FilterChat_guess
CXStr_guess __cdecl FilterChat_guess(const CXStr_guess& text_guess);
// EXTERNAL: TITANIUM 0x0046D46D ConvertItemTags
void __cdecl ConvertItemTags(CXStr_guess& text_guess, int flag_guess);
// EXTERNAL: TITANIUM 0x00576FA0 CopyBounded_guess
void __cdecl CopyBounded_guess(char* destination_guess, const char* source_guess, int length_guess);
// eqlog: appends '[ctime] message' to the log file (+logPath) while logging (+0x39AB9) is on;
// chat logging and DoTellWindow use it.
// FUNCTION: TITANIUM 0x00491125
void __cdecl eqlog_guess(const char* message_guess) {
    int timestamp_guess;
    char line_guess[2048];

    if (g_globalState_guess != 0 && g_globalState_guess->field39ab9_guess != 0) {
        timestamp_guess = _time32_guess(0);
        line_guess[0] = '[';
        line_guess[1] = 0;
        FUN_0060e460_guess(line_guess, _ctime_guess(&timestamp_guess));
        unsigned int length_guess = strlen(line_guess);
        if (line_guess[length_guess - 1] == '\n') {
            line_guess[length_guess - 1] = ']';
            line_guess[length_guess] = ' ';
            line_guess[length_guess + 1] = 0;
        } else {
            line_guess[length_guess] = ']';
            line_guess[length_guess + 1] = ' ';
            line_guess[length_guess + 2] = 0;
        }

        CXStr_guess text_guess(message_guess);
        ConvertItemTags(text_guess, 0);
        FUN_0060e460_guess(line_guess, text_guess);
        FUN_0060e460_guess(line_guess, EQ_ARRAY(char, 0x00641588));

        FILE* file_guess = fopen(g_globalState_guess->logPath_guess,
            EQ_ARRAY(char, 0x0063FE30));
        if (file_guess != 0) {
            fwrite(line_guess, strlen(line_guess), 1, file_guess);
            fclose(file_guess);
        }
    }
}

struct ChatWindowManager_guess {
    // EXTERNAL: TITANIUM 0x004F2F8A ChatWindowManager_guess::AddChat_guess
    void AddChat_guess(CXStr_guess text_guess, int color_guess);
    // EXTERNAL: TITANIUM 0x004F2FFF ChatWindowManager_guess::FUN_004f2fff_guess
    void FUN_004f2fff_guess(CXStr_guess text_guess, int color_guess,
        const char* first_guess, const char* second_guess);
};

#define g_chatManager_guess EQ_GLOBAL(ChatWindowManager_guess*, 0x009917E4)

struct PendingChat_guess {
    char text_guess[0x800]; // 0x0
    int color_guess;        // 0x800
};

struct PendingChatArray_guess {
    int count_guess; // 0x0
    // EXTERNAL: TITANIUM 0x0050319B PendingChatArray_guess::Set_guess
    void Set_guess(int index_guess, PendingChat_guess** value_guess);
};

#define g_pendingChat_guess EQ_GLOBAL(PendingChatArray_guess, 0x0095D3C4)
#define g_chatLogging_guess EQ_GLOBAL(int, 0x00924788)

// dsp_chat for tells: puts the line in the chat manager's tell path for `first`/`second` and logs
// it as 'from -> to: text'.
// FUNCTION: TITANIUM 0x00496782
void GlobalState_guess::DoTellWindow_guess(const char* text_guess, const char* first_guess,
    const char* second_guess, int unused_guess, int color_guess, char log_guess) {
    if (strlen(text_guess) >= 1 && g_globalState_guess->state_guess == 5) {
        DoPercentConvert_guess(text_guess, 0);
        CXStr_guess line_guess;
        line_guess = FilterChat_guess(text_guess);
        ConvertItemTags(line_guess, 1);
        const char* second_copy_guess = second_guess;
        const char* first_copy_guess = first_guess;
        if (g_chatManager_guess != 0) {
            if (color_guess == 0x14) {
                color_guess = 10;
            }
            g_chatManager_guess->FUN_004f2fff_guess(line_guess, color_guess, first_copy_guess, second_copy_guess);
        }
        // Chat log line: "first -> name: text" (the name is the character's own).
        if (g_chatLogging_guess == 1 && log_guess == 1 && first_copy_guess != 0 && second_copy_guess != 0) {
            char buffer_guess[2048];
            if (strcmp(first_copy_guess, second_copy_guess) == 0) {
                _sprintf(buffer_guess, "%s -> %s: %s", first_copy_guess, g_charData_guess->name_guess, text_guess);
            } else {
                _sprintf(buffer_guess, "%s -> %s: %s", g_charData_guess->name_guess, second_copy_guess, text_guess);
            }
            eqlog_guess(buffer_guess);
        }
    }
}

// dsp_chat: shows a line in game (state 5) after the % shortcuts and the chat filter; before the
// chat manager exists the line is queued. Logged when chat logging is on and `log` is set.
// FUNCTION: TITANIUM 0x004982C6
// @early-stop: budget, diff ndiff=8
void GlobalState_guess::DspChat_guess(const char* line_guess, int color_guess, bool log_guess) {
    if (strlen(line_guess) >= 1 && g_globalState_guess->state_guess == 5) {
        DoPercentConvert_guess(line_guess, 0);
        CXStr_guess text_guess;
        text_guess = FilterChat_guess(line_guess);
        ConvertItemTags(text_guess, 1);
        // Colour 0x14 is drawn as colour 10.
        if (color_guess == 0x14) {
            color_guess = 10;
        }
        if (g_chatManager_guess != 0) {
            g_chatManager_guess->AddChat_guess(text_guess, color_guess);
        } else {
            PendingChat_guess* chat_guess = new PendingChat_guess();
            CopyBounded_guess(chat_guess->text_guess, text_guess, 0x800);
            chat_guess->color_guess = color_guess;
            g_pendingChat_guess.Set_guess(g_pendingChat_guess.count_guess, &chat_guess);
        }
        if (g_chatLogging_guess == 1 && log_guess == true) {
            eqlog_guess(line_guess);
        }
    }
}

// dsp_chat in the default colour 0x111, logged.
// FUNCTION: TITANIUM 0x00498436
void GlobalState_guess::DspChat_guess(const char* line_guess) {
    DspChat_guess(line_guess, 0x111, true);
}

// EXTERNAL: TITANIUM 0x00574A30 FUN_00574a30_guess
void __cdecl FUN_00574a30_guess(char* text_guess, int size_guess);

// /emote: sends OP_Emote (0x547A: the current language, then 1024 bytes of text) unless sending is
// blocked (0x92384D), and echoes '<name> <text>' locally.
// FUNCTION: TITANIUM 0x00498449
void GlobalState_guess::Emote_guess() {
    struct ChatPacket_guess {
        int id_guess;
        char text_guess[1024];
    };
    char line_guess[2048];
    ChatPacket_guess packet_guess;
    if (g_flag_0092384d_guess == 0) {
        _sprintf(line_guess, " %s", field17bb4_guess);
        DoPercentConvert_guess(line_guess, 1);
        packet_guess.id_guess = GetCurrentLanguage_guess();
        FUN_00574a30_guess(line_guess, 0x1fe);
        strcpy(packet_guess.text_guess, line_guess);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x547a, &packet_guess, 0x404, 1);
        _sprintf(line_guess, "%s %s", g_globalState_guess->trimName_guess(
            g_contextObject_guess->field44_guess + g_contextObject_guess->field08_guess->field04_guess),
            field17bb4_guess);
        DspChat_guess(line_guess, 0x13a, true);
    }
}

// /gsay: needs a group (0x9043A4 holds the leader's name), else eqstr 0x3039; echoes the line
// (0x303A) and sends it on channel 2.
// FUNCTION: TITANIUM 0x00498720
void GlobalState_guess::send_gsay_guess() {
    char text_guess[2112];
    char buffer_guess[2112];
    if (EQ_GLOBAL(unsigned char, 0x009043A4) == 0) {
        DspChat_guess(pStringTable->getString(0x3039, 0), 0x135, true);
    } else if (g_sendDisabled_00923798_guess == 0 && g_flag_0092384d_guess == 0 &&
        g_flag_00923884_guess == 0) {
        FUN_0060e450_guess(text_guess, field17bb4_guess);
        DoPercentConvert_guess(text_guess, 1);
        FUN_0046da4a_guess(buffer_guess, 0x303a, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(buffer_guess, 0x135, 1);
        SendNewText_guess(2, 0, (int)field17bb4_guess, 0);
    }
}

// /shout: sends on channel 3 and echoes 'You shout, %1' (0x303C).
// FUNCTION: TITANIUM 0x004987F7
void GlobalState_guess::send_shout_guess() {
    char text_guess[2112];
    char buffer_guess[2112];
    if (g_globalState_guess->state_guess == 5 && g_sendDisabled_00923798_guess == 0 &&
        g_flag_0092384d_guess == 0 && g_flag_00923884_guess == 0) {
        SendNewText_guess(3, 0, (int)field17bb4_guess, 0);
        FUN_0060e450_guess(text_guess, field17bb4_guess);
        DoPercentConvert_guess(text_guess, 1);
        FUN_0046da4a_guess(buffer_guess, 0x303c, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(buffer_guess, 0x139, 1);
    }
}

// /broadcast: sends on channel 6 and echoes 'You broadcast' (0x3034).
// FUNCTION: TITANIUM 0x00498539
void GlobalState_guess::send_broadcast_guess() {
    char buffer_guess[2112];
    if (g_globalState_guess->state_guess == 5 && g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        // Formatted and then overwritten by the 0x3034 line: '%1 BROADCASTS %2' is never shown (original).
        FUN_0046da4a_guess(buffer_guess, 0x3033, g_resetOwner_guess->name_0120_guess,
            field17bb4_guess, 0, 0, 0, 0, 0, 0, 0);
        SendNewText_guess(6, 0, (int)field17bb4_guess, 0);
        FUN_0046da4a_guess(buffer_guess, 0x3034, field17bb4_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(buffer_guess, 0x111, 1);
    }
}

// /say: sends on channel 8 with the target's name and echoes 'You say, %1' (0x3038).
// FUNCTION: TITANIUM 0x004985EB
// @early-stop: budget, structural ndiff=17
void GlobalState_guess::send_chat_guess(int value_guess) {
    struct ChatScratch_guess {
        int selected_indices_guess[32];
        GlobalState_guess* owner_guess;
        char output_guess[2112];
        char copied_text_guess[2112];
        char player_name_guess[128];
    } scratch_guess;

    struct NameSource_guess {
        char padding_0000_guess[0x120];
        char name_guess[0x40];
    };

    struct ContextSelectorArray_guess {
        char padding_0000_guess[0x14];
        BoundedArray_guess<char, 32> values_guess;
    };

    if (g_globalState_guess->state_guess == 5) {
        scratch_guess.owner_guess = this;
        if (g_sendDisabled_00923798_guess == 0 && g_flag_0092384d_guess == 0 &&
            g_flag_00923884_guess == 0) {
            if (g_contextObject_guess != 0) {
                int* next_index_guess = scratch_guess.selected_indices_guess;
                // The list of known-language indexes built here is never used (original).
                for (int index_guess = 0; index_guess < 32; ++index_guess) {
                    if (reinterpret_cast<ContextSelectorArray_guess*>(
                            reinterpret_cast<unsigned int>(g_contextObject_guess) +
                            g_contextObject_guess->field08_guess->field04_guess)
                            ->values_guess[index_guess] != 0) {
                        *next_index_guess++ = index_guess;
                    }
                }
            }

            char* player_name_pointer_guess = 0;
            NameSource_guess* name_source_guess =
                EQ_GLOBAL(NameSource_guess*, 0x00905D04);
            if (name_source_guess != 0) {
                player_name_pointer_guess = scratch_guess.player_name_guess;
                FUN_0060e450_guess(scratch_guess.player_name_guess,
                    name_source_guess->name_guess);
            }
            SendNewText_guess(8, reinterpret_cast<int>(player_name_pointer_guess),
                reinterpret_cast<int>(field17bb4_guess), value_guess);
            FUN_0060e450_guess(scratch_guess.copied_text_guess, field17bb4_guess);
            scratch_guess.owner_guess->DoPercentConvert_guess(
                scratch_guess.copied_text_guess, 1);
            FUN_0046da4a_guess(scratch_guess.output_guess, 0x3038,
                scratch_guess.copied_text_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            scratch_guess.owner_guess->DspChat_guess(
                scratch_guess.output_guess, 0x133, 1);
        }
    }
}

// /auction: sends on channel 4 and echoes 'You auction, %1' (0x303E).
// FUNCTION: TITANIUM 0x004988B1
void GlobalState_guess::send_auction_guess() {
    char text_guess[2112];
    char buffer_guess[2112];
    if (g_globalState_guess->state_guess == 5 && g_sendDisabled_00923798_guess == 0 &&
        g_flag_0092384d_guess == 0 && g_flag_00923884_guess == 0 && pCharData != 0) {
        SendNewText_guess(4, 0, (int)field17bb4_guess, 0);
        FUN_0060e450_guess(text_guess, field17bb4_guess);
        DoPercentConvert_guess(text_guess, 1);
        FUN_0046da4a_guess(buffer_guess, 0x303e, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(buffer_guess, 0x138, 1);
    }
}

// /ooc: sends on channel 5 and echoes it (0x3040); refused with 0x303F while 0x923D5C is set.
// FUNCTION: TITANIUM 0x00498977
void GlobalState_guess::send_ooc_guess() {
    char text_guess[2112];
    char buffer_guess[2112];
    if (g_globalState_guess->state_guess == 5 && g_sendDisabled_00923798_guess == 0 &&
        g_flag_0092384d_guess == 0 && g_flag_00923884_guess == 0) {
        if (g_value_00923d5c_guess != 0) {
            DspChat_guess(pStringTable->getString(0x303f, 0), 0x0d, 1);
        } else {
            SendNewText_guess(5, 0, (int)field17bb4_guess, 0);
            FUN_0060e450_guess(text_guess, field17bb4_guess);
            DoPercentConvert_guess(text_guess, 1);
            FUN_0046da4a_guess(buffer_guess, 0x3040, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            DspChat_guess(buffer_guess, 0x137, 1);
        }
    }
}

// Asks to inspect a PC within 20 units (OP_InspectRequest 0x775D: their id, our id), else prints
// the too-far line (0x305A).
// FUNCTION: TITANIUM 0x00498A66
void GlobalState_guess::doInspect(SourceRecord_guess* source_guess) {
    if (source_guess != 0 && source_guess->flag244_guess == 0) {
        if (g_ownedDisplay_guess->PlayerDistance_guess(source_guess, g_actorStatus_guess, 1.0f) < 20.0f) {
            int pair_guess[2];
            pair_guess[0] = source_guess->field258_guess;
            pair_guess[1] = g_sourceRecord_00905ce4_guess->field258_guess;
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x775d, pair_guess, 8, 1);
        } else {
            char text_guess[512];
            FUN_0046da4a_guess(text_guess, 0x305a, source_guess->text_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            DspChat_guess(text_guess);
        }
    }
}

#define g_commandTable_guess EQ_ARRAY(CommandEntry_guess, 0x0078A0C8)
#define g_commandCount_guess EQ_GLOBAL(int, 0x006450B8)
#define g_selected_00924474_guess EQ_GLOBAL(int, 0x00924474)
#define g_commandMode_0095a174_guess EQ_GLOBAL(unsigned char, 0x0095A174)
#define g_channel_009237ec_guess EQ_GLOBAL(unsigned char, 0x009237EC)
#define g_channelName_009237f4_guess EQ_ARRAY(char, 0x009237F4)

struct CommandPrompt_guess {
    // EXTERNAL: TITANIUM 0x0042FF95 CommandPrompt_guess::RaidSay_guess
    void RaidSay_guess(const char* text_guess);
};

#define g_commandPrompt_0091d708_guess EQ_GLOBAL(CommandPrompt_guess, 0x0091D708)

// EXTERNAL: TITANIUM 0x004658AC IsStringPrefix_guess
int __cdecl IsStringPrefix_guess(const char* first_guess, const char* second_guess);
// EXTERNAL: TITANIUM 0x00466B46 do_chat_guess
void __cdecl do_chat_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00466BE3 SendMailChannelText_guess
void __cdecl SendMailChannelText_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x0042DD82 GrabFirstWord_guess
char* __cdecl GrabFirstWord_guess(const char* source_guess, char* output_guess,
    unsigned int size_guess);
// EXTERNAL: TITANIUM 0x00574800 FUN_00574800_guess
int __cdecl FUN_00574800_guess(const char* text_guess, int* length_guess);
// EXTERNAL: TITANIUM 0x00574830 FUN_00574830_guess
int __cdecl FUN_00574830_guess(const char* text_guess, int* length_guess);
// EXTERNAL: TITANIUM 0x00466990 do_guildsay_guess
void __cdecl do_guildsay_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x004678D8 do_gsay_guess
void __cdecl do_gsay_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00467955 do_auction_guess
void __cdecl do_auction_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00467976 do_ooc_guess
void __cdecl do_ooc_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00467997 do_tell_guess
void __cdecl do_tell_guess(void* target_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00476411 SayToTarget_guess
void __cdecl SayToTarget_guess(void* target_guess, const char* text_guess);

// Runs one line of typed input. ';' and '[' lines go to the chat-channel handlers; a command word runs
// its handler (localised name first, then English; GM-only ones need +0x256); other text goes to the
// default channel 0x9237EC (0 guild, 2 group, 4 auction, 5 ooc, 7 tell, 19/20 numbered channels, else say).
// FUNCTION: TITANIUM 0x00498B78
// @early-stop: budget, structural ndiff=326
void GlobalState_guess::InterpretCmd(void* target_guess, const char* text_guess) {
    char full_guess[0x400];
    char word_guess[0x400];
    char firstText_guess[0x210];
    char secondText_guess[0x210];

    if (target_guess == 0 || g_resetOwner_guess == 0) {
        return;
    }
    GlobalState_guess* self_guess = this;
    const char* current_guess = text_guess;
    if (*current_guess == 0) {
        return;
    }
    int length_guess;
    while (FUN_00574860_guess(current_guess, &length_guess) != 0) {
        current_guess += length_guess;
    }
    g_selected_00924474_guess = -1;
    if (*current_guess == ';') {
        if (g_commandMode_0095a174_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f3f, 0));
        } else {
            do_chat_guess(target_guess, current_guess);
        }
    } else if (*current_guess == '[') {
        if (g_commandMode_0095a174_guess == 0) {
            SendMailChannelText_guess(target_guess, current_guess);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x2f3f, 0));
        }
    } else {
        FUN_0060e450_guess(full_guess, current_guess);
        if (*current_guess == '/' || FUN_00574800_guess(current_guess, 0) != 0 ||
            FUN_00574830_guess(current_guess, 0) != 0) {
            text_guess = GrabFirstWord_guess(current_guess, word_guess, 0x400);
        } else {
            word_guess[0] = *current_guess;
            ++current_guess;
            word_guess[1] = 0;
            text_guess = current_guess;
            if (FUN_00574860_guess(current_guess, &length_guess) != 0) {
                do {
                    current_guess += length_guess;
                } while (FUN_00574860_guess(current_guess, &length_guess) != 0);
                text_guess = current_guess;
            }
        }
        if (g_commandMode_0095a174_guess != 0) {
            CXStr wordText_guess(word_guess);
            EQ_METHOD(1, void, 0x005722D0, (CXStr, int), &wordText_guess)(1);
            // In command mode (0x95A174) only the commands listed in eqstr 0x3771 run.
            CXStr allowedText_guess(pStringTable->getString(0x3771, 0));
            EQ_METHOD(1, void, 0x005722D0, (CXStr, int), &allowedText_guess)(1);
            if (EQ_METHOD(3, int, 0x00573F00, (CXStr, const CXStr&, int, int),
                &wordText_guess)(allowedText_guess, 4, 0) != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2f3f, 0));
                self_guess->ClearChatText_guess();
                return;
            }
        }
        int index_guess = 0;
        bool allowed_guess = false;
        for (; index_guess < g_commandCount_guess; ++index_guess) {
            CommandEntry_guess* entry_guess = &g_commandTable_guess[index_guess];
            if (entry_guess->text_guess != 0 &&
                word_guess[0] == entry_guess->text_guess[0] &&
                IsStringPrefix_guess(word_guess, entry_guess->text_guess) != 0) {
                allowed_guess = entry_guess->field10_guess < 1 ||
                    g_resetOwner_guess->gm_0256_guess != 0;
                break;
            }
        }
        if (!allowed_guess) {
            for (index_guess = 0; index_guess < g_commandCount_guess; ++index_guess) {
                CommandEntry_guess* entry_guess = &g_commandTable_guess[index_guess];
                if (word_guess[0] == entry_guess->name_guess[0] &&
                    IsStringPrefix_guess(word_guess, entry_guess->name_guess) != 0) {
                    allowed_guess = entry_guess->field10_guess < 1 ||
                        g_resetOwner_guess->gm_0256_guess != 0;
                    break;
                }
            }
        }
        if (!allowed_guess) {
            if (full_guess[0] != 0) {
                if (full_guess[0] == '/') {
                    // Unknown slash command.
                    pEverQuest->dsp_chat(pStringTable->getString(0x305c, 0), 0xd, 1);
                } else {
                    switch (g_channel_009237ec_guess) {
                    case 0:
                        do_guildsay_guess(target_guess, full_guess);
                        break;
                    case 2:
                        do_gsay_guess(target_guess, full_guess);
                        break;
                    case 4:
                        do_auction_guess(target_guess, full_guess);
                        break;
                    case 5:
                        do_ooc_guess(target_guess, full_guess);
                        break;
                    case 7:
                        _sprintf(firstText_guess, "%s %s", g_channelName_009237f4_guess,
                            full_guess);
                        do_tell_guess(target_guess, firstText_guess);
                        break;
                    case 0xf:
                        g_commandPrompt_0091d708_guess.RaidSay_guess(full_guess);
                        break;
                    case 0x13:
                        _sprintf(firstText_guess, "#%s %s", g_channelName_009237f4_guess,
                            full_guess);
                        do_chat_guess(target_guess, firstText_guess);
                        break;
                    case 0x14:
                        _sprintf(secondText_guess, "#%s %s", g_channelName_009237f4_guess,
                            full_guess);
                        SendMailChannelText_guess(target_guess, secondText_guess);
                        break;
                    default:
                        SayToTarget_guess(target_guess, full_guess);
                        break;
                    }
                }
            }
        } else {
            if (g_contextObject_guess != 0 &&
                (g_contextObject_guess->fieldc280_guess.Cur_HP(0) < 1 ||
                 g_contextObject_guess->field44_guess[
                     g_contextObject_guess->field08_guess->field04_guess + 0xC0] == 3 ||
                 g_contextObject_guess->field44_guess[
                     g_contextObject_guess->field08_guess->field04_guess + 0xC0] == 4) &&
                (g_commandTable_guess[index_guess].flags_guess & 1) == 0) {
                // Refused while +0xC0 is 3 or 4 (or +0xC280 reports nothing) unless the command has flag 1.
                pEverQuest->dsp_chat(pStringTable->getString(0x21a, 0), 0xf, 1);
            } else {
                g_commandTable_guess[index_guess].handler_guess(target_guess, text_guess);
            }
        }
    }
    self_guess->ClearChatText_guess();
}

// Needs ability 6 (probably Apply Poison), else 0x305F. A standing player sits first; a sitting one
// starts the timed application (start 0x923864, item `value` 0x923868) unless another action is pending.
// FUNCTION: TITANIUM 0x0049908D
void GlobalState_guess::ApplyPoison_guess(int value_guess) {
    if (g_contextObject_guess->fieldc280_guess.HasSkill_guess(6) != 0) {
        if (g_resetOwner_guess->standState_0251_guess == 'd') {
            g_resetOwner_guess->ChangePosition_guess(0x6e);
        }
        if (g_resetOwner_guess->standState_0251_guess != 'n') {
            pEverQuest->dsp_chat(pStringTable->getString(0x305d, 0));
        } else {
            if (g_value_00923864_guess != 0 || g_value_00923994_guess != 0 ||
                g_value_009248d4_guess != 0 || g_value_009248d0_guess != 0) {
                return;
            }
            g_value_00923864_guess = g_ownedDisplay_guess->field148_guess;
            g_value_00923868_guess = value_guess;
            pEverQuest->dsp_chat(pStringTable->getString(0x305e, 0));
        }
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x305f, 0));
    }
}

// Prints the game time (eqstr 0x1A32), or 0x3064 'The sun does not move here' in zones of type 3, or
// 0xFC4 in zones 219 and 223, then the local Earth time (0x3065).
// FUNCTION: TITANIUM 0x00499323
void GlobalState_guess::WhatTimeIsIt_guess() {
    char text_guess[300];
    int selector_guess = g_selector_00924470_guess;
    if (selector_guess == 0xdb || selector_guess == 0xdf) {
        strcpy(text_guess, pStringTable->getString(0xfc4, 0));
    } else if (g_lookupManager_guess->FUN_005f6b90_guess(selector_guess) == 3) {
        strcpy(text_guess, pStringTable->getString(0x3064, 0));
    } else {
        char description_guess[128];
        g_lookupManager_guess->FUN_005f6890_guess(description_guess);
        FUN_0046da4a_guess(text_guess, 0x1a32, description_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }
    text_guess[strlen(text_guess)] = 0;
    DspChat_guess(text_guess);

    time_t timestamp_guess = time(0);
    wchar_t dateBuffer_guess[128];
    _wcsftime(dateBuffer_guess, 0x100, L"%#c", localtime(&timestamp_guess));
    WideCXStr_guess dateText_guess(dateBuffer_guess);
    dateText_guess.FUN_005722d0_guess(0);
    FUN_0046da4a_guess(text_guess, 0x3065, dateText_guess,
        0, 0, 0, 0, 0, 0, 0, 0);
    text_guess[strlen(text_guess)] = 0;
    DspChat_guess(text_guess);
}

struct ContextActionRegion_guess {
    char padding_0000_guess[8];
    ContextAction_guess actions_guess[0x2000];
};

struct ContextStatePrefix_guess {
    char padding_0000_guess[0x10];
};

struct ContextStateFields_guess {
    char padding_0000_guess[0x78];
    void* field78_guess;
};

struct ContextState_guess : ContextStatePrefix_guess, ContextStateFields_guess {
};

struct EQ_CharacterProfileView2_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView2_guess::GetCharInfo2
    ContextState_guess* GetCharInfo2();
};

struct ContextStateAccessorRegion_guess {
    char padding_0000_guess[0xC];
    EQ_CharacterProfileView2_guess accessors_guess[0x2000];
};

struct ContextEntryRegion_guess {
    char padding_0000_guess[0xD38];
    ContextEntry_guess* entries_guess[0x24];
};

// EXTERNAL: TITANIUM 0x00470D4F BuildMoneyText_guess
void __cdecl BuildMoneyText_guess(int first_guess, int second_guess,
    int third_guess, int fourth_guess, char* output_guess);

// DoMainLoop helper, once no request is pending (0x9248D0): sends the queued split coins (opcode
// 0x5C44, not in patch_Titanium.conf) with 'You receive %1 as your split.', then moves the first of the
// 36 queued items that has a real slot (< 30000) to the empty cursor.
// FUNCTION: TITANIUM 0x004994B9
// @early-stop: budget, structural ndiff=74
void __cdecl ProcessPendingCoinsAndCursorItems_guess() {
    ContextEntry_guess* entry_guess;
    int coinPacket_guess[4];
    int moveItemPacket_guess[3];
    char formatted_guess[0x200];
    char text_guess[0x80];
    int* pending_guess = EQ_ARRAY(int, 0x00923D08);
    int hasPending_guess = 0;

    if (g_value_009248d0_guess <= 0 && g_contextObject_guess != 0) {
        int* currentPending_guess = pending_guess;
        do {
            if (*currentPending_guess > 0) {
                hasPending_guess = 1;
            }
            ++currentPending_guess;
        } while (reinterpret_cast<int>(currentPending_guess) <
            reinterpret_cast<int>(EQ_ARRAY(int, 0x00923D18)));

        if (hasPending_guess) {
            reinterpret_cast<ContextActionRegion_guess*>(g_contextObject_guess)->
                actions_guess[g_contextObject_guess->field08_guess->field04_guess].
                SetValue0_guess(pending_guess[0]);
            coinPacket_guess[0] = pending_guess[0];
            reinterpret_cast<ContextActionRegion_guess*>(g_contextObject_guess)->
                actions_guess[g_contextObject_guess->field08_guess->field04_guess].
                SetValue1_guess(pending_guess[1]);
            coinPacket_guess[1] = pending_guess[1];
            reinterpret_cast<ContextActionRegion_guess*>(g_contextObject_guess)->
                actions_guess[g_contextObject_guess->field08_guess->field04_guess].
                SetValue2_guess(pending_guess[2]);
            coinPacket_guess[2] = pending_guess[2];
            reinterpret_cast<ContextActionRegion_guess*>(g_contextObject_guess)->
                actions_guess[g_contextObject_guess->field08_guess->field04_guess].
                SetValue3_guess(pending_guess[3]);
            coinPacket_guess[3] = pending_guess[3];
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5c44,
                coinPacket_guess, 0x10, 1);
            g_textProcessor_guess->WavePlay_guess(0x8a, 0);
            text_guess[0] = 0;
            BuildMoneyText_guess(pending_guess[0], pending_guess[1],
                pending_guess[2], pending_guess[3], text_guess);
            FUN_0046da4a_guess(formatted_guess, 0x2f27, text_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            g_globalState_guess->DspChat_guess(formatted_guess, 0x11d, true);

            for (int clearIndex_guess = 0; clearIndex_guess < 4; ++clearIndex_guess) {
                pending_guess[clearIndex_guess] = 0;
            }
            if (g_contextObject_guess != 0) {
                g_contextObject_guess->fieldc28c_guess = 1;
            }
        }

        ContextStateAccessorRegion_guess* accessorRegion_guess =
            reinterpret_cast<ContextStateAccessorRegion_guess*>(g_contextObject_guess);
        if (accessorRegion_guess->accessors_guess[
                g_contextObject_guess->field08_guess->field04_guess].GetCharInfo2()->
                field78_guess == 0 &&
            g_clockData_guess->field11_guess == 0 &&
            g_clockData_guess->field12_guess == 0) {
            ContextEntryRegion_guess* entryRegion_guess =
                reinterpret_cast<ContextEntryRegion_guess*>(g_contextObject_guess);
            for (unsigned int index_guess = 0; index_guess < 0x24; ++index_guess) {
                if (index_guess >= 0x24) __debugbreak();
                if (entryRegion_guess->entries_guess[index_guess] != 0) {
                    if (index_guess >= 0x24) __debugbreak();
                    if (entryRegion_guess->entries_guess[index_guess]->value4c_guess < 30000) {
                        if (index_guess >= 0x24) __debugbreak();
                        entry_guess = entryRegion_guess->entries_guess[index_guess];
                        accessorRegion_guess->accessors_guess[
                            g_contextObject_guess->field08_guess->field04_guess].
                            GetCharInfo2()->field78_guess = entry_guess;
                        g_clockData_guess->field10_guess = 1;
                        if (index_guess >= 0x24) __debugbreak();
                        moveItemPacket_guess[0] =
                            entryRegion_guess->entries_guess[index_guess]->value4c_guess;
                        // Slot 30 is the cursor; the packet is OP_MoveItem {from, to, count}.
                        moveItemPacket_guess[1] = InvSlot_Cursor;
                        moveItemPacket_guess[2] = 0;
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x420f,
                            moveItemPacket_guess, 0xc, 1);
                        if (index_guess >= 0x24) __debugbreak();
                        entryRegion_guess->entries_guess[index_guess] = 0;
                        return;
                    }
                }
            }
        }
    }
}

// Shows why a group invite was cancelled: reasons 1-5 are eqstr 0x2FE8..0x2FEA, 0x13DE and 0x13E0.
// FUNCTION: TITANIUM 0x0049D300
void GlobalState_guess::doUnInvite_guess(SourceText_guess* source_guess) {
    switch (source_guess->field80_guess) {
    case 1: {
        char text_guess[512];
        FUN_0046da4a_guess(text_guess, 0x2fe8, source_guess->field40_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess);
        break;
    }
    case 2: {
        char text_guess[512];
        FUN_0046da4a_guess(text_guess, 0x2fe9, source_guess->field40_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess);
        break;
    }
    case 3: {
        char text_guess[512];
        FUN_0046da4a_guess(text_guess, 0x2fea, source_guess->field40_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess);
        break;
    }
    case 4: {
        char text_guess[512];
        FUN_0046da4a_guess(text_guess, 0x13de, source_guess->field40_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess);
        break;
    }
    case 5: {
        char text_guess[512];
        FUN_0046da4a_guess(text_guess, 0x13e0, source_guess->field40_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess);
        break;
    }
    default:
        return;
    }
}

struct PromptState_guess {
    // EXTERNAL: TITANIUM 0x0042FCCE PromptState_guess::IsInvitePending_guess
    char IsInvitePending_guess();
    // EXTERNAL: TITANIUM 0x0042FCC2 PromptState_guess::IsInRaid_guess
    char IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x0042FCF9 PromptState_guess::IsLocked_guess
    char IsLocked_guess();
    // EXTERNAL: TITANIUM 0x004303A6 PromptState_guess::IsMember_guess
    char IsMember_guess(const char* source_guess);
    // EXTERNAL: TITANIUM 0x0043077B PromptState_guess::IsPlayerGroupLeader_guess
    char IsPlayerGroupLeader_guess();
};

#define g_promptState_0091d708_guess EQ_ARRAY(PromptState_guess, 0x0091D708)
#define g_promptShown_00985808_guess EQ_GLOBAL(unsigned char, 0x00985808)
#define g_promptAccepted_00985844_guess EQ_GLOBAL(unsigned char, 0x00985844)
#define g_promptOutput_00985845_guess EQ_ARRAY(char, 0x00985845)

struct LastPlayer_guess {
    char padding_0000_guess[0x120];
    char name_guess[0x40];
    char padding_0160_guess[0x244 - 0x160];
    unsigned char flag244_guess;
    char padding_0245_guess[0x13];
    unsigned int field258_guess;
    char padding_025c_guess[4];
    int field260_guess;
    char padding_0264_guess[0xC];
    int field270_guess;
};

#define g_lastPlayer_00905d04_guess EQ_GLOBAL(LastPlayer_guess*, 0x00905D04)

struct PlayerActionView_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x0047994F PlayerActionView_guess::NotOnSameDeity_guess
    int NotOnSameDeity_guess(EQPlayer* target_guess, int zero_guess);
};

// /invite: only the leader may invite (0x9043A4 holds the leader's name). Checks self, the target or
// `name`, the 0x91D708 state and duplicates in the 5-name member list, then sends the invite.
// FUNCTION: TITANIUM 0x0049D3CC
// @early-stop: budget, structural ndiff=82
void GlobalState_guess::Invite_guess(char* name_guess) {
    struct NameSendBuffers_guess {
        char name_guess[64];
        char owner_guess[64];
    };
    char inputName_guess[64];
    NameSendBuffers_guess sendBuffers_guess;
    char message_guess[512];

    if (EQ_GLOBAL(unsigned char, 0x009043A4) != 0 &&
        strcmp(EQ_ARRAY(char, 0x009043A4),
            g_contextObject_guess->field44_guess +
                g_contextObject_guess->field08_guess->field04_guess) != 0) {
        DspChat_guess(pStringTable->getString(0x2feb, 0));
        return;
    }

    if (g_lastPlayer_00905d04_guess == 0) {
        if (name_guess == 0 || *name_guess == '\0') {
            DspChat_guess(pStringTable->getString(0x2fec, 0));
            return;
        }
    } else if (g_lastPlayer_00905d04_guess->flag244_guess != 0 &&
        (name_guess == 0 || *name_guess == '\0')) {
        DspChat_guess(pStringTable->getString(0x2fed, 0));
        return;
    } else if (g_lastPlayer_00905d04_guess ==
            reinterpret_cast<LastPlayer_guess*>(g_resetOwner_guess) &&
        (name_guess == 0 || *name_guess == '\0')) {
        DspChat_guess(pStringTable->getString(0x2fee, 0));
        return;
    }

    if (name_guess != 0 && *name_guess == '\0' &&
        _stricmp(g_resetOwner_guess->name_0120_guess, name_guess) == 0) {
        DspChat_guess(pStringTable->getString(0x2fee, 0));
        return;
    }
    if (g_lastPlayer_00905d04_guess != 0 && EQ_GLOBAL(int, 0x00900478) == 4 &&
        reinterpret_cast<PlayerActionView_guess*>(g_displayPlayer_guess)->NotOnSameDeity_guess(
            reinterpret_cast<EQPlayer*>(g_lastPlayer_00905d04_guess), 0) != 0) {
        DspChat_guess(pStringTable->getString(0x2fef, 0));
        return;
    }

    if (g_promptState_0091d708_guess->IsInRaid_guess() != 0) {
        if (g_promptState_0091d708_guess->IsPlayerGroupLeader_guess() == 0) {
            DspChat_guess(pStringTable->getString(0x13df, 0));
            return;
        }
        if (g_promptState_0091d708_guess->IsLocked_guess() != 0) {
            DspChat_guess(pStringTable->getString(0x22a5, 0), 0xd, true);
            return;
        }
    }

    if (name_guess == 0 || *name_guess == '\0') {
        if (g_lastPlayer_00905d04_guess == 0) {
            DspChat_guess(pStringTable->getString(0x2fec, 0));
            return;
        }
        name_guess = g_lastPlayer_00905d04_guess->name_guess;
    }
    FUN_0060e450_guess(inputName_guess, name_guess);

    name_guess = EQ_ARRAY(char, 0x0090424D);
    char* namesEnd_guess = EQ_ARRAY(char, 0x0090438D);
    do {
        if (*name_guess != '\0' && strcmp(inputName_guess, name_guess) == 0) {
            DspChat_guess(pStringTable->getString(0x2ff0, 0));
            return;
        }
        name_guess += 0x40;
    } while ((int)name_guess < (int)namesEnd_guess);

    int nameCount_guess = 0;
    char* emptyEntry_guess = EQ_ARRAY(char, 0x0090424D);
    do {
        if (*emptyEntry_guess == '\0') {
            if (nameCount_guess >= 0) {
                FUN_0060e450_guess(sendBuffers_guess.name_guess, inputName_guess);
                FUN_0060e450_guess(sendBuffers_guess.owner_guess,
                    g_resetOwner_guess->name_0120_guess);
                unsigned int messageId_guess = EQ_GLOBAL(unsigned char, 0x009043A4) == 0
                    // OP_GroupInvite when not grouped yet, else OP_GroupInvite2 (0x12D6);
                    // both carry {invitee, inviter}.
                    ? 0x1b48 : 0x12d6;
                FUN_004912b1_guess(&g_connection_00905ca0_guess, messageId_guess,
                    sendBuffers_guess.name_guess, 0x80, 1);
                FUN_0046da4a_guess(message_guess, 0x2ff1, inputName_guess,
                    0, 0, 0, 0, 0, 0, 0, 0);
                DspChat_guess(message_guess);
                return;
            }
            break;
        }
        emptyEntry_guess += 0x40;
        ++nameCount_guess;
    } while ((int)emptyEntry_guess < (int)namesEnd_guess);

    DspChat_guess(pStringTable->getString(0x2ff3, 0));
}

struct ListOwner_guess {
    unsigned int field00_guess;
    List_guess list_guess;
    ListOwner_guess* Release_guess(unsigned char flags_guess);
};

// Character-name check: not the reserved text at 0x63FE10, and 4 to 15 characters.
// FUNCTION: TITANIUM 0x004933FE
int GlobalState_guess::IsValidName_guess(char* text_guess) {
    if (CompareText_guess(text_guess, g_text_0063fe10_guess) != 0) {
        return 0;
    }
    int length_guess = (int)strlen(text_guess);
    if (length_guess < 4 || length_guess > 15) {
        return 0;
    }
    return 1;
}

// Scalar deleting destructor: deletes every item of the list at +4; flag 1 frees the memory.
// FUNCTION: TITANIUM 0x00498B36
ListOwner_guess* ListOwner_guess::Release_guess(unsigned char flags_guess) {
    list_guess.DeleteAll_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

#define g_userdata_006492e8_guess EQ_ARRAY(char, 0x006492E8)
#define g_pattern_006492dc_guess EQ_ARRAY(char, 0x006492DC)
#define g_simple_006492d4_guess EQ_ARRAY(char, 0x006492D4)
#define g_maps_006492cc_guess EQ_ARRAY(char, 0x006492CC)

// Creates the userdata and maps folders when missing.
// FUNCTION: TITANIUM 0x00493A10
void __cdecl CreateUserDirectories_guess() {
    char path_guess[0x800];
    WIN32_FIND_DATAA data_guess;
    _sprintf(path_guess, g_pattern_006492dc_guess, g_userdata_006492e8_guess);
    if (FindFirstFileA(path_guess, &data_guess) == INVALID_HANDLE_VALUE) {
        _sprintf(path_guess, g_simple_006492d4_guess, g_userdata_006492e8_guess);
        CreateDirectoryA(path_guess, 0);
    }
    _sprintf(path_guess, g_pattern_006492dc_guess, g_maps_006492cc_guess);
    if (FindFirstFileA(path_guess, &data_guess) == INVALID_HANDLE_VALUE) {
        _sprintf(path_guess, g_simple_006492d4_guess, g_maps_006492cc_guess);
        CreateDirectoryA(path_guess, 0);
    }
}

#define g_worldName_0098754c_guess EQ_ARRAY(char, 0x0098754C)
#define g_worldSuffix_00987554_guess EQ_ARRAY(char, 0x00987554)
#define g_fontIndex_00923d74_guess EQ_GLOBAL(int, 0x00923D74)
#define g_configText_0095d3d4_guess EQ_ARRAY(char, 0x0095D3D4)

// EXTERNAL: TITANIUM 0x0062202C _strnicmp
int __cdecl _strnicmp(const char* first_guess, const char* second_guess,
    unsigned int count_guess);
// EXTERNAL: TITANIUM 0x0060E620 _strncpy
char* __cdecl _strncpy(char* destination_guess, const char* source_guess,
    unsigned int count_guess);
// EXTERNAL: TITANIUM 0x00610380 _strcspn
unsigned int __cdecl _strcspn(const char* text_guess, const char* control_guess);
// EXTERNAL: TITANIUM 0x00574310 FUN_00574310_guess
void __cdecl FUN_00574310_guess(char* destination_guess, const char* source_guess,
    int count_guess);
// EXTERNAL: TITANIUM 0x00612662 FUN_00612662_guess
void __cdecl FUN_00612662_guess(char* path_guess);

// Deletes <name>_<server>.opt. The server short name is the 2-3 characters after 'eqworld' for an
// eqworld-* host, else the host up to its first dot.
// FUNCTION: TITANIUM 0x00493430
void __stdcall RemoveCharacterOptionFile_guess(char* name_guess) {
    char buffer_guess[512];
    char world_guess[512];
    FUN_0060e450_guess(buffer_guess, name_guess);
    FUN_0060e460_guess(buffer_guess, "_");
    if (_strnicmp(g_worldName_0098754c_guess, "eqworld", 7) == 0) {
        _strncpy(world_guess, g_worldSuffix_00987554_guess, 3);
        world_guess[3] = 0;
        if (world_guess[2] == '.') {
            world_guess[2] = 0;
        }
    } else {
        unsigned int length_guess = _strcspn(g_worldName_0098754c_guess, ".");
        _strncpy(world_guess, g_worldName_0098754c_guess, length_guess);
        world_guess[length_guess] = 0;
    }
    FUN_0060e460_guess(buffer_guess, world_guess);
    FUN_0060e460_guess(buffer_guess, ".opt");
    FUN_00612662_guess(buffer_guess);
}

struct StatUpdater_guess {
    // EXTERNAL: TITANIUM 0x004F1733 StatUpdater_guess::RebuildPlayerActor_guess
    void RebuildPlayerActor_guess(StatDisplay_guess* display_guess, unsigned char first_guess,
        int value_guess, unsigned char second_guess, unsigned char third_guess);
};

#define g_statUpdater_00850b9c_guess EQ_GLOBAL(StatUpdater_guess*, 0x00850B9C)

struct StatDisplay_guess {
    char padding_0000_guess[0x245];
    unsigned char field245_guess; // 0x245
    unsigned char field246_guess; // 0x246
    unsigned char field247_guess; // 0x247
    unsigned char field248_guess; // 0x248
    unsigned char field249_guess; // 0x249
    unsigned char field24a_guess; // 0x24A
    char padding_024b_guess[2]; // 0x24B
    unsigned char field24d_guess; // 0x24D
    char padding_024e_guess[6]; // 0x24E
    unsigned char field254_guess; // 0x254
    unsigned char field255_guess; // 0x255
    // EXTERNAL: TITANIUM 0x0047A3EB StatDisplay_guess::SetArmorType_guess
    void SetArmorType_guess(int index_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0047A406 StatDisplay_guess::SetArmorTint_guess
    void SetArmorTint_guess(int index_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0047A3D0 StatDisplay_guess::GetArmorType_guess
    int GetArmorType_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004845D8 StatDisplay_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int index_guess, int value_guess, int bonus_guess,
        int other_guess, int one_guess);
    // EXTERNAL: TITANIUM 0x0047DEC4 StatDisplay_guess::SwapFace_guess
    void SwapFace_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0048083A StatDisplay_guess::FUN_0048083a_guess
    void FUN_0048083a_guess(int id_guess, const char* text_guess, int one_guess);
};

// Copies char-select slot `index` (0..7) into a model: face, hair, beard, eye colours, the nine armour
// textures and tints, and the two weapon models as IT<n>. `update` also rebuilds the model (0x4F1733).
// FUNCTION: TITANIUM 0x00493512
void GlobalState_guess::SetPlayerAppearanceFromPInfo_guess(StatDisplay_guess* display_guess,
    int index_guess, char update_guess) {
    if (display_guess != 0 && index_guess >= 0 && index_guess <= 7) {
        int i_guess;
        display_guess->field24d_guess = field39806_guess[index_guess];
        display_guess->field24a_guess = field3978c_guess[index_guess];
        display_guess->field246_guess = field395a0_guess[index_guess];
        display_guess->field249_guess = field395aa_guess[index_guess];
        display_guess->field245_guess = field397c8_guess[index_guess];
        display_guess->field247_guess = field39a9a_guess[index_guess];
        display_guess->field248_guess = field39aa4_guess[index_guess];
        display_guess->field254_guess = field39744_guess[index_guess];
        display_guess->field255_guess = field39796_guess[index_guess];
        if (update_guess != 0) {
            g_statUpdater_00850b9c_guess->RebuildPlayerActor_guess(display_guess,
                field39a90_guess[index_guess], field39410_guess[index_guess] - 1,
                display_guess->field24d_guess, field397fc_guess[index_guess]);
        }
        for (i_guess = 0; i_guess < 9; i_guess++) {
            display_guess->SetArmorType_guess(i_guess, 0);
            display_guess->SetArmorTint_guess(i_guess, 0);
        }
        for (i_guess = 0; i_guess < 9; i_guess++) {
            display_guess->HandleMaterialEx_guess(i_guess, field395b4_guess[index_guess][i_guess],
                display_guess->GetArmorType_guess(i_guess),
                field39438_guess[index_guess][i_guess], 1);
        }
        display_guess->SwapFace_guess(field39806_guess[index_guess],
            display_guess->field24d_guess);
        char text_guess[512];
        int value_guess = field397a0_guess[index_guess];
        if (value_guess > 0) {
            _sprintf(text_guess, "IT%d", value_guess);
            display_guess->FUN_0048083a_guess(7, text_guess, 1);
        } else {
            display_guess->FUN_0048083a_guess(7, "0", 1);
        }
        value_guess = field3971c_guess[index_guess];
        if (value_guess > 0) {
            _sprintf(text_guess, "IT%d", value_guess);
            display_guess->FUN_0048083a_guess(8, text_guess, 1);
        } else {
            display_guess->FUN_0048083a_guess(8, "0", 1);
        }
    }
}

struct PositionOwner_guess {
    char padding_0000_guess[0x30];
    float field30_guess; // 0x30
    float field34_guess; // 0x34
    float field38_guess; // 0x38
};

#define g_positionOwner_00905ce4_guess EQ_GLOBAL(PositionOwner_guess*, 0x00905CE4)

// True while the player stands in the box x -340..-329, y -8..8, z -39..-30 of the char-select scene;
// the char-select loop treats it as stepping through to create/enter.
// FUNCTION: TITANIUM 0x00493700
char GlobalState_guess::IsInCharCreateTrigger_guess() {
    float x_guess = g_positionOwner_00905ce4_guess->field30_guess;
    float y_guess = g_positionOwner_00905ce4_guess->field34_guess;
    float z_guess = g_positionOwner_00905ce4_guess->field38_guess;
    return x_guess > -340.0 && x_guess < -329.0 && y_guess > -8.0 && y_guess < 8.0 &&
        z_guess > -39.0 && z_guess < -30.0;
}

struct DisplayRoot_guess {
    char padding_0000_guess[0x13];
    unsigned char field13_guess; // 0x13
    char padding_0014_guess[0x148 - 0x14];
    unsigned int field148_guess;
    // EXTERNAL: TITANIUM 0x0043EE74 DisplayRoot_guess::InitCharSelectUI_guess
    void InitCharSelectUI_guess();
    // EXTERNAL: TITANIUM 0x00439A93 DisplayRoot_guess::SetPCNameSpriteState_guess
    void SetPCNameSpriteState_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00439AC7 DisplayRoot_guess::SetNPCNameSpriteState_guess
    void SetNPCNameSpriteState_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00440F42 DisplayRoot_guess::SetYon_guess
    void SetYon_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x004459E5 DisplayRoot_guess::SetDayPeriod_guess
    void SetDayPeriod_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004437E5 DisplayRoot_guess::SetSunLight_guess
    void SetSunLight_guess();
    // EXTERNAL: TITANIUM 0x00436156 DisplayRoot_guess::FUN_00436156_guess
    void FUN_00436156_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004439C0 DisplayRoot_guess::SetSkyBackground_guess
    void SetSkyBackground_guess();
    // EXTERNAL: TITANIUM 0x0043C78F DisplayRoot_guess::ChangeVideoMode_guess
    void ChangeVideoMode_guess();
    // EXTERNAL: TITANIUM 0x0043933D DisplayRoot_guess::FUN_0043933d_guess
    void FUN_0043933d_guess();
    // EXTERNAL: TITANIUM 0x004365DB DisplayRoot_guess::FixHeading_guess
    float FixHeading_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x004392DE DisplayRoot_guess::SetCameraMode_guess
    void SetCameraMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004426FB DisplayRoot_guess::SetupCharacterViewCamera_guess
    void SetupCharacterViewCamera_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00445842 DisplayRoot_guess::Render_MinWorld_guess
    void Render_MinWorld_guess();
};

struct FloatSource_guess {
    // EXTERNAL: TITANIUM 0x004899CC FloatSource_guess::FUN_004899cc_guess
    float FUN_004899cc_guess();
};

struct VideoTarget_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess(float value_guess);
    virtual void Slot04_guess(float value_guess);
    virtual void Slot05_guess(float value_guess);
    virtual void Slot06_guess(float value_guess);
    virtual void Slot07_guess();
    virtual void Slot08_guess(float value_guess);
    virtual void Slot09_guess();
    virtual void Slot10_guess(float value_guess);
};

#define g_displayRoot_guess EQ_GLOBAL(DisplayRoot_guess*, 0x00905D24)
#define g_floatSource_guess EQ_GLOBAL(FloatSource_guess*, 0x00905CE4)
#define g_videoTarget_00925518_guess EQ_GLOBAL(VideoTarget_guess*, 0x00925518)
#define g_float_006492c8_guess EQ_GLOBAL(float, 0x006492C8)

// EXTERNAL: TITANIUM 0x004B649F FUN_004b649f_guess
ConnectionStatus_guess* __cdecl FUN_004b649f_guess(HWND hwnd_guess, int value_guess);
// EXTERNAL: TITANIUM 0x00487FF0 LoadAnimationSounds_guess
void __cdecl LoadAnimationSounds_guess(const char* name_guess);

struct RaceData_guess {
    char padding_0000_guess[0x2C];
    // EXTERNAL: TITANIUM 0x0048F742 RaceData_guess::RaceData_guess
    RaceData_guess(char* path_guess);
};

#define g_nameBuffer_00905c18_guess EQ_ARRAY(char, 0x00905C18)
#define g_raceData_00903e80_guess EQ_GLOBAL(RaceData_guess*, 0x00903E80)

// Connects to the world (0x4B649F); a connection that brings no name is dropped. Loads spells_<lang>.txt,
// racedata.txt and AnimationSounds.txt once and shows the window. Returns -1 (or -2 once on a retry).
// FUNCTION: TITANIUM 0x0049377D
int GlobalState_guess::DoLogin_guess(HWND hwnd_guess, int value_guess) {
    g_sendDisabled_00923798_guess = 0;
    FUN_0060e450_guess(g_nameBuffer_00905c18_guess, "*NO NAME*");
    g_connection_00905ca0_guess = FUN_004b649f_guess(hwnd_guess, value_guess);
    if (g_connection_00905ca0_guess != 0) {
        if (strcmp(g_nameBuffer_00905c18_guess, "*NO NAME*") == 0) {
            FUN_0060e450_guess(g_nameBuffer_00905c18_guess, g_text_0063f53f_guess);
            g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
            return -1;
        }
        g_connection_00905ca0_guess->BeginWait_guess(
            g_connectionManager_guess != 0
                ? reinterpret_cast<DisconnectWaitState_guess*>(&g_connectionManager_guess->field48_guess)
                : 0);
    } else {
        if (fieldb50_guess == 1) {
            return -1;
        }
        if (fieldb50_guess == 2) {
            fieldb50_guess = 1;
            return -2;
        }
    }
    if (g_owned_00985cc8_guess == 0) {
        char spellsPath_guess[0x100] = {0};
        _sprintf(spellsPath_guess, "spells_%s.txt",
            EQ_ARRAY(const char*, 0x00799830)[g_fontIndex_00923d74_guess]);
        g_owned_00985cc8_guess = new Owned4C7666_guess(spellsPath_guess);
    }
    if (g_raceData_00903e80_guess == 0) {
        char raceDataPath_guess[0x100] = {0};
        _sprintf(raceDataPath_guess, "racedata.txt",
            EQ_ARRAY(const char*, 0x00799830)[g_fontIndex_00923d74_guess]);
        g_raceData_00903e80_guess = new RaceData_guess(raceDataPath_guess);
    }
    LoadAnimationSounds_guess("AnimationSounds.txt");
    ShowWindow(hwnd_guess, 10);
    UpdateWindow(hwnd_guess);
    g_ownedDisplay_guess->InitDisplay_guess();
    g_ownedDisplay_guess->InitWorld_guess();
    return -1;
}

// Puts the camera in the fixed char-select view (mode 7).
// FUNCTION: TITANIUM 0x00493978
void __cdecl SetupCharSelectCamera_guess() {
    g_displayRoot_guess->SetCameraMode_guess(7);
    g_videoTarget_00925518_guess->Slot06_guess(6.0f);
    g_videoTarget_00925518_guess->Slot04_guess(-(g_floatSource_guess->FUN_004899cc_guess() * 0.33f));
    g_videoTarget_00925518_guess->Slot08_guess(g_float_006492c8_guess);
    g_videoTarget_00925518_guess->Slot05_guess(0.0f);
    g_videoTarget_00925518_guess->Slot03_guess(0.0f);
    g_videoTarget_00925518_guess->Slot10_guess(90.0f);
}

// Short world name for file names: the 2-3 characters after 'eqworld', else up to 8 characters of
// the host converted for the language.
// FUNCTION: TITANIUM 0x00493ADA
void WorldName_guess::Read_guess(char* output_guess) {
    char buffer_guess[0x100];
    if (_strnicmp(g_worldName_0098754c_guess, "eqworld", 7) == 0) {
        _strncpy(output_guess, g_worldSuffix_00987554_guess, 3);
        output_guess[3] = 0;
        if (output_guess[2] == '.') {
            output_guess[2] = 0;
        }
    } else {
        buffer_guess[0] = 0;
        _strcspn(g_worldName_0098754c_guess, ".");
        memset(buffer_guess, 0, 0x100);
        FUN_00574310_guess(buffer_guess, g_worldName_0098754c_guess, 8);
        FUN_005749f0_guess(GetLanguageCodePage_guess(g_fontIndex_00923d74_guess),
            buffer_guess, output_guess, 0x100);
    }
}

// Long world name (0x95D3D4) converted for the language; WriteBazaarLog uses it.
// FUNCTION: TITANIUM 0x00493B8F
void WorldName_guess::GetServerShortName_guess(char* output_guess) {
    char buffer_guess[0x100];
    buffer_guess[0] = 0;
    FUN_0060e450_guess(buffer_guess, g_configText_0095d3d4_guess);
    FUN_005749f0_guess(GetLanguageCodePage_guess(g_fontIndex_00923d74_guess),
        buffer_guess, output_guess, 0x100);
}

struct SystemInfoProvider_guess {
    virtual unsigned int RefreshCounts_guess(); virtual unsigned int Slot01_guess();
    virtual unsigned int Slot02_guess(); virtual unsigned int Slot03_guess();
    virtual unsigned int Slot04_guess(); virtual unsigned int Slot05_guess();
    virtual unsigned int Slot06_guess(); virtual unsigned int Slot07_guess();
    virtual unsigned int Slot08_guess(); virtual unsigned int Slot09_guess();
    virtual unsigned int Slot10_guess(); virtual unsigned int Slot11_guess();
    virtual unsigned char Slot12_guess(); virtual unsigned char Slot13_guess();
    virtual unsigned char Slot14_guess(); virtual unsigned int Slot15_guess();
    virtual unsigned int Slot16_guess(); virtual unsigned int Slot17_guess();
    virtual unsigned int Slot18_guess(); virtual unsigned int Slot19_guess();
    virtual unsigned int Slot20_guess(); virtual unsigned int Slot21_guess();
    virtual unsigned int Slot22_guess(); virtual unsigned int Slot23_guess();
    virtual unsigned int Slot24_guess(); virtual unsigned int Slot25_guess();
    virtual unsigned int Slot26_guess(); virtual unsigned int Slot27_guess();
    virtual unsigned int Slot28_guess(); virtual unsigned int Slot29_guess();
    virtual unsigned int Slot30_guess(); virtual unsigned int Slot31_guess();
    virtual unsigned int Slot32_guess(); virtual unsigned int Slot33_guess();
    virtual unsigned int Slot34_guess(); virtual unsigned int Slot35_guess();
    virtual unsigned int Slot36_guess(); virtual unsigned int Slot37_guess();
    virtual unsigned int Slot38_guess(); virtual unsigned int Slot39_guess();
    virtual unsigned int Slot40_guess(); virtual unsigned int Slot41_guess();
    virtual unsigned int Slot42_guess(); virtual unsigned int Slot43_guess();
    virtual unsigned int Slot44_guess(); virtual unsigned int Slot45_guess();
    virtual unsigned int Slot46_guess(); virtual unsigned int Slot47_guess();
};

struct SystemInfoSource_guess {
    char padding_0000_guess[0x14];
    unsigned int field14_guess;
    unsigned int field18_guess;
    unsigned int field1c_guess;
    unsigned int field20_guess;
    unsigned int field24_guess;
    unsigned char field28_guess;
    unsigned char field29_guess;
    unsigned char field2a_guess;
    unsigned char field2b_guess;
    unsigned char field2c_guess;
    char padding_002d_guess[3];
    const char* field30_guess;
};

struct SystemInfoPacket_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned int field0c_guess;
    unsigned int field10_guess;
    unsigned char field14_guess;
    unsigned char field15_guess;
    unsigned char field16_guess;
    unsigned char field17_guess;
    unsigned char field18_guess;
    char field19_guess[51];
    unsigned int totalPhysicalMB_guess;
    unsigned int totalVirtualMB_guess;
    unsigned int field54_guess;
    unsigned int field58_guess;
    unsigned int field5c_guess;
    unsigned int field60_guess;
    unsigned int field64_guess;
    unsigned int field68_guess;
    unsigned int field6c_guess;
    unsigned int field70_guess;
    unsigned int field74_guess;
    unsigned char field78_guess;
    unsigned char field79_guess;
    unsigned char field7a_guess;
    char field7b_guess[65];
    unsigned int fieldbc_guess;
    unsigned int fieldc0_guess;
    unsigned int platformId_guess;
    unsigned int majorVersion_guess;
    unsigned int minorVersion_guess;
    unsigned int fieldd0_guess;
    unsigned int fieldd4_guess;
    char servicePack_guess[128];
};

struct ExtendedOSVersion_guess {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[128];
    WORD wServicePackMajor;
    WORD wServicePackMinor;
    WORD wSuiteMask;
    BYTE wProductType;
    BYTE wReserved;
};

#define g_systemInfoProvider_guess EQ_GLOBAL(SystemInfoProvider_guess*, 0x0099E364)
#define g_systemInfoSource_guess EQ_GLOBAL(SystemInfoSource_guess*, 0x0099E354)

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();
// EXTERNAL: TITANIUM 0x006093AA Ordinal_11_guess
void __stdcall Ordinal_11_guess(void* first_guess, void* second_guess);

// Once a week (604800 s after [Defaults] LastSysInfoDate) sends the OS version, memory and graphics
// details (opcode 0x1C4C, 0x158 bytes; not in patch_Titanium.conf).
// FUNCTION: TITANIUM 0x00493BEA
// @early-stop: budget, normalised ndiff=0
void GlobalState_guess::SendSystemInfo_guess() {
    ExtendedOSVersion_guess version_guess;
    MEMORYSTATUS memory_guess;
    SystemInfoPacket_guess packet_guess;
    int lastUpdate_guess;

    memset(&version_guess, 0, 0x9c);
    version_guess.dwOSVersionInfoSize = 0x9c;
    if (GetVersionExA((OSVERSIONINFOA*)&version_guess) == 0) {
        version_guess.dwOSVersionInfoSize = 0x94;
        GetVersionExA((OSVERSIONINFOA*)&version_guess);
    }
    lastUpdate_guess = ReadClientIniInt_guess("Defaults", "LastSysInfoDate", 0);
    if ((unsigned int)(FUN_00576e80_guess() - lastUpdate_guess) >= 0x93a80) {
        memory_guess.dwLength = 0x20;
        GlobalMemoryStatus(&memory_guess);
        memset(&packet_guess, 0, 0x158);
        packet_guess.totalPhysicalMB_guess = (memory_guess.dwTotalPhys + 0xfffff) >> 0x14;
        packet_guess.totalVirtualMB_guess = (memory_guess.dwTotalVirtual + 0xfffff) >> 0x14;
        packet_guess.field54_guess = g_systemInfoProvider_guess->Slot06_guess();
        packet_guess.field58_guess = g_systemInfoProvider_guess->Slot04_guess();
        packet_guess.field5c_guess = g_systemInfoProvider_guess->Slot05_guess();
        packet_guess.field60_guess = g_systemInfoProvider_guess->Slot07_guess();
        packet_guess.field64_guess = g_systemInfoProvider_guess->Slot02_guess();
        packet_guess.field68_guess = g_systemInfoProvider_guess->RefreshCounts_guess();
        packet_guess.field6c_guess = g_systemInfoProvider_guess->Slot01_guess();
        packet_guess.field70_guess = g_systemInfoProvider_guess->Slot03_guess();
        packet_guess.field74_guess = g_systemInfoProvider_guess->Slot16_guess();
        packet_guess.field78_guess = g_systemInfoProvider_guess->Slot14_guess();
        packet_guess.field79_guess = g_systemInfoProvider_guess->Slot12_guess();
        packet_guess.field7a_guess = g_systemInfoProvider_guess->Slot13_guess();
        FUN_0060e450_guess(packet_guess.field7b_guess,
            (const char*)g_systemInfoProvider_guess->Slot47_guess());
        Ordinal_11_guess(&packet_guess.fieldbc_guess, &packet_guess.fieldc0_guess);

        packet_guess.field00_guess = g_systemInfoSource_guess->field14_guess;
        packet_guess.field04_guess = g_systemInfoSource_guess->field18_guess;
        packet_guess.field08_guess = g_systemInfoSource_guess->field1c_guess;
        packet_guess.field0c_guess = g_systemInfoSource_guess->field20_guess;
        packet_guess.field10_guess = g_systemInfoSource_guess->field24_guess;
        packet_guess.field14_guess = g_systemInfoSource_guess->field28_guess;
        packet_guess.field15_guess = g_systemInfoSource_guess->field29_guess;
        packet_guess.field16_guess = g_systemInfoSource_guess->field2a_guess;
        packet_guess.field17_guess = g_systemInfoSource_guess->field2b_guess;
        packet_guess.field18_guess = g_systemInfoSource_guess->field2c_guess;
        FUN_0060e450_guess(packet_guess.field19_guess,
            g_systemInfoSource_guess->field30_guess);
        packet_guess.platformId_guess = version_guess.dwPlatformId;
        packet_guess.majorVersion_guess = version_guess.dwMajorVersion;
        packet_guess.minorVersion_guess = version_guess.dwMinorVersion;
        packet_guess.fieldd0_guess = version_guess.wServicePackMajor;
        packet_guess.fieldd4_guess = version_guess.wServicePackMinor;
        FUN_0060e450_guess(packet_guess.servicePack_guess, version_guess.szCSDVersion);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1c4c,
            &packet_guess, 0x158, 1);
        FUN_004ae514_guess(FUN_00576e80_guess(), "Defaults", "LastSysInfoDate");
    }
}

// Yes/no popup 0x6F 'Your last name will be %1 is this correct?' (eqstr 0x235A), carrying the name.
// FUNCTION: TITANIUM 0x00493E92
void GlobalState_guess::ConfirmLastName_guess(const char* text_guess) {
    char buffer_guess[512];
    FUN_0046da4a_guess(buffer_guess, 0x235a, text_guess,
        0, 0, 0, 0, 0, 0, 0, 0);
    unsigned int length_guess = strlen(text_guess);
    void* data_guess = FUN_0060e985_guess(length_guess + 1);
    FUN_0060e450_guess((char*)data_guess, text_guess);
    g_deliveryManager_guess->Activate(
        g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0,
        0x6f, buffer_guess, 0xc, 10000, data_guess, 1);
}

// GM buff confirmation (popup 0x72): the player is kicked and buffed on return, as the text says.
// FUNCTION: TITANIUM 0x00493F1B
void GlobalState_guess::ConfirmBuff_guess(
    CharacterInfo_guess* character_guess, BuffNameProvider_guess* buff_guess,
    int level_guess) {
    char buffer_guess[512];
    _sprintf(buffer_guess,
        "Buff %s to a %s, Level %d, is this correct?\nNOTE: This will kick you from the server.  When you return, you will be buffed.",
        &character_guess->name_guess, buff_guess->FUN_00572300_guess(),
        level_guess);
    BuffData_guess* data_guess = (BuffData_guess*)operator new(0x28);
    data_guess->level_guess = (unsigned char)level_guess;
    data_guess->field00_guess = character_guess->field258_guess;
    FUN_0060e450_guess(data_guess->name_guess,
        buff_guess->FUN_00572300_guess());
    g_deliveryManager_guess->Activate(
        g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0,
        0x72, buffer_guess, 0xc, 10000, data_guess, 0);
}

// Yes/no popup 0x73 'Kill %1, is this correct?' (eqstr 0x235C), carrying both names.
// FUNCTION: TITANIUM 0x00493FC0
void GlobalState_guess::ConfirmKill_guess(const char* first_guess, const char* second_guess) {
    char buffer_guess[512];
    FUN_0046da4a_guess(buffer_guess, 0x235c, first_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    void* data_guess = operator new(0x81);
    FUN_0060e450_guess((char*)data_guess, first_guess);
    FUN_0060e450_guess((char*)data_guess + 0x40, second_guess);
    g_deliveryManager_guess->Activate(
        g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0x73,
        buffer_guess, 0xc, 10000, data_guess, 0);
}

// Input mode 0x9237B0: 1 takes focus from the chat input; 0 gives it focus and re-presses movement
// keys that are still held.
// FUNCTION: TITANIUM 0x00494051
void GlobalState_guess::SetChatInputFocus_guess(int value_guess) {
    if (g_state_009237b0_guess != value_guess) {
        if (g_modeProvider_guess != 0) {
            ModeRoot_guess* root_guess = g_modeProvider_guess->GetActiveChatWindow_guess();
            if (root_guess != 0) {
                if (value_guess == 1) {
                    root_guess->field160_guess->FUN_0059cdd0_guess();
                } else {
                    root_guess->field160_guess->SetFocus();
                    unsigned int flags_guess = 0;
                    if (g_modeFlagA_guess != 0) {
                        flags_guess = 1;
                    } else if (g_modeFlagB_guess != 0) {
                        flags_guess = 2;
                    }
                    if (g_modeFlagC_guess != 0) {
                        flags_guess |= 4;
                    } else if (g_modeFlagD_guess != 0) {
                        flags_guess |= 8;
                    }
                    if (g_modeFlagE_guess != 0) {
                        flags_guess |= 0x10;
                    }
                    if (flags_guess != 0) {
                        ExecuteCmd(0, 1, flags_guess);
                    }
                }
            }
        }
        g_state_009237b0_guess = value_guess;
    }
}

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* first_guess, const char* second_guess);

struct DisplayScreenText_guess;

struct DisplayScreenProvider_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual DisplayScreenText_guess* Slot13_guess();
};

struct DisplayScreenText_guess {
    virtual void RefreshCounts_guess(const char* text_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess(int first_guess, int second_guess, int third_guess,
        int width_guess, RECT* rect_guess, int color_guess, int flags_guess,
        int last_guess);
};

struct DisplayInterface_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(DisplayScreenText_guess* text_guess);
    virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess();
    virtual void Slot35_guess(); virtual void Slot36_guess();
    virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess();
};


#define g_flag_00850508_guess EQ_GLOBAL(int, 0x00850508)
#define g_value_00923880_guess EQ_GLOBAL(int, 0x00923880)
#define g_displayScreenProvider_guess EQ_GLOBAL(DisplayScreenProvider_guess*, 0x0099E360)
#define g_displayInterface_guess EQ_GLOBAL(DisplayInterface_guess*, 0x0099E364)
#define g_displayScreenText_guess EQ_GLOBAL(DisplayScreenText_guess*, 0x009858CC)
#define g_renderTarget_guess EQ_GLOBAL(RenderTarget_guess*, 0x0099D3EC)

// Full-screen error text: Discon.bmp shows eqstr 0x3041, anything else 0x3042. The bitmap name only
// picks the text.
// FUNCTION: TITANIUM 0x004932AB
void __stdcall DisplayScreen_guess(char* name_guess) {
    char text_guess[0x100];
    if (g_clockData_guess->GetValue2cf8_guess() != 0) {
        g_flag_00850508_guess = 2;
        g_clockData_guess->ChangeVideoMode_guess();
        const char* tableText_guess;
        if (strcmp(name_guess, "Discon.bmp") == 0) {
            tableText_guess = g_stringTable_guess->Lookup_guess(0x3041, 0);
        } else {
            tableText_guess = g_stringTable_guess->Lookup_guess(0x3042, 0);
        }
        FUN_0060e450_guess(text_guess, tableText_guess);
        g_value_00923880_guess = 0;
        if (g_fontIndex_00923d74_guess == 0) {
            FUN_00574110_guess(text_guess);
        }
        strlen(text_guess);
        g_displayInterface_guess->Slot40_guess();
        RECT rect_guess;
        rect_guess.bottom = 0;
        rect_guess.right = 0;
        rect_guess.left = 0;
        rect_guess.top = 0;
        rect_guess.right = g_renderTarget_guess->width_guess;
        rect_guess.bottom = g_renderTarget_guess->height_guess;
        if (g_displayScreenText_guess == 0) {
            g_displayScreenText_guess = g_displayScreenProvider_guess->Slot13_guess();
        }
        g_displayScreenText_guess->RefreshCounts_guess(text_guess);
        g_displayScreenText_guess->Slot02_guess(6, 0, 0,
            rect_guess.right - rect_guess.left, &rect_guess, -1, 0x30, 0);
        g_displayInterface_guess->Slot30_guess(g_displayScreenText_guess);
        g_displayInterface_guess->Slot37_guess();
        FUN_00574110_guess("\nend of DisplayScreen\n");
    }
}

#define g_value_009858dc_guess EQ_GLOBAL(unsigned int, 0x009858DC)

struct ListEntry_guess {
    char padding_0000_guess[0x120];
    char field120_guess[0x80];
    char padding_01a0_guess[0x74];
    ListEntry_guess* next_guess; // 0x214
    char padding_0218_guess[0x2C];
    unsigned char field244_guess; // 0x244
    char padding_0245_guess[0x11];
    unsigned char field256_guess; // 0x256
    char padding_0257_guess[1];
    unsigned int field258_guess; // 0x258
    unsigned int key_guess; // 0x25C
};

struct OwnerRecord_guess {
    char padding_0000_guess[0x256];
    unsigned char field256_guess; // 0x256
    char padding_0257_guess[1];
    unsigned int field258_guess; // 0x258
};

struct Message_guess {
    int field00_guess;
    int field04_guess;
};

#define g_listHead_00905cc4_guess EQ_GLOBAL(ListEntry_guess*, 0x00905CC4)
#define g_ownerRecord_00905ce4_guess EQ_GLOBAL(OwnerRecord_guess*, 0x00905CE4)
#define g_lastEntry_00905d04_guess EQ_GLOBAL(ListEntry_guess*, 0x00905D04)

#define g_contextIndex_009237f0_guess EQ_GLOBAL(int, 0x009237F0)

// Index 0x9237F0 into the languages the character knows (skill > 0); 0 (common) when out of range.
// FUNCTION: TITANIUM 0x00497BE2
// @early-stop: budget, diff ndiff=14
int GlobalState_guess::GetCurrentLanguage_guess() {
    if (g_contextObject_guess != 0) {
        int values_guess[32];
        memset(values_guess, 0xff, sizeof(values_guess));
        unsigned int index_guess = 0;
        int* output_guess = values_guess;
        do {
            if (index_guess >= 0x20) {
                __debugbreak();
            }
            const char* flags_guess = g_contextObject_guess->field0c_guess +
                g_contextObject_guess->field08_guess->field04_guess + 8;
            if (flags_guess[index_guess] != 0) {
                *output_guess = index_guess;
                ++output_guess;
            }
            ++index_guess;
        } while (index_guess < 0x20);
        int result_guess;
        int selected_guess = g_contextIndex_009237f0_guess;
        if (selected_guess < 0 || selected_guess >= 0x20) {
            result_guess = 0;
        } else {
            result_guess = values_guess[selected_guess];
        }
        if (result_guess >= 0 && result_guess < 0x20) {
            return result_guess;
        }
    }
    return 0;
}

// Sends chat text on channel `type` (OP_ChannelMessage 0x1004) with the language and its skill less
// +0x5ED550 / 4 (probably intoxication); GMs send 100. With 0x923898 set a copy goes out as opcode
// 0x33DC (not in patch_Titanium.conf), group repeats skipped.
// FUNCTION: TITANIUM 0x00497C5B
// @early-stop: budget, structural ndiff=34
void GlobalState_guess::SendNewText_guess(int type_guess, int from_guess,
    int text_guess, int value_guess) {
    char previous_guess[0x800];
    ChatPacket_guess packet_guess;
    LogPacket_guess log_guess;
    const char* target_guess;

    memset(&packet_guess, 0, 0x894);
    memset(&log_guess, 0, 0x8C4);
    packet_guess.value_guess = value_guess;
    if (from_guess == 0) {
        packet_guess.from_guess[0] = 0;
    } else {
        FUN_0060e450_guess(packet_guess.from_guess,
            reinterpret_cast<const char*>(from_guess));
    }
    if (type_guess == 8 && g_lastEntry_00905d04_guess != 0 &&
        g_lastEntry_00905d04_guess->field244_guess == 1 &&
        g_lastEntry_00905d04_guess->field256_guess == 0 &&
        // A /say to your own pet (with ability 0x4B) is addressed to the pet by name.
        g_contextObject_guess->fieldc280_guess.FindBuffWithEffect_guess(0x4b, 0) != 0 &&
        g_lastEntry_00905d04_guess != 0 &&
        g_lastEntry_00905d04_guess->key_guess == g_ownerRecord_00905ce4_guess->field258_guess) {
        target_guess = g_lastEntry_00905d04_guess->field120_guess;
    } else {
        target_guess = &g_contextObject_guess->field44_guess[
            g_contextObject_guess->field08_guess->field04_guess];
    }
    FUN_0060e450_guess(packet_guess.to_guess, target_guess);
    FUN_0060e450_guess(packet_guess.text_guess,
        reinterpret_cast<const char*>(text_guess));
    packet_guess.text_guess[0x7FF] = 0;
    DoPercentConvert_guess(packet_guess.text_guess, 1);
    packet_guess.type_guess = type_guess;
    packet_guess.index_guess = GetCurrentLanguage_guess();
    if (packet_guess.index_guess < 0x20) {
        packet_guess.chance_guess = (unsigned char)g_contextObject_guess->field0c_guess[
            g_contextObject_guess->field08_guess->field04_guess + packet_guess.index_guess + 8];
        packet_guess.chance_guess -= FUN_005ed550_guess() >> 2;
        if (packet_guess.chance_guess < 0) {
            packet_guess.chance_guess = 0;
        }
        if (g_ownerRecord_00905ce4_guess->field256_guess != 0) {
            packet_guess.chance_guess = 100;
            if (g_ownerRecord_00905ce4_guess->field256_guess != 0 &&
                g_value_00923d5c_guess != 0) {
                packet_guess.chance_guess = -1;
            }
        }
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1004, &packet_guess,
            strlen(packet_guess.text_guess) + 0x99, 1);
        bool found_guess = false;
        if (packet_guess.type_guess == 2 &&
            strcmp(packet_guess.text_guess, previous_guess) == 0) {
            found_guess = true;
        }
        FUN_0060e450_guess(previous_guess, packet_guess.text_guess);
        if (*g_prefix_00923898_guess != 0) {
            FUN_0060e450_guess(log_guess.prefix_guess, g_prefix_00923898_guess);
            FUN_0060e450_guess(log_guess.to_guess,
                &g_contextObject_guess->field44_guess[
                    g_contextObject_guess->field08_guess->field04_guess]);
            if (from_guess == 0) {
                log_guess.from_guess[0] = 0;
            } else {
                FUN_0060e450_guess(log_guess.from_guess,
                    reinterpret_cast<const char*>(from_guess));
            }
            FUN_0060e450_guess(log_guess.text_guess, packet_guess.text_guess);
            log_guess.type_guess = type_guess;
            int length_guess = strlen(packet_guess.text_guess) + 0xc9;
            if (!found_guess) {
                if (_stricmp(packet_guess.to_guess, g_prefix_00923898_guess) == 0 &&
                    _stricmp(packet_guess.from_guess, g_prefix_00923898_guess) == 0) {
                    return;
                }
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x33dc, &log_guess,
                    length_guess, 1);
            }
        }
        return;
    }
    __debugbreak();
}

// Command 0xF only targets the pet locally ('Targeting your pet.' 0x3330, or 0x3323 with no pet);
// others go to the server as OP_PetCommands (0x10A1: command, target).
// FUNCTION: TITANIUM 0x0049975B
void GlobalState_guess::IssuePetCommand_guess(int param_guess, int value_guess) {
    if (param_guess == 0xf) {
        ListEntry_guess* entry_guess = 0;
        if (g_listHead_00905cc4_guess != 0) {
            unsigned int owner_guess = g_ownerRecord_00905ce4_guess->field258_guess;
            entry_guess = g_listHead_00905cc4_guess;
            while (entry_guess != 0 && entry_guess->key_guess != owner_guess) {
                entry_guess = entry_guess->next_guess;
            }
        }
        if (entry_guess == 0) {
            g_globalState_guess->DspChat_guess(g_stringTable_guess->Lookup_guess(0x3323, 0));
        } else {
            DspChat_guess(g_stringTable_guess->Lookup_guess(0x3330, 0));
            if (g_lastEntry_00905d04_guess != 0) {
                unsigned int last_guess = g_lastEntry_00905d04_guess->field258_guess;
                ChatRecord_guess* record_guess = FUN_004c94ae_guess();
                record_guess->fieldf0_guess = last_guess;
            }
            g_lastEntry_00905d04_guess = entry_guess;
        }
    } else if (param_guess != 0) {
        Message_guess message_guess;
        message_guess.field00_guess = param_guess;
        message_guess.field04_guess = value_guess;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x10a1, &message_guess, 8, 1);
    }
}

// Debug print: '<5-digit serial>:text' into the chat window.
// FUNCTION: TITANIUM 0x004999D8
int __cdecl printf_guess(const char* format_guess, ...) {
    char text_guess[0x800];
    char output_guess[0x800];
    va_list arguments_guess;
    va_start(arguments_guess, format_guess);
    _vsprintf(text_guess, format_guess, arguments_guess);
    unsigned int id_guess = g_value_009858dc_guess;
    g_value_009858dc_guess++;
    _sprintf(output_guess, "%05u:%s", id_guess, text_guess);
    if (pEverQuest != 0) {
        pEverQuest->dsp_chat(output_guess);
    }
    return 0;
}

// Classic spell particles for effect stage `mode` (0..2; StartCasting uses 0): up to 3 emitters, each
// placed by its type (0 both hands, 1 a point or a dag, 2 the actor's dag, 3-5 the floor under the
// target, or 10 above it when the emitter's x offset is negative).
// FUNCTION: TITANIUM 0x0049AB78
// @early-stop: budget, structural ndiff=716
SpellNode_guess* __cdecl DoParticleEffect_guess(int mode_guess, TransferRecordA_guess* records_guess,
    int objectValue_guess, TransferAction_guess* first_guess,
    TransferAction_guess* second_guess, int zero_guess, int value5_guess,
    int value6_guess, int value7_guess) {
    ActionPosition_guess* source_guess = (ActionPosition_guess*)value5_guess;
    DagTarget_guess* target_guess = (DagTarget_guess*)value6_guess;
    char name_guess[32];
    char text_guess[128];
    ActionPosition_guess position_guess;
    position_guess.x_guess = 0.0f;
    position_guess.y_guess = 0.0f;
    position_guess.z_guess = 0.0f;
    TransferAction_guess* actor_guess = 0;
    SpellNode_guess* result_guess = 0;
    int level_guess = 1;
    if (first_guess != 0 && first_guess->type_guess == 0) {
        level_guess = first_guess->level_guess;
    }
    for (int i_guess = 0; i_guess < 3; i_guess++) {
        int* nodeType_guess = &records_guess[mode_guess].nodeTypes_guess[i_guess];
        if (*nodeType_guess == -1) {
            continue;
        }
        // Low-level casters get fewer emitters: no third below 39, no second below 24,
        // no first below 10 in stage 1.
        if (level_guess < 39) {
            switch (i_guess) {
            case 0:
                if (level_guess < 10 && mode_guess == 1) {
                    continue;
                }
                break;
            case 1:
                if (level_guess < 24) {
                    continue;
                }
                break;
            case 2:
                continue;
            }
        }
        if (_stricmp(records_guess[mode_guess].attach_guess, "Source") == 0) {
            actor_guess = first_guess;
        } else if (_stricmp(records_guess[mode_guess].attach_guess, "Target") == 0) {
            actor_guess = second_guess;
        }
        if (actor_guess == 0) {
            actor_guess = first_guess;
            if (actor_guess == 0) {
                return 0;
            }
        }
        int dag_guess;
        switch (*nodeType_guess) {
        case 0:
            actor_guess->GetActorTag_guess(name_guess);
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 0, &position_guess, value7_guess);
            if (actor_guess->dags_guess->source_guess != 0 && result_guess != 0) {
                _sprintf(text_guess, "%sL_POINT_DAG", name_guess);
                dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                if (dag_guess == 0) {
                    _sprintf(text_guess, "%sSPELL_POINT_DAG", name_guess);
                    dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                    if (dag_guess == 0) {
                        dag_guess = actor_guess->dags_guess->source_guess->GetDefaultDag_guess(0);
                    }
                }
                if (dag_guess != 0) {
                    result_guess->StartFade_guess(dag_guess);
                }
            }
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 0, &position_guess, value7_guess);
            if (actor_guess->dags_guess->source_guess != 0 && result_guess != 0) {
                _sprintf(text_guess, "%sR_POINT_DAG", name_guess);
                dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                if (dag_guess == 0) {
                    _sprintf(text_guess, "%sSPELL_POINT_DAG", name_guess);
                    dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                    if (dag_guess == 0) {
                        dag_guess = actor_guess->dags_guess->source_guess->GetDefaultDag_guess(1);
                    }
                }
                if (dag_guess != 0) {
                    result_guess->StartFade_guess(dag_guess);
                }
            }
            break;
        case 1:
            if (source_guess != 0) {
                position_guess = *source_guess;
            } else {
                position_guess.z_guess = 0.0f;
                position_guess.y_guess = 0.0f;
                position_guess.x_guess = 0.0f;
            }
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 5, &position_guess, value7_guess);
            if (result_guess == 0) {
                break;
            }
            if (target_guess != 0 && target_guess->slots_guess != 0 &&
                target_guess->slots_guess->dag_guess != 0) {
                result_guess->StartFade_guess(target_guess->slots_guess->dag_guess);
                for (int k_guess = 0; k_guess < 3; k_guess++) {
                    if (target_guess->slots_guess->nodes_guess[k_guess] == 0) {
                        target_guess->slots_guess->nodes_guess[k_guess] = result_guess;
                    }
                }
            } else if (source_guess == 0 && actor_guess != 0) {
                actor_guess->GetActorTag_guess(name_guess);
                if (actor_guess->dags_guess->source_guess != 0) {
                    GetDagName_guess((DagOwner_guess*)actor_guess, name_guess, text_guess,
                        records_guess[mode_guess].dagTypes_guess[i_guess]);
                    dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                    if (dag_guess == 0) {
                        dag_guess = actor_guess->dags_guess->source_guess->GetDefaultDag_guess(0);
                    }
                    if (dag_guess != 0) {
                        result_guess->StartFade_guess(dag_guess);
                    } else {
                        printf_guess("***DAG Error DAG = %08x", dag_guess);
                    }
                }
            }
            break;
        case 2:
            if (source_guess != 0) {
                position_guess = *source_guess;
            } else if (target_guess != 0) {
                position_guess = target_guess->position_guess;
            } else if (actor_guess != 0) {
                position_guess = actor_guess->position_guess;
            } else {
                position_guess.z_guess = 0.0f;
                position_guess.y_guess = 0.0f;
                position_guess.x_guess = 0.0f;
            }
            actor_guess->GetActorTag_guess(name_guess);
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 1, &position_guess, value7_guess);
            if (actor_guess->dags_guess->source_guess != 0) {
                GetDagName_guess((DagOwner_guess*)actor_guess, name_guess, text_guess,
                    records_guess[mode_guess].dagTypes_guess[i_guess]);
                dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                if (dag_guess == 0) {
                    dag_guess = actor_guess->dags_guess->source_guess->GetDefaultDag_guess(0);
                }
                if (result_guess != 0 && dag_guess != 0 && source_guess == 0) {
                    result_guess->StartFade_guess(dag_guess);
                }
            }
            break;
        case 3:
            if (source_guess != 0) {
                position_guess = *source_guess;
            } else {
                if (target_guess != 0) {
                    position_guess = target_guess->position_guess;
                } else if (actor_guess != 0) {
                    position_guess = actor_guess->position_guess;
                } else {
                    break;
                }
                position_guess.z_guess = records_guess[mode_guess].offsets_guess[i_guess].x_guess < 0.0f
                    ? position_guess.z_guess + 10.0f
                    : g_worldServices_guess->GetFloorHeight_guess(position_guess.x_guess,
                        position_guess.y_guess, position_guess.z_guess);
            }
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 3, &position_guess, value7_guess);
            break;
        case 4:
            if (source_guess != 0) {
                position_guess = *source_guess;
            } else {
                if (target_guess != 0) {
                    position_guess = target_guess->position_guess;
                } else if (actor_guess != 0) {
                    position_guess = actor_guess->position_guess;
                } else {
                    break;
                }
                position_guess.z_guess = records_guess[mode_guess].offsets_guess[i_guess].x_guess < 0.0f
                    ? position_guess.z_guess + 10.0f
                    : g_worldServices_guess->GetFloorHeight_guess(position_guess.x_guess,
                        position_guess.y_guess, position_guess.z_guess);
            }
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 4, &position_guess, value7_guess);
            break;
        case 5:
            if (source_guess != 0) {
                position_guess = *source_guess;
            } else {
                if (target_guess != 0) {
                    position_guess = target_guess->position_guess;
                } else if (actor_guess != 0) {
                    position_guess = actor_guess->position_guess;
                } else {
                    break;
                }
                position_guess.z_guess = records_guess[mode_guess].offsets_guess[i_guess].x_guess < 0.0f
                    ? position_guess.z_guess + 10.0f
                    : g_worldServices_guess->GetFloorHeight_guess(position_guess.x_guess,
                        position_guess.y_guess, position_guess.z_guess);
            }
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 6, &position_guess, value7_guess);
            if (target_guess != 0) {
                break;
            }
            actor_guess->GetActorTag_guess(name_guess);
            result_guess = MakePCloudInstance_guess(records_guess, objectValue_guess, mode_guess,
                i_guess, 6, &position_guess, value7_guess);
            if (actor_guess->dags_guess->source_guess != 0) {
                GetDagName_guess((DagOwner_guess*)actor_guess, name_guess, text_guess,
                    records_guess[mode_guess].dagTypes_guess[i_guess]);
                dag_guess = actor_guess->dags_guess->source_guess->FindDag_guess(text_guess);
                if (dag_guess == 0) {
                    dag_guess = actor_guess->dags_guess->source_guess->GetDefaultDag_guess(0);
                }
                if (result_guess != 0 && dag_guess != 0 && source_guess == 0) {
                    result_guess->StartFade_guess(dag_guess);
                }
            }
            break;
        }
    }
    return result_guess;
}

// Shows spell effect stage `mode` (0..2): sets the cast animation (stages 0 and 2), then, unless
// CanShowSpellEffect filters it, plays the emitter set (+0x234, when particle density is on) or the
// old particle records (+0x22C). Returns 1 once the arguments are valid.
// FUNCTION: TITANIUM 0x0049B260
int __cdecl DoSpellEffect_guess(int mode_guess, TransferObject_guess* object_guess,
    TransferAction_guess* first_guess, TransferAction_guess* second_guess,
    int value5_guess, int value6_guess, int value7_guess) {
    if (first_guess == 0 || object_guess == 0 ||
        (object_guess->field22c_guess == 0 && object_guess->field234_guess == 0) ||
        mode_guess < 0 || mode_guess > 2) {
        return 0;
    }

    int selected_guess;
    if (object_guess->field234_guess != 0) {
        selected_guess = object_guess->field234_guess[mode_guess].field40_guess;
    } else {
        selected_guess = object_guess->field22c_guess[mode_guess].field224_guess;
    }

    if (mode_guess != 1 && selected_guess != -1) {
        TransferAction_guess* action_guess = first_guess;
        if (mode_guess == 2) {
            action_guess = second_guess;
        }
        if (action_guess != 0) {
            action_guess->PlaySound_guess(selected_guess);
        }
    }

    if (CanShowSpellEffect_guess(mode_guess, first_guess, second_guess) == 0) {
        if (object_guess->field234_guess != 0) {
            if (g_transferFloat_00985810_guess > 0.0f &&
            g_transferFloat_00985814_guess > 0.0f &&
            g_transferFlag_0092484c_guess != 0) {
                int objectValue_guess = object_guess->field00_guess;
                g_transferResult_00905c04_guess = SubmitEffectEmitters_guess(
                    objectValue_guess, mode_guess, object_guess->field234_guess,
                    first_guess, second_guess, value5_guess, value6_guess, value7_guess, 0);
            }
        } else if (g_transferFlag_0092484c_guess != 0 || mode_guess == 1 ||
            object_guess->FUN_0044ced9_guess() == 1) {
            DoParticleEffect_guess(mode_guess, object_guess->field22c_guess,
                object_guess->field00_guess, first_guess, second_guess, 0,
                value5_guess, value6_guess, value7_guess);
        }
    }
    return 1;
}

// Begin-cast notice: spell -1 is a ground effect `value` units in front of the caster. Otherwise starts
// the cast animation and prints the begin-casting line (0x2FAD self, 0x2FAE others, the song text for
// bards) when the spell-message options (7, 8, 9, 0x16) allow it.
// FUNCTION: TITANIUM 0x0049B39D
// @early-stop: budget, structural ndiff=245
void GlobalState_guess::StartCasting_guess(ActionRecord_guess* action_guess) {
    char message_guess[256];
    char detail_guess[256];
    EQPlayer* actor_guess = reinterpret_cast<EQPlayer*>(
        FUN_00401b28_guess(action_guess->actorId_guess));
    if (actor_guess == 0) {
        return;
    }

    if (action_guess->actionId_guess == -1) {
        float x_guess = actor_guess->Y;
        float y_guess;
        float distance_guess = (float)action_guess->value_guess;
        x_guess += g_displayAngle_guess->Cos_guess(actor_guess->Heading) * distance_guess;
        y_guess = actor_guess->X;
        y_guess += g_displayAngle_guess->Sin_guess(actor_guess->Heading) * distance_guess;
        float z_guess = g_worldServices_guess->GetFloorHeight_guess(
            x_guess, y_guess,
            actor_guess->Z) + 3.0f;
        unsigned char pass_guess = g_worldServices_guess->GetEnvironment_guess(
            x_guess, y_guess, z_guess, 0);
        if (pass_guess == 0 || pass_guess == 3 || pass_guess == 7) {
            return;
        }
        float hit_guess = g_worldServices_guess->FUN_0043d64b_guess(
            x_guess, y_guess, z_guess);
        if (hit_guess == EQ_GLOBAL(float, 0x00640EA0)) {
            return;
        }
        ActionPosition_guess position_guess;
        position_guess.x_guess = x_guess;
        position_guess.y_guess = y_guess;
        position_guess.z_guess = hit_guess;
        DoParticleEffect_guess(2, EQ_ARRAY(TransferRecordA_guess, 0x0087AD00), 0x3d,
            reinterpret_cast<TransferAction_guess*>(actor_guess), 0, 0,
            (int)&position_guess, 0, 500);
        g_worldServices_guess->PlaySoundAtLocation_guess(
            x_guess, y_guess, hit_guess, 99);
        return;
    }

    if (IsValidSpellIndex_guess((int)action_guess->actionId_guess) == 0) {
        return;
    }
    ActionObjectView_guess* actionObject_guess = g_actionManager_guess->GetSpell_guess(
        (int)action_guess->actionId_guess);
    if (actionObject_guess == 0) {
        return;
    }
    if (reinterpret_cast<TransferObject_guess*>(actionObject_guess)->FUN_0044ced9_guess() != 0) {
        ActorControlData_guess* control_guess = reinterpret_cast<ActorControlData_guess*>(
            actor_guess->pActorInfo);
        control_guess->fieldecc_guess = g_worldServices_guess->field148_guess + 1000;
        control_guess->fielded0_guess = 0x4e2;
        control_guess->fielded4_guess = (int)action_guess->actionId_guess;
        ActorActionMethods_guess* actorMethods_guess = reinterpret_cast<ActorActionMethods_guess*>(
            actor_guess);
        ActionUI_guess* actionUI_guess = actorMethods_guess->GetAnimation_guess();
        actionUI_guess->Apply_guess(actionObject_guess->field186_guess, 1, 0, 1.0f, 1);
        return;
    }

    g_displayFlag_0092446c_guess = 1;
    int offset_guess = reinterpret_cast<ActorActionMethods_guess*>(actor_guess)->GetAnimationLength_guess(
        actionObject_guess->field186_guess);
    g_displayFlag_0092446c_guess = 0;
    int total_guess = action_guess->value_guess + offset_guess;

    if (actor_guess->Class == 8) {
        if (actor_guess == g_displayPlayer_guess) {
            strcpy(message_guess, actionObject_guess->field214_guess);
        } else if (actionObject_guess->field218_guess[0] == '\0') {
            message_guess[0] = '\0';
        } else {
            const char* values_guess[2];
            values_guess[0] = trimName_guess(actor_guess->Name);
            values_guess[1] = actionObject_guess->field218_guess;
            FUN_00467441_guess(message_guess, pStringTable->getString(0x2faf, 0),
                values_guess, -1, 0);
        }
    } else {
        const char* text_guess;
        unsigned int textId_guess;
        if (actor_guess == g_displayPlayer_guess) {
            text_guess = actionObject_guess->field208_guess;
            textId_guess = 0x2fad;
        } else {
            text_guess = trimName_guess(actor_guess->Name);
            textId_guess = 0x2fae;
        }
        FUN_0046da4a_guess(message_guess, textId_guess, text_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }

    EQPlayer* localPlayer_guess = g_displayPlayer_guess;
    if (actor_guess == localPlayer_guess &&
        // The player's own cast over 100 ms records the spell and its end time; GMs also
        // see the cast time (0x2FB0).
        (unsigned int)action_guess->value_guess > 100 &&
        reinterpret_cast<ActorControlData_guess*>(localPlayer_guess->pActorInfo)->fieldd8_guess == 0 &&
        reinterpret_cast<ActorControlData_guess*>(localPlayer_guess->pActorInfo)->fieldf98_guess == -1 &&
        localPlayer_guess->Class != 8) {
        if (localPlayer_guess->GM != 0) {
            _itoa(action_guess->value_guess, EQ_ARRAY(char, 0x0099DB00), 10);
            FUN_0046da4a_guess(detail_guess, 0x2fb0, EQ_ARRAY(char, 0x0099DB00),
                0, 0, 0, 0, 0, 0, 0, 0);
            strcat(message_guess, detail_guess);
        }
        reinterpret_cast<ActorControlData_guess*>(localPlayer_guess->pActorInfo)->fieldf98_guess =
            (int)action_guess->actionId_guess;
        reinterpret_cast<ActorControlData_guess*>(localPlayer_guess->pActorInfo)->fieldd8_guess =
            (int)FUN_0046d655_guess() + action_guess->value_guess;
    }

    if (localPlayer_guess->GM != 0) {
        sprintf(message_guess, "%s (%s)", message_guess, actionObject_guess->field208_guess);
    } else if (actor_guess != localPlayer_guess &&
        actor_guess->Level <= localPlayer_guess->Level + 5 &&
        (reinterpret_cast<EQPCFlagData_guess*>(g_displayCharData_guess)->fieldc38c_guess[
            g_displayCharData_guess->vbtable_C284[1]] & 0x40) != 0 &&
        g_displayToggle_009859ec_guess != 0 &&
        (g_displayToggle_009859ec_guess->CanUseAbility_guess(g_displayCharData_guess, 8, 1) != 0 ||
            g_displayToggle_009859ec_guess->CanUseAbility_guess(g_displayCharData_guess, 0x17, 1) != 0)) {
        sprintf(message_guess, "%s <%s>", message_guess, actionObject_guess->field208_guess);
    }

    int chatWidth_guess = 0x120;
    if (actor_guess != localPlayer_guess && actor_guess->Type == 1 && actor_guess->MasterID != 0) {
        chatWidth_guess = 0x150;
    }
    bool showMessage_guess = false;
    if (actor_guess->Class == 8) {
        if (actor_guess == localPlayer_guess) {
            showMessage_guess = g_optionState_guess->FUN_0060ca90_guess(9) != 1;
            chatWidth_guess = 0x108;
        } else {
            int* slot_guess = g_displaySlots_guess;
            int* slotEnd_guess = EQ_ARRAY(int, 0x009043A4);
            bool found_guess = false;
            for (; slot_guess < slotEnd_guess; ++slot_guess) {
                if (*slot_guess == (int)actor_guess) {
                    found_guess = true;
                    break;
                }
            }
            if (found_guess) {
                int state_guess = g_optionState_guess->FUN_0060ca90_guess(9);
                showMessage_guess = state_guess == 2 ||
                    (state_guess != 2 && g_optionState_guess->FUN_0060ca90_guess(9) == 4);
            } else {
                showMessage_guess = g_optionState_guess->FUN_0060ca90_guess(9) == 2;
            }
        }
    } else if (actor_guess == localPlayer_guess) {
        showMessage_guess = FUN_0040da3b_guess((int)action_guess->actionId_guess) == 0;
        chatWidth_guess = 0x108;
    } else {
        int* slot_guess = g_displaySlots_guess;
        int* slotEnd_guess = EQ_ARRAY(int, 0x009043A4);
        bool found_guess = false;
        for (; slot_guess < slotEnd_guess; ++slot_guess) {
            if (*slot_guess == (int)actor_guess) {
                found_guess = true;
                break;
            }
        }
        if (found_guess) {
            int state_guess = g_optionState_guess->FUN_0060ca90_guess(7);
            showMessage_guess = state_guess == 2 ||
                (state_guess != 2 && g_optionState_guess->FUN_0060ca90_guess(7) == 4);
        } else if (actor_guess->Type == 0) {
            showMessage_guess = g_optionState_guess->FUN_0060ca90_guess(7) == 2;
        } else if (chatWidth_guess == 0x150) {
            showMessage_guess = g_optionState_guess->FUN_0060ca90_guess(0x16) == 0;
        } else {
            showMessage_guess = g_optionState_guess->FUN_0060ca90_guess(8) == 0;
        }
    }

    if (showMessage_guess) {
        DspChat_guess(message_guess, chatWidth_guess, true);
    }
    DoSpellEffect_guess(0, reinterpret_cast<TransferObject_guess*>(actionObject_guess),
        reinterpret_cast<TransferAction_guess*>(actor_guess),
        reinterpret_cast<TransferAction_guess*>(actor_guess), 0, 0, total_guess);
}

// eqstr id of a class name (the table GetClassDesc uses); LeftClickedOnPlayer needs the id itself.
// FUNCTION: TITANIUM 0x004920C6
int __stdcall GetClassDescStringId_guess(int id_guess) {
    switch (id_guess) {
    case 0x1: return 0x5de;
    case 0x2: return 0x5e2;
    case 0x3: return 0x5e6;
    case 0x4: return 0x5ee;
    case 0x5: return 0x5ea;
    case 0x6: return 0x5f2;
    case 0x7: return 0x5f6;
    case 0x8: return 0x5fa;
    case 0x9: return 0x5fe;
    case 0xa: return 0x602;
    case 0xb: return 0x606;
    case 0xc: return 0x60a;
    case 0xd: return 0x60e;
    case 0xe: return 0x612;
    case 0xf: return 0x616;
    case 0x10: return 0x169f;
    case 0x14: return 0x5cf;
    case 0x15: return 0x5d0;
    case 0x16: return 0x5d1;
    case 0x18: return 0x5d2;
    case 0x17: return 0x5d3;
    case 0x19: return 0x5d4;
    case 0x1a: return 0x5d5;
    case 0x1b: return 0x5d6;
    case 0x1c: return 0x5d7;
    case 0x1d: return 0x5d8;
    case 0x1e: return 0x5d9;
    case 0x1f: return 0x5da;
    case 0x20: return 0x5db;
    case 0x21: return 0x5dc;
    case 0x22: return 0x5dd;
    case 0x23: return 0x16a0;
    case 0x28: return 0x5ce;
    case 0x29: return 0x5cd;
    case 0x42: return 0x17de;
    default: return 0x998;
    }
}

#define g_digits_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* destination_guess, int radix_guess);

struct SendBuffer_guess {
    char name_guess[64]; // 0x00
    char source_guess[64]; // 0x40
    int field80_guess; // 0x80
    int field84_guess; // 0x84
    int field88_guess; // 0x88
};

// Sends OP_GuildWar (0xC81): the other guild, own name, own guild id and `value`; a leader (rank 2)
// also sees eqstr 0x2FF4 with the value.
// FUNCTION: TITANIUM 0x0049DB44
void __stdcall GuildWar(const char* name_guess, int value_guess) {
    SendBuffer_guess send_guess;
    char message_guess[256];
    strcpy(send_guess.name_guess, name_guess);
    strcpy(send_guess.source_guess,
        &g_contextObject_guess->field44_guess[g_contextObject_guess->field08_guess->field04_guess]);
    send_guess.field80_guess = g_contextObject_guess->field_e0c_guess;
    send_guess.field88_guess = 1;
    send_guess.field84_guess = value_guess;
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xc81, &send_guess, sizeof(send_guess), 1);
    if (value_guess != 0 && g_contextObject_guess->field_e10_guess == 2) {
        FUN_0046da4a_guess(message_guess, 0x2ff4, name_guess,
            _itoa(value_guess, g_digits_guess, 10), 0, 0, 0, 0, 0, 0, 0);
        g_globalState_guess->DspChat_guess(message_guess);
    }
}

// Stand states on the player: 'd' standing (100), 'n' sitting (110), 'o' ducking, 'f' feigning.
// Standing or ducking sits (not while feigning); anything else stands and closes the loot window.
// FUNCTION: TITANIUM 0x0049DCFA
void GlobalState_guess::ToggleSit_guess() {
    // Refused under spell effect 31 (probably mesmerize): 'You do not have control of yourself'.
    if (g_contextObject_guess->fieldc280_guess.TotalSpellAffects_guess(0x1f, 1, 0, 1) != 0) {
        DspChat_guess(g_stringTable_guess->Lookup_guess(0x3050, 0));
        return;
    }

    unsigned int index_guess = g_contextObject_guess->field08_guess->field04_guess;
    char state_guess = g_contextObject_guess->field44_guess[index_guess + 0xc8];
    if (state_guess == 'd' || state_guess == 'o') {
        if (g_resetOwner_guess->standState_0251_guess != 'f') {
            g_resetOwner_guess->ChangePosition_guess(0x6e);
            if (pinstCTipWndCONTEXT_guess != 0) {
                pinstCTipWndCONTEXT_guess->selectTip_guess(0x16, 0);
            }
        }
    } else {
        g_resetOwner_guess->ChangePosition_guess(100);
        if (pinstCLootWnd_guess->IsVisible_guess() != 0) {
            pinstCLootWnd_guess->Deactivate();
        }
    }
}

// /camp: a second /camp abandons it (0x3002). Sits first (0x3003 when that fails), refused on a
// vehicle (0x3004); sends OP_Camp (0x78C1) and starts the 30 s countdown (0x923994).
// FUNCTION: TITANIUM 0x0049DDA6
void GlobalState_guess::PrepareToCamp_guess() {
    if (g_resetOwner_guess->standState_0251_guess == 'f') {
        return;
    }
    if (g_value_00923994_guess != 0) {
        g_value_00923994_guess = 0;
        g_value_00905d28_guess = 0;
        DspChat_guess(pStringTable->getString(0x3002, 0));
        return;
    }
    if (g_contextObject_guess->fieldc280_guess.TotalSpellAffects_guess(0x1f, 1, 0, 1) != 0) {
        DspChat_guess(pStringTable->getString(0x3050, 0));
        return;
    }
    if (g_resetOwner_guess->standState_0251_guess != 'n') {
        ToggleSit_guess();
        if (g_resetOwner_guess->standState_0251_guess != 'n') {
            DspChat_guess(pStringTable->getString(0x3003, 0));
            return;
        }
    } else if (g_resetOwner_guess->pActorInfo_01a8_guess != 0 &&
        g_resetOwner_guess->pActorInfo_01a8_guess->field15c_guess != 0) {
        DspChat_guess(pStringTable->getString(0x3004, 0));
        return;
    }
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x78c1, &g_value_00905d28_guess, 4, 1);
    g_value_00923998_guess = FUN_0046d655_guess();
    g_value_00923994_guess = g_value_00923998_guess + 30000;
    g_value_009239b4_guess = g_resetOwner_guess->hpCurrent_0274_guess;
    g_flag_009239a0_guess = 1;
    g_globalState_guess->DspChat_guess(pStringTable->getString(0x3005, 0));
}

struct PromptPacket_guess {
    char message_guess[64];
    char source_guess[64];
    unsigned char type_guess;
};

struct PromptSelection_guess {
    char padding_0000_guess[0xF90];
    int fieldf90_guess;
};

struct ChatMessage_guess {
    unsigned char field00_guess;
    char padding_0001_guess[3];
    char text_guess[120];
};

struct PromptScratch_guess {
    const char* selectedText_guess;
    char formattedText_guess[64];
    char copiedText_guess[64];
    ChatMessage_guess message_guess;
    char primaryText_guess[64];
    char secondaryText_guess[64];
};

// EXTERNAL: TITANIUM 0x00467441 FUN_00467441_guess
void __cdecl FUN_00467441_guess(char* output_guess, const char* format_guess,
    const char** value_guess, int width_guess, int flags_guess);

struct SlotTarget_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
};

struct FindTail_guess {
    char padding_0000_guess[0x78];
    SlotTarget_guess* field78_guess; // 0x78, after the +4 of the result
};

struct ActorTarget_guess {
    char padding_0000_guess[0x120];
    char name_guess[0x40];
    char padding_0160_guess[0x48];
    ResetState_guess* pActorInfo_01a8_guess; // 0x1A8
    char padding_01ac_guess[0x8C];
    float heightOffset_0238_guess; // 0x238
    char padding_023c_guess[8];
    unsigned char type_0244_guess; // 0x244
    char padding_0245_guess[9];
    unsigned char gender_024e_guess; // 0x24E
    char padding_024f_guess[3];
    char playerClass_0252_guess; // 0x252
    char padding_0253_guess[5];
    unsigned int spawnId_0258_guess; // 0x258
    char padding_025c_guess[4];
    int race_0260_guess; // 0x260
    char padding_0264_guess[0xC];
    int bodyType_0270_guess; // 0x270
    // EXTERNAL: TITANIUM 0x004793B5 ActorTarget_guess::FUN_004793b5_guess
    const char* FUN_004793b5_guess();
    // EXTERNAL: TITANIUM 0x00484E79 ActorTarget_guess::IDied_guess
    void IDied_guess(void* packet_guess);
};

struct InputOwner_guess {
    char padding_0000_guess[0x1E2];
    unsigned char field1e2_guess;
    // EXTERNAL: TITANIUM 0x004F1A03 InputOwner_guess::SelectCharacter_guess
    void SelectCharacter_guess(int index_guess, int enabled_guess);
};

#define g_inputOwner_00850b9c_guess EQ_GLOBAL(InputOwner_guess*, 0x00850B9C)
#define g_actorTarget_00905d04_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905D04)
#define g_selectedActor_00905ce4_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905CE4)
#define g_flag_009254ef_guess EQ_GLOBAL(unsigned char, 0x009254EF)

struct TargetInfoView_guess {
    char padding_0000_guess[0x88];
    unsigned int field88_guess;
};

struct TargetDisplayFlag_guess {
    char padding_0000_guess[0x11];
    unsigned char field11_guess;
};

#define g_targetDisplayFlag_00905d24_guess EQ_GLOBAL(TargetDisplayFlag_guess*, 0x00905D24)

#define g_target_00905ce0_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905CE0)

// Left click to trade. With the merchant window open, clicking that merchant runs 0x56A029 (item on
// the cursor) or 0x56A2B8. Class (+0x252) '(' banker, '?' and '@' tribute masters, 'B' guild banker
// can't take items (0x2139); '>' (LDoN treasure) is ignored; others need IsOkToTransact and range.
// FUNCTION: TITANIUM 0x0049DEB6
void __stdcall RequestTrade_guess(ActorTarget_guess* target_guess) {
    int pair_guess[2];
    char buffer_guess[512];
    if ((target_guess->type_0244_guess == 0 || target_guess->type_0244_guess == 1) &&
        target_guess->pActorInfo_01a8_guess != 0 &&
        target_guess->pActorInfo_01a8_guess->field160_guess == 0) {
        if (pinstCTradeWnd_guess->active_guess != 0) {
            if (g_target_00905ce0_guess != 0 && target_guess == g_target_00905ce0_guess) {
                ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
                    &g_contextObject_guess->field0c_guess[
                        g_contextObject_guess->field08_guess->field04_guess - 4]);
                int* result_guess = selector_guess->finder_guess.GetCharInfo2();
                result_guess += 4;
                if (reinterpret_cast<FindTail_guess*>(result_guess)->field78_guess != 0) {
                    pinstCTradeWnd_guess->DropItemIntoTrade_guess();
                } else {
                    pinstCTradeWnd_guess->DropMoneyIntoTrade_guess();
                }
            }
        } else {
            if (g_sourceRecord_00905ce4_guess->field258_guess != target_guess->spawnId_0258_guess) {
                char code_guess = target_guess->playerClass_0252_guess;
                char* text_guess;
                if (code_guess == '(' || code_guess == '?' || code_guess == '@' || code_guess == 'B') {
                    text_guess = g_stringTable_guess->Lookup_guess(0x2139, 0);
                } else {
                    if (code_guess == '>') {
                        return;
                    }
                    if (!IsOkToTransact_guess()) {
                        return;
                    }
                    float fVar1_guess = target_guess->heightOffset_0238_guess;
                    if (g_ownedDisplay_guess->PlayerDistance_guess(target_guess,
                        (int)g_sourceRecord_00905ce4_guess, 1.0f) > fVar1_guess + 20.0f) {
                        FUN_0046da4a_guess(buffer_guess, 0x3006, target_guess->FUN_004793b5_guess(),
                            0, 0, 0, 0, 0, 0, 0, 0);
                        text_guess = buffer_guess;
                    } else {
                        if (target_guess->type_0244_guess == 0) {
                            ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
                                &g_contextObject_guess->field0c_guess[
                                    g_contextObject_guess->field08_guess->field04_guess - 4]);
                            int* result_guess = selector_guess->finder_guess.GetCharInfo2();
                            result_guess += 4;
                            if (reinterpret_cast<FindTail_guess*>(result_guess)->field78_guess != 0) {
                                ContextSelector_guess* selector2_guess = reinterpret_cast<ContextSelector_guess*>(
                                    &g_contextObject_guess->field0c_guess[
                                        g_contextObject_guess->field08_guess->field04_guess - 4]);
                                int* result2_guess = selector2_guess->finder_guess.GetCharInfo2();
                                result2_guess += 4;
                                if (!reinterpret_cast<FindTail_guess*>(result2_guess)->field78_guess->Slot04_guess(1)) {
                                    return;
                                }
                            }
                        }
                        pair_guess[0] = target_guess->spawnId_0258_guess;
                        pair_guess[1] = g_sourceRecord_00905ce4_guess->field258_guess;
                        // OP_TradeRequest {target id, own id}.
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x372f, pair_guess, 8, 1);
                        return;
                    }
                }
                g_globalState_guess->DspChat_guess(text_guess);
            }
        }
    }
}

// Incoming group invite: shows '%1 invites you to join a group.' and the FOLLOW/DISBAND hint and
// remembers the inviter. A busy player auto-declines with OP_GroupCancelInvite (0x1F27) and a reason:
// 1 already invited, 2 grouped, 4/5 states of 0x91D708.
// FUNCTION: TITANIUM 0x0049D654
void GlobalState_guess::HandleGroupInvite_guess(int action_guess,
    const char* source_guess) {
    char formatted_guess[120];
    PromptPacket_guess packet_guess;
    const char* adjustedSource_guess = source_guess + 0x40;

    FUN_0046da4a_guess(formatted_guess, 0x2ff8, adjustedSource_guess,
        0, 0, 0, 0, 0, 0, 0, 0);
    DspChat_guess(formatted_guess);

    if (g_promptShown_00985808_guess != 0 ||
        g_resetOwner_guess->IsGroupInvitePending_guess() != 0) {
        packet_guess.type_guess = 1;
    } else if (g_promptBlocked_009043a4_guess != 0) {
        packet_guess.type_guess = 2;
    } else if (g_promptState_0091d708_guess->IsInvitePending_guess() != 0) {
        packet_guess.type_guess = 4;
    } else if (g_promptState_0091d708_guess->IsInRaid_guess() != 0 &&
        (g_promptState_0091d708_guess->IsMember_guess(adjustedSource_guess) == 0 ||
        g_promptState_0091d708_guess->IsPlayerGroupLeader_guess() != 0)) {
        packet_guess.type_guess = 5;
    } else {
        DspChat_guess(g_stringTable_guess->Lookup_guess(0x2ff9, 0));
        g_promptShown_00985808_guess = 1;
        g_resetOwner_guess->SetGroupInvitePending_guess(1);
        FUN_0060e450_guess(g_promptOutput_00985845_guess, adjustedSource_guess);
        // Only an OP_GroupInvite invite is accepted with OP_GroupFollow; OP_GroupInvite2 ones use 0x42C9.
        if (action_guess == 0x1b48) {
            g_promptAccepted_00985844_guess = 1;
        }
        return;
    }

    FUN_0060e450_guess(packet_guess.message_guess, adjustedSource_guess);
    FUN_0060e450_guess(packet_guess.source_guess,
        g_resetOwner_guess->name_0120_guess);
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1f27, &packet_guess,
        0x81, 1);
}

struct PromptSendA_guess {
    char name_guess[64];
    char source_guess[64];
};


// EXTERNAL: TITANIUM 0x00468694 do_lfg_guess
void __cdecl do_lfg_guess(int enabled_guess, const char* text_guess);

// /follow: joins the inviter's group (leader name into 0x9043A4) with OP_GroupFollow (0x7BC7), or
// opcode 0x42C9 (not in patch_Titanium.conf) after an OP_GroupInvite2 invite.
// FUNCTION: TITANIUM 0x0049D7B6
void GlobalState_guess::AcceptGroupInvite_guess() {
    char formatted_guess[120];
    PromptSendA_guess send_guess;

    FUN_0046da4a_guess(formatted_guess, 0x2ffb, g_promptOutput_00985845_guess,
        0, 0, 0, 0, 0, 0, 0, 0);
    DspChat_guess(formatted_guess);
    g_resetOwner_guess->SetGroupInvitePending_guess(0);
    g_promptShown_00985808_guess = 0;
    FUN_0060e450_guess(EQ_ARRAY(char, 0x009043A4), g_promptOutput_00985845_guess);
    FUN_0060e450_guess(send_guess.name_guess, g_promptOutput_00985845_guess);
    FUN_0060e450_guess(send_guess.source_guess, g_resetOwner_guess->name_0120_guess);
    if (g_promptAccepted_00985844_guess != 0) {
        g_promptAccepted_00985844_guess = 0;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7bc7, &send_guess, 0x80, 1);
    } else {
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x42c9, &send_guess, 0x80, 1);
    }
    if (pinstCGroupSearchWnd_guess != 0) {
        pinstCGroupSearchWnd_guess->RemoveInfoOnGroupChange_guess();
    } else {
        do_lfg_guess(reinterpret_cast<int>(g_resetOwner_guess),
            g_stringTable_guess->Lookup_guess(0x3292, 0));
    }
    g_promptOutput_00985845_guess[0] = 0;
    EQ_GLOBAL(unsigned char, 0x00985885) = 0;
}

// /disband: the leader removes the selected member (+0xF90) or disbands; a member leaves
// (OP_GroupDisband 0xE76, {name, name}); with an invite pending it declines it instead (0x1F27, reason 3).
// FUNCTION: TITANIUM 0x0049D8BD
void GlobalState_guess::Disband_guess() {
    PromptScratch_guess scratch_guess;

    if (g_promptState_0091d708_guess->IsInRaid_guess() != 0 &&
        g_promptState_0091d708_guess->IsLocked_guess() != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x22a5, 0), 0xd, 1);
        return;
    }

    if (_stricmp(EQ_ARRAY(char, 0x009043A4),
        g_contextObject_guess->field44_guess +
        g_contextObject_guess->field08_guess->field04_guess) == 0) {
        PromptSelection_guess** selectionSlot_guess =
            reinterpret_cast<PromptSelection_guess**>(
                &g_resetOwner_guess->pActorInfo_01a8_guess);
        if ((*selectionSlot_guess)->fieldf90_guess >= 0 &&
            EQ_ARRAY(char, 0x0090424D)[(*selectionSlot_guess)->fieldf90_guess * 0x40] != 0) {
            FUN_0060e450_guess(scratch_guess.primaryText_guess, EQ_ARRAY(char, 0x0090424D) +
                reinterpret_cast<PromptSelection_guess*>(
                    g_resetOwner_guess->pActorInfo_01a8_guess)->fieldf90_guess * 0x40);
            FUN_0060e450_guess(scratch_guess.secondaryText_guess, EQ_ARRAY(char, 0x0090424D) +
                reinterpret_cast<PromptSelection_guess*>(
                    g_resetOwner_guess->pActorInfo_01a8_guess)->fieldf90_guess * 0x40);
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xe76,
                scratch_guess.primaryText_guess, 0x80, 1);
            scratch_guess.selectedText_guess = EQ_ARRAY(char, 0x0090424D) +
                reinterpret_cast<PromptSelection_guess*>(
                    g_resetOwner_guess->pActorInfo_01a8_guess)->fieldf90_guess * 0x40;
            FUN_00467441_guess(scratch_guess.message_guess.text_guess,
                pStringTable->getString(0x2fff, 0), &scratch_guess.selectedText_guess, -1, 0);
            reinterpret_cast<CEverQuest*>(this)->dsp_chat(scratch_guess.message_guess.text_guess);
            reinterpret_cast<PromptSelection_guess*>(
                g_resetOwner_guess->pActorInfo_01a8_guess)->fieldf90_guess = -1;
            return;
        }
    } else if (g_promptShown_00985808_guess == 0 &&
        g_resetOwner_guess->IsGroupInvitePending_guess() == 0) {
        FUN_0060e450_guess(scratch_guess.primaryText_guess,
            g_contextObject_guess->field44_guess +
            g_contextObject_guess->field08_guess->field04_guess);
        FUN_0060e450_guess(scratch_guess.secondaryText_guess,
            g_contextObject_guess->field44_guess +
            g_contextObject_guess->field08_guess->field04_guess);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xe76,
            scratch_guess.primaryText_guess, 0x80, 1);
        return;
    } else {
        FUN_0046da4a_guess(scratch_guess.message_guess.text_guess, 0x3001,
            g_promptOutput_00985845_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        reinterpret_cast<CEverQuest*>(this)->dsp_chat(scratch_guess.message_guess.text_guess);
        scratch_guess.message_guess.field00_guess = 3;
        FUN_0060e450_guess(scratch_guess.formattedText_guess, g_promptOutput_00985845_guess);
        FUN_0060e450_guess(scratch_guess.copiedText_guess,
            g_contextObject_guess->field44_guess +
            g_contextObject_guess->field08_guess->field04_guess);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1f27,
            scratch_guess.formattedText_guess, 0x81, 1);
        g_resetOwner_guess->SetGroupInvitePending_guess(0);
        g_promptShown_00985808_guess = 0;
        g_promptOutput_00985845_guess[0] = 0;
        EQ_GLOBAL(unsigned char, 0x00985885) = 0;
        return;
    }

    FUN_0060e450_guess(scratch_guess.primaryText_guess,
        g_contextObject_guess->field44_guess +
        g_contextObject_guess->field08_guess->field04_guess);
    FUN_0060e450_guess(scratch_guess.secondaryText_guess,
        g_contextObject_guess->field44_guess +
        g_contextObject_guess->field08_guess->field04_guess);
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xe76,
        scratch_guess.primaryText_guess, 0x80, 1);
}

#define g_value_0099d3f8_guess EQ_GLOBAL(int, 0x0099D3F8)

#define g_value_00905ce4_guess EQ_GLOBAL(int, 0x00905CE4)
#define g_flag_0092384d_guess EQ_GLOBAL(unsigned char, 0x0092384D)
#define g_flag_0092419c_guess EQ_GLOBAL(unsigned char, 0x0092419C)
#define g_flag_00923788_guess EQ_GLOBAL(int, 0x00923788)
#define g_value_00905ca4_guess EQ_GLOBAL(int, 0x00905CA4)
#define g_flag_00924676_guess EQ_GLOBAL(unsigned char, 0x00924676)
#define g_flag_00924673_guess EQ_GLOBAL(unsigned char, 0x00924673)
#define g_value_009238f8_guess EQ_GLOBAL(int, 0x009238F8)

struct CharDataE0C_guess {
    char padding_0000_guess[0xE0C];
    int field_e0c_guess;
};
#define g_charDataE0C_guess EQ_GLOBAL(CharDataE0C_guess*, 0x00905D00)

struct CharDataTail_guess {
    char padding_0000_guess[0xE0C];
    int field_e0c_guess;
    unsigned char field_e10_guess;
};
#define g_charDataTail_guess EQ_GLOBAL(CharDataTail_guess*, 0x00905D00)

struct ChatMsg_guess {
    char first_guess[0x40];
    char second_guess[0x40];
    int field80_guess;
    unsigned int field84_guess;
};

struct ChatNames_guess {
    char first_guess[0x40];
    char second_guess[0x40];
};

struct EverQuestActionView_guess : CEverQuest {
    void GuildInvite_guess(char* name_guess, char* action_guess);
};

// /guildinvite: needs a guild (+0xE0C) and officer rank (+0xE10). No name, 'o' or 'l' means the
// target; 'o' (leaders only) invites as officer. Sends OP_GuildInvite (0x18B7, 0x88 bytes).
// FUNCTION: TITANIUM 0x0049BF15
// @early-stop: budget, structural ndiff=161
void EverQuestActionView_guess::GuildInvite_guess(char* name_guess, char* action_guess) {
    char message_guess[128];
    ChatMsg_guess packet_guess;
    EQPlayer* target_guess;

    if (g_charDataTail_guess->field_e0c_guess == -1) {
        dsp_chat(pStringTable->getString(0x2fd2, 0), 0x111, true);
        return;
    }
    if (g_charDataTail_guess->field_e10_guess == 0) {
        dsp_chat(pStringTable->getString(0x2fd3, 0), 0x111, true);
        return;
    }

    if (name_guess[0] == 0 ||
        (strlen(name_guess) == 1 && (name_guess[0] == 'o' || name_guess[0] == 'l'))) {
        target_guess = reinterpret_cast<EQPlayer*>(g_lastPlayer_00905d04_guess);
        if (target_guess == 0 || target_guess->Type != 0 || target_guess == g_displayPlayer_guess) {
            dsp_chat(pStringTable->getString(0x2fd8, 0), 0x111, true);
            return;
        }
        if (EQ_GLOBAL(int, 0x00900478) == 4 &&
            reinterpret_cast<PlayerActionView_guess*>(g_displayPlayer_guess)->NotOnSameDeity_guess(
                target_guess, 0) != 0) {
            dsp_chat(pStringTable->getString(0x2fd4, 0));
            return;
        }

        strcpy(packet_guess.second_guess, g_charData_guess->name_guess);
        strcpy(packet_guess.first_guess, target_guess->Name);
        packet_guess.field80_guess = g_charDataTail_guess->field_e0c_guess;
        packet_guess.field84_guess = 0;
        FUN_0046da4a_guess(message_guess, 0x2fd5, target_guess->Name,
            0, 0, 0, 0, 0, 0, 0, 0);
        if (name_guess[0] == 'o') {
            if (g_charDataTail_guess->field_e10_guess != 2) {
                dsp_chat(pStringTable->getString(0x2fd7, 0), 0x111, true);
                return;
            }
            name_guess = target_guess->Name;
            packet_guess.field84_guess = 1;
            FUN_0046da4a_guess(message_guess, 0x2fd6, name_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (_stricmp(g_charData_guess->name_guess, name_guess) == 0) {
            return;
        }
        strcpy(packet_guess.second_guess, g_charData_guess->name_guess);
        strcpy(packet_guess.first_guess, name_guess);
        packet_guess.field80_guess = g_charDataTail_guess->field_e0c_guess;
        packet_guess.field84_guess = 0;
        target_guess = reinterpret_cast<EQPlayer*>(
            GetSpawnByName_guess(reinterpret_cast<int>(packet_guess.first_guess)));
        if (target_guess == 0 ||
            (target_guess->Type != 0 && target_guess->GM == 0)) {
            dsp_chat(pStringTable->getString(0x2fd9, 0), 0x111, true);
            return;
        }
        FUN_0046da4a_guess(message_guess, 0x2fd5, name_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        if (action_guess[0] == 'o' && strlen(action_guess) == 1) {
            if (g_charDataTail_guess->field_e10_guess != 2) {
                dsp_chat(pStringTable->getString(0x2fd7, 0), 0x111, true);
                return;
            }
            packet_guess.field84_guess = 1;
            FUN_0046da4a_guess(message_guess, 0x2fd6, name_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        }
    }

    dsp_chat(message_guess, 0x111, true);
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x18b7,
        &packet_guess, 0x88, 1);
}

// /guildremove: removing yourself leaves the guild (not allowed for the leader, rank 2); officers can
// remove the target or a named member (OP_GuildRemove 0x179).
// FUNCTION: TITANIUM 0x0049C20E
void GlobalState_guess::GuildRemove_guess(const char* param_guess) {
    char line_guess[128];
    ChatMsg_guess msg_guess;
    if (g_charDataTail_guess->field_e0c_guess == -1) {
        DspChat_guess(pStringTable->getString(0x2fd2, 0), 0x111, 1);
        return;
    }
    if ((*param_guess == 0 && reinterpret_cast<int>(g_lastPlayer_00905d04_guess) == g_value_00905ce4_guess) ||
        strcmp(param_guess, g_charData_guess->name_guess) == 0) {
        if (g_charDataTail_guess->field_e10_guess == 2) {
            DspChat_guess(pStringTable->getString(0x2fdb, 0), 0x111, 1);
            return;
        }
        strcpy(msg_guess.second_guess, g_charData_guess->name_guess);
        strcpy(msg_guess.first_guess, g_charData_guess->name_guess);
        msg_guess.field80_guess = g_charDataTail_guess->field_e0c_guess;
        msg_guess.field84_guess = g_charDataTail_guess->field_e10_guess;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x179, &msg_guess, 0x88, 1);
        DspChat_guess(pStringTable->getString(0x2fdc, 0), 0x111, 1);
        return;
    }
    if (g_charDataTail_guess->field_e10_guess < 1) {
        DspChat_guess(pStringTable->getString(0x2fdd, 0), 0x111, 1);
        return;
    }
    if (*param_guess == 0) {
        if (g_lastPlayer_00905d04_guess == 0 || g_lastPlayer_00905d04_guess->flag244_guess != 0) {
            DspChat_guess(pStringTable->getString(0x2fdf, 0), 0x111, 1);
            return;
        }
        strcpy(msg_guess.second_guess, g_charData_guess->name_guess);
        strcpy(msg_guess.first_guess, g_lastPlayer_00905d04_guess->name_guess);
        msg_guess.field80_guess = g_charDataTail_guess->field_e0c_guess;
        msg_guess.field84_guess = g_charDataTail_guess->field_e10_guess;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x179, &msg_guess, 0x88, 1);
        FUN_0046da4a_guess(line_guess, 0x2fde, g_lastPlayer_00905d04_guess->name_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(line_guess, 0x111, 1);
        return;
    }
    strcpy(msg_guess.second_guess, g_charData_guess->name_guess);
    strcpy(msg_guess.first_guess, param_guess);
    msg_guess.field80_guess = g_charDataTail_guess->field_e0c_guess;
    msg_guess.field84_guess = g_charDataTail_guess->field_e10_guess;
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x179, &msg_guess, 0x88, 1);
    FUN_0046da4a_guess(line_guess, 0x2fde, param_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    DspChat_guess(line_guess, 0x111, 1);
}

// /guildleader: the leader (rank 2) hands leadership to the target or a named player (OP_GuildLeader
// 0x12B1).
// FUNCTION: TITANIUM 0x0049C618
void GlobalState_guess::GuildLeader_guess(const char* param_guess) {
    char line_guess[0x100];
    char text_guess[0x100];
    ChatNames_guess names_guess;
    CopyBounded_guess(text_guess, param_guess, 0x100);
    if (g_charDataTail_guess->field_e0c_guess == -1) {
        DspChat_guess(pStringTable->getString(0x2fd2, 0), 0x111, 1);
        return;
    }
    if (g_charDataTail_guess->field_e10_guess != 2) {
        DspChat_guess(pStringTable->getString(0x2fe5, 0), 0x111, 1);
        return;
    }
    if (text_guess[0] == 0 && g_lastPlayer_00905d04_guess != 0) {
        strcpy(text_guess, g_lastPlayer_00905d04_guess->name_guess);
    }
    FUN_0046da4a_guess(line_guess, 0x2fe6, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    g_globalState_guess->DspChat_guess(line_guess, 0x111, 1);
    strcpy(names_guess.second_guess, text_guess);
    strcpy(names_guess.first_guess,
        g_contextObject_guess->field44_guess +
        g_contextObject_guess->field08_guess->field04_guess);
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x12b1, &names_guess, 0x80, 1);
}

// /guildsay: needs a guild (+0xE0C != -1); echoes the line (0x2FE7) and sends it on channel 0.
// FUNCTION: TITANIUM 0x0049C74E
void GlobalState_guess::GuildSay_guess(int param_guess) {
    char buffer_guess[1024];
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0 &&
        g_flag_0092384d_guess == 0) {
        if (g_charDataE0C_guess->field_e0c_guess == -1) {
            DspChat_guess(pStringTable->getString(0x2fd2, 0), 0x136, 1);
        } else {
            FUN_0046da4a_guess(buffer_guess, 0x2fe7, (const char*)param_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            DspChat_guess(buffer_guess, 0x136, 1);
            SendNewText_guess(0, 0, param_guess, 0);
        }
    }
}

// EXTERNAL: TITANIUM 0x00574950 TextMatch_guess
int __cdecl TextMatch_guess(const char* text_guess, const char* value_guess);
// EXTERNAL: TITANIUM 0x005744B0 TextMatchN_guess
int __cdecl TextMatchN_guess(const char* text_guess, const char* value_guess, int count_guess);

// EXTERNAL: TITANIUM 0x00574270 FUN_00574270_guess
int __cdecl FUN_00574270_guess(const char* text_guess);
// EXTERNAL: TITANIUM 0x00574700 FUN_00574700_guess
char* __cdecl FUN_00574700_guess(char* text_guess);

struct EmoteActor_guess {
    char padding_0000_guess[0x48];
    float field48_guess; // 0x48
    char padding_004c_guess[0x24E - 0x4C];
    unsigned char field24e_guess; // 0x24E
    char padding_024f_guess[2];
    char field251_guess; // 0x251
    char padding_0252_guess[6];
    unsigned short field258_guess; // 0x258
};

struct EmoteAnimator_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Play_guess(unsigned short anim_guess, int first_guess, int second_guess,
        float scale_guess, int enabled_guess);
};

#define g_emoteSelf_00905ce4_guess EQ_GLOBAL(EmoteActor_guess*, 0x00905CE4)
#define g_emoteTarget_00905d04_guess EQ_GLOBAL(EmoteActor_guess*, 0x00905D04)

// Built-in social `emote` (0..0x57). The third-person line (eqstr 0x30D4..0x3249, pronouns from +0x24E)
// goes to the server as OP_Emote with language -1, the animation as OP_Animation (0x2ACF) when standing
// still; then it is rebuilt with 'You' forms and shown locally. The target must be within 60 units.
// FUNCTION: TITANIUM 0x0049E0C1
void GlobalState_guess::send_social_guess(int emote_guess, const char* name_guess,
    const char* text_guess) {
    struct EmoteAnimPacket_guess {
        unsigned short id_guess;
        unsigned char type_guess;
        unsigned char anim_guess;
    };
    struct EmoteChatPacket_guess {
        int id_guess;
        char text_guess[1024];
    };
    EmoteChatPacket_guess packet_guess;
    char tHis_guess[64];
    char tSelf_guess[64];
    char tHim_guess[64];
    char him_guess[64];
    char all_guess[512];
    char his_guess[64];
    char self_guess[64];
    char own_guess[128];
    char who_guess[64];
    char you_guess[64];
    EmoteActor_guess* target_guess;
    int count_guess = FUN_00574270_guess(name_guess);
    int anim_guess = -1;

    all_guess[0] = 0;
    own_guess[0] = 0;
    who_guess[0] = 0;
    you_guess[0] = 0;
    his_guess[0] = 0;
    tHis_guess[0] = 0;
    him_guess[0] = 0;
    tHim_guess[0] = 0;
    self_guess[0] = 0;
    tSelf_guess[0] = 0;
    if (g_flag_0092384d_guess != 0) {
        return;
    }
    // The emote's target: a name in the argument, else the current target (0x3008 when the name is not
    // found). Emoting at yourself counts as no target.
    if (count_guess > 0 && TextMatch_guess(name_guess, pStringTable->getString(0x3007, 0)) != 0) {
        target_guess = (EmoteActor_guess*)FindPlayerByPartialDisplayName_guess(name_guess, 0);
        if (target_guess == 0) {
            DspChat_guess(pStringTable->getString(0x3008, 0));
            return;
        }
    } else {
        target_guess = g_emoteTarget_00905d04_guess;
    }
    if (target_guess == g_emoteSelf_00905ce4_guess) {
        target_guess = 0;
    }
    you_guess[0] = 0;
    // Pronouns by gender (+0x24E: 0 male, 1 female, else neuter) for us and, below, for the target, which
    // must be close enough (0x3021).
    switch (g_emoteSelf_00905ce4_guess->field24e_guess) {
    case 0:
        strcpy(his_guess, pStringTable->getString(0x2fb1, 0));
        strcpy(him_guess, pStringTable->getString(0x3009, 0));
        strcpy(self_guess, pStringTable->getString(0x300d, 0));
        break;
    case 1:
        strcpy(his_guess, pStringTable->getString(0x2fb2, 0));
        strcpy(him_guess, pStringTable->getString(0x300a, 0));
        strcpy(self_guess, pStringTable->getString(0x300b, 0));
        break;
    default:
        strcpy(his_guess, pStringTable->getString(0x2fb3, 0));
        strcpy(him_guess, pStringTable->getString(0x2fb3, 0));
        strcpy(self_guess, pStringTable->getString(0x300c, 0));
        break;
    }
    if (target_guess != 0) {
        if (g_ownedDisplay_guess->PlayerDistance_guess(g_emoteSelf_00905ce4_guess,
            (int)target_guess, 0.0f) > 60.0f) {
            DspChat_guess(pStringTable->getString(0x3021, 0));
            return;
        }
        strcpy(who_guess, reinterpret_cast<ActorTarget_guess*>(target_guess)->FUN_004793b5_guess());
        switch (target_guess->field24e_guess) {
        case 0:
            strcpy(tHis_guess, pStringTable->getString(0x2fb1, 0));
            strcpy(tHim_guess, pStringTable->getString(0x3009, 0));
            strcpy(tSelf_guess, pStringTable->getString(0x300d, 0));
            break;
        case 1:
            strcpy(tHis_guess, pStringTable->getString(0x2fb2, 0));
            strcpy(tHim_guess, pStringTable->getString(0x300a, 0));
            strcpy(tSelf_guess, pStringTable->getString(0x300b, 0));
            break;
        default:
            strcpy(tHis_guess, pStringTable->getString(0x2fb3, 0));
            strcpy(tHim_guess, pStringTable->getString(0x2fb3, 0));
            strcpy(tSelf_guess, pStringTable->getString(0x300c, 0));
            break;
        }
    }
    own_guess[0] = 0;
    all_guess[0] = 0;
    switch (emote_guess) {
    case 0x00:
        // Per emote (0x00-0x57): an animation plus two texts, the line without a target and the one naming
        // it.
        anim_guess = 0x4d;
        FUN_0046da4a_guess(own_guess, 0x30d4, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30d5, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x01:
        anim_guess = 0x1c;
        FUN_0046da4a_guess(own_guess, 0x30d6, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30d7, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x02:
        anim_guess = 0x3f;
        FUN_0046da4a_guess(own_guess, 0x30d8, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30d9, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x03:
        anim_guess = 0x1c;
        FUN_0046da4a_guess(own_guess, 0x30da, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30db, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x04:
        anim_guess = 0x36;
        FUN_0046da4a_guess(own_guess, 0x30dc, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30dd, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x05:
        FUN_0046da4a_guess(own_guess, 0x30de, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30df, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x06:
        FUN_0046da4a_guess(own_guess, 0x30e0, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30e1, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x07:
        anim_guess = 0x46;
        FUN_0046da4a_guess(own_guess, 0x30e2, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30e3, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x08:
        FUN_0046da4a_guess(own_guess, 0x30e4, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30e5, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x09:
        FUN_0046da4a_guess(own_guess, 0x30e6, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30e7, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0a:
        anim_guess = 0x30;
        FUN_0046da4a_guess(own_guess, 0x30e8, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30e9, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0b:
        FUN_0046da4a_guess(own_guess, 0x30ea, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30eb, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0c:
        anim_guess = 0x1d;
        FUN_0046da4a_guess(own_guess, 0x30ec, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30ed, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0d:
        anim_guess = 0x1b;
        FUN_0046da4a_guess(own_guess, 0x30ee, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30ef, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0e:
        anim_guess = 0x1e;
        FUN_0046da4a_guess(own_guess, 0x30f0, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x30f1, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0f:
        anim_guess = 0x30;
        FUN_0046da4a_guess(all_guess, 0x30f2, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30f3, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x10:
        anim_guess = 0x31;
        FUN_0046da4a_guess(all_guess, 0x30f4, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30f5, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x11:
        anim_guess = 0x32;
        FUN_0046da4a_guess(all_guess, 0x30f6, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30f7, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x12:
        anim_guess = 0x33;
        FUN_0046da4a_guess(all_guess, 0x30f8, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30f9, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x13:
        anim_guess = 0x32;
        FUN_0046da4a_guess(all_guess, 0x30fa, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30fb, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x14:
        FUN_0046da4a_guess(all_guess, 0x30fc, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30fd, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x15:
        anim_guess = 0x34;
        FUN_0046da4a_guess(all_guess, 0x30fe, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x30ff, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x16:
        anim_guess = 0x3b;
        FUN_0046da4a_guess(all_guess, 0x3100, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3101, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x17:
        anim_guess = 0x35;
        FUN_0046da4a_guess(all_guess, 0x3102, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3103, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x18:
        anim_guess = 0x31;
        FUN_0046da4a_guess(all_guess, 0x3104, you_guess, who_guess, (int)self_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3105, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x19:
        FUN_0046da4a_guess(all_guess, 0x3106, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3107, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1a:
        anim_guess = 0x1f;
        FUN_0046da4a_guess(all_guess, 0x3108, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3109, you_guess, his_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1b:
        anim_guess = 0x1d;
        FUN_0046da4a_guess(all_guess, 0x310a, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x310b, you_guess, his_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1c:
        anim_guess = 0x37;
        FUN_0046da4a_guess(all_guess, 0x310c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x310d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1d:
        anim_guess = 0x1d;
        FUN_0046da4a_guess(all_guess, 0x310e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x310f, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1e:
        anim_guess = 0x36;
        FUN_0046da4a_guess(all_guess, 0x3110, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3111, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1f:
        FUN_0046da4a_guess(all_guess, 0x3112, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3113, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x20:
        anim_guess = 0x33;
        FUN_0046da4a_guess(all_guess, 0x3114, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3115, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x21:
        FUN_0046da4a_guess(all_guess, 0x3116, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3117, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x22:
        anim_guess = 0x1b;
        FUN_0046da4a_guess(all_guess, 0x3118, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3119, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x23:
        anim_guess = 0x37;
        FUN_0046da4a_guess(all_guess, 0x311a, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x311b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x24:
        anim_guess = 0x38;
        FUN_0046da4a_guess(all_guess, 0x311c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x311d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x25:
        anim_guess = 0x39;
        FUN_0046da4a_guess(all_guess, 0x311e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x311f, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x26:
        anim_guess = 0x3a;
        FUN_0046da4a_guess(all_guess, 0x3120, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3121, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x27:
        anim_guess = 0x3d;
        FUN_0046da4a_guess(all_guess, 0x3122, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3123, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x28:
        anim_guess = 0x38;
        FUN_0046da4a_guess(all_guess, 0x3124, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3125, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x29:
        anim_guess = 0x3c;
        FUN_0046da4a_guess(all_guess, 0x3126, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3127, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2a:
        anim_guess = 0x31;
        FUN_0046da4a_guess(all_guess, 0x3128, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3129, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2b:
        anim_guess = 0x36;
        FUN_0046da4a_guess(all_guess, 0x312a, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x312b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2c:
        anim_guess = 0x3c;
        FUN_0046da4a_guess(all_guess, 0x312c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x312d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2d:
        FUN_0046da4a_guess(all_guess, 0x312e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x312f, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2e:
        anim_guess = 0x1c;
        FUN_0046da4a_guess(all_guess, 0x3130, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3131, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2f:
        anim_guess = 0x32;
        FUN_0046da4a_guess(all_guess, 0x3132, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3133, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x30:
        anim_guess = 0x1b;
        FUN_0046da4a_guess(all_guess, 0x3134, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3135, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x31:
        anim_guess = 0x34;
        FUN_0046da4a_guess(all_guess, 0x3136, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3137, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x32:
        anim_guess = 0x1d;
        FUN_0046da4a_guess(all_guess, 0x3138, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3139, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x33:
        FUN_0046da4a_guess(all_guess, 0x313a, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x313b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x34:
        anim_guess = 0x3e;
        FUN_0046da4a_guess(all_guess, 0x313c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x313d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x35:
        FUN_0046da4a_guess(all_guess, 0x313e, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x313f, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x36:
        FUN_0046da4a_guess(all_guess, 0x3140, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3141, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x37:
        FUN_0046da4a_guess(all_guess, 0x3142, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3143, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x38:
        anim_guess = 0x1c;
        FUN_0046da4a_guess(all_guess, 0x3144, you_guess, self_guess, (int)who_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3145, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x39:
        anim_guess = 0x3d;
        FUN_0046da4a_guess(all_guess, 0x3146, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3147, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3a:
        anim_guess = 0x40;
        FUN_0046da4a_guess(all_guess, 0x3148, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3149, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3b:
        anim_guess = 0x41;
        FUN_0046da4a_guess(all_guess, 0x314a, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x314b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3c:
        anim_guess = 0x39;
        FUN_0046da4a_guess(all_guess, 0x314c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x314d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3d:
        anim_guess = 0x42;
        FUN_0046da4a_guess(all_guess, 0x314e, you_guess, who_guess, (int)self_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x314f, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3e:
        anim_guess = 0x42;
        FUN_0046da4a_guess(all_guess, 0x3150, you_guess, who_guess, (int)tHis_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3151, you_guess, his_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3f:
        anim_guess = 0x1b;
        FUN_0046da4a_guess(all_guess, 0x3152, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3153, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x40:
        anim_guess = 0x43;
        FUN_0046da4a_guess(all_guess, 0x3154, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3155, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x41:
        anim_guess = 0x44;
        FUN_0046da4a_guess(all_guess, 0x3156, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3157, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x42:
        anim_guess = 0x41;
        FUN_0046da4a_guess(all_guess, 0x3158, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3159, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x43:
        anim_guess = 0x1c;
        FUN_0046da4a_guess(all_guess, 0x315a, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x315b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x44:
        FUN_0046da4a_guess(all_guess, 0x315c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x315d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x45:
        anim_guess = 0x3c;
        FUN_0046da4a_guess(all_guess, 0x315e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x315f, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x46:
        anim_guess = 0x36;
        FUN_0046da4a_guess(all_guess, 0x3160, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3161, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x47:
        anim_guess = 0x39;
        FUN_0046da4a_guess(all_guess, 0x3162, you_guess, who_guess, (int)tSelf_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3163, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x48:
        anim_guess = 0x45;
        FUN_0046da4a_guess(all_guess, 0x3164, you_guess, self_guess, (int)his_guess, (int)who_guess,
            0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3165, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x49:
        FUN_0046da4a_guess(all_guess, 0x3166, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3167, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4a:
        anim_guess = 0x46;
        FUN_0046da4a_guess(all_guess, 0x3168, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3169, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4b:
        FUN_0046da4a_guess(all_guess, 0x316a, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x316b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4c:
        anim_guess = 0x3b;
        FUN_0046da4a_guess(all_guess, 0x316c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x316d, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4d:
        anim_guess = 0x1d;
        FUN_0046da4a_guess(all_guess, 0x316e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x316f, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4e:
        FUN_0046da4a_guess(all_guess, 0x3170, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3171, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4f:
        anim_guess = 0x3d;
        FUN_0046da4a_guess(all_guess, 0x3172, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3173, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x50:
        anim_guess = 0x1f;
        FUN_0046da4a_guess(all_guess, 0x3174, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3175, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x51:
        FUN_0046da4a_guess(own_guess, 0x3176, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3177, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x52:
        FUN_0046da4a_guess(own_guess, 0x3178, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3179, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x53:
        FUN_0046da4a_guess(all_guess, 0x317a, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x54:
        FUN_0046da4a_guess(own_guess, 0x317b, you_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x57:
        FUN_0046da4a_guess(own_guess, 0x317c, you_guess, self_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x317d, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x55:
        FUN_0046da4a_guess(own_guess, 0x317e, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x317f, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x56:
        FUN_0046da4a_guess(own_guess, 0x3180, you_guess, him_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3181, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        break;
    default:
        return;
    }
    // No animation while moving or not standing. Free text after the command replaces the canned line; the
    // line goes out as OP_Emote (0x547A) and the animation as OP_Animation (0x2ACF, type 10).
    if (g_emoteSelf_00905ce4_guess->field48_guess != 0.0f ||
        g_emoteSelf_00905ce4_guess->field251_guess != 'd') {
        anim_guess = -1;
    }
    if (strlen(text_guess) > 1) {
        _sprintf(all_guess, "%s %s.", you_guess, text_guess);
    } else if (target_guess == 0 && own_guess[0] != 0) {
        _sprintf(all_guess, "%s %s", you_guess, own_guess);
    }
    if (all_guess[0] != 0) {
        char* last_guess = FUN_00574700_guess(&all_guess[strlen(all_guess) - 1]);
        if (FUN_00574800_guess(last_guess, 0) != 0 || isdigit((unsigned char)*last_guess)) {
            strcat(all_guess, ".");
        }
        DoPercentConvert_guess(all_guess, 1);
        packet_guess.id_guess = -1;
        strcpy(packet_guess.text_guess, all_guess);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x547a, &packet_guess, 0x404, 1);
    }
    if (anim_guess != -1) {
        EmoteAnimPacket_guess animPacket_guess;
        animPacket_guess.id_guess = g_emoteSelf_00905ce4_guess->field258_guess;
        animPacket_guess.type_guess = 10;
        animPacket_guess.anim_guess = (unsigned char)anim_guess;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x2acf, &animPacket_guess, 4, 1);
    }
    own_guess[0] = 0;
    all_guess[0] = 0;
    // Then the same emote again in the second person ("You ...", strings 0x319C on) for our own chat window,
    // with the animation played locally.
    strcpy(you_guess, pStringTable->getString(0x300e, 0));
    strcpy(his_guess, pStringTable->getString(0x300f, 0));
    strcpy(him_guess, pStringTable->getString(0x300f, 0));
    strcpy(self_guess, pStringTable->getString(0x3010, 0));
    switch (emote_guess) {
    case 0x00:
        FUN_0046da4a_guess(own_guess, 0x319c, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x319d, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x01:
        FUN_0046da4a_guess(own_guess, 0x319e, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x319f, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x02:
        FUN_0046da4a_guess(own_guess, 0x31a0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31a1, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x03:
        FUN_0046da4a_guess(own_guess, 0x31a2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31a3, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x04:
        FUN_0046da4a_guess(own_guess, 0x31a4, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31a5, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x05:
        FUN_0046da4a_guess(own_guess, 0x31a6, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31a7, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x06:
        FUN_0046da4a_guess(own_guess, 0x31a8, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31a9, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x07:
        FUN_0046da4a_guess(own_guess, 0x31aa, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31ab, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x08:
        FUN_0046da4a_guess(own_guess, 0x31ac, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31ad, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x09:
        FUN_0046da4a_guess(own_guess, 0x31ae, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31af, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0a:
        FUN_0046da4a_guess(own_guess, 0x31b0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31b1, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0b:
        FUN_0046da4a_guess(own_guess, 0x31b2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31b3, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0c:
        FUN_0046da4a_guess(own_guess, 0x31b4, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31b5, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0d:
        FUN_0046da4a_guess(own_guess, 0x31b6, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31b7, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0e:
        FUN_0046da4a_guess(own_guess, 0x31b8, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x31b9, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x0f:
        FUN_0046da4a_guess(all_guess, 0x31ba, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31bb, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x10:
        FUN_0046da4a_guess(all_guess, 0x31bc, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31bd, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x11:
        FUN_0046da4a_guess(all_guess, 0x31be, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31bf, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x12:
        FUN_0046da4a_guess(all_guess, 0x31c0, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31c1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x13:
        FUN_0046da4a_guess(all_guess, 0x31c2, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31c3, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x14:
        FUN_0046da4a_guess(all_guess, 0x31c4, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31c5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x15:
        FUN_0046da4a_guess(all_guess, 0x31c6, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31c7, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x16:
        FUN_0046da4a_guess(all_guess, 0x31c8, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31c9, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x17:
        FUN_0046da4a_guess(all_guess, 0x31ca, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31cb, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x18:
        FUN_0046da4a_guess(all_guess, 0x31cc, you_guess, who_guess, (int)self_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31cd, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x19:
        FUN_0046da4a_guess(all_guess, 0x31ce, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31cf, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1a:
        FUN_0046da4a_guess(all_guess, 0x31d0, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31d1, his_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1b:
        FUN_0046da4a_guess(all_guess, 0x31d2, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31d3, his_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1c:
        FUN_0046da4a_guess(all_guess, 0x31d4, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31d5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1d:
        FUN_0046da4a_guess(all_guess, 0x31d6, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31d7, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1e:
        FUN_0046da4a_guess(all_guess, 0x31d8, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31d9, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x1f:
        FUN_0046da4a_guess(all_guess, 0x31da, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31db, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x20:
        FUN_0046da4a_guess(all_guess, 0x31dc, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31dd, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x21:
        FUN_0046da4a_guess(all_guess, 0x31de, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31df, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x22:
        FUN_0046da4a_guess(all_guess, 0x31e0, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31e1, him_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x23:
        FUN_0046da4a_guess(all_guess, 0x31e2, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31e3, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x24:
        FUN_0046da4a_guess(all_guess, 0x31e4, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31e5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x25:
        FUN_0046da4a_guess(all_guess, 0x31e6, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31e7, him_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x26:
        FUN_0046da4a_guess(all_guess, 0x31e8, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31e9, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x27:
        FUN_0046da4a_guess(all_guess, 0x31ea, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31eb, him_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x28:
        FUN_0046da4a_guess(all_guess, 0x31ec, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31ed, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x29:
        FUN_0046da4a_guess(all_guess, 0x31ee, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31ef, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2a:
        FUN_0046da4a_guess(all_guess, 0x31f0, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31f1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2b:
        FUN_0046da4a_guess(all_guess, 0x31f2, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31f3, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2c:
        FUN_0046da4a_guess(all_guess, 0x31f4, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31f5, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2d:
        FUN_0046da4a_guess(all_guess, 0x31f6, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31f7, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2e:
        FUN_0046da4a_guess(all_guess, 0x31f8, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31f9, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x2f:
        FUN_0046da4a_guess(all_guess, 0x31fa, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31fb, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x30:
        FUN_0046da4a_guess(all_guess, 0x31fc, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31fd, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x31:
        FUN_0046da4a_guess(all_guess, 0x31fe, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x31ff, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x32:
        FUN_0046da4a_guess(all_guess, 0x3200, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3201, him_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x33:
        FUN_0046da4a_guess(all_guess, 0x3202, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3203, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x34:
        FUN_0046da4a_guess(all_guess, 0x3204, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3205, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x35:
        FUN_0046da4a_guess(all_guess, 0x3206, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3207, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x36:
        FUN_0046da4a_guess(all_guess, 0x3208, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3209, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x37:
        FUN_0046da4a_guess(all_guess, 0x320a, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x320b, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x38:
        FUN_0046da4a_guess(all_guess, 0x320c, you_guess, self_guess, (int)who_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x320d, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x39:
        FUN_0046da4a_guess(all_guess, 0x320e, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x320f, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3a:
        FUN_0046da4a_guess(all_guess, 0x3210, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3211, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3b:
        FUN_0046da4a_guess(all_guess, 0x3212, you_guess, who_guess, (int)tHim_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3213, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3c:
        FUN_0046da4a_guess(all_guess, 0x3214, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3215, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3d:
        FUN_0046da4a_guess(all_guess, 0x3216, you_guess, who_guess, (int)self_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3217, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3e:
        FUN_0046da4a_guess(all_guess, 0x3218, you_guess, who_guess, (int)tHis_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3219, his_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x3f:
        FUN_0046da4a_guess(all_guess, 0x321a, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x321b, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x40:
        FUN_0046da4a_guess(all_guess, 0x321c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x321d, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x41:
        FUN_0046da4a_guess(all_guess, 0x321e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x321f, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x42:
        FUN_0046da4a_guess(all_guess, 0x3220, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3221, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x43:
        FUN_0046da4a_guess(all_guess, 0x3222, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3223, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x44:
        FUN_0046da4a_guess(all_guess, 0x3224, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3225, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x45:
        FUN_0046da4a_guess(all_guess, 0x3226, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3227, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x46:
        FUN_0046da4a_guess(all_guess, 0x3228, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3229, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x47:
        FUN_0046da4a_guess(all_guess, 0x322a, you_guess, who_guess, (int)tSelf_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x322b, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x48:
        FUN_0046da4a_guess(all_guess, 0x322c, you_guess, self_guess, (int)his_guess, (int)who_guess,
            0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x322d, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x49:
        FUN_0046da4a_guess(all_guess, 0x322e, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x322f, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4a:
        FUN_0046da4a_guess(all_guess, 0x3230, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3231, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4b:
        FUN_0046da4a_guess(all_guess, 0x3232, you_guess, who_guess, (int)his_guess, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3233, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4c:
        FUN_0046da4a_guess(all_guess, 0x3234, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3235, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4d:
        FUN_0046da4a_guess(all_guess, 0x3236, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3237, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4e:
        FUN_0046da4a_guess(all_guess, 0x3238, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x3239, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x4f:
        FUN_0046da4a_guess(all_guess, 0x323a, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x323b, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x50:
        FUN_0046da4a_guess(all_guess, 0x323c, you_guess, who_guess, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(own_guess, 0x323d, self_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x51:
        FUN_0046da4a_guess(own_guess, 0x323e, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x323f, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x52:
        FUN_0046da4a_guess(own_guess, 0x3240, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3241, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x53:
        FUN_0046da4a_guess(all_guess, 0x3242, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x54:
        FUN_0046da4a_guess(own_guess, 0x3243, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x57:
        FUN_0046da4a_guess(own_guess, 0x3244, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3245, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x55:
        FUN_0046da4a_guess(own_guess, 0x3246, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3247, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    case 0x56:
        FUN_0046da4a_guess(own_guess, 0x3248, him_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_guess(all_guess, 0x3249, who_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        break;
    }
    if (strlen(text_guess) > 1) {
        FUN_0046da4a_guess(all_guess, 0x3011, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    } else if (target_guess == 0 && own_guess[0] != 0) {
        strcpy(all_guess, own_guess);
    }
    if (anim_guess != -1) {
        reinterpret_cast<EmoteAnimator_guess*>(
            reinterpret_cast<ActorActionMethods_guess*>(g_emoteSelf_00905ce4_guess)
                ->GetAnimation_guess())->Play_guess((unsigned char)anim_guess, 1, 0, 1.0f, 1);
    }
    if (all_guess[0] != 0) {
        char* last_guess = FUN_00574700_guess(&all_guess[strlen(all_guess) - 1]);
        if (FUN_00574800_guess(last_guess, 0) != 0 || isdigit((unsigned char)*last_guess)) {
            strcat(all_guess, ".");
        }
        all_guess[strlen(all_guess)] = 0;
        DspChat_guess(all_guess, 0x107, true);
    }
}

struct WhoGuildTable_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 WhoGuildTable_guess::GetName_guess
    char* GetName_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0040A79B WhoGuildTable_guess::FindGuildIdByNamePrefix_guess
    int FindGuildIdByNamePrefix_guess(char* name_guess);
};
#define g_whoGuilds_guess EQ_GLOBAL(WhoGuildTable_guess, 0x00905D38)

struct WhoActor_guess {
    char padding_0000_guess[0x106C];
    int trader_guess; // 0x106C
    int field1070_guess;
    int buyer_guess; // 0x1074
};

struct WhoFilter_guess {
    char name_guess[0x40];
    int race_guess; // 0x40
    int class_guess; // 0x44
    int levelLow_guess; // 0x48
    int levelHigh_guess; // 0x4C
    int gm_guess; // 0x50
    int guild_guess; // 0x54
    char padding_0058_guess[0x40];
};

typedef char WhoFriendName_guess[0x40];
#define g_whoFriends_guess EQ_ARRAY(WhoFriendName_guess, 0x0095A1B4)
#define g_whoSpawns_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)
#define g_whoPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)

// /who: up to 6 tokens build the filter (name, class, race, level range, GM, guild; guild -2 friends,
// -3 LFG, -4 trader, -5 buyer). 'all' asks the server; otherwise the known spawns are listed here, and
// eqstr 0xC2E (probably 'corpse') lists the player's corpses. Mode 1 is never set.
// FUNCTION: TITANIUM 0x0049C800
// @early-stop: budget, structural ndiff=258
void GlobalState_guess::Who_guess(char* args_guess) {
    char tokens_guess[6][0x80];
    int mode_guess = 0;
    int count_guess = 0;
    WhoFilter_guess filter_guess;
    char trader_guess[16];
    char afk_guess[16];
    char linkdead_guess[16];
    char gmText_guess[16];
    char lfg_guess[16];
    char guildText_guess[128];
    char line_guess[128];
    char number_guess[128];
    char zone_guess[128];
    char countText_guess[20];
    char list_guess[0x800];
    filter_guess.name_guess[0] = 0;
    filter_guess.gm_guess = -1;
    filter_guess.guild_guess = -1;
    filter_guess.levelHigh_guess = -1;
    filter_guess.levelLow_guess = -1;
    filter_guess.class_guess = -1;
    filter_guess.race_guess = -1;
    bool secondLevel_guess = false;
    bool firstLevel_guess = false;
    bool classFound_guess = false;
    bool raceFound_guess = false;
    int level1_guess = -1;
    int level2_guess = -1;
    for (int i = 0; i < 6; i++) {
        char* token_guess = tokens_guess[i];
        args_guess = GrabFirstWord_guess(args_guess, token_guess, 0x80);
        if (strlen(token_guess) < 1) {
            break;
        }
        if (TextMatch_guess(token_guess, pStringTable->getString(0xc2e, 0)) == 0) {
            mode_guess = 2;
        } else if (TextMatch_guess(token_guess, pStringTable->getString(0x3395, 0)) == 0 ||
            TextMatch_guess(token_guess, EQ_ARRAY(char, 0x00649B2C)) == 0) {
            mode_guess = 3;
        } else if (TextMatch_guess(token_guess, pStringTable->getString(0xc2f, 0)) == 0 ||
            TextMatch_guess(token_guess, EQ_ARRAY(char, 0x00649B28)) == 0) {
            filter_guess.gm_guess = 1;
        } else if (TextMatch_guess(token_guess, pStringTable->getString(0xc30, 0)) == 0) {
            filter_guess.gm_guess = 0;
        } else if (TextMatch_guess(token_guess, pStringTable->getString(0xc28, 0)) == 0 ||
            TextMatch_guess(token_guess, "friends") == 0) {
            filter_guess.guild_guess = -2;
        } else if (TextMatch_guess(token_guess, pStringTable->getString(0xc31, 0)) == 0) {
            filter_guess.guild_guess = -3;
        } else if (TextMatch_guess(token_guess, "Trader") == 0 && mode_guess != 3) {
            filter_guess.guild_guess = -4;
        } else if (TextMatch_guess(token_guess, "Buyer") == 0 && mode_guess != 3) {
            filter_guess.guild_guess = -5;
        } else if (TextMatchN_guess(token_guess, pStringTable->getString(0x3342, 0), 5) == 0 &&
            isdigit(token_guess[5])) {
            strcpy(number_guess, token_guess + 5);
            filter_guess.guild_guess = atoi(number_guess);
            strcpy(filter_guess.name_guess, g_whoGuilds_guess.GetName_guess(filter_guess.guild_guess));
        } else {
            if (TextMatch_guess(token_guess, pStringTable->getString(0x3342, 0)) == 0) {
                if (g_whoPlayer_guess->GuildID != -1) {
                    filter_guess.guild_guess = g_whoPlayer_guess->GuildID;
                    strcpy(filter_guess.name_guess,
                        g_whoGuilds_guess.GetName_guess(filter_guess.guild_guess));
                    continue;
                }
                DspChat_guess(pStringTable->getString(0x3030, 0), 0x111, 1);
            }
            if (!classFound_guess) {
                for (int c = 1; c < 0x24; c++) {
                    size_t length_guess = strlen(token_guess);
                    if (_strnicmp(mode_guess == 1 ? GetClassDesc(c) :
                        g_contextObject_guess->fieldc280_guess.GetClassName_guess(c),
                        token_guess, length_guess) == 0) {
                        classFound_guess = true;
                        filter_guess.class_guess = c;
                        break;
                    }
                }
                if (classFound_guess) {
                    continue;
                }
            }
            if (!raceFound_guess) {
                for (int r = 0; r < 0x1db; r++) {
                    size_t length_guess = strlen(token_guess);
                    if (_strnicmp(mode_guess == 1 ? (char*)GetRaceDesc(r) :
                        g_contextObject_guess->fieldc280_guess.RaceName_guess(r),
                        token_guess, length_guess) == 0) {
                        raceFound_guess = true;
                        filter_guess.race_guess = r;
                        break;
                    }
                }
                if (raceFound_guess) {
                    continue;
                }
            }
            if (FUN_00574830_guess(token_guess, 0) != 0) {
                if (!firstLevel_guess) {
                    firstLevel_guess = true;
                    level1_guess = atoi(token_guess);
                    continue;
                }
                if (!secondLevel_guess) {
                    secondLevel_guess = true;
                    level2_guess = atoi(token_guess);
                    continue;
                }
            }
            int guild_guess = g_whoGuilds_guess.FindGuildIdByNamePrefix_guess(token_guess);
            if (guild_guess != -1) {
                filter_guess.guild_guess = guild_guess;
            }
            strcpy(filter_guess.name_guess, token_guess);
        }
    }
    if (level1_guess > 0 || level2_guess > 0) {
        if (level1_guess < 1) {
            filter_guess.levelLow_guess = level2_guess;
            filter_guess.levelHigh_guess = level2_guess;
        } else {
            if (level2_guess < 1) {
                level2_guess = level1_guess;
            }
            if (level2_guess > level1_guess) {
                filter_guess.levelLow_guess = level1_guess;
                filter_guess.levelHigh_guess = level2_guess;
            } else {
                filter_guess.levelLow_guess = level2_guess;
                filter_guess.levelHigh_guess = level1_guess;
            }
        }
    }
    if (mode_guess == 3) {
        if (filter_guess.guild_guess == -2) {
            int names_guess = 0;
            list_guess[0] = 0;
            for (int f = 0; f < 100; f++) {
                char* friend_guess = g_whoFriends_guess[f];
                if (*friend_guess != 0 && strlen(friend_guess) < 0x10 &&
                    strlen(friend_guess) + strlen(list_guess) + 2 < 0x800) {
                    if (names_guess == 0) {
                        strcpy(list_guess, friend_guess);
                    } else {
                        strcat(list_guess, EQ_ARRAY(char, 0x0063F9EC));
                        strcat(list_guess, friend_guess);
                    }
                    names_guess++;
                }
            }
            if (names_guess > 0) {
                // OP_FriendsWho: the friends list joined into one string.
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x48fe, list_guess,
                    strlen(list_guess) + 1, 1);
                DspChat_guess(pStringTable->getString(0x3013, 0), 0x119, 1);
                DspChat_guess("---------------------------------", 0x119, 1);
            } else {
                DspChat_guess(pStringTable->getString(0x3014, 0), 0x119, 1);
            }
        } else {
            // OP_WhoAllRequest: the 0x98-byte filter.
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5cdd, &filter_guess, 0x98, 1);
        }
        return;
    }
    if (filter_guess.guild_guess == -3) {
        DspChat_guess(pStringTable->getString(0x3015, 0), 0x119, 1);
    } else {
        DspChat_guess(pStringTable->getString(0x3016, 0), 0x119, 1);
    }
    DspChat_guess("---------------------------", 0x119, 1);
    for (EQPlayer* p = g_whoSpawns_guess; p != 0; p = p->pNext) {
        bool show_guess = true;
        if (filter_guess.class_guess != -1 &&
            (p->Class != filter_guess.class_guess || p->Anon != 0)) {
            show_guess = false;
        }
        if (filter_guess.race_guess != -1 &&
            (p->Race != filter_guess.race_guess || p->Anon != 0)) {
            show_guess = false;
        }
        if (filter_guess.levelLow_guess != -1 &&
            (p->Level < filter_guess.levelLow_guess || p->Level > filter_guess.levelHigh_guess ||
            p->Anon != 0)) {
            show_guess = false;
        }
        if (filter_guess.gm_guess != -1 && (char)p->GM != filter_guess.gm_guess) {
            show_guess = false;
        }
        if (filter_guess.guild_guess == -3 && p->pActorInfo != 0 && p->LFG == 0) {
            show_guess = false;
        }
        if (filter_guess.guild_guess == -4 && p->pActorInfo != 0 &&
            ((WhoActor_guess*)p->pActorInfo)->trader_guess == 0) {
            show_guess = false;
        }
        if (filter_guess.guild_guess == -5 && p->pActorInfo != 0 &&
            ((WhoActor_guess*)p->pActorInfo)->buyer_guess == 0) {
            show_guess = false;
        }
        if (filter_guess.guild_guess > -1) {
            if (p->GuildID != filter_guess.guild_guess) {
                show_guess = false;
            }
        } else if (filter_guess.name_guess[0] != 0 &&
            _strnicmp(filter_guess.name_guess, p->Name, strlen(filter_guess.name_guess)) != 0) {
            show_guess = false;
        }
        if (p->GM != 0 && p->Anon != 0) {
            show_guess = false;
        }
        if (!show_guess) {
            continue;
        }
        if (p->GuildID != -1 && p->Anon != 1) {
            sprintf(guildText_guess, " <%s>", g_whoGuilds_guess.GetName_guess(p->GuildID));
        } else {
            guildText_guess[0] = 0;
        }
        if (p->AFK != 0) {
            strcpy(afk_guess, pStringTable->getString(0x3017, 0));
        } else {
            afk_guess[0] = 0;
        }
        if (p->GM != 0) {
            strcpy(gmText_guess, pStringTable->getString(0x3018, 0));
        } else {
            gmText_guess[0] = 0;
        }
        if (p->Linkdead != 0 && p->PvPFlag == 0) {
            strcpy(linkdead_guess, pStringTable->getString(0x3019, 0));
        } else {
            linkdead_guess[0] = 0;
        }
        if (p->LFG != 0) {
            strcpy(lfg_guess, pStringTable->getString(0x301a, 0));
        } else {
            lfg_guess[0] = 0;
        }
        trader_guess[0] = 0;
        if (((WhoActor_guess*)p->pActorInfo)->trader_guess == 1) {
            strcpy(trader_guess, pStringTable->getString(0x301b, 0));
        }
        if (((WhoActor_guess*)p->pActorInfo)->buyer_guess == 1) {
            strcpy(trader_guess, pStringTable->getString(0x17a8, 0));
        }
        if (mode_guess == 0) {
            if (p->Type != 0) {
                continue;
            }
            if (p->Anon != 0) {
                sprintf(line_guess, "%s%s%s%s[%s] %s %s%s", trader_guess, afk_guess,
                    linkdead_guess, gmText_guess, pStringTable->getString(0xc32, 0),
                    trimName_guess(p->Name), guildText_guess, lfg_guess);
            } else {
                unsigned char cls_guess = p->Class;
                int race_guess = p->Race;
                unsigned char level_guess = p->Level;
                sprintf(line_guess, "%s%s%s%s[%d %s] %s (%s)%s%s", trader_guess, afk_guess,
                    linkdead_guess, gmText_guess, level_guess,
                    g_contextObject_guess->fieldc280_guess.BuildLabel_guess(cls_guess,
                        level_guess, 0x18c),
                    trimName_guess(p->Name),
                    (char*)g_globalState_guess->GetRaceDesc(race_guess),
                    guildText_guess, lfg_guess);
            }
        } else {
            if (mode_guess == 1 && p->Type == 1) {
                continue;
            }
            if (mode_guess != 2 || p->Type < 2) {
                continue;
            }
            char* self_guess = g_contextObject_guess->field44_guess +
                g_contextObject_guess->field08_guess->field04_guess;
            if (_strnicmp(p->Name, self_guess, strlen(self_guess)) != 0) {
                continue;
            }
            unsigned char cls_guess = p->Class;
            int race_guess = p->Race;
            unsigned char level_guess = p->Level;
            sprintf(line_guess, "[%d %s] %s (%s)", level_guess,
                g_contextObject_guess->fieldc280_guess.BuildLabel_guess(cls_guess, level_guess,
                    0x18c),
                trimName_guess(p->Name),
                g_contextObject_guess->fieldc280_guess.RaceName_guess(race_guess));
        }
        DspChat_guess(line_guess, 0x119, 1);
        count_guess++;
    }
    g_lookupManager_guess->GetZoneName_guess(g_whoPlayer_guess->Zone, zone_guess, 1);
    if (count_guess > 1) {
        sprintf(countText_guess, "%d", count_guess);
        FUN_0046da4a_guess(line_guess, 0x301c, countText_guess, zone_guess, 0, 0, 0, 0, 0, 0, 0);
    } else {
        FUN_0046da4a_guess(line_guess, count_guess == 0 ? 0x301d : 0x301e, zone_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }
    DspChat_guess(line_guess, 0x119, 1);
}

#define g_zoneCharacterData_guess reinterpret_cast<ZoneCharacterData_guess*>(g_displayCharData_guess)
#define g_zonePlayerData_guess reinterpret_cast<ZonePlayerData_guess*>(g_displayPlayer_guess)
#define g_zoneDynamicRegion_guess (reinterpret_cast<ZoneDynamicRegion_guess*>( \
    reinterpret_cast<int>(g_displayCharData_guess) + \
    g_zoneCharacterData_guess->reference_guess->offset_guess))

// Sends OP_Save (0x736B): position, zone, bind and appearance with a checksum (0x4B6C04), only in
// game with nothing pending; `second` takes the live position, `first` echoes eqstr 0x3022. While a
// request is pending it sets 0x924673 to 0xB5 instead (probably a save still owed).
// FUNCTION: TITANIUM 0x004A1350
// @early-stop: budget, structural ndiff=62
void GlobalState_guess::SavePC_guess(int first_guess, int second_guess,
    unsigned char flags_guess) {
    char cleanedName_guess[64];
    ZoneSendPacket_guess packet_guess;
    ZoneSendData_guess data_guess;
    char text_guess[128];
    int zero_guess = 0;

    if (g_displayCharData_guess != 0 && g_displayPlayer_guess != 0 &&
        g_zonePlayerData_guess->state244_guess == 0 &&
        g_worldServices_guess != 0) {
        if (reinterpret_cast<ClockData_guess*>(g_worldServices_guess)->GetValue2cf8_guess() != 0 &&
            g_value_00905ca4_guess != 1 && g_sendDisabled_00923798_guess == 0 &&
            g_flag_00923884_guess == 0) {
            if (g_zoneDynamicRegion_guess->state104_guess < 4) {
                int* finderResult_guess = g_zoneDynamicRegion_guess->finder_guess.GetCharInfo2();
                if (reinterpret_cast<ZoneFinderState_guess*>(finderResult_guess)->state11b0_guess >= 1 &&
                    g_globalState_guess->state_guess == 5 && g_flag_00923788_guess != 0 &&
                    g_value_00923d24_guess != 0 && g_modeProvider_guess != 0 &&
                    g_modeProvider_guess->GetActiveChatWindow_guess() != 0) {
                    if (g_value_009248d4_guess == 0 && g_value_009248d0_guess == 0) {
                        FUN_004b07d8_guess();
                        if (g_flag_00924676_guess == 0) {
                            if (second_guess != 0 && g_zonePlayerData_guess->state244_guess == 0) {
                                g_zoneDynamicRegion_guess->x_guess = g_zonePlayerData_guess->x_guess;
                                g_zoneDynamicRegion_guess->y_guess = g_zonePlayerData_guess->y_guess;
                                g_zoneDynamicRegion_guess->z_guess = g_zonePlayerData_guess->z_guess;
                                g_zoneDynamicRegion_guess->heading_guess =
                                    g_zonePlayerData_guess->heading_guess;
                            }
                            if (strlen(g_zoneDynamicRegion_guess->text_guess) != 0) {
                                reinterpret_cast<NameCleaner_guess*>(this)->StripShipName_guess(
                                    g_zoneDynamicRegion_guess->text_guess, cleanedName_guess);
                                int candidate_guess = FindPlayerByPartialDisplayName_guess(
                                    reinterpret_cast<NameCleaner_guess*>(this)->StripShipName_guess(
                                        g_zoneDynamicRegion_guess->text_guess, cleanedName_guess), 0);
                                if (candidate_guess == 0) {
                                    g_zoneDynamicRegion_guess->textObject_guess.FUN_0040e25c_guess(
                                        g_text_0063f53f_guess);
                                } else {
                                    TransformPassengersToBoatSpace_guess(reinterpret_cast<void*>(candidate_guess));
                                    g_zoneDynamicRegion_guess->x_guess = g_zonePlayerData_guess->x_guess;
                                    g_zoneDynamicRegion_guess->y_guess = g_zonePlayerData_guess->y_guess;
                                    g_zoneDynamicRegion_guess->z_guess = g_zonePlayerData_guess->z_guess;
                                    g_zoneDynamicRegion_guess->heading_guess =
                                        g_zonePlayerData_guess->heading_guess;
                                    TransformPassengersToWorldSpace_guess(reinterpret_cast<void*>(candidate_guess));
                                }
                            }
                        }

                        g_zoneCharacterData_guess->SetFirst_guess(zero_guess);
                        g_zoneCharacterData_guess->SetSecond_guess(zero_guess);
                        int contextOffset_guess = 0x10;
                        int* context_guess = g_zoneDynamicRegion_guess->finder_guess.GetCharInfo2();
                        ZoneContextNames_guess* names_guess = reinterpret_cast<ZoneContextNames_guess*>(
                            context_guess + contextOffset_guess / 4);
                        if (names_guess->first_guess != 0) {
                            context_guess = g_zoneDynamicRegion_guess->finder_guess.GetCharInfo2();
                            names_guess = reinterpret_cast<ZoneContextNames_guess*>(
                                context_guess + contextOffset_guess / 4);
                            strcpy(text_guess, names_guess->first_guess->Get_guess());
                            strcpy(text_guess, text_guess + 2);
                            if (is_number_guess(text_guess) != 0) {
                                g_zoneCharacterData_guess->SetFirst_guess(atoi(text_guess));
                            }
                        }
                        context_guess = g_zoneDynamicRegion_guess->finder_guess.GetCharInfo2();
                        names_guess = reinterpret_cast<ZoneContextNames_guess*>(
                            context_guess + contextOffset_guess / 4);
                        if (names_guess->second_guess != 0) {
                            context_guess = g_zoneDynamicRegion_guess->finder_guess.GetCharInfo2();
                            names_guess = reinterpret_cast<ZoneContextNames_guess*>(
                                context_guess + contextOffset_guess / 4);
                            strncpy(text_guess, names_guess->second_guess->Get_guess(), 0xf);
                            strcpy(text_guess, text_guess + 2);
                            if (is_number_guess(text_guess) != 0) {
                                g_zoneCharacterData_guess->SetSecond_guess(atoi(text_guess));
                            }
                        }

                        if (g_displayPlayer_guess != 0) {
                            int index_guess = 0;
                            do {
                                int value_guess = reinterpret_cast<StatDisplay_guess*>(g_displayPlayer_guess)
                                    ->GetArmorType_guess(index_guess);
                                g_zoneCharacterData_guess->SetValue_guess(index_guess, value_guess);
                                g_zoneCharacterData_guess->SetChoice_guess(index_guess,
                                    g_zonePlayerData_guess->values_guess[index_guess]);
                                ++index_guess;
                            } while (index_guess < 9);
                        }

                        g_zoneDynamicRegion_guess->state130_guess = 0;
                        if (g_zonePlayerData_guess->state256_guess != 0 ||
                            g_zoneCharacterData_guess->statee25_guess != 0) {
                            g_zoneDynamicRegion_guess->state130_guess = 1;
                        }

                        memset(&packet_guess, 0, sizeof(packet_guess));
                        data_guess.x_guess = g_zoneDynamicRegion_guess->x_guess;
                        data_guess.y_guess = g_zoneDynamicRegion_guess->y_guess;
                        data_guess.z_guess = g_zoneDynamicRegion_guess->z_guess;
                        data_guess.heading_guess = (int)g_zoneDynamicRegion_guess->heading_guess;
                        data_guess.field98_guess = g_zoneCharacterData_guess->fielde20_guess;
                        data_guess.field9c_guess = g_zoneCharacterData_guess->GetFirst_guess();
                        data_guess.fielda0_guess = g_zoneCharacterData_guess->GetSecond_guess();
                        data_guess.fielda4_guess = g_zoneCharacterData_guess->fielde30_guess;
                        strcpy(data_guess.name_guess, g_zoneDynamicRegion_guess->text_guess);
                        for (int valueIndex_guess = 0; valueIndex_guess < 22; ++valueIndex_guess) {
                            data_guess.values_guess[valueIndex_guess] =
                                g_zoneCharacterData_guess->GetValue_guess(valueIndex_guess);
                        }
                        memcpy(packet_guess.payload_guess, &data_guess, sizeof(data_guess));
                        packet_guess.hash_guess = MemChecker0(packet_guess.payload_guess,
                            sizeof(data_guess));
                        packet_guess.flags_guess = flags_guess;
                        g_value_009238f8_guess = 1;
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x736b,
                            &packet_guess, sizeof(packet_guess), 1);
                        g_flag_00924673_guess = 0;
                        if (first_guess != 0) {
                            FUN_0046da4a_guess(text_guess, 0x3022,
                                g_zoneDynamicRegion_guess->label_guess,
                                0, 0, 0, 0, 0, 0, 0, 0);
                            DspChat_guess(text_guess);
                        }
                    } else {
                        g_flag_00924673_guess = 0xb5;
                    }
                }
            }
        }
    }
}

// /tell: 'Talking to yourself again?' (0x3023) for yourself, else channel 7.
// FUNCTION: TITANIUM 0x004A18F2
void GlobalState_guess::send_tell_guess(int first_guess, int second_guess) {
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0 &&
        g_flag_0092384d_guess == 0) {
        if (GetSpawnByName_guess(first_guess) == g_value_00905ce4_guess) {
            DspChat_guess(pStringTable->getString(0x3023, 0));
        } else {
            SendNewText_guess(7, first_guess, second_guess, 0);
        }
    }
}

// Ends hiding (0x9239DC, or hide skill 29 pending in 0x923CC4) with eqstr 0x3031, and sneaking (+0x1B1)
// with 0x3032.
// FUNCTION: TITANIUM 0x004A1CE4
void GlobalState_guess::CancelSneakHide() {
    if (g_flag_009239dc_guess != 0 || g_value_00923cc4_guess == 0x1d) {
        if (g_value_00923cc4_guess == 0x1d) {
            g_value_00923cc4_guess = -1;
        }
        g_flag_009239dc_guess = 0;
        g_contextObject_guess->FUN_005ed860_guess(0);
        g_contextObject_guess->fieldc280_guess.UpdateInvisibility_guess();
        g_globalState_guess->DspChat_guess(
            g_stringTable_guess->Lookup_guess(0x3031, 0));
    }
    if (g_resetOwner_guess->field1b1_guess != 0) {
        g_resetOwner_guess->field1b1_guess = 0;
        g_globalState_guess->DspChat_guess(
            g_stringTable_guess->Lookup_guess(0x3032, 0));
    }
}

struct Player1d74_guess;

struct Client1d74_guess {
    char padding_0000_guess[0xAD];
    unsigned char fieldad_guess; // 0xAD
    char padding_00ae_guess[0xC8 - 0xAE];
    float fieldc8_guess; // 0xC8
    char padding_00cc_guess[0x158 - 0xCC];
    Player1d74_guess* field158_guess; // 0x158
    Player1d74_guess* field15c_guess; // 0x15C
    int field160_guess; // 0x160
    char padding_0164_guess[0xEC4 - 0x164];
    float fieldec4_guess; // 0xEC4
    char padding_0ec8_guess[0xFE8 - 0xEC8];
    int fieldfe8_guess; // 0xFE8
};

// The block at player +0x30.
struct Motion1d74_guess {
    char padding_0000_guess[0x18];
    float field18_guess; // +0x48
    float field1c_guess; // +0x4C
    float field20_guess; // +0x50
    char padding_0024_guess[4];
    float field28_guess; // +0x58
    float field2c_guess; // +0x5C
};

struct Player1d74_guess {
    char padding_0000_guess[0x30];
    Motion1d74_guess motion_guess; // 0x30
    char padding_0060_guess[0x1A8 - 0x60];
    Client1d74_guess* client_guess; // 0x1A8
    char padding_01ac_guess[5];
    unsigned char field1b1_guess; // 0x1B1
    char padding_01b2_guess[0x230 - 0x1B2];
    float runSpeed_0230_guess; // 0x230
    char padding_0234_guess[4];
    float heightOffset_0238_guess; // 0x238
    char padding_023c_guess[0x251 - 0x23C];
    char standState_0251_guess; // 0x251
    char padding_0252_guess[6];
    int spawnId_0258_guess; // 0x258
    char padding_025c_guess[4];
    int race_0260_guess; // 0x260
    char padding_0264_guess[0x28C - 0x264];
    int levitate_028c_guess; // 0x28C
    // EXTERNAL: TITANIUM 0x0047C4FC Player1d74_guess::FollowPlayerAI_guess
    void FollowPlayerAI_guess();
    // EXTERNAL: TITANIUM 0x00479482 Player1d74_guess::TurnOffAutoFollow_guess
    void TurnOffAutoFollow_guess();
    // EXTERNAL: TITANIUM 0x0047BFD0 Player1d74_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x0048A2F4 Player1d74_guess::FUN_0048a2f4_guess
    char FUN_0048a2f4_guess();
    // EXTERNAL: TITANIUM 0x0047C2CD Player1d74_guess::GetWalkSpeed_guess
    float GetWalkSpeed_guess();
    // EXTERNAL: TITANIUM 0x0048A793 Player1d74_guess::FUN_0048a793_guess
    void FUN_0048a793_guess(bool flag_guess);
    // EXTERNAL: TITANIUM 0x0048297B Player1d74_guess::DoAttack
    void DoAttack(int id_guess, int zero_guess, Player1d74_guess* other_guess);
    // EXTERNAL: TITANIUM 0x0047A421 Player1d74_guess::FUN_0047a421_guess
    void FUN_0047a421_guess(float speed_guess, int flag_guess);
};

struct Effect1d74_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(float value_guess);
    virtual void Slot05_guess(float value_guess);
    virtual void Slot06_guess(float value_guess);
    virtual void Slot07_guess();
    virtual void SetValue_guess(float value_guess);
    virtual float GetValue_guess();
    virtual void Slot10_guess();
    virtual char IsActive_guess();
    char padding_0004_guess[0x14];
    float field18_guess; // 0x18
    float field1c_guess; // 0x1C
    char padding_0020_guess[0xC];
    float field2c_guess; // 0x2C
    float field30_guess; // 0x30
    float field34_guess; // 0x34
};

struct CharInfo1d74_guess {
    char padding_0000_guess[0x11AC];
    int field11ac_guess; // 0x11AC
};

struct CharVBase1d74_guess {
    char padding_0000_guess[4];
    EQ_CharacterProfile_guess profile_guess; // 0x04
    char padding_000c_guess[0xFC - 0xC];
    signed char fieldfc_guess; // 0xFC
};

struct CharHead1d74_guess {
    char padding_0000_guess[8];
};

struct Char1d74_guess : CharHead1d74_guess, virtual CharVBase1d74_guess {
    char padding_000c_guess[0xC280 - 0xC];
    ContextAction_guess fieldc280_guess; // 0xC280
};

struct Packet2c81_guess {
    int id_guess;
    char flag_guess;
};

#define g_char1d74_guess EQ_GLOBAL(Char1d74_guess*, 0x00905D00)
#define g_target1d74_guess EQ_GLOBAL(Player1d74_guess*, 0x00905CF8)
#define g_self1d74_guess EQ_GLOBAL(Player1d74_guess*, 0x00905CE4)
#define g_last1d74_guess EQ_GLOBAL(Player1d74_guess*, 0x00905D04)
#define g_clock1d74_guess EQ_GLOBAL(DisplayRoot_guess*, 0x00905D24)
#define g_effects1d74_guess EQ_ARRAY(Effect1d74_guess*, 0x009254FC)
#define g_selector1d74_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_paused_0095a174_guess EQ_GLOBAL(unsigned char, 0x0095A174)
#define g_flag1d74_009858c7_guess EQ_GLOBAL(unsigned char, 0x009858C7)
#define g_flag_00924670_guess EQ_GLOBAL(unsigned char, 0x00924670)
#define g_flag_00924671_guess EQ_GLOBAL(unsigned char, 0x00924671)
#define g_value_009257f0_guess EQ_GLOBAL(int, 0x009257F0)
#define g_value_009257ec_guess EQ_GLOBAL(int, 0x009257EC)
#define g_value_009257e4_guess EQ_GLOBAL(int, 0x009257E4)
#define g_value_009257e8_guess EQ_GLOBAL(int, 0x009257E8)
#define g_frameTime_00924858_guess EQ_GLOBAL(float, 0x00924858)
#define g_keys_00923860_guess EQ_GLOBAL(unsigned char, 0x00923860)
#define g_flag_00923d2d_guess EQ_GLOBAL(unsigned char, 0x00923D2D)
#define g_speed_00923d90_guess EQ_GLOBAL(float, 0x00923D90)
#define g_count_00923d50_guess EQ_GLOBAL(int, 0x00923D50)
#define g_count_00923d54_guess EQ_GLOBAL(int, 0x00923D54)
#define g_value_009239bc_guess EQ_GLOBAL(int, 0x009239BC)
#define g_value_00925538_guess EQ_GLOBAL(int, 0x00925538)
#define g_value_0092553c_guess EQ_GLOBAL(int, 0x0092553C)
#define g_value_00925524_guess EQ_GLOBAL(int, 0x00925524)
#define g_value_00924998_guess EQ_GLOBAL(int, 0x00924998)
#define g_value_00925564_guess EQ_GLOBAL(int, 0x00925564)
#define g_value_00925568_guess EQ_GLOBAL(int, 0x00925568)
#define g_value_00925570_guess EQ_GLOBAL(int, 0x00925570)
#define g_value_00925574_guess EQ_GLOBAL(int, 0x00925574)
#define g_time_00923854_guess EQ_GLOBAL(unsigned int, 0x00923854)
#define g_time_00923858_guess EQ_GLOBAL(unsigned int, 0x00923858)
#define g_flag_009254f7_guess EQ_GLOBAL(unsigned char, 0x009254F7)
#define g_value_009237b4_guess EQ_GLOBAL(unsigned char, 0x009237B4)
#define g_count_00923d40_guess EQ_GLOBAL(int, 0x00923D40)
#define g_count_00923d44_guess EQ_GLOBAL(int, 0x00923D44)
#define g_value_009858e0_guess EQ_GLOBAL(float, 0x009858E0)
#define g_value_009858e4_guess EQ_GLOBAL(float, 0x009858E4)
#define g_value_009858e8_guess EQ_GLOBAL(float, 0x009858E8)
#define g_flag_00923d79_guess EQ_GLOBAL(unsigned char, 0x00923D79)
#define g_value_009257f4_guess EQ_GLOBAL(int, 0x009257F4)
#define g_value_009257f8_guess EQ_GLOBAL(int, 0x009257F8)

// Per-frame movement of the player or the spawn it controls: walk/run/back/strafe/turn from the movement
// flags and key bits 0x923860, slowed for sneaking (+0x1B1), ducking ('o') and mounts; boats (race 0x8D)
// steer by their own speed. Sets 0x923D79 (self) or 0x923D78 (controlled) when a position update is due.
// FUNCTION: TITANIUM 0x004A1D74
// @early-stop: budget, structural ndiff=289
void GlobalState_guess::ProcessControls_guess() {
    float speed_guess = 0.0f;
    int active_guess = 1;
    if (g_char1d74_guess->fieldfc_guess > 0 || g_target1d74_guess->standState_0251_guess == 'f') {
        active_guess = 0;
    }
    if (g_paused_0095a174_guess != 0) {
        return;
    }
    if (g_sendDisabled_00923798_guess != 0 || g_flag_00923884_guess != 0) {
        active_guess = 1;
    }
    if (g_target1d74_guess != g_self1d74_guess && g_target1d74_guess->race_0260_guess == 0x8d &&
        g_self1d74_guess->client_guess->field158_guess != g_target1d74_guess) {
        Packet2c81_guess packet_guess;
        packet_guess.id_guess = g_target1d74_guess->spawnId_0258_guess;
        packet_guess.flag_guess = 0;
        // Lets go of a boat it no longer steers (OP_ControlBoat, flag 0).
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x2c81, &packet_guess,
            sizeof(packet_guess), 1);
        g_target1d74_guess->motion_guess.field18_guess = 0.0f;
        g_target1d74_guess->motion_guess.field28_guess = 0.0f;
        g_target1d74_guess = g_self1d74_guess;
    }
    if (g_target1d74_guess->standState_0251_guess != 'd' && g_target1d74_guess->standState_0251_guess != 'o') {
        active_guess = 0;
    }
    g_modeFlagE_guess = 0;
    Client1d74_guess* client_guess = g_target1d74_guess->client_guess;
    Motion1d74_guess* motion_guess = &g_target1d74_guess->motion_guess;
    if (active_guess != 0) {
        speed_guess = -20001.1f;
        motion_guess->field28_guess = 0.0f;
        if (g_target1d74_guess == g_self1d74_guess ||
            g_target1d74_guess == g_self1d74_guess->client_guess->field15c_guess) {
            if (g_target1d74_guess != g_self1d74_guess) {
                g_target1d74_guess->client_guess->fieldfe8_guess =
                    g_self1d74_guess->client_guess->fieldfe8_guess;
            }
            g_target1d74_guess->FollowPlayerAI_guess();
        }
    }
    if (client_guess->fieldc8_guess < -1000.0f) {
        motion_guess->field28_guess = 0.0f;
        motion_guess->field18_guess = 0.0f;
    } else if (client_guess->fieldc8_guess > 1.092006f) {
        float limit_guess = 1.092006f;
        // Spell effect 290 (EQEmu IncreaseRunSpeedCap) raises the 1.092 speed cap by its percent.
        int bonus_guess = g_char1d74_guess->fieldc280_guess.TotalSpellAffects_guess(0x122, 1, 0, 1);
        if (bonus_guess > 0) {
            limit_guess = bonus_guess * 0.01f + 1.092006f;
        }
        if (client_guess->fieldc8_guess > limit_guess) {
            client_guess->fieldc8_guess = limit_guess;
        }
    }
    if (g_flag1d74_009858c7_guess != 0) {
        if (active_guess != 0 && g_self1d74_guess != 0 && g_flag_00924670_guess != 0) {
            g_flag_00924670_guess = 0;
            g_self1d74_guess->DoAttack(0xd, 0, g_last1d74_guess);
        }
        if (g_flag1d74_009858c7_guess != 0 && active_guess != 0 && g_self1d74_guess != 0 &&
            g_flag_00924671_guess != 0) {
            g_flag_00924671_guess = 0;
            g_self1d74_guess->DoAttack(0xe, 0, g_last1d74_guess);
        }
    }
    if (g_selector1d74_guess != 0 && g_value_009257f0_guess != 0 &&
        g_effects1d74_guess[g_selector1d74_guess]->IsActive_guess()) {
        g_modeFlagE_guess = 0;
        g_effects1d74_guess[g_selector1d74_guess]->SetValue_guess(g_clock1d74_guess->FixHeading_guess(
            g_effects1d74_guess[g_selector1d74_guess]->GetValue_guess() -
            g_frameTime_00924858_guess * 12.0f));
    }
    if (g_modeFlagC_guess != 0 || (g_keys_00923860_guess & 4) != 0) {
        g_self1d74_guess->TurnOffAutoFollow_guess();
        if ((g_target1d74_guess->race_0260_guess == 0x8d ||
                (g_flag_00923d2d_guess == 0 && (g_flag_00923842_guess == 0 ||
                    (g_selector1d74_guess > 2 && g_selector1d74_guess != 6)))) &&
            ((g_keys_00923860_guess & 4) == 0 || (g_keys_00923860_guess & 0x10) == 0)) {
            if (active_guess != 0) {
                ++g_count_00923d50_guess;
                if (g_target1d74_guess->IsHorseRace_guess()) {
                    if (g_count_00923d50_guess > 8) {
                        g_count_00923d50_guess = 8;
                    }
                } else if (g_target1d74_guess->race_0260_guess == 0x8d) {
                    if (g_count_00923d50_guess > 3) {
                        g_count_00923d50_guess = 3;
                    }
                } else if (g_count_00923d50_guess > 12) {
                    g_count_00923d50_guess = 12;
                }
                motion_guess->field28_guess = (float)g_count_00923d50_guess;
            }
        } else {
            if (active_guess != 0 && client_guess->fieldc8_guess >= -1000.0f) {
                g_modeFlagE_guess = 1;
                g_speed_00923d90_guess = (g_target1d74_guess == g_self1d74_guess ?
                    g_char1d74_guess->fieldc280_guess.encum_factor_guess() : 1.0f) * 2.0f;
                if (g_target1d74_guess->field1b1_guess != 0 || client_guess->fieldc8_guess < 0.0f ||
                    g_target1d74_guess->standState_0251_guess == 'o') {
                    g_speed_00923d90_guess *= 0.5f;
                }
                if (g_target1d74_guess->client_guess != 0 &&
                    g_target1d74_guess->client_guess->field160_guess != 0) {
                    g_speed_00923d90_guess *= 0.25f;
                }
            }
            if (client_guess->fieldc8_guess < -1000.0f) {
                g_modeFlagE_guess = 0;
                g_speed_00923d90_guess = 0.0f;
            }
        }
    }
    if (g_value_00925538_guess != 0) {
        g_self1d74_guess->TurnOffAutoFollow_guess();
        if (g_target1d74_guess->race_0260_guess != 0x8d) {
            if (active_guess != 0 && client_guess->fieldc8_guess >= -1000.0f) {
                g_modeFlagE_guess = 1;
                g_speed_00923d90_guess = (g_target1d74_guess == g_self1d74_guess ?
                    g_char1d74_guess->fieldc280_guess.encum_factor_guess() : 1.0f) * 2.0f;
                if (g_target1d74_guess->field1b1_guess != 0 || client_guess->fieldc8_guess < 0.0f ||
                    g_target1d74_guess->standState_0251_guess == 'o') {
                    g_speed_00923d90_guess *= 0.5f;
                }
                if (g_target1d74_guess->client_guess != 0 &&
                    g_target1d74_guess->client_guess->field15c_guess != 0) {
                    g_speed_00923d90_guess *= 0.25f;
                }
            }
            if (client_guess->fieldc8_guess < -1000.0f) {
                g_modeFlagE_guess = 0;
                g_speed_00923d90_guess = 0.0f;
            }
        }
    }
    g_value_009239bc_guess = 0;
    if (g_selector1d74_guess != 0 && g_value_009257ec_guess != 0 &&
        g_effects1d74_guess[g_selector1d74_guess]->IsActive_guess()) {
        g_modeFlagE_guess = 0;
        g_effects1d74_guess[g_selector1d74_guess]->SetValue_guess(g_clock1d74_guess->FixHeading_guess(
            g_effects1d74_guess[g_selector1d74_guess]->GetValue_guess() +
            g_frameTime_00924858_guess * 12.0f));
    }
    if (g_modeFlagD_guess != 0 || (g_keys_00923860_guess & 8) != 0) {
        g_self1d74_guess->TurnOffAutoFollow_guess();
        if ((g_target1d74_guess->race_0260_guess == 0x8d ||
                (g_flag_00923d2d_guess == 0 && (g_flag_00923842_guess == 0 ||
                    (g_selector1d74_guess > 2 && g_selector1d74_guess != 6)))) &&
            ((g_keys_00923860_guess & 8) == 0 || (g_keys_00923860_guess & 0x10) == 0)) {
            if (active_guess != 0) {
                ++g_count_00923d54_guess;
                if (g_target1d74_guess->IsHorseRace_guess()) {
                    if (g_count_00923d54_guess > 8) {
                        g_count_00923d54_guess = 8;
                    }
                } else if (g_target1d74_guess->race_0260_guess == 0x8d) {
                    if (g_count_00923d54_guess > 3) {
                        g_count_00923d54_guess = 3;
                    }
                } else if (g_count_00923d54_guess > 12) {
                    g_count_00923d54_guess = 12;
                }
                motion_guess->field28_guess = (float)-g_count_00923d54_guess;
            }
        } else {
            if (active_guess != 0 && client_guess->fieldc8_guess >= -1000.0f) {
                g_modeFlagE_guess = 2;
                g_speed_00923d90_guess = (g_target1d74_guess == g_self1d74_guess ?
                    g_char1d74_guess->fieldc280_guess.encum_factor_guess() : 1.0f) * 2.0f;
                if (g_target1d74_guess->field1b1_guess != 0 || client_guess->fieldc8_guess < 0.0f ||
                    g_target1d74_guess->standState_0251_guess == 'o') {
                    g_speed_00923d90_guess *= 0.5f;
                }
                if (g_target1d74_guess->client_guess != 0 &&
                    g_target1d74_guess->client_guess->field160_guess != 0) {
                    g_speed_00923d90_guess *= 0.25f;
                }
            }
            if (client_guess->fieldc8_guess < -1000.0f) {
                g_modeFlagE_guess = 0;
                g_speed_00923d90_guess = 0.0f;
            }
        }
    }
    if (g_value_0092553c_guess != 0) {
        g_self1d74_guess->TurnOffAutoFollow_guess();
        if (g_target1d74_guess->race_0260_guess != 0x8d) {
            if (active_guess != 0 && client_guess->fieldc8_guess >= -1000.0f) {
                g_modeFlagE_guess = 2;
                g_speed_00923d90_guess = (g_target1d74_guess == g_self1d74_guess ?
                    g_char1d74_guess->fieldc280_guess.encum_factor_guess() : 1.0f) * 2.0f;
                if (g_target1d74_guess->field1b1_guess != 0 || client_guess->fieldc8_guess < 0.0f ||
                    g_target1d74_guess->standState_0251_guess == 'o') {
                    g_speed_00923d90_guess *= 0.5f;
                }
                if (g_target1d74_guess->client_guess != 0 &&
                    g_target1d74_guess->client_guess->field15c_guess != 0) {
                    g_speed_00923d90_guess *= 0.25f;
                }
            }
            if (client_guess->fieldc8_guess < -1000.0f) {
                g_modeFlagE_guess = 0;
                g_speed_00923d90_guess = 0.0f;
            }
        }
    }
    if (g_flag_00923842_guess != 0) {
        if (g_selector1d74_guess != 0 || g_target1d74_guess->standState_0251_guess == 'd' ||
            g_target1d74_guess->standState_0251_guess == 'o') {
            ApplyMouseLook_guess(active_guess);
        }
    } else if (g_value_00924998_guess != 0 && g_selector1d74_guess == 0 &&
        g_value_00925564_guess == 0 && g_value_00925568_guess == 0) {
        if (motion_guess->field2c_guess > 0.0f) {
            if (motion_guess->field2c_guess > 10.0f) {
                motion_guess->field2c_guess = motion_guess->field2c_guess - 10.0f;
            } else {
                motion_guess->field2c_guess = 0.0f;
            }
        }
        if (motion_guess->field2c_guess < 0.0f) {
            if (motion_guess->field2c_guess < -10.0f) {
                motion_guess->field2c_guess = motion_guess->field2c_guess + 10.0f;
            } else {
                motion_guess->field2c_guess = 0.0f;
            }
        }
    }
    if (active_guess != 0 && g_target1d74_guess->levitate_028c_guess == 0 &&
        g_target1d74_guess->race_0260_guess != 0x8d && client_guess->fieldc8_guess >= -1000.0f &&
        g_value_00925524_guess != 0) {
        if (client_guess->fieldad_guess == 0) {
            if ((g_target1d74_guess->standState_0251_guess == 'd' ||
                    g_target1d74_guess->standState_0251_guess == 'o') &&
                g_time_00923854_guess == 0) {
                if (g_time_00923858_guess > g_clock1d74_guess->field148_guess) {
                    g_time_00923858_guess = 0;
                }
                if (g_target1d74_guess->FUN_0048a2f4_guess() &&
                    // One jump per 1.5 s; with +0x11AC (probably endurance) <= 50 and <= a tenth of
                    // the maximum it prints 'You are too fatigued to jump!' instead.
                    g_clock1d74_guess->field148_guess - g_time_00923858_guess > 1500) {
                    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0 &&
                        reinterpret_cast<CharInfo1d74_guess*>(
                            g_char1d74_guess->profile_guess.GetCharInfo2())->field11ac_guess <= 50 &&
                        reinterpret_cast<CharInfo1d74_guess*>(
                            g_char1d74_guess->profile_guess.GetCharInfo2())->field11ac_guess <=
                            g_char1d74_guess->fieldc280_guess.Max_Endurance() / 10) {
                        g_globalState_guess->DspChat_guess(pStringTable->getString(0x304a, 0), 0xf,
                            true);
                    } else {
                        g_time_00923854_guess = g_clock1d74_guess->field148_guess;
                    }
                }
            }
        } else if (g_time_00923854_guess == 0) {
            if (g_time_00923858_guess > g_clock1d74_guess->field148_guess) {
                g_time_00923858_guess = 0;
            }
            g_time_00923854_guess = g_clock1d74_guess->field148_guess;
        }
    }
    g_value_00925524_guess = 0;
    if (g_value_00925570_guess != 0 && g_effects1d74_guess[g_selector1d74_guess]->IsActive_guess()) {
        float value_guess = g_effects1d74_guess[g_selector1d74_guess]->field34_guess -
            g_frameTime_00924858_guess * 2.0f;
        if (value_guess < g_target1d74_guess->heightOffset_0238_guess) {
            value_guess = g_target1d74_guess->heightOffset_0238_guess;
        }
        g_effects1d74_guess[g_selector1d74_guess]->Slot06_guess(value_guess);
    }
    if (g_value_00925574_guess != 0 && g_effects1d74_guess[g_selector1d74_guess]->IsActive_guess()) {
        float value_guess = g_frameTime_00924858_guess * 2.0f +
            g_effects1d74_guess[g_selector1d74_guess]->field34_guess;
        if (value_guess > 400.0f) {
            value_guess = 400.0f;
        }
        g_effects1d74_guess[g_selector1d74_guess]->Slot06_guess(value_guess);
    }
    if (g_selector1d74_guess != 0 && g_value_009257e4_guess != 0) {
        g_effects1d74_guess[g_selector1d74_guess]->Slot04_guess(
            g_frameTime_00924858_guess + g_effects1d74_guess[g_selector1d74_guess]->field2c_guess);
    }
    if (g_modeFlagA_guess != 0 || (g_keys_00923860_guess & 1) != 0 || g_flag_009237b7_guess != 0) {
        if (active_guess == 0) {
            if (g_flag_009254f7_guess != 0 && g_modeFlagA_guess != 0) {
                if (g_target1d74_guess->standState_0251_guess == 'n') {
                    g_globalState_guess->ToggleSit_guess();
                } else if (pinstCLootWnd_guess->IsVisible_guess()) {
                    pinstCLootWnd_guess->Show(0, 1);
                }
            }
        } else if (g_target1d74_guess->race_0260_guess == 0x8d) {
            motion_guess->field18_guess = g_target1d74_guess->GetWalkSpeed_guess();
            if (client_guess->fieldc8_guess < -1000.0f) {
                motion_guess->field18_guess = 0.0f;
            }
            speed_guess = motion_guess->field18_guess;
        } else {
            if (g_target1d74_guess->field1b1_guess != 0) {
                speed_guess = g_target1d74_guess->GetWalkSpeed_guess() *
                    g_target1d74_guess->client_guess->fieldec4_guess;
                if (g_target1d74_guess == g_self1d74_guess) {
                    speed_guess = g_char1d74_guess->fieldc280_guess.encum_factor_guess() * speed_guess;
                }
                if (client_guess->fieldad_guess > 4) {
                    speed_guess = g_char1d74_guess->fieldc280_guess.HasSkillChecked_guess(50) * 0.01 +
                        speed_guess;
                    if (motion_guess->field2c_guess > 0.0f) {
                        g_target1d74_guess->FUN_0048a793_guess(true);
                    }
                }
            } else if (g_target1d74_guess->standState_0251_guess == 'o') {
                speed_guess = g_target1d74_guess->GetWalkSpeed_guess() * 0.5f;
                if (g_target1d74_guess == g_self1d74_guess) {
                    speed_guess = g_char1d74_guess->fieldc280_guess.encum_factor_guess() * speed_guess;
                }
            } else {
                if (g_value_009237b4_guess != 0) {
                    speed_guess = g_value_009237b4_guess * g_target1d74_guess->runSpeed_0230_guess;
                } else {
                    speed_guess = g_target1d74_guess->GetWalkSpeed_guess();
                }
                if (g_target1d74_guess == g_self1d74_guess) {
                    speed_guess = g_char1d74_guess->fieldc280_guess.encum_factor_guess() * speed_guess;
                }
                if (client_guess->fieldad_guess > 4) {
                    speed_guess = g_char1d74_guess->fieldc280_guess.HasSkillChecked_guess(50) * 0.01 +
                        speed_guess;
                    if (motion_guess->field2c_guess > 0.0f) {
                        g_target1d74_guess->FUN_0048a793_guess(true);
                    }
                }
            }
            if (client_guess->fieldc8_guess < -1000.0f) {
                speed_guess = 0.0f;
            } else {
                speed_guess += client_guess->fieldc8_guess;
                if (speed_guess < 0.0f) {
                    speed_guess = 0.01f;
                }
            }
            g_target1d74_guess->FUN_0047a421_guess(speed_guess, 0);
        }
    }
    if (g_selector1d74_guess != 0 && g_value_009257e8_guess != 0) {
        g_effects1d74_guess[g_selector1d74_guess]->Slot04_guess(
            g_effects1d74_guess[g_selector1d74_guess]->field2c_guess - g_frameTime_00924858_guess);
    }
    if (g_modeFlagB_guess != 0 || (g_keys_00923860_guess & 2) != 0) {
        g_self1d74_guess->TurnOffAutoFollow_guess();
        if (active_guess != 0) {
            if (g_target1d74_guess->race_0260_guess == 0x8d) {
                motion_guess->field18_guess = -g_target1d74_guess->GetWalkSpeed_guess();
                if (client_guess->fieldc8_guess < -1000.0f) {
                    motion_guess->field18_guess = 0.0f;
                }
                speed_guess = motion_guess->field18_guess;
            } else {
                // Backing up: half speed when slowed, none while the client is busy.
                bool slow_guess = g_target1d74_guess->field1b1_guess != 0 ||
                    g_target1d74_guess->standState_0251_guess == 'o';
                if (slow_guess || client_guess->fieldad_guess == 0) {
                    if (slow_guess) {
                        speed_guess = -(g_target1d74_guess->GetWalkSpeed_guess() * 0.5f);
                    } else {
                        speed_guess = -g_target1d74_guess->GetWalkSpeed_guess();
                    }
                    if (g_target1d74_guess == g_self1d74_guess) {
                        speed_guess = g_char1d74_guess->fieldc280_guess.encum_factor_guess() * speed_guess;
                    }
                } else {
                    speed_guess = 0.0f;
                }
                if (client_guess->fieldc8_guess < -1000.0f) {
                    speed_guess = 0.0f;
                } else {
                    speed_guess -= client_guess->fieldc8_guess;
                    if (speed_guess > 0.0f) {
                        speed_guess = -0.01f;
                    }
                }
                g_target1d74_guess->FUN_0047a421_guess(speed_guess, 0);
            }
        }
    }
    if (g_selector1d74_guess != 0 && g_value_009257f4_guess != 0) {
        float distance_guess = g_frameTime_00924858_guess * 8.0f +
            g_effects1d74_guess[g_selector1d74_guess]->field30_guess;
        if (distance_guess > 128.0f) {
            distance_guess = 128.0f;
        }
        g_effects1d74_guess[g_selector1d74_guess]->Slot05_guess(distance_guess);
    }
    if (g_value_00925564_guess != 0) {
        if (g_target1d74_guess->IsHorseRace_guess() || g_target1d74_guess->race_0260_guess == 0x8d) {
            if (++g_count_00923d40_guess > 12) {
                g_count_00923d40_guess = 12;
            }
            g_self1d74_guess->motion_guess.field2c_guess =
                g_count_00923d40_guess * g_frameTime_00924858_guess +
                g_self1d74_guess->motion_guess.field2c_guess;
            if (g_self1d74_guess->motion_guess.field2c_guess > 128.0f) {
                g_self1d74_guess->motion_guess.field2c_guess = 128.0f;
            }
        } else {
            if (++g_count_00923d40_guess > 12) {
                g_count_00923d40_guess = 12;
            }
            motion_guess->field2c_guess =
                g_count_00923d40_guess * g_frameTime_00924858_guess + motion_guess->field2c_guess;
            if (motion_guess->field2c_guess > 128.0f) {
                motion_guess->field2c_guess = 128.0f;
            }
        }
    }
    if (g_selector1d74_guess != 0 && g_value_009257f8_guess != 0) {
        float distance_guess = g_effects1d74_guess[g_selector1d74_guess]->field30_guess -
            g_frameTime_00924858_guess * 8.0f;
        if (distance_guess < -128.0f) {
            distance_guess = -128.0f;
        }
        g_effects1d74_guess[g_selector1d74_guess]->Slot05_guess(distance_guess);
    }
    if (g_value_00925568_guess != 0) {
        if (g_target1d74_guess->IsHorseRace_guess() || g_target1d74_guess->race_0260_guess == 0x8d) {
            if (++g_count_00923d44_guess > 12) {
                g_count_00923d44_guess = 12;
            }
            g_self1d74_guess->motion_guess.field2c_guess =
                -(g_count_00923d44_guess * g_frameTime_00924858_guess) +
                g_self1d74_guess->motion_guess.field2c_guess;
            if (g_self1d74_guess->motion_guess.field2c_guess < -128.0f) {
                g_self1d74_guess->motion_guess.field2c_guess = -128.0f;
            }
        } else {
            if (++g_count_00923d44_guess > 12) {
                g_count_00923d44_guess = 12;
            }
            motion_guess->field2c_guess =
                -(g_count_00923d44_guess * g_frameTime_00924858_guess) + motion_guess->field2c_guess;
            if (motion_guess->field2c_guess < -128.0f) {
                motion_guess->field2c_guess = -128.0f;
            }
        }
    }
    // -20001.1 means no movement key was handled this frame: the mover stops.
    if (speed_guess == -20001.1f) {
        g_target1d74_guess->FUN_0047a421_guess(0.0f, 0);
    }
    // Remember what was last sent and flag the mover as changed.
    if (fabs(g_value_009858e4_guess - motion_guess->field1c_guess) >= 2.0f) {
        if (g_self1d74_guess == g_target1d74_guess) {
            g_flag_00923d79_guess = 1;
        } else {
            g_flag_00923d78_guess = 1;
        }
        g_value_009858e4_guess = motion_guess->field1c_guess;
    }
    if (fabs(g_value_009858e0_guess - motion_guess->field18_guess) >= 0.2f) {
        if (g_self1d74_guess == g_target1d74_guess) {
            g_flag_00923d79_guess = 1;
        } else {
            g_flag_00923d78_guess = 1;
        }
        g_value_009858e0_guess = motion_guess->field18_guess;
    }
    if (g_modeFlagE_guess != 0) {
        if (g_self1d74_guess == g_target1d74_guess) {
            g_flag_00923d79_guess = 1;
        } else {
            g_flag_00923d78_guess = 1;
        }
    }
}

// EXTERNAL: TITANIUM 0x004649EB UserPetitions_guess
int __cdecl UserPetitions_guess(char* text);

// /petition, or guide help with `flag`: sends the text (0x4649EB) and echoes 0x3025 or 0xDE8.
// FUNCTION: TITANIUM 0x004A1953
void GlobalState_guess::send_petition_guess(bool flag_guess) {
    char line_guess[2112];
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        UserPetitions_guess(field17bb4_guess);
        FUN_0046da4a_guess(line_guess, flag_guess ? 0x0DE8 : 0x3025, field17bb4_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(line_guess, 0, true);
    }
}

// /gmsay: sends on channel 0xB and echoes 'You GMSAY, %1' (0x3027), unless 0x92419C is set.
// FUNCTION: TITANIUM 0x004A19D1
void GlobalState_guess::send_private_guess() {
    char line_guess[2112];
    if (g_flag_0092419c_guess == 0 && g_sendDisabled_00923798_guess == 0 &&
        g_flag_00923884_guess == 0) {
        // Formatted and then overwritten by the 0x3027 line: '%1 GMSAYS' is never shown (original).
        FUN_0046da4a_guess(line_guess, 0x3026, g_resetOwner_guess->name_0120_guess,
            field17bb4_guess, 0, 0, 0, 0, 0, 0, 0);
        SendNewText_guess(0xb, 0, (int)field17bb4_guess, 0);
        FUN_0046da4a_guess(line_guess, 0x3027, field17bb4_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(line_guess, 0, true);
    }
}

// EXTERNAL: TITANIUM 0x0040C1E2 ClockElapsed_guess
int __cdecl ClockElapsed_guess(__int64 value_guess);

// EXTERNAL: TITANIUM 0x0040C194 GetClockStamp_guess
__int64 __cdecl GetClockStamp_guess();

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

struct NamedSlotTable_guess {
    char padding_0000_guess[0x298];
    __int64 field298_guess; // 0x298
    char field2a0_guess; // 0x2A0, kind
    char field2a1_guess[0x100]; // 0x2A1, name
    char entries3a1_guess[10][0x30]; // 0x3A1
    char padding_0581_guess[3];
    int field584_guess[10]; // 0x584
    int field5ac_guess; // 0x5AC, count
    void ChatServerNotificationFlush_guess();
    void ChatServerNotificationAdd_guess(char kind_guess, const char* name_guess,
        const char* text_guess, int value_guess);
    void ChatServerUserEntered_guess(const char* name_guess, int value_guess,
        const char* text_guess, char enabled_guess);
    void ChatServerUserLeft_guess(const char* name_guess, int value_guess,
        const char* text_guess, char enabled_guess);
};

// Prints one user's batched joins or leaves as '* name has entered channel chan:1, chan2:3' (channel
// numbers 1-based), colour 0x122.
// FUNCTION: TITANIUM 0x0049A111
void NamedSlotTable_guess::ChatServerNotificationFlush_guess() {
    char buffer_guess[2048];
    if (field5ac_guess > 0) {
        if (field2a0_guess != 0) {
            _sprintf(buffer_guess, "* %s has entered channel ", field2a1_guess);
        } else {
            _sprintf(buffer_guess, "* %s has left channel ", field2a1_guess);
        }
        for (int i_guess = 0; i_guess < field5ac_guess; ++i_guess) {
            if (i_guess == 0) {
                _sprintf(buffer_guess + strlen(buffer_guess), "%s:%d",
                    entries3a1_guess[0], field584_guess[0] + 1);
            } else {
                _sprintf(buffer_guess + strlen(buffer_guess), ", %s:%d",
                    entries3a1_guess[i_guess], field584_guess[i_guess] + 1);
            }
        }
        reinterpret_cast<CEverQuest*>(this)->dsp_chat(buffer_guess, 0x122, true);
        field5ac_guess = 0;
        field2a1_guess[0] = 0;
    }
}

// Pumps the chat-server API (+0x290) and flushes batched notices after 1 s. Once connected it auto-joins
// the ChannelAutoJoin list ([Defaults], then [ChatManager]) with ';join'.
// FUNCTION: TITANIUM 0x004A2FD7
void TargetOwner_guess::ChatServerGiveTime_guess() {
    char configValue_guess[1024];
    char channelList_guess[1000];
    NamedSlotTable_guess* table_guess = reinterpret_cast<NamedSlotTable_guess*>(this);

    if (field290_guess != 0) {
        field290_guess->GiveTime_guess();
        if (table_guess->field5ac_guess > 0 &&
            ClockElapsed_guess(table_guess->field298_guess) > 1000) {
            table_guess->ChatServerNotificationFlush_guess();
        }
        if (field290_guess->FUN_0040bf0f_guess() == 1 && field294_guess == 0 &&
            NewUIINI() != 0) {
            FUN_0060be50_guess("Defaults", "ChannelAutoJoin", "*NONE*",
                configValue_guess, 1000, ".\\eqclient.ini");
            g_globalState_guess->FUN_004ae865_guess("ChatManager", "ChannelAutoJoin",
                configValue_guess, channelList_guess, 1000, 1);
            if (strcmp(channelList_guess, "*NONE*") != 0) {
                reinterpret_cast<GlobalState_guess*>(this)->DspChat_guess(
                    "Autojoining channels...", 0x122, true);
                FUN_0060e450_guess(configValue_guess, ";join ");
                FUN_0060e460_guess(configValue_guess, channelList_guess);
                ChatServerMessage_guess((int)configValue_guess);
            }
            field294_guess = 1;
            g_owned_0079dbd4_guess->UpdateAutoJoinChannels_guess(g_charData_guess);
        }
    }
}

// Batches a join (kind 1) or leave (0) for one user; another user or kind, or more than 10 entries,
// flushes first. Names on the ignore list are dropped.
// FUNCTION: TITANIUM 0x004A3125
void NamedSlotTable_guess::ChatServerNotificationAdd_guess(char kind_guess, const char* name_guess,
    const char* text_guess, int value_guess) {
    if (field2a0_guess != kind_guess || _stricmp(field2a1_guess, name_guess) != 0 ||
        field5ac_guess > 10) {
        ChatServerNotificationFlush_guess();
    }
    if (reinterpret_cast<GlobalState_guess*>(this)->BeingIgnored_guess(
            reinterpret_cast<unsigned int>(name_guess)) == 0) {
        field298_guess = GetClockStamp_guess();
        FUN_0060e450_guess(field2a1_guess, name_guess);
        field2a0_guess = kind_guess;
        FUN_0060e450_guess(entries3a1_guess[field5ac_guess], text_guess);
        field584_guess[field5ac_guess] = value_guess;
        ++field5ac_guess;
    }
}

// Chat handler slot 4 (vtable 0x6498D4): queues a channel-joined notice.
// FUNCTION: TITANIUM 0x004A31CB
void NamedSlotTable_guess::ChatServerUserEntered_guess(const char* name_guess, int value_guess,
    const char* text_guess, char enabled_guess) {
    if (enabled_guess != 0) {
        ChatServerNotificationAdd_guess(1, name_guess, text_guess, value_guess);
    }
}

// Chat handler slot 5: queues a channel-left notice.
// FUNCTION: TITANIUM 0x004A31E8
void NamedSlotTable_guess::ChatServerUserLeft_guess(const char* name_guess, int value_guess,
    const char* text_guess, char enabled_guess) {
    if (enabled_guess != 0) {
        ChatServerNotificationAdd_guess(0, name_guess, text_guess, value_guess);
    }
}

// Pumps the mail API (+0x834); a dead connection is dropped; batched notices flush after 1 s.
// FUNCTION: TITANIUM 0x004A3205
void TargetOwner_guess::MailServerGiveTime_guess() {
    if (field834_guess != 0) {
        if (field834_guess->FUN_005ff520_guess() == 0) {
            DisconnectMailServer_guess();
            return;
        }
        field834_guess->FUN_005ffc60_guess();
        if (fieldb4c_guess > 0) {
            if (ClockElapsed_guess(field838_guess) > 1000) {
                MailServerNotificationFlush_guess();
                return;
            }
        }
    }
}

// Waits up to 500 ms for network traffic, then pumps the chat and mail connections; the login and
// zone-in loops call it.
// FUNCTION: TITANIUM 0x004A56B1
int TargetOwner_guess::ProcessMBox_guess() {
    if (g_connectionManager_guess != 0 &&
        reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess != 0) {
        reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess->Wait_guess(500);
    }
    ChatServerGiveTime_guess();
    MailServerGiveTime_guess();
    return 1;
}

#define g_value_00923d60_guess EQ_GLOBAL(int, 0x00923D60)

// Chat handler slot 1: reports the status to the world (opcode 0x623C, not in patch_Titanium.conf)
// unless it is 6, then prints eqstr 599, with ' (reason=a,b)' when 0x923D60 is set.
// FUNCTION: TITANIUM 0x0049A1F1
void GlobalState_guess::ChatServerConnectionLost_guess(ConnectionStatus_guess* status_guess) {
    if (field290_guess != 0 && field290_guess->Get_guess() > 0) {
        int status_value_guess = status_guess->ConvertStatus_guess();
        int payload_guess[2];
        char text_guess[512];
        char reason_guess[512];
        if (status_value_guess != 6) {
            payload_guess[0] = status_value_guess;
            payload_guess[1] = status_guess->GetStatus_guess();
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x623c, payload_guess, 8, 1);
        }
        reason_guess[0] = 0;
        if (g_value_00923d60_guess != 0) {
            _sprintf(reason_guess, " (reason=%d,%d)", status_value_guess,
                status_guess->GetStatus_guess());
        }
        FUN_0046da4a_guess(text_guess, 599, reason_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        DspChat_guess(text_guess, 0x122, 1);
    }
}

struct ChannelEventHandler_guess {
    void ChatServerMessageReceived_guess(const char* first_guess, const char* second_guess,
        int index_guess, const char* text_guess, char flag_guess);
    void MailServerMessageReceived_guess(char* first_guess, char* second_guess,
        int index_guess, char* text_guess, char flag_guess);
};

// Chat handler slot 2, one message: index >= 0 is channel n (colour 0x123+n, 0x13B+n for your own
// lines; ignored senders dropped), -3 a tell (0x1A3F sent, 0x1A40 received), -2 eqstr 0x1A43, -4 a ';'
// line also passed to 0x467AD1 (eqstr 0x1A41).
// FUNCTION: TITANIUM 0x0049A2D7
// @early-stop: budget, structural ndiff=99
void ChannelEventHandler_guess::ChatServerMessageReceived_guess(const char* first_guess,
    const char* second_guess, int index_guess, const char* text_guess,
    char flag_guess) {
    char formatted_guess[96];
    char combined_guess[4096];
    char message_guess[4096];
    int color_guess = 0x122;
    message_guess[0] = 0;

    if (index_guess != -4) {
        if (index_guess == -3) {
            if (flag_guess != 0) {
                color_guess = 0x134;
                FUN_0046da4a_guess(message_guess, 0x1a3f, second_guess,
                    first_guess, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FUN_0046da4a_guess(message_guess, 0x1a40, text_guess,
                    second_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
            }
        } else if (index_guess == -2) {
            _sprintf(formatted_guess, (const char*)EQ_ARRAY(char, 0x006460AC), second_guess);
            FUN_0046da4a_guess(message_guess, 0x1a43, text_guess,
                formatted_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
        } else if (index_guess >= 0) {
            _sprintf(formatted_guess, "%s:%d", second_guess, index_guess + 1);
            color_guess = index_guess + 0x123;
            if (*text_guess != 0) {
                if (reinterpret_cast<GlobalState_guess*>(this)->BeingIgnored_guess(
                        reinterpret_cast<unsigned int>(text_guess)) != 0) {
                    return;
                }
                if (flag_guess != 0) {
                    color_guess = index_guess + 0x13b;
                    FUN_0046da4a_guess(message_guess, 0x1a42, formatted_guess,
                        first_guess, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FUN_0046da4a_guess(message_guess, 0x1a43, text_guess,
                        formatted_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
                }
            } else {
                FUN_0060e450_guess(message_guess, first_guess);
            }
        } else {
            FUN_0060e450_guess(message_guess, first_guess);
        }
    } else {
        if (reinterpret_cast<GlobalState_guess*>(this)->BeingIgnored_guess(
                reinterpret_cast<unsigned int>(text_guess)) != 0) {
            return;
        }
        message_guess[0] = ';';
        FUN_0060e450_guess(message_guess + 1, text_guess);
        AddNameToTellList_guess(message_guess);
        color_guess = 0x101;
        if (EQ_GLOBAL(int, 0x00923D74) == 0) {
            GarbleText_guess(first_guess, combined_guess, 100);
        } else {
            FUN_0060e450_guess(combined_guess, first_guess);
        }
        FUN_0046da4a_guess(message_guess, 0x1a41, text_guess, combined_guess,
            0, 0, 0, 0, 0, 0, 0);
    }

    if (message_guess[0] != 0) {
        reinterpret_cast<NamedSlotTable_guess*>(this)->ChatServerNotificationFlush_guess();
        reinterpret_cast<CEverQuest*>(this)->dsp_chat(message_guess, color_guess, true);
    }
}

struct SlotTableB_guess {
    char padding_0000_guess[0x838];
    __int64 field838_guess; // 0x838
    char field840_guess; // 0x840, kind
    char field841_guess[0x100]; // 0x841, name
    char entries941_guess[10][0x30]; // 0x941
    char padding_0b21_guess[3];
    int field_b24_guess[10]; // 0xB24
    int fieldb4c_guess; // 0xB4C, count
    void MailServerNotificationFlush_guess();
    void MailServerNotificationAdd_guess(char kind_guess, const char* name_guess,
        const char* text_guess, int value_guess);
};

// Twin of ChatServerNotificationFlush for the mail API's batch (+0x840).
// FUNCTION: TITANIUM 0x0049A4F9
void SlotTableB_guess::MailServerNotificationFlush_guess() {
    if (fieldb4c_guess > 0) {
        char buffer_guess[2048];
        if (field840_guess != 0) {
            sprintf(buffer_guess, "* %s has entered channel ", field841_guess);
        } else {
            sprintf(buffer_guess, "* %s has left channel ", field841_guess);
        }
        for (int i = 0; i < fieldb4c_guess; ++i) {
            if (i == 0) {
                sprintf(buffer_guess + strlen(buffer_guess), "%s:%d", entries941_guess[0], field_b24_guess[0] + 1);
            } else {
                sprintf(buffer_guess + strlen(buffer_guess), ", %s:%d", entries941_guess[i], field_b24_guess[i] + 1);
            }
        }
        reinterpret_cast<GlobalState_guess*>(this)->DspChat_guess(buffer_guess, 0x122, true);
        fieldb4c_guess = 0;
        field841_guess[0] = 0;
    }
}

// Twin of ChatServerMessageReceived for the mail connection (`this` is CEverQuest+4); its -4 line
// starts with '[' instead of ';'.
// FUNCTION: TITANIUM 0x0049A970
// @early-stop: budget, structural ndiff=83
void ChannelEventHandler_guess::MailServerMessageReceived_guess(char* first_guess,
    char* second_guess, int index_guess, char* text_guess, char flag_guess) {
    char formatted_guess[96];
    char message_guess[4096];
    char combined_guess[4096];
    int color_guess = 0x122;
    message_guess[0] = 0;

    if (index_guess != -4) {
        if (index_guess == -3) {
            if (flag_guess != 0) {
                color_guess = 0x134;
                FUN_0046da4a_guess(message_guess, 0x1a3f, second_guess,
                    first_guess, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FUN_0046da4a_guess(message_guess, 0x1a40, text_guess,
                    second_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
            }
        } else if (index_guess == -2) {
            _sprintf(formatted_guess, (const char*)EQ_ARRAY(char, 0x006460AC),
                second_guess);
            FUN_0046da4a_guess(message_guess, 0x1a43, text_guess,
                formatted_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
        } else if (index_guess >= 0) {
            _sprintf(formatted_guess, "%s:%d", second_guess, index_guess + 1);
            color_guess = index_guess + 0x123;
            if (*text_guess != 0) {
                GlobalState_guess* owner_guess = reinterpret_cast<GlobalState_guess*>(
                    reinterpret_cast<unsigned int*>(this) - 1);
                if (owner_guess->BeingIgnored_guess(
                        reinterpret_cast<unsigned int>(text_guess)) != 0) {
                    return;
                }
                if (flag_guess != 0) {
                    color_guess = index_guess + 0x13b;
                    FUN_0046da4a_guess(message_guess, 0x1a42, formatted_guess,
                        first_guess, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FUN_0046da4a_guess(message_guess, 0x1a43, text_guess,
                        formatted_guess, (int)first_guess, 0, 0, 0, 0, 0, 0);
                }
            } else {
                FUN_0060e450_guess(message_guess, first_guess);
            }
        } else {
            FUN_0060e450_guess(message_guess, first_guess);
        }
    } else {
        GlobalState_guess* owner_guess = reinterpret_cast<GlobalState_guess*>(
            reinterpret_cast<unsigned int*>(this) - 1);
        if (owner_guess->BeingIgnored_guess(
                reinterpret_cast<unsigned int>(text_guess)) != 0) {
            return;
        }
        message_guess[0] = '[';
        FUN_0060e450_guess(message_guess + 1, text_guess);
        AddNameToTellList_guess(message_guess);
        color_guess = 0x101;
        if (EQ_GLOBAL(int, 0x00923D74) == 0) {
            GarbleText_guess(first_guess, combined_guess, 100);
        } else {
            FUN_0060e450_guess(combined_guess, first_guess);
        }
        FUN_0046da4a_guess(message_guess, 0x1a41, text_guess, combined_guess,
            0, 0, 0, 0, 0, 0, 0);
    }

    if (message_guess[0] != 0) {
        unsigned int* owner_guess = reinterpret_cast<unsigned int*>(this) - 1;
        reinterpret_cast<SlotTableB_guess*>(owner_guess)->MailServerNotificationFlush_guess();
        reinterpret_cast<GlobalState_guess*>(owner_guess)->DspChat_guess(
            message_guess, color_guess, true);
    }
}

// Twin of ChatServerNotificationAdd for the mail API's batch (+0x840).
// FUNCTION: TITANIUM 0x004A325B
void SlotTableB_guess::MailServerNotificationAdd_guess(char kind_guess, const char* name_guess,
    const char* text_guess, int value_guess) {
    if (field840_guess != kind_guess || _stricmp(field841_guess, name_guess) != 0 ||
        fieldb4c_guess > 10) {
        MailServerNotificationFlush_guess();
    }
    if (reinterpret_cast<GlobalState_guess*>(this)->BeingIgnored_guess(
            reinterpret_cast<unsigned int>(name_guess)) == 0) {
        field838_guess = GetClockStamp_guess();
        FUN_0060e450_guess(field841_guess, name_guess);
        field840_guess = kind_guess;
        FUN_0060e450_guess(entries941_guess[fieldb4c_guess], text_guess);
        field_b24_guess[fieldb4c_guess] = value_guess;
        ++fieldb4c_guess;
    }
}

struct SlotTableCallback_guess {
    void MailServerUserEntered_guess(const char* name_guess, int value_guess,
        const char* text_guess, char enabled_guess);
    void MailServerUserLeft_guess(const char* name_guess, int value_guess,
        const char* text_guess, char enabled_guess);
};

// Mail handler slot 4 (vtable 0x649890, `this` is CEverQuest+4): queues a join notice.
// FUNCTION: TITANIUM 0x004A3301
void SlotTableCallback_guess::MailServerUserEntered_guess(const char* name_guess,
    int value_guess, const char* text_guess, char enabled_guess) {
    if (enabled_guess != 0) {
        reinterpret_cast<SlotTableB_guess*>(
            reinterpret_cast<unsigned int*>(this) - 1)->MailServerNotificationAdd_guess(
                1, name_guess, text_guess, value_guess);
    }
}

// Mail handler slot 5: queues a leave notice.
// FUNCTION: TITANIUM 0x004A3321
void SlotTableCallback_guess::MailServerUserLeft_guess(const char* name_guess,
    int value_guess, const char* text_guess, char enabled_guess) {
    if (enabled_guess != 0) {
        reinterpret_cast<SlotTableB_guess*>(
            reinterpret_cast<unsigned int*>(this) - 1)->MailServerNotificationAdd_guess(
                0, name_guess, text_guess, value_guess);
    }
}

struct CharInfoView_guess {
    char padding_0000_guess[0x11A4];
    unsigned char field11a4_guess;
};

struct Owner24c_guess {
    char padding_0000_guess[0x24C];
    unsigned char field24c_guess;
    char padding_024d_guess[0x284 - 0x24D];
    unsigned int field284_guess;
};

#define g_owner24c_00905ce4_guess EQ_GLOBAL(Owner24c_guess*, 0x00905CE4)

#define g_flag_009858c8_guess EQ_GLOBAL(char, 0x009858C8)

#define g_flag_0092384c_guess EQ_GLOBAL(unsigned char, 0x0092384C)
#define g_value_009248d8_guess EQ_GLOBAL(int, 0x009248D8)

struct Dispatch851390_guess {
    // EXTERNAL: TITANIUM 0x0044A617 Dispatch851390_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int value_guess, bool flag_guess);
};

#define g_dispatch_00851390_guess EQ_GLOBAL(Dispatch851390_guess*, 0x00851390)

// Auto attack (0x9858C7): turning it on turns auto fire off; both stay off while 0x92384C is set.
// Refreshes the attack indicator (0x44A617).
// FUNCTION: TITANIUM 0x004A2F7A
void GlobalObj923770_guess::SetAutoAttack_guess(unsigned char value_guess) {
    field62157_guess = value_guess;
    if (g_flag_0092384c_guess != 0) {
        field62157_guess = 0;
        SetAutoFire_guess(0);
    }
    if (field62157_guess != 0) {
        SetAutoFire_guess(0);
    }
    if (g_dispatch_00851390_guess != 0) {
        g_dispatch_00851390_guess->SetMusicSelection_guess(2,
            field62157_guess != 0 && g_value_009248d8_guess != 0);
    }
}

struct EverQuestSelf_guess {
    char padding_0000_guess[0x3A1BB];
    unsigned char field3a1bb_guess;
    void ResetCombatStateOnDeath_guess(int a_guess, int b_guess);
    void ReportSuccessfulHit_guess(void* summary_guess, unsigned char flag_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0049185E EverQuestSelf_guess::SetDefaultDamageDescByRace_guess
    void SetDefaultDamageDescByRace_guess(char* output_guess, int type_guess, char flag_guess);
    // EXTERNAL: TITANIUM 0x00491BAD EverQuestSelf_guess::GetSoundEffectForRiposte_guess
    int GetSoundEffectForRiposte_guess(void* first_guess, void* second_guess);
    void ReportDeath_guess(void* packet_guess);
};

// On death (ReportDeath only): stops auto attack and auto fire, resets the player's +0x24C and +0x284
// from the character data and sets +0x3A1BB.
// FUNCTION: TITANIUM 0x004A6E9F
void EverQuestSelf_guess::ResetCombatStateOnDeath_guess(int a_guess, int b_guess) {
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    CharInfoView_guess* info_guess = reinterpret_cast<CharInfoView_guess*>(
        g_charData_guess->Info_guess());
    g_owner24c_00905ce4_guess->field24c_guess = info_guess->field11a4_guess;
    g_owner24c_00905ce4_guess->field284_guess =
        g_contextObject_guess->fieldc280_guess.Max_HP_guess(0);
    field3a1bb_guess = 1;
}

// Auto fire (0x9858C8); a change prints 'Auto fire on.' (0x116) or 'Auto fire off.' (0x117).
// FUNCTION: TITANIUM 0x0049994C
void GlobalObj923770_guess::SetAutoFire_guess(char value_guess) {
    bool changed_guess = field62158_guess != value_guess;
    field62158_guess = value_guess;
    if (g_flag_0092384c_guess != 0) {
        field62157_guess = 0;
        field62158_guess = 0;
    }
    if (g_globalState_guess != 0 && changed_guess) {
        if (g_flag_009858c8_guess != 0) {
            g_globalState_guess->DspChat_guess(pStringTable->getString(0x116, 0), 0xd, true);
        } else {
            g_globalState_guess->DspChat_guess(pStringTable->getString(0x117, 0), 0xd, true);
        }
        if (g_dispatch_00851390_guess != 0) {
            g_dispatch_00851390_guess->SetMusicSelection_guess(2,
                field62157_guess != 0 && g_value_009248d8_guess != 0);
        }
    }
}

struct FocusService_guess {
    void** vtable_guess;
};
typedef void (__stdcall *FocusCall_guess)(FocusService_guess* service_guess);

struct CursorDisplay_guess {
    // EXTERNAL: TITANIUM 0x00609D50 CursorDisplay_guess::Width_guess
    int Width_guess();
    // EXTERNAL: TITANIUM 0x00609D60 CursorDisplay_guess::Height_guess
    int Height_guess();
};

// EXTERNAL: TITANIUM 0x004CCE44 ProcessMouseEvents_guess
void __cdecl ProcessMouseEvents_guess();
// EXTERNAL: TITANIUM 0x004CD510 GetMouseClientPos_guess
__int64 __cdecl GetMouseClientPos_guess();

#define g_window_00923770_guess EQ_GLOBAL(HWND, 0x00923770)
#define g_focusService_00988c84_guess EQ_GLOBAL(FocusService_guess*, 0x00988C84)
#define g_focusCallEnabled_00790118_guess EQ_GLOBAL(int, 0x00790118)
#define g_inputMode_0095a174_guess EQ_GLOBAL(unsigned char, 0x0095A174)
#define g_mouseX_00988c88_guess EQ_GLOBAL(int, 0x00988C88)
#define g_mouseY_00988c8c_guess EQ_GLOBAL(int, 0x00988C8C)
#define g_mouseFlag_00988c75_guess EQ_GLOBAL(unsigned char, 0x00988C75)
#define g_mouseZ_00988c98_guess EQ_GLOBAL(short, 0x00988C98)
#define g_mouseValue_00988c90_guess EQ_GLOBAL(int, 0x00988C90)
#define g_mouseValue_00988c94_guess EQ_GLOBAL(int, 0x00988C94)
#define g_mouseValue_009237d0_guess EQ_GLOBAL(int, 0x009237D0)
#define g_mouseValue_009237d4_guess EQ_GLOBAL(int, 0x009237D4)
#define g_mouseValue_009237d8_guess EQ_GLOBAL(int, 0x009237D8)
#define g_mouseScreenX_009237c8_guess EQ_GLOBAL(int, 0x009237C8)
#define g_mouseScreenY_009237cc_guess EQ_GLOBAL(int, 0x009237CC)
#define g_mouseChanged_00923cbc_guess EQ_GLOBAL(int, 0x00923CBC)
#define g_mouseChangedAt_00923cb4_guess EQ_GLOBAL(int, 0x00923CB4)
#define g_mouseMode_009858e9_guess EQ_GLOBAL(unsigned char, 0x009858E9)
#define g_mouseMode_009858e8_guess EQ_GLOBAL(unsigned char, 0x009858E8)
#define g_mousePending_00905d2d_guess EQ_GLOBAL(unsigned char, 0x00905D2D)
#define g_displayInput_0099e38c_guess EQ_GLOBAL(CursorDisplay_guess*, 0x0099E38C)

struct CandidateState_guess {
    char padding_0000_guess[0x160];
    void* field160_guess;
};

struct CandidateObject_guess {
    char padding_0000_guess[0x1a8];
    CandidateState_guess* field1a8_guess;
    // EXTERNAL: TITANIUM 0x0047BFD0 CandidateObject_guess::IsHorseRace_guess
    char IsHorseRace_guess();
};

struct ActorCandidate_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot0a_guess(); virtual void Slot0b_guess();
    virtual void Slot0c_guess(); virtual void Slot0d_guess();
    virtual void Slot0e_guess(); virtual void Slot0f_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void GetPosition_guess(float* position_guess);
    int padding_0004_guess[2];
    int field0c_guess;
};

struct ActorDefinitionHead_guess {
    // EXTERNAL: TITANIUM 0x0046478A ActorDefinitionHead_guess::FindByActor_guess
    ActorCandidate_guess* FindByActor_guess(ActorCandidate_guess* candidate_guess);
};

struct RenderTargetView_guess {
    // EXTERNAL: TITANIUM 0x005AE730 RenderTargetView_guess::FUN_005ae730_guess
    int FUN_005ae730_guess(int* first_guess, int* second_guess);
};

struct ContextInput_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0c_guess();
    virtual char CanInteract_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ECCC0 ContextInput_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ContextInput_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ContextInput_guess::GetText_guess
    const char* GetText_guess();
};

struct ContextObjectView_guess {
    char padding_0000_guess[8];
    ContextNode_guess* field08_guess;
    EQ_CharacterProfile_guess contextSlots_guess[0x38];
};

struct ContextActionResult_guess {
    char padding_0000_guess[0x88];
    ContextInput_guess* input_guess;
};

#define g_renderTargetView_guess EQ_GLOBAL(RenderTargetView_guess*, 0x0099D3EC)
#define g_actorDefinitionHeadView_guess EQ_GLOBAL(ActorDefinitionHead_guess*, 0x00905CC8)
#define g_contextTarget_00905ce0_guess EQ_GLOBAL(CandidateObject_guess*, 0x00905CE0)
#define g_contextObjectView_guess EQ_GLOBAL(ContextObjectView_guess*, 0x00905D00)
#define g_clockOffset_00923894_guess EQ_GLOBAL(int, 0x00923894)
#define g_left_00923778_guess EQ_GLOBAL(int, 0x00923778)
#define g_top_0092377c_guess EQ_GLOBAL(int, 0x0092377C)
#define g_right_00923780_guess EQ_GLOBAL(int, 0x00923780)
#define g_bottom_00923784_guess EQ_GLOBAL(int, 0x00923784)
#define g_clickMode_009254dc_guess EQ_GLOBAL(int, 0x009254DC)
#define g_sendDisabledView_00923798_guess EQ_GLOBAL(unsigned char, 0x00923798)

// EXTERNAL: TITANIUM 0x00439C41 TrueDistance_guess
float __stdcall TrueDistance_guess(float firstX_guess, float firstY_guess,
    float firstZ_guess, float secondX_guess, float secondY_guess,
    float secondZ_guess, float scale_guess);

// EXTERNAL: TITANIUM 0x004CCFFE CenterMouse_guess
void __cdecl CenterMouse_guess();

// Right-button release: restore the cursor after mouse look, then hit-test and dispatch a spawn click.
// FUNCTION: TITANIUM 0x004A8BA2
void GlobalState_guess::FUN_004a8ba2_guess(int x_guess, int y_guess) {
    int position_guess[2];
    int out_guess;
    int result_guess;

    if (g_clockData_guess->GetValue2cf8_guess() == 0) {
        return;
    }
    g_flag_009237b7_guess = 0;
    if (g_flag_00850508_guess == 3) {
        if (g_flag_00923842_guess != 0) {
            g_flag_00923842_guess = 0;
        }
        CenterMouse_guess();
        return;
    }
    if (g_flag_00923842_guess != 0) {
        g_flag_00923842_guess = 0;
        if ((g_globalState_guess->state_guess == 1 &&
             g_cursorInput_guess->field1e2_guess == 1) ||
            g_globalState_guess->state_guess == 5) {
            do {
                result_guess = ShowCursor(1);
            } while (result_guess < 0);
            POINT cursor_position_guess = g_cursorPosition_guess->position_guess;
            SetCursorPos(cursor_position_guess.x, cursor_position_guess.y);
        }
        if (500 < (unsigned int)(g_clockData_guess->current_guess -
                                 EQ_GLOBAL(unsigned int, 0x00923890))) {
            CenterMouse_guess();
            return;
        }
    }
    if ((g_cursorInput_guess == 0 || g_globalState_guess->state_guess != 1) &&
        g_globalState_guess->state_guess != 2) {
        if (pinstCascadeMenuList_guess != 0) {
            pinstCascadeMenuList_guess->HitTest_guess(x_guess, y_guess);
        }
        out_guess = 0;
        position_guess[0] = x_guess;
        position_guess[1] = y_guess;
        result_guess = g_renderTargetView_guess->FUN_005ae730_guess(
            position_guess, &out_guess);
        if (result_guess == 0) {
            EQPlayer* player_guess = g_globalState_guess->ClickedPlayer(x_guess, y_guess);
            if (player_guess != 0) {
                RightClickedOnPlayer(reinterpret_cast<Actor7356_guess*>(player_guess));
            }
        }
    }
}

// Left click (released within 750 ms, not in mouse look): a spawn under the cursor goes to
// LeftClickedOnPlayer; on a vehicle or with a controlled spawn it is a switch click. With an item on the
// cursor it drops it, refuses (0x3020) or asks first (popup 0x6E, eqstr 0x2361). Else a ground object
// within 20 units is clicked (OP_ClickObject 0x3BC2), else a door.
// FUNCTION: TITANIUM 0x004A91A4
// @early-stop: budget, structural ndiff=138
void GlobalState_guess::LMouseUp_guess(int x_guess, int y_guess) {
    char message_guess[512];
    int renderValues_guess[3];
    int searchFirst_guess[3];
    int searchSecond_guess[3];
    float position_guess[3];
    int packet_guess[2];

    if (g_value_009248d0_guess != 0) {
        return;
    }
    if (g_flag_00923842_guess != 0) {
        g_flag_009237b7_guess = 0;
        return;
    }
    if ((unsigned int)(g_clockData_guess->current_guess -
        g_clockOffset_00923894_guess) > 0x2eeU) {
        return;
    }
    if (pinstCCursorAttachment_guess != 0) {
        pinstCCursorAttachment_guess->Check_guess();
    }
    if (pinstCascadeMenuList_guess != 0) {
        pinstCascadeMenuList_guess->HitTest_guess(x_guess, y_guess);
    }

    int laterX_guess = x_guess;
    int laterY_guess = y_guess;
    renderValues_guess[0] = laterX_guess;
    renderValues_guess[1] = laterY_guess;
    renderValues_guess[2] = 0;
    if (g_renderTargetView_guess->FUN_005ae730_guess(renderValues_guess,
        &renderValues_guess[2]) != 0) {
        return;
    }

    typedef int (GlobalState_guess::*CandidateSearchCall_guess)(int, int);
    CandidateSearchCall_guess searchCall_guess =
        (CandidateSearchCall_guess)&GlobalState_guess::ClickedPlayer;
    CandidateObject_guess* candidate_guess = reinterpret_cast<CandidateObject_guess*>(
        (this->*searchCall_guess)(laterX_guess, laterY_guess));
    if (candidate_guess != 0) {
        if (candidate_guess->IsHorseRace_guess() != 0 &&
            candidate_guess->field1a8_guess != 0 &&
            candidate_guess->field1a8_guess->field160_guess != 0) {
            candidate_guess = reinterpret_cast<CandidateObject_guess*>(
                candidate_guess->field1a8_guess->field160_guess);
        }
        LeftClickedOnPlayer(reinterpret_cast<ActorTarget_guess*>(candidate_guess));
        return;
    }

    if (g_resetOwner_guess->pActorInfo_01a8_guess->field158_guess != 0 ||
        g_contextTarget_00905ce0_guess != 0) {
        g_globalState_guess->ClickSwitchAtScreenPos_guess(x_guess, y_guess);
        return;
    }

    ContextActionResult_guess* context_guess = reinterpret_cast<ContextActionResult_guess*>(
        g_contextObjectView_guess->contextSlots_guess[
            g_contextObjectView_guess->field08_guess->field04_guess /
                sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
    if (context_guess->input_guess != 0 &&
        laterX_guess <= g_right_00923780_guess && laterY_guess <= g_bottom_00923784_guess &&
        laterX_guess >= g_left_00923778_guess && laterY_guess >= g_top_0092377c_guess) {
        ContextActionResult_guess* modeContext_guess =
            reinterpret_cast<ContextActionResult_guess*>(
                g_contextObjectView_guess->contextSlots_guess[
                    g_contextObjectView_guess->field08_guess->field04_guess /
                        sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
        if (modeContext_guess->input_guess->GetItemClass_guess() == 0) {
            ContextActionResult_guess* actionContext_guess =
                reinterpret_cast<ContextActionResult_guess*>(
                    g_contextObjectView_guess->contextSlots_guess[
                        g_contextObjectView_guess->field08_guess->field04_guess /
                            sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
            int action_guess = actionContext_guess->input_guess->GetItemType_guess();
            // Item types 12, 33 and 39 (probably keys and lockpicks) are used on the door instead.
            if (action_guess == 0xc || action_guess == 0x21 || action_guess == 0x27) {
                g_globalState_guess->ClickSwitchAtScreenPos_guess(laterX_guess, laterY_guess);
                return;
            }
        }
        ContextActionResult_guess* inputContext_guess =
            reinterpret_cast<ContextActionResult_guess*>(
                g_contextObjectView_guess->contextSlots_guess[
                    g_contextObjectView_guess->field08_guess->field04_guess /
                        sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
        if (inputContext_guess->input_guess->CanInteract_guess(1) == 0) {
            return;
        }
        if (g_clickMode_009254dc_guess == 1) {
            g_globalState_guess->DropHeldItemOnGround(1);
            return;
        }
        if (g_clickMode_009254dc_guess == -1) {
            reinterpret_cast<CEverQuest*>(this)->dsp_chat(
                pStringTable->getString(0x3020, 0));
            return;
        }
        ContextActionResult_guess* textContext_guess =
            reinterpret_cast<ContextActionResult_guess*>(
                g_contextObjectView_guess->contextSlots_guess[
                    g_contextObjectView_guess->field08_guess->field04_guess /
                        sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
        const char* itemText_guess = textContext_guess->input_guess->GetText_guess();
        FUN_0046da4a_guess(message_guess, 0x2361, itemText_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        g_deliveryManager_guess->Activate(
            -(unsigned int)(g_globalState_guess != 0) &
                (reinterpret_cast<unsigned int>(g_globalState_guess) + 8U),
            0x6e, message_guess, 0xc, 20000, 0, 0);
        return;
    }

    unsigned char active_guess = g_clockData_guess->field11_guess;
    if (active_guess != 0) {
        if (laterX_guess <= g_right_00923780_guess &&
            laterY_guess <= g_bottom_00923784_guess &&
            laterX_guess >= g_left_00923778_guess &&
            laterY_guess >= g_top_0092377c_guess) {
            return;
        }
        if (active_guess != 0) {
            g_globalState_guess->ClickSwitchAtScreenPos_guess(laterX_guess, laterY_guess);
            return;
        }
    }

    ContextActionResult_guess* pickerContext_guess =
        reinterpret_cast<ContextActionResult_guess*>(
            g_contextObjectView_guess->contextSlots_guess[
                g_contextObjectView_guess->field08_guess->field04_guess /
                    sizeof(EQ_CharacterProfile_guess)].GetCharInfo2());
    if (pickerContext_guess->input_guess == 0) {
        if (pinstCContainerMgr_guess != 0 &&
            pinstCContainerMgr_guess->attached_06C_guess != 0) {
            return;
        }
        ActorCandidate_guess* object_guess = reinterpret_cast<ActorCandidate_guess*>(
            g_clockData_guess->PickActorAt_guess(laterX_guess, laterY_guess, 0,
                searchFirst_guess, searchSecond_guess));
        ActorCandidate_guess* selected_guess =
            g_actorDefinitionHeadView_guess->FindByActor_guess(object_guess);
        if (selected_guess != 0 && object_guess != 0) {
            object_guess->GetPosition_guess(position_guess);
            float distance_guess = TrueDistance_guess(
                g_sourceRecord_00905ce4_guess->x_guess,
                g_sourceRecord_00905ce4_guess->y_guess,
                g_sourceRecord_00905ce4_guess->z_guess,
                position_guess[0], position_guess[1], position_guess[2], 1.0f);
            if (distance_guess < 20.0f) {
                packet_guess[0] = selected_guess->field0c_guess;
                packet_guess[1] = g_sourceRecord_00905ce4_guess->field258_guess;
                ++g_value_009248d0_guess;
                ++g_value_009248d4_guess;
                if (g_sendDisabledView_00923798_guess == 0 &&
                    g_flag_00923884_guess == 0) {
                    FUN_004912b1_guess(&g_connection_00905ca0_guess,
                        0x3bc2, packet_guess, 8, 1);
                }
                pinstCInventoryWnd_guess->Activate();
                return;
            }
        }
    }
    g_globalState_guess->ClickSwitchAtScreenPos_guess(laterX_guess, laterY_guess);
}

// Per-frame mouse in char select/create (states 1, 2) and in game (5), foreground window only:
// clamps the cursor, feeds the wheel zoom, and turns button edges into window clicks or LMouseUp,
// RMouseDown and the world right click (0x4A8BA2). Ignored while feigning; a held press over 750 ms drags.
// FUNCTION: TITANIUM 0x004A9741
// @early-stop: budget, structural ndiff=291
void __cdecl ProcessMouseEvent_guess() {
    int position_guess[2];
    int frameTime_guess;
    char resetInput_guess = 0;

    if (g_globalState_guess->state_guess != 2 &&
        g_globalState_guess->state_guess != 1 &&
        g_globalState_guess->state_guess != 5) {
        return;
    }
    // Only in game states 1, 2 and 5, and only while the game window has focus.
    HWND foreground_guess = GetForegroundWindow();
    if (foreground_guess == 0 || foreground_guess != g_window_00923770_guess) {
        return;
    }
    if (g_focusCallEnabled_00790118_guess != 0) {
        ((FocusCall_guess*)g_focusService_00988c84_guess->vtable_guess)[7](
            g_focusService_00988c84_guess);
    }
    if (g_resetOwner_guess != 0 && g_globalState_guess->state_guess == 5 &&
        g_resetOwner_guess->standState_0251_guess == 'f') {
        return;
    }
    // While 0x0095A174 is set the mouse is refused: a pressed button only prints string 0x2F3F (chat
    // colour 0x111).
    if (g_inputMode_0095a174_guess != 0) {
        if (g_flag_00923877_guess == 0 && g_flag_00923876_guess == 0) {
            return;
        }
        g_globalState_guess->DspChat_guess(
            pStringTable->getString(0x2f3f, 0), 0x111, true);
        return;
    }

    frameTime_guess = FUN_0046d655_guess();
    if (g_globalState_guess->state_guess != 2 &&
        g_globalState_guess->state_guess != 1) {
        // In state 5, a character below 1 HP or with value 3 or 4 at +0x44[0xC0 + id] sets
        // resetInput_guess and clears 0x00923842: the windows still get the mouse, the game's click
        // and wheel handlers do not.
        if (g_contextObject_guess->fieldc280_guess.Cur_HP(0) < 1 ||
            g_contextObject_guess->field44_guess[
                0xc0 + g_contextObject_guess->field08_guess->field04_guess] == 3 ||
            g_contextObject_guess->field44_guess[
                0xc0 + g_contextObject_guess->field08_guess->field04_guess] == 4) {
            resetInput_guess = 1;
            if (g_flag_00923842_guess != 0) {
                g_flag_00923842_guess = 0;
            }
        }
    }

    ProcessMouseEvents_guess();
    // Read the device, then clamp the cursor to the client area.
    __int64 cursorPosition_guess = GetMouseClientPos_guess();
    int x_guess = (int)cursorPosition_guess;
    int y_guess = (int)((unsigned __int64)cursorPosition_guess >> 32);
    if (x_guess < 0) {
        x_guess = 0;
    } else if (g_displayInput_0099e38c_guess->Width_guess() - 1 < x_guess) {
        x_guess = g_displayInput_0099e38c_guess->Width_guess() - 1;
    }
    g_mouseX_00988c88_guess = x_guess;
    if (y_guess < 0) {
        y_guess = 0;
    } else if (g_displayInput_0099e38c_guess->Height_guess() - 1 < y_guess) {
        y_guess = g_displayInput_0099e38c_guess->Height_guess() - 1;
    }
    g_mouseY_00988c8c_guess = y_guess;

    if (g_flag_00923877_guess == 0) {
        if (g_mouseFlag_00988c75_guess != 0) {
            g_mouseFlag_00988c75_guess = 0;
        }
    } else if (g_mouseFlag_00988c75_guess != 0) {
        g_flag_00923877_guess = 0;
    }
    // Publish position, wheel and buttons for the frame; any movement restarts the idle timer
    // (0x00923CB4).
    g_mouseScreenX_009237c8_guess = (int)(short)g_mouseX_00988c88_guess;
    g_mouseScreenY_009237cc_guess = (int)(short)g_mouseY_00988c8c_guess;
    g_mouseValue_009237d0_guess = (int)g_mouseZ_00988c98_guess;
    g_mouseValue_009237d4_guess = g_mouseValue_00988c90_guess;
    g_mouseValue_009237d8_guess = g_mouseValue_00988c94_guess;
    if (g_value_0092386c_guess != g_mouseX_00988c88_guess ||
        g_value_00923870_guess != g_mouseY_00988c8c_guess) {
        g_mouseChanged_00923cbc_guess = 0;
        g_mouseChangedAt_00923cb4_guess = FUN_0046d655_guess();
    }
    if (resetInput_guess == 0) {
        g_globalState_guess->MouseWheelScrolled_guess(g_mouseValue_009237d0_guess);
    }

    if (g_flag_00923877_guess == 0) {
        if (g_flag_00923874_guess != 0) {
            // Left button, 0x00923877 now and 0x00923874 last frame. Released: the window manager
            // (0x0099D3EC) gets it first (end of a held press in mode 1, else a release); if no
            // window takes it, the game's LMouseUp.
            g_flag_009237b7_guess = 0;
            if (g_renderTarget_guess != 0) {
                if (g_flag_00923842_guess == 0 || resetInput_guess != 0) {
                    position_guess[0] = g_mouseX_00988c88_guess;
                    position_guess[1] = g_mouseY_00988c8c_guess;
                    int moved_guess;
                    if (g_mouseMode_009858e9_guess == 1) {
                        moved_guess = g_renderTarget_guess->FUN_005b1480_guess(position_guess);
                    } else {
                        moved_guess = g_renderTarget_guess->FUN_005b0230_guess(position_guess);
                    }
                    if (moved_guess == 0 && g_value_0092388c_guess == 0 &&
                        resetInput_guess == 0) {
                        g_globalState_guess->LMouseUp_guess(
                            g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
                    }
                } else if (g_value_0092388c_guess == 0 &&
                    g_mouseMode_009858e9_guess != 1) {
                    g_globalState_guess->LMouseUp_guess(
                        g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
                }
            }
            g_value_0092388c_guess = 0;
            g_value_00923894_guess = 0;
            g_mousePending_00905d2d_guess = 1;
        }
        g_mouseMode_009858e9_guess = 0;
    } else if (g_flag_00923874_guess != 0) {
        // Held for more than 750 ms: left mode 1, a held press, passed to the window manager
        // (0x005B0050) unless 0x00923842 is set.
        if ((unsigned int)(frameTime_guess - g_value_00923894_guess) > 0x2ee &&
            g_mouseMode_009858e9_guess == 0) {
            g_mouseMode_009858e9_guess = 1;
            if (g_flag_00923842_guess == 0 && g_renderTarget_guess != 0) {
                position_guess[0] = g_mouseX_00988c88_guess;
                position_guess[1] = g_mouseY_00988c8c_guess;
                g_renderTarget_guess->FUN_005b0050_guess(position_guess);
            }
        }
    } else {
        // Pressed this frame: note the time and offer the press to the window manager (0x005B0B80);
        // if no window takes it, the game's LMouseDown.
        g_value_00923894_guess = frameTime_guess;
        if (g_renderTarget_guess == 0) {
            if (resetInput_guess == 0) {
                reinterpret_cast<FlagSetter_guess*>(g_globalState_guess)->LMouseDown_guess(
                    g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
            }
        } else if (g_flag_00923842_guess == 0 || resetInput_guess != 0) {
            position_guess[0] = g_mouseX_00988c88_guess;
            position_guess[1] = g_mouseY_00988c8c_guess;
            int moved_guess = g_renderTarget_guess->FUN_005b0b80_guess(position_guess);
            if (moved_guess == 0 && resetInput_guess == 0) {
                reinterpret_cast<FlagSetter_guess*>(g_globalState_guess)->LMouseDown_guess(
                    g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
            }
        } else {
            reinterpret_cast<FlagSetter_guess*>(g_globalState_guess)->LMouseDown_guess(
                g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
        }
        g_mousePending_00905d2d_guess = 1;
    }

    // Right button below: the same pattern with 0x00923876 now, 0x00923875 last frame and held-press
    // mode 0x009858E8.
    g_flag_00923874_guess = g_flag_00923877_guess;
    if (g_flag_00923876_guess != 0) {
        if (g_flag_00923875_guess == 0) {
            g_value_00923890_guess = frameTime_guess;
            if (g_renderTarget_guess != 0) {
                position_guess[0] = g_mouseX_00988c88_guess;
                position_guess[1] = g_mouseY_00988c8c_guess;
                if (g_renderTarget_guess->FUN_005b03e0_guess(position_guess) != 0) {
                    g_mousePending_00905d2d_guess = 1;
                    g_flag_00923875_guess = g_flag_00923876_guess;
                    return;
                }
            }
            if (resetInput_guess == 0) {
                g_globalState_guess->RMouseDown_guess(
                    g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
            }
            g_flag_00923875_guess = g_flag_00923876_guess;
            g_mousePending_00905d2d_guess = 1;
            return;
        }
        if (g_flag_00923842_guess != 0) {
            g_flag_00923875_guess = g_flag_00923876_guess;
            return;
        }
        // Held 751 ms or more: right mode 1, passed to the window manager (0x005B0140).
        if ((unsigned int)(frameTime_guess - g_value_00923890_guess) < 0x2ef) {
            g_flag_00923875_guess = g_flag_00923876_guess;
            return;
        }
        if (g_mouseMode_009858e8_guess == 0) {
            g_mouseMode_009858e8_guess = 1;
            if (g_renderTarget_guess == 0) {
                g_flag_00923875_guess = g_flag_00923876_guess;
                g_mouseMode_009858e8_guess = 1;
                return;
            }
            position_guess[0] = g_mouseX_00988c88_guess;
            position_guess[1] = g_mouseY_00988c8c_guess;
            g_renderTarget_guess->FUN_005b0140_guess(position_guess);
            g_flag_00923875_guess = g_flag_00923876_guess;
            return;
        }
        g_flag_00923875_guess = g_flag_00923876_guess;
        return;
    }

    if (g_flag_00923875_guess == 0) {
        g_flag_00923875_guess = g_flag_00923876_guess;
        g_mouseMode_009858e8_guess = 0;
        return;
    }
    if (g_renderTarget_guess == 0) {
        // Released: the window manager ends a held press (mode 1) or takes the release (0x005B0530);
        // a release no window took goes to the game's right-click handler at 0x004A8BA2.
        if (resetInput_guess != 0) {
            g_mousePending_00905d2d_guess = 1;
            g_flag_00923875_guess = g_flag_00923876_guess;
            g_value_00923888_guess = 0;
            g_value_00923890_guess = 0;
            g_mouseMode_009858e8_guess = 0;
            return;
        }
        if (g_flag_00923842_guess == 0 && g_value_00923888_guess != 0) {
            g_mousePending_00905d2d_guess = 1;
            g_flag_00923875_guess = g_flag_00923876_guess;
            g_value_00923888_guess = 0;
            g_value_00923890_guess = 0;
            g_mouseMode_009858e8_guess = 0;
            return;
        }
    } else if (g_flag_00923842_guess == 0 || resetInput_guess != 0) {
        if (g_mouseMode_009858e8_guess == 1) {
            position_guess[0] = g_mouseX_00988c88_guess;
            position_guess[1] = g_mouseY_00988c8c_guess;
            g_renderTarget_guess->FUN_005b1580_guess(position_guess);
            g_mousePending_00905d2d_guess = 1;
            g_flag_00923875_guess = g_flag_00923876_guess;
            g_value_00923888_guess = 0;
            g_value_00923890_guess = 0;
            g_mouseMode_009858e8_guess = 0;
            return;
        }
        position_guess[0] = g_mouseX_00988c88_guess;
        position_guess[1] = g_mouseY_00988c8c_guess;
        int moved_guess = g_renderTarget_guess->FUN_005b0530_guess(position_guess);
        if (moved_guess != 0 || g_value_00923888_guess != 0 || resetInput_guess != 0) {
            g_mousePending_00905d2d_guess = 1;
            g_flag_00923875_guess = g_flag_00923876_guess;
            g_value_00923888_guess = 0;
            g_value_00923890_guess = 0;
            g_mouseMode_009858e8_guess = 0;
            return;
        }
    }
    g_globalState_guess->FUN_004a8ba2_guess(
        g_mouseX_00988c88_guess, g_mouseY_00988c8c_guess);
    g_mousePending_00905d2d_guess = 1;
    g_flag_00923875_guess = g_flag_00923876_guess;
    g_value_00923888_guess = 0;
    g_value_00923890_guess = 0;
    g_mouseMode_009858e8_guess = 0;
}
// EXTERNAL: TITANIUM 0x004CC73F PumpMessages_guess
void __cdecl PumpMessages_guess(int value_guess);
// EXTERNAL: TITANIUM 0x004CECC7 ProcessKeyboardEvents_guess
void __cdecl ProcessKeyboardEvents_guess();

// Per-frame input: mouse, keyboard (0x4CC73F), 0x4CECC7 unless 0x99D3F8 is set, then the activity
// report (SendInactivityStatus 0x491721).
// FUNCTION: TITANIUM 0x004A9C84
int __cdecl ProcessGameEvents() {
    ProcessMouseEvent_guess();
    PumpMessages_guess(-1);
    if (g_value_0099d3f8_guess == 0) {
        ProcessKeyboardEvents_guess();
    }
    SendInactivityStatus_guess();
    return 0;
}

#define g_value_00905ca4_guess EQ_GLOBAL(int, 0x00905CA4)

// ProcessGameEvents plus a display update (0x445A6C) with 0x905CA4 set, which SavePC checks.
// FUNCTION: TITANIUM 0x004A9CA7
void __cdecl ProcessGameEventsAndRender_guess() {
    if (g_ownedDisplay_guess != 0) {
        g_value_00905ca4_guess = 1;
        ProcessGameEvents();
        g_ownedDisplay_guess->Render_World_guess();
        g_value_00905ca4_guess = 0;
    }
}

struct Owner_guess {
    char padding_0000_guess[0x4C];
    float field4c_guess;
    // EXTERNAL: TITANIUM 0x0047A523 Owner_guess::GetHairKind_guess
    char GetHairKind_guess();
};

struct IndexedEffect_guess {
    virtual void RefreshCounts_guess() = 0; virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0; virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0; virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0; virtual void Slot07_guess() = 0;
    virtual void SetValue_guess(float value_guess) = 0;
    virtual float GetValue_guess() = 0;
};

struct WindowPipeline_guess {
    char padding_0000_guess[0x74];
    unsigned int field74_guess;
    unsigned int field78_guess;
    // EXTERNAL: TITANIUM 0x005AF6A0 WindowPipeline_guess::FUN_005af6a0_guess
    void FUN_005af6a0_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x005B06A0 WindowPipeline_guess::FUN_005b06a0_guess
    void FUN_005b06a0_guess();
    // EXTERNAL: TITANIUM 0x005AF250 WindowPipeline_guess::FUN_005af250_guess
    void FUN_005af250_guess();
    // EXTERNAL: TITANIUM 0x005AF580 WindowPipeline_guess::FUN_005af580_guess
    void FUN_005af580_guess();
};

struct BoundsPair_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    // EXTERNAL: TITANIUM 0x00491002 BoundsPair_guess::Contains_guess
    char Contains_guess(const BoundsPair_guess* other_guess);
};

#define g_loopClock_00905d24_guess EQ_GLOBAL(DisplayRoot_guess*, 0x00905D24)
#define g_loopTarget_00905ce4_guess EQ_GLOBAL(Owner_guess*, 0x00905CE4)
#define g_loopSelector_00850ccc_guess EQ_GLOBAL(unsigned int, 0x00850CCC)
#define g_loopEffects_009254fc_guess EQ_ARRAY(IndexedEffect_guess*, 0x009254FC)
#define g_loopPipeline_0099d3ec_guess EQ_GLOBAL(WindowPipeline_guess*, 0x0099D3EC)
#define g_loopDisplay_0099e364_guess EQ_GLOBAL(DisplayInterface_guess*, 0x0099E364)
#define g_loopRenderValueA_009237c8_guess EQ_GLOBAL(unsigned int, 0x009237C8)
#define g_loopRenderValueB_009237cc_guess EQ_GLOBAL(unsigned int, 0x009237CC)

// EXTERNAL: TITANIUM 0x004CCFB7 FlushMouse_guess
int __cdecl FlushMouse_guess();
// EXTERNAL: TITANIUM 0x004CCB85 FlushKeyboard_guess
int __cdecl FlushKeyboard_guess();

// Character-creation frame loop (game state 2, run from char select): input, network pump, disconnect
// check, camera nudge every 50 ms, UI and render, 10 ms sleep. Ends when the state changes or the window
// sets +0x418.
// FUNCTION: TITANIUM 0x004A9CD2
// @early-stop: budget, structural ndiff=32
void GlobalState_guess::RunCharacterSelectLoop_guess() {
    unsigned int lastUpdate_guess = 0;
    g_globalState_guess->SetGameState(2);
    pinstCCharacterCreation_guess->Reset_guess();
    pinstCCharacterCreation_guess->Show(1, 1);
    FlushMouse_guess();
    FlushKeyboard_guess();
    if (state_guess != 2) {
        pinstCCharacterCreation_guess->Deactivate();
        return;
    }
    do {
        g_flag_00923842_guess = 0;
        ProcessGameEvents();
        reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
        if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x3e9f, 1) != 0) {
            pinstCCharacterCreation_guess->Deactivate();
            return;
        }
        unsigned int updateTick_guess = g_loopClock_00905d24_guess->field148_guess;
        if (lastUpdate_guess < updateTick_guess) {
            lastUpdate_guess = updateTick_guess + 0x32;
            if (pinstCFacePick_guess->IsVisible_guess() == 0 ||
                pinstCFacePick_guess->field_1C0_guess != 2) {
                g_loopEffects_009254fc_guess[g_loopSelector_00850ccc_guess]->SetValue_guess(
                    g_loopTarget_00905ce4_guess->field4c_guess);
            } else {
                g_loopClock_00905d24_guess->SetupCharacterViewCamera_guess(2);
                if (reinterpret_cast<Owner_guess*>(g_resetOwner_guess)->GetHairKind_guess() == 1) {
                    IndexedEffect_guess* effect_guess = g_loopEffects_009254fc_guess[
                        g_loopSelector_00850ccc_guess];
                    float effectValue_guess = effect_guess->GetValue_guess();
                    effect_guess->SetValue_guess(effectValue_guess + 1.5f);
                }
            }
        }
        WindowPipeline_guess* pipeline_guess = g_loopPipeline_0099d3ec_guess;
        if (pipeline_guess != 0) {
            if (g_flag_00923842_guess == 0) {
                BoundsPair_guess sourceBounds_guess;
                BoundsPair_guess targetBounds_guess;
                sourceBounds_guess.first_guess = g_loopRenderValueA_009237c8_guess;
                sourceBounds_guess.second_guess = g_loopRenderValueB_009237cc_guess;
                targetBounds_guess.first_guess = pipeline_guess->field74_guess;
                targetBounds_guess.second_guess = pipeline_guess->field78_guess;
                if (targetBounds_guess.Contains_guess(&sourceBounds_guess) == 0) {
                    pipeline_guess->FUN_005af6a0_guess(&sourceBounds_guess);
                }
            }
            pipeline_guess->FUN_005b06a0_guess();
            pipeline_guess->FUN_005af250_guess();
            if (g_flag_00923842_guess == 0) {
                pipeline_guess->FUN_005af580_guess();
            }
        }
        g_loopDisplay_0099e364_guess->Slot37_guess();
        g_loopClock_00905d24_guess->Render_MinWorld_guess();
        if (pinstCCharacterCreation_guess->field_418_guess != 0) {
            pinstCCharacterCreation_guess->field_418_guess = 0;
            pinstCCharacterCreation_guess->Deactivate();
            return;
        }
        Sleep(10);
    } while (state_guess == 2);
    pinstCCharacterCreation_guess->Deactivate();
}

struct ResetTarget_guess {
    // EXTERNAL: TITANIUM 0x00408410 ResetTarget_guess::FUN_00408410_guess
    void FUN_00408410_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00408672 ResetTarget_guess::RequestAdventureInfo_guess
    void RequestAdventureInfo_guess(struct Actor7356_guess* actor_guess);
};

struct CacheOwner_guess {
    // EXTERNAL: TITANIUM 0x004C9BA7 CacheOwner_guess::FUN_004c9ba7_guess
    void FUN_004c9ba7_guess();
    // EXTERNAL: TITANIUM 0x004C9BC9 CacheOwner_guess::ClearKnowledgeBase_guess
    void ClearKnowledgeBase_guess();
};

struct FontProvider_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void SetFont_guess(int language_guess, int index_guess, const char* name_guess);
    virtual const char* DefaultFont_guess(int language_guess, int index_guess);
};

struct CharSelect_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void MakeHotButton_guess();
    virtual void Hide_guess();
    char padding_0004_guess[0x1DD];
    unsigned char field1e1_guess; // 0x1E1
    unsigned char field1e2_guess; // 0x1E2
    char padding_01e3_guess[1];
    unsigned char field1e4_guess; // 0x1E4
    char padding_01e5_guess[3];
    int selected_guess; // 0x1E8
    int quit_guess; // 0x1EC
    int enterWorld_guess; // 0x1F0
    int field1f4_guess; // 0x1F4
    unsigned char field1f8_guess; // 0x1F8
    // EXTERNAL: TITANIUM 0x004F18FF CharSelect_guess::LeaveExplorationMode_guess
    void LeaveExplorationMode_guess();
    // EXTERNAL: TITANIUM 0x004F14F0 CharSelect_guess::FUN_004f14f0_guess
    void FUN_004f14f0_guess();
    // EXTERNAL: TITANIUM 0x004F0E72 CharSelect_guess::FUN_004f0e72_guess
    int FUN_004f0e72_guess();
    // EXTERNAL: TITANIUM 0x004F0D1D CharSelect_guess::FUN_004f0d1d_guess
    const char* FUN_004f0d1d_guess();
};

struct LoopDispatch_guess {
    // EXTERNAL: TITANIUM 0x0044A63A LoopDispatch_guess::ProcessSound_guess
    void ProcessSound_guess();
};

struct PopupItem_guess {
    // EXTERNAL: TITANIUM 0x0040812F PopupItem_guess::DisplayText
    void DisplayText(char* text_guess, int width_guess, int height_guess,
        int color_guess, int firstTime_guess, int secondTime_guess, int duration_guess);
};

// EXTERNAL: TITANIUM 0x00407DC9 FUN_00407dc9_guess
PopupItem_guess* __cdecl FUN_00407dc9_guess();
// EXTERNAL: TITANIUM 0x004CD479 AcquireMouse_guess
void __cdecl AcquireMouse_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
int __cdecl FUN_0060beb0_guess(const char* section_guess, const char* key_guess,
    const char* value_guess, const char* file_guess);

// EXTERNAL: TITANIUM 0x004B9096 CreateItemTintTable_guess
void __cdecl CreateItemTintTable_guess();
// EXTERNAL: TITANIUM 0x004B905F CreateNpcTintTable_guess
void __cdecl CreateNpcTintTable_guess();
// EXTERNAL: TITANIUM 0x004B6C71 FUN_004b6c71_guess
void __cdecl FUN_004b6c71_guess();
// EXTERNAL: TITANIUM 0x0044E66E LoadSpellEffects_guess
void __cdecl LoadSpellEffects_guess();
// EXTERNAL: TITANIUM 0x00576B70 FUN_00576b70_guess
int __cdecl FUN_00576b70_guess(const char* section_guess, const char* key_guess,
    int fallback_guess, const char* file_guess);

// EXTERNAL: TITANIUM 0x006495C8 ??_7ObjectKindA_guess@@6B@
struct ObjectKindA_guess : ObjectBase_guess {
    virtual void Slot000_guess();
};

// EXTERNAL: TITANIUM 0x00649608 ??_7ObjectKindB_guess@@6B@
struct ObjectKindB_guess : ObjectBase_guess {
    virtual void Slot000_guess();
};

// EXTERNAL: TITANIUM 0x00649648 ??_7ObjectKindC_guess@@6B@
struct ObjectKindC_guess : ObjectBase_guess {
    virtual void Slot000_guess();
};

// EXTERNAL: TITANIUM 0x00649688 ??_7ObjectKindD_guess@@6B@
struct ObjectKindD_guess : ObjectBase_guess {
    virtual void Slot000_guess();
};

// EXTERNAL: TITANIUM 0x006496C8 ??_7ObjectKindE_guess@@6B@
struct ObjectKindE_guess : ObjectBase_guess {
    virtual void Slot000_guess();
};

#define pinstProjectileCamera_guess EQ_GLOBAL(ObjectSlot_guess*, 0x0092551C)

// Builds CEverQuest: the 0x7EF4-byte buffer at 0x924830, the camera objects (0x9254FC..0x92551C)
// and defaults, then the [Defaults] options of eqclient.ini (InspectOthers, ShowSpellEffects, the hit
// windows ...); a missing option ('*NULL*') is written back with its default.
// FUNCTION: TITANIUM 0x004A3341
// @early-stop: budget, structural ndiff=400
CEverQuest_guess::CEverQuest_guess(int window_guess) {
    int value_guess;
    int mixAhead_guess;
    char buffer_guess[0x20];
    int index_guess;

    BackupMilesSoundSystemFiles_guess();
    // A 0x7EF4-byte raw text buffer with its cursor pointers (0x00924830..0x00924844); on failure they stay
    // 0.
    EQ_GLOBAL(int, 0x00924834) = 0x7ef4;
    EQ_GLOBAL(int, 0x00924830) = (int)malloc(EQ_GLOBAL(int, 0x00924834));
    if (EQ_GLOBAL(int, 0x00924830) == 0) {
        FUN_00574110_guess("ERROR: Unable to allocate memory for raw text buffer!\n");
        EQ_GLOBAL(int, 0x0092483C) = 0;
        EQ_GLOBAL(int, 0x00924844) = 0;
        EQ_GLOBAL(int, 0x00924840) = 0;
        EQ_GLOBAL(int, 0x00924838) = 0;
    } else {
        EQ_GLOBAL(int, 0x0092483C) = EQ_GLOBAL(int, 0x00924830) + 4;
        EQ_GLOBAL(int, 0x00924844) = EQ_GLOBAL(int, 0x00924830);
        EQ_GLOBAL(int, 0x00924840) = EQ_GLOBAL(int, 0x0092483C);
        memset((void*)EQ_GLOBAL(int, 0x00924830), 0, EQ_GLOBAL(int, 0x00924834));
        EQ_GLOBAL(int, 0x00924838) = EQ_GLOBAL(int, 0x00924830) + EQ_GLOBAL(int, 0x00924834);
    }
    field294_guess = 0;
    g_owned_0079dbd4_guess = new Owned424982_guess();
    // Chat channels to rejoin come from AutoChannels.txt; the log file name defaults to log.txt.
    g_owned_0079dbd4_guess->LoadAutoJoinChannels_guess("AutoChannels.txt");
    EQ_GLOBAL(int, 0x00905CE4) = 0;
    EQ_GLOBAL(int, 0x00905D00) = 0;
    field17bac_guess = 0;
    field17bb0_guess = 0;
    for (index_guess = 0; index_guess < 0x200; index_guess++) {
        entries_guess[index_guess].id_guess = -1;
        entries_guess[index_guess].field04_guess = 0;
        entries_guess[index_guess].field08_guess = 0;
        entries_guess[index_guess].field0c_guess = 0;
        entries_guess[index_guess].text10_guess[0] = 0;
        entries_guess[index_guess].text30_guess[0] = 0;
        entries_guess[index_guess].text74_guess[0] = 0;
    }
    EQ_GLOBAL(ObjectHolder_guess*, 0x009254FC) = new ObjectHolder_guess();
    EQ_GLOBAL(ObjectKindA_guess*, 0x00925500) = new ObjectKindA_guess();
    EQ_GLOBAL(ObjectKindB_guess*, 0x00925504) = new ObjectKindB_guess();
    EQ_GLOBAL(ObjectKindC_guess*, 0x00925508) = new ObjectKindC_guess();
    EQ_GLOBAL(ObjectKindC_guess*, 0x0092550C) = new ObjectKindC_guess();
    EQ_GLOBAL(ObjectKindD_guess*, 0x00925514) = new ObjectKindD_guess();
    EQ_GLOBAL(ObjectKindE_guess*, 0x00925510) = new ObjectKindE_guess();
    EQ_GLOBAL(ObjectKindC_guess*, 0x00925518) = new ObjectKindC_guess();
    pinstProjectileCamera_guess = new ObjectSlot_guess();
    EQ_GLOBAL(int, 0x0092386C) = -1;
    EQ_GLOBAL(int, 0x00923870) = -1;
    EQ_GLOBAL(char, 0x00985885) = 0;
    EQ_GLOBAL(char, 0x00985845) = 0;
    EQ_GLOBAL(int, 0x00924790) = 0;
    EQ_GLOBAL(int, 0x00924794) = 0;
    EQ_GLOBAL(int, 0x00924798) = 0;
    EQ_GLOBAL(int, 0x0092479C) = 0;
    EQ_GLOBAL(int, 0x009247A0) = 0;
    EQ_GLOBAL(int, 0x009247A4) = 0;
    EQ_GLOBAL(int, 0x009247A8) = 0;
    EQ_GLOBAL(int, 0x009247AC) = 0;
    EQ_GLOBAL(int, 0x009247B0) = 0;
    EQ_GLOBAL(int, 0x009247B8) = 0;
    EQ_GLOBAL(int, 0x009247BC) = 0;
    EQ_GLOBAL(char, 0x00923874) = 0;
    EQ_GLOBAL(char, 0x00923875) = 0;
    EQ_GLOBAL(char, 0x00923877) = 0;
    EQ_GLOBAL(char, 0x00923876) = 0;
    EQ_GLOBAL(int, 0x00924850) = 0;
    EQ_GLOBAL(int, 0x00924854) = 0;
    EQ_GLOBAL(char, 0x0095A174) = 0;
    field39ab8_guess = 0;
    field39aba_guess[0] = 0;
    field39cba_guess[0] = 0;
    strcpy(field3a0ba_guess, "log.txt");
    field3a1ba_guess = 0;
    strcpy(EQ_ARRAY(char, 0x00923D98), EQ_ARRAY(char, 0x00649F18));
    EQ_GLOBAL(float, 0x00985810) = 1.0f;
    EQ_GLOBAL(float, 0x00985814) = 1.0f;
    EQ_GLOBAL(int, 0x0098581C) = 0x18;
    EQ_GLOBAL(int, 0x0098582C) = 0x18;
    EQ_GLOBAL(float, 0x00985818) = 2.0f;
    EQ_GLOBAL(int, 0x0098583C) = 0x18;
    EQ_GLOBAL(int, 0x00924198) = 1;
    EQ_GLOBAL(char, 0x0092419C) = 0;
    EQ_GLOBAL(float, 0x00985820) = 1.0f;
    EQ_GLOBAL(int, 0x0092485C) = 0;
    EQ_GLOBAL(char, 0x00985808) = 0;
    EQ_GLOBAL(char, 0x0095D3D4) = 0;
    EQ_GLOBAL(float, 0x00985824) = 1.0f;
    EQ_GLOBAL(float, 0x00985828) = 2.0f;
    EQ_GLOBAL(float, 0x00985830) = 1.0f;
    EQ_GLOBAL(float, 0x00985834) = 1.0f;
    EQ_GLOBAL(float, 0x00985838) = 2.0f;
    field00c_guess[0] = 0;
    field190_guess[0] = 0;
    field08c_guess = 0;
    field090_guess[0] = 0;
    field290_guess = 0;
    field2a0_guess = 0;
    field2a1_guess[0] = 0;
    memset(field3a1_guess, 0, 0x1e0);
    memset(field584_guess, 0, 0x28);
    field5ac_guess = 0;
    field298_guess = 0;
    field29c_guess = 0;
    field5b0_guess[0] = 0;
    field734_guess[0] = 0;
    field630_guess = 0;
    field634_guess[0] = 0;
    field834_guess = 0;
    field840_guess = 0;
    field841_guess[0] = 0;
    memset(field941_guess, 0, 0x1e0);
    memset(fieldb24_guess, 0, 0x28);
    fieldb5c_guess = 0.0f;
    fieldb4c_guess = 0;
    field838_guess = 0;
    field83c_guess = 0;
    field3a1c4_guess = 0;
    fieldb60_guess = 0;
    field3a1bb_guess = 0;
    EQ_GLOBAL(int, 0x00905CB0) = 0;
    LoadStringTables_guess();
    // eqclient.ini [Defaults]: "*NULL*" marks a missing key, which is written back with its default, so the
    // file fills itself in. T, t or 1 means true.
    FUN_00574110_guess("Initializing client variables.");
    CreateItemTintTable_guess();
    CreateNpcTintTable_guess();
    FUN_004b6c71_guess();

    FUN_0060be50_guess("Defaults", "InspectOthers", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "InspectOthers", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924848) = value_guess;

    FUN_0060be50_guess("Defaults", EQ_ARRAY(char, 0x00649EF4), "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", EQ_ARRAY(char, 0x00649EF4), "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924788) = value_guess;

    FUN_0060be50_guess("Defaults", "AttackOnAssist", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "AttackOnAssist", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247C0) = value_guess;

    FUN_0060be50_guess("Defaults", "ShowInspectMessage", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "ShowInspectMessage", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247C4) = value_guess;

    FUN_0060be50_guess("Defaults", "LockWindows", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "LockWindows", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247E8) = value_guess;

    FUN_0060be50_guess("Defaults", "InvWinLabels", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "InvWinLabels", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247C8) = value_guess;

    FUN_0060be50_guess("Defaults", "HidePlayerWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HidePlayerWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247EC) = value_guess;

    FUN_0060be50_guess("Defaults", "HidePartyWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HidePartyWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247F0) = value_guess;

    FUN_0060be50_guess("Defaults", "HideTargetWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideTargetWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247F4) = value_guess;

    FUN_0060be50_guess("Defaults", "HideSpellsWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideSpellsWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247F8) = value_guess;

    FUN_0060be50_guess("Defaults", "HideBuffWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideBuffWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009247FC) = value_guess;

    FUN_0060be50_guess("Defaults", "HideHotboxWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideHotboxWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924800) = value_guess;

    FUN_0060be50_guess("Defaults", "HideChatWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideChatWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924804) = value_guess;

    FUN_0060be50_guess("Defaults", "HideMainMenuWin", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "HideMainMenuWin", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924808) = value_guess;

    EQ_GLOBAL(int, 0x0092480C) = 1;
    EQ_GLOBAL(int, 0x00924810) = 1;
    EQ_GLOBAL(int, 0x00924814) = 1;

    FUN_0060be50_guess("Defaults", "ChatLineSpacing", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        EQ_GLOBAL(int, 0x0092391C) = 0;
        FUN_0060beb0_guess("Defaults", "ChatLineSpacing", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    } else {
        EQ_GLOBAL(int, 0x0092391C) = atoi(buffer_guess);
    }

    FUN_0060be50_guess("Defaults", "ShowDynamicLights", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "ShowDynamicLights", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924818) = value_guess;

    FUN_0060be50_guess("Defaults", "ChatFontSize", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        EQ_GLOBAL(int, 0x0092481C) = 1;
        FUN_0060beb0_guess("Defaults", "ChatFontSize", EQ_ARRAY(char, 0x00645EAC), ".\\eqclient.ini");
    } else {
        EQ_GLOBAL(int, 0x0092481C) = atoi(buffer_guess);
    }

    FUN_0060be50_guess("Defaults", "ShowNamesLevel", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924860) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924860) > 6) {
        EQ_GLOBAL(int, 0x00924860) = 4;
        FUN_0060beb0_guess("Defaults", "ShowNamesLevel", EQ_ARRAY(char, 0x00645EA8), ".\\eqclient.ini");
    }

    // [HitsMode]: the floating combat-text settings for my hits, others hitting me and others hitting others;
    // an out-of-range number is replaced by the default.
    FUN_0060be50_guess("HitsMode", "MyHitsMode", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924864) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924864) > 5) {
        EQ_GLOBAL(int, 0x00924864) = 1;
        FUN_0060beb0_guess("HitsMode", "MyHitsMode", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsAlwaysDraw", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924884) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924884) > 1) {
        EQ_GLOBAL(int, 0x00924884) = 0;
        FUN_0060beb0_guess("HitsMode", "MyHitsAlwaysDraw", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsX", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924868) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924868) > 0x640) {
        EQ_GLOBAL(int, 0x00924868) = 4;
        FUN_0060beb0_guess("HitsMode", "MyHitsX", EQ_ARRAY(char, 0x00645EA8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsY", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x0092486C) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x0092486C) > 0x4b0) {
        EQ_GLOBAL(int, 0x0092486C) = 0x3c;
        FUN_0060beb0_guess("HitsMode", "MyHitsY", EQ_ARRAY(char, 0x00649E38), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsCount", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924870) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x00924870) > 10) {
        EQ_GLOBAL(int, 0x00924870) = 3;
        FUN_0060beb0_guess("HitsMode", "MyHitsCount", EQ_ARRAY(char, 0x00645EAC), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsFontSize", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924874) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924874) > 2) {
        EQ_GLOBAL(int, 0x00924874) = 1;
        FUN_0060beb0_guess("HitsMode", "MyHitsFontSize", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsShowHeader", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924878) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924878) > 1) {
        EQ_GLOBAL(int, 0x00924878) = 1;
        FUN_0060beb0_guess("HitsMode", "MyHitsShowHeader", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsShowBG", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x0092487C) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x0092487C) > 1) {
        EQ_GLOBAL(int, 0x0092487C) = 0;
        FUN_0060beb0_guess("HitsMode", "MyHitsShowBG", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "MyHitsBGWidth", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924880) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x00924880) > 0x640) {
        EQ_GLOBAL(int, 0x00924880) = 0x14a;
        FUN_0060beb0_guess("HitsMode", "MyHitsBGWidth", EQ_ARRAY(char, 0x00649DE4), ".\\eqclient.ini");
    }

    FUN_0060be50_guess("HitsMode", "OtherHitsMeMode", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924888) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924888) > 4) {
        EQ_GLOBAL(int, 0x00924888) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeMode", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeAlwaysDraw", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248A8) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248A8) > 1) {
        EQ_GLOBAL(int, 0x009248A8) = 0;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeAlwaysDraw", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeX", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x0092488C) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x0092488C) > 0x640) {
        EQ_GLOBAL(int, 0x0092488C) = 4;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeX", EQ_ARRAY(char, 0x00645EA8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeY", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924890) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924890) > 0x4b0) {
        EQ_GLOBAL(int, 0x00924890) = 0x70;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeY", EQ_ARRAY(char, 0x00649D98), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeCount", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924894) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x00924894) > 10) {
        EQ_GLOBAL(int, 0x00924894) = 3;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeCount", EQ_ARRAY(char, 0x00645EAC), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeFontSize", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924898) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924898) > 2) {
        EQ_GLOBAL(int, 0x00924898) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeFontSize", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeShowHeader", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x0092489C) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x0092489C) > 1) {
        EQ_GLOBAL(int, 0x0092489C) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeShowHeader", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeShowBG", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248A0) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248A0) > 1) {
        EQ_GLOBAL(int, 0x009248A0) = 0;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeShowBG", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsMeBGWidth", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248A4) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x009248A4) > 0x640) {
        EQ_GLOBAL(int, 0x009248A4) = 0x14a;
        FUN_0060beb0_guess("HitsMode", "OtherHitsMeBGWidth", EQ_ARRAY(char, 0x00649DE4), ".\\eqclient.ini");
    }

    FUN_0060be50_guess("HitsMode", "OtherHitsOtherMode", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248AC) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248AC) > 4) {
        EQ_GLOBAL(int, 0x009248AC) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherMode", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherAlwaysDraw", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248CC) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248CC) > 1) {
        EQ_GLOBAL(int, 0x009248CC) = 0;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherAlwaysDraw", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherX", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248B0) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248B0) > 0x640) {
        EQ_GLOBAL(int, 0x009248B0) = 4;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherX", EQ_ARRAY(char, 0x00645EA8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherY", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248B4) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248B4) > 0x4b0) {
        EQ_GLOBAL(int, 0x009248B4) = 0xa4;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherY", EQ_ARRAY(char, 0x00649CDC), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherCount", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248B8) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x009248B8) > 10) {
        EQ_GLOBAL(int, 0x009248B8) = 3;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherCount", EQ_ARRAY(char, 0x00645EAC), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherFontSize", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248BC) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248BC) > 2) {
        EQ_GLOBAL(int, 0x009248BC) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherFontSize", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherShowHeader", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248C0) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248C0) > 1) {
        EQ_GLOBAL(int, 0x009248C0) = 1;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherShowHeader", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherShowBG", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248C4) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009248C4) > 1) {
        EQ_GLOBAL(int, 0x009248C4) = 0;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherShowBG", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("HitsMode", "OtherHitsOtherBGWidth", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009248C8) = atoi(buffer_guess)) < 1 ||
        EQ_GLOBAL(int, 0x009248C8) > 0x640) {
        EQ_GLOBAL(int, 0x009248C8) = 0x14a;
        FUN_0060beb0_guess("HitsMode", "OtherHitsOtherBGWidth", EQ_ARRAY(char, 0x00649DE4), ".\\eqclient.ini");
    }
    EQ_GLOBAL(int, 0x00924864) = 1;
    EQ_GLOBAL(int, 0x00924888) = 1;
    EQ_GLOBAL(int, 0x009248AC) = 1;

    // Back to [Defaults]: video, mouse, effects, music, tracking window, language, grass, camera, NetStat.
    FUN_0060be50_guess("Defaults", "VideoMode", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x00924820) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x00924820) > 4) {
        EQ_GLOBAL(int, 0x00924820) = 0;
        FUN_0060beb0_guess("Defaults", "VideoMode", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("Defaults", "MousePointerSpeedMod", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009237E0) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009237E0) > 10) {
        EQ_GLOBAL(int, 0x009237E0) = 0;
        FUN_0060beb0_guess("Defaults", "MousePointerSpeedMod", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }
    FUN_0060be50_guess("Defaults", "ShowSpellEffects", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x0092484C) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x0092484C) > 1) {
        EQ_GLOBAL(int, 0x0092484C) = 1;
        FUN_0060beb0_guess("Defaults", "ShowSpellEffects", EQ_ARRAY(char, 0x00645EB4), ".\\eqclient.ini");
    }

    FUN_0060be50_guess("Defaults", "CombatMusic", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "CombatMusic", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x009248D8) = value_guess;

    FUN_0060be50_guess("Defaults", "MixAhead", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        mixAhead_guess = 8;
        FUN_0060beb0_guess("Defaults", "MixAhead", EQ_ARRAY(char, 0x00645E94), ".\\eqclient.ini");
    } else {
        mixAhead_guess = atoi(buffer_guess);
    }
    EQ_GLOBAL(int, 0x009248DC) = mixAhead_guess;

    FUN_0060be50_guess("Defaults", "ServerFilter", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*' || (EQ_GLOBAL(int, 0x009237E4) = atoi(buffer_guess)) < 0 ||
        EQ_GLOBAL(int, 0x009237E4) > 1) {
        EQ_GLOBAL(int, 0x009237E4) = 0;
        FUN_0060beb0_guess("Defaults", "ServerFilter", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    }

    FUN_0060be50_guess("Defaults", "TrackPlayers", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "TrackPlayers", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else if (buffer_guess[0] == 'G' || buffer_guess[0] == 'g' || buffer_guess[0] == '2') {
        value_guess = 2;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00923CA8) = value_guess;

    FUN_0060be50_guess("Defaults", "TrackSortType", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 0;
        FUN_0060beb0_guess("Defaults", "TrackSortType", "NORMAL", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'N' || buffer_guess[0] == 'n' || buffer_guess[0] == '0') {
        value_guess = 0;
    } else if (buffer_guess[0] == 'D' || buffer_guess[0] == 'd' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else if (buffer_guess[0] == 'C' || buffer_guess[0] == 'c' || buffer_guess[0] == '2') {
        value_guess = 2;
    } else if (buffer_guess[0] == 'R' || buffer_guess[0] == 'r') {
        if (buffer_guess[1] == 'D' || buffer_guess[1] == 'd') {
            value_guess = 3;
        } else if (buffer_guess[1] == 'C' || buffer_guess[1] == 'c') {
            value_guess = 4;
        }
    } else if (buffer_guess[0] == '3') {
        value_guess = 3;
    } else if (buffer_guess[0] == '4') {
        value_guess = 4;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00923CAC) = value_guess;

    FUN_0060be50_guess("Defaults", "TrackFilterType", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        EQ_GLOBAL(int, 0x00923CB0) = 0;
        FUN_0060beb0_guess("Defaults", "TrackFilterType", EQ_ARRAY(char, 0x006410A8), ".\\eqclient.ini");
    } else {
        EQ_GLOBAL(int, 0x00923CB0) = atoi(buffer_guess);
    }

    EQ_GLOBAL(int, 0x009237F0) =
        reinterpret_cast<GlobalState_guess*>(this)->ReadClientIniInt_guess("Defaults", "DefaultLanguage", 0);
    reinterpret_cast<GlobalState_guess*>(this)->FUN_004ae514_guess(EQ_GLOBAL(int, 0x009237F0),
        "Defaults", "DefaultLanguage");

    FUN_0060be50_guess("Defaults", "ShowGrass", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        value_guess = 1;
        FUN_0060beb0_guess("Defaults", "ShowGrass", "TRUE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        value_guess = 1;
    } else {
        value_guess = 0;
    }
    EQ_GLOBAL(int, 0x00924824) = value_guess;
    EQ_GLOBAL(int, 0x00924828) = 0;
    EQ_GLOBAL(float, 0x0092482C) = 200.0f;

    FUN_0060be50_guess("Defaults", "UseArrowCamera", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        EQ_GLOBAL(char, 0x009858C6) = 0;
        FUN_0060beb0_guess("Defaults", "UseArrowCamera", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 'T' || buffer_guess[0] == 't' || buffer_guess[0] == '1') {
        EQ_GLOBAL(char, 0x009858C6) = 0;
    } else {
        EQ_GLOBAL(char, 0x009858C6) = 0;
    }

    FUN_0060be50_guess("Defaults", "NetStat", "*NULL*", buffer_guess, 0x20, ".\\eqclient.ini");
    if (buffer_guess[0] == '*') {
        EQ_GLOBAL(char, 0x00923844) = 0;
        FUN_0060beb0_guess("Defaults", "NetStat", "FALSE", ".\\eqclient.ini");
    } else if (buffer_guess[0] == 't' || buffer_guess[0] == 'T') {
        EQ_GLOBAL(char, 0x00923844) = 1;
    } else {
        EQ_GLOBAL(char, 0x00923844) = 0;
    }

    // Session state the zone handlers use later starts out cleared.
    EQ_GLOBAL(int, 0x0092387C) = -1;
    EQ_GLOBAL(int, 0x0092378C) = 0;
    EQ_GLOBAL(int, 0x00923D58) = 0;
    EQ_GLOBAL(int, 0x00923D60) = 0;
    EQ_GLOBAL(int, 0x00923D5C) = 0;
    EQ_GLOBAL(char, 0x00923D64) = 0;
    EQ_GLOBAL(char, 0x00923D65) = 0;
    EQ_GLOBAL(char, 0x00923D7C) = 1;
    EQ_GLOBAL(char, 0x00923D66) = 0;
    char* name_guess = EQ_ARRAY(char, 0x00925920);
    do {
        *name_guess = 0;
        name_guess += 0x40;
    } while ((int)name_guess < (int)EQ_ARRAY(char, 0x009265A0));
    EQ_GLOBAL(int, 0x00923CC4) = -1;
    EQ_GLOBAL(int, 0x009265A0) = 0;
    EQ_GLOBAL(int, 0x00923794) = 0;
    EQ_GLOBAL(int, 0x00923880) = 0;
    EQ_GLOBAL(int, 0x00923884) = 0;
    EQ_GLOBAL(char, 0x00923798) = 0;
    EQ_GLOBAL(int, 0x00923D28) = 0;
    EQ_GLOBAL(char, 0x00923CC0) = 0;
    EQ_GLOBAL(int, 0x00923CC8) = 0;
    EQ_GLOBAL(int, 0x00923CCC) = 0;
    EQ_GLOBAL(int, 0x00923CD0) = 0;
    EQ_GLOBAL(int, 0x00923CD4) = 0;
    EQ_GLOBAL(int, 0x00923CD8) = 0;
    EQ_GLOBAL(int, 0x00923CDC) = 0;
    strcpy(EQ_ARRAY(char, 0x00923CE0), EQ_ARRAY(char, 0x0063F53F));
    EQ_GLOBAL(int, 0x00923D04) = -1;
    EQ_GLOBAL(int, 0x00923D00) = 0;
    EQ_GLOBAL(char, 0x009237B8) = 1;
    EQ_GLOBAL(char, 0x009237B7) = 0;
    EQ_GLOBAL(char, 0x009238E8) = 0;
    EQ_GLOBAL(char, 0x00923842) = 0;
    EQ_GLOBAL(int, 0x00923CBC) = 0;
    EQ_GLOBAL(char, 0x00923878) = 1;
    EQ_GLOBAL(char, 0x0092384C) = 0;
    strcpy(EQ_ARRAY(char, 0x00923898), EQ_ARRAY(char, 0x0063F53F));
    EQ_GLOBAL(char, 0x0092384D) = 0;
    EQ_GLOBAL(int, 0x00923CB4) = 0;
    EQ_GLOBAL(char, 0x009239DC) = 0;
    EQ_GLOBAL(int, 0x009239B8) = 0;
    EQ_GLOBAL(int, 0x009237B0) = 1;
    EQ_GLOBAL(int, 0x009239C0) = 0;
    EQ_GLOBAL(int, 0x009239C4) = 0;
    EQ_GLOBAL(int, 0x009239C8) = 0;
    EQ_GLOBAL(int, 0x009239CC) = 0;
    EQ_GLOBAL(int, 0x009239D0) = 0;
    EQ_GLOBAL(int, 0x009239D4) = 0;
    EQ_GLOBAL(int, 0x009239D8) = 0;
    EQ_GLOBAL(int, 0x009239A4) = 0;
    FUN_004c94ae_guess()->fieldf0_guess = 0;
    EQ_GLOBAL(int, 0x00923998) = 0;
    EQ_GLOBAL(int, 0x00923994) = 0;
    EQ_GLOBAL(int, 0x00905D28) = 0;
    EQ_GLOBAL(int, 0x009239A8) = 0;
    EQ_GLOBAL(int, 0x009239AC) = 0;
    EQ_GLOBAL(int, 0x009239B0) = 0;
    EQ_GLOBAL(char, 0x00923D7B) = 0;
    EQ_GLOBAL(int, 0x00923CA4) = 0;
    EQ_GLOBAL(int, 0x00923CA0) = 0;
    EQ_GLOBAL(char, 0x00923D7A) = 0;
    EQ_GLOBAL(char, 0x00923D2C) = 0;
    EQ_GLOBAL(char, 0x00923D2D) = 0;
    EQ_GLOBAL(char, 0x00923D2E) = 0;
    EQ_GLOBAL(char, 0x00923D2F) = 0;
    EQ_GLOBAL(char, 0x00923D30) = 0;
    EQ_GLOBAL(char, 0x00923D31) = 0;
    EQ_GLOBAL(char, 0x00923D32) = 0;
    EQ_GLOBAL(char, 0x00923D33) = 0;
    EQ_GLOBAL(char, 0x00923D34) = 0;
    EQ_GLOBAL(int, 0x00923D38) = 0;
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    EQ_GLOBAL(char, 0x009237B4) = 1;
    EQ_GLOBAL(int, 0x00923D40) = 0;
    EQ_GLOBAL(int, 0x00923D44) = 0;
    EQ_GLOBAL(int, 0x00923D48) = 0;
    EQ_GLOBAL(int, 0x00923D4C) = 0;
    EQ_GLOBAL(int, 0x00923D50) = 0;
    EQ_GLOBAL(int, 0x00923D54) = 0;
    EQ_GLOBAL(int, 0x00923D88) = 0;
    EQ_GLOBAL(int, 0x00923D8C) = 0;
    EQ_GLOBAL(int, 0x009238EC) = 0;
    EQ_GLOBAL(int, 0x009238F0) = 0;
    EQ_GLOBAL(char, 0x00923D78) = 0;
    EQ_GLOBAL(char, 0x00923D79) = 0;
    EQ_GLOBAL(char, 0x00923D1C) = 0;
    EQ_GLOBAL(int, 0x009238F8) = 0;
    EQ_GLOBAL(int, 0x00923860) = 0;
    EQ_GLOBAL(char, 0x00923D2C) = 0;
    EQ_GLOBAL(char, 0x00923D2D) = 0;
    EQ_GLOBAL(char, 0x00923D2E) = 0;
    EQ_GLOBAL(char, 0x00923D2F) = 0;
    EQ_GLOBAL(char, 0x00923D30) = 0;
    EQ_GLOBAL(char, 0x00923D31) = 0;
    EQ_GLOBAL(char, 0x00923D32) = 0;
    EQ_GLOBAL(char, 0x00923D33) = 0;
    EQ_GLOBAL(char, 0x00923D34) = 0;
    EQ_GLOBAL(int, 0x00923868) = 0;
    EQ_GLOBAL(int, 0x00923864) = 0;
    EQ_GLOBAL(int, 0x0092478C) = 0;
    EQ_GLOBAL(int, 0x00923CB8) = 0;
    reinterpret_cast<GlobalState_guess*>(this)->SetDefaultVisionColors_guess();
    for (index_guess = 0; index_guess < 4; index_guess++) {
        EQ_ARRAY(int, 0x00923D08)[index_guess] = 0;
    }
    strcpy(field17bb4_guess, EQ_ARRAY(char, 0x0063F53F));
    EQ_GLOBAL(int, 0x00923850) = 0;
    EQ_GLOBAL(int, 0x00923854) = 0;
    EQ_GLOBAL(int, 0x00923858) = 0;
    EQ_GLOBAL(int, 0x0092385C) = 0;
    EQ_GLOBAL(int, 0x00923888) = 0;
    EQ_GLOBAL(int, 0x00923890) = 0;
    EQ_GLOBAL(int, 0x0092388C) = 0;
    EQ_GLOBAL(int, 0x00923894) = 0;
    field183f4_guess = 0;
    EQ_GLOBAL(int, 0x00924474) = -1;
    EQ_GLOBAL(float, 0x00923D90) = 0.0f;
    EQ_GLOBAL(int, 0x009238D8) = 0;
    EQ_GLOBAL(int, 0x009238DC) = 0;
    EQ_GLOBAL(int, 0x009238E4) = 0;
    EQ_GLOBAL(char, 0x009238E0) = 0;
    EQ_GLOBAL(char, 0x00924675) = 0;
    EQ_GLOBAL(char, 0x00924676) = 0;
    EQ_GLOBAL(char, 0x00924677) = 0;
    EQ_GLOBAL(char, 0x009237B9) = 0;
    EQ_GLOBAL(int, 0x009237BC) = 0;
    EQ_GLOBAL(int, 0x00924678) = 1;
    EQ_GLOBAL(int, 0x0092467C) = 0;
    EQ_GLOBAL(int, 0x00923D24) = 0;
    char* line_guess = EQ_ARRAY(char, 0x00946174);
    do {
        *line_guess = 0;
        line_guess += 0x800;
    } while ((int)line_guess < (int)EQ_ARRAY(char, 0x0095A174));
    EQ_GLOBAL(int, 0x00924468) = 0;
    int* count_guess = EQ_ARRAY(int, 0x009265A4);
    char* text_guess = EQ_ARRAY(char, 0x00926D74);
    do {
        sprintf(text_guess, "@");
        text_guess += 0x100;
        *count_guess++ = 0;
    } while ((int)text_guess < (int)EQ_ARRAY(char, 0x00946174));
    void** slot_guess = EQ_ARRAY(void*, 0x009265A4);
    char* slotText_guess = EQ_ARRAY(char, 0x00926D74);
    do {
        slot_guess[-0x881] = slotText_guess;
        slot_guess[-0x868] = slot_guess;
        slotText_guess += 0x100;
        slot_guess++;
    } while ((int)slotText_guess < (int)EQ_ARRAY(char, 0x00928674));
    EQ_GLOBAL(int, 0x00924478) = 0;
    for (index_guess = 0; index_guess < 0x100; index_guess++) {
        EQ_ARRAY(int, 0x00925520)[index_guess] = 0;
    }
    for (index_guess = 0; index_guess < 100; index_guess++) {
        EQ_ARRAY(char, 0x0092460C)[index_guess] = 1;
        EQ_ARRAY(int, 0x0092447C)[index_guess] = 0;
    }
    EQ_GLOBAL(float, 0x00924950) = 1.0f;
    EQ_GLOBAL(int, 0x00924980) = 10;
    EQ_GLOBAL(int, 0x00924984) = 10;
    EQ_GLOBAL(int, 0x00924954) = 0;
    EQ_GLOBAL(int, 0x00924958) = 0;
    EQ_GLOBAL(int, 0x0092495C) = 2;
    EQ_GLOBAL(int, 0x00924964) = 1;
    EQ_GLOBAL(int, 0x00924968) = 3;
    EQ_GLOBAL(int, 0x00924990) = 4;
    EQ_GLOBAL(int, 0x00924994) = 0;
    EQ_GLOBAL(int, 0x00924998) = 0;
    EQ_GLOBAL(int, 0x0092499C) = 1;
    EQ_GLOBAL(int, 0x009249A0) = 0;
    EQ_GLOBAL(int, 0x009249A4) = 0;
    EQ_GLOBAL(int, 0x009249AC) = 0;
    EQ_GLOBAL(char, 0x009254EC) = 1;
    EQ_GLOBAL(char, 0x009254ED) = 1;
    EQ_GLOBAL(char, 0x009254EE) = 0;
    EQ_GLOBAL(char, 0x009254EF) = 1;
    EQ_GLOBAL(char, 0x009254F4) = 0;
    EQ_GLOBAL(char, 0x009254F6) = 1;
    EQ_GLOBAL(char, 0x009254F7) = 1;
    EQ_GLOBAL(char, 0x009254F8) = 1;
    char* friend_guess = EQ_ARRAY(char, 0x0095BAB4);
    do {
        *friend_guess = 0;
        friend_guess += 0x40;
    } while ((int)friend_guess < (int)EQ_ARRAY(char, 0x0095D3B4));
    char* ignore_guess = EQ_ARRAY(char, 0x0095A1B4);
    do {
        *ignore_guess = 0;
        ignore_guess += 0x40;
    } while ((int)ignore_guess < (int)EQ_ARRAY(char, 0x0095BAB4));
    EQ_GLOBAL(int, 0x00924960) = 1;
    EQ_GLOBAL(int, 0x00924978) = 0;
    EQ_GLOBAL(int, 0x0092497C) = 0;
    EQ_GLOBAL(int, 0x00924970) = 0;
    EQ_GLOBAL(int, 0x00924974) = 0;
    EQ_GLOBAL(int, 0x0092498C) = 0;
    EQ_GLOBAL(int, 0x0092496C) = 1;
    fieldb54_guess = 6;
    if (EQ_GLOBAL(char, 0x00923C9C) == 0) {
        EQ_GLOBAL(float, 0x00923B64) = 100.0f;
        EQ_GLOBAL(float, 0x00923B74) = 2000.0f;
        EQ_GLOBAL(unsigned char, 0x00923B57) = 0xc0;
        EQ_GLOBAL(unsigned char, 0x00923B5B) = 0xc0;
        EQ_GLOBAL(float, 0x00923BE0) = 100.0f;
        EQ_GLOBAL(unsigned char, 0x00923B5F) = 0xc0;
        EQ_GLOBAL(float, 0x00923B84) = 0.4f;
        EQ_GLOBAL(float, 0x00923BE4) = 2000.0f;
        EQ_GLOBAL(char, 0x00923B88) = 1;
        EQ_GLOBAL(char, 0x00923B56) = 1;
        strcpy(EQ_ARRAY(char, 0x00923C3C), "Default");
        strcpy(EQ_ARRAY(char, 0x00923C5C), "Default");
        EQ_GLOBAL(float, 0x00923C7C) = 10.0f;
        strcpy(EQ_ARRAY(char, 0x00923A40), EQ_ARRAY(char, 0x0063F53F));
        strcpy(EQ_ARRAY(char, 0x00923A20), EQ_ARRAY(char, 0x0063F53F));
        char* zoneText_guess = EQ_ARRAY(char, 0x00923AC0);
        do {
            strcpy(zoneText_guess, EQ_ARRAY(char, 0x0063F53F));
            zoneText_guess += 0x1e;
        } while ((int)zoneText_guess < (int)EQ_ARRAY(char, 0x00923B56));
        EQ_GLOBAL(float, 0x00923BC8) = 1.0f;
        EQ_GLOBAL(float, 0x00923BD4) = 9.0f;
        EQ_GLOBAL(float, 0x00923BCC) = 0.0f;
        EQ_GLOBAL(float, 0x00923BD8) = 40000.0f;
        EQ_GLOBAL(float, 0x00923BDC) = -40000.0f;
        EQ_GLOBAL(float, 0x00923BD0) = 0.0f;
    }
    EQ_GLOBAL(int, 0x00923BC0) = 1;
    EQ_GLOBAL(int, 0x00923BBC) = 4;
    EQ_GLOBAL(int, 0x00923BC4) = 0;
    EQ_GLOBAL(char, 0x00923845) = 0;
    EQ_GLOBAL(char, 0x00923992) = 0;
    EQ_GLOBAL(char, 0x00923991) = 0;
    EQ_GLOBAL(char, 0x00923990) = 1;
    EQ_GLOBAL(char, 0x009237EC) = 8;
    EQ_GLOBAL(char, 0x009237F4) = 0;
    int* tab_guess = EQ_ARRAY(int, 0x00923964);
    do {
        tab_guess[-10] = 0;
        *tab_guess = 0;
        tab_guess++;
    } while ((int)tab_guess < (int)EQ_ARRAY(int, 0x0092398C));
    EQ_GLOBAL(int, 0x0092398C) = 0;
    EQ_GLOBAL(int, 0x00923934) = 0;
    EQ_GLOBAL(int, 0x00923938) = 0;
    EQ_GLOBAL(int, 0x00923838) = 0;
    EQ_GLOBAL(int, 0x0092383C) = 0;
    fieldb50_guess = 0;
    field393fc_guess = 0;
    field39400_guess = 0;
    field3a1bc_guess = window_guess;
    EQ_GLOBAL(int, 0x00923770) = window_guess;
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_GLOBAL(int, 0x00850508) = 1;
    EQ_GLOBAL(int, 0x00850910) = 1;
    EQ_GLOBAL(int, 0x009237B0) = 0;
    EQ_GLOBAL(char, 0x00924680) = 1;
    EQ_GLOBAL(char, 0x009237B5) = 1;
    field183f8_guess = 0;
    EQ_GLOBAL(int, 0x009237AC) = 1;
    EQ_GLOBAL(int, 0x00923778) = 0x77;
    EQ_GLOBAL(int, 0x0092377C) = 0;
    EQ_GLOBAL(int, 0x00923780) = 0x207;
    EQ_GLOBAL(int, 0x00923784) = 0x140;
    EQ_GLOBAL(int, 0x00850980) = 0;
    strcpy(field17bb4_guess, EQ_ARRAY(char, 0x0063F53F));
    for (index_guess = 0; index_guess < 5; index_guess++) {
        EQ_ARRAY(int, 0x0090420C)[index_guess] = 0;
    }
    for (index_guess = 0; index_guess < 5; index_guess++) {
        if (index_guess != 4) {
            EQ_ARRAY(int, 0x00905BEC)[index_guess] = 0;
        }
    }
    for (index_guess = 0; index_guess < 10; index_guess++) {
        strcpy(field39810_guess[index_guess], "<none>");
        field397a0_guess[index_guess] = 0;
        field3971c_guess[index_guess] = 0;
    }
    for (index_guess = 0; index_guess < 100; index_guess++) {
        g_records_00851200_guess[index_guess] = new OwnedRecord_guess(index_guess);
    }
    EQ_GLOBAL(Owned4482A9_guess*, 0x008511D8) = new Owned4482A9_guess(0, 0);
    g_owned_009859ec_guess = new Owned4B445E_guess();
    EQ_GLOBAL(Owned4C9AF0_guess*, 0x00985CF0) = new Owned4C9AF0_guess();
    g_owned_00991fa8_guess = new Owned554D6C_guess();
    g_owned_00985cec_guess = new Owned4C9A90_guess();
    g_owned_0079c120_guess = new Owned404AA5_guess();
    LoadSpellEffects_guess();
    EQ_GLOBAL(int, 0x00905D00) = 0;
    g_ownedDisplay_guess = new CDisplay_guess(window_guess);
    if (g_ownedDisplay_guess == 0 || g_ownedDisplay_guess->error_guess == 1) {
        FUN_00574110_guess(
            "nError set to TRUE because DisplayObject == NULL || DisplayObject->nError == TRUE\n");
        fieldb50_guess = 1;
    }
    g_owned_00905cc0_guess = new OwnedVirtual_guess();
    if (!g_ownedDisplay_guess->LoadBMPFile_guess()) {
        FUN_00574110_guess("nError set to TRUE because !DisplayObject->LoadBMPFile()\n");
        fieldb50_guess = 1;
    }
    // Sound setup from [Defaults] Sound44k and SpeakerType.
    bool sound44k_guess = FUN_00576b70_guess("Defaults", "Sound44k", 0, ".\\eqclient.ini") != 0;
    int speaker_guess = FUN_00576b70_guess("Defaults", "SpeakerType", 0, ".\\eqclient.ini");
    g_owned_00851390_guess = new Owned44C426_guess(EQ_GLOBAL(int, 0x00988DE0) != 0,
        sound44k_guess, speaker_guess);
    g_displayState_00903e84_guess = new DisplayState_guess();
    g_owned_00985d90_guess = new Owned4CBAAF_guess();
    loadOptions_guess();
    CreateConnectionManager_guess();
}

struct EnterWorldPacket_guess {
    char name_guess[0x40];
    int field40_guess;
    unsigned char field44_guess;
    char padding_0045_guess[3];
};

#define g_flag_009858c5_guess EQ_GLOBAL(unsigned char, 0x009858C5)
#define g_resetTarget_009232f0_guess EQ_ARRAY(ResetTarget_guess, 0x009232F0)
#define g_cacheOwner_00985cf0_guess EQ_GLOBAL(CacheOwner_guess*, 0x00985CF0)
#define g_float_00923bdc_guess EQ_GLOBAL(float, 0x00923BDC)
#define g_float_00923bd8_guess EQ_GLOBAL(float, 0x00923BD8)
#define g_float_00923b64_guess EQ_GLOBAL(float, 0x00923B64)
#define g_float_00923b74_guess EQ_GLOBAL(float, 0x00923B74)
#define g_byte_00923b57_guess EQ_GLOBAL(unsigned char, 0x00923B57)
#define g_byte_00923b5b_guess EQ_GLOBAL(unsigned char, 0x00923B5B)
#define g_byte_00923b5f_guess EQ_GLOBAL(unsigned char, 0x00923B5F)
#define g_flag_00923c9c_guess EQ_GLOBAL(unsigned char, 0x00923C9C)
#define g_fontProvider_0099e360_guess EQ_GLOBAL(FontProvider_guess*, 0x0099E360)
#define g_charSelect_00850b9c_guess EQ_GLOBAL(CharSelect_guess*, 0x00850B9C)
#define g_notice_00904228_guess EQ_GLOBAL(int, 0x00904228)
#define g_notice_00905cb4_guess EQ_GLOBAL(int, 0x00905CB4)
#define g_notice_00905cb8_guess EQ_GLOBAL(int, 0x00905CB8)
#define g_notice_00905cbc_guess EQ_GLOBAL(int, 0x00905CBC)
#define g_loopDispatch_00851390_guess EQ_GLOBAL(LoopDispatch_guess*, 0x00851390)

// Char-select screen: resets the session, tells the world the client is ready (OP_WorldClientReady
// 0x5E99), sets up scene and font, shows any login notice, then runs frames in state 1. Enter World
// saves [Defaults] LastCharSel and sends OP_EnterWorld (0x7CBA); quit sends OP_WorldLogout (0x7718).
// FUNCTION: TITANIUM 0x004A9EBF
void GlobalState_guess::DoCharacterSelection_guess() {
    // Leave the game: drop the chat and mail servers and the game globals, then tell the world
    // server the client is ready (OP_WorldClientReady).
    g_flag_009858c5_guess = 1;
    reinterpret_cast<TargetOwner_guess*>(this)->DisconnectChatServer_guess();
    reinterpret_cast<TargetOwner_guess*>(this)->DisconnectMailServer_guess();
    ResetGameGlobals_guess();
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5e99, 0, 0, 1);
    FlushMouse_guess();
    FlushKeyboard_guess();
    g_resetTarget_009232f0_guess->FUN_00408410_guess(0);
    if (g_cacheOwner_00985cf0_guess != 0) {
        g_cacheOwner_00985cf0_guess->FUN_004c9ba7_guess();
        g_cacheOwner_00985cf0_guess->ClearKnowledgeBase_guess();
    }
    unsigned int lastUpdate_guess = 0;
    // The char-select scene: name sprites on, far clip 250, hour 12 with sun and sky, the
    // character-view camera.
    g_displayRoot_guess->InitCharSelectUI_guess();
    g_displayRoot_guess->SetPCNameSpriteState_guess(1);
    g_displayRoot_guess->SetNPCNameSpriteState_guess(1);
    g_state_009237b0_guess = 1;
    g_displayRoot_guess->SetYon_guess(250.0f);
    g_displayRoot_guess->SetDayPeriod_guess(0xc, 0);
    g_displayRoot_guess->SetSunLight_guess();
    g_displayRoot_guess->FUN_00436156_guess(0);
    g_float_00923bd8_guess = g_float_00923bdc_guess = -40000.0f;
    g_float_00923b64_guess = 150.0f;
    g_float_00923b74_guess = 250.0f;
    g_byte_00923b57_guess = 200;
    g_byte_00923b5b_guess = 200;
    g_byte_00923b5f_guess = 200;
    g_displayRoot_guess->SetSkyBackground_guess();
    g_flag_00923c9c_guess = 1;
    g_globalState_guess->field39ab8_guess = 0;
    g_displayRoot_guess->SetupCharacterViewCamera_guess(0);
    g_flag_00850508_guess = 2;
    g_displayRoot_guess->ChangeVideoMode_guess();
    g_displayRoot_guess->FUN_0043933d_guess();
    char key_guess[0x100];
    char fontName_guess[0x100];
    // Font for the current size: [Fonts] Font.<size>.0 from the ini, the provider's default
    // otherwise.
    _sprintf(key_guess, "Font.%s.0",
        EQ_ARRAY(const char*, 0x00799830)[g_fontIndex_00923d74_guess]);
    g_globalState_guess->FUN_004ae865_guess("Fonts", key_guess,
        g_fontProvider_0099e360_guess->DefaultFont_guess(g_fontIndex_00923d74_guess, 0),
        fontName_guess, 0x100, 1);
    g_fontProvider_0099e360_guess->SetFont_guess(g_fontIndex_00923d74_guess, -1, fontName_guess);
    g_charSelect_00850b9c_guess->MakeHotButton_guess();
    // A pending login notice shows once, for 4-10 s: strings 0x13FE, 0x1402, 0x175D, or for the
    // selected character 0x16EA plus 0x17E1 or 0x7A2. All four flags are then cleared.
    if (g_notice_00904228_guess != 0 || g_notice_00905cb4_guess != 0 ||
        g_notice_00905cb8_guess != 0 || g_notice_00905cbc_guess != 0) {
        if (g_notice_00905cb4_guess != 0) {
            g_deliveryManager_guess->Activate(
                g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                pStringTable->getString(0x13fe, 0), 1, 4000, 0, 0);
        } else if (g_notice_00905cb8_guess != 0) {
            g_deliveryManager_guess->Activate(
                g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                pStringTable->getString(0x1402, 0), 1, 4000, 0, 0);
        } else if (g_notice_00905cbc_guess != 0) {
            g_deliveryManager_guess->Activate(
                g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                pStringTable->getString(0x175d, 0), 1, 10000, 0, 0);
        } else {
            if (g_lookupManager_guess->FUN_005f6c80_guess(g_globalState_guess->field397d4_guess[
                    g_charSelect_00850b9c_guess->selected_guess]) != 0) {
                g_deliveryManager_guess->Activate(
                    g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                    pStringTable->getString(0x16ea, 0), 1, 6000, 0, 0);
            }
            if (g_lookupManager_guess->FUN_005f6d40_guess(g_globalState_guess->field397d4_guess[
                    g_charSelect_00850b9c_guess->selected_guess]) != 0) {
                g_deliveryManager_guess->Activate(
                    g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                    pStringTable->getString(0x17e1, 0), 1, 6000, 0, 0);
            } else {
                g_deliveryManager_guess->Activate(
                    g_globalState_guess ? (unsigned int)g_globalState_guess + 8 : 0, 0xb,
                    pStringTable->getString(0x7a2, 0), 1, 4000, 0, 0);
            }
        }
        g_notice_00905cb4_guess = 0;
        g_notice_00905cb8_guess = 0;
        g_notice_00904228_guess = 0;
        g_notice_00905cbc_guess = 0;
    }
    AcquireMouse_guess(1);
    // Frame loop while in state 1, about 10 ms apart. Leaves on a lost connection, Enter World, or
    // quit; any other state change hides the screen and sets state 0xFD.
    while (state_guess == 1) {
        ProcessGameEvents();
        reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
        g_loopDispatch_00851390_guess->ProcessSound_guess();
        if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x40cd, 1) != 0) {
            return;
        }
        // +0x1E2 set: player controls run. When the area test turns true (on the change only, kept
        // in fieldb60_guess) the screen leaves that mode.
        if (g_charSelect_00850b9c_guess->field1e2_guess != 0) {
            ProcessControls_guess();
            char inArea_guess = IsInCharCreateTrigger_guess();
            if (inArea_guess != 0 && fieldb60_guess == 0) {
                g_charSelect_00850b9c_guess->LeaveExplorationMode_guess();
                g_charSelect_00850b9c_guess->FUN_004f14f0_guess();
            }
            fieldb60_guess = inArea_guess;
        } else {
            g_flag_00923842_guess = 0;
            if (g_displayRoot_guess->field148_guess > lastUpdate_guess) {
                // Every 50 ms: turn the view by 3 heading units while +0x1E1 is set, else face it
                // along +0x4C of 0x00905CE4.
                lastUpdate_guess = g_displayRoot_guess->field148_guess + 0x32;
                if (g_charSelect_00850b9c_guess->field1e1_guess != 0) {
                    g_loopEffects_009254fc_guess[g_loopSelector_00850ccc_guess]->SetValue_guess(
                        g_displayRoot_guess->FixHeading_guess(
                            g_loopEffects_009254fc_guess[g_loopSelector_00850ccc_guess]
                                ->GetValue_guess() + 3.0f));
                } else {
                    g_loopEffects_009254fc_guess[g_loopSelector_00850ccc_guess]->SetValue_guess(
                        g_loopTarget_00905ce4_guess->field4c_guess);
                }
            }
        }
        if (g_loopPipeline_0099d3ec_guess != 0) {
            if (g_flag_00923842_guess == 0) {
                BoundsPair_guess sourceBounds_guess;
                BoundsPair_guess targetBounds_guess;
                sourceBounds_guess.first_guess = g_loopRenderValueA_009237c8_guess;
                sourceBounds_guess.second_guess = g_loopRenderValueB_009237cc_guess;
                targetBounds_guess.first_guess = g_loopPipeline_0099d3ec_guess->field74_guess;
                targetBounds_guess.second_guess = g_loopPipeline_0099d3ec_guess->field78_guess;
                if (targetBounds_guess.Contains_guess(&sourceBounds_guess) == 0) {
                    g_loopPipeline_0099d3ec_guess->FUN_005af6a0_guess(&sourceBounds_guess);
                }
            }
            g_loopPipeline_0099d3ec_guess->FUN_005b06a0_guess();
            g_loopPipeline_0099d3ec_guess->FUN_005af250_guess();
            if (g_flag_00923842_guess == 0) {
                g_loopPipeline_0099d3ec_guess->FUN_005af580_guess();
            }
        }
        g_loopDisplay_0099e364_guess->Slot37_guess();
        g_loopClock_00905d24_guess->Render_MinWorld_guess();
        // Enter World with a character selected: music 4, LastCharSel saved to eqclient.ini,
        // OP_EnterWorld with the name and +0x1F4 / +0x1F8, then state 3 to wait for the zone.
        if (g_charSelect_00850b9c_guess->enterWorld_guess != 0 &&
            g_charSelect_00850b9c_guess->selected_guess != -1) {
            g_charSelect_00850b9c_guess->enterWorld_guess = 0;
            if (g_charSelect_00850b9c_guess->FUN_004f0e72_guess() > 0) {
                g_dispatch_00851390_guess->SetMusicSelection_guess(4, 0);
                char number_guess[8];
                _sprintf(number_guess, "%d", g_charSelect_00850b9c_guess->selected_guess);
                FUN_0060beb0_guess("Defaults", "LastCharSel", number_guess, ".\\eqclient.ini");
                EnterWorldPacket_guess packet_guess;
                memset(&packet_guess, 0, sizeof(packet_guess));
                FUN_0060e450_guess(packet_guess.name_guess,
                    charNames_guess[g_charSelect_00850b9c_guess->selected_guess]);
                packet_guess.field40_guess = g_charSelect_00850b9c_guess->field1f4_guess;
                packet_guess.field44_guess = g_charSelect_00850b9c_guess->field1f8_guess;
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7cba, &packet_guess,
                    sizeof(packet_guess), 1);
                g_globalState_guess->SetGameStateInline_guess(3);
                return;
            }
        }
        if (g_charSelect_00850b9c_guess->enterWorld_guess != 0) {
            g_charSelect_00850b9c_guess->enterWorld_guess = 0;
        }
        // +0x1E4: hide this screen and run the inner loop. If it ends in state 2 with +0x420 of
        // 0x00850C20 set and a name longer than 3 characters, enter the world as that name; a state
        // 2 without them goes back to state 1.
        if (g_charSelect_00850b9c_guess->field1e4_guess != 0) {
            g_charSelect_00850b9c_guess->field1e4_guess = 0;
            g_charSelect_00850b9c_guess->Hide_guess();
            RunCharacterSelectLoop_guess();
            if (state_guess == 2) {
                if (pinstCCharacterCreation_guess != 0 && g_charSelect_00850b9c_guess != 0 &&
                    pinstCCharacterCreation_guess->field_420_guess != 0 &&
                    strlen(g_charSelect_00850b9c_guess->FUN_004f0d1d_guess()) > 3) {
                    if (g_deliveryManager_guess != 0) {
                        g_deliveryManager_guess->ExpireAll_guess();
                    }
                    EnterWorldPacket_guess packet_guess;
                    memset(&packet_guess, 0, sizeof(packet_guess));
                    FUN_0060e450_guess(packet_guess.name_guess,
                        g_charSelect_00850b9c_guess->FUN_004f0d1d_guess());
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7cba, &packet_guess,
                        sizeof(packet_guess), 1);
                    g_globalState_guess->SetGameStateInline_guess(3);
                    char text_guess[0x80];
                    char message_guess[0x100];
                    g_lookupManager_guess->FUN_005fa1c0_guess(0xbc, text_guess, 1);
                    FUN_0046da4a_guess(message_guess, 0x2524, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    FUN_00407dc9_guess()->DisplayText(message_guess, 10, 10, 0xc0, 0,
                        1000, 1000);
                    if (g_loopPipeline_0099d3ec_guess != 0) {
                        g_loopPipeline_0099d3ec_guess->FUN_005b06a0_guess();
                        g_loopPipeline_0099d3ec_guess->FUN_005af250_guess();
                    }
                    if (g_displayRoot_guess->field13_guess == 0) {
                        ProcessGameEventsAndRender_guess();
                    }
                    return;
                }
                g_globalState_guess->SetGameState(1);
            }
            g_charSelect_00850b9c_guess->MakeHotButton_guess();
        }
        // Quit: state 0xFF and OP_WorldLogout.
        if (g_charSelect_00850b9c_guess->quit_guess != 0) {
            FUN_00574110_guess("Quitting normally.\n");
            fieldb50_guess = 1;
            g_globalState_guess->SetGameStateInline_guess(0xff);
            g_charSelect_00850b9c_guess->quit_guess = 0;
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7718, 0, 0, 1);
            return;
        }
        Sleep(10);
    }
    g_charSelect_00850b9c_guess->Hide_guess();
    g_loopDisplay_0099e364_guess->Slot40_guess();
    g_globalState_guess->SetGameStateInline_guess(0xfd);
}

struct NetPCPrefix_guess {
    int field_0000_guess;
    int field_0004_guess;
};

struct NetPCBase_guess {
    virtual void RefreshCounts_guess();
    virtual ~NetPCBase_guess();
    char padding_0004_guess[0xFC];
    int zoneInstance_guess; // 0x100
};

struct NetPC_guess : NetPCPrefix_guess, virtual NetPCBase_guess {
    // EXTERNAL: TITANIUM 0x004BF2A7 NetPC_guess::NetPC_guess
    NetPC_guess();
    char padding_000c_guess[0xC4D0 - 0xC - 0x104];
};

struct NetMotion_guess {
    float y_guess;
    float x_guess;
    float z_guess;
    void Set_guess(float y_guess_, float x_guess_, float z_guess_) {
        y_guess = y_guess_;
        x_guess = x_guess_;
        z_guess = z_guess_;
    }
};

struct NetActorInfo_guess {
    int field00_guess;
};

struct NetPlayer_guess {
    char padding_0000_guess[0x30];
    NetMotion_guess motion_guess; // 0x30
    char padding_003c_guess[0x1A8 - 0x3C];
    NetActorInfo_guess* actorInfo_guess; // 0x1A8
    char padding_01ac_guess[0x204 - 0x1AC];
    int zone_guess; // 0x204
    char padding_0208_guess[0x348 - 0x208];
    // EXTERNAL: TITANIUM 0x004850A0 NetPlayer_guess::NetPlayer_guess
    NetPlayer_guess(int a_guess, int b_guess, int c_guess, int d_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x004849B2 NetPlayer_guess::~NetPlayer_guess
    ~NetPlayer_guess();
    // EXTERNAL: TITANIUM 0x0047FA9E NetPlayer_guess::SetHeights_guess
    void SetHeights_guess();
    // EXTERNAL: TITANIUM 0x0047CC37 NetPlayer_guess::SetSounds_guess
    void SetSounds_guess();
};

struct NetDisplay_guess {
    int field00_guess;
    char padding_0004_guess[1];
    unsigned char field05_guess;
    // EXTERNAL: TITANIUM 0x00444116 NetDisplay_guess::FUN_00444116_guess
    void FUN_00444116_guess(int zone_guess);
    // EXTERNAL: TITANIUM 0x0043910D NetDisplay_guess::FUN_0043910d_guess
    void FUN_0043910d_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0043C78F NetDisplay_guess::ChangeVideoMode_guess
    void ChangeVideoMode_guess();
    // EXTERNAL: TITANIUM 0x00439A93 NetDisplay_guess::SetPCNameSpriteState_guess
    void SetPCNameSpriteState_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0043A2CE NetDisplay_guess::SetupEQPlayers_guess
    void SetupEQPlayers_guess();
    // EXTERNAL: TITANIUM 0x004392DE NetDisplay_guess::SetCameraMode_guess
    void SetCameraMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0044350D NetDisplay_guess::StopWorldDisplay_guess
    void StopWorldDisplay_guess();
};

struct NetScreen_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess();
};

struct NetReset4463c2_guess {
    // EXTERNAL: TITANIUM 0x004463C2 NetReset4463c2_guess::FUN_004463c2_guess
    void FUN_004463c2_guess();
};

struct NetReset5652c1_guess {
    // EXTERNAL: TITANIUM 0x005652C1 NetReset5652c1_guess::ClearTitles_guess
    void ClearTitles_guess();
};

struct NetReset408efd_guess {
    // EXTERNAL: TITANIUM 0x00408EFD NetReset408efd_guess::ClearBuyLines_guess
    void ClearBuyLines_guess();
};

struct NetReset40abbf_guess {
    // EXTERNAL: TITANIUM 0x0040ABBF NetReset40abbf_guess::FUN_0040abbf_guess
    void FUN_0040abbf_guess(int value_guess);
};

struct NetReset424504_guess {
    // EXTERNAL: TITANIUM 0x00424504 NetReset424504_guess::FUN_00424504_guess
    void FUN_00424504_guess();
};

// EXTERNAL: TITANIUM 0x00469DD7 NoOp_guess
void __cdecl NoOp_guess();
// EXTERNAL: TITANIUM 0x004CC6B7 fillEvilProcessNames_guess
void __cdecl fillEvilProcessNames_guess(int value_guess);

#define g_netPC_00905d00_guess EQ_GLOBAL(NetPC_guess*, 0x00905D00)
#define g_netPlayer_00905ce4_guess EQ_GLOBAL(NetPlayer_guess*, 0x00905CE4)
#define g_netPlayer_00905d20_guess EQ_GLOBAL(NetPlayer_guess*, 0x00905D20)
#define g_netPlayer_00905cf8_guess EQ_GLOBAL(NetPlayer_guess*, 0x00905CF8)
#define g_netValue_00905cfc_guess EQ_GLOBAL(int, 0x00905CFC)
#define g_netDisplay_00905d24_guess EQ_GLOBAL(NetDisplay_guess*, 0x00905D24)
#define g_netScreen_0099e360_guess EQ_GLOBAL(NetScreen_guess*, 0x0099E360)
#define g_netZoneAddr_00905c98_guess EQ_GLOBAL(int, 0x00905C98)
#define g_netReset_0079dbd4_guess EQ_GLOBAL(NetReset424504_guess*, 0x0079DBD4)
#define g_netNoName_00904004_guess EQ_ARRAY(char, 0x00904004)

// Login to char select: makes a placeholder PC and player ('load') in zone 190, loads that scene and
// runs DoCharacterSelection. After Enter World it waits in state 3 up to 180 s for the zone address
// (0x905C98), re-sending OP_EnterWorld up to 20 times while the zone is still booting.
// FUNCTION: TITANIUM 0x004AA92B
void GlobalState_guess::StartNetworkGame(int unused1_guess, int unused2_guess,
    char* name_guess) {
    FUN_00574110_guess("Starting network game.\n");
    reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
    NoOp_guess();
    fillEvilProcessNames_guess(0);
    g_value_00923794_guess = 0;
    if (g_netPC_00905d00_guess != 0) {
        delete g_netPC_00905d00_guess;
        g_netPC_00905d00_guess = 0;
    }
    g_netPC_00905d00_guess = new NetPC_guess;
    g_netPlayer_00905ce4_guess = g_netPlayer_00905d20_guess =
        new NetPlayer_guess(0, 0, 1, 1, "load");
    g_netPlayer_00905ce4_guess->SetHeights_guess();
    g_netPlayer_00905ce4_guess->SetSounds_guess();
    // Zone 190 is clz ("Loading" in the client's zone table), the scene behind character select.
    g_netPlayer_00905ce4_guess->zone_guess = 0xbe;
    g_netPC_00905d00_guess->zoneInstance_guess = g_netPlayer_00905ce4_guess->zone_guess;
    g_netPlayer_00905cf8_guess = g_netPlayer_00905ce4_guess;
    g_netValue_00905cfc_guess = 0;
    g_netDisplay_00905d24_guess->field05_guess = 0;
    g_netPlayer_00905ce4_guess->motion_guess.Set_guess(0.0f, 0.0f, 7.0f);
    FUN_00574110_guess("Starting load.\n");
    g_netDisplay_00905d24_guess->FUN_00444116_guess(g_netPlayer_00905ce4_guess->zone_guess);
    FUN_00574110_guess("load done.\n");
    CreateInitialActors_guess();
    g_netDisplay_00905d24_guess->FUN_0043910d_guess(
        g_netPlayer_00905ce4_guess->actorInfo_guess->field00_guess);
    SetupCharSelectCamera_guess();
    g_flag_00850508_guess = 5;
    g_netDisplay_00905d24_guess->ChangeVideoMode_guess();
    g_netDisplay_00905d24_guess->SetPCNameSpriteState_guess(0);
    g_globalState_guess->SetGameState(1);
    g_netDisplay_00905d24_guess->SetupEQPlayers_guess();
    FUN_00574110_guess("Starting char select.\n");
    g_netScreen_0099e360_guess->Slot32_guess();
    int retries_guess = 0;
    for (;;) {
        if (state_guess != 1) {
          if (state_guess != 3) {
            if (g_charSelect_00850b9c_guess->FUN_004f0e72_guess() > 0) {
                FUN_0060e450_guess(name_guess,
                    charNames_guess[g_charSelect_00850b9c_guess->selected_guess]);
            } else {
                FUN_0060e450_guess(name_guess, g_netNoName_00904004_guess);
            }
            delete g_netPlayer_00905d20_guess;
            g_netPlayer_00905d20_guess = 0;
            g_netPlayer_00905ce4_guess = 0;
            g_netPlayer_00905cf8_guess = 0;
            g_netDisplay_00905d24_guess->SetCameraMode_guess(0);
            g_flag_00850508_guess = 1;
            g_netDisplay_00905d24_guess->ChangeVideoMode_guess();
            g_netDisplay_00905d24_guess->field05_guess = 1;
            g_netDisplay_00905d24_guess->StopWorldDisplay_guess();
            return;
          }
        } else {
            g_dispatch_00851390_guess->SetMusicSelection_guess(1, false);
            g_dispatch_00851390_guess->SetMusicSelection_guess(4, true);
            FUN_00574110_guess("Clearing display buffers.\n");
            g_loopDisplay_0099e364_guess->Slot40_guess();
            FUN_00574110_guess("Display buffers cleared.\n");
            EQ_ARRAY(NetReset4463c2_guess, 0x009231C8)->FUN_004463c2_guess();
            DoCharacterSelection_guess();
            EQ_ARRAY(NetReset5652c1_guess, 0x00992918)->ClearTitles_guess();
            EQ_ARRAY(NetReset408efd_guess, 0x0079C198)->ClearBuyLines_guess();
            EQ_ARRAY(NetReset40abbf_guess, 0x00905D38)->FUN_0040abbf_guess(0);
            g_netReset_0079dbd4_guess->FUN_00424504_guess();
        }
        g_netZoneAddr_00905c98_guess = 0;
        g_notice_00904228_guess = 0;
        g_notice_00905cb4_guess = 0;
        g_notice_00905cb8_guess = 0;
        g_notice_00905cbc_guess = 0;
        // Wait up to 180 s for the zone address (OP_ZoneServerInfo, 0x61B6, sets 0x905C98). A
        // zone-unavailable notice (0x904228: OP_ZoneUnavail, OP_CharInacessable or 0xAC0) re-sends
        // OP_EnterWorld (0x7CBA) after 500 ms while the world still lists the character, at most 20 times;
        // the timeout ends the game (0xFF).
        unsigned int deadline_guess = FUN_0046d655_guess() + 180000;
        while (state_guess == 3) {
            reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
            if (g_netZoneAddr_00905c98_guess != 0) {
                g_globalState_guess->SetGameStateInline_guess(0xfd);
                break;
            }
            if (g_notice_00904228_guess != 0) {
                if (retries_guess < 20 &&
                    g_lookupManager_guess->FUN_005f6c80_guess(g_globalState_guess->field397d4_guess[
                        g_charSelect_00850b9c_guess->selected_guess]) != 0) {
                    Sleep(500);
                    EnterWorldPacket_guess packet_guess;
                    memset(&packet_guess, 0, sizeof(packet_guess));
                    FUN_0060e450_guess(packet_guess.name_guess,
                        charNames_guess[g_charSelect_00850b9c_guess->selected_guess]);
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7cba, &packet_guess,
                        sizeof(packet_guess), 1);
                    g_netZoneAddr_00905c98_guess = 0;
                    g_notice_00904228_guess = 0;
                    g_notice_00905cb4_guess = 0;
                    g_globalState_guess->SetGameStateInline_guess(3);
                    retries_guess++;
                } else {
                    retries_guess = 0;
                    g_globalState_guess->SetGameState(1);
                }
                break;
            }
            if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4301, 1) != 0) {
                break;
            }
            Sleep(10);
            if (FUN_0046d655_guess() > deadline_guess) {
                reinterpret_cast<DisconnectOwner_guess*>(this)->DisplayScreen_guess("Respond.bmp");
                Sleep(2000);
                FUN_00574110_guess("TIMED OUT WAITING FOR ZONE ADDR\n");
                reinterpret_cast<DisconnectOwner_guess*>(this)->field39400_guess = 1;
                g_globalState_guess->SetGameStateInline_guess(0xff);
                g_value_00923794_guess = 0xfd;
                fieldb50_guess = 1;
                g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                return;
            }
        }
    }
}

struct ZoneCharBase_guess {
    virtual void RefreshCounts_guess();
    EQ_CharacterProfile_guess profile_guess; // 0x04
    char padding_000c_guess[0x2C - 0xC];
    float y_guess; // 0x2C
    float x_guess; // 0x30
    float z_guess; // 0x34
    float heading_guess; // 0x38
    char name_guess[0x40]; // 0x3C
    char padding_007c_guess[0xBC - 0x7C];
    TextReceiver_guess text_guess; // 0xBC
    char padding_00bd_guess[0xFC - 0xBD];
    unsigned char field0fc_guess; // 0xFC
    char padding_00fd_guess[3];
    int zoneInstance_guess; // 0x100
};

struct ZoneCharHead_guess : NetPCPrefix_guess, virtual ZoneCharBase_guess {
    char padding_000c_guess[0xC280 - 0xC];
};

struct ZoneCharSecond_guess {
    int field00_guess;
};

struct ZoneChar_guess : ZoneCharHead_guess, ZoneCharSecond_guess {
    // EXTERNAL: TITANIUM 0x004BC20B ZoneChar_guess::FUN_004bc20b_guess
    int FUN_004bc20b_guess(EQPlayer* player_guess);
};

struct ZoneCharInfo_guess {
    char padding_0000_guess[0x11A4];
    int field11a4_guess;
};

struct ZoneResetTarget_guess {
    // EXTERNAL: TITANIUM 0x004B60C2 ZoneResetTarget_guess::FUN_004b60c2_guess
    void FUN_004b60c2_guess();
};

struct ZonePlayerOps_guess {
    // EXTERNAL: TITANIUM 0x0048C1A3 ZonePlayerOps_guess::SendMovementHistory_guess
    void SendMovementHistory_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x004B6088 FUN_004b6088_guess
ZoneResetTarget_guess* __cdecl FUN_004b6088_guess();
// EXTERNAL: TITANIUM 0x004649D5 text_to_client_guess
void __cdecl text_to_client_guess(ZoneCharSecond_guess* target_guess, const char* text_guess,
    int color_guess);
// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination_guess, const char* source_guess,
    int size_guess);

struct ZoneLookup_guess {
    // EXTERNAL: TITANIUM 0x005F6E80 ZoneLookup_guess::FUN_005f6e80_guess
    int FUN_005f6e80_guess(int zone_guess);
};

#define g_zoneChar_00905d00_guess EQ_GLOBAL(ZoneChar_guess*, 0x00905D00)
#define g_zoneLookup_00905cc0_guess EQ_GLOBAL(ZoneLookup_guess*, 0x00905CC0)
#define g_zoneValue_009238f8_guess EQ_GLOBAL(int, 0x009238F8)
#define g_zoneResult_00923d94_guess EQ_GLOBAL(int, 0x00923D94)
#define g_zoneFlag_00923d7b_guess EQ_GLOBAL(unsigned char, 0x00923D7B)
#define g_zoneFlag_00923d7a_guess EQ_GLOBAL(unsigned char, 0x00923D7A)
#define g_zoneAngle_00923d20_guess EQ_GLOBAL(float, 0x00923D20)
#define g_zoneName_00903fd8_guess EQ_ARRAY(char, 0x00903FD8)
#define g_zoneY_00904244_guess EQ_GLOBAL(float, 0x00904244)
#define g_zoneX_00903eb4_guess EQ_GLOBAL(float, 0x00903EB4)
#define g_zoneZ_00904224_guess EQ_GLOBAL(float, 0x00904224)
#define g_zoneHeading_00903eb8_guess EQ_GLOBAL(float, 0x00903EB8)
#define g_zoneCharName_00905c18_guess EQ_ARRAY(char, 0x00905C18)
#define g_zoneSlotFlag_009043a4_guess EQ_GLOBAL(unsigned char, 0x009043A4)
#define g_zoneSlots_00904390_guess EQ_ARRAY(int, 0x00904390)

struct ZoneStatusRequest_guess {
    char zoneName_guess[0x40];
    int zone_guess;
    float y_guess;
    float x_guess;
    float z_guess;
    int mode_guess;
    int zero_guess;
};

struct ZoneStatusReply_guess {
    char zoneName_guess[0x40];
    int field40_guess;
    char padding_0044_guess[0x10];
    int status_guess;
};

struct NetPlayerNameView_guess {
    char padding_0000_guess[0x120];
    char name_guess[1];
};

struct ZoneStatusFrame_guess {
    int waitStorage_guess[5];
    GlobalState_guess* owner_guess;
    char path_guess[0x80];
    ZoneStatusReply_guess reply_guess;
    ZoneStatusRequest_guess request_guess;
    char zoneName_guess[0x20];
};

// EXTERNAL: TITANIUM 0x00576670 FUN_00576670_guess
char __cdecl FUN_00576670_guess(const char* path_guess);

// Asks the world whether this character may enter `zone` at y/x/z (OP_ZoneChange 0x5DD8) and waits
// up to 180 s for the reply (HandleZoneChangeWaitPacket). Returns the reply's success value (1 = yes,
// negative = reason), or -4 when the connection dropped. Zone 75 also needs its .s3d file.
// FUNCTION: TITANIUM 0x00499139
int GlobalState_guess::IsZoneAvailable_guess(int zone_guess, float y_guess,
    float x_guess, float z_guess, int mode_guess) {
    ZoneStatusFrame_guess frame_guess;
    frame_guess.owner_guess = this;
    if (g_zoneChar_00905d00_guess == 0) {
        return 1;
    }

    g_lookupManager_guess->FUN_005f6ed0_guess(zone_guess, frame_guess.zoneName_guess);
    if (zone_guess == 0x4b) {
        _sprintf(frame_guess.path_guess, "%s.s3d", frame_guess.zoneName_guess);
        if (FUN_00576670_guess(frame_guess.path_guess) == 0) {
            frame_guess.owner_guess->DspChat_guess(
                g_stringTable_guess->Lookup_guess(0x3060, 0), 0xd, true);
            return 0;
        }
    }

    strcpy(frame_guess.request_guess.zoneName_guess, g_zoneChar_00905d00_guess->name_guess);
    frame_guess.request_guess.zero_guess = 0;
    frame_guess.request_guess.zone_guess = zone_guess;
    frame_guess.request_guess.y_guess = y_guess;
    frame_guess.request_guess.x_guess = x_guess;
    frame_guess.request_guess.z_guess = z_guess;
    frame_guess.request_guess.mode_guess = mode_guess;

    new (&frame_guess.waitStorage_guess[0])
        TimedEntry_guess(&frame_guess.reply_guess, 180000);
    unsigned int previousWait_guess =
        reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)->GetField1fc_guess();
    g_connection_00905ca0_guess->BeginWait_guess(
        reinterpret_cast<DisconnectWaitState_guess*>(&frame_guess.waitStorage_guess[0]));
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5dd8,
        &frame_guess.request_guess, 0x58, 1);
    while ((char)reinterpret_cast<TimedEntry_guess*>(
               &frame_guess.waitStorage_guess[0])->IsActive_guess() != 0) {
        FUN_00600e40_guess(50);
        if (reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess != 0) {
            reinterpret_cast<ConnectionPumpState_guess*>(g_connectionManager_guess)->field4c_guess->Wait_guess(500);
        }
    }

    if (reinterpret_cast<TimedEntry_guess*>(&frame_guess.waitStorage_guess[0])->expired_guess == 0) {
        FUN_00574110_guess("%s requested status for %i, but the response never came in %f seconds.\n",
            g_zoneChar_00905d00_guess->name_guess, zone_guess, 180.0);
    } else if (frame_guess.reply_guess.status_guess != 1) {
        FUN_00574110_guess("%s (%s) requested status for %i (%s), but was denied. reason: %d.\n",
            frame_guess.reply_guess.zoneName_guess,
            reinterpret_cast<NetPlayerNameView_guess*>(g_netPlayer_00905ce4_guess)->name_guess,
            frame_guess.reply_guess.field40_guess, frame_guess.zoneName_guess,
            frame_guess.reply_guess.status_guess);
    }

    g_connection_00905ca0_guess->BeginWait_guess(
        reinterpret_cast<DisconnectWaitState_guess*>(previousWait_guess));
    if (reinterpret_cast<DisconnectOwner_guess*>(frame_guess.owner_guess)->CheckCharSelectDisconnect_guess(
            "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x5333, 1) != 0) {
        return -4;
    }
    return frame_guess.reply_guess.status_guess;
}

// Zones the player. A refusal from IsZoneAvailable prints its reason (-1/0, -2, -3, -6, -7, -8, -9) and
// stays put; an unavailable home zone goes back to char select (OP_Logout 0x61FF). Otherwise places the
// player, shows the zone banner (0x2524), saves (SavePCOnZone), drops its spawn (OP_DeleteSpawn 0x55BC).
// FUNCTION: TITANIUM 0x004AB056
// @early-stop: budget, structural ndiff=129
char GlobalState_guess::MoveToZone_guess(int zone_guess, const char* reason_guess,
    int home_guess, int mode_guess, float y_guess, float x_guess, float z_guess,
    int heading_guess) {
    char zoneName_guess[0x20];
    g_lookupManager_guess->FUN_005f6ed0_guess(zone_guess, zoneName_guess);
    g_zoneValue_009238f8_guess = 0;
    FUN_004b6088_guess()->FUN_004b60c2_guess();
    reinterpret_cast<ZonePlayerOps_guess*>(g_displayPlayer_guess)->SendMovementHistory_guess(1);
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        if (g_displayPlayer_guess == 0 || g_displayPlayer_guess->StandState == 'f') {
            return 0;
        }
        int result_guess = IsZoneAvailable_guess(zone_guess, y_guess, x_guess, z_guess, mode_guess);
        if (result_guess == -4) {
            return 0;
        }
        if (result_guess != 1) {
            bool reset_guess = true;
            if (result_guess == -8) {
                char deniedName_guess[0x40];
                char deniedText_guess[0x100];
                g_lookupManager_guess->FUN_005fa1c0_guess(zone_guess, deniedName_guess, 1);
                FUN_0046da4a_guess(deniedText_guess, 0x22b5, deniedName_guess, 0, 0, 0, 0, 0, 0,
                    0, 0);
                DspChat_guess(deniedText_guess, 0xd, 1);
                reset_guess = false;
                PlayerMotion_guess saved_guess(
                    *reinterpret_cast<PlayerMotion_guess*>(g_displayPlayer_guess->motion_0E8));
                new (&g_displayPlayer_guess->Y) PlayerMotion_guess(saved_guess);
            }
            char homeName_guess[0x20];
            g_lookupManager_guess->FUN_005f6ed0_guess(
                g_zoneChar_00905d00_guess->zoneInstance_guess, homeName_guess);
            if (g_zoneChar_00905d00_guess->field0fc_guess == 4 || home_guess != 0 ||
                NameHasApostrophe_guess(g_zoneChar_00905d00_guess->name_guess) != 0) {
                text_to_client_guess(g_zoneChar_00905d00_guess,
                    "Your Home Zone is unavailable, going back to Character Selection Screen!",
                    0xd);
                g_zoneResult_00923d94_guess = 8;
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x61ff, 0, 0, 1);
                g_zoneFlag_00923d7b_guess = 1;
                Sleep(1000);
                return 0;
            }
            g_lookupManager_guess->FUN_005f6ed0_guess(
                g_zoneChar_00905d00_guess->zoneInstance_guess, homeName_guess);
            FUN_00574110_guess("ERROR: zone (%s) is unavailable (reason: %d).\n",
                homeName_guess, result_guess);
            FUN_00574110_guess(reason_guess);
            if (IsZoneAvailable_guess(g_zoneChar_00905d00_guess->zoneInstance_guess, y_guess,
                    x_guess, z_guess, mode_guess) == -4) {
                return 0;
            }
            if (result_guess == -7) {
                DspChat_guess(pStringTable->getString(0xfc, 0), 0xd, 1);
            } else if (result_guess == -2) {
                DspChat_guess(pStringTable->getString(0x13b9, 0), 0xd, 1);
            } else if (result_guess == -3) {
                DspChat_guess(pStringTable->getString(0x13ba, 0), 0xd, 1);
            } else if (result_guess == -6) {
                DspChat_guess(pStringTable->getString(0x13bc, 0), 0xd, 1);
            } else if (result_guess == -1 || result_guess == 0) {
                DspChat_guess(pStringTable->getString(0x13bb, 0), 0xd, 1);
            } else if (result_guess == -9) {
                DspChat_guess("The destination zone denied entry...", 0xd, 1);
            } else if (g_zoneChar_00905d00_guess->zoneInstance_guess != 0) {
                int home2_guess = g_zoneChar_00905d00_guess->zoneInstance_guess;
                int level_guess = reinterpret_cast<ZoneCharInfo_guess*>(
                    g_zoneChar_00905d00_guess->profile_guess.GetCharInfo2())->field11a4_guess;
                if (g_zoneLookup_00905cc0_guess->FUN_005f6e80_guess(home2_guess) > level_guess) {
                    DspChat_guess(pStringTable->getString(0x3061, 0));
                }
            } else {
                DspChat_guess(pStringTable->getString(0x3062, 0), 0xd, 1);
                reset_guess = true;
            }
            if (reset_guess) {
                ClearVehicleBeforeZone_guess();
            }
            g_globalState_guess->SavePC_guess(0, 1, 0x20);
            return 0;
        }
    }
    if (mode_guess != 2) {
        reinterpret_cast<ResetState_guess*>(g_displayPlayer_guess->pActorInfo)->field158_guess = 0;
        g_zoneChar_00905d00_guess->text_guess.FUN_0040e25c_guess(g_text_0063f53f_guess);
    }
    g_displayPlayer_guess->SpeedY = 0.0f;
    g_displayPlayer_guess->SpeedX = 0.0f;
    g_displayPlayer_guess->SpeedZ = 0.0f;
    g_displayPlayer_guess->field_58 = 0.0f;
    g_displayPlayer_guess->field_54 = 0.0f;
    g_displayPlayer_guess->SpeedRun = 0.0f;
    g_displayPlayer_guess->Y = y_guess;
    g_displayPlayer_guess->X = x_guess;
    g_displayPlayer_guess->Z = z_guess;
    float heading2_guess = (float)heading_guess;
    g_displayPlayer_guess->Heading = heading2_guess;
    g_zoneChar_00905d00_guess->y_guess = y_guess;
    g_zoneChar_00905d00_guess->x_guess = x_guess;
    g_zoneChar_00905d00_guess->z_guess = z_guess;
    g_zoneChar_00905d00_guess->heading_guess = heading2_guess;
    DspChat_guess(pStringTable->getString(0x3063, 0), 0xd, 1);
    char enterName_guess[0x80];
    char enterText_guess[0x100];
    g_lookupManager_guess->FUN_005fa1c0_guess(zone_guess, enterName_guess, 1);
    FUN_0046da4a_guess(enterText_guess, 0x2524, enterName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    FUN_00407dc9_guess()->DisplayText(enterText_guess, 10, 10, 0xc0, 0, 1000, 1000);
    if (g_loopPipeline_0099d3ec_guess != 0) {
        g_loopPipeline_0099d3ec_guess->FUN_005b06a0_guess();
        g_loopPipeline_0099d3ec_guess->FUN_005af250_guess();
        if (g_flag_00923842_guess == 0) {
            g_loopPipeline_0099d3ec_guess->FUN_005af580_guess();
        }
    }
    if (g_displayRoot_guess->field13_guess == 0) {
        ProcessGameEventsAndRender_guess();
    }
    g_zoneAngle_00923d20_guess = g_displayPlayer_guess->CameraAngle;
    g_zoneChar_00905d00_guess->zoneInstance_guess = zone_guess;
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        SavePCOnZone_guess(home_guess);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x55bc,
            &g_displayPlayer_guess->SpawnID, 4, 1);
    } else {
        steve_strncpy_guess(g_zoneName_00903fd8_guess, zoneName_guess, 0x28);
        g_zoneY_00904244_guess = g_displayPlayer_guess->Y;
        g_zoneX_00903eb4_guess = g_displayPlayer_guess->X;
        g_zoneZ_00904224_guess = g_displayPlayer_guess->Z;
        g_zoneHeading_00903eb8_guess = g_displayPlayer_guess->Heading;
        // Offline (sending off) the fog is set locally, with its own range for qrg.
        if (strcmp(zoneName_guess, "qrg") == 0) {
            g_float_00923b64_guess = 60.0f;
            g_float_00923b74_guess = 400.0f;
        } else {
            g_float_00923b64_guess = 100.0f;
            g_float_00923b74_guess = 2000.0f;
        }
    }
    g_zoneFlag_00923d7a_guess = 1;
    WaitForDisconnectAndProcessMessages_guess();
    FUN_0060e450_guess(g_zoneCharName_00905c18_guess, g_zoneChar_00905d00_guess->name_guess);
    if (g_zoneSlotFlag_009043a4_guess == 0) {
        g_zoneSlots_00904390_guess[0] = 0;
        g_zoneSlots_00904390_guess[1] = 0;
        g_zoneSlots_00904390_guess[2] = 0;
        g_zoneSlots_00904390_guess[3] = 0;
        g_zoneSlots_00904390_guess[4] = 0;
    }
    return 1;
}


struct SubObject_guess {
    int field_guess;
    char padding_0004_guess[0x830 - 4];
    void* sender_guess;
    void MailServerAvailable_guess(char flag_guess, int* values_guess);
    void MailServerUnavailable_guess(int unused_guess);
    void MailSendResult_guess(int unused_guess, const char* text_guess, const char* text2_guess,
        char flag_guess, int unused2_guess);
};

struct HolderBase_guess {
    int vptr_guess;
};

// Mail handler slot 0: 'The Universal Chat service is available.' (0x11B0) and, with mail enabled
// (0x923D65), the mail list's counts.
// FUNCTION: TITANIUM 0x0049A5D9
void SubObject_guess::MailServerAvailable_guess(char flag_guess, int* values_guess) {
    if (flag_guess != 0 && sender_guess != 0) {
        reinterpret_cast<GlobalState_guess*>(
            reinterpret_cast<HolderBase_guess*>(this) - 1)->DspChat_guess(
                g_stringTable_guess->Lookup_guess(0x11b0, 0), 2, true);
        if (EQ_GLOBAL(unsigned char, 0x00923D65) != 0) {
            int first_guess = values_guess[0];
            int second_guess = values_guess[1];
            if (g_globalState_guess != 0 &&
                reinterpret_cast<SlotOwner_guess*>(g_globalState_guess)->
                    GetMailManager_guess() != 0) {
                reinterpret_cast<SlotOwner_guess*>(g_globalState_guess)->
                    GetMailManager_guess()->SetMailboxes_guess(
                        first_guess, second_guess, values_guess + 2);
                reinterpret_cast<SlotOwner_guess*>(g_globalState_guess)->
                    GetMailManager_guess()->Set_guess(second_guess);
            }
        }
    }
}

// Mail handler slot 1: 'The Universal Chat service is temporarily unavailable.' (0x11AF).
// FUNCTION: TITANIUM 0x0049A663
void SubObject_guess::MailServerUnavailable_guess(int unused_guess) {
    if (g_stringTable_guess) {
        HolderBase_guess* base_guess = reinterpret_cast<HolderBase_guess*>(this) - 1;
        reinterpret_cast<GlobalState_guess*>(base_guess)->DspChat_guess(
            g_stringTable_guess->Lookup_guess(0x11af, 0), 0xd, 1);
    }
}

// 'Message sent.' (0x11B2) or 'Mail delivery failure to %1 (subject: %2)' (0x11B3).
// FUNCTION: TITANIUM 0x0049A68D
void SubObject_guess::MailSendResult_guess(int unused_guess, const char* text_guess,
    const char* text2_guess, char flag_guess, int unused2_guess) {
    if (flag_guess != 0) {
        reinterpret_cast<GlobalState_guess*>(reinterpret_cast<HolderBase_guess*>(this) - 1)->DspChat_guess(
            pStringTable->getString(0x11b2, 0), 2, 1);
    } else {
        char buffer_guess[4096];
        FUN_0046da4a_guess(buffer_guess, 0x11b3, text_guess, text2_guess, 0, 0, 0, 0, 0, 0, 0);
        reinterpret_cast<GlobalState_guess*>(reinterpret_cast<HolderBase_guess*>(this) - 1)->DspChat_guess(
            buffer_guess, 0xd, 1);
    }
}

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess,
                              const char* p0_guess, const char* p1_guess,
                              const char* p2_guess, const char* p3_guess,
                              const char* p4_guess, const char* p5_guess,
                              const char* p6_guess, const char* p7_guess,
                              const char* p8_guess);

struct FUN_0049a704_callback_guess {
    void Report_guess(int value_guess, unsigned char indexed_guess);
};

// Mail callback: selects entry `value` of the mail list and shows eqstr 0x11B6 with it, or 0x11B7
// with the number when `indexed` is clear.
// FUNCTION: TITANIUM 0x0049A704
void FUN_0049a704_callback_guess::Report_guess(int value_guess, unsigned char indexed_guess) {
    SlotOwner_guess* root_guess = reinterpret_cast<SlotOwner_guess*>(
        reinterpret_cast<unsigned int*>(this) - 1);
    ManagedObject_guess* state_guess = root_guess->GetMailManager_guess();
    if (state_guess != 0) {
        char output_guess[0x1000];
        char number_guess[20];
        if (indexed_guess != 0) {
            state_guess->Set_guess(value_guess);
            FormatText_guess(output_guess, 0x11b6,
                             state_guess->At_guess(value_guess).c_str(),
                             0, 0, 0, 0, 0, 0, 0, 0);
            reinterpret_cast<GlobalState_guess*>(root_guess)->DspChat_guess(
                output_guess, 2, 1);
        } else {
            sprintf(number_guess, "%d", value_guess);
            FormatText_guess(output_guess, 0x11b7, number_guess,
                             0, 0, 0, 0, 0, 0, 0, 0);
            reinterpret_cast<GlobalState_guess*>(root_guess)->DspChat_guess(
                output_guess, 0xd, 1);
        }
    }
}

struct FUN_0049a7f8_state_view_guess {
    unsigned char pad_000[0x1c];
    int selected_id_01c;
};

struct FUN_0049a7f8_callback_guess {
    void Report_guess(int id_guess, unsigned int mode_guess, bool includeMode_guess);
};

// Mail callback for the selected entry `id` only: eqstr 0x11BA, 0x11BB or 0x11BC by `mode`, or 0x11BD
// when `includeMode` is clear.
// FUNCTION: TITANIUM 0x0049A7F8
// @early-stop: budget, diff ndiff=16
void FUN_0049a7f8_callback_guess::Report_guess(int id_guess, unsigned int mode_guess,
                                               bool includeMode_guess) {
    SlotOwner_guess* root_guess = reinterpret_cast<SlotOwner_guess*>(
        reinterpret_cast<unsigned int*>(this) - 1);
    ManagedObject_guess* state_guess = root_guess->GetMailManager_guess();
    if (state_guess != 0) {
        int selectedId_guess = ((FUN_0049a7f8_state_view_guess*)state_guess)->selected_id_01c;
        if (selectedId_guess == id_guess) {
            CXStr text_guess(state_guess->At_guess((unsigned int)id_guess).c_str());
            char output_guess[0x400];
            if (includeMode_guess != 0) {
                if (mode_guess == 0) {
                    FormatText_guess(output_guess, 0x11ba, (char*)text_guess,
                                     0, 0, 0, 0, 0, 0, 0, 0);
                } else if (mode_guess == 1) {
                    FormatText_guess(output_guess, 0x11bb, (char*)text_guess,
                                     0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    char number_guess[16];
                    sprintf(number_guess, (char*)EQ_ARRAY(char, 0x00649A24), mode_guess);
                    FormatText_guess(output_guess, 0x11bc, (char*)text_guess, number_guess,
                                     0, 0, 0, 0, 0, 0, 0);
                }
                reinterpret_cast<GlobalState_guess*>(root_guess)->DspChat_guess(
                    output_guess, 10, 1);
            } else {
                FormatText_guess(output_guess, 0x11bd, (char*)text_guess,
                                 0, 0, 0, 0, 0, 0, 0, 0);
                reinterpret_cast<GlobalState_guess*>(root_guess)->DspChat_guess(
                    output_guess, 0xd, 1);
            }
        }
    }
}

struct MailtoLink_guess {
    // EXTERNAL: TITANIUM 0x0042A8C8 MailtoLink_guess::Format_guess
    std::string Format_guess(const std::string& link_guess);
};

// Sends a mail command on the mail API (+0x834), formatted by the mail list when there is one; with
// no connection prints 'Please wait until we reconnect you ...' (0x11B1).
// FUNCTION: TITANIUM 0x004A95FF
// @early-stop: budget, structural ndiff=33
void GlobalState_guess::SendMailServerCommand_guess(const char* text_guess) {
    if (sender_834_guess != 0) {
        std::string formattedGuess_guess;
        const char* sendText_guess;
        if (g_globalState_guess != 0) {
            ManagedObject_guess* managed_guess = reinterpret_cast<SlotOwner_guess*>(
                g_globalState_guess)->GetMailManager_guess();
            if (managed_guess != 0) {
                std::string input_guess(text_guess);
                std::string formatted_guess = reinterpret_cast<MailtoLink_guess*>(
                    reinterpret_cast<SlotOwner_guess*>(g_globalState_guess)->
                        GetMailManager_guess())->Format_guess(input_guess);
                formattedGuess_guess.assign(formatted_guess, 0, std::string::npos);
                sendText_guess = formattedGuess_guess.c_str();
            } else {
                sendText_guess = text_guess;
            }
        } else {
            sendText_guess = text_guess;
        }
        CXStr_guess sendTextObject_guess(sendText_guess);
        ConvertItemTags(sendTextObject_guess, 0);
        sender_834_guess->Send_guess((char*)sendTextObject_guess);
        sender_834_guess->Cleanup_guess();
    } else {
        reinterpret_cast<CEverQuest*>(this)->dsp_chat(
            pStringTable->getString(0x11b1, 0), 0xd, 1);
    }
}

struct DamagePacket_guess {
    int field00_guess;
    int field04_guess;
    char padding_0008_guess[8];
    unsigned short field10_guess;
    char padding_0012_guess[2];
    unsigned char field14_guess;
    char padding_0015_guess[3];
    int field18_guess;
};

#pragma pack(push, 1)
struct EventSummary_guess {
    unsigned short field00_guess;
    unsigned short field02_guess;
    unsigned char field04_guess;
    unsigned short field05_guess;
    int field07_guess;
    char padding_00b_guess[13];
};
#pragma pack(pop)

struct ActorMarker_guess {
    char padding_0000_guess[0x251];
    unsigned char field251_guess;
};

struct ActorMutation_guess {
    char padding_0000_guess[0x274];
    int field274_guess;
};

struct ContextTargetView_guess {
    char padding_0000_guess[0xc288];
    ActorTarget_guess* pSpawn_c288_guess;
};

struct ForwardedObjectWithArg_guess {
    // EXTERNAL: TITANIUM 0x004DC160 ForwardedObjectWithArg_guess::CloseBank_guess
    void CloseBank_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
ActorTarget_guess* __cdecl FUN_00401b28_guess(int actorId_guess);

#define g_pendingActor_009238d8_guess EQ_GLOBAL(int, 0x009238D8)
#define g_pendingActor_009238dc_guess EQ_GLOBAL(int, 0x009238DC)
#define g_pendingFlag_009238e0_guess EQ_GLOBAL(unsigned char, 0x009238E0)
#define g_actor_00905d10_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905D10)
#define g_actor_00905d14_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905D14)
#define g_actor_00905d1c_guess EQ_GLOBAL(ActorTarget_guess*, 0x00905D1C)
#define g_value_00923cd4_guess EQ_GLOBAL(int, 0x00923CD4)
#define g_loopFlag_009043a4_guess EQ_GLOBAL(unsigned char, 0x009043A4)
#define g_actorSlots_00904390_guess EQ_ARRAY(int, 0x00904390)
#define g_actorSlotFlags_0090424d_guess EQ_ARRAY(unsigned char, 0x0090424D)
#define g_actorSlotFlagsEnd_0090438d_guess EQ_ARRAY(unsigned char, 0x0090438D)
#define g_forwardedObjectWithArg_guess EQ_GLOBAL(ForwardedObjectWithArg_guess*, 0x00850C38)
#define g_contextTargetView_guess EQ_GLOBAL(ContextTargetView_guess*, 0x00905D00)

struct Actor7356_guess;

struct ActorState7356_guess {
    char padding_0000_guess[0x158];
    Actor7356_guess* field158_guess; // 0x158
    char padding_015c_guess[0x106C - 0x15C];
    int field106c_guess; // 0x106C
    int field1070_guess; // 0x1070
    int field1074_guess; // 0x1074
};

struct Actor7356_guess {
    char padding_0000_guess[0x48];
    float speedRun_0048_guess; // 0x48
    char padding_004c_guess[0xC];
    float field58_guess; // 0x58
    char padding_005c_guess[0x1A8 - 0x5C];
    ActorState7356_guess* pActorInfo_01a8_guess; // 0x1A8
    char padding_01ac_guess[0x244 - 0x1AC];
    unsigned char type_0244_guess; // 0x244
    char padding_0245_guess[0xD];
    unsigned char playerClass_0252_guess; // 0x252
    char padding_0253_guess[5];
    unsigned int spawnId_0258_guess; // 0x258
    char padding_025c_guess[4];
    int race_0260_guess; // 0x260
    char padding_0264_guess[0xC];
    int bodyType_0270_guess; // 0x270
};

struct ClassInfo7356_guess {
    char padding_0000_guess[0x119C];
    unsigned char field119c_guess; // 0x119C
};

struct Handler7356_guess {
    // EXTERNAL: TITANIUM 0x004DC05E Handler7356_guess::OpenBank_guess
    void OpenBank_guess(Actor7356_guess* actor_guess);
    // EXTERNAL: TITANIUM 0x0050C6B1 Handler7356_guess::Activate_guess
    void Activate_guess(Actor7356_guess* actor_guess);
};

struct Packet7356_guess {
    unsigned int field0_guess;
    unsigned int field4_guess;
    unsigned int field8_guess;
    unsigned char fieldc_guess;
};

struct SkillPacket7356_guess {
    unsigned int target_guess;
    unsigned int self_guess;
    int values_guess[100];
    float field198_guess;
    char padding_019c_guess[0x24];
};

// EXTERNAL: TITANIUM 0x00466A73 do_consider_guess
void __cdecl do_consider_guess(Actor7356_guess* actor_guess, const char* text_guess);

#define g_self7356_guess EQ_GLOBAL(Actor7356_guess*, 0x00905CE4)
#define g_target7356_guess EQ_GLOBAL(Actor7356_guess*, 0x00905CF8)
#define g_handler_00850c38_guess EQ_GLOBAL(Handler7356_guess*, 0x00850C38)
#define g_handler_00991a90_guess EQ_GLOBAL(Handler7356_guess*, 0x00991A90)
#define g_value_0079c104_guess EQ_GLOBAL(int, 0x0079C104)
#define pinstPvpCurrency_guess EQ_GLOBAL(int, 0x00985C94)
#define g_value_0079dba0_guess EQ_GLOBAL(int, 0x0079DBA0)
#define pinstRadiantCrystalCurrency_guess EQ_GLOBAL(int, 0x0098593C)
#define pinstEbonCrystalCurrency_guess EQ_GLOBAL(int, 0x00985904)
#define g_value_00924848_guess EQ_GLOBAL(int, 0x00924848)
#define g_flag_009858c7_guess EQ_GLOBAL(char, 0x009858C7)

struct Actor998824State_guess {
    char padding_0000_guess[0x68];
    int field68_guess;
    char padding_006c_guess[0x158 - 0x6c];
    int field158_guess;
};

struct Actor998824View_guess {
    char padding_0000_guess[0x1a8];
    Actor998824State_guess* field1a8_guess;
    char padding_01ac_guess[0x238 - 0x1ac];
    float heightOffset_0238_guess;
};

// The CEverQuest this notifier base sits in (the original's `lea ecx,[esi-8]`).
#define owner_of_notifier_guess(self) reinterpret_cast<CEverQuest*>(static_cast<CEverQuest_guess*>(self))

// Popup answers (vtable 0x64988C slot 0); `flags & 5` means accepted. Each popup id sends its reply:
// 0x64 guild invite (OP_GuildInviteAccept, 5 = declined), 0x65 sacrifice, 0x66 translocate, 0x67
// resurrect (OP_RezzAnswer), 0x6E drop item, 0x6F surname, 0x6D guild delete, 0x75 clear surname ...
// FUNCTION: TITANIUM 0x00499A49
// @early-stop: budget, structural ndiff=664
void EverQuestNotifier_guess::DialogResponse_guess(int msg_guess, unsigned int flags_guess,
    NotifyPacket_guess* data_guess) {
#define active_guess ((flags_guess & 5) != 0)
    if (msg_guess > 0x6934) {
        return;
    }
    // 0x6934 is OP_SharedTaskAddPlayer in patch_Titanium.conf; here it answers
    // a task invite (0x108 bytes).
    if (msg_guess == 0x6934) {
        if (active_guess) {
            data_guess->flag04_guess = 1;
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6934, data_guess, 0x108, 1);
        }
        delete data_guess;
        return;
    }
    switch (msg_guess) {
    case 0x64: {
        NotifyBuf88_guess buf_guess;
        memset(&buf_guess, 0, 0x88);
        strcpy(buf_guess.charName40_guess, g_displayCharData_guess->Character.Name);
        strcpy(buf_guess.name00_guess, data_guess->name40_guess);
        buf_guess.f84_guess = data_guess->f80_guess;
        buf_guess.f80_guess = active_guess ? data_guess->f84_guess : 5;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x61d0, &buf_guess, 0x88, 1);
        delete data_guess;
        return;
    }
    case 0x65: {
        NotifyBuf0C_guess buf_guess;
        buf_guess.zero00_guess = 0;
        buf_guess.field04_guess = g_displayPlayer_guess->SpawnID;
        buf_guess.active08_guess = active_guess;
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(active_guess ? 0x235f : 0x2360, 0), 0x111, true);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x727a, &buf_guess, 0xc, 1);
        return;
    }
    case 0x66: {
        NotifyBuf5C_guess buf_guess;
        if (!active_guess) {
            buf_guess.f58_guess = -1;
            owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0x2368, 0), 0x111, true);
        } else {
            buf_guess.f58_guess = 1;
        }
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x8258, &buf_guess, 0x5c, 1);
        return;
    }
    case 0x67:
        data_guess->flagE0_guess = active_guess;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6219, data_guess, 0xe4, 1);
        delete data_guess;
        return;
    case 0x68:
        strcpy(data_guess->name40_guess, g_displayCharData_guess->Character.Name);
        data_guess->f88_guess = active_guess ? 0 : -2;
        // 0x186D, 0x36F4, 0x46B1, 0x3274, 0x9C, 0x3D05 and 0x6EF5 are not in patch_Titanium.conf.
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x186d, data_guess, 0x8c, 1);
        delete data_guess;
        return;
    case 0x69:
        strcpy(data_guess->name40_guess, g_displayCharData_guess->Character.Name);
        data_guess->f88_guess = active_guess ? 0 : -2;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x36f4, data_guess, 0x8c, 1);
        delete data_guess;
        return;
    case 0x6a:
        data_guess->flagE8_guess = (flags_guess & 7) != 0;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x46b1, data_guess, 0xec, 1);
        delete data_guess;
        return;
    case 0x6b:
        if (!active_guess) {
            return;
        }
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0x228, 0), 0xd, true);
        // OP_BecomePVPPrompt.
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x36b2, 0, 0, 1);
        return;
    case 0x6c:
        if (active_guess) {
            owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0xd19, 0), 0xf, true);
            char buf_guess[0x4c];
            strcpy(buf_guess, g_displayPlayer_guess->Name);
            // OP_VetClaimRequest with the player's name.
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6ba0, buf_guess, 0x4c, 1);
            return;
        }
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0xd16, 0), 0xf, true);
        return;
    case 0x6d: {
        if (!active_guess) {
            return;
        }
        NotifyBuf44_guess buf_guess;
        memset(&buf_guess, 0, 0x44);
        buf_guess.f00_guess = g_displayCharData_guess->pad_0D38[(0xE0C - 0xD38) / 4];
        strcpy(buf_guess.name04_guess, g_displayCharData_guess->Character.Name);
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6cce, &buf_guess, 0x44, 1);
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0x2365, 0), 0x111, true);
        return;
    }
    case 0x6e:
        if (!active_guess) {
            return;
        }
        reinterpret_cast<GlobalState_guess*>(static_cast<CEverQuest_guess*>(this))->DropHeldItemOnGround(0);
        return;
    case 0x6f: {
        if (!active_guess) {
            delete[] data_guess;
            return;
        }
        NotifyBuf64_guess buf_guess;
        memset(&buf_guess, 0, 0x64);
        strcpy(buf_guess.name00_guess, g_displayCharData_guess->Character.Name);
        buf_guess.zero40_guess = 0;
        strcpy(buf_guess.text44_guess, reinterpret_cast<const char*>(data_guess));
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x4668, &buf_guess, 0x64, 1);
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0x235b, 0), 0xf, true);
        delete[] data_guess;
        return;
    }
    case 0x72:
        if (active_guess) {
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6ef5, data_guess, 0x28, 1);
        }
        delete data_guess;
        return;
    case 0x75:
        if (!active_guess) {
            return;
        }
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6cdb, 0, 0, 1);
        return;
    case 0x76:
    case 0x77:
    case 0x78:
        if (active_guess) {
            // OP_AugmentItem; popups 0x76-0x78 also release a pending-request count.
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x539b, data_guess, 8, 1);
        }
        if (g_value_009248d0_guess < 1) {
            g_value_009248d0_guess = 0;
        } else {
            g_value_009248d0_guess = g_value_009248d0_guess - 1;
        }
        delete data_guess;
        return;
    case 0x79:
        if (active_guess) {
            EQ_CharacterProfile_guess* profile_guess =
                reinterpret_cast<EQ_CharacterProfile_guess*>(&g_displayCharData_guess->Character.list);
            NotifyCharInfo_guess* info_guess =
                reinterpret_cast<NotifyCharInfo_guess*>(profile_guess->GetCharInfo2());
            g_contextAction_guess->UpdateItemSlot_guess(g_contextObject_guess, data_guess->id00_guess,
                reinterpret_cast<ContextEntry_guess*>(info_guess->f88_guess), 0);
            pinstCInvSlotMgr_guess->MoveItem(0x1e, data_guess->id00_guess, 1, 1);
            pinstCCursorAttachment_guess->Deactivate();
            int id_guess = data_guess->id00_guess;
            if (id_guess == 0xd || id_guess == 0xe || id_guess == 0xb) {
                g_playerAction_guess->UpdateEquipmentDisplay_guess(id_guess);
            }
            if (data_guess->id00_guess < 0x1f) {
                UpdateLight_guess(g_displayCharData_guess);
            }
            g_textProcessor_guess->WavePlay_guess(0x92, 0);
            profile_guess = reinterpret_cast<EQ_CharacterProfile_guess*>(&g_displayCharData_guess->Character.list);
            info_guess = reinterpret_cast<NotifyCharInfo_guess*>(profile_guess->GetCharInfo2());
            g_displayFlag_guess->flag10_guess = info_guess->f88_guess != 0;
            g_displayCharData_guess->field_C28C = 1;
            g_displayCharData_guess->field_C348 = 0;
        }
        if (g_value_009248d0_guess < 1) {
            g_value_009248d0_guess = 0;
        } else {
            g_value_009248d0_guess = g_value_009248d0_guess - 1;
        }
        delete data_guess;
        return;
    case 0x7b: {
        if (!active_guess) {
            delete[] data_guess;
            return;
        }
        NotifyBuf84_guess buf_guess;
        memset(&buf_guess, 0, 0x84);
        strcpy(buf_guess.name40_guess, g_displayCharData_guess->Character.Name);
        buf_guess.zero80_guess = 0;
        strcpy(buf_guess.text00_guess, reinterpret_cast<const char*>(data_guess));
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x3274, &buf_guess, 0x84, 1);
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0x1755, 0), 0xf, true);
        delete[] data_guess;
        return;
    }
    case 0x7c:
        data_guess->flagE8_guess = (flags_guess & 7) != 0;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x9c, data_guess, 0xec, 1);
        delete data_guess;
        return;
    case 0x7d: {
        if (!active_guess) {
            owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0xe11, 0), 0xf, true);
            return;
        }
        owner_of_notifier_guess(this)->dsp_chat(pStringTable->getString(0xe10, 0), 0xf, true);
        char buf_guess[0x48];
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x3d05, buf_guess, 0x48, 1);
        return;
    }
    default:
        return;
    }
#undef active_guess
}

// Loot request for a corpse (type >= 2) within 1.6 x its size + 14, refused while busy. A request
// still pending is first cancelled with opcode 0x841 (not in patch_Titanium.conf); then OP_LootRequest
// (0x6F90) with the corpse id.
// FUNCTION: TITANIUM 0x00499824
int GlobalState_guess::LootCorpse_guess(Actor7356_guess* actor_guess, int zero_guess) {
    if (actor_guess != 0 && actor_guess->type_0244_guess >= 2 &&
        g_self7356_guess != 0 &&
        reinterpret_cast<Actor998824View_guess*>(g_self7356_guess)->field1a8_guess->field68_guess == 0 &&
        reinterpret_cast<Actor998824View_guess*>(g_self7356_guess)->field1a8_guess->field158_guess == 0 &&
        g_value_009248d4_guess == 0 && g_value_009248d0_guess == 0 &&
        g_value_00923994_guess == 0 && EQ_GLOBAL(int, 0x00905D18) == 0) {
        float limit_guess = reinterpret_cast<Actor998824View_guess*>(actor_guess)->heightOffset_0238_guess;
        if (g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
            reinterpret_cast<int>(g_self7356_guess), EQ_GLOBAL(float, 0x00640E5C)) >
            limit_guess * 1.6f + 14.0f) {
            DspChat_guess(g_stringTable_guess->Lookup_guess(0x3066, 0), 0xd, 1);
            return 0;
        }
        ++g_value_009248d4_guess;
        if (g_value_009248d4_guess != 1) {
            int packet_guess[0x5c / 4];
            packet_guess[0] = -4;
            packet_guess[1] = g_value_009248d4_guess;
            packet_guess[2] = 0xb;
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x841,
                packet_guess, 0x5c, 1);
        }
        EQ_GLOBAL(Actor7356_guess*, 0x00905D18) = actor_guess;
        g_value_009248d4_guess = 1;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x6f90,
            &actor_guess->spawnId_0258_guess, 4, 1);
        return 1;
    }
    return 0;
}

// Targets the clicked spawn (in char select it picks that character's slot instead) and, when 0x9254EF
// is set, prints its description: name line 0x1A7C/0x1A87 plus a gender, class or race line. Then
// offers a trade (RequestTrade) with an item on the cursor or while 0x905D24+0x11 is set.
// FUNCTION: TITANIUM 0x004A6F0E
// @early-stop: budget, structural ndiff=160
void GlobalState_guess::LeftClickedOnPlayer(ActorTarget_guess* target_guess) {
    GlobalState_guess* self_guess = this;
    InputOwner_guess* inputOwner_guess = g_inputOwner_00850b9c_guess;
    ActorTarget_guess* previousTarget_guess = g_actorTarget_00905d04_guess;
    if (inputOwner_guess != 0) {
        if (inputOwner_guess->field1e2_guess != 0) {
            int index_guess = 0;
            do {
                if (_stricmp(self_guess->charNames_guess[index_guess], target_guess->name_guess) == 0) {
                    inputOwner_guess->SelectCharacter_guess(index_guess, 1);
                    break;
                }
                ++index_guess;
            } while (index_guess < 8);
        }
        return;
    }

    if (previousTarget_guess != 0) {
        unsigned int previousValue_guess = previousTarget_guess->spawnId_0258_guess;
        ChatRecord_guess* record_guess = FUN_004c94ae_guess();
        record_guess->fieldf0_guess = previousValue_guess;
    }

    bool useTargetName_guess = true;
    int messageId_guess = 0;
    int messageType_guess = 0;
    g_actorTarget_00905d04_guess = target_guess;
    if ((target_guess == 0 || target_guess->race_0260_guess > 0x8CC ||
            (target_guess->bodyType_0270_guess != 0x0B && target_guess->bodyType_0270_guess != 0x41 &&
                target_guess->bodyType_0270_guess != 0x43 && target_guess->bodyType_0270_guess != 0x3C) ||
            (g_actorTarget_00905d04_guess = previousTarget_guess,
                target_guess == previousTarget_guess)) &&
        g_actorTarget_00905d04_guess->playerClass_0252_guess == '>') {
        useTargetName_guess = false;
        messageId_guess = 0x1A86;
        messageType_guess = 0x1A81;
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x22, 0);
    }

    if (target_guess != 0) {
        if (target_guess->type_0244_guess == 0) {
            messageId_guess = 0x1A88;
            if (target_guess == g_selectedActor_00905ce4_guess) {
                messageType_guess = 0x1A8B;
            } else if (target_guess->gender_024e_guess == 0) {
                messageType_guess = 0x1A89;
            } else if (target_guess->gender_024e_guess == 1) {
                messageType_guess = 0x1A8A;
            } else {
                messageType_guess = 0x1A8D;
            }
        } else {
            unsigned char code_guess = (unsigned char)target_guess->playerClass_0252_guess;
            if (target_guess->race_0260_guess == 0x8D) {
                useTargetName_guess = false;
                messageId_guess = 0x180C;
                messageType_guess = 0x1A7E;
            } else if (code_guess == '(') {
                messageId_guess = 0x5CE;
                messageType_guess = 0x1A83;
            } else if (code_guess == ')') {
                messageId_guess = 0x5CD;
                messageType_guess = 0x1A82;
            } else if (code_guess == '<') {
                messageId_guess = 0x253;
                messageType_guess = 0x1A7F;
            } else if (code_guess == '=') {
                messageId_guess = 0x1D7F;
                messageType_guess = 0x1A80;
            } else if ((code_guess < 0x14 || code_guess > 0x22) ||
                g_charData_guess->IsMyClassGuildmaster_guess(target_guess) == 0) {
                if (target_guess->type_0244_guess < 2 || target_guess->race_0260_guess >= 100) {
                    if (target_guess->race_0260_guess > 0x8CC ||
                        target_guess->bodyType_0270_guess == 0x0B ||
                        target_guess->bodyType_0270_guess == 0x41 ||
                        target_guess->bodyType_0270_guess == 0x43 ||
                        target_guess->bodyType_0270_guess == 0x3C) {
                        messageId_guess = 0;
                        messageType_guess = 0;
                    } else if (target_guess->gender_024e_guess == 0) {
                        messageId_guess = 0x1A70;
                        messageType_guess = 0x1A8E;
                    } else if (target_guess->gender_024e_guess == 1) {
                        messageId_guess = 0x1A70;
                        messageType_guess = 0x1A8F;
                    } else {
                        messageId_guess = 0x1A70;
                        messageType_guess = 0x1A85;
                    }
                } else {
                    messageId_guess = 0x1A6F;
                    messageType_guess = 0x1A7D;
                }
            } else {
                messageId_guess = this->GetClassDescStringId_guess(code_guess);
                messageType_guess = 0x1A84;
            }
        }
    }

    if (messageId_guess != 0 && messageType_guess != 0 && g_flag_009254ef_guess != 0) {
        char buffer_guess[0x200];
        CXStr firstText_guess;
        CXStr secondText_guess;
        if (useTargetName_guess == 0) {
            FUN_0046da4a_guess(buffer_guess, 0x1A87,
                pStringTable->getString(messageId_guess, 0), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            FUN_0046da4a_guess(buffer_guess, 0x1A7C,
                pStringTable->getString(messageId_guess, 0),
                self_guess->trimName_guess(target_guess->name_guess),
                0, 0, 0, 0, 0, 0, 0);
        }
        firstText_guess = buffer_guess;
        FUN_0046da4a_guess(buffer_guess, messageType_guess,
            pStringTable->getString(messageId_guess, 0), 0, 0, 0, 0, 0, 0, 0, 0);
        secondText_guess = buffer_guess;
        pEverQuest->dsp_chat(firstText_guess, 0x0F, true);
        pEverQuest->dsp_chat(secondText_guess, 0x0F, true);
    }

    TargetInfoView_guess* info_guess = reinterpret_cast<TargetInfoView_guess*>(
        g_charData_guess->Info_guess());
    if (info_guess->field88_guess != 0 || g_targetDisplayFlag_00905d24_guess->field11_guess != 0) {
        this->RequestTrade_guess(target_guess);
    }
}

// Right click, if IsOkToTransact: loots a corpse; NPCs within 20 units open by class (+0x252, EQEmu
// numbers): 41 merchant, 40/66 bankers, 20-35 GM trainer of your class, 63/64 tribute masters, 59-61
// and 65-68 special merchants; traders and buyers their shops; a boat is boarded or left.
// FUNCTION: TITANIUM 0x004A7356
// @early-stop: budget, structural ndiff=47
void GlobalState_guess::RightClickedOnPlayer(Actor7356_guess* actor_guess) {
    if (IsOkToTransact_guess() == 0) {
        return;
    }
    Packet7356_guess packet_guess;
    char text_guess[512];
    SkillPacket7356_guess skill_guess;
    if (actor_guess != g_self7356_guess) {
        unsigned char type_guess = actor_guess->type_0244_guess;
        if (type_guess >= 2) {
            if (LootCorpse_guess(actor_guess, 0) != 0) {
                return;
            }
        } else {
            unsigned char race_guess = actor_guess->playerClass_0252_guess;
            if (race_guess == 0x3c) {
                if ((reinterpret_cast<EQPCFlagData_guess*>(g_displayCharData_guess)->fieldc38c_guess[
                        g_displayCharData_guess->vbtable_C284[1]] & 0x20) != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    g_resetTarget_009232f0_guess->RequestAdventureInfo_guess(actor_guess);
                    return;
                }
            } else if (race_guess == 0x3d) {
                if ((reinterpret_cast<EQPCFlagData_guess*>(g_displayCharData_guess)->fieldc38c_guess[
                        g_displayCharData_guess->vbtable_C284[1]] & 0x20) != 0 &&
                    pinstCPointMerchantWnd_guess != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    pinstCPointMerchantWnd_guess->connect_guess(actor_guess, g_value_0079c104_guess);
                }
            } else if (race_guess == 0x3b) {
                if (pinstCPointMerchantWnd_guess != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    pinstCPointMerchantWnd_guess->connect_guess(actor_guess, pinstPvpCurrency_guess);
                }
            } else if (race_guess == 0x41) {
                if (pinstCPointMerchantWnd_guess != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    pinstCPointMerchantWnd_guess->connect_guess(actor_guess, g_value_0079dba0_guess);
                }
            } else if (race_guess == 0x43) {
                if (pinstCPointMerchantWnd_guess != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    pinstCPointMerchantWnd_guess->connect_guess(actor_guess, pinstRadiantCrystalCurrency_guess);
                }
            } else if (race_guess == 0x44) {
                if (pinstCPointMerchantWnd_guess != 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    pinstCPointMerchantWnd_guess->connect_guess(actor_guess, pinstEbonCrystalCurrency_guess);
                }
            } else if (race_guess == 0x29) {
                if (g_actor_00905d10_guess == 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    g_contextObject_guess->fieldc280_guess.RemoveInvisibility_guess(0);
                    g_value_009248d4_guess = 1;
                    packet_guess.field0_guess = actor_guess->spawnId_0258_guess;
                    packet_guess.field4_guess = g_self7356_guess->spawnId_0258_guess;
                    if (g_flag_009858c7_guess != 0) {
                        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
                        pEverQuest->dsp_chat(pStringTable->getString(0x5ba, 0), 0xd, true);
                    }
                    if (g_flag_009858c8_guess != 0) {
                        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
                        pEverQuest->dsp_chat(pStringTable->getString(0x117, 0), 0xd, true);
                    }
                    // OP_ShopRequest; opening any of these windows stops auto attack and auto fire first.
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x45f9, &packet_guess, 0x10, 1);
                    return;
                }
            } else if (race_guess == 0x3f || race_guess == 0x40) {
                if (g_actor_00905d10_guess == 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    g_contextObject_guess->fieldc280_guess.RemoveInvisibility_guess(0);
                    g_value_009248d4_guess = 1;
                    if (g_flag_009858c7_guess != 0) {
                        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
                        pEverQuest->dsp_chat(pStringTable->getString(0x5ba, 0), 0xd, true);
                    }
                    if (g_flag_009858c8_guess != 0) {
                        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
                        pEverQuest->dsp_chat(pStringTable->getString(0x117, 0), 0xd, true);
                    }
                    if (actor_guess->playerClass_0252_guess == 0x3f) {
                        packet_guess.field8_guess = actor_guess->spawnId_0258_guess;
                        packet_guess.field4_guess = g_self7356_guess->spawnId_0258_guess;
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x512e,
                            &packet_guess.field4_guess, 0xc, 1);
                    } else if (actor_guess->playerClass_0252_guess == 0x40) {
                        packet_guess.field8_guess = actor_guess->spawnId_0258_guess;
                        packet_guess.field4_guess = g_self7356_guess->spawnId_0258_guess;
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x60b6,
                            &packet_guess.field4_guess, 0xc, 1);
                    }
                    return;
                }
            } else if (actor_guess->race_0260_guess == 0x8d && type_guess == 1) {
                packet_guess.field8_guess = actor_guess->spawnId_0258_guess;
                if (g_target7356_guess == actor_guess) {
                    packet_guess.fieldc_guess = 0;
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x2c81,
                        &packet_guess.field8_guess, 8, 1);
                    g_target7356_guess = g_self7356_guess;
                    actor_guess->speedRun_0048_guess = 0.0f;
                    actor_guess->field58_guess = 0.0f;
                } else {
                    Actor7356_guess* owner_guess = g_self7356_guess->pActorInfo_01a8_guess->field158_guess;
                    if (owner_guess != 0 && owner_guess == actor_guess) {
                        packet_guess.fieldc_guess = 1;
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x2c81,
                            &packet_guess.field8_guess, 8, 1);
                    }
                }
                return;
            } else if (race_guess == 0x28) {
                if (g_actor_00905d14_guess == 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    g_handler_00850c38_guess->OpenBank_guess(actor_guess);
                    return;
                }
            } else if (race_guess == 0x42) {
                if (g_actor_00905d14_guess == 0 &&
                    g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    g_handler_00991a90_guess->Activate_guess(actor_guess);
                    return;
                }
            } else if (race_guess >= 0x14 && race_guess <= 0x23) {
                if (g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                        reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                    ContextSelector_guess* selector_guess = reinterpret_cast<ContextSelector_guess*>(
                        &g_contextObject_guess->field0c_guess[
                            g_contextObject_guess->field08_guess->field04_guess - 4]);
                    ClassInfo7356_guess* info_guess = reinterpret_cast<ClassInfo7356_guess*>(
                        selector_guess->finder_guess.GetCharInfo2());
                    unsigned char class_guess = actor_guess->playerClass_0252_guess;
                    if (info_guess->field119c_guess + 0x13 == class_guess) {
                        if (g_actor_00905d1c_guess == 0) {
                            g_contextObject_guess->fieldc280_guess.RemoveInvisibility_guess(0);
                            g_value_009248d4_guess = 1;
                            skill_guess.target_guess = actor_guess->spawnId_0258_guess;
                            skill_guess.self_guess = g_self7356_guess->spawnId_0258_guess;
                            for (int i_guess = 0; i_guess < 100; i_guess++) {
                                skill_guess.values_guess[i_guess] = 0;
                            }
                            skill_guess.field198_guess = 0.0f;
                            if (g_flag_009858c7_guess != 0) {
                                EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
                                pEverQuest->dsp_chat(pStringTable->getString(0x5ba, 0), 0xd, true);
                            }
                            if (g_flag_009858c8_guess != 0) {
                                EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
                                pEverQuest->dsp_chat(pStringTable->getString(0x117, 0), 0xd, true);
                            }
                            // OP_GMTraining; a trainer of another class prints 0x5BB instead.
                            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x238f,
                                &skill_guess, 0x1c0, 1);
                        }
                    } else {
                        FUN_0046da4a_guess(text_guess, 0x5bb,
                            g_globalState_guess->GetClassDesc(class_guess - 0x13),
                            0, 0, 0, 0, 0, 0, 0, 0);
                        pEverQuest->dsp_chat(text_guess, 10, true);
                    }
                }
            } else {
                ActorState7356_guess* state_guess = actor_guess->pActorInfo_01a8_guess;
                if (state_guess != 0) {
                    if (state_guess->field106c_guess != 0) {
                        if (g_actor_00905d10_guess == 0 &&
                            g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                                reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                            memset(&packet_guess, 0, sizeof(packet_guess));
                            g_contextObject_guess->fieldc280_guess.RemoveInvisibility_guess(0);
                            g_value_009248d4_guess = 1;
                            packet_guess.field0_guess = actor_guess->spawnId_0258_guess;
                            if (g_flag_009858c7_guess != 0) {
                                EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
                                pEverQuest->dsp_chat(pStringTable->getString(0x5ba, 0), 0xd, true);
                            }
                            if (g_flag_009858c8_guess != 0) {
                                EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
                                pEverQuest->dsp_chat(pStringTable->getString(0x117, 0), 0xd, true);
                            }
                            if (actor_guess->pActorInfo_01a8_guess->field1070_guess != 0) {
                                pEverQuest->dsp_chat(pStringTable->getString(0x5bc, 0), 10, true);
                            } else if (g_self7356_guess->spawnId_0258_guess != actor_guess->spawnId_0258_guess) {
                                // OP_TraderShop; OP_Barter (0x7460) below is the buyer case.
                                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x35e8,
                                    &packet_guess, 0x10, 1);
                            } else {
                                pEverQuest->dsp_chat(pStringTable->getString(0x5bd, 0), 10, true);
                            }
                            return;
                        }
                    } else if (state_guess != 0 && state_guess->field1074_guess != 0 &&
                        g_actor_00905d10_guess == 0 &&
                        g_ownedDisplay_guess->PlayerDistance_guess(actor_guess,
                            reinterpret_cast<int>(g_self7356_guess), 1.0f) <= 20.0f) {
                        g_contextObject_guess->fieldc280_guess.RemoveInvisibility_guess(0);
                        g_value_009248d4_guess = 1;
                        packet_guess.field4_guess = 10;
                        packet_guess.field8_guess = actor_guess->spawnId_0258_guess;
                        if (g_flag_009858c7_guess != 0) {
                            EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
                            pEverQuest->dsp_chat(pStringTable->getString(0x5ba, 0), 0xd, true);
                        }
                        if (g_flag_009858c8_guess != 0) {
                            EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
                            pEverQuest->dsp_chat(pStringTable->getString(0x117, 0), 0xd, true);
                        } else if (g_self7356_guess->spawnId_0258_guess != actor_guess->spawnId_0258_guess) {
                            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7460,
                                &packet_guess.field4_guess, 0xc, 1);
                        } else {
                            pEverQuest->dsp_chat(pStringTable->getString(0x5bd, 0), 10, true);
                        }
                        return;
                    }
                }
            }
        }
        if (actor_guess->race_0260_guess < 0x8cd) {
            int kind_guess = actor_guess->bodyType_0270_guess;
            if (kind_guess == 0xb || kind_guess == 0x41 || kind_guess == 0x43 ||
                kind_guess == 0x3c) {
                return;
            }
        }
        do_consider_guess(actor_guess, g_text_0063fe10_guess);
    }
    if (g_ownedDisplay_guess->field10_guess == 0 && g_value_00924848_guess != 0) {
        g_globalState_guess->doInspect(reinterpret_cast<SourceRecord_guess*>(actor_guess));
    }
}

struct ResetRun_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0c_guess;
};

struct CameraInterface_guess {
    virtual void RefreshCounts_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0c_guess() = 0;
    virtual void SetCamera10_guess(float value_guess) = 0;
    virtual void SetCamera14_guess(float value_guess) = 0;
    virtual void SetCamera18_guess(float value_guess) = 0;
    virtual void Slot1c_guess() = 0;
    virtual void SetCamera20_guess(float value_guess) = 0;
    virtual void Slot24_guess() = 0;
    virtual void SetCamera28_guess(float value_guess) = 0;
};

#define g_camera_guess EQ_GLOBAL(CameraInterface_guess*, 0x00925518)

// Zone-in step 3: clears the per-zone globals, loads the zone (the character's +0xC4 zone, else 1),
// asks for the zone data (OP_ReqNewZone 0x7AC5) and resets cameras, vision and click targets. A load
// failure only logs and sets +0xB50.
// FUNCTION: TITANIUM 0x004A861D
// @early-stop: budget, structural ndiff=15
void CEverQuest_guess::EnterZone(int unused_guess) {
    int negativeOne_guess = -1;
    char zoneName_guess[20];
    int* clearValue_guess = EQ_ARRAY(int, 0x00925520);
    for (int clearCount_guess = 0x100; clearCount_guess != 0; --clearCount_guess) {
        *clearValue_guess = 0;
        ++clearValue_guess;
    }
    EQ_GLOBAL(int, 0x00923888) = 0;
    EQ_GLOBAL(int, 0x00923890) = 0;
    EQ_GLOBAL(int, 0x00923CB4) = 0;
    EQ_GLOBAL(int, 0x00923D88) = 0;
    EQ_GLOBAL(int, 0x00923D8C) = 0;

    int* resetValue_guess = EQ_ARRAY(int, 0x00923964);
    do {
        resetValue_guess[-10] = 0;
        *resetValue_guess = 0;
        ++resetValue_guess;
    } while ((int)resetValue_guess < (int)EQ_ARRAY(int, 0x0092398C));

    EQ_GLOBAL(int, 0x0092398C) = 0;
    EQ_GLOBAL(int, 0x00923D28) = 0;
    EQ_GLOBAL(unsigned char, 0x00923CC0) = 0;
    EQ_GLOBAL(int, 0x00923CC4) = negativeOne_guess;
    EQ_GLOBAL(int, 0x00923CC8) = 0;
    EQ_GLOBAL(int, 0x00923CCC) = 0;
    EQ_GLOBAL(int, 0x00923CD0) = 0;
    EQ_GLOBAL(int, 0x00923CD4) = 0;
    EQ_GLOBAL(int, 0x00923CD8) = 0;
    EQ_GLOBAL(int, 0x00923CDC) = 0;
    FUN_0060e450_guess(EQ_ARRAY(char, 0x00923CE0),
        EQ_ARRAY(const char, 0x0063F53F));
    int defaultWorld_guess = 1;

    EQ_GLOBAL(int, 0x00923D00) = 0;
    EQ_GLOBAL(int, 0x00923D04) = negativeOne_guess;
    EQ_GLOBAL(unsigned char, 0x00923D2C) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2D) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2E) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2F) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D30) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D31) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D32) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D33) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D34) = 0;
    EQ_GLOBAL(int, 0x0092386C) = negativeOne_guess;
    EQ_GLOBAL(int, 0x00923870) = negativeOne_guess;
    EQ_GLOBAL(unsigned char, 0x00923874) = 0;
    EQ_GLOBAL(unsigned char, 0x00923875) = 0;
    EQ_GLOBAL(unsigned char, 0x00923877) = 0;
    EQ_GLOBAL(unsigned char, 0x00923876) = 0;
    EQ_GLOBAL(int, 0x009238D8) = 0;
    EQ_GLOBAL(int, 0x009238DC) = 0;
    EQ_GLOBAL(int, 0x009238E4) = 0;
    EQ_GLOBAL(unsigned char, 0x009238E0) = 0;
    EQ_GLOBAL(int, 0x00923CBC) = 0;
    EQ_GLOBAL(int, 0x00923CB4) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D7A) = 0;
    EQ_GLOBAL(unsigned char, 0x009239DC) = 0;
    EQ_GLOBAL(int, 0x009239B8) = 0;
    EQ_GLOBAL(int, 0x009237B0) = defaultWorld_guess;
    EQ_GLOBAL(int, 0x009239C0) = 0;
    EQ_GLOBAL(int, 0x009239C4) = 0;
    EQ_GLOBAL(int, 0x009239C8) = 0;
    EQ_GLOBAL(int, 0x009239CC) = 0;
    EQ_GLOBAL(int, 0x009239D0) = 0;
    EQ_GLOBAL(int, 0x009239D4) = 0;
    EQ_GLOBAL(int, 0x009239D8) = 0;
    EQ_GLOBAL(unsigned char, 0x00923842) = 0;

    FUN_004c94ae_guess()->fieldf4_guess = 0;
    FUN_004c94ae_guess()->fieldf0_guess = 0;
    FUN_004c94ae_guess()->fieldf8_guess = 0;

    EQ_GLOBAL(int, 0x00923998) = 0;
    EQ_GLOBAL(int, 0x00923994) = 0;
    EQ_GLOBAL(int, 0x00905D28) = 0;
    EQ_GLOBAL(int, 0x009239A8) = 0;
    EQ_GLOBAL(int, 0x009239AC) = 0;
    EQ_GLOBAL(int, 0x009239B0) = 0;
    EQ_GLOBAL(int, 0x00923CA4) = 0;
    EQ_GLOBAL(int, 0x00923CA0) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2C) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2D) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2E) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2F) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D30) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D31) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D32) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D33) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D34) = 0;

    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
    EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    EQ_GLOBAL(float, 0x00923D90) = 0.0f;
    EQ_GLOBAL(int, 0x00923838) = 0;
    EQ_GLOBAL(int, 0x0092383C) = 0;
    EQ_GLOBAL(unsigned char, 0x00923843) = 0;
    EQ_GLOBAL(int, 0x00923D40) = 0;
    EQ_GLOBAL(int, 0x00923D44) = 0;
    EQ_GLOBAL(int, 0x00923D48) = 0;
    EQ_GLOBAL(int, 0x00923D4C) = 0;
    EQ_GLOBAL(int, 0x00923D50) = 0;
    EQ_GLOBAL(int, 0x00923D54) = 0;
    EQ_GLOBAL(int, 0x00923D88) = 0;
    EQ_GLOBAL(int, 0x00923D8C) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D78) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D79) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D1C) = 0;
    EQ_GLOBAL(unsigned char, 0x009237B7) = 0;
    EQ_GLOBAL(int, 0x00923860) = 0;
    EQ_GLOBAL(int, 0x00923868) = 0;
    EQ_GLOBAL(int, 0x00923864) = 0;
    EQ_GLOBAL(int, 0x0092478C) = 0;
    EQ_GLOBAL(int, 0x00923CB8) = 0;
    ResetRun_guess* resetRun_guess = EQ_ARRAY(ResetRun_guess, 0x00923D08);
    resetRun_guess->field00_guess = 0;
    resetRun_guess->field04_guess = 0;
    resetRun_guess->field08_guess = 0;
    resetRun_guess->field0c_guess = 0;
    EQ_GLOBAL(int, 0x00923850) = 0;
    EQ_GLOBAL(int, 0x00923854) = 0;
    EQ_GLOBAL(int, 0x00923858) = 0;
    EQ_GLOBAL(int, 0x0092385C) = 0;
    EQ_GLOBAL(int, 0x00923888) = 0;
    EQ_GLOBAL(int, 0x00923890) = 0;
    EQ_GLOBAL(int, 0x0092388C) = 0;
    EQ_GLOBAL(int, 0x00923894) = 0;
    int worldValue_guess = defaultWorld_guess;
    EQ_GLOBAL(int, 0x00905CE0) = 0;
    EQ_GLOBAL(int, 0x00905D04) = 0;
    EQ_GLOBAL(int, 0x00905CF0) = 0;
    EQ_GLOBAL(int, 0x00905CEC) = 0;
    EQ_GLOBAL(int, 0x00905D10) = 0;
    EQ_GLOBAL(int, 0x00905D14) = 0;
    EQ_GLOBAL(int, 0x00905D18) = 0;
    EQ_GLOBAL(int, 0x00905D1C) = 0;

    int lookupValue_guess = 0;
    if (g_contextObject_guess != 0) {
        lookupValue_guess = *reinterpret_cast<int*>(
            g_contextObject_guess->field44_guess +
            g_contextObject_guess->field08_guess->field04_guess + 0xC4);
        if (lookupValue_guess != 0) {
            worldValue_guess = lookupValue_guess;
            g_lookupManager_guess->FUN_005f6ed0_guess(lookupValue_guess, zoneName_guess);
            FUN_0060e450_guess(EQ_ARRAY(char, 0x00923A20), zoneName_guess);
            FUN_0060e450_guess(EQ_ARRAY(char, 0x009239E0), zoneName_guess);
            FUN_0060e450_guess(EQ_ARRAY(char, 0x00923C3C), zoneName_guess);
            EQ_GLOBAL(unsigned char, 0x00923C5C) = 0;
        }
        if (g_contextObject_guess != 0) {
            if (g_contextObject_guess->FUN_005ed840_guess() != 0) {
                EQ_GLOBAL(unsigned char, 0x009239DC) = 1;
                EQ_GLOBAL(int, 0x00923CC4) = 0x1D;
                EQ_GLOBAL(unsigned char, 0x00924629) = 0;
            }
            if (g_contextObject_guess->FUN_005ed800_guess() != 0) {
                EQ_GLOBAL(unsigned char, 0x00924636) = 0;
            }
        }
    }

    FUN_00574110_guess("Initializing world.");
    g_netDisplay_00905d24_guess->FUN_00444116_guess(worldValue_guess);
    if (g_netDisplay_00905d24_guess->field00_guess == 1) {
        FUN_00574110_guess("ERROR: Failed to initialize world!");
        fieldb50_guess = 1;
    } else {
        if (EQ_GLOBAL(unsigned char, 0x00923798) == 0 &&
            EQ_GLOBAL(int, 0x00923884) == 0) {
            FUN_00574110_guess("Requesting zone data.");
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7AC5, 0, 0, 1);
        }
        FUN_00574110_guess("Resetting cameras.");
        g_camera_guess->SetCamera18_guess(11.0f);
        g_camera_guess->SetCamera20_guess(500.0f);
        g_camera_guess->SetCamera10_guess(-1.0f);
        g_camera_guess->SetCamera14_guess(-7.999f);
        g_camera_guess->SetCamera28_guess(90.0f);
        FUN_00574110_guess("Resetting vision.");
        reinterpret_cast<GlobalState_guess*>(this)->SetDefaultVisionColors_guess();
        FUN_00574110_guess("Resetting overlays.");
        EQ_GLOBAL(int, 0x00905D10) = 0;
        EQ_GLOBAL(int, 0x00905D14) = 0;
        EQ_GLOBAL(int, 0x00905D18) = 0;
        EQ_GLOBAL(int, 0x00905D1C) = 0;
        EQ_GLOBAL(int, 0x009248D4) = 0;
        EQ_GLOBAL(int, 0x009248D0) = 0;
        FUN_00574110_guess("Zone initialized.");
    }
}

// On a boat at zone-in (boat name at profile +0x80): sends the name (opcode 0x3710, not in
// patch_Titanium.conf) and waits up to 60 s for the server's answer (0x924675). Returns 1 when found.
// FUNCTION: TITANIUM 0x004A8AFA
// @early-stop: budget, structural ndiff=24
char CEverQuest_guess::IFoundMyVehicle_guess() {
    CEverQuest_guess* owner_guess = this;
    char result_guess = 0;
    if (strlen(&g_contextObject_guess->field44_guess[
            g_contextObject_guess->field08_guess->field04_guess + 0x80]) >= 1) {
        g_flag_00924676_guess = 1;
        unsigned int start_guess = FUN_0046d655_guess();
        char* text_guess = &g_contextObject_guess->field44_guess[
            g_contextObject_guess->field08_guess->field04_guess + 0x80];
        unsigned int text_size_guess = strlen(text_guess) + 1;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x3710, text_guess,
            text_size_guess, 1);
        while (reinterpret_cast<TargetOwner_guess*>(owner_guess)->ProcessMBox_guess(),
                g_flag_00924675_guess == 0) {
            unsigned int elapsed_guess = FUN_0046d655_guess() - start_guess;
            if (elapsed_guess > 60000) {
                g_flag_00924676_guess = 0;
                return result_guess;
            }
            Sleep(10);
        }
        g_flag_00924675_guess = 0;
        result_guess = 1;
    }
    return result_guess;
}

struct DamageBody56e3_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess();
    virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot20_guess();
    virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess();
    virtual void Slot27_guess(); virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess(); virtual void Slot44_guess();
    virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess();
    virtual void Slot51_guess(); virtual void Slot52_guess(); virtual void Slot53_guess();
    virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(); virtual void Slot64_guess(); virtual void Slot65_guess();
    virtual void Slot66_guess(); virtual void Slot67_guess(); virtual void Slot68_guess();
    virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess();
    virtual void Slot75_guess(); virtual void Slot76_guess(); virtual void Slot77_guess();
    virtual void Slot78_guess(); virtual void Slot79_guess(); virtual void Slot80_guess();
    virtual void Slot81_guess(); virtual void Slot82_guess(); virtual void Slot83_guess();
    virtual void Slot84_guess();
    virtual char IsGroupAbility_guess(int value_guess); // +0x154
};

struct DamageActorInfo56e3_guess {
    DamageBody56e3_guess* body_guess; // 0x0
    char padding_0004_guess[0xAC - 4];
    unsigned char fieldac_guess; // 0xAC
    char padding_00ad_guess[0x15C - 0xAD];
    int field15c_guess; // 0x15C
    char padding_0160_guess[0x16C - 0x160];
    unsigned int field16c_guess; // 0x16C
    char padding_0170_guess[0xEDD - 0x170];
    char fieldedd_guess[0xF30 - 0xEDD]; // 0xEDD
    int fieldf30_guess; // 0xF30
    int fieldf34_guess;
    int fieldf38_guess;
    int fieldf3c_guess;
};

struct DamageSound56e3_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess();
    virtual void Play_guess(unsigned short sound_guess, int first_guess, int second_guess,
        float scale_guess, int enabled_guess);
};

#pragma pack(push, 1)
struct DamageSummary56e3_guess {
    unsigned short target_guess; // 0x0
    unsigned short source_guess; // 0x2
    unsigned char type_guess; // 0x4
    short spell_guess; // 0x5
    int damage_guess; // 0x7
    int field0b_guess;
    int field0f_guess;
    int field13_guess;
};

struct DamageRecord56e3_guess {
    unsigned short target_guess; // 0x0
    unsigned short source_guess; // 0x2
    char padding_0004_guess[6];
    int field0a_guess; // 0xA
    int field0e_guess;
    int field12_guess;
    unsigned char type_guess; // 0x16
    char padding_0017_guess[4];
    short spell_guess; // 0x1B
    char padding_001d_guess[2];
};

struct DamageRequest56e3_guess {
    unsigned int id_guess;
    char text_guess[0x200];
};
#pragma pack(pop)

struct DamageActor56e3_guess {
    char padding_0000_guess[0x120];
    char name_guess[0x40]; // 0x120
    char padding_0160_guess[0x48];
    DamageActorInfo56e3_guess* pActorInfo_01a8_guess; // 0x1A8
    char padding_01ac_guess[7];
    unsigned char field1b3_guess; // 0x1B3
    char padding_01b4_guess[0x244 - 0x1B4];
    unsigned char type_0244_guess; // 0x244
    char padding_0245_guess[7];
    unsigned char level_024c_guess; // 0x24C
    char padding_024d_guess[1];
    unsigned char gender_024e_guess; // 0x24E
    char padding_024f_guess[2];
    unsigned char standState_0251_guess; // 0x251
    unsigned char playerClass_0252_guess; // 0x252
    char padding_0253_guess[5];
    unsigned int spawnId_0258_guess; // 0x258
    unsigned int masterId_025c_guess; // 0x25C
    int race_0260_guess; // 0x260
    char padding_0264_guess[0xC];
    int bodyType_0270_guess; // 0x270
    int hpCurrent_0274_guess; // 0x274
    // EXTERNAL: TITANIUM 0x004793B5 DamageActor56e3_guess::GetName_guess
    const char* GetName_guess();
    // EXTERNAL: TITANIUM 0x00479EE8 DamageActor56e3_guess::PlaySound_guess
    void PlaySound_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047F614 DamageActor56e3_guess::IWasHit_guess
    void IWasHit_guess(DamageRecord56e3_guess* record_guess);
    // EXTERNAL: TITANIUM 0x00483556 DamageActor56e3_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047B069 DamageActor56e3_guess::SpurtBloodOnDag_guess
    void SpurtBloodOnDag_guess();
    // EXTERNAL: TITANIUM 0x0047C08E DamageActor56e3_guess::GetAnimation_guess
    DamageSound56e3_guess* GetAnimation_guess();
};

struct DamageSpell56e3_guess {
    char padding_0000_guess[0x17D];
    unsigned char field17d_guess; // 0x17D
    char padding_017e_guess[2];
    unsigned char field180_guess; // 0x180
    char padding_0181_guess[6];
    unsigned char field187_guess; // 0x187
    char padding_0188_guess[0x1C4 - 0x188];
    unsigned char field1c4_guess; // 0x1C4
    char padding_01c5_guess[0x21C - 0x1C5];
    const char* field21c_guess; // 0x21C
    const char* field220_guess; // 0x220
};

struct DamageSpellManager56e3_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 DamageSpellManager56e3_guess::GetSpell_guess
    DamageSpell56e3_guess* GetSpell_guess(int id_guess);
};

struct DamageChar56e3_guess {
    char padding_0000_guess[0xE30];
    int fielde30_guess; // 0xE30
    char padding_0e34_guess[0xC288 - 0xE34];
    DamageActor56e3_guess* pSpawn_c288_guess; // 0xC288
};

struct DamageEverQuest56e3_guess {
    char padding_0000_guess[0x17BB4];
    char field17bb4_guess[0x840]; // 0x17BB4
    // EXTERNAL: TITANIUM 0x0049E0C1 DamageEverQuest56e3_guess::send_social_guess
    void send_social_guess(int value_guess, const char* first_guess, const char* second_guess);
};

// EXTERNAL: TITANIUM 0x004738AF ShowYouHitOtherMessage_guess
void __cdecl ShowYouHitOtherMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess, int damage_guess);
// EXTERNAL: TITANIUM 0x0047396C ShowOtherHitsYouMessage_guess
void __cdecl ShowOtherHitsYouMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess, int damage_guess);
// EXTERNAL: TITANIUM 0x00473A29 ShowOtherHitsOtherMessage_guess
void __cdecl ShowOtherHitsOtherMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess, int damage_guess, int color_guess);
// EXTERNAL: TITANIUM 0x00473AE4 ShowYouMissOtherMessage_guess
void __cdecl ShowYouMissOtherMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess);
// EXTERNAL: TITANIUM 0x00473B85 ShowOtherMissesYouMessage_guess
void __cdecl ShowOtherMissesYouMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess);
// EXTERNAL: TITANIUM 0x00473C26 ShowOtherMissesOtherMessage_guess
void __cdecl ShowOtherMissesOtherMessage_guess(char* message_guess, char* verb_guess, char* target_guess,
    char* source_guess, int color_guess);

#define g_damageSpells56e3_guess EQ_GLOBAL(DamageSpellManager56e3_guess*, 0x00985CC8)
#define g_damageChar56e3_guess EQ_GLOBAL(DamageChar56e3_guess*, 0x00905D00)
#define g_damageSelf56e3_guess EQ_GLOBAL(DamageActor56e3_guess*, 0x00905CE4)
#define g_damageTarget56e3_guess EQ_GLOBAL(DamageActor56e3_guess*, 0x00905D04)
#define g_damageEverQuest56e3_guess EQ_GLOBAL(DamageEverQuest56e3_guess*, 0x00988DF0)
#define g_damageGroup56e3_guess EQ_ARRAY(DamageActor56e3_guess*, 0x00904390)
#define g_damagePrefix56e3_guess EQ_ARRAY(const char, 0x00649F70)

// Damage report from Handle_OP_Damage and ReportDeath: picks the line by type (melee verbs 0x2F99..,
// spell damage 0x2FAB/0x2FAC, types 0xF3/0xF4, misses and avoids for damage <= 0), colours it by who
// hit whom, and plays the target's flinch animation and the sound.
// FUNCTION: TITANIUM 0x004A56E3
// @early-stop: budget, structural ndiff=884
void EverQuestSelf_guess::ReportSuccessfulHit_guess(void* summary_guess, unsigned char flag_guess,
    int zero_guess) {
    DamageSummary56e3_guess* packet_guess =
        reinterpret_cast<DamageSummary56e3_guess*>(summary_guess);
    char message_guess[512] = {0};
    char spellFormat_guess[512] = {0};
    char sourceName_guess[256] = {0};
    char targetName_guess[256] = {0};
    char verb_guess[256] = {0};
    int sound_guess = -1;
    char damageText_guess[256] = {0};
    DamageSpell56e3_guess* spell_guess = 0;
    DamageActor56e3_guess* source_guess = 0;
    int damage_guess = 0;
    char youAttack_guess = 0;
    char youHit_guess = 0;
    int stagger_guess = 0;
    int inGroup_guess = 0;
    int mine_guess = 0;
    char scratch_guess[256];
    DamageRequest56e3_guess request_guess;
    char saved_guess[0x840];
    DamageActor56e3_guess* target_guess;
    DamageActor56e3_guess* who_guess;
    int color_guess;
    int chatColor_guess;
    int verbType_guess;
    char hit_guess;
    int i_guess;

    target_guess = reinterpret_cast<DamageActor56e3_guess*>(
        FUN_00401b28_guess(packet_guess->target_guess));
    if (target_guess == 0) {
        return;
    }
    if (strlen(target_guess->name_guess) > 0x3f) {
        return;
    }
    // Names for the line: "you" / "YOU" (0x2F99-0x2F9E) when we hit or are hit, else the spawn names.
    if (packet_guess->source_guess != 0) {
        source_guess = reinterpret_cast<DamageActor56e3_guess*>(
            FUN_00401b28_guess(packet_guess->source_guess));
        if (source_guess == 0) {
            return;
        }
        if (strlen(source_guess->name_guess) > 0x3f) {
            return;
        }
        if (packet_guess->source_guess ==
                g_damageChar56e3_guess->pSpawn_c288_guess->pActorInfo_01a8_guess->field16c_guess ||
            (source_guess->field1b3_guess != 0 &&
                source_guess->masterId_025c_guess == g_damageSelf56e3_guess->spawnId_0258_guess)) {
            mine_guess = 1;
        }
        if (packet_guess->type_guess <= 0xe7) {
            bool copyName_guess = true;
            if (packet_guess->type_guess == 0xe7) {
                if (!IsValidSpellIndex_guess(packet_guess->spell_guess)) {
                    return;
                }
                spell_guess = g_damageSpells56e3_guess->GetSpell_guess(
                    packet_guess->spell_guess > 9999 ? 9999 : packet_guess->spell_guess);
                if (spell_guess == 0 || spell_guess->field17d_guess != 0) {
                    copyName_guess = false;
                }
            }
            if (copyName_guess) {
                strcpy(source_guess->pActorInfo_01a8_guess->fieldedd_guess, target_guess->name_guess);
            }
        }
    }

    if (packet_guess->type_guess <= 0xe7 &&
        g_damageSelf56e3_guess->spawnId_0258_guess == packet_guess->source_guess) {
        color_guess = 0x109;
        strcpy(sourceName_guess, pStringTable->getString(0x2f99, 0));
        if (packet_guess->source_guess == packet_guess->target_guess) {
            strcpy(targetName_guess, pStringTable->getString(0x2f9a, 0));
            youHit_guess = 1;
            color_guess = 0x10a;
        } else {
            strcpy(targetName_guess, target_guess->GetName_guess());
        }
        youAttack_guess = 1;
    } else if (g_damageSelf56e3_guess->spawnId_0258_guess == packet_guess->target_guess) {
        if (source_guess != 0) {
            strcpy(sourceName_guess, source_guess->GetName_guess());
            if (g_damageTarget56e3_guess == 0 && source_guess->bodyType_0270_guess < 0x41 &&
                (packet_guess->type_guess != 0xe7 || spell_guess == 0 ||
                    spell_guess->field17d_guess == 0)) {
                g_damageTarget56e3_guess = source_guess;
            }
        }
        strcpy(targetName_guess, pStringTable->getString(0x2f9b, 0));
        youHit_guess = 1;
        color_guess = 0x10a;
    } else {
        color_guess = 0x117;
        if (packet_guess->type_guess < 0xe7 &&
            packet_guess->source_guess == packet_guess->target_guess) {
            if (source_guess != 0) {
                strcpy(sourceName_guess, source_guess->GetName_guess());
                switch (source_guess->gender_024e_guess) {
                case 0:
                    strcpy(targetName_guess, pStringTable->getString(0x2f9c, 0));
                    break;
                case 1:
                    strcpy(targetName_guess, pStringTable->getString(0x2f9d, 0));
                    break;
                default:
                    strcpy(targetName_guess, pStringTable->getString(0x2f9e, 0));
                    break;
                }
            }
        } else {
            if (source_guess != 0) {
                strcpy(sourceName_guess, source_guess->GetName_guess());
            }
            strcpy(targetName_guess, target_guess->GetName_guess());
        }
    }

    // The damage type is the skill (EQEmu numbering): blunt 0/2, slash 1/3, archery 7 and throwing 51,
    // backstab 8, bash 10, monk strikes 21/23/52, kicks 26/30/38/71, hand to hand 28 (verb by race), pierce
    // 36, frenzy 74. 231 (0xE7) is spell damage; 0xF3-0xFD have fixed texts of their own.
    switch (packet_guess->type_guess) {
    case 0:
    case 2:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2f9f, 0));
            if (youAttack_guess != 0 && packet_guess->damage_guess > 0) {
                stagger_guess = 1;
            }
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2fa0, 0));
        }
        break;
    case 1:
    case 3:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2f93, 0));
            if (youAttack_guess != 0 && packet_guess->damage_guess > 0) {
                stagger_guess = 1;
            }
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2f94, 0));
        }
        break;
    case 7:
    case 0x33:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2f97, 0));
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2f98, 0));
        }
        break;
    case 8:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2fa7, 0));
            if (youAttack_guess != 0 && packet_guess->damage_guess > 0) {
                stagger_guess = 1;
            }
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2fa8, 0));
        }
        break;
    case 10:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2fa9, 0));
            if (youAttack_guess != 0 && packet_guess->damage_guess > 0) {
                stagger_guess = 1;
            }
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2faa, 0));
        }
        break;
    case 0x15:
    case 0x17:
    case 0x34:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2fa5, 0));
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2fa6, 0));
        }
        break;
    case 0x1a:
    case 0x1e:
    case 0x26:
    case 0x47:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2fa3, 0));
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2fa4, 0));
        }
        break;
    case 0x1c:
        verbType_guess = 0;
        hit_guess = 0;
        if (youAttack_guess == 0 && packet_guess->damage_guess > 0) {
            hit_guess = 1;
        }
        if (source_guess != 0) {
            verbType_guess = source_guess->race_0260_guess;
        }
        SetDefaultDamageDescByRace_guess(verb_guess, verbType_guess, hit_guess);
        break;
    case 0x24:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x2fa1, 0));
            if (youAttack_guess != 0 && packet_guess->damage_guess > 0) {
                stagger_guess = 1;
            }
        } else {
            strcpy(verb_guess, pStringTable->getString(0x2fa2, 0));
        }
        break;
    case 0x4a:
        if (youAttack_guess == 1 || packet_guess->damage_guess < 1) {
            strcpy(verb_guess, pStringTable->getString(0x16ce, 0));
        } else {
            strcpy(verb_guess, pStringTable->getString(0x16cf, 0));
        }
        break;
    // Spell damage: the spell's own text (+0x21C) with the amount (0x2FAB, 0x2FAC); songs print in 0x10F.
    case 0xe7:
        color_guess = 0x108;
        if (!IsValidSpellIndex_guess(packet_guess->spell_guess)) {
            return;
        }
        spell_guess = g_damageSpells56e3_guess->GetSpell_guess(packet_guess->spell_guess);
        if (spell_guess == 0) {
            return;
        }
        if (spell_guess->field1c4_guess != 0) {
            color_guess = 0x10f;
        }
        if (youHit_guess == 1) {
            if (packet_guess->damage_guess > 0) {
                if (packet_guess->damage_guess > 1) {
                    FormatText_guess(message_guess, 0x2fab, spell_guess->field21c_guess,
                        _itoa(packet_guess->damage_guess, g_digits_guess, 10),
                        0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(message_guess, 0x2fac, spell_guess->field21c_guess,
                        _itoa(packet_guess->damage_guess, g_digits_guess, 10),
                        0, 0, 0, 0, 0, 0, 0);
                }
            } else {
                sprintf(message_guess, "%s", spell_guess->field21c_guess);
            }
        } else {
            if (strlen(spell_guess->field220_guess) > 0) {
                const char* values_guess[9];
                sprintf(spellFormat_guess, "%s%s", g_damagePrefix56e3_guess,
                    spell_guess->field220_guess);
                memset(values_guess, 0, sizeof(values_guess));
                values_guess[0] = targetName_guess;
                FUN_00467441_guess(message_guess, spellFormat_guess, values_guess, -1, 0);
            } else {
                message_guess[0] = 0;
            }
        }
        if (spell_guess->field180_guess == 0xd && youAttack_guess != 0 && youHit_guess != 0) {
            verb_guess[0] = 0;
            message_guess[0] = 0;
            if (packet_guess->damage_guess > 0) {
                FormatText_guess(scratch_guess, 0x33f5, sourceName_guess,
                    0, 0, 0, 0, 0, 0, 0, 0);
                strcpy(request_guess.text_guess, scratch_guess);
                request_guess.id_guess = g_damageSelf56e3_guess->spawnId_0258_guess;
                // Opcode 0x5663 (not in patch_Titanium.conf) with eqstr 0x33F5: a self-hit
                // by a type-13 spell.
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5663, &request_guess,
                    sizeof(request_guess), 1);
                sprintf(scratch_guess, pStringTable->getString(0x2f54, 0));
                pEverQuest->dsp_chat(scratch_guess, color_guess, true);
            } else if (source_guess != 0 && source_guess->level_024c_guess < 0x23) {
                strcpy(saved_guess, g_damageEverQuest56e3_guess->field17bb4_guess);
                g_damageEverQuest56e3_guess->send_social_guess(0, "", "");
                SayToTarget_guess(source_guess, pStringTable->getString(0x2f55, 0));
                strcpy(g_damageEverQuest56e3_guess->field17bb4_guess, saved_guess);
            }
        } else {
            verb_guess[0] = 0;
        }
        if (spell_guess->field187_guess > 0 && spell_guess->field187_guess < 0x4f &&
            (target_guess->standState_0251_guess == 0x64 || target_guess->standState_0251_guess == 0x66)) {
            sound_guess = spell_guess->field187_guess;
        }
        break;
    case 0xf3:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2378, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2379, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf4:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x165a, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x165b, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf5:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f6b, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f6c, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf6:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f6d, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f6e, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf7:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f69, 0), targetName_guess);
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f6a, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf8:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f67, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f68, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xf9:
        sound_guess = 0xc;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f65, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f66, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xfa:
        sound_guess = 0xf;
        color_guess = 0x149;
        if (youHit_guess == 1) {
            sprintf(message_guess, pStringTable->getString(0x2f63, 0));
        } else if (g_optionState_guess->FUN_0060ca90_guess(0x11) == 1) {
            message_guess[0] = 0;
        } else {
            FormatText_guess(message_guess, 0x2f64, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 0xfb:
        sound_guess = 0xf;
        if (youHit_guess == 1) {
            if (target_guess->pActorInfo_01a8_guess->fieldac_guess != 0) {
                g_damageChar56e3_guess->fielde30_guess = 0;
            }
            if (g_selector_00924470_guess == 0xab) {
                sprintf(message_guess, pStringTable->getString(0x2f5f, 0));
            } else {
                sprintf(message_guess, pStringTable->getString(0x2f60, 0));
            }
        } else {
            if (g_selector_00924470_guess == 0xab) {
                FormatText_guess(message_guess, 0x2f61, targetName_guess,
                    0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FormatText_guess(message_guess, 0x2f62, targetName_guess,
                    0, 0, 0, 0, 0, 0, 0, 0);
            }
        }
        break;
    case 0xfc:
        if (youHit_guess == 1) {
            FormatText_guess(message_guess, 0x2f56, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            FormatText_guess(message_guess, 0x2f57, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        target_guess->PlaySound_guess(0x73);
        sound_guess = 0xe;
        break;
    case 0xfd:
        if (youHit_guess == 1) {
            switch (packet_guess->spell_guess) {
            case 0x73:
            case 0x74:
                sprintf(message_guess, pStringTable->getString(0x2f59, 0));
                break;
            case 0x78:
            case 0x7d:
                sprintf(message_guess, pStringTable->getString(0x2f5a, 0));
                break;
            case 0x82:
                sprintf(message_guess, pStringTable->getString(0x2f5b, 0));
                break;
            case 0x87:
                sprintf(message_guess, pStringTable->getString(0x2f5c, 0));
                break;
            case 0x8c:
            case 0x91:
            case 0x92:
            case 0x96:
            case 0x97:
            case 0x98:
                target_guess->PlaySound_guess(0x73);
                sprintf(message_guess, pStringTable->getString(0x2f5d, 0));
                break;
            default:
                sprintf(message_guess, pStringTable->getString(0x2f5e, 0));
                break;
            }
        } else {
            FormatText_guess(message_guess, 0x2f58, targetName_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        }
        sound_guess = 0xe;
        break;
    default:
        verbType_guess = 0;
        hit_guess = 0;
        if (source_guess != 0) {
            verbType_guess = source_guess->race_0260_guess;
        }
        if (youAttack_guess == 0 && packet_guess->damage_guess > 0) {
            hit_guess = 1;
        }
        SetDefaultDamageDescByRace_guess(verb_guess, verbType_guess, hit_guess);
        break;
    }

    if (strlen(sourceName_guess) < 1) {
        strcpy(sourceName_guess, pStringTable->getString(0x1a33, 0));
    }

    // Melee lines. Damage below 1 is an avoided hit (EQEmu: -1 block, -2 parry, -3 riposte, -4 dodge, -5
    // invulnerable, -6 rune); colours depend on who hit whom and the group.
    if (packet_guess->type_guess < 0xe7) {
        damage_guess = packet_guess->damage_guess;
        if (damage_guess < 1) {
            if (youAttack_guess == 1) {
                chatColor_guess = 0x10b;
            } else {
                chatColor_guess = mine_guess != 0 ? 0x148 : 0x118;
            }
            if (youHit_guess == 1) {
                chatColor_guess = 0x10c;
            }
            switch (damage_guess) {
            case -6:
                if (youHit_guess != 0) {
                    sprintf(damageText_guess, pStringTable->getString(0x2f7a, 0));
                } else {
                    FormatText_guess(damageText_guess, 0x2f7b, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                target_guess->PlaySound_guess(0x84);
                break;
            case -5:
                if (youHit_guess != 0) {
                    sprintf(damageText_guess, pStringTable->getString(0x2f78, 0),
                        targetName_guess);
                } else {
                    FormatText_guess(damageText_guess, 0x2f79, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                break;
            case -4:
                if (youHit_guess != 0) {
                    FormatText_guess(damageText_guess, 0x2f76, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(damageText_guess, 0x2f77, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                break;
            case -3:
                if (youHit_guess != 0) {
                    FormatText_guess(damageText_guess, 0x2f74, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(damageText_guess, 0x2f75, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                if (source_guess != 0) {
                    target_guess->PlaySound_guess(GetSoundEffectForRiposte_guess(source_guess, target_guess));
                }
                break;
            case -2:
                if (youHit_guess != 0) {
                    FormatText_guess(damageText_guess, 0x2f72, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(damageText_guess, 0x2f73, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                if (source_guess != 0) {
                    target_guess->PlaySound_guess(GetSoundEffectForRiposte_guess(source_guess, target_guess));
                }
                break;
            case -1:
                if (youHit_guess != 0) {
                    FormatText_guess(damageText_guess, 0x2f70, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(damageText_guess, 0x2f71, targetName_guess,
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                if (source_guess != 0) {
                    target_guess->PlaySound_guess(GetSoundEffectForRiposte_guess(source_guess, target_guess));
                }
                break;
            default:
                if (youAttack_guess != 0) {
                    sprintf(damageText_guess, pStringTable->getString(0x2f7c, 0));
                } else {
                    strcpy(damageText_guess, pStringTable->getString(0x2f7d, 0));
                }
                break;
            }
            if (youHit_guess != 0 && g_optionState_guess->FUN_0060ca90_guess(0x10) == 1) {
                flag_guess = 0;
            }
            if (youAttack_guess != 0) {
                if (g_optionState_guess->FUN_0060ca90_guess(0xd) == 1) {
                    flag_guess = 0;
                }
            } else if (youHit_guess == 0 && g_optionState_guess->FUN_0060ca90_guess(0xe) == 1) {
                flag_guess = (unsigned char)mine_guess;
            }
            if (youAttack_guess == 1) {
                if (target_guess->playerClass_0252_guess == 0x3e) {
                    FormatText_guess(message_guess, 0x1d8b, sourceName_guess, verb_guess,
                        targetName_guess, damageText_guess, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(message_guess, 0x2f7e, sourceName_guess, verb_guess,
                        targetName_guess, damageText_guess, 0, 0, 0, 0, 0);
                }
            } else {
                FormatText_guess(message_guess, 0x2f7f, sourceName_guess, verb_guess,
                    targetName_guess, damageText_guess, 0, 0, 0, 0, 0);
            }
        } else {
            DamageRecord56e3_guess record_guess;
            if (youAttack_guess == 1) {
                chatColor_guess = 0x109;
            } else {
                chatColor_guess = mine_guess != 0 ? 0x148 : 0x117;
            }
            if (youHit_guess == 1) {
                chatColor_guess = 0x10a;
            }
            if (target_guess->pActorInfo_01a8_guess->fieldf30_guess >= 0x20 &&
                target_guess->pActorInfo_01a8_guess->fieldf30_guess <= 0x59) {
                int health_guess;
                if (youHit_guess != 0) {
                    health_guess = target_guess->hpCurrent_0274_guess;
                } else {
                    health_guess = target_guess->level_024c_guess * 30;
                }
                if (health_guess / damage_guess < 10) {
                    target_guess->PlaySound_guess(0x94);
                } else {
                    target_guess->PlaySound_guess(0x93);
                }
            }
            memset(&record_guess, 0, sizeof(record_guess));
            record_guess.target_guess = packet_guess->target_guess;
            record_guess.source_guess = packet_guess->source_guess;
            record_guess.type_guess = packet_guess->type_guess;
            record_guess.spell_guess = packet_guess->spell_guess;
            record_guess.field0a_guess = packet_guess->field0b_guess;
            record_guess.field0e_guess = packet_guess->field0f_guess;
            record_guess.field12_guess = packet_guess->field13_guess;
            target_guess->IWasHit_guess(&record_guess);
            if (youHit_guess == 0 && youAttack_guess == 0 &&
                g_optionState_guess->FUN_0060ca90_guess(0xf) == 1) {
                flag_guess = (unsigned char)mine_guess;
            }
            if (flag_guess != 0) {
                const char* parts_guess[9];
                if (packet_guess->damage_guess > 1) {
                    FormatText_guess(damageText_guess, 0x2f80,
                        _itoa(packet_guess->damage_guess, g_digits_guess, 10),
                        0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(damageText_guess, 0x2f81,
                        _itoa(packet_guess->damage_guess, g_digits_guess, 10),
                        0, 0, 0, 0, 0, 0, 0, 0);
                }
                parts_guess[0] = sourceName_guess;
                parts_guess[1] = verb_guess;
                parts_guess[2] = targetName_guess;
                parts_guess[3] = damageText_guess;
                FUN_00467441_guess(message_guess, pStringTable->getString(0x2f82, 0),
                    parts_guess, -1, 0);
                if (source_guess != 0 && target_guess == source_guess &&
                    target_guess->type_0244_guess == 1) {
                    flag_guess = 0;
                }
            }
        }
        if (target_guess->playerClass_0252_guess == 0x3e && packet_guess->damage_guess > 1000000) {
            flag_guess = 0;
        }
        if (flag_guess != 0 && message_guess[0] != 0) {
            message_guess[0] = (char)toupper(message_guess[0]);
            if (chatColor_guess == 0x109) {
                ShowYouHitOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess, packet_guess->damage_guess);
            } else if (chatColor_guess == 0x10a) {
                ShowOtherHitsYouMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess, packet_guess->damage_guess);
            } else if (chatColor_guess == 0x117) {
                ShowOtherHitsOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess, packet_guess->damage_guess, chatColor_guess);
            } else if (chatColor_guess == 0x10b) {
                ShowYouMissOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess);
            } else if (chatColor_guess == 0x10c) {
                ShowOtherMissesYouMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess);
            } else if (chatColor_guess == 0x118) {
                ShowOtherMissesOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                    sourceName_guess, chatColor_guess);
            } else if (chatColor_guess == 0x148) {
                if (packet_guess->damage_guess > 0) {
                    ShowOtherHitsOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                        sourceName_guess, packet_guess->damage_guess, chatColor_guess);
                } else {
                    ShowOtherMissesOtherMessage_guess(message_guess, verb_guess, targetName_guess,
                        sourceName_guess, chatColor_guess);
                }
            } else {
                reinterpret_cast<CEverQuest*>(this)->dsp_chat(message_guess, chatColor_guess,
                    true);
            }
        }
    } else if (packet_guess->type_guess == 0xe7) {
        who_guess = source_guess;
        if (who_guess == 0) {
            who_guess = target_guess;
        }
        if (spell_guess != 0) {
            if (packet_guess->source_guess != 0 && spell_guess->field180_guess != 0 &&
                strlen(verb_guess) > 0 && flag_guess != 0 && who_guess != 0) {
                if (who_guess->type_0244_guess != 0) {
                    if (g_optionState_guess->FUN_0060ca90_guess(8) == 0) {
                        reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess, color_guess,
                            true);
                    }
                } else if (who_guess->playerClass_0252_guess == 8) {
                    if (who_guess == g_damageSelf56e3_guess) {
                        if (g_optionState_guess->FUN_0060ca90_guess(9) != 1) {
                            reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess,
                                color_guess, true);
                        }
                    } else {
                        for (i_guess = 0; i_guess < 5; i_guess++) {
                            if (who_guess == g_damageGroup56e3_guess[i_guess]) {
                                break;
                            }
                        }
                        if (i_guess < 5) {
                            inGroup_guess = 1;
                            if (g_optionState_guess->FUN_0060ca90_guess(9) == 2 ||
                                g_optionState_guess->FUN_0060ca90_guess(9) == 4) {
                                reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess,
                                    color_guess, true);
                            }
                        } else if (g_optionState_guess->FUN_0060ca90_guess(9) == 2) {
                            reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess,
                                color_guess, true);
                        }
                    }
                } else if (who_guess == g_damageSelf56e3_guess ||
                    target_guess == g_damageSelf56e3_guess) {
                    reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess, color_guess, true);
                } else {
                    for (i_guess = 0; i_guess < 5; i_guess++) {
                        if (who_guess == g_damageGroup56e3_guess[i_guess] ||
                            target_guess == g_damageGroup56e3_guess[i_guess]) {
                            break;
                        }
                    }
                    if (i_guess < 5) {
                        inGroup_guess = 1;
                        if (g_optionState_guess->FUN_0060ca90_guess(7) == 2 ||
                            g_optionState_guess->FUN_0060ca90_guess(7) == 4) {
                            reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess,
                                color_guess, true);
                        }
                    } else if (g_optionState_guess->FUN_0060ca90_guess(7) == 2) {
                        reinterpret_cast<CEverQuest*>(this)->dsp_chat(verb_guess, color_guess,
                            true);
                    }
                }
            }
            if (packet_guess->damage_guess > 0 && spell_guess->field17d_guess == 0) {
                damage_guess = packet_guess->damage_guess;
            }
        }
        if (flag_guess != 0 && who_guess != 0) {
            bool show_guess = true;
            if (who_guess->playerClass_0252_guess == 8) {
                if (who_guess == g_damageSelf56e3_guess) {
                    if (g_optionState_guess->FUN_0060ca90_guess(9) == 1) {
                        show_guess = false;
                    }
                } else {
                    for (i_guess = 0; i_guess < 5; i_guess++) {
                        if (who_guess == g_damageGroup56e3_guess[i_guess]) {
                            break;
                        }
                    }
                    if (g_optionState_guess->FUN_0060ca90_guess(9) != 2 &&
                        g_optionState_guess->FUN_0060ca90_guess(9) != 4) {
                        show_guess = false;
                    }
                }
            } else if (who_guess != g_damageSelf56e3_guess &&
                target_guess != g_damageSelf56e3_guess) {
                for (i_guess = 0; i_guess < 5; i_guess++) {
                    if (who_guess == g_damageGroup56e3_guess[i_guess] ||
                        target_guess == g_damageGroup56e3_guess[i_guess]) {
                        inGroup_guess = 1;
                        break;
                    }
                }
                if (inGroup_guess != 0) {
                    if (g_optionState_guess->FUN_0060ca90_guess(7) != 2 &&
                        g_optionState_guess->FUN_0060ca90_guess(7) != 4) {
                        show_guess = false;
                    }
                } else if (who_guess->type_0244_guess != 0) {
                    if (g_optionState_guess->FUN_0060ca90_guess(8) != 0) {
                        show_guess = false;
                    }
                } else if (g_optionState_guess->FUN_0060ca90_guess(7) != 2) {
                    show_guess = false;
                }
            }
            if (show_guess && message_guess[0] != 0) {
                message_guess[0] = (char)toupper(message_guess[0]);
                reinterpret_cast<CEverQuest*>(this)->dsp_chat(message_guess, color_guess, true);
            }
        }
    } else {
        damage_guess = packet_guess->damage_guess;
        if (damage_guess == 0) {
            sound_guess = -1;
        } else {
            if (youHit_guess == 1) {
                chatColor_guess = 0x10a;
            } else {
                chatColor_guess = color_guess;
                if (chatColor_guess == 0x14) {
                    chatColor_guess = 0x117;
                }
            }
            if (flag_guess != 0 && message_guess[0] != 0) {
                message_guess[0] = (char)toupper(message_guess[0]);
                reinterpret_cast<CEverQuest*>(this)->dsp_chat(message_guess, chatColor_guess,
                    true);
            }
        }
    }

    // Corpses don't react. A hit on us refreshes the HP window and stands us up from sitting or looting
    // (0x6E, 0x69); the target plays one of its four hit sounds and staggers when its model can.
    if (target_guess->type_0244_guess >= 2) {
        return;
    }
    if (damage_guess > 0) {
        if (target_guess == g_damageSelf56e3_guess) {
            if (pinstCSpellBookWnd_guess->IsVisible_guess()) {
                pinstCSpellBookWnd_guess->Deactivate();
            }
            if (g_damageSelf56e3_guess->standState_0251_guess == 0x6e ||
                g_damageSelf56e3_guess->standState_0251_guess == 0x69) {
                g_damageSelf56e3_guess->ChangePosition_guess(100);
            }
            if (g_damageSelf56e3_guess->pActorInfo_01a8_guess != 0 &&
                g_damageSelf56e3_guess->pActorInfo_01a8_guess->field15c_guess != 0) {
                g_damageSelf56e3_guess->ChangePosition_guess(100);
            }
        }
        if (sound_guess == -1) {
            sound_guess = 0xd;
        }
        switch (RandomRange_guess(1, 4)) {
        case 1:
            target_guess->PlaySound_guess(target_guess->pActorInfo_01a8_guess->fieldf30_guess);
            break;
        case 2:
            target_guess->PlaySound_guess(target_guess->pActorInfo_01a8_guess->fieldf34_guess);
            break;
        case 3:
            target_guess->PlaySound_guess(target_guess->pActorInfo_01a8_guess->fieldf38_guess);
            break;
        case 4:
            target_guess->PlaySound_guess(target_guess->pActorInfo_01a8_guess->fieldf3c_guess);
            break;
        }
    }
    if (stagger_guess == 1) {
        if (target_guess->pActorInfo_01a8_guess->body_guess->IsGroupAbility_guess(6)) {
            target_guess->SpurtBloodOnDag_guess();
        }
    }
    if (sound_guess != -1) {
        target_guess->GetAnimation_guess()->Play_guess((unsigned char)sound_guess, 1, 0, 1.0f, 1);
    }
}

// A spawn died: settles a duel with the killer (0x2F44 and OP_DuelDecline 0x3BAD), closes windows tied
// to the corpse, drops it as target, reports the killing blow (ReportSuccessfulHit, within 50 units
// unless the player is involved) and prints the death line; types 0xFA-0xFC have their own lines.
// FUNCTION: TITANIUM 0x004A8CD5
// @early-stop: budget, diff ndiff=238
void EverQuestSelf_guess::ReportDeath_guess(void* rawPacket_guess) {
    char firstBuffer_guess[256];
    char messageBuffer_guess[512];
    EverQuestSelf_guess* self_guess = this;
    DamagePacket_guess* packet_guess = reinterpret_cast<DamagePacket_guess*>(rawPacket_guess);
    unsigned char reportFlag_guess = 1;
    int pair_guess[2];
    unsigned char playerFlag_guess = 0;
    ActorTarget_guess* actor_guess = FUN_00401b28_guess(packet_guess->field00_guess);
    ActorTarget_guess* otherActor_guess;
    EventSummary_guess summary_guess;

    if (actor_guess == 0) {
        return;
    }
    if (actor_guess == reinterpret_cast<ActorTarget_guess*>(g_sourceRecord_00905ce4_guess) &&
        reinterpret_cast<ActorMarker_guess*>(actor_guess)->field251_guess == 'f') {
        playerFlag_guess = 1;
    }
    if (actor_guess->spawnId_0258_guess == g_pendingActor_009238d8_guess) {
        if (packet_guess->field04_guess == g_sourceRecord_00905ce4_guess->field258_guess &&
            g_pendingFlag_009238e0_guess != 0) {
            FUN_0046da4a_guess(firstBuffer_guess, 0x2f44,
                g_sourceRecord_00905ce4_guess->text_guess,
                reinterpret_cast<SourceRecord_guess*>(actor_guess)->text_guess,
                0, 0, 0, 0, 0, 0, 0);
            reinterpret_cast<CEverQuest*>(self_guess)->dsp_chat(firstBuffer_guess, 0x10d, true);
            pair_guess[0] = actor_guess->spawnId_0258_guess;
            pair_guess[1] = g_sourceRecord_00905ce4_guess->field258_guess;
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x3bad,
                pair_guess, 8, 1);
        } else {
            FUN_0046da4a_guess(firstBuffer_guess, 0x2f45,
                reinterpret_cast<SourceRecord_guess*>(actor_guess)->text_guess,
                reinterpret_cast<SourceRecord_guess*>(actor_guess)->text_guess,
                0, 0, 0, 0, 0, 0, 0);
            reinterpret_cast<CEverQuest*>(self_guess)->dsp_chat(firstBuffer_guess, 0x10d, true);
        }
        g_pendingFlag_009238e0_guess = 0;
        g_pendingActor_009238d8_guess = 0;
        g_pendingActor_009238dc_guess = 0;
    }
    if (g_target_00905ce0_guess != 0 && g_target_00905ce0_guess == actor_guess) {
        pinstCTradeWnd_guess->Deactivate_guess();
    }
    if (actor_guess == g_actor_00905d10_guess) {
        pinstCMerchantWnd_guess->Deactivate();
    }
    if (actor_guess == g_actor_00905d14_guess) {
        g_forwardedObjectWithArg_guess->CloseBank_guess(0);
    }
    if (actor_guess == reinterpret_cast<ActorTarget_guess*>(g_sourceRecord_00905ce4_guess)) {
        pinstCLootWnd_guess->FinishLoot_guess();
    }
    if (actor_guess == g_actor_00905d1c_guess) {
        CloseTrainWindow_guess();
    }
    if (g_value_00923cc4_guess != -1 && g_value_00923cd4_guess ==
        reinterpret_cast<int>(actor_guess)) {
        g_value_00923cc4_guess = -1;
        g_value_00923cd4_guess = 0;
        pEverQuest->dsp_chat(pStringTable->getString(0x2f46, 0));
    }
    if (reinterpret_cast<ActorTarget_guess*>(g_lastPlayer_00905d04_guess) == actor_guess) {
        g_lastPlayer_00905d04_guess = 0;
        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoAttack_guess(0);
        EQ_ARRAY(GlobalObj923770_guess, 0x00923770)->SetAutoFire_guess(0);
    }
    if (g_loopFlag_009043a4_guess != 0) {
        int* actors_guess = g_actorSlots_00904390_guess;
        unsigned char* enabled_guess = g_actorSlotFlags_0090424d_guess;
        unsigned char* end_guess = g_actorSlotFlagsEnd_0090438d_guess;
        do {
            if (*enabled_guess != 0 && *actors_guess == reinterpret_cast<int>(actor_guess)) {
                reinterpret_cast<ActorMutation_guess*>(*actors_guess)->field274_guess = -11;
            }
            enabled_guess += 0x40;
            ++actors_guess;
        } while ((int)enabled_guess < (int)end_guess);
    }
    pinstCTrackingWnd_guess->RemoveSpawn_guess(actor_guess);
    otherActor_guess = FUN_00401b28_guess(packet_guess->field04_guess);
    if (otherActor_guess != reinterpret_cast<ActorTarget_guess*>(g_sourceRecord_00905ce4_guess) &&
        packet_guess->field00_guess != g_sourceRecord_00905ce4_guess->field258_guess &&
        g_ownedDisplay_guess->PlayerDistance_guess(g_sourceRecord_00905ce4_guess,
            reinterpret_cast<int>(actor_guess), 0.0f) > 50.0f) {
        reportFlag_guess = 0;
    }

    summary_guess.field00_guess = (unsigned short)packet_guess->field00_guess;
    summary_guess.field02_guess = (unsigned short)packet_guess->field04_guess;
    summary_guess.field04_guess = packet_guess->field14_guess;
    summary_guess.field05_guess = packet_guess->field10_guess;
    summary_guess.field07_guess = packet_guess->field18_guess;
    self_guess->ReportSuccessfulHit_guess(&summary_guess, reportFlag_guess, 0);
    if (actor_guess == reinterpret_cast<ActorTarget_guess*>(g_sourceRecord_00905ce4_guess)) {
        self_guess->ResetCombatStateOnDeath_guess(reinterpret_cast<int>(rawPacket_guess), playerFlag_guess);
        if (packet_guess->field14_guess == 0xfa) {
            strcpy(messageBuffer_guess, pStringTable->getString(0x2f49, 0));
        } else if (packet_guess->field14_guess == 0xfb) {
            strcpy(messageBuffer_guess, pStringTable->getString(0x2f48, 0));
        } else if (packet_guess->field14_guess == 0xfc) {
            strcpy(messageBuffer_guess, pStringTable->getString(0x2f47, 0));
        } else if (packet_guess->field04_guess != 0) {
            if (otherActor_guess == 0) {
                FUN_0046da4a_guess(messageBuffer_guess, 0x2f4c, 0,
                    0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FUN_0046da4a_guess(messageBuffer_guess, 0x2f4b,
                    otherActor_guess->FUN_004793b5_guess(),
                    0, 0, 0, 0, 0, 0, 0, 0);
            }
        } else {
            strcpy(messageBuffer_guess, pStringTable->getString(0x2f4a, 0));
        }
    } else {
        if (packet_guess->field14_guess == 0xfa) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f4f,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (packet_guess->field14_guess == 0xfb) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f4e,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (packet_guess->field14_guess == 0xfc) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f4d,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (packet_guess->field04_guess == 0) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f50,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (packet_guess->field04_guess ==
            g_contextTargetView_guess->pSpawn_c288_guess->spawnId_0258_guess) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f51,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (otherActor_guess == 0) {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f53,
                actor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else if (otherActor_guess == actor_guess && actor_guess->type_0244_guess == 1) {
            reportFlag_guess = 0;
        } else {
            FUN_0046da4a_guess(messageBuffer_guess, 0x2f52,
                actor_guess->FUN_004793b5_guess(),
                otherActor_guess->FUN_004793b5_guess(), 0, 0, 0, 0, 0, 0, 0);
        }
    }
    actor_guess->IDied_guess(rawPacket_guess);
    if (actor_guess->playerClass_0252_guess != '>') {
        if (actor_guess == reinterpret_cast<ActorTarget_guess*>(g_sourceRecord_00905ce4_guess)) {
            reinterpret_cast<CEverQuest*>(self_guess)->dsp_chat(messageBuffer_guess, 0x115, true);
            FUN_00407dc9_guess()->DisplayText(messageBuffer_guess,
                10, 10, 0xc0, 1000, 1000, 4000);
        } else if (reportFlag_guess != 0) {
            reinterpret_cast<CEverQuest*>(self_guess)->dsp_chat(messageBuffer_guess, 0x116, true);
        }
    }
}

// EXTERNAL: TITANIUM 0x00479908 WhatDeityAlliance_guess
int __cdecl WhatDeityAlliance_guess(unsigned int deity_guess);

struct ReportContext_guess {
    char padding_0000_guess[8];
    int field08_guess;
    char padding_000c_guess[0x18 - 0x0c];
    int field18_guess;
};

struct ReportFlags_guess {
    char padding_0000_guess[0xe25];
    unsigned char fielde25_guess;
};

// Consider result: eqstr 0x2FCF '<name> <faction> <danger>' with the faction text (0x2FB4..0x2FBC,
// or deity standing for report type 4) and a danger line by level band (< 15, < 25, above), in the
// con colour from GetConColor.
// FUNCTION: TITANIUM 0x0049B9A6
// @early-stop: budget, structural ndiff=319
int __cdecl PrintAssessment_guess(ZoneChar_guess* character_guess,
    EQPlayer* player_guess, ReportContext_guess* report_guess) {
    char genderName_guess[16];
    char className_guess[256];
    char alternateName_guess[256];
    char detailName_guess[256];
    char message_guess[512];
    int category_guess = report_guess->field08_guess;
    unsigned char levelGuess_guess = player_guess->Level;
    int levelDifference_guess = (unsigned int)levelGuess_guess -
        reinterpret_cast<ZoneCharInfo_guess*>(
            character_guess->profile_guess.GetCharInfo2())->field11a4_guess;

    const char* genderText_guess;
    if (player_guess->Gender == 0) {
        genderText_guess = pStringTable->getString(0x2fb1, 0);
    } else if (player_guess->Gender == 1) {
        genderText_guess = pStringTable->getString(0x2fb2, 0);
    } else {
        genderText_guess = pStringTable->getString(0x2fb3, 0);
    }
    FUN_0060e450_guess(genderName_guess, genderText_guess);

    if (player_guess->Type == 0) {
        category_guess = 5;
    }

    if (category_guess == 1) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb4, 0));
    } else if (category_guess == 2) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb5, 0));
    } else if (category_guess == 3) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb6, 0));
    } else if (category_guess == 4) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb7, 0));
    } else if (category_guess == 5) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb8, 0));
    } else if (category_guess == 6) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fb9, 0));
    } else if (category_guess == 7) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fba, 0));
    } else if (category_guess == 8) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fbb, 0));
    } else if (category_guess == 9) {
        FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fbc, 0));
    }

    if (report_guess->field18_guess == 4) {
        int localDeity_guess = WhatDeityAlliance_guess(g_displayPlayer_guess->Deity);
        int playerDeity_guess = WhatDeityAlliance_guess(player_guess->Deity);
        int canSee_guess = reinterpret_cast<PlayerActionView_guess*>(player_guess)->
            NotOnSameDeity_guess(g_displayPlayer_guess, 0);
        if (canSee_guess == 0) {
            sprintf(className_guess, pStringTable->getString(0x2fb4, 0));
        } else if (localDeity_guess == 2) {
            if (playerDeity_guess == 1) {
                FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fbd, 0));
            } else {
                FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fbe, 0));
            }
        } else if ((localDeity_guess == 1 || localDeity_guess == 3) &&
            playerDeity_guess == 2) {
            FUN_0060e450_guess(className_guess, pStringTable->getString(0x2fbc, 0));
        } else {
            sprintf(className_guess, pStringTable->getString(0x2fba, 0));
        }

        if (reinterpret_cast<ReportFlags_guess*>(g_displayCharData_guess)->fielde25_guess != 0) {
            if (playerDeity_guess == 1) {
                sprintf(detailName_guess, pStringTable->getString(0x169c, 0));
            } else if (playerDeity_guess == 2) {
                sprintf(detailName_guess, pStringTable->getString(0x169d, 0));
            } else if (playerDeity_guess == 3) {
                sprintf(detailName_guess, pStringTable->getString(0x169e, 0));
            }
        }
    }

    int status_guess = GetConColor_guess(
        character_guess->FUN_004bc20b_guess(player_guess));
    if (report_guess->field18_guess != 0) {
        if (status_guess == 2) {
            FUN_0046da4a_guess(alternateName_guess, 0x2fbf, genderName_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        } else if (status_guess == 10) {
            FUN_0046da4a_guess(alternateName_guess, 0x2fc0, genderName_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        } else if (status_guess == 13) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc1, 0));
        }
    } else if (reinterpret_cast<ZoneCharInfo_guess*>(
            character_guess->profile_guess.GetCharInfo2())->field11a4_guess < 15) {
        if (status_guess == 2) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc2, 0));
        } else if (status_guess == 4) {
            int textId_guess = 0x2fc3;
            if (levelDifference_guess >= -3 && reinterpret_cast<ZoneCharInfo_guess*>(
                    character_guess->profile_guess.GetCharInfo2())->field11a4_guess >= 7) {
                textId_guess = 0x2fc4;
            }
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(textId_guess, 0));
        } else if (status_guess == 10) {
            int textId_guess = reinterpret_cast<ZoneCharInfo_guess*>(
                character_guess->profile_guess.GetCharInfo2())->field11a4_guess < 8 ?
                0x2fc5 : 0x2fc6;
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(textId_guess, 0));
        } else if (status_guess == 13) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc1, 0));
        } else if (status_guess == 15) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc7, 0));
        } else if (status_guess == 18) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc3, 0));
        }
    } else if (reinterpret_cast<ZoneCharInfo_guess*>(
            character_guess->profile_guess.GetCharInfo2())->field11a4_guess < 25) {
        if (status_guess == 2) {
            int textId_guess = levelDifference_guess < -5 ? 0x2fc2 : 0x2fc8;
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(textId_guess, 0));
        } else if (status_guess == 4) {
            int textId_guess = levelDifference_guess < -2 ? 0x2fca : 0x2fc9;
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(textId_guess, 0));
        } else if (status_guess == 10) {
            FUN_0046da4a_guess(alternateName_guess, 0x2fcb, genderName_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        } else if (status_guess == 13) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc1, 0));
        } else if (status_guess == 15) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc7, 0));
        } else if (status_guess == 18) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc8, 0));
        }
    } else {
        if (status_guess == 2) {
            int textId_guess = levelDifference_guess < -10 ? 0x2fcc : 0x2fcd;
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(textId_guess, 0));
        } else if (status_guess == 4) {
            FUN_0046da4a_guess(alternateName_guess, 0x2fcb, genderName_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        } else if (status_guess == 10) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc7, 0));
        } else if (status_guess == 13) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc1, 0));
        } else if (status_guess == 15) {
            FUN_0046da4a_guess(alternateName_guess, 0x2fce, genderName_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
        } else if (status_guess == 18) {
            FUN_0060e450_guess(alternateName_guess, pStringTable->getString(0x2fc8, 0));
        }
    }

    const char* values_guess[3];
    const char* playerName_guess = reinterpret_cast<ActorTarget_guess*>(
        player_guess)->FUN_004793b5_guess();
    values_guess[0] = playerName_guess;
    values_guess[1] = className_guess;
    values_guess[2] = alternateName_guess;
    FUN_00467441_guess(message_guess, pStringTable->getString(0x2fcf, 0),
        values_guess, -1, 0);
    pEverQuest->dsp_chat(message_guess, status_guess, true);

    if (report_guess->field18_guess == 4 &&
        reinterpret_cast<ReportFlags_guess*>(g_displayCharData_guess)->fielde25_guess != 0) {
        pEverQuest->dsp_chat(detailName_guess, status_guess, true);
    }
    return 1;
}

struct EverQuestReport_guess : CEverQuest {
    void Consider(EQPlayer* player_guess, ReportContext_guess* report_guess);
};

// 'Consider who?' (0x2FD0) without a target; corpses (type >= 2) get 0x2FD1.
// FUNCTION: TITANIUM 0x0049BEB8
// @early-stop: budget, diff ndiff=19
void EverQuestReport_guess::Consider(EQPlayer* player_guess,
    ReportContext_guess* report_guess) {
    if (player_guess == 0) {
        dsp_chat(pStringTable->getString(0x2fd0, 0), 0x111, true);
        return;
    }
    if (player_guess->Type < 2) {
        PrintAssessment_guess(g_zoneChar_00905d00_guess, player_guess, report_guess);
        return;
    }
    dsp_chat(pStringTable->getString(0x2fd1, 0), 0x111, true);
}

// 0x1C-byte string slot (`data` is the game's string buffer).
struct FriendName_guess {
    unsigned char data_guess[0x1c];
    // EXTERNAL: TITANIUM 0x00403631 FriendName_guess::FriendName_guess
    FriendName_guess(const char* text_guess);
    FriendName_guess(const FriendName_guess& other_guess);
    // EXTERNAL: TITANIUM 0x0040291E FriendName_guess::Tidy_guess
    void Tidy_guess(bool built_guess, unsigned int size_guess);
    ~FriendName_guess() { Tidy_guess(true, 0); }
};

// 0x10-byte list: first at +4, last at +8, end at +0xC.
struct FriendNames_guess {
    int field00_guess;
    FriendName_guess* first_guess;
    FriendName_guess* last_guess;
    FriendName_guess* end_guess;
    FriendNames_guess() : first_guess(0), last_guess(0), end_guess(0) {}
    // EXTERNAL: TITANIUM 0x0040B7B2 FriendNames_guess::FriendNames_guess
    FriendNames_guess(const FriendNames_guess& other_guess);
    // EXTERNAL: TITANIUM 0x0040B88B FriendNames_guess::Push_guess
    void Push_guess(const FriendName_guess& name_guess);
    // EXTERNAL: TITANIUM 0x0040AB88 FriendNames_guess::Size_guess
    unsigned int Size_guess();
    // EXTERNAL: TITANIUM 0x0040B540 FriendNames_guess::Dispose_guess
    void Dispose_guess();
    ~FriendNames_guess() { Dispose_guess(); }
};

// 0x4C-byte pair, destroyed by the out-of-line dtor at 0x0040B867.
struct FriendPair_guess {
    FriendName_guess first_guess;
    FriendNames_guess middle_guess;
    FriendName_guess last_guess;
    int flag_guess;
    // EXTERNAL: TITANIUM 0x0042BA5E FriendPair_guess::FriendPair_guess
    FriendPair_guess(FriendName_guess first_arg, FriendNames_guess list_guess,
        FriendName_guess second_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0040B867 FriendPair_guess::~FriendPair_guess
    ~FriendPair_guess();
};

struct FriendSub_guess {
    // EXTERNAL: TITANIUM 0x00428534 FriendSub_guess::Find_guess
    int Find_guess(const FriendName_guess& name_guess);
    // EXTERNAL: TITANIUM 0x0042BF38 FriendSub_guess::Add_guess
    void Add_guess(const FriendPair_guess& pair_guess);
    // EXTERNAL: TITANIUM 0x0042BF49 FriendSub_guess::Set_guess
    void Set_guess(int value_guess);
};

struct FriendObject_guess {
    char padding_0000_guess[0x60];
    FriendSub_guess sub_guess;
};

struct FriendOwner_guess {
    char padding_0000_guess[0x3A1C4];
    FriendObject_guess* field3a1c4_guess;
    void Refresh_guess();
    void ProcessLocalPCIni_guess(int mode_guess);
};

// Mirrors the friends list into the mail list's 'Friends' group (+0x3A1C4), or empties that group.
// FUNCTION: TITANIUM 0x004AB692
// @early-stop: budget, structural ndiff=6
void FriendOwner_guess::Refresh_guess() {
    if (field3a1c4_guess != 0) {
        int result_guess;
        FriendNames_guess names_guess;
        char* record_guess = gFriendsList_guess;
        do {
            if (*record_guess != 0) {
                names_guess.Push_guess(record_guess);
            }
            record_guess += 0x40;
        } while ((int)record_guess < (int)g_records_0095bab4_guess);
        if (names_guess.Size_guess() > 0) {
            FriendPair_guess pair_guess(FriendName_guess("Friends"), names_guess,
                FriendName_guess(g_text_0063f53f_guess), 1);
            field3a1c4_guess->sub_guess.Add_guess(pair_guess);
        } else {
            result_guess = field3a1c4_guess->sub_guess.Find_guess("Friends");
            if (result_guess != 0) {
                field3a1c4_guess->sub_guess.Set_guess(result_guess);
            }
        }
    }
}

// EXTERNAL: TITANIUM 0x0055955C GetCustomIniFilename_guess
char* __cdecl GetCustomIniFilename_guess();
// EXTERNAL: TITANIUM 0x006104F0 __stat
int __cdecl __stat(const char* path_guess, void* info_guess);
// EXTERNAL: TITANIUM 0x0060BFA0 FUN_0060bfa0_guess
void __cdecl FUN_0060bfa0_guess(const char* section_guess,
    const char* key_guess, const char* default_guess, char* value_guess,
    unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060BF60 FUN_0060bf60_guess
void __cdecl FUN_0060bf60_guess(const char* section_guess,
    const char* key_guess, const char* value_guess);

#define g_records_0095a6b4_guess EQ_ARRAY(char, 0x0095A6B4)
#define g_records_0095bfb4_guess EQ_ARRAY(char, 0x0095BFB4)

// Mode 0 saves, else loads, [Friends] Friend0..99 and [Ignored] Ignored0..99 of the character's ini
// (0x55955C). With no ini yet, the first 20 of each come from older copies (0x924FB0, 0x9246B0) and
// are saved.
// FUNCTION: TITANIUM 0x004AB7F1
// @early-stop: budget, structural ndiff=179
// Load or save friend records.
void FriendOwner_guess::ProcessLocalPCIni_guess(int mode_guess) {
    char info_guess[0x28];
    char entry_guess[256];
    char key_guess[128];
    char* path_guess = GetCustomIniFilename_guess();
    int status_guess = __stat(path_guess, info_guess);
    char* friendEnd_guess = g_records_0095bab4_guess;
    char* ignoredEnd_guess = g_records_0095d3b4_guess;
    if (status_guess != 0) {
        char* record_guess = gFriendsList_guess;
        do {
            if (record_guess < g_records_0095a6b4_guess) {
                FUN_0060e450_guess(record_guess, record_guess - 0x35204);
            } else {
                *record_guess = 0;
            }
            record_guess += 0x40;
        } while (record_guess < friendEnd_guess);
        Refresh_guess();
        record_guess = friendEnd_guess;
        do {
            if (record_guess < g_records_0095bfb4_guess) {
                FUN_0060e450_guess(record_guess, record_guess - 0x37004);
            } else {
                *record_guess = 0;
            }
            record_guess += 0x40;
        } while (record_guess < ignoredEnd_guess);
        mode_guess = 0;
    }
    if (mode_guess == 0) {
        char* record_guess = gFriendsList_guess;
        int index_guess = 0;
        do {
            _sprintf(key_guess, "Friend%d", index_guess);
            const char* value_guess = *record_guess == 0 ? "*NULL*" : record_guess;
            FUN_0060bf60_guess("Friends", key_guess, value_guess);
            ++index_guess;
            record_guess += 0x40;
        } while (record_guess < friendEnd_guess);
        record_guess = friendEnd_guess;
        index_guess = 0;
        do {
            _sprintf(key_guess, "Ignored%d", index_guess);
            const char* value_guess = *record_guess == 0 ? "*NULL*" : record_guess;
            FUN_0060bf60_guess("Ignored", key_guess, value_guess);
            ++index_guess;
            record_guess += 0x40;
        } while (record_guess < ignoredEnd_guess);
    } else {
        char* record_guess = gFriendsList_guess;
        mode_guess = 0;
        do {
            _sprintf(key_guess, "Friend%d", mode_guess);
            FUN_0060bfa0_guess("Friends", key_guess, "*NULL*", entry_guess, 0x20);
            if (entry_guess[0] == '*') {
                *record_guess = 0;
            } else {
                FUN_0060e450_guess(record_guess, entry_guess);
            }
            record_guess += 0x40;
            ++mode_guess;
        } while (record_guess < friendEnd_guess);
        Refresh_guess();
        record_guess = friendEnd_guess;
        mode_guess = 0;
        do {
            _sprintf(key_guess, "Ignored%d", mode_guess);
            FUN_0060bfa0_guess("Ignored", key_guess, "*NULL*", entry_guess, 0x20);
            if (entry_guess[0] == '*') {
                *record_guess = 0;
            } else {
                FUN_0060e450_guess(record_guess, entry_guess);
            }
            ++mode_guess;
            record_guess += 0x40;
        } while (record_guess < ignoredEnd_guess);
    }
}

// The virtual base shared by both halves of the character object.
struct MainLoopCharBase_guess {
    virtual void RefreshCounts_guess();
    EQ_CharacterProfile_guess profile_guess; // 0x04
    char padding_000c_guess[0x2C - 0xC];
    float y_guess; // 0x2C
    float x_guess; // 0x30
    float z_guess; // 0x34
    float heading_guess; // 0x38
    char name_guess[0x40]; // 0x3C
    char padding_007c_guess[0xBC - 0x7C];
    char boatName_guess[0x40]; // 0xBC
    signed char fieldfc_guess; // 0xFC
    char padding_00fd_guess[3];
    int zoneInstance_guess; // 0x100
    char padding_0104_guess[4];
    unsigned char field108_guess; // 0x108
    // EXTERNAL: TITANIUM 0x0040E2BD MainLoopCharBase_guess::FUN_0040e2bd_guess
    void FUN_0040e2bd_guess(int value_guess);
};

struct MainLoopCharHead_guess : CharDataPrefix_guess, virtual MainLoopCharBase_guess {
    char padding_000c_guess[0xC280 - 0xC];
};

struct MainLoopCharSecond_guess : virtual MainLoopCharBase_guess {
    virtual void SecondSlot00_guess();
    EQPlayer* fieldc288_guess; // 0xC288
    bool HasFlag20_guess() { return (field108_guess & 0x20) != 0; }
    // EXTERNAL: TITANIUM 0x0040D933 MainLoopCharSecond_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();
    // EXTERNAL: TITANIUM 0x0040E7AC MainLoopCharSecond_guess::GetBuff_guess
    char* GetBuff_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004193C5 MainLoopCharSecond_guess::encum_factor_guess
    float encum_factor_guess();
    // EXTERNAL: TITANIUM 0x00416A40 MainLoopCharSecond_guess::Max_Endurance
    int Max_Endurance();
};

struct MainLoopChar_guess : MainLoopCharHead_guess, MainLoopCharSecond_guess {
};

struct MainLoopActorInfo_guess {
    char padding_0000_guess[0x48];
    float field48_guess; // 0x48
    char padding_004c_guess[0x68 - 0x4C];
    int field68_guess; // 0x68
    char padding_006c_guess[0xAD - 0x6C];
    unsigned char fieldad_guess; // 0xAD
    char padding_00ae_guess[0xBC - 0xAE];
    float fieldbc_guess; // 0xBC
    char padding_00c0_guess[0x158 - 0xC0];
    EQPlayer* field158_guess; // 0x158
    char padding_015c_guess[4];
    EQPlayer* field160_guess; // 0x160
    char padding_0164_guess[0x1010 - 0x164];
    char field1010_guess[0x20]; // 0x1010
    int field1030_guess; // 0x1030
};

struct MainLoopPlayerOps_guess {
    // EXTERNAL: TITANIUM 0x0048A945 MainLoopPlayerOps_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
    // EXTERNAL: TITANIUM 0x0048A0FC MainLoopPlayerOps_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float y_guess, float x_guess, float z_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00484CA3 MainLoopPlayerOps_guess::DisplayWeaponsAndArmor_guess
    void DisplayWeaponsAndArmor_guess();
    // EXTERNAL: TITANIUM 0x0047CC37 MainLoopPlayerOps_guess::SetSounds_guess
    void SetSounds_guess();
    // EXTERNAL: TITANIUM 0x00483556 MainLoopPlayerOps_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047BFD0 MainLoopPlayerOps_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x0048A2F4 MainLoopPlayerOps_guess::FUN_0048a2f4_guess
    char FUN_0048a2f4_guess();
    // EXTERNAL: TITANIUM 0x00489C83 MainLoopPlayerOps_guess::FUN_00489c83_guess
    void FUN_00489c83_guess(float value_guess);
};

struct MainLoopDisplay_guess {
    // EXTERNAL: TITANIUM 0x0043C783 MainLoopDisplay_guess::RestoreCameraMode_guess
    void RestoreCameraMode_guess();
    // EXTERNAL: TITANIUM 0x00469DD7 MainLoopDisplay_guess::NoOp_guess
    void NoOp_guess();
};

struct MainLoopLookup_guess {
    // EXTERNAL: TITANIUM 0x005F6BC0 MainLoopLookup_guess::FUN_005f6bc0_guess
    char FUN_005f6bc0_guess(int zone_guess);
    // EXTERNAL: TITANIUM 0x005F6740 MainLoopLookup_guess::FUN_005f6740_guess
    void FUN_005f6740_guess(unsigned int time_guess);
};

struct MainLoopCache_guess {
    // EXTERNAL: TITANIUM 0x004C9BFD MainLoopCache_guess::FUN_004c9bfd_guess
    char FUN_004c9bfd_guess();
};

struct MainLoopObject79dc78_guess {
    // EXTERNAL: TITANIUM 0x00432240 MainLoopObject79dc78_guess::FUN_00432240_guess
    void FUN_00432240_guess();
};

struct MainLoopObject98599c_guess {
    // EXTERNAL: TITANIUM 0x004B3569 MainLoopObject98599c_guess::FUN_004b3569_guess
    void FUN_004b3569_guess();
};

struct MainLoopObject9232f0_guess {
    // EXTERNAL: TITANIUM 0x004082DF MainLoopObject9232f0_guess::FUN_004082df_guess
    void FUN_004082df_guess();
};

struct MainLoopMoveData_guess {
    int field00_guess;
    float field04_guess;
    float field08_guess;
    float field0c_guess;
    char padding_0010_guess[0x10];
};

struct MainLoopMovePacket_guess {
    unsigned short spawnId_guess; // 0x00
    unsigned short field02_guess; // 0x02
    MainLoopMoveData_guess data_guess; // 0x04
};

struct MainLoopGuildPacket_guess {
    int guildId_guess; // 0x00
    char name_guess[0x84]; // 0x04
    char field88_guess; // 0x88
    char padding_0089_guess[0x288 - 0x89];
};

// EXTERNAL: TITANIUM 0x004B718D FUN_004b718d_guess
ToggleState_guess* __cdecl FUN_004b718d_guess();
// EXTERNAL: TITANIUM 0x00465244 pack_physics_guess
void __cdecl pack_physics_guess(void* motion_guess, MainLoopMoveData_guess* data_guess,
    EQPlayer* player_guess);
// EXTERNAL: TITANIUM 0x004BFAE8 IsPositionUpdateUnchanged_guess
char __cdecl IsPositionUpdateUnchanged_guess(void* first_guess, void* second_guess);
// EXTERNAL: TITANIUM 0x005770D0 FUN_005770d0_guess
void __cdecl FUN_005770d0_guess();
// EXTERNAL: TITANIUM 0x00611BE8 _control87
extern "C" unsigned int __cdecl _control87(unsigned int value_guess, unsigned int mask_guess);

#define g_mainLoopChar_guess EQ_GLOBAL(MainLoopChar_guess*, 0x00905D00)
#define g_mainLoopPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_mainLoopControlled_guess EQ_GLOBAL(EQPlayer*, 0x00905CF8)
#define g_mainLoopSpawns_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)
#define g_mainLoopTarget_guess EQ_GLOBAL(EQPlayer*, 0x00905D04)
#define g_mainLoopEverQuest_guess EQ_GLOBAL(CEverQuest_guess*, 0x00988DF0)
#define g_mainLoopDisplay_guess EQ_GLOBAL(MainLoopDisplay_guess*, 0x00905D24)
#define g_mainLoopLookup_guess EQ_GLOBAL(MainLoopLookup_guess*, 0x00905CC0)
#define g_mainLoopCache_guess EQ_GLOBAL(MainLoopCache_guess*, 0x00985CF0)
#define g_mainLoopObject79dc78_guess EQ_ARRAY(MainLoopObject79dc78_guess, 0x0079DC78)
#define g_mainLoopObject98599c_guess EQ_GLOBAL(MainLoopObject98599c_guess*, 0x0098599C)
#define g_mainLoopObject9232f0_guess EQ_ARRAY(MainLoopObject9232f0_guess, 0x009232F0)
#define g_mainLoopLock_guess EQ_ARRAY(CRITICAL_SECTION, 0x00903FC0)
#define g_mainLoopReady_guess EQ_GLOBAL(int, 0x00923788)
#define g_mainLoopServerName_guess EQ_ARRAY(char, 0x00923A40)
#define g_mainLoopMotd_guess EQ_ARRAY(char, 0x00923D98)
#define g_mainLoopValue_00923d58_guess EQ_GLOBAL(int, 0x00923D58)
#define g_mainLoopMoveTime_guess EQ_GLOBAL(unsigned int, 0x009238EC)
#define g_mainLoopControlledMoveTime_guess EQ_GLOBAL(unsigned int, 0x009238F0)
#define g_mainLoopFlag_009237b9_guess EQ_GLOBAL(unsigned char, 0x009237B9)
#define g_mainLoopFlag_00988c76_guess EQ_GLOBAL(unsigned char, 0x00988C76)
#define g_mainLoopValue_009254c4_guess EQ_GLOBAL(int, 0x009254C4)
#define g_mainLoopFrameTime_guess EQ_GLOBAL(int, 0x00790114)
#define g_mainLoopValue_00905d10_guess EQ_GLOBAL(int, 0x00905D10)
#define g_mainLoopValue_00905d14_guess EQ_GLOBAL(int, 0x00905D14)
#define g_mainLoopValue_00905d18_guess EQ_GLOBAL(int, 0x00905D18)
#define g_mainLoopValue_00905d1c_guess EQ_GLOBAL(int, 0x00905D1C)

// Zone-in step 4, then the in-game frame loop. Puts the player back on its boat, requests spawns and
// zone data (waiting for ReadyEnterWorld twice), prints the welcome and MOTD, sends OP_ClientReady.
// Each frame in state 5: coin/cursor queue, network, position updates, jump, render, ProcessControls.
// FUNCTION: TITANIUM 0x004ABA14
// @early-stop: budget, structural ndiff=464
void GlobalState_guess::DoMainLoop(HWND window_guess) {
    char chatText_guess[0x400];
    char cleanName_guess[0x100];
    MainLoopGuildPacket_guess guildPacket_guess;
    char iniValue_guess[0x40];
    NetMotion_guess position_guess;
    BoundsPair_guess targetBounds_guess;
    BoundsPair_guess sourceBounds_guess;
    float savedZ_guess;
    MainLoopMovePacket_guess packet_guess;
    int frameSkip_guess = 0x1e;

    reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
    int previousState_guess = state_guess;
    g_globalState_guess->SetGameStateInline_guess(7);
    CreateInitialActors_guess();
    g_globalState_guess->SetGameState(previousState_guess);

    if (g_mainLoopChar_guess == 0) {
        FUN_00574110_guess("ERROR: LocalPC is NULL at the start of DoMainLoop!");
    } else if (strlen(g_mainLoopChar_guess->boatName_guess) > 0) {
        FUN_00574110_guess("Moving player to vehicle %s", g_mainLoopChar_guess->boatName_guess);
        EQPlayer* boat_guess = reinterpret_cast<EQPlayer*>(FindPlayerByPartialDisplayName_guess(
            reinterpret_cast<NameCleaner_guess*>(this)->StripShipName_guess(
                g_mainLoopChar_guess->boatName_guess, cleanName_guess), 0));
        if (boat_guess != 0) {
            g_netPlayer_00905ce4_guess->motion_guess.Set_guess(g_mainLoopChar_guess->y_guess,
                g_mainLoopChar_guess->x_guess, g_mainLoopChar_guess->z_guess);
            g_mainLoopPlayer_guess->Heading = g_mainLoopChar_guess->heading_guess;
            static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                ->field158_guess = boat_guess;
            TransformPassengersToWorldSpace_guess(boat_guess);
            reinterpret_cast<MainLoopPlayerOps_guess*>(g_mainLoopPlayer_guess)
                ->FUN_0048a945_guess();
            static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                ->field158_guess = 0;
            float z_guess = g_mainLoopPlayer_guess->Z;
            float y_guess = g_mainLoopPlayer_guess->Y;
            float x_guess = g_mainLoopPlayer_guess->X;
            float floorZ_guess = reinterpret_cast<MainLoopPlayerOps_guess*>(
                g_mainLoopPlayer_guess)->GetFloorHeightAt_guess(y_guess, x_guess,
                    z_guess + 1.0f, 1);
            if (floorZ_guess == -1e27f ||
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field158_guess == 0) {
                g_netPlayer_00905ce4_guess->motion_guess.Set_guess(0.0f, 0.0f, 25.0f);
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field158_guess = boat_guess;
                TransformPassengersToWorldSpace_guess(boat_guess);
                reinterpret_cast<MainLoopPlayerOps_guess*>(g_mainLoopPlayer_guess)
                    ->FUN_0048a945_guess();
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field158_guess = 0;
                z_guess = g_mainLoopPlayer_guess->Z;
                y_guess = g_mainLoopPlayer_guess->Y;
                x_guess = g_mainLoopPlayer_guess->X;
                floorZ_guess = reinterpret_cast<MainLoopPlayerOps_guess*>(
                    g_mainLoopPlayer_guess)->GetFloorHeightAt_guess(y_guess, x_guess,
                        z_guess + 1.0f, 1);
            }
            if (floorZ_guess != -1e27f) {
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field48_guess = floorZ_guess;
                g_mainLoopPlayer_guess->Z = floorZ_guess +
                    reinterpret_cast<Player1d74_guess*>(g_mainLoopPlayer_guess)->heightOffset_0238_guess;
            }
            if (static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field158_guess == 0) {
                FUN_00574110_guess(
                    "WARNING: Can't set player to vehicle %s! Sending player to safe point.",
                    g_mainLoopChar_guess->boatName_guess);
                g_clockData_guess->MoveLocalPlayerToSafeCoords_guess();
            }
        } else {
            if (reinterpret_cast<CEverQuest_guess*>(this)->IFoundMyVehicle_guess() != 0) {
                g_globalState_guess->SetGameState(5);
                g_flag_00923d7a_guess = 1;
                return;
            }
            FUN_00574110_guess(
                "WARNING: Unable to find vehicle %s, sending player to safe point.",
                g_mainLoopChar_guess->boatName_guess);
            g_clockData_guess->MoveLocalPlayerToSafeCoords_guess();
        }
    }

    SetWindowTextA(window_guess, "EverQuest");
    g_mainLoopTarget_guess = 0;
    g_globalState_guess->SetGameState(5);
    g_mainLoopReady_guess = 0;
    EnterCriticalSection(g_mainLoopLock_guess);
    FUN_00574110_guess("Loading game sounds.");
    UpdateSoundZone_guess();
    FUN_00574110_guess("Requesting initialization data.");
    if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
        // OP_ReqClientSpawn.
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x322, 0, 0, 1);
        FUN_00574110_guess("DoMainLoop: just before first while(!ReadyEnterWorld).");
        while (g_mainLoopReady_guess == 0) {
            reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
            if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4635, 1) != 0) {
                return;
            }
            Sleep(1);
        }
        g_mainLoopReady_guess = 0;
        FUN_00574110_guess("DoMainLoop: complete after first while(!ReadyEnterWorld).");
        FUN_004b102d_guess();
        g_value_009248d4_guess = 0;
        g_value_009248d0_guess = 0;
        reinterpret_cast<FriendOwner_guess*>(this)->ProcessLocalPCIni_guess(1);
        field393fc_guess = 1;
        if (g_flag_009858c5_guess != 0) {
            g_flag_009858c5_guess = 0;
            DspChat_guess(pStringTable->getString(0x3043, 0));
            if (reinterpret_cast<ZoneCharInfo_guess*>(
                    g_mainLoopChar_guess->profile_guess.GetCharInfo2())->field11a4_guess <= 10) {
                DspChat_guess(pStringTable->getString(0x213a, 0));
            }
            for (int index_guess = 0; index_guess < g_mainLoopChar_guess->GetMaxBuffs_guess();
                    index_guess++) {
                if (*g_mainLoopChar_guess->GetBuff_guess(index_guess) != 0) {
                    g_flag_00923990_guess = 1;
                }
            }
            if (g_mainLoopCache_guess->FUN_004c9bfd_guess() != 0) {
                DspChat_guess(pStringTable->getString(0x2274, 0), 0xf, true);
            }
        }
        FUN_0046da4a_guess(chatText_guess, 0x3045, g_mainLoopServerName_guess, 0, 0, 0, 0, 0,
            0, 0, 0);
        DspChat_guess(chatText_guess);
        FUN_004b6088_guess()->FUN_004b60c2_guess();
        if (g_mainLoopValue_00923d58_guess == 4 &&
            reinterpret_cast<ZoneCharInfo_guess*>(
                g_mainLoopChar_guess->profile_guess.GetCharInfo2())->field11a4_guess < 6 &&
            g_mainLoopLookup_guess->FUN_005f6bc0_guess(
                g_mainLoopChar_guess->zoneInstance_guess) == 0) {
            DspChat_guess(pStringTable->getString(0x3046, 0), 0xd, true);
        }
        if (g_mainLoopMotd_guess[0] != '~' && g_mainLoopMotd_guess[0] != 0) {
            FUN_0046da4a_guess(chatText_guess, 0x3047, g_mainLoopMotd_guess, 0, 0, 0, 0, 0, 0,
                0, 0);
            DspChat_guess(chatText_guess, 0xf, true);
        }
        g_mainLoopMotd_guess[0] = '~';
        g_mainLoopObject79dc78_guess->FUN_00432240_guess();
        if (pinstCTaskWnd_guess != 0) {
            pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
        }
        FUN_00574110_guess("DoMainLoop: just before second while(!ReadyEnterWorld).");
        FUN_004b718d_guess()->SetPositionHistoryRecording_guess(1);
        // OP_SendExpZonein.
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x587, 0, 0, 1);
        FUN_0046d655_guess();
        FUN_00574110_guess("Zone Connect -- Sending out a MSG_READY_ENTER_WORLD.");
        while (g_mainLoopReady_guess == 0) {
            reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
            if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4689, 1) != 0) {
                return;
            }
        }
        FUN_00574110_guess("DoMainLoop: completed second while(!ReadyEnterWorld).");
        g_owned_0079dbd4_guess->UpdateAutoJoinChannels_guess(g_mainLoopChar_guess);
        if (g_value_00924198_guess == 1) {
            g_value_00924198_guess = 0;
            if (g_mainLoopPlayer_guess->GuildID != 0xffffffff) {
                guildPacket_guess.guildId_guess = g_mainLoopPlayer_guess->GuildID;
                guildPacket_guess.field88_guess = 0;
                strcpy(guildPacket_guess.name_guess, g_mainLoopPlayer_guess->Name);
            }
        }
    } else if (g_flag_00923884_guess != 0) {
        DspChat_guess(pStringTable->getString(0x3043, 0));
        DspChat_guess(pStringTable->getString(0x3048, 0));
        DspChat_guess(pStringTable->getString(0x3049, 0));
    } else {
        g_mainLoopDisplay_guess->NoOp_guess();
        FUN_004b102d_guess();
        DspChat_guess(pStringTable->getString(0x3043, 0));
    }
    LeaveCriticalSection(g_mainLoopLock_guess);

    g_value_009248d4_guess = 0;
    g_value_009248d0_guess = 0;
    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x5e20, 0, 0, 1);
    FUN_00574110_guess("Setting up models.");
    for (EQPlayer* spawn_guess = g_mainLoopSpawns_guess; spawn_guess != 0;
            spawn_guess = spawn_guess->pNext) {
        reinterpret_cast<MainLoopPlayerOps_guess*>(spawn_guess)->DisplayWeaponsAndArmor_guess();
        if (spawn_guess->pActorInfo != 0) {
            reinterpret_cast<MainLoopPlayerOps_guess*>(spawn_guess)->SetSounds_guess();
        }
    }
    FUN_00574110_guess("Setting up character.");
    if (g_sendDisabled_00923798_guess == 0) {
        RefreshWornAppearance_guess(-1);
        UpdateLight_guess(reinterpret_cast<EQ_PC*>(g_mainLoopChar_guess));
    }
    g_netDisplay_00905d24_guess->SetupEQPlayers_guess();
    FlushMouse_guess();
    FlushKeyboard_guess();
    g_mainLoopObject98599c_guess->FUN_004b3569_guess();
    reinterpret_cast<MainLoopPlayerOps_guess*>(g_mainLoopPlayer_guess)->ChangePosition_guess(100);

    int targetGroupBuff_guess = 0;
    iniValue_guess[0] = 0;
    FUN_0060be50_guess("Defaults", "TargetGroupBuff", "*NULL*", iniValue_guess, 0x20,
        ".\\eqclient.ini");
    if (iniValue_guess[0] != '*') {
        targetGroupBuff_guess = atoi(iniValue_guess);
        // OP_TGB, from [Defaults] TargetGroupBuff.
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xc11, &targetGroupBuff_guess, 4, 1);
    }
    FUN_00574110_guess("Activating music.");
    g_dispatch_00851390_guess->SetMusicSelection_guess(4, false);
    g_dispatch_00851390_guess->SetMusicSelection_guess(1, false);
    if (g_notice_00905cb4_guess != 0) {
        g_notice_00905cb4_guess = 0;
        pConfirmationDialogPool_guess->Activate(
            static_cast<EverQuestNotifier_guess*>(g_mainLoopEverQuest_guess), 0xb,
            pStringTable->getString(0x13ff, 0), 1, 6000, 0, 0);
    }
    if (pinstCAdventureStatsWnd_guess != 0 && pinstCAdventureStatsWnd_guess->IsVisible_guess() != 0) {
        FUN_00574110_guess("Requesting adventure statistics.");
        pinstCAdventureStatsWnd_guess->Send_guess();
    }
    if (pinstCAdventureLeaderboardWnd_guess != 0 &&
        pinstCAdventureLeaderboardWnd_guess->IsVisible_guess() != 0) {
        FUN_00574110_guess("Requesting leaderboard.");
        pinstCAdventureLeaderboardWnd_guess->SendLeaderboardRequest_guess();
    }
    FUN_005770d0_guess();
    FUN_00574110_guess("Initialization complete.\nEntering main loop.");
    AcquireMouse_guess(1);

    while (state_guess == 5) {
        // FPU control word each frame: all exceptions masked, truncation, 24-bit precision.
        _control87(0xa031f, 0xf031f);
        g_displayRoot_guess->field148_guess = FUN_0046d655_guess();
        g_value_0092385c_guess = g_displayRoot_guess->field148_guess;
        ProcessPendingCoinsAndCursorItems_guess();
        reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
        if (g_mainLoopChar_guess->HasFlag20_guess()) {
            g_mainLoopObject9232f0_guess->FUN_004082df_guess();
        }
        if (g_flag_00923d7a_guess != 0) {
            if (static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field68_guess != 0) {
                g_mainLoopDisplay_guess->RestoreCameraMode_guess();
            }
            return;
        }
        if (g_flag_00923d7b_guess == 0 && g_sendDisabled_00923798_guess == 0) {
            if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4734, 0) != 0) {
                g_flag_00923d7b_guess = 1;
                // On a lost connection it waits 16 s before giving up.
                Sleep(16000);
            }
        }
        if (g_flag_00923d7b_guess != 0) {
            g_mainLoopValue_00905d10_guess = 0;
            g_mainLoopValue_00905d14_guess = 0;
            g_mainLoopValue_00905d18_guess = 0;
            g_mainLoopValue_00905d1c_guess = 0;
            g_value_009248d4_guess = 0;
            g_value_009248d0_guess = 0;
            if (g_sendDisabled_00923798_guess != 0 || g_flag_00923884_guess != 0) {
                g_value_00923794_guess = 0xfd;
                g_flag_00923d7b_guess = 0;
                return;
            }
            if (g_flag_00923d7b_guess == 1) {
                g_value_00923794_guess = 0xfe;
                if (g_connection_00905ca0_guess != 0 &&
                    reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)
                        ->GetField88_guess() != 1 &&
                    g_mainLoopPlayer_guess != 0 &&
                    static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                        ->field68_guess == 0) {
                    g_zoneResult_00923d94_guess = 0x1a;
                    g_mainLoopChar_guess->y_guess = g_mainLoopPlayer_guess->Y;
                    g_mainLoopChar_guess->x_guess = g_mainLoopPlayer_guess->X;
                    g_mainLoopChar_guess->z_guess = g_mainLoopPlayer_guess->Z;
                    g_mainLoopChar_guess->heading_guess = g_mainLoopPlayer_guess->Heading;
                    SavePCOnZone_guess(0);
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x55bc,
                        &g_mainLoopPlayer_guess->SpawnID, 4, 1);
                }
                WaitForDisconnectAndProcessMessages_guess();
                switch (g_value_00905d28_guess) {
                case 2:
                    g_value_00905d28_guess = 0;
                case 1:
                    g_value_00923794_guess = 0xfd;
                    break;
                }
                g_flag_00923d7b_guess = 0;
                return;
            }
            if (g_mainLoopPlayer_guess != 0 &&
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                    ->field68_guess == 0) {
                g_zoneResult_00923d94_guess = 0x1a;
                SavePCOnZone_guess(0);
                Sleep(2000);
            }
            field39400_guess = 1;
            g_globalState_guess->SetGameStateInline_guess(0xff);
            g_value_00923794_guess = 0xfd;
            fieldb50_guess = 1;
            g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
            return;
        }

        int active_guess = 1;
        if (g_mainLoopChar_guess->fieldfc_guess > 2 ||
            g_mainLoopPlayer_guess->StandState == 'f') {
            active_guess = 0;
        }
        if (g_sendDisabled_00923798_guess != 0 || g_flag_00923884_guess != 0) {
            active_guess = 1;
        }
        if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
            int mounted_guess = 0;
            if (g_mainLoopControlled_guess != 0 &&
                static_cast<MainLoopActorInfo_guess*>(g_mainLoopControlled_guess->pActorInfo)
                    ->field160_guess != 0) {
                mounted_guess = 1;
            }
            if (active_guess != 0) {
                if (g_flag_00923d79_guess != 0 && mounted_guess == 0) {
                    if (g_mainLoopMoveTime_guess > g_displayRoot_guess->field148_guess) {
                        g_mainLoopMoveTime_guess = g_displayRoot_guess->field148_guess;
                    }
                    if (g_displayRoot_guess->field148_guess - g_mainLoopMoveTime_guess > 0x118) {
                        packet_guess.spawnId_guess =
                            (unsigned short)g_mainLoopPlayer_guess->SpawnID;
                        pack_physics_guess(&g_mainLoopPlayer_guess->Y, &packet_guess.data_guess,
                            g_mainLoopPlayer_guess);
                        if (g_mainLoopPlayer_guess->pActorInfo != 0) {
                            memcpy(static_cast<MainLoopActorInfo_guess*>(
                                    g_mainLoopPlayer_guess->pActorInfo)->field1010_guess,
                                &packet_guess.data_guess, 0x20);
                        }
                        static_cast<MainLoopActorInfo_guess*>(g_mainLoopPlayer_guess->pActorInfo)
                            ->field1030_guess = 0;
                        position_guess = g_netPlayer_00905ce4_guess->motion_guess;
                        packet_guess.field02_guess = FUN_004b718d_guess()->field18_guess;
                        FUN_004b718d_guess()->FUN_004b70db_guess(&position_guess, 2);
                        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x14cb, &packet_guess,
                            0x24, 0);
                        g_flag_00923d79_guess = 0;
                        g_mainLoopMoveTime_guess = g_displayRoot_guess->field148_guess;
                    }
                }
                if (g_mainLoopPlayer_guess != g_mainLoopControlled_guess &&
                    g_mainLoopControlled_guess != 0 && g_flag_00923d78_guess != 0) {
                    if (g_mainLoopControlledMoveTime_guess > g_displayRoot_guess->field148_guess) {
                        g_mainLoopControlledMoveTime_guess = g_displayRoot_guess->field148_guess;
                    }
                    if (g_displayRoot_guess->field148_guess - g_mainLoopControlledMoveTime_guess >
                            0x118) {
                        if (mounted_guess != 0) {
                            MainLoopActorInfo_guess* info_guess =
                                static_cast<MainLoopActorInfo_guess*>(
                                    g_mainLoopControlled_guess->pActorInfo);
                            packet_guess.spawnId_guess =
                                (unsigned short)info_guess->field160_guess->SpawnID;
                            savedZ_guess = g_mainLoopControlled_guess->Z;
                            g_mainLoopControlled_guess->Z =
                                reinterpret_cast<Player1d74_guess*>(info_guess->field160_guess)
                                    ->heightOffset_0238_guess + info_guess->field48_guess;
                            pack_physics_guess(&g_mainLoopControlled_guess->Y,
                                &packet_guess.data_guess, g_mainLoopControlled_guess);
                            g_mainLoopControlled_guess->Z = savedZ_guess;
                        } else {
                            packet_guess.spawnId_guess =
                                (unsigned short)g_mainLoopControlled_guess->SpawnID;
                            pack_physics_guess(&g_mainLoopControlled_guess->Y,
                                &packet_guess.data_guess, g_mainLoopControlled_guess);
                        }
                        if (IsPositionUpdateUnchanged_guess(static_cast<MainLoopActorInfo_guess*>(
                                    g_mainLoopControlled_guess->pActorInfo)->field1010_guess,
                                &packet_guess.data_guess) == 0 ||
                            g_displayRoot_guess->field148_guess -
                                // OP_ClientUpdate for the controlled spawn: when changed or every 1.3 s.
                                // The player's: at most every 280 ms (0x118), 560 ms (0x230) feigning.
                                g_mainLoopControlledMoveTime_guess >= 0x514) {
                            char stopped_guess;
                            if (packet_guess.data_guess.field0c_guess == 0.0f &&
                                packet_guess.data_guess.field08_guess == 0.0f &&
                                packet_guess.data_guess.field04_guess == 0.0f) {
                                stopped_guess = 1;
                            } else {
                                stopped_guess = 0;
                            }
                            float* playerPosition_guess = &g_mainLoopPlayer_guess->Y;
                            packet_guess.field02_guess = FUN_004b718d_guess()->field18_guess;
                            FUN_004b718d_guess()->FUN_004b70db_guess(playerPosition_guess, 2);
                            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x14cb,
                                &packet_guess, 0x24, stopped_guess);
                            g_flag_00923d78_guess = 0;
                            g_mainLoopControlledMoveTime_guess =
                                g_displayRoot_guess->field148_guess;
                            memcpy(static_cast<MainLoopActorInfo_guess*>(
                                    g_mainLoopControlled_guess->pActorInfo)->field1010_guess,
                                &packet_guess.data_guess, 0x20);
                        }
                    }
                }
            } else if (g_flag_00923d79_guess != 0 &&
                       g_mainLoopPlayer_guess->StandState == 'f' &&
                       g_value_0092478c_guess == 0) {
                if (g_mainLoopMoveTime_guess > g_displayRoot_guess->field148_guess) {
                    g_mainLoopMoveTime_guess = g_displayRoot_guess->field148_guess;
                }
                if (g_displayRoot_guess->field148_guess - g_mainLoopMoveTime_guess > 0x230) {
                    packet_guess.spawnId_guess = (unsigned short)g_mainLoopPlayer_guess->SpawnID;
                    pack_physics_guess(&g_mainLoopPlayer_guess->Y, &packet_guess.data_guess,
                        g_mainLoopPlayer_guess);
                    FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x14cb, &packet_guess,
                        0x24, 1);
                    g_flag_00923d79_guess = 0;
                    g_mainLoopMoveTime_guess = g_displayRoot_guess->field148_guess;
                }
            }
        }

        ProcessGameEvents();
        g_value_00923794_guess = 0;
        g_mainLoopLookup_guess->FUN_005f6740_guess(FUN_0046d655_guess());

        EQPlayer* controlled_guess = g_mainLoopControlled_guess;
        if (controlled_guess != 0) {
            MainLoopActorInfo_guess* controlledInfo_guess =
                static_cast<MainLoopActorInfo_guess*>(controlled_guess->pActorInfo);
            if (controlled_guess->Race == 0x8f || controlled_guess->Race == 0x8e ||
                reinterpret_cast<MainLoopPlayerOps_guess*>(controlled_guess)
                    ->IsHorseRace_guess() != 0) {
                g_time_00923854_guess = 0;
            } else {
                if (g_mainLoopFlag_009237b9_guess != 0) {
                    g_time_00923854_guess = 0;
                    if (g_mainLoopControlled_guess->StandState != 'o') {
                        reinterpret_cast<MainLoopPlayerOps_guess*>(g_mainLoopControlled_guess)
                            ->ChangePosition_guess(0x6f);
                        if (g_mainLoopControlled_guess->StandState != 'o') {
                            g_mainLoopFlag_009237b9_guess = 0;
                        }
                    }
                }
                if (g_time_00923854_guess > g_displayRoot_guess->field148_guess) {
                    g_time_00923854_guess = 0;
                }
            }
            if (g_time_00923854_guess != 0) {
                // Jump within 500 ms of the key: OP_Jump (0x797), costing min(50, a tenth of
                // +0x416A40, probably max endurance).
                if (g_displayRoot_guess->field148_guess - g_time_00923854_guess < 500) {
                    if (controlledInfo_guess->fieldad_guess == 0) {
                        if (g_mainLoopControlled_guess->SpeedRun > 0.0f) {
                            g_time_00923854_guess = 0;
                            if (reinterpret_cast<MainLoopPlayerOps_guess*>(
                                    g_mainLoopControlled_guess)->FUN_0048a2f4_guess() != 0) {
                                if (g_mainLoopControlled_guess->StandState == 'o') {
                                    reinterpret_cast<MainLoopPlayerOps_guess*>(
                                        g_mainLoopControlled_guess)->ChangePosition_guess(100);
                                }
                                g_time_00923858_guess = g_displayRoot_guess->field148_guess;
                                if (g_mainLoopPlayer_guess == g_mainLoopControlled_guess) {
                                    g_flag_00923d79_guess = 1;
                                } else {
                                    g_flag_00923d78_guess = 1;
                                }
                                if (g_mainLoopControlled_guess == g_mainLoopPlayer_guess) {
                                    controlled_guess->SpeedZ =
                                        g_mainLoopChar_guess->encum_factor_guess() *
                                        controlledInfo_guess->fieldbc_guess * 1.65f +
                                        controlled_guess->SpeedZ;
                                } else {
                                    controlled_guess->SpeedZ =
                                        controlledInfo_guess->fieldbc_guess * 1.65f +
                                        controlled_guess->SpeedZ;
                                }
                                if (g_mainLoopControlled_guess->Sneak == 0) {
                                    reinterpret_cast<MainLoopPlayerOps_guess*>(
                                        g_mainLoopControlled_guess)->FUN_00489c83_guess(1.0f);
                                }
                                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x797, 0, 0, 1);
                                int cost_guess = 50;
                                if (g_mainLoopChar_guess->Max_Endurance() / 10 < cost_guess) {
                                    cost_guess = g_mainLoopChar_guess->Max_Endurance() / 10;
                                }
                                g_mainLoopChar_guess->FUN_0040e2bd_guess(-cost_guess);
                            }
                        } else if (g_mainLoopControlled_guess->SpeedRun < 0.0f) {
                            g_time_00923854_guess = 0;
                        } else {
                            if (g_mainLoopControlled_guess->StandState == 'd') {
                                reinterpret_cast<MainLoopPlayerOps_guess*>(
                                    g_mainLoopControlled_guess)->ChangePosition_guess(0x6f);
                            }
                            if (g_mainLoopControlled_guess->StandState != 'o') {
                                g_time_00923854_guess = 0;
                            }
                            if (g_mainLoopPlayer_guess == g_mainLoopControlled_guess) {
                                g_flag_00923d79_guess = 1;
                            } else {
                                g_flag_00923d78_guess = 1;
                            }
                        }
                    } else {
                        g_mainLoopControlled_guess->SpeedZ += 0.5f;
                    }
                } else {
                    g_time_00923854_guess = 0;
                    if (g_mainLoopControlled_guess->StandState == 'o') {
                        reinterpret_cast<MainLoopPlayerOps_guess*>(g_mainLoopControlled_guess)
                            ->ChangePosition_guess(100);
                        if (reinterpret_cast<MainLoopPlayerOps_guess*>(
                                g_mainLoopControlled_guess)->FUN_0048a2f4_guess() == 0) {
                            g_time_00923854_guess = 0;
                        } else {
                            g_time_00923858_guess = g_displayRoot_guess->field148_guess;
                            if (g_mainLoopPlayer_guess == g_mainLoopControlled_guess) {
                                g_flag_00923d79_guess = 1;
                            } else {
                                g_flag_00923d78_guess = 1;
                            }
                            if (g_mainLoopControlled_guess == g_mainLoopPlayer_guess) {
                                controlled_guess->SpeedZ =
                                    g_mainLoopChar_guess->encum_factor_guess() *
                                    controlledInfo_guess->fieldbc_guess * 1.65f +
                                    controlled_guess->SpeedZ;
                            } else {
                                controlled_guess->SpeedZ =
                                    controlledInfo_guess->fieldbc_guess * 1.65f +
                                    controlled_guess->SpeedZ;
                            }
                            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x797, 0, 0, 1);
                            int cost_guess = 50;
                            if (g_mainLoopChar_guess->Max_Endurance() / 10 < cost_guess) {
                                cost_guess = g_mainLoopChar_guess->Max_Endurance() / 10;
                            }
                            g_mainLoopChar_guess->FUN_0040e2bd_guess(-cost_guess);
                        }
                    }
                }
            }
        }

        if (pinstCInvSlotMgr_guess != 0) {
            pinstCInvSlotMgr_guess->Refresh_guess(0);
        }
        if (g_loopPipeline_0099d3ec_guess != 0) {
            if (g_flag_00923842_guess == 0) {
                sourceBounds_guess.first_guess = g_loopRenderValueA_009237c8_guess;
                sourceBounds_guess.second_guess = g_loopRenderValueB_009237cc_guess;
                targetBounds_guess.first_guess = g_loopPipeline_0099d3ec_guess->field74_guess;
                targetBounds_guess.second_guess = g_loopPipeline_0099d3ec_guess->field78_guess;
                if (targetBounds_guess.Contains_guess(&sourceBounds_guess) == 0) {
                    g_loopPipeline_0099d3ec_guess->FUN_005af6a0_guess(&sourceBounds_guess);
                }
            }
            if (g_mainLoopChar_guess != 0 && g_mainLoopChar_guess->fieldc288_guess != 0) {
                g_loopPipeline_0099d3ec_guess->FUN_005b06a0_guess();
            }
            if (g_flag_00850508_guess != 3) {
                g_loopPipeline_0099d3ec_guess->FUN_005af250_guess();
                if (g_flag_00923842_guess == 0) {
                    g_loopPipeline_0099d3ec_guess->FUN_005af580_guess();
                }
            }
        }
        if (active_guess != 0) {
            ProcessControls_guess();
        }
        if (frameSkip_guess == 0) {
            g_ownedDisplay_guess->Render_World_guess();
        } else {
            frameSkip_guess--;
        }
        int delay_guess;
        if (g_mainLoopFlag_00988c76_guess != 0) {
            delay_guess = 100;
        } else if (g_mainLoopValue_009254c4_guess == 100) {
            delay_guess = 1;
        } else {
            delay_guess = g_mainLoopFrameTime_guess -
                (FUN_0046d655_guess() - g_value_0092385c_guess);
            if (delay_guess < 1) {
                delay_guess = 1;
            }
        }
        Sleep(delay_guess);
    }
}

struct ProcessPCName_guess {
    char text_guess[0x40];
    // EXTERNAL: TITANIUM 0x0040E25C ProcessPCName_guess::Set_guess
    void Set_guess(char* text_guess_);
};

struct ProcessPCBase_guess {
    virtual void RefreshCounts_guess();
    virtual ~ProcessPCBase_guess();
    char padding_0004_guess[0x38];
    ProcessPCName_guess name_guess; // 0x3C
    char padding_007c_guess[0x84];
    int zone_guess; // 0x100
};

struct ProcessPCItem_guess {
    virtual ~ProcessPCItem_guess();
};

struct ProcessPC_guess : NetPCPrefix_guess, virtual ProcessPCBase_guess {
    // EXTERNAL: TITANIUM 0x004BF2A7 ProcessPC_guess::ProcessPC_guess
    ProcessPC_guess();
    // EXTERNAL: TITANIUM 0x005F0790 ProcessPC_guess::FUN_005f0790_guess
    void FUN_005f0790_guess(int zero_guess, int zone_guess_);
    char padding_000c_guess[0xD38 - 0xC];
    BoundedArray_guess<ProcessPCItem_guess*, 36> items_guess; // 0xD38
    char padding_0dc8_guess[0xC4D0 - 0x104 - 0xDC8];
};

struct ProcessZoneLookup_guess {
    // EXTERNAL: TITANIUM 0x005F6F20 ProcessZoneLookup_guess::FUN_005f6f20_guess
    int FUN_005f6f20_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x005F6B00 ProcessZoneLookup_guess::FUN_005f6b00_guess
    int FUN_005f6b00_guess(int a_guess, int b_guess, char* shortName_guess, char* longName_guess,
        int c_guess, int d_guess, int e_guess, int f_guess, int g_guess);
};

struct ProcessDisplay_guess {
    char padding_0000_guess[0x10];
    unsigned char field10_guess; // 0x10
    // EXTERNAL: TITANIUM 0x0043745D ProcessDisplay_guess::FUN_0043745d_guess
    int FUN_0043745d_guess();
    // EXTERNAL: TITANIUM 0x0044350D ProcessDisplay_guess::StopWorldDisplay_guess
    void StopWorldDisplay_guess();
    // EXTERNAL: TITANIUM 0x0043BA81 ProcessDisplay_guess::ActivateMainUI_guess
    void ActivateMainUI_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00437BCD ProcessDisplay_guess::DeactivateMainUI_guess
    void DeactivateMainUI_guess();
};

struct ProcessAAManager_guess {
    // EXTERNAL: TITANIUM 0x00447EE9 ProcessAAManager_guess::FUN_00447ee9_guess
    void FUN_00447ee9_guess();
    // EXTERNAL: TITANIUM 0x0044826B ProcessAAManager_guess::FUN_0044826b_guess
    void FUN_0044826b_guess();
};

struct ProcessSkillManager_guess {
    // EXTERNAL: TITANIUM 0x005541DB ProcessSkillManager_guess::RequestUpdateAA_guess
    void RequestUpdateAA_guess();
};

struct ProcessObject850350_guess {
    // EXTERNAL: TITANIUM 0x00433E0D ProcessObject850350_guess::RequestTributeLists_guess
    void RequestTributeLists_guess();
};

struct ProcessGroup_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 ProcessGroup_guess::IsInRaid_guess
    char IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x004307A4 ProcessGroup_guess::SetTargetRaidPlayer_guess
    void SetTargetRaidPlayer_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004310A3 ProcessGroup_guess::RemoveSelectedOrLeave_guess
    void RemoveSelectedOrLeave_guess();
    // EXTERNAL: TITANIUM 0x004315F6 ProcessGroup_guess::ResetRaid_guess
    void ResetRaid_guess();
};

struct ProcessPlayer_guess {
    char padding_0000_guess[0x24C];
    unsigned char field24c_guess; // 0x24C
};

struct ProcessWorker_guess {
    char padding_0000_guess[0xC];
    unsigned char busy_guess; // 0x0C
};

struct ProcessGameTail_guess {
    char padding_0000_guess[0x3A1BB];
    unsigned char field3a1bb_guess; // 0x3A1BB
};

// EXTERNAL: TITANIUM 0x0046DD41 SendSpellChecksum_guess
int __cdecl SendSpellChecksum_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0046DEA9 SendExeChecksum_guess
int __cdecl SendExeChecksum_guess(int value_guess);
// EXTERNAL: TITANIUM 0x00469DD7 FUN_00469dd7_value_guess
void __cdecl FUN_00469dd7_value_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0049129C FUN_0049129c_guess
void __cdecl FUN_0049129c_guess(char* value_guess);

#define g_processPC_guess EQ_GLOBAL(ProcessPC_guess*, 0x00905D00)
#define g_processLookup_guess EQ_GLOBAL(ProcessZoneLookup_guess*, 0x00905CC0)
#define g_processDisplay_guess EQ_GLOBAL(ProcessDisplay_guess*, 0x00905D24)
#define g_processAAManager_guess EQ_GLOBAL(ProcessAAManager_guess*, 0x008511D8)
#define g_processSkillManager_guess EQ_GLOBAL(ProcessSkillManager_guess*, 0x00991FA8)
#define g_processObject850350_guess EQ_ARRAY(ProcessObject850350_guess, 0x00850350)
#define g_processGroup_guess EQ_ARRAY(ProcessGroup_guess, 0x0091D708)
#define g_processPlayer_guess EQ_GLOBAL(ProcessPlayer_guess*, 0x00905CE4)
#define g_processWorker_guess EQ_GLOBAL(ProcessWorker_guess*, 0x0085098C)
#define g_processItems_00903ea0_guess EQ_ARRAY(BufferHolder_guess, 0x00903EA0)
#define g_processInstance_00923774_guess EQ_GLOBAL(int, 0x00923774)
#define g_processLoops_00988de8_guess EQ_GLOBAL(int, 0x00988DE8)
#define g_processAuth_00904208_guess EQ_GLOBAL(int, 0x00904208)
#define g_processZoneName_00904104_guess EQ_ARRAY(char, 0x00904104)
#define g_processValue_00850910_guess EQ_GLOBAL(int, 0x00850910)
#define g_processValue_009237ac_guess EQ_GLOBAL(int, 0x009237AC)
#define g_processTable_00904248_guess EQ_ARRAY(char, 0x00904248)

// Top-level loop until state 0xFF: authenticates to the world, runs char select (StartNetworkGame), waits
// up to 120 s for the zone, then per zone GetZoneInfoFromNetwork, EnterZone and DoMainLoop, re-authenticating
// (5 tries) after each zone change. Offline modes fake a PC ('Soandso' in zone 183, or a named zone).
// FUNCTION: TITANIUM 0x004ACF33
// @early-stop: budget, structural ndiff=76
void GlobalState_guess::ProcessGame_guess(HWND window_guess, int instance_guess) {
    g_processInstance_00923774_guess = instance_guess;
    g_globalState_guess->SetGameStateInline_guess(0);
    g_value_00923794_guess = 0;
    FUN_00574110_guess("Starting process game.");
    memset(g_processTable_00904248_guess, 0, 0x19c);
    while (state_guess != 0xff) {
        // FPU control word: all exceptions masked, truncation, 24-bit precision.
        _control87(0xa031f, 0xf031f);
        g_processLoops_00988de8_guess++;
        if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0) {
            if (strcmp(g_nameBuffer_00905c18_guess, g_text_0063f53f_guess) == 0) {
                if (g_connection_00905ca0_guess == 0 ||
                    reinterpret_cast<LockedValues_guess*>(g_connection_00905ca0_guess)
                        ->GetField88_guess() == 1) {
                    g_processAuth_00904208_guess = 1;
                    g_connection_00905ca0_guess = FUN_004b649f_guess(window_guess, instance_guess);
                    if (g_connection_00905ca0_guess != 0) {
                        g_connection_00905ca0_guess->BeginWait_guess(
                            g_connectionManager_guess != 0
                                ? reinterpret_cast<DisconnectWaitState_guess*>(
                                    &g_connectionManager_guess->field48_guess)
                                : 0);
                    } else if (g_globalState_guess->fieldb50_guess == 1) {
                        FUN_00574110_guess("*** ERROR: ProcessGame could not authenticate to world.  "
                            "Bailing with END_GAME.\n");
                        g_globalState_guess->SetGameStateInline_guess(0xff);
                        return;
                    }
                }
                StartNetworkGame((int)window_guess, instance_guess, g_nameBuffer_00905c18_guess);
            } else {
                if (SendSpellChecksum_guess(0) == 0) {
                    FUN_00574110_guess("ERROR: Missing or corrupt datafile: Spdat.eff\n");
                    field39400_guess = 1;
                    g_globalState_guess->SetGameStateInline_guess(0xff);
                    g_value_00923794_guess = 0xfd;
                    fieldb50_guess = 1;
                    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                }
                if (SendExeChecksum_guess(0) == 0) {
                    FUN_00574110_guess("ERROR2: Missing or corrupt file: eqgame.exe\n");
                    field39400_guess = 1;
                    g_globalState_guess->SetGameStateInline_guess(0xff);
                    g_value_00923794_guess = 0xfd;
                    fieldb50_guess = 1;
                    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                }
                EnterWorldPacket_guess packet_guess;
                memset(&packet_guess, 0, sizeof(packet_guess));
                FUN_0060e450_guess(packet_guess.name_guess, g_nameBuffer_00905c18_guess);
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7cba, &packet_guess,
                    sizeof(packet_guess), 1);
                g_globalState_guess->SetGameStateInline_guess(3);
                g_netZoneAddr_00905c98_guess = 0;
                g_notice_00904228_guess = 0;
                g_notice_00905cb4_guess = 0;
                if (g_processPC_guess != 0) {
                    delete g_processPC_guess;
                    g_processPC_guess = 0;
                }
                g_processPC_guess = new ProcessPC_guess;
                unsigned int deadline_guess = FUN_0046d655_guess() + 120000;
                g_connection_00905ca0_guess->BeginWait_guess(
                    g_connectionManager_guess != 0
                        ? reinterpret_cast<DisconnectWaitState_guess*>(
                            &g_connectionManager_guess->field48_guess)
                        : 0);
                while (state_guess == 3) {
                    reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
                    if (g_netZoneAddr_00905c98_guess != 0) {
                        g_globalState_guess->SetGameStateInline_guess(0xfd);
                        break;
                    }
                    if (g_notice_00904228_guess != 0) {
                        StartNetworkGame((int)window_guess, instance_guess,
                            g_nameBuffer_00905c18_guess);
                    } else if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                            "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4dba, 1) != 0) {
                        return;
                    }
                    Sleep(10);
                    if (FUN_0046d655_guess() > deadline_guess) {
                        reinterpret_cast<DisconnectOwner_guess*>(this)->DisplayScreen_guess(
                            "Respond.bmp");
                        Sleep(2000);
                        FUN_00574110_guess("TIMED OUT WAITING FOR ZONE CONNECT\n");
                        field39400_guess = 1;
                        g_globalState_guess->SetGameStateInline_guess(0xff);
                        g_value_00923794_guess = 0xfd;
                        fieldb50_guess = 1;
                        g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                        return;
                    }
                }
            }
            if (fieldb50_guess == 1 || state_guess == 0xff) {
                fieldb50_guess = 0;
                g_globalState_guess->SetGameStateInline_guess(0xff);
                return;
            }
        } else if (g_flag_00923884_guess != 0) {
            if (g_processPC_guess != 0) {
                delete g_processPC_guess;
                g_processPC_guess = 0;
            }
            g_processPC_guess = new ProcessPC_guess;
            g_processPC_guess->FUN_005f0790_guess(0, 0xb7);
            g_processPC_guess->zone_guess = 0xb7;
            g_processPC_guess->name_guess.Set_guess("Soandso");
        } else {
            if (g_processPC_guess != 0) {
                delete g_processPC_guess;
                g_processPC_guess = 0;
            }
            g_processPC_guess = new ProcessPC_guess;
            if (g_processZoneName_00904104_guess[0] != 0 &&
                _strnicmp(g_processZoneName_00904104_guess, "eqworld", 7) != 0) {
                if (g_processLookup_guess->FUN_005f6f20_guess(g_processZoneName_00904104_guess) == 0) {
                    g_processLookup_guess->FUN_005f6b00_guess(0, 0x3e5,
                        g_processZoneName_00904104_guess, g_processZoneName_00904104_guess,
                        0, 0, 0, 0, 0);
                    if (g_processLookup_guess->FUN_005f6f20_guess(
                            g_processZoneName_00904104_guess) == 0) {
                        FUN_0060e450_guess(g_processZoneName_00904104_guess, "qeynos");
                    }
                }
                g_processPC_guess->FUN_005f0790_guess(0,
                    g_processLookup_guess->FUN_005f6f20_guess(g_processZoneName_00904104_guess));
                g_processPC_guess->zone_guess =
                    g_processLookup_guess->FUN_005f6f20_guess(g_processZoneName_00904104_guess);
            } else {
                g_processPC_guess->FUN_005f0790_guess(0, 1);
                g_processPC_guess->zone_guess = 1;
                FUN_0060e450_guess(g_processZoneName_00904104_guess, "qeynos");
            }
            g_processPC_guess->name_guess.Set_guess(g_netNoName_00904004_guess);
        }
        g_flag_00850508_guess = 2;
        g_processValue_00850910_guess = 2;
        if (g_sendDisabled_00923798_guess == 0 && g_flag_00923884_guess == 0 &&
            g_processDisplay_guess->FUN_0043745d_guess() != 0) {
            g_processDisplay_guess->StopWorldDisplay_guess();
        }
        while (state_guess != 0xff) {
            if (g_flag_00923d7a_guess != 0) {
                FUN_00574110_guess("Beginning EnterZone block.\n");
                g_processAuth_00904208_guess = 1;
                int countdown_guess = 5;
                do {
                    countdown_guess--;
                    FUN_00574110_guess("Calling WorldAuthenticate.  Countdown is %d\n",
                        countdown_guess);
                    g_connection_00905ca0_guess = FUN_004b649f_guess(window_guess, instance_guess);
                    if (g_connection_00905ca0_guess != 0) {
                        g_connection_00905ca0_guess->BeginWait_guess(
                            g_connectionManager_guess != 0
                                ? reinterpret_cast<DisconnectWaitState_guess*>(
                                    &g_connectionManager_guess->field48_guess)
                                : 0);
                        break;
                    }
                    g_globalState_guess->fieldb50_guess = 0;
                    Sleep(2500);
                } while (countdown_guess != 0);
                g_flag_00923d7a_guess = 0;
                if (g_connection_00905ca0_guess == 0) {
                    FUN_00574110_guess(
                        "ERROR: Unable to get player name, g_world is NULL, not connected.\n");
                }
                if (strcmp(g_nameBuffer_00905c18_guess, g_text_0063f53f_guess) == 0) {
                    FUN_00574110_guess("World not ready, disconnected at %s:%u\n",
                        "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4f0f);
                    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                    field39400_guess = 1;
                    reinterpret_cast<DisconnectOwner_guess*>(this)->DisplayScreen_guess("Discon.bmp");
                    Sleep(3000);
                    g_globalState_guess->SetGameStateInline_guess(0xff);
                    g_value_00923794_guess = 0xfd;
                    fieldb50_guess = 1;
                    return;
                }
                g_globalState_guess->SetGameStateInline_guess(3);
                g_netZoneAddr_00905c98_guess = 0;
                g_notice_00904228_guess = 0;
                FUN_0046d655_guess();
                if (SendSpellChecksum_guess(0) == 0) {
                    FUN_00574110_guess("ERROR: Missing or corrupt datafile: Spdat.eff\n");
                    field39400_guess = 1;
                    g_globalState_guess->SetGameStateInline_guess(0xff);
                    g_value_00923794_guess = 0xfd;
                    fieldb50_guess = 1;
                    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                }
                if (SendExeChecksum_guess(0) == 0) {
                    FUN_00574110_guess("ERROR: Missing or corrupt datafile: Spdat.eff\n");
                    field39400_guess = 1;
                    g_globalState_guess->SetGameStateInline_guess(0xff);
                    g_value_00923794_guess = 0xfd;
                    fieldb50_guess = 1;
                    g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                }
                FUN_0046d655_guess();
                EnterWorldPacket_guess zonePacket_guess;
                memset(&zonePacket_guess, 0, sizeof(zonePacket_guess));
                FUN_0060e450_guess(zonePacket_guess.name_guess, g_nameBuffer_00905c18_guess);
                FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x7cba, &zonePacket_guess,
                    sizeof(zonePacket_guess), 1);
                if (g_processPC_guess != 0) {
                    FUN_00574110_guess("Waiting to connect to zone... Character %s\n",
                        g_processPC_guess->name_guess.text_guess);
                } else {
                    FUN_00574110_guess("Waiting to connect to zone...\n");
                }
                while (state_guess == 3) {
                    reinterpret_cast<TargetOwner_guess*>(this)->ProcessMBox_guess();
                    if (g_netZoneAddr_00905c98_guess != 0) {
                        g_globalState_guess->SetGameState(5);
                        FUN_0046d655_guess();
                        break;
                    }
                    if (g_notice_00904228_guess != 0) {
                        FUN_00574110_guess("received ZoneUnavailable from world server\n");
                        g_value_00923794_guess = 0xfe;
                        g_globalState_guess->SetGameState(5);
                        g_connectionManager_guess->Teardown_guess(&g_connection_00905ca0_guess);
                        g_processDisplay_guess->StopWorldDisplay_guess();
                        break;
                    }
                    if (reinterpret_cast<DisconnectOwner_guess*>(this)->CheckCharSelectDisconnect_guess(
                            "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4eff, 1) != 0) {
                        return;
                    }
                    Sleep(10);
                }
            }
            reinterpret_cast<DisconnectOwner_guess*>(this)->GetZoneInfoFromNetwork(
                g_nameBuffer_00905c18_guess);
            if (fieldb50_guess == 1) {
                FUN_00574110_guess("nError is TRUE at %s:%u\n",
                    "C:\\EQ\\EverQuest\\EverQuest.cpp", 0x4f25);
                break;
            }
            FUN_00574110_guess("Initializing zone.");
            reinterpret_cast<CEverQuest_guess*>(this)->EnterZone((int)window_guess);
            FUN_00574110_guess("Creating INI files.");
            g_globalState_guess->CreateIniFilenames_guess();
            FUN_00574110_guess("Requesting AA data.");
            g_processAAManager_guess->FUN_00447ee9_guess();
            FUN_00574110_guess("Requesting Skill rank data.");
            g_processSkillManager_guess->RequestUpdateAA_guess();
            if (pinstCMerchantWnd_guess == 0) {
                FUN_0049128a_guess(FUN_0049129c_guess);
                g_processObject850350_guess->RequestTributeLists_guess();
                if (pinstCTipWndOFDAY_guess != 0) {
                    pinstCTipWndOFDAY_guess->selectTip_guess(-1, 0);
                }
                if (g_processPlayer_guess != 0 && g_processPlayer_guess->field24c_guess < 2) {
                    pinstCPetInfoWnd_guess->Deactivate();
                }
            } else {
                g_processDisplay_guess->ActivateMainUI_guess(0);
                if (reinterpret_cast<ProcessGameTail_guess*>(this)->field3a1bb_guess != 0) {
                    reinterpret_cast<ProcessGameTail_guess*>(this)->field3a1bb_guess = 0;
                    if (pinstCTipWndCONTEXT_guess != 0) {
                        pinstCTipWndCONTEXT_guess->selectTip_guess(0x1f, 0);
                    }
                }
            }
            if (g_processWorker_guess != 0) {
                while (g_processWorker_guess->busy_guess != 0) {
                    Sleep(10);
                }
                reinterpret_cast<ListOwner_guess*>(g_processWorker_guess)->Release_guess(1);
                g_processWorker_guess = 0;
            }
            FUN_00574110_guess("Entering main loop.");
            DoMainLoop(window_guess);
            g_processDisplay_guess->DeactivateMainUI_guess();
            g_mainLoopReady_guess = 0;
            if (g_processPC_guess != 0) {
                for (int i_guess = 0; i_guess < 36; i_guess++) {
                    if (g_processPC_guess->items_guess[i_guess] != 0) {
                        delete g_processPC_guess->items_guess[i_guess];
                        g_processPC_guess->items_guess[i_guess] = 0;
                    }
                }
            }
            g_processDisplay_guess->field10_guess = 0;
            g_processItems_00903ea0_guess->ClearItems_guess();
            if (g_value_00923794_guess == 0xfd || g_value_00923794_guess == 0xfe) {
                FUN_00574110_guess("Cleaning up groups.");
                g_resetOwner_guess->SetGroupInvitePending_guess(0);
                g_globalState_guess->Disband_guess();
                if (g_processGroup_guess->IsInRaid_guess() != 0) {
                    g_processGroup_guess->SetTargetRaidPlayer_guess(0);
                    g_processGroup_guess->RemoveSelectedOrLeave_guess();
                }
                g_processGroup_guess->ResetRaid_guess();
                g_processAAManager_guess->FUN_0044826b_guess();
            }
            FUN_00574110_guess("Stopping world display.");
            g_processDisplay_guess->StopWorldDisplay_guess();
            if (g_value_00923794_guess == 0xfd || g_value_00923794_guess == 0xfe) {
                break;
            }
        }
        FUN_0060e450_guess(g_nameBuffer_00905c18_guess, g_text_0063f53f_guess);
        if (g_value_00923794_guess == 0xfe) {
            if (g_processPC_guess != 0) {
                FUN_00574110_guess("Cleaning up.");
                delete g_processPC_guess;
                g_processPC_guess = 0;
            }
            FUN_00574110_guess("Sending Logout.");
            // Opcode 0xF66 (not in patch_Titanium.conf), sent after the logout log line.
            FUN_004912b1_guess(&g_connection_00905ca0_guess, 0xf66, 0, 0, 1);
            if (g_processValue_009237ac_guess == 0) {
                FUN_00469dd7_value_guess(-1);
            }
        }
        if (g_value_00923794_guess == 0xfd) {
            fieldb50_guess = 0;
            g_globalState_guess->SetGameStateInline_guess(0xff);
            FUN_00574110_guess("Exiting normally.");
            return;
        }
    }
    FUN_00574110_guess("*** WARNING: ProcessGame.  Dropped out of game loop.\n");
}

struct SaveCharValue_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 SaveCharValue_guess::Get_guess
    char* Get_guess();
};

struct SaveCharNames_guess {
    char padding_0000_guess[0x34];
    SaveCharValue_guess* first_guess; // 0x34
    SaveCharValue_guess* second_guess; // 0x38
    SaveCharValue_guess* GetFirstName_guess() { return first_guess; }
    SaveCharValue_guess* GetSecondName_guess() { return second_guess; }
};

struct SaveCharInfoHead_guess {
    char padding_0000_guess[0x10];
};

// The names sit in the second base, at +0x10.
struct SaveCharInfo_guess : SaveCharInfoHead_guess, SaveCharNames_guess {
};

struct SaveCharLookup_guess {
    void* list_guess;
    int key_guess;
    // EXTERNAL: TITANIUM 0x005EC220 SaveCharLookup_guess::GetCharInfo2
    SaveCharInfo_guess* GetCharInfo2();
};

struct SaveCharVHead_guess {
    virtual void RefreshCounts_guess();
};

// The virtual base of the character object.
struct SaveCharCore_guess : SaveCharVHead_guess, SaveCharLookup_guess {
    char padding_000c_guess[0x20];
    float y_guess; // 0x2C
    float x_guess; // 0x30
    float z_guess; // 0x34
    float heading_guess; // 0x38
    char padding_003c_guess[0x80];
    union {
        TextReceiver_guess textObject_guess;
        char text_guess[0x40];
    }; // 0xBC
    SaveCharInfo_guess* GetInfo_guess() { return GetCharInfo2(); }
};

struct SaveCharHead_guess {
    virtual void RefreshCounts_guess();
    int field04_guess;
};

struct SaveChar_guess : SaveCharHead_guess, virtual SaveCharCore_guess {
    char padding_000c_guess[0xe14];
    int fielde20_guess; // 0xE20
    char padding_0e24_guess[0x0c];
    int fielde30_guess; // 0xE30
    // EXTERNAL: TITANIUM 0x005ED8A0 SaveChar_guess::SetFirst_guess
    void SetFirst_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED8E0 SaveChar_guess::SetSecond_guess
    void SetSecond_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED880 SaveChar_guess::GetFirst_guess
    int GetFirst_guess();
    // EXTERNAL: TITANIUM 0x005ED8C0 SaveChar_guess::GetSecond_guess
    int GetSecond_guess();
    // EXTERNAL: TITANIUM 0x005F05E0 SaveChar_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005F06B0 SaveChar_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x004BE2DC SaveChar_guess::SetChoice_guess
    void SetChoice_guess(int index_guess, int value_guess);
};

struct SavePlayer_guess {
    char padding_0000_guess[0x30];
    float y_guess; // 0x30
    float x_guess; // 0x34
    float z_guess; // 0x38
    char padding_003c_guess[0x10];
    float heading_guess; // 0x4C
    char padding_0050_guess[0x16c];
    int choices_guess[9]; // 0x1BC
    char padding_01e0_guess[0x64];
    unsigned char type_guess; // 0x244
    // EXTERNAL: TITANIUM 0x0047A3D0 SavePlayer_guess::GetValue_guess
    int GetValue_guess(int index_guess);
};

struct SaveData_guess {
    float y_guess;
    float x_guess;
    float z_guess;
    int heading_guess;
    int values_guess[22];
    char name_guess[0x40];
    int fielde20_guess;
    int first_guess;
    int second_guess;
    int fielde30_guess;
};

struct SavePacket_guess {
    int hash_guess;
    unsigned char flags_guess;
    unsigned char payload_guess[0xbb];
};

#define g_saveChar_guess EQ_GLOBAL(SaveChar_guess*, 0x00905D00)
#define g_savePlayer_guess EQ_GLOBAL(SavePlayer_guess*, 0x00905CE4)

// Refreshes the profile from the live player (position, boat, appearance) and, unless `home`, sends
// OP_SaveOnZoneReq (0x1540) with a checksum; the layout matches SavePC's OP_Save.
// FUNCTION: TITANIUM 0x004976BF
void GlobalState_guess::SavePCOnZone_guess(int home_guess) {
    char text_guess[0x400];
    char cleanedName_guess[0x40];
    SavePacket_guess packet_guess;
    SaveData_guess data_guess;

    FUN_004b07d8_guess();
    if (g_flag_00924676_guess == 0) {
        if (g_savePlayer_guess->type_guess == 0) {
            g_saveChar_guess->y_guess = g_savePlayer_guess->y_guess;
            g_saveChar_guess->x_guess = g_savePlayer_guess->x_guess;
            g_saveChar_guess->z_guess = g_savePlayer_guess->z_guess;
            g_saveChar_guess->heading_guess = g_savePlayer_guess->heading_guess;
        }
        if (strlen(g_saveChar_guess->text_guess) > 0) {
            reinterpret_cast<NameCleaner_guess*>(this)->StripShipName_guess(
                g_saveChar_guess->text_guess, cleanedName_guess);
            int candidate_guess = FindPlayerByPartialDisplayName_guess(
                reinterpret_cast<NameCleaner_guess*>(this)->StripShipName_guess(
                    g_saveChar_guess->text_guess, cleanedName_guess), 0);
            if (candidate_guess != 0) {
                TransformPassengersToBoatSpace_guess(reinterpret_cast<void*>(candidate_guess));
                g_saveChar_guess->y_guess = g_savePlayer_guess->y_guess;
                g_saveChar_guess->x_guess = g_savePlayer_guess->x_guess;
                g_saveChar_guess->z_guess = g_savePlayer_guess->z_guess;
                g_saveChar_guess->heading_guess = g_savePlayer_guess->heading_guess;
                TransformPassengersToWorldSpace_guess(reinterpret_cast<void*>(candidate_guess));
            } else {
                g_saveChar_guess->textObject_guess.FUN_0040e25c_guess(g_text_0063f53f_guess);
            }
        }
    }

    g_saveChar_guess->SetFirst_guess(0);
    g_saveChar_guess->SetSecond_guess(0);
    if (g_saveChar_guess->GetInfo_guess()->GetFirstName_guess() != 0) {
        strcpy(text_guess,
            g_saveChar_guess->GetInfo_guess()->GetFirstName_guess()->Get_guess());
        strcpy(text_guess, text_guess + 2);
        if (is_number_guess(text_guess) != 0) {
            g_saveChar_guess->SetFirst_guess(atoi(text_guess));
        }
    }
    if (g_saveChar_guess->GetInfo_guess()->GetSecondName_guess() != 0) {
        strncpy(text_guess,
            g_saveChar_guess->GetInfo_guess()->GetSecondName_guess()->Get_guess(), 0xf);
        strcpy(text_guess, text_guess + 2);
        if (is_number_guess(text_guess) != 0) {
            g_saveChar_guess->SetSecond_guess(atoi(text_guess));
        }
    }

    if (g_savePlayer_guess != 0) {
        for (int index_guess = 0; index_guess < 9; ++index_guess) {
            g_saveChar_guess->SetValue_guess(index_guess,
                g_savePlayer_guess->GetValue_guess(index_guess));
            g_saveChar_guess->SetChoice_guess(index_guess,
                g_savePlayer_guess->choices_guess[index_guess]);
        }
    }

    if (home_guess == 0) {
        memset(&packet_guess, 0, sizeof(packet_guess));
        data_guess.y_guess = g_saveChar_guess->y_guess;
        data_guess.x_guess = g_saveChar_guess->x_guess;
        data_guess.z_guess = g_saveChar_guess->z_guess;
        data_guess.heading_guess = (int)g_saveChar_guess->heading_guess;
        data_guess.fielde20_guess = g_saveChar_guess->fielde20_guess;
        data_guess.first_guess = g_saveChar_guess->GetFirst_guess();
        data_guess.second_guess = g_saveChar_guess->GetSecond_guess();
        data_guess.fielde30_guess = g_saveChar_guess->fielde30_guess;
        strcpy(data_guess.name_guess, g_saveChar_guess->text_guess);
        for (int valueIndex_guess = 0; valueIndex_guess < 22; ++valueIndex_guess) {
            data_guess.values_guess[valueIndex_guess] =
                g_saveChar_guess->GetValue_guess(valueIndex_guess);
        }
        memcpy(packet_guess.payload_guess, &data_guess, sizeof(data_guess));
        packet_guess.hash_guess = MemChecker0(packet_guess.payload_guess,
            sizeof(data_guess));
        packet_guess.flags_guess = 0;
        FUN_004912b1_guess(&g_connection_00905ca0_guess, 0x1540, &packet_guess,
            sizeof(packet_guess), 1);
    }
    g_flag_00924673_guess = 0;
    g_flag_00923788_guess = 0;
}
