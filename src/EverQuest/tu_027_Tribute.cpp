// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 27: a hint from compare/tumap.py.
// Tribute, personal and guild: tribute master messages, item and platinum donations, the active
// tributes and their upkeep; then the database strings (dbstr) loader. g_candidate_guess is pCharData;
// g_messageState_guess and g_pendingId_guess (0x905D10) hold the open tribute master's spawn. LookupState_,
// SlotManager_, CooldownState_, LookupOwner_ and MessageRouter_guess are views of the tribute manager.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include <new>

struct GuildMemberEntry_guess {
    unsigned char pad_guess[0x264];
    unsigned char enabled_guess;
    unsigned int firstValue_guess;
    unsigned int secondValue_guess;
    unsigned char finalFlag_guess;

    void Set_guess(unsigned char enabled_guess, unsigned int firstValue_guess,
                   unsigned int secondValue_guess, unsigned char finalFlag_guess);
};

struct ClearState_guess {
    unsigned int firstHeader_guess;
    unsigned int secondHeader_guess;
    unsigned int thirdHeader_guess;
    unsigned int fourthHeader_guess;
    unsigned int firstValues_guess[10];
    unsigned int secondValues_guess[10];
    unsigned int thirdValues_guess[10];
    ClearState_guess* Clear_guess();
};

struct ValueStorage_guess {
    unsigned int pad_guess[35]; // 0x00..0x8B
    unsigned int values_guess[5]; // 0x8C

    void SetTributeItem_guess(unsigned int index_guess, unsigned int value_guess);
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    ValueStorage_guess *GetCharInfo2();
};

struct HolderEntry_guess;

struct Holder_guess {
    int pad_guess;
    EQ_CharacterProfileView_guess root_guess; // 0x04

    // EXTERNAL: TITANIUM 0x0040CC50 Holder_guess::Lookup_guess
    void *Lookup_guess(int index_guess);
    unsigned int *GetSlot_guess(unsigned int index_guess);
    void SetTributeItem_guess(unsigned int index_guess, unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x0040CC6B Holder_guess::GetSmallEntry_guess
    HolderEntry_guess *GetSmallEntry_guess(unsigned int index_guess);
};

struct Head_guess {
    unsigned int first_guess;
    unsigned int second_guess;
};

struct Owner_guess : Head_guess, virtual Holder_guess {
};

struct ParameterizedState_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int third_guess;
    unsigned int fourth_guess;

    // EXTERNAL: TITANIUM 0x00490C98 ParameterizedState_guess::Initialize_guess
    void Initialize_guess(unsigned int value_guess);
    ParameterizedState_guess* Reset_guess(unsigned int value_guess);
};

struct EmbeddedState_guess {
    unsigned char pad_guess[0x1c];
    unsigned char firstFlag_guess;
    unsigned char middlePad_guess[7];
    unsigned char state_guess;
    unsigned char active_guess;
    unsigned char tailPad_guess[2];

    // EXTERNAL: TITANIUM 0x0047C3AF EmbeddedState_guess::Initialize_guess
    void Initialize_guess(unsigned int size_guess);
};

struct CombinedState_guess {
    EmbeddedState_guess first_guess;
    EmbeddedState_guess second_guess;

    CombinedState_guess* Initialize_guess();
};

struct TributeTable_guess {
    int count_guess;
    unsigned int pad_guess;
    int mask_guess;
    unsigned int shift_guess;
    unsigned int **pages_guess;
    unsigned char pad2_guess[0xc]; // 0x14..0x1f
    int total_guess; // 0x20
    unsigned char flag_guess; // 0x24
    unsigned char active_guess; // 0x25

    // EXTERNAL: TITANIUM 0x004B73EE TributeTable_guess::~TributeTable_guess
    ~TributeTable_guess();

    unsigned int Lookup_guess(int index_guess);
    int GetUpkeep_guess();
    void UpdateUpkeep_guess();
    void RequestTributeDescription_guess(int message_guess, int index_guess);
    void HandleTributeMessage_guess(int message_guess, int *data_guess);
    void AddActiveTribute_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040600C TributeTable_guess::SetElementIdx_guess
    void SetElementIdx_guess(int index_guess, int *value_guess);
};

struct PairLookupState_guess {
    TributeTable_guess first_guess;
    TributeTable_guess second_guess;

    ~PairLookupState_guess();
};

struct OffsetLookupState_guess {
    unsigned int pad_guess[10];
    int count_guess;
    unsigned int pad2_guess;
    unsigned int mask_guess;
    unsigned int shift_guess;
    unsigned int **pages_guess;

    unsigned int Lookup_guess(int index_guess);
    void RequestGuildTributeDescription_guess(int message_guess, int index_guess);
};

#include "titanium/layouts/core.h"
#include "titanium/wnd/CContainerMgr.h"

struct CandidatePart_guess {
    int unused_guess;
    int index_guess; // 0x04
};

struct CandidateSlot_guess {
    int id_guess;
    int index_guess;
};

struct Thing_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 Thing_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Thing_guess::Has_guess
    int Has_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC650 Thing_guess::Slot_guess
    unsigned int *Slot_guess(int index_guess);
};

struct CandidateSub_guess {
    // EXTERNAL: TITANIUM 0x0041DE16 CandidateSub_guess::GetItemBySlot_guess
    Thing_guess *GetItemBySlot_guess(unsigned int value_guess);
};

struct Candidate_guess {
    unsigned char pad_0000_guess[0x08];
    union {
        VBTable *holder_guess; // 0x08
        unsigned char embedded_guess[0xc280 - 0x08];
        struct {
            unsigned char pad_e70_guess[0xe70 - 0x08];
            int field_e70_guess;
            int field_e74_guess;
            int field_e78_guess;
            int field_e7c_guess;
            int field_e80_guess;
            int field_e84_guess;
            unsigned char pad_c280_guess[0xc280 - 0xe88];
        } fields_guess;
    };
    CandidateSub_guess sub_guess; // 0xc280
    unsigned char pad_c281_guess[3];
    CandidatePart_guess *part_guess; // 0xc284
    unsigned char pad_c288_guess[4];
    unsigned char flagA_guess; // 0xc28c
    unsigned char pad_c28d_guess[0xc348 - 0xc28d];
    unsigned char flagB_guess; // 0xc348
    unsigned char pad_c349_guess[0x43];
    unsigned char stateFlags_guess[1]; // 0xc38c

    // EXTERNAL: TITANIUM 0x005F0D80 Candidate_guess::GetSlot_guess
    CandidateSlot_guess *GetSlot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005F0E20 Candidate_guess::Refresh_guess
    void Refresh_guess(int index_guess, int flag_guess);
};

struct RecordData_guess {
    unsigned char pad_guess[0xc];
    int count_guess; // 0x0c
    unsigned char pad2_guess[0x28];
    unsigned int values_guess[1]; // 0x38
};

struct StringData_guess {
    // EXTERNAL: TITANIUM 0x00572300 StringData_guess::GetText_guess
    char *GetText_guess();
};

union SendData_guess {
    char bytes_guess[12];
    int words_guess[3];
};

union SendDataWide_guess {
    char bytes_guess[16];
    int words_guess[4];
};

struct LookupResult_guess {
    unsigned char pad_guess[0x11d4];
    int value_guess; // 0x11d4
};

struct LookupService_guess {
    int unused_guess;

    // EXTERNAL: TITANIUM 0x005EC220 LookupService_guess::GetCharInfo2
    LookupResult_guess *GetCharInfo2();
};

struct LookupStatus_guess {
    int unused_guess;
    LookupService_guess service_guess; // 0x04

    // EXTERNAL: TITANIUM 0x004167E2 LookupStatus_guess::GetStatus_guess
    int GetStatus_guess();
    // EXTERNAL: TITANIUM 0x00417CF2 LookupStatus_guess::AddValue_guess
    void AddValue_guess(int value_guess);
};

struct SelectionTable_guess {
    // EXTERNAL: TITANIUM 0x0040AA28 SelectionTable_guess::Get_guess
    GuildMemberEntry_guess *Get_guess(const unsigned int *key_guess);
    // EXTERNAL: TITANIUM 0x0040AB01 SelectionTable_guess::Find_guess
    int Find_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040B27A SelectionTable_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x0040AB20 SelectionTable_guess::SpendGuildFavor_guess
    void SpendGuildFavor_guess(int value_guess);
};

struct Notifier_guess {
    unsigned char pad_guess[0x1dc];
    unsigned char pending_guess;

    // EXTERNAL: TITANIUM 0x005117C3 Notifier_guess::SetFlag_guess
    void SetFlag_guess();
    // EXTERNAL: TITANIUM 0x005117CB Notifier_guess::Commit_guess
    void Commit_guess();
    // EXTERNAL: TITANIUM 0x00511A96 Notifier_guess::Notify_guess
    void Notify_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00511AF8 Notifier_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x0051208F Notifier_guess::Begin_guess
    void Begin_guess();
    void FinishPending_guess()
    {
        pending_guess = 1;
        Finish_guess();
    }
    void ClearPending_guess()
    {
        pending_guess = 0;
        Finish_guess();
    }
};

struct NotifierAlt_guess {
    // EXTERNAL: TITANIUM 0x0056CE7C NotifierAlt_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00511A96 NotifierAlt_guess::Notify_guess
    void Notify_guess(int first_guess, int second_guess);
};

struct Sink_guess {
    // EXTERNAL: TITANIUM 0x0056BB49 Sink_guess::MarkDirty_guess
    void MarkDirty_guess();
    // EXTERNAL: TITANIUM 0x0056C185 Sink_guess::MethodA_guess
    void MethodA_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0056C1DB Sink_guess::MethodB_guess
    void MethodB_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0056BB51 Sink_guess::MarkClean_guess
    void MarkClean_guess();
};

struct CooldownOwner_guess {
    unsigned char pad_guess[0xe70];
    int value_guess; // 0xe70
};

struct CooldownState_guess {
    unsigned char pad_guess[0x20];
    int count_guess;            // 0x20
    unsigned char pad2_guess;   // 0x24
    unsigned char active_guess; // 0x25

    void TickTributeTimers_guess(CooldownOwner_guess* owner_guess, int amount_guess);
};

struct Str8_guess {
    unsigned int first_guess;
    unsigned int second_guess;

    Str8_guess() { first_guess = 0; second_guess = 0; }
    // EXTERNAL: TITANIUM 0x00571FC0 Str8_guess::Set_guess
    void Set_guess(const char* text_guess);
};

struct Record_guess {
    int id_guess;                   // 0x00
    Str8_guess name_guess;         // 0x04
    unsigned int value_guess;      // 0x0c
    unsigned int first_guess[10];  // 0x10
    unsigned int cost_guess[10]; // 0x38
    unsigned int itemId_guess[10];  // 0x60

    Record_guess();
};

struct RecordReader_guess {
    void Read_guess(const unsigned char* input_guess, Record_guess* record_guess);
};

struct Dispatch_guess {
    void ShowTributeDescription_guess(int type_guess, int first_guess, int second_guess);
};

struct MessageRouter_guess : Dispatch_guess {
    unsigned char pad_guess[0x28];
    TributeTable_guess table_guess;

    void OnPlatinumDonated_guess(int unused_guess, int *data_guess, int message_guess);
    void OnItemDonated_guess(Owner_guess *owner_guess, int *data_guess, unsigned int message_guess);
    void HandleGuildTributeMessage_guess(int message_guess, unsigned int *data_guess);
};

struct SlotEntry_guess {
    int value_guess; // 0x00
    int count_guess; // 0x04
};

struct MessageSource_guess {
    unsigned char pad_guess[0x288];
    int value_guess; // 0x288
};

struct Pending_guess {
    unsigned char pad_guess[0x1d4];
    unsigned char flag_guess; // 0x1d4

    // EXTERNAL: TITANIUM 0x0056D2E7 Pending_guess::UpdateDonateButton_guess
    void UpdateDonateButton_guess();
    // EXTERNAL: TITANIUM 0x0056D8CF Pending_guess::ClearDonation_guess
    void ClearDonation_guess();
    void ClearPending_guess()
    {
        flag_guess = 0;
        UpdateDonateButton_guess();
    }
};

struct Sender_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 Sender_guess::Store_guess
    char *Store_guess(const char *text_guess);
    // EXTERNAL: TITANIUM 0x004982C6 Sender_guess::dsp_chat
    void dsp_chat(const char* text_guess, int id_guess, bool flag_guess);
};

struct HolderEntry_guess {
    virtual ~HolderEntry_guess();
};

struct PendingVirtual_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual void Slot1C_guess();
    virtual void Slot20_guess();
    virtual void Slot24_guess();
    virtual void Slot28_guess();
    virtual void Slot2C_guess();
    virtual void Slot30_guess();
    virtual void Slot34_guess();
    virtual void Slot38_guess();
    virtual void Slot3C_guess();
    virtual void Slot40_guess();
    virtual void Slot44_guess();
    virtual void Slot48_guess();
    virtual void Slot4C_guess();
    virtual void Slot50_guess();
    virtual void Slot54_guess();
    virtual void Slot58_guess();
    virtual void Slot5C_guess();
    virtual void Slot60_guess();
    virtual void Slot64_guess();
    virtual void Slot68_guess();
    virtual void Slot6C_guess();
    virtual void Slot70_guess();
    virtual void Slot74_guess();
    virtual void Slot78_guess();
    virtual void Slot7C_guess();
    virtual void Slot80_guess();
    virtual void Slot84_guess();
    virtual void Slot88_guess();
    virtual void Slot8C_guess();
    virtual void Slot90_guess();
    virtual void Slot94_guess();
    virtual void Slot98_guess();
    virtual void Slot9C_guess();
    virtual void SlotA0_guess();
    virtual void SlotA4_guess();
    virtual void SlotA8_guess();
    virtual void SlotAC_guess();
    virtual void SlotB0_guess();
    virtual void SlotB4_guess();
    virtual void SlotB8_guess();
    virtual void SlotBC_guess();
    virtual int SlotC0_guess(int first_guess, int second_guess);
};

struct StringRecord_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    CXStr value_guess;
};

#define g_selectionTable_guess EQ_GLOBAL(SelectionTable_guess, 0x00905D38)
#define g_slots_guess EQ_ARRAY(SlotEntry_guess, 0x0091D6D8)
#define g_dirty_guess EQ_GLOBAL(unsigned char, 0x0091D6EC)
#define pinstCGuildTributeMasterWnd_guess EQ_GLOBAL(Notifier_guess*, 0x00991AC8)
#define g_candidate_guess EQ_GLOBAL(Candidate_guess *, 0x00905D00)
#define g_flagA_guess EQ_GLOBAL(int, 0x009247A8)
#define g_flagB_guess EQ_GLOBAL(int, 0x009247AC)
// The tribute master the window talks to (0x905D10).
#define g_tributeMaster_guess EQ_GLOBAL(EQPlayer*, 0x00905D10)
#define g_messageSource_guess EQ_GLOBAL(MessageSource_guess *, 0x00905CE4)
#define g_pending_guess EQ_GLOBAL(Pending_guess *, 0x009929A8)
#define g_enabled_guess EQ_GLOBAL(unsigned char, 0x0091D6ED)
#define pinstCTributeBenefitWnd_guess EQ_GLOBAL(Sink_guess*, 0x0099298C)
#define g_notifier2_guess EQ_GLOBAL(NotifierAlt_guess *, 0x009929A8)
#define g_sender_guess EQ_GLOBAL(Sender_guess *, 0x00988DF0)

#define g_resetFlag_guess EQ_GLOBAL(int, 0x009248D4)
#define g_lookupOwner_guess EQ_GLOBAL(LookupOwner_guess, 0x00850350)

struct LookupOwner_guess {
    void LowerGuildTributeTier_guess(int value_guess);
    void AddGuildTribute_guess(int value_guess);
    int IsTributeAvailable_guess();
    void DonateTributePlatinum_guess(int value_guess);
    int Check_guess();
    void DonateGuildTributePlatinum_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

struct SlotManager_guess {
    unsigned char pad_guess[0x24];
    unsigned char dirty_guess;

    void LowerTributeTier_guess(int value_guess);
};

struct Entry_guess {
    virtual void Slot00_guess(int value_guess);
    unsigned char pad_guess[0x44];
    int field48_guess; // 0x48

    // EXTERNAL: TITANIUM 0x005EC760 Entry_guess::IsStackable_guess
    unsigned char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Entry_guess::GetText_guess
    char *GetText_guess();
    // EXTERNAL: TITANIUM 0x005ECD80 Entry_guess::SetStackCount_guess
    void SetStackCount_guess(int amount_guess);
};

// Reads a big-endian 32-bit value from `bytes`.
// FUNCTION: TITANIUM 0x00433D68
unsigned int __cdecl ReadBigEndianUInt32_guess(const unsigned char* bytes_guess)
{
    return ((unsigned int)bytes_guess[0] << 24) |
           ((unsigned int)bytes_guess[1] << 16) |
           ((unsigned int)bytes_guess[2] << 8) |
           (unsigned int)bytes_guess[3];
}

struct OwnedValue_guess {
    void* value_guess; // 0x00

    // EXTERNAL: TITANIUM 0x004482FB OwnedValue_guess::~OwnedValue_guess
    ~OwnedValue_guess();
};

struct OwnedPair_guess {
    unsigned int pad_guess;        // 0x00
    OwnedValue_guess first_guess;  // 0x04
    OwnedValue_guess second_guess; // 0x08

    ~OwnedPair_guess();
};

// Destructor: releases the two owned pointers at +8 and +4 (0x004482FB).
// FUNCTION: TITANIUM 0x00433D86
OwnedPair_guess::~OwnedPair_guess()
{
}

// A guild member's tribute flags, from OP_GuildOptInOut (GuildMemberEntry_guess is a view of a guild member
// entry).
// FUNCTION: TITANIUM 0x00433DBC
void GuildMemberEntry_guess::Set_guess(unsigned char enabled_guess, unsigned int firstValue_guess,
                                unsigned int secondValue_guess, unsigned char finalFlag_guess)
{
    this->enabled_guess = enabled_guess;
    this->firstValue_guess = firstValue_guess;
    this->secondValue_guess = secondValue_guess;
    this->finalFlag_guess = finalFlag_guess;
}

// One tribute: id, name, tier count, and per tier (10) the level, cost (second_guess) and item id
// (third_guess); see Read_guess.
// FUNCTION: TITANIUM 0x00433DE7
Record_guess::Record_guess()
{
    id_guess = 0;
    value_guess = 0;
    for (int i_guess = 0; i_guess < 10; ++i_guess) {
        first_guess[i_guess] = 0;
        cost_guess[i_guess] = 0;
        itemId_guess[i_guess] = 0;
    }
}

struct Link_guess {
    unsigned char pad_guess[0x1c];
    unsigned char sentA_guess;   // 0x1c
    unsigned char pad2_guess[7];
    unsigned char ready_guess;   // 0x24
    unsigned char pad3_guess[0x1f];
    unsigned char sentB_guess;   // 0x44

    void RequestTributeLists_guess();
};

// Asks for both tribute lists once (OP_SendTributes, OP_RequestGuildTributes) and refreshes the tribute
// windows.
// FUNCTION: TITANIUM 0x00433E0D
void Link_guess::RequestTributeLists_guess()
{
    int data_guess;
    ready_guess = 1;
    if (g_sender_guess != 0) {
        if (sentA_guess == 0) {
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_SendTributes, &data_guess, 4, 1);
            sentA_guess = 1;
        }
        if (g_sender_guess != 0 && sentB_guess == 0) {
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_RequestGuildTributes, &data_guess, 4, 1);
            sentB_guess = 1;
        }
    }
    if (pinstCTributeBenefitWnd_guess != 0) {
        pinstCTributeBenefitWnd_guess->MarkDirty_guess();
        pinstCTributeBenefitWnd_guess->MarkClean_guess();
    }
    if (g_notifier2_guess != 0)
        g_notifier2_guess->Refresh_guess();
    if (pinstCGuildTributeMasterWnd_guess != 0)
        pinstCGuildTributeMasterWnd_guess->SetFlag_guess();
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x0046DA4A BuildText_guess
void __cdecl BuildText_guess(char* output_guess, unsigned int id_guess, const char* arg_guess, ...);

// Donates the item in inventory slot `first_guess` (count `second_guess`) to the open tribute master with
// OP_TributeItem (slot, count, master spawn id). A bag must be empty: otherwise string 0xD38 with the
// master's name. The loop that would send the bag's contents (bag slots 31 + 10*slot + n) is therefore
// never reached; it is kept as compiled.
// FUNCTION: TITANIUM 0x00433EAC
void __stdcall SendTributeItem_guess(int first_guess, unsigned int second_guess)
{
    char buf1_guess[256];
    char buf2_guess[256];
    Thing_guess *thing_guess = g_candidate_guess->sub_guess.GetItemBySlot_guess(first_guess);
    if (g_tributeMaster_guess != 0 && thing_guess != 0) {
        if (thing_guess->GetItemClass_guess() == 1) {
            for (int i_guess = 0; i_guess < 10; ++i_guess) {
                if (thing_guess->Has_guess(i_guess) != 0) {
                    strcpy(buf2_guess, pStringTable->getString(0xd33, 0));
                    if (g_tributeMaster_guess != 0)
                        strcpy(buf2_guess, g_sender_guess->Store_guess(g_tributeMaster_guess->Name));
                    BuildText_guess(buf1_guess, 0xd38, buf2_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    g_sender_guess->dsp_chat(buf1_guess, 0x113, 1);
                    return;
                }
            }
            pinstCContainerMgr_guess->CloseContainer_guess(thing_guess, 1);
            for (int i_guess = 0; i_guess < 10; ++i_guess) {
                Entry_guess *entry_guess = (Entry_guess *)thing_guess->Has_guess(i_guess);
                if (entry_guess != 0) {
                    int msg_guess[4];
                    msg_guess[0] = i_guess + 0x1f + first_guess * 10;
                    msg_guess[1] = 1;
                    if (entry_guess->IsStackable_guess())
                        msg_guess[1] = entry_guess->field48_guess;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_TributeItem, msg_guess, 0x10, 1);
                    if (g_pending_guess != 0) {
                        Pending_guess *pending_guess = g_pending_guess;
                        pending_guess->flag_guess = 1;
                        pending_guess->UpdateDonateButton_guess();
                    }
                }
            }
        }
        int data_guess[4];
        data_guess[2] = g_tributeMaster_guess->SpawnID;
        data_guess[0] = first_guess;
        data_guess[1] = second_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_TributeItem, data_guess, 0x10, 1);
        if (g_pending_guess != 0) {
            Pending_guess *pending_guess = g_pending_guess;
            pending_guess->flag_guess = 1;
            pending_guess->UpdateDonateButton_guess();
        }
    }
}

// Lowers active tribute `value`'s tier by one; below tier 0 its slot is freed. `this` is the tribute table
// (+0x24 is its dirty flag).
// FUNCTION: TITANIUM 0x00434096
void SlotManager_guess::LowerTributeTier_guess(int value_guess)
{
    int index_guess = 0;
    do {
        if (g_candidate_guess->GetSlot_guess(index_guess)->id_guess == value_guess) {
            --g_candidate_guess->GetSlot_guess(index_guess)->index_guess;
            if (g_candidate_guess->GetSlot_guess(index_guess)->index_guess < 0)
                g_candidate_guess->GetSlot_guess(index_guess)->id_guess = -1;
            break;
        }
        ++index_guess;
    } while (index_guess < 5);
    dirty_guess = 1;
    if (pinstCTributeBenefitWnd_guess != 0)
        pinstCTributeBenefitWnd_guess->MarkDirty_guess();
    if (g_notifier2_guess != 0)
        g_notifier2_guess->Refresh_guess();
}

// Timer tick of `amount`: passes it to 0x905D38 (probably the guild member list) while guild tribute
// is on (0x91D6ED), and counts the tribute timer (pCharData +0xE70, from OP_TributeTimer) down while
// personal tribute is on (+0x25) and costs something (+0x20, the upkeep).
// FUNCTION: TITANIUM 0x00434111
void CooldownState_guess::TickTributeTimers_guess(CooldownOwner_guess* owner_guess, int amount_guess)
{
    SelectionTable_guess* table_guess = &g_selectionTable_guess;
    if (table_guess->Count_guess() > 0 && g_enabled_guess != 0)
        table_guess->SpendGuildFavor_guess(amount_guess);
    if (this->count_guess > 0 && this->active_guess != 0) {
        int* value_guess = &owner_guess->value_guess;
        *value_guess -= amount_guess;
        if (*value_guess < 0)
            *value_guess = 0;
    }
}

// Shows a tribute description in the window that asked for it, by the code it put in the request:
// 0 and 2 the window 0x99298C (two methods), 1 the window 0x9929A8, 3 the window 0x991AC8.
// FUNCTION: TITANIUM 0x0043415D
void Dispatch_guess::ShowTributeDescription_guess(int type_guess, int first_guess, int second_guess)
{
    switch (type_guess) {
    case 0:
        if (pinstCTributeBenefitWnd_guess != 0)
            pinstCTributeBenefitWnd_guess->MethodA_guess(first_guess, second_guess);
        break;
    case 1:
        if (g_notifier2_guess != 0)
            g_notifier2_guess->Notify_guess(first_guess, second_guess);
        break;
    case 2:
        if (pinstCTributeBenefitWnd_guess != 0)
            pinstCTributeBenefitWnd_guess->MethodB_guess(first_guess, second_guess);
        break;
    case 3:
        if (pinstCGuildTributeMasterWnd_guess != 0)
            pinstCGuildTributeMasterWnd_guess->Notify_guess(first_guess, second_guess);
        break;
    }
}

// Unpacks a tribute record (OP_TributeInfo and the guild twin 0x5E3D), every word big-endian: id, tier
// count, 10 x (level, item id, cost), then the name. The item id goes to third_guess, the cost to
// second_guess.
// FUNCTION: TITANIUM 0x004341CF
void RecordReader_guess::Read_guess(const unsigned char* input_guess, Record_guess* record_guess)
{
    record_guess->id_guess = ReadBigEndianUInt32_guess(input_guess);
    const unsigned char* p_guess = input_guess + 4;
    record_guess->value_guess = ReadBigEndianUInt32_guess(p_guess);
    p_guess += 4;
    for (int i_guess = 0; i_guess < 10; ++i_guess) {
        record_guess->first_guess[i_guess] = ReadBigEndianUInt32_guess(p_guess);
        p_guess += 4;
        record_guess->itemId_guess[i_guess] = ReadBigEndianUInt32_guess(p_guess);
        p_guess += 4;
        record_guess->cost_guess[i_guess] = ReadBigEndianUInt32_guess(p_guess);
        p_guess += 4;
    }
    record_guess->name_guess.Set_guess((const char*)p_guess);
}

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
unsigned int __cdecl FUN_00401b28_guess(unsigned int index_guess);

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

#define g_digits_guess EQ_ARRAY(char, 0x0099DB00)

struct ResolvedEntry_guess {
    unsigned char pad_guess[0x120];
    char text_guess[1]; // 0x120
};

// Guild twin of SendTributeItem_guess, with the same empty-bag rule: OP_GuildTributeDonateItem (slot,
// count, master spawn id, word 4 the player's GuildID +0x288).
// FUNCTION: TITANIUM 0x0043423C
void __stdcall SendGuildTributeDonateItem_guess(unsigned int first_guess, unsigned int second_guess)
{
    int msg_guess[7];
    char buf1_guess[256];
    char buf2_guess[256];
    Thing_guess *thing_guess = g_candidate_guess->sub_guess.GetItemBySlot_guess(first_guess);
    if (g_tributeMaster_guess != 0 && thing_guess != 0) {
        if (thing_guess->GetItemClass_guess() == 1) {
            for (int i_guess = 0; i_guess < 10; ++i_guess) {
                if (thing_guess->Has_guess(i_guess) != 0) {
                    strcpy(buf2_guess, pStringTable->getString(0xd33, 0));
                    if (g_tributeMaster_guess != 0)
                        strcpy(buf2_guess, g_sender_guess->Store_guess(g_tributeMaster_guess->Name));
                    BuildText_guess(buf1_guess, 0xd38, buf2_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    g_sender_guess->dsp_chat(buf1_guess, 0x113, 1);
                    return;
                }
            }
            pinstCContainerMgr_guess->CloseContainer_guess(thing_guess, 1);
        }
        msg_guess[2] = g_tributeMaster_guess->SpawnID;
        msg_guess[0] = first_guess;
        msg_guess[1] = second_guess;
        msg_guess[4] = g_messageSource_guess->value_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildTributeDonateItem, msg_guess, 0x1c, 1);
        if (pinstCGuildTributeMasterWnd_guess != 0)
            pinstCGuildTributeMasterWnd_guess->FinishPending_guess();
    }
}

// Lowers guild tribute `value` one tier in the two guild slots (0x91D6D8); at tier 0 the slot is freed.
// FUNCTION: TITANIUM 0x004343B4
void LookupOwner_guess::LowerGuildTributeTier_guess(int value_guess)
{
    int index_guess = g_selectionTable_guess.Find_guess(value_guess);
    if (index_guess != -1) {
        SlotEntry_guess oldEntry_guess = g_slots_guess[index_guess];
        if (oldEntry_guess.count_guess == 0) {
            g_slots_guess[index_guess].value_guess = -1;
            g_slots_guess[index_guess].count_guess = 0;
        } else {
            g_slots_guess[index_guess].value_guess = value_guess;
            g_slots_guess[index_guess].count_guess = oldEntry_guess.count_guess - 1;
        }
        g_dirty_guess = 1;
        if (pinstCGuildTributeMasterWnd_guess != 0)
            pinstCGuildTributeMasterWnd_guess->SetFlag_guess();
    }
}

// Adds guild tribute `value` at tier 0 to the first free one of the two guild slots, or raises it a tier
// when already there.
// FUNCTION: TITANIUM 0x0043441A
void LookupOwner_guess::AddGuildTribute_guess(int value_guess)
{
    int index_guess = g_selectionTable_guess.Find_guess(value_guess);
    if (index_guess == -1) {
        index_guess = 0;
        for (; index_guess < 2; ++index_guess) {
            if (g_slots_guess[index_guess].value_guess == -1) {
                if (index_guess != -1) {
                    g_slots_guess[index_guess].count_guess = 0;
                    g_slots_guess[index_guess].value_guess = value_guess;
                    g_dirty_guess = 1;
                }
                break;
            }
        }
    } else {
        SlotEntry_guess oldEntry_guess = g_slots_guess[index_guess];
        g_slots_guess[index_guess].value_guess = value_guess;
        g_slots_guess[index_guess].count_guess = oldEntry_guess.count_guess + 1;
        g_dirty_guess = 1;
    }
    if (pinstCGuildTributeMasterWnd_guess != 0)
        pinstCGuildTributeMasterWnd_guess->SetFlag_guess();
}

// Whether tribute is available: the character's expansion bits (pCharData +0xC38C, probably) include
// 0x40 or 0x80 and GetStatus_guess is 0; before pCharData exists, either flag 0x9247A8 or 0x9247AC.
// FUNCTION: TITANIUM 0x00434495
int LookupOwner_guess::IsTributeAvailable_guess()
{
    Candidate_guess *candidate_guess = g_candidate_guess;
    if (candidate_guess != 0) {
        if (((candidate_guess->stateFlags_guess[candidate_guess->part_guess->index_guess] & 0x40) != 0) ||
            ((g_candidate_guess->stateFlags_guess[g_candidate_guess->part_guess->index_guess] & 0x80) != 0)) {
            LookupStatus_guess *status_guess = reinterpret_cast<LookupStatus_guess *>(
                reinterpret_cast<char *>(candidate_guess) + 8 + candidate_guess->holder_guess->vbase_offset);
            if (status_guess->GetStatus_guess() == 0)
                return 1;
        }
        return 0;
    }
    if (g_flagA_guess != 0 || g_flagB_guess != 0)
        return 1;
    return 0;
}

// Donates `value` platinum to the open tribute master (message 0x27B3: platinum, master spawn id) if the
// character has that much (CharInfo2 +0x11D4, probably the platinum on hand).
// FUNCTION: TITANIUM 0x004344F0
void LookupOwner_guess::DonateTributePlatinum_guess(int value_guess)
{
    if (g_tributeMaster_guess == 0)
        return;
    Candidate_guess *candidate_guess = g_candidate_guess;
    LookupStatus_guess *status_guess = reinterpret_cast<LookupStatus_guess *>(
        reinterpret_cast<char *>(candidate_guess) + 8 + candidate_guess->holder_guess->vbase_offset);
    LookupResult_guess *result_guess = status_guess->service_guess.GetCharInfo2();
    if (value_guess > result_guess->value_guess)
        return;
    int data_guess[3];
    data_guess[0] = value_guess;
    data_guess[1] = g_tributeMaster_guess->SpawnID;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x27b3, data_guess, 0xc, 1);
    if (g_pending_guess != 0) {
        Pending_guess *pending_guess = g_pending_guess;
        pending_guess->flag_guess = 1;
        pending_guess->UpdateDonateButton_guess();
    }
}

// Platinum donation reply (0x27B3, or OP_GuildTributeDonatePlat via Handle_guess; platinum, master id,
// points): unless the platinum is -1 it is taken, and string 0xD7D (master's name) and `message_guess`
// (0xD7E personal, 6000 guild, with the points) are printed.
// FUNCTION: TITANIUM 0x00434567
void MessageRouter_guess::OnPlatinumDonated_guess(int unused_guess, int *data_guess, int message_guess)
{
    char text_guess[1024];
    char name_guess[256];
    char *resolved_text_guess;

    unsigned int selected_guess = FUN_00401b28_guess(data_guess[1]);
    if (selected_guess != 0)
        resolved_text_guess = g_sender_guess->Store_guess(((ResolvedEntry_guess *)selected_guess)->text_guess);
    else
        resolved_text_guess = pStringTable->getString(0xd33, 0);
    strcpy(name_guess, resolved_text_guess);

    if (data_guess[0] != -1) {
        LookupStatus_guess *status_guess = (LookupStatus_guess *)&g_candidate_guess->embedded_guess[
            g_candidate_guess->holder_guess->vbase_offset];
        LookupResult_guess *result_guess = status_guess->service_guess.GetCharInfo2();
        if (result_guess->value_guess >= data_guess[0]) {
            ((LookupStatus_guess *)&g_candidate_guess->embedded_guess[
                g_candidate_guess->holder_guess->vbase_offset])->AddValue_guess(-data_guess[0]);
            BuildText_guess(text_guess, 0xd7d, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            g_sender_guess->dsp_chat(text_guess, 0x113, 1);
            BuildText_guess(text_guess, message_guess,
                            __itoa(data_guess[2], g_digits_guess, 10),
                            0, 0, 0, 0, 0, 0, 0, 0);
            g_sender_guess->dsp_chat(text_guess, 0x113, 1);
        }
    }

    if (g_pending_guess != 0) {
        g_pending_guess->ClearDonation_guess();
        g_pending_guess->ClearPending_guess();
    }
    if (pinstCGuildTributeMasterWnd_guess != 0) {
        pinstCGuildTributeMasterWnd_guess->Begin_guess();
        pinstCGuildTributeMasterWnd_guess->ClearPending_guess();
    }
}

// Same as IsTributeAvailable_guess.
// FUNCTION: TITANIUM 0x004346D5
int LookupOwner_guess::Check_guess()
{
    return IsTributeAvailable_guess();
}

// Guild twin of dsp_chat: OP_GuildTributeDonatePlat (platinum, master spawn id, word 3 the GuildID).
// FUNCTION: TITANIUM 0x004346DA
void LookupOwner_guess::DonateGuildTributePlatinum_guess(int value_guess)
{
    if (g_tributeMaster_guess == 0)
        return;
    Candidate_guess *candidate_guess = g_candidate_guess;
    LookupStatus_guess *status_guess = reinterpret_cast<LookupStatus_guess *>(
        reinterpret_cast<char *>(candidate_guess) + 8 + candidate_guess->holder_guess->vbase_offset);
    LookupResult_guess *result_guess = status_guess->service_guess.GetCharInfo2();
    if (value_guess > result_guess->value_guess)
        return;
    int data_guess[5];
    data_guess[0] = value_guess;
    data_guess[1] = g_tributeMaster_guess->SpawnID;
    data_guess[3] = g_messageSource_guess->value_guess;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildTributeDonatePlat, data_guess, 0x14, 1);
    if (pinstCGuildTributeMasterWnd_guess != 0)
        pinstCGuildTributeMasterWnd_guess->FinishPending_guess();
}

// Stores tribute item pointer `index` (profile +0x8C, 5 slots; larger traps).
// FUNCTION: TITANIUM 0x0043475F
void ValueStorage_guess::SetTributeItem_guess(unsigned int index_guess, unsigned int value_guess)
{
    if (index_guess >= 5)
        __debugbreak();
    values_guess[index_guess] = value_guess;
}

// Inventory slot word `index` (0-30) of the character's item array.
// FUNCTION: TITANIUM 0x00434777
unsigned int *Holder_guess::GetSlot_guess(unsigned int index_guess)
{
    unsigned int *base_guess = (unsigned int *)root_guess.GetCharInfo2();
    base_guess += 4;
    if (index_guess >= 31)
        __debugbreak();
    return base_guess + index_guess;
}

// Stores tribute item pointer `index` in the character's profile; the item packet handler fills slots
// 400-404 with it and the profile load clears them.
// FUNCTION: TITANIUM 0x00434792
void Holder_guess::SetTributeItem_guess(unsigned int index_guess, unsigned int value_guess)
{
    root_guess.GetCharInfo2()->SetTributeItem_guess(index_guess, value_guess);
}

// Two paged arrays with pages of 0x20 entries (0x0047C3AF): both +0x1C flags cleared, and the first
// array's +0x24 set to 1 and +0x25 cleared.
// FUNCTION: TITANIUM 0x004347AC
CombinedState_guess* CombinedState_guess::Initialize_guess()
{
    first_guess.Initialize_guess(0x20);
    second_guess.Initialize_guess(0x20);
    first_guess.firstFlag_guess = 0;
    second_guess.firstFlag_guess = 0;
    first_guess.active_guess = 0;
    first_guess.state_guess = 1;
    return this;
}

// Item donation reply (OP_TributeItem, or OP_GuildTributeDonateItem via Handle_guess; slot, count, master
// id, points): prints string 0xD37 (master, item) and `message_guess` with the points, then shrinks the
// stack by the count or deletes the item. Slots 0-31 are direct; 251-330 are bag slots (31 + 10*bag + n,
// bags 22-29). Slot 31 would trip GetSlot_guess's bound (0-30).
// FUNCTION: TITANIUM 0x004347D3
// @early-stop: budget, structural ndiff=28
void MessageRouter_guess::OnItemDonated_guess(Owner_guess* owner_guess, int* data_guess,
                                     unsigned int message_guess)
{
    char text_guess[512];
    char name_guess[256];
    int index_guess = data_guess[0];
    Entry_guess* entry_guess;
    unsigned int* slot_guess;

    char* resolved_guess;
    unsigned int selected_guess = FUN_00401b28_guess(data_guess[2]);
    if (selected_guess != 0)
        resolved_guess = g_sender_guess->Store_guess(
            ((ResolvedEntry_guess*)selected_guess)->text_guess);
    else
        resolved_guess = pStringTable->getString(0xd33, 0);
    strcpy(name_guess, resolved_guess);

    do {
        if (index_guess >= 0 && index_guess <= 31) {
            entry_guess = (Entry_guess*)owner_guess->Lookup_guess(index_guess);
            slot_guess = owner_guess->GetSlot_guess(index_guess);
        } else {
            if (index_guess >= 0x155)
                break;
            int row_guess = (index_guess - 0x1f) / 10;
            int col_guess = (index_guess - 0x1f) % 10;
            if (row_guess < 22 || row_guess > 29)
                break;
            Thing_guess* thing_guess = (Thing_guess*)owner_guess->Lookup_guess(row_guess);
            if (thing_guess == 0 || thing_guess->GetItemClass_guess() != 1)
                break;
            entry_guess = (Entry_guess*)thing_guess->Has_guess(col_guess);
            slot_guess = thing_guess->Slot_guess(col_guess);
        }
        if (entry_guess == 0)
            break;

        BuildText_guess(text_guess, 0xd37, name_guess, entry_guess->GetText_guess(),
                        0, 0, 0, 0, 0, 0, 0);
        g_sender_guess->dsp_chat(text_guess, 0x113, 1);
        BuildText_guess(text_guess, message_guess,
                        __itoa(data_guess[3], g_digits_guess, 10),
                        0, 0, 0, 0, 0, 0, 0, 0);
        g_sender_guess->dsp_chat(text_guess, 0x113, 1);
        if (entry_guess->IsStackable_guess() && data_guess[1] < entry_guess->field48_guess) {
            entry_guess->SetStackCount_guess(entry_guess->field48_guess - data_guess[1]);
        } else {
            *slot_guess = 0;
            entry_guess->Slot00_guess(1);
            g_candidate_guess->flagA_guess = 1;
            g_candidate_guess->flagB_guess = 0;
        }
    } while (0);

    if (g_pending_guess != 0) {
        g_pending_guess->ClearDonation_guess();
        g_pending_guess->ClearPending_guess();
    }
    if (pinstCGuildTributeMasterWnd_guess != 0) {
        pinstCGuildTributeMasterWnd_guess->Begin_guess();
        pinstCGuildTributeMasterWnd_guess->ClearPending_guess();
    }
}

// Deletes the owned pairs held in both paged arrays (+first, +second) and nulls each slot.
// FUNCTION: TITANIUM 0x00434A12
// @early-stop: budget, structural ndiff=8
PairLookupState_guess::~PairLookupState_guess()
{
    int firstIndex_guess = 0;
    PairLookupState_guess* owner_guess = this;
    while (firstIndex_guess < owner_guess->first_guess.count_guess) {
        OwnedPair_guess* value_guess = (OwnedPair_guess*)
            owner_guess->first_guess.pages_guess[firstIndex_guess >> owner_guess->first_guess.shift_guess]
                                                [firstIndex_guess & owner_guess->first_guess.mask_guess];
        if (value_guess != 0) {
            value_guess->~OwnedPair_guess();
            ::operator delete(value_guess);
        }
        owner_guess->first_guess.pages_guess[firstIndex_guess >> owner_guess->first_guess.shift_guess]
                                            [firstIndex_guess & owner_guess->first_guess.mask_guess] = 0;
        ++firstIndex_guess;
    }
    int secondIndex_guess = 0;
    TributeTable_guess* secondState_guess = &owner_guess->second_guess;
    while (secondIndex_guess < secondState_guess->count_guess) {
        OwnedPair_guess* value_guess = (OwnedPair_guess*)
            secondState_guess->pages_guess[secondIndex_guess >> secondState_guess->shift_guess]
                                          [secondIndex_guess & secondState_guess->mask_guess];
        if (value_guess != 0) {
            value_guess->~OwnedPair_guess();
            ::operator delete(value_guess);
        }
        secondState_guess->pages_guess[secondIndex_guess >> secondState_guess->shift_guess]
                                      [secondIndex_guess & secondState_guess->mask_guess] = 0;
        ++secondIndex_guess;
    }
}

// Paged arrays (block index >> shift, & mask): the record at `index`, 0 when out of range.
// The personal and guild tribute tables.
// FUNCTION: TITANIUM 0x00434AE0
unsigned int TributeTable_guess::Lookup_guess(int index_guess)
{
    unsigned int value_guess = 0;
    if (index_guess >= 0 && index_guess < count_guess)
        value_guess = pages_guess[index_guess >> shift_guess][index_guess & mask_guess];
    return value_guess;
}

// The same lookup at +0x28 (OffsetLookupState_guess).
// FUNCTION: TITANIUM 0x00434B0A
unsigned int OffsetLookupState_guess::Lookup_guess(int index_guess)
{
    unsigned int value_guess = 0;
    if (index_guess >= 0 && index_guess < count_guess)
        value_guess = pages_guess[index_guess >> shift_guess][index_guess & mask_guess];
    return value_guess;
}

// Recomputes the upkeep (+0x20): the cost of each of the 5 active tributes at its tier.
// FUNCTION: TITANIUM 0x00434B35
void TributeTable_guess::UpdateUpkeep_guess()
{
    total_guess = 0;
    for (int i_guess = 0; i_guess < 5; ++i_guess) {
        int id_guess = g_candidate_guess->GetSlot_guess(i_guess)->id_guess;
        if (id_guess != -1) {
            RecordData_guess *record_guess = reinterpret_cast<RecordData_guess *>(
                Lookup_guess(id_guess));
            if (record_guess != 0) {
                int index_guess = g_candidate_guess->GetSlot_guess(i_guess)->index_guess;
                if (index_guess < record_guess->count_guess)
                    total_guess += record_guess->values_guess[index_guess];
            }
        }
    }
    flag_guess = 0;
}

extern "C" unsigned int __cdecl strlen(const char *text_guess);

// Shows tribute `index`'s description in window `message_guess` (codes as in ShowTributeDescription_guess);
// when it isn't cached yet, asks for it with OP_SelectTribute (window code, tribute id).
// FUNCTION: TITANIUM 0x00434B8A
void TributeTable_guess::RequestTributeDescription_guess(int message_guess, int index_guess)
{
    unsigned int object_guess = Lookup_guess(index_guess);
    if (object_guess != 0) {
        StringData_guess *string_guess = reinterpret_cast<StringData_guess *>(
            reinterpret_cast<char *>(object_guess) + 8);
        if (strlen(string_guess->GetText_guess()) > 0) {
            ((Dispatch_guess *)this)->ShowTributeDescription_guess(message_guess, index_guess,
                                                 (int)string_guess->GetText_guess());
        } else {
            SendData_guess data_guess;
            data_guess.words_guess[0] = message_guess;
            data_guess.words_guess[1] = index_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_SelectTribute,
                              data_guess.bytes_guess, 0xc, 1);
        }
    }
}

// Guild version: asks with OP_GuildSelectTribute (window code and tribute id in words 1 and 2).
// FUNCTION: TITANIUM 0x00434C06
void OffsetLookupState_guess::RequestGuildTributeDescription_guess(int message_guess, int index_guess)
{
    unsigned int object_guess = Lookup_guess(index_guess);
    if (object_guess != 0) {
        StringData_guess *string_guess = reinterpret_cast<StringData_guess *>(
            reinterpret_cast<char *>(object_guess) + 8);
        if (strlen(string_guess->GetText_guess()) > 0) {
            ((Dispatch_guess *)this)->ShowTributeDescription_guess(message_guess, index_guess,
                                                 (int)string_guess->GetText_guess());
        } else {
            SendDataWide_guess data_guess;
            data_guess.words_guess[1] = message_guess;
            data_guess.words_guess[2] = index_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildSelectTribute,
                              data_guess.bytes_guess, 0x10, 1);
        }
    }
}

// Activates tribute `value`: one tier up (at most its last) when it is in one of the 5 slots, else the
// first free slot at tier 0; further slots holding it are cleared.
// FUNCTION: TITANIUM 0x00434C82
// @early-stop: budget, structural ndiff=70
void TributeTable_guess::AddActiveTribute_guess(int value_guess)
{
    int freeIndex_guess = -1;
    bool found_guess = false;
    for (int i_guess = 0; i_guess < 5; ++i_guess) {
        if (g_candidate_guess->GetSlot_guess(i_guess)->id_guess == value_guess) {
            if (found_guess) {
                g_candidate_guess->GetSlot_guess(i_guess)->index_guess = 0;
                g_candidate_guess->GetSlot_guess(i_guess)->id_guess = -1;
            } else {
                RecordData_guess *record_guess = reinterpret_cast<RecordData_guess *>(
                    Lookup_guess(value_guess));
                if (record_guess != 0) {
                    ++g_candidate_guess->GetSlot_guess(i_guess)->index_guess;
                    int lastIndex_guess = record_guess->count_guess - 1;
                    if (g_candidate_guess->GetSlot_guess(i_guess)->index_guess > lastIndex_guess)
                        g_candidate_guess->GetSlot_guess(i_guess)->index_guess = lastIndex_guess;
                }
                found_guess = true;
                freeIndex_guess = -1;
            }
        } else if (!found_guess && freeIndex_guess == -1) {
            if (g_candidate_guess->GetSlot_guess(i_guess)->id_guess == -1)
                freeIndex_guess = i_guess;
        }
    }
    if (freeIndex_guess != -1) {
        g_candidate_guess->GetSlot_guess(freeIndex_guess)->id_guess = value_guess;
        g_candidate_guess->GetSlot_guess(freeIndex_guess)->index_guess = 0;
    }
    flag_guess = 1;
    if (pinstCTributeBenefitWnd_guess != 0)
        pinstCTributeBenefitWnd_guess->MarkDirty_guess();
    if (g_notifier2_guess != 0)
        g_notifier2_guess->Refresh_guess();
}

// Personal tribute messages.
// OP_OpenTributeMaster (client id, master spawn id, response): response 0 closes the window and, when
// tribute is available, prints string 0xD35 with the master's name; otherwise the window opens for that
// master (0x905D10), and when that fails (-1) the client answers OP_TributeNPC.
// OP_TributeTimer: pCharData +0xE70. 0x27B3: platinum donation reply. OP_TributeInfo: adds or replaces a
// record. OP_TributeUpdate: on/off (+0x25) and the 5 active (tribute, tier) slots. OP_TributeItem: item
// donation reply. OP_TributePointUpdate: +0xE80, +0xE84, +0xE78, +0xE7C (EQEmu order: points, unknown,
// career points, unknown). OP_SelectTribute: shows the description and caches it in the record.
// FUNCTION: TITANIUM 0x00434D9A
// @early-stop: budget, structural ndiff=127
void TributeTable_guess::HandleTributeMessage_guess(int message_guess, int *data_guess)
{
    char text_guess[2052];
    int zero_guess = 0;
    int pair_guess[3];

    switch (message_guess) {
    case OP_OpenTributeMaster:
        if (data_guess[2] == zero_guess) {
            g_resetFlag_guess = zero_guess;
            if (g_pending_guess != 0)
                ((PendingVirtual_guess *)g_pending_guess)->SlotC0_guess(zero_guess, 1);
            unsigned int entry_guess = FUN_00401b28_guess(data_guess[1]);
            if (g_lookupOwner_guess.IsTributeAvailable_guess() == zero_guess)
                return;
            if (entry_guess == (unsigned int)zero_guess)
                return;
            char *stored_guess = g_sender_guess->Store_guess(
                ((ResolvedEntry_guess *)entry_guess)->text_guess);
            BuildText_guess(text_guess, 0xd35, stored_guess,
                            zero_guess, zero_guess, zero_guess, zero_guess,
                            zero_guess, zero_guess, zero_guess, zero_guess);
            pEverQuest->dsp_chat(text_guess, 0x113, 1);
            return;
        }
        if (g_tributeMaster_guess == 0 && g_pending_guess != 0) {
            g_tributeMaster_guess = (EQPlayer*)FUN_00401b28_guess(data_guess[1]);
            if (((PendingVirtual_guess *)g_pending_guess)->SlotC0_guess(1, 1) != -1)
                return;
            pair_guess[1] = data_guess[1];
            pair_guess[0] = data_guess[0];
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_TributeNPC,
                              pair_guess, 0xc, 1);
        }
        g_resetFlag_guess = zero_guess;
        return;

    case OP_TributeTimer:
        g_candidate_guess->fields_guess.field_e70_guess = data_guess[0];
        return;

    case 0x27b3:
        ((MessageRouter_guess *)this)->OnPlatinumDonated_guess((int)g_candidate_guess, data_guess, 0xd7e);
        return;

    case OP_TributeInfo: {
        void *allocation_guess = operator new(0x88);
        Record_guess *record_guess;
        if (allocation_guess != 0)
            record_guess = new (allocation_guess) Record_guess;
        else
            record_guess = 0;
        ((RecordReader_guess *)this)->Read_guess((const unsigned char *)data_guess,
                                                  record_guess);
        int index_guess = count_guess;
        if (index_guess <= record_guess->id_guess) {
            int indexed_zero_guess = 0;
            do {
                SetElementIdx_guess(count_guess, &indexed_zero_guess);
                ++index_guess;
            } while (index_guess <= record_guess->id_guess);
        }
        unsigned int old_guess = pages_guess[record_guess->id_guess >> shift_guess]
                                           [record_guess->id_guess & mask_guess];
        if (old_guess != (unsigned int)zero_guess)
            delete (OwnedPair_guess *)old_guess;
        pages_guess[record_guess->id_guess >> shift_guess]
                   [record_guess->id_guess & mask_guess] = (unsigned int)record_guess;
        break;
    }

    case OP_TributeUpdate:
        for (int i_guess = 0; i_guess < 5; ++i_guess) {
            g_candidate_guess->GetSlot_guess(i_guess)->id_guess = data_guess[1 + i_guess];
            g_candidate_guess->GetSlot_guess(i_guess)->index_guess = data_guess[6 + i_guess];
            delete ((Holder_guess *)&g_candidate_guess->embedded_guess[
                g_candidate_guess->holder_guess->vbase_offset])->GetSmallEntry_guess(i_guess);
            ((Holder_guess *)&g_candidate_guess->embedded_guess[
                g_candidate_guess->holder_guess->vbase_offset])->SetTributeItem_guess(i_guess, zero_guess);
        }
        active_guess = data_guess[0] != 0;
        g_candidate_guess->flagA_guess = 1;
        g_candidate_guess->flagB_guess = (unsigned char)zero_guess;
        break;

    case OP_TributeItem:
        ((MessageRouter_guess *)this)->OnItemDonated_guess((Owner_guess *)g_candidate_guess, data_guess,
                                                   0xd7e);
        return;

    case OP_TributePointUpdate:
        g_candidate_guess->fields_guess.field_e80_guess = data_guess[0];
        g_candidate_guess->fields_guess.field_e84_guess = data_guess[1];
        g_candidate_guess->fields_guess.field_e78_guess = data_guess[2];
        g_candidate_guess->fields_guess.field_e7c_guess = data_guess[3];
        return;

    case OP_SelectTribute: {
        ((Dispatch_guess *)this)->ShowTributeDescription_guess(data_guess[0], data_guess[1],
                                            (int)(data_guess + 2));
        if (count_guess <= data_guess[1])
            return;
        unsigned int record_guess = pages_guess[data_guess[1] >> shift_guess]
                                               [data_guess[1] & mask_guess];
        if (record_guess != 0)
            ((StringRecord_guess *)record_guess)->value_guess =
                (const char *)(data_guess + 2);
        return;
    }
    default:
        return;
    }

    flag_guess = 1;
    if (pinstCTributeBenefitWnd_guess != 0)
        pinstCTributeBenefitWnd_guess->MarkDirty_guess();
    if (g_notifier2_guess != 0)
        g_notifier2_guess->Refresh_guess();
}

// The upkeep of the active tributes, recomputed when dirty (+0x24).
// FUNCTION: TITANIUM 0x00435150
int TributeTable_guess::GetUpkeep_guess()
{
    if (flag_guess != 0)
        UpdateUpkeep_guess();
    return total_guess;
}

struct Owner2_guess {
    // EXTERNAL: TITANIUM 0x0050FB61 Owner2_guess::Adjust_guess
    void Adjust_guess(GuildMemberEntry_guess *settings_guess, int value_guess);
};

#define g_byteEE_guess EQ_GLOBAL(unsigned char, 0x0091D6EE)
#define g_valueA_guess EQ_GLOBAL(unsigned int, 0x0091D6D0)
#define g_valueB_guess EQ_GLOBAL(unsigned int, 0x0091D6D4)
#define g_flag248d4_guess EQ_GLOBAL(int, 0x009248D4)
#define pinstCGuildManagementWnd_guess EQ_GLOBAL(Owner2_guess*, 0x00991AAC)

struct ThingVt_guess {
    virtual void Slot00_guess(int flag_guess);
};

struct CandidateSubVt_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual ThingVt_guess *Slot05_guess(int index_guess);
};

struct NotifierVt_guess {
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
    virtual void Slot0A_guess();
    virtual void Slot0B_guess();
    virtual void Slot0C_guess();
    virtual void Slot0D_guess();
    virtual void Slot0E_guess();
    virtual void Slot0F_guess();
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
    virtual void Slot1A_guess();
    virtual void Slot1B_guess();
    virtual void Slot1C_guess();
    virtual void Slot1D_guess();
    virtual void Slot1E_guess();
    virtual void Slot1F_guess();
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
    virtual void Slot2A_guess();
    virtual void Slot2B_guess();
    virtual void Slot2C_guess();
    virtual void Slot2D_guess();
    virtual void Slot2E_guess();
    virtual void Slot2F_guess();
    virtual int Slot30_guess(int first_guess, int second_guess);
};

// Guild tribute messages.
// OP_GuildModifyBenefits: byte 0x91D6EE. OP_GuildOptInOut: a member's flags (member name from word 1).
// OP_GuildSendActiveTributes, OP_GuildTributeToggleReply: favor (0x91D6D4), timer (0x91D6D0), on/off
// (0x91D6ED) and the two active (tribute, tier) slots. Donation replies use string 6000. 0x5E3D: a guild
// tribute record. OP_OpenGuildTributeMaster: as OP_OpenTributeMaster, answering 0x6516 and closing with
// string 0x2FD2. OP_GuildTributeFavorAndTimer: favor and timer only. OP_GuildSelectTribute: description.
// FUNCTION: TITANIUM 0x00435163
// @early-stop: budget, structural ndiff=165
void MessageRouter_guess::HandleGuildTributeMessage_guess(int message_guess, unsigned int *data_guess)
{
    int msg_guess[4];
    int zero_guess;
    char buf_guess[2048];
    switch (message_guess) {
    case OP_GuildModifyBenefits:
        g_byteEE_guess = *(unsigned char *)data_guess;
        break;
    case OP_GuildOptInOut: {
        GuildMemberEntry_guess *settings_guess = g_selectionTable_guess.Get_guess(data_guess + 1);
        if (settings_guess == 0)
            return;
        settings_guess->Set_guess(data_guess[0x11] != 0, data_guess[0x12], data_guess[0x13],
                                  *(unsigned char *)(data_guess + 0x14));
        g_dirty_guess = 1;
        if (pinstCTributeBenefitWnd_guess != 0)
            pinstCTributeBenefitWnd_guess->MarkClean_guess();
        if (pinstCGuildManagementWnd_guess != 0)
            pinstCGuildManagementWnd_guess->Adjust_guess(settings_guess, -1);
        if (pinstCGuildTributeMasterWnd_guess != 0)
            pinstCGuildTributeMasterWnd_guess->Commit_guess();
        return;
    }
    case OP_GuildSendActiveTributes: {
        g_valueB_guess = data_guess[1];
        g_valueA_guess = data_guess[2];
        g_enabled_guess = *(unsigned char *)(data_guess + 3);
        int i_guess = 0;
        unsigned int *slot_guess = data_guess + 6;
        for (; i_guess < 2; ++i_guess, ++slot_guess) {
            unsigned int value_guess = slot_guess[0];
            unsigned int count_guess = slot_guess[2];
            g_slots_guess[i_guess].value_guess = value_guess;
            g_slots_guess[i_guess].count_guess = count_guess;
            g_dirty_guess = 1;
            ThingVt_guess *thing_guess =
                ((CandidateSubVt_guess *)&g_candidate_guess->sub_guess)->Slot05_guess(i_guess);
            if (thing_guess != 0)
                thing_guess->Slot00_guess(1);
            g_candidate_guess->Refresh_guess(i_guess, 0);
        }
        if (pinstCTributeBenefitWnd_guess != 0)
            pinstCTributeBenefitWnd_guess->MarkClean_guess();
        if (pinstCGuildTributeMasterWnd_guess != 0)
            pinstCGuildTributeMasterWnd_guess->SetFlag_guess();
        g_candidate_guess->flagA_guess = 1;
        return;
    }
    case OP_GuildTributeDonateItem:
        OnItemDonated_guess((Owner_guess *)g_candidate_guess, (int *)data_guess, 6000);
        return;
    case OP_GuildTributeToggleReply: {
        int i_guess = 0;
        unsigned int *slot_guess = data_guess + 6;
        for (; i_guess < 2; ++i_guess, ++slot_guess) {
            unsigned int value_guess = slot_guess[0];
            unsigned int count_guess = slot_guess[2];
            g_slots_guess[i_guess].value_guess = value_guess;
            g_slots_guess[i_guess].count_guess = count_guess;
            g_dirty_guess = 1;
            ThingVt_guess *thing_guess =
                ((CandidateSubVt_guess *)&g_candidate_guess->sub_guess)->Slot05_guess(i_guess);
            if (thing_guess != 0)
                thing_guess->Slot00_guess(1);
            g_candidate_guess->Refresh_guess(i_guess, 0);
        }
        g_candidate_guess->flagA_guess = 1;
        g_valueB_guess = data_guess[1];
        g_valueA_guess = data_guess[2];
        g_enabled_guess = *(unsigned char *)(data_guess + 3);
        break;
    }
    case OP_GuildTributeDonatePlat:
        OnPlatinumDonated_guess((int)g_candidate_guess, (int *)data_guess, 6000);
        return;
    case 0x5e3d: {
        void *allocation_guess = operator new(0x88);
        Record_guess *record_guess;
        if (allocation_guess != 0)
            record_guess = new (allocation_guess) Record_guess;
        else
            record_guess = 0;
        ((RecordReader_guess *)this)->Read_guess((const unsigned char *)(data_guess + 1),
                                                  record_guess);
        int index_guess = table_guess.count_guess;
        if (index_guess <= record_guess->id_guess) {
            int indexed_zero_guess = 0;
            do {
                table_guess.SetElementIdx_guess(table_guess.count_guess, &indexed_zero_guess);
                ++index_guess;
            } while (index_guess <= record_guess->id_guess);
        }
        unsigned int old_guess = table_guess.pages_guess[record_guess->id_guess >> table_guess.shift_guess]
                                                       [record_guess->id_guess & table_guess.mask_guess];
        if (old_guess != 0)
            delete (OwnedPair_guess *)old_guess;
        table_guess.pages_guess[record_guess->id_guess >> table_guess.shift_guess]
                               [record_guess->id_guess & table_guess.mask_guess] =
            (unsigned int)record_guess;
        if (pinstCTributeBenefitWnd_guess != 0)
            pinstCTributeBenefitWnd_guess->MarkClean_guess();
        g_dirty_guess = 1;
        break;
    }
    case OP_OpenGuildTributeMaster:
        if (data_guess[2] != 0) {
            if (g_tributeMaster_guess == 0 && pinstCGuildTributeMasterWnd_guess != 0) {
                g_tributeMaster_guess = (EQPlayer*)FUN_00401b28_guess(data_guess[1]);
                if (((NotifierVt_guess *)pinstCGuildTributeMasterWnd_guess)->Slot30_guess(1, 1) != -1)
                    return;
                msg_guess[1] = (int)data_guess[1];
                msg_guess[0] = (int)data_guess[0];
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), 0x6516, msg_guess, 0xc, 1);
            }
            g_flag248d4_guess = 0;
            return;
        }
        g_flag248d4_guess = 0;
        if (pinstCGuildTributeMasterWnd_guess != 0)
            ((NotifierVt_guess *)pinstCGuildTributeMasterWnd_guess)->Slot30_guess(0, 1);
        {
            unsigned int id_guess = FUN_00401b28_guess(data_guess[1]);
            char should_guess = (char)g_lookupOwner_guess.IsTributeAvailable_guess();
            if (should_guess == 0 || id_guess == 0)
                return;
        }
        BuildText_guess(buf_guess, 0x2fd2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        g_sender_guess->dsp_chat(buf_guess, 0x113, 1);
        return;
    case OP_GuildTributeFavorAndTimer:
        g_valueA_guess = data_guess[2];
        g_valueB_guess = data_guess[1];
        return;
    case OP_GuildSelectTribute: {
        unsigned int index_guess = data_guess[2];
        ShowTributeDescription_guess((int)data_guess[1], (int)index_guess, (int)(data_guess + 3));
        if (table_guess.count_guess <= (int)index_guess)
            return;
        unsigned int entry_guess = table_guess.pages_guess[(int)index_guess >> table_guess.shift_guess]
                                                         [index_guess & table_guess.mask_guess];
        if (entry_guess == 0)
            return;
        ((StringRecord_guess *)entry_guess)->value_guess = (const char *)(data_guess + 3);
        return;
    }
    default:
        return;
    }
    if (pinstCGuildTributeMasterWnd_guess != 0)
        pinstCGuildTributeMasterWnd_guess->SetFlag_guess();
}

struct DatabaseTable_guess;

struct DatabaseEntry_guess {
    DatabaseTable_guess* nested_guess;
};

struct DatabaseTable_guess {
    unsigned char pad_guess[0x10];
    StringData_guess error_guess;

    // EXTERNAL: TITANIUM 0x004FF9C9 DatabaseTable_guess::Find_guess
    DatabaseEntry_guess* Find_guess(unsigned int key_guess);
    // EXTERNAL: TITANIUM 0x00447C66 DatabaseTable_guess::Insert_guess
    void Insert_guess(const void* value_guess, int key_guess);
    void Load_guess(const char* path_guess);
    char* GetString_guess(unsigned int first_guess, unsigned int second_guess,
                          unsigned char* found_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(StringData_guess* output_guess,
                                const char* format_guess, ...);

// Database string `first` of type `second`; a missing pair gives "Unknown DB String id-type".
// FUNCTION: TITANIUM 0x004355F7
char* DatabaseTable_guess::GetString_guess(unsigned int first_guess,
                                           unsigned int second_guess,
                                           unsigned char* found_guess)
{
    DatabaseEntry_guess* entry_guess = Find_guess(second_guess);
    if (entry_guess != 0) {
        entry_guess = entry_guess->nested_guess->Find_guess(first_guess);
        if (entry_guess != 0) {
            if (found_guess != 0)
                *found_guess = 1;
            return reinterpret_cast<StringData_guess*>(entry_guess)->GetText_guess();
        }
    }
    if (found_guess != 0)
        *found_guess = 0;
    FormatString_guess(&error_guess, "Unknown DB String %d-%d",
                       first_guess, second_guess);
    return error_guess.GetText_guess();
}

// Hash table constructor: empty, with a bucket array sized from `value` by 0x00490C98 (rounded up by
// 0x0042429E).
// FUNCTION: TITANIUM 0x00435652
ParameterizedState_guess* ParameterizedState_guess::Reset_guess(unsigned int value_guess)
{
    first_guess = 0;
    second_guess = 0;
    third_guess = 0;
    fourth_guess = 0;
    Initialize_guess(value_guess);
    return this;
}

struct HashEntry_guess {
    unsigned int key_guess;
    unsigned int hash_guess;
    HashEntry_guess* next_guess;

    // EXTERNAL: TITANIUM 0x00571F70 HashEntry_guess::SetKey_guess
    void SetKey_guess(const void* key_guess);
};

struct HashTable_guess {
    HashEntry_guess** buckets_guess;
    unsigned int bucketCount_guess;
    unsigned int entryCount_guess;
    unsigned int occupiedBucketCount_guess;

    void Insert_guess(const void* key_guess, unsigned int hash_guess);
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// Pushes a node onto bucket hash % count; +0xC counts the buckets in use.
// FUNCTION: TITANIUM 0x00435671
void HashTable_guess::Insert_guess(const void* key_guess, unsigned int hash_guess)
{
    void* allocation_guess = operator new(12);
    HashEntry_guess* node_guess;
    if (allocation_guess != 0) {
        *(unsigned int*)allocation_guess = 0;
        node_guess = (HashEntry_guess*)allocation_guess;
    } else {
        node_guess = 0;
    }
    node_guess->SetKey_guess(key_guess);
    node_guess->hash_guess = hash_guess;
    unsigned int bucket_guess = hash_guess % bucketCount_guess;
    HashEntry_guess* head_guess = buckets_guess[bucket_guess];
    if (head_guess == 0) {
        node_guess->next_guess = 0;
        buckets_guess[bucket_guess] = node_guess;
        ++occupiedBucketCount_guess;
    } else {
        node_guess->next_guess = head_guess;
        buckets_guess[bucket_guess] = node_guess;
    }
    ++entryCount_guess;
}

// EXTERNAL: TITANIUM 0x004999D8 printf_guess
int __cdecl printf_guess(const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x004B2056 ParseLong_guess
int __cdecl ParseLong_guess(const char* input_guess, long* output_guess, int option_guess);
// EXTERNAL: TITANIUM 0x005769E0 ParseBuffer_guess
int __cdecl ParseBuffer_guess(const char* input_guess, char* output_guess, int size_guess,
                              int option_guess, int mode_guess);

// Reads the database strings file: lines "id^type^text", one hash table (512 buckets) per type.
// FUNCTION: TITANIUM 0x004356CC
// @early-stop: tiebreak, structural ndiff=62
void DatabaseTable_guess::Load_guess(const char* path_guess)
{
    char line_guess[0x1000];
    char name_guess[0x800];
    int lineCount_guess;
    FILE* file_guess;
    long type_guess;
    long id_guess;
    printf_guess("Loading database strings file %s...", path_guess);
    file_guess = fopen(path_guess, "rt");
    if (file_guess == 0) {
        Log_guess("ERROR: could not find DatabaseStrings file %s.", path_guess);
        return;
    }
    lineCount_guess = 0;
    line_guess[0] = 0;
    while (!feof(file_guess)) {
        line_guess[0] = 0;
        fgets(line_guess, 0xfff, file_guess);
        ++lineCount_guess;
        line_guess[sizeof(line_guess) - 1] = 0;
        int idLength_guess = ParseLong_guess(line_guess, &id_guess, 0x5e);
        char* rest_guess = line_guess + idLength_guess;
        int typeLength_guess = ParseLong_guess(rest_guess, &type_guess, 0x5e);
        char* text_guess = rest_guess + typeLength_guess;
        if (type_guess < 0) {
            Log_guess("ERROR: DatabaseStrings file %s has line %d with negative type %d.",
                      path_guess, lineCount_guess, type_guess);
        } else {
            DatabaseEntry_guess* entry_guess = Find_guess(type_guess);
            HashTable_guess* table_guess;
            if (entry_guess != 0) {
                table_guess = (HashTable_guess*)entry_guess->nested_guess;
            } else {
                ParameterizedState_guess* created_guess = new ParameterizedState_guess;
                ParameterizedState_guess* nested_guess = 0;
                if (created_guess != 0) {
                    nested_guess = created_guess->Reset_guess(0x200);
                }
                table_guess = (HashTable_guess*)nested_guess;
                Insert_guess(&nested_guess, type_guess);
            }
            ParseBuffer_guess(text_guess, name_guess, 0x800, 0x5e, 1);
            CXStr value_guess(name_guess);
            table_guess->Insert_guess(&value_guess, id_guess);
        }
    }
    fclose(file_guess);
    printf_guess("%d strings read.\n", lineCount_guess);
}

