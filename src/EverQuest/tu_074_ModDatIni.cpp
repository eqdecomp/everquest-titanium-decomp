// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 74: a hint from compare/tumap.py.
// Timed spell-effect sequences, the moddat.ini reader and MemChecker0. EffectSequenceList_guess (= Pair_guess,
// the 8-byte singleton at 0x985C10) holds an active list (+0) and a free list (+4) of 40-byte sequence
// nodes (EffectSequence_guess = TenWords_guess = TripleWords_guess). casterId/targetId are
// spawn ids: 0x401B28 indexes the 3000-entry spawn table.
#include "titanium/eqaddr.h"

struct LinkNode_guess {
    unsigned int unknown_00[8]; // 0x00..0x1c
    LinkNode_guess* previous;   // 0x20
    LinkNode_guess* next;       // 0x24
};

struct List_guess {
    LinkNode_guess* last_guess;
    void Insert(LinkNode_guess* node);
    void Remove(LinkNode_guess* node);
};

struct EffectSequenceList_guess {
    unsigned int unknown_00; // 0x00
    LinkNode_guess* first;   // 0x04
    void Insert(LinkNode_guess* node);
    void ReleaseAll_guess();
    void UpdateActive_guess();
    char CancelEffect_guess(int first_guess, int second_guess, unsigned int third_guess);
    LinkNode_guess* Acquire_guess();
    char InitializeState_guess(const char* casterId_guess, const char* targetId_guess,
        int index_guess, unsigned int lower_guess, unsigned int span_guess,
        unsigned int value_guess);
};

struct Pair_guess {
    unsigned int first;  // 0x00
    unsigned int second; // 0x04
};

struct TripleWords_guess {
    unsigned int first;  // 0x00
    unsigned int second; // 0x04
    unsigned int third;  // 0x08
    char Matches_guess(unsigned int first_guess, unsigned int second_guess, unsigned int third_guess);
};

struct Notifier_guess {
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
    virtual void AboutToShow_guess(unsigned int value_guess);
};

#define g_notifier_guess EQ_GLOBAL(Notifier_guess*, 0x0099E36C)

struct CacheEntry_guess {
    unsigned char unknown_00[0x10c];
};

struct CacheData_guess {
    unsigned int unknown_00[12];
    unsigned int first_guess;  // 0x30
    unsigned int second_guess; // 0x34
    unsigned int third_guess;  // 0x38
};

struct EffectSequence_guess {
    const char* casterId_0000_guess; // 0x00
    const char* targetId_0004_guess; // 0x04
    int index_guess;              // 0x08
    unsigned int lower_guess;     // 0x0c
    unsigned int upper_guess;     // 0x10
    unsigned int value_guess;     // 0x14
    unsigned int current_guess;   // 0x18
    unsigned int lastTick_guess;  // 0x1c
    void Initialize_guess(const char* casterId_guess, const char* targetId_guess,
        int index_guess, unsigned int lower_guess, unsigned int span_guess,
        unsigned int value_guess);
    void Update_guess();
    void Apply_guess(unsigned int kind_guess, unsigned int value_guess);
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
void* __cdecl FUN_00401b28_guess(const char* name_guess);

// EXTERNAL: TITANIUM 0x00495CC3 SubmitEffectEmitters_guess
void __cdecl SubmitEffectEmitters_guess(unsigned int index_guess, unsigned int kind_guess,
    CacheEntry_guess* entry_guess, CacheData_guess* data_guess, void* resolved_guess,
    unsigned int* values_guess, unsigned int zero1_guess, unsigned int value_guess,
    unsigned int zero2_guess);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

#define g_cacheEntries_guess EQ_GLOBAL(CacheEntry_guess*, 0x00851398)
#define g_cacheLimit_guess EQ_GLOBAL(int, 0x0085139C)

#define g_pair_guess EQ_GLOBAL(Pair_guess*, 0x00985C10)

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct TenWords_guess {
    unsigned int words[10]; // 0x00..0x24
    TenWords_guess();
};

struct Resource_guess {
    unsigned int unknown_00[4]; // 0x00..0x0c
    // EXTERNAL: TITANIUM 0x005764E0 ??0Resource_guess@@QAE@PBDH@Z
    Resource_guess(const char* name_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x005761D0 Resource_guess::Release_guess
    void Release_guess();
};

struct ModDatIni_guess {
    Resource_guess* resource; // 0x00
    ModDatIni_guess();
    ~ModDatIni_guess();
};

#define g_globalOwner_guess EQ_GLOBAL(ModDatIni_guess*, 0x00985C18)

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// True when the sequence node's three keys (+0, +4, +8) equal the arguments.
// FUNCTION: TITANIUM 0x004B68E5
char TripleWords_guess::Matches_guess(unsigned int first_guess, unsigned int second_guess, unsigned int third_guess)
{
    return first == first_guess && second == second_guess && third == third_guess;
}

// Fires stage `kind_guess` (0 start, 1 middle, 2 end) of spell effect `index_guess` (table 0x851398, 0x10C
// bytes each) from the caster spawn to the target spawn, at the caster's position (+0x30 to +0x38).
// FUNCTION: TITANIUM 0x004B6908
void EffectSequence_guess::Apply_guess(unsigned int kind_guess, unsigned int value_guess)
{
    int index = index_guess;
    if (index > 0 && index < g_cacheLimit_guess) {
        CacheData_guess* data = (CacheData_guess*)FUN_00401b28_guess(casterId_0000_guess);
        CacheEntry_guess* entry = g_cacheEntries_guess + index;
        if (entry != 0 && data != 0) {
            unsigned int values[3];
            values[0] = data->first_guess;
            values[1] = data->second_guess;
            values[2] = data->third_guess;
            SubmitEffectEmitters_guess(index, kind_guess, entry, data,
                FUN_00401b28_guess(targetId_0004_guess), values, 0, value_guess, 0);
        }
    }
}

// Advances the sequence by the elapsed ms: stage 1 when it passes lower_guess, stage 2 when it passes
// upper_guess. Both tests are strict, so a frame landing exactly on a boundary skips that stage.
// FUNCTION: TITANIUM 0x004B697F
void EffectSequence_guess::Update_guess()
{
    unsigned int elapsed = FUN_0046d655_guess() - lastTick_guess;
    unsigned int next = current_guess + elapsed;
    if (current_guess < lower_guess && next > lower_guess) {
        Apply_guess(1, upper_guess - lower_guess);
    }
    if (current_guess < upper_guess && next > upper_guess) {
        Apply_guess(2, value_guess);
    }
    current_guess = next;
    lastTick_guess = FUN_0046d655_guess();
}

// Pushes `node` as the new head of the doubly linked sequence list.
// FUNCTION: TITANIUM 0x004B69D1
void List_guess::Insert(LinkNode_guess* node)
{
    if (last_guess != 0) {
        last_guess->next = node;
    }
    node->previous = last_guess;
    last_guess = node;
}

// Unlinks `node`. The list's `first` is really the newest node (0x004B69D1 links each new node after it),
// so removing that node moves `first` back to `previous`.
// FUNCTION: TITANIUM 0x004B69E8
void List_guess::Remove(LinkNode_guess* node)
{
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
    if (node == last_guess) {
        last_guess = node->previous;
    }
    node->previous = 0;
    node->next = 0;
}

// Pushes `node` on the free list (+4).
// FUNCTION: TITANIUM 0x004B6A1C
void EffectSequenceList_guess::Insert(LinkNode_guess* node)
{
    if (first != 0) {
        first->next = node;
    }
    node->previous = first;
    first = node;
}

// The sequence manager singleton (0x985C10), created on first use.
// FUNCTION: TITANIUM 0x004B6A36
Pair_guess* InitializePair_guess()
{
    Pair_guess* pair = g_pair_guess;
    if (pair == 0) {
        pair = (Pair_guess*)operator new(8);
        if (pair != 0) {
            pair->first = 0;
            pair->second = 0;
        } else {
            pair = 0;
        }
        g_pair_guess = pair;
    }
    return pair;
}

// Empty 40-byte effect sequence node: all ten dwords zero.
// FUNCTION: TITANIUM 0x004B6A5C
TenWords_guess::TenWords_guess()
{
    words[8] = 0;
    words[9] = 0;
    words[0] = 0;
    words[1] = 0;
    words[2] = 0;
    words[3] = 0;
    words[4] = 0;
    words[5] = 0;
    words[6] = 0;
    words[7] = 0;
}

// Starts a sequence: stage 0 now with `lower_guess`, stage 1 after `lower_guess` ms with `span_guess`,
// stage 2 after `span_guess` more with `value_guess`.
// FUNCTION: TITANIUM 0x004B6A7E
void EffectSequence_guess::Initialize_guess(const char* casterId_guess, const char* targetId_guess,
    int index_guess, unsigned int lower_guess, unsigned int span_guess,
    unsigned int value_guess)
{
    current_guess = 0;
    this->casterId_0000_guess = casterId_guess;
    this->targetId_0004_guess = targetId_guess;
    this->index_guess = index_guess;
    this->upper_guess = lower_guess + span_guess;
    this->lower_guess = lower_guess;
    this->value_guess = value_guess;
    this->lastTick_guess = FUN_0046d655_guess();
    Apply_guess(0, lower_guess);
}

// Moves every active sequence to the free list.
// FUNCTION: TITANIUM 0x004B6AC6
void EffectSequenceList_guess::ReleaseAll_guess()
{
    LinkNode_guess* node = (LinkNode_guess*)unknown_00;
    while (node != 0) {
        LinkNode_guess* previous = node->previous;
        ((List_guess*)this)->Remove(node);
        Insert(node);
        node = previous;
    }
}

// Per frame: advances each active sequence and frees the finished ones. Not CChatManager::Activate,
// whatever the Mac match says.
// FUNCTION: TITANIUM 0x004B6AE6
void EffectSequenceList_guess::UpdateActive_guess()
{
    LinkNode_guess* node = (LinkNode_guess*)unknown_00;
    while (node != 0) {
        LinkNode_guess* next = node->previous;
        ((EffectSequence_guess*)node)->Update_guess();
        if (((EffectSequence_guess*)node)->current_guess >
            ((EffectSequence_guess*)node)->upper_guess) {
            ((List_guess*)this)->Remove(node);
            Insert(node);
        }
        node = next;
    }
}

// Cancels the sequences of effect `third_guess` from caster `first_guess` to target `second_guess`, then
// tells the effect system (0x99E36C, slot 13) to stop it on both spawns, keyed (spawn id << 16) | effect.
// FUNCTION: TITANIUM 0x004B6B1B
char EffectSequenceList_guess::CancelEffect_guess(int first_guess, int second_guess,
    unsigned int third_guess)
{
    char found = 0;
    LinkNode_guess* node = (LinkNode_guess*)unknown_00;
    if (node != 0) {
        do {
            if (((TripleWords_guess*)node)->Matches_guess(first_guess, second_guess,
                third_guess)) {
                ((List_guess*)this)->Remove(node);
                Insert(node);
                found = 1;
            }
            node = node->previous;
        } while (node != 0);
        if (found != 0) {
            g_notifier_guess->AboutToShow_guess(((unsigned int)first_guess << 16) | third_guess);
            if (second_guess != -1) {
                g_notifier_guess->AboutToShow_guess(((unsigned int)second_guess << 16) | third_guess);
            }
        }
    }
    return found;
}

// A node from the free list, or a new one.
// FUNCTION: TITANIUM 0x004B6B99
LinkNode_guess* EffectSequenceList_guess::Acquire_guess()
{
    LinkNode_guess* node = first;
    if (node != 0) {
        first = node->previous;
        node->previous = 0;
        node->next = 0;
        return node;
    }
    return (LinkNode_guess*)new TenWords_guess;
}

// Starts a new sequence on the active list (see Initialize_guess); 0 only if no node.
// FUNCTION: TITANIUM 0x004B6BC5
char EffectSequenceList_guess::InitializeState_guess(const char* casterId_guess,
    const char* targetId_guess, int index_guess, unsigned int lower_guess,
    unsigned int span_guess, unsigned int value_guess)
{
    EffectSequence_guess* state = (EffectSequence_guess*)Acquire_guess();
    if (state == 0) {
        return 0;
    }
    state->Initialize_guess(casterId_guess, targetId_guess, index_guess,
        lower_guess, span_guess, value_guess);
    ((List_guess*)this)->Insert((LinkNode_guess*)state);
    return 1;
}

// The moddat.ini reader singleton (0x985C18).
// FUNCTION: TITANIUM 0x004B6C31
ModDatIni_guess::ModDatIni_guess()
{
    resource = new Resource_guess("Resources\\moddat.ini", 0);
}

// Creates the Resources\moddat.ini reader (0x00985C18) if there is none yet; 0x004B6CB4 does the same
// and returns it.
// FUNCTION: TITANIUM 0x004B6C71
void InitializeGlobalOwner_guess()
{
    if (g_globalOwner_guess == 0) {
        g_globalOwner_guess = new ModDatIni_guess;
    }
}

// The Resources\moddat.ini reader (0x00985C18), created on first use.
// FUNCTION: TITANIUM 0x004B6CB4
ModDatIni_guess* GetGlobalOwner_guess()
{
    if (g_globalOwner_guess != 0) {
        return g_globalOwner_guess;
    }
    g_globalOwner_guess = new ModDatIni_guess;
    return g_globalOwner_guess;
}

struct Setting_guess {
    // EXTERNAL: TITANIUM 0x00575140 Setting_guess::Set_guess
    void Set_guess(const char* name_guess, float default_guess, unsigned int value_guess);
};

struct SettingWrapper_guess {
    Setting_guess* setting; // 0x00
    void GetPESFactor_guess(unsigned int value_guess);
    void GetTIFactor_guess(unsigned int value_guess);
    void GetFPCOffset_guess(unsigned int value_guess);
    void GetROffset_guess(unsigned int value_guess);
    void GetCOFactor_guess(unsigned int value_guess);
    void GetZCMinDis_guess(unsigned int value_guess);
};

// Six moddat.ini float getters: 0x575140 is the ini GetFloat(key, default, flags) (tu_090),
// and the float comes back in st(0), which the void declarations hide. What the keys tune is not known.
// FUNCTION: TITANIUM 0x004B6CF7
void SettingWrapper_guess::GetPESFactor_guess(unsigned int value_guess)
{
    setting->Set_guess("PESFactor", 1.0f, value_guess);
}

// moddat.ini float "TIFactor" (default 1.0) for `value` (0x00575140; the result comes back in st(0)).
// FUNCTION: TITANIUM 0x004B6D10
void SettingWrapper_guess::GetTIFactor_guess(unsigned int value_guess)
{
    setting->Set_guess("TIFactor", 1.0f, value_guess);
}

// moddat.ini float "FPCOffset" (default 0.0) for `value` (0x00575140).
// FUNCTION: TITANIUM 0x004B6D29
void SettingWrapper_guess::GetFPCOffset_guess(unsigned int value_guess)
{
    setting->Set_guess("FPCOffset", 0.0f, value_guess);
}

// moddat.ini float "ROffset" (default 3.125) for `value` (0x00575140).
// FUNCTION: TITANIUM 0x004B6D42
void SettingWrapper_guess::GetROffset_guess(unsigned int value_guess)
{
    setting->Set_guess("ROffset", 3.125f, value_guess);
}

// moddat.ini float "COFactor" (default 1.0) for `value` (0x00575140).
// FUNCTION: TITANIUM 0x004B6D5F
void SettingWrapper_guess::GetCOFactor_guess(unsigned int value_guess)
{
    setting->Set_guess("COFactor", 1.0f, value_guess);
}

// moddat.ini float "ZCMinDis" (default 3.0) for `value` (0x00575140).
// FUNCTION: TITANIUM 0x004B6D78
void SettingWrapper_guess::GetZCMinDis_guess(unsigned int value_guess)
{
    setting->Set_guess("ZCMinDis", 3.0f, value_guess);
}

// moddat.ini reader destructor: releases and frees the ini resource.
// FUNCTION: TITANIUM 0x004B6D95
ModDatIni_guess::~ModDatIni_guess()
{
    Resource_guess* resource = this->resource;
    if (resource != 0) {
        resource->Release_guess();
        free(resource);
    }
    this->resource = 0;
}

// Deletes the moddat.ini reader singleton (0x00985C18) and clears the pointer; the global teardown
// (0x00497395) calls it.
// FUNCTION: TITANIUM 0x004B6DB3
void ClearGlobalOwner_guess()
{
    delete g_globalOwner_guess;
    g_globalOwner_guess = 0;
}

#define g_checksumTable_guess EQ_ARRAY(unsigned int, 0x0078E418)

// MemChecker0 (MQ2): CRC-32 with the standard table (0x78E418), seed 0xFFFFFFFF and no final inversion.
// SpellManager (tu_089) checksums each spell with it.
// FUNCTION: TITANIUM 0x004B6C04
// @early-stop: unknown, diff ndiff=9
unsigned int __cdecl MemChecker0(const char* data, int length)
{
    int index = 0;
    unsigned int checksum = 0xffffffff;
    if (length > 0) {
        do {
            unsigned int tableIndex = (checksum ^ data[index]) & 0xff;
            checksum = (checksum >> 8) ^ g_checksumTable_guess[tableIndex];
            ++index;
        } while (index < length);
    }
    return checksum;
}

