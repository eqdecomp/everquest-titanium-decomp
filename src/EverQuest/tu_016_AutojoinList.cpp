// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 16: a hint from compare/tumap.py.
// Auto-join chat channels: a file of "Channel=name,rule,..." lines whose rules (level range, class, race
// list) decide which channels the character joins or leaves via ";join"/";leave". Also the evolving-item
// toggle request and update handler, and the prime helpers the client's hash tables size themselves with.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CItemExpTransferWnd.h"

struct Object42631_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    unsigned char field0C_guess;
};

struct Argument4243E1_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
};

struct Object4243E1_guess {
    int field00_guess;
    int field04_guess;

    int Check_guess(Argument4243E1_guess* argument_guess);
};

struct Object42416A_guess {
    void* vtable_guess;
    int field04_guess;
    int field08_guess;
    unsigned char field0C_guess[8];
    unsigned char field14_guess[8];

    Object42416A_guess* Initialize_guess();
    bool Parse_guess(char* input_guess);
    char Check_guess(int parameter_guess);
};

// EXTERNAL: TITANIUM 0x006411CC ??_7ParsePredicate424824_guess@@6B@
struct ParsePredicate424824_guess {
    virtual ParsePredicate424824_guess* Dispose_guess(unsigned char deleteFlag_guess);
    virtual bool Parse_guess(char* input_guess);

    ~ParsePredicate424824_guess() {}
};

struct ClassRule_guess;

// EXTERNAL: TITANIUM 0x006411D8 ??_7LevelRangeRule_guess@@6B@
struct LevelRangeRule_guess : ParsePredicate424824_guess {
    int first_guess;
    int last_guess;

    LevelRangeRule_guess() : first_guess(0), last_guess(0) {}
    virtual bool Parse_guess(char* input_guess);
    bool Contains_guess(ClassRule_guess* value_guess);
};

// EXTERNAL: TITANIUM 0x006411E4 ??_7ClassRule_guess@@6B@
struct ClassRule_guess : ParsePredicate424824_guess {
    int classId_0004_guess;

    ClassRule_guess() : classId_0004_guess(-1) {}
    virtual bool Parse_guess(char* input_guess);
};

struct Connection42419C_guess {
    unsigned char padding00_guess[0x80];
    int field80_guess;
    int field84_guess;
};

struct Message42419C_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    int field0C_guess;
    int field10_guess;
    unsigned char field14_guess;
};

struct Connection4241DD_guess {
    unsigned char padding00_guess[0x70];
    double field70_guess;
    unsigned char field78_guess;
    unsigned char padding79_guess[0x80 - 0x79];
    int field80_guess;
    int field84_guess;
};

struct Manager905D00_guess {
    // EXTERNAL: TITANIUM 0x004BE2FC Manager905D00_guess::Find_guess
    Connection4241DD_guess* Find_guess(int first_guess, int second_guess, int zero_guess);
};

#define g_manager905D00_guess EQ_GLOBAL(Manager905D00_guess*, 0x00905D00)



struct Object4247F5_guess {
    void* vtable_guess;
    void* field04_guess;

    void Clear_guess();
    Object4247F5_guess* Dispose_guess(unsigned char deleteFlag_guess);
};

struct Object4243FC_guess {
    void* vtable_guess;

    Object4243FC_guess* Dispose_guess(unsigned char deleteFlag_guess);
};

struct Object424504Item_guess {
    unsigned char padding00_guess[0x14];
    unsigned char field14_guess;
};

struct Object424504Entry_guess {
    Object424504Item_guess* object_guess;
};

struct Source4245_guess;

struct Object424504Collection_guess {
    int count_guess;

    // EXTERNAL: TITANIUM 0x004EB924 Object424504Collection_guess::Get_guess
    Object424504Entry_guess* Get_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0048F513 Object424504Collection_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x00447C66 Object424504Collection_guess::Insert_guess
    void Insert_guess(int* valueAddress_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0050F3F6 ??1Object424504Collection_guess@@QAE@XZ
    ~Object424504Collection_guess();

    void ClearItems_guess();
    void UpdateAutoJoinChannels_guess(Source4245_guess* source_guess);
};

struct Element4244_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual char Evaluate_guess(int parameter_guess);
};

struct Lookup4244BAArgument_guess {
    unsigned char padding00_guess[0x0c];
    int value0C_guess;
};

struct Lookup4244BA_guess {
    // EXTERNAL: TITANIUM 0x004FF9C9 Lookup4244BA_guess::Find_guess
    int Find_guess(int value_guess);
};

struct Object4244BA_guess {
    unsigned char padding00_guess[4];
    Lookup4244BA_guess lookup_guess;

    bool Check_guess(Lookup4244BAArgument_guess* argument_guess);
};

extern "C" unsigned int __cdecl strlen(const char* input_guess);
// EXTERNAL: TITANIUM 0x0060E3A3 atol
extern "C" long __cdecl atol(const char* input_guess);

// EXTERNAL: TITANIUM 0x005769E0 FUN_005769E0_guess
int __cdecl FUN_005769E0_guess(char* input_guess, char* output_guess, int size_guess, int delimiter_guess, int flag_guess);

// EXTERNAL: TITANIUM 0x004C9745 FUN_004C9745_guess
void __fastcall FUN_004C9745_guess(void** value_guess);

struct DivisorValue_guess {
    int value_guess;
};

// Scalar deleting destructor of a channel's rule object (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004242CA
ParsePredicate424824_guess* ParsePredicate424824_guess::Dispose_guess(unsigned char deleteFlag_guess) {
    this->~ParsePredicate424824_guess();
    if ((deleteFlag_guess & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

// Value-list rule check: true when the character's race (info +0xC) is in the rule's set.
// FUNCTION: TITANIUM 0x004244BA
bool Object4244BA_guess::Check_guess(Lookup4244BAArgument_guess* argument_guess) {
    return lookup_guess.Find_guess(argument_guess->value0C_guess) != 0;
}

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x004242C3 SetObjectVtableExternal_guess
void __fastcall SetObjectVtableExternal_guess(void** object_guess);

// Constructor of the object at 0x0079DBA0 (made in UI setup 0x0043EFDD): vtable 0x00641158, whose
// first slot copies the character's +0xFA4/+0xFA8 counts to +4/+8. Zeroes +4, +8 and the 8-byte
// blocks at +0xC and +0x14.
// FUNCTION: TITANIUM 0x0042416A
Object42416A_guess* Object42416A_guess::Initialize_guess() {
    field04_guess = 0;
    field08_guess = 0;
    vtable_guess = &EQ_GLOBAL(int, 0x00641158);
    memset(field0C_guess, 0, 8);
    memset(field14_guess, 0, 8);
    return this;
}

// Sends message 0x7E61 (no EQEmu name; 0x18 bytes): type 0, the item's two key ints (+0x80, +0x84), and
// `flag_guess` as the new on/off state.
// FUNCTION: TITANIUM 0x0042419C
void __cdecl RequestEvolvingItemToggle_guess(Connection42419C_guess* connection_guess, unsigned char flag_guess) {
    Message42419C_guess message_guess;
    message_guess.field00_guess = 0;
    message_guess.field08_guess = connection_guess->field80_guess;
    message_guess.field0C_guess = connection_guess->field84_guess;
    message_guess.field14_guess = flag_guess;
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0x7e61, &message_guess, 0x18, 1);
}

// Evolving-item message from the server. Type 0: stores the item's state (+0x78) and progress (+0x70, as a
// double), then refreshes it in the item experience transfer window (0x991BA8) and flags the inventory window
// (0x850C34 +0x264); type 1 shows that transfer window (vtable +0xC0, SetVisible); type 2 passes the message
// to its preview (HandlePreview_guess).
// FUNCTION: TITANIUM 0x004241DD
void __cdecl Handle_EvolvingItemUpdate_guess(Message42419C_guess* message_guess) {
    switch (message_guess->field00_guess) {
    case 0:
        {
        Connection4241DD_guess* connection_guess =
            g_manager905D00_guess->Find_guess(message_guess->field08_guess, message_guess->field0C_guess, 0);
        if (connection_guess != 0) {
            connection_guess->field78_guess = message_guess->field14_guess;
            connection_guess->field70_guess = (double)message_guess->field10_guess;
            if (pinstCInventoryWnd_guess != 0) {
                pinstCInventoryWnd_guess->dirty_guess = 1;
            }
            if (pinstCItemExpTransferWnd_guess != 0) {
                pinstCItemExpTransferWnd_guess->InvalidateItem_guess(connection_guess->field80_guess,
                                                      connection_guess->field84_guess);
            }
        }
        }
        break;
    case 1:
        if (pinstCItemExpTransferWnd_guess != 0) {
            pinstCItemExpTransferWnd_guess->Show(1, 1);
        }
        break;
    case 2:
        if (pinstCItemExpTransferWnd_guess != 0) {
            pinstCItemExpTransferWnd_guess->HandlePreview_guess(message_guess);
        }
        break;
    }
}

// Prime test by trial division with the 1000 primes at 0x696060, but it answers true as soon as p * p >=
// the value, before dividing by p: prime squares (9, 25, ...) pass as well.
// FUNCTION: TITANIUM 0x0042426A
char __cdecl PassesPrimeScreen_guess(int value_guess) {
    unsigned int offset_guess = 0;
    do {
        if (((DivisorValue_guess*)(EQ_ARRAY(char, 0x00696060) + offset_guess))->value_guess *
            ((DivisorValue_guess*)(EQ_ARRAY(char, 0x00696060) + offset_guess))->value_guess >= value_guess) {
            break;
        }
        if (value_guess % ((DivisorValue_guess*)(EQ_ARRAY(char, 0x00696060) + offset_guess))->value_guess == 0) {
            return 0;
        }
        offset_guess += 4;
    } while (offset_guess < 4000);
    return 1;
}

// Smallest odd number >= `value` that 0x0042426A accepts; hash tables size their bucket arrays with
// it. The test passes primes, but also 1 and prime squares (9, 25, ...).
// FUNCTION: TITANIUM 0x0042429E
int __cdecl NextPrimeCandidate_guess(int value_guess) {
    if (value_guess % 2 == 0) {
        ++value_guess;
    }
    while (PassesPrimeScreen_guess(value_guess) == 0) {
        value_guess += 2;
    }
    return value_guess;
}

// Restores the base rule vtable (0x006411CC); the rule destructors end with it.
// FUNCTION: TITANIUM 0x004242C3
void __fastcall SetObjectVtable_guess(void** object) {
    *object = &EQ_GLOBAL(int, 0x006411CC);
}

// Rule 0, a level range "first^last"; valid when first <= last and last is not 0.
// FUNCTION: TITANIUM 0x004242E7
bool LevelRangeRule_guess::Parse_guess(char* input_guess) {
    char buffer_guess[256];
    input_guess += FUN_005769E0_guess(input_guess, buffer_guess, 0x100, 0x5e, 1);
    first_guess = (int)atol(buffer_guess);
    FUN_005769E0_guess(input_guess, buffer_guess, 0x100, 0x5e, 1);
    last_guess = (int)atol(buffer_guess);
    return first_guess <= last_guess && last_guess != 0;
}

// Level-range rule check: true when the character's level (info +4) is within first..last.
// FUNCTION: TITANIUM 0x0042436B
bool LevelRangeRule_guess::Contains_guess(ClassRule_guess* value_guess) {
    int number_guess = value_guess->classId_0004_guess;
    return number_guess >= first_guess && number_guess <= last_guess;
}

// Rule 1, a single class id; valid for 0-34.
// FUNCTION: TITANIUM 0x00424386
bool ClassRule_guess::Parse_guess(char* input_guess) {
    char buffer_guess[256];
    FUN_005769E0_guess(input_guess, buffer_guess, 0x100, 0x5e, 1);
    classId_0004_guess = (int)atol(buffer_guess);
    return classId_0004_guess >= 0 && classId_0004_guess < 0x23;
}

// Matches when the character's class equals the rule's and the info's first value (+0x1228) is 0.
// FUNCTION: TITANIUM 0x004243E1
int Object4243E1_guess::Check_guess(Argument4243E1_guess* argument_guess) {
    if (argument_guess->field00_guess == 0 && argument_guess->field08_guess == field04_guess) {
        return 1;
    }
    return 0;
}

// Scalar deleting destructor of the class rule (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004243FC
Object4243FC_guess* Object4243FC_guess::Dispose_guess(unsigned char deleteFlag_guess) {
    SetObjectVtableExternal_guess((void**)this);
    if ((deleteFlag_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// A value list "a^b^..." (probably rule 2, races): every non-zero value goes into the set; valid when it
// holds one.
// FUNCTION: TITANIUM 0x00424418
bool Object42416A_guess::Parse_guess(char* input_guess) {
    char buffer_guess[256];
    int length_guess = strlen(input_guess);
    ((Object424504Collection_guess*)&field04_guess)->Prepare_guess();
    int index_guess = 0;
    int count_guess = 0;
    int value_guess;
    if (length_guess > 0) {
        do {
            index_guess += FUN_005769E0_guess(input_guess + index_guess, buffer_guess, 0x100, 0x5e, 1);
            value_guess = (int)atol(buffer_guess);
            if (value_guess != 0) {
                ((Object424504Collection_guess*)&field04_guess)->Insert_guess(&value_guess, value_guess);
                ++count_guess;
            }
        } while (index_guess < length_guess);
    }
    return count_guess > 0;
}

// A channel's rules all have to match `parameter_guess` (the character info built by FUN_00424524_guess).
// FUNCTION: TITANIUM 0x004244D2
char Object42416A_guess::Check_guess(int parameter_guess) {
    int index_guess = 0;
    Object424504Collection_guess* collection_guess = (Object424504Collection_guess*)&field04_guess;
    if (collection_guess->count_guess > 0) {
        do {
            Object424504Entry_guess* entry_guess = collection_guess->Get_guess(index_guess);
            if (!((Element4244_guess*)entry_guess->object_guess)->Evaluate_guess(parameter_guess)) {
                return 0;
            }
            ++index_guess;
        } while (index_guess < collection_guess->count_guess);
    }
    return 1;
}

struct LookupResult4245_guess {
    unsigned char padding0000_guess[0x119c];
    unsigned char class_119c_guess;
    unsigned char padding119d_guess[0x11a4 - 0x119d];
    int level_11a4_guess;
    unsigned char padding11a8_guess[0x1228 - 0x11a8];
    int value1228_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    LookupResult4245_guess* GetCharInfo2();
};

struct LookupHolder4245_guess {
    int field00_guess;
    EQ_CharacterProfileView_guess service_guess;
    unsigned char padding08_guess[0x100 - 8];
    int value100_guess;
};

struct OffsetTable4245_guess {
    int field00_guess;
    int vbaseOffset_0004_guess;
};

struct Source4245_guess {
    unsigned char padding00_guess[8];
    OffsetTable4245_guess* table_guess;
};

struct Output4245_guess {
    int value00_guess;
    int value04_guess;
    int value08_guess;
    int value0C_guess;
};

// Character info for the rules: +0x1228 value, level (+0x11A4), class (+0x119C) and race (low 16 bits when
// over 1000).
// FUNCTION: TITANIUM 0x00424524
void __stdcall GetAutojoinCriteria_guess(Source4245_guess* source_guess, Output4245_guess* output_guess) {
    LookupHolder4245_guess* holder_guess;
    holder_guess = reinterpret_cast<LookupHolder4245_guess*>(
        reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
    output_guess->value04_guess = holder_guess->service_guess.GetCharInfo2()->level_11a4_guess;
    holder_guess = reinterpret_cast<LookupHolder4245_guess*>(
        reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
    output_guess->value08_guess = holder_guess->service_guess.GetCharInfo2()->class_119c_guess;
    holder_guess = reinterpret_cast<LookupHolder4245_guess*>(
        reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
    int value_guess = holder_guess->value100_guess;
    if (value_guess > 1000) {
        value_guess &= 0xffff;
    }
    output_guess->value0C_guess = value_guess;
    holder_guess = reinterpret_cast<LookupHolder4245_guess*>(
        reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
    output_guess->value00_guess = holder_guess->service_guess.GetCharInfo2()->value1228_guess;
}

struct Member4245A0_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x0042F092 ??0Member4245A0_guess@@QAE@H@Z
    Member4245A0_guess(int capacity_guess);
    ~Member4245A0_guess();
};

struct Base4245A0_guess {
    ~Base4245A0_guess();
};

struct Object4245A0_guess : Base4245A0_guess {
    void* vtable_guess;
    Member4245A0_guess member_guess;

    Object4245A0_guess();
};

// Constructor: vtable 0x006411F0 and a member array created with capacity 0x40 (0x0042F092).
// FUNCTION: TITANIUM 0x004245A0
Object4245A0_guess::Object4245A0_guess()
    : vtable_guess(&EQ_GLOBAL(int, 0x006411F0)), member_guess(0x40) {
}

struct Item4245D4_guess {
    virtual void Dispose_guess(unsigned char deleteFlag_guess);
};

struct AutojoinChannel_guess : CXStr {
    Object424504Collection_guess items_guess;

    ~AutojoinChannel_guess();
};

// Destructor of a named rule set: every non-null object in the entry list is deleted through its virtual
// deleting destructor (flag 1). The list storage and the name go with the members.
// FUNCTION: TITANIUM 0x004245D4
// @early-stop: budget, structural ndiff=11
AutojoinChannel_guess::~AutojoinChannel_guess() {
    int index_guess = 0;
    AutojoinChannel_guess* owner_guess = this;
    if (owner_guess->items_guess.count_guess > 0) {
        do {
            Object424504Entry_guess* entry_guess = owner_guess->items_guess.Get_guess(index_guess);
            if (entry_guess->object_guess != 0) {
                ((Item4245D4_guess*)entry_guess->object_guess)->Dispose_guess(1);
            }
            ++index_guess;
        } while (index_guess < owner_guess->items_guess.count_guess);
    }
}

// Zeroes the dwords at +0, +4 and +8 and sets +0xC to 1 (an empty array).
// FUNCTION: TITANIUM 0x00424631
Object42631_guess* __fastcall InitArrayClass_guess(Object42631_guess* object) {
    object->field04_guess = 0;
    object->field00_guess = 0;
    object->field08_guess = 0;
    object->field0C_guess = 1;
    return object;
}

struct GlobalContext_guess {
    // EXTERNAL: TITANIUM 0x00491438 GlobalContext_guess::ChatServerMessage_guess
    void ChatServerMessage_guess(const char* text_guess);
};

#define g_globalContext_guess EQ_GLOBAL(GlobalContext_guess*, 0x00988DF0)
#define g_channelsEnabled_guess EQ_GLOBAL(unsigned char, 0x009254F8)
#define g_listSeparator_guess EQ_ARRAY(char, 0x0063FDE4)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x00577000 FormatText_guess
void __cdecl FormatText_guess(char* buffer_guess, unsigned int size_guess,
                              const char* format_guess, ...);

struct JoinList4246_guess : CXStr {
    JoinList4246_guess(const char* text_guess) : CXStr(text_guess) {}
    // EXTERNAL: TITANIUM 0x00572C10 JoinList4246_guess::AppendString_guess
    void AppendString_guess(const CXStr& text_guess);
};

// Leaves every joined channel whose rules stopped matching (or all, when g_channelsEnabled_guess is off),
// then joins the newly matching ones in a single ";join a, b" command through ChatServerMessage_guess.
// FUNCTION: TITANIUM 0x00424642
// @early-stop: budget, structural ndiff=34
void Object424504Collection_guess::UpdateAutoJoinChannels_guess(Source4245_guess* source_guess) {
    Output4245_guess info_guess;
    char joinBuffer_guess[0x400];
    char leaveBuffer_guess[0x400];
    int size_guess = 0x400;
    GetAutojoinCriteria_guess(source_guess, &info_guess);
    int index_guess = 0;
    for (; index_guess < count_guess; ++index_guess) {
        if (Get_guess(index_guess)->object_guess->field14_guess != 0) {
            if (((Object42416A_guess*)Get_guess(index_guess)->object_guess)->Check_guess((int)&info_guess) == 0 ||
                g_channelsEnabled_guess == 0) {
                FormatText_guess(leaveBuffer_guess, size_guess, ";leave %s",
                                 ((CXStr*)Get_guess(index_guess)->object_guess)->operator char*());
                g_globalContext_guess->ChatServerMessage_guess(leaveBuffer_guess);
                Get_guess(index_guess)->object_guess->field14_guess = 0;
            }
        }
    }
    JoinList4246_guess joinList_guess(g_emptyString_guess);
    index_guess = 0;
    if (g_channelsEnabled_guess != 0) {
        for (; index_guess < count_guess; ++index_guess) {
            if (Get_guess(index_guess)->object_guess->field14_guess == 0) {
                if (((Object42416A_guess*)Get_guess(index_guess)->object_guess)->Check_guess((int)&info_guess) != 0) {
                    if ((joinList_guess.Ptr != 0 ? joinList_guess.Ptr->length : 0) > 0) {
                        joinList_guess += g_listSeparator_guess;
                    }
                    joinList_guess.AppendString_guess(*(CXStr*)Get_guess(index_guess)->object_guess);
                    Get_guess(index_guess)->object_guess->field14_guess = 1;
                }
            }
        }
    }
    if ((joinList_guess.Ptr != 0 ? joinList_guess.Ptr->length : 0) > 0) {
        FormatText_guess(joinBuffer_guess, size_guess, ";join %s", joinList_guess.operator char*());
        g_globalContext_guess->ChatServerMessage_guess(joinBuffer_guess);
    }
}

// Scalar deleting destructor of the value-list rule (0x00424811; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004247F5
Object4247F5_guess* Object4247F5_guess::Dispose_guess(unsigned char deleteFlag_guess) {
    Clear_guess();
    if ((deleteFlag_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Value-list rule destructor body: frees the value set (0x004C9745), then restores the base rule
// vtable.
// FUNCTION: TITANIUM 0x00424811
void Object4247F5_guess::Clear_guess() {
    FUN_004C9745_guess(&field04_guess);
    vtable_guess = &EQ_GLOBAL(int, 0x006411CC);
}

// Marks every auto-join channel as not joined (+0x14); the client clears it on the way back to
// character select.
// FUNCTION: TITANIUM 0x00424504
void Object424504Collection_guess::ClearItems_guess() {
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            Get_guess(index_guess)->object_guess->field14_guess = 0;
            ++index_guess;
        } while (index_guess < count_guess);
    }
}

template <class T> struct ArrayClass424982_guess {
    int length_guess;
    T* array_guess;
    int alloc_guess;

    ~ArrayClass424982_guess();
};

template <class T> ArrayClass424982_guess<T>::~ArrayClass424982_guess() {
    if (array_guess != 0) {
        delete[] array_guess;
    }
    array_guess = 0;
    alloc_guess = 0;
}

struct OwnerList424982_guess : ArrayClass424982_guess<AutojoinChannel_guess*> {
    // EXTERNAL: TITANIUM 0x004EB924 OwnerList424982_guess::Get_guess
    AutojoinChannel_guess** Get_guess(int index_guess);

    ~OwnerList424982_guess();
};

// Destructor of the channel list: deletes every named rule set (0x004245D4).
// FUNCTION: TITANIUM 0x00424982
// @early-stop: name-conflict, diff ndiff=1
OwnerList424982_guess::~OwnerList424982_guess() {
    for (int index_guess = 0; index_guess < length_guess; ++index_guess) {
        delete *Get_guess(index_guess);
    }
}

struct Object4249D5_guess {
    CXStr field00_guess;
    void* collection_guess;

    void SetName_guess(char* input_guess);
    void ParseRest_guess(char* input_guess);
};

// EXTERNAL: TITANIUM 0x0050319B FUN_0050319B_guess
void __stdcall FUN_0050319B_guess(void* collection_guess, void** object_guess);

// Parses the comma-separated rules "type^args" after the channel name; unknown types and rules that fail to
// parse are skipped.
// FUNCTION: TITANIUM 0x00424824
// @early-stop: budget, structural ndiff=38
void Object4249D5_guess::ParseRest_guess(char* input_guess) {
    ParsePredicate424824_guess* predicate_guess;
    char token_guess[0x400];
    char valueText_guess[0x100];
    char* expression_guess;
    int valueOffset_guess;

    if (isdigit(input_guess[0])) {
        do {
            input_guess += FUN_005769E0_guess(input_guess, token_guess, 0x400, 0x2c, 1);
            valueOffset_guess = FUN_005769E0_guess(token_guess, valueText_guess, 0x100, 0x5e, 1);
            expression_guess = token_guess + valueOffset_guess;
            int type_guess = atoi(valueText_guess);

            switch (type_guess) {
            case 0:
                predicate_guess = new LevelRangeRule_guess;
                break;
            case 1:
                predicate_guess = new ClassRule_guess;
                break;
            case 2:
                predicate_guess = reinterpret_cast<ParsePredicate424824_guess*>(new Object4245A0_guess);
                break;
            default:
                continue;
            }

            if (!predicate_guess->Parse_guess(expression_guess)) {
                predicate_guess->Dispose_guess(1);
            } else {
                FUN_0050319B_guess(collection_guess, reinterpret_cast<void**>(&predicate_guess));
            }
        } while (isdigit(input_guess[0]));
    }
}

// Reads one autojoin "Channel=" value: the channel name up to the first comma goes to +0, the rest to
// 0x00424824, which adds the comma-separated "type^rule" join conditions.
// FUNCTION: TITANIUM 0x004249D5
void Object4249D5_guess::SetName_guess(char* input_guess) {
    char buffer_guess[256];
    input_guess += FUN_005769E0_guess(input_guess, buffer_guess, 0x100, 0x2c, 1);
    field00_guess = buffer_guess;
    ParseRest_guess(input_guess);
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message_guess, ...);
// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* record_guess, const char* name_guess);

struct Entry424A2C_guess {
    CXStr name_guess;
    int field04_guess;
    int field08_guess;
    int field0C_guess;
    unsigned char field10_guess;
    unsigned char padding11_guess[3];
    unsigned char field14_guess;

    Entry424A2C_guess() {
        field08_guess = 0;
        field04_guess = 0;
        field0C_guess = 0;
        field10_guess = 1;
        field14_guess = 0;
    }
};

struct AutojoinList_guess {
    int count_guess;

    // EXTERNAL: TITANIUM 0x0050319B AutojoinList_guess::Insert_guess
    void Insert_guess(int index_guess, Entry424A2C_guess** value_guess);

    void LoadAutoJoinChannels_guess(char* fileName_guess);
};

// Reads the auto-join file: each "Channel=..." line adds one channel with its rules. A missing file is only logged.
// FUNCTION: TITANIUM 0x00424A2C
void AutojoinList_guess::LoadAutoJoinChannels_guess(char* fileName_guess) {
    FILE* file_guess = fopen(fileName_guess, "rt");
    if (file_guess == 0) {
        FUN_00574110_guess("ERROR: could not find autojoin channel file %s.", fileName_guess);
    } else {
        while ((file_guess->_flag & 0x10) == 0) {
            char line_guess[4096];
            char buffer_guess[2048];
            line_guess[0] = 0;
            fgets(line_guess, 0xfff, file_guess);
            line_guess[4095] = 0;
            int split_guess = FUN_005769E0_guess(line_guess, buffer_guess, 0x800, 0x3d, 1);
            char* value_guess = line_guess + split_guess;
            if (FUN_00574950_guess(buffer_guess, "Channel") == 0) {
                Entry424A2C_guess* entry_guess = new Entry424A2C_guess;
                ((Object4249D5_guess*)entry_guess)->SetName_guess(value_guess);
                Insert_guess(count_guess, &entry_guess);
            }
        }
        fclose(file_guess);
    }
}

