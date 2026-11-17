// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 188: a hint from compare/tumap.py.
// The merchant window (MerchantWnd, CMerchantWnd_guess; the View/PriceView/BuyView classes are views of it):
// up to 80 merchant items (slot ids 6000-6079), buy and sell with a quantity window, and the merchant's price
// lines. The merchant spawn is 0x905D10; a player trader (Bazaar) uses OP_Trader/OP_TraderBuy instead of the
// shop opcodes. +0x2C4 is the selected slot id (-1 none): below 6000 one of your items, 6000+ the merchant's.
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/slots.h"
#include "titanium/opcodes.h"

#define g_FUN_00537096_global_guess EQ_GLOBAL(int, 0x00905D10)
#define g_FUN_005370be_spawn_guess EQ_GLOBAL(Spawn_guess*, 0x00905D10)
#define g_FUN_005370be_spawn2_guess EQ_GLOBAL(Spawn_guess*, 0x00905CE4)
#define g_FUN_005370be_connection_guess EQ_GLOBAL(MessageConnection_guess, 0x00905CA0)
#define g_FUN_005370be_message_guess EQ_GLOBAL(int, 0x00923D94)
#define g_FUN_005370be_state_guess EQ_GLOBAL(int, 0x00905D04)
#define g_FUN_005370be_reset_guess EQ_GLOBAL(int, 0x009248D4)
#define g_FUN_0044a617_object_guess EQ_GLOBAL(FUN_0044a617_owner_guess*, 0x00851390)
#define g_FUN_004a1350_object_guess EQ_GLOBAL(FUN_004a1350_owner_guess*, 0x00988DF0)
#define g_busyCount_guess EQ_GLOBAL(int, 0x009248D0)

struct Spawn_guess {
    unsigned char pad00_guess[0x120];
    char name_guess[0x88];             // 0x120
    unsigned char pad01_guess[0x9C];
    unsigned char flag_guess;          // 0x244
    unsigned char pad02_guess[0x13];
    int value_guess;                   // 0x258
    // EXTERNAL: TITANIUM 0x0048083A Spawn_guess::FUN_0048083a_guess
    void FUN_0048083a_guess(int value_guess, const char* text_guess, int flag_guess);
};

struct MessageConnection_guess {
    int unused_guess;
};

struct FUN_0044a617_owner_guess {
    // EXTERNAL: TITANIUM 0x0044A617 FUN_0044a617_owner_guess::Run_guess
    void Run_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0044A537 FUN_0044a617_owner_guess::WavePlay_guess
    void WavePlay_guess(int sound_guess, int value_guess);
};

struct Quad_guess {
    int field_0_guess;
    int field_4_guess;
    int field_8_guess;
    int field_C_guess;

    // EXTERNAL: TITANIUM 0x004D9160 Quad_guess::CopyTo_guess
    Quad_guess* CopyTo_guess(Quad_guess* destination_guess, Quad_guess* source_guess);
};

struct FUN_005372d8_result_guess;

struct Spell_guess {
    virtual ~Spell_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual FUN_005372d8_result_guess* Slot10_guess(float speed_guess, int value_guess);

    char pad_004_guess[0x44];
    int count_048_guess;

    // EXTERNAL: TITANIUM 0x005EC760 Spell_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 Spell_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Spell_guess::FUN_005ecc30_guess
    int FUN_005ecc30_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Spell_guess::FUN_005ec630_guess
    Spell_guess* FUN_005ec630_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC650 Spell_guess::FUN_005ec650_guess
    void* FUN_005ec650_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC660 Spell_guess::FUN_005ec660_guess
    void FUN_005ec660_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 Spell_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Spell_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005ECD50 Spell_guess::FUN_005ecd50_guess
    int FUN_005ecd50_guess();
};

// pCharData (0x00905D00) is an EQ_PC: the profile is a virtual base at +0xC384, reached through the vbptr at +8.
struct PcPrefix_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct CharacterProfile_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 CharacterProfile_guess::GetFirst_guess
    Spell_guess* GetFirst_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x00434777 CharacterProfile_guess::FUN_00434777_guess
    void* FUN_00434777_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 CharacterProfile_guess::FUN_0041aa84_guess
    void FUN_0041aa84_guess(int slot_guess, int value_guess);
    unsigned char pad_vftable_guess[4];
    // the list object sits at +4 of the virtual base (GetCharInfo2 = 0x005EC220)
    EQ_CharacterProfile_guess profile_guess;
    // inline member of the vbase: the vbase pointer stays in EAX (NOTES, 0x004850A0 rule)
    void* FindSlot_guess() { return profile_guess.GetCharInfo2(); }
};

struct PcView_guess : PcPrefix_guess, virtual CharacterProfile_guess {
    unsigned char pad_0C_guess[0xC384 - 0x0C];
    // EXTERNAL: TITANIUM 0x004BCE5F PcView_guess::WouldDuplicateLore_guess
    int WouldDuplicateLore_guess(Spell_guess* spell_guess);
    // EXTERNAL: TITANIUM 0x004BC0D3 PcView_guess::SpendMoney_guess
    int SpendMoney_guess(int target_guess);
};

#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)

struct FUN_005372d8_result_guess {
    // EXTERNAL: TITANIUM 0x004B1D79 FUN_005372d8_result_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x004B1D1F FUN_005372d8_result_guess::GetValue2_guess
    int GetValue2_guess();
};

struct FUN_005372d8_target_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual FUN_005372d8_result_guess* Slot10_guess(float speed_guess,
                                                    int value_guess);

    // EXTERNAL: TITANIUM 0x005DFCE0 FUN_005372d8_target_guess::GetDuration_guess
    int GetDuration_guess();
    // EXTERNAL: TITANIUM 0x005E1690 FUN_005372d8_target_guess::GetValue_guess
    int GetValue_guess(float speed_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005E0620 FUN_005372d8_target_guess::IsReady_guess
    int IsReady_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ECCC0 FUN_005372d8_target_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC760 FUN_005372d8_target_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 FUN_005372d8_target_guess::GetTextValue_guess
    int GetTextValue_guess();
};

struct FUN_005372d8_flag_guess {
    unsigned char pad_000_guess[0x5D];
    unsigned char active_05d_guess;
};

struct CMerchantWndPriceView_guess {
    unsigned char pad_000_guess[0x2A4];
    float speed_2a4_guess;
    unsigned char pad_2a8_guess[0x1C];
    FUN_005372d8_flag_guess* flag_2c4_guess;
    FUN_005372d8_flag_guess* flag_2c8_guess;

    int DisplayBuyOrSellPrice(char mode_guess,
                     FUN_005372d8_target_guess* target_guess);
};

struct FUN_005372d8_clock_guess {
    // EXTERNAL: TITANIUM 0x0041A259 FUN_005372d8_clock_guess::GetTime_guess
    __int64 GetTime_guess();
    // EXTERNAL: TITANIUM 0x0041A3C5 FUN_005372d8_clock_guess::FUN_0041a3c5_guess
    void FUN_0041a3c5_guess(int money_guess);
};

struct FUN_005372d8_player_guess {
    unsigned char pad_000_guess[0xC280];
    FUN_005372d8_clock_guess clock_c280_guess;
};

struct FUN_005372d8_text_base_guess {
    unsigned char pad_000_guess[0x120];
    char text_120_guess;
};

#define g_FUN_005372d8_player_guess EQ_GLOBAL(FUN_005372d8_player_guess*, 0x00905D00)
#define g_FUN_005372d8_text_base_guess EQ_GLOBAL(FUN_005372d8_text_base_guess*, 0x00905D10)

struct FUN_004a1350_owner_guess {
    // EXTERNAL: TITANIUM 0x004A1350 FUN_004a1350_owner_guess::Run_guess
    void Run_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x004982C6 FUN_004a1350_owner_guess::dsp_chat
    void dsp_chat(const char* message_guess, int category_guess, bool flag_guess);
    // EXTERNAL: TITANIUM 0x00492EC2 FUN_004a1350_owner_guess::GetText_guess
    char* GetText_guess(const char* source_guess);
};

struct Buff_guess {
    virtual ~Buff_guess();
    unsigned char pad_004_guess[0x74];
    __int64 key_guess;                      // 0x80
    // EXTERNAL: TITANIUM 0x005DFCE0 Buff_guess::FUN_005dfce0_guess
    int FUN_005dfce0_guess();
    // EXTERNAL: TITANIUM 0x005DFCF0 Buff_guess::FUN_005dfcf0_guess
    int FUN_005dfcf0_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Buff_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005EC760 Buff_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECD80 Buff_guess::SetStackCount_guess
    void SetStackCount_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0F30 Buff_guess::GetItemId_guess
    int GetItemId_guess();
};

struct Link_0053826a_guess;
struct MerchantLabelVtable_guess;

struct CMerchantWndView_guess {
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
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual Quad_guess* Slot57_guess(Quad_guess* buffer_guess);
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess();
    virtual void Slot64_guess(int value_guess);
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

    unsigned char pad00_guess[0x58];
    unsigned char flag_guess;
    unsigned char pad01_guess[0xFF];
    int transition_state_guess;
    unsigned char state_guess;
    unsigned char pad02_guess[0x03];
    Buff_guess* slots_guess[0x50];
    union {
        int value_guess;
        float speed_guess;
    };
    int state_id_guess;
    union {
        int reset_state_guess;
        Spell_guess** spell_slot_guess;
        Link_0053826a_guess* link_guess;
    };
    unsigned char dirty_2b0_guess;          // 0x2B0 set when the slots change
    unsigned char pad03_guess[0x3];
    MerchantLabelVtable_guess* field_2b4_guess;   // 0x2B4 object with Slot63(CXStr*)
    MerchantLabelVtable_guess* field_2b8_guess;
    MerchantLabelVtable_guess* field_2bc_guess;
    struct Active_guess {
        unsigned char pad_guess[0x16C];
        int value_guess;
    }* active_guess;
    CMerchantWndView_guess* left_guess;
    CMerchantWndView_guess* right_guess;
    CMerchantWndView_guess* controller_guess;
    void* field_2d0_guess;

    void OpenForMerchant_guess(int first_guess, int second_guess);
    char Deactivate_guess();
    void OnShow_guess();
    void UpdateBuySellButtons_guess();
    void RequestSellItem(int value_guess);
    void ClearSelection_guess();
    char Activate_guess();
    void HandleSell_guess(int value_guess);
    void HandleBuy_guess(int value_guess);
    void SelectBuySellSlot(int state_id_guess, Buff_guess* context_guess);
    int WndNotification_guess(CXWnd* child_guess, int message_guess, void* data_guess);
    void AddMerchantItem_guess(Buff_guess* buff_guess);
    void ClearMerchantSlot_guess(__int64 key_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 CMerchantWndView_guess::IsReady_guess
    char IsReady_guess();
    void RequestBuyItem(int value_guess);
    void FinishSellingItem_guess(struct Msg_005384e2_guess* msg_guess);

};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005B0940 CXWndManagerView_guess::BringWndToTop
    void BringWndToTop(CMerchantWndView_guess* owner_guess, int value_guess);
};

#define g_FUN_005b0940_object_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)

/* ---- CMerchantWnd::CMerchantWnd(CXWnd*) (0x00536D26) ------------------------------------------------
 * Layout: include/titanium/types.h CMerchantWnd (0x2D4). */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CItemDisplayManager.h"
#include "titanium/wnd/CQuantityWnd.h"
#include "titanium/wnd/CTradeskillWnd.h"

// A list window as the merchant window configures it (fields past the header's CListWnd 0x140).
struct MerchantListWnd_guess : CListWnd {
    char pad_140[0x14];
    int field_154;                          // 0x154
    char pad_158;
    unsigned char field_159;                // 0x159
    char pad_15a[2];
    unsigned char field_15c;                // 0x15c
    char pad_15d[3];
    int field_160;                          // 0x160
    char pad_164[8];
    unsigned int color_16c;                 // 0x16c
    void SetRowHeight_guess(int height) {
        field_159 = 1;
        field_160 = height;
    }
    // EXTERNAL: TITANIUM 0x005981F0 MerchantListWnd_guess::FUN_005981f0_guess
    void FUN_005981f0_guess(int column, int value);
    // EXTERNAL: TITANIUM 0x0059B2E0 MerchantListWnd_guess::SetCellColor_guess
    void SetCellColor_guess(int row, int column, unsigned long color);
};

struct MerchantSelectedItem_guess : CXWnd {
    char pad_11c_guess[0x50];
    int field_16c_guess;
};

struct MerchantLabelVtable_guess {
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
    virtual void Slot63_guess(CXStr* text_guess);
};

struct MerchantWndVtable_guess {
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
};

struct MerchantTimer_guess {
    char pad_000_guess[0x148];
    unsigned int time_148_guess;
    // EXTERNAL: TITANIUM 0x00439D16 MerchantTimer_guess::PlayerDistance_guess
    float PlayerDistance_guess(void* first_guess, void* second_guess, float third_guess);
    // EXTERNAL: TITANIUM 0x0043DD14 MerchantTimer_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(PcView_guess* pc_guess, int slot_guess, int value_guess,
                            Spell_guess* item_guess);
};

#define g_merchantTimer_guess EQ_GLOBAL(MerchantTimer_guess*, 0x00905D24)

struct MerchantItem_guess {
    unsigned char pad_000[0x80];
    __int64 key_080;
    // EXTERNAL: TITANIUM 0x005E0F60 MerchantItem_guess::FUN_005e0f60_guess
    char* FUN_005e0f60_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 MerchantItem_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005DFCF0 MerchantItem_guess::FUN_005dfcf0_guess
    int FUN_005dfcf0_guess();
    // EXTERNAL: TITANIUM 0x005DFCE0 MerchantItem_guess::FUN_005dfce0_guess
    int FUN_005dfce0_guess();
};

struct MerchantListState_guess {
    unsigned char pad_000[0x10C];
    int field_10C;
};

struct MerchantListVtable_guess {
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
    virtual void Slot64_guess(int value_guess);
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();
};

struct MerchantItemText_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 MerchantItemText_guess::GetIcon_guess
    char* GetIcon_guess(char* text_guess);
};

#define g_merchantItemText_guess EQ_GLOBAL(MerchantItemText_guess*, 0x00991910)

// EXTERNAL: TITANIUM 0x00658D68 ??_7CMerchantWnd_guess@@6B@
struct CMerchantWnd_guess : CSidlScreenWndBase {
    unsigned int nextUpdate_15c;            // 0x15c
    char pad_160[4];
    void* items_164[80];                    // 0x164
    char pad_2a4[8];
    int* field_2ac;                         // 0x2ac
    unsigned char field_2b0;                // 0x2b0
    char pad_2b1[3];
    CXWnd* merchantName_2b4;                // 0x2b4 MW_MerchantName
    CXWnd* selectedItemLabel_2b8;           // 0x2b8 MW_SelectedItemLabel
    CXWnd* selectedPriceLabel_2bc;          // 0x2bc MW_SelectedPriceLabel
    CXWnd* selectedItem_2c0;                // 0x2c0 MW_SelectedItem
    CXWnd* buyButton_2c4;                   // 0x2c4 MW_Buy_Button
    CXWnd* sellButton_2c8;                  // 0x2c8 MW_Sell_Button
    MerchantListWnd_guess* itemList_2cc;    // 0x2cc ItemList
    CXWnd* doneButton_2d0;                  // 0x2d0 MW_Done_Button
    void RefreshItemList_guess();
    void OnProcessFrame_guess();
    CMerchantWnd_guess(CXWnd* parent);
};

// Style 0x10000; the item list uses 24-pixel rows with 0xFF8AA3FF highlights.
// FUNCTION: TITANIUM 0x00536D26
CMerchantWnd_guess::CMerchantWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "MerchantWnd", -0x101, 3, 0) {
    merchantName_2b4 = 0;
    selectedItemLabel_2b8 = 0;
    selectedPriceLabel_2bc = 0;
    selectedItem_2c0 = 0;
    buyButton_2c4 = 0;
    sellButton_2c8 = 0;
    doneButton_2d0 = 0;
    itemList_2cc = 0;
    field_2ac = 0;
    for (int i = 0; i < 80; ++i) {
        items_164[i] = 0;
    }
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10000;
        field_158_guess = 0x11;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        merchantName_2b4 = ((CSidlScreenWnd*)this)->GetChildItem("MW_MerchantName");
        selectedItemLabel_2b8 = ((CSidlScreenWnd*)this)->GetChildItem("MW_SelectedItemLabel");
        selectedPriceLabel_2bc = ((CSidlScreenWnd*)this)->GetChildItem("MW_SelectedPriceLabel");
        selectedItem_2c0 = ((CSidlScreenWnd*)this)->GetChildItem("MW_SelectedItem");
        buyButton_2c4 = ((CSidlScreenWnd*)this)->GetChildItem("MW_Buy_Button");
        sellButton_2c8 = ((CSidlScreenWnd*)this)->GetChildItem("MW_Sell_Button");
        doneButton_2d0 = ((CSidlScreenWnd*)this)->GetChildItem("MW_Done_Button");
        itemList_2cc = (MerchantListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ItemList");
        if (itemList_2cc != 0) {
            itemList_2cc->SetColors(-1, 0xffffff00, 0xff808080);
            itemList_2cc->SetColumnJustification(0, 0);
            itemList_2cc->SetColumnJustification(1, 0);
            itemList_2cc->SetColumnJustification(2, 1);
            itemList_2cc->SetColumnJustification(3, 1);
            itemList_2cc->SetColumnJustification(4, 1);
            itemList_2cc->SetColumnJustification(5, 1);
            itemList_2cc->SetColumnJustification(6, 1);
            itemList_2cc->color_16c = 0xff8aa3ff;
            itemList_2cc->field_15c = 1;
            itemList_2cc->SetRowHeight_guess(24);
            itemList_2cc->FUN_005981f0_guess(0, 24);
            itemList_2cc->WindowStyle |= 0x40000;
            itemList_2cc->field_154 = 1;
        }
        field_2b0 = 0;
        FUN_0059db90_guess(20);
    }
}

// Opens for merchant `first_guess` (rate `second_guess`) unless already open.
// FUNCTION: TITANIUM 0x00537096
void CMerchantWndView_guess::OpenForMerchant_guess(int first_guess, int second_guess) {
    if (flag_guess == 0) {
        g_FUN_00537096_global_guess = first_guess;
        value_guess = second_guess;
        Slot48_guess(1, 1);
    }
}

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* buffer_guess, int id_guess,
                                const char* text_guess, int zero1_guess,
                                int zero2_guess, int zero3_guess, int zero4_guess,
                                int zero5_guess, int zero6_guess, int zero7_guess,
                                int zero8_guess);

// Closing: frees the 80 items, closes the quantity window, and tells the server: OP_Trader (20 bytes, code 4)
// for a trader, else OP_ShopEnd (merchant id, my id).
// FUNCTION: TITANIUM 0x005370BE
char CMerchantWndView_guess::Deactivate_guess() {
    reset_state_guess = 0;
    for (int i = 0; i < 0x50; i++) {
        if (slots_guess[i] != 0) {
            delete slots_guess[i];
            slots_guess[i] = 0;
        }
    }
    if (pinstCQuantityWnd_guess->IsVisible_guess()) {
        pinstCQuantityWnd_guess->Show(0, 1);
    }
    if (controller_guess != 0) {
        controller_guess->Slot76_guess();
    }
    g_FUN_0044a617_object_guess->Run_guess(6, 0);
    g_FUN_005370be_message_guess = 10;
    g_FUN_004a1350_object_guess->Run_guess(0, 1, 0x14);
    if (g_FUN_005370be_spawn_guess != 0) {
        if (g_FUN_005370be_spawn_guess->flag_guess == 0) {
            int data_guess[5];
            data_guess[0] = 4;
            data_guess[1] = g_FUN_005370be_spawn_guess->value_guess;
            data_guess[2] = g_FUN_005370be_spawn2_guess->value_guess;
            EQSendMessage(&g_FUN_005370be_connection_guess, OP_Trader,
                         data_guess, 0x14, 1);
        } else {
            int data_guess[2];
            data_guess[0] = g_FUN_005370be_spawn_guess->value_guess;
            data_guess[1] = g_FUN_005370be_spawn2_guess->value_guess;
            EQSendMessage(&g_FUN_005370be_connection_guess, OP_ShopEnd,
                         data_guess, 8, 1);
        }
        g_FUN_005370be_spawn_guess = 0;
    }
    g_FUN_005370be_state_guess = 0;
    g_FUN_005370be_reset_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    return 1;
}

// OnShow (vtable slot 35). On show: opens the inventory window (0x850C34, Activate) unless it was already
// open, remembering that in +0x160, brings this window to the top (CXWndManager::BringWndToTop) and shows
// context tip 0x11 in the tip window (0x9928E0). On hide: closes the inventory window if this window opened
// it.
// FUNCTION: TITANIUM 0x005371E0
void CMerchantWndView_guess::OnShow_guess() {
    if (flag_guess != 0) {
        char result_guess = pinstCInventoryWnd_guess->IsVisible_guess();
        state_guess = result_guess;
        if (result_guess == 0) {
            pinstCInventoryWnd_guess->Activate();
        }
        g_FUN_005b0940_object_guess->BringWndToTop(this, 1);
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x11, 0);
        }
    } else {
        if (state_guess == 0) {
            pinstCInventoryWnd_guess->Deactivate();
        }
    }
    ((CSidlScreenWnd*)this)->OnShow();
}

// Buy when nothing or a merchant item is selected, Sell when one of your items is.
// FUNCTION: TITANIUM 0x0053724E
void CMerchantWndView_guess::UpdateBuySellButtons_guess() {
    if (state_id_guess == -1 ||
        (state_id_guess >= 6000 && state_id_guess < 0x17c0)) {
        if (left_guess != 0) {
            left_guess->Slot48_guess(1, 1);
        }
        if (right_guess != 0) {
            right_guess->Slot48_guess(0, 1);
        }
    } else {
        if (left_guess != 0) {
            left_guess->Slot48_guess(0, 1);
        }
        if (right_guess != 0) {
            right_guess->Slot48_guess(1, 1);
        }
    }
}

// Price line in chat: buying uses "That'll be%2 per/for the %3" (strings 4020/4019), selling "I'll give
// you%2 per/for the %3" (12026/12027); "per" for stackable items. Enables Buy or Sell when affordable.
// FUNCTION: TITANIUM 0x005372D8
// @early-stop: budget, diff ndiff=64
int CMerchantWndPriceView_guess::DisplayBuyOrSellPrice(
    char mode_guess, FUN_005372d8_target_guess* target_guess) {
    __int64 local_218_guess;
    int local_210_guess;
    int local_20c_guess;
    int format_true_guess;
    int format_false_guess;
    char buffer_guess[512];

    if (flag_2c8_guess != 0) {
        flag_2c8_guess->active_05d_guess = 1;
    }
    if (target_guess == 0) {
        return 0;
    }
    if (mode_guess != 0) {
        local_20c_guess = target_guess->Slot10_guess(speed_2a4_guess, 1)
                              ->GetValue_guess();
        local_210_guess = target_guess->GetDuration_guess();
        format_true_guess = 0xfb4;
        format_false_guess = 0xfb3;
        local_218_guess = g_FUN_005372d8_player_guess->clock_c280_guess
                              .GetTime_guess();
        if (flag_2c4_guess != 0) {
            if (local_218_guess < target_guess->GetDuration_guess()) {
                flag_2c4_guess->active_05d_guess = 0;
            } else {
                flag_2c4_guess->active_05d_guess = 1;
            }
        }
    } else {
        local_20c_guess = target_guess->Slot10_guess(speed_2a4_guess, 1)
                              ->GetValue2_guess();
        local_210_guess = target_guess->GetValue_guess(speed_2a4_guess, 1);
        format_true_guess = 0x2efa;
        format_false_guess = 0x2efb;
        if (flag_2c8_guess != 0) {
            if (target_guess->IsReady_guess(1) != 0 &&
                target_guess->Slot04_guess(0) != 0 &&
                target_guess->GetValue_guess(speed_2a4_guess, 1) > 0) {
                flag_2c8_guess->active_05d_guess = 1;
            } else {
                flag_2c8_guess->active_05d_guess = 0;
            }
        }
    }
    if (target_guess->GetItemClass_guess() == 0 &&
        target_guess->IsStackable_guess() != 0) {
        FUN_0046da4a_guess(
            buffer_guess, format_true_guess,
            g_FUN_004a1350_object_guess->GetText_guess(
                &g_FUN_005372d8_text_base_guess->text_120_guess),
            local_20c_guess, target_guess->GetTextValue_guess(),
            0, 0, 0, 0, 0, 0);
    } else {
        FUN_0046da4a_guess(
            buffer_guess, format_false_guess,
            g_FUN_004a1350_object_guess->GetText_guess(
                &g_FUN_005372d8_text_base_guess->text_120_guess),
            local_20c_guess, target_guess->GetTextValue_guess(),
            0, 0, 0, 0, 0, 0);
    }
    g_FUN_004a1350_object_guess->dsp_chat(buffer_guess, 0x113, 1);
    return local_210_guess;
}

// Sells `value_guess` of the selected item (slots 0-331) with OP_ShopPlayerSell (16 bytes). Refused while a
// sale is pending (12063 "Hold your horses"), for items the merchant won't take (12062) and for bags that
// are not empty (12064).
// FUNCTION: TITANIUM 0x005374D7
void CMerchantWndView_guess::RequestSellItem(int value_guess) {
    char buffer_guess[512];
    if (spell_slot_guess == 0) {
        return;
    }
    Spell_guess* spell_guess = *spell_slot_guess;
    if (spell_guess == 0 || g_FUN_005370be_spawn_guess == 0 || value_guess < 1) {
        return;
    }
    int state_guess = state_id_guess;
    if (state_guess < 0 || state_guess > 0x14b) {
        return;
    }
    if (g_busyCount_guess != 0) {
        FUN_0046da4a_guess(buffer_guess, 0x2f1f,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_FUN_004a1350_object_guess->dsp_chat(buffer_guess, 0x111, 1);
        return;
    }
    if (!spell_guess->Slot04_guess(1)) {
        FUN_0046da4a_guess(buffer_guess, 0x2f1e,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        g_FUN_004a1350_object_guess->dsp_chat(buffer_guess, 0x111, 1);
        return;
    }
    if (spell_guess->GetItemClass_guess() == 1) {
        for (int i = 0; i < spell_guess->FUN_005ecc30_guess(); i++) {
            if (spell_guess->FUN_005ec630_guess(i) != 0) {
                FUN_0046da4a_guess(buffer_guess, 0x2f20,
                                   g_FUN_004a1350_object_guess->GetText_guess(
                                       g_FUN_005370be_spawn_guess->name_guess),
                                   0, 0, 0, 0, 0, 0, 0, 0);
                g_FUN_004a1350_object_guess->dsp_chat(buffer_guess, 0x111, 1);
                return;
            }
        }
        if (pinstCContainerMgr_guess != 0) {
            pinstCContainerMgr_guess->CloseEQContainer_guess(spell_guess);
        }
    }
    g_busyCount_guess++;
    int data_guess[4];
    data_guess[0] = g_FUN_005370be_spawn_guess->value_guess;
    data_guess[2] = value_guess;
    data_guess[1] = state_guess;
    EQSendMessage(&g_FUN_005370be_connection_guess, OP_ShopPlayerSell, data_guess, 0x10, 1);
}

// Adds or replaces a merchant item from the server (by its id); a bad item prints string 1366.
// FUNCTION: TITANIUM 0x00537691
void CMerchantWndView_guess::AddMerchantItem_guess(Buff_guess* buff_guess) {
    if (!IsReady_guess()) {
        return;
    }
    if (buff_guess == 0) {
        return;
    }
    if (buff_guess->IsStackable_guess()) {
        buff_guess->SetStackCount_guess(1);
    }
    if (buff_guess->GetItemId_guess() == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x556, 0), 0xd, 1);
        delete buff_guess;
        return;
    }
    for (int i = 0; i < 0x50; i++) {
        if (slots_guess[i] != 0 && slots_guess[i]->key_guess == buff_guess->key_guess) {
            Buff_guess** slot_guess = &slots_guess[i];
            if (*slot_guess != 0) {
                delete *slot_guess;
            }
            *slot_guess = buff_guess;
            dirty_2b0_guess = 1;
            return;
        }
    }
    for (int j = 0; j < 0x50; j++) {
        if (slots_guess[j] == 0) {
            slots_guess[j] = buff_guess;
            dirty_2b0_guess = 1;
            return;
        }
    }
    delete buff_guess;
}

// Removes the merchant item with that id.
// FUNCTION: TITANIUM 0x00537777
void CMerchantWndView_guess::ClearMerchantSlot_guess(__int64 key_guess) {
    if (key_guess >= 0) {
        for (int i = 0; i < 0x50; i++) {
            if (slots_guess[i] != 0 && slots_guess[i]->key_guess == key_guess) {
                Buff_guess** slot_guess = &slots_guess[i];
                if (*slot_guess != 0) {
                    delete *slot_guess;
                }
                *slot_guess = 0;
                dirty_2b0_guess = 1;
                return;
            }
        }
    }
}

// Refills the list (name, price, count...) and keeps the selection.
// FUNCTION: TITANIUM 0x005377DC
// @early-stop: budget, structural ndiff=194
void CMerchantWnd_guess::RefreshItemList_guess() {
    if (itemList_2cc != 0) {
        int selectedKey_guess = -1;
        int selectedRow_guess = itemList_2cc->GetCurSel();
        if (selectedRow_guess != -1) {
            int selectedItem_guess = itemList_2cc->GetItemData(selectedRow_guess);
            MerchantItem_guess* item_guess =
                (MerchantItem_guess*)items_164[selectedItem_guess];
            if (item_guess != 0) {
                selectedKey_guess = (int)item_guess->key_080;
            }
        }

        int selectedValue_guess =
            ((MerchantListState_guess*)itemList_2cc)->field_10C;
        ((MerchantListVtable_guess*)itemList_2cc)->Slot76_guess();
        char* itoaBuffer_guess = EQ_ARRAY(char, 0x0099DB00);
        for (int i_guess = 0; i_guess < 0x50; ++i_guess) {
            MerchantItem_guess* item_guess =
                (MerchantItem_guess*)items_164[i_guess];
            if (item_guess != 0) {
                int row_guess = itemList_2cc->AddString(
                    CXStr(EQ_ARRAY(char, 0x0063F53F)), 0xffffffff, i_guess, 0);
                itemList_2cc->SetCellColor_guess(
                    row_guess, 0,
                    (unsigned long)g_merchantItemText_guess->GetIcon_guess(
                        item_guess->FUN_005e0f60_guess()));
                itemList_2cc->SetItemText(
                    row_guess, 1, CXStr(item_guess->FUN_005e0ec0_guess()));

                int value_guess = item_guess->FUN_005dfcf0_guess();
                char* text_guess;
                if (value_guess < 1) {
                    text_guess = EQ_ARRAY(char, 0x0064DA6C);
                } else {
                    text_guess = _itoa(value_guess, itoaBuffer_guess, 10);
                }
                itemList_2cc->SetItemText(row_guess, 2, CXStr(text_guess));

                int duration_guess = item_guess->FUN_005dfce0_guess();
                int remainder_guess = duration_guess % 1000;
                itemList_2cc->SetItemText(
                    row_guess, 3,
                    CXStr(_itoa(duration_guess / 1000, itoaBuffer_guess, 10)));
                itemList_2cc->SetItemText(
                    row_guess, 4,
                    CXStr(_itoa(remainder_guess / 100, itoaBuffer_guess, 10)));
                remainder_guess %= 100;
                itemList_2cc->SetItemText(
                    row_guess, 5,
                    CXStr(_itoa(remainder_guess / 10, itoaBuffer_guess, 10)));
                remainder_guess %= 10;
                itemList_2cc->SetItemText(
                    row_guess, 6,
                    CXStr(_itoa(remainder_guess, itoaBuffer_guess, 10)));
            }
        }
        ((MerchantListVtable_guess*)itemList_2cc)->Slot78_guess();
        if (selectedKey_guess != -1 && itemList_2cc->ItemsCount > 0) {
            for (int i_guess = 0; i_guess < itemList_2cc->ItemsCount;
                 ++i_guess) {
                int selectedItem_guess = itemList_2cc->GetItemData(i_guess);
                MerchantItem_guess* item_guess =
                    (MerchantItem_guess*)items_164[selectedItem_guess];
                if (item_guess != 0 && item_guess->key_080 == selectedKey_guess) {
                    itemList_2cc->SetCurSel(i_guess);
                    break;
                }
            }
        }
        ((MerchantListVtable_guess*)itemList_2cc)->Slot64_guess(selectedValue_guess);
    }
    field_2b0 = 0;
}

// Every frame while open: redraws when items changed, and closes when you move more than 20 units from the
// merchant (unless a request is pending).
// FUNCTION: TITANIUM 0x00537C13
// @early-stop: budget, structural ndiff=56
void CMerchantWnd_guess::OnProcessFrame_guess() {
    CMerchantWnd_guess* window_guess = this;
    int zero_guess = 0;
    if (((CXWnd*)window_guess)->Show != zero_guess) {
        if (window_guess->field_2b0 != zero_guess) {
            window_guess->RefreshItemList_guess();
        }

        unsigned int currentTime_guess = g_merchantTimer_guess->time_148_guess;
        if (currentTime_guess >= window_guess->nextUpdate_15c) {
            window_guess->nextUpdate_15c = currentTime_guess + 500;
            if (g_FUN_005370be_spawn_guess != 0) {
                float distance_guess = g_merchantTimer_guess->PlayerDistance_guess(
                    g_FUN_005370be_spawn_guess,
                    g_FUN_005370be_spawn2_guess, 0.0f);
                if (distance_guess <= 20.0f) {
                    if (window_guess->field_2ac == 0 ||
                        *window_guess->field_2ac == zero_guess) {
                        if (window_guess->selectedItem_2c0 != 0) {
                            ((MerchantSelectedItem_guess*)window_guess->selectedItem_2c0)
                                ->field_16c_guess = 0;
                        }
                        if (window_guess->selectedItemLabel_2b8 != 0) {
                            CXStr text_guess(EQ_ARRAY(char, 0x0063F53F));
                            ((MerchantLabelVtable_guess*)window_guess->selectedItemLabel_2b8)
                                ->Slot63_guess(&text_guess);
                        }
                        if (window_guess->selectedPriceLabel_2bc != 0) {
                            CXStr text_guess(EQ_ARRAY(char, 0x0063F53F));
                            ((MerchantLabelVtable_guess*)window_guess->selectedPriceLabel_2bc)
                                ->Slot63_guess(&text_guess);
                        }
                    }
                } else if (g_busyCount_guess == zero_guess) {
                    ((MerchantWndVtable_guess*)window_guess)->Slot34_guess();
                }
            }
        }
    }
    ((CXWnd*)window_guess)->OnProcessFrame();
}

// Clears the selection and the slot display.
// FUNCTION: TITANIUM 0x00537B4C
void CMerchantWndView_guess::ClearSelection_guess() {
    Active_guess* active = this->active_guess;
    state_id_guess = -1;
    transition_state_guess = 0;
    reset_state_guess = 0;
    if (active != 0) {
        active->value_guess = 0;
    }
    CMerchantWndView_guess* controller = this->controller_guess;
    if (controller != 0) {
        controller->Slot64_guess(0);
    }
    UpdateBuySellButtons_guess();
}

// Clears the selection and shows the merchant's name.
// FUNCTION: TITANIUM 0x00537B8F
char CMerchantWndView_guess::Activate_guess() {
    ClearSelection_guess();
    g_FUN_0044a617_object_guess->Run_guess(6, 1);
    if (field_2b4_guess != 0) {
        CXStr name_guess(g_FUN_004a1350_object_guess->GetText_guess(
            g_FUN_005370be_spawn_guess->name_guess));
        field_2b4_guess->Slot63_guess(&name_guess);
    }
    return 1;
}

// Sell button: a stack asks how many first (quantity window), otherwise sells at once.
// FUNCTION: TITANIUM 0x00537D6A
void CMerchantWndView_guess::HandleSell_guess(int value_guess) {
    if (spell_slot_guess == 0) {
        return;
    }
    Spell_guess* spell_guess = *spell_slot_guess;
    if (spell_guess == 0 || g_FUN_005370be_spawn_guess == 0) {
        return;
    }
    int count_guess;
    if (spell_guess->IsStackable_guess()) {
        count_guess = spell_guess->count_048_guess;
    } else {
        count_guess = 1;
    }
    if (value_guess == -1) {
        Quad_guess local_34_guess;
        Quad_guess local_24_guess;
        Quad_guess local_14_guess;
        local_14_guess.field_C_guess = 0;
        local_14_guess.field_8_guess = 0;
        local_14_guess.field_4_guess = 0;
        local_14_guess.field_0_guess = 0;
        int x_guess;
        int y_guess;
        if (left_guess == 0) {
            x_guess = 0;
            y_guess = 0;
        } else {
            local_14_guess.CopyTo_guess(
                &local_34_guess, left_guess->Slot57_guess(&local_24_guess));
            x_guess = local_14_guess.field_0_guess;
            y_guess = local_14_guess.field_4_guess;
        }
        pinstCQuantityWnd_guess->Function_0054d976_guess(
            this, count_guess, count_guess, x_guess, y_guess, 1);
    } else {
        RequestSellItem(value_guess);
    }
}

struct PcPrefix_0053826a_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct PcBase1_0053826a_guess {
    unsigned char pad_000_guess[0x100];
    // EXTERNAL: TITANIUM 0x0041A259 PcBase1_0053826a_guess::FUN_0041a259_guess
    __int64 FUN_0041a259_guess();
};

struct PcView_0053826a_guess : PcPrefix_0053826a_guess, virtual EQ_Character {
    unsigned char pad_00c_guess[0xC280 - 0x0C];
    PcBase1_0053826a_guess base1_c280_guess;
    unsigned char pad_c380_guess[0xC384 - 0xC380];
};

#define g_pcView_0053826a_guess EQ_GLOBAL(PcView_0053826a_guess*, 0x00905D00)
#define g_itoaBuffer_0053826a_guess EQ_ARRAY(char, 0x0099DB00)

struct PcCharInfo_0053826a_guess {
    unsigned char pad_000_guess[0x88];
    int field_088_guess;
};

struct Msg6dd8_0053826a_guess {
    unsigned char pad_00_guess[4];
    int count_04_guess;
    int value_08_guess;
    unsigned char pad_0c_guess[0x50 - 0x0C];
    int x_50_guess;
    int y_54_guess;
    int value_58_guess;
    unsigned char pad_5c_guess[4];
};

struct Msg221e_0053826a_guess {
    int value_00_guess;
    int value2_04_guess;
    int x_08_guess;
    int y_0c_guess;
    int value_10_guess;
    unsigned char pad_14_guess[4];
};

struct FUN_004b1d79_owner_guess {
    // EXTERNAL: TITANIUM 0x004B1D79 FUN_004b1d79_owner_guess::FormatMoneyText_guess
    int FormatMoneyText_guess();
};

struct Target_0053826a_guess {
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
    virtual FUN_004b1d79_owner_guess* Slot10_guess(float speed_guess, int value_guess);

    unsigned char pad_004_guess[0x80 - 0x04];
    int x_80_guess;
    int y_84_guess;

    // EXTERNAL: TITANIUM 0x005DFCE0 Target_0053826a_guess::FUN_005dfce0_guess
    int FUN_005dfce0_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Target_0053826a_guess::FUN_005e0ec0_guess
    int FUN_005e0ec0_guess();
};

struct Link_0053826a_guess {
    Target_0053826a_guess* target_guess;
};

struct FUN_00537fce_item_guess {
    // EXTERNAL: TITANIUM 0x005E0F60 FUN_00537fce_item_guess::GetDuration_guess
    int GetDuration_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 FUN_00537fce_item_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 FUN_00537fce_item_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 FUN_00537fce_item_guess::GetItem_guess
    FUN_00537fce_item_guess* GetItem_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC650 FUN_00537fce_item_guess::GetItemSlot_guess
    FUN_00537fce_item_guess** GetItemSlot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 FUN_00537fce_item_guess::GetText_guess
    char* GetText_guess();
};

struct FUN_00537fce_mapper_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 FUN_00537fce_mapper_guess::GetIcon_guess
    int GetIcon_guess(int value_guess);
};

#define g_FUN_00537fce_mapper_guess EQ_GLOBAL(FUN_00537fce_mapper_guess*, 0x00991910)

// EXTERNAL: TITANIUM 0x004090FD FormatCoins_guess
CXStr* __cdecl FormatCoins_guess(CXStr* text_guess, int value_guess);

// Selects slot `value`: one of yours (0-330, bags included) or a merchant item (6000+); shows its name and
// asks for the price line.
// FUNCTION: TITANIUM 0x00537FCE
// @early-stop: budget, structural ndiff=39
void CMerchantWndView_guess::SelectBuySellSlot(
    int state_id_guess, Buff_guess* context_guess) {
    this->reset_state_guess = 0;
    this->state_id_guess = state_id_guess;
    this->UpdateBuySellButtons_guess();

    CMerchantWndView_guess::Active_guess** active_slot_guess =
        &this->active_guess;
    if (*active_slot_guess != 0) {
        int duration_guess =
            ((FUN_00537fce_item_guess*)context_guess)->GetDuration_guess();
        int mapped_guess = g_FUN_00537fce_mapper_guess->GetIcon_guess(duration_guess);
        CMerchantWndView_guess::Active_guess* active_guess = *active_slot_guess;
        active_guess->value_guess = mapped_guess;
    }

    FUN_00537fce_item_guess* item_guess;
    int slot_base_guess = 0x1770;
    int result_guess;
    if (this->state_id_guess >= slot_base_guess &&
        this->state_id_guess < 0x17c0) {
        pinstCInvSlotMgr_guess->SetSelection_guess(0);
        int slot_index_guess = this->state_id_guess - slot_base_guess;
        item_guess = (FUN_00537fce_item_guess*)this->slots_guess[slot_index_guess];
        this->spell_slot_guess =
            (Spell_guess**)&this->slots_guess[slot_index_guess];
        result_guess = ((CMerchantWndPriceView_guess*)this)->DisplayBuyOrSellPrice(
            1, (FUN_005372d8_target_guess*)item_guess);
    } else {
        if (g_FUN_005370be_spawn_guess != 0 &&
            g_FUN_005370be_spawn_guess->flag_guess == 0) {
            return;
        }

        if (this->state_id_guess < 0x1f) {
            item_guess = (FUN_00537fce_item_guess*)
                g_pcView_guess->GetFirst_guess(this->state_id_guess);
            this->spell_slot_guess = (Spell_guess**)
                g_pcView_guess->FUN_00434777_guess(this->state_id_guess);
        } else {
            if (this->state_id_guess > 0x14b) {
                return;
            }
            int context_index_guess = (this->state_id_guess - 0x1f) % 10;
            int spell_slot_index_guess = (this->state_id_guess - 0x1f) / 10;
            Spell_guess* spell_guess =
                g_pcView_guess->GetFirst_guess(spell_slot_index_guess);
            if (spell_guess == 0) {
                return;
            }
            spell_guess = g_pcView_guess->GetFirst_guess(spell_slot_index_guess);
            if (spell_guess->GetItemClass_guess() != 1) {
                return;
            }
            spell_guess = g_pcView_guess->GetFirst_guess(spell_slot_index_guess);
            item_guess = ((FUN_00537fce_item_guess*)spell_guess)
                             ->GetItem_guess(context_index_guess);
            this->spell_slot_guess = (Spell_guess**)
                ((FUN_00537fce_item_guess*)spell_guess)
                    ->GetItemSlot_guess(context_index_guess);
        }

        if (item_guess == 0) {
            return;
        }
        if (item_guess->GetItemClass_guess() == 1) {
            for (int index_guess = 0;
                 index_guess < item_guess->GetCount_guess(); ++index_guess) {
                FUN_00537fce_item_guess* child_guess =
                    item_guess->GetItem_guess(index_guess);
                ((CMerchantWndPriceView_guess*)this)->DisplayBuyOrSellPrice(
                    0, (FUN_005372d8_target_guess*)child_guess);
            }
        }
        if (this->controller_guess != 0) {
            ((CListWnd*)this->controller_guess)->SetCurSel(-1);
        }
        result_guess = ((CMerchantWndPriceView_guess*)this)->DisplayBuyOrSellPrice(
            0, (FUN_005372d8_target_guess*)item_guess);
    }

    if (item_guess == 0) {
        return;
    }
    if (this->field_2b8_guess != 0) {
        CXStr text_guess(item_guess->GetText_guess());
        this->field_2b8_guess->Slot63_guess(&text_guess);
    }
    if (this->field_2bc_guess != 0) {
        CXStr text_guess;
        if (result_guess != 0) {
            CXStr* converted_guess = FormatCoins_guess(
                (CXStr*)&result_guess, result_guess);
            text_guess = *converted_guess;
            if (result_guess != 0) {
                ((CXStr*)&result_guess)->FreeRep((CStrRep*)result_guess);
            }
            result_guess = 0;
        }
        this->field_2bc_guess->Slot63_guess(&text_guess);
    }
}

// Buys `value_guess`: refused with an item on the cursor (8548). Traders get OP_TraderBuy (0x60 bytes),
// merchants
// OP_ShopPlayerBuy (24 bytes); short of money prints 12060/12061.
// FUNCTION: TITANIUM 0x0053826A
// @early-stop: budget, structural ndiff=69
void CMerchantWndView_guess::RequestBuyItem(int value_guess) {
    __int64 now_guess;
    char buffer_guess[512];

    if (g_busyCount_guess != 0) {
        return;
    }
    if (link_guess == 0 || link_guess->target_guess == 0) {
        return;
    }
    if (g_FUN_005370be_spawn_guess == 0) {
        return;
    }
    if (value_guess < 1) {
        return;
    }
    PcCharInfo_0053826a_guess* info_guess =
        (PcCharInfo_0053826a_guess*)g_pcView_0053826a_guess->GetCharInfo2();
    if (info_guess->field_088_guess != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2164, 0), 0x114, true);
        return;
    }
    if (state_id_guess - 6000 < 0) {
        return;
    }
    now_guess = g_pcView_0053826a_guess->base1_c280_guess.FUN_0041a259_guess();
    int count_guess = link_guess->target_guess->FUN_005dfce0_guess();
    if (count_guess * value_guess <= now_guess && g_FUN_005370be_spawn_guess != 0) {
        if (g_FUN_005370be_spawn_guess->flag_guess == 0) {
            Msg6dd8_0053826a_guess msg6dd8_guess;
            msg6dd8_guess.value_08_guess = g_FUN_005370be_spawn_guess->value_guess;
            msg6dd8_guess.x_50_guess = link_guess->target_guess->x_80_guess;
            msg6dd8_guess.y_54_guess = link_guess->target_guess->y_84_guess;
            msg6dd8_guess.value_58_guess = value_guess;
            msg6dd8_guess.count_04_guess = link_guess->target_guess->FUN_005dfce0_guess();
            g_busyCount_guess++;
            EQSendMessage(&g_FUN_005370be_connection_guess, OP_TraderBuy, &msg6dd8_guess, 0x60, 1);
        } else {
            Msg221e_0053826a_guess msg221e_guess;
            msg221e_guess.value_00_guess = g_FUN_005370be_spawn_guess->value_guess;
            msg221e_guess.value2_04_guess = g_FUN_005370be_spawn2_guess->value_guess;
            msg221e_guess.x_08_guess = link_guess->target_guess->x_80_guess;
            msg221e_guess.y_0c_guess = link_guess->target_guess->y_84_guess;
            msg221e_guess.value_10_guess = value_guess;
            g_busyCount_guess++;
            EQSendMessage(&g_FUN_005370be_connection_guess, OP_ShopPlayerBuy, &msg221e_guess, 0x18, 1);
        }
        return;
    }
    if (value_guess == 1) {
        FUN_0046da4a_guess(buffer_guess, 0x2f1c,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           link_guess->target_guess->FUN_005e0ec0_guess(),
                           0, 0, 0, 0, 0, 0, 0);
    } else {
        int a4_guess = link_guess->target_guess->Slot10_guess(speed_guess, value_guess)
                           ->FormatMoneyText_guess();
        FUN_0046da4a_guess(buffer_guess, 0x2f1d,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           a4_guess,
                           (int)_itoa(value_guess, g_itoaBuffer_0053826a_guess, 10),
                           link_guess->target_guess->FUN_005e0ec0_guess(),
                           0, 0, 0, 0, 0);
    }
    pEverQuest->dsp_chat(buffer_guess, 0x111, true);
}

struct Msg_005384e2_guess {
    int pad_00_guess;
    int slot_04_guess;
    int value_08_guess;
    int money_0c_guess;
};

#define g_historyIndex_guess EQ_GLOBAL(int, 0x0092398C)
#define g_historyKind_guess EQ_ARRAY(int, 0x00923964)
#define g_historyTime_guess EQ_ARRAY(int, 0x0092393C)
#define g_emptyText_005384e2_guess EQ_ARRAY(char, 0x006410A8)

// EXTERNAL: TITANIUM 0x00464C94 MoveItemQty_guess
void __cdecl MoveItemQty_guess(void* source_guess, Spell_guess** out_guess,
                                int value_guess, int zero_guess, int* value_ptr_guess);
// EXTERNAL: TITANIUM 0x00464E25 GetTextureSlot_guess
int __cdecl GetTextureSlot_guess(int slot_guess);
// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(PcView_guess* pc_guess);
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

// Server confirmed a sale: "You receive%1 from %2 for the %3(s)." (1361, "The merchant" when unnamed), items
// in a sold bag too; errors 1362/1363 for empty slots, 1364 when the merchant refuses. Logs it in the
// 10-entry history.
// FUNCTION: TITANIUM 0x005384E2
// @early-stop: budget, structural ndiff=141
void CMerchantWndView_guess::FinishSellingItem_guess(Msg_005384e2_guess* msg_guess) {
    char buffer_guess[512];
    int value_guess = msg_guess->value_08_guess;
    if (msg_guess->slot_04_guess >= 0) {
    // A sold inventory slot (0-30): the sale line, and for a bag one line per item inside it.
    if (msg_guess->slot_04_guess < InvSlot_PossessionsCount) {
        if (g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess) != 0) {
            if (g_FUN_005370be_spawn_guess == 0) {
                FUN_0046da4a_guess(
                    buffer_guess, 0x551,
                    (const char*)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)
                        ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                    (int)pStringTable->getString(0x555, 0),
                    (int)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->FUN_005e0ec0_guess(),
                    0, 0, 0, 0, 0, 0);
            } else {
                FUN_0046da4a_guess(
                    buffer_guess, 0x551,
                    (const char*)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)
                        ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                    (int)g_FUN_004a1350_object_guess->GetText_guess(
                        g_FUN_005370be_spawn_guess->name_guess),
                    (int)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->FUN_005e0ec0_guess(),
                    0, 0, 0, 0, 0, 0);
            }
            g_FUN_005372d8_player_guess->clock_c280_guess.FUN_0041a3c5_guess(msg_guess->money_0c_guess);
            g_FUN_0044a617_object_guess->WavePlay_guess(0x8a, 0);
            pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
            if (g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->GetItemClass_guess() == 1) {
                Spell_guess* bag_guess = g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess);
                pinstCContainerMgr_guess->CloseContainer_guess(bag_guess, 1);
                for (int i = 0; i < bag_guess->FUN_005ecc30_guess(); i++) {
                    if (bag_guess->FUN_005ec630_guess(i) != 0) {
                        if (g_FUN_005370be_spawn_guess == 0) {
                            FUN_0046da4a_guess(
                                buffer_guess, 0x551,
                                (const char*)bag_guess->FUN_005ec630_guess(i)
                                    ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                                (int)pStringTable->getString(0x555, 0),
                                (int)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->FUN_005e0ec0_guess(),
                                0, 0, 0, 0, 0, 0);
                        } else {
                            FUN_0046da4a_guess(
                                buffer_guess, 0x551,
                                (const char*)bag_guess->FUN_005ec630_guess(i)
                                    ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                                (int)g_FUN_004a1350_object_guess->GetText_guess(
                                    g_FUN_005370be_spawn_guess->name_guess),
                                (int)g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->FUN_005e0ec0_guess(),
                                0, 0, 0, 0, 0, 0);
                        }
                        g_FUN_005372d8_player_guess->clock_c280_guess.FUN_0041a3c5_guess(msg_guess->money_0c_guess);
                        pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
                    }
                }
            }
            if (g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess)->IsStackable_guess()) {
                Spell_guess* out_guess = 0;
                MoveItemQty_guess(g_pcView_guess->FUN_00434777_guess(msg_guess->slot_04_guess),
                                   &out_guess, value_guess, 0, &value_guess);
                if (out_guess != 0) {
                    delete out_guess;
                }
            } else {
                if (msg_guess->slot_04_guess < InvSlot_EquipmentCount) {
                    g_merchantTimer_guess->UpdateItemSlot_guess(
                        g_pcView_guess, msg_guess->slot_04_guess, 0,
                        g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess));
                }
                delete g_pcView_guess->GetFirst_guess(msg_guess->slot_04_guess);
                g_pcView_guess->FUN_0041aa84_guess(msg_guess->slot_04_guess, 0);
            }
            int slot_guess = msg_guess->slot_04_guess;
            if (slot_guess < InvSlot_EquipmentCount) {
                g_FUN_005370be_spawn2_guess->FUN_0048083a_guess(
                    GetTextureSlot_guess(slot_guess), g_emptyText_005384e2_guess, 0);
            }
            UpdateLight_guess(g_pcView_guess);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x552, 0), 0xd, 1);
        }
    } else {
        // Slots from 31 are bag contents: bag (slot - 31) / 10, item (slot - 31) % 10.
        int bag_index_guess = (msg_guess->slot_04_guess - 0x1f) / 10;
        int sub_index_guess = (msg_guess->slot_04_guess - 0x1f) % 10;
        if (g_pcView_guess->GetFirst_guess(bag_index_guess) != 0 &&
            g_pcView_guess->GetFirst_guess(bag_index_guess)->GetItemClass_guess() == 1) {
            Spell_guess* bag_guess = g_pcView_guess->GetFirst_guess(bag_index_guess);
            if (bag_guess->FUN_005ec630_guess(sub_index_guess) != 0) {
                if (g_FUN_005370be_spawn_guess == 0) {
                    FUN_0046da4a_guess(
                        buffer_guess, 0x551,
                        (const char*)bag_guess->FUN_005ec630_guess(sub_index_guess)
                            ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                        (int)pStringTable->getString(0x555, 0),
                        (int)bag_guess->FUN_005ec630_guess(sub_index_guess)->FUN_005e0ec0_guess(),
                        0, 0, 0, 0, 0, 0);
                } else {
                    FUN_0046da4a_guess(
                        buffer_guess, 0x551,
                        (const char*)bag_guess->FUN_005ec630_guess(sub_index_guess)
                            ->Slot10_guess(speed_guess, value_guess)->GetValue2_guess(),
                        (int)g_FUN_004a1350_object_guess->GetText_guess(
                            g_FUN_005370be_spawn_guess->name_guess),
                        (int)bag_guess->FUN_005ec630_guess(sub_index_guess)->FUN_005e0ec0_guess(),
                        0, 0, 0, 0, 0, 0);
                }
                g_FUN_005372d8_player_guess->clock_c280_guess.FUN_0041a3c5_guess(msg_guess->money_0c_guess);
                g_FUN_0044a617_object_guess->WavePlay_guess(0x8a, 0);
                pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
                if (bag_guess->FUN_005ec630_guess(sub_index_guess)->IsStackable_guess()) {
                    Spell_guess* out_guess = 0;
                    MoveItemQty_guess(bag_guess->FUN_005ec650_guess(sub_index_guess),
                                       &out_guess, value_guess, 0, &value_guess);
                    if (out_guess != 0) {
                        delete out_guess;
                    }
                } else {
                    bag_guess->FUN_005ec660_guess(sub_index_guess);
                }
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x552, 0), 0xd, 1);
            }
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x553, 0), 0xd, 1);
        }
    }
    } else {
        if (g_FUN_005370be_spawn_guess == 0) {
            FUN_0046da4a_guess(buffer_guess, 0x554, pStringTable->getString(0x555, 0),
                               0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            FUN_0046da4a_guess(buffer_guess, 0x554,
                               g_FUN_004a1350_object_guess->GetText_guess(
                                   g_FUN_005370be_spawn_guess->name_guess),
                               0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(buffer_guess, 0x113, 1);
    }
    // Every answer releases one pending sale and records a kind-0xC entry in the 10-slot history.
    if (g_busyCount_guess > 0) {
        g_busyCount_guess--;
    } else {
        g_busyCount_guess = 0;
    }
    g_historyIndex_guess++;
    if (g_historyIndex_guess > 9) {
        g_historyIndex_guess = 0;
    }
    g_historyKind_guess[g_historyIndex_guess] = 0xc;
    g_historyTime_guess[g_historyIndex_guess] = FUN_00576e80_guess();
    UpdateLight_guess(g_pcView_guess);
    pinstCInvSlotMgr_guess->Refresh_guess(0);
    if (pinstCTradeskillWnd_guess != 0) {
        pinstCTradeskillWnd_guess->Flush_guess();
    }
}

// Buy button: refuses a Lore item you already have (1573) and a full inventory (1571, general slots 22-29
// and their bags), else asks how many or buys one.
// FUNCTION: TITANIUM 0x00538BCE
void CMerchantWndView_guess::HandleBuy_guess(int value_guess) {
    char buffer_guess[512];
    if (spell_slot_guess == 0) {
        return;
    }
    Spell_guess* spell_guess = *spell_slot_guess;
    if (spell_guess == 0 || g_FUN_005370be_spawn_guess == 0) {
        return;
    }
    if (g_pcView_guess->WouldDuplicateLore_guess(spell_guess) != 0) {
        FUN_0046da4a_guess(buffer_guess, 0x625,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x111, 1);
        return;
    }
    bool missing_guess = false;
    for (int slot_guess = InvSlot_General1; slot_guess <= InvSlot_General8; slot_guess++) {
        if (g_pcView_guess->GetFirst_guess(slot_guess) == 0) {
            missing_guess = true;
        } else if (g_pcView_guess->GetFirst_guess(slot_guess)->GetItemClass_guess() == 1 &&
                   spell_guess->GetItemClass_guess() != 1) {
            Spell_guess* list_guess = g_pcView_guess->GetFirst_guess(slot_guess);
            for (int i = 0; i < list_guess->FUN_005ecc30_guess(); i++) {
                if (list_guess->FUN_005ec630_guess(i) == 0) {
                    missing_guess = true;
                } else if (((Spell_guess*)list_guess->FUN_005ec630_guess(i))->IsStackable_guess() &&
                           spell_guess->IsStackable_guess()) {
                    if (((Spell_guess*)list_guess->FUN_005ec630_guess(i))->GetItemId_guess() ==
                        spell_guess->GetItemId_guess()) {
                        int count_value_guess = ((Spell_guess*)list_guess->FUN_005ec630_guess(i))->count_048_guess;
                        if (count_value_guess !=
                            ((Spell_guess*)list_guess->FUN_005ec630_guess(i))->FUN_005ecd50_guess()) {
                            missing_guess = true;
                        }
                    }
                }
            }
        } else if (g_pcView_guess->GetFirst_guess(slot_guess)->IsStackable_guess() &&
                   spell_guess->IsStackable_guess()) {
            if (g_pcView_guess->GetFirst_guess(slot_guess)->GetItemId_guess() ==
                spell_guess->GetItemId_guess()) {
                int count_value_guess = g_pcView_guess->GetFirst_guess(slot_guess)->count_048_guess;
                if (count_value_guess !=
                    g_pcView_guess->GetFirst_guess(slot_guess)->FUN_005ecd50_guess()) {
                    missing_guess = true;
                }
            }
        }
    }
    if (!missing_guess) {
        FUN_0046da4a_guess(buffer_guess, 0x623,
                           g_FUN_004a1350_object_guess->GetText_guess(
                               g_FUN_005370be_spawn_guess->name_guess),
                           0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer_guess, 0x111, 1);
    } else {
        int count_guess;
        if (spell_guess->IsStackable_guess()) {
            count_guess = spell_guess->FUN_005ecd50_guess();
        } else {
            count_guess = 1;
        }
        if (value_guess == -1) {
            Quad_guess local_34_guess;
            Quad_guess local_24_guess;
            Quad_guess local_14_guess;
            local_14_guess.field_C_guess = 0;
            local_14_guess.field_8_guess = 0;
            local_14_guess.field_4_guess = 0;
            local_14_guess.field_0_guess = 0;
            int x_guess;
            int y_guess;
            if (left_guess == 0) {
                x_guess = 0;
                y_guess = 0;
            } else {
                local_14_guess.CopyTo_guess(
                    &local_34_guess, left_guess->Slot57_guess(&local_24_guess));
                x_guess = local_14_guess.field_0_guess;
                y_guess = local_14_guess.field_4_guess;
            }
            pinstCQuantityWnd_guess->Function_0054d976_guess(
                this, count_guess, count_guess, x_guess, y_guess, 1);
        } else {
            RequestBuyItem(value_guess);
        }
    }
}

struct FUN_00538f24_child_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot75_guess() = 0;
    virtual void Slot76_guess() = 0;
    virtual void Slot77_guess() = 0;
    virtual void Slot78_guess() = 0;

    unsigned char pad_004_guess[0x150];
    int value_154_guess;
    unsigned char flag_158_guess;
};

struct FUN_00538f24_compare_guess {
    int mode_guess;
    CXStr first_text_guess;
    int first_index_guess;
    CXStr second_text_guess;
    int second_index_guess;
    int result_guess;
};

#define g_FUN_005adf60_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x00574460 FUN_00574460_guess
int __cdecl FUN_00574460_guess(char* first_guess, char* second_guess);

// Buy, Sell and Done clicks; a double click (3) on a merchant item shows it and selects it; the quantity
// answer (0x1F) completes the buy or sell; column clicks (0xF) sort, again reverses; 0x10 compares rows for
// the
// sort (text or by value).
// FUNCTION: TITANIUM 0x00538F24
// @early-stop: budget, structural ndiff=213
int CMerchantWndView_guess::WndNotification_guess(CXWnd* child_guess,
                                           int message_guess,
                                           void* data_guess) {
    int event_guess = message_guess;
    if (event_guess == 1) {
        if ((void*)child_guess == (void*)left_guess) {
            HandleBuy_guess(-1);
        } else if ((void*)child_guess == (void*)right_guess) {
            HandleSell_guess(-1);
        } else if (child_guess == (CXWnd*)field_2d0_guess) {
            Slot34_guess();
        } else if ((void*)child_guess == (void*)controller_guess &&
                   !pinstCQuantityWnd_guess->IsVisible_guess()) {
            int row_guess = ((CListWnd*)controller_guess)->GetCurSel();
            if (row_guess != -1) {
                row_guess = ((CListWnd*)controller_guess)->GetItemData(row_guess);
                Buff_guess* item_guess = slots_guess[row_guess];
                if (item_guess != 0) {
                    SelectBuySellSlot(row_guess + 6000, item_guess);
                }
            }
        }
        return 0;
    }
    if (event_guess == 3) {
        if ((void*)child_guess == (void*)controller_guess &&
            !pinstCQuantityWnd_guess->IsVisible_guess()) {
            int row_guess = ((CListWnd*)controller_guess)->GetCurSel();
            if (row_guess != -1) {
                row_guess = ((CListWnd*)controller_guess)->GetItemData(row_guess);
                Buff_guess* item_guess = slots_guess[row_guess];
                if (item_guess != 0) {
                    pinstCItemDisplayManager_guess->SetRaw_guess(
                        item_guess, (~g_FUN_005adf60_guess->GetKeyboardFlags()) & 1);
                    SelectBuySellSlot(row_guess + 6000, item_guess);
                }
            }
        }
        return ((CSidlScreenWnd*)this)->WndNotification(child_guess, event_guess, data_guess);
    }
    if (event_guess == 0x1f) {
        if (spell_slot_guess != 0 && *spell_slot_guess != 0 && IsReady_guess()) {
            if (state_id_guess < 6000 || state_id_guess > 0x17bf) {
                HandleSell_guess(*(int*)data_guess);
            } else {
                HandleBuy_guess(*(int*)data_guess);
            }
            return 0;
        }
        return ((CSidlScreenWnd*)this)->WndNotification(child_guess, event_guess, data_guess);
    }
    if (event_guess == 0x0f) {
        if ((void*)child_guess == (void*)controller_guess) {
            state_id_guess = -1;
            spell_slot_guess = 0;
            if (data_guess != 0) {
                int value_guess = (int)data_guess;
                if (value_guess > 2) {
                    value_guess = 3;
                }
                FUN_00538f24_child_guess* item_guess =
                    (FUN_00538f24_child_guess*)child_guess;
                if (item_guess->value_154_guess == value_guess) {
                    item_guess->flag_158_guess = !item_guess->flag_158_guess;
                } else {
                    item_guess->value_154_guess = value_guess;
                    item_guess->flag_158_guess = 1;
                }
                item_guess->Slot78_guess();
            }
        }
        return ((CSidlScreenWnd*)this)->WndNotification(child_guess, event_guess, data_guess);
    }
    if (event_guess == 0x10 && (void*)child_guess == (void*)controller_guess) {
        FUN_00538f24_compare_guess* compare_guess =
            (FUN_00538f24_compare_guess*)data_guess;
        int mode_guess = compare_guess->mode_guess;
        if (mode_guess == 1) {
            compare_guess->result_guess =
                FUN_00574460_guess(compare_guess->first_text_guess,
                                   compare_guess->second_text_guess);
        } else if (mode_guess == 2) {
            Buff_guess* first_item_guess = slots_guess[compare_guess->first_index_guess];
            Buff_guess* second_item_guess = slots_guess[compare_guess->second_index_guess];
            if (first_item_guess == 0) {
                return 1;
            }
            if (second_item_guess == 0) {
                return -1;
            }
            int first_value_guess = first_item_guess->FUN_005dfcf0_guess();
            int second_value_guess = second_item_guess->FUN_005dfcf0_guess();
            if (first_value_guess == -1) {
                first_value_guess = 1000000;
            }
            if (second_value_guess == -1) {
                second_value_guess = 1000000;
            }
            int difference_guess = first_value_guess - second_value_guess;
            if (difference_guess < 0) {
                compare_guess->result_guess = -1;
            } else if (difference_guess > 0) {
                compare_guess->result_guess = 1;
            } else {
                compare_guess->result_guess = FUN_00574460_guess(
                    first_item_guess->FUN_005e0ec0_guess(),
                    second_item_guess->FUN_005e0ec0_guess());
            }
        } else if (mode_guess > 2 && mode_guess < 7) {
            Buff_guess* first_item_guess = slots_guess[compare_guess->first_index_guess];
            Buff_guess* second_item_guess = slots_guess[compare_guess->second_index_guess];
            if (first_item_guess == 0) {
                return -1;
            }
            if (second_item_guess == 0) {
                return 1;
            }
            int first_duration_guess = first_item_guess->FUN_005dfce0_guess();
            int second_duration_guess = second_item_guess->FUN_005dfce0_guess();
            int difference_guess = first_duration_guess - second_duration_guess;
            if (difference_guess < 0) {
                compare_guess->result_guess = -1;
            } else if (difference_guess > 0) {
                compare_guess->result_guess = 1;
            } else {
                compare_guess->result_guess = FUN_00574460_guess(
                    first_item_guess->FUN_005e0ec0_guess(),
                    second_item_guess->FUN_005e0ec0_guess());
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(child_guess, event_guess, data_guess);
}

// EXTERNAL: TITANIUM 0x0046DAAF CopperToMoneyText_guess
int __cdecl CopperToMoneyText_guess(int target_guess, const char* name_guess,
                               int a_guess, int b_guess, int c_guess,
                               int d_guess, int e_guess, int f_guess,
                               int g_guess);
// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_text_guess
void __cdecl FUN_0046da4a_text_guess(char* buffer_guess, int id_guess,
                                     int value_guess);

struct Request_guess {
    unsigned char pad00_guess[0x08];
    __int64 time_guess;                // 0x08
    unsigned char pad01_guess[0x04];
    int target_guess;                  // 0x14
};

struct Slot_guess {
    unsigned char pad00_guess[0x11D4];
    int value11d4_guess;               // 0x11D4
    int value11d8_guess;               // 0x11D8
    int value11dc_guess;               // 0x11DC
    int value11e0_guess;               // 0x11E0
};

#define g_FUN_00537e10_codes_guess EQ_ARRAY(int, 0x00923964)
#define g_FUN_00537e10_ticks_guess EQ_ARRAY(int, 0x0092393C)
#define g_FUN_00537e10_index_guess EQ_GLOBAL(int, 0x0092398C)

struct CMerchantWndBuyView_guess {
    void FinishBuyingItem_guess(Request_guess* request_guess);
};

// Server answered a purchase: "You give%1 to %2." (string 1437) with the price, or "The item you were
// interested in has already been sold." (1376).
// FUNCTION: TITANIUM 0x00537E10
// @early-stop: unknown, structural ndiff=20
void CMerchantWndBuyView_guess::FinishBuyingItem_guess(Request_guess* request_guess) {
    __int64 time_guess = request_guess->time_guess;
    char text_guess[512];
    if (g_busyCount_guess > 0) {
        g_busyCount_guess--;
    } else {
        g_busyCount_guess = 0;
    }
    g_FUN_00537e10_index_guess++;
    if (g_FUN_00537e10_index_guess > 9) {
        g_FUN_00537e10_index_guess = 0;
    }
    g_FUN_00537e10_codes_guess[g_FUN_00537e10_index_guess] = 0xd;
    g_FUN_00537e10_ticks_guess[g_FUN_00537e10_index_guess] = FUN_00576e80_guess();
    if (time_guess >= 0) {
        if (g_pcView_guess->SpendMoney_guess(request_guess->target_guess) == 0) {
            ((Slot_guess*)g_pcView_guess->FindSlot_guess())->value11e0_guess = 0;
            ((Slot_guess*)g_pcView_guess->FindSlot_guess())->value11dc_guess = 0;
            ((Slot_guess*)g_pcView_guess->FindSlot_guess())->value11d8_guess = 0;
            ((Slot_guess*)g_pcView_guess->FindSlot_guess())->value11d4_guess = 0;
        } else {
            g_FUN_0044a617_object_guess->WavePlay_guess(0x8a, 0);
        }
        int result_guess = CopperToMoneyText_guess(
            request_guess->target_guess,
            g_FUN_005370be_spawn_guess == 0
                ? "the merchant"
                : g_FUN_004a1350_object_guess->GetText_guess(g_FUN_005370be_spawn_guess->name_guess),
            0, 0, 0, 0, 0, 0, 0);
        FUN_0046da4a_text_guess(text_guess, 0x59d, result_guess);
        pEverQuest->dsp_chat(text_guess, 0x114, true);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x560, 0));
    }
    if (pinstCTradeskillWnd_guess != 0) {
        pinstCTradeskillWnd_guess->Flush_guess();
    }
}

