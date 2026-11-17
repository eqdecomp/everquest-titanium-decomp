// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 2: a hint from compare/tumap.py.
// Shroud (monster mission) progression data and the adventure-point purchase prompts, plus a large share of
// VC7.1 standard library code instantiated here (list, string, stringstream and a memory streambuf). The
// progression lists arrive as text: "PROGRESSION" records with "BRANCH" and "TEMPLATE" sub-records, read
// token by token from a stringstream.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"

#include "titanium/core_decls.h"
// EXTERNAL: TITANIUM 0x004912B1 EQSendMessage
void __cdecl EQSendMessage(void* param_1, int param_2, int param_3, int param_4, int param_5);

struct IosBase_guess {
    int* vtable;
    IosBase_guess* Delete_guess(unsigned int flags);
    // EXTERNAL: TITANIUM 0x00623D8D IosBase_guess::Destroy_guess
    void Destroy_guess();
    void DestroyWrapper_guess();
};

struct IosBaseCall_guess {
    // EXTERNAL: TITANIUM 0x00401C6C IosBaseCall_guess::DestroyWrapper_external_guess
    void DestroyWrapper_external_guess();
};

struct CleanupPrefix402EAE_guess {
    int padding_guess[0x14];
};

struct CleanupOwner402EAE_guess;

struct CleanupSubobject402EAE_guess : IosBase_guess {
    void* Delete_guess(unsigned char flags_guess);
};

struct CleanupOwner402EAE_guess : CleanupPrefix402EAE_guess,
    CleanupSubobject402EAE_guess {
    void Destroy_guess();
};

struct CtypeFacet_guess {
    int field00_guess;
    int field04_guess;
    int ctypevec_guess;
    int ToLower_guess(unsigned char value_guess);
    int ToUpper_guess(unsigned char value_guess);
};

// EXTERNAL: TITANIUM 0x006731A4 ??_7FacetDelete_guess@@6B@
struct FacetDelete_guess {
    virtual ~FacetDelete_guess();
    FacetDelete_guess* Delete_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x006237E3 __Tolower_guess
int __cdecl __Tolower_guess(int value_guess, void* ctypevec_guess);

// EXTERNAL: TITANIUM 0x0062417D __Toupper_guess
int __cdecl __Toupper_guess(int value_guess, void* ctypevec_guess);

// EXTERNAL: TITANIUM 0x00403A5F FUN_00403A5F_guess
void __fastcall FUN_00403A5F_guess(int* param_1);

// EXTERNAL: TITANIUM 0x00425232 FUN_00425232_guess
void __fastcall FUN_00425232_guess(int* param_1);

// EXTERNAL: TITANIUM 0x00403B60 FUN_00403B60_guess
void __fastcall FUN_00403B60_guess(void* param_1);

// EXTERNAL: TITANIUM 0x00404581 FUN_00404581_guess
void __cdecl FUN_00404581_guess();

// EXTERNAL: TITANIUM 0x00404A04 FUN_00404A04_guess
void __fastcall FUN_00404A04_guess(void* param_1);

// EXTERNAL: TITANIUM 0x00403026 FUN_00403026_guess
void __fastcall FUN_00403026_guess(void* param_1);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060DA00 memcpy
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int count);

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct ListString_guess;

struct ExceptionBase_guess {
    // EXTERNAL: TITANIUM 0x00403026 ExceptionBase_guess::~ExceptionBase_guess
    virtual ~ExceptionBase_guess();
    // EXTERNAL: TITANIUM 0x0040354C ExceptionBase_guess::ExceptionBase_guess
    ExceptionBase_guess(const ListString_guess& text_guess);
    // EXTERNAL: TITANIUM 0x004036B8 ??0ExceptionBase_guess@@QAE@PBD@Z
    ExceptionBase_guess(const char* message_guess);
    int field04_guess;
    int field08_guess;
    char message_guess[0x1c];
};

// EXTERNAL: TITANIUM 0x0067322C ??_7ExceptionDerived_guess@@6B@
struct ExceptionDerived_guess : ExceptionBase_guess {
    ExceptionDerived_guess(const ListString_guess& text_guess)
        : ExceptionBase_guess(text_guess) {}
    ExceptionDerived_guess(const char* message_guess);
    ExceptionDerived_guess* Delete_guess(unsigned int flags);
    virtual ~ExceptionDerived_guess();
};

struct StringManager_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringManager_guess::getString
    char* getString(unsigned int, int, int, int);
};

struct MessageManager_guess {
    // EXTERNAL: TITANIUM 0x004982C6 MessageManager_guess::dsp_chat
    void dsp_chat(char*);
};

struct StringLabels_guess {
    int padding00_guess[3];
    char* label0c_guess;
    char* label10_guess;
    char* label14_guess;
    char* label18_guess;
    char* label1c_guess;
    char* label20_guess;
    char* label24_guess;
    char* label28_guess;
    char* label2c_guess;
    char* label30_guess;
    char* label34_guess;
    char* label38_guess;
    void Initialize_guess();
};

struct ErrorDisplay_guess {
    // EXTERNAL: TITANIUM 0x00548460 ErrorDisplay_guess::Activate
    void Activate(unsigned int address, int type, char* message,
                    int zero4, int duration, int zero6, int zero7);
};

#define g_errorDisplay_guess EQ_GLOBAL(ErrorDisplay_guess*, 0x00991E44)
#define g_errorSource_guess EQ_GLOBAL(unsigned int, 0x00988DF0)

struct SpellCalc_guess {
    // EXTERNAL: TITANIUM 0x00439CA3 SpellCalc_guess::PlayerSimpleDistance_guess
    float PlayerSimpleDistance_guess(int index_guess, int arg_guess, float scale_guess);
};

#define g_spellCalc_guess EQ_GLOBAL(SpellCalc_guess*, 0x00905D24)

struct ValueHandler_guess {
    char padding00_guess[0xc];
    int index_guess;
    void StartShroudTransform_guess(int value);
    bool IsWithinRange_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x00401B28 GetSpawnByID_call_guess
unsigned int __cdecl GetSpawnByID_call_guess(unsigned int index);

struct Initializer_guess {
    int* vtable_guess;
    int field04_guess;
    int field08_guess;
    char field0c_guess[0x18];
    char field24_guess[0x18];
    Initializer_guess();
};

extern "C" void* __cdecl memset(void* destination, int value, unsigned int count);

// EXTERNAL: TITANIUM 0x0060D682 free_guess
void __cdecl free_guess(void* memory);

struct DeleteElement_guess;
typedef void (DeleteElement_guess::*DeleteElementDtor_guess)();

struct SmallDeleteElement_guess;
typedef void (SmallDeleteElement_guess::*SmallDeleteElementDtor_guess)();

// EXTERNAL: TITANIUM 0x0060D6E5 EHVectorDestructorIterator_guess
void __stdcall EHVectorDestructorIterator_guess(void* first, unsigned int size,
    int count, DeleteElementDtor_guess destructor);

// EXTERNAL: TITANIUM 0x0060D6E5 EHVectorDestructorIteratorSmall_guess
void __stdcall EHVectorDestructorIteratorSmall_guess(void* first, unsigned int size,
    int count, SmallDeleteElementDtor_guess destructor);

struct DeleteArrayHeader_guess {
    int count_guess;
};

struct DeleteElement_guess {
    int field00_guess;
    int field04_guess;
    // EXTERNAL: TITANIUM 0x0044830F DeleteElement_guess::Destroy_guess
    void Destroy_guess();
    DeleteElement_guess* Delete_guess(unsigned char flags_guess);
};

struct SmallDeleteSubobject_guess {
    int field00_guess;
    // EXTERNAL: TITANIUM 0x004482FB SmallDeleteSubobject_guess::Destroy_guess
    void Destroy_guess();
};

struct SmallDeleteElement_guess {
    SmallDeleteSubobject_guess first_guess;
    SmallDeleteSubobject_guess second_guess;
    // EXTERNAL: TITANIUM 0x00401710 SmallDeleteElement_guess::Destroy_guess
    void Destroy_guess();
    SmallDeleteElement_guess* Delete_guess(unsigned char flags_guess);
};

struct PilotItem_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x004482FB PilotItem_guess::~PilotItem_guess
    ~PilotItem_guess();
};

struct PilotContainer_guess : PilotItem_guess {
    PilotItem_guess child_guess;
    ~PilotContainer_guess();
};

struct PointerList_guess {
    int field00_guess;
    char padding04_guess[0x0c];
    DeleteElement_guess** items_guess;
    int count_guess;
    void Cleanup_guess();
    void CleanupThunk_guess();
    ~PointerList_guess() { Cleanup_guess(); }
};

struct OwnerBase_guess {
    int field00_guess;
    ~OwnerBase_guess() {
        ((SmallDeleteSubobject_guess*)this)->Destroy_guess();
    }
};

struct ArrayMember_guess {
    int field00_guess;
    // EXTERNAL: TITANIUM 0x00591770 ArrayMember_guess::~ArrayMember_guess
    ~ArrayMember_guess();
};

struct Owner_guess : OwnerBase_guess {
    PointerList_guess list_guess;
    char padding1c_guess[4];
    ArrayMember_guess array_guess;
    ~Owner_guess();
};

struct SmallPointerList_guess {
    int field00_guess;
    char padding04_guess[0x0c];
    SmallDeleteElement_guess** items_guess;
    int count_guess;
    void Cleanup_guess();
    void CleanupThunk_guess();
    ~SmallPointerList_guess() { Cleanup_guess(); }
};

struct ListElement_guess {
    // EXTERNAL: TITANIUM 0x00401968 ListElement_guess::Destroy_guess
    void Destroy_guess();
    ListElement_guess* Delete_guess(unsigned char flags_guess);
};

typedef void (ListElement_guess::*ListElementDtor_guess)();

// EXTERNAL: TITANIUM 0x0060D6E5 EHVectorDestructorIteratorListElement_guess
void __stdcall EHVectorDestructorIteratorListElement_guess(void* first, unsigned int size,
    int count, ListElementDtor_guess destructor);

struct ElementList_guess {
    int field00_guess;
    char padding04_guess[0x0c];
    ListElement_guess** items_guess;
    int count_guess;
    void Cleanup_guess();
    ~ElementList_guess();
};

struct SharedRecord_guess {
    int field00_guess;
    PilotItem_guess first_guess;
    PilotItem_guess second_guess;
    SmallPointerList_guess list_guess;
    char padding24_guess[4];
    ElementList_guess elements_guess;
    char padding40_guess[4];
    PilotItem_guess last_guess;
    char padding48_guess[4];
    int refCount_guess; // 0x4c
    ~SharedRecord_guess();
    // EXTERNAL: TITANIUM 0x00591EA0 ??3SharedRecord_guess@@SAXPAX@Z
    static void operator delete(void* memory_guess);
};

struct SharedRecordRef_guess {
    SharedRecord_guess* record_guess;
    void Release_guess();
    ~SharedRecordRef_guess();
};

struct SeekResult_guess {
    SeekResult_guess(int position, int state1, int state2, int state3)
        : position_guess(position), state1_guess(state1),
          state2_guess(state2), state3_guess(state3) {}
    int position_guess;
    int unused_guess;
    int state1_guess;
    int state2_guess;
    int state3_guess;
};

struct BufferPosition_guess {
    char padding00_guess[0x10];
    int* field10_guess;
    int* field14_guess;
    char padding18_guess[8];
    int* field20_guess;
    int* field24_guess;
    char padding28_guess[8];
    int* field30_guess;
    int* field34_guess;
    int field38_guess;
    int field3c_guess;
    int field40_guess;
    struct SeekArguments_guess {
        int first_guess;
        int unused_guess;
        int offset_guess;
        int unused2_guess;
        int unused3_guess;
        int unused4_guess;
    };
    void Seek_guess(int* result_guess, SeekArguments_guess arguments_guess,
        unsigned char mode_guess);
    SeekResult_guess SeekRaw_guess(int offset_guess, int origin_guess,
        unsigned char flags_guess);
    // EXTERNAL: TITANIUM 0x004028F2 BufferPosition_guess::NextPut_guess
    char* NextPut_guess();
    int Putback_guess(int value_guess);
    int Underflow_guess();
    int Put_guess(int value_guess);
};

struct StreamBufferByte_guess {
    virtual int Slot00_guess();
    virtual int Slot04_guess();
    virtual int Slot08_guess();
    virtual int Slot0c_guess();
    virtual int Underflow_guess();
    char padding04_guess[0x1c];
    unsigned char** cursor_guess;
    char padding24_guess[0x0c];
    int* count_guess;
    int Bump_guess();
};

struct LeadingBase_guess {
    int fields_guess[2];
};

struct CompleteObject_guess;

struct SecondaryDeleteBase_guess {
    int field00_guess;
    CompleteObject_guess* Delete_guess(unsigned char flags_guess);
};

struct CompleteObject_guess : LeadingBase_guess, SecondaryDeleteBase_guess {
    // EXTERNAL: TITANIUM 0x0040248B CompleteObject_guess::Destroy_guess
    void Destroy_guess();
};

// Adventure merchant refusal text: `kind` 1 singular, else plural; `a` = short of available points
// (8545/8540),
// `b` = short of earned points in the theme (8546/8541), neither = both (8547/8542).
// FUNCTION: TITANIUM 0x0040154F
int __stdcall GetAdventurePurchaseRefusalId_guess(int kind, char a, char b) {
    if (!a) {
        if (!b) {
            return (kind == 1) ? 0x2163 : 0x215e;
        }
        return (kind == 1) ? 0x2161 : 0x215c;
    }
    return (kind == 1) ? 0x2162 : 0x215d;
}

// Caches the theme names twice: the stats spelling (8533-8538) and the short one (8521-8526, "---" .. "Tak").
// FUNCTION: TITANIUM 0x0040158E
void StringLabels_guess::Initialize_guess() {
    label0c_guess = pStringTable->getString(0x2155, 0);
    label10_guess = pStringTable->getString(0x2156, 0);
    label14_guess = pStringTable->getString(0x2157, 0);
    label18_guess = pStringTable->getString(0x2158, 0);
    label1c_guess = pStringTable->getString(0x2159, 0);
    label20_guess = pStringTable->getString(0x215a, 0);
    label24_guess = pStringTable->getString(0x2149, 0);
    label28_guess = pStringTable->getString(0x214a, 0);
    label2c_guess = pStringTable->getString(0x214b, 0);
    label30_guess = pStringTable->getString(0x214c, 0);
    label34_guess = pStringTable->getString(0x214d, 0);
    label38_guess = pStringTable->getString(0x214e, 0);
}

struct LookupTable_guess {
    int padding00_guess[3];
    int first_values_guess[6];
    int second_values_guess[6];
    int Lookup_guess(int index_guess, char use_first_guess);
};

// Theme name `index_guess` (0-5, others 0), short form unless `use_first_guess`.
// FUNCTION: TITANIUM 0x00401687
int LookupTable_guess::Lookup_guess(int index_guess, char use_first_guess) {
    if (index_guess < 0 || index_guess > 5) {
        index_guess = 0;
    }
    if (use_first_guess != 0) {
        return first_values_guess[index_guess];
    }
    return second_values_guess[index_guess];
}

struct LevelRateSource_guess {
    // EXTERNAL: TITANIUM 0x005E0FC0 LevelRateSource_guess::GetLevel_guess
    int GetLevel_guess();
};

// (level + 1) * 70 / 100 * `multiplier_guess`, in integer steps.
// FUNCTION: TITANIUM 0x004016AA
int __stdcall ScaleByLevel_guess(LevelRateSource_guess* source_guess,
    int multiplier_guess) {
    return (((source_guess->GetLevel_guess() + 1) * 0x46) / 100)
        * multiplier_guess;
}

// Compiler vector deleting destructor for 4-byte elements, each a reference to a shared record (0x00401968
// drops one reference and deletes the record at zero): with flag 2 it destroys the whole array (count in
// the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x004016C5
ListElement_guess* ListElement_guess::Delete_guess(unsigned char flags_guess) {
    if ((flags_guess & 2) != 0) {
        DeleteArrayHeader_guess* array_guess = (DeleteArrayHeader_guess*)this - 1;
        EHVectorDestructorIteratorListElement_guess(this, 4, array_guess->count_guess,
            &ListElement_guess::Destroy_guess);
        if ((flags_guess & 1) != 0) {
            free_guess(array_guess);
        }
        return (ListElement_guess*)array_guess;
    }
    Destroy_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor: releases the two CXStr members, +4 then +0 (0x004482FB).
// FUNCTION: TITANIUM 0x00401710
PilotContainer_guess::~PilotContainer_guess() {
}

// Zeroes +4, +8 and the two 0x18-byte blocks at +0xC and +0x24, and sets the vtable 0x0063F4F0.
// FUNCTION: TITANIUM 0x00401745
Initializer_guess::Initializer_guess() {
    field04_guess = 0;
    field08_guess = 0;
    vtable_guess = EQ_ARRAY(int, 0x0063F4F0);
    memset(field0c_guess, 0, 0x18);
    memset(field24_guess, 0, 0x18);
}

// Empties the list: every non-null entry is deleted as an array (0x004016C5 with flags 3), then the
// pointer array is freed and the count and +0 are zeroed.
// FUNCTION: TITANIUM 0x00401777
void ElementList_guess::Cleanup_guess() {
    for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
        if (items_guess[i_guess] != 0) {
            items_guess[i_guess]->Delete_guess(3);
        }
    }
    free_guess(items_guess);
    items_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Empties the list: every non-null entry is deleted as an array (0x00401834 with flags 3), then the
// pointer array is freed and the count and +0 are zeroed.
// FUNCTION: TITANIUM 0x004017B0
void PointerList_guess::Cleanup_guess() {
    for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
        if (items_guess[i_guess] != 0) {
            items_guess[i_guess]->Delete_guess(3);
        }
    }
    free_guess(items_guess);
    items_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Compiler vector deleting destructor for 8-byte elements: with flag 2 it destroys the whole array (count
// in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x004017E9
SmallDeleteElement_guess* SmallDeleteElement_guess::Delete_guess(unsigned char flags_guess) {
    if ((flags_guess & 2) != 0) {
        DeleteArrayHeader_guess* array_guess = (DeleteArrayHeader_guess*)((char*)this - 4);
        EHVectorDestructorIteratorSmall_guess(this, 8, array_guess->count_guess,
            &SmallDeleteElement_guess::Destroy_guess);
        if ((flags_guess & 1) != 0) {
            free_guess(array_guess);
        }
        return (SmallDeleteElement_guess*)array_guess;
    }
    Destroy_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Compiler vector deleting destructor for 8-byte elements: with flag 2 it destroys the whole array (count
// in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x00401834
DeleteElement_guess* DeleteElement_guess::Delete_guess(unsigned char flags_guess) {
    if ((flags_guess & 2) != 0) {
        DeleteArrayHeader_guess* array_guess = (DeleteArrayHeader_guess*)((char*)this - 4);
        EHVectorDestructorIterator_guess(this, 8, array_guess->count_guess,
            &DeleteElement_guess::Destroy_guess);
        if ((flags_guess & 1) != 0) {
            free_guess(array_guess);
        }
        return (DeleteElement_guess*)array_guess;
    }
    Destroy_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor: empties the list (0x00401777).
// FUNCTION: TITANIUM 0x0040187F
ElementList_guess::~ElementList_guess() {
    Cleanup_guess();
}

// Empties the list (0x004017B0).
// FUNCTION: TITANIUM 0x00401884
void PointerList_guess::CleanupThunk_guess() {
    Cleanup_guess();
}

// Destructor: destroys the member at +0x20 (0x00591770), the list at +4 (0x004017B0), then the CXStr
// at +0 (0x004482FB).
// FUNCTION: TITANIUM 0x00401889
Owner_guess::~Owner_guess() {
}

// Empties the list: every non-null entry is deleted as an array (0x004017E9 with flags 3), then the
// pointer array is freed and the count and +0 are zeroed.
// FUNCTION: TITANIUM 0x004018CD
void SmallPointerList_guess::Cleanup_guess() {
    for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
        if (items_guess[i_guess] != 0) {
            items_guess[i_guess]->Delete_guess(3);
        }
    }
    free_guess(items_guess);
    items_guess = 0;
    count_guess = 0;
    field00_guess = 0;
}

// Empties the list (0x004018CD).
// FUNCTION: TITANIUM 0x00401906
void SmallPointerList_guess::CleanupThunk_guess() {
    Cleanup_guess();
}

// Destructor: releases the CXStr at +0x44, the lists at +0x28 and +0xC, then the CXStr members at +8
// and +4.
// FUNCTION: TITANIUM 0x0040190B
SharedRecord_guess::~SharedRecord_guess() {
}

// Drops this reference to the shared record: its count goes down by one and the record is deleted
// once it is 0 or less.
// FUNCTION: TITANIUM 0x00401968
void SharedRecordRef_guess::Release_guess() {
    if (record_guess != 0) {
        --record_guess->refCount_guess;
        if (record_guess->refCount_guess <= 0) {
            delete record_guess;
        }
    }
}

// Destructor: drops the reference to the shared record (0x00401968).
// FUNCTION: TITANIUM 0x0040198E
SharedRecordRef_guess::~SharedRecordRef_guess() {
    Release_guess();
}

FacetDelete_guess::~FacetDelete_guess() {
}

// Standard library: scalar deleting destructor of a locale facet (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00401A93
FacetDelete_guess* FacetDelete_guess::Delete_guess(unsigned char flags_guess) {
    this->FacetDelete_guess::~FacetDelete_guess();
    if ((flags_guess & 1) != 0) {
        operator delete(this);
    }
    return this;
}

// Spawn by id from the 3000-entry id table at 0x900F50; 0 for ids out of range.
// FUNCTION: TITANIUM 0x00401B28
unsigned int __cdecl GetSpawnByID_guess(unsigned int index) {
    if (index <= 0 || index >= 3000) {
        return 0;
    }
    return EQ_ARRAY(unsigned int, 0x00900F50)[index];
}

// "The Shroud Bank window was not opened, as there were no items that could be transferred from your previous
// form." (4558).
// FUNCTION: TITANIUM 0x00401B42
void __cdecl ReportShroudBankNotOpened_guess() {
    ((MessageManager_guess*)EQ_GLOBAL(MessageManager_guess*, 0x00988DF0))->dsp_chat(
        ((StringManager_guess*)EQ_GLOBAL(StringManager_guess*, 0x00905CB0))->getString(0x11ce, 0, 0xf, 1));
}

struct Bucket_guess {
    // EXTERNAL: TITANIUM 0x004C9733 Bucket_guess::GetValue_guess
    int GetValue_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x004C9815 Bucket_guess::Add_guess
    void Add_guess(int* key_guess);
};

#define g_bucket_guess EQ_GLOBAL(Bucket_guess*, 0x00985CEC)

// Cached value for `key_guess`; when missing and `flag_guess` is set, asks the server (message 0x3A14, 4
// bytes).
// FUNCTION: TITANIUM 0x00401B65
int __stdcall GetProgressionRecord_guess(int key_guess, char flag_guess) {
    if (g_bucket_guess == 0) {
        return 0;
    }
    int result_guess = g_bucket_guess->GetValue_guess(key_guess);
    if (result_guess == 0 && flag_guess != 0) {
        int value_guess = key_guess;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x3a14, (int)&value_guess, 4, 1);
    }
    return result_guess;
}

// Whether the spawn is within 50 units.
// FUNCTION: TITANIUM 0x00401BB1
bool ValueHandler_guess::IsWithinRange_guess(int value_guess) {
    int entry_guess = GetSpawnByID_call_guess(index_guess);
    if (entry_guess == 0) {
        return 0;
    }
    return g_spellCalc_guess->PlayerSimpleDistance_guess(entry_guess, value_guess, 1.0f)
        <= 50.0f;
}

// Starts a shroud transformation: sends message 0x4B6D (4 bytes) and shows "Please wait while your
// transformation is completed." (5191) for 45 s.
// FUNCTION: TITANIUM 0x00401BEF
void ValueHandler_guess::StartShroudTransform_guess(int value) {
    int data = value;
    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x4b6d, (int)&data, 4, 1);
    g_errorDisplay_guess->Activate(
        g_errorSource_guess ? g_errorSource_guess + 8 : 0,
        0x82,
        pStringTable->getString(0x1447, 0),
        0, 45000, 0, 0);
}

// Sends message 0x1C2D with no payload; the shroud selection window's cancel (0x00549977) calls it.
// FUNCTION: TITANIUM 0x00401C53
void __cdecl SendProgressionCancel_guess() {
    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x1c2d, 0, 0, 1);
}

// Standard library: ios_base destructor body (restores the ios_base vtable, then destroys the state).
// FUNCTION: TITANIUM 0x00401C6C
void IosBase_guess::DestroyWrapper_guess() {
    vtable = EQ_ARRAY(int, 0x0063F558);
    Destroy_guess();
}

// Standard library: scalar deleting destructor of an ios_base (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00401C86
IosBase_guess* IosBase_guess::Delete_guess(unsigned int flags) {
    ((IosBaseCall_guess*)this)->DestroyWrapper_external_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Standard library: ctype<char>::do_tolower for one char.
// FUNCTION: TITANIUM 0x00401E6E
int CtypeFacet_guess::ToLower_guess(unsigned char value_guess) {
    return __Tolower_guess(value_guess, &ctypevec_guess);
}

// Standard library: ctype<char>::do_toupper for one char.
// FUNCTION: TITANIUM 0x00401EAD
int CtypeFacet_guess::ToUpper_guess(unsigned char value_guess) {
    return __Toupper_guess(value_guess, &ctypevec_guess);
}

// basic_streambuf::uflow: asks underflow (virtual slot 4) for the next char; -1 at the end, else consumes
// it (get pointer +1, remaining count -1) and returns it.
// FUNCTION: TITANIUM 0x0040202D
// @early-stop: budget, diff ndiff=5
int StreamBufferByte_guess::Bump_guess() {
    unsigned char* current_guess;
    int result_guess = Underflow_guess();
    if (result_guess == -1) {
        return result_guess;
    }
    --*count_guess;
    current_guess = *cursor_guess;
    *cursor_guess = current_guess + 1;
    return *current_guess;
}

#define g_invalidPosition_guess EQ_GLOBAL(int, 0x006731B0)
#define g_positionState1_guess EQ_GLOBAL(int, 0x0099E9E0)
#define g_positionState2_guess EQ_GLOBAL(int, 0x0099E9E4)
#define g_positionState3_guess EQ_GLOBAL(int, 0x0079C13C)

struct PositionStateOutput_guess {
    int field00_guess;
    int padding04_guess;
    int field08_guess;
    int field0c_guess;
    int field10_guess;
};

// Stream seekoff on an unseekable buffer: always returns the invalid position.
// FUNCTION: TITANIUM 0x0040213C
void __stdcall seekoff_guess(PositionStateOutput_guess* output_guess,
    int, int, int) {
    output_guess->field00_guess = g_invalidPosition_guess;
    output_guess->field08_guess = g_positionState1_guess;
    output_guess->field0c_guess = g_positionState2_guess;
    output_guess->field10_guess = g_positionState3_guess;
}

// Stream seekpos on an unseekable buffer: always returns the invalid position.
// FUNCTION: TITANIUM 0x00402166
void __stdcall seekpos_guess(PositionStateOutput_guess* output_guess,
    int, int, int, int, int, int, int) {
    output_guess->field00_guess = g_invalidPosition_guess;
    output_guess->field08_guess = g_positionState1_guess;
    output_guess->field0c_guess = g_positionState2_guess;
    output_guess->field10_guess = g_positionState3_guess;
}

// basic_stringbuf::pbackfail: steps the get pointer back one char and stores `value_guess` there; a
// different char is refused (-1) in a constant buffer (state bit 2). EOF only steps back and returns 0.
// FUNCTION: TITANIUM 0x004021A6
// @early-stop: budget, structural ndiff=22
int BufferPosition_guess::Putback_guess(int value_guess) {
    char* current_guess = (char*)*field20_guess;
    if (current_guess == 0 ||
        (unsigned int)current_guess <= (unsigned int)*field10_guess) {
        return -1;
    }
    if (value_guess != -1 &&
        (char)value_guess != current_guess[-1] &&
        (field40_guess & 2) != 0) {
        return -1;
    }
    ++*field30_guess;
    --*field20_guess;
    if (value_guess != -1) {
        *(char*)*field20_guess = (char)value_guess;
        return value_guess;
    }
    return 0;
}

// basic_stringbuf::underflow: the next unread char, else extends the read area up to the written text
// (high-water mark +0x3C); -1 when nothing is left or the buffer has no read area (state bit 4).
// FUNCTION: TITANIUM 0x004021EE
// @early-stop: budget, structural ndiff=23
int BufferPosition_guess::Underflow_guess() {
    unsigned char* current_guess = (unsigned char*)*field20_guess;
    if (current_guess == 0) {
        return -1;
    }
    unsigned int count_guess = *field30_guess;
    if ((unsigned int)*field20_guess <
        (unsigned int)*field20_guess + count_guess) {
        return *current_guess;
    }
    if ((field40_guess & 4) != 0) {
        return -1;
    }
    unsigned int end_guess = *field24_guess;
    if (end_guess == 0 || ((unsigned int)*field20_guess >= end_guess &&
         (unsigned int)*field20_guess >= (unsigned int)field3c_guess)) {
        return -1;
    }
    if ((unsigned int)field3c_guess < end_guess) {
        field3c_guess = end_guess;
    }
    *field30_guess = field3c_guess - *field20_guess;
    return *(unsigned char*)*field20_guess;
}

// basic_stringbuf::seekoff: moves the get pointer (mode bit 1) and/or the put pointer (bit 2) to `offset`
// from the start, current position or end (origin 0/1/2; the end is the high-water mark +0x3C). With both
// bits the put pointer follows the get pointer and origin 1 is refused. Out of range gives the invalid
// position.
// FUNCTION: TITANIUM 0x0040224B
// @early-stop: budget, structural ndiff=103
SeekResult_guess BufferPosition_guess::SeekRaw_guess(int offset_guess,
    int origin_guess, unsigned char flags_guess) {
    int* get_ptr_guess = field24_guess;
    int current_guess = *get_ptr_guess;
    if (current_guess != 0 &&
        (unsigned int)field3c_guess < (unsigned int)current_guess) {
        field3c_guess = current_guess;
    }
    int position_guess = g_invalidPosition_guess;
    if ((flags_guess & 1) != 0 && *field20_guess != 0) {
        int put_guess = *field20_guess;
        int invalid_guess = g_invalidPosition_guess;
        position_guess = invalid_guess;
        if (origin_guess == 2) {
            position_guess = offset_guess + (field3c_guess - *field10_guess);
        } else if (origin_guess == 1) {
            if ((flags_guess & 2) == 0) {
                position_guess = offset_guess + (put_guess - *field10_guess);
            }
        } else if (origin_guess == 0) {
            position_guess = offset_guess;
        }
        if (position_guess < 0 ||
            position_guess > field3c_guess - *field10_guess) {
            position_guess = invalid_guess;
        } else {
            int delta_guess = (*field10_guess - put_guess) + position_guess;
            *field30_guess -= delta_guess;
            *field20_guess += delta_guess;
            if ((flags_guess & 2) != 0) {
                int get_guess = *field24_guess;
                if (get_guess != 0) {
                    int put2_guess = *field20_guess;
                    int count_guess = *field34_guess + get_guess;
                    *field24_guess = put2_guess;
                    *field34_guess = count_guess - put2_guess;
                }
            }
        }
    } else if ((flags_guess & 2) != 0 && *field24_guess != 0) {
        int get_guess = *field24_guess;
        if (origin_guess == 2) {
            position_guess = offset_guess + (field3c_guess - *field10_guess);
        } else if (origin_guess == 1) {
            position_guess = offset_guess + (get_guess - *field10_guess);
        } else if (origin_guess == 0) {
            position_guess = offset_guess;
        } else {
            position_guess = g_invalidPosition_guess;
        }
        if (position_guess < 0 ||
            position_guess > field3c_guess - *field10_guess) {
            position_guess = g_invalidPosition_guess;
        } else {
            int delta_guess = (*field10_guess - get_guess) + position_guess;
            *field34_guess -= delta_guess;
            *field24_guess += delta_guess;
        }
    }
    return SeekResult_guess(position_guess, g_positionState1_guess,
        g_positionState2_guess, g_positionState3_guess);
}

// basic_stringbuf::seekpos: the absolute-position form of seekoff (0x0040224B), same mode rules; the result
// is written to `result_guess` as a stream position.
// FUNCTION: TITANIUM 0x00402392
void BufferPosition_guess::Seek_guess(int* result_guess,
    SeekArguments_guess arguments_guess, unsigned char mode_guess) {
    int position_guess = arguments_guess.first_guess;
    position_guess += arguments_guess.offset_guess;
    int current_guess = *field24_guess;
    if (current_guess != 0 &&
        (unsigned int)field3c_guess < (unsigned int)current_guess) {
        field3c_guess = current_guess;
    }
    int invalid_guess = g_invalidPosition_guess;
    if (position_guess != invalid_guess) {
        if ((mode_guess & 1) != 0 && *field20_guess != 0) {
            int putPosition_guess = *field20_guess;
            if (position_guess >= 0 &&
                position_guess <= field3c_guess - *field10_guess) {
                int delta_guess = (*field10_guess - putPosition_guess) + position_guess;
                *field30_guess -= delta_guess;
                *field20_guess += delta_guess;
                if ((mode_guess & 2) != 0) {
                    int getPosition_guess = *field24_guess;
                    if (getPosition_guess != 0) {
                        int putPosition_guess = *field20_guess;
                        int getCount_guess = *field34_guess;
                        int nextCount_guess = getCount_guess + getPosition_guess;
                        *field24_guess = putPosition_guess;
                        *field34_guess = nextCount_guess - putPosition_guess;
                    }
                }
            } else {
                position_guess = invalid_guess;
            }
        } else {
            if ((mode_guess & 2) != 0) {
                int getPosition_guess = *field24_guess;
                if (getPosition_guess != 0 && position_guess >= 0 &&
                    position_guess <= field3c_guess - *field10_guess) {
                    int delta_guess = (*field10_guess - getPosition_guess) + position_guess;
                    *field34_guess -= delta_guess;
                    *field24_guess += delta_guess;
                } else {
                    position_guess = invalid_guess;
                }
            } else {
                position_guess = invalid_guess;
            }
        }
    }
    result_guess[0] = position_guess;
    result_guess[2] = g_positionState1_guess;
    result_guess[3] = g_positionState2_guess;
    result_guess[4] = g_positionState3_guess;
}

// Scalar deleting destructor entered through the second base (+8): destroys the complete object
// (0x0040248B) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0040246C
// @early-stop: budget, structural ndiff=6
CompleteObject_guess* SecondaryDeleteBase_guess::Delete_guess(
    unsigned char flags_guess) {
    CompleteObject_guess* object_guess =
        static_cast<CompleteObject_guess*>(this);
    object_guess->Destroy_guess();
    if ((flags_guess & 1) != 0) {
        operator delete(object_guess);
    }
    return object_guess;
}

// basic_stringbuf::overflow (Dinkumware): writes `value_guess` at the put pointer, first growing the buffer
// by half its size (at least 32 bytes) when full. State bits at +0x40: 1 buffer owned, 2 constant (no
// growth: returns -1), 4 no read area, 8 append (the put pointer first jumps to the high-water mark +0x3C).
// FUNCTION: TITANIUM 0x00402760
// @early-stop: budget, structural ndiff=74
int BufferPosition_guess::Put_guess(int value_guess) {
    if ((field40_guess & 8) != 0) {
        unsigned int position_guess = *field24_guess;
        unsigned int end_guess = field3c_guess;
        if (position_guess != 0 && position_guess < end_guess) {
            int available_guess = *field34_guess;
            available_guess += position_guess;
            *field24_guess = end_guess;
            *field34_guess = available_guess - end_guess;
        }
    }
    if (value_guess == -1) {
        return 0;
    }
    unsigned int position_guess = *field24_guess;
    if (position_guess != 0 && position_guess < *field34_guess + position_guess) {
        *NextPut_guess() = (char)value_guess;
        return value_guess;
    }
    if ((field40_guess & 2) != 0) {
        return -1;
    }
    unsigned int size_guess;
    if (position_guess == 0) {
        size_guess = 0;
    } else {
        size_guess = *field34_guess - *field10_guess + position_guess;
    }
    unsigned int newSize_guess = size_guess;
    unsigned int capacity_guess = size_guess >> 1;
    if (capacity_guess < 0x20) {
        capacity_guess = 0x20;
    }
    void* buffer_guess = 0;
    if (capacity_guess != 0) {
        do {
            if (size_guess <= 0x7fffffffu - capacity_guess) {
                break;
            }
            capacity_guess >>= 1;
        } while (capacity_guess != 0);
        if (capacity_guess != 0) {
            newSize_guess = capacity_guess + size_guess;
            buffer_guess = operator new(newSize_guess);
        }
    }
    if (size_guess != 0) {
        memcpy(buffer_guess, (void*)*field10_guess, size_guess);
    }
    if ((field40_guess & 1) != 0) {
        operator delete((void*)*field10_guess);
    }
    field40_guess |= 1;
    if (size_guess == 0) {
        field3c_guess = (int)buffer_guess;
        *field14_guess = (int)buffer_guess;
        *field24_guess = (int)buffer_guess;
        *field34_guess = newSize_guess;
        if ((field40_guess & 4) != 0) {
            *field10_guess = (int)buffer_guess;
            *field20_guess = 0;
            *field30_guess = (int)buffer_guess;
        } else {
            *field10_guess = (int)buffer_guess;
            *field20_guess = (int)buffer_guess;
            *field30_guess = 1;
        }
    } else {
        field3c_guess += (int)buffer_guess - *field10_guess;
        *field14_guess += (int)buffer_guess - *field10_guess;
        *field24_guess = (int)buffer_guess + (*field24_guess - *field10_guess);
        *field34_guess = (int)buffer_guess - *field24_guess + newSize_guess;
        if ((field40_guess & 4) != 0) {
            *field10_guess = (int)buffer_guess;
            *field20_guess = 0;
            *field30_guess = (int)buffer_guess;
        } else {
            *field20_guess = (int)buffer_guess + (*field20_guess - *field10_guess);
            *field30_guess = *field24_guess - *field20_guess + 1;
            *field10_guess = (int)buffer_guess;
        }
    }
    *NextPut_guess() = (char)value_guess;
    return value_guess;
}

struct String_guess {
    int data[7];
    // EXTERNAL: TITANIUM 0x004032F1 ??0String_guess@@QAE@PAU0@@Z
    String_guess(String_guess* other);
    // EXTERNAL: TITANIUM 0x0040269F String_guess::Compare_guess
    int Compare_guess(String_guess* other);
    // EXTERNAL: TITANIUM 0x004030E1 String_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x00402E5E String_guess::String_guess
    String_guess();
    // EXTERNAL: TITANIUM 0x00402A80 String_guess::FreeStorage_guess
    void FreeStorage_guess();
    // EXTERNAL: TITANIUM 0x0040291E String_guess::_Tidy
    void _Tidy(bool, unsigned int);
    void FreeThunk_guess();
    void TidyWrapper_guess();
};

struct ListString_guess {
    String_guess text_guess;
    // EXTERNAL: TITANIUM 0x00403631 ??0ListString_guess@@QAE@PBD@Z
    ListString_guess(const char* text_guess);
    ~ListString_guess() { text_guess._Tidy(true, 0); }
};

struct VBaseFlags_guess {
    int field00_guess;
    int field04_guess;
    unsigned char flags08_guess;
};

struct VObject_guess : virtual VBaseFlags_guess {
};

// EXTERNAL: TITANIUM 0x00403448 FUN_00403448_guess
void __cdecl FUN_00403448_guess(VObject_guess* obj_guess, String_guess* str_guess,
                                int value_guess);

struct StringFreeStorage_guess {
    int field00_guess;
    // EXTERNAL: TITANIUM 0x0040313B StringFreeStorage_guess::StringFreeStorage_guess
    StringFreeStorage_guess();
    // EXTERNAL: TITANIUM 0x00404581 StringFreeStorage_guess::Free_guess
    void Free_guess();
};

struct StringCleanupPair_guess {
    int field00_guess;
    String_guess first_guess;
    String_guess second_guess;
    int field3c_guess[2];
    StringFreeStorage_guess storage_guess;
    void Cleanup_guess();
};

struct StringExtended_guess : String_guess {
    int field1c_guess;
    int field20_guess;
    char field24_guess;
    StringExtended_guess();
    StringExtended_guess(StringExtended_guess* other);
};

struct StringCleanupOwner_guess {
    int before_guess;
    String_guess first_guess;
    String_guess second_guess;
    int gap_guess;
    int storage_guess[2];
    void Cleanup_guess();
};

// Releases an entry's members (key + two strings + list): its list (0x00403B60) and both strings.
// FUNCTION: TITANIUM 0x00403CB6
void StringCleanupOwner_guess::Cleanup_guess() {
    FUN_00403B60_guess(storage_guess);
    second_guess._Tidy(true, 0);
    first_guess._Tidy(true, 0);
}

struct StringCopy_guess {
    int data_guess[7];
    // EXTERNAL: TITANIUM 0x004032F1 ??0StringCopy_guess@@QAE@PAU0@@Z
    StringCopy_guess(StringCopy_guess* other);
    // EXTERNAL: TITANIUM 0x0040B488 ??1StringCopy_guess@@QAE@XZ
    ~StringCopy_guess();
};

struct AllocatedNode_guess;

struct EntryList_guess {
    int field00_guess;
    AllocatedNode_guess* head_guess;
    int count_guess;
    int tail_guess[9];
    struct Iter_guess {
        AllocatedNode_guess* node_guess;
    };
    struct Tag_guess {
    };
    // EXTERNAL: TITANIUM 0x00403AAC EntryList_guess::Fill_guess
    void Fill_guess(Iter_guess where, Iter_guess first,
        Iter_guess last, Tag_guess tag);
    EntryList_guess(EntryList_guess* other);
    Iter_guess Begin_guess();
    Iter_guess End_guess();
};

struct NamedEntry_guess {
    int key_guess;
    StringCopy_guess first_guess;
    StringCopy_guess second_guess;
    int field3c_guess;
    EntryList_guess list_guess;
    NamedEntry_guess(NamedEntry_guess* other);
};

// Copy constructor for that entry: key, both strings, the dword at +0x3C and the list.
// FUNCTION: TITANIUM 0x00403E1E
NamedEntry_guess::NamedEntry_guess(NamedEntry_guess* other)
    : key_guess(other->key_guess), first_guess(&other->first_guess),
      second_guess(&other->second_guess), field3c_guess(other->field3c_guess),
      list_guess(&other->list_guess) {
}

struct StringCleanupOwnerView_guess {
    int padding_guess[2];
    StringCleanupOwner_guess owner_guess;
    void Cleanup_guess();
};

// Releases the entry held by this node (0x00403CB6).
// FUNCTION: TITANIUM 0x00403E7B
void StringCleanupOwnerView_guess::Cleanup_guess() {
    owner_guess.Cleanup_guess();
}

// EXTERNAL: TITANIUM 0x00402D20 FUN_00402D20_guess
bool __cdecl FUN_00402D20_guess(String_guess* first, String_guess* second);

struct StringOwner_guess {
    int before;
    String_guess first;
    String_guess second;
    int gap[2];
    String_guess third;
    String_guess fourth;
    StringOwner_guess();
    ~StringOwner_guess();
};

struct StringOwnerView_guess {
    int before_guess[2];
    StringOwner_guess owner_guess;
    ~StringOwnerView_guess();
};

struct StringPair_guess {
    int before;
    String_guess value;
    bool LessThan_guess(StringPair_guess* other);
    bool Equal_guess(StringPair_guess* other);
};

struct DispatchTarget_guess {
    virtual void Invoke_guess(int first, int second);
};

struct DispatchListNode_guess {
    DispatchListNode_guess* next_guess;
    int field04_guess;
    DispatchTarget_guess* target_guess;
};

struct DispatchPair_guess {
    int first_guess;
    int second_guess;
};

struct AllocatedNode_guess {
    AllocatedNode_guess* field00_guess;
    AllocatedNode_guess* field04_guess;
};

// Standard library: stream sentry cleanup (jumps to 0x00425232): unlocks the stream buffer when
// there is one. Only the unwind funclets call it.
// FUNCTION: TITANIUM 0x004026C3
void __fastcall thunk_FUN_00425232(int* param_1) {
    FUN_00425232_guess(param_1);
}

// Standard library: allocates a list head node of 0x30 bytes whose links point at itself (empty list).
// FUNCTION: TITANIUM 0x00402A97
AllocatedNode_guess* __cdecl FUN_00402A97_guess() {
    AllocatedNode_guess* node = (AllocatedNode_guess*)operator new(0x30);
    if (node != 0) {
        node->field00_guess = node;
    }
    if (&node->field04_guess != 0) {
        node->field04_guess = node;
    }
    return node;
}

inline EntryList_guess::Iter_guess EntryList_guess::Begin_guess() {
    Iter_guess it;
    it.node_guess = head_guess->field00_guess;
    return it;
}

inline EntryList_guess::Iter_guess EntryList_guess::End_guess() {
    Iter_guess it;
    it.node_guess = head_guess;
    return it;
}

// List copy constructor for 0x30-byte nodes: a fresh empty sentinel (0x00402A97), size 0, then every
// element of `other` is inserted (0x00403AAC).
// FUNCTION: TITANIUM 0x00403C0C
EntryList_guess::EntryList_guess(EntryList_guess* other) {
    AllocatedNode_guess* node = FUN_00402A97_guess();
    count_guess = 0;
    try {
        head_guess = node;
        Tag_guess tag_guess;
        Fill_guess(Begin_guess(), other->Begin_guess(), other->End_guess(), tag_guess);
    } catch (...) {
        operator delete(head_guess);
        throw;
    }
}

// Standard library: allocates a list head node of 0x54 bytes whose links point at itself (empty list).
// FUNCTION: TITANIUM 0x00402AAF
AllocatedNode_guess* __cdecl FUN_00402AAF_guess() {
    AllocatedNode_guess* node = (AllocatedNode_guess*)operator new(0x54);
    if (node != 0) {
        node->field00_guess = node;
    }
    if (&node->field04_guess != 0) {
        node->field04_guess = node;
    }
    return node;
}

// Standard library: allocates a list head node of 0x58 bytes whose links point at itself (empty list).
// FUNCTION: TITANIUM 0x00402AC7
AllocatedNode_guess* __cdecl FUN_00402AC7_guess() {
    AllocatedNode_guess* node = (AllocatedNode_guess*)operator new(0x58);
    if (node != 0) {
        node->field00_guess = node;
    }
    if (&node->field04_guess != 0) {
        node->field04_guess = node;
    }
    return node;
}

// Standard library: allocates a list head node of 0x88 bytes whose links point at itself (empty list).
// FUNCTION: TITANIUM 0x00402ADF
AllocatedNode_guess* __cdecl FUN_00402ADF_guess() {
    AllocatedNode_guess* node = (AllocatedNode_guess*)operator new(0x88);
    if (node != 0) {
        node->field00_guess = node;
    }
    if (&node->field04_guess != 0) {
        node->field04_guess = node;
    }
    return node;
}

// Calls every listener in the list with (first, second); the std::for_each shape.
// FUNCTION: TITANIUM 0x00402CF2
void __cdecl InvokeEach_guess(DispatchPair_guess* result, DispatchListNode_guess* node,
    DispatchListNode_guess* stop, int first, int second) {
    for (; node != stop; node = node->next_guess) {
        node->target_guess->Invoke_guess(first, second);
    }
    result->second_guess = second;
    result->first_guess = first;
}

// Ordering for the list sort/merge: compares the two entries' strings (0x00402D20).
// FUNCTION: TITANIUM 0x00402D5A
bool StringPair_guess::LessThan_guess(StringPair_guess* other) {
    return FUN_00402D20_guess(&value, &other->value);
}

// True when the two entries' strings are equal; list::remove (0x00403B24) uses it so a re-read
// progression replaces the old one.
// FUNCTION: TITANIUM 0x00402D70
bool StringPair_guess::Equal_guess(StringPair_guess* other) {
    return value.Compare_guess(&other->value) == 0;
}

struct PendingEntry_guess {
    int tag_guess;
    int value_guess;
    bool flag_guess;
};

struct ValueRecord_guess {
    int value_guess;
    int hasKey_guess;
    int key_guess;
};

struct PairRange_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0c_guess;
};

struct PairEntry_guess {
    int tag_guess;
    int value_guess;
    int flag_guess;
};

struct PairSink_guess {
    // EXTERNAL: TITANIUM 0x00490D71 PairSink_guess::GetOrCreateCachedItem_guess
    void GetOrCreateCachedItem_guess(int first_guess, int* range_guess);
};

#define g_pairSink_guess EQ_GLOBAL(PairSink_guess, 0x00903EA0)

struct RecordSink_guess {
    // EXTERNAL: TITANIUM 0x00402D37 RecordSink_guess::Flush_guess
    void Flush_guess(PendingEntry_guess* entry);
    void Store_guess(ValueRecord_guess* record, int unused_guess);
    void Pair_guess(PairRange_guess* range_guess, int end_guess);
};

// Message 0x18CB (routed by 0x004050D0). Only when the length argument equals the dword at +8 plus 8:
// caches the text at +0x0C under id +4 (0x00490D71), then tells every listener (0x00402D37) with tag 3,
// the dword at +0 and that id.
// FUNCTION: TITANIUM 0x00402D88
void RecordSink_guess::Pair_guess(PairRange_guess* range_guess, int end_guess) {
    if (range_guess->field08_guess + 8 == end_guess) {
        g_pairSink_guess.GetOrCreateCachedItem_guess(range_guess->field04_guess, &range_guess->field0c_guess);
        PairEntry_guess entry;
        entry.value_guess = range_guess->field00_guess;
        entry.flag_guess = range_guess->field04_guess;
        entry.tag_guess = 3;
        Flush_guess((PendingEntry_guess*)&entry);
    }
}

// Message 0x1573 (routed by 0x004050D0). When +4 is set, the '^'-separated record from +8 on is parsed
// into the map at 0x00985CEC (0x004C9815); then every listener (0x00402D37) gets tag 1, the dword at +0
// and whether +4 was set.
// FUNCTION: TITANIUM 0x00402E02
void RecordSink_guess::Store_guess(ValueRecord_guess* record, int unused_guess) {
    if (record->hasKey_guess != 0) {
        g_bucket_guess->Add_guess(&record->key_guess);
    }
    PendingEntry_guess entry;
    entry.value_guess = record->value_guess;
    entry.flag_guess = record->hasKey_guess != 0;
    entry.tag_guess = 1;
    Flush_guess(&entry);
}

// Standard library: stream destructor: the stream part at +0x50 (0x0040271A), then its ios_base
// (0x00401C6C).
// FUNCTION: TITANIUM 0x00402E4B
// @early-stop: budget, structural ndiff=7
void CleanupOwner402EAE_guess::Destroy_guess() {
    ((IosBase_guess*)this)->DestroyWrapper_guess();
}

// Standard library: scalar deleting destructor of a stream object (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00402EAE
// @early-stop: budget, structural ndiff=6
void* CleanupSubobject402EAE_guess::Delete_guess(unsigned char flags_guess) {
    CleanupOwner402EAE_guess* owner_guess = (CleanupOwner402EAE_guess*)this;
    owner_guess->Destroy_guess();
    if ((flags_guess & 1) != 0) {
        operator delete(owner_guess);
    }
    return owner_guess;
}

// Zeroes the three dwords that follow the string (+0x1C, +0x20, +0x24).
// FUNCTION: TITANIUM 0x0040305F
StringExtended_guess::StringExtended_guess() {
    field20_guess = 0;
    field1c_guess = 0;
    field24_guess = 0;
}

// Standard library: list destructor (0x00402A80): frees the nodes and the head node, and nulls the
// head.
// FUNCTION: TITANIUM 0x00403076
void String_guess::FreeThunk_guess() {
    return FreeStorage_guess();
}

// Standard library: string destructor (_Tidy with free).
// FUNCTION: TITANIUM 0x0040307B
void String_guess::TidyWrapper_guess() {
    _Tidy(true, 0);
}

// Empty constructor; the four strings construct themselves.
// FUNCTION: TITANIUM 0x00403085
StringOwner_guess::StringOwner_guess() {
}

// Destructor: frees the four strings, last to first.
// FUNCTION: TITANIUM 0x004030AC
StringOwner_guess::~StringOwner_guess() {
    fourth._Tidy(true, 0);
    third._Tidy(true, 0);
    second._Tidy(true, 0);
    first._Tidy(true, 0);
}

// Destructor: destroys the four-string record at +8 (0x004030AC).
// FUNCTION: TITANIUM 0x004032DC
StringOwnerView_guess::~StringOwnerView_guess() {
}

struct CopyStringStorage_guess {
    // EXTERNAL: TITANIUM 0x0040291E CopyStringStorage_guess::Tidy_guess
    void Tidy_guess(bool tidy_guess, unsigned int reserve_guess);
};

struct CopyString_guess {
    unsigned int storage_guess[7];
    // EXTERNAL: TITANIUM 0x004032F1 CopyString_guess::CopyString_guess
    CopyString_guess(const CopyString_guess& source_guess);
    ~CopyString_guess() {
        ((CopyStringStorage_guess*)this)->Tidy_guess(true, 0);
    }
};

struct FourStringRecord_guess {
    int field00_guess;
    CopyString_guess field04_guess;
    CopyString_guess field20_guess;
    int field3c_guess;
    int field40_guess;
    CopyString_guess field44_guess;
    CopyString_guess field60_guess;
    int field7c_guess;
    FourStringRecord_guess(FourStringRecord_guess* other_guess);
};

// Copy constructor for a record of four strings and four dwords (+0, +0x3C, +0x40, +0x7C).
// FUNCTION: TITANIUM 0x004033A8
FourStringRecord_guess::FourStringRecord_guess(FourStringRecord_guess* other_guess)
    : field00_guess(other_guess->field00_guess),
      field04_guess(other_guess->field04_guess),
      field20_guess(other_guess->field20_guess),
      field3c_guess(other_guess->field3c_guess),
      field40_guess(other_guess->field40_guess),
      field44_guess(other_guess->field44_guess),
      field60_guess(other_guess->field60_guess),
      field7c_guess(other_guess->field7c_guess) {
}

// Copy constructor: the string, then the three dwords at +0x1C, +0x20 and +0x24.
// FUNCTION: TITANIUM 0x00403421
StringExtended_guess::StringExtended_guess(StringExtended_guess* other)
    : String_guess((String_guess*)other) {
    field1c_guess = other->field1c_guess;
    field20_guess = other->field20_guess;
    field24_guess = other->field24_guess;
}

// Standard library: scalar deleting destructor of an exception (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00403588
ExceptionDerived_guess* ExceptionDerived_guess::Delete_guess(unsigned int flags) {
    this->ExceptionDerived_guess::~ExceptionDerived_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Standard library: exception destructor: sets its vtable and runs 0x00403026 (frees the message,
// destroys the base).
// FUNCTION: TITANIUM 0x004035A4
ExceptionDerived_guess::~ExceptionDerived_guess() {
}

// Standard library: exception constructor from a message (the list<T> too long / length_error family).
// FUNCTION: TITANIUM 0x0040382A
ExceptionDerived_guess::ExceptionDerived_guess(const char* message_guess)
    : ExceptionBase_guess(message_guess) {
}

// Reads the next token (unless one is pending) and consumes it only when it equals `key_guess`.
// FUNCTION: TITANIUM 0x004035AF
// @early-stop: budget, structural ndiff=19
bool __cdecl MatchSectionTag_guess(VObject_guess* obj_guess, String_guess* str_guess,
                                ListString_guess key_guess, int value_guess) {
    int size_guess = str_guess->data[5];
    if (size_guess == 0) {
        if ((obj_guess->flags08_guess & 6) != 0) {
            return false;
        }
        FUN_00403448_guess(obj_guess, str_guess, value_guess);
    }
    if (str_guess->Compare_guess(&key_guess.text_guess) != 0) {
        return false;
    }
    str_guess->Reset_guess();
    return true;
}

struct ListBase_guess {
    int field00_guess;
    int field04_guess;
    unsigned int size_guess;
    unsigned int IncSize_guess(unsigned int count_guess);
    unsigned int IncSize36FB_guess(unsigned int count_guess);
    unsigned int IncSize3760_guess(unsigned int count_guess);
    unsigned int IncSize37C5_guess(unsigned int count_guess);
};

// std::list size check: throws length_error past max_size. Three more copies follow for other T.
// FUNCTION: TITANIUM 0x00403653
unsigned int ListBase_guess::IncSize_guess(unsigned int count_guess) {
    if (0x6666666u - size_guess < count_guess) {
        ListString_guess text_guess("list<T> too long");
        throw ExceptionDerived_guess(text_guess);
    }
    size_guess += count_guess;
    return size_guess;
}

// Grows the list size by the given count, throwing length_error when that would pass max_size
// 0x35E50D7 (the limit for 76-byte elements); returns the new size.
// FUNCTION: TITANIUM 0x004036FB
unsigned int ListBase_guess::IncSize36FB_guess(unsigned int count_guess) {
    if (0x35e50d7u - size_guess < count_guess) {
        ListString_guess text_guess("list<T> too long");
        throw ExceptionDerived_guess(text_guess);
    }
    size_guess += count_guess;
    return size_guess;
}

// Grows the list size by the given count, throwing length_error when that would pass max_size
// 0x3333333 (the limit for 80-byte elements); returns the new size.
// FUNCTION: TITANIUM 0x00403760
unsigned int ListBase_guess::IncSize3760_guess(unsigned int count_guess) {
    if (0x3333333u - size_guess < count_guess) {
        ListString_guess text_guess("list<T> too long");
        throw ExceptionDerived_guess(text_guess);
    }
    size_guess += count_guess;
    return size_guess;
}

// Grows the list size by the given count, throwing length_error when that would pass max_size
// 0x1FFFFFF (the limit for 128-byte elements); returns the new size.
// FUNCTION: TITANIUM 0x004037C5
unsigned int ListBase_guess::IncSize37C5_guess(unsigned int count_guess) {
    if (0x1ffffffu - size_guess < count_guess) {
        ListString_guess text_guess("list<T> too long");
        throw ExceptionDerived_guess(text_guess);
    }
    size_guess += count_guess;
    return size_guess;
}

// Object of 0x30 bytes: 12 ints. Ctor at 0x00403864 takes three arguments.
struct SmallConstructed_guess {
    int data_guess[0xc];
    // EXTERNAL: TITANIUM 0x00403864 SmallConstructed_guess::SmallConstructed_guess
    SmallConstructed_guess(int, int, int);
};

// Allocates a 0x30-byte list node and constructs it from the three arguments (0x00403864); the memory is
// freed again if the constructor throws.
// FUNCTION: TITANIUM 0x00403886
SmallConstructed_guess* __stdcall FUN_00403886_guess(int first_guess, int second_guess, int third_guess) {
    SmallConstructed_guess* node_guess = (SmallConstructed_guess*)operator new(0x30);
    try {
        new (node_guess) SmallConstructed_guess(first_guess, second_guess, third_guess);
    } catch (...) {
        operator delete(node_guess);
        throw;
    }
    return node_guess;
}

// Object of 0x88 bytes: 34 ints. Ctor at 0x00403842 takes three arguments.
struct LargeConstructed_guess {
    int data_guess[0x22];
    // EXTERNAL: TITANIUM 0x00403842 LargeConstructed_guess::LargeConstructed_guess
    LargeConstructed_guess(int, int, int);
};

// Allocates a 0x88-byte list node and constructs it from the three arguments (0x00403842); the memory is
// freed again if the constructor throws.
// FUNCTION: TITANIUM 0x004038EB
LargeConstructed_guess* __stdcall FUN_004038EB_guess(int first_guess, int second_guess, int third_guess) {
    LargeConstructed_guess* node_guess = (LargeConstructed_guess*)operator new(0x88);
    try {
        new (node_guess) LargeConstructed_guess(first_guess, second_guess, third_guess);
    } catch (...) {
        operator delete(node_guess);
        throw;
    }
    return node_guess;
}

struct RangeNode_guess {
    RangeNode_guess* next_guess;
    RangeNode_guess* field04_guess;
    int field08_guess;
};

struct RangeOperation_guess {
    // EXTERNAL: TITANIUM 0x004039C5 RangeOperation_guess::Apply_guess
    void Apply_guess(void* context_guess, void* value_guess);
    struct Iterator_guess {
        RangeNode_guess* node_guess;
    };
    Iterator_guess Erase_guess(Iterator_guess where_guess);
    void Walk_guess(void* context_guess, RangeNode_guess* first_guess,
        RangeNode_guess* last_guess, void* unused_guess);
};

// Inserts the range [first, last) of another list's nodes: each value (node +8) goes to 0x004039C5 with
// the target position. Used by the list copy constructor 0x00403C0C.
// FUNCTION: TITANIUM 0x00403AAC
void RangeOperation_guess::Walk_guess(void* context_guess,
    RangeNode_guess* first_guess, RangeNode_guess* last_guess, void* unused_guess) {
    RangeNode_guess* next_guess = first_guess;
    try {
        for (; first_guess != last_guess; first_guess = first_guess->next_guess) {
            Apply_guess(context_guess, &first_guess->field08_guess);
        }
    } catch (...) {
        for (; next_guess != first_guess; next_guess = next_guess->next_guess) {
            Iterator_guess before_guess;
            before_guess.node_guess = ((RangeNode_guess*)context_guess)->field04_guess;
            Erase_guess(before_guess);
        }
        throw;
    }
}

// Standard library: list destructor (clears the list and frees its head node, 0x00403A5F).
// FUNCTION: TITANIUM 0x00403B1F
void __fastcall FUN_00403B1F(int* param_1) {
    return FUN_00403A5F_guess(param_1);
}

struct StringPairListNode_guess {
    StringPairListNode_guess* next_guess;
    StringPairListNode_guess* previous_guess;
    StringPair_guess value_guess;
};

struct StringPairList_guess {
    int field00_guess;
    StringPairListNode_guess* sentinel_guess;
    unsigned int count_guess;
    // EXTERNAL: TITANIUM 0x00403A23 StringPairList_guess::Erase_guess
    StringPairListNode_guess* Erase_guess(StringPairList_guess** owner, StringPairListNode_guess* node);
    // EXTERNAL: TITANIUM 0x00403B7C StringPairList_guess::Transfer_guess
    void Transfer_guess(StringPairListNode_guess* position, StringPairList_guess* other,
        StringPairListNode_guess* first, StringPairListNode_guess* last, unsigned int count);
    // EXTERNAL: TITANIUM 0x00404A20 StringPairList_guess::TransferAt4A20_guess
    void TransferAt4A20_guess(StringPairListNode_guess* position, StringPairList_guess* other,
        StringPairListNode_guess* first, StringPairListNode_guess* last, unsigned int count);
    // EXTERNAL: TITANIUM 0x00403BC4 StringPairList_guess::TransferAt403BC4_guess
    void TransferAt403BC4_guess(StringPairListNode_guess* position, StringPairList_guess* other,
        StringPairListNode_guess* first, StringPairListNode_guess* last, unsigned int count);
    // EXTERNAL: TITANIUM 0x00404001 StringPairList_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x004039F4 StringPairList_guess::Insert_guess
    void Insert_guess(StringPairListNode_guess* position_guess, StringPair_guess* value_guess);
    void RemoveEqual_guess(StringPair_guess* value);
    void Merge_guess(StringPairList_guess* other);
    void MergeLess_guess(StringPairList_guess* other);
    void MergeByValue_guess(StringPairList_guess* other);
};

// list::remove: erases every node whose string pair equals `value` (0x00402D70). The progression loader
// uses it so a re-read entry replaces the old one.
// FUNCTION: TITANIUM 0x00403B24
void StringPairList_guess::RemoveEqual_guess(StringPair_guess* value) {
    StringPairListNode_guess* sentinel = sentinel_guess;
    StringPairListNode_guess* node = sentinel->next_guess;
    while (node != sentinel) {
        if (node->value_guess.Equal_guess(value)) {
            StringPairList_guess* out_guess;
            node = Erase_guess(&out_guess, node)->next_guess;
        } else {
            node = node->next_guess;
        }
    }
}

// Standard library: list destructor (clears the list and frees its head node, 0x00403B60).
// FUNCTION: TITANIUM 0x00403B77
void __fastcall FUN_00403B77_guess(void* param_1) {
    return FUN_00403B60_guess(param_1);
}

struct ListContainer_guess {
    int head_guess;
    int count_guess;
    // EXTERNAL: TITANIUM 0x00403128 ListContainer_guess::ListContainer_guess
    ListContainer_guess();
};

struct StringCtor_guess {
    int data_guess[7];
    // EXTERNAL: TITANIUM 0x00402E5E StringCtor_guess::StringCtor_guess
    StringCtor_guess();
    // EXTERNAL: TITANIUM 0x0040B488 StringCtor_guess::~StringCtor_guess
    ~StringCtor_guess();
};

struct StringCleanupCtor_guess {
    int before_guess;
    StringCtor_guess first_guess;
    StringCtor_guess second_guess;
    int gap_guess;
    ListContainer_guess storage_guess;
    StringCleanupCtor_guess();
};

// Zeroes the dwords at +0 and +4.
// FUNCTION: TITANIUM 0x00403C6F
StringCleanupCtor_guess::StringCleanupCtor_guess() {
    gap_guess = 0;
    before_guess = 0;
}

// list::merge of a sorted `other` into this sorted list, ordered by the unsigned key in word 6 of each value.
// FUNCTION: TITANIUM 0x00403D0C
void StringPairList_guess::Merge_guess(StringPairList_guess* other) {
    if (other != this) {
        StringPairListNode_guess* other_sentinel = other->sentinel_guess;
        StringPairListNode_guess* other_node = other_sentinel->next_guess;
        StringPairListNode_guess* sentinel = sentinel_guess;
        StringPairListNode_guess* node = sentinel->next_guess;
        while (node != sentinel) {
            if (other_node == other_sentinel) {
                return;
            }
            if ((unsigned int)other_node->value_guess.value.data[6] <
                (unsigned int)node->value_guess.value.data[6]) {
                StringPairListNode_guess* next = other_node->next_guess;
                Transfer_guess(node, other, other_node, next, 1);
                other_node = next;
            } else {
                node = node->next_guess;
            }
        }
        if (other_node != other_sentinel) {
            Transfer_guess(sentinel, other, other_node, other_sentinel, other->count_guess);
        }
    }
}

// list::merge ordered by the element's LessThan (splice helper 0x00403BC4).
// FUNCTION: TITANIUM 0x00403DA5
void StringPairList_guess::MergeLess_guess(StringPairList_guess* other) {
    if (other != this) {
        StringPairListNode_guess* sentinel = sentinel_guess;
        StringPairListNode_guess* other_sentinel = other->sentinel_guess;
        StringPairListNode_guess* node = sentinel->next_guess;
        StringPairListNode_guess* other_node = other_sentinel->next_guess;
        while (node != sentinel) {
            if (other_node == other_sentinel) {
                return;
            }
            if (other_node->value_guess.LessThan_guess(&node->value_guess)) {
                StringPairListNode_guess* next = other_node->next_guess;
                TransferAt403BC4_guess(node, other, other_node, next, 1);
                other_node = next;
            } else {
                node = node->next_guess;
            }
        }
        if (other_node != other_sentinel) {
            TransferAt403BC4_guess(sentinel, other, other_node, other_sentinel, other->count_guess);
        }
    }
}

// Object of 0x54 bytes. Ctor at 0x00403E83 takes three arguments.
struct MediumConstructed_guess {
    int data_guess[0x15];
    // EXTERNAL: TITANIUM 0x00403E83 MediumConstructed_guess::MediumConstructed_guess
    MediumConstructed_guess(void*, int, void*);
};

// Allocates a 0x54-byte list node and constructs it from the three arguments (0x00403E83); the memory is
// freed again if the constructor throws.
// FUNCTION: TITANIUM 0x0040415D
MediumConstructed_guess* __stdcall FUN_0040415D_guess(void* storage_guess, int field04_guess,
    void* item_guess) {
    MediumConstructed_guess* node_guess = (MediumConstructed_guess*)operator new(0x54);
    try {
        new (node_guess) MediumConstructed_guess(storage_guess, field04_guess, item_guess);
    } catch (...) {
        operator delete(node_guess);
        throw;
    }
    return node_guess;
}

// EXTERNAL: TITANIUM 0x004036FB FUN_004036FB_guess
void __cdecl FUN_004036FB_guess(int value_guess);

struct StorageItem_guess {
    StorageItem_guess* next_guess;
    int field04_guess;
    int payload_guess;
};

struct StorageData_guess {
    int field00_guess;
    int field04_guess;
};

struct SubCopyIter_guess {
    StorageItem_guess* node_guess;
};

struct IterTag_guess {
};

struct StorageRange_guess {
    void InsertBefore_guess(void* storage_guess, void* item_guess);
    void Cleanup_guess(void* storage_guess, StorageItem_guess* first_guess,
        StorageItem_guess* last_guess, int unused_guess);
};

// 0x004044BA seen from the copy constructor: the same four words passed as list iterators and an empty tag.
struct SubCopyRange_guess {
    // EXTERNAL: TITANIUM 0x004044BA SubCopyRange_guess::Insert_guess
    void Insert_guess(SubCopyIter_guess where_guess, SubCopyIter_guess first_guess,
        SubCopyIter_guess last_guess, IterTag_guess tag_guess);
};

// Inserts a copy of `item` before the node `storage` (0x0040415D) and grows the list size by one
// (0x004036FB); the range insert 0x004044BA calls it per element.
// FUNCTION: TITANIUM 0x0040444F
// @early-stop: budget, structural ndiff=16
void StorageRange_guess::InsertBefore_guess(void* storage_guess, void* item_guess) {
    FUN_0040415D_guess(storage_guess,
        ((StorageData_guess*)storage_guess)->field04_guess, item_guess);
    FUN_004036FB_guess(1);
}

// Inserts copies of the range [first, last) before the node `storage`, one 0x54-byte node per element
// (0x0040444F).
// FUNCTION: TITANIUM 0x004044BA
// @early-stop: budget, normalised ndiff=0
void StorageRange_guess::Cleanup_guess(void* storage_guess,
    StorageItem_guess* first_guess, StorageItem_guess* last_guess, int unused_guess) {
    StorageRange_guess* owner_guess = this;
    StorageItem_guess* start_guess = first_guess;
    try {
        while (first_guess != last_guess) {
            owner_guess->InsertBefore_guess(storage_guess, &first_guess->payload_guess);
            first_guess = first_guess->next_guess;
        }
    } catch (...) {
        if (first_guess != start_guess) {
            owner_guess->InsertBefore_guess(storage_guess, &first_guess->payload_guess);
        }
    }
}

struct SubCopy_guess {
    int field00_guess;
    AllocatedNode_guess* sentinel_guess;
    unsigned int count_guess;
    SubCopy_guess(SubCopy_guess* other);
    SubCopyIter_guess Begin_guess() {
        SubCopyIter_guess it;
        it.node_guess = (StorageItem_guess*)sentinel_guess->field00_guess;
        return it;
    }
    SubCopyIter_guess End_guess() {
        SubCopyIter_guess it;
        it.node_guess = (StorageItem_guess*)sentinel_guess;
        return it;
    }
};

// List copy constructor for 0x54-byte nodes: a fresh empty sentinel (0x00402AAF), size 0, then every
// element of `other` is inserted (0x004044BA); the sentinel is freed if that throws.
// FUNCTION: TITANIUM 0x004045E0
SubCopy_guess::SubCopy_guess(SubCopy_guess* other) {
    AllocatedNode_guess* node = FUN_00402AAF_guess();
    count_guess = 0;
    try {
        sentinel_guess = node;
        IterTag_guess tag_guess;
        ((SubCopyRange_guess*)this)->Insert_guess(Begin_guess(),
            other->Begin_guess(), other->End_guess(), tag_guess);
    } catch (...) {
        operator delete(sentinel_guess);
        throw;
    }
}

// Standard library: list destructor (clears the list and frees its head node, 0x00404581).
// FUNCTION: TITANIUM 0x00404643
void __cdecl thunk_FUN_00404581() {
    return FUN_00404581_guess();
}

struct RecordCopy_guess {
    int key_guess;
    StringCopy_guess first_guess;
    StringCopy_guess second_guess;
    int field3c_guess;
    int field40_guess;
    SubCopy_guess sub_guess;
    RecordCopy_guess(RecordCopy_guess* other);
};

// Copy constructor for a keyed record: key, both strings, the dwords at +0x3C and +0x40 and the
// sub-list.
// FUNCTION: TITANIUM 0x004046E1
RecordCopy_guess::RecordCopy_guess(RecordCopy_guess* other)
    : key_guess(other->key_guess), first_guess(&other->first_guess),
      second_guess(&other->second_guess), field3c_guess(other->field3c_guess),
      field40_guess(other->field40_guess), sub_guess(&other->sub_guess) {
}

struct StringCleanupPairInit_guess {
    int field00_guess;
    StringCtor_guess first_guess;
    StringCtor_guess second_guess;
    int field3c_guess;
    int field40_guess;
    StringFreeStorage_guess storage_guess;
    StringCleanupPairInit_guess();
};

// Zeroes the dwords at +0, +0x3C and +0x40.
// FUNCTION: TITANIUM 0x00404744
StringCleanupPairInit_guess::StringCleanupPairInit_guess() {
    field40_guess = 0;
    field3c_guess = 0;
    field00_guess = 0;
}

// Releases a record's members: its sub-list storage and both strings.
// FUNCTION: TITANIUM 0x0040478F
void StringCleanupPair_guess::Cleanup_guess() {
    storage_guess.Free_guess();
    second_guess._Tidy(true, 0);
    first_guess._Tidy(true, 0);
}

struct StringCleanupPairView_guess {
    int padding_guess[2];
    StringCleanupPair_guess pair_guess;
    void Cleanup_guess();
};

// Releases the record held by this node (0x0040478F).
// FUNCTION: TITANIUM 0x004047D6
void StringCleanupPairView_guess::Cleanup_guess() {
    pair_guess.Cleanup_guess();
}

struct ParserString_guess {
    int field00_guess;
    union {
        char inline_guess[16];
        char* heap_guess;
    } buffer_guess;
    int length_guess;
    unsigned int capacity_guess;
    // EXTERNAL: TITANIUM 0x00402505 ParserString_guess::Eos_guess
    void Eos_guess(unsigned int length_guess);
    // EXTERNAL: TITANIUM 0x0040291E ParserString_guess::Tidy_guess
    void Tidy_guess(bool free_guess, unsigned int copy_guess);
};

struct StreamCleanup_guess {
    // EXTERNAL: TITANIUM 0x0040271A StreamCleanup_guess::Close_guess
    void Close_guess();
    // EXTERNAL: TITANIUM 0x00623D8D StreamCleanup_guess::Destroy_guess
    void Destroy_guess();
};

struct StringStream_guess {
    int padding00_guess[0x14];
    int state_guess[0x10];
    // EXTERNAL: TITANIUM 0x00403317 StringStream_guess::StringStream_guess
    StringStream_guess(const ListString_guess& text_guess, int mode_guess,
        int flags_guess);
};

struct BranchTemplateList_guess {
    int field00_guess;
    int field04_guess;
    // EXTERNAL: TITANIUM 0x004039C5 BranchTemplateList_guess::Add_guess
    void Add_guess(int count_guess, StringExtended_guess* value_guess);
    // EXTERNAL: TITANIUM 0x00403EA5 BranchTemplateList_guess::Destroy_guess
    void Destroy_guess();
};

struct ProgressionBranches_guess {
    int field00_guess;
    int field04_guess;
    // EXTERNAL: TITANIUM 0x0040444F ProgressionBranches_guess::Add_guess
    void Add_guess(int count_guess, StringCleanupCtor_guess* value_guess);
    // EXTERNAL: TITANIUM 0x004047DE ProgressionBranches_guess::Destroy_guess
    void Destroy_guess();
};

struct ProgressionMap_guess {
    int field00_guess;
    int count_guess;
    int field08_guess[4];
    // EXTERNAL: TITANIUM 0x004049CE ProgressionMap_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0040499F ProgressionMap_guess::Insert_guess
    void Insert_guess(int count_guess, StringCleanupPairInit_guess* data_guess);
    // EXTERNAL: TITANIUM 0x00404B8B ProgressionMap_guess::Destroy_guess
    void Destroy_guess();
};

struct InputRecord_guess {
    int kind_guess;
    int error_guess;
    int field08_guess;
    char text_guess[1];
};

struct AllocTarget_guess {
    int data_guess[0x16];
    // EXTERNAL: TITANIUM 0x004047B4 AllocTarget_guess::AllocTarget_guess
    AllocTarget_guess(int, int, int);
};

// Allocates a 0x58-byte list node and runs its constructor 0x004047B4 with the three arguments; returns
// null instead of throwing when that fails.
// FUNCTION: TITANIUM 0x0040493A
// @early-stop: budget, structural ndiff=14
AllocTarget_guess* __stdcall FUN_0040493A_guess(int a_guess, int b_guess, int c_guess) {
    AllocTarget_guess* result_guess;
    try {
        result_guess = new AllocTarget_guess(a_guess, b_guess, c_guess);
    } catch (...) {
        result_guess = 0;
    }
    return result_guess;
}

// Standard library: list destructor (clears the list and frees its head node, 0x00404A04).
// FUNCTION: TITANIUM 0x00404A1B
void __fastcall FUN_00404A1B_guess(void* param_1) {
    return FUN_00404A04_guess(param_1);
}

struct StorageChainBase_guess {
    int field00_guess[4];
    // EXTERNAL: TITANIUM 0x00403115 StorageChainBase_guess::StorageChainBase_guess
    StorageChainBase_guess();
    // EXTERNAL: TITANIUM 0x00402A80 StorageChainBase_guess::~StorageChainBase_guess
    ~StorageChainBase_guess();
};

struct StorageChainPart10_guess {
    int field00_guess[3];
    // EXTERNAL: TITANIUM 0x0040314E StorageChainPart10_guess::StorageChainPart10_guess
    StorageChainPart10_guess();
    // EXTERNAL: TITANIUM 0x00404A04 StorageChainPart10_guess::~StorageChainPart10_guess
    ~StorageChainPart10_guess();
};

struct StorageChainPart1c_guess {
    int field00_guess[2];
    // EXTERNAL: TITANIUM 0x00403161 StorageChainPart1c_guess::StorageChainPart1c_guess
    StorageChainPart1c_guess();
    // EXTERNAL: TITANIUM 0x00403A5F StorageChainPart1c_guess::~StorageChainPart1c_guess
    ~StorageChainPart1c_guess();
};

struct StorageChainConstructor_guess : StorageChainBase_guess {
    StorageChainPart10_guess field10_guess;
    StorageChainPart1c_guess field1c_guess;
    StorageChainConstructor_guess();
};

// Constructor: three empty lists at +0, +0x10 and +0x1C (0x00403115, 0x0040314E, 0x00403161).
// FUNCTION: TITANIUM 0x00404A68
StorageChainConstructor_guess::StorageChainConstructor_guess()
    : StorageChainBase_guess(), field10_guess(), field1c_guess() {
}

struct StorageChain_guess {
    int field00_guess[4];
    int field10_guess[3];
    int field1c_guess[2];
};

// Destructor: destroys the lists at +0x1C, +0x10 and +0 (0x00403A5F, 0x00404A04, 0x00402A80).
// FUNCTION: TITANIUM 0x00404AA5
void __fastcall DestroyStorageChain_guess(StorageChain_guess* self) {
    FUN_00403A5F_guess(self->field1c_guess);
    FUN_00404A04_guess(self->field10_guess);
    return ((String_guess*)self)->FreeStorage_guess();
}

// list::merge ordered by the element's LessThan; same shape as 0x00403DA5 with another splice helper.
// FUNCTION: TITANIUM 0x00404AF1
void StringPairList_guess::MergeByValue_guess(StringPairList_guess* other) {
    if (other != this) {
        StringPairListNode_guess* sentinel = sentinel_guess;
        StringPairListNode_guess* other_sentinel = other->sentinel_guess;
        StringPairListNode_guess* node = sentinel->next_guess;
        StringPairListNode_guess* other_node = other_sentinel->next_guess;
        while (node != sentinel) {
            if (other_node == other_sentinel) {
                return;
            }
            if (other_node->value_guess.LessThan_guess(&node->value_guess)) {
                StringPairListNode_guess* next = other_node->next_guess;
                TransferAt4A20_guess(node, other, other_node, next, 1);
                other_node = next;
            } else {
                node = node->next_guess;
            }
        }
        if (other_node != other_sentinel) {
            TransferAt4A20_guess(sentinel, other, other_node, other_sentinel, other->count_guess);
        }
    }
}


struct Sub1C_guess {
    // EXTERNAL: TITANIUM 0x0040398F Sub1C_guess::Release_guess
    void Release_guess();
};

struct Holder1C_guess {
    int field00_guess[7];
    Sub1C_guess sub1c_guess;
    // EXTERNAL: TITANIUM 0x00402D37 Holder1C_guess::Finish_guess
    void Finish_guess(int* status_guess);
    void Process_guess(int a, int b);
    void Run_guess(int a, int b);
};

// Replaces the progression list with a new one.
// FUNCTION: TITANIUM 0x0040452D
void Holder1C_guess::Run_guess(int a, int b) {
    sub1c_guess.Release_guess();
    Process_guess(a, b);
}

struct ProgressionSource_guess {
    int expectedCount_guess;
    char text_guess[1];
};

struct ProgressionRecord_guess : StringOwner_guess {
    int value_guess;
};

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format_guess, int count_guess, int expected_guess);

// Parses "PROGRESSION" records into the list, replacing equal ones; logs "Monster Alt: did not receive the
// number of progressions expected, %d instead of %d" when the count is off.
// FUNCTION: TITANIUM 0x004041C2
// @early-stop: unknown, diff ndiff=163
void Holder1C_guess::Process_guess(int a, int b) {
    ProgressionSource_guess* source_guess = (ProgressionSource_guess*)a;
    StringStream_guess stream_guess(ListString_guess(source_guess->text_guess), 1, 1);
    ParserString_guess section_guess;
    ParserString_guess value_guess;
    section_guess.capacity_guess = 0xf;
    section_guess.Eos_guess(0);
    value_guess.capacity_guess = 0xf;
    value_guess.Eos_guess(0);
    int progressionCount_guess = 0;
    while (MatchSectionTag_guess((VObject_guess*)&stream_guess,
        (String_guess*)&section_guess, "PROGRESSION", 7)) {
        ++progressionCount_guess;
        ProgressionRecord_guess progression_guess;
        FUN_00403448_guess((VObject_guess*)&stream_guess, (String_guess*)&value_guess, 7);
        progression_guess.before = atoi(value_guess.capacity_guess < 0x10
            ? value_guess.buffer_guess.inline_guess
            : value_guess.buffer_guess.heap_guess);
        FUN_00403448_guess((VObject_guess*)&stream_guess,
            (String_guess*)&progression_guess.first, 7);
        FUN_00403448_guess((VObject_guess*)&stream_guess,
            (String_guess*)&progression_guess.second, 7);
        FUN_00403448_guess((VObject_guess*)&stream_guess, (String_guess*)&value_guess, 7);
        progression_guess.gap[0] = atoi(value_guess.capacity_guess < 0x10
            ? value_guess.buffer_guess.inline_guess
            : value_guess.buffer_guess.heap_guess);
        FUN_00403448_guess((VObject_guess*)&stream_guess, (String_guess*)&value_guess, 7);
        progression_guess.gap[1] = atoi(value_guess.capacity_guess < 0x10
            ? value_guess.buffer_guess.inline_guess
            : value_guess.buffer_guess.heap_guess);
        FUN_00403448_guess((VObject_guess*)&stream_guess,
            (String_guess*)&progression_guess.third, 7);
        FUN_00403448_guess((VObject_guess*)&stream_guess,
            (String_guess*)&progression_guess.fourth, 7);
        FUN_00403448_guess((VObject_guess*)&stream_guess, (String_guess*)&value_guess, 7);
        progression_guess.value_guess = atoi(value_guess.capacity_guess < 0x10
            ? value_guess.buffer_guess.inline_guess
            : value_guess.buffer_guess.heap_guess);
        ((StringPairList_guess*)&sub1c_guess)->RemoveEqual_guess(
            (StringPair_guess*)&progression_guess);
        StringPairList_guess* list_guess = (StringPairList_guess*)&sub1c_guess;
        list_guess->Insert_guess(list_guess->sentinel_guess,
            (StringPair_guess*)&progression_guess);
    }
    ((StringPairList_guess*)&sub1c_guess)->Clear_guess();
    if (progressionCount_guess != source_guess->expectedCount_guess) {
        FUN_00574110_guess(
            "Monster Alt: did not receive the number of progressions expected, %d instead of %d",
            progressionCount_guess, source_guess->expectedCount_guess);
    }
    int status_guess = 2;
    Finish_guess(&status_guess);
    value_guess.Tidy_guess(true, 0);
    section_guess.Tidy_guess(true, 0);
    StreamCleanup_guess* cleanup_guess = (StreamCleanup_guess*)&stream_guess.state_guess[0];
    cleanup_guess->Close_guess();
    cleanup_guess->Destroy_guess();
}

struct DispatchOwner_guess {
    int prefix_guess[3];
    int kind_guess;
    ProgressionMap_guess map_guess;
    int field28_guess;
    void Unit402DD4_guess(int first_guess, int second_guess);
    void Send_402D37_guess(int* record_guess);
    // EXTERNAL: TITANIUM 0x00404CE7 DispatchOwner_guess::ParseProgressionData_guess
    void ParseProgressionData_guess(InputRecord_guess* input_guess, int mode_guess);
    void Dispatch_guess(int key_guess, int first_guess, int second_guess);
};

struct DispatchQueueView_guess {
    int field00_guess;
    DispatchListNode_guess* list_guess;
};

// Tells every listener in this list about `record` (for-each 0x00402CF2 over the list at +4); the
// shroud record handlers (messages 0x18CB, 0x1573) and the mail link code call it.
// FUNCTION: TITANIUM 0x00402D37
// @early-stop: budget, structural ndiff=7
void DispatchOwner_guess::Send_402D37_guess(int* record_guess) {
    int result[2];
    int second = (int)record_guess;
    DispatchQueueView_guess* queue = (DispatchQueueView_guess*)this;
    DispatchListNode_guess* list = queue->list_guess;
    DispatchListNode_guess* node = list->next_guess;
    InvokeEach_guess((DispatchPair_guess*)result, node, list, (int)this, second);
}

// Code 8: forwards the payload's first two dwords to every listener as record type 4.
// FUNCTION: TITANIUM 0x00402DD4
void DispatchOwner_guess::Unit402DD4_guess(int first_guess, int second_guess) {
    if (second_guess == 8) {
        int* source_guess = (int*)first_guess;
        int record_guess[3];
        record_guess[0] = 4;
        record_guess[1] = source_guess[0];
        record_guess[2] = source_guess[1];
        Send_402D37_guess(record_guess);
    }
}

// The shroud selection list: PROGRESSION records, each with BRANCH and TEMPLATE records (names and levels);
// an error flag instead shows "You must empty your Shroud Bank before you can polymorph
// again." (4557).
// FUNCTION: TITANIUM 0x00404CE7
// @early-stop: budget, diff ndiff=276
void DispatchOwner_guess::ParseProgressionData_guess(InputRecord_guess* input_guess,
    int mode_guess) {
    kind_guess = input_guess->kind_guess;
    map_guess.Clear_guess();
    if (input_guess->error_guess != 0) {
        pEverQuest->dsp_chat(
                pStringTable->getString(0x11cd, 0),
                0xd, 1);
    } else {
        int input_text_storage_guess[7];
        new (input_text_storage_guess) ListString_guess(input_guess->text_guess);
        StringStream_guess stream_guess(
            *(ListString_guess*)input_text_storage_guess, 1, 1);
        ((ListString_guess*)input_text_storage_guess)->text_guess._Tidy(true, 0);
        ParserString_guess section_guess;
        ParserString_guess value_guess;
        section_guess.capacity_guess = 0xf;
        section_guess.Eos_guess(0);
        value_guess.capacity_guess = 0xf;
        value_guess.Eos_guess(0);
        while (MatchSectionTag_guess((VObject_guess*)&stream_guess,
            (String_guess*)&section_guess, "PROGRESSION", 7)) {
            int progression_storage_guess[0x13];
            StringCleanupPairInit_guess* progression_guess =
                new (progression_storage_guess) StringCleanupPairInit_guess;
            FUN_00403448_guess((VObject_guess*)&stream_guess,
                (String_guess*)&value_guess, 7);
            progression_guess->field00_guess = atoi(
                value_guess.capacity_guess < 0x10
                    ? value_guess.buffer_guess.inline_guess
                    : value_guess.buffer_guess.heap_guess);
            FUN_00403448_guess((VObject_guess*)&stream_guess,
                (String_guess*)&progression_guess->first_guess, 7);
            FUN_00403448_guess((VObject_guess*)&stream_guess,
                (String_guess*)&progression_guess->second_guess, 7);
            while (MatchSectionTag_guess((VObject_guess*)&stream_guess,
                (String_guess*)&section_guess, "BRANCH", 7)) {
                int branch_storage_guess[0x12];
                StringCleanupCtor_guess* branch_guess =
                    new (branch_storage_guess) StringCleanupCtor_guess;
                FUN_00403448_guess((VObject_guess*)&stream_guess,
                    (String_guess*)&value_guess, 7);
                branch_guess->before_guess = atoi(
                    value_guess.capacity_guess < 0x10
                        ? value_guess.buffer_guess.inline_guess
                        : value_guess.buffer_guess.heap_guess);
                FUN_00403448_guess((VObject_guess*)&stream_guess,
                    (String_guess*)&branch_guess->first_guess, 7);
                FUN_00403448_guess((VObject_guess*)&stream_guess,
                    (String_guess*)&branch_guess->second_guess, 7);
                FUN_00403448_guess((VObject_guess*)&stream_guess,
                    (String_guess*)&value_guess, 7);
                branch_guess->gap_guess = atoi(
                    value_guess.capacity_guess < 0x10
                        ? value_guess.buffer_guess.inline_guess
                        : value_guess.buffer_guess.heap_guess);
                ++progression_guess->field40_guess;
                if (branch_guess->gap_guess == 100) {
                    ++progression_guess->field3c_guess;
                }
                BranchTemplateList_guess* templates_guess =
                    (BranchTemplateList_guess*)&branch_guess->storage_guess;
                while (MatchSectionTag_guess((VObject_guess*)&stream_guess,
                    (String_guess*)&section_guess, "TEMPLATE", 7)) {
                    StringExtended_guess template_guess;
                    FUN_00403448_guess((VObject_guess*)&stream_guess,
                        (String_guess*)&template_guess, 7);
                    FUN_00403448_guess((VObject_guess*)&stream_guess,
                        (String_guess*)&value_guess, 7);
                    template_guess.field1c_guess = atoi(
                        value_guess.capacity_guess < 0x10
                            ? value_guess.buffer_guess.inline_guess
                            : value_guess.buffer_guess.heap_guess);
                    FUN_00403448_guess((VObject_guess*)&stream_guess,
                        (String_guess*)&value_guess, 7);
                    template_guess.field20_guess = atoi(
                        value_guess.capacity_guess < 0x10
                            ? value_guess.buffer_guess.inline_guess
                            : value_guess.buffer_guess.heap_guess);
                    FUN_00403448_guess((VObject_guess*)&stream_guess,
                        (String_guess*)&value_guess, 7);
                    template_guess.field24_guess = atoi(
                        value_guess.capacity_guess < 0x10
                            ? value_guess.buffer_guess.inline_guess
                            : value_guess.buffer_guess.heap_guess) != 0;
                    templates_guess->Add_guess(templates_guess->field04_guess,
                        &template_guess);
                    template_guess._Tidy(true, 0);
                }
                templates_guess->Destroy_guess();
                ((ProgressionBranches_guess*)&progression_guess->storage_guess)
                    ->Add_guess(
                        ((ProgressionBranches_guess*)&progression_guess->storage_guess)->field04_guess,
                        branch_guess);
                ((StringCleanupOwner_guess*)branch_guess)->Cleanup_guess();
            }
            ((ProgressionBranches_guess*)&progression_guess->storage_guess)
                ->Destroy_guess();
            map_guess.Insert_guess(map_guess.count_guess, progression_guess);
            ((StringCleanupPair_guess*)progression_guess)->Cleanup_guess();
        }
        map_guess.Destroy_guess();
        input_guess = 0;
        Send_402D37_guess((int*)&input_guess);
        value_guess.Tidy_guess(true, 0);
        section_guess.Tidy_guess(true, 0);
        StreamCleanup_guess* stream_cleanup_guess =
            (StreamCleanup_guess*)&stream_guess.state_guess[0];
        stream_cleanup_guess->Close_guess();
        stream_cleanup_guess->Destroy_guess();
    }
}

// Routes the shroud messages by id: 0x7F63 progression list (fresh), 0x4625 progression update, 0x65B1 the
// selection list, 0x6D32 a pair notice, 0x455F the Shroud Bank notice, 0x18CB/0x1573 records. EQEmu's
// Titanium list names only 0x7F63 (as OP_LockoutTimerInfo).
// FUNCTION: TITANIUM 0x004050D0
void DispatchOwner_guess::Dispatch_guess(int key_guess, int first_guess, int second_guess) {
    switch (key_guess) {
    case 0x7f63:
        ((Holder1C_guess*)this)->Run_guess(first_guess, second_guess);
        break;
    case 0x6d32:
        Unit402DD4_guess(first_guess, second_guess);
        break;
    case 0x65b1:
        ParseProgressionData_guess((InputRecord_guess*)first_guess, second_guess);
        break;
    case 0x4625:
        ((Holder1C_guess*)this)->Process_guess(first_guess, second_guess);
        break;
    case 0x455f:
        ReportShroudBankNotOpened_guess();
        break;
    case 0x18cb:
        ((RecordSink_guess*)this)->Pair_guess((PairRange_guess*)first_guess, second_guess);
        break;
    case 0x1573:
        ((RecordSink_guess*)this)->Store_guess((ValueRecord_guess*)first_guess, second_guess);
        break;
    }
}
