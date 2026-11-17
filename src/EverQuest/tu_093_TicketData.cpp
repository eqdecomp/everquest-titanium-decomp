// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 93: a hint from compare/tumap.py.
// Support-ticket data and Tab-target cycling. TicketData_guess is the ticket data at 0x985CF0
// (current ticket, 10 open tickets, 20 knowledge-base results, one article, 1000 XML topics) that feeds
// CTicketWindow (0x9928A8, tu_226; CTicketWindow_guess). TargetCycler_guess is the target-cycling singleton (0x985CE8,
// tu_044's TargetState_guess); IdMap_guess/TaskTemplate_guess hold '^'-separated records, probably task templates.
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
#include <string.h>

struct ByteValue_guess {
    char value_guess;
    char Get_guess();
};

struct DwordAt10_guess {
    char padding_guess[0x10];
    int value_guess;
    int Get_guess();
};

struct HashEntry_guess {
    void* value_guess;
};

struct IdMap_guess {
    int* values_guess;
    int count_guess;
    int field08_guess;
    int field0c_guess;

    // EXTERNAL: TITANIUM 0x0042F092 IdMap_guess::IdMap_guess
    IdMap_guess(int capacity_guess);
    // EXTERNAL: TITANIUM 0x004C9745 IdMap_guess::~IdMap_guess
    ~IdMap_guess() ;
    // EXTERNAL: TITANIUM 0x004466FA IdMap_guess::First_guess
    HashEntry_guess* First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A IdMap_guess::Next_guess
    HashEntry_guess* Next_guess(HashEntry_guess* entry_guess);

    // EXTERNAL: TITANIUM 0x00447C66 IdMap_guess::Insert_guess
    void Insert_guess(int* value_guess, int key_guess);
    // EXTERNAL: TITANIUM 0x004FF9C9 IdMap_guess::Find_guess
    int* Find_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x0048F513 IdMap_guess::Clear_guess
    void Clear_guess();

    int GetValue_guess(int key_guess);
    void ClearAndFree_guess();
    void DestroyAndFree_guess();
    void Load_guess(int cursor_guess);
};

struct TaskTemplate_guess {
    int key_guess;
    char name_guess[0x40];
    char blob_guess[0xfa0];
    char padding_fe4_guess[8];
    int field_fec_guess;
    char padding_ff0_guess[4];
    int field_ff4_guess;
    char padding_ff8_guess[4];
    int field_ffc_guess;
    int tail_1000_guess[9];
    char padding_1024_guess[4];
    IdMap_guess bucket_1028_guess;
    IdMap_guess bucket_1038_guess;

    TaskTemplate_guess();
    void Destroy_guess();

    void InsertAt1028_guess(int value_guess, int key_guess);
    int GetFrom1028_guess(int key_guess);
    int GetFrom1038_guess(int key_guess);
    void InsertAt1038_guess(int value_guess, int key_guess);
};

struct CDisplayView_guess {
    // EXTERNAL: TITANIUM 0x0043A15C CDisplayView_guess::s3dCollideSphereWithWorld_guess
    void s3dCollideSphereWithWorld_guess(float value0_guess, float value1_guess, float value2_guess,
                         float value3_guess, float value4_guess, float value5_guess,
                         int value6_guess, int value7_guess, int value8_guess,
                         int value9_guess);
};

#define g_display_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
extern "C" int __cdecl atoi(const char* text_guess);

struct ReturnOwner_guess {
    // EXTERNAL: TITANIUM 0x0042F092 ReturnOwner_guess::Prepare_guess
    void Prepare_guess(int value_guess);
    ReturnOwner_guess* PrepareAndReturn_guess();
};

struct TargetCandidate_guess {
    int value_guess;
    float distance_guess;
    char visited_guess;
    char tail_guess[3];
    void UpdateFlags_guess(int* source_guess);
};

struct ClearRecordTable_guess {
    TargetCandidate_guess records_guess[10];
    void UpdateFlags_guess(TargetCandidate_guess* source_guess);
};

struct TargetCandidateList_guess {
    TargetCandidate_guess records_guess[10];
    void Clear_guess();
    void Insert_guess(int value_guess, float time_guess);
    int RestartCycle_guess();
    int GetNextUnvisited_guess();
};

struct TargetCycler_guess {
    char padding_guess[0x78];
    TargetCandidate_guess records_guess[10];
    int state_f0_guess;
    int state_f4_guess;
    int state_f8_guess;
    void Clear_guess();
    void Insert_guess(int value_guess, float time_guess);
    int MarkAndGet_guess();
    int NextValue_guess();
    void UpdateFlags_guess(TargetCandidate_guess* source_guess);
    TargetCycler_guess* Initialize_guess();
    int FindNextTarget_guess(float time_guess, int mode_guess, char advance_guess);
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

#define g_clearAt78_guess EQ_GLOBAL(TargetCycler_guess*, 0x00985CE8)

struct ForwardedObject_guess {
    char value_guess;
};

struct MessageState_guess {
    int field_00_guess;
    int padding_04_guess;
    int field_08_guess;
    int field_0c_guess;
    int field_10_guess;
    int field_14_guess;
    char text_18_guess[0x40];
    char padding_58_guess[4];
    int field_5c_guess;
    int field_60_guess;
    int field_64_guess;
    char text_68_guess[0xfa0];
    char padding_1008_guess[8];
};

struct RequestRow_guess {
    int field_00_guess;
    int field_04_guess;
    int field_08_guess;
    int field_0c_guess;
    int field_10_guess;
    int field_14_guess;
    char text_18_guess[0xfa0];
    char padding_fb8_guess;
    char name_fb9_guess[0x40];
    char padding_ff9_guess[7];
};

struct ListEntry_guess {
    char first_guess[0x41];
    char second_guess[0x100];
    char padding_141_guess;
    unsigned short field_142_guess;
};

struct LargeTextStorage_guess {
    char first_guess[0xff];
    char second_guess[0x1f40];
    char padding_203f_guess;
};

struct CategoryEntry_guess {
    char name_guess[0x100];
    int id_guess;
    int parent_guess;
};

struct RequestInput_guess {
    int field_00_guess;
    int field_04_guess;
    int index_guess;
    int field_0c_guess;
    int field_10_guess;
    int field_14_guess;
    int field_18_guess;
    int field_1c_guess;
    char text_20_guess[0xfa0];
    char padding_fc0_guess;
    char name_fc1_guess[0x40];
};

struct XmlRequestInput_guess {
    int header_guess;
    char xml_guess[1];
};

struct ByteMessage_guess {
    unsigned char value_guess;
};

struct StringUpdate_guess {
    int field_00_guess;
    char first_04_guess[0x100];
    char second_104_guess[0x1f40];
};

struct ListUpdate_guess {
    int count_guess;
    ListEntry_guess entries_guess[1];
};

struct DescriptionUpdate_guess {
    int field_00_guess;
    int field_04_guess;
    int field_08_guess;
    int field_0c_guess;
    int field_10_guess;
    int field_14_guess;
    char name_18_guess[0x40];
    char padding_58_guess[4];
    int field_5c_guess;
    int field_60_guess;
    int padding_64_guess;
    int field_68_guess;
    int field_6c_guess;
    char text_70_guess[0xfa0];
};

struct TicketData_guess {
    char first_guess;
    char second_guess;
    char padding_02_guess[6];
    union {
        ForwardedObject_guess object_08_guess;
        MessageState_guess message_state_guess;
    };
    RequestRow_guess requests_1018_guess[10];
    union {
        ForwardedObject_guess object_b018_guess;
        ListEntry_guess list_b018_guess[20];
    };
    union {
        ForwardedObject_guess object_c968_guess;
        LargeTextStorage_guess text_c968_guess;
    };
    CategoryEntry_guess categories_e9a8_guess[1000];

    void Forward_guess();
    void PrepareAndForward_guess(char flag_guess);
    void ShowKnowledgeBaseResults_guess();
    void Reset_guess();
    void ClearKnowledgeBase_guess();
    void ShowKnowledgeBaseArticle_guess();
    void RefreshTicketWindow_guess();
    TicketData_guess* Initialize_guess();
    void HandleTicketMessage_guess(int unused0_guess, unsigned int code_guess,
                      int data_guess, int unused3_guess);
};

struct CTicketWindow_guess {
    // EXTERNAL: TITANIUM 0x00562710 CTicketWindow_guess::Forward_guess
    void Forward_guess(ForwardedObject_guess* object_guess);
    // EXTERNAL: TITANIUM 0x0056150D CTicketWindow_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x00563E25 CTicketWindow_guess::ShowTicketThunk_guess
    void ShowTicketThunk_guess(ForwardedObject_guess* object_guess);
    // EXTERNAL: TITANIUM 0x00562FED CTicketWindow_guess::ForwardLarge_guess
    void ForwardLarge_guess(ForwardedObject_guess* object_guess);
    // EXTERNAL: TITANIUM 0x005631F4 CTicketWindow_guess::ForwardC968_guess
    void ForwardC968_guess(ForwardedObject_guess* object_guess);
    // EXTERNAL: TITANIUM 0x0056176F CTicketWindow_guess::UpdateGuess_guess
    void UpdateGuess_guess(void* input_guess);
    // EXTERNAL: TITANIUM 0x0056115A CTicketWindow_guess::SetLanguage_guess
    void SetLanguage_guess(unsigned char language_guess);
    // EXTERNAL: TITANIUM 0x005632FB CTicketWindow_guess::OpenCategory_guess
    void OpenCategory_guess();
};

#define pinstCTicketWnd_guess EQ_GLOBAL(CTicketWindow_guess*, 0x009928A8)

struct FreeRecord_guess {
    void* pointer_guess;
    int field04_guess;
    int field08_guess;

    void ClearAndFree_guess();
    void ClearAndFreeThunk_guess();
};

// EXTERNAL: TITANIUM 0x0064C480 ??_7XmlNode_guess@@6B@
struct RecordBase_guess {
    // EXTERNAL: TITANIUM 0x005DC920 RecordBase_guess::~RecordBase_guess
    ~RecordBase_guess() ;
    virtual void Slot00_guess();
};

struct XmlNode_guess : RecordBase_guess {
    int padding_04_guess[3];
    int kind_10_guess;
    int padding_14_guess[8];
    char parsed_34_guess;
    char padding_35_guess;
    short padding_36_guess;
    int padding_38_guess;
    FreeRecord_guess record_3c_guess;

    // EXTERNAL: TITANIUM 0x005DCE30 XmlNode_guess::XmlNode_guess
    XmlNode_guess();
    // EXTERNAL: TITANIUM 0x005DE910 XmlNode_guess::Parse_guess
    void Parse_guess(void* input_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x005DC9A0 XmlNode_guess::GetChild_guess
    XmlNode_guess* GetChild_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x005DCA80 XmlNode_guess::GetNext_guess
    XmlNode_guess* GetNext_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x005DD9F0 XmlNode_guess::GetValue_guess
    char* GetValue_guess(const char* name_guess);
    ~XmlNode_guess() ;
    XmlNode_guess* Delete_guess(char flag_guess);
};

#define g_ticketServiceEnabled_guess EQ_GLOBAL(unsigned char, 0x00923D64)

// EXTERNAL: TITANIUM 0x004B2056 ReadInt_guess
int ReadInt_guess(int source_guess, void* destination_guess, int flags_guess);
// EXTERNAL: TITANIUM 0x005769E0 ReadText_guess
int ReadText_guess(int source_guess, void* destination_guess, int limit_guess, int flags_guess, int mode_guess);

struct Pair8_guess {
    int key_guess;
    int value_guess;
};

struct Entry68_guess {
    int key_guess;
    char text_guess[0x40];
};

// Frees the buffer and zeroes the pointer and both counts.
// FUNCTION: TITANIUM 0x004C9AD3
void FreeRecord_guess::ClearAndFree_guess() {
    if (pointer_guess != 0) {
        _free(pointer_guess);
    }
    pointer_guess = 0;
    field04_guess = 0;
    field08_guess = 0;
}

// XML node destructor: frees its record buffer (+0x3C).
// FUNCTION: TITANIUM 0x004C9C05
XmlNode_guess::~XmlNode_guess()  {
    record_3c_guess.ClearAndFree_guess();
}

// Zeroes the ticket data: current ticket and open tickets (+8, 0xB010 bytes), article, KB results.
// FUNCTION: TITANIUM 0x004C9AF0
TicketData_guess* TicketData_guess::Initialize_guess() {
    first_guess = 0;
    second_guess = 0;
    memset(&object_08_guess, 0, 0xb010);
    memset(&object_c968_guess, 0, 0x203f);
    memset(&object_b018_guess, 0, 0x1950);
    return this;
}

// Collision callback for the target scan; forwards to s3dCollideSphereWithWorld (0x43A15C), so
// s3dCollideSphereWithWorld_guess is a misname. Probably the line-of-sight test.
// FUNCTION: TITANIUM 0x004C90D4
void __cdecl CollideSphereWithWorldThunk_guess(float value0_guess, float value1_guess, float value2_guess,
                                 float value3_guess, float value4_guess, float value5_guess,
                                 int value6_guess, int value7_guess, int value8_guess,
                                 int value9_guess) {
    g_display_guess->s3dCollideSphereWithWorld_guess(value0_guess, value1_guess, value2_guess, value3_guess,
                                     value4_guess, value5_guess, value6_guess, value7_guess,
                                     value8_guess, value9_guess);
}

// Empties the first candidate list (+0).
// FUNCTION: TITANIUM 0x004C9230
void TargetCandidateList_guess::Clear_guess() {
    TargetCandidate_guess* record_guess = records_guess;
    int count_guess = 10;
    do {
        record_guess->value_guess = 0;
        record_guess->visited_guess = 0;
        ++record_guess;
        --count_guess;
    } while (count_guess != 0);
}

// Empties the second candidate list (+0x78).
// FUNCTION: TITANIUM 0x004C9241
void TargetCycler_guess::Clear_guess() {
    TargetCandidate_guess* record_guess = records_guess;
    int count_guess = 10;
    do {
        record_guess->value_guess = 0;
        record_guess->visited_guess = 0;
        ++record_guess;
        --count_guess;
    } while (count_guess != 0);
}

// Inserts a candidate spawn into the first list, kept sorted by distance (`time_guess` is the distance);
// on a full list the farthest of the 10 falls off.
// FUNCTION: TITANIUM 0x004C9255
void TargetCandidateList_guess::Insert_guess(int value_guess, float time_guess) {
    if (value_guess != 0) {
        if (records_guess[0].value_guess == 0) {
            records_guess[0].value_guess = value_guess;
            records_guess[0].distance_guess = time_guess;
            records_guess[0].visited_guess = 0;
        } else {
            int index_guess = 8;
            do {
                TargetCandidate_guess* record_guess = &records_guess[index_guess];
                int currentValue_guess = record_guess->value_guess;
                if (currentValue_guess != 0) {
                    if (time_guess < record_guess->distance_guess) {
                        records_guess[index_guess + 1].distance_guess = record_guess->distance_guess;
                        char currentFlag_guess = record_guess->visited_guess;
                        records_guess[index_guess + 1].value_guess = currentValue_guess;
                        records_guess[index_guess + 1].visited_guess = currentFlag_guess;
                    } else {
                        records_guess[index_guess + 1].distance_guess = time_guess;
                        records_guess[index_guess + 1].value_guess = value_guess;
                        records_guess[index_guess + 1].visited_guess = 0;
                        return;
                    }
                }
                --index_guess;
            } while (index_guess >= 0);
            records_guess[0].distance_guess = time_guess;
            records_guess[0].value_guess = value_guess;
            records_guess[0].visited_guess = 0;
        }
    }
}

// The same sorted insert on the second list.
// FUNCTION: TITANIUM 0x004C92C5
void TargetCycler_guess::Insert_guess(int value_guess, float time_guess) {
    if (value_guess != 0) {
        if (records_guess[0].value_guess == 0) {
            records_guess[0].value_guess = value_guess;
            records_guess[0].distance_guess = time_guess;
            records_guess[0].visited_guess = 0;
        } else {
            TargetCandidate_guess* record_guess = &records_guess[8];
            int index_guess = 8;
            do {
                int currentValue_guess = record_guess->value_guess;
                if (currentValue_guess != 0) {
                    if (time_guess < record_guess->distance_guess) {
                        (record_guess + 1)->distance_guess = record_guess->distance_guess;
                        char currentFlag_guess = record_guess->visited_guess;
                        (record_guess + 1)->value_guess = currentValue_guess;
                        (record_guess + 1)->visited_guess = currentFlag_guess;
                    } else {
                        records_guess[index_guess + 1].value_guess = value_guess;
                        records_guess[index_guess + 1].distance_guess = time_guess;
                        records_guess[index_guess + 1].visited_guess = 0;
                        return;
                    }
                }
                --index_guess;
                --record_guess;
            } while (index_guess >= 0);
            records_guess[0].distance_guess = time_guess;
            records_guess[0].value_guess = value_guess;
            records_guess[0].visited_guess = 0;
        }
    }
}

// Carries the visited flags of the previous scan over to the same spawns in the first list.
// FUNCTION: TITANIUM 0x004C934C
void ClearRecordTable_guess::UpdateFlags_guess(TargetCandidate_guess* source_guess) {
    for (int destinationIndex_guess = 0; destinationIndex_guess < 10; ++destinationIndex_guess) {
        if (records_guess[destinationIndex_guess].value_guess == 0) {
            return;
        }
        for (int sourceIndex_guess = 0; sourceIndex_guess < 10; ++sourceIndex_guess) {
            if (source_guess[sourceIndex_guess].value_guess == 0) {
                break;
            }
            if (records_guess[destinationIndex_guess].value_guess ==
                source_guess[sourceIndex_guess].value_guess) {
                records_guess[destinationIndex_guess].visited_guess =
                    source_guess[sourceIndex_guess].visited_guess;
            }
        }
    }
}

// Carries visited flags over in the second list.
// FUNCTION: TITANIUM 0x004C9387
void TargetCycler_guess::UpdateFlags_guess(TargetCandidate_guess* source_guess) {
    int destinationIndex_guess = 0;
    TargetCandidate_guess* destination_guess = records_guess;
    do {
        if (destination_guess->value_guess == 0) {
            return;
        }
        int sourceIndex_guess = 0;
        TargetCandidate_guess* currentSource_guess = source_guess;
        do {
            if (currentSource_guess->value_guess == 0) {
                break;
            }
            if (destination_guess->value_guess == currentSource_guess->value_guess) {
                destination_guess->visited_guess = currentSource_guess->visited_guess;
            }
            ++sourceIndex_guess;
            ++currentSource_guess;
        } while (sourceIndex_guess < 10);
        ++destinationIndex_guess;
        ++destination_guess;
    } while (destinationIndex_guess < 10);
}

// First list: the nearest spawn not yet visited this cycle; once all are visited the cycle restarts at the
// nearest.
// FUNCTION: TITANIUM 0x004C93C3
int TargetCandidateList_guess::GetNextUnvisited_guess() {
    if (records_guess[0].value_guess == 0) {
        return 0;
    }
    int index_guess = 0;
    TargetCandidate_guess* current_guess = records_guess;
    do {
        if (current_guess->value_guess != 0 && current_guess->visited_guess == 0) {
            records_guess[index_guess].visited_guess = 1;
            return records_guess[index_guess].value_guess;
        }
        ++index_guess;
        ++current_guess;
    } while (index_guess < 10);
    char* firstFlag_guess = &records_guess[0].visited_guess;
    char* currentFlag_guess = firstFlag_guess;
    int count_guess = 10;
    do {
        *currentFlag_guess = 0;
        currentFlag_guess += 0xc;
        --count_guess;
    } while (count_guess != 0);
    int result_guess = records_guess[0].value_guess;
    *firstFlag_guess = 1;
    return result_guess;
}

// First list: restarts the cycle and returns the nearest spawn.
// FUNCTION: TITANIUM 0x004C9405
int TargetCandidateList_guess::RestartCycle_guess() {
    char* first_guess = &records_guess[0].visited_guess;
    char* current_guess = first_guess;
    int count_guess = 10;
    do {
        *current_guess = 0;
        current_guess += 0xc;
        --count_guess;
    } while (count_guess != 0);
    *first_guess = 1;
    return records_guess[0].value_guess;
}

// Second list: next unvisited spawn, wrapping to the nearest.
// FUNCTION: TITANIUM 0x004C941E
int TargetCycler_guess::NextValue_guess() {
    if (records_guess[0].value_guess == 0) {
        return 0;
    }
    for (int index_guess = 0; index_guess < 10; ++index_guess) {
        if (records_guess[index_guess].value_guess != 0 && records_guess[index_guess].visited_guess == 0) {
            records_guess[index_guess].visited_guess = 1;
            return records_guess[index_guess].value_guess;
        }
    }
    for (int index_guess = 0; index_guess < 10; ++index_guess) {
        records_guess[index_guess].visited_guess = 0;
    }
    records_guess[0].visited_guess = 1;
    return records_guess[0].value_guess;
}

// Second list: restarts the cycle at the nearest spawn.
// FUNCTION: TITANIUM 0x004C946C
int TargetCycler_guess::MarkAndGet_guess() {
    char* first_guess = &records_guess[0].visited_guess;
    char* current_guess = first_guess;
    int count_guess = 10;
    do {
        *current_guess = 0;
        current_guess += 0xc;
        --count_guess;
    } while (count_guess != 0);
    *first_guess = 1;
    return records_guess[0].value_guess;
}

// Empties both lists and the three remembered target ids at +0xF0/+0xF4/+0xF8 (tu_044's target keys swap
// previous targets through them).
// FUNCTION: TITANIUM 0x004C9489
TargetCycler_guess* TargetCycler_guess::Initialize_guess() {
    Clear_guess();
    ((TargetCandidateList_guess*)this)->Clear_guess();
    state_f4_guess = 0;
    state_f0_guess = 0;
    state_f8_guess = 0;
    return this;
}

// The target-cycling singleton (0x985CE8, 0xFC bytes), created on first use; other files call this
// GetTargetState_guess.
// FUNCTION: TITANIUM 0x004C94AE
TargetCycler_guess* InitializeClearAt78_guess() {
    TargetCycler_guess* result_guess = g_clearAt78_guess;
    if (result_guess == 0) {
        TargetCycler_guess* object_guess = (TargetCycler_guess*)operator new(0xfc);
        if (object_guess != 0) {
            result_guess = object_guess->Initialize_guess();
        } else {
            result_guess = 0;
        }
        g_clearAt78_guess = result_guess;
    }
    return result_guess;
}

struct ClearTarget_guess {
    char padding_guess[0x160];
    int value_guess;
};

struct ClearSource_guess {
    char padding_guess[0x1a8];
    ClearTarget_guess* target_guess;
    // EXTERNAL: TITANIUM 0x0047BFD0 ClearSource_guess::IsHorseRace_guess
    char IsHorseRace_guess();
};

// Scan callback: adds spawn `value_guess` at distance `time_guess`; `flag_guess` != 0 picks the first list.
// For the second list a spawn whose +0x1A8 -> +0x160 link is set is replaced by the linked spawn (probably
// rider and mount; the test is 0x47BFD0).
// FUNCTION: TITANIUM 0x004C951C
char AddTargetCandidate_guess(int value_guess, float time_guess, char flag_guess) {
    if (value_guess == 0) {
        return 0;
    }
    if (flag_guess != 0) {
        ((TargetCandidateList_guess*)InitializeClearAt78_guess())->Insert_guess(value_guess, time_guess);
    } else {
        ClearSource_guess* source_guess = (ClearSource_guess*)value_guess;
        if (source_guess->IsHorseRace_guess() != 0 && source_guess->target_guess->value_guess != 0) {
            InitializeClearAt78_guess()->Insert_guess(source_guess->target_guess->value_guess, time_guess);
        } else {
            InitializeClearAt78_guess()->Insert_guess(value_guess, time_guess);
        }
    }
    return 1;
}

typedef void (__cdecl *Callback_guess)();

struct ClearCopyRow_guess {
    int value_guess;
    float time_guess;
    char flag_guess;
};

struct StateObject_guess {
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
    virtual void ReadFirst_guess(float* values_guess);
    virtual void ReadSecond_guess(float* values_guess);
};

struct RootObject_guess {
    char padding_1a8_guess[0x1a8];
    StateObject_guess** state_1a8_guess;
    // EXTERNAL: TITANIUM 0x00489BF5 RootObject_guess::ReadTime_guess
    float ReadTime_guess();
};

struct EventObject_guess {
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
    virtual void Submit_guess(float* values_guess, float time_guess, int one_guess, int mode_guess,
                              Callback_guess callback0_guess, Callback_guess callback1_guess,
                              Callback_guess callback2_guess, Callback_guess callback3_guess);
};

#define g_rootObject_guess EQ_GLOBAL(RootObject_guess*, 0x00905CF8)
#define g_eventObject_guess EQ_GLOBAL(EventObject_guess*, 0x0099E368)

// EXTERNAL: TITANIUM 0x004C911C Callback911c_guess
void __cdecl Callback911c_guess();
// EXTERNAL: TITANIUM 0x004C94D7 Callback94d7_guess
void __cdecl Callback94d7_guess();

// Tab targeting: rescans the spawns within range `time_guess` and returns the next target. `mode_guess` != 0
// uses the first list, 0 the second (two target filters); `advance_guess` != 0 restarts at the nearest
// instead of moving on. Visited flags survive the rescan through the copy.
// FUNCTION: TITANIUM 0x004C9585
// @early-stop: unknown, diff ndiff=27
int TargetCycler_guess::FindNextTarget_guess(float time_guess, int mode_guess, char advance_guess) {
    float values_guess[6];
    ClearCopyRow_guess copiedRecords_guess[10];

    if ((char)mode_guess != 0) {
        ClearCopyRow_guess* destination_guess = copiedRecords_guess;
        TargetCandidate_guess* source_guess = ((TargetCandidateList_guess*)this)->records_guess;
        int count_guess = 10;
        do {
            destination_guess->value_guess = source_guess->value_guess;
            destination_guess->time_guess = source_guess->distance_guess;
            destination_guess->flag_guess = source_guess->visited_guess;
            ++destination_guess;
            ++source_guess;
            --count_guess;
        } while (count_guess != 0);
        ((TargetCandidateList_guess*)this)->Clear_guess();
    } else {
        ClearCopyRow_guess* destination_guess = copiedRecords_guess;
        TargetCandidate_guess* source_guess = records_guess;
        int count_guess = 10;
        do {
            destination_guess->value_guess = source_guess->value_guess;
            destination_guess->time_guess = source_guess->distance_guess;
            destination_guess->flag_guess = source_guess->visited_guess;
            ++destination_guess;
            ++source_guess;
            --count_guess;
        } while (count_guess != 0);
        Clear_guess();
    }

    values_guess[0] = 0.0f;
    values_guess[1] = 0.0f;
    values_guess[2] = 0.0f;
    values_guess[3] = 0.0f;
    values_guess[4] = 0.0f;
    values_guess[5] = 0.0f;

    if (g_rootObject_guess != 0 && g_rootObject_guess->state_1a8_guess != 0 &&
        *g_rootObject_guess->state_1a8_guess != 0) {
        (*g_rootObject_guess->state_1a8_guess)->ReadFirst_guess(&values_guess[3]);
        (*g_rootObject_guess->state_1a8_guess)->ReadSecond_guess(values_guess);
        // Scan origin and frame from the player's actor (+0x1A8); the added float
        // raises z, probably to eye height.
        values_guess[5] += g_rootObject_guess->ReadTime_guess();
    }

    g_eventObject_guess->Submit_guess(
        &values_guess[3], time_guess, 1, mode_guess,
        (Callback_guess)Callback911c_guess, (Callback_guess)Callback94d7_guess,
        // The world object (0x99E368) walks the spawns in range and calls back;
        // the last two are the list insert and the collision test above.
        (Callback_guess)AddTargetCandidate_guess, (Callback_guess)CollideSphereWithWorldThunk_guess);

    if ((char)mode_guess == 0) {
        UpdateFlags_guess((TargetCandidate_guess*)copiedRecords_guess);
        if (advance_guess == 0) {
            return NextValue_guess();
        }
        return MarkAndGet_guess();
    }

    ((ClearRecordTable_guess*)this)->UpdateFlags_guess((TargetCandidate_guess*)copiedRecords_guess);
    if (advance_guess == 0) {
        return ((TargetCandidateList_guess*)this)->GetNextUnvisited_guess();
    }
    return ((TargetCandidateList_guess*)this)->RestartCycle_guess();
}

// Returns the byte at +0; the game loop tests it on the ticket data (0x00985CF0).
// FUNCTION: TITANIUM 0x004C9BFD
char ByteValue_guess::Get_guess() {
    return value_guess;
}

// Frees the buffer and zeroes the counts (0x004C9AD3).
// FUNCTION: TITANIUM 0x004C9C00
void FreeRecord_guess::ClearAndFreeThunk_guess() {
    ClearAndFree_guess();
}

// Returns the dword at +0x10.
// FUNCTION: TITANIUM 0x004C9C1E
int DwordAt10_guess::Get_guess() {
    return value_guess;
}

// Scalar deleting destructor of an XML node (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C9C22
XmlNode_guess* XmlNode_guess::Delete_guess(char flag_guess) {
    this->~XmlNode_guess();
    if ((flag_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// A record holds two id maps: +0x1028 id -> (id, int) pairs, +0x1038 id -> 64-char text; these four
// methods read and add to them.
// FUNCTION: TITANIUM 0x004C96D5
int TaskTemplate_guess::GetFrom1028_guess(int key_guess) {
    int* value_guess = bucket_1028_guess.Find_guess(key_guess);
    int result_guess = (int)value_guess;
    if (value_guess != 0) {
        result_guess = *value_guess;
    }
    return result_guess;
}

// Adds `value` under `key` to the id map at +0x1028.
// FUNCTION: TITANIUM 0x004C96ED
void TaskTemplate_guess::InsertAt1028_guess(int value_guess, int key_guess) {
    bucket_1028_guess.Insert_guess(&value_guess, key_guess);
}

// Value stored under `key` in the id map at +0x1038, or 0.
// FUNCTION: TITANIUM 0x004C9704
int TaskTemplate_guess::GetFrom1038_guess(int key_guess) {
    int* value_guess = bucket_1038_guess.Find_guess(key_guess);
    int result_guess = (int)value_guess;
    if (value_guess != 0) {
        result_guess = *value_guess;
    }
    return result_guess;
}

// Adds `value` under `key` to the id map at +0x1038.
// FUNCTION: TITANIUM 0x004C971C
void TaskTemplate_guess::InsertAt1038_guess(int value_guess, int key_guess) {
    bucket_1038_guess.Insert_guess(&value_guess, key_guess);
}

// Value stored under `key` in the id map, or 0.
// FUNCTION: TITANIUM 0x004C9733
int IdMap_guess::GetValue_guess(int key_guess) {
    int* value_guess = Find_guess(key_guess);
    if (value_guess == 0) {
        return 0;
    }
    return *value_guess;
}

// Empties the id map and frees its bucket array.
// FUNCTION: TITANIUM 0x004C9745
void IdMap_guess::ClearAndFree_guess() {
    Clear_guess();
    _free(values_guess);
}

// Both maps start with 0x14 buckets.
// FUNCTION: TITANIUM 0x004C9757
TaskTemplate_guess::TaskTemplate_guess() : bucket_1028_guess(0x14), bucket_1038_guess(0x14) {
}

// Frees every pair and text entry, then both maps.
// FUNCTION: TITANIUM 0x004C9795
void TaskTemplate_guess::Destroy_guess() {
    HashEntry_guess* entry_guess = bucket_1028_guess.First_guess();
    while (entry_guess != 0) {
        void* value_guess = entry_guess->value_guess;
        entry_guess = bucket_1028_guess.Next_guess(entry_guess);
        free(value_guess);
    }
    bucket_1028_guess.Clear_guess();
    entry_guess = bucket_1038_guess.First_guess();
    while (entry_guess != 0) {
        void* value_guess = entry_guess->value_guess;
        entry_guess = bucket_1038_guess.Next_guess(entry_guess);
        free(value_guess);
    }
    bucket_1038_guess.Clear_guess();
    bucket_1038_guess.~IdMap_guess();
    bucket_1028_guess.~IdMap_guess();
}

// Builds a 0x14-bucket map in place: Prepare_guess (0x42F092) is the map constructor.
// FUNCTION: TITANIUM 0x004C9807
ReturnOwner_guess* ReturnOwner_guess::PrepareAndReturn_guess() {
    Prepare_guess(0x14);
    return this;
}

// Parses one '^'-separated record (delimiter 0x5E) into the map: id (the record is created on first sight),
// 64-char name, 4000-char text, 12 ints, then counted (id, int) pairs and (id, 64-char text) entries.
// The task dispatcher feeds it (tu_026, where this map is ChatFilter_guess).
// FUNCTION: TITANIUM 0x004C9815
// @early-stop: budget, structural ndiff=51
void IdMap_guess::Load_guess(int cursor_guess) {
    int key_guess;
    int position_guess = cursor_guess + ReadInt_guess(cursor_guess, &key_guess, 0x5e);
    TaskTemplate_guess* owner_guess = (TaskTemplate_guess*)GetValue_guess(key_guess);
    if (owner_guess == 0) {
        cursor_guess = (int)new TaskTemplate_guess;
        owner_guess = (TaskTemplate_guess*)cursor_guess;
        owner_guess->key_guess = key_guess;
        Insert_guess(&cursor_guess, key_guess);
    }
    position_guess += ReadText_guess(position_guess, owner_guess->name_guess, 0x40, 0x5e, 1);
    position_guess += ReadText_guess(position_guess, owner_guess->blob_guess, 4000, 0x5e, 1);
    position_guess += ReadInt_guess(position_guess, &owner_guess->field_fec_guess, 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->field_ff4_guess, 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->field_ffc_guess, 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[0], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[1], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[2], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[3], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[4], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[5], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[6], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[7], 0x5e);
    position_guess += ReadInt_guess(position_guess, &owner_guess->tail_1000_guess[8], 0x5e);
    position_guess += ReadInt_guess(position_guess, &cursor_guess, 0x5e);
    if (cursor_guess > 0) {
        int remaining_guess = cursor_guess;
        do {
            int entryKey_guess;
            position_guess += ReadInt_guess(position_guess, &entryKey_guess, 0x5e);
            Pair8_guess* pair_guess = (Pair8_guess*)owner_guess->GetFrom1028_guess(entryKey_guess);
            if (pair_guess == 0) {
                pair_guess = new Pair8_guess();
                pair_guess->key_guess = entryKey_guess;
                owner_guess->InsertAt1028_guess((int)pair_guess, entryKey_guess);
            }
            position_guess += ReadInt_guess(position_guess, &pair_guess->value_guess, 0x5e);
            --remaining_guess;
        } while (remaining_guess != 0);
    }
    position_guess += ReadInt_guess(position_guess, &cursor_guess, 0x5e);
    if (cursor_guess > 0) {
        int remaining_guess = cursor_guess;
        do {
            int entryKey_guess;
            position_guess += ReadInt_guess(position_guess, &entryKey_guess, 0x5e);
            Entry68_guess* entry_guess = (Entry68_guess*)owner_guess->GetFrom1038_guess(entryKey_guess);
            if (entry_guess == 0) {
                entry_guess = new Entry68_guess();
                entry_guess->key_guess = entryKey_guess;
                owner_guess->InsertAt1038_guess((int)entry_guess, entryKey_guess);
            }
            position_guess += ReadText_guess(position_guess, entry_guess->text_guess, 0x40, 0x5e, 1);
            --remaining_guess;
        } while (remaining_guess != 0);
    }
}

// Destroys and frees every record, then the map itself.
// FUNCTION: TITANIUM 0x004C9A90
void IdMap_guess::DestroyAndFree_guess() {
    HashEntry_guess* entry_guess = First_guess();
    while (entry_guess != 0) {
        void* value_guess = entry_guess->value_guess;
        entry_guess = Next_guess(entry_guess);
        if (value_guess != 0) {
            ((TaskTemplate_guess*)value_guess)->Destroy_guess();
            free(value_guess);
        }
    }
    Clear_guess();
    ClearAndFree_guess();
}

// Pushes the current ticket (+8) to CTicketWindow.
// FUNCTION: TITANIUM 0x004C9B36
void TicketData_guess::Forward_guess() {
    CTicketWindow_guess* manager_guess = pinstCTicketWnd_guess;
    if (manager_guess != 0) {
        manager_guess->Forward_guess(&object_08_guess);
    }
}

// Pushes the current ticket through the window's other entry (0x563E25); `flag_guess` first sets the
// window's flag (0x56150D).
// FUNCTION: TITANIUM 0x004C9B4B
void TicketData_guess::PrepareAndForward_guess(char flag_guess) {
    if (pinstCTicketWnd_guess != 0) {
        if (flag_guess != 0) {
            pinstCTicketWnd_guess->Prepare_guess();
        }
        pinstCTicketWnd_guess->ShowTicketThunk_guess(&object_08_guess);
    }
}

// Pushes the 20 knowledge-base results (+0xB018) to the window.
// FUNCTION: TITANIUM 0x004C9B77
void TicketData_guess::ShowKnowledgeBaseResults_guess() {
    CTicketWindow_guess* manager_guess = pinstCTicketWnd_guess;
    if (manager_guess != 0) {
        manager_guess->ForwardLarge_guess(&object_b018_guess);
    }
}

// Pushes the knowledge-base article (+0xC968: 255-char title, 8000-char body).
// FUNCTION: TITANIUM 0x004C9B8F
void TicketData_guess::ShowKnowledgeBaseArticle_guess() {
    CTicketWindow_guess* manager_guess = pinstCTicketWnd_guess;
    if (manager_guess != 0) {
        manager_guess->ForwardC968_guess(&object_c968_guess);
    }
}

// Clears the current and open tickets, pushes the empty ticket and drops the have-data flag (+0).
// FUNCTION: TITANIUM 0x004C9BA7
void TicketData_guess::Reset_guess() {
    memset((char*)this + 8, 0, 0xb010);
    Forward_guess();
    *((char*)this) = 0;
}

// Clears the knowledge-base article and results, then pushes them.
// FUNCTION: TITANIUM 0x004C9BC9
void TicketData_guess::ClearKnowledgeBase_guess() {
    memset((char*)this + 0xc968, 0, 0x203f);
    memset((char*)this + 0xb018, 0, 0x1950);
    return ShowKnowledgeBaseResults_guess();
}

// Refreshes every ticket view; tu_029 calls it right after creating CTicketWindow.
// FUNCTION: TITANIUM 0x004C9C3E
void TicketData_guess::RefreshTicketWindow_guess() {
    Forward_guess();
    PrepareAndForward_guess(0);
    ShowKnowledgeBaseResults_guess();
}

// Ticket-system messages from the server, by code (the codes are not in EQEmu's Titanium table). +0 is set
// once ticket data has arrived, +1 while the topic list is loaded.
// FUNCTION: TITANIUM 0x004C9C57
// @early-stop: budget, structural ndiff=588
void TicketData_guess::HandleTicketMessage_guess(int unused0_guess, unsigned int code_guess,
                                       int data_guess, int unused3_guess) {
    if (code_guess <= 0x3b0c) {
        if (code_guess == 0x3b0c) {
            // Clears all 10 open-ticket rows.
            memset(requests_1018_guess, 0, 0xa000);
            PrepareAndForward_guess(1);
            return;
        }
        if (code_guess == 0xf40) {
            if (pinstCTicketWnd_guess != 0) {
                // Passed straight to the window (0x56176F).
                pinstCTicketWnd_guess->UpdateGuess_guess((void*)data_guess);
            }
            return;
        }
        if (code_guess == 0x1525) {
            second_guess = 0;
            return;
        }
        if (code_guess == 0x19cc) {
            Reset_guess();
            Forward_guess();
            return;
        }
        if (code_guess == 0x2217) {
            StringUpdate_guess* input_guess = (StringUpdate_guess*)data_guess;
            // A knowledge-base article: title and body.
            strncpy(text_c968_guess.first_guess, input_guess->first_04_guess, 0xff);
            strncpy(text_c968_guess.second_guess, input_guess->second_104_guess, 0x1f40);
            ShowKnowledgeBaseArticle_guess();
            return;
        }
        if (code_guess != 0x3813) {
            return;
        }
        RequestInput_guess* input_guess = (RequestInput_guess*)data_guess;
        // One open-ticket row, by index 0-9.
        if (input_guess->index_guess < 0 || input_guess->index_guess >= 10) {
            return;
        }
        RequestRow_guess* output_guess = &requests_1018_guess[input_guess->index_guess];
        output_guess->field_00_guess = input_guess->field_0c_guess;
        output_guess->field_10_guess = input_guess->field_18_guess;
        output_guess->field_14_guess = input_guess->field_1c_guess;
        strncpy(output_guess->name_fb9_guess, input_guess->name_fc1_guess, 0x40);
        output_guess->field_08_guess = input_guess->field_14_guess;
        output_guess->field_04_guess = input_guess->field_10_guess;
        strncpy(output_guess->text_18_guess, input_guess->text_20_guess, 4000);
        PrepareAndForward_guess(1);
        first_guess = 1;
        return;
    }

    if (code_guess == 0x3f0d) {
        // Ticket service on or off. 0x923D64 is also set from the LogServer packet
        // (tu_073), so g_ticketServiceEnabled_guess is a misname; 0x56115A enables or disables
        // the window's controls.
        g_ticketServiceEnabled_guess = ((ByteMessage_guess*)data_guess)->value_guess;
        if (pinstCTicketWnd_guess != 0) {
            pinstCTicketWnd_guess->SetLanguage_guess(g_ticketServiceEnabled_guess);
        }
        return;
    }
    if (code_guess == 0x4a52) {
        second_guess = 1;
        XmlNode_guess parser_guess;
        parser_guess.Parse_guess(&((XmlRequestInput_guess*)data_guess)->xml_guess[0], 0);
        if (parser_guess.parsed_34_guess == 0) {
            // Topic tree from XML: categories and subcategories (id, name, parent id),
            // skipping invalid="true" and isBugType="true". Nothing bounds the count
            // by the 1000 rows.
            memset(categories_e9a8_guess, 0, 0x40740);
            int categoryIndex_guess = 0;
            XmlNode_guess* hierarchy_guess =
                parser_guess.GetChild_guess("csa:hierarchy");
            XmlNode_guess* categoryParent_guess =
                hierarchy_guess->GetChild_guess("csa:category");
            while (categoryParent_guess != 0) {
                XmlNode_guess* categoryAttribute_guess = 0;
                if (categoryParent_guess != 0 && categoryParent_guess->kind_10_guess == 1) {
                    categoryAttribute_guess = categoryParent_guess;
                }
                if (strcmp(categoryAttribute_guess->GetValue_guess("invalid"), "true") != 0) {
                    categoryAttribute_guess = 0;
                    if (categoryParent_guess != 0 && categoryParent_guess->kind_10_guess == 1) {
                        categoryAttribute_guess = categoryParent_guess;
                    }
                    if (strcmp(categoryAttribute_guess->GetValue_guess("isBugType"), "true") != 0) {
                        categoryAttribute_guess = 0;
                        if (categoryParent_guess != 0 && categoryParent_guess->kind_10_guess == 1) {
                            categoryAttribute_guess = categoryParent_guess;
                        }
                        CategoryEntry_guess* output_guess =
                            &categories_e9a8_guess[categoryIndex_guess];
                        output_guess->parent_guess = 0;
                        output_guess->id_guess = atoi(
                            categoryAttribute_guess->GetValue_guess("id"));
                        strncpy(output_guess->name_guess,
                                categoryAttribute_guess->GetValue_guess("name"), 0x100);
                        ++categoryIndex_guess;
                        XmlNode_guess* subCategory_guess =
                            categoryParent_guess->GetChild_guess("csa:subCategory");
                        int parentId_guess = output_guess->id_guess;
                        while (subCategory_guess != 0) {
                            XmlNode_guess* subAttribute_guess = 0;
                            if (subCategory_guess != 0 && subCategory_guess->kind_10_guess == 1) {
                                subAttribute_guess = subCategory_guess;
                            }
                            if (strcmp(subAttribute_guess->GetValue_guess("invalid"), "true") != 0) {
                                subAttribute_guess = 0;
                                if (subCategory_guess != 0 && subCategory_guess->kind_10_guess == 1) {
                                    subAttribute_guess = subCategory_guess;
                                }
                                if (strcmp(subAttribute_guess->GetValue_guess("isBugType"), "true") != 0) {
                                    subAttribute_guess = 0;
                                    if (subCategory_guess != 0 && subCategory_guess->kind_10_guess == 1) {
                                        subAttribute_guess = subCategory_guess;
                                    }
                                    CategoryEntry_guess* subOutput_guess =
                                        &categories_e9a8_guess[categoryIndex_guess];
                                    subOutput_guess->id_guess = atoi(
                                        subAttribute_guess->GetValue_guess("id"));
                                    subOutput_guess->parent_guess = parentId_guess;
                                    strncpy(subOutput_guess->name_guess,
                                            subAttribute_guess->GetValue_guess("name"), 0x100);
                                    ++categoryIndex_guess;
                                }
                            }
                            subCategory_guess =
                                subCategory_guess->GetNext_guess("csa:subCategory");
                        }
                    }
                }
                categoryParent_guess = categoryParent_guess->GetNext_guess("csa:category");
            }
            if (pinstCTicketWnd_guess != 0) {
                pinstCTicketWnd_guess->OpenCategory_guess();
            }
        }
        return;
    }
    if (code_guess == 0x5f11) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2275, 0),
                                        0xf, 1);
        return;
    }
    if (code_guess == 0x6ea9) {
        DescriptionUpdate_guess* input_guess = (DescriptionUpdate_guess*)data_guess;
        // The current ticket's details (64-char name, 4000-char text).
        message_state_guess.field_00_guess = input_guess->field_04_guess;
        message_state_guess.field_08_guess = input_guess->field_08_guess;
        message_state_guess.field_0c_guess = input_guess->field_0c_guess;
        message_state_guess.field_10_guess = input_guess->field_10_guess;
        message_state_guess.field_14_guess = input_guess->field_14_guess;
        strncpy(message_state_guess.text_18_guess, input_guess->name_18_guess, 0x40);
        message_state_guess.field_5c_guess = input_guess->field_5c_guess;
        message_state_guess.field_60_guess = input_guess->field_60_guess;
        message_state_guess.field_64_guess = input_guess->field_6c_guess;
        strncpy(message_state_guess.text_68_guess, input_guess->text_70_guess, 4000);
        Forward_guess();
        first_guess = 1;
        return;
    }
    if (code_guess == 0x70ff) {
        // Knowledge-base results; `count_guess` is not checked against the 20 slots.
        memset(list_b018_guess, 0, 0x1950);
        ListUpdate_guess* input_guess = (ListUpdate_guess*)data_guess;
        if (input_guess->count_guess > 0) {
            ListEntry_guess* inputEntry_guess = input_guess->entries_guess;
            ListEntry_guess* outputEntry_guess = list_b018_guess;
            int entryIndex_guess = 0;
            do {
                strncpy(outputEntry_guess->first_guess, inputEntry_guess->first_guess, 0x41);
                strncpy(outputEntry_guess->second_guess, inputEntry_guess->second_guess, 0x100);
                outputEntry_guess->field_142_guess = inputEntry_guess->field_142_guess;
                ++outputEntry_guess;
                ++entryIndex_guess;
                ++inputEntry_guess;
            } while (entryIndex_guess < input_guess->count_guess);
        }
        ShowKnowledgeBaseResults_guess();
        return;
    }
}

