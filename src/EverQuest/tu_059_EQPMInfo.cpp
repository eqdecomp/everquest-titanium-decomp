// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 59: a hint from compare/tumap.py.
// EQPMInfo, the 0x10C0-byte per-actor record (EQActorInfo_guess in the earlier sibling decomp; Mac EQPMInfo.cpp), and
// the racedata.txt table (g_raceData 0x903E80). EQPMInfo_guess is EQPMInfo and CleanupState_guess its destructor's
// view; RaceData_guess, RaceManager_guess and ValueAccessor_guess are all the race-data table.
#include "titanium/eqaddr.h"

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination, int value, unsigned int count);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// EXTERNAL: TITANIUM 0x0046D655 TickA_guess
unsigned int __cdecl TickA_guess();

// EXTERNAL: TITANIUM 0x00576E80 TickB_guess
int __cdecl TickB_guess();

#define g_soundManager_guess EQ_GLOBAL(int, 0x00851390)
#define g_limitA_guess EQ_GLOBAL(int, 0x009237C0)
#define g_limitB_guess EQ_GLOBAL(int, 0x009237C4)

struct Dispatch_guess {
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
    virtual int Slot40_guess() = 0;
};

struct Forwarder_guess {
    Dispatch_guess* dispatch;
    int Forward_guess();
};

struct HeapBlock_guess {
    // EXTERNAL: TITANIUM 0x0044AA7A HeapBlock_guess::Release_guess
    void Release_guess();
};

struct ResourceManager_guess {
    // EXTERNAL: TITANIUM 0x004395C4 ResourceManager_guess::DeleteLight_guess
    void DeleteLight_guess(int handle);
    // EXTERNAL: TITANIUM 0x00439A46 ResourceManager_guess::DeleteActor_guess
    void DeleteActor_guess(int value);
};

#define g_resourceManager_guess EQ_GLOBAL(ResourceManager_guess*, 0x00905D24)

struct OtherObject_guess {
    // EXTERNAL: TITANIUM 0x00401351 OtherObject_guess::StartFade_guess
    void StartFade_guess(int value);
};

// EXTERNAL: TITANIUM 0x00401022 GetFadeList_guess
OtherObject_guess* __cdecl GetFadeList_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct CleanupState_guess {
    int first;
    int handle;
    char pad_008_guess[0x194];
    char mode;
    char pad_19d_guess[0x17];
    HeapBlock_guess* allocation;
    char pad_1b8_guess[0xdf8];
    int entries[10];
    void Clear_guess();
};

struct ChainNode_guess {
    char pad_000_guess[8];
    ChainNode_guess* next;
};

struct HashTable_guess {
    ChainNode_guess** buckets;
    int bucketCount;
    int nodeCount;
    int chainCount;
    void Clear_guess();
};

struct Pair_guess {
    int a_guess;
    int b_guess;
    // EXTERNAL: TITANIUM 0x0044A9E2 ??0Pair_guess@@QAE@H@Z
    Pair_guess(int value);
};

// Object of 0x10C0 bytes; the constructor at 0x0048F023 stores each field in address order.
struct EQPMInfo_guess {
    int m0000;
    int m0004;
    char pad_0008_guess[0x40];
    float m0048;
    int savedZ_004c_guess;
    int m0050;
    int m0054;
    int m0058;
    int m005c;
    int m0060;
    int m0064;
    int m0068;
    int m006c;
    int m0070;
    int m0074;
    int m0078;
    int m007c;
    int m0080;
    int m0084;
    int m0088;
    int m008c;
    int m0090;
    float m0094;
    float m0098;
    unsigned char m009c;
    unsigned char m009d;
    char pad_009e_guess[2];
    int m00a0;
    int m00a4;
    int m00a8;
    unsigned char m00ac;
    unsigned char m00ad;
    unsigned char m00ae;
    char pad_00af_guess[1];
    unsigned char m00b0;
    char pad_00b1_guess[3];
    int m00b4;
    int m00b8;
    float m00bc;
    float m00c0;
    float m00c4;
    float m00c8;
    float m00cc;
    int m00d0;
    int m00d4;
    int m00d8;
    int m00dc;
    int m00e0;
    int m00e4;
    union {
        int e8_guess[34];
        struct {
            char pad_00e8_guess[0x28];
            int m0110;
            int m0114;
            int m0118;
            int m011c;
            int m0120;
            int m0124;
            int m0128;
            int m012c;
            int m0130;
            int m0134;
            int m0138;
            int m013c;
            int m0140;
            int m0144;
            int m0148;
            int m014c;
            unsigned char m0150;
            unsigned char m0151;
            unsigned char m0152;
            unsigned char m0153;
            unsigned char m0154;
            unsigned char m0155;
            char pad_0156_guess[2];
            int m0158;
            int m015c;
            int m0160;
            char pad_0164_guess[8];
            int m016c;
        };
    };
    int m0170;
    int m0174_guess[3];
    int m0180_guess[3];
    int m018c_guess[3];
    int m0198;
    unsigned char m019c;
    char pad_019d_guess[3];
    int m01a0;
    int m01a4;
    int m01a8;
    int m01ac;
    float m01b0;
    Pair_guess* m01b4;
    char pad_01b8_guess[0xd04];
    int m0ebc;
    float m0ec0;
    float m0ec4;
    int m0ec8;
    int m0ecc;
    int m0ed0;
    int m0ed4;
    int m0ed8;
    unsigned char m0edc;
    unsigned char m0edd;
    char pad_0ede_guess[0x42];
    int m0f20;
    int m0f24;
    int m0f28;
    int m0f2c;
    int m0f30;
    int m0f34;
    int m0f38;
    int m0f3c;
    int m0f40;
    int m0f44;
    int m0f48;
    int m0f4c;
    int m0f50;
    int m0f54;
    int m0f58;
    int m0f5c;
    int m0f60;
    int m0f64;
    int m0f68;
    int m0f6c;
    int m0f70;
    int m0f74;
    int m0f78;
    int m0f7c;
    int m0f80;
    int m0f84;
    int m0f88;
    unsigned char m0f8c;
    char pad_0f8d_guess[7];
    int m0f94;
    int m0f98;
    unsigned char m0f9c;
    int m0fa0;
    int m0fa4;
    int m0fa8;
    int m0fac;
    int m0fb0_guess[10];
    int m0fd8;
    int m0fdc;
    int m0fe0;
    int m0fe4;
    int m0fe8;
    char pad_0fec_guess[0x14];
    float m1000;
    unsigned char m1004;
    unsigned char m1005;
    char pad_1006_guess[2];
    int m1008;
    float m100c;
    char pad_1010_guess[0x24];
    int m1034;
    int m1038;
    char pad_103c_guess[4];
    int m1040;
    unsigned char m1044;
    char pad_1045_guess[3];
    int m1048;
    unsigned char m104c;
    char pad_104d_guess[3];
    int m1050;
    int m1054;
    int m1058;
    int m105c;
    int m1060;
    int m1064;
    int m1068;
    int m106c;
    int m1070;
    int m1074;
    unsigned char m1078;
    char pad_1079_guess[3];
    int m107c;
    unsigned char m1080;
    EQPMInfo_guess(const char* value);
};

// Asks the actor (+0, as in EQPMInfo) through its virtual slot 40 (+0xA0); callers treat it as an EQPMInfo
// method.
// FUNCTION: TITANIUM 0x0048F019
int Forwarder_guess::Forward_guess() {
    return dispatch->Slot40_guess();
}

// EQPMInfo constructor (Mac map, medium): zeroes the record, copies the actor's name to +8, stamps the
// clocks and sets the defaults.
// FUNCTION: TITANIUM 0x0048F023
EQPMInfo_guess::EQPMInfo_guess(const char* value) {
    m1050 = 0;
    m1054 = -1;
    m1058 = -1;
    m105c = 0;
    memset(this, 0, 0x10c0);
    m0048 = 0.0f;
    m01b0 = 0.0f;
    // g_soundManager_guess is no seed: 0x851390 is the manager object other TUs call the sound manager.
    m01b4 = new Pair_guess(g_soundManager_guess);
    // Float bits of -1e27: "no saved floor height yet" (savedZ in the earlier sibling decomp, at +0x50).
    savedZ_004c_guess = 0xec4ecb8f;
    m1040 = 0;
    m1044 = 0;
    unsigned int seed = TickA_guess();
    m0078 = seed;
    m005c = seed;
    m0058 = seed;
    m0054 = seed;
    m0050 = seed;
    m0074 = seed;
    m007c = seed;
    strcpy(pad_0008_guess, value);
    m100c = 1.0f;
    m00ac = 0;
    m00ad = 0;
    m00ae = 0;
    m00a0 = -1;
    m00a4 = -1;
    m00a8 = -1;
    m009d = 0;
    m1068 = 0;
    m1060 = 0;
    m1064 = 0;
    // TickA is EqGetTime (0x46D655), TickB Util::FastTime (0x576E80, MQ2).
    m00d4 = TickB_guess();
    m1034 = 0;
    m1038 = -1;
    m0068 = 0;
    m0060 = 0;
    m0064 = 0;
    m0084 = -1;
    m1080 = 0;
    m0088 = -1;
    m0094 = 0.35f;
    m0090 = 32;
    m0098 = 0.1f;
    m008c = 16;
    m00b0 = 0;
    m0151 = 0;
    m0fd8 = 0;
    m0fdc = 0;
    m0fe0 = 0;
    m0158 = 0;
    m015c = 0;
    m0160 = 0;
    m016c = -1;
    m0f20 = 0;
    m0f24 = 0;
    m0f28 = 0;
    m0f2c = 0;
    m0f30 = 0;
    m0f34 = 0;
    m0f38 = 0;
    m0f3c = 0;
    m0f40 = 0;
    m0f44 = 0;
    m0f48 = 0;
    m0f4c = 0;
    m0f5c = 0;
    m0f60 = 0;
    m0f64 = 0;
    m0f50 = 0;
    m0f54 = 0;
    m0f58 = 0;
    m0f68 = 0;
    m0f6c = 0;
    m0f70 = 0;
    m0f74 = 0;
    m0ebc = TickA_guess();
    m0ec0 = 200.0f;
    m0edd = 0;
    m0138 = 32;
    m0ed4 = -1;
    m0f88 = 0;
    m0ec4 = 0.5f;
    m0ec8 = 0;
    m0f8c = 0;
    m0ecc = 0;
    m0ed0 = 0;
    m0f78 = 0;
    m0f7c = 0;
    m0f80 = 0;
    m0f84 = 0;
    m0ed8 = 0;
    m0edc = 0;
    m0170 = 0;
    for (int i = 0; i < 3; ++i) m0174_guess[i] = 0;
    for (int i = 0; i < 3; ++i) m0180_guess[i] = 0;
    for (int i = 0; i < 3; ++i) m018c_guess[i] = 0;
    m00c4 = 1.0f;
    m0198 = 0;
    m00c8 = 0.0f;
    m0f94 = 0;
    m0150 = 0;
    m00cc = 0.0f;
    m00bc = 1.6f;
    m00c0 = 3.2f;
    m00d0 = 0;
    m00b8 = g_limitB_guess;
    m00b4 = g_limitA_guess;
    m00dc = 0;
    m00e0 = 0;
    m00e4 = 0;
    for (int i = 0; i < 34; ++i) e8_guess[i] = 0;
    m0110 = 0;
    m1048 = 0;
    m104c = 0;
    m1050 = 0;
    m105c = 0;
    m1054 = -1;
    m1058 = -1;
    m0114 = 0;
    m0118 = 0;
    m00d8 = 0;
    m0f98 = -1;
    m0f9c = 0xff;
    m0fa0 = 0;
    m0fa4 = 10;
    m011c = 0;
    m0120 = 0;
    m0128 = 0;
    m0124 = 0;
    m0152 = 0;
    m0153 = 0;
    m0154 = 0;
    m0155 = 0;
    m0130 = 0;
    m1008 = 0;
    m006c = 0;
    m0070 = 0;
    m0134 = 0xfe;
    m013c = 0xfe;
    m0140 = 0;
    m0148 = 0;
    m0144 = 0;
    m014c = 0;
    m0080 = 0;
    m012c = 0;
    m0fa8 = -1;
    m0fac = -1;
    m1005 = 0;
    m0fe4 = 0;
    m0fe8 = 0;
    m0000 = 0;
    m0004 = 0;
    m1004 = 0;
    m1000 = 0.0f;
    m009c = 1;
    m106c = 0;
    m1070 = 0;
    m1074 = 0;
    m1078 = 0;
    m107c = 0;
    m019c = 0;
    m01a0 = 0;
    m01a4 = 0;
    m01a8 = 0;
    m01ac = 0;
    for (int i = 0; i < 10; ++i) m0fb0_guess[i] = 0;
}

// EQPMInfo destructor: frees the +0x1B4 block, clears the ten +0xFB0 slots, deletes the light (+4,
// CDisplay::DeleteLight) and the actor (+0): through 0x401022 when +0x19C is set, else CDisplay::DeleteActor.
// FUNCTION: TITANIUM 0x0048F4A4
void CleanupState_guess::Clear_guess() {
    HeapBlock_guess* block = allocation;
    if (block != 0) {
        block->Release_guess();
        free(block);
    }
    for (int i = 0; i < 10; ++i) {
        entries[i] = 0;
    }
    if (handle != 0) {
        g_resourceManager_guess->DeleteLight_guess(handle);
        handle = 0;
    }
    int value = first;
    if (value != 0) {
        if (mode != 0) {
            GetFadeList_guess()->StartFade_guess(value);
        } else {
            g_resourceManager_guess->DeleteActor_guess(value);
        }
        first = 0;
    }
}

// Frees every node of every bucket; the bucket array itself stays.
// FUNCTION: TITANIUM 0x0048F513
void HashTable_guess::Clear_guess() {
    for (int i = 0; i < bucketCount; ++i) {
        ChainNode_guess* node = buckets[i];
        if (node != 0) {
            --chainCount;
            do {
                ChainNode_guess* next = node->next;
                free(node);
                --nodeCount;
                node = next;
            } while (node != 0);
            buckets[i] = 0;
        }
    }
}

struct ValueAccessor_guess {
    // EXTERNAL: TITANIUM 0x004FF9C9 ValueAccessor_guess::Find_guess
    int** Find_guess(void* table);
    int GetRaceValue_guess(void* table, int selector, int index);
};

// Race-data value `index` (0-17) for race key `table`; `selector` 1 reads the second set of 18 (tu_053
// passes the actor's gender there). Probably sound ids; 0 for an unknown race or index.
// FUNCTION: TITANIUM 0x0048F54D
int ValueAccessor_guess::GetRaceValue_guess(void* table, int selector, int index) {
    int result = 0;
    int** found = Find_guess(table);
    if (found != 0 && index >= 0 && index < 18) {
        int* values = *found;
        if (selector == 1) {
            result = values[index + 19];
        } else {
            result = values[index + 1];
        }
    }
    return result;
}

struct Bucket_48f742_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x0042F092 Bucket_48f742_guess::Bucket_48f742_guess
    Bucket_48f742_guess(int capacity_guess);
    // EXTERNAL: TITANIUM 0x004C9745 Bucket_48f742_guess::~Bucket_48f742_guess
    ~Bucket_48f742_guess();
};

struct Table_48f742_guess {
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    int field_00c_guess;
    void* blocks_010_guess;
    int field_014_guess;
    unsigned char field_018_guess;
    char pad_019_guess[3];
    int field_01c_guess;
    // EXTERNAL: TITANIUM 0x0047C3AF Table_48f742_guess::Initialize_guess
    void Initialize_guess(int capacity_guess);
    Table_48f742_guess(int capacity_guess) { Initialize_guess(capacity_guess); }
    // EXTERNAL: TITANIUM 0x004B73EE Table_48f742_guess::~Table_48f742_guess
    ~Table_48f742_guess();
};

struct RaceData_guess {
    Bucket_48f742_guess bucket_guess;
    Table_48f742_guess table_guess;
    // EXTERNAL: TITANIUM 0x0048F583 RaceData_guess::LoadRaceData_guess
    void LoadRaceData_guess(int value_guess);
    RaceData_guess(int value_guess);
};

// Race-data table: a 256-entry hash and a 32-block pool, then loads the file if given (racedata.txt, tu_062).
// FUNCTION: TITANIUM 0x0048F742
RaceData_guess::RaceData_guess(int value_guess)
    : bucket_guess(0x100), table_guess(0x20) {
    if (value_guess != 0) {
        LoadRaceData_guess(value_guess);
    }
}

struct RaceRecord_guess {
    int values[37];
};

struct TextFileReader_guess {
    char data[0x1000c];
    // EXTERNAL: TITANIUM 0x00576BD0 TextFileReader_guess::TextFileReader_guess
    TextFileReader_guess(const char* filename, int delimiter);
    // EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::Ready_guess
    bool Ready_guess();
    // EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::Remaining_guess
    int Remaining_guess();
    // EXTERNAL: TITANIUM 0x00576CF0 TextFileReader_guess::Read_guess
    void Read_guess(char* buffer, int size);
    // EXTERNAL: TITANIUM 0x00576C50 TextFileReader_guess::Close_guess
    void Close_guess();
};

struct RaceManager_guess {
    // EXTERNAL: TITANIUM 0x00447C66 RaceManager_guess::AddRace_guess
    void AddRace_guess(RaceRecord_guess** record, int key);
    bool LoadRaceData_guess(const char* filename);
};

// EXTERNAL: TITANIUM 0x00574830 IsRaceRecord_guess
int __cdecl IsRaceRecord_guess(const char* buffer, int value);

// EXTERNAL: TITANIUM 0x00576D80 ParseRaceValue_guess
int __cdecl ParseRaceValue_guess(char** cursor, int delimiter);

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format, ...);

// Loads '^'-separated lines: race key, 18 values, 18 more; each record goes into the table by key.
// True if the file opened.
// FUNCTION: TITANIUM 0x0048F583
// @early-stop: unknown, structural ndiff=55
bool RaceManager_guess::LoadRaceData_guess(const char* filename) {
    int raceCount = 0;
    bool loaded = false;
    char buffer[0x1000];
    TextFileReader_guess* reader = new TextFileReader_guess(filename, 0x5e);
    if (reader->Ready_guess()) {
        loaded = true;
        int remaining = reader->Remaining_guess();
        while (remaining > 0) {
            reader->Read_guess(buffer, 0x1000);
            if (IsRaceRecord_guess(buffer, 0) != 0) {
                RaceRecord_guess* record = new RaceRecord_guess;
                // The null check covers only the zero-fill; a failed new still crashes on the stores below
                // (as original).
                if (record != 0) {
                    for (int i = 0; i < 37; ++i) {
                        record->values[i] = 0;
                    }
                }
                char* cursor = buffer;
                int key = ParseRaceValue_guess(&cursor, 0x5e);
                int* value = record->values + 1;
                int count = 0x12;
                do {
                    *value++ = ParseRaceValue_guess(&cursor, 0x5e);
                } while (--count != 0);
                value = record->values + 19;
                count = 0x12;
                do {
                    *value++ = ParseRaceValue_guess(&cursor, 0x5e);
                } while (--count != 0);
                record->values[0] = key;
                AddRace_guess(&record, key);
                ++raceCount;
            }
            remaining = reader->Remaining_guess();
        }
    }
    if (reader != 0) {
        reader->Close_guess();
        delete reader;
    }
    // Debug log 0x574110 (names.tsv Handle_OP_LogServer is a low-confidence miss).
    Log_guess("Race Manager loaded %d races from %s.", raceCount, filename);
    return loaded;
}
