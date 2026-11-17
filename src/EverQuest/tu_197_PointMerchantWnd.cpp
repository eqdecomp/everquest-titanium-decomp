// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 197: a hint from compare/tumap.py.
// CPointMerchantWnd (screen "PointMerchantWnd"): the merchant that sells for points instead of coin, as LDoN
// adventure merchants do (EQEmu's OP_AdventureMerchant* opcodes). Wrapper_guess, UseableWindow_guess,
// StatusOwner_guess, QueueOwner_guess, Applier_guess, MerchantOwner_guess and MerchantWindow_guess are all
// this window. Interface_guess (+0x208) is a per-currency adapter: its slots give the points, the theme names
// and the string ids. 0x905D10 is the merchant NPC.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CQuantityWnd.h"
#include "titanium/wnd/CTradeskillWnd.h"

struct Entry_guess {
    char pad_guess[0x48];
    int value48_guess; // 0x48

    // EXTERNAL: TITANIUM 0x005EC760 Entry_guess::IsStackable_guess
    unsigned char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005E0620 Entry_guess::checkFlag_guess
    int checkFlag_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005ECC30 Entry_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Entry_guess::GetChild_guess
    Entry_guess* GetChild_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC650 Entry_guess::GetValue_guess
    unsigned int* GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005ECCC0 Entry_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0FF0 Entry_guess::getValue170_guess
    int getValue170_guess();
    // EXTERNAL: TITANIUM 0x005E0FC0 Entry_guess::getValue16c_guess
    int getValue16c_guess();
    // EXTERNAL: TITANIUM 0x005E0F90 Entry_guess::clearValue168_guess
    int clearValue168_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Entry_guess::probe_guess
    int probe_guess();
    // EXTERNAL: TITANIUM 0x005EC660 Entry_guess::release_guess
    void release_guess(int index_guess);
};

struct StatusTarget_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;
    virtual void slot35_guess() = 0;
    virtual void slot36_guess() = 0;
    virtual void slot37_guess() = 0;
    virtual void slot38_guess() = 0;
    virtual void slot39_guess() = 0;
    virtual void slot40_guess() = 0;
    virtual void slot41_guess() = 0;
    virtual void slot42_guess() = 0;
    virtual void slot43_guess() = 0;
    virtual void slot44_guess() = 0;
    virtual void slot45_guess() = 0;
    virtual void slot46_guess() = 0;
    virtual void slot47_guess() = 0;
    virtual void slot48_guess() = 0;
    virtual void slot49_guess() = 0;
    virtual void slot50_guess() = 0;
    virtual void slot51_guess() = 0;
    virtual void slot52_guess() = 0;
    virtual void slot53_guess() = 0;
    virtual void slot54_guess() = 0;
    virtual void slot55_guess() = 0;
    virtual void slot56_guess() = 0;
    virtual void* slot57_guess(void* buffer_guess) = 0;
    char pad_guess[0x59];
    bool enabled_guess; // 0x5D
};

struct StatusOwner_guess {
    char pad_guess[0x1C0];
    StatusTarget_guess* target_guess;
    char pad2_guess[0x2C];
    int state_guess;
    unsigned int* value_guess;
    char pad3_guess[0xC];
    int field204_guess; // 0x204

    void update_guess();
    void handleEntry_guess(Entry_guess* entry_guess);
    void setValue_guess(int value_arg_guess);
    void activate_guess(int slot_guess);
    void applySlot_guess(int slot_guess);
};

struct Interface_guess {
    virtual int slot0_guess() = 0;
    virtual char slot1_guess() = 0;
    virtual void slot2_guess() = 0;
    virtual int slot3_guess(int arg_guess) = 0;
    virtual void slot4_guess() = 0;
    virtual int slot5_guess(int arg1_guess, int arg2_guess) = 0;
    virtual int slot6_guess(int arg1_guess, int arg2_guess) = 0;
    virtual int slot7_guess(int arg1_guess, int arg2_guess, int arg3_guess) = 0;
    virtual int slot8_guess() = 0;
    virtual int slot9_guess() = 0;
    virtual void slot10_guess(int arg_guess) = 0;
    virtual int slot11_guess() = 0;
    virtual char slot12_guess() = 0;
    virtual int slot13_guess(int arg1_guess, int arg2_guess) = 0;
    virtual char slot14_guess() = 0;
    virtual int slot15_guess() = 0;
    virtual int slot16_guess() = 0;
    virtual char slot17_guess() = 0;
    virtual int slot18_guess() = 0;
};

struct DisplayManager_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;
    // EXTERNAL: TITANIUM 0x0059DD30 DisplayManager_guess::check_guess
    char check_guess();
};

struct QueueState_guess;
struct Presenter_guess;
struct QueueSlot_guess;
struct QueueCollection_guess;
struct QueueSource_guess;
struct CreepRequest_guess;

struct Wrapper_guess {
    char pad0_guess[0x5C];
    bool active_guess;
    char pad1_guess[0x10E];
    char label_guess[0x49];
    Presenter_guess* presenterA_guess;
    void* equipButton_guess; // 0x1B8
    char pad1bc_guess[0x0C];
    Presenter_guess* pointsAvailableValue_guess; // 0x1C8
    Presenter_guess* presenterB_guess;
    Presenter_guess* sink_guess;
    char pad1c_guess[8];
    QueueSlot_guess** slots_guess; // 0x1DC
    char pad1d_guess[4];
    int index_guess; // 0x1E4
    int field1e8_guess; // 0x1E8
    unsigned char field1ec_guess; // 0x1EC
    char pad1ed_guess[3];
    char pad1f0_guess[8];
    char flag_guess;
    char pad2_guess[3];
    int value_guess;
    int count_guess;
    char pad3_guess[4];
    Interface_guess* interface_guess;

    void handleMessage_guess();
    void sendState_guess();
    void refresh_guess();
    void notifyPresenters_guess();
    void ShowPurchaseCancelled_guess();
    void connect_guess(QueueState_guess* state_guess, Interface_guess* interface_arg_guess);
    void refreshStatus_guess();
    // EXTERNAL: TITANIUM 0x00545EEE Wrapper_guess::finishUpdate_guess
    void finishUpdate_guess(int value_guess, unsigned char flag_guess, unsigned char checked_guess);
    void HandleSellReply_guess(CreepRequest_guess* request_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 Wrapper_guess::check_guess
    char check_guess();
    // EXTERNAL: TITANIUM 0x005A1880 Wrapper_guess::finish_guess
    void finish_guess();
    int slot8_guess();
    int slot7_guess(int arg1_guess, int arg2_guess, int arg3_guess);
    void dispatch4_guess();
    int dispatch5_guess(int arg1_guess, int arg2_guess);
    int dispatch11_guess();
    int dispatch3_guess(int arg_guess);
    void dispatch10_guess(int arg_guess);
    int dispatch16_guess();
    char dispatch1_guess();
    void dispatch2_guess();
    int dispatch6_guess(int arg1_guess, int arg2_guess);
    int dispatch15_guess();
    char dispatch14_guess();
    int dispatch13_guess(int arg1_guess, int arg2_guess);
    char dispatch12_guess();
    char dispatch17_guess();
    int dispatch18_guess();
};

struct QueueState_guess {
    char pad_guess[0x120];
    char name_guess[0x120];
    char pad1_guess[4];
    char flag244_guess;
    char pad2_guess[0x13];
    int value_guess;
};

struct Presenter_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;
    virtual void slot35_guess() = 0;
    virtual void slot36_guess() = 0;
    virtual void slot37_guess() = 0;
    virtual void slot38_guess() = 0;
    virtual void slot39_guess() = 0;
    virtual void slot40_guess() = 0;
    virtual void slot41_guess() = 0;
    virtual void slot42_guess() = 0;
    virtual void slot43_guess() = 0;
    virtual void slot44_guess() = 0;
    virtual void slot45_guess() = 0;
    virtual void slot46_guess() = 0;
    virtual void slot47_guess() = 0;
    virtual void slot48_guess(char value_guess, int flag_guess) = 0;
    virtual void slot49_guess() = 0;
    virtual void slot50_guess() = 0;
    virtual void slot51_guess() = 0;
    virtual void slot52_guess() = 0;
    virtual void slot53_guess() = 0;
    virtual void slot54_guess() = 0;
    virtual void slot55_guess() = 0;
    virtual void slot56_guess() = 0;
    virtual void slot57_guess() = 0;
    virtual void slot58_guess() = 0;
    virtual void slot59_guess() = 0;
    virtual void slot60_guess() = 0;
    virtual void slot61_guess() = 0;
    virtual void slot62_guess() = 0;
    virtual void slot63_guess(const CXStr& text_guess) = 0;
};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::GetKeyboardFlags
    unsigned int GetKeyboardFlags();
    // EXTERNAL: TITANIUM 0x005B0940 CXWndManagerView_guess::BringWndToTop
    void BringWndToTop(Wrapper_guess* owner_guess, int flag_guess);
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)
#define g_queueState_guess EQ_GLOBAL(QueueState_guess*, 0x00905D10)

struct StatusBridge_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;
    virtual void slot35_guess() = 0;
    virtual void slot36_guess() = 0;
    virtual void slot37_guess() = 0;
    virtual void slot38_guess() = 0;
    virtual void slot39_guess() = 0;
    virtual void slot40_guess() = 0;
    virtual void slot41_guess() = 0;
    virtual void slot42_guess() = 0;
    virtual void slot43_guess() = 0;
    virtual void slot44_guess() = 0;
    virtual void slot45_guess() = 0;
    virtual void slot46_guess() = 0;
    virtual void slot47_guess() = 0;
    virtual void slot48_guess() = 0;
    virtual void slot49_guess() = 0;
    virtual void slot50_guess() = 0;
    virtual void slot51_guess() = 0;
    virtual void slot52_guess() = 0;
    virtual void slot53_guess() = 0;
    virtual void slot54_guess() = 0;
    virtual void slot55_guess() = 0;
    virtual void slot56_guess() = 0;
    virtual void slot57_guess() = 0;
    virtual void slot58_guess() = 0;
    virtual void slot59_guess() = 0;
    virtual void slot60_guess() = 0;
    virtual void slot61_guess() = 0;
    virtual void slot62_guess() = 0;
    virtual void slot63_guess() = 0;
    virtual void slot64_guess() = 0;
    virtual void slot65_guess() = 0;
    virtual void slot66_guess() = 0;
    virtual void slot67_guess() = 0;
    virtual void slot68_guess() = 0;
    virtual void slot69_guess() = 0;
    virtual void slot70_guess() = 0;
    virtual void slot71_guess() = 0;
    virtual void slot72_guess() = 0;
    virtual void slot73_guess() = 0;
    virtual void slot74_guess() = 0;
    virtual void slot75_guess() = 0;
    virtual void slot76_guess() = 0;
    // EXTERNAL: TITANIUM 0x00598580 StatusBridge_guess::ClearAllSel
    void ClearAllSel();
};

struct StatusController_guess {
    char pad0_guess[0x1B0];
    StatusBridge_guess* bridge_guess;
    char pad1_guess[8];
    StatusTarget_guess* target_guess;
    char pad2_guess[0x24];
    int reset_guess;

    void clear_guess();
};

struct StringDisplay_guess {
    // EXTERNAL: TITANIUM 0x004982C6 StringDisplay_guess::dsp_chat
    void dsp_chat(const char* text_guess, int type_guess, bool mode_guess);
    // EXTERNAL: TITANIUM 0x00492EC2 StringDisplay_guess::sanitizeName_guess
    char* sanitizeName_guess(const char* text_guess);
};

#define g_stringDisplay_guess EQ_GLOBAL(StringDisplay_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0046DA4A buildTokenString_guess
char* __cdecl buildTokenString_guess(char* buffer_guess, int token_guess,
    const char* p0_guess, ...);

extern "C" void* __cdecl malloc(unsigned int size_guess);
extern "C" void* __cdecl memcpy(void* destination_guess, const void* source_guess,
    unsigned int size_guess);

#define pinstCPointMerchantWnd_guess EQ_GLOBAL(int, 0x00991E28)

struct Connection_guess {
    void sendAndFree_guess(void* data_guess);
};

// EXTERNAL: TITANIUM 0x0060E07D free
extern "C" void __cdecl free(void* memory_guess);

#define g_messageCount_guess EQ_GLOBAL(int, 0x009248D0)

struct RebuildSub_guess {
    // EXTERNAL: TITANIUM 0x005482A0 RebuildSub_guess::reset_guess
    void reset_guess(int value_guess);
};

struct ModeManager_guess {
    // EXTERNAL: TITANIUM 0x0044A617 ModeManager_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int mode_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0044A537 ModeManager_guess::WavePlay_guess
    void WavePlay_guess(int mode_guess, int value_guess);
};

struct MerchantOwner_guess {
    char pad0_guess[0x15C];
    RebuildSub_guess rebuild_guess;
    char pad1_guess[4];
    int itemCount_guess;
    char pad2_guess[0x48];
    int listOwner_guess;
    char pad3_guess[0x0C];
    StatusTarget_guess* statusTarget_guess;
    char pad4_guess[0x18];
    void** items_guess;
    char pad5_guess[0x14];
    int status_guess;
    char pad6_guess[0x10];
    int result_guess;

    // EXTERNAL: TITANIUM 0x005A1FE0 MerchantOwner_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(int owner_guess, const char* name_guess);
    char clearMerchantItems_guess();
};

#define g_modeManager_guess EQ_GLOBAL(ModeManager_guess*, 0x00851390)
#define g_statusWordA_guess EQ_GLOBAL(int, 0x00905D10)
#define g_statusWordB_guess EQ_GLOBAL(int, 0x00905D04)

struct MerchantWindowBase_guess {
    char pad_guess[0x60];
    unsigned int windowStyle_guess; // 0x64
    char pad1_guess[0xBC];
    void* sidlPiece_guess; // 0x124
    char pad2_guess[0x34];
    virtual void slot0_guess();
    // EXTERNAL: TITANIUM 0x005A3850 MerchantWindowBase_guess::MerchantWindowBase_guess
    MerchantWindowBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int GetKeyboardFlags,
        int iniVersion_guess, char* blockName_guess);
    // EXTERNAL: TITANIUM 0x005A3100 MerchantWindowBase_guess::~MerchantWindowBase_guess
    ~MerchantWindowBase_guess();
    // EXTERNAL: TITANIUM 0x0059DB90 MerchantWindowBase_guess::SetLayer_guess
    void SetLayer_guess(int layer_guess);
};

struct PointList_guess : CListWnd {
    char pad_guess[0x1C];
    unsigned char field15c_guess; // 0x15C
    char pad1_guess[0xF];
    unsigned long field16c_guess; // 0x16C
};

struct PointLabel_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x004D22D7 PointLabel_guess::GetText_guess
    CXStr GetText_guess() const;
};

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0063FD9C ??_7MerchantAction_guess@@6B@
struct MerchantAction_guess {
    virtual void slot0_guess();
    // EXTERNAL: TITANIUM 0x005482A0 MerchantAction_guess::reset_guess
    void reset_guess(int value_guess);
    virtual ~MerchantAction_guess() {
        reset_guess(-1);
    }
};

// EXTERNAL: TITANIUM 0x0065A890 ??_7MerchantWindow_guess@@6BMerchantWindowBase_guess@@@
// EXTERNAL: TITANIUM 0x0065A88C ??_7MerchantWindow_guess@@6BMerchantAction_guess@@@
struct MerchantWindow_guess : MerchantWindowBase_guess, MerchantAction_guess {
    int field160_guess; // 0x160
    int field164_guess; // 0x164
    unsigned char field168_guess;
    unsigned char field169_guess;
    unsigned char field16a_guess;
    char pointsLabel_guess[0x40]; // 0x16B
    CXWnd* nameLabel_guess; // 0x1AC
    PointList_guess* itemList_guess; // 0x1B0
    PointList_guess* pointList_guess; // 0x1B4
    CXWnd* equipButton_guess; // 0x1B8
    CXWnd* purchaseButton_guess; // 0x1BC
    CXWnd* sellButton_guess; // 0x1C0
    CXWnd* doneButton_guess; // 0x1C4
    CXWnd* pointsAvailableValue_guess; // 0x1C8
    CXWnd* pointsEverLabel_guess; // 0x1CC
    PointLabel_guess* pointsAvailableLabel_guess; // 0x1D0
    int field1d4_guess; // 0x1D4
    int pad1d8_guess;
    int field1dc_guess; // 0x1DC
    int field1e0_guess; // 0x1E0
    int pad1e4_guess[9];
    int field208_guess; // 0x208

    MerchantWindow_guess(CXWnd* parent_guess);
    virtual ~MerchantWindow_guess();
    void* scalarDeletingDestructor_guess(unsigned int GetKeyboardFlags);
    char process_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory_guess);

struct Clock_guess {
    char pad_guess[0x148];
    unsigned int tick_guess;
    // EXTERNAL: TITANIUM 0x00439D16 Clock_guess::PlayerDistance_guess
    float PlayerDistance_guess(int value_guess, int reference_guess, float scale_guess);
};

#define g_timerSource_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_timerTarget_guess EQ_GLOBAL(int, 0x00905D10)

struct TimerWindow_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;

    char pad_guess[0x1D0];
    unsigned int nextCheck_guess;

    // EXTERNAL: TITANIUM 0x0059DD30 TimerWindow_guess::checkActive_guess
    char checkActive_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 TimerWindow_guess::updateBase_guess
    void updateBase_guess();

    void updateTimer_guess();
};

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(void* value, const char* category, char* input,
    char* output, int size, int mode);

// EXTERNAL: TITANIUM 0x0060BF20 ApplySettingAlt_guess
void __cdecl ApplySettingAlt_guess(void* value, const char* category, char* input);

extern "C" int __cdecl sprintf(char* destination, const char* format, ...);

struct SettingsRef_guess {
    // EXTERNAL: TITANIUM 0x00572300 SettingsRef_guess::Get_guess
    void* Get_guess();
};

struct UseableOption_guess {
    char pad0_guess[0x128];
    unsigned char enabled_guess; // 0x128
    // EXTERNAL: TITANIUM 0x005BB140 UseableOption_guess::SetCheck
    void SetCheck(unsigned char value_guess);
};

struct UseableWindow_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;

    char pad0_guess[0x13C];
    SettingsRef_guess settings_guess; // 0x140
    char pad1_guess[0x23];
    int itemCount_guess; // 0x164
    unsigned char flag168_guess;
    unsigned char flag169_guess;
    unsigned char flag16a_guess;
    char pad1a_guess[0x45];
    QueueCollection_guess* collection_guess; // 0x1B0
    char pad1b_guess[4];
    UseableOption_guess* option_guess; // 0x1B8
    QueueSource_guess* source_guess; // 0x1BC
    StatusTarget_guess* target_guess; // 0x1C0
    void* field1c4_guess;
    char pad2_guess[0x14];
    QueueSlot_guess** slots_guess; // 0x1DC
    char pad3_guess[4];
    int index_guess; // 0x1E4
    int value_guess; // 0x1E8
    unsigned char changed_guess; // 0x1EC
    char pad4_guess[7];
    unsigned int* valueSlot_guess; // 0x1F4
    char pad5_guess[0xC];
    int state_guess; // 0x204
    Interface_guess* interface_guess; // 0x208

    void loadUseable_guess();
    void applyUseable_guess();
    void notifyOption_guess(int value_arg_guess, unsigned char changed_arg_guess,
        unsigned char enabled_arg_guess);
    // EXTERNAL: TITANIUM 0x005A2230 UseableWindow_guess::route_guess
    int route_guess(void* target_arg_guess, int message_arg_guess, void* data_arg_guess);
    int handleNotification_guess(void* target_arg_guess, int message_arg_guess,
        void* data_arg_guess);
};

struct RangeBuffer_guess;
struct StringObject_guess {
    // EXTERNAL: TITANIUM 0x00572300 StringObject_guess::c_str_guess
    const char* c_str_guess();
};

struct CXStrView_guess {
    // EXTERNAL: TITANIUM 0x00571D00 CXStrView_guess::FreeRep
    void FreeRep(void* value_guess);
};

struct QueueCollection_guess {
    // EXTERNAL: TITANIUM 0x0059BB50 QueueCollection_guess::find_guess
    void find_guess(RangeBuffer_guess* result_guess);
    // EXTERNAL: TITANIUM 0x00597C00 QueueCollection_guess::getState_guess
    int getState_guess();
    // EXTERNAL: TITANIUM 0x00597ED0 QueueCollection_guess::GetItemData
    int GetItemData(int index_guess);
    // EXTERNAL: TITANIUM 0x00597BE0 QueueCollection_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597F10 QueueCollection_guess::GetItemText
    StringObject_guess* GetItemText(void* output_guess, int index_guess,
        int GetKeyboardFlags);
};

struct RangeBuffer_guess {
    int count_guess;
    int field4_guess;
    int field8_guess;
    unsigned int shift_guess;
    int** values_guess;

    // EXTERNAL: TITANIUM 0x0047C3AF RangeBuffer_guess::RangeBuffer_guess
    RangeBuffer_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E RangeBuffer_guess::~RangeBuffer_guess
    ~RangeBuffer_guess();
};

// Destructor of the point merchant window (vtable 0x65A890): expires every confirmation dialog its
// dialog-owner part (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd destructor
// (0x005A3100).
// FUNCTION: TITANIUM 0x00545402
MerchantWindow_guess::~MerchantWindow_guess() {
}

// Every 500 ms while shown: closes the window when the merchant is more than 20 units away.
// FUNCTION: TITANIUM 0x0054544E
void TimerWindow_guess::updateTimer_guess() {
    if (checkActive_guess()) {
        unsigned int* duePtr_guess = &nextCheck_guess;
        unsigned int tick_guess = g_timerSource_guess->tick_guess;
        if (tick_guess >= *duePtr_guess) {
            *duePtr_guess = tick_guess + 500;
            if (g_timerTarget_guess != 0) {
                if (g_timerSource_guess->PlayerDistance_guess(g_timerTarget_guess,
                        EQ_GLOBAL(int, 0x00905CE4), 0.0f) > 20.0f) {
                    slot34_guess();
                }
            }
        }
    }
    updateBase_guess();
}

// Disables Sell (+0x1C0) and empties the item list.
// FUNCTION: TITANIUM 0x005454B8
void StatusController_guess::clear_guess() {
    StatusTarget_guess* target = target_guess;
    reset_guess = 0;
    if (target != 0) {
        target->enabled_guess = false;
    }
    if (bridge_guess != 0) {
        bridge_guess->ClearAllSel();
        bridge_guess->slot76_guess();
    }
}

// ShowPurchaseCancelled_guess is misnamed: shows string 0x2167 in chat, probably "purchase cancelled": the confirmation
// was declined or the window is no longer shown.
// FUNCTION: TITANIUM 0x005454EC
void Wrapper_guess::ShowPurchaseCancelled_guess() {
    g_stringDisplay_guess->dsp_chat(
        pStringTable->getString(0x2167, 0), 0x114, 1);
}

// Restores PointMerchant_EquipButton, the only-usable toggle, from OnlyUseable in the character INI ('1', 't'
// or 'T' is on).
// FUNCTION: TITANIUM 0x00545512
void UseableWindow_guess::loadUseable_guess() {
    if (NewUIINI()) {
        char input_guess[256];
        char output_guess[256];
        sprintf(input_guess, "%s", EQ_ARRAY(char, 0x006410A8));
        LoadStringFromUIIniFile_guess(settings_guess.Get_guess(), "OnlyUseable",
            input_guess, output_guess, 0xff, 1);
        unsigned char flag_guess = (output_guess[0] == '1' || output_guess[0] == 't' ||
            output_guess[0] == 'T') ? 1 : 0;
        option_guess->SetCheck(flag_guess);
    }
}

// Saves the only-usable toggle as OnlyUseable "1" or "0".
// FUNCTION: TITANIUM 0x005455BD
void UseableWindow_guess::applyUseable_guess() {
    if (NewUIINI()) {
        char value_guess[256];
        sprintf(value_guess, "%s",
            option_guess->enabled_guess ? EQ_ARRAY(char, 0x00645EB4)
                                        : EQ_ARRAY(char, 0x006410A8));
        ApplySettingAlt_guess(settings_guess.Get_guess(), "OnlyUseable",
            value_guess);
    }
}

// Sell after the confirmation: OP_AdventureMerchantSell 0x97 {currency, NPC id, slot, count}, counted as
// pending (0x9248D0) until the server answers; frees the request.
// FUNCTION: TITANIUM 0x00545633
void Connection_guess::sendAndFree_guess(void* data_guess) {
    ++g_messageCount_guess;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AdventureMerchantSell, data_guess, 0x14, 1);
    free(data_guess);
}

// Sell is enabled while an inventory slot is selected.
// FUNCTION: TITANIUM 0x0054565F
void StatusOwner_guess::update_guess() {
    if (target_guess != 0) {
        target_guess->enabled_guess = state_guess != -1;
    }
}

// dispatch*/slot7/slot8: thunks to the currency adapter's virtual slots, 0 when there is none.
// The meaning of each slot comes from its callers in this file.
// Adds `arg_guess` points (after a sale).
// FUNCTION: TITANIUM 0x00545677
void Wrapper_guess::dispatch10_guess(int arg_guess) {
    if (interface_guess != 0) {
        interface_guess->slot10_guess(arg_guess);
    }
}

// Currency name for chat lines.
// FUNCTION: TITANIUM 0x0054568E
int Wrapper_guess::dispatch16_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot16_guess();
    }
    return 0;
}

// Currency id, the first field of every request.
// FUNCTION: TITANIUM 0x005456A5
int Wrapper_guess::dispatch15_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot15_guess();
    }
    return 0;
}

// Point merchant window: asks its currency adapter (+0x208, slot 14) whether inventory items may be
// offered to this merchant; 0 without an adapter. A slot click (0x00519356) checks it, with the window
// open, before handing the clicked slot to the window (0x00546FA5).
// FUNCTION: TITANIUM 0x005456BC
char Wrapper_guess::dispatch14_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot14_guess();
    }
    return 0;
}

// Price the merchant pays for an item.
// FUNCTION: TITANIUM 0x005456D3
int Wrapper_guess::dispatch13_guess(int arg1_guess, int arg2_guess) {
    if (interface_guess != 0) {
        return interface_guess->slot13_guess(arg1_guess, arg2_guess);
    }
    return 0;
}

// Called when the window opens.
// FUNCTION: TITANIUM 0x005456EC
void Wrapper_guess::dispatch4_guess() {
    if (interface_guess != 0) {
        interface_guess->slot4_guess();
    }
}

// Name of theme `arg1_guess`.
// FUNCTION: TITANIUM 0x00545701
int Wrapper_guess::dispatch5_guess(int arg1_guess, int arg2_guess) {
    if (interface_guess != 0) {
        return interface_guess->slot5_guess(arg1_guess, arg2_guess);
    }
    return 0;
}

// Points available.
// FUNCTION: TITANIUM 0x0054571A
int Wrapper_guess::dispatch11_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot11_guess();
    }
    return 0;
}

// Points available in theme `arg_guess`.
// FUNCTION: TITANIUM 0x00545731
int Wrapper_guess::dispatch3_guess(int arg_guess) {
    if (interface_guess != 0) {
        return interface_guess->slot3_guess(arg_guess);
    }
    return 0;
}

// Whether the window may open.
// FUNCTION: TITANIUM 0x0054574A
char Wrapper_guess::dispatch1_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot1_guess();
    }
    return 0;
}

// Called after the window was shown.
// FUNCTION: TITANIUM 0x00545761
void Wrapper_guess::dispatch2_guess() {
    if (interface_guess != 0) {
        interface_guess->slot2_guess();
    }
}

// String id of the purchase confirmation.
// FUNCTION: TITANIUM 0x00545776
int Wrapper_guess::dispatch6_guess(int arg1_guess, int arg2_guess) {
    if (interface_guess != 0) {
        return interface_guess->slot6_guess(arg1_guess, arg2_guess);
    }
    return 0;
}

// Theme count + 1 (row 0 is skipped).
// FUNCTION: TITANIUM 0x0054578F
int Wrapper_guess::slot8_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot8_guess();
    }
    return 0;
}

// String id of the can't-afford message.
// FUNCTION: TITANIUM 0x005457A6
int Wrapper_guess::slot7_guess(int arg1_guess, int arg2_guess, int arg3_guess) {
    if (interface_guess != 0) {
        return interface_guess->slot7_guess(arg1_guess, arg2_guess, arg3_guess);
    }
    return 0;
}

// Whether the inventory opens with this window.
// FUNCTION: TITANIUM 0x005457BF
char Wrapper_guess::dispatch12_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot12_guess();
    }
    return 0;
}

// Whether the theme lists show.
// FUNCTION: TITANIUM 0x005457D6
char Wrapper_guess::dispatch17_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot17_guess();
    }
    return 0;
}

// Label text for the points, or 0 for the XML text.
// FUNCTION: TITANIUM 0x005457ED
int Wrapper_guess::dispatch18_guess() {
    if (interface_guess != 0) {
        return interface_guess->slot18_guess();
    }
    return 0;
}

// Point merchant window constructor: finds the PointMerchant_ controls, keeps a copy of the points label's
// text, disables Sell, sets up the item and point lists, then disables Sell and empties the item list again
// (0x005454B8) and restores the only-usable toggle from the INI (0x00545512).
// FUNCTION: TITANIUM 0x00545804
MerchantWindow_guess::MerchantWindow_guess(CXWnd* parent_guess)
    : MerchantWindowBase_guess(parent_guess, "PointMerchantWnd", ~0x100, 1, 0) {
    field160_guess = 0;
    field168_guess = 0;
    field169_guess = 0;
    field16a_guess = 0;
    field1e0_guess = 0;
    field1dc_guess = 0;
    nameLabel_guess = 0;
    itemList_guess = 0;
    pointList_guess = 0;
    equipButton_guess = 0;
    purchaseButton_guess = 0;
    sellButton_guess = 0;
    doneButton_guess = 0;
    pointsAvailableValue_guess = 0;
    pointsAvailableLabel_guess = 0;
    pointsEverLabel_guess = 0;
    memset(pointsLabel_guess, 0, sizeof(pointsLabel_guess));
    field164_guess = 0;
    field1d4_guess = 0;
    field208_guess = 0;
    if (sidlPiece_guess != 0) {
        windowStyle_guess |= 0x10000;
        CSidlScreenWnd* sidl_guess = (CSidlScreenWnd*)this;
        sidl_guess->CreateChildrenFromSidl();
        nameLabel_guess = sidl_guess->GetChildItem("PointMerchant_NameLabel");
        itemList_guess = (PointList_guess*)sidl_guess->GetChildItem("PointMerchant_ItemList");
        // Not an equip button: it toggles "only usable items" (OnlyUseable).
        equipButton_guess = sidl_guess->GetChildItem("PointMerchant_EquipButton");
        purchaseButton_guess = sidl_guess->GetChildItem("PointMerchant_PurchaseButton");
        sellButton_guess = sidl_guess->GetChildItem("PointMerchant_SellButton");
        doneButton_guess = sidl_guess->GetChildItem("PointMerchant_DoneButton");
        pointsAvailableValue_guess =
            sidl_guess->GetChildItem("PointMerchant_PointsAvailableValue");
        pointList_guess = (PointList_guess*)sidl_guess->GetChildItem("PointMerchant_PointList");
        pointsEverLabel_guess = sidl_guess->GetChildItem("PointMerchant_PointsEverLabel");
        pointsAvailableLabel_guess = (PointLabel_guess*)sidl_guess->GetChildItem(
            "PointMerchant_PointsAvailableLabel");
        if (pointsAvailableLabel_guess != 0) {
            strcpy(pointsLabel_guess, pointsAvailableLabel_guess->GetText_guess());
        }
        if (sellButton_guess != 0) {
            sellButton_guess->Enabled = 0;
        }
        if (itemList_guess != 0) {
            itemList_guess->SetColors(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
            itemList_guess->field16c_guess = 0xFF8AA3FF;
            itemList_guess->field15c_guess = 1;
            itemList_guess->SetColumnJustification(0, 0);
            itemList_guess->SetColumnJustification(1, 0);
            itemList_guess->SetColumnJustification(2, 0);
        }
        if (pointList_guess != 0) {
            pointList_guess->SetColors(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
            pointList_guess->field16c_guess = 0xFF8AA3FF;
            pointList_guess->field15c_guess = 1;
            pointList_guess->SetColumnJustification(0, 0);
            pointList_guess->SetColumnJustification(1, 0);
        }
        SetLayer_guess(0x14);
        reinterpret_cast<StatusController_guess*>(this)->clear_guess();
        reinterpret_cast<UseableWindow_guess*>(this)->loadUseable_guess();
    }
}

// Scalar deleting destructor of the point merchant window (vtable 0x65A890 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00545C4A
void* MerchantWindow_guess::scalarDeletingDestructor_guess(unsigned int GetKeyboardFlags) {
    this->MerchantWindow_guess::~MerchantWindow_guess();
    if (GetKeyboardFlags & 1) {
        operator delete(this);
    }
    return this;
}

// Shows the theme lists when the adapter wants them and sets the points label.
// FUNCTION: TITANIUM 0x00545C66
void Wrapper_guess::notifyPresenters_guess() {
    if (presenterA_guess != 0 && presenterB_guess != 0) {
        presenterA_guess->slot48_guess(dispatch17_guess(), 1);
        presenterB_guess->slot48_guess(dispatch17_guess(), 1);
    }
    if (sink_guess != 0) {
        if (dispatch18_guess() != 0) {
            CXStr text_guess(reinterpret_cast<const char*>(dispatch18_guess()));
            sink_guess->slot63_guess(text_guess);
        }
        else {
            CXStr text_guess(label_guess);
            sink_guess->slot63_guess(text_guess);
        }
    }
}

// Closing: saves the list layout, frees the items, forgets the merchant and the target (0x905D10, 0x905D04).
// FUNCTION: TITANIUM 0x00545D57
char MerchantOwner_guess::clearMerchantItems_guess() {
    rebuild_guess.reset_guess(-1);
    StoreIniListWnd_guess(listOwner_guess, EQ_ARRAY(char, 0x0065AAF4));
    reinterpret_cast<StatusController_guess*>(this)->clear_guess();
    status_guess = 0;
    g_modeManager_guess->SetMusicSelection_guess(6, 0);
    if (items_guess != 0) {
        for (int i_guess = 0; i_guess < itemCount_guess; ++i_guess) {
            void* item_guess = items_guess[i_guess];
            if (item_guess != 0) {
                free(item_guess);
                items_guess[i_guess] = 0;
            }
        }
        free(items_guess);
        items_guess = 0;
        itemCount_guess = 0;
    }
    g_statusWordA_guess = 0;
    g_statusWordB_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    if (statusTarget_guess != 0) {
        statusTarget_guess->enabled_guess = false;
    }
    result_guess = 0;
    return 1;
}

// On show, opens the inventory window (0x850C34, probably) when the adapter asks and remembers whether it was
// open; on hide, closes it again unless it was.
// FUNCTION: TITANIUM 0x00545E19
void Wrapper_guess::handleMessage_guess() {
    if (active_guess) {
        if (dispatch12_guess()) {
            char result = pinstCInventoryWnd_guess->IsVisible_guess();
            flag_guess = result;
            if (!result) {
                pinstCInventoryWnd_guess->Activate();
            }
        }
        pinstCXWndManager_guess->BringWndToTop(this, 1);
        dispatch2_guess();
    }
    else if (dispatch12_guess() && !flag_guess) {
        pinstCInventoryWnd_guess->Deactivate();
    }
    finish_guess();
}

// Buys: OP_AdventureMerchantPurchase 0x413D {currency, NPC id, item id, quantity}.
// FUNCTION: TITANIUM 0x00545E8D
void Wrapper_guess::sendState_guess() {
    if (count_guess > 0) {
        int data[4];
        data[0] = dispatch15_guess();
        data[2] = value_guess;
        data[3] = count_guess;
        data[1] = g_queueState_guess != 0 ? g_queueState_guess->value_guess : 0;
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AdventureMerchantPurchase, data, 0x10, 1);
    }
}

struct SortItem_guess {
    char text_guess[0x40];        // 0x00: strcmp key and list cell text (sort items)
    int data_guess;               // 0x40
    unsigned int quantity_guess;  // 0x44
    int sortValue_guess;          // 0x48
    char pad_guess[0x10];
    unsigned char enabled_guess;  // 0x5C
};

struct ListColor_guess {
    // EXTERNAL: TITANIUM 0x0059B3E0 ListColor_guess::setColor_guess
    void setColor_guess(int row_guess, int column_guess, unsigned int color_guess);
};

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* a_guess, const char* b_guess);
// EXTERNAL: TITANIUM 0x005738B0 format_guess
void __cdecl format_guess(CXStr* output_guess, const char* fmt_guess, unsigned int value_guess);

// Sorts and refills PointMerchant_ItemList: column 0 name, 1 theme, 2 cost, `changed` for the direction. With
// only-usable on, usable items go first and only they are listed. Rows you can't afford, overall or in the
// item's theme, are grey.
// FUNCTION: TITANIUM 0x00545EEE
// @early-stop: budget, structural ndiff=187
void UseableWindow_guess::notifyOption_guess(int value_arg_guess, unsigned char changed_arg_guess,
    unsigned char enabled_arg_guess) {
    if (slots_guess != 0 && collection_guess != 0) {
        reinterpret_cast<StatusController_guess*>(this)->clear_guess();
        value_guess = value_arg_guess;
        changed_guess = changed_arg_guess;

        for (int outer_guess = 0; outer_guess < itemCount_guess - 1; ++outer_guess) {
            for (int inner_guess = outer_guess + 1; inner_guess < itemCount_guess; ++inner_guess) {
                if (enabled_arg_guess) {
                    if (!reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->enabled_guess &&
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->enabled_guess) {
                        SortItem_guess* swap_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess] =
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess] = swap_guess;
                        continue;
                    }
                    if (!reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->enabled_guess) {
                        continue;
                    }
                }

                if (value_arg_guess == 0) {
                    int compare_guess = strcmp(
                        reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->text_guess,
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->text_guess);
                    if (changed_arg_guess) {
                        if (compare_guess > 0) {
                            SortItem_guess* swap_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess];
                            reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess] =
                                reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess];
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess] = swap_guess;
                        }
                    }
                    else if (compare_guess < 0) {
                        SortItem_guess* swap_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess] =
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess] = swap_guess;
                    }
                }
                else if (value_arg_guess == 1) {
                    if (reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->sortValue_guess !=
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->sortValue_guess &&
                        changed_arg_guess ==
                            (reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->sortValue_guess >
                                reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->sortValue_guess)) {
                        SortItem_guess* swap_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess] =
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess] = swap_guess;
                    }
                }
                else if (value_arg_guess == 2) {
                    if (reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->quantity_guess !=
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->quantity_guess &&
                        changed_arg_guess ==
                            (reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess]->quantity_guess >
                                reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess]->quantity_guess)) {
                        SortItem_guess* swap_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[outer_guess] =
                            reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess];
                        reinterpret_cast<SortItem_guess**>(slots_guess)[inner_guess] = swap_guess;
                    }
                }
            }
        }

        value_arg_guess = 0;
        if (!enabled_arg_guess) {
            value_arg_guess = itemCount_guess;
        }
        else if (itemCount_guess > 0) {
            for (int i_guess = 0; i_guess < itemCount_guess; ++i_guess) {
                if (reinterpret_cast<SortItem_guess**>(slots_guess)[i_guess]->enabled_guess) {
                    ++value_arg_guess;
                }
            }
        }

        for (int row_guess = 0; row_guess < value_arg_guess; ++row_guess) {
            reinterpret_cast<CListWnd*>(collection_guess)->AddString(CXStr("Item"), 0xFFFFFFFF, 0, 0);
        }

        for (int row_guess = 0; row_guess < value_arg_guess; ++row_guess) {
            CXStr text_guess;
            text_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[row_guess]->text_guess;
            reinterpret_cast<CListWnd*>(collection_guess)->SetItemText(row_guess, 0, text_guess);
            text_guess = reinterpret_cast<const char*>(reinterpret_cast<Wrapper_guess*>(this)->dispatch5_guess(
                reinterpret_cast<SortItem_guess**>(slots_guess)[row_guess]->sortValue_guess, 0));
            reinterpret_cast<CListWnd*>(collection_guess)->SetItemText(row_guess, 1, text_guess);
            format_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C),
                reinterpret_cast<SortItem_guess**>(slots_guess)[row_guess]->quantity_guess);
            reinterpret_cast<CListWnd*>(collection_guess)->SetItemText(row_guess, 2, text_guess);
            reinterpret_cast<CListWnd*>(collection_guess)->SetItemData(row_guess,
                reinterpret_cast<SortItem_guess**>(slots_guess)[row_guess]->data_guess);

            SortItem_guess* item_guess = reinterpret_cast<SortItem_guess**>(slots_guess)[row_guess];
            if (static_cast<unsigned int>(reinterpret_cast<Wrapper_guess*>(this)->dispatch11_guess()) <
                    item_guess->quantity_guess ||
                (item_guess->sortValue_guess > 0 &&
                    static_cast<unsigned int>(reinterpret_cast<Wrapper_guess*>(this)->dispatch3_guess(
                        item_guess->sortValue_guess)) < item_guess->quantity_guess)) {
                reinterpret_cast<ListColor_guess*>(collection_guess)->setColor_guess(row_guess, 0, 0xFFC0C0C0);
                reinterpret_cast<ListColor_guess*>(collection_guess)->setColor_guess(row_guess, 1, 0xFFC0C0C0);
                reinterpret_cast<ListColor_guess*>(collection_guess)->setColor_guess(row_guess, 2, 0xFFC0C0C0);
            }
        }

        reinterpret_cast<Presenter_guess*>(collection_guess)->slot48_guess(
            reinterpret_cast<CListWnd*>(collection_guess)->Show, 1);
    }
}

struct SelectionState_guess {
    char pad_guess[0x128];
    unsigned char value128_guess; // 0x128
};

struct ClientDisplayState_guess {
    char pad0_guess[0x252];
    unsigned char race_guess; // 0x252
    char pad1_guess[0xD];
    int class_guess; // 0x260
};

#define g_clientDisplayState_guess EQ_GLOBAL(ClientDisplayState_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x00576D80 readNumber_guess
int __cdecl readNumber_guess(char** source_guess, int delimiter_guess);
// EXTERNAL: TITANIUM 0x00576E00 readText_guess
char* __cdecl readText_guess(char** source_guess, int delimiter_guess);
// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" unsigned int __cdecl strlen(const char* text_guess);

struct QueueSlot_guess {
    char name_guess[0x40];
    int value40_guess; // 0x40
    int count44_guess; // 0x44
    int value48_guess; // 0x48
    int value4c_guess; // 0x4C
    int value50_guess; // 0x50
    unsigned int flags54_guess; // 0x54
    unsigned int flags58_guess; // 0x58
    unsigned char active5c_guess; // 0x5C
};

struct Applier_guess : DisplayManager_guess {
    char pad0_guess[0x160];
    int itemCount_guess; // 0x164
    char pad1_guess[0x48];
    CListWnd* list_guess; // 0x1B0
    char pad2_guess[4];
    SelectionState_guess* selection_guess; // 0x1B8
    char pad3_guess[0x20];
    QueueSlot_guess** rows_guess; // 0x1DC
    int lastParsed_guess; // 0x1E0

    void load_guess(int arg_guess);
    void reload_guess(int arg_guess);
};

// Parses the server's item list: a count and '^', then per item name|item id|cost|theme|?|?|mask|mask^. The
// class_guess / race_guess names here are swapped: flags54_guess is tested with +0x260 of the player (the race;
// 128, 130 and 330 map to bits 13-15) and flags58_guess with +0x252 (the class).
// FUNCTION: TITANIUM 0x0054620C
// @early-stop: unknown, structural ndiff=87
void Applier_guess::load_guess(int arg_guess) {
    if (list_guess == 0) {
        return;
    }
    char* source_guess = reinterpret_cast<char*>(arg_guess);

    CXStr text_guess;
    int item_guess;

    reinterpret_cast<StatusController_guess*>(this)->clear_guess();
    rows_guess = (QueueSlot_guess**)malloc(4000);
    for (int i_guess = 0; i_guess < 1000; ++i_guess) {
        rows_guess[i_guess] = (QueueSlot_guess*)malloc(0x60);
    }

    lastParsed_guess = readNumber_guess(&source_guess, 0x5e);
    item_guess = 0;
    strcpy(rows_guess[item_guess]->name_guess, readText_guess(&source_guess, 0x7c));
    while (strlen(rows_guess[item_guess]->name_guess) != 0) {
        {
            CXStr tag_guess(EQ_ARRAY(char, 0x0065AB0C));
            list_guess->AddString(tag_guess, 0xffffffff, 0, 0);
        }

        rows_guess[item_guess]->value40_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->count44_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->value48_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->value4c_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->value50_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->flags54_guess = readNumber_guess(&source_guess, 0x7c);
        rows_guess[item_guess]->flags58_guess = readNumber_guess(&source_guess, 0x5e);

        int class_guess = g_clientDisplayState_guess->class_guess;
        if (class_guess == 0x80) {
            class_guess = 0xd;
        }
        else if (class_guess == 0x82) {
            class_guess = 0xe;
        }
        else if (class_guess == 0x14a) {
            class_guess = 0xf;
        }
        unsigned int classFlag_guess = 1 << (class_guess - 1);
        unsigned int raceFlag_guess = 1 << (g_clientDisplayState_guess->race_guess - 1);
        rows_guess[item_guess]->active5c_guess =
            (rows_guess[item_guess]->flags54_guess & classFlag_guess) != 0
            && (rows_guess[item_guess]->flags58_guess & raceFlag_guess) != 0;

        text_guess = rows_guess[item_guess]->name_guess;
        list_guess->SetItemText(item_guess, 0, text_guess);
        text_guess = reinterpret_cast<const char*>(
            reinterpret_cast<Wrapper_guess*>(this)->dispatch5_guess(
                rows_guess[item_guess]->value48_guess, 0));
        list_guess->SetItemText(item_guess, 1, text_guess);
        format_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C),
            rows_guess[item_guess]->count44_guess);
        list_guess->SetItemText(item_guess, 2, text_guess);
        list_guess->SetItemData(item_guess, rows_guess[item_guess]->value40_guess);

        if ((unsigned int)reinterpret_cast<Wrapper_guess*>(this)->dispatch11_guess()
                < (unsigned int)rows_guess[item_guess]->count44_guess
            || (unsigned int)reinterpret_cast<Wrapper_guess*>(this)
                ->dispatch3_guess(rows_guess[item_guess]->value48_guess)
                < (unsigned int)rows_guess[item_guess]->count44_guess) {
            reinterpret_cast<ListColor_guess*>(list_guess)
                ->setColor_guess(item_guess, 0, 0xffc0c0c0);
            reinterpret_cast<ListColor_guess*>(list_guess)
                ->setColor_guess(item_guess, 1, 0xffc0c0c0);
        }

        ++item_guess;
        strcpy(rows_guess[item_guess]->name_guess, readText_guess(&source_guess, 0x7c));
    }

    itemCount_guess = item_guess;
    reinterpret_cast<UseableWindow_guess*>(this)->notifyOption_guess(2, 0,
        selection_guess != 0 ? selection_guess->value128_guess : (unsigned char)0);
}

// Opens the merchant: keeps the NPC and adapter, sends OP_AdventureMerchantRequest 0x950 {currency, NPC id}.
// FUNCTION: TITANIUM 0x00546576
void Wrapper_guess::connect_guess(QueueState_guess* state_guess,
    Interface_guess* interface_arg_guess) {
    if (!check_guess()) {
        g_queueState_guess = state_guess;
        interface_guess = interface_arg_guess;
        if (state_guess != 0) {
            int data[2];
            data[0] = dispatch15_guess();
            data[1] = state_guess->value_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AdventureMerchantRequest, data, 8, 1);
        }
    }
}

// Price check for an inventory item: enables Sell when this merchant buys it and says so in chat (strings
// 0x229B-0x229F, singular or plural).
// FUNCTION: TITANIUM 0x005465D1
// @early-stop: budget, structural ndiff=58
void StatusOwner_guess::handleEntry_guess(Entry_guess* entry_guess) {
    if (entry_guess == 0) {
        return;
    }
    Entry_guess* source_guess = entry_guess;
    int rank_guess = entry_guess->clearValue168_guess();
    Wrapper_guess* wrapper_guess = reinterpret_cast<Wrapper_guess*>(this);
    int count_guess = wrapper_guess->dispatch13_guess(
        reinterpret_cast<int>(entry_guess), 1);
    char countText_guess[8];
    sprintf(countText_guess, "%7d", count_guess);
    char message_guess[512];
    if (target_guess != 0) {
        if (entry_guess->checkFlag_guess(1) != 0
                && wrapper_guess->dispatch15_guess()
                    == entry_guess->getValue170_guess()
                && count_guess > 0 && rank_guess >= 0) {
            target_guess->enabled_guess = true;
        }
        else {
            target_guess->enabled_guess = false;
            buildTokenString_guess(message_guess, 0x229B,
                g_stringDisplay_guess->sanitizeName_guess(
                    reinterpret_cast<const char*>(entry_guess =
                        reinterpret_cast<Entry_guess*>(
                            g_queueState_guess->name_guess))),
                reinterpret_cast<const char*>(wrapper_guess->dispatch16_guess()),
                reinterpret_cast<const char*>(source_guess->probe_guess()));
            g_stringDisplay_guess->dsp_chat(message_guess, 0x113, 1);
            return;
        }
    }
    if (entry_guess->GetItemClass_guess() == 0
            && entry_guess->IsStackable_guess() != 0) {
        buildTokenString_guess(message_guess,
            0x229C + (count_guess == 1) * 2,
            g_stringDisplay_guess->sanitizeName_guess(
                reinterpret_cast<const char*>(entry_guess =
                    reinterpret_cast<Entry_guess*>(
                        g_queueState_guess->name_guess))), countText_guess,
            reinterpret_cast<const char*>(wrapper_guess->dispatch16_guess()),
            reinterpret_cast<const char*>(source_guess->probe_guess()),
            0, 0, 0, 0, 0);
    }
    else {
        buildTokenString_guess(message_guess,
            0x229D + (count_guess == 1) * 2,
            g_stringDisplay_guess->sanitizeName_guess(
                reinterpret_cast<const char*>(entry_guess =
                    reinterpret_cast<Entry_guess*>(
                        g_queueState_guess->name_guess))), countText_guess,
            reinterpret_cast<const char*>(wrapper_guess->dispatch16_guess()),
            reinterpret_cast<const char*>(source_guess->probe_guess()),
            0, 0, 0, 0, 0);
    }
    g_stringDisplay_guess->dsp_chat(message_guess, 0x113, 1);
}

// Sells `slot_guess` items from the selected slot. Refused while a sale is pending (0x2F1F), for a bag with
// items (0x2F20), or when a bag's contents are worthless (0x22A3). A bag with items asks first (dialog 0x65,
// string 0x22A4); else OP_AdventureMerchantSell goes out at once.
// FUNCTION: TITANIUM 0x005467A8
void StatusOwner_guess::activate_guess(int slot_guess) {
    char message_guess[512];
    char hasChild_guess = 0;
    if (value_guess == 0) {
        return;
    }
    Entry_guess* entry_guess = reinterpret_cast<Entry_guess*>(*value_guess);
    if (entry_guess == 0 || g_queueState_guess == 0 || slot_guess < 1) {
        return;
    }
    int state_value_guess = state_guess;
    if (state_value_guess < 0 || state_value_guess > 0x14B) {
        return;
    }
    if (g_messageCount_guess != 0) {
        buildTokenString_guess(message_guess, 0x2F1F,
            g_stringDisplay_guess->sanitizeName_guess(
                g_queueState_guess->name_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message_guess, 0x111, 1);
        return;
    }
    if (entry_guess->checkFlag_guess(1) != 0) {
        if (entry_guess->getValue170_guess()
                == reinterpret_cast<Wrapper_guess*>(this)->dispatch15_guess()
            && entry_guess->getValue16c_guess() > 0) {
                entry_guess->clearValue168_guess();
                if (entry_guess->GetItemClass_guess() == 1) {
                    for (int index_guess = 0;
                            index_guess < entry_guess->GetCount_guess();
                            ++index_guess) {
                        if (entry_guess->GetChild_guess(index_guess) != 0) {
                            buildTokenString_guess(message_guess, 0x2F20,
                                g_stringDisplay_guess->sanitizeName_guess(
                                    g_queueState_guess->name_guess),
                                0, 0, 0, 0, 0, 0, 0, 0);
                            pEverQuest->dsp_chat(message_guess, 0x111, 1);
                            return;
                        }
                    }
                    if (pinstCContainerMgr_guess != 0) {
                        pinstCContainerMgr_guess->CloseEQContainer_guess(entry_guess);
                    }
                }
                else {
                    for (int index_guess = 0; index_guess < 10; ++index_guess) {
                        if (entry_guess->GetChild_guess(index_guess) != 0) {
                            if (entry_guess->GetChild_guess(index_guess)
                                    ->getValue16c_guess() <= 0) {
                                buildTokenString_guess(message_guess, 0x22A3,
                                    g_stringDisplay_guess->sanitizeName_guess(
                                        g_queueState_guess->name_guess),
                                    0, 0, 0, 0, 0, 0, 0, 0);
                                pEverQuest->dsp_chat(message_guess, 0x111, 1);
                                return;
                            }
                            hasChild_guess = 1;
                        }
                    }
                }
                int data_guess[5];
                data_guess[0] =
                    reinterpret_cast<Wrapper_guess*>(this)->dispatch15_guess();
                data_guess[1] = g_queueState_guess->value_guess;
                data_guess[3] = slot_guess;
                data_guess[2] = state_value_guess;
                if (target_guess != 0) {
                    target_guess->enabled_guess = false;
                }
                if (hasChild_guess) {
                    int* copy_guess = reinterpret_cast<int*>(malloc(0x14));
                    memcpy(copy_guess, data_guess, 0x14);
                    pConfirmationDialogPool_guess->Activate(
                        (void*)(pinstCPointMerchantWnd_guess
                            ? pinstCPointMerchantWnd_guess + 0x15C : 0),
                        0x65, pStringTable->getString(0x22A4, 0), 0xC, -1,
                        reinterpret_cast<int>(copy_guess), 1);
                    return;
                }
                ++g_messageCount_guess;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AdventureMerchantSell, data_guess,
                    0x14, 1);
                return;
            }
        }
        buildTokenString_guess(message_guess, 0x2F1E,
            g_stringDisplay_guess->sanitizeName_guess(
                g_queueState_guess->name_guess),
            0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message_guess, 0x111, 1);
}

struct PointListUpdate_guess {
    // EXTERNAL: TITANIUM 0x0059B9D0 PointListUpdate_guess::AddString
    void AddString(const CXStr& text_guess, int index_guess, int column_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0059B360 PointListUpdate_guess::SetItemText
    void SetItemText(int index_guess, int column_guess, CXStr* text_guess);
};

struct ButtonState_guess {
    char pad_guess[0x128];
    unsigned char checked_guess; // 0x128
};

// Redraws the points: the total, and per theme its name and points.
// FUNCTION: TITANIUM 0x00546A64
// @early-stop: budget, diff ndiff=16
void Wrapper_guess::refreshStatus_guess() {
    if (interface_guess != 0) {
        interface_guess->slot0_guess();
    }
    if (pointsAvailableValue_guess != 0) {
        char valueText_guess[12];
        sprintf(valueText_guess, EQ_ARRAY(char, 0x0063F53C), dispatch11_guess());
        CXStr value_guess(valueText_guess);
        pointsAvailableValue_guess->slot63_guess(value_guess);
    }
    if (presenterA_guess != 0) {
        reinterpret_cast<StatusBridge_guess*>(presenterA_guess)->ClearAllSel();
        reinterpret_cast<StatusBridge_guess*>(presenterA_guess)->slot76_guess();
        for (int index_guess = 1; index_guess < slot8_guess(); ++index_guess) {
            CXStr itemText_guess;
            {
                CXStr emptyText_guess(EQ_ARRAY(char, 0x006410A8));
                reinterpret_cast<PointListUpdate_guess*>(presenterA_guess)
                    ->AddString(emptyText_guess, -1, 0, 0);
            }
            itemText_guess = reinterpret_cast<const char*>(dispatch5_guess(index_guess, 0));
            reinterpret_cast<PointListUpdate_guess*>(presenterA_guess)
                ->SetItemText(index_guess - 1, 0, &itemText_guess);
            format_guess(&itemText_guess, EQ_ARRAY(char, 0x0063F53C),
                static_cast<unsigned int>(dispatch3_guess(index_guess)));
            reinterpret_cast<PointListUpdate_guess*>(presenterA_guess)
                ->SetItemText(index_guess - 1, 1, &itemText_guess);
        }
    }
    unsigned char checked_guess = 0;
    if (equipButton_guess != 0) {
        checked_guess = reinterpret_cast<ButtonState_guess*>(equipButton_guess)->checked_guess;
    }
    finishUpdate_guess(field1e8_guess, field1ec_guess, checked_guess);
}

// Opening: merchant name, adapter, points, list layout from the INI.
// FUNCTION: TITANIUM 0x00546C1F
char MerchantWindow_guess::process_guess() {
    Wrapper_guess* wrapper_guess = reinterpret_cast<Wrapper_guess*>(this);
    if (!wrapper_guess->dispatch1_guess() || sidlPiece_guess == 0) {
        return 0;
    }

    g_modeManager_guess->SetMusicSelection_guess(6, 1);
    if (nameLabel_guess != 0 && g_queueState_guess != 0) {
        CXStr name_guess(g_stringDisplay_guess->sanitizeName_guess(
            g_queueState_guess->name_guess));
        reinterpret_cast<Presenter_guess*>(nameLabel_guess)->slot63_guess(
            name_guess);
    }

    wrapper_guess->dispatch4_guess();
    wrapper_guess->refreshStatus_guess();
    PointList_guess* list_guess = itemList_guess;
    if (list_guess != 0) {
        reinterpret_cast<Presenter_guess*>(list_guess)->slot48_guess(
            list_guess->Show, 1);
        reinterpret_cast<CSidlScreenWnd*>(this)->LoadIniListWnd(
            itemList_guess, EQ_ARRAY(char, 0x0065AAF4));
    }
    PointList_guess* points_guess = pointList_guess;
    if (points_guess != 0) {
        reinterpret_cast<Presenter_guess*>(points_guess)->slot48_guess(
            points_guess->Show, 1);
    }
    wrapper_guess->notifyPresenters_guess();
    return 1;
}

// Purchase confirmed: buys if the window is still open.
// FUNCTION: TITANIUM 0x00546D1E
void Wrapper_guess::refresh_guess() {
    if (check_guess() == 0) {
        ShowPurchaseCancelled_guess();
    }
    else {
        sendState_guess();
    }
}

// Shows the window and loads the item list.
// FUNCTION: TITANIUM 0x00546E80
void Applier_guess::reload_guess(int arg_guess) {
    slot33_guess();
    load_guess(arg_guess);
}

struct MessageSink_guess {
    void handle_guess(int id_guess, unsigned char GetKeyboardFlags, void* data_guess);
};

// Confirmation answers (yes is flags 1 or 4): dialog 0x64 buys, dialog 0x65 sells the bag.
// FUNCTION: TITANIUM 0x00546E9A
void MessageSink_guess::handle_guess(int id_guess, unsigned char GetKeyboardFlags,
    void* data_guess) {
    if (id_guess == 0x64) {
        Wrapper_guess* wrapper_guess = reinterpret_cast<Wrapper_guess*>(
            reinterpret_cast<char*>(this) - 0x15C);
        if ((GetKeyboardFlags & 5) != 0) {
            wrapper_guess->refresh_guess();
        }
        else {
            wrapper_guess->ShowPurchaseCancelled_guess();
        }
    }
    else if (id_guess == 0x65) {
        if ((GetKeyboardFlags & 5) != 0) {
            Connection_guess* connection_guess = reinterpret_cast<Connection_guess*>(
                reinterpret_cast<char*>(this) - 0x15C);
            connection_guess->sendAndFree_guess(data_guess);
        }
        else {
            free(data_guess);
        }
    }
}

struct CharInfoState_guess {
    char pad_guess[0x78];
    int state_guess;
};

struct CharInfoOuter_guess {
    char pad_guess[0x10];
    CharInfoState_guess sub_guess;
};

// pCharData's class: vfptr and int at +0, vbptr at +8, the profile in the virtual base.
struct CharDataPrefix_guess {
    virtual void slot00_guess() = 0;
    int field04_guess;
};

// The virtual base: vfptr at +0, the profile at +4.
struct CharDataVirtual_guess {
    void* vftable_guess;
    EQ_CharacterProfile_guess profile_guess;

    CHARINFO2* Lookup_guess() {
        return profile_guess.GetCharInfo2();
    }

    // EXTERNAL: TITANIUM 0x0040CC50 CharDataVirtual_guess::GetEntry_guess
    Entry_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00434777 CharDataVirtual_guess::GetSlot_guess
    unsigned int* GetSlot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 CharDataVirtual_guess::SetSlot_guess
    void SetSlot_guess(int index_guess, int value_guess);
};

struct CharDataRoot_guess : CharDataPrefix_guess, virtual CharDataVirtual_guess {
};

#define g_charData_guess EQ_GLOBAL(CharDataRoot_guess*, 0x00905D00)

struct Pair_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x004D9160 Pair_guess::Copy_guess
    void Copy_guess(void* destination_guess, void* source_guess);
};

struct QueueSource_guess {
    virtual void slot00_guess() = 0;
    virtual void slot01_guess() = 0;
    virtual void slot02_guess() = 0;
    virtual void slot03_guess() = 0;
    virtual void slot04_guess() = 0;
    virtual void slot05_guess() = 0;
    virtual void slot06_guess() = 0;
    virtual void slot07_guess() = 0;
    virtual void slot08_guess() = 0;
    virtual void slot09_guess() = 0;
    virtual void slot10_guess() = 0;
    virtual void slot11_guess() = 0;
    virtual void slot12_guess() = 0;
    virtual void slot13_guess() = 0;
    virtual void slot14_guess() = 0;
    virtual void slot15_guess() = 0;
    virtual void slot16_guess() = 0;
    virtual void slot17_guess() = 0;
    virtual void slot18_guess() = 0;
    virtual void slot19_guess() = 0;
    virtual void slot20_guess() = 0;
    virtual void slot21_guess() = 0;
    virtual void slot22_guess() = 0;
    virtual void slot23_guess() = 0;
    virtual void slot24_guess() = 0;
    virtual void slot25_guess() = 0;
    virtual void slot26_guess() = 0;
    virtual void slot27_guess() = 0;
    virtual void slot28_guess() = 0;
    virtual void slot29_guess() = 0;
    virtual void slot30_guess() = 0;
    virtual void slot31_guess() = 0;
    virtual void slot32_guess() = 0;
    virtual void slot33_guess() = 0;
    virtual void slot34_guess() = 0;
    virtual void slot35_guess() = 0;
    virtual void slot36_guess() = 0;
    virtual void slot37_guess() = 0;
    virtual void slot38_guess() = 0;
    virtual void slot39_guess() = 0;
    virtual void slot40_guess() = 0;
    virtual void slot41_guess() = 0;
    virtual void slot42_guess() = 0;
    virtual void slot43_guess() = 0;
    virtual void slot44_guess() = 0;
    virtual void slot45_guess() = 0;
    virtual void slot46_guess() = 0;
    virtual void slot47_guess() = 0;
    virtual void slot48_guess() = 0;
    virtual void slot49_guess() = 0;
    virtual void slot50_guess() = 0;
    virtual void slot51_guess() = 0;
    virtual void slot52_guess() = 0;
    virtual void slot53_guess() = 0;
    virtual void slot54_guess() = 0;
    virtual void slot55_guess() = 0;
    virtual void slot56_guess() = 0;
    virtual void* slot57_guess(void* buffer_guess) = 0;
    char pad_guess[0x59];
    unsigned char enabled_guess; // 0x5D
};


struct QueueOwner_guess {
    char pad0_guess[0x1BC];
    QueueSource_guess* source_guess;
    char pad1_guess[0x44];
    int field204_guess;

    void ConfirmPurchase_guess(int mode_guess);
    void update_guess(int first_guess, int second_guess, int third_guess);
};

#define g_flag9254b4_guess EQ_GLOBAL(int, 0x009254B4)

// ConfirmPurchase_guess is misnamed: asks to confirm buying `mode_guess` of the selected item (dialog 0x64), or buys at once
// when 0x9254B4 is set (probably a no-confirm option).
// FUNCTION: TITANIUM 0x00546D37
void QueueOwner_guess::ConfirmPurchase_guess(int mode_guess) {
    Wrapper_guess* self_guess = reinterpret_cast<Wrapper_guess*>(this);
    self_guess->count_guess = mode_guess;
    QueueSlot_guess** entry_guess =
        &self_guess->slots_guess[self_guess->index_guess];
    self_guess->value_guess = (*entry_guess)->value40_guess;
    if (g_flag9254b4_guess == 0) {
        QueueSlot_guess* slot_guess = *entry_guess;
        char buffer_guess[500];
        char local14_guess[12];
        char local20_guess[12];
        char local2c_guess[12];
        if (mode_guess == 1) {
            int count_guess = slot_guess->count44_guess;
            sprintf(local14_guess, "%d", count_guess);
            buildTokenString_guess(buffer_guess,
                self_guess->dispatch6_guess(1, count_guess), local14_guess,
                reinterpret_cast<const char*>(
                    self_guess->slots_guess[self_guess->index_guess]),
                0, 0, 0, 0, 0, 0, 0);
        }
        else {
            int count_guess = slot_guess->count44_guess;
            sprintf(local20_guess, "%d", mode_guess);
            sprintf(local14_guess, "%d", count_guess);
            sprintf(local2c_guess, "%d", count_guess * mode_guess);
            buildTokenString_guess(buffer_guess,
                self_guess->dispatch6_guess(mode_guess, count_guess),
                local2c_guess,
                local20_guess,
                reinterpret_cast<const char*>(
                    self_guess->slots_guess[self_guess->index_guess]),
                local14_guess, 0, 0, 0, 0, 0);
        }
        pConfirmationDialogPool_guess->Activate(
            (void*)(pinstCPointMerchantWnd_guess ? pinstCPointMerchantWnd_guess + 0x15C : 0),
            0x64, buffer_guess, 0xC, -1, 0, 1);
    }
    else {
        reinterpret_cast<Wrapper_guess*>(this)->sendState_guess();
    }
}

// Sell: a stack asks for the count in the quantity window (0x850C3C); `slot_guess` >= 0 sells that many.
// FUNCTION: TITANIUM 0x00546EE3
void StatusOwner_guess::applySlot_guess(int slot_guess) {
    if (value_guess == 0) {
        return;
    }
    Entry_guess* entry_guess = reinterpret_cast<Entry_guess*>(*value_guess);
    if (entry_guess == 0) {
        return;
    }
    if (g_queueState_guess == 0) {
        return;
    }
    int flag_guess;
    if (entry_guess->IsStackable_guess()) {
        flag_guess = entry_guess->value48_guess;
    }
    else {
        flag_guess = 1;
    }
    if (slot_guess == -1) {
        int buffer_guess[4];
        int dest_guess[4];
        Pair_guess pair_guess;
        pair_guess.values_guess[3] = 0;
        pair_guess.values_guess[2] = 0;
        pair_guess.values_guess[1] = 0;
        pair_guess.values_guess[0] = 0;
        int first_guess_v;
        int second_guess_v;
        if (target_guess == 0) {
            first_guess_v = 0;
            second_guess_v = 0;
        }
        else {
            void* value_guess_v = target_guess->slot57_guess(buffer_guess);
            pair_guess.Copy_guess(dest_guess, value_guess_v);
            first_guess_v = pair_guess.values_guess[0];
            second_guess_v = pair_guess.values_guess[1];
        }
        if (pinstCQuantityWnd_guess != 0) {
            field204_guess = 1;
            pinstCQuantityWnd_guess->Function_0054d976_guess(this, flag_guess, flag_guess,
                first_guess_v, second_guess_v, 1);
        }
    }
    else {
        activate_guess(slot_guess);
    }
}

// Inventory slot `value_arg_guess` was selected (0-30 top level, 31-331 bag contents): checks the item and,
// for a bag, each item in it.
// FUNCTION: TITANIUM 0x00546FA5
void StatusOwner_guess::setValue_guess(int value_arg_guess) {
    value_guess = 0;
    state_guess = value_arg_guess;
    update_guess();
    if (g_queueState_guess != 0 && g_queueState_guess->flag244_guess == 0) {
        return;
    }

    Entry_guess* entry_guess;
    unsigned int* slot_guess;
    if (state_guess < 0x1F) {
        entry_guess = g_charData_guess->GetEntry_guess(state_guess);
        slot_guess = g_charData_guess->GetSlot_guess(state_guess);
    }
    else if (state_guess <= 0x14B) {
        int group_guess = (state_guess - 0x1F) / 10;
        int sub_guess = (state_guess - 0x1F) % 10;
        if (g_charData_guess->GetEntry_guess(group_guess) == 0) {
            return;
        }
        if (g_charData_guess->GetEntry_guess(group_guess)->GetItemClass_guess() != 1) {
            return;
        }
        Entry_guess* groupEntry_guess =
            g_charData_guess->GetEntry_guess(group_guess);
        entry_guess = groupEntry_guess->GetChild_guess(sub_guess);
        slot_guess = groupEntry_guess->GetValue_guess(sub_guess);
    }
    else {
        if (target_guess != 0) {
            target_guess->enabled_guess = false;
        }
        return;
    }

    value_guess = slot_guess;
    if (entry_guess != 0) {
        if (entry_guess->GetItemClass_guess() == 1) {
            for (int i_guess = 0; i_guess < entry_guess->GetCount_guess();
                    ++i_guess) {
                handleEntry_guess(entry_guess->GetChild_guess(i_guess));
            }
        }
        else {
            for (int i_guess = 0; i_guess < 10; ++i_guess) {
                Entry_guess* child_guess = entry_guess->GetChild_guess(i_guess);
                if (child_guess != 0) {
                    handleEntry_guess(child_guess);
                }
            }
        }
        handleEntry_guess(entry_guess);
    }
    else if (target_guess != 0) {
        target_guess->enabled_guess = false;
    }
}

// Request block: id at +8, extra at +0xC, count at +0x10.
struct CreepRequest_guess {
    char pad_guess[8];
    int id_guess;
    int extra_guess;
    int count_guess;
};

// An entry's vptr slot 0 is a deleter: slot0(1).
struct Deletable_guess {
    virtual void slot0_guess(int flag_guess) = 0;
};

struct LocalPlayer_guess {
    // EXTERNAL: TITANIUM 0x0048083A LocalPlayer_guess::Notify_guess
    void Notify_guess(char* text_guess, const char* name_guess, int flag_guess);
};

#define g_localPlayer_guess EQ_GLOBAL(LocalPlayer_guess*, 0x00905CE4)
#define g_ringIndex_guess EQ_GLOBAL(int, 0x0092398C)
#define g_ringCodes_guess EQ_ARRAY(int, 0x00923964)
#define g_ringTimes_guess EQ_ARRAY(unsigned int, 0x0092393C)

// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(void* data_guess);
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();
// EXTERNAL: TITANIUM 0x00464C94 MoveItemQty_guess
void __cdecl MoveItemQty_guess(unsigned int* slot_guess, void* out_guess,
    int extra_guess, int zero_guess, int* index_guess);
// EXTERNAL: TITANIUM 0x00464E25 GetTextureSlot_guess
char* __cdecl GetTextureSlot_guess(int id_guess, const char* text_guess, int flag_guess);

// Prints the sale (string 0x22A0, 0x22A1 for one), adds the points and
// removes the item or part of the stack; a negative slot means the merchant refused (0x554).
// FUNCTION: TITANIUM 0x00547115
// @early-stop: budget, structural ndiff=30
void Wrapper_guess::HandleSellReply_guess(CreepRequest_guess* request_guess) {
    char buffer_guess[512];
    char count_guess[8];
    sprintf(count_guess, "%7d", request_guess->count_guess);
    int extra_guess = request_guess->extra_guess;
    int token_guess = request_guess->count_guess == 1 ? 0x22A1 : 0x22A0;
    if (request_guess->id_guess >= 0) {
        pinstCInvSlotMgr_guess->SetSelection_guess(0);
        if (request_guess->id_guess < 0x1F) {
            if (g_charData_guess->GetEntry_guess(request_guess->id_guess) != 0) {
                if (g_queueState_guess == 0) {
                    buildTokenString_guess(buffer_guess, token_guess, count_guess,
                        reinterpret_cast<const char*>(dispatch16_guess()),
                        pStringTable->getString(0x555, 0),
                        reinterpret_cast<const char*>(g_charData_guess->GetEntry_guess(
                            request_guess->id_guess)->probe_guess()),
                        0, 0, 0, 0, 0);
                }
                else {
                    char* name_guess = g_queueState_guess->name_guess;
                    buildTokenString_guess(buffer_guess, token_guess, count_guess,
                        reinterpret_cast<const char*>(dispatch16_guess()),
                        g_stringDisplay_guess->sanitizeName_guess(name_guess),
                        reinterpret_cast<const char*>(g_charData_guess->GetEntry_guess(
                            request_guess->id_guess)->probe_guess()),
                        0, 0, 0, 0, 0);
                }
                dispatch10_guess(request_guess->count_guess);
                g_modeManager_guess->WavePlay_guess(0x8a, 0);
                pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
                if (g_charData_guess->GetEntry_guess(request_guess->id_guess)->GetItemClass_guess() == 1) {
                    Entry_guess* group_guess = g_charData_guess->GetEntry_guess(request_guess->id_guess);
                    pinstCContainerMgr_guess->CloseContainer_guess(group_guess, 1);
                    for (int i_guess = 0; i_guess < group_guess->GetCount_guess(); ++i_guess) {
                        if (group_guess->GetChild_guess(i_guess) != 0) {
                            if (g_queueState_guess == 0) {
                                buildTokenString_guess(buffer_guess, token_guess, count_guess,
                                    reinterpret_cast<const char*>(dispatch16_guess()),
                                    pStringTable->getString(0x555, 0),
                                    reinterpret_cast<const char*>(g_charData_guess->GetEntry_guess(
                                        request_guess->id_guess)->probe_guess()),
                                    0, 0, 0, 0, 0);
                            }
                            else {
                                char* name_guess = g_queueState_guess->name_guess;
                                buildTokenString_guess(buffer_guess, token_guess, count_guess,
                                    reinterpret_cast<const char*>(dispatch16_guess()),
                                    g_stringDisplay_guess->sanitizeName_guess(name_guess),
                                    reinterpret_cast<const char*>(g_charData_guess->GetEntry_guess(
                                        request_guess->id_guess)->probe_guess()),
                                    0, 0, 0, 0, 0);
                            }
                            dispatch10_guess(request_guess->count_guess);
                            pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
                        }
                    }
                }
                if (g_charData_guess->GetEntry_guess(request_guess->id_guess)->IsStackable_guess()) {
                    Entry_guess* out_guess = 0;
                    int index_guess;
                    MoveItemQty_guess(g_charData_guess->GetSlot_guess(request_guess->id_guess),
                        &out_guess, extra_guess, 0, &index_guess);
                    if (out_guess != 0) {
                        reinterpret_cast<Deletable_guess*>(out_guess)->slot0_guess(1);
                    }
                }
                else {
                    Entry_guess* old_guess = g_charData_guess->GetEntry_guess(request_guess->id_guess);
                    if (old_guess != 0) {
                        reinterpret_cast<Deletable_guess*>(old_guess)->slot0_guess(1);
                    }
                    g_charData_guess->SetSlot_guess(request_guess->id_guess, 0);
                }
                // Worn slots (below 22) also update how the character looks.
                if (request_guess->id_guess < 0x16) {
                    char* text_guess = GetTextureSlot_guess(request_guess->id_guess,
                        EQ_ARRAY(char, 0x006410A8), 0);
                    g_localPlayer_guess->Notify_guess(text_guess, EQ_ARRAY(char, 0x006410A8), 0);
                }
                UpdateLight_guess(g_charData_guess);
            }
            else {
                pEverQuest->dsp_chat(pStringTable->getString(0x552, 0), 0xd, 1);
            }
        }
        else {
            int group_guess = (request_guess->id_guess - 0x1F) / 10;
            int sub_guess = (request_guess->id_guess - 0x1F) % 10;
            if (g_charData_guess->GetEntry_guess(group_guess) != 0
                    && g_charData_guess->GetEntry_guess(group_guess)->GetItemClass_guess() == 1) {
                Entry_guess* group_entry_guess = g_charData_guess->GetEntry_guess(group_guess);
                if (group_entry_guess->GetChild_guess(sub_guess) != 0) {
                    if (g_queueState_guess == 0) {
                        buildTokenString_guess(buffer_guess, token_guess, count_guess,
                            reinterpret_cast<const char*>(dispatch16_guess()),
                            pStringTable->getString(0x555, 0),
                            reinterpret_cast<const char*>(
                                group_entry_guess->GetChild_guess(sub_guess)->probe_guess()),
                            0, 0, 0, 0, 0);
                    }
                    else {
                        char* name_guess = g_queueState_guess->name_guess;
                        buildTokenString_guess(buffer_guess, token_guess, count_guess,
                            reinterpret_cast<const char*>(dispatch16_guess()),
                            g_stringDisplay_guess->sanitizeName_guess(name_guess),
                            reinterpret_cast<const char*>(
                                group_entry_guess->GetChild_guess(sub_guess)->probe_guess()),
                            0, 0, 0, 0, 0);
                    }
                    dispatch10_guess(request_guess->count_guess);
                    g_modeManager_guess->WavePlay_guess(0x8a, 0);
                    pEverQuest->dsp_chat(buffer_guess, 0x114, 1);
                    if (group_entry_guess->GetChild_guess(sub_guess)->IsStackable_guess()) {
                        Entry_guess* out_guess = 0;
                        int index_guess;
                        MoveItemQty_guess(group_entry_guess->GetValue_guess(sub_guess),
                            &out_guess, extra_guess, 0, &index_guess);
                        if (out_guess != 0) {
                            reinterpret_cast<Deletable_guess*>(out_guess)->slot0_guess(1);
                        }
                    }
                    else {
                        group_entry_guess->release_guess(sub_guess);
                    }
                }
                else {
                    pEverQuest->dsp_chat(pStringTable->getString(0x552, 0), 0xd, 1);
                }
            }
            else {
                pEverQuest->dsp_chat(pStringTable->getString(0x553, 0), 0xd, 1);
            }
        }
    }
    else {
        if (g_queueState_guess == 0) {
            buildTokenString_guess(buffer_guess, 0x554, pStringTable->getString(0x555, 0),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
        else {
            buildTokenString_guess(buffer_guess, 0x554,
                g_stringDisplay_guess->sanitizeName_guess(g_queueState_guess->name_guess),
                0, 0, 0, 0, 0, 0, 0, 0);
        }
        pEverQuest->dsp_chat(buffer_guess, 0x113, 1);
    }
    if (g_messageCount_guess > 0) {
        --g_messageCount_guess;
    }
    else {
        g_messageCount_guess = 0;
    }
    ++g_ringIndex_guess;
    if (g_ringIndex_guess > 9) {
        g_ringIndex_guess = 0;
    }
    g_ringCodes_guess[g_ringIndex_guess] = 0xc;
    g_ringTimes_guess[g_ringIndex_guess] = FUN_00576e80_guess();
    UpdateLight_guess(g_charData_guess);
    pinstCInvSlotMgr_guess->Refresh_guess(0);
    if (pinstCTradeskillWnd_guess != 0) {
        pinstCTradeskillWnd_guess->Flush_guess();
    }
}

// Purchase: refused while CHARINFO2 +0x88 is set (string 0x2164). Depending on the row (+0x4C, +0x50,
// probably whether it stacks) it buys one or asks how many in the quantity window, at most 20.
// FUNCTION: TITANIUM 0x00547728
void QueueOwner_guess::update_guess(int first_guess, int second_guess,
    int third_guess) {
    if (g_queueState_guess != 0) {
        CharInfoOuter_guess* info_guess = reinterpret_cast<CharInfoOuter_guess*>(
            g_charData_guess->Lookup_guess());
        CharInfoState_guess* state_guess = &info_guess->sub_guess;
        if (state_guess->state_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2164, 0), 0x114, 1);
        }
        else if (third_guess == 0 || second_guess != 0) {
            ConfirmPurchase_guess(1);
        }
        else {
            int buffer_guess[4];
            int dest_guess[4];
            Pair_guess pair_guess;
            pair_guess.values_guess[3] = 0;
            pair_guess.values_guess[2] = 0;
            pair_guess.values_guess[1] = 0;
            pair_guess.values_guess[0] = 0;
            int first_guess_v;
            int second_guess_v;
            if (source_guess == 0) {
                first_guess_v = 0;
                second_guess_v = 0;
            }
            else {
                void* value_guess = source_guess->slot57_guess(buffer_guess);
                pair_guess.Copy_guess(dest_guess, value_guess);
                first_guess_v = pair_guess.values_guess[0];
                second_guess_v = pair_guess.values_guess[1];
            }
            if (pinstCQuantityWnd_guess != 0) {
                field204_guess = 0;
                pinstCQuantityWnd_guess->Function_0054d976_guess(this, 0x14, 0x14,
                    first_guess_v, second_guess_v, 1);
            }
        }
    }
}

// Equip toggles only-usable. Selecting an item enables Purchase when you can afford it, else chat says why.
// Done closes.
// FUNCTION: TITANIUM 0x005477FD
// @early-stop: budget, structural ndiff=168
int UseableWindow_guess::handleNotification_guess(void* target_arg_guess,
    int message_arg_guess, void* data_arg_guess) {
    if (message_arg_guess == 1) {
        if (target_arg_guess == option_guess) {
            applyUseable_guess();
            notifyOption_guess(value_guess, changed_guess,
                option_guess->enabled_guess);
        }
        else if (target_arg_guess == source_guess) {
            QueueCollection_guess* collection_guess_v = collection_guess;
            if (collection_guess_v != 0) {
                RangeBuffer_guess range_guess(0x20);
                collection_guess_v->find_guess(&range_guess);
                if (range_guess.count_guess > 0) {
                    int selected_guess = *range_guess.values_guess[
                        0 >> range_guess.shift_guess];
                    index_guess = selected_guess;
                    int value_guess_v = collection_guess->GetItemData(
                        selected_guess);
                    QueueSlot_guess* slot_guess = slots_guess[index_guess];
                    reinterpret_cast<QueueOwner_guess*>(this)->update_guess(
                        value_guess_v, slot_guess->value50_guess,
                        slot_guess->value4c_guess);
                }
            }
        }
        else if (target_arg_guess == target_guess) {
            reinterpret_cast<StatusOwner_guess*>(this)->applySlot_guess(-1);
        }
        else {
            QueueCollection_guess* collection_guess_v = collection_guess;
            if (target_arg_guess == collection_guess_v) {
                if (collection_guess_v != 0) {
                    RangeBuffer_guess range_guess(0x20);
                    collection_guess_v->find_guess(&range_guess);
                    if (range_guess.count_guess > 0) {
                        int selected_guess = *range_guess.values_guess[
                            0 >> range_guess.shift_guess];
                        QueueSlot_guess* slot_guess = slots_guess[index_guess];
                        unsigned int amount_guess =
                            reinterpret_cast<Wrapper_guess*>(this)->dispatch11_guess();
                        unsigned char enough_guess = amount_guess >=
                            (unsigned int)slot_guess->count44_guess;
                        unsigned char hasLimit_guess = 1;
                        if (slot_guess->value48_guess != 0) {
                            unsigned int remaining_guess =
                                reinterpret_cast<Wrapper_guess*>(this)->dispatch3_guess(
                                    slot_guess->value48_guess);
                            hasLimit_guess = 0;
                            if ((unsigned int)slot_guess->count44_guess <= remaining_guess) {
                                hasLimit_guess = 1;
                            }
                        }
                        unsigned char allowed_guess = enough_guess && hasLimit_guess;
                        if (source_guess != 0) {
                            source_guess->enabled_guess = allowed_guess;
                        }
                        if (!allowed_guess) {
                            char amountText_guess[12];
                            char renderedText_guess[0x158];
                            sprintf(amountText_guess, "%d", slot_guess->count44_guess);
                            if (enough_guess == 0) {
                                if (hasLimit_guess == 0) {
                                    int detail_guess =
                                        reinterpret_cast<Wrapper_guess*>(this)->
                                            dispatch5_guess(slot_guess->value48_guess, 1);
                                    int token_guess =
                                        reinterpret_cast<Wrapper_guess*>(this)->
                                            slot7_guess(slot_guess->count44_guess, 0, 0);
                                    buildTokenString_guess(renderedText_guess,
                                        token_guess, amountText_guess, amountText_guess,
                                        reinterpret_cast<const char*>(detail_guess),
                                        0, 0, 0, 0, 0, 0);
                                }
                                else {
                                    int token_guess =
                                        reinterpret_cast<Wrapper_guess*>(this)->
                                            slot7_guess(slot_guess->count44_guess, 0, 1);
                                    buildTokenString_guess(renderedText_guess,
                                        token_guess, amountText_guess, 0, 0,
                                        0, 0, 0, 0, 0, 0);
                                }
                            }
                            else {
                                int detail_guess =
                                    reinterpret_cast<Wrapper_guess*>(this)->
                                        dispatch5_guess(slot_guess->value48_guess, 1);
                                int token_guess =
                                    reinterpret_cast<Wrapper_guess*>(this)->
                                        slot7_guess(slot_guess->count44_guess, 1,
                                            hasLimit_guess);
                                buildTokenString_guess(renderedText_guess,
                                    token_guess, amountText_guess,
                                    reinterpret_cast<const char*>(detail_guess), 0,
                                    0, 0, 0, 0, 0, 0);
                            }
                            g_stringDisplay_guess->dsp_chat(renderedText_guess,
                                0x114, 1);
                        }
                    }
                }
            }
            else if (target_arg_guess == field1c4_guess) {
                slot34_guess();
            }
        }
    }
    // 0xF: a column header click; the same column again flips the order.
    else if (message_arg_guess == 0xF) {
        if (target_arg_guess == collection_guess) {
            int choice_guess = reinterpret_cast<int>(data_arg_guess);
            unsigned char result_guess = 0;
            if (choice_guess == 0) {
                result_guess = flag168_guess == 0;
                flag168_guess = result_guess;
            }
            else if (choice_guess == 1) {
                result_guess = flag169_guess == 0;
                flag169_guess = result_guess;
            }
            else if (choice_guess == 2) {
                result_guess = flag16a_guess == 0;
                flag16a_guess = result_guess;
            }
            if (option_guess != 0) {
                notifyOption_guess(choice_guess, result_guess,
                    option_guess->enabled_guess);
            }
        }
        return 0;
    }
    // 3: right click on an item asks for its details (OP_ItemLinkResponse 0x667C; flag 2 with shift).
    else if (message_arg_guess == 3) {
        if (target_arg_guess == collection_guess) {
            if (collection_guess != 0) {
                int state_guess_v = collection_guess->getState_guess();
                if (state_guess_v >= 0 && state_guess_v < 3) {
                    int message_guess[18];
                    memset(message_guess, 0, 0x48);
                    if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0) {
                        message_guess[1] |= 2;
                    }
                    int selected_guess = collection_guess->GetCurSel();
                    message_guess[0] = collection_guess->GetItemData(
                        selected_guess);
                    StringObject_guess* text_guess =
                        collection_guess->GetItemText(&data_arg_guess,
                            selected_guess, 0);
                    strcpy(reinterpret_cast<char*>(&message_guess[2]),
                        text_guess->c_str_guess());
                    if (data_arg_guess != 0) {
                        reinterpret_cast<CXStrView_guess*>(&data_arg_guess)->
                            FreeRep(data_arg_guess);
                    }
                    data_arg_guess = 0;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_ItemLinkResponse,
                        message_guess, 0x48, 1);
                }
            }
            return 0;
        }
    }
    // 0x1F: the quantity window's answer, for a purchase (+0x204 = 0) or a sale (+0x204 = 1).
    else if (message_arg_guess == 0x1F) {
        if (state_guess == 0) {
            reinterpret_cast<QueueOwner_guess*>(this)->ConfirmPurchase_guess(
                *reinterpret_cast<int*>(data_arg_guess));
            return 0;
        }
        if (state_guess == 1 && valueSlot_guess != 0
            && *valueSlot_guess != 0) {
            reinterpret_cast<StatusOwner_guess*>(this)->applySlot_guess(
                *reinterpret_cast<int*>(data_arg_guess));
            return 0;
        }
    }
    else if (message_arg_guess == 10) {
        slot34_guess();
    }
    return route_guess(target_arg_guess, message_arg_guess, data_arg_guess);
}


