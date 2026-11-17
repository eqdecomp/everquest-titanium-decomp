// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 37: a hint from compare/tumap.py.
// Skills and sound. First the skill table (SkillInfo_guess is one skill's definition, built per skill id)
// and
// the skill caps; then EqSoundManager: wave and MP3 assets from sounds\, voice\default\ and the snd*.pfs
// archives, the zone's music (<zone>.xmi) and emitters (<zone>.emt, or the older
// <zone>_sndbnk.eff/_sounds.eff),
// the global music cues and the mp3index.txt jukebox. EqSoundManagerView_guess views the same object.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include <stdio.h>
#include <string.h>
#include <new>
#include <string>

// EXTERNAL: TITANIUM 0x0060F5DE srand
void __cdecl srand(unsigned int seed);

struct Forwarded_guess {
    unsigned char reserved_00[0x2c];
    char disabled;                      // 0x2c
    unsigned char reserved_2d[3];
    // EXTERNAL: TITANIUM 0x004C5007 Forwarded_guess::SetPreference_guess
    void SetPreference_guess(int value);
    // EXTERNAL: TITANIUM 0x004C5033 Forwarded_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x004C503A Forwarded_guess::SetValue_guess
    void SetValue_guess(int value);
    // EXTERNAL: TITANIUM 0x004C505C Forwarded_guess::SetListenerLocation_guess
    void SetListenerLocation_guess(float first, float second, float third, float fourth);
    // EXTERNAL: TITANIUM 0x004C72E3 Forwarded_guess::Update_guess
    void Update_guess();
};

struct Part_guess {
    unsigned char reserved_00[0x30];
    float value_30;                     // 0x30
    float value_34;                     // 0x34
    unsigned char reserved_38[4];
    float value_3c;                     // 0x3c
    // EXTERNAL: TITANIUM 0x004C73B8 Part_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x004C72A8 Part_guess::Flush_guess
    void Flush_guess();
    // EXTERNAL: TITANIUM 0x004C6956 Part_guess::UpdateMusic_guess
    void UpdateMusic_guess();
    // EXTERNAL: TITANIUM 0x004C6AF2 Part_guess::Add_guess
    void Add_guess(int value);
    // EXTERNAL: TITANIUM 0x004C6B18 Part_guess::Remove_guess
    void Remove_guess(int value);
    // EXTERNAL: TITANIUM 0x004C60C9 Part_guess::SetFloat_guess
    void SetFloat_guess(float value);
    // EXTERNAL: TITANIUM 0x004C60D3 Part_guess::SetVolume_guess
    void SetVolume_guess(float value);
    // EXTERNAL: TITANIUM 0x004C6A37 Part_guess::SetMusicTrackVolume_guess
    void SetMusicTrackVolume_guess(float value);
};

struct Local_guess {
    union {
        int words[11];
        float values[11];
    };
    // EXTERNAL: TITANIUM 0x004C5C39 Local_guess::Initialize_guess
    void Initialize_guess();
};

struct IndexedItem_guess {
    // EXTERNAL: TITANIUM 0x004C5C2B IndexedItem_guess::SoundAsset_Stop_guess
    void SoundAsset_Stop_guess();
    // EXTERNAL: TITANIUM 0x004C5ADF IndexedItem_guess::IsPlaying_guess
    char IsPlaying_guess();
    // EXTERNAL: TITANIUM 0x004C5ABE IndexedItem_guess::GetType_guess
    int GetType_guess();
    // EXTERNAL: TITANIUM 0x004C5B16 IndexedItem_guess::SoundAsset_Play_guess
    void SoundAsset_Play_guess(Local_guess* value);
    // EXTERNAL: TITANIUM 0x004C5B12 IndexedItem_guess::GetName_guess
    char* GetName_guess();
};

struct IndexedEntry_guess {
    IndexedItem_guess* item;
    char enabled;
    unsigned char reserved_05[3];
};

struct Callback8_guess;
struct Callback0_guess;
struct Node_guess;
struct SoundMixer_guess;
struct SoundListener_guess;
struct Track_guess;

struct NodeHandleList_guess {
    // EXTERNAL: TITANIUM 0x004C69EA NodeHandleList_guess::RemoveAsset_guess
    void RemoveAsset_guess(Node_guess* target_guess);
};

struct EqSoundManagerView_guess {
    Part_guess* first_guess;
    Forwarded_guess* forwarded;
    Part_guess* second_guess;
    Part_guess* third_guess;
    unsigned char reserved_10[0x14];
    Node_guess* node24_guess;
    IndexedItem_guess* target;
    char disabled;
    unsigned char reserved_2d[3];
    int activeCount_guess;               // 0x30
    Callback8_guess* callbacks[1000];
    int callbackCount;
    Callback8_guess* filterA_guess;     // 0xfd8
    Callback8_guess* filterB_guess;     // 0xfdc
    int indoorEnvironment_0fe0_guess;                // 0xfe0
    int enclosedEnvironment_0fe4_guess;                // 0xfe4
    int outdoorEnvironment_0fe8_guess;                // 0xfe8
    float lastFloat;
    float waveVolume_0ff0_guess;
    char flag_ff4_guess;
    char visualState;
    char flag_ff6_guess;
    unsigned char reserved_ff7_guess;
    int filterValue_guess;              // 0xff8
    int mode;
    char filterFlag_guess;              // 0x1000
    unsigned char reserved_1001_guess[3];
    IndexedEntry_guess entries[1];
    unsigned char reserved_100c_guess[0x9cbc];
    IndexedItem_guess* indexedItems_guess[100];
    char indexNames_guess[100][32];
    int indexedItemCount_guess;

    void WaveStop_guess(int index);
    IndexedItem_guess* GetEntry_guess(int index);
    char GetEntryStatus_guess(int index);
    void SetHeight_guess(float height);
    void WavePlay_guess(int index, Local_guess* value);
    void SetMp3Volume_guess(float value);
    void ReplayMp3_guess(int value);
    void SetMusicSelection_guess(int value, char flag);
    void ProcessSound_guess();
    void ReleaseZoneMusic_guess();
    void Refresh_guess();
    int GetRoomType_guess();
    void SetRoomType_guess(int value);
    void SetListenerLocation_guess(float first, float second, float third, float fourth);
    void SetEnclosedEnvironment_guess();
    void SetVisualState_guess(char state);
    void SetMode_guess(char state);
    void SetIndoorEnvironment_guess();
    void SetOutdoorEnvironment_guess();
    void EmitterSetWind_guess(char value);
    void SetMixAhead_guess(int value);
    void ClearIndexedItems_guess();
    void ReleaseMp3Index_guess();
    void OldMp3Init_guess();
    void UnloadZoneWaves_guess();
    void RemoveAllEmitters_guess();
    void SetRealism_guess(float value);
    void SetWaveVolume_guess(float value);
    void SetMusicVolume_guess(float value);
    void SetEnvSounds_guess(char value);
    void SetWeatherLoopsMuted_guess(char value);
    IndexedItem_guess* GetAsset_guess(char* name);
    IndexedItem_guess* GetMp3Asset_guess(int index);
    Track_guess* CreateSoundEmitter_guess(int type, float value_c, float value_10, float value_14,
                                    int value_18, int value_1c, int value_20, float value_24,
                                    int value_28, int value_2c, int index);
    void PlayMp3_guess(char* name, int value);
    void WaveLoad_guess(char* name, int index, char flag);
};

struct Track_guess {
    unsigned char reserved_00[0x08];
    float field_08;
    unsigned char reserved_0c[0x0c];
    int field_18;
    int field_1c;
    int field_20;
    float field_24;
    float field_28;
    float field_2c;
    float field_30;
    float field_34;
    float field_38;
    float field_3c;
    int field_40;
    int field_44;
    int field_48[4];
    unsigned char reserved_58[0x128];
    // EXTERNAL: TITANIUM 0x004C6658 Track_guess::Track_guess
    Track_guess(Part_guess* part, IndexedItem_guess* item, int mode);
    // EXTERNAL: TITANIUM 0x004C6698 Track_guess::Track_guess
    Track_guess(Part_guess* part, Part_guess* item, int mode);
};

struct TextReceiver_guess {
    unsigned char reserved_00[0x58];
    char data[1];
    // EXTERNAL: TITANIUM 0x004C5D97 TextReceiver_guess::FUN_004c5d97_guess
    void FUN_004c5d97_guess(float first, float second, float third);
    // EXTERNAL: TITANIUM 0x004C5E03 TextReceiver_guess::SetAsset_guess
    void SetAsset_guess(IndexedItem_guess* item);
};

struct EqMobileEmitterView_guess {
    TextReceiver_guess* receiver;
    EqSoundManagerView_guess* owner;
    void Move_guess(float first, float second, float third);
    void SetTextAndItem_guess(int index, const char* text);
};

/* ---- sound part created on the stack at 0x0044BD94 (constructor 0x0044AB59) ---- */
struct SoundPart_guess {
    char name_guess[0x20];              // 0x00
    int field_20;                       // 0x20
    int field_24;                       // 0x24
    union {
        char field_28;                  // 0x28
        unsigned char field_28_unsigned;
    };
    unsigned char reserved_29[3];
    float field_2c;                     // 0x2c
    union {
        float field_30;                 // 0x30
        int field_30_bits;
    };
    int field_34;                       // 0x34
    int field_38;                       // 0x38
    int field_3c;                       // 0x3c
    union {
        float field_40;                 // 0x40
        int field_40_bits;
    };
    union {
        float field_44;                 // 0x44
        int field_44_bits;
    };
    float field_48;                     // 0x48
    union {
        float field_4c;                 // 0x4c
        int field_4c_bits;
    };
    union {
        float field_50;                 // 0x50
        int field_50_bits;
    };
    union {
        float field_54;                 // 0x54
        int field_54_bits;
    };
    float field_58;                     // 0x58
    int field_5c;                       // 0x5c
    int field_60;                       // 0x60
    int field_64;                       // 0x64
    SoundPart_guess();
    void Load_guess(char* text);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x00576930 RemoveCharacter_guess
void __cdecl RemoveCharacter_guess(char* text, int value);

// EXTERNAL: TITANIUM 0x00576D80 ReadInt_guess
int __cdecl ReadInt_guess(char** cursor, int delimiter);

// EXTERNAL: TITANIUM 0x00576D20 ReadString_guess
void __cdecl ReadString_guess(char* destination, int maxLength, char** cursor, int delimiter);

// EXTERNAL: TITANIUM 0x00576DC0 ReadFloat_guess
float __cdecl ReadFloat_guess(char** cursor, int delimiter);

struct Callback8_guess {
    unsigned char reserved_00_guess[0x08];
    float value08_guess;                // 0x08
    int value0c_guess;                  // 0x0c
    unsigned char reserved_10_guess[0x08];
    int value18_guess;                  // 0x18
    int value1c_guess;                  // 0x1c
    int value20_guess;                  // 0x20
    int value24_guess;                  // 0x24
    int value28_guess;                  // 0x28
    float value2c_guess;                // 0x2c
    union {
        float value30_guess;            // 0x30
        int bits30_guess;
    };
    union {
        float value34_guess;            // 0x34
        int bits34_guess;
    };
    int value38_guess;                  // 0x38
    float value3c_guess;                // 0x3c
    int value40_guess;                  // 0x40
    int value44_guess;                  // 0x44
    int first_guess;                    // 0x48
    int second_guess;                   // 0x4c
    int third_guess;                    // 0x50
    unsigned char reserved_54_guess[0x174 - 0x54];
    char value174_guess;                // 0x174
    unsigned char reserved_175_guess[0x180 - 0x175];
    // EXTERNAL: TITANIUM 0x004C6658 ??0Callback8_guess@@QAE@PAUSoundMixer_guess@@PAUIndexedItem_guess@@H@Z
    Callback8_guess(SoundMixer_guess* mixer, IndexedItem_guess* item, int flag);
    // EXTERNAL: TITANIUM 0x004C6698 ??0Callback8_guess@@QAE@PAUSoundMixer_guess@@PAUSoundListener_guess@@H@Z
    Callback8_guess(SoundMixer_guess* mixer, SoundListener_guess* listener, int index);
    // EXTERNAL: TITANIUM 0x004C5E40 Callback8_guess::SetEnabled_guess
    void SetEnabled_guess(char value);
    // EXTERNAL: TITANIUM 0x004C6092 Callback8_guess::Run_guess
    void Run_guess(void* value);
};

struct Callback0_guess {
    // EXTERNAL: TITANIUM 0x004C5AEB Callback0_guess::SetVolume_guess
    void SetVolume_guess(float value, int flags);
    // EXTERNAL: TITANIUM 0x004C529E Callback0_guess::Release_guess
    void Release_guess();
};

struct Holder_guess {
    unsigned char reserved_00[8];
    Callback8_guess* callback;
    unsigned char reserved_0c[0x20];
    char flag;
};

struct Monitor_guess {
    Callback0_guess* first;
    Holder_guess* second;
    void Detach_guess();
};

// EXTERNAL: TITANIUM 0x00577560 ReportAllocationError_guess
void __cdecl ReportAllocationError_guess(int code, const char* message, const char* detail);

struct RefCounted_guess {
    virtual void Delete_guess(int flags);
    unsigned int referenceCount;
    void* buffer;
    void Release_guess();
    void DestroyContents_guess();
    RefCounted_guess* DestroyAndFree_guess(unsigned char flags);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyString_guess
char* __cdecl CopyString_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// EXTERNAL: TITANIUM 0x00644054 ??_7Rc_guess@@6B@
struct Rc_guess {
    int refs;
    Rc_guess() : refs(0) {}
    virtual ~Rc_guess();
    void Release_guess() {
        if (--refs == 0) {
            delete this;
        }
    }
};

// EXTERNAL: TITANIUM 0x006440A4 ??_7SharedText_guess@@6B@
struct SharedTextBase_guess : Rc_guess {
    char* data;          // 0x8
    unsigned int length; // 0xc
    SharedTextBase_guess(unsigned int count) : length(count) {}
};

struct SharedText_guess : SharedTextBase_guess {
    SharedText_guess(char* text, unsigned int count) : SharedTextBase_guess(count) { data = text; }
    virtual ~SharedText_guess();
};

struct SharedString_guess;

struct SharedTextPtr_guess {
    SharedText_guess* shared;
    SharedTextPtr_guess(unsigned int length);
    // EXTERNAL: TITANIUM 0x0044B0C3 ??0SharedTextPtr_guess@@QAE@H@Z
    SharedTextPtr_guess(int length);
    // EXTERNAL: TITANIUM 0x0044B14A ??0SharedTextPtr_guess@@QAE@PBD@Z
    SharedTextPtr_guess(const char* text);
    SharedTextPtr_guess(const SharedString_guess& source);
    SharedTextPtr_guess(const SharedTextPtr_guess& other) : shared(other.shared) {
        if (shared != 0) {
            ++shared->refs;
        }
    }
    ~SharedTextPtr_guess() {
        if (shared != 0) {
            shared->Release_guess();
        }
    }
    // the tools' annotation parser cannot name `operator=`, so the assignment operator is spelled Assign
    SharedTextPtr_guess& Assign_guess(SharedTextPtr_guess other);

};

struct SharedString_guess {
    SharedTextPtr_guess buffer; // 0x0
    int cursor;                 // 0x4
    SharedString_guess(const char* text);
    SharedString_guess(const SharedString_guess& source);
    // EXTERNAL: TITANIUM 0x0044AD92 SharedString_guess::GetCountMinusOne_guess
    int GetCountMinusOne_guess() const;
    SharedString_guess& Assign_guess(const SharedString_guess& source);
};

struct SoundPath_guess {
    SharedString_guess value;
    SoundPath_guess(const char* name);
    ~SoundPath_guess();
};

struct DestroyDispatch_guess {
    virtual ~DestroyDispatch_guess();
};

struct RefCountHolder_guess {
    RefCounted_guess* value;
    void Release_guess();
};

struct Counted_guess {
    unsigned char reserved_00[0x0c];
    unsigned int count;
};

struct CountHolder_guess {
    Counted_guess* value;
    unsigned int Count() const { return value ? value->count : 0; }
    int GetCountMinusOne_guess();
};

struct ValueTables_guess {
    unsigned char reserved_00[0x0b];
    char flag_0b;                       // 0x0b
    int first[77];
    int second[36];
    int third[36];
    int fourth[36];

    int GetFirst_guess(int index);
    int GetSecond_guess(int index);
    int GetThird_guess(int index);
    int GetFourth_guess(int index);
};

struct QueueEntry_guess {
    const char* first;
    int second;
};

struct TextIndex_guess {
    int reserved_00;
    int* current_guess;
    // EXTERNAL: TITANIUM 0x0042639C TextIndex_guess::Find_guess
    int* Find_guess(const char* key);
    int* Resolve_guess(int* output, const char* key);
};

// EXTERNAL: TITANIUM 0x00402D20 CompareText_guess
bool __cdecl CompareText_guess(const char* first, const char* second);

#define g_queueCount_guess EQ_GLOBAL(unsigned int, 0x0099CE50)
#define g_queueEntries_guess EQ_ARRAY(QueueEntry_guess, 0x0099CC50)
#define g_radianScale_guess EQ_GLOBAL(double, 0x00644058)

struct SkillCapRow_guess {
    int levels[70];
};

struct SkillCapClass_guess {
    SkillCapRow_guess skills[100];
};

// [class - 1][skill][level - 1]
#define g_skillCaps_guess EQ_ARRAY(SkillCapClass_guess, 0x00698B30)

struct SkillInfo_guess {
    int id_00_guess;                    // 0x00
    int duration_04_guess;              // 0x04
    unsigned char flag_08_guess;        // 0x08
    unsigned char flag_09_guess;        // 0x09
    unsigned char flag_0a_guess;        // 0x0a
    unsigned char flag_0b_guess;        // 0x0b
    int values_0c_guess[36];            // 0x0c
    int minLevel_guess[36];             // 0x9c, by class
    int value_12c_guess;                // 0x12c
    int value_130_guess;                // 0x130
    int value_134_guess;                // 0x134
    int value_138_guess;                // 0x138
    float value_13c_guess;              // 0x13c
    int values_140_guess[36];           // 0x140
    int values_1d0_guess[36];           // 0x1d0
    int values_260_guess[36];           // 0x260
    int value_2f0_guess;                // 0x2f0
    SkillInfo_guess(int effectType_guess);
};

// Skill definition for skill id `effectType_guess`: name string (74 Frenzy = 5837, 59 Alchemy = 13850...),
// reuse time in ms, and the level each class gets it at (255 = never).
// FUNCTION: TITANIUM 0x00448D94
// @early-stop: budget, structural ndiff=1800
SkillInfo_guess::SkillInfo_guess(int effectType_guess) {
    int i;
    // Static data for one skill, by skill id (EQEmu numbering: 0 1H blunt ... 56 Make Poison, 58 Research, 74
    // Frenzy): +0 its name string, +4 a time in ms, and per class (1-16) the value at +0x9C, 0xFF meaning the
    // class has no use of it. Melee skills give casters the higher numbers there, so despite its name
    // (minLevel_guess) it is not a level; no client code reads it by class (doubt D02).
    for (i = 0; i < 36; ++i) {
        values_0c_guess[i] = 0;
        minLevel_guess[i] = 0xff;
        values_140_guess[i] = 0;
        values_1d0_guess[i] = 0;
        values_260_guess[i] = 0;
    }
    value_13c_guess = 0.0f;
    flag_0a_guess = 0;
    flag_09_guess = 0;
    value_134_guess = 0x74;
    value_138_guess = 0x75;
    flag_0b_guess = 1;
    value_2f0_guess = 0;
    duration_04_guess = 0;
    value_12c_guess = 0;
    switch (effectType_guess) {
    // Skills with a timer (Frenzy 15 s, skills 55-59 10-12 s) and their few classes.
    case 0x4a:
        id_00_guess = 0x16cd;
        duration_04_guess = 15000;
        flag_08_guess = 0;
        value_130_guess = 10;
        minLevel_guess[16] = 8;
        flag_09_guess = 1;
        flag_0a_guess = 2;
        value_13c_guess = 0.05f;
        break;
    case 0x3b:
        id_00_guess = 0x361a;
        minLevel_guess[10] = 4;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_12c_guess = 1;
        break;
    case 0x3a:
        id_00_guess = 0x361b;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_12c_guess = 1;
        minLevel_guess[11] = 1; minLevel_guess[12] = 1; minLevel_guess[13] = 1; minLevel_guess[14] = 1;
        break;
    case 0x39:
        id_00_guess = 0x361c;
        flag_0b_guess = 0;
        minLevel_guess[1] = 2; minLevel_guess[2] = 2; minLevel_guess[3] = 2; minLevel_guess[5] = 2; minLevel_guess[4] = 2; minLevel_guess[6] = 2; minLevel_guess[7] = 2; minLevel_guess[8] = 2;
        minLevel_guess[9] = 2; minLevel_guess[10] = 2; minLevel_guess[11] = 2; minLevel_guess[12] = 2; minLevel_guess[13] = 2; minLevel_guess[14] = 2; minLevel_guess[15] = 2; minLevel_guess[16] = 2;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_12c_guess = 1;
        break;
    case 0x38:
        id_00_guess = 0x361d;
        minLevel_guess[9] = 2;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_12c_guess = 1;
        break;
    case 0x37:
        id_00_guess = 0x361e;
        duration_04_guess = 12000;
        flag_0b_guess = 1;
        flag_09_guess = 1;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 8; minLevel_guess[2] = 8; minLevel_guess[3] = 8; minLevel_guess[5] = 8; minLevel_guess[4] = 8; minLevel_guess[6] = 8; minLevel_guess[7] = 8; minLevel_guess[8] = 8;
        minLevel_guess[9] = 8; minLevel_guess[10] = 8; minLevel_guess[15] = 8; minLevel_guess[16] = 8;
        value_134_guess = 0x68;
        value_138_guess = 0x69;
        value_12c_guess = 1;
        minLevel_guess[11] = 8; minLevel_guess[12] = 8; minLevel_guess[13] = 8; minLevel_guess[14] = 8;
        break;
    // Weapon skills: every class has a value, 15 for most, the shaman (10) 17, the cleric (2) 18 and the int
    // casters (11-14) 20.
    case 0:
        id_00_guess = 0x361f;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_13c_guess = 0.1f;
        minLevel_guess[2] = 0x12; minLevel_guess[6] = 0x0f; minLevel_guess[10] = 0x11; minLevel_guess[15] = 0x0f; minLevel_guess[16] = 0x0f;
        minLevel_guess[1] = 0x0f; minLevel_guess[3] = 0x0f; minLevel_guess[5] = 0x0f; minLevel_guess[4] = 0x0f; minLevel_guess[7] = 0x0f; minLevel_guess[8] = 0x0f; minLevel_guess[9] = 0x0f;
        minLevel_guess[11] = 0x14; minLevel_guess[12] = 0x14; minLevel_guess[13] = 0x14; minLevel_guess[14] = 0x14;
        break;
    case 1:
        id_00_guess = 0x3620;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_13c_guess = 0.1f;
        minLevel_guess[2] = 0x12; minLevel_guess[6] = 0x0f; minLevel_guess[10] = 0x11; minLevel_guess[15] = 0x0f; minLevel_guess[16] = 0x0f;
        minLevel_guess[1] = 0x0f; minLevel_guess[3] = 0x0f; minLevel_guess[5] = 0x0f; minLevel_guess[4] = 0x0f; minLevel_guess[7] = 0x0f; minLevel_guess[8] = 0x0f; minLevel_guess[9] = 0x0f;
        minLevel_guess[11] = 0x14; minLevel_guess[12] = 0x14; minLevel_guess[13] = 0x14; minLevel_guess[14] = 0x14;
        break;
    case 2:
    case 3:
        id_00_guess = effectType_guess == 2 ? 0x3621 : 0x3622;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_13c_guess = 0.2f;
        minLevel_guess[1] = 0x0c; minLevel_guess[2] = 0x11; minLevel_guess[3] = 0x0c; minLevel_guess[5] = 0x0c; minLevel_guess[4] = 0x0c; minLevel_guess[6] = 0x11; minLevel_guess[7] = 0x0c;
        minLevel_guess[8] = 0x0c; minLevel_guess[9] = 0x0c; minLevel_guess[10] = 0x0f; minLevel_guess[11] = 0x13; minLevel_guess[12] = 0x13; minLevel_guess[13] = 0x13; minLevel_guess[14] = 0x13;
        minLevel_guess[15] = 0x0c; minLevel_guess[16] = 0x0c;
        break;
    case 4:
    case 5:
    case 0x0e:
    case 0x12:
    case 0x18:
        switch (effectType_guess) {
        case 4: id_00_guess = 0x3623; break;
        case 5: id_00_guess = 0x3625; break;
        case 0x0e: id_00_guess = 0x3633; break;
        case 0x12: id_00_guess = 0x3637; break;
        default: id_00_guess = 0x363d; break;
        }
        minLevel_guess[1] = 8; minLevel_guess[2] = 6; minLevel_guess[3] = 2; minLevel_guess[5] = 2; minLevel_guess[4] = 2; minLevel_guess[6] = 6; minLevel_guess[7] = 8; minLevel_guess[8] = 8; minLevel_guess[9] = 8;
        minLevel_guess[10] = 6; minLevel_guess[11] = 6; minLevel_guess[12] = 6; minLevel_guess[13] = 6; minLevel_guess[14] = 6;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[15] = 6; minLevel_guess[16] = 6;
        break;
    case 0x42:
        id_00_guess = 0x3624;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 1; minLevel_guess[2] = 1; minLevel_guess[3] = 1; minLevel_guess[5] = 1; minLevel_guess[4] = 1; minLevel_guess[6] = 1; minLevel_guess[7] = 1; minLevel_guess[8] = 1;
        minLevel_guess[9] = 1; minLevel_guess[10] = 1; minLevel_guess[15] = 1; minLevel_guess[16] = 1;
        value_134_guess = 0x68;
        value_138_guess = 0x69;
        minLevel_guess[11] = 1; minLevel_guess[12] = 1; minLevel_guess[13] = 1; minLevel_guess[14] = 1;
        break;
    case 6:
        id_00_guess = 0x3626;
        duration_04_guess = 60000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[9] = 2;
        value_134_guess = 0x96;
        value_138_guess = 0x97;
        break;
    case 7:
        id_00_guess = 0x3627;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[9] = 4;
        value_13c_guess = 0.15f;
        break;
    case 8:
        id_00_guess = 0x3628;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 1;
        minLevel_guess[9] = 7;
        value_134_guess = 0x6e;
        value_138_guess = 0x6f;
        value_13c_guess = 0.3f;
        flag_09_guess = 1;
        flag_0a_guess = 2;
        break;
    case 0x3c:
    case 0x41:
        id_00_guess = effectType_guess == 0x3c ? 0x3629 : 0x3631;
        flag_0b_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 3; minLevel_guess[2] = 3; minLevel_guess[3] = 3; minLevel_guess[5] = 3; minLevel_guess[4] = 3; minLevel_guess[6] = 3; minLevel_guess[7] = 3; minLevel_guess[8] = 3;
        minLevel_guess[9] = 3; minLevel_guess[10] = 3; minLevel_guess[15] = 3; minLevel_guess[16] = 3;
        value_134_guess = 0x68;
        value_138_guess = 0x69;
        value_12c_guess = 1;
        minLevel_guess[11] = 3; minLevel_guess[12] = 3; minLevel_guess[13] = 3; minLevel_guess[14] = 3;
        break;
    case 9:
    case 0x10:
        if (effectType_guess == 9) {
            id_00_guess = 0x362a;
            value_134_guess = 0x7e;
            value_138_guess = 0x7f;
        } else {
            id_00_guess = 0x3635;
            value_134_guess = 100;
            value_138_guess = 101;
        }
        duration_04_guess = 10000;
        minLevel_guess[1] = 2; minLevel_guess[2] = 2; minLevel_guess[3] = 2; minLevel_guess[5] = 2; minLevel_guess[4] = 2; minLevel_guess[6] = 2; minLevel_guess[7] = 2; minLevel_guess[8] = 2;
        minLevel_guess[9] = 2; minLevel_guess[10] = 2; minLevel_guess[11] = 2; minLevel_guess[12] = 2; minLevel_guess[13] = 2; minLevel_guess[14] = 2; minLevel_guess[15] = 2; minLevel_guess[16] = 2;
        flag_08_guess = 0;
        value_130_guess = 0;
        flag_09_guess = 1;
        flag_0a_guess = 1;
        break;
    case 0x0a:
        id_00_guess = 0x362b;
        duration_04_guess = 8000;
        flag_08_guess = 0;
        value_130_guess = 2;
        minLevel_guess[1] = 8; minLevel_guess[2] = 8; minLevel_guess[3] = 8; minLevel_guess[5] = 8;
        value_134_guess = 0x66;
        value_138_guess = 0x67;
        value_13c_guess = 0.3f;
        flag_09_guess = 1;
        flag_0a_guess = 2;
        break;
    case 0x43:
        id_00_guess = 0x362c;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 0x1c; minLevel_guess[2] = 0x1c; minLevel_guess[3] = 0x1c; minLevel_guess[5] = 0x1c; minLevel_guess[4] = 0x1c; minLevel_guess[6] = 0x1c; minLevel_guess[7] = 0x1c;
        minLevel_guess[8] = 0x1c; minLevel_guess[9] = 0x1c; minLevel_guess[10] = 0x1c; minLevel_guess[15] = 0x1c; minLevel_guess[16] = 0x1c;
        flag_09_guess = 1;
        value_134_guess = 0x7a;
        value_138_guess = 0x7b;
        minLevel_guess[11] = 0x1c; minLevel_guess[12] = 0x1c; minLevel_guess[13] = 0x1c; minLevel_guess[14] = 0x1c;
        break;
    case 0x48:
        value_13c_guess = 0.0f;
        id_00_guess = 0x362d;
        duration_04_guess = 7500;
        value_134_guess = 0x9e;
        value_138_guess = 0x9f;
        flag_08_guess = 0;
        value_130_guess = 0;
        flag_09_guess = 1;
        flag_0a_guess = 1;
        break;
    case 0x0b:
        id_00_guess = 0x362f;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[7] = 0x0c;
        minLevel_guess[15] = 0x0c;
        break;
    case 0x0c:
        id_00_guess = 0x3630;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[8] = 0x14;
        break;
    case 0x0f:
        id_00_guess = 0x3634;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 0x0f; minLevel_guess[2] = 0x11; minLevel_guess[3] = 0x11; minLevel_guess[5] = 0x11; minLevel_guess[4] = 0x11; minLevel_guess[6] = 0x11; minLevel_guess[7] = 0x0f;
        minLevel_guess[8] = 0x11; minLevel_guess[9] = 0x0f; minLevel_guess[10] = 0x11; minLevel_guess[11] = 0x11; minLevel_guess[12] = 0x11; minLevel_guess[13] = 0x11; minLevel_guess[14] = 0x11;
        minLevel_guess[15] = 0x11; minLevel_guess[16] = 0x11;
        break;
    case 0x11:
        id_00_guess = 0x3636;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 0x14; minLevel_guess[2] = 0x14; minLevel_guess[3] = 0x14; minLevel_guess[5] = 0x14; minLevel_guess[4] = 0x14; minLevel_guess[6] = 0x14; minLevel_guess[7] = 0x14;
        minLevel_guess[8] = 0x14; minLevel_guess[9] = 0x14; minLevel_guess[10] = 0x14; minLevel_guess[15] = 0x14; minLevel_guess[16] = 0x14;
        flag_09_guess = 1;
        value_134_guess = 0x74;
        value_138_guess = 0x75;
        minLevel_guess[11] = 0x14; minLevel_guess[12] = 0x14; minLevel_guess[13] = 0x14; minLevel_guess[14] = 0x14;
        break;
    case 0x14:
        minLevel_guess[2] = 0x14; minLevel_guess[6] = 0x14; minLevel_guess[10] = 0x14;
        id_00_guess = 0x3639;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[15] = 0x18; minLevel_guess[16] = 0x18;
        minLevel_guess[1] = 0x0e; minLevel_guess[3] = 0x0e; minLevel_guess[5] = 0x0e; minLevel_guess[4] = 0x0e; minLevel_guess[7] = 0x0e; minLevel_guess[8] = 0x0e; minLevel_guess[9] = 0x0e;
        minLevel_guess[11] = 0x18; minLevel_guess[12] = 0x18; minLevel_guess[13] = 0x18; minLevel_guess[14] = 0x18;
        break;
    case 0x16:
        minLevel_guess[2] = 0x14; minLevel_guess[6] = 0x14; minLevel_guess[10] = 0x14;
        id_00_guess = 0x363b;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 0x12; minLevel_guess[3] = 0x12; minLevel_guess[5] = 0x12; minLevel_guess[4] = 0x12; minLevel_guess[7] = 0x10; minLevel_guess[8] = 0x12; minLevel_guess[9] = 0x12;
        minLevel_guess[15] = 0x12; minLevel_guess[16] = 0x12;
        minLevel_guess[11] = 0x18; minLevel_guess[12] = 0x18; minLevel_guess[13] = 0x18; minLevel_guess[14] = 0x18;
        break;
    case 0x1c:
        minLevel_guess[2] = 0x1d; minLevel_guess[6] = 0x1d;
        id_00_guess = 0x3642;
        duration_04_guess = 3500;
        value_130_guess = 2;
        minLevel_guess[1] = 0x19; minLevel_guess[3] = 0x19; minLevel_guess[5] = 0x19; minLevel_guess[4] = 0x19; minLevel_guess[8] = 0x19; minLevel_guess[9] = 0x19; minLevel_guess[10] = 0x1b;
        minLevel_guess[11] = 0x22; minLevel_guess[12] = 0x22; minLevel_guess[13] = 0x22; minLevel_guess[14] = 0x22; minLevel_guess[16] = 0x19;
        flag_08_guess = 0;
        minLevel_guess[7] = 0x12; minLevel_guess[15] = 0x12;
        value_13c_guess = 0.1f;
        break;
    case 0x1d:
        id_00_guess = 0x3643;
        value_134_guess = 0x7c;
        value_138_guess = 0x7d;
        minLevel_guess[9] = 3;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 4; minLevel_guess[2] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[6] = 4; minLevel_guess[7] = 4; minLevel_guess[8] = 4;
        minLevel_guess[10] = 4; minLevel_guess[11] = 4; minLevel_guess[12] = 4; minLevel_guess[13] = 4; minLevel_guess[14] = 4; minLevel_guess[15] = 4; minLevel_guess[16] = 4;
        flag_09_guess = 1;
        break;
    case 0x20:
        id_00_guess = 0x3647;
        duration_04_guess = 360000;
        minLevel_guess[1] = 4; minLevel_guess[2] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[6] = 4; minLevel_guess[7] = 4; minLevel_guess[8] = 4;
        minLevel_guess[9] = 4; minLevel_guess[10] = 4; minLevel_guess[11] = 4; minLevel_guess[12] = 4; minLevel_guess[13] = 4; minLevel_guess[14] = 4; minLevel_guess[15] = 4; minLevel_guess[16] = 4;
        value_134_guess = 0x98;
        value_138_guess = 0x99;
        flag_08_guess = 0;
        value_130_guess = 0;
        flag_09_guess = 1;
        flag_0a_guess = 1;
        break;
    case 0x21:
        id_00_guess = 0x3648;
        minLevel_guess[1] = 0x0f; minLevel_guess[2] = 0x12; minLevel_guess[3] = 0x0f; minLevel_guess[5] = 0x0f; minLevel_guess[4] = 0x0f; minLevel_guess[6] = 0x12; minLevel_guess[7] = 0x0f;
        minLevel_guess[8] = 0x0f; minLevel_guess[9] = 0x0f; minLevel_guess[10] = 0x10; minLevel_guess[11] = 0x12; minLevel_guess[12] = 0x12; minLevel_guess[13] = 0x12; minLevel_guess[14] = 0x12;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[15] = 0x0f; minLevel_guess[16] = 0x0f;
        break;
    case 0x24:
        id_00_guess = 0x364c;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_13c_guess = 0.05f;
        minLevel_guess[2] = 0x12; minLevel_guess[6] = 0x0f; minLevel_guess[10] = 0x11; minLevel_guess[15] = 0x0f; minLevel_guess[16] = 0x0f;
        minLevel_guess[1] = 0x0f; minLevel_guess[3] = 0x0f; minLevel_guess[5] = 0x0f; minLevel_guess[4] = 0x0f; minLevel_guess[7] = 0x0f; minLevel_guess[8] = 0x0f; minLevel_guess[9] = 0x0f;
        minLevel_guess[11] = 0x14; minLevel_guess[12] = 0x14; minLevel_guess[13] = 0x14; minLevel_guess[14] = 0x14;
        break;
    case 0x49:
        id_00_guess = 0x364e;
        duration_04_guess = 6000;
        flag_08_guess = 0;
        value_130_guess = 0;
        flag_0a_guess = 1;
        flag_09_guess = 1;
        value_134_guess = 0xa0;
        value_138_guess = 0xa1;
        minLevel_guess[1] = 4; minLevel_guess[2] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[6] = 4; minLevel_guess[7] = 4; minLevel_guess[8] = 4;
        minLevel_guess[9] = 4; minLevel_guess[10] = 4; minLevel_guess[11] = 4; minLevel_guess[12] = 4; minLevel_guess[13] = 4; minLevel_guess[14] = 4; minLevel_guess[15] = 4; minLevel_guess[16] = 4;
        break;
    case 0x0d:
    case 0x13:
    case 0x1f:
    case 0x22:
    case 0x25:
    case 0x27:
    case 0x29:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x36:
    case 0x46:
        switch (effectType_guess) {
        // One value shared by all 16 classes: the inner switch only picks the name and that value.
        case 0x0d: id_00_guess = 0x3632; i = 7; break;
        case 0x13: id_00_guess = 0x3638; i = 0x0c; break;
        case 0x1f: id_00_guess = 0x3646; i = 10; break;
        case 0x22: id_00_guess = 0x3649; i = 0x0c; break;
        case 0x25: id_00_guess = 0x364f; i = 0x0c; break;
        case 0x27: id_00_guess = 0x3651; i = 5; break;
        case 0x29: id_00_guess = 0x3654; i = 0x14; break;
        case 0x2b: id_00_guess = 0x3656; i = 0x1c; break;
        case 0x2c: id_00_guess = 0x3657; i = 0x1c; break;
        case 0x2d: id_00_guess = 0x3658; i = 0x1c; break;
        case 0x2e: id_00_guess = 0x3659; i = 0x1c; break;
        case 0x2f: id_00_guess = 0x365a; i = 0x1c; break;
        case 0x31: id_00_guess = 0x365c; i = 0x14; break;
        case 0x32: id_00_guess = 0x365d; i = 8; break;
        case 0x36: id_00_guess = 0x3663; i = 0x14; break;
        default: id_00_guess = 0x364a; i = 0x14; break;
        }
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = i; minLevel_guess[2] = i; minLevel_guess[3] = i; minLevel_guess[5] = i; minLevel_guess[4] = i; minLevel_guess[6] = i; minLevel_guess[7] = i; minLevel_guess[8] = i;
        minLevel_guess[9] = i; minLevel_guess[10] = i; minLevel_guess[11] = i; minLevel_guess[12] = i; minLevel_guess[13] = i; minLevel_guess[14] = i; minLevel_guess[15] = i; minLevel_guess[16] = i;
        break;
    case 0x15:
    case 0x26:
    case 0x17:
    case 0x1a:
    case 0x1e:
    case 0x34:
        switch (effectType_guess) {
        case 0x15:
            id_00_guess = 0x363a;
            duration_04_guess = 6200;
            value_130_guess = 0x0c;
            value_134_guess = 0x8a;
            value_138_guess = 0x8b;
            value_13c_guess = 0.25f;
            i = 9;
            break;
        case 0x26:
            id_00_guess = 0x3650;
            duration_04_guess = 8500;
            value_130_guess = 5;
            value_134_guess = 0x82;
            value_138_guess = 0x83;
            value_13c_guess = 0.25f;
            i = 9;
            break;
        case 0x17:
            id_00_guess = 0x363c;
            duration_04_guess = 6000;
            value_130_guess = 7;
            value_134_guess = 0x86;
            value_138_guess = 0x87;
            value_13c_guess = 0.2f;
            i = 9;
            break;
        case 0x1a:
            id_00_guess = 0x3640;
            duration_04_guess = 8500;
            value_130_guess = 0x19;
            value_134_guess = 0x80;
            value_138_guess = 0x81;
            value_13c_guess = 0.4f;
            i = 8;
            break;
        case 0x1e:
            id_00_guess = 0x3645;
            duration_04_guess = 8000;
            value_130_guess = 3;
            value_134_guess = 0x84;
            value_138_guess = 0x85;
            value_13c_guess = 0.2f;
            i = 8;
            break;
        default:
            id_00_guess = 0x3660;
            duration_04_guess = 5500;
            value_130_guess = 4;
            value_134_guess = 0x88;
            value_138_guess = 0x89;
            value_13c_guess = 0.2f;
            i = 9;
            break;
        }
        flag_08_guess = 0;
        minLevel_guess[1] = i; minLevel_guess[2] = i; minLevel_guess[3] = i; minLevel_guess[5] = i; minLevel_guess[4] = i; minLevel_guess[6] = i; minLevel_guess[7] = i; minLevel_guess[8] = i;
        minLevel_guess[9] = i; minLevel_guess[10] = i; minLevel_guess[11] = i; minLevel_guess[12] = i; minLevel_guess[13] = i; minLevel_guess[14] = i; minLevel_guess[15] = i; minLevel_guess[16] = i;
        flag_09_guess = 1;
        flag_0a_guess = 2;
        break;
    case 0x19:
        id_00_guess = 0x363e;
        value_130_guess = 0;
        value_134_guess = 0x90;
        value_138_guess = 0x91;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        minLevel_guess[1] = 8; minLevel_guess[2] = 8; minLevel_guess[3] = 8; minLevel_guess[5] = 8; minLevel_guess[4] = 8; minLevel_guess[6] = 8; minLevel_guess[7] = 8; minLevel_guess[8] = 8;
        minLevel_guess[9] = 8; minLevel_guess[10] = 8; minLevel_guess[11] = 8; minLevel_guess[12] = 8; minLevel_guess[13] = 8; minLevel_guess[14] = 8; minLevel_guess[15] = 8; minLevel_guess[16] = 8;
        flag_09_guess = 1;
        flag_0a_guess = 1;
        break;
    case 0x1b:
        id_00_guess = 0x3641;
        duration_04_guess = 100000;
        value_134_guess = 0x76;
        value_138_guess = 0x77;
        flag_08_guess = 0;
        minLevel_guess[1] = 0x10; minLevel_guess[2] = 0x10; minLevel_guess[3] = 0x10; minLevel_guess[5] = 0x10; minLevel_guess[4] = 0x10; minLevel_guess[6] = 0x10; minLevel_guess[7] = 0x10;
        minLevel_guess[8] = 0x10; minLevel_guess[9] = 0x10; minLevel_guess[10] = 0x10; minLevel_guess[11] = 0x10; minLevel_guess[12] = 0x10; minLevel_guess[13] = 0x10; minLevel_guess[14] = 0x10;
        minLevel_guess[15] = 0x10; minLevel_guess[16] = 0x10;
        flag_09_guess = 1;
        break;
    case 0x23:
        id_00_guess = 0x364b;
        duration_04_guess = 10000;
        value_130_guess = 0;
        value_134_guess = 0x94;
        value_138_guess = 0x95;
        flag_08_guess = 0;
        minLevel_guess[1] = 0x10; minLevel_guess[2] = 0x10; minLevel_guess[3] = 0x10; minLevel_guess[5] = 0x10; minLevel_guess[4] = 0x10; minLevel_guess[6] = 0x10; minLevel_guess[7] = 0x10;
        minLevel_guess[8] = 8; minLevel_guess[9] = 4; minLevel_guess[10] = 0x10; minLevel_guess[11] = 0x10; minLevel_guess[12] = 0x10; minLevel_guess[13] = 0x10; minLevel_guess[14] = 0x10;
        minLevel_guess[15] = 0x10; minLevel_guess[16] = 0x10;
        flag_09_guess = 1;
        break;
    case 0x28:
    case 0x35:
        if (effectType_guess == 0x28) {
            id_00_guess = 0x3652;
            duration_04_guess = 2000;
            flag_0b_guess = 0;
            value_134_guess = 0x70;
            value_138_guess = 0x71;
            i = 7;
        } else {
            id_00_guess = 0x3661;
            duration_04_guess = 10000;
            value_134_guess = 0x78;
            value_138_guess = 0x79;
            i = 8;
        }
        value_130_guess = 0;
        flag_08_guess = 0;
        minLevel_guess[1] = i; minLevel_guess[2] = i; minLevel_guess[3] = i; minLevel_guess[5] = i; minLevel_guess[4] = i; minLevel_guess[6] = i; minLevel_guess[7] = i; minLevel_guess[8] = i;
        minLevel_guess[9] = i; minLevel_guess[10] = i; minLevel_guess[11] = i; minLevel_guess[12] = i; minLevel_guess[13] = i; minLevel_guess[14] = i; minLevel_guess[15] = i; minLevel_guess[16] = i;
        flag_09_guess = 1;
        break;
    case 0x2a:
    case 0x30:
        if (effectType_guess == 0x2a) {
            id_00_guess = 0x3655;
            value_134_guess = 0x6a;
            value_138_guess = 0x6b;
            minLevel_guess[9] = 3;
        } else {
            id_00_guess = 0x365b;
            value_134_guess = 0x92;
            value_138_guess = 0x93;
            minLevel_guess[9] = 4;
        }
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 4; minLevel_guess[2] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[6] = 4; minLevel_guess[7] = 4; minLevel_guess[8] = 4;
        minLevel_guess[10] = 4; minLevel_guess[11] = 4; minLevel_guess[12] = 4; minLevel_guess[13] = 4; minLevel_guess[14] = 4; minLevel_guess[15] = 4; minLevel_guess[16] = 4;
        flag_09_guess = 1;
        break;
    case 0x33:
        id_00_guess = 0x365f;
        duration_04_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 2; minLevel_guess[2] = 4; minLevel_guess[3] = 4; minLevel_guess[5] = 4; minLevel_guess[4] = 4; minLevel_guess[6] = 4; minLevel_guess[8] = 4; minLevel_guess[9] = 2;
        minLevel_guess[10] = 4; minLevel_guess[11] = 4; minLevel_guess[12] = 4; minLevel_guess[13] = 4; minLevel_guess[14] = 4; minLevel_guess[16] = 2;
        flag_08_guess = 0;
        minLevel_guess[7] = 2;
        minLevel_guess[15] = 2;
        value_13c_guess = 0.1f;
        break;
    case 0x3d:
    case 0x3f:
    case 0x40:
    case 0x44:
    case 0x45:
        switch (effectType_guess) {
        case 0x3d: id_00_guess = 0x365e; i = 2; break;
        case 0x3f: id_00_guess = 0x362e; i = 2; break;
        case 0x40: id_00_guess = 0x363f; i = 4; break;
        case 0x44: id_00_guess = 0x3644; i = 4; break;
        default: id_00_guess = 0x364d; i = 4; break;
        }
        minLevel_guess[1] = i; minLevel_guess[2] = i; minLevel_guess[3] = i; minLevel_guess[5] = i; minLevel_guess[4] = i; minLevel_guess[6] = i; minLevel_guess[7] = i; minLevel_guess[8] = i;
        minLevel_guess[9] = i; minLevel_guess[10] = i; minLevel_guess[11] = i; minLevel_guess[12] = i; minLevel_guess[13] = i; minLevel_guess[14] = i; minLevel_guess[15] = i; minLevel_guess[16] = i;
        flag_0b_guess = 0;
        value_134_guess = 0x68;
        value_138_guess = 0x69;
        flag_08_guess = 0;
        value_130_guess = 0;
        value_12c_guess = 1;
        break;
    case 0x3e:
        id_00_guess = 0x3653;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        value_130_guess = 0;
        minLevel_guess[1] = 8; minLevel_guess[2] = 8; minLevel_guess[3] = 8; minLevel_guess[5] = 8; minLevel_guess[4] = 8; minLevel_guess[6] = 8; minLevel_guess[7] = 8; minLevel_guess[8] = 8;
        minLevel_guess[9] = 8; minLevel_guess[10] = 8; minLevel_guess[11] = 8; minLevel_guess[12] = 8; minLevel_guess[13] = 8; minLevel_guess[14] = 8; minLevel_guess[15] = 8; minLevel_guess[16] = 8;
        flag_09_guess = 1;
        value_134_guess = 0x9c;
        value_138_guess = 0x9d;
        break;
    case 0x47:
        id_00_guess = 0x3662;
        value_130_guess = 2;
        minLevel_guess[7] = 4;
        minLevel_guess[8] = 6;
        minLevel_guess[9] = 2;
        minLevel_guess[16] = 4;
        value_134_guess = 0x9a;
        value_138_guess = 0x9b;
        value_13c_guess = 2.5f;
        duration_04_guess = 10000;
        flag_08_guess = 0;
        minLevel_guess[1] = 0x0c; minLevel_guess[2] = 0x0c; minLevel_guess[3] = 0x0c; minLevel_guess[5] = 0x0c; minLevel_guess[4] = 0x0c; minLevel_guess[6] = 0x0c; minLevel_guess[10] = 0x0c;
        minLevel_guess[15] = 0x0c; minLevel_guess[11] = 0x0c; minLevel_guess[12] = 0x0c; minLevel_guess[13] = 0x0c; minLevel_guess[14] = 0x0c;
        flag_09_guess = 1;
        flag_0a_guess = 1;
        break;
    default:
        id_00_guess = 0x4c0;
        duration_04_guess = 0;
        flag_08_guess = 0;
        value_130_guess = 0;
        for (i = 1; i <= 16; ++i) {
            minLevel_guess[i] = 0;
        }
        break;
    }
    if (effectType_guess < 0x4b) {
        // first level with a nonzero cap, and the caps at levels 50, 65 and 70
        for (i = 1; i < 36; ++i) {
            const int* caps_guess = g_skillCaps_guess[i - 1].skills[effectType_guess].levels;
            values_140_guess[i] = caps_guess[49];
            values_1d0_guess[i] = caps_guess[64];
            values_260_guess[i] = caps_guess[69];
            for (int level_guess = 1; level_guess < 70; ++level_guess) {
                if (caps_guess[level_guess - 1] != 0) {
                    values_0c_guess[i] = level_guess;
                    break;
                }
            }
        }
    }
}

// 0 for a fixed list of skill ids (the weapon skills 0-3, the tradeskills 56-69 and others), 1 for the rest.
// FUNCTION: TITANIUM 0x0044A273
int __cdecl IsSkillClampedTo252_guess(unsigned int value) {
    switch (value) {
    case 0x00:
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x07:
    case 0x08:
    case 0x0a:
    case 0x0b:
    case 0x0f:
    case 0x13:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1a:
    case 0x1c:
    case 0x1e:
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x4a:
        return 0;
    default:
        return 1;
    }
}

// Value for class `index` (1-35) from the table at +0xC; 0 out of range.
// FUNCTION: TITANIUM 0x0044A2E4
int ValueTables_guess::GetFirst_guess(int index) {
    if (index < 1 || index > 0x23) {
        return 0;
    }
    return first[index];
}

// Value for class `index` (1-35) from the table at +0x140; 0 out of range.
// FUNCTION: TITANIUM 0x0044A2FD
int ValueTables_guess::GetSecond_guess(int index) {
    if (index < 1 || index > 0x23) {
        return 0;
    }
    return second[index];
}

// Value for class `index` (1-35) from the table at +0x1D0; 0 out of range.
// FUNCTION: TITANIUM 0x0044A319
int ValueTables_guess::GetThird_guess(int index) {
    if (index < 1 || index > 0x23) {
        return 0;
    }
    return third[index];
}

// Value for class `index` (1-35) from the table at +0x260; 0 out of range.
// FUNCTION: TITANIUM 0x0044A335
int ValueTables_guess::GetFourth_guess(int index) {
    if (index < 1 || index > 0x23) {
        return 0;
    }
    return fourth[index];
}

struct PcCharInfo_guess {
    unsigned char reserved_0000[0x1198];
    int race_1198_guess;                     // 0x1198
    unsigned char class_119c_guess;     // 0x119c
};

struct PcCharList_guess {
    void* list;                         // 0x04
    int key;                            // 0x08
    // EXTERNAL: TITANIUM 0x005EC220 PcCharList_guess::GetCharInfo2
    PcCharInfo_guess* GetCharInfo2();
};

struct PcCharBase_guess : PcCharList_guess {
    virtual void VSlot00_guess();
    unsigned char reserved_0c_guess[0x108 - 0x0c];
    // vtordisp -4 on the PcCharacter1 view: the flags word reads at +0x10c through it
    unsigned short flags_10c_guess;     // 0x108 here
    PcCharInfo_guess* Profile_guess() { return GetCharInfo2(); }
};

struct PcPrefix_guess {
    virtual void PSlot00_guess();
    int field_004;
};

struct PcProfile_guess : PcPrefix_guess, virtual PcCharBase_guess {
    unsigned char pad_00c[0xc280 - 0x0c];
};

struct PcCharacter1_guess : virtual PcCharBase_guess {
    virtual void CSlot00_guess();
    // EXTERNAL: TITANIUM 0x004106A3 PcCharacter1_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int affect, bool includeAlt, int subindex, bool includeItems);
};

struct PcFull_guess : PcProfile_guess, PcCharacter1_guess {
};

#define g_slots_guess EQ_ARRAY(ValueTables_guess*, 0x00851200)
#define g_table_guess EQ_ARRAY(int, 0x00691DCC)

// Skill cap by class from one of three tables, picked by bits of +0x10C (probably the expansions owned), plus
// spell effect 247 (raise skill cap). Skill 57 (Tinkering) is 0 for every race but Gnome (12).
// FUNCTION: TITANIUM 0x0044A351
int __cdecl GetTradeskillCap_guess(PcFull_guess* pc, int index) {
    if (pc == 0) {
        return 0;
    }
    int cls = pc->Profile_guess()->class_119c_guess;
    int result = g_slots_guess[index]->GetSecond_guess(cls);
    if ((((PcCharacter1_guess*)pc)->flags_10c_guess & 0x1ff) != 0) {
        result = g_slots_guess[index]->GetThird_guess(pc->Profile_guess()->class_119c_guess);
        if ((((PcCharacter1_guess*)pc)->flags_10c_guess & 0x18a) != 0) {
            result = g_slots_guess[index]->GetFourth_guess(pc->Profile_guess()->class_119c_guess);
        }
        result += ((PcCharacter1_guess*)pc)->TotalSpellAffects_guess(0xf7, 1, index, 1);
    }
    if (index == 0x39 && pc->Profile_guess()->race_1198_guess != 0xc) {
        result = 0;
    }
    return result;
}

// Skill cap from the class x skill x level table (70 levels per row) plus effect 247; tradeskills go to
// GetTradeskillCap_guess. Tinkering again needs a Gnome.
// FUNCTION: TITANIUM 0x0044A448
int __cdecl GetSkillCap_guess(int a, int b, int c, PcFull_guess* d) {
    if (g_slots_guess[c]->flag_0b == 0) {
        return GetTradeskillCap_guess(d, c);
    }
    int result = g_table_guess[(b * 100 + c) * 0x46 + a];
    if (d != 0) {
        result += d->PcCharacter1_guess::TotalSpellAffects_guess(0xf7, 1, c, 1);
        if (c == 0x39) {
            PcCharBase_guess* profile = d;
            if (profile->Profile_guess()->race_1198_guess != 0xc) {
                result = 0;
            }
        }
    }
    return result;
}

// EXTERNAL: TITANIUM 0x00574A30 FinishString_guess
void __cdecl FinishString_guess(char* destination, unsigned int index);

// strncpy of `count` chars, then a terminator forced at `count` - 1 (0x00574A30).
// FUNCTION: TITANIUM 0x0044A4C7
char* __cdecl CopyTerminated_guess(char* destination, const char* source, unsigned int count) {
    strncpy(destination, source, count);
    FinishString_guess(destination, count - 1);
    return destination;
}

// Queues (`first`, `second`) in the 64-entry global list at 0x0099CC50 (dropped when full); returns 0.
// The shared-text allocation check passes it the source file and line.
// FUNCTION: TITANIUM 0x0044A4ED
int __cdecl EnqueuePair_guess(const char* first, int second) {
    unsigned int index = g_queueCount_guess;
    if (index < 0x40) {
        g_queueEntries_guess[index].first = first;
        g_queueEntries_guess[index].second = second;
        g_queueCount_guess = index + 1;
    }
    return 0;
}

// State of the wave in slot `index`; 0 with sound disabled or an empty slot.
// FUNCTION: TITANIUM 0x0044A516
char EqSoundManagerView_guess::GetEntryStatus_guess(int index) {
    if (disabled == 0 && entries[index].item != 0) {
        return entries[index].item->IsPlaying_guess();
    }
    return 0;
}

// Plays wave `index` at `value`'s position (or a default one), scaled by the wave volume.
// FUNCTION: TITANIUM 0x0044A537
void EqSoundManagerView_guess::WavePlay_guess(int index, Local_guess* value) {
    if (disabled == 0) {
        Local_guess local;
        local.Initialize_guess();
        if (value != 0) {
            value->values[9] = lastFloat * value->values[9];
            value->values[6] = -value->values[6];
        } else {
            value = &local;
        }
        value->values[0] = waveVolume_0ff0_guess * value->values[0];
        if (entries[index].item != 0) {
            entries[index].item->SoundAsset_Play_guess(value);
        }
    }
}

// Stops the wave in slot `index`, unless sound is disabled or the slot is empty.
// FUNCTION: TITANIUM 0x0044A591
void EqSoundManagerView_guess::WaveStop_guess(int index) {
    if (disabled == 0 && entries[index].item != 0) {
        entries[index].item->SoundAsset_Stop_guess();
    }
}

// The wave in slot `index`; 0 with sound disabled.
// FUNCTION: TITANIUM 0x0044A5AE
IndexedItem_guess* EqSoundManagerView_guess::GetEntry_guess(int index) {
    if (disabled != 0) {
        return 0;
    }
    return entries[index].item;
}

// Replays the current MP3 (+0x28) from the start, stopping it first; the argument is the first play
// parameter, a float level (the large dialog's Replay button passes it). 0x0044B741 loads a new MP3 the
// same way.
// FUNCTION: TITANIUM 0x0044A5C6
void EqSoundManagerView_guess::ReplayMp3_guess(int value) {
    if (target != 0) {
        target->SoundAsset_Stop_guess();
        Local_guess local;
        local.Initialize_guess();
        local.words[10] = 0;
        local.words[0] = value;
        target->SoundAsset_Play_guess(&local);
    }
}

// Sets the current MP3's volume to `value`, when one is loaded.
// FUNCTION: TITANIUM 0x0044A5FE
void EqSoundManagerView_guess::SetMp3Volume_guess(float value) {
    if (target != 0) {
        ((Callback0_guess*)target)->SetVolume_guess(value, 0);
    }
}

// Adds or removes a music selection (`flag`).
// FUNCTION: TITANIUM 0x0044A617
void EqSoundManagerView_guess::SetMusicSelection_guess(int value, char flag) {
    if (disabled == 0) {
        if (flag != 0) {
            third_guess->Add_guess(value);
        } else {
            third_guess->Remove_guess(value);
        }
    }
}

// Per-frame sound update (unless sound is disabled): the three mixer parts and the forwarded mixer. The
// frame render and the game loop call it.
// FUNCTION: TITANIUM 0x0044A63A
void EqSoundManagerView_guess::ProcessSound_guess() {
    if (disabled == 0) {
        if (first_guess != 0) {
            first_guess->Clear_guess();
        }
        second_guess->Flush_guess();
        third_guess->UpdateMusic_guess();
        forwarded->Update_guess();
    }
}

// On a zone change (0x0044C1BC): takes the sound at +0x24 out of the music list (+0xC), sets its volume
// to 0 (the call 0x0044A5FE makes), releases it and clears the slot.
// FUNCTION: TITANIUM 0x0044A669
void EqSoundManagerView_guess::ReleaseZoneMusic_guess() {
    if (disabled == 0 && node24_guess != 0) {
        ((NodeHandleList_guess*)third_guess)->RemoveAsset_guess(node24_guess);
        ((Callback0_guess*)node24_guess)->SetVolume_guess(0.0f, 0);
        ((Callback0_guess*)node24_guess)->Release_guess();
        node24_guess = 0;
    }
}

// Stops and releases the wave slots loaded with the zone flag (the <zone>_sndbnk.eff waves); the fixed
// waves stay.
// FUNCTION: TITANIUM 0x0044A6A0
void EqSoundManagerView_guess::UnloadZoneWaves_guess() {
    if (disabled != 0) {
        return;
    }
    IndexedEntry_guess* entry = entries;
    int count = 5000;
    do {
        if (entry->item != 0 && entry->enabled != 0) {
            ((Callback0_guess*)entry->item)->SetVolume_guess(0.0f, 0);
            ((Callback0_guess*)entry->item)->Release_guess();
            entry->item = 0;
        }
        ++entry;
        --count;
    } while (count != 0);
}

// Detaches and releases every zone emitter (the list 0x0044A7EC filters) and empties the list.
// FUNCTION: TITANIUM 0x0044A6DF
void EqSoundManagerView_guess::RemoveAllEmitters_guess() {
    if (disabled != 0) {
        return;
    }
    int index = 0;
    if (callbackCount > 0) {
        Callback8_guess** callback = callbacks;
        do {
            ((Callback8_guess*)second_guess)->Run_guess(*callback);
            ((Callback0_guess*)*callback)->Release_guess();
            ++index;
            ++callback;
        } while (index < callbackCount);
    }
    callbackCount = 0;
}

// Applies the sound Realism option (`value`, 0-1) to the wave mixer.
// FUNCTION: TITANIUM 0x0044A71F
void EqSoundManagerView_guess::SetRealism_guess(float value) {
    if (disabled == 0) {
        lastFloat = value;
        second_guess->SetFloat_guess(value);
    }
}

// Applies the SoundMixAhead option to the mixer (/mixahead and the options load).
// FUNCTION: TITANIUM 0x0044A742
void EqSoundManagerView_guess::SetMixAhead_guess(int value) {
    if (disabled == 0) {
        forwarded->SetPreference_guess(value);
    }
}

// Sets the wave (sound effect) volume, 0-1, and remembers it (+0xFF0).
// FUNCTION: TITANIUM 0x0044A753
void EqSoundManagerView_guess::SetWaveVolume_guess(float value) {
    if (disabled == 0) {
        waveVolume_0ff0_guess = value;
        second_guess->SetVolume_guess(value);
    }
}

// Sets the music volume, 0-1.
// FUNCTION: TITANIUM 0x0044A776
void EqSoundManagerView_guess::SetMusicVolume_guess(float value) {
    if (disabled == 0) {
        third_guess->SetMusicTrackVolume_guess(value);
    }
}

// The mixer's current environment preset; 0 with sound disabled.
// FUNCTION: TITANIUM 0x0044A78F
int EqSoundManagerView_guess::GetRoomType_guess() {
    if (disabled != 0) {
        return 0;
    }
    return forwarded->GetValue_guess();
}

// Sets the mixer's environment preset, unless sound is disabled; the outdoor, indoor and enclosed
// setters and 0x00438FC2 (stun, drunkenness, head environment) use it.
// FUNCTION: TITANIUM 0x0044A7A0
void EqSoundManagerView_guess::SetRoomType_guess(int value) {
    if (disabled == 0) {
        forwarded->SetValue_guess(value);
    }
}

// Moves the listener to (first, second, -third) facing `fourth`, a heading of 512 units per turn
// converted to radians; does nothing when sound is disabled. The frame render calls it.
// FUNCTION: TITANIUM 0x0044A7B1
void EqSoundManagerView_guess::SetListenerLocation_guess(float first, float second, float third, float fourth) {
    if (disabled == 0) {
        forwarded->SetListenerLocation_guess(first, second, -third, fourth * g_radianScale_guess);
    }
}

// Re-enables or mutes every zone emitter: an emitter tagged with an environment (1 outdoor, 2 indoor, 3
// enclosed) must match the current one, one tagged 1 or 2 must match the mode set by 0x0044B02C (probably
// day/night), and one with the third tag is muted while 0x0044B050's flag is on. Then the two filter
// sounds.
// FUNCTION: TITANIUM 0x0044A7EC
void EqSoundManagerView_guess::Refresh_guess() {
    if (disabled == 0) {
        for (int index_guess = 0; index_guess < callbackCount; ++index_guess) {
            Callback8_guess* callback_guess = callbacks[index_guess];
            char hidden_guess = 0;
            if (callback_guess->first_guess != 0 && callback_guess->first_guess != filterValue_guess) {
                hidden_guess = 1;
            }
            if (callback_guess->second_guess != 0 && callback_guess->second_guess != mode) {
                hidden_guess = 1;
            }
            if (callback_guess->third_guess != 0 && filterFlag_guess != 0) {
                hidden_guess = 1;
            }
            callback_guess->SetEnabled_guess(!hidden_guess);
        }
        filterA_guess->SetEnabled_guess(flag_ff4_guess != 0 && flag_ff6_guess == 0);
        filterB_guess->SetEnabled_guess(visualState != 0 && flag_ff6_guess == 0);
    }
}

// Stops and releases every cached mp3 asset (filled on demand by 0x0044B502).
// FUNCTION: TITANIUM 0x0044A89F
void EqSoundManagerView_guess::ClearIndexedItems_guess() {
    if (disabled == 0) {
        int index_guess = 0;
        if (index_guess < indexedItemCount_guess) {
            IndexedItem_guess** item_guess = indexedItems_guess;
            do {
                if (*item_guess != 0) {
                    (*item_guess)->SoundAsset_Stop_guess();
                    ((Callback0_guess*)*item_guess)->Release_guess();
                    *item_guess = 0;
                }
                ++index_guess;
                ++item_guess;
            } while (index_guess < indexedItemCount_guess);
        }
    }
}

// Reads mp3index.txt: one MP3 name per line, spaces stripped, up to 32 characters. There is no check on the
// count, so more than 100 lines overrun the 100-entry tables.
// FUNCTION: TITANIUM 0x0044A8DF
void EqSoundManagerView_guess::OldMp3Init_guess() {
    if (disabled == 0) {
        memset(indexedItems_guess, 0, 0x190);
        memset(indexNames_guess, 0, 0xc80);
        indexedItemCount_guess = 0;
        FILE* file_guess = fopen("mp3index.txt", "rt");
        if (file_guess != 0) {
            char line_guess[256];
            while ((file_guess->_flag & 0x10) == 0) {
                line_guess[0] = 0;
                fgets(line_guess, 0x100, file_guess);
                RemoveCharacter_guess(line_guess, 0xd);
                RemoveCharacter_guess(line_guess, 0xa);
                RemoveCharacter_guess(line_guess, 0x20);
                if (strlen(line_guess) > 0) {
                    CopyTerminated_guess(indexNames_guess[indexedItemCount_guess], line_guess, 0x20);
                    ++indexedItemCount_guess;
                }
            }
            fclose(file_guess);
        }
    }
}

// Stops and releases every cached MP3 asset, unless sound is disabled.
// FUNCTION: TITANIUM 0x0044A9D6
void EqSoundManagerView_guess::ReleaseMp3Index_guess() {
    if (disabled == 0) {
        ClearIndexedItems_guess();
    }
}

// When the owner's flag is clear: runs its callback on the held object, releases the object and forgets
// it.
// FUNCTION: TITANIUM 0x0044AA7A
void Monitor_guess::Detach_guess() {
    if (second->flag == 0) {
        second->callback->Run_guess(first);
        first->Release_guess();
        first = 0;
    }
}

// Moves the emitter's 3D sound source to (x, y, -z), unless sound is disabled.
// FUNCTION: TITANIUM 0x0044AA9C
void EqMobileEmitterView_guess::Move_guess(float first, float second, float third) {
    if (owner->disabled == 0) {
        receiver->FUN_004c5d97_guess(first, second, -third);
    }
}

// Sets the loop sound of an actor's mobile emitter: copies the spawn's +0x120 string in, then attaches
// sound `index` (0 detaches it). 0x00479F75 calls it when the spawn's loop sound changes; nothing happens
// with sound disabled.
// FUNCTION: TITANIUM 0x0044AACB
void EqMobileEmitterView_guess::SetTextAndItem_guess(int index, const char* text) {
    if (owner->disabled == 0) {
        CopyText_guess(receiver->data, text);
        if (index == 0) {
            receiver->SetAsset_guess(0);
        } else {
            receiver->SetAsset_guess(owner->GetEntry_guess(index));
        }
    }
}

// Sizes the actor's sound emitter from its height when the actor is built: +0x30 = height / 2 (at least
// 2), +0x34 and +0x3C = 24 times that, the same pattern 0x00479EE8 uses for one-shot spawn sounds.
// FUNCTION: TITANIUM 0x0044AB0B
void EqSoundManagerView_guess::SetHeight_guess(float height) {
    if (forwarded->disabled == 0 && first_guess != 0) {
        first_guess->value_30 = height * 0.5f;
        if (first_guess->value_30 < 2.0f) {
            first_guess->value_30 = 2.0f;
        }
        first_guess->value_34 = first_guess->value_30 * 24.0f;
        first_guess->value_3c = first_guess->value_34;
    }
}

// Defaults for one .emt emitter line: scale fields 1.0, the two times (+0x5C, +0x60) 5000.
// FUNCTION: TITANIUM 0x0044AB59
SoundPart_guess::SoundPart_guess() {
    memset(this, 0, 0x20);
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_2c = 1.0f;
    field_30 = 1.0f;
    field_34 = 0;
    field_38 = 0;
    field_3c = 1;
    field_40 = 0.0f;
    field_44 = 0.0f;
    field_48 = 0.0f;
    field_4c = 0.0f;
    field_50 = 0.0f;
    field_54 = 0.0f;
    field_58 = 0.0f;
    field_5c = 5000;
    field_60 = 5000;
    field_64 = 0;
}

// Parses one comma-separated line of <zone>.emt (0x0044BD94): leading field count, wave name (31 chars),
// then the numeric emitter settings; the last field (a flag) defaults to 1 when the count is below 2.
// FUNCTION: TITANIUM 0x0044ABC1
void SoundPart_guess::Load_guess(char* text) {
    int count = ReadInt_guess(&text, 0x2c);
    ReadString_guess(name_guess, 0x20, &text, 0x2c);
    field_20 = ReadInt_guess(&text, 0x2c);
    field_24 = ReadInt_guess(&text, 0x2c);
    field_2c = ReadFloat_guess(&text, 0x2c);
    field_34 = ReadInt_guess(&text, 0x2c);
    field_38 = ReadInt_guess(&text, 0x2c);
    field_3c = ReadInt_guess(&text, 0x2c);
    field_40 = ReadFloat_guess(&text, 0x2c);
    field_44 = ReadFloat_guess(&text, 0x2c);
    field_48 = ReadFloat_guess(&text, 0x2c);
    field_4c = ReadFloat_guess(&text, 0x2c);
    field_50 = ReadFloat_guess(&text, 0x2c);
    field_54 = ReadFloat_guess(&text, 0x2c);
    field_58 = ReadFloat_guess(&text, 0x2c);
    field_5c = ReadInt_guess(&text, 0x2c);
    field_60 = ReadInt_guess(&text, 0x2c);
    field_64 = ReadInt_guess(&text, 0x2c);
    field_30 = ReadFloat_guess(&text, 0x2c);
    if (count < 2) {
        field_28 = 1;
    } else {
        field_28 = ReadInt_guess(&text, 0x2c) != 0;
    }
}

// Drops one reference on the held object and deletes it at zero.
// FUNCTION: TITANIUM 0x0044ACF1
void RefCountHolder_guess::Release_guess() {
    RefCounted_guess* item = value;
    if (item != 0 && --item->referenceCount == 0) {
        item->Delete_guess(1);
    }
}

// Assignment of a reference-counted text handle: drops the old text (freed at zero references) and takes a
// reference on `other`'s.
// FUNCTION: TITANIUM 0x0044AD03
SharedTextPtr_guess& SharedTextPtr_guess::Assign_guess(SharedTextPtr_guess other) {
    if (&other == this) {
        return *this;
    }
    if (shared != 0) {
        shared->Release_guess();
    }
    shared = other.shared;
    if (shared != 0) {
        ++shared->refs;
    }
    return *this;
}

// Returns `value`; null reports "There was an error allocating memory." with `detail`.
// FUNCTION: TITANIUM 0x0044AD61
void* __cdecl CheckAllocation_guess(void* value, const char* detail, int where) {
    if (value == 0) {
        ReportAllocationError_guess(0, "There was an error allocating memory.", detail);
    }
    return value;
}

// Drops one reference and deletes the object at zero.
// FUNCTION: TITANIUM 0x0044AD80
Rc_guess::~Rc_guess() { if (--refs == 0) delete this; }

// The shared text's size minus one (its length without the terminator); 0 for none.
// FUNCTION: TITANIUM 0x0044AD92
int CountHolder_guess::GetCountMinusOne_guess() {
    if (Count() > 0) return Count() - 1;
    return 0;
}

// Assignment of a shared text with its read cursor.
// FUNCTION: TITANIUM 0x0044ADB3
SharedString_guess& SharedString_guess::Assign_guess(const SharedString_guess& source) {
    buffer.Assign_guess(source.buffer);
    cursor = source.cursor;
    return *this;
}

// Switches to the enclosed environment: its preset (+0xFE4) and, when it changed, refreshes the zone
// emitters (environment 3).
// FUNCTION: TITANIUM 0x0044AF75
void EqSoundManagerView_guess::SetEnclosedEnvironment_guess() {
    if (disabled == 0) {
        SetRoomType_guess(enclosedEnvironment_0fe4_guess);
        if (filterValue_guess != 3) {
            filterValue_guess = 3;
            Refresh_guess();
        }
    }
}

// Switches to the indoor environment: its preset (+0xFE0) and, when it changed, refreshes the zone
// emitters (environment 2).
// FUNCTION: TITANIUM 0x0044AFA2
void EqSoundManagerView_guess::SetIndoorEnvironment_guess() {
    if (disabled == 0) {
        SetRoomType_guess(indoorEnvironment_0fe0_guess);
        if (filterValue_guess != 2) {
            filterValue_guess = 2;
            Refresh_guess();
        }
    }
}

// Switches to the outdoor environment: its preset (+0xFE8) and, when it changed, refreshes the zone
// emitters (environment 1).
// FUNCTION: TITANIUM 0x0044AFCF
void EqSoundManagerView_guess::SetOutdoorEnvironment_guess() {
    if (disabled == 0) {
        SetRoomType_guess(outdoorEnvironment_0fe8_guess);
        if (filterValue_guess != 1) {
            filterValue_guess = 1;
            Refresh_guess();
        }
    }
}

// Sets the wind flag (+0xFF4) and refreshes the zone emitters; the weather and the world display
// shutdown (0x0044350D) use it.
// FUNCTION: TITANIUM 0x0044AFFC
void EqSoundManagerView_guess::EmitterSetWind_guess(char value) {
    if (disabled == 0) {
        flag_ff4_guess = value;
        Refresh_guess();
    }
}

// Sets the visual state byte and refreshes the zone emitters; the display and the weather use it.
// FUNCTION: TITANIUM 0x0044B014
void EqSoundManagerView_guess::SetVisualState_guess(char state) {
    if (disabled == 0) {
        visualState = state;
        Refresh_guess();
    }
}

// Sets the emitter mode to 2 when `state` is set, else 1, refreshing the zone emitters on a change.
// FUNCTION: TITANIUM 0x0044B02C
void EqSoundManagerView_guess::SetMode_guess(char state) {
    if (disabled == 0) {
        int newMode = (state != 0) + 1;
        if (mode != newMode) {
            mode = newMode;
            Refresh_guess();
        }
    }
}

// Sets the EnvSounds-off flag (environment emitters muted) and refreshes the zone emitters.
// FUNCTION: TITANIUM 0x0044B050
void EqSoundManagerView_guess::SetEnvSounds_guess(char value) {
    if (disabled == 0) {
        filterFlag_guess = value;
        Refresh_guess();
    }
}

// Sets the weather-loop flag (+0xFF6) and refreshes the zone emitters.
// FUNCTION: TITANIUM 0x0044B068
void EqSoundManagerView_guess::SetWeatherLoopsMuted_guess(char value) {
    if (disabled == 0) {
        flag_ff6_guess = value;
        Refresh_guess();
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 FreeObject_guess
void __cdecl FreeObject_guess(void* value);

// EXTERNAL: TITANIUM 0x0060D682 FreeBuffer_guess
void __cdecl FreeBuffer_guess(void* value);

// Scalar deleting destructor of a shared text block (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0044B080
RefCounted_guess* RefCounted_guess::DestroyAndFree_guess(unsigned char flags) {
    DestroyContents_guess();
    if ((flags & 1) != 0) {
        FreeObject_guess(this);
    }
    return this;
}

// Shared text block destructor: frees the buffer and drops one reference, deleting the base at zero.
// FUNCTION: TITANIUM 0x0044B09C
void RefCounted_guess::DestroyContents_guess() {
    *(void**)this = EQ_ARRAY(char, 0x006440A4);
    FreeBuffer_guess(buffer);
    --referenceCount;
    *(void**)this = EQ_ARRAY(char, 0x00644054);
    if (referenceCount == 0) {
        delete (DestroyDispatch_guess*)this;
    }
}

// Makes a handle to a new shared text block of `length` bytes (share.h allocation checks), holding one
// reference; length 0 gives a null handle.
// FUNCTION: TITANIUM 0x0044B0C3
// @early-stop: budget, structural ndiff=10
SharedTextPtr_guess::SharedTextPtr_guess(unsigned int length) {
    shared = 0;
    if (length != 0) {
        char* text = (char*)CheckAllocation_guess(new char[length], "new T[ len ]",
                                                  EnqueuePair_guess("c:\\eq\\eqpfs\\share.h", 0x1b0));
        shared = (SharedText_guess*)CheckAllocation_guess(new SharedText_guess(text, length), "new SharedT( aT, len )",
                                                          EnqueuePair_guess("c:\\eq\\eqpfs\\share.h", 0x1b2));
        ++shared->refs;
    }
}

// Copies `text` into a new shared block of strlen + 1 bytes with the read cursor at 0; null or empty text
// leaves the handle null.
// FUNCTION: TITANIUM 0x0044B14A
SharedString_guess::SharedString_guess(const char* text) : buffer(0) {
    cursor = 0;
    if (text != 0) {
        unsigned int length = strlen(text);
        if (length != 0) {
            buffer.Assign_guess(SharedTextPtr_guess(length + 1));
            CopyString_guess(buffer.shared->data, text);
            cursor = 0;
        }
    }
}

// Not a plain copy: the copy is lowercased and every run of '\\' or '/' becomes one '/', so the result is a
// normalized path key (SoundPath_guess builds its key this way).
// FUNCTION: TITANIUM 0x0044B1B5
// @early-stop: budget, diff ndiff=4
SharedString_guess::SharedString_guess(const SharedString_guess& source)
    : buffer((const char*)0) {
    SharedTextPtr_guess text((unsigned int)(source.GetCountMinusOne_guess() + 1));
    {
        int output = 0;
        int length = source.GetCountMinusOne_guess();
        SharedText_guess* shared = text.shared;
        bool previousSeparator = false;
        int index = 0;
        while (index < length) {
            char value = source.buffer.shared->data[index];
            if ((value < 'A') || ('Z' < value)) {
                if ((value != '\\') && (value != '/')) {
                    shared->data[output] = value;
                    ++output;
                    previousSeparator = false;
                } else if (!previousSeparator) {
                    shared->data[output] = '/';
                    ++output;
                    previousSeparator = true;
                }
            } else {
                value += ' ';
                shared->data[output] = value;
                ++output;
                previousSeparator = false;
            }
            ++index;
        }
        shared->data[output] = 0;
    }
    SharedString_guess value(text.shared->data);
    Assign_guess(value);
}

// Sound path key from `name`: lowercased, each run of slashes or backslashes made one '/' (0x0044B1B5).
// FUNCTION: TITANIUM 0x0044B2AC
SoundPath_guess::SoundPath_guess(const char* name) : value(0) {
    SharedString_guess string_guess(name);
    value.Assign_guess(SharedString_guess(string_guess));
}

// Mp3 asset number `index` (1-based) from the mp3 name list, loaded on first use and cached.
// FUNCTION: TITANIUM 0x0044B502
IndexedItem_guess* EqSoundManagerView_guess::GetMp3Asset_guess(int index) {
    if (disabled == 0) {
        index = index - 1;
        if (index >= 0 && index < indexedItemCount_guess) {
            IndexedItem_guess** slot = &indexedItems_guess[index];
            if (*slot == 0) {
                *slot = GetAsset_guess(indexNames_guess[index]);
            }
            return *slot;
        }
    }
    return 0;
}

// Loads wave `name` into slot `index` unless the slot already holds it (the old one is stopped and
// released); `flag` marks a zone wave, which 0x0044A6A0 unloads on zone change.
// FUNCTION: TITANIUM 0x0044B6D9
void EqSoundManagerView_guess::WaveLoad_guess(char* name, int index, char flag) {
    if (disabled == 0) {
        IndexedEntry_guess* entry = &entries[index];
        if (entry->item != 0) {
            if (_stricmp(entry->item->GetName_guess(), name) == 0) {
                return;
            }
            ((Callback0_guess*)entry->item)->SetVolume_guess(0.0f, 0);
            ((Callback0_guess*)entry->item)->Release_guess();
            entry->item = 0;
        }
        entries[index].item = GetAsset_guess(name);
        entries[index].enabled = flag;
    }
}

// Stops the current mp3 asset and plays `name` (names of 3 chars or less are ignored) with `value` as the
// first play parameter.
// FUNCTION: TITANIUM 0x0044B741
void EqSoundManagerView_guess::PlayMp3_guess(char* name, int value) {
    if (target != 0) {
        if (target->IsPlaying_guess() != 0) {
            target->SoundAsset_Stop_guess();
        }
        target = 0;
    }
    if (target == 0) {
        if (strlen(name) > 3) {
            target = GetAsset_guess(name);
        }
        if (target == 0) {
            return;
        }
    }
    Local_guess local;
    local.Initialize_guess();
    local.words[10] = 0;
    local.words[0] = value;
    target->SoundAsset_Play_guess(&local);
}

/* ---- EqSoundManager::EqSoundManager(bool, bool, SpeakerType) (0x0044CA8F) --------------------------
 * The class this file's EqSoundManagerView_guess functions view; 0xBAFC bytes (last field +0xBAF8). */

struct SoundTable_guess {
    unsigned int words[4];
    // EXTERNAL: TITANIUM 0x004FF9C9 SoundTable_guess::Lookup_guess
    CXStr* Lookup_guess(int index);
    // EXTERNAL: TITANIUM 0x00435671 SoundTable_guess::FUN_00435671_guess
    void FUN_00435671_guess(CXStr* name, int index);
    // EXTERNAL: TITANIUM 0x00435652 ??0SoundTable_guess@@QAE@I@Z
    SoundTable_guess(unsigned int size);
    // EXTERNAL: TITANIUM 0x00435906 ??1SoundTable_guess@@QAE@XZ
    ~SoundTable_guess();
};

struct SoundList_guess {
    unsigned int words[3];
    // EXTERNAL: TITANIUM 0x0042610D ??0SoundList_guess@@QAE@XZ
    SoundList_guess();
    // EXTERNAL: TITANIUM 0x0042C050 SoundList_guess::Insert_guess
    int* Insert_guess(struct ClientString_guess* value);
    // EXTERNAL: TITANIUM 0x0042BDBE ??1SoundList_guess@@QAE@XZ
    ~SoundList_guess();
};

struct ClientString_guess {
    int words[7];
    // EXTERNAL: TITANIUM 0x00403631 ClientString_guess::ClientString_guess
    ClientString_guess(const char* value);
    // EXTERNAL: TITANIUM 0x0040291E ClientString_guess::Tidy_guess
    void Tidy_guess(bool reallocate, unsigned int capacity);
    ~ClientString_guess() { Tidy_guess(true, 0); }
};

struct ArchiveFile_guess {
    void* data;                             // 0x00
    ArchiveFile_guess() : data(0) {}
    // EXTERNAL: TITANIUM 0x00577F50 ??1ArchiveFile_guess@@QAE@XZ
    ~ArchiveFile_guess();
    // EXTERNAL: TITANIUM 0x00577780 ArchiveFile_guess::Size_guess
    unsigned int Size_guess();
    // EXTERNAL: TITANIUM 0x00577B00 ArchiveFile_guess::Read_guess
    void Read_guess(char* buffer, unsigned int size);
};

struct TextValue_guess {
    char padding_guess[0x220];
    // EXTERNAL: TITANIUM 0x004C596F TextValue_guess::TextValue_guess
    TextValue_guess(int manager_guess, const char* text_guess, int first_guess, int second_guess);
};

// EXTERNAL: TITANIUM 0x00624405 FileAccess_guess
int __cdecl FileAccess_guess(const char* path, int mode);

struct SoundArchives_guess {
    unsigned char unused;
    // EXTERNAL: TITANIUM 0x00577750 ??0SoundArchives_guess@@QAE@XZ
    SoundArchives_guess();
    // EXTERNAL: TITANIUM 0x00578400 SoundArchives_guess::Open_guess
    char Open_guess(SoundPath_guess path, ArchiveFile_guess& file);
    // EXTERNAL: TITANIUM 0x00579970 SoundArchives_guess::Load_guess
    void Load_guess(SoundPath_guess path);
    // EXTERNAL: TITANIUM 0x00579490 SoundArchives_guess::Unload_guess
    void Unload_guess(SoundPath_guess path);
};

struct SoundDevice_guess {
    unsigned char data[0x4ac];
    // EXTERNAL: TITANIUM 0x004C6B3A ??0SoundDevice_guess@@QAE@HHHHHHH@Z
    SoundDevice_guess(int a, int b, int c, int rate, int bits, int e, int speakerType);
    // EXTERNAL: TITANIUM 0x004C6110 ??1SoundDevice_guess@@QAE@XZ
    ~SoundDevice_guess();
    // EXTERNAL: TITANIUM 0x004C6203 SoundDevice_guess::AddInstances_guess
    void AddInstances_guess(int a, int b, int c);
    // EXTERNAL: TITANIUM 0x004C631D SoundDevice_guess::Find_guess
    TextValue_guess* Find_guess(const char* name);
};

struct SoundListener_guess {
    unsigned char data[0x10];
    // EXTERNAL: TITANIUM 0x004C60FD ??0SoundListener_guess@@QAE@XZ
    SoundListener_guess();
    // EXTERNAL: TITANIUM 0x004C72C1 ??1SoundListener_guess@@QAE@XZ
    ~SoundListener_guess();
    // EXTERNAL: TITANIUM 0x004C6A99 SoundListener_guess::FUN_004c6a99_guess
    void FUN_004c6a99_guess(int type, IndexedItem_guess* item, int index, float volume,
                             int flag, int priority, int start, int fade, int duration, int loop);
};

// EXTERNAL: TITANIUM 0x005768A0 FUN_005768a0_guess
int __cdecl FUN_005768a0_guess(const char* first, const char* second);

struct SoundMixer_guess {
    unsigned char data[0x14];
    // EXTERNAL: TITANIUM 0x004C603C ??0SoundMixer_guess@@QAE@PAUSoundDevice_guess@@@Z
    SoundMixer_guess(SoundDevice_guess* device);
    // EXTERNAL: TITANIUM 0x004C6079 SoundMixer_guess::Attach_guess
    void Attach_guess(Callback8_guess* callback);
    // EXTERNAL: TITANIUM 0x004C6092 SoundMixer_guess::Detach_guess
    void Detach_guess(Callback8_guess* callback);
    // EXTERNAL: TITANIUM 0x004C6059 ??1SoundMixer_guess@@QAE@XZ
    ~SoundMixer_guess();
};

struct SoundBank_guess {
    unsigned char data[0x4020];
    // EXTERNAL: TITANIUM 0x004C5E4D ??0SoundBank_guess@@QAE@PAUSoundDevice_guess@@PAUSoundListener_guess@@@Z
    SoundBank_guess(SoundDevice_guess* device, SoundListener_guess* listener);
    // EXTERNAL: TITANIUM 0x004C7304 ??1SoundBank_guess@@QAE@XZ
    ~SoundBank_guess();
};

struct EqSoundManager_guess {
    SoundBank_guess* bank;                  // 0x0000
    SoundDevice_guess* device;              // 0x0004
    SoundMixer_guess* mixer;                // 0x0008
    SoundListener_guess* listener;          // 0x000c
    Callback0_guess* callback_0010_guess;   // 0x0010
    Callback0_guess* callback_0014_guess;   // 0x0014
    Callback0_guess* callback_0018_guess;   // 0x0018
    Callback0_guess* callback_001c_guess;   // 0x001c
    Callback0_guess* callback_0020_guess;   // 0x0020
    int value_0024;                         // 0x0024
    Callback0_guess* callback_0028_guess;   // 0x0028
    char disabled;                          // 0x002c
    unsigned char reserved_002d[3];
    int nextEmitterIndex_0030_guess;                         // 0x0030
    Callback8_guess* callbacks[1000];       // 0x0034
    int callbackCount;                      // 0x0fd4
    Callback8_guess* filterA;               // 0x0fd8
    Callback8_guess* filterB;               // 0x0fdc
    int indoorEnvironment_0fe0_guess;                         // 0x0fe0
    int enclosedEnvironment_0fe4_guess;                         // 0x0fe4
    int outdoorEnvironment_0fe8_guess;                         // 0x0fe8
    float value_0fec;                       // 0x0fec
    float value_0ff0;                       // 0x0ff0
    char flag_0ff4;                         // 0x0ff4
    char visualState;                       // 0x0ff5
    char flag_0ff6;                         // 0x0ff6
    unsigned char reserved_0ff7;
    int filterValue;                        // 0x0ff8
    int mode;                               // 0x0ffc
    char filterFlag;                        // 0x1000
    unsigned char reserved_1001[3];
    IndexedEntry_guess entries[5000];       // 0x1004
    unsigned char block_ac44[0x80];         // 0xac44
    SoundArchives_guess* archives;          // 0xacc4
    unsigned char reserved_acc8[0xe14];
    SoundTable_guess table_badc;            // 0xbadc
    SoundList_guess list_baec;              // 0xbaec
    int value_baf8;                         // 0xbaf8
    EqSoundManager_guess(bool disable, bool highRate, int speakerType);
    ~EqSoundManager_guess();
    int AddDynamicAsset_guess(const char* path);
    void LoadAssets_guess(const char* name);
    // EXTERNAL: TITANIUM 0x0044B7B0 EqSoundManager_guess::LoadGlobalMusic_guess
    void LoadGlobalMusic_guess();
    void LoadGlobalWaves_guess();
    void LoadGlobalEmitters_guess();
    void WaveLoadById_guess(int index, char flag);
    void WaveLoadRange_guess(int first, int count);
    void AddEmitter_guess(SoundPart_guess* part);
    bool EmitterLoad_guess(const char* path);
    void LoadOldEmitters_guess();
    void SetCurrentZone_guess(const char* name);
    int GetDynamicAssetId_guess(const char* name_guess);
};

struct TextFileReader_guess {
    unsigned char data[0x1000c];
    // EXTERNAL: TITANIUM 0x00576BD0 TextFileReader_guess::TextFileReader_guess
    TextFileReader_guess(const char* path, int delimiter);
    // EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::IsOpen_guess
    bool IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::GetLineCount_guess
    int GetLineCount_guess();
    // EXTERNAL: TITANIUM 0x00576CF0 TextFileReader_guess::ReadLine_guess
    void ReadLine_guess(char* buffer, int size);
    // EXTERNAL: TITANIUM 0x00576C50 TextFileReader_guess::Close_guess
    void Close_guess();
};

// Finds a sound by name: loaded already, then sounds\<name>, voice\default\<name>, then the pfs archives.
// FUNCTION: TITANIUM 0x0044B33B
IndexedItem_guess* EqSoundManagerView_guess::GetAsset_guess(char* name) {
    EqSoundManager_guess* self = (EqSoundManager_guess*)this;
    if (disabled != 0) {
        return 0;
    }
    TextValue_guess* result = self->device->Find_guess(name);
    if (result == 0) {
        char sounds[0x40];
        strcpy(sounds, "sounds\\");
        strcat(sounds, name);
        char voice[0x80];
        strcpy(voice, "voice\\default\\");
        strcat(voice, name);
        if (FileAccess_guess(sounds, 0) == 0) {
            result = new TextValue_guess((int)self->device, sounds, 0, 0);
        } else if (FileAccess_guess(voice, 0) == 0) {
            result = new TextValue_guess((int)self->device, voice, 0, 0);
        } else {
            ArchiveFile_guess file;
            if (self->archives->Open_guess(SoundPath_guess(name), file)) {
                unsigned int size = file.Size_guess();
                char* data = new char[size];
                file.Read_guess(data, size);
                result = new TextValue_guess((int)self->device, name, (int)data, (int)size);
                delete[] data;
            }
        }
    }
    return (IndexedItem_guess*)result;
}

// Adds an emitter from a parsed sound line; .mp3 and .xmi names are music, others waves.
// FUNCTION: TITANIUM 0x0044B540
// @early-stop: budget, structural ndiff=19
void EqSoundManager_guess::AddEmitter_guess(SoundPart_guess* part) {
    if (disabled != 0) {
        return;
    }

    IndexedItem_guess* item = ((EqSoundManagerView_guess*)this)->GetAsset_guess(part->name_guess);
    if (item == 0) {
        return;
    }

    Callback8_guess* callback;
    if (FUN_005768a0_guess(part->name_guess, ".mp3") == 0 &&
        FUN_005768a0_guess(part->name_guess, ".xmi") == 0) {
        callback = new Callback8_guess(mixer, item, 3);
    } else {
        int index = nextEmitterIndex_0030_guess++;
        int state = item->GetType_guess();
        float duration = part->field_58 + EQ_GLOBAL(float, 0x00642AE0);
        listener->FUN_004c6a99_guess(index, item, part->field_64, part->field_2c,
                                      part->field_3c, (int)duration, part->field_34,
                                      1500, part->field_38, state == 2);
        callback = new Callback8_guess(mixer, listener, index);
    }

    ((Callback0_guess*)item)->Release_guess();
    if (callback != 0) {
        callback->value08_guess = part->field_2c;
        callback->value0c_guess = part->field_30_bits;
        callback->value18_guess = part->field_34;
        callback->value1c_guess = part->field_38;
        callback->value20_guess = part->field_3c;
        callback->value24_guess = part->field_40_bits;
        callback->value28_guess = part->field_44_bits;
        callback->value2c_guess = -part->field_48;
        callback->bits30_guess = part->field_4c_bits;
        callback->bits34_guess = part->field_50_bits;
        callback->value38_guess = part->field_54_bits;
        callback->value3c_guess = part->field_58;
        callback->value40_guess = part->field_5c;
        callback->value44_guess = part->field_60;
        callback->first_guess = part->field_20;
        callback->second_guess = part->field_24;
        callback->third_guess = part->field_28_unsigned;
        callbacks[callbackCount] = callback;
        ++callbackCount;
        mixer->Attach_guess(callback);
    }
}

// EXTERNAL: TITANIUM 0x00574860 FUN_00574860_guess
int __cdecl FUN_00574860_guess(const char* text, int* width);
// EXTERNAL: TITANIUM 0x00574830 FUN_00574830_guess
int __cdecl FUN_00574830_guess(const char* text, int zero);
// EXTERNAL: TITANIUM 0x00576D20 FUN_00576D20_guess
void __cdecl FUN_00576D20_guess(char* destination, int size, char** source, int delimiter);
// EXTERNAL: TITANIUM 0x00576D80 FUN_00576D80_guess
int __cdecl FUN_00576D80_guess(char** source, int delimiter);
// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format, ...);

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess(void);

// Global music cues: eqtheme.mp3 (or opener4.xmi) for the title, combattheme1 or 2.mp3 (picked at random) for
// combat, deaththeme.mp3 for death, falling back to tracks of gl.xmi.
// FUNCTION: TITANIUM 0x0044B7B0
void EqSoundManager_guess::LoadGlobalMusic_guess() {
    if (disabled == 0) {
        callback_0010_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("gl.xmi");
        callback_0014_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("opener4.xmi");
        callback_0018_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("eqtheme.mp3");
        callback_001c_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("deaththeme.mp3");
        srand(FUN_00576e80_guess());
        if (rand() % 2 != 0) {
            callback_0020_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("combattheme1.mp3");
        } else {
            callback_0020_guess = (Callback0_guess*)((EqSoundManagerView_guess*)this)->GetAsset_guess("combattheme2.mp3");
        }

        if (callback_0018_guess != 0) {
            listener->FUN_004c6a99_guess(1, (IndexedItem_guess*)callback_0018_guess, 0, 1.0f, 0, 10, 0, 1500, 5000, 1);
            listener->FUN_004c6a99_guess(4, (IndexedItem_guess*)callback_0018_guess, 0, 1.0f, 0, 10,
                                         0, 1500, 5000, 1);
        } else {
            listener->FUN_004c6a99_guess(1, (IndexedItem_guess*)callback_0014_guess, 0, 1.0f, 0, 10, 0, 1500, 5000, 0);
            listener->FUN_004c6a99_guess(4, (IndexedItem_guess*)callback_0014_guess, 1, 1.0f, 0, 9,
                                         0, 1500, 5000, 0);
        }

        if (callback_0020_guess != 0) {
            listener->FUN_004c6a99_guess(2, (IndexedItem_guess*)callback_0020_guess, 0, 1.0f, 0, 3, 1000, 3000, 4000, 1);
        } else {
            listener->FUN_004c6a99_guess(2, (IndexedItem_guess*)callback_0010_guess, 0, 1.0f, 0, 3, 1500, 3000, 4000, 0);
        }
        if (callback_001c_guess != 0) {
            listener->FUN_004c6a99_guess(8, (IndexedItem_guess*)callback_001c_guess, 0, 1.0f, 1, 2, 1500, 1500, 2500, 1);
        } else {
            listener->FUN_004c6a99_guess(8, (IndexedItem_guess*)callback_0010_guess, 3, 1.0f, 1, 2, 1500, 1500, 2500, 0);
        }
        listener->FUN_004c6a99_guess(3, (IndexedItem_guess*)callback_0010_guess, 21, 1.0f, 0, 5, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(6, (IndexedItem_guess*)callback_0010_guess, 21, 1.0f, 0, 5, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(7, (IndexedItem_guess*)callback_0010_guess, 23, 1.0f, 0, 5, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(15, (IndexedItem_guess*)callback_0010_guess, 19, 1.0f, 0, 5, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(9, (IndexedItem_guess*)callback_0010_guess, 20, 1.0f, 0, 5, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(10, (IndexedItem_guess*)callback_0010_guess, 7, 1.0f, 0, 6, 1500, 2500, 3500, 0);
        listener->FUN_004c6a99_guess(11, (IndexedItem_guess*)callback_0010_guess, 8, 1.0f, 0, 5, 1500, 1500, 2500, 0);
        listener->FUN_004c6a99_guess(12, (IndexedItem_guess*)callback_0010_guess, 9, 1.0f, 0, 5, 1500, 1500, 2500, 0);
        listener->FUN_004c6a99_guess(13, (IndexedItem_guess*)callback_0010_guess, 10, 1.0f, 0, 5, 1500, 1500, 2500, 0);
        listener->FUN_004c6a99_guess(14, (IndexedItem_guess*)callback_0010_guess, 11, 1.0f, 0, 5, 1500, 1500, 2500, 0);
        listener->FUN_004c6a99_guess(5, 0, 0, 1.0f, 0, 0, 1600, 1400, 10000, 0);
    }
}

// EXTERNAL: TITANIUM 0x004C4FA1 FUN_004c4fa1_guess
float __cdecl FUN_004c4fa1_guess(int value);

// Creates the emitter (a Track) for one half of a <zone>_sounds.eff record; 0x0044BED1 passes the record's
// fields. Types 0, 2 and 3 play wave `index` from the zone bank, type 1 is music: mp3 number -index when
// index < 0, else track `index` of the zone music at +0x24. Null when sound is off or the type is unknown.
// FUNCTION: TITANIUM 0x0044BA79
// @early-stop: budget, structural ndiff=159
Track_guess* EqSoundManagerView_guess::CreateSoundEmitter_guess(int type, float value_c, float value_10,
                                              float value_14, int value_18, int value_1c,
                                              int value_20, float value_24, int value_28,
                                              int value_2c, int index) {
    if (disabled != 0) {
        return 0;
    }

    Track_guess* result = 0;
    int values[4];
    memset(values, 0, 0x10);
    values[0] = 0;
    values[1] = 0;
    values[2] = 1;

    // A negative range is kept (as a positive int) in the first parameter word and the range becomes 10000.
    if (value_24 < 0.0) {
        values[0] = (int)-value_24;
        value_24 = 10000.0f;
    }

    if (type != 0) {
        if (type != 1) {
            if (type <= 1 || type > 3) {
                return result;
            }
        } else {
            if (index < 0) {
                IndexedItem_guess* item = GetMp3Asset_guess(-index);
                if (item != 0) {
                    int counter = activeCount_guess++;
                    int limit = value_2c;
                    if (limit > 20000) {
                        limit = 20000;
                    }
                    ((SoundListener_guess*)third_guess)->FUN_004c6a99_guess(
                        counter, item, 0, 1.0f, 0, (int)(value_24 + 0.5f), value_28,
                        1500, limit, 1);

                    Track_guess* track = new Track_guess(second_guess, third_guess, counter);
                    track->field_24 = value_c;
                    track->field_2c = -value_14;
                    track->field_28 = value_10;
                    track->field_20 = value_18;
                    track->field_08 = 1.0f;
                    track->field_40 = value_1c;
                    track->field_44 = value_1c + value_20;
                    track->field_3c = value_24;
                    track->field_34 = 0.0f;
                    track->field_30 = 0.0f;
                    result = track;
                    memcpy(track->field_48, values, 0x10);
                    track->field_18 = value_28;
                    track->field_1c = limit;
                }
            } else if (node24_guess != 0) {
                int counter = activeCount_guess++;
                int limit = value_2c;
                if (limit > 20000) {
                    limit = 20000;
                }
                ((SoundListener_guess*)third_guess)->FUN_004c6a99_guess(
                    counter, (IndexedItem_guess*)node24_guess, index, 1.0f, 0,
                    (int)(value_24 + 0.5f), value_28, 1500, limit, 0);

                Track_guess* track = new Track_guess(second_guess, third_guess, counter);
                track->field_24 = value_c;
                track->field_2c = -value_14;
                track->field_28 = value_10;
                track->field_20 = value_18;
                track->field_08 = 1.0f;
                track->field_40 = value_1c;
                track->field_44 = value_1c + value_20;
                track->field_3c = value_24;
                track->field_34 = 0.0f;
                track->field_30 = 0.0f;
                result = track;
                memcpy(track->field_48, values, 0x10);
                track->field_18 = value_28;
                track->field_1c = limit;
            }
            return result;
        }
    }

    IndexedItem_guess* item = entries[index].item;
    if (item != 0) {
        Track_guess* track = new Track_guess(second_guess, item, 3);
        track->field_24 = value_c;
        track->field_2c = -value_14;
        track->field_28 = value_10;
        result = track;

        if (-value_18 < 0) {
            track->field_08 = FUN_004c4fa1_guess(-value_18);
        } else if (type != 0) {
            track->field_08 = 1.0f;
        } else {
            track->field_08 = 0.2f;
        }

        int start = 0;
        // A positive delay makes the wave repeat; with an extra time (value_20) the start moves 500 later.
        if (value_1c < 1) {
            track->field_20 = 0;
            track->field_44 = 0;
        } else {
            track->field_20 = 1;
            if (value_20 > 0) {
                start = value_1c + 500;
                track->field_44 = value_1c + 500 + value_20;
            } else {
                start = value_1c;
                track->field_44 = value_1c;
            }
        }
        track->field_40 = start;
        track->field_3c = value_24;
        memcpy(track->field_48, values, 0x10);

        track->field_1c = value_2c;
        if (type == 0) {
            track->field_30 = 0.0f;
            track->field_34 = 0.0f;
        } else if (type == 3) {
            track->field_30 = 8.0f;
            track->field_38 = (float)value_28 + 150.0f;
            track->field_34 = 100.0f;
        } else if (type == 2) {
            if (value_28 < 3) {
                track->field_30 = 3.0f;
            } else {
                track->field_30 = (float)value_28;
            }
            track->field_34 = 100.0f;
        }
    }

    return result;
}

// map::find for string keys: the lower bound of `key` (0x0042639C), or the end (+4) when that is the end
// or `key` sorts before its key (+0xC, 0x00402D20). Written through `output`, which is returned.
// FUNCTION: TITANIUM 0x0044BE5D
int* TextIndex_guess::Resolve_guess(int* output, const char* key) {
    int* item = Find_guess(key);
    int** selected;
    if (item != current_guess && !CompareText_guess(key, (const char*)(item + 3))) {
        selected = &item;
    } else {
        key = (const char*)current_guess;
        selected = (int**)&key;
    }
    *output = (int)*selected;
    return output;
}

struct SoundRow_guess {
    char name_00[0x20];                 // 0x00
    int outdoorEnvironment_0020_guess;                       // 0x20
    int indoorEnvironment_0024_guess;                       // 0x24
    int enclosedEnvironment_0028_guess;                       // 0x28
};

#define g_soundRows_guess EQ_ARRAY(SoundRow_guess, 0x00787F50)

struct EqMobileEmitter_guess {
    Callback8_guess* target;            // 0x00
    EqSoundManager_guess* controller;   // 0x04
    EqMobileEmitter_guess(EqSoundManager_guess* controller_arg);
};

// Mobile sound emitter constructor (spawns and path followers make these): unless sound is disabled,
// creates its 3D sound source (0x004C6658) on the mixer with no wave yet, +0x30 = 3.0 and +0x34/+0x3C = 72
// (24 times that), and attaches it.
// FUNCTION: TITANIUM 0x0044A9E2
EqMobileEmitter_guess::EqMobileEmitter_guess(EqSoundManager_guess* controller_arg) {
    controller = controller_arg;
    if (controller_arg->disabled != 0) {
        target = 0;
    } else {
        target = new Callback8_guess(controller->mixer, (IndexedItem_guess*)0, 0);
        target->value40_guess = 0;
        target->value44_guess = 0;
        target->value20_guess = 0;
        target->value30_guess = 3.0f;
        target->value34_guess = target->value30_guess * 24.0f;
        target->value3c_guess = target->value34_guess;
        controller->mixer->Attach_guess(target);
    }
}

// Two looping emitters (waves 0x9F and 0x9E), half volume, off at start; they fade in over 2000 ms and out
// over 3000 ms (+0x18/+0x1C) and get no spatial range (+0x30/+0x34/+0x3C zero).
// FUNCTION: TITANIUM 0x0044ADE4
void EqSoundManager_guess::LoadGlobalEmitters_guess() {
    if (disabled == 0) {
        filterA = new Callback8_guess(mixer, ((EqSoundManagerView_guess*)this)->GetEntry_guess(0x9f), 0);
        filterA->value40_guess = 0;
        filterA->value44_guess = 0;
        filterA->value20_guess = 0;
        filterA->value3c_guess = 0.0f;
        filterA->value30_guess = 0.0f;
        filterA->value34_guess = 0.0f;
        filterA->value18_guess = 2000;
        filterA->value1c_guess = 3000;
        filterA->value08_guess = 0.5f;
        filterA->SetEnabled_guess(0);
        mixer->Attach_guess(filterA);
        filterB = new Callback8_guess(mixer, ((EqSoundManagerView_guess*)this)->GetEntry_guess(0x9e), 0);
        filterB->value40_guess = 0;
        filterB->value44_guess = 0;
        filterB->value20_guess = 0;
        filterB->value3c_guess = 0.0f;
        filterB->value30_guess = 0.0f;
        filterB->value34_guess = 0.0f;
        filterB->value18_guess = 2000;
        filterB->value1c_guess = 3000;
        filterB->value08_guess = 0.5f;
        filterB->SetEnabled_guess(0);
        mixer->Attach_guess(filterB);
    }
}

// Loads emitters from "<zone>.emt"; false when the file is missing.
// FUNCTION: TITANIUM 0x0044BD94
bool EqSoundManager_guess::EmitterLoad_guess(const char* path) {
    if (disabled != 0) {
        return false;
    }
    char line[1024];
    char fileName[256];
    if (path == 0) {
        sprintf(fileName, "%s.emt", (const char*)block_ac44);
        path = fileName;
    }
    SoundPart_guess part;
    FILE* file = fopen(path, "rt");
    if (file != 0) {
        while (!feof(file)) {
            line[0] = 0;
            fgets(line, 0x400, file);
            if (strlen(line) > 10) {
                part.Load_guess(line);
                AddEmitter_guess(&part);
            }
        }
        fclose(file);
        return true;
    }
    return false;
}

struct IndexEntry_guess {
    unsigned char reserved_00_guess[0x28];
    int value_guess;    // 0x28
};

// The index is keyed by std::string; Resolve_guess takes the key by address.
inline const char* StringKey_guess(const std::string& key_guess) {
    return (const char*)&key_guess;
}

// Sound index registered for this name by 0x0044C7E0 (map +0xBAEC), or -1 when the name is unknown.
// FUNCTION: TITANIUM 0x0044C325
int EqSoundManager_guess::GetDynamicAssetId_guess(const char* name_guess) {
    int output_guess;
    int found_guess = *((TextIndex_guess*)&list_baec)->Resolve_guess(
        &output_guess, StringKey_guess(name_guess));
    if (found_guess == (int)((TextIndex_guess*)&list_baec)->current_guess) {
        return -1;
    }
    return ((IndexEntry_guess*)found_guess)->value_guess;
}

// Loads wave `index` under its registered name (table +0xBADC) into slot `index`; spawn sounds,
// switch sounds and the animation mapper (0x004893EB) use it.
// FUNCTION: TITANIUM 0x0044BEA0
void EqSoundManager_guess::WaveLoadById_guess(int index, char flag) {
    CXStr* found = table_badc.Lookup_guess(index);
    if (found != 0) {
        ((EqSoundManagerView_guess*)this)->WaveLoad_guess((char*)*found, index, flag);
    }
}

struct SoundRecord_guess {
    char name_00_guess[0x10];
    float value_10_guess;
    float value_14_guess;
    float value_18_guess;
    float value_1c_guess;
    int value_20_guess;
    int value_24_guess;
    int value_28_guess;
    int value_2c_guess;
    int value_30_guess;
    int value_34_guess;
    unsigned char type_38_guess;
    unsigned char type_39_guess;
    unsigned char reserved_3a_guess[2];
    int value_3c_guess;
    int value_40_guess;
    int value_44_guess;
    int value_48_guess;
    int value_4c_guess;
    int value_50_guess;
};

// The pre-.emt emitter format: "<zone>_sndbnk.eff" (wave names under EMIT and LOOP) and the binary
// "<zone>_sounds.eff" (0x54-byte records).
// FUNCTION: TITANIUM 0x0044BED1
// @early-stop: budget, structural ndiff=57
void EqSoundManager_guess::LoadOldEmitters_guess() {
    char line[256];
    char fileName[512];

    if (disabled == 0 && block_ac44[0] != 0) {
        sprintf(fileName, "%s_sndbnk.eff", (char*)block_ac44);
        FILE* bankFile = fopen(fileName, "rt");
        if (bankFile != 0) {
            int index = 1;
            while ((bankFile->_flag & 0x10) == 0) {
                line[0] = 0;
                fgets(line, 0x100, bankFile);
                RemoveCharacter_guess(line, 0x0d);
                RemoveCharacter_guess(line, 0x0a);
                RemoveCharacter_guess(line, 0x20);
                if (_stricmp(line, "EMIT") == 0) {
                    index = 1;
                } else if (_stricmp(line, "LOOP") == 0) {
                    index = 0xa2;
                } else if (line[0] != 0) {
                    if (strchr(line, '.') == 0) {
                        strcat(line, ".wav");
                    }
                    ((EqSoundManagerView_guess*)this)->WaveLoad_guess(line, index, 1);
                    ++index;
                }
            }
            fclose(bankFile);
        }

        sprintf(fileName, "%s_sounds.eff", (char*)block_ac44);
        FILE* soundFile = fopen(fileName, "rb");
        if (soundFile != 0) {
            while ((soundFile->_flag & 0x10) == 0) {
                SoundRecord_guess record;
                if (fread(&record, 1, 0x54, soundFile) == 0x54) {
                    char same = 0;
                    if (record.type_38_guess == record.type_39_guess &&
                        record.value_3c_guess == record.value_40_guess &&
                        record.value_20_guess == record.value_24_guess &&
                        record.value_30_guess == record.value_34_guess) {
                        same = 1;
                    }
                    if (record.type_38_guess == 2) {
                        same = 1;
                    }

                    Callback8_guess* callback = (Callback8_guess*)((EqSoundManagerView_guess*)this)->CreateSoundEmitter_guess(
                        record.type_38_guess, record.value_10_guess, record.value_14_guess,
                        record.value_18_guess, record.value_3c_guess, record.value_20_guess,
                        record.value_28_guess, record.value_1c_guess, record.value_4c_guess,
                        record.value_44_guess, record.value_30_guess);
                    if (callback != 0) {
                        callback->third_guess = 1;
                        callback->second_guess = same == 0;
                        callback->SetEnabled_guess(1);
                        callbacks[callbackCount] = callback;
                        ++callbackCount;
                        mixer->Attach_guess(callback);
                    }

                    if (same == 0) {
                        callback = (Callback8_guess*)((EqSoundManagerView_guess*)this)->CreateSoundEmitter_guess(
                            record.type_38_guess, record.value_10_guess, record.value_14_guess,
                            record.value_18_guess, record.value_40_guess, record.value_24_guess,
                            record.value_28_guess, record.value_1c_guess, record.value_50_guess,
                            record.value_48_guess, record.value_34_guess);
                        if (callback != 0) {
                            callback->second_guess = 2;
                            callback->third_guess = 1;
                            callback->SetEnabled_guess(0);
                            callbacks[callbackCount] = callback;
                            ++callbackCount;
                            mixer->Attach_guess(callback);
                        }
                    }
                }
            }
            fclose(soundFile);
        }
    }
}

// Loads `count` waves from id `first` on, unless sound is disabled.
// FUNCTION: TITANIUM 0x0044C18E
void EqSoundManager_guess::WaveLoadRange_guess(int first, int count) {
    if (!disabled) {
        for (int i = 0; i < count; i++) {
            WaveLoadById_guess(first + i, 0);
        }
    }
}

// Zone change: drops the old zone's sounds and music, loads <zone>.xmi and its emitters, and takes the zone's
// music track numbers from its 127-row zone table (defaults 2, 12, 19).
// FUNCTION: TITANIUM 0x0044C1BC
void EqSoundManager_guess::SetCurrentZone_guess(const char* name) {
    if (disabled == 0 && (name == 0 || _stricmp(name, (const char*)block_ac44) != 0)) {
        ((EqSoundManagerView_guess*)this)->UnloadZoneWaves_guess();
        ((EqSoundManagerView_guess*)this)->RemoveAllEmitters_guess();
        ((EqSoundManagerView_guess*)this)->ReleaseZoneMusic_guess();
        ((EqSoundManagerView_guess*)this)->ClearIndexedItems_guess();
        indoorEnvironment_0fe0_guess = 2;
        enclosedEnvironment_0fe4_guess = 12;
        outdoorEnvironment_0fe8_guess = 19;
        block_ac44[0] = 0;
        if (name != 0) {
            strcpy((char*)block_ac44, name);
            char xmiPath[256];
            char emtPath[256];
            sprintf(xmiPath, "%s.xmi", (const char*)block_ac44);
            value_0024 = (int)((EqSoundManagerView_guess*)this)->GetAsset_guess(xmiPath);
            sprintf(emtPath, "%s.emt", (const char*)block_ac44);
            if (!EmitterLoad_guess(emtPath)) {
                LoadOldEmitters_guess();
            }
            for (unsigned int i = 0; i < 127; i++) {
                if (_stricmp(g_soundRows_guess[i].name_00, name) == 0) {
                    indoorEnvironment_0fe0_guess = g_soundRows_guess[i].indoorEnvironment_0024_guess;
                    enclosedEnvironment_0fe4_guess = g_soundRows_guess[i].enclosedEnvironment_0028_guess;
                    outdoorEnvironment_0fe8_guess = g_soundRows_guess[i].outdoorEnvironment_0020_guess;
                    break;
                }
            }
        }
        filterValue = 0;
        mode = 0;
    }
}

// Preloads the global waves: blocks of 10 from 0x20, then 0x5C-0xA1, 0x50F-0x514 and the dynamic range up to
// 4999. The first two blocks are loaded twice (harmless: already loaded).
// FUNCTION: TITANIUM 0x0044C386
void EqSoundManager_guess::LoadGlobalWaves_guess() {
    if (disabled == 0) {
        WaveLoadRange_guess(0x20, 10);
        WaveLoadRange_guess(0x2a, 10);
        WaveLoadRange_guess(0x34, 10);
        WaveLoadRange_guess(0x3e, 10);
        WaveLoadRange_guess(0x48, 10);
        WaveLoadRange_guess(0x52, 10);
        WaveLoadRange_guess(0x20, 10);
        WaveLoadRange_guess(0x2a, 10);
        WaveLoadRange_guess(0x5c, 0x46);
        WaveLoadRange_guess(0x50f, 4);
        WaveLoadRange_guess(0x513, 2);
        WaveLoadRange_guess(value_baf8 + 1, 4999 - value_baf8);
    }
}

// Gives a new sound name the current dynamic id (+0xBAF8, counting down from 4999) and moves the counter
// down; -1 when it is negative or that id is already in use (no search for a free one).
// FUNCTION: TITANIUM 0x0044C7E0
// @early-stop: budget, structural ndiff=4
int EqSoundManager_guess::AddDynamicAsset_guess(const char* value) {
    if (value_baf8 < 0 || entries[value_baf8].item != 0) {
        return -1;
    }
    {
        ClientString_guess name_guess(value);
        *list_baec.Insert_guess(&name_guess) = value_baf8;
    }
    return value_baf8--;
}

// Reads a name list (one per line, '^'-separated ids) into the dynamic assets; logs "Sound Manager has no
// more
// room for dynamic assets..." when full and "Sound Manager loaded %d filenames from %s." at the end.
// FUNCTION: TITANIUM 0x0044C859
// @early-stop: budget, structural ndiff=99
void EqSoundManager_guess::LoadAssets_guess(const char* name) {
    int loaded = 0;
    TextFileReader_guess* reader;
    void* storage = ::operator new(0x1000c);
    if (storage != 0) {
        reader = new (storage) TextFileReader_guess(name, 0x5e);
    } else {
        reader = 0;
    }
    if (reader->IsOpen_guess()) {
        while (reader->GetLineCount_guess() > 0) {
            int bufferSize = 0x100;
            char line[0x1000];
            char token[0x100];
            char soundName[0x100];
            reader->ReadLine_guess(line, 0x1000);
            char* cursor = line;
            while (*cursor != 0) {
                int width = 0;
                if (FUN_00574860_guess(cursor, &width) == 0) {
                    break;
                }
                cursor += width;
            }
            if (*cursor != '#' && *cursor != 0 && *cursor != '\n') {
                int soundId;
                if (FUN_00574830_guess(cursor, 0) == 0) {
                    FUN_00576D20_guess(token, bufferSize, &cursor, 0x5e);
                    if (token[0] != 0) {
                        soundId = AddDynamicAsset_guess(token);
                        if (soundId == -1) {
                            FUN_00574110_guess("Sound Manager has no more room for dynamic assets.  Cannot load \"%s\".", token);
                            continue;
                        }
                    } else {
                        soundId = 0;
                    }
                } else {
                    soundId = FUN_00576D80_guess(&cursor, 0x5e);
                }
                if (soundId != 0) {
                    FUN_00576D20_guess(soundName, bufferSize, &cursor, 0x5e);
                    CXStr soundNameString(soundName);
                    table_badc.FUN_00435671_guess(&soundNameString, soundId);
                    ++loaded;
                }
            }
        }
    }
    if (reader != 0) {
        reader->Close_guess();
        delete reader;
    }
    FUN_00574110_guess("Sound Manager loaded %d filenames from %s.", loaded, name);
}

// Shuts sound down: unloads the zone, the mp3 list and the two filter emitters, stops and releases all
// 5000 wave slots and the six fixed sounds, unloads snd1.pfs-snd17.pfs, then deletes the bank, mixer,
// listener and device.
// FUNCTION: TITANIUM 0x0044C426
EqSoundManager_guess::~EqSoundManager_guess() {
    if (disabled == 0) {
        SetCurrentZone_guess(0);
        ((EqSoundManagerView_guess*)this)->ReleaseMp3Index_guess();
        if (filterA != 0) {
            mixer->Detach_guess(filterA);
            ((Callback0_guess*)filterA)->Release_guess();
            filterA = 0;
        }
        if (filterB != 0) {
            mixer->Detach_guess(filterB);
            ((Callback0_guess*)filterB)->Release_guess();
            filterB = 0;
        }
        IndexedEntry_guess* entry = entries;
        int count = 5000;
        do {
            if (entry->item != 0) {
                ((Callback0_guess*)entry->item)->SetVolume_guess(0.0f, 0);
                ((Callback0_guess*)entry->item)->Release_guess();
                entry->item = 0;
            }
            ++entry;
            --count;
        } while (count != 0);
        if (callback_0010_guess != 0) {
            callback_0010_guess->SetVolume_guess(0.0f, 0);
            callback_0010_guess->Release_guess();
            callback_0010_guess = 0;
        }
        if (callback_0014_guess != 0) {
            callback_0014_guess->SetVolume_guess(0.0f, 0);
            callback_0014_guess->Release_guess();
            callback_0014_guess = 0;
        }
        if (callback_0018_guess != 0) {
            callback_0018_guess->SetVolume_guess(0.0f, 0);
            callback_0018_guess->Release_guess();
            callback_0018_guess = 0;
        }
        if (callback_0020_guess != 0) {
            callback_0020_guess->SetVolume_guess(0.0f, 0);
            callback_0020_guess->Release_guess();
            callback_0020_guess = 0;
        }
        if (callback_001c_guess != 0) {
            callback_001c_guess->SetVolume_guess(0.0f, 0);
            callback_001c_guess->Release_guess();
            callback_001c_guess = 0;
        }
        if (callback_0028_guess != 0) {
            callback_0028_guess->SetVolume_guess(0.0f, 0);
            callback_0028_guess->Release_guess();
            callback_0028_guess = 0;
        }
        archives->Unload_guess(SoundPath_guess("snd1.pfs"));
        archives->Unload_guess(SoundPath_guess("snd2.pfs"));
        archives->Unload_guess(SoundPath_guess("snd3.pfs"));
        archives->Unload_guess(SoundPath_guess("snd4.pfs"));
        archives->Unload_guess(SoundPath_guess("snd5.pfs"));
        archives->Unload_guess(SoundPath_guess("snd6.pfs"));
        archives->Unload_guess(SoundPath_guess("snd7.pfs"));
        archives->Unload_guess(SoundPath_guess("snd8.pfs"));
        archives->Unload_guess(SoundPath_guess("snd9.pfs"));
        archives->Unload_guess(SoundPath_guess("snd10.pfs"));
        archives->Unload_guess(SoundPath_guess("snd11.pfs"));
        archives->Unload_guess(SoundPath_guess("snd12.pfs"));
        archives->Unload_guess(SoundPath_guess("snd13.pfs"));
        archives->Unload_guess(SoundPath_guess("snd14.pfs"));
        archives->Unload_guess(SoundPath_guess("snd15.pfs"));
        archives->Unload_guess(SoundPath_guess("snd16.pfs"));
        archives->Unload_guess(SoundPath_guess("snd17.pfs"));
        FreeObject_guess(archives);
        delete bank;
        delete mixer;
        delete listener;
        delete device;
    }
}

// Opens the device (44100 or 22050 Hz, `speakerType`), the snd*.pfs archives and soundassets.txt; `disable`
// turns every sound call into a no-op.
// FUNCTION: TITANIUM 0x0044CA8F
EqSoundManager_guess::EqSoundManager_guess(bool disable, bool highRate, int speakerType)
    : table_badc(0x100) {
    bank = 0;
    listener = 0;
    mixer = 0;
    device = 0;
    callback_0028_guess = 0;
    value_0024 = 0;
    filterA = 0;
    filterB = 0;
    memset(block_ac44, 0, 0x80);
    memset(entries, 0, 0x9c40);
    value_0fec = 1.0f;
    value_0ff0 = 1.0f;
    callbackCount = 0;
    flag_0ff4 = 0;
    visualState = 0;
    flag_0ff6 = 0;
    filterValue = 0;
    mode = 0;
    filterFlag = 0;
    indoorEnvironment_0fe0_guess = 2;
    enclosedEnvironment_0fe4_guess = 12;
    outdoorEnvironment_0fe8_guess = 19;
    nextEmitterIndex_0030_guess = 16;
    disabled = disable;
    if (!disable) {
        value_baf8 = 4999;
        LoadAssets_guess("soundassets.txt");
        device = new SoundDevice_guess(0x10, 6, 1, highRate ? 44100 : 22050, 0x10, 1, speakerType);
        device->AddInstances_guess(0, 1, 1);
        device->AddInstances_guess(1, 2, 2);
        device->AddInstances_guess(0, 2, 1);
        device->AddInstances_guess(1, 3, 4);
        device->AddInstances_guess(0, 3, 2);
        listener = new SoundListener_guess;
        mixer = new SoundMixer_guess(device);
        bank = new SoundBank_guess(device, listener);
        archives = new SoundArchives_guess;
        archives->Load_guess("snd1.pfs");
        archives->Load_guess("snd2.pfs");
        archives->Load_guess("snd3.pfs");
        archives->Load_guess("snd4.pfs");
        archives->Load_guess("snd5.pfs");
        archives->Load_guess("snd6.pfs");
        archives->Load_guess("snd7.pfs");
        archives->Load_guess("snd8.pfs");
        archives->Load_guess("snd9.pfs");
        archives->Load_guess("snd10.pfs");
        archives->Load_guess("snd11.pfs");
        archives->Load_guess("snd12.pfs");
        archives->Load_guess("snd13.pfs");
        archives->Load_guess("snd14.pfs");
        archives->Load_guess("snd16.pfs");
        archives->Load_guess("snd15.pfs");
        archives->Load_guess("snd17.pfs");
        ((EqSoundManagerView_guess*)this)->OldMp3Init_guess();
        LoadGlobalMusic_guess();
        LoadGlobalWaves_guess();
        LoadGlobalEmitters_guess();
    }
}
