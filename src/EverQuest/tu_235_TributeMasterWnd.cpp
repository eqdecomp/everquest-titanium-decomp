// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 235: a hint from compare/tumap.py.
// CTributeMasterWnd (screen "TributeMasterWnd", vtable 0x65F788): active benefits, every benefit with
// its tiers and costs, and item or coin donations. CTributeMasterWnd_guess, Target_guess, Pending_guess,
// Tick_0056e7_guess, Scalar_0056e_guess and Checker_0056_guess are views of it. g_sink_guess (0x850350)
// is the tribute table and request sender; g_spawn_0056_guess (0x905D10) the tribute master NPC.
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include <new>
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CQuantityWnd.h"

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);

struct LayoutLookup_guess {
    char pad_000_guess[0x3c];
    // EXTERNAL: TITANIUM 0x00572300 LayoutLookup_guess::Lookup_guess
    int Lookup_guess(const char* name);
    // EXTERNAL: TITANIUM 0x00572300 LayoutLookup_guess::Lookup3_guess
    int Lookup3_guess(const char* name, int value, int flag);
};

struct Panel_guess {
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
    virtual void Slot73_guess(int value);
    virtual void Slot74_guess(int value);
};

struct Defaults_guess {
    // EXTERNAL: TITANIUM 0x004AE7DE Defaults_guess::SetValue_guess
    void SetValue_guess(int width, int fallback);
    // EXTERNAL: TITANIUM 0x004A1350 Defaults_guess::Reset_guess
    void Reset_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x004AE8D9 Defaults_guess::Read_guess
    int Read_guess(int value);
};

#define g_defaults_guess EQ_GLOBAL(Defaults_guess*, 0x00988DF0)

struct Entry_guess {
    char pad_000_guess[0x40];
    int field_40_guess; // 0x40
    int field_44_guess; // 0x44
    char pad_048_guess[0x04];
    int field_4c_guess;
    int field_50_guess; // 0x50
};

struct Record_0056_guess {
    char pad_000_guess[0x0c];
    int count_guess; // 0x0c
    int slots_guess[1]; // 0x10
    int values_guess[9]; // 0x14
    int widths_guess[1]; // 0x38
};

struct CandidateHolder_guess {
    int unused_guess;
    int vbaseOffset_0004_guess; // 0x04
};

struct CandidateSlot_guess {
    int id_guess;    // 0x00
    int index_guess; // 0x04
};

struct Candidate_guess {
    char pad_000_guess[0x08];
    union {
        CandidateHolder_guess* holder_guess; // 0x08
        char embedded_guess[0xe80 - 0x08];
    };
    __int64 clock_guess; // 0xe80

    // EXTERNAL: TITANIUM 0x005F0D80 Candidate_guess::GetSlot_guess
    CandidateSlot_guess* GetSlot_guess(int index);
};

struct State_0056_guess {
    char pad_000_guess[0x120];
    char text_120_guess[0x132]; // 0x120
    char flag_252_guess; // 0x252
    char pad_253_guess[0x05];
    int value_guess; // 0x258
};

struct SavePacket_0056_guess {
    int field_00_guess;      // 0x00
    int ids_guess[5];        // 0x04
    int indexes_guess[5];    // 0x18
    int value_guess;         // 0x2c
};

struct LookupResult_guess {
    char pad_0000_guess[0x11a4];
    int level_11a4_guess;
    char pad_11a8_guess[0x2c];
    int platinum_11d4_guess;
};

struct LookupService_guess {
    int unused_guess;
    // EXTERNAL: TITANIUM 0x005EC220 LookupService_guess::GetCharInfo2
    LookupResult_guess* GetCharInfo2();
};

struct LookupStatus_guess {
    int unused_guess;
    LookupService_guess service_guess; // 0x04
};

#define g_candidate_guess EQ_GLOBAL(Candidate_guess*, 0x00905D00)
#define g_spawn_0056_guess EQ_GLOBAL(State_0056_guess*, 0x00905D10)
#define g_other_0056_guess EQ_GLOBAL(State_0056_guess*, 0x00905CE4)
#define g_connection_0056_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_reset_0056_guess EQ_GLOBAL(int, 0x009248D4)
#define g_message_0056_guess EQ_GLOBAL(int, 0x00923D94)

struct Record_guess {
    Entry_guess* entry_0000_guess;
};

struct Helper_guess {
    char pad_000_guess[0x11c];
    int count_guess; // 0x11c
    char pad_120_guess[0x0c];
    int widthCount_guess; // 0x12c
    // EXTERNAL: TITANIUM 0x00597BE0 Helper_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 Helper_guess::GetItemData
    int GetItemData(int index);
    // EXTERNAL: TITANIUM 0x00597C20 Helper_guess::SetCurSel
    void SetCurSel(int index);
    // EXTERNAL: TITANIUM 0x00598D90 Helper_guess::Apply_guess
    void Apply_guess(int index);
    // EXTERNAL: TITANIUM 0x00598170 Helper_guess::GetWidth_guess
    int GetWidth_guess(int index);
    // EXTERNAL: TITANIUM 0x005981F0 Helper_guess::SetWidth_guess
    void SetWidth_guess(int index, int width);
    // EXTERNAL: TITANIUM 0x0059B3E0 Helper_guess::SetValue_guess
    void SetValue_guess(int row, int column, int value);
};

struct Container_guess {
    char pad_000_guess[0x10];
    int count_guess; // 0x10
    struct Second_guess {
        char pad_000_guess[0x10];
        int count_guess; // 0x10

        // EXTERNAL: TITANIUM 0x004EB924 Second_guess::Lookup_guess
        Record_guess* Lookup_guess(int index);
    } second_guess; // 0x14

    // EXTERNAL: TITANIUM 0x004EB924 Container_guess::Lookup_guess
    Record_guess* Lookup_guess(int index);
};

struct TributeManager_guess {
    int count_guess; // 0x00
    // EXTERNAL: TITANIUM 0x00435150 TributeManager_guess::GetUpkeep_guess
    int GetUpkeep_guess();
    // EXTERNAL: TITANIUM 0x00434096 TributeManager_guess::LowerTributeTier_guess
    void LowerTributeTier_guess(int value);
    // EXTERNAL: TITANIUM 0x00434495 TributeManager_guess::IsTributeAvailable_guess
    bool IsTributeAvailable_guess();
    // EXTERNAL: TITANIUM 0x00434AE0 TributeManager_guess::Find_guess
    Record_0056_guess* Find_guess(int key);
    // EXTERNAL: TITANIUM 0x00434C82 TributeManager_guess::AddActiveTribute_guess
    void AddActiveTribute_guess(int key);
    // EXTERNAL: TITANIUM 0x00434B8A TributeManager_guess::RequestTributeDescription_guess
    void RequestTributeDescription_guess(int mode, int key);
    // EXTERNAL: TITANIUM 0x00433EAC TributeManager_guess::SendTributeItem_guess
    void SendTributeItem_guess(int key, int value);
    // EXTERNAL: TITANIUM 0x004344F0 TributeManager_guess::DonateTributePlatinum_guess
    void DonateTributePlatinum_guess(int value);
};

#define g_sink_guess EQ_GLOBAL(TributeManager_guess, 0x00850350)


struct CTributeMasterWnd_guess {
    char pad_000_guess[0x120];
    LayoutLookup_guess layout_120_guess; // 0x120, size 0x3c
    int field_15c_guess; // 0x15c
    Helper_guess* helper_guess; // 0x160
    Helper_guess* helper2_guess; // 0x164
    char pad_168_guess[0x18];
    Panel_guess* panel_180_guess; // 0x180
    Container_guess container_guess; // 0x184, size 0x28
    unsigned char field_1ac_guess; // 0x1ac
    void Mark_guess();
    void RemoveBenefit_guess();
    void SelectBenefit_guess(int key);
    void RefreshStatus_guess();
    void SaveWidths_guess();
    void LoadWidths_guess();
    char CloseMaster_guess();
};

// Marks the lists stale; the next frame rebuilds them.
// FUNCTION: TITANIUM 0x0056CE7C
void CTributeMasterWnd_guess::Mark_guess() {
    field_1ac_guess = 1;
}

// Selects tribute `key` in both lists and shows its description (0x434B8A). Removes nothing.
// FUNCTION: TITANIUM 0x0056CE84
void CTributeMasterWnd_guess::SelectBenefit_guess(int key) {
    g_sink_guess.Find_guess(key);

    if (helper_guess != 0) {
        int index = -1;
        for (int i = 0; i < helper_guess->count_guess; ++i) {
            if (helper_guess->GetItemData(i) == key) {
                index = i;
                break;
            }
        }
        helper_guess->SetCurSel(index);
        helper_guess->Apply_guess(index);
    }

    if (helper2_guess != 0) {
        int index = -1;
        for (int i = 0; i < helper2_guess->count_guess; ++i) {
            if (helper2_guess->GetItemData(i) == key) {
                index = i;
                break;
            }
        }
        helper2_guess->SetCurSel(index);
        helper2_guess->Apply_guess(index);
    }

    if (field_15c_guess != 0) {
        g_sink_guess.RequestTributeDescription_guess(1, key);
    }
}

// LoadIniInfo side: column widths (ActiveBenefitList/BenefitMasterList .colN.wid) and the list layout.
// FUNCTION: TITANIUM 0x0056D04A
void CTributeMasterWnd_guess::LoadWidths_guess() {
    int values_guess[10];
    char buffer_guess[256];
    if (helper_guess != 0) {
        int index = 0;
        while (index < (helper_guess->widthCount_guess < 1 ? 1 : helper_guess->widthCount_guess)) {
            values_guess[index] = helper_guess->GetWidth_guess(index);
            ++index;
        }
        index = 0;
        while (index < (helper_guess->widthCount_guess < 1 ? 1 : helper_guess->widthCount_guess)) {
            _sprintf_guess(buffer_guess, "ActiveBenefitList.col%d.wid", index);
            int value = layout_120_guess.Lookup3_guess(buffer_guess, values_guess[index], 1);
            values_guess[index] = g_defaults_guess->Read_guess(value);
            helper_guess->SetWidth_guess(index, values_guess[index]);
            ++index;
        }
    }
    if (helper2_guess != 0) {
        int index = 0;
        while (index < (helper2_guess->widthCount_guess < 1 ? 1 : helper2_guess->widthCount_guess)) {
            values_guess[index] = helper2_guess->GetWidth_guess(index);
            ++index;
        }
        index = 0;
        while (index < (helper2_guess->widthCount_guess < 1 ? 1 : helper2_guess->widthCount_guess)) {
            _sprintf_guess(buffer_guess, "BenefitMasterList.col%d.wid", index);
            int value = layout_120_guess.Lookup3_guess(buffer_guess, values_guess[index], 1);
            values_guess[index] = g_defaults_guess->Read_guess(value);
            helper2_guess->SetWidth_guess(index, values_guess[index]);
            ++index;
        }
    }
    if (panel_180_guess != 0) {
        panel_180_guess->Slot73_guess(layout_120_guess.Lookup_guess("ListLayout"));
    }
}

// StoreIniInfo side of 0x0056D04A: saves every column width of ActiveBenefitList and BenefitMasterList
// (.colN.wid keys) and the list layout.
// FUNCTION: TITANIUM 0x0056D1CE
void CTributeMasterWnd_guess::SaveWidths_guess() {
    char buffer_guess[256];
    int index = 0;
    if (helper_guess != 0) {
        while (index < (helper_guess->widthCount_guess < 1 ? 1 : helper_guess->widthCount_guess)) {
            _sprintf_guess(buffer_guess, "ActiveBenefitList.col%d.wid", index);
            g_defaults_guess->SetValue_guess(helper_guess->GetWidth_guess(index),
                                             layout_120_guess.Lookup_guess(buffer_guess));
            ++index;
        }
    }
    index = 0;
    if (helper2_guess != 0) {
        while (index < (helper2_guess->widthCount_guess < 1 ? 1 : helper2_guess->widthCount_guess)) {
            _sprintf_guess(buffer_guess, "BenefitMasterList.col%d.wid", index);
            g_defaults_guess->SetValue_guess(helper2_guess->GetWidth_guess(index),
                                             layout_120_guess.Lookup_guess(buffer_guess));
            ++index;
        }
    }
    if (panel_180_guess != 0) {
        panel_180_guess->Slot74_guess(layout_120_guess.Lookup_guess("ListLayout"));
    }
}

// Closing with a master: sends the 5 active tributes and their tiers (OP_TributeUpdate) and
// OP_TributeNPC (master and player spawn ids), forgets the master, then saves the column widths.
// FUNCTION: TITANIUM 0x0056D388
char CTributeMasterWnd_guess::CloseMaster_guess() {
    if (g_spawn_0056_guess != 0) {
        SavePacket_0056_guess packet_guess;
        for (int i = 0; i < 5; ++i) {
            packet_guess.ids_guess[i] = g_candidate_guess->GetSlot_guess(i)->id_guess;
            packet_guess.indexes_guess[i] = g_candidate_guess->GetSlot_guess(i)->index_guess;
        }
        packet_guess.value_guess = g_spawn_0056_guess->value_guess;
        EQSendMessage(&g_connection_0056_guess, OP_TributeUpdate, &packet_guess, 0x30, 1);
        int data_guess[3];
        data_guess[1] = g_spawn_0056_guess->value_guess;
        data_guess[0] = g_other_0056_guess->value_guess;
        EQSendMessage(&g_connection_0056_guess, OP_TributeNPC, data_guess, 0xc, 1);
        g_spawn_0056_guess = 0;
    }
    g_reset_0056_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    g_message_0056_guess = 10;
    g_defaults_guess->Reset_guess(0, 1, 0x14);
    SaveWidths_guess();
    return 1;
}

struct Widget_0056_guess {
    char pad_000_guess[0x5d];
    unsigned char flag_5d_guess; // 0x5d
};

struct Table_0056_guess {
    int count_guess; // 0x00
    int data_guess;  // 0x04
    // EXTERNAL: TITANIUM 0x004EB924 Table_0056_guess::Lookup_guess
    Record_guess* Lookup_guess(int index);
};

struct Target_guess {
    char pad_000_guess[0x160];
    Helper_guess* helper_guess;          // 0x160
    Helper_guess* state_guess;           // 0x164
    char pad_168_guess[0x0c];
    Widget_0056_guess* widget_174_guess; // 0x174
    Widget_0056_guess* widget_178_guess; // 0x178
    char pad_17c_guess[0x1c];
    Table_0056_guess container_guess;    // 0x198
    char pad_1a0_guess[0x1d];
    unsigned char field_1bd_guess;       // 0x1bd
    unsigned char field_1be_guess;       // 0x1be
    void UpgradeBenefit_guess();
};

// Upgrade: requests the selected benefit's next tier (0x434C82) if there is one and the player's
// tribute points (charinfo +0x11A4) cover its cost.
// FUNCTION: TITANIUM 0x0056D466
void Target_guess::UpgradeBenefit_guess() {
    int index = state_guess->GetCurSel();
    if (index != -1) {
        int key = container_guess.Lookup_guess(index)->entry_0000_guess->field_4c_guess;
        int position = container_guess.Lookup_guess(index)->entry_0000_guess->field_50_guess;
        Record_0056_guess* record = g_sink_guess.Find_guess(key);
        if (record != 0) {
            if (position < record->count_guess - 1) {
                Candidate_guess* candidate = g_candidate_guess;
                LookupStatus_guess* status = reinterpret_cast<LookupStatus_guess*>(
                    reinterpret_cast<char*>(candidate) + 8 + candidate->holder_guess->vbaseOffset_0004_guess);
                LookupResult_guess* result = status->service_guess.GetCharInfo2();
                if (result->level_11a4_guess >= record->values_guess[position]) {
                    g_sink_guess.AddActiveTribute_guess(key);
                }
            }
        }
    }
}

// Downgrade: asks to drop the selected active benefit (0x434096).
// FUNCTION: TITANIUM 0x0056D4E9
void CTributeMasterWnd_guess::RemoveBenefit_guess() {
    if (helper_guess != 0) {
        int index = helper_guess->GetCurSel();
        if (index != -1) {
            g_sink_guess.LowerTributeTier_guess(container_guess.Lookup_guess(index)->entry_0000_guess->field_4c_guess);
        }
    }
}

// Greys (0xFFC0C0C0) the benefits the player can't take now: no next tier, too few points, or its
// time (+0x44 less the tier offset) not reached on the tribute clock; then sets Upgrade and Downgrade.
// FUNCTION: TITANIUM 0x0056D6EF
// @early-stop: budget, structural ndiff=89
void CTributeMasterWnd_guess::RefreshStatus_guess() {
    Target_guess* self = (Target_guess*)this;
    self->field_1bd_guess = 0;
    self->field_1be_guess = 0;
    if (self->state_guess != 0) {
        Table_0056_guess* table = &self->container_guess;
        for (int i = 0; i < table->count_guess; ++i) {
            if (table->Lookup_guess(i)->entry_0000_guess != 0) {
                Record_0056_guess* record = g_sink_guess.Find_guess(
                    table->Lookup_guess(i)->entry_0000_guess->field_4c_guess);
                bool enabled = table->Lookup_guess(i)->entry_0000_guess->field_50_guess
                    < record->count_guess - 1;
                LookupStatus_guess* status = reinterpret_cast<LookupStatus_guess*>(
                    &g_candidate_guess->embedded_guess[g_candidate_guess->holder_guess->vbaseOffset_0004_guess]);
                LookupResult_guess* result = status->service_guess.GetCharInfo2();
                enabled = enabled & (result->level_11a4_guess >= record->slots_guess[
                    table->Lookup_guess(i)->entry_0000_guess->field_40_guess]);
                int offset = table->Lookup_guess(i)->entry_0000_guess->field_50_guess == -1
                    ? 0
                    : record->widths_guess[table->Lookup_guess(i)->entry_0000_guess->field_50_guess];
                __int64 clock = g_candidate_guess->clock_guess;
                Entry_guess* entry = table->Lookup_guess(i)->entry_0000_guess;
                enabled = enabled & (clock >= g_sink_guess.GetUpkeep_guess() + (entry->field_44_guess - offset));
                int color = enabled ? -1 : 0xFFC0C0C0;
                for (int j = 0; j < 4; ++j) {
                    self->state_guess->SetValue_guess(i, j, color);
                }
                if (i == self->state_guess->GetCurSel()) {
                    self->field_1bd_guess = enabled;
                }
            }
        }
    }
    if (self->helper_guess != 0) {
        self->field_1be_guess = self->helper_guess->GetCurSel() != -1;
    }
    if (self->widget_178_guess != 0) {
        self->widget_178_guess->flag_5d_guess = self->field_1be_guess;
    }
    if (self->widget_174_guess != 0) {
        self->widget_174_guess->flag_5d_guess = self->field_1bd_guess;
    }
}

struct Ticker_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Ticker_guess::Stop_guess
    void Stop_guess(int value);
};

struct Holder_guess {
    char pad_000_guess[0x16c];
    Ticker_guess* ticker_16c_guess; // 0x16c
};

struct Source_guess {
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
    virtual CXRect* Slot57_guess(CXRect* rect_guess);
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(CXStr& text_guess); // 0xfc
};

struct TributeListDispatch_guess : Source_guess {
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
    virtual void Clear_guess();
};

struct EQ_Item_guess {
    char pad_000_guess[0x48];
    int field_48_guess; // 0x48
    // EXTERNAL: TITANIUM 0x005ECCC0 EQ_Item_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 EQ_Item_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 EQ_Item_guess::GetEntry_guess
    EQ_Item_guess* GetEntry_guess(int index);
    // EXTERNAL: TITANIUM 0x005EC650 EQ_Item_guess::GetSlot_guess
    EQ_Item_guess** GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x005E1050 EQ_Item_guess::Ready_guess
    int Ready_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 EQ_Item_guess::GetName_guess
    char* GetName_guess();
    // EXTERNAL: TITANIUM 0x005EC760 EQ_Item_guess::IsStackable_guess
    bool IsStackable_guess();
};

struct EQText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EQText_guess::GetText_guess
    char* GetText_guess(const char* source);
};

#define g_eqText_guess EQ_GLOBAL(EQText_guess*, 0x00988DF0)
#define g_itoaBuffer_0056_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* destination, unsigned int capacity, const char* text,
                          const char* arg4, const char* arg5, int zero6, int zero7,
                          int zero8, int zero9, int zero10, int zero11);

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* buffer, int radix);

struct FlushTarget_guess {
    char pad_000_guess[0x5d];
    unsigned char flag_5d_guess; // 0x5d
};

struct Pending_guess {
    char pad_000_guess[0x124];
    int field_124_guess;            // 0x124
    char pad_128_guess[0x40];
    // EXTERNAL: TITANIUM 0x0056E3E7 Pending_guess::RebuildRows_guess
    void RebuildRows_guess();
    Holder_guess* holder_168_guess; // 0x168
    Source_guess* source_16c_guess; // 0x16c
    FlushTarget_guess* donateButton_0170_guess; // 0x170
    char pad_174_guess[0x08];
    Source_guess* source_17c_guess; // 0x17c
    char pad_180_guess[0x40];
    int field_1c0_guess;            // 0x1c0
    EQ_Item_guess** field_1c4_guess; // 0x1c4
    char pad_1c8_guess[0x04];
    int field_1cc_guess;            // 0x1cc
    char pad_1d0_guess[0x04];
    unsigned char flag_1d4_guess;   // 0x1d4

    void UpdateDonateButton_guess();
    void ClearDonation_guess();
    bool CanActivate_guess();
    void SelectDonationItem_guess(int slot, struct SelectArg_guess* arg);
};

// Donate button: on for coins, or for an item worth something (0x5E1050); for a bag, every item in it
// must be worth something too.
// FUNCTION: TITANIUM 0x0056D2E7
void Pending_guess::UpdateDonateButton_guess() {
    bool ok = flag_1d4_guess == 0;
    if (donateButton_0170_guess == 0) {
        return;
    }
    if (field_1c4_guess == 0) {
        if (field_1cc_guess <= 0) {
            ok = false;
        }
    } else {
        EQ_Item_guess* node = *field_1c4_guess;
        if (node == 0) {
            ok = false;
        } else {
            if (node->GetItemClass_guess() == 1 && node->GetCount_guess() > 0) {
                int i = 0;
                do {
                    EQ_Item_guess* entry = node->GetEntry_guess(i);
                    if (entry != 0) {
                        if (ok && entry->Ready_guess() > 0) {
                            ok = true;
                        } else {
                            ok = false;
                        }
                    }
                    ++i;
                } while (i < node->GetCount_guess());
            }
            if (ok && node->Ready_guess() > 0) {
                ok = true;
            } else {
                ok = false;
            }
        }
    }
    donateButton_0170_guess->flag_5d_guess = ok;
}

// Clears the chosen item, coin amount and value text.
// FUNCTION: TITANIUM 0x0056D8CF
void Pending_guess::ClearDonation_guess() {
    field_1c4_guess = 0;
    pinstCInvSlotMgr_guess->SetSelection_guess(0);
    field_1c4_guess = 0;
    field_1cc_guess = 0;
    if (source_17c_guess != 0) {
        CXStr text_guess(EQ_ARRAY(char, 0x006410A8));
        source_17c_guess->Slot63_guess(text_guess);
    }
    if (holder_168_guess != 0) {
        Ticker_guess* ticker_guess = holder_168_guess->ticker_16c_guess;
        ticker_guess->Stop_guess(-1);
    }
    if (source_16c_guess != 0) {
        CXStr text2_guess(EQ_ARRAY(char, 0x0063F53F));
        source_16c_guess->Slot63_guess(text2_guess);
    }
    UpdateDonateButton_guess();
}

struct Checker_0056_guess {
    bool ShowAppraisal_guess(EQ_Item_guess* node);
};

// The master's appraisal in chat (channel 0x113): string 0xD34 with the value, or 0xD36 when the item
// is worth nothing (then false).
// FUNCTION: TITANIUM 0x0056CF4E
bool Checker_0056_guess::ShowAppraisal_guess(EQ_Item_guess* node) {
    bool ok = true;
    char buffer_guess[512];
    if (node != 0) {
        if (node->Ready_guess() == 0) {
            char* text = g_spawn_0056_guess->text_120_guess;
            Format_guess(buffer_guess, 0xd36, g_eqText_guess->GetText_guess(text),
                         node->GetName_guess(), 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0x113, 1);
            ok = false;
        } else {
            char* text = g_spawn_0056_guess->text_120_guess;
            Format_guess(buffer_guess, 0xd34, g_eqText_guess->GetText_guess(text),
                         _itoa(node->Ready_guess(), g_itoaBuffer_0056_guess, 10),
                         node->GetName_guess(), 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buffer_guess, 0x113, 1);
        }
    }
    return ok;
}

struct PcPrefix_0056_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct Profile_0056_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 Profile_0056_guess::GetItem_guess
    EQ_Item_guess* GetItem_guess(int slot);
    // EXTERNAL: TITANIUM 0x00434777 Profile_0056_guess::GetSlot_guess
    EQ_Item_guess** GetSlot_guess(int slot);
};

struct Pc_0056_guess : PcPrefix_0056_guess, virtual Profile_0056_guess {
};

#define g_pc_0056_guess EQ_GLOBAL(Pc_0056_guess*, 0x00905D00)

struct SelectArg_guess {
    char pad_000_guess[0x38];
    int value_38_guess; // 0x38
};

// Item chosen for donation from slot `slot`; shows its value.
// FUNCTION: TITANIUM 0x0056DDAA
void Pending_guess::SelectDonationItem_guess(int slot, SelectArg_guess* arg) {
    char chat_guess[256];
    char text_guess[256];
    bool ok = true;
    field_1cc_guess = 0;
    field_1c4_guess = 0;
    if (source_17c_guess != 0) {
        CXStr empty_guess(EQ_ARRAY(char, 0x006410A8));
        source_17c_guess->Slot63_guess(empty_guess);
    }
    field_1c0_guess = slot;
    if (holder_168_guess != 0) {
        int value_guess = arg->value_38_guess;
        Ticker_guess* ticker_guess = holder_168_guess->ticker_16c_guess;
        ticker_guess->Stop_guess(value_guess);
    }
    text_guess[0] = 0;
    if (source_16c_guess != 0) {
        CXStr text2_guess(text_guess);
        source_16c_guess->Slot63_guess(text2_guess);
    }
    EQ_Item_guess* node = 0;
    int current = field_1c0_guess;
    if (current < 31) {
        node = g_pc_0056_guess->GetItem_guess(current);
        field_1c4_guess = g_pc_0056_guess->GetSlot_guess(field_1c0_guess);
    // Ids 31-331 are bag contents: 31 + bag slot x 10 + index (bags sit in 22-29, so 251-330).
    } else if (current <= 0x14b) {
        int bag = (current - 31) / 10;
        int index = (current - 31) % 10;
        if (g_pc_0056_guess->GetItem_guess(bag) != 0
            && g_pc_0056_guess->GetItem_guess(bag)->GetItemClass_guess() == 1) {
            EQ_Item_guess* container = g_pc_0056_guess->GetItem_guess(bag);
            node = container->GetEntry_guess(index);
            field_1c4_guess = container->GetSlot_guess(index);
        }
    }
    if (node != 0) {
        if (node->GetItemClass_guess() == 1) {
            for (int i = 0; i < node->GetCount_guess(); ++i) {
                if (node->GetEntry_guess(i) != 0) {
                    ok = false;
                }
            }
        }
        if (ok) {
            reinterpret_cast<Checker_0056_guess*>(this)->ShowAppraisal_guess(node);
            _itoa(node->Ready_guess(), text_guess, 10);
        } else {
            // Bags must be empty (string 0xD86).
            Format_guess(chat_guess, 0xd86, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(chat_guess, 0x113, 1);
            _itoa(0, text_guess, 10);
        }
    }
    if (source_16c_guess != 0) {
        CXStr text3_guess(text_guess);
        source_16c_guess->Slot63_guess(text3_guess);
    }
    UpdateDonateButton_guess();
}

struct Display_0056e7_guess {
    char pad_000_guess[0x148];
    unsigned int tick_148_guess; // 0x148
    // EXTERNAL: TITANIUM 0x00439D16 Display_0056e7_guess::PlayerDistance_guess
    float PlayerDistance_guess(const void* first_guess, const void* second_guess, float scale_guess);
};

#define g_display_0056e7_guess EQ_GLOBAL(Display_0056e7_guess*, 0x00905D24)
#define g_busy_0056e7_guess EQ_GLOBAL(int, 0x009248D0)

// Activation check: tribute data loaded and the window built, and the NPC is a tribute master within
// 20 units; then the lists are built.
// FUNCTION: TITANIUM 0x0056E6CE
bool Pending_guess::CanActivate_guess() {
    bool ok = g_sink_guess.IsTributeAvailable_guess() && field_124_guess != 0;
    // Class 63, Tribute Master.
    if (g_spawn_0056_guess == 0 || g_spawn_0056_guess->flag_252_guess != '?') {
        ok = false;
    } else if (g_display_0056e7_guess->PlayerDistance_guess(g_spawn_0056_guess, g_other_0056_guess, 1.0f) > 20.0f) {
        ok = false;
    }
    if (holder_168_guess != 0) {
        Ticker_guess* ticker_guess = holder_168_guess->ticker_16c_guess;
        ticker_guess->Stop_guess(-1);
    }
    if (donateButton_0170_guess != 0) {
        donateButton_0170_guess->flag_5d_guess = 0;
    }
    if (source_17c_guess != 0) {
        CXStr text_guess(EQ_ARRAY(char, 0x006410A8));
        source_17c_guess->Slot63_guess(text_guess);
    }
    flag_1d4_guess = 0;
    UpdateDonateButton_guess();
    if (ok) {
        RebuildRows_guess();
    } else {
        g_reset_0056_guess = 0;
    }
    ClearDonation_guess();
    return ok;
}

struct ListRow_0056e7_guess;

struct List_0056e7_guess {
    int capacity_guess; // 0x00
    void* entries_guess; // 0x04
    int field_08_guess; // 0x08
    int field_0c_guess; // 0x0c
    // EXTERNAL: TITANIUM 0x0050F3F6 ??1List_0056e7_guess@@QAE@XZ
    ~List_0056e7_guess();
    // EXTERNAL: TITANIUM 0x0050319B List_0056e7_guess::Ensure_guess
    void Ensure_guess(int capacity_guess, ListRow_0056e7_guess** value_guess);
    // EXTERNAL: TITANIUM 0x004EB924 List_0056e7_guess::Lookup_guess
    ListRow_0056e7_guess** Lookup_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00405492 List_0056e7_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
};

// Base with a virtual dtor at 0x005A3100 (the base cleanup the dtor calls last).
struct ScalarBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1ScalarBase_guess@@UAE@XZ
    virtual ~ScalarBase_guess();
};

// EXTERNAL: TITANIUM 0x0065F788 ??_7Scalar_0056e_guess@@6B@
struct Scalar_0056e_guess : ScalarBase_guess {
    virtual ~Scalar_0056e_guess();
    char pad_004_guess[0x184 - 0x004];
    List_0056e7_guess active_184_guess; // 0x184
    char pad_194_guess[0x198 - 0x194];
    List_0056e7_guess master_198_guess; // 0x198
    // Scalar deleting destructor: runs the dtor, frees when flag bit 0 is set.
    void* Destroy_guess(unsigned char flags);
};

// Scalar deleting destructor of the tribute master window (vtable 0x65F788 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0056E086
void* Scalar_0056e_guess::Destroy_guess(unsigned char flags) {
    this->Scalar_0056e_guess::~Scalar_0056e_guess();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

struct Record_0056e7_guess;
struct TributeBenefitList_0056e8_guess;
struct WindowText_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x005A8B00 WindowText_guess::SetSTMLText
    void SetSTMLText(CXStr text_guess, bool first_guess, SLinkInfo* second_guess);
};

struct Tick_0056e7_guess {
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
    char pad_004_guess[0x58];
    char enabled_05c_guess; // 0x5c
    char pad_05d_guess[0x15c - 0x05d];
    WindowText_guess* description_15c_guess; // 0x15c
    TributeBenefitList_0056e8_guess* activeList_160_guess; // 0x160
    TributeBenefitList_0056e8_guess* masterList_164_guess; // 0x164
    char pad_168_guess[0x184 - 0x168];
    List_0056e7_guess active_184_guess; // 0x184
    int activeCount_194_guess; // 0x194
    List_0056e7_guess master_198_guess; // 0x198
    int masterCount_1a8_guess; // 0x1a8
    unsigned char flag_1ac_guess; // 0x1ac
    char pad_1ad_guess[0x03];
    int selector_1b0_guess; // 0x1b0
    unsigned char descending_1b4_guess; // 0x1b4
    char pad_1b5_guess[0x03];
    int selector_1b8_guess; // 0x1b8
    unsigned char descending_1bc_guess; // 0x1bc
    char pad_1bd_guess[0x13];
    unsigned int next_1d0_guess; // 0x1d0
    void OnProcessFrame_guess();
    void RebuildRows_guess();
    void SortActive_guess();
    void SortMaster_guess();
    void Refresh_guess();
    void MarkHeldBenefit_guess(Record_0056e7_guess* record_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x005A0E50 Tick_0056e7_guess::OnProcessFrame
    void OnProcessFrame();
};

struct ListRow_0056e7_guess {
    char text_guess[0x40]; // 0x00
    int field_40_guess; // 0x40
    void* source_44_guess; // 0x44
    int value_48_guess; // 0x48
    int id_4c_guess; // 0x4c
    int index_50_guess; // 0x50
};

struct Record_0056e7_guess {
    int field_00_guess; // 0x00
    CXStr name_04_guess; // 0x04
    int field_08_guess; // 0x08
    int count_0c_guess; // 0x0c
    int value_10_guess; // 0x10
    int values_14_guess[1]; // 0x14
    char pad_018_guess[0x20];
    void* source_38_guess[1]; // 0x38
};

typedef int (__cdecl *Compare_guess)(const void*, const void*);

// EXTERNAL: TITANIUM 0x0056BF4F CompareTributeName_guess
int __cdecl CompareTributeName_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BF64 Compare_0056bf64_guess
int __cdecl Compare_0056bf64_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BFAF Compare_0056bfaf_guess
int __cdecl Compare_0056bfaf_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BF76 CompareTributeTierThenName_guess
int __cdecl CompareTributeTierThenName_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BFFA Compare_0056bffa_guess
int __cdecl Compare_0056bffa_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056BFC1 CompareTributeCostThenName_guess
int __cdecl CompareTributeCostThenName_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056C045 Compare_0056c045_guess
int __cdecl Compare_0056c045_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x0056C00C Compare_0056c00c_guess
int __cdecl Compare_0056c00c_guess(const void*, const void*);

// Active-list sort; its third column uses key 3, like the master list's fourth.
// FUNCTION: TITANIUM 0x0056D51D
void Tick_0056e7_guess::SortActive_guess() {
    Compare_guess compare = 0;
    switch (selector_1b0_guess) {
    case 0:
        if (descending_1b4_guess != 0) compare = CompareTributeName_guess;
        else compare = Compare_0056bf64_guess;
        break;
    case 1:
        if (descending_1b4_guess != 0) compare = CompareTributeTierThenName_guess;
        else compare = Compare_0056bfaf_guess;
        break;
    case 3:
        if (descending_1b4_guess != 0) compare = CompareTributeCostThenName_guess;
        else compare = Compare_0056bffa_guess;
        break;
    }

    int count = activeCount_194_guess;
    if (count > 0 && compare != 0) {
        List_0056e7_guess& list = active_184_guess;
        if (list.capacity_guess <= 0 || list.entries_guess == 0) {
            return list.Fail_guess();
        }
        qsort(list.entries_guess, count, 4, compare);
    }
}

// Master-list sort, keys 0-3 by column.
// FUNCTION: TITANIUM 0x0056D5A6
void Tick_0056e7_guess::SortMaster_guess() {
    Compare_guess compare = 0;
    switch (selector_1b8_guess) {
    case 0:
        if (descending_1bc_guess != 0) compare = CompareTributeName_guess;
        else compare = Compare_0056bf64_guess;
        break;
    case 1:
        if (descending_1bc_guess != 0) compare = CompareTributeTierThenName_guess;
        else compare = Compare_0056bfaf_guess;
        break;
    case 2:
        if (descending_1bc_guess != 0) compare = Compare_0056c00c_guess;
        else compare = Compare_0056c045_guess;
        break;
    case 3:
        if (descending_1bc_guess != 0) compare = CompareTributeCostThenName_guess;
        else compare = Compare_0056bffa_guess;
        break;
    }

    int count = masterCount_1a8_guess;
    if (count > 0 && compare != 0) {
        List_0056e7_guess& list = master_198_guess;
        if (list.capacity_guess <= 0 || list.entries_guess == 0) {
            return list.Fail_guess();
        }
        qsort(list.entries_guess, count, 4, compare);
    }
}

// Shows benefit `record_guess` as held in the master list: tier `index_guess`, and the next tier's cost
// and +0x38 value.
// FUNCTION: TITANIUM 0x0056D647
// @early-stop: budget, structural ndiff=32
void Tick_0056e7_guess::MarkHeldBenefit_guess(Record_0056e7_guess* record_guess, int index_guess) {
    int index = 0;
    List_0056e7_guess& list = master_198_guess;
    if (list.capacity_guess > 0) {
        int slot = index_guess;
        int* values = &record_guess->value_10_guess + slot;
        do {
            int current = record_guess->field_00_guess;
            if (list.Lookup_guess(index)[0]->id_4c_guess == current) {
                list.Lookup_guess(index)[0]->index_50_guess = slot;
                if (slot < record_guess->count_0c_guess - 1) {
                    ++slot;
                    ++values;
                    index_guess = slot;
                }
                list.Lookup_guess(index)[0]->field_40_guess = slot;
                list.Lookup_guess(index)[0]->source_44_guess = record_guess->source_38_guess[slot];
                list.Lookup_guess(index)[0]->value_48_guess = *values;
            }
            ++index;
        } while (index < list.capacity_guess);
    }
}

// Rebuilds both row arrays: every benefit in the tribute table, then the 5 active slots (pCharData
// 0x5F0D80) with their tiers; then sorts and refills the lists.
// FUNCTION: TITANIUM 0x0056E3E7
// @early-stop: budget, structural ndiff=111
void Tick_0056e7_guess::RebuildRows_guess() {
    int index_guess = 0;
    masterCount_1a8_guess = 0;
    if (g_sink_guess.count_guess - 1 >= 0) {
        do {
            Record_0056e7_guess* record_guess =
                (Record_0056e7_guess*)g_sink_guess.Find_guess(index_guess);
            if (record_guess == 0) {
                if (masterCount_1a8_guess < master_198_guess.capacity_guess) {
                    delete *master_198_guess.Lookup_guess(masterCount_1a8_guess);
                    *master_198_guess.Lookup_guess(masterCount_1a8_guess) = 0;
                }
            } else {
                if (master_198_guess.capacity_guess <= masterCount_1a8_guess) {
                    ListRow_0056e7_guess* value_guess = 0;
                    do {
                        master_198_guess.Ensure_guess(master_198_guess.capacity_guess,
                                                      &value_guess);
                    } while (master_198_guess.capacity_guess <= masterCount_1a8_guess);
                }
                if (*master_198_guess.Lookup_guess(masterCount_1a8_guess) == 0) {
                    ListRow_0056e7_guess* value_guess =
                        (ListRow_0056e7_guess*)::operator new(0x54);
                    *master_198_guess.Lookup_guess(masterCount_1a8_guess) = value_guess;
                }
                ListRow_0056e7_guess** row_guess =
                    master_198_guess.Lookup_guess(masterCount_1a8_guess);
                strcpy((*row_guess)->text_guess, record_guess->name_04_guess);
                master_198_guess.Lookup_guess(masterCount_1a8_guess)[0]->source_44_guess =
                    record_guess->source_38_guess[0];
                master_198_guess.Lookup_guess(masterCount_1a8_guess)[0]->field_40_guess = 0;
                master_198_guess.Lookup_guess(masterCount_1a8_guess)[0]->value_48_guess =
                    record_guess->value_10_guess;
                master_198_guess.Lookup_guess(masterCount_1a8_guess)[0]->index_50_guess = -1;
                master_198_guess.Lookup_guess(masterCount_1a8_guess)[0]->id_4c_guess =
                    index_guess;
                ++masterCount_1a8_guess;
            }
            ++index_guess;
        } while (index_guess <= g_sink_guess.count_guess - 1);
    }

    activeCount_194_guess = 0;
    index_guess = 0;
    do {
        int id_guess = g_candidate_guess->GetSlot_guess(index_guess)->id_guess;
        int slotIndex_guess = g_candidate_guess->GetSlot_guess(index_guess)->index_guess;
        Record_0056e7_guess* record_guess =
            (Record_0056e7_guess*)g_sink_guess.Find_guess(id_guess);
        if (record_guess == 0) {
            if (activeCount_194_guess < active_184_guess.capacity_guess) {
                delete *active_184_guess.Lookup_guess(activeCount_194_guess);
                *active_184_guess.Lookup_guess(activeCount_194_guess) = 0;
            }
        } else {
            if (active_184_guess.capacity_guess <= activeCount_194_guess) {
                ListRow_0056e7_guess* value_guess = 0;
                do {
                    active_184_guess.Ensure_guess(active_184_guess.capacity_guess,
                                                  &value_guess);
                } while (active_184_guess.capacity_guess <= activeCount_194_guess);
            }
            if (*active_184_guess.Lookup_guess(activeCount_194_guess) == 0) {
                ListRow_0056e7_guess* value_guess =
                    (ListRow_0056e7_guess*)::operator new(0x54);
                *active_184_guess.Lookup_guess(activeCount_194_guess) = value_guess;
            }
            ListRow_0056e7_guess** row_guess =
                active_184_guess.Lookup_guess(activeCount_194_guess);
            strcpy((*row_guess)->text_guess, record_guess->name_04_guess);
            active_184_guess.Lookup_guess(activeCount_194_guess)[0]->source_44_guess =
                record_guess->source_38_guess[slotIndex_guess];
            active_184_guess.Lookup_guess(activeCount_194_guess)[0]->field_40_guess =
                slotIndex_guess;
            active_184_guess.Lookup_guess(activeCount_194_guess)[0]->index_50_guess =
                slotIndex_guess;
            active_184_guess.Lookup_guess(activeCount_194_guess)[0]->id_4c_guess = id_guess;
            ++activeCount_194_guess;
            MarkHeldBenefit_guess(record_guess, slotIndex_guess);
        }
        ++index_guess;
    } while (index_guess < 5);
    SortActive_guess();
    SortMaster_guess();
    Refresh_guess();
    flag_1ac_guess = 0;
}

// OnProcessFrame: rebuilds stale lists; every 500 ms closes the window when there is no master, or it is
// over 20 units away and 0x9248D0 is clear.
// FUNCTION: TITANIUM 0x0056E7D7
void Tick_0056e7_guess::OnProcessFrame_guess() {
    if (enabled_05c_guess != 0) {
        if (flag_1ac_guess != 0) {
            RebuildRows_guess();
        }
        if (g_display_0056e7_guess->tick_148_guess >= next_1d0_guess) {
            next_1d0_guess = g_display_0056e7_guess->tick_148_guess + 500;
            bool run = true;
            if (g_spawn_0056_guess != 0) {
                float measured = g_display_0056e7_guess->PlayerDistance_guess(
                    g_spawn_0056_guess, g_other_0056_guess, 0.0f);
                if (!(measured > 20.0f && g_busy_0056e7_guess == 0)) {
                    run = false;
                }
            }
            if (run) {
                Slot34_guess();
            }
        }
    }
    OnProcessFrame();
}

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850), 0x15C bytes.
struct TributeMasterBase_0056e8_guess {
    virtual void RefreshCounts_guess();
    // EXTERNAL: TITANIUM 0x005A3100 ??1TributeMasterBase_0056e8_guess@@UAE@XZ
    virtual ~TributeMasterBase_0056e8_guess();
    // EXTERNAL: TITANIUM 0x005A3850 ??0TributeMasterBase_0056e8_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    TributeMasterBase_0056e8_guess(CXWnd* parent_guess, const CXStr& screen_guess,
                                   int flags_guess, int iniVersion_guess, char* blockName_guess);
    char pad_004_guess[0x66 - 0x04];
    unsigned char field_0066_guess; // 0x66
    char pad_067_guess[0x124 - 0x067];
    void* sidlPiece_124_guess;      // 0x124
    char pad_128_guess[0x158 - 0x128];
    int field_158_guess;            // 0x158
};

// CTextureAnimation (0x4C bytes).
struct TributeAnimation_0056e8_guess {
    char data_guess[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0TributeAnimation_0056e8_guess@@QAE@XZ
    TributeAnimation_0056e8_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ??4TributeAnimation_0056e8_guess@@QAEAAU0@ABU0@@Z
    TributeAnimation_0056e8_guess& operator=(const TributeAnimation_0056e8_guess& other_guess);
    // EXTERNAL: TITANIUM 0x005B1AB0 TributeAnimation_0056e8_guess::Stop_guess
    void Stop_guess(int value_guess);
};

struct TributeSidlManager_0056e8_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 TributeSidlManager_0056e8_guess::FindAnimation_guess
    TributeAnimation_0056e8_guess* FindAnimation_guess(const CXStr& name_guess);
};

#define g_tributeSidlManager_0056e8_guess EQ_GLOBAL(TributeSidlManager_0056e8_guess*, 0x0099D3F4)

struct TributeSmall_0056e8_guess {
    int field_00_guess; // 0x00
    int field_04_guess; // 0x04
    int field_08_guess; // 0x08
    unsigned char field_0c_guess; // 0x0c
    TributeSmall_0056e8_guess() {
        field_04_guess = 0;
        field_00_guess = 0;
        field_08_guess = 0;
        field_0c_guess = 1;
    }
    ~TributeSmall_0056e8_guess();
};

struct TributeBenefitList_0056e8_guess : CListWnd {
    char pad_140_guess[0x15c - 0x140];
    unsigned char field_15c_guess; // 0x15c
    char pad_15d_guess[0x16c - 0x15d];
    unsigned int field_16c_guess; // 0x16c
};

struct TributeSelectedItem_0056e8_guess : CXWnd {
    char pad_11c_guess[0x16c - 0x11c];
    TributeAnimation_0056e8_guess* animation_16c_guess; // 0x16c
};

// Destructor: deletes every object held in the two pointer arrays (+0x184, +0x198), walking each up to
// its capacity.
// FUNCTION: TITANIUM 0x0056D9AC
// @early-stop: unknown, structural ndiff=2
Scalar_0056e_guess::~Scalar_0056e_guess() {
    for (int i = 0; i < active_184_guess.capacity_guess; ++i) {
        ::operator delete(*active_184_guess.Lookup_guess(i));
    }
    for (int i = 0; i < master_198_guess.capacity_guess; ++i) {
        ::operator delete(*master_198_guess.Lookup_guess(i));
    }
}

// Refills both list widgets (name, tier + 1, +0x44; the master list adds the cost) and keeps the
// master selection.
// FUNCTION: TITANIUM 0x0056DA41
void Tick_0056e7_guess::Refresh_guess() {
    if (description_15c_guess != 0) {
        description_15c_guess->SetSTMLText(CXStr(EQ_ARRAY(char, 0x0063F53F)), 1, 0);
    }

    char* buffer_guess = g_itoaBuffer_0056_guess;
    if (activeList_160_guess != 0) {
        ((TributeListDispatch_guess*)activeList_160_guess)->Clear_guess();
        int index_guess = 0;
        if (index_guess < activeCount_194_guess) {
            do {
                int row_guess;
                {
                    CXStr text_guess((*active_184_guess.Lookup_guess(index_guess))->text_guess);
                    row_guess = activeList_160_guess->AddString(
                        text_guess, 0xffffffff,
                        (*active_184_guess.Lookup_guess(index_guess))->id_4c_guess, 0);
                }
                {
                    CXStr text_guess(_itoa(
                        (*active_184_guess.Lookup_guess(index_guess))->field_40_guess + 1,
                        buffer_guess, 10));
                    activeList_160_guess->SetItemText(row_guess, 1, text_guess);
                }
                {
                    CXStr text_guess(_itoa(
                        (int)(*active_184_guess.Lookup_guess(index_guess))->source_44_guess,
                        buffer_guess, 10));
                    activeList_160_guess->SetItemText(row_guess, 2, text_guess);
                }
            } while (++index_guess < activeCount_194_guess);
        }
    }

    int selected_guess = -1;
    if (masterList_164_guess != 0) {
        int current_guess = masterList_164_guess->GetCurSel();
        if (current_guess != -1) {
            selected_guess = masterList_164_guess->GetItemData(current_guess);
        }
        ((TributeListDispatch_guess*)masterList_164_guess)->Clear_guess();
        int index_guess = 0;
        if (index_guess < masterCount_1a8_guess) {
            do {
                int row_guess;
                {
                    CXStr text_guess((*master_198_guess.Lookup_guess(index_guess))->text_guess);
                    row_guess = masterList_164_guess->AddString(
                        text_guess, 0xffffffff,
                        (*master_198_guess.Lookup_guess(index_guess))->id_4c_guess, 0);
                }
                {
                    CXStr text_guess(_itoa(
                        (*master_198_guess.Lookup_guess(index_guess))->field_40_guess + 1,
                        buffer_guess, 10));
                    masterList_164_guess->SetItemText(row_guess, 1, text_guess);
                }
                {
                    CXStr text_guess(_itoa(
                        (*master_198_guess.Lookup_guess(index_guess))->value_48_guess,
                        buffer_guess, 10));
                    masterList_164_guess->SetItemText(row_guess, 2, text_guess);
                }
                {
                    CXStr text_guess(_itoa(
                        (int)(*master_198_guess.Lookup_guess(index_guess))->source_44_guess,
                        buffer_guess, 10));
                    masterList_164_guess->SetItemText(row_guess, 3, text_guess);
                }
            } while (++index_guess < masterCount_1a8_guess);
        }
        ((CTributeMasterWnd_guess*)this)->SelectBenefit_guess(selected_guess);
    }
    ((CTributeMasterWnd_guess*)this)->RefreshStatus_guess();
}

// EXTERNAL: TITANIUM 0x0065F788 ??_7TributeMasterWnd_0056e8_guess@@6B@
struct TributeMasterWnd_0056e8_guess : TributeMasterBase_0056e8_guess {
    virtual void RefreshCounts_guess();
    CXWnd* description_15c_guess;                    // 0x15c
    TributeBenefitList_0056e8_guess* activeList_160_guess; // 0x160
    TributeBenefitList_0056e8_guess* masterList_164_guess; // 0x164
    TributeSelectedItem_0056e8_guess* selectedItem_168_guess; // 0x168
    CXWnd* valueLabel_16c_guess;                     // 0x16c
    CXWnd* donateButton_170_guess;                   // 0x170
    CXWnd* upgradeButton_174_guess;                  // 0x174
    CXWnd* downgradeButton_178_guess;                // 0x178
    CXWnd* coinButton_17c_guess;                     // 0x17c
    CXWnd* layout_180_guess;                         // 0x180
    TributeSmall_0056e8_guess small_184_guess;       // 0x184
    int field_194_guess;                             // 0x194
    TributeSmall_0056e8_guess small_198_guess;       // 0x198
    int field_1a8_guess;                             // 0x1a8
    unsigned char field_1ac_guess;                   // 0x1ac
    int activeSortColumn_01b0_guess;                             // 0x1b0
    unsigned char activeSortAscending_01b4_guess;                   // 0x1b4
    int masterSortColumn_01b8_guess;                             // 0x1b8
    unsigned char masterSortAscending_01bc_guess;                   // 0x1bc
    unsigned char field_1bd_guess;                   // 0x1bd
    unsigned char field_1be_guess;                   // 0x1be
    int field_1c0_guess;                             // 0x1c0
    EQ_Item_guess** field_1c4_guess;                // 0x1c4
    int field_1c8_guess;                             // 0x1c8
    int donatePlatinum_01cc_guess;                             // 0x1cc
    int field_1d0_guess;                             // 0x1d0
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                             void* data_guess);
    TributeMasterWnd_0056e8_guess(CXWnd* parent_guess);
};

// Donate: coins (+0x1CC) go at once (0x4344F0); a stackable item first asks CQuantityWnd for a count,
// other items go straight away (0x433EAC). The coin button asks for an amount up to charinfo +0x11D4
// (probably platinum). Double-click (4): Upgrade or Downgrade; 0xF sorts.
// FUNCTION: TITANIUM 0x0056E0A2
// @early-stop: budget, structural ndiff=89
int TributeMasterWnd_0056e8_guess::WndNotification_guess(CXWnd* sender_guess,
                                                         unsigned int message_guess,
                                                         void* data_guess) {
    CXWnd* sender_value_guess = sender_guess;
    if (message_guess == 1) {
        if (sender_value_guess == activeList_160_guess || sender_value_guess == masterList_164_guess) {
            ((CTributeMasterWnd_guess*)this)->SelectBenefit_guess(
                ((CListWnd*)sender_value_guess)->GetItemData(
                    ((CListWnd*)sender_value_guess)->GetCurSel()));
            ((CTributeMasterWnd_guess*)this)->RefreshStatus_guess();
            return 0;
        } else if (sender_value_guess == donateButton_170_guess) {
            if (donatePlatinum_01cc_guess > 0) {
                g_sink_guess.DonateTributePlatinum_guess(donatePlatinum_01cc_guess);
                return 0;
            }
            if (field_1c4_guess != 0 && *field_1c4_guess != 0) {
                if ((*field_1c4_guess)->IsStackable_guess()) {
                    CXRect rect_guess;
                    CXRect* values_guess = ((Source_guess*)donateButton_170_guess)
                        ->Slot57_guess(&rect_guess);
                    int left_guess = values_guess->left;
                    int top_guess = values_guess->top;
                    int value_guess = (*field_1c4_guess)->field_48_guess;
                    field_1c8_guess = 0;
                    pinstCQuantityWnd_guess->Function_0054d976_guess(this, value_guess, value_guess,
                                                              left_guess, top_guess, 1);
                } else {
                    g_sink_guess.SendTributeItem_guess(field_1c0_guess, 1);
                }
            }
            return 0;
        } else if (sender_value_guess == coinButton_17c_guess) {
            ((Pending_guess*)this)->ClearDonation_guess();
            field_1c8_guess = 1;
            CXRect rect_guess;
            CXRect* values_guess = ((Source_guess*)coinButton_17c_guess)
                ->Slot57_guess(&rect_guess);
            int top_guess = values_guess->top;
            int left_guess = values_guess->left;
            Candidate_guess* candidate_guess = g_candidate_guess;
            LookupStatus_guess* status_guess = (LookupStatus_guess*)
                &candidate_guess->embedded_guess[candidate_guess->holder_guess->vbaseOffset_0004_guess];
            LookupResult_guess* result_guess = status_guess->service_guess.GetCharInfo2();
            pinstCQuantityWnd_guess->Function_0054d976_guess(this, result_guess->platinum_11d4_guess,
                result_guess->platinum_11d4_guess, left_guess, top_guess, 1);
        } else if (sender_value_guess == downgradeButton_178_guess) {
            ((CTributeMasterWnd_guess*)this)->RemoveBenefit_guess();
            return 0;
        } else if (sender_value_guess == upgradeButton_174_guess) {
            ((Target_guess*)this)->UpgradeBenefit_guess();
            return 0;
        }
    // CQuantityWnd reply: the item count to donate (+0x1C8 = 0) or the coin amount (+0x1C8 = 1).
    } else if (message_guess == 0x1f) {
        if (field_1c8_guess == 0) {
            if (field_1c4_guess != 0 && *field_1c4_guess != 0) {
                g_sink_guess.SendTributeItem_guess(field_1c0_guess, *(int*)data_guess);
            }
        } else if (field_1c8_guess == 1) {
            donatePlatinum_01cc_guess = *(int*)data_guess;
            if (coinButton_17c_guess != 0) {
                CXStr text_guess(_itoa(donatePlatinum_01cc_guess, g_itoaBuffer_0056_guess, 10));
                ((Source_guess*)coinButton_17c_guess)->Slot63_guess(text_guess);
            }
            ((Pending_guess*)this)->UpdateDonateButton_guess();
        }
        return 0;
    } else if (message_guess == 4) {
        if (sender_value_guess == activeList_160_guess && field_1be_guess != 0) {
            ((CTributeMasterWnd_guess*)this)->RemoveBenefit_guess();
            return 0;
        } else if (sender_value_guess == masterList_164_guess && field_1bd_guess != 0) {
            ((Target_guess*)this)->UpgradeBenefit_guess();
            return 0;
        }
    } else if (message_guess == 0xf) {
        if (sender_value_guess == activeList_160_guess) {
            int value_guess = activeSortColumn_01b0_guess;
            switch ((int)data_guess) {
            case 0:
                value_guess = 0;
                break;
            case 1:
                value_guess = 1;
                break;
            case 2:
                value_guess = 3;
                break;
            }
            activeSortAscending_01b4_guess = value_guess == activeSortColumn_01b0_guess
                ? activeSortAscending_01b4_guess == 0 : 1;
            activeSortColumn_01b0_guess = value_guess;
            ((Tick_0056e7_guess*)this)->SortActive_guess();
        } else if (sender_value_guess == masterList_164_guess) {
            int value_guess = masterSortColumn_01b8_guess;
            switch ((int)data_guess) {
            case 0:
                value_guess = 0;
                break;
            case 1:
                value_guess = 1;
                break;
            case 2:
                value_guess = 2;
                break;
            case 3:
                value_guess = 3;
                break;
            }
            masterSortAscending_01bc_guess = value_guess == masterSortColumn_01b8_guess
                ? masterSortAscending_01bc_guess == 0 : 1;
            masterSortColumn_01b8_guess = value_guess;
            ((Tick_0056e7_guess*)this)->SortMaster_guess();
        } else {
            return ((CSidlScreenWnd*)this)->WndNotification(sender_value_guess, message_guess,
                                                            data_guess);
        }
        ((Tick_0056e7_guess*)this)->Refresh_guess();
        return 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_value_guess, message_guess, data_guess);
}

// Tribute master window constructor: finds its controls, sets up the active and master benefit lists,
// gives the selected-item slot its own stopped copy of the A_DragItem animation, then restores the column
// widths and list layout (0x0056D04A).
// FUNCTION: TITANIUM 0x0056E855
TributeMasterWnd_0056e8_guess::TributeMasterWnd_0056e8_guess(CXWnd* parent_guess)
    : TributeMasterBase_0056e8_guess(parent_guess, "TributeMasterWnd", -1, 1, 0),
      small_184_guess(), small_198_guess(), field_1c0_guess(-1) {
    description_15c_guess = 0;
    activeList_160_guess = 0;
    masterList_164_guess = 0;
    valueLabel_16c_guess = 0;
    selectedItem_168_guess = 0;
    donateButton_170_guess = 0;
    upgradeButton_174_guess = 0;
    downgradeButton_178_guess = 0;
    coinButton_17c_guess = 0;
    layout_180_guess = 0;
    activeSortColumn_01b0_guess = 0;
    activeSortAscending_01b4_guess = 1;
    masterSortColumn_01b8_guess = 0;
    masterSortAscending_01bc_guess = 1;
    field_1be_guess = 0;
    field_1bd_guess = 0;
    field_1ac_guess = 0;
    field_194_guess = 0;
    field_1a8_guess = 0;
    field_1c4_guess = 0;
    field_1d0_guess = 0;
    donatePlatinum_01cc_guess = 0;
    if (sidlPiece_124_guess != 0) {
        field_0066_guess |= 1;
        field_158_guess = 0x2b;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        description_15c_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0064DC54));
        valueLabel_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F8E4));
        selectedItem_168_guess = (TributeSelectedItem_0056e8_guess*)
            ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F8D4));
        donateButton_170_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F8C4));
        downgradeButton_178_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F714));
        upgradeButton_174_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F8B4));
        coinButton_17c_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065F8A8));
        layout_180_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00650060));
        activeList_160_guess = (TributeBenefitList_0056e8_guess*)
            ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00655E10));
        if (activeList_160_guess != 0) {
            activeList_160_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            activeList_160_guess->SetColumnJustification(0, 0);
            activeList_160_guess->SetColumnJustification(1, 1);
            activeList_160_guess->SetColumnJustification(2, 1);
            activeList_160_guess->field_16c_guess = 0xff8aa3ff;
            activeList_160_guess->field_15c_guess = 1;
        }
        masterList_164_guess = (TributeBenefitList_0056e8_guess*)
            ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00655DFC));
        if (masterList_164_guess != 0) {
            masterList_164_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            masterList_164_guess->SetColumnJustification(0, 0);
            masterList_164_guess->SetColumnJustification(1, 1);
            masterList_164_guess->SetColumnJustification(2, 1);
            masterList_164_guess->SetColumnJustification(3, 1);
            masterList_164_guess->field_16c_guess = 0xff8aa3ff;
            masterList_164_guess->field_15c_guess = 1;
        }
        if (selectedItem_168_guess != 0) {
            TributeAnimation_0056e8_guess* drag_guess =
                g_tributeSidlManager_0056e8_guess->FindAnimation_guess(EQ_ARRAY(char, 0x00642A8C));
            TributeAnimation_0056e8_guess* animation_guess = new TributeAnimation_0056e8_guess;
            if (animation_guess != 0) {
                *animation_guess = *drag_guess;
                animation_guess->Stop_guess(-1);
            }
            selectedItem_168_guess->animation_16c_guess = animation_guess;
        }
        ((CTributeMasterWnd_guess*)this)->LoadWidths_guess();
    }
}
