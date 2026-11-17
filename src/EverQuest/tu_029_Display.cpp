// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 29: a hint from compare/tumap.py.
// CDisplay (Display.cpp): world load and teardown, the UI build, cameras, lights, fog, sky and the
// per-frame render. Evidence: the "CDisplay::CreatePlayerActor" string, and the bodies follow Display.cpp
// of the earlier sibling decomp. pinstCDisplay is 0x00905D24, so CoordinateService_guess, GameState_guess,
// NpcFileLoader_guess, g_client_guess and the `this` casts (AngleMath_guess, StateOwner_guess, ClockData_guess,
// LabelOwner_guess) are all CDisplay.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/races.h"
#include "titanium/opcodes.h"
#include <float.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#define _exit _exit_guess

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x0060E3A3 atol
extern "C" long __cdecl atol(const char* value);
// EXTERNAL: TITANIUM 0x0060E3A3 atoi
extern "C" int __cdecl atoi(const char* value);

// EXTERNAL: TITANIUM 0x0060F60D _fabs
extern "C" double __cdecl _fabs(double value);

struct Releasable_guess {
    Releasable_guess* Release_guess(unsigned char should_free);
};

struct Counter_guess {
    unsigned char pad_0000_guess[0x48];
    int value_0048_guess;
    unsigned char pad_004c_guess[0x20];
    int count_006c_guess;
    void Update_guess(int value);
};

struct CopyBlock_guess {
    int value_0000_guess;
    int values_0004_guess[10];
    CopyBlock_guess* CopyFrom_guess(const CopyBlock_guess* source);
};

struct Vector3_guess {
    float x_0000_guess;
    float y_0004_guess;
    float z_0008_guess;
    void Subtract_guess(Vector3_guess* output, const Vector3_guess* other);
    float LengthSquared_guess();
    float DistanceSquared_guess(const Vector3_guess* other);
    float Length2D_guess();
};

struct PositionedObject_guess {
    unsigned char pad_0000_guess[0x30];
    Vector3_guess position_0030_guess;
};

struct FloatSink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Apply_guess(float value);
};

struct CameraFrame_guess {
    int pad_0000_guess[3];
    Vector3_guess initialPosition_000c_guess;
    int spawnId_0018_guess;
};

struct ViewActor_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual char* Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Release_guess(int value);
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
    virtual void GetPosition_guess(Vector3_guess* value);
    virtual void FillCameraFrame_guess(CameraFrame_guess* value);
};

struct ActorAssociationNode_guess {
    ViewActor_guess* actor_0000_guess;
};

struct ActorAssociation_guess {
    unsigned char pad_0000_guess[0x120];
    char text_0120_guess[0x88];
    ActorAssociationNode_guess* node_01a8_guess;
};

struct RequestData_guess {
    int value_0000_guess;
    int value_0004_guess;
    int value_0008_guess;
};

struct ActorUpdateData_guess {
    unsigned char pad_0000_guess[0x48];
    float floorHeight_0048_guess;
    unsigned char pad_004c_guess[4];
    int value_0050_guess;
    unsigned char pad_0054_guess[0xe68];
    int lastUpdateTime_0ebc_guess;
};

#include "titanium/layouts/core.h"
#include "titanium/wnd/CAAWnd.h"
#include "titanium/wnd/CAdvancedDisplayOptionsWnd.h"
#include "titanium/wnd/CAdventureLeaderboardWnd.h"
#include "titanium/wnd/CAdventureRequestWnd.h"
#include "titanium/wnd/CAdventureStatsWnd.h"
#include "titanium/wnd/CAlarmWnd.h"
#include "titanium/wnd/CAltStorageWnd.h"
#include "titanium/wnd/CAvaZoneWnd.h"
#include "titanium/wnd/CBandolierWnd.h"
#include "titanium/wnd/CBarterMerchantWnd.h"
#include "titanium/wnd/CBarterSearchWnd.h"
#include "titanium/wnd/CBarterWnd.h"
#include "titanium/wnd/CBazaarSearchWnd.h"
#include "titanium/wnd/CBazaarWnd.h"
#include "titanium/wnd/CBodyTintWnd.h"
#include "titanium/wnd/CBookWnd.h"
#include "titanium/wnd/CBreathWnd.h"
#include "titanium/wnd/CBugReportWnd.h"
#include "titanium/wnd/CCastingWnd.h"
#include "titanium/wnd/CColorPickerWnd.h"
#include "titanium/wnd/CCombatSkillSelectWnd.h"
#include "titanium/wnd/CCursorAttachment.h"
#include "titanium/wnd/CDynamicZoneWnd.h"
#include "titanium/wnd/CEQMainWnd.h"
#include "titanium/wnd/CEditLabelWnd.h"
#include "titanium/wnd/CFeedbackWnd.h"
#include "titanium/wnd/CFileSelectionWnd.h"
#include "titanium/wnd/CFindLocationWnd.h"
#include "titanium/wnd/CFriendsWnd.h"
#include "titanium/wnd/CGemsGameWnd.h"
#include "titanium/wnd/CGiveWnd.h"
#include "titanium/wnd/CGroupSearchFiltersWnd.h"
#include "titanium/wnd/CGroupSearchWnd.h"
#include "titanium/wnd/CGuildBankWnd.h"
#include "titanium/wnd/CGuildManagementWnd.h"
#include "titanium/wnd/CGuildTributeMasterWnd.h"
#include "titanium/wnd/CInspectWnd.h"
#include "titanium/wnd/CItemExpTransferWnd.h"
#include "titanium/wnd/CJournalCatWnd.h"
#include "titanium/wnd/CJournalNPCWnd.h"
#include "titanium/wnd/CLFGuildWnd.h"
#include "titanium/wnd/CLargeDialogWnd.h"
#include "titanium/wnd/CLeadershipWnd.h"
#include "titanium/wnd/CLoadskinWnd.h"
#include "titanium/wnd/CLootWnd.h"
#include "titanium/wnd/CMIZoneSelectWnd.h"
#include "titanium/wnd/CMailAddressBookWnd.h"
#include "titanium/wnd/CMailCompositionWnd.h"
#include "titanium/wnd/CMailWnd.h"
#include "titanium/wnd/CMapToolbarWnd.h"
#include "titanium/wnd/CMapViewWnd.h"
#include "titanium/wnd/CMerchantWnd.h"
#include "titanium/wnd/CNoteWnd.h"
#include "titanium/wnd/COptionsWnd.h"
#include "titanium/wnd/CPetInfoWnd.h"
#include "titanium/wnd/CPetitionQWnd.h"
#include "titanium/wnd/CPlayerNotesWnd.h"
#include "titanium/wnd/CPointMerchantWnd.h"
#include "titanium/wnd/CPotionBeltWnd.h"
#include "titanium/wnd/CProgressionSelectionWnd.h"
#include "titanium/wnd/CPvPStatsWnd.h"
#include "titanium/wnd/CPvpLeaderboardWnd.h"
#include "titanium/wnd/CQuantityWnd.h"
#include "titanium/wnd/CRaidOptionsWnd.h"
#include "titanium/wnd/CRaidWnd.h"
#include "titanium/wnd/CRespawnWnd.h"
#include "titanium/wnd/CServerListWnd.h"
#include "titanium/wnd/CSkillsSelectWnd.h"
#include "titanium/wnd/CSkillsWnd.h"
#include "titanium/wnd/CSocialEditWnd.h"
#include "titanium/wnd/CSoulmarkWnd.h"
#include "titanium/wnd/CTargetOfTargetWnd.h"
#include "titanium/wnd/CTaskSelectWnd.h"
#include "titanium/wnd/CTaskWnd.h"
#include "titanium/wnd/CTextEntryWnd.h"
#include "titanium/wnd/CTicketCommentWnd.h"
#include "titanium/wnd/CTicketWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CTitleWnd.h"
#include "titanium/wnd/CTrackingWnd.h"
#include "titanium/wnd/CTradeWnd.h"
#include "titanium/wnd/CTradeskillWnd.h"
#include "titanium/wnd/CTrainWnd.h"
#include "titanium/wnd/CTributeBenefitWnd.h"
#include "titanium/wnd/CTributeMasterWnd.h"
#include "titanium/wnd/CVideoModesWnd.h"
#include "titanium/wnd/CVoiceMacroWnd.h"

struct ActorUpdateNode_guess {
    unsigned char pad_0000_guess[0x30];
    FloatBits value_0030_guess;
    float value_0034_guess;
    float value_0038_guess;
    unsigned char pad_003c_guess[0x16c];
    ActorUpdateData_guess* data_01a8_guess;
    unsigned char pad_01ac_guess[0x68];
    ActorUpdateNode_guess* next_0214_guess;
};

struct MotionSource_guess {
    Vector3_guess position_0000_guess;
    unsigned char pad_000c_guess[0x10];
    float angle_001c_guess;
    unsigned char pad_0020_guess[0x0c];
    float angle_002c_guess;
};

struct MotionSource30_guess {
    unsigned char pad_0000_guess[0x30];
    MotionSource_guess source_0030_guess;
};

struct MotionSource10_guess {
    unsigned char pad_0000_guess[0x10];
    MotionSource_guess source_0010_guess;
};

struct MotionSink_guess {
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
    virtual int Update_guess(Vector3_guess* position);
    virtual void Apply_guess(float* angles);
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual float GetAngle_guess();
};

struct MotionHook_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Update_guess(Vector3_guess* position);
};

struct MotionAngleTable_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Cos_guess(float angle);
    virtual float Sin_guess(float angle);
};

#define g_motionAngleTable_guess EQ_GLOBAL(MotionAngleTable_guess*, 0x0099E374)

struct MotionTask_guess {
    Vector3_guess position_0000_guess;
    unsigned char pad_000c_guess[0x0c];
    float value_0018_guess;
    float angle_001c_guess;
    FloatBits value_0020_guess;
    unsigned char pad_0024_guess[8];
    float angle_002c_guess;
    unsigned char pad_0030_guess[0x28];
    MotionTask_guess* previous_0058_guess;
    MotionTask_guess* next_005c_guess;
    MotionSource30_guess* source30_0060_guess;
    MotionSource10_guess* source10_0064_guess;
    MotionSink_guess* sink_0068_guess;
    MotionHook_guess* hook_006c_guess;
    float scale_0070_guess;
    float offset_0074_guess;
    unsigned int expiration_0078_guess;
    int lastUpdate_007c_guess;
    int angleOffset_0080_guess;
    int angleOffset_0084_guess;
    int mode_0088_guess;
};

#define g_motionTaskHead_guess EQ_GLOBAL(MotionTask_guess*, 0x00905CDC)
#define g_oneFloat_guess EQ_GLOBAL(float, 0x0063F4D0)

struct CoordinateService_guess {
    unsigned char pad_0000_guess[0x2cf8];
    int state_2cf8_guess;
    unsigned char pad_2cfc_guess[0x18];
    float value_2d14_guess;
    // EXTERNAL: TITANIUM 0x00439BD1 CoordinateService_guess::SimpleDistance_guess
    float SimpleDistance_guess(float x0, float y0, float z0, float x1, float y1, float z1, float scale);
    float TrueDistance_guess(float x0, float y0, float z0, float x1, float y1, float z1, float scale);
    float PlayerSimpleDistance_guess(const PositionedObject_guess* first, const PositionedObject_guess* second, float scale);
    float PlayerDistance_guess(const PositionedObject_guess* first, const PositionedObject_guess* second, float scale);
    // EXTERNAL: TITANIUM 0x00439F26 CoordinateService_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x, float y, float z);
};

struct QueryScratch_guess {
    int values_guess[2];
    float result_guess;
};

typedef void (__cdecl *QueryCallback_guess)();

// EXTERNAL: TITANIUM 0x0042D05F CanCollideWith_guess
void __cdecl CanCollideWith_guess();
// EXTERNAL: TITANIUM 0x0042CE5D LAB_0042ce5d_guess
void __cdecl LAB_0042ce5d_guess();

struct QueryService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual int Query_guess(const Vector3_guess* first, const Vector3_guess* second, float radius,
        QueryCallback_guess callback0, QueryCallback_guess callback1, int value0,
        QueryScratch_guess* scratch0, int* scratch1, int* scratch2, int value1, int value2);
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
    virtual unsigned char Save_guess();
    virtual void Slot21_guess();
    virtual void Restore_guess(unsigned char value);
};

#define g_queryService_guess EQ_GLOBAL(QueryService_guess*, 0x0099E370)
#define g_queryFallbackEnabled_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_queryFallbackRadius_guess EQ_GLOBAL(float, 0x00923BD8)

struct PositionHandler_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Update_guess(Vector3_guess* position);
    virtual void GetValues_guess(float* values);
};

struct ActorUpdateManager_guess {
    void SetupEQPlayers_guess();
    void ComparePosition_guess(PositionHandler_guess* handler, Vector3_guess* position);
    void ComparePositionAhead_guess(PositionHandler_guess* handler, float* p);
};

#define g_actorUpdateHead_guess EQ_GLOBAL(ActorUpdateNode_guess*, 0x00905CC4)
#define g_coordinateService_guess EQ_GLOBAL(CoordinateService_guess*, 0x00905D24)
#define g_floatSink_guess EQ_GLOBAL(FloatSink_guess*, 0x0099E374)

struct Trig0043D9C5_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float angle);
    virtual float Cos_guess(float angle);
};

#define g_trig0043D9C5_guess EQ_GLOBAL(Trig0043D9C5_guess*, 0x0099E374)

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

struct AcquiredObject_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};

struct ActorReceiver_guess {
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
    virtual unsigned char Slot12_guess(Vector3_guess* position);
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess(int value);
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void SetActor_guess(ViewActor_guess* actor);
    virtual void Acquire_guess(int value, RequestData_guess* data, float distance, AcquiredObject_guess** result);
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess(void* value);
};

struct StatusByte_guess {
    unsigned char pad_0000_guess[0x1e2];
    unsigned char value_01e2_guess;
};

struct CameraService_guess {
    // EXTERNAL: TITANIUM 0x0044A7B1 CameraService_guess::SetListenerLocation_guess
    void SetListenerLocation_guess(float value);
    // EXTERNAL: TITANIUM 0x0044A63A CameraService_guess::ProcessSound_guess
    void ProcessSound_guess();
};

struct SharedStringOutput_guess {
    virtual void Set_guess(const char* value);
};

struct DistanceOwner_guess {
    // EXTERNAL: TITANIUM 0x0049180C DistanceOwner_guess::GetDistance_guess
    double GetDistance_guess();
};

#define g_currentActor_guess EQ_GLOBAL(void*, 0x00850CC4)
#define g_messageSource_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_actorAssociation_guess EQ_GLOBAL(ActorAssociation_guess*, 0x00905CE4)
#define g_actorReceiver_guess EQ_GLOBAL(ActorReceiver_guess*, 0x0099E368)
#define g_distanceOwner_guess EQ_GLOBAL(DistanceOwner_guess*, 0x00988DF0)
#define g_statusByte_guess EQ_GLOBAL(StatusByte_guess*, 0x00850B9C)
#define g_cameraService_guess EQ_GLOBAL(CameraService_guess*, 0x00851390)
#define g_sharedStringOutput_guess EQ_GLOBAL(SharedStringOutput_guess*, 0x008503A8)

// EXTERNAL: TITANIUM 0x00610884 FUN_00610884_guess
double __cdecl FUN_00610884_guess(double value);
// EXTERNAL: TITANIUM 0x0047C88E GetSpawnByName_guess
ActorAssociation_guess* __cdecl GetSpawnByName_guess(const char* name);
// EXTERNAL: TITANIUM 0x0047981D FindPlayerByPartialDisplayName_guess
ActorAssociation_guess* __cdecl FindPlayerByPartialDisplayName_guess(const char* name, int zero);
// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output, unsigned int id, const char* text, int zero1, int zero2,
    int zero3, int zero4, int zero5, int zero6, int zero7, int zero8);

struct SharedField_guess {
    int value_0000_guess;
    // EXTERNAL: TITANIUM 0x00571F70 SharedField_guess::Assign_guess
    void Assign_guess(const SharedField_guess* source);
};

struct DialogObject_guess {
    unsigned char value_0000_guess;
    unsigned char pad_0001_guess[3];
    int value_0004_guess;
    SharedField_guess value_0008_guess;
    int value_000c_guess;
    int value_0010_guess;
    int value_0014_guess;
    DialogObject_guess* CopyFrom_guess(const DialogObject_guess* source);
};

typedef int (__stdcall *DialogBoxParamA_guess)(void*, const char*, void*, int (__cdecl *)(HWND, unsigned int, short), long);

// EXTERNAL: TITANIUM 0x005A39B0 BeforeRelease_guess
void __cdecl BeforeRelease_guess();
int __cdecl DialogProc_guess(HWND window, unsigned int message, short wparam);
// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);
// EXTERNAL: TITANIUM 0x00576ED0 FUN_00576ed0_guess
void __cdecl FUN_00576ed0_guess(const char* value);
// EXTERNAL: TITANIUM 0x0060BE20 FUN_0060be20_guess
int __cdecl FUN_0060be20_guess(const char* section, const char* key, int default_value, const char* filename);
// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section, const char* key, const char* value, const char* filename);
// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
int __cdecl FUN_0060be50_guess(const char* section, const char* key, const char* default_value, char* value, unsigned int size, const char* filename);
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);
// EXTERNAL: TITANIUM 0x0060E887 fopen
void* __cdecl fopen(const char* filename, const char* mode);
// EXTERNAL: TITANIUM 0x0060E790 fclose
int __cdecl fclose(void* file);
typedef unsigned int (__stdcall *GetPrivateProfileStringA_guess)(const char*, const char*, const char*, char*, unsigned int, const char*);
#define g_getPrivateProfileStringA_guess EQ_GLOBAL(GetPrivateProfileStringA_guess, 0x0063F124)
#define g_screenshotOutput_guess EQ_GLOBAL(ScreenshotOutput_guess*, 0x0099E364)
// EXTERNAL: TITANIUM 0x006115DC GetDrive_guess
int __cdecl GetDrive_guess();
// EXTERNAL: TITANIUM 0x00611595 GetCurrentDirectory_guess
char* __cdecl GetCurrentDirectory_guess(int drive, char* buffer, int size);
// EXTERNAL: TITANIUM 0x0060E460 AppendString_guess
void __cdecl AppendString_guess(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x00571F70 Retain_guess
void __stdcall Retain_guess(const CopyBlock_guess* source);

struct HashNode_guess {
    int value_0000_guess;
    int value_0004_guess;
    HashNode_guess* next_0008_guess;
};

struct HashTable_guess {
    HashNode_guess** buckets_0000_guess;
    int bucketCount_0004_guess;
    int nodeCount_0008_guess;
    int usedBucketCount_000c_guess;
    void Clear_guess();
    void Free_guess();
};

// EXTERNAL: TITANIUM 0x0044830F FUN_0044830f_guess
void __fastcall FUN_0044830f_guess(HashNode_guess* self);

struct TableEntry_guess {
    HashTable_guess* table_0000_guess;
};

struct OwnedWord_guess {
    int value_0000_guess;
    // EXTERNAL: TITANIUM 0x004482FB OwnedWord_guess::~OwnedWord_guess
    ~OwnedWord_guess();
};

struct TableHolder_guess {
    void* buffer_0000_guess;
    unsigned char pad_0004_guess[0x0c];
    // EXTERNAL: TITANIUM 0x004466FA TableHolder_guess::FirstItem_guess
    TableEntry_guess* FirstItem_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A TableHolder_guess::NextItem_guess
    TableEntry_guess* NextItem_guess(TableEntry_guess* entry);
    // EXTERNAL: TITANIUM 0x0048F513 TableHolder_guess::ClearChains_guess
    void ClearChains_guess();
    void ClearTables_guess();
    // EXTERNAL: TITANIUM 0x00490E9C TableHolder_guess::~TableHolder_guess
    ~TableHolder_guess();
};

struct TableHolderEx_guess : TableHolder_guess {
    OwnedWord_guess word_0010_guess;
    ~TableHolderEx_guess();
};

// Removes every node of the hash table: each node's value is released (0x0044830F) and the node freed,
// with the node and used-bucket counts kept in step. The bucket array stays.
// FUNCTION: TITANIUM 0x004358C3
void HashTable_guess::Clear_guess() {
    for (int i = 0; i < bucketCount_0004_guess; ++i) {
        HashNode_guess* node = buckets_0000_guess[i];
        if (node != 0) {
            --usedBucketCount_000c_guess;
            do {
                HashNode_guess* next = node->next_0008_guess;
                FUN_0044830f_guess(node);
                free(node);
                --nodeCount_0008_guess;
                node = next;
            } while (node != 0);
            buckets_0000_guess[i] = 0;
        }
    }
}

// Empties the hash table (0x004358C3) and frees its bucket array.
// FUNCTION: TITANIUM 0x00435906
void HashTable_guess::Free_guess() {
    Clear_guess();
    free(buckets_0000_guess);
}

// Frees every hash table held in the chain list (each emptied by 0x00435906 and then freed), then clears
// the chains themselves (0x0048F513).
// FUNCTION: TITANIUM 0x00435918
void TableHolder_guess::ClearTables_guess() {
    TableEntry_guess* entry = FirstItem_guess();
    while (entry != 0) {
        HashTable_guess* table = entry->table_0000_guess;
        entry = NextItem_guess(entry);
        if (table != 0) {
            table->Free_guess();
            free(table);
        }
    }
    ClearChains_guess();
}

// Destructor of the database-string manager: frees every hash table it holds (0x00435918).
// FUNCTION: TITANIUM 0x00435954
TableHolderEx_guess::~TableHolderEx_guess() {
    ClearTables_guess();
}

// Scalar deleting destructor: runs the cleanup at 0x005A39B0, and flag 1 frees the memory.
// FUNCTION: TITANIUM 0x00435A8B
Releasable_guess* Releasable_guess::Release_guess(unsigned char should_free) {
    BeforeRelease_guess();
    if ((should_free & 1) != 0) {
        free(this);
    }
    return this;
}

// Records `value` at +0x48, counting how many times in a row the same value came (+0x6C, back to 1 on a
// change).
// FUNCTION: TITANIUM 0x00435AA7
void Counter_guess::Update_guess(int value) {
    if (value_0048_guess != value) {
        count_006c_guess = 1;
    } else {
        ++count_006c_guess;
    }
    value_0048_guess = value;
}

// Assignment: the string at +0 (0x00571F70) and the ten ints after it.
// FUNCTION: TITANIUM 0x00435AC2
CopyBlock_guess* CopyBlock_guess::CopyFrom_guess(const CopyBlock_guess* source) {
    Retain_guess(source);
    values_0004_guess[0] = source->values_0004_guess[0];
    values_0004_guess[1] = source->values_0004_guess[1];
    values_0004_guess[2] = source->values_0004_guess[2];
    values_0004_guess[3] = source->values_0004_guess[3];
    values_0004_guess[4] = source->values_0004_guess[4];
    values_0004_guess[5] = source->values_0004_guess[5];
    values_0004_guess[6] = source->values_0004_guess[6];
    values_0004_guess[7] = source->values_0004_guess[7];
    values_0004_guess[8] = source->values_0004_guess[8];
    values_0004_guess[9] = source->values_0004_guess[9];
    return this;
}

// Writes this vector minus `other` to `output`.
// FUNCTION: TITANIUM 0x00435B13
void Vector3_guess::Subtract_guess(Vector3_guess* output, const Vector3_guess* other) {
    float z = z_0008_guess - other->z_0008_guess;
    float y = y_0004_guess - other->y_0004_guess;
    float x = x_0000_guess - other->x_0000_guess;
    output->x_0000_guess = x;
    output->y_0004_guess = y;
    output->z_0008_guess = z;
}

// Squared length of the vector (x*x + y*y + z*z).
// FUNCTION: TITANIUM 0x00435B36
float Vector3_guess::LengthSquared_guess() {
    return x_0000_guess * x_0000_guess
        + y_0004_guess * y_0004_guess
        + z_0008_guess * z_0008_guess;
}

// Squared distance between this point and `other`.
// FUNCTION: TITANIUM 0x00435B55
float Vector3_guess::DistanceSquared_guess(const Vector3_guess* other) {
    float x = x_0000_guess - other->x_0000_guess;
    float y = y_0004_guess - other->y_0004_guess;
    float z = z_0008_guess - other->z_0008_guess;
    float result = x * x;
    result += z * z;
    result += y * y;
    return result;
}

// Length of the vector in the x-y plane (z ignored).
// FUNCTION: TITANIUM 0x00435B82
float Vector3_guess::Length2D_guess() {
    float y = y_0004_guess;
    y = x_0000_guess * x_0000_guess + y * y;
    return (float)FUN_00610884_guess(y);
}

struct Vtable00435BBA_guess {
    void** vtable_0000_guess;
    Vtable00435BBA_guess* Release_guess(unsigned char should_free);
};

struct Delegate004382E5_guess {
    // EXTERNAL: TITANIUM 0x005AE6B0 Delegate004382E5_guess::Invoke_guess
    unsigned char Invoke_guess();
};

struct KeyPredicate_guess {
    int Test_guess(int key);
};

// EXTERNAL: TITANIUM 0x00571FC0 Text_guess::Assign_guess
struct Text_guess {
    void* value_0000_guess;
    Text_guess() : value_0000_guess(0) {}
    // EXTERNAL: TITANIUM 0x004482FB Text_guess::~Text_guess
    ~Text_guess();
    void Assign_guess(const char* value);
};

// EXTERNAL: TITANIUM 0x00641F24 ??_7OwnerBase00435BDE_guess@@6B@
struct OwnerBase00435BDE_guess {
    virtual void Slot00_guess();
    unsigned char pad_0004_guess[4];
    ~OwnerBase00435BDE_guess() {}
    OwnerBase00435BDE_guess* Destroy_guess(unsigned char should_free);
};

struct Owner00435BDE_guess {
    OwnerBase00435BDE_guess base_0000_guess;
    unsigned char state_0008_guess;
    unsigned char pad_0009_guess[7];
    Text_guess text_0010_guess;
    void SetText_guess(const char* value);
    Owner00435BDE_guess* Release_guess(unsigned char should_free);
    Owner00435BDE_guess* ReleaseWithFlag_guess(unsigned char should_free);
    void Destroy_guess();
    ~Owner00435BDE_guess();
};

// EXTERNAL: TITANIUM 0x0048C879 GetRaceModelTag_guess
void __cdecl GetRaceModelTag_guess(char* buffer, int key, int state);

typedef void (__cdecl *KeyCallback_guess)(char* buffer);

struct Queue_guess {
    // EXTERNAL: TITANIUM 0x0044A7A0 Queue_guess::SetRoomType_guess
    void SetRoomType_guess(int value);
    // EXTERNAL: TITANIUM 0x0044AFFC Queue_guess::EmitterSetWind_guess
    void EmitterSetWind_guess(int value);
    // EXTERNAL: TITANIUM 0x0044B014 Queue_guess::FUN_0044b014_guess
    void FUN_0044b014_guess(int value);
    // EXTERNAL: TITANIUM 0x0044A537 Queue_guess::WavePlay_guess
    void WavePlay_guess(int value, struct Params_guess* params);
    // EXTERNAL: TITANIUM 0x0044AF75 Queue_guess::SetEnclosedEnvironment_guess
    void SetEnclosedEnvironment_guess();
    // EXTERNAL: TITANIUM 0x0044AFA2 Queue_guess::SetIndoorEnvironment_guess
    void SetIndoorEnvironment_guess();
    // EXTERNAL: TITANIUM 0x0044AFCF Queue_guess::SetOutdoorEnvironment_guess
    void SetOutdoorEnvironment_guess();
    // EXTERNAL: TITANIUM 0x0044B068 Queue_guess::SetWeatherLoopsMuted_guess
    void SetWeatherLoopsMuted_guess(char value);
    // EXTERNAL: TITANIUM 0x0044B02C Queue_guess::SetMode_guess
    void SetMode_guess(char state);
    // EXTERNAL: TITANIUM 0x0044A617 Queue_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int first, int second);
};

struct ScreenshotOutput_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual int Slot06_guess();
    virtual int Slot07_guess();
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void WriteScreenshot_guess(const char* filename);
};

struct ScreenshotTarget_guess {
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
    virtual void SetScale_guess(float value, int count);
};

struct ScreenshotHandler_guess {
    void SetActorScale_guess(ScreenshotTarget_guess* output, float value, int count);
};

struct Params_guess {
    // EXTERNAL: TITANIUM 0x004C5C39 Params_guess::Params_guess
    Params_guess();
    int pad_0000_guess[4];
    int value_0010_guess;
    int value_0014_guess;
    int value_0018_guess;
    int value_001c_guess;
    int value_0020_guess;
    int pad_0024_guess;
    int value_0028_guess;
};

struct ActorDef_guess;
struct ActorInstance_guess;

struct Service_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual int Slot03_guess(float value0, float value1, float value2, int value3);
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual unsigned char Slot12_guess(Vector3_guess* position);
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual int Slot17_guess(ActorDef_guess* def, Vector3_guess* position, Vector3_guess* second,
        int mode, float nearValue_guess, float factor, float distance, int zero0, int zero1, int zero2,
        int zero3, ActorInstance_guess** out);
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess(int value);
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess(void* value);
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual int Slot32_guess(void* camera, int id, int ownerId, int x, int y, int type, void** actor, int first, int second);
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess(Vector3_guess* vector, float value);
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
};

struct StateDispatch_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess(Vector3_guess* vector);
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void Slot49_guess();
    virtual void Notify_guess(int selection, int enabled);
};

struct StateFlag_guess {
    unsigned char pad_0000_guess[0x0c];
    unsigned char state_000c_guess;
};

struct AboutToHide_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Slot04_guess();
    virtual void Slot05_guess(float value);
    virtual void Slot06_guess(float value);
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess(void* value);
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual int Slot13_guess(Vector3_guess* position, int value);
    virtual void Slot14_guess(void* value);
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual float Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual float Slot20_guess(float value);
    virtual float Slot21_guess(float value);
    virtual float Slot22_guess(float value);
};

struct CDisplay_guess {
    int value_0000_guess;
    unsigned char state_0004_guess;
    unsigned char state_0005_guess;
    unsigned char pad_0006_guess[2];
    float yon_0008_guess;  // far clip (yon) distance; SetFogState sets it to the fog end
    float value_000c_guess;
    unsigned char state_0010_guess;
    unsigned char state_0011_guess;
    unsigned char state_0012_guess;
    unsigned char state_0013_guess;
    unsigned char state_0014_guess;
    unsigned char pad_0015_guess[0x118 - 0x15];
    AboutToHide_guess* callback_0118_guess;  // the world camera
    void* buffer_011c_guess;
    void* buffer_0120_guess;
    int value_0124_guess;
    unsigned char state_0128_guess;
    unsigned char state_0129_guess;  // "UseLuclinElementals" (eqclient.ini)
    unsigned char state_012a_guess;
    unsigned char pad_012b_guess[0x12c - 0x12b];
    float fogStart_012c_guess;
    float fogEnd_0130_guess;
    unsigned char fogRed_0134_guess;
    unsigned char fogGreen_0135_guess;
    unsigned char fogBlue_0136_guess;
    unsigned char pad_0137_guess[0x144 - 0x137];
    unsigned char state_0144_guess;
    unsigned char state_0145_guess;
    unsigned char pad_0146_guess[2];
    int frameTime_0148_guess;  // frame time in milliseconds
    unsigned char state_014c_guess;
    unsigned char state_014d_guess;  // doors ignore the hour (UpdateDoorStateBasedOnWorldTime)
    unsigned char pad_014e_guess[2];
    int lastUpdateTime_0150_guess;
    int value_0154_guess;
    int value_0158_guess;
    unsigned char buffer_015c_guess[10000];
    int value_286c_guess;
    int torchLight_2870_guess;
    int magTorchLight_2874_guess;
    int smLanternLight_2878_guess;
    int lgLanternLight_287c_guess;
    int smMagicLight_2880_guess;
    int lgMagicLight_2884_guess;
    int candleLight_2888_guess;
    int redLight_288c_guess;
    int blueLight_2890_guess;
    unsigned char pad_2894[0x28c4 - 0x2894];
    int value_28c4_guess;
    unsigned char pad_28c8[0x28d4 - 0x28c8];
    float value_28d4_guess;
    float value_28d8_guess;
    float value_28dc_guess;
    unsigned char state_28e0_guess;
    unsigned char pad_28e1[0x28e4 - 0x28e1];
    void* window_28e4_guess;
    float fieldOfView_28e8_guess;  // field of view, set by SetViewAngle (0x00440F51)
    float value_28ec_guess;
    int value_28f0_guess;
    float value_28f4_guess;
    unsigned char pad_28f8[0x2cf8 - 0x28f8];
    int value_2cf8_guess;  // world display is up: set at the end of LoadZone, cleared by StopWorldDisplay
    int displayInitialized_2cfc_guess;  // display initialised (InitDisplay)
    int particlesInitialized_2d00_guess;  // particle system loaded
    int viewLeft_2d04_guess;
    int viewTop_2d08_guess;
    int viewRight_2d0c_guess;
    int viewBottom_2d10_guess;
    float value_2d14_guess;  // collision radius used by the floor and ceiling probes; LoadZone sets 1.0
    int playerLight_2d18_guess;  // the player's own light ("mylight01")
    int sunLight_2d1c_guess;  // SUN_LIGHTDEF light
    int value_2d20_guess;  // the sun object made from it
    unsigned char pad_2d24[0x2d28 - 0x2d24];
    Text_guess text_2d28_guess;
    unsigned char state_2d2c_guess;
    unsigned char pad_2d2d[0x2d54 - 0x2d2d];
    unsigned char state_2d54_guess;
    unsigned char pad_2d55[0x2d58 - 0x2d55];
    int value_2d58_guess;
    unsigned char state_2d5c_guess;  // sound environment set by hand: no per-frame choice
    unsigned char pcNameSprites_2d5d_guess;
    unsigned char npcNameSprites_2d5e_guess;
    // 0x2D5F..0x2D65: MultipassLighting, Shadows, WaterSwap, 20PixelShaders, 14PixelShaders,
    // 1xPixelShaders, VertexShaders, in the order InitGlobalData reads them from eqclient.ini.
    unsigned char state_2d5f_guess;
    unsigned char state_2d60_guess;
    unsigned char state_2d61_guess;
    unsigned char state_2d62_guess;
    unsigned char state_2d63_guess;
    unsigned char state_2d64_guess;
    unsigned char state_2d65_guess;
    unsigned char pad_2d66_guess[2];
    int actorClipPlane_2d68_guess;
    int shadowClipPlane_2d6c_guess;
    CDisplay_guess(void* window);
    ~CDisplay_guess();
    void InitCommonLights_guess();
    int GetValue2cf8_guess();
    unsigned char s3dCollideSphereWithWorld_guess(int value0, int value1, int value2, float x, float y, float z,
        float* outX, float* outY, float* outZ, unsigned char mode);
    int GetEnvironment_guess(float value0, float value1, float value2, int* flag);
    int GetValue2d00_guess();
    float FindZoneTopZ_guess(float x, float y, float z);
    float GetCeilingHeight_guess(float x, float y, float z, float scale);
    void* GetClickedActor(int x, int y, int type, int first, int second);
    struct PickActor_guess* PickActorAt_guess(int x, int y, bool select, int first, int second);
    ActorInstance_guess* CreateActor_guess(char* name, float x, float y, float z, float x2, float y2,
        float height, bool allowFallback, bool useFlag);
    // EXTERNAL: TITANIUM 0x0048C285 CDisplay_guess::GetOnActor_guess
    void GetOnActor_guess(struct PickActor_guess* actor, struct PickOwner_guess* owner);
    void InitParticleSystem_guess();
    void SetDisplayOptions_guess(int* result);
    void DeleteLight_guess(int value);
    void Handle_guess(int value);
    void SetState2d60_guess(char value);
    void SetState2d5f_guess(char value);
    void SetState2d61_guess(char value);
    void SetState2d62_guess(char value);
    void SetState2d64_guess(char value);
    void SetState2d63_guess(char value);
    void SetState2d65_guess(char value);
    void RealRender_World_guess();
    // EXTERNAL: TITANIUM 0x004439C0 CDisplay_guess::SetSkyBackground_guess
    void SetSkyBackground_guess();
    void SetDayPeriod_guess(unsigned char hour, unsigned char minute);
    void Render_World_guess();
    void ResetUI_guess();
    // EXTERNAL: TITANIUM 0x0043AEBB CDisplay_guess::CleanCharSelectUI_guess
    void CleanCharSelectUI_guess();
    // EXTERNAL: TITANIUM 0x0043AF46 CDisplay_guess::CleanGameUI
    void CleanGameUI();
    void ShutdownDisplay_guess();
    void MoveLocalPlayerToSafeCoords_guess();
    AcquiredObject_guess* CreateLightInstance_guess(unsigned char type, float distance, int value0, int value1, int value2);
    void SetActorClipPlane_guess(int value);
    void SetShadowClipPlane_guess(int value);
    void SetRenderWindow_guess();
    void Render_MinWorld_guess();
    void ProcessSky_guess();
    void SetPCNameSpriteState_guess(int value);
    void SetNPCNameSpriteState_guess(int value);
    int TurnInfravisionEffectOff_guess();
    void DeleteActor_guess(ViewActor_guess* actor);
    void UpdateSoundEnvironment_guess();
    void UpdateIndoorSoundState_guess();
    unsigned char LoadWorldFile_guess(int value0, int value1, unsigned char value2,
        unsigned char value3, unsigned char value4, unsigned char value5);
    void SetViewActor_guess(ViewActor_guess* actor);
    void SetViewActorByName_guess(const char* name);
    __declspec(noreturn) void StartWorldDisplay_Bailout(const char* message);
    void LoadZone_guess(int zone);
    // EXTERNAL: TITANIUM 0x00438357 CDisplay_guess::BuildPath_guess
    char BuildPath_guess(char* path, const char* suffix);
    // EXTERNAL: TITANIUM 0x004387B8 CDisplay_guess::LoadNpc_guess
    char LoadNpc_guess(char* filePath, char* worldName, char* npcName);
    // EXTERNAL: TITANIUM 0x0043895F CDisplay_guess::HasSecondChr_guess
    bool HasSecondChr_guess(int zone);
    void LoadUserDefinedColors_guess();
    void RestoreCameraMode_guess();
    void ChangeVideoMode_guess();
    void DefaultCameras_guess();
    void InitDisplay_guess();
    void StoreDisplayOptions_guess();
    void ApplyVideoMode_guess();
    void SetCameraMode_guess(int mode);
    void InitNewUI_guess();
    void InitUIManager_guess();
    void InitCharSelectUI_guess();
    void DeactivateMainUI_guess();
    void ActivateMainUI_guess(char refresh);
    void InitGameUI_guess();
    void ReloadUI(int value);
    void SetSunLight_guess();
    // EXTERNAL: TITANIUM 0x00439B36 CDisplay_guess::GetZoneTimeOfDay_guess
    int GetZoneTimeOfDay_guess(int* hour, int* minute);
    void SetAmbientLight_guess(float value);
    // EXTERNAL: TITANIUM 0x00440F51 CDisplay_guess::FUN_00440f51_guess
    void FUN_00440f51_guess(int value);
    void CycleCamera_guess();
    void StopWorldDisplay_guess();
    // EXTERNAL: TITANIUM 0x0043C1D2 CDisplay_guess::DeleteAllEffects_guess
    void DeleteAllEffects_guess();
    // EXTERNAL: TITANIUM 0x0043C1EF CDisplay_guess::DeleteAllHSprites_guess
    void DeleteAllHSprites_guess();
    // EXTERNAL: TITANIUM 0x0043C20C CDisplay_guess::DeleteAllPlayers_guess
    void DeleteAllPlayers_guess();
    // EXTERNAL: TITANIUM 0x0043C229 CDisplay_guess::DeleteAllGroundItems_guess
    void DeleteAllGroundItems_guess();
    // EXTERNAL: TITANIUM 0x0043C246 CDisplay_guess::DeleteAllMoney_guess
    void DeleteAllMoney_guess();
    // EXTERNAL: TITANIUM 0x0043C263 CDisplay_guess::DeleteAllMissiles_guess
    void DeleteAllMissiles_guess();
    // EXTERNAL: TITANIUM 0x0043C280 CDisplay_guess::DeleteAllObjects_guess
    void DeleteAllObjects_guess();
    // EXTERNAL: TITANIUM 0x0043A650 CDisplay_guess::SetLabel_guess
    void SetLabel_guess(const char* value);
    // EXTERNAL: TITANIUM 0x0043A68B CDisplay_guess::SetSecondarySkyName_guess
    void SetSecondarySkyName_guess(const char* value, float amount);
    void SetFogState_guess(int one, float start, float end, int red,
        unsigned char green, unsigned char blue);
    void SetupCharacterViewCamera_guess(int value);
    bool ShouldLoadNewPcModel_guess(int race, int female);
    // EXTERNAL: TITANIUM 0x0043AB98 CDisplay_guess::GetNewPCIniFlag_guess
    int GetNewPCIniFlag_guess(int race, int female);
    void InitWorld_guess();
    void CreatePlayerActor(struct Spawn_0043C84B_guess* player);
};

struct ListenerSink_guess {
    // EXTERNAL: TITANIUM 0x0044AA9C ListenerSink_guess::SetPosition_guess
    void SetPosition_guess(float x, float y, float z);
};

struct ListenerState_guess {
    void* actorInstance_0000_guess;
    unsigned char pad_0004_guess[0x1b4 - 4];
    ListenerSink_guess* sink_01b4_guess;
};

struct Listener_guess {
    unsigned char pad_0000_guess[0x30];
    float y_0030_guess;
    float x_0034_guess;
    float z_0038_guess;
    unsigned char pad_003c_guess[0x1a8 - 0x3c];
    ListenerState_guess* pActorInfo_01a8_guess;
    unsigned char pad_01ac_guess[0x214 - 0x1ac];
    Listener_guess* next_0214_guess;
    unsigned char pad_0218_guess[0x2c];
    unsigned char type_0244_guess;
    unsigned char pad_0245_guess[0x258 - 0x245];
    int spawnId_0258_guess;
    // EXTERNAL: TITANIUM 0x0047CF7C Listener_guess::Update_guess
    void Update_guess(int value);
    // EXTERNAL: TITANIUM 0x0047B8D5 Listener_guess::Visit_guess
    void Visit_guess(unsigned char* value);
};

struct Mapping_guess {
    unsigned char GetIntensity_guess(unsigned char value);
};

struct GraphicsState_guess {
    unsigned char pad_0000_guess[4];
    unsigned char fullscreen_0004_guess;
    unsigned char pad_0005_guess[0x1b];
    int value_0020_guess;
    int value_0024_guess;
    // EXTERNAL: TITANIUM 0x0060A090 GraphicsState_guess::Initialize_guess
    int Initialize_guess(int value);
    // EXTERNAL: TITANIUM 0x00609D50 GraphicsState_guess::GetFirst_guess
    int GetFirst_guess();
    // EXTERNAL: TITANIUM 0x00609D60 GraphicsState_guess::GetSecond_guess
    int GetSecond_guess();
};

struct Target_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Notify_guess(bool enabled, int value);
    // EXTERNAL: TITANIUM 0x0059FD80 Target_guess::FUN_0059fd80_guess
    void FUN_0059fd80_guess(int value);
    // EXTERNAL: TITANIUM 0x00552751 Target_guess::UpdateKeyLabels_guess
    void UpdateKeyLabels_guess();
    // EXTERNAL: TITANIUM 0x004EB5A2 Target_guess::Refresh1_guess
    void Refresh1_guess();
    // EXTERNAL: TITANIUM 0x0050BC7E Target_guess::UpdateButtonHotkeys_guess
    void UpdateButtonHotkeys_guess();
    // EXTERNAL: TITANIUM 0x004D262D Target_guess::UpdateKeyCombos_guess
    void UpdateKeyCombos_guess();
    unsigned char pad_0004_guess[0x58];
    unsigned char state_005c_guess;
};

#define g_queue_guess EQ_GLOBAL(Queue_guess*, 0x00851390)
#define g_target0_guess EQ_GLOBAL(Target_guess*, 0x00850C54)
#define g_target1_guess EQ_GLOBAL(Target_guess*, 0x00991AE4)
#define g_target2_guess EQ_GLOBAL(Target_guess*, 0x00850C2C)
#define g_target3_guess EQ_GLOBAL(Target_guess*, 0x00850C30)
#define g_target4_guess EQ_GLOBAL(Target_guess*, 0x00850C18)
#define g_target5_guess EQ_GLOBAL(Target_guess*, 0x00850C1C)
#define g_target6_guess EQ_GLOBAL(Target_guess*, 0x00850C10)
#define g_target7_guess EQ_GLOBAL(Target_guess*, 0x00850C08)
#define g_target8_guess EQ_GLOBAL(Target_guess*, 0x00991A74)
#define g_target9_guess EQ_GLOBAL(Target_guess**, 0x009917E4)
#define g_target10_guess EQ_GLOBAL(Target_guess*, 0x00850C34)
#define g_target11_guess EQ_GLOBAL(Target_guess*, 0x00850C38)
#define g_target12_guess EQ_GLOBAL(Target_guess*, 0x00850C48)
#define g_target13_guess EQ_GLOBAL(Target_guess*, 0x00850C44)
#define g_target14_guess EQ_GLOBAL(Target_guess*, 0x00850C88)
#define g_target15_guess EQ_GLOBAL(Target_guess*, 0x0099283C)
#define g_target16_guess EQ_GLOBAL(Target_guess*, 0x00991AE8)
#define g_target17_guess EQ_GLOBAL(Target_guess*, 0x00991AEC)
#define g_target18_guess EQ_GLOBAL(Target_guess*, 0x00991AF0)
#define g_stateDispatch_guess EQ_GLOBAL(StateDispatch_guess*, 0x0099E364)
#define g_stateMode_guess EQ_GLOBAL(int, 0x00924824)
#define g_stateFloat_guess EQ_GLOBAL(float, 0x0092482C)
#define g_stateFlag_guess EQ_GLOBAL(StateFlag_guess*, 0x0085098C)
#define g_value2d04_guess EQ_GLOBAL(int, 0x00923778)
#define g_value2d08_guess EQ_GLOBAL(int, 0x0092377C)
#define g_viewRight_guess EQ_GLOBAL(int, 0x00923780)
#define g_viewBottom_guess EQ_GLOBAL(int, 0x00923784)
#define g_vtable00435BBA_guess EQ_GLOBAL(void*, 0x00641F24)
#define g_guard004382E5_guess EQ_GLOBAL(int, 0x009248D0)
#define g_delegate004382E5_guess EQ_GLOBAL(Delegate004382E5_guess*, 0x0099D3EC)
#define g_service_guess EQ_GLOBAL(Service_guess*, 0x0099E368)
#define g_listenerHead_guess EQ_GLOBAL(Listener_guess*, 0x00905CC4)
#define g_dialog_import_guess EQ_GLOBAL(DialogBoxParamA_guess, 0x0063F2B4)
#define g_dialog_value0_guess EQ_GLOBAL(int, 0x0085039C)
#define g_dialog_value1_guess EQ_GLOBAL(int, 0x008503A0)
#define g_byteTable_guess EQ_ARRAY(unsigned char, 0x008503B0)
#define g_particleSystem_guess EQ_GLOBAL(ParticleSystem_guess*, 0x0099E36C)
#define g_graphicsState_guess EQ_GLOBAL(GraphicsState_guess*, 0x0099E38C)
#define g_graphicsValue0_guess EQ_GLOBAL(int, 0x009237A4)
#define g_graphicsValue1_guess EQ_GLOBAL(int, 0x009237A8)
#define g_graphicsValue2_guess EQ_GLOBAL(int, 0x0092379C)
#define g_graphicsValue3_guess EQ_GLOBAL(int, 0x009237A0)
#define g_pathSeparator_guess EQ_ARRAY(char, 0x0064217C)

struct ParticleSystem_guess {
    virtual int LoadEmitterDefinitions_guess();
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
    virtual void SetParameter_guess(float value);
};

// FUNCTION: TITANIUM 0x00439A46
// If it is the view actor, the camera goes back to the player's own actor first.
void CDisplay_guess::DeleteActor_guess(ViewActor_guess* actor) {
    if (actor != 0) {
        lastUpdateTime_0150_guess = 0;
        if (g_currentActor_guess == actor) {
            ActorAssociation_guess* association = g_actorAssociation_guess;
            if (association == 0 || association->node_01a8_guess == 0 ||
                association->node_01a8_guess->actor_0000_guess == g_currentActor_guess) {
                SetViewActor_guess(0);
            } else {
                SetViewActor_guess(association->node_01a8_guess->actor_0000_guess);
            }
        }
        g_actorReceiver_guess->SetActor_guess(actor);
    }
}

// FUNCTION: TITANIUM 0x00439A93
// Spawn type 0 (+0x244) is a PC; SetNPCNameSpriteState takes every other type.
void CDisplay_guess::SetPCNameSpriteState_guess(int value) {
    Listener_guess* listener = g_listenerHead_guess;
    pcNameSprites_2d5d_guess = (unsigned char)value;
    while (listener != 0) {
        if (listener->type_0244_guess == 0) {
            listener->Update_guess(value);
        }
        listener = listener->next_0214_guess;
    }
}

// /shownpcnames and the ini NPC-names option: stores the flag (+0x2D5E) and shows or hides the name tag
// of every spawn that is not a PC (type +0x244 nonzero). PC twin: 0x00439A93.
// FUNCTION: TITANIUM 0x00439AC7
void CDisplay_guess::SetNPCNameSpriteState_guess(int value) {
    Listener_guess* listener = g_listenerHead_guess;
    npcNameSprites_2d5e_guess = (unsigned char)value;
    while (listener != 0) {
        if (listener->type_0244_guess != 0) {
            listener->Update_guess(value);
        }
        listener = listener->next_0214_guess;
    }
}

// Clears the infravision flag (+0x2D58) and passes a black RGB triple to every spawn in the list
// (0x0047B8D5 forwards it to the spawn's actor and, for some models, its slot-7 part).
// FUNCTION: TITANIUM 0x00439AFB
int CDisplay_guess::TurnInfravisionEffectOff_guess() {
    Listener_guess* listener = g_listenerHead_guess;
    value_2d58_guess = 0;
    unsigned char value[3];
    value[2] = 0;
    value[1] = 0;
    value[0] = 0;
    while (listener != 0) {
        listener->Visit_guess(value);
        listener = listener->next_0214_guess;
    }
    return 1;
}

struct ModeState00439B36_guess {
    unsigned char pad_0000_guess[4];
    unsigned char value_0004_guess;
    unsigned char value_0005_guess;
};

#define g_modeCount00439B36_guess EQ_GLOBAL(int, 0x00923C00)
#define g_mode00439B36_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_modeState00439B36_guess EQ_GLOBAL(ModeState00439B36_guess*, 0x00905CC0)
#define g_modeCode00439B36_guess EQ_GLOBAL(int, 0x00924470)

// FUNCTION: TITANIUM 0x00439B36
// @early-stop: budget, structural ndiff=57
// Returns 1 when the hour is fixed, 0 when it follows the world clock (game states 1, 2, 5; else 0:00).
// A fixed hour comes from 0x00923C00 (1-24) or the zone: unrest (0x3F) and hateplane (0x4C) are always
// 6:00, airplane (0x47) 18:00, necropolis (0x7B) 10:00; zone ids per the older client's zone table.
int __stdcall GetZoneTimeOfDay_guess(int* first, int* second) {
    if (g_modeCount00439B36_guess > 0 && g_modeCount00439B36_guess < 0x19) {
        *first = g_modeCount00439B36_guess;
        *second = 0;
        return 1;
    }

    if (g_mode00439B36_guess == 2 || g_mode00439B36_guess == 1 || g_mode00439B36_guess == 5) {
        *first = g_modeState00439B36_guess->value_0004_guess;
        *second = g_modeState00439B36_guess->value_0005_guess;
    } else {
        *first = 0;
        *second = 0;
    }

    int code = g_modeCode00439B36_guess;
    if (code == 0x3f) {
        *first = 6;
    } else if (code == 0x47) {
        *first = 0x12;
    } else if (code == 0x4c) {
        *first = 6;
    } else if (code == 0x7b) {
        *first = 10;
    } else {
        return 0;
    }
    *second = 0;
    return 1;
}

// FUNCTION: TITANIUM 0x00439D89
// Sets the engine's light vector (Slot36) to zero; FUN_00439db8 sets it from the state engine.
void ClearGrassDisplacement_guess() {
    Vector3_guess vector;
    vector.x_0000_guess = 0.0f;
    vector.y_0004_guess = 0.0f;
    vector.z_0008_guess = 0.0f;
    g_service_guess->Slot36_guess(&vector, 0.0f);
}

// FUNCTION: TITANIUM 0x00439DB8
// In state mode 1 only: the engine vector, negated, with strength 0x0092482C.
void UpdateGrassDisplacement_guess() {
    if (g_stateMode_guess == 1) {
        Vector3_guess vector;
        g_stateDispatch_guess->Slot45_guess(&vector);
        vector.x_0000_guess = -vector.x_0000_guess;
        vector.y_0004_guess = -vector.y_0004_guess;
        vector.z_0008_guess = -vector.z_0008_guess;
        g_service_guess->Slot36_guess(&vector, g_stateFloat_guess);
    }
}

// Cheap distance: |dx| + |dy| + |dz| / scale; scale 0 leaves z out, scale 1.0 skips the divide.
// FUNCTION: TITANIUM 0x00439BD1
// @early-stop: budget, diff ndiff=4
float CoordinateService_guess::SimpleDistance_guess(float x0, float y0, float z0,
    float x1, float y1, float z1, float scale) {
    x1 = (float)_fabs((double)(x0 - x1));
    x0 = (float)_fabs((double)(y0 - y1));
    float result = 0.0f;
    if (scale != 0.0f) {
        result = (float)_fabs((double)(z0 - z1));
        if (scale == g_oneFloat_guess) {
            return result + x0 + x1;
        }
        result /= scale;
    }
    return result + x0 + x1;
}

// Straight-line distance: sqrt of dx^2 + dy^2 + (dz / scale)^2, through the math service's square root
// (slot 4); scale 0 ignores height. 0x00439BD1 is the cheaper |dx| + |dy| + |dz| / scale form.
// FUNCTION: TITANIUM 0x00439C41
float CoordinateService_guess::TrueDistance_guess(float x0, float y0, float z0,
    float x1, float y1, float z1, float scale) {
    float dx = x0 - x1;
    float dy = y0 - y1;
    if (scale == 0.0f) {
        return g_floatSink_guess->Apply_guess(dx * dx + dy * dy);
    }
    float dz = (z0 - z1) / scale;
    return g_floatSink_guess->Apply_guess(dx * dx + dy * dy + dz * dz);
}

// SimpleDistance (0x00439BD1) between two spawns' positions (+0x30); a fixed large value if either is null.
// FUNCTION: TITANIUM 0x00439CA3
float CoordinateService_guess::PlayerSimpleDistance_guess(const PositionedObject_guess* first,
    const PositionedObject_guess* second, float scale) {
    if (first == 0 || second == 0) {
        return EQ_GLOBAL(float, 0x00640EA0);
    }
    float z1 = second->position_0030_guess.z_0008_guess;
    float y1 = second->position_0030_guess.y_0004_guess;
    float x1 = second->position_0030_guess.x_0000_guess;
    float z0 = first->position_0030_guess.z_0008_guess;
    float y0 = first->position_0030_guess.y_0004_guess;
    float x0 = first->position_0030_guess.x_0000_guess;
    return SimpleDistance_guess(x0, y0, z0, x1, y1, z1, scale);
}

// FUNCTION: TITANIUM 0x00439D16
// CDisplay::PlayerDistance in the earlier sibling decomp; the class name is a view of CDisplay.
float CoordinateService_guess::PlayerDistance_guess(const PositionedObject_guess* first,
    const PositionedObject_guess* second, float scale) {
    if (first == 0 || second == 0) {
        return EQ_GLOBAL(float, 0x00640EA0);
    }
    float z1 = second->position_0030_guess.z_0008_guess;
    float y1 = second->position_0030_guess.y_0004_guess;
    float x1 = second->position_0030_guess.x_0000_guess;
    float z0 = first->position_0030_guess.z_0008_guess;
    float y0 = first->position_0030_guess.y_0004_guess;
    float x0 = first->position_0030_guess.x_0000_guess;
    return TrueDistance_guess(x0, y0, z0, x1, y1, z1, scale);
}

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestText_guess::trimName_guess
    char* trimName_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00494285 EverQuestText_guess::DoLoadScreen_guess
    void DoLoadScreen_guess(int value);
};

#define g_everQuestText_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)

// FUNCTION: TITANIUM 0x00439E0F
// Chat strings: 0x4FC (not found), 0x4FB (the player itself), 0x4FD (another spawn, by name).
void CDisplay_guess::SetViewActorByName_guess(const char* name) {
    char buf[192];
    ActorAssociation_guess* assoc = GetSpawnByName_guess(name);
    if (assoc == 0) {
        assoc = FindPlayerByPartialDisplayName_guess(name, 0);
    }
    if (assoc == 0 || assoc->node_01a8_guess == 0 || assoc->node_01a8_guess->actor_0000_guess == 0) {
        FUN_0046da4a_guess(buf, 0x4fc, name, 0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        ViewActor_guess* actor = assoc->node_01a8_guess->actor_0000_guess;
        if (g_currentActor_guess == actor) {
            return;
        }
        if (g_currentActor_guess == 0) {
            SetViewActor_guess(actor);
            return;
        }
        SetViewActor_guess(actor);
        char* kind = ((ViewActor_guess*)g_currentActor_guess)->Slot02_guess();
        if (*kind == 3 && kind == (char*)assoc) {
            return;
        }
        if (assoc == g_actorAssociation_guess) {
            strcpy(buf, pStringTable->getString(0x4fb, 0));
        } else {
            FUN_0046da4a_guess(buf, 0x4fd, g_everQuestText_guess->trimName_guess(assoc->text_0120_guess),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
    }
    pEverQuest->dsp_chat(buf, 0xd, 1);
}

// FUNCTION: TITANIUM 0x00439F26
// @early-stop: budget, structural ndiff=15
// Floor below (x, y, z), probing from just above z down to -32767; -1.0e27 means no floor.
// If nothing is hit and 0x00923B88 is set, it retries from the height at 0x00923BD8.
float CoordinateService_guess::GetFloorHeight_guess(float x, float y, float z) {
    int scratch1[3];
    QueryScratch_guess scratch0;
    Vector3_guess firstQuery;
    Vector3_guess secondQuery;
    int scratch2;
    int zero = 0;
    float result = 0.0f;

    if (state_2cf8_guess != zero) {
        firstQuery.x_0000_guess = x;
        firstQuery.z_0008_guess = z + value_2d14_guess + 1.0f;
        firstQuery.y_0004_guess = y;
        if (g_actorReceiver_guess->Slot12_guess(&firstQuery) == 0) {
            return -1.0e27f;
        }

        secondQuery.x_0000_guess = x;
        secondQuery.y_0004_guess = y;
        secondQuery.z_0008_guess = -32767.0f;
        unsigned char previousMode = g_queryService_guess->Save_guess();
        g_queryService_guess->Restore_guess(1);

        int status = g_queryService_guess->Query_guess(&firstQuery, &secondQuery,
            value_2d14_guess, CanCollideWith_guess, LAB_0042ce5d_guess, zero,
            &scratch0, scratch1, &scratch2, zero, 1);
        if (status == 0) {
            if (scratch0.result_guess <= -32767.0f) {
                if (g_queryFallbackEnabled_guess == 0) {
                    status = -1;
                } else {
                    firstQuery.z_0008_guess = g_queryFallbackRadius_guess;
                    secondQuery.x_0000_guess = x;
                    secondQuery.y_0004_guess = y;
                    secondQuery.z_0008_guess = -32767.0f;
                    status = g_queryService_guess->Query_guess(&firstQuery, &secondQuery,
                        value_2d14_guess, CanCollideWith_guess, LAB_0042ce5d_guess, zero,
                        &scratch0, scratch1, &scratch2, zero, 1);
                }
            }
        }

        if (status == 0) {
            result = (scratch0.result_guess - value_2d14_guess) + 0.001f;
            g_queryService_guess->Restore_guess(previousMode);
        } else {
            g_queryService_guess->Restore_guess(previousMode);
            result = -1.0e27f;
        }
    }
    return result;
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message, ...);
// EXTERNAL: TITANIUM 0x004CD060 ReleaseMouse_guess
void __cdecl ReleaseMouse_guess();
typedef int (__stdcall *DestroyWindow_guess)(void* window);
typedef int (__stdcall *MessageBoxA_guess)(void* window, const char* text, const char* caption, unsigned int type);
#define g_destroyWindow_guess EQ_GLOBAL(DestroyWindow_guess, 0x0063F2AC)
#define g_messageBoxA_guess EQ_GLOBAL(MessageBoxA_guess, 0x0063F2F0)
// EXTERNAL: TITANIUM 0x00611848 _exit_guess
void __stdcall _exit_guess(int status);

typedef void* (__stdcall *GetDlgItem_guess)(void* window, int id);
typedef int (__stdcall *SetWindowTextA_guess)(void* window, const char* text);
typedef int (__stdcall *EndDialog_guess)(void* window, int result);
#define g_getDlgItem_guess EQ_GLOBAL(GetDlgItem_guess, 0x0063F2B8)
#define g_setWindowTextA_guess EQ_GLOBAL(SetWindowTextA_guess, 0x0063F2BC)
#define g_endDialog_guess EQ_GLOBAL(EndDialog_guess, 0x0063F2C0)

// FUNCTION: TITANIUM 0x00435995
// WM_INITDIALOG (0x110) fills the two text controls, falling back to strings 0x61C/0x61D; IDOK closes.
int __cdecl DialogProc_guess(HWND window, unsigned int message, short wparam) {
    if (message == 0x110) {
        const char* text = (const char*)g_dialog_value0_guess;
        if (text != 0) {
            SetWindowTextA(GetDlgItem(window, 0x3ec), text);
        } else {
            SetWindowTextA(GetDlgItem(window, 0x3ec), pStringTable->getString(0x61c, 0));
        }
        text = (const char*)g_dialog_value1_guess;
        if (text != 0) {
            SetWindowTextA(GetDlgItem(window, 0x3eb), text);
        } else {
            SetWindowTextA(GetDlgItem(window, 0x3eb), pStringTable->getString(0x61d, 0));
        }
        return 1;
    }
    if (message == 0x111 && wparam == 1) {
        EndDialog(window, 1);
        return 1;
    }
    return 0;
}

// FUNCTION: TITANIUM 0x00435A2A
// Modal error box from dialog resource 0x6C with two optional texts.
void __cdecl ShowErrorDialog_guess(void* instance, void* parent, int value0, int value1) {
    g_dialog_value0_guess = value0;
    g_dialog_value1_guess = value1;
    g_dialog_import_guess(instance, (const char*)0x6c, parent, DialogProc_guess, 0);
}

// Assignment: the byte at +0, the dword at +4, the shared field at +8 and the dwords +0xC..+0x14.
// FUNCTION: TITANIUM 0x00435A54
DialogObject_guess* DialogObject_guess::CopyFrom_guess(const DialogObject_guess* source) {
    value_0000_guess = source->value_0000_guess;
    value_0004_guess = source->value_0004_guess;
    value_0008_guess.Assign_guess(&source->value_0008_guess);
    value_000c_guess = source->value_000c_guess;
    value_0010_guess = source->value_0010_guess;
    value_0014_guess = source->value_0014_guess;
    return this;
}

// Restores the base vtable (0x00641F24).
// FUNCTION: TITANIUM 0x00435BBA
void __fastcall InitVtable00435BBA_guess(Vtable00435BBA_guess* object) {
    object->vtable_0000_guess = &g_vtable00435BBA_guess;
}

// Scalar deleting destructor of the menu item base (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00435BC1
OwnerBase00435BDE_guess* OwnerBase00435BDE_guess::Destroy_guess(unsigned char should_free) {
    this->~OwnerBase00435BDE_guess();
    if ((should_free & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

// Sets a menu item's text (+0x10) and marks it enabled (+8 = 1).
// FUNCTION: TITANIUM 0x00435BDE
void Owner00435BDE_guess::SetText_guess(const char* value) {
    text_0010_guess.Assign_guess(value);
    state_0008_guess = 1;
}

// Empty menu item destructor; the text member releases itself.
// FUNCTION: TITANIUM 0x00435BF5
Owner00435BDE_guess::~Owner00435BDE_guess() {
}

// FUNCTION: TITANIUM 0x00435C25
// Races 1-12 plus Iksar (0x80), Vah Shir (0x82) and Froglok (0x14A), male and female tags each.
void __cdecl ForEachPlayableRaceTag_guess(KeyCallback_guess callback) {
    char buffer[8];
    int key = 1;
    do {
        GetRaceModelTag_guess(buffer, key, 0);
        callback(buffer);
        GetRaceModelTag_guess(buffer, key, 1);
        callback(buffer);
        ++key;
    } while (key <= 12);
    GetRaceModelTag_guess(buffer, 0x80, 0);
    callback(buffer);
    GetRaceModelTag_guess(buffer, 0x80, 1);
    callback(buffer);
    GetRaceModelTag_guess(buffer, 0x82, 0);
    callback(buffer);
    GetRaceModelTag_guess(buffer, 0x82, 1);
    callback(buffer);
    GetRaceModelTag_guess(buffer, 0x14a, 0);
    callback(buffer);
    GetRaceModelTag_guess(buffer, 0x14a, 1);
    callback(buffer);
}

// FUNCTION: TITANIUM 0x00435CF3
// Every other race id below 0x1DB, in the three gender variants; tags longer than 3 letters are skipped.
void __cdecl ForEachNonPlayableRaceTag_guess(KeyCallback_guess callback) {
    char buffer[8];
    for (int key = 0xd; key < 0x1db; ++key) {
        if (key != 0x80 && key != 0x82 && key != 0x14a) {
            strcpy(buffer, "AAAA");
            GetRaceModelTag_guess(buffer, key, 0);
            if (buffer[3] == 0) {
                callback(buffer);
            }
            strcpy(buffer, "AAAA");
            GetRaceModelTag_guess(buffer, key, 2);
            if (buffer[3] == 0) {
                callback(buffer);
            }
            strcpy(buffer, "AAAA");
            GetRaceModelTag_guess(buffer, key, 1);
            if (buffer[3] == 0) {
                callback(buffer);
            }
        }
    }
}

struct GameState_guess {
    unsigned char pad_0000_guess[0x15];
    char text_0015_guess[0x100];
};

#define g_gameState_guess EQ_GLOBAL(GameState_guess*, 0x00905D24)

// FUNCTION: TITANIUM 0x00435DB5
// Region name (world file) to region flags. Low byte, the liquid type: DR 0, WT 5, SL 6, LA 7, VW 8, W2 9,
// W3 10 (A-prefixed names too). 0x40000000 probably PvP, 0x80000000 teleport (target to CDisplay+0x15).
// Names over 32 characters carry more flags at offsets 0x1F-0x21.
unsigned int __cdecl ParseRegionName_guess(char* value, unsigned int flags) {
    if (value == 0 || strlen(value) < 4) {
        return flags;
    }
    if (value[0] == 'A') {
        if (strncmp(value, "AWT", 3) == 0) {
            flags = (flags & 0xffffff05) | 5;
        } else if (strncmp(value, "ALV", 3) == 0) {
            flags = (flags & 0xffffff07) | 7;
        } else if (strncmp(value, "AVW", 3) == 0) {
            flags = (flags & 0xffffff08) | 8;
        } else if (strncmp(value, "APK", 3) == 0) {
            flags |= 0x40000000;
        } else if (strncmp(value, "ATP", 3) == 0) {
            flags |= 0x80000000;
            sprintf(g_gameState_guess->text_0015_guess, "DRNTP00255%05d000000000000000", atol(value + 4));
        } else if (strncmp(value, "ASL", 3) == 0) {
            flags |= 0x10000000;
        }
    } else {
        if (strncmp(value, "DR", 2) == 0) {
            flags &= 0xffffff00;
        } else if (strncmp(value, "WT", 2) == 0) {
            flags = (flags & 0xffffff05) | 5;
        } else if (strncmp(value, "LA", 2) == 0) {
            flags = (flags & 0xffffff07) | 7;
        } else if (strncmp(value, "SL", 2) == 0) {
            flags = (flags & 0xffffff06) | 6;
        } else if (strncmp(value, "VW", 2) == 0) {
            flags = (flags & 0xffffff08) | 8;
        } else if (strncmp(value, "W2", 2) == 0) {
            flags = (flags & 0xffffff09) | 9;
        } else if (strncmp(value, "W3", 2) == 0) {
            flags = (flags & 0xffffff0a) | 10;
        }
        if (value[2] == 'P') {
            flags |= 0x40000000;
        }
        if (value[3] == 'T' && value[4] == 'P') {
            flags |= 0x80000000;
            strcpy(g_gameState_guess->text_0015_guess, value);
        }
        if (strlen(value) > 0x20) {
            if (value[0x1f] == 'M') {
                flags |= 0x20000000;
            }
            if (value[0x20] == 'S') {
                flags |= 0x10000000;
            }
            if (value[0x21] == 'P') {
                flags |= 0x8000000;
            } else if (value[0x21] == 'F') {
                flags |= 0x4000000;
            }
        }
    }
    return flags;
}

struct ActorInfo436039_guess {
    unsigned char pad_0000_guess[0x158];
    void* value_0158_guess;
    unsigned char pad_015c_guess[0xebc - 0x15c];
    int lastUpdateTime_0ebc_guess;
};

struct Player_436039_guess {
    // EXTERNAL: TITANIUM 0x0048BA76 Player_436039_guess::MovePlayer_guess
    int MovePlayer_guess();
    // EXTERNAL: TITANIUM 0x0047E43E Player_436039_guess::PlayIdleFidget_guess
    void PlayIdleFidget_guess();
    // EXTERNAL: TITANIUM 0x00480409 Player_436039_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
};

struct AssociationAction_guess {
    // EXTERNAL: TITANIUM 0x0056FFA8 AssociationAction_guess::FUN_0056ffa8_guess
    void FUN_0056ffa8_guess();
};

// EXTERNAL: TITANIUM 0x004798B7 FindSpawnByActor_guess
int __cdecl FindSpawnByActor_guess(int value);

#define g_playerOwner_436039_guess EQ_GLOBAL(EQPlayer*, 0x00905CF8)
#define g_localPlayer_436039_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_clock_436039_guess EQ_GLOBAL(CDisplay_guess*, 0x00905D24)
#define g_statusFlag_436039_guess EQ_GLOBAL(int, 0x00923884)

// EXTERNAL: TITANIUM 0x004BFE0F FUN_004bfe0f_guess
void __cdecl FUN_004bfe0f_guess(EQPlayer* player, int zero1, int zero2);

// FUNCTION: TITANIUM 0x00436039
// @early-stop: budget, structural ndiff=18
// Moves a spawn other than the player, its mount and the controlled pet. A spawn idle for 12 s that has
// stopped moving is skipped. Returns false only for those three.
bool __cdecl ProcessPlayerPhysics_guess(EQPlayer* player, int value_guess) {
    if (player == g_playerOwner_436039_guess || player == g_localPlayer_436039_guess ||
        player == ((ActorInfo436039_guess*)g_playerOwner_436039_guess->pActorInfo)->value_0158_guess) {
        return false;
    }
    if ((unsigned int)(g_clock_436039_guess->frameTime_0148_guess -
            ((ActorInfo436039_guess*)player->pActorInfo)->lastUpdateTime_0ebc_guess) > 12000) {
        if (player->Type >= 1 && player->SpeedRun == 0.0f) {
            if (player->SpeedZ == 0.0f) {
                return true;
            }
        } else if (g_statusFlag_436039_guess == 0) {
            return true;
        }
    }
    FUN_004bfe0f_guess(player, 0, 0);
    ((Player_436039_guess*)player)->MovePlayer_guess();
    return true;
}

// FUNCTION: TITANIUM 0x004360D6
// Actor clip distance is (value * 5 + 25) * 2, capped at the camera's far plane.
void CDisplay_guess::SetActorClipPlane_guess(int value) {
    actorClipPlane_2d68_guess = value;
    if (callback_0118_guess != 0) {
        float current = callback_0118_guess->Slot04_guess();
        float limit = (float)((value * 5 + 0x19) * 2);
        if (limit > current) {
            limit = current;
        }
        callback_0118_guess->Slot05_guess(limit);
    }
}

// FUNCTION: TITANIUM 0x00436129
// Shadow clip distance is value * 5 + 10.
void CDisplay_guess::SetShadowClipPlane_guess(int value) {
    shadowClipPlane_2d6c_guess = value;
    if (callback_0118_guess != 0) {
        callback_0118_guess->Slot06_guess((float)(value * 5 + 10));
    }
}

// FUNCTION: TITANIUM 0x00436156
// The seven SetState2d* setters are the eqclient.ini render toggles (tu_100 names them): this one is
// Shadows (engine state 1). The 5,x pairs below are on/off codes for one engine state.
void CDisplay_guess::SetState2d60_guess(char value) {
    int enabled = value != 0;
    state_2d60_guess = value;
    g_stateDispatch_guess->Notify_guess(1, enabled);
}

// FUNCTION: TITANIUM 0x0043617D
// MultipassLighting (engine state 3).
void CDisplay_guess::SetState2d5f_guess(char value) {
    int enabled = value != 0;
    state_2d5f_guess = value;
    g_stateDispatch_guess->Notify_guess(3, enabled);
}

// FUNCTION: TITANIUM 0x004361A4
// WaterSwap (engine state 2).
void CDisplay_guess::SetState2d61_guess(char value) {
    int enabled = value != 0;
    state_2d61_guess = value;
    g_stateDispatch_guess->Notify_guess(2, enabled);
}

// FUNCTION: TITANIUM 0x004361CB
// 20PixelShaders (codes 2/3).
void CDisplay_guess::SetState2d62_guess(char value) {
    state_2d62_guess = value;
    if (value != 0) {
        g_stateDispatch_guess->Notify_guess(5, 2);
    } else {
        g_stateDispatch_guess->Notify_guess(5, 3);
    }
}

// FUNCTION: TITANIUM 0x004361F2
// 1xPixelShaders (codes 6/7).
void CDisplay_guess::SetState2d64_guess(char value) {
    state_2d64_guess = value;
    if (value != 0) {
        g_stateDispatch_guess->Notify_guess(5, 6);
    } else {
        g_stateDispatch_guess->Notify_guess(5, 7);
    }
}

// FUNCTION: TITANIUM 0x00436219
// 14PixelShaders (codes 4/5).
void CDisplay_guess::SetState2d63_guess(char value) {
    state_2d63_guess = value;
    if (value != 0) {
        g_stateDispatch_guess->Notify_guess(5, 4);
    } else {
        g_stateDispatch_guess->Notify_guess(5, 5);
    }
}

// FUNCTION: TITANIUM 0x00436240
// VertexShaders (codes 8/9).
void CDisplay_guess::SetState2d65_guess(char value) {
    state_2d65_guess = value;
    if (value != 0) {
        g_stateDispatch_guess->Notify_guess(5, 8);
    } else {
        g_stateDispatch_guess->Notify_guess(5, 9);
    }
}

// FUNCTION: TITANIUM 0x00436267
// Copies the client rectangle (0x00923778..0x00923784) to the camera.
void CDisplay_guess::SetRenderWindow_guess() {
    viewLeft_2d04_guess = g_value2d04_guess;
    viewTop_2d08_guess = g_value2d08_guess;
    viewRight_2d0c_guess = g_viewRight_guess;
    viewBottom_2d10_guess = g_viewBottom_guess;
    if (callback_0118_guess != 0) {
        callback_0118_guess->Slot09_guess(&viewLeft_2d04_guess);
    }
}

struct LanguageService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess(char* name, ActorDef_guess** out);
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
    virtual void Slot30_guess(int language, int value, char* buffer);
    virtual const char* Slot31_guess(int language, int zero);
    void SetLanguage_guess(int language);
};

struct LanguageOutput_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess(int value);
    virtual void Slot39_guess(int value);
};

struct StringTable_guess {
    unsigned char pad_0000_guess[0xb54];
    int mode_0b54_guess;
    // EXTERNAL: TITANIUM 0x004971AD StringTable_guess::LoadStringTables_guess
    void LoadStringTables_guess();
};

#define g_languageService_guess EQ_GLOBAL(LanguageService_guess*, 0x0099E360)
#define g_languageOutput_guess EQ_GLOBAL(LanguageOutput_guess*, 0x0099E364)
#define g_languageNames_guess EQ_ARRAY(const char*, 0x007997F4)
#define g_language_guess EQ_GLOBAL(int, 0x00923D74)
#define g_stringTable_guess EQ_GLOBAL(StringTable_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x006112D3 _setlocale
extern "C" char* __cdecl _setlocale(int category, const char* locale);

// FUNCTION: TITANIUM 0x004362AA
// Sets LC_CTYPE (category 2) and the text renderer's mode for the language, then reloads the string tables.
void LanguageService_guess::SetLanguage_guess(int language) {
    g_languageService_guess->Slot27_guess();
    _setlocale(2, g_languageNames_guess[language]);
    if (language == 0) {
        g_languageOutput_guess->Slot38_guess(0);
        g_languageOutput_guess->Slot39_guess(0);
    } else if (language == 1) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(1);
    } else if (language == 5) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(language);
    } else if (language == 4) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(language);
    } else if (language == 6) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(language);
    } else if (language == 3) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(language);
    } else if (language == 2) {
        g_languageOutput_guess->Slot38_guess(1);
        g_languageOutput_guess->Slot39_guess(language);
    }
    g_language_guess = language;
    g_stringTable_guess->LoadStringTables_guess();
}

// FUNCTION: TITANIUM 0x004363A0
// Calls one UI window, picked by index 0-18 from its global, with `value` (index 15 is ignored).
// tu_042's packet dispatcher calls it; which window property is set is unknown.
void __stdcall FUN_004363a0_guess(int selection, int value) {
    Target_guess* target;
    switch (selection) {
    case 0: target = g_target0_guess; break;
    case 1: target = g_target1_guess; break;
    case 16: target = g_target16_guess; break;
    case 17: target = g_target17_guess; break;
    case 18: target = g_target18_guess; break;
    case 2: target = g_target2_guess; break;
    case 3: target = g_target3_guess; break;
    case 4: target = g_target4_guess; break;
    case 5: target = g_target5_guess; break;
    case 6: target = g_target6_guess; break;
    case 7: target = g_target7_guess; break;
    case 8: target = g_target8_guess; break;
    case 9: target = *g_target9_guess; break;
    case 10: target = g_target10_guess; break;
    case 11: target = g_target11_guess; break;
    case 12: target = g_target12_guess; break;
    case 13: target = g_target13_guess; break;
    case 14: target = g_target14_guess; break;
    case 15: return;
    default: return;
    }

    if (target != 0) {
        target->Slot33_guess();
        target->FUN_0059fd80_guess(value);
    }
}

// FUNCTION: TITANIUM 0x004364B0
// Shows (mode 0), hides (1) or toggles (2) a UI window picked by index, as FUN_004363a0 picks it.
void __stdcall Apply_guess(int selection, int mode) {
    Target_guess* target;
    switch (selection) {
    case 0: target = g_target0_guess; break;
    case 1: target = g_target1_guess; break;
    case 16: target = g_target16_guess; break;
    case 17: target = g_target17_guess; break;
    case 18: target = g_target18_guess; break;
    case 2: target = g_target2_guess; break;
    case 3: target = g_target3_guess; break;
    case 4: target = g_target4_guess; break;
    case 5: target = g_target5_guess; break;
    case 6: target = g_target6_guess; break;
    case 7: target = g_target7_guess; break;
    case 8: target = g_target8_guess; break;
    case 9: target = *g_target9_guess; break;
    case 10: target = g_target10_guess; break;
    case 11: target = g_target11_guess; break;
    case 12: target = g_target12_guess; break;
    case 13: target = g_target13_guess; break;
    case 14: target = g_target14_guess; break;
    case 15: target = g_target15_guess; break;
    default: return;
    }

    if (target != 0) {
        switch (mode) {
        case 0:
            target->Notify_guess(true, 1);
            break;
        case 1:
            target->Notify_guess(false, 1);
            break;
        case 2:
            target->Notify_guess(target->state_005c_guess == 0, 1);
            break;
        }
    }
}

// FUNCTION: TITANIUM 0x004382E5
// Runs the UI manager's hook unless 0x009248D0 blocks it.
unsigned char __cdecl FUN_004382E5_guess() {
    if (g_guard004382E5_guess != 0) {
        return 0;
    }
    return g_delegate004382E5_guess->Invoke_guess();
}

// FUNCTION: TITANIUM 0x004382FC
// Refreshes four windows; windows 2 and 8 twice. The repeat is original.
void __cdecl RefreshHotkeyWindows_guess() {
    if (g_target0_guess != 0) {
        g_target0_guess->UpdateKeyLabels_guess();
    }
    if (g_target2_guess != 0) {
        g_target2_guess->Refresh1_guess();
    }
    if (g_target8_guess != 0) {
        g_target8_guess->UpdateButtonHotkeys_guess();
    }
    if (g_target13_guess != 0) {
        g_target13_guess->UpdateKeyCombos_guess();
    }
    if (g_target2_guess != 0) {
        g_target2_guess->Refresh1_guess();
    }
    if (g_target8_guess != 0) {
        return g_target8_guess->UpdateButtonHotkeys_guess();
    }
}

// FUNCTION: TITANIUM 0x00438357
// The class's BuildPath_guess: current directory + "\" + file name.
char __stdcall GetWorldFilePath(char* path, const char* suffix) {
    if ((path != 0) && (suffix != 0)) {
        if (GetCurrentDirectory_guess(GetDrive_guess(), path, 0x200) != 0) {
            size_t length = strlen(path);
            if (path[length - 1] != '\\') {
                AppendString_guess(path, g_pathSeparator_guess);
            }
            AppendString_guess(path, suffix);
            return 1;
        }
    }
    return 0;
}

struct NpcFileLoader_guess {
    int result_0000_guess;
    // EXTERNAL: TITANIUM 0x00438357 NpcFileLoader_guess::BuildPath_guess
    char BuildPath_guess(char* path, const char* suffix);
    char LoadNpc_guess(char* filePath, char* worldName, char* npcName);
};

struct WorldFileSystem_guess {
    virtual void* GetWorld_guess(const char* path);
    virtual void ReleaseWorld_guess(void* world);
};

struct NpcFileSystem_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual int ReadNpc_guess(char* name, void* world, int zero, char* type);
};

#define g_worldFileSystem_guess EQ_GLOBAL(WorldFileSystem_guess*, 0x0099E35C)
#define g_npcFileSystem_guess EQ_GLOBAL(NpcFileSystem_guess*, 0x0099E360)

struct WorldLoadRequest_guess {
    char* worldName_0000_guess;
    char* fileName_0004_guess;
    unsigned char mode_0008_guess;
    unsigned char defaultWorld_0009_guess;
    unsigned char arg_000a_guess;
    unsigned char arg_000b_guess;
    unsigned char loaded_000c_guess;
    unsigned char complete_000d_guess;
};

struct NpcWorldReader_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual int ReadWorld_guess(char* fileName, void* world, unsigned char mode, unsigned char arg, unsigned char finalArg);
};

#define g_npcFileLoader_guess EQ_GLOBAL(NpcFileLoader_guess*, 0x00905D24)
#define g_npcWorldReader_guess EQ_GLOBAL(NpcWorldReader_guess*, 0x0099E360)

// FUNCTION: TITANIUM 0x004383B0
// @early-stop: budget, structural ndiff=68
// Opens <world>.s3d and reads <file>.wld from it. arena2/erudsxing2 load as arena/erudsxing. A missing
// optional archive (_chr, _lit, _amr ...) fails quietly; with defaultWorld set the client falls back to
// qeynos. After a read error it creates an empty <world>.chk file (a marker; its reader is not known).
void __cdecl LoadWorldFileRequest_guess(WorldLoadRequest_guess* request) {
    char* fileName = request->fileName_0004_guess;
    unsigned char mode = request->mode_0008_guess;
    unsigned char finalArg = request->arg_000b_guess;
    char defaultWorld = request->defaultWorld_0009_guess;
    char* worldName = request->worldName_0000_guess;
    unsigned char arg = request->arg_000a_guess;
    void* world;
    char checkPath[512];
    char fullPath[512];

    char* match = strstr(worldName, "arena2");
    int prefixLength = 6;
    if (match == 0) {
        match = strstr(worldName, "erudsxing2");
        prefixLength = 10;
    }
    if (match != 0) {
        strcpy(match + prefixLength - 1, match + prefixLength);
    }

    if (_strnicmp(fileName, "arena2", 6) == 0) {
        sprintf(fileName, "arena%s", fileName + 6);
    } else if (_strnicmp(fileName, "erudsxing2", 10) == 0) {
        sprintf(fileName, "erudsxing%s", fileName + 10);
    }

    FUN_00574110_guess("Loading %s", fileName);
    AppendString_guess(worldName, ".s3d");
    AppendString_guess(fileName, ".wld");
    if (!g_npcFileLoader_guess->BuildPath_guess(fullPath, worldName)) {
        FUN_00574110_guess("Error: unable to get full path for [%s].\n", worldName);
    }

    world = g_worldFileSystem_guess->GetWorld_guess(fullPath);
    if (world == 0) {
        if (_strnicmp(worldName, "load_chr", 8) != 0
            && _strnicmp(worldName, "global2_chr", 11) != 0
            && _strnicmp(worldName, "global3_chr", 11) != 0
            && _strnicmp(worldName, "global4_chr", 11) != 0
            && strstr(worldName, "_lit") == 0
            && strstr(worldName, "_amr") == 0
            && strstr(worldName, "_chr2") == 0
            && strstr(worldName, "_obj2") == 0) {
            FUN_00574110_guess("Failed to open %s.\n", fullPath);
        }
        if (defaultWorld != 0) {
            FUN_00574110_guess("Defaulting to qeynos.\n");
            strcpy(worldName, "qeynos.s3d");
            if (strcmp(fileName, "objects.wld") != 0 && strcmp(fileName, "lights.wld") != 0) {
                strcpy(fileName, "qeynos.wld");
            }
            g_npcFileLoader_guess->BuildPath_guess(fullPath, worldName);
            world = g_worldFileSystem_guess->GetWorld_guess(fullPath);
            if (world == 0) {
                FUN_00574110_guess("Failed to open the world (S3D) file %s.\n", fullPath);
                g_npcFileLoader_guess->result_0000_guess = 1;
            }
        }
    }

    if (world == 0) {
        request->loaded_000c_guess = 0;
    } else {
        g_npcFileLoader_guess->result_0000_guess = g_npcWorldReader_guess->ReadWorld_guess(fileName, world, mode, arg, finalArg);
        if (g_npcFileLoader_guess->result_0000_guess != 0) {
            if (_strnicmp(worldName, "load_chr", 8) != 0
                && _strnicmp(worldName, "global2_chr", 11) != 0
                && _strnicmp(worldName, "global3_chr", 11) != 0
                && _strnicmp(worldName, "global4_chr", 11) != 0
                && _strnicmp(worldName, "gequip2", 7) != 0
                && strstr(worldName, "_lit") == 0
                && strstr(worldName, "_amr") == 0) {
                FUN_00574110_guess("%s was not there (error %d).\n", fileName, g_npcFileLoader_guess->result_0000_guess);
                size_t fileLength = strlen(fileName);
                if (fileLength == strlen(worldName)) {
                    strcpy(checkPath, worldName);
                    _strrev(checkPath);
                    checkPath[0] = 'k';
                    checkPath[1] = 'h';
                    checkPath[2] = 'c';
                    _strrev(checkPath);
                    void* file = fopen(checkPath, "w");
                    if (file != 0) {
                        fclose(file);
                    }
                }
            }
            request->loaded_000c_guess = 0;
        }
        if (world != 0) {
            g_worldFileSystem_guess->ReleaseWorld_guess(world);
        }
        if (request->loaded_000c_guess == 0) {
            FUN_00574110_guess("ERROR: Load failure!", 0);
        }
        Sleep(1);
    }
    request->complete_000d_guess = 1;
}

// FUNCTION: TITANIUM 0x004387B8
// Like LoadWorldFileRequest_guess for one NPC model; the .chk marker is written on failure here too.
char NpcFileLoader_guess::LoadNpc_guess(char* filePath, char* worldName, char* npcName) {
    unsigned char success = 1;
    char savedPath[512];
    char fullPath[512];
    char checkPath[256];

    FUN_00574110_guess("Load NPC point 1 (%s, %s)\n", worldName, npcName);
    strcpy(savedPath, filePath);
    AppendString_guess(filePath, ".s3d");
    AppendString_guess(worldName, ".wld");
    if (!BuildPath_guess(fullPath, filePath)) {
        FUN_00574110_guess("Error: unable to get full path for [%s].\n", filePath);
    }
    FUN_00574110_guess("Load world point 3 (%s)\n", fullPath);

    void* world = g_worldFileSystem_guess->GetWorld_guess(fullPath);
    if (world == 0) {
        return 0;
    }

    FUN_00574110_guess("Load NPC point 5 (%x, %s, %s).\n", world, worldName, npcName);
    int readResult = g_npcFileSystem_guess->ReadNpc_guess(worldName, world, 0, npcName);
    result_0000_guess = readResult;
    if (readResult != 0) {
        FUN_00574110_guess("%s was not there (error %d).\n", worldName, readResult);
        sprintf(checkPath, "%s.chk", savedPath);
        void* file = fopen(checkPath, "w");
        if (file != 0) {
            fclose(file);
        }
        success = 0;
    } else {
        FUN_00574110_guess("Successful read of NPC.\n");
    }
    g_worldFileSystem_guess->ReleaseWorld_guess(world);
    FUN_00574110_guess("Load NPC end (%d).\n", success);
    return success;
}

struct BmpWad_guess {
    char LoadBMPFile_guess();
    // EXTERNAL: TITANIUM 0x00438357 BmpWad_guess::BuildPath_guess
    char BuildPath_guess(char* path, const char* suffix);
};

// FUNCTION: TITANIUM 0x00438916
// Builds the path of bmpwad8.s3d and returns 1 without loading anything.
char BmpWad_guess::LoadBMPFile_guess() {
    char name[256];
    char path[256];
    strcpy(name, "bmpwad8.s3d");
    BuildPath_guess(path, name);
    return 1;
}

// FUNCTION: TITANIUM 0x0043895F
// Really CDisplay::HasSecondChr_guess(zone) (the EXTERNAL at 0x0043895F): zones that ship a <zone>2_chr
// archive, which LoadZone then loads.
int KeyPredicate_guess::Test_guess(int key) {
    if ((key == 0x25) || (key == 0x44) || (key == 0x60) ||
        (key == 0x22) || (key == 0x81) || (key == 0x7e) ||
        (key == 0x7f) || (key == 0x7b) || (key == 0x72) ||
        (key == 0x80)) {
        return 1;
    }
    return 0;
}

struct ParameterOwner_guess {
    void SetPCloudDensity_guess(int mode);
};

// FUNCTION: TITANIUM 0x004389FB
// Particle density from the options: off, 33%, 66%, full.
void ParameterOwner_guess::SetPCloudDensity_guess(int mode) {
    float value = 1.0f;
    switch (mode) {
    case 0:
        value = 0.0f;
        break;
    case 1:
        value = 0.33f;
        break;
    case 2:
        value = 0.66f;
        break;
    case 3:
        value = 1.0f;
        break;
    }
    g_particleSystem_guess->SetParameter_guess(value);
}

// FUNCTION: TITANIUM 0x00438AF2
// Groups item model numbers (IT<n>, inferred from IsShieldModel's ranges): 2 for most listed ones, 4 for 4,
// 5 for 0x3D and 0x2A1A, 3 for 200-300 (the shields), 0 below 1, else 1. The groups' meanings are not known.
int __stdcall GetItemTypeCategory_guess(int value) {
    int result = 1;
    if (value <= 0x23) {
        if (value >= 0x22) {
            return 2;
        }
        switch (value) {
        case 4:
            return 4;
        case 1:
        case 2:
        case 3:
        case 5:
        case 7:
        case 9:
        case 0x10:
        case 0x11:
        case 0x13:
        case 0x14:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1e:
            return 2;
        }
    } else {
        if (value <= 0x3c) {
            if (value >= 0x39) {
                return 2;
            }
            if (value == 0x25) {
                return 2;
            }
            if (value > 0x26) {
                if (value <= 0x2c) {
                    return 2;
                }
                if (value > 0x31) {
                    if (value <= 0x33) {
                        return 2;
                    }
                    if (value == 0x35) {
                        return 2;
                    }
                }
            }
        } else {
            switch (value) {
            case 0x3d:
            case 0x2a1a:
                return 5;
            case 0x3e:
                return 2;
            }
        }
    }
    if (value < result) {
        result = 0;
    } else if (value >= 200 && value <= 300) {
        result = 3;
    }
    return result;
}

// Model ids that attach at the shield point: 0x0048083A puts these in slot 5 when worn in the secondary
// slot.
// FUNCTION: TITANIUM 0x00438A42
int __stdcall IsShieldModel_guess(int value) {
    if (((value >= 200) && (value <= 0xe4)) ||
        ((value >= 0x2af9) && (value <= 0x2b0c)) ||
        ((value >= 0x2922) && (value <= 0x2930)) ||
        ((value >= 0x29a8) && (value <= 0x29af)) ||
        (value == 0x29c3) || (value == 0x29e9) || (value == 0x29ea) ||
        (value == 0x10727) || (value == 0x29f2) || (value == 0x2a02) ||
        (value == 0x2a14) || (value == 0x2a17) || (value == 0x2a1d) ||
        (value == 0x2a26) || (value == 0x2a4a) || (value == 0x2a4b) ||
        (value == 0x2a50) || (value == 0x2a51)) {
        return 1;
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004389A3
// @early-stop: budget, structural ndiff=168
// Fatal: closes the engine and the window, shows the message and exits with -43.
void CDisplay_guess::StartWorldDisplay_Bailout(const char* message) {
    FUN_00574110_guess("StartWorldDisplay() is bailing out: %s.\n", message);
    g_stateDispatch_guess->Slot20_guess();
    g_service_guess->Slot47_guess();
    ReleaseMouse_guess();
    DestroyWindow((HWND)window_28e4_guess);
    MessageBoxA(0, message, "Unable to load World", 0);
    exit(-0x2b);
}

// FUNCTION: TITANIUM 0x00438BA7
// The 86 user chat colours (0-0x55) as 0x00BBGGRR; a bad index reads colour 0.
unsigned int __cdecl GetUserDefinedColor(int index) {
    if ((index > 0x55) || (index < 0)) {
        index = 0;
    }
    int offset = index * 4;
    return g_byteTable_guess[offset] |
        ((unsigned int)g_byteTable_guess[offset + 1] << 8) |
        ((unsigned int)g_byteTable_guess[offset + 2] << 16);
}

#define g_textColorTable_guess EQ_ARRAY(unsigned char, 0x00698848)

// FUNCTION: TITANIUM 0x00438BD4
// Returns the built-in colour and writes it back to eqclient.ini [TextColors] User_<n>_Red/Green/Blue.
void __cdecl GetDefaultUserDefinedColor_guess(int index, int* red, int* green, int* blue) {
    char name[16];
    char key[32];
    char value[16];

    if (index > 0x55 || index < 0) {
        index = 0;
    }
    *red = g_textColorTable_guess[index * 4];
    *green = g_textColorTable_guess[index * 4 + 1];
    *blue = g_textColorTable_guess[index * 4 + 2];
    sprintf(name, "User_%d_", index + 1);
    strcpy(key, name);
    AppendString_guess(key, "Red");
    sprintf(value, "%d", *red);
    FUN_0060beb0_guess("TextColors", key, value, ".\\eqclient.ini");
    strcpy(key, name);
    AppendString_guess(key, "Green");
    sprintf(value, "%d", *green);
    FUN_0060beb0_guess("TextColors", key, value, ".\\eqclient.ini");
    strcpy(key, name);
    AppendString_guess(key, "Blue");
    sprintf(value, "%d", *blue);
    FUN_0060beb0_guess("TextColors", key, value, ".\\eqclient.ini");
}

// Sets user-defined chat colour `index` (0-0x55) to the given three bytes; out-of-range indexes are
// ignored. The options window and the colour command use it.
// FUNCTION: TITANIUM 0x00438CF7
void __cdecl SetUserDefinedColor_guess(int index, unsigned char value0, unsigned char value1, unsigned char value2) {
    if (index <= 0x55 && index >= 0) {
        int offset = index * 4;
        g_byteTable_guess[offset] = value0;
        g_byteTable_guess[offset + 1] = value1;
        g_byteTable_guess[offset + 2] = value2;
    }
}

// FUNCTION: TITANIUM 0x00438D26
// Reads [TextColors] for all 86 colours; any missing component resets that colour to its default.
void CDisplay_guess::LoadUserDefinedColors_guess() {
    int green;
    int blue;
    int red;
    int index = 0;
    char value[256];
    char name[16];
    char key[32];

    do {
        int nextIndex = index + 1;
        sprintf(name, "User_%d_", nextIndex);
        strcpy(key, name);
        AppendString_guess(key, "Red");
        FUN_0060be50_guess("TextColors", key, "*NULL*", value, 0x100, ".\\eqclient.ini");
        if (value[0] == '*') {
            GetDefaultUserDefinedColor_guess(index, &red, &green, &blue);
        } else {
            red = atol(value);
            strcpy(key, name);
            AppendString_guess(key, "Green");
            FUN_0060be50_guess("TextColors", key, "*NULL*", value, 0x100, ".\\eqclient.ini");
            if (value[0] == '*') {
                GetDefaultUserDefinedColor_guess(index, &red, &green, &blue);
            } else {
                green = atol(value);
                strcpy(key, name);
                AppendString_guess(key, "Blue");
                FUN_0060be50_guess("TextColors", key, "*NULL*", value, 0x100, ".\\eqclient.ini");
                if (value[0] == '*') {
                    GetDefaultUserDefinedColor_guess(index, &red, &green, &blue);
                } else {
                    blue = atol(value);
                }
            }
        }
        SetUserDefinedColor_guess(index, (unsigned char)red, (unsigned char)green, (unsigned char)blue);
        index = nextIndex;
    } while (index + 1 < 0x57);
}

// Passes `value` and `count` to the actor's virtual at +0x50 (its scale) when there is an actor; the
// avatar height change and switches use it.
// FUNCTION: TITANIUM 0x00438EBC
void ScreenshotHandler_guess::SetActorScale_guess(ScreenshotTarget_guess* output, float value, int count) {
    if (output != 0) {
        output->SetScale_guess(value, count);
    }
}

// FUNCTION: TITANIUM 0x00438ED8
// Screenshots\EQ<6 digits>.<ScreenshotType>, starting at ScreenshotNumber and skipping files that exist.
void __cdecl CaptureScreenshot_guess() {
    int number;
    char filename[80];
    char extension[32];

    FUN_00576ed0_guess("Screenshots");
    g_getPrivateProfileStringA_guess("Defaults", "ScreenshotType", EQ_ARRAY(char, 0x00642464), extension, 0x20, ".\\eqclient.ini");
    number = FUN_0060be20_guess("Defaults", "ScreenshotNumber", 0, ".\\eqclient.ini");
    sprintf(filename, "Screenshots\\EQ%06d.%s", number, extension);
    void* file = fopen(filename, "rb");
    while (file != 0) {
        fclose(file);
        ++number;
        sprintf(filename, "Screenshots\\EQ%06d.%s", number, extension);
        file = fopen(filename, "rb");
    }
    g_screenshotOutput_guess->WriteScreenshot_guess(filename);
    sprintf(extension, "%d", number + 1);
    FUN_0060beb0_guess("Defaults", "ScreenshotNumber", extension, ".\\eqclient.ini");
}

// FUNCTION: TITANIUM 0x00438FC2
// Hands a sound environment to the sound manager (0x00851390) and stops the per-frame choice.
void CDisplay_guess::Handle_guess(int value) {
    g_queue_guess->SetRoomType_guess(value);
    state_2d5c_guess = 1;
}

struct ManagerView_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual float Slot45_guess();
};

struct ManagerCamera_guess {
    ManagerView_guess* view_0000_guess;
    unsigned char pad_0004_guess[0x44];
    float value_0048_guess;
    unsigned char pad_004c_guess[0x164];
    float value_01b0_guess;
};

struct ManagerDisplay_guess {
    unsigned char pad_0000_guess[0x1a8];
    ManagerCamera_guess* camera_01a8_guess;
};

struct ModeState_guess {
    unsigned char pad_0000_guess[4];
    unsigned char state_0004_guess;
};

#define g_display_guess EQ_GLOBAL(ManagerDisplay_guess*, 0x00905CE4)
#define g_modeState_guess EQ_GLOBAL(ModeState_guess*, 0x00905CC0)
#define g_value850d78_guess EQ_GLOBAL(unsigned int, 0x00850D78)

// EXTERNAL: TITANIUM 0x0046D655 CreateWorker_guess
int __cdecl CreateWorker_guess();

// FUNCTION: TITANIUM 0x00438FDF
// Picks one of three sound environments by the player's |+0x1B0 - floor (+0x48)|, probably the room height:
// up to 20, up to 500 (then by UpdateIndoorSoundState's flag), more.
void CDisplay_guess::UpdateSoundEnvironment_guess() {
    state_2d5c_guess = 0;
    if (g_display_guess == 0) {
        return;
    }
    int value = (int)_fabs((double)(g_display_guess->camera_01a8_guess->value_01b0_guess -
                                     g_display_guess->camera_01a8_guess->value_0048_guess));
    Queue_guess* queue = g_queue_guess;
    if (value <= 0x1f4) {
        if (value <= 0x14) {
            queue->SetEnclosedEnvironment_guess();
            return;
        }
        if (state_28e0_guess == 0) {
            queue->SetOutdoorEnvironment_guess();
        } else {
            queue->SetIndoorEnvironment_guess();
        }
        return;
    }
    queue->SetOutdoorEnvironment_guess();
}

// FUNCTION: TITANIUM 0x00439041
// Sets the indoor flag (engine value under 0.48) and night (hours 0-4, 19-23). The throttle reads last - now,
// unsigned, so it passes on almost every call: original code, keep it.
void CDisplay_guess::UpdateIndoorSoundState_guess() {
    int now = CreateWorker_guess();
    if (g_value850d78_guess - now <= 500) {
        return;
    }
    g_value850d78_guess = CreateWorker_guess();
    int visible = g_display_guess->camera_01a8_guess->view_0000_guess != 0 &&
                  g_display_guess->camera_01a8_guess->view_0000_guess->Slot45_guess() < 0.48f;
    state_28e0_guess = visible;
    g_queue_guess->SetWeatherLoopsMuted_guess(visible);
    g_queue_guess->SetMode_guess((g_modeState_guess->state_0004_guess <= 4) ||
                                 (g_modeState_guess->state_0004_guess >= 0x13));
}

// Each frame: moves every spawn's mobile sound emitter (ActorInfo +0x1B4) to the spawn's position (+0x30,
// +0x34, +0x38), so sounds follow moving spawns.
// FUNCTION: TITANIUM 0x004390CC
void __cdecl MoveMobileSoundEmitters_guess() {
    Listener_guess* listener = g_listenerHead_guess;
    while (listener != 0) {
        ListenerSink_guess* sink = listener->pActorInfo_01a8_guess->sink_01b4_guess;
        if (sink != 0) {
            sink->SetPosition_guess(listener->y_0030_guess, listener->x_0034_guess,
                                    listener->z_0038_guess);
        }
        listener = listener->next_0214_guess;
    }
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format, ...);

// FUNCTION: TITANIUM 0x0043910D
// Tells the server whose view the camera follows: message 0x7752 (EQEmu: OP_AckPacket) with that spawn's
// id, 0 for an actor with no spawn. Not sent in game states 1 and 2 (CEverQuest+0xB54).
void CDisplay_guess::SetViewActor_guess(ViewActor_guess* actor) {
    CameraFrame_guess frame;
    if (g_currentActor_guess != 0) {
        ((ViewActor_guess*)g_currentActor_guess)->Release_guess(0);
    }
    g_currentActor_guess = actor;
    if (actor != 0) {
        actor->GetPosition_guess(&frame.initialPosition_000c_guess);
        ((ViewActor_guess*)g_currentActor_guess)->FillCameraFrame_guess(&frame);
        if (callback_0118_guess->Slot13_guess(&frame.initialPosition_000c_guess, 0) != 0) {
            FUN_00574110_guess("* Bad Initial Camera Location %f, %f, %f(SetViewActor)\n",
                               (double)frame.initialPosition_000c_guess.x_0000_guess,
                               (double)frame.initialPosition_000c_guess.y_0004_guess,
                               (double)frame.initialPosition_000c_guess.z_0008_guess);
        }
        callback_0118_guess->Slot14_guess(&frame);
    }
    lastUpdateTime_0150_guess = 0;
    frame.spawnId_0018_guess = 0;
    if (g_currentActor_guess != 0 &&
        g_currentActor_guess != (void*)g_display_guess->camera_01a8_guess->view_0000_guess) {
        Listener_guess* entry = g_listenerHead_guess;
        while (entry != 0) {
            if (entry->pActorInfo_01a8_guess->actorInstance_0000_guess == g_currentActor_guess) {
                frame.spawnId_0018_guess = entry->spawnId_0258_guess;
                break;
            }
            entry = entry->next_0214_guess;
        }
    }
    if (g_stringTable_guess->mode_0b54_guess != 2 && g_stringTable_guess->mode_0b54_guess != 1) {
        EQSendMessage(&g_messageSource_guess, OP_AckPacket, &frame.spawnId_0018_guess, 4, 1);
    }
}

// FUNCTION: TITANIUM 0x0043933D
// Three engine calls when the display state changed (ChangeVideoMode); purpose not known.
void __cdecl FUN_0043933d_guess() {
    if ((g_stateFlag_guess != 0) && (g_stateFlag_guess->state_000c_guess == 0)) {
        g_stateDispatch_guess->Slot35_guess();
        g_stateDispatch_guess->Slot37_guess();
        return g_stateDispatch_guess->Slot35_guess();
    }
}

// FUNCTION: TITANIUM 0x00439377
// Light types 1-15 (0 is the player's own light): candle 25, torch and magic torch 100, small lantern and
// small magic 150, large lantern and large magic 200, type 8 the large lantern at 400, red and blue 150.
// A nonzero `distance` overrides the default; the result is capped at a global maximum.
AcquiredObject_guess* CDisplay_guess::CreateLightInstance_guess(unsigned char type, float distance, int value0, int value1, int value2) {
    AcquiredObject_guess* result_guess = 0;
    if (value_2cf8_guess != 0) {
        int value_guess;
        float range_guess;
        switch (type) {
        case 0:
            value_guess = playerLight_2d18_guess;
            range_guess = distance;
            break;
        case 1:
            value_guess = candleLight_2888_guess;
            if (distance == 0.0f) range_guess = 25.0f; else range_guess = distance;
            break;
        case 2:
            value_guess = torchLight_2870_guess;
            if (distance == 0.0f) range_guess = 100.0f; else range_guess = distance;
            break;
        case 3:
        case 9:
            value_guess = magTorchLight_2874_guess;
            if (distance == 0.0f) range_guess = 100.0f; else range_guess = distance;
            break;
        case 4:
            value_guess = smLanternLight_2878_guess;
            if (distance == 0.0f) range_guess = 150.0f; else range_guess = distance;
            break;
        case 5:
        case 10:
            value_guess = smMagicLight_2880_guess;
            if (distance == 0.0f) range_guess = 150.0f; else range_guess = distance;
            break;
        case 6:
            value_guess = lgLanternLight_287c_guess;
            if (distance == 0.0f) range_guess = 200.0f; else range_guess = distance;
            break;
        case 7:
        case 11:
            value_guess = lgMagicLight_2884_guess;
            if (distance == 0.0f) range_guess = 200.0f; else range_guess = distance;
            break;
        case 8:
            value_guess = lgLanternLight_287c_guess;
            if (distance == 0.0f) range_guess = 400.0f; else range_guess = distance;
            break;
        case 12:
        case 14:
            value_guess = redLight_288c_guess;
            if (distance == 0.0f) range_guess = 150.0f; else range_guess = distance;
            break;
        case 13:
        case 15:
            value_guess = blueLight_2890_guess;
            if (distance == 0.0f) range_guess = 150.0f; else range_guess = distance;
            break;
        default:
            return 0;
        }

        if (value_guess != 0) {
            double max_distance_guess = g_distanceOwner_guess->GetDistance_guess();
            if (range_guess > max_distance_guess) {
                range_guess = (float)max_distance_guess;
            }
            RequestData_guess data_guess;
            data_guess.value_0000_guess = value0;
            data_guess.value_0004_guess = value1;
            data_guess.value_0008_guess = value2;
            g_actorReceiver_guess->Acquire_guess(value_guess, &data_guess, range_guess, &result_guess);
            result_guess->Slot00_guess();
            result_guess->Slot01_guess();
        }
    }
    return result_guess;
}

struct AngleMath_guess {
    unsigned char pad_0000_guess[0x148];
    unsigned int frame_0148_guess;
    void ProcessEffects_guess();
    float FixHeading_guess(float angle_guess);
    float HeadingDiff_guess(float first_guess, float second_guess, float* output_guess);
};

// FUNCTION: TITANIUM 0x004365DB
// Headings run 0-512. More than six wraps reset it to 0, so a wild value can't hang the loop.
float AngleMath_guess::FixHeading_guess(float angle_guess) {
    int count_guess = 0;
    while (angle_guess >= 512.0f) {
        angle_guess -= 512.0f;
        if (count_guess > 5) {
            angle_guess = 0.0f;
            break;
        }
        ++count_guess;
    }
    count_guess = 0;
    while (angle_guess < 0.0) {
        angle_guess += 512.0f;
        if (count_guess > 5) {
            angle_guess = 0.0f;
            break;
        }
        ++count_guess;
    }
    return angle_guess;
}

// FUNCTION: TITANIUM 0x00436628
// The smallest angle between two headings; *output gets it signed.
float AngleMath_guess::HeadingDiff_guess(float first_guess, float second_guess, float* output_guess) {
    float high_guess;
    float low_guess;
    if (first_guess > second_guess) {
        high_guess = first_guess;
        low_guess = second_guess;
    } else {
        high_guess = second_guess;
        low_guess = first_guess;
    }
    float difference_guess = high_guess - low_guess;
    if (difference_guess > 256.0f) {
        difference_guess -= 512.0f;
        if (output_guess != 0) {
            *output_guess = difference_guess;
        }
        return -difference_guess;
    }
    if (output_guess != 0) {
        *output_guess = difference_guess;
    }
    return difference_guess;
}

struct StateData_guess {
    unsigned char pad_0000_guess[0x23];
    unsigned char state_0023_guess;
    unsigned char pad_0024_guess[0x10];
    float value_0034_guess;
};

struct GameMode_guess {
    unsigned char pad_0000_guess[4];
    unsigned char mode_0004_guess;
};

struct StateOwner_guess {
    unsigned char pad_0000_guess[0x14d];
    unsigned char enabled_014d_guess;
    void Update_guess(StateData_guess* state_guess);
    void ProcessSwitches_guess();
};

#define g_gameMode_guess EQ_GLOBAL(GameMode_guess*, 0x00905CC0)

// FUNCTION: TITANIUM 0x00436678
// CDisplay::UpdateDoorStateBasedOnWorldTime (the earlier sibling decomp): a door with parameter 2.0 is closed in
// daytime (hours 5-18) unless CDisplay+0x14D is set; 1.0 is open only in daytime. Other values: untouched.
void StateOwner_guess::Update_guess(StateData_guess* state_guess) {
    if (state_guess->value_0034_guess == 0.0f) {
        return;
    }
    if (state_guess->value_0034_guess == 2.0f) {
        if (enabled_014d_guess == 0) {
            unsigned char mode_guess = g_gameMode_guess->mode_0004_guess;
            if ((mode_guess >= 5) && (mode_guess <= 0x12)) {
                state_guess->state_0023_guess = 0;
                return;
            }
        }
        state_guess->state_0023_guess = 1;
        return;
    }
    if (state_guess->value_0034_guess != 1.0f) {
        return;
    }
    unsigned char mode_guess = g_gameMode_guess->mode_0004_guess;
    if ((mode_guess <= 4) || (mode_guess >= 0x13)) {
        state_guess->state_0023_guess = 0;
        return;
    }
    state_guess->state_0023_guess = 1;
}

struct MotionState366E8_guess {
    unsigned char pad_0000_guess[0x22];
    unsigned char type_0022_guess;
    unsigned char mode_0023_guess;
    float value_0024_guess;
    float value_0028_guess;
    unsigned char pad_002c_guess[0x0c];
    float value_0038_guess;
    float value_003c_guess;
    unsigned char pad_0040_guess[4];
    float direction_0044_guess;
    // EXTERNAL: TITANIUM 0x0049030E MotionState366E8_guess::GetTriggerRange_guess
    float GetTriggerRange_guess();
    // EXTERNAL: TITANIUM 0x0048FC2E MotionState366E8_guess::FUN_0048fc2e_guess
    void FUN_0048fc2e_guess(int value_guess, int zero1_guess, int zero2_guess);
};

struct MotionHandler366E8_guess {
    unsigned char UpdateDoorPosition_guess(MotionState366E8_guess* state_guess, float amount_guess,
        int notify_guess, float scale_guess);
};

// FUNCTION: TITANIUM 0x004366E8
// @early-stop: budget, structural ndiff=87
// 0.35 is the speed when `amount` is 0; door type 0x4E takes its threshold from the door (default 22).
unsigned char MotionHandler366E8_guess::UpdateDoorPosition_guess(MotionState366E8_guess* state_guess,
    float amount_guess, int notify_guess, float scale_guess) {
    unsigned char result_guess = 0;
    float threshold_guess = 0.0f;
    amount_guess = amount_guess == 0.0f ? 0.35f : amount_guess;
    unsigned char type_guess = state_guess->type_0022_guess;
    if (type_guess < 0x4f) {
        if (type_guess == 0x4e) {
            threshold_guess = state_guess->GetTriggerRange_guess();
            if (threshold_guess == 0.0f) {
                threshold_guess = 22.0f;
            }
        } else if (type_guess < 0x17) {
            if (type_guess < 0x14) {
                if (type_guess > 9) {
                    if (type_guess < 0xd) {
                        threshold_guess = 8.0f;
                    } else if (type_guess > 0xe && type_guess < 0x12) {
                        threshold_guess = 10.0f;
                    }
                }
            } else {
                threshold_guess = 14.0f;
            }
        } else if (type_guess > 0x18 && type_guess < 0x1c) {
            threshold_guess = state_guess->GetTriggerRange_guess();
            if (threshold_guess == 0.0f) {
                threshold_guess = 22.0f;
            }
        }
    } else if (type_guess == 0x4f || type_guess == 0x51) {
        amount_guess = -amount_guess;
        threshold_guess = state_guess->GetTriggerRange_guess();
        if (threshold_guess == 0.0f) {
            threshold_guess = 22.0f;
        }
    } else if (type_guess == 0x50) {
        threshold_guess = state_guess->GetTriggerRange_guess();
        if (threshold_guess == 0.0f) {
            threshold_guess = 22.0f;
        }
    }
    if (amount_guess < 0.0f) {
        threshold_guess = -threshold_guess;
    }
    float* current_guess;
    float* base_guess;
    if (state_guess->direction_0044_guess == 128.0f) {
        current_guess = &state_guess->value_0038_guess;
        base_guess = &state_guess->value_0024_guess;
    } else if (state_guess->direction_0044_guess == 256.0f) {
        current_guess = &state_guess->value_003c_guess;
        base_guess = &state_guess->value_0028_guess;
    } else {
        amount_guess = -amount_guess;
        threshold_guess = -threshold_guess;
        if (state_guess->direction_0044_guess == 384.0f) {
            current_guess = &state_guess->value_0038_guess;
            base_guess = &state_guess->value_0024_guess;
        } else {
            current_guess = &state_guess->value_003c_guess;
            base_guess = &state_guess->value_0028_guess;
        }
    }
    float limit_guess = threshold_guess + *base_guess;
    if (threshold_guess < 0.0f) {
        threshold_guess = -threshold_guess;
    }
    if (state_guess->mode_0023_guess == 2) {
        float next_guess = amount_guess * scale_guess + *current_guess;
        *current_guess = next_guess;
        if (_fabs((double)(next_guess - *base_guess)) >= (double)threshold_guess) {
            *current_guess = limit_guess;
            result_guess = 1;
            if (notify_guess != 0) {
                state_guess->FUN_0048fc2e_guess(1, 0, 0);
            }
        }
    } else {
        float next_guess = *current_guess - amount_guess * scale_guess;
        *current_guess = next_guess;
        if (_fabs((double)(next_guess - limit_guess)) >= (double)threshold_guess) {
            *current_guess = *base_guess;
            result_guess = 1;
            if (notify_guess != 0) {
                state_guess->FUN_0048fc2e_guess(0, 0, 0);
            }
        }
    }
    return result_guess;
}

struct DoorModel_guess {
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
    virtual float GetScale_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void SetPosition_guess(Vector3_guess* position_guess);
    virtual void SetRotation_guess(Vector3_guess* rotation_guess);
};

struct DoorSound_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Release_guess(int value_guess);
};

struct Door_guess {
    unsigned char pad_0000_guess[0x22];
    unsigned char type_0022_guess;
    unsigned char state_0023_guess;
    Vector3_guess home_0024_guess;
    float heading_0030_guess;
    float tilt_0034_guess;
    Vector3_guess pos_0038_guess;
    float heading_0044_guess;
    float tilt_0048_guess;
    unsigned char prevState_004c_guess;
    unsigned char pad_004d_guess[2];
    unsigned char disabled_004f_guess;
    unsigned char pad_0050_guess[0x16];
    short effect_0066_guess;
    unsigned char pad_0068_guess[0x28];
    DoorModel_guess* model_0090_guess;
    DoorSound_guess* sound_0094_guess;
    unsigned int time_0098_guess;
    float speed_009c_guess;

    // EXTERNAL: TITANIUM 0x004903D4 Door_guess::IsBusy_guess
    unsigned char IsBusy_guess();
    // EXTERNAL: TITANIUM 0x0048FC2E Door_guess::SetState_guess
    void SetState_guess(unsigned char state_guess, int value0_guess, int value1_guess);
    // EXTERNAL: TITANIUM 0x0048FAA5 Door_guess::RepopFrequency_guess
    unsigned int RepopFrequency_guess();
    // EXTERNAL: TITANIUM 0x00490B20 Door_guess::ToggleDoorState_guess
    void ToggleDoorState_guess();
    // EXTERNAL: TITANIUM 0x004903F1 Door_guess::IsReady_guess
    unsigned char IsReady_guess();
    // EXTERNAL: TITANIUM 0x00490370 Door_guess::IsSolid_guess
    unsigned char IsSolid_guess();
    // EXTERNAL: TITANIUM 0x0048FA18 Door_guess::TopSpeed_guess
    float TopSpeed_guess(float* accel_guess);
    // EXTERNAL: TITANIUM 0x0049030E Door_guess::GetDistance_guess
    float GetDistance_guess();
};

struct DoorList_guess {
    // EXTERNAL: TITANIUM 0x004904FD DoorList_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x00490530 DoorList_guess::Get_guess
    Door_guess* Get_guess(int index_guess);
};

// x/y pair; Length2D only reads x and y
struct DoorDelta_guess {
    float deltaY_0000_guess;
    float deltaX_0004_guess;
};

struct DoorEffect_guess {
    unsigned char data_guess[0xae8];
};

struct DoorSpawn_guess {
    unsigned char pad_0000_guess[0x30];
    float y_0030_guess;
    float x_0034_guess;
    unsigned char pad_0038_guess[0x214 - 0x38];
    DoorSpawn_guess* next_0214_guess;
    unsigned char pad_0218_guess[0x2e6 - 0x218];
    unsigned char touched_02e6_guess;

    // EXTERNAL: TITANIUM 0x004898D6 DoorSpawn_guess::GetActor_guess
    DoorModel_guess* GetActor_guess();
    // EXTERNAL: TITANIUM 0x00489955 DoorSpawn_guess::Touch_guess
    void Touch_guess();
};

// EXTERNAL: TITANIUM 0x0049AB78 DoParticleEffect_guess
DoorSound_guess* __cdecl DoParticleEffect_guess(int kind_guess, DoorEffect_guess* effect_guess, int id_guess, void* player_guess,
    int value0_guess, int value1_guess, Vector3_guess* pos_guess, int value2_guess, int duration_guess);

#define g_doorLastTick_guess EQ_GLOBAL(int, 0x00850D0C)
#define g_doorList_guess EQ_GLOBAL(DoorList_guess*, 0x00903E84)
#define g_doorPlayer_guess EQ_GLOBAL(void*, 0x00905CE4)
#define g_doorEffects_guess EQ_ARRAY(DoorEffect_guess, 0x008513B8)
#define g_doorSpawns_guess EQ_GLOBAL(DoorSpawn_guess*, 0x00905CC4)

// FUNCTION: TITANIUM 0x004368B3
// @early-stop: budget, structural ndiff=252
// CDisplay::ProcessSwitches: moves the doors each frame and settles doors in states 2 and 3.
void StateOwner_guess::ProcessSwitches_guess() {
    float rate_guess = 0.0f;
    float radius_guess = 100.0f;
    float rate2_guess = 0.0f;
    // Time step: ms since the last pass times 0.02 (50 ms units). Movement below is scaled by it;
    // the spinner speed-ups and slow-downs are applied once per pass.
    float dt_guess = (float)(unsigned int)(FUN_0046d655_guess() - g_doorLastTick_guess) * 0.02f;
    float px_guess;
    float py_guess;
    g_doorLastTick_guess = FUN_0046d655_guess();
    for (int i = 0; i < g_doorList_guess->Count_guess(); i++) {
        Door_guess* door = g_doorList_guess->Get_guess(i);
        if (door->disabled_004f_guess != 0) {
            continue;
        }
        // Type 53 carries a particle effect (+0x66, 1-255) at the door while open (state 1); it is
        // released with a 1 s fade once closed (state 0).
        if (door->type_0022_guess == 0x35) {
            Update_guess((StateData_guess*)door);
            if (door->state_0023_guess == 1 && door->sound_0094_guess == 0) {
                short effect_guess = door->effect_0066_guess;
                if (effect_guess > 0 && effect_guess < 0x100 && g_doorPlayer_guess != 0) {
                    Vector3_guess pos_guess;
                    pos_guess.x_0000_guess = door->pos_0038_guess.x_0000_guess;
                    pos_guess.y_0004_guess = door->pos_0038_guess.y_0004_guess;
                    pos_guess.z_0008_guess = door->pos_0038_guess.z_0008_guess;
                    door->sound_0094_guess = DoParticleEffect_guess(2, &g_doorEffects_guess[effect_guess], effect_guess,
                        g_doorPlayer_guess, 0, 0, &pos_guess, 0, 43200000);
                }
            } else if (door->state_0023_guess == 0) {
                if (door->sound_0094_guess != 0) {
                    door->sound_0094_guess->Release_guess(1000);
                    door->sound_0094_guess = 0;
                }
            }
        }
        if (door->IsBusy_guess()) {
            continue;
        }
        unsigned int elapsed_guess = g_doorLastTick_guess - door->time_0098_guess;
        if (door->state_0023_guess != door->prevState_004c_guess) {
            // A changed state (+0x23 against +0x4C) reverts on its own: state 4 after 60 s, any
            // other once the door's repop time, when nonzero, has passed.
            if (door->state_0023_guess == 4) {
                if (elapsed_guess <= 60000) {
                    continue;
                }
                door->SetState_guess(door->prevState_004c_guess, 0, 0);
            } else {
                unsigned int timeout_guess = door->RepopFrequency_guess();
                if (timeout_guess != 0 && elapsed_guess > timeout_guess) {
                    door->ToggleDoorState_guess();
                }
            }
        }
        unsigned char type_guess = door->type_0022_guess;
        // Types 53, 57 and 58 never move. The rest animate while opening (2) and closing (3); an
        // open door (1) below type 100 is at rest. States: 0 closed, 1 open.
        if (type_guess != 0x35 && type_guess != 0x39 && type_guess != 0x3a) {
            if (door->state_0023_guess == 0) {
                continue;
            }
            if (door->state_0023_guess == 1 && type_guess < 100) {
                continue;
            }
            unsigned char ready_guess = door->IsReady_guess();
            // A solid door keeps its centre and radius (model scale, else 100) for the spawn sweep
            // at the end.
            unsigned char solid_guess = door->IsSolid_guess();
            if (solid_guess) {
                if (door->model_0090_guess != 0) {
                    radius_guess = door->model_0090_guess->GetScale_guess();
                } else {
                    radius_guess = 100.0f;
                }
                px_guess = door->pos_0038_guess.x_0000_guess;
                py_guess = door->pos_0038_guess.y_0004_guess;
            }
            type_guess = door->type_0022_guess;
            float range_guess = 128.0f;
            float target_guess;
            // Types 0-8 swing on the heading: a quarter turn (128 of 512) at 8 per step, types 5-7
            // the other way.
            if (type_guess <= 8) {
                rate_guess = 8.0f;
                if (door->type_0022_guess >= 5 && door->type_0022_guess <= 7) {
                    rate_guess = -8.0f;
                    range_guess = -128.0f;
                }
                target_guess = ((AngleMath_guess*)this)->FixHeading_guess(range_guess + door->heading_0030_guess);
                if (range_guess < 0.0f) {
                    range_guess = -range_guess;
                }
                if (door->state_0023_guess == 2) {
                    door->heading_0044_guess = ((AngleMath_guess*)this)->FixHeading_guess(door->heading_0044_guess + dt_guess * rate_guess);
                    if (((AngleMath_guess*)this)->HeadingDiff_guess(door->heading_0044_guess, door->heading_0030_guess, 0) >= range_guess) {
                        door->heading_0044_guess = target_guess;
                        door->SetState_guess(1, 0, 0);
                    }
                } else {
                    door->heading_0044_guess = ((AngleMath_guess*)this)->FixHeading_guess(door->heading_0044_guess - dt_guess * rate_guess);
                    if (((AngleMath_guess*)this)->HeadingDiff_guess(door->heading_0044_guess, target_guess, 0) >= range_guess) {
                        door->heading_0044_guess = door->heading_0030_guess;
                        door->SetState_guess(0, 0, 0);
                    }
                }
            // Types 30, 35, 36, 40 and 130 swing on the tilt (+0x48) instead: 128 (248 for 130) at
            // their own open / close rates; 36 the other way.
            } else if (type_guess == 0x28 || type_guess == 0x1e || type_guess == 0x23
                || type_guess == 0x82 || type_guess == 0x24) {
                switch (type_guess) {
                case 0x1e:
                    rate2_guess = 4.0f;
                    rate_guess = 10.0f;
                    break;
                case 0x23:
                    rate2_guess = 8.0f;
                    rate_guess = 16.0f;
                    break;
                case 0x24:
                    rate2_guess = -8.0f;
                    rate_guess = -16.0f;
                    break;
                case 0x82:
                    range_guess = 248.0f;
                    rate2_guess = rate_guess = 16.0f;
                    break;
                default:
                    rate2_guess = rate_guess = 8.0f;
                    break;
                }
                target_guess = ((AngleMath_guess*)this)->FixHeading_guess(door->tilt_0034_guess - range_guess);
                if (range_guess < 0.0f) {
                    range_guess = -range_guess;
                }
                if (door->state_0023_guess == 2) {
                    if (((AngleMath_guess*)this)->HeadingDiff_guess(door->tilt_0048_guess, door->tilt_0034_guess, 0) >= range_guess) {
                        door->tilt_0048_guess = target_guess;
                        door->SetState_guess(1, 0, 0);
                    } else {
                        door->tilt_0048_guess = ((AngleMath_guess*)this)->FixHeading_guess(door->tilt_0048_guess - dt_guess * rate_guess);
                    }
                } else if (door->state_0023_guess == 3) {
                    if (((AngleMath_guess*)this)->HeadingDiff_guess(door->tilt_0048_guess, target_guess, 0) >= range_guess) {
                        door->tilt_0048_guess = door->tilt_0034_guess;
                        door->SetState_guess(0, 0, 0);
                    } else {
                        door->tilt_0048_guess = ((AngleMath_guess*)this)->FixHeading_guess(door->tilt_0048_guess + dt_guess * rate_guess);
                    }
                }
            // Lifts slide z away from home (+0x24). Up: 60-62 by 8, 65-67 by 10, 70-72 by 14, 75-77
            // by the door's distance (22 when unset), 59 and 78-79 by the distance. Down: 80-81 by
            // the distance; 120, 140, 145 and 146 by 10. Other types in the range move 128 at 0.25.
            // 78-81 also run the path step, and closing settles only once that step is done.
            } else if ((type_guess >= 0x3c && type_guess <= 0x4d) || (type_guess >= 0x8c && type_guess <= 0x92)
                || type_guess == 0x78 || type_guess == 0x3b || (type_guess >= 0x4e && type_guess <= 0x51)) {
                unsigned char ok_guess = 1;
                rate_guess = 0.25f;
                rate2_guess = 0.25f;
                switch (door->type_0022_guess) {
                case 0x3c:
                case 0x3d:
                case 0x3e:
                    range_guess = 8.0f;
                    rate_guess = 0.45f;
                    break;
                case 0x41:
                case 0x42:
                case 0x43:
                    range_guess = 10.0f;
                    rate_guess = 0.45f;
                    break;
                case 0x46:
                case 0x47:
                case 0x48:
                    range_guess = 14.0f;
                    rate_guess = 0.45f;
                    break;
                case 0x4b:
                case 0x4c:
                case 0x4d:
                    range_guess = door->GetDistance_guess();
                    if (range_guess == 0.0f) {
                        range_guess = 22.0f;
                    }
                    rate_guess = 0.45f;
                    break;
                case 0x4e:
                case 0x4f:
                    ok_guess = ((MotionHandler366E8_guess*)this)->UpdateDoorPosition_guess((MotionState366E8_guess*)door, 0.0f, 0, dt_guess);
                case 0x3b:
                    range_guess = door->GetDistance_guess();
                    rate2_guess = rate_guess = 0.45f;
                    break;
                case 0x50:
                case 0x51:
                    ok_guess = ((MotionHandler366E8_guess*)this)->UpdateDoorPosition_guess((MotionState366E8_guess*)door, 0.0f, 0, dt_guess);
                    range_guess = -door->GetDistance_guess();
                    rate2_guess = rate_guess = -0.45f;
                    break;
                case 0x78:
                case 0x8c:
                    range_guess = -10.0f;
                    rate_guess = -1.0f;
                    rate2_guess = -0.25f;
                    break;
                case 0x91:
                    range_guess = -10.0f;
                    rate2_guess = rate_guess = -0.25f;
                    break;
                case 0x92:
                    range_guess = -10.0f;
                    rate_guess = -1.0f;
                    rate2_guess = -1.0f;
                    break;
                }
                target_guess = range_guess + door->home_0024_guess.z_0008_guess;
                if (range_guess < 0.0f) {
                    range_guess = -range_guess;
                }
                if (door->state_0023_guess == 2) {
                    door->pos_0038_guess.z_0008_guess += dt_guess * rate_guess;
                    if (_fabs(door->pos_0038_guess.z_0008_guess - door->home_0024_guess.z_0008_guess) >= range_guess) {
                        door->pos_0038_guess.z_0008_guess = target_guess;
                        door->SetState_guess(1, 0, 0);
                    }
                } else if (door->state_0023_guess == 3) {
                    door->pos_0038_guess.z_0008_guess -= dt_guess * rate2_guess;
                    if (_fabs(door->pos_0038_guess.z_0008_guess - target_guess) >= range_guess) {
                        door->pos_0038_guess.z_0008_guess = door->home_0024_guess.z_0008_guess;
                        if (ok_guess) {
                            door->SetState_guess(0, 0, 0);
                        }
                    }
                }
            // Types 10-27 move only by the path step.
            } else if (type_guess >= 10 && type_guess <= 0x1b) {
                ((MotionHandler366E8_guess*)this)->UpdateDoorPosition_guess((MotionState366E8_guess*)door, 0.0f, 1, dt_guess);
            } else if ((type_guess >= 100 && type_guess <= 0x6b) || type_guess == 0x73 || type_guess == 0x74) {
                float* angle_guess = &door->heading_0044_guess;
                if (type_guess >= 0x69) {
                    angle_guess = &door->tilt_0048_guess;
                }
                // Spinners (100-107, 115, 116): opening speeds up by the rate until top speed (then
                // state 1), open keeps spinning, closing slows down to a stop (state 0). 105 and up
                // spin on the tilt.
                float speed_guess = door->TopSpeed_guess(&rate_guess);
                if (door->state_0023_guess == 2) {
                    float current_guess = rate_guess + door->speed_009c_guess;
                    door->speed_009c_guess = current_guess;
                    if (current_guess >= speed_guess) {
                        door->SetState_guess(1, 0, 0);
                    } else {
                        *angle_guess += current_guess * dt_guess;
                    }
                } else if (door->state_0023_guess == 1) {
                    *angle_guess += speed_guess * dt_guess;
                } else {
                    float current_guess = door->speed_009c_guess - rate_guess;
                    door->speed_009c_guess = current_guess;
                    if (current_guess <= 0.0f) {
                        door->SetState_guess(0, 0, 0);
                    } else {
                        *angle_guess += current_guess * dt_guess;
                    }
                }
                *angle_guess = ((AngleMath_guess*)this)->FixHeading_guess(*angle_guess);
            }
            type_guess = door->type_0022_guess;
            if (type_guess == 0x2d || type_guess == 0x6d || type_guess == 0x73 || type_guess == 0x74 || type_guess == 0x7d
                || (type_guess >= 0x96 && type_guess <= 0x98)) {
                switch (type_guess) {
                case 0x2d:
                case 0x6d:
                    range_guess = -1.0f;
                    rate2_guess = rate_guess = -0.05f;
                    break;
                case 0x73:
                    range_guess = 20.0f;
                    rate2_guess = rate_guess = 0.75f;
                    break;
                case 0x74:
                    range_guess = 40.0f;
                    rate2_guess = rate_guess = 0.75f;
                    break;
                case 0x7d:
                    rate2_guess = 0.35f;
                    rate_guess = 0.75f;
                    range_guess = 10.0f;
                    break;
                case 0x96:
                    rate_guess = 1.0f;
                    rate2_guess = 0.25f;
                    range_guess = 10.0f;
                    break;
                case 0x97:
                    rate_guess = 0.25f;
                    rate2_guess = 0.25f;
                    range_guess = 10.0f;
                    break;
                case 0x98:
                    rate_guess = 1.0f;
                    rate2_guess = 1.0f;
                    range_guess = 10.0f;
                    break;
                }
                float* value_guess;
                float* home_guess;
                // Sliders (45, 109, 115, 116, 125, 150-152) move along the first axis of +0x38 at
                // heading 0 or 256 and the second at 128 or any other; headings other than 0 and 128
                // reverse the range and rates (45 and 109 start negative).
                if (door->heading_0044_guess == 0.0f) {
                    value_guess = &door->pos_0038_guess.x_0000_guess;
                    home_guess = &door->home_0024_guess.x_0000_guess;
                } else if (door->heading_0044_guess == 128.0f) {
                    value_guess = &door->pos_0038_guess.y_0004_guess;
                    home_guess = &door->home_0024_guess.y_0004_guess;
                } else {
                    rate_guess = -rate_guess;
                    rate2_guess = -rate2_guess;
                    range_guess = -range_guess;
                    if (door->heading_0044_guess == 256.0f) {
                        value_guess = &door->pos_0038_guess.x_0000_guess;
                        home_guess = &door->home_0024_guess.x_0000_guess;
                    } else {
                        value_guess = &door->pos_0038_guess.y_0004_guess;
                        home_guess = &door->home_0024_guess.y_0004_guess;
                    }
                }
                target_guess = range_guess + *home_guess;
                if (range_guess < 0.0f) {
                    range_guess = -range_guess;
                }
                if (door->state_0023_guess == 2) {
                    *value_guess += dt_guess * rate_guess;
                    if (_fabs(*value_guess - *home_guess) >= range_guess) {
                        *value_guess = target_guess;
                        door->SetState_guess(1, 0, 0);
                    }
                } else if (door->state_0023_guess == 3) {
                    *value_guess -= dt_guess * rate2_guess;
                    if (_fabs(*value_guess - target_guess) >= range_guess) {
                        *value_guess = *home_guess;
                        door->SetState_guess(0, 0, 0);
                    }
                }
            }
            if (door->state_0023_guess == 1) {
                type_guess = door->type_0022_guess;
                // Once fully open, 109 toggles back at once and 110-152 (not 115) start closing:
                // they cycle.
                if (type_guess != 0x73) {
                    if (type_guess == 0x6d) {
                        door->ToggleDoorState_guess();
                    } else if (type_guess > 0x6d && type_guess <= 0x98) {
                        door->SetState_guess(3, 0, 0);
                    }
                }
            }
            if (door->model_0090_guess == 0) {
                continue;
            }
            Vector3_guess position_guess;
            position_guess.x_0000_guess = door->pos_0038_guess.x_0000_guess;
            position_guess.y_0004_guess = door->pos_0038_guess.y_0004_guess;
            position_guess.z_0008_guess = door->pos_0038_guess.z_0008_guess;
            Vector3_guess rotation_guess;
            rotation_guess.x_0000_guess = door->heading_0044_guess;
            rotation_guess.y_0004_guess = door->tilt_0048_guess;
            rotation_guess.z_0008_guess = 0.0f;
            door->model_0090_guess->SetPosition_guess(&position_guess);
            door->model_0090_guess->SetRotation_guess(&rotation_guess);
            // Spawns within radius + 200 + their size (2D): a solid door touches them (Touch_guess),
            // otherwise they are only flagged (+0x2E6).
            if (solid_guess || ready_guess) {
                for (DoorSpawn_guess* spawn_guess = g_doorSpawns_guess; spawn_guess != 0;
                    spawn_guess = spawn_guess->next_0214_guess) {
                    float reach_guess = radius_guess + 200.0f;
                    DoorModel_guess* actor_guess = spawn_guess->GetActor_guess();
                    float size_guess;
                    if (actor_guess != 0) {
                        size_guess = actor_guess->GetScale_guess();
                    } else {
                        size_guess = 10.0f;
                    }
                    DoorDelta_guess delta_guess;
                    delta_guess.deltaY_0000_guess = spawn_guess->y_0030_guess - px_guess;
                    delta_guess.deltaX_0004_guess = spawn_guess->x_0034_guess - py_guess;
                    if (((Vector3_guess*)&delta_guess)->Length2D_guess() < size_guess + reach_guess) {
                        if (solid_guess) {
                            spawn_guess->Touch_guess();
                        } else {
                            spawn_guess->touched_02e6_guess = 1;
                        }
                    }
                }
            }
        // Types 53, 57 and 58 finish opening or closing at once.
        } else if (door->state_0023_guess == 2) {
            door->SetState_guess(1, 0, 0);
        } else if (door->state_0023_guess == 3) {
            door->SetState_guess(0, 0, 0);
        }
    }
}

struct SetupObject_guess {
    virtual void Slot00_guess();
    virtual void Reset_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void SetValue10_guess(float value);
    virtual void SetValue14_guess(float value);
    virtual void SetValue18_guess(float value);
    virtual void Slot07_guess();
    virtual void SetValue20_guess(float value);
    virtual void Slot09_guess();
    virtual void SetValue28_guess(float value);
    virtual void Slot11_guess();
    virtual void SetValue30_guess(int value);
};

#define g_setup0_guess EQ_GLOBAL(SetupObject_guess*, 0x009254FC)
#define g_setup1_guess EQ_GLOBAL(SetupObject_guess*, 0x00925500)
#define g_setup2_guess EQ_GLOBAL(SetupObject_guess*, 0x00925504)
#define g_setup3_guess EQ_GLOBAL(SetupObject_guess*, 0x00925508)
#define g_setup4_guess EQ_GLOBAL(SetupObject_guess*, 0x0092550C)
#define g_setup5_guess EQ_GLOBAL(SetupObject_guess*, 0x00925510)
#define g_setup6_guess EQ_GLOBAL(SetupObject_guess*, 0x00925514)
#define pinstProjectileCamera_guess EQ_GLOBAL(SetupObject_guess*, 0x0092551C)
#define g_setupEnabled_guess EQ_GLOBAL(int, 0x00923D74)

// FUNCTION: TITANIUM 0x00445842
// @early-stop: budget, structural ndiff=60
// The world update without the full render: spawns, doors, camera, sky.
void CDisplay_guess::Render_MinWorld_guess() {
    int one = 1;
    if ((EQ_GLOBAL(unsigned char, 0x00850DA8) & 1) == 0) {
        EQ_GLOBAL(int, 0x00850DA8) |= one;
        int initialValue;
        try {
            initialValue = FUN_0046d655_guess();
        } catch (...) {
            throw;
        }
        EQ_GLOBAL(int, 0x00850DA4) = initialValue;
    }

    int updateAll;
    if (pEverQuest->pad_0000C[0x2d2] == one && g_statusByte_guess->value_01e2_guess != 0) {
        updateAll = 0;
        ((Player_436039_guess*)EQ_GLOBAL(EQPlayer*, 0x00905CE4))->UpdatePlayerVisibility_guess();
    } else {
        updateAll = one;
    }

    frameTime_0148_guess = FUN_0046d655_guess();
    g_actorReceiver_guess->Slot15_guess(frameTime_0148_guess);
    ((StateOwner_guess*)this)->ProcessSwitches_guess();

    EQPlayer* player = EQ_GLOBAL(EQPlayer*, 0x00905CC4);
    for (; player != 0; player = player->pNext) {
        FUN_004bfe0f_guess(player, 0, 0);
        ((Player_436039_guess*)player)->MovePlayer_guess();
        if (player != EQ_GLOBAL(EQPlayer*, 0x00905CE4) || updateAll != 0) {
            ((Player_436039_guess*)player)->PlayIdleFidget_guess();
        }
    }

    int association = FindSpawnByActor_guess((int)g_currentActor_guess);
    if (association != 0) {
        ((AssociationAction_guess*)association)->FUN_0056ffa8_guess();
    }

    AboutToHide_guess* camera = callback_0118_guess;
    g_cameraService_guess->SetListenerLocation_guess(
        camera->Slot20_guess(camera->Slot21_guess(camera->Slot22_guess(camera->Slot17_guess()))));
    g_cameraService_guess->ProcessSound_guess();

    if (g_sharedStringOutput_guess != 0) {
        g_actorReceiver_guess->Slot28_guess(g_sharedStringOutput_guess);
        g_sharedStringOutput_guess->Set_guess((CXStr&)text_2d28_guess);
    }

    ProcessSky_guess();

    EQPlayer* localPlayer = EQ_GLOBAL(EQPlayer*, 0x00905CE4);
    if (localPlayer != 0 && localPlayer->pActorInfo != 0 && *(void**)localPlayer->pActorInfo != 0) {
        ((ViewActor_guess*)*(void**)localPlayer->pActorInfo)->Slot17_guess();
    }
    g_screenshotOutput_guess->Slot36_guess();
    if (EQ_GLOBAL(int, 0x00923914) != -1) {
        SetRenderWindow_guess();
    }
}

// FUNCTION: TITANIUM 0x004372E6
// Resets the eight camera objects (0x009254FC, indexed by camera mode) to their default offsets; camera 2's
// offsets apply only when 0x00923D74 is 1.
void CDisplay_guess::DefaultCameras_guess() {
    g_setup0_guess->Reset_guess();
    g_setup0_guess->SetValue28_guess(90.0f);
    g_setup1_guess->Reset_guess();
    g_setup1_guess->SetValue10_guess(25.0f);
    g_setup1_guess->SetValue14_guess(-100.0f);
    g_setup2_guess->Reset_guess();
    if (g_setupEnabled_guess == 1) {
        g_setup2_guess->SetValue18_guess(8.43998f);
        g_setup2_guess->SetValue10_guess(3.05999f);
        g_setup2_guess->SetValue14_guess(-17.52f);
    }
    g_setup3_guess->Reset_guess();
    g_setup3_guess->SetValue18_guess(30.0f);
    g_setup3_guess->SetValue20_guess(192.0f);
    g_setup3_guess->SetValue10_guess(5.0f);
    g_setup3_guess->SetValue30_guess(1);
    g_setup4_guess->Reset_guess();
    g_setup4_guess->SetValue18_guess(82.0f);
    g_setup4_guess->SetValue20_guess(277.0f);
    g_setup4_guess->SetValue10_guess(18.0f);
    g_setup4_guess->SetValue30_guess(1);
    g_setup6_guess->Reset_guess();
    g_setup5_guess->Reset_guess();
    pinstProjectileCamera_guess->Reset_guess();
}

// FUNCTION: TITANIUM 0x0043745D
// World display flag (see the field).
int CDisplay_guess::GetValue2cf8_guess() {
    return value_2cf8_guess;
}

// True once the particle emitter definitions loaded (+0x2D00, set by 0x004379F1).
// FUNCTION: TITANIUM 0x00437464
int CDisplay_guess::GetValue2d00_guess() {
    return particlesInitialized_2d00_guess;
}

struct LightService_guess {
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
    virtual void Register_guess(const char* name, int type, int count, int* table, float* colors,
                                int first, int intensity, int second, int* output);
};

#define g_lightService_guess EQ_GLOBAL(LightService_guess*, 0x0099E360)

// FUNCTION: TITANIUM 0x0043746B
// Registers the nine carried-light definitions; both 10-entry tables hold 0x3F7FF972, which is 0.9999f.
void CDisplay_guess::InitCommonLights_guess() {
    float lanternColor_guess[3] = {
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040)
    };
    float torchColors_guess[30] = {
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        0.957f, EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040),
        EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642044), EQ_GLOBAL(float, 0x00642040)
    };
    int* firstTable_guess = EQ_ARRAY(int, 0x00850D38);
    for (int i_guess = 0; i_guess < 10; ++i_guess) {
        firstTable_guess[i_guess] = 0x3f7ff972;
    }
    int* secondTable_guess = EQ_ARRAY(int, 0x00850D10);
    for (int i_guess = 0; i_guess < 10; ++i_guess) {
        secondTable_guess[i_guess] = 0x3f7ff972;
    }

    g_lightService_guess->Register_guess("torch", 1, 10, secondTable_guess, torchColors_guess,
                                         0, 200, 0, &torchLight_2870_guess);
    g_lightService_guess->Register_guess("candle", 1, 10, secondTable_guess, torchColors_guess,
                                         0, 200, 0, &candleLight_2888_guess);
    g_lightService_guess->Register_guess("smlantern", 1, 1, firstTable_guess, lanternColor_guess,
                                         0, 200, 0, &smLanternLight_2878_guess);
    g_lightService_guess->Register_guess("lglantern", 1, 1, secondTable_guess, lanternColor_guess,
                                         0, 200, 0, &lgLanternLight_287c_guess);

    float magicColors_guess[30] = {
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642010), EQ_GLOBAL(float, 0x00642010),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), 0.9012f, EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), 0.9031f, EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048),
        EQ_GLOBAL(float, 0x00642014), EQ_GLOBAL(float, 0x00642048), EQ_GLOBAL(float, 0x00642048)
    };
    g_lightService_guess->Register_guess("magtorch", 1, 10, secondTable_guess, magicColors_guess,
                                         0, 200, 0, &magTorchLight_2874_guess);
    g_lightService_guess->Register_guess("smmagic", 1, 1, secondTable_guess, magicColors_guess,
                                         0, 200, 0, &smMagicLight_2880_guess);
    g_lightService_guess->Register_guess("lgmagic", 1, 1, secondTable_guess, magicColors_guess,
                                         0, 200, 0, &lgMagicLight_2884_guess);

    float redColors_guess[30] = {
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f,
        EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x00641FF0), 0.0f
    };
    g_lightService_guess->Register_guess("redlight", 1, 1, secondTable_guess, redColors_guess,
                                         0, 200, 0, &redLight_288c_guess);

    float blueColors_guess[30] = {
        EQ_GLOBAL(float, 0x00641FE0), 0.2f, EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC),
        EQ_GLOBAL(float, 0x00641FE0), EQ_GLOBAL(float, 0x00640FEC), EQ_GLOBAL(float, 0x006410BC)
    };
    g_lightService_guess->Register_guess("blueLight", 1, 1, secondTable_guess, blueColors_guess,
                                         0, 200, 0, &blueLight_2890_guess);
}

// FUNCTION: TITANIUM 0x00437915
// Race name as eqclient.ini spells it ("UseLuclin<Race>Male"); a static buffer.
char* __stdcall GetIniRaceName_guess(int race_guess) {
    if (race_guess <= 0x80) {
        if (race_guess != Race_Iksar) {
            switch (race_guess) {
            case Race_Human: strcpy(EQ_ARRAY(char, 0x00850D60), "Human"); break;
            case Race_Barbarian: strcpy(EQ_ARRAY(char, 0x00850D60), "Barbarian"); break;
            case Race_Erudite: strcpy(EQ_ARRAY(char, 0x00850D60), "Erudite"); break;
            case Race_WoodElf: strcpy(EQ_ARRAY(char, 0x00850D60), "WoodElf"); break;
            case Race_HighElf: strcpy(EQ_ARRAY(char, 0x00850D60), "HighElf"); break;
            case Race_DarkElf: strcpy(EQ_ARRAY(char, 0x00850D60), "DarkElf"); break;
            case Race_HalfElf: strcpy(EQ_ARRAY(char, 0x00850D60), "HalfElf"); break;
            case Race_Dwarf: strcpy(EQ_ARRAY(char, 0x00850D60), "Dwarf"); break;
            case Race_Troll: strcpy(EQ_ARRAY(char, 0x00850D60), "Troll"); break;
            case Race_Ogre: strcpy(EQ_ARRAY(char, 0x00850D60), "Ogre"); break;
            case Race_Halfling: strcpy(EQ_ARRAY(char, 0x00850D60), "Halfling"); break;
            case Race_Gnome: strcpy(EQ_ARRAY(char, 0x00850D60), "Gnome"); break;
            default: strcpy(EQ_ARRAY(char, 0x00850D60), "Unknown"); break;
            }
        } else {
            strcpy(EQ_ARRAY(char, 0x00850D60), "Iksar");
        }
    } else {
        if (race_guess != Race_VahShir) {
            if (race_guess != Race_Froglok) {
                strcpy(EQ_ARRAY(char, 0x00850D60), "Unknown");
            } else {
                strcpy(EQ_ARRAY(char, 0x00850D60), "Froglok");
            }
        } else {
            strcpy(EQ_ARRAY(char, 0x00850D60), "VahShir");
        }
    }
    return EQ_ARRAY(char, 0x00850D60);
}

// Loads the particle emitter definitions; on success sets +0x2D00, else logs
// the LoadEmitterDefinitions failure.
// FUNCTION: TITANIUM 0x004379F1
void CDisplay_guess::InitParticleSystem_guess() {
    if (g_particleSystem_guess->LoadEmitterDefinitions_guess() < 0) {
        FUN_00574110_guess("g_pGfx_ParticleSystem->LoadEmitterDefinitions() failed.\n");
        return;
    }
    particlesInitialized_2d00_guess = 1;
}

// The display-options step of 0x00443F8F: starts the graphics engine (0x0099E38C, mode 0) and
// returns its code in *result for the log line, then caches engine values +0x20, +0x24 and its two getters
// in 0x009237A4, 0x009237A8, 0x0092379C and 0x009237A0.
// FUNCTION: TITANIUM 0x00437A1B
void CDisplay_guess::SetDisplayOptions_guess(int* result) {
    *result = g_graphicsState_guess->Initialize_guess(0);
    g_graphicsValue0_guess = g_graphicsState_guess->value_0020_guess;
    g_graphicsValue1_guess = g_graphicsState_guess->value_0024_guess;
    g_graphicsValue2_guess = g_graphicsState_guess->GetFirst_guess();
    g_graphicsValue3_guess = g_graphicsState_guess->GetSecond_guess();
}

// FUNCTION: TITANIUM 0x00437A61
// Writes the resolution to eqclient.ini: width, height, refresh and depth in full screen, else the
// windowed width and height. The section and key names are in the .rdata strings at 0x00642110-0x00642174.
void CDisplay_guess::StoreDisplayOptions_guess() {
    int width = g_graphicsState_guess->GetFirst_guess();
    int height = g_graphicsState_guess->GetSecond_guess();
    int refresh = g_screenshotOutput_guess->Slot07_guess();
    int bitsPerPixel = g_screenshotOutput_guess->Slot06_guess();
    char value[32];

    if (g_graphicsState_guess->fullscreen_0004_guess != 0) {
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), width);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642174), value, EQ_ARRAY(char, 0x006412E4));
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), height);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642160), value, EQ_ARRAY(char, 0x006412E4));
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), refresh);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642148), value, EQ_ARRAY(char, 0x006412E4));
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), bitsPerPixel);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642130), value, EQ_ARRAY(char, 0x006412E4));
    } else {
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), width);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642120), value, EQ_ARRAY(char, 0x006412E4));
        sprintf(value, EQ_ARRAY(char, 0x0063F53C), height);
        FUN_0060beb0_guess(EQ_ARRAY(char, 0x00642168), EQ_ARRAY(char, 0x00642110), value, EQ_ARRAY(char, 0x006412E4));
    }
}

struct ExtendedCopy_guess {
    int value_0000_guess;
    int values_0004_guess[13];
    int value_0038_guess;
    int value_003c_guess;
    int value_0040_guess;
    int value_0044_guess;
    ExtendedCopy_guess* CopyFrom_guess(const ExtendedCopy_guess* source);
};

// Assignment: the string at +0 (0x00571F70) and the 17 ints after it.
// FUNCTION: TITANIUM 0x00437B89
ExtendedCopy_guess* ExtendedCopy_guess::CopyFrom_guess(const ExtendedCopy_guess* source) {
    Retain_guess((const CopyBlock_guess*)source);
    for (int i = 0; i < 13; ++i) {
        values_0004_guess[i] = source->values_0004_guess[i];
    }
    value_0038_guess = source->value_0038_guess;
    value_003c_guess = source->value_003c_guess;
    value_0040_guess = source->value_0040_guess;
    value_0044_guess = source->value_0044_guess;
    return this;
}

struct CleanupService_guess {
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
    virtual void Deactivate();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004FAABA CleanupService_guess::Help_guess
    void Help_guess();
    // EXTERNAL: TITANIUM 0x0052B026 CleanupService_guess::FinishLoot_guess
    void FinishLoot_guess();
    // EXTERNAL: TITANIUM 0x004DC160 CleanupService_guess::CloseBank_guess
    void CloseBank_guess(char enabled_guess);
    // EXTERNAL: TITANIUM 0x004F21D6 CleanupService_guess::FUN_004f21d6_guess
    void FUN_004f21d6_guess();
    // EXTERNAL: TITANIUM 0x0051E180 CleanupService_guess::CloseAllItemDisplays_guess
    void CloseAllItemDisplays_guess();
    // EXTERNAL: TITANIUM 0x00548256 CleanupService_guess::ExpireAll_guess
    void ExpireAll_guess();
    // EXTERNAL: TITANIUM 0x005242E8 CleanupService_guess::SaveJournal_guess
    void SaveJournal_guess();
    // EXTERNAL: TITANIUM 0x00503020 CleanupService_guess::LoopAndClear_guess
    void LoopAndClear_guess();
};

struct ApplyManagerState_guess {
    unsigned char pad_0000_guess[0x84];
    int value_0084_guess;
};

#define g_cleanup_00850CBC_guess EQ_GLOBAL(CleanupService_guess*, 0x00850CBC)
#define g_cleanup_00850C38_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C38)
#define g_cleanup_00850C34_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C34)
#define g_cleanup_00850C30_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C30)
#define g_cleanup_00850C2C_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C2C)
#define g_cleanup_0099D414_guess EQ_GLOBAL(CleanupService_guess*, 0x0099D414)
#define g_cleanup_009917E4_guess EQ_GLOBAL(CleanupService_guess*, 0x009917E4)
#define g_cleanup_00850C18_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C18)
#define g_cleanup_00850C1C_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C1C)
#define g_cleanup_00991B88_guess EQ_GLOBAL(CleanupService_guess*, 0x00991B88)
#define g_cleanup_00991E44_guess EQ_GLOBAL(CleanupService_guess*, 0x00991E44)
#define g_cleanup_00850BE0_guess EQ_GLOBAL(CleanupService_guess*, 0x00850BE0)
#define g_cleanup_00991A74_guess EQ_GLOBAL(CleanupService_guess*, 0x00991A74)
#define g_cleanup_00850C08_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C08)
#define g_cleanupTargets_guess EQ_ARRAY(CleanupService_guess*, 0x00991AE4)
#define g_cleanup_00850C10_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C10)
#define g_cleanup_00850BA0_guess EQ_GLOBAL(CleanupService_guess*, 0x00850BA0)
#define g_cleanup_00850C44_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C44)
#define g_cleanup_00850C48_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C48)
#define g_cleanup_00850C54_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C54)
#define g_cleanup_00850C88_guess EQ_GLOBAL(CleanupService_guess*, 0x00850C88)
#define g_cleanup_00850CA0_guess EQ_GLOBAL(CleanupService_guess*, 0x00850CA0)
#define g_cleanup_0079C148_guess EQ_GLOBAL(CleanupService_guess*, 0x0079C148)
#define g_cleanup_0099283C_guess EQ_GLOBAL(CleanupService_guess*, 0x0099283C)
#define g_cleanupByte_guess EQ_GLOBAL(unsigned char, 0x00991680)
#define g_cleanupApplyManager_guess EQ_GLOBAL(ApplyManagerState_guess*, 0x0099D3EC)

#define CLEANUP_DEACTIVATE_GUESS(service) \
    if ((service) != 0) { \
        (service)->Deactivate(); \
    }

// Hides every game window that exists before the UI is rebuilt (the deactivate-previous-UI step of the
// reload); the globals stay set so the windows are reused.
// FUNCTION: TITANIUM 0x00437BCD
// @early-stop: budget, diff ndiff=3
void CDisplay_guess::DeactivateMainUI_guess() {
    if (g_cleanup_00850CBC_guess != 0) {
        g_cleanup_00850CBC_guess->Help_guess();
    }
    CLEANUP_DEACTIVATE_GUESS(pinstCSocialEditWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCInspectWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTrackingWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGemsGameWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTitleWnd_guess)
    if (pinstCBazaarWnd_guess != 0) {
        unsigned char saved_guess = g_cleanupByte_guess;
        pinstCBazaarWnd_guess->Deactivate();
        g_cleanupByte_guess = saved_guess;
    }
    CLEANUP_DEACTIVATE_GUESS(pinstCBazaarSearchWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTradeWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGiveWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCMerchantWnd_guess)
    // LootWnd (0x850C40) and BankWnd (0x850C38) close through their own calls instead of Deactivate.
    if (pinstCLootWnd_guess != 0) {
        pinstCLootWnd_guess->FinishLoot_guess();
    }
    if (g_cleanup_00850C38_guess != 0) {
        g_cleanup_00850C38_guess->CloseBank_guess(0);
    }
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C34_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C30_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C2C_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCCastingWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCCursorAttachment_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_0099D414_guess)
    if (g_cleanup_009917E4_guess != 0) {
        g_cleanup_009917E4_guess->FUN_004f21d6_guess();
    }
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C18_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C1C_guess)
    if (g_cleanup_00991B88_guess != 0) {
        g_cleanup_00991B88_guess->CloseAllItemDisplays_guess();
    }
    if (g_cleanup_00991E44_guess != 0) {
        g_cleanup_00991E44_guess->ExpireAll_guess();
    }
    CLEANUP_DEACTIVATE_GUESS(pinstCNoteWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTipWndCONTEXT_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTipWndOFDAY_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBookWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCFriendsWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCRespawnWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBandolierWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCPotionBeltWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850BE0_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAlarmWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCLoadskinWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCPetInfoWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTrainWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCSkillsWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCSkillsSelectWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCCombatSkillSelectWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAAWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00991A74_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGroupSearchWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGroupSearchFiltersWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCRaidWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCRaidOptionsWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBreathWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCMapViewWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCMapToolbarWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCEditLabelWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C08_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCColorPickerWnd_guess)
    CleanupService_guess** entry_guess = g_cleanupTargets_guess;
    do {
        CLEANUP_DEACTIVATE_GUESS(*entry_guess)
        ++entry_guess;
    } while ((int)entry_guess < (int)(g_cleanupTargets_guess + 4));
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C10_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCEQMainWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850BA0_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCQuantityWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTextEntryWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCFileSelectionWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C44_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C48_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C54_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850C88_guess)
    if (pinstCJournalNPCWnd_guess != 0) {
        pinstCJournalNPCWnd_guess->SaveJournal_guess();
        pinstCJournalNPCWnd_guess->Deactivate();
    }
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_00850CA0_guess)
    if (pinstCFindLocationWnd_guess != 0) {
        pinstCFindLocationWnd_guess->LoopAndClear_guess();
        pinstCFindLocationWnd_guess->Deactivate();
    }
    if (pinstCLargeDialogWnd_guess != 0) {
        pinstCLargeDialogWnd_guess->Show(0, 1);
    }
    CLEANUP_DEACTIVATE_GUESS(pinstCBodyTintWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGuildManagementWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCPointMerchantWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAdventureRequestWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCPvpLeaderboardWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCPvPStatsWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAdventureStatsWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAdventureLeaderboardWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_0079C148_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTradeskillWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCDynamicZoneWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCLeadershipWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTicketWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTicketCommentWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCItemExpTransferWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAltStorageWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTributeBenefitWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTaskWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBarterWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBarterMerchantWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCBarterSearchWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCLFGuildWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGuildBankWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCVoiceMacroWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTaskSelectWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCTributeMasterWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCGuildTributeMasterWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCServerListWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(g_cleanup_0099283C_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCProgressionSelectionWnd_guess)
    CLEANUP_DEACTIVATE_GUESS(pinstCAvaZoneWnd_guess)
    g_cleanupApplyManager_guess->value_0084_guess = 0;
}

// FUNCTION: TITANIUM 0x00439546
// Light type (as CreateLightInstance takes it) to an intensity rank 0-10, brighter lights higher.
// The ranking is inferred from the light ranges.
unsigned char Mapping_guess::GetIntensity_guess(unsigned char value) {
    switch (value) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 9: return 3;
    case 12:
    case 14: return 4;
    case 13:
    case 15: return 5;
    case 4: return 6;
    case 5:
    case 10: return 7;
    case 6: return 8;
    case 7:
    case 11: return 9;
    case 8: return 10;
    default: return 0;
    }
}

// Deletes light `value` through the graphics engine (virtual +0x60), only while the world display is up
// (+0x2CF8).
// FUNCTION: TITANIUM 0x004395C4
void CDisplay_guess::DeleteLight_guess(int value) {
    if ((value_2cf8_guess != 0) && (value != 0)) {
        return g_service_guess->Slot24_guess(value);
    }
}

// FUNCTION: TITANIUM 0x004395E2
// Plays sound `value3` at (value0, value1, value2); 0x40A00000 and 0x42A00000 are 5.0f and 80.0f,
// probably the near and far distances.
void __stdcall PlaySoundAtLocation_guess(int value0, int value1, int value2, int value3) {
    Params_guess params;
    params.value_0010_guess = value0;
    params.value_0014_guess = value1;
    params.value_0018_guess = value2;
    params.value_001c_guess = 0x40a00000;
    params.value_0020_guess = 0x42a00000;
    params.value_0028_guess = 0;
    g_queue_guess->WavePlay_guess(value3, &params);
}

struct Entry_guess {
    int value_0000_guess;
    int value_0004_guess;
};

struct EntryTable_guess {
    Entry_guess* entries_0000_guess;
    int count_0004_guess;
    void FreeAll_guess();
    int GetValue_guess(int index);
    int GetOther_guess(int index);
};

struct Slots_guess {
    Entry_guess* entries_0000_guess;
    int count_0004_guess;
    void LoadFromFile_guess(const char* filename);
    Slots_guess* Init_guess(const char* filename);
};

struct EntryFile_guess {
    unsigned char storage_0000_guess[0x1000c];
    // EXTERNAL: TITANIUM 0x00576BD0 EntryFile_guess::EntryFile_guess
    EntryFile_guess(const char* filename, int separator);
    // EXTERNAL: TITANIUM 0x00576D10 EntryFile_guess::IsOpen_guess
    char IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 EntryFile_guess::Next_guess
    int Next_guess();
    // EXTERNAL: TITANIUM 0x00576F50 EntryFile_guess::Read_guess
    void Read_guess(char* buffer, int size);
    // EXTERNAL: TITANIUM 0x00576C50 EntryFile_guess::~EntryFile_guess
    ~EntryFile_guess();
};

struct PickOwner_guess;

struct PickInfo_guess {
    int id_0000_guess;
    unsigned char pad_0004_guess[0x15c - 0x4];
    PickOwner_guess* owner_015c_guess;
};

struct PickOwner_guess {
    unsigned char pad_0000_guess[0x1a8];
    PickInfo_guess* info_01a8_guess;
};

struct PickActor_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual bool IsHidden_guess();
};

struct PickQuery_guess {
    void* actor;
    int id;
    int ownerId;
};

#define g_pickOwner_guess EQ_GLOBAL(PickOwner_guess*, 0x00905CE4)
#define g_pickDisabled_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_pickId_guess EQ_GLOBAL(int, 0x00850CC4)

// FUNCTION: TITANIUM 0x0043962A
// @early-stop: budget, structural ndiff=32
// 0x00850CCC is the camera mode (SetCameraMode writes it). In first person (0) the view actor (0x00850CC4)
// and its owner's id go to the engine, probably so the pick skips them. x, y are window coordinates.
void* CDisplay_guess::GetClickedActor(int x, int y, int type, int first, int second) {
    PickQuery_guess query = { 0, 0, 0 };
    if (value_2cf8_guess != 1) {
        return 0;
    }
    if (g_pickDisabled_guess == 0) {
        query.id = g_pickId_guess;
        if (g_pickOwner_guess != 0) {
            PickInfo_guess* info = g_pickOwner_guess->info_01a8_guess;
            if (info != 0 && info->id_0000_guess == query.id) {
                PickOwner_guess* owner = info->owner_015c_guess;
                if (owner != 0) {
                    PickInfo_guess* ownerInfo = owner->info_01a8_guess;
                    if (ownerInfo != 0 && ownerInfo->id_0000_guess != 0) {
                        query.ownerId = ownerInfo->id_0000_guess;
                    }
                }
            }
        }
    }
    int status = g_service_guess->Slot32_guess(callback_0118_guess, query.id, query.ownerId, x - g_value2d04_guess,
                                               y - g_value2d08_guess, type, &query.actor, first, second);
    return status ? 0 : query.actor;
}

// Returns the visible actor under screen point x,y (or null). With `select`, hands it and the local
// player to 0x0048C285, which climbs a clicked ladder (type 6) when close enough.
// FUNCTION: TITANIUM 0x004396DF
PickActor_guess* CDisplay_guess::PickActorAt_guess(int x, int y, bool select, int first, int second) {
    PickActor_guess* actor = (PickActor_guess*)GetClickedActor(x, y, 2, first, second);
    bool hidden = actor == 0 || actor->IsHidden_guess();
    if (hidden) {
        return 0;
    }
    if (select) {
        GetOnActor_guess(actor, g_pickOwner_guess);
    }
    return actor;
}

// EXTERNAL: TITANIUM 0x00574830 NumericTail_guess
int __cdecl NumericTail_guess(const char* text, int base);
// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" size_t __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x00621E9C _stricmp
extern "C" int __cdecl _stricmp(const char* left, const char* right);
// EXTERNAL: TITANIUM 0x0062202C _strnicmp
extern "C" int __cdecl _strnicmp(const char* left, const char* right, size_t count);
// EXTERNAL: TITANIUM 0x0060E460 AppendString_guess
void __cdecl AppendString_guess(char* destination, const char* source);

struct ActorDef_guess {
    virtual void Slot00_guess();
    virtual float Slot01_guess();
};

struct WorldRef_guess {
    unsigned char pad_0000_guess[0x204];
    int zone_0204_guess;
};

struct ActorInstance_guess {
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
    virtual void Slot12_guess(int value);
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess(Vector3_guess* value);
    virtual void Slot19_guess(Vector3_guess* value);
};

#define g_worldA_guess EQ_GLOBAL(WorldRef_guess*, 0x00905CE4)
#define g_worldB_guess EQ_GLOBAL(WorldRef_guess*, 0x00905CC4)

// FUNCTION: TITANIUM 0x0043972A
// @early-stop: budget, structural ndiff=72
// Places an item or object actor (<name>_ACTORDEF). Missing models fall back to IT63, then RED_BLOB.
// Some IT models are rescaled: 0.8 for IT70/IT74 in rivervale, akanon, kaladima and kaladimb (0x13, 0x37,
// 0x3C, 0x43), else 1.5 or 1.3; BBBOARD 1.5. IT66-IT76 of that set also clear useFlag.
ActorInstance_guess* CDisplay_guess::CreateActor_guess(char* name, float x, float y, float z, float x2, float y2,
    float height, bool allowFallback, bool useFlag) {
    ActorDef_guess* def;
    int flag;
    ActorInstance_guess* instance;
    CDisplay_guess* self = this;
    def = 0;
    instance = 0;
    flag = useFlag;
    if (value_2cf8_guess != 0) {
    if (strlen(name) < 10 && _stricmp(name, "PLAYER_1") != 0) {
        AppendString_guess(name, "_ACTORDEF");
    }
    g_languageService_guess->Slot02_guess(name, &def);
    if (def == 0) {
        if (allowFallback) {
        strcpy(name, "IT63_ACTORDEF");
        g_languageService_guess->Slot02_guess(name, &def);
        if (def == 0) {
            strcpy(name, "RED_BLOB_ACTORDEF");
            g_languageService_guess->Slot02_guess(name, &def);
            if (def == 0) {
                return 0;
            }
        }
        } else {
            return 0;
        }
    }
    float factor = 1.0f;
    WorldRef_guess* world = g_worldA_guess;
    if (world == 0) {
        world = g_worldB_guess;
    }
    int zone = world == 0 ? 0 : world->zone_0204_guess;
    if (zone == 0x3c || zone == 0x43 || zone == 0x13 || zone == 0x37) {
        if (_strnicmp(name, "IT70", 4) == 0 || _strnicmp(name, "IT74", 4) == 0) {
            factor = 0.8f;
        }
    } else {
        if (_strnicmp(name, "IT66", 4) == 0 || _strnicmp(name, "IT69", 4) == 0 || _strnicmp(name, "IT73", 4) == 0) {
            factor = 1.5f;
        } else if (_strnicmp(name, "IT74", 4) == 0) {
            factor = 1.3f;
        }
    }
    if (_strnicmp(name, "BBBOARD", 7) == 0) {
        factor = 1.5f;
    }
    float dist = def->Slot01_guess() * factor;
    int mode = 0;
    float nearValue_guess = 0.0f;
    if (_strnicmp(name, "IT", 2) == 0 && NumericTail_guess(name + 2, 0) != 0) {
        if (_strnicmp(name, "IT66", 4) == 0 || _strnicmp(name, "IT69", 4) == 0 ||
            _strnicmp(name, "IT70", 4) == 0 || _strnicmp(name, "IT73", 4) == 0 ||
            _strnicmp(name, "IT74", 4) == 0 || _strnicmp(name, "IT76", 4) == 0) {
            flag = 0;
        }
    }
    if (flag == 0) {
        if (height == 0.0f) {
            mode = 1;
        } else {
            mode = 2;
            nearValue_guess = height;
        }
    }
    self->lastUpdateTime_0150_guess = 0;
    Vector3_guess position;
    position.x_0000_guess = x;
    position.y_0004_guess = y;
    position.z_0008_guess = z;
    Vector3_guess second;
    second.x_0000_guess = x2;
    second.y_0004_guess = y2;
    second.z_0008_guess = 0.0f;
    int status = g_service_guess->Slot17_guess(def, &position, &second, mode, nearValue_guess, factor, dist, 0, 0, 0, 0, &instance);
    if (status != -1) {
        instance->Slot12_guess(flag != 0 ? 3 : 2);
        instance->Slot18_guess(&position);
        instance->Slot19_guess(&second);
    }
    }
    return instance;
}

// EXTERNAL: TITANIUM 0x0042D123 FUN_0042d123_guess
int __cdecl FUN_0042d123_guess(void* object);
// EXTERNAL: TITANIUM 0x0042CF5C FUN_0042cf5c_guess
void __cdecl FUN_0042cf5c_guess();
typedef int (__cdecl *QueryFilter_guess)(void* object);
typedef void (__cdecl *QueryCallback_guess)();

struct CollisionQuery_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual int Query_guess(Vector3_guess* from, Vector3_guess* to, float radius, QueryFilter_guess filter,
        QueryCallback_guess callback, int zero0, Vector3_guess* hit, Vector3_guess* normal, int* flag,
        int zero1, int one);
};

#define g_collisionQuery_guess EQ_GLOBAL(CollisionQuery_guess*, 0x0099E370)

// FUNCTION: TITANIUM 0x0043A0A0
// Ceiling above (x, y, z), or -1.0e27 when there is none or the point is outside the world.
float CDisplay_guess::GetCeilingHeight_guess(float x, float y, float z, float scale) {
    int flag;
    float result = 0.0f;
    if (value_2cf8_guess != 0) {
        Vector3_guess from;
        from.x_0000_guess = x;
        from.y_0004_guess = y;
        from.z_0008_guess = z;
        if (g_actorReceiver_guess->Slot12_guess(&from)) {
            Vector3_guess to;
            to.x_0000_guess = x;
            to.y_0004_guess = y;
            to.z_0008_guess = 32767.0f;
            float radius = scale * value_2d14_guess;
            Vector3_guess hit;
            Vector3_guess normal;
            if (g_collisionQuery_guess->Query_guess(&from, &to, radius, FUN_0042d123_guess, FUN_0042cf5c_guess, 0,
                    &hit, &normal, &flag, 0, 1) == 0) {
                if (!(hit.z_0008_guess + radius < radius + z)) {
                    return hit.z_0008_guess + radius;
                }
            }
        }
        result = -1.0e27f;
    }
    return result;
}

struct TraceRequest_guess {
    int value_0000_guess[3];
    float value_000c_guess[3];
};

struct TraceFrame_guess {
    int resultData_0000_guess[3];
    TraceRequest_guess request_000c_guess;
    float hit_0024_guess[3];
    unsigned char pad_0030_guess;
    unsigned char pad_0031_guess;
    unsigned char pad_0032_guess;
    unsigned char result_0033_guess;
};

typedef void (__cdecl *TraceCallback_guess)();

// EXTERNAL: TITANIUM 0x0042CF5C TraceCallback0042cf5c_guess
void __cdecl TraceCallback0042cf5c_guess();
// EXTERNAL: TITANIUM 0x0042CF6E TraceCallback0042cf6e_guess
void __cdecl TraceCallback0042cf6e_guess();
// EXTERNAL: TITANIUM 0x0042D109 TraceCallback0042d109_guess
void __cdecl TraceCallback0042d109_guess();
// EXTERNAL: TITANIUM 0x0056F736 FUN_0056f736_guess
void __cdecl FUN_0056f736_guess();

struct TraceService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual int Slot09_guess(int* request, float* origin, float value, TraceCallback_guess callback,
                             TraceCallback_guess callback2, int zero, float* output, int* result,
                             unsigned char* mode, int zero2, int zero3);
};

#define g_traceService_guess EQ_GLOBAL(TraceService_guess*, 0x0099E370)

// FUNCTION: TITANIUM 0x0043A15C
// @early-stop: budget, structural ndiff=14
// Returns 0 when the sphere reached its target (hit point within 0.01 of it), 1 when it collided.
// `mode` picks the collision filter; modes 2 and 3 share one.
unsigned char CDisplay_guess::s3dCollideSphereWithWorld_guess(int value0, int value1, int value2, float x, float y, float z,
                                                float* outX, float* outY, float* outZ, unsigned char mode) {
    TraceFrame_guess frame;
    frame.result_0033_guess = 1;
    if (value_2cf8_guess != 0) {
        frame.request_000c_guess.value_0000_guess[0] = value0;
        frame.request_000c_guess.value_0000_guess[1] = value1;
        frame.request_000c_guess.value_0000_guess[2] = value2;
        frame.request_000c_guess.value_000c_guess[0] = x;
        frame.request_000c_guess.value_000c_guess[1] = y;
        frame.request_000c_guess.value_000c_guess[2] = z;
        TraceCallback_guess callback;
        if (mode == 2) {
            callback = TraceCallback0042d109_guess;
        } else if (mode == 3) {
            callback = TraceCallback0042d109_guess;
        } else {
            callback = FUN_0056f736_guess;
            if (mode == 0) {
                callback = TraceCallback0042cf6e_guess;
            }
        }
        int status = g_traceService_guess->Slot09_guess(&frame.request_000c_guess.value_0000_guess[0],
                                                        &frame.request_000c_guess.value_000c_guess[0], value_2d14_guess,
                                                        callback, TraceCallback0042cf5c_guess, 0,
                                                        &frame.hit_0024_guess[0], &frame.resultData_0000_guess[0],
                                                        &mode, 0, 0);
        if (status == 0) {
            if (outX != 0) {
                *outX = frame.hit_0024_guess[0];
            }
            if (outY != 0) {
                *outY = frame.hit_0024_guess[1];
            }
            if (outZ != 0) {
                *outZ = frame.hit_0024_guess[2];
            }
            if (_fabs((double)(frame.hit_0024_guess[0] - x)) < 0.01f) {
                if (_fabs((double)(frame.hit_0024_guess[1] - y)) < 0.01f) {
                    if (_fabs((double)(frame.hit_0024_guess[2] - z)) < 0.01f) {
                        frame.result_0033_guess = 0;
                    }
                }
            }
        }
    }
    return frame.result_0033_guess;
}

// FUNCTION: TITANIUM 0x0043A292
// Region flags at a point (see ParseRegionName_guess); sets *flag for teleport regions (bit 31).
int CDisplay_guess::GetEnvironment_guess(float value0, float value1, float value2, int* flag) {
    int result = g_service_guess->Slot03_guess(value0, value1, value2, 0);
    if ((flag != 0) && ((result & 0x80000000) != 0)) {
        *flag = 1;
    }
    return result;
}

// FUNCTION: TITANIUM 0x0043A2CE
// Snaps every spawn to the floor under it (1.0 when there is none).
void ActorUpdateManager_guess::SetupEQPlayers_guess() {
    ActorUpdateNode_guess* actor = g_actorUpdateHead_guess;
    for (; actor != 0; actor = actor->next_0214_guess) {
        if (actor->data_01a8_guess != 0) {
            float z = actor->value_0038_guess;
            FloatBits x;
            x.bits = actor->value_0030_guess.bits;
            float y = actor->value_0034_guess;
            actor->data_01a8_guess->floorHeight_0048_guess =
                g_coordinateService_guess->GetFloorHeight_guess(
                    x.value, y, z + 1.0f);
            if (actor->data_01a8_guess->floorHeight_0048_guess == -1.0e27f) {
                actor->data_01a8_guess->floorHeight_0048_guess = 1.0f;
            }
            actor->data_01a8_guess->value_0050_guess = 0;
            actor->data_01a8_guess->lastUpdateTime_0ebc_guess = FUN_0046d655_guess();
        }
    }
}

// Moves the handler to `position` (vtable slot 6) only when it is more than 0.1 away from where it is now,
// measured with the cheap |dx| + |dy| + |dz| distance (0x00439BD1), so tiny moves cause no update.
// FUNCTION: TITANIUM 0x0043A371
void ActorUpdateManager_guess::ComparePosition_guess(PositionHandler_guess* handler, Vector3_guess* position) {
    float values[3];
    handler->GetValues_guess(values);
    float difference = g_coordinateService_guess->SimpleDistance_guess(
        values[0], values[1], values[2],
        position->x_0000_guess, position->y_0004_guess, position->z_0008_guess, 1.0f);
    if (difference > 0.1f) {
        handler->Update_guess(position);
    }
}

// Frees a two-column text table read by 0x0043A41B (such as the zone's <zone>_pre_chr.txt NPC list):
// both strings of every row, then the row array; the table is left empty.
// FUNCTION: TITANIUM 0x0043A3E1
void EntryTable_guess::FreeAll_guess() {
    for (int i = 0; i < count_0004_guess; ++i) {
        free((void*)entries_0000_guess[i].value_0000_guess);
        free((void*)entries_0000_guess[i].value_0004_guess);
    }
    free(entries_0000_guess);
    entries_0000_guess = 0;
    count_0004_guess = 0;
}

// FUNCTION: TITANIUM 0x0043A41B
// @early-stop: budget, diff ndiff=2
// A comma-separated file: a count line (1-999), then name pairs.
void Slots_guess::LoadFromFile_guess(const char* filename) {
    EntryFile_guess* file = new EntryFile_guess(filename, 0x2c);
    int index = 0;
    char countText[0x20];
    char firstText[0x100];
    char secondText[0x100];

    if (file->IsOpen_guess() != 0) {
        file->Next_guess();
        file->Read_guess(countText, 0x20);
        int parsedCount = atoi(countText);
        count_0004_guess = parsedCount;
        if (parsedCount <= index || parsedCount >= 1000) {
            FUN_00574110_guess("Bad file: %s", filename);
        } else {
            entries_0000_guess = new Entry_guess[count_0004_guess];
            memset(entries_0000_guess, index, count_0004_guess << 3);
            char badFile = 0;
            int result = file->Next_guess();
            if (result > 0) {
                do {
                    file->Read_guess(firstText, 0x100);
                    file->Read_guess(secondText, 0x100);
                    if (firstText[0] != 0) {
                        if (index >= count_0004_guess) {
                            badFile = 1;
                            break;
                        }
                        int offset = index << 3;
                        entries_0000_guess[index].value_0000_guess =
                            (int)new char[strlen(firstText) + 1];
                        strcpy((char*)entries_0000_guess[index].value_0000_guess, firstText);
                        entries_0000_guess[index].value_0004_guess =
                            (int)new char[strlen(secondText) + 1];
                        strcpy((char*)entries_0000_guess[index].value_0004_guess, secondText);
                        ++index;
                    } else {
                        --count_0004_guess;
                        badFile = 1;
                    }
                    result = file->Next_guess();
                } while (result > 0);
            }
            if (badFile != 0 || count_0004_guess != index) {
                FUN_00574110_guess("Bad file: %s (%d, %d)", filename, index, count_0004_guess);
                if (index < count_0004_guess) {
                    count_0004_guess = index;
                }
            }
        }
    }
    delete file;
}

struct IndexedTable_guess {
    unsigned char pad_0000_guess[0x1c];
    int values_001c_guess[1001];
    int Get_guess(int index);
};

// First value of entry `index` of the name-pair list; 0 out of range.
// FUNCTION: TITANIUM 0x0043A61D
int EntryTable_guess::GetValue_guess(int index) {
    if ((index < 0) || (index >= count_0004_guess)) {
        return 0;
    }
    return entries_0000_guess[index].value_0000_guess;
}

// Second value of entry `index` of the name-pair list; 0 out of range.
// FUNCTION: TITANIUM 0x0043A636
int EntryTable_guess::GetOther_guess(int index) {
    if ((index < 0) || (index >= count_0004_guess)) {
        return 0;
    }
    return entries_0000_guess[index].value_0004_guess;
}

struct Interface008503A8_guess {
    virtual void Slot00_guess(const char* value);
    virtual void Slot01_guess();
    virtual void Slot02_guess(const char* value, float amount);
};

struct LabelOwner_guess {
    unsigned char pad_0000_guess[0x2d28];
    Text_guess text_2d28_guess;
    void SetLabel_guess(const char* value);
};

struct NameBuffer_guess {
    char text_0000_guess[0x20];
};

#define g_interface008503A8_guess EQ_GLOBAL(Interface008503A8_guess*, 0x008503A8)
#define g_nameBuffer_guess EQ_GLOBAL(NameBuffer_guess, 0x00923C3C)
#define g_nameBuffer2_guess EQ_GLOBAL(NameBuffer_guess, 0x00923C5C)

// FUNCTION: TITANIUM 0x0043A650
// Probably the sky name ("Default" at start), the companion of SetSecondarySkyName; kept in 0x00923C3C
// and CDisplay+0x2D28.
void LabelOwner_guess::SetLabel_guess(const char* value) {
    g_interface008503A8_guess->Slot00_guess(value);
    strncpy(g_nameBuffer_guess.text_0000_guess, value, 0x20);
    g_nameBuffer_guess.text_0000_guess[0x1f] = 0;
    text_2d28_guess.Assign_guess(value);
}

// FUNCTION: TITANIUM 0x0043A68B
// The second sky layer and its blend amount.
void __stdcall SetSecondarySkyName_guess(const char* value, float amount) {
    g_interface008503A8_guess->Slot02_guess(value, amount);
    strncpy(g_nameBuffer2_guess.text_0000_guess, value, 0x20);
    g_nameBuffer2_guess.text_0000_guess[0x1f] = 0;
}

// FUNCTION: TITANIUM 0x0043A6BF
// Ids over 1000 keep only their low 16 bits (the same mask LoadZone uses on zone ids).
int IndexedTable_guess::Get_guess(int index) {
    if (index > 1000) {
        index &= 0xffff;
    }
    if (index <= 0 || index > 1000) {
        return 0;
    }
    return values_001c_guess[index];
}

struct ValueHelper_guess {
    // EXTERNAL: TITANIUM 0x004EB924 ValueHelper_guess::Read_guess
    int* Read_guess(int value);
};

struct Accessor_guess {
    unsigned char pad_0000_guess[0xf4];
    ValueHelper_guess helper_00f4_guess;
    int Read_guess(int value);
};

struct WorkerResult_guess {
    unsigned char pad_0000_guess[0x120c];
    unsigned char state_120c_guess;
};

// EXTERNAL: TITANIUM 0x00435BA2 ThreadStart_guess
void __cdecl ThreadStart_guess(void* value);
// EXTERNAL: TITANIUM 0x00611958 _beginthread
int __cdecl _beginthread(void (__cdecl *start)(void*), unsigned int stack_size, void* argument);

struct Worker_guess {
    int startTime_0000_guess;
    unsigned char pad_0004_guess[8];
    unsigned char state_000c_guess;
    void Start_guess();
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    WorkerResult_guess* GetCharInfo2();
};

struct Setter_guess {
    unsigned char pad_0000_guess[4];
    EQ_CharacterProfileView_guess helper_0004_guess;
    void Set_guess(unsigned char value);
};

// The value at `value` in the table held at +0xF4.
// FUNCTION: TITANIUM 0x0043A6E4
int Accessor_guess::Read_guess(int value) {
    return *helper_00f4_guess.Read_guess(value);
}

// FUNCTION: TITANIUM 0x0043A6F8
// Starts the worker thread (0x00435BA2) with this object as its argument.
void Worker_guess::Start_guess() {
    startTime_0000_guess = CreateWorker_guess();
    state_000c_guess = 1;
    _beginthread(ThreadStart_guess, 0, this);
}

// Sets the profile byte at +0x120C; the profile load copies it from the server's profile.
// FUNCTION: TITANIUM 0x0043A718
void Setter_guess::Set_guess(unsigned char value) {
    helper_0004_guess.GetCharInfo2()->state_120c_guess = value;
}

// Scalar deleting destructor: restores the base vtable (0x00435BBA), and flag 1 frees the memory.
// FUNCTION: TITANIUM 0x0043A72D
Vtable00435BBA_guess* Vtable00435BBA_guess::Release_guess(unsigned char should_free) {
    void (__fastcall *init_guess)(Vtable00435BBA_guess*) = InitVtable00435BBA_guess;
    init_guess(this);
    if ((should_free & 1) != 0) {
        free(this);
    }
    return this;
}

struct MenuItemBase_guess {
    int value_0004_guess;
    MenuItemBase_guess(int value) { value_0004_guess = value; }
    ~MenuItemBase_guess() { value_0004_guess = 0; }
};

// EXTERNAL: TITANIUM 0x00642550 ??_7MenuTextItem_guess@@6B@
struct MenuTextItem_guess : MenuItemBase_guess {
    virtual void Slot00_guess();
    unsigned char state_0008_guess;
    unsigned char pad_0009_guess[3];
    int value_000c_guess;
    Text_guess text_0010_guess;
    // EXTERNAL: TITANIUM 0x00435BDE MenuTextItem_guess::SetText_guess
    void SetText_guess(const char* value);
    MenuTextItem_guess(int first, int second, const char* value);
    // EXTERNAL: TITANIUM 0x00435BF5 MenuTextItem_guess::~MenuTextItem_guess
    ~MenuTextItem_guess();
};

// Text menu item: kind +4 (0 submenu 0x0043A7B1, 1 command 0x0043A86C; separators are kind 2 without
// text), the caller's value +0xC, +8 set to 1, label +0x10.
// FUNCTION: TITANIUM 0x0043A749
MenuTextItem_guess::MenuTextItem_guess(int first, int second, const char* value)
    : MenuItemBase_guess(first), text_0010_guess() {
    value_000c_guess = second;
    state_0008_guess = 1;
    SetText_guess(value);
}

// Scalar deleting destructor of a menu item (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0043A795
Owner00435BDE_guess* Owner00435BDE_guess::ReleaseWithFlag_guess(unsigned char should_free) {
    this->~Owner00435BDE_guess();
    if ((should_free & 1) != 0) {
        free(this);
    }
    return this;
}

struct OwnerItem0043A7F6_guess {
    virtual void Release_guess(unsigned char should_free);
};

struct OwnerArray0043A7F6_guess {
    int count_0000_guess;
    OwnerItem0043A7F6_guess** items_0004_guess;
    int GetCount_guess() const { return count_0000_guess; }
    OwnerItem0043A7F6_guess* At_guess(int index) {
        if (index >= count_0000_guess || index < 0 || items_0004_guess == 0) {
            Fail_guess();
        }
        return items_0004_guess[index];
    }
    // EXTERNAL: TITANIUM 0x00405492 OwnerArray0043A7F6_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    // EXTERNAL: TITANIUM 0x0050F3F6 OwnerArray0043A7F6_guess::Clear_guess
    void Clear_guess();
};

// EXTERNAL: TITANIUM 0x00642554 ??_7SubMenuItem_guess@@6B@
struct SubMenuItem_guess : MenuTextItem_guess {
    int items_0014_guess;
    SubMenuItem_guess(int first, const char* value, int extra);
    ~SubMenuItem_guess();
    SubMenuItem_guess* Release_guess(unsigned char should_free);
};

// Sub-menu item (kind 0): label `value`, id `first`, sub-menu `extra` at +0x14, enabled.
// FUNCTION: TITANIUM 0x0043A7B1
SubMenuItem_guess::SubMenuItem_guess(int first, const char* value, int extra)
    : MenuTextItem_guess(0, first, value), items_0014_guess(extra) {
    state_0008_guess = 1;
}

// Scalar deleting destructor of a sub-menu item (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0043A7DA
SubMenuItem_guess* SubMenuItem_guess::Release_guess(unsigned char should_free) {
    this->~SubMenuItem_guess();
    if ((should_free & 1) != 0) {
        free(this);
    }
    return this;
}

// Releases every child item in the array at +0x14, then empties the array.
// FUNCTION: TITANIUM 0x0043A7F6
SubMenuItem_guess::~SubMenuItem_guess() {
    OwnerArray0043A7F6_guess* items;
    for (int i = 0; i < ((items = (OwnerArray0043A7F6_guess*)items_0014_guess) != 0
            ? items->count_0000_guess : 0); ++i) {
        if (i >= items->count_0000_guess || i < 0 || items->items_0004_guess == 0) {
            items->Fail_guess();
        }
        OwnerItem0043A7F6_guess* item = items->items_0004_guess[i];
        if (item != 0) {
            item->Release_guess(1);
        }
    }
    ((OwnerArray0043A7F6_guess*)items_0014_guess)->Clear_guess();
}

// EXTERNAL: TITANIUM 0x00642558 ??_7CommandMenuItem_guess@@6B@
struct CommandMenuItem_guess : MenuTextItem_guess {
    int value_0014_guess;
    CommandMenuItem_guess(int first, const char* value, int extra);
};

// Command menu item (kind 1): label `value`, id `first`, command `extra` at +0x14, enabled.
// FUNCTION: TITANIUM 0x0043A86C
CommandMenuItem_guess::CommandMenuItem_guess(int first, const char* value, int extra)
    : MenuTextItem_guess(1, first, value), value_0014_guess(extra) {
    state_0008_guess = 1;
}

struct Releasable0043A895_guess : Owner00435BDE_guess {
    Releasable0043A895_guess* Release_guess(unsigned char should_free);
    ~Releasable0043A895_guess();
};

// Scalar deleting destructor of a menu item (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0043A895
Releasable0043A895_guess* Releasable0043A895_guess::Release_guess(unsigned char should_free) {
    this->~Releasable0043A895_guess();
    if ((should_free & 1) != 0) {
        free(this);
    }
    return this;
}

// Empty destructor.
// FUNCTION: TITANIUM 0x0043A8B1
Releasable0043A895_guess::~Releasable0043A895_guess() {
}

struct PositionLookup_guess {
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
    virtual int Lookup_guess(void* value0_guess, Vector3_guess* position_guess, float* value2_guess, int value3_guess,
                             float value4_guess, float value5_guess, float value6_guess, int value7_guess,
                             int value8_guess, int value9_guess, int value10_guess, void** result_guess);
};

struct LookupResult_guess {
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
    virtual void Release_guess(int value_guess);
};

struct PositionOffset_guess {
    int value_0000_guess;
    int byteOffset_0004_guess;
};

struct PositionRecord_guess {
    unsigned char pad_0000_guess[0x2c];
    float x_002c_guess;
    float y_0030_guess;
    float z_0034_guess;
};

struct PositionBinding_guess {
    int value_0000_guess;
    PositionOffset_guess* offset_0004_guess;
    int values_0008_guess[1];
};

struct PositionOwner_guess {
    unsigned char pad_0000_guess[0x30];
    Vector3_guess position_0030_guess;
    unsigned char pad_003c_guess[0x218 - 0x3c];
    PositionBinding_guess* binding_0218_guess;
};

#define g_positionLookup_guess EQ_GLOBAL(PositionLookup_guess*, 0x0099E368)

// FUNCTION: TITANIUM 0x0043A8B6
// @early-stop: budget, structural ndiff=75
// If the engine refuses the position, it nudges x, then y, then z, then all three, from -5 by 1 unit (10
// tries each), and last tries the zone's safe point (0x00923BCC, as MoveLocalPlayerToSafeCoords uses).
// A moved position is written back to the spawn.
LookupResult_guess* __cdecl r3dCreateActorEx_guess(
    void* value0_guess, Vector3_guess* position_guess, float* value2_guess, int value3_guess,
    float value4_guess, float value5_guess, float value6_guess, int value7_guess,
    int value8_guess, int value9_guess, PositionOwner_guess* owner_guess) {
    int attempt_guess;
    float originalX_guess = position_guess->x_0000_guess;
    float originalY_guess = position_guess->y_0004_guess;
    float originalZ_guess = position_guess->z_0008_guess;
    LookupResult_guess* result_guess = 0;
    unsigned char adjusted_guess = 0;
    int status_guess = g_positionLookup_guess->Lookup_guess(
        value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
        value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
    if (status_guess == -1) {
        adjusted_guess = 1;
        position_guess->x_0000_guess -= 5.0f;
        for (attempt_guess = 0; attempt_guess < 10; ++attempt_guess) {
            status_guess = g_positionLookup_guess->Lookup_guess(
                value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
                value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
            if (status_guess != -1) {
                break;
            }
            position_guess->x_0000_guess += 1.0f;
        }
        if (status_guess == -1) {
            position_guess->x_0000_guess = originalX_guess;
            position_guess->y_0004_guess = originalY_guess - 5.0f;
            for (attempt_guess = 0; attempt_guess < 10; ++attempt_guess) {
                status_guess = g_positionLookup_guess->Lookup_guess(
                    value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
                    value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
                if (status_guess != -1) {
                    break;
                }
                position_guess->y_0004_guess += 1.0f;
            }
        }
        if (status_guess == -1) {
            position_guess->x_0000_guess = originalX_guess;
            position_guess->y_0004_guess = originalY_guess;
            position_guess->z_0008_guess = originalZ_guess - 5.0f;
            for (attempt_guess = 0; attempt_guess < 10; ++attempt_guess) {
                status_guess = g_positionLookup_guess->Lookup_guess(
                    value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
                    value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
                if (status_guess != -1) {
                    break;
                }
                position_guess->z_0008_guess += 1.0f;
            }
        }
        if (status_guess == -1) {
            position_guess->x_0000_guess = originalX_guess - 5.0f;
            position_guess->y_0004_guess = originalY_guess - 5.0f;
            position_guess->z_0008_guess = originalZ_guess - 5.0f;
            for (attempt_guess = 0; attempt_guess < 10; ++attempt_guess) {
                status_guess = g_positionLookup_guess->Lookup_guess(
                    value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
                    value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
                if (status_guess != -1) {
                    break;
                }
                position_guess->x_0000_guess += 1.0f;
                position_guess->y_0004_guess += 1.0f;
                position_guess->z_0008_guess += 1.0f;
            }
        }
        if (status_guess == -1) {
            position_guess->x_0000_guess = EQ_GLOBAL(float, 0x00923BCC);
            position_guess->y_0004_guess = EQ_GLOBAL(float, 0x00923BD0);
            position_guess->z_0008_guess = EQ_GLOBAL(float, 0x00923BD4);
            status_guess = g_positionLookup_guess->Lookup_guess(
                value0_guess, position_guess, value2_guess, value3_guess, value4_guess, value5_guess, value6_guess,
                value7_guess, value8_guess, value9_guess, 1, (void**)&result_guess);
        }
    }
    if ((owner_guess != 0) && (adjusted_guess != 0) && (status_guess != -1)) {
        owner_guess->position_0030_guess = *position_guess;
        PositionBinding_guess* binding_guess = owner_guess->binding_0218_guess;
        if (binding_guess != 0) {
            PositionRecord_guess* record_guess = (PositionRecord_guess*)&binding_guess->values_0008_guess[
                (binding_guess->offset_0004_guess->byteOffset_0004_guess - 4) / 4];
            record_guess->x_002c_guess = owner_guess->position_0030_guess.x_0000_guess;
            record_guess->y_0030_guess = owner_guess->position_0030_guess.y_0004_guess;
            record_guess->z_0034_guess = owner_guess->position_0030_guess.z_0008_guess;
        }
    }
    if (result_guess != 0) {
        result_guess->Release_guess(2);
    }
    return result_guess;
}

struct CharSelectComposite_guess {
    SharedField_guess value_0000_guess;
    CopyBlock_guess value_0004_guess;
    CopyBlock_guess value_0030_guess;
    ExtendedCopy_guess value_005c_guess;
    DialogObject_guess value_00a4_guess;
    int value_00bc_guess;
    CharSelectComposite_guess* CopyFrom_guess(const CharSelectComposite_guess* source);
};

struct UIResource_guess {
    unsigned char storage_0000_guess[0x268];
    // EXTERNAL: TITANIUM 0x00553947 ??0UIResource_guess@@QAE@XZ
    UIResource_guess();
};

struct FontNode_guess {
    int pad_0000_guess[2];
    int fontId_0008_guess;
};

struct UIErrorState_guess {
    int count_0000_guess;
    FontNode_guess* node_0004_guess;
    // EXTERNAL: TITANIUM 0x00405492 UIErrorState_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
};

struct Font_guess {
    void* vtable_0000_guess;
    int index_0004_guess;
    Font_guess(int index)
        : vtable_0000_guess(EQ_ARRAY(unsigned char, 0x00641F20)),
          index_0004_guess(index) {}
};

struct UIManager_guess {
    unsigned char pad_0000_guess[0xec];
    int screenWidth_00ec_guess;
    int screenHeight_00f0_guess;
    UIErrorState_guess state_00f4_guess;
    unsigned char pad_00fc_guess[0x54];
    // EXTERNAL: TITANIUM 0x004FFE98 ??0UIManager_guess@@QAE@PAUUIResource_guess@@@Z
    UIManager_guess(UIResource_guess* resource);
    // EXTERNAL: TITANIUM 0x005B1680 UIManager_guess::RegisterFont_guess
    void RegisterFont_guess(Font_guess* font);
    // EXTERNAL: TITANIUM 0x005B16F0 UIManager_guess::SelectFont_guess
    void SelectFont_guess(int value);
    // EXTERNAL: TITANIUM 0x005AEF50 UIManager_guess::Test_guess
    unsigned char Test_guess();
};

struct UIOptional_guess {
    unsigned char storage_0000_guess[0x24];
    // EXTERNAL: TITANIUM 0x005AD1A0 ??0UIOptional_guess@@QAE@H@Z
    UIOptional_guess(int value);
    // EXTERNAL: TITANIUM 0x005AD2B0 UIOptional_guess::~UIOptional_guess
    ~UIOptional_guess();
};

// Slot 0 of a deleting-destructor vtable: called with 1 to free the object.
struct ReleasableSlot0_guess {
    virtual void Slot00_guess(int value);
};

#define g_uiManagerRelease_guess EQ_GLOBAL(ReleasableSlot0_guess*, 0x0099D3EC)
#define g_uiResourceRelease_guess EQ_GLOBAL(ReleasableSlot0_guess*, 0x0099D3F4)

struct UIInitializer_guess {
    void Initialize_guess();
};

#define g_uiResource_guess EQ_GLOBAL(UIResource_guess*, 0x0099D3F4)
#define g_uiManager_guess EQ_GLOBAL(UIManager_guess*, 0x0099D3EC)
#define g_uiOptional_guess EQ_GLOBAL(UIOptional_guess*, 0x0099D3F8)
#define g_uiManagerValue_guess EQ_GLOBAL(int, 0x0092379C)
#define g_uiManagerSecondValue_guess EQ_GLOBAL(int, 0x009237A0)
#define g_uiOptionalEnabled_guess EQ_GLOBAL(int, 0x00923D74)
#define g_uiOptionalValue_guess EQ_GLOBAL(int, 0x009889BC)

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z

// FUNCTION: TITANIUM 0x0043AB98
// Reads UseLuclin<Race><Gender>. When unset it writes TRUE if 0x00924798 or 0x0092479C is set (probably
// the Luclin defaults) or the race is Vah Shir (0x82, which has no older model).
int __stdcall GetNewPCIniFlag_guess(int race_guess, int female_guess) {
    char value_guess[256];
    char key_guess[256];
    int result = 0;
    char* race_name = GetIniRaceName_guess(race_guess);
    if (female_guess == 0) {
        sprintf(key_guess, "UseLuclin%sMale", race_name);
    } else {
        sprintf(key_guess, "UseLuclin%sFemale", race_name);
    }
    FUN_0060be50_guess("Defaults", key_guess, "*NULL*", value_guess, 0x20, ".\\eqclient.ini");
    if (value_guess[0] == '*') {
        if (EQ_GLOBAL(int, 0x00924798) != 0 || race_guess == Race_VahShir || EQ_GLOBAL(int, 0x0092479C) != 0) {
            result = 1;
            FUN_0060beb0_guess("Defaults", key_guess, "TRUE", ".\\eqclient.ini");
        }
    } else if (value_guess[0] == 'T' || value_guess[0] == 't' || value_guess[0] == '1') {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

// EXTERNAL: TITANIUM 0x004CD3C7 ReadIniBool_guess
int __cdecl ReadIniBool_guess(const char* section, const char* key, const char* value);

// FUNCTION: TITANIUM 0x0043AC64
// @early-stop: budget, diff ndiff=53
// Vah Shir always follow their own setting; other races need a Luclin flag and AllLuclinPcModelsOff off.
bool CDisplay_guess::ShouldLoadNewPcModel_guess(int race, int female) {
    int group;
    if (race == Race_VahShir) {
        return GetNewPCIniFlag_guess(0x82, female) == 1;
    }
    if (EQ_GLOBAL(int, 0x00924798) == 0 && EQ_GLOBAL(int, 0x0092479C) == 0
        && EQ_GLOBAL(int, 0x00923D74) == 0) {
        return false;
    }
    if (ReadIniBool_guess("Defaults", "AllLuclinPcModelsOff", "FALSE") == 1) {
        return false;
    }
    if (GetNewPCIniFlag_guess(race, female) == 1) {
        return true;
    }
    if (race == Race_Human) {
        group = 3;
    } else {
        if (race != Race_WoodElf) {
            return false;
        }
        if (GetNewPCIniFlag_guess(6, female) == 1) {
            return true;
        }
        if (GetNewPCIniFlag_guess(7, female) == 1) {
            return true;
        }
        group = 5;
    }
    return GetNewPCIniFlag_guess(group, female) == 1;
}

// Creates the UI resource and UI manager (given the screen width and height), the optional UI object when
// enabled (0x00923D74), and the 11 fonts; then selects font 2 (the checked access fails hard if fewer).
// FUNCTION: TITANIUM 0x0043AD1F
void CDisplay_guess::InitUIManager_guess() {
    FUN_00574110_guess("Initializing UI manager.");
    EQ_GLOBAL(int, 0x0099E414) = 0;
    g_uiResource_guess = new UIResource_guess;
    g_uiManager_guess = new UIManager_guess(g_uiResource_guess);
    g_uiManager_guess->screenWidth_00ec_guess = g_uiManagerValue_guess;
    g_uiManager_guess->screenHeight_00f0_guess = g_uiManagerSecondValue_guess;
    g_uiOptional_guess = 0;
    if (g_uiOptionalEnabled_guess != 0) {
        g_uiOptional_guess = new UIOptional_guess(g_uiOptionalValue_guess);
    }

    FUN_00574110_guess("Initializing fonts.");
    for (int i = 0; i < 0xb; ++i) {
        Font_guess* font = new Font_guess(i);
        g_uiManager_guess->RegisterFont_guess(font);
    }
    UIManager_guess* manager = g_uiManager_guess;
    UIErrorState_guess* state = &manager->state_00f4_guess;
    if (state->count_0000_guess > 2 && state->node_0004_guess != 0) {
        manager->SelectFont_guess(state->node_0004_guess->fontId_0008_guess);
        return;
    }
    state->Fail_guess();
}

// Assignment: the shared field, the two copy blocks, the extended block, the dialog block and the final
// dword (+0xBC).
// FUNCTION: TITANIUM 0x0043AE64
CharSelectComposite_guess* CharSelectComposite_guess::CopyFrom_guess(const CharSelectComposite_guess* source) {
    value_0000_guess.Assign_guess(&source->value_0000_guess);
    value_0004_guess.CopyFrom_guess(&source->value_0004_guess);
    value_0030_guess.CopyFrom_guess(&source->value_0030_guess);
    value_005c_guess.CopyFrom_guess(&source->value_005c_guess);
    value_00a4_guess.CopyFrom_guess(&source->value_00a4_guess);
    value_00bc_guess = source->value_00bc_guess;
    return this;
}

struct CharSelectUi_guess {
    unsigned char pad_0000_guess[0x3c];
    // EXTERNAL: TITANIUM 0x00548144 CharSelectUi_guess::CharSelectUi_guess
    CharSelectUi_guess();
    // EXTERNAL: TITANIUM 0x0054815C CharSelectUi_guess::~CharSelectUi_guess
    ~CharSelectUi_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void operator delete(void* memory);

struct ReleasableVirtual_guess {
    virtual void Slot00_guess();
    virtual ReleasableVirtual_guess* Release_guess(unsigned char should_free);
};

struct Request0043C187_guess {
    int value_0000_guess;
    int value_0004_guess;
    unsigned char value_0008_guess;
    unsigned char value_0009_guess;
    unsigned char value_000a_guess;
    unsigned char value_000b_guess;
    unsigned char value_000c_guess;
    unsigned char value_000d_guess;
    unsigned short pad_000e_guess;
};

// EXTERNAL: TITANIUM 0x004383B0 LoadWorldFileRequest_guess
void __cdecl LoadWorldFileRequest_guess(Request0043C187_guess* request);

#define g_charSelectUi_guess EQ_GLOBAL(CharSelectUi_guess*, 0x00991E44)
#define g_releasable0_guess EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C20)
#define g_releasable1_guess EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850B9C)
#define g_releasable2_guess EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850BA0)
#define g_releasable3_guess EQ_GLOBAL(ReleasableVirtual_guess*, 0x009927D0)

// Deletes the char-select UI object and releases the CharacterCreation, CharacterSelectWindow,
// FacePickWindow and SystemInfoDialogBox windows.
// FUNCTION: TITANIUM 0x0043AEBB
void __cdecl CleanCharSelectUI_guess() {
    FUN_00574110_guess("Resetting character select UI.");
    if (g_charSelectUi_guess != 0) {
        delete g_charSelectUi_guess;
        g_charSelectUi_guess = 0;
    }
    if (g_releasable0_guess != 0) {
        g_releasable0_guess->Release_guess(1);
        g_releasable0_guess = 0;
    }
    if (g_releasable1_guess != 0) {
        g_releasable1_guess->Release_guess(1);
        g_releasable1_guess = 0;
    }
    if (g_releasable2_guess != 0) {
        g_releasable2_guess->Release_guess(1);
        g_releasable2_guess = 0;
    }
    if (g_releasable3_guess != 0) {
        g_releasable3_guess->Release_guess(1);
        g_releasable3_guess = 0;
    }
}

struct GameUi0051E027_guess {
    // EXTERNAL: TITANIUM 0x0051E027 GameUi0051E027_guess::~GameUi0051E027_guess
    ~GameUi0051E027_guess();
};

struct GameUi00424073_guess {
    // EXTERNAL: TITANIUM 0x00424073 GameUi00424073_guess::~GameUi00424073_guess
    ~GameUi00424073_guess();
};

struct GameUi004C39DE_guess {
    // EXTERNAL: TITANIUM 0x004C39DE GameUi004C39DE_guess::~GameUi004C39DE_guess
    ~GameUi004C39DE_guess();
};

struct GameUi00401429_guess {
    // EXTERNAL: TITANIUM 0x00401429 GameUi00401429_guess::~GameUi00401429_guess
    ~GameUi00401429_guess();
};

struct GameUi004F2141_guess {
    // EXTERNAL: TITANIUM 0x004F2141 GameUi004F2141_guess::~GameUi004F2141_guess
    ~GameUi004F2141_guess();
};

struct GameUi004EB1B2_guess {
    // EXTERNAL: TITANIUM 0x004EB1B2 GameUi004EB1B2_guess::~GameUi004EB1B2_guess
    ~GameUi004EB1B2_guess();
};

// EXTERNAL: TITANIUM 0x004FFBA8 FreeIconCaches_guess
void __cdecl FreeIconCaches_guess();

#define RELEASE_UI_GUESS(p) \
    if ((p) != 0) {         \
        (p)->Release_guess(1); \
        (p) = 0;            \
    }

#define DELETE_UI_GUESS(p) \
    if ((p) != 0) {        \
        delete (p);        \
        (p) = 0;           \
    }

// Tears down the in-game UI: the game window globals, the character-select UI included, are deleted or
// released (Release(1)) and nulled, except 0x00850BD4, which is released only inside the 0x00991A58 branch.
// Then the drag-item and menu-icon animations are freed (0x004FFBA8).
// FUNCTION: TITANIUM 0x0043AF46
void CDisplay_guess::CleanGameUI() {
    FUN_00574110_guess("Resetting game UI.");
    DELETE_UI_GUESS(EQ_GLOBAL(CharSelectUi_guess*, 0x00991E44))
    RELEASE_UI_GUESS(pinstCInspectWnd_guess)
    RELEASE_UI_GUESS(pinstCTrackingWnd_guess)
    RELEASE_UI_GUESS(pinstCGemsGameWnd_guess)
    RELEASE_UI_GUESS(pinstCTitleWnd_guess)
    RELEASE_UI_GUESS(pinstCBazaarWnd_guess)
    RELEASE_UI_GUESS(pinstCBazaarSearchWnd_guess)
    RELEASE_UI_GUESS(pinstCGiveWnd_guess)
    RELEASE_UI_GUESS(pinstCTradeWnd_guess)
    RELEASE_UI_GUESS(pinstCMerchantWnd_guess)
    RELEASE_UI_GUESS(pinstCLootWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C38))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C34))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C30))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C2C))
    RELEASE_UI_GUESS(pinstCCastingWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C18))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C1C))
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi0051E027_guess*, 0x00991B88))
    RELEASE_UI_GUESS(pinstCNoteWnd_guess)
    RELEASE_UI_GUESS(pinstCTipWndOFDAY_guess)
    RELEASE_UI_GUESS(pinstCTipWndCONTEXT_guess)
    RELEASE_UI_GUESS(pinstCBookWnd_guess)
    RELEASE_UI_GUESS(pinstCFriendsWnd_guess)
    RELEASE_UI_GUESS(pinstCRespawnWnd_guess)
    RELEASE_UI_GUESS(pinstCBandolierWnd_guess)
    RELEASE_UI_GUESS(pinstCPotionBeltWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850BE0))
    RELEASE_UI_GUESS(pinstCAlarmWnd_guess)
    RELEASE_UI_GUESS(pinstCLoadskinWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x009927D0))
    RELEASE_UI_GUESS(pinstCPetInfoWnd_guess)
    RELEASE_UI_GUESS(pinstCTrainWnd_guess)
    RELEASE_UI_GUESS(pinstCSkillsWnd_guess)
    RELEASE_UI_GUESS(pinstCSkillsSelectWnd_guess)
    RELEASE_UI_GUESS(pinstCCombatSkillSelectWnd_guess)
    RELEASE_UI_GUESS(pinstCAAWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00991A74))
    if (pinstCGroupSearchWnd_guess != 0) {
        pinstCGroupSearchWnd_guess->Release_guess(1);
        pinstCGroupSearchWnd_guess = 0;
        if (pinstCGroupSearchFiltersWnd_guess != 0) {
            pinstCGroupSearchFiltersWnd_guess->Release_guess(1);
        }
        pinstCGroupSearchFiltersWnd_guess = 0;
    }
    RELEASE_UI_GUESS(pinstCRaidWnd_guess)
    RELEASE_UI_GUESS(pinstCRaidOptionsWnd_guess)
    RELEASE_UI_GUESS(pinstCMailWnd_guess)
    RELEASE_UI_GUESS(pinstCMailCompositionWnd_guess)
    RELEASE_UI_GUESS(pinstCMailAddressBookWnd_guess)
    RELEASE_UI_GUESS(pinstCBreathWnd_guess)
    RELEASE_UI_GUESS(pinstCMapViewWnd_guess)
    RELEASE_UI_GUESS(pinstCMapToolbarWnd_guess)
    RELEASE_UI_GUESS(pinstCEditLabelWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C08))
    RELEASE_UI_GUESS(pinstCColorPickerWnd_guess)
    for (ReleasableVirtual_guess** slot = EQ_ARRAY(ReleasableVirtual_guess*, 0x00991AE4);
         (int)slot < (int)(EQ_ARRAY(ReleasableVirtual_guess*, 0x00991AE4) + 4); ++slot) {
        RELEASE_UI_GUESS(*slot)
    }
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C10))
    RELEASE_UI_GUESS(pinstCEQMainWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850BA0))
    RELEASE_UI_GUESS(pinstCOptionsWnd_guess)
    RELEASE_UI_GUESS(pinstCCursorAttachment_guess)
    RELEASE_UI_GUESS(pinstCQuantityWnd_guess)
    RELEASE_UI_GUESS(pinstCTextEntryWnd_guess)
    RELEASE_UI_GUESS(pinstCFileSelectionWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C44))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C48))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C54))
    RELEASE_UI_GUESS(pinstCSocialEditWnd_guess)
    RELEASE_UI_GUESS(pinstCFeedbackWnd_guess)
    RELEASE_UI_GUESS(pinstCBugReportWnd_guess)
    RELEASE_UI_GUESS(pinstCVideoModesWnd_guess)
    RELEASE_UI_GUESS(pinstCAdvancedDisplayOptionsWnd_guess)
    RELEASE_UI_GUESS(pinstCPetitionQWnd_guess)
    RELEASE_UI_GUESS(pinstCTributeBenefitWnd_guess)
    RELEASE_UI_GUESS(pinstCTributeMasterWnd_guess)
    RELEASE_UI_GUESS(pinstCGuildTributeMasterWnd_guess)
    RELEASE_UI_GUESS(pinstCTaskWnd_guess)
    RELEASE_UI_GUESS(pinstCBarterWnd_guess)
    RELEASE_UI_GUESS(pinstCBarterMerchantWnd_guess)
    RELEASE_UI_GUESS(pinstCBarterSearchWnd_guess)
    RELEASE_UI_GUESS(pinstCLFGuildWnd_guess)
    RELEASE_UI_GUESS(pinstCGuildBankWnd_guess)
    RELEASE_UI_GUESS(pinstCVoiceMacroWnd_guess)
    RELEASE_UI_GUESS(pinstCTaskSelectWnd_guess)
    RELEASE_UI_GUESS(pinstCSoulmarkWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C88))
    RELEASE_UI_GUESS(pinstCPlayerNotesWnd_guess)
    RELEASE_UI_GUESS(pinstCJournalNPCWnd_guess)
    RELEASE_UI_GUESS(pinstCJournalCatWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850CA0))
    RELEASE_UI_GUESS(pinstCFindLocationWnd_guess)
    RELEASE_UI_GUESS(pinstCLargeDialogWnd_guess)
    RELEASE_UI_GUESS(pinstCAdventureRequestWnd_guess)
    RELEASE_UI_GUESS(pinstCPvpLeaderboardWnd_guess)
    RELEASE_UI_GUESS(pinstCPvPStatsWnd_guess)
    RELEASE_UI_GUESS(pinstCPointMerchantWnd_guess)
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi00424073_guess*, 0x0079DBA0))
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi004C39DE_guess*, 0x00985C94))
    // These two tests only store 0 over 0; the function is byte-identical, so they are the original's.
    if (EQ_GLOBAL(int, 0x0098593C) == 0) {
        EQ_GLOBAL(int, 0x0098593C) = 0;
    }
    if (EQ_GLOBAL(int, 0x00985904) == 0) {
        EQ_GLOBAL(int, 0x00985904) = 0;
    }
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi00401429_guess*, 0x0079C104))
    RELEASE_UI_GUESS(pinstCAdventureStatsWnd_guess)
    RELEASE_UI_GUESS(pinstCAdventureLeaderboardWnd_guess)
    RELEASE_UI_GUESS(pinstCLeadershipWnd_guess)
    RELEASE_UI_GUESS(pinstCTargetOfTargetWnd_guess)
    RELEASE_UI_GUESS(pinstCTradeskillWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x0079C148))
    RELEASE_UI_GUESS(pinstCDynamicZoneWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x009918C4))
    RELEASE_UI_GUESS(pinstCTicketWnd_guess)
    RELEASE_UI_GUESS(pinstCTicketCommentWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x0099283C))
    if (pinstCProgressionSelectionWnd_guess != 0) {
        pinstCProgressionSelectionWnd_guess->Release_guess(1);
    }
    pinstCProgressionSelectionWnd_guess = 0;
    RELEASE_UI_GUESS(pinstCItemExpTransferWnd_guess)
    RELEASE_UI_GUESS(pinstCAltStorageWnd_guess)
    RELEASE_UI_GUESS(pinstCServerListWnd_guess)
    RELEASE_UI_GUESS(pinstCMIZoneSelectWnd_guess)
    RELEASE_UI_GUESS(pinstCAvaZoneWnd_guess)
    RELEASE_UI_GUESS(pinstCBodyTintWnd_guess)
    RELEASE_UI_GUESS(pinstCGuildManagementWnd_guess)
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x00850C94))
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi004F2141_guess*, 0x009917E4))
    DELETE_UI_GUESS(EQ_GLOBAL(GameUi004EB1B2_guess*, 0x00991758))
    RELEASE_UI_GUESS(EQ_GLOBAL(ReleasableVirtual_guess*, 0x0099D414))
    if (EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CBC) != 0) {
        EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CBC)->Slot00_guess(1);
        EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CBC) = 0;
    }
    if (EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CB8) != 0) {
        EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CB8)->Slot00_guess(1);
        EQ_GLOBAL(ReleasableSlot0_guess*, 0x00850CB8) = 0;
    }
    FreeIconCaches_guess();
}

// Full UI teardown: char-select and game UIs, then the optional UI object, the UI manager and the UI
// resource.
// FUNCTION: TITANIUM 0x0043BA0B
void CDisplay_guess::ResetUI_guess() {
    FUN_00574110_guess("Resetting UI.");
    CleanCharSelectUI_guess();
    CleanGameUI();
    if (g_uiOptional_guess != 0) {
        delete g_uiOptional_guess;
        g_uiOptional_guess = 0;
    }
    if (g_uiManagerRelease_guess != 0) {
        g_uiManagerRelease_guess->Slot00_guess(1);
        g_uiManagerRelease_guess = 0;
    }
    if (g_uiResourceRelease_guess != 0) {
        g_uiResourceRelease_guess->Slot00_guess(1);
        g_uiResourceRelease_guess = 0;
    }
    FUN_00574110_guess("UI Reset.");
}

struct Dispatch0043BA81_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void Slot49_guess();
    virtual void AboutToHide_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual void Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess();
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    unsigned char pad_0004_guess[0x134];
    unsigned char state_0138_guess;
    // EXTERNAL: TITANIUM 0x00561310 Dispatch0043BA81_guess::ShowHelpPage_guess
    void ShowHelpPage_guess(const char* help);
    // EXTERNAL: TITANIUM 0x005612E7 Dispatch0043BA81_guess::ShowPage_guess
    void ShowPage_guess(int value);
};

struct Text0043BA81_guess {
    int ptr_0000_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Text0043BA81_guess(const char* text);
};

struct Container0043BA81_guess {
    // EXTERNAL: TITANIUM 0x004F2591 Container0043BA81_guess::FUN_004f2591_guess
    void FUN_004f2591_guess();
    // EXTERNAL: TITANIUM 0x004F21A7 Container0043BA81_guess::FUN_004f21a7_guess
    void FUN_004f21a7_guess();
    // EXTERNAL: TITANIUM 0x004F2F8A Container0043BA81_guess::FUN_004f2f8a_guess
    void FUN_004f2f8a_guess(Text0043BA81_guess text, int value);
};

struct Counted0043BA81_guess {
    int count_0000_guess;
    // EXTERNAL: TITANIUM 0x004EB924 Counted0043BA81_guess::Read_guess
    int* Read_guess(int index);
    // EXTERNAL: TITANIUM 0x0050F3F6 Counted0043BA81_guess::FUN_0050f3f6_guess
    void FUN_0050f3f6_guess();
};

struct Character1_0043BA81_guess {
    // EXTERNAL: TITANIUM 0x00417DAF Character1_0043BA81_guess::IsSpellcaster_guess
    int IsSpellcaster_guess();
};

struct Ui0043BA81_guess {
    unsigned char pad_0000_guess[0x84];
    int value_0084_guess;
};

// EQ_PC view: 0xC284 bytes of non-virtual base, then the vbptr; flags in a virtual base at +0x108.
struct CharPadBase0043BA81_guess {
    unsigned char pad_0000_guess[0xc284];
};
struct CharVirtualBase0043BA81_guess {
    unsigned char pad_0000_guess[0x108];
    unsigned int flags_0108_guess;
};
struct CharFlags0043BA81_guess : CharPadBase0043BA81_guess, virtual CharVirtualBase0043BA81_guess {
};

struct Entry0043BA81_guess {
    unsigned char pad_0000_guess[0xc];
    int value_000c_guess;
};

struct EntryTable0043BA81_guess {
    // EXTERNAL: TITANIUM 0x0043A6BF EntryTable0043BA81_guess::Get_guess
    Entry0043BA81_guess* Get_guess(int index);
};

struct Named0043BA81_guess {
    unsigned char pad_0000_guess[0x800];
    int value_0800_guess;
};

#define g_indexTable0043BA81_guess EQ_GLOBAL(EntryTable0043BA81_guess*, 0x00905CC0)
#define g_index0043BA81_guess EQ_GLOBAL(int, 0x00924470)
#define g_container0043BA81_guess EQ_GLOBAL(Container0043BA81_guess*, 0x009917E4)
#define g_counted0043BA81_guess EQ_GLOBAL(Counted0043BA81_guess, 0x0095D3C4)
#define g_pc0043BA81_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_charFlags0043BA81_guess EQ_GLOBAL(CharFlags0043BA81_guess*, 0x00905D00)
#define g_ui0043BA81_guess EQ_GLOBAL(Ui0043BA81_guess*, 0x0099D3EC)
#define g_flag0043BA81_guess EQ_GLOBAL(unsigned char, 0x00850510)
#define g_flagText0043BA81_guess EQ_ARRAY(char, 0x00850510)
#define g_value0043BA81_guess EQ_GLOBAL(int, 0x00850988)
#define g_flag991680_guess EQ_GLOBAL(unsigned char, 0x00991680)
#define g_help0043BA81_guess EQ_ARRAY(char, 0x00642628)
#define g_disp_850c18_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C18)
#define g_disp_850c1c_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C1C)
#define g_disp_850c2c_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C2C)
#define g_disp_850be0_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850BE0)
#define g_disp_850c08_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C08)
#define g_disp_array0043BA81_guess EQ_ARRAY(Dispatch0043BA81_guess*, 0x00991AE4)
#define g_disp_850c10_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C10)
#define g_disp_991a74_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00991A74)
#define g_disp_850c44_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C44)
#define g_disp_850c54_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C54)
#define g_disp_850c88_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C88)
#define g_disp_850c48_guess EQ_GLOBAL(Dispatch0043BA81_guess*, 0x00850C48)

// Brings the game windows back after a UI (re)build: with `refresh` each window calls vtable slot 70,
// then the ones flagged at +0x138 are shown again (slot 33).
// FUNCTION: TITANIUM 0x0043BA81
// @early-stop: budget, structural ndiff=192
void CDisplay_guess::ActivateMainUI_guess(char refresh) {
    int index = g_index0043BA81_guess;
    EntryTable0043BA81_guess* table = g_indexTable0043BA81_guess;
    char flags[2];
    flags[1] = 0;
    flags[0] = 0;
    int value = table->Get_guess(index)->value_000c_guess;
    // Zone 188 (tutoriala in the client's zone table) leaves about ten of the ~27 windows here closed; zone
    // 189 (tutorialb) only two (0x009928A8, 0x00850BAC).
    if (value == 0xbc) {
        flags[1] = 1;
    }
    Entry0043BA81_guess* entry = table->Get_guess(index);
    if (entry->value_000c_guess == 0xbd) {
        flags[0] = 1;
    }
    char& isBc = flags[1];
    char& isBd = flags[0];
    if (pinstCTributeBenefitWnd_guess != 0) {
        if (refresh != 0) {
            pinstCTributeBenefitWnd_guess->LoadIniInfo();
        }
        if (pinstCTributeBenefitWnd_guess->state_0138_guess != 0) {
            pinstCTributeBenefitWnd_guess->Activate();
        }
    }
    if (g_container0043BA81_guess != 0) {
        if (refresh != 0) {
            g_container0043BA81_guess->FUN_004f2591_guess();
        }
        g_container0043BA81_guess->FUN_004f21a7_guess();
    }
    if (pinstCMapViewWnd_guess != 0) {
        if (refresh != 0) {
            pinstCMapViewWnd_guess->LoadIniInfo();
        }
        if (pinstCMapViewWnd_guess->state_0138_guess != 0) {
            pinstCMapViewWnd_guess->Activate();
        }
    }
    if (pinstCMapToolbarWnd_guess != 0) {
        if (refresh != 0) {
            pinstCMapToolbarWnd_guess->LoadIniInfo();
        }
        if (pinstCMapToolbarWnd_guess->state_0138_guess != 0) {
            pinstCMapToolbarWnd_guess->Activate();
        }
    }
    if (g_disp_850c18_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c18_guess->Slot70_guess();
        }
        if (g_disp_850c18_guess->state_0138_guess != 0) {
            g_disp_850c18_guess->Slot33_guess();
        }
    }
    if (g_disp_850c1c_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c1c_guess->Slot70_guess();
        }
        if (g_disp_850c1c_guess->state_0138_guess != 0) {
            g_disp_850c1c_guess->Slot33_guess();
        }
    }
    if (pinstCTicketWnd_guess != 0 && !isBc && !isBd) {
        if (refresh != 0) {
            pinstCTicketWnd_guess->LoadIniInfo();
        }
        pinstCTicketWnd_guess->ShowHelpPage_guess(g_help0043BA81_guess);
        if (pinstCTicketWnd_guess->state_0138_guess != 0) {
            pinstCTicketWnd_guess->ShowPage_guess(0);
            pinstCTicketWnd_guess->Activate();
        }
    }
    if (g_disp_850c2c_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c2c_guess->Slot70_guess();
        }
        int found = ((Character1_0043BA81_guess*)&g_pc0043BA81_guess->vftable_C280)->IsSpellcaster_guess();
        if (found != 0 && g_disp_850c2c_guess->state_0138_guess != 0) {
            g_disp_850c2c_guess->Slot33_guess();
        }
    }
    if (g_disp_850be0_guess != 0) {
        if (refresh != 0) {
            g_disp_850be0_guess->Slot70_guess();
        }
        if (g_disp_850be0_guess->state_0138_guess != 0) {
            g_disp_850be0_guess->Slot33_guess();
        }
    }
    if (g_disp_850c08_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c08_guess->Slot70_guess();
        }
        if (g_disp_850c08_guess->state_0138_guess != 0) {
            g_disp_850c08_guess->Slot33_guess();
        }
    }
    if (pinstCTargetOfTargetWnd_guess != 0 && refresh != 0) {
        pinstCTargetOfTargetWnd_guess->LoadIniInfo();
    }
    for (int i = 0; i < 4; ++i) {
        Dispatch0043BA81_guess* slot = g_disp_array0043BA81_guess[i];
        if (slot != 0 && !isBc) {
            if (refresh != 0) {
                slot->Slot70_guess();
            }
            if (slot->state_0138_guess != 0) {
                slot->Slot33_guess();
            }
        }
    }
    if (g_disp_850c10_guess != 0) {
        if (refresh != 0) {
            g_disp_850c10_guess->Slot70_guess();
        }
        if (g_disp_850c10_guess->state_0138_guess != 0) {
            g_disp_850c10_guess->Slot33_guess();
        }
    }
    if (pinstCEQMainWnd_guess != 0) {
        if (refresh != 0) {
            pinstCEQMainWnd_guess->LoadIniInfo();
        }
        if (pinstCEQMainWnd_guess->state_0138_guess != 0) {
            pinstCEQMainWnd_guess->Activate();
        }
    }
    if (g_disp_991a74_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_991a74_guess->Slot70_guess();
        }
        if (g_disp_991a74_guess->state_0138_guess != 0) {
            g_disp_991a74_guess->Slot33_guess();
        }
    }
    if (g_disp_850c44_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c44_guess->Slot70_guess();
        }
        if (g_disp_850c44_guess->state_0138_guess != 0) {
            g_disp_850c44_guess->Slot33_guess();
        }
    }
    if (g_disp_850c54_guess != 0) {
        if (refresh != 0) {
            g_disp_850c54_guess->Slot70_guess();
        }
        if (g_disp_850c54_guess->state_0138_guess != 0) {
            g_disp_850c54_guess->Slot33_guess();
        }
    }
    if (pinstCPetInfoWnd_guess != 0 && !isBc && !isBd) {
        if (refresh != 0) {
            pinstCPetInfoWnd_guess->LoadIniInfo();
        }
        if (pinstCPetInfoWnd_guess->state_0138_guess != 0) {
            pinstCPetInfoWnd_guess->Activate();
        }
    }
    if (pinstCJournalNPCWnd_guess != 0) {
        if (refresh != 0) {
            pinstCJournalNPCWnd_guess->LoadIniInfo();
        }
        if (pinstCJournalNPCWnd_guess->state_0138_guess != 0) {
            pinstCJournalNPCWnd_guess->Activate();
        }
    }
    if (g_disp_850c88_guess != 0 && !isBc) {
        if (refresh != 0) {
            g_disp_850c88_guess->Slot70_guess();
        }
        if (g_disp_850c88_guess->state_0138_guess != 0) {
            g_disp_850c88_guess->Slot33_guess();
        }
    }
    if (pinstCRaidWnd_guess != 0) {
        if (refresh != 0) {
            pinstCRaidWnd_guess->LoadIniInfo();
        }
        if (pinstCRaidWnd_guess->state_0138_guess != 0) {
            pinstCRaidWnd_guess->Activate();
        }
    }
    if (pinstCAlarmWnd_guess != 0) {
        if (refresh != 0) {
            pinstCAlarmWnd_guess->LoadIniInfo();
        }
        pinstCAlarmWnd_guess->Activate();
    }
    if (pinstCTipWndOFDAY_guess != 0 && refresh != 0) {
        pinstCTipWndOFDAY_guess->LoadIniInfo();
    }
    if (pinstCTipWndCONTEXT_guess != 0 && refresh != 0) {
        pinstCTipWndCONTEXT_guess->LoadIniInfo();
    }
    if (g_disp_850c48_guess != 0) {
        if (refresh != 0) {
            g_disp_850c48_guess->Slot70_guess();
        }
        if (g_disp_850c48_guess->state_0138_guess != 0) {
            g_disp_850c48_guess->Slot33_guess();
        }
    }
    if (pinstCFindLocationWnd_guess != 0) {
        for (ActorUpdateNode_guess* node = g_actorUpdateHead_guess; node != 0; node = node->next_0214_guess) {
            if ((node->pad_01ac_guess[4] & 1) != 0) {
                pinstCFindLocationWnd_guess->AddSpawn_guess(node);
            }
        }
    }
    if (pinstCBazaarWnd_guess != 0) {
        if (refresh != 0) {
            pinstCBazaarWnd_guess->LoadIniInfo();
        }
        if (g_flag991680_guess != 0) {
            pinstCBazaarWnd_guess->Activate();
        }
    }
    if ((((char)g_charFlags0043BA81_guess->flags_0108_guess < 0) ||
            (g_charFlags0043BA81_guess->flags_0108_guess & 0x100) != 0) && pinstCTaskWnd_guess != 0) {
        if (refresh != 0) {
            pinstCTaskWnd_guess->LoadIniInfo();
        }
        if (pinstCTaskWnd_guess->state_0138_guess != 0) {
            pinstCTaskWnd_guess->Activate();
        }
    }
    if ((g_charFlags0043BA81_guess->flags_0108_guess & 0x20) != 0) {
        if (pinstCAdventureRequestWnd_guess != 0) {
            if (refresh != 0) {
                pinstCAdventureRequestWnd_guess->LoadIniInfo();
            }
            if (pinstCAdventureRequestWnd_guess->state_0138_guess != 0) {
                pinstCAdventureRequestWnd_guess->Activate();
            }
        }
        if (pinstCAdventureStatsWnd_guess != 0) {
            if (refresh != 0) {
                pinstCAdventureStatsWnd_guess->LoadIniInfo();
            }
            if (pinstCAdventureStatsWnd_guess->state_0138_guess != 0) {
                pinstCAdventureStatsWnd_guess->Activate();
            }
        }
        if (pinstCAdventureLeaderboardWnd_guess != 0) {
            if (refresh != 0) {
                pinstCAdventureLeaderboardWnd_guess->LoadIniInfo();
            }
            if (pinstCAdventureLeaderboardWnd_guess->state_0138_guess != 0) {
                pinstCAdventureLeaderboardWnd_guess->Activate();
            }
        }
    }
    if ((g_charFlags0043BA81_guess->flags_0108_guess & 0x100) != 0 && pinstCPotionBeltWnd_guess != 0) {
        if (refresh != 0) {
            pinstCPotionBeltWnd_guess->LoadIniInfo();
        }
        if (pinstCPotionBeltWnd_guess->state_0138_guess != 0) {
            pinstCPotionBeltWnd_guess->Activate();
        }
    }
    g_ui0043BA81_guess->value_0084_guess = 0;
    // Then chat lines held back while the UI was down (one flagged line, then the queued list) are shown
    // through the chat manager (0x009917E4, 0x004F2F8A), and the list is emptied.
    if (g_flag0043BA81_guess != 0) {
        if (g_container0043BA81_guess != 0) {
            g_container0043BA81_guess->FUN_004f2f8a_guess(Text0043BA81_guess(g_flagText0043BA81_guess), g_value0043BA81_guess);
        }
        g_flag0043BA81_guess = 0;
    }
    if (g_container0043BA81_guess != 0) {
        for (int i = 0; i < g_counted0043BA81_guess.count_0000_guess; ++i) {
            int* item = g_counted0043BA81_guess.Read_guess(i);
            if (*item != 0) {
                g_container0043BA81_guess->FUN_004f2f8a_guess(Text0043BA81_guess((const char*)*item),
                    ((Named0043BA81_guess*)*item)->value_0800_guess);
            }
        }
        g_counted0043BA81_guess.FUN_0050f3f6_guess();
    }
}

// FUNCTION: TITANIUM 0x0043C187
// Synchronous: runs the load request on this thread.
unsigned char CDisplay_guess::LoadWorldFile_guess(int value0, int value1,
    unsigned char value2, unsigned char value3, unsigned char value4, unsigned char value5) {
    Request0043C187_guess request;
    request.value_0000_guess = value0;
    request.value_0004_guess = value1;
    request.value_0008_guess = value2;
    request.value_0009_guess = value3;
    request.value_000a_guess = value4;
    request.value_000b_guess = value5;
    request.value_000c_guess = 1;
    request.value_000d_guess = 0;
    LoadWorldFileRequest_guess(&request);
    Sleep(1);
    return request.value_000c_guess;
}

struct CleanupNode0043C1D2_guess {
    // EXTERNAL: TITANIUM 0x004519E8 CleanupNode0043C1D2_guess::Process_guess
    void Process_guess();
};

struct CleanupNode0043C1EF_guess {
    // EXTERNAL: TITANIUM 0x004618AB CleanupNode0043C1EF_guess::Process_guess
    void Process_guess();
};

struct CleanupNode0043C20C_guess {
    // EXTERNAL: TITANIUM 0x004849B2 CleanupNode0043C20C_guess::Process_guess
    void Process_guess();
};

#define g_cleanupNode0043C1D2_guess EQ_GLOBAL(CleanupNode0043C1D2_guess*, 0x00905CDC)
#define g_cleanupNode0043C1EF_guess EQ_GLOBAL(CleanupNode0043C1EF_guess*, 0x00905CD4)
#define g_cleanupNode0043C20C_guess EQ_GLOBAL(CleanupNode0043C20C_guess*, 0x00905CC4)

// FUNCTION: TITANIUM 0x0043C1D2
// The DeleteAll* family: each node's cleanup unlinks it from the list head (0x004519E8 does for effects),
// so each loop ends at an empty list.
// Effects: list 0x00905CDC.
void __cdecl DeleteAllEffects_guess() {
    CleanupNode0043C1D2_guess* memory;
    while ((memory = g_cleanupNode0043C1D2_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

// FUNCTION: TITANIUM 0x0043C1EF
// Hierarchical sprites: list 0x00905CD4.
void __cdecl DeleteAllHSprites_guess() {
    CleanupNode0043C1EF_guess* memory;
    while ((memory = g_cleanupNode0043C1EF_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

// FUNCTION: TITANIUM 0x0043C20C
// Spawns: list 0x00905CC4.
void __cdecl DeleteAllPlayers_guess() {
    CleanupNode0043C20C_guess* memory;
    while ((memory = g_cleanupNode0043C20C_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

struct CleanupNode0043C229_guess {
    // EXTERNAL: TITANIUM 0x0046471B CleanupNode0043C229_guess::Process_guess
    void Process_guess();
};

struct CleanupNode0043C246_guess {
    // EXTERNAL: TITANIUM 0x00477B4B CleanupNode0043C246_guess::Process_guess
    void Process_guess();
};

struct CleanupNode0043C263_guess {
    // EXTERNAL: TITANIUM 0x0047789D CleanupNode0043C263_guess::MissileTeardown_guess
    void MissileTeardown_guess();
};

struct CleanupNode0043C280_guess {
    // EXTERNAL: TITANIUM 0x00479305 CleanupNode0043C280_guess::Process_guess
    void Process_guess();
};

#define g_cleanupNode0043C229_guess EQ_GLOBAL(CleanupNode0043C229_guess*, 0x00905CC8)
#define g_cleanupNode0043C246_guess EQ_GLOBAL(CleanupNode0043C246_guess*, 0x00905CCC)
#define g_cleanupNode0043C263_guess EQ_GLOBAL(CleanupNode0043C263_guess*, 0x00905CD0)
#define g_cleanupNode0043C280_guess EQ_GLOBAL(CleanupNode0043C280_guess*, 0x00905CD8)

// FUNCTION: TITANIUM 0x0043C229
// Ground items: list 0x00905CC8.
void __cdecl DeleteAllGroundItems_guess() {
    CleanupNode0043C229_guess* memory;
    while ((memory = g_cleanupNode0043C229_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

// FUNCTION: TITANIUM 0x0043C246
// Dropped money: list 0x00905CCC.
void __cdecl DeleteAllMoney_guess() {
    CleanupNode0043C246_guess* memory;
    while ((memory = g_cleanupNode0043C246_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

// FUNCTION: TITANIUM 0x0043C263
// Missiles: list 0x00905CD0.
void __cdecl DeleteAllMissiles_guess() {
    CleanupNode0043C263_guess* memory;
    while ((memory = g_cleanupNode0043C263_guess) != 0) {
        memory->MissileTeardown_guess();
        free(memory);
    }
}

// FUNCTION: TITANIUM 0x0043C280
// Placed objects: list 0x00905CD8.
void __cdecl DeleteAllObjects_guess() {
    CleanupNode0043C280_guess* memory;
    while ((memory = g_cleanupNode0043C280_guess) != 0) {
        memory->Process_guess();
        free(memory);
    }
}

struct GraphicsSlot0043C29D_guess {
    virtual void Slot00_guess();
};

struct LanguageSlot0043C29D_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value);
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
};

struct Reset0043C29D_guess {
    unsigned char pad_0000_guess[4];
    int value_0004_guess;
    // EXTERNAL: TITANIUM 0x0060C2A0 Reset0043C29D_guess::Reset_guess
    void Reset_guess();
};

#define g_graphicsSlot0043C29D_guess EQ_GLOBAL(GraphicsSlot0043C29D_guess*, 0x0099E38C)
#define g_languageSlot0043C29D_guess EQ_GLOBAL(LanguageSlot0043C29D_guess*, 0x0099E360)
#define g_reset0043C29D_guess EQ_GLOBAL(Reset0043C29D_guess, 0x0099E414)
#define g_value905d04_guess EQ_GLOBAL(int, 0x00905D04)
#define g_value905d08_guess EQ_GLOBAL(int, 0x00905D08)
#define g_value905d0c_guess EQ_GLOBAL(int, 0x00905D0C)
#define g_value850cc8_guess EQ_GLOBAL(int, 0x00850CC8)
#define g_value905cf8_guess EQ_GLOBAL(int, 0x00905CF8)
#define g_value905d20_guess EQ_GLOBAL(int, 0x00905D20)
#define g_value905cfc_guess EQ_GLOBAL(int, 0x00905CFC)
#define g_value905d10_guess EQ_GLOBAL(int, 0x00905D10)
#define g_value905d14_guess EQ_GLOBAL(int, 0x00905D14)
#define g_value905d18_guess EQ_GLOBAL(int, 0x00905D18)
#define g_value905d1c_guess EQ_GLOBAL(int, 0x00905D1C)

// Undoes the display setup: clears the world/display/particle flags, passes the camera (+0x118) to the
// engine's slot 27 and clears it, resets the whole UI (0x0043BA0B), nulls the local player, target and
// related spawn pointers and the light handles, and wipes the 10000-byte table at +0x15C.
// FUNCTION: TITANIUM 0x0043C29D
void CDisplay_guess::ShutdownDisplay_guess() {
    value_2cf8_guess = 0;
    displayInitialized_2cfc_guess = 0;
    particlesInitialized_2d00_guess = 0;
    g_graphicsSlot0043C29D_guess->Slot00_guess();
    AboutToHide_guess* callback = callback_0118_guess;
    if (callback != 0) {
        g_service_guess->Slot27_guess(callback);
    }
    callback_0118_guess = 0;
    g_reset0043C29D_guess.Reset_guess();
    ResetUI_guess();
    g_languageSlot0043C29D_guess->Slot01_guess(1);
    g_languageSlot0043C29D_guess->Slot28_guess();
    g_stateDispatch_guess->Slot20_guess();
    g_service_guess->Slot47_guess();
    g_actorAssociation_guess = 0;
    g_value905d04_guess = 0;
    g_value905d08_guess = 0;
    g_value905d0c_guess = 0;
    g_currentActor_guess = 0;
    g_value850cc8_guess = 0;
    g_value905cf8_guess = 0;
    g_value905d20_guess = 0;
    g_value905cfc_guess = 0;
    g_value905d10_guess = 0;
    g_value905d14_guess = 0;
    g_value905d18_guess = 0;
    g_value905d1c_guess = 0;
    torchLight_2870_guess = 0;
    magTorchLight_2874_guess = 0;
    smLanternLight_2878_guess = 0;
    lgLanternLight_287c_guess = 0;
    smMagicLight_2880_guess = 0;
    lgMagicLight_2884_guess = 0;
    candleLight_2888_guess = 0;
    playerLight_2d18_guess = 0;
    value_286c_guess = 0;
    memset(buffer_015c_guess, 0, 10000);
    value_0158_guess = 0;
    lastUpdateTime_0150_guess = 0;
    value_28f0_guess = 0;
    g_particleSystem_guess->Slot03_guess();
    g_particleSystem_guess->Slot04_guess();
}

struct DrawTarget_guess {
    // EXTERNAL: TITANIUM 0x005A3C80 DrawTarget_guess::DrawText_guess
    void DrawText_guess(CXStr* label, int x, int y, int width, CXRect* rect, unsigned int color, int flag, int other);
};

union ColorArg_guess {
    int value_guess;
    unsigned char bytes_guess[4];
};

// FUNCTION: TITANIUM 0x0043C3E0
// @early-stop: budget, structural ndiff=66
// Colour < 0x100 is one of the classic chat colour codes (13 red, 14 green, 15 yellow, 16 blue, 18 cyan;
// unknown codes are grey); 0x100 + n is user colour n.
int __cdecl WriteTextHD2(const char* text, int x, int y, ColorArg_guess color) {
    unsigned int rgb;
    if (color.value_guess > 0xff) {
        color.value_guess = GetUserDefinedColor(color.value_guess - 0x100);
        rgb = color.bytes_guess[2];
        rgb |= (unsigned int)(color.value_guess | 0xffffff00) << 16;
        rgb |= (unsigned int)color.value_guess & 0xff00;
    } else {
        switch (color.value_guess) {
        case 0x0: rgb = 0xff000000; break;
        case 0x2: rgb = 0xff008000; break;
        case 0x4: rgb = 0xff000080; break;
        case 0x5: rgb = 0xfff000f0; break;
        case 0x6: rgb = 0xff808080; break;
        case 0x7: rgb = 0xffe0e0e0; break;
        case 0xa: rgb = 0xfff0f0f0; break;
        case 0xc: rgb = 0xffa0a0a0; break;
        case 0xd: rgb = 0xfff00000; break;
        case 0xe: rgb = 0xff00f000; break;
        case 0xf: rgb = 0xfff0f000; break;
        case 0x10: rgb = 0xff0000f0; break;
        case 0x12: rgb = 0xff00f0f0; break;
        case 0x14: rgb = 0xff000000; break;
        default: rgb = 0xff606060; break;
        }
    }
    if (g_uiManager_guess != 0) {
        int left = x;
        int top = y;
        CXRect rect;
        rect.left = left;
        rect.top = top;
        rect.right = g_uiManager_guess->screenWidth_00ec_guess;
        rect.bottom = g_uiManager_guess->screenHeight_00f0_guess;
        CXStr label(text);
        if (g_uiManager_guess->state_00f4_guess.count_0000_guess <= 2 ||
            g_uiManager_guess->state_00f4_guess.node_0004_guess == 0) {
            g_uiManager_guess->state_00f4_guess.Fail_guess();
        }
        DrawTarget_guess* target = (DrawTarget_guess*)g_uiManager_guess->state_00f4_guess.node_0004_guess->fontId_0008_guess;
        target->DrawText_guess(&label, left, top,
            g_uiManager_guess->screenWidth_00ec_guess - left, &rect, rgb, 1, 0);
    }
    return 1;
}

// FUNCTION: TITANIUM 0x0043C565
// @early-stop: budget, structural ndiff=171
// Per-frame update of spell effects attached to spawns (list 0x00905CDC). Expired ones are freed.
// Mode 0 orbits the source at a heading offset; mode 2 follows it.
void AngleMath_guess::ProcessEffects_guess() {
    MotionTask_guess* task = g_motionTaskHead_guess;
    if (task == 0) {
        return;
    }
    do {
        MotionTask_guess* next = task->next_005c_guess;
        if (task->expiration_0078_guess != 0 && frame_0148_guess > task->expiration_0078_guess) {
            ((CleanupNode0043C1D2_guess*)task)->Process_guess();
            delete task;
            task = next;
            continue;
        }

        if (task->mode_0088_guess == 0) {
            MotionSource_guess* source = 0;
            if (task->source10_0064_guess != 0) {
                source = &task->source10_0064_guess->source_0010_guess;
            } else if (task->source30_0060_guess != 0) {
                source = &task->source30_0060_guess->source_0030_guess;
            }
            if (source != 0) {
                if (source->angle_001c_guess != task->angle_001c_guess) {
                    task->angle_001c_guess = source->angle_001c_guess;
                    float angle = FixHeading_guess((float)task->angleOffset_0080_guess + source->angle_001c_guess);
                    float sourceX = source->position_0000_guess.x_0000_guess;
                    float sine = g_motionAngleTable_guess->Sin_guess(angle);
                    task->position_0000_guess.x_0000_guess =
                        sine * task->scale_0070_guess + sourceX;
                    float sourceY = source->position_0000_guess.y_0004_guess;
                    float cosine = g_motionAngleTable_guess->Cos_guess(angle);
                    task->position_0000_guess.y_0004_guess =
                        cosine * task->scale_0070_guess + sourceY;
                }
                if (source->angle_002c_guess != task->angle_002c_guess) {
                    task->angle_002c_guess = source->angle_002c_guess;
                    float angle = FixHeading_guess(
                        (float)task->angleOffset_0084_guess + source->angle_002c_guess + 256.0f);
                    float sourceZ = source->position_0000_guess.z_0008_guess;
                    float cosine = g_motionAngleTable_guess->Cos_guess(angle);
                    task->position_0000_guess.z_0008_guess =
                        cosine * task->scale_0070_guess + sourceZ;
                }
            }
        } else if (task->mode_0088_guess == 2) {
            if (task->source30_0060_guess != 0) {
                MotionSource_guess* source = &task->source30_0060_guess->source_0030_guess;
                task->position_0000_guess.x_0000_guess = source->position_0000_guess.x_0000_guess;
                task->position_0000_guess.y_0004_guess = source->position_0000_guess.y_0004_guess;
                task->position_0000_guess.z_0008_guess = source->position_0000_guess.z_0008_guess;
                if ((unsigned int)(task->expiration_0078_guess - frame_0148_guess) <= 0xc8) {
                    task->value_0018_guess = 0.0f;
                }
            } else if (task->source10_0064_guess != 0) {
                MotionSource_guess* source = &task->source10_0064_guess->source_0010_guess;
                task->position_0000_guess.x_0000_guess = source->position_0000_guess.x_0000_guess;
                task->position_0000_guess.y_0004_guess = source->position_0000_guess.y_0004_guess;
                task->position_0000_guess.z_0008_guess = source->position_0000_guess.z_0008_guess;
            }
        }

        if ((unsigned int)(frame_0148_guess - task->lastUpdate_007c_guess) > 0x20) {
            FUN_004bfe0f_guess(0, 0, (int)(EQPlayer*)task);
        }
        Vector3_guess position;
        position.x_0000_guess = task->position_0000_guess.x_0000_guess;
        position.y_0004_guess = task->position_0000_guess.y_0004_guess;
        position.z_0008_guess = task->position_0000_guess.z_0008_guess;
        float angles[3];
        angles[0] = task->angle_001c_guess;
        angles[1] = task->value_0020_guess.value;
        angles[2] = FixHeading_guess(task->sink_0068_guess->GetAngle_guess() + task->offset_0074_guess);
        if (task->sink_0068_guess->Update_guess(&position) != 0) {
            if (task->source10_0064_guess != 0) {
                ((CleanupNode0043C1D2_guess*)task)->Process_guess();
                delete task;
            }
        } else {
            task->sink_0068_guess->Apply_guess(angles);
            if (task->hook_006c_guess != 0) {
                task->hook_006c_guess->Update_guess(&position);
            }
        }
        task = next;
    } while (task != 0);
}

// FUNCTION: TITANIUM 0x0043C783
// Back to the camera mode saved in 0x008503AC.
void CDisplay_guess::RestoreCameraMode_guess() {
    SetCameraMode_guess(EQ_GLOBAL(int, 0x008503AC));
}

struct ClientRender_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(float value);
    virtual void Slot02_guess();
    virtual void Slot03_guess(float value);
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess(float value0, float value1);
};

#define g_viewLeft_guess EQ_GLOBAL(int, 0x00923778)
#define g_viewTop_guess EQ_GLOBAL(int, 0x0092377C)
#define g_displayState_guess EQ_GLOBAL(int, 0x00850508)
#define g_previousDisplayState_guess EQ_GLOBAL(int, 0x00698A04)

struct DisplayWindowState_guess {
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
    virtual unsigned char IsDisplayReady_guess();
};

#define g_displayWindowState_guess EQ_GLOBAL(DisplayWindowState_guess*, 0x0099E364)

// Pushes the view settings to the camera (+0x118) if there is one: +0x28E8 scaled by the viewport's
// aspect ratio (probably the field of view), +0x28F4, the far clip and the actor/shadow clip planes. Then
// copies the viewport rect and maximizes the main window (SW_SHOWMAXIMIZED) once the display is ready.
// FUNCTION: TITANIUM 0x00439212
// @early-stop: budget, structural ndiff=17
void CDisplay_guess::ApplyVideoMode_guess() {
    float width_guess = (float)(g_viewRight_guess - g_viewLeft_guess);
    value_0000_guess = 0;
    if (callback_0118_guess != 0) {
        ((ClientRender_guess*)callback_0118_guess)->Slot08_guess(fieldOfView_28e8_guess,
            (1.0f / (width_guess / (float)(g_viewBottom_guess - g_viewTop_guess))) * fieldOfView_28e8_guess);
        ((ClientRender_guess*)callback_0118_guess)->Slot01_guess(value_28f4_guess);
        ((ClientRender_guess*)callback_0118_guess)->Slot03_guess(yon_0008_guess);
        SetActorClipPlane_guess(actorClipPlane_2d68_guess);
        SetShadowClipPlane_guess(shadowClipPlane_2d6c_guess);
    }
    SetRenderWindow_guess();
    if (g_displayWindowState_guess->IsDisplayReady_guess() != 0) {
        ShowWindow((HWND)window_28e4_guess, 3);
        UpdateWindow((HWND)window_28e4_guess);
    }
}

struct ModeObject_guess {
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
    virtual void Slot14_guess(ModeObject_guess* other);
    virtual void Slot15_guess(ModeObject_guess* other);
};

struct ModeService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(float value);
};

struct ModeClient_guess {
    unsigned char pad_0000_guess[0xb5c];
    float value_0b5c_guess;
};

#define g_currentMode_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_modeObjects_guess EQ_ARRAY(ModeObject_guess*, 0x009254FC)
#define g_modeService_guess EQ_GLOBAL(ModeService_guess*, 0x00925514)
#define g_modeClient_guess EQ_GLOBAL(ModeClient_guess*, 0x00988DF0)

// Switches to camera `mode` (table at 0x009254FC; 0x00850CCC holds the current one); the old and new
// camera objects are told about each other. Every mode but 6 also zeroes a camera value on two objects.
// FUNCTION: TITANIUM 0x004392DE
// @early-stop: budget, diff ndiff=5
void CDisplay_guess::SetCameraMode_guess(int mode) {
    ModeObject_guess** currentSlot = &g_modeObjects_guess[g_currentMode_guess];
    ModeObject_guess** nextSlot = &g_modeObjects_guess[mode];
    (*currentSlot)->Slot15_guess(*nextSlot);
    (*nextSlot)->Slot14_guess(*currentSlot);
    if (mode != 6) {
        g_modeService_guess->Slot06_guess(0.0f);
        if (g_modeClient_guess != 0) {
            g_modeClient_guess->value_0b5c_guess = 0.0f;
        }
    }
    g_currentMode_guess = mode;
}

// ApplyVideoMode's camera update without the null check or ShowWindow; first runs 0x0043933D when the
// display state (0x00850508) changed since the last call, then records it.
// FUNCTION: TITANIUM 0x0043C78F
// @early-stop: budget, structural ndiff=12
void CDisplay_guess::ChangeVideoMode_guess() {
    if (g_displayState_guess != g_previousDisplayState_guess) {
        FUN_0043933d_guess();
    }
    float width_guess = (float)(g_viewRight_guess - g_viewLeft_guess);
    int height_guess = g_viewBottom_guess - g_viewTop_guess;
    value_0000_guess = 0;
    float heightAsFloat_guess = (float)height_guess;
    float ratio_guess = width_guess / heightAsFloat_guess;
    ((ClientRender_guess*)callback_0118_guess)->Slot08_guess(fieldOfView_28e8_guess,
        (1.0f / ratio_guess) * fieldOfView_28e8_guess);
    ((ClientRender_guess*)callback_0118_guess)->Slot01_guess(value_28f4_guess);
    ((ClientRender_guess*)callback_0118_guess)->Slot03_guess(yon_0008_guess);
    SetActorClipPlane_guess(actorClipPlane_2d68_guess);
    SetShadowClipPlane_guess(shadowClipPlane_2d6c_guess);
    SetRenderWindow_guess();
    value_0000_guess = 0;
    g_previousDisplayState_guess = g_displayState_guess;
}

struct Spawn_0043C84B_guess;

struct SpriteDef_0043C84B_guess {
    virtual void Slot00_guess();
    virtual float GetScale_guess();
    virtual void SetScale_guess(float scale);
};

struct SpriteLoader_0043C84B_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Find_guess(char* tag, SpriteDef_0043C84B_guess** sprite);
};

struct World_0043C84B_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual char IsValid_guess(Vector3_guess* position);
};

struct ActorInstance_0043C84B_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void SetOwner_guess(Spawn_0043C84B_guess* owner);
    virtual void Slot04_guess(int value);
    virtual void Slot05_guess();
    virtual void Slot06_guess(int value);
    virtual void Slot07_guess(); virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess();
    virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void SetPosition_guess(Vector3_guess* position);
    virtual void SetHeading_guess(float* heading);
    virtual void Slot20_guess(float value, int flag);
    virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess();
    virtual void Slot27_guess(); virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(float value);
    virtual void Slot43_guess(); virtual void Slot44_guess(); virtual void Slot45_guess();
    virtual void Slot46_guess(); virtual void Slot47_guess(); virtual void Slot48_guess();
    virtual void Slot49_guess(); virtual void AboutToHide_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess();
    virtual void SetBoneScale_guess(int bone, float scale);
    virtual float GetBoneScale_guess(int bone);
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess();
    virtual void Slot59_guess(); virtual void Slot60_guess(); virtual void Slot61_guess();
    virtual void Slot62_guess(); virtual void Slot63_guess(); virtual void Slot64_guess();
    virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess();
    virtual void Slot71_guess(); virtual void Slot72_guess(); virtual void Slot73_guess();
    virtual void Slot74_guess(); virtual void Slot75_guess(); virtual void Slot76_guess();
    virtual void Slot77_guess(); virtual void Slot78_guess(); virtual void Slot79_guess();
    virtual void Slot80_guess(); virtual void Slot81_guess(); virtual void Slot82_guess();
    virtual void Slot83_guess(); virtual void Slot84_guess();
    virtual char HasBone_guess(int bone);
    virtual void Slot86_guess(); virtual void Slot87_guess(); virtual void Slot88_guess();
    virtual void Slot89_guess(); virtual void Slot90_guess(); virtual void Slot91_guess();
    virtual void Slot92_guess(); virtual void Slot93_guess(); virtual void Slot94_guess();
    virtual void Slot95_guess();
    virtual void Slot96_guess(); virtual void Slot97_guess(); virtual void Slot98_guess();
    virtual void Slot99_guess(); virtual void Slot100_guess(); virtual void Slot101_guess();
    virtual void Slot102_guess(); virtual void Slot103_guess(); virtual void Slot104_guess();
    virtual void Slot105_guess(); virtual void Slot106_guess(); virtual void Slot107_guess();
    virtual void Slot108_guess(); virtual void Slot109_guess(); virtual void Slot110_guess();
    virtual void Slot111_guess();
    virtual void Slot112_guess(float value);
};

struct Model_0043C84B_guess {
    unsigned char pad_0000_guess[0x34];
    unsigned char value_0034_guess;
    unsigned char pad_0035_guess[3];
    float value_0038_guess;
    unsigned char pad_003c_guess[0x48 - 0x3c];
    float value_0048_guess;
    unsigned char pad_004c_guess[0x58 - 0x4c];
    // EXTERNAL: TITANIUM 0x00461772 Model_0043C84B_guess::Model_0043C84B_guess
    Model_0043C84B_guess(char* tag, ActorInstance_0043C84B_guess* instance, Spawn_0043C84B_guess* owner);
    // EXTERNAL: TITANIUM 0x00461920 Model_0043C84B_guess::SetROffsetFromActor_guess
    void SetROffsetFromActor_guess(ActorInstance_0043C84B_guess* instance, float scale);
};

struct ModelCache_0043C84B_guess {
    // EXTERNAL: TITANIUM 0x0046194C ModelCache_0043C84B_guess::Find_guess
    Model_0043C84B_guess* Find_guess(char* tag);
};

struct ActorInfo_0043C84B_guess {
    ActorInstance_0043C84B_guess* instance_0000_guess;
    int value_0004_guess;
    char tag_0008_guess[0xc4 - 8];
    float heightScale_00c4_guess;
    unsigned char pad_00c8_guess[0x12c - 0xc8];
    Model_0043C84B_guess* model_012c_guess;
    unsigned char pad_0130_guess[0xf4c - 0x130];
    int value_0f4c_guess;
    unsigned char pad_0f50_guess[0xf88 - 0xf50];
    int value_0f88_guess;
    // EXTERNAL: TITANIUM 0x0048F019 ActorInfo_0043C84B_guess::FUN_0048f019_guess
    int FUN_0048f019_guess();
};

struct Sound_0043C84B_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Play_guess(int id, int loop, int value, float volume, int flag);
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Stop_guess(int id, int value0, int value1, float volume);
};

struct Spawn_0043C84B_guess {
    unsigned char pad_0000_guess[0x30];
    Vector3_guess position_0030_guess;
    unsigned char pad_003c_guess[0x4c - 0x3c];
    float heading_004c_guess;
    float value_0050_guess;
    unsigned char pad_0054_guess[0x120 - 0x54];
    char name_0120_guess[0x40];
    unsigned char pad_0160_guess[0x1a0 - 0x160];
    float speed_01a0_guess;
    int value_01a4_guess;
    ActorInfo_0043C84B_guess* actor_01a8_guess;
    unsigned char pad_01ac_guess[0x1b6 - 0x1ac];
    unsigned char boat_01b6_guess;
    unsigned char pad_01b7_guess[0x234 - 0x1b7];
    float eyeHeight_0234_guess;
    int value_0238_guess;
    float height_023c_guess;
    unsigned char pad_0240_guess[4];
    unsigned char type_0244_guess;
    unsigned char pad_0245_guess[0x24e - 0x245];
    unsigned char gender_024e_guess;
    unsigned char pad_024f_guess[2];
    unsigned char stand_0251_guess;
    unsigned char pad_0252_guess[2];
    signed char illusion_0254_guess;
    signed char helm_0255_guess;
    unsigned char pad_0256_guess[2];
    int spawnId_0258_guess;
    int value_025c_guess;
    int race_0260_guess;
    unsigned char pad_0264_guess[0x270 - 0x264];
    int bodyType_0270_guess;
    // EXTERNAL: TITANIUM 0x00479A3A Spawn_0043C84B_guess::SetAnimVariation_guess
    void SetAnimVariation_guess();
    // EXTERNAL: TITANIUM 0x004798D7 Spawn_0043C84B_guess::GetActorTag_guess
    void GetActorTag_guess(char* tag);
    // EXTERNAL: TITANIUM 0x00479E02 Spawn_0043C84B_guess::LegalPlayerRace_guess
    int LegalPlayerRace_guess(int race);
    // EXTERNAL: TITANIUM 0x0047A741 Spawn_0043C84B_guess::SetRace_guess
    void SetRace_guess(int race);
    // EXTERNAL: TITANIUM 0x0047B8D5 Spawn_0043C84B_guess::FUN_0047b8d5_guess
    void FUN_0047b8d5_guess(unsigned char* value);
    // EXTERNAL: TITANIUM 0x0047B940 Spawn_0043C84B_guess::SetPlayerPitchType_guess
    void SetPlayerPitchType_guess();
    // EXTERNAL: TITANIUM 0x0047BCE2 Spawn_0043C84B_guess::UpdateLight_guess
    void UpdateLight_guess();
    // EXTERNAL: TITANIUM 0x0047BFD0 Spawn_0043C84B_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x0047C017 Spawn_0043C84B_guess::CreateAnimation_guess
    void CreateAnimation_guess(int value);
    // EXTERNAL: TITANIUM 0x0047C08E Spawn_0043C84B_guess::GetAnimation_guess
    Sound_0043C84B_guess* GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x0047C17E Spawn_0043C84B_guess::InitSpellPoints_guess
    void InitSpellPoints_guess();
    // EXTERNAL: TITANIUM 0x0047C2D4 Spawn_0043C84B_guess::FUN_0047c2d4_guess
    float FUN_0047c2d4_guess();
    // EXTERNAL: TITANIUM 0x0047D776 Spawn_0043C84B_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
    // EXTERNAL: TITANIUM 0x0047D7A4 Spawn_0043C84B_guess::UpdateDAGPointers_guess
    void UpdateDAGPointers_guess();
    // EXTERNAL: TITANIUM 0x0047E35C Spawn_0043C84B_guess::GetModelAtSpawnSpot_guess
    char GetModelAtSpawnSpot_guess(char* buffer, int kind);
    // EXTERNAL: TITANIUM 0x0047FDF6 Spawn_0043C84B_guess::RandomizeRace_guess
    void RandomizeRace_guess();
    // EXTERNAL: TITANIUM 0x00480130 Spawn_0043C84B_guess::SetDefaultFacialFeaturesByFace_guess
    void SetDefaultFacialFeaturesByFace_guess(int value0, int value1, int value2);
    // EXTERNAL: TITANIUM 0x00481D5D Spawn_0043C84B_guess::SetAvatarHeight_guess
    void SetAvatarHeight_guess(float height);
    // EXTERNAL: TITANIUM 0x00482722 Spawn_0043C84B_guess::SwapNPCMaterials_guess
    void SwapNPCMaterials_guess();
    // EXTERNAL: TITANIUM 0x00483B9B Spawn_0043C84B_guess::RefreshFacialFeatures_guess
    void RefreshFacialFeatures_guess();
    // EXTERNAL: TITANIUM 0x00489906 Spawn_0043C84B_guess::FUN_00489906_guess
    float FUN_00489906_guess();
    // EXTERNAL: TITANIUM 0x004899CC Spawn_0043C84B_guess::FUN_004899cc_guess
    float FUN_004899cc_guess();
};

#define g_display_0043C84B_guess EQ_GLOBAL(CDisplay_guess*, 0x00905D24)
#define g_localSpawn_0043C84B_guess EQ_GLOBAL(Spawn_0043C84B_guess*, 0x00905CE4)
#define g_spriteLoader_0043C84B_guess EQ_GLOBAL(SpriteLoader_0043C84B_guess*, 0x0099E360)
#define g_world_0043C84B_guess EQ_GLOBAL(World_0043C84B_guess*, 0x0099E368)
#define g_modelCache_0043C84B_guess EQ_GLOBAL(ModelCache_0043C84B_guess*, 0x00905CD4)
#define g_zoneId_0043C84B_guess EQ_GLOBAL(int, 0x00924470)
#define g_viewFlag_0043C84B_guess EQ_GLOBAL(int, 0x00923884)
#define g_safeX_0043C84B_guess EQ_GLOBAL(float, 0x00923BCC)
#define g_safeY_0043C84B_guess EQ_GLOBAL(float, 0x00923BD0)
#define g_safeZ_0043C84B_guess EQ_GLOBAL(float, 0x00923BD4)
#define g_tint_0043C84B_guess EQ_ARRAY(unsigned char, 0x006974CC)

// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination, const char* source, int length);
// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int code, int value0, int value1);

// FUNCTION: TITANIUM 0x0043C84B
// @early-stop: budget, structural ndiff=278
// Builds a spawn's actor. Races 0xD1-0xD4 (Luclin elementals) map to race 0x4B with texture 0, 3, 2, 1
// when UseLuclinElementals is off, and back when it is on. An unknown model becomes a human (HUM/HUF).
// A spawn inside geometry is raised 2 units up to four times, then moved to the safe point (0x00923BCC);
// for some spawns of the player's own name (pets) message 0x5E51 also reports the spawn id.
// The race switch scales models built at the wrong size; it is data, kept as the client has it.
void CDisplay_guess::CreatePlayerActor(Spawn_0043C84B_guess* player) {
    float scale;
    SpriteDef_0043C84B_guess* sprite = 0;
    if (player == 0) {
        return;
    }
    char savedTag[0x40];
    memset(savedTag, 0, sizeof(savedTag));
    strcpy(savedTag, player->actor_01a8_guess->tag_0008_guess);
    char raceTag[0x18];
    player->GetActorTag_guess(raceTag);
    if (value_2cf8_guess != 0) {
        int race = player->race_0260_guess;
        if (race == 0x8f || race == 0x8e) {
            char tag[0x80];
            player->GetModelAtSpawnSpot_guess(tag, (race == 0x8f) + 7);
            steve_strncpy_guess(player->actor_01a8_guess->tag_0008_guess, tag, 0x1e);
        // Elementals: without the Luclin set, races 209-212 become the classic elemental (75) with the
        // matching texture; with it, race 75 maps the other way when that model exists.
        } else if (g_display_0043C84B_guess->state_0129_guess == 0 && race >= 0xd1 && race <= 0xd4) {
            switch (race) {
            case 0xd1:
                player->illusion_0254_guess = 0;
                break;
            case 0xd2:
                player->illusion_0254_guess = 3;
                break;
            case 0xd3:
                player->illusion_0254_guess = 2;
                break;
            case 0xd4:
                player->illusion_0254_guess = 1;
                break;
            }
            player->SetRace_guess(0x4b);
            player->GetActorTag_guess(player->actor_01a8_guess->tag_0008_guess);
            strcat(player->actor_01a8_guess->tag_0008_guess, "_ACTORDEF");
            g_spriteLoader_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess, &sprite);
        } else if (race == 0x4b && g_display_0043C84B_guess->state_0129_guess != 0) {
            switch (player->illusion_0254_guess) {
            case 0:
                player->SetRace_guess(0xd1);
                break;
            case 1:
                player->SetRace_guess(0xd4);
                break;
            case 2:
                player->SetRace_guess(0xd3);
                break;
            default:
                player->SetRace_guess(0xd2);
                break;
            }
            player->GetActorTag_guess(player->actor_01a8_guess->tag_0008_guess);
            strcat(player->actor_01a8_guess->tag_0008_guess, "_ACTORDEF");
            g_spriteLoader_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess, &sprite);
            if (sprite == 0) {
                player->SetRace_guess(0x4b);
                player->GetActorTag_guess(player->actor_01a8_guess->tag_0008_guess);
                strcat(player->actor_01a8_guess->tag_0008_guess, "_ACTORDEF");
            } else {
                player->helm_0255_guess = 0;
                player->illusion_0254_guess = 0;
            }
        } else if (race == 0x14 && g_zoneId_0043C84B_guess == 0xa3) {
            player->RandomizeRace_guess();
        }

        if (sprite == 0) {
            g_spriteLoader_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess, &sprite);
            if (sprite == 0) {
                strcpy(savedTag, player->actor_01a8_guess->tag_0008_guess);
                if (player->gender_024e_guess == 1) {
                    // A model that can't be found falls back to a human of the same gender; if even that is
                    // missing it is fatal.
                    strcpy(player->actor_01a8_guess->tag_0008_guess, "HUF_ACTORDEF");
                    if (!player->IsHorseRace_guess()) {
                        player->SetRace_guess(1);
                        player->gender_024e_guess = 1;
                    }
                } else {
                    strcpy(player->actor_01a8_guess->tag_0008_guess, "HUM_ACTORDEF");
                    if (!player->IsHorseRace_guess()) {
                        player->SetRace_guess(1);
                        player->gender_024e_guess = 0;
                    }
                }
                g_spriteLoader_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess, &sprite);
                if (sprite == 0) {
                    FUN_00574110_guess(
                        "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. actor_tag=%s\n",
                        player->name_0120_guess, player->actor_01a8_guess->tag_0008_guess);
                    ExecuteCmd(0xfd, 0, 0);
                    return;
                }
            }
        }

        Vector3_guess position;
        float heading[3];
        position.x_0000_guess = player->position_0030_guess.x_0000_guess;
        position.y_0004_guess = player->position_0030_guess.y_0004_guess;
        position.z_0008_guess = player->position_0030_guess.z_0008_guess;
        heading[0] = player->heading_004c_guess;
        heading[1] = player->value_0050_guess;
        heading[2] = 0.0f;
        if (!g_world_0043C84B_guess->IsValid_guess(&position)) {
            position.z_0008_guess += 2.0f;
            if (!g_world_0043C84B_guess->IsValid_guess(&position)) {
                position.z_0008_guess += 2.0f;
                if (!g_world_0043C84B_guess->IsValid_guess(&position)) {
                    position.z_0008_guess += 2.0f;
                    if (!g_world_0043C84B_guess->IsValid_guess(&position)) {
                        position.z_0008_guess += 2.0f;
                        if (!g_world_0043C84B_guess->IsValid_guess(&position)) {
                            if (player->type_0244_guess == 2) {
                                size_t length = strlen(g_localSpawn_0043C84B_guess->name_0120_guess);
                                char name[0x40];
                                strcpy(name, player->name_0120_guess);
                                if (strncmp(g_localSpawn_0043C84B_guess->name_0120_guess, player->name_0120_guess,
                                        length - 1) == 0) {
                                    int spawnId = player->spawnId_0258_guess;
                                    EQSendMessage(&g_messageSource_guess, 0x5e51, &spawnId, 4, 1);
                                }
                            }
                            position.x_0000_guess = g_safeX_0043C84B_guess;
                            position.y_0004_guess = g_safeY_0043C84B_guess;
                            position.z_0008_guess = g_safeZ_0043C84B_guess;
                        }
                    }
                }
            }
            player->position_0030_guess.x_0000_guess = position.x_0000_guess;
            player->position_0030_guess.y_0004_guess = position.y_0004_guess;
            player->position_0030_guess.z_0008_guess = position.z_0008_guess;
        }

        scale = sprite->GetScale_guess();
        if (scale < 1.0f) {
            scale = 1.0f;
        }
        switch (player->race_0260_guess) {
        case 0x15:
        case 0x16:
        case 0x1e:
        case 0x26:
        case 0x34:
        case 0x56:
        case 0x58:
        case 100:
        case 0x6d:
        case 0x6f:
        case 0x9a:
        case 0x19e:
        case 0x8cd:
        case 0x8ce:
        case 0x8cf:
        case 0x8d0:
        case 0x8d1:
        case 0x8d2:
            scale *= 2.0f;
            break;
        case 0x48:
            if (player->actor_01a8_guess->value_0f88_guess == 1) {
                scale *= 2.0f;
            }
            break;
        case 0x1f:
        case 0x7d:
        case 0xae:
        case 0xbc:
        case 0xbd:
            scale *= 3.0f;
            break;
        case 0x24:
        case 0x19f:
        case 0x1d9:
            scale *= 4.0f;
            break;
        case 0x4f:
            scale *= 5.0f;
            break;
        case 0x22:
        case 0x1a0:
            scale *= 7.0f;
            break;
        case 0x102:
            scale *= 2.2f;
            break;
        case 0x18a:
            scale *= 0.5f;
            break;
        case 0x2e:
            scale = 10.5f;
            break;
        case 0x31:
            scale = 116.3f;
            break;
        case 0x45:
            scale = 20.0f;
            break;
        case 0x55:
            scale = 10.1f;
            break;
        case 0x59:
            scale = 16.5f;
            break;
        case 0x5b:
            scale = 6.35f;
            break;
        case 0x71:
            scale = 40.0f;
            break;
        case 0xb7:
            scale = 3.0f;
            break;
        case 0x130:
            scale = 120.0f;
            break;
        case 0x194:
            scale = 115.0f;
            break;
        }
        if (player->LegalPlayerRace_guess(-1) != 0) {
            scale *= 1.2f;
        }
        if (player->FUN_0047c2d4_guess() == 0.0f) {
            player->speed_01a0_guess = scale;
        }
        if (g_modelCache_0043C84B_guess == 0 ||
            g_modelCache_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess) == 0) {
            sprite->SetScale_guess(scale);
        }
        {
        float height = player->FUN_00489906_guess();
        int collision;
        if (player->race_0260_guess < 0x8cd && player->bodyType_0270_guess < 0x41) {
            collision = (player->boat_01b6_guess == 0) + 1;
        } else {
            collision = 0;
        }
        lastUpdateTime_0150_guess = 0;
        int newRace = player->race_0260_guess;
        unsigned char shadow = 0;
        if (newRace >= 0x8cd || (newRace != 0x8d && newRace != 0x8e && newRace != 0x8f && newRace != 0x49 &&
                                 newRace != 0x72 && newRace < 0x1db)) {
            shadow = 1;
        }
        player->actor_01a8_guess->instance_0000_guess = (ActorInstance_0043C84B_guess*)r3dCreateActorEx_guess(
            sprite, &position, heading, collision, height, 1.0f, scale, 0, shadow,
            player->LegalPlayerRace_guess(newRace) == 0, (PositionOwner_guess*)player);
        }
        if (player->actor_01a8_guess->instance_0000_guess != 0) {
            player->actor_01a8_guess->instance_0000_guess->Slot95_guess();
        }
        if (player->actor_01a8_guess->instance_0000_guess != 0) {
            race = player->race_0260_guess;
            if (race == 0x8e || race == 0x8f) {
                player->UpdateDAGPointers_guess();
                player->InitSpellPoints_guess();
            } else if (race >= 0x8cd || (race != 0x8d && race != 0x49 && race != 0x72 && race < 0x1db)) {
                if (g_viewFlag_0043C84B_guess != 0) {
                    SetViewActor_guess(
                        (ViewActor_guess*)g_localSpawn_0043C84B_guess->actor_01a8_guess->instance_0000_guess);
                }
                if (g_modelCache_0043C84B_guess != 0) {
                    player->actor_01a8_guess->model_012c_guess =
                        g_modelCache_0043C84B_guess->Find_guess(player->actor_01a8_guess->tag_0008_guess);
                } else {
                    player->actor_01a8_guess->model_012c_guess = 0;
                }
                if (player->actor_01a8_guess->model_012c_guess == 0) {
                    player->actor_01a8_guess->model_012c_guess = new Model_0043C84B_guess(
                        player->actor_01a8_guess->tag_0008_guess, player->actor_01a8_guess->instance_0000_guess,
                        player);
                } else {
                    player->CreateAnimation_guess(player->actor_01a8_guess->FUN_0048f019_guess());
                }
                player->actor_01a8_guess->instance_0000_guess->Slot112_guess(
                    player->actor_01a8_guess->model_012c_guess->value_0038_guess);
                player->actor_01a8_guess->instance_0000_guess->Slot42_guess(
                    player->actor_01a8_guess->model_012c_guess->value_0048_guess);
                player->UpdateDAGPointers_guess();
                player->InitSpellPoints_guess();
                player->actor_01a8_guess->model_012c_guess->SetROffsetFromActor_guess(
                    player->actor_01a8_guess->instance_0000_guess, player->actor_01a8_guess->heightScale_00c4_guess);
                if (player->LegalPlayerRace_guess(-1) == 0) {
                    char changed = 0;
                    if (player->helm_0255_guess == -1) {
                        player->helm_0255_guess = 0;
                        changed = 1;
                    }
                    if (player->illusion_0254_guess == -1) {
                        player->illusion_0254_guess = 0;
                        changed = 1;
                    }
                    if (changed || g_stringTable_guess->mode_0b54_guess == 1) {
                        player->SwapNPCMaterials_guess();
                    }
                } else {
                    player->illusion_0254_guess = -1;
                }
                race = player->race_0260_guess;
                if ((race == Race_Barbarian || (race > 7 && race <= 0xb)) &&
                    player->actor_01a8_guess->instance_0000_guess->HasBone_guess(3) &&
                    player->actor_01a8_guess->instance_0000_guess->HasBone_guess(4)) {
                    scale = player->actor_01a8_guess->instance_0000_guess->GetBoneScale_guess(3);
                    player->actor_01a8_guess->instance_0000_guess->GetBoneScale_guess(4);
                    if (player->race_0260_guess == Race_Dwarf) {
                        if (player->gender_024e_guess == 0) {
                            scale = 1.0f;
                        } else {
                            scale = 1.2f;
                        }
                        player->actor_01a8_guess->instance_0000_guess->SetBoneScale_guess(3, scale);
                    }
                    player->actor_01a8_guess->instance_0000_guess->SetBoneScale_guess(4, scale);
                }
                player->RefreshNameSprite_guess();
                if (value_2d58_guess != 0) {
                    player->FUN_0047b8d5_guess(g_tint_0043C84B_guess);
                }
                if (player->type_0244_guess == 0) {
                    player->UpdateLight_guess();
                }
            }
        }
        if (player->actor_01a8_guess->instance_0000_guess != 0) {
            player->actor_01a8_guess->instance_0000_guess->Slot20_guess(player->actor_01a8_guess->heightScale_00c4_guess, 1);
            player->actor_01a8_guess->instance_0000_guess->SetPosition_guess(&position);
            player->actor_01a8_guess->instance_0000_guess->SetHeading_guess(heading);
            if (player->type_0244_guess < 2 && player->stand_0251_guess != 's') {
                char stand = player->stand_0251_guess;
                if (stand == 'i') {
                    player->GetAnimation_guess()->Play_guess(0x24, 1, 0, 1.0f, 1);
                } else if (stand == 'n') {
                    player->GetAnimation_guess()->Play_guess(0x21, 1, 0, 1.0f, 1);
                } else {
                    player->GetAnimation_guess()->Play_guess(0x20, 0, 0, 1.0f, 1);
                }
            } else {
                int saved = player->actor_01a8_guess->value_0f4c_guess;
                player->actor_01a8_guess->value_0f4c_guess = 0;
                player->GetAnimation_guess()->Stop_guess(0x10, 1, 1, 0.0f);
                player->actor_01a8_guess->value_0f4c_guess = saved;
            }
        }
    }
    if (player->actor_01a8_guess->instance_0000_guess != 0) {
        player->actor_01a8_guess->instance_0000_guess->SetOwner_guess(player);
        player->actor_01a8_guess->instance_0000_guess->Slot04_guess(1);
        if (player->bodyType_0270_guess >= 0x41) {
            player->actor_01a8_guess->instance_0000_guess->Slot06_guess(1);
        }
        if (value_2d58_guess != 0) {
            int bodyType = player->bodyType_0270_guess;
            if (bodyType != 8 && bodyType != 3 && bodyType != 5 && bodyType != 0xc) {
                player->FUN_0047b8d5_guess(g_tint_0043C84B_guess);
            }
        }
        player->SetAnimVariation_guess();
        player->SetDefaultFacialFeaturesByFace_guess(-1, 0, 0);
        player->RefreshFacialFeatures_guess();
        if (player->actor_01a8_guess != 0 && player->actor_01a8_guess->model_012c_guess != 0 &&
            player->actor_01a8_guess->model_012c_guess->value_0034_guess != 0) {
            scale = player->FUN_004899cc_guess();
            switch (player->race_0260_guess) {
            case 7:
                if (player->height_023c_guess == 5.5f) {
                    player->SetAvatarHeight_guess(5.3f);
                }
                break;
            case 9:
                if (player->height_023c_guess == 8.0f) {
                    player->SetAvatarHeight_guess(7.5f);
                }
                break;
            case 10:
                if (player->height_023c_guess == 9.0f) {
                    player->SetAvatarHeight_guess(8.8f);
                }
                break;
            case 0x80:
                if (player->height_023c_guess == 6.0f) {
                    player->SetAvatarHeight_guess(6.5f);
                }
                break;
            case 0x14a:
                if (player->height_023c_guess == 6.0f) {
                    player->SetAvatarHeight_guess(5.0f);
                }
                break;
            }
            player->eyeHeight_0234_guess = scale;
        }
    }
    player->SetPlayerPitchType_guess();
}

struct TextReceiver_0043D7C5_guess {
    char text_guess[0x40];
    // EXTERNAL: TITANIUM 0x0040E25C TextReceiver_0043D7C5_guess::FUN_0040e25c_guess
    char FUN_0040e25c_guess(const char* text_guess);
};

struct PlayerActor_0043D7C5_guess {
    unsigned char pad_0000_guess[0x48];
    float floorHeight_0048_guess;
    unsigned char pad_004c_guess[0x150 - 0x4c];
    unsigned char value_0150_guess;
    unsigned char pad_0151_guess[0x158 - 0x151];
    int value_0158_guess;
    unsigned char pad_015c_guess[4];
    int rider_0160_guess;
    unsigned char pad_0164_guess[0xf94 - 0x164];
    int value_f94_guess;
};

struct Motion_0043D7C5_guess {
    float value_0000_guess;
    float value_0004_guess;
    float value_0008_guess;
    float value_000c_guess;
    float value_0010_guess;
    float value_0014_guess;
    float value_0018_guess;
    unsigned char pad_001c_guess[0x24 - 0x1c];
    float value_0024_guess;
    float value_0028_guess;
};

struct Player_0043D7C5_guess {
    unsigned char pad_0000_guess[0x30];
    Motion_0043D7C5_guess motion_0030_guess;
    unsigned char pad_005c_guess[0x1a8 - 0x5c];
    PlayerActor_0043D7C5_guess* actor_01a8_guess;
    // EXTERNAL: TITANIUM 0x0048BB5A Player_0043D7C5_guess::UpdateSharedValuesIfLocal_guess
    void UpdateSharedValuesIfLocal_guess();
    // EXTERNAL: TITANIUM 0x0048C14F Player_0043D7C5_guess::FUN_0048c14f_guess
    void FUN_0048c14f_guess(char value_guess);
    // EXTERNAL: TITANIUM 0x0048A0FC Player_0043D7C5_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float first_guess, float second_guess, float third_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x0048A945 Player_0043D7C5_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
};

struct CharacterBase_0043D7C5_guess {
    unsigned char pad_0000_guess[0x2c];
    float value_002c_guess;
    float value_0030_guess;
    float value_0034_guess;
    unsigned char pad_0038_guess[0xbc - 0x38];
    TextReceiver_0043D7C5_guess receiver_00bc_guess;
    unsigned char pad_00fc_guess[0x14c - 0xfc];
    void SetPosition_0043D7C5_guess(float first_guess, float second_guess, float third_guess) {
        value_002c_guess = first_guess;
        value_0030_guess = second_guess;
        value_0034_guess = third_guess;
    }
};

struct CharacterPrefix_0043D7C5_guess {
    void* vftable_guess;
    int value_0004_guess;
};

struct CharacterView_0043D7C5_guess : CharacterPrefix_0043D7C5_guess, virtual CharacterBase_0043D7C5_guess {
    unsigned char pad_000c_guess[0xC384 - 0x0C];
};

#define g_localPlayer_0043D7C5_guess EQ_GLOBAL(Player_0043D7C5_guess*, 0x00905CE4)
#define g_cachedPlayer_0043D7C5_guess EQ_GLOBAL(Player_0043D7C5_guess*, 0x00905CF8)
#define g_value00923bcc_0043D7C5_guess EQ_GLOBAL(float, 0x00923BCC)
#define g_value00923bd0_0043D7C5_guess EQ_GLOBAL(float, 0x00923BD0)
#define g_value00923bd4_0043D7C5_guess EQ_GLOBAL(float, 0x00923BD4)
#define g_text_0043D7C5_guess EQ_ARRAY(char, 0x0063F53F)

static void SetMotionPosition_0043D7C5_guess(Motion_0043D7C5_guess* motion_guess, float first_guess,
    float second_guess, float third_guess) {
    motion_guess->value_0000_guess = first_guess;
    motion_guess->value_0004_guess = second_guess;
    motion_guess->value_0008_guess = third_guess;
}

static void ClearMotionSpeed_0043D7C5_guess(Motion_0043D7C5_guess* motion_guess) {
    motion_guess->value_000c_guess = 0.0f;
    motion_guess->value_0010_guess = 0.0f;
    motion_guess->value_0014_guess = 0.0f;
}

struct ZoneProbe_guess {
    float noFloor_0000_guess;
    Vector3_guess position_0004_guess;
};

struct ZoneScratch_guess {
    ZoneProbe_guess probe_0000_guess;
    float step_0010_guess;
};

#define g_zoneStep_guess EQ_GLOBAL(float, 0x006410BC)
#define g_zoneLimit_guess EQ_GLOBAL(float, 0x00640E20)
#define g_noFloor_guess EQ_GLOBAL(float, 0x00640EA0)

// FUNCTION: TITANIUM 0x0043D64B
// @early-stop: budget, structural ndiff=34
// Highest z of the region at (x, y, z): steps up until the region type changes. NaN or infinite z is logged.
float CDisplay_guess::FindZoneTopZ_guess(float x, float y, float z) {
    ZoneScratch_guess scratch;
    char message[512];
    if ((_isnan(z) == 0) && (_fpclass(z) != 4) && (_fpclass(z) != 0x200)) {
        scratch.probe_0000_guess.position_0004_guess.x_0000_guess = x;
        scratch.probe_0000_guess.position_0004_guess.y_0004_guess = y;
        scratch.probe_0000_guess.noFloor_0000_guess = -1.0e27f;
        scratch.step_0010_guess = 0.0f;
        unsigned char initial = (unsigned char)GetEnvironment_guess(x, y, z, 0);
        if (initial != 0) {
            while (true) {
                scratch.step_0010_guess += g_zoneStep_guess;
                scratch.probe_0000_guess.position_0004_guess.z_0008_guess = scratch.step_0010_guess + z;
                if ((g_service_guess->Slot12_guess(&scratch.probe_0000_guess.position_0004_guess) == 0) ||
                    (scratch.step_0010_guess > g_zoneLimit_guess)) {
                    break;
                }
                unsigned char current = (unsigned char)GetEnvironment_guess(
                    scratch.probe_0000_guess.position_0004_guess.x_0000_guess,
                    scratch.probe_0000_guess.position_0004_guess.y_0004_guess,
                    scratch.probe_0000_guess.position_0004_guess.z_0008_guess, 0);
                if (current != initial) {
                    return scratch.step_0010_guess - g_zoneStep_guess + z;
                }
            }
        } else {
            return scratch.probe_0000_guess.noFloor_0000_guess;
        }
    } else {
        sprintf(message,
            (const char*)EQ_ARRAY(char, 0x006426D0), (double)z);
        FUN_00574110_guess(message);
        OutputDebugStringA(message);
    }
    return g_noFloor_guess;
}

// FUNCTION: TITANIUM 0x0043D7C5
// Moves the player to the zone's safe point (0x00923BCC), and the spawn at 0x00905CF8 when it is moving.
void CDisplay_guess::MoveLocalPlayerToSafeCoords_guess() {
    SetMotionPosition_0043D7C5_guess(&g_localPlayer_0043D7C5_guess->motion_0030_guess,
        g_value00923bcc_0043D7C5_guess, g_value00923bd0_0043D7C5_guess,
        g_value00923bd4_0043D7C5_guess);
    g_localPlayer_0043D7C5_guess->UpdateSharedValuesIfLocal_guess();
    g_localPlayer_0043D7C5_guess->FUN_0048c14f_guess(1);
    ClearMotionSpeed_0043D7C5_guess(&g_localPlayer_0043D7C5_guess->motion_0030_guess);
    g_localPlayer_0043D7C5_guess->motion_0030_guess.value_0028_guess = 0.0f;
    g_localPlayer_0043D7C5_guess->motion_0030_guess.value_0024_guess = 0.0f;
    g_localPlayer_0043D7C5_guess->motion_0030_guess.value_0018_guess = 0.0f;
    g_localPlayer_0043D7C5_guess->actor_01a8_guess->value_0150_guess = 0;
    g_localPlayer_0043D7C5_guess->actor_01a8_guess->value_0158_guess = 0;
    g_localPlayer_0043D7C5_guess->actor_01a8_guess->value_f94_guess = 0;
    if (pCharData != 0) {
        ((CharacterView_0043D7C5_guess*)pCharData)->receiver_00bc_guess.FUN_0040e25c_guess(g_text_0043D7C5_guess);
        ((CharacterView_0043D7C5_guess*)pCharData)->SetPosition_0043D7C5_guess(
            g_value00923bcc_0043D7C5_guess, g_value00923bd0_0043D7C5_guess,
            g_value00923bd4_0043D7C5_guess);
    }
    float result_guess = g_localPlayer_0043D7C5_guess->GetFloorHeightAt_guess(
        g_value00923bcc_0043D7C5_guess, g_value00923bd0_0043D7C5_guess,
        g_value00923bd4_0043D7C5_guess + 1.0f, 1);
    if (result_guess != -1e27f) {
        g_localPlayer_0043D7C5_guess->actor_01a8_guess->floorHeight_0048_guess = result_guess;
    }
    g_localPlayer_0043D7C5_guess->FUN_0048a945_guess();
    if (g_cachedPlayer_0043D7C5_guess != 0 && g_cachedPlayer_0043D7C5_guess != g_localPlayer_0043D7C5_guess &&
        (g_cachedPlayer_0043D7C5_guess->actor_01a8_guess->value_0158_guess != 0 ||
         g_cachedPlayer_0043D7C5_guess->actor_01a8_guess->rider_0160_guess != 0)) {
        SetMotionPosition_0043D7C5_guess(&g_cachedPlayer_0043D7C5_guess->motion_0030_guess,
            g_value00923bcc_0043D7C5_guess, g_value00923bd0_0043D7C5_guess,
            g_value00923bd4_0043D7C5_guess);
        float cachedResult_guess = g_cachedPlayer_0043D7C5_guess->GetFloorHeightAt_guess(
            g_value00923bcc_0043D7C5_guess, g_value00923bd0_0043D7C5_guess,
            g_value00923bd4_0043D7C5_guess + 1.0f, 1);
        if (cachedResult_guess != -1e27f) {
            g_cachedPlayer_0043D7C5_guess->actor_01a8_guess->floorHeight_0048_guess = cachedResult_guess;
        }
        g_cachedPlayer_0043D7C5_guess->FUN_0048a945_guess();
    }
}

struct IndexTable_guess {
    unsigned char pad_0000_guess[0x1ac8];
    int values_1ac8_guess[9];
};

// EXTERNAL: TITANIUM 0x005ED490 GetIndexTable_guess
IndexTable_guess* __cdecl GetIndexTable_guess();

struct IndexAccessor_guess {
    int GetValue_guess(int index);
};

// FUNCTION: TITANIUM 0x0043DA4A
// Index 9 passes the range check but breaks into the debugger on the array bound: original behaviour.
int IndexAccessor_guess::GetValue_guess(int index) {
    if ((index < 0) || (index > 9)) {
        return 0;
    }
    int* values = GetIndexTable_guess()->values_1ac8_guess;
    if ((unsigned int)index >= 9) {
        __debugbreak();
    }
    return values[index];
}

struct EverQuestOwner_guess {
    unsigned char pad_0000_guess[0xb54];
    int value_0b54_guess;
    // EXTERNAL: TITANIUM 0x004AE865 EverQuestOwner_guess::ReadFonts_guess
    void ReadFonts_guess(const char* section, const char* key, const char* fallback,
        char* buffer, int size, int flag);
    // EXTERNAL: TITANIUM 0x004B102D EverQuestOwner_guess::FUN_004b102d_guess
    void FUN_004b102d_guess();
    // EXTERNAL: TITANIUM 0x00491459 EverQuestOwner_guess::DisconnectChatServer_guess
    void DisconnectChatServer_guess();
    // EXTERNAL: TITANIUM 0x004914B5 EverQuestOwner_guess::DisconnectMailServer_guess
    void DisconnectMailServer_guess();
    // EXTERNAL: TITANIUM 0x004AE9C6 EverQuestOwner_guess::FUN_004ae9c6_guess
    void FUN_004ae9c6_guess();
};

#define g_everQuestOwner_guess EQ_GLOBAL(EverQuestOwner_guess*, 0x00988DF0)
#define g_client_guess EQ_GLOBAL(CDisplay_guess*, 0x00905D24)

// Destructor: frees the chat- and mail-server connection objects, shuts the display down if InitDisplay
// ran (+0x2CFC), then frees the two work buffers.
// FUNCTION: TITANIUM 0x0043DCA1
CDisplay_guess::~CDisplay_guess() {
    g_everQuestOwner_guess->DisconnectChatServer_guess();
    g_everQuestOwner_guess->DisconnectMailServer_guess();
    if (displayInitialized_2cfc_guess != 0) {
        g_client_guess->ShutdownDisplay_guess();
    }
    free(buffer_011c_guess);
    free(buffer_0120_guess);
}

// EXTERNAL: TITANIUM 0x00464AFB GetMaterialSlotFromInvSlot_guess
int __cdecl GetMaterialSlotFromInvSlot_guess(int value);

struct DirRecord_guess {
    // EXTERNAL: TITANIUM 0x005E0DA0 DirRecord_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x005E0B90 DirRecord_guess::Value_guess
    int Value_guess();
    // EXTERNAL: TITANIUM 0x005E0F00 DirRecord_guess::Text_guess
    char* Text_guess();
};

struct DirSlot_guess {
    unsigned char pad_0000_guess[0x120c];
    unsigned char state_120c_guess;
};

struct DirObj_guess {
    unsigned char pad_0000_guess[4];
    EQ_CharacterProfile_guess profile_0004_guess;
};

struct DirSession_guess {
    unsigned char pad_0000_guess[0x244];
    unsigned char flag_0244_guess;
    unsigned char pad_0245_guess[0x254 - 0x245];
    unsigned char state_0254_guess;
    // EXTERNAL: TITANIUM 0x00479E02 DirSession_guess::LegalPlayerRace_guess
    int LegalPlayerRace_guess(int value);
    // EXTERNAL: TITANIUM 0x004845D8 DirSession_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int a, int b, int c, int d, int e);
};

struct DirLink_guess {
    unsigned char pad_0000_guess[4];
    int offset_0004_guess;
};

struct DirRoot_guess {
    unsigned char pad_0000_guess[8];
    DirLink_guess* link_0008_guess;
    unsigned char pad_000c_guess[0xc288 - 0xc];
    DirSession_guess* session_c288_guess;
};

// The slot found from root: link+8 plus the link's offset, then the profile at +4.
static DirSlot_guess* FindDirSlot_guess(DirRoot_guess* root) {
    DirObj_guess* obj = (DirObj_guess*)((int)&root->link_0008_guess + root->link_0008_guess->offset_0004_guess);
    return (DirSlot_guess*)obj->profile_0004_guess.GetCharInfo2();
}

// FUNCTION: TITANIUM 0x0043DD14
// @early-stop: budget, structural ndiff=101
// CDisplay::UpdateItemSlot (the earlier sibling decomp): the item model shown in one equipment slot (0-21) of a spawn.
void __stdcall UpdateItemSlot_guess(int p1, int p2, int p3, int p4) {
    char buf[64];
    int slot;
    long parsed;
    if (p2 >= 0x16) {
        return;
    }
    if (p1 == 0 || ((DirRoot_guess*)p1)->session_c288_guess == 0) {
        return;
    }
    DirRoot_guess& host = *(DirRoot_guess*)p1;
    slot = GetMaterialSlotFromInvSlot_guess(p2);
    if (slot == -1) {
        return;
    }
    DirRecord_guess* rec = (DirRecord_guess*)p3;
    if (rec == 0) {
        p3 = 0;
        p2 = 0;
    } else {
        p3 = rec->Count_guess();
        p2 = rec->Value_guess();
        strcpy(buf, rec->Text_guess());
        if (rec->Count_guess() > 0 || atol(buf + 2) > 0xef) {
            if (((IndexAccessor_guess*)&host)->GetValue_guess(slot) != 0) {
                p2 = ((IndexAccessor_guess*)&host)->GetValue_guess(slot);
            }
        }
    }
    DirRecord_guess* rec2 = (DirRecord_guess*)p4;
    if (p4 == 0) {
        p1 = 0;
        p4 = 0;
    } else {
        p1 = rec2->Count_guess();
        p4 = rec2->Value_guess();
    }
    if (slot == 0) {
        if (rec != 0 && rec->Text_guess() != 0 && strlen(rec->Text_guess()) > 2) {
            strcpy(buf, rec->Text_guess());
            parsed = atol(buf + 2);
            if (parsed > 0xef) {
                p3 = parsed;
            }
        }
        if (rec2 != 0 && rec2->Text_guess() != 0 && strlen(rec2->Text_guess()) > 2) {
            strcpy(buf, rec2->Text_guess());
            parsed = atol(buf + 2);
            if (parsed > 0xef) {
                p1 = parsed;
            }
        }
    }
    if (p1 != p3 || p4 != p2) {
        if ((host.session_c288_guess->state_0254_guess != 0xff || FindDirSlot_guess(&host)->state_120c_guess != 0xff) &&
            host.session_c288_guess->flag_0244_guess == 0) {
            FindDirSlot_guess(&host)->state_120c_guess = 0xff;
            if (host.session_c288_guess->LegalPlayerRace_guess(-1) != 0) {
                host.session_c288_guess->state_0254_guess = 0xff;
            }
        }
        host.session_c288_guess->HandleMaterialEx_guess(slot, p3, p1, p2, 0);
    }
}

typedef void (__cdecl *KeyHandler_guess)(KeyCallback_guess callback);

struct GlobalLoader_guess {
    virtual void LoadFile_guess(char* file, int one, int zero1, int zero2);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void SetLoadMode_guess(int mode);
    virtual void BeginLoad_guess();
    virtual void EndLoad_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void SetKeyHandlers_guess(KeyHandler_guess first, KeyHandler_guess second);
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual struct Sky_guess* CreateSky_guess(void* definition);
};

struct Sky_guess {
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
    virtual void Follow_guess(int value);
};

struct SkyOwner_guess {
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
    virtual void SetSky_guess(Sky_guess* sky);
};

struct MipOwner_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void SetMipMapping_guess(bool first, bool second);
};

struct GlobalLoadFile_guess {
    unsigned char data_0000_guess[0x1000c];
    // EXTERNAL: TITANIUM 0x00576BD0 GlobalLoadFile_guess::GlobalLoadFile_guess
    GlobalLoadFile_guess(const char* path, char separator);
    // EXTERNAL: TITANIUM 0x00576C50 GlobalLoadFile_guess::~GlobalLoadFile_guess
    ~GlobalLoadFile_guess();
    // EXTERNAL: TITANIUM 0x00576C60 GlobalLoadFile_guess::NextLine_guess
    int NextLine_guess();
    // EXTERNAL: TITANIUM 0x00576F50 GlobalLoadFile_guess::GetField_guess
    void GetField_guess(char* buffer, int size);
};

struct GlobalSettings_guess {
    // EXTERNAL: TITANIUM 0x004AE721 GlobalSettings_guess::GetBool_guess
    char GetBool_guess(const char* section, const char* key, char default_value);
    // EXTERNAL: TITANIUM 0x004AE64C GlobalSettings_guess::ReadClientIniInt_guess
    int ReadClientIniInt_guess(const char* section, const char* key, int default_value);
    // EXTERNAL: TITANIUM 0x004A56B1 GlobalSettings_guess::ProcessMBox_guess
    void ProcessMBox_guess();
};

// EXTERNAL: TITANIUM 0x00494236 DoLoadScreenProgressBar_guess
void __cdecl DoLoadScreenProgressBar_guess(GlobalSettings_guess* owner, int progress, const char* format, ...);
// EXTERNAL: TITANIUM 0x004CD3C7 ReadIniBool_guess
int __cdecl ReadIniBool_guess(const char* section, const char* key, const char* value);
// EXTERNAL: TITANIUM 0x004CD453 WriteIniString_guess
void __cdecl WriteIniString_guess(const char* section, const char* key, const char* value);

#define g_globalLoader_guess EQ_GLOBAL(GlobalLoader_guess*, 0x0099E360)
#define g_globalSettings_guess EQ_GLOBAL(GlobalSettings_guess*, 0x00988DF0)
#define g_skyOwner_guess EQ_GLOBAL(SkyOwner_guess*, 0x0099E368)
#define g_mipOwner_guess EQ_GLOBAL(MipOwner_guess*, 0x0099E364)
#define g_sky_guess EQ_GLOBAL(Sky_guess*, 0x008503A8)
#define g_skyValue_guess EQ_GLOBAL(int, 0x00924964)
#define g_mipMapping_guess EQ_GLOBAL(int, 0x009249A4)
#define g_luclinEnabled_guess EQ_GLOBAL(int, 0x00923D74)
#define g_loadArmor_guess EQ_ARRAY(int, 0x00924788)

// FUNCTION: TITANIUM 0x0043DF32
// @early-stop: budget, structural ndiff=75
// Reads the render toggles, then loads the global models listed in Resources\GlobalLoad.txt, the Luclin
// or classic character and armour archives by the eqclient.ini switches, and starts the sky.
void CDisplay_guess::InitWorld_guess() {
    char flags[16];
    char name[64];
    char name2[64];
    char type[16];
    char file[64];
    char column2[16];
    char code[32];
    char message[64];
    char key[32];
    char value[32];
    int progress;
    int count;

    // Render options from eqclient.ini, then the files Resources\GlobalLoad.txt lists, stage by stage (type
    // '1', '2', ...).
    FUN_00574110_guess("Initializing global data.");
    progress = 0;
    g_globalLoader_guess->BeginLoad_guess();
    SetState2d5f_guess(g_globalSettings_guess->GetBool_guess("Defaults", "MultipassLighting", 0));
    SetState2d60_guess(g_globalSettings_guess->GetBool_guess("Defaults", "Shadows", 0));
    SetState2d61_guess(g_globalSettings_guess->GetBool_guess("Defaults", "WaterSwap", 1));
    SetState2d62_guess(g_globalSettings_guess->GetBool_guess("Defaults", "20PixelShaders", 1));
    SetState2d63_guess(g_globalSettings_guess->GetBool_guess("Defaults", "14PixelShaders", 1));
    SetState2d64_guess(g_globalSettings_guess->GetBool_guess("Defaults", "1xPixelShaders", 1));
    SetState2d65_guess(g_globalSettings_guess->GetBool_guess("Defaults", "VertexShaders", 1));
    SetActorClipPlane_guess(g_globalSettings_guess->ReadClientIniInt_guess("Options", "ActorClipPlane", 50));
    SetShadowClipPlane_guess(g_globalSettings_guess->ReadClientIniInt_guess("Options", "ShadowClipPlane", 50));
    g_globalLoader_guess->SetKeyHandlers_guess(ForEachPlayableRaceTag_guess, ForEachNonPlayableRaceTag_guess);

    GlobalLoadFile_guess* reader = new GlobalLoadFile_guess("Resources\\GlobalLoad.txt", ',');
    count = reader->NextLine_guess();
    reader->GetField_guess(type, 16);
    reader->GetField_guess(column2, 16);
    reader->GetField_guess(flags, 16);
    reader->GetField_guess(file, 64);
    reader->GetField_guess(message, 64);

    while (count > 0 && type[0] == '1') {
        if (strstr(file, ".eqg") == 0) {
            strcpy(name, file);
            strcpy(name2, file);
            LoadWorldFile_guess((int)name, (int)name2, flags[0] == 'T', flags[1] == 'T',
                flags[2] == 'T', flags[3] == 'T');
            progress++;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, message);
        } else {
            g_globalLoader_guess->LoadFile_guess(file, 1, 0, 0);
        }
        count = reader->NextLine_guess();
        if (count == 0) {
            break;
        }
        reader->GetField_guess(type, 16);
        reader->GetField_guess(column2, 16);
        reader->GetField_guess(flags, 16);
        reader->GetField_guess(file, 64);
        reader->GetField_guess(message, 64);
    }
    while (count > 0 && type[0] == '2') {
        if (strstr(file, ".eqg") == 0) {
            strcpy(name, file);
            strcpy(name2, file);
            LoadWorldFile_guess((int)name, (int)name2, flags[0] == 'T', flags[1] == 'T',
                flags[2] == 'T', flags[3] == 'T');
            progress++;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, message);
        } else {
            g_globalLoader_guess->LoadFile_guess(file, 1, 0, 0);
        }
        count = reader->NextLine_guess();
        if (count == 0) {
            break;
        }
        reader->GetField_guess(type, 16);
        reader->GetField_guess(column2, 16);
        reader->GetField_guess(flags, 16);
        reader->GetField_guess(file, 64);
        reader->GetField_guess(message, 64);
    }

    g_globalSettings_guess->ProcessMBox_guess();
    int loadSocial;
    {
        MEMORYSTATUS status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatus(&status);
        int megabytes = (status.dwTotalPhys + 0xfffff) >> 20;
        if (megabytes >= 512) {
            loadSocial = ReadIniBool_guess("Defaults", "LoadSocialAnimations", "TRUE");
        } else {
            loadSocial = ReadIniBool_guess("Defaults", "LoadSocialAnimations", "FALSE");
            if (megabytes <= 128 && g_luclinEnabled_guess != 0) {
                WriteIniString_guess("Defaults", "AllLuclinPcModelsOff", "TRUE");
            }
        }
    }
    g_globalLoader_guess->SetLoadMode_guess(loadSocial == 1 ? 5 : 7);
    progress += 20;
    // Luclin player models for races 1-12, Iksar (128) and Vah Shir (130) (after 12 the loop jumps to 128,
    // then 130), per gender when ShouldLoadNewPcModel_guess allows: global<code>_chr2 and global<code>_chr;
    // Vah Shir also loads VEquip.
    for (int race = 1; race <= 0x82; race++) {
        if (race > 12) {
            race = race >= 0x80 ? 0x82 : 0x80;
        }
        for (int female = 0; female < 2; female++) {
            if (ShouldLoadNewPcModel_guess(race, female) != 0) {
                GetRaceModelTag_guess(code, race, female);
                DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Player Character Models");
                sprintf(name, "global%s_chr2", code);
                strcpy(name2, name);
                LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 1);
                sprintf(name, "global%s_chr", code);
                strcpy(name2, name);
                if (LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 1)) {
                    if (race == Race_VahShir) {
                        if (female == 0 || GetNewPCIniFlag_guess(0x82, 0) == 0) {
                            strcpy(name, "VEquip");
                            strcpy(name2, "VEquip");
                            LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
                        }
                    } else {
                        state_0128_guess = 1;
                    }
                }
                progress += 2;
            }
        }
    }
    g_globalLoader_guess->SetLoadMode_guess(loadSocial == 1 ? 4 : 6);

    state_0129_guess = 0;
    // Global NPC models (Luclin elementals optional), then the armour and equipment sets.
    if (ReadIniBool_guess("Defaults", "UseLuclinElementals", "TRUE") == 1) {
        progress += 2;
        state_0129_guess = 1;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Global NPC Models");
        strcpy(name, "Global5_chr2");
        strcpy(name2, "Global5_chr2");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        strcpy(name, "Global5_chr");
        strcpy(name2, "Global5_chr");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        strcpy(name, "frog_mount_chr");
        strcpy(name2, "frog_mount_chr");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
    }
    progress += 5;
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Armor and Equipment");
    if (state_0128_guess == 1) {
        progress += 2;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Armor and Equipment");
        strcpy(name, "LGEquip_amr2");
        strcpy(name2, "LGEquip_amr2");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        strcpy(name, "LGEquip_amr");
        strcpy(name2, "LGEquip_amr");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        progress += 2;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Armor and Equipment");
        strcpy(name, "LGEquip2");
        strcpy(name2, "LGEquip2");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        strcpy(name, "LGEquip");
        strcpy(name2, "LGEquip");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
    }
    g_globalLoader_guess->SetLoadMode_guess(0);
    progress += 3;
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Armor and Equipment");
    if (GetNewPCIniFlag_guess(0x82, 0) == 0 || GetNewPCIniFlag_guess(0x82, 1) == 0) {
        strcpy(name, "GEquip6");
        strcpy(name2, "GEquip6");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
        strcpy(name, "Global7_chr");
        strcpy(name2, "Global7_chr");
        LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
    }

    while (count > 0 && type[0] == '3') {
        if (strstr(file, ".eqg") == 0) {
            strcpy(name, file);
            strcpy(name2, file);
            LoadWorldFile_guess((int)name, (int)name2, flags[0] == 'T', flags[1] == 'T',
                flags[2] == 'T', flags[3] == 'T');
            progress++;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, message);
        } else {
            g_globalLoader_guess->LoadFile_guess(file, 1, 0, 0);
        }
        count = reader->NextLine_guess();
        if (count == 0) {
            break;
        }
        reader->GetField_guess(type, 16);
        reader->GetField_guess(column2, 16);
        reader->GetField_guess(flags, 16);
        reader->GetField_guess(file, 64);
        reader->GetField_guess(message, 64);
    }

    if (state_0128_guess == 0 ||
        ReadIniBool_guess("Defaults", "LoadVeliousArmorsWithLuclin", "FALSE") == 1) {
        progress += 2;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Velious Textures");
        for (int armor = 0x11; armor < 0x18; armor++) {
            sprintf(key, "LoadArmor%d", armor);
            FUN_0060be50_guess("Defaults", key, "*NULL*", value, 0x20, ".\\eqclient.ini");
            int load;
            if (value[0] == '*') {
                FUN_0060beb0_guess("Defaults", key, "FALSE", ".\\eqclient.ini");
                load = 0;
            } else if (value[0] == 'F' || value[0] == 'f' || value[0] == '0') {
                load = 0;
            } else {
                load = 1;
            }
            g_loadArmor_guess[armor] = load;
            if (load == 1) {
                progress += 2;
                DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading %s", "Velious Textures");
                sprintf(name, "Global%d_amr", armor);
                sprintf(name2, "Global%d_amr", armor);
                LoadWorldFile_guess((int)name, (int)name2, 1, 0, 0, 0);
            }
        }
    }

    while (count > 0) {
        if (strstr(file, ".eqg") == 0) {
            strcpy(name, file);
            strcpy(name2, file);
            LoadWorldFile_guess((int)name, (int)name2, flags[0] == 'T', flags[1] == 'T',
                flags[2] == 'T', flags[3] == 'T');
            progress++;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, message);
        } else {
            g_globalLoader_guess->LoadFile_guess(file, 1, 0, 0);
        }
        count = reader->NextLine_guess();
        if (count == 0) {
            break;
        }
        reader->GetField_guess(type, 16);
        reader->GetField_guess(column2, 16);
        reader->GetField_guess(flags, 16);
        reader->GetField_guess(file, 64);
        reader->GetField_guess(message, 64);
    }
    delete reader;

    FUN_00574110_guess("Initializing sky system.");
    g_sky_guess = g_globalLoader_guess->CreateSky_guess(EQ_ARRAY(void, 0x00697760));
    if (g_sky_guess == 0) {
        FUN_00574110_guess("ERROR: Failed to init sky!\n");
        g_skyValue_guess = 0;
    } else {
        g_skyOwner_guess->SetSky_guess(g_sky_guess);
        g_sky_guess->Follow_guess(g_skyValue_guess);
    }
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, 100, "Finished Loading World");
    g_mipOwner_guess->SetMipMapping_guess(g_mipMapping_guess != 0, g_mipMapping_guess != 0);
    g_globalLoader_guess->EndLoad_guess();
    FUN_00574110_guess("Global data initialized.");
}

struct CharSelectData_guess {
    SharedField_guess value_0000_guess;
    DialogObject_guess value_0004_guess;
    CharSelectComposite_guess value_001c_guess;
    CharSelectComposite_guess value_00dc_guess;
    CopyBlock_guess value_019c_guess;
    CopyBlock_guess value_01c8_guess;
    CopyBlock_guess value_01f4_guess;
    CopyBlock_guess value_0220_guess;
    ExtendedCopy_guess value_024c_guess;
    ExtendedCopy_guess value_0294_guess;
    CharSelectData_guess* CopyFrom_guess(const CharSelectData_guess* source);
};

// Assignment, member by member: the value at +0 (0x00571F70), the dialog object at +4, the two composites
// at +0x1C and +0xDC, four string-and-ints blocks (0x00435AC2) and two larger ones (0x00437B89).
// FUNCTION: TITANIUM 0x0043EDC9
CharSelectData_guess* CharSelectData_guess::CopyFrom_guess(const CharSelectData_guess* source) {
    value_0000_guess.Assign_guess(&source->value_0000_guess);
    value_0004_guess.CopyFrom_guess(&source->value_0004_guess);
    value_001c_guess.CopyFrom_guess(&source->value_001c_guess);
    value_00dc_guess.CopyFrom_guess(&source->value_00dc_guess);
    value_019c_guess.CopyFrom_guess(&source->value_019c_guess);
    value_01c8_guess.CopyFrom_guess(&source->value_01c8_guess);
    value_01f4_guess.CopyFrom_guess(&source->value_01f4_guess);
    value_0220_guess.CopyFrom_guess(&source->value_0220_guess);
    value_024c_guess.CopyFrom_guess(&source->value_024c_guess);
    value_0294_guess.CopyFrom_guess(&source->value_0294_guess);
    return this;
}

struct UiPaths_guess {
    // EXTERNAL: TITANIUM 0x0060C590 UiPaths_guess::SetPath_guess
    void SetPath_guess(int index, const CXStr& path);
    // EXTERNAL: TITANIUM 0x0060C0E0 UiPaths_guess::SetDefaultPath_guess
    void SetDefaultPath_guess(int index, const CXStr& path);
};

struct XmlResource_guess {
    unsigned char pad_0000_guess[0x260];
    unsigned char error_0260_guess;
    unsigned char pad_0261_guess[3];
    CXStr errorText_0264_guess;
    // EXTERNAL: TITANIUM 0x005B60B0 XmlResource_guess::Load_guess
    int Load_guess(const CXStr& skinPath, const CXStr& defaultPath, const CXStr& fileName);
    // EXTERNAL: TITANIUM 0x005B4530 XmlResource_guess::Find_guess
    CharSelectData_guess* Find_guess(const CXStr& name);
};

struct UiTextures_guess {
    // EXTERNAL: TITANIUM 0x005ACDE0 UiTextures_guess::Load_guess
    void Load_guess(const char* path);
};

struct UiOwner_guess {
    unsigned char pad_0000_guess[0x118];
    UiTextures_guess textures_0118_guess;
};

struct EQConfig_guess {
    unsigned char pad_0000_guess[0x3a1ba];
    unsigned char guide_3a1ba_guess;
    // EXTERNAL: TITANIUM 0x004AE919 EQConfig_guess::GetFlag_guess
    unsigned char GetFlag_guess(const char* section, const char* key, unsigned char value, unsigned char save);
};

// EXTERNAL: TITANIUM 0x0060B530 ResetUIErrors_guess
void __cdecl ResetUIErrors_guess();
// EXTERNAL: TITANIUM 0x0060B580 WriteUIError_guess
void __cdecl WriteUIError_guess(const char* message);
// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
    const char* defaultValue, char* value, int size, char useDefault);
// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key, const char* value);
// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
char __cdecl FileExists_guess(const char* path);

#define g_uiPaths_guess EQ_GLOBAL(UiPaths_guess, 0x0099E414)
#define g_xmlResource_guess EQ_GLOBAL(XmlResource_guess*, 0x0099D3F4)
#define g_uiOwner_guess EQ_GLOBAL(UiOwner_guess*, 0x0099D3EC)
#define g_eqConfig_guess EQ_GLOBAL(EQConfig_guess*, 0x00988DF0)
#define g_charSelectData_guess EQ_GLOBAL(CharSelectData_guess, 0x0099D058)
#define g_skinPath_guess EQ_ARRAY(char, 0x00850990)
#define g_defaultUIPath_guess EQ_ARRAY(char, 0x006974D0)
#define g_uiError_guess EQ_ARRAY(char, 0x00850510)
#define g_uiErrorColor_guess EQ_GLOBAL(int, 0x00850988)
#define g_tellWindows_guess EQ_GLOBAL(unsigned char, 0x009254F4)
#define g_contextMenus_guess EQ_GLOBAL(unsigned char, 0x009254ED)
#define g_ctrlBypass_guess EQ_GLOBAL(unsigned char, 0x009254F5)

// Loads the UI: the skin and atlas folders, then EQUI.xml (or EQUI_GUIDE.xml for a GM) and the default
// textures. A skin that fails to parse falls back to the default once; if that fails too the client exits.
// FUNCTION: TITANIUM 0x00442D80
// @early-stop: budget, structural ndiff=64
void CDisplay_guess::InitNewUI_guess() {
    char skin[512];
    char atlas[512];
    char xmlName[512];
    char fullPath[1024];

    FUN_00574110_guess("Initializing UI.");
    g_uiError_guess[0] = 0;
    InitUIManager_guess();
    ResetUIErrors_guess();
    FUN_00574110_guess("Parsing UI XML.");
    // Before a character is loaded the skins come from eqclient.ini [Defaults]; in game from the [Main]
    // section, with the context-menu, tell-window and tradeskill Ctrl-bypass options.
    if (pCharData == 0) {
        FUN_0060be50_guess("Defaults", "UISkin", "Default", skin, 0x1ff, ".\\eqclient.ini");
        FUN_0060beb0_guess("Defaults", "UISkin", skin, ".\\eqclient.ini");
        FUN_0060be50_guess("Defaults", "AtlasSkin", "Default", atlas, 0x1ff, ".\\eqclient.ini");
        FUN_0060beb0_guess("Defaults", "AtlasSkin", atlas, ".\\eqclient.ini");
    } else {
        g_contextMenus_guess = g_eqConfig_guess->GetFlag_guess("Main", "ContextMenus", 1, 1);
        g_tellWindows_guess = g_eqConfig_guess->GetFlag_guess("Main", "UseTellWindows", 0, 1);
        g_ctrlBypass_guess = g_eqConfig_guess->GetFlag_guess("TradeskillWnd", "CtrlBypass", 1, 1);
        LoadStringFromUIIniFile_guess("Main", "UISkin", "Default", skin, 0x1ff, 1);
        FUN_0060bf20_guess("Main", "UISkin", skin);
        LoadStringFromUIIniFile_guess("Main", "AtlasSkin", "Default", atlas, 0x1ff, 1);
        FUN_0060bf20_guess("Main", "AtlasSkin", atlas);
    }
    size_t len = strlen(skin);
    if (skin[len - 1] != '\\') {
        skin[len] = '\\';
        skin[len + 1] = 0;
    }
    sprintf(g_skinPath_guess, "UIFiles\\%s", skin);
    g_uiPaths_guess.SetPath_guess(0, g_skinPath_guess);
    const char* defaultPath = g_defaultUIPath_guess;
    g_uiPaths_guess.SetDefaultPath_guess(0, defaultPath);

    len = strlen(atlas);
    if (atlas[len - 1] != '\\') {
        atlas[len] = '\\';
        atlas[len + 1] = 0;
    }
    CXStr atlasPath("Atlas\\");
    atlasPath += atlas;
    g_uiPaths_guess.SetPath_guess(1, atlasPath);
    g_uiPaths_guess.SetDefaultPath_guess(1, "Atlas\\Default\\");

    // A GM gets EQUI_GUIDE.xml when the default folder has it, which also turns on the guide windows.
    strcpy(xmlName, "EQUI_GUIDE.xml");
    sprintf(fullPath, "%s%s", defaultPath, xmlName);
    if (g_localPlayer_436039_guess != 0 && g_localPlayer_436039_guess->GM != 0 && FileExists_guess(fullPath)) {
        g_eqConfig_guess->guide_3a1ba_guess = 1;
    } else {
        strcpy(xmlName, "EQUI.xml");
    }
    g_xmlResource_guess->Load_guess(g_skinPath_guess, defaultPath, xmlName);

    // Parse error: errors go to UIErrors.txt; a custom skin retries with Default, else everything is torn
    // down, a message box shows and the process exits.
    if (g_xmlResource_guess->error_0260_guess) {
        CXStr error(g_xmlResource_guess->errorText_0264_guess);
        WriteUIError_guess(error);
        bool retry = _stricmp(skin, "Default\\") != 0;
        if (retry) {
            sprintf(g_uiError_guess, "Error loading skin \"%s\", attempting to load default.", skin);
            g_uiErrorColor_guess = 0xd;
            FUN_00574110_guess("UI ERROR: %s", g_uiError_guess);
            WriteUIError_guess("Error loading skin: loading default skin instead.");
            ResetUI_guess();
            InitUIManager_guess();
            strcpy(g_skinPath_guess, defaultPath);
            g_uiPaths_guess.SetPath_guess(0, g_skinPath_guess);
            g_xmlResource_guess->Load_guess(g_skinPath_guess, defaultPath, xmlName);
        }
        if (!retry || g_xmlResource_guess->error_0260_guess) {
            CXStr text(g_xmlResource_guess->errorText_0264_guess);
            FUN_00574110_guess("UI ERROR: %s", text.Ptr);
            WriteUIError_guess(text);
            if (g_uiManagerRelease_guess != 0) {
                g_uiManagerRelease_guess->Slot00_guess(1);
            }
            g_uiManagerRelease_guess = 0;
            if (g_uiResourceRelease_guess != 0) {
                g_uiResourceRelease_guess->Slot00_guess(1);
            }
            g_uiResourceRelease_guess = 0;
            delete g_uiOptional_guess;
            g_uiOptional_guess = 0;
            g_stateDispatch_guess->Slot20_guess();
            g_service_guess->Slot47_guess();
            ReleaseMouse_guess();
            DestroyWindow((HWND)window_28e4_guess);
            MessageBoxA(0, "Error in your GUI XML files.  Check UIErrors.txt.", "Error in XML", 0);
            FUN_00574110_guess("Unable to continue, exiting.");
            _exit(0);
        }
    }

    FUN_00574110_guess("Loading default UI resources.");
    CharSelectData_guess* data = g_xmlResource_guess->Find_guess("WDT_Def");
    if (data != 0) {
        g_charSelectData_guess.CopyFrom_guess(data);
    }
    const char* path = g_skinPath_guess;
    if (skin[0] == '\\') {
        path = defaultPath;
    }
    g_uiOwner_guess->textures_0118_guess.Load_guess(path);
}

#include "titanium/layouts/shared_classes.h"

// FUNCTION: TITANIUM 0x00440F51
// The class is a view of CDisplay: this is CDisplay::SetViewAngle (the field of view).
void ClockData_guess::SetViewAngle(int value) {
    fieldOfView_28e8_guess = (float)value;
    ChangeVideoMode_guess();
}

struct SetupFloat_guess {
    unsigned char pad_0000_guess[0x40];
    float value_0040_guess;
};

struct CharacterSlot_guess {
    // EXTERNAL: TITANIUM 0x004106A3 CharacterSlot_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first, int second, int third, int fourth);
};

struct CharacterStat_guess {
    // EXTERNAL: TITANIUM 0x005ED550 CharacterStat_guess::FUN_005ed550_guess
    int FUN_005ed550_guess();
    unsigned char pad_0000_guess[0xC280];
    CharacterSlot_guess slot_c280_guess;
};

#define g_characterStat_guess EQ_GLOBAL(CharacterStat_guess*, 0x00905D00)
#define g_stateCopy_guess EQ_GLOBAL(int, 0x008503AC)
#define g_setupTable_guess EQ_ARRAY(SetupFloat_guess*, 0x009254FC)

// FUNCTION: TITANIUM 0x00440F63
// Steps to the next camera mode (0x00850CCC); mode 8 doesn't cycle.
void CDisplay_guess::CycleCamera_guess() {
    int oldState = g_pickDisabled_guess;
    int state = g_pickDisabled_guess;
    if (g_pickDisabled_guess != 8) {
        int level = g_characterStat_guess->FUN_005ed550_guess();
        if (level >= 0x46) {
            state = 0;
            float scale = g_setupTable_guess[g_pickDisabled_guess]->value_0040_guess;
            g_client_guess->FUN_00440f51_guess(g_characterStat_guess->FUN_005ed550_guess() - 0x46 + (int)scale);
        } else {
            if (g_pickDisabled_guess == 3 || g_pickDisabled_guess == 4) {
                g_everQuestOwner_guess->FUN_004ae9c6_guess();
            }
            if (g_pickDisabled_guess == 6) {
                state = 0;
            }
            state = state + 1;
            int value;
            if (state >= 6) {
                state = 0;
                value = 0;
                CharacterStat_guess* stat = g_characterStat_guess;
                if (stat != 0) {
                    value = stat->slot_c280_guess.TotalSpellAffects_guess(0x57, 1, 0, 1);
                }
                if (value <= 0) {
                    value = (int)g_setupTable_guess[0]->value_0040_guess;
                }
            } else {
                value = (int)g_setupTable_guess[state]->value_0040_guess;
            }
            g_client_guess->FUN_00440f51_guess(value);
        }
        if (state != oldState) {
            SetCameraMode_guess(state);
        }
        g_stateCopy_guess = state;
    }
}

struct CameraControl_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void SetFirst_guess(float value);
    virtual void Slot05_guess();
    virtual void SetSecond_guess(float value);
    virtual void Slot07_guess();
    virtual void SetThird_guess(int value);
    unsigned char pad_0004_guess[0x30];
    float angle_0034_guess;
};

struct CameraRequest_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Request_guess(int type, bool flag, int zero, float scale, int one);
};

struct PlayerState4426_guess {
    unsigned char pad_0000_guess[0x4c];
    int heading_004c_guess;
    unsigned char pad_0050_guess[0x1a8 - 0x50];
    void* association_01a8_guess;
    unsigned char pad_01ac_guess[0x23c - 0x1ac];
    float avatarHeight_023c_guess;
    unsigned char pad_0240_guess[0x24e - 0x240];
    unsigned char gender_024e_guess;
    unsigned char pad_024f_guess[0x260 - 0x24f];
    int mode_0260_guess;
    // EXTERNAL: TITANIUM 0x004899CC PlayerState4426_guess::FUN_004899cc_guess
    float FUN_004899cc_guess();
    // EXTERNAL: TITANIUM 0x0047A523 PlayerState4426_guess::GetHairKind_guess
    char GetHairKind_guess();
};

struct Association4426_guess {
    unsigned char pad_0000_guess[0x12c];
    void* value_012c_guess;
};

struct AssociationData4426_guess {
    unsigned char pad_0000_guess[0x34];
    unsigned char state_0034_guess;
};

#define g_clockData4426_guess EQ_GLOBAL(ClockData_guess*, 0x00905D24)
#define g_playerState4426_guess EQ_GLOBAL(PlayerState4426_guess*, 0x00905CE4)
#define g_cameraControlIndex4426_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_cameraControls4426_guess EQ_ARRAY(CameraControl_guess*, 0x009254FC)

// EXTERNAL: TITANIUM 0x0047C08E GetAnimation_guess
CameraRequest_guess* __cdecl GetAnimation_guess();
// Sets the view angle and the camera's eye offsets for camera view `value`, by the player's race.
// FUNCTION: TITANIUM 0x004426FB
// @early-stop: budget, structural ndiff=492
// Frames the character for a close-up view (probably char select); offsets depend on race and gender.
void CDisplay_guess::SetupCharacterViewCamera_guess(int value) {
    if (value != 0) {
    if (value != 100) {
        g_clockData4426_guess->SetViewAngle(0x46);
    }

    int mode = g_playerState4426_guess->mode_0260_guess;
    Association4426_guess* association = (Association4426_guess*)g_playerState4426_guess->association_01a8_guess;
    AssociationData4426_guess* data = association == 0 ? 0 : (AssociationData4426_guess*)association->value_012c_guess;
    // Views other than 0 (100 keeps the angle): with a model loaded, the eye height and forward
    // offset per race: Iksar (128), Vah Shir (130), Froglok (330) and the older races in the
    // switch; without a loaded model a shorter table (9, 10, 128, 130, 436) applies.
    if (data != 0 && data->state_0034_guess != 0) {
        CameraRequest_guess* request = GetAnimation_guess();
        request->Request_guess(0x47, false, 0, 1.0f, 1);
        CameraControl_guess* camera = g_cameraControls4426_guess[g_cameraControlIndex4426_guess];
        camera->SetSecond_guess(1.8f);
        camera->SetFirst_guess(0.0f);

        if (mode == 0x80) {
            if (g_playerState4426_guess->gender_024e_guess == 1) {
                camera->SetSecond_guess(2.1f);
                camera->SetFirst_guess(0.0f);
            } else {
                camera->SetSecond_guess(2.35f);
                camera->SetFirst_guess(0.1f);
            }
        } else if (mode == 0x82) {
            camera->SetFirst_guess(-0.6f);
            camera->SetSecond_guess(2.5f);
        } else if (mode == 0x14a) {
            camera->SetSecond_guess(6.0f);
            camera->SetFirst_guess(-2.5f);
        } else {
            switch (mode) {
            case 1:
                if (g_playerState4426_guess->gender_024e_guess == 0) {
                    camera->SetSecond_guess(1.4f);
                }
                break;
            case 2:
                camera->SetSecond_guess(2.1f);
                break;
            case 3:
                camera->SetSecond_guess(g_playerState4426_guess->gender_024e_guess == 0 ? 1.8f : 2.0f);
                break;
            case 6:
                camera->SetSecond_guess(1.6f);
                break;
            case 7:
                camera->SetSecond_guess(1.7f);
                break;
            case 8:
                if (g_playerState4426_guess->gender_024e_guess != 0) {
                    camera->SetSecond_guess(1.6f);
                } else {
                    camera->SetFirst_guess(-0.25f);
                }
                break;
            case 9:
                if (g_playerState4426_guess->gender_024e_guess == 1) {
                    camera->SetFirst_guess(-0.3f);
                    camera->SetSecond_guess(2.2f);
                } else {
                    camera->SetFirst_guess(-0.5f);
                }
                break;
            case 10:
                camera->SetSecond_guess(g_playerState4426_guess->gender_024e_guess == 0 ? 3.5f : 3.8f);
                break;
            case 0xb:
                if (g_playerState4426_guess->gender_024e_guess == 1) {
                    camera->SetSecond_guess(1.8f);
                }
                break;
            case 0xc:
                camera->SetFirst_guess(-0.1f);
                camera->SetSecond_guess(1.5f);
                break;
            }
        }
        if (value == 2) {
            if (g_playerState4426_guess->GetHairKind_guess() == 1) {
                CameraControl_guess* camera = g_cameraControls4426_guess[g_cameraControlIndex4426_guess];
                float angle = camera->angle_0034_guess;
                if ((g_playerState4426_guess->mode_0260_guess == 1
                        && g_playerState4426_guess->gender_024e_guess == 0)
                    || (g_playerState4426_guess->mode_0260_guess == 10
                        && g_playerState4426_guess->gender_024e_guess == 1)) {
                    camera->SetSecond_guess(angle + 1.2f);
                } else {
                    camera->SetSecond_guess(angle + 0.5f);
                }
            } else {
                CameraControl_guess* camera = g_cameraControls4426_guess[g_cameraControlIndex4426_guess];
                camera->SetThird_guess(g_playerState4426_guess->heading_004c_guess);
            }
        }
    } else {
        bool flag = mode != 0x82;
        CameraRequest_guess* request = GetAnimation_guess();
        request->Request_guess(mode == 0x82 ? 0x47 : 0x20, flag, 0, 1.0f, 1);
        CameraControl_guess* camera = g_cameraControls4426_guess[g_cameraControlIndex4426_guess];
        unsigned char state = g_playerState4426_guess->gender_024e_guess;
        if (state == 0) {
            if (mode == 10 || mode == 9) {
                camera->SetFirst_guess(-1.0f);
            } else if (mode == 8 || mode == 0xb || mode == 0xc) {
                camera->SetFirst_guess(-0.5f);
            } else {
                camera->SetFirst_guess(0.0f);
            }
        } else if (mode == 10 || mode == 9) {
            camera->SetFirst_guess(-1.0f);
        } else {
            camera->SetFirst_guess(-0.5f);
        }

        camera->SetSecond_guess(state == 0 || mode == 3 || mode == 5 ? 1.5f : 1.3f);
        if (mode == 8 || mode == 0xc || mode == 0xb) {
            camera->SetSecond_guess(state == 0 ? 2.5f : 1.5f);
        }
        if (mode == 10 || mode == 9) {
            camera->SetSecond_guess(state == 0 ? 4.0f : 3.0f);
            if (mode != 10 || state == 0) {
                return;
            }
            camera->SetSecond_guess(4.0f);
        } else if (mode == 0x80) {
            camera->SetSecond_guess(2.5f);
            camera->SetFirst_guess(0.5f);
            return;
        } else if (mode == 0x82) {
            camera->SetFirst_guess(state == 1 ? -1.2f : -0.4f);
            camera->SetSecond_guess(2.4f);
        } else if (mode == 0x1b4) {
            camera->SetSecond_guess(4.0f);
        } else {
            return;
        }
    }

    } else {
        // View 0: the wider angle, the camera lifted by the spawn's height (+0x23C) plus two units.
        g_clockData4426_guess->SetViewAngle(0x5a);
        int mode = g_playerState4426_guess->mode_0260_guess;
        CameraControl_guess* camera = g_cameraControls4426_guess[g_cameraControlIndex4426_guess];
        if (mode == 10 || mode == 9 || mode == 0x80) {
            camera->SetSecond_guess(7.0f);
            camera->SetFirst_guess(-g_playerState4426_guess->FUN_004899cc_guess() * 0.33f);
        } else {
            camera->SetSecond_guess(6.0f);
            if (mode == 0x1b4) {
                camera->SetFirst_guess(1.0f);
            } else {
                camera->SetFirst_guess(-g_playerState4426_guess->FUN_004899cc_guess() * 0.33f);
            }
        }
        camera->SetSecond_guess(g_playerState4426_guess->avatarHeight_023c_guess + 2.0f
            + camera->angle_0034_guess);
    }
}

// FUNCTION: TITANIUM 0x00440F42
// CDisplay::SetYon. `value` is really a float: SetFogState passes the float's bits.
void ClockData_guess::SetYon_guess(int value) {
    yon_0008_guess = value;
    ChangeVideoMode_guess();
}

struct FogColorProvider0044104C_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual unsigned int* GetColor_guess();
};

struct FogColorSink0044104C_guess {
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
    virtual void SetColor_guess(int one, int start, int end, unsigned int color);
};

#define g_zoneType0044104C_guess EQ_GLOBAL(unsigned char, 0x0085097C)
#define g_modeFlag0044104C_guess EQ_GLOBAL(int, 0x00924964)
#define g_colorFlagA0044104C_guess EQ_GLOBAL(unsigned char, 0x00923C3C)
#define g_colorFlagB0044104C_guess EQ_GLOBAL(unsigned char, 0x00923BBA)
#define g_colorFlagC0044104C_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_fogStart0044104C_guess EQ_GLOBAL(float, 0x00923BE0)
#define g_fogEnd0044104C_guess EQ_GLOBAL(float, 0x00923BE4)
#define g_fogScale0044104C_guess EQ_GLOBAL(int, 0x009249AC)
#define g_fogColorProvider0044104C_guess EQ_GLOBAL(FogColorProvider0044104C_guess*, 0x008503A8)
#define g_fogColorSink0044104C_guess EQ_GLOBAL(FogColorSink0044104C_guess*, 0x0099E364)

// FUNCTION: TITANIUM 0x0044104C
// @early-stop: budget, structural ndiff=175
// No range (both < 0.1) means the far clip minus 50; black fog becomes grey 0xC0. With `one` set the range is
// rescaled by the fog option (0x009249AC, 5% steps); zone types 5-10 keep their range. `one` == 0 turns fog
// off and sets the clip to 600.
void CDisplay_guess::SetFogState_guess(int one, float start, float end,
    int red, unsigned char green, unsigned char blue) {
    int updateRange = 1;
    if (state_0004_guess != 0) {
        if (g_zoneType0044104C_guess == 5 || g_zoneType0044104C_guess == 6
            || g_zoneType0044104C_guess == 7 || g_zoneType0044104C_guess == 9
            || g_zoneType0044104C_guess == 10 || g_zoneType0044104C_guess == 8) {
            updateRange = 0;
        }
        if (start < 0.1f && end < 0.1f) {
            start = yon_0008_guess - 50.0f;
            end = yon_0008_guess - 1.0f;
        }
        if (start < 0.0f) {
            start = 0.0f;
        }
        if (end < start) {
            end = start + 50.0f;
        }
        if ((unsigned char)red == 0 && green == 0 && blue == 0) {
            red = (red & 0xffffff00) | 0xc0;
            green = 0xc0;
            blue = 0xc0;
        }
        if (g_modeFlag0044104C_guess == 0) {
            state_2d2c_guess = 0;
        } else {
            state_2d2c_guess = (g_colorFlagA0044104C_guess != 0
                && g_colorFlagB0044104C_guess != 0);
            if (g_colorFlagC0044104C_guess != 0) {
                state_2d2c_guess = 1;
            }
        }
        if ((unsigned char)one != 0) {
            if (updateRange && state_014c_guess == 0) {
                start = end - start;
                end = g_fogStart0044104C_guess
                    + (g_fogEnd0044104C_guess - g_fogStart0044104C_guess)
                        * ((float)g_fogScale0044104C_guess * 0.05f);
                if (end < g_fogStart0044104C_guess) {
                    end = g_fogStart0044104C_guess;
                }
                start = end - start;
                if (start < 0.0f) {
                    start = 0.0f;
                }
            }
            state_012a_guess = (unsigned char)one;
            if (updateRange) {
                fogStart_012c_guess = start;
                fogEnd_0130_guess = end;
            }
            fogRed_0134_guess = (unsigned char)red;
            fogGreen_0135_guess = green;
            fogBlue_0136_guess = blue;
            if (end < 101.0f || g_zoneType0044104C_guess > 4) {
                state_2d2c_guess = 0;
            }
        } else {
            end = 600.0f;
        }
        if (yon_0008_guess != end) {
            ((ClockData_guess*)this)->SetYon_guess(*(int*)&end);
        }
        g_fogColorSink0044104C_guess->SetColor_guess(one, (int)start, (int)end,
            g_fogColorProvider0044104C_guess != 0 && g_modeFlag0044104C_guess != 0
                && state_2d2c_guess != 0 && g_zoneType0044104C_guess < 5
                ? *g_fogColorProvider0044104C_guess->GetColor_guess()
                : ((unsigned int)red & 0xff000000)
                    | ((unsigned int)(unsigned char)blue)
                    | ((unsigned int)(unsigned char)green << 8)
                    | (((unsigned int)red & 0xff) << 16));
    }
}

struct ModeTime_guess {
    unsigned char pad_0000_guess[4];
    unsigned char hour_0004_guess;
    unsigned char minute_0005_guess;
    unsigned char value_0006_guess;
    unsigned char value_0007_guess;
    int value_0008_guess;
    unsigned char copy_000c_guess;
    unsigned char copy_000d_guess;
    unsigned char copy_000e_guess;
    unsigned char copy_000f_guess;
    int copy_0010_guess;
    int value_0014_guess;
    int value_0018_guess;
};

#define g_modeTime_guess EQ_GLOBAL(ModeTime_guess*, 0x00905CC0)

// FUNCTION: TITANIUM 0x004459E5
// Sets the world clock (wrapped to 24 h / 60 min) and redraws the sky for it.
void CDisplay_guess::SetDayPeriod_guess(unsigned char hour, unsigned char minute) {
    g_modeTime_guess->hour_0004_guess = hour % 0x18;
    g_modeTime_guess->minute_0005_guess = minute % 0x3c;
    g_modeTime_guess->value_0014_guess = FUN_0046d655_guess();
    g_modeTime_guess->value_0018_guess = FUN_00576e80_guess();
    g_modeTime_guess->copy_000c_guess = g_modeTime_guess->hour_0004_guess;
    g_modeTime_guess->copy_000d_guess = g_modeTime_guess->minute_0005_guess;
    g_modeTime_guess->copy_000e_guess = g_modeTime_guess->value_0006_guess;
    g_modeTime_guess->copy_000f_guess = g_modeTime_guess->value_0007_guess;
    g_modeTime_guess->copy_0010_guess = g_modeTime_guess->value_0008_guess;
    SetSkyBackground_guess();
}

// Renders one frame of the world (0x00445243); the game loop calls it.
// FUNCTION: TITANIUM 0x00445A6C
void CDisplay_guess::Render_World_guess() {
    RealRender_World_guess();
}

// EXTERNAL: TITANIUM 0x004CD479 AcquireMouse_guess
void __cdecl AcquireMouse_guess(int value);
typedef unsigned int (__cdecl *DisplayCallback_guess)(char* value, unsigned int flags);
typedef void (__cdecl *GetGraphicsEngineInfo_guess)(void* info);

struct DisplayService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(DisplayCallback_guess callback);
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
    virtual void Slot26_guess(void* value);
};

struct RenderSettings_guess {
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
    virtual void Slot27_guess(float value);
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void Slot49_guess(int value, bool enabled);
};

#define g_displayService_guess EQ_GLOBAL(DisplayService_guess*, 0x0099E368)
#define g_renderSettings_guess EQ_GLOBAL(RenderSettings_guess*, 0x0099E364)
#define g_getGraphicsEngineInfo_guess EQ_GLOBAL(GetGraphicsEngineInfo_guess, 0x0099E378)
#define g_gammaValue_guess EQ_GLOBAL(float, 0x00924950)
#define g_autoMipMapping_guess EQ_GLOBAL(int, 0x009249A4)

// FUNCTION: TITANIUM 0x00443F8F
// Particles, display mode, camera, fonts, music, then the load screen.
void CDisplay_guess::InitDisplay_guess() {
    int returnCode;
    FUN_00574110_guess("Initializing display.");
    state_0128_guess = 0;
    FUN_00574110_guess("Initializing Particle System.");
    InitParticleSystem_guess();
    FUN_00574110_guess("Setting display options.");
    SetDisplayOptions_guess(&returnCode);
    FUN_00574110_guess("Display options set, return code %d.", returnCode);
    g_displayService_guess->Slot06_guess(ParseRegionName_guess);
    g_renderSettings_guess->Slot27_guess(g_gammaValue_guess * 0.1f + 0.5f);
    g_renderSettings_guess->Slot49_guess(0, g_autoMipMapping_guess != 0);
    FUN_00574110_guess("AutoMipMapping set to %d.", g_autoMipMapping_guess);
    g_displayService_guess->Slot26_guess(&callback_0118_guess);
    FUN_00574110_guess("Camera created.");
    g_viewRight_guess = g_graphicsValue2_guess;
    g_value2d04_guess = 0;
    g_value2d08_guess = 0;
    g_viewBottom_guess = g_graphicsValue3_guess;
    g_client_guess->ApplyVideoMode_guess();
    FUN_00574110_guess("Storing display options.");
    StoreDisplayOptions_guess();
    displayInitialized_2cfc_guess = 1;
    FUN_00574110_guess("Initializing fonts.");
    ((LanguageService_guess*)this)->SetLanguage_guess(g_language_guess);
    InitNewUI_guess();
    AcquireMouse_guess(0);
    FUN_00574110_guess("Initializing Music.");
    g_queue_guess->SetMusicSelection_guess(1, 1);
    FUN_00574110_guess("Activating Load Screen.");
    g_getGraphicsEngineInfo_guess(EQ_ARRAY(void, 0x0099E354));
    g_everQuestText_guess->DoLoadScreen_guess(0);
    FUN_00574110_guess("Display initialized.");
}


// Moves the handler to the point 2 units ahead of `p` along its heading (p[7]) and 4 units up, unless it
// is already within 0.1 of it (0x0043A371).
// FUNCTION: TITANIUM 0x0043D9C5
// @early-stop: budget, diff ndiff=4
void ActorUpdateManager_guess::ComparePositionAhead_guess(PositionHandler_guess* handler, float* p) {
    Vector3_guess position;
    float component = p[0];
    float cos_value = g_trig0043D9C5_guess->Cos_guess(p[7]);
    position.x_0000_guess = cos_value + cos_value + component;
    component = p[1];
    float sin_value = g_trig0043D9C5_guess->Sin_guess(p[7]);
    position.y_0004_guess = sin_value + sin_value + component;
    position.z_0008_guess = p[2] + 4.0f;
    ComparePosition_guess(handler, &position);
}

// Name-pair list read from `arg` (0x0043A41B; a count line then name pairs); the zone load reads
// <zone>_pre_chr.txt and <zone>_chr.txt with it.
// FUNCTION: TITANIUM 0x0043DA31
Slots_guess* Slots_guess::Init_guess(const char* arg) {
    entries_0000_guess = 0;
    count_0004_guess = 0;
    LoadFromFile_guess(arg);
    return this;
}

// EXTERNAL: TITANIUM 0x0044E7E4 InitAnimationTags_guess
void __cdecl InitAnimationTags_guess();
// EXTERNAL: TITANIUM 0x004CD3C7 ReadIniBool_guess
int __cdecl ReadIniBool_guess(const char* section, const char* key, const char* value);

// FUNCTION: TITANIUM 0x0043DA73
// Name sprites start on; the camera mode is 2 (0x008503AC) when 0x00923D74 is 1, else 0.
// Expect: state 0x13 stored before the EH frame, as a member initialiser (NOTES: ctor member init).
CDisplay_guess::CDisplay_guess(void* window) : state_0013_guess(0) {
    FUN_00574110_guess("Initializing display structures.");
    state_0014_guess = 0;
    state_28e0_guess = 0;
    pcNameSprites_2d5d_guess = 1;
    npcNameSprites_2d5e_guess = 1;
    buffer_011c_guess = operator new(0xc);
    buffer_0120_guess = operator new(0xc);
    EQ_GLOBAL(unsigned char, 0x006974CC) = 0;
    EQ_GLOBAL(unsigned char, 0x006974CE) = 100;
    EQ_GLOBAL(unsigned char, 0x006974CD) = 0;
    frameTime_0148_guess = 0;
    state_0145_guess = 0;
    text_2d28_guess.Assign_guess("Default");
    LoadUserDefinedColors_guess();
    EQ_GLOBAL(int, 0x008503AC) = (g_setupEnabled_guess != 1) ? 0 : 2;
    RestoreCameraMode_guess();
    InitAnimationTags_guess();
    state_0005_guess = 1;
    EQ_GLOBAL(unsigned char, 0x00924674) = 1;
    lastUpdateTime_0150_guess = 0;
    value_0154_guess = 0;
    value_0124_guess = 0;
    state_2d5c_guess = 0;
    EQ_GLOBAL(unsigned char, 0x0085097C) = 0;
    value_2cf8_guess = 0;
    displayInitialized_2cfc_guess = 0;
    particlesInitialized_2d00_guess = 0;
    state_2d54_guess = 0;
    state_0010_guess = 0;
    state_0011_guess = 0;
    state_0012_guess = 0;
    window_28e4_guess = window;
    value_0000_guess = 0;
    g_languageOutput_guess->Slot38_guess(0);
    value_28f4_guess = 1.0f;
    fieldOfView_28e8_guess = 110.0f;
    value_28ec_guess = 1.25f;
    yon_0008_guess = 600.0f;
    value_28f0_guess = 0;
    g_value850cc8_guess = 0;
    callback_0118_guess = 0;
    playerLight_2d18_guess = 0;
    value_286c_guess = 0;
    memset(buffer_015c_guess, 0, 10000);
    value_0158_guess = 0;
    torchLight_2870_guess = 0;
    magTorchLight_2874_guess = 0;
    smLanternLight_2878_guess = 0;
    lgLanternLight_287c_guess = 0;
    smMagicLight_2880_guess = 0;
    lgMagicLight_2884_guess = 0;
    candleLight_2888_guess = 0;
    value_2d20_guess = 0;
    sunLight_2d1c_guess = 0;
    value_28c4_guess = 0;
    value_28d4_guess = 4.0f;
    value_28d8_guess = 2.0f;
    value_28dc_guess = 3.0f;
    DefaultCameras_guess();
    state_2d2c_guess = 1;
    state_0004_guess = 1;
    EQ_GLOBAL(float, 0x00923D20) = 0.0f;
    EQ_GLOBAL(unsigned char, 0x00924673) = 0;
    EQ_GLOBAL(unsigned char, 0x009237B4) = 0;
    EQ_GLOBAL(unsigned char, 0x009237B6) = 0;
    state_0144_guess = ReadIniBool_guess("Defaults", "DoProperTinting", "FALSE") != 0;
}

struct CharacterCreation_guess {
    unsigned char pad_0000_guess[0x424];
    // EXTERNAL: TITANIUM 0x004EF965 CharacterCreation_guess::CharacterCreation_guess
    CharacterCreation_guess(int value);
};

struct CharacterSelectWindow_guess {
    unsigned char pad_0000_guess[0x1fc];
    // EXTERNAL: TITANIUM 0x004F116C CharacterSelectWindow_guess::CharacterSelectWindow_guess
    CharacterSelectWindow_guess(int value);
};

struct FacePickWindow_guess {
    unsigned char pad_0000_guess[0x1cc];
    // EXTERNAL: TITANIUM 0x00500DF3 FacePickWindow_guess::FacePickWindow_guess
    FacePickWindow_guess(int value);
};

struct SystemInfoDialog_guess {
    unsigned char pad_0000_guess[0x168];
    // EXTERNAL: TITANIUM 0x0055B4D1 SystemInfoDialog_guess::SystemInfoDialog_guess
    SystemInfoDialog_guess(int value);
};

struct CharSelectManager_guess {
    // EXTERNAL: TITANIUM 0x005AF630 CharSelectManager_guess::FUN_005af630_guess
    void FUN_005af630_guess();
};

#define g_characterCreation_guess EQ_GLOBAL(CharacterCreation_guess*, 0x00850C20)
#define g_characterSelectWindow_guess EQ_GLOBAL(CharacterSelectWindow_guess*, 0x00850B9C)
#define g_facePickWindow_guess EQ_GLOBAL(FacePickWindow_guess*, 0x00850BA0)
#define g_systemInfoDialog_guess EQ_GLOBAL(SystemInfoDialog_guess*, 0x009927D0)
#define g_charSelectManager_guess EQ_GLOBAL(CharSelectManager_guess*, 0x0099D3EC)

// Builds the character-select screen: tears down the game UI, creates the CharacterCreation,
// CharacterSelectWindow, FacePickWindow and SystemInfoDialogBox windows if missing, then sets the viewport
// rect to the full screen (0x0092379C x 0x009237A0) and applies the video mode.
// FUNCTION: TITANIUM 0x0043EE74
void CDisplay_guess::InitCharSelectUI_guess() {
    FUN_00574110_guess("Initializing character select UI.");
    CleanGameUI();
    if (g_characterCreation_guess == 0) {
        g_characterCreation_guess = new CharacterCreation_guess(0);
    }
    if (g_characterSelectWindow_guess == 0) {
        g_characterSelectWindow_guess = new CharacterSelectWindow_guess(0);
    }
    if (g_facePickWindow_guess == 0) {
        g_facePickWindow_guess = new FacePickWindow_guess(0);
    }
    if (g_systemInfoDialog_guess == 0) {
        g_systemInfoDialog_guess = new SystemInfoDialog_guess(0);
    }
    if (g_charSelectUi_guess == 0) {
        g_charSelectUi_guess = new CharSelectUi_guess;
    }
    g_charSelectManager_guess->FUN_005af630_guess();
    g_viewRight_guess = g_graphicsValue2_guess;
    g_value2d04_guess = 0;
    g_value2d08_guess = 0;
    g_viewBottom_guess = g_graphicsValue3_guess;
    ApplyVideoMode_guess();
}

#include "titanium/bounded_array.h"

// Game UI windows built by 0x0043EFDD: size from the `new`, constructor at the VA in the name.
struct Rect0043EFDD_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    Rect0043EFDD_guess(int left, int top, int right, int bottom)
        : left_guess(left), top_guess(top), right_guess(right), bottom_guess(bottom) {}
    Rect0043EFDD_guess(const Rect0043EFDD_guess& other);
};

struct Wnd004FD26A_guess {
    unsigned char pad_0000_guess[0x1168];
    // EXTERNAL: TITANIUM 0x004FD26A Wnd004FD26A_guess::Wnd004FD26A_guess
    Wnd004FD26A_guess(int parent, int id, Rect0043EFDD_guess rect);
};
struct Obj004EB19D_guess {
    unsigned char pad_0000_guess[0x14];
    // EXTERNAL: TITANIUM 0x004EB19D Obj004EB19D_guess::Obj004EB19D_guess
    Obj004EB19D_guess();
};
struct Obj0051A8E2_guess {
    unsigned char pad_0000_guess[0x100c];
    // EXTERNAL: TITANIUM 0x0051A8E2 Obj0051A8E2_guess::Obj0051A8E2_guess
    Obj0051A8E2_guess();
};
struct Obj004FA372_guess {
    unsigned char pad_0000_guess[0x78];
    // EXTERNAL: TITANIUM 0x004FA372 Obj004FA372_guess::Obj004FA372_guess
    Obj004FA372_guess();
};
struct Obj004F60C5_guess {
    unsigned char pad_0000_guess[0x240];
    // EXTERNAL: TITANIUM 0x004F60C5 Obj004F60C5_guess::Obj004F60C5_guess
    Obj004F60C5_guess();
};
struct Obj0051DF88_guess {
    unsigned char pad_0000_guess[0x3c];
    // EXTERNAL: TITANIUM 0x0051DF88 Obj0051DF88_guess::Obj0051DF88_guess
    Obj0051DF88_guess();
};
struct Obj00548144_guess {
    unsigned char pad_0000_guess[0x3c];
    // EXTERNAL: TITANIUM 0x00548144 Obj00548144_guess::Obj00548144_guess
    Obj00548144_guess();
};
struct Wnd00539810_guess {  // MusicPlayerWnd
    unsigned char pad_0000_guess[0x3a0];
    // EXTERNAL: TITANIUM 0x00539810 Wnd00539810_guess::Wnd00539810_guess
    Wnd00539810_guess(int parent);
    // EXTERNAL: TITANIUM 0x00539BEB Wnd00539810_guess::RestorePlaylist_guess
    void RestorePlaylist_guess();
};
struct Wnd0050C317_guess {  // GroupWindow
    unsigned char pad_0000_guess[0x1c0];
    // EXTERNAL: TITANIUM 0x0050C317 Wnd0050C317_guess::Wnd0050C317_guess
    Wnd0050C317_guess(int parent);
};
struct CBuffWindow_guess {  // BuffWindow / ShortDurationBuffWindow
    unsigned char pad_0000_guess[0x24c];
    // EXTERNAL: TITANIUM 0x004E955B CBuffWindow_guess::CBuffWindow_guess
    CBuffWindow_guess(int parent, int kind);
};
struct Wnd0055BA0F_guess {  // TargetWindow
    unsigned char pad_0000_guess[0x170];
    // EXTERNAL: TITANIUM 0x0055BA0F Wnd0055BA0F_guess::Wnd0055BA0F_guess
    Wnd0055BA0F_guess(int parent);
};
struct Wnd00513CD7_guess {  // HotButtonWnd
    unsigned char pad_0000_guess[0x20c];
    // EXTERNAL: TITANIUM 0x00513CD7 Wnd00513CD7_guess::Wnd00513CD7_guess
    Wnd00513CD7_guess(int parent, int index, char* name);
};
struct Wnd005452F7_guess {  // PlayerWindow
    unsigned char pad_0000_guess[0x180];
    // EXTERNAL: TITANIUM 0x005452F7 Wnd005452F7_guess::Wnd005452F7_guess
    Wnd005452F7_guess(int parent);
};
struct Wnd004EC8B4_guess {  // CastSpellWnd
    unsigned char pad_0000_guess[0x1b4];
    // EXTERNAL: TITANIUM 0x004EC8B4 Wnd004EC8B4_guess::Wnd004EC8B4_guess
    Wnd004EC8B4_guess(int parent);
};
struct Wnd00558521_guess {  // SpellBookWnd
    unsigned char pad_0000_guess[0x2a8];
    // EXTERNAL: TITANIUM 0x00558521 Wnd00558521_guess::Wnd00558521_guess
    Wnd00558521_guess(int parent);
};
struct Wnd00516E9A_guess {  // inventory window
    unsigned char pad_0000_guess[0x268];
    // EXTERNAL: TITANIUM 0x00516E9A Wnd00516E9A_guess::Wnd00516E9A_guess
    Wnd00516E9A_guess(int parent);
};
struct Wnd004DC838_guess {  // BankWnd / BigBankWnd
    unsigned char pad_0000_guess[0x1dc];
    // EXTERNAL: TITANIUM 0x004DC838 Wnd004DC838_guess::Wnd004DC838_guess
    Wnd004DC838_guess(int parent, CXStr name);
};
struct Wnd004D4277_guess {
    unsigned char pad_0000_guess[0x21c];
    // EXTERNAL: TITANIUM 0x004D4277 Wnd004D4277_guess::Wnd004D4277_guess
    Wnd004D4277_guess(int parent);
};
struct Wnd004F9AE1_guess {
    unsigned char pad_0000_guess[0x1b0];
    // EXTERNAL: TITANIUM 0x004F9AE1 Wnd004F9AE1_guess::Wnd004F9AE1_guess
    Wnd004F9AE1_guess(int parent);
};
struct CSelectorWnd_guess {
    unsigned char pad_0000_guess[0x220];
    // EXTERNAL: TITANIUM 0x0055279D CSelectorWnd_guess::CSelectorWnd_guess
    CSelectorWnd_guess(int parent);
};
struct CCompassWnd_guess {
    unsigned char pad_0000_guess[0x1c0];
    // EXTERNAL: TITANIUM 0x004FA183 CCompassWnd_guess::CCompassWnd_guess
    CCompassWnd_guess(int parent);
};
struct Obj0042416A_guess {
    unsigned char pad_0000_guess[0x1c];
    // EXTERNAL: TITANIUM 0x0042416A Obj0042416A_guess::Obj0042416A_guess
    Obj0042416A_guess();
};
struct Obj004C3AB3_guess {
    unsigned char pad_0000_guess[0x1c];
    // EXTERNAL: TITANIUM 0x004C3AB3 Obj004C3AB3_guess::Obj004C3AB3_guess
    Obj004C3AB3_guess();
};
struct Obj004B1473_guess {
    unsigned char pad_0000_guess[0x1c];
    // EXTERNAL: TITANIUM 0x004B1473 Obj004B1473_guess::Obj004B1473_guess
    Obj004B1473_guess();
};
struct Obj004B1325_guess {
    unsigned char pad_0000_guess[0x1c];
    // EXTERNAL: TITANIUM 0x004B1325 Obj004B1325_guess::Obj004B1325_guess
    Obj004B1325_guess();
};
struct Obj00401745_guess {
    unsigned char pad_0000_guess[0x3c];
    // EXTERNAL: TITANIUM 0x00401745 Obj00401745_guess::Obj00401745_guess
    Obj00401745_guess();
};

// Window vtable view: slot 33 (+0x84) is called right after two of the windows are built.
struct VWnd0043EFDD_guess {
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
};
struct Wnd004C7DE4_guess : VWnd0043EFDD_guess {
    unsigned char pad_0004_guess[0x188 - 4];
    // EXTERNAL: TITANIUM 0x004C7DE4 Wnd004C7DE4_guess::Wnd004C7DE4_guess
    Wnd004C7DE4_guess(int parent);
    // EXTERNAL: TITANIUM 0x004C799A Wnd004C7DE4_guess::ShouldAutoOpen_guess
    bool ShouldAutoOpen_guess();
};
struct Obj00407706_guess {
    unsigned char pad_0000_guess[0x190];
    // EXTERNAL: TITANIUM 0x00407706 Obj00407706_guess::Obj00407706_guess
    Obj00407706_guess();
};
struct Wnd0055D8CA_guess {
    unsigned char pad_0000_guess[0x214];
    // EXTERNAL: TITANIUM 0x0055D8CA Wnd0055D8CA_guess::Wnd0055D8CA_guess
    Wnd0055D8CA_guess(int parent);
};
struct Wnd00563FBB_guess : VWnd0043EFDD_guess {
    unsigned char pad_0004_guess[0x13c - 4];
    // EXTERNAL: TITANIUM 0x00563FBB Wnd00563FBB_guess::Wnd00563FBB_guess
    Wnd00563FBB_guess(unsigned int seconds);
};

struct Obj009232F0_guess {
    // EXTERNAL: TITANIUM 0x004084BA Obj009232F0_guess::FUN_004084ba_guess
    void FUN_004084ba_guess();
};
struct Obj00985CF0_guess {
    // EXTERNAL: TITANIUM 0x004C9C3E Obj00985CF0_guess::RefreshTicketWindow_guess
    void RefreshTicketWindow_guess();
};
struct IconAnim0043EFDD_guess {
    // EXTERNAL: TITANIUM 0x005B1BB0 IconAnim0043EFDD_guess::FUN_005b1bb0_guess
    void FUN_005b1bb0_guess();
};
struct IconOwner0043EFDD_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 IconOwner0043EFDD_guess::FUN_005b44a0_guess
    IconAnim0043EFDD_guess* FUN_005b44a0_guess(const CXStr& name);
};

// EQ_PC view: 8 bytes, the vbptr, bank slots at +0xCF0; GetCharInfo2 sits at +4 of the virtual base.
struct CharInfo0043EFDD_guess {
    unsigned char pad_0000_guess[0x11a4];
    int level_11a4_guess;
};
struct PcHead0043EFDD_guess {
    unsigned char pad_0000_guess[8];
};
struct PcVBase0043EFDD_guess {
    void* vftable_guess;
    EQ_CharacterProfile_guess profile_0004_guess;
    CharInfo0043EFDD_guess* GetInfo_guess() { return (CharInfo0043EFDD_guess*)profile_0004_guess.GetCharInfo2(); }
};
struct Pc0043EFDD_guess : PcHead0043EFDD_guess, virtual PcVBase0043EFDD_guess {
    unsigned char pad_000c_guess[0xcf0 - 0xc];
    BoundedArray_guess<int, 16> bank_0cf0_guess;
};

// EXTERNAL: TITANIUM 0x004FFAB8 InitIconCaches_guess
void __cdecl InitIconCaches_guess();
// EXTERNAL: TITANIUM 0x0046C627 LoadViewportRect_guess
void __cdecl LoadViewportRect_guess();
// EXTERNAL: TITANIUM 0x00576FA0 FUN_00576fa0_guess
void __cdecl FUN_00576fa0_guess(char* destination, const char* source, int size);
// EXTERNAL: TITANIUM 0x00576FD0 FUN_00576fd0_guess
void __cdecl FUN_00576fd0_guess(char* destination, const char* source, int size);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value, char* buffer, int radix);

#define g_pc0043EFDD_guess EQ_GLOBAL(Pc0043EFDD_guess*, 0x00905D00)
#define g_iconOwner0043EFDD_guess EQ_GLOBAL(IconOwner0043EFDD_guess*, 0x0099D3F4)
#define g_hotButtonWnds_guess EQ_ARRAY(Wnd00513CD7_guess*, 0x00991AE4)
#define g_hotButtonName_guess EQ_GLOBAL(const char*, 0x00792E94)
#define g_numberText_guess EQ_ARRAY(char, 0x0099DB00)
#define g_mailEnabled_guess EQ_GLOBAL(unsigned char, 0x00923D65)
#define g_expansion9247A0_guess EQ_GLOBAL(int, 0x009247A0)
#define g_expansion9247A4_guess EQ_GLOBAL(int, 0x009247A4)
#define g_expansion9247A8_guess EQ_GLOBAL(int, 0x009247A8)
#define g_expansion9247AC_guess EQ_GLOBAL(int, 0x009247AC)
#define g_expansion9247B0_guess EQ_GLOBAL(int, 0x009247B0)
#define g_timerEnd985840_guess EQ_GLOBAL(int, 0x00985840)
#define g_wnd850CA0_guess EQ_GLOBAL(Wnd004C7DE4_guess*, 0x00850CA0)
#define g_wnd850C94_guess EQ_GLOBAL(Wnd00563FBB_guess*, 0x00850C94)
#define g_wnd850BE0_guess EQ_GLOBAL(Wnd00539810_guess*, 0x00850BE0)
#define g_wnd850C38_guess EQ_GLOBAL(Wnd004DC838_guess*, 0x00850C38)

// Builds the in-game UI (the game-UI init step): creates each game window once (zoning reuses them;
// expansion flags gate some), picks BigBankWnd or BankWnd, adds the GM windows when the guide setting
// is on, then loads the animated icons (A_InvEar, A_DragItem, spell icons and book pages), applies the
// Shadows setting and resets the viewport.
// FUNCTION: TITANIUM 0x0043EFDD
// @early-stop: budget, structural ndiff=245
void CDisplay_guess::InitGameUI_guess() {
    char name[0x400];
    // Every game window is created once (a null global means not made yet), so zoning reuses them; the
    // expansion flags at 0x009247A0.. gate their expansions' windows.
    FUN_00574110_guess("Initializing game UI.");
    InitIconCaches_guess();
    if (EQ_GLOBAL(Wnd004FD26A_guess*, 0x0099D414) == 0) {
        EQ_GLOBAL(Wnd004FD26A_guess*, 0x0099D414) = new Wnd004FD26A_guess(0, 0, Rect0043EFDD_guess(0, 0, 1, 1));
    }
    if (EQ_GLOBAL(Obj004EB19D_guess*, 0x00991758) == 0) {
        EQ_GLOBAL(Obj004EB19D_guess*, 0x00991758) = new Obj004EB19D_guess;
    }
    if (pinstCCursorAttachment_guess == 0) {
        pinstCCursorAttachment_guess = new CCursorAttachment_guess(0);
    }
    if (pinstCSocialEditWnd_guess == 0) {
        pinstCSocialEditWnd_guess = new CSocialEditWnd_guess(0);
    }
    if (EQ_GLOBAL(Obj0051A8E2_guess*, 0x00850CB8) == 0) {
        EQ_GLOBAL(Obj0051A8E2_guess*, 0x00850CB8) = new Obj0051A8E2_guess;
    }
    if (EQ_GLOBAL(Obj004FA372_guess*, 0x00850CBC) == 0) {
        EQ_GLOBAL(Obj004FA372_guess*, 0x00850CBC) = new Obj004FA372_guess;
    }
    if (EQ_GLOBAL(Obj004F60C5_guess*, 0x009917E4) == 0) {
        EQ_GLOBAL(Obj004F60C5_guess*, 0x009917E4) = new Obj004F60C5_guess;
    }
    if (g_mailEnabled_guess != 0) {
        if (pinstCMailWnd_guess == 0) {
            pinstCMailWnd_guess = new CMailWnd_guess(0);
        }
        if (pinstCMailCompositionWnd_guess == 0) {
            pinstCMailCompositionWnd_guess = new CMailCompositionWnd_guess(0);
        }
        if (pinstCMailAddressBookWnd_guess == 0) {
            pinstCMailAddressBookWnd_guess = new CMailAddressBookWnd_guess(0);
        }
    }
    if (g_facePickWindow_guess == 0) {
        g_facePickWindow_guess = new FacePickWindow_guess(0);
    }
    if (EQ_GLOBAL(Obj0051DF88_guess*, 0x00991B88) == 0) {
        EQ_GLOBAL(Obj0051DF88_guess*, 0x00991B88) = new Obj0051DF88_guess;
    }
    if (EQ_GLOBAL(Obj00548144_guess*, 0x00991E44) == 0) {
        EQ_GLOBAL(Obj00548144_guess*, 0x00991E44) = new Obj00548144_guess;
    }
    if (pinstCNoteWnd_guess == 0) {
        pinstCNoteWnd_guess = new CNoteWnd_guess(0);
    }
    if (pinstCTipWndOFDAY_guess == 0) {
        pinstCTipWndOFDAY_guess = new CTipWnd_guess(0, 0);
    }
    if (pinstCTipWndCONTEXT_guess == 0) {
        pinstCTipWndCONTEXT_guess = new CTipWnd_guess(0, 1);
    }
    if (pinstCBookWnd_guess == 0) {
        pinstCBookWnd_guess = new CBookWnd_guess(0);
    }
    if (pinstCFriendsWnd_guess == 0) {
        pinstCFriendsWnd_guess = new CFriendsWnd_guess(0);
    }
    if (pinstCRespawnWnd_guess == 0) {
        pinstCRespawnWnd_guess = new CRespawnWnd_guess(0);
    }
    if (pinstCServerListWnd_guess == 0) {
        pinstCServerListWnd_guess = new CServerListWnd_guess(0);
    }
    if (pinstCMIZoneSelectWnd_guess == 0) {
        pinstCMIZoneSelectWnd_guess = new CMIZoneSelectWnd_guess(0);
    }
    if (g_expansion9247B0_guess != 0) {
        if (pinstCBandolierWnd_guess == 0) {
            pinstCBandolierWnd_guess = new CBandolierWnd_guess(0);
        }
        if (pinstCPotionBeltWnd_guess == 0) {
            pinstCPotionBeltWnd_guess = new CPotionBeltWnd_guess(0);
        }
    }
    if (g_wnd850BE0_guess == 0) {
        g_wnd850BE0_guess = new Wnd00539810_guess(0);
        g_wnd850BE0_guess->RestorePlaylist_guess();
    }
    if (pinstCAlarmWnd_guess == 0) {
        pinstCAlarmWnd_guess = new CAlarmWnd_guess(0);
    }
    if (pinstCLoadskinWnd_guess == 0) {
        pinstCLoadskinWnd_guess = new CLoadskinWnd_guess(0);
    }
    if (pinstCPetInfoWnd_guess == 0) {
        pinstCPetInfoWnd_guess = new CPetInfoWnd_guess(0);
    }
    if (pinstCTrainWnd_guess == 0) {
        pinstCTrainWnd_guess = new CTrainWnd_guess(0);
    }
    if (pinstCSkillsWnd_guess == 0) {
        pinstCSkillsWnd_guess = new CSkillsWnd_guess(0);
    }
    if (pinstCSkillsSelectWnd_guess == 0) {
        pinstCSkillsSelectWnd_guess = new CSkillsSelectWnd_guess(0);
    }
    if (pinstCCombatSkillSelectWnd_guess == 0) {
        pinstCCombatSkillSelectWnd_guess = new CCombatSkillSelectWnd_guess(0);
    }
    if (pinstCAAWnd_guess == 0) {
        pinstCAAWnd_guess = new CAAWnd_guess(0);
    }
    if (EQ_GLOBAL(Wnd0050C317_guess*, 0x00991A74) == 0) {
        EQ_GLOBAL(Wnd0050C317_guess*, 0x00991A74) = new Wnd0050C317_guess(0);
    }
    if (g_systemInfoDialog_guess == 0) {
        g_systemInfoDialog_guess = new SystemInfoDialog_guess(0);
    }
    if (pinstCGroupSearchWnd_guess == 0) {
        pinstCGroupSearchWnd_guess = new CGroupSearchWnd_guess(0);
        pinstCGroupSearchFiltersWnd_guess = new CGroupSearchFiltersWnd_guess(0);
    }
    if (pinstCRaidWnd_guess == 0) {
        pinstCRaidWnd_guess = new CRaidWnd_guess(0);
    }
    if (pinstCAdvancedDisplayOptionsWnd_guess == 0) {
        pinstCAdvancedDisplayOptionsWnd_guess = new CAdvancedDisplayOptionsWnd_guess(0);
    }
    if (pinstCRaidOptionsWnd_guess == 0) {
        pinstCRaidOptionsWnd_guess = new CRaidOptionsWnd_guess(0);
    }
    if (pinstCBreathWnd_guess == 0) {
        pinstCBreathWnd_guess = new CBreathWnd_guess(0);
    }
    if (pinstCMapViewWnd_guess == 0) {
        pinstCMapToolbarWnd_guess = new CMapToolbarWnd_guess(0);
        pinstCMapViewWnd_guess = new CMapViewWnd_guess(0);
        pinstCEditLabelWnd_guess = new CEditLabelWnd_guess(0);
    }
    if (pinstCOptionsWnd_guess == 0) {
        pinstCOptionsWnd_guess = new COptionsWnd_guess(0);
    }
    if (EQ_GLOBAL(CBuffWindow_guess*, 0x00850C18) == 0) {
        EQ_GLOBAL(CBuffWindow_guess*, 0x00850C18) = new CBuffWindow_guess(0, 0);
    }
    if (EQ_GLOBAL(CBuffWindow_guess*, 0x00850C1C) == 0) {
        EQ_GLOBAL(CBuffWindow_guess*, 0x00850C1C) = new CBuffWindow_guess(0, 1);
    }
    if (EQ_GLOBAL(Wnd0055BA0F_guess*, 0x00850C08) == 0) {
        EQ_GLOBAL(Wnd0055BA0F_guess*, 0x00850C08) = new Wnd0055BA0F_guess(0);
    }
    if (pinstCColorPickerWnd_guess == 0) {
        pinstCColorPickerWnd_guess = new CColorPickerWnd_guess(0);
    }
    for (int i = 0; i < 4; i++) {
        if (g_hotButtonWnds_guess[i] == 0) {
            FUN_00576fa0_guess(name, g_hotButtonName_guess, 0x400);
            if (i > 0) {
                FUN_00576fd0_guess(name, _itoa(i + 1, g_numberText_guess, 10), 0x400);
            }
            g_hotButtonWnds_guess[i] = new Wnd00513CD7_guess(0, i, name);
        }
    }
    if (EQ_GLOBAL(Wnd005452F7_guess*, 0x00850C10) == 0) {
        EQ_GLOBAL(Wnd005452F7_guess*, 0x00850C10) = new Wnd005452F7_guess(0);
    }
    if (pinstCEQMainWnd_guess == 0) {
        pinstCEQMainWnd_guess = new CEQMainWnd_guess(0);
    }
    if (pinstCCastingWnd_guess == 0) {
        pinstCCastingWnd_guess = new CCastingWnd_guess(0);
    }
    if (EQ_GLOBAL(Wnd004EC8B4_guess*, 0x00850C2C) == 0) {
        EQ_GLOBAL(Wnd004EC8B4_guess*, 0x00850C2C) = new Wnd004EC8B4_guess(0);
    }
    if (EQ_GLOBAL(Wnd00558521_guess*, 0x00850C30) == 0) {
        EQ_GLOBAL(Wnd00558521_guess*, 0x00850C30) = new Wnd00558521_guess(0);
    }
    if (EQ_GLOBAL(Wnd00516E9A_guess*, 0x00850C34) == 0) {
        EQ_GLOBAL(Wnd00516E9A_guess*, 0x00850C34) = new Wnd00516E9A_guess(0);
    }
    if (g_wnd850C38_guess == 0) {
        // BigBankWnd (16 slots) when the account has the expansion at 0x009247A0 or anything already sits in
        // bank slots 8-15; otherwise the 8-slot BankWnd.
        bool hasExtraBank = false;
        if (g_pc0043EFDD_guess != 0) {
            for (int slot = 8; slot < 16; slot++) {
                if (g_pc0043EFDD_guess->bank_0cf0_guess[slot] != 0) {
                    hasExtraBank = true;
                    break;
                }
            }
        }
        if (g_expansion9247A0_guess != 0 || hasExtraBank) {
            g_wnd850C38_guess = new Wnd004DC838_guess(0, "BigBankWnd");
        } else {
            g_wnd850C38_guess = new Wnd004DC838_guess(0, "BankWnd");
        }
    }
    if (pinstCQuantityWnd_guess == 0) {
        pinstCQuantityWnd_guess = new CQuantityWnd_guess(0);
    }
    if (pinstCTextEntryWnd_guess == 0) {
        pinstCTextEntryWnd_guess = new CTextEntryWnd_guess(0);
    }
    if (pinstCFileSelectionWnd_guess == 0) {
        pinstCFileSelectionWnd_guess = new CFileSelectionWnd_guess(0);
    }
    if (pinstCLootWnd_guess == 0) {
        pinstCLootWnd_guess = new CLootWnd_guess(0);
    }
    if (EQ_GLOBAL(Wnd004D4277_guess*, 0x00850C44) == 0) {
        EQ_GLOBAL(Wnd004D4277_guess*, 0x00850C44) = new Wnd004D4277_guess(0);
    }
    if (EQ_GLOBAL(Wnd004F9AE1_guess*, 0x00850C48) == 0) {
        EQ_GLOBAL(Wnd004F9AE1_guess*, 0x00850C48) = new Wnd004F9AE1_guess(0);
    }
    if (pinstCMerchantWnd_guess == 0) {
        pinstCMerchantWnd_guess = new CMerchantWnd_guess(0);
    }
    if (pinstCTradeWnd_guess == 0) {
        pinstCTradeWnd_guess = new CTradeWnd_guess(0);
    }
    if (pinstCBazaarWnd_guess == 0) {
        pinstCBazaarWnd_guess = new CBazaarWnd_guess(0);
    }
    if (pinstCBazaarSearchWnd_guess == 0) {
        pinstCBazaarSearchWnd_guess = new CBazaarSearchWnd_guess(0);
    }
    if (pinstCGiveWnd_guess == 0) {
        pinstCGiveWnd_guess = new CGiveWnd_guess(0);
    }
    if (EQ_GLOBAL(CSelectorWnd_guess*, 0x00850C54) == 0) {
        EQ_GLOBAL(CSelectorWnd_guess*, 0x00850C54) = new CSelectorWnd_guess(0);
    }
    if (pinstCTrackingWnd_guess == 0) {
        pinstCTrackingWnd_guess = new CTrackingWnd_guess(0);
    }
    if (pinstCInspectWnd_guess == 0) {
        pinstCInspectWnd_guess = new CInspectWnd_guess(0);
    }
    if (pinstCFeedbackWnd_guess == 0) {
        pinstCFeedbackWnd_guess = new CFeedbackWnd_guess(0);
    }
    if (pinstCBugReportWnd_guess == 0) {
        pinstCBugReportWnd_guess = new CBugReportWnd_guess(0);
    }
    if (pinstCVideoModesWnd_guess == 0) {
        pinstCVideoModesWnd_guess = new CVideoModesWnd_guess(0);
    }
    if (EQ_GLOBAL(CCompassWnd_guess*, 0x00850C88) == 0) {
        EQ_GLOBAL(CCompassWnd_guess*, 0x00850C88) = new CCompassWnd_guess(0);
    }
    if (pinstCPlayerNotesWnd_guess == 0) {
        pinstCPlayerNotesWnd_guess = new CPlayerNotesWnd_guess(0);
    }
    if (pinstCGemsGameWnd_guess == 0) {
        pinstCGemsGameWnd_guess = new CGemsGameWnd_guess(0);
    }
    if (pinstCTitleWnd_guess == 0) {
        pinstCTitleWnd_guess = new CTitleWnd_guess(0);
    }
    if (pinstCPvpLeaderboardWnd_guess == 0) {
        pinstCPvpLeaderboardWnd_guess = new CPvpLeaderboardWnd_guess(0);
    }
    if (pinstCPvPStatsWnd_guess == 0) {
        pinstCPvPStatsWnd_guess = new CPvPStatsWnd_guess(0);
    }
    if (pinstCPointMerchantWnd_guess == 0) {
        pinstCPointMerchantWnd_guess = new CPointMerchantWnd_guess(0);
    }
    if (EQ_GLOBAL(Obj0042416A_guess*, 0x0079DBA0) == 0) {
        EQ_GLOBAL(Obj0042416A_guess*, 0x0079DBA0) = new Obj0042416A_guess;
    }
    if (EQ_GLOBAL(Obj004C3AB3_guess*, 0x00985C94) == 0) {
        EQ_GLOBAL(Obj004C3AB3_guess*, 0x00985C94) = new Obj004C3AB3_guess;
    }
    if (EQ_GLOBAL(Obj004B1473_guess*, 0x0098593C) == 0) {
        EQ_GLOBAL(Obj004B1473_guess*, 0x0098593C) = new Obj004B1473_guess;
    }
    if (EQ_GLOBAL(Obj004B1325_guess*, 0x00985904) == 0) {
        EQ_GLOBAL(Obj004B1325_guess*, 0x00985904) = new Obj004B1325_guess;
    }
    if (g_expansion9247A4_guess != 0 && EQ_GLOBAL(Obj00401745_guess*, 0x0079C104) == 0) {
        EQ_GLOBAL(Obj00401745_guess*, 0x0079C104) = new Obj00401745_guess;
    }
    if (g_wnd850CA0_guess == 0) {
        g_wnd850CA0_guess = new Wnd004C7DE4_guess(0);
        if (g_wnd850CA0_guess->ShouldAutoOpen_guess() && g_pc0043EFDD_guess != 0
            && g_pc0043EFDD_guess->GetInfo_guess()->level_11a4_guess > 1) {
            g_wnd850CA0_guess->Slot33_guess();
        }
    }
    if (pinstCFindLocationWnd_guess == 0) {
        pinstCFindLocationWnd_guess = new CFindLocationWnd_guess(0);
    }
    if (pinstCLargeDialogWnd_guess == 0) {
        pinstCLargeDialogWnd_guess = new CLargeDialogWnd_guess(0);
    }
    if (pinstCDynamicZoneWnd_guess == 0) {
        pinstCDynamicZoneWnd_guess = new CDynamicZoneWnd_guess(0);
    }
    if (pinstCTaskWnd_guess == 0) {
        pinstCTaskWnd_guess = new CTaskWnd_guess(0);
    }
    if (pinstCTaskSelectWnd_guess == 0) {
        pinstCTaskSelectWnd_guess = new CTaskSelectWnd_guess(0);
    }
    if (g_expansion9247A4_guess != 0) {
        if (pinstCAdventureRequestWnd_guess == 0) {
            pinstCAdventureRequestWnd_guess = new CAdventureRequestWnd_guess(0);
            EQ_GLOBAL(Obj009232F0_guess, 0x009232F0).FUN_004084ba_guess();
        }
        if (pinstCAdventureStatsWnd_guess == 0) {
            pinstCAdventureStatsWnd_guess = new CAdventureStatsWnd_guess(0);
        }
        if (pinstCAdventureLeaderboardWnd_guess == 0) {
            pinstCAdventureLeaderboardWnd_guess = new CAdventureLeaderboardWnd_guess(0);
        }
    }
    if (g_expansion9247A8_guess != 0) {
        if (pinstCLeadershipWnd_guess == 0) {
            pinstCLeadershipWnd_guess = new CLeadershipWnd_guess(0);
        }
        if (pinstCTargetOfTargetWnd_guess == 0) {
            pinstCTargetOfTargetWnd_guess = new CTargetOfTargetWnd_guess(0);
        }
    }
    if (g_expansion9247A0_guess != 0) {
        if (pinstCBodyTintWnd_guess == 0) {
            pinstCBodyTintWnd_guess = new CBodyTintWnd_guess(0);
        }
        if (pinstCGuildManagementWnd_guess == 0) {
            pinstCGuildManagementWnd_guess = new CGuildManagementWnd_guess(0);
        }
    }
    if (g_expansion9247A4_guess != 0 || g_expansion9247A0_guess != 0) {
        if (pinstCJournalNPCWnd_guess == 0) {
            pinstCJournalNPCWnd_guess = new CJournalNPCWnd_guess(0);
        }
        if (pinstCJournalCatWnd_guess == 0) {
            pinstCJournalCatWnd_guess = new CJournalCatWnd_guess(0);
        }
    }
    if (g_expansion9247A8_guess != 0 || g_expansion9247AC_guess != 0) {
        if (pinstCTributeBenefitWnd_guess == 0) {
            pinstCTributeBenefitWnd_guess = new CTributeBenefitWnd_guess(0);
        }
        if (pinstCTributeMasterWnd_guess == 0) {
            pinstCTributeMasterWnd_guess = new CTributeMasterWnd_guess(0);
        }
        if (pinstCGuildTributeMasterWnd_guess == 0) {
            pinstCGuildTributeMasterWnd_guess = new CGuildTributeMasterWnd_guess(0);
        }
        if (g_expansion9247AC_guess != 0 && pinstCVoiceMacroWnd_guess == 0) {
            pinstCVoiceMacroWnd_guess = new CVoiceMacroWnd_guess(0);
        }
    }
    if (g_expansion9247B0_guess != 0) {
        if (pinstCLFGuildWnd_guess == 0) {
            pinstCLFGuildWnd_guess = new CLFGuildWnd_guess(0);
        }
        if (pinstCGuildBankWnd_guess == 0) {
            pinstCGuildBankWnd_guess = new CGuildBankWnd_guess(0);
        }
    }
    if (pinstCBarterWnd_guess == 0) {
        pinstCBarterWnd_guess = new CBarterWnd_guess(0);
    }
    if (pinstCBarterMerchantWnd_guess == 0) {
        pinstCBarterMerchantWnd_guess = new CBarterMerchantWnd_guess(0);
    }
    if (pinstCBarterSearchWnd_guess == 0) {
        pinstCBarterSearchWnd_guess = new CBarterSearchWnd_guess(0);
    }
    if (pinstCTradeskillWnd_guess == 0) {
        pinstCTradeskillWnd_guess = new CTradeskillWnd_guess(0);
    }
    if (EQ_GLOBAL(Obj00407706_guess*, 0x0079C148) == 0) {
        EQ_GLOBAL(Obj00407706_guess*, 0x0079C148) = new Obj00407706_guess;
    }
    if (pinstCTicketWnd_guess == 0) {
        pinstCTicketWnd_guess = new CTicketWnd_guess(0);
        if (EQ_GLOBAL(Obj00985CF0_guess*, 0x00985CF0) != 0) {
            EQ_GLOBAL(Obj00985CF0_guess*, 0x00985CF0)->RefreshTicketWindow_guess();
        }
    }
    if (pinstCTicketCommentWnd_guess == 0) {
        pinstCTicketCommentWnd_guess = new CTicketCommentWnd_guess(0);
    }
    if (EQ_GLOBAL(Wnd0055D8CA_guess*, 0x0099283C) == 0) {
        EQ_GLOBAL(Wnd0055D8CA_guess*, 0x0099283C) = new Wnd0055D8CA_guess(0);
    }
    if (pinstCProgressionSelectionWnd_guess == 0) {
        pinstCProgressionSelectionWnd_guess = new CProgressionSelectionWnd_guess(0);
    }
    if (pinstCItemExpTransferWnd_guess == 0) {
        pinstCItemExpTransferWnd_guess = new CItemExpTransferWnd_guess(0);
    }
    if (pinstCAltStorageWnd_guess == 0) {
        pinstCAltStorageWnd_guess = new CAltStorageWnd_guess(0);
    }
    // GM-only windows, when the guide setting is on; then a countdown window if a timer is running
    // (0x00985840).
    if (pinstLocalPlayer->GM != 0 && g_eqConfig_guess->guide_3a1ba_guess != 0) {
        if (pinstCPetitionQWnd_guess == 0) {
            pinstCPetitionQWnd_guess = new CPetitionQWnd_guess(0);
        }
        if (pinstCSoulmarkWnd_guess == 0) {
            pinstCSoulmarkWnd_guess = new CSoulmarkWnd_guess(0);
        }
        if (pinstCAvaZoneWnd_guess == 0) {
            pinstCAvaZoneWnd_guess = new CAvaZoneWnd_guess(0);
        }
    }
    if (g_wnd850C94_guess == 0 && g_timerEnd985840_guess > 0) {
        g_wnd850C94_guess = new Wnd00563FBB_guess(
            (unsigned int)(g_timerEnd985840_guess - FUN_0046d655_guess()) / 1000);
        g_wnd850C94_guess->Slot33_guess();
    }
    // Animated UI icons by name (A_InvEar, A_DragItem, spell icons and book pages), then shadows and the
    // viewport.
    FUN_00574110_guess("Loading Icons.");
    g_charSelectManager_guess->FUN_005af630_guess();
    IconAnim0043EFDD_guess* icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_InvEar");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_DragItem");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_SpellIcons");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_SpellBook01");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_SpellBook02");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_SpellBook03");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    icon = g_iconOwner0043EFDD_guess->FUN_005b44a0_guess("A_SpellBook04");
    if (icon != 0) {
        icon->FUN_005b1bb0_guess();
    }
    SetState2d60_guess(g_globalSettings_guess->GetBool_guess("Defaults", "Shadows", 0));
    FUN_00574110_guess("Resetting viewport.");
    LoadViewportRect_guess();
    ApplyVideoMode_guess();
    FUN_00574110_guess("Game UI Initialized.");
}

struct Compare850CA0_guess {
    // EXTERNAL: TITANIUM 0x004C776D Compare850CA0_guess::HasUnreadStory_guess
    bool HasUnreadStory_guess();
};

#define g_compare850CA0_guess EQ_GLOBAL(Compare850CA0_guess*, 0x00850CA0)
#define g_flag799438_guess EQ_GLOBAL(unsigned char, 0x00799438)
#define g_value850988_guess EQ_GLOBAL(int, 0x00850988)
#define g_text850510_guess EQ_ARRAY(char, 0x00850510)
#define g_fontNames_guess EQ_ARRAY(const char*, 0x00799830)
// EXTERNAL: TITANIUM 0x00469DD7 NoOp_guess
void __cdecl NoOp_guess();

struct TimeSource_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Slot04_guess();
    virtual void Slot05_guess();
    virtual float Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual int Slot10_guess();
    virtual int Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess(float value);
    virtual bool Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess(int value);
};

struct ScreenMapper_guess {
    virtual float Slot00_guess(float value);
    virtual float Slot01_guess(float value);
    virtual float Slot02_guess(float value);
    virtual float Slot03_guess(float value);
};

struct ViewPoint_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess(Vector3_guess* position);
    virtual void Slot03_guess(int value);
};

#define g_mode_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_timeSource_guess EQ_GLOBAL(TimeSource_guess*, 0x008503A8)
#define g_screenMapper_guess EQ_GLOBAL(ScreenMapper_guess*, 0x0099E374)
#define g_timeSlots_guess EQ_ARRAY(float, 0x0078F618)

struct Window004C32FF_guess {
    int value_0000_guess;
    unsigned char pad_0004_guess[5];
    unsigned char state_0009_guess;
    // EXTERNAL: TITANIUM 0x004C38A9 Window004C32FF_guess::Clear_guess
    void Clear_guess(int value);
};

// EXTERNAL: TITANIUM 0x004C32FF GetWindow004C32FF_guess
Window004C32FF_guess* __cdecl GetWindow004C32FF_guess();

struct DisplayState004909CE_guess {
    // EXTERNAL: TITANIUM 0x004909CE DisplayState004909CE_guess::Clear_guess
    void Clear_guess();
};

// The fade list (tu_000 FadeList_guess); 0x00401022 creates it on first use.
struct FadeList_guess {
    // EXTERNAL: TITANIUM 0x00401307 FadeList_guess::ClearFades_guess
    void ClearFades_guess();
    // EXTERNAL: TITANIUM 0x004012BB FadeList_guess::UpdateFades_guess
    void UpdateFades_guess();
};

// EXTERNAL: TITANIUM 0x00401022 GetFadeList_guess
FadeList_guess* __cdecl GetFadeList_guess();

struct OffsetList004B6A36_guess {
    // EXTERNAL: TITANIUM 0x004B6AC6 OffsetList004B6A36_guess::ReleaseAll_guess
    void ReleaseAll_guess();
};

// EXTERNAL: TITANIUM 0x004B6A36 InitializeOffsetList004B6A36_guess
OffsetList004B6A36_guess* __cdecl InitializeOffsetList004B6A36_guess();

struct MessageOwner00406AEF_guess {
    // EXTERNAL: TITANIUM 0x00405971 MessageOwner00406AEF_guess::SaveTriggers_guess
    void SaveTriggers_guess();
};

// EXTERNAL: TITANIUM 0x00406AEF InitializeMessageOwner00406AEF_guess
MessageOwner00406AEF_guess* __cdecl InitializeMessageOwner00406AEF_guess();

struct ResourceContainer00985CE4_guess {
    // EXTERNAL: TITANIUM 0x004C8860 ResourceContainer00985CE4_guess::~ResourceContainer00985CE4_guess
    ~ResourceContainer00985CE4_guess();
};

struct TargetTable00985C88_guess {
    // EXTERNAL: TITANIUM 0x004C1899 TargetTable00985C88_guess::~TargetTable00985C88_guess
    ~TargetTable00985C88_guess();
};

#define g_displayState004909CE_guess EQ_GLOBAL(DisplayState004909CE_guess*, 0x00903E84)
#define g_resource00985CE4_guess EQ_GLOBAL(ResourceContainer00985CE4_guess*, 0x00985CE4)
#define g_targetTable00985C88_guess EQ_GLOBAL(TargetTable00985C88_guess*, 0x00985C88)
#define g_localPlayer00905CE4_guess EQ_GLOBAL(void*, 0x00905CE4)
#define g_value850CC4_guess EQ_GLOBAL(int, 0x00850CC4)
#define g_flag850B90_guess EQ_GLOBAL(int, 0x00850B90)
#define g_flag924828_guess EQ_GLOBAL(int, 0x00924828)
#define g_defaultStart00923B64_guess EQ_GLOBAL(float, 0x00923B64)
#define g_defaultEnd00923B74_guess EQ_GLOBAL(float, 0x00923B74)
#define g_defaultStart200923BE0_guess EQ_GLOBAL(float, 0x00923BE0)
#define g_defaultEnd200923BE4_guess EQ_GLOBAL(float, 0x00923BE4)
#define g_defaultRed00923B57_guess EQ_GLOBAL(unsigned char, 0x00923B57)
#define g_defaultGreen00923B5B_guess EQ_GLOBAL(unsigned char, 0x00923B5B)
#define g_defaultBlue00923B5F_guess EQ_GLOBAL(unsigned char, 0x00923B5F)
#define g_default00400923B84_guess EQ_GLOBAL(float, 0x00923B84)
#define g_defaultMode00923B88_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_defaultFlag00923B56_guess EQ_GLOBAL(unsigned char, 0x00923B56)
#define g_defaultFlag00923BBA_guess EQ_GLOBAL(unsigned char, 0x00923BBA)
#define g_defaultValue00923C80_guess EQ_GLOBAL(int, 0x00923C80)
#define g_defaultValue00923C7C_guess EQ_GLOBAL(float, 0x00923C7C)

// FUNCTION: TITANIUM 0x0044350D
// Tears the zone down: every object list, the sun, the sounds; the reverse of LoadZone.
void CDisplay_guess::StopWorldDisplay_guess() {
    if (state_2d54_guess != 0) {
        if (g_charSelectManager_guess != 0) {
            ((Counter_guess*)g_charSelectManager_guess)->Update_guess(0);
        }
        value_2cf8_guess = 0;
        GetWindow004C32FF_guess()->Clear_guess(
            GetWindow004C32FF_guess()->value_0000_guess);
        g_queue_guess->EmitterSetWind_guess(0);
        g_queue_guess->FUN_0044b014_guess(0);
        DeleteAllEffects_guess();
        DeleteAllHSprites_guess();
        DeleteAllPlayers_guess();
        DeleteAllGroundItems_guess();
        DeleteAllMoney_guess();
        DeleteAllMissiles_guess();
        if (g_flag850B90_guess != 0) {
            g_languageSlot0043C29D_guess->Slot26_guess();
            g_flag850B90_guess = 0;
        }
        g_flag924828_guess = 0;
        DeleteAllObjects_guess();
        g_displayState004909CE_guess->Clear_guess();
        g_service_guess->Slot35_guess();
        g_service_guess->Slot24_guess(value_2d20_guess);
        GetFadeList_guess()->ClearFades_guess();
        InitializeOffsetList004B6A36_guess()->ReleaseAll_guess();
        g_languageSlot0043C29D_guess->Slot01_guess(0);
        g_localPlayer00905CE4_guess = 0;
        g_value905d04_guess = 0;
        g_value905d08_guess = 0;
        g_value905d0c_guess = 0;
        g_value850CC4_guess = 0;
        g_value850cc8_guess = 0;
        g_value905cf8_guess = 0;
        g_value905d20_guess = 0;
        g_value905cfc_guess = 0;
        g_value905d10_guess = 0;
        g_value905d14_guess = 0;
        g_value905d18_guess = 0;
        g_value905d1c_guess = 0;
        torchLight_2870_guess = 0;
        magTorchLight_2874_guess = 0;
        smLanternLight_2878_guess = 0;
        lgLanternLight_287c_guess = 0;
        smMagicLight_2880_guess = 0;
        lgMagicLight_2884_guess = 0;
        candleLight_2888_guess = 0;
        redLight_288c_guess = 0;
        blueLight_2890_guess = 0;
        sunLight_2d1c_guess = 0;
        value_2d20_guess = 0;
        playerLight_2d18_guess = 0;
        value_286c_guess = 0;
        memset(buffer_015c_guess, 0, 10000);
        value_0158_guess = 0;
        lastUpdateTime_0150_guess = 0;
        value_28f0_guess = 0;
        if (g_resource00985CE4_guess != 0) {
            delete g_resource00985CE4_guess;
            g_resource00985CE4_guess = 0;
        }
        if (g_targetTable00985C88_guess != 0) {
            delete g_targetTable00985C88_guess;
            g_targetTable00985C88_guess = 0;
        }
        InitializeMessageOwner00406AEF_guess()->SaveTriggers_guess();
        state_2d54_guess = 0;
        g_defaultStart00923B64_guess = 100.0f;
        g_defaultEnd00923B74_guess = 2000.0f;
        g_defaultStart200923BE0_guess = 100.0f;
        g_defaultRed00923B57_guess = 0xc0;
        g_defaultGreen00923B5B_guess = 0xc0;
        g_defaultEnd200923BE4_guess = 2000.0f;
        g_defaultBlue00923B5F_guess = 0xc0;
        g_default00400923B84_guess = 0.4f;
        g_defaultMode00923B88_guess = 1;
        g_defaultFlag00923B56_guess = 1;
        g_defaultValue00923C80_guess = 0;
        g_defaultFlag00923BBA_guess = 1;
        strcpy(g_nameBuffer_guess.text_0000_guess, "Default");
        SetLabel_guess("Default");
        strcpy(g_nameBuffer2_guess.text_0000_guess, "Default");
        SetSecondarySkyName_guess("Default", -1.0f);
        g_defaultValue00923C7C_guess = 10.0f;
        g_client_guess->SetFogState_guess(1, 100.0f, 2000.0f, 0xc0, 0xc0, 0xc0);
    }
}

// FUNCTION: TITANIUM 0x004437E5
// Sun position from the time of day; 0.00069444446 is 1/1440, minutes to a fraction of the day.
void CDisplay_guess::SetSunLight_guess() {
    Vector3_guess pos;
    Vector3_guess vec;
    int minute;
    int hour;
    if (value_2cf8_guess != 0) {
        if (g_mode_guess == 2 || g_mode_guess == 1 || g_mode_guess == 5) {
            GetZoneTimeOfDay_guess(&hour, &minute);
            if (g_timeSource_guess != 0) {
                g_timeSource_guess->Slot14_guess(((float)hour * 60.0f + (float)minute) * 0.00069444446f);
                bool day = g_timeSource_guess->Slot15_guess();
                pos.x_0000_guess = 0.0f;
                if (day) {
                    pos.y_0004_guess = g_screenMapper_guess->Slot00_guess(512.0f - g_timeSource_guess->Slot06_guess());
                    pos.z_0008_guess = -g_screenMapper_guess->Slot01_guess(512.0f - g_timeSource_guess->Slot06_guess());
                    ((ViewPoint_guess*)value_2d20_guess)->Slot02_guess(&pos);
                    ((ViewPoint_guess*)value_2d20_guess)->Slot03_guess(g_timeSource_guess->Slot11_guess());
                } else {
                    pos.y_0004_guess = g_screenMapper_guess->Slot00_guess(512.0f - g_timeSource_guess->Slot04_guess());
                    pos.z_0008_guess = -g_screenMapper_guess->Slot01_guess(512.0f - g_timeSource_guess->Slot04_guess());
                    ((ViewPoint_guess*)value_2d20_guess)->Slot02_guess(&pos);
                    ((ViewPoint_guess*)value_2d20_guess)->Slot03_guess(g_timeSource_guess->Slot10_guess());
                }
            } else {
                vec.x_0000_guess = g_timeSlots_guess[state_0145_guess];
                vec.y_0004_guess = g_timeSlots_guess[state_0145_guess];
                vec.z_0008_guess = g_timeSlots_guess[state_0145_guess];
                ((PositionHandler_guess*)sunLight_2d1c_guess)->Update_guess(&vec);
            }
        } else {
            vec.x_0000_guess = 0.0f;
            vec.y_0004_guess = 0.0f;
            vec.z_0008_guess = 0.0f;
            ((PositionHandler_guess*)sunLight_2d1c_guess)->Update_guess(&vec);
            if (g_timeSource_guess != 0) {
                g_timeSource_guess->Slot18_guess(0);
            }
        }
        SetAmbientLight_guess(g_timeSlots_guess[state_0145_guess]);
    }
}

struct ClockInterface_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Slot04_guess();
    virtual void Slot05_guess(float value_guess);
    virtual void Slot06_guess();
    virtual void Slot07_guess(float value_guess);
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess(float value_guess);
};

#define g_clockInterface_guess EQ_GLOBAL(ClockInterface_guess*, 0x008503A8)
#define g_clockBase_guess EQ_GLOBAL(float, 0x00850CD8)
#define g_clockScale_guess EQ_GLOBAL(float, 0x00850CDC)
#define g_clockTarget_guess EQ_GLOBAL(int, 0x00850CE0)
#define g_clockDuration_guess EQ_GLOBAL(int, 0x00850CE4)
#define g_clockInterval_guess EQ_GLOBAL(int, 0x00698A00)
#define g_clockTime_guess EQ_GLOBAL(int, 0x00850984)
#define g_clockMinute_guess EQ_GLOBAL(int, 0x00850CEC)
#define g_clockNext_guess EQ_GLOBAL(int, 0x00850CF0)
#define g_clockPartTime_guess EQ_GLOBAL(int, 0x00850D7C)
#define g_clockPartMinute_guess EQ_GLOBAL(int, 0x00850D80)
#define g_clockPartHour_guess EQ_GLOBAL(int, 0x00850D84)
#define g_clockHourMultiplier_guess EQ_ARRAY(float, 0x00640DAC)
#define g_clockMinuteMultiplier_guess EQ_ARRAY(float, 0x00642F64)

// FUNCTION: TITANIUM 0x004439C0
// @early-stop: budget, structural ndiff=37
// Sky and light for the clock time, in 12-minute steps (120 a day): some spans hold one sky slot, the
// others blend between slots.
void CDisplay_guess::SetSkyBackground_guess() {
    int hour_guess;
    int minute_guess;
    int now_guess = CreateWorker_guess();
    frameTime_0148_guess = now_guess;
    GetZoneTimeOfDay_guess(&hour_guess, &minute_guess);

    int segment_guess = (hour_guess * 0x3c + minute_guess) / 0xc;
    int phase_guess = ((hour_guess + 0x15) * 0x3c + minute_guess) % 0x5a0;
    if (segment_guess < 0xf) {
        segment_guess = 0x2c;
        minute_guess = 0;
        phase_guess = (0x168 - (phase_guess % 0x168)) * 3;
    } else if (segment_guess < 0x2d) {
        segment_guess = (segment_guess + 0x1d) % 0x3c;
        hour_guess = 0xe;
        minute_guess = 0x24;
        phase_guess = 0;
    } else if (segment_guess < 0x4b) {
        segment_guess = 0xe;
        minute_guess = 0;
        phase_guess = (0x168 - (phase_guess % 0x168)) * 3;
    } else if (segment_guess < 0x69) {
        segment_guess = (int)((unsigned int)segment_guess + (unsigned int)-0x3d);
        hour_guess = 0x2c;
        minute_guess = 0x24;
        phase_guess = 0;
    } else {
        segment_guess = 0x2c;
        minute_guess = 0;
        phase_guess = (0x168 - (phase_guess % 0x168)) * 3;
    }
    if (minute_guess == 0) {
        hour_guess = segment_guess;
    }

    state_0145_guess = (unsigned char)segment_guess;
    if (state_0145_guess > 0x3b) {
        state_0145_guess = 0;
    }
    if (segment_guess == 0xe && hour_guess == 0xe) {
        g_clockBase_guess = 448.0f;
        g_clockScale_guess = 128.0f;
        g_clockTarget_guess = (phase_guess - 0x438) * 1000 + frameTime_0148_guess;
        g_clockDuration_guess = 0x107ac0;
        g_clockInterval_guess = 1;
    } else if (segment_guess == 0x2c && hour_guess == 0x2c) {
        g_clockBase_guess = 192.0f;
        g_clockScale_guess = 128.0f;
        g_clockTarget_guess = (phase_guess - 0x438) * 1000 + frameTime_0148_guess;
        g_clockDuration_guess = 0x107ac0;
        g_clockInterval_guess = 1;
    } else if (hour_guess == 0xe) {
        int interval_guess = 0xe - segment_guess;
        if (interval_guess < 0) {
            interval_guess += 0x3c;
        }
        g_clockBase_guess = 320.0f;
        g_clockScale_guess = 128.0f;
        g_clockTarget_guess = (interval_guess * minute_guess - 0x438 + phase_guess) * 1000 + frameTime_0148_guess;
        g_clockInterval_guess = interval_guess;
        g_clockDuration_guess = 0x107ac0;
    } else if (hour_guess == 0x2c) {
        int interval_guess = 0x2c - segment_guess;
        g_clockBase_guess = 64.0f;
        g_clockScale_guess = 128.0f;
        g_clockTarget_guess = (interval_guess * minute_guess - 0x438 + phase_guess) * 1000 + frameTime_0148_guess;
        g_clockInterval_guess = interval_guess;
        g_clockDuration_guess = 0x107ac0;
    }

    if (g_clockInterface_guess != 0) {
        hour_guess = frameTime_0148_guess - g_clockTarget_guess;
        float elapsed_float_guess = (float)hour_guess;
        if (hour_guess < 0) {
            elapsed_float_guess += 4294967296.0f;
        }
        g_clockInterface_guess->Slot05_guess(((AngleMath_guess*)this)->FixHeading_guess(
            elapsed_float_guess * g_clockScale_guess / (float)g_clockDuration_guess + g_clockBase_guess));
        float angle_guess = g_clockInterface_guess->Slot04_guess();
        g_clockInterface_guess->Slot07_guess(((AngleMath_guess*)this)->FixHeading_guess(angle_guess + 256.0f));
    }
    g_clockTime_guess = frameTime_0148_guess;
    g_clockMinute_guess = minute_guess * 1000;
    if (phase_guess == 0) {
        g_clockNext_guess = frameTime_0148_guess + g_clockMinute_guess;
    } else {
        g_clockNext_guess = phase_guess * 1000 + frameTime_0148_guess;
    }
    SetSunLight_guess();
}

// Byte color as the renderer takes it.
struct FogColor_guess {
    unsigned char blue_guess;
    unsigned char green_guess;
    unsigned char red_guess;
    unsigned char alpha_guess;
};

struct FogRender_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void SetAmbient_guess(FogColor_guess* color);
    virtual void SetFogColor_guess(FogColor_guess* color);
};

struct SkyColorSource_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual FogColor_guess* GetColor_guess();
};

struct LightSource_guess {
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual float GetLevel_guess();
};

struct LightRef_guess {
    LightSource_guess* light_0000_guess;
};

struct LightPlayer_guess {
    unsigned char pad_0000_guess[0x1a8];
    LightRef_guess* ref_01a8_guess;
};

struct FogOwner_guess {
    unsigned char pad_0000_guess[0x39404];
    int red_39404_guess;
    int green_39408_guess;
    int blue_3940c_guess;
    // EXTERNAL: TITANIUM 0x004940E1 FogOwner_guess::UpdateFog_guess
    void UpdateFog_guess(int value);
};

// Sight slot in the profile: 0xFF when empty.
struct SightSlot_guess {
    unsigned char pad_0000_guess[0x18];
    int value_0018_guess;
};

struct SightTable_guess {
    SightSlot_guess slots_0000_guess[2];
    int Value_guess(int index) {
        return slots_0000_guess[index].value_0018_guess;
    }
};

struct CHARINFO2 {
    unsigned char pad_0000_guess[0x1100];
    SightTable_guess sight_1100_guess;
};

struct PcCharacter1_guess {
    // EXTERNAL: TITANIUM 0x004106A3 PcCharacter1_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int effect, int value0, int value1, int value2);
};

struct PcPrefix_guess {
    int pad_0000_guess;
    int pad_0004_guess;
};

struct PcBase_guess : EQ_Character {
    CHARINFO2* Info_guess() {
        return GetCharInfo2();
    }
};

struct PcView_guess : PcPrefix_guess, virtual PcBase_guess {
    unsigned char pad_000c_guess[0xc280 - 0xc];
    PcCharacter1_guess character1_c280_guess;
};

#define g_fogRender_guess EQ_GLOBAL(FogRender_guess*, 0x0099E368)
#define g_skyColorSource_guess EQ_GLOBAL(SkyColorSource_guess*, 0x008503A8)
#define g_lightPlayer_guess EQ_GLOBAL(LightPlayer_guess*, 0x00905CF8)
#define g_fogOwner_guess EQ_GLOBAL(FogOwner_guess*, 0x00988DF0)
#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)
#define g_zoneType_guess EQ_GLOBAL(unsigned char, 0x0085097C)
#define g_skyMode_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_skyRed_guess EQ_ARRAY(float, 0x0078F708)
#define g_skyGreen_guess EQ_ARRAY(float, 0x0078F768)
#define g_skyBlue_guess EQ_ARRAY(float, 0x0078F7C8)
#define g_lightFade_guess EQ_GLOBAL(float, 0x00698A08)
#define g_infraRed_guess EQ_GLOBAL(int, 0x009238FC)
#define g_infraGreen_guess EQ_GLOBAL(int, 0x00923900)
#define g_infraBlue_guess EQ_GLOBAL(int, 0x00923904)
#define g_ultraRed_guess EQ_GLOBAL(int, 0x00923908)
#define g_ultraGreen_guess EQ_GLOBAL(int, 0x0092390C)
#define g_ultraBlue_guess EQ_GLOBAL(int, 0x00923910)
#define g_fogRed_guess EQ_GLOBAL(unsigned char, 0x00923B57)
#define g_fogGreen_guess EQ_GLOBAL(unsigned char, 0x00923B5B)
#define g_fogBlue_guess EQ_GLOBAL(unsigned char, 0x00923B5F)

// Mixes the ambient light and fog colour for the frame from the sky, the player's light source and his
// infravision or ultravision; 0x004940E1 then applies the fog.
// FUNCTION: TITANIUM 0x00441295
// @early-stop: budget, structural ndiff=465
// When flag +9 of window 0x004C32FF is set outside zone types 7-8, ambient goes white and the fog takes the
// player's light level (at least the zone's colour).
void CDisplay_guess::SetAmbientLight_guess(float value) {
    int hour;
    int minute;
    if (value_2cf8_guess == 0) {
        return;
    }
    GetZoneTimeOfDay_guess(&hour, &minute);
    bool infra = false;
    bool ultra = false;
    // A lightning flash (weather +9, set together with the thunder sound) lights everything white, except in
    // environment modes 7 and 8 (0x85097C).
    if (GetWindow004C32FF_guess()->state_0009_guess != 0 && g_zoneType_guess != 7 && g_zoneType_guess != 8) {
        FogColor_guess white;
        white.alpha_guess = 0xff;
        white.blue_guess = 0xff;
        white.green_guess = 0xff;
        white.red_guess = 0xff;
        g_fogRender_guess->SetAmbient_guess(&white);
        int level = 255;
        if (g_lightPlayer_guess->ref_01a8_guess->light_0000_guess != 0) {
            level = (int)(g_lightPlayer_guess->ref_01a8_guess->light_0000_guess->GetLevel_guess() * 255.0f);
        }
        FogOwner_guess* owner = g_fogOwner_guess;
        unsigned char red = level > owner->red_39404_guess ? level : owner->red_39404_guess;
        unsigned char green = level > owner->green_39408_guess ? level : owner->green_39408_guess;
        unsigned char blue = level > owner->blue_3940c_guess ? level : owner->blue_3940c_guess;
        g_client_guess->SetFogState_guess(1, fogStart_012c_guess, fogEnd_0130_guess, red, green, blue);
        return;
    }
    // Infravision and ultravision: innate (+0x1100, 0xFF none) or from a buff (SPA 65, 66); ultravision wins.
    if (g_pcView_guess->Info_guess()->sight_1100_guess.Value_guess(0) != 0xff
        || g_pcView_guess->character1_c280_guess.TotalSpellAffects_guess(0x41, 1, 0, 1) != 0) {
        infra = true;
    }
    if (g_pcView_guess->Info_guess()->sight_1100_guess.Value_guess(1) != 0xff
        || g_pcView_guess->character1_c280_guess.TotalSpellAffects_guess(0x42, 1, 0, 1) != 0) {
        ultra = true;
        infra = false;
    }
    float red;
    float green;
    float blue;
    // Base light: in the outdoor zone types (1, 2, 5 at 0x923B88) the hourly colour tables blended by the
    // minute, or a fixed colour source (0x8503A8); 0.5 in type 4, else 0.1.
    if (g_skyMode_guess == 1 || g_skyMode_guess == 2 || g_skyMode_guess == 5) {
        if (g_skyColorSource_guess == 0) {
            unsigned char now = (unsigned char)hour;
            unsigned char next = now + 1;
            if (next > 24) {
                next = 1;
            }
            unsigned char from = now - 1;
            unsigned char to = next - 1;
            red = (g_skyRed_guess[to] - g_skyRed_guess[from]) * (float)minute * 0.016666668f + g_skyRed_guess[from];
            green = (g_skyGreen_guess[to] - g_skyGreen_guess[from]) * (float)minute * 0.016666668f + g_skyGreen_guess[from];
            blue = (g_skyBlue_guess[to] - g_skyBlue_guess[from]) * (float)minute * 0.016666668f + g_skyBlue_guess[from];
        } else {
            FogColor_guess color = *g_skyColorSource_guess->GetColor_guess();
            red = color.red_guess * 0.003921569f;
            green = color.green_guess * 0.003921569f;
            blue = color.blue_guess * 0.003921569f;
        }
        if (green > 1.0f) {
            green = 1.0f;
        }
        if (red > 1.0f) {
            red = 1.0f;
        }
        if (blue > 1.0f) {
            blue = 1.0f;
        }
    } else if (g_skyMode_guess == 4) {
        red = blue = green = 0.5f;
    } else {
        red = blue = green = 0.1f;
    }
    float level = 1.0f;
    if (g_lightPlayer_guess->ref_01a8_guess->light_0000_guess != 0) {
        level = g_lightPlayer_guess->ref_01a8_guess->light_0000_guess->GetLevel_guess();
    }
    // The fade keeps its unrounded value for the darkening below.
    double fade = g_lightFade_guess;
    if (fade == -1.0) {
        g_lightFade_guess = level;
        fade = level;
    }
    // The shown light level moves 0.01 per call toward the light source's level (1.0 without one).
    if (level > fade) {
        fade += 0.01f;
        g_lightFade_guess = (float)fade;
        if (fade > level) {
            g_lightFade_guess = level;
            fade = level;
        }
    } else if (level < fade) {
        fade -= 0.01f;
        g_lightFade_guess = (float)fade;
        if (fade < level) {
            g_lightFade_guess = level;
            fade = level;
        }
    }
    float tintRed;
    float tintGreen;
    float tintBlue;
    // The vision floor (infravision or ultravision colour, else 0.08): the base light never drops below it,
    // and as a fog tint it fades as the light rises.
    if (infra) {
        tintRed = g_infraRed_guess * 0.003921569f;
        tintGreen = g_infraGreen_guess * 0.003921569f;
        tintBlue = g_infraBlue_guess * 0.003921569f;
    } else if (ultra) {
        tintRed = g_ultraRed_guess * 0.003921569f;
        tintGreen = g_ultraGreen_guess * 0.003921569f;
        tintBlue = g_ultraBlue_guess * 0.003921569f;
    } else {
        tintBlue = tintGreen = tintRed = 0.08f;
    }
    if (red < tintRed) {
        red = tintRed;
    }
    if (green < tintGreen) {
        green = tintGreen;
    }
    if (blue < tintBlue) {
        blue = tintBlue;
    }
    double dark = 1.0 - fade;
    tintRed = (float)(tintRed * dark);
    tintGreen = (float)(tintGreen * dark);
    tintBlue = (float)(dark * tintBlue);
    FogColor_guess fog;
    fog.alpha_guess = 0xff;
    fog.red_guess = (unsigned char)(tintRed * 255.0f);
    fog.green_guess = (unsigned char)(tintGreen * 255.0f);
    fog.blue_guess = (unsigned char)(tintBlue * 255.0f);
    g_fogRender_guess->SetFogColor_guess(&fog);
    FogColor_guess ambient;
    ambient.alpha_guess = 0xff;
    ambient.blue_guess = (unsigned char)(blue * 255.0f);
    ambient.green_guess = (unsigned char)(green * 255.0f);
    ambient.red_guess = (unsigned char)(red * 255.0f);
    g_fogRender_guess->SetAmbient_guess(&ambient);
    value = (blue + green + red) * 0.33333334f;
    float tintBright = (tintBlue + tintGreen + tintRed) * 0.33333334f;
    int outRed;
    int outGreen;
    int outBlue;
    int fogRed;
    int fogGreen;
    int fogBlue;
    // Environment modes 5-10 scale by fixed fog colours, other zones by their own fog colour;
    // the tint's floor still shows through.
    if (g_zoneType_guess == 5) {
        outRed = (int)(red * 240.0f);
        outGreen = (int)(green * 570.0f);
        outBlue = (int)(blue * 370.0f);
        fogRed = (int)(tintRed * 240.0f);
        fogGreen = (int)(tintGreen * 570.0f);
        fogBlue = (int)(tintBlue * 370.0f);
    } else if (g_zoneType_guess == 6) {
        outRed = (int)(red * 57.0f);
        outGreen = (int)(green * 57.0f);
        outBlue = (int)(blue * 0.0f);
        fogRed = (int)(tintRed * 57.0f);
        fogGreen = (int)(tintGreen * 57.0f);
        fogBlue = (int)(tintBlue * 0.0f);
    } else if (g_zoneType_guess == 7) {
        outRed = (int)(red * 2550.0f);
        outGreen = (int)(green * 0.0f);
        outBlue = (int)(blue * 0.0f);
        fogRed = (int)(tintRed * 2550.0f);
        fogGreen = (int)(tintGreen * 0.0f);
        fogBlue = (int)(tintBlue * 0.0f);
    } else if (g_zoneType_guess == 8) {
        outRed = (int)(red * 0.0f);
        outGreen = (int)(green * 0.0f);
        outBlue = (int)(blue * 125.0f);
        fogRed = (int)(tintRed * 0.0f);
        fogGreen = (int)(tintGreen * 0.0f);
        fogBlue = (int)(tintBlue * 125.0f);
    } else if (g_zoneType_guess == 9) {
        outRed = (int)(red * 49.0f);
        outGreen = (int)(green * 52.0f);
        outBlue = (int)(blue * 62.0f);
        fogRed = (int)(tintRed * 49.0f);
        fogGreen = (int)(tintGreen * 52.0f);
        fogBlue = (int)(tintBlue * 62.0f);
    } else if (g_zoneType_guess == 10) {
        outRed = (int)(red * 179.0f);
        outGreen = (int)(green * 193.0f);
        outBlue = (int)(blue * 227.0f);
        fogRed = (int)(tintRed * 179.0f);
        fogGreen = (int)(tintGreen * 193.0f);
        fogBlue = (int)(tintBlue * 227.0f);
    } else {
        float defRed = (float)g_fogRed_guess;
        float defGreen = (float)g_fogGreen_guess;
        float defBlue = (float)g_fogBlue_guess;
        outRed = (int)(red * defRed);
        outGreen = (int)(green * defGreen);
        outBlue = (int)(blue * defBlue);
        fogRed = (int)(tintRed * defRed);
        fogGreen = (int)(tintGreen * defGreen);
        fogBlue = (int)(tintBlue * defBlue);
    }
    int finalRed = (int)(outRed * g_lightFade_guess * value);
    int finalGreen = (int)(outGreen * g_lightFade_guess * value);
    int finalBlue = (int)(outBlue * g_lightFade_guess * value);
    int minRed = (int)(fogRed * tintBright);
    int minGreen = (int)(fogGreen * tintBright);
    int minBlue = (int)(fogBlue * tintBright);
    if (minRed > finalRed) {
        finalRed = minRed;
    }
    if (minGreen > finalGreen) {
        finalGreen = minGreen;
    }
    if (minBlue > finalBlue) {
        finalBlue = minBlue;
    }
    g_fogOwner_guess->red_39404_guess = finalRed;
    g_fogOwner_guess->green_39408_guess = finalGreen;
    g_fogOwner_guess->blue_3940c_guess = finalBlue;
    g_fogOwner_guess->UpdateFog_guess(0);
    value_000c_guess = value;
}

// FUNCTION: TITANIUM 0x00443C03
// @early-stop: budget, structural ndiff=33
// Once a frame: a fixed-hour zone just sets light and sun; otherwise the clock advances the sky blend.
void CDisplay_guess::ProcessSky_guess() {
    int elapsed_guess;
    int minute_guess;
    int hour_guess;
    int currentTime_guess;

    if (GetZoneTimeOfDay_guess(&hour_guess, &minute_guess) != 0) {
        SetAmbientLight_guess(g_timeSlots_guess[state_0145_guess]);
        if (g_clockInterface_guess != 0) {
            g_clockInterface_guess->Slot14_guess(
                (float)hour_guess * g_clockHourMultiplier_guess[0]
                    * g_clockMinuteMultiplier_guess[0]);
        }
        SetSunLight_guess();
        return;
    }

    currentTime_guess = FUN_0046d655_guess();
    if (g_clockPartHour_guess == hour_guess &&
        g_clockPartMinute_guess == minute_guess) {
        elapsed_guess = currentTime_guess - g_clockPartTime_guess;
    } else {
        g_clockPartHour_guess = hour_guess;
        g_clockPartMinute_guess = minute_guess;
        elapsed_guess = 0;
        g_clockPartTime_guess = currentTime_guess;
    }

    if (g_clockInterface_guess != 0) {
        g_clockInterface_guess->Slot14_guess(
            ((float)hour_guess * 60.0f
                + (float)(unsigned int)elapsed_guess * 0.00033333333f
                + (float)minute_guess) * 0.00069444446f);
        if (g_clockDuration_guess != 0) {
            elapsed_guess = frameTime_0148_guess - g_clockTarget_guess;
            g_clockInterface_guess->Slot05_guess(
                ((AngleMath_guess*)this)->FixHeading_guess(
                    (float)(unsigned int)elapsed_guess * g_clockScale_guess
                        / g_clockDuration_guess + g_clockBase_guess));
            g_clockInterface_guess->Slot07_guess(
                ((AngleMath_guess*)this)->FixHeading_guess(
                    g_clockInterface_guess->Slot04_guess() + 256.0f));
        }
    }

    if ((unsigned int)frameTime_0148_guess < (unsigned int)g_clockNext_guess) {
        SetAmbientLight_guess(1.0f);
        return;
    }

    g_clockNext_guess = frameTime_0148_guess + g_clockMinute_guess;
    ++state_0145_guess;
    if (state_0145_guess > 59) {
        state_0145_guess = 0;
    }
    if (g_clockInterval_guess-- == 0) {
        SetSkyBackground_guess();
        return;
    }
    g_clockTime_guess = frameTime_0148_guess;
    SetSunLight_guess();
}

// FUNCTION: TITANIUM 0x00443DBC
// Rebuilds the UI (probably after a skin change); fonts per language from [Fonts] Font.<lang>.0.
void CDisplay_guess::ReloadUI(int value) {
    char buffer[256];
    char key[256];
    FUN_00574110_guess("Loading UI.");
    FUN_00576e80_guess();
    g_flag799438_guess = (unsigned char)value;
    FUN_00574110_guess("Deactivating previous UI.");
    DeactivateMainUI_guess();
    g_stateDispatch_guess->Slot34_guess();
    FUN_00574110_guess("Unloading previous textures.");
    g_reset0043C29D_guess.Reset_guess();
    ResetUI_guess();
    FUN_00576e80_guess();
    InitNewUI_guess();
    FUN_00576e80_guess();
    if (g_everQuestOwner_guess->value_0b54_guess == 2) {
        InitCharSelectUI_guess();
    } else {
        InitGameUI_guess();
    }
    FUN_00576e80_guess();
    NoOp_guess();
    if (g_uiManager_guess->Test_guess() == 0) {
        strcpy(g_text850510_guess, pStringTable->getString(0xc4a, 0));
        g_value850988_guess = 0xd;
    } else if (g_compare850CA0_guess != 0 && g_compare850CA0_guess->HasUnreadStory_guess()) {
        strcpy(g_text850510_guess, pStringTable->getString(0xc73, 0));
        g_value850988_guess = 0xf;
    }
    if (g_everQuestOwner_guess->value_0b54_guess != 2) {
        ActivateMainUI_guess(value);
    }
    g_flag799438_guess = 1;
    sprintf(key, "Font.%s.0", g_fontNames_guess[g_language_guess]);
    g_everQuestOwner_guess->ReadFonts_guess("Fonts", key,
        g_languageService_guess->Slot31_guess(g_language_guess, 0), buffer, 0x100, 1);
    g_languageService_guess->Slot30_guess(g_language_guess, -1, buffer);
    g_everQuestOwner_guess->FUN_004b102d_guess();
    if (pinstCMapViewWnd_guess != 0) {
        pinstCMapViewWnd_guess->SelectMap_guess();
    }
    FUN_00576e80_guess();
}

struct SlideShow_guess : Worker_guess {
    // EXTERNAL: TITANIUM 0x004C4C83 SlideShow_guess::SlideShow_guess
    SlideShow_guess(const char* filename);
};

struct ZoneLoader_guess {
    virtual int Load_guess(const char* filename, int zero0, int zero1, int zero2);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Reset_guess();
    virtual void PostLoad_guess();
    virtual void Slot10_guess();
    virtual void CreateLight_guess(const char* name, int type, int count, void* table, void* colors,
        int first, int range, int second, int* output);
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
    virtual void SetFog_guess(const char* zoneName, float value, void* data);
};

struct ZoneRender_guess {
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
    virtual int GetExtents_guess(Vector3_guess* minimum, Vector3_guess* maximum);
    virtual void Slot14_guess();
    virtual void SetEffects_guess(int effects);
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void CreateSun_guess(int light, Vector3_guess* direction, int* output);
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
    virtual void AddSun_guess(int sun);
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void SetEnabled_guess(int enabled);
};

struct ZoneTable_guess {
    // EXTERNAL: TITANIUM 0x005F6ED0 ZoneTable_guess::GetName_guess
    void GetName_guess(int zone, char* name);
    // EXTERNAL: TITANIUM 0x005F6B90 ZoneTable_guess::GetType_guess
    int GetType_guess(int zone);
};

struct ZoneInfo_guess {
    unsigned char pad_0000_guess[0x10];
    char name_0010_guess[0x20];
};

struct Emitters_guess {
    // EXTERNAL: TITANIUM 0x004477AB Emitters_guess::Load_guess
    void Load_guess(const char* filename);
};

struct EntryList_guess : EntryTable_guess {
    // EXTERNAL: TITANIUM 0x0043DA31 EntryList_guess::EntryList_guess
    EntryList_guess(const char* filename);
};

struct AssetNode_guess {
    virtual void Load_guess(int zero0, int zero1);
    AssetNode_guess* next_0004_guess;
};

struct AssetList_guess {
    int value_0000_guess;
    AssetNode_guess* first_0004_guess;
    int value_0008_guess;
    // EXTERNAL: TITANIUM 0x00405359 AssetList_guess::AssetList_guess
    AssetList_guess(const char* filename);
    // EXTERNAL: TITANIUM 0x00405463 AssetList_guess::Clear_guess
    void Clear_guess();
};

struct ZoneDisplay_guess {
    unsigned char pad_0000_guess[0x204];
    int zone_0204_guess;
};

struct ZonePcBase_guess {
    int pad_0000_guess[2];
};
struct ZonePcVirtual_guess {
    unsigned char pad_0000_guess[0x100];
    int zone_0100_guess;
    void SetZone_guess(int zone) { zone_0100_guess = zone; }
};
struct ZonePc_guess : ZonePcBase_guess, virtual ZonePcVirtual_guess {
};

struct MusicQueue_guess {
    // EXTERNAL: TITANIUM 0x0044C1BC MusicQueue_guess::LoadZone_guess
    void LoadZone_guess(const char* zoneName);
};

struct TargetIndicator_guess {
    // EXTERNAL: TITANIUM 0x004C874B TargetIndicator_guess::TargetIndicator_guess
    TargetIndicator_guess();
    // EXTERNAL: TITANIUM 0x004C8143 TargetIndicator_guess::SetEnabled_guess
    void SetEnabled_guess(bool visible);
    unsigned char data_0000_guess[0x40];
};

struct PlayerPath_guess {
    // EXTERNAL: TITANIUM 0x004C1733 PlayerPath_guess::PlayerPath_guess
    PlayerPath_guess();
    unsigned char data_0000_guess[0x400];
};

struct Precipitation_guess {
    // EXTERNAL: TITANIUM 0x004C3325 Precipitation_guess::Start_guess
    void Start_guess();
};

// EXTERNAL: TITANIUM 0x004C32FF FUN_004c32ff_guess
Precipitation_guess* __stdcall FUN_004c32ff_guess(const char* zoneName);
// EXTERNAL: TITANIUM 0x00465108 msg_teleport_index_guess
void __cdecl msg_teleport_index_guess(const char* zoneName);
// EXTERNAL: TITANIUM 0x0044D1AE CreatePartEffects_guess
void __cdecl CreatePartEffects_guess();
// EXTERNAL: TITANIUM 0x005331ED FUN_005331ed_guess
void __cdecl FUN_005331ed_guess(int zone, Vector3_guess* minimum, Vector3_guess* maximum);
// EXTERNAL: TITANIUM 0x00469DD7 FUN_00469dd7_arg_guess
void __cdecl FUN_00469dd7_arg_guess(int value);

#define g_slideShow_guess EQ_GLOBAL(Worker_guess*, 0x0085098C)
#define g_zoneLoader_guess EQ_GLOBAL(ZoneLoader_guess*, 0x0099E360)
#define g_zoneRender_guess EQ_GLOBAL(ZoneRender_guess*, 0x0099E368)
#define g_zoneTable_guess EQ_GLOBAL(ZoneTable_guess*, 0x00905CC0)
#define g_zoneIndex_guess EQ_GLOBAL(IndexedTable_guess*, 0x00905CC0)
#define g_zoneId_guess EQ_GLOBAL(int, 0x00924470)
#define g_emitters_guess EQ_GLOBAL(Emitters_guess, 0x00850DC8)
#define g_zoneDisplay_guess EQ_GLOBAL(ZoneDisplay_guess*, 0x00905CE4)
#define g_zonePc_guess EQ_GLOBAL(ZonePc_guess*, 0x00905D00)
#define g_lightTable_guess EQ_GLOBAL(void*, 0x00698A0C)
#define g_musicQueue_guess EQ_GLOBAL(MusicQueue_guess*, 0x00851390)
#define g_targetIndicator_guess EQ_GLOBAL(TargetIndicator_guess*, 0x00985CE4)
#define g_playerPath_guess EQ_GLOBAL(PlayerPath_guess*, 0x00985C88)
#define g_lastZoneName_guess EQ_ARRAY(char, 0x00987650)
#define g_fogData_guess EQ_ARRAY(unsigned char, 0x00850B90)

// FUNCTION: TITANIUM 0x00444116
// @early-stop: budget, diff ndiff=1
// Zone ids over 1000 keep their low 16 bits. Zone 0xBC (probably a tutorial zone) gets the slide show;
// 0xCA (poknowledge) also loads poknowledge_obj3.eqg. Loads the .eqg or the s3d set (_obj2, _obj, _2_obj,
// _chr2, 2_chr, _chr, the _chr.txt models, _assets.txt, objects, lights), then cameras, lights and effects.
void CDisplay_guess::LoadZone_guess(int zone) {
    char zoneName[32];
    char name[512];
    char lightName[20];
    char name2[512];
    char eqgPath[512];
    char fullPath[512];
    char eqgName[512];
    char message[512];
    char message2[512];
    char emitters[512];
    int progress;
    char loadedEqg;

    loadedEqg = 0;
    int id = zone;
    if (id > 1000) {
        id &= 0xffff;
    }
    // Zone 188 shows the loading slideshow (Resources/SlideShow/SlideShow.txt).
    if (id == 0xbc) {
        g_slideShow_guess = new SlideShow_guess("Resources/SlideShow/SlideShow.txt");
    }
    if (g_slideShow_guess != 0) {
        g_slideShow_guess->Start_guess();
        Sleep(1);
    }
    g_zoneLoader_guess->Reset_guess();
    value_0000_guess = 0;
    EQ_GLOBAL(int, 0x00924678) = 0;
    EQ_GLOBAL(unsigned char, 0x00924673) = 0;
    EQ_GLOBAL(unsigned char, 0x00924675) = 0;
    EQ_GLOBAL(unsigned char, 0x00924676) = 0;
    EQ_GLOBAL(unsigned char, 0x009237B9) = 0;
    EQ_GLOBAL(int, 0x009237BC) = 0;
    g_zoneId_guess = zone;
    g_zoneTable_guess->GetName_guess(zone, zoneName);
    EQ_GLOBAL(unsigned char, 0x0095A174) = 0;
    progress = 0;
    EQ_GLOBAL(int, 0x0098580C) = 0;
    g_everQuestText_guess->DoLoadScreen_guess(0);
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, 0, "Loading zone file(s)");
    ZoneInfo_guess* info = (ZoneInfo_guess*)g_zoneIndex_guess->Get_guess(g_zoneId_guess);
    if (info != 0) {
        sprintf(emitters, "%s_EnvironmentEmitters.txt", info->name_0010_guess);
        g_emitters_guess.Load_guess(emitters);
    }
    if (g_sky_guess != 0) {
        g_sky_guess->Follow_guess(g_skyValue_guess);
    }
    strcpy(eqgName, zoneName);
    // Newer zones load from <zone>.EQG. Without one the classic <zone>.s3d must exist (zones 130 and 180 are
    // exempt), or the world display does not start.
    AppendString_guess(eqgName, ".EQG");
    FUN_00574110_guess("Attempting to load %s.", eqgName);
    if (g_zoneLoader_guess->Load_guess(eqgName, 0, 0, 0) == 0) {
        FUN_00574110_guess("Loaded %s.", eqgName);
        loadedEqg = 1;
        progress = 0x28;
    }
    FUN_00574110_guess("Verifying world files.");
    if (loadedEqg == 0 && zone != 0xb4 && zone != 0x82) {
        strcpy(eqgPath, zoneName);
        AppendString_guess(eqgPath, ".s3d");
        if (!BuildPath_guess(fullPath, eqgPath)) {
            FUN_00574110_guess("ERROR: Unable to get path to specified world file [%s] (%d, %s).  Not starting world display.\n",
                fullPath, zone, zoneName);
            FUN_0046da4a_guess(message, 0x4f8, zoneName, 0, 0, 0, 0, 0, 0, 0, 0);
            StartWorldDisplay_Bailout(message);
        }
        if (!FileExists_guess(fullPath)) {
            FUN_00574110_guess("ERROR: Unable to find specified world file [%s] (%d, %s).  Not starting world display.\n",
                fullPath, zone, zoneName);
            FUN_0046da4a_guess(message, 0x4f8, zoneName, 0, 0, 0, 0, 0, 0, 0, 0);
            StartWorldDisplay_Bailout(message);
        }
    }
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
    g_client_guess->UpdateSoundEnvironment_guess();
    EQ_GLOBAL(int, 0x00924684) = -1;
    EQ_GLOBAL(int, 0x0092446C) = 0;
    if (EQ_GLOBAL(unsigned char, 0x00923798) != 0 || g_statusFlag_436039_guess != 0) {
        if (g_zoneDisplay_guess != 0) {
            g_zoneDisplay_guess->zone_0204_guess = zone;
        }
        if (g_zonePc_guess != 0) {
            g_zonePc_guess->SetZone_guess(zone);
        }
        msg_teleport_index_guess(zoneName);
    }
    state_2d2c_guess = 1;
    state_0004_guess = 1;
    state_014c_guess = 0;
    state_014d_guess = 0;
    g_renderSettings_guess->Slot27_guess(g_gammaValue_guess * 0.1f + 0.5f);
    // Zone files: zone type 6 gets OBEQUIP_LEXIT; <zone>_pre_chr.txt lists NPC models to load from .eqg
    // files.
    FUN_00574110_guess("Loading zone specific files.");
    if (g_zoneTable_guess->GetType_guess(zone) == 6) {
        strcpy(name, "OBEQUIP_LEXIT");
        strcpy(name2, "OBEQUIP_LEXIT");
        LoadWorldFile_guess((int)name, (int)name2, 0, 0, 1, 0);
        progress += 10;
    }
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");

    sprintf(name, "%s_pre_chr.txt", zoneName);
    EntryList_guess* list = new EntryList_guess(name);
    int count = list->count_0004_guess;
    for (int i = 0; i < count; ++i) {
        char* file = (char*)list->GetOther_guess(i);
        if (file != 0) {
            strcpy(name, file);
            strcpy(name2, name);
            char* code = (char*)list->GetValue_guess(i);
            if (code != 0) {
                if (name[2] == code[2] && name[1] == code[1] && name[0] == code[0]) {
                    strcpy(eqgPath, name);
                    AppendString_guess(eqgPath, ".EQG");
                    if (g_zoneLoader_guess->Load_guess(eqgPath, 0, 0, 0) == 0) {
                        FUN_00574110_guess("Loaded %s.", eqgPath);
                    }
                }
                FUN_00574110_guess("Loaded NPC with code %s from %s.eqg\n", code, file);
            }
            ++progress;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        }
    }
    list->FreeAll_guess();
    free(list);

    if (loadedEqg == 0) {
        if (zone == 0xca) {
            // Classic zones: object files, language-specific first (<zone>_<lang>_obj2, _obj, _2_obj), then
            // the character files (_chr2, 2_chr...).
            g_zoneLoader_guess->Load_guess("poknowledge_obj3.eqg", 0, 0, 0);
        }
        sprintf(name, "%s_%2s_obj2.s3d", zoneName, g_fontNames_guess[g_language_guess]);
        if (FileExists_guess(name)) {
            sprintf(name, "%s_%2s_obj2", zoneName, g_fontNames_guess[g_language_guess]);
        } else {
            sprintf(name, "%s_obj2", zoneName);
        }
        strcpy(name2, name);
        LoadWorldFile_guess((int)name, (int)name2, 0, 0, 1, 0);
        progress += 5;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        sprintf(name, "%s_%2s_obj.s3d", zoneName, g_fontNames_guess[g_language_guess]);
        if (FileExists_guess(name)) {
            sprintf(name, "%s_%2s_obj", zoneName, g_fontNames_guess[g_language_guess]);
        } else {
            sprintf(name, "%s_obj", zoneName);
        }
        strcpy(name2, name);
        if (!LoadWorldFile_guess((int)name, (int)name2, 0, 0, 1, 0)) {
            value_0000_guess = 1;
            FUN_00574110_guess("LoadWorldFile() failed.  Cannot load %s.  Failing.", name);
            FUN_0046da4a_guess(eqgPath, 0x4f9, name, 0, 0, 0, 0, 0, 0, 0, 0);
            StartWorldDisplay_Bailout(eqgPath);
        }
        progress += 5;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        sprintf(name, "%s_%2s_2_obj.s3d", zoneName, g_fontNames_guess[g_language_guess]);
        if (FileExists_guess(name)) {
            sprintf(name, "%s_%2s_2_obj", zoneName, g_fontNames_guess[g_language_guess]);
        } else {
            sprintf(name, "%s_2_obj", zoneName);
        }
        strcpy(name2, name);
        strcpy(fullPath, name);
        AppendString_guess(fullPath, ".s3d");
        if (FileExists_guess(fullPath)) {
            LoadWorldFile_guess((int)name, (int)name2, 0, 0, 1, 0);
        }
        sprintf(name, "%s_chr2", zoneName);
        sprintf(name2, "%s_chr2", zoneName);
        LoadWorldFile_guess((int)name, (int)name2, 0, 0, 0, 0);
        progress += 5;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        if (HasSecondChr_guess(zone)) {
            sprintf(name, "%s2_chr", zoneName);
            sprintf(name2, "%s2_chr", zoneName);
            LoadWorldFile_guess((int)name, (int)name2, 0, 0, 0, 0);
            progress += 5;
            DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        }
        sprintf(name, "%s_chr", zoneName);
        sprintf(name2, "%s_chr", zoneName);
        LoadWorldFile_guess((int)name, (int)name2, 0, 0, 0, 0);
        progress += 5;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
    }

    sprintf(name, "%s_chr.txt", zoneName);
    list = new EntryList_guess(name);
    count = list->count_0004_guess;
    for (int j = 0; j < count; ++j) {
        char* file = (char*)list->GetOther_guess(j);
        if (file != 0) {
            strcpy(name, file);
            strcpy(name2, name);
            char* code = (char*)list->GetValue_guess(j);
            if (code != 0) {
                if (name[2] == code[2] && name[1] == code[1] && name[0] == code[0]) {
                    strcpy(eqgPath, name);
                    AppendString_guess(eqgPath, ".EQG");
                    if (g_zoneLoader_guess->Load_guess(eqgPath, 0, 0, 0) == 0) {
                        FUN_00574110_guess("Loaded %s.", eqgPath);
                    } else {
                        LoadWorldFile_guess((int)name, (int)name2, 0, 0, 0, 0);
                    }
                } else {
                    LoadNpc_guess(name, name2, code);
                }
                FUN_00574110_guess("Loaded NPC with code %s from %s.s3d\n", code, file);
                ++progress;
                DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
            }
        }
    }
    list->FreeAll_guess();
    free(list);

    sprintf(name, "%s_assets.txt", zoneName);
    AssetList_guess* assets = new AssetList_guess(name);
    for (AssetNode_guess* node = assets->first_0004_guess; node != 0; node = node->next_0004_guess) {
        node->Load_guess(0, 0);
    }
    assets->Clear_guess();
    free(assets);

    if (loadedEqg == 0) {
        strcpy(name2, zoneName);
        strcpy(name, zoneName);
        if (!LoadWorldFile_guess((int)name, (int)name2, 0, 0, 0, 0)) {
            value_0000_guess = 1;
            FUN_00574110_guess("LoadWorldFile() failed.  Cannot load %s.  Failing.", name);
            FUN_0046da4a_guess(message2, 0x4f9, name, 0, 0, 0, 0, 0, 0, 0, 0);
            StartWorldDisplay_Bailout(message2);
        }
        progress += 5;
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress, "Loading zone file(s)");
        if (value_0000_guess == 0) {
            strcpy(name, zoneName);
            sprintf(name2, "objects");
            LoadWorldFile_guess((int)name, (int)name2, 0, 1, 0, 0);
            value_0000_guess = 0;
        }
        DoLoadScreenProgressBar_guess(g_globalSettings_guess, progress + 5, "Loading zone file(s)");
        if (value_0000_guess == 0) {
            strcpy(name, zoneName);
            sprintf(name2, "lights");
            LoadWorldFile_guess((int)name, (int)name2, 0, 1, 0, 0);
            value_0000_guess = 0;
        }
    }
    DoLoadScreenProgressBar_guess(g_globalSettings_guess, 100, "Loading zone file(s)");
    if (g_slideShow_guess == 0) {
        g_everQuestText_guess->DoLoadScreen_guess(1);
    }

    FUN_00574110_guess("Initializing cameras.");
    EQ_GLOBAL(float, 0x009237C4) = 0.8f;
    EQ_GLOBAL(float, 0x009237C0) = 0.625f;
    value_2d14_guess = 1.0f;
    ((Vector3_guess*)buffer_011c_guess)->x_0000_guess = 0.0f;
    ((Vector3_guess*)buffer_011c_guess)->y_0004_guess = 0.0f;
    ((Vector3_guess*)buffer_011c_guess)->z_0008_guess = 9.0f;
    ((Vector3_guess*)buffer_0120_guess)->x_0000_guess = 0.0f;
    ((Vector3_guess*)buffer_0120_guess)->y_0004_guess = 0.0f;
    ((Vector3_guess*)buffer_0120_guess)->z_0008_guess = 0.0f;
    if (callback_0118_guess != 0) {
        callback_0118_guess->Slot14_guess(buffer_0120_guess);
        if (callback_0118_guess->Slot13_guess((Vector3_guess*)buffer_011c_guess, 0) != 0) {
            FUN_00574110_guess("* Bad Initial Camera Location!\n");
        }
    }

    FUN_00574110_guess("Initializing lights.");
    strcpy(lightName, "mylight01");
    EQ_GLOBAL(float, 0x00850D88) = 1.0f;
    EQ_GLOBAL(float, 0x00850D8C) = 0.9f;
    EQ_GLOBAL(float, 0x00850D90) = 0.8f;
    EQ_GLOBAL(float, 0x00850D94) = 0.8f;
    EQ_GLOBAL(float, 0x00850D98) = 0.9f;
    EQ_GLOBAL(float, 0x00850D9C) = 1.0f;
    g_zoneLoader_guess->CreateLight_guess(lightName, 1, 1, g_lightTable_guess, 0, 0, 500, 1, &playerLight_2d18_guess);
    float sunTable[1];
    float sunColor[3];
    sunTable[0] = 1.0f;
    sunColor[0] = 1.0f;
    sunColor[1] = 1.0f;
    sunColor[2] = 1.0f;
    g_zoneLoader_guess->CreateLight_guess("SUN_LIGHTDEF", 1, 1, sunTable, sunColor, 0, 0x1e, 1, &sunLight_2d1c_guess);
    Vector3_guess direction;
    direction.x_0000_guess = -0.707f;
    direction.y_0004_guess = 0.0f;
    direction.z_0008_guess = -0.707f;
    g_zoneRender_guess->CreateSun_guess(sunLight_2d1c_guess, &direction, &value_2d20_guess);
    ((ViewPoint_guess*)value_2d20_guess)->Slot00_guess();
    ((ViewPoint_guess*)value_2d20_guess)->Slot01_guess();
    g_zoneRender_guess->AddSun_guess(value_2d20_guess);
    InitCommonLights_guess();

    FUN_00574110_guess("Initializing visual effects.");
    CreatePartEffects_guess();
    g_zoneRender_guess->SetEffects_guess(FUN_0046d655_guess());
    value_2cf8_guess = 1;
    g_zoneRender_guess->SetEnabled_guess(1);
    g_musicQueue_guess->LoadZone_guess(zoneName);
    Vector3_guess minExtent;
    Vector3_guess maxExtent;
    if (g_zoneRender_guess->GetExtents_guess(&minExtent, &maxExtent) == -1) {
        minExtent.x_0000_guess = -2000.0f;
        minExtent.y_0004_guess = -2000.0f;
        minExtent.z_0008_guess = -2000.0f;
        maxExtent.x_0000_guess = 2000.0f;
        maxExtent.y_0004_guess = 2000.0f;
        maxExtent.z_0008_guess = 2000.0f;
        FUN_00574110_guess("Failed to Get World Extents, using default values.\n");
    }
    if (pinstCMapViewWnd_guess != 0) {
        pinstCMapViewWnd_guess->SelectMap_guess();
    } else {
        FUN_005331ed_guess(zone, &minExtent, &maxExtent);
    }
    FUN_00469dd7_arg_guess(1);
    state_2d54_guess = 1;
    if (zone != 0xbe) {
        strcpy(g_lastZoneName_guess, zoneName);
    }
    if (EQ_GLOBAL(int, 0x00924978) != 0) {
        SetPCNameSpriteState_guess(1);
    } else {
        SetPCNameSpriteState_guess(0);
    }
    if (EQ_GLOBAL(int, 0x0092497C) != 0) {
        SetNPCNameSpriteState_guess(1);
    } else {
        SetNPCNameSpriteState_guess(0);
    }
    TurnInfravisionEffectOff_guess();
    if (g_stateMode_guess != 0) {
        g_zoneLoader_guess->SetFog_guess(zoneName, g_stateFloat_guess, g_fogData_guess);
        EQ_GLOBAL(int, 0x00924828) = 1;
    }
    g_client_guess->SetSkyBackground_guess();

    FUN_00574110_guess("Initializing target indicator.");
    g_targetIndicator_guess = new TargetIndicator_guess;
    g_targetIndicator_guess->SetEnabled_guess(EQ_GLOBAL(int, 0x009254C0) != 0);
    FUN_00574110_guess("Initializing player path.");
    g_playerPath_guess = new PlayerPath_guess;
    FUN_00574110_guess("Performing post-load operations.");
    g_zoneLoader_guess->PostLoad_guess();
    FUN_00574110_guess("Initializing precipitation system.");
    FUN_004c32ff_guess(zoneName)->Start_guess();
    FUN_00574110_guess("World initialized: %s", zoneName);
}

// Window group: a 0x10 node holding the children added to it.
struct WindowGroup_guess {
    int value_0000_guess;
    int value_0004_guess;
    int value_0008_guess;
    unsigned char flag_000c_guess;
    WindowGroup_guess() {
        value_0004_guess = 0;
        value_0000_guess = 0;
        value_0008_guess = 0;
        flag_000c_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0050319B WindowGroup_guess::Add_guess
    void Add_guess(int key, MenuTextItem_guess* const& item);
    void Append_guess(MenuTextItem_guess* item) { Add_guess(value_0000_guess, item); }
};

// EXTERNAL: TITANIUM 0x00641F28 ??_7MenuSeparator_guess@@6B@
struct MenuSeparator_guess : MenuItemBase_guess {
    virtual void Slot00_guess();
    unsigned char state_0008_guess;
    MenuSeparator_guess() : MenuItemBase_guess(2) { state_0008_guess = 1; }
};

#define g_pvpEnabled_guess EQ_GLOBAL(int, 0x00900478)
#define g_upgradeOffered_guess EQ_GLOBAL(unsigned char, 0x00923D66)

// FUNCTION: TITANIUM 0x00441AC6
// @early-stop: budget, diff ndiff=6
// The EQ button menu; each CommandMenuItem's third argument is the command id it runs.
WindowGroup_guess* CreateMainMenu_guess() {
    WindowGroup_guess* root = new WindowGroup_guess;
    WindowGroup_guess* group = new WindowGroup_guess;
    group->Append_guess(new CommandMenuItem_guess(-1, "Atlas/Map", 0xbb));
    group->Append_guess(new CommandMenuItem_guess(-1, "Compass", 0xae));
    group->Append_guess(new CommandMenuItem_guess(-1, "Find", 0xc9));
    root->Append_guess(new SubMenuItem_guess(10, "Navigation", (int)group));

    group = new WindowGroup_guess;
    group->Append_guess(new CommandMenuItem_guess(-1, "Group Status", 0x98));
    group->Append_guess(new CommandMenuItem_guess(-1, "Guild", 0xbc));
    group->Append_guess(new CommandMenuItem_guess(-1, "Raid", 0xaf));
    group->Append_guess(new CommandMenuItem_guess(-1, "Looking for Group", 0xbd));
    group->Append_guess(new CommandMenuItem_guess(-1, "Friends/Ignore", 0xa7));
    root->Append_guess(new SubMenuItem_guess(9, "Players", (int)group));

    group = new WindowGroup_guess;
    group->Append_guess(new CommandMenuItem_guess(-1, "Combat Abilities", 0xd4));
    group->Append_guess(new CommandMenuItem_guess(-1, "Target", 0x99));
    group->Append_guess(new CommandMenuItem_guess(-1, "Hotkeys 1", 0x9c));
    group->Append_guess(new CommandMenuItem_guess(-1, "Hotkeys 2", 0x9d));
    group->Append_guess(new CommandMenuItem_guess(-1, "Hotkeys 3", 0x9e));
    group->Append_guess(new CommandMenuItem_guess(-1, "Hotkeys 4", 0x9f));
    group->Append_guess(new CommandMenuItem_guess(-1, "Bandolier", 0xe1));
    group->Append_guess(new CommandMenuItem_guess(-1, "Voice Macro", 0xda));
    group->Append_guess(new CommandMenuItem_guess(-1, "Audio Triggers", 0xe6));
    group->Append_guess(new CommandMenuItem_guess(-1, "Actions Window", 0xa3));
    root->Append_guess(new SubMenuItem_guess(8, "Actions", (int)group));

    group = new WindowGroup_guess;
    group->Append_guess(new CommandMenuItem_guess(-1, "NPC Journal", 0xb7));
    group->Append_guess(new CommandMenuItem_guess(-1, "Expeditions", 0xd5));
    group->Append_guess(new CommandMenuItem_guess(-1, "Quest Journal", 0xd7));
    group->Append_guess(new CommandMenuItem_guess(-1, "Adventures", 0xc6));
    root->Append_guess(new SubMenuItem_guess(7, "Quests", (int)group));

    group = new WindowGroup_guess;
    group->Append_guess(new CommandMenuItem_guess(-1, "Player Information", 0x97));
    group->Append_guess(new CommandMenuItem_guess(-1, EQ_ARRAY(char, 0x00642BF8), 0xa8));
    group->Append_guess(new CommandMenuItem_guess(-1, "Spell Gems", 0x9a));
    group->Append_guess(new CommandMenuItem_guess(-1, "Spell Book", 0x81));
    group->Append_guess(new CommandMenuItem_guess(-1, "Alternate Advancement", 0xa4));
    group->Append_guess(new CommandMenuItem_guess(-1, "Buffs", 0x9b));
    group->Append_guess(new CommandMenuItem_guess(-1, "Short Duration Buffs", 0xb8));
    group->Append_guess(new CommandMenuItem_guess(-1, "Leadership", 0xca));
    group->Append_guess(new CommandMenuItem_guess(-1, "Tribute", 0xcb));
    if (g_pvpEnabled_guess != 0) {
        group->Append_guess(new CommandMenuItem_guess(-1, "PvP Stats", 0xd6));
    }
    root->Append_guess(new SubMenuItem_guess(5, "Character", (int)group));

    root->Append_guess(new CommandMenuItem_guess(7, "Storyline", 0xba));
    root->Append_guess(new CommandMenuItem_guess(6, "Skills", 0xe4));
    root->Append_guess(new CommandMenuItem_guess(4, "Mail", 0xa1));
    root->Append_guess(new CommandMenuItem_guess(3, "Inventory", 0xe));
    root->Append_guess(new CommandMenuItem_guess(2, "Options", 0xa9));
    root->Append_guess((MenuTextItem_guess*)new MenuSeparator_guess);
    if (g_upgradeOffered_guess != 0) {
        root->Append_guess(new CommandMenuItem_guess(11, "Upgrade EverQuest", 0xe5));
        root->Append_guess((MenuTextItem_guess*)new MenuSeparator_guess);
    }
    root->Append_guess(new CommandMenuItem_guess(1, "Help", 0xaa));
    root->Append_guess(new CommandMenuItem_guess(0, "Camp & Quit", 0x89));
    return root;
}

struct Particle_445243_guess {
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
    virtual void SetPosition_guess(float x, float y, float z);
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
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void SetEnabled_guess(bool enabled);
};

typedef bool (__cdecl *PlayerCallback_445243_guess)(EQPlayer* player, int value);

struct World_445243_guess {
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
    virtual void SetTime_guess(int time);
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
    virtual void SetSky_guess(void* sky);
    virtual void Slot29_guess();
    virtual void SetClip_guess(void* buffer, float distance, int one);
    virtual void ForEachPlayer_guess(PlayerCallback_445243_guess callback);
};

struct Render_445243_guess {
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
    virtual void DrawExtra_guess();
    virtual void BeginFrame_guess();
    virtual void EndFrame_guess();
};

struct Sky_445243_guess {
    virtual void SetName_guess(const char* name);
    virtual void Slot01_guess();
    virtual void SetName2_guess(const char* name, float value);
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
    virtual void Follow_guess(int value);
};

struct CameraView_445243_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float GetDistance_guess();
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
    virtual void SetFirst_guess(void* value);
    virtual void SetSecond_guess(void* value);
    virtual float GetValue_guess();
};

struct ClientView_445243_guess {
    unsigned char pad_0000_guess[0x118];
    CameraView_445243_guess* camera_0118_guess;
};

struct CameraQueue_445243_guess {
    // EXTERNAL: TITANIUM 0x0044A78F CameraQueue_445243_guess::GetRoomType_guess
    void GetRoomType_guess();
    // EXTERNAL: TITANIUM 0x0044A7B1 CameraQueue_445243_guess::SetListenerLocation_guess
    void SetListenerLocation_guess(float x, float y, float z, float value);
    // EXTERNAL: TITANIUM 0x0044A63A CameraQueue_445243_guess::ProcessSound_guess
    void ProcessSound_guess();
};

struct OffsetList_445243_guess {
    // EXTERNAL: TITANIUM 0x004B6AE6 OffsetList_445243_guess::FUN_004b6ae6_guess
    void FUN_004b6ae6_guess();
};

// EXTERNAL: TITANIUM 0x004B6A36 GetOffsetList_445243_guess
OffsetList_445243_guess* __cdecl GetOffsetList_445243_guess();

struct Message_445243_guess {
    // EXTERNAL: TITANIUM 0x00469DD7 Message_445243_guess::NoOp_guess
    void NoOp_guess();
};

// EXTERNAL: TITANIUM 0x00406AEF GetMessage_445243_guess
Message_445243_guess* __cdecl GetMessage_445243_guess();

struct Window_445243_guess {
    unsigned char pad_0000_guess[9];
    unsigned char state_0009_guess;
    // EXTERNAL: TITANIUM 0x004C36CD Window_445243_guess::UpdateWeather_guess
    void UpdateWeather_guess();
    // EXTERNAL: TITANIUM 0x004C38D5 Window_445243_guess::FUN_004c38d5_guess
    void FUN_004c38d5_guess();
};

// EXTERNAL: TITANIUM 0x004C32FF GetWindow_445243_guess
Window_445243_guess* __cdecl GetWindow_445243_guess();

struct Controller_445243_guess {
    // EXTERNAL: TITANIUM 0x00407F6A Controller_445243_guess::Draw_guess
    void Draw_guess();
};

// EXTERNAL: TITANIUM 0x00407DC9 GetController_445243_guess
Controller_445243_guess* __cdecl GetController_445243_guess();

struct Visibility_445243_guess {
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
    virtual void Slot044_guess();
    virtual void Slot045_guess();
    virtual void Slot046_guess();
    virtual void Slot047_guess();
    virtual void Slot048_guess();
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
    virtual void Slot059_guess();
    virtual void Slot060_guess();
    virtual void Slot061_guess();
    virtual void Slot062_guess();
    virtual void Slot063_guess();
    virtual void Slot064_guess();
    virtual void Slot065_guess();
    virtual void Slot066_guess();
    virtual void Slot067_guess();
    virtual void Slot068_guess();
    virtual void Slot069_guess();
    virtual void Slot070_guess();
    virtual void Slot071_guess();
    virtual void Slot072_guess();
    virtual void Slot073_guess();
    virtual void Slot074_guess();
    virtual void Slot075_guess();
    virtual void Slot076_guess();
    virtual void Slot077_guess();
    virtual void Slot078_guess();
    virtual void Slot079_guess();
    virtual void Slot080_guess();
    virtual void Slot081_guess();
    virtual void Slot082_guess();
    virtual void Slot083_guess();
    virtual void Slot084_guess();
    virtual void Slot085_guess();
    virtual void Slot086_guess();
    virtual void Slot087_guess();
    virtual void Slot088_guess();
    virtual void Slot089_guess();
    virtual void Slot090_guess();
    virtual void Slot091_guess();
    virtual void Slot092_guess();
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
    virtual void Slot105_guess();
    virtual void Slot106_guess();
    virtual bool IsHidden_guess();
};

struct ActorModel_445243_guess {
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
    virtual void Update_guess();
};

struct ActorInfo_445243_guess {
    ActorModel_445243_guess* model_0000_guess;
    unsigned char pad_0004_guess[0x154 - 4];
    unsigned char state_0154_guess;
    unsigned char pad_0155_guess[3];
    EQPlayer* mount_0158_guess;
    unsigned char pad_015c_guess[0xebc - 0x15c];
    int time_0ebc_guess;
};

struct Spawn_445243_guess {
    unsigned char pad_0000_guess[0x30];
    Vector3_guess position_0030_guess;
    unsigned char pad_003c_guess[0x1a8 - 0x3c];
    ActorInfo_445243_guess* info_01a8_guess;
    unsigned char pad_01ac_guess[0x214 - 0x1ac];
    Spawn_445243_guess* next_0214_guess;
    // EXTERNAL: TITANIUM 0x004898D6 Spawn_445243_guess::GetVisibility_guess
    Visibility_445243_guess* GetVisibility_guess();
    // EXTERNAL: TITANIUM 0x0048BA76 Spawn_445243_guess::MovePlayer_guess
    int MovePlayer_guess();
    // EXTERNAL: TITANIUM 0x00480409 Spawn_445243_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
};

struct GroundData_445243_guess {
    int value_0000_guess;
    unsigned char pad_0004_guess[0x4c];
    int time_0050_guess;
    unsigned char pad_0054_guess[0x1005 - 0x54];
    unsigned char state_1005_guess;
};

struct GroundItem_445243_guess {
    unsigned char pad_0000_guess[8];
    GroundItem_445243_guess* next_0008_guess;
    unsigned char pad_000c_guess[0x48 - 0xc];
    GroundData_445243_guess* data_0048_guess;
    // EXTERNAL: TITANIUM 0x00476B12 GroundItem_445243_guess::CreateActorWhenReady_guess
    void CreateActorWhenReady_guess();
    // EXTERNAL: TITANIUM 0x0047789D GroundItem_445243_guess::MissileTeardown_guess
    void MissileTeardown_guess();
    // EXTERNAL: TITANIUM 0x004766AA GroundItem_445243_guess::TrackTarget_guess
    void TrackTarget_guess();
};

struct GroundOwner_445243_guess {
    // EXTERNAL: TITANIUM 0x00477CC9 GroundOwner_445243_guess::MoveMissile_guess
    void MoveMissile_guess(GroundItem_445243_guess* item);
};

// EXTERNAL: TITANIUM 0x004BFE0F FUN_004bfe0f_item_guess
void __cdecl FUN_004bfe0f_item_guess(Spawn_445243_guess* spawn, GroundItem_445243_guess* item, int zero);

struct ModeEntry_445243_guess {
    unsigned char pad_0000_guess[0x46];
    unsigned char state_0046_guess;
};

struct ZoneAction_445243_guess {
    // EXTERNAL: TITANIUM 0x0056FFA8 ZoneAction_445243_guess::FUN_0056ffa8_guess
    void FUN_0056ffa8_guess();
};

// EXTERNAL: TITANIUM 0x004798B7 FindZoneAction_445243_guess
ZoneAction_445243_guess* __cdecl FindZoneAction_445243_guess(void* actor);

struct CharPart_445243_guess {
    // EXTERNAL: TITANIUM 0x00422198 CharPart_445243_guess::DoPassageOfTime_guess
    void DoPassageOfTime_guess();
};

struct Char_445243_guess {
    unsigned char pad_0000_guess[0xc280];
    CharPart_445243_guess part_c280_guess;
};

struct Target_445243_guess {
    unsigned char pad_0000_guess[0x258];
    int id_0258_guess;
    // EXTERNAL: TITANIUM 0x0047AA0B Target_445243_guess::SetNameSpriteTint
    void SetNameSpriteTint();
};

// EXTERNAL: TITANIUM 0x00401B28 FindTarget_445243_guess
Target_445243_guess* __cdecl FindTarget_445243_guess(int id);

// EXTERNAL: TITANIUM 0x00611BE8 _control87
extern "C" unsigned int __cdecl _control87(unsigned int value, unsigned int mask);
// EXTERNAL: TITANIUM 0x004B8DFD DrawNetStatus
void __cdecl DrawNetStatus(int x, int y, int value, int zero);

struct Effects_445243_guess {
    // EXTERNAL: TITANIUM 0x004C2CDF Effects_445243_guess::ProcessPath_guess
    void ProcessPath_guess(Vector3_guess* position);
};

struct Resources_445243_guess {
    // EXTERNAL: TITANIUM 0x004C8FDB Resources_445243_guess::Process_guess
    void Process_guess(Vector3_guess* position);
};

#define g_frameToggle_445243_guess EQ_GLOBAL(int, 0x00923CB8)
#define g_particleMode_445243_guess EQ_GLOBAL(int, 0x00923C80)
#define g_particle_445243_guess EQ_GLOBAL(Particle_445243_guess*, 0x0099E36C)
#define g_world_445243_guess EQ_GLOBAL(World_445243_guess*, 0x0099E368)
#define g_render_445243_guess EQ_GLOBAL(Render_445243_guess*, 0x0099E364)
#define g_sky_445243_guess EQ_GLOBAL(Sky_445243_guess*, 0x008503A8)
#define g_cameraQueue_445243_guess EQ_GLOBAL(CameraQueue_445243_guess*, 0x00851390)
#define g_localSpawn_445243_guess EQ_GLOBAL(Spawn_445243_guess*, 0x00905CE4)
#define g_controlSpawn_445243_guess EQ_GLOBAL(Spawn_445243_guess*, 0x00905CF8)
#define g_spawnHead_445243_guess EQ_GLOBAL(Spawn_445243_guess*, 0x00905CC4)
#define g_groundHead_445243_guess EQ_GLOBAL(GroundItem_445243_guess*, 0x00905CD0)
#define g_paused_445243_guess EQ_GLOBAL(int, 0x00905CA4)
#define g_modeIndex_445243_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_modeEntries_445243_guess EQ_ARRAY(ModeEntry_445243_guess*, 0x009254FC)
#define g_currentTarget_445243_guess EQ_GLOBAL(void*, 0x00850CC4)
#define g_groupActive_445243_guess EQ_GLOBAL(int, 0x00905CDC)
#define g_char_445243_guess EQ_GLOBAL(Char_445243_guess*, 0x00905D00)
#define g_target_445243_guess EQ_GLOBAL(Target_445243_guess*, 0x00905D04)
#define g_lastTargetId_445243_guess EQ_GLOBAL(int, 0x00850DA0)
#define g_gameState_445243_guess EQ_GLOBAL(unsigned char, 0x00923B88)
#define g_rateTable_445243_guess EQ_ARRAY(float, 0x0078F618)
#define g_cursor_445243_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_cursorShown_445243_guess EQ_GLOBAL(unsigned char, 0x00923844)
#define g_cursorMode_445243_guess EQ_GLOBAL(int, 0x00850508)
#define g_mouseX_445243_guess EQ_GLOBAL(int, 0x00923778)
#define g_mouseY_445243_guess EQ_GLOBAL(int, 0x0092377C)
#define g_effects_445243_guess EQ_GLOBAL(Effects_445243_guess*, 0x00985C88)
#define g_resources_445243_guess EQ_GLOBAL(Resources_445243_guess*, 0x00985CE4)
#define g_skyValue_445243_guess EQ_GLOBAL(int, 0x00924964)
#define g_skyStamp_445243_guess EQ_GLOBAL(unsigned char, 0x00698A14)
#define g_skyStampNow_445243_guess EQ_GLOBAL(unsigned char, 0x00923BBA)
#define g_skyZone_445243_guess EQ_GLOBAL(int, 0x00698A10)
#define g_skyZoneNow_445243_guess EQ_GLOBAL(int, 0x00924470)
#define g_skyBlend_445243_guess EQ_GLOBAL(float, 0x00923C7C)
#define g_pendingMode_445243_guess EQ_GLOBAL(int, 0x00923914)
#define g_pendingFlag_445243_guess EQ_GLOBAL(unsigned char, 0x00923D1C)
#define g_listenerX_445243_guess EQ_GLOBAL(float, 0x00985818)
#define g_listenerY_445243_guess EQ_GLOBAL(float, 0x00985828)
#define g_listenerZ_445243_guess EQ_GLOBAL(float, 0x00985838)

// One frame of the world: our movement, camera clip, movement of the other spawns, the character tick,
// light and sky, then the scene is drawn between BeginFrame and EndFrame.
// FUNCTION: TITANIUM 0x00445243
// @early-stop: signature, structural ndiff=67
// The frame: sound, camera, spawns, effects and sky, then the draw.
void CDisplay_guess::RealRender_World_guess() {
    state_0013_guess = 1;
    g_frameToggle_445243_guess ^= 1;
    g_particle_445243_guess->SetEnabled_guess(g_particleMode_445243_guess == 1);
    GetOffsetList_445243_guess()->FUN_004b6ae6_guess();
    GetFadeList_guess()->UpdateFades_guess();
    MoveMobileSoundEmitters_guess();
    UpdateIndoorSoundState_guess();
    g_cameraQueue_445243_guess->GetRoomType_guess();
    if (state_2d5c_guess == 0) {
        UpdateSoundEnvironment_guess();
    }
    if (g_localSpawn_445243_guess != 0) {
        Spawn_445243_guess* local = g_localSpawn_445243_guess;
        float z = local->position_0030_guess.z_0008_guess;
        float y = local->position_0030_guess.y_0004_guess;
        float x = local->position_0030_guess.x_0000_guess;
        g_cameraQueue_445243_guess->SetListenerLocation_guess(x, y, z,
            ((ClientView_445243_guess*)this)->camera_0118_guess->GetValue_guess());
    }
    g_cameraQueue_445243_guess->ProcessSound_guess();
    GetMessage_445243_guess()->NoOp_guess();
    GetWindow_445243_guess()->state_0009_guess = 0;
    frameTime_0148_guess = FUN_0046d655_guess();
    g_particle_445243_guess->SetPosition_guess(g_listenerX_445243_guess, g_listenerY_445243_guess,
        g_listenerZ_445243_guess);
    g_world_445243_guess->SetTime_guess(frameTime_0148_guess);
    ((StateOwner_guess*)this)->ProcessSwitches_guess();
    if (g_controlSpawn_445243_guess != 0) {
        g_controlSpawn_445243_guess->info_01a8_guess->time_0ebc_guess = frameTime_0148_guess;
    }
    g_localSpawn_445243_guess->UpdatePlayerVisibility_guess();
    // Movement (0x004BFE0F): the mount always, then, unless 0x905CA4 is set, the controlled spawn and
    // our own spawn when we control another.
    if (g_controlSpawn_445243_guess->info_01a8_guess != 0 &&
        g_controlSpawn_445243_guess->info_01a8_guess->mount_0158_guess != 0) {
        FUN_004bfe0f_guess(g_controlSpawn_445243_guess->info_01a8_guess->mount_0158_guess, 0, 0);
        ((Spawn_445243_guess*)g_controlSpawn_445243_guess->info_01a8_guess->mount_0158_guess)->MovePlayer_guess();
    }
    if (g_paused_445243_guess == 0) {
        FUN_004bfe0f_guess((EQPlayer*)g_controlSpawn_445243_guess, 0, 0);
        g_controlSpawn_445243_guess->MovePlayer_guess();
        if (g_localSpawn_445243_guess != g_controlSpawn_445243_guess) {
            FUN_004bfe0f_guess((EQPlayer*)g_localSpawn_445243_guess, 0, 0);
            g_localSpawn_445243_guess->MovePlayer_guess();
        }
    }
    // Every 250 ms the camera settings are reapplied and the far clip set to the camera distance
    // (at most 600).
    if (lastUpdateTime_0150_guess == 0 || (unsigned int)(frameTime_0148_guess - lastUpdateTime_0150_guess) > 0xfa) {
        lastUpdateTime_0150_guess = frameTime_0148_guess;
        CameraView_445243_guess* camera = ((ClientView_445243_guess*)this)->camera_0118_guess;
        camera->SetFirst_guess(buffer_011c_guess);
        ((ClientView_445243_guess*)this)->camera_0118_guess->SetSecond_guess(buffer_0120_guess);
        float distance = ((ClientView_445243_guess*)this)->camera_0118_guess->GetDistance_guess();
        if (distance > 600.0f) {
            distance = 600.0f;
        }
        g_world_445243_guess->SetClip_guess(buffer_011c_guess, distance, 1);
    }
    // Movement for the other spawns (ProcessPlayerPhysics_guess, 0x00436039; it skips us, the controlled
    // spawn and its mount, and spawns idle for 12 s): once for every spawn, then again for visible spawns
    // within 250 units (62500 = 250 squared) of the controlled one.
    g_world_445243_guess->ForEachPlayer_guess(ProcessPlayerPhysics_guess);
    if (g_controlSpawn_445243_guess != 0) {
        Vector3_guess* center = &g_controlSpawn_445243_guess->position_0030_guess;
        for (Spawn_445243_guess* spawn = g_spawnHead_445243_guess; spawn != 0; spawn = spawn->next_0214_guess) {
            if (spawn->info_01a8_guess != 0) {
                Visibility_445243_guess* visibility = spawn->GetVisibility_guess();
                if (visibility != 0 && !visibility->IsHidden_guess() &&
                    spawn->position_0030_guess.DistanceSquared_guess(center) < 62500.0f) {
                    ProcessPlayerPhysics_guess((EQPlayer*)spawn, 0);
                }
            }
        }
    }
    if (g_paused_445243_guess == 0 &&
        g_modeEntries_445243_guess[g_modeIndex_445243_guess]->state_0046_guess == 0) {
        ZoneAction_445243_guess* action = FindZoneAction_445243_guess(g_currentTarget_445243_guess);
        if (action != 0) {
            action->FUN_0056ffa8_guess();
        }
    } else {
        g_modeEntries_445243_guess[g_modeIndex_445243_guess]->state_0046_guess = 0;
    }
    GroundItem_445243_guess* item = g_groundHead_445243_guess;
    while (item != 0) {
        GroundItem_445243_guess* next = item->next_0008_guess;
        if (item->data_0048_guess->value_0000_guess == 0) {
            item->CreateActorWhenReady_guess();
            if (item->data_0048_guess->state_1005_guess == 1) {
                item->MissileTeardown_guess();
                delete item;
            }
        } else if ((unsigned int)(frameTime_0148_guess - item->data_0048_guess->time_0050_guess) >= 0x21) {
            item->TrackTarget_guess();
            FUN_004bfe0f_item_guess(0, item, 0);
            ((GroundOwner_445243_guess*)this)->MoveMissile_guess(item);
        }
        item = next;
    }
    if (g_groupActive_445243_guess != 0) {
        ((AngleMath_guess*)this)->ProcessEffects_guess();
    }
    if (g_paused_445243_guess == 0) {
        // The character tick (0x00422198: timers, regeneration, casting).
        g_char_445243_guess->part_c280_guess.DoPassageOfTime_guess();
    }
    Target_445243_guess* target = g_target_445243_guess;
    if (target != 0) {
        if (g_lastTargetId_445243_guess != 0 && g_lastTargetId_445243_guess != target->id_0258_guess) {
            Target_445243_guess* previous = FindTarget_445243_guess(g_lastTargetId_445243_guess);
            if (previous != 0) {
                previous->SetNameSpriteTint();
                target = g_target_445243_guess;
            }
            g_lastTargetId_445243_guess = 0;
        }
        target->SetNameSpriteTint();
        g_lastTargetId_445243_guess = g_target_445243_guess->id_0258_guess;
    } else if (g_lastTargetId_445243_guess != 0) {
        Target_445243_guess* previous = FindTarget_445243_guess(g_lastTargetId_445243_guess);
        if (previous != 0) {
            previous->SetNameSpriteTint();
        }
        g_lastTargetId_445243_guess = 0;
    }
    // Outdoor zone types 1, 2 and 5 (0x923B88) run the day cycle 0x00443C03; the others go straight to the
    // light and fog mix 0x00441295.
    unsigned char state = g_gameState_445243_guess;
    if (state == 2 || state == 1 || state == 5) {
        if (state_014c_guess != 0) {
            GetWindow_445243_guess()->UpdateWeather_guess();
        }
        ProcessSky_guess();
    } else {
        SetAmbientLight_guess(g_rateTable_445243_guess[state_0145_guess]);
    }
    _control87(0xa031f, 0xf031f);
    if (g_cursor_445243_guess != 0 && g_cursorShown_445243_guess != 0 &&
        g_cursorMode_445243_guess != 3 && g_cursorMode_445243_guess != 5) {
        DrawNetStatus(g_mouseX_445243_guess + 5, g_mouseY_445243_guess + 5, g_cursor_445243_guess, 0);
    }
    if (g_effects_445243_guess != 0) {
        g_effects_445243_guess->ProcessPath_guess(&g_localSpawn_445243_guess->position_0030_guess);
    }
    if (g_resources_445243_guess != 0) {
        g_resources_445243_guess->Process_guess(&g_localSpawn_445243_guess->position_0030_guess);
    }
    GetWindow_445243_guess()->FUN_004c38d5_guess();
    GetController_445243_guess()->Draw_guess();
    if (g_localSpawn_445243_guess != 0 && g_localSpawn_445243_guess->info_01a8_guess != 0 &&
        g_localSpawn_445243_guess->info_01a8_guess->model_0000_guess != 0) {
        g_localSpawn_445243_guess->info_01a8_guess->model_0000_guess->Update_guess();
    }
    if (state_2d2c_guess == 0) {
        if (g_sky_445243_guess != 0) {
            g_sky_445243_guess->Follow_guess(0);
        }
    } else {
        g_sky_445243_guess->Follow_guess(g_skyValue_445243_guess);
        g_world_445243_guess->SetSky_guess(g_sky_445243_guess);
        if (g_skyStamp_445243_guess != g_skyStampNow_445243_guess) {
            float blend;
            if (g_skyZone_445243_guess == g_skyZoneNow_445243_guess) {
                blend = g_skyBlend_445243_guess;
            } else {
                g_skyZone_445243_guess = g_skyZoneNow_445243_guess;
                blend = 0.0f;
            }
            g_sky_445243_guess->SetName_guess(g_nameBuffer_guess.text_0000_guess);
            g_sky_445243_guess->SetName2_guess(g_nameBuffer2_guess.text_0000_guess, blend);
            g_skyStamp_445243_guess = g_skyStampNow_445243_guess;
        }
    }
    g_render_445243_guess->BeginFrame_guess();
    if (g_localSpawn_445243_guess != 0 && g_localSpawn_445243_guess->info_01a8_guess != 0 &&
        g_localSpawn_445243_guess->info_01a8_guess->state_0154_guess != 0) {
        g_render_445243_guess->DrawExtra_guess();
    }
    if (g_pendingMode_445243_guess != -1) {
        SetRenderWindow_guess();
    }
    if (g_pendingFlag_445243_guess != 0) {
        CaptureScreenshot_guess();
        g_pendingFlag_445243_guess = 0;
    }
    g_render_445243_guess->EndFrame_guess();
    state_0013_guess = 0;
}
