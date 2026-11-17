// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 170: a hint from compare/tumap.py.
// The inventory window (InventoryWindow, CInventoryWnd; CInventoryWndView_guess here): equipment slots,
// coins,
// Radiant/Ebon crystals (the SIDL calls them IW_GoodPoints/IW_EvilPoints), experience gauges, the evolving
// items page and the monster-mission progression page; plus the /outputfile inventory dump.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include <string>

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0047477F AutoEquipItem_guess
void __cdecl AutoEquipItem_guess(void* character, void* value, int delay);

struct Destination_guess {
    char pad_0000[0x5D];
    bool flag;
};

struct Owner_guess {
    char pad_0000[0x238];
    CListWnd* child;
    Destination_guess* destination;

    void Update_guess();
};

struct ProgressNode_guess;

struct TertiaryBase_guess;
struct Dispatcher_guess {
    char pad_0000[4];
    int* field_004;                         // 0x04 (its first dword is passed to the list helper)
    char pad_0008[0x18];
    ProgressNode_guess* sentinel_020;       // 0x20 progression list head
    // EXTERNAL: TITANIUM 0x00518B72 Dispatcher_guess::Submit_guess
    void Submit_guess(unsigned int* value);
    struct Iter_guess { int* node; Iter_guess(int* n) : node(n) {} };
    Iter_guess Begin_guess() { return Iter_guess((int*)*field_004); }
    // EXTERNAL: TITANIUM 0x00518D4A Dispatcher_guess::Insert_guess
    void Insert_guess(Iter_guess where, TertiaryBase_guess* const& value);
    void PushFront_guess(TertiaryBase_guess* const& value) { Insert_guess(Begin_guess(), value); }
};

#define g_dispatcher_guess EQ_GLOBAL(Dispatcher_guess*, 0x0079C120)

struct EverQuestExt_guess {
    // EXTERNAL: TITANIUM 0x00495F81 EverQuestExt_guess::MoveMoney_guess
    void MoveMoney_guess(int mode, int show, int slot, int index, int value, int flag);
};

struct Client_state_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 Client_state_guess::CheckReady_guess
    char CheckReady_guess();
    // EXTERNAL: TITANIUM 0x0054D976 Client_state_guess::ShowInventory_guess
    void ShowInventory_guess(void* owner, int amount, int amount2, int x, int y, int flag);
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
    virtual void OnDone_guess();
};


struct CallbackOwner_guess {
    char pad_0000[0x5C];
    bool busy;
    char pad_005D[0x107];
    int state164;
    int state168;

    // EXTERNAL: TITANIUM 0x005A1880 CallbackOwner_guess::OnShow
    void OnShow();
    void Handle_guess();
};

struct Result_guess {
    char pad_0000[0x11A4];
    int level_11a4;
    char pad_11a8[0x2c];
    int value0;
    int value1;
    int value2;
    int value3;
    int field_11e4;
    int field_11e8;
    int field_11ec;
    int field_11f0;
};

struct CharInfoState_guess {
    char pad_0000[0x78];
    int value_guess;                        // 0x78
};

struct CharInfoOuter_guess {
    char pad_0000[0x10];
    CharInfoState_guess state_guess;        // 0x10
};

struct Prefix_guess {
    int pad_0000;
};

struct Wrapper_guess : Prefix_guess, EQ_CharacterProfile_guess {
    Result_guess* Get_guess() {
        return reinterpret_cast<Result_guess*>(GetCharInfo2());
    }
};

#include "titanium/layouts/core.h"

#include "titanium/layouts/geometry.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CAAWnd.h"
#include "titanium/wnd/CBodyTintWnd.h"
#include "titanium/wnd/CCursorAttachment.h"
#include "titanium/wnd/CFacePick.h"
#include "titanium/wnd/CQuantityWnd.h"
#include "titanium/wnd/CSkillsWnd.h"

struct Rect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004EA5BF Rect_guess::Contains_guess
    char Contains_guess(const CXPoint* point_guess);
    // EXTERNAL: TITANIUM 0x004D9160 Rect_guess::CopyTo_guess
    void CopyTo_guess(Rect_guess* dst, void* src);
    // EXTERNAL: TITANIUM 0x004DC02D Rect_guess::CenterPoint
    CXPoint* CenterPoint(CXPoint* point);
};

struct Root_guess {
    char pad_0000[8];
    VBTable* offset;
    char pad_000C[0xfac - 0xc];
    int field_fac;
    char pad_0fb0[4];
    int ebonCrystals_0fb4_guess;
    // EXTERNAL: TITANIUM 0x004BE5FE Root_guess::DestroyHeldItemOrMoney
    void DestroyHeldItemOrMoney();
};

struct RootData_guess {
    char pad_0000[8];
    union {
        VBTable* vbtable_0008_guess;
        unsigned char data_008[0x10000];
    };
};

struct CharacterData_guess {
    void* vftable;
    EQ_CharacterProfile_guess profile;
};

struct StatusHost_guess {
    // EXTERNAL: TITANIUM 0x004167E2 StatusHost_guess::GetStatus_guess
    int GetStatus_guess();
};

// Window whose text is set through vtable slot 0xFC (63).
struct TextWnd_guess {
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
    virtual void SetEnabled_guess(char enabled, bool update);
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual void* Slot57_guess(int* buffer);
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void SetText_guess(const CXStr& text);
};

#define g_root_guess EQ_GLOBAL(Root_guess*, 0x00905D00)

struct ResourceUser_guess {
    // EXTERNAL: TITANIUM 0x0044A537 ResourceUser_guess::WavePlay_guess
    void WavePlay_guess(int value, void* pack);
};

#define g_resourceUser_guess EQ_GLOBAL(ResourceUser_guess*, 0x00851390)

struct ReportEntry_guess {
    char pad_0000[0x48];
    int slotCount;

    // EXTERNAL: TITANIUM 0x005EC760 ReportEntry_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ReportEntry_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 ReportEntry_guess::GetSelectedSlots_guess
    int GetSelectedSlots_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 ReportEntry_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ReportEntry_guess::GetSlotText_guess
    const char* GetSlotText_guess();
    // EXTERNAL: TITANIUM 0x005E0D00 ReportEntry_guess::HasSlot_guess
    char HasSlot_guess(int slot);
    // EXTERNAL: TITANIUM 0x005E0CC0 ReportEntry_guess::IsSlotValid_guess
    char IsSlotValid_guess(int slot);
    // EXTERNAL: TITANIUM 0x005EC630 ReportEntry_guess::GetSlotEntry_guess
    ReportEntry_guess* GetSlotEntry_guess(int slot);
};

struct ReportOwner_guess {
    void WriteEntry_guess(FILE* file, ReportEntry_guess* entry, const char* name);
    void WriteInventoryFile_guess(const char* path);
};

template <unsigned int N>
struct ReportPointerArray_guess {
    ReportEntry_guess* data[N];

    ReportEntry_guess* operator[](int index) {
        if ((unsigned int)index < N) {
            return data[index];
        }
        __debugbreak();
        return data[index];
    }
};

// CTextureAnimation (0x4C bytes, ctor 0x005B1D90); slot 0 is its deleting destructor.
struct CallbackTarget_guess {
    virtual void Invoke_guess(int value);
    char pad_0004[0x29];
    bool flag_2D;                           // 0x2D
    char pad_002E[0x1E];
    // EXTERNAL: TITANIUM 0x004DBB3B CallbackTarget_guess::Attach_guess
    void Attach_guess(int anim);
    // EXTERNAL: TITANIUM 0x005B1730 CallbackTarget_guess::FUN_005b1730_guess
    void FUN_005b1730_guess(int value);
    // EXTERNAL: TITANIUM 0x005B1D90 ??0CallbackTarget_guess@@QAE@XZ
    CallbackTarget_guess();
};

struct CallbackLink_guess {
    char pad_0000[0x64];
    CallbackTarget_guess* target;
};

struct InvSidlTemplate_guess {
    char pad_0000[0x60];
    unsigned int style_060;                 // 0x060
    unsigned int GetStyle_guess() { return style_060; }
};

// CInventoryWnd's CSidlScreenWnd base (include/titanium/core_decls.h layout).
struct PrimaryBase_guess {
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
    char pad_0004[0x60];
    unsigned int windowStyle_064;           // 0x064 (CXWnd::WindowStyle)
    char pad_0068[0xbc];
    InvSidlTemplate_guess* sidlPiece_124;   // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_0128[0x30];
    int field_158;                          // 0x158
    // EXTERNAL: TITANIUM 0x005A3850 ??0PrimaryBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    PrimaryBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 PrimaryBase_guess::~PrimaryBase_guess
    ~PrimaryBase_guess();
};

struct SecondaryBase_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005482A0 SecondaryBase_guess::Reset_guess
    void Reset_guess(int value);
    ~SecondaryBase_guess() { Reset_guess(-1); }
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7TertiaryBase_guess@@6B@
struct TertiaryBase_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(Dispatcher_guess* dispatcher, int* event);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7SecondaryBase_guess@@6B@
// EXTERNAL: TITANIUM 0x006563C8 ??_7CInventoryWndView_guess@@6BPrimaryBase_guess@@@
// EXTERNAL: TITANIUM 0x006563C0 ??_7CInventoryWndView_guess@@6BSecondaryBase_guess@@@
// EXTERNAL: TITANIUM 0x006563BC ??_7CInventoryWndView_guess@@6BTertiaryBase_guess@@@
// Window parts the inventory ctor configures (fields at +0x20/+0x24 of a CXWnd, set together inline).
struct InvRange_guess {
    int first;
    int second;
    InvRange_guess(int a, int b) : first(a), second(b) {}
};

struct InvRangeWnd_guess {
    char pad_0000[0x20];
    InvRange_guess range_020;               // 0x020
    char pad_0028[0x3c];
    unsigned int windowStyle_064;           // 0x064
};

struct InvListWnd_guess : InvRangeWnd_guess {
    char pad_0068[0xa4];
    int field_10c;                          // 0x10C
    char pad_0110[0x44];
    int field_154;                          // 0x154
    char pad_0158;
    unsigned char field_159;                // 0x159
    char pad_015a[2];
    unsigned char field_15c;                // 0x15c
    char pad_015d[3];
    int field_160;                          // 0x160
    char pad_0164[8];
    unsigned int color_16c;                 // 0x16c
    // EXTERNAL: TITANIUM 0x00597C60 InvListWnd_guess::SetColors
    void SetColors(unsigned long a, unsigned long b, unsigned long c);
    // EXTERNAL: TITANIUM 0x005982E0 InvListWnd_guess::SetColumnJustification
    void SetColumnJustification(int column, int justification);
    // EXTERNAL: TITANIUM 0x005981F0 InvListWnd_guess::FUN_005981f0_guess
    void FUN_005981f0_guess(int column, int value);
    void SetRowHeight_guess(int height) {
        field_159 = 1;
        field_160 = height;
    }
};

struct InvViewWnd_guess {
    char pad_0000[0x64];
    unsigned int windowStyle_064;           // 0x064
    // EXTERNAL: TITANIUM 0x005A2490 InvViewWnd_guess::GetChildLabel_guess
    CallbackLink_guess* GetChildLabel_guess(const CXStr& name);
};

struct InvDisplay_guess {
    char pad_0000[0x11];
    unsigned char cursorMoneyType_0011_guess;                 // 0x11
    char pad_0012[0x148 - 0x12];
    int frameTime_0148_guess;
};

#define g_invDisplay_guess EQ_GLOBAL(InvDisplay_guess*, 0x00905D24)


struct ItemSlot_guess {
    char pad_0000[0x78];
    bool flag_078;
};

struct CharSub_guess {
    // EXTERNAL: TITANIUM 0x0041DE16 CharSub_guess::GetItemBySlot_guess
    ItemSlot_guess* GetItemBySlot_guess(unsigned int id);
};

struct CharBig_guess {
    char pad_0000[0xc280];
    CharSub_guess sub_c280;
};

struct ReportRoot_guess {
    char pad_0000[8];
    VBTable* offset;
    char pad_000C[0xce4];
    ReportPointerArray_guess<16> entries_cf0;
    ReportPointerArray_guess<2> entries_d30;
    char pad_0D38[0xb548];
    CharSub_guess inventory_c280;
};

struct CharLevel_guess {
    // EXTERNAL: TITANIUM 0x004167E2 CharLevel_guess::Get_guess
    int Get_guess();
};

// EXTERNAL: TITANIUM 0x0042419C RequestEvolvingItemToggle_guess
void __cdecl RequestEvolvingItemToggle_guess(ItemSlot_guess* slot, bool flag);

// CInventoryWnd (include/titanium/types.h, 0x268).
struct CInventoryWndView_guess : PrimaryBase_guess, SecondaryBase_guess, TertiaryBase_guess {
    int selectedMoneyButton_0164_guess;                          // 0x164
    int selectedCrystal_0168_guess;                          // 0x168
    CXWnd* money_16c[4];                    // 0x16c IW_Money0..3
    CXWnd* invSlots_17c[30];                // 0x17c InvSlot0..29
    CXWnd* nextLevelLabel_1f4;              // 0x1f4 NextLevelLabel
    CXWnd* expGauge_1f8;                    // 0x1f8 ExpGauge
    CXWnd* altAdvLabel_1fc;                 // 0x1fc AltAdvLabel
    CXWnd* altAdvGauge_200;                 // 0x200 AltAdvGauge
    CXWnd* destroyButton_204;               // 0x204 IW_Destroy
    CXWnd* skillsButton_208;                // 0x208 IW_Skills
    CXWnd* altAdvButton_20c;                // 0x20c IW_AltAdvBtn
    CXWnd* doneButton_210;                  // 0x210 DoneButton
    CXWnd* facePickButton_214;              // 0x214 IW_FacePick
    CXWnd* tintingButton_218;               // 0x218 IW_Tinting
    CXWnd* goodPoints_21c;                  // 0x21c IW_GoodPoints
    CXWnd* evilPoints_220;                  // 0x220 IW_EvilPoints
    CXWnd* reclaimButton_224;               // 0x224 IW_ReclaimButton
    CallbackLink_guess* callbackLink;       // 0x228 ClassAnim (in IW_CharacterView)
    InvViewWnd_guess* characterView_22c;    // 0x22c IW_CharacterView
    int field_230;                          // 0x230
    int field_234;                          // 0x234
    InvListWnd_guess* itemList_238;         // 0x238 EI_ItemList
    CXWnd* toggleButton_23c;                // 0x23c EI_ToggleButton
    CXWnd* allOnButton_240;                 // 0x240 EI_AllOnButton
    CXWnd* allOffButton_244;                // 0x244 EI_AllOffButton
    InvListWnd_guess* progressionList_248;  // 0x248 ProgressionList
    InvRangeWnd_guess* progressionInfo_24c; // 0x24c ProgressionInfo
    CXWnd* invPage_250;                     // 0x250 InvPage
    CXWnd* eiPage_254;                      // 0x254 EIPage
    CXWnd* altCharProgPage_258;             // 0x258 AltCharProgPage
    CXWnd* subwindows_25c;                  // 0x25c IW_Subwindows
    int field_260;                          // 0x260
    unsigned char field_264;
    char pad_265[3];
    CInventoryWndView_guess(CXWnd* parent);
    void OnProcessFrame_guess();
    ~CInventoryWndView_guess();
    CInventoryWndView_guess* ScalarDeletingDestructor_guess(unsigned char freeFlag);
    void UpdateAlignment_guess();
    void UpdateMoney_guess();
    void Refresh_guess();
    void ClickedMoneyButton_guess(int value, int flag);
    void UpdateProgressionInfo_guess();
    void UpdateProgress_guess();
    int HandleLButtonUp_guess(const CXPoint* point_guess, unsigned int flags);
    char AboutToShow_guess();
    // EXTERNAL: TITANIUM 0x005169AF CInventoryWndView_guess::FillEvolvingItemList_guess
    void FillEvolvingItemList_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CInventoryWndView_guess::CheckReady_guess
    char CheckReady_guess();
    // EXTERNAL: TITANIUM 0x00517DC3 CInventoryWndView_guess::ConfirmDestroyHeld_guess
    void ConfirmDestroyHeld_guess();
    void ClickedCrystalButton_guess(int value, int flag);
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

// Progression data changed (event 2 from the progression manager 0x79C120): rebuild the list.
// FUNCTION: TITANIUM 0x00518BD0
// @early-stop: budget, structural ndiff=6
void TertiaryBase_guess::Slot01_guess(Dispatcher_guess* dispatcher, int* event)
{
    if (dispatcher == g_dispatcher_guess && *event == 2) {
        CInventoryWndView_guess& client = static_cast<CInventoryWndView_guess&>(*this);
        client.UpdateProgress_guess();
    }
}

struct SubwindowsHost_guess {
    // EXTERNAL: TITANIUM 0x005BC460 SubwindowsHost_guess::SetPage_guess
    void SetPage_guess(CXWnd* page, int flag);
};

#define g_flag_9247a0_guess EQ_GLOBAL(int, 0x009247A0)

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text, const char* format, ...);

// Releases the class animation shown in the character view.
// FUNCTION: TITANIUM 0x005168DF
CInventoryWndView_guess::~CInventoryWndView_guess()
{
    if (callbackLink != 0) {
        CallbackTarget_guess* target = callbackLink->target;
        if (target != 0) {
            target->Invoke_guess(1);
        }
    }
}

// Inventory window OnShow (vtable 0x6563C8 slot 35): on show, context tip 0 in the tip window
// (0x9928E0); on hide with a coin or crystal quantity request pending (+0x164 / +0x168 not -1), closes
// the quantity window (0x850C3C) if it is open. Then the CSidlScreenWnd OnShow (0x005A1880).
// FUNCTION: TITANIUM 0x00516957
void CallbackOwner_guess::Handle_guess()
{
    if (busy != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0, 0);
        }
    } else if (state164 != -1 || state168 != -1) {
        if (pinstCQuantityWnd_guess != 0 && pinstCQuantityWnd_guess->IsVisible_guess() != 0) {
            pinstCQuantityWnd_guess->Deactivate();
        }
    }
    OnShow();
}

// Inventory window, evolving items page: enables EI_ToggleButton (+0x23C, flag +0x5D) only while a row
// of EI_ItemList (+0x238) is selected. Run by the 200 ms refresh (0x00517BFB).
// FUNCTION: TITANIUM 0x00516C2F
void Owner_guess::Update_guess()
{
    bool state = false;
    if (child != 0) {
        state = child->GetCurSel() != -1;
    }
    if (destination != 0) {
        destination->flag = state;
    }
}

// Shows the crystal counts: Radiant (+0xFAC) and Ebon (+0xFB4), the same fields tu_064 reports.
// FUNCTION: TITANIUM 0x00516C58
void CInventoryWndView_guess::UpdateAlignment_guess()
{
    if (g_root_guess != 0) {
        char text[0x100];
        sprintf(text, "%d", g_root_guess->field_fac);
        if (goodPoints_21c != 0) {
            CXStr value(text);
            ((TextWnd_guess*)goodPoints_21c)->SetText_guess(value);
        }
        sprintf(text, "%d", g_root_guess->ebonCrystals_0fb4_guess);
        if (evilPoints_220 != 0) {
            CXStr value(text);
            ((TextWnd_guess*)evilPoints_220)->SetText_guess(value);
        }
    }
}

// Inventory window's dialog-owner callback (secondary vtable 0x6563C0 slot 0): a yes (flags 1 or 4) to
// confirmation 100 destroys the item or money on the cursor (0x004BE5FE).
// FUNCTION: TITANIUM 0x00516D72
void __stdcall ConfirmDestroyHeldItemOrMoney_guess(int value_guess, char flags_guess, int unused_guess)
{
    if (value_guess == 100 && (flags_guess & 5) != 0) {
        g_root_guess->DestroyHeldItemOrMoney();
    }
}

// One line per item: location, name, id, count, slots; containers recurse as "<location>-Slot<n>".
// FUNCTION: TITANIUM 0x00516D8E
void ReportOwner_guess::WriteEntry_guess(FILE* file, ReportEntry_guess* entry, const char* name)
{
    char slotName[512];
    if (entry != 0) {
        int mode = 1;
        if (entry->IsStackable_guess() != 0) {
            mode = entry->slotCount;
        }
        int count;
        if (entry->GetItemClass_guess() == 1) {
            count = entry->GetSelectedSlots_guess();
        } else {
            count = 5;
        }
        fprintf(file, "%s\t%s\t%d\t%d\t%d\n", name,
            entry->GetSlotText_guess(), entry->GetItemId_guess(), mode, count);
        int slot = 0;
        if (count > 0) {
            do {
                if (entry->GetItemClass_guess() == 1 ||
                    (entry->HasSlot_guess(slot) != 0 && entry->IsSlotValid_guess(slot) != 0)) {
                    ReportEntry_guess* child = entry->GetSlotEntry_guess(slot);
                    sprintf(slotName, "%s-Slot%d", name, slot + 1);
                    WriteEntry_guess(file, child, slotName);
                }
                ++slot;
            } while (slot < count);
            }
    } else {
        fprintf(file, "%s\tEmpty\t0\t0\t0\n", name);
    }
}

// Writes "<name>-Inventory.txt" (or `path`): worn and carried slots 0-30, Bank1-16 (string 3496) and
// SharedBank1-2 (3497).
// FUNCTION: TITANIUM 0x0051802A
// @early-stop: budget, diff ndiff=17
void ReportOwner_guess::WriteInventoryFile_guess(const char* path)
{
    char defaultPath[512];
    char slotName[512];
    FILE* file;
    int i;
    unsigned int index;
    unsigned int number;
    ReportEntry_guess* entry;
    const char* name;
    if (path == 0 || *path == '\0') {
        sprintf(defaultPath, "%s-Inventory.txt", EQ_GLOBAL(EQPlayer*, 0x00905CE4)->Name);
        path = defaultPath;
    }
    file = fopen(path, "w");
    if (file != 0) {
        fprintf(file, "Location\tName\tID\tCount\tSlots\n");
        i = 0;
        do {
            entry = (ReportEntry_guess*)((CharBig_guess*)g_root_guess)->sub_c280.GetItemBySlot_guess(i);
            name = pStringTable->getString(EQ_ARRAY(int, 0x006674C8)[i], 0);
            WriteEntry_guess(file, entry, name);
            ++i;
        } while (i <= 0x1e);
        index = 0;
        do {
            entry = ((ReportRoot_guess*)g_root_guess)->entries_cf0[index];
            number = index + 1;
            sprintf(slotName, "%s%d", pStringTable->getString(0xda8, 0), number);
            WriteEntry_guess(file, entry, slotName);
            index = number;
        } while ((int)index < 0x10);
        index = 0;
        do {
            entry = ((ReportRoot_guess*)g_root_guess)->entries_d30[index];
            number = index + 1;
            sprintf(slotName, "%s%d", pStringTable->getString(0xda9, 0), number);
            WriteEntry_guess(file, entry, slotName);
            index = number;
        } while ((int)index < 2);
        fclose(file);
    }
}

// Style 0x10000; InvSlot0-29, IW_Money0-3 and the other children. Both lists get 0xFF8AA3FF highlights; the
// evolving list uses 24-pixel rows.
// FUNCTION: TITANIUM 0x00516E9A
CInventoryWndView_guess::CInventoryWndView_guess(CXWnd* parent)
    : PrimaryBase_guess(parent, "InventoryWindow", -0x101, 2, 0) {
    field_234 = 0;
    for (int index = 0; index < 4; ++index) {
        money_16c[index] = 0;
    }
    windowStyle_064 |= 0x10000;
    goodPoints_21c = 0;
    evilPoints_220 = 0;
    reclaimButton_224 = 0;
    destroyButton_204 = 0;
    skillsButton_208 = 0;
    altAdvButton_20c = 0;
    doneButton_210 = 0;
    facePickButton_214 = 0;
    tintingButton_218 = 0;
    nextLevelLabel_1f4 = 0;
    expGauge_1f8 = 0;
    altAdvLabel_1fc = 0;
    altAdvGauge_200 = 0;
    characterView_22c = 0;
    itemList_238 = 0;
    toggleButton_23c = 0;
    allOnButton_240 = 0;
    allOffButton_244 = 0;
    progressionList_248 = 0;
    progressionInfo_24c = 0;
    invPage_250 = 0;
    eiPage_254 = 0;
    altCharProgPage_258 = 0;
    subwindows_25c = 0;
    field_158 = 0;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->GetStyle_guess();
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        char name[0x80];
        for (int i = 0; i < 30; ++i) {
            sprintf(name, "InvSlot%d", i);
            invSlots_17c[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        for (int j = 0; j < 4; ++j) {
            sprintf(name, "IW_Money%d", j);
            money_16c[j] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        goodPoints_21c = ((CSidlScreenWnd*)this)->GetChildItem("IW_GoodPoints");
        evilPoints_220 = ((CSidlScreenWnd*)this)->GetChildItem("IW_EvilPoints");
        reclaimButton_224 = ((CSidlScreenWnd*)this)->GetChildItem("IW_ReclaimButton");
        destroyButton_204 = ((CSidlScreenWnd*)this)->GetChildItem("IW_Destroy");
        skillsButton_208 = ((CSidlScreenWnd*)this)->GetChildItem("IW_Skills");
        altAdvButton_20c = ((CSidlScreenWnd*)this)->GetChildItem("IW_AltAdvBtn");
        doneButton_210 = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        facePickButton_214 = ((CSidlScreenWnd*)this)->GetChildItem("IW_FacePick");
        tintingButton_218 = ((CSidlScreenWnd*)this)->GetChildItem("IW_Tinting");
        nextLevelLabel_1f4 = ((CSidlScreenWnd*)this)->GetChildItem("NextLevelLabel");
        expGauge_1f8 = ((CSidlScreenWnd*)this)->GetChildItem("ExpGauge");
        altAdvLabel_1fc = ((CSidlScreenWnd*)this)->GetChildItem("AltAdvLabel");
        altAdvGauge_200 = ((CSidlScreenWnd*)this)->GetChildItem("AltAdvGauge");
        characterView_22c = (InvViewWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("IW_CharacterView");
        if (characterView_22c != 0) {
            callbackLink = characterView_22c->GetChildLabel_guess("ClassAnim");
            if (callbackLink != 0) {
                callbackLink->target = new CallbackTarget_guess;
            }
            characterView_22c->windowStyle_064 &= ~0x800;
        }
        itemList_238 = (InvListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("EI_ItemList");
        toggleButton_23c = ((CSidlScreenWnd*)this)->GetChildItem("EI_ToggleButton");
        allOnButton_240 = ((CSidlScreenWnd*)this)->GetChildItem("EI_AllOnButton");
        allOffButton_244 = ((CSidlScreenWnd*)this)->GetChildItem("EI_AllOffButton");
        progressionList_248 = (InvListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ProgressionList");
        progressionInfo_24c = (InvRangeWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ProgressionInfo");
        invPage_250 = ((CSidlScreenWnd*)this)->GetChildItem("InvPage");
        eiPage_254 = ((CSidlScreenWnd*)this)->GetChildItem("EIPage");
        altCharProgPage_258 = ((CSidlScreenWnd*)this)->GetChildItem("AltCharProgPage");
        subwindows_25c = ((CSidlScreenWnd*)this)->GetChildItem("IW_Subwindows");
        field_260 = 0;
        if (itemList_238 != 0) {
            itemList_238->SetColors(-1, 0xffffff00, 0xff808080);
            itemList_238->SetColumnJustification(0, 0);
            itemList_238->SetColumnJustification(1, 0);
            itemList_238->SetColumnJustification(2, 1);
            itemList_238->SetColumnJustification(3, 1);
            itemList_238->SetColumnJustification(4, 0);
            itemList_238->color_16c = 0xff8aa3ff;
            itemList_238->field_15c = 1;
            itemList_238->SetRowHeight_guess(24);
            itemList_238->FUN_005981f0_guess(0, 24);
            itemList_238->windowStyle_064 |= 0x40000;
            itemList_238->field_154 = 1;
        }
        if (progressionList_248 != 0) {
            progressionList_248->SetColors(-1, 0xffffff00, 0xff808080);
            progressionList_248->SetColumnJustification(0, 0);
            progressionList_248->SetColumnJustification(1, 1);
            progressionList_248->SetColumnJustification(2, 1);
            progressionList_248->SetColumnJustification(3, 2);
            progressionList_248->color_16c = 0xff8aa3ff;
            progressionList_248->field_15c = 1;
            progressionList_248->range_020 = InvRange_guess(0, 30);
        }
        if (progressionInfo_24c != 0) {
            progressionInfo_24c->range_020 = InvRange_guess(0, 30);
        }
        field_230 = g_invDisplay_guess->frameTime_0148_guess;
    }
}

// Scalar deleting destructor of the inventory window (vtable 0x6563C8 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x005177F4
CInventoryWndView_guess* CInventoryWndView_guess::ScalarDeletingDestructor_guess(unsigned char freeFlag)
{
    this->~CInventoryWndView_guess();
    if ((freeFlag & 1) != 0) {
        free(this);
    }
    return this;
}

struct SlotPool_guess {
    // EXTERNAL: TITANIUM 0x005481CF SlotPool_guess::Attach_guess
    int Attach_guess(SecondaryBase_guess* owner, int value);
    // EXTERNAL: TITANIUM 0x00548225 SlotPool_guess::ExpireAt_guess
    void ExpireAt_guess(int handle);
};

#define g_slotPool_guess EQ_GLOBAL(SlotPool_guess*, 0x00991E44)

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* dest, int value, size_t count);

// Crystal box clicked: with a count (`value` >= 0) sends OP_CrystalCreate (8 bytes: type 4 Radiant or 5 Ebon,
// count) to turn crystals into items; without one, opens the quantity window over that box.
// FUNCTION: TITANIUM 0x00517810
// @early-stop: budget, structural ndiff=8
void CInventoryWndView_guess::ClickedCrystalButton_guess(int kind, int value)
{
    int value_guess = 0;
    int handle = g_slotPool_guess->Attach_guess(this, -1);
    g_slotPool_guess->ExpireAt_guess(handle);
    selectedMoneyButton_0164_guess = -1;
    if (value > -1) {
        int message[2];
        memset(message, value_guess, sizeof(message));
        message[0] = kind;
        message[1] = value;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_CrystalCreate, message, sizeof(message), 1);
        UpdateAlignment_guess();
        return;
    }

    Rect_guess area;
    Rect_guess temp;
    Rect_guess rect;
    CXPoint pair;
    CXPoint center;
    rect.left_guess = rect.top_guess = rect.right_guess = rect.bottom_guess = 0;
    switch (kind) {
    case 4:
        value_guess = g_root_guess->field_fac;
        if (goodPoints_21c != 0) {
            Rect_guess* source = (Rect_guess*)((TextWnd_guess*)goodPoints_21c)->Slot57_guess((int*)&area);
            rect.CopyTo_guess(&temp, source);
        }
        break;
    case 5:
        value_guess = g_root_guess->ebonCrystals_0fb4_guess;
        if (evilPoints_220 != 0) {
            Rect_guess* source = (Rect_guess*)((TextWnd_guess*)evilPoints_220)->Slot57_guess((int*)&pair);
            rect.CopyTo_guess(&temp, source);
        }
        break;
    }
    selectedCrystal_0168_guess = kind;
    CXPoint* point = rect.CenterPoint(&center);
    pinstCQuantityWnd_guess->Function_0054d976_guess(this, value_guess, value_guess,
        point->x, point->y, 1);
}

// Coin count `index`: 0 platinum .. 3 copper.
// FUNCTION: TITANIUM 0x00517924
int __stdcall GetValue_guess(int index)
{
    switch (index) {
    case 0:
    {
        Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        return wrapper->Get_guess()->value0;
    }
    case 1:
    {
        Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        return wrapper->Get_guess()->value1;
    }
    case 2:
    {
        Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        return wrapper->Get_guess()->value2;
    }
    case 3:
    {
        Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        return wrapper->Get_guess()->value3;
    }
    default:
        return 0;
    }
}

// Writes the four coin counts of the character (CharInfo2 +0x11D4 to +0x11E0) into IW_Money0-3.
// FUNCTION: TITANIUM 0x005179B7
void CInventoryWndView_guess::UpdateMoney_guess()
{
    if (g_root_guess != 0) {
        char text[0x100];
        Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        sprintf(text, "%d", wrapper->Get_guess()->value0);
        if (money_16c[0] != 0) {
            CXStr value(text);
            ((TextWnd_guess*)money_16c[0])->SetText_guess(value);
        }
        wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        sprintf(text, "%d", wrapper->Get_guess()->value1);
        if (money_16c[1] != 0) {
            CXStr value(text);
            ((TextWnd_guess*)money_16c[1])->SetText_guess(value);
        }
        wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        sprintf(text, "%d", wrapper->Get_guess()->value2);
        if (money_16c[2] != 0) {
            CXStr value(text);
            ((TextWnd_guess*)money_16c[2])->SetText_guess(value);
        }
        wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        sprintf(text, "%d", wrapper->Get_guess()->value3);
        if (money_16c[3] != 0) {
            CXStr value(text);
            ((TextWnd_guess*)money_16c[3])->SetText_guess(value);
        }
    }
}

// Coin box clicked. With coins on the cursor (cursor mode 1-4) puts them back into the box; otherwise asks
// how many to pick up (quantity window), then moves `value` coins to the cursor.
// FUNCTION: TITANIUM 0x00517EBB
// @early-stop: budget, structural ndiff=85
void CInventoryWndView_guess::ClickedMoneyButton_guess(int index, int value)
{
    selectedCrystal_0168_guess = -1;
    int mode;
    int show;
    int slot;
    if (g_invDisplay_guess->cursorMoneyType_0011_guess != 0) {
        unsigned char display = g_invDisplay_guess->cursorMoneyType_0011_guess;
        mode = 0;
        show = 1;
        slot = display - 1;
        switch (display) {
        case 1:
        {
            Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
            value = wrapper->Get_guess()->field_11e4;
            break;
        }
        case 2:
        {
            Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
            value = wrapper->Get_guess()->field_11e8;
            break;
        }
        case 3:
        {
            Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
            value = wrapper->Get_guess()->field_11ec;
            break;
        }
        case 4:
        {
            Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
            value = wrapper->Get_guess()->field_11f0;
            break;
        }
        default:
            value = 0;
            break;
        }
    } else {
        mode = 1;
        show = 0;
        slot = index;
        if (value < 0) {
            Rect_guess rect;
            Rect_guess scratch;
            int buffer[2];
            rect.left_guess = 0;
            rect.top_guess = 0;
            rect.right_guess = 0;
            rect.bottom_guess = 0;
            selectedMoneyButton_0164_guess = index;
            int amount = GetValue_guess(index);
            if (money_16c[index] != 0) {
                void* source = ((TextWnd_guess*)money_16c[index])->Slot57_guess(buffer);
                rect.CopyTo_guess(&scratch, source);
            }
            CXPoint point;
            rect.CenterPoint(&point);
            pinstCQuantityWnd_guess->Function_0054d976_guess(this, amount, amount, point.x, point.y, 1);
            return;
        }
    }
    reinterpret_cast<EverQuestExt_guess*>(pEverQuest)->MoveMoney_guess(mode, show, slot, index, value, 0);
    UpdateMoney_guess();
}

// Every 200 ms: on the inventory page, refreshes coins and crystals and greys the experience gauges while the
// character can't gain (the AA gauge also below level 51); restarts the class animation about every 6 s.
// On the evolving page, refreshes that list.
// FUNCTION: TITANIUM 0x00517BFB
void CInventoryWndView_guess::OnProcessFrame_guess()
{
    if (((Client_state_guess*)this)->CheckReady_guess() != 0) {
        if (field_260 == 1) {
            if ((unsigned int)g_invDisplay_guess->frameTime_0148_guess > (unsigned int)field_230 + 200U) {
                if (field_264 != 0) {
                    FillEvolvingItemList_guess();
                }
                ((Owner_guess*)this)->Update_guess();
                field_230 = g_invDisplay_guess->frameTime_0148_guess;
            }
        } else if (field_260 == 0 &&
            (unsigned int)g_invDisplay_guess->frameTime_0148_guess > (unsigned int)field_230 + 200U) {
            ++field_234;
            if (g_root_guess != 0) {
                RootData_guess* rootData = (RootData_guess*)g_root_guess;
                StatusHost_guess* statusHost = (StatusHost_guess*)
                    &rootData->data_008[rootData->vbtable_0008_guess->vbase_offset];
                int status = statusHost->GetStatus_guess();
                char canUse = !status;
                if (nextLevelLabel_1f4 != 0) {
                    ((TextWnd_guess*)nextLevelLabel_1f4)->SetEnabled_guess(canUse, true);
                }
                if (expGauge_1f8 != 0) {
                    ((TextWnd_guess*)expGauge_1f8)->SetEnabled_guess(canUse, true);
                }
                if (altAdvLabel_1fc != 0) {
                    ((TextWnd_guess*)altAdvLabel_1fc)->SetEnabled_guess(
                        canUse != 0 && ((Wrapper_guess*)&((RootData_guess*)g_root_guess)->data_008[
                            ((RootData_guess*)g_root_guess)->vbtable_0008_guess->vbase_offset])->Get_guess()->level_11a4 >= 0x33,
                        true);
                }
                if (altAdvGauge_200 != 0) {
                    ((TextWnd_guess*)altAdvGauge_200)->SetEnabled_guess(
                        canUse != 0 && ((Wrapper_guess*)&((RootData_guess*)g_root_guess)->data_008[
                            ((RootData_guess*)g_root_guess)->vbtable_0008_guess->vbase_offset])->Get_guess()->level_11a4 >= 0x33,
                        true);
                }
            }
            field_230 = g_invDisplay_guess->frameTime_0148_guess;
            UpdateMoney_guess();
            UpdateAlignment_guess();
            if (field_234 > 0x1e) {
                if (callbackLink != 0 && callbackLink->target != 0) {
                    callbackLink->target->FUN_005b1730_guess(0);
                }
                field_234 = 0;
            }
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Name or label string, VC 7.1 std::string layout: buffer or pointer at +0, size +0x10, capacity +0x14.
struct StdString_guess {
    union {
        char buf[16];
        char* ptr;
    };
    unsigned int size;
    unsigned int res;
    const char* c_str() const { return res < 16 ? buf : ptr; }
};

// Progression list node: id at +0x08, name at +0x10, cur/max at +0x44/+0x48, label at +0x50, percent at +0x84.
struct ProgressNode_guess {
    ProgressNode_guess* next;               // 0x00
    char pad_0004[4];
    int id_008;                             // 0x08
    char pad_000c[4];
    StdString_guess name_010;               // 0x10
    char pad_0028[0x1c];
    int cur_044;                            // 0x44
    int max_048;                            // 0x48
    char pad_004c[4];
    StdString_guess label_050;              // 0x50
    char pad_0068[0x1c];
    unsigned int percent_084;               // 0x84
};

// The progression list's vtable slots used here (slot 64 and 76 are the list's own virtuals).
struct ListVtbl_guess {
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
    virtual void Slot64_guess(int value);
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
    char pad_0004[0x108];
    int scroll_10c;                         // 0x10C
    int GetScroll_guess() { return scroll_10c; }
};

// Progression detail node used by the description panel.
struct ProgressionDetail_guess {
    ProgressionDetail_guess* next;           // 0x00
    char pad_0004[4];
    int id_008;                              // 0x08
    char pad_000C[0x20];
    StdString_guess currentClass_02C;         // 0x2C
    int cur_044;                             // 0x44
    int max_048;                             // 0x48
    char pad_004C[0x20];
    StdString_guess nextClass_06C;            // 0x6C
    int percent_084;                         // 0x84
};

struct CXStrCat_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00572C10 CXStrCat_guess::Append_guess
    void Append_guess(const CXStr& other);
};

struct MessageObject_guess {
    // EXTERNAL: TITANIUM 0x005E0EC0 MessageObject_guess::GetMessage_guess
    int GetMessage_guess();
};

struct MessagePrefix_guess {
    char pad_0000[0x10];
};

struct MessageData_guess {
    char pad_0000[0x78];
    MessageObject_guess* messageObject;     // 0x78 past the 0x10 prefix
    MessageObject_guess* GetMessageObject_guess() { return messageObject; }
};

struct MessageResult_guess : MessagePrefix_guess, MessageData_guess {
};

struct Setting_guess {
    char pad_0000[0x11];
    char ready;                             // 0x11
};

#define g_setting_guess EQ_GLOBAL(Setting_guess*, 0x00905D24)
#define pinstCInventoryWnd_guess EQ_GLOBAL(unsigned int, 0x00850C34)

// EXTERNAL: TITANIUM 0x0046DA4A FormatMessage_guess
void __cdecl FormatMessage_guess(char* output, int id, int message,
                                 int a3, int a4, int a5, int a6, int a7,
                                 int a8, int a9, int a10);
// EXTERNAL: TITANIUM 0x004BE5FE DestroyHeldItemOrMoney
void __cdecl DestroyHeldItemOrMoney();

// Item list entry: visible at +0x60, value at +0x68, percent at +0x70, special flag at +0x78.
struct ItemEntry_guess {
    char pad_0000[0x60];
    unsigned char visible_060;
    char pad_0061[7];
    int value_068;
    char pad_006c[4];
    double percent_070;
    unsigned char special_078;
    // EXTERNAL: TITANIUM 0x005E0F60 ItemEntry_guess::GetName_guess
    const char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ItemEntry_guess::GetDescription_guess
    const char* GetDescription_guess();
};

struct ItemArray_guess {
    // EXTERNAL: TITANIUM 0x0041DE16 ItemArray_guess::GetItemBySlot_guess
    ItemEntry_guess* GetItemBySlot_guess(int index);
};

struct ItemArrayRoot_guess {
    char pad_0000[0xc280];
    ItemArray_guess items;
};

struct NameProcessor_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 NameProcessor_guess::GetIcon_guess
    const char* GetIcon_guess(const char* text);
};

struct CListText_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059B2E0 CListText_guess::SetItemText_guess
    void SetItemText_guess(int row, int column, const char* text);
};

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* destination_guess, int radix_guess);

#define g_nameProcessor_guess EQ_GLOBAL(NameProcessor_guess*, 0x00991910)
#define g_itemBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// Evolving items (slots 0-21 that evolve): name, description, level, percent and "yes" (string 13219) when
// the item's special flag is set; keeps the selection and scroll position.
// FUNCTION: TITANIUM 0x005169AF
// @early-stop: unknown, structural ndiff=14
void CInventoryWndView_guess::FillEvolvingItemList_guess()
{
    if (itemList_238 != 0) {
        int selectedData = -1;
        {
            int selectedRow = ((CListWnd*)itemList_238)->GetCurSel();
            if (selectedRow != -1) {
                selectedData = (int)((CListWnd*)itemList_238)->GetItemData(selectedRow);
            }
        }
        int position = itemList_238->field_10c;
        ((ListVtbl_guess*)itemList_238)->Slot76_guess();
        for (int index = 0; index <= 21; ++index) {
            ItemEntry_guess* entry = ((ItemArrayRoot_guess*)g_root_guess)->items.GetItemBySlot_guess(index);
            if (entry != 0 && entry->visible_060 != 0) {
                int row;
                {
                    CXStr empty(g_emptyString_guess);
                    row = ((CListWnd*)itemList_238)->AddString(empty, 0xffffffff, index, 0);
                }
                ((CListText_guess*)itemList_238)->SetItemText_guess(row, 0,
                    g_nameProcessor_guess->GetIcon_guess(entry->GetName_guess()));
                {
                    CXStr description(entry->GetDescription_guess());
                    ((CListWnd*)itemList_238)->SetItemText(row, 1, description);
                }
                {
                    CXStr value(_itoa(entry->value_068, g_itemBuffer_guess, 10));
                    ((CListWnd*)itemList_238)->SetItemText(row, 2, value);
                }
                {
                    CXStr percentage;
                    FormatString_guess(&percentage, "%d%%", (int)entry->percent_070);
                    ((CListWnd*)itemList_238)->SetItemText(row, 3, percentage);
                    if (entry->special_078 != 0) {
                        percentage = pStringTable->getString(0x33a3, 0);
                    } else {
                        percentage = g_emptyString_guess;
                    }
                    ((CListWnd*)itemList_238)->SetItemText(row, 4, percentage);
                }
            }
        }
        ((ListVtbl_guess*)itemList_238)->Slot78_guess();
        if (selectedData != -1) {
            for (int index = 0; index < ((CListWnd*)itemList_238)->ItemsCount; ++index) {
                if (((CListWnd*)itemList_238)->GetItemData(index) == (unsigned int)selectedData) {
                    ((CListWnd*)itemList_238)->SetCurSel(index);
                    break;
                }
            }
        }
        ((ListVtbl_guess*)itemList_238)->Slot64_guess(position);
    }
    field_264 = 0;
}

// Destroy button: asks "Are you absolutely sure you want to destroy your %1?" (2043) for the cursor item or
// "... the money you are holding?" (2061), unless the no-confirm option (0x9249A0) is on.
// FUNCTION: TITANIUM 0x00517DC3
// @early-stop: budget, diff ndiff=41
void ConfirmDestroyHeld_guess()
{
    RootData_guess* root = (RootData_guess*)g_root_guess;
    if (root == 0) {
        return;
    }
    char message[512];
    if (EQ_GLOBAL(int, 0x009249A0) == 0) {
        Wrapper_guess* wrapper = (Wrapper_guess*)&root->data_008[root->vbtable_0008_guess->vbase_offset];
        if (((MessageResult_guess*)wrapper->Get_guess())->GetMessageObject_guess() != 0) {
            RootData_guess* rootData2 = (RootData_guess*)g_root_guess;
            Wrapper_guess* wrapper2 = (Wrapper_guess*)&rootData2->data_008[rootData2->vbtable_0008_guess->vbase_offset];
            MessageObject_guess* object = ((MessageResult_guess*)wrapper2->Get_guess())->GetMessageObject_guess();
            FormatMessage_guess(message, 0x7fb, object->GetMessage_guess(), 0, 0, 0, 0, 0, 0, 0, 0);
        } else {
            if (g_setting_guess->ready == 0) {
                return;
            }
            char* text = pStringTable->getString(0x80d, 0);
            strcpy(message, text);
        }
        pConfirmationDialogPool_guess->Activate(
            (void*)(pinstCInventoryWnd_guess != 0 ? pinstCInventoryWnd_guess + 0x15cU : 0),
            100, message, 0xc, 10000, 0, 1);
    } else {
        DestroyHeldItemOrMoney();
    }
}

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag_guess
CXStr ColorTag_guess(unsigned int color);
// EXTERNAL: TITANIUM 0x0042E3D9 Join_guess
CXStr Join_guess(const char* prefix, const CXStr& color);
// EXTERNAL: TITANIUM 0x004B1357 Concat_guess
CXStr Concat_guess(const CXStr& head, const char* tail);
// EXTERNAL: TITANIUM 0x005738B0 FormatPct_guess
CXStr FormatPct_guess(const char* format, int value);

// Progression description (STML): the current monster class, then the next one and its percent, or "All
// monster classes in this progression are available." in green.
// FUNCTION: TITANIUM 0x005181AF
// @early-stop: budget, structural ndiff=102
void CInventoryWndView_guess::UpdateProgressionInfo_guess()
{
    if (progressionList_248 != 0 && progressionInfo_24c != 0 && g_dispatcher_guess != 0) {
        int row = ((CListWnd*)progressionList_248)->GetCurSel();
        int key = 0;
        if (row != -1) {
            key = ((CListWnd*)progressionList_248)->GetItemData(row);
        }
        if (key == 0) {
            ((CStmlWnd*)progressionInfo_24c)->SetSTMLText("", true, 0);
        } else {
            ProgressionDetail_guess* head =
                (ProgressionDetail_guess*)g_dispatcher_guess->sentinel_020;
            for (ProgressionDetail_guess* node = head->next; node != head; node = node->next) {
                if (node->id_008 == key) {
                    unsigned int color = 0xff8aa3ff;
                    CXStrCat_guess text;
                    {
                        CXStr colorTag = ColorTag_guess(color);
                        CXStr prefix = Join_guess("<C ", colorTag);
                        CXStr label = Concat_guess(prefix, ">Progression: </C>");
                        text.Append_guess(label);
                    }
                    text += node->currentClass_02C.c_str();
                    text += "<BR>";
                    if (node->cur_044 == node->max_048) {
                        {
                            CXStr colorTag = ColorTag_guess(0xff00ff00);
                            CXStr prefix = Join_guess("<C ", colorTag);
                            CXStr label = Concat_guess(prefix, ">");
                            text.Append_guess(label);
                        }
                        text += "All monster classes in this progression are available.";
                        text += "<BR>";
                    } else {
                        CXStr pct = FormatPct_guess("%d%%", node->percent_084);
                        {
                            CXStr colorTag = ColorTag_guess(color);
                            CXStr prefix = Join_guess("<C ", colorTag);
                            CXStr label = Concat_guess(prefix, ">Next Monster Class: </C>");
                            text.Append_guess(label);
                        }
                        text += node->nextClass_06C.c_str();
                        text += " (";
                        text.Append_guess(pct);
                        text += " completed)<BR>";
                    }
                    ((CStmlWnd*)progressionInfo_24c)->SetSTMLText(text, true, 0);
                    break;
                }
            }
        }
    }
}

// Progression list: name, done/total, and the next class with its percent (green text when complete).
// FUNCTION: TITANIUM 0x005188F4
void CInventoryWndView_guess::UpdateProgress_guess()
{
    if (progressionList_248 != 0 && g_dispatcher_guess != 0) {
        int selectedId = -1;
        int cur = ((CListWnd*)progressionList_248)->GetCurSel();
        if (cur != -1) {
            selectedId = ((CListWnd*)progressionList_248)->GetItemData(cur);
        }
        int scroll = ((ListVtbl_guess*)progressionList_248)->GetScroll_guess();
        int selectedRow = -1;
        ((ListVtbl_guess*)progressionList_248)->Slot76_guess();
        ProgressNode_guess** headSlot = &g_dispatcher_guess->sentinel_020;
        ProgressNode_guess* node = (*headSlot)->next;
        if (node != *headSlot) {
            do {
                CXStr text;
                int row = ((CListWnd*)progressionList_248)->AddString(EQ_ARRAY(char, 0x0063F53F), 0xffffffff, 0, 0);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), progressionList_248)(
                    row, 0, node->name_010.res >= 16 ? node->name_010.ptr : node->name_010.buf);
                FormatString_guess(&text, "%d/%d", node->cur_044, node->max_048);
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), progressionList_248)(
                    row, 1, text);
                if (node->percent_084 > 0 && node->percent_084 < 100) {
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), progressionList_248)(
                        row, 2, node->label_050.res >= 16 ? node->label_050.ptr : node->label_050.buf);
                    FormatString_guess(&text, "%d%%", node->percent_084);
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), progressionList_248)(
                        row, 3, text);
                } else {
                    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), progressionList_248)(
                        row, 2, EQ_ARRAY(char, 0x0065673C));
                    EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int), progressionList_248)(
                        row, 2, 0xff00ff00);
                }
                ((CListWnd*)progressionList_248)->SetItemData(row, node->id_008);
                if (node->id_008 == selectedId) {
                    selectedRow = row;
                }
            } while ((node = node->next) != *headSlot);
        }
        ((CListWnd*)progressionList_248)->SetCurSel(selectedRow);
        ((ListVtbl_guess*)progressionList_248)->Slot64_guess(scroll);
        UpdateProgressionInfo_guess();
    }
}

// Done hides; Reclaim sends OP_ReclaimCrystals (no payload); the crystal and coin boxes start the quantity
// flow, whose answer comes back as message 0x1F; Tint and Face open their windows when the character allows
// it;
// Skills and Alt. Adv. toggle theirs. Toggle/All On/All Off switch evolving on items.
// FUNCTION: TITANIUM 0x0051853F
// @early-stop: budget, structural ndiff=48
int CInventoryWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data)
{
    if (CheckReady_guess() == 0) {
        return 1;
    }
    if (message == 1) {
        if (sender == (CXWnd*)progressionList_248) {
            UpdateProgressionInfo_guess();
        } else if (sender == doneButton_210) {
            Slot34_guess();
        } else if (sender == subwindows_25c) {
            field_260 = *(int*)data;
        } else if (sender == toggleButton_23c) {
            InvListWnd_guess* list = itemList_238;
            if (list != 0) {
                int selected = ((CListWnd*)itemList_238)->GetCurSel();
                if (selected != -1) {
                    unsigned int itemData = ((CListWnd*)itemList_238)->GetItemData(selected);
                    ItemSlot_guess* slot = ((CharBig_guess*)pCharData)->sub_c280.GetItemBySlot_guess(itemData);
                    if (slot != 0) {
                        RequestEvolvingItemToggle_guess(slot, !slot->flag_078);
                    }
                }
            }
        } else if (sender == (CXWnd*)allOnButton_240 || sender == (CXWnd*)allOffButton_244) {
            if (itemList_238 != 0 && ((CListWnd*)itemList_238)->ItemsCount > 0) {
                int index = 0;
                do {
                    if (index != -1) {
                        unsigned int itemData = ((CListWnd*)itemList_238)->GetItemData(index);
                        ItemSlot_guess* slot = ((CharBig_guess*)pCharData)->sub_c280.GetItemBySlot_guess(itemData);
                        if (slot != 0) {
                            RequestEvolvingItemToggle_guess(slot, sender == (CXWnd*)allOnButton_240);
                        }
                    }
                    ++index;
                } while (index < ((CListWnd*)itemList_238)->ItemsCount);
            }
        } else if (sender == reclaimButton_224) {
            EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), OP_ReclaimCrystals, 0, 0, 1);
        } else if (sender == goodPoints_21c) {
            ClickedCrystalButton_guess(4, -1);
        } else if (sender == evilPoints_220) {
            ClickedCrystalButton_guess(5, -1);
        } else if (sender == tintingButton_218) {
            EQ_PC* character = (EQ_PC*)pCharData;
            if (character != 0 && ((CharLevel_guess*)((unsigned int)character + character->vbtable[1] + 8))->Get_guess() == 0) {
                CBodyTintWnd_guess* state = pinstCBodyTintWnd_guess;
                if (state != 0) {
                    state->Activate();
                }
            }
        } else if (sender == facePickButton_214) {
            EQ_PC* character = (EQ_PC*)pCharData;
            if (character != 0 && ((CharLevel_guess*)((unsigned int)character + character->vbtable[1] + 8))->Get_guess() == 0) {
                CFacePick_guess* state = pinstCFacePick_guess;
                if (state != 0) {
                    state->Activate();
                }
            }
        } else if (sender == destroyButton_204) {
            ConfirmDestroyHeld_guess();
        } else if (sender == skillsButton_208) {
            if (pinstCSkillsWnd_guess->IsVisible_guess() != 0) {
                pinstCSkillsWnd_guess->Deactivate();
            } else {
                pinstCSkillsWnd_guess->Activate();
            }
        } else if (sender == altAdvButton_20c) {
            if (pinstCAAWnd_guess->IsVisible_guess() != 0) {
                pinstCAAWnd_guess->Deactivate();
            } else {
                pinstCAAWnd_guess->Activate();
            }
        } else {
            for (int slot = 0; slot < 4; ++slot) {
                if (sender == money_16c[slot]) {
                    ClickedMoneyButton_guess(slot, -1);
                }
            }
        }
    } else if (message == 0x1f) {
        if (selectedMoneyButton_0164_guess != -1) {
            ClickedMoneyButton_guess(selectedMoneyButton_0164_guess, *(int*)data);
            selectedMoneyButton_0164_guess = -1;
        } else if (selectedCrystal_0168_guess != -1) {
            ClickedCrystalButton_guess(selectedCrystal_0168_guess, *(int*)data);
            selectedCrystal_0168_guess = -1;
        }
        return 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// A drop on the character view: an item on the cursor (mode 2) is auto-equipped (sound 0x92), coins
// (mode 3) go back into their box.
// FUNCTION: TITANIUM 0x0051881C
int CInventoryWndView_guess::HandleLButtonUp_guess(const CXPoint* point_guess, unsigned int flags)
{
    if (characterView_22c != 0) {
        CXRect rect = ((CXWnd*)characterView_22c)->GetScreenRect();
        if (((Rect_guess&)rect).Contains_guess(point_guess) && (flags & 0xffff0000) != 0x10000) {
            if (pinstCCursorAttachment_guess->mode_15c_guess == 2) {
                Wrapper_guess* wrapper = reinterpret_cast<Wrapper_guess*>(
                    reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
                CharInfoOuter_guess* info = reinterpret_cast<CharInfoOuter_guess*>(wrapper->Get_guess());
                CharInfoState_guess* state = &info->state_guess;
                if (state->value_guess != 0) {
                    g_resourceUser_guess->WavePlay_guess(0x92, 0);
                    Wrapper_guess* wrapper2 = reinterpret_cast<Wrapper_guess*>(
                        reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
                    CharInfoOuter_guess* info2 = reinterpret_cast<CharInfoOuter_guess*>(wrapper2->Get_guess());
                    CharInfoState_guess* state2 = &info2->state_guess;
                    AutoEquipItem_guess(g_root_guess, &state2->value_guess, 0x1e);
                }
            } else if (pinstCCursorAttachment_guess->mode_15c_guess == 3) {
                ClickedMoneyButton_guess(g_invDisplay_guess->cursorMoneyType_0011_guess - 1, -1);
            }
        }
    }
    return 0;
}

// Inventory window AboutToHide (vtable 0x6563C8 slot 50): removes its listener part (+0x160) from the
// listener list at 0x79C120 (0x00518B72); never vetoes.
// FUNCTION: TITANIUM 0x00518BA3
char __fastcall Callback_guess(int value)
{
    unsigned int local = 0;
    if (g_dispatcher_guess != 0) {
        local = value != 0 ? value + 0x160 : 0;
        g_dispatcher_guess->Submit_guess(&local);
    }
    return 1;
}

struct AnimTable_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 AnimTable_guess::Find_guess
    int Find_guess(const CXStr& name);
};

#define g_animTable_guess EQ_GLOBAL(AnimTable_guess*, 0x0099D3F4)
#define g_controlledPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)

// Loads the class animation A_ClassAnim<class> and enables Face and Tint while the character may change them.
// FUNCTION: TITANIUM 0x00518BF3
void CInventoryWndView_guess::Refresh_guess()
{
    if (callbackLink != 0 && callbackLink->target != 0 && g_controlledPlayer_guess != 0) {
        char animName[0x40];
        sprintf(animName, "A_ClassAnim%02d", g_controlledPlayer_guess->Class);
        int anim = g_animTable_guess->Find_guess(animName);
        if (anim != 0) {
            callbackLink->target->Attach_guess(anim);
            callbackLink->target->flag_2D = false;
        }
    }
    if (g_root_guess != 0) {
        StatusHost_guess* host = reinterpret_cast<StatusHost_guess*>(
            reinterpret_cast<char*>(g_root_guess) + g_root_guess->offset->vbase_offset + 8);
        bool state = host->GetStatus_guess() == 0;
        if (facePickButton_214 != 0) {
            ((Destination_guess*)facePickButton_214)->flag = state;
        }
        if (tintingButton_218 != 0) {
            ((Destination_guess*)tintingButton_218)->flag = state;
        }
    }
}

// Opens on the inventory page and refreshes everything; Tint stays off unless 0x9247A0 is set.
// FUNCTION: TITANIUM 0x00518D79
char CInventoryWndView_guess::AboutToShow_guess()
{
    Refresh_guess();
    field_260 = 0;
    if (invPage_250 != 0 && subwindows_25c != 0) {
        ((SubwindowsHost_guess*)subwindows_25c)->SetPage_guess(invPage_250, 1);
    }
    UpdateMoney_guess();
    UpdateAlignment_guess();
    FillEvolvingItemList_guess();
    if (g_flag_9247a0_guess == 0 && tintingButton_218 != 0) {
        ((Destination_guess*)tintingButton_218)->flag = false;
    }
    selectedMoneyButton_0164_guess = -1;
    selectedCrystal_0168_guess = -1;
    Dispatcher_guess* dispatcher = g_dispatcher_guess;
    if (dispatcher != 0) {
        dispatcher->PushFront_guess(this);
    }
    UpdateProgress_guess();
    return 1;
}

