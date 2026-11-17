// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 82: a hint from compare/tumap.py.
// The find-path trail ("PlayerPath"): one object at 0x985C88 seen through many per-TU views
// (PlayerPathView_guess, PathFollower_guess, SweepTrack_guess, CallbackBatch_guess, EmitterSystem_guess ...).
// It requests a path to a spawn, snaps the reply to the floor and draws it with SpellEffects\Path.ini
// settings, particles and a sound. EqSoundManagerView_guess is EqSoundManager (0x851390), WavePlay_guess WavePlay.
#include <winsock2.h>
#include <windows.h>
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <new>
#include <math.h>

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x00612670 FloatOperation_guess
double __cdecl FloatOperation_guess(double first_guess, double second_guess);

struct TableView_guess {
    int count_0000_guess;
    int unknown04_guess;
    unsigned int mask_guess;
    int shift_guess;
    int* values_guess;

    // EXTERNAL: TITANIUM 0x004B73EE TableView_guess::Clear_guess
    void Clear_guess();
    int Lookup_guess(int index_guess);
};

struct VectorOwner_guess {
    int unknown00_guess;
    struct VectorData_guess* data_guess;
    int unknown08_guess;

    void Clear_guess();
    void Thunk_guess();
};

struct VectorData_guess {
    // EXTERNAL: TITANIUM 0x004056CE VectorData_guess::VectorDeletingDestructor_guess
    void VectorDeletingDestructor_guess(unsigned int flags_guess);
};

struct EqSoundManagerView_guess;

struct EqMobileEmitter_guess {
    struct Target_guess* target_guess;
    EqSoundManagerView_guess* controller_guess;

    // EXTERNAL: TITANIUM 0x0044A9E2 EqMobileEmitter_guess::EqMobileEmitter_guess
    EqMobileEmitter_guess(EqSoundManagerView_guess* controller_guess_arg);
    // EXTERNAL: TITANIUM 0x0044AACB EqMobileEmitter_guess::Open_guess
    void Open_guess(void* owner_guess, const char* name_guess);
};

struct Target_guess {
    char unknown00_guess[0x08];
    int unknown08_guess;
    char unknown0c_guess[0x0c];
    int unknown18_guess;
    int unknown1c_guess;
    int unknown20_guess;
    char unknown24_guess[0x0c];
    int unknown30_guess;
    int unknown34_guess;
    char unknown38_guess[0x04];
    int unknown3c_guess;
    int unknown40_guess;
    int unknown44_guess;

    // EXTERNAL: TITANIUM 0x004C5E40 Target_guess::SetEnabled_guess
    void SetEnabled_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0044AA9C Target_guess::SetPosition_guess
    void SetPosition_guess(float x_guess, float y_guess, float z_guess);
};

struct IndexedVector_guess {
    int count_guess;
    int unknown04_guess;
    int unknown08_guess;

    // EXTERNAL: TITANIUM 0x004EB924 IndexedVector_guess::Get_guess
    int* Get_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0050319B IndexedVector_guess::Insert_guess
    void Insert_guess(int index_guess, const int* value_guess);
    // EXTERNAL: TITANIUM 0x0050F3F6 IndexedVector_guess::Finish_guess
    void Finish_guess();
};

struct CleanupBuffer_guess {
    // EXTERNAL: TITANIUM 0x0044AA7A CleanupBuffer_guess::Cleanup_guess
    void Cleanup_guess();
};

struct GlobalDispatcher_guess {
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
    virtual void Dispatch_guess(int value_guess);
};

#define g_dispatcher_guess EQ_GLOBAL(GlobalDispatcher_guess*, 0x0099E360)

struct EQPlayerView_guess {
    char unknown000_guess[0x30];
    int unknown030_guess;
    int unknown034_guess;
    int unknown038_guess;
    char unknown03c_guess[0x1fc];
    float heightOffset_0238_guess;
    char unknown23c_guess[0x1a];
    unsigned char flag256_guess;
};

struct MessagePayload_guess {
    unsigned short message_guess;
    int unknown004_guess;
    int unknown008_guess;
    int unknown00c_guess;
};

struct MessageState_guess {
    unsigned char state_guess;
    char unknown001_guess[0x13];
    unsigned char pending_guess;
    char unknown015_guess[3];
    unsigned short message_guess;
    char unknown01a_guess[2];
    unsigned int lastTick_guess;

    void SendFindPersonRequest_guess();
    void ResendFindRequest_guess();
};

typedef unsigned int (__cdecl *GetTickCountFunction_guess)();

#define g_connectionConfig_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)
#define g_messageBuffer_guess EQ_ARRAY(char, 0x00905CA0)
#define g_getTickCount_guess EQ_GLOBAL(GetTickCountFunction_guess, 0x0063F180)

struct TargetTable_guess {
    char unknown000_guess[0x58];
    int unknown58_guess;
    int unknown5c_guess;
    char unknown060_guess[0x38c];
    struct EqMobileEmitter_guess* entries_guess[1];
    char unknown3f0_guess[0x0c];
    int unknown3fc_guess;

    void Dispatch_guess(int index_guess, int value_guess);
    void Open_guess(int index_guess, void* owner_guess, int value_guess);
    void OpenPlayerPath_guess();
};

#include "titanium/layouts/shared_classes.h"

struct EmitterFactoryView_guess {
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
    virtual void Dispatch_guess(int value_guess);
};

struct CleanupInterface_guess {
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
};

struct CleanupTable_guess {
    unsigned char state_guess;
    char unknown001_guess[0x113];
    CleanupInterface_guess* interface_guess;
    char unknown118_guess[0x54];
    int entries_guess[123];
    unsigned int count_guess;

    void ReleaseEmitters_guess();
    void Reset_guess();
    void Cancel_guess();
};

struct Vector3_guess;

struct Callback_guess {
    virtual void Slot00_guess(Vector3_guess* position_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess(float value_guess);
};

struct CallbackRow_guess {
    Callback_guess* entries_guess[4];
    float threshold_guess;      // 0x10
    unsigned int lastTick_guess; // 0x14
};

struct InlineArray_guess {
    char unknown000_guess[0x28];

    // EXTERNAL: TITANIUM 0x0047C3AF InlineArray_guess::Initialize_guess
    void Initialize_guess(int count_guess);
};

struct SmallState_guess {
    int values_guess[3];
    unsigned char enabled_guess;
    char unknown00d_guess[3];
};

struct CallbackBatch_guess {
    unsigned char unknown000_guess;
    char unknown001_guess[3];
    int unknown004_guess;
    char unknown008_guess[4];
    unsigned int elapsed_guess; // 0x0c
    char unknown010_guess[4];
    unsigned char unknown014_guess;
    unsigned char unknown015_guess;
    char unknown016_guess[2];
    int unknown018_guess;
    char unknown01c_guess[0x34];
    float unknown050_guess;
    unsigned char unknown054_guess;
    char unknown055_guess[3];
    FloatRange_guess range058_guess;
    FloatRange_guess range06c_guess;
    char unknown080_guess[0x14];
    FloatRange_guess range094_guess;
    float unknown0a8_guess;
    float unknown0ac_guess;
    char unknown0b0_guess[0x3c];
    float unknown0ec_guess;
    float unknown0f0_guess;
    float unknown0f4_guess;
    float unknown0f8_guess;
    float current_guess; // 0xfc
    char unknown100_guess[0x0c];
    float unknown10c_guess;
    char unknown110_guess[4];
    int unknown114_guess;
    InlineArray_guess array118_guess;
    SmallState_guess state140_guess;
    char unknown150_guess[0x0c];
    float unknown15c_guess;
    float unknown160_guess;
    float unknown164_guess;
    unsigned char unknown168_guess;
    char unknown169_guess[3];
    CallbackRow_guess rows_guess[20];
    float base_guess; // 0x34c
    float scale_guess; // 0x350
    unsigned int interval_guess; // 0x354
    unsigned int count_guess; // 0x358
    unsigned int unknown35c_guess; // 0x35c
    unsigned int capacity_guess; // 0x360
    unsigned int lastTick_guess; // 0x364
    char unknown368_guess[4];
    int definition_guess[4]; // 0x36c
    char unknown37c_guess[0x10];
    int lifeSpan_guess[4]; // 0x38c
    float density_guess[4]; // 0x39c
    float opacity_guess[4]; // 0x3ac
    char unknown3bc_guess[0x30];
    int unknown3ec_guess;

    CallbackBatch_guess();
    void SpawnEmitterRows_guess();
    void HideEmittersBeyond_guess(float value_guess);
    void HideAllEmitters_guess();
};

struct Vector3_guess {
    float x_guess;
    float y_guess;
    float z_guess;

    // EXTERNAL: TITANIUM 0x00435B55 Vector3_guess::Distance_guess
    float Distance_guess(const Vector3_guess* other_guess);
    // EXTERNAL: TITANIUM 0x00477C8F Vector3_guess::ScaleInto_guess
    Vector3_guess* ScaleInto_guess(Vector3_guess* output_guess, float scale_guess);

    // EXTERNAL: TITANIUM 0x0046482C Vector3_guess::Scale_guess
    void Scale_guess(float value_guess);
    void Normalize_guess();
};

// EXTERNAL: TITANIUM 0x00610884 Sqrt_guess
double __cdecl Sqrt_guess(double value_guess);

struct PositionTable_guess {
    char unknown000_guess[0x3ec];
    Target_guess* entries_guess[1];

    void DispatchPosition_guess(int index_guess, Vector3_guess* position_guess);
};

#define g_cleanupDispatcher_guess EQ_GLOBAL(EmitterFactoryView_guess*, 0x0099E36C)

#define g_targetTable_guess EQ_GLOBAL(TargetTable_guess*, 0x00985C88)

struct EqSoundManagerView_guess {
    // EXTERNAL: TITANIUM 0x0044A537 EqSoundManagerView_guess::WavePlay_guess
    void WavePlay_guess(int message_guess, int value_guess);
};

#define g_controller_guess EQ_GLOBAL(EqSoundManagerView_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z

struct CollectionInterface_guess {
    virtual void Slot00_guess();
};

// Chunked table at +0x118; its dtor is 0x004B73EE (landed in tu_077_ItemMoveQueue.cpp, symbol mapped in crt_defaults.json).
struct DialogTable_guess {
    int count;
    int chunkSize;
    unsigned mask;
    int shift;
    int** buckets;
    int chunkCount;
    char enabled;
    char pad19[7];

    ~DialogTable_guess();
};

struct OwnedVector_guess : IndexedVector_guess {
    ~OwnedVector_guess();
};

struct Collection_guess {
    char unknown000_guess[0x114];
    CollectionInterface_guess* interface_guess;
    DialogTable_guess table_guess;      // 0x118
    char unknown138_guess[8];
    OwnedVector_guess entries_guess;    // 0x140
    char unknown14c_guess[0x2a0];
    int buffer_guess;

    ~Collection_guess();
    void Release_guess();
    void Process_guess();
};

// 0x004B73EE: body kept visible so 0x004C1899 sees it as nothrow (delete[] only).
DialogTable_guess::~DialogTable_guess()
{
    for (int i = 0; i < chunkCount; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
    buckets = 0;
    chunkCount = 0;
    count = 0;
}

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text_guess, const char* format_guess, ...);

struct EmitterSource_guess {
    // EXTERNAL: TITANIUM 0x005751E0 EmitterSource_guess::Read_guess
    void Read_guess(const char* key_guess, CXStr* value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00575070 EmitterSource_guess::GetInt_guess
    int GetInt_guess(const char* key_guess, int default_guess, const char* value_guess);
    // EXTERNAL: TITANIUM 0x00575140 EmitterSource_guess::GetFloat_guess
    float GetFloat_guess(const char* key_guess, float default_guess, const char* value_guess);
};

struct EmitterTable_guess {
    char unknown000_guess[0x36c];
    int definition_guess[8];    // 0x36C
    int lifeSpan_guess[4];      // 0x38C
    float density_guess[4];     // 0x39C
    float opacity_guess[4];     // 0x3AC

    void LoadEmitter_guess(EmitterSource_guess* source_guess, int index_guess);
};

// fmodf: the float wrapper of fmod (0x612670).
// FUNCTION: TITANIUM 0x004C0ADC
double __cdecl fmodf_guess(float first_guess, float second_guess)
{
    return FloatOperation_guess((double)first_guess, (double)second_guess);
}

// Stores the two distances in order (low, high), with their squares and the span high - low, so range
// tests can compare squared distances.
// FUNCTION: TITANIUM 0x004C0AF7
void FloatRange_guess::Set_guess(float first_guess, float second_guess)
{
    if (first_guess < second_guess) {
        this->low_guess = first_guess;
        this->high_guess = second_guess;
    } else {
        this->high_guess = first_guess;
        this->low_guess = second_guess;
    }
    this->low_square_guess = this->low_guess * this->low_guess;
    this->high_square_guess = this->high_guess * this->high_guess;
    this->span_guess = this->high_guess - this->low_guess;
}

// Where `value_guess` falls in the range, clamped to 0-1.
// FUNCTION: TITANIUM 0x004C0B38
float FloatRange_guess::Fraction_guess(float value_guess)
{
    float fraction_guess = (value_guess - this->low_guess) / this->span_guess;
    if (!(fraction_guess > 0.0f)) {
        fraction_guess = 0.0f;
    }
    if (!(fraction_guess < 1.0f)) {
        fraction_guess = 1.0f;
    }
    return fraction_guess;
}

// Creates sound emitter slot `index_guess` named "PlayerPath" for wave `owner_guess` and starts it
// switched off (Notify_guess is probably SoundEmitter::Enable).
// FUNCTION: TITANIUM 0x004C0B66
void TargetTable_guess::Open_guess(int index_guess, void* owner_guess, int value_guess)
{
    EqMobileEmitter_guess* entry_guess = new EqMobileEmitter_guess(g_controller_guess);
    this->entries_guess[index_guess] = entry_guess;
    entry_guess->Open_guess(owner_guess, "PlayerPath");
    Target_guess* target_guess = this->entries_guess[index_guess]->target_guess;
    if (target_guess != 0) {
        target_guess->unknown40_guess = 1;
        target_guess->unknown44_guess = 1;
        target_guess->unknown20_guess = value_guess;
        target_guess->unknown3c_guess = this->unknown5c_guess;
        target_guess->unknown30_guess = this->unknown58_guess;
        target_guess->unknown34_guess = this->unknown5c_guess;
        target_guess->unknown18_guess = 0;
        target_guess->unknown1c_guess = 0;
        target_guess->unknown08_guess = this->unknown3fc_guess;
        target_guess->SetEnabled_guess(0);
    }
}

// The trail's sound: wave 0x510 on emitter slot 0.
// FUNCTION: TITANIUM 0x004C0C09
void TargetTable_guess::OpenPlayerPath_guess()
{
    this->Open_guess(0, (void*)0x510, 1);
}

// Switches sound emitter slot `index_guess` on or off.
// FUNCTION: TITANIUM 0x004C0C18
void TargetTable_guess::Dispatch_guess(int index_guess, int value_guess)
{
    EqMobileEmitter_guess* entry_guess = this->entries_guess[index_guess];
    if (entry_guess != 0 && entry_guess->target_guess != 0) {
        entry_guess->target_guess->SetEnabled_guess(value_guess);
    }
}

// EXTERNAL: TITANIUM 0x0060F784 Cosine_guess
double __cdecl Cosine_guess(double angle_guess);
// EXTERNAL: TITANIUM 0x0060F6D4 Sine_guess
double __cdecl Sine_guess(double angle_guess);

struct RingPoint_guess {
    float x_guess;
    float y_guess;
    float z_guess;

    RingPoint_guess(float x_arg, float y_arg, float z_arg)
    {
        this->x_guess = x_arg;
        this->y_guess = y_arg;
        this->z_guess = z_arg;
    }
};

struct Emitter_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Plot_guess(const RingPoint_guess& point_guess);
};

struct RingSource_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual Emitter_guess* Create_guess();
};

struct Ring_guess {
    char unknown000_guess[0x114];
    RingSource_guess* source_guess;

    Emitter_guess* CreateRingShape_guess(float* center_guess, float radius_guess, unsigned int segments_guess);
};

// A closed ring shape: `segments_guess` + 1 points on a circle of `radius_guess` around `center_guess`,
// starting at angle pi. Called as PlayerPathView_guess::CreateRingShape_guess.
// FUNCTION: TITANIUM 0x004C0C3B
// @early-stop: budget, diff ndiff=2
Emitter_guess* Ring_guess::CreateRingShape_guess(float* center_guess, float radius_guess, unsigned int segments_guess)
{
    Emitter_guess* emitter_guess = this->source_guess->Create_guess();
    double step_guess = 6.283185307179586 / (double)segments_guess;
    for (unsigned int index_guess = 0; index_guess <= segments_guess; ++index_guess) {
        float angle_guess = (float)(index_guess * step_guess + 3.141592653589793);
        float x_guess = (float)Cosine_guess(angle_guess);
        emitter_guess->Plot_guess(RingPoint_guess(
            center_guess[0] + radius_guess * x_guess, 0.0f, center_guess[1] + radius_guess * (float)Sine_guess(angle_guess)));
    }
    return emitter_guess;
}

// Emitter<n> names an ini section; reads its particle definition, lifespan, density and opacity.
// FUNCTION: TITANIUM 0x004C0CD8
void EmitterTable_guess::LoadEmitter_guess(EmitterSource_guess* source_guess, int index_guess)
{
    CXStr key_guess;
    CXStr value_guess;
    FormatString_guess(&key_guess, "Emitter%u", index_guess);
    value_guess = "*NULL*";
    source_guess->Read_guess(key_guess, &value_guess, 0);
    this->definition_guess[index_guess] = source_guess->GetInt_guess("Definition", -1, value_guess);
    this->lifeSpan_guess[index_guess] = (int)source_guess->GetFloat_guess("LifeSpan", 10.0f, value_guess);
    this->density_guess[index_guess] = source_guess->GetFloat_guess("Density", 1.0f, value_guess);
    this->opacity_guess[index_guess] = source_guess->GetFloat_guess("Opacity", 1.0f, value_guess);
}

struct FinishEmitterTable_guess {
    char unknown000_guess[0x37c];
    int definition_guess[16];   // 0x37C
    int lifeSpan_guess[4];      // 0x3BC
    float density_guess[4];     // 0x3CC
    float opacity_guess[4];     // 0x3DC

    void FinishEmitter_guess(EmitterSource_guess* source_guess, int index_guess);
};

// The same for FinishEmitter<n>, the effects spawned on arrival.
// FUNCTION: TITANIUM 0x004C0DFC
void FinishEmitterTable_guess::FinishEmitter_guess(EmitterSource_guess* source_guess, int index_guess)
{
    CXStr key_guess;
    CXStr value_guess;
    FormatString_guess(&key_guess, "FinishEmitter%u", index_guess);
    value_guess = "*NULL*";
    source_guess->Read_guess(key_guess, &value_guess, 0);
    this->definition_guess[index_guess] = source_guess->GetInt_guess("Definition", -1, value_guess);
    this->lifeSpan_guess[index_guess] = (int)source_guess->GetFloat_guess("LifeSpan", 10.0f, value_guess);
    this->density_guess[index_guess] = source_guess->GetFloat_guess("Density", 1.0f, value_guess);
    this->opacity_guess[index_guess] = source_guess->GetFloat_guess("Opacity", 1.0f, value_guess);
}

// Sends the find request: spawn id (+0x18) and the player's position (pinstLocalPlayer +0x30 to +0x38);
// clears the active and pending flags.
// FUNCTION: TITANIUM 0x004C0F20
void MessageState_guess::SendFindPersonRequest_guess()
{
    MessagePayload_guess payload_guess;
    payload_guess.message_guess = this->message_guess;
    payload_guess.unknown004_guess = g_connectionConfig_guess->unknown030_guess;
    payload_guess.unknown008_guess = g_connectionConfig_guess->unknown034_guess;
    payload_guess.unknown00c_guess = g_connectionConfig_guess->unknown038_guess;
    EQSendMessage(g_messageBuffer_guess, OP_FindPersonRequest, &payload_guess, 0x10, 1);
    this->lastTick_guess = g_getTickCount_guess();
    this->state_guess = 0;
    this->pending_guess = 0;
}

// Every EmitterPeriod ms starts a new emitter row at the trail's start, reusing the oldest row once
// MaxEmitterCount are in use; rows move EmitterSpeed units per ms.
// FUNCTION: TITANIUM 0x004C1158
void CallbackBatch_guess::SpawnEmitterRows_guess()
{
    if (this->capacity_guess != 0) {
        float step_guess = (float)this->elapsed_guess * this->scale_guess;
        if (this->count_guess > 0) {
            unsigned int rowIndex_guess = 0;
            do {
                this->rows_guess[rowIndex_guess].threshold_guess -= step_guess;
                ++rowIndex_guess;
            } while (rowIndex_guess < this->count_guess);
        }

        unsigned int elapsedTicks_guess = GetTickCount() - this->lastTick_guess;
        if (elapsedTicks_guess > this->interval_guess) {
            this->lastTick_guess = GetTickCount();
            unsigned int rowIndex_guess;
            if (this->count_guess < this->capacity_guess) {
                rowIndex_guess = this->count_guess;
                unsigned int entryIndex_guess = 0;
                do {
                    this->rows_guess[this->count_guess].entries_guess[entryIndex_guess] = 0;
                    ++entryIndex_guess;
                } while (entryIndex_guess < 4);
                ++this->count_guess;
            } else {
                rowIndex_guess = 0;
                for (unsigned int scanIndex_guess = 0; scanIndex_guess < this->count_guess; ++scanIndex_guess) {
                    if (this->rows_guess[scanIndex_guess].lastTick_guess <
                        this->rows_guess[rowIndex_guess].lastTick_guess) {
                        rowIndex_guess = scanIndex_guess;
                    }
                }
                for (unsigned int entryIndex_guess = 0; entryIndex_guess < 4; ++entryIndex_guess) {
                    Callback_guess* entry_guess = this->rows_guess[rowIndex_guess].entries_guess[entryIndex_guess];
                    if (entry_guess != 0) {
                        g_cleanupDispatcher_guess->Dispatch_guess((int)entry_guess);
                        this->rows_guess[rowIndex_guess].entries_guess[entryIndex_guess] = 0;
                    }
                }
            }
            CallbackRow_guess* row_guess = &this->rows_guess[rowIndex_guess];
            row_guess->lastTick_guess = GetTickCount();
            float overdue_guess = (float)(elapsedTicks_guess - this->interval_guess);
            row_guess->threshold_guess =
                (this->current_guess - this->base_guess) - overdue_guess * this->scale_guess;
        }
    }
}

// Switches off the emitters of rows beyond `value_guess` (the drawn length) or before the start.
// FUNCTION: TITANIUM 0x004C1305
void CallbackBatch_guess::HideEmittersBeyond_guess(float value_guess)
{
    for (int row_guess = 0; row_guess < 20; ++row_guess) {
        if (this->rows_guess[row_guess].threshold_guess > value_guess ||
            this->rows_guess[row_guess].threshold_guess < 0.0f) {
            CallbackRow_guess* entry_guess = &this->rows_guess[row_guess];
            unsigned int index_guess = 0;
            do {
                if (entry_guess->entries_guess[index_guess] != 0) {
                    entry_guess->entries_guess[index_guess]->Slot03_guess(0.0f);
                }
                ++index_guess;
            } while (index_guess < 4);
        }
    }
}

// Releases every row's emitter handles to the particle system (0x99E36C).
// FUNCTION: TITANIUM 0x004C12B4
void CleanupTable_guess::ReleaseEmitters_guess()
{
    while (this->count_guess > 0) {
        --this->count_guess;
        for (unsigned int index_guess = 0; index_guess < 4; ++index_guess) {
            int* entry_guess = &this->entries_guess[this->count_guess * 6 + index_guess];
            if (*entry_guess != 0) {
                g_cleanupDispatcher_guess->Dispatch_guess(*entry_guess);
                *entry_guess = 0;
            }
        }
    }
}

// Switches off every row's emitters.
// FUNCTION: TITANIUM 0x004C1357
void CallbackBatch_guess::HideAllEmitters_guess()
{
    CallbackRow_guess* row_guess = &this->rows_guess[0];
    int remaining_guess = 20;
    do {
        unsigned int index_guess = 0;
        do {
            if (row_guess->entries_guess[index_guess] != 0) {
                row_guess->entries_guess[index_guess]->Slot03_guess(0.0f);
            }
            ++index_guess;
        } while (index_guess < 4);
        ++row_guess;
        --remaining_guess;
    } while (remaining_guess != 0);
}

// Moves sound emitter slot `index_guess` to `position_guess`.
// FUNCTION: TITANIUM 0x004C1389
void PositionTable_guess::DispatchPosition_guess(int index_guess, Vector3_guess* position_guess)
{
    Target_guess* entry_guess = this->entries_guess[index_guess];
    if (entry_guess != 0) {
        entry_guess->SetPosition_guess(
            position_guess->x_guess, position_guess->y_guess, position_guess->z_guess);
    }
}

// Stops the trail: inactive, renderer cleared (slot 13), emitters released.
// FUNCTION: TITANIUM 0x004C13BA
void CleanupTable_guess::Reset_guess()
{
    CleanupInterface_guess* interface_guess = this->interface_guess;
    this->state_guess = 0;
    if (interface_guess != 0) {
        interface_guess->Slot13_guess();
    }
    return this->ReleaseEmitters_guess();
}

// Cancels the trail: mutes its sound, plays wave 0x512, resets. tu_073 calls it before each new find.
// FUNCTION: TITANIUM 0x004C13D7
void CleanupTable_guess::Cancel_guess()
{
    if (g_targetTable_guess != 0) {
        g_targetTable_guess->Dispatch_guess(0, 0);
        g_controller_guess->WavePlay_guess(0x512, 0);
        return this->Reset_guess();
    }
}

// Re-sends the find request while a trail is active.
// FUNCTION: TITANIUM 0x004C1409
void MessageState_guess::ResendFindRequest_guess()
{
    if (this->state_guess != 0) {
        this->SendFindPersonRequest_guess();
    }
}

// EXTERNAL: TITANIUM 0x00435B36 GetScale_guess
float __cdecl GetScale_guess();

// EXTERNAL: TITANIUM 0x00610884 ApplyScale_guess
float __cdecl ApplyScale_guess(double value_guess);

// EXTERNAL: TITANIUM 0x00464803 IsScaleReady_guess
char __cdecl IsScaleReady_guess(float value_guess);

// Normalises the vector; a near-zero length gives the zero vector.
// FUNCTION: TITANIUM 0x004C1414
void Vector3_guess::Normalize_guess()
{
    float value_guess = ApplyScale_guess((double)GetScale_guess());
    if (IsScaleReady_guess(value_guess)) {
        this->z_guess = 0.0f;
        this->y_guess = 0.0f;
        this->x_guess = 0.0f;
    } else {
        this->Scale_guess(1.0f / value_guess);
    }
}

// Detaches and frees the path's sound holder (0x0044AA7A), if any, and forgets it.
// FUNCTION: TITANIUM 0x004C1460
void Collection_guess::Release_guess()
{
    int buffer_guess = this->buffer_guess;
    if (buffer_guess != 0) {
        ((CleanupBuffer_guess*)buffer_guess)->Cleanup_guess();
        free((void*)buffer_guess);
        this->buffer_guess = 0;
    }
}

// Releases every loaded frame texture (0x99E360), newest first, and empties the list.
// FUNCTION: TITANIUM 0x004C1482
void Collection_guess::Process_guess()
{
    int index_guess = this->entries_guess.count_guess;
    while (index_guess != 0) {
        --index_guess;
        int value_guess = *this->entries_guess.Get_guess(index_guess);
        g_dispatcher_guess->Dispatch_guess(value_guess);
    }
    return this->entries_guess.Finish_guess();
}

struct EmitterFactory_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual int Slot05_guess(int definition_guess, int zero_guess, int lifeSpan_guess, float density_guess,
        float opacity_guess, Vector3_guess* position_guess, int zero2_guess, int zero3_guess, int zero4_guess,
        void* handle_guess, float scale_guess, int flag_guess);
};

#define g_emitterFactory_guess EQ_GLOBAL(EmitterFactory_guess*, 0x0099E36C)

struct CopyRecord_guess {
    unsigned int values_guess[3];

    // EXTERNAL: TITANIUM 0x0048F790 CopyRecord_guess::Distance_guess
    float Distance_guess(const CopyRecord_guess* other_guess);
};

struct EmissionSink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess(Vector3_guess* position_guess, float first_guess,
                              float second_guess, unsigned char* color_guess,
                              float third_guess, int zero_guess);
};

union PositionArgument_guess {
    int pointer_guess;
    float distance_guess;
};

struct SweepTrack_guess {
    char unknown000_guess[0x54];
    unsigned char flag54_guess;
    char unknown055_guess[0x17];
    FloatRange_guess range6c_guess;
    FloatRange_guess range80_guess;
    float value94_guess;
    char unknown098_guess[0x0c];
    float valueA4_guess;
    float valueA8_guess;
    float valueAC_guess;
    float valueB0_guess;
    float valueB4_guess;
    float valueB8_guess;
    char unknown0bc_guess[0x30];
    float valueEC_guess;
    float valueF0_guess;
    float valueF4_guess;
    char unknown0f8_guess[0x1c];
    EmissionSink_guess* sink114_guess;
    char unknown118_guess[0x44];
    float value15c_guess;
    char unknown160_guess[0x04];
    float value164_guess;
    char unknown168_guess[0x04];
    CallbackRow_guess rows_guess[20];   // 0x16C
    char unknown34c_guess[0x0c];
    unsigned int count_guess;           // 0x358
    char unknown35c_guess[0x04];
    int flag360_guess;                  // 0x360
    char unknown364_guess[0x08];
    int definition_guess[8];            // 0x36C
    int lifeSpan_guess[4];              // 0x38C
    float density_guess[4];             // 0x39C
    float opacity_guess[4];             // 0x3AC
    char unknown3bc_guess[0x30];
    int entry3ec_guess;                 // 0x3EC
    float time3f0_guess;                // 0x3F0

    void PlaceEmitterRows_guess(float first_guess, float second_guess, int p2_guess,
                       CopyRecord_guess* p3_guess, CopyRecord_guess* p4_guess, int p5_guess);
    void ApplySineWobble_guess(CopyRecord_guess* sample_guess, float time_guess, Vector3_guess* out_guess);
    bool DrawTrailPoint_guess(CopyRecord_guess* sample_guess, int position_guess, float time_guess);
    void DrawCurvedSegment_guess(int p1_guess, int p2_guess, CopyRecord_guess* p3_guess,
                     CopyRecord_guess* p4_guess, int p5_guess, float step_guess, float* accum_guess);
};

// EXTERNAL: TITANIUM 0x00580C35 FillSample_guess
void __stdcall FillSample_guess(CopyRecord_guess* sample_guess, int p2_guess,
                                CopyRecord_guess* p3_guess, CopyRecord_guess* p4_guess,
                                int p5_guess, float t_guess);

// EXTERNAL: TITANIUM 0x0060F784 ScalarTransform_guess
double __cdecl ScalarTransform_guess(double value_guess);

struct PositionTransform_guess {
    char unknown000_guess[0xb0];
    float scaleX_guess;
    float scaleY_guess;
    float scaleZ_guess;
    float rateX_guess;
    float rateY_guess;
    float rateZ_guess;
    char unknown0c8_guess[0x0c];
    float phaseX_guess;
    float phaseY_guess;
    float phaseZ_guess;
};

// Adds the sine wobble (SineRadius, SineSpeed, SinePhase) at trail distance `time_guess` to the point;
// ScalarTransform_guess is cos (the Cosine_guess VA).
// FUNCTION: TITANIUM 0x004C0F75
// @early-stop: budget, structural ndiff=7
void SweepTrack_guess::ApplySineWobble_guess(CopyRecord_guess* sample_guess, float time_guess, Vector3_guess* out_guess)
{
    PositionTransform_guess* transform_guess = (PositionTransform_guess*)this;
    float x_guess = (float)ScalarTransform_guess(
        (double)(time_guess * transform_guess->rateX_guess + transform_guess->phaseX_guess));
    float y_guess = (float)ScalarTransform_guess(
        (double)(time_guess * transform_guess->rateY_guess + transform_guess->phaseY_guess));
    double z_guess = ScalarTransform_guess(
        (double)(time_guess * transform_guess->rateZ_guess + transform_guess->phaseZ_guess));
    out_guess->x_guess = x_guess * transform_guess->scaleX_guess + ((Vector3_guess*)sample_guess)->x_guess;
    out_guess->y_guess = y_guess * transform_guess->scaleY_guess + ((Vector3_guess*)sample_guess)->y_guess;
    out_guess->z_guess = (float)(z_guess * transform_guess->scaleZ_guess + ((Vector3_guess*)sample_guess)->z_guess);
}

// Draws one trail point at distance `time_guess`. Alpha rises over the opaque range (+0x6C) and falls over
// the moving band (+0x80), both by distance from the player, times Alpha; scale, twist and texture scroll
// animate with time. Returns whether the point was visible.
// FUNCTION: TITANIUM 0x004C0FFF
// @early-stop: budget, structural ndiff=37
bool SweepTrack_guess::DrawTrailPoint_guess(CopyRecord_guess* sample_guess,
                                  int position_guess, float time_guess)
{
    Vector3_guess output_guess;
    float callbackTime_guess;
    float firstFraction_guess;

    ((PositionArgument_guess*)&position_guess)->distance_guess =
        ((Vector3_guess*)sample_guess)->Distance_guess((const Vector3_guess*)
            ((PositionArgument_guess*)&position_guess)->pointer_guess);
    firstFraction_guess = this->range6c_guess.Fraction_guess(
        (float)Sqrt_guess((double)((PositionArgument_guess*)&position_guess)->distance_guess));
    unsigned char alpha_guess = (unsigned char)(int)(
        (EQ_ARRAY(float, 0x0063F4D0)[0] - this->range80_guess.Fraction_guess(
            (float)Sqrt_guess((double)((PositionArgument_guess*)&position_guess)->distance_guess))) * firstFraction_guess *
        (int)this->flag54_guess);

    unsigned int tickCount_guess = GetTickCount();
    float tick_guess = (float)(int)tickCount_guess;
    if ((int)tickCount_guess < 0) {
        // Unsigned fix-up of the tick count.
        tick_guess = tick_guess + EQ_ARRAY(float, 0x0063F4D8)[0];
    }
    callbackTime_guess = (time_guess + this->valueF4_guess) * this->valueEC_guess +
        tick_guess * this->valueF0_guess * EQ_ARRAY(float, 0x00641088)[0];
    float angle_guess = (time_guess + this->valueAC_guess) * this->valueA8_guess;
    double operation_guess = fmodf_guess(angle_guess, EQ_ARRAY(float, 0x0064BB44)[0]);
    float outputX_guess = (float)ScalarTransform_guess(operation_guess) * this->valueA4_guess +
        this->value94_guess;

    this->ApplySineWobble_guess(sample_guess, time_guess, &output_guess);
    unsigned char color_guess[4];
    color_guess[0] = 0xff;
    color_guess[1] = 0xff;
    color_guess[2] = 0xff;
    color_guess[3] = alpha_guess;
    this->sink114_guess->Slot02_guess(&output_guess, outputX_guess, callbackTime_guess,
        color_guess, (time_guess + this->value164_guess) * this->value15c_guess, 0);
    return alpha_guess != 0;
}

// Places the emitter rows whose distance lies in [`first_guess`, `second_guess`) on this segment, creating
// their four emitters on first use, and moves the sound emitter when its distance (+0x3F0) falls here.
// FUNCTION: TITANIUM 0x004C14B0
void SweepTrack_guess::PlaceEmitterRows_guess(float first_guess, float second_guess, int p2_guess,
                                     CopyRecord_guess* p3_guess, CopyRecord_guess* p4_guess, int p5_guess)
{
    unsigned int row_index_guess = 0;
    float span_guess = second_guess - first_guess;
    if (this->count_guess > 0) {
        CallbackRow_guess* row_guess = &this->rows_guess[0];
        do {
            float time_guess = row_guess->threshold_guess;
            if (time_guess >= first_guess && time_guess < second_guess) {
                CopyRecord_guess sample_guess;
                FillSample_guess(&sample_guess, p2_guess, p3_guess, p4_guess, p5_guess,
                                 (time_guess - first_guess) / span_guess);
                Vector3_guess position_guess;
                this->ApplySineWobble_guess(&sample_guess, time_guess, &position_guess);
                unsigned int slot_index_guess = 0;
                do {
                    if (row_guess->entries_guess[slot_index_guess] == 0) {
                        int& definition_value_guess = this->definition_guess[slot_index_guess];
                        if (definition_value_guess >= 0 &&
                            g_emitterFactory_guess->Slot05_guess(definition_value_guess, 0, 0,
                                this->density_guess[slot_index_guess],
                                this->opacity_guess[slot_index_guess], &position_guess,
                                0, 0, 0, &row_guess->entries_guess[slot_index_guess], 1.0f, 0) < 0) {
                            this->flag360_guess = 0;
                        }
                    }
                    if (row_guess->entries_guess[slot_index_guess] != 0) {
                        row_guess->entries_guess[slot_index_guess]->Slot00_guess(&position_guess);
                    }
                    ++slot_index_guess;
                } while (slot_index_guess < 4);
            }
            ++row_index_guess;
            ++row_guess;
        } while (row_index_guess < this->count_guess);
    }
    if (this->entry3ec_guess != 0 && this->time3f0_guess >= first_guess &&
        this->time3f0_guess < second_guess) {
        CopyRecord_guess sample_guess;
        FillSample_guess(&sample_guess, p2_guess, p3_guess, p4_guess, p5_guess,
                         (this->time3f0_guess - first_guess) / span_guess);
        Vector3_guess position_guess;
        this->ApplySineWobble_guess(&sample_guess, this->time3f0_guess, &position_guess);
        ((PositionTable_guess*)this)->DispatchPosition_guess(0, &position_guess);
    }
}

// Address of point `index_guess` in the chunked table (12-byte points).
// FUNCTION: TITANIUM 0x004C16F4
int TableView_guess::Lookup_guess(int index_guess)
{
    return this->values_guess[index_guess >> this->shift_guess] +
        ((this->mask_guess & index_guess) * 12);
}

// Frees the element array (vector deleting destructor 0x004056CE with flags 3) and zeroes the pointer
// and both counts.
// FUNCTION: TITANIUM 0x004C1715
void VectorOwner_guess::Clear_guess()
{
    if (this->data_guess != 0) {
        this->data_guess->VectorDeletingDestructor_guess(3);
    }
    this->data_guess = 0;
    this->unknown08_guess = 0;
    this->unknown00_guess = 0;
}

// Defaults: emitter period 1000 ms, start 10, speed 1, up to 20 rows; four emitter slots with no
// definition, lifespan 10, density and opacity 1.
// FUNCTION: TITANIUM 0x004C1733
// @early-stop: budget, structural ndiff=22
CallbackBatch_guess::CallbackBatch_guess()
{
    this->unknown004_guess = -1;
    this->unknown0a8_guess = 1.0f;
    this->unknown018_guess = -1;
    this->unknown0ac_guess = 0.0f;
    this->unknown0ec_guess = 0.0f;
    this->unknown000_guess = 0;
    this->unknown0f0_guess = 1.0f;
    this->unknown014_guess = 0;
    this->unknown015_guess = 0;
    this->unknown050_guess = 0.1f;
    this->unknown0f4_guess = 0.0f;
    this->unknown054_guess = 0x80;
    this->unknown0f8_guess = 20.0f;
    this->unknown114_guess = 0;
    this->unknown10c_guess = 1.0f;
    this->array118_guess.Initialize_guess(32);
    SmallState_guess* state_guess = &this->state140_guess;
    state_guess->values_guess[1] = 0;
    state_guess->values_guess[0] = 0;
    state_guess->values_guess[2] = 0;
    state_guess->enabled_guess = 1;
    this->unknown15c_guess = 1.0f;
    this->unknown160_guess = 1.0f;
    this->unknown164_guess = 0.0f;
    this->unknown168_guess = 1;
    this->base_guess = 10.0f;
    this->interval_guess = 1000;
    this->scale_guess = 1.0f;
    this->count_guess = 0;
    this->capacity_guess = 20U;
    this->range058_guess.Set_guess(EQ_GLOBAL(float, 0x00647CCC), EQ_GLOBAL(float, 0x0064BB48));
    this->range06c_guess.Set_guess(EQ_GLOBAL(float, 0x006410C8), EQ_GLOBAL(float, 0x00644368));
    this->range094_guess.Set_guess(EQ_GLOBAL(float, 0x006410BC), EQ_GLOBAL(float, 0x006410D0));
    int index_guess = 4;
    int* slot_guess = this->definition_guess;
    do {
        int* cell_guess = slot_guess - 128;
        int row_guess = 20;
        do {
            *cell_guess = 0;
            cell_guess += 6;
            row_guess--;
        } while (row_guess != 0);
        *slot_guess = -1;
        ((float*)slot_guess)[12] = 1.0f;
        slot_guess[8] = 10;
        index_guess--;
        slot_guess++;
        ((float*)slot_guess)[15] = 1.0f;
    } while (index_guess != 0);
    this->unknown3ec_guess = 0;
}

// Path trail destructor: releases the interface at +0x114 (its virtual slot 0), every loaded frame
// texture (0x004C1482) and the sound holder (0x004C1460).
// FUNCTION: TITANIUM 0x004C1899
Collection_guess::~Collection_guess()
{
    if (this->interface_guess != 0) {
        this->interface_guess->Slot00_guess();
    }
    this->Process_guess();
    this->Release_guess();
}

// Frees the element array (0x004C1715).
// FUNCTION: TITANIUM 0x004C19F2
void VectorOwner_guess::Thunk_guess()
{
    this->Clear_guess();
}

struct Record_guess {
    int first_guess;
    int second_guess;
    int third_guess;
};

struct RecordTable_guess {
    int count_guess;                // 0x00
    int unknown04_guess;            // 0x04
    unsigned int mask_guess;        // 0x08
    int shift_guess;                // 0x0C
    int* values_guess;              // 0x10
    int allocatedBlockCount_0014_guess;            // 0x14
    char flag_guess;                // 0x18

    void Grow_guess(int index_guess);
    void Store_guess(int index_guess, const Record_guess* record_guess);
    // EXTERNAL: TITANIUM 0x0051DA09 RecordTable_guess::RoundUp_guess
    int RoundUp_guess(int requested_guess);
    // EXTERNAL: TITANIUM 0x00405492 RecordTable_guess::Fail_guess
    void Fail_guess();
};

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z
// EXTERNAL: TITANIUM 0x00401000 ??_H@YGXPAXIHP6EPAX0@Z@Z

struct ValueRecord_guess {
    int values_guess[3];

    // EXTERNAL: TITANIUM 0x00451A9B ValueRecord_guess::ValueRecord_guess
    ValueRecord_guess();
};

// Makes room for `requested_guess` points by adding chunks (0x51DA09 rounds up); on failure clears the
// table and raises (0x405492).
// FUNCTION: TITANIUM 0x004C18F5
// @early-stop: compiler-generated, diff ndiff=1
void RecordTable_guess::Grow_guess(int requested_guess)
{
    if (this->flag_guess != 0 && requested_guess > 0) {
        requested_guess = this->RoundUp_guess(requested_guess);
        if (requested_guess > this->allocatedBlockCount_0014_guess) {
            int* newValues_guess = new int[requested_guess];
            if (newValues_guess == 0) {
                this->flag_guess = 0;
            } else {
                for (int index_guess = 0; index_guess < this->allocatedBlockCount_0014_guess; ++index_guess) {
                    newValues_guess[index_guess] = this->values_guess[index_guess];
                }
                for (int index_guess = this->allocatedBlockCount_0014_guess; index_guess < requested_guess; ++index_guess) {
                    ValueRecord_guess* block_guess = new ValueRecord_guess[this->unknown04_guess];
                    newValues_guess[index_guess] = (int)block_guess;
                    if (block_guess == 0) {
                        this->flag_guess = 0;
                        break;
                    }
                }
                if (this->flag_guess != 0) {
                    delete[] this->values_guess;
                    this->values_guess = newValues_guess;
                    this->allocatedBlockCount_0014_guess = requested_guess;
                }
            }
        }
        if (this->flag_guess == 0) {
            ((TableView_guess*)this)->Clear_guess();
            this->Fail_guess();
        }
    }
}

// Writes point `index_guess`, growing the table and count as needed.
// FUNCTION: TITANIUM 0x004C19F7
void RecordTable_guess::Store_guess(int index_guess, const Record_guess* record_guess)
{
    if (index_guess >= 0) {
        if (index_guess >= this->count_guess) {
            this->Grow_guess(index_guess + 1);
            if (this->flag_guess != 0) {
                this->count_guess = index_guess + 1;
            }
        }
        if (this->flag_guess != 0) {
            Record_guess* entry_guess =
                (Record_guess*)((TableView_guess*)this)->Lookup_guess(index_guess);
            entry_guess->first_guess = record_guess->first_guess;
            entry_guess->second_guess = record_guess->second_guess;
            entry_guess->third_guess = record_guess->third_guess;
        }
    }
}

struct EmitterSystem_guess {
    unsigned char state_guess;                  // 0x00
    char unknown001_guess[0x13];
    unsigned char ready_guess;                  // 0x14
    char unknown015_guess[0xf7];
    float zOffset_guess;                        // 0x10C
    char unknown110_guess[4];
    CleanupInterface_guess* interface_guess;    // 0x114
    TableView_guess view_guess;                 // 0x118
    char unknown12c_guess[0x250];
    int definition_guess[16];                   // 0x37C
    int lifeSpan_guess[4];                      // 0x3BC
    float density_guess[4];                     // 0x3CC
    float opacity_guess[4];                     // 0x3DC

    void Arrive_guess();
};

struct SpawnView_guess {
    char unknown000_guess[0x120];
    char name_120_guess[0x124];         // 0x120
    char flag_244_guess;                // 0x244
    char unknown245_guess[0x13];        // 0x245
    unsigned short spawnId_0258_guess;     // 0x258

    // EXTERNAL: TITANIUM 0x00479396 SpawnView_guess::Check_guess
    char Check_guess();
};

struct CharData_guess {
    // EXTERNAL: TITANIUM 0x004BB226 CharData_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(const char* text_guess);
};

#define g_charData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)

struct IniReader_guess : EmitterSource_guess {
    int data_guess[4];

    // EXTERNAL: TITANIUM 0x005764E0 IniReader_guess::IniReader_guess
    IniReader_guess(const char* file_guess, const char* section_guess);
    // EXTERNAL: TITANIUM 0x005761D0 IniReader_guess::~IniReader_guess
    ~IniReader_guess();
    // EXTERNAL: TITANIUM 0x005750A0 IniReader_guess::GetBool_guess
    bool GetBool_guess(const char* key_guess, bool default_guess, const char* value_guess);
    // EXTERNAL: TITANIUM 0x00574E70 IniReader_guess::SetSection_guess
    void SetSection_guess(const char* section_guess);
    // EXTERNAL: TITANIUM 0x00575320 IniReader_guess::ReadSections_guess
    void ReadSections_guess(IndexedVector_guess* list_guess, const char* section_guess);
};

struct TextHelper_guess {
    // EXTERNAL: TITANIUM 0x00572C10 TextHelper_guess::Append_guess
    void Append_guess(const CXStr& other_guess);
    // EXTERNAL: TITANIUM 0x00573B10 TextHelper_guess::Compare_guess
    int Compare_guess(const CXStr& other_guess, int flag_guess);
};

struct SectionList_guess : IndexedVector_guess {
    bool valid_guess;

    SectionList_guess()
    {
        this->unknown04_guess = 0;
        this->count_guess = 0;
        this->unknown08_guess = 0;
        this->valid_guess = true;
    }
    ~SectionList_guess() { ((VectorOwner_guess*)this)->Clear_guess(); }
};

struct PathColor_guess {
    unsigned char blue_guess;
    unsigned char green_guess;
    unsigned char red_guess;
    unsigned char alpha_guess;

    PathColor_guess(unsigned char red_guess_arg, unsigned char green_guess_arg, unsigned char blue_guess_arg,
                    unsigned char alpha_guess_arg)
    {
        this->blue_guess = blue_guess_arg;
        this->green_guess = green_guess_arg;
        this->red_guess = red_guess_arg;
        this->alpha_guess = alpha_guess_arg;
    }
};

struct Point2_guess {
    float x_guess;
    float y_guess;

    Point2_guess(float x_guess_arg, float y_guess_arg)
    {
        this->x_guess = x_guess_arg;
        this->y_guess = y_guess_arg;
    }
};

struct PathShape_guess {
    virtual void Slot00_guess();
    virtual void SetColor_guess(const PathColor_guess* color_guess);
    virtual void SetScale_guess(float value_guess);
    virtual void SetTwist_guess(float value_guess);
    virtual void SetTextureScale_guess(float value_guess);
};

struct PathRenderer_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Reset_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void SetAdditive_guess(bool value_guess);
};

struct PathFactory_guess {
    virtual PathRenderer_guess* Create_guess();
};

#define g_pathFactory_guess EQ_GLOBAL(PathFactory_guess*, 0x0099E348)

// EXTERNAL: TITANIUM 0x004C805F LoadTexture_guess
int __stdcall LoadTexture_guess(const char* name_guess);

struct PathVector_guess {
    float x_guess;
    float y_guess;
    float z_guess;

    void Set_guess(float x_guess_arg, float y_guess_arg, float z_guess_arg)
    {
        this->x_guess = x_guess_arg;
        this->y_guess = y_guess_arg;
        this->z_guess = z_guess_arg;
    }
};

struct PlayerPathView_guess {
    char unknown000_guess[0x10];
    float finishRange_guess;            // 0x10
    char unknown014_guess[0x04];
    int message_18_guess;               // 0x18
    char unknown01c_guess[0x04];
    float segmentLength_guess;          // 0x20
    float controlSegmentLength_guess;   // 0x24
    float mergeDistance_guess;          // 0x28
    char unknown02c_guess[0x24];
    float extendDistanceSq_guess;       // 0x50
    unsigned char alpha_guess;          // 0x54
    char unknown055_guess[3];
    FloatRange_guess fade_guess;        // 0x58
    FloatRange_guess opaque_guess;      // 0x6C
    FloatRange_guess band_guess;        // 0x80
    FloatRange_guess scale_guess;       // 0x94
    float scaleSpeed_guess;             // 0xA8
    float scaleValue_guess;             // 0xAC
    PathVector_guess sineRadius_guess;  // 0xB0
    PathVector_guess sinePeriod_guess;  // 0xBC
    PathVector_guess sineSpeed_guess;   // 0xC8
    PathVector_guess sinePhase_guess;   // 0xD4
    PathVector_guess sineOffset_guess;  // 0xE0
    float twistFactor_guess;            // 0xEC
    float twistSpeed_guess;             // 0xF0
    float twistValue_guess;             // 0xF4
    float curveScale_guess;             // 0xF8
    char unknown0fc_guess[4];
    float initialLength_guess;          // 0x100
    float travel_guess;                 // 0x104
    float growSpeed_guess;              // 0x108
    float floorOffset_guess;            // 0x10C
    float lodFactor_guess;              // 0x110
    PathRenderer_guess* renderer_guess; // 0x114
    char unknown118_guess[0x28];
    IndexedVector_guess frames_guess;   // 0x140
    char unknown14c_guess[4];
    int duration_guess;                 // 0x150
    int frame_guess;                    // 0x154
    unsigned int frameTick_guess;       // 0x158
    float textureScale_guess;           // 0x15C
    float textureSpeed_guess;           // 0x160
    float textureValue_guess;           // 0x164
    char unknown168_guess[0x1e4];
    float emitterStart_guess;           // 0x34C
    float emitterSpeed_guess;           // 0x350
    int emitterPeriod_guess;            // 0x354
    char unknown358_guess[4];
    unsigned int minEmitters_guess;     // 0x35C
    unsigned int maxEmitters_guess;     // 0x360
    char unknown364_guess[0x90];
    float soundLoopSpeed_guess;         // 0x3F4
    float soundDistance_guess;          // 0x3F8
    float soundLoopVolume_guess;        // 0x3FC

    void LoadSettings_guess();
    // EXTERNAL: TITANIUM 0x004C0C3B PlayerPathView_guess::CreateRingShape_guess
    PathShape_guess* CreateRingShape_guess(Point2_guess* point_guess, float scale_guess, int points_guess);
    void FindGroupMember_guess(SpawnView_guess* spawn_guess);
    void FindRaidMember_guess(SpawnView_guess* spawn_guess);
    void RefreshFlagged_guess(SpawnView_guess* spawn_guess);
};

// Loads SpellEffects\Path.ini [Path]: segment lengths, fades, sine wobble, twist, emitters, sound, the
// shapes listed under ShapeSet and the Texture frames (<name><n>.tga, or <name>.tga), then creates the
// sound emitter. Every find request reloads it.
// FUNCTION: TITANIUM 0x004C1A41
// @early-stop: budget, structural ndiff=426
void PlayerPathView_guess::LoadSettings_guess()
{
    CXStr section_guess("Path");
    IniReader_guess ini_guess("SpellEffects\\Path.ini", section_guess);
    this->segmentLength_guess = ini_guess.GetFloat_guess("SegmentLength", 5.0f, 0);
    this->lodFactor_guess = ini_guess.GetFloat_guess("LODFactor", 0.0f, 0);
    this->controlSegmentLength_guess = ini_guess.GetFloat_guess("ControlSegmentLength", 5.0f, 0);
    this->mergeDistance_guess = ini_guess.GetFloat_guess("MergeDistance", 5.0f, 0);
    float extend_guess = ini_guess.GetFloat_guess("ExtendDistance", 0.1f, 0);
    this->extendDistanceSq_guess = extend_guess * extend_guess;
    this->finishRange_guess = ini_guess.GetFloat_guess("FinishRange", 10.0f, 0);

    CXStr texture_guess("Path");
    ini_guess.Read_guess("Texture", &texture_guess, 0);
    CXStr path_guess("SpellEffects\\");
    ((TextHelper_guess*)&path_guess)->Append_guess(texture_guess);

    int frameCount_guess = ini_guess.GetInt_guess("FrameCount", 0, 0);
    this->duration_guess = ini_guess.GetInt_guess("Duration", 0, 0);
    this->textureScale_guess = ini_guess.GetFloat_guess("TextureScale", 1.0f, 0);
    this->textureSpeed_guess = ini_guess.GetFloat_guess("TextureSpeed", 0.0f, 0);
    this->textureValue_guess = 0.0f;
    this->twistValue_guess = 0.0f;
    this->scaleValue_guess = 0.0f;
    this->alpha_guess = (unsigned char)ini_guess.GetInt_guess("Alpha", 0x80, 0);
    // A no-op clamp: the field is already a byte.
    this->alpha_guess = this->alpha_guess < 255 ? this->alpha_guess : 255;

    this->fade_guess.Set_guess(ini_guess.GetFloat_guess("FadeStart", 80.0f, 0),
                               ini_guess.GetFloat_guess("FadeEnd", 110.0f, 0));
    this->opaque_guess.Set_guess(ini_guess.GetFloat_guess("OpaqueStart", 10.0f, 0),
                                 ini_guess.GetFloat_guess("OpaqueEnd", 20.0f, 0));
    float initial_guess = ini_guess.GetFloat_guess("InitialLength", 1.0f, 0);
    this->initialLength_guess = initial_guess;
    this->travel_guess = initial_guess - this->fade_guess.span_guess;
    this->growSpeed_guess = ini_guess.GetFloat_guess("GrowSpeed", 1.0f, 0);
    this->scale_guess.Set_guess(ini_guess.GetFloat_guess("ScaleMin", 0.5f, 0),
                                ini_guess.GetFloat_guess("ScaleMax", 1.5f, 0));
    this->scaleSpeed_guess = ini_guess.GetFloat_guess("ScaleSpeed", 1.0f, 0);

    this->sinePeriod_guess.Set_guess(ini_guess.GetFloat_guess("SinePeriodX", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SinePeriodY", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SinePeriodZ", 0.0f, 0));
    this->sineRadius_guess.Set_guess(ini_guess.GetFloat_guess("SineRadiusX", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SineRadiusY", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SineRadiusZ", 0.0f, 0));
    this->sineSpeed_guess.Set_guess(ini_guess.GetFloat_guess("SineSpeedX", 0.0f, 0),
                                    ini_guess.GetFloat_guess("SineSpeedY", 0.0f, 0),
                                    ini_guess.GetFloat_guess("SineSpeedZ", 0.0f, 0));
    // the original reads SineOffsetZ for Y as well
    this->sineOffset_guess.Set_guess(ini_guess.GetFloat_guess("SineOffsetX", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SineOffsetZ", 0.0f, 0),
                                     ini_guess.GetFloat_guess("SineOffsetZ", 0.0f, 0));
    this->sinePhase_guess = this->sineOffset_guess;

    this->floorOffset_guess = ini_guess.GetFloat_guess("FloorOffset", 1.0f, 0);
    // Scaled by a float of the local player (+0x238), probably its height.
    this->floorOffset_guess = g_connectionConfig_guess->heightOffset_0238_guess * this->floorOffset_guess;
    this->twistFactor_guess = ini_guess.GetFloat_guess("TwistFactor", 0.0f, 0);
    this->twistSpeed_guess = ini_guess.GetFloat_guess("TwistSpeed", 1.0f, 0);
    this->curveScale_guess = ini_guess.GetFloat_guess("CurveScale", 20.0f, 0);
    this->emitterSpeed_guess = ini_guess.GetFloat_guess("EmitterSpeed", 1.0f, 0);
    this->emitterPeriod_guess = ini_guess.GetInt_guess("EmitterPeriod", 1000, 0);
    this->emitterStart_guess = ini_guess.GetFloat_guess("EmitterStartCoordinate", 10.0f, 0);
    this->minEmitters_guess = ini_guess.GetInt_guess("MinEmitterCount", 0, 0) > 0
        ? ini_guess.GetInt_guess("MinEmitterCount", 0, 0) : 0;
    this->maxEmitters_guess = ini_guess.GetInt_guess("MaxEmitterCount", 0, 0) > 0
        ? ini_guess.GetInt_guess("MaxEmitterCount", 0, 0) : 0;
    // At most 20 rows (rows_guess).
    this->maxEmitters_guess = this->maxEmitters_guess < 20 ? this->maxEmitters_guess : 20;
    this->soundDistance_guess = ini_guess.GetFloat_guess("SoundDistance", 10.0f, 0);
    this->soundLoopVolume_guess = ini_guess.GetFloat_guess("SoundLoopVolume", 4.0f, 0);
    this->soundLoopSpeed_guess = ini_guess.GetFloat_guess("SoundLoopSpeed", 1.0f, 0);

    for (unsigned int emitter_guess = 0; emitter_guess < 4; ++emitter_guess) {
        ((EmitterTable_guess*)this)->LoadEmitter_guess(&ini_guess, emitter_guess);
        ((FinishEmitterTable_guess*)this)->FinishEmitter_guess(&ini_guess, emitter_guess);
    }
    ((CleanupTable_guess*)this)->ReleaseEmitters_guess();

    if (g_pathFactory_guess != 0) {
        if (this->renderer_guess == 0) {
            this->renderer_guess = g_pathFactory_guess->Create_guess();
        } else {
            this->renderer_guess->Reset_guess();
        }
        this->renderer_guess->SetAdditive_guess(!ini_guess.GetBool_guess("Additive", true, 0));

        CXStr shapeSet_guess("*NULL*");
        ini_guess.Read_guess("ShapeSet", &shapeSet_guess, 0);
        bool undefined_guess = ((TextHelper_guess*)&shapeSet_guess)->Compare_guess("*NULL*", 0) == 0;
        if (undefined_guess) {
            OutputDebugStringA("PlayerPath: ShapeSet undefined!\n");
        } else {
            SectionList_guess sections_guess;
            ini_guess.ReadSections_guess(&sections_guess, shapeSet_guess);
            CXStr unused1_guess;
            CXStr unused2_guess;
            int count_guess = sections_guess.count_guess;
            for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
                ini_guess.SetSection_guess(*(CXStr*)sections_guess.Get_guess(i_guess));
                Point2_guess point_guess(ini_guess.GetFloat_guess("X", 0.0f, 0),
                                         ini_guess.GetFloat_guess("Y", 0.0f, 0));
                PathShape_guess* shape_guess = this->CreateRingShape_guess(&point_guess,
                    ini_guess.GetFloat_guess("Scale", 1.0f, 0), ini_guess.GetInt_guess("Points", 8, 0));
                PathColor_guess color_guess(ini_guess.GetInt_guess("Red", 0xff, 0),
                                            ini_guess.GetInt_guess("Green", 0xff, 0),
                                            ini_guess.GetInt_guess("Blue", 0xff, 0),
                                            ini_guess.GetInt_guess("Alpha", 0xff, 0));
                shape_guess->SetColor_guess(&color_guess);
                shape_guess->SetTwist_guess(ini_guess.GetFloat_guess("Twist", 1.0f, 0));
                shape_guess->SetScale_guess(ini_guess.GetFloat_guess("Scale", 1.0f, 0));
                shape_guess->SetTextureScale_guess(ini_guess.GetFloat_guess("TextureScale", 1.0f, 0));
            }

            ((Collection_guess*)this)->Process_guess();
            CXStr frameName_guess;
            // The (AVATAR) load messages below are built and dropped, never shown.
            if (frameCount_guess > 0) {
                for (int frame_guess = 0; frame_guess < frameCount_guess; ++frame_guess) {
                    FormatString_guess(&frameName_guess, "%s%d.tga", (char*)path_guess, frame_guess);
                    int handle_guess = LoadTexture_guess(frameName_guess);
                    if (handle_guess == 0) {
                        CXStr message_guess;
                        FormatString_guess(&message_guess, "(AVATAR) Unable to load: %s", (char*)frameName_guess);
                    } else {
                        CXStr message_guess;
                        FormatString_guess(&message_guess, "(AVATAR) Loaded: %s", (char*)frameName_guess);
                        this->frames_guess.Insert_guess(this->frames_guess.count_guess, &handle_guess);
                    }
                }
            } else {
                FormatString_guess(&frameName_guess, "%s.tga", (char*)path_guess);
                int handle_guess = LoadTexture_guess(frameName_guess);
                if (handle_guess == 0) {
                    CXStr message_guess;
                    FormatString_guess(&message_guess, "(AVATAR) Unable to load: %s", (char*)frameName_guess);
                } else {
                    CXStr message_guess;
                    FormatString_guess(&message_guess, "(AVATAR) Loaded: %s", (char*)frameName_guess);
                    this->frames_guess.Insert_guess(this->frames_guess.count_guess, &handle_guess);
                }
            }
            ((Collection_guess*)this)->Release_guess();
            ((TargetTable_guess*)this)->OpenPlayerPath_guess();
            this->frame_guess = 0;
            this->frameTick_guess = GetTickCount();
        }
    }
}

// Find path to an NPC (+0x244 = 1), a spawn passing 0x479396, or anyone while the player's +0x256 flag is
// set (that flag also skips floor snapping).
// FUNCTION: TITANIUM 0x004C251B
void PlayerPathView_guess::RefreshFlagged_guess(SpawnView_guess* spawn_guess)
{
    if (spawn_guess != 0) {
        if (spawn_guess->Check_guess() != 0 || spawn_guess->flag_244_guess == 1 ||
            g_connectionConfig_guess->flag256_guess != 0) {
            this->message_18_guess = spawn_guess->spawnId_0258_guess;
            ((MessageState_guess*)this)->SendFindPersonRequest_guess();
        }
    }
    this->LoadSettings_guess();
}

// Find path to a group member (EQ_PC::IsAGroupMember, 0x4BB226); players only. The group Find Path
// leadership ability (tu_073).
// FUNCTION: TITANIUM 0x004C2566
void PlayerPathView_guess::FindGroupMember_guess(SpawnView_guess* spawn_guess)
{
    if (spawn_guess != 0 && spawn_guess->flag_244_guess == 0) {
        if (g_charData_guess->IsAGroupMember_guess(spawn_guess->name_120_guess) != 0) {
            this->message_18_guess = spawn_guess->spawnId_0258_guess;
            ((MessageState_guess*)this)->SendFindPersonRequest_guess();
        }
    }
    this->LoadSettings_guess();
}

struct NameTable_guess {
    // EXTERNAL: TITANIUM 0x004303A6 NameTable_guess::IsMember_guess
    char IsMember_guess(const char* name_guess);
};

#define g_nameTable_guess EQ_ARRAY(NameTable_guess, 0x0091D708)

// Find path to a raid member (CRaid at 0x91D708); the raid Find Path ability.
// FUNCTION: TITANIUM 0x004C25AE
void PlayerPathView_guess::FindRaidMember_guess(SpawnView_guess* spawn_guess)
{
    if (spawn_guess != 0 && spawn_guess->flag_244_guess == 0) {
        if (g_nameTable_guess->IsMember_guess(spawn_guess->name_120_guess) != 0) {
            this->message_18_guess = spawn_guess->spawnId_0258_guess;
            ((MessageState_guess*)this)->SendFindPersonRequest_guess();
        }
    }
    this->LoadSettings_guess();
}

// Arrival, once: mutes the trail sound, plays wave 0x511, prints string 0x1A78, hides the trail and spawns
// the four FinishEmitter effects at the destination (point 0), lowered by FloorOffset.
// FUNCTION: TITANIUM 0x004C25F5
void EmitterSystem_guess::Arrive_guess()
{
    if (this->ready_guess == 0) {
        ((TargetTable_guess*)this)->Dispatch_guess(0, 0);
        g_controller_guess->WavePlay_guess(0x511, 0);
        const char* text_guess = pStringTable->getString(0x1a78, 0);
        pEverQuest->dsp_chat(text_guess);
        this->ready_guess = 1;
        this->state_guess = 0;
        this->interface_guess->Slot13_guess();
        ((CallbackBatch_guess*)this)->HideAllEmitters_guess();
        int remaining_guess = 4;
        float* density_guess = this->density_guess;
        do {
            int definition_guess = ((int*)density_guess)[-20];
            if (definition_guess >= 0) {
                Vector3_guess* source_guess =
                    (Vector3_guess*)this->view_guess.values_guess[0 >> this->view_guess.shift_guess];
                Vector3_guess position_guess;
                position_guess.x_guess = source_guess->x_guess;
                position_guess.y_guess = source_guess->y_guess;
                position_guess.z_guess = source_guess->z_guess - this->zOffset_guess;
                int handle_guess;
                g_emitterFactory_guess->Slot05_guess(definition_guess, 0, ((int*)density_guess)[-4],
                    *density_guess, density_guess[4], &position_guess,
                    0, 0, 0, &handle_guess, 1.0f, 1);
            }
            ++density_guess;
            --remaining_guess;
        } while (remaining_guess != 0);
    }
}

struct SlotGate_guess {
    int slot_guess;             // 0x00
    char unknown04_guess[0x0c]; // 0x04
    int gate_guess;             // 0x10

    // EXTERNAL: TITANIUM 0x004C18F5 SlotGate_guess::Notify_guess
    void Notify_guess(int value_guess);
    void SetPointCount_guess(int value_guess);
};

// Sets the point count after making room; TrimToPlayer_guess uses it to cut the trail.
// FUNCTION: TITANIUM 0x004C26D9
void SlotGate_guess::SetPointCount_guess(int value_guess)
{
    this->Notify_guess(value_guess);
    if (this->gate_guess != 0) {
        this->slot_guess = value_guess;
    }
}


// Draws the segment `fromPoint_guess` -> `toPoint_guess` as a spline with tangent points `beforeControlPoint_guess` and `afterControlPoint_guess`, in
// steps of `step_guess`. Adds span * step to `*accum_guess` per sample and once more after the loop: the
// full span only when the step divides 1 (step 0.3 adds 1.2 spans).
// FUNCTION: TITANIUM 0x004C1645
void SweepTrack_guess::DrawCurvedSegment_guess(int targetPosition_guess, int beforeControlPoint_guess, CopyRecord_guess* fromPoint_guess,
                                   CopyRecord_guess* toPoint_guess, int afterControlPoint_guess, float step_guess,
                                   float* accum_guess)
{
    float t_guess = step_guess;
    float span_guess = toPoint_guess->Distance_guess(fromPoint_guess);
    this->PlaceEmitterRows_guess(*accum_guess, span_guess + *accum_guess, beforeControlPoint_guess, fromPoint_guess, toPoint_guess, afterControlPoint_guess);
    float distanceStep_guess = span_guess * step_guess;
    while (t_guess < 0.99f) {
        CopyRecord_guess sample_guess;
        FillSample_guess(&sample_guess, beforeControlPoint_guess, fromPoint_guess, toPoint_guess, afterControlPoint_guess, t_guess);
        *accum_guess = distanceStep_guess + *accum_guess;
        this->DrawTrailPoint_guess(&sample_guess, targetPosition_guess, *accum_guess);
        t_guess = t_guess + step_guess;
    }
    *accum_guess = distanceStep_guess + *accum_guess;
}

struct World_guess {
    // EXTERNAL: TITANIUM 0x00439F26 World_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x_guess, float y_guess, float z_guess);
};

#define g_world_guess EQ_GLOBAL(World_guess*, 0x00905D24)
#define g_zoneCounter_guess EQ_GLOBAL(int, 0x00924470)

struct PathSink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess(int* value_guess);
};

struct PathInterface_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(int value_guess);
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess(int value_guess);
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual PathSink_guess* Slot15_guess();
    virtual PathSink_guess* Slot16_guess();
};

struct PathFollower_guess {
    unsigned char state_guess;          // 0x000
    char unknown001_guess[3];
    int zone_guess;                     // 0x004
    unsigned int lastTick_guess;        // 0x008
    unsigned int elapsed_guess;         // 0x00C
    float range_guess;                  // 0x010
    unsigned char ready_guess;          // 0x014
    char unknown015_guess[0x0b];
    float radius_guess;                 // 0x020
    float maxStep_guess;                // 0x024
    float threshold28_guess;              // 0x028
    Vector3_guess basePosition_guess;   // 0x02C
    int marker_guess;                   // 0x038
    int previousMarker_guess;           // 0x03C
    Vector3_guess recentPosition_guess; // 0x040
    unsigned int prepareTick_guess;     // 0x04C
    char unknown050_guess[8];
    float limit_guess;                  // 0x058
    float limitHigh_guess;              // 0x05C
    char unknown060_guess[0x08];
    float spread_guess;                 // 0x068
    char unknown06c_guess[8];
    float distanceLimit_guess;          // 0x074
    char unknown078_guess[8];
    FloatRange_guess band_guess;        // 0x080
    char unknown094_guess[0x14];
    float rateA8_guess;                 // 0x0A8
    float valueAC_guess;                // 0x0AC
    char unknown0b0_guess[0x18];
    float rateC8_guess;                 // 0x0C8
    float rateCC_guess;                 // 0x0CC
    float rateD0_guess;                 // 0x0D0
    float valueD4_guess;                // 0x0D4
    float valueD8_guess;                // 0x0D8
    float valueDC_guess;                // 0x0DC
    Vector3_guess initialValue_guess;     // 0x0E0
    char unknown0ec_guess[4];
    float rateF0_guess;                 // 0x0F0
    float valueF4_guess;                // 0x0F4
    float scale_guess;                  // 0x0F8
    float markerDistance_guess;         // 0x0FC
    float value100_guess;               // 0x100
    float travel_guess;                 // 0x104
    float speed_guess;                  // 0x108
    float zOffset_guess;                // 0x10C
    float radiusScale_guess;            // 0x110
    PathInterface_guess* interface_guess; // 0x114
    TableView_guess points_guess;       // 0x118
    char unknown12c_guess[0x08];
    CopyRecord_guess origin_guess;      // 0x134
    IndexedVector_guess frames_guess;   // 0x140
    char unknown14c_guess[4];
    unsigned int frameInterval_guess;   // 0x150
    int frame_guess;                    // 0x154
    unsigned int frameTick_guess;       // 0x158
    char unknown15c_guess[4];
    float rate160_guess;                // 0x160
    float value164_guess;               // 0x164
    char unknown168_guess[0x288];
    float fade_guess;                   // 0x3F0
    float fadeRate_guess;               // 0x3F4
    float fadeMargin_guess;             // 0x3F8

    void Handle_OP_FindPersonReply_guess(const Vector3_guess* positions_guess, unsigned int count_guess,
                          int interfaceValue_guess);
    void TrimToPlayer_guess(Vector3_guess* position_guess);
    void ProcessPath_guess(Vector3_guess* position_guess);
};

// The find reply: builds the trail from the server's points, last first, so point 0 is the destination.
// Points are snapped to the floor plus FloorOffset, closer than MergeDistance (+0x28) are dropped, and gaps
// over ControlSegmentLength (+0x24) are filled. Under 2 or over 10000 points fail with string 0x1A7B;
// success plays wave 0x50F and prints 0x1A77.
// FUNCTION: TITANIUM 0x004C270D
// @early-stop: budget, structural ndiff=227
void PathFollower_guess::Handle_OP_FindPersonReply_guess(const Vector3_guess* positions_guess,
                                          unsigned int count_guess, int interfaceValue_guess)
{
    if (g_pathFactory_guess == 0) {
        return;
    }
    if (count_guess < 2) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1a7b, 0));
        ((CleanupTable_guess*)this)->Reset_guess();
        return;
    }

    if (this->interface_guess == 0) {
        this->interface_guess = (PathInterface_guess*)g_pathFactory_guess->Create_guess();
    } else {
        this->interface_guess->Slot13_guess();
    }

    this->origin_guess.values_guess[0] = ((const unsigned int*)positions_guess)[0];
    this->origin_guess.values_guess[1] = ((const unsigned int*)positions_guess)[1];
    this->origin_guess.values_guess[2] = ((const unsigned int*)positions_guess)[2];
    this->points_guess.Clear_guess();
    CXStr pathString_guess;

    unsigned int remaining_guess = count_guess;
    float previousX_guess = 3.402823466e+38f;
    float previousY_guess = 3.402823466e+38f;
    float previousZ_guess = 3.402823466e+38f;
    const Vector3_guess* point_guess = positions_guess + count_guess;

    if (count_guess > 1) {
        do {
            --remaining_guess;
            --point_guess;
            float height_guess = point_guess->z_guess;
            if (g_connectionConfig_guess->flag256_guess == 0) {
                float ground_guess = g_world_guess->GetFloorHeight_guess(
                    point_guess->x_guess, point_guess->y_guess, point_guess->z_guess);
                if (ground_guess > -1.0e27f) {
                    height_guess = ground_guess + this->zOffset_guess;
                }
            }

            Vector3_guess candidate_guess;
            candidate_guess.x_guess = point_guess->x_guess;
            candidate_guess.y_guess = point_guess->y_guess;
            candidate_guess.z_guess = height_guess;
            Vector3_guess previous_guess;
            previous_guess.x_guess = previousX_guess;
            previous_guess.y_guess = previousY_guess;
            previous_guess.z_guess = previousZ_guess;
            float distanceSquared_guess = candidate_guess.Distance_guess(&previous_guess);

            if (this->threshold28_guess * this->threshold28_guess <= distanceSquared_guess) {
                if (remaining_guess + 1 < count_guess &&
                    this->maxStep_guess * this->maxStep_guess < distanceSquared_guess) {
                    double distance_guess = Sqrt_guess((double)distanceSquared_guess);
                    Vector3_guess difference_guess;
                    difference_guess.x_guess = candidate_guess.x_guess - previousX_guess;
                    difference_guess.y_guess = candidate_guess.y_guess - previousY_guess;
                    difference_guess.z_guess = candidate_guess.z_guess - previousZ_guess;
                    float step_guess = (float)(this->maxStep_guess / distance_guess);
                    float fraction_guess = step_guess;
                    float end_guess = 1.0f - step_guess;

                    while (fraction_guess < end_guess) {
                        if (this->points_guess.count_0000_guess > 10000) {
                            pEverQuest->dsp_chat(pStringTable->getString(0x1a7b, 0));
                            ((CleanupTable_guess*)this)->Reset_guess();
                            return;
                        }
                        Vector3_guess scaled_guess;
                        difference_guess.ScaleInto_guess(&scaled_guess, fraction_guess);
                        Vector3_guess sample_guess;
                        sample_guess.x_guess = previousX_guess + scaled_guess.x_guess;
                        sample_guess.y_guess = previousY_guess + scaled_guess.y_guess;
                        sample_guess.z_guess = previousZ_guess + scaled_guess.z_guess;

                        float sampleHeight_guess = sample_guess.z_guess;
                        if (g_connectionConfig_guess->flag256_guess == 0) {
                            float sampleBase_guess = sample_guess.z_guess > candidate_guess.z_guess
                                ? sample_guess.z_guess : candidate_guess.z_guess;
                            float ground_guess = g_world_guess->GetFloorHeight_guess(
                                sample_guess.x_guess, sample_guess.y_guess, sampleBase_guess + 3.0f);
                            if (ground_guess > -1.0e27f) {
                                sampleHeight_guess = ground_guess + this->zOffset_guess;
                            } else {
                                sampleHeight_guess = point_guess->z_guess;
                            }
                        }
                        double heightDifference_guess = fabs((double)(sampleHeight_guess - sample_guess.z_guess));
                        // A floor hit more than 1000 units off is ignored.
                        if (heightDifference_guess < 1000.0) {
                            sample_guess.z_guess = sampleHeight_guess;
                        }
                        ((RecordTable_guess*)&this->points_guess)->Store_guess(
                            this->points_guess.count_0000_guess, (const Record_guess*)&sample_guess);
                        fraction_guess = fraction_guess + step_guess;
                    }
                }
                ((RecordTable_guess*)&this->points_guess)->Store_guess(
                    this->points_guess.count_0000_guess, (const Record_guess*)&candidate_guess);
                previousX_guess = candidate_guess.x_guess;
                previousY_guess = candidate_guess.y_guess;
                previousZ_guess = candidate_guess.z_guess;
            }
        } while (remaining_guess > 1);
    }

    Vector3_guess* last_guess = (Vector3_guess*)this->points_guess.Lookup_guess(
        this->points_guess.count_0000_guess - 1);
    this->basePosition_guess = *last_guess;
    this->previousMarker_guess = this->points_guess.count_0000_guess - 1;
    this->interface_guess->Slot10_guess(interfaceValue_guess);
    this->state_guess = 1;
    this->marker_guess = 0;
    this->travel_guess = this->value100_guess - this->spread_guess;
    this->markerDistance_guess = 0.0f;
    unsigned int now_guess = GetTickCount();
    this->lastTick_guess = now_guess;
    ((CallbackBatch_guess*)this)->lastTick_guess = 0;
    this->prepareTick_guess = now_guess - 500;
    this->recentPosition_guess.x_guess = 3.402823466e+38f;
    this->recentPosition_guess.y_guess = 3.402823466e+38f;
    this->recentPosition_guess.z_guess = 3.402823466e+38f;
    this->valueD4_guess = this->initialValue_guess.x_guess;
    this->valueD8_guess = this->initialValue_guess.y_guess;
    this->valueDC_guess = this->initialValue_guess.z_guess;
    this->fade_guess = -1.0f;
    g_controller_guess->WavePlay_guess(0x50f, 0);
    pEverQuest->dsp_chat(pStringTable->getString(0x1a77, 0));
}

// Keeps the trail's end at the player: at most every 500 ms and after moving 25 units, cuts the trail at
// the first point within +0x74 of the player, then joins the player's position in ControlSegmentLength
// steps.
// FUNCTION: TITANIUM 0x004C2B02
// @early-stop: budget, structural ndiff=111
void PathFollower_guess::TrimToPlayer_guess(Vector3_guess* position_guess)
{
    Vector3_guess interpolated_guess;
    Vector3_guess difference_guess;
    Vector3_guess sample_guess;
    float fraction_guess;
    float step_guess;
    float end_guess;

    if (this->lastTick_guess - this->prepareTick_guess > 500 &&
        position_guess->Distance_guess(&this->recentPosition_guess) > 25.0f) {
        this->prepareTick_guess = this->lastTick_guess;
        this->recentPosition_guess = *position_guess;

        int count_guess = this->points_guess.count_0000_guess;
        int lastIndex_guess = count_guess - 1;
        if (this->marker_guess == 0) {
            this->marker_guess = lastIndex_guess;
        }
        while (count_guess > 1) {
            --count_guess;
            Vector3_guess* point_guess =
                (Vector3_guess*)this->points_guess.Lookup_guess(count_guess);
            if (point_guess->Distance_guess(position_guess) <= this->distanceLimit_guess) {
                this->marker_guess = count_guess;
            }
        }
        if (this->marker_guess + 1 < lastIndex_guess) {
            ((SlotGate_guess*)&this->points_guess)->SetPointCount_guess(this->marker_guess + 1);
            Vector3_guess* point_guess =
                (Vector3_guess*)this->points_guess.Lookup_guess(this->marker_guess);
            this->basePosition_guess = *point_guess;
            if (this->marker_guess < this->previousMarker_guess) {
                this->previousMarker_guess = this->marker_guess;
            }
        }
    }

    difference_guess.x_guess = position_guess->x_guess - this->basePosition_guess.x_guess;
    difference_guess.y_guess = position_guess->y_guess - this->basePosition_guess.y_guess;
    difference_guess.z_guess = position_guess->z_guess - this->basePosition_guess.z_guess;
    double distance_guess = Sqrt_guess((double)(
        difference_guess.x_guess * difference_guess.x_guess +
        difference_guess.y_guess * difference_guess.y_guess +
        difference_guess.z_guess * difference_guess.z_guess));

    if (distance_guess <= this->maxStep_guess) {
        Vector3_guess* point_guess =
            (Vector3_guess*)this->points_guess.Lookup_guess(this->points_guess.count_0000_guess - 1);
        *point_guess = *position_guess;
    } else {
        step_guess = (float)(this->maxStep_guess / distance_guess);
        fraction_guess = step_guess;
        end_guess = 1.0f - step_guess;
        if (fraction_guess < end_guess) {
            do {
                Vector3_guess* scaled_guess =
                    difference_guess.ScaleInto_guess(&interpolated_guess, fraction_guess);
                sample_guess.x_guess = scaled_guess->x_guess + this->basePosition_guess.x_guess;
                sample_guess.y_guess = scaled_guess->y_guess + this->basePosition_guess.y_guess;
                sample_guess.z_guess = scaled_guess->z_guess + this->basePosition_guess.z_guess;
                ((RecordTable_guess*)&this->points_guess)->Store_guess(
                    this->points_guess.count_0000_guess, (const Record_guess*)&sample_guess);
                fraction_guess = fraction_guess + step_guess;
            } while (fraction_guess < end_guess);
        }
        ((RecordTable_guess*)&this->points_guess)->Store_guess(
            this->points_guess.count_0000_guess, (const Record_guess*)position_guess);
        this->basePosition_guess = *position_guess;
    }
}

// Per frame: resets on a zone change; arrives within FinishRange (+0x10) of the destination; otherwise grows
// the visible band by GrowSpeed, trims the trail to the player, starts emitter rows and draws each segment,
// straight when shorter than the curve radius, else as a spline. Then animates frames, twist, scale, fade.
// FUNCTION: TITANIUM 0x004C2CDF
// @early-stop: budget, structural ndiff=117
void PathFollower_guess::ProcessPath_guess(Vector3_guess* position_guess)
{
    if (g_zoneCounter_guess != this->zone_guess) {
        ((CleanupTable_guess*)this)->Reset_guess();
        this->zone_guess = g_zoneCounter_guess;
    }
    if (this->interface_guess != 0 && this->state_guess != 0 && this->points_guess.count_0000_guess != 0) {
        this->elapsed_guess = GetTickCount() - this->lastTick_guess;
        if (this->fade_guess < 0.0f) {
            ((PositionTable_guess*)this)->DispatchPosition_guess(0,
                (Vector3_guess*)this->points_guess.Lookup_guess(this->points_guess.count_0000_guess - 1));
        }
        if (this->ready_guess != 0 ||
            ((CopyRecord_guess*)position_guess)->Distance_guess(&this->origin_guess) < this->range_guess) {
            ((EmitterSystem_guess*)this)->Arrive_guess();
        } else {
            ((TargetTable_guess*)this)->Dispatch_guess(0, 1);
            this->travel_guess = (float)this->elapsed_guess * this->speed_guess + this->travel_guess;
            if (this->travel_guess > this->limit_guess) {
                this->band_guess.Set_guess(this->limit_guess, this->limitHigh_guess);
            } else {
                this->band_guess.Set_guess(this->travel_guess, this->travel_guess + this->spread_guess);
            }

            float height_guess;
            if (g_connectionConfig_guess->flag256_guess != 0) {
                height_guess = position_guess->z_guess;
            } else {
                height_guess = g_world_guess->GetFloorHeight_guess(position_guess->x_guess,
                    position_guess->y_guess, position_guess->z_guess) + this->zOffset_guess;
            }
            Vector3_guess target_guess;
            target_guess.z_guess =
                fabs(height_guess - position_guess->z_guess) > 6.0f ? position_guess->z_guess : height_guess;
            target_guess.x_guess = position_guess->x_guess;
            target_guess.y_guess = position_guess->y_guess;

            this->TrimToPlayer_guess(position_guess);
            ((CallbackBatch_guess*)this)->SpawnEmitterRows_guess();
            this->interface_guess->Slot13_guess();

            float distance_guess = 0.0f;
            unsigned int misses_guess = 0;
            int last_guess = this->points_guess.count_0000_guess - 1;
            for (int i_guess = -1; i_guess < last_guess; ++i_guess) {
                Vector3_guess* from_guess =
                    (Vector3_guess*)this->points_guess.Lookup_guess(i_guess > 0 ? i_guess : 0);
                Vector3_guess* to_guess = (Vector3_guess*)this->points_guess.Lookup_guess(i_guess + 1);
                float segment_guess = ((CopyRecord_guess*)to_guess)->Distance_guess((CopyRecord_guess*)from_guess);
                if (i_guess + 1 == this->marker_guess) {
                    this->markerDistance_guess = distance_guess;
                }
                if (i_guess + 1 > this->marker_guess ||
                    (!((SweepTrack_guess*)this)->DrawTrailPoint_guess((CopyRecord_guess*)from_guess, (int)&target_guess,
                         distance_guess) &&
                     // After three invisible points in a row the rest is only measured, not drawn.
                     ++misses_guess > 2)) {
                    distance_guess = segment_guess + distance_guess;
                } else {
                    float radius_guess = this->radius_guess;
                    misses_guess = 0;
                    if (!IsScaleReady_guess(this->radiusScale_guess)) {
                        radius_guess = ((CopyRecord_guess*)position_guess)->Distance_guess(
                            (CopyRecord_guess*)from_guess) * radius_guess * this->radiusScale_guess;
                    }
                    if (segment_guess < radius_guess) {
                        segment_guess = segment_guess + distance_guess;
                        ((SweepTrack_guess*)this)->PlaceEmitterRows_guess(distance_guess, segment_guess, (int)from_guess,
                            (CopyRecord_guess*)from_guess, (CopyRecord_guess*)to_guess, (int)to_guess);
                        distance_guess = segment_guess;
                    } else {
                        Vector3_guess* before_guess = (Vector3_guess*)this->points_guess.Lookup_guess(
                            i_guess - 1 > 0 ? i_guess - 1 : 0);
                        Vector3_guess* after_guess = (Vector3_guess*)this->points_guess.Lookup_guess(
                            i_guess + 2 < last_guess ? i_guess + 2 : last_guess);
                        float radiusSquared_guess = radius_guess * radius_guess;

                        Vector3_guess inTangent_guess;
                        inTangent_guess.x_guess = before_guess->x_guess - from_guess->x_guess;
                        inTangent_guess.y_guess = before_guess->y_guess - from_guess->y_guess;
                        inTangent_guess.z_guess = before_guess->z_guess - from_guess->z_guess;
                        if (inTangent_guess.x_guess * inTangent_guess.x_guess +
                                inTangent_guess.y_guess * inTangent_guess.y_guess +
                                inTangent_guess.z_guess * inTangent_guess.z_guess < radiusSquared_guess) {
                            inTangent_guess.x_guess = from_guess->x_guess;
                            inTangent_guess.y_guess = from_guess->y_guess;
                            inTangent_guess.z_guess = from_guess->z_guess;
                        } else {
                            inTangent_guess.Normalize_guess();
                            float scale_guess = this->scale_guess;
                            inTangent_guess.x_guess *= scale_guess;
                            inTangent_guess.y_guess *= scale_guess;
                            inTangent_guess.z_guess *= scale_guess;
                            inTangent_guess.x_guess += from_guess->x_guess;
                            inTangent_guess.y_guess += from_guess->y_guess;
                            inTangent_guess.z_guess += from_guess->z_guess;
                        }

                        Vector3_guess outTangent_guess;
                        outTangent_guess.x_guess = after_guess->x_guess - to_guess->x_guess;
                        outTangent_guess.y_guess = after_guess->y_guess - to_guess->y_guess;
                        outTangent_guess.z_guess = after_guess->z_guess - to_guess->z_guess;
                        if (outTangent_guess.x_guess * outTangent_guess.x_guess +
                                outTangent_guess.y_guess * outTangent_guess.y_guess +
                                outTangent_guess.z_guess * outTangent_guess.z_guess < radiusSquared_guess) {
                            outTangent_guess.x_guess = to_guess->x_guess;
                            outTangent_guess.y_guess = to_guess->y_guess;
                            outTangent_guess.z_guess = to_guess->z_guess;
                        } else {
                            outTangent_guess.Normalize_guess();
                            float scale_guess = this->scale_guess;
                            outTangent_guess.x_guess *= scale_guess;
                            outTangent_guess.y_guess *= scale_guess;
                            outTangent_guess.z_guess *= scale_guess;
                            outTangent_guess.x_guess += to_guess->x_guess;
                            outTangent_guess.y_guess += to_guess->y_guess;
                            outTangent_guess.z_guess += to_guess->z_guess;
                        }

                        ((SweepTrack_guess*)this)->DrawCurvedSegment_guess((int)&target_guess, (int)&inTangent_guess,
                            (CopyRecord_guess*)from_guess, (CopyRecord_guess*)to_guess, (int)&outTangent_guess,
                            radius_guess / segment_guess, &distance_guess);
                    }
                }
            }

            unsigned int now_guess = GetTickCount();
            unsigned int delta_guess = now_guess - this->frameTick_guess;
            if (delta_guess > this->frameInterval_guess) {
                if (++this->frame_guess >= this->frames_guess.count_guess) {
                    this->frame_guess = 0;
                }
                this->frameTick_guess = now_guess;
            }
            if (this->frame_guess < this->frames_guess.count_guess) {
                this->interface_guess->Slot06_guess(*this->frames_guess.Get_guess(this->frame_guess));
            }

            float step_guess = (float)delta_guess;
            this->value164_guess += step_guess * this->rate160_guess;
            this->valueF4_guess += step_guess * this->rateF0_guess;
            this->valueAC_guess += step_guess * this->rateA8_guess;
            this->valueD4_guess += step_guess * this->rateC8_guess;
            this->valueD8_guess += step_guess * this->rateCC_guess;
            this->valueDC_guess += step_guess * this->rateD0_guess;
            if (this->fade_guess < 0.0f) {
                this->fade_guess = distance_guess;
            }
            this->fade_guess -= step_guess * this->fadeRate_guess;
            float margin_guess = distance_guess - this->fadeMargin_guess;
            this->fade_guess = this->fade_guess < margin_guess ? this->fade_guess : margin_guess;
            this->fade_guess = this->fade_guess > 0.0f ? this->fade_guess : 0.0f;

            PathSink_guess* sink_guess = this->interface_guess->Slot15_guess();
            if (sink_guess != 0) {
                int zero_guess = 0;
                sink_guess->Slot04_guess(&zero_guess);
            }
            sink_guess = this->interface_guess->Slot16_guess();
            if (sink_guess != 0) {
                int zero_guess = 0;
                sink_guess->Slot04_guess(&zero_guess);
            }
            this->lastTick_guess = now_guess;
            ((CallbackBatch_guess*)this)->HideEmittersBeyond_guess(distance_guess);
        }
    } else {
        this->lastTick_guess = GetTickCount();
    }
}

// Destructor of the client's growable array: frees the element buffer (+4) and zeroes it, the
// capacity (+8) and the count (+0). Many holders use it to empty their arrays.
// FUNCTION: TITANIUM 0x0050F3F6
OwnedVector_guess::~OwnedVector_guess()
{
    if (this->unknown04_guess != 0) {
        delete[] (int*)this->unknown04_guess;
    }
    this->unknown04_guess = 0;
    this->unknown08_guess = 0;
    this->count_guess = 0;
}
