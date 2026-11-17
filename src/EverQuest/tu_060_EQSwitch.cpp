// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 60: a hint from compare/tumap.py.
// Doors and switches (EQSwitch_guess, one per zone door; the list at 0x903E84). `kind`, the open
// type, picks the model behaviour, speed, sounds and repop time; states are 0 closed, 1 open, 2 opening,
// 3 closing, 4 triggered (traps). Clicks go to the server as OP_ClickDoor unless the client runs the door
// itself; lock text is strings 129-132.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"

#include "titanium/core_decls.h"
struct Entry_guess {
    char pad00_guess[1];
    unsigned char field01_guess;
    char pad02_guess[0x4d];
    char field4f_guess;
    char pad50_guess[0x40];
    int id;
};

struct Collection_guess {
    int count;
    Entry_guess* entries[1];

    int GetCount_guess();
    Entry_guess* Find_guess(int id);
    Entry_guess* FindMatching_guess(unsigned int value_guess, char kind_guess);
    Entry_guess* GetAt_guess(int index);
    void Add_guess(Entry_guess* entry);
    void Remove_guess(Entry_guess* entry_guess);
    void Clear_guess();
};

struct RecordSource_guess {
    char name00_guess[0x20];
    int field20_guess;
    int field24_guess;
    int field28_guess;
    int field2c_guess;
    int field30_guess;
    short field34_guess;
    char pad36_guess[0x3c - 0x36];
    char field3c_guess;
    char field3d_guess;
    char field3e_guess;
    char field3f_guess;
    short field40_guess;
    char pad42_guess[0x44 - 0x42];
    int field44_guess;
    int field48_guess;
    char field4c_guess;
    char field4d_guess;
    char field4e_guess;
    char field4f_guess;
};

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x0060E620 strncpy
extern "C" char* __cdecl strncpy(char* dest_guess, char* src_guess, unsigned int count_guess);
// EXTERNAL: TITANIUM 0x0060DD40 memmove
extern "C" void* __cdecl memmove(void* dest_guess, void* src_guess, unsigned int size_guess);

struct Owner_guess;

union Amount_guess {
    int value_guess;
    char bytes_guess[4];
};

struct EQSwitch_guess {
    unsigned char type00_guess;  // 0x00
    char field01_guess;          // 0x01
    char name02_guess[0x1f];     // 0x02
    char pad21_guess;            // 0x21
    unsigned char kind;          // 0x22
    char state_guess;            // 0x23
    float field24_guess;         // 0x24
    float field28_guess;         // 0x28
    float field2c_guess;         // 0x2c
    float field30_guess;         // 0x30
    float field34_guess;         // 0x34
    float field38_guess;         // 0x38
    float field3c_guess;         // 0x3c
    float field40_guess;         // 0x40
    float field44_guess;         // 0x44
    float field48_guess;         // 0x48
    char field4c_guess;          // 0x4c
    char field4d_guess;
    char field4e_guess;
    char field4f_guess;          // 0x4f
    unsigned char level50_guess; // 0x50
    char field51_guess[5];
    char field56_guess[5];
    char pad5b_guess[0x62 - 0x5b];
    short field62_guess;         // 0x62
    short field64_guess;         // 0x64
    short field66_guess;         // 0x66
    char field68_guess[5];
    char field6d_guess;         // 0x6d
    char pad6e_guess[0x90 - 0x6e];
    int field90_guess;           // 0x90
    int field94_guess;           // 0x94
    int field98_guess;           // 0x98
    float field9c_guess;         // 0x9c
    char pada0_guess[0xa4 - 0xa0];
    int fielda4_guess;           // 0xa4
    float fielda8_guess;         // 0xa8
    float fieldac_guess;         // 0xac
    float fieldb0_guess;         // 0xb0
    int fieldb4_guess;           // 0xb4
    char fieldb8_guess;          // 0xb8
    char padb9_guess[0xbc - 0xb9];
    int fieldbc_guess;           // 0xbc
    char fieldc0_guess;          // 0xc0
    char fieldc1_guess;          // 0xc1
    char fieldc2_guess;          // 0xc2
    char padc3_guess[0x218 - 0xc3];
    int field218_guess;          // 0x218
    char pad21c_guess[0x23c - 0x21c];
    float field23c_guess;        // 0x23c
    char pad240_guess[4];
    char field244_guess;         // 0x244
    char pad245_guess[0x258 - 0x245];
    int field258_guess;          // 0x258

    char IsInMode_guess();
    int IsSpecial_guess();
    char IsAllowed_guess();
    char FUN_004903f1_guess();
    void SetState_guess(unsigned char kind_guess);
    void SetDefaults_guess();
    void CreateSwitchActor_guess();
    void ReleaseActor_guess();
    float TopSpeed_guess(float* out_guess);
    int GetSwitchDamage_guess();
    int RepopFrequency_guess();
    bool IsTrapWithoutSkill_guess(int value_guess);
    void LoadSwitchSounds_guess(unsigned int code_guess);
    void ChangeState_guess(char newState_guess, int arg2_guess, int arg3_guess);
    bool SwitchWasOpened_guess(int id_guess, int level_guess, Owner_guess* owner_guess, int unused_guess);
    void CopyFrom_guess(RecordSource_guess* src_guess);
    float GetTriggerRange_guess();
    EQSwitch_guess* InitFromDoorRecord_guess(RecordSource_guess* src_guess);
    void UseSwitch_guess(unsigned int string_id_guess, int value_guess, Amount_guess amount_guess, float range_guess);
};

#define g_mode_guess EQ_GLOBAL(int, 0x00924470)

struct Sink_guess {
    // EXTERNAL: TITANIUM 0x0044BEA0 Sink_guess::WaveLoadById_guess
    void WaveLoadById_guess(int value_guess, int flag_guess);
};

#define g_sink_guess EQ_GLOBAL(Sink_guess*, 0x00851390)

struct Service_guess {
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
    virtual void Slot25_guess(int value_guess);
};

#define g_service_guess EQ_GLOBAL(Service_guess*, 0x0099E368)

struct Actor_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess(EQSwitch_guess* record_guess);
    virtual void Slot04_guess(int value_guess);
    virtual void Slot05_guess();
    virtual void Slot06_guess(int value_guess);
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess(unsigned int value_guess);
    virtual unsigned int Slot13_guess();
    virtual float Slot14_guess();
};

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x00439A46 Manager_guess::Release_guess
    void Release_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004395E2 Manager_guess::PlaySoundAtLocation_guess
    void PlaySoundAtLocation_guess(float x_guess, float y_guess, float z_guess, int id_guess);
    // EXTERNAL: TITANIUM 0x0043972A Manager_guess::CreateActor_guess
    int CreateActor_guess(char* name_guess, float a_guess, float b_guess, float c_guess, float d_guess, float e_guess, float f_guess, int g_guess, int h_guess);
    // EXTERNAL: TITANIUM 0x00439C41 Manager_guess::TrueDistance_guess
    float TrueDistance_guess(float a_guess, float b_guess, float c_guess, float d_guess, float e_guess, float f_guess, float g_guess);
    // EXTERNAL: TITANIUM 0x00438EBC Manager_guess::SetScale_guess
    void SetScale_guess(Actor_guess* actor_guess, float scale_guess, int flag_guess);
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00905D24)
#define g_flag_guess EQ_GLOBAL(char, 0x00923798)
#define g_source_record_guess EQ_GLOBAL(EQSwitch_guess*, 0x00905CE4)
#define g_alternate_record_guess EQ_GLOBAL(EQSwitch_guess*, 0x00905CF8)
#define g_collection_guess EQ_GLOBAL(Collection_guess*, 0x00903E84)
#define g_mode_record_guess EQ_GLOBAL(int, 0x00923884)

struct ModeState_guess {
    char pad00_guess[0xb54];
    int value_guess;
};

#define g_mode_state_guess EQ_GLOBAL(ModeState_guess*, 0x00988DF0)

struct Item_guess {
    char pad00_guess[0x10];
    Item_guess* next_guess;      // 0x10
};

struct Node_guess {
    Item_guess* head_guess;      // 0x0
    char pad04_guess[0xc];
    Node_guess* next_guess;      // 0x10
};

struct Table_guess {
    // EXTERNAL: TITANIUM 0x004466FA Table_guess::Begin_guess
    Node_guess* Begin_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A Table_guess::Next_guess
    Node_guess* Next_guess(Node_guess* node_guess);
    // EXTERNAL: TITANIUM 0x0048F513 Table_guess::Finish_guess
    void Finish_guess();
};

struct Outer_guess {
    char pad00_guess[0x42c];
    Table_guess table_guess;     // 0x42c
    void FreeBucketEntries_guess();
};

struct BytePair_guess {
    char pad[0x56];
    char left0_guess;
    char left1_guess;
    char left2_guess;
    char left3_guess;
    char left4_guess;
    char right0_guess;
    char right1_guess;
    char right2_guess;
    char right3_guess;
    char right4_guess;

    bool IsCombinationSet_guess();
};

// EXTERNAL: TITANIUM 0x00435B55 FUN_00435b55_guess
float __stdcall FUN_00435b55_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00610884 FUN_00610884_guess
double __cdecl FUN_00610884_guess(double value_guess);

// EXTERNAL: TITANIUM 0x005769E0 FUN_005769E0_guess
int __cdecl FUN_005769E0_guess(char* input_guess, char* output_guess, int size_guess, int delimiter_guess, int flag_guess);

// EXTERNAL: TITANIUM 0x0060EC17 _strtol
long __cdecl _strtol(const char* input_guess, char** end_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 atol
extern "C" long __cdecl atol(const char* input_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

struct DoubleWrapper_guess {
    double DistanceTo_guess(int value_guess);
};

// Distance between this point and `value` (square root of 0x00435B55); switch use, the path follower
// and the position history (0x004B5F5F) use it.
// FUNCTION: TITANIUM 0x0048F790
double DoubleWrapper_guess::DistanceTo_guess(int value_guess) {
    return FUN_00610884_guess(FUN_00435b55_guess(value_guess));
}

// Defaults: no key (-1), size 100 percent, kind 5, closed.
// FUNCTION: TITANIUM 0x0048F7B4
void EQSwitch_guess::SetDefaults_guess() {
    field62_guess = -1;
    fielda8_guess = 0;
    fielda4_guess = 0;
    fieldac_guess = 0;
    fieldb4_guess = 0;
    field64_guess = 100;
    field4f_guess = 0;
    fieldb0_guess = 0;
    type00_guess = 5;
    field6d_guess = 0;
    field90_guess = 0;
    field9c_guess = 0;
    kind = 0;
    state_guess = 0;
    field4c_guess = 0;
    fieldb8_guess = 0;
    fieldbc_guess = 0;
    fieldc0_guess = 1;
    fieldc1_guess = 0;
    fieldc2_guess = 1;
}

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* dest_guess, const char* format_guess, ...);

// Creates the model "<name>_ACTORDEF" at the door's position (kind 0x35 has none). Kinds 0x32, 0x36 and 0x39
// (at scale 1) keep their size; others are scaled by +0x64 percent (0 or 255 means 100). A door that starts
// open (+0xC1) begins opening.
// FUNCTION: TITANIUM 0x0048F826
void EQSwitch_guess::CreateSwitchActor_guess() {
    char buffer_guess[256];
    _sprintf(buffer_guess, "%s_ACTORDEF", name02_guess);
    if (field4f_guess == 0) {
        if (kind == 0x35) {
            field90_guess = 0;
            field94_guess = 0;
        } else {
            field90_guess = g_manager_guess->CreateActor_guess(buffer_guess, field38_guess, field3c_guess,
                field40_guess, field44_guess, field48_guess, 0.0f, 0, 0);
        }
        if (field90_guess == 0) {
            return;
        }
        reinterpret_cast<Actor_guess*>(field90_guess)->Slot04_guess(2);
        if (kind == 0x37 && g_flag_guess == 0) {
            unsigned int value_guess = reinterpret_cast<Actor_guess*>(field90_guess)->Slot13_guess();
            reinterpret_cast<Actor_guess*>(field90_guess)->Slot12_guess(value_guess & 0xfffffffd);
        }
    }
    if (field64_guess == 0xff || field64_guess < 1) {
        field64_guess = 100;
    }
    if (field62_guess == 0) {
        field62_guess = -1;
    }
    if (field4f_guess == 0) {
        if (field90_guess != 0) {
            reinterpret_cast<Actor_guess*>(field90_guess)->Slot03_guess(this);
            reinterpret_cast<Actor_guess*>(field90_guess)->Slot04_guess(2);
        }
        if (field90_guess != 0) {
            if (kind == 0x36 || (kind == 0x39 && field34_guess == 1.0f) || kind == 0x32) {
                reinterpret_cast<Actor_guess*>(field90_guess)->Slot06_guess(1);
            } else if (kind != 0x35) {
                g_manager_guess->SetScale_guess(reinterpret_cast<Actor_guess*>(field90_guess),
                    (float)field64_guess * 0.01f, 1);
            }
        }
        if (fieldc1_guess != 0) {
            state_guess = 2;
        }
        field98_guess = FUN_0046d655_guess();
    }
}

// Frees the model (kind 0x35 holds a different object at +0x94).
// FUNCTION: TITANIUM 0x0048F9C7
void EQSwitch_guess::ReleaseActor_guess() {
    if (field94_guess == 0 && field90_guess == 0) {
        return;
    }
    if (kind == 0x35) {
        if (field94_guess != 0) {
            g_service_guess->Slot25_guess(field94_guess);
            field94_guess = 0;
        }
    } else {
        if (field90_guess != 0) {
            g_manager_guess->Release_guess(field90_guess);
            field90_guess = 0;
        }
    }
}

// Speed for the moving kinds 0x64-0x6B and 0x73-0x74 (3, 9, 15 or 45); `out_guess` gets the matching
// acceleration. Others don't slide.
// FUNCTION: TITANIUM 0x0048FA18
float EQSwitch_guess::TopSpeed_guess(float* out_guess) {
    float result = 0.0f;
    switch (kind) {
    case 0x64:
    case 0x69:
        result = 3.0f;
        if (out_guess != 0) {
            *out_guess = 0.025f;
        }
        break;
    case 0x65:
    case 0x6a:
        result = 9.0f;
        if (out_guess != 0) {
            *out_guess = 0.075f;
        }
        break;
    case 0x66:
    case 0x6b:
        result = 15.0f;
        if (out_guess != 0) {
            *out_guess = 0.125f;
        }
        break;
    case 0x73:
    case 0x74:
        result = 45.0f;
        if (out_guess != 0) {
            *out_guess = 0.375f;
        }
        break;
    }
    return result;
}

// Milliseconds an open door stays open before closing itself. +0x66 overrides it for kinds 0x28/0x2D/0x32
// (32001 means 30 minutes); +0x66 of -2 or -3 never closes.
// FUNCTION: TITANIUM 0x0048FAA5
// @early-stop: budget, structural ndiff=30
int EQSwitch_guess::RepopFrequency_guess() {
    int result;
    switch (kind) {
    case 0:
    case 5:
        result = 10000;
        break;
    case 0x28:
    case 0x2d:
    case 0x32:
        if (field66_guess > 0) {
            result = field66_guess;
            if (field66_guess == 0x7d01) {
                result = 1800000;
            }
        } else {
            result = 20000;
        }
        break;
    case 0x35:
        result = (field4e_guess == 0);
        break;
    case 0x39:
    case 0x3a:
        result = 2000;
        break;
    case 0x3b:
        if (field66_guess > 0xaa) {
            result = 0;
        } else {
            result = 20000;
        }
        break;
    case 0x69:
    case 0x6a:
    case 0x6b:
        result = 0;
        break;
    case 0x73:
        result = 1;
        break;
    case 0x78:
    case 0x7d:
    case 0x87:
    case 0x92:
    case 0x98:
        result = 3000;
        break;
    case 0x82:
        result = 800;
        break;
    case 0x8c:
        result = 2000;
        break;
    case 0x96:
        result = 4000;
        break;
    case 0x23:
    case 0x24:
    case 0x74:
    case 0x91:
    case 0x97:
        result = 6000;
        break;
    default:
        result = 20000;
        break;
    }
    if (field66_guess == -2 || field66_guess == -3) {
        result = 0;
    }
    return result;
}

// Damage a trap kind deals (4, 10, 30 or 50); 0 for a plain door.
// FUNCTION: TITANIUM 0x0048FBC8
int EQSwitch_guess::GetSwitchDamage_guess() {
    int result = 0;
    switch (kind) {
    case 0x78:
    case 0x7d:
        result = 0x1e;
        break;
    case 0x73:
    case 0x74:
    case 0x82:
    case 0x87:
        result = 4;
        break;
    case 0x8c:
    case 0x91:
    case 0x96:
    case 0x97:
        result = 10;
        break;
    case 0x92:
    case 0x98:
        result = 0x32;
        break;
    }
    return result;
}

// Moves to `newState_guess` and plays the kind's open/close sound at the door. An always-open door (+0xC1)
// only
// goes to open (1) or opening (2); kinds 0x39/0x3A never change state.
// FUNCTION: TITANIUM 0x0048FC2E
void EQSwitch_guess::ChangeState_guess(char newState_guess, int arg2_guess, int arg3_guess) {
    if (fieldc1_guess != 0) {
        state_guess = 1;
        if (newState_guess != 2) {
            newState_guess = 1;
        }
    }
    if (newState_guess == 3) {
        field9c_guess = TopSpeed_guess(0);
    } else if (newState_guess == 1) {
        field9c_guess = 0;
    }
    if (kind == 0x39 || kind == 0x3a) {
        return;
    }
    if (state_guess == newState_guess) {
        return;
    }
    state_guess = newState_guess;
    switch (kind) {
    case 0:
    case 5:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0x87);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0x88);
        break;
    case 0x23:
    case 0x24:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0x87);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xbd);
        break;
    case 1:
    case 6:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb0);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xaf);
        break;
    case 0x3e:
    case 0x43:
    case 0x48:
    case 0x4d:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb8);
        }
        if (state_guess == 3) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb7);
        }
        if (state_guess != 0) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb6);
        break;
    case 0x3c:
    case 0x3d:
    case 0x41:
    case 0x42:
    case 0x46:
    case 0x47:
    case 0x4b:
    case 0x4c:
        if (newState_guess == 2 || newState_guess == 3) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb5);
        }
        if (state_guess != 0) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb6);
        break;
    case 0xa:
    case 0xb:
    case 0xc:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb8);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb7);
        break;
    case 0x1e:
        if (newState_guess == 2 || newState_guess == 3) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xad);
        }
        if (state_guess != 0) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xae);
        break;
    case 0x28:
        if (newState_guess != 2 && newState_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb4);
        break;
    case 0x3b:
        if (newState_guess != 2 && newState_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb9);
        break;
    case 0x6e:
        if (newState_guess != 2) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xac);
        break;
    case 0x78:
        if (newState_guess != 2) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xbb);
        break;
    case 0x7d:
        if (newState_guess != 2) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xbc);
        break;
    case 0x73:
    case 0x74:
    case 0x82:
    case 0x87:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0x77);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0x77);
        break;
    case 2:
    case 7:
    case 8:
    case 0x8c:
    case 0x91:
    case 0x92:
    case 0x96:
    case 0x97:
    case 0x98:
        if (newState_guess == 2) {
            g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb3);
        }
        if (state_guess != 3) {
            break;
        }
        g_manager_guess->PlaySoundAtLocation_guess(field38_guess, field3c_guess, field40_guess, 0xb2);
        break;
    }
    field98_guess = FUN_0046d655_guess();
}

struct Owner_guess {
    char pad00_guess[0x218];
    Sink_guess* sink218_guess;   // 0x218
    char pad21c_guess[0x244 - 0x21c];
    char flag244_guess;          // 0x244
};

// EXTERNAL: TITANIUM 0x004649B1 token_string_to_client_guess
void __cdecl token_string_to_client_guess(Sink_guess* sink_guess, int code_guess, int flags_guess, int extra_guess);

// Whether the clicker may operate the door. Traps: a disarm skill over the trap level (+0x50) wins, else
// "You failed to disarm the trap." (129). Locked doors (key item +0x62): the key opens, else the lockpick
// skill must beat +0x50: "It's locked and you're not holding the key." (130), "This lock cannot be picked."
// (131, difficulty over 209) or "You are not sufficiently skilled to pick this lock." (132). NPCs (+0x244)
// always pass. Keys of -2 and below need the key and an exact match of the passed value;
// the client does not say which doors use them.
// FUNCTION: TITANIUM 0x0049002C
// @early-stop: budget, diff ndiff=39
bool EQSwitch_guess::SwitchWasOpened_guess(int id_guess, int level_guess, Owner_guess* owner_guess, int unused_guess) {
    if (GetSwitchDamage_guess() > 0) {
        if (level50_guess < level_guess) {
            return 1;
        }
        if (owner_guess == 0) {
            return 0;
        }
        if (owner_guess->flag244_guess == 1) {
            return 1;
        }
        if (owner_guess->sink218_guess == 0) {
            return 0;
        }
        token_string_to_client_guess(owner_guess->sink218_guess, 0x81, 0xd, 0);
        return 0;
    }
    if (field62_guess == -1 || state_guess == 1) {
        return 1;
    }
    if (field66_guess <= -2) {
        if (id_guess != field62_guess) {
            return 0;
        }
        if (field66_guess == level_guess) {
            return 1;
        }
        return 0;
    }
    if (id_guess == field62_guess) {
        return 1;
    }
    if (level_guess < 1) {
        if (owner_guess == 0) {
            return 0;
        }
        if (owner_guess->sink218_guess == 0) {
            return 0;
        }
        token_string_to_client_guess(owner_guess->sink218_guess, 0x82, 0xd, 0);
        return 0;
    }
    if (level50_guess < level_guess) {
        return 1;
    }
    if (owner_guess == 0) {
        return 0;
    }
    if (owner_guess->sink218_guess == 0) {
        return 0;
    }
    if (level50_guess <= 0xd1) {
        token_string_to_client_guess(owner_guess->sink218_guess, 0x84, 0xd, 0);
    } else {
        token_string_to_client_guess(owner_guess->sink218_guess, 0x83, 0xd, 0);
    }
    return 0;
}

// Refreshes the door from a server door record; a door flagged always-open starts opening.
// FUNCTION: TITANIUM 0x00490449
void EQSwitch_guess::CopyFrom_guess(RecordSource_guess* src_guess) {
    if (src_guess == 0) {
        return;
    }
    strncpy(name02_guess, src_guess->name00_guess, 0x1f);
    *reinterpret_cast<int*>(&field24_guess) = src_guess->field20_guess;
    *reinterpret_cast<int*>(&field28_guess) = src_guess->field24_guess;
    *reinterpret_cast<int*>(&field2c_guess) = src_guess->field28_guess;
    *reinterpret_cast<int*>(&field30_guess) = src_guess->field2c_guess;
    field34_guess = (float)src_guess->field30_guess;
    field64_guess = src_guess->field34_guess;
    field01_guess = src_guess->field3c_guess;
    kind = src_guess->field3d_guess;
    state_guess = src_guess->field3e_guess;
    field4c_guess = src_guess->field3f_guess;
    field66_guess = src_guess->field40_guess;
    fielda4_guess = src_guess->field44_guess;
    fieldb4_guess = src_guess->field48_guess;
    fieldb8_guess = src_guess->field4c_guess;
    fieldc0_guess = src_guess->field4d_guess;
    fieldc1_guess = src_guess->field4e_guess;
    fieldc2_guess = src_guess->field4f_guess;
    if (fieldc1_guess != 0) {
        ChangeState_guess(2, 0, 0);
    }
}

// EXTERNAL: TITANIUM 0x0048FBC8 GetSwitchDamage_guess
int __cdecl GetSwitchDamage_guess();

// True for a trap clicked with no skill (`value_guess` < 1).
// FUNCTION: TITANIUM 0x00490117
bool EQSwitch_guess::IsTrapWithoutSkill_guess(int value_guess) {
    if (GetSwitchDamage_guess() != 0) {
        if (value_guess < 1) {
            return true;
        }
    }
    return false;
}

// Preloads the open/close sounds of a kind (-1 = this door's kind), the same table as ChangeState_guess.
// FUNCTION: TITANIUM 0x0049012E
void EQSwitch_guess::LoadSwitchSounds_guess(unsigned int code_guess) {
    if (code_guess == 0xffffffff) {
        code_guess = kind;
    }
    switch (code_guess) {
    case 1:
    case 6:
        g_sink_guess->WaveLoadById_guess(0xb0, 1);
        g_sink_guess->WaveLoadById_guess(0xaf, 1);
        break;
    case 10:
    case 0xb:
    case 0xc:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
        g_sink_guess->WaveLoadById_guess(0xb8, 1);
        g_sink_guess->WaveLoadById_guess(0xb7, 1);
        break;
    case 0x1e:
        g_sink_guess->WaveLoadById_guess(0xad, 1);
        g_sink_guess->WaveLoadById_guess(0xae, 1);
        break;
    case 0x23:
    case 0x24:
        g_sink_guess->WaveLoadById_guess(0xbd, 1);
        break;
    case 0x28:
        g_sink_guess->WaveLoadById_guess(0xb4, 1);
        break;
    case 0x3b:
        g_sink_guess->WaveLoadById_guess(0xb9, 1);
        break;
    case 0x3e:
    case 0x43:
    case 0x48:
    case 0x4d:
        g_sink_guess->WaveLoadById_guess(0xb8, 1);
        g_sink_guess->WaveLoadById_guess(0xb7, 1);
        g_sink_guess->WaveLoadById_guess(0xb6, 1);
        break;
    case 0x3c:
    case 0x3d:
    case 0x41:
    case 0x42:
    case 0x46:
    case 0x47:
    case 0x4b:
    case 0x4c:
        g_sink_guess->WaveLoadById_guess(0xb5, 1);
        g_sink_guess->WaveLoadById_guess(0xb6, 1);
        break;
    case 0x6e:
        g_sink_guess->WaveLoadById_guess(0xac, 1);
        break;
    case 0x78:
        g_sink_guess->WaveLoadById_guess(0xbb, 1);
        break;
    case 0x7d:
        g_sink_guess->WaveLoadById_guess(0xbc, 1);
        break;
    case 2:
    case 7:
    case 8:
    case 0x8c:
    case 0x91:
    case 0x92:
    case 0x96:
    case 0x97:
    case 0x98:
        g_sink_guess->WaveLoadById_guess(0xb3, 1);
        g_sink_guess->WaveLoadById_guess(0xb2, 1);
        break;
    }
}

// The lock difficulty as a positive number: +0x66 itself when positive, its magnitude below -3, else 0.
// FUNCTION: TITANIUM 0x0049030E
// @early-stop: tiebreak, structural ndiff=4
float EQSwitch_guess::GetTriggerRange_guess() {
    short value = field66_guess;
    float result;
    if (value > 0) {
        result = (float)value;
    } else if (value < -3) {
        result = -(float)value;
    } else {
        return 0.0f;
    }
    return result;
}

// True when the five door-state bytes at +0x51 equal those at +0x56 (a combination lock is set right).
// FUNCTION: TITANIUM 0x00490341
bool BytePair_guess::IsCombinationSet_guess() {
    return left0_guess == right0_guess &&
        left1_guess == right1_guess &&
        left2_guess == right2_guess &&
        left3_guess == right3_guess &&
        left4_guess == right4_guess;
}

// Door kinds that are solid while they move: the collision filter 0x0042D05F counts them and the door
// update 0x004368B3 (IsSolid_guess there) tracks their position and radius. A few more only in zones
// 154 (acrylia), 205 (podisease), 208 (povalor) and 212 (solrotower), by the zone id at 0x924470.
// FUNCTION: TITANIUM 0x00490370
char EQSwitch_guess::IsInMode_guess() {
    if (kind >= 0x99 && kind <= 0x9b) {
        return 1;
    }
    if (kind >= 0x1e && kind <= 0x2d) {
        return 1;
    }
    if (kind >= 0x36 && kind <= 0x3b) {
        return 1;
    }
    if (kind >= 0x32 && kind <= 0x33) {
        return 1;
    }
    switch (g_mode_guess) {
    case 0x9a:
        if (kind == 0x1b) {
            return 1;
        }
        break;
    case 0xcd:
        if (kind == 0x1a) {
            return 1;
        }
        break;
    case 0xd0:
        if (kind == 8) {
            return 1;
        }
        break;
    case 0xd4:
        if (kind == 0x1a) {
            return 1;
        }
        break;
    }
    return 0;
}

// Kinds 0x99 and 0x9B.
// FUNCTION: TITANIUM 0x004903C2
int EQSwitch_guess::IsSpecial_guess() {
    if (kind == 0x9b || kind == 0x99) {
        return 1;
    }
    return 0;
}

// Kinds that start open: 0x32-0x3A except 0x35, and 0x99-0x9B.
// FUNCTION: TITANIUM 0x004903D4
char EQSwitch_guess::IsAllowed_guess() {
    if ((kind == 0x35 || kind < 0x32 || kind >= 0x3b) &&
        (kind < 0x99 || kind > 0x9b)) {
        return 0;
    }
    return 1;
}

// The trap and moving kinds (0x33, 0x73-0x74, 0x78, 0x7D, 0x82, 0x87, 0x8C, 0x91-0x92, 0x96-0x98).
// FUNCTION: TITANIUM 0x004903F1
char EQSwitch_guess::FUN_004903f1_guess() {
    int value_guess = kind;
    if (value_guess <= 0x82) {
        if (value_guess != 0x82 && value_guess != 0x33 &&
            (value_guess <= 0x72 || (value_guess > 0x74 && value_guess != 0x78 && value_guess != 0x7d))) {
            return 0;
        }
    } else if (value_guess != 0x87 && value_guess != 0x8c) {
        if (value_guess <= 0x90) {
            return 0;
        }
        if (value_guess > 0x92) {
            if (value_guess <= 0x95) {
                return 0;
            }
            if (value_guess > 0x98) {
                return 0;
            }
        }
    }
    return 1;
}

// Number of doors in the zone's door list (0x00903E84).
// FUNCTION: TITANIUM 0x004904FD
int Collection_guess::GetCount_guess() {
    return count;
}

// The door with door id `id`.
// FUNCTION: TITANIUM 0x00490500
Entry_guess* Collection_guess::Find_guess(int id) {
    int index = 0;
    if (count > 0) {
        do {
            if (entries[index]->id == id) {
                return entries[index];
            }
            index++;
        } while (index < count);
    }
    return 0;
}

// The door with id `value_guess` whose +0x4F flag is `kind_guess`.
// FUNCTION: TITANIUM 0x00490547
Entry_guess* Collection_guess::FindMatching_guess(unsigned int value_guess, char kind_guess) {
    int index = 0;
    if (count > 0) {
        do {
            if (entries[index]->field4f_guess == kind_guess &&
                entries[index]->field01_guess == value_guess) {
                return entries[index];
            }
            index++;
        } while (index < count);
    }
    return 0;
}

// Door `index` of the zone's door list, or 0 when out of range.
// FUNCTION: TITANIUM 0x00490530
Entry_guess* Collection_guess::GetAt_guess(int index) {
    if (index < 0 || index >= count) {
        return 0;
    }
    return entries[index];
}

// Appends a door to the list, with no capacity check; the door spawn handler adds each new door.
// FUNCTION: TITANIUM 0x00490580
void Collection_guess::Add_guess(Entry_guess* entry) {
    entries[count] = entry;
    count++;
}

// Frees the door and closes the gap in the list.
// FUNCTION: TITANIUM 0x0049058F
void Collection_guess::Remove_guess(Entry_guess* entry_guess) {
    for (int index = 0; index < count; index++) {
        if (entries[index] == entry_guess) {
            EQSwitch_guess* entry = reinterpret_cast<EQSwitch_guess*>(entries[index]);
            if (entry != 0) {
                entry->ReleaseActor_guess();
                free(entry);
            }
            count--;
            memmove(&entries[index], &entries[index + 1], (count - index) * 4);
            return;
        }
    }
}

// Reads one byte field, decimal or 0x hex.
// FUNCTION: TITANIUM 0x004905F3
int __cdecl ParseByteToken_guess(char* input_guess, unsigned char* output_guess, int delimiter_guess) {
    char buffer_guess[0x800];
    buffer_guess[0] = 0;
    int result_guess = FUN_005769E0_guess(input_guess, buffer_guess, 0x800, delimiter_guess, 1);
    if (buffer_guess[0] == '0' && buffer_guess[1] == 'x') {
        *output_guess = (unsigned char)_strtol(buffer_guess, 0, 16);
    } else {
        *output_guess = (unsigned char)atol(buffer_guess);
    }
    return result_guess;
}

// Resets position from the spawn coordinates and sets the state: `kind_guess` 1 or 2 (or flag +0xC1) gives
// open for always-open kinds, else opening; otherwise it becomes `kind_guess`, or closed (0) when the old
// state is 3 (closing).
// FUNCTION: TITANIUM 0x00490670
void EQSwitch_guess::SetState_guess(unsigned char kind_guess) {
    field38_guess = field24_guess;
    field3c_guess = field28_guess;
    field40_guess = field2c_guess;
    field44_guess = field30_guess;
    field48_guess = field34_guess;
    if ((unsigned char)kind_guess == 2 || (unsigned char)kind_guess == 1 || fieldc1_guess != 0) {
        state_guess = IsAllowed_guess() ? 1 : 2;
    } else {
        state_guess = (state_guess == 3) ? 0 : kind_guess;
    }
}

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
extern "C" EQSwitch_guess* __cdecl FUN_00401b28_guess(unsigned int string_id_guess);

#define g_message_type_guess EQ_ARRAY(char, 0x00905CA0)

struct Message_guess {
    char type_guess;
    int amount_guess;
    int value_guess;
    unsigned int string_id_guess;
};

// Clicking a door. Ignored for kinds 0x36-0x38, doors with +0xC0 or +0xC2 clear, moving doors and open doors
// keyed -2.
// Too far away (beyond the door's half height + reach + 20) prints "You can't reach that, get closer."
// (1462). Server-run doors send OP_ClickDoor (16 bytes: door id, picklock skill, key item, clicker id);
// client-run doors check the lock and change state at once, and a combination lock also toggles the doors
// it is chained to (+0x68, five slots).
// FUNCTION: TITANIUM 0x004906C5
// @early-stop: budget, diff ndiff=231
void EQSwitch_guess::UseSwitch_guess(unsigned int string_id_guess, int value_guess,
    Amount_guess amount_guess, float range_guess) {
    if (kind == 0x36 || kind == 0x37 || kind == 0x38) {
        return;
    }
    if (fieldc0_guess == 0) {
        return;
    }
    if (fieldc2_guess == 0) {
        return;
    }
    if (kind < 0x69 || kind > 0x6b) {
        if (GetSwitchDamage_guess() == 0) {
            if (state_guess == 2 || state_guess == 3) {
                return;
            }
        }
    }
    if (state_guess == 1 && field66_guess == -2) {
        return;
    }
    if (amount_guess.value_guess > 0xfe) {
        amount_guess.value_guess = 0xfe;
    }

    EQSwitch_guess* local_record_guess = 0;
    EQSwitch_guess* selected_record_guess;
    if (string_id_guess != 0) {
        local_record_guess = FUN_00401b28_guess(string_id_guess);
    }
    selected_record_guess = local_record_guess;
    if (local_record_guess == g_source_record_guess &&
        g_alternate_record_guess != g_source_record_guess) {
        selected_record_guess = g_alternate_record_guess;
        string_id_guess = (unsigned int)g_alternate_record_guess->field258_guess;
    }

    if (local_record_guess != 0 && local_record_guess->field244_guess == 0) {
        if (IsTrapWithoutSkill_guess(amount_guess.value_guess)) {
            return;
        }
        float height_guess;
        if (range_guess == 0.0f) {
            range_guess = g_manager_guess->TrueDistance_guess(selected_record_guess->field30_guess,
                selected_record_guess->field34_guess, selected_record_guess->field38_guess,
                field38_guess, field3c_guess, field40_guess, 0.0f);
            if (field90_guess == 0) {
                int height_units_guess = field64_guess;
                height_guess = (float)height_units_guess * 0.01f;
            } else {
                height_guess = reinterpret_cast<Actor_guess*>(field90_guess)->Slot14_guess() * 0.5f;
            }
        } else {
            range_guess = (float)reinterpret_cast<DoubleWrapper_guess*>(this)->DistanceTo_guess(
                (int)&selected_record_guess->field30_guess);
            height_guess = 0.0f;
        }
        if (height_guess + selected_record_guess->field23c_guess + 20.0f < range_guess) {
            if (local_record_guess->field218_guess == 0) {
                return;
            }
            token_string_to_client_guess(reinterpret_cast<Sink_guess*>(local_record_guess->field218_guess),
                0x5b6, 10, 0);
            return;
        }
    }

    if (g_mode_state_guess->value_guess == 1 || g_mode_record_guess != 0) {
        if (field4e_guess == 0) {
            if (SwitchWasOpened_guess(value_guess, amount_guess.value_guess,
                reinterpret_cast<Owner_guess*>(selected_record_guess), (int)&amount_guess.bytes_guess[3])) {
                int new_state_guess;
                if (GetSwitchDamage_guess() == 0) {
                    new_state_guess = state_guess == 0 ? 2 : 3;
                } else {
                    new_state_guess = 4;
                }
                ChangeState_guess((char)new_state_guess, (int)selected_record_guess, 0);
            }
        } else if (SwitchWasOpened_guess(value_guess, amount_guess.value_guess,
            reinterpret_cast<Owner_guess*>(selected_record_guess), (int)&amount_guess.bytes_guess[3])) {
            if (field4d_guess == 0) {
                if (string_id_guess != 0) {
                    return;
                }
            } else {
                field56_guess[0] = field56_guess[0] == 0;
            }
            if (reinterpret_cast<BytePair_guess*>(this)->IsCombinationSet_guess() || state_guess == 1) {
                int new_state_guess;
                if (GetSwitchDamage_guess() == 0) {
                    new_state_guess = state_guess == 0 ? 2 : 3;
                } else {
                    new_state_guess = 4;
                }
                ChangeState_guess((char)new_state_guess, (int)selected_record_guess, 0);
                for (int index_guess = 0; index_guess < 5; ++index_guess) {
                    char entry_kind_guess = field68_guess[index_guess];
                    if (entry_kind_guess != -1 && entry_kind_guess != field01_guess) {
                        Entry_guess* entry_guess = g_collection_guess->FindMatching_guess(
                            (unsigned char)entry_kind_guess, 0);
                        if (entry_guess != 0) {
                            char state_index_guess = field51_guess[index_guess];
                            if (state_index_guess >= 0 && state_index_guess < 5) {
                                EQSwitch_guess* record_guess = reinterpret_cast<EQSwitch_guess*>(entry_guess);
                                if (record_guess->field4d_guess == 0 || state_index_guess != 0) {
                                    record_guess->field56_guess[state_index_guess] =
                                        record_guess->field56_guess[state_index_guess] == 0;
                                }
                                record_guess->UseSwitch_guess(0, value_guess, amount_guess, 0.0f);
                            }
                        }
                    }
                }
            }
        }
    } else if (g_flag_guess == 0) {
        Message_guess message_guess;
        message_guess.type_guess = field01_guess;
        message_guess.amount_guess = amount_guess.value_guess;
        message_guess.value_guess = value_guess;
        message_guess.string_id_guess = string_id_guess;
        EQSendMessage(g_message_type_guess, OP_ClickDoor, &message_guess, 0x10, 1);
    }
}

// Frees every door.
// FUNCTION: TITANIUM 0x004909CE
void Collection_guess::Clear_guess() {
    int index = 0;
    if (count > 0) {
        do {
            EQSwitch_guess* entry = reinterpret_cast<EQSwitch_guess*>(entries[index]);
            if (entry != 0) {
                entry->ReleaseActor_guess();
                free(entry);
            }
            index++;
        } while (index < count);
    }
    count = 0;
}

// Frees every item of every chain in the table at +0x42C, then releases the table's own chain storage
// (0x0048F513).
// FUNCTION: TITANIUM 0x00490A01
void Outer_guess::FreeBucketEntries_guess() {
    Table_guess* table = &table_guess;
    Node_guess* node = table->Begin_guess();
    while (node != 0) {
        Item_guess* item = node->head_guess;
        node = table->Next_guess(node);
        while (item != 0) {
            Item_guess* old = item;
            item = item->next_guess;
            free(old);
        }
    }
    table->Finish_guess();
}

// Builds a door from the zone's door record and preloads its sounds and model.
// FUNCTION: TITANIUM 0x00490A43
EQSwitch_guess* EQSwitch_guess::InitFromDoorRecord_guess(RecordSource_guess* src_guess) {
    SetDefaults_guess();
    field01_guess = src_guess->field3c_guess;
    strcpy(name02_guess, src_guess->name00_guess);
    kind = src_guess->field3d_guess;
    state_guess = src_guess->field3e_guess;
    field4c_guess = src_guess->field3f_guess;
    *reinterpret_cast<int*>(&field24_guess) = src_guess->field20_guess;
    *reinterpret_cast<int*>(&field28_guess) = src_guess->field24_guess;
    *reinterpret_cast<int*>(&field2c_guess) = src_guess->field28_guess;
    *reinterpret_cast<int*>(&field30_guess) = src_guess->field2c_guess;
    field34_guess = (float)src_guess->field30_guess;
    field66_guess = src_guess->field40_guess;
    *reinterpret_cast<int*>(&field38_guess) = *reinterpret_cast<int*>(&field24_guess);
    *reinterpret_cast<int*>(&field3c_guess) = *reinterpret_cast<int*>(&field28_guess);
    *reinterpret_cast<int*>(&field40_guess) = *reinterpret_cast<int*>(&field2c_guess);
    *reinterpret_cast<int*>(&field44_guess) = *reinterpret_cast<int*>(&field30_guess);
    *reinterpret_cast<int*>(&field48_guess) = *reinterpret_cast<int*>(&field34_guess);
    field64_guess = src_guess->field34_guess;
    fielda4_guess = src_guess->field44_guess;
    fieldb4_guess = src_guess->field48_guess;
    fieldb8_guess = src_guess->field4c_guess;
    if (kind != 0x35) {
        SetState_guess(state_guess);
    }
    fieldc0_guess = src_guess->field4d_guess;
    fieldc1_guess = src_guess->field4e_guess;
    fieldc2_guess = src_guess->field4f_guess;
    LoadSwitchSounds_guess(0xffffffff);
    CreateSwitchActor_guess();
    return this;
}
