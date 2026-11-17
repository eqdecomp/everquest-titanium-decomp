// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 207: a hint from compare/tumap.py.
// The selector bar (SelectorWindow: one toggle button per main window, with a blinking new-mail button)
// and the respawn-choice list of RespawnWnd (message 0x11D, no EQEmu name in Titanium). The mail manager
// comes from pEverQuest (g_service_guess) via GetMailManager_guess (0x00495250); CSelectorWndView_guess and
// CSelectorWndObserverView_guess are views of CSelectorWnd_guess (its observer sits at +0x15C).
#include "titanium/eqaddr.h"

#include "titanium/core_decls.h"
struct Object_guess
{
    virtual void RefreshCounts_guess();
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

    char pad_004[0x59];
    char state_05D;
    unsigned int flags_060_guess;
    char pad_064[0xf4];
    Object_guess* field_158_guess;
    Object_guess* field_15C_guess;
    Object_guess* field_160_guess;
    Object_guess* field_164_guess;
    Object_guess* field_168_guess;

    // EXTERNAL: TITANIUM 0x00597BE0 Object_guess::FUN_00597be0_guess
    int FUN_00597be0_guess();
    // EXTERNAL: TITANIUM 0x00597ED0 Object_guess::FUN_00597ed0_guess
    int FUN_00597ed0_guess(int value);
    // EXTERNAL: TITANIUM 0x00597C60 Object_guess::FUN_00597c60_guess
    void FUN_00597c60_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x0059B800 Object_guess::FUN_0059b800_guess
    void FUN_0059b800_guess(struct LocalData_guess* value_guess);
    // EXTERNAL: TITANIUM 0x0059DBF0 Object_guess::FUN_0059dbf0_guess
    void FUN_0059dbf0_guess(int value);
    // EXTERNAL: TITANIUM 0x005BB140 Object_guess::FUN_005bb140_guess
    void FUN_005bb140_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00598580 Object_guess::FUN_00598580_guess
    void FUN_00598580_guess();
};

struct CRespawnWndView_guess
{
    char pad_000[0x15c];
    Object_guess* field_15C;
    Object_guess* field_160;
    int field_164;
    int field_168;

    int WndNotification_guess(Object_guess* selected, int mode, int unused);
    void InitRespawnList_guess(int first, int second);
    char FUN_005531d2_guess();
    void AddRespawnOption_guess(bool flag_guess, int value_guess, int id_guess,
        int unknown_00c_guess, int unknown_010_guess, int unknown_014_guess,
        int unknown_018_guess, const char* text_guess);
    // EXTERNAL: TITANIUM 0x005A2230 CRespawnWndView_guess::FUN_005a2230_guess
    int FUN_005a2230_guess(Object_guess* first, int second, int third);
    char AboutToHide_guess();
};

struct CollectionEntry_guess
{
    int unknown_000_guess;
    unsigned int value_004;
    int kind_008;
};

struct CollectionArray_guess
{
    char pad_000[0xc];
    int begin_00c;
    int count_010;
};

struct CollectionIterator_guess
{
    CollectionArray_guess* array_000;
    int index_004;

    // EXTERNAL: TITANIUM 0x00425170 CollectionIterator_guess::Deref_guess
    CollectionEntry_guess*& Deref_guess() const;
    // EXTERNAL: TITANIUM 0x00425196 CollectionIterator_guess::NotEqual_guess
    bool NotEqual_guess(const CollectionIterator_guess& other_guess) const;
};

struct NodeIter_guess
{
    int* node_000;

    NodeIter_guess(int* node) : node_000(node) {}
};

struct Collection_guess
{
    char pad_000[4];
    int* field_004_guess;
    char pad_008[0x1c];
    CollectionArray_guess array_024;
    char pad_038[0x18];
    unsigned char field_050_guess;

    // EXTERNAL: TITANIUM 0x00518B72 Collection_guess::FUN_00518b72_guess
    void FUN_00518b72_guess(int* value);
    NodeIter_guess Begin_guess()
    {
        return NodeIter_guess((int*)*field_004_guess);
    }
    // EXTERNAL: TITANIUM 0x00518D4A Collection_guess::FUN_00518d4a_guess
    void FUN_00518d4a_guess(NodeIter_guess first, int* second);
};

struct CSelectorWndObserverView_guess
{
    char pad_000[0x38];
    unsigned int newestMailTime_0038_guess;

    void OnMailChanged_guess(Collection_guess* first_guess, int* second_guess);
};

struct Service_guess
{
    char pad_000[0x834];
    int field_834_guess;

    // EXTERNAL: TITANIUM 0x00495250 Service_guess::GetMailManager_guess
    Collection_guess* GetMailManager_guess();
};

#define g_service_guess EQ_GLOBAL(Service_guess*, 0x00988DF0)

struct PrimaryBase_guess
{
    virtual void RefreshCounts_guess();
    // EXTERNAL: TITANIUM 0x005A3850 PrimaryBase_guess::PrimaryBase_guess
    PrimaryBase_guess(int id_guess, const struct UiText_guess& text_guess,
        int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x005A3100 PrimaryBase_guess::~PrimaryBase_guess
    virtual ~PrimaryBase_guess();
    char pad_004[0x14];
    unsigned char field_018_guess;
    char pad_019[0x43];
    unsigned char show_005c_guess;
    char pad_05D[3];
    unsigned int field_060_guess;
    unsigned int windowStyle_0064_guess;
    char pad_068[0xbc];
    Object_guess* field_124_guess;
    char pad_128[0x34];
};

struct UiText_guess
{
    int value_000_guess;

    // EXTERNAL: TITANIUM 0x00571E00 UiText_guess::SetText_guess
    void SetText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 UiText_guess::Release_guess
    void Release_guess(int value_guess);
    UiText_guess(const char* text_guess)
    {
        SetText_guess(text_guess);
    }
    ~UiText_guess()
    {
        if (value_000_guess != 0)
        {
            Release_guess(value_000_guess);
        }
        value_000_guess = 0;
    }
};

struct SecondaryBase_guess
{
    virtual void RefreshCounts_guess();
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7SecondaryBase_guess@@6B@
// EXTERNAL: TITANIUM 0x0065C518 ??_7CSelectorWnd_guess@@6BPrimaryBase_guess@@@
// EXTERNAL: TITANIUM 0x0065C638 ??_7CSelectorWnd_guess@@6BSecondaryBase_guess@@@
struct CSelectorWnd_guess : PrimaryBase_guess, SecondaryBase_guess
{
    // EXTERNAL: TITANIUM 0x005A25B0 CSelectorWnd_guess::FUN_005a25b0_guess
    void FUN_005a25b0_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CSelectorWnd_guess::FUN_005a0e50_guess
    void FUN_005a0e50_guess();
    // EXTERNAL: TITANIUM 0x005A1E10 CSelectorWnd_guess::FUN_005a1e10_guess
    Object_guess* FUN_005a1e10_guess(UiText_guess* text_guess);

    Object_guess* mailBtnNormal_0160_guess;
    Object_guess* mailBtnPressed_0164_guess;
    Object_guess* mailBtnFlyby_0168_guess;
    Object_guess* mailBtnPressedFlyby_016c_guess;
    Object_guess* gotMailBtnNormal_0170_guess;
    Object_guess* gotMailBtnPressed_0174_guess;
    Object_guess* gotMailBtnFlyby_0178_guess;
    Object_guess* gotMailBtnPressedFlyby_017c_guess;
    Object_guess* redMailBtnNormal_0180_guess;
    Object_guess* redMailBtnPressed_0184_guess;
    Object_guess* redMailBtnFlyby_0188_guess;
    Object_guess* redMailBtnPressedFlyby_018c_guess;
    Object_guess* mailBtnDisabled_0190_guess;
    int field_194_guess;
    int flashCount_0198_guess;
    Object_guess* selectorFields_19C_guess[16];
    int selectorIds_1dc_guess[16];
    int lastButtonUpdateTime_021c_guess;

    CSelectorWnd_guess(int id_guess);
    virtual ~CSelectorWnd_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CSelectorWnd_guess::FUN_005a2230_guess
    int FUN_005a2230_guess(Object_guess* selected_guess, int mode_guess, int unused_guess);
    // EXTERNAL: TITANIUM 0x0059D080 CSelectorWnd_guess::FUN_0059d080_guess
    void FUN_0059d080_guess(int value_guess);
    int WndNotification_guess(Object_guess* selected_guess, int mode_guess, int unused_guess);
    void UpdateKeyLabels_guess();
    void OnProcessFrame_guess();
    void* ScalarDeletingDestructor_guess(unsigned char flags);
};

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int value_guess, int first_guess, int second_guess);

struct ResourceManager_guess
{
    // EXTERNAL: TITANIUM 0x005B44A0 ResourceManager_guess::FUN_005b44a0_guess
    Object_guess* FUN_005b44a0_guess(UiText_guess* text_guess);
};

struct FlagManager_guess
{
    // EXTERNAL: TITANIUM 0x004BC547 FlagManager_guess::IsMeleeClass_guess
    unsigned char IsMeleeClass_guess();
};

#define g_resourceManager_guess EQ_GLOBAL(ResourceManager_guess*, 0x0099D3F4)
#define g_selectorFlagA_guess EQ_GLOBAL(int, 0x009247A0)
#define g_selectorFlagB_guess EQ_GLOBAL(int, 0x009247A4)
#define g_mailEnabled_guess EQ_GLOBAL(unsigned char, 0x00923D65)
#define g_flagManager_guess EQ_GLOBAL(FlagManager_guess*, 0x00905D00)

#define GET_SELECTOR_guess(field, text) \
    { UiText_guess text_guess(text); \
      field = FUN_005a1e10_guess(&text_guess); }
#define GET_MAIL_guess(field, text) \
    { UiText_guess text_guess(text); \
      field = g_resourceManager_guess->FUN_005b44a0_guess(&text_guess); }

// EXTERNAL: TITANIUM 0x0060D0D5 _free
void __cdecl _free(void* memory);

#define g_messageTarget_guess EQ_GLOBAL(int, 0x00905CA0)

// Select clicked with a row chosen: sends message 0x11D with that row's option id and disables the list
// and the button until the server answers.
// FUNCTION: TITANIUM 0x00552121
int CRespawnWndView_guess::WndNotification_guess(Object_guess* selected, int mode, int unused)
{
    if (mode == 1 && selected == field_15C && field_160 != 0)
    {
        int index = field_160->FUN_00597be0_guess();
        if (index >= 0)
        {
            int value = field_160->FUN_00597ed0_guess(index);
            EQSendMessage(&g_messageTarget_guess, 0x11d, &value, 4, 1);
            field_160->FUN_00597c60_guess(-1, 0xffffff00, 0xffffff00);
            field_160->state_05D = 0;
            field_15C->state_05D = 0;
            return 1;
        }
    }
    return FUN_005a2230_guess(selected, mode, unused);
}

// Empties the respawn list (yellow text, grey when disabled), enables it, disables Select and clears the
// two header values.
// FUNCTION: TITANIUM 0x005521B6
void __fastcall ResetRespawnList_guess(CRespawnWndView_guess* self)
{
    if (self->field_160 != 0)
    {
        self->field_160->FUN_00597c60_guess(-1, 0xffffff00, 0xff808080);
        self->field_160->state_05D = 1;
        self->field_160->Slot76_guess();
    }
    if (self->field_15C != 0)
    {
        self->field_15C->state_05D = 0;
    }
    self->field_164 = 0;
    self->field_168 = 0;
}

// Starts a new 0x11D respawn offer: empties the list and keeps the two header values the message carries
// (+0x164, +0x168; meaning not known).
// FUNCTION: TITANIUM 0x0055220A
void CRespawnWndView_guess::InitRespawnList_guess(int first, int second)
{
    ResetRespawnList_guess(this);
    field_164 = first;
    field_168 = second;
}

// EXTERNAL: TITANIUM 0x005A3100 FUN_005a3100_guess
void __cdecl FUN_005a3100_guess(void);

// Thunk to the CSidlScreenWnd destructor.
// FUNCTION: TITANIUM 0x0055222A
void __cdecl DestroySidlScreenWnd_guess(void)
{
    FUN_005a3100_guess();
}

struct LocalText_guess
{
    int field_000_guess;
    int field_004_guess;

    // EXTERNAL: TITANIUM 0x00571FC0 LocalText_guess::SetText_guess
    void SetText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x004482FB LocalText_guess::~LocalText_guess
    ~LocalText_guess();
};

struct LocalData_guess
{
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    unsigned char field_00C_guess;
    char pad_00D[3];
    int field_010_guess;

    // EXTERNAL: TITANIUM 0x0042D7A7 LocalData_guess::Prepare_guess
    void Prepare_guess(int value_guess, int* output_guess);
    // EXTERNAL: TITANIUM 0x0042D7E5 LocalData_guess::~LocalData_guess
    ~LocalData_guess();
};

struct LocalState_guess
{
    int field_000_guess;
    unsigned char field_004_guess;
    unsigned char field_005_guess;
    char pad_006[2];
    int field_008_guess;
};

struct TextService_guess
{
    // EXTERNAL: TITANIUM 0x005FA1C0 TextService_guess::Convert_guess
    void Convert_guess(int id_guess, char* output_guess, int option_guess);
};

#define g_textService_guess EQ_GLOBAL(TextService_guess*, 0x00905CC0)

// Adds one respawn option row: '*' when it is the server's default, the option name, and the zone name
// from the zone list (0x905CC0); the row's item data is the option id.
// FUNCTION: TITANIUM 0x0055222F
// @early-stop: budget, structural ndiff=47
void CRespawnWndView_guess::AddRespawnOption_guess(bool flag_guess, int value_guess, int id_guess,
    int unknown_00c_guess, int unknown_010_guess, int unknown_014_guess,
    int unknown_018_guess, const char* text_guess)
{
    if (field_160 != 0)
    {
        LocalData_guess data_guess = { 0, 0, 0, 1, { 0, 0, 0 }, 0 };
        LocalState_guess state_guess = { -1, 0, 1, { 0, 0 }, 0 };
        LocalText_guess text_value_guess = { 0, -1 };
        if (flag_guess)
        {
            text_value_guess.SetText_guess(EQ_ARRAY(const char, 0x0063FAF8));
        }
        data_guess.Prepare_guess(data_guess.field_000_guess, &state_guess.field_008_guess);
        text_value_guess.SetText_guess(text_guess);
        data_guess.Prepare_guess(data_guess.field_000_guess, &state_guess.field_008_guess);
        char output_guess[80] = { 0 };
        g_textService_guess->Convert_guess(id_guess, output_guess, 1);
        text_value_guess.SetText_guess(output_guess);
        data_guess.Prepare_guess(data_guess.field_000_guess, &state_guess.field_008_guess);
        data_guess.field_010_guess = value_guess;
        field_160->FUN_0059b800_guess(&data_guess);
    }
}

struct CSelectorWndView_guess
{
    char pad_000[0x15c];
    CSelectorWndObserverView_guess inner_15c_guess;
    int value_198;

    // EXTERNAL: TITANIUM 0x00552751 CSelectorWndView_guess::UpdateKeyLabels_guess
    void UpdateKeyLabels_guess();
    unsigned int GetNewestMailTime_guess();
    int StartMailBlink_guess();
    char AboutToShow_guess();
};

struct ValueSource_guess
{
    // EXTERNAL: TITANIUM 0x005BA300 ValueSource_guess::GetValue_guess
    int GetValue_guess();
};

struct SlotManager_guess
{
    // EXTERNAL: TITANIUM 0x004B2459 SlotManager_guess::FUN_004b2459_guess
    ValueSource_guess* FUN_004b2459_guess(int id);
    // EXTERNAL: TITANIUM 0x004B244F SlotManager_guess::FUN_004b244f_guess
    ValueSource_guess* FUN_004b244f_guess(int id, int value);
};

#define g_slotManager_guess EQ_GLOBAL(SlotManager_guess*, 0x0098599C)

// Starts the mail button blink: 20 more 250 ms steps, keeping the parity so the current image doesn't jump;
// returns half the steps that were still left.
// FUNCTION: TITANIUM 0x00552360
int CSelectorWndView_guess::StartMailBlink_guess()
{
    int value = value_198;
    if (value > 0)
    {
        value_198 = value % 2 + 0x14;
        return value / 2;
    }
    value_198 = 0x14;
    return value;
}

struct Clock_guess
{
    char pad_000[0x148];
    int frameTime_0148_guess;
};

struct FlagOverride_guess
{
    // EXTERNAL: TITANIUM 0x005F6BC0 FlagOverride_guess::FUN_005f6bc0_guess
    unsigned char FUN_005f6bc0_guess(int value_guess);
};

struct ValueNode_guess
{
    // EXTERNAL: TITANIUM 0x0059DD30 ValueNode_guess::Read_guess
    int Read_guess();
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_specialFlag_guess EQ_GLOBAL(FlagOverride_guess*, 0x00905CC0)
#define g_selectorFlagA_guess EQ_GLOBAL(int, 0x009247A0)
#define pinstCCastSpellWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C2C)
#define pinstCActionsWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C44)
#define pinstCInventoryWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C34)
#define pinstCPetInfoWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850BAC)
#define pinstCFriendsWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850BC0)
#define pinstCOptionsWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C14)
#define g_value_991ae4_guess EQ_GLOBAL(ValueNode_guess*, 0x00991AE4)
#define pinstCBuffWindowNORMAL_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C18)
#define pinstCBuffWindowSHORT_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C1C)
#define pinstCGuildManagementWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00991AAC)
#define pinstCMapViewWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850BFC)
#define g_value_850ca0_guess EQ_GLOBAL(ValueNode_guess*, 0x00850CA0)
#define pinstCJournalNPCWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850CA4)
#define pinstCMailWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850BE4)
#define pinstCTicketWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x009928A8)
#define pinstCCombatAbilityWnd_guess EQ_GLOBAL(ValueNode_guess*, 0x00850C48)

// Every 250 ms: checks each toggle button whose window is open (window pointers 0x850C2C...). The map
// button is enabled when 0x9247A0 is set or the zone (0x924470) passes 0x5F6BC0. The mail button shows the
// red images when pEverQuest +0x834 is 0 (probably no mail server), else Got Mail while the manager's
// +0x50 flag is set, swapped on odd blink steps.
// FUNCTION: TITANIUM 0x00552387
// @early-stop: budget, diff ndiff=2
void CSelectorWnd_guess::OnProcessFrame_guess()
{
    if (show_005c_guess != 0)
    {
        int current_guess = g_clock_guess->frameTime_0148_guess;
        if (current_guess - lastButtonUpdateTime_021c_guess >= 0xfa)
        {
            lastButtonUpdateTime_021c_guess = current_guess;
            if (selectorFields_19C_guess[0] != 0 && pinstCCastSpellWnd_guess != 0)
            {
                selectorFields_19C_guess[0]->FUN_005bb140_guess(
                    pinstCCastSpellWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[1] != 0 && pinstCActionsWnd_guess != 0)
            {
                selectorFields_19C_guess[1]->FUN_005bb140_guess(
                    pinstCActionsWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[2] != 0 && pinstCInventoryWnd_guess != 0)
            {
                selectorFields_19C_guess[2]->FUN_005bb140_guess(
                    pinstCInventoryWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[3] != 0 && pinstCPetInfoWnd_guess != 0)
            {
                selectorFields_19C_guess[3]->FUN_005bb140_guess(
                    pinstCPetInfoWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[4] != 0 && pinstCFriendsWnd_guess != 0)
            {
                selectorFields_19C_guess[4]->FUN_005bb140_guess(
                    pinstCFriendsWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[5] != 0 && pinstCOptionsWnd_guess != 0)
            {
                selectorFields_19C_guess[5]->FUN_005bb140_guess(
                    pinstCOptionsWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[6] != 0)
            {
                selectorFields_19C_guess[6]->FUN_005bb140_guess(
                    g_value_991ae4_guess->Read_guess());
            }
            if (selectorFields_19C_guess[7] != 0 && pinstCBuffWindowNORMAL_guess != 0)
            {
                selectorFields_19C_guess[7]->FUN_005bb140_guess(
                    pinstCBuffWindowNORMAL_guess->Read_guess());
            }
            if (selectorFields_19C_guess[8] != 0)
            {
                selectorFields_19C_guess[8]->FUN_005bb140_guess(
                    pinstCBuffWindowSHORT_guess->Read_guess());
            }
            if (selectorFields_19C_guess[9] != 0 && pinstCGuildManagementWnd_guess != 0)
            {
                selectorFields_19C_guess[9]->FUN_005bb140_guess(
                    pinstCGuildManagementWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[10] != 0 && pinstCMapViewWnd_guess != 0)
            {
                selectorFields_19C_guess[10]->FUN_005bb140_guess(
                    pinstCMapViewWnd_guess->Read_guess());
                unsigned char state_guess;
                if (g_selectorFlagA_guess == 0)
                {
                    state_guess = g_specialFlag_guess->FUN_005f6bc0_guess(
                        EQ_GLOBAL(int, 0x00924470));
                    if (state_guess != 0)
                    {
                        state_guess = 1;
                    }
                }
                else
                {
                    state_guess = 1;
                }
                selectorFields_19C_guess[10]->state_05D = state_guess;
            }
            if (selectorFields_19C_guess[11] != 0 && g_value_850ca0_guess != 0)
            {
                selectorFields_19C_guess[11]->FUN_005bb140_guess(
                    g_value_850ca0_guess->Read_guess());
            }
            if (selectorFields_19C_guess[12] != 0 && pinstCJournalNPCWnd_guess != 0)
            {
                selectorFields_19C_guess[12]->FUN_005bb140_guess(
                    pinstCJournalNPCWnd_guess->Read_guess());
            }
            if (g_service_guess != 0 &&
                g_service_guess->GetMailManager_guess() != 0 &&
                selectorFields_19C_guess[14] != 0 && pinstCMailWnd_guess != 0)
            {
                Collection_guess* collection_guess =
                    g_service_guess->GetMailManager_guess();
                unsigned char active_guess = collection_guess->field_050_guess;
                Object_guess* button_guess = selectorFields_19C_guess[14];
                int buttonValue_guess = pinstCMailWnd_guess->Read_guess();
                button_guess->FUN_005bb140_guess(buttonValue_guess);
                if (g_service_guess->field_834_guess == 0)
                {
                    button_guess->field_158_guess = redMailBtnNormal_0180_guess;
                    button_guess->field_15C_guess = redMailBtnPressed_0184_guess;
                    button_guess->field_160_guess = redMailBtnFlyby_0188_guess;
                    button_guess->field_168_guess = redMailBtnPressedFlyby_018c_guess;
                }
                else
                {
                    int useAlternate_guess;
                    if (flashCount_0198_guess % 2 == 0)
                    {
                        useAlternate_guess = active_guess;
                    }
                    else
                    {
                        useAlternate_guess = active_guess == 0;
                    }
                    if (useAlternate_guess != 0)
                    {
                        button_guess->field_158_guess = gotMailBtnNormal_0170_guess;
                        button_guess->field_15C_guess = gotMailBtnPressed_0174_guess;
                        button_guess->field_160_guess = gotMailBtnFlyby_0178_guess;
                        button_guess->field_168_guess = gotMailBtnPressedFlyby_017c_guess;
                    }
                    else
                    {
                        button_guess->field_158_guess = mailBtnNormal_0160_guess;
                        button_guess->field_15C_guess = mailBtnPressed_0164_guess;
                        button_guess->field_160_guess = mailBtnFlyby_0168_guess;
                        button_guess->field_168_guess = mailBtnPressedFlyby_016c_guess;
                    }
                }
                if (flashCount_0198_guess > 0)
                {
                    --flashCount_0198_guess;
                }
            }
            if (selectorFields_19C_guess[13] != 0 && pinstCTicketWnd_guess != 0)
            {
                selectorFields_19C_guess[13]->FUN_005bb140_guess(
                    pinstCTicketWnd_guess->Read_guess());
            }
            if (selectorFields_19C_guess[15] != 0 && pinstCCombatAbilityWnd_guess != 0)
            {
                selectorFields_19C_guess[15]->FUN_005bb140_guess(
                    pinstCCombatAbilityWnd_guess->Read_guess());
            }
        }
    }
    FUN_005a0e50_guess();
}

// Gives each of the 16 buttons the key bound to its command (key manager 0x98599C), probably for the tooltip.
// FUNCTION: TITANIUM 0x00552751
void CSelectorWnd_guess::UpdateKeyLabels_guess()
{
    Object_guess** slot = selectorFields_19C_guess;
    int count = 0x10;
    do
    {
        if (*slot != 0)
        {
            SlotManager_guess* manager = g_slotManager_guess;
            ValueSource_guess* first = g_slotManager_guess->FUN_004b2459_guess(((int*)slot)[0x10]);
            int value = first->GetValue_guess();
            ValueSource_guess* second = manager->FUN_004b244f_guess(((int*)slot)[0x10], value);
            (*slot)->FUN_0059dbf0_guess(second->GetValue_guess());
        }
        ++slot;
        --count;
    } while (count != 0);
}

// Builds SelectorWindow. The mail button needs 0x923D65; guild and map need 0x9247A0, the journal 0x9247A0
// or 0x9247A4, combat skills a melee class. Each button runs one ExecuteCmd command: TOGGLE_SPELLSWIN,
// TOGGLE_MAINMENUWIN, INVENTORY, TOGGLE_PETINFOWIN, TOGGLE_FRIENDSWIN, TOGGLE_OPTIONSWIN, TOGGLE_HOTBOX1WIN,
// TOGGLE_BUFFWIN, TOGGLE_SDBUFFWIN, TOGGLE_GUILDMGMTWIN, TOGGLE_MAPWIN, TOGGLE_STORYWIN, TOGGLE_JOURNAL,
// TOGGLE_HELPWIN, TOGGLE_MAILWIN, CMD_TOGGLE_COMBAT_ABILITY_WIN (ids 0x9A... in button order).
// FUNCTION: TITANIUM 0x0055279D
CSelectorWnd_guess::CSelectorWnd_guess(int id_guess)
    : PrimaryBase_guess(id_guess, UiText_guess("SelectorWindow"), -1, 1, 0)
{
    int i_guess;
    for (i_guess = 0; i_guess < 16; ++i_guess)
    {
        selectorFields_19C_guess[i_guess] = 0;
    }
    if (field_124_guess != 0)
    {
        windowStyle_0064_guess |= field_124_guess->flags_060_guess | 0x800;
        field_018_guess = 0;
        FUN_005a25b0_guess();
        GET_SELECTOR_guess(selectorFields_19C_guess[0], "SELW_CastSpellToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[1], "SELW_ActionsToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[2], "SELW_InventoryToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[3], "SELW_PetInfoToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[4], "SELW_FriendsToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[5], "SELW_OptionsToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[6], "SELW_HotboxToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[7], "SELW_BuffToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[8], "SELW_SDBuffToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[9], "SELW_GuildToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[10], "SELW_MapToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[11], "SELW_StoryToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[12], "SELW_JournalToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[13], "SELW_HelpToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[15], "SELW_CombatSkillsToggleButton");
        GET_SELECTOR_guess(selectorFields_19C_guess[14], "SELW_MailToggleButton");
        GET_MAIL_guess(mailBtnNormal_0160_guess, "A_MailBtnNormal");
        GET_MAIL_guess(mailBtnPressed_0164_guess, "A_MailBtnPressed");
        GET_MAIL_guess(mailBtnFlyby_0168_guess, "A_MailBtnFlyby");
        GET_MAIL_guess(mailBtnPressedFlyby_016c_guess, "A_MailBtnPressedFlyby");
        GET_MAIL_guess(gotMailBtnNormal_0170_guess, "A_GotMailBtnNormal");
        GET_MAIL_guess(gotMailBtnPressed_0174_guess, "A_GotMailBtnPressed");
        GET_MAIL_guess(gotMailBtnFlyby_0178_guess, "A_GotMailBtnFlyby");
        GET_MAIL_guess(gotMailBtnPressedFlyby_017c_guess, "A_GotMailBtnPressedFlyby");
        GET_MAIL_guess(redMailBtnNormal_0180_guess, "A_RedMailBtnNormal");
        GET_MAIL_guess(redMailBtnPressed_0184_guess, "A_RedMailBtnPressed");
        GET_MAIL_guess(redMailBtnFlyby_0188_guess, "A_RedMailBtnFlyby");
        GET_MAIL_guess(redMailBtnPressedFlyby_018c_guess, "A_RedMailBtnPressedFlyby");
        GET_MAIL_guess(mailBtnDisabled_0190_guess, "A_MailBtnDisabled");
        if (g_mailEnabled_guess == 0 && selectorFields_19C_guess[14] != 0)
        {
            selectorFields_19C_guess[14]->state_05D = 0;
        }
        flashCount_0198_guess = 0;
        field_194_guess = 0;
        if (selectorFields_19C_guess[9] != 0)
        {
            selectorFields_19C_guess[9]->state_05D = g_selectorFlagA_guess != 0;
        }
        if (selectorFields_19C_guess[10] != 0)
        {
            selectorFields_19C_guess[10]->state_05D = g_selectorFlagA_guess != 0;
        }
        if (selectorFields_19C_guess[12] != 0)
        {
            selectorFields_19C_guess[12]->state_05D =
                g_selectorFlagA_guess != 0 || g_selectorFlagB_guess != 0;
        }
        if (selectorFields_19C_guess[15] != 0 && g_flagManager_guess != 0)
        {
            selectorFields_19C_guess[15]->state_05D =
                g_flagManager_guess->IsMeleeClass_guess();
        }
        selectorIds_1dc_guess[0] = 0x9a;
        selectorIds_1dc_guess[1] = 0xa3;
        selectorIds_1dc_guess[2] = 0xe;
        selectorIds_1dc_guess[3] = 0xa8;
        selectorIds_1dc_guess[4] = 0xa7;
        selectorIds_1dc_guess[5] = 0xa9;
        selectorIds_1dc_guess[6] = 0x9c;
        selectorIds_1dc_guess[7] = 0x9b;
        selectorIds_1dc_guess[8] = 0xb8;
        selectorIds_1dc_guess[9] = 0xbc;
        selectorIds_1dc_guess[10] = 0xbb;
        selectorIds_1dc_guess[11] = 0xba;
        selectorIds_1dc_guess[12] = 0xb7;
        selectorIds_1dc_guess[13] = 0xaa;
        selectorIds_1dc_guess[14] = 0xa1;
        selectorIds_1dc_guess[15] = 0xd4;
        lastButtonUpdateTime_021c_guess = 0;
    }
}

// Newest value (+4, probably the time) among the mail manager's entries of kind 0 or 1; 0 without mail.
// FUNCTION: TITANIUM 0x00552FD3
unsigned int CSelectorWndView_guess::GetNewestMailTime_guess()
{
    if (g_service_guess == 0)
    {
        return 0;
    }
    Collection_guess* collection = g_service_guess->GetMailManager_guess();
    if (collection == 0)
    {
        return 0;
    }
    CollectionIterator_guess end;
    CollectionIterator_guess it;
    it.index_004 = collection->array_024.begin_00c;
    CollectionArray_guess* array = &collection->array_024;
    int limit = array->count_010 + array->begin_00c;
    it.array_000 = array;
    end.array_000 = array;
    end.index_004 = limit;
    unsigned int best = 0;
    while (it.NotEqual_guess(end))
    {
        CollectionEntry_guess* entry = it.Deref_guess();
        if ((entry->kind_008 == 0 || entry->kind_008 == 1) && entry->value_004 > best)
        {
            best = entry->value_004;
        }
        ++it.index_004;
    }
    return best;
}

// Mail manager observer: on change 0 (probably mail added) with a newer entry than the last one seen
// (+0x194 of the window), remembers it and starts the blink.
// FUNCTION: TITANIUM 0x00553044
void CSelectorWndObserverView_guess::OnMailChanged_guess(Collection_guess* first_guess, int* second_guess)
{
    if (g_service_guess != 0)
    {
        if (first_guess == g_service_guess->GetMailManager_guess())
        {
            if (*second_guess == 0)
            {
                CSelectorWndView_guess* controller = (CSelectorWndView_guess*)((char*)this - 0x15c);
                unsigned int value = controller->GetNewestMailTime_guess();
                if (value > newestMailTime_0038_guess)
                {
                    newestMailTime_0038_guess = value;
                    controller->StartMailBlink_guess();
                }
            }
        }
    }
}

// Unregisters the window's observer from the mail manager.
// FUNCTION: TITANIUM 0x00553087
CSelectorWnd_guess::~CSelectorWnd_guess()
{
    if (g_service_guess != 0)
    {
        if (g_service_guess->GetMailManager_guess() != 0)
        {
            int* value = (int*)static_cast<SecondaryBase_guess*>(this);
            Collection_guess* collection = g_service_guess->GetMailManager_guess();
            collection->FUN_00518b72_guess((int*)&value);
        }
    }
}

// Unregisters the observer at +0x15C from the mail manager; this is CSelectorWnd's AboutToHide (vtable slot
// 50; the RespawnWnd view name is wrong).
// FUNCTION: TITANIUM 0x005530F5
char CRespawnWndView_guess::AboutToHide_guess()
{
    if (g_service_guess != 0)
    {
        if (g_service_guess->GetMailManager_guess() != 0)
        {
            int local = this != 0 ? (int)&field_15C : 0;
            Collection_guess* collection = g_service_guess->GetMailManager_guess();
            collection->FUN_00518b72_guess(&local);
        }
    }
    return 1;
}

// Scalar deleting destructor of the selector window (vtable 0x65C518 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x0055313B
void* CSelectorWnd_guess::ScalarDeletingDestructor_guess(unsigned char flags)
{
    this->CSelectorWnd_guess::~CSelectorWnd_guess();
    if (flags & 1)
    {
        _free(this);
    }
    return this;
}

// AboutToShow (vtable slot 49): refreshes the key labels; with mail enabled (0x923D65) registers the
// observer and, the first time, records the newest mail and blinks if there is any.
// FUNCTION: TITANIUM 0x00553157
char CSelectorWndView_guess::AboutToShow_guess()
{
    UpdateKeyLabels_guess();
    if (g_mailEnabled_guess != 0)
    {
        if (g_service_guess != 0)
        {
            if (g_service_guess->GetMailManager_guess() != 0)
            {
                int local = this != 0 ? (int)&inner_15c_guess : 0;
                Collection_guess* collection = g_service_guess->GetMailManager_guess();
                collection->FUN_00518d4a_guess(collection->Begin_guess(), &local);
            }
        }
        if (inner_15c_guess.newestMailTime_0038_guess == 0)
        {
            unsigned int value = GetNewestMailTime_guess();
            inner_15c_guess.newestMailTime_0038_guess = value;
            if (value != 0)
            {
                StartMailBlink_guess();
            }
        }
    }
    return 1;
}

// RespawnWnd's vtable slot 50 hook: clears the respawn list's selection (CListWnd::ClearAllSel, 0x598580, on
// +0x15C); returns 1.
// FUNCTION: TITANIUM 0x005531D2
char CRespawnWndView_guess::FUN_005531d2_guess()
{
    if (field_15C != 0)
    {
        field_15C->FUN_00598580_guess();
    }
    return 1;
}

// A toggle button click runs its ExecuteCmd command (pressed), then calls 0x59D080(1) instead of the base
// handler.
// FUNCTION: TITANIUM 0x005526F4
int CSelectorWnd_guess::WndNotification_guess(Object_guess* selected_guess, int mode_guess, int unused_guess)
{
    if (mode_guess == 1)
    {
        int index_guess = 0;
        Object_guess** slot_guess = selectorFields_19C_guess;
        do
        {
            if (selected_guess == *slot_guess)
            {
                int value_guess = selectorIds_1dc_guess[index_guess];
                if (value_guess != -1)
                {
                    ExecuteCmd(value_guess, 1, 0);
                }
                FUN_0059d080_guess(1);
                return 0;
            }
            ++index_guess;
            ++slot_guess;
        } while (index_guess < 0x10);
    }
    return FUN_005a2230_guess(selected_guess, mode_guess, unused_guess);
}

