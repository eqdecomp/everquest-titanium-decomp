// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EQPlayer core: model tags, race sizes, faces, hair, armor, the name sprite, mounts, illusions, ctor, dtor.
// EQPlayerCore/RaceView/StatusView/ArmorView/BoneView/PcView_guess and ActorInfoView_guess are per-function
// views of EQPlayer (types.h) and its pActorInfo (+0x1A8); SpawnStruct_guess is the Titanium Spawn_Struct
// (EQEmu offsets). Command_guess::TotalSpellAffects_guess(n) totals spell effect n (11 haste, 40 divine aura).
#include <winsock2.h>
#include <windows.h>
#include "titanium/types.h"
#include "titanium/skills.h"
#include "titanium/races.h"
#include "titanium/opcodes.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <new>
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z

struct CallbackTarget_guess {
    void OnCallback_guess();
};

struct TextSink_guess {
    // EXTERNAL: TITANIUM 0x00498436 TextSink_guess::dsp_chat
    void dsp_chat(const char* text);
    // EXTERNAL: TITANIUM 0x004980E7 TextSink_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00496B08 TextSink_guess::UpdateAppearance_guess
    void UpdateAppearance_guess(void* player, int light);
};

#define g_callbackTarget_guess EQ_GLOBAL(CallbackTarget_guess*, 0x00905CE4)
#define g_textSink_guess EQ_GLOBAL(TextSink_guess*, 0x00988DF0)

struct Entry_guess {
    int count;
    int index;
    unsigned char flag;
};

struct Input_guess {
    int unknown;
    Entry_guess entries[5];
};

struct Chain_guess {
    char* object_000_guess;
    int key_004_guess;
    Chain_guess* next_008_guess;
    // EXTERNAL: TITANIUM 0x004FF9C9 Chain_guess::FindByHash_guess
    Chain_guess* FindByHash_guess(unsigned int hash);
    Chain_guess* FindNext_guess(Chain_guess* entry);
};

struct RemovalNode_guess {
    char pad_000_guess[0x5c];
    RemovalNode_guess* next_05c_guess;
    int key_060_guess;
    // EXTERNAL: TITANIUM 0x004519E8 RemovalNode_guess::Remove_guess
    void Remove_guess();
};

#define g_chainList_guess EQ_GLOBAL(RemovalNode_guess*, 0x00905CDC)
#define g_chainLookup_guess EQ_GLOBAL(Chain_guess*, 0x00903E50)

// EXTERNAL: TITANIUM 0x00574890 FUN_00574890_guess
unsigned int __cdecl FUN_00574890_guess(const char* text);

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x00574510 FUN_00574510_guess
unsigned int __cdecl FUN_00574510_guess(const char* source, int* character);

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination, const char* source, int length);

// EXTERNAL: TITANIUM 0x0060E590 FUN_0060e590_guess
int __cdecl FUN_0060e590_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x00473CC3 ConvertNameToLocal_guess
void __cdecl ConvertNameToLocal_guess(char* text);

extern "C" {
int __cdecl _iswdigit(int value);
}

extern "C" {
// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);
}

struct PowerTable_guess {
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    int field_00c_guess;
    int field_010_guess;
    int field_014_guess;
    unsigned char field_018_guess;
    PowerTable_guess();
    void Initialize_guess(int value);
};

struct CallbackResult_guess;

struct Target_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess(int value);
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void Slot018_guess();
    virtual void Slot019_guess();
    virtual void Slot020_guess();
    virtual void Slot021_guess();
    virtual void Slot022_guess();
    virtual void Slot023_guess();
    virtual void Slot024_guess();
    virtual void Slot025_guess();
    virtual void Slot026_guess();
    virtual void Slot027_guess();
    virtual void Slot028_guess();
    virtual void Slot029_guess();
    virtual void Slot030_guess();
    virtual void Slot031_guess();
    virtual void Slot032_guess();
    virtual void Slot033_guess();
    virtual void Slot034_guess();
    virtual void Slot035_guess();
    virtual void Slot036_guess();
    virtual void Slot037_guess();
    virtual void Slot038_guess();
    virtual void Slot039_guess();
    virtual void Slot040_guess();
    virtual void Slot041_guess();
    virtual void Slot042_guess();
    virtual void Slot043_guess();
    virtual char Slot044_guess(char* first, char* second, unsigned char* color, int flags);
    virtual void Slot045_guess();
    virtual void Slot046_guess();
    virtual void Slot047_guess();
    virtual void Slot048_guess(int value, float* output, int flags);
    virtual void Slot049_guess();
    virtual void Slot050_guess();
    virtual void Slot051_guess();
    virtual void Slot052_guess();
    virtual void Slot053_guess();
    virtual void Slot054_guess();
    virtual void Slot055_guess();
    virtual void Slot056_guess();
    virtual void Slot057_guess();
    virtual void Slot058_guess();
    virtual int Slot059_guess(int type, const char* name);
    virtual void Slot060_guess();
    virtual void Slot061_guess(int value, unsigned char* color);
    virtual unsigned char Slot062_guess(char* text);
    virtual unsigned char Slot063_guess(int value, char* text);
    virtual void Slot064_guess();
    virtual void Slot065_guess();
    virtual void Slot066_guess(int* first, int* second, bool flag, bool isType);
    virtual char Slot067_guess(int value, int state);
    virtual void Slot068_guess();
    virtual void Slot069_guess();
    virtual void Slot070_guess();
    virtual void Slot071_guess();
    virtual void Slot072_guess();
    virtual void Slot073_guess();
    virtual void Slot074_guess();
    virtual void Slot075_guess();
    virtual void Slot076_guess();
    virtual int Slot077_guess(const char* name);
    virtual void Slot078_guess();
    virtual void Slot079_guess();
    virtual void Slot080_guess();
    virtual void Slot081_guess();
    virtual void Slot082_guess();
    virtual void Slot083_guess(int index, const char* name);
    virtual void Slot084_guess(int value);
    virtual char Slot085_guess(int value);
    virtual CallbackResult_guess* Slot086_guess(int value);
    virtual void Slot087_guess();
    virtual void Slot088_guess();
    virtual void Slot089_guess();
    virtual void Slot090_guess();
    virtual void Slot091_guess();
    virtual int Slot092_guess(int value);
    virtual void Slot093_guess();
    virtual void Slot094_guess();
    virtual void Slot095_guess();
    virtual void Slot096_guess();
    virtual void Slot097_guess();
    virtual void Slot098_guess();
    virtual void Slot099_guess();
    virtual void Slot100_guess();
    virtual void Slot101_guess();
    virtual void Slot102_guess();
    virtual void Slot103_guess();
    virtual void Slot104_guess();
    virtual void Dispatch_guess(int count, int value, unsigned char flag);
    // EXTERNAL: TITANIUM 0x0059DD30 Target_guess::CanNotify_guess
    char CanNotify_guess();
    // EXTERNAL: TITANIUM 0x004E7703 Target_guess::FUN_004e7703_guess
    void FUN_004e7703_guess(int value);
};

struct Face_guess {
    unsigned char blue_0000_guess;
    unsigned char green_0001_guess;
    unsigned char red_0002_guess;
    unsigned char alpha_0003_guess;
};

#define CALLBACK_EMPTY_SLOT(n) virtual void Slot##n##_guess() = 0;
struct CallbackResult_guess {
    CALLBACK_EMPTY_SLOT(000) CALLBACK_EMPTY_SLOT(001) CALLBACK_EMPTY_SLOT(002) CALLBACK_EMPTY_SLOT(003)
    CALLBACK_EMPTY_SLOT(004) CALLBACK_EMPTY_SLOT(005) CALLBACK_EMPTY_SLOT(006) CALLBACK_EMPTY_SLOT(007)
    CALLBACK_EMPTY_SLOT(008) CALLBACK_EMPTY_SLOT(009) CALLBACK_EMPTY_SLOT(010) CALLBACK_EMPTY_SLOT(011)
    CALLBACK_EMPTY_SLOT(012) CALLBACK_EMPTY_SLOT(013) CALLBACK_EMPTY_SLOT(014) CALLBACK_EMPTY_SLOT(015)
    CALLBACK_EMPTY_SLOT(016) CALLBACK_EMPTY_SLOT(017) CALLBACK_EMPTY_SLOT(018) CALLBACK_EMPTY_SLOT(019)
    CALLBACK_EMPTY_SLOT(020) CALLBACK_EMPTY_SLOT(021) CALLBACK_EMPTY_SLOT(022) CALLBACK_EMPTY_SLOT(023)
    CALLBACK_EMPTY_SLOT(024) CALLBACK_EMPTY_SLOT(025) CALLBACK_EMPTY_SLOT(026) CALLBACK_EMPTY_SLOT(027)
    CALLBACK_EMPTY_SLOT(028) CALLBACK_EMPTY_SLOT(029) CALLBACK_EMPTY_SLOT(030) CALLBACK_EMPTY_SLOT(031)
    CALLBACK_EMPTY_SLOT(032) CALLBACK_EMPTY_SLOT(033) CALLBACK_EMPTY_SLOT(034) CALLBACK_EMPTY_SLOT(035)
    CALLBACK_EMPTY_SLOT(036) CALLBACK_EMPTY_SLOT(037) CALLBACK_EMPTY_SLOT(038) CALLBACK_EMPTY_SLOT(039)
    CALLBACK_EMPTY_SLOT(040) CALLBACK_EMPTY_SLOT(041) CALLBACK_EMPTY_SLOT(042) CALLBACK_EMPTY_SLOT(043)
    CALLBACK_EMPTY_SLOT(044) CALLBACK_EMPTY_SLOT(045) CALLBACK_EMPTY_SLOT(046) CALLBACK_EMPTY_SLOT(047)
    CALLBACK_EMPTY_SLOT(048)
    virtual void Slot049_guess(int value) = 0;
    CALLBACK_EMPTY_SLOT(050) CALLBACK_EMPTY_SLOT(051) CALLBACK_EMPTY_SLOT(052)
    virtual void Slot053_guess(Face_guess* face) = 0;
};

struct CallbackCallTarget_guess {
    CALLBACK_EMPTY_SLOT(000) CALLBACK_EMPTY_SLOT(001) CALLBACK_EMPTY_SLOT(002) CALLBACK_EMPTY_SLOT(003)
    CALLBACK_EMPTY_SLOT(004) CALLBACK_EMPTY_SLOT(005) CALLBACK_EMPTY_SLOT(006) CALLBACK_EMPTY_SLOT(007)
    CALLBACK_EMPTY_SLOT(008) CALLBACK_EMPTY_SLOT(009) CALLBACK_EMPTY_SLOT(010) CALLBACK_EMPTY_SLOT(011)
    CALLBACK_EMPTY_SLOT(012) CALLBACK_EMPTY_SLOT(013) CALLBACK_EMPTY_SLOT(014) CALLBACK_EMPTY_SLOT(015)
    CALLBACK_EMPTY_SLOT(016) CALLBACK_EMPTY_SLOT(017) CALLBACK_EMPTY_SLOT(018) CALLBACK_EMPTY_SLOT(019)
    CALLBACK_EMPTY_SLOT(020) CALLBACK_EMPTY_SLOT(021) CALLBACK_EMPTY_SLOT(022) CALLBACK_EMPTY_SLOT(023)
    CALLBACK_EMPTY_SLOT(024) CALLBACK_EMPTY_SLOT(025) CALLBACK_EMPTY_SLOT(026) CALLBACK_EMPTY_SLOT(027)
    CALLBACK_EMPTY_SLOT(028) CALLBACK_EMPTY_SLOT(029) CALLBACK_EMPTY_SLOT(030) CALLBACK_EMPTY_SLOT(031)
    CALLBACK_EMPTY_SLOT(032) CALLBACK_EMPTY_SLOT(033) CALLBACK_EMPTY_SLOT(034) CALLBACK_EMPTY_SLOT(035)
    CALLBACK_EMPTY_SLOT(036) CALLBACK_EMPTY_SLOT(037) CALLBACK_EMPTY_SLOT(038) CALLBACK_EMPTY_SLOT(039)
    CALLBACK_EMPTY_SLOT(040) CALLBACK_EMPTY_SLOT(041) CALLBACK_EMPTY_SLOT(042) CALLBACK_EMPTY_SLOT(043)
    CALLBACK_EMPTY_SLOT(044) CALLBACK_EMPTY_SLOT(045) CALLBACK_EMPTY_SLOT(046) CALLBACK_EMPTY_SLOT(047)
    CALLBACK_EMPTY_SLOT(048)
    virtual void Slot049_guess(int value) = 0;
};

struct CallbackGetter_guess {
    CALLBACK_EMPTY_SLOT(000) CALLBACK_EMPTY_SLOT(001) CALLBACK_EMPTY_SLOT(002) CALLBACK_EMPTY_SLOT(003)
    CALLBACK_EMPTY_SLOT(004) CALLBACK_EMPTY_SLOT(005) CALLBACK_EMPTY_SLOT(006) CALLBACK_EMPTY_SLOT(007)
    CALLBACK_EMPTY_SLOT(008) CALLBACK_EMPTY_SLOT(009) CALLBACK_EMPTY_SLOT(010) CALLBACK_EMPTY_SLOT(011)
    CALLBACK_EMPTY_SLOT(012) CALLBACK_EMPTY_SLOT(013) CALLBACK_EMPTY_SLOT(014) CALLBACK_EMPTY_SLOT(015)
    CALLBACK_EMPTY_SLOT(016) CALLBACK_EMPTY_SLOT(017) CALLBACK_EMPTY_SLOT(018) CALLBACK_EMPTY_SLOT(019)
    CALLBACK_EMPTY_SLOT(020) CALLBACK_EMPTY_SLOT(021) CALLBACK_EMPTY_SLOT(022) CALLBACK_EMPTY_SLOT(023)
    CALLBACK_EMPTY_SLOT(024) CALLBACK_EMPTY_SLOT(025) CALLBACK_EMPTY_SLOT(026) CALLBACK_EMPTY_SLOT(027)
    CALLBACK_EMPTY_SLOT(028) CALLBACK_EMPTY_SLOT(029) CALLBACK_EMPTY_SLOT(030) CALLBACK_EMPTY_SLOT(031)
    CALLBACK_EMPTY_SLOT(032) CALLBACK_EMPTY_SLOT(033) CALLBACK_EMPTY_SLOT(034) CALLBACK_EMPTY_SLOT(035)
    CALLBACK_EMPTY_SLOT(036) CALLBACK_EMPTY_SLOT(037) CALLBACK_EMPTY_SLOT(038) CALLBACK_EMPTY_SLOT(039)
    CALLBACK_EMPTY_SLOT(040) CALLBACK_EMPTY_SLOT(041) CALLBACK_EMPTY_SLOT(042) CALLBACK_EMPTY_SLOT(043)
    CALLBACK_EMPTY_SLOT(044) CALLBACK_EMPTY_SLOT(045) CALLBACK_EMPTY_SLOT(046) CALLBACK_EMPTY_SLOT(047)
    CALLBACK_EMPTY_SLOT(048) CALLBACK_EMPTY_SLOT(049) CALLBACK_EMPTY_SLOT(050) CALLBACK_EMPTY_SLOT(051)
    CALLBACK_EMPTY_SLOT(052) CALLBACK_EMPTY_SLOT(053) CALLBACK_EMPTY_SLOT(054) CALLBACK_EMPTY_SLOT(055)
    CALLBACK_EMPTY_SLOT(056) CALLBACK_EMPTY_SLOT(057) CALLBACK_EMPTY_SLOT(058) CALLBACK_EMPTY_SLOT(059)
    CALLBACK_EMPTY_SLOT(060) CALLBACK_EMPTY_SLOT(061) CALLBACK_EMPTY_SLOT(062) CALLBACK_EMPTY_SLOT(063)
    CALLBACK_EMPTY_SLOT(064) CALLBACK_EMPTY_SLOT(065) CALLBACK_EMPTY_SLOT(066) CALLBACK_EMPTY_SLOT(067)
    CALLBACK_EMPTY_SLOT(068) CALLBACK_EMPTY_SLOT(069) CALLBACK_EMPTY_SLOT(070) CALLBACK_EMPTY_SLOT(071)
    CALLBACK_EMPTY_SLOT(072) CALLBACK_EMPTY_SLOT(073) CALLBACK_EMPTY_SLOT(074) CALLBACK_EMPTY_SLOT(075)
    CALLBACK_EMPTY_SLOT(076) CALLBACK_EMPTY_SLOT(077) CALLBACK_EMPTY_SLOT(078) CALLBACK_EMPTY_SLOT(079)
    CALLBACK_EMPTY_SLOT(080) CALLBACK_EMPTY_SLOT(081) CALLBACK_EMPTY_SLOT(082) CALLBACK_EMPTY_SLOT(083)
    CALLBACK_EMPTY_SLOT(084) CALLBACK_EMPTY_SLOT(085)
    virtual CallbackResult_guess* Slot086_guess(int value) = 0;
};

struct CallbackSetDispatch_guess {
    virtual void Slot000_guess() = 0;
    virtual void Slot001_guess(int value) = 0;
};
#undef CALLBACK_EMPTY_SLOT

struct ChildState_guess {
    char pad_000_guess[0x34];
    char field_034_guess;
};

struct Dispatch_guess {
    // EXTERNAL: TITANIUM 0x0044AACB Dispatch_guess::Apply_guess
    void Apply_guess(int value, void* owner);
};

struct ActorInfoView_guess {
    Target_guess* target;
    // EXTERNAL: TITANIUM 0x0048F019 ActorInfoView_guess::FUN_0048f019_guess
    char FUN_0048f019_guess();
    char pad_004_guess[0x44];
    float floorHeight_0048_guess;
    char pad_04c_guess[0x50];
    unsigned char field_09c_guess;
    unsigned char field_09d_guess;
    char pad_09e_guess[0x0f];
    unsigned char field_0ad_guess;
    unsigned char feetEnvironment_00ae_guess;
    char pad_0af_guess[0x7d];
    ChildState_guess* actorDef_012c_guess;
    char pad_130_guess[4];
    int currentAnimation_0134_guess;
    char pad_138_guess[0x24];
    int mount_015c_guess;
    void* rider_0160_guess;
    char pad_164_guess[0x50];
    Dispatch_guess* loopSoundEmitter_01b4_guess;
    char pad_1b8_guess[0xd0c];
    float sneakMod_0ec4_guess;
    char pad_ec8_guess[0x58];
    int field_f20_guess;
    char pad_f24_guess[0x48];
    int currentLoopSound_0f6c_guess;
    char pad_f70_guess[8];
    int primaryItemType_0f78_guess;
    int secondaryItemType_0f7c_guess;
    int primaryModelId_0f80_guess;
    int secondaryModelId_0f84_guess;
    char pad_f88_guess[4];
    char field_f8c_guess;
    char pad_f8d_guess[0x0b];
    int castingSpellId_0f98_guess;
    char pad_f9c_guess[0x0c];
    int field_fa8_guess;
    int field_fac_guess;
    int values[10];
};

struct HandlerState_guess {
    char pad[0x106c];
    int field_106c_guess;
    char pad_1070_guess[4];
    int field_1074_guess;
};

struct FlagSet_guess {
    char pad[0x294];
    unsigned int flags_guess;
    void AddPlayerState_guess(unsigned int value);
    void RemovePlayerState_guess(unsigned int value);
    char HasPlayerState_guess(unsigned int value);
};

struct FlagProxy_guess {
    // EXTERNAL: TITANIUM 0x0047C007 FlagProxy_guess::HasPlayerState_guess
    char HasPlayerState_guess(unsigned int value);
};

struct Accessor_guess {
    char pad[0x160];
    char field_160_guess;
    char* At160_guess();
};

struct ActorDefName_guess {
    char pad_000_guess[8];
    char name_008_guess[1];
};

struct ActorDefInfo_guess {
    char pad_000_guess[0x12c];
    ActorDefName_guess* actorDef_012c_guess;
    char pad_130_guess[0xdf0];
    int field_f20_guess;
    int field_f24_guess;
    int field_f28_guess;
    int field_f2c_guess;
    int field_f30_guess;
    int field_f34_guess;
    int field_f38_guess;
    int field_f3c_guess;
    int field_f40_guess;
    int field_f44_guess;
    int field_f48_guess;
    int field_f4c_guess;
    int field_f50_guess;
    int field_f54_guess;
    int field_f58_guess;
    int field_f5c_guess;
    int field_f60_guess;
    int field_f64_guess;
    char pad_f68_guess[8];
    int field_f70_guess;
};

struct ActorStatus_guess {
    char pad_000_guess[0x22];
    unsigned char type_022_guess;
    unsigned char state_023_guess;
    char pad_024_guess[0x42];
    short value_066_guess;
    char pad_068_guess[0x3c];
    int value_0a4_guess;
    char pad_0a8_guess[0xc];
    int value_0b4_guess;
    unsigned char flag_0b8_guess;
    // EXTERNAL: TITANIUM 0x004903F1 ActorStatus_guess::FUN_004903f1_guess
    char FUN_004903f1_guess();
    // EXTERNAL: TITANIUM 0x0048FAA5 ActorStatus_guess::RepopFrequency_guess
    unsigned int RepopFrequency_guess();
    // EXTERNAL: TITANIUM 0x0048FBC8 ActorStatus_guess::GetSwitchDamage_guess
    int GetSwitchDamage_guess();
    // EXTERNAL: TITANIUM 0x004906C5 ActorStatus_guess::UseSwitch_guess
    void UseSwitch_guess(unsigned int spawnId, unsigned int value, int zero, int secondZero);
};

#define g_lastActorStatus_guess EQ_GLOBAL(ActorStatus_guess*, 0x00903E5C)

struct ProfileText_guess;

struct QueryValue_guess {
    char pad_000_guess[0x88];
    ProfileText_guess* object_088_guess;
};

struct EQ_CharacterProfileView_guess {
    char pad_000_guess[4];
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    QueryValue_guess* GetCharInfo2();
};

struct QueryResult_guess {
    char pad_000_guess[8];
    struct QueryHeader_guess* header_008_guess;
};

struct QueryHeader_guess {
    char pad_000_guess[4];
    int offset_004_guess;
};

#pragma pack(push, 1)
struct ActorMessage_guess {
    unsigned short spawnId_000_guess;
    unsigned short zero_002_guess;
    unsigned short size_004_guess;
    int message_006_guess;
    float zero_00a_guess;
    float zero_00e_guess;
    float zero_012_guess;
    unsigned char type_016_guess;
    unsigned short zero_017_guess;
    unsigned short size_019_guess;
    unsigned short state_01b_guess;
    unsigned char zero_01d_guess;
    unsigned char zero_01e_guess;
    unsigned char pad_01f_guess;
};
#pragma pack(pop)

struct ResourceLookup_guess {
    // EXTERNAL: TITANIUM 0x0048F54D ResourceLookup_guess::GetRaceValue_guess
    int GetRaceValue_guess(int type, int race, int index);
};

struct EffectPack_guess {
    float values_guess[10];
    int flags_guess;
    // EXTERNAL: TITANIUM 0x004C5C39 EffectPack_guess::Initialize_guess
    void Initialize_guess();
};

struct ResourceUser_guess {
    // EXTERNAL: TITANIUM 0x0044BEA0 ResourceUser_guess::WaveLoadById_guess
    void WaveLoadById_guess(int resource, int flag);
    // EXTERNAL: TITANIUM 0x0044A537 ResourceUser_guess::Apply_guess
    void Apply_guess(int value, EffectPack_guess* pack);
    // EXTERNAL: TITANIUM 0x0044A591 ResourceUser_guess::WaveStop_guess
    void WaveStop_guess(int value);
    // EXTERNAL: TITANIUM 0x0044A617 ResourceUser_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int first, int second);
};

#define g_resourceLookup_guess EQ_GLOBAL(ResourceLookup_guess*, 0x00903E80)
#define g_resourceUser_guess EQ_GLOBAL(ResourceUser_guess*, 0x00851390)

struct EQPlayerRaceView_guess {
    char pad_000_guess[0x1a8];
    ActorDefInfo_guess* pActorInfo_01a8_guess;
    char pad_1ac_guess[0x0a];
    unsigned char field_1b6_guess;
    char pad_1b7_guess[0x96];
    unsigned char faceHair_024d_guess;
    unsigned char gender_024e_guess;
    char pad_24f_guess[0x11];
    int race_0260_guess;
    char pad_264_guess[0x40];
    char text_2a4_guess[0x20];
    char GetBeardKind_guess();
    void GetHairColorRange_guess(int value, int* first, int* second);
    int CanHaveNoHair_guess();
    bool IsHorseRace_guess();
    void SetSounds_guess();
    char IsHorseUsingHumanModel_guess();
    bool FUN_0047cf40_guess();
    void SetRace_guess(int value);
    void SetTitle_guess(const char* text);
};

struct Display_guess {
    char pad_000_guess[0x84];
    int field_84_guess;
    char pad_088_guess[0x14];
    bool field_9c_guess;
    char pad_09d_guess[0x10];
    unsigned char field_ad_guess;
    unsigned char field_ae_guess;
    unsigned char field_af_guess;
    char pad_0b0_guess[0xbc];
    int field_16c_guess;
};

struct EQPlayerStatusView_guess {
    char pad_000_guess[0x1a8];
    Display_guess* pActorInfo_01a8_guess;
    char pad_1ac_guess[0x98];
    unsigned char type_0244_guess;
    char pad_245_guess[0x1b];
    int race_0260_guess;
    char pad_264_guess[0x28];
    int levitate_028c_guess;
    void SetRegionType_guess(unsigned char value);
    void SetLevitate_guess(int value);
    bool Check_guess(int value);
    unsigned int FindFreeIndex_guess();
    int GetField16c_guess();
};

#define g_statusCode_guess EQ_GLOBAL(int, 0x00924470)
#define g_statusCursor_guess EQ_GLOBAL(unsigned int, 0x0078D854)

struct TableOwner_guess {
    char pad_000_guess[0x258];
    unsigned int field_258_guess;
    void SetSpawnId_guess(unsigned int index);
    void ClearTable_guess();
};

struct SearchNode_guess {
    char pad_000_guess[0x30];
    float field_030_guess;
    float field_034_guess;
    float field_038_guess;
    char pad_03c_guess[0xe4];
    char field_120_guess;
    char text_121_guess[0x87];
    int* field_1a8_guess;
    char pad_1ac_guess[0x68];
    SearchNode_guess* next_214_guess;
    char pad_218_guess[0x2c];
    unsigned char field_244_guess;
};

struct Position_guess {
    char pad_000_guess[0x30];
    float field_030_guess;
    float field_034_guess;
    float field_038_guess;
};

#define g_searchList_guess EQ_GLOBAL(SearchNode_guess*, 0x00905CC4)

#define g_walkCounter_guess EQ_GLOBAL(int, 0x00903E54)

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
int __cdecl FUN_00401b28_guess(int value);

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* text);

// EXTERNAL: TITANIUM 0x00464A48 MakeNPCCorpseName_guess
void __cdecl MakeNPCCorpseName_guess(unsigned int playerClass, char* name, int value);

// EXTERNAL: TITANIUM 0x004912B1 FUN_004912b1_guess
void __cdecl FUN_004912b1_guess(const char* category, int message, const int* data, int size, int flag);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, unsigned int id_guess,
    const char* text_guess, int zero1_guess, int zero2_guess, int zero3_guess,
    int zero4_guess, int zero5_guess, int zero6_guess, int zero7_guess,
    int zero8_guess);

struct SendState_guess {
    char pad_000_guess[0x20c];
    int values_guess[2];
    char pad_214_guess[0x3c];
    char field_250_guess;
    char pad_251_guess[7];
    int SpawnID;
    void Send_guess(int index, int value, char logFlag);
    void SetHideMode_guess(char value);
};

struct FloatOwner_guess {
    char pad[0x240];
    float field_240_guess;
    float GetWalkSpeed_guess();
};

struct FloatSource_guess {
    char pad_000_guess[0xc4];
    float value_0c4_guess;
};

struct FloatScaleOwner_guess {
    char pad_000_guess[0x1a0];
    float value_1a0_guess;
    char pad_1a4_guess[4];
    FloatSource_guess* source_1a8_guess;
    float FUN_0047c2d4_guess();
};

struct OffsetLink_guess {
    char pad_000_guess[4];
    OffsetLink_guess* next_004_guess;
};

struct DispatchTarget_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual int Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual int Slot016_guess();
};

struct EQPlayerPcView_guess {
    char pad_000_guess[0x1bc];
    int values_1bc_guess[9];
    char pad_1e0_guess[0x38];
    int value_218_guess;
    char pad_21c_guess[0x28];
    unsigned char field_244_guess;
    int GetPcClient_guess();
    int FUN_0047c31a_guess();
    int IsLevitating_guess();
    int GetArmorTint_guess(int index);
    // EXTERNAL: TITANIUM 0x00479EE8 EQPlayerPcView_guess::PlaySound_guess
    void PlaySound_guess(int value);
    void IHaveFallen_guess(float value);
};

#include "titanium/layouts/core.h"


struct SpellState_guess {
    char pad_000_guess[0x48];
    int count_048_guess;
    // EXTERNAL: TITANIUM 0x005ECC00 SpellState_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 SpellState_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC850 SpellState_guess::Check_guess
    int Check_guess(int value);
};

struct Record_guess {
    char pad_000_guess[0x2c];
    SpellState_guess* first_02c_guess;
    char pad_030_guess[0x24];
    SpellState_guess* second_054_guess;
};

struct RecordSlot_guess {
    char pad_000_guess[4];
    EQ_CharacterProfileView_guess accessor_guess;
    Record_guess* GetSelected_guess() {
        int* words_guess = (int*)accessor_guess.GetCharInfo2();
        words_guess += 4;
        return (Record_guess*)words_guess;
    }
};

struct RecordObject_guess {
    char pad_000_guess[8];
    union {
        VBPtr lookup_008_guess;
        RecordSlot_guess slots_008_guess[16];
    };
    RecordSlot_guess* CurrentSlot_guess() {
        int index_guess = lookup_008_guess.table->vbase_offset
            / (int)sizeof(RecordSlot_guess);
        return &slots_008_guess[index_guess];
    }
};

struct ResultCheck_guess {
    // EXTERNAL: TITANIUM 0x0043DA4A ResultCheck_guess::FUN_0043da4a_guess
    int FUN_0043da4a_guess(int index);
};

struct Command_guess {
    // EXTERNAL: TITANIUM 0x004106A3 Command_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int type, int first, int second, int third);
    // EXTERNAL: TITANIUM 0x00420DEC Command_guess::TakeFallDamage_guess
    int TakeFallDamage_guess(float value);
};

struct ResultOwner_guess {
    char pad_000_guess[0xc280];
    Command_guess command_guess;
};

struct PlayerCtx_guess;
struct AttackState_guess;
struct HeadingResult_guess {
    char pad_000_guess[0x2c];
    float field_02c_guess;
    float field_030_guess;
    char pad_034_guess[8];
    float field_03c_guess;
};

struct EQPlayerCore_guess {
    char pad_000_guess[0x30];
    float y_0030_guess;
    float x_0034_guess;
    float z_0038_guess;
    float velocityY_003c_guess;
    float velocityX_0040_guess;
    float velocityZ_0044_guess;
    float speedRun_0048_guess;
    float heading_004c_guess;
    char pad_050_guess[0x0c];
    float pitch_005c_guess;
    char pad_060_guess[0xc0];
    char name_0120_guess;
    char pad_121_guess[0x3f];
    char text_160_guess[0x40];
    char pad_1a0_guess[8];
    ActorInfoView_guess* handler;
    // EXTERNAL: TITANIUM 0x0048A0FC EQPlayerCore_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float x, float y, float z, int flag);
    // EXTERNAL: TITANIUM 0x0048A945 EQPlayerCore_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
    void SetDisplayedName_guess(const char* value);
    int AimAtTarget_guess(EQPlayerCore_guess* other, HeadingResult_guess* output);
    void FacePlayer_guess(EQPlayerCore_guess* other);
    bool FUN_00479396_guess();
    char FUN_0047a387_guess();
    void FUN_0047a3b3_guess(int value);
    void FindDefaultEyeMaterialIndexes_guess();
    void UpdateDAGPointers_guess();
    void SpurtBloodOnDag_guess();
    int SetEyeColor_guess(char flag, int value);
    int GetRaceOffsetForAttachmentITs_guess();
    int SwapHairBeardIT_guess(int value);
    int GetArmorAttachSlot_guess(int kind, int flags);
    unsigned char GetBaseFaceNbr_guess(int value, unsigned char* output);
    int IsPathClear_guess(float x_guess, float y_guess, float z_guess, float angle_guess,
                           float length_guess);
    char pad_1ac_guess[0x38];
    int field_1e4_guess;
    char pad_1e8_guess[0x30];
    PlayerCtx_guess* pCharInfo_0218_guess;
    char pad_21c_guess[0x1c];
    float heightOffset_0238_guess;
    float avatarHeight_023c_guess;
    char pad_240_guess[4];
    unsigned char type_0244_guess;
    unsigned char hairColor_0245_guess;
    unsigned char beardColor_0246_guess;
    unsigned char eyeColor1_0247_guess;
    unsigned char eyeColor_0248_guess;
    unsigned char field_249_guess;
    unsigned char field_24a_guess;
    unsigned char holding_024b_guess;
    unsigned char level_024c_guess;
    unsigned char faceHair_024d_guess;
    unsigned char gender_024e_guess;
    char pad_24f_guess[2];
    char standState_0251_guess;
    unsigned char playerClass_0252_guess;
    char pad_253_guess[3];
    unsigned char gm_0256_guess;
    char pad_257_guess[1];
    int spawnId_0258_guess;
    int masterId_025c_guess;
    int race_0260_guess;
    char pad_264_guess[0x1c];
    int deity_0280_guess;
    int NotOnSameDeity_guess(EQPlayerCore_guess* other, int flag);
    void PlaceOnFloor_guess();
    int GetAttachedHelmITNum_guess(int value, int* flag);
    void FUN_0047b8d5_guess(int value);
    int SetPlayerPitchType_guess();
    void InitSneakMod_guess();
    float ScaleFromSize_guess(float value);
    float GetDefaultSizeForRace_guess(int race, char gender);
    char CanFitIllusionRace_guess(int race, unsigned int state, float value);
    void SetAnimVariation_guess();
    int GetTopMasterID_guess();
    void GetActorTag_guess(char* output);
    int FUN_0047bc52_guess();
    int FUN_0047bc8e_guess(int unused, int value);
    char FUN_0047bf6c_guess(int value, float* output);
    char IsGroupInvitePending_guess();
    void SetGroupInvitePending_guess(int value);
    void PlaySound_guess(int value);
    void SetCurrentLoopSound_guess(int value);
    char FUN_0047a018_guess();
    void PlayLevelAppearance_guess(Input_guess* input);
    void InitSpellPoints_guess();
    bool SwapHairStyle_guess(int head);
    bool SwapBeardStyle_guess(int head);
    char SetAttachmentTint_guess(int value, Face_guess* face);
    void ModifyHandToHandDelay_guess(int* value, int object);
    void feetEnvironmentChange_guess(unsigned char state);
    void RemoveFromEffectList_guess();
    int LegalPlayerRace_guess(int race);
    char GetHairKind_guess();
    // EXTERNAL: TITANIUM 0x0047DEC4 EQPlayerCore_guess::SwapFace_guess
    void SwapFace_guess(int value, int old_value);
    void SetDefaultFacialFeaturesByFace_guess(int value, int flags, char commit);
    char CanPcUseSkill_guess(int value, int index);
    int DoAttack(unsigned char kind, unsigned char skill, int target);
    char CanAttack_guess(int target);
    char CanIHit_guess(int target, float bonus);
    unsigned int ModifyAttackSpeed_guess(int delay, int ranged);
    // EXTERNAL: TITANIUM 0x00481B3A EQPlayerCore_guess::FireRangedItem_guess
    void FireRangedItem_guess(int target);
    AttackState_guess* Attack_guess() { return (AttackState_guess*)handler; }
};

struct ContextQuery_guess {
    // EXTERNAL: TITANIUM 0x005E0F30 ContextQuery_guess::GetItemId_guess
    int GetItemId_guess();
};

struct ProcessNodeLink_guess {
    char pad_000_guess[0xfe8];
    unsigned int owner_0fe8_guess;
};

struct ProcessNode_guess {
    char pad_000_guess[8];
    ProcessNode_guess* next_008_guess;
    char pad_00c_guess[0x3c];
    ProcessNodeLink_guess* link_048_guess;
    int field_04c_guess;
    int field_050_guess;
    // EXTERNAL: TITANIUM 0x0047789D ProcessNode_guess::MissileTeardown_guess
    void MissileTeardown_guess();
};

#define g_processList_guess EQ_GLOBAL(ProcessNode_guess*, 0x00905CD0)

struct Notify_guess {
    // EXTERNAL: TITANIUM 0x0050C661 Notify_guess::Set_guess
    void Set_guess(int value);
};

struct Refresh_guess {
    // EXTERNAL: TITANIUM 0x00564E7E Refresh_guess::Update_guess
    void Update_guess(int type, int value);
};

#define pinstCGroupWnd_guess EQ_GLOBAL(Notify_guess*, 0x00991A74)
#define g_ownerState_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_field923c30_guess EQ_GLOBAL(int, 0x00923C30)

struct Attachment_guess;

struct Display2_guess {
    char pad_000[0x128];
    unsigned char field_128;
    unsigned char field_129;
    char pad_12a[0x1e];
    unsigned int frameTime_0148_guess;
    char pad_14c[4];
    int field_150;
    char pad_154[0x2d58 - 0x154];
    int field_2d58_guess;
    char pad_2d5c[1];
    unsigned char field_2d5d_guess;
    unsigned char field_2d5e_guess;
    // EXTERNAL: TITANIUM 0x00438EBC Display2_guess::SetActorScale_guess
    void SetActorScale_guess(void* object, float value, int flag);
    // EXTERNAL: TITANIUM 0x00438FDF Display2_guess::UpdateSoundEnvironment_guess
    void UpdateSoundEnvironment_guess();
    // EXTERNAL: TITANIUM 0x00438FC2 Display2_guess::FUN_00438fc2_guess
    void FUN_00438fc2_guess(int value);
    // EXTERNAL: TITANIUM 0x0043C84B Display2_guess::AddPlayer_guess
    void AddPlayer_guess(void* player);
    // EXTERNAL: TITANIUM 0x00439F26 Display2_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float y, float x, float z);
    // EXTERNAL: TITANIUM 0x00439E0F Display2_guess::SetViewActorByName_guess
    void SetViewActorByName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x00437464 Display2_guess::FUN_00437464_guess
    int FUN_00437464_guess();
    // EXTERNAL: TITANIUM 0x00439A46 Display2_guess::DeleteActor_guess
    void DeleteActor_guess(void* object);
    // EXTERNAL: TITANIUM 0x0043A0A0 Display2_guess::GetCeilingHeight_guess
    float GetCeilingHeight_guess(float y, float x, float z, float step);
    // EXTERNAL: TITANIUM 0x0043745D Display2_guess::FUN_0043745d_guess
    int FUN_0043745d_guess();
    // EXTERNAL: TITANIUM 0x004395C4 Display2_guess::DeleteLight_guess
    void DeleteLight_guess(void* object);
    // EXTERNAL: TITANIUM 0x00439377 Display2_guess::CreateLightInstance_guess
    Attachment_guess* CreateLightInstance_guess(float light, int zero, float x, float y, float z);
};

#define g_display2_guess EQ_GLOBAL(Display2_guess*, 0x00905D24)

struct ScaleProvider_guess {
    // EXTERNAL: TITANIUM 0x004B6D42 ScaleProvider_guess::GetROffset_guess
    float GetROffset_guess();
};

// EXTERNAL: TITANIUM 0x004B6CB4 FUN_004b6cb4_guess
ScaleProvider_guess* __stdcall FUN_004b6cb4_guess(char* name);

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float first_guess, float second_guess, float third_guess, float fourth_guess);

// EXTERNAL: TITANIUM 0x00476167 CastRay
int __cdecl CastRay(void* object, float first, float second, float third);

// EXTERNAL: TITANIUM 0x0046595A get_melee_range
float __cdecl get_melee_range(void* first, void* second);

// EXTERNAL: TITANIUM 0x0046591B get_range_squared_guess
float __cdecl get_range_squared_guess(void* first, void* second);

// EXTERNAL: TITANIUM 0x0048C879 GetRaceModelTag_guess
void __cdecl GetRaceModelTag_guess(char* output, int type, int state);

// EXTERNAL: TITANIUM 0x004649B1 token_string_to_client_guess
void __cdecl token_string_to_client_guess(void* ctx, int textId, int color, int flag);

#include <stdio.h>
#include "titanium/wnd/CBazaarSearchWnd.h"
#include "titanium/wnd/CTipWnd.h"

struct EQPlayerArmorView_guess {
    char pad[0x1bc];
    int values_1bc_guess[9];
    int values_1e0_guess[9];
    int GetArmorType_guess(int index);
    void SetArmorType_guess(int index, int value);
    void SetArmorTint_guess(int index, int value);
};

struct InitBase_guess {
    int value_004_guess;
    unsigned char flag_008_guess;
    char pad_009_guess[3];
    InitBase_guess() : flag_008_guess(0) {}
};

// EXTERNAL: TITANIUM 0x006481F0 ??_7PlayerAnimation_guess@@6B@
struct PlayerAnimation_guess : InitBase_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void SetModeOverride_guess(unsigned char flag, int value);
    int field_00c_guess;
    int field_010_guess;
    char pad_014_guess[4];
    unsigned char modeOverrideActive_0018_guess;
    char pad_019_guess[3];
    int modeOverride_001c_guess;
    PlayerAnimation_guess(int value);
    int PickRandomVariant_guess(int tableIndex, int recordIndex);
    float GetAnimBlendTime_guess(int first, int second);
    int RemapAnimationKey_guess(int key, int recordIndex);
    int SelectMode_guess(int key);
};

struct StringMatcher_guess {
    char pad_000_guess[5];
    char entries_005_guess[5][0x40];
    char pad_145_guess[0x17];
    char primary_15c_guess[0x40];
    bool MatchesAnyName_guess(const char* value);
};

// Race 403 or 405 and up: probably the newer model set, which gets its own size scale and walk speed.
// FUNCTION: TITANIUM 0x0047937C
char __cdecl FUN_0047937c_guess(unsigned int value) {
    if (value != 0x193 && value < 0x195) {
        return 0;
    }
    return 1;
}

// Whether actor info +0x106C or +0x1074 is set; the name sprite adds strings 0x157F / 0x17A7 for them
// and gives such PCs their own name colour.
// FUNCTION: TITANIUM 0x00479396
bool EQPlayerCore_guess::FUN_00479396_guess() {
    HandlerState_guess* state = (HandlerState_guess*)handler;
    bool result = false;
    if (state != 0) {
        if (state->field_1074_guess != 0 || state->field_106c_guess != 0) {
            result = true;
        }
    }
    return result;
}

// The spawn's displayed name (+0x160).
// FUNCTION: TITANIUM 0x004793B5
char* Accessor_guess::At160_guess() {
    return &field_160_guess;
}

// Display form of `value` in DisplayedName (+0x160): stops at an apostrophe, drops digits and '#',
// turns '_' into spaces ("a_rat01" becomes "a rat").
// FUNCTION: TITANIUM 0x004793BC
void EQPlayerCore_guess::SetDisplayedName_guess(const char* value) {
    char source[64];
    char transformed[0x21000];
    FUN_0060e450_guess(source, value);
    strlen(source);
    char* destination = transformed;
    char* cursor = source;
    if (source[0] != 0) {
        do {
            if (*cursor == '\'') {
                break;
            }
            int character;
            unsigned int length = FUN_00574510_guess(cursor, &character);
            if (!_iswdigit(character) && (short)character != '#') {
                if ((short)character == '_') {
                    *destination = ' ';
                    ++destination;
                } else {
                    memcpy(destination, cursor, length);
                    destination += length;
                }
            }
            cursor += length;
        } while (*cursor != 0);
    }
    *destination = 0;
    ConvertNameToLocal_guess(transformed);
    FUN_0060e450_guess(text_160_guess, transformed);
}

// Turns this spawn to face `other`: heading (+0x4C) becomes the bearing from its own x/y (+0x30, +0x34) to
// the other spawn's.
// FUNCTION: TITANIUM 0x004797D5
void EQPlayerCore_guess::FacePlayer_guess(EQPlayerCore_guess* other) {
    float otherY = other->x_0034_guess;
    float otherX = other->y_0030_guess;
    float y = x_0034_guess;
    float x = y_0030_guess;
    heading_004c_guess = get_bearing_guess(x, y, otherX, otherY);
}

// The spawn whose actor (pActorInfo +0) is `value`, or 0: is_player_actor (Mac name) in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x004798B7
SearchNode_guess* __cdecl FindSpawnByActor_guess(int value) {
    SearchNode_guess* node = g_searchList_guess;
    while (node != 0 && *node->field_1a8_guess != value) {
        node = node->next_214_guess;
    }
    return node;
}

// Model tag for the race and gender (HUM, HUF...), the prefix of every actor, DAG and texture name; race 71
// with gender 2 is forced to 0. EQPlayer::GetActorTag in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x004798D7
void EQPlayerCore_guess::GetActorTag_guess(char* output) {
    if (race_0260_guess == 0x47 && gender_024e_guess == 2) {
        gender_024e_guess = 0;
    }
    GetRaceModelTag_guess(output, race_0260_guess, gender_024e_guess);
}

// Deity alliance: 1 good (204, 208, 210, 212, 215), 2 neutral (202, 205, 207, 209, 213, 214, 216),
// 3 evil (201, 203, 206, 211), 0 for anything else (agnostic is 396).
// FUNCTION: TITANIUM 0x00479908
int __cdecl WhatDeityAlliance_guess(int value) {
    int result;
    switch (value) {
    case 0xcc:
    case 0xd0:
    case 0xd2:
    case 0xd4:
    case 0xd7:
        return 1;
    case 0xca:
    case 0xcd:
    case 0xcf:
    case 0xd1:
    case 0xd5:
    case 0xd6:
    case 0xd8:
        result = 2;
        break;
    case 0xc9:
    case 0xcb:
    case 0xce:
    case 0xd3:
        result = 3;
        break;
    default:
        return 0;
    }
    return result;
}

// 1 when the two deities fall in different alliances (WhatDeityAlliance_guess groups); 0 when either is
// unaligned, and for a GM `other` unless `flag`. AllowedToAttack_guess uses it under PvP ruleset 4.
// FUNCTION: TITANIUM 0x0047994F
// @early-stop: budget, structural ndiff=21
int EQPlayerCore_guess::NotOnSameDeity_guess(EQPlayerCore_guess* other, int flag) {
    int type;
    if (this != 0) {
        if (other != 0 && other->gm_0256_guess != 0 && flag == 0) {
            return 0;
        }
        type = deity_0280_guess;
    } else {
        type = 0;
    }
    int otherType;
    if (other != 0) {
        otherType = other->deity_0280_guess;
    } else {
        otherType = 0;
    }
    bool same;
    switch (type) {
    case 0xcc:
    case 0xd0:
    case 0xd2:
    case 0xd4:
    case 0xd7:
        if (otherType == 0xcc || otherType == 0xd0 || otherType == 0xd4 ||
            otherType == 0xd2) {
            return 0;
        }
        same = otherType == 0xd7;
        break;
    case 0xca:
    case 0xcd:
    case 0xcf:
    case 0xd1:
    case 0xd5:
    case 0xd6:
    case 0xd8:
        if (otherType == 0xca || otherType == 0xcd || otherType == 0xcf ||
            otherType == 0xd1 || otherType == 0xd5 || otherType == 0xd6) {
            return 0;
        }
        same = otherType == 0xd8;
        break;
    case 0xc9:
    case 0xcb:
    case 0xce:
    case 0xd3:
        if (otherType == 0xc9 || otherType == 0xcb || otherType == 0xce) {
            return 0;
        }
        same = otherType == 0xd3;
        break;
    default:
        return 0;
    }
    if (!same) {
        return 1;
    }
    return 0;
}

// Holding (+0x24B), the stance picked from the item types in hand (actor +0xF78 primary, +0xF7C secondary);
// only for models whose actor definition has +0x34 set.
// FUNCTION: TITANIUM 0x00479A3A
void EQPlayerCore_guess::SetAnimVariation_guess() {
    ActorInfoView_guess* h = handler;
    holding_024b_guess = 0;
    if (h->actorDef_012c_guess != 0 && h->actorDef_012c_guess->field_034_guess != 0) {
        if (h->secondaryItemType_0f7c_guess != 0) {
            if (h->primaryItemType_0f78_guess != 0) {
                holding_024b_guess = 3;
                return;
            }
            if (h->secondaryItemType_0f7c_guess == 4) {
                holding_024b_guess = 7;
                return;
            }
            holding_024b_guess = h->secondaryItemType_0f7c_guess == 3 ? 2 : 5;
        } else {
            switch (h->primaryItemType_0f78_guess) {
            case 0:
                return;
            case 1:
                holding_024b_guess = 4;
                return;
            default:
                holding_024b_guess = 1;
                return;
            }
        }
    }
}

// Follows MasterID (+0x25C) up to 5 owners deep; 0 when this has no master. The depth counter is the
// global 0x903E54, reset on return.
// FUNCTION: TITANIUM 0x00479AB0
int EQPlayerCore_guess::GetTopMasterID_guess() {
    EQPlayerCore_guess* current = this;
    int count = g_walkCounter_guess;
    int value;
    EQPlayerCore_guess* next;
    do {
        value = current->spawnId_0258_guess;
        if (++count >= 6) {
            break;
        }
        next = (EQPlayerCore_guess*)FUN_00401b28_guess(current->masterId_025c_guess);
        if (next == 0 || next->spawnId_0258_guess == value) {
            break;
        }
        current = next;
    } while (current != 0);
    if (count == 1) {
        value = 0;
    }
    g_walkCounter_guess = 0;
    return value;
}

// Monk (class 7) and beastlord (15) hand-to-hand delay. Above level 26 a monk loses 100 per 4 levels
// (6 for an Iksar PC), at most 1000; from 61 the delay is fixed at 2400, 2200, then 2000 (+100 Iksar).
// Beastlords lose 100 per 5 levels.
// FUNCTION: TITANIUM 0x00479C78
void EQPlayerCore_guess::ModifyHandToHandDelay_guess(int* value, int object) {
    if (playerClass_0252_guess == 7 && level_024c_guess > 0x1a) {
        int amount = ((level_024c_guess - 0x18) / 4) * 100;
        if (race_0260_guess == 0x80 && type_0244_guess == 0) {
            amount = ((level_024c_guess - 0x18) / 6) * 100;
        }
        if (amount > 1000) {
            amount = 1000;
        }
        *value -= amount;
        if (level_024c_guess > 0x3c) {
            *value = 0x960;
            if (level_024c_guess > 0x3d) {
                *value = 0x898;
            }
            if (level_024c_guess > 0x3e) {
                *value = 0x7d0;
            }
            if (race_0260_guess == 0x80 && type_0244_guess == 0) {
                *value += 100;
            }
        }
        if (object != 0) {
            // Item 10652 in the hands slot gives 1600 above level 50; probably the monk epic.
            if (((ContextQuery_guess*)object)->GetItemId_guess() == 0x299c && level_024c_guess > 0x32) {
                *value = 0x640;
            }
        }
    }
    if (playerClass_0252_guess == 0xf && level_024c_guess > 0x1a) {
        int amount = ((level_024c_guess - 0x18) / 5) * 100;
        if (amount > 1000) {
            amount = 1000;
        }
        *value -= amount;
    }
}

// True when the spawn is not race 367 and its model data (actor info +0x12C) has no armour parts (+0x34
// clear).
// FUNCTION: TITANIUM 0x0047A387
char EQPlayerCore_guess::FUN_0047a387_guess() {
    if (race_0260_guess != 0x16f && handler != 0 &&
        handler->actorDef_012c_guess != 0 &&
        handler->actorDef_012c_guess->field_034_guess == 0) {
        return 1;
    }
    return 0;
}

// Passes `value` to the actor's model virtual at slot 6, when there is a model.
// FUNCTION: TITANIUM 0x0047A3B3
void EQPlayerCore_guess::FUN_0047a3b3_guess(int value) {
    if (handler != 0 && handler->target != 0) {
        handler->target->Slot006_guess(value);
    }
}

// Material per wear slot 0-8 (head, chest, arms, wrist, hands, legs, feet, primary, secondary) at +0x1E0.
// SetArmorType_guess writes it; SetArmorTint_guess keeps the tints at +0x1BC.
// FUNCTION: TITANIUM 0x0047A3D0
int EQPlayerArmorView_guess::GetArmorType_guess(int index) {
    int result;
    if (index < 0 || index > 8) {
        result = 0;
    } else {
        result = values_1e0_guess[index];
    }
    return result;
}

// Sets the armour type of equipment slot `index` (0-8, +0x1E0); other indexes are ignored.
// FUNCTION: TITANIUM 0x0047A3EB
void EQPlayerArmorView_guess::SetArmorType_guess(int index, int value) {
    if (index >= 0 && index <= 8) {
        values_1e0_guess[index] = value;
    }
}

// Sets the armour tint of equipment slot `index` (0-8, +0x1BC); other indexes are ignored.
// FUNCTION: TITANIUM 0x0047A406
void EQPlayerArmorView_guess::SetArmorTint_guess(int index, int value) {
    if (index >= 0 && index <= 8) {
        values_1bc_guess[index] = value;
    }
}

#define g_smoothStep_guess EQ_GLOBAL(float, 0x00924858)

struct SmoothTarget_guess {
    char pad_000_guess[0x160];
    int field_160_guess;
};

struct SmoothValue_guess {
    char pad_000_guess[0x48];
    float field_048_guess;
    char pad_04c_guess[0x15c];
    SmoothTarget_guess* field_1a8_guess;
    void SetTarget_guess(float target, int immediate);
};

// Eases +0x48 toward `target` (up 0.02, down 0.03 times the frame step 0x924858) while the linked
// object's +0x160 is set; otherwise, or with `immediate`, jumps.
// FUNCTION: TITANIUM 0x0047A421
void SmoothValue_guess::SetTarget_guess(float target, int immediate) {
    if (field_048_guess == target) {
        return;
    }
    if (immediate == 0 && field_1a8_guess != 0 && field_1a8_guess->field_160_guess != 0) {
        if (target > field_048_guess) {
            field_048_guess = g_smoothStep_guess * 0.02f + field_048_guess;
            if (!(field_048_guess > target)) {
                return;
            }
        } else {
            field_048_guess = field_048_guess - g_smoothStep_guess * 0.03f;
            if (!(field_048_guess < target)) {
                return;
            }
        }
    }
    field_048_guess = target;
}

// When this spawn is the local player, passes string 0x5B5 to the client object (0x00988DF0).
// FUNCTION: TITANIUM 0x00479D72
void CallbackTarget_guess::OnCallback_guess() {
    if (this == g_callbackTarget_guess) {
        const char* text = pStringTable->getString(0x5b5, 0);
        g_textSink_guess->dsp_chat(text);
    }
}

struct ValueManager_guess {
    unsigned char Adjust_guess(unsigned char value);
};

// Weapon item type to its combat skill id: 0 -> 1 (1H slashing), 1 -> 3, 2 -> 36 (piercing), 3 -> 0, 4
// -> 2, 5/6/27/28 -> 7 (archery), and so on.
// FUNCTION: TITANIUM 0x00479D99
unsigned char ValueManager_guess::Adjust_guess(unsigned char value) {
    // 5, 6, 0x1b, 0x1c share one return (7)
    switch (value) {
    case 0: return 1;
    case 1: return 3;
    case 2: return 0x24;
    case 3: return 0;
    case 4: return 2;
    case 5:
    case 6:
    case 0x1b:
    case 0x1c:
        return 7;
    case 7:
    case 0x13:
        return 0x33;
    case 9: return 0xe7;
    case 10: return 0xf;
    case 0x23: return 0x24;
    }
    return 0x1c;
}

// Playable race: up to 12, Iksar 128, Vah Shir 130, Froglok 330; `race` -1 tests this spawn.
// EQPlayer::LegalPlayerRace in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x00479E02
// @early-stop: budget, structural ndiff=17
int EQPlayerCore_guess::LegalPlayerRace_guess(int race) {
    if (race == -1) {
        race = race_0260_guess;
    }
    if (race <= 12 || race == Race_Iksar || race == Race_VahShir || race == Race_Froglok) {
        return 1;
    }
    return 0;
}

// Drops the spawn onto the floor below it (Z = floor + +0x238); -1e27 means no floor was found.
// FUNCTION: TITANIUM 0x00479E37
// @early-stop: budget, structural ndiff=6
void EQPlayerCore_guess::PlaceOnFloor_guess() {
    int x_bits = *(int*)&y_0030_guess;
    float result = GetFloorHeightAt_guess(*(float*)&x_bits, x_0034_guess, z_0038_guess, 1);
    if (result != -1e27f) {
        handler->floorHeight_0048_guess = result;
        z_0038_guess = result + heightOffset_0238_guess;
    }
    FUN_0048a945_guess();
}

// Whether a group invite is pending for the player (actor +0xF8C).
// FUNCTION: TITANIUM 0x00479EA3
char EQPlayerCore_guess::IsGroupInvitePending_guess() {
    return handler->field_f8c_guess;
}

// Invite-pending flag (handler +0xF8C, read by 0x00479EA3): set when a group invite is shown
// (0x0049D654), cleared on /follow (0x0049D7B6), /disband (0x0049D8BD), death (0x004BCA2C) and a full
// raid update. Also passed to the object at 0x00991A74; when set, 0x009928E0 gets update 0xC.
// FUNCTION: TITANIUM 0x00479EB0
void EQPlayerCore_guess::SetGroupInvitePending_guess(int value) {
    handler->field_f8c_guess = (char)value;
    pinstCGroupWnd_guess->Set_guess(value);
    if ((char)value != 0 && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0xc, 0);
    }
}

// Plays sound `value` at the spawn; quieter (x0.8) and flagged 2 when this is the player or carries
// the player (actor +0x160 is the rider).
// FUNCTION: TITANIUM 0x00479EE8
void EQPlayerCore_guess::PlaySound_guess(int value) {
    bool controlled = this == EQ_GLOBAL(EQPlayerCore_guess*, 0x00905CE4) ||
        handler->rider_0160_guess == EQ_GLOBAL(EQPlayerCore_guess*, 0x00905CE4);
    EffectPack_guess pack;
    pack.Initialize_guess();
    float half = avatarHeight_023c_guess * 0.5f;
    pack.values_guess[4] = y_0030_guess;
    pack.values_guess[5] = x_0034_guess;
    pack.values_guess[7] = half;
    pack.values_guess[6] = z_0038_guess;
    pack.values_guess[8] = half * 24.0f;
    pack.flags_guess = controlled ? 2 : 0;
    if (controlled) {
        pack.values_guess[0] *= 0.8f;
    }
    g_resourceUser_guess->Apply_guess(value, &pack);
}

// Loop sound of the actor (+0xF6C); 0 picks the race's idle loop (+0xF20). Corpses (Type 2+) are silent.
// FUNCTION: TITANIUM 0x00479F75
void EQPlayerCore_guess::SetCurrentLoopSound_guess(int value) {
    if (value == 0) {
        value = handler->field_f20_guess;
    }
    if (type_0244_guess >= 2) {
        value = 0;
    }
    if (this == (EQPlayerCore_guess*)g_callbackTarget_guess && g_ownerState_guess == 0) {
        value = 0;
    }
    if (race_0260_guess == 0x1d &&
        (handler->currentAnimation_0134_guess == 0x21 || handler->currentAnimation_0134_guess == 0x49)) {
        value = 0;
    }
    handler->currentLoopSound_0f6c_guess = value;
    if (handler->loopSoundEmitter_01b4_guess != 0) {
        if (handler->currentLoopSound_0f6c_guess == 0) {
            handler->loopSoundEmitter_01b4_guess->Apply_guess(0, &name_0120_guess);
        } else {
            handler->loopSoundEmitter_01b4_guess->Apply_guess(handler->currentLoopSound_0f6c_guess, &name_0120_guess);
        }
    }
}

// 1 for races 25, 34, 47, 56, 69, 79, 109, 111, 113 and 416; 0 for 72, 73, 114, 141 and 404; any other
// race gives 1 unless the spawn has no actor info or its +0x9C is 1. A spell check refuses with string
// 0x121 when it is 0.
// FUNCTION: TITANIUM 0x0047A018
char EQPlayerCore_guess::FUN_0047a018_guess() {
    switch (race_0260_guess) {
    case 0x6d:
    case 0x38:
    case 0x19:
    case 0x22:
    case 0x2f:
    case 0x45:
    case 0x4f:
    case 0x6f:
    case 0x71:
    case 0x1a0:
        return 1;
    case 0x48:
    case 0x49:
    case 0x72:
    case 0x8d:
    case 0x194:
        return 0;
    }
    if (handler == 0 || handler->field_09c_guess == 1) {
        return 0;
    }
    return 1;
}

// Sneak modifier (actor +0xEC4): 0.5, plus 0.1 per rogue (class 9) level above 50, at most 1.5.
// FUNCTION: TITANIUM 0x0047A085
void EQPlayerCore_guess::InitSneakMod_guess() {
    if (handler != 0) {
        handler->sneakMod_0ec4_guess = 0.5f;
        if (playerClass_0252_guess == 9 && level_024c_guess > 0x32) {
            int count = level_024c_guess - 0x32;
            float amount = (float)count;
            if (amount > 10.0f) {
                amount = 10.0f;
            }
            float change = amount * 0.1f;
            handler->sneakMod_0ec4_guess = change + handler->sneakMod_0ec4_guess;
        }
    }
}

// Actor scale from model size: size/5, or size/6 for the races of FUN_0047937c_guess; the 1.3 factors
// depend on the global 0x923C30.
// FUNCTION: TITANIUM 0x0047A0E9
float EQPlayerCore_guess::ScaleFromSize_guess(float value) {
    if (FUN_0047937c_guess(race_0260_guess)) {
        if (g_field923c30_guess == 0 && g_ownerState_guess == 0) {
            float result = value * 0.16666667f;
            return result * 1.3f;
        }
        return value * 0.16666667f;
    }
    float result = value * 0.2f;
    if (g_field923c30_guess != 0) {
        result = result * 0.7692308f;
    }
    return result;
}

// Default model size by race. The other ids are probably the city-NPC versions of player races (77, 78,
// 81, 88, 90, 92-94, 112), which share their race's size; races 42 and 120 are 3 when gender is 2.
// FUNCTION: TITANIUM 0x0047A147
float EQPlayerCore_guess::GetDefaultSizeForRace_guess(int race, char gender) {
    switch (race) {
    case 7:
        return 5.5f;
    case 2:
        return 7.0f;
    case 0x5a:
        return 7.0f;
    case 0x82:
        return 7.0f;
    case 0xb:
        return 3.5f;
    case 0x51:
        return 3.5f;
    case 4:
        return 5.0f;
    case 6:
        return 5.0f;
    case 0x70:
        return 5.0f;
    case 0x14a:
        return 5.0f;
    case 0x4d:
        return 5.0f;
    case 0x2b:
        return 4.7f;
    case 9:
        return 8.0f;
    case 0x5c:
        return 8.0f;
    case 1:
        return 6.0f;
    case 3:
        return 6.0f;
    case 5:
        return 6.0f;
    case 0x18:
        return 6.0f;
    case 0x4e:
        return 6.0f;
    case 0x80:
        return 6.0f;
    case 0x2a:
    case 0x78:
        if (gender == 2) {
            return 3.0f;
        }
        return 6.0f;
    case 0xc:
        return 3.0f;
    case 0x58:
        return 3.0f;
    case 8:
        return 4.0f;
    case 0x5e:
        return 4.0f;
    case 0xa:
        return 9.0f;
    case 0x5d:
        return 9.0f;
    }
    return 6.0f;
}

// Race overrides for SetHeights_guess's height values: `first` the actor scale, `second` +0x234,
// `third` +0x238, `fourth` +0x22C. Callers cast it and pass a sixth `Type == 0` argument it never reads.
// FUNCTION: TITANIUM 0x0047A239
void __cdecl AdjustHeightsForRace_guess(int code_guess, float* first_guess, float* second_guess, float* third_guess, float* fourth_guess) {
    switch (code_guess) {
    case 0x78:
    case 0xab:
    case 0x164:
        *second_guess = 3.9f;
        break;
    case 0x48:
        *second_guess = 1.0f;
        *third_guess = 0.1f;
        *first_guess = 2.0f;
        break;
    case 0x1a:
    case 0x1b:
    case 0x14a:
        *second_guess = *second_guess * 0.75;
        break;
    case 0x24:
    case 0x5b:
        *fourth_guess = *third_guess * 0.75f;
        *second_guess = 3.0f;
        break;
    case 0x31:
    case 0x9e:
    case 0xc4:
        *second_guess = 34.5f;
        *third_guess = 20.0f;
        *first_guess = 1.0f;
        break;
    case 0x32:
        *second_guess = 5.0f;
        break;
    case 0x49:
    case 0x72:
    case 0x8d:
    case 0xfc:
    case 0x194:
        *second_guess = 1.0f;
        *third_guess = 0.1f;
        *first_guess = 1.0f;
        break;
    case 0x6c:
        *second_guess = 3.0f;
        *third_guess = 3.0f;
        *first_guess = 0.05f;
        break;
    case 0x8e:
    case 0x8f:
        *second_guess = 6.0f;
        *third_guess = 0.1f;
        *first_guess = 1.0f;
        break;
    }
}

// Splits a face code: returns the ones digit (the face) and stores the tens (the variant) in `output`.
// `value` < 0 uses FaceHair (+0x24D).
// FUNCTION: TITANIUM 0x0047A491
unsigned char EQPlayerCore_guess::GetBaseFaceNbr_guess(int value, unsigned char* output) {
    if (value < 0) {
        value = faceHair_024d_guess;
    }
    if (value < 10) {
        if (output != 0) {
            *output = 0;
        }
        return (unsigned char)value;
    }
    unsigned char remainder = (unsigned char)(value % 10);
    if (output != 0) {
        *output = (unsigned char)((value - remainder) / 10);
    }
    return remainder;
}

// Beard kind: 1 for human, barbarian, erudite, dwarf, halfling and gnome males; 2 for high, dark and
// half-elf males and dwarf females (SetFHEB_guess then skips the beard IT); else 0.
// FUNCTION: TITANIUM 0x0047A4E1
char EQPlayerRaceView_guess::GetBeardKind_guess() {
    char result = 0;
    if (gender_024e_guess == 1) {
        if (race_0260_guess == 8) {
            result = 2;
        }
    } else {
        if (0 < race_0260_guess) {
            if (race_0260_guess <= 3) {
                result = 1;
            } else if (race_0260_guess <= 4) {
            } else if (race_0260_guess <= 7) {
                result = 2;
            } else if (race_0260_guess == 8) {
                result = 1;
            } else if (race_0260_guess <= 10) {
            } else if (race_0260_guess <= 12) {
                result = 1;
            }
        }
    }
    return result;
}

// Hair kind: 2 for Erudites, 0 for male trolls and ogres, Iksar, Vah Shir and Froglok, else 1.
// FUNCTION: TITANIUM 0x0047A523
char EQPlayerCore_guess::GetHairKind_guess() {
    char result = 1;
    switch (race_0260_guess) {
    case 3:
        result = 2;
        break;
    case 9:
    case 10:
        if (gender_024e_guess == 0) {
            result = 0;
        }
        break;
    case 0x80:
    case 0x82:
    case 0x14a:
        result = 0;
        break;
    }
    return result;
}

// Hair colour range for a race: dark elves 11-19, high elves 4-17, gnomes 0-22, trolls and ogres 0-23,
// others 0-18; Iksar, Vah Shir and Froglok have none (0-0).
// FUNCTION: TITANIUM 0x0047A561
void EQPlayerRaceView_guess::GetHairColorRange_guess(int value, int* first, int* second) {
    if (value < 0) {
        value = race_0260_guess;
    }
    if (value <= 0x80) {
        if (value != 0x80) {
            switch (value) {
            case 6:
                *first = 0xb;
                *second = 0x13;
                return;
            case 5:
                *first = 4;
                *second = 0x11;
                return;
            case 12:
                *first = 0;
                *second = 0x16;
                return;
            case 9:
            case 10:
                *first = 0;
                *second = 0x17;
                return;
            case 1:
                *first = 0;
                *second = 0x12;
                return;
            case 2:
                *first = 0;
                *second = 0x12;
                return;
            case 3:
                *first = 0;
                *second = 0x12;
                return;
            case 4:
                *first = 0;
                *second = 0x12;
                return;
            case 7:
                *first = 0;
                *second = 0x12;
                return;
            case 8:
                *first = 0;
                *second = 0x12;
                return;
            case 11:
                *first = 0;
                *second = 0x12;
                return;
            }
            *first = 0;
            *second = 0x12;
            return;
        }
    } else if (value != 0x82 && value != 0x14a) {
        *first = 0;
        *second = 0x12;
        return;
    }
    *first = 0;
    *second = 0;
}

// True for males, trolls and ogres: only they can roll no hair in
// SetDefaultFacialFeaturesByFace_guess.
// FUNCTION: TITANIUM 0x0047A62D
int EQPlayerRaceView_guess::CanHaveNoHair_guess() {
    if (gender_024e_guess != 0 && race_0260_guess != 10 && race_0260_guess != 9) {
        return false;
    }
    return true;
}

// Sets Levitate (+0x28C, the Spawn_Struct flymode): actor +0x9C is set only for 0 (probably gravity), and
// +0x84 is 1 for mode 2, else -1.
// FUNCTION: TITANIUM 0x0047A64D
void EQPlayerStatusView_guess::SetLevitate_guess(int value) {
    levitate_028c_guess = value;
    if (pActorInfo_01a8_guess != 0) {
        pActorInfo_01a8_guess->field_9c_guess = value == 0;
        if (levitate_028c_guess == 2) {
            pActorInfo_01a8_guess->field_84_guess = 1;
        } else {
            pActorInfo_01a8_guess->field_84_guess = -1;
        }
    }
}

// True when a spawn with id `value` exists (0x00401B28).
// FUNCTION: TITANIUM 0x0047A691
bool EQPlayerStatusView_guess::Check_guess(int value) {
    return FUN_00401b28_guess(value) != 0;
}

// Next free spawn id, 1-2999, round-robin from the cursor 0x78D854; EQPlayer_guess declares the same VA as
// NextSpawnId_guess.
// FUNCTION: TITANIUM 0x0047A6A4
// @early-stop: budget, structural ndiff=10
unsigned int EQPlayerStatusView_guess::FindFreeIndex_guess() {
    unsigned int index = g_statusCursor_guess;
    int tries = 0;
    if (index >= 3000 || index == 0) {
        index = 1;
    }
    while (Check_guess(index) != 0) {
        ++index;
        if (index >= 3000 || index == 0) {
            index = 1;
        }
        ++tries;
        if (tries >= 3000) {
            g_statusCursor_guess &= 0;
            // Deliberate null write: a full spawn table crashes the client here. Keep it.
            EQ_GLOBAL(unsigned char, 0x00000000) = 10;
            index = g_statusCursor_guess;
            break;
        }
    }
    unsigned int result = index;
    ++index;
    g_statusCursor_guess = index;
    return result;
}

// Sets SpawnID (+0x258) and claims slot `index` of the 3000-entry spawn table 0x900F50 if it is free;
// ClearTable_guess empties that table.
// FUNCTION: TITANIUM 0x0047A705
void TableOwner_guess::SetSpawnId_guess(unsigned int index) {
    if (index > 0 && index < 3000 && EQ_ARRAY(TableOwner_guess*, 0x00900F50)[index] == 0) {
        EQ_ARRAY(TableOwner_guess*, 0x00900F50)[index] = this;
    }
    field_258_guess = index;
}

// Clears the spawn-by-id table (0x00900F50, 3000 entries).
// FUNCTION: TITANIUM 0x0047A72C
void TableOwner_guess::ClearTable_guess() {
    memset(EQ_ARRAY(char, 0x00900F50), 0, 0x2ee0);
}

// Sets Race (+0x260) and IsABoat (+0x1B6) for the boat races 72 (ship), 73 (launch), 114 (ghost ship),
// 141 (boat) and 404.
// FUNCTION: TITANIUM 0x0047A741
void EQPlayerRaceView_guess::SetRace_guess(int value) {
    race_0260_guess = value;
    if (value == 0x8d || value == 0x48 || value == 0x49 || value == 0x72 || value == 0x194) {
        field_1b6_guess = 1;
    } else {
        field_1b6_guess = 0;
    }
}

// Title shown before the name (+0x2A4, 32 bytes; the Spawn_Struct title). TextBufferOwner_guess::
// SetSuffix_guess is its twin for the suffix (+0x2C4).
// FUNCTION: TITANIUM 0x0047A77B
void EQPlayerRaceView_guess::SetTitle_guess(const char* text) {
    if (text != 0) {
        strncpy(text_2a4_guess, text, 0x1f);
        text_2a4_guess[0x1f] = 0;
    } else {
        memset(text_2a4_guess, 0, 0x20);
    }
}

struct TextBufferOwner_guess {
    char pad_000_guess[0x2c4];
    char field_2c4_guess[0x20];
    void SetSuffix_guess(const char* text);
};

// Suffix shown after the name (+0x2C4, 32 bytes, the Spawn_Struct suffix); null clears it. Twin of the
// title setter 0x0047A77B.
// FUNCTION: TITANIUM 0x0047A7B7
void TextBufferOwner_guess::SetSuffix_guess(const char* text) {
    if (text != 0) {
        strncpy(field_2c4_guess, text, 0x1f);
        field_2c4_guess[0x1f] = 0;
    } else {
        memset(field_2c4_guess, 0, 0x20);
    }
}

// Whether an illusion of `race` (gender `state`, size `value`) fits here. A mounted spawn (actor +0x15C)
// may only take playable races, 60 and 367; a model taller than the current one needs floor-to-ceiling
// room for twice its height.
// FUNCTION: TITANIUM 0x0047A7F3
// @early-stop: budget, structural ndiff=47
char EQPlayerCore_guess::CanFitIllusionRace_guess(int race, unsigned int state, float value) {
    if (handler == 0) {
        return 1;
    }
    if (handler->mount_015c_guess != 0 && !LegalPlayerRace_guess(race) &&
        race != 0x3c && race != 0x16f) {
        if (type_0244_guess == 0 && pCharInfo_0218_guess != 0) {
            token_string_to_client_guess(pCharInfo_0218_guess, 0xbe, 0x121, 0);
        }
        return 0;
    }
    if (g_display2_guess == 0) {
        return 0;
    }
    if (value < 0.0f) {
        value = GetDefaultSizeForRace_guess(race, (char)state);
    }
    float adjustedHeight = value * 0.2f;
    char actorName[0x20];
    GetRaceModelTag_guess(actorName, race, state & 0xff);
    ScaleProvider_guess* provider = FUN_004b6cb4_guess(actorName);
    value = provider->GetROffset_guess() * adjustedHeight;
    float threshold;
    ((void (__cdecl *)(int, float*, float*, float*, float*, bool))AdjustHeightsForRace_guess)(
        race, &adjustedHeight, &threshold, &value, (float*)&state, type_0244_guess == 0);
    if (heightOffset_0238_guess < value) {
        threshold = value + value;
        float x = y_0030_guess;
        float y = x_0034_guess;
        float floorHeight = g_display2_guess->GetCeilingHeight_guess(
            x, y, z_0038_guess, 0.5f);
        float floorHeight2 = g_display2_guess->GetFloorHeight_guess(
            x, y, z_0038_guess);
        if (floorHeight - floorHeight2 <= threshold) {
            return 0;
        }
    }
    return 1;
}

#define MESSAGE_SLOT(n) virtual void Slot##n##_guess();
struct MessageInterface_guess {
    MESSAGE_SLOT(000) MESSAGE_SLOT(001) MESSAGE_SLOT(002) MESSAGE_SLOT(003)
    MESSAGE_SLOT(004) MESSAGE_SLOT(005) MESSAGE_SLOT(006) MESSAGE_SLOT(007)
    MESSAGE_SLOT(008) MESSAGE_SLOT(009) MESSAGE_SLOT(010) MESSAGE_SLOT(011)
    MESSAGE_SLOT(012) MESSAGE_SLOT(013) MESSAGE_SLOT(014) MESSAGE_SLOT(015)
    MESSAGE_SLOT(016) MESSAGE_SLOT(017) MESSAGE_SLOT(018) MESSAGE_SLOT(019)
    MESSAGE_SLOT(020) MESSAGE_SLOT(021) MESSAGE_SLOT(022) MESSAGE_SLOT(023)
    MESSAGE_SLOT(024) MESSAGE_SLOT(025) MESSAGE_SLOT(026) MESSAGE_SLOT(027)
    MESSAGE_SLOT(028) MESSAGE_SLOT(029) MESSAGE_SLOT(030) MESSAGE_SLOT(031)
    MESSAGE_SLOT(032) MESSAGE_SLOT(033) MESSAGE_SLOT(034) MESSAGE_SLOT(035)
    MESSAGE_SLOT(036) MESSAGE_SLOT(037) MESSAGE_SLOT(038) MESSAGE_SLOT(039)
    MESSAGE_SLOT(040) MESSAGE_SLOT(041) MESSAGE_SLOT(042) MESSAGE_SLOT(043)
    MESSAGE_SLOT(044) MESSAGE_SLOT(045) MESSAGE_SLOT(046) MESSAGE_SLOT(047)
    MESSAGE_SLOT(048) MESSAGE_SLOT(049) MESSAGE_SLOT(050) MESSAGE_SLOT(051)
    MESSAGE_SLOT(052) MESSAGE_SLOT(053) MESSAGE_SLOT(054) MESSAGE_SLOT(055)
    MESSAGE_SLOT(056) MESSAGE_SLOT(057) MESSAGE_SLOT(058) MESSAGE_SLOT(059)
    MESSAGE_SLOT(060) MESSAGE_SLOT(061) MESSAGE_SLOT(062) MESSAGE_SLOT(063)
    MESSAGE_SLOT(064) MESSAGE_SLOT(065) MESSAGE_SLOT(066) MESSAGE_SLOT(067)
    MESSAGE_SLOT(068) MESSAGE_SLOT(069) MESSAGE_SLOT(070) MESSAGE_SLOT(071)
    MESSAGE_SLOT(072) MESSAGE_SLOT(073) MESSAGE_SLOT(074) MESSAGE_SLOT(075)
    MESSAGE_SLOT(076) MESSAGE_SLOT(077) MESSAGE_SLOT(078) MESSAGE_SLOT(079)
    virtual void Dispatch_guess(int value, const char* input, char* output);
    virtual void Slot081_guess();
    virtual void Slot082_guess();
    virtual void Slot083_guess(int index, const char* name);
    virtual void Slot084_guess();
    virtual char Slot085_guess(int index);
};
#undef MESSAGE_SLOT

struct MessageHolder_guess {
    MessageInterface_guess* object_guess;
};

struct EQPlayerBoneView_guess {
    char pad_000_guess[0x1a8];
    MessageHolder_guess* field_1a8_guess;
    void SetAttachmentBoneNames_guess();
    void ChangeBoneStringSprite(int value, const char* input);
};

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* output, const char* input);

// Sets the text sprite on bone `value` (0 HEAD_NAME, the name sprite; 2 HEAD_GUILD); null clears it.
// FUNCTION: TITANIUM 0x0047A99F
void EQPlayerBoneView_guess::ChangeBoneStringSprite(int value, const char* input) {
    char output[8192];
    if (field_1a8_guess->object_guess != 0) {
        if (input != 0) {
            FUN_0060e450_guess(output, input);
        } else {
            output[0] = 0;
        }
        field_1a8_guess->object_guess->Dispatch_guess(value, input, output);
    }
}

// Bone names for the attachment points of newer skeletons (point ids as in UpdateDAGPointers_guess);
// the camera falls back to ROOT_CAM01 when HEAD_CAM01 is missing.
// FUNCTION: TITANIUM 0x0047AD34
void EQPlayerBoneView_guess::SetAttachmentBoneNames_guess() {
    field_1a8_guess->object_guess->Slot083_guess(1, "HEAD_HELM");
    field_1a8_guess->object_guess->Slot083_guess(8, "HEAD_HAIR");
    field_1a8_guess->object_guess->Slot083_guess(9, "HEAD_BEARD");
    field_1a8_guess->object_guess->Slot083_guess(10, "HEAD_EBROWS");
    field_1a8_guess->object_guess->Slot083_guess(0, "HEAD_NAME");
    field_1a8_guess->object_guess->Slot083_guess(2, "HEAD_GUILD");
    field_1a8_guess->object_guess->Slot083_guess(0x17, "HEAD_CAM01");
    if (!field_1a8_guess->object_guess->Slot085_guess(0x17)) {
        field_1a8_guess->object_guess->Slot083_guess(0x17, "ROOT_CAM01");
    }
    field_1a8_guess->object_guess->Slot083_guess(0x13, "CHEST_CHEST01");
    field_1a8_guess->object_guess->Slot083_guess(0x14, "CHEST_CHEST02");
    field_1a8_guess->object_guess->Slot083_guess(0x15, "CHEST_CHEST03");
    field_1a8_guess->object_guess->Slot083_guess(0xe, "ARML_PLDN");
    field_1a8_guess->object_guess->Slot083_guess(0xf, "ARMR_PLDN");
    field_1a8_guess->object_guess->Slot083_guess(0x18, "CHEST_BACK");
    field_1a8_guess->object_guess->Slot083_guess(0xc, "ARML_BRCR");
    field_1a8_guess->object_guess->Slot083_guess(0xd, "ARMR_BRCR");
    field_1a8_guess->object_guess->Slot083_guess(0x19, "ARML_GLVE");
    field_1a8_guess->object_guess->Slot083_guess(0x1a, "ARMR_GLVE");
    field_1a8_guess->object_guess->Slot083_guess(3, "ARMR_WEAP");
    field_1a8_guess->object_guess->Slot083_guess(4, "ARML_WEAP");
    field_1a8_guess->object_guess->Slot083_guess(5, "ARML_SHLD");
    field_1a8_guess->object_guess->Slot083_guess(0x1b, "ARMR_SHTH");
    field_1a8_guess->object_guess->Slot083_guess(0x1c, "ARML_SHTH");
    field_1a8_guess->object_guess->Slot083_guess(0x1d, "CHEST_SHTH");
    field_1a8_guess->object_guess->Slot083_guess(0x1e, "LEGL_LEG01");
    field_1a8_guess->object_guess->Slot083_guess(0x1f, "LEGL_LEG02");
    field_1a8_guess->object_guess->Slot083_guess(0x20, "LEGL_BOOT");
    field_1a8_guess->object_guess->Slot083_guess(0x21, "LEGR_BOOT");
    field_1a8_guess->object_guess->Slot083_guess(0x22, "CHEST03_TORCH01");
    field_1a8_guess->object_guess->Slot083_guess(0x12, "CHEST03_MOUNT01");
}

// Finds the two eye materials (actor +0xFA8, +0xFAC) that SetEyeColor_guess tints; halfling males and
// Froglok have their own layout.
// FUNCTION: TITANIUM 0x0047B001
void EQPlayerCore_guess::FindDefaultEyeMaterialIndexes_guess() {
    if (handler != 0 && handler->actorDef_012c_guess != 0 &&
        handler->actorDef_012c_guess->field_034_guess != 0) {
        bool flag = race_0260_guess == 0xb && gender_024e_guess == 0;
        handler->target->Slot066_guess(&handler->field_fa8_guess, &handler->field_fac_guess,
                                       flag, race_0260_guess == 0x14a);
    }
}

struct SpawnPoint_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct SpawnColor_guess {
    unsigned char r_guess;
    unsigned char g_guess;
    unsigned char b_guess;
    unsigned char a_guess;
};

// Record passed to the BSPURT_BCD spawn call (0x84 bytes)
struct BloodSpawn_guess {
    int type_000_guess;
    int flags_004_guess;
    int count_008_guess;
    float field_00c_guess;
    float field_010_guess;
    float field_014_guess;
    float field_018_guess;
    float x_01c_guess;
    float y_020_guess;
    float z_024_guess;
    float x_028_guess;
    float y_02c_guess;
    float z_030_guess;
    int field_034_guess;
    int field_038_guess;
    float x_03c_guess;
    float y_040_guess;
    float z_044_guess;
    float x_048_guess;
    float y_04c_guess;
    float z_050_guess;
    float field_054_guess;
    float field_058_guess;
    float field_05c_guess;
    float field_060_guess;
    float field_064_guess;
    int field_068_guess;
    float field_06c_guess;
    int field_070_guess;
    float field_074_guess;
    float field_078_guess;
    SpawnColor_guess color_07c_guess;
    int sprite_080_guess;
};

struct SpawnObject_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess(int value);
};

struct SpawnFactory_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void Slot018_guess();
    virtual void Slot019_guess();
    virtual void Slot020_guess();
    virtual void Slot021_guess();
    virtual void Slot022_guess(int value, SpawnPoint_guess* point, SpawnObject_guess** result,
                               int flags, int extra);
};

#define g_spawnFactory_guess EQ_GLOBAL(SpawnFactory_guess*, 0x0099E368)

struct SpawnService_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess(const char* name, BloodSpawn_guess* spawn, int* out);
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void Slot018_guess();
    virtual void Slot019_guess();
    virtual void Slot020_guess();
    virtual void Slot021_guess();
    virtual void Slot022_guess();
    virtual void Slot023_guess();
    virtual void Slot024_guess(const char* name, int* out);
};

#define g_spawnService_guess EQ_GLOBAL(SpawnService_guess*, 0x0099E360)

struct SpawnDisplay_guess {
    char pad_000_guess[0x28c4];
    int field_28c4_guess;
    // EXTERNAL: TITANIUM 0x0043A15C SpawnDisplay_guess::s3dCollideSphereWithWorld_guess
    bool s3dCollideSphereWithWorld_guess(float x_guess, float y_guess, float z_guess, float a_guess,
                         float b_guess, float c_guess, int d_guess, int e_guess,
                         int f_guess, int g_guess);
    // EXTERNAL: TITANIUM 0x0043A292 SpawnDisplay_guess::GetEnvironment_guess
    bool GetEnvironment_guess(float x_guess, float y_guess, float z_guess, int* flag_guess);
};

#define g_spawnDisplay_guess EQ_GLOBAL(SpawnDisplay_guess*, 0x00905D24)

// Builds the BSPURT_BCD particle emitter once (sprite I_BLOODSPRITE, cached at 0x905D24 +0x28C4) and
// fires it at bone 6, the _BLD_DAG point.
// FUNCTION: TITANIUM 0x0047B069
void EQPlayerCore_guess::SpurtBloodOnDag_guess() {
    SpawnPoint_guess pos = {0.0f, 0.0f, 0.0f};
    SpawnObject_guess* object = 0;
    if (g_spawnDisplay_guess->field_28c4_guess == 0) {
        int sprite = 0;
        SpawnColor_guess color = {0xff, 0xff, 0xff, 0xff};
        g_spawnService_guess->Slot024_guess("I_BLOODSPRITE", &sprite);
        if (sprite != 0) {
            BloodSpawn_guess spawn = {
                3, 0x401, 100, 1.0f, 0.0f, 0.0f, 1.0f,
                pos.x_guess, pos.y_guess, pos.z_guess, pos.x_guess, pos.y_guess, pos.z_guess,
                1, 500,
                pos.x_guess, pos.y_guess, pos.z_guess, pos.x_guess, pos.y_guess, pos.z_guess,
                0.0f, 0.0f, 0.0f, 0.0f,
                128.0f, 500, 5.0f, 5, 0.25f, 1.0f,
                color, sprite};
            g_spawnService_guess->Slot012_guess("BSPURT_BCD", &spawn,
                                                &g_spawnDisplay_guess->field_28c4_guess);
        }
    }
    if (g_spawnDisplay_guess->field_28c4_guess != 0) {
        g_spawnFactory_guess->Slot022_guess(g_spawnDisplay_guess->field_28c4_guess, &pos,
                                            &object, 0, 0);
        object->Slot001_guess(handler->target->Slot092_guess(6));
    }
}

// IT-number offset of a race's default attachments: 60 per race in this switch's order, +30 for females.
// FUNCTION: TITANIUM 0x0047B1F1
int EQPlayerCore_guess::GetRaceOffsetForAttachmentITs_guess() {
    int result = 0;
    if (gender_024e_guess == 1) {
        result = 0x1e;
    }
    int type = race_0260_guess;
    switch (type) {
    case 7: return result + 0x3c;
    case 8: return result + 0x78;
    case 6: return result + 0xb4;
    case 4: return result + 0xf0;
    case 5: return result + 0x12c;
    case 1: return result + 0x168;
    case 3: return result + 0x1e0;
    case 2: return result + 0x21c;
    case 9: return result + 0x294;
    case 10: return result + 0x2d0;
    case 11: return result + 0x30c;
    case 0x80: return result + 0x1a4;
    case 0x82: result += 0x258; break;
    case 0x14a: return result + 0x348;
    }
    return result;
}

// Eye colour `value`: `flag` 1 tints material +0xFAC and stores +0x248 (Spawn_Struct eyecolor2), 0 tints
// +0xFA8 and stores +0x247 (eyecolor1). Some faces force 0xD1 or 0xCF, probably eye patches or scars;
// non-human textures are offset per race.
// FUNCTION: TITANIUM 0x0047B2A9
int EQPlayerCore_guess::SetEyeColor_guess(char flag, int value) {
    if (handler != 0 && handler->actorDef_012c_guess != 0 &&
        handler->actorDef_012c_guess->field_034_guess != 0 &&
        handler->field_fac_guess >= 0 && value != 0xff) {
        int state;
        if (flag != 0) {
            unsigned char digit = GetBaseFaceNbr_guess(-1, 0);
            if ((race_0260_guess == 1 && gender_024e_guess == 0 && digit == 3) ||
                (race_0260_guess == 2 && gender_024e_guess == 0 && digit == 6)) {
                value = 0xd1;
            } else if ((race_0260_guess == 8 && gender_024e_guess == 0 && digit == 5) ||
                       (race_0260_guess == 2 && gender_024e_guess == 0 && digit == 4)) {
                value = 0xcf;
            }
            state = handler->field_fac_guess;
        } else {
            state = handler->field_fa8_guess;
        }

        int adjusted = value;
        switch (race_0260_guess) {
        case 6:
            adjusted += 0x14;
            break;
        case 9:
            adjusted += 100;
            break;
        case 10:
            adjusted += 0x50;
            break;
        case 0x80:
            adjusted += 0x28;
            break;
        case 0x82:
            adjusted += 0x3c;
            break;
        case 0x14a:
            adjusted += 0x78;
            break;
        }
        if (handler->target->Slot067_guess(adjusted, state)) {
            if (flag != 0) {
                eyeColor_0248_guess = (unsigned char)value;
            } else {
                eyeColor1_0247_guess = (unsigned char)value;
            }
            return 1;
        }
    }
    return 0;
}

// Hair style for the newer (Luclin) models: puts mesh "<actor tag>_HS<head>_HEAD_HAIR" on attachment point
// 8 and returns whether the actor took it. Older models use IT models instead (0x0047B511).
// FUNCTION: TITANIUM 0x0047B3E3
bool EQPlayerCore_guess::SwapHairStyle_guess(int head) {
    char name[12];
    char buffer[64];
    GetActorTag_guess(name);
    sprintf(buffer, "%s_HS%2d_HEAD_HAIR", name, head);
    return handler->target->Slot059_guess(8, buffer) != 0;
}

// Beard for the newer (Luclin) models: puts mesh "<actor tag>_FH<head>_HEAD_BEARD" on attachment point 9
// and returns whether the actor took it. Older models use IT models instead (0x0047B511).
// FUNCTION: TITANIUM 0x0047B43E
bool EQPlayerCore_guess::SwapBeardStyle_guess(int head) {
    char name[12];
    char buffer[64];
    GetActorTag_guess(name);
    sprintf(buffer, "%s_FH%2d_HEAD_BEARD", name, head);
    return handler->target->Slot059_guess(9, buffer) != 0;
}

// Tints attachment `value` with the RGBA quad `face`; black (0, 0, 0) means untinted and becomes white.
// FUNCTION: TITANIUM 0x0047B499
char EQPlayerCore_guess::SetAttachmentTint_guess(int value, Face_guess* face) {
    Face_guess local;
    if (handler->target->Slot085_guess(value)) {
        if (face != 0) {
            CallbackResult_guess* result = handler->target->Slot086_guess(value);
            if (result != 0) {
                if (face->red_0002_guess == 0 && face->green_0001_guess == 0 &&
                    face->blue_0000_guess == 0) {
                    local.alpha_0003_guess = 0xff;
                    local.red_0002_guess = 0xff;
                    local.blue_0000_guess = 0xff;
                    local.green_0001_guess = 0xff;
                    face = &local;
                }
                result->Slot053_guess(face);
                return 1;
            }
        }
    }
    return 0;
}

// Old-skeleton hair (`value` 1000+) or beard (2000+) as an IT model on point 8 or 9, offset by
// GetRaceOffsetForAttachmentITs_guess. Vah Shir (except face 7) and Froglok get none, and their hair
// style and beard (+0x249, +0x24A) are cleared.
// FUNCTION: TITANIUM 0x0047B511
int EQPlayerCore_guess::SwapHairBeardIT_guess(int value) {
    char buffer[128];
    int result;
    if (handler->FUN_0048f019_guess()) {
        result = 0;
    } else {
        int type = value >= 0x7d0 ? 9 : 8;
        if (!handler->target->Slot085_guess(type)) {
            result = 0;
        } else {
            value += GetRaceOffsetForAttachmentITs_guess();
            if (race_0260_guess == 0x82 && faceHair_024d_guess != 7) {
                field_249_guess = 0xff;
                field_24a_guess = 0xff;
                value = 0;
            }
            if (race_0260_guess == 0x14a) {
                field_249_guess = 0xff;
                field_24a_guess = 0xff;
                value = 0;
            }
            sprintf(buffer, "IT%d", value);
            result = handler->target->Slot059_guess(type, buffer) != 0;
        }
    }
    return result;
}

// Attachment point of wear slot `kind` on old skeletons: head 1, chest 11 (tunic 7 for `flags` 1),
// arms 15/14, wrist 13/12, legs 18, feet 16/17, primary 3, secondary 4; -1 for hands.
// FUNCTION: TITANIUM 0x0047B5EF
int EQPlayerCore_guess::GetArmorAttachSlot_guess(int kind, int flags) {
    switch (kind) {
    case 2:
        if (flags == 0) {
            return 15;
        }
        if (flags == 1) {
            return 14;
        }
        break;
    case 0:
        if (flags == 0) {
            return 1;
        }
        break;
    case 1:
        if (flags == 0) {
            return 11;
        }
        if (flags == 1) {
            return 7;
        }
        break;
    case 3:
        if (flags == 0) {
            return 13;
        }
        if (flags == 1) {
            return 12;
        }
        break;
    case 7:
        if (flags == 0) {
            return 3;
        }
        break;
    case 8:
        if (flags == 0) {
            return 4;
        }
        break;
    case 5:
        return 18;
    case 6:
        return (flags != 0) + 16;
    }
    return -1;
}

struct StatePart_guess {
    int unused_guess;
    int index_guess; // 0x04
};

struct StateHolder_guess {
    char pad_0000_guess[0xc284];
    StatePart_guess* part_guess; // 0xc284
    char pad_c288_guess[0xc38c - 0xc288];
    unsigned char stateFlags_guess[0x200]; // 0xc38c
};

#define g_stateHolder_guess EQ_GLOBAL(StateHolder_guess*, 0x00905D00)

// IT number of the race helm for helm materials 240 and 241, by race and gender; `flagOut` is cleared
// for some models. Without the expansion bits at pCharData +0xC38C (probably) it is always 3.
// FUNCTION: TITANIUM 0x0047B699
// @early-stop: budget, structural ndiff=88
int EQPlayerCore_guess::GetAttachedHelmITNum_guess(int kind, int* flagOut) {
    *flagOut = 1;
    if (g_stateHolder_guess == 0 ||
        (*(unsigned short*)&g_stateHolder_guess->stateFlags_guess[
             g_stateHolder_guess->part_guess->index_guess] & 0x3fe) == 0) {
        return 3;
    }
    if (kind == 0xf0) {
        switch (race_0260_guess) {
        case 1:
            if (gender_024e_guess == 0) {
                return 0x273;
            }
            *flagOut = 0;
            return 0x26c;
        case 2:
            if (gender_024e_guess == 0) {
                return 0x219;
            }
            *flagOut = 0;
            return 0x212;
        case 3:
            *flagOut = 0;
            return gender_024e_guess != 0 ? 0x23a : 0x23f;
        case 4:
            if (gender_024e_guess == 0) {
                return 0x235;
            }
            *flagOut = 0;
            return 0x231;
        case 5:
            return gender_024e_guess != 0 ? 0x258 : 0x25d;
        case 6:
            if (gender_024e_guess == 0) {
                return 0x221;
            }
            *flagOut = 0;
            return 0x21c;
        case 7:
            return gender_024e_guess != 0 ? 0x24e : 0x253;
        case 8:
            return gender_024e_guess != 0 ? 0x226 : 0x22d;
        case 9:
            return gender_024e_guess != 0 ? 0x28a : 0x28f;
        case 10:
            return gender_024e_guess != 0 ? 0x280 : 0x285;
        case 11:
            return gender_024e_guess != 0 ? 0x262 : 0x267;
        case 12:
            return gender_024e_guess != 0 ? 0x244 : 0x249;
        case 0x80:
            return gender_024e_guess != 0 ? 0x276 : 0x27b;
        }
        return kind;
    }
    if (kind != 0xf1) {
        return kind;
    }
    switch (race_0260_guess) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 0x80:
        return 3;
    case 2:
        if (gender_024e_guess == 0) {
            return 0x219;
        }
        *flagOut = 0;
        return 0x212;
    case 10:
        return gender_024e_guess != 0 ? 0x281 : 0x286;
    }
    return kind;
}

// Applies `value` (callers pass 0x6974CC) to the actor, and to the tunic point (7) when the chest
// material is a robe (10-16).
// FUNCTION: TITANIUM 0x0047B8D5
void EQPlayerCore_guess::FUN_0047b8d5_guess(int value) {
    if (handler != 0 && handler->target != 0) {
        ((CallbackCallTarget_guess*)handler->target)->Slot049_guess(value);
        if (handler->actorDef_012c_guess != 0 &&
            handler->actorDef_012c_guess->field_034_guess != 0 &&
            field_1e4_guess >= 10 && field_1e4_guess <= 16) {
            CallbackResult_guess* result =
                ((CallbackGetter_guess*)handler->target)->Slot086_guess(7);
            if (result != 0) {
                return result->Slot049_guess(value);
            }
        }
    }
}

// Movement mode by race (actor vslot 1): 3 when lying ('s') or a corpse ('x'), 2 or 3 for the races
// listed, else 1. Probably the skeleton's walk class; not confirmed.
// FUNCTION: TITANIUM 0x0047B940
int EQPlayerCore_guess::SetPlayerPitchType_guess() {
    if (handler == 0 || handler->target == 0) {
        return false;
    }
    if (standState_0251_guess == 'x' || standState_0251_guess == 's') {
        ((CallbackSetDispatch_guess*)handler->target)->Slot001_guess(3);
        return 1;
    }
    switch (race_0260_guess) {
        case 0x0e: case 0x10: case 0x29: case 0x2a: case 0x2b:
        case 0x30: case 0x31: case 0x32: case 0x3f: case 0x4c:
        case 0x53: case 0x57: case 0x6b: case 0x77: case 0x78:
        case 0x79: case 0x7a: case 0x7c: case 0x87: case 0x9e:
        case 0xc4: case 0xc7: case 0xc8: case 0xce: case 0xd8:
        case 0xd9: case 0xdd: case 0xe8: case 0xf1: case 0xf5:
        case 0x111: case 0x118: case 0x11a: case 0x11f: case 0x129:
        case 0x130: case 0x131: case 0x13a: case 0x13f: case 0x141:
        case 0x199: case 0x1ae: case 0x1b0: case 0x1b2: case 0x1b3:
        case 0x1b5: case 0x1b6: case 0x1b7: case 0x1cb: case 0x1d1:
        case 0x1d5: case 0x1d8: case 0x1da:
            ((CallbackSetDispatch_guess*)handler->target)->Slot001_guess(2);
            return 1;
        case 0x16: case 0x1f: case 0x24: case 0x25: case 0x26:
        case 0x39: case 0x50: case 0x54: case 0x5b: case 0x81:
        case 0x91: case 0x95: case 0xc9: case 0xcb: case 0xdf:
        case 0xe9: case 0xf4: case 0xf6: case 0x103: case 0x114:
        case 0x119: case 0x12e: case 0x13c: case 0x146: case 0x147:
        case 0x184: case 0x185: case 0x186: case 0x187: case 0x18a:
        case 0x19a: case 0x19c: case 0x19f: case 0x1a2: case 0x1b4:
        case 0x1b8: case 0x1b9: case 0x1c2: case 0x1c3: case 0x1cc:
        case 0x1cd: case 0x1ce: case 0x1d4:
            ((CallbackSetDispatch_guess*)handler->target)->Slot001_guess(3);
            return 1;
        default:
            break;
    }
    ((CallbackSetDispatch_guess*)handler->target)->Slot001_guess(1);
    return 1;
}

struct TrigSource_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float angle_guess);
    virtual float Cos_guess(float angle_guess);
};

#define g_trigSource_guess EQ_GLOBAL(TrigSource_guess*, 0x0099E374)


// Whether a spot is clear: no world collision on the line from the spawn to (x, y, z), and no solid
// region at every 2 units walked back from it towards the spawn over `length`. A spell's push-back
// search uses it.
// FUNCTION: TITANIUM 0x0047BB72
int EQPlayerCore_guess::IsPathClear_guess(float x_guess, float y_guess, float z_guess,
                                    float angle_guess, float length_guess) {
    int hit_guess = 0;
    float origin_z_guess = z_0038_guess;
    FloatBits origin_guess;
    origin_guess.bits = *(int*)&y_0030_guess;
    float origin_y_guess = x_0034_guess;
    if (g_spawnDisplay_guess->s3dCollideSphereWithWorld_guess(origin_guess.value, origin_y_guess,
                                              origin_z_guess, x_guess, y_guess, z_guess,
                                              0, 0, 0, 2)) {
        return 0;
    }
    do {
        g_spawnDisplay_guess->GetEnvironment_guess(x_guess, y_guess, z_guess, &hit_guess);
        if (hit_guess != 0) {
            return 0;
        }
        length_guess -= 2.0f;
        float cos_guess = g_trigSource_guess->Cos_guess(angle_guess);
        float sin_guess = g_trigSource_guess->Sin_guess(angle_guess);
        x_guess -= cos_guess + cos_guess;
        y_guess -= sin_guess + sin_guess;
    } while (length_guess > 0.0f);
    return 1;
}

// Asks the actor's model (virtual slot 62, +0xF8) about the spawn's actor tag.
// FUNCTION: TITANIUM 0x0047BC52
int EQPlayerCore_guess::FUN_0047bc52_guess() {
    char text[16];
    GetActorTag_guess(text);
    return handler->target->Slot062_guess(text);
}

// Asks the actor's model (virtual slot 63, +0xFC) about `value` and the spawn's actor tag; 0 without
// a model.
// FUNCTION: TITANIUM 0x0047BC8E
int EQPlayerCore_guess::FUN_0047bc8e_guess(int unused, int value) {
    char text[16];
    if (handler == 0 || handler->target == 0) {
        return 0;
    }
    GetActorTag_guess(text);
    return handler->target->Slot063_guess(value, text);
}

// Position of model point `value` (virtual slot 48 of the actor's model) copied into `output` (3 floats).
// False, with `output` untouched, when there is no model or `value` is -1. Missiles and the cameras use
// it.
// FUNCTION: TITANIUM 0x0047BF6C
char EQPlayerCore_guess::FUN_0047bf6c_guess(int value, float* output) {
    if (handler == 0 || handler->target == 0 || value == -1) {
        return 0;
    }
    float result[3];
    handler->target->Slot048_guess(value, result, 0);
    output[0] = result[0];
    output[1] = result[1];
    output[2] = result[2];
    return 1;
}

// The actor info's +0x16C (a spawn id); 0 without actor info.
// FUNCTION: TITANIUM 0x0047BFBC
int EQPlayerStatusView_guess::GetField16c_guess() {
    if (pActorInfo_01a8_guess != 0) {
        return pActorInfo_01a8_guess->field_16c_guess;
    }
    return 0;
}

// True for the horse races (216 and 472).
// FUNCTION: TITANIUM 0x0047BFD0
bool EQPlayerRaceView_guess::IsHorseRace_guess() {
    return race_0260_guess == 0xd8 || race_0260_guess == 0x1d8;
}

// Loads the race's 18 sounds into actor +0xF20..+0xF64 and preloads them; city-NPC races use their base
// race's set. The local `race` holds the gender (+0x24E). Sounds 10/11 and 15-17 land out of order
// (+0xF4C, +0xF48, then +0xF50..+0xF58): that is the original layout.
// FUNCTION: TITANIUM 0x0047CC37
void EQPlayerRaceView_guess::SetSounds_guess() {
    int type = race_0260_guess;
    switch (type) {
    case 0x2c:
    case 0x37:
    case 0x43:
    case 0x47:
        type = 1;
        break;
    case 0x4d:
        type = 6;
        break;
    case 0x4e:
        type = 3;
        break;
    case 0x51:
        type = 0xb;
        break;
    case 0x5a:
        type = 2;
        break;
    case 0x5c:
        type = 9;
        break;
    case 0x5d:
        type = 10;
        break;
    case 0x5e:
        type = 8;
        break;
    case 0x6a:
        type = 5;
        break;
    case 0x70:
        type = 4;
        break;
    }

    unsigned char race = gender_024e_guess;
    pActorInfo_01a8_guess->field_f20_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0);
    pActorInfo_01a8_guess->field_f24_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 1);
    pActorInfo_01a8_guess->field_f28_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 2);
    pActorInfo_01a8_guess->field_f2c_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 3);
    pActorInfo_01a8_guess->field_f30_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 4);
    pActorInfo_01a8_guess->field_f34_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 5);
    pActorInfo_01a8_guess->field_f38_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 6);
    pActorInfo_01a8_guess->field_f3c_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 7);
    pActorInfo_01a8_guess->field_f40_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 8);
    pActorInfo_01a8_guess->field_f44_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 9);
    pActorInfo_01a8_guess->field_f4c_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 10);
    pActorInfo_01a8_guess->field_f48_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0xb);
    pActorInfo_01a8_guess->field_f5c_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0xc);
    pActorInfo_01a8_guess->field_f60_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0xd);
    pActorInfo_01a8_guess->field_f64_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0xe);
    pActorInfo_01a8_guess->field_f50_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0xf);
    pActorInfo_01a8_guess->field_f54_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0x10);
    pActorInfo_01a8_guess->field_f58_guess = g_resourceLookup_guess->GetRaceValue_guess(type, race, 0x11);

    int index = 0;
    do {
        int resource = g_resourceLookup_guess->GetRaceValue_guess(type, race, index);
        if (resource != 0) {
            g_resourceUser_guess->WaveLoadById_guess(resource, 1);
        }
        ++index;
    } while (index <= 0x11);

    ((EQPlayerCore_guess*)this)->SetCurrentLoopSound_guess(pActorInfo_01a8_guess->field_f20_guess);
    pActorInfo_01a8_guess->field_f70_guess = 0;
}

// True for a horse-race spawn (216/472) whose actor definition is the human male or female model
// (HUM_ACTORDEF / HUF_ACTORDEF).
// FUNCTION: TITANIUM 0x0047CEE4
char EQPlayerRaceView_guess::IsHorseUsingHumanModel_guess() {

    if (IsHorseRace_guess() != 0 && pActorInfo_01a8_guess != 0 &&
        pActorInfo_01a8_guess->actorDef_012c_guess != 0) {
        if (strcmp(pActorInfo_01a8_guess->actorDef_012c_guess->name_008_guess, "HUM_ACTORDEF") != 0 &&
            strcmp(pActorInfo_01a8_guess->actorDef_012c_guess->name_008_guess, "HUF_ACTORDEF") != 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

// PlayerState bits (+0x294; EQEmu: 0x10 instrument, 0x40 primary, 0x80 secondary weapon equipped).
// FUNCTION: TITANIUM 0x0047BFEB
void FlagSet_guess::AddPlayerState_guess(unsigned int value) {
    flags_guess |= value;
}

// Clears the given PlayerState bits.
// FUNCTION: TITANIUM 0x0047BFF8
void FlagSet_guess::RemovePlayerState_guess(unsigned int value) {
    flags_guess &= ~value;
}

// True when any of the given PlayerState bits is set.
// FUNCTION: TITANIUM 0x0047C007
char FlagSet_guess::HasPlayerState_guess(unsigned int value) {
    return (value & flags_guess) != 0;
}

// Stores weapon value `index` (0 primary, 1 secondary) at +0x20C and, with `logFlag`, sends
// OP_WeaponEquip1 (0x6C5E: spawn id, index, value). connection_guess is really SpawnID (+0x258).
// FUNCTION: TITANIUM 0x0047C0C2
void SendState_guess::Send_guess(int index, int value, char logFlag) {
    if (index < 2) {
        values_guess[index] = value;
        if (logFlag != 0) {
            int data[3];
            data[0] = SpawnID;
            data[1] = index;
            data[2] = value;
            FUN_004912b1_guess(EQ_ARRAY(char, 0x00905ca0), OP_WeaponEquip1, data, 0xc, 1);
        }
    }
}

// Sets the hide mode byte (+0x250; 1 is invisible).
// FUNCTION: TITANIUM 0x0047C10D
void SendState_guess::SetHideMode_guess(char value) {
    field_250_guess = value;
}

// Plays up to five effects (count, spell point index into InitSpellPoints_guess's table, flag) on the
// actor; probably from OP_LevelAppearance (0x358E).
// FUNCTION: TITANIUM 0x0047C11A
void EQPlayerCore_guess::PlayLevelAppearance_guess(Input_guess* input) {
    if (handler != 0 && *(int*)handler != 0 && input != 0) {
        Entry_guess* entry = input->entries;
        int remaining = 5;
        do {
            if (entry->count > 0) {
                int value = handler->values[entry->index];
                if (value != 0) {
                    handler->target->Dispatch_guess(entry->count, value, entry->flag);
                }
            }
            ++entry;
        } while (--remaining != 0);
    }
}

// Looks up the model's ten spell effect points by name (SPELLPOINT_DEFAULT, CHEST, HEAD, both hands, both
// feet, both eyes, MOUTH) and keeps their handles in that order.
// FUNCTION: TITANIUM 0x0047C17E
void EQPlayerCore_guess::InitSpellPoints_guess() {
    handler->values[0] = handler->target->Slot077_guess("SPELLPOINT_DEFAULT");
    handler->values[1] = handler->target->Slot077_guess("SPELLPOINT_CHEST");
    handler->values[2] = handler->target->Slot077_guess("SPELLPOINT_HEAD");
    handler->values[3] = handler->target->Slot077_guess("SPELLPOINT_LHAND");
    handler->values[4] = handler->target->Slot077_guess("SPELLPOINT_RHAND");
    handler->values[5] = handler->target->Slot077_guess("SPELLPOINT_LFOOT");
    handler->values[6] = handler->target->Slot077_guess("SPELLPOINT_RFOOT");
    handler->values[7] = handler->target->Slot077_guess("SPELLPOINT_LEYE");
    handler->values[8] = handler->target->Slot077_guess("SPELLPOINT_REYE");
    handler->values[9] = handler->target->Slot077_guess("SPELLPOINT_MOUTH");
}

// The spawn's walk speed (+0x240).
// FUNCTION: TITANIUM 0x0047C2CD
float FloatOwner_guess::GetWalkSpeed_guess() {
    return field_240_guess;
}

// The spawn's bounding radius (+0x1A0) times the actor's scale (+0xC4, 1.0 without actor info).
// FUNCTION: TITANIUM 0x0047C2D4
float FloatScaleOwner_guess::FUN_0047c2d4_guess() {
    return (source_1a8_guess != 0 ? source_1a8_guess->value_0c4_guess : 1.0f) * value_1a0_guess;
}

// The EQ_PC behind pCharInfo (+0x218), through its virtual base's slot 16; 0 for spawns without one.
// FUN_0047c31a_guess is the slot-13 twin.
// FUNCTION: TITANIUM 0x0047C2FB
int EQPlayerPcView_guess::GetPcClient_guess() {
    if (value_218_guess == 0) {
        return 0;
    }
    OffsetLink_guess* first = (OffsetLink_guess*)value_218_guess;
    OffsetLink_guess* second = first->next_004_guess;
    DispatchTarget_guess* target = (DispatchTarget_guess*)((char*)second->next_004_guess + value_218_guess + 4);
    return target->Slot016_guess();
}

// Calls virtual slot 13 of the character object at +0x218 (through its virtual-base offset); 0 when
// there is none.
// FUNCTION: TITANIUM 0x0047C31A
int EQPlayerPcView_guess::FUN_0047c31a_guess() {
    if (value_218_guess == 0) {
        return 0;
    }
    OffsetLink_guess* first = (OffsetLink_guess*)value_218_guess;
    OffsetLink_guess* second = first->next_004_guess;
    DispatchTarget_guess* target = (DispatchTarget_guess*)((char*)second->next_004_guess + value_218_guess + 4);
    return target->Slot013_guess();
}

// Whether this PC has spell effect 57 (levitate) active.
// FUNCTION: TITANIUM 0x0047CF4C
int EQPlayerPcView_guess::IsLevitating_guess() {
    if (field_244_guess == 0) {
        int result = GetPcClient_guess();
        if (result != 0) {
            ResultOwner_guess* owner = (ResultOwner_guess*)result;
            if (owner->command_guess.TotalSpellAffects_guess(0x39, 1, 0, 1) != 0) {
                return true;
            }
        }
    }
    return false;
}

// Next entry in the same hash chain with the same key as `entry`, or null; the player name lookup
// 0x0047C88E walks name matches with it.
// FUNCTION: TITANIUM 0x0047C397
Chain_guess* Chain_guess::FindNext_guess(Chain_guess* entry) {
    int key = entry->key_004_guess;
    for (;;) {
        entry = entry->next_008_guess;
        if (entry == 0) {
            break;
        }
        if (entry->key_004_guess == key) {
            break;
        }
    }
    return entry;
}

// Unlinks (0x004519E8) and frees every node of the list at 0x00905CDC whose owner (+0x60) is the spawn
// `key`. The spawn's destructor calls it.
// FUNCTION: TITANIUM 0x0047C85F
void __fastcall DeleteOwnedEffects_guess(int key) {
    RemovalNode_guess* entry = g_chainList_guess;
    while (entry != 0) {
        RemovalNode_guess* next = entry->next_05c_guess;
        if (key == entry->key_060_guess) {
            entry->Remove_guess();
            free(entry);
        }
        entry = next;
    }
}

// Exact-name lookup in the player hash 0x903E50 (keyed on Name +0x120); get_player in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x0047C88E
int __cdecl GetSpawnByName_guess(const char* text) {
    if (*text == '\0') {
        return 0;
    }

    Chain_guess* entry = g_chainLookup_guess->FindByHash_guess(FUN_00574890_guess(text));
    while (entry != 0) {
        if (FUN_00574950_guess(entry->object_000_guess + 0x120, text) == 0) {
            return (int)entry->object_000_guess;
        }
        entry = g_chainLookup_guess->FindNext_guess(entry);
    }
    return 0;
}

// Exact match first; otherwise the spawn nearest `position` whose name starts with `name` (a leading '#'
// is skipped) and whose Type is at most `limit`.
// FUNCTION: TITANIUM 0x0047C8DF
int __cdecl get_player_partial_name_guess(const char* name, Position_guess* position, int limit) {
    int best;
    float best_d = 9e32f;
    int found = GetSpawnByName_guess(name);
    if (found != 0) {
        return found;
    }
    int len = strlen(name);
    best = 0;
    if (len > 0) {
        for (SearchNode_guess* node = g_searchList_guess; node != 0; node = node->next_214_guess) {
            if ((int)node->field_244_guess > limit) {
                continue;
            }
            const char* text = &node->field_120_guess;
            if (_strnicmp(text, name, len) != 0) {
                if (*text != '#' || _strnicmp(node->text_121_guess, name, len) != 0) {
                    continue;
                }
            }
            float dx = position->field_030_guess - node->field_030_guess;
            float dy = position->field_034_guess - node->field_034_guess;
            float dz = position->field_038_guess - node->field_038_guess;
            float d = dx * dx + dy * dy + dz * dz;
            if (node == g_searchList_guess || d < best_d) {
                best_d = d;
                best = (int)node;
            }
        }
    }
    return best;
}

// Landing sound for a PC: 0x72, or 0x73 for a hard fall (TakeFallDamage_guess(height) >= 1).
// FUNCTION: TITANIUM 0x0047CA9D
void EQPlayerPcView_guess::IHaveFallen_guess(float value) {
    ResultOwner_guess* owner = (ResultOwner_guess*)GetPcClient_guess();
    if (owner != 0) {
        int id = (owner->command_guess.TakeFallDamage_guess(value) >= 1) + 0x72;
        if (field_244_guess != 0) {
            id = -1;
        }
        if (id != -1) {
            PlaySound_guess(id);
        }
    }
}

// Records the region type under the spawn in ActorInfo +0xAD (the previous one in +0xAF; 5 and up are
// water). With levitate state 3, +0x9C is set while out of water. In zone 71 (0x00924470) an NPC that is
// not a horse (race 216/472) gets +0x9C cleared and levitate state 1.
// FUNCTION: TITANIUM 0x0047CAE6
void EQPlayerStatusView_guess::SetRegionType_guess(unsigned char value) {
    pActorInfo_01a8_guess->field_af_guess = pActorInfo_01a8_guess->field_ad_guess;
    pActorInfo_01a8_guess->field_ad_guess = value;
    if (levitate_028c_guess == 3) {
        pActorInfo_01a8_guess->field_9c_guess = pActorInfo_01a8_guess->field_ad_guess < 5;
    }
    if (type_0244_guess == 1 && g_statusCode_guess == 0x47 && pActorInfo_01a8_guess != 0) {
        if (!((EQPlayerRaceView_guess*)this)->IsHorseRace_guess()) {
            pActorInfo_01a8_guess->field_9c_guess = 0;
            levitate_028c_guess = 1;
        }
    }
}

// ArrayClass2 setup: the block size is the next power of two >= `value` (shift +0xC, mask +8).
// FUNCTION: TITANIUM 0x0047C3AF
inline void PowerTable_guess::Initialize_guess(int value) {
    field_00c_guess = 0;
    field_004_guess = 1;
    while (field_004_guess < value) {
        field_004_guess <<= 1;
        ++field_00c_guess;
    }
    field_010_guess = 0;
    field_000_guess = 0;
    field_014_guess = 0;
    field_008_guess = field_004_guess - 1;
    field_018_guess = 1;
}

// Splash sounds: 99 leaving a liquid or entering state 7, 100 entering 5, 6 or 8-10 while moving
// vertically faster than 1.
// FUNCTION: TITANIUM 0x0047CB5F
// @early-stop: budget, structural ndiff=21
void EQPlayerCore_guess::feetEnvironmentChange_guess(unsigned char state) {
    unsigned char old = handler->feetEnvironment_00ae_guess;
    if (old == state) {
        return;
    }
    int effect = -1;
    handler->feetEnvironment_00ae_guess = state;
    if (old > 0 && state == 0) {
        effect = 99;
    }
    switch (state) {
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
        if (velocityZ_0044_guess >= 1.0f || velocityZ_0044_guess <= -1.0f) {
            effect = 100;
        }
        break;
    case 7:
        effect = 99;
        break;
    }
    if (effect != -1) {
        PlaySound_guess(effect);
    }
}

// Detaches this spawn from the effect list 0x905CD0: clears references to it and frees the entries
// owned by its spawn id.
// FUNCTION: TITANIUM 0x0047CBE0
void EQPlayerCore_guess::RemoveFromEffectList_guess() {
    ProcessNode_guess* entry = g_processList_guess;
    while (entry != 0) {
        ProcessNode_guess* next = entry->next_008_guess;
        if (entry->field_050_guess == spawnId_0258_guess) {
            entry->field_050_guess = 0;
        }
        if (entry->link_048_guess != 0) {
            unsigned int* owner = &entry->link_048_guess->owner_0fe8_guess;
            if (*owner == (unsigned int)this) {
                *owner = 0;
            }
        }
        if (entry->field_04c_guess == spawnId_0258_guess) {
            entry->MissileTeardown_guess();
            free(entry);
        }
        entry = next;
    }
}

// True for the horse races (0x0047BFD0).
// FUNCTION: TITANIUM 0x0047CF40
bool EQPlayerRaceView_guess::FUN_0047cf40_guess() {
    return IsHorseRace_guess() != 0;
}

struct NestedState_guess {
    char pad[0x1c];
    int field_344_guess;
    // EXTERNAL: TITANIUM 0x004B73EE NestedState_guess::Reset_guess
    void Reset_guess();
};

#include "titanium/layouts/math.h"
#include "titanium/wnd/CBarterSearchWnd.h"
#include "titanium/wnd/CBodyTintWnd.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CFacePick.h"
#include "titanium/wnd/CFindLocationWnd.h"
#include "titanium/wnd/CInspectWnd.h"
#include "titanium/wnd/CPetInfoWnd.h"
#include "titanium/wnd/CSpellBookWnd.h"
#include "titanium/wnd/CTitleWnd.h"
#include "titanium/wnd/CTrackingWnd.h"

struct ResultObject_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
};

struct Factory_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void Slot018_guess();
    virtual void Slot019_guess(int resource, CVector3* point, float scale,
                               ResultObject_guess** result);
};

struct TransformOwner_guess {
    char pad_000_guess[0x30];
    CVector3 point_030_guess;
    ResultObject_guess* CreateUserLight_guess(int resource, int scale);
};

#define g_factory_guess EQ_GLOBAL(Factory_guess*, 0x0099E368)

// Creates an object from the factory at 0x0099E368 (slot 19) with definition `resource` at the spawn's
// position (+0x30) and size `scale`, calls its first two virtual methods and returns it. Character select
// and creation give their models a light this way.
// FUNCTION: TITANIUM 0x0047E619
ResultObject_guess* TransformOwner_guess::CreateUserLight_guess(int resource, int scale) {
    CVector3 point_guess;
    ResultObject_guess* result = 0;
    point_guess.x = point_030_guess.x;
    point_guess.y = point_030_guess.y;
    point_guess.z = point_030_guess.z;
    g_factory_guess->Slot019_guess(resource, &point_guess, (float)scale, &result);
    result->Slot000_guess();
    result->Slot001_guess();
    return result;
}

// EXTERNAL: TITANIUM 0x0041D3C6 PcCharInfoGate_guess::CanISeeInvis_guess
struct PcCharInfoGate_guess {
    unsigned char CanISeeInvis_guess();
};

struct ActorInfoGate_guess {
    char pad_000_guess[0x106c];
    int field_106c_guess;
    char pad_1070_guess[4];
    int field_1074_guess;
};


struct EQPlayerCheck_guess : EQPlayer {
    char IsInvisibleToMe_guess(EQPlayer* object);
};

// Whether `object` is hidden from this spawn: invisible (+0x250 = 1) unless this one sees invisible
// (0x41D3C6, probably), though a GM stays hidden from non-GMs; actor states +0x106C and +0x1074 hide it from
// all but one spawn id. For a corpse or a dead spawn it clears the target's HideMode as a side effect.
// FUNCTION: TITANIUM 0x0047E7EE
char EQPlayerCheck_guess::IsInvisibleToMe_guess(EQPlayer* object) {
    char result = 0;
    int checked = 0;
    if (object != 0) {
        if (object->Type < 2 && object->HPCurrent >= 1) {
            // Body types 65 and up are never drawn.
            if ((int)object->BodyType >= 0x41) {
                return 1;
            }
            ActorInfoGate_guess* state = (ActorInfoGate_guess*)object->pActorInfo;
            if (state->field_106c_guess != 0) {
                if (pinstCBazaarSearchWnd_guess != 0 && pinstCBazaarSearchWnd_guess->IsHideTraders_guess() != 0) {
                    int spawn = (int)object->SpawnID;
                    if (pinstCBazaarSearchWnd_guess->GetValue_guess() != spawn) {
                        return 1;
                    }
                }
            } else if (state->field_1074_guess != 0 && pinstCBarterSearchWnd_guess != 0 &&
                       pinstCBarterSearchWnd_guess->field_1D4_guess != 0 &&
                       pinstCBarterSearchWnd_guess->field_1D0_guess != (int)object->SpawnID) {
                return 1;
            }
            if (pCharInfo != 0) {
                checked = ((PcCharInfoGate_guess*)pCharInfo)->CanISeeInvis_guess();
            }
            if (object->HideMode == 1) {
                result = 1;
                if (checked != 0) {
                    result = 0;
                    if (object->GM != 0 && GM == 0) {
                        result = 1;
                    }
                }
            }
            return result;
        }
        object->HideMode = 0;
    }
    return 0;
}

struct StateOwner_guess {
    char pad[0x328];
    NestedState_guess nested_guess;
    void Clear_guess();
};

// Clears +0x344 of the nested state and resets it.
// FUNCTION: TITANIUM 0x0047E8E0
void StateOwner_guess::Clear_guess() {
    nested_guess.field_344_guess = 0;
    nested_guess.Reset_guess();
}

// ArrayClass2 default constructor: blocks of 32.
// FUNCTION: TITANIUM 0x0047E8F2
PowerTable_guess::PowerTable_guess() {
    Initialize_guess(0x20);
}

struct ProfileText_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 ProfileText_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ProfileText_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ProfileText_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 ProfileText_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E1640 ProfileText_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x005E0E90 ProfileText_guess::GetSkill_guess
    int GetSkill_guess();
    // EXTERNAL: TITANIUM 0x005EC850 ProfileText_guess::GetDamage_guess
    int GetDamage_guess(int flag);
    // EXTERNAL: TITANIUM 0x005EC620 ProfileText_guess::Load_guess
    void Load_guess(struct SkillRequest_guess* request);
    // EXTERNAL: TITANIUM 0x005E10E0 ProfileText_guess::GetLeftValue_guess
    int GetLeftValue_guess();
    // EXTERNAL: TITANIUM 0x005E1110 ProfileText_guess::GetRightValue_guess
    int GetRightValue_guess();
};

struct SkillRequest_guess {
    char pad_000_guess[0x12d];
    unsigned char skill_12d_guess;
    char pad_12e_guess[5];
    unsigned char baseDamage_0133_guess;
    unsigned char field_134_guess;
};

#define g_skillItem_guess EQ_GLOBAL(ProfileText_guess*, 0x00903E30)
#define g_skillRequest_guess EQ_GLOBAL(SkillRequest_guess*, 0x00903E34)

struct ProfileNames_guess {
    char pad_000_guess[0x2c];
    ProfileText_guess* field_02c_guess;     // 0x03c
    ProfileText_guess* field_030_guess;     // 0x040
    ProfileText_guess* field_034_guess;     // 0x044
    ProfileText_guess* field_038_guess;     // 0x048
    char pad_03c_guess[0x18];
    ProfileText_guess* field_054_guess;     // 0x064
    ProfileText_guess* GetFirst_guess() { return field_02c_guess; }
    ProfileText_guess* GetSecond_guess() { return field_034_guess; }
    ProfileText_guess* GetThird_guess() { return field_038_guess; }
    ProfileText_guess* GetRange_guess() { return field_054_guess; }
    ProfileText_guess* GetAmmo_guess() { return field_030_guess; }
};

struct CharInfo2_guess {
    char pad_000[0x10];
    ProfileNames_guess names_010_guess;
    char pad_068[0xfc0 - 0x68];
    int field_fc0;
    char pad_fc4[0x1128 - 0xfc4];
    int field_1128_guess;
    char pad_112c[0x1214 - 0x112c];
    int field_1214;
    char pad_1218[0x1280 - 0x1218];
    unsigned char field_1280;
    char pad_1281[3];
    int field_1284;
};

struct PlayerSpawn_guess {
    char pad_000_guess[0x1a8];
    void* actor_1a8_guess;
};

struct PlayerSlot_guess {
    char pad_000_guess[0x130];
    int count_130_guess;
};

#define g_slotTable_guess EQ_ARRAY(PlayerSlot_guess*, 0x00851200)

// pCharInfo points at the +0xC280 view: vfptr at +0, vbptr at +4, virtual base at +0xC384.
struct PlayerBase_guess : EQ_Character {
    CharInfo2_guess* GetProfile_guess() { return (CharInfo2_guess*)GetCharInfo2(); }
    // EXTERNAL: TITANIUM 0x0040CC50 PlayerBase_guess::GetInventorySlot_guess
    ProfileText_guess* GetInventorySlot_guess(int kind);
    char pad_00c_guess[0xf0];
    char state_0fc_guess;       // 0x0fc of the virtual base (0x100 from the PlayerCtx view)
};

struct PlayerCtx_guess : virtual PlayerBase_guess {
    virtual void Slot000_guess();
    PlayerSpawn_guess* spawn_008_guess;
    // EXTERNAL: TITANIUM 0x0041C8F4 PlayerCtx_guess::HasSkillChecked_guess
    int HasSkillChecked_guess(int index);
    // EXTERNAL: TITANIUM 0x0041EF86 PlayerCtx_guess::GetSkillBaseDamage_guess
    unsigned char GetSkillBaseDamage_guess(unsigned char skill, int target);
    // EXTERNAL: TITANIUM 0x0041EDAC PlayerCtx_guess::CheckDualWield_guess
    char CheckDualWield_guess(int target);
    // EXTERNAL: TITANIUM 0x0041EE86 PlayerCtx_guess::CanDoubleAttack_guess
    char CanDoubleAttack_guess(int target, unsigned char kind);
};

struct SkillDelay_guess {
    int field_000_guess;
    int delay_004_guess;
};

#define g_skillDelays_guess EQ_ARRAY(SkillDelay_guess*, 0x00851200)

struct AttackState_guess {
    char pad_000_guess[0x60];
    unsigned int timer_060_guess;
    char pad_064_guess[0x39];
    unsigned char kind_09d_guess;
    char pad_09e_guess[0x3e];
    unsigned int timer_0dc_guess;
    char pad_0e0_guess[0x34];
    unsigned int timer_114_guess;
    int delay_118_guess;
    char pad_11c_guess[0x1034 - 0x11c];
    int field_1034_guess;
    char pad_1038_guess[4];
    int field_103c_guess;
    char pad_1040_guess[0x3c];
    int field_107c_guess;
};

struct RangeCheck_guess {
    // EXTERNAL: TITANIUM 0x00439D16 RangeCheck_guess::PlayerDistance_guess
    float PlayerDistance_guess(EQPlayerCore_guess* from, int target, float zero);
};

struct AutoAttack_guess {
    // EXTERNAL: TITANIUM 0x0049994C AutoAttack_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value);
};

#define g_rangeCheck_guess EQ_GLOBAL(RangeCheck_guess*, 0x00905D24)
#define g_autoAttack_guess EQ_GLOBAL(AutoAttack_guess, 0x00923770)
#define g_flag92384c_guess EQ_GLOBAL(char, 0x0092384C)
#define g_flag9858c8_guess EQ_GLOBAL(char, 0x009858C8)

// EXTERNAL: TITANIUM 0x0046D655 GetTimeMs_guess
unsigned int __cdecl GetTimeMs_guess();
// EXTERNAL: TITANIUM 0x004753F0 DoMissileHit_guess
void __cdecl DoMissileHit_guess(EQPlayerCore_guess* owner, int target, ProfileText_guess* item, unsigned char kind);
struct TimerCell_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 TimerCell_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECCF0 TimerCell_guess::GetState_guess
    int GetState_guess();
    // EXTERNAL: TITANIUM 0x005E0E00 TimerCell_guess::GetDuration_guess
    int GetDuration_guess();
};

// Attack delay after haste (effect 11) and, for a ranged attack, the quiver's reduction.
// EQPlayer::ModifyAttackSpeed in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x0047F01E
// @early-stop: budget, structural ndiff=34
unsigned int EQPlayerCore_guess::ModifyAttackSpeed_guess(int delay, int ranged) {
    PlayerCtx_guess* ctx = pCharInfo_0218_guess;
    unsigned int result = delay;
    if (delay != 0) {
        delay = ((Command_guess*)ctx)->TotalSpellAffects_guess(0xb, 1, 0, 1);
        if (delay > 0) {
            result = (unsigned int)((float)result / ((float)delay * EQ_GLOBAL(float, 0x00640038)));
        }
        if (ranged != 0) {
            // Quivers: inventory slots 22-29, a container of type 2 with a weight reduction.
            for (delay = 0x16; delay < 0x1e; ++delay) {
                if (ctx->GetInventorySlot_guess(delay) != 0) {
                    if (((TimerCell_guess*)ctx->GetInventorySlot_guess(delay))->GetItemClass_guess() == 1) {
                        TimerCell_guess* cell = (TimerCell_guess*)ctx->GetInventorySlot_guess(delay);
                        if (cell->GetState_guess() == 2 && cell->GetDuration_guess() > 0) {
                            delay = cell->GetDuration_guess();
                            unsigned int used = (unsigned int)((float)result *
                                ((float)delay * EQ_GLOBAL(float, 0x00648108)));
                            unsigned int remaining = result - (used + 1);
                            // The reduction never brings the delay to 1000 or below.
                            if (remaining > 0x3e8) {
                                result = remaining;
                            }
                            return result;
                        }
                    }
                }
            }
        }
    }
    return result;
}

// Whether the PC may use skill `index` (`value` 100). Bash (10): trolls, ogres and barbarians always;
// others need a shield (item type 8) in the secondary, primary item 11050, 10099 or 14383, or effect 226
// (two-hand bash) with a two-handed weapon.
// FUNCTION: TITANIUM 0x0047F12B
char EQPlayerCore_guess::CanPcUseSkill_guess(int value, int index) {
    if (value == 100) {
        if (g_slotTable_guess[index]->count_130_guess >= 1) {
            if (index == 10 &&
                (race_0260_guess == 9 || race_0260_guess == index || race_0260_guess == 2)) {
                return 1;
            }
            PlayerCtx_guess* ctx = pCharInfo_0218_guess;
            if (ctx != 0) {
                value = ctx->HasSkillChecked_guess(index);
            } else {
                value = 0;
            }
            if (value == 0) {
                return 0;
            }
            if (ctx != 0 && index == 10 && type_0244_guess == 0) {
                if (ctx->GetProfile_guess()->names_010_guess.GetThird_guess() == 0 ||
                    ctx->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemClass_guess() != 0 ||
                    ctx->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemType_guess() != 8) {
                    if (ctx->GetProfile_guess()->names_010_guess.GetSecond_guess() == 0 ||
                        (ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemId_guess() != 0x2b2a &&
                         ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemId_guess() != 0x2773 &&
                         ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemId_guess() != 0x382f)) {
                        value = 0;
                    }
                }
                if (ctx->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0 &&
                    ctx->spawn_008_guess != 0 && ctx->spawn_008_guess->actor_1a8_guess != 0) {
                    if (((Command_guess*)ctx)->TotalSpellAffects_guess(0xe2, 1, 0, 1) != 0) {
                        if (ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 1 ||
                            ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 4 ||
                            ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 0x23) {
                            value = 1;
                        }
                    }
                }
            }
            if (value != 0) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// Armour tint colour of visible slot `index` (0-8): the spawn's own (+0x1BC), but for a PC with a client
// the client's value (0x0043DA4A) wins when it is non-zero. Out of range gives 0.
// FUNCTION: TITANIUM 0x0047FD9B
int EQPlayerPcView_guess::GetArmorTint_guess(int index) {
    int result;
    if (index < 0 || index >= 9) {
        result = 0;
    } else {
        result = values_1bc_guess[index];
        if (field_244_guess == 0 && GetPcClient_guess() != 0) {
            if (((ResultCheck_guess*)GetPcClient_guess())->FUN_0043da4a_guess(index) != 0) {
                result = ((ResultCheck_guess*)GetPcClient_guess())->FUN_0043da4a_guess(index);
            }
        }
    }
    return result;
}

struct SegmentedArray_guess {
    char pad_000_guess[8];
    unsigned int mask_guess;
    unsigned int shift_guess;
    int** segments_guess;
    int* At_guess(int index);
};

// ArrayClass2 element `index`.
// FUNCTION: TITANIUM 0x004814B6
int* SegmentedArray_guess::At_guess(int index) {
    return segments_guess[index >> shift_guess] + (index & mask_guess);
}

struct CursorArray_guess {
    char pad_000_guess[0x328];
    unsigned int count_328_guess;
    char pad_32c_guess[4];
    unsigned int mask_330_guess;
    unsigned int shift_334_guess;
    int** segments_338_guess;
    char pad_33c_guess[8];
    int cursor_344_guess;
    int Next_guess();
};

// Next element of the table at +0x328, round-robin on the cursor +0x344.
// FUNCTION: TITANIUM 0x004828DE
int CursorArray_guess::Next_guess() {
    if (count_328_guess == 0) {
        return 0;
    }
    if (cursor_344_guess >= count_328_guess) {
        cursor_344_guess = 0;
    }
    int index = cursor_344_guess;
    cursor_344_guess = index + 1;
    return segments_338_guess[index >> shift_334_guess][index & mask_330_guess];
}

/* ---- EQPlayer::EQPlayer (0x004850A0) -------------------------------------------------------------
 * Layout: include/titanium/types.h EQPlayer (0x348). The ctor's class needs the members with their
 * constructors, so it is declared here; the other EQPlayer methods of this file are still declared
 * on their per-function view classes. */

// 0x38-byte motion block at +0x30, +0x68, +0xB0, +0xE8 (MQ2 Y/X/Z/Speed*/Heading at +0x30).
struct PlayerVec3_guess {
    float y;
    float x;
    float z;
    void Set_guess(float newY, float newX, float newZ) {
        y = newY;
        x = newX;
        z = newZ;
    }
};

struct PlayerMotion_guess {
    PlayerVec3_guess pos;       // 0x00 (MQ2 Y, X, Z)
    PlayerVec3_guess speed;     // 0x0c (MQ2 SpeedY, SpeedX, SpeedZ)
    float speedRun;     // 0x18
    float heading;      // 0x1c
    float field_20;     // 0x20
    float field_24;     // 0x24
    float field_28;     // 0x28
    float field_2c;     // 0x2c
    int field_30;       // 0x30
    int field_34;       // 0x34
    PlayerMotion_guess() { Reset_guess(); }
    void SetSpeed_guess(float newY, float newX, float newZ) {
        speed.y = newY;
        speed.x = newX;
        speed.z = newZ;
    }
    // EXTERNAL: TITANIUM 0x004519AC PlayerMotion_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x00494593 PlayerMotion_guess::Copy_guess
    void Copy_guess(PlayerMotion_guess* source);
};

#pragma pack(push, 1)
struct MotionUpdatePrefix_guess {
    unsigned short field_000_guess;
    unsigned short field_002_guess;
    char pad_004_guess[2];
    int field_006_guess;
};

struct MotionUpdate_guess {
    union {
        MotionUpdatePrefix_guess prefix_000_guess;
        char pad_000_guess[0x0a];
    };
    float amount_00a_guess;
    float angle_00e_guess;
    float angle_012_guess;
    unsigned char type_016_guess;
    char pad_017_guess[4];
    short field_01b_guess;
    char pad_01d_guess;
    unsigned char flags_01e_guess;
};
#pragma pack(pop)

// ArrayClass2-style table at +0x328 (count, alloc, mask, shift, blocks, ?, flag) + cursor at +0x344.
// Clear_guess is the class's inline cleanup; VC keeps it out of line (a COMDAT that the linker took from
// another object at 0x004B73EE): tests/unicorn/crt_defaults.json aliases its symbol to that address.
struct PlayerTable_guess {
    int field_000;          // 0x00
    int alloc_004;          // 0x04
    int mask_008;           // 0x08
    int shift_00c;          // 0x0c
    char** blocks_010;      // 0x10
    int blockCount_014;     // 0x14
    unsigned char flag_018; // 0x18
    int cursor_01c;         // 0x1c
    PlayerTable_guess(int size) { ((PowerTable_guess*)this)->Initialize_guess(size); }
    ~PlayerTable_guess() { Clear_guess(); }
    void Clear_guess() {
        int index = 0;
        if (blockCount_014 > 0) {
            do {
                delete[] blocks_010[index];
                index++;
            } while (index < blockCount_014);
        }
        delete[] blocks_010;
        blocks_010 = 0;
        blockCount_014 = 0;
        field_000 = 0;
    }
};

struct CharacterBase_guess : EQ_Character {
    CharInfo2_guess* GetProfile_guess() { return (CharInfo2_guess*)GetCharInfo2(); }
    char pad_00c[0x30];
    char name_03c[0x40];        // 0x03c
    char pad_07c[0x80];
    char field_0fc_guess;       // 0x0fc, vbptr-relative (+8) is 0x104 in the view
    int zone_100;               // 0x100
    // EXTERNAL: TITANIUM 0x0040E75C CharacterBase_guess::FUN_0040e75c_guess
    void FUN_0040e75c_guess(int type, int value);
};

struct PcCharInfo_guess {
    int field_000;
    int field_004;
    void* player_008;           // EQ_PC +0xc288
    // EXTERNAL: TITANIUM 0x0041BF92 PcCharInfo_guess::InitInnates_guess
    void InitInnates_guess(int race, int playerClass);
    // EXTERNAL: TITANIUM 0x0041AC65 PcCharInfo_guess::DoLight_guess
    void DoLight_guess(unsigned char light);
    // EXTERNAL: TITANIUM 0x0040E934 PcCharInfo_guess::GetSpellAffect_guess
    int GetSpellAffect_guess(int type, int flags);
    // EXTERNAL: TITANIUM 0x0040E934 PcCharInfo_guess::GetSpellAffectText_guess
    int GetSpellAffectText_guess(int type, int* textId);
    // EXTERNAL: TITANIUM 0x00411F2F PcCharInfo_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(int affect);
    // EXTERNAL: TITANIUM 0x004179AA PcCharInfo_guess::NotifyPCAffectChange_guess
    void NotifyPCAffectChange_guess(int textId, int one);
    // EXTERNAL: TITANIUM 0x0041377F PcCharInfo_guess::ReapplyBuffEffects_guess
    void ReapplyBuffEffects_guess(int value);
    // EXTERNAL: TITANIUM 0x0041A44A PcCharInfo_guess::UpdateInvisibility_guess
    void UpdateInvisibility_guess();
    // EXTERNAL: TITANIUM 0x0041C905 PcCharInfo_guess::FUN_0041c905_guess
    void FUN_0041c905_guess(int value, ActorMessage_guess* message, int first, int second,
                            int third, int fourth);
    // EXTERNAL: TITANIUM 0x00414913 PcCharInfo_guess::HitBySpell
    void HitBySpell(const void* update, int value);
};

struct PcPrefix_guess {
    int field_000;
    int field_004;
};

struct PcCore_guess : PcPrefix_guess, virtual CharacterBase_guess {
    char pad_00c[0xe19];
    unsigned char field_e25;    // 0xe25
    char pad_e26[0xb45a];
};

struct PcClient_guess : PcCore_guess, PcCharInfo_guess {
    // EXTERNAL: TITANIUM 0x005F0A50 PcClient_guess::GetSlot_guess
    int GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x005ED860 PcClient_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(int value);
};

struct PcClientAffectView_guess {
    char pad_000_guess[0xc280];
    PcCharInfo_guess affect_0c280_guess;
};
#define g_pcClientAffectView_guess EQ_GLOBAL(PcClientAffectView_guess*, 0x00905D00)

#define g_pcClient_guess EQ_GLOBAL(PcClient_guess*, 0x00905D00)
#define g_stateFlag9239dc_guess EQ_GLOBAL(char, 0x009239DC)
#define g_state923cc4_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_scaleThreshold_guess EQ_GLOBAL(float, 0x00642650)
#define g_scaleBase_guess EQ_GLOBAL(float, 0x00648110)
#define g_scaleFast_guess EQ_GLOBAL(float, 0x0064810C)

// Virtual-call view of the PcCore virtual base; slot 17 sits at +0x44.
struct VBaseCall_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual char Slot017_guess();
};

// False while actor +0xF98 is set (bards excepted), while the PC's state (+0xFC) is 1-4 or 7, for
// corpses, or when the PC's slot-17 test fails; state 1 prints message 0x7D.
// FUNCTION: TITANIUM 0x0047C9C6
// @early-stop: budget, structural ndiff=38
char EQPlayerCore_guess::CanAttack_guess(int unused_guess) {
    if (handler->castingSpellId_0f98_guess != -1 && playerClass_0252_guess != 8) {
        return 0;
    }
    PlayerCtx_guess* ctx = pCharInfo_0218_guess;
    if (ctx != 0) {
        if (type_0244_guess == 0 && ctx->state_0fc_guess == 1) {
            token_string_to_client_guess(ctx, 0x7d, 0xd, 0);
            return 0;
        }
        if (type_0244_guess == 0) {
            if (ctx->state_0fc_guess == 2 || ctx->state_0fc_guess == 3 || ctx->state_0fc_guess == 4) {
                return 0;
            }
        }
    }
    if (type_0244_guess > 1) {
        return 0;
    }
    if (type_0244_guess == 0) {
        int found = ((EQPlayerPcView_guess*)this)->GetPcClient_guess();
        if (found != 0) {
            PcCore_guess* result = (PcCore_guess*)found;
            char state = result->field_0fc_guess;
            if (state == 7 || state == 4) {
                return 0;
            }
            CharacterBase_guess* base = result;
            if (((VBaseCall_guess*)base)->Slot017_guess() != 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Drops the player's invisibility effects (12, 28, 29, 314-316) and effect 94; if hidden, also unhides
// and prints string 0x318A.
// FUNCTION: TITANIUM 0x00479AF3
void __cdecl BreakInvisibility_guess() {
    if (g_pcClient_guess != 0) {
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0xc, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x1c, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x1d, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x13a, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x13b, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x13c, 0));
        g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x5e, 0));
    }
    if (g_stateFlag9239dc_guess != 0 || g_state923cc4_guess == 0x1d) {
        if (g_state923cc4_guess == 0x1d) {
            g_state923cc4_guess = -1;
        }
        g_stateFlag9239dc_guess = 0;
        g_pcClient_guess->FUN_005ed860_guess(0);
        g_pcClient_guess->UpdateInvisibility_guess();
        pEverQuest->dsp_chat(pStringTable->getString(0x318a, 0), 0x10e, 1);
    }
}

struct ActorDispatch_guess {
    // EXTERNAL: TITANIUM 0x0044AB0B ActorDispatch_guess::SetHeight_guess
    void SetHeight_guess(float height);
};

#define ACTOR_VISUAL_SLOT(n) virtual void Slot##n##_guess();
struct ActorVisual_guess {
    ACTOR_VISUAL_SLOT(000) ACTOR_VISUAL_SLOT(001) ACTOR_VISUAL_SLOT(002) ACTOR_VISUAL_SLOT(003)
    ACTOR_VISUAL_SLOT(004) ACTOR_VISUAL_SLOT(005) virtual void Slot006_guess(char value); ACTOR_VISUAL_SLOT(007)
    ACTOR_VISUAL_SLOT(008) ACTOR_VISUAL_SLOT(009) ACTOR_VISUAL_SLOT(010) ACTOR_VISUAL_SLOT(011)
    ACTOR_VISUAL_SLOT(012) ACTOR_VISUAL_SLOT(013) ACTOR_VISUAL_SLOT(014) ACTOR_VISUAL_SLOT(015)
    ACTOR_VISUAL_SLOT(016) ACTOR_VISUAL_SLOT(017) ACTOR_VISUAL_SLOT(018) ACTOR_VISUAL_SLOT(019)
    ACTOR_VISUAL_SLOT(020) ACTOR_VISUAL_SLOT(021) ACTOR_VISUAL_SLOT(022) ACTOR_VISUAL_SLOT(023)
    ACTOR_VISUAL_SLOT(024) ACTOR_VISUAL_SLOT(025) ACTOR_VISUAL_SLOT(026) ACTOR_VISUAL_SLOT(027)
    ACTOR_VISUAL_SLOT(028) ACTOR_VISUAL_SLOT(029) ACTOR_VISUAL_SLOT(030) ACTOR_VISUAL_SLOT(031)
    ACTOR_VISUAL_SLOT(032) ACTOR_VISUAL_SLOT(033) ACTOR_VISUAL_SLOT(034) ACTOR_VISUAL_SLOT(035)
    ACTOR_VISUAL_SLOT(036) ACTOR_VISUAL_SLOT(037) ACTOR_VISUAL_SLOT(038) ACTOR_VISUAL_SLOT(039)
    ACTOR_VISUAL_SLOT(040) ACTOR_VISUAL_SLOT(041) ACTOR_VISUAL_SLOT(042) ACTOR_VISUAL_SLOT(043)
    ACTOR_VISUAL_SLOT(044) ACTOR_VISUAL_SLOT(045) ACTOR_VISUAL_SLOT(046) ACTOR_VISUAL_SLOT(047)
    virtual void GetPosition_guess(int type, float* position, int flag);
    ACTOR_VISUAL_SLOT(049) ACTOR_VISUAL_SLOT(050) ACTOR_VISUAL_SLOT(051) ACTOR_VISUAL_SLOT(052)
    ACTOR_VISUAL_SLOT(053) ACTOR_VISUAL_SLOT(054) ACTOR_VISUAL_SLOT(055) ACTOR_VISUAL_SLOT(056)
    ACTOR_VISUAL_SLOT(057) ACTOR_VISUAL_SLOT(058) ACTOR_VISUAL_SLOT(059) ACTOR_VISUAL_SLOT(060)
    ACTOR_VISUAL_SLOT(061) ACTOR_VISUAL_SLOT(062) ACTOR_VISUAL_SLOT(063) ACTOR_VISUAL_SLOT(064)
    virtual char Slot065_guess(const char* name, int field, bool flag, bool isType3, bool isType2);
    ACTOR_VISUAL_SLOT(066) ACTOR_VISUAL_SLOT(067)
    virtual int GetCount_guess();
    virtual void SetText_guess(char* appearance, char* count, int value);
    ACTOR_VISUAL_SLOT(070) ACTOR_VISUAL_SLOT(071) ACTOR_VISUAL_SLOT(072)
    ACTOR_VISUAL_SLOT(073) ACTOR_VISUAL_SLOT(074) ACTOR_VISUAL_SLOT(075) ACTOR_VISUAL_SLOT(076)
    ACTOR_VISUAL_SLOT(077) ACTOR_VISUAL_SLOT(078) ACTOR_VISUAL_SLOT(079) ACTOR_VISUAL_SLOT(080)
    virtual void Slot081_guess(unsigned char* color); ACTOR_VISUAL_SLOT(082) ACTOR_VISUAL_SLOT(083) ACTOR_VISUAL_SLOT(084)
    virtual char HasPosition_guess(int type);
    ACTOR_VISUAL_SLOT(086) ACTOR_VISUAL_SLOT(087) ACTOR_VISUAL_SLOT(088) ACTOR_VISUAL_SLOT(089)
    ACTOR_VISUAL_SLOT(090) ACTOR_VISUAL_SLOT(091) ACTOR_VISUAL_SLOT(092) ACTOR_VISUAL_SLOT(093)
    ACTOR_VISUAL_SLOT(094) ACTOR_VISUAL_SLOT(095) ACTOR_VISUAL_SLOT(096) ACTOR_VISUAL_SLOT(097)
    ACTOR_VISUAL_SLOT(098) ACTOR_VISUAL_SLOT(099) ACTOR_VISUAL_SLOT(100) ACTOR_VISUAL_SLOT(101)
    ACTOR_VISUAL_SLOT(102) ACTOR_VISUAL_SLOT(103) ACTOR_VISUAL_SLOT(104) ACTOR_VISUAL_SLOT(105)
    ACTOR_VISUAL_SLOT(106) ACTOR_VISUAL_SLOT(107) ACTOR_VISUAL_SLOT(108) ACTOR_VISUAL_SLOT(109)
    virtual void Apply_guess(int value);
};
#undef ACTOR_VISUAL_SLOT

struct Attachment_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Update_guess(int value);
};

struct ActorInfo_guess {
    union {
        int actorInstance_0000_guess;
        ActorVisual_guess* visual_000_guess;
    };
    union {
        char pad_004[4];
        Attachment_guess* light_0004_guess;
    };
    char actorName_008_guess[0x40];
    float floorHeight_0048_guess;            // 0x048
    char pad_04c[0x10];
    unsigned int nextFidgetTime_005c_guess;     // 0x05c
    char pad_060[8];
    int deathTime_0068_guess;              // 0x068
    char pad_06c[4];
    unsigned int sitStartTime_0070_guess; // 0x070
    char pad_074[0x10];
    int field_084;              // 0x084
    char pad_088[4];
    int field_08c;              // 0x08c
    char pad_090[8];
    float field_098;            // 0x098
    unsigned char field_09c;    // 0x09c
    char pad_09d[0xf];
    unsigned char headEnvironment_00ac_guess;
    unsigned char field_0ad_guess;
    char pad_0ae[2];
    unsigned char field_0b0_guess;
    char pad_0b1[0xb];
    float field_0bc_guess;      // 0x0bc
    float field_0c0_guess;      // 0x0c0
    float heightScale_00c4_guess;
    char pad_0c8[0x20];
    int slots_0e8[10];          // 0x0e8
    char pad_110[0x0c];
    unsigned int lastUpdate_11c_guess;
    char pad_120[0x0c];
    void* actorDef_012c_guess;    // 0x12c
    // EXTERNAL: TITANIUM 0x0048F019 ActorInfo_guess::FUN_0048f019_guess
    int FUN_0048f019_guess();
    char pad_130[4];
    int currentAnimation_0134_guess;              // 0x134
    int field_138_guess;        // 0x138
    int field_13c_guess;        // 0x13c
    int field_140_guess;        // 0x140
    int field_144_guess;        // 0x144
    int field_148_guess;        // 0x148
    char pad_14c_guess[9];
    unsigned char field_155;
    char pad_156_guess[2];
    void* field_158;            // 0x158
    void* mount_015c_guess;            // 0x15c
    void* rider_0160_guess;            // 0x160
    char pad_164[8];
    int field_16c;              // 0x16c
    void* field_170;                    // 0x170
    void* field_174[3];                 // 0x174
    void* field_180[3];                 // 0x180
    void* field_18c[3];                 // 0x18c
    void* field_198;                    // 0x198
    unsigned char field_19c;    // 0x19c
    char pad_19d[0x13];
    float ceilingHeight_01b0_guess;            // 0x1b0
    ActorDispatch_guess* dispatch_1b4;  // 0x1b4
    char pad_1b8[0xd04];
    unsigned int field_ebc_guess;
    float field_ec0_guess;      // 0xec0
    char pad_ec4_guess[4];
    int field_ec8_guess;
    char pad_ecc_guess[0xbc];
    int field_f88_guess;        // 0xf88
    char pad_f8c_guess[8];
    ActorStatus_guess* status_f94_guess;
    char pad_f98_guess[0x50];
    EQPlayerCore_guess* followTarget_0fe8_guess;   // 0xfe8
    float field_fec_guess;
    char pad_ff0_guess[4];
    float followDistance_0ff4_guess;
    char pad_ff8_guess[0x0c];
    unsigned char field_1004_guess;
    char pad_1005_guess[0x2b];
    int field_1030;             // 0x1030
    char pad_1034[0xc];
    int field_1040_guess;
    char pad_1044[0x28];
    int field_106c;             // 0x106c
    char pad_1070[4];
    int field_1074;             // 0x1074
    char pad_1078[0x48];
    // EXTERNAL: TITANIUM 0x0048F023 ActorInfo_guess::ActorInfo_guess
    ActorInfo_guess(char* actorDef);
    // EXTERNAL: TITANIUM 0x0048F4A4 ActorInfo_guess::~ActorInfo_guess
    ~ActorInfo_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

struct ItemListBase_guess {
    virtual ~ItemListBase_guess();
    // EXTERNAL: TITANIUM 0x005ECE20 ItemListBase_guess::ItemListBase_guess
    ItemListBase_guess();
    char pad_004[0xa4];
};

// EXTERNAL: TITANIUM 0x00644780 ??_7EQ_Item_guess@@6B@
struct EQ_Item_guess : ItemListBase_guess {
    virtual void Slot001_guess();
};

struct ItemRegistry_guess {
    char pad_000[0x2c4];
    // EXTERNAL: TITANIUM 0x00601F60 ItemRegistry_guess::ItemRegistry_guess
    ItemRegistry_guess();
};

#define g_itemList_guess EQ_GLOBAL(EQ_Item_guess*, 0x00903E30)
#define g_itemRegistry_guess EQ_GLOBAL(ItemRegistry_guess*, 0x00903E34)
#define g_playerLock_guess EQ_ARRAY(CRITICAL_SECTION, 0x0090422C)

static float FloorAt_guess(float y, float x, float z) {
    return g_display2_guess->GetFloorHeight_guess(y, x, z);
}

static float FloorBelow_guess(float y, float x, float z) {
    return g_display2_guess->GetCeilingHeight_guess(y, x, z, 0.5f);
}


// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
void __cdecl FUN_0046d655_guess();

struct PlayerAttachment_guess {
    virtual ~PlayerAttachment_guess();
    int value_004_guess;
    char pad_008_guess[0x10];
    virtual void Apply_guess(int type, int first, int second, float amount, int finalValue);
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void SetPosition_guess(PlayerVec3_guess* position);
    virtual void Slot019_guess();
    virtual void Slot020_guess();
    virtual PlayerVec3_guess* GetPosition_guess();
    // EXTERNAL: TITANIUM 0x00488974 PlayerAttachment_guess::PlayAnimation_guess
    void PlayAnimation_guess(int type, int first, int second, float amount, int finalValue);
};

#pragma pack(push, 1)
struct SpawnStruct_guess {
    unsigned char field_000_guess;
    unsigned char gm_0001_guess;
    unsigned char pad_002_guess;
    unsigned char aaTitle_0003_guess;
    unsigned char field_004_guess;
    signed char anon_0005_guess;
    unsigned char face_0006_guess;
    char name_007[0x40];
    int deity_0047_guess;
    float size_004b_guess;
    int field_04f_guess;
    unsigned char npc_0053_guess;
    unsigned char invis_0054_guess;
    unsigned char hairColor_0055_guess;
    signed char curHp_0056_guess;
    unsigned char field_057_guess;
    unsigned char findable_0058_guess;
    char pad_059_guess[5];
    unsigned int flags_05e_guess;
    unsigned int flags_062_guess;
    char pad_066_guess[0x0c];
    unsigned char eyeColor1_0072_guess;
    int ids_073_guess[6];
    unsigned char showHelm_008b_guess;
    int field_08c_guess;
    unsigned char field_090_guess;
    unsigned char hairStyle_0091_guess;
    unsigned char beardColor_0092_guess;
    int field_093_guess;
    unsigned char level_0097_guess;
    int playerState_0098_guess;
    unsigned char beard_009c_guess;
    char suffix_009d_guess[0x20];
    int petOwnerId_00bd_guess;
    int guildRank_00c1_guess;
    int equipment_00c5_guess[9];
    float runSpeed_00e9_guess;
    signed char afk_00ed_guess;
    int guildId_00ee_guess;
    char title_00f2_guess[0x20];
    unsigned char field_112_guess;
    unsigned char helm_0113_guess;
    int values_114_guess[2];
    int race_011c_guess;
    char pad_120_guess[3];
    unsigned char field_123_guess;
    char lastName_0124_guess[0x20];
    float walkSpeed_0144_guess;
    unsigned char field_148_guess;
    unsigned char isPet_0149_guess;
    unsigned char light_014a_guess;
    unsigned char class_014b_guess;
    unsigned char eyeColor2_014c_guess;
    signed char flyMode_014d_guess;
    unsigned char gender_014e_guess;
    int bodyType_014f_guess;
    unsigned char equipChest2_0153_guess;
    int spawnId_0154_guess;
    float boundingRadius_0158_guess;
    int equipmentTint_015c_guess[9];
    unsigned char lfg_0180_guess;
};
#pragma pack(pop)

struct AppearanceUpdate_guess {
    char pad_000_guess[0x44];
    int type_044_guess;
    char gender_048_guess;
    char state_049_guess;
    char field_04a_guess;
    char pad_04b_guess;
    int faceHair_04c_guess;
    unsigned char eyes_050_guess;
    unsigned char hairColor_051_guess;
    unsigned char beardType_052_guess;
    unsigned char beardColor_053_guess;
    float height_054_guess;
    int values_058_guess[9];
    int values_07c_guess[9];
    int class_0a0_guess;
    unsigned int hasValues_0a4_guess;
};

struct PlayerDeathInfo_guess {
    char pad_000_guess[4];
    int value_004_guess;
    int corpseNumber_0008_guess;
};

struct EQPlayer_guess {
    unsigned char field_000;            // 0x000
    unsigned char lastName_0001_guess;            // 0x001
    char pad_002[0x22];
    float field_024;                    // 0x024
    float field_028;                    // 0x028
    float field_02c;                    // 0x02c
    PlayerMotion_guess motion_030;      // 0x030
    PlayerMotion_guess motion_068;      // 0x068
    char pad_0a0[0x10];
    PlayerMotion_guess motion_0b0;      // 0x0b0
    PlayerMotion_guess motion_0e8;      // 0x0e8
    char name_120[0x40];                // 0x120
    char pad_160[0x40];
    float boundingRadius_01a0_guess;                    // 0x1a0
    int field_1a4;                      // 0x1a4
    ActorInfo_guess* pActorInfo;        // 0x1a8
    int field_1ac;                      // 0x1ac
    unsigned char canFindLocation_01b0_guess;            // 0x1b0
    unsigned char field_1b1;            // 0x1b1
    unsigned char linkdead_01b2_guess;            // 0x1b2
    unsigned char field_1b3;            // 0x1b3
    unsigned char lfg_01b4_guess;            // 0x1b4
    unsigned char isPet_01b5_guess;            // 0x1b5
    unsigned char isABoat_01b6_guess;            // 0x1b6
    unsigned char field_1b7;            // 0x1b7
    unsigned char showHelm_01b8_guess;            // 0x1b8
    char pad_1b9[3];
    int colors_01bc_guess[9];          // 0x1bc
    int materials_01e0_guess[7];          // 0x1e0
    int primaryModelId_01fc_guess;             // 0x1fc
    int secondaryModelId_0200_guess;             // 0x200
    int zone_204;                       // 0x204
    PlayerAttachment_guess* animation_0208_guess;  // 0x208
    int field_20c[2];                   // 0x20c
    EQPlayer_guess* pNext;              // 0x214
    PcCharInfo_guess* pCharInfo;        // 0x218
    int field_21c;                      // 0x21c
    EQPlayer_guess* pPrev;              // 0x220
    int field_224;                      // 0x224
    float field_228;                    // 0x228
    float stepHeight_022c_guess;                    // 0x22c
    float runSpeed_0230_guess;                    // 0x230
    float eyeHeight_0234_guess;                    // 0x234
    float heightOffset_0238_guess;                    // 0x238
    float avatarHeight;                 // 0x23c
    float walkSpeed;                    // 0x240
    unsigned char type;                 // 0x244
    unsigned char hairColor;            // 0x245
    unsigned char beardColor;           // 0x246
    unsigned char eyeColor1_0247_guess;            // 0x247
    unsigned char eyes;                 // 0x248
    unsigned char eyes2;                // 0x249
    unsigned char beardType;            // 0x24a
    unsigned char holding;              // 0x24b
    unsigned char level;                // 0x24c
    unsigned char faceHair;             // 0x24d
    unsigned char gender;               // 0x24e
    unsigned char pvpFlag;              // 0x24f
    unsigned char hideMode;             // 0x250
    unsigned char standState;           // 0x251
    unsigned char playerClass;          // 0x252
    unsigned char light;                // 0x253
    char equipChest2_0254_guess;                     // 0x254
    char helm_0255_guess;                     // 0x255
    unsigned char gm;                   // 0x256
    unsigned char pad_257;
    unsigned int spawnId;               // 0x258
    int masterId;                       // 0x25c
    int race;                           // 0x260
    int anon;                           // 0x264
    int field_268;                      // 0x268
    int afk_026c_guess;                // 0x26c
    int bodyType;                       // 0x270
    int hpCurrent;                      // 0x274
    int aaTitle_0278_guess;                      // 0x278
    int guildRank_027c_guess;                      // 0x27c
    int deity;                          // 0x280
    int hpMax;                          // 0x284
    int guildId;                        // 0x288
    int levitate;                       // 0x28c
    int field_290;                      // 0x290
    union {
        int playerState_0294_guess;                  // 0x294
        unsigned char flags_294[4];
    };
    int field_298;                      // 0x298
    int field_29c;                      // 0x29c
    int field_2a0;                      // 0x2a0
    char text_2a4[0x20];                // 0x2a4
    char text_2c4[0x20];                // 0x2c4
    unsigned char field_2e4;            // 0x2e4
    unsigned char field_2e5;            // 0x2e5
    char pad_2e6[0x12];
    float field_2f8;
    char pad_2fc[0x28];
    float field_324;                    // 0x324
    PlayerTable_guess table_328;        // 0x328

    EQPlayer_guess(SpawnStruct_guess* source, unsigned char gender, int race, unsigned char playerClass,
                   const char* name);
    ~EQPlayer_guess();
    int SetNameSpriteState(bool show);      // sets the name sprite text
    char SetNameSpriteTint();
    // EXTERNAL: TITANIUM 0x0047CF40 EQPlayer_guess::FUN_0047cf40_guess
    int FUN_0047cf40_guess();
    void MountEQPlayer_guess(EQPlayer_guess* player);
    void ClearMountLinks_guess();
    void ClearOthersReferenceToMe_guess();
    char AttachPlayerToPlayerDag_guess(void* actor, int state);
    void UpdatePlayerVisibility_guess();
    void Dismount_guess();
    void UpdateHairForHelm_guess();
    // EXTERNAL: TITANIUM 0x0048A7F9 EQPlayer_guess::FUN_0048a7f9_guess
    void FUN_0048a7f9_guess();
    void RefreshFacialFeatures_guess();
    void headEnvironmentChange_guess(unsigned char state);
    void SetDefaultITAttachments_guess(int value);
    int SetFacialFeature_guess(unsigned char value, char mode);
    unsigned int SetFeatureColor_guess(unsigned char value, int two);
    void SetAvatarHeight_guess(float value);
    void CreateAnimation_guess(int value);
    PlayerAttachment_guess* GetAnimation_guess();
    int GetAnimationLength_guess(int index);
    // EXTERNAL: TITANIUM 0x0048BB83 EQPlayer_guess::FUN_0048bb83_guess
    char FUN_0048bb83_guess(PlayerMotion_guess* motion, int flags);
    // EXTERNAL: TITANIUM 0x00489A32 EQPlayer_guess::FUN_00489a32_guess
    float FUN_00489a32_guess();
    // EXTERNAL: TITANIUM 0x004898D6 EQPlayer_guess::FUN_004898d6_guess
    PlayerAttachment_guess* FUN_004898d6_guess();
    void PlayIdleFidget_guess();
    char GetModelAtSpawnSpot_guess(char* out, int value);
    void InitTables_guess();
    // EXTERNAL: TITANIUM 0x00489955 EQPlayer_guess::FUN_00489955_guess
    void FUN_00489955_guess();
    void SetName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x0047A6A4 EQPlayer_guess::NextSpawnId_guess
    int NextSpawnId_guess();
    // EXTERNAL: TITANIUM 0x0047D776 EQPlayer_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
    void SetAFK_guess(int value);
    int CopyFrom_guess(SpawnStruct_guess* source);
    // EXTERNAL: TITANIUM 0x0047FA9E EQPlayer_guess::SetHeights_guess
    void SetHeights_guess();
    // EXTERNAL: TITANIUM 0x00489906 EQPlayer_guess::FUN_00489906_guess
    float FUN_00489906_guess();
    // EXTERNAL: TITANIUM 0x004899CC EQPlayer_guess::FUN_004899cc_guess
    float FUN_004899cc_guess();
    void UpdateLight_guess();
    void DisplayWeaponsAndArmor_guess();
    void GetConscious_guess();
    void KnockedOut_guess();
    void IDied_guess(PlayerDeathInfo_guess* message);
    void ApplyIllusion_guess(const AppearanceUpdate_guess* update);
    void ChangeTextures_guess(int a_guess, int b_guess);
    // EXTERNAL: TITANIUM 0x00483556 EQPlayer_guess::ChangePosition_guess
    void ChangePosition_guess(unsigned char state);
    // EXTERNAL: TITANIUM 0x004845D8 EQPlayer_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int index, unsigned int value, unsigned int zero, int field, int one);
    int SwapFace_guess(int value, int oldValue);
    bool SwapHead_guess(int value, int zero, int field, int one);
    int SwapNPCMaterials_guess();
    char SwapMaterial_guess(int part, int texA, int texB, int color, unsigned char variant);
    char UpdateItemSlot_guess(unsigned char action, const char* text, int noReport);
    void UpdateEquipmentDisplay_guess(int type);
    ActorInfoView_guess* GetHandler_guess() { return (ActorInfoView_guess*)pActorInfo; }
    // EXTERNAL: TITANIUM 0x0047CC37 EQPlayer_guess::SetSounds_guess
    void SetSounds_guess();
    // EXTERNAL: TITANIUM 0x0048500B EQPlayer_guess::MakeRiderMountUp_guess
    void MakeRiderMountUp_guess();
    // EXTERNAL: TITANIUM 0x0048A945 EQPlayer_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
    // EXTERNAL: TITANIUM 0x0048C11B EQPlayer_guess::FUN_0048c11b_guess
    void FUN_0048c11b_guess();
    void TurnOffAutoFollow_guess();
    void RandomizeRace_guess();
    PcClient_guess* GetPc_guess() { return (PcClient_guess*)((EQPlayerPcView_guess*)this)->GetPcClient_guess(); }
    char AllowedToAttack_guess(EQPlayer_guess* other, int param3);
    // EXTERNAL: TITANIUM 0x0047994F EQPlayer_guess::NotOnSameDeity_guess
    int NotOnSameDeity_guess(EQPlayer_guess* self, void* entry);
};

#define MOUNT_EMPTY_SLOT(n) virtual void Slot##n##_guess();
struct MountTarget_guess {
    MOUNT_EMPTY_SLOT(000) MOUNT_EMPTY_SLOT(001) MOUNT_EMPTY_SLOT(002) MOUNT_EMPTY_SLOT(003)
    MOUNT_EMPTY_SLOT(004) MOUNT_EMPTY_SLOT(005) virtual void Slot006_guess(int value);
    MOUNT_EMPTY_SLOT(007) MOUNT_EMPTY_SLOT(008) MOUNT_EMPTY_SLOT(009) MOUNT_EMPTY_SLOT(010)
    MOUNT_EMPTY_SLOT(011) MOUNT_EMPTY_SLOT(012) MOUNT_EMPTY_SLOT(013) MOUNT_EMPTY_SLOT(014)
    MOUNT_EMPTY_SLOT(015) MOUNT_EMPTY_SLOT(016) MOUNT_EMPTY_SLOT(017)
    virtual void Slot018_guess(float* position);
    MOUNT_EMPTY_SLOT(019) MOUNT_EMPTY_SLOT(020) MOUNT_EMPTY_SLOT(021) MOUNT_EMPTY_SLOT(022)
    MOUNT_EMPTY_SLOT(023) MOUNT_EMPTY_SLOT(024) MOUNT_EMPTY_SLOT(025) MOUNT_EMPTY_SLOT(026)
    MOUNT_EMPTY_SLOT(027) MOUNT_EMPTY_SLOT(028) MOUNT_EMPTY_SLOT(029) MOUNT_EMPTY_SLOT(030)
    MOUNT_EMPTY_SLOT(031) MOUNT_EMPTY_SLOT(032) MOUNT_EMPTY_SLOT(033) MOUNT_EMPTY_SLOT(034)
    MOUNT_EMPTY_SLOT(035) MOUNT_EMPTY_SLOT(036) MOUNT_EMPTY_SLOT(037) MOUNT_EMPTY_SLOT(038)
    MOUNT_EMPTY_SLOT(039) MOUNT_EMPTY_SLOT(040) MOUNT_EMPTY_SLOT(041) MOUNT_EMPTY_SLOT(042)
    MOUNT_EMPTY_SLOT(043) MOUNT_EMPTY_SLOT(044) MOUNT_EMPTY_SLOT(045) MOUNT_EMPTY_SLOT(046)
    MOUNT_EMPTY_SLOT(047) MOUNT_EMPTY_SLOT(048) MOUNT_EMPTY_SLOT(049) MOUNT_EMPTY_SLOT(050)
    MOUNT_EMPTY_SLOT(051) MOUNT_EMPTY_SLOT(052) MOUNT_EMPTY_SLOT(053) MOUNT_EMPTY_SLOT(054)
    MOUNT_EMPTY_SLOT(055) MOUNT_EMPTY_SLOT(056) MOUNT_EMPTY_SLOT(057) MOUNT_EMPTY_SLOT(058)
    MOUNT_EMPTY_SLOT(059) MOUNT_EMPTY_SLOT(060) MOUNT_EMPTY_SLOT(061) MOUNT_EMPTY_SLOT(062)
    MOUNT_EMPTY_SLOT(063) MOUNT_EMPTY_SLOT(064) MOUNT_EMPTY_SLOT(065) MOUNT_EMPTY_SLOT(066)
    MOUNT_EMPTY_SLOT(067) MOUNT_EMPTY_SLOT(068) MOUNT_EMPTY_SLOT(069) MOUNT_EMPTY_SLOT(070)
    MOUNT_EMPTY_SLOT(071) MOUNT_EMPTY_SLOT(072) MOUNT_EMPTY_SLOT(073) MOUNT_EMPTY_SLOT(074)
    MOUNT_EMPTY_SLOT(075) MOUNT_EMPTY_SLOT(076) MOUNT_EMPTY_SLOT(077) MOUNT_EMPTY_SLOT(078)
    MOUNT_EMPTY_SLOT(079) MOUNT_EMPTY_SLOT(080) MOUNT_EMPTY_SLOT(081) MOUNT_EMPTY_SLOT(082)
    virtual void Slot083_guess(int value, const char* text);
    MOUNT_EMPTY_SLOT(084)
    virtual char Slot085_guess(int value);
    MOUNT_EMPTY_SLOT(086)
    virtual void Slot087_guess(int index, int value);
    MOUNT_EMPTY_SLOT(088)
    virtual void Slot089_guess(int index, int value);
};
#undef MOUNT_EMPTY_SLOT

// Attaches this spawn to `actor`'s rider point (0x12, <tag>RIDER_DAG): copies the mount's position when
// already mounted on it, else links the actor.
// FUNCTION: TITANIUM 0x0047E668
// @early-stop: budget, structural ndiff=38
char EQPlayer_guess::AttachPlayerToPlayerDag_guess(void* actor, int state) {
    char name[16];
    char buffer[64];
    EQPlayer* other = (EQPlayer*)actor;
    EQPlayer* self = (EQPlayer*)this;
    if (actor != 0 &&
        ((ActorInfo_guess*)self->pActorInfo)->actorInstance_0000_guess != 0 &&
        (state != -1 ||
         (((EQPlayerRaceView_guess*)other)->IsHorseRace_guess() != 0 &&
          (((ActorInfo_guess*)self->pActorInfo)->mount_015c_guess == other ||
           (((EQPlayerCore_guess*)this)->FUN_0047a387_guess() == 0 &&
            ((EQPlayerRaceView_guess*)this)->IsHorseUsingHumanModel_guess() == 0)) &&
          (((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot085_guess(0x12) != 0
               ? ((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot085_guess(0x12) != 0
               : (((EQPlayerCore_guess*)other)->GetActorTag_guess(name),
                  sprintf(buffer, "%sRIDER_DAG", name),
                  ((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot083_guess(0x12, buffer),
                  ((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot085_guess(0x12) != 0))))) {
        if (((ActorInfo_guess*)self->pActorInfo)->actorInstance_0000_guess != 0) {
            if (((ActorInfo_guess*)self->pActorInfo)->mount_015c_guess == other) {
                self->Y = other->Y;
                self->X = other->X;
                self->Z = other->Z;
                self->SpeedY = other->SpeedY;
                self->SpeedX = other->SpeedX;
                self->SpeedZ = other->SpeedZ;
                self->SpeedRun = other->SpeedRun;
                ((MountTarget_guess*)((ActorInfo_guess*)self->pActorInfo)->visual_000_guess)->Slot018_guess(&self->Y);
                ((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot087_guess(0x12, 0);
            } else {
                ((MountTarget_guess*)((ActorInfo_guess*)other->pActorInfo)->visual_000_guess)->Slot089_guess(0x12, (int)((ActorInfo_guess*)self->pActorInfo)->actorInstance_0000_guess);
                if ((this == (EQPlayer_guess*)g_callbackTarget_guess ||
                     this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CF8)) &&
                    EQ_GLOBAL(int, 0x00850CCC) == 0) {
                    ((MountTarget_guess*)((ActorInfo_guess*)self->pActorInfo)->visual_000_guess)->Slot006_guess(1);
                }
            }
            return 1;
        }
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x00465304 unpack_physics_guess
void __cdecl unpack_physics_guess(float* position, unsigned int* values, EQPlayer_guess* player);

// EXTERNAL: TITANIUM 0x00495CC3 SubmitEffectEmitters_guess
void __cdecl SubmitEffectEmitters_guess(int id, int type, int actor, EQPlayer_guess* first,
                                EQPlayer_guess* second, float* position,
                                int zero1, int zero2, int zero3);

// Fills the spawn from a Titanium Spawn_Struct (`source`). Position bits with the marker 0x42 / 0x210
// return 2 (the ctor then sets actor +0x1030 = 6). A playable race with a chest texture (+0x254)
// wears it on body slots 1-6.
// FUNCTION: TITANIUM 0x004816D7
// @early-stop: budget, structural ndiff=38
int EQPlayer_guess::CopyFrom_guess(SpawnStruct_guess* source) {
    int result = 1;
    if (source == 0) {
        return 0;
    }

    avatarHeight = source->size_004b_guess;
    faceHair = source->face_0006_guess;
    walkSpeed = source->walkSpeed_0144_guess;
    runSpeed_0230_guess = source->runSpeed_00e9_guess;
    for (int index = 0; index < 9; ++index) {
        ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(index, source->equipmentTint_015c_guess[index]);
        ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(index, source->equipment_00c5_guess[index]);
    }
    spawnId = source->spawnId_0154_guess;
    bodyType = source->bodyType_014f_guess;
    masterId = source->petOwnerId_00bd_guess;
    hpCurrent = source->curHp_0056_guess;
    hpMax = 100;
    hairColor = source->hairColor_0055_guess;
    beardColor = source->beardColor_0092_guess;
    eyeColor1_0247_guess = source->eyeColor1_0072_guess;
    eyes = source->eyeColor2_014c_guess;
    eyes2 = source->hairStyle_0091_guess;
    beardType = source->beard_009c_guess;
    field_1b7 = source->field_112_guess;
    showHelm_01b8_guess = source->showHelm_008b_guess;
    holding = source->field_000_guess;
    deity = source->deity_0047_guess;
    guildId = source->guildId_00ee_guess;
    guildRank_027c_guess = source->guildRank_00c1_guess;
    ((EQPlayerRaceView_guess*)this)->SetRace_guess(source->race_011c_guess);
    type = source->npc_0053_guess;
    playerClass = source->class_014b_guess;
    gender = source->gender_014e_guess;
    level = source->level_0097_guess;
    hideMode = source->invis_0054_guess;
    field_1b1 = source->field_004_guess;
    pvpFlag = source->field_148_guess;
    standState = source->field_057_guess;
    light = source->light_014a_guess;
    anon = source->anon_0005_guess;
    SetAFK_guess(source->afk_00ed_guess);
    lfg_01b4_guess = source->lfg_0180_guess;
    isPet_01b5_guess = source->isPet_0149_guess;
    linkdead_01b2_guess = source->field_090_guess;
    gm = source->gm_0001_guess;
    levitate = source->flyMode_014d_guess;
    equipChest2_0254_guess = source->equipChest2_0153_guess;
    helm_0255_guess = source->helm_0113_guess;
    FUN_0060e450_guess((char*)&lastName_0001_guess, source->lastName_0124_guess);
    aaTitle_0278_guess = source->aaTitle_0003_guess;
    PlayerMotion_guess* motion = &motion_030;
    motion->pos.y = 0.0f;
    motion->pos.x = 0.0f;
    motion->pos.z = 0.0f;
    motion->heading = 0.0f;
    motion->field_20 = 0.0f;
    motion->speedRun = 0.0f;
    motion->speed.y = 0.0f;
    motion->speed.x = 0.0f;
    motion->speed.z = 0.0f;
    motion->field_28 = 0.0f;
    motion->field_24 = 0.0f;
    motion->field_2c = 0.0f;
    field_1b3 = source->field_123_guess == 1;
    canFindLocation_01b0_guess = source->findable_0058_guess;
    playerState_0294_guess = source->playerState_0098_guess;
    field_298 = source->field_08c_guess;
    field_29c = source->field_093_guess;
    field_2a0 = source->field_04f_guess;
    boundingRadius_01a0_guess = source->boundingRadius_0158_guess;
    for (int index = 0; index < 2; ++index) {
        field_20c[index] = source->values_114_guess[index];
    }
    EQ_GLOBAL(int, 0x009006AC) = 1;
    if ((source->flags_062_guess & 0x1ff80000) == 0x02100000 &&
        (source->flags_05e_guess & 0x3ff) == 0x42) {
        result = 2;
        source->flags_062_guess &= 0xe007ffff;
        source->flags_05e_guess &= 0xfffffc00;
    }
    unpack_physics_guess(&motion->pos.y, &source->flags_05e_guess, this);
    EQ_GLOBAL(int, 0x009006AC) = 0;

    if (equipChest2_0254_guess > -1 && ((EQPlayerCore_guess*)this)->LegalPlayerRace_guess(-1) != 0) {
        for (int index = 0; index < 9; ++index) {
            int value = source->equipment_00c5_guess[index];
            if (index > 0 && index <= 6) {
                value = equipChest2_0254_guess;
            }
            ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(index, value);
            ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(index, source->equipmentTint_015c_guess[index]);
        }
        equipChest2_0254_guess = -1;
    } else {
        for (int index = 0; index < 9; ++index) {
            ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(index, source->equipment_00c5_guess[index]);
            ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(index, source->equipmentTint_015c_guess[index]);
        }
    }

    int* id = &source->ids_073_guess[0];
    int remaining = 6;
    do {
        int actor = *id;
        if (actor != 0 && actor < EQ_GLOBAL(int, 0x0085139C)) {
            int actorAddress = actor * 0x10c + EQ_GLOBAL(int, 0x00851398);
            if (actorAddress != 0) {
                float position[3];
                position[0] = motion_030.pos.y;
                position[1] = motion_030.pos.x;
                position[2] = motion_030.pos.z;
                SubmitEffectEmitters_guess(actor, 2, actorAddress, this, this, position, 0, 0, 0);
            }
        }
        ++id;
    } while (--remaining != 0);

    ((EQPlayerRaceView_guess*)this)->SetTitle_guess(source->title_00f2_guess);
    ((TextBufferOwner_guess*)this)->SetSuffix_guess(source->suffix_009d_guess);
    return result;
}

struct TraitSet_guess {
    // EXTERNAL: TITANIUM 0x004B8F3B TraitSet_guess::GetByIndex_guess
    int GetByIndex_guess(int index);
};

#define g_traitSet_guess EQ_GLOBAL(TraitSet_guess*, 0x00985C50)

// Non-player-race appearance (texture +0x254 0-30, head +0x255): picks the head on multi-head models and
// applies the texture set; race 60 always uses texture 0.
// FUNCTION: TITANIUM 0x00482722
// @early-stop: budget, structural ndiff=73
int EQPlayer_guess::SwapNPCMaterials_guess() {
    char appearance[16];
    char count[4];
    int limit = 0;
    int index = 0;
    if (pActorInfo == 0 || pActorInfo->visual_000_guess == 0) {
        return 0;
    }
    if (equipChest2_0254_guess < 0 || equipChest2_0254_guess > 30) {
        return 0;
    }
    if (race == 0x3c && equipChest2_0254_guess > 0) {
        equipChest2_0254_guess = 0;
    }
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(appearance);
    sprintf(count, "%02d", (int)equipChest2_0254_guess);
    if (pActorInfo->visual_000_guess->GetCount_guess() >= 1) {
        if (pActorInfo->visual_000_guess->GetCount_guess() > 1 && helm_0255_guess >= 0) {
            limit = 4;
            if (race == 0x16c) {
                limit = 5;
            }
            if (limit > 0) {
                do {
                    if (SwapHead_guess((int)helm_0255_guess, index, 0, 1) != 0) {
                        break;
                    }
                    ++index;
                } while (index < limit);
            }
        }
        index = 0;
        int value = 0;
        if (field_298 > index) {
            value = g_traitSet_guess->GetByIndex_guess(field_298 - 1);
        }
        pActorInfo->visual_000_guess->SetText_guess(appearance, count, value);
        pActorInfo->visual_000_guess->Apply_guess((int)equipChest2_0254_guess);
        if ((char)pActorInfo->FUN_0048f019_guess() != 0 && pActorInfo->currentAnimation_0134_guess != 0x92) {
            GetAnimation_guess()->PlayAnimation_guess(0x6e, 0, 0, 1.0f, 0);
        }
        if (g_display2_guess->field_2d58_guess != 0 && bodyType != 8 && bodyType != 3 &&
            bodyType != 5 && bodyType != 0xc) {
            ((EQPlayerCore_guess*)this)->FUN_0047b8d5_guess((int)EQ_ARRAY(char, 0x006974CC));
        }
        return 1;
    }
    return 0;
}

struct MagicEntry_guess {
    char pad_000_guess[0x120];
    int id_120_guess;
    char pad_124_guess[0x59];
    unsigned char field_17d_guess;
    // EXTERNAL: TITANIUM 0x0044E77B MagicEntry_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int value);
};

struct MagicLookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 MagicLookup_guess::GetSpell_guess
    MagicEntry_guess* GetSpell_guess(int id);
};

struct ZoneInfo_guess {
    // EXTERNAL: TITANIUM 0x005F6BC0 ZoneInfo_guess::FUN_005f6bc0_guess
    char FUN_005f6bc0_guess(int zone);
};

struct PcRoot_guess {
    // EXTERNAL: TITANIUM 0x004BB226 PcRoot_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(const char* name);
};

struct CharInfoVBase_guess {
    char pad_000_guess[0x10c];
    unsigned char field_10c_guess;
};

struct CharInfoView_guess : virtual CharInfoVBase_guess {
    virtual void Slot000_guess();
    EQPlayer_guess* player_008_guess;
};

#define g_magicLookup_guess EQ_GLOBAL(MagicLookup_guess*, 0x00985CC8)
#define g_zoneInfo_guess EQ_GLOBAL(ZoneInfo_guess*, 0x00905CC0)
#define g_combatFlag_guess EQ_GLOBAL(unsigned char, 0x009238E0)
#define g_combatSpawnId_guess EQ_GLOBAL(int, 0x009238D8)
#define g_gameMode_guess EQ_GLOBAL(int, 0x00900478)

// EXTERNAL: TITANIUM 0x0060F81E FUN_0060f81e_guess
int __cdecl FUN_0060f81e_guess(int value);

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value);

// Recomputes the size-dependent values: default size, actor scale, the race overrides, a speed factor
// (actor +0xEC0, at least 0.3) and the sneak modifier. Ships (race 72) in zones 84, 93, 96 and 110 set
// actor +0xF88.
// FUNCTION: TITANIUM 0x0047FA9E
// @early-stop: budget, structural ndiff=11
void EQPlayer_guess::SetHeights_guess() {
    int zero = 0;
    stepHeight_022c_guess = 0.0f;
    if (pActorInfo != 0) {
        if (race == 0x8d) {
            ((EQPlayerStatusView_guess*)this)->SetLevitate_guess(2);
            pActorInfo->field_08c = 4;
            pActorInfo->field_098 = 0.005f;
        } else if (isABoat_01b6_guess != 0) {
            pActorInfo->field_09c = zero;
        }
    }
    float actorHeight;
    if (avatarHeight <= 0.0f) {
        avatarHeight = ((EQPlayerCore_guess*)this)->GetDefaultSizeForRace_guess(race, gender);
        actorHeight = avatarHeight;
    } else {
        actorHeight = avatarHeight;
    }
    char actorName[0x20];
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(actorName);
    ScaleProvider_guess* scaleProvider = FUN_004b6cb4_guess(actorName);
    heightOffset_0238_guess = scaleProvider->GetROffset_guess();
    eyeHeight_0234_guess = 6.2f;
    if (pActorInfo != 0) {
        pActorInfo->heightScale_00c4_guess = ((EQPlayerCore_guess*)this)->ScaleFromSize_guess(actorHeight);
        heightOffset_0238_guess = pActorInfo->heightScale_00c4_guess * heightOffset_0238_guess;
        eyeHeight_0234_guess = FUN_004899cc_guess() * pActorInfo->heightScale_00c4_guess;
    }
    float adjustedHeight = -1.0f;
    float heightScale = FUN_004899cc_guess();
    float currentScale = heightOffset_0238_guess;
    float currentHeight = stepHeight_022c_guess;
    ((void (__cdecl *)(int, float*, float*, float*, float*, bool))AdjustHeightsForRace_guess)(
        race, &adjustedHeight, &heightScale, &currentScale, &currentHeight, type == 0);
    eyeHeight_0234_guess = heightScale;
    heightOffset_0238_guess = currentScale;
    stepHeight_022c_guess = currentHeight;
    if (pActorInfo != 0 && adjustedHeight != -1.0f) {
        pActorInfo->heightScale_00c4_guess = adjustedHeight;
    }
    if (pActorInfo != 0) {
        pActorInfo->field_0bc_guess = 1.35f;
        pActorInfo->field_0c0_guess = pActorInfo->field_0bc_guess * 2.5f;
    }
    if (pActorInfo != 0) {
        if (heightOffset_0238_guess >= g_scaleThreshold_guess) {
            pActorInfo->field_ec0_guess = heightOffset_0238_guess * g_scaleBase_guess;
        } else {
            pActorInfo->field_ec0_guess = heightOffset_0238_guess * g_scaleFast_guess;
        }
        if (pActorInfo->field_ec0_guess < 0.3f) {
            pActorInfo->field_ec0_guess = 0.3f;
        }
        if (race == 0x48 && g_pcClient_guess != 0) {
            int actorType = g_pcClient_guess->zone_100;
            if (actorType == 0x54 || actorType == 0x60 || actorType == 0x5d || actorType == 0x6e) {
                pActorInfo->field_f88_guess = 1;
            }
        }
        ((EQPlayerCore_guess*)this)->InitSneakMod_guess();
    }
    if (pCharInfo != 0) {
        PcClient_guess* pc = GetPc_guess();
        int profileValue = pc->GetProfile_guess()->field_1128_guess;
        pc->InitInnates_guess(race, playerClass);
        pc->FUN_0040e75c_guess(10, profileValue);
    }
    if (heightOffset_0238_guess == 0.0f) {
        heightOffset_0238_guess = 0.1f;
    }
}

struct EQPlayerView_guess : EQPlayer {
    void FollowPlayerAI_guess();
    unsigned int TouchingSwitch_guess();
};

struct HeadingMath_guess {
    // EXTERNAL: TITANIUM 0x00439C41 HeadingMath_guess::TrueDistance_guess
    float TrueDistance_guess(float y_guess, float x_guess, float z_guess,
        float other_y_guess, float other_x_guess, float other_z_guess, float zero_guess);
    // EXTERNAL: TITANIUM 0x00436628 HeadingMath_guess::HeadingDiff_guess
    float HeadingDiff_guess(float current_guess, float target_guess, float* difference_guess);
    // EXTERNAL: TITANIUM 0x004365DB HeadingMath_guess::FixHeading_guess
    float FixHeading_guess(float heading_guess);
};

#define g_headingMath_guess EQ_GLOBAL(HeadingMath_guess*, 0x00905D24)

struct AngleFunctions_guess {
    virtual float Slot000_guess(float value);
    virtual float Slot001_guess(float value);
    virtual float Cos_guess(float value);
    virtual float Sin_guess(float value);
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual float Angle_guess(float distance_guess, float delta_guess, float* output_guess);
};

#define g_angleFunctions_guess EQ_GLOBAL(AngleFunctions_guess*, 0x0099E374)
#define g_appearanceEnabled_guess EQ_GLOBAL(int, 0x00924818)
#define g_headingFactor_guess EQ_GLOBAL(float, 0x00641138)
#define g_headingStep_guess EQ_GLOBAL(float, 0x00641134)
#define g_player905cf8_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905CF8)

struct EQPlayerMotion_guess : EQPlayer {
    void TriggerSpellEffect_guess(const MotionUpdate_guess* update);
    char IWasHit_guess(const MotionUpdate_guess* update);
};

struct MotionData_guess {
    char pad_000_guess[4];
    float scale_004_guess;
    char pad_008_guess[0x118];
    int type_120_guess;
    char pad_124_guess[0x5c];
    char active_180_guess;
    char pad_181_guess[5];
    unsigned char appearance_186_guess;
};

struct MotionState_guess {
    char pad_000_guess[0x30];
    float y_030_guess;
    float x_034_guess;
    float z_038_guess;
    char pad_03c_guess[0x215];
    char state_251_guess;
    unsigned char mode_252_guess;
};

struct MotionDataOwner_guess {
    // EXTERNAL: TITANIUM 0x0044CED9 MotionDataOwner_guess::FUN_0044ced9_guess
    int FUN_0044ced9_guess();
};

struct MotionDataLookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 MotionDataLookup_guess::GetSpell_guess
    MotionData_guess* GetSpell_guess(int id);
};

struct MotionPosition_guess {
    float y_guess;
    float x_guess;
    float z_guess;
};

struct MotionStatePair_guess {
    MotionState_guess* state_guess;
    MotionState_guess* target_guess;
};

struct AnimPlayer_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Play_guess(int anim, bool flag, int zero, float speed, int one);
};

#define g_motionDataLookup_guess EQ_GLOBAL(MotionDataLookup_guess*, 0x00985CC8)
#define g_motionAppearanceEnabled_guess EQ_GLOBAL(int, 0x0092446C)

// EXTERNAL: TITANIUM 0x0049B260 DoSpellEffect_guess
void __cdecl DoSpellEffect_guess(int type, MotionData_guess* data, MotionState_guess* state,
                                EQPlayerMotion_guess* player, float* position, int first, int second);

// Cast animation and effect of spell +0x1B for a damage message: the caster animates when standing
// ('d') or 'f'; the effect is placed ahead of the caster or at the target, by the spell's type.
// FUNCTION: TITANIUM 0x0047F4AF
// @early-stop: budget, structural ndiff=62
void EQPlayerMotion_guess::TriggerSpellEffect_guess(const MotionUpdate_guess* update) {
    short id = update->field_01b_guess;
    if (!IsValidSpellIndex_guess(id)) {
        return;
    }

    MotionData_guess* data = g_motionDataLookup_guess->GetSpell_guess(id);
    if (data == 0 || data->active_180_guess == 0) {
        return;
    }

    MotionStatePair_guess actors;
    actors.state_guess = (MotionState_guess*)FUN_00401b28_guess(update->prefix_000_guess.field_002_guess);
    actors.target_guess = (MotionState_guess*)FUN_00401b28_guess(update->prefix_000_guess.field_000_guess);
    if (actors.state_guess != 0 &&
        (actors.state_guess->state_251_guess == 'd' || actors.state_guess->state_251_guess == 'f') &&
        ((MotionDataOwner_guess*)data)->FUN_0044ced9_guess() == 0) {
        g_motionAppearanceEnabled_guess = 1;
        if (actors.state_guess->mode_252_guess != 8 || update->prefix_000_guess.field_006_guess > 10) {
            ((AnimPlayer_guess*)((EQPlayer_guess*)actors.state_guess)->GetAnimation_guess())->Play_guess(
                data->appearance_186_guess, true, 0, 1.0f, 1);
        }
        g_motionAppearanceEnabled_guess = 0;
    }

    MotionPosition_guess position;
    float* positionPtr = 0;
    int type = data->type_120_guess;
    if (type == 0x21 || type == 0x6a || type == 0x6c) {
        position.y_guess = Y + g_angleFunctions_guess->Sin_guess(Heading) * data->scale_004_guess;
        position.x_guess = X + g_angleFunctions_guess->Cos_guess(Heading) * data->scale_004_guess;
        position.z_guess = Z;
        positionPtr = &position.y_guess;
    } else if (type == 0x47) {
        if (actors.target_guess == 0) {
            position.y_guess = Y + g_angleFunctions_guess->Sin_guess(Heading) * data->scale_004_guess;
            position.x_guess = X + g_angleFunctions_guess->Cos_guess(Heading) * data->scale_004_guess;
            position.z_guess = Z;
            positionPtr = &position.y_guess;
        } else {
            position.y_guess = actors.target_guess->y_030_guess;
            position.x_guess = actors.target_guess->x_034_guess;
            position.z_guess = actors.target_guess->z_038_guess;
            positionPtr = &position.y_guess;
        }
    }

    DoSpellEffect_guess(2, data, actors.state_guess, this, positionPtr, 0, 0);
}

struct QueryState_guess {
    // EXTERNAL: TITANIUM 0x005ED820 QueryState_guess::FUN_005ed820_guess
    void FUN_005ed820_guess(int value);
    // EXTERNAL: TITANIUM 0x005ED860 QueryState_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(int value);
};

struct QueryStateDispatch_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual QueryState_guess* Slot016_guess();
};

struct QueryOffset_guess {
    int pad_000_guess;
    int offset_004_guess;
};

struct QueryDispatchRoot_guess {
    char pad_000_guess[8];
    union {
        QueryOffset_guess* offset_008_guess;
        unsigned char entries_008_guess[1];
    } dispatch_008_guess;
};

// EXTERNAL: TITANIUM 0x0048C130 FUN_0048c130_guess
void __stdcall FUN_0048c130_guess(float* speed, int count);

// Turns toward `other` (heading and pitch) when both are within range of the current bearing; returns
// how many of the two were (0-2) and at 2 stores them here and in `output`.
// EQPlayer::AimAtTarget in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x004795BC
// @early-stop: budget, structural ndiff=123
int EQPlayerCore_guess::AimAtTarget_guess(EQPlayerCore_guess* other, HeadingResult_guess* output) {
    float coordinate_guess;
    float angle_guess = 0.0f;
    int result_guess = 0;
    if (type_0244_guess != 0) {
        return 0;
    }
    if (other == 0 || other == this) {
        return 0;
    }

    coordinate_guess = y_0030_guess;
    float this_center_guess = heightOffset_0238_guess * EQ_GLOBAL(float, 0x006410BC) + z_0038_guess;
    float other_center_guess = other->heightOffset_0238_guess * EQ_GLOBAL(float, 0x006410BC) + other->z_0038_guess;
    float other_heading_guess = get_bearing_guess(
        coordinate_guess, x_0034_guess,
        other->velocityY_003c_guess * 2.0f + other->y_0030_guess,
        other->velocityX_0040_guess * 2.0f + other->x_0034_guess);

    bool heading_ok_guess = true;
    float current_heading_guess = heading_004c_guess;
    if (other_heading_guess != current_heading_guess) {
        if (other_heading_guess <= current_heading_guess) {
            if (!(current_heading_guess <= other_heading_guess)) {
                float difference_guess = current_heading_guess - other_heading_guess;
                if (EQ_GLOBAL(float, 0x00641140) < difference_guess) {
                    difference_guess = (EQ_GLOBAL(float, 0x0064113C) - current_heading_guess) +
                        other_heading_guess;
                }
                if (EQ_GLOBAL(float, 0x00647CCC) <= difference_guess) {
                    heading_ok_guess = false;
                }
            }
        } else {
            float difference_guess = other_heading_guess - current_heading_guess;
            if (EQ_GLOBAL(float, 0x00641140) < difference_guess) {
                difference_guess = (EQ_GLOBAL(float, 0x0064113C) - other_heading_guess) +
                    current_heading_guess;
            }
            if (EQ_GLOBAL(float, 0x00647CCC) <= difference_guess) {
                heading_ok_guess = false;
            }
        }
    }
    if (heading_ok_guess) {
        angle_guess = other_heading_guess;
        result_guess = 1;
    }

    coordinate_guess = 0.0f;
    float distance_guess = g_rangeCheck_guess->PlayerDistance_guess(other, (int)this, 0.0f);
    if (distance_guess < EQ_GLOBAL(float, 0x00647CC8)) {
        distance_guess = EQ_GLOBAL(float, 0x00647CC8);
    }
    double height_difference_guess = fabs((double)(this_center_guess - other_center_guess));
    float facing_guess = g_angleFunctions_guess->Angle_guess(
        distance_guess, (float)height_difference_guess, &coordinate_guess);
    facing_guess = (float)fabs((double)(EQ_GLOBAL(float, 0x00641F8C) - facing_guess));
    if (other_center_guess < this_center_guess) {
        facing_guess = -facing_guess;
    }
    double heading_difference_guess = fabs((double)(
        (facing_guess + EQ_GLOBAL(float, 0x00641F8C)) -
        (pitch_005c_guess + EQ_GLOBAL(float, 0x00641F8C))));
    if (EQ_GLOBAL(float, 0x00645ED4) <= heading_difference_guess) {
        facing_guess = 0.0f;
    } else {
        ++result_guess;
    }
    if (result_guess == 2) {
        if (output != 0) {
            output->field_03c_guess = facing_guess;
            output->field_030_guess = facing_guess;
            output->field_02c_guess = angle_guess;
        }
        pitch_005c_guess = facing_guess;
        heading_004c_guess = angle_guess;
    }
    return result_guess;
}

union ByteFloat_guess {
    float float_guess;
    unsigned char byte_guess;
};

// Light source (+0x253): rebuilds the actor's light at the torch point (0x22) or 2 units ahead and 4 up.
// In liquids (actor +0xAD 5-10) only lights 3, 5, 7 and 9+ shine.
// FUNCTION: TITANIUM 0x0047BCE2
// @early-stop: budget, structural ndiff=133
void EQPlayer_guess::UpdateLight_guess() {
    if (g_display2_guess->FUN_0043745d_guess() == 0) {
        return;
    }
    if (g_appearanceEnabled_guess == 0) {
        return;
    }

    bool changed = false;
    unsigned char currentLight;
    if (pActorInfo->light_0004_guess != 0) {
        g_display2_guess->DeleteLight_guess(pActorInfo->light_0004_guess);
        pActorInfo->light_0004_guess = 0;
        ++changed;
    }

    float angle = motion_030.heading;
    angle *= g_headingFactor_guess;
    angle *= g_headingStep_guess;
    float sine = g_angleFunctions_guess->Sin_guess(angle) * 2.0f;
    float cosine = g_angleFunctions_guess->Cos_guess(angle) * 2.0f;
    currentLight = light;

    if (currentLight > 0) {
        unsigned char state = pActorInfo->field_0ad_guess;
        bool specialState = state == 5 || state == 9 || state == 10 ||
            state == 6 || state == 7 || state == 8;
        if (specialState) {
            if (currentLight == 3 || currentLight == 5 || currentLight == 7 || currentLight > 8) {
                if (pActorInfo->visual_000_guess != 0 && pActorInfo->FUN_0048f019_guess() != 0 &&
                    pActorInfo->visual_000_guess->HasPosition_guess(0x22) != 0) {
                    float position[4];
                    pActorInfo->visual_000_guess->GetPosition_guess(0x22, position, 1);
                    ByteFloat_guess lightValue;
                    lightValue.byte_guess = currentLight;
                    pActorInfo->light_0004_guess = g_display2_guess->CreateLightInstance_guess(
                        lightValue.float_guess, 0, position[0], position[1], position[2]);
                } else {
                    float position[3];
                    float baseX = motion_030.pos.y;
                    position[0] = baseX + sine;
                    position[1] = motion_030.pos.x + cosine;
                    position[2] = motion_030.pos.z + 4.0f;
                    ByteFloat_guess lightValue;
                    lightValue.byte_guess = currentLight;
                    pActorInfo->light_0004_guess = g_display2_guess->CreateLightInstance_guess(
                        lightValue.float_guess, 0, position[0], position[1], position[2]);
                }
            }
            changed = true;
        } else {
            if (pActorInfo->visual_000_guess == 0 || pActorInfo->FUN_0048f019_guess() == 0 ||
                pActorInfo->visual_000_guess->HasPosition_guess(0x22) == 0) {
                float position[3];
                float baseX = motion_030.pos.y;
                position[0] = baseX + sine;
                position[1] = motion_030.pos.x + cosine;
                position[2] = motion_030.pos.z + 4.0f;
                ByteFloat_guess lightValue;
                lightValue.byte_guess = currentLight;
                pActorInfo->light_0004_guess = g_display2_guess->CreateLightInstance_guess(
                    lightValue.float_guess, 0, position[0], position[1], position[2]);
            } else {
                float position[4];
                pActorInfo->visual_000_guess->GetPosition_guess(0x22, position, 0);
                ByteFloat_guess lightValue;
                lightValue.byte_guess = currentLight;
                pActorInfo->light_0004_guess = g_display2_guess->CreateLightInstance_guess(
                    lightValue.float_guess, 0, position[0], position[1], position[2]);
            }
            changed = true;
        }
    }

    if (pActorInfo->light_0004_guess == 0) {
        light = 0;
    } else {
        pActorInfo->light_0004_guess->Update_guess(1);
    }
    if (this == g_player905cf8_guess && changed != 0) {
        g_textSink_guess->UpdateAppearance_guess(g_player905cf8_guess, light);
    }
}

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess();
// EXTERNAL: TITANIUM 0x00465538 GetZoneNbrFromTableIndex_guess
int __cdecl GetZoneNbrFromTableIndex_guess(int value);
// EXTERNAL: TITANIUM 0x00465490 DoesS3dZoneFileExist_guess
char __cdecl DoesS3dZoneFileExist_guess(int value);
// EXTERNAL: TITANIUM 0x004654E4 DoesEqgZoneFileExist_guess
char __cdecl DoesEqgZoneFileExist_guess(int value);

// Damage taken: spell damage (type 0xE7) plays the spell's effect; anything else breaks hide, sneak and
// invisibility on the PC and adds the push (+0x0A amount, +0x0E heading, +0x12 pitch) to its speed.
// FUNCTION: TITANIUM 0x0047F614
// @early-stop: budget, structural ndiff=73
char EQPlayerMotion_guess::IWasHit_guess(const MotionUpdate_guess* update) {
    char result = 0;
    int client = ((EQPlayerPcView_guess*)this)->GetPcClient_guess();

    if (update->type_016_guess == 0xe7) {
        TriggerSpellEffect_guess(update);
        if (client != result && (update->flags_01e_guess & 4) != 0) {
            ((PcClientAffectView_guess*)client)->affect_0c280_guess.HitBySpell(update, -1);
        }
    } else if (client != result) {
        PcClientAffectView_guess* clientView = (PcClientAffectView_guess*)client;
        ((ActorInfo_guess*)((EQPlayer*)clientView->affect_0c280_guess.player_008)->pActorInfo)->field_155 =
            (unsigned char)result;
        ((EQPlayer*)clientView->affect_0c280_guess.player_008)->HideMode = (unsigned char)result;
        ((EQPlayer*)clientView->affect_0c280_guess.player_008)->Sneak = (unsigned char)result;
        if (((EQPlayer*)clientView->affect_0c280_guess.player_008)->Type == result) {
            QueryDispatchRoot_guess* root = (QueryDispatchRoot_guess*)client;
            ((QueryStateDispatch_guess*)&root->dispatch_008_guess.entries_008_guess[
                root->dispatch_008_guess.offset_008_guess->offset_004_guess])->Slot016_guess()->FUN_005ed820_guess(result);
            ((QueryStateDispatch_guess*)&root->dispatch_008_guess.entries_008_guess[
                root->dispatch_008_guess.offset_008_guess->offset_004_guess])->Slot016_guess()->FUN_005ed860_guess(result);
        }

        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x0c, result));
        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x1c, result));
        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x1d, result));
        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x13a, result));
        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x13b, result));
        clientView->affect_0c280_guess.RemovePCAffect_guess(
            clientView->affect_0c280_guess.GetSpellAffect_guess(0x13c, result));

        result = 1;
        if (update->amount_00a_guess != EQ_GLOBAL(float, 0x0063F4CC)) {
            SpeedY += g_angleFunctions_guess->Sin_guess(update->angle_00e_guess) *
                      update->amount_00a_guess;
            SpeedX += g_angleFunctions_guess->Cos_guess(update->angle_00e_guess) *
                      update->amount_00a_guess;
            SpeedZ += g_angleFunctions_guess->Cos_guess(update->angle_012_guess) *
                      update->amount_00a_guess;
            EQPlayer* playerThis = this;
            EQPlayer* primary = EQ_GLOBAL(EQPlayer*, 0x00905CE4);
            EQPlayer* secondary = EQ_GLOBAL(EQPlayer*, 0x00905CF8);
            if (playerThis == primary && secondary != primary) {
                EQ_GLOBAL(unsigned char, 0x00923D79) = (unsigned char)result;
            } else if (playerThis == secondary) {
                EQ_GLOBAL(unsigned char, 0x00923D78) = (unsigned char)result;
                FUN_0048c130_guess(&SpeedY, 7);
            }
        }
    }
    return (char)result;
}

// Acts on the door our spawn just touched (ActorInfo +0xF94, cleared on return) by door kind. Kinds 115+
// that 0x004903F1 accepts hurt us through TakeDamage (0x0041C905, damage type 0xFD, amount from the door)
// at most once per 1000 ms for the same door (400 ms if its repop time is shorter). Kind 35 has a 50%
// chance to fire each second; for our own player kind 57 (zone teleport) fires every 2 s if the target
// zone's .s3d or .eqg exists or another destination field is set, and kind 50 fires when closed and is
// marked closed again after its repop time. Returns the ActorInfo pointer.
// FUNCTION: TITANIUM 0x0047F7DC
// @early-stop: budget, structural ndiff=212
unsigned int EQPlayerView_guess::TouchingSwitch_guess() {
    ActorInfo_guess* actor = (ActorInfo_guess*)pActorInfo;
    ActorStatus_guess* status = actor->status_f94_guess;
    unsigned char code = status->type_022_guess;

    if (status->state_023_guess == 4) {
        actor->status_f94_guess = 0;
        return (unsigned int)actor;
    }

    if (code >= 0x73) {
        char allowed = status->FUN_004903f1_guess();
        if (allowed == 0) {
            return (unsigned int)allowed;
        }
        unsigned int wait = 1000;
        if (status->RepopFrequency_guess() < 1000) {
            wait = 400;
        }
        if (g_lastActorStatus_guess == status &&
            (g_display2_guess->frameTime_0148_guess - actor->lastUpdate_11c_guess) < wait) {
            return (unsigned int)actor;
        }

        ActorMessage_guess message;
        g_lastActorStatus_guess = status;
        message.spawnId_000_guess = (unsigned short)SpawnID;
        message.zero_002_guess = 0;
        message.zero_01e_guess = 0;
        message.size_004_guess = 200;
        message.message_006_guess = status->GetSwitchDamage_guess();
        message.zero_00a_guess = 0.0f;
        message.zero_00e_guess = 0.0f;
        message.zero_012_guess = 0.0f;
        message.type_016_guess = 0xfd;
        message.zero_017_guess = 0;
        message.size_019_guess = 200;
        message.state_01b_guess = status->type_022_guess;
        message.zero_01d_guess = 0;
        if (pCharInfo != 0) {
            ((PcCharInfo_guess*)pCharInfo)->FUN_0041c905_guess(
                message.message_006_guess, &message, 1, 0, 1, 1);
        }
        actor->lastUpdate_11c_guess = g_display2_guess->frameTime_0148_guess;
        actor->status_f94_guess = 0;
        return (unsigned int)actor;
    }

    if (code == 0x23) {
        unsigned int now = g_display2_guess->frameTime_0148_guess;
        if ((now - actor->lastUpdate_11c_guess) > 1000) {
            actor->lastUpdate_11c_guess = now;
            if (number_percent_guess() > 0x32) {
                status->UseSwitch_guess(0, 0, 0, 0);
            }
        }
    } else if (code == 0x39) {
        unsigned int now = g_display2_guess->frameTime_0148_guess;
        if ((now - actor->lastUpdate_11c_guess) > 0x7d0) {
            actor->lastUpdate_11c_guess = now;
            if (Type == 0) {
                QueryResult_guess* result = (QueryResult_guess*)((EQPlayerPcView_guess*)this)->GetPcClient_guess();
                if (result != 0) {
                    unsigned int value = 0xffffffff;
                    int cursorAddress = result->header_008_guess->offset_004_guess + (int)result + 8;
                    QueryValue_guess* query = ((EQ_CharacterProfileView_guess*)(cursorAddress + 4))->GetCharInfo2();
                    if (query->object_088_guess != 0) {
                        cursorAddress = result->header_008_guess->offset_004_guess + (int)result + 8;
                        query = ((EQ_CharacterProfileView_guess*)(cursorAddress + 4))->GetCharInfo2();
                        value = query->object_088_guess->GetItemId_guess();
                    }

                    unsigned int index = GetZoneNbrFromTableIndex_guess(status->value_066_guess);
                    char allowed = DoesS3dZoneFileExist_guess(index);
                    if (allowed == 1 || DoesEqgZoneFileExist_guess(index) == 1 ||
                        status->value_0a4_guess >= 1 || status->value_0b4_guess != 0 ||
                        status->flag_0b8_guess != 0) {
                        status->UseSwitch_guess(SpawnID, value, 0, 0);
                    }
                }
            }
        }
    } else if (code == 0x32 && Type == 0) {
        if (status->state_023_guess == 0) {
            status->UseSwitch_guess(SpawnID, 0xffffffff, 0, 0);
            actor->lastUpdate_11c_guess = g_display2_guess->frameTime_0148_guess;
        } else if (status->RepopFrequency_guess() <
                   g_display2_guess->frameTime_0148_guess - actor->lastUpdate_11c_guess) {
            status->state_023_guess = 0;
        }
    }

    actor->status_f94_guess = 0;
    return (unsigned int)actor;
}

// Face, hair, eye and beard setter (`mode` 1 face, 2 hair style, 3 eye colour, else beard): newer
// skeletons swap models, older ones IT attachments (hair 1000+, beard 2000+).
// FUNCTION: TITANIUM 0x00480614
// @early-stop: budget, diff ndiff=16
int EQPlayer_guess::SetFacialFeature_guess(unsigned char value, char mode) {
    if (mode == 1) {
        if (SwapFace_guess(value, faceHair) != 0) {
            if (pActorInfo->actorDef_012c_guess != 0 &&
                ((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess != 0) {
                if (eyeColor1_0247_guess == 0xff || eyeColor1_0247_guess == 0) {
                    eyeColor1_0247_guess = 1;
                    eyes = 1;
                } else {
                    eyes = eyeColor1_0247_guess;
                }
                ((EQPlayerCore_guess*)this)->SetEyeColor_guess(1, eyes);
            }
            return 1;
        }
        return 0;
    }

    if (mode == 2) {
        if ((char)pActorInfo->FUN_0048f019_guess() != 0) {
            return ((EQPlayerCore_guess*)this)->SwapHairStyle_guess(value);
        }
        if (((EQPlayerCore_guess*)this)->SwapHairBeardIT_guess(value + 1000) == 0) {
            eyes2 = 0xff;
            hairColor = 0xff;
            return 0;
        }
        eyes2 = value;
    } else if (mode == 3) {
        if (((EQPlayerCore_guess*)this)->SetEyeColor_guess(1, value) == 0) {
            return 0;
        }
        ((EQPlayerCore_guess*)this)->SetEyeColor_guess(0, value);
    } else {
        if ((char)pActorInfo->FUN_0048f019_guess() != 0) {
            return ((EQPlayerCore_guess*)this)->SwapBeardStyle_guess(value);
        }
        if (((EQPlayerRaceView_guess*)this)->GetBeardKind_guess() != 2) {
            if (((EQPlayerCore_guess*)this)->SwapHairBeardIT_guess(value + 2000) == 0) {
                beardType = 0xff;
                beardColor = 0xff;
                return 0;
            }
            beardType = value;
        }
    }
    return 1;
}

// Colour `value` from the 24-entry palette 0x6989A0 for `two` = 2 hair, 4 beard, 1 face variant (sets the
// face code's tens digit). Hair colours outside the race's range are refused.
// FUNCTION: TITANIUM 0x00480767
// @early-stop: budget, structural ndiff=70
unsigned int EQPlayer_guess::SetFeatureColor_guess(unsigned char value, int two) {
    int first = value;
    int hi;
    unsigned char b = value;
    if (b < 0x18) {
        if ((char)two != 1) {
            ((EQPlayerRaceView_guess*)this)->GetHairColorRange_guess(-1, &first, &hi);
            if ((int)b < first || hi < (int)b) {
                return 0;
            }
        }
    } else if ((char)two != 1) {
        return 0;
    }
    bool tail = false;
    int slot = 0;
    if ((char)two == 4) {
        beardColor = b;
        if (((EQPlayerRaceView_guess*)this)->GetBeardKind_guess() == 2) {
            two = faceHair;
            tail = true;
        } else {
            slot = 9;
        }
    } else if ((char)two == 1) {
        two = (unsigned char)(((EQPlayerCore_guess*)this)->GetBaseFaceNbr_guess(-1, 0) + b * 10);
        tail = true;
    } else {
        slot = 8;
        hairColor = b;
    }
    if (tail) {
        return SetFacialFeature_guess(two, 1);
    }
    if (pActorInfo->visual_000_guess->HasPosition_guess(slot) == 0) {
        return 0;
    }
    return (unsigned char)((EQPlayerCore_guess*)this)->SetAttachmentTint_guess(slot, &EQ_ARRAY(Face_guess, 0x006989A0)[b]);
}

// EXTERNAL: TITANIUM 0x004658DD is_number_guess
int __cdecl is_number_guess(const char* text);

struct ItemCatalog_guess {
    // EXTERNAL: TITANIUM 0x00438A42 ItemCatalog_guess::IsShieldModel_guess
    int IsShieldModel_guess(int itemId);
    // EXTERNAL: TITANIUM 0x00438AF2 ItemCatalog_guess::GetItemTypeCategory_guess
    int GetItemTypeCategory_guess(int itemId);
};
#define g_itemCatalog_guess EQ_GLOBAL(ItemCatalog_guess*, 0x00905D24)
#define g_tintSet_guess EQ_GLOBAL(TraitSet_guess*, 0x00985C54)

struct GameFlags_guess {
    char pad_000_guess[0xb54];
    int field_b54_guess;
};
#define g_gameFlags_guess EQ_GLOBAL(GameFlags_guess*, 0x00988DF0)

struct WearChange_guess {
    int spawnId;
    int flag;
};

struct WearReport_guess {
    short spawnId;
    short itemId;
    int value;
    unsigned char action;
};

// Shows item `text` ("IT<n>") in wear slot `action` (0 head, 1 chest, 7 primary, 8 secondary). For the
// player it also updates PlayerState: 0x10 instrument (item types 0x17-0x1A, the local `twoHanded`), 0x40
// and 0x80 primary and secondary weapon, via OP_PlayerStateAdd (0x63DA) / OP_PlayerStateRemove (0x381D),
// then reports the change with OP_WearChange (0x7441) unless `noReport`.
// FUNCTION: TITANIUM 0x0048083A
// @early-stop: tiebreak, structural ndiff=141
char EQPlayer_guess::UpdateItemSlot_guess(unsigned char action, const char* text, int noReport) {
    char result = 0;
    char is10758 = 0;
    char is10742 = 0;
    char itemName[32];
    char numeric[128];
    char actorName[32];

    if (race == 0x0e) {
        return 0;
    }
    if (GetHandler_guess() == 0 || GetHandler_guess()->target == 0) {
        return 0;
    }

    // Our own weapon slots (7 primary, 8 secondary) also keep the player-state flags the zone sees: 0x10
    // while either hand holds an instrument (item types 23-26), 0x40 / 0x80 while the primary / secondary
    // item is ready; each change goes out as OP_PlayerStateAdd (0x63DA) or OP_PlayerStateRemove (0x381D).
    if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)) {
        switch (action) {
        case 7:
            GetHandler_guess()->field_09d_guess = 0x0d;
            break;
        case 8:
            GetHandler_guess()->field_09d_guess = 0x0b;
            break;
        }
        if (action == 7 || action == 8) {
            WearChange_guess change;
            change.spawnId = EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->spawnId;
            char twoHanded = 0;
            char primaryReady = 0;
            char secondaryReady = 0;
            if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0) {
                if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 0x17 ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 0x1a ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 0x19 ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetItemType_guess() == 0x18) {
                    twoHanded = 1;
                }
                if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->IsReady_guess()) {
                    primaryReady = 1;
                }
            }
            if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess() != 0) {
                if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemType_guess() == 0x17 ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemType_guess() == 0x1a ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemType_guess() == 0x19 ||
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetItemType_guess() == 0x18) {
                    twoHanded = 1;
                }
                if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->IsReady_guess()) {
                    secondaryReady = 1;
                }
            }

            change.flag = 0x10;
            if (twoHanded != 0) {
                if ((playerState_0294_guess & 0x10) == 0) {
                    EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->playerState_0294_guess |= 0x10;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateAdd, &change, 8, 1);
                }
            } else if ((playerState_0294_guess & 0x10) != 0) {
                EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->playerState_0294_guess &= ~0x10;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateRemove, &change, 8, 1);
            }
            change.flag = 0x40;
            if (primaryReady != 0) {
                if ((playerState_0294_guess & 0x40) == 0) {
                    EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->playerState_0294_guess |= 0x40;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateAdd, &change, 8, 1);
                }
            } else if ((playerState_0294_guess & 0x40) != 0) {
                EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->playerState_0294_guess &= ~0x40;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateRemove, &change, 8, 1);
            }
            change.flag = 0x80;
            if (secondaryReady != 0) {
                if ((playerState_0294_guess & 0x80) == 0) {
                    EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->playerState_0294_guess |= 0x80;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateAdd, &change, 8, 1);
                }
            } else if ((playerState_0294_guess & 0x80) != 0) {
                EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)->flags_294[0] &= 0x7f;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_PlayerStateRemove, &change, 8, 1);
            }

            if (primaryReady != 0) {
                int value = g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetLeftValue_guess();
                if (value != field_20c[0]) {
                    ((SendState_guess*)this)->Send_guess(0, value, 1);
                }
            } else if (field_20c[0] != -1) {
                ((SendState_guess*)this)->Send_guess(0, -1, 1);
            }
        }
    }

    FUN_0060e450_guess(itemName, text);
    numeric[0] = 0;
    // Model IT36 shows as IT13 while +0xAD is set.
    if (strcmp(itemName, "IT36") == 0 && GetHandler_guess()->field_0ad_guess != 0) {
        FUN_0060e450_guess(itemName, "IT13");
    }
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(actorName);
    int length = strlen(itemName);
    if (length > 2) {
        int count = 0;
        if (length > 2) {
            count = length - 2;
            for (int i = 0; i < count; i++) {
                numeric[i] = itemName[i + 2];
            }
        }
        numeric[count] = 0;
    }
    int itemId;
    if (is_number_guess(numeric) != 0) {
        itemId = atoi(numeric);
    } else {
        itemId = 0;
    }

    int special = 0;
    int slot;
    int forced;
    if (action == 8 && g_itemCatalog_guess->IsShieldModel_guess(itemId) != 0) {
        if (GetHandler_guess()->target->Slot085_guess(4)) {
            GetHandler_guess()->target->Slot059_guess(4, 0);
        }
        slot = 5;
        forced = 1;
    } else {
        slot = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(action, 0);
        if (action == 8 && GetHandler_guess()->target->Slot085_guess(5)) {
            GetHandler_guess()->target->Slot059_guess(5, 0);
        }
        forced = 0;
        if (slot == -1) {
            return result;
        }
    }

    switch (action) {
    case 0: {
        GetHandler_guess()->target->Slot059_guess(slot, itemName);
        Face_guess face;
        unsigned int color = colors_01bc_guess[0];
        face.red_0002_guess = (unsigned char)(color >> 16);
        face.blue_0000_guess = (unsigned char)color;
        face.green_0001_guess = (unsigned char)(color >> 8);
        face.alpha_0003_guess = 0xff;
        ((EQPlayerCore_guess*)this)->SetAttachmentTint_guess(slot, &face);
        ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(action, itemId);
        break;
    }
    case 1:
        GetHandler_guess()->target->Slot059_guess(slot, itemName);
        ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(action, itemId);
        break;
    case 7:
        if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4) && itemId == 0 &&
            g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess() != 0) {
            if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                          "IT159", 5) == 0) {
                GetHandler_guess()->target->Slot059_guess(slot, "IT159");
                special = 1;
            } else if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                                 "IT10758", 7) == 0) {
                GetHandler_guess()->target->Slot059_guess(slot, "IT10758");
                is10758 = 1;
                special = 1;
            } else if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                                 "IT10742", 7) == 0) {
                GetHandler_guess()->target->Slot059_guess(slot, "IT10742");
                is10742 = 1;
                special = 1;
            }
        }
        GetHandler_guess()->primaryItemType_0f78_guess = g_itemCatalog_guess->GetItemTypeCategory_guess(itemId);
        GetHandler_guess()->primaryModelId_0f80_guess = itemId;
        primaryModelId_01fc_guess = itemId;
        if (special == 0) {
            CallbackResult_guess* model =
                (CallbackResult_guess*)GetHandler_guess()->target->Slot059_guess(slot, itemName);
            int tint = field_29c;
            if (tint > 0 && model != 0) {
                model->Slot053_guess((Face_guess*)g_tintSet_guess->GetByIndex_guess(tint));
            }
        }
        ((EQPlayerCore_guess*)this)->SetAnimVariation_guess();
        break;
    case 8:
        if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4) && (itemId == 0 || forced == 1) &&
            g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess() != 0) {
            if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                          "IT159", 5) == 0) {
                GetHandler_guess()->target->Slot059_guess(4, "IT159");
                special = 1;
            } else if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                                 "IT10758", 7) == 0) {
                GetHandler_guess()->target->Slot059_guess(4, "IT10758");
                is10758 = 1;
                special = 1;
            } else if (_strnicmp(g_pcClient_guess->GetProfile_guess()->names_010_guess.GetAmmo_guess()->GetText_guess(),
                                 "IT10742", 7) == 0) {
                GetHandler_guess()->target->Slot059_guess(4, "IT10742");
                is10742 = 1;
                special = 1;
            }
        }
        GetHandler_guess()->secondaryItemType_0f7c_guess = g_itemCatalog_guess->GetItemTypeCategory_guess(itemId);
        GetHandler_guess()->secondaryModelId_0f84_guess = itemId;
        secondaryModelId_0200_guess = itemId;
        if (special == 0 || forced == 1) {
            CallbackResult_guess* model =
                (CallbackResult_guess*)GetHandler_guess()->target->Slot059_guess(slot, itemName);
            int tint = field_2a0;
            if (tint > 0 && model != 0) {
                model->Slot053_guess((Face_guess*)g_tintSet_guess->GetByIndex_guess(tint));
            }
        }
        ((EQPlayerCore_guess*)this)->SetAnimVariation_guess();
        break;
    default:
        return 0;
    }

    result = 1;
    if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4) && noReport == 0 && g_ownerState_guess == 0 &&
        g_gameFlags_guess->field_b54_guess != 1) {
        // Our own changes are reported as OP_WearChange (0x7441, 9 bytes) unless suppressed.
        WearReport_guess report;
        report.spawnId = (short)spawnId;
        report.action = action;
        if (special == 1) {
            if (is10758 != 0) {
                report.itemId = 0x2a06;
            } else {
                report.itemId = (is10742 != 0 ? 0x29f6 : 0x9f);
            }
        } else {
            report.itemId = (short)itemId;
        }
        report.value = 0;
        if (action == 0) {
            report.value = ((EQPlayerPcView_guess*)this)->GetArmorTint_guess(0);
        } else if (action == 7) {
            if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0) {
                report.value = field_29c =
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetRightValue_guess();
            }
        } else if (action == 8) {
            if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess() != 0) {
                report.value = field_2a0 =
                    g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetRightValue_guess();
            }
        }
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_WearChange, &report, 9, 1);
    }
    return result;
}

// Refreshes the hands after an equipment change: `type` 13/14 (primary/secondary) show both weapons,
// falling back to the range item; 11 (range) shows the range item alone.
// FUNCTION: TITANIUM 0x0048127E
void EQPlayer_guess::UpdateEquipmentDisplay_guess(int type) {
    int hasOne = 0;
    int hasTwo = 0;
    int hasThree = 0;
    char bufferThree[64];
    char bufferOne[64];
    char bufferTwo[64];
    FUN_0060e450_guess(bufferOne, EQ_ARRAY(char, 0x006410A8));
    FUN_0060e450_guess(bufferTwo, EQ_ARRAY(char, 0x006410A8));
    FUN_0060e450_guess(bufferThree, EQ_ARRAY(char, 0x006410A8));
    if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0) {
        FUN_0060e450_guess(bufferOne,
            g_pcClient_guess->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetText_guess());
        hasOne = 1;
    }
    if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess() != 0) {
        FUN_0060e450_guess(bufferTwo,
            g_pcClient_guess->GetProfile_guess()->names_010_guess.GetThird_guess()->GetText_guess());
        hasTwo = 1;
    }
    if (g_pcClient_guess->GetProfile_guess()->names_010_guess.GetFirst_guess() != 0) {
        FUN_0060e450_guess(bufferThree,
            g_pcClient_guess->GetProfile_guess()->names_010_guess.GetFirst_guess()->GetText_guess());
        hasThree = 1;
    }
    if (type == 0xd) {
        if (pActorInfo->currentAnimation_0134_guess == 9) {
            return;
        }
        UpdateItemSlot_guess(7, bufferOne, 0);
        UpdateItemSlot_guess(8, bufferTwo, 0);
        if (hasOne != 0) {
            return;
        }
        if (hasTwo != 0) {
            return;
        }
        if (hasThree == 0) {
            return;
        }
        UpdateItemSlot_guess(8, bufferThree, 0);
    }
    if (type == 0xe) {
        if (pActorInfo->currentAnimation_0134_guess == 9) {
            return;
        }
        UpdateItemSlot_guess(7, bufferOne, 0);
        UpdateItemSlot_guess(8, bufferTwo, 0);
        if (hasOne != 0) {
            return;
        }
        if (hasTwo != 0) {
            return;
        }
        if (hasThree == 0) {
            return;
        }
        UpdateItemSlot_guess(8, bufferThree, 0);
    }
    if (type == 0xb) {
        if (hasThree != 0) {
            UpdateItemSlot_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
            UpdateItemSlot_guess(8, bufferThree, 0);
        } else {
            UpdateItemSlot_guess(7, bufferOne, 0);
            UpdateItemSlot_guess(8, bufferTwo, 0);
        }
    }
}

struct OldPlayerAnimation_guess {
    char pad_000_guess[0x18];
    // EXTERNAL: TITANIUM 0x0044F6D9 OldPlayerAnimation_guess::OldPlayerAnimation_guess
    OldPlayerAnimation_guess(int value);
};

// Replaces the animation helper (+0x208): PlayerAnimation_guess for newer skeletons, else the small one.
// FUNCTION: TITANIUM 0x0047C017
// @early-stop: budget, structural ndiff=23
void EQPlayer_guess::CreateAnimation_guess(int value) {
    if (animation_0208_guess != 0) {
        delete animation_0208_guess;
    }
    if ((char)value != 0) {
        value = (int)new PlayerAnimation_guess((int)this);
    } else {
        value = (int)new OldPlayerAnimation_guess((int)this);
    }
    animation_0208_guess = (PlayerAttachment_guess*)value;
}

// Animation helper (+0x208), created on first use: the newer-skeleton kind when the actor info has
// +0x12C set and 0x0048F019 says so, else the old kind (0x0047C017).
// FUNCTION: TITANIUM 0x0047C08E
PlayerAttachment_guess* EQPlayer_guess::GetAnimation_guess() {
    if (animation_0208_guess == 0) {
        if (pActorInfo != 0 && pActorInfo->actorDef_012c_guess != 0) {
            this->CreateAnimation_guess(pActorInfo->FUN_0048f019_guess());
        } else {
            this->CreateAnimation_guess(0);
        }
    }
    return animation_0208_guess;
}

struct AttachSlots16_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual int Slot004_guess(int value);
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual int Slot010_guess(int value, unsigned char* flag);
};

struct Obj16_guess {
    virtual float Slot000_guess() = 0;
};

struct Entry16_guess {
    Obj16_guess* obj_000_guess;
    char pad_004_guess[12];
};

struct ActorTable16_guess {
    char pad_000_guess[0x2c];
    Entry16_guess** rows_02c_guess;
};

// Length of animation `index` from the model's track table (ActorInfo +0x12C). A missing track falls back
// to the animation the animation set substitutes (its slot 0x10); models flagged by 0x0048F019 map the
// index through the set first. 0 when nothing is found.
// FUNCTION: TITANIUM 0x0047DDD4
// @early-stop: budget, structural ndiff=21
int EQPlayer_guess::GetAnimationLength_guess(int index) {
    if (pActorInfo == 0 || pActorInfo->actorDef_012c_guess == 0) {
        return 0;
    }
    ActorTable16_guess* table = (ActorTable16_guess*)pActorInfo->actorDef_012c_guess;
    unsigned char flag = 0;
    char useAttachment = (char)pActorInfo->FUN_0048f019_guess();
    Obj16_guess* obj = 0;
    int key = 0;
    if (useAttachment != 0) {
        int slot = ((AttachSlots16_guess*)GetAnimation_guess())->Slot004_guess(index);
        Entry16_guess* row = table->rows_02c_guess[slot];
        if (row != 0) {
            obj = row[flag].obj_000_guess;
        }
        if (obj == 0) {
            int value = ((AttachSlots16_guess*)GetAnimation_guess())->Slot010_guess(index, &flag);
            key = ((AttachSlots16_guess*)GetAnimation_guess())->Slot004_guess(value);
        }
    } else {
        Entry16_guess* row = table->rows_02c_guess[index];
        if (row != 0) {
            obj = row[flag].obj_000_guess;
        }
        if (obj == 0) {
            key = ((AttachSlots16_guess*)GetAnimation_guess())->Slot010_guess(index, &flag);
        }
    }
    if (obj == 0) {
        Entry16_guess* row = table->rows_02c_guess[key];
        if (row == 0 || (obj = row[flag].obj_000_guess) == 0 || obj == 0) {
            return 0;
        }
    }
    return (int)obj->Slot000_guess();
}

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int minimum_guess, int maximum_guess);

// Rolls 1-46: up to 12 is that playable race, higher rolls a fixed list (Iksar, Vah Shir, NPC races);
// then the gender (`code` 3: 0-1, 4: 0-2, else fixed) and a new actor.
// FUNCTION: TITANIUM 0x0047FDF6
// @early-stop: budget, structural ndiff=63
void EQPlayer_guess::RandomizeRace_guess() {
    int code = 2;
    int zero = 0;
    int roll = RandomRange_guess(1, 0x2e);
    switch (roll) {
    case 0xd:
        race = 0x80;
        isABoat_01b6_guess = zero;
        avatarHeight = -1.0f;
        code = 3;
        break;
    case 0xe:
        race = 0x82;
        isABoat_01b6_guess = zero;
        avatarHeight = -1.0f;
        code = 3;
        break;
    case 0xf:
        race = 0x55;
        isABoat_01b6_guess = zero;
        break;
    case 0x10:
        race = 0x4b;
        isABoat_01b6_guess = zero;
        break;
    case 0x11:
        race = 0x2a;
        isABoat_01b6_guess = zero;
        break;
    case 0x12:
        race = 0x2b;
        isABoat_01b6_guess = zero;
        break;
    case 0x13:
        race = 0x5b;
        isABoat_01b6_guess = zero;
        break;
    case 0x14:
        race = 0x59;
        isABoat_01b6_guess = zero;
        break;
    case 0x15:
        race = 0x16f;
        isABoat_01b6_guess = zero;
        break;
    case 0x16:
        race = 0xe6;
        isABoat_01b6_guess = zero;
        code = 0;
        break;
    case 0x17:
        race = 0xda;
        isABoat_01b6_guess = zero;
        break;
    case 0x18:
        race = 0xe4;
        isABoat_01b6_guess = zero;
        break;
    case 0x19:
        race = 0xca;
        isABoat_01b6_guess = zero;
        code = 4;
        break;
    case 0x1a:
        race = 0xcd;
        isABoat_01b6_guess = zero;
        break;
    case 0x1b:
        race = 0xdf;
        isABoat_01b6_guess = zero;
        break;
    case 0x1c:
        race = 0xe5;
        isABoat_01b6_guess = zero;
        break;
    case 0x1d:
        race = 0xce;
        isABoat_01b6_guess = zero;
        break;
    case 0x1e:
        race = 0xed;
        isABoat_01b6_guess = zero;
        code = 0;
        break;
    case 0x1f:
        race = 0xcf;
        isABoat_01b6_guess = zero;
        break;
    case 0x20:
        race = 0xc8;
        isABoat_01b6_guess = zero;
        break;
    case 0x21:
        race = 0xdd;
        isABoat_01b6_guess = zero;
        break;
    case 0x22:
        race = 0xe0;
        isABoat_01b6_guess = zero;
        code = 3;
        break;
    case 0x23:
        race = 0xc7;
        isABoat_01b6_guess = zero;
        break;
    case 0x24:
        race = 0xd9;
        isABoat_01b6_guess = zero;
        break;
    case 0x25:
        race = 0xe3;
        isABoat_01b6_guess = zero;
        break;
    case 0x26:
        race = 0xe8;
        isABoat_01b6_guess = zero;
        break;
    case 0x27:
        race = 0xeb;
        isABoat_01b6_guess = zero;
        break;
    case 0x28:
        race = 0xdc;
        isABoat_01b6_guess = zero;
        break;
    case 0x29:
        race = 0xe1;
        isABoat_01b6_guess = zero;
        break;
    case 0x2a:
        race = 0xd7;
        isABoat_01b6_guess = zero;
        break;
    case 0x2b:
        race = 0xd6;
        isABoat_01b6_guess = zero;
        break;
    case 0x2c:
        race = 0xc9;
        isABoat_01b6_guess = zero;
        break;
    case 0x2d:
        race = 0xd0;
        isABoat_01b6_guess = zero;
        code = 0;
        break;
    case 0x2e:
        race = 0xde;
        isABoat_01b6_guess = zero;
        break;
    default:
        avatarHeight = -1.0f;
        if (roll < 0xd) {
            ((EQPlayerRaceView_guess*)this)->SetRace_guess(roll);
        } else {
            race = 1;
            isABoat_01b6_guess = zero;
        }
        code = 3;
        break;
    }
    gender = (unsigned char)code;
    if (code == 1) {
        gender = 2;
    } else if (code == 3) {
        gender = (unsigned char)RandomRange_guess(zero, 1);
    } else if (code == 4) {
        gender = (unsigned char)RandomRange_guess(zero, 2);
    }
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(pActorInfo->actorName_008_guess);
    strcat(pActorInfo->actorName_008_guess, "_ACTORDEF");
    SetHeights_guess();
}

// EXTERNAL: TITANIUM 0x0046E3EB PickRandomValue_guess
int __cdecl PickRandomValue_guess(int first_guess, ...);


struct MotionObject_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual void Slot012_guess();
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual void Slot016_guess();
    virtual void Slot017_guess();
    virtual void Slot018_guess();
    virtual void Slot019_guess();
    virtual void Slot020_guess();
    virtual void Slot021_guess();
    virtual void Slot022_guess(CVector3* point);
    virtual void Slot023_guess();
    virtual float Slot024_guess();
    virtual float Slot025_guess();
    virtual float Slot026_guess();
};

struct MotionFactory_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Slot008_guess();
    virtual void Slot009_guess();
    virtual void Slot010_guess();
    virtual void Slot011_guess();
    virtual bool Slot012_guess(CVector3* point);
    virtual void Slot013_guess();
    virtual void Slot014_guess();
    virtual void Slot015_guess();
    virtual unsigned int Slot016_guess(CVector3* point, float scale, int value, bool flag,
                                       char* out);
};

#define g_motionFactory_guess EQ_GLOBAL(MotionFactory_guess*, 0x0099E368)
#define g_speedBase_guess EQ_GLOBAL(float, 0x00923B74)

// Every 5-15 s picks a random idle animation from the class's list (PickRandomValue_guess picks one of its
// -1-terminated arguments); 0x20 is the plain idle.
// FUNCTION: TITANIUM 0x0047E43E
void EQPlayer_guess::PlayIdleFidget_guess() {
    int play = 0;
    int anim = 0x20;
    if (g_display2_guess->frameTime_0148_guess >= pActorInfo->nextFidgetTime_005c_guess) {
        pActorInfo->nextFidgetTime_005c_guess = RandomRange_guess(5, 15) * 1000 + g_display2_guess->frameTime_0148_guess;
        if (pinstCFacePick_guess->field_1C0_guess != 0) {
            anim = 0x20;
        } else {
            play = 1;
            switch (playerClass) {
            case 1:
            case 0x10:
                anim = PickRandomValue_guess(0x1a, 1, 2, 3, 4, 5, 6, 7, 8, 0x1b, -1);
                break;
            case 7:
                anim = PickRandomValue_guess(0x1a, 1, 0xb, 0x2e, 5, 6, 0x2d, 8, 0x2f, -1);
                break;
            case 9:
                anim = PickRandomValue_guess(0x1a, 2, 5, 6, 8, 4, -1);
                break;
            case 4:
                anim = PickRandomValue_guess(0x1a, 1, 2, 3, 5, 6, 8, 9, 0x2a, 0x2b, 0x2c, -1);
                break;
            case 8:
                anim = PickRandomValue_guess(0x1a, 0x29, 2, 3, 5, 6, 0x27, 0x28, -1);
                break;
            case 3:
            case 5:
                anim = PickRandomValue_guess(0x1a, 2, 3, 5, 6, 7, 8, 0x3c, 0x2a, 0x2b, 0x2c, -1);
                break;
            case 0xf:
                anim = PickRandomValue_guess(0x1a, 1, 2, 3, 5, 6, 8, 0x2a, 0x2b, 0x2c, -1);
                break;
            case 2:
            case 6:
            case 10:
                anim = PickRandomValue_guess(0x1a, 0x2a, 2, 3, 5, 0x2b, 0x2c, 8, -1);
                break;
            case 0xb:
            case 0xc:
            case 0xd:
            case 0xe:
                anim = PickRandomValue_guess(0x1a, 0x2a, 2, 0x2b, 5, 0x45, 0x2c, 8, 0x45, -1);
                break;
            default:
                anim = PickRandomValue_guess(0x1a, 1, 2, 3, 5, 6, 7, 8, -1);
                break;
            }
        }
    }
    if (anim != pActorInfo->currentAnimation_0134_guess) {
        ((AnimPlayer_guess*)GetAnimation_guess())->Play_guess(anim, play != 0, 0, 1.0f, 1);
    }
}

struct AttachmentSlots_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
};

// Turns the name sprite on (state 1) when the display shows names for this kind of spawn (+0x2D5D for
// players, +0x2D5E for others).
// FUNCTION: TITANIUM 0x0047D776
void EQPlayer_guess::RefreshNameSprite_guess() {
    if ((type != 0 && g_display2_guess->field_2d5e_guess != 0) ||
        (type == 0 && g_display2_guess->field_2d5d_guess != 0)) {
        SetNameSpriteState(1);
    }
}

// Sets the AFK flag (+0x26C) and refreshes the name sprite.
// FUNCTION: TITANIUM 0x0047E900
void EQPlayer_guess::SetAFK_guess(int value) {
    afk_026c_guess = value;
    RefreshNameSprite_guess();
}

// Whether this may harm `other` with spell `param3` (-1 melee). Pets act as their top master; NPCs always
// may. For PCs it follows the server ruleset 0x900478: 2 allows 8 levels apart, 4 different deity
// alliances, otherwise both need the PvP flag (+0x24F) and, except ruleset 6, 4 levels or less.
// Below level 6 it mostly fails.
// FUNCTION: TITANIUM 0x0047E912
// @early-stop: budget, structural ndiff=195
char EQPlayer_guess::AllowedToAttack_guess(EQPlayer_guess* other, int param3) {
    EQPlayer_guess* self = this;
    if (other == 0) {
        return 0;
    }
    if (self->pActorInfo == 0) {
        return 0;
    }
    if (other->pActorInfo == 0) {
        return 0;
    }
    unsigned int spawnId = self->spawnId;
    if (other->masterId == spawnId) {
        return 0;
    }
    if ((unsigned int)((EQPlayerCore_guess*)other)->GetTopMasterID_guess() == spawnId) {
        return 0;
    }
    int otherLevel;
    int thisLevel;
    thisLevel = self->level;
    otherLevel = other->level;
    CharInfoView_guess* info = (CharInfoView_guess*)self->pCharInfo;
    if (self->type == 0 && info != 0 && info->field_10c_guess != 0) {
        if (self->pActorInfo == 0) {
            return 1;
        }
        int value = self->pActorInfo->field_1040_guess;
        if (value < 1) {
            return 1;
        }
        return value >= otherLevel;
    }
    info = (CharInfoView_guess*)other->pCharInfo;
    if (other->type == 0 && info != 0 && info->field_10c_guess != 0) {
        ActorInfo_guess* actorInfo = info->player_008_guess->pActorInfo;
        if (actorInfo == 0) {
            return 1;
        }
        int value = actorInfo->field_1040_guess;
        if (value < 1) {
            return 1;
        }
        return value >= thisLevel;
    }
    int levelDiff = FUN_0060f81e_guess(thisLevel - otherLevel);
    if (other->isABoat_01b6_guess != 0) {
        return 0;
    }
    if (self->isABoat_01b6_guess != 0) {
        return 0;
    }
    if (self->type != 1 && self->pActorInfo->field_0ad_guess != other->pActorInfo->field_0ad_guess &&
        param3 != 0x6eb && param3 != -1) {
        if (self->type != 0) {
            return 0;
        }
        if (other->type != 0) {
            return 0;
        }
    }
    if (self->pActorInfo->field_0b0_guess != 0 && other->pActorInfo->field_0b0_guess != 0) {
        if (!IsValidSpellIndex_guess(param3)) {
            return 1;
        }
        MagicEntry_guess* entry = g_magicLookup_guess->GetSpell_guess(param3);
        if (entry != 0 && !entry->FindAffectSlot_guess(0x19)) {
            return 1;
        }
    }
    if (self == other && IsValidSpellIndex_guess(param3)) {
        return 1;
    }
    if (other->type == 1 && other->masterId != 0) {
        EQPlayer_guess* master = (EQPlayer_guess*)FUN_00401b28_guess(
            ((EQPlayerCore_guess*)other)->GetTopMasterID_guess());
        if (master != 0 && master->type == 0) {
            other = master;
            otherLevel = master->level;
        }
    }
    if (self->type == 1 && self->masterId != 0) {
        EQPlayer_guess* master = (EQPlayer_guess*)FUN_00401b28_guess(
            ((EQPlayerCore_guess*)self)->GetTopMasterID_guess());
        if (master != 0 && master->type == 0) {
            self = master;
            thisLevel = master->level;
        }
    }
    if (other->type == 1) {
        return 1;
    }
    if (self->type == 1) {
        return 1;
    }
    MagicEntry_guess* entry = 0;
    if (IsValidSpellIndex_guess(param3)) {
        entry = g_magicLookup_guess->GetSpell_guess(param3);
        if (entry == 0) {
            return 0;
        }
    }
    if (g_combatFlag_guess != 0) {
        if (entry != 0 && entry->field_17d_guess != 0 && other->pvpFlag != self->pvpFlag) {
            return 0;
        }
        if (g_combatSpawnId_guess == (int)other->spawnId) {
            return 1;
        }
        if (g_combatSpawnId_guess == (int)self->spawnId) {
            return 1;
        }
    }
    if (param3 == -1 && other->type == 0 && self->type == 0 &&
        self->guildId != -1 && other->guildId != -1) {
        return 1;
    }
    if (entry != 0 && entry->field_17d_guess != 0) {
        int state = ((EQPlayerPcView_guess*)other)->GetPcClient_guess();
        if (self->gm != 0) {
            return 1;
        }
        if (entry->field_17d_guess > 1) {
            if (other->type >= 1) {
                return 0;
            }
            if (self->type != 0) {
                return 0;
            }
            if (!entry->FindAffectSlot_guess(0x51)) {
                if (state == 0) {
                    return 0;
                }
                if (((PcRoot_guess*)state)->IsAGroupMember_guess(self->name_120) == 0) {
                    return 0;
                }
            }
        } else {
            int id = entry->id_120_guess;
            if (id == 0xc || id == 0x1c || id == 0x1d || id == 0x13a || id == 0x13b ||
                id == 0x13c || param3 == 0x1a8) {
                if (other->type == 0) {
                    if (state == 0) {
                        return 0;
                    }
                    if (((PcRoot_guess*)state)->IsAGroupMember_guess(self->name_120) == 0) {
                        return 0;
                    }
                }
            }
        }
        if (other->pvpFlag != self->pvpFlag) {
            return 0;
        }
        if (g_combatFlag_guess != 0) {
            return 0;
        }
        if (g_gameMode_guess != 4) {
            return 1;
        }
        if (entry->FindAffectSlot_guess(0x1b)) {
            return 1;
        }
        if (other->NotOnSameDeity_guess(self, entry) == 0) {
            return 1;
        }
        return 0;
    }
    int mode = g_gameMode_guess;
    if (mode == 2) {
        if (levelDiff > 8) {
            return 0;
        }
    } else if ((mode == 4 && other->NotOnSameDeity_guess(self, entry) != 0) ||
               (entry != 0 && mode == 6)) {
        if (thisLevel >= 6 && otherLevel >= 6) {
            return 1;
        }
        if (g_zoneInfo_guess->FUN_005f6bc0_guess(other->zone_204) != 0) {
            return 0;
        }
        return 1;
    } else {
        if (other->pvpFlag == 0) {
            return 0;
        }
        if (self->pvpFlag == 0) {
            return 0;
        }
        if (levelDiff > 4 && mode != 6) {
            return 0;
        }
    }
    if (thisLevel >= 6 && otherLevel >= 6) {
        return 1;
    }
    return 0;
}

// Whether this can hit `target` from here: allowed, in sight, within melee range + `bonus` (x1.25 PvP),
// and facing it. Refusals print their reason. EQPlayer::CanIHit in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x0047ED9C
// @early-stop: budget, structural ndiff=72
char EQPlayerCore_guess::CanIHit_guess(int target, float bonus) {
    float thisY;
    float thisX;
    float limit = 80.0f;
    EQPlayerCore_guess* other = (EQPlayerCore_guess*)target;

    if (pCharInfo_0218_guess == 0) {
        return 0;
    }
    // Divine aura (effect 40) blocks attacking.
    if (((ResultOwner_guess*)g_pcClient_guess)->command_guess.TotalSpellAffects_guess(0x28, 1, 0, 1) > 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3197, 0), 0x12f, 1);
        return 0;
    }
    if (other == this) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3198, 0), 0x12f, 1);
        return 0;
    } else if (other == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3199, 0), 0x12f, 1);
        return 0;
    } else {
        if (!((EQPlayer_guess*)this)->AllowedToAttack_guess((EQPlayer_guess*)other, -1)) {
            return 0;
        }
        if (handler == 0 || handler->target == 0 || other->handler == 0 || other->handler->target == 0) {
            return 0;
        }
        thisY = x_0034_guess;
        thisX = y_0030_guess;
        float otherY = other->x_0034_guess;
        float otherX = other->y_0030_guess;
        if (!CastRay(this, otherX, otherY, other->z_0038_guess)) {
            token_string_to_client_guess(pCharInfo_0218_guess, 0x7b, 0x12f, 0);
            return 0;
        }
        float range = get_melee_range(this, other);
        if (bonus == 0.0f && type_0244_guess == 0 && other->type_0244_guess == 0) {
            range *= 1.25f;
        }
        float sum = range + bonus;
        if (sum * sum < get_range_squared_guess(this, other)) {
            token_string_to_client_guess(pCharInfo_0218_guess, 0x7c, 0x12f, 0);
            return 0;
        }
        float distance = get_bearing_guess(thisX, thisY, otherX, otherY);
        // Headings run 0-512 and wrap: near 0 and near 512 count as close.
        if (distance > 472.0f && heading_004c_guess < 40.0f) {
            distance = heading_004c_guess;
        }
        if (distance < 40.0f && heading_004c_guess > 472.0f) {
            distance = heading_004c_guess;
        }
        if (other->type_0244_guess == 0 && type_0244_guess == 0) {
            limit = 256.0f;
            if (distance > 350.0f && heading_004c_guess < 150.0f) {
                distance = heading_004c_guess;
            }
            if (distance < 150.0f && heading_004c_guess > 350.0f) {
                distance = heading_004c_guess;
            }
        }
        if (fabs((double)(distance - heading_004c_guess)) <= limit) {
            return 1;
        }
        token_string_to_client_guess(pCharInfo_0218_guess, 0x6c, 0x12f, 0);
        return 0;
    }
}

// Zeroes every field the ctor does not set; showhelm (+0x1B8) defaults to 1.
// FUNCTION: TITANIUM 0x004814D4
void EQPlayer_guess::InitTables_guess() {
    playerState_0294_guess = 0;
    for (int j = 0; j < 2; j++) {
        field_20c[j] = -1;
    }
    field_000 = 0;
    name_120[0] = 0;
    zone_204 = 0;
    motion_030.Reset_guess();
    motion_030.field_30 = 0;
    motion_030.field_34 = 0;
    eyeHeight_0234_guess = 0.0f;
    field_298 = 0;
    field_29c = 0;
    heightOffset_0238_guess = 0.0f;
    field_2a0 = 0;
    pPrev = 0;
    pNext = 0;
    field_1a4 = 0;
    pActorInfo = 0;
    pCharInfo = 0;
    spawnId = 0;
    masterId = 0;
    hpMax = 0;
    hpCurrent = 0;
    guildId = 0;
    field_1ac = 0;
    type = 0;
    playerClass = 0;
    race = 0;
    isABoat_01b6_guess = 0;
    gender = 0;
    level = 0;
    hideMode = 0;
    field_1b1 = 0;
    pvpFlag = 0;
    standState = 0;
    light = 0;
    faceHair = 0;
    for (int i = 0; i < 9; i++) {
        ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(i, 0);
        ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(i, 0);
    }
    avatarHeight = 0.0f;
    equipChest2_0254_guess = 0;
    helm_0255_guess = 0;
    field_228 = 0.0f;
    linkdead_01b2_guess = 0;
    gm = 0;
    lfg_01b4_guess = 0;
    stepHeight_022c_guess = 0.0f;
    levitate = 0;
    bodyType = 0;
    field_21c = 0;
    walkSpeed = 0.0f;
    anon = 0;
    field_268 = 0;
    runSpeed_0230_guess = 0.0f;
    SetAFK_guess(0);
    isPet_01b5_guess = 0;
    aaTitle_0278_guess = 0;
    field_290 = 0;
    lastName_0001_guess = 0;
    guildRank_027c_guess = 0;
    deity = 0;
    holding = 0;
    hairColor = 0;
    beardColor = 0;
    eyeColor1_0247_guess = 0;
    eyes = 0;
    eyes2 = 0;
    beardType = 0;
    canFindLocation_01b0_guess = 0;
    field_1b7 = 0;
    showHelm_01b8_guess = 1;
    field_224 = 0;
    field_1b3 = 0;
    isABoat_01b6_guess = 0;
    ((EQPlayerRaceView_guess*)this)->SetTitle_guess(0);
    ((TextBufferOwner_guess*)this)->SetSuffix_guess(0);
    FUN_00489955_guess();
    field_2e4 = 0;
    field_2e5 = 0;
    field_324 = -1.0f;
}

// Attachment points: newer skeletons use bone names (SetAttachmentBoneNames_guess); older ones the
// race's *_POINT_DAG nodes, with the human ones (HUM/HUF) as the head's fallback.
// FUNCTION: TITANIUM 0x0047D7A4
void EQPlayerCore_guess::UpdateDAGPointers_guess() {
    char local_d8[128];
    char local_58[64];
    char local_18[16];
    AttachmentSlots_guess* attachment = (AttachmentSlots_guess*)((EQPlayer_guess*)this)->GetAnimation_guess();
    attachment->Slot006_guess();
    if (handler->FUN_0048f019_guess() != 0) {
        ((EQPlayerBoneView_guess*)this)->SetAttachmentBoneNames_guess();
    } else {
        // Point 0: the race's HEAD_POINT, else its HE node, else the human one by gender (+0x24E 1 =
        // female); point 1 the HE node with the same fallback.
        GetActorTag_guess(local_18);
        sprintf(local_58, "%sHEAD_POINT_DAG", local_18);
        handler->target->Slot083_guess(0, local_58);
        if (handler->target->Slot085_guess(0) == 0) {
            sprintf(local_58, "%sHE_DAG", local_18);
            handler->target->Slot083_guess(0, local_58);
            if (handler->target->Slot085_guess(0) == 0) {
                if (gender_024e_guess == 1) {
                    sprintf(local_58, "HUFHEAD_POINT_DAG");
                } else {
                    sprintf(local_58, "HUMHEAD_POINT_DAG");
                }
                handler->target->Slot083_guess(0, local_58);
            }
        }
        handler->target->Slot085_guess(0);
        if (((EQPlayerRaceView_guess*)this)->IsHorseRace_guess()) {
            handler->target->Slot084_guess(0);
        }
        sprintf(local_58, "%sHE_DAG", local_18);
        handler->target->Slot083_guess(1, local_58);
        if (handler->target->Slot085_guess(1) == 0) {
            if (gender_024e_guess == 1) {
                sprintf(local_58, "HUFHE_DAG");
            } else {
                sprintf(local_58, "HUMHE_DAG");
            }
            handler->target->Slot083_guess(1, local_58);
        }
        handler->target->Slot085_guess(1);
        // Points 6, 3, 4 and 5: body, right hand, left hand and shield.
        sprintf(local_58, "%s_BLD_DAG", local_18);
        handler->target->Slot083_guess(6, local_58);
        sprintf(local_58, "%sR_POINT_DAG", local_18);
        handler->target->Slot083_guess(3, local_58);
        sprintf(local_58, "%sL_POINT_DAG", local_18);
        handler->target->Slot083_guess(4, local_58);
        sprintf(local_58, "%sSHIELD_POINT_DAG", local_18);
        handler->target->Slot083_guess(5, local_58);
        // Models with armour parts (+0x12C +0x34) swap points 0 and 1 to HEHEAD and HEAD_POINT and add the
        // tunic, hair, beard, chest, gauntlet, shoulder, leg, pelvis and two chest-cloak points.
        if (handler->actorDef_012c_guess != 0 && handler->actorDef_012c_guess->field_034_guess != 0) {
            sprintf(local_58, "%sHEHEAD_DAG", local_18);
            handler->target->Slot083_guess(0, local_58);
            sprintf(local_58, "%sHEAD_POINT_DAG", local_18);
            handler->target->Slot083_guess(1, local_58);
            if (handler->target->Slot085_guess(7) == 0) {
                sprintf(local_d8, "%sTUNIC_POINT_DAG", local_18);
                handler->target->Slot083_guess(7, local_d8);
            }
            if (handler->target->Slot085_guess(8) == 0) {
                sprintf(local_d8, "%sHAIR_POINT_DAG", local_18);
                handler->target->Slot083_guess(8, local_d8);
            }
            if (handler->target->Slot085_guess(9) == 0) {
                sprintf(local_d8, "%sBEARD_POINT_DAG", local_18);
                handler->target->Slot083_guess(9, local_d8);
            }
            if (handler->target->Slot085_guess(0xb) == 0) {
                sprintf(local_d8, "%sCHEST_POINT_DAG", local_18);
                handler->target->Slot083_guess(0xb, local_d8);
            }
            if (handler->target->Slot085_guess(0xc) == 0) {
                sprintf(local_d8, "%sGAUNTL_POINT_DAG", local_18);
                handler->target->Slot083_guess(0xc, local_d8);
            }
            if (handler->target->Slot085_guess(0xd) == 0) {
                sprintf(local_d8, "%sGAUNTR_POINT_DAG", local_18);
                handler->target->Slot083_guess(0xd, local_d8);
            }
            if (handler->target->Slot085_guess(0xe) == 0) {
                sprintf(local_d8, "%sSHOULDL_POINT_DAG", local_18);
                handler->target->Slot083_guess(0xe, local_d8);
            }
            if (handler->target->Slot085_guess(0xf) == 0) {
                sprintf(local_d8, "%sSHOULDR_POINT_DAG", local_18);
                handler->target->Slot083_guess(0xf, local_d8);
            }
            if (handler->target->Slot085_guess(0x10) == 0) {
                sprintf(local_d8, "%sLEGL_POINT_DAG", local_18);
                handler->target->Slot083_guess(0x10, local_d8);
            }
            if (handler->target->Slot085_guess(0x11) == 0) {
                sprintf(local_d8, "%sLEGR_POINT_DAG", local_18);
                handler->target->Slot083_guess(0x11, local_d8);
            }
            if (handler->target->Slot085_guess(0x12) == 0) {
                sprintf(local_d8, "%sPELVIS_POINT_DAG", local_18);
                handler->target->Slot083_guess(0x12, local_d8);
            }
            if (handler->target->Slot085_guess(0x13) == 0) {
                sprintf(local_d8, "%sCHCHEST1_DAG", local_18);
                handler->target->Slot083_guess(0x13, local_d8);
            }
            if (handler->target->Slot085_guess(0x14) == 0) {
                sprintf(local_d8, "%sCHCHEST2_DAG", local_18);
                handler->target->Slot083_guess(0x14, local_d8);
            }
            this->FindDefaultEyeMaterialIndexes_guess();
        }
    }
}

static void SetPcLight_guess(EQPlayer_guess* player, unsigned char light) {
    player->GetPc_guess()->DoLight_guess(light);
}

#define g_playerList_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905CC4)
#define g_controlledPlayer_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)
#define g_player905d04_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905D04)
#define g_player923cd4_guess EQ_GLOBAL(EQPlayer_guess*, 0x00923CD4)
#define g_value923cc4_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_player905cf8_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905CF8)
// A real array (0x00904390, 5 entries): tests/unicorn/crt_defaults.json maps the symbol. Through
// EQ_ARRAY the loop keeps a separate index (lea eax,[ecx+base]); the original compares the address.
extern EQPlayer_guess* g_playerSlots_guess[5];
#define g_spawnTable_guess EQ_ARRAY(EQPlayer_guess*, 0x00900F50)

struct ClientRoot_guess {
    // EXTERNAL: TITANIUM 0x0043745D ClientRoot_guess::GetValue2cf8_guess
    int GetValue2cf8_guess();
    // EXTERNAL: TITANIUM 0x0043C783 ClientRoot_guess::RestoreCameraMode_guess
    void RestoreCameraMode_guess();
    // EXTERNAL: TITANIUM 0x004392DE ClientRoot_guess::SetCameraMode_guess
    void SetCameraMode_guess(int value);
};

#define g_clientRoot_guess EQ_GLOBAL(ClientRoot_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00576FD0 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source, int size);

struct NameTextEq_guess {
    char pad_000[0xb54];
    int field_b54;
    // EXTERNAL: TITANIUM 0x00492EC2 NameTextEq_guess::GetDisplayName_guess
    char* GetDisplayName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x00491E5B NameTextEq_guess::GetClassDesc
    char* GetClassDesc(int playerClass);
};

struct NameZones_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 NameZones_guess::GetZoneName_guess
    void GetZoneName_guess(int zone, char* out, int flag);
};

struct NameGuilds_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 NameGuilds_guess::GetName_guess
    char* GetName_guess(int guildId);
};

struct NameRaid_guess {
    // EXTERNAL: TITANIUM 0x004B44C6 NameRaid_guess::Check_guess
    char Check_guess(void* character, int type, int one);
};

// The profile flags sit in a virtual base, reached through the vbptr of the base at +0xc280.
struct PcFlagsBase_guess {
    char pad_000[0x108];
    unsigned int flags_108;
};
struct PcHead_guess {
    virtual void Slot000_guess();
    char pad_004[0xc27c];
};
struct PcZoneView_guess : virtual PcFlagsBase_guess {
    virtual void Slot000_guess();
};
struct PcView_guess : PcHead_guess, PcZoneView_guess {
};

inline bool ContainsPlayer_guess(void* const* list, int count, const EQPlayer_guess* player) {
    for (int i = 0; i < count; i++) {
        if (list[i] == player) {
            return true;
        }
    }
    return false;
}

#define g_nameEq_guess EQ_GLOBAL(NameTextEq_guess*, 0x00988DF0)
#define g_nameZones_guess EQ_GLOBAL(NameZones_guess*, 0x00905CC0)
#define g_nameGuilds_guess EQ_ARRAY(NameGuilds_guess, 0x00905D38)
#define g_nameRaid_guess EQ_GLOBAL(NameRaid_guess*, 0x009859EC)
#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)
#define g_showNames_guess EQ_GLOBAL(int, 0x00924860)
#define g_nameDebug_guess EQ_GLOBAL(int, 0x00850B9C)
#define g_blendMode_guess EQ_GLOBAL(int, 0x00923D58)
#define g_pulseStep_guess EQ_GLOBAL(int, 0x00903E58)

// Name colour by kind: debug, GM, NPC, PvP (anonymous variant), the +0x106C/+0x1074 states, roleplay.
// Ruleset 2 at 0x923D58 tints PCs by race team; the player's name changes colour while the title choice at
// 0x9928FC differs from its title or suffix. The target (0x905D04) pulses brighter each call.
// FUNCTION: TITANIUM 0x0047AA0B
// @early-stop: budget, structural ndiff=62
char EQPlayer_guess::SetNameSpriteTint() {
    int green_guess;
    unsigned char color[3];
    if (pActorInfo == 0 || pActorInfo->visual_000_guess == 0) {
        return 0;
    }
    if (g_nameDebug_guess != 0 && g_nameEq_guess->field_b54 == 1) {
        color[2] = 0xff;
        color[1] = 0xff;
        color[0] = 0;
        pActorInfo->visual_000_guess->Slot081_guess(color);
        return 1;
    }
    if (race >= 0x8cd) {
        color[1] = 0xff;
        if (hpMax == 2000) {
            color[0] = 0x33;
            color[2] = 0xff;
        } else {
            color[2] = 0x66;
            color[0] = 0;
        }
    } else if ((gm & 1) != 0 && type != 1 && anon == 0) {
        color[2] = 0x1d;
        color[1] = 0xa6;
        color[0] = 0x4b;
    } else if (type != 0) {
        color[2] = 0x17;
        color[1] = 0xb8;
        color[0] = 0xad;
    } else {
        if (pvpFlag != 0) {
            if (((anon >> 1) & 1) != 0) {
                color[2] = 0xef;
                color[1] = 0x5d;
                color[0] = 0x5d;
            } else {
                color[2] = 0xa6;
                color[1] = 0x14;
                color[0] = 0x14;
            }
        } else if (((EQPlayerCore_guess*)this)->FUN_00479396_guess()) {
            color[2] = 0x40;
            color[1] = 0xff;
            color[0] = 0xff;
        } else {
            if ((((anon >> 1) & 1) != 0 && g_blendMode_guess == 0) ||
                (((anon >> 1) & 1) != 0 && g_blendMode_guess == 4)) {
                color[2] = 0x85;
                color[1] = 0x48;
                color[0] = 0x9c;
            } else {
                color[2] = 0x3d;
                color[1] = 0x6b;
                color[0] = 0xdc;
                if (g_blendMode_guess == 2) {
                    if (race == Race_HighElf || race == Race_WoodElf || race == Race_HalfElf) {
                        color[2] = 0xff;
                        color[1] = 0xff;
                        color[0] = 0;
                    } else if (race == Race_Dwarf || race == Race_Gnome || race == Race_Halfling) {
                        color[2] = 0x85;
                        color[1] = 0x48;
                        color[0] = 0x9c;
                    }
                    if (race == Race_Human || race == Race_Barbarian || race == Race_Erudite || race == Race_VahShir || race == Race_Froglok) {
                        color[2] = 0x3d;
                        color[1] = 0x6b;
                        color[0] = 0xdc;
                    }
                    if (race == Race_Ogre || race == Race_Troll || race == Race_DarkElf || race == Race_Iksar) {
                        color[2] = 0xff;
                        color[1] = 0x80;
                        color[0] = 0;
                    }
                }
            }
        }
        if (this == g_controlledPlayer_guess && pinstCTitleWnd_guess != 0 &&
            pinstCTitleWnd_guess->dShow != 0) {
            char* first = pinstCTitleWnd_guess->GetTitlePrefix_guess();
            char* second = pinstCTitleWnd_guess->GetTitleSuffix_guess();
            if ((first != 0 && strlen(first) > 0 && _stricmp(first, text_2a4) != 0) ||
                (second != 0 && strlen(second) > 0 && _stricmp(second, text_2c4) != 0)) {
                color[2] = 0xff;
                color[1] = 0xff;
                color[0] = 0;
            }
        }
    }
    if (this == g_player905d04_guess) {
        int red = 0xff - ((0xff - color[2]) / 10) * g_pulseStep_guess;
        green_guess = 0xff - ((0xff - color[1]) / 10) * g_pulseStep_guess;
        int blue = 0xff - ((0xff - color[0]) / 10) * g_pulseStep_guess;
        if (red < 0) {
            red = 0;
        }
        if (green_guess < 0) {
            green_guess = 0;
        }
        if (blue < 0) {
            blue = 0;
        }
        color[2] = (unsigned char)red;
        color[1] = (unsigned char)green_guess;
        color[0] = (unsigned char)blue;
        if (g_pulseStep_guess == 10) {
            g_pulseStep_guess = 0;
        } else {
            g_pulseStep_guess = g_pulseStep_guess + 1;
        }
    }
    pActorInfo->visual_000_guess->Slot081_guess(color);
    return 1;
}

// Builds the name sprite text: name, title and suffix, guild, LFG/AFK tags; for NPCs the assist and
// mark numbers and HP percent. `show` 0 clears it. MQ2 EQPlayer::SetNameSpriteState.
// FUNCTION: TITANIUM 0x0047CF7C
// @early-stop: budget, structural ndiff=623
int EQPlayer_guess::SetNameSpriteState(bool show) {
    char line[1024];
    char name[128];
    char text[512];
    char number[32];
    EQPlayerBoneView_guess* owner = (EQPlayerBoneView_guess*)this;

    if (g_clientRoot_guess->GetValue2cf8_guess() == 0) {
        if (owner->field_1a8_guess != 0 && owner->field_1a8_guess->object_guess != 0 &&
            owner->field_1a8_guess->object_guess->Slot085_guess(0)) {
            owner->ChangeBoneStringSprite(0, 0);
        }
        return 0;
    }
    if (type != 0 && pActorInfo != 0) {
        int r = race;
        if (((r == 0x3c && masterId == 0) || (r == 0x16f && masterId == 0) || r == 0x1d || r == 0x34 ||
             r == 0x118 || r == 0xf4) &&
            ((r == 0x3c && pActorInfo->currentAnimation_0134_guess == 0x10) || pActorInfo->currentAnimation_0134_guess == 0x21 ||
             pActorInfo->currentAnimation_0134_guess == 0x26 || r == 0xf4 || r == 0x34)) {
            if (owner->field_1a8_guess->object_guess != 0 &&
                owner->field_1a8_guess->object_guess->Slot085_guess(0)) {
                owner->ChangeBoneStringSprite(0, 0);
            }
            return 1;
        }
    }
    name[0] = 0;
    if (field_1b7 != 0) {
        CopyText_guess(name, EQ_ARRAY(char, 0x00647F2C), 0x80);
    }
    CopyText_guess(name, g_nameEq_guess->GetDisplayName_guess(name_120), 0x80);
    if (owner->field_1a8_guess == 0 || owner->field_1a8_guess->object_guess == 0 ||
        !owner->field_1a8_guess->object_guess->Slot085_guess(0)) {
        return 0;
    }
    if (g_nameDebug_guess != 0 && g_nameEq_guess->field_b54 == 1) {
        g_nameZones_guess->GetZoneName_guess(zone_204, text, 0);
        sprintf(line, "%s [%d %s]\n%s", name_120, level, g_nameEq_guess->GetClassDesc(playerClass), text);
        owner->ChangeBoneStringSprite(0, line);
        SetNameSpriteTint();
        return 1;
    }
    if (!show || (g_showNames_guess <= 0 && type != 1)) {
        owner->ChangeBoneStringSprite(0, 0);
        return 1;
    }
    text[0] = 0;
    if (race >= 0x8cd) {
        strcpy(text, name_120);
    } else if (type != 0) {
        bool inRaid = (g_pcView_guess->flags_108 >> 6) & 1;
        ActorInfo_guess* group = g_controlledPlayer_guess->pActorInfo;
        bool marked = false;
        sprintf(text, EQ_ARRAY(char, 0x0063F53F));
        if (inRaid) {
            if (ContainsPlayer_guess(&group->field_170, 1, this) ||
                ContainsPlayer_guess(group->field_174, 3, this)) {
                marked = true;
                strcat(text, EQ_ARRAY(char, 0x00647F10));
            }
            int index = -1;
            int i;
            for (i = 0; i < 3; i++) {
                if (group->field_180[i] == this) {
                    index = i;
                    break;
                }
            }
            for (i = 0; i < 3; i++) {
                if (group->field_18c[i] == this) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                sprintf(number, "%d - ", index + 1);
                strcat(text, number);
            }
        }
        if (hideMode == 1 && type == 1) {
            strcat(text, EQ_ARRAY(char, 0x00647F18));
            strcat(text, name);
            strcat(text, EQ_ARRAY(char, 0x00641098));
        } else {
            strcat(text, name);
        }
        if (inRaid && type == 1 && g_nameRaid_guess != 0 &&
            (g_nameRaid_guess->Check_guess(g_pcView_guess, 1, 1) ||
             g_nameRaid_guess->Check_guess(g_pcView_guess, 0x11, 1))) {
            if (g_player905d04_guess == this || ContainsPlayer_guess(&group->field_170, 1, this) ||
                ContainsPlayer_guess(group->field_174, 3, this) ||
                ContainsPlayer_guess(group->field_180, 3, this) ||
                ContainsPlayer_guess(group->field_18c, 3, this)) {
                // HP percent of assisted or marked NPCs, with raid leadership ability 1 or 17 (probably).
                sprintf(number, " - %d%%", hpCurrent);
                strcat(text, number);
            }
        }
        if (marked) {
            strcat(text, EQ_ARRAY(char, 0x00647EFC));
        }
        strcpy(number, (const char*)&lastName_0001_guess);
        if (type == 1 && number[0] != 0) {
            strcat(text, EQ_ARRAY(char, 0x00647EF8));
            strcat(text, number);
            strcat(text, EQ_ARRAY(char, 0x00641098));
        }
    } else {
        bool showGuild = true;
        if (anon != 0 && (((unsigned int)anon >> 1) & 1) == 0) {
            showGuild = false;
        }
        if (pActorInfo->field_106c == 1) {
            strcat(text, pStringTable->getString(0x157f, 0));
        }
        if (pActorInfo->field_1074 == 1) {
            strcat(text, pStringTable->getString(0x17a7, 0));
        } else if (this == g_controlledPlayer_guess && pinstCTitleWnd_guess != 0 && pinstCTitleWnd_guess->dShow != 0) {
            if (pinstCTitleWnd_guess->GetTitlePrefix_guess() != 0) {
                strcat(text, pinstCTitleWnd_guess->GetTitlePrefix_guess());
            }
            strcat(text, EQ_ARRAY(char, 0x0063FE10));
        } else if (g_showNames_guess > 3 && text_2a4[0] != 0) {
            strcat(text, text_2a4);
            strcat(text, EQ_ARRAY(char, 0x0063FE10));
        }
        if (hideMode == 1) {
            strcat(text, EQ_ARRAY(char, 0x00647F18));
            strcat(text, name);
            strcat(text, EQ_ARRAY(char, 0x00641098));
        } else {
            strcat(text, name);
        }
        if (g_showNames_guess == 2 || g_showNames_guess == 3 || g_showNames_guess == 4 || g_showNames_guess == 6) {
            strcat(text, EQ_ARRAY(char, 0x0063FE10));
            strcat(text, g_nameEq_guess->GetDisplayName_guess((const char*)&lastName_0001_guess));
        }
        if (this == g_controlledPlayer_guess && pinstCTitleWnd_guess != 0 && pinstCTitleWnd_guess->dShow != 0) {
            strcat(text, EQ_ARRAY(char, 0x0063FE10));
            if (pinstCTitleWnd_guess->GetTitleSuffix_guess() != 0) {
                strcat(text, pinstCTitleWnd_guess->GetTitleSuffix_guess());
            }
        } else if (g_showNames_guess > 3 && text_2c4[0] != 0) {
            strcat(text, EQ_ARRAY(char, 0x0063FE10));
            strcat(text, text_2c4);
        }
        if (lfg_01b4_guess != 0) {
            // LFG (+0x1B4, Spawn_Struct lfg).
            strcat(text, pStringTable->getString(0x301a, 0));
        }
        if (pvpFlag == 0) {
            if (afk_026c_guess != 0) {
                // AFK (+0x26C, Spawn_Struct afk).
                strcat(text, pStringTable->getString(0x3017, 0));
            }
            if (linkdead_01b2_guess != 0) {
                strcat(text, pStringTable->getString(0x8c0, 0));
            }
        }
        if ((g_showNames_guess == 3 || g_showNames_guess == 4) && showGuild == true && guildId != -1) {
            strcat(text, EQ_ARRAY(char, 0x00647F14));
            strcat(text, g_nameGuilds_guess->GetName_guess(guildId));
            strcat(text, EQ_ARRAY(char, 0x00641684));
        }
    }
    owner->ChangeBoneStringSprite(0, text);
    SetNameSpriteTint();
    return 1;
}

struct AppearanceState_guess {
    char pad_000_guess[0x144];
    char field_144_guess;
    char pad_145_guess[0x2d58 - 0x145];
    int field_2d58_guess;
};

#define g_appearanceState_guess EQ_GLOBAL(AppearanceState_guess*, 0x00905D24)

// Swaps the head textures (<tag>HE<tens><face>1_MDF) from `oldValue`'s face code to `value`'s. Old models
// swap several head textures (digits 1-5); Vah Shir and Froglok also re-apply body materials.
// FUNCTION: TITANIUM 0x0047DEC4
// @early-stop: budget, structural ndiff=320
int EQPlayer_guess::SwapFace_guess(int value, int oldValue) {
    struct FaceDigits_guess {
        char requestedValue;
        unsigned char oldTens;
        unsigned char newTens;
    } digits;
    char* extraTexture;
    char bodyName[64];
    char modelName[16];
    char newTexture[64];
    char oldTexture[64];

    if (pActorInfo == 0 || pActorInfo->actorInstance_0000_guess == 0 || pActorInfo->actorDef_012c_guess == 0) {
        return 0;
    }
    if ((char)pActorInfo->FUN_0048f019_guess() == 0) {
        ((EQPlayerCore_guess*)this)->GetActorTag_guess(modelName);
        if (value < 0 || oldValue < 0) {
            return 0;
        }

        digits.requestedValue = (char)value;
        digits.oldTens = 0;
        digits.newTens = 0;
        oldValue = ((EQPlayerCore_guess*)this)->GetBaseFaceNbr_guess(oldValue, &digits.oldTens);
        value = ((EQPlayerCore_guess*)this)->GetBaseFaceNbr_guess(value, &digits.newTens);

        if (equipChest2_0254_guess == -1) {
            if (((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess == 0) {
                extraTexture = 0;
            } else if (race == Race_VahShir) {
                extraTexture = 0;
                if (((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot085_guess(8) != 0) {
                    if (value == 7) {
                        eyes2 = 0;
                        sprintf(bodyName, "IT%d", ((EQPlayerCore_guess*)this)->GetRaceOffsetForAttachmentITs_guess() + 1000);
                    } else {
                        FUN_0060e450_guess(bodyName, EQ_ARRAY(char, 0x006410A8));
                    }
                    ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot059_guess(8, bodyName);
                }
            } else if (((EQPlayerRaceView_guess*)this)->GetBeardKind_guess() != 2 || digits.newTens == 0 ||
                       beardColor > 0x17 || g_appearanceState_guess->field_144_guess == 0) {
                extraTexture = 0;
            } else {
                extraTexture = (char*)&EQ_ARRAY(int, 0x006989A0)[beardColor];
            }

            sprintf(oldTexture, "%sHE%02d%d1_MDF", modelName,
                    digits.oldTens, oldValue);
            sprintf(newTexture, "%sHE%02d%d1_MDF", modelName,
                    digits.newTens, value);
            if (((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                    oldTexture, newTexture, (unsigned char*)extraTexture, 0) == 0 && oldValue != 0) {
                sprintf(oldTexture + 7, "%d1_MDF", 0);
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                    oldTexture, newTexture, (unsigned char*)extraTexture, 0);
            }

            if (((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess == 0 && race != Race_VahShir) {
                ++oldTexture[8];
                ++newTexture[8];
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                    oldTexture, newTexture, 0, 0);
            } else if (race == Race_VahShir || race == Race_Froglok) {
                int count = 7;
                do {
                    ++oldTexture[8];
                    ++newTexture[8];
                    ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                        oldTexture, newTexture, 0, 0);
                } while (--count != 0);

                for (int part = 1; part < 7; ++part) {
                    int color = colors_01bc_guess[part];
                    if (SwapMaterial_guess(
                            part,
                            ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(part),
                            ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(part),
                            color, value) == 0) {
                        if (SwapMaterial_guess(
                                part,
                                ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(part),
                                0, color, value) == 0) {
                            faceHair = 0;
                            SwapMaterial_guess(
                                part,
                                ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(part),
                                0, color, value);
                        }
                    }
                }
            } else if (race == Race_Iksar) {
                int count = 7;
                do {
                    ++oldTexture[8];
                    ++newTexture[8];
                    ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                        oldTexture, newTexture, 0, 0);
                } while (--count != 0);
            } else {
                if (race == Race_Erudite || (race > 8 && race < 0xb)) {
                    oldTexture[8] = '2';
                    newTexture[8] = '2';
                    extraTexture = 0;
                    ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                        oldTexture, newTexture, (unsigned char*)extraTexture, 0);
                } else {
                    if ((race > 4 && race < 8 && gender == 0) || (race == Race_Dwarf && gender == 1)) {
                        oldTexture[8] = '3';
                        newTexture[8] = '3';
                        ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                            oldTexture, newTexture, (unsigned char*)extraTexture, 0);
                    }
                }
                oldTexture[8] = '4';
                newTexture[8] = '4';
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                    oldTexture, newTexture, 0, 0);
                ++oldTexture[8];
                ++newTexture[8];
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(
                    oldTexture, newTexture, 0, 0);
            }
        } else {
            sprintf(oldTexture, "%sHE%02d%d1_MDF", modelName,
                    oldValue == 0 ? (int)helm_0255_guess : 0, oldValue);
            sprintf(newTexture, "%sHE%02d%d1_MDF", modelName,
                    value == 0 ? (int)helm_0255_guess : 0, value);
            char useOld = oldValue == 0;
            ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(oldTexture, newTexture, 0, useOld);
            ++oldTexture[8];
            ++newTexture[8];
            ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot044_guess(oldTexture, newTexture, 0, useOld);
        }

        faceHair = digits.requestedValue;
        if (g_appearanceState_guess->field_2d58_guess != 0 && bodyType != 8 && bodyType != 3 &&
            bodyType != 5 && bodyType != 0xc) {
            ((EQPlayerCore_guess*)this)->FUN_0047b8d5_guess((int)EQ_ARRAY(char, 0x006974CC));
        }
    }
    return 1;
}

// Asks the motion factory (0x99E368 slot 16) for a model at the spawn's spot; used for the illusion
// races 142 and 143.
// FUNCTION: TITANIUM 0x0047E35C
char EQPlayer_guess::GetModelAtSpawnSpot_guess(char* out, int value) {
    CVector3 point_guess;
    if (g_clientRoot_guess->GetValue2cf8_guess() == 0 || pActorInfo == 0) {
        *out = 0;
        return 0;
    }
    if (pActorInfo->actorInstance_0000_guess == 0) {
        point_guess.x = motion_030.pos.y;
        point_guess.y = motion_030.pos.x;
        point_guess.z = motion_030.pos.z;
        if (!g_motionFactory_guess->Slot012_guess(&point_guess)) {
            *out = 0;
            return 0;
        }
    } else {
        ((MotionObject_guess*)pActorInfo->actorInstance_0000_guess)->Slot022_guess(&point_guess);
        ((MotionObject_guess*)pActorInfo->actorInstance_0000_guess)->Slot024_guess();
        ((MotionObject_guess*)pActorInfo->actorInstance_0000_guess)->Slot025_guess();
        ((MotionObject_guess*)pActorInfo->actorInstance_0000_guess)->Slot026_guess();
    }
    float scale = g_speedBase_guess - 100.0f;
    if (scale < 50.0f) {
        scale = 50.0f;
    }
    int raceValue = race;
    return g_motionFactory_guess->Slot016_guess(&point_guess, scale, value, raceValue == 0x8e, out);
}

// Default hair, beard and eye features for face `value`; with `commit` it rolls random ones, probably for
// character creation.
// FUNCTION: TITANIUM 0x00480130
// @early-stop: budget, structural ndiff=101
void EQPlayerCore_guess::SetDefaultFacialFeaturesByFace_guess(int value, int flags, char commit) {
    if ((char)flags == 0 && eyeColor1_0247_guess != 0xff) {
        return;
    }
    if (LegalPlayerRace_guess(-1) == 0) {
        return;
    }
    if (handler == 0) {
        return;
    }
    if (handler->actorDef_012c_guess == 0) {
        return;
    }
    if (handler->actorDef_012c_guess->field_034_guess == 0) {
        return;
    }
    unsigned char cell = faceHair_024d_guess;
    if (value < 0) {
        value = -1;
    }
    value = GetBaseFaceNbr_guess(value, 0);
    if (race_0260_guess == 0x82 && value == 7) {
        field_249_guess = 0;
    } else {
        field_249_guess = 0xff;
    }
    hairColor_0245_guess = 0xff;
    field_24a_guess = 0xff;
    beardColor_0246_guess = 0xff;
    int second_guess;
    if (GetHairKind_guess() == 1) {
        ((EQPlayerRaceView_guess*)this)->GetHairColorRange_guess(-1, &flags, &second_guess);
        field_249_guess = 0;
        hairColor_0245_guess = (unsigned char)flags;
    } else if (GetHairKind_guess() == 2) {
        ((EQPlayerRaceView_guess*)this)->GetHairColorRange_guess(-1, &flags, &second_guess);
        field_249_guess = 1;
        cell = (unsigned char)(value + 10);
        hairColor_0245_guess = (unsigned char)flags;
    }
    if (commit == 0) {
        if (gender_024e_guess == 0 && race_0260_guess == 8) {
            field_24a_guess = 0;
            beardColor_0246_guess = hairColor_0245_guess;
        }
    } else {
        unsigned char roll = (unsigned char)RandomRange_guess(1, 9);
        eyeColor1_0247_guess = roll;
        eyeColor_0248_guess = roll;
        cell = (unsigned char)value;
        if (race_0260_guess == 2 && RandomRange_guess(1, 100) < 0x1f) {
            cell = (unsigned char)(RandomRange_guess(0, 8) * 10 + value);
        }
        if (GetHairKind_guess() == 1) {
            ((EQPlayerRaceView_guess*)this)->GetHairColorRange_guess(-1, &flags, &second_guess);
            int cap = (((EQPlayerRaceView_guess*)this)->CanHaveNoHair_guess() != 0) + 2;
            unsigned char pick = (unsigned char)RandomRange_guess(0, cap);
            field_249_guess = pick;
            if (pick == 3) {
                field_249_guess = (unsigned char)RandomRange_guess(0, cap);
            }
            if (field_249_guess == 3) {
                field_249_guess = 0xff;
            }
            hairColor_0245_guess = (unsigned char)RandomRange_guess(flags, second_guess);
        } else if (GetHairKind_guess() == 2) {
            int range = 5;
            if (race_0260_guess == 3) {
                range = gender_024e_guess != 0 ? 8 : 5;
            }
            cell = (unsigned char)(RandomRange_guess(0, range) * 10 + value);
        }
        char kind = ((EQPlayerRaceView_guess*)this)->GetBeardKind_guess();
        if (kind == 1) {
            if (race_0260_guess != 8 && RandomRange_guess(1, 100) > 0x28) {
                field_24a_guess = 0xff;
                beardColor_0246_guess = 0xff;
            } else {
                field_24a_guess = (unsigned char)RandomRange_guess(0, 4);
                beardColor_0246_guess = hairColor_0245_guess;
            }
        } else {
            char kind2 = ((EQPlayerRaceView_guess*)this)->GetBeardKind_guess();
            if (kind2 == 2 && RandomRange_guess(1, 100) < 0x29) {
                int range = (race_0260_guess != 8) * 2 + 1;
                cell = (unsigned char)(RandomRange_guess(0, range) * 10 + value);
                beardColor_0246_guess = hairColor_0245_guess;
            }
        }
    }
    if (faceHair_024d_guess != cell) {
        SwapFace_guess(cell, faceHair_024d_guess);
    }
    if (commit != 0) {
        pinstCFacePick_guess->SetFaceSelectionsFromPlayer_guess();
    }
}

// Shows or hides the actor: hidden when invisible to the player, for some NPCs unseen for 12 s, and while
// riding (actor +0x15C); then refreshes the name sprite.
// FUNCTION: TITANIUM 0x00480409
// @early-stop: budget, structural ndiff=68
void EQPlayer_guess::UpdatePlayerVisibility_guess() {
    if (g_display2_guess->FUN_0043745d_guess() == 0 || bodyType >= 0x41) {
        return;
    }

    int one;
    char result = ((EQPlayerCheck_guess*)g_controlledPlayer_guess)->IsInvisibleToMe_guess((EQPlayer*)this);
    one = 1;
    if (result == 0) {
        if (this == g_controlledPlayer_guess || this == g_player905cf8_guess) {
            if (EQ_GLOBAL(int, 0x00850CCC) == 0) {
                RefreshNameSprite_guess();
                return;
            }
        } else {
            if ((type == one && motion_030.speedRun == EQ_ARRAY(float, 0x0063F4CC)[0]) ||
                (unsigned int)pActorInfo->field_1030 >= 3) {
                pActorInfo->field_ebc_guess = g_display2_guess->frameTime_0148_guess;
            }
            if (type < 2 && hpCurrent >= one &&
                (type != one || motion_030.speedRun != EQ_ARRAY(float, 0x0063F4CC)[0]) &&
                isABoat_01b6_guess == 0) {
                if ((unsigned int)pActorInfo->field_1030 < 3) {
                    ActorInfo_guess* actor = pActorInfo;
                    if (actor->mount_015c_guess != 0) {
                        actor = ((EQPlayer_guess*)actor->mount_015c_guess)->pActorInfo;
                    }
                    if ((unsigned int)(g_display2_guess->frameTime_0148_guess - actor->field_ebc_guess) > 12000) {
                        result = 1;
                    }
                }
            } else if (pActorInfo->field_ec8_guess == one) {
                result = (char)one;
            }
        }
    }

    EQPlayer_guess* linkedPlayer = (EQPlayer_guess*)pActorInfo->mount_015c_guess;
    if (pActorInfo->mount_015c_guess != 0 && linkedPlayer->pActorInfo != 0 &&
        linkedPlayer->pActorInfo->actorInstance_0000_guess != 0) {
        linkedPlayer->pActorInfo->visual_000_guess->Slot006_guess(
            g_display2_guess->field_129 != 0 ? result : (char)one);
    }

    if (pActorInfo->actorInstance_0000_guess != 0) {
        if (result == 0) {
            if (((EQPlayerRaceView_guess*)this)->IsHorseUsingHumanModel_guess() != 0) {
                result = (char)one;
            }
            if (((EQPlayerRaceView_guess*)this)->IsHorseRace_guess() != 0 && pActorInfo->rider_0160_guess != 0 &&
                ((EQPlayerCore_guess*)pActorInfo->rider_0160_guess)->FUN_0047a387_guess() != 0) {
                result = (char)one;
            }
        }
        if (pActorInfo->mount_015c_guess != 0) {
            result = (char)one;
        }
        pActorInfo->visual_000_guess->Slot006_guess(result);
    }
    RefreshNameSprite_guess();
}

// Updates every spawn's visibility while the world display is up.
// FUNCTION: TITANIUM 0x004805E9
void UpdateAllPlayersVisibility_guess() {
    if (g_clientRoot_guess->GetValue2cf8_guess() != 0) {
        for (EQPlayer_guess* player = g_playerList_guess; player != 0; player = player->pNext) {
            player->UpdatePlayerVisibility_guess();
        }
    }
}

struct PlayerHashNode_guess {
    EQPlayer_guess* player_000_guess;
    unsigned int hash_004_guess;
    PlayerHashNode_guess* next_008_guess;
};

struct PlayerHash_guess {
    PlayerHashNode_guess** buckets_000_guess;
    unsigned int bucketCount_004_guess;
    int count_008_guess;
    int usedBuckets_00c_guess;
    bool Remove_guess(EQPlayer_guess** player, unsigned int hash);
    // EXTERNAL: TITANIUM 0x00447C66 PlayerHash_guess::Insert_guess
    void Insert_guess(EQPlayer_guess** player, unsigned int hash);
};

#define g_playerHash_guess EQ_GLOBAL(PlayerHash_guess*, 0x00903E50)
#define g_value923860_guess EQ_GLOBAL(int, 0x00923860)
#define g_flag9237b4_guess EQ_GLOBAL(unsigned char, 0x009237B4)

// Removes the (player, hash) entry from the player name hash; true when found.
// FUNCTION: TITANIUM 0x0047C339
bool PlayerHash_guess::Remove_guess(EQPlayer_guess** player, unsigned int hash) {
    unsigned int index = hash % bucketCount_004_guess;
    PlayerHashNode_guess* node = buckets_000_guess[index];
    PlayerHashNode_guess** slot = &buckets_000_guess[index];
    if (node != 0) {
        do {
            if (node->player_000_guess == *player && node->hash_004_guess == hash) {
                *slot = node->next_008_guess;
                delete node;
                count_008_guess--;
                if (buckets_000_guess[index] == 0) {
                    usedBuckets_00c_guess--;
                }
                return true;
            }
            slot = &node->next_008_guess;
            node = node->next_008_guess;
        } while (node != 0);
    }
    return false;
}

// Renames the spawn and re-keys it in the player name hash 0x903E50; one-letter names are not hashed.
// FUNCTION: TITANIUM 0x0047C3EF
void EQPlayer_guess::SetName_guess(const char* name) {
    EQPlayer_guess* self = this;
    unsigned int hash = FUN_00574890_guess(name_120);
    g_playerHash_guess->Remove_guess(&self, hash);
    FUN_0060e450_guess(name_120, name);
    ((EQPlayerCore_guess*)this)->SetDisplayedName_guess(name);
    if (strlen(name) > 1) {
        hash = FUN_00574890_guess(name_120);
        g_playerHash_guess->Insert_guess(&self, hash);
    }
}

// Clears every other spawn's references to this one: auto-follow (+0xFE8), group/raid assist and mark
// slots (+0x170..+0x194) and +0x198.
// FUNCTION: TITANIUM 0x0047C457
void EQPlayer_guess::ClearOthersReferenceToMe_guess() {
    for (EQPlayer_guess* player = g_playerList_guess; player != 0; player = player->pNext) {
        if (player != this) {
            ActorInfo_guess* info = player->pActorInfo;
            if (info->followTarget_0fe8_guess == (EQPlayerCore_guess*)this) {
                info->followTarget_0fe8_guess = 0;
                if (player == g_controlledPlayer_guess) {
                    player->TurnOffAutoFollow_guess();
                }
            }
            if (info->field_170 == this) {
                info->field_170 = 0;
            }
            for (int i = 0; i < 3; ++i) {
                if (info->field_174[i] == this) {
                    info->field_174[i] = 0;
                }
            }
            for (int i = 0; i < 3; ++i) {
                if (info->field_180[i] == this) {
                    info->field_180[i] = 0;
                }
            }
            for (int i = 0; i < 3; ++i) {
                if (info->field_18c[i] == this) {
                    info->field_18c[i] = 0;
                }
            }
            if (info->field_198 == this) {
                info->field_198 = 0;
            }
        }
    }
}

// Auto-follow step: turns toward the followed spawn and runs while it is more than 15 units (plus its
// height) away; past 200 units or when it is a corpse ('x') it prints 0x3195 / 0x3194 and stops.
// FUNCTION: TITANIUM 0x0047C4FC
// @early-stop: budget, structural ndiff=217
void EQPlayerView_guess::FollowPlayerAI_guess() {
    char text_guess[264];
    ActorInfo_guess* info_guess = (ActorInfo_guess*)pActorInfo;
    if (info_guess == 0) {
        return;
    }
    EQPlayerCore_guess* target_guess = info_guess->followTarget_0fe8_guess;
    if (target_guess == 0) {
        return;
    }

    unsigned int textId_guess;
    const char* textSource_guess;
    if (target_guess->standState_0251_guess == 'x') {
        textId_guess = 0x3194;
        textSource_guess = &target_guess->name_0120_guess;
    } else {
        info_guess->followDistance_0ff4_guess = g_headingMath_guess->TrueDistance_guess(Y, X, Z,
            target_guess->y_0030_guess, target_guess->x_0034_guess,
            target_guess->z_0038_guess, 0);
        if (info_guess->followDistance_0ff4_guess <= 200.0f) {
            float height_guess = target_guess->heightOffset_0238_guess + heightOffset_0238_guess;
            info_guess->field_fec_guess = get_bearing_guess(
                Y, X, target_guess->y_0030_guess, target_guess->x_0034_guess);
            if (CastRay(target_guess, Y, X, Z) != 0) {
                if (info_guess->followDistance_0ff4_guess >= 20.0f) {
                    float difference_guess;
                    float step_guess = g_headingMath_guess->HeadingDiff_guess(
                        Heading, info_guess->field_fec_guess, &difference_guess);
                    if (step_guess >= 1.0f) {
                        if (step_guess >= 4.0f) {
                            if (step_guess <= 128.0f) {
                                step_guess = 4.0f;
                            } else {
                                step_guess = 9.0f;
                            }
                        }
                        if ((Heading < info_guess->field_fec_guess && difference_guess < 0.0f) ||
                            (info_guess->field_fec_guess < Heading && difference_guess > 0.0f)) {
                            Heading -= step_guess;
                        } else {
                            Heading += step_guess;
                        }
                        Heading = g_headingMath_guess->FixHeading_guess(Heading);
                    } else {
                        Heading = info_guess->field_fec_guess;
                    }
                } else {
                    Heading = info_guess->field_fec_guess;
                }
            }

            if (info_guess->followDistance_0ff4_guess < height_guess + 15.0f) {
                g_value923860_guess = 0;
                SpeedRun = 0.0f;
                return;
            }
            if (height_guess + 30.0f <= info_guess->followDistance_0ff4_guess ||
                (SpeedRun <= target_guess->speedRun_0048_guess && SpeedRun != 0.0f)) {
                g_flag9237b4_guess = 1;
            } else {
                g_flag9237b4_guess = 0;
            }
            g_value923860_guess = 1;
            return;
        }

        EQPlayerCore_guess* displayTarget_guess = target_guess;
        EQPlayer_guess* current_guess = g_player905cf8_guess;
        if (g_controlledPlayer_guess != current_guess) {
            ActorInfo_guess* currentInfo_guess = (ActorInfo_guess*)current_guess->pActorInfo;
            if (currentInfo_guess != 0 && currentInfo_guess->followTarget_0fe8_guess != 0) {
                displayTarget_guess = currentInfo_guess->followTarget_0fe8_guess;
            }
        }
        textId_guess = 0x3195;
        textSource_guess = displayTarget_guess->text_160_guess;
    }

    FUN_0046da4a_guess(text_guess, textId_guess, textSource_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    g_textSink_guess->dsp_chat(text_guess);
    ((EQPlayer_guess*)this)->TurnOffAutoFollow_guess();
}

// Stops auto-follow for the player or the player's mount and prints string 0x3196.
// FUNCTION: TITANIUM 0x00479482
void EQPlayer_guess::TurnOffAutoFollow_guess() {
    char buf[256];
    if (pActorInfo != 0 && g_player905cf8_guess != 0 &&
        ((g_player905cf8_guess->pActorInfo != 0 && g_player905cf8_guess->pActorInfo->followTarget_0fe8_guess != 0) ||
         pActorInfo->followTarget_0fe8_guess != 0)) {
        g_value923860_guess = 0;
        g_flag9237b4_guess = 1;
        motion_030.speedRun = 0.0f;
        if (g_controlledPlayer_guess == g_player905cf8_guess || g_player905cf8_guess->pActorInfo == 0 ||
            g_player905cf8_guess->pActorInfo->rider_0160_guess == 0 || g_player905cf8_guess->pActorInfo->followTarget_0fe8_guess == 0) {
            FUN_0046da4a_guess(buf, 0x3196, pActorInfo->followTarget_0fe8_guess->text_160_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            g_textSink_guess->dsp_chat(buf);
            pActorInfo->followTarget_0fe8_guess = 0;
        } else {
            FUN_0046da4a_guess(buf, 0x3196, g_player905cf8_guess->pActorInfo->followTarget_0fe8_guess->text_160_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            g_textSink_guess->dsp_chat(buf);
            g_player905cf8_guess->pActorInfo->followTarget_0fe8_guess = 0;
            g_controlledPlayer_guess->pActorInfo->followTarget_0fe8_guess = 0;
        }
    }
}

struct ActorObject_guess {
    virtual void Slot000_guess() = 0;
    virtual void Slot001_guess() = 0;
    virtual void Slot002_guess() = 0;
    virtual void Slot003_guess() = 0;
    virtual void Slot004_guess() = 0;
    virtual void Slot005_guess() = 0;
    virtual void Slot006_guess() = 0;
    virtual void Slot007_guess() = 0;
    virtual void Slot008_guess() = 0;
    virtual void Slot009_guess() = 0;
    virtual void Slot010_guess() = 0;
    virtual void Slot011_guess(float value) = 0;
};

struct PlayerInfoView_guess : virtual CharacterBase_guess {
    virtual void Slot000_guess();
};

struct EQPlayerFunctionView_guess : EQPlayer {
    char HandleAmmo_guess();
    // EXTERNAL: TITANIUM 0x0048083A EQPlayerFunctionView_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(int slot, const char* text, int one);
    char FireRangedItem_guess(int param);
};

// What a ranged attack uses: 0 the range-slot item, 1 the ammo (slot 21), 2 a throwing stack (type 0x13)
// or nothing (string 0x324B). Archery (type 5) needs ammo of type 0x1B, type 6 needs 0x1C.
// FUNCTION: TITANIUM 0x0047F36C
// @early-stop: budget, structural ndiff=39
char EQPlayerFunctionView_guess::HandleAmmo_guess() {
    EQPlayerPcView_guess* owner_guess = (EQPlayerPcView_guess*)this;
    RecordObject_guess* object_guess = (RecordObject_guess*)owner_guess->FUN_0047c31a_guess();
    SpellState_guess* first_guess =
        object_guess->CurrentSlot_guess()->GetSelected_guess()->first_02c_guess;
    SpellState_guess* second_guess =
        object_guess->CurrentSlot_guess()->GetSelected_guess()->second_054_guess;

    int state_guess = first_guess->GetItemType_guess();
    if (state_guess != 0x13 && first_guess->GetItemType_guess() != 5 &&
        first_guess->GetItemType_guess() != 6) {
        char check_guess = first_guess->Check_guess(1) != 0;
        --check_guess;
        return check_guess & 2;
    }

    state_guess = first_guess->GetItemType_guess();
    if (second_guess == 0) {
        if (state_guess == 0x13 && first_guess->count_048_guess > 1 &&
            owner_guess->field_244_guess == 0) {
            return 2;
        }
        state_guess = first_guess->GetItemType_guess();
        if (state_guess == 0x13 && first_guess->count_048_guess == 1) {
            return 0;
        }
    } else {
        if (state_guess == 0x13 &&
            second_guess->GetItemId_guess() == first_guess->GetItemId_guess()) {
            return (char)(second_guess->count_048_guess > 0);
        }
        if ((first_guess->GetItemType_guess() == 5 && second_guess->GetItemType_guess() == 0x1b) ||
            (first_guess->GetItemType_guess() == 6 && second_guess->GetItemType_guess() == 0x1c)) {
            if (second_guess->count_048_guess <= 0) {
                g_textSink_guess->dsp_chat(pStringTable->getString(0x324b, 0));
                return 2;
            }
            return 1;
        }
        if (first_guess->GetItemType_guess() == 0x13 && second_guess->count_048_guess > 0) {
            return 2;
        }
    }
    g_textSink_guess->dsp_chat(pStringTable->getString(0x324b, 0));
    return 2;
}

// Fires the ranged item chosen by HandleAmmo_guess at `param` and redraws the hands.
// FUNCTION: TITANIUM 0x00481B3A
// @early-stop: budget, structural ndiff=202
char EQPlayerFunctionView_guess::FireRangedItem_guess(int param) {
    PlayerInfoView_guess* view = (PlayerInfoView_guess*)pCharInfo;
    if (view->GetProfile_guess()->names_010_guess.field_02c_guess == 0) {
        return 0;
    }
    char state = HandleAmmo_guess();
    if (state == 0) {
        if (view->GetProfile_guess()->names_010_guess.field_02c_guess == 0) {
            return 1;
        }
        ProfileText_guess* item = view->GetProfile_guess()->names_010_guess.field_02c_guess;
        if (param == 0) {
            return 0;
        }
        DoMissileHit_guess((EQPlayerCore_guess*)this, param, item, 0xb);
        UpdateItemSlot_guess(8, EQ_ARRAY(char, 0x006410A8), 0);
        return 1;
    }
    if (state == 1) {
        if (view->GetProfile_guess()->names_010_guess.field_054_guess == 0) {
            return 1;
        }
        ProfileText_guess* item = view->GetProfile_guess()->names_010_guess.field_054_guess;
        if (param == 0) {
            return 0;
        }
        DoMissileHit_guess((EQPlayerCore_guess*)this, param, item, 0xb);
        UpdateItemSlot_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
    } else if (state == 2) {
        if (view->GetProfile_guess()->names_010_guess.field_02c_guess == 0) {
            return 1;
        }
        if (view->GetProfile_guess()->names_010_guess.field_02c_guess->GetItemType_guess() != 0x13) {
            return 1;
        }
        if (param == 0) {
            return 0;
        }
        DoMissileHit_guess((EQPlayerCore_guess*)this, param,
                           view->GetProfile_guess()->names_010_guess.field_02c_guess, 0xb);
        if (view->GetProfile_guess()->names_010_guess.field_034_guess == 0) {
            UpdateItemSlot_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
        } else {
            UpdateItemSlot_guess(
                7, view->GetProfile_guess()->names_010_guess.field_034_guess->GetText_guess(), 0);
        }
    } else {
        return 1;
    }
    if (view->GetProfile_guess()->names_010_guess.field_02c_guess == 0) {
        if (view->GetProfile_guess()->names_010_guess.field_038_guess == 0) {
            UpdateItemSlot_guess(8, EQ_ARRAY(char, 0x006410A8), 0);
            return 1;
        }
        UpdateItemSlot_guess(
            8, view->GetProfile_guess()->names_010_guess.field_038_guess->GetText_guess(), 0);
    } else {
        UpdateItemSlot_guess(
            8, view->GetProfile_guess()->names_010_guess.field_02c_guess->GetText_guess(), 0);
    }
    return 1;
}

// Sets `value` as the avatar height of this spawn and of every spawn chained through ActorInfo +0x15C,
// recomputing each one's heights.
// FUNCTION: TITANIUM 0x00481D5D
void EQPlayer_guess::SetAvatarHeight_guess(float value) {
    EQPlayer_guess* player = this;
    do {
        player->avatarHeight = value;
        player->SetHeights_guess();
        g_display2_guess->SetActorScale_guess((void*)player->pActorInfo->actorInstance_0000_guess,
                                             player->pActorInfo->heightScale_00c4_guess, 1);
        float amount = player->FUN_00489906_guess();
        if (player->pActorInfo->actorInstance_0000_guess != 0) {
            ((ActorObject_guess*)player->pActorInfo->actorInstance_0000_guess)->Slot011_guess(amount);
        }
        player = (EQPlayer_guess*)player->pActorInfo->mount_015c_guess;
    } while (player != 0);
}

// Gets off the mount (actor info +0x15C): re-attaches to it, stops a horse and resets heights;
// /dismount (0x0046BDAB), MountEQPlayer_guess, ApplyIllusion_guess and others call it.
// FUNCTION: TITANIUM 0x00481DC7
void EQPlayer_guess::Dismount_guess() {
    int state = -1;
    if (pActorInfo != 0 && pActorInfo->mount_015c_guess != 0) {
        if (!((EQPlayerRaceView_guess*)pActorInfo->mount_015c_guess)->IsHorseRace_guess()) {
            state = 3;
        }
        AttachPlayerToPlayerDag_guess(pActorInfo->mount_015c_guess, state);
        if (((EQPlayerRaceView_guess*)pActorInfo->mount_015c_guess)->IsHorseRace_guess()) {
            ((EQPlayer_guess*)pActorInfo->mount_015c_guess)->motion_030.speedRun = 0.0f;
            ((EQPlayer_guess*)pActorInfo->mount_015c_guess)->motion_030.field_28 = 0.0f;
            if (this == g_controlledPlayer_guess) {
                g_player905cf8_guess = g_controlledPlayer_guess;
            }
            SetHeights_guess();
        }
        if (this == g_controlledPlayer_guess && pinstCSpellBookWnd_guess != 0 &&
            pinstCSpellBookWnd_guess->IsVisible_guess()) {
            pinstCSpellBookWnd_guess->Deactivate();
        }
        ((EQPlayer_guess*)pActorInfo->mount_015c_guess)->pActorInfo->rider_0160_guess = 0;
        pActorInfo->mount_015c_guess = 0;
        motion_030.field_20 = 0.0f;
        UpdatePlayerVisibility_guess();
    }
}

// Hides the hair (point 8) while a helm model is attached (point 1), else restores it.
// FUNCTION: TITANIUM 0x00481E9C
void EQPlayer_guess::UpdateHairForHelm_guess() {
    if (race != Race_VahShir) {
        if (((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot085_guess(8)) {
            if (((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot085_guess(1)) {
                if (((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot086_guess(1) != 0) {
                    ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot059_guess(8, EQ_ARRAY(char, 0x006410A8));
                    return;
                }
                SetFacialFeature_guess(eyes2, 2);
                SetFeatureColor_guess(hairColor, 2);
            }
        }
    }
}

struct TargetState_guess {
    char pad_000_guess[0xb54];
    int field_b54_guess;
};

#define g_targetState_guess EQ_GLOBAL(TargetState_guess*, 0x00988DF0)

// IT models for old skeletons, wear slots `index` to 6 (-1: all): helm 5000+, chest 4010+, arms 7000+,
// wrist 8000+, legs 4020+, feet 9000+, offset by GetRaceOffsetForAttachmentITs_guess; robes (10-16)
// keep only head and chest. Then replays the stand-state idle.
// FUNCTION: TITANIUM 0x00481F2C
// @early-stop: budget, structural ndiff=178
void EQPlayer_guess::SetDefaultITAttachments_guess(int index) {
    if ((char)pActorInfo->FUN_0048f019_guess() != 0) {
        return;
    }

    int specialRace = 0;
    if (((EQPlayerCore_guess*)this)->LegalPlayerRace_guess(-1) == 1) {
        int lastIndex = index;
        if (index == -1) {
            lastIndex = 6;
        }
        if (((EQPlayerCore_guess*)this)->field_1e4_guess >= 10 &&
            ((EQPlayerCore_guess*)this)->field_1e4_guess <= 16) {
            specialRace = 1;
        }
        index = index < 0 ? 0 : index;

        while (1) {
            int limit = lastIndex;
            if (limit > 5) {
                limit = 6;
            }
            if (limit < index) {
                break;
            }

            int value = colors_01bc_guess[index];
            Face_guess face;
            face.blue_0000_guess = (unsigned char)value;
            face.green_0001_guess = (unsigned char)(value >> 8);
            face.red_0002_guess = (unsigned char)(value >> 16);
            face.alpha_0003_guess = (unsigned char)(value >> 24);
            int secondary = -1;
            int primary = 0;
            int auxiliary = 0;
            int current = ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(index);
            int item = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, 0);

            if (index == 0) {
                int kind = race;
                if ((kind == 3 && specialRace != 0) || showHelm_01b8_guess == 0) {
                    primary = 0;
                } else if (kind == 2) {
                    if (current == 0xf1 || current >= 3) {
                        primary = 0x13a5;
                    } else {
                        primary = current + 5000;
                    }
                } else if (current == 0xf0) {
                    if (kind == 0x80 || kind == 0x82) {
                        primary = 0x138b;
                    } else {
                        primary = 0x13a4;
                    }
                } else if (current == 3) {
                    if (kind == 0x80 || kind == 0x82 || kind == 0x14a) {
                        primary = current + 5000;
                    } else {
                        primary = 0x13a4;
                    }
                } else if (current == 0xf1) {
                    primary = 0x13a5;
                } else {
                    primary = current + 5000;
                }
            } else if (index == 1) {
                secondary = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, index);
                if (current >= 0) {
                    if (current < 4) {
                        if (current == 3) {
                            primary = 6000;
                        }
                        auxiliary = current + 0xfaa;
                        if (race == Race_Gnome && gender == 1 && current == 1) {
                            auxiliary = 0;
                        }
                        item = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, 0);
                    } else if (current > 9 && current < 17 && race == Race_Erudite) {
                        auxiliary = current + 0xf96;
                        ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot059_guess(
                            1, EQ_ARRAY(char, 0x006410A8));
                    }
                }
            } else if (index == 2) {
                secondary = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, 1);
                if (current == 0) {
                    primary = 7000;
                } else if (current == 1) {
                    primary = 0x1b5a;
                } else if (current == 2) {
                    primary = 0x1b5c;
                } else if (current == 3) {
                    primary = 0x1b5e;
                }
                auxiliary = primary + 1;
            } else if (index == 3) {
                secondary = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, 1);
                if (current == 0) {
                    primary = 8000;
                } else if (current == 1) {
                    primary = 0x1f42;
                } else if (current == 2) {
                    primary = 0x1f44;
                } else if (current == 3) {
                    primary = 0x1f46;
                }
                auxiliary = primary + 1;
            } else if (index == 5) {
                primary = current + 0xfb4;
            } else if (index == 6) {
                secondary = ((EQPlayerCore_guess*)this)->GetArmorAttachSlot_guess(index, 1);
                if (current == 0) {
                    primary = 9000;
                } else if (current == 1) {
                    primary = 0x232a;
                } else if (current == 2) {
                    primary = 0x232c;
                } else if (current == 3) {
                    primary = 0x232e;
                }
                auxiliary = primary + 1;
            }

            if (specialRace != 0 && index != 0 && index != 1) {
                primary = 0;
                auxiliary = 0;
            }

            char text[128];
            if (item != -1) {
                if (primary == 0) {
                    FUN_0060e450_guess(text, EQ_ARRAY(char, 0x006410A8));
                } else {
                    int offset = ((EQPlayerCore_guess*)this)->GetRaceOffsetForAttachmentITs_guess();
                    sprintf(text, "IT%d", offset + primary);
                }
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot059_guess(item, text);
                ((EQPlayerCore_guess*)this)->SetAttachmentTint_guess(item, &face);
            }
            if (secondary != -1) {
                if (auxiliary == 0) {
                    FUN_0060e450_guess(text, EQ_ARRAY(char, 0x006410A8));
                } else {
                    int offset = ((EQPlayerCore_guess*)this)->GetRaceOffsetForAttachmentITs_guess();
                    sprintf(text, "IT%d", offset + auxiliary);
                }
                ((Target_guess*)pActorInfo->actorInstance_0000_guess)->Slot059_guess(secondary, text);
                ((EQPlayerCore_guess*)this)->SetAttachmentTint_guess(secondary, &face);
            }
            if (index == 0) {
                UpdateHairForHelm_guess();
            }
            ++index;
        }

        if (g_targetState_guess->field_b54_guess == 2 && pActorInfo->currentAnimation_0134_guess != 0x47) {
            ((AnimPlayer_guess*)GetAnimation_guess())->Play_guess(0x47, 1, 0, 1.0f, 2);
        } else if (standState == 'd') {
            ((AnimPlayer_guess*)GetAnimation_guess())->Play_guess(0x20, 1, 0, 1.0f, 2);
        } else if (standState != 's') {
            ((AnimPlayer_guess*)GetAnimation_guess())->Play_guess(0x1a, 1, 0, 1.0f, 2);
        }
    }
}

// Helm material `value` with tint `field`: newer models via SetDefaultITAttachments_guess, Vah Shir via
// race helm items (IT 661-663, 666-668), others via the head sprite; showhelm (+0x1B8) 0 skips it.
// Reports OP_WearChange (0x7441) for wear slot 0 unless `one`.
// FUNCTION: TITANIUM 0x0048236E
// @early-stop: budget, structural ndiff=176
bool EQPlayer_guess::SwapHead_guess(int value, int zero, int field, int one) {
    struct MessageData_guess {
        short spawnId_guess;
        short value_guess;
        int result_guess;
        char zero_guess;
    };
    ActorInfo_guess* actor = pActorInfo;
    int textureFlag = 1;
    char spriteName[64];
    char itemName[16];
    char actorName[16];
    MessageData_guess message;

    if (actor == 0 || actor->actorInstance_0000_guess == 0) {
        return false;
    }
    if (showHelm_01b8_guess == 0) {
        return true;
    }

    if (actor->actorDef_012c_guess != 0 &&
        ((ChildState_guess*)actor->actorDef_012c_guess)->field_034_guess != 0) {
        if (g_appearanceState_guess->field_2d58_guess != 0 && bodyType != 8 && bodyType != 3 &&
            bodyType != 5 && bodyType != 0xc) {
            ((EQPlayerCore_guess*)this)->FUN_0047b8d5_guess((int)EQ_ARRAY(char, 0x006974CC));
        }
        materials_01e0_guess[0] = value;
        colors_01bc_guess[0] = field;
        SetDefaultITAttachments_guess(0);
        if (one != 0) {
            return true;
        }
        message.spawnId_guess = (short)spawnId;
        message.zero_guess = 0;
        message.result_guess = ((EQPlayerPcView_guess*)this)->GetArmorTint_guess(0);
        message.value_guess = (short)value;
        FUN_004912b1_guess((const char*)EQ_ARRAY(char, 0x00905CA0), OP_WearChange,
                           (const int*)&message, 9, 1);
        return true;
    }

    if (race == Race_VahShir) {
        if (g_appearanceState_guess->field_2d58_guess != 0 && bodyType != 8 && bodyType != 3 &&
            bodyType != 5 && bodyType != 0xc) {
            ((EQPlayerCore_guess*)this)->FUN_0047b8d5_guess((int)EQ_ARRAY(char, 0x006974CC));
        }

        const char* itemText;
        if (value < 1) {
            colors_01bc_guess[0] = field;
            itemText = EQ_ARRAY(char, 0x006410A8);
        } else if (value < 4 || value == 0xf0) {
            if (value == 0xf0) {
                value = 3;
            }
            if (gender == 1) {
                value += 0x294;
            } else {
                value += 0x299;
            }
            sprintf(itemName, (char*)EQ_ARRAY(char, 0x0064251C), value);
            colors_01bc_guess[0] = field;
            itemText = itemName;
        } else if (value < 0x295 ||
                   (value > 0x297 && (value < 0x29a || value > 0x29c))) {
            colors_01bc_guess[0] = field;
            itemText = EQ_ARRAY(char, 0x006410A8);
        } else {
            sprintf(itemName, (char*)EQ_ARRAY(char, 0x0064251C), value);
            colors_01bc_guess[0] = field;
            itemText = itemName;
        }
        materials_01e0_guess[0] = value;
        UpdateItemSlot_guess(0, itemText, one);
        return true;
    }

    int spriteId = value;
    if (spriteId > 0xef && spriteId < 0x100) {
        spriteId = ((EQPlayerCore_guess*)this)->GetAttachedHelmITNum_guess(spriteId, &textureFlag);
    }
    if ((char)actor->FUN_0048f019_guess() == 0 && spriteId == 7) {
        spriteId = 2;
        value = spriteId;
        if (race == Race_Iksar) {
            spriteId = 3;
            value = spriteId;
        }
    }
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(actorName);
    if (spriteId >= 0 && spriteId < 0xf0) {
        UpdateItemSlot_guess(0, EQ_ARRAY(char, 0x006410A8), one);
        sprintf(spriteName,
                (char*)((char)actor->FUN_0048f019_guess() == 0
                            ? EQ_ARRAY(char, 0x0064813C)
                            : EQ_ARRAY(char, 0x00648154)),
                actorName, spriteId);
        char result = actor->visual_000_guess->Slot065_guess(
            spriteName, field, textureFlag != 0, race == Race_Erudite, race == Race_Barbarian);
        materials_01e0_guess[0] = value;
        colors_01bc_guess[0] = field;
        if (one == 0) {
            message.spawnId_guess = (short)spawnId;
            message.zero_guess = 0;
            message.result_guess = ((EQPlayerPcView_guess*)this)->GetArmorTint_guess(0);
            message.value_guess = (short)value;
            FUN_004912b1_guess((const char*)EQ_ARRAY(char, 0x00905CA0), OP_WearChange,
                               (const int*)&message, 9, 1);
        }
        return result != 0;
    }

    materials_01e0_guess[0] = value;
    colors_01bc_guess[0] = field;
    const char* itemText;
    if (spriteId < 0xf0) {
        itemText = EQ_ARRAY(char, 0x006410A8);
    } else {
        sprintf((char*)&message, (char*)EQ_ARRAY(char, 0x0064251C), spriteId);
        itemText = (const char*)&message;
    }
    UpdateItemSlot_guess(0, itemText, one);
    sprintf(spriteName, (char*)EQ_ARRAY(char, 0x0064813C), actorName, 0);
    return actor->visual_000_guess->Slot065_guess(
               spriteName, field, textureFlag != 0, race == Race_Erudite, race == Race_Barbarian) != 0;
}

// Unlinks this spawn from every other one: clears their +0x158 links to it, dismounts those whose
// ActorInfo +0x15C is this spawn, and dismounts this spawn when another's +0x160 points to it.
// FUNCTION: TITANIUM 0x00482922
void EQPlayer_guess::ClearMountLinks_guess() {
    for (EQPlayer_guess* player = g_playerList_guess; player != 0; player = player->pNext) {
        if (player != this) {
            if (player->pActorInfo->field_158 == this) {
                player->pActorInfo->field_158 = 0;
            }
            if (player->pActorInfo->mount_015c_guess == this) {
                player->Dismount_guess();
            }
            if (player->pActorInfo->rider_0160_guess == this) {
                Dismount_guess();
            }
        }
    }
}

// One attack on `target`. `kind` is the inventory slot (11 range, 13 primary, 14 secondary), 100 a skill
// `skill`, 0x65 a primary or bare-hand swing. Checks the delay (ModifyAttackSpeed), standing ('d'), and
// range (CanIHit); DoMissileHit_guess performs it.
// FUNCTION: TITANIUM 0x0048297B
// @early-stop: budget, structural ndiff=256
int EQPlayerCore_guess::DoAttack(unsigned char kind, unsigned char skill, int target) {
    float bonus = 0.0f;
    char fromRequest = 0;
    unsigned int* timer = 0;
    ProfileText_guess* item;
    int delay;
    // Nothing happens without a character object and an actor, for an illegal target, or for our own spawn
    // while 0x0092384C is set. Every other exit also returns 1; the value says nothing about a hit.
    if ((g_flag92384c_guess != 0 && this == EQ_GLOBAL(EQPlayerCore_guess*, 0x00905CE4)) ||
        pCharInfo_0218_guess == 0 || handler == 0 || !CanAttack_guess(target)) {
        return 1;
    }
    PlayerCtx_guess* ctx = pCharInfo_0218_guess;
    if (ctx == 0) {
        return 1;
    }
    // A player who attacks loses Sanctuary (SPA 312).
    if (type_0244_guess == 0 && ((Command_guess*)ctx)->TotalSpellAffects_guess(0x138, 1, 0, 1) != 0) {
        int affect;
        while ((affect = ((PcCharInfo_guess*)ctx)->GetSpellAffect_guess(0x138, 0)) != 0) {
            ((PcCharInfo_guess*)ctx)->RemovePCAffect_guess(affect);
        }
    }
    BreakInvisibility_guess();
    if (!CanPcUseSkill_guess(kind, skill)) {
        return 1;
    }
    if (kind == 0) {
        return 1;
    }
    switch (kind) {
    // `kind` is the slot: 11 range, 13 primary, 14 secondary. Going ranged shows the range item in the
    // secondary hand and nothing in the primary; going back to melee puts both weapons back.
    case 0xb: {
        AttackState_guess* state = Attack_guess();
        timer = &state->timer_060_guess;
        if (state != 0) {
            if (state->kind_09d_guess != 0xb) {
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(7, "0", 0);
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(8, "0", 0);
                if (ctx->GetProfile_guess()->names_010_guess.GetFirst_guess() != 0) {
                    ((EQPlayer_guess*)this)->UpdateItemSlot_guess(
                        8, ctx->GetProfile_guess()->names_010_guess.GetFirst_guess()->GetText_guess(), 0);
                }
            }
            // With auto-fire (0x009858C8) on, a ranged attack switches it off (0x0049994C) and returns 0, the
            // only 0 this function returns.
            if (g_flag9858c8_guess != 0) {
                g_autoAttack_guess.SetAutoFire_guess(0);
                return 0;
            }
            Attack_guess()->kind_09d_guess = 0xb;
        }
        break;
    }
    // Primary (13) and secondary (14): coming back from ranged puts the two weapon models back in hands 7 and
    // 8. Primary and range share the swing timer at actor +0x60; the secondary has its own at +0xDC.
    case 0xd: {
        AttackState_guess* state = Attack_guess();
        timer = &state->timer_060_guess;
        if (state != 0) {
            if (state->kind_09d_guess == 0xb) {
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(
                    7, ctx->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0
                           ? ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetText_guess()
                           : "0",
                    0);
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(
                    8, ctx->GetProfile_guess()->names_010_guess.GetThird_guess() != 0
                           ? ctx->GetProfile_guess()->names_010_guess.GetThird_guess()->GetText_guess()
                           : "0",
                    0);
            }
            Attack_guess()->kind_09d_guess = 0xd;
        }
        break;
    }
    case 0xe: {
        AttackState_guess* state = Attack_guess();
        timer = &state->timer_0dc_guess;
        if (state != 0) {
            if (state->kind_09d_guess == 0xb) {
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(
                    7, ctx->GetProfile_guess()->names_010_guess.GetSecond_guess() != 0
                           ? ctx->GetProfile_guess()->names_010_guess.GetSecond_guess()->GetText_guess()
                           : "0",
                    0);
                ((EQPlayer_guess*)this)->UpdateItemSlot_guess(
                    8, ctx->GetProfile_guess()->names_010_guess.GetThird_guess() != 0
                           ? ctx->GetProfile_guess()->names_010_guess.GetThird_guess()->GetText_guess()
                           : "0",
                    0);
            }
            Attack_guess()->kind_09d_guess = 0xe;
        }
        break;
    }
    }
    if (kind != 0xd && kind != 0xe && kind != 0xb) {
        switch (kind) {
        // Skill attacks: backstab (8) needs a piercer (item type 2) in the primary, else string 12874
        // (players only). The skill's
        // own reuse delay, less ReduceSkillTimer (SPA 227) seconds, gates it; then it must be standing and in
        // range.
        case 100: {
            if (g_skillRequest_guess == 0) {
                return 1;
            }
            g_skillRequest_guess->baseDamage_0133_guess = ctx->GetSkillBaseDamage_guess(skill, target);
            g_skillRequest_guess->field_134_guess = 0x16;
            g_skillRequest_guess->skill_12d_guess = skill;
            g_skillItem_guess->Load_guess(g_skillRequest_guess);
            item = g_skillItem_guess;
            if (skill == 8) {
                ProfileText_guess* primary = ctx->GetProfile_guess()->names_010_guess.GetSecond_guess();
                if ((primary == 0 || primary->GetItemType_guess() != 2) && type_0244_guess == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x324a, 0));
                    return 1;
                }
            }
            delay = ModifyAttackSpeed_guess(Attack_guess()->delay_118_guess, 0);
            unsigned int* lastTime = &Attack_guess()->timer_114_guess;
            unsigned int now = GetTimeMs_guess();
            if (now - *lastTime < delay &&
                (type_0244_guess != 0 || (Attack_guess()->field_107c_guess == 0 && skill != 'G'))) {
                if (type_0244_guess != 1 || Attack_guess()->field_103c_guess <= 1) {
                    return 1;
                }
            }
            if (Attack_guess()->field_107c_guess == 0 && skill != 'G') {
                *lastTime = now;
                Attack_guess()->delay_118_guess = g_skillDelays_guess[skill]->delay_004_guess;
                Attack_guess()->delay_118_guess +=
                    // The next use is the skill's reuse time less one second per point of ReduceSkillTimer
                    // (SPA 227) for this skill. Skill 71 and a pending actor +0x107C skip the timer.
                    ((Command_guess*)ctx)->TotalSpellAffects_guess(0xe3, 1, skill, 1) * -1000;
            }
            if (standState_0251_guess != 'd') {
                pEverQuest->dsp_chat(pStringTable->getString(standState_0251_guess == 'f' ? 0x3050 : 0x3051, 0),
                                     0xd, 1);
            } else if (CanIHit_guess(target, 0.0f) || g_ownerState_guess != 0) {
                DoMissileHit_guess(this, target, item, kind);
            }
            Attack_guess()->field_107c_guess = 0;
            return 1;
        }
        // A primary swing, bare-handed (hand to hand, skill 28) when the primary is empty.
        case 0x65: {
            item = ctx->GetProfile_guess()->names_010_guess.GetSecond_guess();
            if (item == 0) {
                g_skillRequest_guess->baseDamage_0133_guess = ctx->GetSkillBaseDamage_guess(SkillHandtoHand, target);
                g_skillRequest_guess->field_134_guess = 0x16;
                g_skillRequest_guess->skill_12d_guess = 0x1c;
                g_skillItem_guess->Load_guess(g_skillRequest_guess);
                item = g_skillItem_guess;
            }
            if (standState_0251_guess != 'd') {
                pEverQuest->dsp_chat(pStringTable->getString(standState_0251_guess == 'f' ? 0x3050 : 0x3051, 0),
                                     0xd, 1);
                return 1;
            }
            if (CanIHit_guess(target, 0.0f) || g_ownerState_guess != 0) {
                DoMissileHit_guess(this, target, item, 0xd);
            }
            return 1;
        }
        }
        return 1;
    }
    // Weapon swings: an empty range slot says 0x23BE; an empty hand fights hand to hand, with +0x1280 as the
    // skill level and +0x1284 as the delay when set.
    item = ctx->GetInventorySlot_guess(kind);
    if (item != 0) {
        if (!item->IsReady_guess()) {
            return 1;
        }
    } else {
        if (kind == 0xb) {
            // "You do not have a ranged weapon equipped."
            pEverQuest->dsp_chat(pStringTable->getString(0x23be, 0));
            return 1;
        }
        g_skillRequest_guess->baseDamage_0133_guess = ctx->GetProfile_guess()->field_1280;
        if (g_skillRequest_guess->baseDamage_0133_guess <= 0) {
            g_skillRequest_guess->baseDamage_0133_guess = ctx->GetSkillBaseDamage_guess(SkillHandtoHand, target);
        }
        g_skillRequest_guess->field_134_guess = 0x16;
        g_skillRequest_guess->skill_12d_guess = 0x1c;
        g_skillItem_guess->Load_guess(g_skillRequest_guess);
        item = g_skillItem_guess;
        fromRequest = 1;
    }
    if (item == 0) {
        return 1;
    }
    if (!item->IsReady_guess() && item->GetItemType_guess() != 0xd && item->GetItemType_guess() != 0x16) {
        return 1;
    }
    int base;
    // Delay: the hand-to-hand item (type 0x16) uses the skill delay table adjusted by the ammo slot, weapons
    // their delay in tenths of a second; GetDelay_guess applies haste (bows, type 5, separately).
    if (item->GetItemType_guess() == 0x16) {
        delay = g_skillDelays_guess[item->GetSkill_guess()]->delay_004_guess;
        ModifyHandToHandDelay_guess(&delay, (int)ctx->GetProfile_guess()->names_010_guess.GetAmmo_guess());
        int skillType = item->GetSkill_guess();
        int override;
        if (fromRequest != 0 && skillType == 0x1c &&
            (override = pCharInfo_0218_guess->GetProfile_guess()->field_1284) > 0) {
            base = override;
        } else {
            base = delay;
        }
    } else {
        base = item->GetSkill_guess() * 100;
    }
    unsigned int wait = ModifyAttackSpeed_guess(base, item->GetItemType_guess() == 5);
    unsigned int now = GetTimeMs_guess();
    unsigned int old = *timer;
    // Too early. An NPC with actor +0x103C above 1, or any actor with +0x1034 set, swings anyway.
    if (now - old < wait) {
        if (type_0244_guess != 1 || Attack_guess() == 0 || Attack_guess()->field_103c_guess <= 1) {
            AttackState_guess* state = Attack_guess();
            if (state == 0 || state->field_1034_guess == 0) {
                if (type_0244_guess == 1 && state != 0 && state->field_103c_guess < 2) {
                    state->field_103c_guess = 0;
                }
                return 1;
            }
        }
    }
    *timer = now;
    if (type_0244_guess == 0) {
        if (standState_0251_guess != 'd') {
            pEverQuest->dsp_chat(pStringTable->getString(standState_0251_guess == 'f' ? 0x3050 : 0x3051, 0),
                                 0xd, 1);
            return 1;
        }
        if (kind == 0xb) {
            // Ranged attacks need 30 units of distance.
            if (target != 0 && g_rangeCheck_guess->PlayerDistance_guess(this, target, 0.0f) < 30.0f) {
                token_string_to_client_guess(ctx, 0x319a, 0xf, 0);
                return 1;
            }
            if (item->GetItemType_guess() == 5) {
                bonus = (float)item->GetDamage_guess(1);
                if (ctx->GetProfile_guess()->names_010_guess.GetRange_guess() != 0 &&
                    ctx->GetProfile_guess()->names_010_guess.GetRange_guess()->GetItemType_guess() == 0x1b) {
                    bonus = (float)ctx->GetProfile_guess()->names_010_guess.GetRange_guess()->GetDamage_guess(1) +
                            bonus;
                }
            } else if (ctx->GetProfile_guess()->names_010_guess.GetRange_guess() != 0) {
                bonus = (float)ctx->GetProfile_guess()->names_010_guess.GetRange_guess()->GetDamage_guess(1);
            } else if (ctx->GetProfile_guess()->names_010_guess.GetFirst_guess() != 0) {
                bonus = (float)ctx->GetProfile_guess()->names_010_guess.GetFirst_guess()->GetDamage_guess(1);
            }
        }
        // Ranged reach is the bow's range plus the arrow's (or the thrown item's); a shot out of range gives
        // the timer back.
        if (!CanIHit_guess(target, bonus) && g_ownerState_guess == 0) {
            if (kind == 0xb) {
                *timer = old;
            }
            return 1;
        }
    } else if (type_0244_guess == 1 && Attack_guess() != 0 && Attack_guess()->field_103c_guess < 2) {
        Attack_guess()->field_103c_guess = 1;
    }
    char ok;
    switch (kind) {
    case 0xb:
        // Ranged fires through FireRangedItem_guess. The secondary swings only if the dual-wield roll
        // (CheckDualWield_guess) succeeds. A second swing follows a successful double-attack roll
        // (CanDoubleAttack_guess): rolled for the primary every time, for the secondary only with +0xFC0 >=
        // 150 or GiveDoubleAttack (SPA 225).
        FireRangedItem_guess(target);
        return 1;
    case 0xd:
        DoMissileHit_guess(this, target, item, kind);
        ok = ctx->CanDoubleAttack_guess(target, kind);
        break;
    case 0xe:
        if (ctx->CheckDualWield_guess(target) != 1) {
            return 1;
        }
        DoMissileHit_guess(this, target, item, kind);
        // Secondary: the dual-wield roll first (0x0041EDAC, 1-375). Its extra swing needs +0xFC0 at 150 or
        // more or GiveDoubleAttack (SPA 225), then the same double-attack roll as the primary (0x0041EE86,
        // skill 20, 1-500).
        if (ctx->GetProfile_guess()->field_fc0 < 0x96 &&
            ((Command_guess*)ctx)->TotalSpellAffects_guess(0xe1, 1, 0, 1) == 0) {
            return 1;
        }
        ok = ctx->CanDoubleAttack_guess(target, kind);
        break;
    default:
        return 1;
    }
    if (ok != 1) {
        return 1;
    }
    DoMissileHit_guess(this, target, item, kind);
    return 1;
}

// Head-in-liquid state (actor +0xAC). For the controlled spawn it swaps the underwater loop (0xA1, 0xA0
// for state 7) and state 5 sets display mode 0x16. A rider going under dismounts and loses effect 113
// (summon horse).
// FUNCTION: TITANIUM 0x00483439
void EQPlayer_guess::headEnvironmentChange_guess(unsigned char state) {
    unsigned char old = pActorInfo->headEnvironment_00ac_guess;
    if (old == state) {
        return;
    }
    if (this != g_player905cf8_guess) {
        pActorInfo->headEnvironment_00ac_guess = state;
        return;
    }
    switch (old) {
    case 5:
        g_resourceUser_guess->WaveStop_guess(0xa1);
        g_display2_guess->UpdateSoundEnvironment_guess();
        break;
    case 6:
    case 8:
    case 9:
    case 10:
        g_resourceUser_guess->WaveStop_guess(0xa1);
        break;
    case 7:
        g_resourceUser_guess->WaveStop_guess(0xa0);
        break;
    }
    int mode = -1;
    pActorInfo->headEnvironment_00ac_guess = state;
    switch (state) {
    case 5:
        mode = 0xa1;
        g_display2_guess->FUN_00438fc2_guess(0x16);
        break;
    case 6:
    case 8:
    case 9:
    case 10:
        mode = 0xa1;
        break;
    case 7:
        mode = 0xa0;
        break;
    }
    ((EQPlayerPcView_guess*)this)->GetPcClient_guess();
    if (pActorInfo != 0) {
        EQPlayer_guess* other = (EQPlayer_guess*)pActorInfo->rider_0160_guess;
        if (other != 0) {
            if (other == g_controlledPlayer_guess) {
                other->Dismount_guess();
            }
            if (g_pcClient_guess != 0) {
                int spell = g_pcClient_guess->GetSpellAffect_guess(0x71, 0);
                g_pcClient_guess->RemovePCAffect_guess(spell);
            }
        }
    }
    if (mode != -1) {
        g_resourceUser_guess->Apply_guess(mode, 0);
    }
}

struct StateMessage_guess {
    unsigned short spawnId_guess;
    unsigned short type_guess;
    unsigned int state_guess;
};

struct StateIndex_guess {
    int field_000_guess;
    int index_004_guess;
};

struct StateIndexOwner_guess {
    int field_000_guess;
    int field_004_guess;
    StateIndex_guess* index_008_guess;
};

struct StateBuffer_guess {
    char pad_000_guess[0x10c];
    unsigned char state_guess[1];
};

struct StateNotifyMethods_guess {
    // EXTERNAL: TITANIUM 0x0040E934 StateNotifyMethods_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int id_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00411F2F StateNotifyMethods_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(int value_guess);
};

struct StateNotify_guess {
    char pad_000_guess[0xc280];
    StateNotifyMethods_guess methods_c280_guess;
};

#define g_stateNotify_guess EQ_GLOBAL(StateNotify_guess*, 0x00905D00)

#define g_stateValue923994_guess EQ_GLOBAL(int, 0x00923994)
#define g_stateValue905d28_guess EQ_GLOBAL(int, 0x00905D28)
#define g_stateValue923864_guess EQ_GLOBAL(int, 0x00923864)
#define g_stateValue923868_guess EQ_GLOBAL(int, 0x00923868)

// Stand state (+0x251; EQEmu animation codes: 'd' 100 stand, 'n' sit, 'o' crouch, 'i' kneel, 's' lying,
// 'x' corpse): blocks standing into a ceiling, tells the server, and plays the matching animation.
// FUNCTION: TITANIUM 0x00483556
// @early-stop: budget, diff ndiff=146
void EQPlayer_guess::ChangePosition_guess(unsigned char state) {
    int dispatch;
    int zero = 0;
    PlayerVec3_guess position;
    StateMessage_guess message;

    if (standState == state) {
        return;
    }
    if (pActorInfo != 0 && state != 's') {
        pActorInfo->field_155 = (unsigned char)zero;
    }
    if (pActorInfo != 0 && state == 'n' && pActorInfo->mount_015c_guess != 0) {
        return;
    }

    dispatch = ((EQPlayerPcView_guess*)this)->FUN_0047c31a_guess();
    if (this == g_player905cf8_guess) {
        g_value923860_guess = 0;
        if (this == g_controlledPlayer_guess) {
            if (g_stateValue923994_guess != 0) {
                g_stateValue923994_guess = 0;
                g_stateValue905d28_guess = 0;
                g_textSink_guess->dsp_chat(pStringTable->getString(0x3002, 0));
            }
            if (g_stateValue923864_guess != 0) {
                g_textSink_guess->dsp_chat(pStringTable->getString(0x30d1, 0));
                g_stateValue923864_guess = 0;
                g_stateValue923868_guess = 0;
            }
            if (standState == 'n') {
                g_textSink_guess->Clear_guess();
            }
        }
        if (g_display2_guess->FUN_0043745d_guess() != 0) {
            if (standState == 'd' && state == 'o') {
                standState = 'o';
                if (FUN_0048bb83_guess(&motion_030, 0) == 0 ||
                    pActorInfo->ceilingHeight_01b0_guess - motion_030.pos.z < heightOffset_0238_guess) {
                    standState = 'd';
                    motion_030.pos.z += FUN_00489a32_guess();
                    PlayerAttachment_guess* attachment = FUN_004898d6_guess();
                    if (attachment != 0) {
                        position = *attachment->GetPosition_guess();
                        position.z += FUN_00489a32_guess();
                        attachment->SetPosition_guess(&position);
                    }
                } else {
                    standState = 'd';
                }
            } else if (standState == 'o' && (state == 'd' || state == 'n')) {
                standState = state;
                if (FUN_0048bb83_guess(&motion_030, 0) == 0 ||
                    pActorInfo->ceilingHeight_01b0_guess - motion_030.pos.z < heightOffset_0238_guess) {
                    standState = 'o';
                    return;
                }
                standState = 'o';
            }
        }
    }

    if (dispatch != 0) {
        message.spawnId_guess = (unsigned short)spawnId;
        // OP_SpawnAppearance type 14: animation.
        message.type_guess = 0x0e;
        message.state_guess = state;
        FUN_004912b1_guess(EQ_ARRAY(char, 0x00905CA0), OP_SpawnAppearance, (const int*)&message, 8, 1);
        StateBuffer_guess* buffer = (StateBuffer_guess*)dispatch;
        StateIndexOwner_guess* owner = (StateIndexOwner_guess*)dispatch;
        buffer->state_guess[owner->index_008_guess->index_004_guess] = state;
    }

    switch (state) {
    case 'd':
        if (standState == 'o') {
            PlayerAttachment_guess* attachment = GetAnimation_guess();
            attachment->Apply_guess(0x18, 1, 1, 1.0f, 1);
        } else if (standState == 'i' || pActorInfo->currentAnimation_0134_guess == 0x24) {
            PlayerAttachment_guess* attachment = GetAnimation_guess();
            attachment->Apply_guess(0x24, 1, 1, 1.0f, 1);
        } else if (standState != 'f') {
            PlayerAttachment_guess* attachment = GetAnimation_guess();
            attachment->Apply_guess(0x21, 1, 1, 1.0f, 1);
        }
        break;
    case 'i': {
        PlayerAttachment_guess* attachment = GetAnimation_guess();
        attachment->Apply_guess(0x24, 1, 0, 1.0f, 1);
        motion_030.speedRun = 0.0f;
        motion_030.field_28 = 0.0f;
        break;
    }
    case 'n': {
        PlayerAttachment_guess* attachment = GetAnimation_guess();
        attachment->Apply_guess(0x21, 1, 0, 1.0f, 1);
        motion_030.speedRun = 0.0f;
        motion_030.field_28 = 0.0f;
        pActorInfo->sitStartTime_0070_guess = g_display2_guess->frameTime_0148_guess;
        break;
    }
    case 'o':
        if (pActorInfo->currentAnimation_0134_guess != 0x18 && pActorInfo->currentAnimation_0134_guess != 0x16) {
            PlayerAttachment_guess* attachment = GetAnimation_guess();
            attachment->Apply_guess(0x18, 1, 0, 1.0f, 1);
        }
        break;
    case 's':
        if (pActorInfo != 0 && pActorInfo->mount_015c_guess != 0) {
            Dismount_guess();
            if (g_stateNotify_guess != 0 && this == g_controlledPlayer_guess) {
                int stateText_guess = g_stateNotify_guess->methods_c280_guess.FindBuffWithEffect_guess(0x71, 0);
                g_stateNotify_guess->methods_c280_guess.RemovePCAffect_guess(stateText_guess);
            }
        }
        if (pActorInfo->currentAnimation_0134_guess != 0x10) {
            PlayerAttachment_guess* attachment = GetAnimation_guess();
            attachment->Apply_guess(0x10, 1, 0, 1.0f, 1);
        }
        motion_030.speedRun = 0.0f;
        motion_030.field_28 = 0.0f;
        break;
    default:
        break;
    }

    standState = state;
    ((EQPlayerCore_guess*)this)->SetPlayerPitchType_guess();
}

// Mounts `mount`: refused with message 0xFE3 when there is no headroom, 0x1594 when the rider point is
// missing; both remove effect 113 (summon horse). A horse mount becomes the controlled spawn.
// FUNCTION: TITANIUM 0x00483958
// @early-stop: budget, diff ndiff=4
void EQPlayer_guess::MountEQPlayer_guess(EQPlayer_guess* mount) {
    EQPlayer* player = (EQPlayer*)this;
    EQPlayer_guess* playerGuess = (EQPlayer_guess*)player;
    int state = -1;
    if (mount == 0) {
        return;
    }
    if (mount->pActorInfo == 0) {
        return;
    }
    if (player->pActorInfo == 0) {
        return;
    }
    if (((ActorInfo_guess*)player->pActorInfo)->mount_015c_guess != 0) {
        if (((ActorInfo_guess*)player->pActorInfo)->mount_015c_guess == mount) {
            return;
        }
        playerGuess->Dismount_guess();
    }
    if (g_display2_guess->field_128 == 0) {
        ((ActorInfo_guess*)mount->pActorInfo)->rider_0160_guess = player;
    }
    if (((EQPlayerRaceView_guess*)mount)->IsHorseRace_guess() &&
        ((EQPlayerCore_guess*)player)->FUN_0047a387_guess()) {
        ((ActorInfo_guess*)mount->pActorInfo)->rider_0160_guess = player;
    }
    if (player == (EQPlayer*)g_controlledPlayer_guess &&
        playerGuess->FUN_0048bb83_guess((PlayerMotion_guess*)&player->Y, 0) != 0 &&
        ((ActorInfo_guess*)player->pActorInfo)->ceilingHeight_01b0_guess - playerGuess->field_2f8 <
            playerGuess->heightOffset_0238_guess * 3.0f) {
        playerGuess->Dismount_guess();
        token_string_to_client_guess(g_pcClientAffectView_guess != 0 ?
                               &g_pcClientAffectView_guess->affect_0c280_guess : 0,
                           0xfe3, 0xd, 0);
    } else {
        if (((EQPlayerRaceView_guess*)mount)->IsHorseRace_guess()) {
            ((EQPlayer_guess*)mount)->SetAvatarHeight_guess(player->AvatarHeight);
        } else {
            state = 3;
        }
        if (playerGuess->AttachPlayerToPlayerDag_guess(mount, state) != 0) {
            ((ActorInfo_guess*)player->pActorInfo)->mount_015c_guess = mount;
            ((ActorInfo_guess*)mount->pActorInfo)->rider_0160_guess = player;
            if (player->Levitate == 2) {
                ((EQPlayerStatusView_guess*)((ActorInfo_guess*)player->pActorInfo)->mount_015c_guess)->SetLevitate_guess(2);
            }
            if (player == (EQPlayer*)g_controlledPlayer_guess &&
                ((EQPlayerRaceView_guess*)mount)->IsHorseRace_guess()) {
                g_player905cf8_guess = (EQPlayer_guess*)mount;
                ((EQPlayer*)g_controlledPlayer_guess)->SpeedRun = 0.0f;
                ((EQPlayer*)g_controlledPlayer_guess)->field_58 = 0.0f;
                ((EQPlayer_guess*)mount)->motion_030.Copy_guess(
                    (PlayerMotion_guess*)&((EQPlayer*)g_controlledPlayer_guess)->Y);
                ((EQPlayer_guess*)mount)->FUN_0048a945_guess();
                player->eyeHeight_0234_guess = playerGuess->FUN_004899cc_guess() * 0.85f;
            }
            playerGuess->UpdatePlayerVisibility_guess();
            ((ActorInfo_guess*)player->pActorInfo)->currentAnimation_0134_guess = 0;
            if (((ActorInfo_guess*)player->pActorInfo)->field_158 != 0) {
                EQPlayer_guess* mountGuess = (EQPlayer_guess*)mount;
                PlayerVec3_guess* mountPosition = &mountGuess->motion_030.pos;
                PlayerVec3_guess* playerPosition = &playerGuess->motion_030.pos;
                mountPosition->y = playerPosition->y;
                mountPosition->x = playerPosition->x;
                mountPosition->z = playerPosition->z;
                ActorInfo_guess* playerActor = (ActorInfo_guess*)player->pActorInfo;
                ActorInfo_guess* mountActor = (ActorInfo_guess*)mount->pActorInfo;
                mountActor->floorHeight_0048_guess = playerActor->floorHeight_0048_guess;
                ((EQPlayer_guess*)mount)->FUN_0048a945_guess();
            }
            ((EQPlayer_guess*)mount)->FUN_0048a7f9_guess();
            playerGuess->FUN_0048a7f9_guess();
            return;
        }
        if (player != (EQPlayer*)g_controlledPlayer_guess) {
            return;
        }
        token_string_to_client_guess(g_pcClientAffectView_guess != 0 ?
                               &g_pcClientAffectView_guess->affect_0c280_guess : 0,
                           0x1594, 0xd, 0);
    }
    EQ_GLOBAL(PcClientAffectView_guess*, 0x00905D00)->affect_0c280_guess.RemovePCAffect_guess(
        EQ_GLOBAL(PcClientAffectView_guess*, 0x00905D00)->affect_0c280_guess.GetSpellAffect_guess(0x71, 0));
}

// For a playable-race look (+0x254 = -1) whose model data (ActorInfo +0x12C) has +0x34 set: re-applies
// hair style (+0x249) and beard (+0x24A), hair and beard colours, both eye colours, then the default
// attachments.
// FUNCTION: TITANIUM 0x00483B9B
void EQPlayer_guess::RefreshFacialFeatures_guess() {
    if (pActorInfo != 0 && pActorInfo->actorDef_012c_guess != 0 &&
        ((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess != 0 && equipChest2_0254_guess == -1) {
        SetFacialFeature_guess(eyes2, 2);
        SetFacialFeature_guess(beardType, 4);
        SetFeatureColor_guess(hairColor, 2);
        SetFeatureColor_guess(beardColor, 4);
        ((EQPlayerCore_guess*)this)->SetEyeColor_guess(1, eyes);
        ((EQPlayerCore_guess*)this)->SetEyeColor_guess(0, eyeColor1_0247_guess);
        SetDefaultITAttachments_guess(-1);
    }
}

#define g_state924794_guess EQ_GLOBAL(int, 0x00924794)
#define g_texOption11_guess EQ_GLOBAL(int, 0x009247CC)
#define g_texOption12_guess EQ_GLOBAL(int, 0x009247D0)
#define g_texOption13_guess EQ_GLOBAL(int, 0x009247D4)
#define g_texOption14_guess EQ_GLOBAL(int, 0x009247D8)
#define g_texOption15_guess EQ_GLOBAL(int, 0x009247DC)
#define g_texOption16_guess EQ_GLOBAL(int, 0x009247E0)
#define g_texOption17_guess EQ_GLOBAL(int, 0x009247E4)

// Body texture swap for wear slot `part` 1-6 from material `texB` to `texA`. Materials above the cap (16;
// 23 with expansion flag 2 or 0x924794; 53 for NPCs) fall back to 1-4, and 17-23 also fall back when
// their option (0x9247CC..) is off, always for Vah Shir and Froglok. Monks keep material 4 (class 7).
// FUNCTION: TITANIUM 0x00483C3C
char EQPlayer_guess::SwapMaterial_guess(int part, int texA, int texB, int color, unsigned char variant) {
    int cls;
    int maxTex = 0x10;
    char result = 1;
    char special = 0;
    EQPlayerCore_guess* self = (EQPlayerCore_guess*)this;
    if (self->handler->actorDef_012c_guess != 0 && self->handler->FUN_0048f019_guess() != 0) {
        return 0;
    }
    // Highest texture number this model may use: 53 for an NPC (type 1); for others 23 when flag 2
    // of the view's +0x108 or state 0x00924794 is set, else 16.
    if (type == 1) {
        maxTex = 0x35;
    } else if (g_pcView_guess != 0 && (g_pcView_guess->flags_108 & 2) != 0) {
        maxTex = 0x17;
    } else if (g_state924794_guess == 1) {
        maxTex = 0x17;
    }
    if (self->handler == 0 || self->handler->target == 0 || self->handler->actorDef_012c_guess == 0) {
        return 0;
    }
    cls = playerClass;
    // texA is the new texture, texB the one being replaced. Texture 7 becomes 2 (3 for an Iksar).
    if (texA == 7) {
        texA = 2;
        if (race == Race_Iksar) {
            texA = 3;
        }
    }
    if (texB == 7) {
        texB = 2;
        if (race == Race_Iksar) {
            texB = 3;
        }
    }
    // With +0x254 set (not -1) the model is refreshed through 0x00482722 instead and nothing is
    // swapped.
    if (equipChest2_0254_guess != -1) {
        SwapNPCMaterials_guess();
        return 0;
    }
    unsigned char rgb[4];
    rgb[2] = (unsigned char)(color >> 16);
    rgb[1] = (unsigned char)(color >> 8);
    rgb[0] = (unsigned char)color;
    char prefix[16];
    self->GetActorTag_guess(prefix);
    // Part 1-6 picks the texture name: CH chest, UA arms, FA wrists, HN hands, LG legs, FT feet;
    // part 0 and anything else return 0.
    char partName[16];
    switch (part) {
    case 0:
        return 0;
    case 1:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x006446F0));
        break;
    case 2:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x00648198));
        break;
    case 3:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x0064470C));
        break;
    case 4:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x0064819C));
        break;
    case 5:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x006481A0));
        break;
    case 6:
        FUN_0060e450_guess(partName, EQ_ARRAY(char, 0x006481A4));
        break;
    default:
        return 0;
    }
    // Optional textures 17-23 fall back to 1, 2 or 3 (23: 4 for a Monk, class 7, else 1) when their
    // option global is off, and always for a Froglok or Vah Shir. Texture 4 is Monk only.
    if (race == Race_Froglok || race == Race_VahShir) {
        special = 1;
    }
    switch (texA) {
    case 4:
        if (playerClass != 7) texA = 1;
        break;
    case 0x11:
        if (g_texOption11_guess == 0 || special) texA = 1;
        break;
    case 0x12:
        if (g_texOption12_guess == 0 || special) texA = 2;
        break;
    case 0x13:
        if (g_texOption13_guess == 0 || special) texA = 3;
        break;
    case 0x16:
        if (g_texOption16_guess == 0 || special) texA = 3;
        break;
    case 0x15:
        if (g_texOption15_guess == 0 || special) texA = 2;
        break;
    case 0x14:
        if (g_texOption14_guess == 0 || special) texA = 1;
        break;
    case 0x17:
        if (g_texOption17_guess == 0 || special) texA = cls == 7 ? 4 : 1;
        break;
    }
    switch (texB) {
    case 4:
        if (playerClass != 7) texB = 1;
        break;
    case 0x11:
        if (g_texOption11_guess == 0 || special) texB = 1;
        break;
    case 0x12:
        if (g_texOption12_guess == 0 || special) texB = 2;
        break;
    case 0x13:
        if (g_texOption13_guess == 0 || special) texB = 3;
        break;
    case 0x14:
        if (g_texOption14_guess == 0 || special) texB = 1;
        break;
    case 0x15:
        if (g_texOption15_guess == 0 || special) texB = 2;
        break;
    case 0x16:
        if (g_texOption16_guess == 0 || special) texB = 3;
        break;
    case 0x17:
        if (g_texOption17_guess == 0 || special) texB = cls == 7 ? 4 : 1;
        break;
    }
    // Above the model's limit the same fallbacks apply (for texB, 23 too becomes 0) and anything
    // else becomes 0; for texA, 23 is Monk only even within the limit.
    if (texA > maxTex) {
        switch (texA) {
        case 0x11:
        case 0x14:
            texA = 1;
            break;
        case 0x12:
        case 0x15:
            texA = 2;
            break;
        case 0x13:
        case 0x16:
            texA = 3;
            break;
        case 0x17:
            texA = cls == 7 ? 4 : 1;
            break;
        default:
            texA = 0;
            break;
        }
    } else if (texA == 0x17 && cls != 7) {
        texA = 1;
    }
    if (texB > maxTex) {
        switch (texB) {
        case 0x11:
        case 0x14:
            texB = 1;
            break;
        case 0x12:
        case 0x15:
            texB = 2;
            break;
        case 0x13:
        case 0x16:
            texB = 3;
            break;
        default:
            texB = 0;
            break;
        }
    }
    char nameA[64];
    char nameB[64];
    FUN_0060e450_guess(nameA, prefix);
    // Names are actor tag + part + texture (2 digits) + piece (2 digits) + "_MDF"; Froglok and Vah
    // Shir put a variant digit before the piece digit. nameA is the old texture, nameB the new;
    // bumping [8] steps to the next piece.
    strcat(nameA, partName);
    FUN_0060e450_guess(nameB, nameA);
    if (race == Race_VahShir || race == Race_Froglok) {
        sprintf(nameA + 5, "%02d%01d1_MDF", texB, faceHair);
        sprintf(nameB + 5, "%02d%01d1_MDF", texA, variant);
    } else {
        sprintf(nameA + 5, "%02d01_MDF", texB);
        sprintf(nameB + 5, "%02d01_MDF", texA);
    }
    int count;
    switch (part) {
    case 1:
        if (self->handler->actorDef_012c_guess->field_034_guess == 0 && race != Race_VahShir && race != Race_Froglok) {
            // Chest on the basic model (+0x34 of the model data clear, not Froglok / Vah Shir):
            // textures 10-16 are robes. Putting one on swaps the chest pieces to texture 00 and sets
            // the robe look (texA - 6).
            if (texA >= 10 && texA <= 16) {
                if (texB < 10 || texB > 16) {
                    nameB[5] = '0';
                    nameB[6] = '0';
                    self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                    nameA[8]++;
                    nameB[8]++;
                    self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                    if (self->handler->actorDef_012c_guess->field_034_guess != 0) {
                        nameA[8]++;
                        nameB[8]++;
                        self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                    } else {
                        self->FUN_0047bc8e_guess(0, 1);
                    }
                }
                if (self->handler->actorDef_012c_guess->field_034_guess == 0) {
                    self->handler->target->Slot061_guess(texA - 6, rgb);
                }
            } else {
                // Taking a robe off: the old names use texture 00 and the body is reset (0x0047BC52,
                // 0x0047BC8E).
                if (texB >= 10 && texB <= 16) {
                    nameA[5] = '0';
                    nameA[6] = '0';
                    self->FUN_0047bc52_guess();
                    self->FUN_0047bc8e_guess(1, 0);
                }
                self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                nameA[8]++;
                nameB[8]++;
                self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                if (self->handler->actorDef_012c_guess->field_034_guess != 0) {
                    nameA[8]++;
                    nameB[8]++;
                    self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
                }
            }
        } else {
            result = self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
            // Other models: three chest pieces; for Froglok ("FR") names the pieces after the first
            // use variant digit '0' ([7]).
            for (int i = 0; i < 2; i++) {
                if (strncmp(nameB, "FR", 2) == 0) {
                    nameA[7] = '0';
                    nameB[7] = '0';
                }
                nameA[8]++;
                nameB[8]++;
                self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
            }
        }
        break;
    case 2:
    case 3:
        result = self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        if (self->handler->actorDef_012c_guess->field_034_guess == 0 && race != Race_VahShir && race != Race_Froglok) {
            // Arms and wrists: one piece on the basic model, two on the others.
            count = 0;
        } else {
            count = 1;
        }
        for (int i = 0; i < count; i++) {
            nameA[8]++;
            nameB[8]++;
            self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        }
        break;
    case 4:
    case 6:
        result = self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        if (self->handler->actorDef_012c_guess->field_034_guess == 0 && race != Race_VahShir && race != Race_Froglok) {
            count = 1;
        } else {
            count = 4;
        }
        for (int i = 0; i < count; i++) {
            nameA[8]++;
            nameB[8]++;
            // Hands and feet: two pieces on the basic model, five on the others. Froglok feet after
            // the first piece are drawn white (untinted).
            if (part == 6 && race == Race_Froglok) {
                rgb[2] = 0xff;
                rgb[0] = 0xff;
                rgb[1] = 0xff;
            }
            self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        }
        break;
    case 5:
        result = self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        if (race == Race_VahShir) {
            char altA[64];
            char altB[64];
            FUN_0060e450_guess(altA, nameA);
            // Vah Shir legs also swap the tail (part "TA"), using tail texture 00 when that texture
            // is missing.
            strncpy(altA + 3, "TA", 2);
            FUN_0060e450_guess(altB, nameB);
            strncpy(altB + 3, "TA", 2);
            if (self->handler->target->Slot044_guess(altA, altB, rgb, 0) == 0) {
                strncpy(altA + 3, "TA00", 4);
                strncpy(altB + 3, "TA00", 4);
                self->handler->target->Slot044_guess(altA, altB, rgb, 0);
            }
        }
        if (self->handler->actorDef_012c_guess->field_034_guess == 0 && race != Race_VahShir && race != Race_Froglok) {
            // Legs: three pieces on the basic model, five on the others.
            count = 2;
        } else {
            count = 4;
        }
        for (int i = 0; i < count; i++) {
            if (strncmp(nameB, "FR", 2) == 0) {
                nameA[7] = '0';
                nameB[7] = '0';
            }
            nameA[8]++;
            nameB[8]++;
            self->handler->target->Slot044_guess(nameA, nameB, rgb, 0);
        }
        break;
    }
    // When result is set (the first piece swapped, or always on the basic-model chest path above):
    // remember the part's new texture and tint.
    if (result) {
        ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(part, texA);
        ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(part, color);
    }
    return result;
}

// Wear-slot material change: slot 0 is the helm, `value` 200+ an IT model, else a texture with
// fallbacks; a robe (10-16) on the chest repaints arms and wrists. Sends OP_WearChange unless `one`.
// FUNCTION: TITANIUM 0x004845D8
// @early-stop: budget, structural ndiff=99
void EQPlayer_guess::HandleMaterialEx_guess(int index, unsigned int value, unsigned int zero,
                                        int field, int one) {
    struct ChangeMessage_guess {
        unsigned short spawnId;
        unsigned short value;
        int field;
        unsigned char index;
    };

    char found = 0;
    char itemName[32];
    unsigned int savedZero;
    ChangeMessage_guess message;

    if (pActorInfo == 0) {
        return;
    }
    if (equipChest2_0254_guess != -1) {
        return;
    }
    if (pActorInfo->actorDef_012c_guess != 0 &&
        (char)pActorInfo->FUN_0048f019_guess() != 0) {
        return;
    }

    if (index == 0) {
        SwapHead_guess((int)value, (int)zero, field, one);
        if (value >= 200) {
            value = (unsigned int)pActorInfo->actorDef_012c_guess;
        }
    } else if (value >= 200) {
        if (pActorInfo->actorDef_012c_guess != 0 &&
            ((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess != 0) {
            sprintf(itemName, "IT%d", (int)value);
            UpdateItemSlot_guess(index, itemName, 1);
        }
        found = SwapMaterial_guess(index, 3, (int)zero, field, faceHair);
        if (found == 0) {
            zero = faceHair;
            found = SwapMaterial_guess(index, 3, 0, field, faceHair);
        }
    } else {
        if (pActorInfo->actorDef_012c_guess != 0 &&
            ((ChildState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess != 0) {
            if ((index == 2 || index == 3 || (index == 5 && race == Race_Froglok))) {
                int adjustedValue = materials_01e0_guess[1];
                if (adjustedValue >= 10 && adjustedValue <= 16) {
                    field = colors_01bc_guess[1];
                    value = (unsigned int)adjustedValue;
                }
            }
            found = SwapMaterial_guess(index, (int)value, (int)zero, field, faceHair);
            if (found == 0) {
                savedZero = zero;
                zero = 0;
                found = SwapMaterial_guess(index, (int)value, 0, field, faceHair);
                if (found == 0 && (race == Race_VahShir || race == Race_Froglok)) {
                    unsigned char savedFaceHair = faceHair;
                    faceHair = 0;
                    found = SwapMaterial_guess(index, (int)value, 0, field,
                                               savedFaceHair);
                    if (found == 0) {
                        found = SwapMaterial_guess(index, (int)value, (int)savedZero,
                                                   field, savedFaceHair);
                        if (found != 0) {
                            zero = savedZero;
                        }
                    }
                    faceHair = savedFaceHair;
                }
            }
            if (index == 1 &&
                ((value >= 10 && value <= 16) || (zero >= 10 && zero <= 16))) {
                SwapMaterial_guess(2, (int)value, materials_01e0_guess[2], field, faceHair);
                SwapMaterial_guess(3, (int)value, materials_01e0_guess[3], field, faceHair);
                if (race == Race_Froglok) {
                    SwapMaterial_guess(5, (int)value, materials_01e0_guess[5], field, faceHair);
                }
                SetDefaultITAttachments_guess(-1);
            }
            SetDefaultITAttachments_guess(index);
        } else {
            SwapMaterial_guess(index, (int)value, (int)zero, field, faceHair);
        }
    }

    if (found != 0 && one == 0) {
        message.spawnId = (unsigned short)spawnId;
        message.value = (unsigned short)value;
        message.field = field;
        message.index = (unsigned char)index;
        FUN_004912b1_guess(EQ_ARRAY(char, 0x00905CA0), OP_WearChange,
                           (const int*)&message, 9, 1);
    }

    if (pinstCBodyTintWnd_guess != 0 &&
        pinstCBodyTintWnd_guess->IsVisible_guess() != 0) {
        pinstCBodyTintWnd_guess->UpdateBrush_guess(1);
    }
}

// Playable races: +0x254 = -1 and the head (part 0) gets `b_guess`, parts 1-6 `a_guess`. Other races: `a`
// and `b` (each 0-30) become the texture set (+0x254) and helm (+0x255), applied by 0x00482722. Then
// refreshes the model's sounds.
// FUNCTION: TITANIUM 0x0048492C
void EQPlayer_guess::ChangeTextures_guess(int a_guess, int b_guess) {
    if (((EQPlayerCore_guess*)this)->LegalPlayerRace_guess(-1) != 0) {
        /* fake match: a pointer to the array lets the store come before its load, as in the original; reading
           field_1e0_guess[0] directly loads it first */
        int* values_guess = materials_01e0_guess;
        equipChest2_0254_guess = -1;
        HandleMaterialEx_guess(0, b_guess, values_guess[0], 0, 1);
        for (int i = 1; i <= 6; i++) {
            int value = ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(i);
            HandleMaterialEx_guess(i, a_guess, value, 0, 1);
        }
    } else {
        if (a_guess >= 0 && a_guess <= 30) {
            if (b_guess >= 0 && b_guess <= 30) {
                equipChest2_0254_guess = (char)a_guess;
                helm_0255_guess = (char)b_guess;
                SwapNPCMaterials_guess();
            }
        }
    }
    SetSounds_guess();
}

// Unlinks from the player list and name hash, clears every reference others hold (mounts, target 0x905D04,
// slots 0x904390, watchers) and frees the actor. The last spawn also frees the item list 0x903E30.
// FUNCTION: TITANIUM 0x004849B2
EQPlayer_guess::~EQPlayer_guess() {
    SetNameSpriteState(0);
    EnterCriticalSection(g_playerLock_guess);
    if (pPrev != 0 && pNext != 0) {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    } else if (pPrev == 0 && pNext != 0) {
        pNext->pPrev = 0;
        g_playerList_guess = pNext;
    } else if (pNext == 0 && pPrev != 0) {
        pPrev->pNext = 0;
    } else {
        pNext = 0;
        pPrev = 0;
        g_playerList_guess = 0;
        if (g_itemList_guess != 0) {
            delete g_itemList_guess;
            g_itemList_guess = 0;
            g_itemRegistry_guess = 0;
        }
    }
    unsigned int hash = FUN_00574890_guess(name_120);
    EQPlayer_guess* self = this;
    g_playerHash_guess->Remove_guess(&self, hash);
    if (isABoat_01b6_guess != 0 || (pActorInfo != 0 && (pActorInfo->rider_0160_guess != 0 || pActorInfo->mount_015c_guess != 0))) {
        ClearMountLinks_guess();
    }
    for (EQPlayer_guess* player = g_playerList_guess; player != 0; player = player->pNext) {
        if (player != this && player->pActorInfo != 0 && player->pActorInfo->rider_0160_guess == this) {
            player->pActorInfo->rider_0160_guess = 0;
        }
    }
    EQPlayer_guess* controlled = g_controlledPlayer_guess;
    if (controlled != 0 && controlled->pActorInfo != 0 && spawnId == controlled->pActorInfo->field_16c) {
        controlled->pActorInfo->field_16c = -1;
        if (pinstCPetInfoWnd_guess != 0) {
            pinstCPetInfoWnd_guess->Refresh_guess();
        }
    }
    if (pinstCFindLocationWnd_guess != 0 && (canFindLocation_01b0_guess & 1)) {
        pinstCFindLocationWnd_guess->RemoveByValue_guess(spawnId);
    }
    ((EQPlayerCore_guess*)this)->RemoveFromEffectList_guess();
    DeleteOwnedEffects_guess((int)this);
    if (pCharInfo != 0) {
        GetPc_guess()->player_008 = 0;
    }
    if (g_player905d04_guess == this) {
        g_player905d04_guess = 0;
    }
    if (g_player923cd4_guess == this) {
        g_value923cc4_guess = -1;
        g_player923cd4_guess = 0;
    }
    if (this == g_player905cf8_guess) {
        if (this == g_controlledPlayer_guess) {
            g_player905cf8_guess = 0;
            g_controlledPlayer_guess = 0;
        } else {
            if (g_pcClient_guess != 0) {
                g_pcClient_guess->RemovePCAffect_guess(g_pcClient_guess->GetSpellAffect_guess(0x43, 0));
            }
            g_player905cf8_guess = g_controlledPlayer_guess;
        }
    }
    if (type == 0) {
        for (int i = 0; i < 5; ++i) {
            if (g_playerSlots_guess[i] == this) {
                g_playerSlots_guess[i] = 0;
            }
        }
    }
    if (pinstCTrackingWnd_guess != 0) {
        pinstCTrackingWnd_guess->RemoveSpawn_guess(this);
    }
    if (pinstCInspectWnd_guess != 0) {
        pinstCInspectWnd_guess->PlayerBeingDeleted_guess(this);
    }
    ClearOthersReferenceToMe_guess();
    if (pActorInfo != 0) {
        if (type >= 2 && !((EQPlayerRaceView_guess*)this)->IsHorseRace_guess()) {
            pActorInfo->field_19c = 1;
        }
        delete pActorInfo;
        pActorInfo = 0;
    }
    g_display2_guess->field_150 = 0;
    delete animation_0208_guess;
    LeaveCriticalSection(g_playerLock_guess);
    if (spawnId > 0 && spawnId < 3000) {
        g_spawnTable_guess[spawnId] = 0;
    }
}
#define g_gameFlag_guess EQ_GLOBAL(int, 0x00923884)
#define g_floorValue_guess EQ_GLOBAL(float, 0x00923D20)
#define g_charInfoValue_guess EQ_GLOBAL(int, 0x009244FC)
#define g_charInfoDirty_guess EQ_GLOBAL(unsigned char, 0x0092462C)

// Re-applies the worn look: with +0x254 at -1 the 7 armor parts and the face, otherwise the head and the
// face; then the primary and secondary item models ("IT<n>" from +0x1FC/+0x200) at attach points 7 and 8
// (0x0048083A).
// FUNCTION: TITANIUM 0x00484CA3
void EQPlayer_guess::DisplayWeaponsAndArmor_guess() {
    char text[8];
    if (equipChest2_0254_guess == -1) {
        for (int index = 0; index <= 6; ++index) {
            HandleMaterialEx_guess(index,
                              ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(index),
                              0, colors_01bc_guess[index], 1);
        }
        SwapFace_guess(faceHair, 0);
    } else {
        SwapHead_guess(materials_01e0_guess[0], 0, colors_01bc_guess[0], 1);
        SwapNPCMaterials_guess();
        if (faceHair > 0) {
            SwapFace_guess(faceHair, 0);
        }
    }
    if (primaryModelId_01fc_guess != 0) {
        sprintf(text, "IT%u", primaryModelId_01fc_guess);
        UpdateItemSlot_guess(7, text, 1);
    }
    if (secondaryModelId_0200_guess != 0) {
        sprintf(text, "IT%u", secondaryModelId_0200_guess);
        UpdateItemSlot_guess(8, text, 1);
    }
}

// Wakes the player from knocked out (PC state +0xFC 3+, string 0x324C), then stands up from kneeling.
// FUNCTION: TITANIUM 0x00484D8D
void EQPlayer_guess::GetConscious_guess() {
    if (this == g_controlledPlayer_guess) {
        PcClient_guess* pc = GetPc_guess();
        if (pc == 0) {
            return;
        }
        if (pc->field_0fc_guess < 3) {
            return;
        }
        pc->field_0fc_guess = 0;
        g_clientRoot_guess->RestoreCameraMode_guess();
        pEverQuest->dsp_chat(pStringTable->getString(0x324c, 0), 0xd, 1);
    }
    standState = 0x69;
    ChangePosition_guess(100);
}

// Lies down ('s'); the player's PC state becomes 3 (string 0x324D).
// FUNCTION: TITANIUM 0x00484DF5
void EQPlayer_guess::KnockedOut_guess() {
    if (g_ownerState_guess == 0 && g_gameFlag_guess == 0 &&
        (ChangePosition_guess(0x73), this == g_controlledPlayer_guess)) {
        PcClient_guess* pc = (PcClient_guess*)((EQPlayerPcView_guess*)this)->FUN_0047c31a_guess();
        if (pc == 0) {
            return;
        }
        if (pc->field_0fc_guess > 0) {
            return;
        }
        pc->field_0fc_guess = 3;
        g_clientRoot_guess->SetCameraMode_guess(1);
        pEverQuest->dsp_chat(pStringTable->getString(0x324d, 0), 0xf, 1);
    }
    motion_030.field_28 = 0.0f;
    motion_030.field_24 = 0.0f;
    motion_030.speedRun = 0.0f;
}

// Turns the spawn into a corpse: lying, renamed ("<name>'s corpse<n>" for PCs), Type 2, stand state 'x'.
// FUNCTION: TITANIUM 0x00484E79
// @early-stop: budget, diff ndiff=10
void EQPlayer_guess::IDied_guess(PlayerDeathInfo_guess* message) {
    if (type < 2) {
        if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)) {
            FUN_00574110_guess("I died.\n");
            EQPlayer_guess* killer = (EQPlayer_guess*)FUN_00401b28_guess(message->value_004_guess);
            if (killer == 0) {
                EQ_GLOBAL(unsigned int, 0x0078D850) = 1;
            } else {
                EQ_GLOBAL(unsigned int, 0x0078D850) = killer->type;
            }
            pActorInfo->deathTime_0068_guess = 0;
        } else {
            pActorInfo->deathTime_0068_guess = GetTimeMs_guess();
        }
        KnockedOut_guess();
        char corpse[64];
        if (type == 0) {
            FUN_0060e450_guess(corpse, name_120);
            sprintf(corpse, "%s's corpse%u", name_120, message->corpseNumber_0008_guess);
            SetName_guess(corpse);
        } else {
            FUN_0060e450_guess(corpse, name_120);
            MakeNPCCorpseName_guess(playerClass, corpse, message->corpseNumber_0008_guess);
            SetName_guess(corpse);
        }
        type = 2;
        hideMode = 0;
        UpdatePlayerVisibility_guess();
        standState = 0x78;
        ((EQPlayerCore_guess*)this)->SetCurrentLoopSound_guess(0);
        if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)) {
            g_resourceUser_guess->SetMusicSelection_guess(8, 1);
            if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4) &&
                pinstCContainerMgr_guess != 0) {
                pinstCContainerMgr_guess->Flush_guess();
            }
        }
        motion_030.field_28 = 0.0f;
        motion_030.field_24 = 0.0f;
        motion_030.speedRun = 0.0f;
        motion_030.speed.y = 0.0f;
        motion_030.speed.x = 0.0f;
        motion_030.speed.z = 0.0f;
        levitate = 0;
        pActorInfo->field_09c = 1;
        if (this == EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)) {
            pActorInfo->field_1004_guess = 1;
        }
    }
}

// An NPC horse named "<rider>`s_Mount" mounts its rider.
// FUNCTION: TITANIUM 0x0048500B
void EQPlayer_guess::MakeRiderMountUp_guess() {
    if (type == 1 && FUN_0047cf40_guess() != 0 &&
        pActorInfo != 0 && pActorInfo->rider_0160_guess == 0 && pActorInfo->actorInstance_0000_guess != 0) {
        int length = strlen(name_120);
        if (length >= 9 && FUN_0060e590_guess(name_120, "`s_Mount") != 0) {
            char name[64];
            steve_strncpy_guess(name, name_120, length - 9);
            EQPlayer_guess* mount = (EQPlayer_guess*)GetSpawnByName_guess(name);
            if (mount != 0) {
                mount->MountEQPlayer_guess(this);
            }
        }
    }
}

// Spawn from a Spawn_Struct (`source`) or bare (`name`). Joins the player list and name hash, binds
// pCharInfo when the name is the character's, builds the actor <tag>_ACTORDEF, places it on the floor
// and dresses it.
// FUNCTION: TITANIUM 0x004850A0
EQPlayer_guess::EQPlayer_guess(SpawnStruct_guess* source, unsigned char gender, int race,
                               unsigned char playerClass, const char* name)
    : table_328(0x20) {
    int kind = 1;
    char actorDef[0x20];
    InitTables_guess();
    if (g_playerList_guess == 0) {
        ((TableOwner_guess*)this)->ClearTable_guess();
    }
    if (source != 0) {
        if (strlen(source->name_007) < 0x40) {
            SetName_guess(source->name_007);
        } else {
            SetName_guess("NameTooLong");
        }
    } else if (name != 0) {
        SetName_guess(name);
    }
    field_024 = 1.0f;
    pCharInfo = 0;
    masterId = 0;
    field_028 = 1.0f;
    gm = 0;
    isPet_01b5_guess = 0;
    deity = 0;
    field_02c = 1.0f;
    holding = 0;
    hairColor = 0xff;
    beardColor = 0xff;
    eyeColor1_0247_guess = 0xff;
    eyes = 0xff;
    eyes2 = 0xff;
    beardType = 0xff;
    animation_0208_guess = 0;
    if (g_itemList_guess == 0) {
        g_itemList_guess = new EQ_Item_guess;
        g_itemRegistry_guess = new ItemRegistry_guess;
    }
    stepHeight_022c_guess = 0.0f;
    helm_0255_guess = -1;
    equipChest2_0254_guess = -1;
    eyeHeight_0234_guess = 5.5f;
    field_228 = 3.0f;
    if (FUN_0047937c_guess(race)) {
        runSpeed_0230_guess = 0.7f;
        walkSpeed = 0.325f;
    } else {
        runSpeed_0230_guess = 0.7f;
        walkSpeed = 0.46f;
    }
    boundingRadius_01a0_guess = 0.0f;
    EnterCriticalSection(g_playerLock_guess);
    if (g_playerList_guess == 0) {
        g_playerList_guess = this;
        pNext = 0;
        pPrev = 0;
    } else {
        g_playerList_guess->pPrev = this;
        pNext = g_playerList_guess;
        pPrev = 0;
        g_playerList_guess = this;
    }
    avatarHeight = -1.0f;
    if (g_pcClient_guess != 0 && _stricmp(name_120, g_pcClient_guess->name_03c) == 0) {
        pCharInfo = g_pcClient_guess;
        if (pCharInfo != 0) {
            GetPc_guess()->player_008 = this;
            zone_204 = g_pcClient_guess->zone_100;
        }
    }
    if (source == 0) {
        if (g_ownerState_guess == 0 && g_gameFlag_guess == 0) {
            spawnId = 0;
        } else if (race != 0x8cd) {
            spawnId = NextSpawnId_guess();
            if (race == 0xd8) {
                walkSpeed = 0.7f;
                runSpeed_0230_guess = 1.4f;
            }
        }
        guildId = -1;
        levitate = 0;
        bodyType = 1;
        motion_030.pos.Set_guess(0.0f, 0.0f, 9.0f);
        motion_030.heading = 0.0f;
        linkdead_01b2_guess = 0;
        motion_030.field_20 = 0.0f;
        motion_030.speedRun = 0.0f;
        motion_030.SetSpeed_guess(0.0f, 0.0f, 0.0f);
        this->gender = gender;
        motion_030.field_28 = 0.0f;
        motion_030.field_24 = 0.0f;
        motion_030.field_2c = 0.0f;
        ((EQPlayerRaceView_guess*)this)->SetRace_guess(race);
        this->playerClass = playerClass;
        hideMode = 0;
        field_1b1 = 0;
        hpMax = 50;
        hpCurrent = 50;
        standState = 100;
        light = 0;
        pvpFlag = 0;
        faceHair = 0;
        for (int i = 0; i < 9; ++i) {
            ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(i, 0);
            ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(i, 0);
        }
        SetAFK_guess(0);
        type = 0;
        anon = 0;
    } else {
        kind = CopyFrom_guess(source);
    }
    stepHeight_022c_guess = 0.0f;
    field_1ac = 0;
    field_21c = 0;
    field_268 = 0;
    field_000 = 3;
    ((EQPlayerCore_guess*)this)->GetActorTag_guess(actorDef);
    strcat(actorDef, "_ACTORDEF");
    pActorInfo = new ActorInfo_guess(actorDef);
    if (pActorInfo->dispatch_1b4 != 0) {
        pActorInfo->dispatch_1b4->SetHeight_guess(avatarHeight);
    }
    if (kind == 2) {
        pActorInfo->field_1030 = 6;
    }
    SetHeights_guess();
    pActorInfo->deathTime_0068_guess = 0;
    g_display2_guess->AddPlayer_guess(this);
    pActorInfo->floorHeight_0048_guess = FloorAt_guess(motion_030.pos.y, motion_030.pos.x, motion_030.pos.z);
    pActorInfo->ceilingHeight_01b0_guess = FloorBelow_guess(motion_030.pos.y, motion_030.pos.x, motion_030.pos.z);
    if (pActorInfo->floorHeight_0048_guess == -1.0e27f) {
        pActorInfo->floorHeight_0048_guess = 1.0f;
    }
    ((EQPlayerStatusView_guess*)this)->SetLevitate_guess(levitate);
    if (pCharInfo != 0 && type == 0) {
        SetPcLight_guess(this, light);
        gm = GetPc_guess()->field_e25 != 0;
    }
    UpdateLight_guess();
    if (field_1b3 == 0 && !((EQPlayerRaceView_guess*)this)->IsHorseRace_guess() && this->race != 0x6c && type == 1 &&
        masterId != 0) {
        EQPlayer_guess* master = (EQPlayer_guess*)FUN_00401b28_guess(masterId);
        if (master != 0 && master->pActorInfo != 0) {
            master->pActorInfo->field_16c = spawnId;
        }
    }
    // Races 475 and up get no armor and no sounds.
    if (this->race < 0x1db) {
        DisplayWeaponsAndArmor_guess();
        SetSounds_guess();
    }
    g_display2_guess->field_150 = 0;
    LeaveCriticalSection(g_playerLock_guess);
    if (type == 1) {
        if (g_statusCode_guess == 0x47 && !((EQPlayerRaceView_guess*)this)->IsHorseRace_guess()) {
            levitate = 1;
            pActorInfo->field_09c = 0;
        }
        MakeRiderMountUp_guess();
    }
    ((TableOwner_guess*)this)->SetSpawnId_guess(spawnId);
    if (field_1b3 == 0 && !((EQPlayerRaceView_guess*)this)->IsHorseRace_guess() && this->race != 0x6c) {
        EQPlayer_guess* controlled = g_controlledPlayer_guess;
        if (controlled != 0 && controlled->spawnId != 0 && masterId == controlled->spawnId &&
            controlled->pActorInfo != 0) {
            controlled->pActorInfo->field_16c = spawnId;
            if (pinstCPetInfoWnd_guess != 0) {
                pinstCPetInfoWnd_guess->Refresh_guess();
            }
        }
    }
    if (pinstCFindLocationWnd_guess != 0 && (canFindLocation_01b0_guess & 1)) {
        pinstCFindLocationWnd_guess->AddSpawn_guess(this);
    }
    if (pActorInfo != 0) {
        if (this->race == 0x8d) {
            levitate = 2;
            pActorInfo->field_09c = 0;
            pActorInfo->field_084 = 1;
            pActorInfo->field_08c = 3;
            pActorInfo->field_098 = 0.005f;
        } else if (isABoat_01b6_guess != 0) {
            pActorInfo->field_09c = 0;
        }
        if (pCharInfo != 0) {
            FUN_0046d655_guess();
            for (int i = 0; i < 10; ++i) {
                pActorInfo->slots_0e8[i] = GetPc_guess()->GetSlot_guess(i);
            }
            g_charInfoValue_guess = GetPc_guess()->GetProfile_guess()->field_1214;
            GetPc_guess()->GetCharInfo2();
            g_charInfoDirty_guess = 0;
        }
    }
    motion_030.field_2c = 0.0f;
    if (pCharInfo != 0 && type == 0) {
        motion_030.field_2c = g_floorValue_guess;
        GetPc_guess()->ReapplyBuffEffects_guess(1);
    }
    FUN_0048c11b_guess();
}

struct ActorState_guess {
    char pad_000_guess[0x34];
    unsigned char field_034_guess;
};

struct ActorRegistry_guess {
    virtual void Slot000_guess();
    virtual void Slot001_guess();
    virtual void Slot002_guess();
    virtual void Slot003_guess();
    virtual void Slot004_guess();
    virtual void Slot005_guess();
    virtual void Slot006_guess();
    virtual void Slot007_guess();
    virtual void Notify_guess(void* oldActor, void* newActor);
};

struct AppearanceSaved_guess {
    int faceHair_guess;
    ActorObject_guess* actor_guess;
    int typeOrMount_guess;
};

#define g_actorRegistry_guess EQ_GLOBAL(ActorRegistry_guess*, 0x0099E36C)
#define g_player905ce4_guess EQ_GLOBAL(EQPlayer_guess*, 0x00905CE4)

// The spawn with the shortest name whose display name starts with `text`'s, skipping `ignored`.
// FUNCTION: TITANIUM 0x0047981D
// @early-stop: budget, structural ndiff=7
EQPlayer_guess* __cdecl FindPlayerByPartialDisplayName_guess(char* text, EQPlayer_guess* ignored) {
    int length = (int)strlen(g_nameEq_guess->GetDisplayName_guess(text));
    unsigned int shortest = 0;
    EQPlayer_guess* result = 0;
    if (length > 0) {
        EQPlayer_guess* node = g_playerList_guess;
        while (node != 0) {
            if (_strnicmp(g_nameEq_guess->GetDisplayName_guess(node->name_120),
                    g_nameEq_guess->GetDisplayName_guess(text), length) == 0 &&
                (result == 0 || strlen(node->name_120) < shortest) &&
                node != ignored) {
                result = node;
                shortest = (unsigned int)strlen(node->name_120);
            }
            node = node->pNext;
        }
    }
    return result;
}

// Illusion: new race, gender, textures, face and features, then a rebuilt actor and re-mount. Races 142
// and 143 need a model at the spot (GetModelAtSpawnSpot_guess); without one the old look is restored, effects
// 58 and 156 (illusion) are dropped and string 0x55B is printed.
// FUNCTION: TITANIUM 0x00485873
// @early-stop: budget, structural ndiff=210
void EQPlayer_guess::ApplyIllusion_guess(const AppearanceUpdate_guess* update) {
    AppearanceSaved_guess saved;
    int oldAnimation;
    unsigned char oldClass;
    char raceName[0x20];
    char mountName[0x40];
    char actorName[0x20];
    int oldState;
    saved.actor_guess = 0;
    oldState = equipChest2_0254_guess;
    saved.faceHair_guess = faceHair;
    saved.typeOrMount_guess = race;
    char oldGender = gender;
    oldAnimation = materials_01e0_guess[0];
    oldClass = playerClass;

    if (pActorInfo == 0 || pActorInfo->actorInstance_0000_guess == 0) {
        return;
    }

    if (race == Race_VahShir &&
        (pActorInfo->actorDef_012c_guess == 0 ||
         ((ActorState_guess*)pActorInfo->actorDef_012c_guess)->field_034_guess == 0)) {
        if (oldGender == 0) {
            if (oldAnimation >= 0x29a && oldAnimation <= 0x29c) {
                materials_01e0_guess[0] = oldAnimation - 0x299;
            }
        } else if (oldAnimation >= 0x295 && oldAnimation <= 0x297) {
            materials_01e0_guess[0] = oldAnimation - 0x294;
        }
    }

    if (update->gender_048_guess != -1) {
        gender = update->gender_048_guess;
    }
    if (update->type_044_guess != -1) {
        ((EQPlayerRaceView_guess*)this)->SetRace_guess(update->type_044_guess);
    }
    if (((EQPlayerCore_guess*)this)->LegalPlayerRace_guess(-1) == 0) {
        equipChest2_0254_guess = update->state_049_guess;
    } else {
        equipChest2_0254_guess = -1;
    }
    if (update->field_04a_guess != -1) {
        helm_0255_guess = update->field_04a_guess;
    }
    if (update->faceHair_04c_guess != -1) {
        faceHair = (unsigned char)update->faceHair_04c_guess;
    }

    if (update->type_044_guess != 0x8f && update->type_044_guess != 0x8e) {
        ((EQPlayerCore_guess*)this)->GetActorTag_guess(actorName);
        strcat(actorName, "_ACTORDEF");
        eyes2 = update->eyes_050_guess;
        hairColor = update->hairColor_051_guess;
        beardType = update->beardType_052_guess;
        beardColor = update->beardColor_053_guess;
        if (update->hasValues_0a4_guess > 0) {
            helm_0255_guess = update->field_04a_guess;
            if (type == 1) {
                if (update->class_0a0_guess >= 0) {
                    playerClass = (unsigned char)update->class_0a0_guess;
                }
                for (int index = 0; index < 9; ++index) {
                    ((EQPlayerArmorView_guess*)this)->SetArmorType_guess(index,
                                                                   update->values_058_guess[index]);
                    ((EQPlayerArmorView_guess*)this)->SetArmorTint_guess(index,
                                                                   update->values_07c_guess[index]);
                }
            }
        }
    } else {
        if (GetModelAtSpawnSpot_guess(raceName, (update->type_044_guess == 0x8f) + 7) != 1) {
            ((EQPlayerRaceView_guess*)this)->SetRace_guess(saved.typeOrMount_guess);
            equipChest2_0254_guess = oldState;
            materials_01e0_guess[0] = oldAnimation;
            faceHair = (unsigned char)saved.faceHair_guess;
            gender = oldGender;
            if (this != g_player905ce4_guess) {
                return;
            }
            int textId = -1;
            int effect = g_pcClient_guess->GetSpellAffectText_guess(0x3a, &textId);
            g_pcClient_guess->RemovePCAffect_guess(effect);
            if (textId == -1) {
                effect = g_pcClient_guess->GetSpellAffectText_guess(0x9c, &textId);
                g_pcClient_guess->RemovePCAffect_guess(effect);
            }
            if (textId != -1) {
                g_pcClient_guess->NotifyPCAffectChange_guess(textId, 1);
            }
            pEverQuest->dsp_chat(pStringTable->getString(0x55b, 0), 0x108, 1);
            return;
        }
        steve_strncpy_guess(actorName, raceName, 0x1e);
    }

    saved.typeOrMount_guess = (int)pActorInfo->mount_015c_guess;
    if (saved.typeOrMount_guess != 0) {
        Dismount_guess();
    } else {
        sprintf(mountName, "%s`s_Mount", name_120);
        EQPlayer_guess* mount = FindPlayerByPartialDisplayName_guess(mountName, 0);
        saved.typeOrMount_guess = (int)mount;
        if (mount != 0 && mount->pActorInfo != 0 && mount->pActorInfo->rider_0160_guess == this) {
            mount->pActorInfo->rider_0160_guess = 0;
        }
    }

    if (pActorInfo->actorInstance_0000_guess != 0) {
        saved.actor_guess = (ActorObject_guess*)pActorInfo->actorInstance_0000_guess;
        pActorInfo->actorInstance_0000_guess = 0;
    }
    FUN_0060e450_guess(pActorInfo->actorName_008_guess, actorName);
    pActorInfo->field_138_guess = 0x20;
    pActorInfo->currentAnimation_0134_guess = 0xfe;
    pActorInfo->field_140_guess = 0x20;
    pActorInfo->field_13c_guess = 0xfe;
    pActorInfo->field_148_guess = 0;
    pActorInfo->field_144_guess = 0;
    pActorInfo->actorDef_012c_guess = 0;

    if (update->height_054_guess != 0.0f) {
        if (update->height_054_guess == -1.0f) {
            avatarHeight = -1.0f;
        } else {
            avatarHeight = update->height_054_guess;
        }
    }
    SetHeights_guess();
    SetSounds_guess();
    pActorInfo->floorHeight_0048_guess = g_display2_guess->GetFloorHeight_guess(
        motion_030.pos.y, motion_030.pos.x, motion_030.pos.z);
    if (pActorInfo->floorHeight_0048_guess == -1.0e27f) {
        pActorInfo->floorHeight_0048_guess = 1.0f;
    }
    pActorInfo->deathTime_0068_guess = 0;
    g_display2_guess->AddPlayer_guess(this);

    if (((EQPlayerCore_guess*)this)->LegalPlayerRace_guess(-1) != 0) {
        equipChest2_0254_guess = -1;
        if (update->state_049_guess == -1) {
            for (int index = 0; index < 7; ++index) {
                int field = ((EQPlayerPcView_guess*)this)->GetArmorTint_guess(index);
                int value = ((EQPlayerArmorView_guess*)this)->GetArmorType_guess(index);
                HandleMaterialEx_guess(index, value, 0, field, 1);
            }
        } else {
            for (int index = 0; index < 7; ++index) {
                HandleMaterialEx_guess(index, (int)update->state_049_guess, 0, 0, 1);
            }
        }
    }
    DisplayWeaponsAndArmor_guess();
    FUN_0048a945_guess();
    pActorInfo->deathTime_0068_guess = 0;
    if (this == g_player905ce4_guess) {
        g_display2_guess->SetViewActorByName_guess(name_120);
        if (g_pcClient_guess != 0) {
            g_pcClient_guess->ReapplyBuffEffects_guess(0);
        }
    }
    if (saved.typeOrMount_guess != 0) {
        ((EQPlayer_guess*)saved.typeOrMount_guess)->MakeRiderMountUp_guess();
    }
    ((AnimPlayer_guess*)g_player905ce4_guess->GetAnimation_guess())->Play_guess(0x47, 0, 0, 1.0f, 1);
    if (g_display2_guess->FUN_00437464_guess() != 0) {
        g_actorRegistry_guess->Notify_guess(saved.actor_guess, (void*)pActorInfo->actorInstance_0000_guess);
    }
    if (saved.actor_guess != 0) {
        g_display2_guess->DeleteActor_guess(saved.actor_guess);
    }
    playerClass = oldClass;
}

// Group record at 0x00904248: true when `value` is the leader's name (+0x15C) or one of the five member
// names (64 bytes each from +5).
// FUNCTION: TITANIUM 0x00485DF1
bool StringMatcher_guess::MatchesAnyName_guess(const char* value) {
    bool result = false;
    if (FUN_00574950_guess(primary_15c_guess, value) == 0) {
        result = true;
    } else {
        int index = 0;
        char* entry = &entries_005_guess[0][0];
        do {
            if (*entry != 0 && FUN_00574950_guess(entry, value) == 0) {
                result = true;
                break;
            }
            ++index;
            entry += 0x40;
        } while (index < 5);
    }
    return result;
}

// Animation helper for spawn `value`: no override and the other fields zeroed.
// FUNCTION: TITANIUM 0x00485E40
PlayerAnimation_guess::PlayerAnimation_guess(int value) {
    value_004_guess = value;
    field_010_guess = 0;
    field_00c_guess = 0;
    modeOverrideActive_0018_guess = 0;
    modeOverride_001c_guess = 0;
}

struct PickRecord_guess {
    int field_000_guess;
    int values_004_guess[3];
};

struct PickTables_guess {
    char pad_000_guess[0x2c];
    PickRecord_guess** tables_02c_guess;
};

struct PickMiddle_guess {
    char pad_000_guess[0x12c];
    PickTables_guess* tables_12c_guess;
    char pad_130_guess[0x2c];
    int field_15c_guess;
};

struct PickRoot_guess {
    char pad_000_guess[0x1a8];
    PickMiddle_guess* tables_1a8_guess;
    char pad_1ac_guess[0x60];
    int field_20c_guess;
};

// Random variant 0..n-1 of animation `tableIndex`, record `recordIndex` (n = 1 + its alternates).
// FUNCTION: TITANIUM 0x00485E69
int PlayerAnimation_guess::PickRandomVariant_guess(int tableIndex, int recordIndex) {
    PickRoot_guess* root = (PickRoot_guess*)value_004_guess;
    PickRecord_guess* records = root->tables_1a8_guess->tables_12c_guess->tables_02c_guess[tableIndex];
    int count = 1;
    PickRecord_guess* record = records + recordIndex;
    int* value = record->values_004_guess;
    int remaining = 3;
    do {
        if (*value != 0) {
            ++count;
        }
        ++value;
    } while (--remaining != 0);
    if (count == 1) {
        return 0;
    }
    return rand() % count;
}

// Mean of two fields of the animation table at 0x00692530 (rows of 9 dwords): +0xC of row `first`
// and +0x10 of row `second` (the constant at 0x006410BC is 0.5).
// FUNCTION: TITANIUM 0x00485EB7
float PlayerAnimation_guess::GetAnimBlendTime_guess(int first, int second) {
    int firstIndex = first * 9;
    int secondIndex = second * 9;
    return (EQ_ARRAY(float, 0x0069253C)[firstIndex] +
            EQ_ARRAY(float, 0x00692540)[secondIndex]) * EQ_GLOBAL(float, 0x006410BC);
}

// Sets the animation mode override flag (+0x18) and its mode (+0x1C).
// FUNCTION: TITANIUM 0x00485F0F
void PlayerAnimation_guess::SetModeOverride_guess(unsigned char flag, int value) {
    modeOverrideActive_0018_guess = flag;
    modeOverride_001c_guess = value;
}

#define g_keyOffset_guess EQ_GLOBAL(int, 0x0066D248)

// Part of the animation-change test 0x004891E9: `first` is the new animation, `second` the current one,
// both made absolute with the base 0x0066D248. False only for new 0x77-0x79 over current 0x6E or 0x76.
// FUNCTION: TITANIUM 0x00485EDC
char __stdcall FUN_00485edc_guess(int first, int second) {
    int firstValue = first + g_keyOffset_guess;
    int secondValue = second + g_keyOffset_guess;
    if ((firstValue == 0x79 || firstValue == 0x78 || firstValue == 0x77) &&
        (secondValue == 0x6e || secondValue == 0x76)) {
        return 0;
    }
    return 1;
}

// True for the absolute animation ids 0x68-0x6C, 0x7D, 0x7E and 0x80. 0x0048895A adds the base
// 0x0066D248 first; 0x004891E9 asks it when the new animation's rank (+0) is above the current one's.
// FUNCTION: TITANIUM 0x00485F20
char __stdcall FUN_00485f20_guess(int value) {
    if (value == 0x6c || value == 0x6b || value == 0x6a ||
        value == 0x68 || value == 0x69 || value == 0x7e ||
        value == 0x7d || value == 0x80) {
        return 1;
    }
    return 0;
}

#define g_pickMaskA_guess EQ_GLOBAL(unsigned int, 0x00647CB0)
#define g_pickMaskB_guess EQ_GLOBAL(unsigned int, 0x00647CB4)
#define g_pickMaskC_guess EQ_GLOBAL(unsigned int, 0x00647CC0)
#define g_pickMaskD_guess EQ_GLOBAL(unsigned int, 0x00647CC4)

// With either of two PlayerState masks set, animation keys 0x6E/0x6F become 0x70/0x71 when the model
// has a track for them (all four less the base at 0x0066D248); other keys pass through.
// FUNCTION: TITANIUM 0x00485F57
// @early-stop: budget, structural ndiff=30
int PlayerAnimation_guess::RemapAnimationKey_guess(int key, int recordIndex) {
    if (((FlagProxy_guess*)value_004_guess)->HasPlayerState_guess(g_pickMaskA_guess) ||
        ((FlagProxy_guess*)value_004_guess)->HasPlayerState_guess(g_pickMaskB_guess)) {
        PickRoot_guess* root = (PickRoot_guess*)value_004_guess;
        PickTables_guess* tables = root->tables_1a8_guess->tables_12c_guess;
        if (key != 0x6e - g_keyOffset_guess &&
            key != 0x6f - g_keyOffset_guess) {
            return key;
        }
        int slot = key == 0x6e - g_keyOffset_guess
            ? 0x70 - g_keyOffset_guess : 0x71 - g_keyOffset_guess;
        PickRecord_guess* records = tables->tables_02c_guess[slot];
        if (records != 0) {
            if (records[recordIndex].field_000_guess != 0) {
                return slot;
            }
            if (records->field_000_guess != 0) {
                return slot;
            }
        }
    }
    return key;
}

// Animation mode: the override when set; 5 when mounted; else from two PlayerState masks and `key`
// (0-4, or the spawn's +0x20C when set).
// FUNCTION: TITANIUM 0x00485FD6
int PlayerAnimation_guess::SelectMode_guess(int key) {
    if (modeOverrideActive_0018_guess != 0) {
        return modeOverride_001c_guess;
    }
    char first = ((FlagProxy_guess*)value_004_guess)->HasPlayerState_guess(g_pickMaskC_guess);
    char second = ((FlagProxy_guess*)value_004_guess)->HasPlayerState_guess(g_pickMaskD_guess);
    PickRoot_guess* root = (PickRoot_guess*)value_004_guess;
    if (root->tables_1a8_guess->field_15c_guess != 0) {
        return 5;
    }
    int result = 0;
    if (first != 0) {
        if (second != 0) {
            result = 3;
        } else {
            if (key == 0x56 || key == 0x57) {
                result = 2;
            } else {
                result = (key == 0x58) ? 4 : 1;
            }
            if (root->field_20c_guess != -1) {
                result = root->field_20c_guess;
            }
        }
    }
    return result;
}

struct NestedTarget_guess {
    unsigned int field_000_guess;
    // EXTERNAL: TITANIUM 0x0040600C NestedTarget_guess::SetElementIdx_guess
    void SetElementIdx_guess(unsigned int value, unsigned int* output);
};

struct IndexedOwner_guess {
    char pad_000_guess[0x328];
    NestedTarget_guess field_328_guess;
    void FUN_00484909_guess(unsigned int value);
};

// Queues `value` (1-9) on the spawn's round-robin table (+0x328); others are ignored.
// FUNCTION: TITANIUM 0x00484909
void IndexedOwner_guess::FUN_00484909_guess(unsigned int value) {
    if (value != 0 && value <= 9) {
        field_328_guess.SetElementIdx_guess(field_328_guess.field_000_guess, &value);
    }
}

