// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 132: a hint from compare/tumap.py.
// CBazaarWnd ("BazaarWnd", 0x5F8): the trader's bazaar manager. It lists the items in Trader's Satchels
// (item id 17899) in bags 22-29, keeps prices in BZR_<name>_<server>.ini, and drives trader mode through
// OP_Trader (0x524E; first int the action: 1 start, 2 end, 3 price, 10 sold, 11 list, 13 browsing).
// SellWindow_guess and TickerWindow_guess are more views of this window; prices are in copper.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <windows.h>

extern "C" int __cdecl sprintf(char* output, const char* format, ...);
extern "C" unsigned int __cdecl strlen(const char* input);
extern "C" void* __cdecl memset(void* output, int value, unsigned int size);
// EXTERNAL: TITANIUM 0x0060E3A3 _atol
extern "C" long __cdecl atol(const char* value);
// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, int id, const char* text, ...);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value, char* output, int radix);

struct Item_guess {
    char pad_0000[0x58];
    int stack_count_0058;
    char pad_005c[0xc4];
    char name_0120_guess[0x30];
    int color_150;
    int color_154;
    // EXTERNAL: TITANIUM 0x005ECD20 Item_guess::GetItemType_guess
    int GetItemType_guess(int index);
    // EXTERNAL: TITANIUM 0x005E0EC0 Item_guess::GetName_guess
    const char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005E32E0 Item_guess::IsSellable_guess
    char IsSellable_guess(int param_2, int param_3);
};

struct SellWindow_guess {
    char pad_0000[0x1a4];
    Item_guess* items_01a4[80];
    Item_guess* items_02e4[80];
    int values_0424[80];
    char flags_0564[0x50];
    char item_text_05b4[0x40];
    char flag_05f4;
    void SetItemToSell_guess(Item_guess* item, int index, int value);
    bool Deactivate_guess();
    void UpdateItemColors_guess(int param_2, char param_3);
    void UpdateSellItems_guess(char param_2);
    void LoadSellItems_guess();
    // EXTERNAL: TITANIUM 0x004E4CA6 SellWindow_guess::AddBazaarText_guess
    void AddBazaarText_guess(char* text, int color);
};

#define g_resumeTraderMode_guess EQ_GLOBAL(char, 0x00991680)

struct TextValue_guess {
    int field_0000_guess;
    int field_0004_guess;
    int field_0008_guess;
    int field_000c_guess;
    // EXTERNAL: TITANIUM 0x004D9160 ??4TextValue_guess@@QAE?AU0@ABU0@@Z
    TextValue_guess operator=(const TextValue_guess& value);
};

#include "titanium/layouts/geometry.h"

#include "titanium/layouts/core.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CChatManager.h"
#include "titanium/wnd/CQuantityWnd.h"

struct TickerItem_guess {
    char pad_0000[0x28];
    TickerItem_guess* nested_0028_guess;
    char pad_002c[0x114];
    RecordLink_guess* link_0140_guess;
    // EXTERNAL: TITANIUM 0x0059D960 TickerItem_guess::GetScreenRect
    TextValue_guess GetScreenRect();
    // EXTERNAL: TITANIUM 0x0059FEC0 TickerItem_guess::IsReallyVisible
    unsigned char IsReallyVisible();
    // EXTERNAL: TITANIUM 0x005A02F0 TickerItem_guess::ApplyPoint_guess
    void ApplyPoint_guess(CXPoint* point);
};

struct TickerWindow_guess {
    char pad_0000[0x62];
    char enabled_0062_guess;
    char pad_0063[0x141];
    TickerItem_guess* items_01a4_guess[0x50];
    int PostDraw_guess();
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x0044D0D0 ValidateItemType_guess
bool __cdecl ValidateItemType_guess(int item_type);
// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* output, const char* input);
// EXTERNAL: TITANIUM 0x0060BE50 ReadSetting_guess
void __cdecl ReadSetting_guess(const char* name, const char* value, const char* fallback,
                               char* output, int size, char* storage);
// EXTERNAL: TITANIUM 0x0060BEB0 WriteSetting_guess
void __cdecl WriteSetting_guess(const char* name, const char* value, const char* fallback,
                                char* storage);

struct TextSource_guess {
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
    virtual CXPoint Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void SetText_guess(const CXStr& text); // 0xFC
    // EXTERNAL: TITANIUM 0x004D22D7 TextSource_guess::GetText_guess
    CXStr GetText_guess();
};

struct BazaarButton_guess {
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
    virtual void SetPressed_guess(int value, int flag);    // slot 0x30 (0xc0)
    char pad_004[0x59];
    unsigned char Enabled;                                  // 0x5d
};

struct SellItem_guess;

struct CBazaarWndMoneyView_guess {
    char pad_0000[0x15c];
    int selected_slot_015c_guess;               // 0x15c
    char pad_0160[4];
    unsigned int money_0164_guess;              // 0x164
    int field_0168_guess;                       // 0x168
    SellItem_guess* field_016c_guess;           // 0x16c
    BazaarButton_guess* startButton_0170_guess; // 0x170
    BazaarButton_guess* endButton_0174_guess;   // 0x174
    BazaarButton_guess* clearButton_0178_guess; // 0x178
    BazaarButton_guess* setPriceButton_017c_guess; // 0x17c
    BazaarButton_guess* listButton_0180_guess;  // 0x180
    char pad_0184[4];
    BazaarButton_guess* addButton_0188_guess;   // 0x188
    BazaarButton_guess* removeButton_018c_guess;// 0x18c
    TextSource_guess* fields_0190_guess[4];     // 0x190
    char pad_01a0[0x144];
    SellItem_guess* sell_items_02e4[0x50];      // 0x2e4
    int values_0424[0x50];                      // 0x424
    char flags_0564_guess[0x50];                // 0x564
    char pad_05b4[0x40];
    unsigned char flag_05f4_guess;              // 0x5f4

    int GetQtyFromCoinType_guess(int index);
    int GetTotalCopper_guess();
    char* FormatMoneyText_guess(unsigned int amount);
    void UpdatePriceButtons_guess();
    void UpdateMoney_guess();
    void SetFieldMoney_guess(int index, int value);
    void SetSelected_guess(int value, int unused_guess);
    void ClickedMoneyButton_guess(int index, int value);
};

// Copper amount as " 1p 2g 3s 4c" (zero coins left out; "0" for nothing), in the shared static buffer
// 0x9916A0: the next call overwrites it.
// FUNCTION: TITANIUM 0x004E4DC4
char* CBazaarWndMoneyView_guess::FormatMoneyText_guess(unsigned int amount) {
    int platinum = (int)(amount / 1000u);
    int gold = (int)((amount % 1000u) / 100u);
    int silver = (int)((amount % 100u) / 10u);
    int copper = (int)(amount % 10u);
    char platinum_text[16];
    char gold_text[16];
    char silver_text[16];
    char copper_text[16];

    if (platinum > 0) {
        sprintf(platinum_text, " %dp", platinum);
    } else {
        CopyText_guess(platinum_text, EQ_ARRAY(char, 0x0063F53F));
    }
    if (gold > 0) {
        sprintf(gold_text, " %dg", gold);
    } else {
        CopyText_guess(gold_text, EQ_ARRAY(char, 0x0063F53F));
    }
    if (silver > 0) {
        sprintf(silver_text, " %ds", silver);
    } else {
        CopyText_guess(silver_text, EQ_ARRAY(char, 0x0063F53F));
    }
    if (copper > 0) {
        sprintf(copper_text, " %dc", copper);
    } else {
        CopyText_guess(copper_text, EQ_ARRAY(char, 0x0063F53F));
    }

    char* result = EQ_ARRAY(char, 0x009916A0);
    sprintf(result, "%s%s%s%s", platinum_text, gold_text, silver_text, copper_text);
    if (strlen(result) == 0) {
        CopyText_guess(result, EQ_ARRAY(char, 0x006410A8));
    }
    return result;
}

// Puts `item` in bazaar slot `index` with the price stored in the INI (section ItemToSell), writing "0"
// when it has none. The key is the item name, plus ":<charges>" (+0x58) when the item has a valid
// spell, so clickies with different charges keep separate prices.
// FUNCTION: TITANIUM 0x004E4EE8
void SellWindow_guess::SetItemToSell_guess(Item_guess* item, int index, int value) {
    int* stored_value = &this->values_0424[index];
    *stored_value = value;
    this->items_02e4[index] = item;
    this->flags_0564[index] = 0;

    char item_name[128];
    char setting_value[64];
    if (ValidateItemType_guess(item->GetItemType_guess(0)) && item->stack_count_0058 > 0) {
        sprintf(item_name, "%s:%d", item->GetName_guess(), item->stack_count_0058);
    } else {
        CopyText_guess(item_name, item->GetName_guess());
    }
    ReadSetting_guess("ItemToSell", item_name, "*NULL*", setting_value, 0x40,
                      this->item_text_05b4);
    if (setting_value[0] == '*') {
        WriteSetting_guess("ItemToSell", item_name,
                           EQ_ARRAY(char, 0x006410A8), this->item_text_05b4);
    } else {
        *stored_value = (int)atol(setting_value);
    }
}

// Ends trader mode (OP_Trader action 2) and forgets the listed items.
// FUNCTION: TITANIUM 0x004E4FC8
bool SellWindow_guess::Deactivate_guess() {
    int message[5];
    memset(message, 0, 0x14);
    message[0] = 2;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, message, 0x14, 1);
    g_resumeTraderMode_guess = 0;
    Item_guess** item = this->items_02e4;
    for (int count = 0x50; count != 0; --count) {
        *item++ = 0;
    }
    this->flag_05f4 = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    return true;
}

// While keyboard flags 0x0C are held, places an overlay at every filled slot (5 left of it; 2 below the
// top on the first row, 22 on later rows), skipping slots scrolled out of the slot pane.
// FUNCTION: TITANIUM 0x004E502C
int TickerWindow_guess::PostDraw_guess() {
    if ((pinstCXWndManager_guess->GetKeyboardFlags() & 0x0c) != 0 && this->enabled_0062_guess != 0) {
        TickerItem_guess** cursor = this->items_01a4_guess;
        TickerItem_guess* first = *cursor;
        int first_index = -1;
        TextValue_guess initial;
        TextValue_guess current;
        CXPoint point;
        int count;
        char have_initial;

        point.x = 0;
        point.y = 0;
        current.field_000c_guess = 0;
        current.field_0008_guess = 0;
        current.field_0004_guess = 0;
        current.field_0000_guess = 0;
        initial.field_000c_guess = 0;
        initial.field_0008_guess = 0;
        initial.field_0004_guess = 0;
        initial.field_0000_guess = 0;
        have_initial = 0;
        if (first != 0 && first->nested_0028_guess != 0) {
            initial = first->nested_0028_guess->GetScreenRect();
            have_initial = 1;
        }

        count = 0x50;
        do {
            if (*cursor != 0 && (*cursor)->IsReallyVisible() != 0) {
                TickerItem_guess* item = *cursor;
                int* records = item->link_0140_guess->records_guess;
                int first_record = records != 0 ? *records : 0;
                if (first_record != 0) {
                    current = item->GetScreenRect();
                    if (first_index == -1) {
                        first_index = current.field_0000_guess;
                    }
                    point.x = current.field_0008_guess - 5;
                    if (current.field_0000_guess == first_index) {
                        point.y = current.field_0004_guess + 2;
                    } else {
                        point.y = current.field_0004_guess + 0x16;
                    }
                    if (have_initial == 0 ||
                        (point.y <= initial.field_000c_guess - 0xf &&
                         point.y >= initial.field_0004_guess)) {
                        (*cursor)->ApplyPoint_guess(&point);
                    }
                }
            }
            ++cursor;
            --count;
        } while (count != 0);
    }
    return 0;
}

// Splits the price (+0x164, copper) into the four BZW_Money fields.
// FUNCTION: TITANIUM 0x004E5143
void CBazaarWndMoneyView_guess::UpdateMoney_guess() {
    unsigned int amount = this->money_0164_guess;
    int platinum = (int)(amount / 1000u);
    int gold = (int)((amount % 1000u) / 100u);
    int silver = (int)((amount % 100u) / 10u);
    int copper = (int)(amount % 10u);
    char text[32];

    sprintf(text, "%d", platinum);
    {
        CXStr value(text);
        this->fields_0190_guess[0]->SetText_guess(value);
    }

    sprintf(text, "%d", gold);
    {
        CXStr value(text);
        this->fields_0190_guess[1]->SetText_guess(value);
    }

    sprintf(text, "%d", silver);
    {
        CXStr value(text);
        this->fields_0190_guess[2]->SetText_guess(value);
    }

    sprintf(text, "%d", copper);
    {
        CXStr value(text);
        this->fields_0190_guess[3]->SetText_guess(value);
    }
}

// The amount typed into coin field `index` (0 platinum to 3 copper, the order the setter above fills);
// 0 for any other index.
// FUNCTION: TITANIUM 0x004E52D7
int CBazaarWndMoneyView_guess::GetQtyFromCoinType_guess(int index) {
    switch (index) {
    case 0:
        return atol(fields_0190_guess[0]->GetText_guess());
    case 1:
        return atol(fields_0190_guess[1]->GetText_guess());
    case 2:
        return atol(fields_0190_guess[2]->GetText_guess());
    case 3:
        return atol(fields_0190_guess[3]->GetText_guess());
    }
    return 0;
}

// Bazaar window: the price in the four coin fields as copper (platinum, gold, silver, copper, each a
// factor of 10). Set Price, the button refresh and the coin and button handlers use it.
// FUNCTION: TITANIUM 0x004E53FB
int CBazaarWndMoneyView_guess::GetTotalCopper_guess() {
    return ((GetQtyFromCoinType_guess(0) * 10 + GetQtyFromCoinType_guess(1)) * 10 + GetQtyFromCoinType_guess(2)) * 10 +
           GetQtyFromCoinType_guess(3);
}

// Green (0xFF00DF00 / 0xFF40FF40) marks slots on the bazaar list; others get UI colours 12 and 10.
// The first argument is really an item: 0 recolours every slot from its flag, else every slot holding a
// matching item gets flag `param_3`.
// FUNCTION: TITANIUM 0x004E5533
void SellWindow_guess::UpdateItemColors_guess(int param_2, char param_3) {
    int color1 = pinstCChatManager_guess->GetRGBAFromIndex(0xc);
    int color2 = pinstCChatManager_guess->GetRGBAFromIndex(0xa);
    if (param_2 == 0) {
        for (int i = 0; i < 0x50; ++i) {
            Item_guess* item = this->items_01a4[i];
            if (this->flags_0564[i] != 0) {
                item->color_154 = 0xff00df00;
                item->color_150 = 0xff40ff40;
            } else {
                item->color_154 = color1;
                item->color_150 = color2;
            }
        }
    } else {
        for (int i = 0; i < 0x50; ++i) {
            Item_guess* sell = this->items_02e4[i];
            if (sell != 0 && sell->IsSellable_guess(param_2, 1)) {
                if ((this->flags_0564[i] = param_3) != 0) {
                    Item_guess* item = this->items_01a4[i];
                    item->color_154 = 0xff00df00;
                    item->color_150 = 0xff40ff40;
                } else {
                    Item_guess* item = this->items_01a4[i];
                    item->color_154 = color1;
                    item->color_150 = color2;
                }
            }
        }
    }
}

/* ---- CBazaarWnd (0x5F8); layout of include/titanium/types.h CBazaarWnd ----------------------------- */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct BazaarText_guess {
    char pad_0000[0x1c0];
    int line_count_01c0_guess;              // 0x1c0
};

struct RankNode_guess;

// EXTERNAL: TITANIUM 0x00650F18 ??_7CBazaarWndView_guess@@6B@
struct CBazaarWndView_guess : CSidlScreenWndBase {
    int selected_slot_015c_guess;           // 0x15c
    int pad_0160_guess;                     // 0x160
    unsigned int money_0164_guess;          // 0x164
    int field_0168_guess;                   // 0x168
    int field_016c_guess;                   // 0x16c
    CXWnd* startButton_170;                 // 0x170 BZW_Start_Button
    CXWnd* endButton_174;                   // 0x174 BZW_End_Button
    CXWnd* clearButton_178;                 // 0x178 BZW_Clear_Button
    CXWnd* setPriceButton_17c;              // 0x17c BZW_SetPrice_Button
    CXWnd* listButton_180;                  // 0x180 BZW_List_Button
    CXWnd* pad_184;
    CXWnd* addButton_188;                   // 0x188 BZW_Add_Button
    CXWnd* removeButton_18c;                // 0x18c BZW_Remove_Button
    CXWnd* money_190[4];                    // 0x190 BZW_Money0..3
    CXWnd* bazaarText_1a0;                  // 0x1a0 BZW_BazaarText
    CXWnd* slots_1a4[80];                   // 0x1a4 BZR_BazaarSlot0..79
    CXWnd* sell_items_02e4[80];             // 0x2e4
    int values_0424[80];                    // 0x424
    char flags_0564[0x50];                  // 0x564
    char pad_05b4[0x40];                    // 0x5b4
    unsigned char field_5f4;                // 0x5f4
    char pad_5f5[3];

    void BuildIniPath_guess();
    void Init_guess();
    char Activate_guess();
    void AddBazaarText_guess(char* text, int value);
    int StartTraderMode_guess();
    char SetPriceForSelectedItem_guess();
    // EXTERNAL: TITANIUM 0x004E5BD4 CBazaarWndView_guess::ClickedMoneyButton_guess
    void ClickedMoneyButton_guess(int index, int value);
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
    // EXTERNAL: TITANIUM 0x004E63BD CBazaarWndView_guess::FUN_004e63bd_guess
    void FUN_004e63bd_guess();
    RankNode_guess* FindTraderSatchelItem_guess(int value);
    void HandleMessage_guess(int* message);
    CBazaarWndView_guess(CXWnd* parent);
};

struct SellItem_guess {
    char pad_0000[0x58];
    int c_0058_guess;                       // 0x58
    char pad_005c[0x24];
    int a_0080_guess;                       // 0x80
    int b_0084_guess;                       // 0x84
    // EXTERNAL: TITANIUM 0x005E0F30 SellItem_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 SellItem_guess::GetName_guess
    const char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 SellItem_guess::GetItemType_guess
    int GetItemType_guess(int index);
    // EXTERNAL: TITANIUM 0x005EC760 SellItem_guess::IsStackable_guess
    char IsStackable_guess();
};

struct SellMessage_guess {
    int header_0000[2];                     // 0x000
    int pairs_0008[160];                    // 0x008
    int values_0288[80];                    // 0x288
};

struct CharSub_guess {
    // EXTERNAL: TITANIUM 0x00417373 CharSub_guess::Check_guess
    int Check_guess(int value);
};

struct CharOwner_guess {
    char pad_0000[0xc280];
    CharSub_guess sub_c280;                 // 0xc280
    char pad_c281[7];
    int field_c288;                         // 0xc288
};

#define g_charOwner_guess EQ_GLOBAL(CharOwner_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag132_guess
CXStr __cdecl ColorTag132_guess(unsigned int color);
// EXTERNAL: TITANIUM 0x0042E3D9 Concat132_guess
CXStr __cdecl Concat132_guess(const char* first, const CXStr& second);
// EXTERNAL: TITANIUM 0x004B1357 Join132_guess
CXStr __cdecl Join132_guess(const CXStr& left, const char* right);
// EXTERNAL: TITANIUM 0x0049549E WriteBazaarLog_guess
void __cdecl WriteBazaarLog_guess(const char* message);

struct Sink132_guess {
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
    virtual void Slot64_guess(int value);   // 0x100
    char pad_0004[0x104];
    int field_0108_guess;                   // 0x108
    // EXTERNAL: TITANIUM 0x005AC2A0 Sink132_guess::Append_guess
    void Append_guess(int* link, CXStr text);
};

// Appends `text` in UI colour `value` to the BZW_BazaarText log, scrolls to the end, and also passes it to
// WriteBazaarLog_guess.
// FUNCTION: TITANIUM 0x004E4CA6
void CBazaarWndView_guess::AddBazaarText_guess(char* text, int value) {
    int link;
    CXStr line;
    line = Join132_guess(
        Concat132_guess(EQ_ARRAY(char, 0x0064AF8C),
                        ColorTag132_guess(pinstCChatManager_guess->GetRGBAFromIndex(value))),
        EQ_ARRAY(char, 0x00641684));
    line += text;
    line += "</c><br>";
    ((Sink132_guess*)this->bazaarText_1a0)->Append_guess(&link, line);
    {
        const unsigned long& field108 = ((Sink132_guess*)this->bazaarText_1a0)->field_0108_guess;
        ((Sink132_guess*)this->bazaarText_1a0)->Slot64_guess(field108);
    }
    WriteBazaarLog_guess(text);
}

// Sends the start of trader mode (OP_Trader action 1: every priced slot's item ids and price). Returns -1
// when not standing in a trader stall (the check on pCharData +0xC280, probably), -2 with nothing priced;
// on success disables Start/End until the server answers and remembers trader mode (0x991680).
// FUNCTION: TITANIUM 0x004E5436
int CBazaarWndView_guess::StartTraderMode_guess() {
    SellMessage_guess msg;
    char any = 0;
    int i = 0;
    memset(&msg, 0, sizeof(msg));
    if (g_charOwner_guess == 0 ||
        g_charOwner_guess->sub_c280.Check_guess(g_charOwner_guess->field_c288) != 0) {
        int* pairs_out = msg.pairs_0008;
        int* values_out = msg.values_0288;
        int* entry = (int*)this->sell_items_02e4;
        for (i = 0; i < 0x50; ++i, ++entry) {
            if (entry[0x50] != 0 && *entry != 0) {
                SellItem_guess* item = (SellItem_guess*)*entry;
                *values_out = entry[0x50];
                pairs_out[0] = item->a_0080_guess;
                pairs_out[1] = item->b_0084_guess;
                values_out = values_out + 1;
                this->flags_0564[i] = 1;
                any = 1;
                pairs_out = pairs_out + 2;
            }
        }
        if (any) {
            msg.header_0000[0] = 1;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, &msg, sizeof(msg), 1);
            ((BazaarButton_guess*)this->startButton_170)->Enabled = 0;
            ((BazaarButton_guess*)this->endButton_174)->Enabled = 0;
            g_resumeTraderMode_guess = 1;
            return 1;
        }
        return -2;
    }
    return -1;
}

struct BazaarPcPrefix_guess {
    int pad_0000_guess;
    int pad_0004_guess;
};

struct BazaarPcTextBase_guess {
    char pad_0000_guess[0x3c];
    char text_003c_guess[0x40];
};

struct BazaarPcView_guess : BazaarPcPrefix_guess, virtual BazaarPcTextBase_guess {
};

struct BazaarFiles_guess {
    // EXTERNAL: TITANIUM 0x00493B8F BazaarFiles_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
    // EXTERNAL: TITANIUM 0x00493ADA BazaarFiles_guess::FUN_00493ada_guess
    void FUN_00493ada_guess(char* output);
};

#define g_bazaarPc_guess EQ_GLOBAL(BazaarPcView_guess*, 0x00905D00)
#define g_bazaarFiles_guess EQ_GLOBAL(BazaarFiles_guess*, 0x00988DF0)
#define g_bazaarValue_guess EQ_GLOBAL(int, 0x00923D74)

// EXTERNAL: TITANIUM 0x0040552D GetLanguageCodePage_guess
int __cdecl GetLanguageCodePage_guess(int value_guess);
// EXTERNAL: TITANIUM 0x005749F0 FUN_005749f0_guess
void __cdecl FUN_005749f0_guess(int mode_guess, const char* input_guess, char* output_guess,
                                int size_guess);
// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
char __cdecl FileExists_guess(const char* path);
// EXTERNAL: TITANIUM 0x00612662 FUN_00612662_guess
void __cdecl FUN_00612662_guess(char* path_guess);
// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* output, const char* input);

// Builds the INI path (+0x5B4) .\BZR_<name>_<server>.ini. If only the file under the other server-name
// form exists, it is copied to the new name and the old one deleted.
// FUNCTION: TITANIUM 0x004E5610
void CBazaarWndView_guess::BuildIniPath_guess() {
    char file_b[0x100];
    char name[0x100];
    char* dest = this->pad_05b4;
    dest[0] = 0;
    if (g_bazaarPc_guess != 0) {
        FUN_005749f0_guess(GetLanguageCodePage_guess(g_bazaarValue_guess),
                           g_bazaarPc_guess->text_003c_guess, name, 0x100);
        sprintf(dest, ".\\BZR_%s_", name);
        g_bazaarFiles_guess->GetServerShortName_guess(name);
        strcat(dest, name);
        strcat(dest, ".ini");

        FUN_005749f0_guess(GetLanguageCodePage_guess(g_bazaarValue_guess),
                           g_bazaarPc_guess->text_003c_guess, name, 0x100);
        sprintf(file_b, ".\\BZR_%s_", name);
        g_bazaarFiles_guess->FUN_00493ada_guess(name);
        strcat(file_b, name);
        strcat(file_b, ".ini");

        if (!FileExists_guess(dest)) {
            if (FileExists_guess(file_b)) {
                if (CopyFileA(file_b, dest, 1) != 0) {
                    FUN_00612662_guess(file_b);
                }
            }
        }
    }
}

// Set Price: gives the entered price to every slot with the selected item (same item ids, or same item
// and charges) and saves it to the INI (string 6751). False when the item is in no slot.
// FUNCTION: TITANIUM 0x004E5769
// @early-stop: budget, structural ndiff=63
char CBazaarWndView_guess::SetPriceForSelectedItem_guess() {
    SellItem_guess* selected = (SellItem_guess*)field_016c_guess;
    bool found = false;
    int total = ((CBazaarWndMoneyView_guess*)this)->GetTotalCopper_guess();
    SellItem_guess** slot = (SellItem_guess**)sell_items_02e4;
    for (int count = 0x50; count != 0; --count, ++slot) {
        SellItem_guess* item = *slot;
        if (item != 0 && selected != 0) {
            if (item->a_0080_guess != selected->a_0080_guess ||
                item->b_0084_guess != selected->b_0084_guess) {
                if (item->GetItemId_guess() != selected->GetItemId_guess() ||
                    item->c_0058_guess != selected->c_0058_guess) {
                    if (item->GetItemId_guess() != selected->GetItemId_guess() ||
                        selected->IsStackable_guess() == 0) {
                        continue;
                    }
                }
            }
            ((int*)slot)[0x50] = total;
            found = true;
        }
    }
    if (found) {
        char item_name[128];
        char message[256];
        if (ValidateItemType_guess(selected->GetItemType_guess(0)) &&
            selected->c_0058_guess > 0) {
            sprintf(item_name, "%s:%d", selected->GetName_guess(), selected->c_0058_guess);
        } else {
            CopyText_guess(item_name, selected->GetName_guess());
        }
        FormatText_guess(message, 0x1a5f, selected->GetName_guess(),
                         ((CBazaarWndMoneyView_guess*)this)->FormatMoneyText_guess(total),
                         0, 0, 0, 0, 0, 0, 0);
        AddBazaarText_guess(message, 10);
        sprintf(message, "%d", total);
        WriteSetting_guess("ItemToSell", item_name, message, pad_05b4);
        return 1;
    }
    return 0;
}

// Enables the buttons for the current state: Start/End always (one shown pressed), List in trader mode,
// Set Price with a selection, Clear with a price, then Add or Remove by whether the slot is listed.
// The null guard skips List (+0x180), which is then used unchecked.
// FUNCTION: TITANIUM 0x004E5907
void CBazaarWndMoneyView_guess::UpdatePriceButtons_guess() {
    if (this->setPriceButton_017c_guess == 0 || this->startButton_0170_guess == 0 ||
        this->clearButton_0178_guess == 0 || this->endButton_0174_guess == 0 ||
        this->removeButton_018c_guess == 0 || this->addButton_0188_guess == 0) {
        return;
    }

    this->addButton_0188_guess->Enabled = 0;
    this->removeButton_018c_guess->Enabled = 0;
    this->listButton_0180_guess->Enabled = 0;
    this->setPriceButton_017c_guess->Enabled = 0;
    this->clearButton_0178_guess->Enabled = 0;
    this->startButton_0170_guess->Enabled = 1;
    this->endButton_0174_guess->Enabled = 1;

    if (this->flag_05f4_guess != 0) {
        this->endButton_0174_guess->SetPressed_guess(1, 1);
        this->startButton_0170_guess->SetPressed_guess(0, 1);
        this->listButton_0180_guess->Enabled = 1;
    } else {
        this->endButton_0174_guess->SetPressed_guess(0, 1);
        this->startButton_0170_guess->SetPressed_guess(1, 1);
    }

    if (this->field_016c_guess != 0) {
        this->setPriceButton_017c_guess->Enabled = 1;
    }

    if (this->GetTotalCopper_guess() != 0) {
        this->clearButton_0178_guess->Enabled = 1;
        if (this->flag_05f4_guess != 0) {
            if (this->flags_0564_guess[this->selected_slot_015c_guess] != 0) {
                this->removeButton_018c_guess->Enabled = 1;
            } else {
                this->addButton_0188_guess->Enabled = 1;
            }
        }
    }
}

// Selects slot `value`: bazaar slot ids are 7000-7079. Picks the first slot with the same item and loads
// its price; anything else clears the selection.
// FUNCTION: TITANIUM 0x004E5A35
void CBazaarWndMoneyView_guess::SetSelected_guess(int value, int unused_guess) {
    selected_slot_015c_guess = value;
    field_016c_guess = 0;
    if (value < 7000 || value > 0x1ba8) {
        return;
    }
    int index = value - 7000;
    selected_slot_015c_guess = index;
    SellItem_guess* item = 0;
    if (index >= 0 && index < 0x50) {
        item = sell_items_02e4[index];
        field_016c_guess = item;
    }
    if (item != 0) {
        money_0164_guess = 0;
        for (int i = 0; i < 0x50; ++i) {
            SellItem_guess* cur = sell_items_02e4[i];
            if (cur == 0) {
                continue;
            }
            if (cur->a_0080_guess != item->a_0080_guess ||
                cur->b_0084_guess != item->b_0084_guess) {
                if (cur->GetItemId_guess() != item->GetItemId_guess() ||
                    sell_items_02e4[i]->c_0058_guess != item->c_0058_guess) {
                    continue;
                }
            }
            selected_slot_015c_guess = i;
            money_0164_guess = values_0424[i];
            break;
        }
    } else {
        selected_slot_015c_guess = -1;
        money_0164_guess = 0;
    }
    UpdateMoney_guess();
    UpdatePriceButtons_guess();
}


struct LookupRoot_guess {
    union {
        struct {
            int unknown_0000_guess;
            int unknown_0004_guess;
            VBTable* holder_0008_guess;
        };
        unsigned char bytes_0000_guess[0x400];
    };
};

struct RankNode_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int flag);
    // EXTERNAL: TITANIUM 0x005E0F30 RankNode_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 RankNode_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 RankNode_guess::GetEntry_guess
    RankNode_guess* GetEntry_guess(int index);
    // EXTERNAL: TITANIUM 0x005E06A0 RankNode_guess::TestFlag_guess
    int TestFlag_guess(int flag);
};

struct RankEntry_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int flag);
};

struct IndexedAccess_guess {
    int unknown_0000_guess;
    int context_0004_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 IndexedAccess_guess::GetFirst_guess
    RankNode_guess* GetFirst_guess(int index);
};

#define g_lookupRoot_guess EQ_GLOBAL(LookupRoot_guess*, 0x00905D00)
#define g_sellEnabled_guess EQ_GLOBAL(int, 0x00923D5C)

struct FlagsBlock_guess {
    unsigned char bytes[0x50];
};

struct ItemsBlock_guess {
    Item_guess* items[0x50];
};

struct ValuesBlock_guess {
    int values[0x50];
};

struct BazaarMessage_guess {
    int type_guess;
    int field_04_guess;
    int field_08_guess;
    int field_0c_guess;
    int field_10_guess;
    int field_14_guess;
};

// Rescans the satchels after an inventory change and keeps price and listed flag for items still there.
// In trader mode with `param_2`, items that left are taken off the list (action 3, price 0).
// FUNCTION: TITANIUM 0x004E6109
// @early-stop: budget, structural ndiff=59
void SellWindow_guess::UpdateSellItems_guess(char param_2) {
    int count = 0;
    FlagsBlock_guess saved_flags = *(FlagsBlock_guess*)this->flags_0564;
    ItemsBlock_guess saved_items = *(ItemsBlock_guess*)this->items_02e4;
    ValuesBlock_guess saved_values = *(ValuesBlock_guess*)this->values_0424;

    for (int i = 0; i < 0x50; ++i) {
        this->items_02e4[i] = 0;
        this->values_0424[i] = 0;
        this->flags_0564[i] = 0;
    }

    for (int level = 0x16; level < 0x1e; ++level) {
        if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                 g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                ->GetFirst_guess(level) != 0) {
            if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                     g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                    ->GetFirst_guess(level)
                    ->GetItemId_guess() == 0x45eb) {
                for (int index = 0;
                     index < ((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                  g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                  ->GetFirst_guess(level)
                                  ->GetCount_guess();
                     ++index) {
                    if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                             g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                            ->GetFirst_guess(level)
                            ->GetEntry_guess(index) != 0) {
                        if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                 g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                ->GetFirst_guess(level)
                                ->GetEntry_guess(index) != 0) {
                            if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                     g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                        ->GetFirst_guess(level)
                                        ->GetEntry_guess(index)
                                        ->TestFlag_guess(1) != 0 ||
                                (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                      g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                      ->GetFirst_guess(level)
                                      ->GetEntry_guess(index)
                                      ->Slot04_guess(0) != 0 &&
                                 g_sellEnabled_guess != 0)) {
                                this->SetItemToSell_guess(
                                    (Item_guess*)((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                                       g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                        ->GetFirst_guess(level)
                                        ->GetEntry_guess(index),
                                    count, 0);
                                ++count;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int outer = 0; outer < 0x50; ++outer) {
        for (count = 0; count < 0x50; ++count) {
            if (this->items_02e4[outer] == saved_items.items[count]) {
                this->values_0424[outer] = saved_values.values[count];
                this->flags_0564[outer] = saved_flags.bytes[count];
                this->UpdateItemColors_guess((int)this->items_02e4[outer],
                                             saved_flags.bytes[count]);
                saved_items.items[count] = 0;
            }
        }
    }

    if (this->flag_05f4 != 0 && param_2 != 0) {
        for (int i = 0; i < 0x50; ++i) {
            Item_guess* item = saved_items.items[i];
            if (item != 0 && this->flag_05f4 != 0) {
                BazaarMessage_guess message;
                message.type_guess = 3;
                message.field_08_guess = ((SellItem_guess*)item)->a_0080_guess;
                message.field_0c_guess = ((SellItem_guess*)item)->b_0084_guess;
                message.field_10_guess = 0;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, &message, 0x18, 1);
            }
        }
    }
}

// Fills the slots from every Trader's Satchel in bags 22-29 and reports: 6746 ("%1 items were found")
// and 6747, or 6748 (satchels but no items) / 6749 (no satchel).
// FUNCTION: TITANIUM 0x004E63BD
// @early-stop: budget, structural ndiff=25
void SellWindow_guess::LoadSellItems_guess() {
    int count = 0;
    int found_kind = 0;
    char message[260];

    if (g_lookupRoot_guess != 0) {
        for (int level = 0x16; level < 0x1e; ++level) {
            if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                     g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                    ->GetFirst_guess(level) != 0) {
                if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                         g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                        ->GetFirst_guess(level)
                        ->GetItemId_guess() == 0x45eb) {
                    found_kind = 1;
                    for (int index = 0;
                         index < ((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                      g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                      ->GetFirst_guess(level)
                                      ->GetCount_guess();
                         ++index) {
                        if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                 g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                ->GetFirst_guess(level)
                                ->GetEntry_guess(index) != 0) {
                            if (((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                     g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                    ->GetFirst_guess(level)
                                    ->GetEntry_guess(index)
                                    ->TestFlag_guess(1) == 0) {
                                char enabled = ((RankEntry_guess*)((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                                    g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                                    ->GetFirst_guess(level)
                                                    ->GetEntry_guess(index))
                                                   ->Slot04_guess(0);
                                if (enabled == 0 || g_sellEnabled_guess == 0) {
                                    continue;
                                }
                            }
                            this->SetItemToSell_guess(
                                (Item_guess*)((IndexedAccess_guess*)&g_lookupRoot_guess->bytes_0000_guess[
                                                  g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8])
                                    ->GetFirst_guess(level)
                                    ->GetEntry_guess(index),
                                count, 0);
                            ++count;
                        }
                    }
                }
            }
        }

        char* text;
        if (count != 0) {
            FormatText_guess(message, 0x1a5a,
                             _itoa(count, EQ_ARRAY(char, 0x0099DB00), 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
            this->AddBazaarText_guess(message, 10);
            text = pStringTable->getString(0x1a5b, 0);
        } else {
            CopyText_guess(message, pStringTable->getString(found_kind ? 0x1a5c : 0x1a5d, 0));
            text = message;
        }
        this->AddBazaarText_guess(text, 10);
    }
}

// Sets one coin field and recomputes the price, capped at 1,000,000,000 copper (1,000,000 platinum).
// FUNCTION: TITANIUM 0x004E5B31
void CBazaarWndMoneyView_guess::SetFieldMoney_guess(int index, int value) {
    char text[32];
    sprintf(text, "%d", value);
    {
        CXStr str(text);
        fields_0190_guess[index]->SetText_guess(str);
    }

    int total = GetTotalCopper_guess();
    money_0164_guess = total;
    if (total > 1000000000) {
        money_0164_guess = 1000000000;
    }
    UpdateMoney_guess();
}

struct Bounds_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9160 Bounds_guess::CopyTo_guess
    void CopyTo_guess(Bounds_guess& destination, const CXPoint& source);
    // EXTERNAL: TITANIUM 0x004DC02D Bounds_guess::CenterPoint
    void CenterPoint(CXPoint* point);
};


// A coin field was clicked (`value` -1): opens the quantity slider (0x850C3C) at the field, max 1,000,000
// for platinum, else 100. The slider's answer (notification 0x1F) comes back with the amount.
// FUNCTION: TITANIUM 0x004E5BD4
// @early-stop: unknown, structural ndiff=7
void CBazaarWndMoneyView_guess::ClickedMoneyButton_guess(int index, int value) {
    int scale = 100;
    Bounds_guess bounds;
    bounds.bottom_guess = 0;
    bounds.right_guess = 0;
    bounds.top_guess = 0;
    bounds.left_guess = 0;
    if (field_016c_guess != 0) {
        if (value > -1) {
            SetFieldMoney_guess(index, value);
        } else {
            if (index == 0) {
                scale = 1000000;
            }
            field_0168_guess = index;
            int money = GetQtyFromCoinType_guess(index);
            Bounds_guess copy;
            bounds.CopyTo_guess(copy, fields_0190_guess[index]->Slot57_guess());
            CXPoint point;
            bounds.CenterPoint(&point);
            pinstCQuantityWnd_guess->Function_0054d976_guess(this, scale, money, point.x, point.y, 1);
        }
        UpdatePriceButtons_guess();
    }
}

// Buttons: Set Price (6753 when the item isn't listed yet), Add and Remove (OP_Trader action 3 with the
// price or 0), Start (6743 / 6754 on failure), List (action 11), Clear, End (action 2). Notification 0x1F
// is the quantity slider's result for a coin field.
// FUNCTION: TITANIUM 0x004E5C84
// @early-stop: budget, structural ndiff=143
int CBazaarWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    CXWnd* current_sender = sender;
    unsigned int current_message = message;
    int msg[6];
    if (current_message == 1) {
        if (current_sender == setPriceButton_17c) {
            int total = ((CBazaarWndMoneyView_guess*)this)->GetTotalCopper_guess();
            if (selected_slot_015c_guess != -1 && SetPriceForSelectedItem_guess() != 0 && field_5f4 != 0) {
                int slot = selected_slot_015c_guess;
                if (flags_0564[slot] == 0) {
                    if (field_5f4 != 0) {
                        AddBazaarText_guess(pStringTable->getString(0x1a61, 0), 0xf);
                    }
                } else {
                    SellItem_guess* trade = (SellItem_guess*)field_016c_guess;
                    msg[4] = total;
                    msg[2] = trade->a_0080_guess;
                    msg[3] = trade->b_0084_guess;
                    msg[0] = 3;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, msg, 0x18, 1);
                    AddBazaarText_guess(pStringTable->getString(0x1a60, 0), 0xf);
                }
            }
        } else if (current_sender == addButton_188) {
            int total = ((CBazaarWndMoneyView_guess*)this)->GetTotalCopper_guess();
            if (total != 0 && field_016c_guess != 0 && field_5f4 != 0) {
                SellItem_guess* trade = (SellItem_guess*)field_016c_guess;
                msg[4] = total;
                msg[2] = trade->a_0080_guess;
                msg[3] = trade->b_0084_guess;
                msg[0] = 3;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, msg, 0x18, 1);
            }
        } else if (current_sender == removeButton_18c) {
            SellItem_guess* trade = (SellItem_guess*)field_016c_guess;
            if (trade != 0 && field_5f4 != 0) {
                msg[4] = 0;
                msg[2] = trade->a_0080_guess;
                msg[3] = trade->b_0084_guess;
                msg[0] = 3;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, msg, 0x18, 1);
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 0);
            }
        } else if (current_sender == startButton_170) {
            int text_id;
            int price = StartTraderMode_guess();
            if (price == -1) {
                text_id = 0x1a57;
            } else if (price == -2) {
                text_id = 0x1a62;
            } else {
                return 0;
            }
            AddBazaarText_guess(pStringTable->getString(text_id, 0), 0xf);
            return 0;
        } else if (current_sender == listButton_180) {
            if (field_5f4 == 0) {
                return 0;
            }
            memset(&msg[1], 0, 0x14);
            msg[1] = 0xb;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, &msg[1], 0x14, 1);
            return 0;
        } else if (current_sender == clearButton_178) {
            money_0164_guess = 0;
            ((CBazaarWndMoneyView_guess*)this)->UpdateMoney_guess();
            if (selected_slot_015c_guess != -1 && SetPriceForSelectedItem_guess() != 0 && field_5f4 != 0) {
                SellItem_guess* trade = (SellItem_guess*)field_016c_guess;
                msg[4] = 0;
                msg[2] = trade->a_0080_guess;
                msg[3] = trade->b_0084_guess;
                msg[0] = 3;
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, msg, 0x18, 1);
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 0);
            }
        } else if (current_sender == endButton_174) {
            memset(&msg[1], 0, 0x14);
            msg[1] = 2;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, &msg[1], 0x14, 1);
            g_resumeTraderMode_guess = 0;
            int* cell = (int*)flags_0564;
            for (int i = 0x14; i != 0; --i) {
                *cell++ = 0;
            }
            ((SellWindow_guess*)this)->UpdateItemColors_guess(0, 0);
            return 0;
        } else {
            for (int i = 0; i < 4; ++i) {
                if (current_sender == money_190[i]) {
                    ClickedMoneyButton_guess(i, -1);
                    return 0;
                }
            }
            return ((CSidlScreenWnd*)this)->WndNotification(current_sender, current_message, data);
        }
        ((CBazaarWndMoneyView_guess*)this)->UpdatePriceButtons_guess();
        return 0;
    }
    if (current_message != 3 && current_message == 0x1f && field_0168_guess != -1) {
        ClickedMoneyButton_guess(field_0168_guess, *(int*)data);
        field_0168_guess = -1;
        return 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(current_sender, current_message, data);
}

// Empties all 80 slots and the selection; the log keeps 100 lines.
// FUNCTION: TITANIUM 0x004E5FBD
void CBazaarWndView_guess::Init_guess() {
    int color1 = pinstCChatManager_guess->GetRGBAFromIndex(0xc);
    int color2 = pinstCChatManager_guess->GetRGBAFromIndex(0xa);
    ((BazaarText_guess*)this->bazaarText_1a0)->line_count_01c0_guess = 100;
    this->BuildIniPath_guess();
    for (int i = 0; i < 0x50; ++i) {
        this->sell_items_02e4[i] = 0;
        this->values_0424[i] = 0;
        this->flags_0564[i] = 0;
        Item_guess* slot = (Item_guess*)this->slots_1a4[i];
        slot->color_154 = color1;
        slot->color_150 = color2;
    }
    this->money_0164_guess = 0;
    this->selected_slot_015c_guess = -1;
    this->field_0168_guess = -1;
    this->field_016c_guess = 0;
}

// The satchel item with item id `value`, or 0.
// FUNCTION: TITANIUM 0x004E604B
RankNode_guess* CBazaarWndView_guess::FindTraderSatchelItem_guess(int value) {
    if (g_lookupRoot_guess != 0) {
        for (int level = 0x16; level < 0x1e; ++level) {
            if (reinterpret_cast<IndexedAccess_guess*>(
                    reinterpret_cast<char*>(g_lookupRoot_guess) +
                    g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8)
                    ->GetFirst_guess(level) != 0) {
                if (reinterpret_cast<IndexedAccess_guess*>(
                        reinterpret_cast<char*>(g_lookupRoot_guess) +
                        g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8)
                        ->GetFirst_guess(level)
                        ->GetItemId_guess() == 0x45eb) {
                    RankNode_guess* node = reinterpret_cast<IndexedAccess_guess*>(
                        reinterpret_cast<char*>(g_lookupRoot_guess) +
                        g_lookupRoot_guess->holder_0008_guess->vbase_offset + 8)
                        ->GetFirst_guess(level);
                    for (int index = 0; index < node->GetCount_guess(); ++index) {
                        if (node->GetEntry_guess(index) != 0) {
                            if (node->GetEntry_guess(index)->GetItemId_guess() == value) {
                                return node->GetEntry_guess(index);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

struct GateState_guess {
    // EXTERNAL: TITANIUM 0x005F6D00 GateState_guess::Check_guess
    char Check_guess(unsigned int value);
};

struct EverQuestState_guess {
    // EXTERNAL: TITANIUM 0x00494C09 EverQuestState_guess::IsOkToTransact_guess
    char IsOkToTransact_guess();
};

#define g_gate_guess EQ_GLOBAL(GateState_guess*, 0x00905CC0)
#define g_everQuestState_guess EQ_GLOBAL(EverQuestState_guess*, 0x00988DF0)

// Opens only in game: clears the log, prints the welcome (6750), loads the satchels and restarts trader
// mode if it was on when the window last closed.
// FUNCTION: TITANIUM 0x004E65E3
char CBazaarWndView_guess::Activate_guess() {
    if (g_gate_guess->Check_guess(EQ_GLOBAL(unsigned int, 0x00924470)) != 0) {
        if (g_everQuestState_guess->IsOkToTransact_guess() != 0) {
            {
                CXStr text(EQ_ARRAY(char, 0x0063FE10));
                this->bazaarText_1a0->SetWindowTextA(text);
            }
            this->Init_guess();
            ((CBazaarWndMoneyView_guess*)this)->UpdateMoney_guess();
            ((CBazaarWndMoneyView_guess*)this)->UpdatePriceButtons_guess();
            this->AddBazaarText_guess(pStringTable->getString(0x1a5e, 0), 10);
            this->FUN_004e63bd_guess();
            pinstCInvSlotMgr_guess->SetSelection_guess(0);
            if (g_resumeTraderMode_guess != 0) {
                this->StartTraderMode_guess();
                g_resumeTraderMode_guess = 0;
            }
            return 1;
        }
    }
    return 0;
}

/* ---- CBazaarWnd::CBazaarWnd(CXWnd*) (0x004E66C2) ----------------------------------------------------
 * Layout: include/titanium/types.h CBazaarWnd (0x5F8). */

// Binds BZR_BazaarSlot0..79 and the BZW_ buttons, money fields and log.
// FUNCTION: TITANIUM 0x004E66C2
CBazaarWndView_guess::CBazaarWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "BazaarWnd") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        char name[0x20];
        for (int i = 0; i < 80; ++i) {
            sprintf(name, "BZR_BazaarSlot%d", i);
            slots_1a4[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        CXWnd* slotsWnd = ((CSidlScreenWnd*)this)->GetChildItem("BZW_BazaarSlotsWnd");
        slotsWnd->WindowStyle &= ~0x800;
        slotsWnd->Fades = 0;
        setPriceButton_17c = ((CSidlScreenWnd*)this)->GetChildItem("BZW_SetPrice_Button");
        startButton_170 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Start_Button");
        endButton_174 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_End_Button");
        clearButton_178 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Clear_Button");
        listButton_180 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_List_Button");
        bazaarText_1a0 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_BazaarText");
        removeButton_18c = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Remove_Button");
        addButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Add_Button");
        money_190[0] = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Money0");
        money_190[1] = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Money1");
        money_190[2] = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Money2");
        money_190[3] = ((CSidlScreenWnd*)this)->GetChildItem("BZW_Money3");
        field_5f4 = 0;
        Init_guess();
    }
}

struct CharSecond_guess {
    char pad_0000[0xc280];
    unsigned char field_c280_guess;
};

#define g_charSecond_guess EQ_GLOBAL(CharSecond_guess*, 0x00905D00)

struct Notifier_guess {
    // EXTERNAL: TITANIUM 0x0044A537 Notifier_guess::WavePlay_guess
    void WavePlay_guess(int first, int second);
};

#define g_notifier_guess EQ_GLOBAL(Notifier_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
int __cdecl FUN_00401b28_guess(int value);
// EXTERNAL: TITANIUM 0x004649D5 text_to_client_guess
void __cdecl text_to_client_guess(void* target, const char* text, int value);

// OP_Trader from the server. 1: start answer (6742 ON, then asks for the list; else 6743). 2: mode off
// (6741, also to chat). 3: price change result 0-3 (6733-6736). 10: a buyer bought an item (6744: buyer,
// quantity, item, price; sound 138). 11: the list as the server has it (6737-6740). 13: someone browsing.
// FUNCTION: TITANIUM 0x004E6A81
// @early-stop: budget, structural ndiff=79
void CBazaarWndView_guess::HandleMessage_guess(int* message) {
    int msg[5];
    int* entry;
    int count;
    int local_110;
    int index;
    int* price_slot;
    char buffer[256];

    switch (message[0]) {
    case 1:
        if (message[1] != 0) {
            memset(msg, 0, 0x14);
            AddBazaarText_guess(pStringTable->getString(0x1a56, 0), 0xd);
            field_5f4 = 1;
            ((SellWindow_guess*)this)->UpdateItemColors_guess(0, 1);
            ((CBazaarWndMoneyView_guess*)this)->UpdatePriceButtons_guess();
            msg[0] = 0xb;
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Trader, msg, 0x14, 1);
            return;
        }
        AddBazaarText_guess(pStringTable->getString(0x1a57, 0), 0xd);
        break;
    case 2: {
        AddBazaarText_guess(pStringTable->getString(0x1a55, 0), 0xd);
        CharSecond_guess* charData = g_charSecond_guess;
        text_to_client_guess(charData != 0 ? &charData->field_c280_guess : 0,
                           pStringTable->getString(0x1a55, 0), 0xf);
        field_5f4 = 0;
        ((CBazaarWndMoneyView_guess*)this)->UpdatePriceButtons_guess();
        for (int i = 0; i < 0x14; ++i) {
            ((int*)flags_0564)[i] = 0;
        }
        ((SellWindow_guess*)this)->UpdateItemColors_guess(0, 0);
        return;
    }
    case 3:
        if (field_016c_guess != 0) {
            switch (message[1]) {
            case 0:
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 0);
                AddBazaarText_guess(pStringTable->getString(0x1a4d, 0), 0xf);
                break;
            case 1:
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 1);
                FormatText_guess(buffer, 0x1a4e,
                                 ((Item_guess*)field_016c_guess)->GetName_guess(),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                AddBazaarText_guess(buffer, 0xf);
                break;
            case 2:
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 0);
                FormatText_guess(buffer, 0x1a4f,
                                 ((Item_guess*)field_016c_guess)->GetName_guess(),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                AddBazaarText_guess(buffer, 0xf);
                break;
            case 3:
                ((SellWindow_guess*)this)->UpdateItemColors_guess(field_016c_guess, 1);
                FormatText_guess(buffer, 0x1a50,
                                 ((Item_guess*)field_016c_guess)->GetName_guess(),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                AddBazaarText_guess(buffer, 0xf);
                break;
            }
        }
        break;
    case 10:
        local_110 = FUN_00401b28_guess(message[2]);
        if (local_110 != 0) {
            FormatText_guess(buffer, 0x1a58,
                             ((Item_guess*)local_110)->name_0120_guess,
                             _itoa(message[0x16], EQ_ARRAY(char, 0x0099DAE0), 10),
                             (const char*)&message[3],
                             ((CBazaarWndMoneyView_guess*)this)->FormatMoneyText_guess(message[1]),
                             0, 0, 0, 0, 0);
            AddBazaarText_guess(buffer, 0xf);
            g_notifier_guess->WavePlay_guess(0x8a, 0);
        }
        ((SellWindow_guess*)this)->UpdateSellItems_guess(0);
        return;
    case 11:
        AddBazaarText_guess(pStringTable->getString(0x1a51, 0), 0xf);
        entry = message + 2;
        price_slot = message + 0xa2;
        count = 0x50;
        index = 1;
        do {
            if (entry[0] != 0 || entry[1] != 0) {
                RankNode_guess* node = FindTraderSatchelItem_guess(entry[0]);
                if (node == 0) {
                    FormatText_guess(buffer, 0x1a53,
                                     _itoa(index, EQ_ARRAY(char, 0x0099DB00), 10),
                                     0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatText_guess(buffer, 0x1a52,
                                     _itoa(index, EQ_ARRAY(char, 0x0099DB00), 10),
                                     ((Item_guess*)node)->GetName_guess(),
                                     ((CBazaarWndMoneyView_guess*)this)->FormatMoneyText_guess(*price_slot),
                                     0, 0, 0, 0, 0, 0);
                }
                AddBazaarText_guess(buffer, 10);
            }
            ++price_slot;
            entry += 2;
            ++index;
            --count;
        } while (count != 0);
        AddBazaarText_guess(pStringTable->getString(0x1a54, 0), 10);
        return;
    case 13:
        local_110 = FUN_00401b28_guess(message[1]);
        if (local_110 == 0) {
            return;
        }
        FormatText_guess(buffer, 0x1a59,
                         ((Item_guess*)local_110)->name_0120_guess,
                         0, 0, 0, 0, 0, 0, 0, 0);
        AddBazaarText_guess(buffer, 0xf);
        return;
    default:
        return;
    }
    ((CBazaarWndMoneyView_guess*)this)->UpdatePriceButtons_guess();
}
