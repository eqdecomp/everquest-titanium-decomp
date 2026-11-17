// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 232: a hint from compare/tumap.py.
// The trade window (TradeWnd; CTradeWnd in types.h, 0x238 bytes, viewed here as CTradeWndView_guess): 8 slots
// each side (my slots 3000-3007, the partner's 3008-3015), four coin boxes each, Trade and Cancel. The
// partner
// spawn is 0x905CE0 (an NPC when its +0x244 is 1, which allows only 4 slots); each name turns green once
// that side has pressed Trade.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CGiveWnd.h"
#include "titanium/wnd/CInventoryWnd.h"

union Dword_guess {
    int value_guess;
    struct {
        unsigned char b0_guess;
        unsigned char b1_guess;
        unsigned char b2_guess;
        unsigned char b3_guess;
    } bytes_guess;
};

struct Msg_guess {
    int value_guess;
    unsigned char flag_guess;
};

struct State_guess;

struct CTradeWndView_guess {
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

    char pad_0004_guess[0x58];
    unsigned char state_005c_guess; // 0x5c
    char pad_005d_guess[5];
    unsigned char state_0062_guess; // 0x62
    char pad_0063_guess[0xf9];
    unsigned int tick_015c_guess; // 0x15c
    unsigned char state_0160_guess; // 0x160
    char pad_0161_guess[3];
    CXWnd* hisMoney_164_guess[4]; // 0x164
    CXWnd* moneyButtons_174_guess[4]; // 0x174
    CXWnd* tradeButton_184_guess; // 0x184
    CXWnd* cancelButton_188_guess; // 0x188
    CXWnd* hisName_18c_guess; // 0x18c
    CXWnd* myName_190_guess; // 0x190
    struct Entry_guess* entries_guess[16]; // 0x194
    int pair_guess[8]; // 0x1d4
    int block_guess[16]; // 0x1f4
    unsigned char flag1_guess; // 0x234
    unsigned char flag2_guess; // 0x235
    unsigned char flag3_guess; // 0x236

    void Clear_guess();
    void ResetConnection_guess();
    void Deactivate_guess();
    void OnShow_guess();
    int PostDraw_guess();
    void ClickedCancelButton_guess();
    void CompleteTrade_guess();
    void SetMyReadyTrade_guess(unsigned char value_guess);
    void SetHisReadyTrade_guess(unsigned char value_guess);
    void SetHisMoney_guess(int index_guess, int value_guess);
    void OnProcessFrame_guess();
    void ClickedTradeButton_guess();
    void ClickedMoneyButton_guess(int param_guess);
    char IsMyTradeSlot_guess(int value_guess, unsigned char* flag_guess);
    void TradeItemChanged_guess(Dword_guess param_guess, int second_guess);
    int AddEqItemToHisTradeArray_guess(struct Child_guess* param_guess);

    void UpdateTradeDisplay_guess();

    void Activate_guess(State_guess* state_guess, unsigned char flag_guess);

    void DropItemIntoTrade_guess();

    void DropMoneyIntoTrade_guess();

    // EXTERNAL: TITANIUM 0x005A2230 CTradeWndView_guess::WndNotification
    int WndNotification(CXWnd* control_guess, unsigned int message_guess, void* data_guess);

    int WndNotification_guess(CXWnd* control_guess, int message_guess, void* data_guess);

    // EXTERNAL: TITANIUM 0x005A1880 CTradeWndView_guess::OnShow
    void OnShow();
};

struct CleanupState_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 CleanupState_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005DFCC0 CleanupState_guess::Ready_guess
    char Ready_guess();
};

struct Child_guess {
    virtual ~Child_guess();
    char pad_004_guess[0x48];
    int index_guess; // 0x4c

    // EXTERNAL: TITANIUM 0x005E0F30 Child_guess::GetItemId_guess
    int GetItemId_guess();
};

struct Backend_guess {
    // EXTERNAL: TITANIUM 0x004FAA17 Backend_guess::CloseContainer_guess
    void CloseContainer_guess(int value_guess, int mode_guess);
};

struct State_guess {
    char pad_0000_guess[0x120];
    char text_0120_guess[0x118]; // 0x120 (text buffer, passed to 0x00492EC2)
    float field_238_guess; // 0x238
    char pad_023c_guess[0x244 - 0x23c];
    unsigned char flag_0244_guess; // 0x244
    char pad_0245_guess[0x258 - 0x245];
    int value_guess; // 0x258
};

struct Display_guess {
    char pad_0000_guess[0x10];
    unsigned char state_0010_guess; // 0x10
    unsigned char mode_guess; // 0x11
    char pad_0012_guess[0x148 - 0x12];
    unsigned int tick_0148_guess; // 0x148

    // EXTERNAL: TITANIUM 0x00439D16 Display_guess::PlayerDistance_guess
    float PlayerDistance_guess(State_guess* a_guess, State_guess* b_guess, float c_guess);
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

struct Text_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;

    // EXTERNAL: TITANIUM 0x004D9160 Text_guess::Transform_guess
    Text_guess Transform_guess(const Text_guess& value_guess);
};

struct Resource_guess {
    char pad_0000_guess[0x10];
    int* value_guess; // 0x10
};

struct Entry_guess {
    char pad_0000_guess[0x140];
    Resource_guess* resource_guess; // 0x140

    // EXTERNAL: TITANIUM 0x0059FEC0 Entry_guess::IsReallyVisible
    char IsReallyVisible();
    // EXTERNAL: TITANIUM 0x0059D960 Entry_guess::GetScreenRect
    Text_guess GetScreenRect();
    // EXTERNAL: TITANIUM 0x005A02F0 Entry_guess::Submit_guess
    void Submit_guess(int* values_guess);
};

struct Queue_guess {
    // EXTERNAL: TITANIUM 0x004A1350 Queue_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int third_guess);
};

#define g_stateA_guess EQ_GLOBAL(State_guess*, 0x00905ce0)
#define g_stateB_guess EQ_GLOBAL(State_guess*, 0x00905ce4)
#define pinstCContainerMgr_guess EQ_GLOBAL(Backend_guess*, 0x00850cbc)
#define g_queue_guess EQ_GLOBAL(Queue_guess*, 0x00988df0)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099d3ec)
#define g_prevState_guess EQ_GLOBAL(State_guess*, 0x00905d04)

struct Holder_guess {
    char pad_0000_guess[0xf0];
    int field_f0_guess; // 0xf0
};

// EXTERNAL: TITANIUM 0x004C94AE FUN_004c94ae_guess
Holder_guess* __cdecl FUN_004c94ae_guess();

// Empties the 16 slot pointers and both money rows, and clears both accept flags.
// FUNCTION: TITANIUM 0x00569552
void CTradeWndView_guess::Clear_guess()
{
    int* p = &block_guess[0];
    for (int i = 16; i != 0; --i) {
        *p = 0;
        ++p;
    }

    int* q = &pair_guess[4];
    int count = 4;
    do {
        q[-4] = 0;
        *q = 0;
        ++q;
        --count;
    } while (count != 0);

    flag2_guess = 0;
    flag1_guess = 0;
}

// Sends OP_CancelTrade (partner id, my id) while a partner is set, frees every slot item (removing ones still
// held by the item manager), clears the window state and forgets the partner.
// FUNCTION: TITANIUM 0x00569588
void CTradeWndView_guess::ResetConnection_guess()
{
    if (g_stateA_guess != 0) {
        int data_guess[2];
        data_guess[0] = g_stateA_guess->value_guess;
        data_guess[1] = g_stateB_guess->value_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_CancelTrade, data_guess, 8, 1);
    }

    int* p_guess = &block_guess[0];
    int count_guess = 16;
    do {
        if (*p_guess != 0) {
            if (((CleanupState_guess*)*p_guess)->GetItemClass_guess() == 1) {
                if (((CleanupState_guess*)*p_guess)->Ready_guess() != 0) {
                    pinstCContainerMgr_guess->CloseContainer_guess(*p_guess, 1);
                }
            }
            delete (Child_guess*)*p_guess;
        }
        *p_guess = 0;
        ++p_guess;
        --count_guess;
    } while (count_guess != 0);
    Clear_guess();
    EQ_GLOBAL(int, 0x009248d4) = 0;
    g_stateA_guess = 0;
    flag3_guess = 0;
}

// Closes the window (Show(0)), or, while the give window (0x850C60) is showing, closes that one instead;
// then resets.
// FUNCTION: TITANIUM 0x00569639
void CTradeWndView_guess::Deactivate_guess()
{
    if (pinstCGiveWnd_guess->dShow != 0) {
        pinstCGiveWnd_guess->Deactivate();
    } else {
        Slot48_guess(0, 1);
    }
    ResetConnection_guess();
}

// OnShow (vtable slot 35). On show: context tip 0x15 in the tip window (0x9928E0). On hide: closes the
// inventory window (0x850C34, Deactivate) unless it was already open when the trade started (+0x160).
// FUNCTION: TITANIUM 0x00569670
void CTradeWndView_guess::OnShow_guess()
{
    if (state_005c_guess != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x15, 0);
        }
    } else if (state_0160_guess == 0) {
        pinstCInventoryWnd_guess->Deactivate();
    }
    OnShow();
}

// Draws each loaded slot's item label just under its slot; slots on another row than the first get 20 more
// pixels. Only when display mask bits 0x0C are on.
// FUNCTION: TITANIUM 0x005696AC
int CTradeWndView_guess::PostDraw_guess()
{
    if ((pinstCXWndManager_guess->GetKeyboardFlags() & 0x0c) != 0) {
        char zero_guess = 0;
        if (state_0062_guess != zero_guess) {
            int first_guess = -1;
            int values_guess[2] = { zero_guess, zero_guess };
            Text_guess text_guess;
            text_guess.fourth_guess = zero_guess;
            text_guess.third_guess = zero_guess;
            text_guess.second_guess = zero_guess;
            text_guess.first_guess = zero_guess;
            Entry_guess** entry_guess = &entries_guess[0];
            int count_guess = 16;
            do {
                if (*entry_guess != (Entry_guess*)zero_guess && (*entry_guess)->IsReallyVisible() != zero_guess) {
                    Resource_guess* resource_guess = (*entry_guess)->resource_guess;
                    int* value_guess = resource_guess->value_guess;
                    int loaded_guess = value_guess != (int*)zero_guess ? *value_guess : zero_guess;
                    if (loaded_guess != zero_guess) {
                        text_guess.Transform_guess((*entry_guess)->GetScreenRect());
                        if (first_guess == -1) {
                            first_guess = text_guess.first_guess;
                        }
                        values_guess[0] = text_guess.third_guess - 5;
                        if (text_guess.first_guess == first_guess) {
                            values_guess[1] = text_guess.second_guess + 2;
                        } else {
                            values_guess[1] = text_guess.second_guess + 0x16;
                        }
                        (*entry_guess)->Submit_guess(values_guess);
                    }
                }
                ++entry_guess;
                --count_guess;
            } while (count_guess != 0);
        }
    }
    return 0;
}

// With a partner, asks the server to cancel (OP_CancelTrade); the window closes on its reply. Alone, closes
// now.
// FUNCTION: TITANIUM 0x00569773
void CTradeWndView_guess::ClickedCancelButton_guess()
{
    if (g_stateA_guess != 0) {
        int values_guess[2];
        values_guess[0] = g_stateA_guess->value_guess;
        values_guess[1] = g_stateB_guess->value_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_CancelTrade, values_guess, 8, 1);
        return;
    }
    Deactivate_guess();
}

// True for my trade slots and my trade bags (3000-3110, but not 3008-3015); `flag_guess` is set for the
// partner's slots (3008-3015 and 3111-3330).
// FUNCTION: TITANIUM 0x005697BB
char CTradeWndView_guess::IsMyTradeSlot_guess(int value_guess, unsigned char* flag_guess)
{
    if (flag_guess != 0) {
        *flag_guess = 0;
    }
    if ((value_guess >= 3000) && (value_guess <= 3330)) {
        if (((value_guess >= 3008) && (value_guess < 3016)) || (value_guess > 3110)) {
            if (flag_guess != 0) {
                *flag_guess = 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

// The trade went through: sets cursor mode 9, resets the queue and closes without sending a cancel.
// FUNCTION: TITANIUM 0x00569802
void CTradeWndView_guess::CompleteTrade_guess()
{
    EQ_GLOBAL(int, 0x00923d94) = 9;
    g_queue_guess->SavePC_guess(0, 1, 0x10);
    EQ_GLOBAL(int, 0x00905ce0) = 0;
    Deactivate_guess();
}

/* ---- CTradeWnd::CTradeWnd(CXWnd*) (0x0056982F) ------------------------------------------------------
 * Layout: include/titanium/types.h CTradeWnd (0x238); this file's CTradeWndView_guess functions view it. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065F2E8 ??_7CTradeWnd_guess@@6B@
struct CTradeWnd_guess : CSidlScreenWndBase {
    char pad_15c[8];
    CXWnd* hisMoney_164[4];                 // 0x164 TRDW_HisMoney0..3
    CXWnd* myMoney_174[4];                  // 0x174 TRDW_MyMoney0..3
    CXWnd* tradeButton_184;                 // 0x184 TRDW_Trade_Button
    CXWnd* cancelButton_188;                // 0x188 TRDW_Cancel_Button
    CXWnd* hisName_18c;                     // 0x18c TRDW_HisName
    CXWnd* myName_190;                      // 0x190 TRDW_MyName
    CXWnd* tradeSlots_194[16];              // 0x194 TRDW_TradeSlot0..15
    char pad_1d4[0x62];
    unsigned char field_236;                // 0x236
    char pad_237;
    CTradeWnd_guess(CXWnd* parent);
};

// Style 0x10000 is added to the SIDL style; children TRDW_HisMoney0-3, TRDW_MyMoney0-3, the two buttons,
// both names and TRDW_TradeSlot0-15.
// FUNCTION: TITANIUM 0x0056982F
CTradeWnd_guess::CTradeWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "TradeWnd") {
    hisName_18c = 0;
    myName_190 = 0;
    field_236 = 0;
    ((CTradeWndView_guess*)this)->Clear_guess();
    for (int i = 0; i < 16; ++i) {
        tradeSlots_194[i] = 0;
    }
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10000;
        field_158_guess = 0x15;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        int i;
        char name[0x200];
        for (i = 0; i < 4; ++i) {
            sprintf(name, "TRDW_HisMoney%d", i);
            hisMoney_164[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            sprintf(name, "TRDW_MyMoney%d", i);
            myMoney_174[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        tradeButton_184 = ((CSidlScreenWnd*)this)->GetChildItem("TRDW_Trade_Button");
        cancelButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("TRDW_Cancel_Button");
        hisName_18c = ((CSidlScreenWnd*)this)->GetChildItem("TRDW_HisName");
        myName_190 = ((CSidlScreenWnd*)this)->GetChildItem("TRDW_MyName");
        for (i = 0; i < 16; ++i) {
            sprintf(name, "TRDW_TradeSlot%d", i);
            tradeSlots_194[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        FUN_0059db90_guess(20);
    }
}

// Window view: slot 63 (0xFC) is SetWindowTextA; 0x7C is the text colour.
struct WindowView_guess {
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
    virtual void SetWindowTextA_guess(const CXStr& text_guess);
    char pad_004_guess[0x78];
    unsigned int color_007c_guess; // 0x7c
};

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestText_guess::trimName_guess
    char* trimName_guess(const char* text_guess);
};
#define g_everQuestText_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)

#include "titanium/layouts/core.h"

// pCharData: the pointer at +8 is read as a VBTable*.
struct CharRoot_guess {
    char bytes_00_guess[8];
    VBTable* ref_08_guess;
};

// EXTERNAL: TITANIUM 0x00507310 UpdateGiveDisplay_guess
void UpdateGiveDisplay_guess();

// Names: red (0xFFFF0000) until that side accepts, green after. Then the eight coin counts.
// FUNCTION: TITANIUM 0x00569B3C
// @early-stop: unknown, structural ndiff=53
void CTradeWndView_guess::UpdateTradeDisplay_guess()
{
    char zero_guess = 0;
    if (pinstCGiveWnd_guess->dShow != zero_guess) {
        UpdateGiveDisplay_guess();
        return;
    }
    if (g_stateA_guess != (State_guess*)zero_guess && hisName_18c_guess != (CXWnd*)zero_guess) {
        ((WindowView_guess*)hisName_18c_guess)->color_007c_guess = flag1_guess == zero_guess ? 0xffff0000 : 0xff00ff00;
        CXStr text_guess(g_everQuestText_guess->trimName_guess(g_stateA_guess->text_0120_guess));
        ((WindowView_guess*)hisName_18c_guess)->SetWindowTextA_guess(text_guess);
    }
    if (pCharData != (EQ_Character*)zero_guess && myName_190_guess != (CXWnd*)zero_guess) {
        ((WindowView_guess*)myName_190_guess)->color_007c_guess = flag2_guess == zero_guess ? 0xffff0000 : 0xff00ff00;
        CXStr text_guess(g_everQuestText_guess->trimName_guess(
            &((CharRoot_guess*)pCharData)->bytes_00_guess[((CharRoot_guess*)pCharData)->ref_08_guess->vbase_offset + 0x44]));
        ((WindowView_guess*)myName_190_guess)->SetWindowTextA_guess(text_guess);
    }
    int* slot_guess = (int*)hisMoney_164_guess;
    int remaining_guess = 4;
    do {
        char buf_guess[0x100];
        if (slot_guess[0] != zero_guess) {
            sprintf(buf_guess, "%d", slot_guess[0x1c]);
            CXStr text_guess(buf_guess);
            ((WindowView_guess*)slot_guess[0])->SetWindowTextA_guess(text_guess);
        }
        if (slot_guess[4] != zero_guess) {
            sprintf(buf_guess, "%d", slot_guess[0x20]);
            CXStr text_guess(buf_guess);
            ((WindowView_guess*)slot_guess[4])->SetWindowTextA_guess(text_guess);
        }
        ++slot_guess;
        --remaining_guess;
    } while (remaining_guess != 0);
}

// Trade window: sets your accept flag (+0x235) and redraws the names (green once accepted) and coins
// (0x00569B3C). The Trade button sets it; the partner clearing theirs clears it.
// FUNCTION: TITANIUM 0x00569D82
void CTradeWndView_guess::SetMyReadyTrade_guess(unsigned char value_guess)
{
    flag2_guess = value_guess;
    UpdateTradeDisplay_guess();
}

// The partner's accept flag. Clearing it clears mine too: any change to the trade resets both.
// FUNCTION: TITANIUM 0x00569D94
void CTradeWndView_guess::SetHisReadyTrade_guess(unsigned char value_guess)
{
    flag1_guess = value_guess;
    if (value_guess == 0) {
        SetMyReadyTrade_guess(0);
    } else {
        UpdateTradeDisplay_guess();
    }
}

// Sets one of the partner's coin counts and resets both accepts.
// FUNCTION: TITANIUM 0x00569DB3
void CTradeWndView_guess::SetHisMoney_guess(int index_guess, int value_guess)
{
    pair_guess[index_guess] = value_guess;
    SetHisReadyTrade_guess(0);
}

// Every 500 ms: cancels when the partner is more than 20 units beyond its +0x238 range, else redraws.
// FUNCTION: TITANIUM 0x00569DCC
void CTradeWndView_guess::OnProcessFrame_guess()
{
    if (flag3_guess != 0) {
        if (g_display_guess->tick_0148_guess >= tick_015c_guess) {
            tick_015c_guess = g_display_guess->tick_0148_guess + 500;
            if (g_stateA_guess != 0) {
                float level_guess = g_stateA_guess->field_238_guess;
                if (g_display_guess->PlayerDistance_guess(g_stateA_guess, g_stateB_guess, 1.0f) > level_guess + 20.0f) {
                    Deactivate_guess();
                } else {
                    UpdateTradeDisplay_guess();
                }
            }
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Trade button: marks me ready and sends OP_TradeAcceptClick (8 bytes: ready flag, partner id).
// FUNCTION: TITANIUM 0x00569E4E
void CTradeWndView_guess::ClickedTradeButton_guess()
{
    if (g_stateA_guess != 0 && flag2_guess == 0) {
        SetMyReadyTrade_guess(1);
        Msg_guess msg_guess;
        msg_guess.flag_guess = flag2_guess;
        msg_guess.value_guess = g_stateA_guess->value_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_TradeAcceptClick, (int*)&msg_guess, 8, 1);
    }
}

struct Actor_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int flag_guess);

    char pad_0004_guess[0x44];
    int field_0048_guess; // 0x48

    // EXTERNAL: TITANIUM 0x005EC760 Actor_guess::IsStackable_guess
    char IsStackable_guess();
};

// EXTERNAL: TITANIUM 0x00464D65 SwapCombine_guess
int __cdecl SwapCombine_guess(Actor_guess** owner_guess, int* slot_guess, int mode_guess, int id_guess);


struct CharInfoLead_guess {
    char pad_0000_guess[0x10];
};

struct CharInfoSub_guess {
    char pad_0000_guess[0x78];
    Actor_guess* field_78_guess;

    int Value78_guess() { return (int)field_78_guess; }
};

struct CharInfo_guess : CharInfoLead_guess, CharInfoSub_guess {
    char pad_008c_guess[0x11e4 - 0x8c];
    int cursorPlatinum_11e4_guess;
    int cursorGold_11e8_guess;
    int cursorSilver_11ec_guess;
    int cursorCopper_11f0_guess;
};

struct CharHead_guess {
    int pad_0_guess;
};

struct CharProfile_guess {
    // EXTERNAL: TITANIUM 0x005EC220 CharProfile_guess::GetCharInfo2
    CharInfo_guess* GetCharInfo2();
};

struct CharBase_guess : CharHead_guess, CharProfile_guess {
    int Value78_guess() { return GetCharInfo2()->CharInfoSub_guess::Value78_guess(); }
    int Field11e4_guess() { return GetCharInfo2()->cursorPlatinum_11e4_guess; }
    int Field11e8_guess() { return GetCharInfo2()->cursorGold_11e8_guess; }
    int Field11ec_guess() { return GetCharInfo2()->cursorSilver_11ec_guess; }
    int Field11f0_guess() { return GetCharInfo2()->cursorCopper_11f0_guess; }
    Actor_guess* ActorPointer_guess() { return GetCharInfo2()->CharInfoSub_guess::field_78_guess; }
    Actor_guess** ActorAddress_guess() { return &GetCharInfo2()->CharInfoSub_guess::field_78_guess; }
};

struct CharPrefix_guess {
    int pad_0_guess;
    int pad_4_guess;
};

struct CharView_guess : CharPrefix_guess, virtual CharBase_guess {
};

#define g_charView_guess EQ_GLOBAL(CharView_guess*, 0x00905D00)

struct Engine_guess {
    // EXTERNAL: TITANIUM 0x00495F81 Engine_guess::MoveMoney_guess
    void MoveMoney_guess(int a_guess, int b_guess, int c_guess, int d_guess, int e_guess, int f_guess);
};

#define g_engine_guess EQ_GLOBAL(Engine_guess*, 0x00988DF0)

// Coin box `param_guess` clicked with coins on the cursor (cursor mode 1-4 = platinum..copper): moves those
// coins into that box and resets both accepts.
// FUNCTION: TITANIUM 0x00569E9C
void CTradeWndView_guess::ClickedMoneyButton_guess(int param_guess)
{
    int value_guess = 0;
    char zero_guess = 0;
    if (g_display_guess->mode_guess != zero_guess) {
        int index_guess = g_display_guess->mode_guess - 1;
        switch (g_display_guess->mode_guess) {
        case 1:
            value_guess = g_charView_guess->Field11e4_guess();
            break;
        case 2:
            value_guess = g_charView_guess->Field11e8_guess();
            break;
        case 3:
            value_guess = g_charView_guess->Field11ec_guess();
            break;
        case 4:
            value_guess = g_charView_guess->Field11f0_guess();
            break;
        }
        g_engine_guess->MoveMoney_guess(0, 3, index_guess, param_guess, value_guess, 0);
        SetHisReadyTrade_guess(0);
    }
}

// Resets both accepts when either changed slot belongs to the trade.
// FUNCTION: TITANIUM 0x00569F63
void CTradeWndView_guess::TradeItemChanged_guess(Dword_guess param_guess, int second_guess)
{
    unsigned char flagA_guess;
    unsigned char flagB_guess;
    unsigned char a_guess = IsMyTradeSlot_guess(param_guess.value_guess, &flagA_guess);
    unsigned char b_guess = IsMyTradeSlot_guess(second_guess, &flagB_guess);
    if (a_guess + b_guess != 0 || flagB_guess + flagA_guess != 0) {
        SetHisReadyTrade_guess(0);
    }
}

// Places an item the server put in the partner's slot (index 0-7 goes to slot 8+index). An item that fails to
// resolve is reported (string 1366 "Got a bogus item, deleting it") and dropped.
// FUNCTION: TITANIUM 0x00569FA8
int CTradeWndView_guess::AddEqItemToHisTradeArray_guess(Child_guess* param_guess)
{
    if (flag3_guess == 0) {
        return 0;
    }
    if (param_guess == 0) {
        return 0;
    }
    if (param_guess->GetItemId_guess() == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x556, 0), 0xd, 1);
        delete param_guess;
        return 0;
    }
    if (param_guess->index_guess < 8) {
        int* slot_guess = &block_guess[8 + param_guess->index_guess];
        Child_guess* old_guess = (Child_guess*)*slot_guess;
        delete old_guess;
        *slot_guess = (int)param_guess;
        SetHisReadyTrade_guess(0);
        return 1;
    }
    delete param_guess;
    return 0;
}

// Drops the cursor item into the first free trade slot. NPCs take no stacks (string 537) and only 4 slots;
// a full trade prints string 12319 "All your trade slots are full!".
// FUNCTION: TITANIUM 0x0056A029
// @early-stop: budget, structural ndiff=132
void CTradeWndView_guess::DropItemIntoTrade_guess()
{
    int found_guess = -1;
    int count_guess;
    char zero_guess = 0;
    if (g_stateA_guess->flag_0244_guess == zero_guess) {
        if (g_charView_guess->ActorPointer_guess()->Slot04_guess(1) == zero_guess) {
            return;
        }
        count_guess = 8;
    } else {
        count_guess = 4;
    }

    if (g_charView_guess->ActorPointer_guess()->IsStackable_guess() != zero_guess
        && (g_stateA_guess == (State_guess*)zero_guess || g_stateA_guess->flag_0244_guess != 1)) {
        int* slot_guess = block_guess;
        for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
            if (g_charView_guess->ActorPointer_guess() == (Actor_guess*)zero_guess) {
                break;
            }
            if (*slot_guess != (int)zero_guess) {
                int actor_id_guess = ((Child_guess*)g_charView_guess->ActorPointer_guess())->GetItemId_guess();
                int child_id_guess = ((Child_guess*)*slot_guess)->GetItemId_guess();
                if (actor_id_guess == child_id_guess) {
                    if (SwapCombine_guess(g_charView_guess->ActorAddress_guess(), slot_guess, 0x1e,
                            index_guess + 3000) != 0) {
                        found_guess = index_guess;
                    }
                }
            }
            ++slot_guess;
        }
    }

    if (g_charView_guess->ActorPointer_guess() != (Actor_guess*)zero_guess) {
        int* slot_guess = block_guess;
        for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
            if (g_charView_guess->ActorPointer_guess() == (Actor_guess*)zero_guess) {
                break;
            }
            if (g_stateA_guess != (State_guess*)zero_guess && g_stateA_guess->flag_0244_guess == 1
                && g_charView_guess->ActorPointer_guess()->field_0048_guess > 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x219, 0), 0xd, 1);
                break;
            }
            if (*slot_guess == (int)zero_guess) {
                pinstCInvSlotMgr_guess->MoveItem(0x1e, index_guess + 3000, 0, 1);
                found_guess = index_guess;
            }
            ++slot_guess;
        }
    }

    if (found_guess == -1) {
        pEverQuest->dsp_chat(pStringTable->getString(0x301f, 0), 0xa, 1);
    } else {
        SetHisReadyTrade_guess(0);
    }
    g_display_guess->state_0010_guess = g_charView_guess->ActorPointer_guess() != 0;
}

// Drops the cursor coins into the matching coin box (platinum..copper by cursor mode 1-4).
// FUNCTION: TITANIUM 0x0056A2B8
void CTradeWndView_guess::DropMoneyIntoTrade_guess()
{
    if (g_display_guess->mode_guess != 0) {
        int value_guess = 0;
        switch (g_display_guess->mode_guess) {
        case 1:
            value_guess = g_charView_guess->Field11e4_guess();
            break;
        case 2:
            value_guess = g_charView_guess->Field11e8_guess();
            break;
        case 3:
            value_guess = g_charView_guess->Field11ec_guess();
            break;
        case 4:
            value_guess = g_charView_guess->Field11f0_guess();
            break;
        }
        g_engine_guess->MoveMoney_guess(0, 3, g_display_guess->mode_guess - 1,
            g_display_guess->mode_guess - 1, value_guess, 0);
        SetHisReadyTrade_guess(0);
    }
}

// Opens the trade with `state_guess`. The opener (`flag_guess`) drops what is on the cursor; the other side
// answers OP_TradeRequestAck (partner id, my id). Opens the inventory window (0x850C34) unless it is open,
// noting which in +0x160. Shows the trade window, except that when this side opens it on an NPC partner
// (+0x244 == 1) the give window (0x850C60) opens instead.
// FUNCTION: TITANIUM 0x0056A380
void CTradeWndView_guess::Activate_guess(State_guess* state_guess, unsigned char flag_guess)
{
    if (state_005c_guess != 0) {
        return;
    }
    Clear_guess();
    g_stateA_guess = state_guess;
    if (g_prevState_guess != 0) {
        int value_guess = g_prevState_guess->value_guess;
        FUN_004c94ae_guess()->field_f0_guess = value_guess;
    }
    g_prevState_guess = state_guess;
    if (flag_guess != 0) {
        if (g_charView_guess->Value78_guess() != 0) {
            DropItemIntoTrade_guess();
        } else {
            DropMoneyIntoTrade_guess();
        }
    } else {
        if (g_stateA_guess != 0) {
            int data_guess[2];
            data_guess[0] = g_stateA_guess->value_guess;
            data_guess[1] = g_stateB_guess->value_guess;
            EQSendMessage(EQ_ARRAY(char, 0x00905ca0), OP_TradeRequestAck, data_guess, 8, 1);
        }
    }
    EQ_GLOBAL(int, 0x009248d4) = 1;
    UpdateTradeDisplay_guess();
    unsigned char target_state_guess = pinstCInventoryWnd_guess->dShow;
    state_0160_guess = target_state_guess;
    if (target_state_guess == 0) {
        pinstCInventoryWnd_guess->Activate();
    }
    if (g_stateA_guess == 0 || g_stateA_guess->flag_0244_guess != 1 || flag_guess == 0) {
        Slot48_guess(1, 1);
    } else {
        pinstCGiveWnd_guess->Activate();
    }
    flag3_guess = 1;
}

// Left clicks: Cancel, Trade, and my four coin boxes; everything else goes to the base handler.
// FUNCTION: TITANIUM 0x0056A4A4
int CTradeWndView_guess::WndNotification_guess(CXWnd* control_guess, int message_guess, void* data_guess)
{
    if (message_guess == 1) {
        if (control_guess == cancelButton_188_guess) {
            ClickedCancelButton_guess();
            return 0;
        }
        if (control_guess == tradeButton_184_guess) {
            ClickedTradeButton_guess();
            return 0;
        }
        int index_guess = 0;
        CXWnd** button_guess = &moneyButtons_174_guess[0];
        do {
            if (control_guess == *button_guess) {
                ClickedMoneyButton_guess(index_guess);
                return 0;
            }
            ++index_guess;
            ++button_guess;
        } while (index_guess < 4);
    }
    return WndNotification(control_guess, message_guess, data_guess);
}
