// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 47: a hint from compare/tumap.py.
// Missiles (arrows, thrown items, spell bolts) and the /hail and say-to-NPC commands. EQMissile_guess,
// MotionObject_guess, AlertOwner_guess and CleanupOwner_guess are views of one missile object, kept in the
// list at 0x905CD0: +0x48 actor, +0x4C source and +0x50 target spawn ids, +0x5C spell id (weapon damage for
// non-spells), +0x63 type (9 = spell), +0x65 model name. Sent as is, it is EQEmu's Arrow_Struct (0x88 bytes).
#include <winsock2.h>
#include <windows.h>
#include <math.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/races.h"
#include "titanium/opcodes.h"

struct AlertRecord_guess {
    char unknown_00_guess[0x120];
    char textData_guess;
    char unknown_121_guess[0x3F];
    AlertRecord_guess *selected_guess; // 0x160
    char unknown_164_guess[0x44];
    AlertRecord_guess *replacement_guess; // 0x1A8
};

struct AlertPanel_guess {
    int activeId_guess;
    char unknown_04_guess[0x1000];
    char available_guess;
    char blocked_guess;
};

struct AlertOwner_guess {
    char unknown_00_guess[0x48];
    AlertPanel_guess *panel_guess;
    void *queryKey_guess;
    char unknown_50_guess[0x0C];
    void *window_guess;
    char unknown_60_guess[3];
    char type_guess;
    void ReportSentinel_guess(int recordId_guess, int unused_guess);
};

struct QueryResult_guess {
    char unknown_00_guess[0x0C];
    float value_guess; // 0x0C
    char unknown_10_guess[0x18];
    unsigned int delay_guess; // 0x28
    char unknown_2C_guess[0x154];
    unsigned char category_guess; // 0x180
    char unknown_181_guess[5];
    unsigned char sound_guess; // 0x186
    char unknown_187_guess;
    unsigned char state_guess; // 0x188
    // EXTERNAL: TITANIUM 0x0044E77B QueryResult_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int category_guess);
};

struct ValidationOwner_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 ValidationOwner_guess::Find_guess
    QueryResult_guess *Find_guess(void *window_guess);
};

struct StringManager_guess {
    char unknown_00_guess[0x17BB4];
    char text_17bb4_guess;
    // EXTERNAL: TITANIUM 0x00492EC2 StringManager_guess::GetRecordText_guess
    char *GetRecordText_guess(char *recordText_guess);
    // EXTERNAL: TITANIUM 0x004985EB StringManager_guess::send_chat_guess
    void send_chat_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x00492F68 StringManager_guess::DoPercentConvert_guess
    void DoPercentConvert_guess(char *buffer_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00497C5B StringManager_guess::SendNewText_guess
    void SendNewText_guess(int mode_guess, char *name_guess,
        const char *text_guess, int zero_guess);
};

struct CharacterBase_guess {
    // EXTERNAL: TITANIUM 0x004106A3 CharacterBase_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int arg1_guess, int arg2_guess, int arg3_guess, int arg4_guess);
};

struct CharacterPc_guess {
    char unknown_00_guess[0xC280];
    CharacterBase_guess base_guess;
};

#define g_charPc_guess EQ_GLOBAL(CharacterPc_guess *, 0x00905D00)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char *buffer_guess, int textId_guess,
    const char *recordText_guess, int zero1_guess, int zero2_guess,
    int zero3_guess, int zero4_guess, int zero5_guess, int zero6_guess,
    int zero7_guess, int zero8_guess);

// EXTERNAL: TITANIUM 0x00476167 CastRay
int __cdecl CastRay(AlertRecord_guess *record_guess, float y_guess,
    float x_guess, float z_guess);

// EXTERNAL: TITANIUM 0x0044D0D0 IsWindowAvailable_guess
char __cdecl IsWindowAvailable_guess(void *window_guess);
// EXTERNAL: TITANIUM 0x004798B7 FindRecord_guess
AlertRecord_guess *__cdecl FindRecord_guess(int recordId_guess);
// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char *destination_guess, const char *source_guess);
// EXTERNAL: TITANIUM 0x00464803 IsNearlyZero_guess
bool __cdecl IsNearlyZero_guess(float value_guess);

#define g_validationOwner_guess EQ_GLOBAL(ValidationOwner_guess *, 0x00985CC8)
#define g_specialRecord_guess EQ_GLOBAL(AlertRecord_guess *, 0x00905CE4)
#define g_targetPlayer_guess EQ_GLOBAL(EQPlayer *, 0x00905D04)
#define g_stringManager_guess EQ_GLOBAL(StringManager_guess *, 0x00988DF0)
struct ListNode_guess {
    ListNode_guess *prev_guess;      // 0x00
    ListNode_guess *next_guess;      // 0x04
    int unknown_08_guess;            // 0x08
    int unknown_0C_guess;            // 0x0C
    int unknown_10_guess;            // 0x10
    int unknown_14_guess;            // 0x14
    int key_guess;                   // 0x18
    char unknown_1C_guess[0x14];
    int unknown_30_guess;            // 0x30
    int handle_guess;                // 0x34
    void Remove_guess();
};

struct GroundItem_guess : ListNode_guess {
    float unknown_38_guess;          // 0x38
    float radius_guess;              // 0x3C
    float unknown_40_guess;          // 0x40
    float unknown_44_guess;          // 0x44
    float unknown_48_guess;          // 0x48
    float unknown_4C_guess;          // 0x4C
    char name_guess[32];             // 0x50
    GroundItem_guess();
};

struct SpawnedActor_guess;

struct Manager_guess {
    char unknown_00_guess[0x148];
    int currentTick_guess; // 0x148
    // EXTERNAL: TITANIUM 0x0043972A Manager_guess::CreateActor_guess
    SpawnedActor_guess *CreateActor_guess(const char *label_guess,
        float x_guess, float y_guess, float z_guess, float speed_guess,
        float heading_guess, float scale_guess, bool mode_guess, bool zero_guess);
    // EXTERNAL: TITANIUM 0x00439377 Manager_guess::CreateLightInstance_guess
    void *CreateLightInstance_guess(char option_guess, float zero_guess, float x_guess,
        float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x004392DE Manager_guess::Update_guess
    void Update_guess(void *window_guess);
    // EXTERNAL: TITANIUM 0x00439C41 Manager_guess::TrueDistance_guess
    float TrueDistance_guess(float x1_guess, float y1_guess, float z1_guess,
        float x2_guess, float y2_guess, float z2_guess, float zero_guess);
    // EXTERNAL: TITANIUM 0x00436628 Manager_guess::HeadingDiff_guess
    float HeadingDiff_guess(float current_guess, float target_guess,
        float *difference_guess);
    // EXTERNAL: TITANIUM 0x004365DB Manager_guess::FixHeading_guess
    float FixHeading_guess(float angle_guess);
    // EXTERNAL: TITANIUM 0x00439A46 Manager_guess::Release_guess
    void Release_guess(int handle_guess);
    // EXTERNAL: TITANIUM 0x00439F26 Manager_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float y_guess, float x_guess, float z_guess);
};

#define g_manager_guess EQ_GLOBAL(Manager_guess *, 0x00905D24)

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float x1_guess, float y1_guess,
    float x2_guess, float y2_guess);

#define g_motionFlag_guess EQ_GLOBAL(char, 0x00923798)

struct ListOwner_guess {
    ListNode_guess *Find_guess(int key_guess);
};

struct SearchValue_guess {
    int key_guess;
};

struct SearchNode_guess {
    int unknown_00_guess;
    int unknown_04_guess;
    SearchNode_guess *next_guess;
    char unknown_0C_guess[0x3C];
    SearchValue_guess *value_guess;
};

struct SearchOwner_guess {
    SearchNode_guess *Find_guess(int key_guess);
};

struct QueryTarget_guess {
    int id_guess;
};

struct QueryChild_guess {
    char unknown_00_guess[0x1A8];
    QueryTarget_guess *target_guess;
};

struct QueryMiddle_guess {
    int id_guess;
    char unknown_04_guess[0x4C];
    int tick_guess; // 0x50
    char unknown_54_guess[0x108];
    QueryChild_guess *child_guess;
};

struct QueryRoot_guess {
    char unknown_00_guess[0x30];
    float x_guess; // 0x30
    float y_guess; // 0x34
    float z_guess; // 0x38
    char unknown_3C_guess[0x16C];
    QueryMiddle_guess *middle_guess; // 0x1A8
    char unknown_1AC_guess[0xB4];
    int type_guess; // 0x260
    // EXTERNAL: TITANIUM 0x0047BF6C QueryRoot_guess::GetPosition_guess
    char GetPosition_guess(int zero_guess, float *position_guess);
};

struct SpawnedActor_guess {
    virtual void slot0_guess();
    virtual void slot1_guess();
    virtual void slot2_guess();
    virtual void Attach_guess(void *owner_guess);
    virtual void SetState_guess(int state_guess);
};

struct MotionState_guess {
    SpawnedActor_guess *actor_guess;
    void *auxiliary_guess; // 0x04
    char unknown_08_guess[0x48];
    unsigned int lastSpawnTime_guess; // 0x50
    char unknown_54_guess[0x14];
    unsigned int deadline_guess; // 0x68
    char unknown_6C_guess[0x30];
    char unknown_9C_guess;
    char unknown_9D_guess[0x47];
    unsigned int nextUpdate_guess; // 0xE4
    char unknown_E8_guess[0xEFC];
    QueryRoot_guess *query_guess; // 0xFE4
    EQPlayer *targetPlayer_guess; // 0xFE8
    float speed_guess; // 0xFEC
    float angle_guess; // 0xFF0
    float duration_guess; // 0xFF4
    char unknown_FF8_guess[0x0D];
    char failed_guess; // 0x1005
    char unknown_1006_guess[2];
    unsigned int lastUpdate_guess; // 0x1008
};

struct MotionObject_guess {
    char unknown_00_guess[0x10];
    float x_guess; // 0x10
    float y_guess; // 0x14
    float z_guess; // 0x18
    float velocityX_guess; // 0x1C
    float velocityY_guess; // 0x20
    float velocityZ_guess; // 0x24
    float speed_guess; // 0x28
    float scale_guess; // 0x2C
    float heading_guess; // 0x30
    char unknown_34_guess[8];
    float fallSpeed_guess; // 0x3C
    char unknown_40_guess[8];
    MotionState_guess *state_guess; // 0x48
    void *queryKey_guess; // 0x4C
    void *positionKey_guess; // 0x50
    char unknown_54_guess[8];
    void *window_guess; // 0x5C
    char option_guess; // 0x60
    char unknown_61_guess;
    char option2_guess; // 0x62
    char type_guess; // 0x63
    char unknown_64_guess;
    char label_guess[0x80]; // 0x65
    void TrackTarget_guess();
    void CreateActorWhenReady_guess();
};

struct RotationService_guess {
    virtual float slot0_guess();
    virtual float slot1_guess();
    virtual float Sin_guess(float angle_guess);
    virtual void slot3_guess();
    virtual void slot4_guess();
    virtual void slot5_guess();
    virtual float Angle_guess(float distance_guess, float height_guess,
        float *unused_guess);
};

#define g_rotationService_guess EQ_GLOBAL(RotationService_guess *, 0x0099E374)

struct CleanupOwner_guess {
    int unknown_00_guess;
    CleanupOwner_guess *prev_guess; // 0x04
    CleanupOwner_guess *next_guess; // 0x08
    int unknown_0C_guess;
    float x_guess; // 0x10
    float y_guess; // 0x14
    float z_guess; // 0x18
    float oldX_guess; // 0x1C
    float oldY_guess; // 0x20
    float oldZ_guess; // 0x24
    char unknown_28_guess[4];
    int unknown_2C_guess;
    int unknown_30_guess;
    char unknown_34_guess[0x14];
    struct CleanupPayload_guess *payload_guess; // 0x48
    short unknown_4C_guess;
    char unknown_4E_guess[0x0A];
    short unknown_58_guess;
    char unknown_5A_guess[2];
    int state_guess;
    char unknown_60_guess[3];
    char type_guess; // 0x63
    char category_guess; // 0x64
    // EXTERNAL: TITANIUM 0x0040CBD6 CleanupOwner_guess::Find_guess
    QueryResult_guess *Find_guess(int recordId_guess);
    void MissileTeardown_guess();
    void Cleanup_guess();
};

struct CleanupPayload_guess {
    int unknown_00_guess;
    char unknown_04_guess[0xFE0];
    int key_guess; // 0xFE4
    // EXTERNAL: TITANIUM 0x0048F4A4 CleanupPayload_guess::Release_guess
    void Release_guess();
};

struct AlertRoot_guess {
    char unknown_00_guess[0x48];
    void *window_guess; // 0x48
    CleanupOwner_guess *owner_guess; // 0x4C
};

struct CleanupSpecial_guess {
    char unknown_00_guess[0x30];
    float x_guess; // 0x30
    float y_guess; // 0x34
    float z_guess; // 0x38
    char unknown_3C_guess[0x21C];
    short recordId_guess; // 0x258
    // EXTERNAL: TITANIUM 0x0047F614 CleanupSpecial_guess::IWasHit_guess
    void IWasHit_guess(void *packet_guess);
};

#pragma pack(push, 1)
struct CleanupPacket_guess {
    short specialId_guess;
    short ownerId_guess;
    short ownerState_guess;
    int mode_guess;
    float value_guess;
    int unknown_14_guess;
    int unknown_18_guess;
    char ownerCategory_guess;
    short zero_17_guess;
    short zero_19_guess;
    short recordId_guess;
    char unknown_1D_guess;
    char zero_1E_guess;
};
#pragma pack(pop)

struct CleanupNode_guess {
    char unknown_00_guess[0x5C];
    CleanupNode_guess *next_guess;
    int unknown_60_guess;
    CleanupOwner_guess *owner_guess;
    // EXTERNAL: TITANIUM 0x004519E8 CleanupNode_guess::Unlink_guess
    void Unlink_guess();
};

#define g_listHead_guess EQ_GLOBAL(ListNode_guess *, 0x00905CCC)
#define g_searchHead_guess EQ_GLOBAL(SearchNode_guess *, 0x00905CD0)
#define g_searchOwner_guess EQ_GLOBAL(SearchOwner_guess *, 0x00905CD0)
#define g_alertSentinel_guess EQ_GLOBAL(int, 0x00850CC8)
#define g_cleanupHead_guess EQ_GLOBAL(CleanupNode_guess *, 0x00905CDC)
#define g_specialCleanup_guess EQ_GLOBAL(CleanupSpecial_guess *, 0x00905CE4)
#define g_alertRoot_guess EQ_GLOBAL(AlertRoot_guess *, 0x0092551C)
#define g_alertCriticalSection_guess EQ_ARRAY(CRITICAL_SECTION, 0x00900800)
#define g_alertHead_guess EQ_GLOBAL(CleanupOwner_guess *, 0x00905CD0)
#define g_alertCurrent_guess EQ_GLOBAL(CleanupOwner_guess *, 0x00905CFC)
#define g_alertMode_guess EQ_GLOBAL(int, 0x00850CCC)

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();
// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
QueryRoot_guess *__cdecl FUN_00401b28_guess(void *key_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void *memory_guess);

// EXTERNAL: TITANIUM 0x0049B260 DoSpellEffect_guess
void __cdecl DoSpellEffect_guess(int mode_guess, QueryResult_guess *result_guess,
    int key_guess, int zero_guess, void *position_guess, void *owner_guess,
    int record_guess);

// /hail: "Hail, %1" (0x331D) with the target's name when you can see it (CastRay), else plain "Hail"
// (0x331C); send_chat_guess's flag says which. Halflings, gnomes and dwarves are aimed at 1 unit higher.
// FUNCTION: TITANIUM 0x00476336
void __cdecl do_hail_guess()
{
    CopyText_guess(&g_stringManager_guess->text_17bb4_guess,
        pStringTable->getString(0x331c, 0));
    if (g_targetPlayer_guess != 0) {
        int race_guess = g_targetPlayer_guess->Race;
        float z_guess = g_targetPlayer_guess->Z;
        if (race_guess == Race_Halfling || race_guess == Race_Gnome || race_guess == Race_Dwarf) {
            z_guess += 1.0f;
        }
        float x_guess = g_targetPlayer_guess->X;
        unsigned int yBits_guess = *(unsigned int *)&g_targetPlayer_guess->Y;
        if (CastRay(g_specialRecord_guess, *(float *)&yBits_guess,
                x_guess, z_guess) != 0) {
            FormatText_guess(&g_stringManager_guess->text_17bb4_guess, 0x331d,
                g_stringManager_guess->GetRecordText_guess(
                    &g_targetPlayer_guess->Name[0]),
                0, 0, 0, 0, 0, 0, 0, 0);
            g_stringManager_guess->send_chat_guess(1);
        } else {
            g_stringManager_guess->send_chat_guess(0);
        }
    } else {
        g_stringManager_guess->send_chat_guess(0);
    }
    g_stringManager_guess->text_17bb4_guess = 0;
}

// Says `text_guess` to the targeted NPC (Type 1) when you can see it (SendNewText_guess channel 8) and
// echoes "You say, '%1'" (0x331E) unless SPA_VoiceGraft is on you; otherwise a plain send_chat_guess.
// The first argument is unused.
// FUNCTION: TITANIUM 0x00476411
void __cdecl SayToTarget_guess(int unused_guess, const char *text_guess)
{
    unsigned int yBits_guess;
    char textCopy_guess[4096];
    char message_guess[2144];

    CopyText_guess(&g_stringManager_guess->text_17bb4_guess, text_guess);
    if (g_targetPlayer_guess != 0 && g_targetPlayer_guess->Type == 1) {
        int race_guess = g_targetPlayer_guess->Race;
        float z_guess = g_targetPlayer_guess->Z;
        if (race_guess == Race_Halfling || race_guess == Race_Gnome || race_guess == Race_Dwarf) {
            z_guess += 1.0f;
        }
        float x_guess = g_targetPlayer_guess->X;
        yBits_guess = *(unsigned int *)&g_targetPlayer_guess->Y;
        if (CastRay(g_specialRecord_guess, *(float *)&yBits_guess,
                x_guess, z_guess) != 0) {
            g_stringManager_guess->SendNewText_guess(8, g_targetPlayer_guess->Name,
                &g_stringManager_guess->text_17bb4_guess, 0);
            if (g_charPc_guess->base_guess.TotalSpellAffects_guess(0x4b, 1, 0, 1) != 0) {
                return;
            }
            CopyText_guess(textCopy_guess, &g_stringManager_guess->text_17bb4_guess);
            g_stringManager_guess->DoPercentConvert_guess(textCopy_guess, 1);
            FormatText_guess(message_guess, 0x331e, textCopy_guess,
                0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0x133, true);
        } else {
            g_stringManager_guess->send_chat_guess(0);
        }
    } else {
        g_stringManager_guess->send_chat_guess(0);
    }
}

// The missile whose actor has id `key_guess`, or 0.
// FUNCTION: TITANIUM 0x0047656E
SearchNode_guess *SearchOwner_guess::Find_guess(int key_guess)
{
    SearchNode_guess *node_guess = g_searchHead_guess;
    while (node_guess != 0 && node_guess->value_guess->key_guess != key_guess) {
        node_guess = node_guess->next_guess;
    }
    return node_guess;
}

// Sentinel alarm: when a spell missile (type 9) whose spell has SPA_Sentinel meets spawn `recordId_guess`,
// prints "You have triggered your sentinel." (0x1A44) for you, else "%1 has triggered your sentinel."
// (0x1A45). A spawn with a rider (+0x1A8, +0x160) reports the rider. Only for a launched missile not
// yet stopped.
// FUNCTION: TITANIUM 0x0047658A
void AlertOwner_guess::ReportSentinel_guess(int recordId_guess, int unused_guess)
{
    char buffer_guess[128];
    if (recordId_guess != 0 && panel_guess->blocked_guess != 1 &&
        panel_guess->available_guess != 0 && type_guess == 9) {
        AlertRecord_guess *record_guess = FindRecord_guess(recordId_guess);
        if (record_guess != 0) {
            if (record_guess->replacement_guess != 0 &&
                record_guess->replacement_guess->selected_guess != 0) {
                record_guess = record_guess->replacement_guess->selected_guess;
            }
            if (IsWindowAvailable_guess(window_guess) != 0) {
                QueryResult_guess *query_guess = g_validationOwner_guess->Find_guess(window_guess);
                if (query_guess != 0 && query_guess->FindAffectSlot_guess(0x4C) != 0) {
                    if (record_guess == g_specialRecord_guess) {
                        const char *text_guess = pStringTable->getString(0x1A44, 0);
                        CopyText_guess(buffer_guess, text_guess);
                    } else {
                        FormatText_guess(buffer_guess, 0x1A45,
                            g_stringManager_guess->GetRecordText_guess(&record_guess->textData_guess),
                            0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    pEverQuest->dsp_chat(buffer_guess, 0x108, 1);
                }
            }
        }
    }
}

// Homing: turns a missile toward its target's middle. The aim is recomputed every 0 ms under 200 units, 250
// under 250, 500 under 350, else 1000; under 2 units the target is hit (ReportSentinel_guess) and the missile
// stops (+0x1005). Within 32 units heading and pitch snap; farther, heading turns by at most 16 per update.
// Pitch turns 16 at a time only when 16 or more off: a 1-16 difference is never closed. `state_guess` is used
// before its null test when 0x923798 is set (the target is then always pinstTarget).
// FUNCTION: TITANIUM 0x004766AA
// @early-stop: unknown, structural ndiff=277
void MotionObject_guess::TrackTarget_guess()
{
    float local8_guess;
    float localC_guess;
    float local10_guess;
    float local14_guess;
    float local18_guess;
    float local1C_guess;
    float local20_guess;
    float local24_guess;

    if (g_motionFlag_guess != 0) {
        state_guess->targetPlayer_guess = g_targetPlayer_guess;
    }

    MotionState_guess *state_guess = this->state_guess;
    if (state_guess != 0 && this->speed_guess != 0.0f &&
        state_guess->targetPlayer_guess != 0 &&
        state_guess->targetPlayer_guess->StandState != 'x') {
        EQPlayer *target_guess = state_guess->targetPlayer_guess;
        if (target_guess->SpawnID == (unsigned int)this->queryKey_guess &&
            g_motionFlag_guess == 0) {
            state_guess->targetPlayer_guess = 0;
        } else {
            int delay_guess;
            if (state_guess->duration_guess >= 200.0f) {
                // Always true here, so the 125 ms case is unreachable; kept as compiled.
                if (state_guess->duration_guess >= 150.0f) {
                    if (state_guess->duration_guess >= 250.0f) {
                        delay_guess = 500;
                        if (state_guess->duration_guess >= 350.0f) {
                            delay_guess = 1000;
                        }
                    } else {
                        delay_guess = 250;
                    }
                } else {
                    delay_guess = 125;
                }
            } else {
                delay_guess = 0;
                if (state_guess->duration_guess < 2.0f &&
                    target_guess->pActorInfo != 0) {
                    ((AlertOwner_guess *)this)->ReportSentinel_guess(
                        *(int *)target_guess->pActorInfo, 0);
                    this->state_guess->failed_guess = 1;
                    return;
                }
            }

            if ((unsigned int)delay_guess <
                (unsigned int)(g_manager_guess->currentTick_guess -
                    state_guess->nextUpdate_guess)) {
                float center_guess = target_guess->heightOffset_0238_guess * 0.5f +
                    target_guess->Z;
                float heightDifference_guess = center_guess - this->z_guess;
                float absoluteHeightDifference_guess = heightDifference_guess;
                if (heightDifference_guess < 0.0f) {
                    absoluteHeightDifference_guess = -heightDifference_guess;
                }

                state_guess->nextUpdate_guess = g_manager_guess->currentTick_guess;
                local14_guess = this->y_guess;
                local18_guess = this->x_guess;
                state_guess->speed_guess = get_bearing_guess(
                    local18_guess, local14_guess, target_guess->Y, target_guess->X);
                local18_guess = this->z_guess;
                local14_guess = this->y_guess;
                local1C_guess = this->x_guess;
                state_guess->duration_guess = g_manager_guess->TrueDistance_guess(
                    local1C_guess, local14_guess, local18_guess,
                    target_guess->Y, target_guess->X, center_guess, 0.0f);

                if (absoluteHeightDifference_guess <= 0.5f) {
                    state_guess->angle_guess = 0.0f;
                } else {
                    local1C_guess = 0.0f;
                    state_guess->angle_guess = 128.0f -
                        g_rotationService_guess->Angle_guess(
                            state_guess->duration_guess,
                            absoluteHeightDifference_guess,
                            &local1C_guess);
                    if (heightDifference_guess < 0.0f) {
                        state_guess->angle_guess = -state_guess->angle_guess;
                    }
                }
            }

            state_guess = this->state_guess;
            if (state_guess->duration_guess < 32.0f) {
                this->scale_guess = state_guess->speed_guess;
                this->fallSpeed_guess = state_guess->angle_guess;
            } else {
                local20_guess = 16.0f;
                local8_guess = g_manager_guess->HeadingDiff_guess(
                    this->scale_guess, state_guess->speed_guess, &local10_guess);
                localC_guess = g_manager_guess->HeadingDiff_guess(
                    this->fallSpeed_guess, state_guess->angle_guess, &local24_guess);
                if (local8_guess >= 1.0f) {
                    if (local8_guess < 16.0f) {
                        local20_guess = local8_guess;
                    }
                    if ((this->scale_guess < state_guess->speed_guess &&
                            local10_guess < 0.0f) ||
                        (state_guess->speed_guess < this->scale_guess &&
                            local10_guess > 0.0f)) {
                        this->scale_guess -= local20_guess;
                    } else {
                        this->scale_guess += local20_guess;
                    }
                    this->scale_guess = g_manager_guess->FixHeading_guess(
                        this->scale_guess);
                } else {
                    this->scale_guess = state_guess->speed_guess;
                }

                if (localC_guess >= 1.0f) {
                    if (localC_guess < 16.0f) {
                        return;
                    }
                    if (local24_guess < 0.0f ||
                        state_guess->angle_guess < this->fallSpeed_guess) {
                        this->fallSpeed_guess -= 16.0f;
                    } else {
                        this->fallSpeed_guess += 16.0f;
                    }
                    this->fallSpeed_guess = g_manager_guess->FixHeading_guess(
                        this->fallSpeed_guess);
                    return;
                }
                this->fallSpeed_guess = state_guess->angle_guess;
            }
        }
    }
}

// Creates the missile's actor once its launch time (+0x1008) has passed. Spell missiles live for the
// spell's +0x28 ms, else 30 s (spell byte +0x188 == 3) or 50 ms; others 120 s. Spells with target byte
// (+0x180) 8, 21-23 or 28 appear at the target and don't move; for the other spells the start point is
// advanced by the time since the source's +0x50 tick. Then DoSpellEffect_guess and the first update,
// 2 s later for spells, 500 ms for others. `state_guess` is read before its null test.
// FUNCTION: TITANIUM 0x00476B12
// @early-stop: budget, structural ndiff=216
void MotionObject_guess::CreateActorWhenReady_guess()
{
    MotionState_guess *state_guess = this->state_guess;
    if (FUN_0046d655_guess() < state_guess->lastUpdate_guess) {
        return;
    }
    if (state_guess == 0) {
        return;
    }

    int mode_guess = 1;
    QueryResult_guess *result_guess = 0;
    if (state_guess->query_guess == 0) {
        state_guess->query_guess = FUN_00401b28_guess(queryKey_guess);
        if (state_guess->query_guess == 0) {
            state_guess->failed_guess = 1;
            return;
        }
    }

    state_guess->deadline_guess = FUN_0046d655_guess() + 120000;
    if (type_guess == 9) {
        if (IsWindowAvailable_guess(window_guess) == 0) {
            state_guess->failed_guess = 1;
            return;
        }
        result_guess = g_validationOwner_guess->Find_guess(window_guess);
        if (result_guess == 0) {
            state_guess->failed_guess = 1;
            return;
        }

        if (result_guess->delay_guess > 0) {
            state_guess->deadline_guess = FUN_0046d655_guess() + result_guess->delay_guess;
        } else if (result_guess->state_guess == 3) {
            state_guess->deadline_guess = FUN_0046d655_guess() + 30000;
        } else {
            state_guess->deadline_guess = FUN_0046d655_guess() + 0x32;
        }

        unsigned char category_guess = result_guess->category_guess;
        if (category_guess == 8 ||
            (category_guess > 0x14 &&
             (category_guess < 0x18 || category_guess == 0x1C))) {
            QueryRoot_guess *position_guess = FUN_00401b28_guess(positionKey_guess);
            if (position_guess != 0) {
                x_guess = position_guess->x_guess;
                y_guess = position_guess->y_guess;
                z_guess = position_guess->z_guess;
            }
            mode_guess = 2;
            velocityX_guess = 0.0f;
            velocityY_guess = 0.0f;
            velocityZ_guess = 0.0f;
            speed_guess = 0.0f;
            state_guess->unknown_9C_guess = 0;
        } else {
            int elapsedTicks_guess = (int)FUN_0046d655_guess() -
                state_guess->query_guess->middle_guess->tick_guess;
            float elapsed_guess = (float)elapsedTicks_guess;
            if (elapsedTicks_guess < 0) {
                elapsed_guess += 4294967296.0f;
            }
            elapsed_guess *= 0.02f;

            if (state_guess->query_guess->type_guess == 0x31 ||
                state_guess->query_guess->type_guess == 0x9E ||
                state_guess->query_guess->type_guess == 0xC4) {
                float position_guess[3];
                if (state_guess->query_guess->GetPosition_guess(0, position_guess) == 1) {
                    x_guess = position_guess[0];
                    y_guess = position_guess[1];
                    z_guess = position_guess[2];
                    x_guess = velocityX_guess * 32.5f + x_guess;
                    y_guess = velocityY_guess * 32.5f + y_guess;
                    z_guess = z_guess - 12.0f;
                }
                float speed_guess = this->speed_guess;
                fallSpeed_guess = -72.0f;
                velocityZ_guess = g_rotationService_guess->Sin_guess(-72.0f) *
                    speed_guess + velocityZ_guess;
            }

            if (result_guess->state_guess != 3) {
                x_guess = velocityX_guess * 5.5f + x_guess;
                y_guess = velocityY_guess * 5.5f + y_guess;
                z_guess = velocityZ_guess * 5.5f + z_guess;
                x_guess = elapsed_guess * velocityX_guess + x_guess;
                y_guess = elapsed_guess * velocityY_guess + y_guess;
                elapsed_guess = elapsed_guess * velocityZ_guess;
                z_guess = elapsed_guess + z_guess;
            } else {
                velocityZ_guess = 0.0f;
            }
        }
    } else {
        x_guess = velocityX_guess + x_guess;
        y_guess = velocityY_guess + y_guess;
        z_guess = velocityZ_guess + z_guess;
    }

    float scale_guess = 1.0f;
    if (option2_guess == 0) {
        scale_guess = 1.5f;
        if (state_guess->query_guess->type_guess == 0x31 ||
            state_guess->query_guess->type_guess == 0x9E ||
            state_guess->query_guess->type_guess == 0xC4) {
            scale_guess = 20.5f;
        }
    } else if (state_guess->query_guess->type_guess == 0x31 ||
        state_guess->query_guess->type_guess == 0x9E ||
        state_guess->query_guess->type_guess == 0xC4) {
        scale_guess = 1.0f;
    }

    float renderX_guess = x_guess;
    float renderY_guess = y_guess;
    float renderZ_guess = z_guess;
    MotionState_guess *stateForActor_guess = state_guess;
    SpawnedActor_guess *actor_guess = g_manager_guess->CreateActor_guess(&label_guess[0],
        renderX_guess, renderY_guess, renderZ_guess, this->scale_guess,
        this->heading_guess, scale_guess, true, false);
    stateForActor_guess->actor_guess = actor_guess;
    if (actor_guess == 0) {
        stateForActor_guess->failed_guess = 1;
        return;
    }

    actor_guess->Attach_guess(this);
    actor_guess->SetState_guess(3);
    if (option_guess == 0) {
        stateForActor_guess->auxiliary_guess = 0;
    } else {
        stateForActor_guess->auxiliary_guess = g_manager_guess->CreateLightInstance_guess(option_guess,
            0.0f, x_guess, y_guess, z_guess);
    }

    if (result_guess != 0) {
        DoSpellEffect_guess(mode_guess, result_guess,
            (int)stateForActor_guess->query_guess, 0, 0, this,
            result_guess->delay_guess);
    }
    stateForActor_guess->speed_guess = this->scale_guess;
    stateForActor_guess->angle_guess = fallSpeed_guess;
    stateForActor_guess->duration_guess = 2000.0f;
    unsigned int now_guess = FUN_0046d655_guess();
    stateForActor_guess->lastSpawnTime_guess = now_guess;
    stateForActor_guess->nextUpdate_guess = stateForActor_guess->lastSpawnTime_guess;
    if (type_guess == 9) {
        stateForActor_guess->nextUpdate_guess += 2000;
    } else {
        stateForActor_guess->nextUpdate_guess += 500;
    }
}

struct Item47_guess {
    // EXTERNAL: TITANIUM 0x005E0540 Item47_guess::GetDamage_guess
    int GetDamage_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005EC850 Item47_guess::GetBonus_guess
    int GetBonus_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0770 Item47_guess::IsMagic_guess
    char IsMagic_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005ECC00 Item47_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0F00 Item47_guess::GetName_guess
    const char *GetName_guess();
    // EXTERNAL: TITANIUM 0x005E0130 Item47_guess::GetOption2_guess
    char GetOption2_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0D40 Item47_guess::GetOption_guess
    char GetOption_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Item47_guess::GetItemId_guess
    unsigned int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Item47_guess::GetSpell_guess
    int GetSpell_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0E90 Item47_guess::GetSkill_guess
    unsigned char GetSkill_guess();
};

struct CharInfo2_47_guess {
    char unknown_00_guess[0x3C];
    Item47_guess *ammo_guess; // 0x3C
    char unknown_40_guess[0x1164];
    int spellSkill_guess; // 0x11A4
};

struct CharacterPc1_47_guess : virtual EQ_Character {
    virtual void slot0_guess();
    EQPlayer *spawn_guess; // 0x08
    // EXTERNAL: TITANIUM 0x0041A877 CharacterPc1_47_guess::ApplyLevelDamageCap_guess
    void ApplyLevelDamageCap_guess(CharacterPc1_47_guess *self_guess, int *damage_guess,
        unsigned char skill_guess);
    // EXTERNAL: TITANIUM 0x0041EBB3 CharacterPc1_47_guess::GetSkill_guess
    int GetSkill_guess(unsigned char skill_guess);
};

struct SoundSet47_guess {
    virtual void slot0_guess();
    virtual void slot1_guess();
    virtual void Play_guess(int sound_guess, int one_guess, int zero_guess,
        float volume_guess, int flag_guess);
    virtual void slot3_guess();
    virtual void slot4_guess();
    virtual void slot5_guess();
    virtual void slot6_guess();
    virtual void slot7_guess();
    virtual void slot8_guess();
    virtual void slot9_guess();
    virtual void slot10_guess();
    virtual int Pick_guess(unsigned char skill_guess, unsigned char type_guess,
        unsigned char ranged_guess, float *volume_guess, int mode_guess);
};

struct EQMissile_guess;

struct Spawn47_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x00479D99 Spawn47_guess::GetSkillFor_guess
    unsigned char GetSkillFor_guess(unsigned char type_guess);
    // EXTERNAL: TITANIUM 0x004795BC Spawn47_guess::AimAtTarget_guess
    int AimAtTarget_guess(Spawn47_guess *target_guess, EQMissile_guess *projectile_guess);
    // EXTERNAL: TITANIUM 0x0047C08E Spawn47_guess::GetAnimation_guess
    SoundSet47_guess *GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x0047DDD4 Spawn47_guess::GetAnimationLength_guess
    unsigned int GetAnimationLength_guess(int sound_guess);
};

struct ActorInfo47_guess {
    int unknown_00_guess;
    char unknown_04_guess[0x44];
    float scale_guess; // 0x48
    char unknown_4C_guess[0x50];
    char unknown_9C_guess; // 0x9C
    char unknown_9D_guess[0xE83];
    int unknown_F20_guess; // 0xF20
    char unknown_F24_guess[0xC0];
    Spawn47_guess *source_guess; // 0xFE4
    Spawn47_guess *target_guess; // 0xFE8
    char unknown_FEC_guess[0x0C];
    float startY_guess; // 0xFF8
    float startX_guess; // 0xFFC
    float unknown_1000_guess; // 0x1000
    char launched_guess; // 0x1004
    char unknown_1005_guess[3];
    unsigned int arriveTime_guess; // 0x1008
    char unknown_100C_guess[0xB4];
    // EXTERNAL: TITANIUM 0x0048F023 ActorInfo47_guess::ActorInfo47_guess
    ActorInfo47_guess(const char *name_guess);
};

struct Motion47_guess {
    float y_guess; // 0x00
    float x_guess; // 0x04
    float z_guess; // 0x08
    float speedY_guess; // 0x0C
    float speedX_guess; // 0x10
    float speedZ_guess; // 0x14
    float speed_guess; // 0x18
    float heading_guess; // 0x1C
    float pitch_guess; // 0x20
    float pitchSpeed_guess; // 0x24
    float unknown_28_guess; // 0x28
    float unknown_2C_guess; // 0x2C
    char unknown_30_guess[8];
    Motion47_guess() { Reset_guess(); }
    // EXTERNAL: TITANIUM 0x004519AC Motion47_guess::Reset_guess
    void Reset_guess();
};

struct Trig47_guess {
    virtual float slot0_guess();
    virtual float slot1_guess();
    virtual float Sin_guess(float angle_guess);
    virtual float Cos_guess(float angle_guess);
};

struct SoundPacket47_guess {
    short spawnId_guess;
    unsigned char volume_guess;
    unsigned char sound_guess;
};

struct EQMissile_guess {
    unsigned char active_guess; // 0x00
    char unknown_01_guess[3];
    EQMissile_guess *prev_guess; // 0x04
    EQMissile_guess *next_guess; // 0x08
    int unknown_0C_guess;
    Motion47_guess motion_guess; // 0x10
    ActorInfo47_guess *actor_guess; // 0x48
    unsigned int sourceId_guess; // 0x4C
    unsigned int targetId_guess; // 0x50
    unsigned int flags_guess; // 0x54
    int skillValue_guess; // 0x58
    int spellId_guess; // 0x5C
    char option_guess; // 0x60
    char option2_guess; // 0x61
    unsigned char ranged_guess; // 0x62
    unsigned char type_guess; // 0x63
    unsigned char skill_guess; // 0x64
    char name_guess[0x23]; // 0x65
    EQMissile_guess(Item47_guess *item_guess, Spawn47_guess *source_guess,
        EQMissile_guess *copy_guess, const char *name_guess,
        unsigned char skill_guess, unsigned int targetId_guess);
};

// EXTERNAL: TITANIUM 0x00401B28 GetSpawn47_guess
Spawn47_guess *__cdecl GetSpawn47_guess(unsigned int id_guess);
struct Camera47_guess {
    // EXTERNAL: TITANIUM 0x005707B8 Camera47_guess::Follow_guess
    void Follow_guess(EQMissile_guess *projectile_guess);
};

#define g_camera47_guess EQ_GLOBAL(Camera47_guess *, 0x0092551C)

#define g_projectileHead47_guess EQ_GLOBAL(EQMissile_guess *, 0x00905CD0)
#define g_trig47_guess EQ_GLOBAL(Trig47_guess *, 0x0099E374)
#define g_connection47_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_localPlayer47_guess EQ_GLOBAL(Spawn47_guess *, 0x00905CE4)
#define g_noSound47_guess EQ_GLOBAL(char, 0x00923798)
#define g_soundMuted47_guess EQ_GLOBAL(int, 0x00923884)
#define g_playingSound47_guess EQ_GLOBAL(int, 0x0092446C)
#define g_followProjectile47_guess EQ_GLOBAL(char, 0x009858C6)

// Launches a missile from `source_guess`, or clones `copy_guess`. `skill_guess` is really the inventory slot:
// InvSlot_Range adds the ammo's damage (doubled for an NPC shooter), InvSlot_Primary/Secondary adjust melee
// damage. A range-slot shot leaves 1.5 units ahead and aims (0x4795BC); item types 27-28 fly level at
// speed 4, spells at 1.5 (0.8 for spell 859), the rest arc at 2.5. A fired shot is sent as message
// 0x4033 (not in opcodes.h; 0x88 bytes, the missile itself) unless 0x923798 is set or the spell has
// SPA_Sentinel; a non-range missile sends OP_Animation (spawn id, volume x10, sound). Your own arrows
// can take the camera (0x9858C6).
// FUNCTION: TITANIUM 0x00476F34
// @early-stop: budget, structural ndiff=203
EQMissile_guess::EQMissile_guess(Item47_guess *item_guess, Spawn47_guess *source_guess,
    EQMissile_guess *copy_guess, const char *name_guess,
    unsigned char skill_guess, unsigned int targetId_guess)
{
    int damage_guess = 0;
    int magic_guess = 0;
    int bonus_guess = 0;
    Spawn47_guess *target_guess = 0;
    EnterCriticalSection(g_alertCriticalSection_guess);
    // Push onto the head of the global missile list; the lock is held until the start position is
    // set, before the optional camera follow.
    if (g_projectileHead47_guess == 0) {
        g_projectileHead47_guess = this;
        next_guess = 0;
        prev_guess = 0;
    } else {
        g_projectileHead47_guess->prev_guess = this;
        next_guess = g_projectileHead47_guess;
        prev_guess = 0;
        g_projectileHead47_guess = this;
    }
    QueryResult_guess *found_guess = 0;
    active_guess = 1;
    CharacterPc1_47_guess *charInfo_guess;
    if (source_guess != 0) {
        charInfo_guess = (CharacterPc1_47_guess *)source_guess->pCharInfo;
        if (item_guess != 0) {
            damage_guess = item_guess->GetDamage_guess(1);
            bonus_guess = item_guess->GetBonus_guess(1);
            if (item_guess->IsMagic_guess(1)) {
                magic_guess = 1;
            }
            // Range slot (11): ammo of item type 5 or 6 adds its damage and bonus; an NPC shooter
            // (spawn type 1) doubles the damage.
            if (skill_guess == 0xB && charInfo_guess != 0) {
                if (((CharInfo2_47_guess *)charInfo_guess->GetCharInfo2())->ammo_guess != 0) {
                    Item47_guess *ammo_guess =
                        ((CharInfo2_47_guess *)charInfo_guess->GetCharInfo2())->ammo_guess;
                    if (ammo_guess->GetItemType_guess() == 5 || ammo_guess->GetItemType_guess() == 6) {
                        damage_guess += ammo_guess->GetDamage_guess(1);
                        bonus_guess += ammo_guess->GetBonus_guess(1);
                    }
                }
                if (charInfo_guess->spawn_guess != 0 && charInfo_guess->spawn_guess->Type == 1) {
                    damage_guess *= 2;
                }
            }
        } else {
            // No item: damage 2.
            damage_guess = 2;
        }
        if (item_guess != 0 && item_guess->GetItemType_guess() != 9 &&
            (skill_guess == 0xD || skill_guess == 0xE)) {
            // Primary (13) and secondary (14) slot items other than type 9 pass their damage through
            // the shooter's per-slot adjustment.
            charInfo_guess->ApplyLevelDamageCap_guess(charInfo_guess, &damage_guess, skill_guess);
        }
    } else {
        charInfo_guess = 0;
    }

    if (copy_guess != 0) {
        motion_guess.y_guess = copy_guess->motion_guess.y_guess;
        motion_guess.x_guess = copy_guess->motion_guess.x_guess;
        motion_guess.z_guess = copy_guess->motion_guess.z_guess;
        motion_guess.heading_guess = copy_guess->motion_guess.heading_guess;
        motion_guess.pitch_guess = copy_guess->motion_guess.pitch_guess;
        motion_guess.unknown_28_guess = copy_guess->motion_guess.unknown_28_guess;
        motion_guess.pitchSpeed_guess = copy_guess->motion_guess.pitchSpeed_guess;
        motion_guess.unknown_2C_guess = copy_guess->motion_guess.unknown_2C_guess;
        motion_guess.speed_guess = copy_guess->motion_guess.speed_guess;
        motion_guess.speedY_guess = copy_guess->motion_guess.speedY_guess;
        motion_guess.speedX_guess = copy_guess->motion_guess.speedX_guess;
        motion_guess.speedZ_guess = copy_guess->motion_guess.speedZ_guess;
        sourceId_guess = copy_guess->sourceId_guess;
        this->targetId_guess = copy_guess->targetId_guess;
        flags_guess = copy_guess->flags_guess;
        skillValue_guess = copy_guess->skillValue_guess;
        spellId_guess = copy_guess->spellId_guess;
        option_guess = copy_guess->option_guess;
        option2_guess = copy_guess->option2_guess;
        ranged_guess = copy_guess->ranged_guess;
        type_guess = copy_guess->type_guess;
        this->skill_guess = copy_guess->skill_guess;
        CopyText_guess(this->name_guess, copy_guess->name_guess);
        actor_guess = new ActorInfo47_guess(this->name_guess);
        actor_guess->source_guess = GetSpawn47_guess(copy_guess->sourceId_guess);
        actor_guess->target_guess = GetSpawn47_guess(copy_guess->targetId_guess);
        actor_guess->launched_guess = 0;
        // A clone is not sent again; its actor takes the floor height under it (-1e27 = no floor,
        // then 1.0).
        actor_guess->scale_guess = g_manager_guess->GetFloorHeight_guess(motion_guess.y_guess,
            motion_guess.x_guess, motion_guess.z_guess);
        if (actor_guess->scale_guess == -1e27f) {
            actor_guess->scale_guess = 1.0f;
        }
        actor_guess->unknown_F20_guess = 0;
        actor_guess->unknown_1000_guess = 0.0f;
        actor_guess->unknown_9C_guess = 0;
    } else {
        sourceId_guess = source_guess->SpawnID;
        this->targetId_guess = targetId_guess;
        if (targetId_guess > 0) {
            target_guess = GetSpawn47_guess(targetId_guess);
        }
        if (name_guess != 0) {
            CopyText_guess(this->name_guess, name_guess);
        } else {
            CopyText_guess(this->name_guess, item_guess->GetName_guess());
        }
        option2_guess = item_guess->GetOption2_guess(1);
        option_guess = item_guess->GetOption_guess();
        flags_guess = item_guess->GetItemId_guess();
        if (magic_guess != 0) {
            flags_guess |= 0x8000;
        }
        // The damage travels in the spell id field; a type 9 item (a spell) carries its spell
        // instead.
        spellId_guess = damage_guess;
        if (item_guess->GetItemType_guess() == 9) {
            spellId_guess = item_guess->GetSpell_guess(0);
        }
        if (skill_guess == 0xB) {
            ranged_guess = (unsigned char)bonus_guess;
            int itemType_guess = item_guess->GetItemType_guess();
            // Item types 0, 2 and 3 fired from the range slot fly as type 7.
            if (itemType_guess == 0 || (itemType_guess > 1 && itemType_guess <= 3)) {
                type_guess = 7;
            } else {
                type_guess = item_guess->GetItemType_guess();
            }
        } else {
            ranged_guess = 0;
            type_guess = item_guess->GetItemType_guess();
        }
        this->skill_guess = source_guess->GetSkillFor_guess(type_guess);
        if (type_guess == 9) {
            skillValue_guess =
                ((CharInfo2_47_guess *)charInfo_guess->GetCharInfo2())->spellSkill_guess;
        } else if (source_guess->pCharInfo != 0) {
            if (type_guess == 0x16) {
                this->skill_guess = item_guess->GetSkill_guess();
            }
            skillValue_guess = charInfo_guess->GetSkill_guess(this->skill_guess);
        } else {
            skillValue_guess = 0;
        }
        motion_guess.speedY_guess = source_guess->SpeedY;
        motion_guess.speedX_guess = source_guess->SpeedX;
        motion_guess.speedZ_guess = source_guess->SpeedZ;
        Motion47_guess *motion_ptr_guess = &motion_guess;
        motion_ptr_guess->y_guess = source_guess->Y;
        motion_ptr_guess->x_guess = source_guess->X;
        // Races 49, 158 and 196 launch from 2 above their origin, others from half their height
        // (+0x238). A ranged shot also starts 1.5 units ahead along the heading (below).
        if (source_guess->Race == 0x31 || source_guess->Race == 0x9E ||
            source_guess->Race == 0xC4) {
            motion_guess.z_guess = source_guess->Z + 2.0f;
        } else {
            motion_guess.z_guess = source_guess->Z + source_guess->heightOffset_0238_guess * 0.5f;
        }
        if (ranged_guess != 0 && source_guess->AimAtTarget_guess(target_guess, this) != 2) {
            motion_guess.heading_guess = source_guess->Heading;
            motion_guess.unknown_2C_guess = source_guess->CameraAngle;
            motion_guess.pitch_guess = source_guess->CameraAngle;
        }
        if (type_guess == 9 && IsWindowAvailable_guess((void *)spellId_guess)) {
            found_guess = g_validationOwner_guess->Find_guess((void *)spellId_guess);
            if (found_guess != 0 && target_guess != 0) {
                unsigned char category_guess = found_guess->category_guess;
                // Spells of category 8, 21, 22, 23 or 28 start on the target itself (and below get
                // no speed).
                if (category_guess == 8 || category_guess == 0x15 || category_guess == 0x1C ||
                    category_guess == 0x17 || category_guess == 0x16) {
                    motion_ptr_guess->y_guess = target_guess->Y;
                    motion_ptr_guess->x_guess = target_guess->X;
                    motion_ptr_guess->z_guess = target_guess->Z;
                }
            }
        }
        if (ranged_guess != 0) {
            motion_ptr_guess->y_guess +=
                g_trig47_guess->Cos_guess(motion_guess.heading_guess) * 1.5f;
            motion_ptr_guess->x_guess +=
                g_trig47_guess->Sin_guess(motion_guess.heading_guess) * 1.5f;
        }
        actor_guess = new ActorInfo47_guess(this->name_guess);
        actor_guess->target_guess = target_guess;
        actor_guess->source_guess = source_guess;
        actor_guess->launched_guess = 1;
        actor_guess->scale_guess = ((ActorInfo47_guess *)source_guess->pActorInfo)->scale_guess;
        motion_guess.unknown_28_guess = 0.0f;
        motion_guess.pitchSpeed_guess = 0.0f;
        bool send_guess = true;
        if (ranged_guess == 0) {
            // Speeds: non-ranged 1.0, spells 1.5 (spell 859: 0.8), item types 27-28 fly level at 4
            // (pitch +128), the rest arc down (pitch speed -20) at 2.5.
            motion_guess.speed_guess = 1.0f;
            actor_guess->unknown_1000_guess = 0.0f;
        } else if (type_guess == 9) {
            motion_guess.speed_guess = 1.5f;
            if (spellId_guess == 0x35B) {
                motion_guess.speed_guess = 0.8f;
            }
            actor_guess->unknown_1000_guess = 0.0f;
        } else if (type_guess > 0x1A && type_guess <= 0x1C) {
            motion_guess.pitch_guess += 128.0f;
            motion_guess.unknown_2C_guess = 1.0f;
            actor_guess->unknown_1000_guess = 0.0f;
            motion_guess.speed_guess = 4.0f;
        } else {
            motion_guess.pitchSpeed_guess = -20.0f;
            motion_guess.speed_guess = 2.5f;
            actor_guess->unknown_1000_guess = 0.0f;
        }
        actor_guess->unknown_9C_guess = 0;
        if (ranged_guess == 0 && (source_guess->Race == 0x31 || source_guess->Race == 0x9E ||
                source_guess->Race == 0xC4)) {
            // Non-ranged missiles of races 49, 158 and 196 take 3.5 times the source's velocity.
            motion_guess.speedY_guess *= 3.5f;
            motion_guess.speedX_guess *= 3.5f;
            motion_guess.speedZ_guess *= 3.5f;
        }
        if (type_guess == 9) {
            if (IsWindowAvailable_guess((void *)spellId_guess)) {
                found_guess = g_validationOwner_guess->Find_guess((void *)spellId_guess);
            }
            // Not sent: spells with SPA_Sentinel (76), and every non-ranged missile.
            if (found_guess != 0 && found_guess->FindAffectSlot_guess(0x4C)) {
                send_guess = false;
            }
        }
        if (ranged_guess == 0) {
            send_guess = false;
        }
        if (found_guess != 0) {
            unsigned char category_guess = found_guess->category_guess;
            if (category_guess == 8 || category_guess == 0x1C || category_guess == 0x15 ||
                category_guess == 0x17 || category_guess == 0x16) {
                motion_guess.speed_guess = 0.0f;
                motion_ptr_guess->speedY_guess = 0.0f;
                motion_ptr_guess->speedX_guess = 0.0f;
                motion_ptr_guess->speedZ_guess = 0.0f;
            }
        }
        if (g_noSound47_guess == 0 && send_guess) {
            EQSendMessage(&g_connection47_guess, 0x4033, this, 0x88, 1);
        }
    }

    if (fabs(motion_guess.speedY_guess) < 0.001f) {
        motion_guess.speedY_guess = 0.0f;
    }
    if (fabs(motion_guess.speedX_guess) < 0.001f) {
        motion_guess.speedX_guess = 0.0f;
    }
    if (fabs(motion_guess.speedZ_guess) < 0.001f) {
        motion_guess.speedZ_guess = 0.0f;
    }
    actor_guess->unknown_00_guess = 0;
    float volume_guess = 1.0f;
    int sound_guess = 0xFE;
    if (found_guess != 0) {
        sound_guess = found_guess->sound_guess;
    } else if (actor_guess->source_guess != 0) {
        SoundSet47_guess *sounds_guess = actor_guess->source_guess->GetAnimation_guess();
        if (sounds_guess != 0) {
            sound_guess = sounds_guess->Pick_guess(this->skill_guess, type_guess, ranged_guess,
                &volume_guess, 7);
        }
    }
    // Launch sound: the spell's, else one picked from the source's sound set; 0xFE and 0x4F are
    // none.
    if (sound_guess != 0xFE && sound_guess != 0x4F) {
        g_playingSound47_guess = 1;
        if (volume_guess < 0.001f) {
            volume_guess = 1.0f;
        }
        if (actor_guess != 0 && actor_guess->source_guess != 0) {
            actor_guess->source_guess->GetAnimation_guess()->Play_guess(sound_guess, 1, 0,
                volume_guess, 1);
        }
        g_playingSound47_guess = 0;
    }
    if (ranged_guess != 0) {
        g_playingSound47_guess = 1;
        unsigned int delay_guess;
        if (actor_guess != 0 && actor_guess->source_guess != 0) {
            delay_guess = (unsigned int)(
                actor_guess->source_guess->GetAnimationLength_guess(sound_guess) * 0.7);
        } else {
            delay_guess = 0;
        }
        if (delay_guess == 0) {
            delay_guess = 1500;
        }
        // A ranged shot is timed 70% into the shooter's animation for that sound (1500 ms if
        // unknown).
        actor_guess->arriveTime_guess = FUN_0046d655_guess() + delay_guess;
        g_playingSound47_guess = 0;
    } else if (actor_guess->launched_guess != 0 && g_noSound47_guess == 0 &&
        g_soundMuted47_guess == 0 && sound_guess != 0xFE && sound_guess != 0x4F) {
        SoundPacket47_guess packet_guess;
        packet_guess.spawnId_guess = (short)actor_guess->source_guess->SpawnID;
        packet_guess.sound_guess = (unsigned char)sound_guess;
        packet_guess.volume_guess = (unsigned char)(volume_guess * 10.0f);
        EQSendMessage(&g_connection47_guess, OP_Animation, &packet_guess, 4, 1);
    }
    ActorInfo47_guess *actor_ptr_guess = actor_guess;
    Spawn47_guess *start_guess = actor_ptr_guess->source_guess;
    if (start_guess == 0) {
        actor_ptr_guess->startY_guess = motion_guess.y_guess;
        actor_ptr_guess->startX_guess = motion_guess.x_guess;
    } else {
        actor_ptr_guess->startY_guess = start_guess->Y;
        actor_ptr_guess->startX_guess = start_guess->X;
    }
    LeaveCriticalSection(g_alertCriticalSection_guess);
    // The local player's own type 27 shot takes the camera when the follow option is on and the view
    // mode is not 8.
    if (g_followProjectile47_guess != 0 && type_guess == 0x1B && g_alertMode_guess != 8 &&
        actor_guess->source_guess == g_localPlayer47_guess) {
        g_manager_guess->Update_guess((void *)8);
        g_camera47_guess->Follow_guess(this);
    }
}

// Unlinks the node from the list at 0x905CCC and deletes its actor (+0x34).
// FUNCTION: TITANIUM 0x00477B4B
void ListNode_guess::Remove_guess()
{
    ListNode_guess *prev = prev_guess;
    ListNode_guess *next = next_guess;
    if (prev != 0) {
        if (next != 0) {
            this->prev_guess->next_guess = this->next_guess;
            this->next_guess->prev_guess = this->prev_guess;
        }
    } else if (next != 0) {
        this->next_guess->prev_guess = 0;
        g_listHead_guess = this->next_guess;
    }
    if (next == 0) {
        if (this->prev_guess != 0) {
            this->prev_guess->next_guess = 0;
        } else {
            this->next_guess = 0;
            this->prev_guess = 0;
            g_listHead_guess = 0;
        }
    }
    if (handle_guess != 0) {
        g_manager_guess->Release_guess(handle_guess);
    }
}

// The node in the 0x905CCC list with key +0x18 == `key_guess`, or 0.
// FUNCTION: TITANIUM 0x00477BA0
ListNode_guess *ListOwner_guess::Find_guess(int key_guess)
{
    ListNode_guess *node_guess = g_listHead_guess;
    while (node_guess != 0 && node_guess->key_guess != key_guess) {
        node_guess = node_guess->next_guess;
    }
    return node_guess;
}

struct Vector3_47_guess {
    float x_guess; // 0x0
    float y_guess; // 0x4
    float z_guess; // 0x8
    bool IsZero_guess();
};

// True when all three components are nearly zero (0x464803).
// FUNCTION: TITANIUM 0x00477BBA
bool Vector3_47_guess::IsZero_guess()
{
    return IsNearlyZero_guess(x_guess) && IsNearlyZero_guess(y_guess) &&
        IsNearlyZero_guess(z_guess);
}

// Collision filter during a missile's flight: actor `candidate_guess` counts as a hit unless it is
// 0x850CC8, the missile's own actor, its source's actor or that actor's child, or another missile.
// A hit is reported (sentinel) and stops the missile; 1 = hit or no missile.
// FUNCTION: TITANIUM 0x00477BF8
int __cdecl CheckMissileHit_guess(int candidate_guess, AlertOwner_guess *owner_guess)
{
    int result_guess = 0;
    int secondaryId_guess = 0;
    if (owner_guess == 0) {
        return 1;
    } else if (candidate_guess != g_alertSentinel_guess &&
        candidate_guess != owner_guess->panel_guess->activeId_guess) {
        int primaryId_guess;
        QueryRoot_guess *root_guess = FUN_00401b28_guess(owner_guess->queryKey_guess);
        if (root_guess != 0) {
            QueryMiddle_guess *middle_guess = root_guess->middle_guess;
            primaryId_guess = middle_guess->id_guess;
            if (root_guess->middle_guess != 0 && middle_guess->child_guess != 0 &&
                middle_guess->child_guess->target_guess != 0) {
                secondaryId_guess = middle_guess->child_guess->target_guess->id_guess;
            }
        } else {
            primaryId_guess = 0;
        }
        if (candidate_guess != primaryId_guess && candidate_guess != secondaryId_guess &&
            g_searchOwner_guess->Find_guess(candidate_guess) == 0) {
            result_guess = 1;
            owner_guess->ReportSentinel_guess(candidate_guess, 0);
            owner_guess->panel_guess->blocked_guess = 1;
        }
    }
    return result_guess;
}

// Drops the 0x905CDC list's nodes that point at this missile; for spell 859 (0x35B) the node is kept and
// only forgets it.
// FUNCTION: TITANIUM 0x00476AD4
void __fastcall Cleanup_guess(CleanupOwner_guess *owner_guess)
{
    CleanupNode_guess *node_guess = g_cleanupHead_guess;
    if (node_guess != 0) {
        do {
            CleanupNode_guess *next_guess = node_guess->next_guess;
            if (owner_guess == node_guess->owner_guess) {
                if (owner_guess->state_guess == 0x35B) {
                    node_guess->owner_guess = 0;
                } else {
                    node_guess->Unlink_guess();
                    free(node_guess);
                }
            }
            node_guess = next_guess;
        } while (node_guess != 0);
    }
}

// Missile teardown, under the missile lock (0x900800): unlinks it, gives back a camera that followed it,
// then for spells: spell 54 casts its effect where it stopped (DoSpellEffect_guess); spell 859 hits
// the local player within 40 units (IWasHit_guess, type 10). Then the actor is released.
// FUNCTION: TITANIUM 0x0047789D
// @early-stop: budget, structural ndiff=180
void CleanupOwner_guess::MissileTeardown_guess()
{
    EnterCriticalSection(g_alertCriticalSection_guess);

    CleanupOwner_guess *previous_guess = prev_guess;
    CleanupOwner_guess *nextNode_guess = this->next_guess;
    if (previous_guess != 0) {
        if (nextNode_guess != 0) {
            previous_guess->next_guess = nextNode_guess;
            nextNode_guess->prev_guess = previous_guess;
        } else {
            previous_guess->next_guess = 0;
        }
    } else if (nextNode_guess != 0) {
        nextNode_guess->prev_guess = 0;
        g_alertHead_guess = nextNode_guess;
    } else {
        this->next_guess = 0;
        this->prev_guess = 0;
        g_alertHead_guess = 0;
    }

    if (g_alertMode_guess == 8 && g_alertRoot_guess->owner_guess == this) {
        g_manager_guess->Update_guess(g_alertRoot_guess->window_guess);
    }
    if (this == g_alertCurrent_guess) {
        g_alertCurrent_guess = 0;
    }

    if (type_guess == 9 && payload_guess->unknown_00_guess != 0) {
        ::Cleanup_guess(this);
        if (state_guess == 0x36) {
            x_guess -= oldX_guess;
            y_guess -= oldY_guess;
            z_guess -= oldZ_guess;
            float position_guess[3];
            position_guess[0] = x_guess;
            position_guess[1] = y_guess;
            position_guess[2] = z_guess;
            DoSpellEffect_guess(2,
                g_validationOwner_guess->Find_guess((void *)state_guess),
                payload_guess->key_guess, 0, position_guess, 0, 0);
        } else if (state_guess == 0x35B) {
            float ownerX_guess = x_guess;
            float ownerY_guess = y_guess;
            float ownerZ_guess = z_guess;
            float specialX_guess = g_specialCleanup_guess->x_guess;
            float distance_guess = g_manager_guess->TrueDistance_guess(ownerX_guess, ownerY_guess,
                ownerZ_guess, specialX_guess, g_specialCleanup_guess->y_guess,
                g_specialCleanup_guess->z_guess, 0.0f);
            if (distance_guess <= 40.0f) {
                CleanupPacket_guess packet_guess;
                packet_guess.specialId_guess = g_specialCleanup_guess->recordId_guess;
                packet_guess.ownerId_guess = unknown_4C_guess;
                packet_guess.ownerState_guess = unknown_58_guess;
                packet_guess.recordId_guess = (short)state_guess;
                packet_guess.ownerCategory_guess = category_guess;
                packet_guess.zero_1E_guess = 0;
                packet_guess.mode_guess = 10;
                QueryResult_guess *result_guess =
                    g_validationOwner_guess->Find_guess((void *)state_guess);
                packet_guess.value_guess = result_guess == 0 ? 0.0f : result_guess->value_guess;
                packet_guess.unknown_14_guess = unknown_2C_guess;
                packet_guess.unknown_18_guess = unknown_30_guess;
                packet_guess.zero_17_guess = 0;
                packet_guess.zero_19_guess = 0;
                g_specialCleanup_guess->IWasHit_guess(&packet_guess);
            }
        }
    }

    CleanupPayload_guess *payload_guess_local = payload_guess;
    if (payload_guess_local != 0) {
        payload_guess_local->Release_guess();
        delete payload_guess_local;
        payload_guess = 0;
    }
    LeaveCriticalSection(g_alertCriticalSection_guess);
}

// Adds a node to the 0x905CCC list with the default model SWORD_ACTORDEF and radius 20; probably the
// ground-item list.
// FUNCTION: TITANIUM 0x00477AD3
GroundItem_guess::GroundItem_guess()
{
    if (g_listHead_guess == 0) {
        g_listHead_guess = this;
        next_guess = 0;
        prev_guess = 0;
    } else {
        g_listHead_guess->prev_guess = this;
        next_guess = g_listHead_guess;
        prev_guess = 0;
        g_listHead_guess = this;
    }
    unknown_38_guess = 0.0f;
    radius_guess = 20.0f;
    unknown_40_guess = 0.0f;
    unknown_44_guess = 0.0f;
    unknown_48_guess = 0.0f;
    unknown_4C_guess = 0.0f;
    CopyText_guess(name_guess, "SWORD_ACTORDEF");
    unknown_14_guess = 0;
    unknown_10_guess = 0;
    unknown_0C_guess = 0;
    unknown_08_guess = 0;
    key_guess = 0;
    unknown_30_guess = 0;
    handle_guess = 0;
}

