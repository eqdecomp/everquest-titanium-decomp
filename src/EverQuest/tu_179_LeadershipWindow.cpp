// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 179: a hint from compare/tumap.py.
// CLeadershipWindow ("LeadershipWindow"): buy group and raid leadership abilities and make hot keys for
// them. CLeadershipWindow_guess and Object_guess are the same window; LeadershipManager_guess (0x9859EC) is tu_073's
// leadership manager and LeadershipAbility_guess its ability definition, not AA. Rows sit at +0x1AC, 50 per list
// (0 group, 1 raid); +0x4CC is the selected row, +0x4D0 the shown list.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>
#include <stdio.h>

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
// EXTERNAL: TITANIUM 0x0060E450 strcpy

struct LeadershipAbility_guess {
    int titleId_0000;
    int nameId_0004;
    int rank_0008;
    int text1Id_000c;
    int text2Id_0010;
    int text3Id_0014;
    int descriptionId_0018;
    int requirementId_001c;
    char pad_0020_0033[0x14];
    int maxRank_0034;
};

struct LeadershipManager_guess {
    LeadershipAbility_guess* abilities[1];

    // EXTERNAL: TITANIUM 0x004B5EB1 LeadershipManager_guess::CanBuyNextRank_guess
    bool CanBuyNextRank_guess(EQ_Character* character, int index);
    // EXTERNAL: TITANIUM 0x004B4E12 LeadershipManager_guess::HasAbility_guess
    bool HasAbility_guess(EQ_Character* character, int index, bool flag);
    // EXTERNAL: TITANIUM 0x004B4488 LeadershipManager_guess::HasSharedRank_guess
    bool HasSharedRank_guess(EQ_Character* character, int index, bool flag);
    // EXTERNAL: TITANIUM 0x004B50AA LeadershipManager_guess::CanUse_guess
    bool CanUse_guess(EQ_Character* character, int index, int slot);
    // EXTERNAL: TITANIUM 0x004B5085 LeadershipManager_guess::GetNextRankCost_guess
    int GetNextRankCost_guess(EQ_Character* character, int index);
    // EXTERNAL: TITANIUM 0x004B3FA2 LeadershipManager_guess::GetGroupLeadershipPointCap_guess
    int GetGroupLeadershipPointCap_guess(EQ_Character* character);
    // EXTERNAL: TITANIUM 0x004B3FD0 LeadershipManager_guess::GetSpent_guess
    int GetSpent_guess(EQ_Character* character);
    // EXTERNAL: TITANIUM 0x004B415C LeadershipManager_guess::IsGroupAbility_guess
    bool IsGroupAbility_guess(int index);
};

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output, int id, const char* a1, const char* a2, const char* a3,
                              const char* a4, const char* a5, const char* a6, const char* a7,
                              const char* a8, const char* a9);

struct CCursorAttachmentView_guess {
    // EXTERNAL: TITANIUM 0x004FD91E CCursorAttachmentView_guess::Put_guess
    void Put_guess(int a, int b, int index, const char* text, int e);
};
#define pinstCCursorAttachment_guess EQ_GLOBAL(CCursorAttachmentView_guess*, 0x00850C24)
#define g_skipLeadershipConfirm_guess EQ_GLOBAL(int, 0x009254B8)

#define pAltAdvManager_guess EQ_GLOBAL(LeadershipManager_guess*, 0x009859EC)

struct Record_guess {
    int value;
    int listIndex;
};

struct State_guess {
    char pad_0000_0bef[0xbf0];
    int currentRanks_0bf0[64];
    char pad_0cf0_0e9f[0x1b0];
    int groupLeadershipPoints_0ea0_guess;
    int raidLeadershipPoints_0ea4_guess;
    char leadershipExpOn_0ea8_guess;
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct Child_guess {
    // EXTERNAL: TITANIUM 0x005482A0 Child_guess::Reset_guess
    void Reset_guess(int value);
};

// Window base, 0x15C bytes: the CSidlScreenWnd ctor (0x005A3850) and the fields its callers set.
struct RootBase_guess {
    char pad_0004_005b[0x58];
    char enabled_005c;
    char pad_005d_0063[7];
    unsigned int windowStyle_0064;
    char pad_0068_0123[0xbc];
    int target_0124;
    char pad_0128_0157[0x30];
    unsigned int flags_0158;
    // EXTERNAL: TITANIUM 0x005A3850 RootBase_guess::RootBase_guess
    RootBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 RootBase_guess::~RootBase_guess
    virtual ~RootBase_guess();
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7ChildBase_guess@@6B@
struct ChildBase_guess {
    // EXTERNAL: TITANIUM 0x005482A0 ChildBase_guess::Reset_guess
    void Reset_guess(int value);
    virtual void Slot_guess();
    virtual ~ChildBase_guess() { Reset_guess(-1); }
};

struct TextControl_guess;

// The leadership window: its dtor (0x526721) and ctor (0x526C4F) share one vtable at 0x657430.
// EXTERNAL: TITANIUM 0x00657430 ??_7CLeadershipWindow_guess@@6BRootBase_guess@@@
// EXTERNAL: TITANIUM 0x00657428 ??_7CLeadershipWindow_guess@@6BChildBase_guess@@@
struct CLeadershipWindow_guess : RootBase_guess, ChildBase_guess {
    virtual ~CLeadershipWindow_guess();
    CLeadershipWindow_guess(CXWnd* parent);
    CLeadershipWindow_guess* Delete_guess(unsigned char flags);
    // EXTERNAL: TITANIUM 0x005A2490 CLeadershipWindow_guess::GetCounter_guess
    CXWnd* GetCounter_guess(const CXStr& name);

    int laneCount_0160;
    char ready_0164;
    char pad_0165_0167[3];
    CButtonWnd* purchaseButton_0168;
    CButtonWnd* hotkeyButton1_016c;
    CButtonWnd* hotkeyButton2_0170;
    CButtonWnd* hotkeyButton3_0174;
    CButtonWnd* doneButton_0178;
    CButtonWnd* expOnButton_017c_guess;
    CButtonWnd* expOffButton_0180_guess;
    CStmlWnd* description_0184;
    TextControl_guess* groupPoints_0188_guess;
    TextControl_guess* raidPoints_018c_guess;
    CXWnd* subwindows_0190;
    CXWnd* pages_0194[2];
    CListWnd* lanes_019c[2];
    int laneCounts_01a4[2];
    Record_guess records_01ac[100];
    int recordBase_04cc;
    int recordRow_04d0;

    void UpdateRows_guess();
    bool AboutToShow_guess();
    void BuildLists_guess();
};

// Destructor of the leadership window (vtable 0x657430): expires every confirmation dialog its
// dialog-owner part (+0x15C) opened (the purchase prompts; 0x005482A0, all messages), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00526721
CLeadershipWindow_guess::~CLeadershipWindow_guess() {
}

struct Object_guess {
    char pad_0000[0x5c];
    char enabled_005c;
    char pad_005d[0xff];
    Child_guess child_015c;
    char pad_015d[3];
    int pageCount_0160;
    char pad_0164[4];
    CButtonWnd* button_0168;
    CButtonWnd* button_016c;
    CButtonWnd* button_0170;
    CButtonWnd* button_0174;
    CXWnd* done_0178;
    CButtonWnd* check_017c;
    CButtonWnd* check_0180;
    CStmlWnd* description_0184;
    char pad_0188[8];
    CXWnd* tabs_0190;
    CXWnd* pages_0194[2];
    CListWnd* lists_019c[2];
    int counts_01a4[2];
    Record_guess records_01ac[1];
    char pad_01b4[0x318];
    int recordBase_04cc;
    int recordRow_04d0;

    // EXTERNAL: TITANIUM 0x005A1880 Object_guess::OnShow
    void OnShow();
    void OnShow_guess();
    void SendPurchase_guess();
    void SendExpToggle_guess();
    void UpdateSelected_guess();
    // EXTERNAL: TITANIUM 0x00527130 Object_guess::UpdateRows_guess
    void UpdateRows_guess();
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
};

struct Window_guess {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84();
    virtual void Deactivate_guess();
};

struct TabNotify_guess {
    int pad_0000[2];
    CXWnd* page_0008;
};

struct ColoredList_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059B3E0 ColoredList_guess::SetItemColor_guess
    void SetItemColor_guess(int row, int column, int color);
};

struct TextControl_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x005BD810 TextControl_guess::SetText_guess
    void SetText_guess(const CXStr& text);
};

#define pinstCLeadershipWnd_guess EQ_GLOBAL(CLeadershipWindow_guess*, 0x00991C24)

#define g_state_guess EQ_GLOBAL(State_guess*, 0x00905D00)

// For the selected ability: Purchase if the next rank can be bought (ability 4 needs 0 and 20 needs 16
// first), Hotkey 1-3 if that rank is usable, and the text "Usable by:" (0x21CF), requirements and name.
// With nothing selected: help text 0x2183 and all buttons off.
// FUNCTION: TITANIUM 0x0052676D
void Object_guess::UpdateSelected_guess() {
    CXStr text;
    char buffer[1024];
    if (recordBase_04cc != -1) {
        int index = records_01ac[recordRow_04d0 * 0x32 + recordBase_04cc].value;
        LeadershipAbility_guess* ability = pAltAdvManager_guess->abilities[index];
        if (button_0168 != 0) {
            button_0168->Enabled = pAltAdvManager_guess->CanBuyNextRank_guess(pCharData, index);
            if ((index == 4 && !pAltAdvManager_guess->HasAbility_guess(pCharData, 0, true))
                || (index == 0x14 && !pAltAdvManager_guess->HasAbility_guess(pCharData, 0x10, true)))
                button_0168->Enabled = 0;
        }
        if (button_016c != 0)
            button_016c->Enabled = pAltAdvManager_guess->CanUse_guess(pCharData, index, 1);
        if (button_0170 != 0)
            button_0170->Enabled = pAltAdvManager_guess->CanUse_guess(pCharData, index, 2);
        if (button_0174 != 0)
            button_0174->Enabled = pAltAdvManager_guess->CanUse_guess(pCharData, index, 3);
        if (ability->descriptionId_0018 > 0) {
            sprintf(buffer, "%s  %s", pStringTable->getString(0x21cf, 0),
                    pStringTable->getString(ability->descriptionId_0018, 0));
            text += buffer;
        }
        if (ability->requirementId_001c > 0) {
            strcpy(buffer, pStringTable->getString(ability->requirementId_001c, 0));
            text += "<BR>";
            text += buffer;
        }
        text += "<BR>";
        int nameId = pAltAdvManager_guess->abilities[index]->nameId_0004;
        text += pStringTable->getString(nameId, 0);
        if (description_0184 != 0)
            description_0184->SetSTMLText(text, true, 0);
    } else {
        if (description_0184 != 0)
            description_0184->SetSTMLText(CXStr(pStringTable->getString(0x2183, 0)), true, 0);
        if (button_0168 != 0)
            button_0168->Enabled = 0;
        if (button_016c != 0)
            button_016c->Enabled = 0;
        if (button_0170 != 0)
            button_0170->Enabled = 0;
        if (button_0174 != 0)
            button_0174->Enabled = 0;
    }
}

struct Entry_guess {
    int id_0000;
    char pad_0004_002f[0x2c];
    int type_0030;
    char pad_0034_0037[4];
    char active_0038;
};

// Polymorphic view of a list window: only the slot at byte offset 0x130 is called.
struct ListSlots_guess {
    virtual void RefreshCounts_guess(); virtual void Slot04_guess(); virtual void Slot08_guess(); virtual void Slot0C_guess();
    virtual void Slot10_guess(); virtual void Slot14_guess(); virtual void Slot18_guess(); virtual void Slot1C_guess();
    virtual void Slot20_guess(); virtual void Slot24_guess(); virtual void Slot28_guess(); virtual void Slot2C_guess();
    virtual void Slot30_guess(); virtual void Slot34_guess(); virtual void Slot38_guess(); virtual void Slot3C_guess();
    virtual void Slot40_guess(); virtual void Slot44_guess(); virtual void Slot48_guess(); virtual void Slot4C_guess();
    virtual void Slot50_guess(); virtual void Slot54_guess(); virtual void Slot58_guess(); virtual void Slot5C_guess();
    virtual void Slot60_guess(); virtual void Slot64_guess(); virtual void Slot68_guess(); virtual void Slot6C_guess();
    virtual void Slot70_guess(); virtual void Slot74_guess(); virtual void Slot78_guess(); virtual void Slot7C_guess();
    virtual void Slot80_guess(); virtual void Slot84_guess(); virtual void Slot88_guess(); virtual void Slot8C_guess();
    virtual void Slot90_guess(); virtual void Slot94_guess(); virtual void Slot98_guess(); virtual void Slot9C_guess();
    virtual void SlotA0_guess(); virtual void SlotA4_guess(); virtual void SlotA8_guess(); virtual void SlotAC_guess();
    virtual void SlotB0_guess(); virtual void SlotB4_guess(); virtual void SlotB8_guess(); virtual void SlotBC_guess();
    virtual void SlotC0_guess(); virtual void SlotC4_guess(); virtual void SlotC8_guess(); virtual void SlotCC_guess();
    virtual void SlotD0_guess(); virtual void SlotD4_guess(); virtual void SlotD8_guess(); virtual void SlotDC_guess();
    virtual void SlotE0_guess(); virtual void SlotE4_guess(); virtual void SlotE8_guess(); virtual void SlotEC_guess();
    virtual void SlotF0_guess(); virtual void SlotF4_guess(); virtual void SlotF8_guess(); virtual void SlotFC_guess();
    virtual void Slot100_guess(); virtual void Slot104_guess(); virtual void Slot108_guess(); virtual void Slot10C_guess();
    virtual void Slot110_guess(); virtual void Slot114_guess(); virtual void Slot118_guess(); virtual void Slot11C_guess();
    virtual void Slot120_guess(); virtual void Slot124_guess(); virtual void Slot128_guess(); virtual void Slot12C_guess();
    virtual void Slot130_guess();
};

#define g_entries_guess EQ_GLOBAL(Entry_guess**, 0x009859EC)

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CTipWnd.h"

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_guess
void __cdecl FormatCXStr_guess(CXStr* output, const char* format, ...);

// Leadership window constructor: finds the LEW_ controls with Purchase and the three hot key buttons
// disabled, the group and raid lists LEList1-2 with their pages LEPage1-2, the two point counters, then
// fills both lists (0x00526A44).
// FUNCTION: TITANIUM 0x00526C4F
CLeadershipWindow_guess::CLeadershipWindow_guess(CXWnd* parent)
    : RootBase_guess(parent, "LeadershipWindow", 0xfffffdff, 1, 0), recordBase_04cc(-1) {
    purchaseButton_0168 = 0;
    hotkeyButton1_016c = 0;
    hotkeyButton2_0170 = 0;
    hotkeyButton3_0174 = 0;
    doneButton_0178 = 0;
    expOnButton_017c_guess = 0;
    expOffButton_0180_guess = 0;
    subwindows_0190 = 0;
    description_0184 = 0;
    groupPoints_0188_guess = 0;
    raidPoints_018c_guess = 0;
    laneCount_0160 = 2;
    recordRow_04d0 = 0;
    for (int k = 0; k < laneCount_0160; ++k) {
        lanes_019c[k] = 0;
        pages_0194[k] = 0;
    }
    if (target_0124 != 0) {
        windowStyle_0064 |= 0x10800;
        flags_0158 = 0x29;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        purchaseButton_0168 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_PurchaseButton");
        if (purchaseButton_0168 != 0)
            purchaseButton_0168->Enabled = 0;
        hotkeyButton1_016c = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_HotkeyButton1");
        hotkeyButton2_0170 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_HotkeyButton2");
        hotkeyButton3_0174 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_HotkeyButton3");
        if (hotkeyButton1_016c != 0)
            hotkeyButton1_016c->Enabled = 0;
        if (hotkeyButton2_0170 != 0)
            hotkeyButton2_0170->Enabled = 0;
        if (hotkeyButton3_0174 != 0)
            hotkeyButton3_0174->Enabled = 0;
        doneButton_0178 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_DoneButton");
        expOnButton_017c_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_OnButton");
        expOffButton_0180_guess = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_OffButton");
        subwindows_0190 = ((CSidlScreenWnd*)this)->GetChildItem("LEW_Subwindows");
        for (int k = 0; k < laneCount_0160; ++k) {
            char listName[128];
            sprintf(listName, "LEList%d", k + 1);
            CXStr pageName(listName);
            lanes_019c[k] = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem(pageName);
            if (lanes_019c[k] != 0) {
                lanes_019c[k]->SetColors(0xffffffff, 0xffffff00, 0xff808080);
                lanes_019c[k]->SetColumnJustification(0, 0);
                lanes_019c[k]->SetColumnJustification(1, 1);
                lanes_019c[k]->SetColumnJustification(2, 1);
                ((ListFields_guess*)lanes_019c[k])->textColor_guess = 0xff8aa3ff;
                ((ListFields_guess*)lanes_019c[k])->flag_guess = 1;
            }
            FormatCXStr_guess(&pageName, "LEPage%d", k + 1);
            pages_0194[k] = ((CSidlScreenWnd*)this)->GetChildItem(pageName);
        }
        description_0184 = (CStmlWnd*)((CSidlScreenWnd*)this)->GetChildItem("LEW_Description");
        // Group points; the next counter shows raid points.
        groupPoints_0188_guess = (TextControl_guess*)GetCounter_guess("LEW_CurrentGroupCount");
        raidPoints_018c_guess = (TextControl_guess*)GetCounter_guess("LEW_CurrentRaidCount");
        ready_0164 = 0;
        BuildLists_guess();
    }
}

// Sorts the 31 abilities into the group list (kind 1) and the raid list (kind 2), name in column 0.
// FUNCTION: TITANIUM 0x00526A44
// @early-stop: budget, structural ndiff=52
void CLeadershipWindow_guess::BuildLists_guess() {
    if (g_state_guess != 0) {
        ready_0164 = 1;
        laneCounts_01a4[0] = 0;
        laneCounts_01a4[1] = 0;
        for (int i = 0; i < 0x1f; i++) {
            Entry_guess* entry = g_entries_guess[i];
            if (entry->active_0038 != 0) {
                if (entry->type_0030 == 1) {
                    records_01ac[laneCounts_01a4[0]].value = i;
                    laneCounts_01a4[0]++;
                } else if (entry->type_0030 == 2) {
                    records_01ac[50 + laneCounts_01a4[1]].value = i;
                    laneCounts_01a4[1]++;
                }
            }
        }
        for (int k = 0; k < laneCount_0160; k++) {
            if (lanes_019c[k] != 0) {
                ((ListSlots_guess*)lanes_019c[k])->Slot130_guess();
                Record_guess* row = &records_01ac[50 * k];
                for (int j = 0; j < laneCounts_01a4[k]; j++, row++) {
                    row->listIndex = lanes_019c[k]->AddString(
                        CXStr(pStringTable->getString(g_entries_guess[row->value]->id_0000, 0)), -1, 0, 0);
                }
            }
        }
    }
}

// OnShow: opening shows context tip 0x29 (CTipWnd 0x9928E0); closing drops a pending confirmation.
// FUNCTION: TITANIUM 0x00526B84
void Object_guess::OnShow_guess() {
    if (enabled_005c != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x29, 0);
        }
    } else {
        child_015c.Reset_guess(-1);
    }
    return OnShow();
}

// Buys the selected ability (PurchaseLeadershipAA 0x17BF, its index).
// FUNCTION: TITANIUM 0x00526BB7
void Object_guess::SendPurchase_guess() {
    int value;
    memset(&value, 0, 4);
    int index = recordRow_04d0 * 0x32 + recordBase_04cc;
    value = records_01ac[index].value;
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), OP_PurchaseLeadershipAA, &value, 4, 1);
}

// Sends the leadership-exp switch (LeadershipExpToggle 0x5B37, one byte).
// FUNCTION: TITANIUM 0x00526C1D
void Object_guess::SendExpToggle_guess() {
    char value;
    value = g_state_guess->leadershipExpOn_0ea8_guess != 0;
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), OP_LeadershipExpToggle, &value, 1, 1);
}

// Scalar deleting destructor of the leadership window (vtable 0x657430 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00527114
CLeadershipWindow_guess* CLeadershipWindow_guess::Delete_guess(unsigned char flags) {
    this->CLeadershipWindow_guess::~CLeadershipWindow_guess();
    if (flags & 1)
        free(this);
    return this;
}

// Rank "cur/max" and next cost ("--" at max) per row, coloured green when the leader shares it, gold when
// you have it, grey when it can't be bought, else white. Then the exp switch and the group and raid points
// as "%d of %d" against their caps.
// FUNCTION: TITANIUM 0x00527130
// @early-stop: budget, structural ndiff=121
void CLeadershipWindow_guess::UpdateRows_guess() {
    CXStr text;
    char buffer[1024];
    int* record = &records_01ac[0].listIndex;
    for (int category = 0; category < laneCount_0160; ++category, record += 100) {
        CListWnd* list = lanes_019c[category];
        if (list != 0 && laneCounts_01a4[category] > 0) {
            int* row = record;
            for (int rowIndex = 0; rowIndex < laneCounts_01a4[category]; ++rowIndex, row += 2) {
                unsigned int index = row[-1];
                int current = g_state_guess->currentRanks_0bf0[index];
                int maximum = pAltAdvManager_guess->abilities[index]->maxRank_0034;
                int points = pAltAdvManager_guess->GetNextRankCost_guess(pCharData, index);
                sprintf(buffer, "%d/%d", current, maximum);
                text = buffer;
                list->SetItemText(row[0], 1, text);
                if (current < maximum)
                    sprintf(buffer, "%d", points);
                else
                    sprintf(buffer, "--");
                text = buffer;
                list->SetItemText(row[0], 2, text);

                int color;
                if (pAltAdvManager_guess->HasSharedRank_guess(pCharData, index, true)) {
                    color = 0xff00ff00;
                } else if (pAltAdvManager_guess->HasAbility_guess(pCharData, index, true)) {
                    color = 0xffd6b228;
                } else if (!pAltAdvManager_guess->CanBuyNextRank_guess(pCharData, index)
                           || (index == 4 && !pAltAdvManager_guess->HasAbility_guess(pCharData, 0, true))
                           || (index == 0x14 && !pAltAdvManager_guess->HasAbility_guess(pCharData, 0x10, true))) {
                    color = 0xffc0c0c0;
                } else {
                    color = 0xffffffff;
                }
                ((ColoredList_guess*)list)->SetItemColor_guess(row[0], 0, color);
                ((ColoredList_guess*)list)->SetItemColor_guess(row[0], 1, color);
                ((ColoredList_guess*)list)->SetItemColor_guess(row[0], 2, color);
            }
        }
    }
    if (expOnButton_017c_guess != 0)
        expOnButton_017c_guess->SetCheck(g_state_guess->leadershipExpOn_0ea8_guess);
    if (expOffButton_0180_guess != 0)
        expOffButton_0180_guess->SetCheck(g_state_guess->leadershipExpOn_0ea8_guess == 0);
    if (groupPoints_0188_guess != 0) {
        sprintf(buffer, "%d of %d", g_state_guess->groupLeadershipPoints_0ea0_guess,
                pAltAdvManager_guess->GetGroupLeadershipPointCap_guess(pCharData));
        text = buffer;
        groupPoints_0188_guess->SetText_guess(text);
    }
    if (raidPoints_018c_guess != 0) {
        sprintf(buffer, "%d of %d", g_state_guess->raidLeadershipPoints_0ea4_guess,
                pAltAdvManager_guess->GetSpent_guess(pCharData));
        text = buffer;
        raidPoints_018c_guess->SetText_guess(text);
    }
    ((Object_guess*)this)->UpdateSelected_guess();
}

// Leadership window AboutToShow (vtable 0x657430 slot 49): vetoes the show while the window has no
// template (+0x124); otherwise sorts the abilities into the group and raid lists once (0x00526A44, flag
// +0x164) and refreshes the values (0x00527130).
// FUNCTION: TITANIUM 0x005274C9
bool CLeadershipWindow_guess::AboutToShow_guess() {
    if (target_0124 == 0)
        return false;
    if (ready_0164 == 0)
        BuildLists_guess();
    UpdateRows_guess();
    return true;
}

// Purchase asks first (0x2186/0x2187 group, 0x218B/0x218C raid, by cost 1 or more; 20 s) unless 0x9254B8
// is set, then buys. Hotkey n puts ability*8+n on the cursor (CCursorAttachment kind 13, a leadership hot
// button). On and Off switch leadership exp; list clicks select, tab clicks swap lists.
// FUNCTION: TITANIUM 0x005274F4
// @early-stop: budget, structural ndiff=51
int Object_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if (sender == done_0178) {
            ((Window_guess*)this)->Deactivate_guess();
        } else if (sender == button_0168) {
            if (recordBase_04cc < 0)
                return 1;
            button_0168->Enabled = 0;
            if (pCharData != 0) {
                if (g_skipLeadershipConfirm_guess == 0) {
                    char costText[8];
                    char text[512];
                    int index = records_01ac[recordRow_04d0 * 0x32 + recordBase_04cc].value;
                    int cost = pAltAdvManager_guess->GetNextRankCost_guess(pCharData, index);
                    int id;
                    if (pAltAdvManager_guess->IsGroupAbility_guess(index))
                        id = (cost != 1) + 0x2186;
                    else
                        id = (cost != 1) + 0x218b;
                    sprintf(costText, "%d", cost);
                    int titleId = pAltAdvManager_guess->abilities[index]->titleId_0000;
                    FormatText_guess(text, id, costText, pStringTable->getString(titleId, 0),
                                     0, 0, 0, 0, 0, 0, 0);
                    pConfirmationDialogPool_guess->Activate((ChildBase_guess*)pinstCLeadershipWnd_guess, 100, text, 0xc,
                                                            20000, 0, 1);
                } else {
                    SendPurchase_guess();
                }
            }
            return 1;
        } else if (sender == button_016c) {
            if (recordBase_04cc < 0)
                return 1;
            int index = records_01ac[recordRow_04d0 * 0x32 + recordBase_04cc].value;
            CXStr text;
            if (pAltAdvManager_guess->abilities[index]->text1Id_000c > 0)
                text = pStringTable->getString(pAltAdvManager_guess->abilities[index]->text1Id_000c, 0);
            if (pAltAdvManager_guess->abilities[index]->text2Id_0010 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                int text2Id = pAltAdvManager_guess->abilities[index]->text2Id_0010;
                text += pStringTable->getString(text2Id, 0);
            }
            if (pAltAdvManager_guess->abilities[index]->text3Id_0014 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                text += pStringTable->getString(pAltAdvManager_guess->abilities[index]->text3Id_0014, 0);
            }
            if (pAltAdvManager_guess->abilities[index]->rank_0008 > 1)
                // Rank suffix only for multi-rank abilities; Hotkey 2 and 3 always add one.
                text += " 1";
            pinstCCursorAttachment_guess->Put_guess(0, 0xd, index * 8 + 1, text, -1);
        } else if (sender == button_0170) {
            if (recordBase_04cc < 0)
                return 1;
            int index = records_01ac[recordRow_04d0 * 0x32 + recordBase_04cc].value;
            CXStr text;
            if (pAltAdvManager_guess->abilities[index]->text1Id_000c > 0)
                text = pStringTable->getString(pAltAdvManager_guess->abilities[index]->text1Id_000c, 0);
            if (pAltAdvManager_guess->abilities[index]->text2Id_0010 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                int text2Id = pAltAdvManager_guess->abilities[index]->text2Id_0010;
                text += pStringTable->getString(text2Id, 0);
            }
            if (pAltAdvManager_guess->abilities[index]->text3Id_0014 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                text += pStringTable->getString(pAltAdvManager_guess->abilities[index]->text3Id_0014, 0);
            }
            text += " 2";
            pinstCCursorAttachment_guess->Put_guess(0, 0xd, index * 8 + 2, text, -1);
        } else if (sender == button_0174) {
            if (recordBase_04cc < 0)
                return 1;
            int index = records_01ac[recordRow_04d0 * 0x32 + recordBase_04cc].value;
            CXStr text;
            if (pAltAdvManager_guess->abilities[index]->text1Id_000c > 0)
                text = pStringTable->getString(pAltAdvManager_guess->abilities[index]->text1Id_000c, 0);
            if (pAltAdvManager_guess->abilities[index]->text2Id_0010 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                int text2Id = pAltAdvManager_guess->abilities[index]->text2Id_0010;
                text += pStringTable->getString(text2Id, 0);
            }
            if (pAltAdvManager_guess->abilities[index]->text3Id_0014 > 0) {
                text += EQ_ARRAY(char, 0x0063FE10);
                text += pStringTable->getString(pAltAdvManager_guess->abilities[index]->text3Id_0014, 0);
            }
            text += " 3";
            pinstCCursorAttachment_guess->Put_guess(0, 0xd, index * 8 + 3, text, -1);
        } else if (sender == check_017c) {
            if (check_017c != 0)
                check_017c->SetCheck(true);
            if (check_0180 != 0)
                check_0180->SetCheck(false);
            if (g_state_guess->leadershipExpOn_0ea8_guess == 0) {
                g_state_guess->leadershipExpOn_0ea8_guess = 1;
                SendExpToggle_guess();
            }
        } else if (sender == check_0180) {
            if (check_017c != 0)
                check_017c->SetCheck(false);
            if (check_0180 != 0)
                check_0180->SetCheck(true);
            if (g_state_guess->leadershipExpOn_0ea8_guess != 0) {
                g_state_guess->leadershipExpOn_0ea8_guess = 0;
                SendExpToggle_guess();
            }
        } else {
            child_015c.Reset_guess(-1);
            int i;
            for (i = 0; i < pageCount_0160; i++) {
                if (sender == lists_019c[i]) {
                    int selection = lists_019c[i]->GetCurSel();
                    for (int j = 0; j < counts_01a4[recordRow_04d0]; j++) {
                        if (records_01ac[recordRow_04d0 * 0x32 + j].listIndex == selection) {
                            recordBase_04cc = j;
                            UpdateSelected_guess();
                            break;
                        }
                    }
                    return 1;
                }
            }
            if (sender == tabs_0190) {
                CXWnd* page = ((TabNotify_guess*)data)->page_0008;
                for (i = 0; i < pageCount_0160; i++) {
                    if (page == pages_0194[i]) {
                        if (lists_019c[recordRow_04d0] != 0) {
                            lists_019c[recordRow_04d0]->SetCurSel(-1);
                            recordBase_04cc = -1;
                            recordRow_04d0 = i;
                            UpdateSelected_guess();
                            UpdateRows_guess();
                        }
                        return 1;
                    }
                }
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

