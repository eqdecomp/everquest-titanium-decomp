// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 167: a hint from compare/tumap.py.
// CGuildTributeMasterWnd (screen "GuildTributeMasterWnd"): the guild tribute master's window.
// Object_005117c3, Report_00511af8 and SortObject_00511 are all this window; Deleter_00512846 is its
// destructor. The benefits live in the tu_027 table at 0x850350 (count 0x850378); 0x91D6D8 holds the two
// active ones (benefit, tier) and 0x91D6EE says whether guild tribute is on. 0x905D10 is the tribute master
// NPC (spawn id +0x258).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CTributeBenefitWnd.h"
#include "titanium/wnd/CQuantityWnd.h"

struct State_00511_guess {
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
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess();
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual void DeleteAll_guess();
    char pad_004_guess[0x118];
    int count_11c_guess;
    // EXTERNAL: TITANIUM 0x0059B9D0 State_00511_guess::AddString_guess
    int AddString_guess(const CXStr& text, unsigned long color, unsigned int data, const void* icon);
    // EXTERNAL: TITANIUM 0x0059B360 State_00511_guess::SetItemText_guess
    void SetItemText_guess(int index, int column, const CXStr& text);
    // EXTERNAL: TITANIUM 0x00597BE0 State_00511_guess::GetIndex_guess
    int GetIndex_guess();
    // EXTERNAL: TITANIUM 0x00597ED0 State_00511_guess::GetValue_guess
    int GetValue_guess(int index);
    // EXTERNAL: TITANIUM 0x00597C20 State_00511_guess::SetIndex_guess
    void SetIndex_guess(int index);
    // EXTERNAL: TITANIUM 0x00598D90 State_00511_guess::Refresh_guess
    void Refresh_guess(int index);
    // EXTERNAL: TITANIUM 0x005E1080 State_00511_guess::HasStatus_guess
    int HasStatus_guess();
    // EXTERNAL: TITANIUM 0x005E1080 State_00511_guess::QueryText_guess
    int QueryText_guess(char* output, int radix, ...);
    // EXTERNAL: TITANIUM 0x0059B3E0 State_00511_guess::SetCell_guess
    void SetCell_guess(int index, int slot, unsigned long color);
};

struct Flag_00511_guess {
    char pad_000_guess[0x5d];
    unsigned char value_05d_guess;
};

struct Sink_00511_guess {
    char pad_000_guess[0x128];
    unsigned char value_128_guess;
    // EXTERNAL: TITANIUM 0x005BB140 Sink_00511_guess::SetCheck
    void SetCheck(unsigned char value);
};

struct LayoutFactory_00511_guess {
    // EXTERNAL: TITANIUM 0x00572300 LayoutFactory_00511_guess::GetLayout_guess
    void* GetLayout_guess(const char* name);
};

struct Panel_00511_guess {
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
    virtual void SetListLayoutA_guess(void* value);
    virtual void SetListLayoutB_guess(void* value);
};

struct Item_00511_guess {
    char name_000_guess[0x40];
    int position_0040_guess;
    int value_044_guess;
    int value_048_guess;
    int key_04c_guess;
    int position_050_guess;
};

struct Container_00511_guess {
    int count_guess;
    Item_00511_guess** data_guess;
    // EXTERNAL: TITANIUM 0x004EB924 Container_00511_guess::At_guess
    Item_00511_guess** At_guess(int index);
    // EXTERNAL: TITANIUM 0x0050319B Container_00511_guess::Insert_guess
    void Insert_guess(int index, Item_00511_guess** value);
    // EXTERNAL: TITANIUM 0x00405492 Container_00511_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
};

struct Slots_00511af8_guess;

struct Header_00511_guess {
    char pad_000_guess[0x120];
    LayoutFactory_00511_guess layoutFactory_120_guess;
    char pad_121_guess[0x3b];
    CStmlWnd* flag_15c_guess;
    State_00511_guess* state_160_guess;
    State_00511_guess* state_164_guess;
    char pad_168_guess[0x0c];
    Flag_00511_guess* out_174_guess;
    Flag_00511_guess* out_178_guess;
    char pad_17c_guess[0x04];
    Sink_00511_guess* sink_180_guess;
    Panel_00511_guess* panel_184_guess;
    Slots_00511af8_guess* state_188_guess;
    // EXTERNAL: TITANIUM 0x005A1EF0 Header_00511_guess::LoadActiveBenefits_guess
    void LoadActiveBenefits_guess(State_00511_guess* state, const char* name);
    // EXTERNAL: TITANIUM 0x005A1FE0 Header_00511_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(State_00511_guess* state, const char* name);
};

struct Result_005117cb_guess {
    char pad_000_guess[0x264];
    unsigned char value_264_guess;
};

struct SelectionData_005117cb_guess {
    char pad_000_guess[0x120];
    char name_0120_guess;
    char pad_121_guess[0x15b];
    int state_27c_guess;
    char pad_280_guess[0x08];
    int state_288_guess;
};

struct SelectionLookup_005117cb_guess {
    // EXTERNAL: TITANIUM 0x0040AA28 SelectionLookup_005117cb_guess::Find_guess
    Result_005117cb_guess* Find_guess(char* value);
};

struct Record_00511_guess;

struct Lookup_00511_guess {
    // EXTERNAL: TITANIUM 0x00434AE0 Lookup_00511_guess::Begin_guess
    void Begin_guess(int value);
    // EXTERNAL: TITANIUM 0x00434C06 Lookup_00511_guess::RequestGuildTributeDescription_guess
    void RequestGuildTributeDescription_guess(int mode, int value);
    // EXTERNAL: TITANIUM 0x00434B0A Lookup_00511_guess::Find_guess
    Record_00511_guess* Find_guess(int key);
    // EXTERNAL: TITANIUM 0x0043441A Lookup_00511_guess::AddGuildTribute_guess
    void AddGuildTribute_guess(int key);
    // EXTERNAL: TITANIUM 0x004343B4 Lookup_00511_guess::LowerGuildTributeTier_guess
    void LowerGuildTributeTier_guess(int key);
    // EXTERNAL: TITANIUM 0x004346D5 Lookup_00511_guess::Check_guess
    bool Check_guess();
    // EXTERNAL: TITANIUM 0x004346DA Lookup_00511_guess::DonateGuildTributePlatinum_guess
    void DonateGuildTributePlatinum_guess(int value);
    // EXTERNAL: TITANIUM 0x0043423C Lookup_00511_guess::SendGuildTributeDonateItem_guess
    void SendGuildTributeDonateItem_guess(int value, int mode);
};

struct Record_00511_guess {
    int key_000_guess;
    CXStr name_004_guess;
    int pad_008_guess;
    int count_guess;
    int values_010_guess[10];
    int values_038_guess[10];
};

struct SlotPair_00512d0f_guess {
    int key_guess;
    int index_guess;
};

#define g_recordCount_00512d0f_guess EQ_GLOBAL(int, 0x00850378)
#define g_slotPairs_00512d0f_guess EQ_ARRAY(SlotPair_00512d0f_guess, 0x0091D6D8)

typedef int (__cdecl *Compare_00511_guess)(const void*, const void*);

// EXTERNAL: TITANIUM 0x0056BF4F CompareTributeName_guess
int __cdecl CompareTributeName_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BF76 CompareTributeTierThenName_guess
int __cdecl CompareTributeTierThenName_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BFC1 CompareTributeCostThenName_guess
int __cdecl CompareTributeCostThenName_guess(const void*, const void*);

extern "C" void __cdecl qsort(void*, unsigned int, unsigned int, Compare_00511_guess);

#define g_lookup_00511_guess EQ_GLOBAL(Lookup_00511_guess, 0x00850350)
#define g_selectionData_005117cb_guess EQ_GLOBAL(SelectionData_005117cb_guess*, 0x00905ce4)
#define g_selectionLookup_005117cb_guess EQ_GLOBAL(SelectionLookup_005117cb_guess, 0x00905d38)
#define g_flagByte_00511f40_guess EQ_GLOBAL(unsigned char, 0x0091D6EE)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_00511_guess
void __cdecl FormatText_00511_guess(char* output, int id, const char* first, const char* second);
// EXTERNAL: TITANIUM 0x005E0EC0 FormatValue_00511_guess
const char* __cdecl FormatValue_00511_guess(int value, ...);
#define g_formatValue_005118e0_guess EQ_ARRAY(char, 0x0099db00)
#define g_context_005118e0_guess EQ_GLOBAL(char*, 0x00905d10)

struct Object_005117c3_guess : Header_00511_guess, Container_00511_guess {
    char pad_194_guess[0x08];
    int count_19c_guess;
    Container_00511_guess container_1a0_guess;
    char pad_1a8_guess[0x08];
    int count_1b0_guess;
    unsigned char flag_1b4_guess;
    char pad_1b5_guess[0x03];
    int mode_1b8_guess;
    char compareFlag_1bc_guess;
    char pad_1bd_guess[0x08];
    unsigned char flag_1c5_guess;
    unsigned char flag_1c6_guess;
    char pad_1c7_guess[0x11];
    unsigned int limit_1d8_guess;
    void ProcessFrame_guess();
    void SetFlag_guess();
    void SetSelectionState_guess();
    void SelectBenefit_guess(int value);
    void UpdateSelection_guess();
    void ClearSelection_guess();
    void SortSelection_guess();
    void LoadIniInfo_guess();
    void StoreIniInfo_guess();
    bool ShowTributeValue_guess(State_00511_guess* state);
    void SetBenefitText_guess(int value, const char* text);
    void RefreshBenefitLists_guess();
    void Rebuild_guess();
    void UpdateButtons_guess();
    bool LeaveMaster_guess();
};

extern "C" char* __cdecl _itoa(int value, char* buffer, int radix);
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)

struct SortPrefix_00511_guess {
    char pad_000_guess[0x1a0];
};

struct SortObject_00511_guess : SortPrefix_00511_guess, Container_00511_guess {
    char pad_1a8_guess[0x08];
    int sortCount_1b0_guess;
    char pad_1b4_guess[0x0c];
    int mode_1c0_guess;
    char compareFlag_1c4_guess;
    void Sort_guess();
    void UpdateItems_guess(int* values, int position);
};

struct Source_00511af8_guess {
    char pad_000_guess[0x48];
    int value_048_guess;
    // EXTERNAL: TITANIUM 0x005ECCC0 Source_00511af8_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Source_00511af8_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Source_00511af8_guess::HasValue_guess
    int HasValue_guess(int index);
    // EXTERNAL: TITANIUM 0x005E1080 Source_00511af8_guess::GetLimit_guess
    int GetLimit_guess();
    // EXTERNAL: TITANIUM 0x005EC760 Source_00511af8_guess::IsStackable_guess
    bool IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Source_00511af8_guess::GetChild_guess
    Source_00511af8_guess* GetChild_guess(int index);
    // EXTERNAL: TITANIUM 0x005EC650 Source_00511af8_guess::GetChildSlot_guess
    Source_00511af8_guess** GetChildSlot_guess(int index);
};

struct SlotItem_0051256a_guess {
    char pad_000_guess[0x38];
    int value_038_guess;
};

// pCharData seen through its virtual base (vbptr at +8).
struct InventoryPrefix_0051256a_guess {
    virtual void Slot00_guess() = 0;
    int field04_guess;
};

struct InventoryBase_0051256a_guess {
    void* vftable_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 InventoryBase_0051256a_guess::GetItem_guess
    Source_00511af8_guess* GetItem_guess(int slot);
    // EXTERNAL: TITANIUM 0x00434777 InventoryBase_0051256a_guess::GetItemSlot_guess
    Source_00511af8_guess** GetItemSlot_guess(int slot);
};

struct Inventory_0051256a_guess : InventoryPrefix_0051256a_guess, virtual InventoryBase_0051256a_guess {
};

#define g_inventory_0051256a_guess EQ_GLOBAL(Inventory_0051256a_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText11_0051256a_guess
char* __cdecl FormatText11_0051256a_guess(char* output, int id, const char* a, const char* b,
    const char* c, const char* d, const char* e, const char* f, const char* g, const char* h,
    const char* i);

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::GetText_guess
    const char* GetText_guess(unsigned int id, int value, int code, int flags);
};

struct AlertSink_00511af8_guess {
    // EXTERNAL: TITANIUM 0x004A1350 AlertSink_00511af8_guess::SavePC_guess
    void SavePC_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x004982C6 AlertSink_00511af8_guess::Show_guess
    void Show_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00492EC2 AlertSink_00511af8_guess::Resolve_guess
    const char* Resolve_guess(const char* value);
};

struct Sub_00511af8_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Sub_00511af8_guess::Method_guess
    void Method_guess(int value);
    void SetValue_guess(int value) { Method_guess(value); }
};

struct Holder_00511af8_guess {
    char pad_000_guess[0x16c];
    Sub_00511af8_guess* sub_16c_guess;
};

struct Pair_00512862_guess {
    int first_guess;
    int second_guess;
};

struct Slots_00511af8_guess {
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
    virtual Pair_00512862_guess GetPair_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(CXStr& value);
};

struct OutputFlag_00511af8_guess : Slots_00511af8_guess {
    char pad_004_guess[0x59];
    unsigned char enabled_005d_guess;
    char pad_05e_guess[0xca];
    unsigned char value_128_guess;
};


struct Report_00511af8_guess {
    char pad_000_guess[0x124];
    int value_124_guess;
    char pad_128_guess[0x38];
    State_00511_guess* state_160_guess;
    State_00511_guess* state_164_guess;
    Holder_00511af8_guess* holder_168_guess;
    Slots_00511af8_guess* sink_16c_guess;
    OutputFlag_00511af8_guess* output_170_guess;
    Flag_00511_guess* out_174_guess;
    Flag_00511_guess* out_178_guess;
    Slots_00511af8_guess* sink_17c_guess;
    Sink_00511_guess* sink_180_guess;
    char pad_184_guess[0x04];
    OutputFlag_00511af8_guess* state_188_guess;
    char pad_18c_guess[0x2c];
    int mode_1b8_guess;
    char compareFlag_1bc_guess;
    char pad_1bd_guess[0x03];
    int sortMode_1c0_guess;
    unsigned char flag_1c4_guess;
    unsigned char flag_1c5_guess;
    unsigned char flag_1c6_guess;
    char pad_1c7_guess;
    int state_1c8_guess;
    Source_00511af8_guess** source_1cc_guess;
    int eventState_1d0_guess;
    int fallbackCount_1d4_guess;
    char pad_1d8_guess[0x04];
    unsigned char inverted_1dc_guess;
    // EXTERNAL: TITANIUM 0x005A2230 Report_00511af8_guess::HandleOther_guess
    int HandleOther_guess(void* sender, unsigned int message, void* data);
    void Update_guess();
    void SetSlot_guess(int slot, SlotItem_0051256a_guess* item);
    void Reset_guess();
    bool OpenForMaster_guess();
    int WndNotification_guess(void* sender, unsigned int message, void* data);
};

#define g_textLookup_00511af8_guess EQ_GLOBAL(StringTableView_guess*, 0x00905cb0)
#define g_alertSink_00511af8_guess EQ_GLOBAL(AlertSink_00511af8_guess*, 0x00988df0)

struct CharInfo2View_00512862_guess {
    char pad_000_guess[0x11d4];
    int value_11d4_guess;
};

// EXTERNAL: TITANIUM 0x0060E450 CopyInfo_00512862_guess
void __cdecl CopyInfo_00512862_guess(void* destination, const void* source);

struct Connection_00511_guess {
    char pad_000_guess[0x258];
    int spawnId_0258_guess;
};

struct BenefitPacket_00511_guess {
    char prefix_000_guess[0x14];
    int value_014_guess;
    int values_018_guess[6];
};

struct BenefitListPacket_00511_guess {
    char prefix_000_guess[0x4c];
    int value_04c_guess;
};

struct NotificationPacket_00512862_guess {
    int value_000_guess;
    unsigned char value_004_guess;
    char pad_005_guess[0x03];
    char data_008_guess[0x44];
    int value_04c_guess;
};

struct StatusPacket_00512862_guess {
    unsigned char enabled_000_guess;
    char pad_001_guess[0x4b];
    int value_04c_guess;
};

struct CharacterDataView_00512862_guess {
    char pad_000_guess[0x120];
    char data_120_guess[0x168];
    int value_288_guess;
};

#define g_benefitConnection_00511_guess EQ_GLOBAL(Connection_00511_guess*, 0x00905d10)
#define g_selectionValue_00511_guess EQ_GLOBAL(Connection_00511_guess*, 0x00905ce4)
#define g_benefitValues_00511_guess EQ_ARRAY(int, 0x0091D6D8)
#define g_benefitStatus_00511_guess EQ_GLOBAL(int, 0x00923D94)
#define g_benefitResult_00511_guess EQ_GLOBAL(int, 0x009248D4)

// ShowTributeValue_guess is misnamed: a chat line about the selected item's tribute value from the master (name at
// +0x120): string 0xD34 with the value, or 0xD36 when it has none (returns false).
// FUNCTION: TITANIUM 0x005118E0
// @early-stop: budget, structural ndiff=76
bool Object_005117c3_guess::ShowTributeValue_guess(State_00511_guess* state) {
    char buffer[512];
    bool result = true;
    if (state != 0) {
        int hasStatus = state->HasStatus_guess();
        const char* context = g_context_005118e0_guess + 0x120;
        if (hasStatus != 0) {
            FormatText_00511_guess(
                buffer, 0xd34,
                g_alertSink_00511af8_guess->Resolve_guess(context),
                _itoa(state->QueryText_guess(
                          g_formatValue_005118e0_guess, 10,
                          FormatValue_00511_guess(0, 0, 0, 0, 0, 0)),
                      g_formatValue_005118e0_guess, 10));
            pEverQuest->dsp_chat(buffer, 0x113, 1);
        } else {
            FormatText_00511_guess(
                buffer, 0xd36,
                g_alertSink_00511af8_guess->Resolve_guess(context),
                FormatValue_00511_guess(0, 0, 0, 0, 0, 0));
            pEverQuest->dsp_chat(buffer, 0x113, 1);
            result = false;
        }
    }
    return result;
}

// Restores the column layout of both lists from the INI (0x5A1EF0, probably LoadIniListWnd).
// FUNCTION: TITANIUM 0x005119DC
void Object_005117c3_guess::LoadIniInfo_guess() {
    if (state_160_guess != 0) {
        LoadActiveBenefits_guess(state_160_guess, "ActiveBenefitList");
    }
    if (state_164_guess != 0) {
        LoadActiveBenefits_guess(state_164_guess, "BenefitMasterList");
    }
    if (panel_184_guess != 0) {
        panel_184_guess->SetListLayoutA_guess(
            layoutFactory_120_guess.GetLayout_guess("ListLayout"));
    }
}

// Saves the column layout of both lists (0x5A1FE0, probably StoreIniListWnd).
// FUNCTION: TITANIUM 0x00511A39
void Object_005117c3_guess::StoreIniInfo_guess() {
    if (state_160_guess != 0) {
        StoreIniListWnd_guess(state_160_guess, "ActiveBenefitList");
    }
    if (state_164_guess != 0) {
        StoreIniListWnd_guess(state_164_guess, "BenefitMasterList");
    }
    if (panel_184_guess != 0) {
        panel_184_guess->SetListLayoutB_guess(
            layoutFactory_120_guess.GetLayout_guess("ListLayout"));
    }
}

// Puts `text` in GuildDescription when `value` is the benefit selected in the master list.
// FUNCTION: TITANIUM 0x00511A96
void Object_005117c3_guess::SetBenefitText_guess(int value, const char* text) {
    bool shouldSet = (state_164_guess == 0);
    if (state_164_guess != 0) {
        int index = state_164_guess->GetIndex_guess();
        if (index != -1) {
            shouldSet = (state_164_guess->GetValue_guess(index) == value);
        }
    }
    if (shouldSet && flag_15c_guess != 0) {
        flag_15c_guess->SetSTMLText(text, 1, 0);
    }
}

// Enables GuildDonateButton: a coin amount, or an item with a tribute value that is not a bag with items in
// it (string 0xD86).
// FUNCTION: TITANIUM 0x00511AF8
void Report_00511af8_guess::Update_guess() {
    bool allowed = (inverted_1dc_guess == 0);
    int index = 0;
    if (output_170_guess != 0) {
        if (source_1cc_guess == 0) {
            if (fallbackCount_1d4_guess <= 0) {
                allowed = false;
            }
        } else {
            Source_00511af8_guess* source = *source_1cc_guess;
            if (source != 0) {
                if (source->GetItemClass_guess() == 1 && source->GetCount_guess() > 0) {
                    do {
                        if (source->HasValue_guess(index) != 0) {
                            const char* text = g_textLookup_00511af8_guess->GetText_guess(0xd86, 0, 0x113, 1);
                            g_alertSink_00511af8_guess->Show_guess(text);
                            allowed = false;
                        }
                        ++index;
                    } while (index < source->GetCount_guess());
                }
                if (allowed && source->GetLimit_guess() > 0) {
                    allowed = true;
                } else {
                    allowed = false;
                }
            } else {
                allowed = false;
            }
        }
        output_170_guess->enabled_005d_guess = allowed;
    }
}

// Asks for a rebuild on the next frame.
// FUNCTION: TITANIUM 0x005117C3
void Object_005117c3_guess::SetFlag_guess() {
    flag_1b4_guess = 1;
}

// Sets GuildStatusButton from your own guild member entry (+0x264, probably the tribute opt-in).
// FUNCTION: TITANIUM 0x005117CB
void Object_005117c3_guess::SetSelectionState_guess() {
    unsigned char value = 0;
    if (g_selectionData_005117cb_guess->state_288_guess != -1) {
        Result_005117cb_guess* result = g_selectionLookup_005117cb_guess.Find_guess(&g_selectionData_005117cb_guess->name_0120_guess);
        if (result != 0) {
            value = result->value_264_guess;
        }
    }
    if (sink_180_guess != 0) {
        sink_180_guess->SetCheck(value);
    }
}

// FUNCTION: TITANIUM 0x00511816
void Object_005117c3_guess::SelectBenefit_guess(int value) {
    int target = value;
    g_lookup_00511_guess.Begin_guess(target);
    if (state_160_guess != 0) {
        int index = 0;
        int found = -1;
        if (state_160_guess->count_11c_guess > 0) {
            do {
                if (state_160_guess->GetValue_guess(index) == target) {
                    found = index;
                    break;
                }
                ++index;
            } while (index < state_160_guess->count_11c_guess);
        }
        state_160_guess->SetIndex_guess(found);
        state_160_guess->Refresh_guess(found);
    }
    if (state_164_guess != 0) {
        int index = 0;
        int found = -1;
        if (state_164_guess->count_11c_guess > 0) {
            do {
                if (state_164_guess->GetValue_guess(index) == target) {
                    found = index;
                    break;
                }
                ++index;
            } while (index < state_164_guess->count_11c_guess);
        }
        state_164_guess->SetIndex_guess(found);
        state_164_guess->Refresh_guess(found);
    }
    if (flag_15c_guess != 0) {
        g_lookup_00511_guess.RequestGuildTributeDescription_guess(3, target);
    }
}

// Saves the active benefits when tribute is on
// (OP_GuildSaveActiveTributes), sends OP_GuildModifyBenefits, then 0x6516 (no EQEmu name) with both spawn ids, and
// forgets the master.
// FUNCTION: TITANIUM 0x00511BAB
// @early-stop: budget, structural ndiff=15
bool Object_005117c3_guess::LeaveMaster_guess() {
    BenefitPacket_00511_guess packet;
    BenefitListPacket_00511_guess listPacket;
    int currentStats[3];

    g_benefitStatus_00511_guess = 10;
    g_alertSink_00511af8_guess->SavePC_guess(0, 1, 0x14);
    if (g_flagByte_00511f40_guess != 0) {
        int* destination = packet.values_018_guess + 2;
        int* source = g_benefitValues_00511_guess + 1;
        do {
            destination[-2] = source[-1];
            destination[0] = source[0];
            source += 2;
            ++destination;
        } while ((int)source < (int)(g_benefitValues_00511_guess + 5));
        packet.value_014_guess = g_benefitConnection_00511_guess->spawnId_0258_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_GuildSaveActiveTributes, &packet, 0x30, 1);
    }

    listPacket.prefix_000_guess[0] = 0;
    listPacket.value_04c_guess = g_benefitConnection_00511_guess->spawnId_0258_guess;
    EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_GuildModifyBenefits, &listPacket, 0x50, 1);
    if (g_benefitConnection_00511_guess != 0) {
        currentStats[1] = g_benefitConnection_00511_guess->spawnId_0258_guess;
        currentStats[0] = g_selectionValue_00511_guess->spawnId_0258_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905ca0), 0x6516, currentStats, 0x0c, 1);
        g_benefitConnection_00511_guess = 0;
    }

    g_benefitResult_00511_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    StoreIniInfo_guess();
    return true;
}

// Upgrade: raises the master-list benefit one tier unless it is at its last tier.
// FUNCTION: TITANIUM 0x00511CBC
void Object_005117c3_guess::UpdateSelection_guess() {
    int index = state_164_guess->GetIndex_guess();
    if (index != -1) {
        int key = (*container_1a0_guess.At_guess(index))->key_04c_guess;
        int position = (*container_1a0_guess.At_guess(index))->position_050_guess;
        Record_00511_guess* record = g_lookup_00511_guess.Find_guess(key);
        if (record != 0) {
            if (position < record->count_guess - 1) {
                g_lookup_00511_guess.AddGuildTribute_guess(key);
            }
            if (pinstCTributeBenefitWnd_guess != 0) {
                return pinstCTributeBenefitWnd_guess->SetSecond_guess();
            }
        }
    }
}

// Downgrade: drops the selected active benefit.
// FUNCTION: TITANIUM 0x00511D2A
void Object_005117c3_guess::ClearSelection_guess() {
    if (state_160_guess != 0) {
        int index = state_160_guess->GetIndex_guess();
        if (index != -1) {
            g_lookup_00511_guess.LowerGuildTributeTier_guess((*At_guess(index))->key_04c_guess);
            if (pinstCTributeBenefitWnd_guess != 0) {
                return pinstCTributeBenefitWnd_guess->SetSecond_guess();
            }
        }
    }
}

// Sorts the active list by its column mode (0, 1 or 3); the flag at +0x1BC picks the direction.
// FUNCTION: TITANIUM 0x00511D6E
void Object_005117c3_guess::SortSelection_guess() {
    Compare_00511_guess compare = 0;
    switch (mode_1b8_guess) {
    case 3:
        if (compareFlag_1bc_guess != 0) {
            compare = CompareTributeCostThenName_guess;
        } else {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BFFA);
        }
        break;
    case 1:
        if (compareFlag_1bc_guess != 0) {
            compare = CompareTributeTierThenName_guess;
        } else {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BFAF);
        }
        break;
    case 0:
        compare = CompareTributeName_guess;
        if (compareFlag_1bc_guess == 0) {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BF64);
        }
        break;
    }

    int count = count_19c_guess;
    if (count > 0 && compare != 0) {
        Container_00511_guess* list = this;
        if (list->count_guess <= 0 || list->data_guess == 0) {
            return list->Fail_guess();
        }
        qsort(list->data_guess, count, 4, compare);
    }
}

// Sorts the master list by column mode 0-3; the flag at +0x1C4 picks the direction.
// FUNCTION: TITANIUM 0x00511DF7
void SortObject_00511_guess::Sort_guess() {
    Compare_00511_guess compare = 0;
    int count;
    switch (mode_1c0_guess) {
    case 3:
        if (compareFlag_1c4_guess != 0) {
            compare = CompareTributeCostThenName_guess;
        } else {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BFFA);
        }
        break;
    case 2:
        if (compareFlag_1c4_guess != 0) {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056C00C);
        } else {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056C045);
        }
        break;
    case 1:
        if (compareFlag_1c4_guess != 0) {
            compare = CompareTributeTierThenName_guess;
        } else {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BFAF);
        }
        break;
    case 0:
        compare = CompareTributeName_guess;
        if (compareFlag_1c4_guess == 0) {
            compare = (Compare_00511_guess)EQ_ARRAY(char, 0x0056BF64);
        }
        break;
    }

    count = sortCount_1b0_guess;
    if (count > 0 && compare != 0) {
        Container_00511_guess* list = this;
        if (list->count_guess <= 0 || list->data_guess == 0) {
            return list->Fail_guess();
        }
        qsort(list->data_guess, count, 4, compare);
    }
}

// Copies an active benefit's tier into the master-list row of the same benefit.
// FUNCTION: TITANIUM 0x00511E98
void SortObject_00511_guess::UpdateItems_guess(int* values, int position) {
    int i = 0;
    if (count_guess > 0) {
        int* current = values + position + 4;
        do {
            int key = values[0];
            if ((*At_guess(i))->key_04c_guess == key) {
                (*At_guess(i))->position_050_guess = position;
                if (position < values[3] - 1) {
                    ++position;
                    ++current;
                }
                (*At_guess(i))->position_0040_guess = position;
                int value = current[10];
                (*At_guess(i))->value_044_guess = value;
                value = current[0];
                (*At_guess(i))->value_048_guess = value;
            }
            ++i;
        } while (i < count_guess);
    }
}

// Master-list rows are white when they can be upgraded, grey when not. Both buttons also need tribute on and
// +0x27C of the player (0x905CE4) above 0, probably a guild rank check.
// FUNCTION: TITANIUM 0x00511F40
void Object_005117c3_guess::UpdateButtons_guess() {
    flag_1c5_guess = 0;
    flag_1c6_guess = 0;
    if (state_164_guess != 0) {
        Container_00511_guess* list = &container_1a0_guess;
        for (int i = 0; i < list->count_guess; ++i) {
            if (*list->At_guess(i) != 0) {
                int selected = g_selectionData_005117cb_guess->state_27c_guess;
                Record_00511_guess* record = g_lookup_00511_guess.Find_guess((*list->At_guess(i))->key_04c_guess);
                int last = record->count_guess - 1;
                unsigned char usable = ((*list->At_guess(i))->position_050_guess < last) & (selected > 0);
                usable &= g_flagByte_00511f40_guess;
                unsigned long color = usable ? 0xFFFFFFFF : 0xFFC0C0C0;
                for (int j = 0; j < 4; ++j) {
                    state_164_guess->SetCell_guess(i, j, color);
                }
                if (i == state_164_guess->GetIndex_guess()) {
                    flag_1c5_guess = usable;
                }
            }
        }
    }
    if (state_160_guess != 0) {
        flag_1c6_guess = (g_selectionData_005117cb_guess->state_27c_guess > 0 && state_160_guess->GetIndex_guess() != -1 && g_flagByte_00511f40_guess != 0) ? 1 : 0;
    }
    if (out_178_guess != 0) {
        out_178_guess->value_05d_guess = flag_1c6_guess;
    }
    if (out_174_guess != 0) {
        out_174_guess->value_05d_guess = flag_1c5_guess;
    }
}

// Clears the donation: coin amount "0", no selected item, empty value label.
// FUNCTION: TITANIUM 0x0051208F
void Report_00511af8_guess::Reset_guess() {
    source_1cc_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    source_1cc_guess = 0;
    fallbackCount_1d4_guess = 0;
    if (sink_17c_guess != 0) {
        CXStr text(EQ_ARRAY(char, 0x006410A8));
        sink_17c_guess->Slot63_guess(text);
    }
    if (holder_168_guess != 0) {
        Sub_00511af8_guess* sub = holder_168_guess->sub_16c_guess;
        sub->Method_guess(-1);
    }
    if (sink_16c_guess != 0) {
        CXStr text(EQ_ARRAY(char, 0x0063F53F));
        sink_16c_guess->Slot63_guess(text);
    }
    Update_guess();
}

struct OwnerBase_0051216c_guess {
    // EXTERNAL: TITANIUM 0x005A3100 OwnerBase_0051216c_guess::~OwnerBase_0051216c_guess
    virtual ~OwnerBase_0051216c_guess();
    char pad_004_guess[0x188];
};

struct OwnedList_0051216c_guess {
    int count_guess;
    Item_00511_guess** data_guess;
    char pad_008_guess[0x0c];
    // EXTERNAL: TITANIUM 0x004EB924 OwnedList_0051216c_guess::At_guess
    Item_00511_guess** At_guess(int index);
    // EXTERNAL: TITANIUM 0x0050F3F6 OwnedList_0051216c_guess::Reset_guess
    void Reset_guess();
};

// EXTERNAL: TITANIUM 0x00655E28 ??_7Deleter_00512846_guess@@6B@
struct Deleter_00512846_guess : OwnerBase_0051216c_guess {
    OwnedList_0051216c_guess first_18c_guess;
    OwnedList_0051216c_guess second_1a0_guess;
    virtual ~Deleter_00512846_guess();
    void* ScalarDelete_guess(unsigned int flags_guess);
};

// Guild tribute master window destructor: deletes every object held in the two pointer arrays (+0x18C,
// +0x1A0), then empties both arrays (0x0050F3F6).
// FUNCTION: TITANIUM 0x0051216C
// @early-stop: budget, diff ndiff=1
Deleter_00512846_guess::~Deleter_00512846_guess() {
    int firstIndex = 0;
    if (first_18c_guess.count_guess > 0) {
        do {
            operator delete(*first_18c_guess.At_guess(firstIndex));
            ++firstIndex;
        } while (firstIndex < first_18c_guess.count_guess);
    }

    int secondIndex = 0;
    if (second_1a0_guess.count_guess > 0) {
        do {
            operator delete(*second_1a0_guess.At_guess(secondIndex));
            ++secondIndex;
        } while (secondIndex < second_1a0_guess.count_guess);
    }
    second_1a0_guess.Reset_guess();
    first_18c_guess.Reset_guess();
}

// Refills both lists: name, tier (1-based) and the tier's numbers from the benefit record.
// FUNCTION: TITANIUM 0x00512201
void Object_005117c3_guess::RefreshBenefitLists_guess() {
    if (flag_15c_guess != 0) {
        flag_15c_guess->SetSTMLText(EQ_ARRAY(char, 0x0063F53F), 1, 0);
    }
    if (state_160_guess != 0) {
        state_160_guess->DeleteAll_guess();
        for (int i = 0; i < count_19c_guess; ++i) {
            int row;
            {
                CXStr name((*At_guess(i))->name_000_guess);
                row = state_160_guess->AddString_guess(name, -1, (*At_guess(i))->key_04c_guess, 0);
            }
            state_160_guess->SetItemText_guess(row, 1,
                _itoa((*At_guess(i))->position_0040_guess + 1, g_itoaBuffer_guess, 10));
            state_160_guess->SetItemText_guess(row, 2,
                _itoa((*At_guess(i))->value_044_guess, g_itoaBuffer_guess, 10));
        }
    }
    int selected = -1;
    if (state_164_guess != 0) {
        int index = state_164_guess->GetIndex_guess();
        if (index != -1) {
            selected = state_164_guess->GetValue_guess(index);
        }
        state_164_guess->DeleteAll_guess();
        for (int i = 0; i < count_1b0_guess; ++i) {
            int row;
            {
                CXStr name((*container_1a0_guess.At_guess(i))->name_000_guess);
                row = state_164_guess->AddString_guess(name, -1, (*container_1a0_guess.At_guess(i))->key_04c_guess, 0);
            }
            state_164_guess->SetItemText_guess(row, 1,
                _itoa((*container_1a0_guess.At_guess(i))->position_0040_guess + 1, g_itoaBuffer_guess, 10));
            state_164_guess->SetItemText_guess(row, 2,
                _itoa((*container_1a0_guess.At_guess(i))->value_048_guess, g_itoaBuffer_guess, 10));
            state_164_guess->SetItemText_guess(row, 3,
                _itoa((*container_1a0_guess.At_guess(i))->value_044_guess, g_itoaBuffer_guess, 10));
        }
        SelectBenefit_guess(selected);
    }
    UpdateButtons_guess();
}

// An item was put in GuildSelectedItem from inventory slot `slot`. Slots 0-30 are the top-level slots; 31-331
// are bag contents, (slot - 31) / 10 the bag's slot and the remainder the index in it. Shows the item's
// tribute value in GuildValueLabel, 0 for a bag that still holds items.
// FUNCTION: TITANIUM 0x0051256A
void Report_00511af8_guess::SetSlot_guess(int slot, SlotItem_0051256a_guess* item) {
    char message[256];
    char text[256];
    bool allowed = true;
    fallbackCount_1d4_guess = 0;
    source_1cc_guess = 0;
    if (sink_17c_guess != 0) {
        CXStr empty(EQ_ARRAY(char, 0x006410A8));
        sink_17c_guess->Slot63_guess(empty);
    }
    state_1c8_guess = slot;
    if (holder_168_guess != 0) {
        holder_168_guess->sub_16c_guess->SetValue_guess(item->value_038_guess);
    }
    text[0] = 0;
    if (sink_16c_guess != 0) {
        CXStr value(text);
        sink_16c_guess->Slot63_guess(value);
    }
    Source_00511af8_guess* source = 0;
    if (state_1c8_guess < 0x1f) {
        source = g_inventory_0051256a_guess->GetItem_guess(state_1c8_guess);
        source_1cc_guess = g_inventory_0051256a_guess->GetItemSlot_guess(state_1c8_guess);
    } else if (state_1c8_guess <= 0x14b) {
        int bag = (state_1c8_guess - 0x1f) / 10;
        int index = (state_1c8_guess - 0x1f) % 10;
        if (g_inventory_0051256a_guess->GetItem_guess(bag) != 0
            && g_inventory_0051256a_guess->GetItem_guess(bag)->GetItemClass_guess() == 1) {
            Source_00511af8_guess* container = g_inventory_0051256a_guess->GetItem_guess(bag);
            source = container->GetChild_guess(index);
            source_1cc_guess = container->GetChildSlot_guess(index);
        }
    }
    if (source != 0) {
        if (source->GetItemClass_guess() == 1) {
            for (int i = 0; i < source->GetCount_guess(); ++i) {
                if (source->GetChild_guess(i) != 0) {
                    allowed = false;
                }
            }
        }
        if (allowed) {
            reinterpret_cast<Object_005117c3_guess*>(this)->ShowTributeValue_guess(
                reinterpret_cast<State_00511_guess*>(source));
            _itoa(source->GetLimit_guess(), text, 10);
        } else {
            FormatText11_0051256a_guess(message, 0xd86, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message, 0x113, 1);
            _itoa(0, text, 10);
        }
    }
    if (sink_16c_guess != 0) {
        CXStr value(text);
        sink_16c_guess->Slot63_guess(value);
    }
    Update_guess();
}

// LockButton turns guild tribute on or off (OP_GuildModifyBenefits, saving the active benefits first when it
// was on). GuildDonateButton donates the coin amount, or opens the quantity window (0x850C3C, probably
// CQuantityWnd) for the item. GuildCoinButton opens it for platinum. GuildStatusButton sends OP_GuildOptInOut
// with your name. Upgrade and Downgrade need tribute on (else string 0x1791).
// FUNCTION: TITANIUM 0x00512862
// @early-stop: budget, structural ndiff=257
int Report_00511af8_guess::WndNotification_guess(void* sender, unsigned int message, void* data) {
    Object_005117c3_guess* object = reinterpret_cast<Object_005117c3_guess*>(this);

    if (message == 1) {
        if (sender == state_188_guess) {
            bool enabled = true;
            if (g_flagByte_00511f40_guess != 0) {
                BenefitPacket_00511_guess packet;
                int* destination = packet.values_018_guess + 2;
                int* source = g_benefitValues_00511_guess + 1;
                do {
                    destination[-2] = source[-1];
                    destination[0] = source[0];
                    source += 2;
                    ++destination;
                } while ((int)source < (int)(g_benefitValues_00511_guess + 5));
                packet.value_014_guess = g_benefitConnection_00511_guess->spawnId_0258_guess;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildSaveActiveTributes, &packet, 0x30, 1);
                enabled = g_flagByte_00511f40_guess == 0;
            }
            StatusPacket_00512862_guess packet;
            packet.enabled_000_guess = enabled;
            packet.value_04c_guess = g_benefitConnection_00511_guess->spawnId_0258_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildModifyBenefits, &packet, 0x50, 1);
        } else if (sender == state_160_guess || sender == state_164_guess) {
            State_00511_guess* state = reinterpret_cast<State_00511_guess*>(sender);
            int index = state->GetIndex_guess();
            int value = state->GetValue_guess(index);
            object->SelectBenefit_guess(value);
            object->UpdateButtons_guess();
        } else if (sender == output_170_guess) {
            if (fallbackCount_1d4_guess > 0) {
                g_lookup_00511_guess.DonateGuildTributePlatinum_guess(fallbackCount_1d4_guess);
            } else if (source_1cc_guess != 0 && *source_1cc_guess != 0) {
                Source_00511af8_guess* source = *source_1cc_guess;
                if (!source->IsStackable_guess()) {
                    g_lookup_00511_guess.SendGuildTributeDonateItem_guess(state_1c8_guess, 1);
                } else {
                    const Pair_00512862_guess& value = output_170_guess->GetPair_guess();
                    int first = value.first_guess;
                    int second = value.second_guess;
                    eventState_1d0_guess = 0;
                    pinstCQuantityWnd_guess->Function_0054d976_guess(this,
                        source->value_048_guess, source->value_048_guess,
                        first, second, 1);
                }
            }
        } else if (sender == sink_17c_guess) {
            Reset_guess();
            eventState_1d0_guess = 1;
            const Pair_00512862_guess& value = sink_17c_guess->GetPair_guess();
            int first = value.first_guess;
            int second = value.second_guess;
            CharInfo2View_00512862_guess* info = reinterpret_cast<CharInfo2View_00512862_guess*>(
                pCharData->GetCharInfo2());
            pinstCQuantityWnd_guess->Function_0054d976_guess(this,
                info->value_11d4_guess, info->value_11d4_guess,
                first, second, 1);
            return HandleOther_guess(sender, message, data);
        } else if (sender == out_178_guess) {
            if (g_flagByte_00511f40_guess != 0) {
                object->ClearSelection_guess();
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x1791, 0), 0x0f, 1);
            }
        } else if (sender == out_174_guess) {
            if (g_flagByte_00511f40_guess != 0) {
                object->UpdateSelection_guess();
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x1791, 0), 0x0f, 1);
            }
        } else if (sender == sink_180_guess) {
            NotificationPacket_00512862_guess packet;
            packet.value_000_guess = g_selectionData_005117cb_guess->state_288_guess;
            packet.value_004_guess = sink_180_guess->value_128_guess;
            CopyInfo_00512862_guess(packet.data_008_guess, &g_selectionData_005117cb_guess->name_0120_guess);
            packet.value_04c_guess = g_benefitConnection_00511_guess->spawnId_0258_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_GuildOptInOut, &packet, 0x50, 1);
        } else {
            return HandleOther_guess(sender, message, data);
        }
    // 0x1F: the quantity window's answer, an item count (+0x1D0 = 0) or a coin amount (+0x1D0 = 1).
    } else if (message == 0x1f) {
        if (eventState_1d0_guess == 0) {
            if (source_1cc_guess != 0 && *source_1cc_guess != 0) {
                g_lookup_00511_guess.SendGuildTributeDonateItem_guess(state_1c8_guess, *(int*)data);
            }
        } else if (eventState_1d0_guess == 1) {
            fallbackCount_1d4_guess = *(int*)data;
            if (sink_17c_guess != 0) {
                CXStr text(_itoa(fallbackCount_1d4_guess, g_itoaBuffer_guess, 10));
                sink_17c_guess->Slot63_guess(text);
            }
            Update_guess();
        }
    // 4: a double click on a list row (probably) upgrades or downgrades it.
    } else if (message == 4) {
        if (g_flagByte_00511f40_guess == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x1791, 0), 0x0f, 1);
        } else if (sender == state_160_guess && flag_1c6_guess != 0) {
            object->ClearSelection_guess();
        } else if (sender == state_164_guess && flag_1c5_guess != 0) {
            object->UpdateSelection_guess();
        } else {
            return HandleOther_guess(sender, message, data);
        }
    // 0x0F: a column header click; the same column again flips the sort direction.
    } else if (message == 0x0f) {
        int dataValue = (int)data;
        if (sender == state_160_guess) {
            int mode = mode_1b8_guess;
            if (dataValue == 0) {
                mode = 0;
            } else if (dataValue == 1) {
                mode = 1;
            } else if (dataValue == 2) {
                mode = 3;
            }
            if (mode == mode_1b8_guess) {
                compareFlag_1bc_guess = compareFlag_1bc_guess == 0;
            } else {
                compareFlag_1bc_guess = 1;
            }
            mode_1b8_guess = mode;
            object->SortSelection_guess();
        } else if (sender == state_164_guess) {
            int mode = sortMode_1c0_guess;
            if (dataValue == 0) {
                mode = 0;
            } else if (dataValue == 1) {
                mode = 1;
            } else if (dataValue == 2) {
                mode = 2;
            } else if (dataValue == 3) {
                mode = 3;
            }
            if (mode == sortMode_1c0_guess) {
                flag_1c4_guess = flag_1c4_guess == 0;
            } else {
                flag_1c4_guess = 1;
            }
            sortMode_1c0_guess = mode;
            reinterpret_cast<SortObject_00511_guess*>(this)->Sort_guess();
        } else {
            return HandleOther_guess(sender, message, data);
        }
        object->RefreshBenefitLists_guess();
    } else {
        return HandleOther_guess(sender, message, data);
    }
    return 0;
}

// Scalar deleting destructor of the guild tribute master window (vtable 0x655E28 slot 1): runs the
// destructor (0x0051216C) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00512846
void* Deleter_00512846_guess::ScalarDelete_guess(unsigned int flags_guess) {
    this->Deleter_00512846_guess::~Deleter_00512846_guess();
    if (flags_guess & 1) {
        operator delete(this);
    }
    return this;
}

// Rebuilds both lists: every benefit at tier 0 for the master list, then the two active ones.
// FUNCTION: TITANIUM 0x00512D0F
void Object_005117c3_guess::Rebuild_guess() {
    int i;
    count_1b0_guess = 0;
    for (i = 0; i <= g_recordCount_00512d0f_guess - 1; ++i) {
        Record_00511_guess* record = g_lookup_00511_guess.Find_guess(i);
        if (record != 0) {
            if (count_1b0_guess >= container_1a0_guess.count_guess) {
                Item_00511_guess* empty = 0;
                while (count_1b0_guess >= container_1a0_guess.count_guess) {
                    container_1a0_guess.Insert_guess(container_1a0_guess.count_guess, &empty);
                }
            }
            if (*container_1a0_guess.At_guess(count_1b0_guess) == 0) {
                Item_00511_guess* item = new Item_00511_guess;
                *container_1a0_guess.At_guess(count_1b0_guess) = item;
            }
            strcpy((*container_1a0_guess.At_guess(count_1b0_guess))->name_000_guess, record->name_004_guess);
            int value = record->values_038_guess[0];
            (*container_1a0_guess.At_guess(count_1b0_guess))->value_044_guess = value;
            (*container_1a0_guess.At_guess(count_1b0_guess))->position_0040_guess = 0;
            value = record->values_010_guess[0];
            (*container_1a0_guess.At_guess(count_1b0_guess))->value_048_guess = value;
            (*container_1a0_guess.At_guess(count_1b0_guess))->position_050_guess = -1;
            (*container_1a0_guess.At_guess(count_1b0_guess))->key_04c_guess = i;
            ++count_1b0_guess;
        } else if (count_1b0_guess < container_1a0_guess.count_guess) {
            delete *container_1a0_guess.At_guess(count_1b0_guess);
            *container_1a0_guess.At_guess(count_1b0_guess) = 0;
        }
    }

    count_19c_guess = 0;
    for (i = 0; i < 2; ++i) {
        int key = g_slotPairs_00512d0f_guess[i].key_guess;
        int index = g_slotPairs_00512d0f_guess[i].index_guess;
        Record_00511_guess* record = g_lookup_00511_guess.Find_guess(key);
        if (record != 0) {
            if (count_19c_guess >= count_guess) {
                Item_00511_guess* empty = 0;
                while (count_19c_guess >= count_guess) {
                    Insert_guess(count_guess, &empty);
                }
            }
            if (*At_guess(count_19c_guess) == 0) {
                Item_00511_guess* item = new Item_00511_guess;
                *At_guess(count_19c_guess) = item;
            }
            strcpy((*At_guess(count_19c_guess))->name_000_guess, record->name_004_guess);
            int value = record->values_038_guess[index];
            (*At_guess(count_19c_guess))->value_044_guess = value;
            (*At_guess(count_19c_guess))->position_0040_guess = index;
            (*At_guess(count_19c_guess))->position_050_guess = index;
            (*At_guess(count_19c_guess))->key_04c_guess = key;
            ++count_19c_guess;
            ((SortObject_00511_guess*)this)->UpdateItems_guess((int*)record, index);
        } else if (count_19c_guess < count_guess) {
            delete *At_guess(count_19c_guess);
            *At_guess(count_19c_guess) = 0;
        }
    }
    SortSelection_guess();
    ((SortObject_00511_guess*)this)->Sort_guess();
    RefreshBenefitLists_guess();
    flag_1b4_guess = 0;
}

struct WorldEntry_00512fe5_guess {
    char pad_000_guess[0x252];
    char code_252_guess;
};

struct UpdateClock_00512fe5_guess {
    // EXTERNAL: TITANIUM 0x00439D16 UpdateClock_00512fe5_guess::PlayerDistance_guess
    float PlayerDistance_guess(void* first_guess, void* second_guess, float scale_guess);
};

#define g_entry_00512fe5_guess EQ_GLOBAL(WorldEntry_00512fe5_guess*, 0x00905D10)
#define g_clock_00512fe5_guess EQ_GLOBAL(UpdateClock_00512fe5_guess*, 0x00905D24)
#define g_resetCounter_00512fe5_guess EQ_GLOBAL(int, 0x009248D4)

// It needs the NPC's class (+0x252) to be '@'
// (64, the guild tribute master class in EQEmu) and to stand within 20 units; returns whether it opened.
// FUNCTION: TITANIUM 0x00512FE5
bool Report_00511af8_guess::OpenForMaster_guess() {
    bool active = (g_lookup_00511_guess.Check_guess() && value_124_guess != 0);
    if (g_entry_00512fe5_guess != 0 && g_entry_00512fe5_guess->code_252_guess == '@') {
        if (g_clock_00512fe5_guess->PlayerDistance_guess(g_entry_00512fe5_guess, g_selectionData_005117cb_guess, 1.0f) > 20.0f) {
            active = false;
        }
    } else {
        active = false;
    }
    if (holder_168_guess != 0) {
        Sub_00511af8_guess* sub = holder_168_guess->sub_16c_guess;
        sub->Method_guess(-1);
    }
    if (output_170_guess != 0) {
        output_170_guess->enabled_005d_guess = 0;
    }
    if (sink_17c_guess != 0) {
        CXStr text(EQ_ARRAY(char, 0x006410A8));
        sink_17c_guess->Slot63_guess(text);
    }
    inverted_1dc_guess = 0;
    Update_guess();
    if (active) {
        ((Object_005117c3_guess*)this)->Rebuild_guess();
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x35, 0);
        }
    } else {
        g_resetCounter_00512fe5_guess = 0;
    }
    Reset_guess();
    ((Object_005117c3_guess*)this)->SetSelectionState_guess();
    return active;
}

struct Clock_00513107_guess {
    char pad_000_guess[0x148];
    unsigned int tick_148_guess;
};

struct Char_00513107_guess {
    char pad_000_guess[0xe10];
    unsigned char value_e10_guess;
};

#define g_9248d0_00513107_guess EQ_GLOBAL(int, 0x009248D0)

// Every 500 ms while shown: LockButton reads string 0x1790 when tribute is on, 0x178F when off, and is
// enabled only when pCharData +0xE10 (probably the guild rank, as in tu_180) is above 0. Closes the window
// when the master is gone or farther than 20 units.
// FUNCTION: TITANIUM 0x00513107
void Object_005117c3_guess::ProcessFrame_guess() {
    unsigned char show = ((CXWnd*)this)->Show;
    if (show != 0) {
        if (flag_1b4_guess != 0) {
            Rebuild_guess();
        }
        if (((Clock_00513107_guess*)g_clock_00512fe5_guess)->tick_148_guess >= limit_1d8_guess) {
            if (state_188_guess != 0) {
                if (g_flagByte_00511f40_guess != 0) {
                    CXStr text(pStringTable->getString(0x1790, 0));
                    state_188_guess->Slot63_guess(text);
                } else {
                    CXStr text(pStringTable->getString(0x178f, 0));
                    state_188_guess->Slot63_guess(text);
                }
                ((CXWnd*)state_188_guess)->Enabled = ((Char_00513107_guess*)pCharData)->value_e10_guess > 0;
            }
            limit_1d8_guess = ((Clock_00513107_guess*)g_clock_00512fe5_guess)->tick_148_guess + 500;
            if (g_entry_00512fe5_guess == 0 ||
                (g_clock_00512fe5_guess->PlayerDistance_guess(g_entry_00512fe5_guess, g_selectionData_005117cb_guess, 0.0f) > 20.0f &&
                 g_9248d0_00513107_guess == 0)) {
                ((Panel_00511_guess*)this)->Slot34_guess();
            }
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

struct GuildWindowBase_00513266_guess {
    virtual void Slot00_guess() = 0;
    // EXTERNAL: TITANIUM 0x005A3100 ??1GuildWindowBase_00513266_guess@@UAE@XZ
    virtual ~GuildWindowBase_00513266_guess();
    char pad_004_guess[0x62];
    unsigned char flag_066_guess;
    char pad_067_guess[0xbd];
    int flag_124_guess;
    char pad_128_guess[0x30];
    int value_158_guess;
    // EXTERNAL: TITANIUM 0x005A3850 ??0GuildWindowBase_00513266_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    GuildWindowBase_00513266_guess(CXWnd* parent, const CXStr& screen, int flags, int version, char* blockName);
};

struct BenefitList_00513266_guess {
    char pad_000_guess[0x15c];
    unsigned char enabled_15c_guess;
    char pad_15d_guess[0x0f];
    unsigned int color_16c_guess;
    // EXTERNAL: TITANIUM 0x00597C60 BenefitList_00513266_guess::SetColors
    void SetColors(int first, unsigned int second, unsigned int third);
    // EXTERNAL: TITANIUM 0x005982E0 BenefitList_00513266_guess::SetColumnJustification
    void SetColumnJustification(int column, int enabled);
};

struct InlineBlock_00513266_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    unsigned char enabled_guess;
    char pad_00d_guess[3];
    InlineBlock_00513266_guess() {
        second_guess = 0;
        first_guess = 0;
        third_guess = 0;
        enabled_guess = 1;
    }
};

struct DragItemManager_00513266_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 DragItemManager_00513266_guess::GetChild_guess
    void* GetChild_guess(const CXStr& name);
};

struct DragItem_00513266_guess {
    char pad_000_guess[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0DragItem_00513266_guess@@QAE@XZ
    DragItem_00513266_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B DragItem_00513266_guess::SetItem_guess
    void SetItem_guess(void* item);
    // EXTERNAL: TITANIUM 0x005B1AB0 DragItem_00513266_guess::SetMode_guess
    void SetMode_guess(int mode);
};

struct SelectedItemControl_00513266_guess {
    char pad_000_guess[0x16c];
    DragItem_00513266_guess* dragItem_16c_guess;
};

#define g_dragItemManager_00513266_guess EQ_GLOBAL(DragItemManager_00513266_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x00655E28 ??_7GuildTributeMasterWnd_00513266_guess@@6B@
struct GuildTributeMasterWnd_00513266_guess : GuildWindowBase_00513266_guess {
    CXWnd* description_15c_guess;
    BenefitList_00513266_guess* activeBenefitList_160_guess;
    BenefitList_00513266_guess* benefitMasterList_164_guess;
    CXWnd* selectedItem_168_guess;
    int valueLabel_16c_guess;
    CXWnd* donateButton_170_guess;
    CXWnd* upgradeButton_174_guess;
    CXWnd* downgradeButton_178_guess;
    CXWnd* coinButton_17c_guess;
    CXWnd* statusButton_180_guess;
    CXWnd* layout_184_guess;
    CXWnd* lockButton_188_guess;
    InlineBlock_00513266_guess block_18c_guess;
    int count_19c_guess;
    InlineBlock_00513266_guess block_1a0_guess;
    int value_1b0_guess;
    unsigned char flag_1b4_guess;
    char pad_1b5_guess[0x03];
    int value_1b8_guess;
    unsigned char flag_1bc_guess;
    char pad_1bd_guess[0x03];
    int value_1c0_guess;
    unsigned char flag_1c4_guess;
    unsigned char flag_1c5_guess;
    unsigned char flag_1c6_guess;
    char pad_1c7_guess;
    unsigned int value_1c8_guess;
    int value_1cc_guess;
    char pad_1d0_guess[0x04];
    int value_1d4_guess;
    unsigned int value_1d8_guess;

    GuildTributeMasterWnd_00513266_guess(CXWnd* parent);
};

// Guild tribute master window constructor: finds its controls, sets up the active-benefit and
// benefit-master lists, gives the selected-item slot an A_DragItem icon, then calls 0x005119DC, which
// reloads both lists by name and the list layout from the INI.
// FUNCTION: TITANIUM 0x00513266
// @early-stop: budget, structural ndiff=119
GuildTributeMasterWnd_00513266_guess::GuildTributeMasterWnd_00513266_guess(CXWnd* parent)
    : GuildWindowBase_00513266_guess(parent, "GuildTributeMasterWnd", -1, 1, 0) {
    value_1c8_guess |= 0xffffffff;

    description_15c_guess = 0;
    activeBenefitList_160_guess = 0;
    benefitMasterList_164_guess = 0;
    valueLabel_16c_guess = 0;
    selectedItem_168_guess = 0;
    donateButton_170_guess = 0;
    upgradeButton_174_guess = 0;
    downgradeButton_178_guess = 0;
    coinButton_17c_guess = 0;
    statusButton_180_guess = 0;
    layout_184_guess = 0;
    lockButton_188_guess = 0;
    value_1b8_guess = 0;
    flag_1bc_guess = 1;
    value_1c0_guess = 0;
    flag_1c4_guess = 1;
    flag_1c6_guess = 0;
    flag_1c5_guess = 0;
    flag_1b4_guess = 0;
    count_19c_guess = 0;
    value_1b0_guess = 0;
    value_1cc_guess = 0;
    value_1d8_guess = 0;
    value_1d4_guess = 0;

    if (flag_124_guess != 0) {
        flag_066_guess |= 1;
        value_158_guess = 0x35;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();

        description_15c_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildDescription");
        valueLabel_16c_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("GuildValueLabel");
        selectedItem_168_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildSelectedItem");
        donateButton_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildDonateButton");
        downgradeButton_178_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildDowngradeButton");
        upgradeButton_174_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildUpgradeButton");
        coinButton_17c_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildCoinButton");
        statusButton_180_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildStatusButton");
        layout_184_guess = ((CSidlScreenWnd*)this)->GetChildItem("GuildLayout");
        lockButton_188_guess = ((CSidlScreenWnd*)this)->GetChildItem("LockButton");
        activeBenefitList_160_guess = (BenefitList_00513266_guess*)((CSidlScreenWnd*)this)->GetChildItem("GuildActiveBenefitList");
        if (activeBenefitList_160_guess != 0) {
            activeBenefitList_160_guess->SetColors(-1, 0xffffff00, 0xff808080);
            activeBenefitList_160_guess->SetColumnJustification(0, 0);
            activeBenefitList_160_guess->SetColumnJustification(1, 1);
            activeBenefitList_160_guess->SetColumnJustification(2, 1);
            activeBenefitList_160_guess->color_16c_guess = 0xff8aa3ff;
            activeBenefitList_160_guess->enabled_15c_guess = 1;
        }

        benefitMasterList_164_guess = (BenefitList_00513266_guess*)((CSidlScreenWnd*)this)->GetChildItem("GuildBenefitMasterList");
        if (benefitMasterList_164_guess != 0) {
            benefitMasterList_164_guess->SetColors(-1, 0xffffff00, 0xff808080);
            benefitMasterList_164_guess->SetColumnJustification(0, 0);
            benefitMasterList_164_guess->SetColumnJustification(1, 1);
            benefitMasterList_164_guess->SetColumnJustification(2, 1);
            benefitMasterList_164_guess->SetColumnJustification(3, 1);
            benefitMasterList_164_guess->color_16c_guess = 0xff8aa3ff;
            benefitMasterList_164_guess->enabled_15c_guess = 1;
        }

        if (selectedItem_168_guess != 0) {
            void* item = g_dragItemManager_00513266_guess->GetChild_guess("A_DragItem");
            DragItem_00513266_guess* dragItem = new DragItem_00513266_guess;
            if (dragItem != 0) {
                dragItem->SetItem_guess(item);
                dragItem->SetMode_guess(-1);
            }
            ((SelectedItemControl_00513266_guess*)selectedItem_168_guess)->dragItem_16c_guess = dragItem;
        }
        ((Object_005117c3_guess*)this)->LoadIniInfo_guess();
    }
}
