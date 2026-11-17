// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 5: a hint from compare/tumap.py.
// Audio triggers: the SIDL "AudioTriggersWindow" (ATW_* children) plays a .wav when a chat line matches a
// pattern. AudioTriggerManager_guess is the lazy singleton at 0x0079C144; triggers persist per character in
// .\userdata\AT_<folder>_<character>_<server>.ini, section "Triggers". The TList, ArrayClass2 and pooled
// name-hash helpers here serve it; the many small structs are views of the manager or the window.
#include "titanium/types.h"

extern "C" int __cdecl _toupper(int value);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

// EXTERNAL: TITANIUM 0x0060E985 operator_new_guess
void* __cdecl operator_new_guess(unsigned int size);

// EXTERNAL: TITANIUM 0x0060D682 _free_guess
void __cdecl _free_guess(void* memory);

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

// EXTERNAL: TITANIUM 0x0060D5A8 FUN_0060d5a8_guess
void __cdecl FUN_0060d5a8_guess(void);

struct Link_guess;
struct HashEntry_guess;
struct AudioTriggerManagerSounds_guess;

struct Link_call_guess
{
    // EXTERNAL: TITANIUM 0x004055F2 Link_call_guess::LinkAfter_guess
    void LinkAfter_guess(Link_guess* next);
};

// One view for a TList node (prev +0, next +4, owning list +8) and a list head (first +0, last +4).
// On an AudioTrigger_guess node, +0xC is the pattern and +0x10 the sound name.
struct Link_guess
{
    Link_guess* field00_guess; // 0x0
    Link_guess* field04_guess; // 0x4
    Link_guess* field08_guess; // 0x8
    CXStr text_guess; // 0xC
    CXStr soundName_0010_guess; // 0x10

    void LinkAfter_guess(Link_guess* next);
    void InsertAfter_guess(Link_guess* item, Link_guess* next);
    void Unlink_guess();

    // EXTERNAL: TITANIUM 0x004B6E52 Link_guess::FUN_004b6e52_guess
    void FUN_004b6e52_guess(Link_guess* item);

    void MoveNodeDown_guess(Link_guess* item);
    void MoveNodeUp_guess(Link_guess* previous);

    // EXTERNAL: TITANIUM 0x0047C397 Link_guess::FUN_0047c397_guess
    HashEntry_guess* FUN_0047c397_guess(HashEntry_guess* item);

    // EXTERNAL: TITANIUM 0x00405637 Link_guess::LinkBefore_guess
    void LinkBefore_guess(Link_guess* item);

    HashEntry_guess* FindByName_guess(void* item);

    char AddUniqueByName_guess(void* item);

    void Add_guess(Link_guess* item);
    void InsertBefore_guess(Link_guess* previous, Link_guess* item);
};

struct LinkOwner_guess
{
    unsigned char flag_guess; // 0x0
    char padding_guess[3];
    Link_guess list_guess; // 0x4

    void MoveTriggerDown_guess(Link_guess* item);
    void DeleteTrigger_guess(void* item);
    void MoveTriggerUp_guess(Link_guess* previous);
};

struct SearchPredicate_guess
{
    // EXTERNAL: TITANIUM 0x00573B10 SearchPredicate_guess::FUN_00573b10_guess
    int FUN_00573b10_guess(int key, int mode);
};

struct SearchNode_guess
{
    char padding00_guess[4];
    SearchNode_guess* next_guess; // 0x4
    char padding08_guess[4];
    SearchPredicate_guess predicate_guess; // 0xC
};

struct SearchList_guess
{
    char padding00_guess[4];
    SearchNode_guess* first_guess; // 0x4

    SearchNode_guess* FindTriggerByPattern_guess(int key);
};

// Pooled hash entry: the object (an AudioTriggerSound_guess), its name hash, the bucket chain.
struct HashEntry_guess
{
    void* field00_guess; // 0x0
    unsigned int key_guess; // 0x4
    HashEntry_guess* next_guess; // 0x8
};

struct KeyText_guess
{
    int field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x00572300 KeyText_guess::FUN_00572300_guess
    const char* FUN_00572300_guess();

    // EXTERNAL: TITANIUM 0x004482FB KeyText_guess::~KeyText_guess
    ~KeyText_guess();
};

struct KeyTextOwner_guess
{
    char padding_guess[4];
    KeyText_guess text_guess; // 0x4
};

#include "titanium/layouts/core.h"

struct PathInputRoot_guess
{
    char padding_guess[8];
    VBTable* input_guess; // 0x8
};

struct BufferService_guess
{
    // EXTERNAL: TITANIUM 0x00493B8F BufferService_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
};

// EXTERNAL: TITANIUM 0x005749F0 FUN_005749f0_guess
void __cdecl FUN_005749f0_guess(int mode, const char* input, char* output, int size);

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(char* output, const char* format, ...);

struct PathOwner_guess
{
    char padding_guess[0x7c];
    KeyText_guess keyText_guess; // 0x7c

    void GetUserIniPath_guess(char* output);
};

struct Str_guess
{
    int field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);

    Str_guess() : field00_guess(0)
    {
    }

    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::Release_guess
    void Release_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x00572300 Str_guess::Get_guess
    const char* Get_guess();

    ~Str_guess()
    {
        if (field00_guess != 0)
        {
            Release_guess(field00_guess);
        }
        field00_guess = 0;
    }
};

struct IniWriter_guess
{
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0c_guess;

    // EXTERNAL: TITANIUM 0x005764E0 IniWriter_guess::IniWriter_guess
    IniWriter_guess(const char* path_guess, const char* section_guess);

    // EXTERNAL: TITANIUM 0x00576050 IniWriter_guess::Write_guess
    void Write_guess(const char* key_guess, const char* value_guess, int flag_guess);

    // EXTERNAL: TITANIUM 0x00575FF0 IniWriter_guess::WriteInt_guess
    void WriteInt_guess(const char* key_guess, int value_guess, int flag_guess);

    // EXTERNAL: TITANIUM 0x005761D0 IniWriter_guess::~IniWriter_guess
    ~IniWriter_guess();
};

struct TriggerOwner_guess
{
    unsigned char flag_guess; // 0x0
    char padding_guess[3];
    Link_guess* first_guess; // 0x4
    char padding08_guess[0x74];
    CXStr path_guess; // 0x7c

    void SaveTriggers_guess();
};

struct PathBuffers_guess
{
    char converted_guess[256];
    char name_guess[256];
};

struct HashTable_guess
{
    char padding_guess[0x3c];
    HashEntry_guess** buckets_guess; // 0x3c
    int bucketCount_guess; // 0x40

    HashEntry_guess* FindEntry_guess(unsigned int key);
    HashEntry_guess* FirstEntry_guess();
    HashEntry_guess* NextEntry_guess(HashEntry_guess* item);

    char RemoveEntry_guess(HashEntry_guess* item, unsigned int hash);

    void Remove_guess(HashEntry_guess* item);
    void DeleteAllSounds_guess();
};

struct LookupOwner_guess
{
    char padding_guess[0x0c];
    HashTable_guess table_guess; // 0x0c

    char PlaySoundByName_guess(void* item);
};

struct KeyLookupCheck_guess
{
    void* field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x00571E00 KeyLookupCheck_guess::KeyLookupCheck_guess
    KeyLookupCheck_guess(const char* value);

    // EXTERNAL: TITANIUM 0x00571D00 KeyLookupCheck_guess::Release_guess
    void Release_guess(void* value);

    ~KeyLookupCheck_guess()
    {
        if (field00_guess != 0)
        {
            Release_guess(field00_guess);
        }
    }

    // EXTERNAL: TITANIUM 0x00574030 KeyLookupCheck_guess::FUN_00574030_guess
    char FUN_00574030_guess(void* value, int mode);
};

struct KeyLookupOwner_guess
{
    char padding00_guess[4];
    KeyLookupOwner_guess* next_guess; // 0x4
    char padding08_guess[4];
    int field0c_guess; // 0x0c
    KeyText_guess text_guess; // 0x10
    LookupOwner_guess* lookup_guess; // 0x14

    char PlaySound_guess();
    char PlayIfMatches_guess(KeyLookupCheck_guess* check);
    void CheckChatText_guess(const char* value);
};

extern "C" int __cdecl __stricmp(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060E620 strncpy
extern "C" char* __cdecl strncpy(char* dest, const char* src, unsigned int count);

// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" unsigned int __cdecl strlen(const char* text);

struct CString_guess
{
    // EXTERNAL: TITANIUM 0x004482FB CString_guess::Destroy_guess
    void Destroy_guess();

    void* VectorDeletingDestructor_guess(unsigned char flags);
};

struct CStringField_guess
{
    int storage_guess;

    CStringField_guess() : storage_guess(0)
    {
    }

    // EXTERNAL: TITANIUM 0x00571FC0 CStringField_guess::Set_guess
    void Set_guess(const char* value);

    ~CStringField_guess()
    {
        ((CString_guess*)this)->Destroy_guess();
    }
};

// One trigger: a TList node (+0..+8), Pattern +0xC, Sound +0x10, owning manager +0x14.
struct AudioTrigger_guess
{
    int field00_guess;
    int field04_guess;
    int field08_guess;
    CStringField_guess first_guess;
    CStringField_guess second_guess;
    int field14_guess;

    AudioTrigger_guess(int value, const char* first, const char* second);
    ~AudioTrigger_guess();
};

struct AudioTriggerQueue_guess
{
    // EXTERNAL: TITANIUM 0x004B6E73 AudioTriggerQueue_guess::GetNext_guess
    AudioTrigger_guess* GetNext_guess();

    void DeleteAll_guess();
};

struct OwnerQueueTable_guess
{
    char padding00_guess[0x04];
    AudioTriggerQueue_guess queue_guess; // 0x04
    char padding05_guess[0x07];
    HashTable_guess table_guess; // 0x0c

    void ClearAll_guess();
};

struct CStringAllocation_guess
{
    int count_guess; // 0x0
};

typedef void (__cdecl *CStringDestructor_guess)(void* item);

// EXTERNAL: TITANIUM 0x004482FB CStringDestructorCallback_guess
void __cdecl CStringDestructorCallback_guess(void* item);

// EXTERNAL: TITANIUM 0x0060D6E5 eh_vector_destructor_iterator_guess
void __stdcall eh_vector_destructor_iterator_guess(void* array, unsigned int elementSize, int count, CStringDestructor_guess destructor);

// EXTERNAL: TITANIUM 0x0060D682 free_vector_guess
void __cdecl free_vector_guess(void* memory);

struct Link_insert_guess
{
    Link_insert_guess* field00_guess; // 0x0
    Link_insert_guess* field04_guess; // 0x4

    void LinkBefore_guess(Link_insert_guess* item);
};

struct Flag_guess
{
    unsigned char field00_guess; // 0x0

    void SetDirty_guess();
};

struct ThrowOwner_guess
{
    void ThrowSelf_guess();
};

struct Resource_guess
{
    // EXTERNAL: TITANIUM 0x004C529E Resource_guess::Release_guess
    void Release_guess();
};

struct ResourceBase_guess
{
    int field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x004482FB ResourceBase_guess::~ResourceBase_guess
    ~ResourceBase_guess();
};

struct ResourceMember_guess
{
    int field00_guess; // 0x0
    int field04_guess; // 0x4

    // EXTERNAL: TITANIUM 0x004482FB ResourceMember_guess::~ResourceMember_guess
    ~ResourceMember_guess();
};

struct ResourceOwner_guess : ResourceBase_guess
{
    ResourceMember_guess member_guess; // 0x4
    Resource_guess* first_guess; // 0xC
    Resource_guess* second_guess; // 0x10

    ~ResourceOwner_guess();
};

struct Divisor_guess
{
    int value_guess; // 0x0
};

struct Callback_guess
{
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0c_guess();
    virtual void Invoke_guess(int value);
};

struct CallbackOwner_guess
{
    char padding_guess[0x0c];
    Callback_guess* callback_guess; // 0xC

    char Play_guess();
};

struct IndexTable_guess
{
    char padding_guess[0x4c];
    int current_guess; // 0x4c
    int* slots_guess; // 0x50

    void MarkBucketUsed_guess(int index);
};

struct Element12_guess
{
    int field00_guess;
    int field04_guess;
    int field08_guess;
};

struct ElementArray_guess
{
    int count_guess;
    Element12_guess* elements_guess;
    int capacity_guess; // 0x8
    unsigned char flag_guess; // 0xC

    void Reallocate_guess(int capacity);
    Element12_guess* Get_guess(int index);
    void SetLength_guess(int count);
};

struct ItemSubobject_guess
{
    char storage_guess[0x20];

    // EXTERNAL: TITANIUM 0x0047C3AF ItemSubobject_guess::Initialize_guess
    void Initialize_guess(int size);

    // EXTERNAL: TITANIUM 0x004B73EE ItemSubobject_guess::Clear_guess
    void Clear_guess();
};

struct EntryPool_guess
{
    int field00_guess; // 0x0
    int field04_guess; // 0x4
    int field08_guess; // 0x8
    unsigned char field0c_guess; // 0xC
    char padding0d_guess[3];
    int field10_guess; // 0x10
    int field14_guess; // 0x14
    int field18_guess; // 0x18
    int field1c_guess; // 0x1C
    ItemSubobject_guess subobject_guess; // 0x20

    // EXTERNAL: TITANIUM 0x0050F3F6 EntryPool_guess::Reset_guess
    void Reset_guess();

    EntryPool_guess();
    ~EntryPool_guess()
    {
        subobject_guess.Clear_guess();
    }
};

// The Mac client's ArrayClass2: elements live in chunks of chunkSize, element i at
// items[i >> shift][i & mask]. field00 is the element count, count_guess the chunk count and enabled_guess
// the valid flag (cleared by an allocation failure, which then throws). *Str = CXStr, *Int = int elements.
struct ArrayClass2_guess
{
    int field00_guess; // 0x0
    int chunkSize_guess; // 0x4
    unsigned int mask_guess; // 0x8
    unsigned int shift_guess; // 0xC
    void** items_guess; // 0x10
    int count_guess; // 0x14
    unsigned char enabled_guess; // 0x18

    ArrayClass2_guess()
    {
        Initialize_guess(0x20);
    }

    // EXTERNAL: TITANIUM 0x0047C3AF ArrayClass2_guess::Initialize_guess
    void Initialize_guess(int chunkSize);

    void ResetInt_guess();
    void DestroyInt_guess();
    // EXTERNAL: TITANIUM 0x00405BFF ArrayClass2_guess::~ArrayClass2_guess
    ~ArrayClass2_guess();
    // EXTERNAL: TITANIUM 0x0051DA09 ArrayClass2_guess::FUN_0051da09_guess
    int FUN_0051da09_guess(int count);
    void Assure_guess(int count);
    void InsertElement_guess(int index, int* value);
    int& At_guess(int index)
    {
        return ((int*)items_guess[index >> shift_guess])[index & (int)mask_guess];
    }
    void SetElementIdxInt_guess(int index, int* value);
    void Append_guess(int* value);
    void ResetStr_guess();
    void AssureStr_guess(int count);
    void DestroyStr_guess();
    void SetElementIdxStr_guess(int index, void* value);
    void AppendStr_guess(void* value);
};

struct CountedArrayBase_guess
{
    int count_guess; // 0x0
    Element12_guess* elements_guess; // 0x4
    int capacity_guess; // 0x8
    unsigned char flag_guess; // 0xC

    CountedArrayBase_guess()
    {
        elements_guess = 0;
        count_guess = 0;
        capacity_guess = 0;
        flag_guess = 1;
    }

    ~CountedArrayBase_guess()
    {
        _free_guess(elements_guess);
    }

    // EXTERNAL: TITANIUM 0x0050F3F6 CountedArrayBase_guess::Reset_guess
    void Reset_guess();
};

struct EntryPoolBlock_guess : CountedArrayBase_guess
{
    int field10_guess; // 0x10

    EntryPoolBlock_guess(int count);
};

struct PooledHashTable_guess : EntryPool_guess
{
    PooledHashTable_guess(int value);

    // EXTERNAL: TITANIUM 0x00406746 PooledHashTable_guess::~PooledHashTable_guess
    ~PooledHashTable_guess();
};

struct OwnerFields_guess
{
    unsigned char field00_guess; // 0x00 dirty: SaveTriggers writes only when set
    char padding01_guess[3];
    int field04_guess; // 0x04 trigger list first
    int field08_guess; // 0x08 trigger list last

    OwnerFields_guess() : field00_guess(0), field04_guess(0), field08_guess(0)
    {
    }
};

struct OwnerKey_guess : KeyText_guess
{
    OwnerKey_guess()
    {
        field00_guess = 0;
    }
};

struct AudioTriggerManager_guess : OwnerFields_guess
{
    PooledHashTable_guess rehash_guess; // 0x0c loaded sounds by name
    char padding4c_guess[0x14];
    ArrayClass2_guess values_guess; // 0x60 folder names under AudioTriggers, minus "shared"
    OwnerKey_guess key_guess; // 0x7c current folder

    // EXTERNAL: TITANIUM 0x00405971 AudioTriggerManager_guess::SaveTriggers_guess
    void SaveTriggers_guess();

    AudioTrigger_guess* AddTrigger_guess(const char* first, const char* second);
    void LoadTriggers_guess();
    void LoadFolder_guess(const char* name);

    AudioTriggerManager_guess();
    ~AudioTriggerManager_guess();
};

// The manager singleton, and the sound-off flag: while it is set LoadFolder loads nothing.
#define g_owner406a53_guess EQ_GLOBAL(AudioTriggerManager_guess*, 0x0079C144)
#define g_audioDisabled_guess EQ_GLOBAL(int, 0x00988DE0)

struct SearchText_guess
{
    int field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x00573B10 SearchText_guess::Compare_guess
    int Compare_guess(const KeyText_guess* key, int flags);
};

struct ResultList_guess
{
    // EXTERNAL: TITANIUM 0x0059C3E0 ResultList_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 ResultList_guess::Add_guess
    void Add_guess(const SearchText_guess* text);
    // EXTERNAL: TITANIUM 0x0059C360 ResultList_guess::Finish_guess
    void Finish_guess(int index);
};

struct ResultOwner_guess
{
    char padding_guess[0x184];
    ResultList_guess* list_guess; // 0x184

    void FillFolderList_guess();
};

struct PointerSlot_guess
{
    int field00_guess; // 0x0

    // EXTERNAL: TITANIUM 0x00571F70 PointerSlot_guess::FUN_00571f70_guess
    void FUN_00571f70_guess(void* value);
};

struct IndexedTable_guess
{
    int count_guess; // 0x0
    char padding04_guess[4];
    unsigned int mask_guess; // 0x8
    unsigned int shift_guess; // 0xC
    int** chunks_guess; // 0x10
    char padding14_guess[4];
    unsigned char enabled_guess; // 0x18

    // EXTERNAL: TITANIUM 0x00548095 IndexedTable_guess::FUN_00548095_guess
    void FUN_00548095_guess(int count);

    void SetElementIdx_guess(int index, int* value);
};

struct CStringArrayElement_guess
{
    int field00_guess;

    // EXTERNAL: TITANIUM 0x0053ACD9 CStringArrayElement_guess::CStringArrayElement_guess
    CStringArrayElement_guess();

    // EXTERNAL: TITANIUM 0x004482FB CStringArrayElement_guess::~CStringArrayElement_guess
    ~CStringArrayElement_guess();
};

// FUNCTION: TITANIUM 0x00405492
// The ArrayClass error path: throws the container itself.
void ThrowOwner_guess::ThrowSelf_guess()
{
    throw this;
}

// FUNCTION: TITANIUM 0x004054A8
// Trial division by the 1000-entry prime table at 0x00693600.
#define g_divisors_guess EQ_ARRAY(int, 0x00693600)
char __cdecl IsPrime_guess(int value)
{
    for (unsigned int index = 0; index < 1000; ++index)
    {
        if (g_divisors_guess[index] * g_divisors_guess[index] >= value)
        {
            break;
        }
        if (value % g_divisors_guess[index] == 0)
        {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: TITANIUM 0x004054DC
// Smallest odd prime >= value: the hash bucket count (Rehash).
int __cdecl NextPrime_guess(int value)
{
    int candidate = value;
    if (candidate % 2 == 0)
    {
        ++candidate;
    }
    while (IsPrime_guess(candidate) == 0)
    {
        candidate += 2;
    }
    return candidate;
}

// FUNCTION: TITANIUM 0x00405501
// Case-blind name hash for the sound table; the >> 26 is a signed (arithmetic) shift on purpose.
unsigned int __cdecl HashStringNoCase_guess(char* text)
{
    unsigned int hash = 0;
    while (*text != 0)
    {
        hash = ((int)hash >> 0x1a) ^ (_toupper((int)*text) + hash * 0x1f);
        ++text;
    }
    return hash;
}

// FUNCTION: TITANIUM 0x0040552D
// Windows code page for the client language: 949, 950, 932, 936 for languages 1, 2, 3, 6, else 1252.
int __cdecl GetLanguageCodePage_guess(int value)
{
    int result = 0x4e4;
    switch (value)
    {
    case 1:
        result = 0x3b5;
        break;
    case 2:
        result = 0x3b6;
        break;
    case 3:
        result = 0x3a4;
        break;
    case 6:
        result = 0x3a8;
        break;
    }
    return result;
}

// FUNCTION: TITANIUM 0x0040555C
// Really ~AudioTriggerSound_guess: releases the audio object (+0xC) and the sound (+0x10). Only the first
// pointer is nulled afterwards (as compiled).
ResourceOwner_guess::~ResourceOwner_guess()
{
    if (first_guess != 0)
    {
        first_guess->Release_guess();
        first_guess = 0;
    }
    if (second_guess != 0)
    {
        second_guess->Release_guess();
    }
}

// FUNCTION: TITANIUM 0x004055CA
// `this` is the manager: SaveTriggers will write the ini.
void Flag_guess::SetDirty_guess()
{
    field00_guess = 1;
}

// FUNCTION: TITANIUM 0x004055CE
// TList primitives follow (Unlink, LinkAfter/Before, InsertAfter/Before, Add, MoveNodeUp/Down); other TUs
// reach them through EXTERNAL lines.
void Link_guess::Unlink_guess()
{
    Link_guess* previous = field00_guess;
    if (previous != 0)
    {
        previous->field04_guess = field04_guess;
    }
    Link_guess* next = field04_guess;
    if (next != 0)
    {
        next->field00_guess = field00_guess;
    }
    field04_guess = 0;
    field00_guess = 0;
    field08_guess = 0;
}

// Links this node into a list right after `next` (+0 is the previous link, +4 the next): it takes over
// `next`'s successor and fixes that successor's back link.
// FUNCTION: TITANIUM 0x004055F2
void Link_guess::LinkAfter_guess(Link_guess* next)
{
    field00_guess = next;
    if (next != 0)
    {
        field04_guess = next->field04_guess;
        next->field04_guess = this;
        if (field04_guess != 0)
        {
            field04_guess->field00_guess = this;
        }
    }
}

// Links `item` after `next` (0x004055F2), makes it the tail when `next` was, and records this list as
// its owner.
// FUNCTION: TITANIUM 0x00405611
void Link_guess::InsertAfter_guess(Link_guess* item, Link_guess* next)
{
    ((Link_call_guess*)item)->LinkAfter_guess(next);
    if (field04_guess == next)
    {
        field04_guess = item;
    }
    item->field08_guess = this;
}

// Links this node into a list right before `item` (+0 is the previous link, +4 the next): it takes over
// `item`'s predecessor and fixes that predecessor's forward link.
// FUNCTION: TITANIUM 0x00405637
void Link_insert_guess::LinkBefore_guess(Link_insert_guess* item)
{
    field04_guess = item;
    if (item != 0)
    {
        field00_guess = item->field00_guess;
        item->field00_guess = this;
        if (field00_guess != 0)
        {
            field00_guess->field04_guess = this;
        }
    }
}

// FUNCTION: TITANIUM 0x00405654
// Pooled hash table walk (Find/First/Next): buckets +0x3C, bucket count +0x40, bucket = key % count.
HashEntry_guess* HashTable_guess::FindEntry_guess(unsigned int key)
{
    HashEntry_guess* item = buckets_guess[key % (unsigned int)bucketCount_guess];
    while (item != 0 && item->key_guess != key)
    {
        item = item->next_guess;
    }
    return item;
}

// First entry of the table: the head of the first non-empty bucket, or null.
// FUNCTION: TITANIUM 0x00405678
HashEntry_guess* HashTable_guess::FirstEntry_guess()
{
    int count = bucketCount_guess;
    int index = 0;
    if (count > 0)
    {
        HashEntry_guess** bucket = buckets_guess;
        do
        {
            HashEntry_guess* item = *bucket;
            if (item != 0)
            {
                return item;
            }
            ++index;
            ++bucket;
        } while (index < count);
    }
    return 0;
}

// Entry after `item`: its chain successor, else the head of the next non-empty bucket, else null.
// FUNCTION: TITANIUM 0x00405697
HashEntry_guess* HashTable_guess::NextEntry_guess(HashEntry_guess* item)
{
    int i = item->key_guess % bucketCount_guess;
    HashEntry_guess* next = item->next_guess;
    if (next != 0)
    {
        return next;
    }
    int j = i + 1;
    if (i + 1 < bucketCount_guess)
    {
        for (; j < bucketCount_guess; ++j)
        {
            next = buckets_guess[j];
            if (next != 0)
            {
                return next;
            }
        }
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004056CE
// CXStr vector deleting dtor: flag 2 = array with a count header before it, flag 1 = free the memory.
void* CString_guess::VectorDeletingDestructor_guess(unsigned char flags)
{
    void* allocation;
    if ((flags & 2) != 0)
    {
        CStringAllocation_guess* header = ((CStringAllocation_guess*)this) - 1;
        eh_vector_destructor_iterator_guess(this, 4, header->count_guess, CStringDestructorCallback_guess);
        if ((flags & 1) != 0)
        {
            free_vector_guess(header);
        }
        allocation = header;
    }
    else
    {
        Destroy_guess();
        if ((flags & 1) != 0)
        {
            free(this);
        }
        allocation = this;
    }
    return allocation;
}

// FUNCTION: TITANIUM 0x00405719
// Chains a newly used bucket into the used-bucket list (links +0x50, -1 = unlinked; head +0x4C).
void IndexTable_guess::MarkBucketUsed_guess(int index)
{
    int* slot = slots_guess + index;
    if (*slot == -1 && current_guess != index)
    {
        *slot = current_guess;
        current_guess = index;
    }
}

// FUNCTION: TITANIUM 0x004055B4
// Plays a sound through slot 4 of its audio object (+0xC); 0 when it has none.
char CallbackOwner_guess::Play_guess()
{
    if (callback_guess == 0)
    {
        return 0;
    }
    callback_guess->Invoke_guess(0);
    return 1;
}

// FUNCTION: TITANIUM 0x00405739
// Array of 12-byte hash entries (the pool blocks). A failed allocation empties it and clears the valid flag.
void ElementArray_guess::Reallocate_guess(int capacity)
{
    if (capacity != 0 && (capacity > count_guess || elements_guess == 0))
    {
        Element12_guess* allocation = (Element12_guess*)operator_new_guess(capacity * sizeof(Element12_guess));
        if (allocation != 0)
        {
            if (elements_guess != 0)
            {
                int i = 0;
                if (count_guess > 0)
                {
                    do
                    {
                        allocation[i] = elements_guess[i];
                        ++i;
                    }
                    while (i < count_guess);
                }
            }
            _free_guess(elements_guess);
            elements_guess = allocation;
            capacity_guess = capacity;
        }
        else
        {
            _free_guess(elements_guess);
            elements_guess = 0;
            capacity_guess = 0;
            flag_guess = 0;
        }
    }
}

// FUNCTION: TITANIUM 0x004057BB
// No return after ThrowSelf_guess: it never returns.
Element12_guess* ElementArray_guess::Get_guess(int index)
{
    if (index < count_guess && index >= 0 && elements_guess != 0)
    {
        return elements_guess + index;
    }
    ((ThrowOwner_guess*)this)->ThrowSelf_guess();
}

// Audio trigger: unlinked, with its pattern `first` and sound `second` copied and `value` at +0x14.
// FUNCTION: TITANIUM 0x004057DD
AudioTrigger_guess::AudioTrigger_guess(int value, const char* first, const char* second)
    : field00_guess(0), field04_guess(0), field08_guess(0), first_guess(), second_guess(), field14_guess(value)
{
    first_guess.Set_guess(first);
    second_guess.Set_guess(second);
}

// Resizes the hash-entry array to `count` (0x00405739); the count is kept only when that succeeded.
// FUNCTION: TITANIUM 0x00405D8F
void ElementArray_guess::SetLength_guess(int count)
{
    Reallocate_guess(count);
    if (elements_guess != 0)
    {
        count_guess = count;
    }
}

// FUNCTION: TITANIUM 0x004058E6
// .\userdata\AT_<folder>_<character>_<server>.ini; the character name is converted with the language's
// code page (language at 0x00923D74).
void PathOwner_guess::GetUserIniPath_guess(char* output)
{
    PathBuffers_guess buffers;
    FUN_005749f0_guess(
        GetLanguageCodePage_guess(EQ_GLOBAL(int, 0x00923D74)),
        (char*)EQ_GLOBAL(PathInputRoot_guess*, 0x00905D00) +
            EQ_GLOBAL(PathInputRoot_guess*, 0x00905D00)->input_guess->vbase_offset + 0x44,
        buffers.converted_guess,
        0x100);
    EQ_GLOBAL(BufferService_guess*, 0x00988DF0)->GetServerShortName_guess(buffers.name_guess);
    FUN_005738b0_guess(output, ".\\userdata\\AT_%s_%s_%s.ini",
                       keyText_guess.FUN_00572300_guess(), buffers.converted_guess,
                       buffers.name_guess);
}

// FUNCTION: TITANIUM 0x00405971
// @early-stop: budget, structural ndiff=15
// Only when dirty and a folder is set: Pattern<n>/Sound<n> per trigger, then PatternCount.
void TriggerOwner_guess::SaveTriggers_guess()
{
    if (flag_guess != 0)
    {
        flag_guess = 0;
        if (path_guess.Ptr != 0 && path_guess.Ptr->length != 0)
        {
            CXStr path;
            ((PathOwner_guess*)this)->GetUserIniPath_guess((char*)&path);
            IniWriter_guess writer(path, "Triggers");
            int index = 0;
            CXStr first;
            CXStr second;
            CXStr buf;
            FUN_005738b0_guess((char*)&buf, "Pattern%d", 0);
            for (Link_guess* link = first_guess; link != 0; link = link->field04_guess)
            {
                FUN_005738b0_guess((char*)&buf, "Pattern%d", index);
                writer.Write_guess(buf, link->text_guess, 0);
                FUN_005738b0_guess((char*)&buf, "Sound%d", index);
                writer.Write_guess(buf, link->soundName_0010_guess, 0);
                ++index;
            }
            writer.WriteInt_guess("PatternCount", index, 0);
        }
    }
}

// FUNCTION: TITANIUM 0x00405AD9
// Case-blind CXStr compare (0x00573B10, mode 1, 0 = equal) of each pattern against `key`.
SearchNode_guess* SearchList_guess::FindTriggerByPattern_guess(int key)
{
    SearchNode_guess* node = first_guess;
    while (node != 0)
    {
        if (node->predicate_guess.FUN_00573b10_guess(key, 1) == 0)
        {
            return node;
        }
        node = node->next_guess;
    }
    return 0;
}

// Empty destructor; the two CXStr members release themselves.
// FUNCTION: TITANIUM 0x00405B02
AudioTrigger_guess::~AudioTrigger_guess()
{
}

// Appends `item` to this list (+0 head, +4 tail): linked after the old tail (0x004055F2), or made the head
// of an empty list, then becomes the tail and records this list as its owner (+8).
// FUNCTION: TITANIUM 0x00405B38
void Link_guess::Add_guess(Link_guess* item)
{
    Link_guess* next = field04_guess;
    if (next != 0)
    {
        ((Link_call_guess*)item)->LinkAfter_guess(next);
    }
    else
    {
        field00_guess = item;
    }
    field04_guess = item;
    item->field08_guess = this;
}

// Moves `item` one place towards the tail: unlinks it and relinks it after its old successor.
// FUNCTION: TITANIUM 0x00405B5E
void Link_guess::MoveNodeDown_guess(Link_guess* item)
{
    Link_guess* next = item->field04_guess;
    if (next != 0)
    {
        FUN_004b6e52_guess(item);
        InsertAfter_guess(item, next);
    }
}

// FUNCTION: TITANIUM 0x00405B83
// Sound lookup: hash bucket, then stricmp on each object's name; an entry with no object ends the scan.
HashEntry_guess* Link_guess::FindByName_guess(void* item)
{
    if (item == 0 || *(char*)item == 0)
    {
        return 0;
    }
    char* text = (char*)item;
    HashEntry_guess* entry = ((HashTable_guess*)this)->FindEntry_guess(HashStringNoCase_guess(text));
    for (; entry != 0; entry = FUN_0047c397_guess(entry))
    {
        if (entry->field00_guess == 0)
        {
            break;
        }
        const char* value = ((KeyTextOwner_guess*)entry->field00_guess)->text_guess.FUN_00572300_guess();
        if (__stricmp(text, value) == 0)
        {
            break;
        }
    }
    return entry;
}

// Links `previous` before `item` (0x00405637), makes it the head when `item` was, and records this list
// as its owner.
// FUNCTION: TITANIUM 0x00405BDB
void Link_guess::InsertBefore_guess(Link_guess* previous, Link_guess* item)
{
    previous->LinkBefore_guess(item);
    if (field00_guess == item)
    {
        field00_guess = previous;
    }
    previous->field08_guess = this;
}

// Frees every string chunk (vector delete) and the chunk table; the array is left empty.
// FUNCTION: TITANIUM 0x00405BFF
void ArrayClass2_guess::ResetStr_guess()
{
    int index = 0;
    if (count_guess > 0)
    {
        do
        {
            CString_guess* item = (CString_guess*)items_guess[index];
            if (item != 0)
            {
                item->VectorDeletingDestructor_guess(3);
            }
            ++index;
        } while (index < count_guess);
    }
    free_vector_guess(items_guess);
    items_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Grows the chunk table so it holds `count` string elements: rounds up to whole chunks (0x0051DA09), keeps
// the old chunk pointers and allocates the new chunks of `chunkSize` elements. On an allocation failure it
// frees the old array (0x00405BFF) and throws; the half-built new table and its new chunks leak.
// FUNCTION: TITANIUM 0x00405C81
void ArrayClass2_guess::AssureStr_guess(int count)
{
    if (enabled_guess != 0 && count > 0)
    {
        count = FUN_0051da09_guess(count);
        if (count > count_guess)
        {
            void** newItems = (void**)operator_new_guess(count << 2);
            if (newItems == 0)
            {
                enabled_guess = 0;
            }
            else
            {
                if (count_guess > 0)
                {
                    int index = 0;
                    do
                    {
                        newItems[index] = items_guess[index];
                        ++index;
                    } while (index < count_guess);
                }
                int index = count_guess;
                if (index < count)
                {
                    do
                    {
                        CStringArrayElement_guess* chunk = new CStringArrayElement_guess[chunkSize_guess];
                        newItems[index] = chunk;
                        if (chunk == 0)
                        {
                            enabled_guess = 0;
                            break;
                        }
                        ++index;
                    } while (index < count);
                }
                if (enabled_guess != 0)
                {
                    _free_guess(items_guess);
                    items_guess = newItems;
                    count_guess = count;
                }
            }
        }
        if (enabled_guess == 0)
        {
            ResetStr_guess();
            ((ThrowOwner_guess*)this)->ThrowSelf_guess();
        }
    }
}

struct TextValue_guess
{
    char padding_guess[0x220];

    // EXTERNAL: TITANIUM 0x004C596F TextValue_guess::TextValue_guess
    TextValue_guess(int manager_guess, const char* text_guess, int first_guess, int second_guess);
};

struct ListValue_guess
{
    char padding_guess[0x2c];

    // EXTERNAL: TITANIUM 0x004C52F9 ListValue_guess::ListValue_guess
    ListValue_guess(int manager_guess);

    virtual void Slot00_guess();
    virtual void Slot01_guess(TextValue_guess* value_guess);
};

struct Manager_guess
{
    char padding_guess[4];
    int field04_guess; // 0x4

    int GetField04_guess()
    {
        return field04_guess;
    }
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00851390)

struct AudioTriggerSound_guess
{
    Str_guess first_guess;        // 0x0
    Str_guess second_guess;       // 0x4
    AudioTriggerManagerSounds_guess* owner_guess;     // 0x8
    ListValue_guess* list_guess;  // 0xC
    TextValue_guess* text_guess;  // 0x10

    AudioTriggerSound_guess(AudioTriggerManagerSounds_guess* owner, int first, AudioTriggerSound_guess* second);
};

struct AudioTriggerManagerSounds_guess
{
    char padding_guess[0x0c];
    Link_guess entries_guess;

    void AddSound_guess(int first, AudioTriggerSound_guess* second);
    void LoadSoundFolder_guess(const char* directory);
};

// FUNCTION: TITANIUM 0x00405834
// One per .wav: `first` is the path, `second` the name without extension (both passed as ints, see
// LoadSoundFolder). Makes the sound (0x004C596F) and the audio object (0x004C52F9) that plays it.
AudioTriggerSound_guess::AudioTriggerSound_guess(AudioTriggerManagerSounds_guess* owner, int first, AudioTriggerSound_guess* second)
    : first_guess(reinterpret_cast<const char*>(first)),
      second_guess(reinterpret_cast<const char*>(second))
{
    owner_guess = owner;
    text_guess = new TextValue_guess(g_manager_guess->GetField04_guess(),
                                     reinterpret_cast<const char*>(first), 0, 0);
    list_guess = new ListValue_guess(g_manager_guess->field04_guess);
    list_guess->Slot01_guess(text_guess);
}

// EXTERNAL: TITANIUM 0x004B73EE FUN_004b73ee_guess
void __cdecl FUN_004b73ee_guess(void);

// Frees every page and the page table of a paged array (0x004B73EE).
// FUNCTION: TITANIUM 0x00405C7C
void __cdecl DestroyPointerList_guess(void)
{
    FUN_004b73ee_guess();
}

// Plays the loaded sound whose name matches `item` (hash lookup 0x00405B83); 0 when none is loaded.
// FUNCTION: TITANIUM 0x00405DAA
char LookupOwner_guess::PlaySoundByName_guess(void* item)
{
    HashEntry_guess* entry = ((Link_guess*)&table_guess)->FindByName_guess(item);
    if (entry == 0 || entry->field00_guess == 0)
    {
        return 0;
    }
    return ((CallbackOwner_guess*)entry->field00_guess)->Play_guess();
}

// FUNCTION: TITANIUM 0x00405DCE
// @early-stop: budget, structural ndiff=1
// Appends to the trigger list (+4) and marks the manager dirty.
AudioTrigger_guess* AudioTriggerManager_guess::AddTrigger_guess(const char* first, const char* second)
{
    AudioTrigger_guess* item = new AudioTrigger_guess((int)this, first, second);
    ((Link_guess*)&field04_guess)->Add_guess((Link_guess*)item);
    field00_guess = 1;
    return item;
}

// Moves a trigger one place down in the list and marks the triggers dirty for saving.
// FUNCTION: TITANIUM 0x00405E1F
void LinkOwner_guess::MoveTriggerDown_guess(Link_guess* item)
{
    list_guess.MoveNodeDown_guess(item);
    flag_guess = 1;
}

// Moves `previous` one place towards the head: unlinks it and relinks it before its old predecessor.
// FUNCTION: TITANIUM 0x00405E35
void Link_guess::MoveNodeUp_guess(Link_guess* previous)
{
    Link_guess* item = previous->field00_guess;
    if (item != 0)
    {
        FUN_004b6e52_guess(previous);
        InsertBefore_guess(previous, item);
    }
}

// Deletes every queued trigger (0x004B6E73 hands out the next one until none is left).
// FUNCTION: TITANIUM 0x00405E59
void AudioTriggerQueue_guess::DeleteAll_guess()
{
    AudioTrigger_guess* item;
    while ((item = GetNext_guess()) != 0)
    {
        item->~AudioTrigger_guess();
        free(item);
    }
}

// Frees the string pages and empties the array (0x00405BFF).
// FUNCTION: TITANIUM 0x00405E7D
void ArrayClass2_guess::DestroyStr_guess()
{
    ResetStr_guess();
}

// PooledHashTable_guess as Rehash and the pool see it: entry pool +0x00..+0x38 (free list +0x20), buckets
// +0x3C, bucket count +0x40, entry count +0x44, used buckets +0x48, used-bucket chain +0x4C/+0x50.
struct RehashIndex_guess
{
    int field00_guess; // 0x0
    char padding04_guess[0x0c];
    int field10_guess; // 0x10
    int count_guess; // 0x14
    int field18_guess; // 0x18
    int field1c_guess; // 0x1c
    int queue_count_guess; // 0x20
    char padding24_guess[4];
    unsigned int queue_mask_guess; // 0x28
    unsigned int queue_shift_guess; // 0x2c
    HashEntry_guess*** queue_chunks_guess; // 0x30
    char padding34_guess[8];
    HashEntry_guess** buckets_guess; // 0x3c
    int bucketCount_guess; // 0x40
    int field44_guess; // 0x44
    int field48_guess; // 0x48
    int current_guess; // 0x4c
    int* slots_guess; // 0x50

    void InsertIntoBucket_guess(unsigned int index, HashEntry_guess* item);

    // EXTERNAL: TITANIUM 0x0040644A RehashIndex_guess::AllocEntry_guess
    HashEntry_guess* AllocEntry_guess();

    void InsertEntry_guess(void** value, unsigned int key);
    void Rehash_guess(int value);
};

// Pushes `item` on the front of bucket `index`; a bucket that was empty is marked used and counted (+0x48).
// FUNCTION: TITANIUM 0x00405C38
// @early-stop: budget, structural ndiff=19
void RehashIndex_guess::InsertIntoBucket_guess(unsigned int index, HashEntry_guess* item)
{
    HashEntry_guess* current = buckets_guess[index];
    if (current == 0)
    {
        item->next_guess = 0;
        buckets_guess[index] = item;
        ((IndexTable_guess*)this)->MarkBucketUsed_guess((int)index);
        ++field48_guess;
    }
    else
    {
        item->next_guess = current;
        buckets_guess[index] = item;
    }
}

// FUNCTION: TITANIUM 0x00405E82
// Rebuilds the buckets with NextPrime(value) slots and re-inserts every entry.
void RehashIndex_guess::Rehash_guess(int value)
{
    HashEntry_guess** oldBuckets = buckets_guess;
    int oldCount = bucketCount_guess;
    bucketCount_guess = NextPrime_guess(value);
    buckets_guess = (HashEntry_guess**)operator_new_guess(bucketCount_guess << 2);
    memset(buckets_guess, 0, bucketCount_guess << 2);
    _free_guess(slots_guess);
    slots_guess = (int*)operator_new_guess(bucketCount_guess << 2);
    int index = bucketCount_guess;
    while (index != 0)
    {
        --index;
        slots_guess[index] = -1;
    }
    current_guess = -1;
    field48_guess = 0;
    if (field44_guess > 0)
    {
        value = 0;
        if (oldCount > 0)
        {
            do
            {
                HashEntry_guess* item = oldBuckets[value];
                while (item != 0)
                {
                    HashEntry_guess* current = item;
                    item = item->next_guess;
                    InsertIntoBucket_guess(current->key_guess % (unsigned int)bucketCount_guess, current);
                }
            } while (++value < oldCount);
        }
    }
    _free_guess(oldBuckets);
}

// FUNCTION: TITANIUM 0x00405F3A
// Entry pool: 3000-entry blocks (EntryPoolBlock_guess) plus a free list of returned entries.
EntryPool_guess::EntryPool_guess()
{
    field04_guess = 0;
    field00_guess = 0;
    field08_guess = 0;
    field0c_guess = 1;
    subobject_guess.Initialize_guess(0x20);
    Reset_guess();
    field10_guess = 0;
    field14_guess = 0;
    field18_guess = 0;
    field1c_guess = 0;
    subobject_guess.Clear_guess();
}

// Stores a string at `index`, growing the array to index + 1 first; negative indexes are ignored.
// FUNCTION: TITANIUM 0x00405F79
void ArrayClass2_guess::SetElementIdxStr_guess(int index, void* value)
{
    if (index >= 0)
    {
        if (index >= field00_guess)
        {
            int newCount = index + 1;
            AssureStr_guess(newCount);
            if (enabled_guess != 0)
            {
                field00_guess = newCount;
            }
        }
        if (enabled_guess != 0)
        {
            ((PointerSlot_guess*)items_guess[index >> shift_guess] + (index & mask_guess))
                ->FUN_00571f70_guess(value);
        }
    }
}

// Hash-entry pool block of `count` entries: reset, +0x10 zeroed, then sized (0x00405D8F).
// FUNCTION: TITANIUM 0x00405FC5
EntryPoolBlock_guess::EntryPoolBlock_guess(int count)
{
    Reset_guess();
    field10_guess = 0;
    ((ElementArray_guess*)this)->SetLength_guess(count);
}

// Stores `*value` at `index` of the paged table, growing it to index + 1 first (0x00548095); negative
// indexes and a table whose last growth failed are ignored.
// FUNCTION: TITANIUM 0x0040600C
void IndexedTable_guess::SetElementIdx_guess(int index, int* value)
{
    if (index < 0)
    {
        return;
    }
    if (index >= count_guess)
    {
        int newCount = index + 1;
        FUN_00548095_guess(newCount);
        if (enabled_guess != 0)
        {
            count_guess = newCount;
        }
    }
    if (enabled_guess != 0)
    {
        chunks_guess[index >> shift_guess][index & mask_guess] = *value;
    }
}

// FUNCTION: TITANIUM 0x00406055
// `this` is a trigger node: its manager (+0x14) plays its sound name (+0x10).
char KeyLookupOwner_guess::PlaySound_guess()
{
    return lookup_guess->PlaySoundByName_guess((void*)text_guess.FUN_00572300_guess());
}

// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
char __cdecl FileExists_guess(const char* path);

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message);

struct AudioConfig_guess
{
    int padding00_guess[4];

    // EXTERNAL: TITANIUM 0x005764E0 AudioConfig_guess::AudioConfig_guess
    AudioConfig_guess(const char* file, const char* section);

    // EXTERNAL: TITANIUM 0x005761D0 AudioConfig_guess::~AudioConfig_guess
    ~AudioConfig_guess();

    // EXTERNAL: TITANIUM 0x005751E0 AudioConfig_guess::Read_guess
    char Read_guess(const char* key, Str_guess* value, int flag);

    // EXTERNAL: TITANIUM 0x00575070 AudioConfig_guess::GetInt_guess
    int GetInt_guess(const char* key, int fallback, const char* section);
};

// FUNCTION: TITANIUM 0x0040606B
// Without a user ini yet, reads .\AudioTriggers\<folder>\AT_InitialSettings.ini. The missing-file log
// lines get the format string but no index (as compiled).
void AudioTriggerManager_guess::LoadTriggers_guess()
{
    Str_guess path;
    ((PathOwner_guess*)this)->GetUserIniPath_guess((char*)&path);
    if (FileExists_guess(path.Get_guess()) == 0)
    {
        FUN_005738b0_guess((char*)&path, ".\\AudioTriggers\\%s\\AT_InitialSettings.ini",
                           key_guess.FUN_00572300_guess());
    }
    AudioConfig_guess config(path.Get_guess(), "Triggers");
    ((OwnerQueueTable_guess*)this)->queue_guess.DeleteAll_guess();
    int index = 0;
    int count = config.GetInt_guess("PatternCount", 0, 0);
    Str_guess pattern;
    Str_guess sound;
    Str_guess name;
    FUN_005738b0_guess((char*)&name, "Pattern%d", 0);
    if (count > 0)
    {
        do
        {
            if (config.Read_guess(name.Get_guess(), &pattern, 0) != 0)
            {
                FUN_005738b0_guess((char*)&name, "Sound%d", index);
                if (config.Read_guess(name.Get_guess(), &sound, 0) != 0)
                {
                    AddTrigger_guess(pattern.Get_guess(), sound.Get_guess());
                }
                else
                {
                    FUN_00574110_guess("Audio Triggers - Sound %d is missing.");
                }
            }
            else
            {
                FUN_00574110_guess("Audio Triggers - Pattern %d is missing.");
            }
            ++index;
            FUN_005738b0_guess((char*)&name, "Pattern%d", index);
        } while (index < count);
    }
}

// Unlinks a trigger, destroys and frees it, and marks the triggers dirty for saving. The window's
// ATW_Delete button (0x00407119) uses it.
// FUNCTION: TITANIUM 0x00406222
void LinkOwner_guess::DeleteTrigger_guess(void* item)
{
    list_guess.FUN_004b6e52_guess((Link_guess*)item);
    if (item != 0)
    {
        ((AudioTrigger_guess*)item)->~AudioTrigger_guess();
        free(item);
    }
    flag_guess = 1;
}

// Moves a trigger one place up in the list and marks the triggers dirty for saving.
// FUNCTION: TITANIUM 0x0040624D
void LinkOwner_guess::MoveTriggerUp_guess(Link_guess* previous)
{
    list_guess.MoveNodeUp_guess(previous);
    flag_guess = 1;
}

// Appends a string to the end of the paged string array.
// FUNCTION: TITANIUM 0x00406263
void ArrayClass2_guess::AppendStr_guess(void* value)
{
    SetElementIdxStr_guess(field00_guess, value);
}

struct ResetItem_guess
{
    char padding00_guess[0x10];
    int field10_guess; // 0x10

    // EXTERNAL: TITANIUM 0x004D99C0 ResetItem_guess::Reset_guess
    void Reset_guess();
};

struct ResetQueue_guess
{
    int count_guess; // 0x0
    char padding04_guess[4];
    unsigned int mask_guess; // 0x8
    unsigned int shift_guess; // 0xC
    HashEntry_guess*** chunks_guess; // 0x10

    // EXTERNAL: TITANIUM 0x0045AEE0 ResetQueue_guess::SetValue_guess
    void SetValue_guess(int value);

    // EXTERNAL: TITANIUM 0x004B73EE ResetQueue_guess::Clear_guess
    void Clear_guess();
};

struct ResetOwner_guess
{
    int field00_guess; // 0x0
    char padding04_guess[0xc];
    int field10_guess; // 0x10
    int count_guess; // 0x14
    char padding18_guess[4];
    int field1c_guess; // 0x1c
    ResetQueue_guess queue_guess; // 0x20

    // EXTERNAL: TITANIUM 0x004EB924 ResetOwner_guess::Slot_guess
    ResetItem_guess** Slot_guess(int index);

    // EXTERNAL: TITANIUM 0x0050319B ResetOwner_guess::FUN_0050319b_guess
    void FUN_0050319b_guess(int count, EntryPoolBlock_guess** value);

    void Reset_guess();
    void FreeBlocks_guess();
};

struct PooledHashTableView_guess
{
    char padding00_guess[0x3c];
    void* field3c_guess; // 0x3C
    char padding40_guess[0x10];
    void* field50_guess; // 0x50

    // EXTERNAL: TITANIUM 0x00406622 PooledHashTableView_guess::FUN_00406622_guess
    void FUN_00406622_guess();
    void DestroyTable_guess();
    void DestroyPooledTable_guess();
};

// FUNCTION: TITANIUM 0x00406271
// Pool reset: each block's used count to 0, free list emptied; the high-water mark (+0x1C) is kept.
void ResetOwner_guess::Reset_guess()
{
    if (field00_guess != 0)
    {
        for (int index = 0; index <= count_guess; ++index)
        {
            ResetItem_guess* item = *Slot_guess(index);
            item->field10_guess = 0;
        }
    }
    queue_guess.SetValue_guess(0);
    int high = field10_guess;
    if (high > field1c_guess)
    {
        field1c_guess = high;
    }
    count_guess = 0;
    field10_guess = 0;
}

// FUNCTION: TITANIUM 0x004062B4
// CXStr match (0x00574030, mode 1) of the chat text against this trigger's pattern.
char KeyLookupOwner_guess::PlayIfMatches_guess(KeyLookupCheck_guess* check)
{
    char result = check->FUN_00574030_guess(&field0c_guess, 1);
    if (result != 0)
    {
        result = PlaySound_guess();
    }
    return result;
}

struct TriggerSearch_guess
{
    int handle_guess; // 0x0
    char data_guess[0x144]; // 0x4

    // EXTERNAL: TITANIUM 0x00576690 TriggerSearch_guess::TriggerSearch_guess
    TriggerSearch_guess(const char* directory_guess, const char* pattern_guess);

    // EXTERNAL: TITANIUM 0x005767D0 TriggerSearch_guess::Next_guess
    char Next_guess(Str_guess* value_guess);

    // EXTERNAL: TITANIUM 0x00576760 TriggerSearch_guess::Find_guess
    char Find_guess(Str_guess* value_guess);

    // EXTERNAL: TITANIUM 0x00576740 TriggerSearch_guess::~TriggerSearch_guess
    ~TriggerSearch_guess();
};

struct AudioTriggerOwner_guess
{
    char padding_guess[0x60];
    ArrayClass2_guess values_guess; // 0x60

    void ListTriggerFolders_guess();
};

// FUNCTION: TITANIUM 0x004062D5
// Every entry found in AudioTriggers except "shared" (always loaded) becomes a folder choice. The compare
// returns 0 on equal, so notShared_guess is nonzero when the name is NOT "shared" (misnamed).
void AudioTriggerOwner_guess::ListTriggerFolders_guess()
{
    values_guess.ResetStr_guess();
    TriggerSearch_guess search_guess("AudioTriggers", EQ_ARRAY(char, 0x0063FAF8));
    Str_guess value_guess;
    while (search_guess.Next_guess(&value_guess) != 0)
    {
        int notShared_guess;
        {
            Str_guess key_guess("shared");
            notShared_guess = ((SearchPredicate_guess*)&value_guess)->FUN_00573b10_guess((int)&key_guess, 0);
        }
        if (notShared_guess != 0)
        {
            values_guess.SetElementIdxStr_guess(values_guess.field00_guess, &value_guess);
        }
    }
}

// FUNCTION: TITANIUM 0x004063F2
// @early-stop: budget, diff ndiff=6
// Called for each chat line (0x004F2F8A). `this` is the manager seen as a list head, so the walk starts at
// its +4; the first matching trigger plays and ends it.
void KeyLookupOwner_guess::CheckChatText_guess(const char* value)
{
    KeyLookupOwner_guess* item = this;
    KeyLookupCheck_guess check(value);
    while ((item = item->next_guess) != 0)
    {
        if (item->PlayIfMatches_guess(&check) != 0)
        {
            break;
        }
    }
}

struct AppendOwner_guess
{
    char padding00_guess[0x10];
    int count_guess; // 0x10
    char padding14_guess[0xc];
    IndexedTable_guess table_guess; // 0x20

    void FreeEntry_guess(int value);
};

// FUNCTION: TITANIUM 0x0040652C
// Returns an entry to the pool's free list and drops the live count.
void AppendOwner_guess::FreeEntry_guess(int value)
{
    table_guess.SetElementIdx_guess(table_guess.count_guess, &value);
    --count_guess;
}

// Empties the pooled name table: resets it, frees every pool block and its slot, then resets the entry
// pool and clears the paged block array.
// FUNCTION: TITANIUM 0x00406545
void ResetOwner_guess::FreeBlocks_guess()
{
    Reset_guess();
    int index = 0;
    if (field00_guess > 0)
    {
        do
        {
            ResetItem_guess* item = *Slot_guess(index);
            if (item != 0)
            {
                item->Reset_guess();
                free(item);
            }
            *Slot_guess(index) = 0;
            ++index;
        } while (index < field00_guess);
    }
    ((EntryPool_guess*)this)->Reset_guess();
    queue_guess.Clear_guess();
}

// FUNCTION: TITANIUM 0x0040665B
// Hashes the sound's name (+4); 0 if a sound of that name is already in, else inserts it and returns 1.
char Link_guess::AddUniqueByName_guess(void* item)
{
    AudioTriggerSound_guess* entry = *(AudioTriggerSound_guess**)item;
    const char* name = entry->second_guess.Get_guess();
    unsigned int hash = HashStringNoCase_guess((char*)name);
    HashEntry_guess* found = ((HashTable_guess*)this)->FindEntry_guess(hash);
    if (found != 0)
    {
        for (; found != 0; found = FUN_0047c397_guess(found))
        {
            if (found->field00_guess == 0)
            {
                break;
            }
            const char* value = ((KeyTextOwner_guess*)found->field00_guess)->text_guess.FUN_00572300_guess();
            if (__stricmp(name, value) == 0)
            {
                break;
            }
        }
        if (found != 0 && found->field00_guess != 0)
        {
            return 0;
        }
    }
    ((RehashIndex_guess*)this)->InsertEntry_guess((void**)item, hash);
    return 1;
}

// FUNCTION: TITANIUM 0x0040644A
// @early-stop: budget, structural ndiff=24
// Free list first, else the next slot of the current block; a full pool gets a new 3000-entry block.
HashEntry_guess* RehashIndex_guess::AllocEntry_guess()
{
    HashEntry_guess* value;
    if (queue_count_guess != 0)
    {
        int index = queue_count_guess - 1;
        value = queue_chunks_guess[index >> queue_shift_guess][index & queue_mask_guess];
        ((ResetQueue_guess*)&queue_count_guess)->SetValue_guess(index);
    }
    else
    {
        EntryPoolBlock_guess* item = 0;
        if (field00_guess != 0)
        {
            item = (EntryPoolBlock_guess*)*(((ResetOwner_guess*)this)->Slot_guess(count_guess));
        }
        else
        {
            count_guess = -1;
        }
        if (item == 0 || item->field10_guess >= item->count_guess)
        {
            ++count_guess;
            if (count_guess >= field00_guess)
            {
                EntryPoolBlock_guess* fresh = new EntryPoolBlock_guess(3000);
                ((ResetOwner_guess*)this)->FUN_0050319b_guess(field00_guess, &fresh);
                field18_guess += ((EntryPoolBlock_guess*)*
                    (((ResetOwner_guess*)this)->Slot_guess(count_guess)))->count_guess;
            }
            item = (EntryPoolBlock_guess*)*
                (((ResetOwner_guess*)this)->Slot_guess(count_guess));
        }
        value = (HashEntry_guess*)((ElementArray_guess*)item)->Get_guess(item->field10_guess);
        ++item->field10_guess;
    }
    ++field10_guess;
    return value;
}

// Adds `*value` under hash `key`: a fresh pooled entry goes into bucket key % bucket count, and the
// entry count goes up.
// FUNCTION: TITANIUM 0x00406593
void RehashIndex_guess::InsertEntry_guess(void** value, unsigned int key)
{
    HashEntry_guess* item = AllocEntry_guess();
    item->field00_guess = *value;
    item->key_guess = key;
    InsertIntoBucket_guess(key % (unsigned int)bucketCount_guess, item);
    ++field44_guess;
}

// FUNCTION: TITANIUM 0x004065C1
// Unlinks the entry with the same object and hash; 1 when found.
char HashTable_guess::RemoveEntry_guess(HashEntry_guess* item, unsigned int hash)
{
    unsigned int index = hash % (unsigned int)bucketCount_guess;
    RehashIndex_guess* self = (RehashIndex_guess*)this;
    HashEntry_guess* entry = buckets_guess[index];
    HashEntry_guess** link = &buckets_guess[index];
    if (entry != 0)
    {
        do
        {
            if (entry->field00_guess == item->field00_guess && entry->key_guess == hash)
            {
                *link = entry->next_guess;
                ((AppendOwner_guess*)this)->FreeEntry_guess((int)entry);
                --self->field44_guess;
                if (self->buckets_guess[index] == 0)
                {
                    --self->field48_guess;
                }
                return 1;
            }
            link = &entry->next_guess;
            entry = *link;
        } while (entry != 0);
    }
    return 0;
}

struct ItemTableBase_guess
{
    int count_guess; // 0x0
    void* elements_guess; // 0x4
    int capacity_guess; // 0x8
    unsigned char flag_guess; // 0xC

    // EXTERNAL: TITANIUM 0x0050F3F6 ItemTableBase_guess::~ItemTableBase_guess
    ~ItemTableBase_guess();
};

struct ItemTableQueue_guess
{
    char storage_guess[0x1c];

    // EXTERNAL: TITANIUM 0x004B73EE ItemTableQueue_guess::~ItemTableQueue_guess
    ~ItemTableQueue_guess();
};

struct ItemTable_guess : ItemTableBase_guess
{
    int field10_guess; // 0x10
    int field14_guess; // 0x14
    int field18_guess; // 0x18
    int field1c_guess; // 0x1C
    ItemTableQueue_guess queue_guess; // 0x20

    ~ItemTable_guess();
};

// Destructor: empties the pooled name table (0x00406545).
// FUNCTION: TITANIUM 0x00406622
// @early-stop: name-conflict, structural ndiff=2
ItemTable_guess::~ItemTable_guess()
{
    ((ResetOwner_guess*)this)->FreeBlocks_guess();
}

// Removes `item` from the sound table, rehashing its owner's name (case-insensitive) to find the
// bucket.
// FUNCTION: TITANIUM 0x004066D6
void HashTable_guess::Remove_guess(HashEntry_guess* item)
{
    KeyTextOwner_guess* owner = (KeyTextOwner_guess*)item->field00_guess;
    unsigned int hash = HashStringNoCase_guess((char*)owner->text_guess.FUN_00572300_guess());
    RemoveEntry_guess(item, hash);
}

// FUNCTION: TITANIUM 0x004066FD
// The manager passes 100, so the sound table starts with 101 buckets.
PooledHashTable_guess::PooledHashTable_guess(int value) : EntryPool_guess()
{
    RehashIndex_guess* index = (RehashIndex_guess*)this;
    index->current_guess = -1;
    index->buckets_guess = 0;
    index->bucketCount_guess = 0;
    index->field44_guess = 0;
    index->field48_guess = 0;
    index->slots_guess = 0;
    index->Rehash_guess(value);
}

// FUNCTION: TITANIUM 0x004067CC
// Removes and destroys every sound (dtor 0x0040555C).
void HashTable_guess::DeleteAllSounds_guess()
{
    HashEntry_guess* item = FirstEntry_guess();
    HashEntry_guess* next;
    while (item != 0)
    {
        next = NextEntry_guess(item);
        Remove_guess(item);
        ResourceOwner_guess* owner = (ResourceOwner_guess*)item->field00_guess;
        if (owner != 0)
        {
            owner->~ResourceOwner_guess();
            free(owner);
        }
        item = next;
    }
}

// FUNCTION: TITANIUM 0x00406746
// ~PooledHashTable: frees the buckets (+0x3C) and bucket links (+0x50), then the pool.
void PooledHashTableView_guess::DestroyTable_guess()
{
    _free_guess(field3c_guess);
    _free_guess(field50_guess);
    FUN_00406622_guess();
}

// FUNCTION: TITANIUM 0x00406763
// Reached only from EH unwind funclets.
void PooledHashTableView_guess::DestroyPooledTable_guess()
{
    DestroyTable_guess();
}

// FUNCTION: TITANIUM 0x00406768
// `first` is the path, `second` the name; a name already loaded is skipped.
void AudioTriggerManagerSounds_guess::AddSound_guess(int first, AudioTriggerSound_guess* second)
{
    if (entries_guess.FindByName_guess(second) == 0)
    {
        second = new AudioTriggerSound_guess(this, first, second);
        entries_guess.AddUniqueByName_guess(&second);
    }
}

// FUNCTION: TITANIUM 0x0040680C
// Each *.wav in AudioTriggers\<directory>, named by its file name up to the last '.'; a name with no
// '.' ends up empty (as compiled).
void AudioTriggerManagerSounds_guess::LoadSoundFolder_guess(const char* directory)
{
    Str_guess dir;
    FUN_005738b0_guess((char*)&dir, "AudioTriggers\\%s", directory);
    TriggerSearch_guess search(dir.Get_guess(), "*.wav");
    Str_guess value;
    Str_guess path;
    while (search.Find_guess(&value) != 0)
    {
        FUN_005738b0_guess((char*)&path, "AudioTriggers\\%s\\%s", directory, value.Get_guess());
        char name[0x200];
        strncpy(name, value.Get_guess(), 0x1ff);
        unsigned int n = strlen(name);
        while ((n = n - 1) != 0)
        {
            if (name[n] == '.')
            {
                break;
            }
        }
        name[n] = 0;
        AddSound_guess((int)path.Get_guess(), (AudioTriggerSound_guess*)name);
    }
}

// Deletes every trigger, then every loaded sound (0x004067CC).
// FUNCTION: TITANIUM 0x0040699A
void OwnerQueueTable_guess::ClearAll_guess()
{
    queue_guess.DeleteAll_guess();
    table_guess.DeleteAllSounds_guess();
}

// Audio trigger manager destructor: saves the triggers when dirty (0x00405971), then deletes them and
// the loaded sounds.
// FUNCTION: TITANIUM 0x004069AE
AudioTriggerManager_guess::~AudioTriggerManager_guess()
{
    SaveTriggers_guess();
    ((OwnerQueueTable_guess*)this)->ClearAll_guess();
}

// FUNCTION: TITANIUM 0x00406A03
// Saves the old folder's triggers first. The folder's sounds load before "shared", so a folder .wav wins
// over a shared one of the same name.
void AudioTriggerManager_guess::LoadFolder_guess(const char* name)
{
    SaveTriggers_guess();
    ((OwnerQueueTable_guess*)this)->table_guess.DeleteAllSounds_guess();
    if (g_audioDisabled_guess == 0)
    {
        if (name != 0 && *name != 0)
        {
            ((CStringField_guess*)&key_guess)->Set_guess(name);
            ((AudioTriggerManagerSounds_guess*)this)->LoadSoundFolder_guess(name);
        }
        ((AudioTriggerManagerSounds_guess*)this)->LoadSoundFolder_guess("shared");
        LoadTriggers_guess();
    }
}

// EXTERNAL: TITANIUM 0x004AE865 DefaultsService_guess::GetString_guess
struct DefaultsService_guess
{
    void GetString_guess(const char* section, const char* key, const char* defaultValue,
                         char* buffer, unsigned int size, int flags);
};

// FUNCTION: TITANIUM 0x00406A53
// @early-stop: budget, diff ndiff=4
// The folder comes from the "AudioTriggerFolder" setting (section "default", default "default").
AudioTriggerManager_guess::AudioTriggerManager_guess()
    : OwnerFields_guess(), rehash_guess(100), values_guess(), key_guess()
{
    ((AudioTriggerOwner_guess*)this)->ListTriggerFolders_guess();
    char folder_guess[0x80];
    EQ_GLOBAL(DefaultsService_guess*, 0x00988DF0)->GetString_guess(
        "default", "AudioTriggerFolder", "default", folder_guess, 0x80, 1);
    LoadFolder_guess(folder_guess);
}

// FUNCTION: TITANIUM 0x00406AEF
// FreeAudioTriggerManager_guess, called from ~CEverQuest, deletes it.
AudioTriggerManager_guess* GetAudioTriggerManager_guess()
{
    AudioTriggerManager_guess* owner = g_owner406a53_guess;
    if (owner == 0)
    {
        owner = new AudioTriggerManager_guess;
        g_owner406a53_guess = owner;
    }
    return owner;
}

// Deletes the audio trigger manager singleton and clears its pointer; the global teardown (0x00497395)
// calls it.
// FUNCTION: TITANIUM 0x00406B35
void FreeAudioTriggerManager_guess()
{
    delete g_owner406a53_guess;
    g_owner406a53_guess = 0;
}

// Frees each plain chunk and the chunk table; the non-string form of 0x00405BFF.
// FUNCTION: TITANIUM 0x00406E7E
void ArrayClass2_guess::ResetInt_guess()
{
    int index = 0;
    if (count_guess > 0)
    {
        do
        {
            free(items_guess[index]);
            ++index;
        } while (index < count_guess);
    }
    free(items_guess);
    items_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Only the list's vtable slot at +0x130 is called here (slot 76).
struct TriggerListVt_guess
{
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
    virtual void Slot50_guess();
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
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual void Slot76_guess();
};

struct TextSource_guess;

// Only slot 76 (+0x130) is called here; it returns a Str by hidden pointer.
struct StrSource_guess
{
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
    virtual void Slot50_guess();
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
    virtual void Slot63_guess(Str_guess* value);
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual Str_guess Slot76_guess();
};

// Local polymorphic base for the window ctor: 0x005A3900 is CSidlScreenWnd's (CXWnd*, const CXStr&) ctor.
struct TriggerBase_guess
{
    // EXTERNAL: TITANIUM 0x005A3100 ??1TriggerBase_guess@@UAE@XZ
    virtual ~TriggerBase_guess();
    char pad004_guess[0x62];
    unsigned char flags66_guess; // 0x66
    char pad067_guess[0x158 - 0x67];
    int field158_guess; // 0x158
    // EXTERNAL: TITANIUM 0x005A3900 ??0TriggerBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    TriggerBase_guess(CXWnd* parent, const CXStr& screen);
};

// EXTERNAL: TITANIUM 0x0063FBC8 ??_7CAudioTriggersWindow_guess@@6B@
struct CAudioTriggersWindow_guess : TriggerBase_guess
{
    Link_guess* link_guess; // 0x15C selected trigger
    Link_guess* field160_guess; // 0x160 trigger last shown in the editor
    CXWnd* enable164_guess; // 0x164 ATW_Apply
    CXWnd* enable168_guess; // 0x168 ATW_Create
    CXWnd* enable16c_guess; // 0x16C ATW_Delete
    CXWnd* enable170_guess; // 0x170 ATW_Play
    CXWnd* first_guess; // 0x174 ATW_MoveUp
    CXWnd* second_guess; // 0x178 ATW_MoveDown
    StrSource_guess* field17c_guess; // 0x17C ATW_Pattern (edit box)
    TextSource_guess* source180_guess; // 0x180 ATW_Sound (combo, row 0 empty)
    TextSource_guess* source184_guess; // 0x184 ATW_Skin (folder combo)
    CListWnd* list_guess; // 0x188 ATW_List
    int index_guess; // 0x18C selected row, -1 = none

    CAudioTriggersWindow_guess();
    void FillTriggerList_guess();

    void ShowSelectedTrigger_guess(bool force);

    void OnApply_guess();
    void OnCreate_guess();
    void OnDelete_guess();
    void OnListSelect_guess();
    void OnFolderChange_guess();

    void FillSoundList_guess();
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
};

// FUNCTION: TITANIUM 0x00406EB2
// One ATW_List row per trigger: column 0 pattern, column 1 sound (0x0059B360), item data the trigger.
void CAudioTriggersWindow_guess::FillTriggerList_guess()
{
    if (list_guess != 0)
    {
        list_guess->ClearAllSel();
        ((TriggerListVt_guess*)list_guess)->Slot76_guess();
        Link_guess* link = ((LinkOwner_guess*)GetAudioTriggerManager_guess())->list_guess.field00_guess;
        while (link != 0)
        {
            int index = list_guess->AddString(link->text_guess, 0xffffffff, (unsigned int)link, 0);
            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
                index, 1, link->soundName_0010_guess);
            link = link->field04_guess;
        }
        bool enabled = list_guess->ItemsCount > 1;
        first_guess->Enabled = enabled;
        second_guess->Enabled = enabled;
    }
}

// CXStr storage: the length is at +8, so these tests are "text length >= n".
struct StrHeader_guess
{
    char padding00_guess[8];
    int count_guess; // 0x8
};

struct TriggerFlags_guess
{
    char padding_guess[0x5d];
    bool ready_guess; // 0x5D the CXWnd Enabled byte
};

struct TextSource_guess
{
    char padding000_guess[0x11c];
    CListWnd* list_guess; // 0x11C

    // EXTERNAL: TITANIUM 0x0059C3A0 TextSource_guess::GetCurChoice_guess
    int GetCurChoice_guess();

    // EXTERNAL: TITANIUM 0x0059C3B0 TextSource_guess::GetText_guess
    Str_guess GetText_guess();

    // EXTERNAL: TITANIUM 0x0059C360 TextSource_guess::FUN_0059c360_guess
    void FUN_0059c360_guess(int index);

    // EXTERNAL: TITANIUM 0x0059C390 TextSource_guess::GetCount_guess
    int GetCount_guess();
};

struct TriggerRoot_guess
{
    char padding000_guess[0x170];
    TriggerFlags_guess* flags_guess; // 0x170
    char padding174_guess[0x180 - 0x174];
    TextSource_guess* source_guess; // 0x180

    // EXTERNAL: TITANIUM 0x00406D4D TriggerRoot_guess::UpdateButtons_guess
    void UpdateButtons_guess();

    void OnPlay_guess();
};

// FUNCTION: TITANIUM 0x00406B57
// @early-stop: budget, structural ndiff=178
// Puts the selected trigger's pattern in ATW_Pattern (slot 63, SetWindowText), selects its sound in ATW_Sound
// (searching back towards the empty row 0) and its ATW_List row. With none selected it clears both and
// disables Apply, Delete, MoveUp and MoveDown. `force` re-shows the trigger already shown.
void CAudioTriggersWindow_guess::ShowSelectedTrigger_guess(bool force)
{
    if (list_guess == 0 || field17c_guess == 0 || source180_guess == 0)
    {
        return;
    }
    Link_guess* item = link_guess;
    if (item == 0)
    {
        {
            CXStr text(EQ_ARRAY(char, 0x0063F53F));
            field17c_guess->Slot63_guess((Str_guess*)&text);
        }
        source180_guess->FUN_0059c360_guess(0);
        list_guess->ClearAllSel();
        enable164_guess->Enabled = 0;
        enable16c_guess->Enabled = 0;
        first_guess->Enabled = 0;
        second_guess->Enabled = 0;
        return;
    }
    if (force || item != field160_guess)
    {
        field160_guess = item;
        field17c_guess->Slot63_guess((Str_guess*)&item->text_guess);
        int count = source180_guess->GetCount_guess();
        CListWnd* textList = source180_guess->list_guess;
        bool keepGoing;
        do
        {
            keepGoing = false;
            if (count > 0)
            {
                CXStr text = textList->GetItemText(count, 0);
                keepGoing = true;
                if (((SearchPredicate_guess*)&text)->FUN_00573b10_guess((int)&item->soundName_0010_guess, 1) == 0)
                {
                    keepGoing = false;
                }
            }
            if (!keepGoing)
            {
                break;
            }
            --count;
        } while (true);
        source180_guess->FUN_0059c360_guess(count);
        list_guess->ClearAllSel();
    }
    int count = list_guess->ItemsCount;
    for (int index = 0; index < count; ++index)
    {
        if (list_guess->GetItemData(index) == (unsigned int)item)
        {
            list_guess->SetCurSel(index);
            return;
        }
    }
    enable164_guess->Enabled = 1;
    enable16c_guess->Enabled = 1;
    first_guess->Enabled = count > 1;
    second_guess->Enabled = count > 1;
}

// FUNCTION: TITANIUM 0x00406D4D
// @early-stop: budget, diff ndiff=34
// Typing a pattern that an existing trigger has selects that trigger. Create needs a 2+ character pattern,
// a sound and no such trigger; Delete needs the trigger; Play needs a sound.
void TriggerRoot_guess::UpdateButtons_guess()
{
    CAudioTriggersWindow_guess* window = (CAudioTriggersWindow_guess*)this;
    if (window->field17c_guess != 0 && window->enable168_guess != 0 &&
        window->enable164_guess != 0 && window->enable16c_guess != 0 &&
        window->first_guess != 0 && window->second_guess != 0)
    {
        Str_guess key = window->field17c_guess->Slot76_guess();
        Str_guess node = window->source180_guess->GetText_guess();
        Link_guess* found = (Link_guess*)((SearchList_guess*)GetAudioTriggerManager_guess())->FindTriggerByPattern_guess((int)&key);
        window->link_guess = found;
        int count = node.field00_guess != 0 ? ((StrHeader_guess*)node.field00_guess)->count_guess : 0;
        int keyCount = key.field00_guess != 0 ? ((StrHeader_guess*)key.field00_guess)->count_guess : 0;
        if (keyCount < 2 || count < 1)
        {
            window->enable168_guess->Enabled = 0;
            window->enable164_guess->Enabled = 0;
        }
        else
        {
            window->enable168_guess->Enabled = found == 0;
        }
        window->enable170_guess->Enabled = count > 0;
        window->enable16c_guess->Enabled = found != 0;
    }
}

struct Flag_call_guess
{
    // EXTERNAL: TITANIUM 0x004055CA Flag_call_guess::SetDirty_guess
    void SetDirty_guess();
};

// FUNCTION: TITANIUM 0x00406F2F
// ATW_Apply: the pattern text and the ATW_Sound choice go into the selected trigger and its row.
void CAudioTriggersWindow_guess::OnApply_guess()
{
    int count = list_guess->ItemsCount;
    if (index_guess < count)
    {
        link_guess = (Link_guess*)list_guess->GetItemData(index_guess);
        if (link_guess != 0 && index_guess >= 0)
        {
            TextSource_guess* source = source180_guess;
            CListWnd* list = source->list_guess;
            KeyTextOwner_guess* item = (KeyTextOwner_guess*)list->GetItemData(source->GetCurChoice_guess());
            link_guess->soundName_0010_guess = item->text_guess.FUN_00572300_guess();
            link_guess->text_guess = field17c_guess->Slot76_guess().Get_guess();
            ((CListWnd*)list_guess)->SetItemText(index_guess, 0, link_guess->text_guess);
            ((CListWnd*)list_guess)->SetItemText(index_guess, 1, link_guess->soundName_0010_guess);
            ((Flag_call_guess*)GetAudioTriggerManager_guess())->SetDirty_guess();
            ((TriggerRoot_guess*)this)->UpdateButtons_guess();
        }
    }
}

// FUNCTION: TITANIUM 0x00407048
// ATW_Create: same 2+ character pattern and sound rule as UpdateButtons.
void CAudioTriggersWindow_guess::OnCreate_guess()
{
    Str_guess list_text = field17c_guess->Slot76_guess();
    Str_guess source_text = source180_guess->GetText_guess();
    int count = list_text.field00_guess != 0 ? ((StrHeader_guess*)list_text.field00_guess)->count_guess : 0;
    if (count > 1)
    {
        int sourceCount = source_text.field00_guess != 0 ? ((StrHeader_guess*)source_text.field00_guess)->count_guess : 0;
        if (sourceCount > 0)
        {
            GetAudioTriggerManager_guess()->AddTrigger_guess(list_text.Get_guess(), source_text.Get_guess());
            link_guess = 0;
            FillTriggerList_guess();
            ShowSelectedTrigger_guess(0);
            ((TriggerRoot_guess*)this)->UpdateButtons_guess();
        }
    }
}

// FUNCTION: TITANIUM 0x0040714C
// ATW_Play, or a choice in ATW_Sound: plays that sound. `this` is the window; +0x170 is ATW_Play, whose
// Enabled byte follows whether a sound is chosen.
void TriggerRoot_guess::OnPlay_guess()
{
    if (source_guess != 0)
    {
        // Text and item count from the source.
        Str_guess text = source_guess->GetText_guess();
        int count = text.field00_guess != 0 ? ((StrHeader_guess*)text.field00_guess)->count_guess : 0;
        bool hasItems = count > 0;
        flags_guess->ready_guess = hasItems;
        UpdateButtons_guess();
        if (hasItems)
        {
            ((LookupOwner_guess*)GetAudioTriggerManager_guess())->PlaySoundByName_guess((void*)text.Get_guess());
        }
    }
}

// ATW_Delete: removes the selected trigger (+0x15C) from the audio trigger manager, which frees it and
// marks the list dirty for saving, then rebuilds ATW_List and empties the editor (nothing selected).
// FUNCTION: TITANIUM 0x00407119
void CAudioTriggersWindow_guess::OnDelete_guess()
{
    if (link_guess != 0)
    {
        ((LinkOwner_guess*)GetAudioTriggerManager_guess())->DeleteTrigger_guess(link_guess);
        link_guess = 0;
        FillTriggerList_guess();
        ShowSelectedTrigger_guess(0);
    }
}

// FUNCTION: TITANIUM 0x004071D1
// ATW_List: the clicked row becomes the selected trigger; the buttons follow.
void CAudioTriggersWindow_guess::OnListSelect_guess()
{
    if (list_guess != 0)
    {
        int index = list_guess->GetCurSel();
        index_guess = index;
        if (index < 0 || index >= list_guess->ItemsCount)
        {
            link_guess = 0;
        }
        else
        {
            link_guess = (Link_guess*)list_guess->GetItemData(index);
        }
        ShowSelectedTrigger_guess(1);
        bool enabled = list_guess->ItemsCount > 1;
        first_guess->Enabled = enabled;
        second_guess->Enabled = enabled;
        bool hasLink = link_guess != 0;
        enable16c_guess->Enabled = hasLink;
        enable168_guess->Enabled = !hasLink;
        enable164_guess->Enabled = hasLink;
        enable170_guess->Enabled = hasLink;
    }
}

// Frees the plain pages and empties the array (0x00406E7E).
// FUNCTION: TITANIUM 0x00407274
void ArrayClass2_guess::DestroyInt_guess()
{
    ResetInt_guess();
}

// FUNCTION: TITANIUM 0x00407279
// The Mac client's ArrayClass2<int>::Assure.
void ArrayClass2_guess::Assure_guess(int count)
{
    if (enabled_guess != 0 && count > 0)
    {
        count = FUN_0051da09_guess(count);
        if (count > count_guess)
        {
            void** newChunks = (void**)operator new(count << 2);
            if (newChunks == 0)
            {
                enabled_guess = 0;
            }
            else
            {
                for (int index = 0; index < count_guess; ++index)
                {
                    newChunks[index] = items_guess[index];
                }
                for (int index = count_guess; index < count; ++index)
                {
                    newChunks[index] = operator new(chunkSize_guess << 2);
                    if (newChunks[index] == 0)
                    {
                        enabled_guess = 0;
                        break;
                    }
                }
                if (enabled_guess != 0)
                {
                    free(items_guess);
                    items_guess = newChunks;
                    count_guess = count;
                }
            }
        }
        if (enabled_guess == 0)
        {
            ResetInt_guess();
            ((ThrowOwner_guess*)this)->ThrowSelf_guess();
        }
    }
}

// FUNCTION: TITANIUM 0x00407328
// Shifts the tail up one; FillSoundList's insertion sort uses it.
void ArrayClass2_guess::InsertElement_guess(int index, int* value)
{
    if (index < 0)
    {
        return;
    }
    if (index >= field00_guess)
    {
        SetElementIdxInt_guess(index, value);
        return;
    }
    Assure_guess(field00_guess + 1);
    if (enabled_guess != 0)
    {
        for (int source = field00_guess; source > index; --source)
        {
            At_guess(source) = At_guess(source - 1);
        }
        ((int*)items_guess[index >> shift_guess])[index & mask_guess] = *value;
        ++field00_guess;
    }
}

// Stores an int at `index`, growing the array to index + 1 first; negative indexes are ignored.
// FUNCTION: TITANIUM 0x004073CB
void ArrayClass2_guess::SetElementIdxInt_guess(int index, int* value)
{
    if (index >= 0)
    {
        if (index >= field00_guess)
        {
            Assure_guess(index + 1);
            if (enabled_guess != 0)
            {
                field00_guess = index + 1;
            }
        }
        if (enabled_guess != 0)
        {
            ((int*)items_guess[index >> shift_guess])[index & mask_guess] = *value;
        }
    }
}

struct SortEntry_guess
{
    int field00_guess; // 0x0
    KeyText_guess text_guess; // 0x4
};

struct SortedPointers_guess
{
    int field00_guess; // 0x0
    int chunkSize_guess; // 0x4
    unsigned int mask_guess; // 0x8
    unsigned int shift_guess; // 0xC
    void** items_guess; // 0x10
    int count_guess; // 0x14
    unsigned char enabled_guess; // 0x18

    // EXTERNAL: TITANIUM 0x0047C3AF SortedPointers_guess::Initialize_guess
    void Initialize_guess(int size);

    ~SortedPointers_guess()
    {
        ((ArrayClass2_guess*)this)->ResetInt_guess();
    }
};

#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// FUNCTION: TITANIUM 0x00407414
// @early-stop: budget, structural ndiff=62
// ATW_Sound: an empty row 0, then every loaded sound sorted by name (insertion sort into a local
// ArrayClass2), item data = the sound. Incrementing row before SetItemData skips that empty row.
void CAudioTriggersWindow_guess::FillSoundList_guess()
{
    if (source180_guess != 0)
    {
        ((ResultList_guess*)source180_guess)->Reset_guess();
        HashTable_guess* table = &((LookupOwner_guess*)GetAudioTriggerManager_guess())->table_guess;
        HashEntry_guess* h = table->FirstEntry_guess();
        CListWnd* list = source180_guess->list_guess;
        {
            Str_guess key(g_emptyString_guess);
            ((ResultList_guess*)source180_guess)->Add_guess((SearchText_guess*)&key);
        }
        SortedPointers_guess sorted;
        sorted.Initialize_guess(0x20);
        while (h != 0 && h->field00_guess != 0)
        {
            void* obj = h->field00_guess;
            int index = 0;
            int count = sorted.field00_guess - 1;
            if (count > 0)
            {
                do
                {
                    SortEntry_guess* item = (SortEntry_guess*)((int*)sorted.items_guess[index >> sorted.shift_guess])[index & sorted.mask_guess];
                    if (((SearchText_guess*)&item->text_guess)->Compare_guess(&((SortEntry_guess*)obj)->text_guess, 0) >= 0)
                    {
                        break;
                    }
                    ++index;
                } while (index < count);
            }
            ((ArrayClass2_guess*)&sorted)->InsertElement_guess(index, (int*)&obj);
            h = table->NextEntry_guess(h);
        }
        int total = sorted.field00_guess;
        int row = 0;
        if (total > 0)
        {
            do
            {
                SortEntry_guess* item = (SortEntry_guess*)((int*)sorted.items_guess[row >> sorted.shift_guess])[row & sorted.mask_guess];
                ((ResultList_guess*)source180_guess)->Add_guess((SearchText_guess*)&item->text_guess);
                ++row;
                list->SetItemData(row, (unsigned int)item);
            } while (row < total);
        }
    }
}

// FUNCTION: TITANIUM 0x0040756E
// ATW_Skin (window +0x184): every folder, with the current one (+0x7C) selected.
void ResultOwner_guess::FillFolderList_guess()
{
    int index = 0;
    if (list_guess != 0)
    {
        list_guess->Reset_guess();
        ArrayClass2_guess* values = &GetAudioTriggerManager_guess()->values_guess;
        int count = values->field00_guess;
        KeyText_guess* key = &GetAudioTriggerManager_guess()->key_guess;
        if (count > 0)
        {
            do
            {
                list_guess->Add_guess((SearchText_guess*)values->items_guess[index >> values->shift_guess] + (index & values->mask_guess));
                if (((SearchText_guess*)values->items_guess[index >> values->shift_guess] + (index & values->mask_guess))->Compare_guess(key, 1) == 0)
                {
                    list_guess->Finish_guess(index);
                }
                ++index;
            } while (index < count);
        }
    }
}

// FUNCTION: TITANIUM 0x0040760B
// ATW_Skin: loads the chosen folder, refills both lists, clears the editor and disables every button.
void CAudioTriggersWindow_guess::OnFolderChange_guess()
{
    GetAudioTriggerManager_guess()->LoadFolder_guess(source184_guess->GetText_guess().Get_guess());
    FillSoundList_guess();
    FillTriggerList_guess();
    link_guess = 0;
    {
        Str_guess text(EQ_ARRAY(char, 0x0063F53F));
        field17c_guess->Slot63_guess(&text);
    }
    source180_guess->FUN_0059c360_guess(0);
    ((TriggerFlags_guess*)enable164_guess)->ready_guess = false;
    ((TriggerFlags_guess*)enable16c_guess)->ready_guess = false;
    ((TriggerFlags_guess*)enable170_guess)->ready_guess = false;
    ((TriggerFlags_guess*)first_guess)->ready_guess = false;
    ((TriggerFlags_guess*)second_guess)->ready_guess = false;
    ((TriggerFlags_guess*)enable168_guess)->ready_guess = false;
}

// Appends `*value` to the end of the paged array.
// FUNCTION: TITANIUM 0x004076F8
void ArrayClass2_guess::Append_guess(int* value)
{
    SetElementIdxInt_guess(field00_guess, value);
}

// FUNCTION: TITANIUM 0x00407706
// Reloads the triggers from the ini, then fills the sound, folder and trigger lists.
CAudioTriggersWindow_guess::CAudioTriggersWindow_guess()
    : TriggerBase_guess(0, "AudioTriggersWindow")
{
    index_guess = -1;
    flags66_guess |= 1;
    link_guess = 0;
    field160_guess = 0;
    field158_guess = 0x46;
    ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
    enable164_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_Apply");
    enable168_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_Create");
    enable16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_Delete");
    enable170_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_Play");
    first_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_MoveUp");
    second_guess = ((CSidlScreenWnd*)this)->GetChildItem("ATW_MoveDown");
    field17c_guess = (StrSource_guess*)((CSidlScreenWnd*)this)->GetChildItem("ATW_Pattern");
    source180_guess = (TextSource_guess*)((CSidlScreenWnd*)this)->GetChildItem("ATW_Sound");
    source184_guess = (TextSource_guess*)((CSidlScreenWnd*)this)->GetChildItem("ATW_Skin");
    list_guess = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("ATW_List");
    GetAudioTriggerManager_guess()->LoadTriggers_guess();
    FillSoundList_guess();
    ((ResultOwner_guess*)this)->FillFolderList_guess();
    FillTriggerList_guess();
    ((TriggerRoot_guess*)this)->UpdateButtons_guess();
}

struct RefCount_guess
{
    int count_guess; // 0x0
};

struct Provider_guess
{
    // EXTERNAL: TITANIUM 0x005A3C60 Provider_guess::Get_guess
    int Get_guess();
};

struct StrSlot_guess
{
    int field00_guess;

    // EXTERNAL: TITANIUM 0x00571D00 StrSlot_guess::Release_guess
    void Release_guess(int value);
};

struct Pool407_guess
{
    // EXTERNAL: TITANIUM 0x00597ED0 Pool407_guess::Item_guess
    int Item_guess(int index);

    // EXTERNAL: TITANIUM 0x00597F10 Pool407_guess::Get_guess
    Str_guess Get_guess(int index, int flag);

    // EXTERNAL: TITANIUM 0x00597F10 Pool407_guess::Into_guess
    Str_guess* Into_guess(Str_guess* out, int index, int flag);

    // EXTERNAL: TITANIUM 0x00597F10 Pool407_guess::Into_slot_guess
    StrSlot_guess* Into_slot_guess(StrSlot_guess* out, int index, int flag);

    // EXTERNAL: TITANIUM 0x0059B360 Pool407_guess::Set_guess
    void Set_guess(int index, int flag, Str_guess* value);

    // EXTERNAL: TITANIUM 0x0059B360 Pool407_guess::Set_slot_guess
    void Set_slot_guess(int index, int flag, StrSlot_guess* value);

    // EXTERNAL: TITANIUM 0x00598620 Pool407_guess::Bind_guess
    void Bind_guess(int index, int value);

    // EXTERNAL: TITANIUM 0x00598580 Pool407_guess::Flush_guess
    void Flush_guess();

    // EXTERNAL: TITANIUM 0x0059B280 Pool407_guess::Adopt_guess
    void Adopt_guess(ArrayClass2_guess* scratch);
};

// Width and height pair returned by value (cx, cy).
struct CXSize_guess
{
    int cx; // 0x0
    int cy; // 0x4

    CXSize_guess(int width, int height) : cx(width), cy(height)
    {
    }
};

// The same window through its CXWnd fields: rect +0x3C..+0x48, minimized +0x5E, draw template +0x68,
// tooltip CXStr +0x78. GetTooltip, GetUntileSize, SetDrawTemplate and OnMinimizeBox are CXWnd vtable slots
// 53, 59, 62 and 38 that every window shares; 59 and 62 are named from MQ2's member order, not proven.
struct CAudioTriggersWindowView_guess
{
    char padding00_guess[0x3c];
    int field3c_guess; // 0x3c
    int field40_guess; // 0x40
    int field44_guess; // 0x44
    int field48_guess; // 0x48
    char padding4c_guess[0x5e - 0x4c];
    unsigned char flag5e_guess; // 0x5e
    char padding5f_guess[0x68 - 0x5f];
    Provider_guess* provider_guess; // 0x68
    int first_guess; // 0x6c
    int second_guess; // 0x70
    char padding74_guess[4];
    RefCount_guess* shared_guess; // 0x78
    char padding7c_guess[0x15c - 0x7c];
    Link_guess* link_guess; // 0x15c
    char padding160_guess[0x188 - 0x160];
    Pool407_guess* field188_guess; // 0x188
    int index_guess; // 0x18c

    void GetTooltip_guess(RefCount_guess** output);
    CXSize_guess GetUntileSize_guess();
    void SetDrawTemplate_guess(Provider_guess* provider);

    // EXTERNAL: TITANIUM 0x0059FDC0 CAudioTriggersWindowView_guess::FUN_0059fdc0_guess
    void FUN_0059fdc0_guess(bool value);
    void OnMinimizeBox_guess();

    void OnMoveUp_guess();
    void OnMoveDown_guess();

    void SwapListRow_guess(int delta);
};

// FUNCTION: TITANIUM 0x004079DD
// @early-stop: budget, structural ndiff=18
// Hands out the tooltip CXStr with its reference count raised.
void CAudioTriggersWindowView_guess::GetTooltip_guess(RefCount_guess** output)
{
    RefCount_guess* shared_local_guess = shared_guess;
    if (shared_local_guess != 0)
    {
        ++shared_local_guess->count_guess;
    }
    *output = shared_guess;
}

// Returns the width and height of the rect at +0x3C (right - left, bottom - top).
// FUNCTION: TITANIUM 0x00407A0C
CXSize_guess CAudioTriggersWindowView_guess::GetUntileSize_guess()
{
    return CXSize_guess(field44_guess - field3c_guess, field48_guess - field40_guess);
}

// Stores the draw template at +0x68; when the first image (+0x6C) is unset, gets both images (+0x6C,
// +0x70) through 0x005A3C60, which asks the global at 0x0099E360 (virtual slot 13), not the
// template. The timer window shares this code.
// FUNCTION: TITANIUM 0x00407A38
void CAudioTriggersWindowView_guess::SetDrawTemplate_guess(Provider_guess* provider)
{
    provider_guess = provider;
    if (first_guess == 0)
    {
        first_guess = provider_guess->Get_guess();
        second_guess = provider_guess->Get_guess();
    }
}

// Toggles the minimized state: passes the inverse of the flag at +0x5E to 0x0059FDC0.
// FUNCTION: TITANIUM 0x00407A6B
void CAudioTriggersWindowView_guess::OnMinimizeBox_guess()
{
    FUN_0059fdc0_guess(flag5e_guess == 0);
}

// ATW_MoveUp: when the selected trigger has one before it (node +0), moves it one place up in the
// manager's list (marked dirty) and swaps its ATW_List row with the row above (0x00407A79).
// FUNCTION: TITANIUM 0x00407C30
void CAudioTriggersWindowView_guess::OnMoveUp_guess()
{
    Link_guess* link = link_guess;
    if (link != 0 && link->field00_guess != 0 && field188_guess != 0)
    {
        ((LinkOwner_guess*)GetAudioTriggerManager_guess())->MoveTriggerUp_guess(link);
        SwapListRow_guess(-1);
    }
}

// ATW_MoveDown: when the selected trigger has one after it (node +4), moves it one place down in the
// manager's list (marked dirty) and swaps its ATW_List row with the row below (0x00407A79).
// FUNCTION: TITANIUM 0x00407C63
void CAudioTriggersWindowView_guess::OnMoveDown_guess()
{
    Link_guess* link = link_guess;
    if (link != 0 && link->field04_guess != 0 && field188_guess != 0)
    {
        ((LinkOwner_guess*)GetAudioTriggerManager_guess())->MoveTriggerDown_guess(link);
        SwapListRow_guess(1);
    }
}

struct Scratch407_guess
{
    int field00_guess;
    int chunkSize_guess;
    unsigned int mask_guess;
    unsigned int shift_guess;
    void** items_guess;
    int count_guess;
    int enabled_guess;
    int tail_guess;

    // EXTERNAL: TITANIUM 0x0047C3AF Scratch407_guess::Init_guess
    void Init_guess(int size);

    Scratch407_guess()
    {
        Init_guess(0x20);
    }

    ~Scratch407_guess()
    {
        ((ArrayClass2_guess*)this)->ResetInt_guess();
    }
};

// FUNCTION: TITANIUM 0x00407A79
// @early-stop: budget, structural ndiff=38
// Swaps both text columns and the item data of rows index and index+delta, then selects the moved row.
void CAudioTriggersWindowView_guess::SwapListRow_guess(int delta)
{
    int first = field188_guess->Item_guess(index_guess);
    Str_guess a = field188_guess->Get_guess(index_guess, 0);
    Str_guess b = field188_guess->Get_guess(index_guess, 1);
    StrSlot_guess value;
    StrSlot_guess* result = field188_guess->Into_slot_guess(&value, index_guess + delta, 0);
    field188_guess->Set_slot_guess(index_guess, 0, result);
    if (value.field00_guess != 0)
    {
        value.Release_guess(value.field00_guess);
    }
    result = field188_guess->Into_slot_guess(&value, index_guess + delta, 1);
    field188_guess->Set_slot_guess(index_guess, 1, result);
    if (value.field00_guess != 0)
    {
        value.Release_guess(value.field00_guess);
    }
    value.field00_guess = 0;
    field188_guess->Bind_guess(index_guess,
                               field188_guess->Item_guess(index_guess + delta));
    field188_guess->Set_guess(index_guess + delta, 0, &a);
    field188_guess->Set_guess(index_guess + delta, 1, &b);
    field188_guess->Bind_guess(index_guess + delta, first);
    index_guess += delta;
    Scratch407_guess scratch;
    ((ArrayClass2_guess*)&scratch)->SetElementIdxInt_guess(scratch.field00_guess,
                                                              &index_guess);
    field188_guess->Flush_guess();
    field188_guess->Adopt_guess((ArrayClass2_guess*)&scratch);
}

// FUNCTION: TITANIUM 0x00407C97
// Message 1: a child was clicked or chosen; 14: the ATW_Pattern text changed.
int CAudioTriggersWindow_guess::WndNotification(CXWnd* sender, unsigned int message, void* data)
{
    switch (message)
    {
    case 1:
        if (sender == enable164_guess)
        {
            OnApply_guess();
        }
        else if (sender == enable168_guess)
        {
            OnCreate_guess();
        }
        else if (sender == enable16c_guess)
        {
            OnDelete_guess();
        }
        else if (sender == enable170_guess)
        {
            ((TriggerRoot_guess*)this)->OnPlay_guess();
        }
        else if (sender == first_guess)
        {
            ((CAudioTriggersWindowView_guess*)this)->OnMoveUp_guess();
        }
        else if (sender == second_guess)
        {
            ((CAudioTriggersWindowView_guess*)this)->OnMoveDown_guess();
        }
        else if (sender == (CXWnd*)source180_guess)
        {
            ((TriggerRoot_guess*)this)->OnPlay_guess();
        }
        else if (sender == list_guess)
        {
            OnListSelect_guess();
        }
        else if (sender == (CXWnd*)source184_guess)
        {
            OnFolderChange_guess();
        }
        break;
    case 14:
        if (sender == (CXWnd*)field17c_guess)
        {
            ((TriggerRoot_guess*)this)->UpdateButtons_guess();
        }
        break;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

