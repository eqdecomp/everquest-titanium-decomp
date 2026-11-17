// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 31: a hint from compare/tumap.py.
// A mixed TU. First the client's expedition (dynamic zone) state, Expedition_guess, fed by the
// OP_Dz* messages in its Dispatch_guess: members, lockout timers, compass points and the choose-zone list,
// each read from the packet through a small hash table. Then the environment-sound emitter loader, vlong
// helpers for tu_095's RSA code, and the AA ability record AltAbility_guess (SendAA layout) with its checks.
#include <new>
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
#include "titanium/opcodes.h"

// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z

struct AltAbility_guess {
    int field0_guess;
    char field4_guess;
    char pad5_guess[3];
    int field8_guess;
    int fieldc_guess;
    int field10_guess;
    int field14_guess;
    int field18_guess;
    int field1c_guess;
    int field20_guess;
    int field24_guess;
    int field28_guess;
    int field2c_guess;
    int field30_guess;
    int field34_guess;
    char field38_guess;
    char pad39_guess[3];
    int field3c_guess;
    int field40_guess;
    int field44_guess;
    int field48_guess;
    char pad4c_guess[4];
    int field50_guess;
    int field54_guess;
    char field58_guess;
    char field59_guess;
    char pad5a_guess[2];
    int field5c_guess;
    int field60_guess;
    int field64_guess;
    int field68_guess;

    // EXTERNAL: TITANIUM 0x004167E2 AltAbility_guess::GetStatus_guess
    int GetStatus_guess();
    void Reset_guess();
    AltAbility_guess* Init_guess();
    void CopyFrom_guess(const AltAbility_guess* source_guess, int unused_guess);
    char CanClassUse_guess(int index_guess);
    bool IsSpecial_guess();
    int IsStatusOneOrTwo_guess();
};

struct Property_guess {
    char pad_guess[0x48];
    int value_guess;

    int GetMaxRank_guess();
};

struct Property48_guess {
    char pad_guess[0x48];

    // EXTERNAL: TITANIUM 0x00447959 Property48_guess::GetMaxRank_guess
    int GetMaxRank_guess();
};

struct TextNode_guess {
    char text_guess[0x40];
    int field40_guess;
    TextNode_guess* next_guess;

    TextNode_guess* Init_guess();
    int SetText_guess(char* value_guess);
};

struct TextList_guess {
    int field0_guess;
    int count_guess;
    TextNode_guess* head_guess;
    TextNode_guess* tail_guess;

    void Append_guess(TextNode_guess* node_guess);
    int Read_guess(const char* source_guess, int unused_guess);
};

struct WideNode_guess {
    char pad_guess[0x180];
    int field180_guess;
    char pad184_guess[4];
    WideNode_guess* next_guess;
};

struct WideList_guess {
    int field0_guess;
    int count_guess;
    WideNode_guess* head_guess;
    WideNode_guess* tail_guess;

    void Append_guess(WideNode_guess* node_guess);
    int Read_guess(const char* source_guess, int unused_guess);
};

struct LinkNode_guess {
    char pad_guess[0x120];
    LinkNode_guess* next_guess;
    LinkNode_guess* prev_guess;
};

struct LinkList_guess {
    LinkNode_guess* head_guess;
    int count_guess;

    void Push_guess(LinkNode_guess* node_guess);
};

struct NamedSource_guess {
    int field0_guess;
    char name_guess[0x40];
};

struct SourceData_guess {
    char pad00_guess[4];
    char field4_guess;
    char pad05_guess[3];
    int field8_guess;
    char formatc_guess[0x80];
    char format8c_guess[0x80];
};

struct Manager_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess);
    char pad04_guess[0x58];
    char field5c_guess;

    // EXTERNAL: TITANIUM 0x004FEA17 Manager_guess::Touch_guess
    void Touch_guess();

    // EXTERNAL: TITANIUM 0x005A1CD0 Manager_guess::Refresh_guess
    void Refresh_guess();

    // EXTERNAL: TITANIUM 0x004FF54D Manager_guess::Notify_guess
    void Notify_guess();

    // EXTERNAL: TITANIUM 0x004FF11E Manager_guess::Flush_guess
    void Flush_guess();
};

struct CleanupBase_guess {
    // EXTERNAL: TITANIUM 0x005482A0 CleanupBase_guess::Purge_guess
    void Purge_guess(int value_guess);
    virtual void Slot00_guess() {}
    ~CleanupBase_guess() {
        Purge_guess(-1);
    }
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7CleanupBase_guess@@6B@
// EXTERNAL: TITANIUM 0x00643620 ??_7Expedition_guess@@6B@

struct HashEntryB_guess;

struct HashTableB_guess {
    HashEntryB_guess** buckets_guess;
    int bucketCount_guess;
    int nodeCount_guess;
    int usedCount_guess;

    HashTableB_guess(int bucketCount_guess);
    void Clear_guess();
    HashEntryB_guess* NextEntry_guess(HashEntryB_guess* entry_guess);
    void Insert_guess(const int* source_guess, unsigned int hash_guess);
    void Rehash_guess(int bucketCount_guess);
    ~HashTableB_guess();
};

struct LineSource_guess {
    int field0_guess;
    char flag4_guess;
    char pad5_guess[3];
    char text8_guess[0x40];
};

struct Expedition_guess : CleanupBase_guess {
    int field4_guess;
    char field8_guess;
    char pad09_guess[0x3f];
    char field48_guess;
    char field49_guess;
    char field4a_guess;
    char pad4b_guess[0x3f];
    char field8a_guess;
    char pad8b_guess[0x81];
    int field10c_guess;
    TextNode_guess* head110_guess;
    WideNode_guess* head114_guess;
    HashTableB_guess table_guess;

    Expedition_guess();
    ~Expedition_guess();
    void Append_guess(TextNode_guess* node_guess);
    void ClearMembers_guess();
    void ClearLockoutTimers_guess();
    // EXTERNAL: TITANIUM 0x00446D32 Expedition_guess::ReleaseContents_guess
    void ReleaseContents_guess();
    void Reset_guess();
    char Find_guess(char* value_guess);
    void Handle_OP_DzSetLeaderName_guess(NamedSource_guess* source_guess);
    void Handle_OP_DzExpeditionInfo_guess(SourceData_guess* source_guess);
    void Handle_OP_DzMemberList_guess(char* source_guess);
    void Handle_OP_DzExpeditionLockoutTimers_guess(char* source_guess);
    void Handle_OP_DzMemberListStatus_guess(char* source_guess);

    void RemoveByName_guess(char* value_guess);
    void Handle_OP_DzMemberListName_guess(LineSource_guess* source_guess);

    // EXTERNAL: TITANIUM 0x0044660F Expedition_guess::Handle_OP_DzExpeditionEndsWarning_guess
    void Handle_OP_DzExpeditionEndsWarning_guess(int value_guess);

    void Handle_OP_DzChooseZone_guess(int first_guess, int second_guess);

    void Handle_OP_DzCompass_guess(int first_guess, int second_guess);

    void Dispatch_guess(int unused_guess, unsigned int message_guess,
        int first_guess, int second_guess);
};

struct Payload_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
};

struct HeapBox_guess {
    Payload_guess* payload_guess;
    HeapBox_guess* field4_guess;
    HeapBox_guess* field8_guess;

    // EXTERNAL: TITANIUM 0x0044795D HeapBox_guess::HeapBox_guess
    HeapBox_guess(Payload_guess* source_guess);
    HeapBox_guess* Init_guess(Payload_guess* source_guess);
    void Release_guess();
};

struct HeapBoxList_guess {
    int count_guess;
    HeapBox_guess* head_guess;
    HeapBox_guess* tail_guess;
    HeapBox_guess* current_guess;

    void Clear_guess();
    char Remove_guess();
    char Add_guess(Payload_guess* source_guess);
};

struct HeapBoxListOwner_guess {
    char pad_guess[0x5c];
    HeapBoxList_guess list_guess;

    void Clear_guess();
};

struct HeapBoxArrayEntry_guess {
    // EXTERNAL: TITANIUM 0x00448263 HeapBoxArrayEntry_guess::Clear_guess
    void Clear_guess();
};

struct Table_guess {
    // EXTERNAL: TITANIUM 0x0047C339 Table_guess::Apply_guess
    void Apply_guess(int** valueAddress_guess, int value_guess);

    // EXTERNAL: TITANIUM 0x004FF9C9 Table_guess::Find_guess
    int* Find_guess(int key_guess);
};

#include "titanium/layouts/core.h"
#include "titanium/wnd/CCompassWnd.h"
#include "titanium/wnd/CDynamicZoneWnd.h"

struct LookupResultB_guess {
    char pad00_guess[0x119c];
    unsigned char class_119c_guess;
    char pad119d_guess[7];
    int level_11a4_guess;
};

struct LookupService_guess {
    int unused_guess;

    // EXTERNAL: TITANIUM 0x005EC220 LookupService_guess::GetCharInfo2
    LookupResultB_guess* GetCharInfo2();
};

struct LookupStatus_guess {
    int field0_guess;
    LookupService_guess service_guess;
};

struct StatusCheck_guess {
    // EXTERNAL: TITANIUM 0x00447CB1 StatusCheck_guess::IsStatusOneOrTwo_guess
    bool IsStatusOneOrTwo_guess();
};

struct QuerySource_guess {
    char pad00_guess[8];
    union {
        VBTable* holder_guess;
        char bytes_guess[1];
    } data_guess;

    // EXTERNAL: TITANIUM 0x004BAAEB QuerySource_guess::ContainsId_guess
    char ContainsId_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x004BAD65 QuerySource_guess::ReturnTrue_guess
    bool ReturnTrue_guess(int value_guess);
};

struct Query_guess;

struct DescriptionInput_guess {
    char pad00_guess[0x18];
    int value18_guess;
    char pad1c_guess[0x0c];
    int value28_guess;
    int value2c_guess;
    int value30_guess;
};

struct DescriptionResult_guess {
    char pad00_guess[0x10];
    int value10_guess;
    char pad14_guess[0x0c];
    int value20_guess;
    char pad24_guess[0x0c];
    int value30_guess;
};

struct AltAdvManager_guess {
    Table_guess* table_guess;

    void Apply_guess(int* value_guess);
    int GetAltAbility(int key_guess);
    void GetAbilityReqs_guess(char* destination_guess, char* dataAddress_guess);
    int FindOwnedBySeq_guess(Query_guess* query_guess, int value_guess);
    char Check_guess(QuerySource_guess* source_guess, AltAbility_guess* state_guess);
    char MeetsPrerequisites_guess(Query_guess* query_guess, AltAbility_guess* state_guess);
    char CanPurchase_guess(Query_guess* query_guess, AltAbility_guess* state_guess, char flag_guess);
};

struct ValueEntry_guess {
    int field0_guess;
    char pad04_guess[0x1c];
    int field20_guess;
    int field24_guess;
    char pad28_guess[8];
    int field30_guess;
    char pad34_guess[0x18];
    int field4c_guess;
};

struct SmallOwner_guess {
    // EXTERNAL: TITANIUM 0x004106A3 SmallOwner_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
};

struct BigOwner_guess {
    char pad_guess[0xc280];
    SmallOwner_guess owner_guess;
};

struct Source_guess {
    char pad00_guess[0x20];
    int value20_guess;
    char pad24_guess[0x18];
    int field3c_guess;
    int value40_guess;
};

struct CompassPoint_guess {
    int values_guess[6];

    CompassPoint_guess* CopyFrom_guess(const CompassPoint_guess* source_guess);
    int CopyBytesFrom_guess(const CompassPoint_guess* source_guess, int unused_guess);
};

struct Entry6_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
};

struct Copy7_guess {
    int values_guess[7];

    Copy7_guess* CopyFrom_guess(const int* source_guess);
};

struct Copy7Zero_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
    int field18_guess;

    Copy7Zero_guess();
};

struct Node7_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
    int field18_guess;
    unsigned int hash_guess;
    Node7_guess* link_guess;

    // EXTERNAL: TITANIUM 0x00446340 Node7_guess::Init_guess
    void Init_guess();
};

struct Copy7Init_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
    int field18_guess;

    Copy7Init_guess(const CompassPoint_guess* source_guess);
};

struct CompassMarker_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
    char field18_guess;
    char pad19_guess[3];
    char pad1c_guess[8];
    int field24_guess;
    int field28_guess;
    int field2c_guess;

    CompassMarker_guess();
};

struct SoundEmitter_guess {
    int field0_guess;
    char name_guess[0x100];
    int field104_guess;
    int field108_guess;
    float field10c_guess;
    float field110_guess;
    float field114_guess;
    int field118_guess;
    int field11c_guess;
    SoundEmitter_guess* next_guess;
    int field124_guess;

    SoundEmitter_guess* Init_guess();

    void Parse_guess(char* source_guess);
};

struct Connection_guess {
    char pad_guess[8];
    int state_guess;
};

struct ConnectionOwner_guess {
    Connection_guess* connection_guess;

    int Check_guess();
};

struct DispatchList_guess {
    SoundEmitter_guess* head_guess;

    void Process_guess();
    void DispatchByName_guess(char* name_guess, int id_guess, float x_guess, float y_guess, float z_guess);
};

struct DispatchTarget_guess {
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
    virtual void Dispatch_guess(int first_guess, int* payload_guess,
        int third_guess, int* state_guess, int fifth_guess, int sixth_guess);
    virtual void Slot24_guess();
    virtual void Stop_guess(int handle_guess);
};

struct DispatchPayload_guess {
    float first_guess;
    float second_guess;
    float third_guess;
};

struct TextFileReader_guess {
    char pad_guess[0x1000c];

    // EXTERNAL: TITANIUM 0x00576BD0 TextFileReader_guess::TextFileReader_guess
    TextFileReader_guess(const char* name_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x00576C50 TextFileReader_guess::~TextFileReader_guess
    ~TextFileReader_guess();
    // EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::IsOpen_guess
    char IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::Advance_guess
    int Advance_guess();
    // EXTERNAL: TITANIUM 0x00576CF0 TextFileReader_guess::Read_guess
    void Read_guess(char* buffer_guess, int size_guess);
};

struct SoundEmitterList_guess : DispatchList_guess {
    int count_guess;
    int nextId_guess;
    char name_guess[0x100];

    void Reset_guess();
    int LoadEnvironmentEmitterInstances(char* source_guess);
};

struct IntArrayView_guess {
    int* values_guess;
    int count_guess;

    int FirstNonZero_guess();

    // EXTERNAL: TITANIUM 0x0042EC1A IntArrayView_guess::Remove_guess
    int* Remove_guess(int* slot_guess);

    // EXTERNAL: TITANIUM 0x0048F513 IntArrayView_guess::Finish_guess
    void Finish_guess();
};

struct HeapBoxArrayOwner_guess {
    IntArrayView_guess* view_guess;

    void Cleanup_guess();
};

struct HashEntryA_guess {
    char pad00_guess[0x18];
    unsigned int hash_guess;
    HashEntryA_guess* link_guess;
};

struct HashEntryB_guess {
    char pad00_guess[4];
    int field4_guess;
    int field8_guess;
    char pad0c_guess[0x0c];
    void* payload_guess;
    unsigned int hash_guess;
    HashEntryB_guess* link_guess;
};

struct HashTableA_guess {
    HashEntryA_guess** buckets_guess;
    int bucketCount_guess;

    HashEntryA_guess* NextEntry_guess(HashEntryA_guess* entry_guess);
};

struct HashTableB_guess;

struct EntryManager_guess {
    char pad_guess[0x118];
    HashTableB_guess table_guess;

    void ReleaseContents_guess();
};

struct LookupOwner_guess {
    char pad_guess[0x118];
    HashTableB_guess table_guess;

    int FindStateOne_guess();
};

struct HashChain_guess {
    int key_guess;
    unsigned int hash_guess;
    HashChain_guess* next_guess;
};

struct HashTableC_guess {
    HashChain_guess** buckets_guess;
    unsigned int bucketCount_guess;
    int nodeCount_guess;
    int usedCount_guess;

    void Insert_guess(const HashChain_guess* source_guess, unsigned int hash_guess);
};

struct ChooseZoneEntry_guess;
struct HashEntryWide_guess;

struct HashTableWide_guess {
    HashEntryWide_guess** buckets_guess;
    int bucketCount_guess;
    int nodeCount_guess;
    int usedCount_guess;

    HashTableWide_guess(int bucketCount_guess);
    void Clear_guess();
    void Insert_guess(const ChooseZoneEntry_guess* source_guess, unsigned int hash_guess);
    void Rehash_guess(int bucketCount_guess);
    void Release_guess();
};

struct HashEntrySmall_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    float fieldc_guess;
    float field10_guess;
    float field14_guess;
    unsigned int hash_guess;
    HashEntrySmall_guess* next_guess;
};

struct HashTableSmall_guess {
    HashEntrySmall_guess** buckets_guess;
    int bucketCount_guess;
    int nodeCount_guess;
    int usedCount_guess;

    HashTableSmall_guess(int bucketCount_guess);
    void Clear_guess();
    void Insert_guess(const CompassPoint_guess* source_guess, unsigned int hash_guess);
    void Rehash_guess(int bucketCount_guess);
    void Release_guess();
};

struct HashTableWideOwner_guess {
    int field0_guess;
    HashTableWide_guess table_guess;

    HashTableWideOwner_guess(int bucketCount_guess) : table_guess(bucketCount_guess) {
        field0_guess = -1;
    }
    ~HashTableWideOwner_guess() {
        table_guess.Release_guess();
    }
    int Read_guess(const char* source_guess, int size_guess);
    void Release_guess();
};

struct HashTableSmallOwner_guess {
    int field0_guess;
    HashTableSmall_guess table_guess;

    HashTableSmallOwner_guess() : table_guess(50) {
        field0_guess = -1;
    }
    ~HashTableSmallOwner_guess() {
        table_guess.Release_guess();
    }
    int Read_guess(const char* source_guess, int size_guess);
    void Release_guess();
};

struct HashTableOwner_guess {
    HashTableC_guess* table_guess;

    char InsertValue_guess(int* value_guess);
};

struct QueryTarget_guess {
    char pad_guess[0x1a8];
    int field1a8_guess;
};

struct QueryPart_guess {
    int field0_guess;
    int field4_guess;
};

struct Query_guess {
    char pad00_guess[8];
    union {
        VBTable* holder_guess;
        char bytes_guess[1];
    } data_guess;
    char pad0c_guess[0xc284 - 0x0c];
    QueryPart_guess* part_guess;
    QueryTarget_guess* pSpawn_c288_guess;
    char pad28c_guess[0xc38c - 0xc28c];
    unsigned char stateFlags_guess[2];

    // EXTERNAL: TITANIUM 0x005ED730 Query_guess::GetLimit_guess
    int GetLimit_guess();

    // EXTERNAL: TITANIUM 0x005F0910 Query_guess::GetEntry_guess
    int GetEntry_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x005F0BD0 Query_guess::GetOffset_guess
    int GetOffset_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x004BAAEB Query_guess::ContainsId_guess
    char ContainsId_guess(int value_guess);
};

struct Validator_guess {
    char Check_guess(BigOwner_guess* owner_guess, Source_guess* source_guess, int* result_guess);
};

struct BufferOwner_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    char buffer_guess[0x400];
    int field40c_guess;

    BufferOwner_guess* Init_guess();
};

struct LockoutTimer_guess {
    char first_guess[0x80];
    char second_guess[0x100];
    int field180_guess;
    int field184_guess;
    int field188_guess;

    LockoutTimer_guess* Init_guess();
    int SetSource_guess(const char* source_guess);
};

struct ChooseZoneEntry_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    int fieldc_guess;
    char pad10_guess[0x80];
    char field90_guess;

    ChooseZoneEntry_guess* CopyFrom_guess(const ChooseZoneEntry_guess* source_guess);

    int Read_guess(const char* source_guess, int size_guess);
};

struct HashEntryWide_guess : ChooseZoneEntry_guess {
    char pad94_guess[0x3c];
    unsigned int hash_guess;
    HashEntryWide_guess* next_guess;
};

struct EntryBlock_guess : ChooseZoneEntry_guess {
    char pad94_guess[0x3c];
};

struct T_guess {
    int first_guess;
    int second_guess;

    // EXTERNAL: TITANIUM 0x004CA749 ??0T_guess@@QAE@ABU0@@Z
    T_guess(const T_guess& source_guess);
    ~T_guess();
};

struct Vlong_guess {
    // EXTERNAL: TITANIUM 0x004CA954 Vlong_guess::Compare_guess
    int Compare_guess(T_guess value_guess);
};

struct EventData_guess {
    char pad00_guess[4];
    char first_guess[0x40];
    char second_guess[0x80];
    char flagc4_guess;
    char textc5_guess[0x43];
    int field108_guess;
};

struct MessageState_guess {
    int field0_guess;
    int field4_guess;
    char text_guess[0x40];
    char flag48_guess;

    void Send_guess(int message_guess, unsigned char flags_guess, int unused_guess);
    void SetFrom_guess(EventData_guess* source_guess);
};

struct OutgoingData_guess {
    int field0_guess;
    int field4_guess;
    char flag8_guess;
    char flag9_guess;
    char text_guess[0x42];
};

struct PublicKey_guess;
// EXTERNAL: TITANIUM 0x004CB264 ?ModExp_guess@@YA?AUCXStr@@HPAUPublicKey_guess@@0@Z
CXStr __cdecl ModExp_guess(int value_guess, PublicKey_guess* first_guess, PublicKey_guess* second_guess);

struct PublicKey_guess {
    char pad00_guess[8];
    int field8_guess;

    CXStr Encrypt_guess(int value_guess);
};

struct StringTable_guess {
    // EXTERNAL: TITANIUM 0x004355F7 StringTable_guess::GetString_guess
    char* GetString_guess(int key_guess, int one_guess, int zero_guess);
};

#define g_voidConnection_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_query_guess EQ_GLOBAL(Query_guess*, 0x00905D00)
#define g_dispatchTarget_guess EQ_GLOBAL(DispatchTarget_guess*, 0x0099E368)
#define g_stringTable_guess EQ_GLOBAL(StringTable_guess*, 0x00850398)

// EXTERNAL: TITANIUM 0x00576E80 GetCurrent_guess
int __cdecl GetCurrent_guess();

// EXTERNAL: TITANIUM 0x004912B1 SendConnectionMessage_guess
void __cdecl SendConnectionMessage_guess(int* connection_guess, int message_guess, int data_guess, int size_guess, int flags_guess);

// EXTERNAL: TITANIUM 0x0060E450 CopyRegion_guess
void __cdecl CopyRegion_guess(void* destination_guess, const void* source_guess);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D682 FreeAt60D682_guess
void __cdecl FreeAt60D682_guess(void* memory_guess);

// EXTERNAL: TITANIUM 0x0042429E NextPrimeCandidate_guess
int __cdecl NextPrimeCandidate_guess(int count_guess);

// EXTERNAL: TITANIUM 0x0060E985 AllocateBucketStorage_guess
void* __cdecl AllocateBucketStorage_guess(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(char* first_guess, char* second_guess);

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);
extern "C" char* __cdecl strncpy(char* destination_guess, const char* source_guess, unsigned int count_guess);
extern "C" void* __cdecl memcpy(void* destination_guess, const void* source_guess, unsigned int size_guess);
extern "C" int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);
extern "C" double __cdecl atof(const char* value_guess);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* destination_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" unsigned int __cdecl strlen(const char* value_guess);
// EXTERNAL: TITANIUM 0x0060EA01 __snprintf
int __cdecl __snprintf(char* destination_guess, unsigned int size_guess,
    const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x005769E0 ReadText_guess
int __cdecl ReadText_guess(char* input_guess, char* output_guess,
    unsigned int size_guess, int option_guess, int final_guess);

// EXTERNAL: TITANIUM 0x004B2056 ParseLong_guess
int __cdecl ParseLong_guess(const char* input_guess, int* output_guess, int option_guess);

// EXTERNAL: TITANIUM 0x0046DA4A BuildEventMessage_guess
void __cdecl BuildEventMessage_guess(char* output_guess, int message_guess,
    char* first_guess, char* second_guess, char* third_guess, char* fourth_guess,
    char* fifth_guess, char* sixth_guess, char* seventh_guess, char* eighth_guess,
    char* ninth_guess);

// Choose-zone entry (OP_DzChooseZone): four ints, a 128-byte and a 64-byte string.
// FUNCTION: TITANIUM 0x00445FF0
ChooseZoneEntry_guess* ChooseZoneEntry_guess::CopyFrom_guess(const ChooseZoneEntry_guess* source_guess) {
    field0_guess = source_guess->field0_guess;
    field4_guess = source_guess->field4_guess;
    field8_guess = source_guess->field8_guess;
    fieldc_guess = source_guess->fieldc_guess;
    CopyRegion_guess(&field90_guess, &source_guess->field90_guess);
    CopyRegion_guess(&pad10_guess[0], &source_guess->pad10_guess[0]);
    return this;
}

// Reads one choose-zone entry from the packet; returns the bytes used. Each string is passed to __snprintf
// as the format, so a '%' in one is expanded (original).
// FUNCTION: TITANIUM 0x00446038
// @early-stop: budget, structural ndiff=27
int ChooseZoneEntry_guess::Read_guess(const char* source_guess, int size_guess) {
    int result_guess = 0;
    if (source_guess != 0) {
        memcpy(&field0_guess, source_guess, 4);
        memcpy(&field4_guess, source_guess + 4, 4);
        memcpy(&field8_guess, source_guess + 8, 4);
        memcpy(&fieldc_guess, source_guess + 0xc, 4);
        const char* text_guess = source_guess + 0x10;
        pad10_guess[0x7f] = 0;
        ((EntryBlock_guess*)this)->pad94_guess[0x3b] = 0;
        unsigned int firstSize_guess = 0x7f;
        unsigned int length_guess = strlen(text_guess);
        if (length_guess + 1 <= firstSize_guess) {
            firstSize_guess = strlen(text_guess) + 1;
        }
        int firstWritten_guess = __snprintf(pad10_guess, firstSize_guess, text_guess);
        firstWritten_guess += 0x11;
        text_guess = source_guess + firstWritten_guess;
        unsigned int secondSize_guess = 0x3f;
        length_guess = strlen(text_guess);
        if (length_guess + 1 <= secondSize_guess) {
            secondSize_guess = strlen(text_guess) + 1;
        }
        int secondWritten_guess = __snprintf(&field90_guess, secondSize_guess, text_guess);
        result_guess = firstWritten_guess + secondWritten_guess + 1;
    }
    return result_guess;
}

// Compass point (OP_DzCompass): id, type, an int, then x, y, z floats.
// FUNCTION: TITANIUM 0x004460F4
CompassPoint_guess* CompassPoint_guess::CopyFrom_guess(const CompassPoint_guess* source_guess) {
    values_guess[0] = source_guess->values_guess[0];
    values_guess[1] = source_guess->values_guess[1];
    values_guess[2] = source_guess->values_guess[2];
    values_guess[3] = source_guess->values_guess[3];
    values_guess[4] = source_guess->values_guess[4];
    values_guess[5] = source_guess->values_guess[5];
    return this;
}

// Reads a 24-byte record (six dwords) from `source`; returns the bytes used (0x18), or 0 for a null
// source. The second argument is not used.
// FUNCTION: TITANIUM 0x0044611F
int CompassPoint_guess::CopyBytesFrom_guess(const CompassPoint_guess* source_guess, int unused_guess) {
    int result_guess = 0;
    if (source_guess != 0) {
        memcpy(&values_guess[0], &source_guess->values_guess[0], 4);
        memcpy(&values_guess[1], &source_guess->values_guess[1], 4);
        memcpy(&values_guess[2], &source_guess->values_guess[2], 4);
        memcpy(&values_guess[3], &source_guess->values_guess[3], 4);
        memcpy(&values_guess[4], &source_guess->values_guess[4], 4);
        memcpy(&values_guess[5], &source_guess->values_guess[5], 4);
        result_guess = 0x18;
    }
    return result_guess;
}

// Empty lockout timer record: both names cleared, no time left, +0x184 = -1, no next.
// FUNCTION: TITANIUM 0x0044618B
LockoutTimer_guess* LockoutTimer_guess::Init_guess() {
    memset(first_guess, 0, 0x80);
    memset(second_guess, 0, 0x100);
    field180_guess = 0;
    field184_guess = -1;
    field188_guess = 0;
    return this;
}

// Reads one lockout timer (0x18C-byte record): expedition name, seconds left (+0x180), an int (+0x184) and
// the event name (+0x80).
// FUNCTION: TITANIUM 0x004461CA
int LockoutTimer_guess::SetSource_guess(const char* source_guess) {
    int offset_guess = 0;
    if (source_guess != 0) {
        offset_guess = sprintf(first_guess, "%s", source_guess) + 1;
        memcpy(&field180_guess, source_guess + offset_guess, 4);
        offset_guess += 4;
        memcpy(&field184_guess, source_guess + offset_guess, 4);
        offset_guess += 4;
        offset_guess += sprintf(second_guess, "%s", source_guess + offset_guess) + 1;
    }
    return offset_guess;
}

// Appends a lockout timer node at the tail of the chain; null is ignored.
// FUNCTION: TITANIUM 0x00446299
void WideList_guess::Append_guess(WideNode_guess* node_guess) {
    if (node_guess != 0) {
        if (head_guess == 0) {
            head_guess = node_guess;
        } else {
            tail_guess->next_guess = node_guess;
        }
        tail_guess = node_guess;
    }
}

// Frees the member list (+0x110).
// FUNCTION: TITANIUM 0x004462BB
void Expedition_guess::ClearMembers_guess() {
    while (head110_guess != 0) {
        TextNode_guess* node_guess = head110_guess;
        head110_guess = node_guess->next_guess;
        free(node_guess);
    }
    head110_guess = 0;
}

// Frees the lockout timers (+0x114).
// FUNCTION: TITANIUM 0x004462E8
void Expedition_guess::ClearLockoutTimers_guess() {
    while (head114_guess != 0) {
        WideNode_guess* node_guess = head114_guess;
        head114_guess = node_guess->next_guess;
        free(node_guess);
    }
    head114_guess = 0;
}

// Compass marker for the marker manager (0x850C88): colour at +0/+4/+8, position at +0xC/+0x10/+0x14.
// FUNCTION: TITANIUM 0x00446318
CompassMarker_guess::CompassMarker_guess() {
    field18_guess = 0;
    field14_guess = 0.0f;
    field10_guess = 0.0f;
    fieldc_guess = 0.0f;
    field8_guess = 0;
    field4_guess = 0;
    field0_guess = 0;
    field24_guess = 0;
    field28_guess = 0;
    field2c_guess = 0;
}

// Zeroes the compass entry: three ints, the x/y/z floats and the marker pointer.
// FUNCTION: TITANIUM 0x00446340
Copy7Zero_guess::Copy7Zero_guess() :
    field0_guess(0),
    field4_guess(0),
    field8_guess(0),
    fieldc_guess(0.0f),
    field10_guess(0.0f),
    field14_guess(0.0f),
    field18_guess(0) {
}

// Compass entry as kept by the expedition: the point plus its marker (+0x18).
// FUNCTION: TITANIUM 0x0044635F
Copy7Init_guess::Copy7Init_guess(const CompassPoint_guess* source_guess) {
    field0_guess = 0;
    field4_guess = 0;
    field8_guess = 0;
    fieldc_guess = 0.0f;
    field10_guess = 0.0f;
    field14_guess = 0.0f;
    ((CompassPoint_guess*)this)->CopyFrom_guess(source_guess);
    field18_guess = 0;
}

// Compass entry assignment: the point (six dwords), then the marker pointer.
// FUNCTION: TITANIUM 0x0044638F
Copy7_guess* Copy7_guess::CopyFrom_guess(const int* source_guess) {
    CompassPoint_guess local_guess = *(const CompassPoint_guess*)source_guess;
    ((CompassPoint_guess*)this)->CopyFrom_guess(&local_guess);
    values_guess[6] = source_guess[6];
    return this;
}

// Forgets the expedition: members, timers, names and flags.
// FUNCTION: TITANIUM 0x004463C2
void Expedition_guess::Reset_guess() {
    ClearMembers_guess();
    ClearLockoutTimers_guess();
    field10c_guess = 0;
    field4_guess = 0;
    field48_guess = 0;
    field49_guess = 0;
    field4a_guess = 0;
    field8a_guess = 0;
    field8_guess = 0;
}

// Whether `value` is an expedition member.
// FUNCTION: TITANIUM 0x004463F0
char Expedition_guess::Find_guess(char* value_guess) {
    if (value_guess != 0) {
        TextNode_guess* node_guess = head110_guess;
        while (node_guess != 0) {
            if (__stricmp(node_guess->text_guess, value_guess) == 0) {
                return 1;
            }
            node_guess = node_guess->next_guess;
        }
    }
    return 0;
}

// Popup callback for an expedition invite (message 0x3817, OP_DzExpeditionInvite): sends the answer
// (OP_DzExpeditionInviteResponse, 0x4C bytes) with the fields SetFrom_guess stored at +4, +8 and +0x48.
// FUNCTION: TITANIUM 0x00446421
void MessageState_guess::Send_guess(int message_guess, unsigned char flags_guess, int unused_guess) {
    if (message_guess == 0x3817) {
        OutgoingData_guess data_guess;
        // Accepted when the popup's button flags have 1 or 4 set (probably Yes/OK).
        data_guess.flag8_guess = (flags_guess & 5) != 0;
        data_guess.field4_guess = field4_guess;
        data_guess.flag9_guess = flag48_guess;
        memset(data_guess.text_guess, 0, 0x40);
        strncpy(data_guess.text_guess, text_guess, 0x3f);
        SendConnectionMessage_guess(&g_voidConnection_guess, OP_DzExpeditionInviteResponse,
            (int)&data_guess, 0x4c, 1);
    }
}

// OP_DzExpeditionInvite: stores the invite and asks the player (string 0xDC7 with the inviter and the
// expedition name); Send_guess gets the answer. MessageState_guess is a view of the expedition object.
// FUNCTION: TITANIUM 0x00446494
void MessageState_guess::SetFrom_guess(EventData_guess* source_guess) {
    char message_guess[0x1004];
    if (source_guess != 0) {
        field4_guess = source_guess->field108_guess;
        flag48_guess = source_guess->flagc4_guess;
        memset(text_guess, 0, 0x40);
        strncpy(text_guess, source_guess->textc5_guess, 0x3f);
        BuildEventMessage_guess(message_guess, 0xdc7, source_guess->first_guess,
            source_guess->second_guess, 0, 0, 0, 0, 0, 0, 0);
        pConfirmationDialogPool_guess->Activate(this, 0x3817, message_guess,
            0xc, -1, 0, 1);
    }
}

// OP_DzExpeditionInfo: leader (+0x4A), expedition name (+0x8A), max players (+0x10C). Clears the members
// when the expedition ends and opens the expedition window (0x9918C0) when one starts.
// FUNCTION: TITANIUM 0x00446538
void Expedition_guess::Handle_OP_DzExpeditionInfo_guess(SourceData_guess* source_guess) {
    if (source_guess != 0) {
        // The names are passed as the format string; a '%' in one is expanded (original).
        sprintf(&field4a_guess, source_guess->format8c_guess);
        sprintf(&field8a_guess, source_guess->formatc_guess);
        bool refresh_guess;
        if (field49_guess != 0 || source_guess->field4_guess == 0) {
            refresh_guess = false;
        } else {
            refresh_guess = true;
        }
        char state_guess = source_guess->field4_guess;
        field49_guess = state_guess;
        if (state_guess != 0) {
            field10c_guess = source_guess->field8_guess;
        } else {
            field10c_guess = 0;
            ClearMembers_guess();
        }
        if (pinstCDynamicZoneWnd_guess != 0) {
            if (refresh_guess && pinstCDynamicZoneWnd_guess->dShow == 0) {
                pinstCDynamicZoneWnd_guess->Show(1, 1);
                pinstCDynamicZoneWnd_guess->StoreIniVis();
            }
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FF21C_guess();
        }
    }
}

// OP_DzSetLeaderName.
// FUNCTION: TITANIUM 0x004465E0
void Expedition_guess::Handle_OP_DzSetLeaderName_guess(NamedSource_guess* source_guess) {
    if (source_guess != 0) {
        sprintf(&field4a_guess, "%s", source_guess->name_guess);
        if (pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FF21C_guess();
        }
    }
}

struct Panel44660F_guess {
    // EXTERNAL: TITANIUM 0x0040812F Panel44660F_guess::Init_guess
    void Init_guess(char* buffer_guess, int a_guess, int b_guess, int c_guess,
        int d_guess, int e_guess, int f_guess);
};

// EXTERNAL: TITANIUM 0x00407DC9 MakePanel44660F_guess
Panel44660F_guess* __cdecl MakePanel44660F_guess();

struct Handle44660F_arg_guess {
    int field0_guess;
    int field4_guess;
};

// OP_DzExpeditionEndsWarning: puts string 0xDDF with the minutes left (+4) on screen as large
// text; the 500/500/5000 are probably fade-in, fade-out and hold times in ms.
// FUNCTION: TITANIUM 0x0044660F
void Expedition_guess::Handle_OP_DzExpeditionEndsWarning_guess(int value_guess) {
    char buffer_guess[2048];
    char text_guess[64];
    if (value_guess != 0) {
        sprintf(text_guess, "%d", ((Handle44660F_arg_guess*)value_guess)->field4_guess);
        BuildEventMessage_guess(buffer_guess, 0xddf, text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        MakePanel44660F_guess()->Init_guess(buffer_guess, 0xf, 10, 0xcc, 500, 500, 5000);
    }
}

// Appends `node` to the end of the singly linked chain at +0x110 (it becomes the head when the chain is
// empty). A null node is ignored.
// FUNCTION: TITANIUM 0x00446690
void Expedition_guess::Append_guess(TextNode_guess* node_guess) {
    if (node_guess != 0) {
        if (head110_guess == 0) {
            head110_guess = node_guess;
        } else {
            TextNode_guess* current_guess = head110_guess;
            while (current_guess->next_guess != 0) {
                current_guess = current_guess->next_guess;
            }
            current_guess->next_guess = node_guess;
        }
    }
}

// Deletes the first node whose text equals `value_guess`, ignoring case.
// FUNCTION: TITANIUM 0x004466B7
void Expedition_guess::RemoveByName_guess(char* value_guess) {
    if (value_guess != 0) {
        TextNode_guess* node_guess = head110_guess;
        if (node_guess != 0) {
            TextNode_guess** link_guess = &head110_guess;
            do {
                if (__stricmp(node_guess->text_guess, value_guess) == 0) {
                    *link_guess = node_guess->next_guess;
                    delete node_guess;
                    return;
                }
                link_guess = &node_guess->next_guess;
                node_guess = *link_guess;
            } while (node_guess != 0);
        }
    }
}

// Hash-table iteration start: the head of the first non-empty bucket (callers cast tables to this view).
// FUNCTION: TITANIUM 0x004466FA
int IntArrayView_guess::FirstNonZero_guess() {
    int index_guess = 0;
    if (count_guess > 0) {
        int* current_guess = values_guess;
        do {
            int value_guess = *current_guess;
            if (value_guess != 0) {
                return value_guess;
            }
            index_guess++;
            current_guess++;
        } while (index_guess < count_guess);
    }
    return 0;
}

// Iteration step: the next node in the chain, else the head of the next non-empty bucket.
// FUNCTION: TITANIUM 0x00446718
HashEntryA_guess* HashTableA_guess::NextEntry_guess(HashEntryA_guess* entry_guess) {
    int index_guess = entry_guess->hash_guess % bucketCount_guess;
    HashEntryA_guess* result_guess = entry_guess->link_guess;
    if (result_guess != 0) {
        return result_guess;
    }
    int nextIndex_guess = index_guess + 1;
    if (index_guess + 1 < bucketCount_guess) {
        for (; nextIndex_guess < bucketCount_guess; ++nextIndex_guess) {
            result_guess = buckets_guess[nextIndex_guess];
            if (result_guess != 0) {
                return result_guess;
            }
        }
    }
    return 0;
}

// HashTableB/Wide/Small_guess are one chained hash table for three node types: compass entries (B, in the
// expedition), choose-zone entries (Wide) and compass points read from a packet (Small). Buckets are sized
// by NextPrimeCandidate_guess; inserts go at the chain head.
// FUNCTION: TITANIUM 0x0044674E
void HashTableB_guess::Clear_guess() {
    for (int index_guess = 0; index_guess < bucketCount_guess; index_guess++) {
        HashEntryB_guess* node_guess = buckets_guess[index_guess];
        if (node_guess != 0) {
            usedCount_guess--;
            do {
                HashEntryB_guess* next_guess = node_guess->link_guess;
                free(node_guess);
                nodeCount_guess--;
                node_guess = next_guess;
            } while (node_guess != 0);
            buckets_guess[index_guess] = node_guess;
        }
    }
}

// Find_guess is misnamed: no search. Returns the entry after `entry_guess` (its chain successor, else the head of the
// next non-empty bucket, else null).
// FUNCTION: TITANIUM 0x00446788
HashEntryB_guess* HashTableB_guess::NextEntry_guess(HashEntryB_guess* entry_guess) {
    int index_guess = entry_guess->hash_guess % bucketCount_guess;
    HashEntryB_guess* result_guess = entry_guess->link_guess;
    if (result_guess != 0) {
        return result_guess;
    }
    int nextIndex_guess = index_guess + 1;
    if (index_guess + 1 < bucketCount_guess) {
        for (; nextIndex_guess < bucketCount_guess; ++nextIndex_guess) {
            result_guess = buckets_guess[nextIndex_guess];
            if (result_guess != 0) {
                return result_guess;
            }
        }
    }
    return 0;
}

// Frees every node of the choose-zone table, keeping the node and used-bucket counts in step; the
// bucket array stays.
// FUNCTION: TITANIUM 0x004467BE
void HashTableWide_guess::Clear_guess() {
    for (int index_guess = 0; index_guess < bucketCount_guess; index_guess++) {
        HashEntryWide_guess* node_guess = buckets_guess[index_guess];
        if (node_guess != 0) {
            usedCount_guess--;
            do {
                HashEntryWide_guess* next_guess = node_guess->next_guess;
                free(node_guess);
                nodeCount_guess--;
                node_guess = next_guess;
            } while (node_guess != 0);
            buckets_guess[index_guess] = node_guess;
        }
    }
}

// Rehash of the Wide table (choose-zone entries): every node moves to bucket hash % n for n =
// 0x0042429E(the request) (odd; prime squares can pass); the used-bucket count is rebuilt.
// FUNCTION: TITANIUM 0x004467FB
void HashTableWide_guess::Rehash_guess(int bucketCount_guess) {
    HashEntryWide_guess** oldBuckets_guess = buckets_guess;
    int oldCount_guess = this->bucketCount_guess;
    this->bucketCount_guess = NextPrimeCandidate_guess(bucketCount_guess);
    HashEntryWide_guess** newBuckets_guess = (HashEntryWide_guess**)
        AllocateBucketStorage_guess(this->bucketCount_guess << 2);
    buckets_guess = newBuckets_guess;
    memset(newBuckets_guess, 0, this->bucketCount_guess << 2);
    usedCount_guess = 0;
    if (nodeCount_guess > 0) {
        bucketCount_guess = 0;
        if (oldCount_guess > 0) {
            do {
                HashEntryWide_guess* node_guess = oldBuckets_guess[bucketCount_guess];
                while (node_guess != 0) {
                    HashEntryWide_guess* current_guess = node_guess;
                    unsigned int hash_guess = current_guess->hash_guess;
                    HashEntryWide_guess** link_guess = &node_guess->next_guess;
                    node_guess = *link_guess;
                    unsigned int index_guess = hash_guess % this->bucketCount_guess;
                    HashEntryWide_guess* head_guess = buckets_guess[index_guess];
                    if (head_guess == 0) {
                        *link_guess = 0;
                        buckets_guess[index_guess] = current_guess;
                        usedCount_guess++;
                    } else {
                        *link_guess = head_guess;
                        buckets_guess[index_guess] = current_guess;
                    }
                }
                bucketCount_guess++;
            } while (bucketCount_guess < oldCount_guess);
        }
    }
    FreeAt60D682_guess(oldBuckets_guess);
}

// Frees every node of the hash table, keeping the node and used-bucket counts in step; the bucket array
// stays.
// FUNCTION: TITANIUM 0x004468A9
void HashTableSmall_guess::Clear_guess() {
    for (int index_guess = 0; index_guess < bucketCount_guess; index_guess++) {
        HashEntrySmall_guess* node_guess = buckets_guess[index_guess];
        if (node_guess != 0) {
            usedCount_guess--;
            do {
                HashEntrySmall_guess* next_guess = node_guess->next_guess;
                free(node_guess);
                nodeCount_guess--;
                node_guess = next_guess;
            } while (node_guess != 0);
            buckets_guess[index_guess] = node_guess;
        }
    }
}

// Rehash of the Small table (compass points from a packet); same steps as 0x004467FB.
// FUNCTION: TITANIUM 0x004468E3
void HashTableSmall_guess::Rehash_guess(int bucketCount_guess) {
    HashEntrySmall_guess** oldBuckets_guess = buckets_guess;
    int oldCount_guess = this->bucketCount_guess;
    this->bucketCount_guess = NextPrimeCandidate_guess(bucketCount_guess);
    HashEntrySmall_guess** newBuckets_guess = (HashEntrySmall_guess**)
        AllocateBucketStorage_guess(this->bucketCount_guess << 2);
    buckets_guess = newBuckets_guess;
    memset(newBuckets_guess, 0, this->bucketCount_guess << 2);
    usedCount_guess = 0;
    if (nodeCount_guess > 0) {
        bucketCount_guess = 0;
        if (oldCount_guess > 0) {
            do {
                HashEntrySmall_guess* node_guess = oldBuckets_guess[bucketCount_guess];
                while (node_guess != 0) {
                    HashEntrySmall_guess* current_guess = node_guess;
                    unsigned int hash_guess = current_guess->hash_guess;
                    HashEntrySmall_guess** link_guess = &node_guess->next_guess;
                    node_guess = *link_guess;
                    unsigned int index_guess = hash_guess % this->bucketCount_guess;
                    HashEntrySmall_guess* head_guess = buckets_guess[index_guess];
                    if (head_guess == 0) {
                        *link_guess = 0;
                        buckets_guess[index_guess] = current_guess;
                        usedCount_guess++;
                    } else {
                        *link_guess = head_guess;
                        buckets_guess[index_guess] = current_guess;
                    }
                }
                bucketCount_guess++;
            } while (bucketCount_guess < oldCount_guess);
        }
    }
    FreeAt60D682_guess(oldBuckets_guess);
}

// Rehash of the B table (the expedition's compass entries); same steps as 0x004467FB.
// FUNCTION: TITANIUM 0x0044698B
void HashTableB_guess::Rehash_guess(int bucketCount_guess) {
    HashEntryB_guess** oldBuckets_guess = buckets_guess;
    int oldCount_guess = this->bucketCount_guess;
    this->bucketCount_guess = NextPrimeCandidate_guess(bucketCount_guess);
    HashEntryB_guess** newBuckets_guess = (HashEntryB_guess**)
        AllocateBucketStorage_guess(this->bucketCount_guess << 2);
    buckets_guess = newBuckets_guess;
    memset(newBuckets_guess, 0, this->bucketCount_guess << 2);
    usedCount_guess = 0;
    if (nodeCount_guess > 0) {
        bucketCount_guess = 0;
        if (oldCount_guess > 0) {
            do {
                HashEntryB_guess* node_guess = oldBuckets_guess[bucketCount_guess];
                while (node_guess != 0) {
                    HashEntryB_guess* current_guess = node_guess;
                    unsigned int hash_guess = current_guess->hash_guess;
                    HashEntryB_guess** link_guess = &node_guess->link_guess;
                    node_guess = *link_guess;
                    unsigned int index_guess = hash_guess % this->bucketCount_guess;
                    HashEntryB_guess* head_guess = buckets_guess[index_guess];
                    if (head_guess == 0) {
                        *link_guess = 0;
                        buckets_guess[index_guess] = current_guess;
                        usedCount_guess++;
                    } else {
                        *link_guess = head_guess;
                        buckets_guess[index_guess] = current_guess;
                    }
                }
                bucketCount_guess++;
            } while (bucketCount_guess < oldCount_guess);
        }
    }
    FreeAt60D682_guess(oldBuckets_guess);
}

// Reads a member list: a 4-byte header, the count, then per member a name and a status byte. Returns the
// bytes read (0 for a null source).
// FUNCTION: TITANIUM 0x00446A33
int TextList_guess::Read_guess(const char* source_guess, int unused_guess) {
    int index_guess;
    int offset_guess = 0;
    if (source_guess != 0) {
        memcpy(this, source_guess, 4);
        memcpy(&count_guess, source_guess + 4, 4);
        offset_guess = 8;
        for (index_guess = 0; index_guess < count_guess; index_guess++) {
            TextNode_guess* node_guess = (TextNode_guess*)operator new(0x48);
            if (node_guess != 0) {
                node_guess = node_guess->Init_guess();
            } else {
                node_guess = 0;
            }
            offset_guess += node_guess->SetText_guess(const_cast<char*>(source_guess + offset_guess));
            Append_guess(node_guess);
        }
    }
    return offset_guess;
}

// Reads lockout timers: count, then SetSource_guess records.
// FUNCTION: TITANIUM 0x00446ABE
int WideList_guess::Read_guess(const char* source_guess, int unused_guess) {
    int index_guess;
    int offset_guess = 0;
    if (source_guess != 0) {
        memcpy(this, source_guess, 4);
        memcpy(&count_guess, source_guess + 4, 4);
        offset_guess = 8;
        for (index_guess = 0; index_guess < count_guess; index_guess++) {
            LockoutTimer_guess* node_guess = (LockoutTimer_guess*)operator new(0x18c);
            if (node_guess != 0) {
                node_guess = node_guess->Init_guess();
            } else {
                node_guess = 0;
            }
            offset_guess += node_guess->SetSource_guess(source_guess + offset_guess);
            Append_guess((WideNode_guess*)node_guess);
        }
    }
    return offset_guess;
}

// Field +8 of the first compass entry whose type (+4) is 1; -1 if none.
// FUNCTION: TITANIUM 0x00446B4C
int LookupOwner_guess::FindStateOne_guess() {
    HashTableB_guess* tablePtr_guess = &table_guess;
    HashEntryB_guess* entry_guess = (HashEntryB_guess*)
        ((IntArrayView_guess*)tablePtr_guess)->FirstNonZero_guess();
    while (entry_guess != 0) {
        if (entry_guess->field4_guess == 1) {
            return entry_guess->field8_guess;
        }
        entry_guess = tablePtr_guess->NextEntry_guess(entry_guess);
    }
    return -1;
}

// OP_DzMemberList: replaces the member list.
// FUNCTION: TITANIUM 0x00446B78
void Expedition_guess::Handle_OP_DzMemberList_guess(char* source_guess) {
    if (source_guess != 0) {
        TextList_guess list_guess;
        list_guess.count_guess = 0;
        list_guess.head_guess = 0;
        list_guess.tail_guess = 0;
        list_guess.Read_guess(source_guess, 1);
        ClearMembers_guess();
        head110_guess = list_guess.head_guess;
        if (pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FF21C_guess();
        }
    }
}

// OP_DzMemberListStatus: swaps in the updated record for each member named in the packet.
// FUNCTION: TITANIUM 0x00446BC4
// @early-stop: budget, diff ndiff=44
void Expedition_guess::Handle_OP_DzMemberListStatus_guess(char* source_guess) {
    if (source_guess != 0) {
        TextList_guess list_guess;
        list_guess.count_guess = 0;
        list_guess.head_guess = 0;
        list_guess.tail_guess = 0;
        list_guess.Read_guess(source_guess, 1);
        TextNode_guess* node_guess = list_guess.head_guess;
        if (node_guess != 0) {
            TextNode_guess** link_guess = &head110_guess;
            TextNode_guess* next_guess;
            do {
                TextNode_guess* current_guess = *link_guess;
                next_guess = node_guess->next_guess;
                while (current_guess != 0) {
                    if (__stricmp(current_guess->text_guess, node_guess->text_guess) == 0) {
                        break;
                    }
                    link_guess = &current_guess->next_guess;
                    current_guess = *link_guess;
                }
                if (current_guess != 0) {
                    *link_guess = node_guess;
                    node_guess->next_guess = current_guess->next_guess;
                    free(current_guess);
                }
                link_guess = &head110_guess;
            } while (next_guess != 0);
        }
        if (pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FF21C_guess();
        }
    }
}

// OP_DzExpeditionLockoutTimers: replaces the timers, turning seconds left into an expiry time (now + left).
// FUNCTION: TITANIUM 0x00446C5F
void Expedition_guess::Handle_OP_DzExpeditionLockoutTimers_guess(char* source_guess) {
    if (source_guess != 0) {
        WideList_guess list_guess;
        list_guess.count_guess = 0;
        list_guess.head_guess = 0;
        list_guess.tail_guess = 0;
        list_guess.Read_guess(source_guess, 1);
        ClearLockoutTimers_guess();
        int stamp_guess = GetCurrent_guess();
        WideNode_guess* node_guess = list_guess.head_guess;
        while (node_guess != 0) {
            node_guess->field180_guess += stamp_guess;
            node_guess = node_guess->next_guess;
        }
        head114_guess = list_guess.head_guess;
        if (pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FE0FD_guess();
        }
    }
}

// OP_DzMemberListName: adds (flag +4 set) or removes one member by name.
// FUNCTION: TITANIUM 0x00446CC5
void Expedition_guess::Handle_OP_DzMemberListName_guess(LineSource_guess* source_guess) {
    if (source_guess != 0) {
        if (source_guess->flag4_guess != 0) {
            TextNode_guess* memory_guess = new TextNode_guess;
            TextNode_guess* node_guess;
            if (memory_guess != 0) {
                node_guess = memory_guess->Init_guess();
            } else {
                node_guess = 0;
            }
            CopyRegion_guess(node_guess->text_guess, source_guess->text8_guess);
            Append_guess(node_guess);
        } else {
            RemoveByName_guess(source_guess->text8_guess);
        }
        if (pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->UpdateIfShown_4FF21C_guess();
            pinstCDynamicZoneWnd_guess->Update_4FF11E_guess();
        }
    }
}

// Frees the compass entries (+0x118) and their markers; EntryManager_guess is the expedition object.
// FUNCTION: TITANIUM 0x00446D32
void EntryManager_guess::ReleaseContents_guess() {
    if (pinstCCompassWnd_guess != 0) {
        HashTableB_guess* tablePtr_guess = &table_guess;
        HashEntryB_guess* entry_guess = (HashEntryB_guess*)
            ((IntArrayView_guess*)tablePtr_guess)->FirstNonZero_guess();
        while (entry_guess != 0) {
            HashEntryB_guess* current_guess = entry_guess;
            entry_guess = tablePtr_guess->NextEntry_guess(entry_guess);
            if (current_guess->payload_guess != 0) {
                pinstCCompassWnd_guess->RemoveMarker_guess(current_guess->payload_guess);
                if (current_guess->payload_guess != 0) {
                    free(current_guess->payload_guess);
                }
            }
        }
    }
    table_guess.Clear_guess();
}

// Choose-zone table constructor: empty, buckets sized for `bucketCount` (0x004467FB).
// FUNCTION: TITANIUM 0x00446D94
HashTableWide_guess::HashTableWide_guess(int bucketCount_guess) {
    buckets_guess = 0;
    this->bucketCount_guess = 0;
    nodeCount_guess = 0;
    usedCount_guess = 0;
    Rehash_guess(bucketCount_guess);
}

// Frees every choose-zone entry and the bucket array.
// FUNCTION: TITANIUM 0x00446DB3
void HashTableWide_guess::Release_guess() {
    Clear_guess();
    FreeAt60D682_guess(buckets_guess);
}

// Wide insert: copies `source_guess` into a new 0xD8-byte node and pushes it on its bucket's chain.
// FUNCTION: TITANIUM 0x00446DC5
void HashTableWide_guess::Insert_guess(const ChooseZoneEntry_guess* source_guess, unsigned int hash_guess) {
    HashEntryWide_guess* allocation_guess = (HashEntryWide_guess*)operator new(0xd8);
    HashEntryWide_guess* node_guess;
    if (allocation_guess != 0) {
        allocation_guess->field4_guess = -1;
        allocation_guess->fieldc_guess = -1;
        allocation_guess->field0_guess = 0;
        allocation_guess->field8_guess = 0;
        allocation_guess->pad10_guess[0] = 0;
        allocation_guess->field90_guess = 0;
        node_guess = allocation_guess;
    } else {
        node_guess = 0;
    }
    node_guess->CopyFrom_guess(source_guess);
    node_guess->hash_guess = hash_guess;
    unsigned int index_guess = hash_guess % bucketCount_guess;
    HashEntryWide_guess* head_guess = buckets_guess[index_guess];
    if (head_guess == 0) {
        node_guess->next_guess = 0;
        buckets_guess[index_guess] = node_guess;
        usedCount_guess++;
    } else {
        node_guess->next_guess = head_guess;
        buckets_guess[index_guess] = node_guess;
    }
    nodeCount_guess++;
}

// Packet compass-point table constructor: empty, buckets sized for `bucketCount`.
// FUNCTION: TITANIUM 0x00446E43
HashTableSmall_guess::HashTableSmall_guess(int bucketCount_guess) {
    buckets_guess = 0;
    this->bucketCount_guess = 0;
    nodeCount_guess = 0;
    usedCount_guess = 0;
    Rehash_guess(bucketCount_guess);
}

// Frees every packet compass point and the bucket array.
// FUNCTION: TITANIUM 0x00446E62
void HashTableSmall_guess::Release_guess() {
    Clear_guess();
    FreeAt60D682_guess(buckets_guess);
}

// Small insert: copies `source_guess` into a new 0x20-byte node and pushes it on its bucket's chain.
// FUNCTION: TITANIUM 0x00446E74
void HashTableSmall_guess::Insert_guess(const CompassPoint_guess* source_guess, unsigned int hash_guess) {
    HashEntrySmall_guess* allocation_guess = (HashEntrySmall_guess*)operator new(0x20);
    HashEntrySmall_guess* node_guess;
    if (allocation_guess != 0) {
        allocation_guess->field0_guess = 0;
        allocation_guess->field4_guess = 0;
        allocation_guess->fieldc_guess = 0.0f;
        allocation_guess->field8_guess = 0;
        allocation_guess->field10_guess = 0.0f;
        allocation_guess->field14_guess = 0.0f;
        node_guess = allocation_guess;
    } else {
        node_guess = 0;
    }
    ((CompassPoint_guess*)node_guess)->CopyFrom_guess(source_guess);
    node_guess->hash_guess = hash_guess;
    unsigned int index_guess = hash_guess % bucketCount_guess;
    HashEntrySmall_guess* head_guess = buckets_guess[index_guess];
    if (head_guess == 0) {
        node_guess->next_guess = 0;
        buckets_guess[index_guess] = node_guess;
        usedCount_guess++;
    } else {
        node_guess->next_guess = head_guess;
        buckets_guess[index_guess] = node_guess;
    }
    nodeCount_guess++;
}

// Compass entry table constructor: empty, buckets sized for `bucketCount`.
// FUNCTION: TITANIUM 0x00446EE6
HashTableB_guess::HashTableB_guess(int bucketCount_guess) {
    buckets_guess = 0;
    this->bucketCount_guess = 0;
    nodeCount_guess = 0;
    usedCount_guess = 0;
    Rehash_guess(bucketCount_guess);
}

// Compass entry table destructor: frees every node and the bucket array.
// FUNCTION: TITANIUM 0x00446F05
HashTableB_guess::~HashTableB_guess() {
    Clear_guess();
    delete[] buckets_guess;
}

// B insert: copies `source_guess` into a new 0x24-byte node and pushes it on its bucket's chain.
// FUNCTION: TITANIUM 0x00446F17
void HashTableB_guess::Insert_guess(const int* source_guess, unsigned int hash_guess) {
    Node7_guess* node_guess = (Node7_guess*)operator new(0x24);
    if (node_guess != 0) {
        node_guess->Init_guess();
    } else {
        node_guess = 0;
    }
    ((Copy7_guess*)node_guess)->CopyFrom_guess(source_guess);
    HashEntryB_guess* entry_guess = (HashEntryB_guess*)node_guess;
    entry_guess->hash_guess = hash_guess;
    unsigned int index_guess = hash_guess % bucketCount_guess;
    HashEntryB_guess* head_guess = buckets_guess[index_guess];
    if (head_guess == 0) {
        entry_guess->link_guess = 0;
        buckets_guess[index_guess] = entry_guess;
        usedCount_guess++;
    } else {
        entry_guess->link_guess = head_guess;
        buckets_guess[index_guess] = entry_guess;
    }
    nodeCount_guess++;
}

// Reads the choose-zone list (count, entries) into the table, keyed by each entry's first int.
// FUNCTION: TITANIUM 0x00446F76
int HashTableWideOwner_guess::Read_guess(const char* source_guess, int size_guess) {
    int offset_guess = 0;
    if (source_guess != 0) {
        int count_guess = 0;
        memcpy(this, source_guess, 4);
        memcpy(&count_guess, source_guess + 4, 4);
        offset_guess = 8;
        for (int index_guess = 0; index_guess < count_guess; index_guess++) {
            EntryBlock_guess entry_guess;
            entry_guess.field4_guess = -1;
            entry_guess.fieldc_guess = -1;
            entry_guess.field0_guess = 0;
            entry_guess.field8_guess = 0;
            entry_guess.pad10_guess[0] = 0;
            entry_guess.field90_guess = 0;
            offset_guess += entry_guess.Read_guess(source_guess + offset_guess, size_guess - offset_guess);
            table_guess.Insert_guess(&entry_guess, entry_guess.field0_guess);
        }
    }
    return offset_guess;
}

// Reads the compass points (count, 24-byte points), keyed by id.
// FUNCTION: TITANIUM 0x00447022
int HashTableSmallOwner_guess::Read_guess(const char* source_guess, int size_guess) {
    int offset_guess = 0;
    if (source_guess != 0) {
        int count_guess = 0;
        memcpy(this, source_guess, 4);
        memcpy(&count_guess, source_guess + 4, 4);
        offset_guess = 8;
        for (int index_guess = 0; index_guess < count_guess; index_guess++) {
            Entry6_guess entry_guess;
            entry_guess.field0_guess = 0;
            entry_guess.field4_guess = 0;
            entry_guess.field8_guess = 0;
            entry_guess.fieldc_guess = 0.0f;
            entry_guess.field10_guess = 0.0f;
            entry_guess.field14_guess = 0.0f;
            offset_guess += ((CompassPoint_guess*)&entry_guess)->CopyBytesFrom_guess((const CompassPoint_guess*)(source_guess + offset_guess), size_guess - offset_guess);
            table_guess.Insert_guess((const CompassPoint_guess*)&entry_guess, entry_guess.field0_guess);
        }
    }
    return offset_guess;
}

// Expedition_guess is the expedition: +4, +8 (a name) and +0x48 hold invite fields echoed in the reply,
// +0x49 = in an expedition, +0x4A leader, +0x8A expedition name, +0x10C max players, +0x110 members,
// +0x114 lockout timers, +0x118 compass entries (20 buckets).
// FUNCTION: TITANIUM 0x004470B4
Expedition_guess::Expedition_guess() : table_guess(0x14) {
    field10c_guess = 0;
    head110_guess = 0;
    head114_guess = 0;
    field4a_guess = 0;
    field8a_guess = 0;
    field8_guess = 0;
    field4_guess = 0;
    field48_guess = 0;
}

// Expedition destructor: frees the members, the lockout timers and the compass entries.
// FUNCTION: TITANIUM 0x00447112
Expedition_guess::~Expedition_guess() {
    ClearMembers_guess();
    ClearLockoutTimers_guess();
    ReleaseContents_guess();
}

// Empty member node: no name, status 0, no next.
// FUNCTION: TITANIUM 0x00446233
TextNode_guess* TextNode_guess::Init_guess() {
    memset(text_guess, 0, 0x40);
    field40_guess = 0;
    next_guess = 0;
    return this;
}

// A name, then the status byte after its terminator; returns the bytes read.
// FUNCTION: TITANIUM 0x0044624F
int TextNode_guess::SetText_guess(char* value_guess) {
    int result_guess = 0;
    if (value_guess != 0) {
        result_guess = sprintf(text_guess, "%s", value_guess);
        result_guess++;
        field40_guess = value_guess[result_guess];
        result_guess++;
    }
    return result_guess;
}

// Appends a member node at the tail of the chain; null is ignored.
// FUNCTION: TITANIUM 0x0044627A
void TextList_guess::Append_guess(TextNode_guess* node_guess) {
    if (node_guess != 0) {
        if (head_guess == 0) {
            head_guess = node_guess;
        } else {
            tail_guess->next_guess = node_guess;
        }
        tail_guess = node_guess;
    }
}

// Frees the choose-zone table (0x00446DB3).
// FUNCTION: TITANIUM 0x0044716E
void HashTableWideOwner_guess::Release_guess() {
    table_guess.Release_guess();
}

// Frees the packet compass-point table (0x00446E62).
// FUNCTION: TITANIUM 0x00447176
void HashTableSmallOwner_guess::Release_guess() {
    table_guess.Release_guess();
}

struct ZoneSwitch_guess : Manager_guess {
    char pad_guess[0x178 - sizeof(Manager_guess)];

    // EXTERNAL: TITANIUM 0x004FEB25 ZoneSwitch_guess::ZoneSwitch_guess
    ZoneSwitch_guess(int first_guess);
};

#define g_zoneSwitch_guess EQ_GLOBAL(ZoneSwitch_guess*, 0x009918C4)

// EXTERNAL: TITANIUM 0x004FEC7B ProcessTable_guess
void __stdcall ProcessTable_guess(HashTableWide_guess* table_guess);

// OP_DzChooseZone: builds the choice table, creates the choose-zone window (0x9918C4) on first
// use, fills it and shows it.
// FUNCTION: TITANIUM 0x0044717E
// @early-stop: budget, structural ndiff=17
void Expedition_guess::Handle_OP_DzChooseZone_guess(int first_guess, int second_guess) {
    if (first_guess != 0) {
        HashTableWideOwner_guess owner_guess(50);
        owner_guess.Read_guess((const char*)first_guess, second_guess);
        if (g_zoneSwitch_guess == 0) {
            g_zoneSwitch_guess = new ZoneSwitch_guess(0);
        }
        ProcessTable_guess(&owner_guess.table_guess);
        g_zoneSwitch_guess->Slot48_guess(1, 1);
    }
}

// OP_DzCompass: replaces the compass entries. Each point gets a marker, purple (200, 50, 200)
// for types up to 2 and above 5, green (10, 100, 50) for 3-5; string 0xDFE once if any was added.
// FUNCTION: TITANIUM 0x0044721B
// @early-stop: unknown, structural ndiff=24
void Expedition_guess::Handle_OP_DzCompass_guess(int first_guess, int second_guess) {
    if (first_guess != 0) {
        // Not a bucket count: this 50 is a colour component below (misnamed local).
        int green_guess = 50;
        HashTableSmallOwner_guess owner_guess;
        owner_guess.Read_guess((const char*)first_guess, second_guess);
        ReleaseContents_guess();
        bool inserted_guess = false;
        first_guess = ((IntArrayView_guess*)&owner_guess.table_guess)->FirstNonZero_guess();
        if (first_guess != 0) {
            second_guess = (int)&table_guess;
            do {
                Copy7Init_guess copy_guess((const CompassPoint_guess*)first_guess);
                if (pinstCCompassWnd_guess != 0) {
                    CompassMarker_guess* state_guess = new CompassMarker_guess;
                    state_guess->field18_guess = 1;
                    state_guess->fieldc_guess = copy_guess.fieldc_guess;
                    state_guess->field10_guess = copy_guess.field10_guess;
                    copy_guess.field18_guess = (int)state_guess;
                    state_guess->field14_guess = copy_guess.field14_guess;
                    // The `== 1` test is implied by `<= 2`; kept for the original compare order.
                    if (copy_guess.field4_guess == 1 || copy_guess.field4_guess <= 2 ||
                        copy_guess.field4_guess > 5) {
                        state_guess->field0_guess = 200;
                        state_guess->field4_guess = green_guess;
                        state_guess->field8_guess = 200;
                    } else {
                        state_guess->field0_guess = 10;
                        state_guess->field4_guess = 100;
                        state_guess->field8_guess = green_guess;
                    }
                    pinstCCompassWnd_guess->AddMarker_guess((int)state_guess);
                    inserted_guess = true;
                }
                ((HashTableB_guess*)second_guess)->Insert_guess((const int*)&copy_guess, copy_guess.field0_guess);
                first_guess = (int)((HashTableA_guess*)&owner_guess.table_guess)->NextEntry_guess((HashEntryA_guess*)first_guess);
            } while (first_guess != 0);
            if (inserted_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0xdfe, 0), 0xf, 1);
            }
        }
    }
}

// Expedition messages from the server, by opcode.
// FUNCTION: TITANIUM 0x00447364
void Expedition_guess::Dispatch_guess(int unused_guess, unsigned int message_guess,
    int first_guess, int second_guess) {
    switch (message_guess) {
    case OP_DzCompass:
        Handle_OP_DzCompass_guess(first_guess, second_guess);
        break;
    case OP_DzExpeditionInfo:
        Handle_OP_DzExpeditionInfo_guess((SourceData_guess*)first_guess);
        break;
    case OP_DzMemberList:
        Handle_OP_DzMemberList_guess((char*)first_guess);
        break;
    case OP_DzChooseZone:
        Handle_OP_DzChooseZone_guess(first_guess, second_guess);
        break;
    case OP_DzMemberListName:
        Handle_OP_DzMemberListName_guess((LineSource_guess*)first_guess);
        break;
    case OP_DzExpeditionEndsWarning:
        Handle_OP_DzExpeditionEndsWarning_guess(first_guess);
        break;
    case OP_DzMemberListStatus:
        Handle_OP_DzMemberListStatus_guess((char*)first_guess);
        break;
    case OP_DzExpeditionInvite:
        // The invite handler is a view of this same object.
        ((MessageState_guess*)this)->SetFrom_guess((EventData_guess*)first_guess);
        break;
    case OP_DzSetLeaderName:
        Handle_OP_DzSetLeaderName_guess((NamedSource_guess*)first_guess);
        break;
    case OP_DzExpeditionLockoutTimers:
        Handle_OP_DzExpeditionLockoutTimers_guess((char*)first_guess);
        break;
    }
}

// vlong operator!= (tu_095); Vlong_guess is vlong and T_guess its by-value copy.
// FUNCTION: TITANIUM 0x00447428
int __cdecl NotEqual_guess(Vlong_guess& first_guess, const T_guess& second_guess) {
    return first_guess.Compare_guess(second_guess) != 0;
}

// vlong operator<.
// FUNCTION: TITANIUM 0x0044744E
int __cdecl Less_guess(Vlong_guess& first_guess, const T_guess& second_guess) {
    return first_guess.Compare_guess(second_guess) < 0;
}

// RSA encrypt from the vlong library (public_key::encrypt): modexp(plain, e at +8, m at +0). tu_046
// encrypts a random 64-bit seed with it.
// FUNCTION: TITANIUM 0x00447474
CXStr PublicKey_guess::Encrypt_guess(int value_guess) {
    return ModExp_guess(value_guess, (PublicKey_guess*)&field8_guess, this);
}

// Reads one '^'-separated field as a float; returns the bytes read.
// FUNCTION: TITANIUM 0x00447496
int __cdecl ParseFloat_guess(char* input_guess, float* output_guess, int option_guess) {
    char buffer_guess[0x800];
    buffer_guess[0] = 0;
    int result_guess = ReadText_guess(input_guess, buffer_guess, 0x800, option_guess, 1);
    double value_guess = atof(buffer_guess);
    *output_guess = (float)value_guess;
    return result_guess;
}

// Environment sound emitter, one line of the emitter file: name, sound (+0x104), x/y/z (+0x10C-0x114),
// a parameter (+0x118); +0x11C is the playing handle. 0x99E368 is probably the sound manager.
// FUNCTION: TITANIUM 0x004474EB
SoundEmitter_guess* SoundEmitter_guess::Init_guess() {
    field0_guess = 10;
    field11c_guess = 0;
    next_guess = 0;
    field124_guess = 0;
    field108_guess = 0;
    memset(name_guess, 0, 0x100);
    field10c_guess = 0.0f;
    field104_guess = 0;
    field110_guess = 0.0f;
    field118_guess = 0;
    field114_guess = 0.0f;
    return this;
}

// Zeroes the three dwords at +0, the 0x400-byte buffer and the dword at +0x40C.
// FUNCTION: TITANIUM 0x0044754A
BufferOwner_guess* BufferOwner_guess::Init_guess() {
    field0_guess = 0;
    field4_guess = 0;
    field8_guess = 0;
    memset(buffer_guess, 0, 0x400);
    field40c_guess = 0;
    return this;
}

// Restarts emitter `name`: stops it and, unless `id` < 0, plays it again; nonzero arguments override the
// stored position and parameter.
// FUNCTION: TITANIUM 0x00447575
void DispatchList_guess::DispatchByName_guess(char* name_guess, int id_guess, float x_guess, float y_guess, float z_guess) {
    if (name_guess == 0) {
        return;
    }
    SoundEmitter_guess* node_guess = head_guess;
    while (node_guess != 0) {
        if (__stricmp(node_guess->name_guess, name_guess) == 0) {
            if (node_guess->field11c_guess != 0) {
                g_dispatchTarget_guess->Stop_guess(node_guess->field11c_guess);
                node_guess->field11c_guess = 0;
            }
            if (id_guess < 0) {
                return;
            }
            node_guess->field11c_guess = 0;
            float xValue_guess = x_guess != 0.0f ? x_guess : node_guess->field10c_guess;
            float yValue_guess = y_guess != 0.0f ? y_guess : node_guess->field110_guess;
            float zValue_guess = z_guess != 0.0f ? z_guess : node_guess->field114_guess;
            int idValue_guess = id_guess != 0 ? id_guess : node_guess->field118_guess;
            DispatchPayload_guess payload_guess = { xValue_guess, yValue_guess, zValue_guess };
            g_dispatchTarget_guess->Dispatch_guess(node_guess->field104_guess, (int*)&payload_guess,
                idValue_guess, &node_guess->field11c_guess, 0, 0);
            return;
        }
        node_guess = node_guess->next_guess;
    }
}

// Parses name^sound^x^y^z^parameter.
// FUNCTION: TITANIUM 0x00447729
void SoundEmitter_guess::Parse_guess(char* source_guess) {
    if (source_guess != 0) {
        int first_guess = ReadText_guess(source_guess, name_guess, 0x100, 0x5e, 1);
        char* cursor_guess = source_guess + first_guess;
        int count_guess = ParseLong_guess(cursor_guess, &field104_guess, 0x5e);
        cursor_guess += count_guess;
        count_guess = ParseFloat_guess(cursor_guess, &field10c_guess, 0x5e);
        cursor_guess += count_guess;
        count_guess = ParseFloat_guess(cursor_guess, &field110_guess, 0x5e);
        cursor_guess += count_guess;
        cursor_guess += ParseFloat_guess(cursor_guess, &field114_guess, 0x5e);
        ParseLong_guess(cursor_guess, &field118_guess, 0x5e);
    }
}

// Starts every emitter that is not playing.
// FUNCTION: TITANIUM 0x0044766B
void DispatchList_guess::Process_guess() {
    SoundEmitter_guess* current_guess = head_guess;
    while (current_guess != 0) {
        if (current_guess->field11c_guess == 0) {
            DispatchPayload_guess payload_guess;
            payload_guess.first_guess = current_guess->field10c_guess;
            payload_guess.second_guess = current_guess->field110_guess;
            payload_guess.third_guess = current_guess->field114_guess;
            g_dispatchTarget_guess->Dispatch_guess(current_guess->field104_guess,
                (int*)&payload_guess, current_guess->field118_guess,
                &current_guess->field11c_guess, 0, 0);
        }
        current_guess = current_guess->next_guess;
    }
}

// Pushes `node` at the head of the doubly linked list and counts it; null is ignored.
// FUNCTION: TITANIUM 0x004476C9
void LinkList_guess::Push_guess(LinkNode_guess* node_guess) {
    if (node_guess != 0) {
        node_guess->next_guess = head_guess;
        if (head_guess != 0) {
            head_guess->prev_guess = node_guess;
        }
        count_guess++;
        head_guess = node_guess;
    }
}

// Stops and frees every emitter.
// FUNCTION: TITANIUM 0x004476ED
void SoundEmitterList_guess::Reset_guess() {
    SoundEmitter_guess* node_guess = head_guess;
    while (node_guess != 0) {
        head_guess = node_guess;
        node_guess = head_guess->next_guess;
        if (head_guess->field11c_guess != 0) {
            g_dispatchTarget_guess->Stop_guess(head_guess->field11c_guess);
        }
        delete head_guess;
    }
    head_guess = 0;
    count_guess = 0;
}

// Loads emitters from a '^'-separated file (the first line is skipped, probably a header), numbers them
// (+0x108) from the loader's running id, starts them and returns the count.
// FUNCTION: TITANIUM 0x004477AB
int SoundEmitterList_guess::LoadEnvironmentEmitterInstances(char* source_guess) {
    char buffer_guess[0x1000];
    int loaded_guess = 0;
    TextFileReader_guess* reader_guess = 0;
    Reset_guess();
    if (source_guess != 0) {
        CopyRegion_guess(name_guess, source_guess);
        reader_guess = new TextFileReader_guess(source_guess, 0x5e);
        if (reader_guess->IsOpen_guess()) {
            reader_guess->Advance_guess();
            int remaining_guess = reader_guess->Advance_guess();
            while (remaining_guess > 0) {
                reader_guess->Read_guess(buffer_guess, 0x1000);
                SoundEmitter_guess* node_guess = new SoundEmitter_guess;
                if (node_guess != 0) {
                    node_guess = node_guess->Init_guess();
                } else {
                    node_guess = 0;
                }
                node_guess->Parse_guess(buffer_guess);
                node_guess->field108_guess = nextId_guess;
                nextId_guess++;
                ((LinkList_guess*)this)->Push_guess((LinkNode_guess*)node_guess);
                loaded_guess++;
                remaining_guess = reader_guess->Advance_guess();
            }
        }
        delete reader_guess;
    }
    Process_guess();
    return loaded_guess;
}

// AltAbility_guess is one AA ability in the SendAA layout (CopyFrom_guess maps it): +0 id, +0x18 level needed,
// +0x1C cost, +0x20 seq, +0x24 rank, +0x28 prereq ability (negative: a category), +0x2C prereq rank, +0x30
// type, +0x3C reuse timer, +0x40 reuse time, +0x44 class bits, +0x50 previous rank, +0x54 next rank.
// FUNCTION: TITANIUM 0x004478D1
void AltAbility_guess::Reset_guess() {
    field3c_guess |= -1;
    field50_guess |= -1;
    field54_guess |= -1;
    field0_guess = 0;
    field4_guess = 0;
    field8_guess = 0;
    fieldc_guess = 0;
    field10_guess = 0;
    field14_guess = 0;
    field18_guess = 0;
    field1c_guess = 0;
    field20_guess = 0;
    field24_guess = 0;
    field28_guess = 0;
    field2c_guess = 0;
    field30_guess = 0;
    field34_guess = 0;
    field38_guess = 0;
    field40_guess = 0;
    field44_guess = 0;
    field48_guess = 1;
    field58_guess = 0;
    field59_guess = 0;
}

// Whether class `index` (1-16) may use the ability.
// FUNCTION: TITANIUM 0x0044791F
char AltAbility_guess::CanClassUse_guess(int index_guess) {
    if (index_guess <= 0 || index_guess > 16) {
        return 0;
    }
    return (field44_guess & (1 << index_guess)) ? 1 : 0;
}

// AA types 9 and 10, which Check_guess treats apart.
// FUNCTION: TITANIUM 0x00447945
bool AltAbility_guess::IsSpecial_guess() {
    return field30_guess == 9 || field30_guess == 10;
}

// The ability's maximum rank (+0x48); the AA window shows "rank/max" with it.
// FUNCTION: TITANIUM 0x00447959
int Property_guess::GetMaxRank_guess() {
    return value_guess;
}

// Clears +4 and +8 and keeps a heap copy (16 bytes) of `source` as the payload; the payload is null if the
// allocation failed.
// FUNCTION: TITANIUM 0x0044795D
HeapBox_guess* HeapBox_guess::Init_guess(Payload_guess* source_guess) {
    field4_guess = 0;
    field8_guess = 0;
    Payload_guess* copy_guess = (Payload_guess*)operator new(0x10);
    if (copy_guess != 0) {
        *copy_guess = *source_guess;
    } else {
        copy_guess = 0;
    }
    payload_guess = copy_guess;
    return this;
}

// Frees the box's payload and forgets it.
// FUNCTION: TITANIUM 0x0044798E
void HeapBox_guess::Release_guess() {
    if (payload_guess != 0) {
        free(payload_guess);
    }
    payload_guess = 0;
}

// Appends a box for `source_guess` at the tail and makes it current; 0 if the allocation failed.
// FUNCTION: TITANIUM 0x004479A3
char HeapBoxList_guess::Add_guess(Payload_guess* source_guess) {
    HeapBox_guess* box_guess = new HeapBox_guess(source_guess);
    if (box_guess == 0) {
        return 0;
    }
    if (count_guess == 0) {
        head_guess = box_guess;
        tail_guess = box_guess;
        box_guess->field4_guess = 0;
        box_guess->field8_guess = 0;
    } else {
        HeapBox_guess* previous_guess = tail_guess;
        box_guess->field4_guess = previous_guess;
        box_guess->field8_guess = 0;
        previous_guess->field8_guess = box_guess;
        tail_guess = box_guess;
    }
    count_guess++;
    current_guess = box_guess;
    return 1;
}

struct StateCopyDst_guess {
    int field0_guess;
    bool field4_guess;
    char pad5_guess[3];
    int field8_guess;
    int fieldc_guess;
    int field10_guess;
    int field14_guess;
    int field18_guess;
    int field1c_guess;
    int field20_guess;
    int field24_guess;
    int field28_guess;
    int field2c_guess;
    int field30_guess;
    int field34_guess;
    bool field38_guess;
    char pad39_guess[3];
    int field3c_guess;
    int field40_guess;
    int field44_guess;
    int field48_guess;
    int field4c_guess;
    int field50_guess;
    int field54_guess;
    bool field58_guess;
    char pad59_guess[3];
    HeapBoxList_guess list5c_guess;
};

struct StateCopySrc_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    int fieldc_guess;
    int field10_guess;
    int field14_guess;
    int field18_guess;
    int field1c_guess;
    int field20_guess;
    int field24_guess;
    int field28_guess;
    int field2c_guess;
    int field30_guess;
    int field34_guess;
    int field38_guess;
    int field3c_guess;
    int field40_guess;
    int field44_guess;
    int field48_guess;
    int field4c_guess;
    int field50_guess;
    int field54_guess;
    int field58_guess;
    int field5c_guess;
    int field60_guess;
};

// Fills the ability from a SendAA_Struct record (EQEmu titanium_structs.h); fields from +0x38 on are
// reordered, and the 16-byte effect entries go into the list at +0x5C.
// FUNCTION: TITANIUM 0x00447A14
// @early-stop: budget, structural ndiff=19
void AltAbility_guess::CopyFrom_guess(const AltAbility_guess* source_guess, int unused_guess) {
    StateCopyDst_guess* dest_guess = (StateCopyDst_guess*)this;
    const StateCopySrc_guess* source = (const StateCopySrc_guess*)source_guess;
    dest_guess->field0_guess = source->field0_guess;
    dest_guess->field4_guess = source->field4_guess == 1;
    dest_guess->field8_guess = source->field8_guess;
    dest_guess->fieldc_guess = source->fieldc_guess;
    dest_guess->field10_guess = source->field10_guess;
    dest_guess->field14_guess = source->field14_guess;
    dest_guess->field18_guess = source->field18_guess;
    dest_guess->field1c_guess = source->field1c_guess;
    dest_guess->field20_guess = source->field20_guess;
    dest_guess->field24_guess = source->field24_guess;
    dest_guess->field28_guess = source->field28_guess;
    dest_guess->field2c_guess = source->field2c_guess;
    dest_guess->field30_guess = source->field30_guess;
    dest_guess->field34_guess = source->field34_guess;
    dest_guess->field3c_guess = source->field38_guess;
    dest_guess->field40_guess = source->field3c_guess;
    dest_guess->field44_guess = source->field40_guess;
    dest_guess->field48_guess = source->field44_guess;
    dest_guess->field50_guess = source->field48_guess;
    dest_guess->field54_guess = source->field4c_guess;
    dest_guess->field4c_guess = source->field50_guess;
    dest_guess->field38_guess = source->field54_guess != 0;
    dest_guess->field58_guess = source->field58_guess != 0;
    int count_guess = source->field5c_guess;
    if (count_guess > 0) {
        HeapBoxList_guess* list_guess = &dest_guess->list5c_guess;
        const int* entry_guess = &source->field60_guess;
        do {
            Payload_guess local_guess;
            local_guess.first_guess = *entry_guess++;
            local_guess.second_guess = *entry_guess++;
            local_guess.third_guess = *entry_guess++;
            local_guess.fourth_guess = *entry_guess++;
            list_guess->Add_guess(&local_guess);
        } while (--count_guess != 0);
    }
}

// Unlinks and frees the current box; the next box (or the new tail) becomes current. Returns whether the
// removed box held a payload.
// FUNCTION: TITANIUM 0x00447AFD
char HeapBoxList_guess::Remove_guess() {
    if (count_guess == 0) {
        return false;
    }

    HeapBox_guess* item_guess = current_guess;
    HeapBox_guess* next_guess = item_guess->field8_guess;
    if (next_guess == 0 && item_guess->field4_guess == 0) {
        head_guess = 0;
        tail_guess = 0;
        current_guess = 0;
    } else {
        HeapBox_guess* previous_guess = item_guess->field4_guess;
        if (previous_guess == 0) {
            head_guess = next_guess;
            current_guess = current_guess->field8_guess;
            current_guess->field4_guess = 0;
        } else if (next_guess == 0) {
            tail_guess = previous_guess;
            previous_guess->field8_guess = 0;
            current_guess = tail_guess;
        } else {
            previous_guess->field8_guess = next_guess;
            current_guess = current_guess->field8_guess;
            current_guess->field4_guess = item_guess->field4_guess;
        }
    }

    int hasPayload_guess = (int)item_guess->payload_guess;
    item_guess->Release_guess();
    free(item_guess);
    --count_guess;
    return (char)(hasPayload_guess != 0);
}

// Removes every box from the list, starting at the head.
// FUNCTION: TITANIUM 0x00447B7F
void HeapBoxList_guess::Clear_guess() {
    current_guess = head_guess;
    while (count_guess != 0) {
        Remove_guess();
    }
}

// AA ability constructor: empty effect list (+0x5C..+0x68), then every field reset.
// FUNCTION: TITANIUM 0x00447B98
AltAbility_guess* AltAbility_guess::Init_guess() {
    field5c_guess = 0;
    field60_guess = 0;
    field64_guess = 0;
    field68_guess = 0;
    Reset_guess();
    return this;
}

// The ability's reuse time less the reduction from spell effect 0x108 (264, probably hastened AA reuse);
// Allocate_guess is really that effect's total.
// FUNCTION: TITANIUM 0x00447BAE
int __stdcall AltAdvManager_GetCalculatedTimer(BigOwner_guess* owner_guess, Source_guess* source_guess) {
    if (source_guess == 0) {
        return 0;
    }
    int result_guess = source_guess->value40_guess;
    if ((unsigned int)result_guess > 0) {
        int value_guess = source_guess->value20_guess;
        int amount_guess = owner_guess->owner_guess.TotalSpellAffects_guess(0x108, 1, value_guess, 1);
        result_guess = result_guess - amount_guess;
    }
    return result_guess;
}

// Whether the ability's reuse timer (+0x3C, 0-29) is ready; *result gets the seconds left. No timer or no
// reuse time counts as ready.
// FUNCTION: TITANIUM 0x00447BE2
// @early-stop: budget, structural ndiff=24
char Validator_guess::Check_guess(BigOwner_guess* owner_guess, Source_guess* source_guess, int* result_guess) {
    int zero_guess = 0;
    if (owner_guess == (BigOwner_guess*)zero_guess) {
        return false;
    }
    if (source_guess == (Source_guess*)zero_guess) {
        return false;
    }

    unsigned int initial_guess = (unsigned int)AltAdvManager_GetCalculatedTimer(owner_guess, source_guess);
    if (initial_guess <= 0 || source_guess->field3c_guess < zero_guess || source_guess->field3c_guess >= 0x1e) {
        if (result_guess != 0) {
            *result_guess = zero_guess;
        }
        return true;
    }

    int offset_guess = g_query_guess->GetOffset_guess(source_guess->field3c_guess);
    int current_guess = GetCurrent_guess();
    int value_guess = AltAdvManager_GetCalculatedTimer(owner_guess, source_guess);
    if (result_guess != 0) {
        *result_guess = (value_guess - current_guess) + offset_guess;
    }
    return value_guess + offset_guess <= current_guess;
}

// Adds a 12-byte node (key from `source`, the hash, next link) at the front of bucket hash % bucket count,
// counting a newly used bucket and the node. Duplicates are not checked.
// FUNCTION: TITANIUM 0x00447C66
void HashTableC_guess::Insert_guess(const HashChain_guess* source_guess, unsigned int hash_guess) {
    HashChain_guess* node_guess = (HashChain_guess*)operator new(0xc);
    node_guess->key_guess = source_guess->key_guess;
    node_guess->hash_guess = hash_guess;
    unsigned int index_guess = hash_guess % bucketCount_guess;
    HashChain_guess* head_guess = buckets_guess[index_guess];
    if (head_guess == 0) {
        node_guess->next_guess = 0;
        buckets_guess[index_guess] = node_guess;
        usedCount_guess++;
    } else {
        node_guess->next_guess = head_guess;
        buckets_guess[index_guess] = node_guess;
    }
    nodeCount_guess++;
}

// True when the character's profile value +0x1224 (0x004167E2) is 1 or 2; the AA window filters
// ability types 9 and 10 with it.
// FUNCTION: TITANIUM 0x00447CB1
int AltAbility_guess::IsStatusOneOrTwo_guess() {
    if (GetStatus_guess() != 1 && GetStatus_guess() != 2) {
        return false;
    }
    return true;
}

// Adds an AA ability record to the table, keyed by its id (first int); false for null. The AA table
// packet handler fills it.
// FUNCTION: TITANIUM 0x00447CD3
char HashTableOwner_guess::InsertValue_guess(int* value_guess) {
    if (value_guess != 0) {
        table_guess->Insert_guess((const HashChain_guess*)&value_guess, *value_guess);
        return 1;
    }
    return 0;
}

// Removes AA ability `value` from the table (0x0047C339, keyed by its id); the AA window drops
// abilities it cannot list.
// FUNCTION: TITANIUM 0x00447CF2
void AltAdvManager_guess::Apply_guess(int* value_guess) {
    table_guess->Apply_guess(&value_guess, *value_guess);
}

// AltAdvManager_guess is the AA table: an ability by id, or 0.
// FUNCTION: TITANIUM 0x00447D07
int AltAdvManager_guess::GetAltAbility(int key_guess) {
    int* value_guess = table_guess->Find_guess(key_guess);
    int result_guess;
    if (value_guess != 0) {
        result_guess = *value_guess;
    } else {
        result_guess = 0;
    }
    return result_guess;
}

// The player's ability whose seq is `value`, from the 240 AA slots of the profile.
// FUNCTION: TITANIUM 0x00447D1F
int AltAdvManager_guess::FindOwnedBySeq_guess(Query_guess* query_guess, int value_guess) {
    if (query_guess != 0) {
        int index_guess = 0;
        do {
            int key_guess = query_guess->GetEntry_guess(index_guess);
            int result_guess = GetAltAbility(key_guess);
            if (result_guess != 0 && ((ValueEntry_guess*)result_guess)->field20_guess == value_guess) {
                return result_guess;
            }
            ++index_guess;
        } while (index_guess < 0xf0);
    }
    return 0;
}

// An ability's requirement text: prereq -1, -2, -3 are fixed cases (strings 0x88B, 0x88C, 0x23E9), other
// values <= 0 use 0x88F; else the prereq ability is found by seq (ids under 10000) and named by its title
// (0x88D or 0x88E).
// FUNCTION: TITANIUM 0x00447D5B
// @early-stop: budget, structural ndiff=128
void AltAdvManager_guess::GetAbilityReqs_guess(char* destination_guess, char* dataAddress_guess) {
    if (g_query_guess != 0 && dataAddress_guess != 0) {
        int category_guess = ((DescriptionInput_guess*)dataAddress_guess)->value28_guess;
        DescriptionInput_guess* data_guess = (DescriptionInput_guess*)dataAddress_guess;
        if (category_guess == -1) {
            char* format_guess = pStringTable->getString(0x88b, 0);
            sprintf(destination_guess, format_guess);
        } else {
            int message_guess;
            char* first_guess = 0;
            char* second_guess = 0;
            char* third_guess = 0;
            if (category_guess == -2) {
                first_guess = _itoa(data_guess->value18_guess,
                    EQ_ARRAY(char, 0x0099DB00), 10);
                message_guess = 0x88c;
            } else if (category_guess == -3) {
                first_guess = _itoa(data_guess->value2c_guess,
                    EQ_ARRAY(char, 0x0099DB00), 10);
                message_guess = 0x23e9;
            } else if (category_guess <= 0) {
                first_guess = _itoa(data_guess->value18_guess,
                    EQ_ARRAY(char, 0x0099DB00), 10);
                message_guess = 0x88f;
            } else {
                dataAddress_guess = 0;
                int result_guess;
                for (;;) {
                    result_guess = GetAltAbility((int)dataAddress_guess);
                    if (result_guess != 0 &&
                        ((DescriptionResult_guess*)result_guess)->value20_guess == category_guess) {
                        break;
                    }
                    ++dataAddress_guess;
                    if ((int)dataAddress_guess >= 10000) {
                        return;
                    }
                }
                DescriptionResult_guess* found_guess = (DescriptionResult_guess*)result_guess;
                if (data_guess->value30_guess == 3 && found_guess->value30_guess == 1) {
                    second_guess = _itoa(data_guess->value2c_guess,
                        EQ_ARRAY(char, 0x0099DB00), 10);
                    first_guess = g_stringTable_guess->GetString_guess(
                        found_guess->value10_guess, 1, 0);
                    message_guess = 0x88d;
                } else {
                    third_guess = _itoa(data_guess->value2c_guess,
                        EQ_ARRAY(char, 0x0099DAE0), 10);
                    second_guess = g_stringTable_guess->GetString_guess(
                        found_guess->value10_guess, 1, 0);
                    first_guess = _itoa(data_guess->value18_guess,
                        EQ_ARRAY(char, 0x0099DB00), 10);
                    message_guess = 0x88e;
                }
            }
            BuildEventMessage_guess(destination_guess, message_guess,
                first_guess, second_guess, third_guess, 0, 0, 0, 0, 0, 0);
        }
    }
}

// The AA count once the table has arrived; else requests it (OP_SendAATable). That path returns no value
// (kept as decompiled).
// FUNCTION: TITANIUM 0x00447EE9
int ConnectionOwner_guess::Check_guess() {
    if (connection_guess->state_guess > 0) {
        return connection_guess->state_guess;
    }
    SendConnectionMessage_guess(&g_voidConnection_guess, OP_SendAATable, 0, 0, 1);
}

// Whether to list the ability for the player (probably the AA window's filter): right class, and it, its
// previous rank (+0x50) or nothing of its seq is owned. Types 9/10 need status 1 or 2, the rest status 0.
// FUNCTION: TITANIUM 0x00447F0B
char AltAdvManager_guess::Check_guess(QuerySource_guess* source_guess, AltAbility_guess* state_guess) {
    if ((((AltAbility_guess*)&source_guess->data_guess.bytes_guess[
             source_guess->data_guess.holder_guess->vbase_offset])->GetStatus_guess() == 0 &&
         !state_guess->IsSpecial_guess()) ||
        (((StatusCheck_guess*)&source_guess->data_guess.bytes_guess[
             source_guess->data_guess.holder_guess->vbase_offset])->IsStatusOneOrTwo_guess() &&
         state_guess->IsSpecial_guess() &&
         source_guess->ReturnTrue_guess(state_guess->field0_guess))) {
        AltAbility_guess* status_guess = (AltAbility_guess*)&source_guess->data_guess.bytes_guess[
            source_guess->data_guess.holder_guess->vbase_offset];
        LookupResultB_guess* result_guess = ((LookupStatus_guess*)status_guess)->service_guess.GetCharInfo2();
        if (!state_guess->CanClassUse_guess(result_guess->class_119c_guess)) {
            return 0;
        }
        do {
            if (state_guess->field54_guess > 0) {
                int value_guess = state_guess->field24_guess;
                if (value_guess != ((Property48_guess*)state_guess)->GetMaxRank_guess()) {
                    break;
                }
            }
            if (source_guess->ContainsId_guess(state_guess->field0_guess)) {
                return 1;
            }
        } while (0);
        int* entry_guess = (int*)GetAltAbility(state_guess->field50_guess);
        if (entry_guess != 0) {
            if (source_guess->ContainsId_guess(*entry_guess)) {
                return 1;
            }
        } else if (FindOwnedBySeq_guess((Query_guess*)source_guess, state_guess->field20_guess) == 0) {
            return 1;
        }
        if (state_guess->field58_guess != 0 &&
            source_guess->ContainsId_guess(state_guess->field0_guess)) {
            return 1;
        }
    }
    return 0;
}

// Prerequisites: previous rank (+0x50) owned, no other rank of the seq owned, the prereq ability at rank
// +0x2C or more, and for prereq -1 or type 2 at least 6 points spent (+0x4C) on type-1 abilities (12 on
// type 2 for prereq -2 or type 3).
// FUNCTION: TITANIUM 0x00448004
char AltAdvManager_guess::MeetsPrerequisites_guess(Query_guess* query_guess, AltAbility_guess* state_guess) {
    int index_guess = 0;
    if (state_guess != 0 && query_guess != 0 &&
        query_guess->pSpawn_c288_guess != 0 && query_guess->pSpawn_c288_guess->field1a8_guess != 0 &&
        (state_guess->field50_guess <= 0 ||
         query_guess->ContainsId_guess(state_guess->field50_guess))) {
        if (state_guess->field20_guess > 0) {
            ValueEntry_guess* found_guess = (ValueEntry_guess*)
                FindOwnedBySeq_guess(query_guess, state_guess->field20_guess);
            if (found_guess != 0 && found_guess->field0_guess != state_guess->field50_guess) {
                return 0;
            }
        }
        if (state_guess->field28_guess > 0) {
            ValueEntry_guess* entry_guess = 0;
            for (index_guess = 0; ; ++index_guess) {
                if (index_guess >= 0xf0) {
                    return 0;
                }
                entry_guess = (ValueEntry_guess*)
                    GetAltAbility(query_guess->GetEntry_guess(index_guess));
                if (entry_guess != 0 && entry_guess->field20_guess == state_guess->field28_guess) {
                    break;
                }
            }
            if (entry_guess->field24_guess < state_guess->field2c_guess) {
                return 0;
            }
        }
        if (state_guess->field28_guess == -1 || state_guess->field30_guess == 2) {
            int total_guess = 0;
            for (index_guess = 0; index_guess < 0xf0; ++index_guess) {
                ValueEntry_guess* entry_guess = (ValueEntry_guess*)
                    GetAltAbility(query_guess->GetEntry_guess(index_guess));
                if (entry_guess != 0 && entry_guess->field30_guess == 1) {
                    total_guess += entry_guess->field4c_guess;
                }
            }
            if (total_guess < 6) {
                return 0;
            }
        }
        if (state_guess->field28_guess == -2 || state_guess->field30_guess == 3) {
            int total_guess = 0;
            for (index_guess = 0; index_guess < 0xf0; ++index_guess) {
                ValueEntry_guess* entry_guess = (ValueEntry_guess*)
                    GetAltAbility(query_guess->GetEntry_guess(index_guess));
                if (entry_guess != 0 && entry_guess->field30_guess == 2) {
                    total_guess += entry_guess->field4c_guess;
                }
            }
            if (total_guess < 0xc) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// Whether the ability can be bought now (tu_098 calls it CanTrain): not owned, unspent points for the cost,
// level, class, `flag` for +0x58 abilities, MeetsPrerequisites_guess, and types 6, 7 and 11 need bits 0x40, 0x80
// and 0x200 of the flags at +0xC38C (probably expansions). Types outside 1-11 never pass.
// FUNCTION: TITANIUM 0x00448122
char AltAdvManager_guess::CanPurchase_guess(Query_guess* query_guess, AltAbility_guess* state_guess, char flag_guess) {
    if (state_guess != 0 && query_guess != 0 && query_guess->pSpawn_c288_guess != 0 &&
        query_guess->pSpawn_c288_guess->field1a8_guess != 0 &&
        !query_guess->ContainsId_guess(state_guess->field0_guess)) {
        int limit_guess = state_guess->field1c_guess;
        if (query_guess->GetLimit_guess() >= limit_guess) {
            AltAbility_guess* status_guess = (AltAbility_guess*)&query_guess->data_guess.bytes_guess[
                query_guess->data_guess.holder_guess->vbase_offset];
            if (((LookupStatus_guess*)status_guess)->service_guess.GetCharInfo2()->level_11a4_guess >= state_guess->field18_guess &&
                (!state_guess->IsSpecial_guess() || ((StatusCheck_guess*)&query_guess->data_guess.bytes_guess[
                    query_guess->data_guess.holder_guess->vbase_offset])->IsStatusOneOrTwo_guess())) {
                AltAbility_guess* test_guess = (AltAbility_guess*)&query_guess->data_guess.bytes_guess[
                    query_guess->data_guess.holder_guess->vbase_offset];
                if (state_guess->CanClassUse_guess(((LookupStatus_guess*)test_guess)->service_guess.GetCharInfo2()->class_119c_guess) &&
                    (state_guess->field58_guess == 0 || flag_guess != 0) &&
                    MeetsPrerequisites_guess(query_guess, state_guess)) {
                    int kind_guess = state_guess->field30_guess;
                    if (kind_guess < 12 && kind_guess > 0 &&
                        (kind_guess != 6 || (query_guess->stateFlags_guess[query_guess->part_guess->field4_guess] & 0x40)) &&
                        (kind_guess != 7 || (query_guess->stateFlags_guess[query_guess->part_guess->field4_guess] & 0x80)) &&
                        (kind_guess != 11 || (query_guess->stateFlags_guess[query_guess->part_guess->field4_guess + 1] & 2))) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// Frees the ability's effect list (+0x5C).
// FUNCTION: TITANIUM 0x00448263
void HeapBoxListOwner_guess::Clear_guess() {
    list_guess.Clear_guess();
}

// Frees every ability record in the table.
// FUNCTION: TITANIUM 0x0044826B
void HeapBoxArrayOwner_guess::Cleanup_guess() {
    int* slot_guess = (int*)view_guess->FirstNonZero_guess();
    if (slot_guess != 0) {
        do {
            HeapBoxArrayEntry_guess* owner_guess = (HeapBoxArrayEntry_guess*)*slot_guess;
            if (owner_guess == 0) {
                break;
            }
            int* next_guess = view_guess->Remove_guess(slot_guess);
            owner_guess->Clear_guess();
            free(owner_guess);
            slot_guess = next_guess;
        } while (slot_guess != 0);
    }
    view_guess->Finish_guess();
}


