// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 26: a hint from compare/tumap.py.
// The client task system. TaskManager_guess is the task manager; TaskManagerView_guess (the packet dispatcher),
// LookupOwner_guess, RecordTable_guess, ValueOwner_guess and MessageOwner_guess are views of it. Slots are
// TaskSlot_guess: one task (category 0), one shared task (1), 19 more, probably quests (2), then 50 completed
// tasks. EQ_CharacterView_guess is pCharData's task progress; windows: CTaskWnd, CTaskTemplateSelectWnd.
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "titanium/wnd/CTaskSelectWnd.h"

struct Part_guess {
    int pad00_guess;
    int first_guess;
    int second_guess;
    int pad0c_guess;
    char tail_guess;
    // EXTERNAL: TITANIUM 0x0050F3F6 Part_guess::Reset_guess
    void Reset_guess();
};

struct Owner_guess {
    char pad[0x14];
    Part_guess part;
    void DestroyPart_guess();
};

struct Record_guess {
    int first_guess;
    int second_guess;
    char bytes_guess[0x14];
    int words_guess[0x14];
    void Clear_guess();
    Record_guess* Initialize_guess();
};

struct EQ_CharacterView_guess {
    char prefix_guess[0x38];
    Record_guess first_guess[1];
    Record_guess rest_guess[0x13];
    char middle_guess[0x818];
    int field10c0_guess;                // 0x10C0
    char middle_tail_guess[4];
    Record_guess special_guess;
    Record_guess* First_guess(unsigned int index_guess);
    Record_guess* Rest_guess(unsigned int index_guess);
};

struct IndexedRecord_guess {
    char data_guess[0x2834];
};

struct RecordTable_guess {
    char prefix_guess[0x34c48];
    IndexedRecord_guess records_guess[0x32];
    IndexedRecord_guess* At_guess(int index_guess);
    void InitializeAll_guess();
    void Handle_OP_CompletedTasks_guess(int unused_guess, const char* data_guess);
    void Handle_OP_TaskHistoryReply_guess(int unused_guess, const char* data_guess);
};

struct LinkNode_guess {
    char prefix_guess[0x48];
    LinkNode_guess* next_guess;
};

struct ValueNode_guess {
    char prefix_guess[0x40];
    int value_guess;
    int padding_guess;
    ValueNode_guess* next_guess;
};

struct UpdateData_guess {
    char prefix_guess[8];
    char key_guess[0x40];
    int value_guess;
};

struct ValueToggle_guess {
    int first_guess;                    // 0x0000
    int second_guess;                   // 0x0004
    char flag_guess;                    // 0x0008
    char name_guess[0x40];              // 0x0009
};

struct ValueOwner_guess {
    char prefix_guess[0xb26b8];
    ValueNode_guess* first_guess;
    void Clear_guess();
    int CountValue_guess(int value_guess);
    void Update_guess(UpdateData_guess* data_guess, int unused_guess);
    void Add_guess(const char* name_guess);
    void Remove_guess(const char* name_guess);
    void Handle_OP_TaskMemberChange_guess(ValueToggle_guess* data_guess);
    void Handle_OP_SharedTaskMemberList_guess(const void* source_guess);
};

struct RequestLootSlot_guess {
    int firstValue_guess;              // 0x0000
    int secondValue_guess;             // 0x0004
    int count_guess;                   // 0x0008
    LinkNode_guess* first_guess;       // 0x000c
    LinkNode_guess* last_guess;        // 0x0010
    void Append_guess(LinkNode_guess* node_guess);
    int Load_guess(const void* source_guess, int unused_guess);
};

struct Buffer_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    char data_guess[0x1000];
    Buffer_guess* Initialize_guess();
};

struct CopyData_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    char value_guess;
    char tail_guess[0x40];
    int CopyText_guess(const CopyData_guess* source_guess, unsigned int length_guess);
    CopyData_guess* CopyFrom_guess(const CopyData_guess* source_guess);
    int CopyHeader_guess(const void* source_guess, int length_guess);
};

struct CopyItem_guess : CopyData_guess {
    // EXTERNAL: TITANIUM 0x00432061 CopyItem_guess::CopyItem_guess
    CopyItem_guess();
};

// EXTERNAL: TITANIUM 0x00401000 ??_H@YGXPAXIHP6EPAX0@Z@Z

struct CopyList_guess {
    int capacity_guess;                 // 0x0000
    CopyData_guess* items_guess;        // 0x0004
    int allocated_guess;                // 0x0008
    char flag_guess;                    // 0x000C
    void Grow_guess(int count_guess);
    void Set_guess(int index_guess, const CopyData_guess* source_guess);
    // EXTERNAL: TITANIUM 0x0050F3F6 CopyList_guess::~CopyList_guess
    ~CopyList_guess();
};

struct CopyObject_guess {
    int first_guess;                    // 0x0000
    int second_guess;                   // 0x0004
    int fourth_guess;                   // 0x0008
    int third_guess;                    // 0x000C
    char flag_guess;                    // 0x0010
    CopyList_guess list_guess;          // 0x0014
    CopyObject_guess() {
        list_guess.items_guess = 0;
        list_guess.capacity_guess = 0;
        list_guess.allocated_guess = 0;
        list_guess.flag_guess = 1;
    }
    int Load_guess(const void* source_guess, int length_guess);
};

struct TaskMemberNode_guess {
    char data_guess[0x40];
    int first_guess;
    int second_guess;
    int third_guess;
    TaskMemberNode_guess* Initialize_guess();
    int Parse_guess(const char* text_guess);
};

struct TaskActivity_guess {
    int first_guess;
    int second_guess;
    char first_data_guess[0x40];
    char second_data_guess[0x40];
    int values_guess[4];
    char flag_guess;
    char flag_pad_guess[3];
    int tail_values_guess[2];
    char tail_data_guess[0x80];
    void Clear_guess();
};

struct TaskSlot_guess {
    int count_guess;                            // 0x0000
    char name_guess[0x40];                      // 0x0004
    int field44_guess;                          // 0x0044
    int field48_guess;                          // 0x0048
    char data4c_guess[0x800];                   // 0x004C
    char flag84c_guess;                         // 0x084C
    int field850_guess;                         // 0x0850
    int field854_guess;                         // 0x0854
    int field858_guess;                         // 0x0858
    char data85c_guess[0x60];                   // 0x085C
    int field8bc_guess;                         // 0x08BC
    char data8c0_guess[0x80];                   // 0x08C0
    TaskActivity_guess records_guess[0x14];      // 0x0940
    int field2010_guess;                        // 0x2010
    int field2014_guess;                        // 0x2014
    char flag2018_guess;                        // 0x2018
    char data2019_guess[0x800];                 // 0x2019
    char flag2819_guess;                        // 0x2819
    int field281c_guess;                        // 0x281C
    Part_guess part_guess;                      // 0x2820
    // EXTERNAL: TITANIUM 0x00432C38 TaskSlot_guess::TaskSlot_guess
    TaskSlot_guess();
    // EXTERNAL: TITANIUM 0x00432C72 TaskSlot_guess::~TaskSlot_guess
    ~TaskSlot_guess();
    void Initialize_guess();
};

struct RuleText_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00572060 RuleText_guess::AppendCharacter_guess
    void AppendCharacter_guess(char character_guess);
    // EXTERNAL: TITANIUM 0x00572130 RuleText_guess::AppendRange_guess
    void AppendRange_guess(const CXStr* text_guess, unsigned int length_guess);
    // EXTERNAL: TITANIUM 0x00572F20 RuleText_guess::AppendString_guess
    void AppendString_guess(const CXStr* text_guess, const CXStr* suffix_guess);
    // EXTERNAL: TITANIUM 0x00572C10 RuleText_guess::Add_guess
    void Add_guess(const CXStr* text_guess);
    // EXTERNAL: TITANIUM 0x005738D0 RuleText_guess::Contains_guess
    char Contains_guess(const CXStr* first_guess, const CXStr* second_guess);
};

struct IndexSet_guess {
    int count_guess;
    int values_guess[3];
    // EXTERNAL: TITANIUM 0x00424631 IndexSet_guess::IndexSet_guess
    IndexSet_guess();
    // EXTERNAL: TITANIUM 0x004D99C0 IndexSet_guess::~IndexSet_guess
    ~IndexSet_guess();
    // EXTERNAL: TITANIUM 0x0050319B IndexSet_guess::Parse_guess
    void Parse_guess(int value_guess, int* end_guess);
    // EXTERNAL: TITANIUM 0x004EB924 IndexSet_guess::At_guess
    int* At_guess(int index_guess);
};

struct TaskProgressView_guess {
    char prefix_guess[0x1c];
    int values_guess[0x14];
};

struct RuleParser_guess {
    void FormatActivityText_guess(TaskActivity_guess* record_guess, char* output_guess);
    void BuildDescription_guess(TaskSlot_guess* state_guess, TaskProgressView_guess* context_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatNumber_guess
void __cdecl FormatNumber_guess(CXStr* output_guess, const char* format_guess, int value_guess);

// EXTERNAL: TITANIUM 0x00576D80 FindNumberEnd_guess
int __cdecl FindNumberEnd_guess(const char** text_guess, int delimiter_guess);

// EXTERNAL: TITANIUM 0x0060F3DC _isdigit
extern "C" int __cdecl _isdigit(int character_guess);

struct LookupEntry_guess {
    int value_guess;
    char padding_guess[0x2830];
};

struct LookupOwner_guess {
    char prefix_guess[4];
    LookupEntry_guess first_guess[1];
    LookupEntry_guess entries_guess[19];
    LookupEntry_guess last_guess[1];
    int* Get_guess(int index_guess, int category_guess, char allowEmpty_guess);
    Record_guess* GetRecord_guess(EQ_CharacterView_guess* owner_guess, int index_guess, int category_guess);
    void Handle_OP_CancelTask_guess(EQ_CharacterView_guess* owner_guess, int index_guess, int category_guess);
    void Handle_OP_TaskDescription_guess(EQ_CharacterView_guess* owner_guess, const char* source_guess);
};

struct MessageData_guess {
    int first_guess;
    int second_guess;
    unsigned char flag_guess;
};

struct MessageInput_guess {
    int first_guess;
    int state_guess;
    char data_guess[0x40];
    char tail_guess[0x40];
};

struct MessageOwner_guess {
    char prefix_guess[0xb2670];
    int state_guess;
    void Handle_OP_TaskMemberInvite_guess(MessageInput_guess* input_guess);
    void OnInviteAnswer_guess(int message_guess, unsigned char flags_guess, int unused_guess);
};

struct RefreshOwner_guess {
    // EXTERNAL: TITANIUM 0x0055FA4C RefreshOwner_guess::RefreshSharedTaskMembers_guess
    void RefreshSharedTaskMembers_guess();
    // EXTERNAL: TITANIUM 0x0055F192 RefreshOwner_guess::RefreshRecords_guess
    void RefreshRecords_guess(void* state_guess);
    // EXTERNAL: TITANIUM 0x005A1CD0 RefreshOwner_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x0055F706 RefreshOwner_guess::RequestRefresh_guess
    void RequestRefresh_guess();
    // EXTERNAL: TITANIUM 0x00469DD7 RefreshOwner_guess::Apply_guess
    void Apply_guess();
};

struct NotifyOwner_guess {
    char padding_guess[0x5c];
    char enabled_guess;
    // EXTERNAL: TITANIUM 0x0055D0DD NotifyOwner_guess::RebuildLists_guess
    void RebuildLists_guess();
    // EXTERNAL: TITANIUM 0x0055D8BA NotifyOwner_guess::Flush_guess
    void Flush_guess();
    // EXTERNAL: TITANIUM 0x0055D222 NotifyOwner_guess::SendData_guess
    void SendData_guess(void* data_guess);
    // EXTERNAL: TITANIUM 0x0055D1F3 NotifyOwner_guess::SendText_guess
    void SendText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0055D283 NotifyOwner_guess::ShowTemplate_guess
    void ShowTemplate_guess();
};

// Same object seen through its vtable: the call goes to slot 0x84 / 4 = 33.
struct NotifySlots_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
    virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
    virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
    virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
};

struct ScanEntry_guess {
    int value_guess;
    char tail_guess[0x2830];
};

struct ScanOwner_guess {
    char prefix_guess[0x34c34];
    ScanEntry_guess entries_guess[2];
    char HasPositive_guess();
};

struct IndexedData_guess {
    int count_guess;
    char* data_guess;
    // EXTERNAL: TITANIUM 0x00405492 IndexedData_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    char* Get_guess(int index_guess);
};

struct DispatchRecord_guess {
    char selected_guess;
    char padding_guess[3];
    int id_guess;
    char middle_guess[0x281c];
    IndexedData_guess entries_guess;
    char tail_guess[8];
};

struct DispatchMessageData_guess {
    int first_guess;
    int second_guess;
    int id_guess;
    union {
        int state_guess;
        const char* text_guess;
    } tail_guess;
};

struct DispatchLookupData_guess {
    int first_guess;
    int second_guess;
    int id_guess;
    unsigned char value_guess;
    char padding_guess[3];
    int lineMode_guess;
    int enabled_guess;
};

struct DispatchLine_guess;

struct TaskManagerView_guess {
    DispatchRecord_guess records_guess[0x22];
    // EXTERNAL: TITANIUM 0x0055C13B TaskManagerView_guess::HandleData_guess
    void HandleData_guess(void* data_guess);
    void Handle_OP_TaskActivity_guess(EQ_Character* character_guess, void* data_guess);
    void LoadCopy_guess(int source_guess, int length_guess);
    void HandleTaskMessage_guess(int message_guess, void* data_guess, int extra_guess);
};

struct DispatchLine_guess {
    // EXTERNAL: TITANIUM 0x0040812F DispatchLine_guess::Show_guess
    void Show_guess();
};

// EXTERNAL: TITANIUM 0x00407DC9 CreateLine_guess
DispatchLine_guess* __stdcall CreateLine_guess(char* text_guess, int type_guess, int first_guess, int color_guess, int x_guess, int y_guess, int time_guess);

struct CharacterAction_guess {
    // EXTERNAL: TITANIUM 0x004BB006 CharacterAction_guess::Set_guess
    void Set_guess(int value_guess);
};

struct ChatFilter_guess {
    // EXTERNAL: TITANIUM 0x004C9815 ChatFilter_guess::Check_guess
    int Check_guess(const char* text_guess);
};

struct CharacterTail_guess {
    EQ_Character base_guess;
    char padding_guess[0xe50 - sizeof(EQ_Character)];
    int value_guess;
};

struct ChatSettings_guess {
    char padding_guess[0x148];
    int value_guess;
};

struct SearchOwner_guess {
    // EXTERNAL: TITANIUM 0x00490D71 SearchOwner_guess::GetOrCreateCachedItem_guess
    void GetOrCreateCachedItem_guess(int value_guess, void* data_guess);
};

#define g_messageTable_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_copyDefault_guess EQ_ARRAY(char, 0x0063F9FC)
#define pinstCTaskWnd_guess EQ_GLOBAL(RefreshOwner_guess*, 0x00992858)
#define pinstCTaskTemplateSelectWnd_guess EQ_GLOBAL(NotifyOwner_guess*, 0x0099283C)
#define g_taskTemplates_guess EQ_GLOBAL(ChatFilter_guess*, 0x00985CEC)
#define g_chatSettings_guess EQ_GLOBAL(ChatSettings_guess*, 0x00905D24)
#define g_searchOwner_guess EQ_GLOBAL(SearchOwner_guess*, 0x00903EA0)

struct FormatEntry_guess {
    int key_guess;
    int alternateValue_guess;
    int defaultValue_guess;
};

struct FormatString_guess {
    char padding_guess[0x208];
    const char* text_guess;
};

struct FormatStrings_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 FormatStrings_guess::Get_guess
    FormatString_guess* Get_guess(int index_guess);
};

#define g_formatCount_guess EQ_GLOBAL(int, 0x006970E8)
#define g_formatEntries_guess EQ_ARRAY(FormatEntry_guess, 0x00697058)
#define g_formatStrings_guess EQ_GLOBAL(FormatStrings_guess*, 0x00985CC8)
#define g_formatStringIds_guess EQ_ARRAY(unsigned long*, 0x00851200)

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x00576FA0 CopyTail_guess
void __cdecl CopyTail_guess(char* destination_guess, const char* source_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x00577000 CopyTextHelper_guess
int __cdecl CopyTextHelper_guess(char* destination_guess, int size_guess, const char* default_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x00574310 CopyBuffer_guess
void __cdecl CopyBuffer_guess(char* destination_guess, const char* source_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0046D46D ConvertItemTags
void __cdecl ConvertItemTags(CXStr& text_guess, int flag_guess);

// EXTERNAL: TITANIUM 0x0046DA4A BuildMessage_guess
void __cdecl BuildMessage_guess(char* buffer_guess, int type_guess, const char* tail_guess, const char* data_guess, const char* a_guess, const char* b_guess, const char* c_guess, int d_guess, int e_guess, int f_guess, int g_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// Clears a progress record: task id, +4, and the 20 activity done-flags and done-counts.
// FUNCTION: TITANIUM 0x00432043
void Record_guess::Clear_guess() {
    first_guess = 0;
    second_guess = 0;
    int index_guess = 0;
    int* word_guess = words_guess;
    do {
        bytes_guess[index_guess] = 0;
        *word_guess = 0;
        ++index_guess;
        ++word_guess;
    } while (index_guess < 0x14);
}

// Reads one 0x54-byte list entry from a packet: four ints, a flag byte, a name of up to 64 chars;
// returns the bytes used.
// FUNCTION: TITANIUM 0x0043208A
int CopyData_guess::CopyText_guess(const CopyData_guess* source_guess, unsigned int length_guess) {
    int result_guess = 0;
    if (length_guess > 4) {
        char value_guess = 0;
        memcpy(&first_guess, source_guess, 4);
        memcpy(&second_guess, (const char*)source_guess + 4, 4);
        memcpy(&third_guess, (const char*)source_guess + 8, 4);
        memcpy(&fourth_guess, (const char*)source_guess + 12, 4);
        memcpy(&value_guess, (const char*)source_guess + 0x10, 1);
        result_guess = CopyTextHelper_guess(tail_guess, 0x3f, g_copyDefault_guess, (const char*)source_guess + 0x11);
        result_guess += 0x12;
        this->value_guess = value_guess != 0;
    }
    return result_guess;
}

// Assignment of a 0x54-byte list entry: the four ints, the flag and the name (up to 64 chars).
// FUNCTION: TITANIUM 0x0043210E
CopyData_guess* CopyData_guess::CopyFrom_guess(const CopyData_guess* source_guess) {
    first_guess = source_guess->first_guess;
    second_guess = source_guess->second_guess;
    third_guess = source_guess->third_guess;
    fourth_guess = source_guess->fourth_guess;
    value_guess = source_guess->value_guess;
    CopyTail_guess(tail_guess, source_guess->tail_guess, 0x40);
    return this;
}

// Zeroes a shared-task member node (0x4C bytes): name, int, flag, next.
// FUNCTION: TITANIUM 0x00432149
TaskMemberNode_guess* TaskMemberNode_guess::Initialize_guess() {
    memset(data_guess, 0, 0x40);
    second_guess = 0;
    first_guess = 0;
    third_guess = 0;
    return this;
}

// Reads a member from a packet: name, int, flag byte; returns the bytes used.
// FUNCTION: TITANIUM 0x00432169
int TaskMemberNode_guess::Parse_guess(const char* text_guess) {
    int offset_guess = 0;
    if (text_guess != 0) {
        offset_guess = sprintf(data_guess, "%s", text_guess) + 1;
        memcpy(&first_guess, text_guess + offset_guess, 4);
        offset_guess += 4;
        second_guess = text_guess[offset_guess];
        ++offset_guess;
    }
    return offset_guess;
}

// Appends a shared-task member node at the tail of the member list; the member-list reader (0x004328EF)
// adds each member with it.
// FUNCTION: TITANIUM 0x004321AC
void RequestLootSlot_guess::Append_guess(LinkNode_guess* node_guess) {
    if (node_guess != 0) {
        if (first_guess == 0)
            first_guess = node_guess;
        else
            last_guess->next_guess = node_guess;
        last_guess = node_guess;
    }
}

// Zeroes a 16-byte header and a 4 KB buffer for the template packet.
// FUNCTION: TITANIUM 0x004321CB
Buffer_guess* Buffer_guess::Initialize_guess() {
    second_guess = 0;
    first_guess = 0;
    third_guess = 0;
    fourth_guess = 0;
    memset(data_guess, 0, 0x1000);
    return this;
}

// Reads the template packet's four-int header; returns 16.
// FUNCTION: TITANIUM 0x004321F1
int CopyData_guess::CopyHeader_guess(const void* source_guess, int length_guess) {
    int size_guess = 0;
    if (source_guess != 0) {
        memcpy(&first_guess, source_guess, 4);
        memcpy(&second_guess, (const char*)source_guess + 4, 4);
        memcpy(&third_guess, (const char*)source_guess + 8, 4);
        memcpy(&fourth_guess, (const char*)source_guess + 12, 4);
        size_guess = 0x10;
    }
    return size_guess;
}

// Frees the shared-task member list (+0xB26B8).
// FUNCTION: TITANIUM 0x00432240
void ValueOwner_guess::Clear_guess() {
    while (first_guess != 0) {
        ValueNode_guess* node_guess = first_guess;
        first_guess = node_guess->next_guess;
        free(node_guess);
    }
    first_guess = 0;
}

// Default list entry: ints 0, 1, 1, 0, flag 1, empty name. This is CopyItem_guess's constructor
// (the EXTERNAL above); the Record_guess view is a misname.
// FUNCTION: TITANIUM 0x00432061
Record_guess* Record_guess::Initialize_guess() {
    CopyData_guess* data_guess = (CopyData_guess*)this;
    data_guess->first_guess = 0;
    data_guess->second_guess = 1;
    data_guess->third_guess = 1;
    data_guess->fourth_guess = 0;
    data_guess->value_guess = 1;
    memset(data_guess->tail_guess, 0, 0x40);
    return this;
}

// Clears an activity record (0x124 bytes).
// FUNCTION: TITANIUM 0x0043226D
void TaskActivity_guess::Clear_guess() {
    first_guess = 0;
    second_guess = 0;
    memset(first_data_guess, 0, 0x40);
    memset(second_data_guess, 0, 0x40);
    values_guess[0] = 0;
    values_guess[1] = 0;
    values_guess[2] = 0;
    values_guess[3] = 0;
    flag_guess = 0;
    tail_values_guess[0] = 0;
    tail_values_guess[1] = 0;
    memset(tail_data_guess, 0, 0x80);
}

// The slot for (`index_guess`, `category_guess`): category 0 the task, 1 the shared task, 2 slot 0-18.
// `allowEmpty_guess` != 0 actually rejects an empty slot (id 0), so the name is inverted.
// FUNCTION: TITANIUM 0x004322D2
int* LookupOwner_guess::Get_guess(int index_guess, int category_guess, char allowEmpty_guess) {
    int* result_guess = 0;
    int* entry_guess;
    switch (category_guess) {
    case 0:
        if (index_guess >= 0 && index_guess < 1) {
            entry_guess = &first_guess[index_guess].value_guess;
            if (*entry_guess != 0 || allowEmpty_guess == 0)
                result_guess = entry_guess;
        }
        break;
    case 1:
        if (index_guess >= 0 && index_guess < 1) {
            entry_guess = &last_guess[index_guess].value_guess;
            if (*entry_guess != 0 || allowEmpty_guess == 0)
                result_guess = entry_guess;
        }
        break;
    case 2:
        if (index_guess >= 0 && index_guess < 0x13) {
            entry_guess = &entries_guess[index_guess].value_guess;
            if (*entry_guess != 0 || allowEmpty_guess == 0)
                result_guess = entry_guess;
        }
        break;
    }
    return result_guess;
}

// Completed-task entry 0-49.
// FUNCTION: TITANIUM 0x0043233F
IndexedRecord_guess* RecordTable_guess::At_guess(int index_guess) {
    IndexedRecord_guess* record_guess = 0;
    if (index_guess >= 0 && index_guess < 0x32)
        record_guess = &records_guess[index_guess];
    return record_guess;
}

// Slots per category: 1, 1, 19.
// FUNCTION: TITANIUM 0x0043235E
int __stdcall GetSlotCount_guess(int code_guess) {
    int result_guess = 0;
    switch (code_guess) {
    case 0:
        result_guess = 1;
        break;
    case 1:
        result_guess = 1;
        break;
    case 2:
        result_guess = 0x13;
        break;
    }
    return result_guess;
}

// Handle_OP_TaskHistoryReply: the activities of completed task `index` (up to 20: type, target, item,
// goal, string and spell ids, text), then refreshes CTaskWnd.
// FUNCTION: TITANIUM 0x00432379
void RecordTable_guess::Handle_OP_TaskHistoryReply_guess(int unused_guess, const char* data_guess) {
    const char* cursor_guess = data_guess;
    int index_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    if (index_guess < 0 || index_guess >= 0x32)
        return;
    int entry_guess = 0;
    TaskSlot_guess* state_guess = (TaskSlot_guess*)&records_guess[index_guess];
    int count_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    for (; entry_guess < count_guess; ++entry_guess) {
        if (entry_guess >= 0x14)
            break;
        TaskActivity_guess* record_guess = &state_guess->records_guess[entry_guess];
        record_guess->first_guess = *(const int*)cursor_guess;
        cursor_guess += 4;
        CopyBuffer_guess(record_guess->first_data_guess, cursor_guess, 0x40);
        cursor_guess += strlen(cursor_guess) + 1;
        CopyBuffer_guess(record_guess->second_data_guess, cursor_guess, 0x80);
        cursor_guess += strlen(cursor_guess) + 1;
        record_guess->values_guess[3] = *(const int*)cursor_guess;
        cursor_guess += 4;
        record_guess->values_guess[1] = *(const int*)cursor_guess;
        cursor_guess += 4;
        record_guess->values_guess[2] = *(const int*)cursor_guess;
        cursor_guess += 4;
        record_guess->values_guess[0] = *(const int*)cursor_guess;
        cursor_guess += 4;
        record_guess->tail_values_guess[1] = *(const int*)cursor_guess;
        cursor_guess += 4;
        CopyBuffer_guess(record_guess->tail_data_guess, cursor_guess, 0x80);
        cursor_guess += strlen(cursor_guess) + 1;
    }
    state_guess->flag2819_guess = 1;
    if (pinstCTaskWnd_guess != 0)
        pinstCTaskWnd_guess->RefreshRecords_guess(state_guess);
}

// One activity's text: the server's own text (+0xA4) if any, else the message for activity type
// `first_guess` from the table at 0x697058 (alternate id when a target is named), filled with the goal
// count, target, item, a spell name (0x985CC8 is the spell manager) and a string-table entry (<100).
// FUNCTION: TITANIUM 0x00432477
void RuleParser_guess::FormatActivityText_guess(TaskActivity_guess* record_guess, char* output_guess) {
    char lookupText_guess[0x100];
    char stringText_guess[0x100];
    if (record_guess->tail_data_guess[0] != 0) {
        strcpy(output_guess, record_guess->tail_data_guess);
    } else {
        int index_guess = 0;
        int found_guess = 0;
        if (g_formatCount_guess > 0) {
            do {
                if (record_guess->first_guess == g_formatEntries_guess[index_guess].key_guess) {
                    if (index_guess != -1)
                        found_guess = 1;
                    break;
                }
                ++index_guess;
            } while (index_guess < g_formatCount_guess);
        }
        if (!found_guess)
            // Overwritten below, and the code then reads the entry one past the table (original).
            sprintf(output_guess, "Unknown index %d.", record_guess->first_guess);
        int message_guess = g_formatEntries_guess[index_guess].defaultValue_guess;
        if (record_guess->first_data_guess[0] != 0)
            message_guess = g_formatEntries_guess[index_guess].alternateValue_guess;
        lookupText_guess[0] = 0;
        if (record_guess->values_guess[2] != -1) {
            FormatString_guess* string_guess = g_formatStrings_guess->Get_guess(record_guess->values_guess[2]);
            if (string_guess != 0)
                strcpy(lookupText_guess, string_guess->text_guess);
        }
        stringText_guess[0] = 0;
        if (record_guess->values_guess[1] != -1 && record_guess->values_guess[1] < 100)
            strcpy(stringText_guess, pStringTable->getString(*g_formatStringIds_guess[record_guess->values_guess[1]], 0));
        BuildMessage_guess(output_guess, message_guess,
            _itoa(record_guess->values_guess[3], EQ_ARRAY(char, 0x0099DB00), 10), record_guess->first_data_guess,
            record_guess->second_data_guess, lookupText_guess, stringText_guess, 0, 0, 0, 0);
    }
}

// Handle_OP_TaskMemberInvite: asks the player with a confirmation dialog (string 0x22E6: inviter, task);
// the answer comes back through OnInviteAnswer_guess. +0xB2670 keeps the request id.
// FUNCTION: TITANIUM 0x004325B9
void MessageOwner_guess::Handle_OP_TaskMemberInvite_guess(MessageInput_guess* input_guess) {
    char buffer_guess[0x1004];
    if (input_guess != 0) {
        state_guess = input_guess->state_guess;
        BuildMessage_guess(buffer_guess, 0x22e6, input_guess->tail_guess, input_guess->data_guess, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(this, 0x79b4, buffer_guess, 0xc, -1, 0, 1);
    }
}

// Sets the int of the member named in `data_guess`, then refreshes both task windows.
// FUNCTION: TITANIUM 0x00432634
void ValueOwner_guess::Update_guess(UpdateData_guess* data_guess, int unused_guess) {
    if (data_guess != 0 && first_guess != 0) {
        ValueNode_guess* node_guess = first_guess;
        do {
            if (_stricmp((const char*)node_guess, data_guess->key_guess) == 0) {
                node_guess->value_guess = data_guess->value_guess;
                if (pinstCTaskWnd_guess != 0)
                    pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
                if (pinstCTaskTemplateSelectWnd_guess != 0)
                    pinstCTaskTemplateSelectWnd_guess->RebuildLists_guess();
                return;
            }
            node_guess = node_guess->next_guess;
        } while (node_guess != 0);
    }
}


// How many shared-task members have the int `value`; the task template window counts with it.
// FUNCTION: TITANIUM 0x0043268C
int ValueOwner_guess::CountValue_guess(int value_guess) {
    int result_guess = 0;
    for (ValueNode_guess* node_guess = first_guess; node_guess != 0; node_guess = node_guess->next_guess) {
        if (node_guess->value_guess == value_guess)
            ++result_guess;
    }
    return result_guess;
}

// Appends a member by name, then refreshes CTaskWnd and CTaskTemplateSelectWnd.
// FUNCTION: TITANIUM 0x004326AA
void ValueOwner_guess::Add_guess(const char* name_guess) {
    TaskMemberNode_guess* node_guess = (TaskMemberNode_guess*)operator new(0x4c);
    if (node_guess != 0) {
        node_guess = node_guess->Initialize_guess();
    } else {
        node_guess = 0;
    }
    strncpy(node_guess->data_guess, name_guess, 0x40);
    node_guess->third_guess = 0;
    ValueNode_guess* link_guess = (ValueNode_guess*)node_guess;
    if (first_guess == 0) {
        first_guess = link_guess;
    } else {
        ValueNode_guess* current_guess = first_guess;
        while (current_guess != 0) {
            if (current_guess->next_guess == 0) {
                current_guess->next_guess = link_guess;
                break;
            }
            current_guess = current_guess->next_guess;
        }
    }
    if (pinstCTaskWnd_guess != 0)
        pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
    if (pinstCTaskTemplateSelectWnd_guess != 0)
        pinstCTaskTemplateSelectWnd_guess->RebuildLists_guess();
}

// Unlinks the member named `name_guess` and refreshes the windows.
// FUNCTION: TITANIUM 0x00432721
void ValueOwner_guess::Remove_guess(const char* name_guess) {
    if (first_guess != 0) {
        if (strcmp(name_guess, (const char*)first_guess) == 0) {
            // The head node is unlinked but never freed (original leak); later matches are freed.
            first_guess = first_guess->next_guess;
        } else {
            ValueNode_guess* node_guess = first_guess;
            while (node_guess != 0) {
                ValueNode_guess* next_guess = node_guess->next_guess;
                if (next_guess != 0 && strcmp(name_guess, (const char*)next_guess) == 0) {
                    node_guess->next_guess = next_guess->next_guess;
                    free(next_guess);
                }
                node_guess = node_guess->next_guess;
            }
        }
        if (pinstCTaskWnd_guess != 0)
            pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
        if (pinstCTaskTemplateSelectWnd_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->RebuildLists_guess();
    }
}

// The invite dialog's answer: sends TaskMemberInviteResponse with the request id and accept = button
// flags & 5.
// FUNCTION: TITANIUM 0x004327A8
void MessageOwner_guess::OnInviteAnswer_guess(int message_guess, unsigned char flags_guess, int unused_guess) {
    if (message_guess == 0x79b4) {
        MessageData_guess data_guess;
        data_guess.flag_guess = (flags_guess & 5) != 0;
        data_guess.second_guess = state_guess;
        EQSendMessage(&g_messageTable_guess, 0x358, &data_guess, 0xc, 1);
    }
}

// Whether the shared task's entry list (+0x34C34) is non-empty; the loop covers its one slot.
// FUNCTION: TITANIUM 0x004327E8
char ScanOwner_guess::HasPositive_guess() {
    int index_guess = 0;
    ScanEntry_guess* entry_guess = entries_guess;
    do {
        if (entry_guess->value_guess > 0)
            return 1;
        ++index_guess;
        ++entry_guess;
    } while (index_guess < 1);
    return 0;
}

// Entry `index_guess` (0x54 bytes) of that list; out of range raises (0x405492).
// FUNCTION: TITANIUM 0x00432806
char* IndexedData_guess::Get_guess(int index_guess) {
    if (index_guess < count_guess && index_guess >= 0 && data_guess != 0)
        return data_guess + index_guess * 0x54;
    Fail_guess();
}

// Reads the member-list packet: two ints, a count, then the members.
// FUNCTION: TITANIUM 0x004328EF
int RequestLootSlot_guess::Load_guess(const void* source_guess, int unused_guess) {
    int offset_guess = 0;
    if (source_guess != 0) {
        memcpy(&firstValue_guess, source_guess, 4);
        memcpy(&secondValue_guess, (const char*)source_guess + 4, 4);
        memcpy(&count_guess, (const char*)source_guess + 8, 4);
        int index_guess = 0;
        offset_guess = 0xc;
        while (index_guess < count_guess) {
            TaskMemberNode_guess* node_guess = (TaskMemberNode_guess*)operator new(0x4c);
            if (node_guess != 0) {
                node_guess = node_guess->Initialize_guess();
            } else {
                node_guess = 0;
            }
            offset_guess += node_guess->Parse_guess((const char*)source_guess + offset_guess);
            Append_guess((LinkNode_guess*)node_guess);
            ++index_guess;
        }
    }
    return offset_guess;
}

// Empties a task slot. Layout: id +0, title +4, formatted description +0x4C, reward flag +0x84C with text
// +0x85C and item link +0x8C0, 20 activities at +0x940, type +0x2010, raw description +0x2019, history
// loaded +0x2819, completion time +0x281C, entry list +0x2820.
// FUNCTION: TITANIUM 0x00432995
void TaskSlot_guess::Initialize_guess() {
    count_guess = 0;
    memset(name_guess, 0, 0x40);
    field44_guess = 0;
    field48_guess = 0;
    memset(data4c_guess, 0, 0x800);
    flag84c_guess = 0;
    field850_guess = 0;
    field854_guess = 0;
    field858_guess = 0;
    memset(data85c_guess, 0, 0x60);
    field8bc_guess = 0;
    memset(data8c0_guess, 0, 0x80);
    field2010_guess = 0;
    field2014_guess = 0;
    flag2018_guess = 0;
    memset(data2019_guess, 0, 0x800);
    flag2819_guess = 0;
    field281c_guess = 0;
    part_guess.tail_guess = 0;
    for (int index_guess = 0; index_guess < 0x14; ++index_guess)
        records_guess[index_guess].Clear_guess();
    part_guess.Reset_guess();
}

// Empties the 50 completed-task entries.
// FUNCTION: TITANIUM 0x00432A5B
void RecordTable_guess::InitializeAll_guess() {
    TaskSlot_guess* state_guess = (TaskSlot_guess*)records_guess;
    for (int index_guess = 0; index_guess < 0x32; ++index_guess)
        state_guess[index_guess].Initialize_guess();
}

// Handle_OP_CompletedTasks: up to 50 entries of id, name and completion time.
// FUNCTION: TITANIUM 0x00432A79
void RecordTable_guess::Handle_OP_CompletedTasks_guess(int unused_guess, const char* data_guess) {
    InitializeAll_guess();
    int count_guess = *(const int*)data_guess;
    int index_guess = 0;
    const char* cursor_guess = data_guess + 4;
    if (count_guess > 0) {
        int* tail_guess = &((TaskSlot_guess*)records_guess)[0].field281c_guess;
        do {
            if (index_guess >= 0x32)
                break;
            TaskSlot_guess* state_guess = (TaskSlot_guess*)((char*)tail_guess - 0x281C);
            state_guess->count_guess = *(const int*)cursor_guess;
            cursor_guess += 4;
            strcpy(state_guess->name_guess, cursor_guess);
            cursor_guess += strlen(cursor_guess) + 1;
            *tail_guess = *(const int*)cursor_guess;
            cursor_guess += 4;
            ++index_guess;
            tail_guess += 0x2834 / sizeof(int);
        } while (index_guess < count_guess);
    }
    if (pinstCTaskWnd_guess != 0)
        pinstCTaskWnd_guess->RequestRefresh_guess();
}

// Handle_OP_TaskMemberChange: adds (string 0x2165) or removes (0x2166) a shared-task member and says so.
// FUNCTION: TITANIUM 0x00432AF2
void ValueOwner_guess::Handle_OP_TaskMemberChange_guess(ValueToggle_guess* data_guess) {
    char buffer_guess[0x100];
    if (data_guess != 0) {
        if (data_guess->flag_guess != 0) {
            Add_guess(data_guess->name_guess);
            BuildMessage_guess(buffer_guess, 0x2165, data_guess->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0, 1);
        } else {
            Remove_guess(data_guess->name_guess);
            BuildMessage_guess(buffer_guess, 0x2166, data_guess->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0, 1);
        }
    }
}

// Handle_OP_SharedTaskMemberList: replaces the member list.
// FUNCTION: TITANIUM 0x00432B71
void ValueOwner_guess::Handle_OP_SharedTaskMemberList_guess(const void* source_guess) {
    if (source_guess != 0) {
        RequestLootSlot_guess queue_guess;
        queue_guess.count_guess = 0;
        queue_guess.first_guess = 0;
        queue_guess.last_guess = 0;
        queue_guess.Load_guess(source_guess, 1);
        Clear_guess();
        first_guess = (ValueNode_guess*)queue_guess.first_guess;
        if (pinstCTaskWnd_guess != 0)
            pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
        if (pinstCTaskTemplateSelectWnd_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->RebuildLists_guess();
    }
}

// Grows the entry list to `count_guess` * 2 + 8, copying the old entries; on failure empties it.
// FUNCTION: TITANIUM 0x00432827
// @early-stop: compiler-generated, diff ndiff=1
void CopyList_guess::Grow_guess(int count_guess) {
    if (count_guess != 0 &&
        (count_guess > allocated_guess || items_guess == 0)) {
        int newCount_guess = count_guess * 2 + 8;
        CopyData_guess* newItems_guess = new CopyItem_guess[newCount_guess];
        if (newItems_guess != 0) {
            if (items_guess != 0) {
                for (count_guess = 0; count_guess < capacity_guess; ++count_guess)
                    newItems_guess[count_guess].CopyFrom_guess(&items_guess[count_guess]);
            }
            delete[] items_guess;
            items_guess = newItems_guess;
            allocated_guess = newCount_guess;
        } else {
            delete[] items_guess;
            items_guess = 0;
            allocated_guess = 0;
            flag_guess = 0;
        }
    }
}

// ArrayClass SetElementIdx for the shared-task entries (four ints, a byte and a 64-byte text): stores a
// copy at `index`, first growing the array (0x00432827) and the length to index + 1 when needed. Negative
// indexes are ignored, and so is the store when the allocation failed.
// FUNCTION: TITANIUM 0x00432BCC
void CopyList_guess::Set_guess(int index_guess, const CopyData_guess* source_guess) {
    if (index_guess >= 0) {
        if (index_guess >= capacity_guess) {
            Grow_guess(index_guess + 1);
            if (items_guess != 0)
                capacity_guess = index_guess + 1;
        }
        if (items_guess != 0)
            items_guess[index_guess].CopyFrom_guess(source_guess);
    }
}

// pCharData progress record of the task (index 0 only).
// FUNCTION: TITANIUM 0x00432C0B
Record_guess* EQ_CharacterView_guess::First_guess(unsigned int index_guess) {
    Record_guess* records_guess = first_guess;
    if (index_guess >= 1)
        __debugbreak();
    return &records_guess[index_guess];
}

// pCharData progress record of slot `index_guess` (0-18).
// FUNCTION: TITANIUM 0x00432C20
Record_guess* EQ_CharacterView_guess::Rest_guess(unsigned int index_guess) {
    Record_guess* records_guess = rest_guess;
    if (index_guess >= 0x13)
        __debugbreak();
    return &records_guess[index_guess];
}

// The pCharData progress record of a slot; the shared task's is at +0x10C8.
// FUNCTION: TITANIUM 0x00432D17
Record_guess* LookupOwner_guess::GetRecord_guess(EQ_CharacterView_guess* owner_guess, int index_guess, int category_guess) {
    Record_guess* result_guess = 0;
    if (index_guess >= 0) {
        int count_guess = GetSlotCount_guess(category_guess);
        if (index_guess < count_guess) {
            switch (category_guess) {
            case 0:
                result_guess = owner_guess->First_guess(index_guess);
                break;
            case 1:
                result_guess = &owner_guess->special_guess;
                break;
            case 2:
                result_guess = owner_guess->Rest_guess(index_guess);
                break;
            }
        }
    }
    return result_guess;
}

// Handle_OP_CancelTask: empties the slot and its progress; for the shared task also clears the member
// list and +0x10C0.
// FUNCTION: TITANIUM 0x00432D65
void LookupOwner_guess::Handle_OP_CancelTask_guess(EQ_CharacterView_guess* owner_guess, int index_guess, int category_guess) {
    int* entry_guess = Get_guess(index_guess, category_guess, 1);
    Record_guess* record_guess = GetRecord_guess(owner_guess, index_guess, category_guess);
    if (entry_guess != 0)
        reinterpret_cast<TaskSlot_guess*>(entry_guess)->Initialize_guess();
    // Not null-checked: a bad index or category from the server crashes here.
    record_guess->Clear_guess();
    if (category_guess == 1) {
        owner_guess->field10c0_guess = 0;
        reinterpret_cast<ValueOwner_guess*>(this)->Clear_guess();
        if (pinstCTaskWnd_guess != 0)
            pinstCTaskWnd_guess->RefreshSharedTaskMembers_guess();
        if (pinstCTaskTemplateSelectWnd_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->Flush_guess();
    }
    if (pinstCTaskWnd_guess != 0)
        pinstCTaskWnd_guess->RequestRefresh_guess();
}

// Resets the part at +0x14 (0x0050F3F6).
// FUNCTION: TITANIUM 0x00433129
void Owner_guess::DestroyPart_guess() {
    part.Reset_guess();
}

// Reads the shared-task entry packet: four ints, a flag, a count, then that many entries.
// FUNCTION: TITANIUM 0x00433131
int CopyObject_guess::Load_guess(const void* source_guess, int length_guess) {
    int offset_guess = 0;
    if (source_guess != 0) {
        int count_guess = 0;
        char flag_guess = 0;
        CopyData_guess data_guess;
        memcpy(&first_guess, source_guess, 4);
        memcpy(&second_guess, (const char*)source_guess + 4, 4);
        memcpy(&third_guess, (const char*)source_guess + 8, 4);
        memcpy(&fourth_guess, (const char*)source_guess + 0xC, 4);
        memcpy(&flag_guess, (const char*)source_guess + 0x10, 1);
        memcpy(&count_guess, (const char*)source_guess + 0x11, 4);
        int index_guess = 0;
        offset_guess = 0x15;
        while (index_guess < count_guess) {
            if (offset_guess >= length_guess)
                break;
            ((Record_guess*)&data_guess)->Initialize_guess();
            offset_guess += data_guess.CopyText_guess(
                (const CopyData_guess*)((const char*)source_guess + offset_guess),
                length_guess - offset_guess);
            list_guess.Set_guess(list_guess.capacity_guess, &data_guess);
            ++index_guess;
        }
        this->flag_guess = flag_guess != 0;
    }
    return offset_guess;
}

// The owner's vtable: slot 48 (+0xC0) is called from Load_guess.
struct RefreshVirtual_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(int a_guess, int b_guess);
};

// Handle_OP_TaskDescription: the slot's id, title, two timer ints, raw description and optional reward
// (text and item link, the link through ConvertItemTags at 0x46D46D). A set `flag_guess` marks a new
// task: the slot is emptied first and CTaskWnd is told to show it.
// FUNCTION: TITANIUM 0x00432DEB
// @early-stop: budget, structural ndiff=13
void LookupOwner_guess::Handle_OP_TaskDescription_guess(EQ_CharacterView_guess* owner_guess, const char* source_guess) {
    const char* cursor_guess = source_guess;
    int index_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    int count_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    char flag_guess = *cursor_guess;
    ++cursor_guess;
    int category_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    int field2014_guess = *(const int*)cursor_guess;
    cursor_guess += 4;
    Record_guess* record_guess = GetRecord_guess(owner_guess, index_guess, category_guess);
    TaskSlot_guess* state_guess = reinterpret_cast<TaskSlot_guess*>(Get_guess(index_guess, category_guess, 0));
    if (record_guess != 0 && state_guess != 0) {
        if (flag_guess != 0)
            state_guess->Initialize_guess();
        state_guess->field2014_guess = field2014_guess;
        state_guess->count_guess = count_guess;
        state_guess->field2010_guess = category_guess;
        record_guess->first_guess = count_guess;
        state_guess->flag2018_guess = 0;
        if (state_guess->count_guess != 0) {
            strcpy(state_guess->name_guess, cursor_guess);
            cursor_guess += strlen(cursor_guess) + 1;
            state_guess->field44_guess = *(const int*)cursor_guess;
            cursor_guess += 4;
            state_guess->field48_guess = *(const int*)cursor_guess;
            cursor_guess += 4;
            record_guess->second_guess = *(const int*)cursor_guess;
            cursor_guess += 4;
            CopyBuffer_guess(state_guess->data2019_guess, cursor_guess, 0x800);
            cursor_guess += strlen(cursor_guess) + 1;
            char extra_guess = *cursor_guess;
            state_guess->flag84c_guess = extra_guess;
            ++cursor_guess;
            if (extra_guess != 0) {
                state_guess->field850_guess = *(const int*)cursor_guess;
                cursor_guess += 4;
                state_guess->field854_guess = *(const int*)cursor_guess;
                cursor_guess += 4;
                state_guess->field8bc_guess = *(const int*)cursor_guess;
                cursor_guess += 4;
                CopyBuffer_guess(state_guess->data85c_guess, cursor_guess, 0x60);
                cursor_guess += strlen(cursor_guess) + 1;
                CXStr text_guess(cursor_guess);
                ConvertItemTags(text_guess, 1);
                CopyBuffer_guess(state_guess->data8c0_guess, text_guess, 0x80);
                const int* tail_guess = (const int*)(cursor_guess + strlen(cursor_guess) + 1);
                state_guess->field858_guess = *tail_guess;
            }
        }
        if (pinstCTaskWnd_guess != 0) {
            pinstCTaskWnd_guess->RequestRefresh_guess();
            if (flag_guess != 0) {
                ((RefreshVirtual_guess*)pinstCTaskWnd_guess)->Slot48_guess(1, 1);
                pinstCTaskWnd_guess->Finish_guess();
            }
        }
        if (pinstCTaskTemplateSelectWnd_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->Flush_guess();
    }
}

// Handle_OP_TaskActivity: activity `slot_guess` (0-19, unchecked) of a slot. Type 0 clears it, -1 only
// sets its flag; otherwise flag, ids, target, item, goal, text, then pCharData's done count and flag.
// FUNCTION: TITANIUM 0x00432FD2
// @early-stop: budget, structural ndiff=38
void TaskManagerView_guess::Handle_OP_TaskActivity_guess(EQ_Character* character_guess, void* data_guess) {
    int* cursor_guess = (int*)data_guess;
    int index_guess = *cursor_guess;
    ++cursor_guess;
    int category_guess = *cursor_guess;
    cursor_guess += 2;
    LookupOwner_guess* lookup_guess = (LookupOwner_guess*)this;
    Record_guess* record_guess = lookup_guess->GetRecord_guess((EQ_CharacterView_guess*)character_guess, index_guess, category_guess);
    TaskSlot_guess* state_guess = (TaskSlot_guess*)lookup_guess->Get_guess(index_guess, category_guess, 1);
    if (record_guess != 0 && state_guess != 0) {
        state_guess->flag2018_guess = 0;
        int slot_guess = *cursor_guess;
        TaskActivity_guess* entry_guess = &state_guess->records_guess[slot_guess];
        ++cursor_guess;
        entry_guess->tail_values_guess[0] = *cursor_guess;
        ++cursor_guess;
        int first_guess = *cursor_guess;
        entry_guess->first_guess = first_guess;
        ++cursor_guess;
        if (first_guess == 0) {
            entry_guess->Clear_guess();
        } else if (first_guess != -1) {
            entry_guess->flag_guess = *cursor_guess != 0;
            ++cursor_guess;
            entry_guess->second_guess = *cursor_guess;
            ++cursor_guess;
            const char* text_guess = (const char*)cursor_guess;
            CopyBuffer_guess(entry_guess->first_data_guess, text_guess, 0x40);
            text_guess += strlen(text_guess) + 1;
            CopyBuffer_guess(entry_guess->second_data_guess, text_guess, 0x80);
            text_guess += strlen(text_guess) + 1;
            const int* tail_guess = (const int*)text_guess;
            entry_guess->values_guess[3] = tail_guess[0];
            entry_guess->values_guess[1] = tail_guess[1];
            entry_guess->values_guess[2] = tail_guess[2];
            entry_guess->values_guess[0] = tail_guess[3];
            entry_guess->tail_values_guess[1] = tail_guess[4];
            CopyBuffer_guess(entry_guess->tail_data_guess, (const char*)(tail_guess + 5), 0x80);
            const char* end_guess = (const char*)(tail_guess + 5);
            end_guess += strlen(end_guess) + 1;
            record_guess->words_guess[slot_guess] = *(const int*)end_guess;
            record_guess->bytes_guess[slot_guess] = *(const int*)(end_guess + 4) != 0;
        } else {
            entry_guess->flag_guess = *cursor_guess != 0;
        }
        if (pinstCTaskWnd_guess != 0)
            pinstCTaskWnd_guess->RequestRefresh_guess();
    }
}

// Empty base with a user dtor: its cleanup is what the ctor's EH state guards.
struct Base_guess {
    ~Base_guess();
};

// Layout from the ctor: vtable, then 1 + 0x13 + 1 + 0x32 BigState elements, then a tail.
// EXTERNAL: TITANIUM 0x00641C20 ??_7TaskManager_guess@@6B@
struct TaskManager_guess : Base_guess {
    virtual void Slot00_guess();
    TaskSlot_guess first_guess[1];          // 0x0004
    TaskSlot_guess rest_guess[0x13];        // 0x2838
    TaskSlot_guess special_guess[1];        // 0x32414
    TaskSlot_guess records_guess[0x32];     // 0x34C48
    char tail_guess[0x48];                  // 0xB2670
    int* last_guess;                        // 0xB26B8
    TaskManager_guess();
};

// The task manager: 21 slots and 50 history entries; +0xB2670 pending invite, +0xB26B8 member list.
// FUNCTION: TITANIUM 0x0043320E
// @early-stop: budget, structural ndiff=3
TaskManager_guess::TaskManager_guess() {
    first_guess[0].Initialize_guess();
    for (int index_guess = 0; index_guess < 0x13; ++index_guess)
        rest_guess[index_guess].Initialize_guess();
    special_guess[0].Initialize_guess();
    for (int index_guess = 0; index_guess < 0x32; ++index_guess)
        records_guess[index_guess].Initialize_guess();
    last_guess = 0;
}

// Builds a slot's shown description from its template (+0x2019). Text in [n,m,...] is kept only while
// every listed activity (1-based) exists and at least one is below its goal in `context_guess` (pCharData's
// progress record; TaskProgressView_guess is that record). Then %20 down to %1 become activity texts.
// FUNCTION: TITANIUM 0x004332E8
// @early-stop: budget, structural ndiff=218
void RuleParser_guess::BuildDescription_guess(TaskSlot_guess* state_guess, TaskProgressView_guess* context_guess) {
    char recordText_guess[0x200];
    char text_guess[0x800];
    // Room for 40 pieces; the parser below never checks the count.
    RuleText_guess tokens_guess[0x28];
    IndexSet_guess sets_guess[0x28];
    RuleText_guess current_guess;
    int tokenCount_guess = 0;
    RuleText_guess* token_guess = tokens_guess;
    IndexSet_guess* set_guess = sets_guess;
    const char* cursor_guess = state_guess->data2019_guess;

    if (*cursor_guess != 0) {
        do {
            if (*cursor_guess == '[') {
                if (current_guess.Ptr != 0 && current_guess.Ptr->length > 0) {
                    ++tokenCount_guess;
                    RuleText_guess* oldToken_guess = token_guess;
                    ++token_guess;
                    ++set_guess;
                    ((CXStr&)*oldToken_guess) = current_guess;
                    ((CXStr&)current_guess) = "";
                }
                ++cursor_guess;
                int finished_guess = 0;
                do {
                    const char* start_guess = cursor_guess;
                    int end_guess = FindNumberEnd_guess(&cursor_guess, ',');
                    int numberEnd_guess = end_guess;
                    if (end_guess == 0) {
                        numberEnd_guess = 1000;
                        set_guess->Parse_guess(set_guess->count_guess, &numberEnd_guess);
                        cursor_guess = start_guess;
                        finished_guess = 1;
                    } else {
                        set_guess->Parse_guess(set_guess->count_guess, &numberEnd_guess);
                    }
                    if (_isdigit((unsigned char)*cursor_guess) == 0)
                        finished_guess = 1;
                } while (finished_guess == 0);

                const char* endText_guess = strchr(cursor_guess, ']');
                if (endText_guess == 0)
                    endText_guess = cursor_guess + strlen(cursor_guess) - 1;
                size_t length_guess = (size_t)(endText_guess - cursor_guess);
                strncpy(text_guess, cursor_guess, length_guess);
                text_guess[length_guess] = 0;
                ((CXStr&)*token_guess) = text_guess;
                ++tokenCount_guess;
                ++token_guess;
                ++set_guess;
                cursor_guess = endText_guess;
            } else {
                current_guess.AppendCharacter_guess(*cursor_guess);
            }
            ++cursor_guess;
        } while (*cursor_guess != 0);
        if (current_guess.Ptr != 0 && current_guess.Ptr->length > 0) {
            ++tokenCount_guess;
            RuleText_guess* oldToken_guess = token_guess;
            ++token_guess;
            ++set_guess;
            ((CXStr&)*oldToken_guess) = current_guess;
        }
    }

    RuleText_guess result_guess;
    int remaining_guess = tokenCount_guess;
    token_guess = tokens_guess;
    set_guess = sets_guess;
    while (remaining_guess > 0) {
        int keep_guess = 1;
        int thresholds_guess = 1;
        if (set_guess->count_guess < 1) {
            result_guess.Add_guess(token_guess);
        } else {
            for (int item_guess = 0; item_guess < set_guess->count_guess; ++item_guess) {
                int* value_guess = set_guess->At_guess(item_guess);
                int recordIndex_guess = *value_guess - 1;
                if (recordIndex_guess < 0 || recordIndex_guess >= 0x14) {
                    keep_guess = 0;
                    break;
                }
                if (keep_guess != 0 && state_guess->records_guess[recordIndex_guess].first_guess != -1 &&
                    state_guess->records_guess[recordIndex_guess].first_guess != 0) {
                    keep_guess = 1;
                } else {
                    keep_guess = 0;
                }
                if (context_guess->values_guess[recordIndex_guess] <
                    state_guess->records_guess[recordIndex_guess].values_guess[3])
                    thresholds_guess = 0;
            }
            if (keep_guess != 0 && thresholds_guess == 0)
                result_guess.Add_guess(token_guess);
        }
        ++token_guess;
        ++set_guess;
        --remaining_guess;
    }

    int number_guess = 0x14;
    TaskActivity_guess* record_guess = &state_guess->records_guess[0x13];
    do {
        if (record_guess->first_guess != -1 && record_guess->first_guess != 0)
            FormatActivityText_guess(record_guess, recordText_guess);
        RuleText_guess formattedNumber_guess;
        // Largest number first, so %1 never matches the start of %10.
        FormatNumber_guess(&formattedNumber_guess, "%%%d", number_guess);
        if (result_guess.Contains_guess(&formattedNumber_guess, token_guess)) {
            unsigned int length_guess = formattedNumber_guess.Ptr != 0 ?
                (unsigned int)formattedNumber_guess.Ptr->length : 0;
            result_guess.AppendRange_guess(token_guess, length_guess);
            CXStr recordString_guess(recordText_guess);
            result_guess.AppendString_guess(token_guess, &recordString_guess);
        }
        --number_guess;
        --record_guess;
    } while (number_guess > 0);

    CopyBuffer_guess(state_guess->data4c_guess, (const char*)result_guess, 0x800);
    state_guess->flag2018_guess = 1;
}
// Shared-task entry list: when its id matches the shared task, copies the flag and replaces the entries,
// then refreshes CTaskTemplateSelectWnd (vtable slot 33 too when the list was empty).
// FUNCTION: TITANIUM 0x0043379D
// @early-stop: budget, diff ndiff=54
void TaskManagerView_guess::LoadCopy_guess(int source_guess, int length_guess) {
    if (source_guess != 0) {
        CopyObject_guess object_guess;
        object_guess.Load_guess((const void*)source_guess, length_guess);
        for (int index_guess = 0; index_guess < 1; ++index_guess) {
            if (records_guess[index_guess + 20].id_guess == object_guess.third_guess) {
                int copy_guess = 0;
                int first_guess = 0;
                records_guess[index_guess + 21].selected_guess = object_guess.flag_guess;
                IndexedData_guess* entries_guess = &records_guess[index_guess + 20].entries_guess;
                first_guess = entries_guess->count_guess;
                reinterpret_cast<Part_guess*>(entries_guess)->Reset_guess();
                source_guess = object_guess.list_guess.capacity_guess;
                for (copy_guess = 0; copy_guess < source_guess; ++copy_guess) {
                    const CopyData_guess* item_guess = (const CopyData_guess*)reinterpret_cast<IndexedData_guess*>(&object_guess.list_guess)->Get_guess(copy_guess);
                    reinterpret_cast<CopyList_guess*>(entries_guess)->Set_guess(entries_guess->count_guess, item_guess);
                }
                if (pinstCTaskTemplateSelectWnd_guess != 0) {
                    pinstCTaskTemplateSelectWnd_guess->Flush_guess();
                    if (first_guess == 0 && source_guess > 0)
                        ((NotifySlots_guess*)pinstCTaskTemplateSelectWnd_guess)->Slot21_guess();
                }
                return;
            }
        }
    }
}

// Task packet dispatcher; most cases forward to the handlers above, which name their EQEmu packet.
// FUNCTION: TITANIUM 0x00433887
// @early-stop: budget, structural ndiff=220
void TaskManagerView_guess::HandleTaskMessage_guess(int message_guess, void* data_guess, int extra_guess) {
    EQ_Character* character_guess = pCharData;
    char lineBuffer_guess[0x400];
    char chatBuffer_guess[0x8000];
    if (character_guess != 0) {
    switch (message_guess) {
    case 0x1d6e:
        ((CharacterAction_guess*)character_guess)->Set_guess(*(int*)data_guess);
        if (pinstCTaskWnd_guess != 0)
            pinstCTaskWnd_guess->Apply_guess();
        break;
    case OP_TaskHistoryReply:
        ((RecordTable_guess*)this)->Handle_OP_TaskHistoryReply_guess((int)character_guess, (const char*)data_guess);
        break;
    case OP_CancelTask: {
        int* values_guess = (int*)data_guess;
        ((LookupOwner_guess*)this)->Handle_OP_CancelTask_guess((EQ_CharacterView_guess*)character_guess, values_guess[0], values_guess[1]);
        break;
    }
    case 0x4562:
        ((ValueOwner_guess*)this)->Update_guess((UpdateData_guess*)data_guess, extra_guess);
        break;
    case 0x46aa: {
        DispatchLookupData_guess* update_guess = (DispatchLookupData_guess*)data_guess;
        int index_guess = 0;
        do {
            if (update_guess->id_guess == records_guess[20 + index_guess].id_guess) {
                records_guess[index_guess + 0x15].selected_guess = update_guess->value_guess;
                break;
            }
            ++index_guess;
        } while (index_guess < 1);
        break;
    }
    case OP_TaskActivityComplete: {
        DispatchLookupData_guess* update_guess = (DispatchLookupData_guess*)data_guess;
        int lineType_guess;
        int addLine_guess;
        // TaskActivityComplete: a centre-screen line (CTextOverlay) naming the task, string 0x1774
        // or 0x1773 by `lineMode_guess`; 0x1775 when `enabled_guess` is set. `entry_guess` is
        // not null-checked.
        lineBuffer_guess[0] = 0;
        if (update_guess->enabled_guess == 0) {
            int* entry_guess = ((LookupOwner_guess*)this)->Get_guess(update_guess->first_guess, update_guess->second_guess, 1);
            if (*entry_guess != update_guess->id_guess)
                break;
            addLine_guess = 1;
            if (update_guess->lineMode_guess == 0) {
                BuildMessage_guess(lineBuffer_guess, 0x1774, (const char*)(entry_guess + 1), 0, 0, 0, 0, 0, 0, 0, 0);
                lineType_guess = 0xd;
            } else {
                BuildMessage_guess(lineBuffer_guess, 0x1773, (const char*)(entry_guess + 1), 0, 0, 0, 0, 0, 0, 0, 0);
                lineType_guess = 0xe;
            }
        } else {
            addLine_guess = 0;
            strcpy(lineBuffer_guess, pStringTable->getString(0x1775, 0));
            lineType_guess = 0xf;
        }
        if (lineBuffer_guess[0] != 0) {
            DispatchLine_guess* line_guess = CreateLine_guess(lineBuffer_guess, lineType_guess, addLine_guess, 0xff, 500, 500, 3000);
            line_guess->Show_guess();
        }
        break;
    }
    case 0x5886:
        ((ValueOwner_guess*)this)->Handle_OP_TaskMemberChange_guess((ValueToggle_guess*)data_guess);
        break;
    case OP_TaskSelectWindow:
        if (pinstCTaskSelectWnd_guess != 0) {
            // TaskSelectWindow: the offered tasks go to CTaskSelectWnd (0x992820, g_chatList_guess).
            HandleData_guess(data_guess);
            pinstCTaskSelectWnd_guess->Show(1, 1);
        }
        break;
    case OP_TaskDescription:
        ((LookupOwner_guess*)this)->Handle_OP_TaskDescription_guess((EQ_CharacterView_guess*)character_guess, (const char*)data_guess);
        break;
    case 0x64d7:
        LoadCopy_guess((int)data_guess, extra_guess);
        break;
    case 0x67c6: {
        UpdateData_guess* update_guess = (UpdateData_guess*)data_guess;
        g_searchOwner_guess->GetOrCreateCachedItem_guess(update_guess->value_guess, &update_guess->key_guess[4]);
        if (pinstCTaskTemplateSelectWnd_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->SendData_guess(data_guess);
        break;
    }
    case OP_TaskActivity:
        Handle_OP_TaskActivity_guess(character_guess, data_guess);
        break;
    case 0x6a1d:
        // TaskTimers: pCharData +0xE50 = CDisplay +0x148 (probably the clock) + the
        // seconds sent; g_chatSettings_guess is CDisplay.
        ((CharacterTail_guess*)character_guess)->value_guess = g_chatSettings_guess->value_guess + *(int*)data_guess;
        break;
    case 0x6c97: {
        // Status of a shared-task entry by id: one of strings 0xE19-0xE25 with its name.
        char* name_guess = EQ_ARRAY(char, 0x0063F53F);
        int matched_guess = 0;
        int category_guess = 0;
        do {
            IndexedData_guess* entries_guess = &records_guess[20 + category_guess].entries_guess;
            for (int index_guess = 0; index_guess < entries_guess->count_guess && !matched_guess; ++index_guess) {
                if (((DispatchMessageData_guess*)data_guess)->id_guess == *(int*)entries_guess->Get_guess(index_guess)) {
                    name_guess = entries_guess->Get_guess(index_guess) + 0x11;
                    matched_guess = 1;
                }
            }
            ++category_guess;
        } while (category_guess < 1 && !matched_guess);
        CXStr cleanup_guess;
        int textType_guess = 0xd;
        int state_guess = ((DispatchMessageData_guess*)data_guess)->tail_guess.state_guess;
        if (state_guess == 0) {
            BuildMessage_guess(chatBuffer_guess, 0xe1a, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            textType_guess = 0xf;
        } else {
            int textId_guess;
            const char* extraText_guess = 0;
            switch (state_guess) {
            case 1: textId_guess = 0xe19; break;
            case 2: textId_guess = 0xe1d; break;
            case 3: textId_guess = 0xe1b; break;
            case 4: textId_guess = 0xe1c; extraText_guess = EQ_ARRAY(char, 0x0063F53F); break;
            case 5: textId_guess = 0xe1e; break;
            case 6: textId_guess = 0xe25; break;
            default: textId_guess = 0;
            }
            if (textId_guess != 0)
                BuildMessage_guess(chatBuffer_guess, textId_guess, name_guess, extraText_guess, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(chatBuffer_guess, textType_guess, 1);
        break;
    }
    case 0x7135:
        if (pinstCTaskTemplateSelectWnd_guess != 0 && pinstCTaskTemplateSelectWnd_guess->enabled_guess != 0)
            pinstCTaskTemplateSelectWnd_guess->SendText_guess(((DispatchMessageData_guess*)data_guess)->tail_guess.text_guess);
        break;
    case OP_SharedTaskMemberList:
        ((ValueOwner_guess*)this)->Handle_OP_SharedTaskMemberList_guess(data_guess);
        break;
    case 0x729c: {
        Buffer_guess buffer_guess;
        buffer_guess.Initialize_guess();
        int length_guess = ((CopyData_guess*)&buffer_guess)->CopyHeader_guess(data_guess, extra_guess);
        if (g_taskTemplates_guess != 0) {
            // Template data after the 16-byte header goes to the '^'-record map (0x985CEC,
            // tu_093); ChatFilter_guess is a misname.
            g_taskTemplates_guess->Check_guess((const char*)data_guess + length_guess);
            if (pinstCTaskTemplateSelectWnd_guess != 0)
                pinstCTaskTemplateSelectWnd_guess->ShowTemplate_guess();
        }
        break;
    }
    case OP_CompletedTasks:
        ((RecordTable_guess*)this)->Handle_OP_CompletedTasks_guess((int)character_guess, (const char*)data_guess);
        break;
    case 0x79b4:
        ((MessageOwner_guess*)this)->Handle_OP_TaskMemberInvite_guess((MessageInput_guess*)data_guess);
        break;
    }
    }
}

